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
; ******************************************************************************
; fib_register.s - A recursive subroutine example to compute a Fibonnachi number
; ******************************************************************************

.include "xc.inc"

.global __reset          ;The label for the first line of code.


      .bss        ;unitialized data section
;;These start at location 0x0800 because 0-0x07FF reserved for SFRs
k:   .space 2        ;Allocating space (in bytes) to variable
j:   .space 2        ;Allocating space (in bytes) to variable.

.text                             ;Start of Code section
__reset:                          ; first instruction located at __reset label
       mov #__SP_init, W15       ;Initalize the Stack Pointer
       mov #__SPLIM_init,W0
       mov W0, SPLIM             ;Initialize the stack limit register
 ;__SP_init set by linker to be after allocated data
       rcall main              ;call main()
       reset                   ;start over

main:
       mov #13, W0
       mov WREG,j     ;j=13
 ;subroutine call
       mov j,WREG     ;W0 used to for n parameter
       rcall fib
       mov WREG,k

done:
    goto    done           ;infinite wait loop


; n passed in W0
; return value passed back in W0
; W1 used for f1 local
fib:
    cp W0,#0          ;n==0?
    bra Z,fib_exit    ;if W0 is 0, return it
    cp W0,#1          ;n==1?
    bra Z,fib_exit    ;if W0 is 1, return it
    push W0           ;save n (W0)
    dec W0,W0         ;n=n-1
    rcall fib         ;fib(n-1)
    mov W0,W1         ;save f1 in W1
    pop W0            ;get old n
    dec2 W0,W0        ;n=n-2
    push W1           ;save f1
    rcall fib         ;fib(n-2)
    pop W1            ;restore f1 to W1
    add W0,W1,W0      ;W0=fib(n-2)+f1
fib_exit:
    return            ;return f1

    .end
