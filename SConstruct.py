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
# ****************************************************************
# SConstruct.py - Build all libraries and examples over many chips
# ****************************************************************
# This file contains all that a SConstruct file normally contains.
# In order to use CodeChat, however, all Python files must end with
# a ``.py`` extension. So, SConstuct simply executes this file.
#
#  This file provides an automated build process for the
#  \ref index "libraries" included in this collection.
#  To use:
#
#  #. Install SCons.
#  #. Install the Microchip compiler. Make sure your path
#     includes the directories in which the compiler binaries
#     exist.
#  #. From the command line, change to the directory in which
#     this file lies.
#  #. Execute ``SCons``, which builds everything. Optionally use :doc:`runscons.bat <runscons.bat>` to filter through the resulting warnings.
#
#  The build process can be modified by passing options to
#  SCons. See ``SCons --help`` for options specific
#  to this build and ``SCons -H`` for generic SCons
#  options.
#
#  To do:
#
#  - Some flags for I2C master/slave not done yet
#  - Create some reset replacement that uses more of the functionality
#    (calls functions from all our .c/.h files


import os
import psutil

# Make sure SCons is recent enough.
EnsureSConsVersion(2, 0)


# Create a Microchip XC16 Construction Environment
# ================================================

# Define command-line options to set processor, bootloader
opts = Variables()
opts.Add(EnumVariable('BOOTLDR', 'Determines bootloader type', 'msu',
                    allowed_values=('msu', 'none')))

env = Environment(
        # Force SCons to set up with gnu tools to start
        # with reasonable defaults. Note: using platform = 'posix'
        # causes SCons to try to call fork() when executing programs
        # (such as compilers), which errors out on Windows.
        tools = ['gcc', 'gnulink', 'ar', 'zip', 'packaging'],
        options = opts,
        CPPPATH = 'lib/include',
        CC = 'xc16-gcc',
        LIBPATH = '.',
        AR = 'xc16-ar',
        LINK = 'xc16-gcc',
        # Copied and cobbled together from SCons\Tools\cc.py with mods
        CCCOM = '$CC -c -o $TARGET $CFLAGS $CCFLAGS $CPPFLAGS $_CPPDEFFLAGS $_CPPINCFLAGS $SOURCES',
        CCCCOMSTR = 'Compiling $SOURCES',
        # The warnings provide some lint-like checking. Omitted options: -Wstrict-prototypes -Wold-style-definition complains about void foo(), which should be void foo(void), but isn't worth the work to change.
        CCFLAGS = '-mcpu=${MCU} -O1 -msmart-io=1 -omf=elf -Wall -Wextra -Wdeclaration-after-statement -Wlong-long -fdiagnostics-show-option',
        LINKFLAGS = '-mcpu=${MCU} -omf=elf -Wl,--heap=100,$LINKERSCRIPT,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,--no-cpp',
        LINKERSCRIPT = '--script="lib/lkr/p${MCU}_bootldr.gld"',
        ARFLAGS = 'rcs',
        ARSTR = 'Create static library: $TARGET',
        OBJSUFFIX = '.o',
        PROGSUFFIX = '.elf',
        # Copy the host envrionment variables for our scons environment
        # so scons can find the build tools and related env vars.
        ENV = os.environ,
      )

#
# add the bin2hex program to the environment as a new builder
#
b2h = Builder(
        action = 'xc16-bin2hex $SOURCE -a -omf=elf',
        suffix = 'hex',
        src_suffix = 'elf')
env.Append(BUILDERS = {'Hex' : b2h})

# This functions converts a binary (.elf or .cof) file to a hex file.
#  \param binName The name of the .elf/.cof file to be converted
#  \param buildEnvinonment An Environment in which to build these sources.
#  \param aliasString A string to serve as an alias for this build.
def bin2hex(binName, buildEnvironment, aliasString):
  f = os.path.splitext(binName)[0]
  myHex = buildEnvironment.Hex(f, f)
  # Add this hex file to a convenient alias
  buildEnvironment.Alias(aliasString, myHex)

# adjust our default environment based on user command-line requests
dict = env.Dictionary()
if dict['BOOTLDR'] != 'msu':
    env.Replace(LINKERSCRIPT = '--script="p${MCU}.gld"')

# By default, run number_of_cpus*2 jobs at once. This only works if the --no-cpp option is passed to the linker; otherwise, the linker produces a temporary file in the root build directory, which gets overwritten and confused when multiple builds run. There's some nice examples and explanation for tihs in the `SCons user guide <http://www.scons.org/doc/production/HTML/scons-user/c2092.html#AEN2183>`_.
#
# Some results from running on my 8-core PC:, gathered from the Total build time returned by the --debug=time scons command-line option:
#
# ==  ==========  ===============  ============
# -j  Time (sec)  Time (hh:mm:ss)  Speedup
# ==  ==========  ===============  ============
# 32   303        0:05:03          11.66006601
# 16   348.7      0:05:49          10.13191855
#  8   510.9      0:08:31           6.915247602
#  4   916        0:15:16           3.8569869
#  2  1777        0:29:37           1.98818233
#  1  3533        0:58:53           1
# ==  ==========  ===============  ============

env.SetOption('num_jobs', psutil.NUM_CPUS*4)
print("Running with -j %d." % GetOption('num_jobs'))

# generate some command line help for our custom options
Help(opts.GenerateHelpText(env))
Help("""Additional targets:
  template-build: Build all .c/.h files which are produced by templates.
  zipit: Build an archive for distributing end-user library contents.
  bootloader: Build the bootloader binaries only.""")

#
# A DEBUG STATEMENT to see what the scons build envrionment (env) has defined
#
#print   env.Dump()

## @}



# Definition of targets
# =====================
# First, set up for defining targets.
#
# Inform SCons about the dependencies in the template-based files
SConscript('templates/SConscript.py', 'env')

## Create a target which zips up library files. Only built it if explicitly requested on the command line.
if 'zipit' in COMMAND_LINE_TARGETS:
    zip_file = 'build/pic24_code_examples.zip'
    hg_dir = 'build/pic24lib_all'
    env.Command(zip_file, '', [
      # Clone the repo to create a clean distribution.
      Delete(hg_dir, must_exist = 0),
      'hg clone . ' + hg_dir,
      # Copy over hex files from the build.
      Copy(hg_dir + '/hex', 'hex'),
      # Perform zip in clean clone.
      'scons -C ' + hg_dir + ' -f SCons_zipit.py', ])
    env.Alias('zipit', zip_file)
# Only build this if it's explicitly requested. Since the dependencies of '' are wrong, force a build using AlwaysBuild.
    env.AlwaysBuild(zip_file)

# PIC24/dsPIC33 chip/clock variant builds
# ---------------------------------------
# Call SConscript with a specific buildTargets value
def buildTargetsSConscript(buildTargets, env, hardware_platform, extra_defines = ''):
  # Build a variant directory name, based on the hardware platform, MCU, and extra defines (if any)
  vdir = 'build/' + '_'.join([hardware_platform, env['MCU']])
  if extra_defines:
    vdir += '_' + extra_defines
  SConscript('SCons_build.py', exports = 'buildTargets env bin2hex',
    variant_dir = vdir)

# Build small, non-DMA on the PIC24HJ32GP202
buildTargetsSConscript(['chap08', 'chap09', 'chap10', 'chap11nodma', 'chap12'],
env.Clone(MCU='24HJ32GP202'), 'default')

# Build the large files on the PIC24HJ64GP202
buildTargetsSConscript(                            ['chap10large', ],
  env.Clone(MCU='24HJ64GP202'), 'default')

# Build everything on the PIC24FJ64GA002
buildTargetsSConscript(['chap08', 'chap09', 'chap10', 'chap10large', 'chap11nodma', 'chap12',
                        'chap15'],
  env.Clone(MCU='24FJ64GA002'), 'default')

# Build small, non-DMA on the dsPIC33FJ32GP202
buildTargetsSConscript(['chap08', 'chap09', 'chap10',                'chap11nodma', 'chap12'],
  env.Clone(MCU='33FJ32GP202'), 'default')

# Build the large files on the dsPIC33FJ64GP202
buildTargetsSConscript(                            ['chap10large'],
  env.Clone(MCU='33FJ64GP202'), 'default')

# Minimally test the 24F16KA102. It has hardmapped UART pins.
buildTargetsSConscript(['reset', 'echo'],
  env.Clone(MCU='24F32KA302', CPPDEFINES='HARDWARE_PLATFORM=HARDMAPPED_UART'), 'default')

# Build the PIC24HJGP502-compatible directories
buildTargetsSConscript(['chap11dma', 'chap13', 'chap15'],
  env.Clone(MCU='24HJ64GP502'), 'default')

# Same as above, but for the dsPIC
buildTargetsSConscript(['chap08', 'chap09', 'chap10', 'chap10stdio', 'chap11dma',  'chap12big','chap12',
                        'chap13', 'chap15'],
  env.Clone(MCU='33FJ128GP802'), 'default')

# Same as above, but for the dsPIC33EP128GP502
buildTargetsSConscript(['chap08', 'chap09', 'chap10', 'chap12',
                        'chap13', 'chap15'],
  env.Clone(MCU='33EP128GP502'), 'default')

# Same as above, but for the dsPIC33EP128GP502 on a MicroStickII target
buildTargetsSConscript(['chap08', 'chap09', 'chap10', 'chap12',
                        'chap13', 'chap15'],
  env.Clone(MCU='33EP128GP502', CPPDEFINES='HARDWARE_PLATFORM=MICROSTICK2'), 'MICROSTICK2')

# Build some for the PIC24E device
buildTargetsSConscript(['chap08', 'chap09', 'chap10', 'chap11_24E',  'chap12big', 'chap12_24E'],
  env.Clone(MCU='24EP64GP202'), 'default')

# Build some for the CAN2 rev.C1 board used in ECE4723 Embedded Systems
buildTargetsSConscript(['embeddedC1'],
  env.Clone(MCU='33EP128GP504', CPPDEFINES='HARDWARE_PLATFORM=EMBEDDED_C1'), 'EMBEDDED_C1')

# Build for the explorer board
buildTargetsSConscript(['explorer'],
  env.Clone(MCU='24FJ128GA010', CPPDEFINES='HARDWARE_PLATFORM=EXPLORER16_100P'), 'EXPLORER16_100P')
buildTargetsSConscript(['explorerh'],
  env.Clone(MCU='24HJ256GP610', CPPDEFINES='HARDWARE_PLATFORM=EXPLORER16_100P'), 'EXPLORER16_100P')

# Do a no-float build of reset
buildTargetsSConscript(['reset'],
  env.Clone(MCU='24HJ32GP202',  CPPDEFINES='_NOFLOAT'), 'default', 'nofloat')

# Build reset on other supported platforms
buildTargetsSConscript(['reset'],
  env.Clone(MCU='24FJ64GA002',  CPPDEFINES='HARDWARE_PLATFORM=STARTER_BOARD_28P'), 'starter_board_28p')
buildTargetsSConscript(['reset'],
  env.Clone(MCU='33FJ128GP204', CPPDEFINES='HARDWARE_PLATFORM=DANGEROUS_WEB'), 'dangerous_web')

# Build reset with various clock options on all processors
for clock in ['SIM_CLOCK', 'FRCPLL_FCY16MHz', 'FRC_FCY4MHz',
'PRI_NO_PLL_7372KHzCrystal', 'PRIPLL_8MHzCrystal_16MHzFCY']:
    buildTargetsSConscript(['reset'],
      env.Clone(MCU='24FJ64GA002', CPPDEFINES='CLOCK_CONFIG=' + clock), 'default', clock)
    buildTargetsSConscript(['reset'],
      env.Clone(MCU='24FJ64GA102', CPPDEFINES='CLOCK_CONFIG=' + clock), 'default', clock)
    buildTargetsSConscript(['reset'],
      env.Clone(MCU='24F32KA302', CPPDEFINES=['CLOCK_CONFIG=' + clock, 'HARDWARE_PLATFORM=HARDMAPPED_UART']), 'HARDMAPPED_UART', clock)
for clock in ['SIM_CLOCK', 'PRI_NO_PLL_7372KHzCrystal', 'FRC_FCY3685KHz',
'FRCPLL_FCY40MHz', 'PRIPLL_7372KHzCrystal_40MHzFCY', 'PRIPLL_8MHzCrystal_40MHzFCY']:
    buildTargetsSConscript(['reset'],
      env.Clone(MCU='24HJ32GP202',  CPPDEFINES='CLOCK_CONFIG=' + clock), 'default', clock)
    buildTargetsSConscript(['reset'],
      env.Clone(MCU='33FJ128GP802', CPPDEFINES='CLOCK_CONFIG=' + clock), 'default', clock)


# Bootloader targets
# ------------------
def buildTargetsBootloader(env, mcu):
    # Create an environment for building the bootloader:
    # 1. Define the MCU.
    env = env.Clone(MCU = mcu)
    # 2. Use the custom bootloader linker script.
    env.Replace(
        LINKERSCRIPT = '--script=bootloader/pic24_dspic33_bootloader.X/lkr/p${MCU}.gld',
    )
    env.Append(CPPDEFINES = ['BOOTLOADER'])

    # Now, invoke a variant build using this environment.
    SConscript('SCons_bootloader.py', exports = 'env bin2hex',
      variant_dir = 'build/default_bootloader_' + mcu)

for mcu in ('24FJ32GA002',
            '24FJ64GA002',
            '24FJ32GA102',
            '24FJ64GA102',
            '24FJ64GB002',
            '24FJ64GB004',
            
            '24HJ12GP202',
            '24HJ32GP202',
            '24HJ64GP502',
            '24HJ128GP502',

            '24EP64GP202',

            '33FJ32GP202',
            '33FJ128GP802',

            '33EP128GP502',
            '33EP128GP504',
           ):
    buildTargetsBootloader(env, mcu)
    
for mcu in ('24F32KA302',):
    buildTargetsBootloader(env.Clone(CPPDEFINES='HARDWARE_PLATFORM=HARDMAPPED_UART'), mcu)
    



# ESOS builds
# -----------
def buildTargetsEsos(env, mcu, hardware_platform = 'DEFAULT_DESIGN'):
    # Create an environment for building ESOS.
    env = env.Clone(MCU = mcu)
    env.Append(CPPDEFINES = ['BUILT_ON_ESOS', 'HARDWARE_PLATFORM=' + hardware_platform],
               CPPPATH = ['esos/include', 'esos/include/pic24']) 

    # Now, invoke a variant build using this environment.
    SConscript('SCons_esos.py', exports = 'env bin2hex',
      variant_dir = 'build/esos_' + mcu + '_' + hardware_platform)
      
# Build ESOS over a variety of chips.
for mcu in (
            '24HJ64GP202',
            '24FJ64GA002',
            '24HJ128GP502',
            '24EP64GP202',
            '33FJ64GP202',
            '33FJ128GP802',
            '33EP128GP502',
            '33EP128GP504',
           ):
    buildTargetsEsos(env, mcu)
buildTargetsEsos(env, '33EP128GP504', 'EMBEDDED_C1')
buildTargetsEsos(env, '33EP128GP502')
buildTargetsEsos(env, '33EP128GP502', 'MICROSTICK2')
