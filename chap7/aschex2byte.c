#include <stdio.h>
typedef unsigned char       uint8;   //8 bits
typedef unsigned short      uint16;  //16 bits
typedef unsigned long       uint32;  //32 bits
typedef unsigned long long  uint64;  //64 bits
typedef signed char         int8;    //8 bits
typedef signed short        int16;   //16 bits
typedef signed long         int32;   //32 bits
typedef signed long long    int64;   //64 bits

// assumes digit is either '0' to '9',
// 'A'-'F', or 'a' to 'f'
uint8 aschex2nyb (uint8 u8_n) {
  u8_n = u8_n & 0xDF;  //to uppercase
  if (u8_n >= 0x3A) return (u8_n - 0x37);
  return (u8_n - 0x30);
}

uint8 aschex2byte(uint8 *pu8_s) {
  uint8 u8_c;
  // convert 1st char to upper 4-bits
  u8_c = aschex2nyb(*pu8_s);
  // move to upper four bits
  u8_c = u8_c << 4;
  // convert 2nd char to lower 4-bits and combine
  pu8_s++;
  u8_c = u8_c | aschex2nyb(*pu8_s);
  return(u8_c);
}


uint8 u8_buf[3]; // temp space
uint8 u8_c;
uint16 u16_i;
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

