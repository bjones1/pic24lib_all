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
// *****************************************************************
// outcompare_squarewave_24e.c - generates a square wave using output compare, demos a mode available only on dsPIC33e/PIC24E
// *****************************************************************
// Generates a square wave using output compare (OC1). The internal timer uses
// the Timer2 clock2 and is synchrononized to the OCxRS match event, which means
// that  the internal timer resets to zero on OCxRS match.  This example only works
// on the PIC24E/dsPIC33E

#include "pic24_all.h"
#if (! (defined(__dsPIC33E__) || defined(__PIC24E__)))
#error "This example only works with the dsPIC33E/PIC24E families"
#endif

#define SQWAVE_PERIOD 5000   // desired period, in us
void  configTimer2(void) {
  T2CON = T2_OFF | T2_IDLE_CON | T2_GATE_OFF
          | T2_32BIT_MODE_OFF
          | T2_SOURCE_INT
          | T2_PS_1_64 ;  //1 tick = 1.6 us at FCY=40 MHz
  PR2 = 0xFFFF;    //maximum period
  TMR2  = 0;       //clear timer2 value
}


void configOutputCompare1(void) {
  T2CONbits.TON = 0;       //disable Timer when configuring Output compare
  CONFIG_OC1_TO_RP(RB5_RP);     //map OC1 to RB5
//use OC1R to set pulse high, OC1RS to set pulse low, timer reset on OC1RS match.
//assumes TIMER2 initialized before OC1 so PRE bits are set
  OC1RS = usToU16Ticks(SQWAVE_PERIOD/2, getTimerPrescale(T2CONbits));   //used to reset timer
  OC1R = OC1RS/2;    //1/4 period
  OC1CON1 = OC_TIMER2_SRC |         //Timer2 source
            OC_TOGGLE_PULSE;        //single compare toggle
  OC1CON2 = OC_SYNCSEL_OCxRS;       //reset internal timer when OCxRS match occurs
}

int main (void) {
  configBasic(HELLO_MSG);
  configTimer2();
  configOutputCompare1();
  T2CONbits.TON = 1;       //turn on Timer2 to start sqwave
  while (1) doHeartbeat(); //nothing to do, squarewave generated in hardware
}
