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
// *******************************
// app_softmenu.c - soft menu demo
// *******************************
// ESOS application program to implement a simple soft menu on the LCD44780.
//


// INCLUDEs go here  (First include the main esos.h file)
//      After that, the user can include what they need
#include    "esos.h"
#include    "esos_lcd44780.h"
#include    "string.h"

#ifdef __linux

#include    "esos_pc.h"
#include    "esos_pc_stdio.h"
// INCLUDE these so that printf() and our PC hacks work
#include <stdio.h>
#include <sys/select.h>
#include <termios.h>
#include <unistd.h>

#else

#include    "esos_pic24.h"
#include    "esos_pic24_rs232.h"

#endif

// DEFINEs go here
#ifndef __linux

// These defines should be replaced by hardware-appropriate
// definitions.
#define CONFIG_LED3()   printf("Called CONFIG_LED3()\n");
uint8_t LED3 = FALSE;   // LED3 is initially "off"
#define CONFIG_SW1()    printf("called CONFIG_SW1()");
#define CONFIG_SW2()    printf("called CONFIG_SW2()");
uint8_t SW1 = FALSE;
#define SW1_PRESSED()   ( SW1 == 0 )
#define SW1_RELEASED()  ( SW1 == 1 )
uint8_t SW2 = FALSE;
#define SW2_PRESSED()   ( SW2 == 0 )
#define SW2_RELEASED()  ( SW2 == 1 )

#else
    
#define CONFIG_LED3()   printf("Called CONFIG_LED3()\n");
uint8_t LED3 = FALSE;   // LED3 is initially "off"
#define CONFIG_SW1()    printf("called CONFIG_SW1()");
#define CONFIG_SW2()    printf("called CONFIG_SW2()");

#endif

// PROTOTYPEs go here

// GLOBALs go here
//  Generally, the user-created semaphores will be defined/allocated here
typedef struct {
    char ac_line1[8];
    char ac_line2[8];
} menu_item_t;

typedef struct {
    uint8_t u8_numItems;
    uint8_t u8_choice;
    menu_item_t ast_items[];
} menu_t;

menu_t main_menu = {
    .u8_numItems = 3,
    .u8_choice = 0,
    .ast_items = {
        { "Embedded",
          "Systems" },
        { "J.W.",
          "Bruce" },
        { "Drew",
          "Taylor" },
    }
};

#ifdef __linux
/*
 * Simulate the timer ISR found on a MCU
 *   The PC doesn't have a timer ISR, so this task will periodically
 *   call the timer services callback instead.
 *   USED ONLY FOR DEVELOPMENT AND TESTING ON PC.
 *   Real MCU hardware doesn't need this task
 */
ESOS_USER_TASK( __simulated_isr ) {
  ESOS_TASK_BEGIN();
  while (TRUE) {
    // call the ESOS timer services callback just like a real H/W ISR would
    __esos_tmrSvcsExecute();
    ESOS_TASK_WAIT_TICKS( 1 );

  } // endof while(TRUE)
  ESOS_TASK_END();
} // end child_task
#endif

/************************************************************************
 * User supplied functions
 ************************************************************************
 */

/*
 * An ESOS task to mimic the heartbeat LED found
 * in the PIC24 support library code used in Chapters 8-13.
 *
 * Toggle LED1, wait 250ms, repeat forever.
 *
 * \note Since this heartbeat is performed in an ESOS task,
 * a flashing LED indicates that the ESOS scheduler is still
 * running properly.  If the LED quits flashing, the ESOS
 * scheduler is no longer rotating through the runnable task
 * list.  The most likely reason is that some task has ceased
 * "yielding" the processor, and is caught in some deadlock
 * or otherwise infinite loop.
 * \hideinitializer
 */
ESOS_USER_TASK(heartbeat_LED) {
  ESOS_TASK_BEGIN();
  while (TRUE) {
    LED3 = !LED3;

#ifdef __linux
    if (LED3) {
      printf("\a");
      fflush(stdout);
    }
#endif

    ESOS_TASK_WAIT_TICKS( 500 );
  } // endof while(TRUE)
  ESOS_TASK_END();
} // end heartbeat_LED task

/*
 * An ESOS task to update the LCD44780 structure based on the selected
 * menu choice.
 * \hideinitializer
 */
ESOS_USER_TASK ( soft_menu_task ) {
    int i;
    
    ESOS_TASK_BEGIN();
    
    while (TRUE) {
        esos_lcd44780_clearScreen();
        for (i = 0; i < strlen(main_menu.ast_items[main_menu.u8_choice].ac_line1); i++) {
            esos_lcd44780_writeChar(0,i,main_menu.ast_items[main_menu.u8_choice].ac_line1[i]);
        }
        for (i = 0; i < strlen(main_menu.ast_items[main_menu.u8_choice].ac_line2); i++) {
            esos_lcd44780_writeChar(1,i,main_menu.ast_items[main_menu.u8_choice].ac_line2[i]);
        }
        
        ESOS_TASK_YIELD();
    }
    
    ESOS_TASK_END();
}

/*
 * An ESOS task to update the menu choice based on switch activity.
 * \hideinitializer
 */
ESOS_USER_TASK ( selection_handler ) {
    ESOS_TASK_BEGIN();
    
    while ( TRUE ) {
        if (SW1_PRESSED()) {
            ESOS_TASK_WAIT_UNTIL(SW1_RELEASED());
            if (main_menu.u8_choice == 0) {
                main_menu.u8_choice = 2;
            } else {
                main_menu.u8_choice = main_menu.u8_choice - 1;
            }
        } else if (SW2_PRESSED()) {
            ESOS_TASK_WAIT_UNTIL(SW2_RELEASED());
            if (main_menu.u8_choice == 2) {
                main_menu.u8_choice = 0;
            } else {
                main_menu.u8_choice = main_menu.u8_choice + 1;
            }
        }
        
        ESOS_TASK_YIELD();
    }
    
    ESOS_TASK_END();
}

/****************************************************
 *  user_init()
 ****************************************************
 */
void user_init(void) {

  // Call the hardware-provided routines to print the
  // HELLO_MSG to the screen.  Must use this call because
  // the ESOS communications subsystems is not yet fully
  // initialized, since this call is in user_init()
  //
  // In general, users should call hardware-specific
  // function like this.

  __esos_unsafe_PutString( HELLO_MSG );

#ifdef __linux
  // register our little ESOS task to mimic MCU's TIMER T1 IRQ which kicks off
  // the ESOS S/W timers when they expire
  esos_RegisterTask( __simulated_isr );
#endif

  // configure our hardware as needed by the tasks
  CONFIG_LED3();
  CONFIG_SW1();
  CONFIG_SW2();
  esos_lcd44780_configDisplay();
  esos_lcd44780_init();

  // user_init() should register at least one user task
  esos_RegisterTask( heartbeat_LED );
  esos_RegisterTask( soft_menu_task );
  esos_RegisterTask( selection_handler );

} // end user_init()
