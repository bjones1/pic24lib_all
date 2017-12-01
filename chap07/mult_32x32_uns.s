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
; ***********************************************************
; mult_32x32_uns - Demonstrate unsigned 32 bit multiplication
; ***********************************************************

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
      mov #0xFFFF,W0  ;
      mov #0xFFFF,W1  ; s = W1:W0 = 4294967295
      mov #0xFFFF,W2  ;
      mov #0xFFFF,W3  ; r = W3:W2 = 4294967295
      call mult32x32_uns
;;W3:W2:W1:W0 = 0xFFFFFFFE00000001 = 18446744065119617025
done:                     ;do not return
       bra done

; p = s * r, where:
; W1:W0 = s
sL = W0
sH = W1
; W3:W2 = r
rL = W2
rH = W3
; Use W4-W11 to store low and high words of partial products 0-3
pp0L = W4
pp0H = W5
pp1L = W6
pp1H = W7
pp2L = W8
pp2H = W9
pp3L = W10
pp3H = W11
; 64-bit result in p = W3:W2:W1:W0 (p3:p2:p1:p0)
p0 = W0
p1 = W1
p2 = W2
p3 = W3
mult32x32_uns:
     push W8
     push W9
     push W10
     push W11
     mul.uu  sL,rL,pp0L  ;sL*rL = pp0
     mul.uu  sL,rH,pp1L  ;sL*rH = pp1
     mul.uu  sH,rL,pp2L  ;sH*rL = pp2
     mul.uu  sH,rH,pp3L  ;sH*rH = pp3
     mov  pp0L,p0        ;p0 = pp0L
     add  pp0H,pp1L,p1   ;p1 = pp0H + pp1L
;;now propagate carry all the way up to p3 word
     addc pp1H,pp2H,p2   ;p2 = pp1H + pp2H + cout(pp0H + pp1L)
     addc pp3H,#0,p3     ;p3 = pp3H + 0 + cout(previous sum)
;;next sum
     add  p1,pp2L,p1     ;p1 = pp2L + (p1=pp0H + pp1L)
;;now propagate carry all the way up to p3 word
     addc p2,pp3L,p2     ;p2 = pp3L + (p2=pp1H+pp2H) + cout(previous_sum)
     addc p3,#0,p3       ;p3 = p3 + 0 + cout(previous_sum)
;;64-bit result p3:p2:p1:p0
     pop W11
     pop W10
     pop W9
     pop W8
     return

    .end
