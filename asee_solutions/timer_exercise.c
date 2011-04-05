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
 * Timer exercise:
 * Use a periodic timer interrupt to output a byte in asynchronous serial
 * format using bit-banging.
 * The format should be 1 start, 8 data, 1 stop bit; data is sent LSB first.
 * You pick the baud rate.
 * The timer configuration has been written except for setting the PR2 register.
 * Use RB14 as the output port.
 * Use the Logicport logic analzyer to verify serial data is being written.
 *
*/


#define SEROUT           _LATB14  //serial output
#define CONFIG_SEROUT()  CONFIG_RB14_AS_DIG_OUTPUT()


volatile uint8_t u8_bitCnt = 0;

//contains the 8-bit data to serial bit-bang
volatile uint8_t u8_serData;

//set to '1' to indicate to ISR that serial bit-banging should start, ISR should clear it.
volatile uint8_t u8_startFlag;


//Interrupt Service Routine for Timer2
void _ISRFAST _T2Interrupt (void) {
//complete this code to accomplish async serial bit-banging
  if (u8_startFlag) {
    if (u8_bitCnt == 0) {
      SEROUT = 0;  //start bit
      u8_bitCnt++;
    } else if (u8_bitCnt < 9) {
      SEROUT = u8_serData & 0x01;
      u8_serData = u8_serData >> 1;
      u8_bitCnt++;
    } else if (u8_bitCnt == 9) {
      SEROUT = 1;  //stop bit
      u8_bitCnt++;
    } else {
      u8_startFlag = 0;
      u8_bitCnt = 0;
    }
  }
  _T2IF = 0;                 //clear the timer interrupt bit
}

void BitBangSerialOut(uint8_t u8_c) {
  u8_serData = u8_c;
  u8_startFlag = 1;
  while (u8_startFlag) doHeartbeat();  //wait for serial out to finish, ISR clears flag
}


#define ISR_PERIOD  52    // in us

void  configTimer2(void) {
  //T2CON set like this for documentation purposes.
  T2CON = T2_OFF | T2_IDLE_CON | T2_GATE_OFF
          | T2_32BIT_MODE_OFF
          | T2_SOURCE_INT
          | T2_PS_1_8 ;  //results in T2CON = 0x0000
  //subtract 1 from ticks value assigned to PR2 because period is PRx + 1
  PR2 = usToU16Ticks (ISR_PERIOD, getTimerPrescale(T2CONbits)) - 1;
  TMR2  = 0;                       //clear timer2 value
  _T2IF = 0;                       //clear interrupt flag
  _T2IP = 1;                       //choose a priority
  _T2IE = 1;                       //enable the interrupt
  T2CONbits.TON = 1;               //turn on the timer
}


int main (void) {
  uint8_t u8_c;

  configBasic(HELLO_MSG);
  CONFIG_SEROUT();
  configTimer2();
  SEROUT = 1;       //default state is high
  while (1) {
    u8_c = inChar1();  //wait for a character
    u8_c++;  //echo it
    outChar1(u8_c); //echo to normal serial
    BitBangSerialOut(u8_c);//echo to alternate serial
    doHeartbeat();
  }
}
