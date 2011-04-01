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
 * Change notification exercise:
 * Enable change notification on SW1, SW2
 * Use a change notification interrupt to detect a change on either of these
 * pins, print a message identifying which one trigerred the event.
 * Have the processor sleep while waiting for a change notification interrupt.
 * Use RB13 and RB12 as the switch inputs, you must enable the change notification
 * interrupt and weak pullup on these ports, and configure them as inputs.
*/

//Interrupt Service Routine for Change Notification
void _ISRFAST _CNInterrupt (void) {
  _CNIF = 0;    //clear the change notification interrupt bit
}

#define SW1              _RB13  //switch state
/// Switch1 configuration
inline void CONFIG_SW1()  {
  CONFIG_RB13_AS_DIG_INPUT();     //use RB13 for switch input
  ENABLE_RB13_PULLUP();           //enable the pullup
  ENABLE_RB13_CN_INTERRUPT();     //CN14IE = 1
}

#define SW2              _RB12  //switch state
/// Switch2 configuration
inline void CONFIG_SW2()  {
  CONFIG_RB12_AS_DIG_INPUT();     //use RB12 for switch input
  ENABLE_RB12_PULLUP();           //enable the pullup
  ENABLE_RB12_CN_INTERRUPT();     //CN13IE = 1
}

int main (void) {
  uint8 u8_sw1old, u8_sw2old;

  configBasic(HELLO_MSG);
  /** Configure the switch ***********/
  CONFIG_SW1();  //enables individual CN interrupt also
  CONFIG_SW2();  //enables individual CN interrupt also
  DELAY_US(1);   //delay for pullup
  /** Configure Change Notification general interrupt  */
  _CNIF = 0;         //Clear the interrupt flag
  _CNIP = 2;         //Choose a priority
  _CNIE = 1;         //enable the Change Notification general interrupt
  while (1) {
    u8_sw1old = SW1;
    u8_sw2old = SW2;
    outString("Entering Sleep mode. Press SW1 or SW2 to wake.\n");
    // Finish sending characters before sleeping
    WAIT_UNTIL_TRANSMIT_COMPLETE_UART1();
    SLEEP();         //macro for asm("pwrsav #0")
    DELAY_MS(10);    //wait for switch bounce to clear
    if (u8_sw1old != SW1) outString ("SW1 triggered!\n");
    if (u8_sw2old != SW2) outString ("SW2 triggered!\n");
  }
}
