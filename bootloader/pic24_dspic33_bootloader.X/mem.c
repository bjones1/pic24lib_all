// ********************************************
// mem.c - Read/write the PIC's program memory.
// ********************************************

#include "pic24_util.h"

typedef short          Word16;
typedef unsigned short UWord16;
typedef long           Word32;
typedef unsigned long  UWord32;

// Write these in C so that can we use the __PIC24H__, __PIC24F__ defines.
void WriteMem(UWord16 val) {
  UNUSED(val);

  asm("mov W0, NVMCON");
  __builtin_write_NVM();

  // Wait for write end.
  asm("1: btsc NVMCON, #15");
  asm("bra 1b");
}


#if (defined(__PIC24E__) || defined(__dsPIC33E__))
void WriteMem2(UWord16 addrhi, UWord16 addrlo, UWord16 val) {
  UNUSED(addrhi);
  UNUSED(addrlo);
  UNUSED(val);

  // Init Pointer to page to be erased.
  asm("mov W0, NVMADRU");
  // Init Pointer to offset to be erased.
  asm("mov W1, NVMADR");
  asm("mov W2, NVMCON");
  //__builtin_write_NVM();
  asm("disi #06");
  asm("mov #0x55, W0");
  asm("mov W0, NVMKEY");
  asm("mov #0xAA, W0");
  asm("mov W0, NVMKEY");
  asm("bset NVMCON, #15");
  asm("nop");
  asm("nop");

  // Wait for write end.
  asm("1: btsc NVMCON, #15");
  asm(" bra 1b");
}
#endif


//_LoadAddr:  ;W0=NVMADRU,W1=NVMADR - no return values
void LoadAddr(UWord16 nvmadru, UWord16 nvmadr) {
  UNUSED(nvmadru);
  UNUSED(nvmadr);

  asm("mov W0, TBLPAG");
  asm("mov W1, W1");
}

//_WriteLatch: ;W0=TBLPAG,W1=Wn,W2=WordHi,W3=WordLo - no return values
void WriteLatch(UWord16 addrhi,UWord16 addrlo, UWord16 wordhi, UWord16 wordlo) {
  UNUSED(addrhi);
  UNUSED(addrlo);
  UNUSED(wordhi);
  UNUSED(wordlo);

  asm("mov W0, TBLPAG");
  asm("tblwtl W3, [W1]");
  asm("tblwth W2, [W1]");
}


#if (defined(__PIC24E__) || defined(__dsPIC33E__))
//_LoadTwoWords: ;W0=TBLPAG,W1=Wn,W2=WordHi,W3=WordLo W4=Word2Hi,W5=Word2Lo
//W0,W1 not really used
void LoadTwoWords(UWord16 addrhi, UWord16 addrlo, UWord16 wordhi, UWord16 wordlo, UWord16 word2hi, UWord16 word2lo) {
  UNUSED(addrhi);
  UNUSED(addrlo);
  UNUSED(wordhi);
  UNUSED(wordlo);
  UNUSED(word2hi);
  UNUSED(word2lo);

  asm("mov #0xFA,W0");
  asm("mov W0, TBLPAG");
  asm("mov #0, W1");
  asm("tblwtl W3, [W1]");
  asm("tblwth W2, [W1++]");
  asm("tblwtl W5, [W1]");
  asm("tblwth W4, [W1++]");
}
#endif


//_ReadLatch: ;W0=TBLPAG,W1=Wn - data in W1:W0
UWord32 ReadLatch(UWord16 addrhi, UWord16 addrlo) {
  UNUSED(addrhi);
  UNUSED(addrlo);

  asm("mov W0, TBLPAG");
  asm("tblrdl [W1], W0");
  asm("tblrdh [W1], W1");
  // This gives a compiler warning because not explicitly returning
  // a value from the function, but since this is assembly, do not
  // know how to prevent warning.  The function is correct, since
  // W1:W0 being used to return the tblrdl,tblrdh. Could write
  // less efficient code and use a temporary UWord32.
  //
  // Attempts to suppress following warning:
  //
  // bootloader\pic24_dspic33_bootloader.X\mem.c:110:1: warning: control reaches
  // end of non-void function [-Wreturn-type]
  //
  // #pragma GCC diagnostic warning "-Wreturn-type" works.
  // However, if I later re-enable it at any point in this file with a
  // #pragma GCC diagnostic warning "-Wreturn-type", then the warning still
  // appears. So, leave the warning for now, rather than possibly hide future
  // warnings. See https://gcc.gnu.org/onlinedocs/gcc/Diagnostic-Pragmas.html
  // for more information.
}


void ResetDevice(void) {
#if (defined(__PIC24E__) || defined(__dsPIC33E__))
  asm("goto 0x1300");
#else
  asm("goto 0x0E00");
#endif
}


void ResetDeviceasPOR(void) {
  _POR = 1;
  ResetDevice();
}


#if (defined(__PIC24E__) || defined(__dsPIC33E__))
void Erase(UWord16 addrhi, UWord16 addrlo, UWord16 val) {
  UNUSED(addrhi);
  UNUSED(addrlo);
  UNUSED(val);

  asm("mov W2,NVMCON");

  // Init Pointer to page to be erased.
  asm("mov W0, NVMADRU");
  // Init Pointer to offset to be erased.
  asm("mov W1, NVMADR");

  //__builtin_write_NVM();

  asm("disi #06");
  asm("mov #0x55, W0");
  asm("mov W0, NVMKEY");
  asm("mov #0xAA, W0");
  asm("mov W0, NVMKEY");
  asm("bset NVMCON, #15");
  asm("nop");
  asm("nop");

  // Wait for write end.
  asm("1: btsc NVMCON, #15");
  asm(" bra 1b");
}


#else
//_Erase:
void Erase(UWord16 addrhi, UWord16 addrlo, UWord16 val) {
  UNUSED(addrhi);
  UNUSED(addrlo);
  UNUSED(val);

  asm("push TBLPAG");
  asm("mov W2, NVMCON");

  // Init Pointer to page to be erased.
  asm("mov W0, TBLPAG");
  // Dummy write to select the row.
  asm("tblwtl W1,[W1]");

  __builtin_write_NVM();

  //  Wait for write end.
  asm("1: btsc NVMCON, #15");
  asm(" bra 1b");

  asm("pop TBLPAG");
}
#endif
