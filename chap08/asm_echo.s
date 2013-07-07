/** \file
   Demonstrates how to call C functions from assembly lanaguage.
   Implements a UART1 character echo, and calls the
   \ref configBasic, \ref inChar, and \ref outChar functions.
*/
/** \cond nodoxygen */
.include "xc.inc"         ; Include processor-specific headers


           .section psv psv		; Place following statements in PSV space
HELLO_MSG: .asciz "asm_echo.s ready!\n" ; Define a null-terminated ASCII string


;..............................................................................
;Code Section in Program Memory
;..............................................................................

.text                             ;Start of Code section

; int main() {
.global _main                   ; Make _main visible outside
								; this file so C startup code
                                ; can call it
_main:

  ;               W0
  ; configBasic(HELLO_MSG)
  mov #HELLO_MSG, W0
  call _configBasic

  ; while (1) {
  while_top:

    ; W0 = inChar();
    call _inChar

    ; W0++;
    inc W0, W0

    ; outChar(W0);
	call _outChar

  bra while_top
  ; }


/** \endcond */
