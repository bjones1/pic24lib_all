#include <stdio.h>
typedef unsigned char       uint8;   //8 bits
typedef unsigned short      uint16;  //16 bits
typedef unsigned long       uint32;  //32 bits
typedef unsigned long long  uint64;  //64 bits
typedef signed char         int8;    //8 bits
typedef signed short        int16;   //16 bits
typedef signed long         int32;   //32 bits
typedef signed long long    int64;   //64 bits


uint8 nyb2aschex (uint8 u8_c) {
  if (u8_c >= 10)
    return (u8_c + 0x37);
  else return(u8_c + 0x30);
}

void byte2aschex(
  uint8 u8_c,
  uint8 *pu8_s) {
  *pu8_s = nyb2aschex(u8_c >> 4);
  pu8_s++;
  // second hex digit
  *pu8_s = nyb2aschex(u8_c & 0x0F);
}

float f;   //single precision
double d;  //double precision
char *ptr; //generic pointer
uint8 u8_i;
uint8 u8_buf[2]; //temp space

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
