REM .. "Copyright (c) 2008 Robert B. Reese, Bryan A. Jones, J. W. Bruce ("AUTHORS")"
REM    All rights reserved.
REM    (R. Reese, reese_AT_ece.msstate.edu, Mississippi State University)
REM    (B. A. Jones, bjones_AT_ece.msstate.edu, Mississippi State University)
REM    (J. W. Bruce, jwbruce_AT_ece.msstate.edu, Mississippi State University)
REM
REM     Permission to use, copy, modify, and distribute this software and its
REM     documentation for any purpose, without fee, and without written agreement is
REM     hereby granted, provided that the above copyright notice, the following
REM     two paragraphs and the authors appear in all copies of this software.
REM
REM     IN NO EVENT SHALL THE "AUTHORS" BE LIABLE TO ANY PARTY FOR
REM     DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
REM     OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE "AUTHORS"
REM     HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
REM
REM     THE "AUTHORS" SPECIFICALLY DISCLAIMS ANY WARRANTIES,
REM     INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
REM     AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
REM     ON AN "AS IS" BASIS, AND THE "AUTHORS" HAS NO OBLIGATION TO
REM     PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
REM
REM     Please maintain this header in its entirety when copying/modifying
REM     these files.
REM
REM ***********************************************************
REM runscons.bat - Run SCons, collecting and filtering warnings
REM ***********************************************************
REM First, run the build, collecting all errors and warnings into ``err.txt``.
call scons -j 1 %* > err.txt 2>&1

REM Remove #warnings generated during compiles
REM ==========================================
REM Note: the ``> errn.txt`` was placed immediately after findstr below, since the
REM use of ``\"`` confuses cmd.exe (but not findstr). Placing it at the end
REM prevents cmd.exe from capturing output to the ``errn.txt`` file.
REM
REM Therefore, I can't use the ^ line continuation character following lines where
REM the ``"`` symbols don't match.
findstr > err1.txt /V ^
/C:"warning: #warning \"Baud rates of 19200 or lower recommended for this clock choice.\""  ^
/C:"warning: #warning \"Using dummy function for configPinsForLowPower() in common/pic24_util.c.\"" ^
/C:"warning: #warning \"Using default config bit settings for the " /C:"warning: #warning \"Clock configured" err.txt

findstr > err2.txt /V ^
/C:"warning: #warning \"UART2 pin mappings not defined. See comments below for more info.\"" ^
/C:"warning: #warning \"UART3 pin mappings not defined. See comments below for more info.\"" ^
/C:"warning: #warning \"UART4 pin mappings not defined. See comments below for more info.\"" ^
/C:"warning: #warning \"Using dummy function for configPinsForLowPower().\"" ^
/C:"warning: #warning \"PLL Enabled.\"" ^
/C:"lib\src\pic24_ecan.c:233:2: warning: #warning \"ECAN module not configured for current processor frequency! Edit function configECAN1().\"" ^
/C:"lib\src\pic24_uart.c:263:5: warning: #warning Building configUART1() for the Dangerous Web target." ^
/C:"warning: #warning \"This example only works with the dsPIC33E/PIC24E families\"" ^
/C:"warning: #warning \"This example does not work with the dsPIC33E/PIC24E families.\"" ^
/C:"warning: #warning \"This is a E family processor, which this example does not support.\"" ^
/C:"warning: #warning \"DAC_R2R.C built for SPI-based 12-bit MAX5353 DAC connected to RB14(SDO) and RB13(SCLK).\"" ^
/C:"warning: #warning \"This processor selection has the DMA module; this code example is incompatible with a PIC24 CPU that has DMA.\"" ^
/C:"warning: #warning \"This example only works with a device that has a secondary oscillator.\"" ^
/C:"warning: #warning \"and an RTCC module.\"" ^
/C:"warning: #warning \"This processor selection does not have a DMA module; this code example is incompatible with a PIC24 CPU that does not have DMA.\""  ^
/C:"warning: #warning \"OR this is a E family processor, which this example does not support.\"" ^
/C:"warning: #warning \"For all PIC24F and some PIC24E/dsPIC33E family members, the DATA_FLASH_PAGE is set to the second to last flash page instead of the last page,\"" ^
/C:"warning: #warning \"as the last flash page in the 24F family contains the configuration bits.\"" ^
/C:"warning: #warning Building configUART1() for the Rev.F14 Embedded Systems target." ^
/C:"warning: #warning Building configUART1() for the Rev.C1 Embedded Systems target." ^
/C:"warning: #warning Building configUART1() for the StarterBoard_28P target." ^
/C:"warning: #warning \"Ensure that the PLLDIV value is set to divide by 2 in the configuration bits for " /C:"warning: #warning \"Edit common/pic24_configbits.c to add config bits for your processor!\"" err1.txt

REM Work around compiler warnings I can't figure out how to suppress
REM ================================================================
findstr > err3.txt /V ^
/C:"\bootloader\pic24_dspic33_bootloader.X\mem.c:119:1: warning: control reaches end of non-void function" ^
/C:"warning: Taking the address of '" ^
err2.txt

REM Output only errors and warnings
REM ===============================
findstr /C:"warning" /C:"error" err3.txt > build_errors.txt
echo Errors and warnings:
type build_errors.txt
