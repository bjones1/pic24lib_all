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
// *************
// aschex2byte.c
// *************
#include <stdio.h>
typedef unsigned char       uint8_t;   //8 bits
typedef unsigned short      uint16_t;  //16 bits
typedef unsigned long       uint32_t;  //32 bits
typedef unsigned long long  uint64;  //64 bits
typedef signed char         int8_t;    //8 bits
typedef signed short        int16_t;   //16 bits
typedef signed long         int32_t;   //32 bits
typedef signed long long    int64;   //64 bits

// assumes digit is either '0' to '9',
// 'A'-'F', or 'a' to 'f'
uint8_t aschex2nyb (uint8_t u8_n) {
  u8_n = u8_n & 0xDF;  //to uppercase
  if (u8_n >= 0x3A) return (u8_n - 0x37);
  return (u8_n - 0x30);
}

uint8_t aschex2byte(uint8_t *pu8_s) {
  uint8_t u8_c;
  // convert 1st char to upper 4-bits
  u8_c = aschex2nyb(*pu8_s);
  // move to upper four bits
  u8_c = u8_c << 4;
  // convert 2nd char to lower 4-bits and combine
  pu8_s++;
  u8_c = u8_c | aschex2nyb(*pu8_s);
  return(u8_c);
}


uint8_t u8_buf[3]; // temp space
uint8_t u8_c;
uint16_t u16_i;
main() {

  u8_buf[0] = '9';
  u8_buf[1] = 'A';
  //terminate string
  //for sscanf
  u8_buf[2]= 0x00;
  u8_c = aschex2byte(u8_buf);
  //use sscanf to check
  sscanf(u8_buf,"%x",&u16_i);
  if (u16_i != u8_c)
    printf("aschex2byte failed!\n");
  else
    printf("aschex2byte passed!\n");

}
