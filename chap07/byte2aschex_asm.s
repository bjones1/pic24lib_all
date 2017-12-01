; .. Copyright (c) 2013 Bryan A. Jones, Robert B. Reese, and J. W. Bruce ("AUTHORS")
;    All rights reserved.
;    (B. A. Jones, bjones_AT_ece.msstate.edu, Mississippi State University)
;    (R. Reese, reese_AT_ece.msstate.edu, Mississippi State University)
;    (J. W. Bruce, jwbruce_AT_ece.msstate.edu, Mississippi State University)
;
;    Permission to use, copy, modify, and distribute this software and its documentation for any purpose, without fee, and without written agreement is hereby granted, provided that the above copyright notice, the following two paragraphs and the authors appear in all copies of this software.
;
;    IN NO EVENT SHALL THE "AUTHORS" BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE "AUTHORS" HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;
;    THE "AUTHORS" SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS ON AN "AS IS" BASIS, AND THE "AUTHORS" HAS NO OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
;
;    Please maintain this header in its entirety when copying/modifying these files.
;
; ******************
; bytes2aschex_asm.s
; ******************

.include "p24Hxxxx.inc"

.global __reset          ;The label for the first line of code.


         .data            ;unitialized data section

         .bss
;;These start at location 0x0800 because 0-0x07FF reserved for SFRs
u8_buf:   .space 2        ;Allocating space (in bytes) to variable.

.text                          ;Start of Code section
__reset:                       ; first instruction located at __reset label
       mov #__SP_init, w15     ;Initalize the Stack Pointer
       mov #__SPLIM_init,W0
       mov W0, SPLIM           ;Initialize the stack limit register
       rcall main              ;call main()
       reset                   ;start over
 ;__SP_init set by linker to be after allocated data

main:
      mov #0x9A,W0
      mov #u8_buf,W1
      rcall byte2aschex

done:                     ;do not return
       bra done

;;Convert lower 4-bits of W0 to ASCII Hex
nyb2aschex:
      mov.b #0x30,W2   ;offset for '0' to '9' digit
      cp.b W0,#10      ; W0  >= 10?
      bra LTU, nyb_1   ; branch if W0 < 10
      mov.b #0x37,W2   ;offset for 'A' to 'F' digit
nyb_1:
      add.b W0,W2,W0
      return

;;W0 is byte to be converted
;;W1 points to temp buffer that can hold 2 bytes
byte2aschex:
      ;do most significant digit
      push  W0          ;save
      lsr   W0,#4,W0    ;do upper 4-bits
      and.b W0,#0x0F,W0 ; mask off upper bits
      rcall nyb2aschex
      mov.b W0,[W1++]   ;save return value
      pop W0            ;restore
      ;do least significant digit
      and.b W0,#0x0F,W0 ; mask off upper bits
      rcall nyb2aschex
      mov.b W0,[W1]     ;save return value
      return

    .end
