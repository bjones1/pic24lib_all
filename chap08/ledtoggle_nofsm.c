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
A program that toggles an LED whenever a pushbutton switch is pressed
and released. Does not use a finite statement approach.
*/


// LED1 configuration and access
// =============================
#define CONFIG_LED1() CONFIG_RB14_AS_DIG_OUTPUT()
#define LED1 _LATB14     //led1 state

// Switch 1 configuration and access
// =================================
void config_sw1()  {
  CONFIG_RB13_AS_DIG_INPUT();
  ENABLE_RB13_PULLUP();
  // Give the pullup some time to take effect.
  DELAY_US(1);
}

#define SW1              _RB13
#define SW1_PRESSED()   (SW1 == 0)
#define SW1_RELEASED()  (SW1 == 1)

int main (void) {
  configBasic(HELLO_MSG);
  config_sw1();
  CONFIG_LED1();
  LED1 = 0;            //LED off initially
  while (1) {
    // The pushbutton is released. Wait for it not to be.
    while (SW1_RELEASED()) {
      doHeartbeat();
    }
    DELAY_MS(DEBOUNCE_DLY); //debounce
    // Loggle the LED on each press.
    LED1 = !LED1;  //toggle the LED

    // The pushbutton is pressed. Wait for it not to be.
    while (SW1_PRESSED()) {
      doHeartbeat();
    }
    DELAY_MS(DEBOUNCE_DLY); // debounce
  }
}
