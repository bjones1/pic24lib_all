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
#include <stdio.h>

/** \file
I2C Example: Demonstrates I2C functions by reading/writing
from a Maxim DS1631 Digital Thermometer.

Change this code to write values to the Temperature High (TH), and Temperature Low (TL)
trip-point registers in order to achieve state changes on the TOUT pin.

The TOUT pin (pin 3) is configured for active low by default at power-up.
Assuming active low configuration, at power-up TOUT is high.
When the temperature exceeds TH, the TOUT pin is asserted (low).
When the temperature drops back below TL, the pin is negated (high).

Locate a wire jumper in your part kit.
On the ASEE board, connect the TOUT pin (pin 3) on header JP2 to the
uncommitted LED3 pin on the same header (pin 1). At power up, the LED should be on.

Modify the code to set trip points for TH, TL that can be activated by putting your
finger on the sensor. When the temperature exceeds TH, the LED will turn off.
When the temperature drops back below TL, the LED will turn on.

Before writing the TH, TL registers, the "Stop Conversion" must be issued (value= 0x22).
This is the same as the startConversionDS1631() function, just write a '0x22'.

To write the TH register, three bytes must be written in the I2C transaction in addition
to the I2C address:
  0xA1, MSByte temperature, LSByte temperature.

Similarly, for the TL register, the three bytes are:
  0xA2, MSByte temperature, LSByte temperature.

The following I2C library function can be used for this transaction, which
takes as arguments an array of bytes to write, and a count of the number of bytes:

void writeNI2C1(uint8_t u8_addr,uint8_t* pu8_data, uint16_t u16_cnt);

An illustrative code fragment would be:
 uint8_t au8_buf[3];

 au8_buf[0] =  0xA1;  //TH register
 au8_buf[1] =  temperature_MSB;  //MSByte
 au8_buf[2] =  temperature_LSB;  //LSByte
 writeNI2C1(DS1631ADDR, au8_buf, 3);

As a suggested implementation, write  a function named:

void setTripPoint(uint8_t u8_reg, float f_tempC);

in which the "u8_reg" parameter is the register number either for TH or TL,
and the "f_tempC" parameter is the trip-point Celsius temperature. Your function
would need to convert "f_tempC" to a 16-bit integer temperature, this can be done
by multiplying it by 256, and then assigning it to a uint16_t variable.

*/

#define DS1631ADDR 0x90   //DS1631 address with all pins tied low
#define ACCESS_CONFIG 0xAC
#define START_CONVERT 0x51
#define READ_TEMP 0xAA

void writeConfigDS1631(uint8_t u8_i) {
  write2I2C1(DS1631ADDR, ACCESS_CONFIG, u8_i);
}

void startConversionDS1631() {
  write1I2C1(DS1631ADDR, START_CONVERT);
}

int16_t readTempDS1631() {
  uint8_t u8_lo, u8_hi;
  int16_t i16_temp;
  write1I2C1(DS1631ADDR, READ_TEMP);
  read2I2C1 (DS1631ADDR, &u8_hi, &u8_lo);
  i16_temp = u8_hi;
  return ((i16_temp<<8)|u8_lo);
}

int main (void) {
  int16_t i16_temp;
  float  f_tempC,f_tempF;
  configBasic(HELLO_MSG);
  configI2C1(400);            //configure I2C for 400 KHz
  writeConfigDS1631(0x0C);    //continuous conversion, 12-bit mode
  startConversionDS1631();    //start conversions
  while (1) {
    DELAY_MS(750);
    i16_temp = readTempDS1631();
    f_tempC = i16_temp;  //convert to floating point
    f_tempC = f_tempC/256;  //divide by precision
    f_tempF = f_tempC*9/5 + 32;
    printf("Temp is: 0x%0X, %4.4f (C), %4.4f (F)\n", i16_temp, (double) f_tempC, (double) f_tempF);
  }

}