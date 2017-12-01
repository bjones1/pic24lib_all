; .. Copyright (c) 2013 Bryan A. Jones, Robert B. Reese, and J. W. Bruce ("AUTHORS")
;    All rights reserved.
;    (B. A. Jones, bjones_AT_ece.msstate.edu, Mississippi State University)
;    (R. Reese, reese_AT_ece.msstate.edu, Mississippi State University)
;    (J. W. Bruce, jwbruce_AT_ece.msstate.edu, Mississippi State University)
;
;    Permission to use, copy, modify, and distribute this software and its
;    documentation for any purpose, without fee, and without written agreement
;    is hereby granted, provided that the above copyright notice, the following
;    two paragraphs and the authors appear in all copies of this software.
;
;    IN NO EVENT SHALL THE "AUTHORS" BE LIABLE TO ANY PARTY FOR DIRECT,
;    INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT OF THE
;    USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE "AUTHORS" HAS BEEN
;    ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;
;    THE "AUTHORS" SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT
;    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
;    PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS ON AN "AS IS"
;    BASIS, AND THE "AUTHORS" HAS NO OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT,
;    UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
;
;    Please maintain this header in its entirety when copying/modifying these
;    files.
;
; ***********************************************************************
; psv_intarray.s - Initialize array from program memory (PIC24H/dsPIC33F)
; ***********************************************************************
; Illustrates array initialization from program memory
; using the PSV window, PIC24H/dsPIC33F

.include "xc.inc"

.global __reset          ;The label for the first line of code.


      .bss        ;unitialized data section
;;These start at location 0x0800 because 0-0x07FF reserved for SFRs

i8_a:   .space 4*1      ;Allocating space (in bytes) to variable
i16_b:  .space 4*2      ;Allocating space (in bytes) to variable
ui32_c: .space 4*4      ;Allocating space (in bytes) to variable

;; constant data to be moved to data memory
.section .const,psv
i8_a_const:  .byte -9, 10, 58, -125
i16_b_const:  .word 200, -3200, -2, 450
ui32_c_const:  .long 160235, 250345, 65536, 489300

.text                             ;Start of Code section
__reset:                          ; first instruction located at __reset label
       mov #__SP_init, w15       ;Initalize the Stack Pointer
       mov #__SPLIM_init,W0
       mov W0, SPLIM             ;Initialize the stack limit register
       call init_variables       ;initialize global variables
 ;__SP_init set by linker to be after allocated data
       rcall main              ;call main()
       reset                   ;start over
main:
    ;empty body...
done:
    goto    done           ;infinite wait loop





init_variables:
;turn on Program Visibility Space
;value of 0
    bset CORCON,#2   ;enable PSV
;only set the PSVPAG once since these are all on the same page
    mov #psvpage(i8_a_const), W0
    mov W0,PSVPAG
;copy i8_a_const to i8_a
    mov  #psvoffset(i8_a_const),W0
    mov  #i8_a,W1        ;destination address in data memory
    mov  #((4*1)-1),W2    ;(number of bytes)-1 to copy
    call byte_copy
;copy i16_b_const to i16_b
    mov  #psvoffset(i16_b_const),W0
    mov  #i16_b,W1        ;destination address in data memory
    mov  #((4*2)-1),W2    ;(number of bytes)-1 to copy
    call byte_copy
;copy i32_c_const to i32_c
    mov  #psvoffset(ui32_c_const),W0
    mov  #ui32_c,W1        ;destination address in data memory
    mov  #((4*4)-1),W2    ;(number of bytes)-1 to copy1
    call byte_copy
    return

byte_copy:
    repeat W2
    mov.b [W0++],[W1++]
    return
 .end
