call scons -j 1 %* > err.txt 2>&1
findstr /V /C:"warning: Options have been disabled due to expired license" /C:"#warning Clock configured" /C:"#warning Baud rates of 19200 or lower recommended for this clock choice." /C:"#warning Baud rates of 9600 or lower recommended for this clock choice." /C:"#warning Using dummy function for configPinsForLowPower() in 'common/pic24_util.c'" /C:"#warning Using default config bit settings for the " /C:"#warning Edit this file to define bits for your processor!" /C:"DAC_R2R.C built for SPI-based 12-bit MAX5353 DAC connected to RP14(SDO) and RP13(SCLK)" err.txt > err1.txt
findstr /V /C:"#warning UART2 pin mappings not defined. See comments below for more info." /C:"#warning UART1 RX pin configured to RP10(RB10), UART1 TX pin configured to RP11(RB11)" /C:"#warning UART1 RX pin configured to RP42(RB10), UART1 TX pin configured to RP43(RB11)" err1.txt > err2.txt
echo Errors and warnings:
findstr /C:"warning" /C:"error" err2.txt
