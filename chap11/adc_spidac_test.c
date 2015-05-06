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
// ****************************************************************************************************************************************************
// adc_spidac_test.c - Demonstrates reading the internal ADC in 12-bit mode and then sending the upper 8 bits to an external 8-bit SPI DAC (MAXIM 548A)
// ****************************************************************************************************************************************************
// Demonstrates reading the internal ADC in 12-bit mode and
// then sending the upper 8-bits to an external
// 8-bit SPI DAC (MAXIM 548A)

#include "pic24_all.h"
#include <stdio.h>

#define CONFIG_SLAVE_ENABLE() CONFIG_RB3_AS_DIG_OUTPUT()
#define SLAVE_ENABLE()        _LATB3 = 0  //low true assertion
#define SLAVE_DISABLE()       _LATB3 = 1


void configSPI1(void) {
  SPI1CON1 =
#if (defined(__dsPIC33E__) || defined(__PIC24E__))
    //spi clock = 60MHz/1*6 = 60MHz/4 = 10MHz
    PRI_PRESCAL_1_1 |     //1:1 primary prescale
    SEC_PRESCAL_6_1 |     //6:1 secondary prescale
#else
    //spi clock = 40MHz/4*1 = 40MHz/4 = 10MHz
    PRI_PRESCAL_4_1 |     //4:1 primary prescale
    SEC_PRESCAL_1_1 |     //1:1 secondary prescale
#endif
    CLK_POL_ACTIVE_HIGH   | //clock active high (CKP = 0)
    SPI_CKE_ON          | //out changes active to inactive (CKE=1)
    SPI_MODE8_ON        | //8-bit mode
    MASTER_ENABLE_ON;     //master mode
#if (defined(__dsPIC33E__) || defined(__PIC24E__))
  //nothing to do here. On this family, the SPI1 port uses dedicated
  //pins for higher speed. The SPI2 port can be used with remappable pins.
  //you may need to add code to disable analog functionality if the SPI ports
  //are on analog-capable pins.
#else
  CONFIG_SDO1_TO_RP(RB6_RP);      //use RP6 for SDO
  CONFIG_SCK1OUT_TO_RP(RB7_RP);   //use RP7 for SCLK
#endif

  SPI1STATbits.SPIEN = 1;  //enable SPI mode
}
void configDAC() {
  CONFIG_SLAVE_ENABLE();       //chip select for DAC
  SLAVE_DISABLE();             //disable the chip select
}

void writeDAC (uint8_t dacval) {
  SLAVE_ENABLE();                 //assert Chipselect line to DAC
  ioMasterSPI1(0b00001001);      //control byte that enables DAC A
  ioMasterSPI1(dacval);          //write DAC value
  SLAVE_DISABLE();
}

// assume Vref = 3.3 volts
#define VREF (3.3)

int main (void) {
  uint16_t u16_adcVal;
  uint8_t u8_dacVal;
  float f_adcVal;
  float f_dacVal;

  configBasic(HELLO_MSG);
  CONFIG_RA0_AS_ANALOG();
  // Configure A/D to sample AN0 for 31 Tad periods in 12-bit mode
  // then perform a single conversion.
  configADC1_ManualCH0(RA0_AN, 31, 1);
  configSPI1();
  configDAC();
  while (1) {
    u16_adcVal = convertADC1();   //get ADC value
    u8_dacVal = (u16_adcVal>>4) & 0x00FF;  //upper 8 bits to DAC value
    writeDAC(u8_dacVal);
    f_adcVal = u16_adcVal;
    f_adcVal = f_adcVal/4096.0 * VREF;  //convert to float 0.0 to VREF
    f_dacVal = u8_dacVal;
    f_dacVal = f_dacVal/256.0 * VREF;
    printf("ADC in: %4.3f V (0x%04x), To DAC: %4.3f V (0x%02x) \n",
           (double) f_adcVal, u16_adcVal, (double) f_dacVal, u8_dacVal);
    DELAY_MS(300);   //delay so that we do not flood the UART.
  } //end while(1)

}
