*************************************
Differences between PIC24H and PIC24E
*************************************
The library has been updated to be compatible with PIC24E/dsPIC33 devices (only tested on PIC24EP64GP202).
Most of the examples in Chapters 8-12 have been tested with the PIC24EP64GP202, with the exception of the
ADC examples where only the simple examples were tested. In the advanced chapter (chapter13), only the
flash memory examples have been updated. In cases where code changes were necessary, conditional compilation
was used for the PIC24E/dsPIC33E families.  The ESOS examples (chap 14) were not tested but should work.
The capstone examples were not modified/tested.

In most cases, modules have considerable new capability but also retain the same functionality as the
same modules in the PIC24H family.

Clock Speed
===========
The maximum clock speed is 60 MHz (instead of 40 MHz) over full temperature range, and 70Mhz over reduced ranged.
The library default is 60 MHz for PIC24E devices (there is a clock macro for 70MHz if you want to use it).
The clock configurations that use a crystal for the PIC24H are compatible with the PIC24E.

Change Interrupts, Analog pin configuration
===========================================
Change interrupt enable/disable, Analog enable/disable are now tied to the digital port name (there
are no more PCFGx bits for analog/enable disable, change interrupt/disable bit names are changed).
This is a good change, makes these more consistent with the pullup/pulldown/opendrain control bits (there are pulldowns
available, on PIC24E pins).

I2C
===
On 28 pin devices, have to use the Alternate I2C1 pins; the normal ones are not available.

Remappable pins
===============
Remappable pin numbers have changed (code examples have #ifdef to distinguish between families in these cases).
Some remappable pins on PIC24E are input-only (RPIxx pins).

Run Time Self Programming (Flash)
=================================
Registers for self=programming of flash memory have changed, requiring #ifdef to distinguish between families.
The erase page size for most PIC24E families is now double that of the PIC24, and so this means that more flash
space is reserved in low memory for the bootloader because of the increased coarseness of page erases.
Have to use double word programming on PIC24E devices instead of row programming.

SPI
===
The SPI1 port uses dedicated pins for higher speed (not remappable pins). The SPI2 port can be used with
remappable pins. On the PIC24H, the SPI1 port used remappable pins. Some more functionality availble, but
compatible with 24H.

ADC
===
Lots of new functionality, but PIC24E ADC compatible with PIC24H in basic modes.

Output Compare
==============
There are multiple output control modules, so OC1CON is now OC1CONx.
Some bits have moved around in OC2CONx, required header file changes.

The output compare modules now have their own internal timers for comparison purposes,
instead of using the Timer2/Timer3 registers for sources. This really changes how things works, since this
internal timer has to be reset by an external source, it does not roll over on its own.
The OCx module can now be either triggerred or synched by multiple sources, a new control register OCxCON2 selects this.

The PIC24E output compare can be made to emulate the PIC24H output compare for the most part by synching the internal timer of
the output compare module with either Timer2 or Timer3, which has been done for most of the examples.

There is now a dedicated high-speed PWM module which was not tested; all of the PWM examples were done using the
output compare modules as was done for the PIC24H.

Input Compare
=============
The changes to the output compare modules were made in a similar fashion to the input compare modules.

Other modules
=============
Advanced functional modules like ECAN, RTCC, comparators that have example code in Chapter 12 was not tested.

