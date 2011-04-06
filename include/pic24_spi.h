/* Standard copyright does not go in this file because
* of the use of Microchip provided macros, see comments below.
*/


// Documentation for this file. If the \file tag isn't present,
// this file won't be documented.
/** \file
 *  \brief SPI module support functions.
 */

#ifndef _PIC24_SPI_H_
#define _PIC24_SPI_H_

#include "pic24_chip.h"
#include "stdint.h"
// Configure spi.h below to allow ORing of bit-fields; by default, it
// requires ANDing them.
#define USE_AND_OR
#include <spi.h>

// Workaround for annoying difference in naming
// conventions in spi.h for PIC24F vs. spi.h for
// all others.
#ifdef __PIC24F__
#define SPI_MODE16_OFF SPI_MODE8_ON
#endif

// Only include if this SPI module exists.
#if (NUM_SPI_MODS >= 1)
uint16_t ioMasterSPI1(uint16_t u16_c);
#endif


#if (NUM_SPI_MODS >= 2)
uint16_t ioMasterSPI2(uint16_t u16_c);
#endif


#endif
