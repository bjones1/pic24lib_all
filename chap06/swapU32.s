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
; *******************************************************
; swapU32.s - Swap two U32 values referenced by a pointer
; *******************************************************

.include "xc.inc"

.global __reset          ;The label for the first line of code.


     .bss           ;unitialized data section

au32_x:    .space   4*4  ; four element u32 array

.text                             ;Start of Code section
__reset:                          ; first instruction located at __reset label
       mov #__SP_init, W15       ;Initalize the Stack Pointer
       mov #__SPLIM_init, W0
       mov W0, SPLIM             ;Initialize the stack limit register
       rcall init_a
       goto main
 ;__SP_init set by linker to be after allocated data

main:
       mov #au32_x, W0
       mov.b #1, W1
       mov.b #3, W2
       rcall swapU32


done:
    goto    done           ;infinite wait loop


; u32_baseptr passed in W0
; u8_k passed in W1
; u8_i passed in W2
; W3 used for &bptr[k]
; W4 used for &bptr[j]
; W5,W6 used for u32_tmp
swapU32:
    ze W1, W1
    ze W2, W2
    sl W1, #2, W1      ; k=k<<2=k*4
    sl W2, #2, W2      ; j=j<<2=j*4
    add W0, W1, W3     ; W3 = &bptr[k]
    add W0, W2, W4     ; W4 = &bptr[j]

    mov [W3++], W5     ; W5 = bptr[k].LSW
    mov [W3--], W6     ; W6 = bptr[k].MSW

    mov [W4++], [W3++] ; bptr[k].LSW = bptr[j].LSW
    mov [W4--], [W3--] ; bptr[k].MSW = bptr[j].MSW

    add W0, W2, W4     ; W4 = &bptr[j]

    mov W5, [W4++]     ; bptr[j].LSW = u32_tmp.LSW;
    mov W6, [W4--]     ; bptr[j].MSW = u32_tmp.MSW;

    return

; Initialize au32_x array
init_a:

    mov #au32_x, W2
    mov #0xA1F9, W0
    mov #0x0982, W1
    mov.d W0, [W2++]
    mov #0x3204, W0
    mov #0x88B2, W1
    mov.d W0, [W2++]
    mov #0x6B10, W0
    mov #0xE3D9, W1
    mov.d W0, [W2++]
    mov #0xFB29, W0
    mov #0xC385, W1
    mov.d W0, [W2++]
    return

    .end
