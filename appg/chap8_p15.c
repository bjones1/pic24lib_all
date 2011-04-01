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


/** \file
Problem 8.13
*/

/// LED1
#define CONFIG_LED1() CONFIG_RB14_AS_DIG_OUTPUT()
#define LED1  _LATB14     //led1 state
/// LED1
#define CONFIG_LED2() CONFIG_RB12_AS_DIG_OUTPUT()
#define LED2  _LATB12     //led1 state

/// Switch1 configuration
inline void CONFIG_SW1()  {
  CONFIG_RB13_AS_DIG_INPUT();     //use RB13 for switch input
  ENABLE_RB13_PULLUP();           //enable the pullup
}
#define SW1              _RB13  //switch state
#define SW1_PRESSED()   SW1==0  //switch test
#define SW1_RELEASED()  SW1==1  //switch test

typedef enum  {
  STATE_WAIT_FOR_PRESS,
  STATE_WAIT_FOR_RELEASE,
} STATE;

void changeLEDs() {
  if (!LED1 && !LED2) {
    LED2 = 1;
    return;
  }
  if (!LED1 && LED2) {
    LED1 = 1;
    LED2 = 0;
    return;
  }
  if (LED1 && !LED2) {
    LED2 = 1;
    return;
  }
  if (LED1 && LED2) {
    LED1 = 0;
    LED2 = 0;
    return;
  }
}

int main(void) {
  STATE e_mystate;
  configBasic(HELLO_MSG);
  CONFIG_SW1();
  CONFIG_LED1();
  CONFIG_LED2();
  e_mystate = STATE_WAIT_FOR_PRESS ;
  LED1 = 0;
  LED2 = 0; //LEDs are off.
  while (1) {
    switch (e_mystate) {
      case STATE_WAIT_FOR_PRESS :
        if (SW1_PRESSED()) {
          e_mystate = STATE_WAIT_FOR_RELEASE;
          changeLEDs();  //change the LED states
        }
        break;
      case STATE_WAIT_FOR_RELEASE :
        if (SW1_RELEASED()) {
          e_mystate = STATE_WAIT_FOR_PRESS;
          changeLEDs();  //change the LED states
        }
        break;
      default:
        e_mystate = STATE_WAIT_FOR_PRESS;
    }//end switch(e_mystate)
    DELAY_MS(DEBOUNCE_DLY);   //Debounce
    doHeartbeat();     //ensure that we are alive
  }//end while
}//end main
