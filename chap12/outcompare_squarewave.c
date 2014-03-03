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
// ********************************************************************************************
// outcompare_squarewave.c - generates a square wave using output compare (PIC24F/H/E families)
// ********************************************************************************************
// Generates a square wave using output compare (OC1). The example uses
// the Timer2 clock2 and is compatible with the PIC24F/H/E families

#include "pic24_all.h"


#define SQWAVE_PERIOD 5000   // desired period, in us

void  configTimer2(void) {
  T2CON = T2_OFF | T2_IDLE_CON | T2_GATE_OFF
          | T2_32BIT_MODE_OFF
          | T2_SOURCE_INT
          | T2_PS_1_64 ;  //1 tick = 1.6 us at FCY=40 MHz
  PR2 = usToU16Ticks(SQWAVE_PERIOD/2,getTimerPrescale(T2CONbits)) -1;
  TMR2 = 0;  //clear timer2 value
}

void configOutputCompare1(void) {
  T2CONbits.TON = 0;         //disable Timer when configuring Output compare
  CONFIG_OC1_TO_RP(RB5_RP);  //map OC1 to RB5
  //initialize the compare register to 1/4 the squarewave period
  //assumes TIMER2 initialized before OC1 so PRE bits are set
  OC1R = usToU16Ticks(SQWAVE_PERIOD/4, getTimerPrescale(T2CONbits));
#ifdef OC1CON1
  OC1CON1 = OC_TIMER2_SRC |      //Timer2 source
            OC_TOGGLE_PULSE;     //single compare toggle
  OC1CON2 = OC_SYNCSEL_TIMER2;   //synchronize to timer2
#else
  OC1CON = OC_TIMER2_SRC |      //Timer2 source
           OC_TOGGLE_PULSE;     //single compare toggle
#endif
}

int main (void) {
  configBasic(HELLO_MSG);
  configTimer2();
  configOutputCompare1();
  T2CONbits.TON = 1;       //turn on Timer2 to start sqwave
  while (1) doHeartbeat(); //nothing to do, squarewave generated in hardware
}
