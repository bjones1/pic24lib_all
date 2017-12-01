# .. "Copyright (c) 2008 Robert B. Reese, Bryan A. Jones, J. W. Bruce ("AUTHORS")"
#    All rights reserved.
#    (R. Reese, reese_AT_ece.msstate.edu, Mississippi State University)
#    (B. A. Jones, bjones_AT_ece.msstate.edu, Mississippi State University)
#    (J. W. Bruce, jwbruce_AT_ece.msstate.edu, Mississippi State University)
#
#    Permission to use, copy, modify, and distribute this software and its
#    documentation for any purpose, without fee, and without written agreement is
#    hereby granted, provided that the above copyright notice, the following
#    two paragraphs and the authors appear in all copies of this software.
#
#    IN NO EVENT SHALL THE "AUTHORS" BE LIABLE TO ANY PARTY FOR
#    DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
#    OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE "AUTHORS"
#    HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
#    THE "AUTHORS" SPECIFICALLY DISCLAIMS ANY WARRANTIES,
#    INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
#    AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
#    ON AN "AS IS" BASIS, AND THE "AUTHORS" HAS NO OBLIGATION TO
#    PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
#
#    Please maintain this header in its entirety when copying/modifying
#    these files.
#
# **************************************************
# SCons_esos.py - Build ESOS chapter 14 applications
# **************************************************
import os
Import('env bin2hex linker_side_effect')

## Inform SCons about the dependencies in the template-based files
SConscript('templates/SConscript.py', 'env')

## Walk through each source file and build it
for sourceFile in Glob('chap14/*.c', True, True, True):
    # Compile the ESOS application.
    p = env.Program(
      [ sourceFile,
        'lib/src/pic24_clockfreq.c',
        'lib/src/pic24_configbits.c',
        'lib/src/pic24_timer.c',
        'lib/src/pic24_util.c',
        'lib/src/pic24_serial.c',
        'lib/src/pic24_uart.c',
        'esos/src/esos.c',
        'esos/src/esos_comm.c',
        'esos/src/esos_cb.c',
        'esos/src/esos_mail.c',
        'esos/src/pic24/esos_pic24_i2c.c',
        'esos/src/pic24/esos_pic24_irq.c',
        'esos/src/pic24/esos_pic24_rs232.c',
        'esos/src/pic24/esos_pic24_spi.c',
        'esos/src/pic24/esos_pic24_tick.c', ])
    linker_side_effect(env, p)
    # Convert it to a .hex
    bin2hex(sourceFile, env, 'esos')
