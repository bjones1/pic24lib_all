import os
Import('env')

## This functions converts a cof to a hex file.
#  \param cofName The name of the .c or .cof file to be converted (.c files
#    are assumed to be compiled to .cof elsewhere)
#  \param buildEnvinonment An Environment in which to build these sources.
#  \param aliasString A string to serve as an alias for this build.
def cof2hex(cofName, buildEnvironment, aliasString):
  f = os.path.splitext(cofName)[0]
  myHex = buildEnvironment.Hex(f, f)
  # Add this hex file to a convenient alias
  buildEnvironment.Alias(aliasString, myHex)


targetName = '../p${MCU}_bootloader'
env.Program(target = targetName, source = 
  ['bootloader/24h_24f_target/main.c',
   'bootloader/24h_24f_target/mem.c',
   'bootloader/24h_24f_target/pic24_clockfreq.c',
   'bootloader/24h_24f_target/pic24_configbits.c'])
cof2hex(targetName, env, 'bootloader')
