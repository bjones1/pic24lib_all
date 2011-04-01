/*
 * "Copyright (c) 2008 Robert B. Reese, Bryan A. Jones, J. W. Bruce ("AUTHORS")"
 * All rights reserved.
 * (R. Reese, reese_AT_ece.msstate.edu, Mississippi State University)
 * (B. A. Jones, bjones_AT_ece.msstate.edu, Mississippi State University)
 * (J. W. Bruce, jwbruce_AT_ece.msstate.edu, Mississippi State University)
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement is
 * hereby granted, provided that the above copyright notice, the following
 * two paragraphs and the authors appear in all copies of this software.
 *
 * IN NO EVENT SHALL THE "AUTHORS" BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
 * OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE "AUTHORS"
 * HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * THE "AUTHORS" SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE "AUTHORS" HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
 *
 * Please maintain this header in its entirety when copying/modifying
 * these files.
 *
 *
 */

/* Documentation placed on the main page. This file only
   include comments for Doxygen; it does not contain any
   code.

   NOTE: This page must be manually synchronized with
   http://www.reesemicro.com/Home/pic24-software-library-collection.
   Make sure any edits there are reflected here and vice versa!
*/



/**
 * \mainpage
 * The latest version of this document is located
 * <a href="http://www.reesemicro.com/Home/pic24-software-library-collection">here</a>.
 *
 * \section internalWelcome PIC24 library collection
 Welcome to the PIC24 library collection! This \ref PIC24_support "library"
 (the latest version is
 <a href="http://www.ece.msstate.edu/courses/ece3724/main_pic24/labs/files/pic24_code_examples.zip">here</a>),
 accompanied by detailed explanations in the
 <a href="http://www.reesemicro.com/Home/textbook">textbook</a>,
 supplemented with numerous real-world \ref textbookExamples "examples", and
 accompanied by extensive on-line documentation given below,
 enable developers to take advantage of the wide range of peripherals offered by the PIC24.
 The collection consists of the
 <a href="http://www.reesemicro.com/Home/pic24-software-library-collection/getting-started">getting
 started guide</a>; the \ref PIC24_support "PIC24 support library"; and
 \ref ESOS, the Embedded Systems Operating System.

 * \section internalStarted Getting started
The
<a href="http://www.reesemicro.com/Home/pic24-software-library-collection/getting-started">getting
started</a> page walks newcomers through the first step in developing for the PIC24:
installing software and obtaining necessary hardware. Next, \ref textbookExamples "examples" introduce use of the libraries below.
Finally, documentation below provides a detailed reference to each of the library's operation.

* \section internalSupport PIC24 support library

The \ref PIC24_support "PIC24 support library" supports all the major subsystems of the PIC24:
clock configuration, configuration bits, delays, interrupts,
digital I/O, timers, serial I/O, SPI, I2C, ECAN, comparators, A/D conversion, FLASH reads/writes, and DMA.
An extensive set of \ref textbookExamples "examples" accompanying the library provide working sample code to guide newcomers to using the library.

* \section internalESOS ESOS
\ref ESOS, the Embedded Systems Operating System, is a cooperative multitasking operating system with
very low memory overhead. ESOS is a task-driven programming paradigm within an event-driven framework.
ESOS gives the user timer, interrupt, and communication services commonly needed in embedded systems programs.

\section bootloader PIC24 Bootloader
The PIC24 Bully Bootloader is a serial bootloader for the PIC24H/F processors;
it includes both firmware and a PC GUI in the files accompanying this archive.
Additional documentation can be found here
(<a href="http://www.reesemicro.com/Home/pic24-software-library-collection/pic24-bully-bootloader">HTML</a>)
and here
(<a href="manuallyCreated/PIC24_bully_bootloader.pdf">PDF</a>).
After unpacking the code archive, the bootloader executable is named
<code>bin/winbootldr.exe</code>, source is in the <code>bootloader/24h_24_target</code> directories,
and pre-compiled bootloader hex files are in the <code>hex/</code> directory.
The Bully Bootloader is named after the Mississippi State mascot ("Bully", a bulldog).

* \section internalMoredoc Additional documentation
Additional documentation is available for:
* - <a href="manuallyCreated/PIC24_bully_bootloader.pdf">Bully Bootloader firmware and GUI documentation.</a>
* - <a href="manuallyCreated/board_walkthru_pic24.pdf">A prototyping walk-through for the PIC24HJ32GP202 reference system of Chapter 8</a>
* - <a href="manuallyCreated/Sparkfun_minibully.pdf">Using the Sparkfun 'mini-Bully' breakout board with the code examples</a>
* - <a href="manuallyCreated/Appendix_H_ADC_with_DMA.pdf">A textbook supplement that discusses using the DMA module with the ADC</a>
*
* \section internalLicense License
* These libraries are released under terms given in the \ref License "license".
*/
