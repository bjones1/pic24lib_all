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

/** \file
 * Generate an asymmetric square wave using output compare (OC1), continuous pulse mode.
 * This projects uses an external crystal for accuracy.
 * CLOCK_CONFIG=PRIPLL_8MHzCrystal_40MHzFCY is defined in the MPLAB project.
 * Remove this macro if you wish to use the internal oscillator.
*/

#ifndef SQWAVE_PWHIGH
#define SQWAVE_PWHIGH 2000   // desired PW High, in us
#endif
#ifndef SQWAVE_PERIOD
#define SQWAVE_PERIOD 20000  // desired period, in us
#endif


void  configTimer2(void) {
  T2CON = T2_OFF | T2_IDLE_CON | T2_GATE_OFF
          | T2_32BIT_MODE_OFF
          | T2_SOURCE_INT
          | T2_PS_1_64 ;  //1 tick = 1.6 us at FCY=40 MHz
  PR2 = usToU16Ticks(SQWAVE_PERIOD, getTimerPrescale(T2CONbits));
  TMR2  = 0;       //clear timer2 value
}

void configOutputCapture1(void) {
  T2CONbits.TON = 0;       //disable Timer when configuring Output compare
  CONFIG_RB8_AS_DIG_OUTPUT();
  CONFIG_OC1_TO_RP(8);        //map OC1 to RP8/RP13
//initialized the primary,secondary compare registers
//assumes TIMER2 initialized before OC1 so PRE bits are set
  OC1R = 0;   //go high when Timer2 == 0
  OC1RS = usToU16Ticks(SQWAVE_PWHIGH, getTimerPrescale(T2CONbits)); //go low when Timer2 == u16_sqwavePWHighTicks
//turn on the compare toggle mode using Timer2
  OC1CON = OC_TIMER2_SRC |     //Timer2 source
           OC_CONTINUE_PULSE;  //Continuous pulse mode
  _OC1IF = 0;
}

int main (void) {
  configBasic(HELLO_MSG);
  configTimer2();
  configOutputCapture1();
  T2CONbits.TON = 1;       //turn on Timer2 to start sqwave
  while (1) doHeartbeat(); //nothing to do, squarewave generated in hardware
}
