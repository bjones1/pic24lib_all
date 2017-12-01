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
; **********************************************************************
; nsc.s - Implement the Number Sequencing Computering in PIC24 assembly.
; **********************************************************************

    .include "xc.inc"
    .global __reset          ;The label for the first line of code.

         .bss        ;unitialized data section

loc:      .space 1    ;byte variable
dout:     .space 1    ;byte variable

         .text           ;Start of Code section
__reset:                 ; first instruction located at __reset label
    mov #__SP_init, W15  ;Initalize the Stack Pointer


   ;bclr   loc, #0   ;uncomment for loc<0>=0
   bset    loc, #0   ;uncomment for loc<0>=1
loop_top:
   btsc.b  loc,#0    ;skip next if loc<0> is 0
   goto    loc_lsb_is_1
   ;loc<0> is 0 if reach here
   mov.b   #3,W0
   mov.b   WREG,dout  ;dout = 3
   mov.b   #2,W0
   mov.b   WREG,dout  ;dout = 2
   mov.b   #4,W0
   mov.b   WREG,dout  ;dout = 4
loc_lsb_is_1:
   mov.b   #8,W0
   mov.b   WREG,dout  ;dout = 8
   mov.b   #5,W0
   mov.b   WREG,dout  ;dout = 5
   mov.b   #6,W0
   mov.b   WREG,dout  ;dout = 6
   mov.b   #1,W0
   mov.b   WREG,dout  ;dout = 1
   goto    loop_top  ;loop forever
