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
Problem 8.17
*/

/// DFF_D
#define CONFIG_DFF_D() CONFIG_RB14_AS_DIG_OUTPUT()
#define DFF_D  _LATB14
#define CONFIG_DFF_R() CONFIG_RB13_AS_DIG_OUTPUT()
#define DFF_R  _LATB13
#define CONFIG_DFF_S() CONFIG_RB12_AS_DIG_OUTPUT()
#define DFF_S  _LATB12
#define CONFIG_DFF_CLK() CONFIG_RB2_AS_DIG_OUTPUT()
#define DFF_CLK  _LATB2
#define CONFIG_DFF_Q() CONFIG_RB3_AS_DIG_INPUT()
#define DFF_Q  _RB3

//written in a simple style
uint8 testDFFAsync(uint8 u8_op) {
  DFF_R =1;
  DFF_S = 1;  //negate
  DELAY_US(1);
  if (u8_op) {
    //reset
    DFF_R = 0;  //assert
    DELAY_US(1);
    DFF_R =1;   //negate
    DELAY_US(1);
    if (DFF_Q) return 0;  //incorrect output
    else return 1; //correct output
  } else {
    //set
    DFF_S = 0;  //assert
    DELAY_US(1);
    DFF_S =1;   //negate
    DELAY_US(1);
    if (DFF_Q) return 1;  //correct output
    else return 0; //incorrect output
  }
}


int main(void) {

  configBasic(HELLO_MSG);
  CONFIG_DFF_D();
  CONFIG_DFF_R();
  CONFIG_DFF_S();
  CONFIG_DFF_CLK();
  CONFIG_DFF_Q();
  while (1) {
    doHeartbeat();     //ensure that we are alive
  }//end while
}//end main
