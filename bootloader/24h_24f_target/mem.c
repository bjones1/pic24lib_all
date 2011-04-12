#include "pic24_all.h"

typedef short          Word16;
typedef unsigned short UWord16;
typedef long           Word32;
typedef unsigned long  UWord32;

//write these in C so that can use the
//__PIC24H__, __PIC24F__ defines.

void WriteMem(UWord16 val) {
  asm("mov	W0,NVMCON");
  __builtin_write_NVM();

  asm("1:	btsc NVMCON,#15");    //	;Wait for write end
  asm("	bra 1b");

}

//_LoadAddr:	;W0=NVMADRU,W1=NVMADR - no return values
void LoadAddr(UWord16 nvmadru, UWord16 nvmadr) {
  asm("mov	W0,TBLPAG");
  asm("mov	W1,W1");
}

//_WriteLatch: ;W0=TBLPAG,W1=Wn,W2=WordHi,W3=WordLo - no return values
void WriteLatch(UWord16 addrhi,UWord16 addrlo, UWord16 wordhi, UWord16 wordlo) {
  asm("	mov	W0,TBLPAG");
  asm("	tblwtl W3,[W1]");
  asm("	tblwth W2,[W1]");
}

//_ReadLatch: ;W0=TBLPAG,W1=Wn - data in W1:W0
UWord32 ReadLatch(UWord16 addrhi, UWord16 addrlo) {

  asm("	mov	W0,TBLPAG");
  asm("	tblrdl [W1],W0");
  asm("	tblrdh [W1],W1");

}

void ResetDevice(void) {

//  asm(" goto 0xc02");
  asm(" goto 0xe00");

}

void ResetDeviceasPOR(void) {

  _POR = 1;
//  asm(" goto 0xc02");
  asm(" goto 0xe00");

}

//_Erase:
void Erase(UWord16 addrhi, UWord16 addrlo, UWord16 val ) {

  asm("push    TBLPAG");
  asm("mov	W2,NVMCON");

  asm("mov     w0,TBLPAG");           //; Init Pointer to page to be erased
  asm("tblwtl  w1,[w1]");		        //; Dummy write to select the row

  __builtin_write_NVM();


  asm("1:	btsc NVMCON,#15");    //	;Wait for write end
  asm("	bra 1b");

  asm("pop     TBLPAG");
}


