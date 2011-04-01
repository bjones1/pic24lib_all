 
;
; Just check out MPLAB

		.include "p24Hxxxx.inc"

       .global __reset          ;The label for the first line of code. 

         .bss            ;unitialized data section
block:   .space 2048
;;These start at location 0x0800 because 0-0x07FF reserved for SFRs
m_1000:       .space 2        ;Allocating space (in bytes) to variable.
m_1002:       .space 2        ;Allocating space (in bytes) to variable.
m_1004:       .space 2        ;Allocating space (in bytes) to variable.
m_1006:       .space 2
m_1008:       .space 2

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

 	mov W2,0x1008       ;16
   call meminit
 	mov.b 0x1001,WREG      ;17
   call meminit
	 	mov #0x1001,W1     ;18   
   call meminit
 	mov.b [W3],[W4]     ;19
   call meminit
 	mov [W0],W4        ;20
   call meminit
	 mov.b #0x20,W3      ;21   
  call meminit
   add W0,[W0],W1      ;22
   call meminit
 	dec 0x1004,WREG      ;23
   call meminit
 	add 0x1002      ;24
   call meminit
 	add.b 0x1000,WREG      ;25
   call meminit
 	sub W0,W1,[W0]      ;26
   call meminit
 	sub.b W4,#10,[W0]      ;27
   call meminit
 	dec2 0x1008      ;28
   call meminit
    dec2.b 0x1008      ;29
   call meminit
 	inc W0,[W3]       ;30
   call meminit
    inc2.b 0x1009    ;31
   call meminit
 	inc2 0x1008,WREG    ;32
  
done:
    goto     done    ;Place holder for last line of executed code

meminit:
 
    mov #0x382A, W0
    mov WREG, 0x1000
    mov #0xFB80, W0
    mov WREG, 0x1002
    mov #0x4D19, W0
    mov WREG, 0x1004
    mov #0xE7C0, W0
    mov WREG, 0x1006
    mov #0xFF00, W0
    mov WREG, 0x1008
    mov #0x1006,W0
    mov #0x00BC,W1
    mov #0x8345,W2
    mov #0x1000,W3
    mov #0x1005,W4
	mov #0x000,W8
    inc W8,W8            ;Z = 0, C = 0
    return
    
      




.end       ;End of program code in this file
