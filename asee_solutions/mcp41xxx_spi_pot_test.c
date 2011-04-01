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
SPI example: PIC24 uC in Master mode to Microchip MCP41xxx Digital Potentiometer
This code tests the MCP4010 SPI digital potentiometer on the ASEE board by setting
the wiper value to an 8-bit value that is entered by the user. The potentiometer is
connected to 3.3 V and ground, so the wiper output voltage will be  wiper_value/256*3.3.
On Header JP1, jumper pin 7 to pin 8 to connect the potentiometer wiper output to
the PIC24 AN1 input.  Use the ADC to read this voltage, and compute the difference
between expected and actual voltages and print this information to the console.
*/

#define CONFIG_SLAVE_ENABLE() CONFIG_RB1_AS_DIG_OUTPUT()
#define SLAVE_ENABLE()        _LATB1 = 0  //low true assertion
#define SLAVE_DISABLE()       _LATB1 = 1


void configSPI1(void) {
  //spi clock = 40MHz/1*4 = 40MHz/4 = 10MHz
  SPI1CON1 = SEC_PRESCAL_1_1 |     //1:1 secondary prescale
             PRI_PRESCAL_4_1 |     //4:1 primary prescale
             CLK_POL_ACTIVE_HIGH | //clock active high (CKP = 0)
             SPI_CKE_ON          | //out changes active to inactive (CKE=1)
             SPI_MODE8_ON        | //8-bit mode
             MASTER_ENABLE_ON;     //master mode
  SPI1STATbits.SPIEN = 1;  //enable SPI mode
  //configure pins. Only need SDO, SCLK since POT is output only
  CONFIG_SDO1_TO_RP(6);      //use RP6 for SDO
  CONFIG_RP6_AS_DIG_PIN();   //ensure that analog is disabled
  CONFIG_SCK1OUT_TO_RP(7);   //use RP7 for SCLK
  CONFIG_RP7_AS_DIG_PIN();   //ensure that analog is disabled
  CONFIG_SLAVE_ENABLE();       //chip select for MCP41xxx
  SLAVE_DISABLE();             //disable the chip select
}

void setPotWiper(uint8 u8_i) {
  SLAVE_ENABLE();         //assert MCP41xxx chipselect
  ioMasterSPI1(0x11);   //command byte to select wiper register
  ioMasterSPI1(u8_i);
  SLAVE_DISABLE();         //negate MCP41xxx chipselect
}

#define BUFSIZE 15
char  sz_1[BUFSIZE+1];

int main (void) {
  uint16 u16_pv;
  uint16 u16_adcVal;
  float f_adcVal;
  float f_potVal;
  float f_err;

  configBasic(HELLO_MSG);
  configSPI1();
  CONFIG_AN1_AS_ANALOG();
  configADC1_ManualCH0(ADC_CH0_POS_SAMPLEA_AN1, 31, 0);

  while (1) {
    outString("Input decimal value (0-255): ");
    inString(sz_1,BUFSIZE);
    sscanf(sz_1,"%d",  (int *) &u16_pv);
    printf("\nSending %d to pot.\n",u16_pv);
    setPotWiper(u16_pv & 0x00FF);
    //expected pot Voltage
    f_potVal = 3.3*u16_pv/256;
    u16_adcVal = convertADC1();   //get ADC value
    f_adcVal = u16_adcVal;
    f_adcVal = f_adcVal/1024.0 * 3.3;  //convert to float in range 0.0 to VREF
    f_err = f_potVal - f_adcVal;
    printf("ADC input: %5.3f V, Expected: %5.3f V, diff: %5.3f V \n",
           (double) f_adcVal, (double) f_potVal, (double) f_err);

  }
}
