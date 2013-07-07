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

#include "pic24_clockfreq.h"
#include "pic24_uart.h"
#include "pic24_ports.h"
#include "pic24_unittest.h"
#include "pic24_delay.h"


// The standard library wants a heartbeat, which isn't used by the bootloader.
// Provide an empty function to make it happy. This is copied from portions
// of pic24_util.c.
void doHeartbeat(void) {
}


// Text below copied and pasted from specific portions of pic24_uart.c.
// Important change: comment out the default case in the function below; it
// causes the bootloader to take too much space to fit before 0x0C00.

/** Configures a UART based compiler setting of DEFAULT_UART
 *  and sets __C30_UART to the default UART.
 *  If you want to configure a different UART, then call the configUARTx function explicitly.
 *  \param u32_baudRate The baud rate to use.
 */
void configDefaultUART(uint32_t u32_baudRate) {
  switch (DEFAULT_UART) {
#if (NUM_UART_MODS >= 1)
    case 1 :
      __C30_UART = 1;   //this is the default UART
      configUART1(u32_baudRate);
      break;
#endif
#if (NUM_UART_MODS >= 2)
    case 2 :
      __C30_UART = 2;   //this is the default UART
      configUART2(u32_baudRate);
      break;
#endif
#if (NUM_UART_MODS >= 3)
    case 3 :
      __C30_UART = 3;   //this is the default UART
      configUART3(u32_baudRate);
      break;
#endif
#if (NUM_UART_MODS >= 4)
    case 4 :
      __C30_UART = 4;   //this is the default UART
      configUART4(u32_baudRate);
      break;
#endif
//    default :
//      REPORT_ERROR("Invalid UART");
  }
}



// Only include if this UART exists.
#if (NUM_UART_MODS >= 1)


/** Chose a default BRGH for UART1, used by
 *  \ref configUART1 to set up UART1.
 */
#ifndef DEFAULT_BRGH1
# define DEFAULT_BRGH1  DEFAULT_BRGH
#endif

#if (DEFAULT_BRGH1 != 0) && (DEFAULT_BRGH1 != 1)
# error "Invalid value specified for DEFAULT_BRGH1."
#endif


/** Configure the UART. Settings chosen:
 *  - TX is on RP11
 *  - RX is on RP10
 *  - Format is 8 data bits, no parity, 1 stop bit
 *  - CTS, RTS, and BCLK not used
 *
 *  \param u32_baudRate The baud rate to use.
 */
void configUART1(uint32_t u32_baudRate) {
#ifdef _NOFLOAT
  uint32_t u32_brg;
#else
  float f_brg;
#endif

  /*************************  UART config ********************/
  // See comments in the #warning statements below for
  // instructions on how to modify this configuration.
  // More information on each of these board is given
  // in the HARDWARE_PLATFORM section of pic24_libconfig.h.
#if (HARDWARE_PLATFORM == EXPLORER16_100P)
  // There's nothing to do, since pins on these boards are
  // mapped to fixed ports.
#elif (1 == 1)
  // The following pin mappings will apply only to UART 1.
  // Change them as necessary for your device.
# if (HARDWARE_PLATFORM == DANGEROUS_WEB)
  CONFIG_RB14_AS_DIG_INPUT();           // RX pin must be digital input
  CONFIG_U1RX_TO_RP(RB14_RP);           // U1RX <- RB14
  CONFIG_RB15_AS_DIG_OUTPUT();          // TX pin must be digital output
  CONFIG_U1TX_TO_RP(RB15_RP);           // U1TX -> RB15
# elif (HARDWARE_PLATFORM == STARTER_BOARD_28P)
  CONFIG_RB9_AS_DIG_INPUT();            // RX pin must be digital input
  CONFIG_U1RX_TO_RP(RB9_RP);            // U1RX <- RB9
  CONFIG_RB8_AS_DIG_OUTPUT();           // TX pin must be digital output
  CONFIG_U1TX_TO_RP(RB8_RP);            // U1TX -> RB8
# elif (HARDWARE_PLATFORM == DEFAULT_DESIGN)
  CONFIG_RB10_AS_DIG_INPUT();           // RX pin must be digital input
  CONFIG_U1RX_TO_RP(RB10_RP);           // U1RX <- RB10
  CONFIG_RB11_AS_DIG_OUTPUT();          // TX pin must be digital output
  CONFIG_U1TX_TO_RP(RB11_RP);           // U1TX -> RB11
# else
#   error "Unknown hardware platform."
# endif
#else
# warning "UART1 pin mappings not defined. See comments below for more info."
  // If your device has more than one UART, ****** CHANGE THE MAPPING ******
  // since multiple UARTs can not share the same pins. In particular:
  // 1. Change the statement #if (1 == 1) to #if 1
  // 2. Change the pin numbers above
  //    to something valid for your device.
  //    If your device does not have remappable I/O,
  //    (typical for >44 pin packages), skip this step --
  //    the UART I/O pins are already assigned to something
  //    valid.
#endif

  // First, disable the UART, clearing all errors, terminating
  // any in-progress transmissions/receptions, etc.
  // In particular, this clears UTXEN.
  U1MODE = (0u << 15); // UARTEN = 0 to disable.

  /* Configure UART baud rate, based on \ref FCY.
   *  NOTE: Be careful about using BRGH=1 - this uses only four clock
   *  periods to sample each bit and can be very intolerant of
   *  baud rate % error - you may see framing errors. BRGH is selected
   *  via the DEFAULT_BRGH1 define above.
   */
#ifdef _NOFLOAT
  u32_brg = FCY/u32_baudRate;
# if (DEFAULT_BRGH1 == 0)
  if ((u32_brg & 0x0FL) >= 8) u32_brg = u32_brg/16;
  else u32_brg = u32_brg/16 - 1;
# else
  if ((brg & 0x03L) >= 2) u32_brg = u32_brg/4;
  else u32_brg = u32_brg/4 - 1;
# endif
  ASSERT(u32_brg < 65536);
  U1BRG = u32_brg;
#else
# if (DEFAULT_BRGH1 == 0)
  f_brg = (((float) FCY)/((float) u32_baudRate)/16.0) - 1.0;
# else
  f_brg = (((float) FCY)/((float) u32_baudRate)/4.0) - 1.0;
# endif
  ASSERT(f_brg < 65535.5);
  U1BRG = roundFloatToUint16(f_brg);
#endif

  // Set up the UART mode register
  U1MODE =
    (1u   << 15) |      // UARTEN = 1 (enable the UART)
    (0u   << 13) |      // USIDL = 0  (continue operation in idle mode)
    (0u   << 12) |      // IREN = 0   (IrDA encoder and decoder disabled)
    (0u   << 11) |      // RTSMD = 0  (UxRTS# in flow control mode. Given
    //                  //  the UEN setting below, this doesn't matter.)
    (0b00 <<  8) |      // UEN = 00   (UxTX and UxRx pins are enabled and used;
    //                  //  used; UxCTS, UxRTS, and BCLKx pins are
    //                  //  controlled by port latches)
    (0u   <<  7) |      // WAKE = 0   (Wake-up on start bit detect during
    //                  //  sleep mode disabled)
    (0u   <<  6) |      // LPBACK = 0 (UARTx loopback mode is disabled)
    (0u   <<  5) |      // ABAUD = 0  (Auto-baud disabled)
    (0u   <<  4) |      // URXINV = 0 (Receve polarity inversion bit:
    //                  //  UxRX idle state is 1)
    (DEFAULT_BRGH1 << 3) | // BRGH (High/low baud rate select bit:
    //                  //  1 = high speed, 0 = low speed)
    (0b00 <<  1) |      // PDSEL = 00 (8-bit data, no parity)
    (0u   <<  0);       // STSEL = 0  (1 stop bit)

  // Set up the UART status and control register
  U1STA =
    (0u   << 15) |      // UTXISEL1 = 0  (See bit 13 below for explanation)
    (0u   << 14) |      // UTXINV = 0    (UxTX idle state is 1 (though docs
    //                  //  say 0))
    (0u   << 13) |      // UTXISEL0 = 0  (With bit 15 above, UTXISEL = 00:
    //                  //  Interrupt generated when any character
    //                  //  is transferred to the Transmit Shift Register).
    (0u   << 11) |      // UTXBRK = 0    (Sync break transmission disabled)
    (1u   << 10) |      // UTXEN = 0     (UARTx transmitter enabled. NOTE: per
    //                  //  the data sheet, this must be set *AFTER* UARTEN
    //                  //  is set to 1 (see UxMODE assignment above).
    (0b00 <<  6) |      // URXISEL = 00  (Interrupt flag bit is set when a
    //                  //  character is received)
    (0u   <<  5) |      // ADDEN = 0     (Address detect mode disabled)
    (0u   <<  1);       // OERR = 0      (Clear any overrun errors)

  // Delay 1 ms (at least one bit time) before beginning transmission,
  // since the UxTX pin is initially configured as an input on device
  // reset. It needs to be high for at least one bit time before
  // a character is sent in order for the start bit to be recognized.
  // See 24H FRM Sec. 17.5 for more details.
  ASSERT(u32_baudRate >= 1000L);
  // Note: If the baud rate is less than 1000, this delay
  // isn't long encough. The alternative is to use floating-point
  // math to compute the correct delay, which seems worse than the
  // problem.
  DELAY_MS(1);

  // Clear any errors
  U1STAbits.OERR = 0;
  while (U1STAbits.PERR || U1STAbits.FERR) {
    U1RXREG; //clear errors by reading RXREG
  }

  // Set up interrupts if requested
#ifdef UART1_RX_INTERRUPT
  _U1RXIF = 0;            //clear the flag
  _U1RXIP = UART1_RX_INTERRUPT_PRIORITY; //choose a priority
  _U1RXIE = 1;            //enable the interrupt
#endif
#ifdef UART1_TX_INTERRUPT
  //do not clear the U1TXIF flag!
  _U1TXIP = UART1_TX_INTERRUPT_PRIORITY; //choose a priority
  //do not enable the interrupt until we try to write to the UART
#endif

}

#endif







// Only include if this UART exists.
#if (NUM_UART_MODS >= 2)

/** Chose a default BRGH for UART2, used by
 *  \ref configUART2 to set up UART2.
 */
#ifndef DEFAULT_BRGH2
# define DEFAULT_BRGH2  DEFAULT_BRGH
#endif

#if (DEFAULT_BRGH2 != 0) && (DEFAULT_BRGH2 != 1)
# error "Invalid value specified for DEFAULT_BRGH2."
#endif


/** Configure the UART. Settings chosen:
 *  - TX is on RP11
 *  - RX is on RP10
 *  - Format is 8 data bits, no parity, 1 stop bit
 *  - CTS, RTS, and BCLK not used
 *
 *  \param u32_baudRate The baud rate to use.
 */
void configUART2(uint32_t u32_baudRate) {
#ifdef _NOFLOAT
  uint32_t u32_brg;
#else
  float f_brg;
#endif

  /*************************  UART config ********************/
  // See comments in the #warning statements below for
  // instructions on how to modify this configuration.
  // More information on each of these board is given
  // in the HARDWARE_PLATFORM section of pic24_libconfig.h.
#if (HARDWARE_PLATFORM == EXPLORER16_100P)
  // There's nothing to do, since pins on these boards are
  // mapped to fixed ports.
#elif (2 == 1)
  // The following pin mappings will apply only to UART 1.
  // Change them as necessary for your device.
# if (HARDWARE_PLATFORM == DANGEROUS_WEB)
  CONFIG_RB14_AS_DIG_INPUT();           // RX pin must be digital input
  CONFIG_U1RX_TO_RP(RB14_RP);           // U1RX <- RB14
  CONFIG_RB15_AS_DIG_OUTPUT();          // TX pin must be digital output
  CONFIG_U1TX_TO_RP(RB15_RP);           // U1TX -> RB15
# elif (HARDWARE_PLATFORM == STARTER_BOARD_28P)
  CONFIG_RB9_AS_DIG_INPUT();            // RX pin must be digital input
  CONFIG_U1RX_TO_RP(RB9_RP);            // U1RX <- RB9
  CONFIG_RB8_AS_DIG_OUTPUT();           // TX pin must be digital output
  CONFIG_U1TX_TO_RP(RB8_RP);            // U1TX -> RB8
# elif (HARDWARE_PLATFORM == DEFAULT_DESIGN)
  CONFIG_RB10_AS_DIG_INPUT();           // RX pin must be digital input
  CONFIG_U1RX_TO_RP(RB10_RP);           // U1RX <- RB10
  CONFIG_RB11_AS_DIG_OUTPUT();          // TX pin must be digital output
  CONFIG_U1TX_TO_RP(RB11_RP);           // U1TX -> RB11
# else
#   error "Unknown hardware platform."
# endif
#else
# warning "UART2 pin mappings not defined. See comments below for more info."
  // If your device has more than one UART, ****** CHANGE THE MAPPING ******
  // since multiple UARTs can not share the same pins. In particular:
  // 1. Change the statement #if (2 == 1) to #if 1
  // 2. Change the pin numbers above
  //    to something valid for your device.
  //    If your device does not have remappable I/O,
  //    (typical for >44 pin packages), skip this step --
  //    the UART I/O pins are already assigned to something
  //    valid.
#endif

  // First, disable the UART, clearing all errors, terminating
  // any in-progress transmissions/receptions, etc.
  // In particular, this clears UTXEN.
  U2MODE = (0u << 15); // UARTEN = 0 to disable.

  /* Configure UART baud rate, based on \ref FCY.
   *  NOTE: Be careful about using BRGH=1 - this uses only four clock
   *  periods to sample each bit and can be very intolerant of
   *  baud rate % error - you may see framing errors. BRGH is selected
   *  via the DEFAULT_BRGH1 define above.
   */
#ifdef _NOFLOAT
  u32_brg = FCY/u32_baudRate;
# if (DEFAULT_BRGH2 == 0)
  if ((u32_brg & 0x0FL) >= 8) u32_brg = u32_brg/16;
  else u32_brg = u32_brg/16 - 1;
# else
  if ((brg & 0x03L) >= 2) u32_brg = u32_brg/4;
  else u32_brg = u32_brg/4 - 1;
# endif
  ASSERT(u32_brg < 65536);
  U2BRG = u32_brg;
#else
# if (DEFAULT_BRGH2 == 0)
  f_brg = (((float) FCY)/((float) u32_baudRate)/16.0) - 1.0;
# else
  f_brg = (((float) FCY)/((float) u32_baudRate)/4.0) - 1.0;
# endif
  ASSERT(f_brg < 65535.5);
  U2BRG = roundFloatToUint16(f_brg);
#endif

  // Set up the UART mode register
  U2MODE =
    (1u   << 15) |      // UARTEN = 1 (enable the UART)
    (0u   << 13) |      // USIDL = 0  (continue operation in idle mode)
    (0u   << 12) |      // IREN = 0   (IrDA encoder and decoder disabled)
    (0u   << 11) |      // RTSMD = 0  (UxRTS# in flow control mode. Given
    //                  //  the UEN setting below, this doesn't matter.)
    (0b00 <<  8) |      // UEN = 00   (UxTX and UxRx pins are enabled and used;
    //                  //  used; UxCTS, UxRTS, and BCLKx pins are
    //                  //  controlled by port latches)
    (0u   <<  7) |      // WAKE = 0   (Wake-up on start bit detect during
    //                  //  sleep mode disabled)
    (0u   <<  6) |      // LPBACK = 0 (UARTx loopback mode is disabled)
    (0u   <<  5) |      // ABAUD = 0  (Auto-baud disabled)
    (0u   <<  4) |      // URXINV = 0 (Receve polarity inversion bit:
    //                  //  UxRX idle state is 1)
    (DEFAULT_BRGH2 << 3) | // BRGH (High/low baud rate select bit:
    //                  //  1 = high speed, 0 = low speed)
    (0b00 <<  1) |      // PDSEL = 00 (8-bit data, no parity)
    (0u   <<  0);       // STSEL = 0  (1 stop bit)

  // Set up the UART status and control register
  U2STA =
    (0u   << 15) |      // UTXISEL1 = 0  (See bit 13 below for explanation)
    (0u   << 14) |      // UTXINV = 0    (UxTX idle state is 1 (though docs
    //                  //  say 0))
    (0u   << 13) |      // UTXISEL0 = 0  (With bit 15 above, UTXISEL = 00:
    //                  //  Interrupt generated when any character
    //                  //  is transferred to the Transmit Shift Register).
    (0u   << 11) |      // UTXBRK = 0    (Sync break transmission disabled)
    (1u   << 10) |      // UTXEN = 0     (UARTx transmitter enabled. NOTE: per
    //                  //  the data sheet, this must be set *AFTER* UARTEN
    //                  //  is set to 1 (see UxMODE assignment above).
    (0b00 <<  6) |      // URXISEL = 00  (Interrupt flag bit is set when a
    //                  //  character is received)
    (0u   <<  5) |      // ADDEN = 0     (Address detect mode disabled)
    (0u   <<  1);       // OERR = 0      (Clear any overrun errors)

  // Delay 1 ms (at least one bit time) before beginning transmission,
  // since the UxTX pin is initially configured as an input on device
  // reset. It needs to be high for at least one bit time before
  // a character is sent in order for the start bit to be recognized.
  // See 24H FRM Sec. 17.5 for more details.
  ASSERT(u32_baudRate >= 1000L);
  // Note: If the baud rate is less than 1000, this delay
  // isn't long encough. The alternative is to use floating-point
  // math to compute the correct delay, which seems worse than the
  // problem.
  DELAY_MS(1);

  // Clear any errors
  U2STAbits.OERR = 0;
  while (U2STAbits.PERR || U2STAbits.FERR) {
    U2RXREG; //clear errors by reading RXREG
  }

  // Set up interrupts if requested
#ifdef UART2_RX_INTERRUPT
  _U2RXIF = 0;            //clear the flag
  _U2RXIP = UART2_RX_INTERRUPT_PRIORITY; //choose a priority
  _U2RXIE = 1;            //enable the interrupt
#endif
#ifdef UART2_TX_INTERRUPT
  //do not clear the U2TXIF flag!
  _U2TXIP = UART2_TX_INTERRUPT_PRIORITY; //choose a priority
  //do not enable the interrupt until we try to write to the UART
#endif

}

#endif // #if (NUM_UARTS >= 2)









// Only include if this UART exists.
#if (NUM_UART_MODS >= 3)

/** Chose a default BRGH for UART3, used by
 *  \ref configUART3 to set up UART3.
 */
#ifndef DEFAULT_BRGH3
# define DEFAULT_BRGH3  DEFAULT_BRGH
#endif

#if (DEFAULT_BRGH3 != 0) && (DEFAULT_BRGH3 != 1)
# error "Invalid value specified for DEFAULT_BRGH3."
#endif


/** Configure the UART. Settings chosen:
 *  - TX is on RP11
 *  - RX is on RP10
 *  - Format is 8 data bits, no parity, 1 stop bit
 *  - CTS, RTS, and BCLK not used
 *
 *  \param u32_baudRate The baud rate to use.
 */
void configUART3(uint32_t u32_baudRate) {
#ifdef _NOFLOAT
  uint32_t u32_brg;
#else
  float f_brg;
#endif

  /*************************  UART config ********************/
  // See comments in the #warning statements below for
  // instructions on how to modify this configuration.
  // More information on each of these board is given
  // in the HARDWARE_PLATFORM section of pic24_libconfig.h.
#if (HARDWARE_PLATFORM == EXPLORER16_100P)
  // There's nothing to do, since pins on these boards are
  // mapped to fixed ports.
#elif (3 == 1)
  // The following pin mappings will apply only to UART 1.
  // Change them as necessary for your device.
# if (HARDWARE_PLATFORM == DANGEROUS_WEB)
  CONFIG_RB14_AS_DIG_INPUT();           // RX pin must be digital input
  CONFIG_U1RX_TO_RP(RB14_RP);           // U1RX <- RB14
  CONFIG_RB15_AS_DIG_OUTPUT();          // TX pin must be digital output
  CONFIG_U1TX_TO_RP(RB15_RP);           // U1TX -> RB15
# elif (HARDWARE_PLATFORM == STARTER_BOARD_28P)
  CONFIG_RB9_AS_DIG_INPUT();            // RX pin must be digital input
  CONFIG_U1RX_TO_RP(RB9_RP);            // U1RX <- RB9
  CONFIG_RB8_AS_DIG_OUTPUT();           // TX pin must be digital output
  CONFIG_U1TX_TO_RP(RB8_RP);            // U1TX -> RB8
# elif (HARDWARE_PLATFORM == DEFAULT_DESIGN)
  CONFIG_RB10_AS_DIG_INPUT();           // RX pin must be digital input
  CONFIG_U1RX_TO_RP(RB10_RP);           // U1RX <- RB10
  CONFIG_RB11_AS_DIG_OUTPUT();          // TX pin must be digital output
  CONFIG_U1TX_TO_RP(RB11_RP);           // U1TX -> RB11
# else
#   error "Unknown hardware platform."
# endif
#else
# warning "UART3 pin mappings not defined. See comments below for more info."
  // If your device has more than one UART, ****** CHANGE THE MAPPING ******
  // since multiple UARTs can not share the same pins. In particular:
  // 1. Change the statement #if (3 == 1) to #if 1
  // 2. Change the pin numbers above
  //    to something valid for your device.
  //    If your device does not have remappable I/O,
  //    (typical for >44 pin packages), skip this step --
  //    the UART I/O pins are already assigned to something
  //    valid.
#endif

  // First, disable the UART, clearing all errors, terminating
  // any in-progress transmissions/receptions, etc.
  // In particular, this clears UTXEN.
  U3MODE = (0u << 15); // UARTEN = 0 to disable.

  /* Configure UART baud rate, based on \ref FCY.
   *  NOTE: Be careful about using BRGH=1 - this uses only four clock
   *  periods to sample each bit and can be very intolerant of
   *  baud rate % error - you may see framing errors. BRGH is selected
   *  via the DEFAULT_BRGH1 define above.
   */
#ifdef _NOFLOAT
  u32_brg = FCY/u32_baudRate;
# if (DEFAULT_BRGH3 == 0)
  if ((u32_brg & 0x0FL) >= 8) u32_brg = u32_brg/16;
  else u32_brg = u32_brg/16 - 1;
# else
  if ((brg & 0x03L) >= 2) u32_brg = u32_brg/4;
  else u32_brg = u32_brg/4 - 1;
# endif
  ASSERT(u32_brg < 65536);
  U3BRG = u32_brg;
#else
# if (DEFAULT_BRGH3 == 0)
  f_brg = (((float) FCY)/((float) u32_baudRate)/16.0) - 1.0;
# else
  f_brg = (((float) FCY)/((float) u32_baudRate)/4.0) - 1.0;
# endif
  ASSERT(f_brg < 65535.5);
  U3BRG = roundFloatToUint16(f_brg);
#endif

  // Set up the UART mode register
  U3MODE =
    (1u   << 15) |      // UARTEN = 1 (enable the UART)
    (0u   << 13) |      // USIDL = 0  (continue operation in idle mode)
    (0u   << 12) |      // IREN = 0   (IrDA encoder and decoder disabled)
    (0u   << 11) |      // RTSMD = 0  (UxRTS# in flow control mode. Given
    //                  //  the UEN setting below, this doesn't matter.)
    (0b00 <<  8) |      // UEN = 00   (UxTX and UxRx pins are enabled and used;
    //                  //  used; UxCTS, UxRTS, and BCLKx pins are
    //                  //  controlled by port latches)
    (0u   <<  7) |      // WAKE = 0   (Wake-up on start bit detect during
    //                  //  sleep mode disabled)
    (0u   <<  6) |      // LPBACK = 0 (UARTx loopback mode is disabled)
    (0u   <<  5) |      // ABAUD = 0  (Auto-baud disabled)
    (0u   <<  4) |      // URXINV = 0 (Receve polarity inversion bit:
    //                  //  UxRX idle state is 1)
    (DEFAULT_BRGH3 << 3) | // BRGH (High/low baud rate select bit:
    //                  //  1 = high speed, 0 = low speed)
    (0b00 <<  1) |      // PDSEL = 00 (8-bit data, no parity)
    (0u   <<  0);       // STSEL = 0  (1 stop bit)

  // Set up the UART status and control register
  U3STA =
    (0u   << 15) |      // UTXISEL1 = 0  (See bit 13 below for explanation)
    (0u   << 14) |      // UTXINV = 0    (UxTX idle state is 1 (though docs
    //                  //  say 0))
    (0u   << 13) |      // UTXISEL0 = 0  (With bit 15 above, UTXISEL = 00:
    //                  //  Interrupt generated when any character
    //                  //  is transferred to the Transmit Shift Register).
    (0u   << 11) |      // UTXBRK = 0    (Sync break transmission disabled)
    (1u   << 10) |      // UTXEN = 0     (UARTx transmitter enabled. NOTE: per
    //                  //  the data sheet, this must be set *AFTER* UARTEN
    //                  //  is set to 1 (see UxMODE assignment above).
    (0b00 <<  6) |      // URXISEL = 00  (Interrupt flag bit is set when a
    //                  //  character is received)
    (0u   <<  5) |      // ADDEN = 0     (Address detect mode disabled)
    (0u   <<  1);       // OERR = 0      (Clear any overrun errors)

  // Delay 1 ms (at least one bit time) before beginning transmission,
  // since the UxTX pin is initially configured as an input on device
  // reset. It needs to be high for at least one bit time before
  // a character is sent in order for the start bit to be recognized.
  // See 24H FRM Sec. 17.5 for more details.
  ASSERT(u32_baudRate >= 1000L);
  // Note: If the baud rate is less than 1000, this delay
  // isn't long encough. The alternative is to use floating-point
  // math to compute the correct delay, which seems worse than the
  // problem.
  DELAY_MS(1);

  // Clear any errors
  U3STAbits.OERR = 0;
  while (U3STAbits.PERR || U3STAbits.FERR) {
    U3RXREG; //clear errors by reading RXREG
  }

  // Set up interrupts if requested
#ifdef UART3_RX_INTERRUPT
  _U3RXIF = 0;            //clear the flag
  _U3RXIP = UART3_RX_INTERRUPT_PRIORITY; //choose a priority
  _U3RXIE = 1;            //enable the interrupt
#endif
#ifdef UART3_TX_INTERRUPT
  //do not clear the U3TXIF flag!
  _U3TXIP = UART3_TX_INTERRUPT_PRIORITY; //choose a priority
  //do not enable the interrupt until we try to write to the UART
#endif

}

#endif // #if (NUM_UARTS >= 3)









// Only include if this UART exists.
#if (NUM_UART_MODS >= 4)
/** Chose a default BRGH for UART4, used by
 *  \ref configUART4 to set up UART4.
 */
#ifndef DEFAULT_BRGH4
# define DEFAULT_BRGH4  DEFAULT_BRGH
#endif

#if (DEFAULT_BRGH4 != 0) && (DEFAULT_BRGH4 != 1)
# error "Invalid value specified for DEFAULT_BRGH4."
#endif


/** Configure the UART. Settings chosen:
 *  - TX is on RP11
 *  - RX is on RP10
 *  - Format is 8 data bits, no parity, 1 stop bit
 *  - CTS, RTS, and BCLK not used
 *
 *  \param u32_baudRate The baud rate to use.
 */
void configUART4(uint32_t u32_baudRate) {
#ifdef _NOFLOAT
  uint32_t u32_brg;
#else
  float f_brg;
#endif

  /*************************  UART config ********************/
  // See comments in the #warning statements below for
  // instructions on how to modify this configuration.
  // More information on each of these board is given
  // in the HARDWARE_PLATFORM section of pic24_libconfig.h.
#if (HARDWARE_PLATFORM == EXPLORER16_100P)
  // There's nothing to do, since pins on these boards are
  // mapped to fixed ports.
#elif (4 == 1)
  // The following pin mappings will apply only to UART 1.
  // Change them as necessary for your device.
# if (HARDWARE_PLATFORM == DANGEROUS_WEB)
  CONFIG_RB14_AS_DIG_INPUT();           // RX pin must be digital input
  CONFIG_U1RX_TO_RP(RB14_RP);           // U1RX <- RB14
  CONFIG_RB15_AS_DIG_OUTPUT();          // TX pin must be digital output
  CONFIG_U1TX_TO_RP(RB15_RP);           // U1TX -> RB15
# elif (HARDWARE_PLATFORM == STARTER_BOARD_28P)
  CONFIG_RB9_AS_DIG_INPUT();            // RX pin must be digital input
  CONFIG_U1RX_TO_RP(RB9_RP);            // U1RX <- RB9
  CONFIG_RB8_AS_DIG_OUTPUT();           // TX pin must be digital output
  CONFIG_U1TX_TO_RP(RB8_RP);            // U1TX -> RB8
# elif (HARDWARE_PLATFORM == DEFAULT_DESIGN)
  CONFIG_RB10_AS_DIG_INPUT();           // RX pin must be digital input
  CONFIG_U1RX_TO_RP(RB10_RP);           // U1RX <- RB10
  CONFIG_RB11_AS_DIG_OUTPUT();          // TX pin must be digital output
  CONFIG_U1TX_TO_RP(RB11_RP);           // U1TX -> RB11
# else
#   error "Unknown hardware platform."
# endif
#else
# warning "UART4 pin mappings not defined. See comments below for more info."
  // If your device has more than one UART, ****** CHANGE THE MAPPING ******
  // since multiple UARTs can not share the same pins. In particular:
  // 1. Change the statement #if (4 == 1) to #if 1
  // 2. Change the pin numbers above
  //    to something valid for your device.
  //    If your device does not have remappable I/O,
  //    (typical for >44 pin packages), skip this step --
  //    the UART I/O pins are already assigned to something
  //    valid.
#endif

  // First, disable the UART, clearing all errors, terminating
  // any in-progress transmissions/receptions, etc.
  // In particular, this clears UTXEN.
  U4MODE = (0u << 15); // UARTEN = 0 to disable.

  /* Configure UART baud rate, based on \ref FCY.
   *  NOTE: Be careful about using BRGH=1 - this uses only four clock
   *  periods to sample each bit and can be very intolerant of
   *  baud rate % error - you may see framing errors. BRGH is selected
   *  via the DEFAULT_BRGH1 define above.
   */
#ifdef _NOFLOAT
  u32_brg = FCY/u32_baudRate;
# if (DEFAULT_BRGH4 == 0)
  if ((u32_brg & 0x0FL) >= 8) u32_brg = u32_brg/16;
  else u32_brg = u32_brg/16 - 1;
# else
  if ((brg & 0x03L) >= 2) u32_brg = u32_brg/4;
  else u32_brg = u32_brg/4 - 1;
# endif
  ASSERT(u32_brg < 65536);
  U4BRG = u32_brg;
#else
# if (DEFAULT_BRGH4 == 0)
  f_brg = (((float) FCY)/((float) u32_baudRate)/16.0) - 1.0;
# else
  f_brg = (((float) FCY)/((float) u32_baudRate)/4.0) - 1.0;
# endif
  ASSERT(f_brg < 65535.5);
  U4BRG = roundFloatToUint16(f_brg);
#endif

  // Set up the UART mode register
  U4MODE =
    (1u   << 15) |      // UARTEN = 1 (enable the UART)
    (0u   << 13) |      // USIDL = 0  (continue operation in idle mode)
    (0u   << 12) |      // IREN = 0   (IrDA encoder and decoder disabled)
    (0u   << 11) |      // RTSMD = 0  (UxRTS# in flow control mode. Given
    //                  //  the UEN setting below, this doesn't matter.)
    (0b00 <<  8) |      // UEN = 00   (UxTX and UxRx pins are enabled and used;
    //                  //  used; UxCTS, UxRTS, and BCLKx pins are
    //                  //  controlled by port latches)
    (0u   <<  7) |      // WAKE = 0   (Wake-up on start bit detect during
    //                  //  sleep mode disabled)
    (0u   <<  6) |      // LPBACK = 0 (UARTx loopback mode is disabled)
    (0u   <<  5) |      // ABAUD = 0  (Auto-baud disabled)
    (0u   <<  4) |      // URXINV = 0 (Receve polarity inversion bit:
    //                  //  UxRX idle state is 1)
    (DEFAULT_BRGH4 << 3) | // BRGH (High/low baud rate select bit:
    //                  //  1 = high speed, 0 = low speed)
    (0b00 <<  1) |      // PDSEL = 00 (8-bit data, no parity)
    (0u   <<  0);       // STSEL = 0  (1 stop bit)

  // Set up the UART status and control register
  U4STA =
    (0u   << 15) |      // UTXISEL1 = 0  (See bit 13 below for explanation)
    (0u   << 14) |      // UTXINV = 0    (UxTX idle state is 1 (though docs
    //                  //  say 0))
    (0u   << 13) |      // UTXISEL0 = 0  (With bit 15 above, UTXISEL = 00:
    //                  //  Interrupt generated when any character
    //                  //  is transferred to the Transmit Shift Register).
    (0u   << 11) |      // UTXBRK = 0    (Sync break transmission disabled)
    (1u   << 10) |      // UTXEN = 0     (UARTx transmitter enabled. NOTE: per
    //                  //  the data sheet, this must be set *AFTER* UARTEN
    //                  //  is set to 1 (see UxMODE assignment above).
    (0b00 <<  6) |      // URXISEL = 00  (Interrupt flag bit is set when a
    //                  //  character is received)
    (0u   <<  5) |      // ADDEN = 0     (Address detect mode disabled)
    (0u   <<  1);       // OERR = 0      (Clear any overrun errors)

  // Delay 1 ms (at least one bit time) before beginning transmission,
  // since the UxTX pin is initially configured as an input on device
  // reset. It needs to be high for at least one bit time before
  // a character is sent in order for the start bit to be recognized.
  // See 24H FRM Sec. 17.5 for more details.
  ASSERT(u32_baudRate >= 1000L);
  // Note: If the baud rate is less than 1000, this delay
  // isn't long encough. The alternative is to use floating-point
  // math to compute the correct delay, which seems worse than the
  // problem.
  DELAY_MS(1);

  // Clear any errors
  U4STAbits.OERR = 0;
  while (U4STAbits.PERR || U4STAbits.FERR) {
    U4RXREG; //clear errors by reading RXREG
  }

  // Set up interrupts if requested
#ifdef UART4_RX_INTERRUPT
  _U4RXIF = 0;            //clear the flag
  _U4RXIP = UART4_RX_INTERRUPT_PRIORITY; //choose a priority
  _U4RXIE = 1;            //enable the interrupt
#endif
#ifdef UART4_TX_INTERRUPT
  //do not clear the U4TXIF flag!
  _U4TXIP = UART4_TX_INTERRUPT_PRIORITY; //choose a priority
  //do not enable the interrupt until we try to write to the UART
#endif

}

#endif // #if (NUM_UARTS >= 4)
