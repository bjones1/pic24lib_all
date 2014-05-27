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
// *************************************************************************
// ledsw1.c - Demonstrates using a FSM approach for a LED/switch IO problem.
// *************************************************************************
// A program that uses a finite state machine approach for implementing switch/LED input/output.

#include <stdio.h>
#include "pic24_all.h"

// LED1 configuration and access
// =============================
#define CONFIG_LED1() CONFIG_RB14_AS_DIG_OUTPUT()
#define LED1 (_LATB14)     //led1 state

// Pushbutton configuration and access
// ===================================
void config_pb()  {
  CONFIG_RB13_AS_DIG_INPUT();
  ENABLE_RB13_PULLUP();
  // Give the pullup some time to take effect.
  DELAY_US(1);
}

#if (HARDWARE_PLATFORM == EMBEDDED_C1)
# define PB_PRESSED()   (_RB7 == 0)
# define PB_RELEASED()  (_RB7 == 1)
#else
# define PB_PRESSED()   (_RB13 == 0)
# define PB_RELEASED()  (_RB13 == 1)
#endif

// Switch configuration and access
// ===============================
void config_sw()  {
  CONFIG_RB12_AS_DIG_INPUT();
  ENABLE_RB12_PULLUP();
  // Give the pullup some time to take effect.
  DELAY_US(1);
}

#define SW              (_RB12)

// State machine
// =============
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
  "STATE_RELEASED3_BLINK - LED blinks 5x, waiting for PB press",
  "STATE_PRESSED3 - LED is on",
};

// Provide a convenient function to print out the state.
void print_state(state_t e_state) {
  // Force an initial print of the state
  static state_t e_last_state = 0xFFFF;

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
void update_state(void) {
  static state_t e_state = STATE_RELEASED1;
  // The number of times the LED was toggled in the blink state
  static uint16_t u16_led_toggles;

  switch (e_state) {
    case STATE_RELEASED1:
      LED1 = 0;
      if (PB_PRESSED()) {
        e_state = STATE_PRESSED1;
      }
      break;

    case STATE_PRESSED1:
      if (PB_RELEASED()) {
        e_state = STATE_RELEASED2;
      }
      break;

    case STATE_RELEASED2:
      LED1 = 1;
      if (PB_PRESSED()) {
        e_state = STATE_PRESSED2;
      }
      break;

    case STATE_PRESSED2:
      if (PB_RELEASED() && SW) {
        e_state = STATE_RELEASED3_BLINK;
        // Zero the toggled count when entering the blink state.
        u16_led_toggles = 0;
      }
      if (PB_RELEASED() && !SW) {
        e_state = STATE_RELEASED1;
      }
      break;

    case STATE_RELEASED3_BLINK:
      // Toggle the LED.
      LED1 = !LED1;
      u16_led_toggles++;
      printf("toggles = %d\n", u16_led_toggles);
      // Delay to make LED blinks visible
      DELAY_MS(250);

      if (u16_led_toggles >= 10) {
        e_state = STATE_RELEASED1;
      }
      if (PB_PRESSED()) {
        e_state = STATE_PRESSED3;
      }
      break;

    case STATE_PRESSED3:
      LED1 = 1;
      if (PB_RELEASED()) {
        e_state = STATE_RELEASED1;
      }
      break;

    default:
      ASSERT(0);
  }

  print_state(e_state);
}

int main(void) {
  // Configure the hardware.
  configBasic(HELLO_MSG);
  config_pb();
  config_sw();
  CONFIG_LED1();

  // Initialize the state machine to its starting state.
  LED1 = 0;

  while (1) {
    update_state();

    // Debounce the switch by waiting for bounces to die out.
    DELAY_MS(DEBOUNCE_DLY);

    // Blink the heartbeat LED to confirm that the program is running.
    doHeartbeat();
  }
}
