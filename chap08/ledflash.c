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
// *********************************************
// ledflash.c - Flashes an LED, uses I/O macros.
// *********************************************
// A simple program that flashes the Power LED, uses I/O macros.
// RB15 is configured as an open drain output, and drives an LED at
// the junction between the LED and a pullup resistor to VDD. When
// RB15 is driven low, the LED is off. When RB15 is driven high,
// the RB15 output floats because of the open drain, and so the
// LED is turned on by the pullup resistor to VDD. This allows
// the power LED to function as a 'blinky' LED in addition to serving
// as a power indicator.

#include "pic24_all.h"


void config_led1() {
  CONFIG_RB15_AS_DIG_OUTPUT();
  ENABLE_RB15_OPENDRAIN();
}

// _LATB15 is the port register for RB15.
#define LED1 (_LATB15)

int main(void) {
  configClock();
  config_led1();
  LED1 = 0;
  while (1) {
    // Delay long enough to see LED blink.
    DELAY_MS(250);
    // Toggle the LED.
    LED1 = !LED1;
  } // end while (1)
}
