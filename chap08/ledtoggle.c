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
// ********************************************************************************************************
// ledtoggle.c - Uses an FSM approach to toggle an LED whenever a pushbutton input is pressed and released.
// ********************************************************************************************************
// A program that uses a finite state machine approach for toggling an LED whenever a pushbutton switch is pressed and released. Demonstrates the use of debounce delays when polling a switch input.

#include "pic24_all.h"

// LED1 configuration and access
// =============================
#define CONFIG_LED1() CONFIG_RB14_AS_DIG_OUTPUT()
#define LED1 (_LATB14)     //led1 state

// Pushbutton configuration and access
// ===================================
void config_pb()  {
#if (HARDWARE_PLATFORM == EMBEDDED_C1)
  CONFIG_RB7_AS_DIG_INPUT();
  ENABLE_RB7_PULLUP();
#else
  CONFIG_RB13_AS_DIG_INPUT();
  ENABLE_RB13_PULLUP();
#endif
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

// State machine
// =============
// First, define the states, along with a human-readable version.

typedef enum  {
  STATE_PRESSED,
  STATE_RELEASED,
} state_t;

const char* apsz_state_names[] = {
  "STATE_PRESSED",
  "STATE_RELEASED",
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
  static state_t e_state = STATE_RELEASED;

  switch (e_state) {
    case STATE_RELEASED:
      if (PB_PRESSED()) {
        e_state = STATE_PRESSED;
        LED1 = !LED1;
      }
      break;

    case STATE_PRESSED:
      if (PB_RELEASED()) {
        e_state = STATE_RELEASED;
      }
      break;

    default:
      ASSERT(0);
  }

  print_state(e_state);
}

// main
// ====
// This code initializes the system, then runs the state machine above when
// the pushbutton's value changes.
int main (void) {
  // Configure the hardware.
  configBasic(HELLO_MSG);
  config_pb();
  CONFIG_LED1();

  // Initialize the state machine's extended state to its starting value.
  LED1 = 0;

  while (1) {
    update_state();

    // Debounce the switch by waiting for bounces to die out.
    DELAY_MS(DEBOUNCE_DLY);

    // Blink the heartbeat LED to confirm that the program is running.
    doHeartbeat();
  }
}
