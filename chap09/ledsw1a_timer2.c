// .. "Copyright (c) 2008 Robert B. Reese, Bryan A. Jones, J. W. Bruce ("AUTHORS")"
//    All rights reserved.
//    (R. Reese, reese_AT_ece.msstate.edu, Mississippi State University)
//    (B. A. Jones, bjones_AT_ece.msstate.edu, Mississippi State University)
//    (J. W. Bruce, jwbruce_AT_ece.msstate.edu, Mississippi State University)
//
//    Permission to use, copy, modify, and distribute this software and its
//    documentation for any purpose, without fee, and without written agreement is
//    hereby granted, provided that the above copyright notice, the following
//    two paragraphs and the authors appear in all copies of this software.
//
//    IN NO EVENT SHALL THE "AUTHORS" BE LIABLE TO ANY PARTY FOR
//    DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
//    OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE "AUTHORS"
//    HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//    THE "AUTHORS" SPECIFICALLY DISCLAIMS ANY WARRANTIES,
//    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
//    AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
//    ON AN "AS IS" BASIS, AND THE "AUTHORS" HAS NO OBLIGATION TO
//    PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
//
//    Please maintain this header in its entirety when copying/modifying
//   these files.
//
// *****************************************************************
// ledsw1a_timer2.c - Example of implementing a FSM in an interrupt.
// *****************************************************************
// Demonstrates the use of a events to create an energy-efficient FSM implementation. All of the FSM work is done in the ISR.


#include "pic24_all.h"

// LED1 configuration and access
// =============================
#define CONFIG_LED1() CONFIG_RB14_AS_DIG_OUTPUT()
#define LED1 (_LATB14)

// Pushbutton configuration and access
// ===================================
void config_pb(void)  {
  CONFIG_RB13_AS_DIG_INPUT();
  ENABLE_RB13_PULLUP();
  // Give the pullup some time to take effect.
  DELAY_US(1);
}

#define PB_PRESSED()   (_RB13 == 0)
#define PB_RELEASED()  (_RB13 == 1)

// Switch configuration and access
// ===============================
void config_sw(void)  {
  CONFIG_RB12_AS_DIG_INPUT();
  ENABLE_RB12_PULLUP();
  // Give the pullup some time to take effect.
  DELAY_US(1);
}

#define SW              (_RB12)

// State machine
// =============
// State definition
// ----------------
// First, define the states, along with a human-readable version.
typedef enum  {
  STATE_RELEASED1,
  STATE_PRESSED1,
  STATE_RELEASED2,
  STATE_PRESSED2,
  STATE_RELEASED3_BLINK,
  STATE_PRESSED3,
} state_t;

const char* apsz_state_names[] = {
  "STATE_RELEASED1 - LED is off",
  "STATE_PRESSED1",
  "STATE_RELEASED2 - LED is on",
  "STATE_PRESSED2 - SW2 on goes to blink else go to RELEASED1",
  "STATE_RELEASED3_BLINK - LED blinks, waiting for SW1 press",
  "STATE_PRESSED3 - LED is on",
};

// Event definition
// ----------------
// Define events known to this system. They identify the interrupt source.
typedef enum {
  EVENT_CN,
  EVENT_T3,
} event_t;

const char* apsz_event_names[] = {
  "EVENT_CN",
  "EVENT_T3",
};

// Provide a convenient function to print out the state and event.
void print_state(event_t e_event, state_t e_state) {
  // Verify that the event has a string representation before printing it.
  ASSERT(e_event <= N_ELEMENTS(apsz_event_names));
  outString(apsz_event_names[e_event]);
  outString(", ");
  //outString(SW ? "1, " : "0, ");

  // Verify that the state has a string representation before printing it.
  ASSERT(e_state <= N_ELEMENTS(apsz_state_names));
  outString(apsz_state_names[e_state]);
  outString(".\n");
}

// Timer arming
// ------------
// This function prepares the timer to interrupt after the given delay (in ms).
void timer3_arm(uint16_t u16_time_ms) {
  PR3 = msToU16Ticks(u16_time_ms, getTimerPrescale(T3CONbits)) - 1;
  TMR3 = 0;
  T3CONbits.TON = 1;
}

// State machine
// -------------
// This function defines the state machine.
void update_state(event_t e_event) {
  static state_t e_state = STATE_RELEASED1;

  switch (e_event) {
    // If this is a timer event, assume it was a debounce delay.
    case EVENT_T3 :
    // Clear any pending change notification interrupts due to switch bounce.
    _CNIF = 0;
    // Re-enable change notification interrupts now that all bounces have died out.
    _CNIE = 1;
    // Make this a one-shot timer: turn it off.
    T3CONbits.TON = 0;
    break;

    // If this is a change notification event, wait a debounce delay before accepting further CN events.
    case EVENT_CN :
    _CNIE = 0;
    timer3_arm(DEBOUNCE_DLY);
    break;

    default:
    ASSERT(0);
  }

  switch (e_state) {
    case STATE_RELEASED1:
      if (PB_PRESSED()) e_state = STATE_PRESSED1;
      break;

    case STATE_PRESSED1:
      if (PB_RELEASED()) {
        // Turn the LED on when entering STATE_RELEASED2.
        e_state = STATE_RELEASED2;
        LED1 = 1;
      }
      break;

    case STATE_RELEASED2:
      if (PB_PRESSED()) e_state = STATE_PRESSED2;
      break;

    case STATE_PRESSED2:
      if (PB_RELEASED()) {
        if (SW) {
          e_state = STATE_RELEASED3_BLINK;
        } else {
          // Turn the LED off when moving to STATE_RELEASED1.
          e_state = STATE_RELEASED1;
          LED1 = 0;
        }
      }
      break;

    case STATE_RELEASED3_BLINK:
      LED1 = !LED1;
      timer3_arm(100);
      if (PB_PRESSED()) {
        // Freeze the LED on when existing the blink state.
        e_state = STATE_PRESSED3;
        LED1 = 1;
      }
      break;

    case STATE_PRESSED3:
      if (PB_RELEASED()) {
        // Turn the LED off when moving to STATE_RELEASED1.
        e_state = STATE_RELEASED1;
        LED1 = 0;
      }
      break;

    default:
      ASSERT(0);
  }

  print_state(e_event, e_state);
}

// Event sources
// =============
// Timer events
// ------------
// Configure the timer to produce interrupts.
void configTimer3(void) {
  //ensure that Timer2,3 configured as separate timers.
  T2CONbits.T32 = 0;     // 32-bit mode off
  //T3CON set like this for documentation purposes.
  //could be replaced by T3CON = 0x0020
  T3CON = T3_OFF | T3_IDLE_CON | T3_GATE_OFF
          | T3_SOURCE_INT
          | T3_PS_1_256;
  _T3IF = 0;                       //clear interrupt flag
  _T3IP = 1;                       //choose a priority
  _T3IE = 1;                       //enable the interrupt
}

// Interrupt Service Routine for Timer3
void _ISR _T3Interrupt(void) {
  // Clear the interrupt flag.
  _T3IF = 0;
  // Inform our state machine of an event.
  update_state(EVENT_T3);
}

// Enable change-notification interrupts on the switch.
void config_cn(void) {
  ENABLE_RB13_CN_INTERRUPT();
  _CNIF = 0;         //Clear the interrupt flag
  _CNIP = 1;         //Choose a priority
  _CNIE = 1;         //enable the Change Notification general interrupt
}

// Interrupt service routine for change notification interrupts.
void _ISR _CNInterrupt(void) {
  _CNIF = 0;
  update_state(EVENT_CN);
}

// Main
// ====
int main (void) {
  configBasic(HELLO_MSG);
  config_pb();
  config_sw();
  CONFIG_LED1();
  configTimer3();
  config_cn();

  // Idle when the ISR doesn't run to reduce power consumption.
  while (1) {
    IDLE();
  }
}
