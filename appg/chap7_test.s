 
;
; Just check out MPLAB

		.include "p24Hxxxx.inc"

       .global __reset          ;The label for the first line of code. 

         .bss            ;unitialized data section
astring: .space 16
;..............................................................................
;Code Section in Program Memory
;..............................................................................

         .text           ;Start of Code section
__reset:                 ; first instruction located at __reset label
        mov #__SP_init, w15       ;Initalize the Stack Pointer
        mov #__SPLIM_init,W0   
        mov W0, SPLIM             ;Initialize the stack limit register
;__SP_init set by linker to be after allocated data      

    mov #'9',W0
    mov.b WREG,astring
    mov #'9',W0
    mov.b WREG,astring+1
    mov #'9',W0
    mov.b WREG,astring+2   
    clr.b astring+3
    mov #astring,W0
    call ascdec_to_binary

done:
    goto     done    ;Place holder for last line of executed code


;;W0 has a pointer to a string
;;W0 returns the converted value, only handles up to 65535
ascdec_to_binary:
    mov W0,W1
    mov #0x0A,W4
    clr W0
ascdec_top:
    cp0.b [W1]
    bra Z, ascdec_exit
    mov.b [W1++],W2
    mov #'0',W3
    sub.b W2,W3,W2   ;W2 is now 0 through 9
    ze W2,W2
    mul.uu W0,W4,W6
    add W2,W6,W0
    bra ascdec_top
ascdec_exit:
    return
   



p30:
    add.b W0,W1,W0
    bra NOV, p30_exit  ; exit if no overflow
    add W1,#0,W1       ; test to see if W1 is negative
    bra NN, p30_max_pos
    mov.b #0x80,W0     ; W0 is max negative
    bra p30_exit
p30_max_pos:
    mov.b #0x7f,W0     ; W0 is max positive
p30_exit:
    return


 
    
;;These start at location 0x0800 because 0-0x07FF reserved for SFRs
float_j: .single -0.15625  ;single precision float
float_k: .single -545.6875


.end       ;End of program code in this file
