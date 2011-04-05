 
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
u32_i:       .space 4
u32_j:       .space 4
u32_k:       .space 4
u64_i:       .space 8
u64_j:       .space 8
u64_k:       .space 8
i16_i:       .space 2
i16_j:       .space 2
i16_k:       .space 2
i8_p:       .space 2
i8_q:       .space 2
i32_r:       .space 4
i32_s:       .space 4
i64_x:       .space 4

;..............................................................................
;Code Section in Program Memory
;..............................................................................

         .text           ;Start of Code section
__reset:                 ; first instruction located at __reset label
        mov #__SP_init, w15       ;Initalize the Stack Pointer
        mov #__SPLIM_init,W0   
        mov W0, SPLIM             ;Initialize the stack limit register
;__SP_init set by linker to be after allocated data      


p1_loop_top:
    mov u32_k,W0
    sub u32_i
    mov u32_k+2,W0
    subb u32_i+2      ;u32_i = u32_i – u32_k;
    mov u32_j,W0
    add u32_k,WREG
    mov W0,W2
    mov u32_j+2,W0
    addc u32_k+2,WREG 
    mov W0,W3       ;W3:W2 = u32_j + u32_k
    mov u32_i,W0  
    mov u32_i+2,W1  ;W1:W0 = u32_i
    cp W0,W2
    cpb W1,W3       ; u32_i < (u32_j + u32_k)
    bra LTU, p1_loop_top


p2:
    mov u32_i,W0
    ior u32_i+2,WREG
    bra Z, p2_end_if
    mov u32_j,W0
    ior u32_j+2,WREG
    bra Z, p2_end_if
    mov #0x0489,W0
    and u32_k
    mov #0xCFAB,W0
    and u32_k+2
p2_end_if:

p3:
     mov  u32_j,W0
     ior  u32_i,WREG
     mov  W0,u32_k
     mov  u32_j+2,W0
     ior  u32_i+2,WREG
     mov  W0,u32_k+2


p4_loop_top:
     mov u32_j,W0
     sub u32_i
     mov u32_j+2,W0
     subb u32_i+2
     bra Z,p4_loop_end
     lsr u32_k+2
     rrc u32_k
     clr W0
     dec u32_j
     subb u32_j+2
     bra p4_loop_top
p4_loop_end:


p5_loop_top:
    mov u64_k,W0
    sub u64_i
    mov u64_k+2,W0
    subb u64_i+2      
    mov u64_k+4,W0
    subb u64_i+4
    mov u64_k+6,W0
    subb u64_i+6    ;u64_i = u64_i – u64_k; 
    mov u64_j,W0
    add u64_k,WREG
    mov W0,W4
    mov u64_j+2,W0
    addc u64_k+2,WREG 
    mov W0,W5
    mov u64_j+4,W0
    addc u64_k+4,WREG 
    mov W0,W6 
    mov u64_j+6,W0
    addc u64_k+6,WREG 
    mov W0,W7         ;W7:W4 = u64_j + u64_k  
    mov u64_i,W0  
    mov u64_i+2,W1
    mov u64_i+4,W2
    mov u64_i+6,W3     ;W3:W0 = u64_i
    cp W0,W4
    cpb W1,W5       
    cpb W2,W6
    cpb W3,W7          ; u64_i < (u64_j + u64_k)
    bra LTU, p5_loop_top



p6:
    mov u64_i,W0
    ior u64_i+2,WREG
    ior u64_i+4,WREG
    ior u64_i+6,WREG
    bra Z, p6_end_if
    mov u64_j,W0
    ior u64_j+2,WREG
    ior u64_j+4,WREG
    ior u64_j+6,WREG
    bra Z, p6_end_if
    mov #0x3210,W0
    and u64_k
    mov #0x7654,W0
    and u64_k+2
    mov #0xBA98,W0
    and u64_k+4
    mov #0xFEDC,W0
    and u64_k+6
p6_end_if:

p7:
     mov  u64_j,W0
     ior  u64_i,WREG
     mov  W0,u64_k
     mov  u64_j+2,W0
     ior  u64_i+2,WREG
     mov  W0,u64_k+2
     mov  u64_j+4,W0
     ior  u64_i+4,WREG
     mov  W0,u64_k+4
     mov  u64_j+6,W0
     ior  u64_i+6,WREG
     mov  W0,u64_k+6

p8_loop_top:
     mov u64_j,W0
     sub u64_i
     mov u64_j+2,W0
     subb u64_i+2
     mov u64_j+4,W0
     subb u64_i+4
     mov u64_j+6,W0
     subb u64_i+6
     bra Z,p8_loop_end
     lsr u64_k+6
     rrc u64_k+4
     rrc u64_k+2
     rrc u64_k
     clr W0
     dec u64_j
     subb u64_j+2
     subb u64_j+4
     subb u64_j+6
     bra p8_loop_top
p8_loop_end:


p22_loop_top:
    mov i16_k,W0
    sub i16_i        ; i16_i = i16_i – i16_k
    mov i16_j,W0
    add i16_k,WREG   ; W0 = (i16_j + i16_k)
    cp i16_i         ; i16_i < (i16_j + i16_k)
    bra LT, p22_loop_top   ;signed branch
 
p23:
    mov i16_j,W0
    cp i16_k
    bra LT, p23_end_if  ;signed branch
    asr i16_i           ;preserve sign
    asr i16_i
p23_end_if:

p24:
    mov.b i8_p, WREG
    se W0,W1           ;W1 = (int16_t) i8_p  (sign extend)
    sl i16_j,WREG      ;W0 = i16_j << 1
    add W1,W0,W0       ;W0 = (int16_t) i8_p + (i16_j << 1)
    mov #256,W1
    sub W0,W1,W0       ;W0 = (int16_t) i8_p + (i16_j << 1) - 256
    mov WREG,i16_k

p25:
    mov.b u8_q, WREG
    ze W0,W1           ;W1 = (int16_t) u8_q (zero extend)
    lsr W1,#2,W1       ;W1 = (int16_t) u8_q >> 2
    mov u16_k,W0
    sub W0,W1,W0       ;W0 = ((u16_k – (uint8_t) u8_q) >> 2)
    mov #0xA34D,W1
    and W0,W1,W0       ;W0 = ((u16_k – (uint8_t) u8_q) >> 2) & 0xA34D;
    mov WREG,u16_i
 
p26:
    mov i16_k,W2
    clr W3
    btsc W2,#15
    mov  #0xFFFF,W3     ;W3:W2 = (int32_t) i16_k
    sl   i32_s,WREG
    mov  W0,W4
    rlc  i32_s+2,WREG
    mov  W0,W5        ;W5:W4 = (i32_s << 1)
    add  W2,W4,W2
    addc W3,W5,W3     ;W3:W2 = (int32_t) i16_k + (i32_s << 1)
    mov  #1024,W0
    clr  W1           ;W1:W0 = (int32_t) 1024
    sub  W2,W0,W0
    subb W3,W1,W1     ;W1:W0 = (int32_t) i16_k + (i32_s << 1) - 1024
    mov W0,i32_r
    mov W1,i32_r+2

p27:
    mov.b i8_q,WREG
    se    W0,W0       ; W0 = (int16_t) i8_q
    clr   W1
    btsc W0,#15
    setm W1            ;W1:W0 = (int32_t) i8_q 
    asr  W1,W1
    rrc  W0,W0          ;W1:W0 = (int32_t) i8_q >> 2
    mov.d W0,W2         ;W3:W2 = (int32_t) i8_q >> 2
    mov i32_s,W0
    mov i32_s+2,W1      ;W1 = i32_s
    sub W0,W2,W0
    subb W1,W3,W1         ;W1:W0 = i32_s - (int32_t) i8_q >> 2
    mov #0x807F,W2
    mov #0x38DB,W3      ;W3:W2 = 0x38DB807F
    ior W0,W2,W0
    ior W1,W3,W1        ;W1:W0 = (i32_s - (int32_t) i8_q >> 2)| 0x38DB807F
    mov W0,i32_r
    mov W1,i32_r+2

p28:
    mov.b i8_q,WREG
    se    W0,W0       ; W0 = (int16_t) i8_q
    clr   W1
    clr   W2
    clr   W3
    add   W0,#0,W0    ; test negative flag
    bra   N,p28_skip1
    setm  W1
    setm  W2
    setm  W3
p28_skip1:               ;W3:W0 = (int64) i8_q 
    sl    W0,W0
    rlc   W1,W0
    rlc   W2,W2
    rlc   W3,W3          ;W3:W0 = (int64) i8_q << 1
    mov   i16_k,W4
    clr   W5
    clr   W6
    clr   W7
    add   W4,#0,W4    ; test negative flag
    bra   N,p28_skip2
    setm  W5
    setm  W6
    setm  W7
p28_skip2:               ;W7:W4 = (int64) i16_k 
    add   W0,W4,W4
    addc  W1,W5,W5
    addc  W2,W6,W6
    addc  W3,W7,W7       ;W7:W4 = (int64) i16_k + ((int64) i8_q << 1)
    mov   i32_s,W0
    mov   i32_s+2,W1     ;W1:W0 = i32_s
    clr   W2
    clr   W3
    add   W1,#0,W1    ; test negative flag
    bra   N,p28_skip3
    setm  W2
    setm  W3
p28_skip3:               ;W3:W0 = (int64) i32_s   
    sub   W4,W0,W0
    subb  W5,W0,W1
    subb  W6,W0,W2
    subb  W7,W0,W3       ;W3:W0 = (int64) i16_k + ((int64) i8_q << 1) - (int64) i32_s 
    mov   W0,i64_x
    mov   W0,i64_x+2
    mov   W0,i64_x+4
    mov   W0,i64_x+6
    
  
    

    
       

done:
    goto     done    ;Place holder for last line of executed code


    
      




.end       ;End of program code in this file
