 
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

sz_1:   .space 16        ;reserve space    
sz_2:   .space 16        ;reserve space
u8_k:   .space 2         ;reserve space
i32_k:  .space 4
i8_p:   .space 1


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
   add.b W4, W2, W0    ;1
    call meminit
	add W4, W2, W0     ;2
   call meminit
	sub W1,W0,W2      ;3
   call meminit
    sub.b W4,W2, W2   ;4
   call meminit
	and.b W0, W1, W1  ;5
   call meminit
	and W3, W2, W0    ;6
   call meminit
	ior W3, W1, W0    ;7
   call meminit
	ior.b W0, W1, W0  ;8
   call meminit
	xor.b W3, W4, W4  ;9
   call meminit
 	xor W4, W3, W3    ;10
   call meminit
	clr W4         ;11
   call meminit
	clr.b W3       ;12
   call meminit
	setm W1      ;13
   call meminit
	setm.b W3      ;14
   call meminit
	bset.b 0x0801,#6      ;15
   call meminit
	bset 0x0804,#9      ;16
   call meminit
	bclr 0x0804,#15      ;17
   call meminit
	bclr.b 0x0805,#7      ;18
   call meminit
	btg 0x0806,#3      ;19
   call meminit
	btg.b  0x0808,#0      ;20
   call meminit
    com.b 0x0803      ;21
   call meminit
	com 0x0804      ;22
   call meminit
	lsr W3, #8, W3      ;23
   call meminit
	lsr W2,#4, W0      ;24
   call meminit
	sl W3,#12,W0      ;25
   call meminit 
	sl W1, #2, W0      ;26
   call meminit
	rlnc.b 0x0800      ;27
   call meminit
	rlnc 0x0800      ;28
   call meminit
	rlc 0x802      ;29
   call meminit
	rlc.b 0x803      ;30
   call meminit
	rrnc 0x0800    ;31
   call meminit
	rrnc.b 0x0800    ;32
   call meminit
	rrc.b 0x802    ;33
   call meminit
	rrc 0x806    ;34
   


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
    mov #0x0804,W0
    mov #0x0806,W1
    mov #0x8301,W2
    mov #0xF0A2,W3
    mov #0xFFFF,W4
	mov #0xFFFF,W8
    inc2 W8,W8            ;Z = 0, C = 1
    return
    
      




.end       ;End of program code in this file
