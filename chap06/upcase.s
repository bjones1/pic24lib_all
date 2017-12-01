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
; ***************************************
; upcase.s - Change a string to uppercase
; ***************************************

.include "xc.inc"

.global __reset          ;The label for the first line of code.


      .bss        ;unitialized data section
;;These start at location 0x0800 because 0-0x07FF reserved for SFRs
s:   .space  6        ;Allocating space (in bytes) to variable

.text                             ;Start of Code section
__reset:                          ; first instruction located at __reset label
       mov #__SP_init, W15       ;Initalize the Stack Pointer
       mov #__SPLIM_init,W0
       mov W0, SPLIM             ;Initialize the stack limit register

;;uppercase string at s:

  mov #s,W0         ;W0=&s[0]
top_loop:
  mov.b [W0],W1     ;W1=*p
  cp.b W1,#0x00
  bra Z, end_loop   ;exit if at end of string
  mov #0x60,W2
  cp.b W1,W2        ;compare *p and 0x60
  bra LEU, end_if   ;skip if-body
  mov #0x7B,W2
  cp.b W1,W2        ;compare *p and 0x7B
  bra GEU, end_if   ;skip if_body
  mov #0x20,W2
  sub.b W1,W2,[W0]  ;*p = *p-0x20
end_if:
  inc W0,W0         ;do p=p+1*sizeof(char)=p+1
  bra top_loop      ;loop back to top
end_loop:

done:
    goto    done           ;infinite wait loop

;*p passed in W0
;W1,W2 used as temporaries

  return



    .end
