call scons -j 1 %* > err.txt 2>&1

: Note: the > errn.txt was placed immediately after findstr, since the use of \" confuses cmd.exe (but not findstr). Placing it at the end prevents cmd.exe from capturing output to the errn.txt file.

: Remove #warnings generated during compiles
: ==========================================
findstr > err1.txt /V /C:"warning: Options have been disabled due to expired license" /C:"#warning \"Clock configured" /C:"#warning \"Baud rates of 19200 or lower recommended for this clock choice.\"" /C:"#warning \"Baud rates of 9600 or lower recommended for this clock choice.\"" /C:"#warning \"Using dummy function for configPinsForLowPower() in common/pic24_util.c.\"" /C:"#warning \"Using default config bit settings for the " /C:"#warning \"Edit this file to define bits for your processor!\"" /C:"DAC_R2R.C built for SPI-based 12-bit MAX5353 DAC connected to RP14(SDO) and RP13(SCLK)" err.txt

findstr > err2.txt /V /C:"#warning \"UART2 pin mappings not defined. See comments below for more info.\"" /C:"#warning \"UART1 RX pin configured to RP10(RB10), UART1 TX pin configured to RP11(RB11).\"" /C:"#warning \"UART1 RX pin configured to RP42(RB10), UART1 TX pin configured to RP43(RB11).\"" /C:"#warning \"Using dummy function for configPinsForLowPower().\"" /C:"#warning \"Ensure that the PLLDIV value is set to divide by 2 in the configuration bits for " /C:"#warning \"PLL Enabled."" err1.txt

: Work around compiler warnings I can't figure out how to suppress
: ================================================================
findstr > err3.txt /V /C:"\bootloader\pic24_dspic33_bootloader.X\mem.c:106:1: warning: control reaches end of non-void function" /C:"warning: Taking the address of '" err2.txt


: Output only errors and warnings.
: ================================
findstr /C:"warning" /C:"error" err3.txt > build_errors.txt
echo Errors and warnings:
type build_errors.txt
