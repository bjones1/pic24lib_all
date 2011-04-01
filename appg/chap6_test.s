 
;
; Just check out MPLAB

		.include "p24Hxxxx.inc"

       .global __reset          ;The label for the first line of code. 

         .bss            ;unitialized data section
;;These start at location 0x0800 because 0-0x07FF reserved for SFRs
au16_values: .space 2*6  ; data memory space
ai16_x: .space 2*6       ; data_memory space
ai16_y: .space 2*6       ; data_memory space

;..............................................................................
;Code Section in Program Memory
;..............................................................................

         .text           ;Start of Code section
__reset:                 ; first instruction located at __reset label
        mov #__SP_init, w15       ;Initalize the Stack Pointer
        mov #__SPLIM_init,W0   
        mov W0, SPLIM             ;Initialize the stack limit register
;__SP_init set by linker to be after allocated data      


       

done:
    goto     done    ;Place holder for last line of executed code

p27:
;W0 = psz_1, W1 = psz_2 , W2 used for u8_char 
str_swap:
   cp0 [W0]             ; *psz_1 != 0
   bra Z, str_swap_exit
   mov.b [W0],W2        ;u8_char = *psz_1
   mov.b [W0],[W1]      ;*psz_1 = *psz_2 
   mov.b W2,[W1++]      ;*psz_2 = u8_char, psz_2++
   inc   W0,W0          ;psz_1++
   bra  str_swap
str_swap_exit:
   return

p28:
;W0 = pu16_x, W1 = u8_i,  W2 = u8_j
;W3 used for pu16_x+u8_i, W4 used for pu16_x+u8_j
;W5 used as u16_k local
u16_swap:
   ze W1,W1
   ze W2,W2    ;zero extend to 16 bits
   add W0,W1,W3  ;pu16_x+u8_i
   add W0,W2,W4  ;pu16_x+u8_j
   mov [W3],W5   ;u16_k = pu16_x[u8_i]
   mov [W4],[W3] ;pu16_x[u8_i] = pu16_x[u8_j]
   mov W5,[W3]   ;pu16_x[u8_j] = u16_k;
   return

p29:
;W0 = pi16_a, W1 = u8_cnt, W2 = i16_k
find_max:
   mov #0x8000,W2    ;i16_k = -32768
find_max_loop_top:
   cp0.b W1
   bra Z, find_max_exit
   cp W2,[W0]        ;16_k < *pi16_a
   bra GE, find_max_skip  ;signed compare
   mov [W0],W2       ;i16_k = *pi16_a
find_max_skip:
   inc2 W0,W0        ;pi16_a++
   dec.b W1,W1       ;u8_cnt-- 
   bra find_max_loop_top
find_max_exit:
   mov W2,W0         ;set up return value
   return

p30:
;W0 = pi16_a, W1 = pi16_b, W2 = u8_cnt
i16vec_add:
   cp0.b W2
   bra Z, i16vec_add_exit
   mov [W0],W3           ; W3 = *pi16_a
   add W3,[W1++],[W0++]  ;*pi16_a = *pi16_a + *pi16_b , pi16_a++; pi16_b ++;
   dec.b W2,W2           ;u8_cnt--
   bra i16vec_add
i16vec_add_exit:
   return

p31:

putch:
    nop     ;;dummy
    return

;W0 = psz_in
putstr:
    cp0.b [W0]
    bra Z, putstr_exit
    push W0       ;save W0 for subroutine call
    mov [W0],W0   ;get parameter for subroutine call
    call putch
    pop W0
    inc W0,W0     ;psz_in++
    bra putstr
putstr_exit:
    return

p32:
getch:
    nop     ;;dummy
    return

;W0 = psz_in, W1 used for u8_char
getstr:
    push W0          ;save psz_in
    call getch  
    mov W0,W1        ;u8_char = getch()
    pop W0
    mov.b W1,[W0++]  ;*psz_in = u8_char, psz_in++
    cp0.b W1         ;u8_char != 0
    bra NZ, getstr
    return

p35:
;pu16_x              ;FP - 12
;u8_i                ;FP - 10
;u8_j                ;FP - 8
;Rtn Addr (LSW)      ;FP - 6
;Rtn Addr (MSW)      ;FP - 4
;old FP              ;FP - 2
;i16_k			;<- New FP (+0)
;free			;<- New SP

;use W0 = pu16_x, W1 = u8_i,  W2 = u8_j
;W3 used for pu16_x+u8_i, W4 used for pu16_x+u8_j
;W5 used as offset registers
;local space used for i16_k
p35_u16_swap:
   lnk #2         ;allocate 2 words of space of i16_k
   mov #-12,W0
   mov [W14+W5],W0 ;W0 = pu16_x
   mov #-10,W5
   mov.b [W14+W5],W1 ;W1 = u8_i
   mov #-8,W5
   mov.b [W14+W5],W2 ;W2 = u8_j
   ze W1,W1
   ze W2,W2         ;zero extend to 16 bits
   add W0,W1,W3     ;pu16_x+u8_i
   add W0,W2,W4     ;pu16_x+u8_j
   mov [W3],[W14]   ;u16_k = pu16_x[u8_i]
   mov [W4],[W3]    ;pu16_x[u8_i] = pu16_x[u8_j]
   mov [W4],[W3]   ;pu16_x[u8_j] = u16_k;
   ulnk
   return

p36:
;pi16_a              ;FP - 10
;u8_cnt              ;FP - 8
;Rtn Addr (LSW)      ;FP - 6
;Rtn Addr (MSW)      ;FP - 4
;old FP              ;FP - 2
;i16_k			;<- New FP (+0)
;free			;<- New SP
;W0 = pi16_a, W1 = u8_cnt, W2 is used for i16_k, not local space

p36_find_max:
   lnk #2         ;allocate 2 words of space of i16_k
   mov #-10,W0
   mov [W14+W5],W0 ;W0 = pi16_a
   mov #-8,W5
   mov.b [W14+W5],W1 ;W1 = u8_cnt
   mov #0x8000,W2    ;i16_k = -32768
p36_find_max_loop_top:
   cp0.b W1
   bra Z, p36_find_max_exit
   cp W2,[W0]        ;16_k < *pi16_a
   bra GE, p36_find_max_skip  ;signed compare
   mov [W0],W2       ;i16_k = *pi16_a
p36_find_max_skip:
   inc2 W0,W0        ;pi16_a++
   dec.b W1,W1       ;u8_cnt-- 
   bra p36_find_max_loop_top
p36_find_max_exit:
   mov W2,W0         ;set up return value
   ulnk
   return

p37:
   mov #__SP_init, w15       ;Initalize the Stack Pointer
   mov #__SPLIM_init,W0   
   mov W0, SPLIM             ;Initialize the stack limit register
   call p37_init_variables
   call p37_main
   reset

ui16_swap:
   nop
   return

p37_main:

   mov #au16_values, W0
   mov #3,W1
   mov #4,W2
   call ui16_swap
p37_done: bra p37_done


au16_values_const:  .word 489, 45, 1000, 238, 30000, 10134
   
p37_init_variables:
    bset CORCON,#2   ;enable PSV 
;copy au16_values_const to au16_values
    mov  #psvoffset(au16_values_const),W2   
    mov  #au16_values,W3        ;destination address in data memory
    mov  #((6*2)-1),W4    ;(number of bytes)-1 to copy
    call p37_byte_copy
    return

p37_byte_copy:
    repeat W4
    mov.b [W2++],[W3++]
    return


p38:
   mov #__SP_init, w15       ;Initalize the Stack Pointer
   mov #__SPLIM_init,W0   
   mov W0, SPLIM             ;Initialize the stack limit register
   call p38_init_variables
   call p38_main
   reset

p38_i16vec_add:
   nop
   return

p38_main:

   mov #ai16_x, W0
   mov #ai16_y, W1
   mov #6,W2
   call p38_i16vec_add
p38_done: bra p38_done


ai16_x_const:  .word -3489, 239, 900, -216, 8920, -9345
ai16_y_const:  .word 980, 3766, -8472, 32000, -16788, 34
   
p38_init_variables:
    bset CORCON,#2   ;enable PSV 
;copy ai16_x_const to ai16_x
    mov  #psvoffset(ai16_x_const),W2   
    mov  #ai16_x,W3        ;destination address in data memory
    mov  #((6*2)-1),W4    ;(number of bytes)-1 to copy
    call p38_byte_copy
;copy ai16_y_const to ai16_y
    mov  #psvoffset(ai16_y_const),W2   
    mov  #ai16_y,W3        ;destination address in data memory
    mov  #((6*2)-1),W4    ;(number of bytes)-1 to copy
    call p38_byte_copy
    return

p38_byte_copy:
    repeat W4
    mov.b [W2++],[W3++]
    return




.end       ;End of program code in this file
