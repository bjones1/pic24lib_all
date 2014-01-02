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
// ***********************************************************************************************
// softfilt_test.c - Implements a software filter for input pulses less than a specified duration.
// ***********************************************************************************************

#include "pic24_all.h"


// Use RB9 as the test output (TOUT).
#define CONFIG_TOUT() CONFIG_RB9_AS_DIG_OUTPUT()
#define TOUT  (_LATB9)

// Use RB8 as the raw test input (TIN).
#define CONFIG_TIN_RAW()  CONFIG_RB8_AS_DIG_INPUT();
#define TIN_RAW (_RB8)


// Define the time, in ms, between Timer3 interrupts.
#define ISR_PERIOD (1)
// The software filter only passes changes in the TIN input if the TIN input is stable for MIN_STABLE number of milliseconds
#define MIN_STABLE (15)
// The minimum number of timer3 interrupts that TIN must be stable for in order for a new value to pass through the filter.
#define MIN_STABLECOUNT  (MIN_STABLE/ISR_PERIOD)


uint16_t u16_stableCountTIN = 0;
uint8_t u8_rawTIN = 0;
uint8_t u8_oldrawTIN = 0;


// Debounced switch value that is set in the timer ISR.
// Any variable written by an ISR, and accessed outside of the ISR
// should be declared volatile.
volatile uint8_t u8_valueTIN = 0;

// Interrupt Service Routine for Timer3
void _ISR _T3Interrupt(void) {
  u8_rawTIN = TIN_RAW;     //sample the switch
  if (u8_rawTIN != u8_oldrawTIN) {
    //changed values, zero the stability counter
    u16_stableCountTIN = 0;
    u8_oldrawTIN = u8_rawTIN;
  } else {
    u16_stableCountTIN++;
    if (u16_stableCountTIN >= MIN_STABLECOUNT) {
      //new value is ready!
      u8_valueTIN = u8_rawTIN;
    }
  }
  _T3IF = 0;                 //clear the timer interrupt bit
}

void  configTimer3(void) {
  // Ensure that Timer2,3 configured as separate timers.
  T2CONbits.T32 = 0;     // 32-bit mode off
  // T3CON set like this for documentation purposes.
  T3CON = T3_OFF |T3_IDLE_CON | T3_GATE_OFF
          | T3_SOURCE_INT
          | T3_PS_1_1;
  // Subtract 1 from ticks value assigned to PR3 because period is PRx + 1.
  PR3 = msToU16Ticks(ISR_PERIOD, getTimerPrescale(T3CONbits)) - 1;
  // Start with a cleared timer2 value.
  TMR3  = 0;
  // Enable Timer3 interrupts.
  _T3IF = 0;
  _T3IP = 1;
  _T3IE = 1;
  // Start the timer only after all timer-related configuration is complete.
  T3CONbits.TON = 1;
}

uint8_t u8_oldvalueTIN = 0;

// Define the pulse width of TOUT in ms.
#define TPW  (20)

int main(void) {
  configBasic(HELLO_MSG);
  // TOUT drives TIN.
  TOUT = 0;
  CONFIG_TIN_RAW();
  CONFIG_TOUT();
  configTimer3();

  while (1) {
    TOUT = !TOUT;
    DELAY_MS(TPW);
    if (u8_valueTIN != u8_oldvalueTIN) {
      u8_oldvalueTIN = u8_valueTIN;
      outString("*");
    }
  }
}
