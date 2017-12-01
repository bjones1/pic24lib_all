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
; *****************************************************************************
; psv_upcase_24E33E.s - Initialize string from program memory (PIC24E/dsPIC33E)
; *****************************************************************************
; illustrates string initialization from program memory
; using the PSV window for the PIC24E/dsPIC33E family

.include "xc.inc"

.global __reset          ;The label for the first line of code.


      .bss        ;unitialized data section
;;These start at location 0x01000 because 0-0x0FFF is reserved for SFRs
sz_1:   .space  6        ;Allocating space (in bytes) to variable
sz_2:   .space 12        ;reserve space

;; constant data to be moved to data memory
.section .const,psv
sz_1_const: .asciz  "Hello"
sz_2_const: .asciz  "UPPER/lower"

.text                             ;Start of Code section
__reset:                          ; first instruction located at __reset label
       mov #__SP_init, w15       ;Initalize the Stack Pointer
       mov #__SPLIM_init,W0
       mov W0, SPLIM             ;Initialize the stack limit register
       call init_variables       ;initialize strings
 ;__SP_init set by linker to be after allocated data
       rcall main              ;call main()
       reset                   ;start over
main:
    mov #sz_1,W0
    rcall upcase
    mov #sz_2,W0
    rcall upcase
done:
    goto    done           ;infinite wait loop

;*p passed in W0
;W1,W2 used as temporaries
upcase:
  mov.b [W0],W1       ;W1=*p
  cp.b W1,#0x00
  bra Z, upcase_exit  ;exit if at end of string
  mov #0x60,W2
  cp.b W1,W2             ;compare *p and 0x60
  bra LEU, upcase_end_if  ;skip if-body
  mov #0x7B,W2
  cp.b W1,W2          ;compare *p and 0x7B
  bra GEU, upcase_end_if     ;skip if_body
  mov #0x20,W2
  sub.b W1,W2,[W0]    ; *p = *p-0x20
upcase_end_if:
  mov.b [W0],[W0++]   ;dummy move to do p++
  bra upcase          ;loop back to top
upcase_exit:
  return



init_variables:
    movpag #psvpage(sz_1_const), DSRPAG   ;PIC24E/dsPIC33E family
;copy source address in program memory to W0
    mov  #psvoffset(sz_1_const),W0
    mov  #sz_1,W1        ;destination address in data memory
    rcall copy_cstring
;copy source address in program memory to W0
    movpag #psvpage(sz_2_const), DSRPAG  ;PIC24E/dsPIC33E family
    mov  #psvoffset(sz_2_const),W0
    mov  #sz_2,W1        ;destination address in data memory
    rcall copy_cstring
    return
;;copy constant null-terminated string from program memory to data memory
;;W0 points to program memory, W1 to data memory
copy_cstring:
    mov.b [W0],W2
    cp.b W2,#0
    bra Z, copy_cstring_exit  ;exit if null byte
    mov.b [W0++],[W1++]
    bra  copy_cstring
copy_cstring_exit:
    mov.b [W0++],[W1++]    ;copy null byte
    return


    .end
