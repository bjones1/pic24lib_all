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
; **********
; bcd_test.s
; **********

.include "p24Hxxxx.inc"

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
      mov #0xFFFF,W0  ; 65535 unsigned, -1 signed
      mov #0x1,W1     ; 1 unsigned, +1 signed

;addition
      mov   #0x39,W0
      mov   #0x28,W1
      rcall bcd_add8  ;BCD (39 + 28 = 67)

;subtraction
      mov   #0x42,W0
      mov   #0x24,W1
      rcall bcd_sub8 ;BCD (42 - 24 = 18)


done:                     ;do not return
       bra done

;;do bcd 8-bit addition, W0+W1=W0
bcd_add8:
      add.b W0,W1,W0  ;W0 = W0 + W1
      daw.b W0        ;decimal adjust
      return

;;do bcd 8-bit subtractin, W0-W1=W0
bcd_sub8:
      mov   #0x99,W2
      sub.b W2,W1,W1  ;do 0x99-W1
      inc.b W1,W1     ;add 1 for 10's complement
      add.b W0,W1,W0  ;W0 = W0 + (-W1)
      daw.b W0
      return




    .end
