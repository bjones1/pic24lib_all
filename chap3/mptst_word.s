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
; .. highlight:: nasm
;
; ************
; mptst_word.s
; ************
; This file demonstrates translating the following *C* program to assembly:
;
; .. code-block:: C
;
;     uint16_t u16_i;
;     uint16_t u16_j;
;     uint16_t u16_k;
;
;   void main() {
;     i = 2047;    /* i = 2047 (0x7FF). */
;     i = i + 1;   /* i++, so i = 2048 (0x800).  */
;     j = i;       /* j is 2048 (0x0800). */
;     j = j - 1;   /* j--, so j is 2047.   */
;     k = j + i;   /* k = 4095 (0x0FFF). */
;   }
;
; Declare variables
; =================
; Next, set aside space for some variables to work with. The ``.bss`` command instructs the assembler to place the following values in data memory. Data memory starts at 0x0800; locations 0x000-0x07FF are reserved for special function registers (SFRs).
.bss
; Reserve two bytes (16 bits) for each variable using the ``.space`` directive. To emphasize the connection between assembly and *C*, the equivalent *C* code given above is repeated before its assembly-language translation.
;; uint16_t u16_i;
u16_i:   .space 2
;; uint16_t u16_j;
u16_j:   .space 2
;; uint16_t u16_k;
u16_k:   .space 2
; This isn't used, but makes the debugger display the size of the u16_k variable above correctly.
u16_bug: .space 2

; Code
; ====
; Now, we can write code. First, tell the assembly the following lines should be placed in program memory using the ``.text`` directive.
.text
; Next, label the beginning of our program, so the PIC24 will know what to do after powering up.
.global __reset          ;The label for the first line of code.
__reset:
; Our code starts here. The *C* program above is listed as a comment before each group of resulting assembly statements. Above each *C* line is a register assignment. After the register assignment comes the input, process, and output steps.

  ;; W0   W0
  ;; i = 2047;
  ; Input
  mov #2047, W0
  ; Output
  mov W0, u16_i

  ; This statement requires no register assignments.
  ;; u16_i = u16_i + 1;
  ; Input, process, and output
  inc  u16_i

  ;; W0       W0
  ;; u16_j = u16_i
  ; Input
  mov   u16_i, W0
  ; Output
  mov   W0, u16_j

  ;; u16_j = u16_j - 1;
  ; Input, process, and output
  dec   u16_j

  ;;  W0      W1      W2
  ;; u16_k = u16_j + u16_i
  ; Input
  mov   u16_j, W1
  mov   u16_i, W2
  ; Process
  add   W1, W2, W0
  ; Output
  mov   W0, u16_k

; The code is complete, but the processor doesn't stop. To give it something to do, loop forever.
done:
  goto     done    ;Place holder for last line of executed code
