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


//Interrupt Service Routine for Timer3
void _ISR _T3Interrupt(void) {
  _T3IF = 0;                 //clear the timer interrupt bit
  update_state();
}

// in ms
#define ISR_PERIOD (15)
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

// main
// ====
// This code initializes the system, then runs the state machine above when
// the pushbutton's value changes.
int main (void) {
  // Configure the hardware.
  configBasic(HELLO_MSG);
  config_pb();
  CONFIG_LED1();
  configTimer3();

  // Initialize the state machine's extended state to its starting value.
  LED1 = 0;

  while (1) {
    // Blink the heartbeat LED to confirm that the program is running.
    doHeartbeat();
  }
}
