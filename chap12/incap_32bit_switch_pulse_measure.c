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
// ****************************************************************************************
// incap_32bit_switch_pulse_measure.c - Uses IC1,IC2 in cascade mode to measure pulse width
// ****************************************************************************************
// Measures the pulse width of pushbutton switching using IC1,IC2 in cascade mode.
// Timer 2 is used as the clock source, and pulse width is assume to not exceed
// the 32-bit range of cascade mode. This example only runs on dsPIC33E/PIC24E families.
// This example assumes a debounced switch.
// To configure this example to run with an external 8 MHz crystal for
// for a FCY=40MHz, define the C preprocessor macro: CLOCK_CONFIG=PRIPLL_8MHzCrystal_40MHzFCY
// and have an external crysal + 2 capacitors on the OSC1/OSC2 pins.
// Typical crystal accuracy for through hole is +/-20 pmm, so for a 100000 us
// pulse width measurement this is +/- 2 us.

#include "pic24_all.h"
#include <stdio.h>

#if (! (defined(__dsPIC33E__) || defined(__PIC24E__)))
# warning "This example only works with the dsPIC33E/PIC24E families"
int main(void) {
  return 0;
}
#else
typedef enum  {
  STATE_WAIT_FOR_FALL_EDGE = 0,
  STATE_WAIT_FOR_RISE_EDGE,
} ICSTATE;

ICSTATE e_isrICState = STATE_WAIT_FOR_FALL_EDGE;
volatile uint8_t u8_captureFlag = 0;
volatile union32 u32_lastCapture;
volatile union32 u32_thisCapture;
volatile uint32_t u32_pulseWidth;

void _ISRFAST _IC1Interrupt() {
  _IC1IF = 0;
  u32_thisCapture.u16.ls16 = IC1BUF;  //read LSW
  u32_thisCapture.u16.ms16 = IC2BUF;  //read MSW
  switch (e_isrICState) {
    case STATE_WAIT_FOR_FALL_EDGE:
      if (u8_captureFlag == 0) {
        u32_lastCapture = u32_thisCapture;
        e_isrICState = STATE_WAIT_FOR_RISE_EDGE;
      }
      break;
    case STATE_WAIT_FOR_RISE_EDGE:
      u32_pulseWidth = u32_thisCapture.u32 - u32_lastCapture.u32;  //get delta ticks
      u32_pulseWidth = ticksToUs(u32_pulseWidth,getTimerPrescale(T2CONbits)); //convert to microseconds
      u8_captureFlag = 1;
      e_isrICState = STATE_WAIT_FOR_FALL_EDGE;
      break;
    default:
      e_isrICState = STATE_WAIT_FOR_FALL_EDGE;
  }
}

/// Switch1 configuration
inline void CONFIG_SW1()  {
  CONFIG_RB13_AS_DIG_INPUT();     //use RB13 for switch input
  ENABLE_RB13_PULLUP();           //enable the pull-up
  DELAY_US(1);            //delay for pull-up
}



void configInputCapture(void) {
  CONFIG_IC1_TO_RP(RB13_RP);      //map IC1 to RB13
  CONFIG_IC2_TO_RP(RB13_RP);      //map IC2 to RB13
  //first, config the MSW (EVEN) module IC2 - configuration order matters!
  IC2CON1 = IC_TIMER2_SRC |     //Timer2 source
            IC_EVERY_EDGE;      //Capture every edge
  //cascade on, sync mode, no timer sync, just use clock source
  IC2CON2 = IC_IC32_ON| IC_SYNC_MODE | IC_SYNCSEL_NOSYNC;
  //now config LSW (ODD) module IC1
  IC1CON1 = IC_TIMER2_SRC |     //Timer2 source
            IC_INT_1CAPTURE |   //Interrupt every capture
            IC_EVERY_EDGE;      //Capture every edge
  //cascade on, sync mode, no timer sync, just use clock source
  IC1CON2 = IC_IC32_ON| IC_SYNC_MODE | IC_SYNCSEL_NOSYNC;
  _IC1IF = 0;
  _IC1IP = 2;   //higher than Timer2 so that Timer2 does not interrupt IC1
  _IC1IE = 1;   //enable
}

void  configTimer2(void) {
  T2CON = T2_OFF | T2_IDLE_CON | T2_GATE_OFF
          | T2_32BIT_MODE_OFF
          | T2_SOURCE_INT
          | T2_PS_1_8 ;  //1 tick = 0.2 us at FCY=40 MHz
  PR2 = 0xFFFF;                    //maximum period
  TMR2  = 0;                       //clear timer2 value
  _T2IP = 0;                       //interrupt disabled
  _T2IE = 0;                       //interrupt disabled
  T2CONbits.TON = 1;               //turn on the timer
}

int main (void) {
  configBasic(HELLO_MSG);
  CONFIG_SW1();    //use RB13
  configInputCapture();
  configTimer2();

  while (1) {
    outString("Press button...");
    while (!u8_captureFlag) doHeartbeat();
    printf(" %ld us\n",u32_pulseWidth);
    u8_captureFlag = 0;
  }
}
#endif
