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
// **************
// bytes2aschex.c
// **************
#include <stdio.h>
typedef unsigned char       uint8_t;   //8 bits
typedef unsigned short      uint16_t;  //16 bits
typedef unsigned long       uint32_t;  //32 bits
typedef unsigned long long  uint64;  //64 bits
typedef signed char         int8_t;    //8 bits
typedef signed short        int16_t;   //16 bits
typedef signed long         int32_t;   //32 bits
typedef signed long long    int64;   //64 bits


uint8_t nyb2aschex (uint8_t u8_c) {
  if (u8_c >= 10)
    return (u8_c + 0x37);
  else return(u8_c + 0x30);
}

void byte2aschex(
  uint8_t u8_c,
  uint8_t *pu8_s) {
  *pu8_s = nyb2aschex(u8_c >> 4);
  pu8_s++;
  // second hex digit
  *pu8_s = nyb2aschex(u8_c & 0x0F);
}

float f;   //single precision
double d;  //double precision
char *ptr; //generic pointer
uint8_t u8_i;
uint8_t u8_buf[2]; //temp space

main() {

  f = 1398.5625;
  ptr = (char *) &f;
  printf("float: %6.2f bytes are: ",
         f);
  // print the four bytes
  for (u8_i=0; u8_i<4; u8_i++) {
    byte2aschex(*(ptr+3-u8_i),u8_buf);
    putchar(u8_buf[0]); // print MS digit
    putchar(u8_buf[1]); // print LS digit
  }
  printf("\n");
  d = -28.75;
  ptr = (char *) &d;
  printf("double: %6.2lf bytes are: ",
         d);
  for (u8_i=0; u8_i<8; u8_i++) {
    byte2aschex(*(ptr+7-u8_i),u8_buf);
    putchar(u8_buf[0]); // print MS digit
    putchar(u8_buf[1]); // print LS digit
  }
  printf("\n");
}
