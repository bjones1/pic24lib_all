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
UART Exercise: Autobaud Function

This code has an uncomplete 'autobaud()' function whose goal is
to find the baud rate that matches an incoming stream of '0' (hex 0x30 value)
characters.  The main 'while(1)' loop calls 'autobaud()' if it detects
a UART error has occurred or if the input character was not a '0'.

The baud rates to adjust to are contained in the au32_baudRates[] array.

For reading a character, the 'myInChar1()' function is used, which returns
the error for the last read character in the global variable u8_lastRxError,
as the value 'NO_ERROR', 'PARITY_ERROR', 'FRAMING_ERROR', or 'OVERRUN_ERROR'.
See the code for the function 'myCheckRxErrorUART1()' that is called from
within 'myInChar1()' for details.

Complete the 'autoBaud()' function. A suggested approach is step through the
au32_baudRates[] array, setting the UART to each baud rate. At a target baud
rate, receive two characters. If both of the characters are received with no
UART error, and match the SYNC_CHAR (0x30), then assume the target baudrate
has been found, and print out the current baud rate before exiting.

The macro:   CONFIG_BAUDRATE_UART1 (uint32_t baudRate)
can be used to set the baudrate.

*/

#define SYNC_CHAR 0x30     //'0'

#define CONFIG_LED1() CONFIG_RB14_AS_DIG_OUTPUT()
#define LED1  _LATB14     //led1 state

#define NO_ERROR     0
#define PARITY_ERROR 1
#define FRAMING_ERROR 2
#define OVERRUN_ERROR 3

uint8_t myCheckRxErrorUART1(void) {
  uint8_t u8_c, u8_err;

  u8_err = NO_ERROR;
  if (U1STAbits.PERR) {
    u8_c = U1RXREG; //clear error
    u8_err = PARITY_ERROR;
  }
  if (U1STAbits.FERR) {
    u8_c = U1RXREG; //clear error
    u8_err = FRAMING_ERROR;
  }
  if (U1STAbits.OERR) {
    U1STAbits.OERR = 0; //clear error
    u8_err = OVERRUN_ERROR ;
  }
  return u8_err;
}


uint8_t u8_lastRxError;

uint8_t myInChar1(void) {
  //do heartbeat while waiting for character.
  while (!IS_CHAR_READY_UART1())  doHeartbeat();
  u8_lastRxError = myCheckRxErrorUART1();
  LED1 = !LED1;  //toggle an LED to show a character was received
  if (u8_lastRxError == NO_ERROR) return U1RXREG;  //read the receive register
  else return 0;
}

#define NUM_BAUDS 5
uint32_t au32_baudRates[] = {19200,28800,38400,57600,115200};


//Complete this function
void autoBaud(void) {

}


int main (void) {
  uint8_t u8_c;
  configBasic(HELLO_MSG);
  CONFIG_LED1();
  while (1) {
    u8_c = myInChar1();
    if (u8_c != SYNC_CHAR || u8_lastRxError != NO_ERROR) autoBaud();
    else {
      outChar(u8_c);
      outString("\n");
    }
  }
}
