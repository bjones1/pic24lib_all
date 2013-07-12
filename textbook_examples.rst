..
  "Copyright (c) 2008 Robert B. Reese, Bryan A. Jones, J. W. Bruce ("AUTHORS")"
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
 
 

This page gives example PIC24 code accompanying the textbook titled `"Microcontrollers: From Assembly to C with the PIC24 Family" <http://www.reesemicro.com>`_ by R. Reese, B. Jones and J.W. Bruce published by Cengage Learning in December 2008.

The next section discussing using the example code, while the `example code directory`_ lists all available examples.

Using the example code
======================
First, make sure you've read the `getting started guide <http://www.reesemicro.com/Home/pic24-software-library-collection/getting-started>`_, insuring that your hardware and software are correctly configured.

These examples have minimal reliance on the libraries shipped with the PIC24 compiler, and instead use libraries that have been developed by the authors. The new libraries are meant to be more friendly to programmers who are new to the PIC24 Family, as this material and code examples are used in an introductory microprocessors class at Mississippi State University.

Most of the examples are meant for a reference PIC24E128GP202 system. The projects all have a custom linker file intended for use with a serial bootloader - if you want generated hex files to be compatible with the PICKIT2 programmer then delete the linker file from the MPLAB project.

If you have a different PIC24 Family member, simply change the target device in the MPLAB to that device. When you compile the files, you will get warnings that the internal oscillator with PLL is being used, and that the default configuration bit settings are being used.

To change clock options, see the documentation in common/pic24_clockfreq.c and include/pic24_clockfreq.h  To change config bits, see the documentation on common/pic24_configbits.c

All of the examples assume a serial port using UART1; our reference system uses pins RP10 (RX) and RP11 (TX) with a default baud rate of 230,400 baud. To change these assignments, edit the function called configUART1() in common/pic24_uart.c.  To change the default baudrate, edit the ``#define DEFAULT_BAUDRATE`` in include/pic24_libconfig.h (this file includes all of the macros for configuring user-defineable behavior for library functions).

If the end-of-line (EOL) output behavior is not correct for the serial terminal program that you are using (i.e, printed new lines do not return to the left edge of the screen), then you can change this by selecting an appropriate value for the ``SERIAL_EOL_DEFAULT`` macro contained in include/pic24_libconfig.h. By default, the library signals an EOL using a line feed only.

Our examples also assume an LED tied to port RB15 - this is used as a 'heartbeat' and is blinked by our examples when waiting for input. You can reassign this to another port (see \ref HB_LED) or remove it entirely (see \ref USE_HEARTBEAT) by editing pic24_libconfig.h.

The best project to start with is chap8/reset.c - this just assumes basic serial port functionality.

Example code directory
======================
Example code includes:
- Chapters 3-7 (assembly language)

- Chapter 8 (initial startup, parallel port examples)

  - chap08/asm_echo.s - Demonstrates calling C from assembly.
  - chap08/echo.c - inputs chararacter from UART RX1, echos back +1.
  - chap08/lcd4bit.c - Character LCD interface example
  - chap08/ledflash.c - Flashes an LED, uses I/O macros.
  - chap08/ledflash_nomacros.c - Flashes an LED, does not use I/O macros.
  - chap08/ledsw1.c - Demonstrates using a FSM approach for a LED/switch IO problem.
  - chap08/ledtoggle.c - Uses an FSM approach to toggle an LED whenever a pushbutton input is pressed and released.
  - chap08/ledtoggle_nofsm.c - Toggles an LED whenever a pushbutton input is pressed and released, does not use an FSM approach.
  - chap08/reset.c - Demonstrates software reset, idle, sleep, watchdog timer operation.
- Chapter 9 (interrupts, simple timer usage)

  - chap09/trap_test.c - Code which causes a math error (divide by zero) trap
  - chap09/trap_test_handled.c - contains an ISR which handles the math error (divide by zero)
  - chap09/button_semaphore.c - has a periodic timer ISR that creates a semaphore for a complete button press/release
  - chap09/change_bounce.c - uses a change notification interrupt to detect switch bounce
  - chap09/change_latency.c - measures ISR latency using a change notification interrupt
  - chap09/change_test.c - demos a change notification interrupt using an input pushbutton
  - chap09/change_wakeup.c - wake from sleep using a change notification interrupt
  - chap09/filt_test.c - test an extern low-pass RC filter effectiveness by generating a pulse train that is read by another port
  - chap09/int0_bounce.c - use the INT0 interrupt to detect switch bounce.
  - chap09/int0_wakeup.c - uses INT0 to wake from sleep mode.
  - chap09/int1_bounce.c - use the INT1 interrupt to detect switch bounce.
  - chap09/int1_wakeup.c - uses INT1 to wake from sleep mode.
  - chap09/keypad.c - Implements a 4x3 key scanned keypad interface.
  - chap09/ledflash_timer.c - uses a periodic timer interrupt to flash an LED.
  - chap09/ledsw1_timer.c - uses a periodic Timer3 interrupt for a LED/SW IO problem, uses a button semaphore in the ISR.
  - chap09/ledsw1_timer2.c - same problem as ledsw1_timer.c, except ISR implements the entire FSM for the LED/SW IO problem.
  - chap09/ledtoggle_timer.c - toggle an LED using a periodic interrupt to poll the switch input
  - chap09/rot_enc.c - A 2-bit incremental Gray code rotary encoder example
  - chap09/rot_enc_trace.c - Demonstrates use of an ISR trace buffer for capturing the states of a rotary encoder.
  - chap09/softfilt_test.c - Implements a software filter for input pulses less than a specified duration.
  - chap09/squarewave.c - Generates a square wave using timer 2 and an ISR.
- Chapter 10 (UART, SPI, I2C)

  - chap10/soft_uart.c - Demonstrates a software driven UART TX/RX using PIO pins
  - chap10/reverse_string.c - Used in three different projects to illustrate polled UART RX/TX (reverse_string.mcp), interrupt driven RX/polled TX (uartrx_fifo.mcp), interrupt driven RX/TX (uartrxtx_fifo.mcp)
  - chap10/mcp41xxx_spi_pot.c - PIC24 uC in Master mode to Microchip MCP41xxx Digital Potentiometer
  - chap10/ds1722_spi_tempsense.c - PIC24 uC in Master mode to Maxim DS1722 Digital Thermometer using SPI
  - chap10/spi_master_revstring.c, spi_slave_revstring.c - uses SPI for PIC24 uC to PIC24 uC communication, master uses slave to reverse strings.
  - chap10/ds1621_i2c.c - PIC24 uC in Master mode to Maxim DS1621 Digital Thermometer using I2C
  - chap10/ds1631_i2c.c - PIC24 uC in Master mode to Maxim DS1631 Digital Thermometer using I2C
  - chap10/mcp24lc515_i2c_eeprom.c - PIC24 uC in Master mode to Microchip 24LC515 EEPROM using I2C
- Chapter 11: Data Conversion (ADC, DAC) subdirectory

  - chap11/adc2pots1.c - Demonstrates 2-channel manual sampling with the ADC
  - chap11/adc7scan1.c - Samples 7 channels sequentially with automatic channel scanning (only for PIC24 CPUs without DMA).
  - chap11/adc7scan2.c - Above plus uses double buffering (only for PIC24 CPUs without DMA).
  - chap11/adc4simul.c - Simultaneous sampling of 4 channels (only for PIC24 CPUs without DMA).
  - chap11/adc_spidac_test.c - Demonstrates reading the internal ADC in 12-bit mode and then sending the upper 8 bits to an external 8-bit SPI DAC (MAXIM 548A)
- Chapter 12 (Timer coverage - PWM, input capture, output compare, time keeping)

   - chap12/incap_freqmeasure.c - Measures the square wave frequency using input capture and Timer2
   - chap12/incap_switch_pulse_measure.c - Measures the pulse width of pushbutton switching using input capture and Timer2
   - chap12/ir_biphase_decode.c - Decodes bi-phase bitstream from IR remote control as output by an IR receiver. The protocol is Phillips VCR control, 13 bit command (start bit, toggle bit, 5-bit address, 6-bit data). The Timer2 divider must be set such that one bit time does not exceed the timer period.
   - chap12/manual_switch_pulse_measure.c - Measures the pulse width of a pushbutton switch using Timer2 without input capture.
   - chap12/timer32bit_switch_pulse_measure.c - Measures the pulse width of pushbutton switch using Timer2/3 in 32-bit mode with INT1 for edge detection.
   - chap12/outcompare_contpulse.c - Generate an asymmetric square wave using output compare (OC1), continuous pulse mode.
   - chap12/outcompare_squarewave.c - Generate a squarewave using output compare (OC1).
   - chap12/outputcompare_oneservo.c - Demonstrates pulse width modulation using the OC1 output to control a hobby servo. The ADC input value on AN0 is used to vary the pulse width between its min and maximum values.
   - chap12/outputcompare_multiservo.c - Demonstrates pulse width modulation using four digital outputs and the OC1 module to create four PWM outputs for hobby servos. A table is used to control the pulse widths of the four servos.
   - chap12/ledpwm.c - Demonstrates pulse width modulation by controlling the intensity of an LED. The ADC input value on AN0 is used to vary the PWM period.
   - chap12/pwm_dac.c - Demonstrates a PWM DAC - connect an RC filter on the OC1 output and vary the pulse width of the PWM signal, and monitor the DC value on the capacitor. The RC time constant should  be at least 10x greater than the PWM period. Examples values used for testing were R=6.8k, C = 1.0u, PWM period= 500 us.
   - chap12/rtcc.c - Demonstrates the Real Time clock module
- Chapter 13 Advanced topics (DMA, ECAN, I2C slave, flash programming, comparator)

  - chap13/comparator_example.c - Illustrates a simple use of the comparator module
  - chap13/dma_example.c - Uses DMA in ping-pong mode to capture data from the UART, write it to the 24LC515 EEPROM.
  - chap13/ecan_example_nofifo.c - Illustrate CAN transmit, receive. Uses only one buffer for RX receive, and uses a standard data frame.
  - chap13/ecan_example_fifo.c - Illustrate CAN transmit, receive. Uses a FIFO for RX receive, and uses a standard data frame.
  - chap13/ecan_example_fifo_eid.c - Illustrate CAN transmit, receive. Uses a FIFO for RX receive, and uses an extended data frame.
  - chap13/flash_example.c - Illustrates run time self programming of the flash memory
  - chap13/i2c_master_reverse_string.c, chap13/i2c_slave_reverse_string.c - pair of files that shows a PIC24 I2C master talking to a PIC24 I2C slave
  - chap13/i2c_multmaster_rstring.c - Two PIC24 uCs communicate with each other over I2C, acting both as master and slave devices.
- Chapter 14 ESOS examples (also see the \ref ESOS section)

  - chap14/esos_skel.c - basic ESOS template
  - chap14/app_flashled.c - flash an LED
  - chap14/app_echo1.c - ESOS version of the echo.c program
  - chap14/app_reverse.c - demonstrates a user task that reverses a string
  - chap14/app_timerLEDecho.c - flash an LED using a software timer
  - chap14/app_semaphore1.c - demonstrates use of semaphores for signaling synchronization
  - chap14/app_semaphore1.c - demonstrates rendezvous synchronization with semaphores
  - chap14/app_childtask.c - demonstrates child tasks
  - chap14/app_irqs.c - demostrates IRQ handling in ESOS
  - chap14/app_ds1631.c - I2C example using the DS1631
  - chap14/app_ds1722.c - SPI example using the DS1722
- Chapter 15 Capstone examples

  - chap15/audio.c, chap15/audio_adpcm.c - audio record/playback to/from Serial EEPROM with adpcm compression.
  - chap15/reflow_oven.c, chap15/reflow_debug.c, chap15/reflow_flash.c, chap15/reflow_operate.c - Use a toaster oven as a reflow oven, demonstrates AC power control and high temperature monitoring.
  - chap15/robot.c, chap15/robot_ir_decode.c - code for a small three-wheeled robot with IR control and collision avoidance.

- Examples converted to be compatible with the Explorer-16, 100-pin demo board:

  - explorer16_100p/reset.c example (see Chapter 8); Demonstrates software reset, idle, sleep, watchdog timer operation
  - explorer16_100p/lcd4bit.c example (see Chapter 8); Character LCD interface example
  - explorer16_100p/adc_test.c example (see Chapter 11); Demonstrates reading the internal ADC in 10-bit mode and converting it to a voltage.
  - explorer16_100p/timer1_sosc.c example (see Chapter 12); Demonstrates using the secondary oscillator with a 32768 Hz oscillator.
  - explorer16_100p/mcp25lc256_spi_eeprom.c example (see Chapter 10); Demonstrates using the 25lc256 SPI EEPROM on the explorer-16 board. This is not tied to a particular textbook example, but has a similar structure to the Chapter 10 mcp24lc515_i2c_eeprom.c example that uses I2C.

- Other examples not tied to textbook figures:

  - chap11/adc_test.c - Demonstrates reading the internal ADC in 10-bit mode and converting it to a voltage.
  - chap11/adc_test_12bit.c - Demonstrates reading the internal ADC in 12-bit mode and converting it to a voltage.
  - chap11/adc7scan1_dma_scatter_gather_1.c - Samples 7 channels sequentially with automatic channel scanning in scatter/gather mode; uses DMA (only for PIC24 CPUs with DMA) - see the Appendix H online-supplement.
  - chap11/adc7scan1_dma_conv_order.c - Samples 7 channels sequentially with automatic channel scanning in ordered mode; uses DMA (only for PIC24 CPUs with DMA) - see the Appendix H online-supplement.
  - chap11/adc4simul_dma.c - Simultaneous sampling of 4 channels (only for PIC24 CPUs DMA) - see the Appendix H online-supplement.

- Examples using the \ref dataXfer "data transfer protocol": see the data transfer protocol \ref dataXferExamples "example listing".

