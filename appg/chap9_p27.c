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
Problem 9.27
*/


#define ISR_PERIOD     15                // in ms
void  configTimer3(void) {
  //ensure that Timer2,3 configured as separate timers.
  T2CONbits.T32 = 0;     // 32-bit mode off
  //T3CON set like this for documentation purposes.
  //could be replaced by T3CON = 0x0020
  T3CON = T3_OFF |T3_IDLE_CON | T3_GATE_OFF
          | T3_SOURCE_INT
          | T3_PS_1_64 ;  //results in T3CON= 0x0020
  PR3 = msToU16Ticks (ISR_PERIOD, getTimerPrescale(T3CONbits)) - 1;
  TMR3  = 0;                       //clear timer3 value
  _T3IF = 0;                       //clear interrupt flag
  _T3IP = 1;                       //choose a priority
  _T3IE = 1;                       //enable the interrupt
  T3CONbits.TON = 1;               //turn on the timer
}

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

#define SW1_RAW         _RB13             //raw switch value
#define SW1             u8_valueSW1       //switch state
#define SW1_PRESSED()   SW1==0  //switch test
#define SW1_RELEASED()  SW1==1  //switch test

typedef enum  {
  STATE_WAIT_FOR_PRESS,
  STATE_WAIT_FOR_RELEASE,
} STATE;
STATE e_mystate;

volatile u8_blinkFlag = 1;
volatile uint8 u8_valueSW1  = 1;    //initially high
//Interrupt Service Routine for Timer3
void _ISRFAST _T3Interrupt (void) {
  u8_valueSW1 = SW1_RAW;     //sample the switch
  _T3IF = 0;                 //clear the timer interrupt bit
  switch (e_mystate) {
    case STATE_WAIT_FOR_PRESS :
      if (SW1_PRESSED()) {
        e_mystate = STATE_WAIT_FOR_RELEASE;
        u8_blinkFlag = !u8_blinkFlag;  //toggle blink flag
      }
      break;
    case STATE_WAIT_FOR_RELEASE :
      if (SW1_RELEASED()) {
        e_mystate = STATE_WAIT_FOR_PRESS;
        u8_blinkFlag = !u8_blinkFlag;  //toggle blink flag
      }
      break;
    default:
      e_mystate = STATE_WAIT_FOR_PRESS;
  }//end switch(e_mystate)
}

int main(void) {
  configBasic(HELLO_MSG);
  CONFIG_SW1();
  CONFIG_LED1();
  configTimer3();
  e_mystate = STATE_WAIT_FOR_PRESS ;
  LED1 = 0;
  LED2 = 0; //LEDs are off.
  while (1) {
    if (u8_blinkFlag) {
      LED1 = !LED1;
      DELAY_MS(100);   //blink
    }
    doHeartbeat();     //ensure that we are alive
  }
}//end main
