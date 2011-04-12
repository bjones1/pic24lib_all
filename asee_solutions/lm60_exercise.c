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
#include <stdio.h>

/** \file
 Modify this code to read the LM60 temperature sensor that is on the ASEE experiment board.
You will need to move the jumper on header JP1 to jumper pin 3 to pin 4;
this connects the LM60 temperature output to the AN0 input.
The LM60 output is 6.25 mV/°C with a DC offset of 424 mV.
Convert the ADC value to temperature values in both °C and °F and print this to the console.
Use float operations for simplicity.
 */

#define VREF 3.3  //assume Vref = 3.3 volts

int main (void) {
  uint16_t u16_adcVal;
  float f_adcVal;
  float f_tempC, f_tempF;

  configBasic(HELLO_MSG);
  CONFIG_AN0_AS_ANALOG();

  // Configure A/D to sample AN0 for 31 Tad periods in 10-bit mode
  // then perform a single conversion.
  configADC1_ManualCH0(ADC_CH0_POS_SAMPLEA_AN0, 31, 0);
  while (1) {
    u16_adcVal = convertADC1();   //get ADC value
    f_adcVal = u16_adcVal;
    f_adcVal = f_adcVal/1024.0 * VREF;  //convert to float in range 0.0 to VREF
    f_tempC = (f_adcVal - 0.424)/0.00625;
    f_tempF = f_tempC*9/5 + 32;
    printf("ADC input: %4.3f V, Temp: %4.4f (C), %4.4f (F) \n", (double) f_adcVal,
           (double)f_tempC, (double) f_tempF);
    DELAY_MS(300);   //delay so that we do not flood the UART.
    doHeartbeat();
  } //end while(1)

}
