 
;
; Just check out MPLAB

		.include "p24Hxxxx.inc"

       .global __reset          ;The label for the first line of code. 

         .bss            ;unitialized data section
;;These start at location 0x0800 because 0-0x07FF reserved for SFRs
m_800:       .space 2        ;Allocating space (in bytes) to variable.
m_802:       .space 2        ;Allocating space (in bytes) to variable.
m_804:       .space 2        ;Allocating space (in bytes) to variable.
m_806:       .space 2
m_808:       .space 2
m_80A:       .space 2



;..............................................................................
;Code Section in Program Memory
;..............................................................................

         .text           ;Start of Code section
__reset:                 ; first instruction located at __reset label
        mov #__SP_init, w15       ;Initalize the Stack Pointer
        mov #__SPLIM_init,W0   
        mov W0, SPLIM             ;Initialize the stack limit register
;__SP_init set by linker to be after allocated data      


    call meminit
	mov [--W1],W0           ;3
    call meminit
 	mov W1,[W0+W4]          ;4
   call meminit
 	mov.b [--W1],W0          ;5
   call meminit
	mov.b W1,[W0+W4]          ;6
   call meminit
	mov W2,[W0++]          ;7
   call meminit
 	mov W2,[--W0]          ;8
   call meminit
 	mov.b W2,[W0++]          ;9
   call meminit
 	mov.b W2,[--W1]          ;10
   call meminit
 	mov [W1+W4],W2          ;11
   call meminit
 	mov [++W1],W1         ;12
   call meminit
 	mov [W1],[W0++]         ;13
   call meminit
 	mov.b [W1+W4],W2         ;14
   call meminit
 	mov.b [++W1],W1         ;15
   call meminit
 	mov.b [W1],[W0++]         ;16

  call meminit
 	mov.b W1,[W0+3]         ;17

 call meminit
 	mov [W0-4],W1         ;18

   mov #0x0900,W15
   call meminit
   mov #0x0804,W15


	push W1				;19
  mov #0x0900,W15
   call meminit
   mov #0x0804,W15
 	pop W2				;20
  mov #0x0900,W15
   call meminit
   mov #0x0804,W15
 	pop W3				;21
  mov #0x0900,W15
   call meminit
   mov #0x0804,W15
 	push W0				;22
  mov #0x0900,W15
   call meminit
   mov #0x0804,W15

 	lnk #6			;23
  mov #0x0900,W15
   call meminit
   mov #0x0804,W15
 	ulnk			;24
 


done:
    goto     done    ;Place holder for last line of executed code

meminit:
 
    mov #0x382A, W0
    mov WREG, 0x800
    mov #0xFB80, W0
    mov WREG, 0x802
    mov #0x80FF, W0
    mov WREG, 0x804
    mov #0x7B03, W0
    mov WREG, 0x806
    mov #0x0001, W0
    mov WREG, 0x808
    mov #0xCE46, W0
    mov WREG, 0x80A
    mov #0x0804,W0
    mov #0x0806,W1
    mov #0x8301,W2
    mov #0xF0A2,W3
    mov #0x0004,W4
	mov #0x0804,W5 
    mov #0x0802,W14
    return
    
      




.end       ;End of program code in this file
