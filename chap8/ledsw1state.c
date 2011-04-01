/*
 * "Copyright (c) 2008 Robert B. Reese, Bryan A. Jones, J. W. Bruce ("AUTHORS")"
 * All rights reserved.
 * (R. Reese, reese_AT_ece.msstate.edu, Mississippi State University)
 * (B. A. Jones, bjones_AT_ece.msstate.edu, Mississippi State University)
 * (J. W. Bruce, jwbruce_AT_ece.msstate.edu, Mississippi State University)
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement is
 * hereby granted, provided that the above copyright notice, the following
 * two paragraphs and the authors appear in all copies of this software.
 *
 * IN NO EVENT SHALL THE "AUTHORS" BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
 * OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE "AUTHORS"
 * HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * THE "AUTHORS" SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE "AUTHORS" HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
 *
 * Please maintain this header in its entirety when copying/modifying
 * these files.
 *
 *
 */

#include "pic24_all.h"
#include <stdio.h>

/** \file
 *  \brief A program that uses a finite state machine approach for
 *    implementing switch/LED input/output.
 *
 *  Thoughts on the implementation:
 *
 *  Things I don't like:
 *  - Not having an entry action makes for some repetition
 *    in the code. It also makes things a bit less intuitive,
 *    since actions that seem to belong as a state entry have
 *    to go in the exit actions of other states.
 */

void arm_timer0 (uint16 u16_timeout_ms);
void disarm_timer0 (void);

/// Define all events for this system.
typedef enum {
  /// Signals a timer expired
  TIMEOUT_EVENT,
  /// The button was pressed
  PRESS_EVENT,
  /// The button was released
  RELEASE_EVENT
} EVENT;


/* Configure hardware
=====================================================================*/
/// Configures LED1.
#define CONFIG_LED1() CONFIG_RB14_AS_DIG_OUTPUT()

/// Define the pin to which LED1 is attached.
#define LED1  _LATB14     //led1 state

/// Switch1 configuration - a pushbutton
void CONFIG_SW1()  {
  CONFIG_RB13_AS_DIG_INPUT();     //use RB13 for switch input
  ENABLE_RB13_PULLUP();           //enable the pullup
}

/// Specify the I/O pin to which the switch is connected.
#define SW1              _RB13

/// Switch2 configuration
inline void CONFIG_SW2()  {
  CONFIG_RB12_AS_DIG_INPUT();     //use RB12 for switch input
  ENABLE_RB12_PULLUP();           //enable the pullup
}

/// Specify the I/O pin to which the switch is connected.
#define SW2              _RB12  //switch state


/* Define state machine
=====================================================================*/
/// The states which the state machine can take on. Note that
/// the STATE_MAX is not used by the machine, but instead to
/// verify that the machine's state is valid.
typedef enum  {
  STATE_LED_OFF,
  STATE_LED_ON_0,
  STATE_LED_BLINK,
  STATE_LED_ON_1,
  STATE_MAX
} STATE;

/// Strings corresponding to valid states of the FSM.
const char *apsz_state_names[] = {
  "STATE_LED_OFF",
  "STATE_LED_ON_0",
  "STATE_LED_BLINK",
  "STATE_LED_ON_1"
};

/// The state of the state machine.
STATE e_mystate;

/// The constructor for the FSM. It initializes all
/// the hardware for the FSM.
void fsm_ctor(void) {
  CONFIG_SW1();        //configure switch
  CONFIG_SW2();        //configure switch
  CONFIG_LED1();       //config the LED
  DELAY_US(1);         //give pullups a little time
}

/// Move the state machine to its initial state.
void fsm_init(void) {
  LED1 = 0;
  e_mystate = STATE_LED_OFF;
}

/// Half the time of an LED blink, in MS
#define LED_BLINK_HALF_PERIOD_MS 1000

/// Take one step in the state machine, based on the event e.
/// @param e Event the state machine should respond to.
void fsm_run(EVENT e) {
  switch (e_mystate) {
    case STATE_LED_OFF:
      if (e == RELEASE_EVENT) {
        e_mystate = STATE_LED_ON_0;
        // On entry to the LED_ON state, turn
        // the LED on.
        LED1 = 1;
      }
      break;

    case STATE_LED_ON_0:
      LED1 = 1; //turn on the LED
      if (e == RELEASE_EVENT) {
        // Implement SW2 decision box
        outString("SW2 == ");
        outString(SW2 ? "1\n" : "0\n");
        if (SW2) {
          e_mystate = STATE_LED_BLINK;
          // Arm the blink timer to get the blink
          // state started.
          arm_timer0(LED_BLINK_HALF_PERIOD_MS);
        } else {
          e_mystate = STATE_LED_OFF;
          // On entry to the LED_OFF state, turn
          // the LED off.
          LED1 = 0;
        }
      }
      break;

    case STATE_LED_BLINK:
      // On a timeout, toggle the LED and request another timeout
      if (e == TIMEOUT_EVENT) {
        LED1 = !LED1;
        arm_timer0(LED_BLINK_HALF_PERIOD_MS);
      }

      // On a press, move to the next state.
      if (e == PRESS_EVENT) {
        // Disarm the timer before existing this state.
        disarm_timer0();
        e_mystate = STATE_LED_ON_1;
        // On entry to the LED_ON state, turn
        // the LED on.
        LED1 = 1;
      }
      break;

    case STATE_LED_ON_1:
      if (RELEASE_EVENT) {
        e_mystate = STATE_LED_OFF;
          // On entry to the LED_OFF state, turn
          // the LED off.
          LED1 = 0;
      }
      break;

    default:
      ASSERT(0);
  }
}



/* Framework to execute a state machine
=====================================================================*/
/// The circular current time, in ms. The time is never 0 ms;
/// after the maximum time of 65535 ms, the time rolls over to
/// 1 ms. Therefore, DO NOT measure absolute time -- this is,
/// instead, circular time. Therefore, comparisions to the
/// the circular time must always be in terms of equality/
/// inequality, rather than greater/lesser.
uint16 u16_ctime_ms = 1;

/// The time at which timer event 0 should fire. A time of
/// 0 indicates the timer is not armed.
uint16 u16_timeout0_ms = 0;

/// Arm timer 0 to expire u16_timeout_ms in the future.
/// The timer must not already be armed and the timeout
/// must be greater than 0.
/// @param u16_timeout_ms Time, in ms from the current time,
///   at which the next timer event will occur.
void arm_timer0 (uint16 u16_timeout_ms) {
  // Make sure we're not overwriting an already-existing
  // timer event
  ASSERT(u16_timeout0_ms == 0);

  // Verify that the requested timeout is non-zero.
  ASSERT(u16_timeout_ms != 0);

  // Compute the new circutlar timer for the requested timtout.
  u16_timeout0_ms = u16_ctime_ms + u16_timeout_ms;
}

/// Disarm timer 0, so that no timeout event will occur
/// in the future. An already-disarmed timer can be
/// disarmed again with no adverse side affects.
void disarm_timer0 (void) {
  u16_timeout0_ms = 0;
}

/// The last state of SW1.
uint16 u16_lastButton;

// Initialize the framework
void framework_init (void) {
  // Set up heartbeat, UART, print hello message and diags
  configBasic(HELLO_MSG);
  // Set up state machine and associated peripherals
  fsm_ctor();
  // Initialize last value of pushbutton only after
  // it's been initialized by the routine above.
  u16_lastButton = SW1;
  fsm_init();
}


/// Implement a framework to generate events from the hardware
/// and pass them on to the FSM.
void framework_run (void) {
  // The time at which a timer event 1 should fire. A time of
  // 0 indicates the timer is not armed.
  static uint16 u16_timeout1_ms = 0;
  // Last state of the FSM
  static STATE e_last_state = STATE_MAX;


  // Print out the state if it changes
  if (e_mystate != e_last_state) {
    e_last_state = e_mystate;
    ASSERT(e_mystate <= STATE_MAX);
    outString(apsz_state_names[e_mystate]);
    outString("\n");
  }

  // If timer 0 expires, then send an event
  if (u16_timeout0_ms == u16_ctime_ms) {
    outString("At circular time ");
    outUint16Decimal(u16_ctime_ms);
    outString(": timeout\n");
    // Indicate the timer is disarmed before executing the FSM,
    // therefore allowing the FSM to arm another event.
    u16_timeout0_ms = 0;
    fsm_run(TIMEOUT_EVENT);
  }

  // If timer 1 expires, disarm it. No event is necessary,
  // since this code checks for a disarmed timer before
  // generating a button press/release event.
  if (u16_timeout1_ms == u16_ctime_ms) {
    u16_timeout1_ms = 0;
  }

  // If a button press occurs after bounces have died out, send an event
  if ( (u16_timeout1_ms == 0) && (SW1 != u16_lastButton) ) {
    // Update last state of the switch
    u16_lastButton = SW1;
    // Update valid time for next button press
    u16_timeout1_ms = u16_ctime_ms + DEBOUNCE_DLY;
    // Dispatch the event
    outString("At circular time ");
    outUint16Decimal(u16_ctime_ms);
    outString(u16_lastButton ? ": release\n" : ": press\n");
    fsm_run(u16_lastButton ? RELEASE_EVENT : PRESS_EVENT);
  }

  // Move forward in time. Circular time goes from its max count
  // to 1 ms, not 0 ms.
  u16_ctime_ms++;
  if (u16_ctime_ms == 0) {
    u16_ctime_ms = 1;
  }

  doHeartbeat();     //ensure that we are alive
} // end while (1)


/// Period of the timer2 ISR, in MS
#define ISR_PERIOD_MS  1

/// Configure timer 2 for periodic interrupt generation.
void  config_timer2 (void) {
  //T2CON set like this for documentation purposes.
  //could be replaced by T2CON = 0x0020
  T2CON = T2_OFF | T2_IDLE_CON | T2_GATE_OFF
          | T2_32BIT_MODE_OFF
          | T2_SOURCE_INT
          | T2_PS_1_64 ;  //results in T2CON = 0x0020
  //subtract 1 from ticks value assigned to PR2 because period is PRx + 1
  PR2 = msToU16Ticks(ISR_PERIOD_MS, getTimerPrescale(T2CONbits)) - 1;
  TMR2  = 0;                       //clear timer2 value
  _T2IF = 0;                       //clear interrupt flag
  _T2IP = 1;                       //choose a priority
  _T2IE = 1;                       //enable the interrupt
  T2CONbits.TON = 1;               //turn on the timer
}

/// On each timer2 interrupt, run the framework.
void _ISR _T2Interrupt (void) {
  _T2IF = 0;                 //clear the timer interrupt bit
  framework_run();
}

/// Uncomment to enable timer2 use, rather than delay loops,
/// to call the framework.
#define USE_TIMER2

/// Call the framework to execute the FSM.
int main (void) {
  configPinsForLowPower();
  // Disable all peripheral modules except timer 2
  // to save power
  PMD1 = (1u << 13) |   // T3MD = 1: disable timer 3
         (0u << 11) |   // T2MD = 0: enable timer 2
         (1u << 11) |   // T1MD = 1: disable timer 1
         (1u <<  7) |   // I2C1MD = 1: disable I2C1
         (0u <<  5) |   // U1MD = 0: enable UART1
         (1u <<  3) |   // SPI1MD = 0: disable SPI1
         (1u <<  0);    // AD1MD = 0: disable AD1
  PMD2 = 0xFFFF;        // Disable all IC, OC modules
  framework_init();
#ifdef USE_TIMER2
  config_timer2();
  while (1) {
    IDLE();
  }
#else
  while (1) {
    framework_run();
    DELAY_MS(1);
  }
#endif
}
