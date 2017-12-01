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
; *********************************************************
; countOnes_assem.s - Counts the number of 1 bits in a word
; *********************************************************

.include "xc.inc"

.global __reset          ;The label for the first line of code.


         .data            ;unitialized data section

         .bss
;;These start at location 0x0800 because 0-0x07FF reserved for SFRs
u16_k:   .space 2        ;Allocating space (in bytes) to variable.
u8_j:    .space 1        ;Allocating space (in bytes) to variable.

.text                          ;Start of Code section
__reset:                       ; first instruction located at __reset label
       mov #__SP_init, w15     ;Initalize the Stack Pointer
       mov #__SPLIM_init,W0
       mov W0, SPLIM           ;Initialize the stack limit register
       rcall main              ;call main()
       reset                   ;start over
 ;__SP_init set by linker to be after allocated data

main:
; u16_k = 0xA501;
       mov #0xA501, W0
       mov WREG, u16_k     ;init u16_k

; u8_j = countOnes(u16_k);
       mov u16_k, WREG     ;W0 used to for u16_v parameter
       rcall countOnes
       mov.b WREG, u8_j
done:                     ;do not return
       bra done




; u16_v passed in W0
; return value passed back in W0
; W1 used for local u8_cnt, W2 for u8_i
countOnes:
    clr.b W1          ;u8_cnt=0
    clr.b W2          ;u8_i=0
loop_top:
    cp.b W2,#16       ;compare u8_i, 16
    bra GEU,end_loop  ;exit loop if u8_i>=16
    btst.z W0,#0      ;test LSbit for zero
    bra Z, end_if
    inc.b W1,W1       ;u8_cnt++;
end_if:
    lsr W0,#1,W0      ;u16_v = u16_v >> 1;
    inc.b W2,W2       ;u8_i++
    bra loop_top
end_loop:
    mov.b W1,W0       ;W0 = u8_cnt for
    return            ;  return value


    .end
