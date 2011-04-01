 
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
 	mul.uu W0,W1,W8      ;1
 call meminit
	 mul.ss W0,W1,W8      ;2
 call meminit
    mul.us W0,W1,W8      ;3
 call meminit
	mul.su W0,W1,W8      ;4
 call meminit
	mul.ss W2,W3,W8      ;5
 call meminit
	mul.us W2,W3,W8      ;6
 call meminit
	mul.su W2,W3,W8      ;7
 call meminit
	mul.uu W2,W3,W8      ;8
 call meminit
    repeat #17
	div.u W6,W2        ;9
 call meminit
    repeat #17
	div.s W4,W5        ;10
 call meminit
    repeat #17
	div.u W4,W5        ;11
 call meminit
    repeat #17
	div.s W4,W2        ;12 
  call meminit
    repeat #17
	div.ud W8,W4        ;13
 call meminit
    repeat #17
    div.sd W8,W4        ;14
 call meminit
    repeat #17
	div.sd W6,W8        ;15
 call meminit
    repeat #17
	div.ud W8,W6        ;16
 call meminit
    repeat #17
	div.s W6,W9        ;17
 call meminit
    repeat #17
	div.ud W6,W4        ;18
    nop	

done:
    goto     done    ;Place holder for last line of executed code

meminit:
 
    mov #0xFFF4,W0
    mov #0x000A,W1
    mov #0x000C,W2
    mov #0xFF06,W3
    mov #0xFFD0,W4
	mov #0x0005,W5 
    
    mov #0xC0FF,W6
    mov #0x0001,W7
    mov #0xE000,W8
    mov #0xFFFF,W9

    return
    
      




.end       ;End of program code in this file
