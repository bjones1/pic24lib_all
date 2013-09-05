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

#include <libpic30.h>
#include <stdint.h>
#include "pic24_uart.h"

// The standard library wants a heartbeat, which isn't used by the bootloader.
// Provide an empty function to make it happy. This is copied from portions
// of pic24_util.c.
void doHeartbeat(void) {
}

// Copied from the pic24_util.c, the _NOFLOAT version, but with ASSERTs removed.
uint16_t compute_brg(uint32_t u32_fcy, uint16_t u16_brgh, uint32_t u32_baudrate) {
  uint32_t u32_brg;

  u32_brg = u32_fcy/u32_baudrate;
  if (u16_brgh == 0) {
    if ((u32_brg & 0x0FL) >= 8) {
      u32_brg = u32_brg/16;
    } else {
      u32_brg = u32_brg/16 - 1;
    }
  } else {
    if ((u32_brg & 0x03L) >= 2) {
      u32_brg = u32_brg/4;
    } else {
      u32_brg = u32_brg/4 - 1;
    }
  }
  return u32_brg;
}



// Text below copied and pasted from portions of pic24_uart.c.
/** Configures a UART based compiler setting of DEFAULT_UART
 *  and sets __C30_UART to the default UART.
 *  If you want to configure a different UART, then call the configUARTx function explicitly.
 *  \param u32_baudRate The baud rate to use.
 */
void configDefaultUART(uint32_t u32_baudRate) {
  __C30_UART = DEFAULT_UART;

#if DEFAULT_UART == 1
  configUART1(u32_baudRate);
#elif DEFAULT_UART == 2
  configUART2(u32_baudRate);
#elif DEFAULT_UART == 3
  configUART3(u32_baudRate);
#elif DEFAULT_UART == 4
  configUART4(u32_baudRate);
#else
# error "Invalid DEFAULT_UART."
#endif
}
