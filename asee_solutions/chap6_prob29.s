 
;
; This assembly code implements the following C code:
;
;; //pi16_a is a pointer to signed 16-bit integer array
;; //u8_cnt is the number of elements in the array
;; //Function returns the maximum value in the array.
;; int16_t find_max (int16_t* pi16_a, uint8_t u8_cnt) {
;;   int16_t i16_k;
;;   i16_k = –32768;
;;   while (u8_cnt != 0) {
;;      if (*pi16_a > i16_k) i16_k = *pi16_a;
;;      pi16_a++; u8_cnt––;
;;   }
;;   return i16_k;
;; }
;
;; int16_t ai16_x[]= {-34, 1024, -30452, 32767, 10, 245};
;; uint16_t au16_y[]= {2048, 10, 40323,356, 290, 20000};
;; int16_t  i16_signedMax;
;; uint16_t ui16_unsignedMax;
;;
;; main(){
;;  i16_signedMax = find_max(ai16_x, 6);
;; }
;;

;;



		.include "p24Hxxxx.inc"

       .global __reset          ;The label for the first line of code. 

         .bss            ;unitialized data section
;;These start at location 0x0800 because 0-0x07FF reserved for SFRs
;;an array of six signed 16-bit integers.
ai16_x:             .space 2*6     ;;initialized to contain: -34, 1024, -30452, 32767, 10, 245
;;an array of six unsigned 16-bit integers
au16_y:             .space 2*6     ;;initialized to contain: 2048, 10, 40323,356, 290, 20000
i16_signedMax:      .space 2
i16_signedMin:      .space 2
ui16_unsignedMax:   .space 2


;..............................................................................
;Code Section in Program Memory
;..............................................................................

         .text           ;Start of Code section
;;this emulates the C runtime actions before main() is called
__reset:                 ; first instruction located at __reset label
        mov #__SP_init, w15       ;Initalize the Stack Pointer
        mov #__SPLIM_init,W0   
        mov W0, SPLIM             ;Initialize the stack limit register
;__SP_init set by linker to be after allocated data      
        call init_variables       ;initialize RAM variables from Program memory space
        call main
        reset                     ;software reset if main returns (main should not return).


main:
        mov #ai16_x, W0   ;W0 has starting address of ai16_x[]
        mov #6,W1         ;W1 has number of elements in ai16_x[]
        rcall find_max
        mov W0, i16_signedMax

        mov #ai16_x, W0   ;W0 has starting address of ai16_x[]
        mov #6,W1         ;W1 has number of elements in ai16_x[]
        rcall find_min
        mov W0, i16_signedMin

        mov #au16_y, W0   ;W0 has starting address of ai16_x[]
        mov #6,W1         ;W1 has number of elements in ai16_x[]
        rcall find_max_unsigned
        mov W0, ui16_unsignedMax               
       

done:
    goto     done    ;Place holder for last line of executed code


;Assembly language implementation of
; int16_t find_max (int16_t* pi16_a, uint8_t u8_cnt)
;Register usage:
;W0 used for pi16_a parameter
;W1 used for u8_cnt parameter
;W2 used for local variable i16_k;
;Function return value is returned in W0

find_max:
   mov #0x8000,W2    ;i16_k = -32768
find_max_loop_top:
   cp0.b W1          ;check loop counter
   bra Z, find_max_exit  ;exit loop if loop counter is zero
   cp W2,[W0]        ;compare i16_k to *pi16_a, then signed branch
   bra GE, find_max_skip  ;skip if-body i16_k >= *pi16_a
   mov [W0],W2       ;i16_k = *pi16_a  //save new maximum value
find_max_skip:
   inc2 W0,W0        ;pi16_a++        //increment pointer to next integer
   dec.b W1,W1       ;u8_cnt--        //decrement loop counter
   bra find_max_loop_top  ;;back to top
find_max_exit:
   mov W2,W0         ;set up return value in W0
   return

find_min:
   mov #0x7FFF,W2    ;i16_k = +32767
find_min_loop_top:
   cp0.b W1          ;check loop counter
   bra Z, find_min_exit  ;exit loop if loop counter is zero
   cp W2,[W0]        ;compare i16_k to *pi16_a, then signed branch
   bra LE, find_min_skip  ;skip if-body i16_k <= *pi16_a
   mov [W0],W2       ;i16_k = *pi16_a  //save new maximum value
find_min_skip:
   inc2 W0,W0        ;pi16_a++        //increment pointer to next integer
   dec.b W1,W1       ;u8_cnt--        //decrement loop counter
   bra find_min_loop_top  ;;back to top
find_min_exit:
   mov W2,W0         ;set up return value in W0
   return

find_max_unsigned:
   mov #0x0000,W2    ;i16_k = 0
find_max_uns_loop_top:
   cp0.b W1          ;check loop counter
   bra Z, find_max_uns_exit  ;exit loop if loop counter is zero
   cp W2,[W0]        ;compare ui16_k to *pi16_a, then unsigned branch
   bra GEU, find_max_uns_skip  ;skip if-body ui16_k >= *pi16_a
   mov [W0],W2       ;ui16_k = *pi16_a  //save new maximum value
find_max_uns_skip:
   inc2 W0,W0        ;pi16_a++        //increment pointer to next integer
   dec.b W1,W1       ;u8_cnt--        //decrement loop counter
   bra find_max_uns_loop_top  ;;back to top
find_max_uns_exit:
   mov W2,W0         ;set up return value in W0
   return



;; Utility code to initialize RAM variables from constants in program memory
;; constant data to be moved to data memory
;;an array of six signed 16-bit integers
ai16_x_const:             .word -34, 1024, -30452, 32767, 10, 245
;;an array of six unsigned 16-bit integers
au16_y_const:             .word 2048, 10, 40323,356, 290, 20000   

init_variables:
;turn on Program Visibility Space, use default PSVPAG
;value of 0
    bset CORCON,#2   ;enable PSV 
;copy ai16_x_const to ai16_x
    mov  #psvoffset(ai16_x_const),W2   
    mov  #ai16_x,W3        ;destination address in data memory
    mov  #((6*2)-1),W4    ;(number of bytes)-1 to copy
    call byte_copy
    mov  #psvoffset(au16_y_const),W2   
    mov  #au16_y,W3        ;destination address in data memory
    mov  #((6*2)-1),W4    ;(number of bytes)-1 to copy
    call byte_copy
    return

byte_copy:
    repeat W4
    mov.b [W2++],[W3++]
    return



.end       ;End of program code in this file
