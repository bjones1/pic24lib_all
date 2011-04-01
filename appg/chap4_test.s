 
;
; Just check out MPLAB

		.include "p24Hxxxx.inc"

       .global __reset          ;The label for the first line of code. 

         .bss            ;unitialized data section
;;These start at location 0x0800 because 0-0x07FF reserved for SFRs
u16_i:       .space 2        ;Allocating space (in bytes) to variable.
u16_k:       .space 2        ;Allocating space (in bytes) to variable.
u16_j:       .space 2        ;Allocating space (in bytes) to variable.
u16_n:       .space 2
u8_p:        .space 2        ;keep this 2 so memory is aligned
u8_q:        .space 2
u8_r:        .space 2
u8_i:        .space 2
u8_j:        .space 2
u8_k:        .space 2


;..............................................................................
;Code Section in Program Memory
;..............................................................................

         .text           ;Start of Code section
__reset:                 ; first instruction located at __reset label
        mov #__SP_init, w15       ;Initalize the Stack Pointer
        mov #__SPLIM_init,W0   
        mov W0, SPLIM             ;Initialize the stack limit register
;__SP_init set by linker to be after allocated data      


p35:
       sl u16_j,WREG
       mov #0x30,W1
       sub W0,W1,W0
       add u16_i,WREG
       mov WREG,u16_k

p36:
       mov u16_j,W0
       sub u16_k,WREG
       lsr W0,#4,W0
	   and W0,#0x0F,W0
       mov WREG,u16_k

p37:
       mov.b u8_p,WREG
       ze W0,W1         ;W1 = (uint16) u8_p
       sl u16_j,WREG    ;W0 = u16_j << 1
       add W0,W1,W0     ;W0 = (uint16) u8_p +  ((uint16) u8_p)
       mov #0x30,W1
       sub W0,W1,W0     ;W0 = (uint16) u8_p +  ((uint16) u8_p) - 0x30
       mov WREG,u16_k

p38:  
       mov.b u8_p,WREG
       ze W0,W1         ;W1 = (uint16) u8_p
       mov u16_k,WREG
       sub W0,W1,W0     ;W0 = ((u16_k – (uint8) u8_q)
       lsr W0,#4,W0     ;W0 = ((u16_k – (uint8) u8_q) >> 4
       and W0,#0x0F,W0  ;W0 = (((u16_k – (uint8) u8_q) >> 4) & 0x0F
       mov WREG,u16_k

p39:
       mov #0x400,W0
       cp  u16_k
       bra GEU, p39_if_body
       cp0.b u8_r
       bra NZ, p39_else_body
p39_if_body:
       nop    ;;if body
       bra    p39_end_if
p39_else_body:
       nop    ;; else body
p39_end_if:
       
p40:
       mov u16_j,WREG
       cp  u16_k
       bra LTU,p40_if_body
       mov u8_q,WREG
       cp  u8_r
       bra Z, p40_else_body
p40_if_body:
       nop    ;;if body
       bra    p40_end_if
p40_else_body:
       nop    ;; else body
p40_end_if:

p41:
       mov #0x400,W0
       cp u16_k
       bra Z, p41_else_body
       mov u8_p,W0
       cp  u8_r
       bra LEU,p41_else_body
p41_if_body:
       nop    ;;if body
       bra    p41_end_if
p41_else_body:
       nop    ;; else body
p41_end_if:

p42:
       cp0 u16_k
       bra Z, p42_else_body
       mov u16_i,WREG
       cp u16_j
       bra LTU,p42_else_body
p42_if_body:
       nop    ;;if body
       bra    p42_end_if
p42_else_body:
       nop    ;; else body
p42_end_if:

p43:
p43_loop_top:
       mov u16_k,WREG
       cp u16_i
       bra Z,p43_loop_end
       nop   ;;loop body
       bra   p43_loop_top
p43_loop_end:

p44_loop_top:
       cp.b u8_r
       bra  Z, p44_loop_end
       mov.b u8_q,WREG
       cp.b  u8_p
       bra GEU, p44_loop_end
       nop   ;;loop body
       bra   p44_loop_top
p44_loop_end:


p45_loop_top:
       nop    ;;loop_body
       cp.b u8_r
       bra  NZ, p45_loop_top
       mov.b u8_q,WREG
       cp.b  u8_p
       bra LTU, p45_loop_top
    
p46_loop_top:
       nop    ;;loop_body
       mov u16_k,WREG
       cp u16_i
       bra Z, p46_loop_exit
       mov #0x50,W0
       cp u8_p
       bra GTU,p46_loop_top
p46_loop_exit:


p47:
    ;; Use W0 for u8_i 
    clr.b u8_k      ;u8_k = 0
    clr.b W0      ;u8_i = 0    
p47_loop_top:
    cp.b W0,#8     ;u8_i != 8
    bra  Z, p47_loop_exit
    btst.b u8_j, #0   ; test LSB of u8_j
    bra  Z, p47_skip
    inc.b u8_k       ;u8_k++
p47_skip:
    lsr.b  u8_j       ;u8_j = u8_j >> 1
    inc.b W0,W0       ;u8_i++;
p47_loop_exit:
 
 
p48:
    ;; Use W0 for u16_i, 
    clr u16_k    
    inc u16_k    ;u16_k = 1
    clr W0       ;u16_i = 0    
p48_loop_top:
    cp  W0,#16    ;u16_i != 8
    bra  Z, p48_loop_exit
    btst u16_j, #0   ; test LSB of u16_j
    bra  NZ, p48_skip
    sl  u16_k      ;u16_k = u16_k << 1
p48_skip:
    lsr  u16_j      ;u16_j = u16_j >> 1
    inc W0,W0       ;u16_i++;
p48_loop_exit:
 


done:
    goto     done    ;Place holder for last line of executed code


    
      




.end       ;End of program code in this file
