import os
Import('env bin2hex')

## Inform SCons about the dependencies in the template-based files
SConscript('templates/SConscript.py', 'env')

targetName = 'p${MCU}_bootloader'
# Compile the bootloader to a .cof file.
env.Program(target = targetName, source =
  ['bootloader/pic24_dspic33_bootloader.X/main.c',
   'bootloader/pic24_dspic33_bootloader.X/mem.c',
   'bootloader/pic24_dspic33_bootloader.X/pic24_uart-small.c',
   'lib/src/pic24_clockfreq.c',
   'lib/src/pic24_uart.c',
   'lib/src/pic24_configbits.c'])
# Convert it to a .hex
bin2hex(targetName, env, 'bootloader')
# Copy the .hex to the hex/ directory.
env.Command('../../hex/' + targetName + '.hex', targetName + '.hex', Copy("$TARGET", "$SOURCE"))
