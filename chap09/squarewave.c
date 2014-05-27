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
// ****************************************************************
// squarewave.c - Generates a square wave using timer 2 and an ISR.
// ****************************************************************

#include "pic24_all.h"

// Output the square wave on RB2.
#define WAVEOUT (_LATB2)
#define CONFIG_WAVEOUT() CONFIG_RB2_AS_DIG_OUTPUT()

// Interrupt Service Routine for Timer2.
void _ISR _T2Interrupt(void) {
  // Toggle the output pin to generate a square wave.
  WAVEOUT = !WAVEOUT;
  // Clear the timer interrupt bit, signaling the PIC that this interrupt has been serviced.
  _T2IF = 0;
}

// Define the time, in ms, between Timer2 interrupts.
#define ISR_PERIOD  (15)

void  configTimer2(void) {
  // T2CON is set like this for documentation purposes.
  // It could be replaced by T2CON = 0x0020.
  T2CON = T2_OFF | T2_IDLE_CON | T2_GATE_OFF
          | T2_32BIT_MODE_OFF
          | T2_SOURCE_INT
          | T2_PS_1_64;
  // Subtract 1 from ticks value assigned to PR2 because period is PRx + 1.
  PR2 = msToU16Ticks(ISR_PERIOD, getTimerPrescale(T2CONbits)) - 1;
  // Start with a cleared timer2 value.
  TMR2  = 0;
  // Enable Timer2 interrupts.
  _T2IF = 0;
  _T2IP = 1;
  _T2IE = 1;
  // Start the timer only after all timer-related configuration is complete.
  T2CONbits.TON = 1;
}

int main (void) {
  configBasic(HELLO_MSG);
  CONFIG_WAVEOUT();
  configTimer2();

  // The interrupt does work of generating the square wave; no code is needed here.
  while (1) {
    // Blink the heartbeat LED to show that the PIC is running.
    doHeartbeat();
  }
}
