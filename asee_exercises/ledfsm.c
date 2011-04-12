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
ASEE Workshop Exercise
Create a LED/SW FSM that does the following:

1. States S1_PRESS_WAIT, S1_RELEASE_WAIT:
Turn the LED off. On SW1 press and release, go to Step 2.

2. States S2_PRESS_WAIT, S2_RELEASE_WAIT:
Turn the LED on. After SW1 press and release, go to Step 3.

3. States S3_PRESS_WAIT, S3_RELEASE_WAIT:
Blink the LED. After SW1 press and release, halt blinking.
If SW2 is released go to Step 1, otherwise go to Step 4.

4. State S4_PRESS_WAIT:
Turn the LED off. On press only, go to Step 5.

5. States S5_RELEASE_WAIT1, S5_RELEASE_WAIT2, S5_PRESS_WAIT:
Blink rapidly 5 times while button held down. If SW1 released before all 5 blinks complete, go to (1).
If all 5 blinks complete, freeze off, and release remains in this state. A subsequent SW1 press repeats Step 5.


Macros for LED1 (RB14), SW1(RB13), SW2(RB12) have been defined.

Use 400 ms toggle delay for a 'slow blink', and 200 ms toggle delay for a 'fast blink'.

Edit the while(1) loop in main() and try to do through step #3.
If you have time, do steps 4& 5 also.
The states have been declared for you.


*/

/// LED1
#define CONFIG_LED1() CONFIG_RB14_AS_DIG_OUTPUT()
#define LED1  _LATB14     //led1 state

/// Switch1 configuration
inline void CONFIG_SW1()  {
  CONFIG_RB13_AS_DIG_INPUT();     //use RB13 for switch input
  ENABLE_RB13_PULLUP();           //enable the pullup
}
#define SW1              _RB13  //switch state
#define SW1_PRESSED()   SW1==0  //switch test
#define SW1_RELEASED()  SW1==1  //switch test

/// Switch2 configuration
inline void CONFIG_SW2()  {
  CONFIG_RB12_AS_DIG_INPUT();     //use RB12 for switch input
  ENABLE_RB12_PULLUP();           //enable the pullup
}

#define SW2              _RB12  //switch state
#define SW2_PRESSED()   SW2==0  //switch test
#define SW2_RELEASED()  SW2==1  //switch test

typedef enum  {
  S1_RESET = 0,
  S1_PRESS_WAIT,
  S1_RELEASE_WAIT,
  S2_PRESS_WAIT,
  S2_RELEASE_WAIT,
  S3_PRESS_WAIT,
  S3_RELEASE_WAIT,
  S4_PRESS_WAIT,
  S5_RELEASE_WAIT1,
  S5_RELEASE_WAIT2,
  S5_PRESS_WAIT
} STATE;

STATE e_LastState = S1_RESET;
//print debug message for state when it changes
void printNewState (STATE e_currentState) {
  if (e_LastState != e_currentState) {
    switch (e_currentState) {
      case S1_PRESS_WAIT:
        outString("S1_PRESS_WAIT1 - LED is off, waiting on press.\n");
        break;
      case S1_RELEASE_WAIT:
        outString("S1_RELEASE_WAIT - LED is off, waiting on release.\n");
        break;
      case S2_PRESS_WAIT:
        outString("S2_PRESS_WAIT - LED is on, waiting on press.\n");
        break;
      case S2_RELEASE_WAIT:
        outString("S2_RELEASE_WAIT - LED is on, waiting on release.\n");
        break;
      case S3_PRESS_WAIT:
        outString("S3_PRESS_WAIT - LED is blinking, waiting on press.\n");
        break;
      case S3_RELEASE_WAIT:
        outString("S3_RELEASE_WAIT - LED is blinking, waiting on release.\n");
        outString("On release, goto S4_PRESS_WAIT if SW2 is pressed, else goto S1_PRESS_WAIT1.\n");
        break;
      case S4_PRESS_WAIT:
        outString("S4_PRESS_WAIT - LED is off, waiting on press.\n");
        break;
      case S5_RELEASE_WAIT1:
        outString("S5_RELEASE_WAIT1 - LED blinks rapidly, waiting on release or 5 blinks complete.\n");
        outString("Goto S1_PRESS_WAIT1 if release before 5 blinks complete, else\n");
        outString(" will freeze on after 5 blinks, wait for release, then goto S5_RELEASE_WAIT1 again on press.\n");
        break;
      case S5_RELEASE_WAIT2:
        outString("S5_RELEASE_WAIT2 - 5 blinks complete, LED is off, waiting for release.\n");
        break;
      case S5_PRESS_WAIT:
        outString("S5_PRESS_WAIT - LED is off, waiting on press.\n");
        break;
      default:
        break;
    }
  }
  e_LastState = e_currentState;  //remember last state
}



int main (void) {
  STATE e_mystate;

  configBasic(HELLO_MSG);      // Set up heartbeat, UART, print hello message and diags
  /** GPIO config ***************************/
  CONFIG_SW1();        //configure switch
  CONFIG_SW2();        //configure switch
  CONFIG_LED1();       //config the LED
  DELAY_US(1);         //give pullups a little time
  /*****Toggle LED each time switch is pressed and released ******************************/
  e_mystate = S1_PRESS_WAIT;

  while (1) {
    printNewState(e_mystate);  //debug message when state changes
    switch (e_mystate) {
      case S1_PRESS_WAIT:    //complete this state

        break;
      case S1_RELEASE_WAIT:  //complete this state

        break;
      case S2_PRESS_WAIT:    //complete this state

        break;
      case S2_RELEASE_WAIT:  //complete this state

        break;
      case S3_PRESS_WAIT:   //complete this state

        break;
      case S3_RELEASE_WAIT:  //complete this state

        break;
      case S4_PRESS_WAIT: //complete this state

        break;
      case S5_RELEASE_WAIT1: //complete this state
        break;
      case S5_RELEASE_WAIT2: //complete this state

        break;
      case S5_PRESS_WAIT:  //complete this state

        break;
      default:
        e_mystate = S1_PRESS_WAIT;
    }//end switch(e_mystate)
    DELAY_MS(DEBOUNCE_DLY);      //Debounce
    doHeartbeat();     //ensure that we are alive
  } // end while (1)
}
