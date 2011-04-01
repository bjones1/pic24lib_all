call scons -j 1 %* > err.txt 2>&1
findstr /V /C:"warning: Options have been disabled due to expired license" /C:"warning: #warning Clock configured" /C:"warning: #warning Baud rates of 19200 or lower recommended for this clock choice." /C:"warning: #warning Baud rates of 9600 or lower recommended for this clock choice." /C:"warning: #warning Using dummy function for configPinsForLowPower() in 'common/pic24_util.c'" /C:"warning: #warning Warning: Using default config bit settings in 'common/pic24_configbits.c' for PIC24H family." /C:"warning: #warning edit 'common/pic24_configbits.c' to define bits for your processor!" /C:"DAC_R2R.C built for SPI-based 12-bit MAX5353 DAC connected to RP14(SDO) and RP13(SCLK)" /C:"warning: #warning Using default config bit settings in 'common/pic24_configbits.c' for PIC24F family." err.txt > err1.txt
findstr /V /C:"warning: #warning UART2 pin mappings not defined!!! For simplicity," /C:"warning: #warning pin mappings are identical for UARTS 1-4. If your device has more than" /C:"#warning one UART, ****** CHANGE THE MAPPING ****** since" /C:"#warning multiple UARTs can not share the same pins." /C:"#warning In particular:" /C:"#warning 1. Change the statement #if (" /C:"warning: #warning 2. Change the pin numbers in the next four lines" /C:"to something valid for your device." /C:"If your device does not have remappable I/O," /C:"warning: #warning (typical for >44 pin packages), skip this step --" /C:"warning: #warning the UART I/O pins are already assigned to something" /C:"warning: #warning valid." err1.txt > err2.txt
