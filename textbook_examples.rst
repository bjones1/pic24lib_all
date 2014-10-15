.. "Copyright (c) 2008 Robert B. Reese, Bryan A. Jones, J. W. Bruce ("AUTHORS")"
   All rights reserved.
   (R. Reese, reese_AT_ece.msstate.edu, Mississippi State University)
   (B. A. Jones, bjones_AT_ece.msstate.edu, Mississippi State University)
   (J. W. Bruce, jwbruce_AT_ece.msstate.edu, Mississippi State University)

   Permission to use, copy, modify, and distribute this software and its
   documentation for any purpose, without fee, and without written agreement is
   hereby granted, provided that the above copyright notice, the following
   two paragraphs and the authors appear in all copies of this software.

   IN NO EVENT SHALL THE "AUTHORS" BE LIABLE TO ANY PARTY FOR
   DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
   OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE "AUTHORS"
   HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

   THE "AUTHORS" SPECIFICALLY DISCLAIMS ANY WARRANTIES,
   INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
   AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
   ON AN "AS IS" BASIS, AND THE "AUTHORS" HAS NO OBLIGATION TO
   PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."

   Please maintain this header in its entirety when copying/modifying
   these files.


*****************
Textbook examples
*****************

This page gives example PIC24 code accompanying the textbook titled `"Microcontrollers: From Assembly to C with the PIC24 Family" <http://www.reesemicro.com>`_ by R. Reese, B. Jones and J.W. Bruce published by Cengage Learning in December 2008.

The next section discussing using the example code, while the `example code directory`_ lists all available examples.

Using the example code
======================
First, make sure you've read the `getting started guide <http://www.reesemicro.com/Home/pic24-software-library-collection/getting-started>`_, insuring that your hardware and software are correctly configured.

These examples have minimal reliance on the libraries shipped with the PIC24 compiler, and instead use libraries that have been developed by the authors. The new libraries are meant to be more friendly to programmers who are new to the PIC24 Family, as this material and code examples are used in an introductory microprocessors class at Mississippi State University.

Most of the examples are meant for a reference dsPIC33EP128GP502 system. The projects all have a custom linker file intended for use with a serial bootloader - if you want generated hex files to be compatible with the PICKit 3 programmer then delete the linker file from the MPLAB X project.

If you have a different PIC24 Family member, simply change the target device in the MPLAB to that device. When you compile the files, you will get warnings that the internal oscillator with PLL is being used, and that the default configuration bit settings are being used.

To change clock options, see the documentation in `common/pic24_clockfreq.c <../pic24__clockfreq_8c.html>`_ and `include/pic24_clockfreq.h <../pic24__clockfreq_8h.html>`_  To change config bits, see the documentation on `common/pic24_configbits.c <../pic24__configbits_8c.html>`_

All of the examples assume a serial port using UART1; our reference system uses pins RP10 (RX) and RP11 (TX) with a default baud rate of 230,400 baud. To change these assignments, edit the function called configUART1() in `common/pic24_uart.c <../pic24__uart_8h.html>`_.  To change the default baudrate, edit the ``#define DEFAULT_BAUDRATE`` in `include/pic24_libconfig.h <../pic24__libconfig_8h.html>`_ (this file includes all of the macros for configuring user-defineable behavior for library functions).

If the end-of-line (EOL) output behavior is not correct for the serial terminal program that you are using (i.e, printed new lines do not return to the left edge of the screen), then you can change this by selecting an appropriate value for the ``SERIAL_EOL_DEFAULT`` macro contained in `include/pic24_libconfig.h`_. By default, the library signals an EOL using a line feed only.

Our examples also assume an LED tied to port RB15 - this is used as a 'heartbeat' and is blinked by our examples when waiting for input. You can reassign this to another port (see ``HB_LED``) or remove it entirely (see ``USE_HEARTBEAT``) by editing `include/pic24_libconfig.h`_.

The best project to start with is :doc:`reset.c <chap08/reset.c>` - this just assumes basic serial port functionality.

Example code directory
======================

Chapter 3: translation from *C* arithmetic to assembly
------------------------------------------------------
.. toctree::
   :titlesonly:

   chap03/mptst_word.s
   chap03/mptst_byte.s

Chapter 4: Unsigned 8/16-bit arithmetic
---------------------------------------
.. toctree::
   :titlesonly:

   chap04/nsc.s

Chapter 6: Pointers and subroutines
-----------------------------------
.. toctree::
   :titlesonly:

   chap06/countOnes.c
   chap06/countOnes_assem.s
   chap06/fib.c
   chap06/fib_register.s
   chap06/fib_stack.s
   chap06/psv_intarray.s
   chap06/psv_intarray_24E33E.s
   chap06/psv_upcase.s
   chap06/psv_upcase_24E33E.s
   chap06/swapU32.s
   chap06/upcase.s
   chap06/upcase_cversion.c

Chapter 7: Advanced assembly language - higher math
---------------------------------------------------
.. toctree::
   :titlesonly:

   chap07/aschex2byte.c
   chap07/aschex2byte_asm.s
   chap07/bcd_test.s
   chap07/byte2aschex.c
   chap07/byte2aschex_asm.s
   chap07/div_asm_tests.s
   chap07/float_bench.c
   chap07/float_encoding.s
   chap07/mult_32x32_uns.s
   chap07/mult_asm_tests.s
   chap07/sat_add.s

Chapter 8: initial startup, parallel port examples
--------------------------------------------------
.. toctree::
   :titlesonly:

   chap08/ledflash_nomacros.c
   chap08/ledflash.c
   chap08/echo.c
   chap08/asm_echo.s
   chap08/reset.c
   chap08/ledtoggle.c
   chap08/ledsw1.c
   chap08/lcd4bit.c
   chap08/lcd4bit_4lines.c

Chapter 9: interrupts, simple timer usage
-----------------------------------------
.. toctree::
   :titlesonly:

   chap09/trap_test.c
   chap09/trap_test_handled.c
   chap09/change_wakeup.c
   chap09/change_latency.c
   chap09/int1_wakeup.c
   chap09/squarewave.c
   chap09/filt_test.c
   chap09/softfilt_test.c
   chap09/ledsw1_sampling.c
   chap09/ledsw1_cn.c
   chap09/ledsw1_cn_revised.c
   chap09/rot_enc.c
   chap09/keypad.c
   chap09/rot_enc_trace.c


Extras
^^^^^^
These programs demonstrate related concepts, but are not directly discussed in the textbook.

.. toctree::
   :titlesonly:

   chap09/change_bounce.c
   chap09/change_test.c
   chap09/int0_bounce.c
   chap09/int0_wakeup.c
   chap09/int1_bounce.c
   chap09/ledflash_timer.c
   chap09/ledtoggle_timer.c

Chapter 10 (UART, SPI, I2C)
---------------------------
.. toctree::
   :titlesonly:

   chap10/soft_uart.c
   chap10/reverse_string.c
   chap10/mcp41xxx_spi_pot.c
   chap10/ds1722_spi_tempsense.c
   chap10/spi_master_revstring.c
   chap10/spi_slave_revstring.c
   chap10/ds1621_i2c.c
   chap10/ds1631_i2c.c
   chap10/mcp24lc515_i2c_eeprom.c

Extras
^^^^^^
These programs demonstrate related concepts, but are not directly discussed in the textbook.

.. toctree::
   :titlesonly:

   chap10/reverse_string_stdio.c
   chap10/stdio_test.c
   chap10/uart_wakeup.c

Chapter 11: Data Conversion - ADC, DAC
--------------------------------------
.. toctree::
   :titlesonly:

   chap11/adc2pots1.c
   chap11/adc7scan1.c
   chap11/adc7scan2.c
   chap11/adc4simul.c
   chap11/adc_spidac_test.c
   chap11/adc_test.c
   chap11/adc_test_12bit.c
   chap11/adc7scan1_dma_scatter_gather_1.c
   chap11/adc7scan1_dma_conv_order.c
   chap11/adc4simul_dma.c
   chap11/dac_r2r.c

Chapter 12: Timer coverage - PWM, input capture, output compare, time keeping
-----------------------------------------------------------------------------
.. toctree::
   :titlesonly:

   chap12/incap_freqmeasure.c
   chap12/incap_switch_pulse_measure.c
   chap12/ir_biphase_decode.c
   chap12/manual_switch_pulse_measure.c
   chap12/timer32bit_switch_pulse_measure.c
   chap12/outcompare_contpulse.c
   chap12/outcompare_squarewave.c
   chap12/outcompare_squarewave_24e.c
   chap12/outputcompare_oneservo.c
   chap12/outputcompare_multiservo.c
   chap12/ledpwm.c
   chap12/pwm_dac.c
   chap12/rtcc.c

Extras
^^^^^^
These programs demonstrate related concepts, but are not directly discussed in the textbook.

.. toctree::
   :titlesonly:

   chap12/incap_32bit_switch_pulse_measure.c
   chap12/ledpwm_bullymon.c
   chap12/pwm_dac.c
   chap12/timer1_sosc.c

Chapter 13: Advanced topics - DMA, ECAN, I2C slave, flash programming, comparator
---------------------------------------------------------------------------------
.. toctree::
   :titlesonly:

   chap13/comparator_example.c
   chap13/dma_example.c
   chap13/ecan_example_nofifo.c
   chap13/ecan_example_fifo.c
   chap13/ecan_example_fifo_eid.c
   chap13/flash_example.c
   chap13/i2c_master_reverse_string.c
   chap13/i2c_slave_reverse_string.c
   chap13/i2c_multmaster_rstring.c

Extras
^^^^^^
These programs demonstrate related concepts, but are not directly discussed in the textbook.

.. toctree::
   :titlesonly:

   chap13/simple_flash_example.c

Chapter 14: ESOS examples
-------------------------
.. toctree::
   :titlesonly:

   chap14/esos_skel.c
   chap14/app_flashled.c
   chap14/app_echo1.c
   chap14/app_reverse.c
   chap14/app_timerLEDecho.c
   chap14/app_semaphore1.c
   chap14/app_semaphore2.c
   chap14/app_childtask.c
   chap14/app_irqs.c
   chap14/app_ds1631.c
   chap14/app_ds1722.c

Extras
^^^^^^
.. toctree::
   :titlesonly:

   chap14/app_test1.c
   chap14/app_ds1631_msg.c
   chap14/app_mailA.c
   chap14/app_mailB.c
   chap14/app_mailC.c
   chap14/app_mailD.c

Examples converted to be compatible with the Explorer-16, 100-pin demo board
----------------------------------------------------------------------------
.. toctree::
   :titlesonly:

   explorer16_100p/reset.c
   explorer16_100p/lcd4bit.c
   explorer16_100p/adc_test.c
   explorer16_100p/timer1_sosc.c
   explorer16_100p/rtcc.c
   explorer16_100p/mcp25lc256_spi_eeprom.c

Examples using the `data transfer protocol <../data_xfer.html>`_
----------------------------------------------------------------
The following programs use the data transfer protocol, providing working examples of its usage.

.. toctree::
   :titlesonly:

   util/dataXfer_echo.c
   util/dataXfer_demo.c
