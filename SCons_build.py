# Documentation for this file. If the \file tag isn't present,
# this file won't be documented.
## \file
#  Given a build environment, this file performs specific builds
#  using the PIC24 library. It should be called from an SCons script
#  that exports:
#  - env: the build environment to use
#  - buildTargets: a list of strings specifying what to build
#    (see if statements toward the end of this file).
#
#  This file delegates to templates/SConscript.py to build all
#  templates.


import os
Import('buildTargets env bin2hex')

## Inform SCons about the dependencies in the template-based files
SConscript('templates/SConscript.py', 'env')


## @{
#  \name Setup for building files based on the PIC24 support library
###############################################################################


## Common sources used for the PIC24 support library
PIC24SupportLibSources = [
  'lib/common/dataXfer.c',
  'lib/common/dataXferImpl.c',
  'lib/common/pic24_adc.c',
  'lib/common/pic24_clockfreq.c',
  'lib/common/pic24_configbits.c',
  'lib/common/pic24_ecan.c',
  'lib/common/pic24_flash.c',
  'lib/common/pic24_i2c.c',
  'lib/common/pic24_serial.c',
  'lib/common/pic24_spi.c',
  'lib/common/pic24_timer.c',
  'lib/common/pic24_uart.c',
  'lib/common/pic24_util.c' ]



## @}

## @{
#  \name Example code build
###############################################################################

## This function builds a program which includes the PIC24 library.
#  \param sourceFileList A list of source files to be built into one program.
#  \param commonSources  A list of source files upon which all sources
#                        in the sourceFileList depend. Wildcards are not
#                        supported.
#  \param buildEnvinonment An Environment in which to build these sources.
#  \param aliasString    A string to serve as an alias for this build.
def buildProgramWithCommonSources(sourceFileList, commonSources, buildEnvironment,
                                  aliasString):
  be = buildEnvironment
  be.Program(sourceFileList + commonSources)
  # Pick the name of the target to be the first c file in the list
  bin2hex(sourceFileList[0], be, aliasString)

## This function takes a list of source files (including wildcards),
#  adds the PIC24 common
#  sources to each item, then uses Program to build each item.
#  \param sourceFileList A list of source files (which may include
#                        wildcards) to be built.
#  \param commonSources  A list of source files upon which all sources
#                        in the sourceFileList depend. Wildcards are not
#                        supported.
#  \param buildEnvinonment An Environment in which to build these sources.
#  \param exceptionDict A exceptionFileName={key=value pairs used to create the
#                          custom environment correpsonding to the
#                          exceptionFile} dict
#  \param aliasString    A string to serve as an alias for this set of
#                        builds.
def buildWithCommonSources(sourceFileList, commonSources, buildEnvironment,
                           exceptionDict, aliasString):
  for sourceFileGlob in sourceFileList:
    for sourceFile in Glob(sourceFileGlob, True, True, True):
        # See if this is an exception
        if sourceFile in exceptionDict:
          # Yes, so modify environment with dict of changes.
          be = buildEnvironment.Clone()
          flags = exceptionDict[sourceFile]
#          print flags
#          be.MergeFlags(flags) # produces weird
          # errors, so hand-code a simple alternative
          # TODO: This overwrites flags, which is a BAD thing
          for a in flags:
            be[a] = flags[a]
        else:
          # No, just use the existing environment
          be = buildEnvironment
        buildProgramWithCommonSources([sourceFile], commonSources, be,
          aliasString)


## Compile the support library into objects for the default
#  environment.
PIC24SupportLibObjects = env.Object(PIC24SupportLibSources)


if 'reset' in buildTargets:
  buildWithCommonSources(['chap08/reset.c'], PIC24SupportLibObjects, env, {}, 'reset')
if 'chap08' in buildTargets:
  buildWithCommonSources(['chap08/*.c'], PIC24SupportLibObjects, env, {}, 'chap08')
if 'chap09' in buildTargets:
  buildWithCommonSources(['chap09/*.c'], PIC24SupportLibObjects, env, {}, 'chap09')
if 'chap10' in buildTargets:
  buildWithCommonSources([
                          'chap10/mcp24lc515_i2c_eeprom.c',
                          'chap10/reverse_string.c',
                          'chap10/reverse_string1.c',
                          'chap10/soft_uart.c',
                          'chap10/spi_master_revstring.c',
                          'chap10/spi_slave_revstring.c'],
    PIC24SupportLibObjects, env,
    {'chap10\\reverse_string.c'  : { 'CPPDEFINES': 'UART1_RX_INTERRUPT'},
     'chap10\\reverse_string1.c' : { 'CPPDEFINES': ['UART1_RX_INTERRUPT', 'UART1_TX_INTERRUPT']}},
    'chap10')
if 'chap10large' in buildTargets:   # These files usually need a larger device (64K) to compile
  buildWithCommonSources(['chap10/stdio_test.c',
                          'chap10/reverse_string_stdio.c', 'chap10/ds1621_i2c.c', 'chap10/ds1631_i2c.c','chap10/ds1722_spi_tempsense.c',
                          'chap10/mcp41xxx_spi_pot.c',],
    PIC24SupportLibObjects, env, {}, 'chap10stdio')
if 'chap11_24E' in buildTargets:
  buildWithCommonSources([ 'chap11/adc_spidac_test.c',
     'chap11/adc_test.c',
    'chap11/adc_test_12bit.c'], PIC24SupportLibSources, env, {}, 'chap11')
if 'chap11nodma' in buildTargets:
  buildWithCommonSources([ 'chap11/adc2pots1.c','chap11/adc4simul.c','chap11/adc7scan1.c', 'chap11/adc7scan2.c', 'chap11/adc_spidac_test.c',
     'chap11/adc_test.c',
    'chap11/adc_test_12bit.c', 'chap11/dac_r2r.c'], PIC24SupportLibSources, env, {}, 'chap11')
if 'chap11dma' in buildTargets:
  buildWithCommonSources(['chap11/adc4simul_dma.c', 'chap11/adc7scan1_dma_conv_order.c',
    'chap11/adc7scan1_dma_scatter_gather_1.c'],
    PIC24SupportLibObjects, env, {}, 'chap11dma')
if 'chap12_24E' in buildTargets:
  buildWithCommonSources(['chap12/incap_freqmeasure.c','chap12/incap_switch_pulse_measure.c',
  'chap12/ir_biphase_decode.c', 'chap12/manual_switch_pulse_measure.c',
  'chap12/outcompare_contpulse.c', 'chap12/outcompare_squarewave.c',
  'chap12/outputcompare_multiservo.c','chap12/outputcompare_oneservo.c',
  'chap12/pwm_dac.c', 'chap12/pwm_dac_test.c', 'chap12/timer32bit_switch_pulse_measure.c'], PIC24SupportLibSources, env, {}, 'chap12')
if 'chap12' in buildTargets:
  buildWithCommonSources(['chap12/incap_freqmeasure.c','chap12/incap_switch_pulse_measure.c',
  'chap12/ir_biphase_decode.c', 'chap12/ledpwm_pic24f.c', 'chap12/manual_switch_pulse_measure.c',
  'chap12/outcompare_contpulse.c', 'chap12/outcompare_squarewave.c',
  'chap12/outputcompare_multiservo.c','chap12/outputcompare_oneservo.c',
  'chap12/pwm_dac.c', 'chap12/pwm_dac_test.c', 'chap12/timer32bit_switch_pulse_measure.c'], PIC24SupportLibSources, env, {}, 'chap12')
if 'chap12big' in buildTargets:
  buildWithCommonSources(['chap12/ledpwm.c'], PIC24SupportLibSources, env, {}, 'chap12')
if 'chap13' in buildTargets:
  buildWithCommonSources(['chap13/*.c'], PIC24SupportLibObjects, env,
  {'chap13\\i2c_multmaster_rstring.c' :  { 'CPPDEFINES': 'CPU_ID=1' },
   'chap13\\i2c_multmaster_rstring1.c' : { 'CPPDEFINES': 'CPU_ID=2' }},
  'chap13')
if 'chap14' in buildTargets:
  buildWithCommonSources(['chap14/*.c'], PIC24SupportLibObjects, env, {}, 'chap14')
if 'chap15' in buildTargets:
  # Case-by-case, since this chapter's program have multiple source files
  buildProgramWithCommonSources(['chap15/audio.c', 'chap15/audio_adpcm.c', ],
    PIC24SupportLibObjects, env, 'chap15')
  buildProgramWithCommonSources(['chap15/reflow_oven.c', 'chap15/reflow_debug.c',
    'chap15/reflow_flash.c', 'chap15/reflow_operate.c'], PIC24SupportLibObjects,
    env, 'chap15')
  buildProgramWithCommonSources(['chap15/robot.c', 'chap15/robot_ir_decode.c', ],
    PIC24SupportLibObjects, env, 'chap15')
if 'explorerh' in buildTargets:  # Don't build rtcc.c, since the PIC24H doesn't have it
  buildWithCommonSources(['explorer16_100p/adc_test.c', 'explorer16_100p/lcd4bit.c',
    'explorer16_100p/mcp25lc256_spi_eeprom.c', 'explorer16_100p/reset.c',
    'explorer16_100p/timer1_sosc.c'], PIC24SupportLibObjects, env, {}, 'explorerh')
if 'explorer' in buildTargets:
  buildWithCommonSources(['explorer16_100p/*.c'], PIC24SupportLibObjects, env, {}, 'explorer')

## @}
