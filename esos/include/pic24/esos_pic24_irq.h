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

/** \file
 *  \brief This file contains macros, prototypes, and definitions for
 *  Microchip PIC24 family specific interrupts on ESOS
 */

/************************************************************************
 * esos_pic24_irq.h
 ************************************************************************
 * User-supplied include file which defines the IRQ which are supported
 *
 * NOTE:  the file must be consistent with esos_pic24_irq.c which uses
 *          many of these constant to manipulate IRQ registers
 */

#ifndef     ESOS_PIC24_IRQ_H
#define ESOS_PIC24_IRQ_H

#include "esos.h"
#include "esos_irq.h"
#include "esos_pic24.h"


/**
 * Declaration of an ESOS interrupt.
 *
 * This macro is used to declare an ESOS user inerrupt. All ESOS user
 * interrupt tasks must be declared with this macro.
 *
 * \param desc Descriptor of the hardware interrupt
 *
 * \note ESOS user interrupts have no arguments passed in and cannot return values.
 * \note Hardware interrupt descriptors are found in the file <b>esos_<i>hw</i>_irq.h</b>
 * where <i>hw</i> is the name of the chip for the ESOS port has been written.
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 *
 * \hideinitializer
 */
#define ESOS_USER_INTERRUPT(desc)    __xESOS_USER_ISR(desc)
#define __xESOS_USER_ISR(attrib, ivt, ifsr, ifsb, ipcr, ipcb)      void _ISRFAST attrib (void)



/*
 * Define the ESOS user IRQ levels here
 *  ESOS-based IRQs will run at IRQ priority levels
 *  7 and 5.
 *
 * NOTE: Any user IRQ with its IRQ priority level at 0 signifies
 *  that the IRQ is not registered with ESOS.
 */
/**
 * Highest priority user interrupt level on PIC24 Family
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \hideinitializer
 */
#define ESOS_USER_IRQ_LEVEL1        6
/**
 * Second-highest priority user interrupt level on PIC24 Family
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \hideinitializer
 */
#define ESOS_USER_IRQ_LEVEL2        4
/**
 * Third-highest priority user interrupt level on PIC24 Family
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \hideinitializer
 */
#define ESOS_USER_IRQ_LEVEL3        3
/**
 * Lowest priority user interrupt level on PIC24 Family
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \hideinitializer
 */
#define ESOS_USER_IRQ_LEVEL4        2

#define __ESOS_USER_IRQ_UNREGISTERED    0
// this #define is the IPL that will disabled all user IRQs at once
#define __ESOS_DISABLE_USER_IRQS_LEVEL    ESOS_USER_IRQ_LEVEL2
// this #define is the IPL that will enabled all user IRQs at once
#define __ESOS_ENABLE_USER_IRQS_LEVEL   __ESOS_USER_IRQ_UNREGISTERED

/*
*  IRQ masks for the PIC24HJ32GP202
*/
#if defined(__PIC24HJ32GP202__)  || defined(__DOXYGEN__)
//         MNEMONIC            C30 ISR ATTRIB, IVT addr, IFS register, IFS bit, IPC register, IPC bit
/**
 * AD1 Conversion Complete Interrupt (User interrupt descriptor)
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 * \hideinitializer
 */
#define  ESOS_IRQ_PIC24_AD1 _ADC1Interrupt, 0x002E, 0, 13, 3, 4            // AD1 Conversion complete
/**
 * SP1 Event Interrupt (User interrupt descriptor)
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 * \hideinitializer
 */
#define  ESOS_IRQ_PIC24_SPI1  _SPI1Interrupt, 0x0028, 0, 10, 2, 8            // SPI1 event
/**
 * SP1 Exception Event Interrupt (User interrupt descriptor)
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 * \hideinitializer
 */
#define  ESOS_IRQ_PIC24_SPI1E _SPI1ErrInterrupt, 0x0026, 0, 9, 2, 4          // SPI1 (exception) fault event
/**
 * Timer 3 expiration Interrupt (User interrupt descriptor)
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 * \hideinitializer
 */
#define  ESOS_IRQ_PIC24_T3     _T3Interrupt, 0x0024, 0, 8, 2, 0               // Timer 3
/**
 * Timer 2 expiration Interrupt (User interrupt descriptor)
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 * \hideinitializer
 */
#define  ESOS_IRQ_PIC24_T2  _T2Interrupt, 0x0022, 0, 7, 1, 12              // Timer 2
/**
 * Output Compare Channel 2 Interrupt (User interrupt descriptor)
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 * \hideinitializer
 */
#define  ESOS_IRQ_PIC24_OC2 _OC2Interrupt, 0x0020, 0, 6, 1, 8              // Output compare channel 2
/**
 * Input Capture Channel 2 Interrupt (User interrupt descriptor)
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 * \hideinitializer
 */
#define  ESOS_IRQ_PIC24_IC2 _IC2Interrupt, 0x001E, 0, 5, 1, 4              // Input capture channel 2
/**
 * Output Compare Channel 1 Interrupt (User interrupt descriptor)
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 * \hideinitializer
 */
#define  ESOS_IRQ_PIC24_OC1 _OC1Interrupt, 0x0018, 0, 2, 0, 8              // Output compare channel 1

/**
 * Input Capture Channel 1 Interrupt (User interrupt descriptor)
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 * \hideinitializer
 */
#define  ESOS_IRQ_PIC24_IC1 _IC1Interrupt, 0x0016, 0, 1, 0, 4              // Input capture channel 1
/**
 * External IRQ 0 Interrupt (User interrupt descriptor)
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 * \hideinitializer
 */
#define  ESOS_IRQ_PIC24_INT0  _INT0Interrupt, 0x0014, 0, 0, 0, 0             // external interrupt 0
/**
 * External IRQ 2 Interrupt (User interrupt descriptor)
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 * \hideinitializer
 */
#define  ESOS_IRQ_PIC24_INT2  _INT2Interrupt, 0x004E, 1, 13, 7, 4            // external interrupt 2

/**
 * Input Capture Channel 8 Interrupt (User interrupt descriptor)
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 * \hideinitializer
 */
#define  ESOS_IRQ_PIC24_IC8 _IC8Interrupt, 0x0042, 1, 7, 5, 12             // Input capture channel 8
/**
 * Input Capture Channel 7 Interrupt (User interrupt descriptor)
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 * \hideinitializer
 */
#define  ESOS_IRQ_PIC24_IC7 _IC7Interrupt, 0x0040, 1, 6, 5, 8              // Input capture channel 7
/**
 * External IRQ 1 Interrupt (User interrupt descriptor)
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 * \hideinitializer
 */
#define  ESOS_IRQ_PIC24_INT1  _INT1Interrupt, 0x003C, 1, 4, 5, 0             // external interrupt 1
/**
 * Input Change Notification Interrupt (User interrupt descriptor)
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 * \hideinitializer
 */
#define  ESOS_IRQ_PIC24_CN  _CNInterrupt, 0x003A, 1, 3, 4, 12              // input change notification
/**
 * I2C1 Master Event Interrupt (User interrupt descriptor)
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 * \hideinitializer
 */
#define  ESOS_IRQ_PIC24_MI2C1 _MI2C1Interrupt, 0x0036, 1, 1, 4, 4            // I2C1 Master event
/**
 * I2C1 Slave Event Interrupt (User interrupt descriptor)
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 * \hideinitializer
 */
#define  ESOS_IRQ_PIC24_SI2C1 _SI2C1Interrupt, 0x0034, 1, 0, 4, 0            // I2C1 slave event

// if the user is __NOT__  using the built-in ESOS comm system but __IS__ using user IRQs, then
//    we should define the UART IRQs for their use
//  #ifndef _ESOS_PIC24_RS232_H
#if !defined(_ESOS_PIC24_RS232_H)  || defined(__DOXYGEN__)
/**
 * UART1 TX Event Interrupt (User interrupt descriptor)
 * \note Only defined if ESOS is built <em>without</em> the communications subsystem.
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 * \hideinitializer
 */
#define  ESOS_IRQ_PIC24_U1TX  _U1TXInterrupt, 0x002C, 0, 12, 3, 0            // UART1 TX event
/**
 * UART1 RX Event Interrupt (User interrupt descriptor)
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 * \note Only defined if ESOS is built <em>without</em> the communications subsystem.
 * \hideinitializer
 */
#define  ESOS_IRQ_PIC24_U1RX  _U1RXInterrupt, 0x002A, 0, 11, 2, 12           // UART1 RX event

/**
 * UART1 Error Event Interrupt (User interrupt descriptor)
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 * \note Only defined if ESOS is built <em>without</em> the communications subsystem.
 * \hideinitializer
 */
#define  ESOS_IRQ_PIC24_U1E _U1ErrInterrupt, 0x0096, 4, 1, 16, 4           // UART1 Error event

#endif      // end of UART1 constants

#endif      // __PIC24HJ32GP202__

// This covers the dsPIC33EPxxxGP50x, dsPIC33EPxxxMC20x/50x, and PIC24EPxxxGP/MC20x - rnn13 8/21/2013
#if defined(__PIC24EP32GP202__)		|| defined(__PIC24EP64GP202__)		|| \
	defined(__PIC24EP128GP202__)	|| defined(__PIC24EP256GP202__)		|| \
	defined(__PIC24EP512GP202__)	|| defined(__PIC24EP32GP203__)		|| \
	defined(__PIC24EP64GP203__)		|| defined(__PIC24EP32GP204__)		|| \
	defined(__PIC24EP64GP204__)		|| defined(__PIC24EP128GP204__)		|| \
	defined(__PIC24EP256GP204__)	|| defined(__PIC24EP512GP204__)		|| \
	defined(__PIC24EP64GP206__)		|| defined(__PIC24EP128GP206__)		|| \
	defined(__PIC24EP256GP206__)	|| defined(__PIC24EP512GP206__)		|| \
	defined(__dsPIC33EP32GP502__)	|| defined(__dsPIC33EP64GP502__)	|| \
	defined(__dsPIC33EP128GP502__)	|| defined(__dsPIC33EP256GP502__)	|| \
	defined(__dsPIC33EP512GP502__)	|| defined(__dsPIC33EP32GP503__)	|| \
	defined(__dsPIC33EP64GP503__)	|| defined(__dsPIC33EP32GP504__)	|| \
	defined(__dsPIC33EP64GP504__)	|| defined(__dsPIC33EP128GP504__)	|| \
	defined(__dsPIC33EP256GP504__)	|| defined(__dsPIC33EP512GP504__)	|| \
	defined(__dsPIC33EP64GP506__)	|| defined(__dsPIC33EP128GP506__)	|| \
	defined(__dsPIC33EP256GP506__)	|| defined(__dsPIC33EP512GP506__)	|| \
	defined(__PIC24EP32MC202__)		|| defined(__PIC24EP64MC202__)		|| \
	defined(__PIC24EP128MC202__)	|| defined(__PIC24EP256MC202__)		|| \
	defined(__PIC24EP512MC202__)	|| defined(__PIC24EP32MC203__)		|| \
	defined(__PIC24EP64MC203__)		|| defined(__PIC24EP32MC204__)		|| \
	defined(__PIC24EP64MC204__)		|| defined(__PIC24EP128MC204__)		|| \
	defined(__PIC24EP256MC204__)	|| defined(__PIC24EP512MC204__)		|| \
	defined(__PIC24EP64MC206__)		|| defined(__PIC24EP128MC206__)		|| \
	defined(__PIC24EP256MC206__)	|| defined(__PIC24EP512MC206__)		|| \
	defined(__dsPIC33EP32MC202__)	|| defined(__dsPIC33EP64MC202__)	|| \
	defined(__dsPIC33EP128MC202__)	|| defined(__dsPIC33EP256MC202__)	|| \
	defined(__dsPIC33EP512MC202__)	|| defined(__dsPIC33EP32MC203__)	|| \
	defined(__dsPIC33EP64MC203__)	|| defined(__dsPIC33EP32MC204__)	|| \
	defined(__dsPIC33EP64MC204__)	|| defined(__dsPIC33EP128MC204__)	|| \
	defined(__dsPIC33EP256MC204__)	|| defined(__dsPIC33EP512MC204__)	|| \
	defined(__dsPIC33EP64MC206__)	|| defined(__dsPIC33EP128MC206__)	|| \
	defined(__dsPIC33EP256MC206__)	|| defined(__dsPIC33EP512MC206__)	|| \
	defined(__dsPIC33EP32MC502__)	|| defined(__dsPIC33EP64MC502__)	|| \
	defined(__dsPIC33EP128MC502__)	|| defined(__dsPIC33EP256MC502__)	|| \
	defined(__dsPIC33EP512MC502__)	|| defined(__dsPIC33EP32MC503__)	|| \
	defined(__dsPIC33EP64MC503__)	|| defined(__DOXYGEN__)

		#define  ESOS_IRQ_PIC24_INT0	_INT0Interrupt,		0x0014,	0,	0,	0,	0	// External Interrupt 0
		#define  ESOS_IRQ_PIC24_IC1		_IC1Interrupt,		0x0016,	0,	1,	0,	4	// Input Capture 1
		#define  ESOS_IRQ_PIC24_OC1		_OC1Interrupt,		0x0018,	0,	2,	0,	8	// Output Comapre 1
		#define  ESOS_IRQ_PIC24_DMA0	_DMA0Interrupt,		0x001A,	0,	4,	1,	0	// DMA Channel 0
		#define  ESOS_IRQ_PIC24_IC2		_IC2Interrupt,		0x001E,	0,	5,	1,	4	// Input Capture 2
		#define  ESOS_IRQ_PIC24_OC2		_OC2Interrupt,		0x0020,	0,	6,	1,	8	// Output Compare 2
		#define  ESOS_IRQ_PIC24_T2		_T2Interrupt,		0x0022,	0,	7,	1,	12	// Timer2
		#define  ESOS_IRQ_PIC24_T3		_T3Interrupt,		0x0024,	0,	8,	2,	0	// Timer3
		#define  ESOS_IRQ_PIC24_SPI1E	_SPI1ErrInterrupt,	0x0026,	0,	9,	2,	4	// SPI1 Error
		#define  ESOS_IRQ_PIC24_SPI1	_SPI1Interrupt,		0x0028,	0,	10,	2,	8	// SPI1 Transfer Done
		#define  ESOS_IRQ_PIC24_U1RX	_U1RXInterrupt,		0x002A,	0,	11,	2,	12	// UART1 Receiver
		#define  ESOS_IRQ_PIC24_U1TX	_U1TXInterrupt,		0x002C,	0,	12,	3,	0	// UART1 Transmitter
		#define  ESOS_IRQ_PIC24_AD1		_ADC1Interrupt,		0x002E,	0,	13,	3,	4	// ADC1 Convert Done
		#define  ESOS_IRQ_PIC24_DMA1	_DMA1Interrupt,		0x0030,	0,	14,	3,	8	// DMA Channel 1
		#define  ESOS_IRQ_PIC24_SI2C1	_SI2C1Interrupt,	0x0034,	1,	0,	4,	0	// I2C1 Slave Event
		#define  ESOS_IRQ_PIC24_MI2C1	_MI2C1Interrupt,	0x0036,	1,	1,	4,	4	// I2C1 Master Event
		#define  ESOS_IRQ_PIC24_CM		_CMInterrupt,		0x0038,	1,	2,	4,	8	// Comparator Combined Event
		#define  ESOS_IRQ_PIC24_CN		_CNInterrupt,		0x003A,	1,	3,	4,	12	// Input Change Interrupt
		#define  ESOS_IRQ_PIC24_INT1	_INT1Interrupt,		0x003C,	1,	4,	5,	0	// External Interrupt 1
		#define  ESOS_IRQ_PIC24_DMA2	_DMA2Interrupt,		0x0044,	1,	8,	6,	0	// DMA Channel 2
		#define  ESOS_IRQ_PIC24_OC3		_OC3Interrupt,		0x0046,	1,	9,	6,	4	// Output Compare 3
		#define  ESOS_IRQ_PIC24_OC4		_OC4Interrupt,		0x0048,	1,	10,	6,	8	// Output Compare 4
		#define  ESOS_IRQ_PIC24_T4		_T4Interrupt,		0x004A,	1,	11,	6,	12	// Timer4
		#define  ESOS_IRQ_PIC24_T5		_T5Interrupt,		0x004C,	1,	12,	7,	0	// Timer5
		#define  ESOS_IRQ_PIC24_INT2	_INT2Interrupt,		0x004E,	1,	13,	7,	4	// External Interrupt 2
		#define  ESOS_IRQ_PIC24_U2RX	_U2RXInterrupt,		0x0050,	1,	14,	7,	8	// UART2 Receiver
		#define  ESOS_IRQ_PIC24_U2TX	_U2TXInterrupt,		0x0052,	1,	15,	7,	12	// UART2 Transmitter
		#define  ESOS_IRQ_PIC24_SPI2E	_SPI2ErrInterrupt,	0x0054,	2,	0,	8,	0	// SPI2 Error
		#define  ESOS_IRQ_PIC24_SPI2	_SPI2Interrupt,		0x0056,	2,	1,	8,	4	// SPI2 Transfer Done
		#define  ESOS_IRQ_PIC24_DMA3	_DMA3Interrupt,		0x005C,	2,	4,	9,	0	// DMA Channel 3
		#define  ESOS_IRQ_PIC24_IC3		_IC3Interrupt,		0x005E,	2,	5,	9,	4	// Input Capture 3
		#define  ESOS_IRQ_PIC24_IC4		_IC4Interrupt,		0x0060,	2,	6,	9,	8	// Input Capture 4
		#define  ESOS_IRQ_PIC24_SI2C2	_SI2C2Interrupt,	0x0076,	3,	1,	12,	4	// I2C2 Slave Event
		#define  ESOS_IRQ_PIC24_MI2C2	_MI2C2Interrupt,	0x0078,	3,	2,	12,	8	// I2C2 Master Event
		#define  ESOS_IRQ_PIC24_U1E		_U1ErrInterrupt,	0x0096,	4,	1,	16,	4	// UART1 Error Interrupt
		#define  ESOS_IRQ_PIC24_U2E		_U2ErrInterrupt,	0x0098,	4,	2,	16,	8	// UART2 Error Interrupt
		#define  ESOS_IRQ_PIC24_CRC		_CRCInterrupt,		0x009A,	4,	3,	16,	12	// CRC Generator Interrupt
		#define  ESOS_IRQ_PIC24_CTMU	_CTMUInterrupt,		0x00AE,	4,	13,	19,	4	// CTMU Interrupt
		#define  ESOS_IRQ_PIC24_ICD		_ICDInterrupt,		0x0142,	8,	14,	35,	8	// ICD Application
		#define  ESOS_IRQ_PIC24_JTAG	_JTAGInterrupt,		0x0130,	8,	15,	35,	12	// JTAG Programming
		#define  ESOS_IRQ_PIC24_PTGSTEP	_PTGSTEPInterrupt,	0x0136,	9,	1,	36,	4	// PTG Step
		#define  ESOS_IRQ_PIC24_PTGWDT	_PTGWDTInterrupt,	0x0138,	9,	2,	36,	8	// PTG Watchdog Time-out
		#define  ESOS_IRQ_PIC24_PTG0	_PTG0Interrupt,		0x013A,	9,	3,	36,	12	// PTG Interupt 0
		#define  ESOS_IRQ_PIC24_PTG1	_PTG1Interrupt,		0x013C,	9,	4,	37,	0	// PTG Interrupt 1
		#define  ESOS_IRQ_PIC24_PTG2	_PTG2Interrupt,		0x013E,	9,	5,	37,	4	// PTG Interrupt 2
		#define  ESOS_IRQ_PIC24_PTG3	_PTG3Interrupt,		0x0140,	9,	6,	37,	8	// PTG Interrupt 3


#endif

// This covers the dsPIC33EPxxxGP50x, dsPIC33EPxxxMC20x/50x, and PIC24EPxxxGP/MC20x with CAN support - rnn13 8/21/2013
#if defined(__dsPIC33EP32GP502__)	|| defined(__dsPIC33EP64GP502__)	|| \
	defined(__dsPIC33EP128GP502__)	|| defined(__dsPIC33EP256GP502__)	|| \
	defined(__dsPIC33EP512GP502__)	|| defined(__dsPIC33EP32GP503__)	|| \
	defined(__dsPIC33EP64GP503__)	|| defined(__dsPIC33EP32GP504__)	|| \
	defined(__dsPIC33EP64GP504__)	|| defined(__dsPIC33EP128GP504__)	|| \
	defined(__dsPIC33EP256GP504__)	|| defined(__dsPIC33EP512GP504__)	|| \
	defined(__dsPIC33EP64GP506__)	|| defined(__dsPIC33EP128GP506__)	|| \
	defined(__dsPIC33EP256GP506__)	|| defined(__dsPIC33EP512GP506__)	|| \
	defined(__dsPIC33EP32MC502__)	|| defined(__dsPIC33EP64MC502__)	|| \
	defined(__dsPIC33EP128MC502__)	|| defined(__dsPIC33EP256MC502__)	|| \
	defined(__dsPIC33EP512MC502__)	|| defined(__dsPIC33EP32MC503__)	|| \
	defined(__dsPIC33EP64MC503__)	|| defined(_DOXYGEN_)

		#define  ESOS_IRQ_PIC24_C1RX	_C1RXInterrupt,		0x0058,	2,	2,	8,	8	// CAN1 RX Data Ready				(This input source is available on dsPIC33EPxxxGP50x and dsPIC33EPxxxMC50x devices only)
		#define  ESOS_IRQ_PIC24_C1		_C1Interrupt,		0x005A,	2,	3,	8,	12	// CAN1 Event						(This input source is available on dsPIC33EPxxxGP50x and dsPIC33EPxxxMC50x devices only)
		#define  ESOS_IRQ_PIC24_C1TX	_C1TXInterrupt,		0x00A0,	4,	6,	17,	8	// CAN1 TX Data Request				(This input source is available on dsPIC33EPxxxGP50x and dsPIC33EPxxxMC50x devices only)

#endif

// This covers the dsPIC33EPxxxGP50x, dsPIC33EPxxxMC20x/50x, and PIC24EPxxxGP/MC20x with PWM and Quadrature Encoder support - rnn13 8/21/2013
#if defined(__dsPIC33EP32MC202__)	|| defined(__dsPIC33EP64MC202__)		|| \
	defined(__dsPIC33EP128MC202__)	|| defined(__dsPIC33EP256MC202__)		|| \
	defined(__dsPIC33EP512MC202__)	|| defined(__dsPIC33EP32MC203__)		|| \
	defined(__dsPIC33EP64MC203__)	|| defined(__dsPIC33EP32MC204__)		|| \
	defined(__dsPIC33EP64MC204__)	|| defined(__dsPIC33EP128MC204__)		|| \
	defined(__dsPIC33EP256MC204__)	|| defined(__dsPIC33EP512MC204__)		|| \
	defined(__dsPIC33EP64MC206__)	|| defined(__dsPIC33EP128MC206__)		|| \
	defined(__dsPIC33EP256MC206__)	|| defined(__dsPIC33EP512MC206__)		|| \
	defined(__PIC24EP32MC202__)		|| defined(__PIC24EP64MC202__)			|| \
	defined(__PIC24EP128MC202__)	|| defined(__PIC24EP256MC202__)			|| \
	defined(__PIC24EP512MC202__)	|| defined(__PIC24EP32MC203__)			|| \
	defined(__PIC24EP64MC203__)		|| defined(__PIC24EP32MC204__)			|| \
	defined(__PIC24EP64MC204__)		|| defined(__PIC24EP128MC204__)			|| \
	defined(__PIC24EP256MC204__)	|| defined(__PIC24EP512MC204__)			|| \
	defined(__PIC24EP64MC206__)		|| defined(__PIC24EP128MC206__)			|| \
	defined(__PIC24EP256MC206__)	|| defined(__PIC24EP512MC206__)			|| \
	defined(_DOXYGEN_)

		#define  ESOS_IRQ_PIC24_PSEM	_PSEMInterrupt,		0x0086,	3,	9,	14,	4	// PWM Special Event Match			(This interrupt source is available on dsPIC33EPxxxMC20x/50x and PIC24EPxxxMC20x devices only)
		#define  ESOS_IRQ_PIC24_QEI1	_QEI1Interrupt,		0x0088,	3,	10,	14,	8	// QEI1 Position Counter Compare	(This interrupt source is available on dsPIC33EPxxxMC20x/50x and PIC24EPxxxMC20x devices only)
		#define  ESOS_IRQ_PIC24_PWM1	_PWM1Interrupt,		0x00D0,	5,	14,	23,	8	// PWM Generator 1					(This interrupt source is available on dsPIC33EPxxxMC20x/50x and PIC24EPxxxMC20x devices only)
		#define  ESOS_IRQ_PIC24_PWM2	_PWM2Interrupt,		0x00D2,	5,	15,	23,	12	// PWM Generator 2					(This interrupt source is available on dsPIC33EPxxxMC20x/50x and PIC24EPxxxMC20x devices only)
		#define  ESOS_IRQ_PIC24_PWM3	_PWM3Interrupt,		0x00D4,	6,	0,	24,	0	// PWM Generator 3					(This interrupt source is available on dsPIC33EPxxxMC20x/50x and PIC24EPxxxMC20x devices only)

#endif

/*
 * MACROs COMMON TO ALL PIC24 PROCESSORS
 */

#define __GET_IRQ_ATTRIB(Q)     __xGET_IRQ_ATTRIB(Q)
#define __GET_IVTQ(Q)           __xGET_IVT(Q)
#define __GET_IFS_NUM(Q)        __xGET_IFS_NUM(Q)
#define __GET_IFS_BITNUM(Q)     __xGET_IFS_BITNUM(Q)
#define __GET_IEC_NUM(Q)        __xGET_IFS_NUM(Q)
#define __GET_IEC_BITNUM(Q)     __xGET_IFS_BITNUM(Q)
#define __GET_IPC_NUM(Q)        __xGET_IPC_NUM(Q)
#define __GET_IPC_BITNUM(Q)     __xGET_IPC_BITNUM(Q)

#define __xGET_IRQ_ATTRIB(attrib, ivt, ifsr, ifsb, ipcr, ipcb)            attrib
#define __xGET_IVT(attrib, ivt, ifsr, ifsb, ipcr, ipcb)               ivt
#define __xGET_IFS_NUM(attrib, ivt, ifsr, ifsb, ipcr, ipcb)           ifsr
#define __xGET_IFS_BITNUM(attrib, ivt, ifsr, ifsb, ipcr, ipcb)        ifsb
#define __xGET_IEC_NUM(attrib, ivt, ifsr, ifsb, ipcr, ipcb)           ifsr
#define __xGET_IEC_BITNUM(attrib, ivt, ifsr, ifsb, ipcr, ipcb)        ifsb
#define __xGET_IPC_NUM(attrib, ivt, ifsr, ifsb, ipcr, ipcb)           ipcr
#define __xGET_IPC_BITNUM(attrib, ivt, ifsr, ifsb, ipcr, ipcb)        ipcb


// this macro gets the IRQ's IPL number from its corresponding IPC register
#define __GET_IPL_FROM_IPCX(Q)      ((*(&IPC0+(__xGET_IPC_NUM(Q))) >> __xGET_IPC_BITNUM(Q))&0x7)

// this macro tests the IRQ's IPL number from its corresponding IPC register
// against a value
#define __IS_IPL_FROM_IPCX(Q, val)    ((__GET_IPL_FROM_IPCX(Q))==(val))

// this macro sets the IRQ's IPL number in its corresponding IPC register
#define __PUT_IPL_INTO_IPCX(ipc,ipcb,ipl)                             \
    do {                                                            \
    BIT_CLEAR_MASK( *(&IPC0+(ipc)), 0x07<<ipcb) + (ipl<<ipcb);  \
    *(&IPC0+ipc) += (ipl<<ipcb); \
      }while(0)

/**
* Unregisters the user interrupt denoted by the interrupt descriptor
* \param desc   Descriptor of the hardware interrupt
* \note Hardware interrupt descriptors are found in the file <b>esos_<i>hw</i>_irq.h</b>
* where <i>hw</i> is the name of the chip for the ESOS port has been written.
* \hideinitializer
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 */
#define  ESOS_UNREGISTER_PIC24_USER_INTERRUPT(desc)    __xUNREGISTER_PIC24_USER_INTERRUPT(desc)
#define  __xUNREGISTER_PIC24_USER_INTERRUPT(attrib, ivt, ifsr, ifsb, ipcr, ipcb)   \
  do{                                               \
  __xDISABLE_PIC24_USER_INTERRUPT(attrib, ivt, ifsr, ifsb, ipcr, ipcb);               \
  __PUT_IPL_INTO_IPCX(ipcr,ipcb, __ESOS_USER_IRQ_UNREGISTERED);      \
  }while(0)


/**
* Registers the user interrupt denoted by the interrupt descriptor
* \param desc   Descriptor of the hardware interrupt
* \param ipl     Interrupt Priority Level (IPL) for the interrupt being registered
* \param p2f        Pointer to function to serve as the ISR. Function must have <em>void</em>
* arguments and return <em>void</em>
* \note Hardware interrupt descriptors are found in the file <b>esos_<i>hw</i>_irq.h</b>
* where <i>hw</i> is the name of the chip for the ESOS port has been written.
* \hideinitializer
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 */
#define ESOS_REGISTER_PIC24_USER_INTERRUPT(desc, ipl, p2f)    __xREGISTER_PIC24_USER_INTERRUPT(desc, ipl, p2f)
#define __xREGISTER_PIC24_USER_INTERRUPT(attrib, ivt, ifsr, ifsb, ipcr, ipcb, ipl, p2f)    \
   do {                                               \
      __xDISABLE_PIC24_USER_INTERRUPT(attrib, ivt, ifsr, ifsb, ipcr, ipcb);   \
      __PUT_IPL_INTO_IPCX(ipcr, ipcb, ipl);   \
   }while(0)

/**
* Disables all registered user interrupts.
* \note This function does <em>NOT</em> disable all interrupts.  Interrupts used by
* ESOS will continue to function.
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
* \hideinitializer
*/
#define  ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS()     SET_CPU_IPL(__ESOS_DISABLE_USER_IRQS_LEVEL)

/**
* Enables all registered user interrupts.
* \note Does not affect interrupts used by ESOS
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
* \hideinitializer
*/
#define  ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS()      SET_CPU_IPL(__ESOS_ENABLE_USER_IRQS_LEVEL)

/**
* Queries the enabled state of user interrupt denoted by the interrupt descriptor
* \param desc   Descriptor of the hardware interrupt
* \retval TRUE    If the user interrupt is currently enabled
* \retval FALSE    If the user interrupt is currently disabled
* \note Hardware interrupt descriptors are found in the file <b>esos_<i>hw</i>_irq.h</b>
* where <i>hw</i> is the name of the chip for the ESOS port has been written.
* \hideinitializer
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 */
#define  ESOS_IS_PIC24_USER_INTERRUPT_ENABLED(desc)     __xIS_PIC24_USER_INTERRUPT_ENABLED(desc)
#define  __xIS_PIC24_USER_INTERRUPT_ENABLED(attrib, ivt, ifsr, ifsb, ipcr, ipcb)    IS_BIT_SET(*(&IEC0+ifsr),ifsb)

/**
* Queries the "flag" state of user interrupt denoted by the interrupt descriptor
* \param desc   Descriptor of the hardware interrupt
* \retval TRUE    If the user interrupt is needs to be serviced
* \retval FALSE    Otherwise
* \note Hardware interrupt descriptors are found in the file <b>esos_<i>hw</i>_irq.h</b>
* where <i>hw</i> is the name of the chip for the ESOS port has been written.
* \hideinitializer
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
*/
#define  ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING(desc)    __xDOES_PIC24_USER_INTERRUPT_NEED_SERVICING(desc)
#define  __xDOES_PIC24_USER_INTERRUPT_NEED_SERVICING(attrib, ivt, ifsr, ifsb, ipcr, ipcb)     IS_BIT_SET(*(&IFS0+ifsr), ifsb)

/**
* Tells ESOS to mark the user interrupt denoted by the interrupt descriptor as being serviced
* \param desc   Descriptor of the hardware interrupt
* \note Hardware interrupt descriptors are found in the file <b>esos_<i>hw</i>_irq.h</b>
* where <i>hw</i> is the name of the chip for the ESOS port has been written.
* \hideinitializer
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
*/
#define  ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED(desc)   __xMARK_PIC24_USER_INTERRUPT_SERVICED(desc)
#define  __xMARK_PIC24_USER_INTERRUPT_SERVICED(attrib, ivt, ifsr, ifsb, ipcr, ipcb)            BIT_CLEAR(*(&IFS0+ifsr),ifsb)

/**
* Enables the user interrupt denoted by the interrupt descriptor
* \param desc   Descriptor of the hardware interrupt
* \note Hardware interrupt descriptors are found in the file <b>esos_<i>hw</i>_irq.h</b>
* where <i>hw</i> is the name of the chip for the ESOS port has been written.
* \hideinitializer
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_DISABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 */
#define   ESOS_ENABLE_PIC24_USER_INTERRUPT(desc)      __xENABLE_PIC24_USER_INTERRUPT(desc)
#define  __xENABLE_PIC24_USER_INTERRUPT(attrib, ivt, ifsr, ifsb, ipcr, ipcb)     BIT_SET(*(&IEC0+ifsr), ifsb)

/**
* Disables the user interrupt denoted by the interrupt descriptor
* \param desc   Descriptor of the hardware interrupt
* \note Hardware interrupt descriptors are found in the file <b>esos_<i>hw</i>_irq.h</b>
* where <i>hw</i> is the name of the chip for the ESOS port has been written.
* \hideinitializer
 * \sa ESOS_USER_INTERRUPT
 * \sa ESOS_REGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_UNREGISTER_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_PIC24_USER_INTERRUPT
 * \sa ESOS_ENABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_DISABLE_ALL_PIC24_USER_INTERRUPTS
 * \sa ESOS_IS_PIC24_USER_INTERRUPT_ENABLED
 * \sa ESOS_DOES_PIC24_USER_INTERRUPT_NEED_SERVICING
 * \sa ESOS_MARK_PIC24_USER_INTERRUPT_SERVICED
 */
#define  ESOS_DISABLE_PIC24_USER_INTERRUPT(desc)       __xDISABLE_PIC24_USER_INTERRUPT(desc)
#define  __xDISABLE_PIC24_USER_INTERRUPT(attrib, ivt, ifsr, ifsb, ipcr, ipcb)       BIT_CLEAR(*(&IEC0+ifsr), ifsb)

#endif          // ESOS_PIC24_IRQ_H


