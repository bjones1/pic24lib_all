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
Problem 8.19
*/

/// GATE
#define CONFIG_GATE_A() CONFIG_RB14_AS_DIG_OUTPUT()
#define GATE_A  _LATB14
#define CONFIG_GATE_B() CONFIG_RB13_AS_DIG_OUTPUT()
#define GATE_B  _LATB13
#define CONFIG_GATE_Y() CONFIG_RB3_AS_DIG_INPUT()
#define GATE_Y  _RB3

//written in a simple style
uint8_t testGate(void) {
  GATE_A = 0;
  GATE_B = 0;
  DELAY_US(1);
  if (!GATE_Y) return 0;
  GATE_A = 0;
  GATE_B = 1;
  DELAY_US(1);
  if (!GATE_Y) return 0;
  GATE_A = 1;
  GATE_B = 0;
  DELAY_US(1);
  if (!GATE_Y) return 0;
  GATE_A = 1;
  GATE_B = 1;
  DELAY_US(1);
  if (GATE_Y) return 0;
  return 1;
}


int main(void) {

  configBasic(HELLO_MSG);
  CONFIG_GATE_A();
  CONFIG_GATE_B();
  CONFIG_GATE_Y();
  while (1) {
    doHeartbeat();     //ensure that we are alive
  }//end while
}//end main
