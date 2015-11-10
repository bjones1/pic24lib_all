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
// spi_master_revstring.c - SPI master uses slave to reverse strings
// *****************************************************************
// SPI example: PIC24 uC in Master mode talking to a PIC24 uC in slave mode, using
// the slave PIC24 uC (:doc:`spi_slave_revstring.c`) to reverse strings. The master
// expects the slave to assert a PIO output (SLAVE_ORDY in code) when a string
// has been reversed; the master then reads the string from the slave.


#include "pic24_all.h"

#define CONFIG_SLAVE_ENABLE() CONFIG_RB3_AS_DIG_OUTPUT()
#define SLAVE_ENABLE()      _LATB3 = 0  //low true assertion
#define SLAVE_DISABLE()     _LATB3 = 1

#define CONFIG_SLAVE_ORDY() CONFIG_RB2_AS_DIG_INPUT()
#define SLAVE_ORDY _RB2

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
    SPI_CKE_OFF          | //out changes inactive to active (CKE=0)
    SPI_MODE8_ON        | //8-bit mode
    MASTER_ENABLE_ON;     //master mode
#if (defined(__dsPIC33E__) || defined(__PIC24E__))
  //nothing to do here. On this family, the SPI1 port uses dedicated
  //pins for higher speed. The SPI2 port can be used with remappable pins.
#else
  CONFIG_SDO1_TO_RP(RB6_RP);      //use RB6 for SDO
  CONFIG_RB6_AS_DIG_OUTPUT();   //Ensure that this is a digital output
  CONFIG_SCK1OUT_TO_RP(RB7_RP);   //use RB7 for SCLK
  CONFIG_RB7_AS_DIG_INPUT();   //Ensure that this is a digital input
  CONFIG_SDI1_TO_RP(RB5_RP);      //use RP5 for SDI
  CONFIG_RB5_AS_DIG_INPUT();   //Ensure that this is a digital input
#endif
  CONFIG_SLAVE_ENABLE();     //slave select config
  CONFIG_SLAVE_ORDY();       //output ready from slave
  SLAVE_DISABLE();           //disable slave
  SPI1STATbits.SPIEN = 1;    //enable SPI mode
}

typedef enum  {
  STATE_GET_IN_STRING = 0,
  STATE_GET_REV_STRING,
} STATE;

void sendStringSPI1(char* psz_s1) {
  SLAVE_ENABLE();
  while (*psz_s1) {
    ioMasterSPI1(*psz_s1);
    psz_s1++;
  }
  ioMasterSPI1(*psz_s1);  //send null terminator
  SLAVE_DISABLE();
}

void getStringSPI1(char* psz_s1, uint16_t u16_maxCount) {
  uint16_t u16_i = 0;
  if (!u16_maxCount) return;
  SLAVE_ENABLE();
  do {
    *psz_s1 = ioMasterSPI1(0);  //send dummy byte to get byte back
    psz_s1++;
    u16_i++;
  } while (*(psz_s1-1) && (u16_i <u16_maxCount));
  SLAVE_DISABLE();
  psz_s1--;
  *psz_s1 = 0; //ensure string is null terminated
}


#define BUFSIZE 63
char  sz_1[BUFSIZE+1];

int main (void) {
  STATE e_mystate;
  configBasic(HELLO_MSG);
  configSPI1();
  e_mystate = STATE_GET_IN_STRING;
  while (1) {
    switch (e_mystate) {
      case STATE_GET_IN_STRING:
        inStringEcho(sz_1,BUFSIZE);   //get a string from the console
        if (*sz_1) {
          sendStringSPI1(sz_1);
          e_mystate = STATE_GET_REV_STRING;
        }
        break;
      case STATE_GET_REV_STRING:
        if (SLAVE_ORDY) {
          getStringSPI1(sz_1,BUFSIZE+1);
          outString(sz_1);       //output the reversed string
          outString("\n");
          e_mystate = STATE_GET_IN_STRING;
        }
        break;
      default:
        e_mystate = STATE_GET_IN_STRING;
    }
    doHeartbeat();
  } //end switch
}
