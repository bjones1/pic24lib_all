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
; *************************************************************
; mptst_byte.s - translation of 8-bit *C* aritmetic to assembly
; *************************************************************
; Like :doc:`mptst_word.s`, this file demonstrates translating a *C* program
; into assembly; however, this *C* project uses 8-bit, rather than 16-bit,
; values.
;
; .. code-block:: c
;    :linenos:
;
;    uint8_t u8_i;
;    uint8_t u8_j;
;    uint8_t u8_k;
;
;    void main(void) {
;      u8_i = 100;           // u8_i = 64 (0x64).
;      u8_i = u8_i + 1;      // u8_i++, so u8_i = 101 (0x65).
;      u8_j = u8_i;          // u8_j is 101 (0x65).
;      u8_j = u8_j - 1;      // u8_j--, so u8_j is 100 (0x64).
;      u8_k = u8_j + u8_i;   // u8_k = 201 (0xC9).
;    }
;
; Declare variables
; =================
.bss
; Reserve one byte (8 bits) for each variable using the ``.space`` directive.
;; uint8_t u8_i;
u8_i:   .space 1
;; uint8_t u8_j;
u8_j:   .space 1
;; uint8_t u8_k;
u8_k:   .space 1
; This isn't used, but makes the MPLAB X v. 1.80 watch window display the size
; of the ``u8_k`` variable above correctly.
u8_bug: .space 2

; Code
; ====
.text
.global __reset
__reset:

  ;;  W0     W0
  ;; u8_i = 100;
  ; Input
  mov.b #100, W0
  ; Output. **Important note:** When MOVing directly from memory to register or
  ; vice versa, you must always target WREG (the 8-bit name for W0). You may not
  ; use W1, W2, etc.
  mov.b WREG, u8_i

  ; This statement requires no register assignments.
  ;; u8_i = u8_i + 1;
  ; Input, process, and output
  inc.b  u8_i

  ;;  W0     W0
  ;; u8_j = u8_i
  ; Input. As discussed above, this 8-bit operation **must** target WREG.
  mov.b   u8_i, WREG
  ; Output
  mov.b   WREG, u8_j

  ;; u8_j = u8_j - 1;
  ; Input, process, and output
  dec.b   u8_j

  ; To make this a bit easier, we'll re-use W0 to hold both u8_j and u8_k.
  ;;  W0     W0     W1
  ;; u8_k = u8_j + u8_i
  ; Input. First, load u8_i, since it overwrites WREG; then, load u8_j into
  ; WREG.
  mov.b u8_i, WREG
  mov.b W0, W1
  mov.b u8_j, WREG
  ; Process
  add.b W0, W1, W0
  ; Output
  mov.b WREG, u8_k

done:
  goto     done    ;Place holder for last line of executed code
