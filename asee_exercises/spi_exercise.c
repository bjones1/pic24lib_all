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
 *  SPI Exercise: PIC24 uC in Master mode to Maxim DS1722 Digital Thermometer
 * Change this code to use one-shot Temperature conversions instead of continuous conversions,
 * and to poll the DS1722 to determine when the conversion is finished (the software delay
 * should be removed).
 * To disable continuous conversions, the LSbit of the value written to the configuration register
 * must be a '1' (this bit is called the "SD" bit in the datasheet).
 * To start a conversion, bit #4 (called the "1SHOT" bit in the datasheet) of the
 * configuration register value must
 * be written with a '1', this bit will be cleared when the conversion is done.
 * To read the configuration register, write a '0x00' to access the register, then a second
 * write (write value is a don't care) returns the configuration register value.
 *
 * The while(1) loop should be changed to trigger a conversion, then poll the configuration
 * register until the conversion is finished.
 * You may want to write a '*' character to the console in your polling loop in order to
 * give an indication on how many unsuccessful polls are done before the conversion is done.
 *
*/

#define CONFIG_SLAVE_ENABLE() CONFIG_RB2_AS_DIG_OUTPUT()
#define SLAVE_ENABLE()        _LATB2 = 1  //high true assertion
#define SLAVE_DISABLE()       _LATB2 = 0

void configSPI1(void) {
  //spi clock = 40MHz/1*4 = 40MHz/4 = 10MHz
  SPI1CON1 = SEC_PRESCAL_1_1 |     //1:1 secondary prescale
             PRI_PRESCAL_4_1 |     //4:1 primary prescale
             CLK_POL_ACTIVE_HIGH   | //clock active high (CKP = 0)
             SPI_CKE_OFF          | //out changes inactive to active (CKE=0)
             SPI_MODE8_ON        | //8-bit mode
             MASTER_ENABLE_ON;     //master mode
  //configure pins. Only need SDO, SCLK since POT is output only
  CONFIG_SDO1_TO_RP(6);      //use RP6 for SDO
  CONFIG_RP6_AS_DIG_PIN();   //Ensure that analog is disabled
  CONFIG_SCK1OUT_TO_RP(7);   //use RP7 for SCLK
  CONFIG_RP7_AS_DIG_PIN();   //Ensure that analog is disabled
  CONFIG_SDI1_TO_RP(5);      //use RP5 for SDI
  CONFIG_RP5_AS_DIG_PIN();   //Ensure that analog is disabled
  CONFIG_SLAVE_ENABLE();       //chip select for MCP41xxx
  SLAVE_DISABLE();             //disable the chip select
  SPI1STATbits.SPIEN = 1;  //enable SPI mode
}

void writeConfigDS1722(uint8_t u8_i) {
  SLAVE_ENABLE();       //assert chipselect
  ioMasterSPI1(0x80);   //config address
  ioMasterSPI1(u8_i);   //config value
  SLAVE_DISABLE();
}

int16_t readTempDS1722() {
  uint16_t u16_lo, u16_hi;
  SLAVE_ENABLE();       //assert chipselect
  ioMasterSPI1(0x01);   //LSB address
  u16_lo = ioMasterSPI1(0x00); //read LSByte
  u16_hi = ioMasterSPI1(0x00); //read MSByte
  SLAVE_DISABLE();
  return((u16_hi<<8) | u16_lo);
}

int main (void) {
  int16_t i16_temp;
  float  f_tempC,f_tempF;
  configBasic(HELLO_MSG);
  configSPI1();
  writeConfigDS1722(0xE8); //12-bit mode
  while (1) {
    DELAY_MS(1500);
    i16_temp = readTempDS1722();
    f_tempC = i16_temp;  //convert to floating point
    f_tempC = f_tempC/256;  //divide by precision
    f_tempF = f_tempC*9/5 + 32;
    printf("Temp is: 0x%0X, %4.4f (C), %4.4f (F)\n", i16_temp, (double) f_tempC, (double) f_tempF);
  }
}
