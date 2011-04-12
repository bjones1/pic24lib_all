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
#include <pic24_all.h>
#include <dataXfer.h>

/** \file
Demonstrates pulse width modulation by
controlling the intensity of an LED. The
ADC input value on AN0 is used to vary the PWM
period.
*/

#ifndef PWM_PERIOD
#define PWM_PERIOD 1000  // desired period, in us
#endif

void  configTimer2(void) {
  T2CON = T2_OFF | T2_IDLE_CON | T2_GATE_OFF
          | T2_32BIT_MODE_OFF
          | T2_SOURCE_INT
          | T2_PS_1_8;
  PR2 = usToU16Ticks(PWM_PERIOD, getTimerPrescale(T2CONbits)) - 1;
  TMR2  = 0;       //clear timer2 value
  _T2IF = 0;
  _T2IP = 1;
  _T2IE = 1;    //enable the Timer2 interrupt
}


void configOutputCapture1(void) {
  T2CONbits.TON = 0;       //disable Timer when configuring Output compare
  CONFIG_OC1_TO_RP(14);        //map OC1 to RP14/RB14
//assumes TIMER2 initialized before OC1 so PRE bits are set
  OC1RS = 0;  //initially off
//turn on the compare toggle mode using Timer2
  OC1CON = OC_TIMER2_SRC |     //Timer2 source
           OC_PWM_FAULT_PIN_DISABLE;  //PWM, no fault detection
}

void _ISR _T2Interrupt(void) {
  uint32_t u32_temp;
  _T2IF = 0;    //clear the timer interrupt bit
  //update the PWM duty cycle from the ADC value
  u32_temp = ADC1BUF0;  //use 32-bit value for range
  //compute new pulse width that is 0 to 99% of PR2
  // pulse width (PR2) * ADC/4096
  u32_temp = (u32_temp * (PR2))>> 12 ;  // >>12 is same as divide/4096
  OC1RS = u32_temp;  //update pulse width value
  SET_SAMP_BIT_ADC1();      //start sampling and conversion
}

/// Indexes of all the variables to be transferred.
enum { U32_PW_NDX, OC1RS_NDX, ADC1BUF0_NDX };


int main(void) {
  uint32_t u32_pw;

  // Initialize
  configBasic(HELLO_MSG);
  initDataXfer();

  // All variables received by the PIC must be specified.
  // Params:  Index         Variable  PC can change  Format  Description
  SPECIFY_VAR(U32_PW_NDX,   u32_pw,   FALSE,         "%u",   "PWM pulse width (us)");
  SPECIFY_VAR(OC1RS_NDX,    OC1RS,    FALSE,         "%hu",  "Raw PWM value");
  SPECIFY_VAR(ADC1BUF0_NDX, ADC1BUF0, FALSE,         "%hu",  "Raw ADC value");

  // Configure PWM
  configTimer2();
  configOutputCapture1();
  CONFIG_AN0_AS_ANALOG();
  configADC1_ManualCH0( ADC_CH0_POS_SAMPLEA_AN0, 31, 1 );
  SET_SAMP_BIT_ADC1();      //start sampling and conversion
  T2CONbits.TON = 1;       //turn on Timer2 to start PWM

  // Report results only
  while (1) {
    u32_pw = ticksToUs(OC1RS, getTimerPrescale(T2CONbits));
    sendVar(U32_PW_NDX);
    sendVar(OC1RS_NDX);
    sendVar(ADC1BUF0_NDX);
    DELAY_MS(100);
    doHeartbeat();
  }
}
