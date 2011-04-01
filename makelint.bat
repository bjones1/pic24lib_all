@echo off
echo @module %1 > ..\lint.mm
copy ..\lint.mm+%1 ..\lint.mm >> NUL
pushd ..
cd common
for %%i in (*.c) do echo @module %%i >> ..\lint.mm && copy ..\lint.mm+%%i ..\lint.mm >> NUL
cd ..\include
for %%i in (*.h) do echo @module %%i >> ..\lint.mm && copy ..\lint.mm+%%i ..\lint.mm >> NUL
echo @module pic24hj32gp202_ports.h >> ..\lint.mm
copy ..\lint.mm+devices\pic24hj32gp202_ports.h ..\lint.mm >> NUL
cd ..
echo @module p24hxxxx.h >> lint.mm
echo #define __PIC24HJ32GP202__ >> lint.mm
copy lint.mm+"C:\Program Files\Microchip\MPLAB C30\support\PIC24H\h\p24HJ32GP202.h" lint.mm >> NUL
echo @module libpic30.h >> lint.mm
copy lint.mm+"C:\Program Files\Microchip\MPLAB C30\support\generic\h\libpic30.h" lint.mm >> NUL
popd
