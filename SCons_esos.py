import os
Import('env bin2hex')

## Inform SCons about the dependencies in the template-based files
SConscript('templates/SConscript.py', 'env')

## Walk through each source file and build it
for sourceFile in Glob('chap14/*.c', True, True, True):
    # Compile the ESOS application.
    env.Program(
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
    # Convert it to a .hex
    bin2hex(sourceFile, env, 'esos')
