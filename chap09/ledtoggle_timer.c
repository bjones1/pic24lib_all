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
//    these files.
//
// *************************************************************************************
// ledtoggle_timer.c - toggle an LED using a periodic interrupt to poll the switch input
// *************************************************************************************
// Demonstrates the use of a period interrupt to sample a switch input, removes the need for debounce delays.

#include "pic24_all.h"
#include <stdio.h>

/// LED1
#define CONFIG_LED1() CONFIG_RB14_AS_DIG_OUTPUT()
#define LED1  _LATB14     //led1 state



void config_pb()  {
  CONFIG_RB13_AS_DIG_INPUT();
  ENABLE_RB13_PULLUP();
  // Give the pullup some time to take effect.
  DELAY_US(1);
}

void config_sw()  {
  CONFIG_RB12_AS_DIG_INPUT();
  ENABLE_RB12_PULLUP();
  // Give the pullup some time to take effect.
  DELAY_US(1);
}

#define PB_RAW         (_RB13)
#define SEL_RAW    (_RB12)


#define OFF 0
#define ON 1
#define SLOW_BLINK 500
#define FAST_BLINK 100


//debounced switch value that is set in the timer ISR
//any variable written by an ISR should be declared volatile
volatile uint8_t u8_pbValue = 1;  // initially high
volatile uint8_t u8_selValue = 1; // initially high

#define PB_PRESSED()   (u8_pbValue == 0)
#define PB_RELEASED()  (u8_pbValue == 1)

#define SELECT_1()     (u8_selValue == 1)
#define SELECT_0()     (u8_selValue == 0)

//Interrupt Service Routine for Timer3
void _ISRFAST _T3Interrupt (void) {
  u8_pbValue = PB_RAW;   //sample the push button
  u8_selValue = SEL_RAW; // sample the select switch
  _T3IF = 0;             // clear the timer interrupt bit
}

// State machine
// =============
// First, define the states, along with a human-readable version.

typedef enum  {
    STATE1,
    STATE1_TURN_LED_OFF,
    STATE1_WAIT_FOR_PRESS,
    STATE1_WAIT_FOR_RELEASED,
    STATE2,
    STATE2_WAIT_FOR_PRESS,
    STATE2_FLASH_LED_AND_WAIT_FOR_RELEASE,
    STATE2_TURN_LED_ON_AND_GOTO_STATE3,
    STATE3,
    STATE3_WAIT_FOR_PRESS,
    STATE3_WAIT_FOR_RELSEASE,
    STATE3_MAKE_SELECTION,
    STATE4,
    STATE4_BLINK_5_TIMES_OR_ESCAPE,
    STATE4_MAKE_SELECTION,
    STATE5,
    STATE5_BLINK_RAPIDLY_AND_WAIT_FOR_RELEASE,
    ERROR_STATE
} state_t;

const char* apsz_state_names[] = {
  "State 1",
  "State 1 - Turn LED Off",
  "State 1 - Wait for Press",
  "State 1 - Wait for Release & Goto State 2",
  "State 2",
  "State 2 - Wait for Press",
  "State 2 - Flash LED & Wait for Release",
  "State 2 - Turn LED On & Goto State 3",
  "State 3",
  "State 3 - Wait for Press",
  "State 3 - Wait for Relsease",
  "State 3 - Make Selection.  If select input = 1 goto (1), else goto step 4.",
  "State 4",
  "State 4 - Blink five times. If all five blinks complete, continue to selection.  Any press during the five blinks aborts and goto Step 5.",
  "State 4 - If select input = 0, go to State 1, else goto State 5. ",
  "State 5",
  "State 5 - Wait for release (if pressed) & Blink Rapidly, Goto State 1",
  "Error - Unknown State"
};

// Provide a convenient function to print out the state.
void print_state(state_t e_state) {
  static state_t e_last_state = 0xFFFF;  // Force an initial print of the state

  // Only print if the state changes.
  if (e_state != e_last_state) {
    e_last_state = e_state;
    // Verify that the state has a string representation before printing it.
    ASSERT(e_state <= N_ELEMENTS(apsz_state_names));
    outString(apsz_state_names[e_state]);
    outChar('\n');
  }
}

// This function defines the state machine.
void update_state() {
  static state_t e_state = STATE1;
  static uint8_t u8_counter;

  switch (e_state) {
      case STATE1:
          e_state = STATE1_TURN_LED_OFF;
          break;

      case STATE1_TURN_LED_OFF:
          LED1 = OFF;
          e_state = STATE1_WAIT_FOR_PRESS;
          break;

      case STATE1_WAIT_FOR_PRESS:
          if(PB_PRESSED()) // If pressed...
              e_state = STATE1_WAIT_FOR_RELEASED; // ... goto next step
          break;

      case STATE1_WAIT_FOR_RELEASED:
          if(PB_RELEASED()) // If released...
          {
              LED1 = ON;
              e_state = STATE2;
          }
          break;

      case STATE2:
          e_state = STATE2_WAIT_FOR_PRESS;
          break;

      case STATE2_WAIT_FOR_PRESS:
          if(PB_PRESSED()) // If pressed...
              e_state = STATE2_FLASH_LED_AND_WAIT_FOR_RELEASE; // goto next step
          break;

      case STATE2_FLASH_LED_AND_WAIT_FOR_RELEASE:
          LED1 = !LED1;
          DELAY_MS(SLOW_BLINK);
          if(PB_RELEASED())
              e_state = STATE2_TURN_LED_ON_AND_GOTO_STATE3;
          break;

      case STATE2_TURN_LED_ON_AND_GOTO_STATE3:
          LED1 = 1;
          e_state = STATE3;
          break;

      case STATE3:
          e_state = STATE3_WAIT_FOR_PRESS;
          break;

      case STATE3_WAIT_FOR_PRESS:
          if(PB_PRESSED())
              e_state = STATE3_WAIT_FOR_RELSEASE;
          break;

      case STATE3_WAIT_FOR_RELSEASE:
          if(PB_RELEASED())
              e_state = STATE3_MAKE_SELECTION;
          break;

      case STATE3_MAKE_SELECTION: // if select input = 1 goto (1), else goto next step.
          if(SELECT_1())
              e_state = STATE1;
          else
              e_state = STATE4;
          break;

      case STATE4:
          e_state = STATE4_BLINK_5_TIMES_OR_ESCAPE;
          u8_counter = 0;
          break;

      case STATE4_BLINK_5_TIMES_OR_ESCAPE:
          LED1 = u8_counter % 2;
          DELAY_MS(SLOW_BLINK);
          if(PB_PRESSED())
              e_state = STATE5;
          u8_counter++;
          printf("u8_counter = %d\nLED = %d\n", u8_counter, LED1);
          if(u8_counter >= 10) // Blink 5 times
              e_state = STATE4_MAKE_SELECTION;
          break;

      case STATE4_MAKE_SELECTION:
          if(SELECT_0())
              e_state = STATE1;
          else
              e_state = STATE5;
          break;

      case STATE5:
          e_state = STATE5_BLINK_RAPIDLY_AND_WAIT_FOR_RELEASE;
          break;

      case STATE5_BLINK_RAPIDLY_AND_WAIT_FOR_RELEASE:
          LED1 = !LED1;
          DELAY_MS(FAST_BLINK);
          if(PB_RELEASED())
              e_state = STATE1;
          break;

    default:
      e_state = ERROR_STATE;
  }

  print_state(e_state);
}

#define ISR_PERIOD     15                // in ms

void  configTimer3(void) {
  //ensure that Timer2,3 configured as separate timers.
  T2CONbits.T32 = 0;     // 32-bit mode off
  //T3CON set like this for documentation purposes.
  //could be replaced by T3CON = 0x0020
  T3CON = T3_OFF |T3_IDLE_CON | T3_GATE_OFF
          | T3_SOURCE_INT
          | T3_PS_1_64 ;  //results in T3CON= 0x0020
  PR3 = msToU16Ticks (ISR_PERIOD, getTimerPrescale(T3CONbits)) - 1;
  TMR3  = 0;                       //clear timer3 value
  _T3IF = 0;                       //clear interrupt flag
  _T3IP = 1;                       //choose a priority
  _T3IE = 1;                       //enable the interrupt
  T3CONbits.TON = 1;               //turn on the timer
}

int main (void) {

  configBasic(HELLO_MSG);

  /** PIO config ****/
  config_pb();
  config_sw();
  CONFIG_LED1();

  /* Timer configuration */
  configTimer3();

  LED1 = 0;

  while (1) {
    update_state();

    // Blink the heartbeat LED to confirm that the program is running.
    doHeartbeat();
  }
}
