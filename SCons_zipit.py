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
# ***************************************************************
# SCons_zipit.py - Build docs then create a .zip for distribution
# ***************************************************************
# Bring in path for SCons use.
import os
env = Environment(ENV = {'PATH' : os.environ['PATH']})

# Update docs.
env.Execute('doxygen')

# Copy updated CodeChat docs into Doxygen output.
env.Execute('sphinx-build -d _build\\doctrees . _build\\html')
env.Execute(Delete('docs/sphinx', must_exist = 0))
env.Execute(Copy('docs/sphinx', '_build/html'))


# Define a single target to build the zip file.
zip_file = '../pic24_code_examples.zip'
env.Default(env.Zip(zip_file, [
  'readme.txt',
  'standard_header.txt',
  'bin',
  'bootloader',
  'docs',
  'hex',
  'chap03',
  'chap04',
  'chap06',
  'chap07',
  'chap08',
  'chap09',
  'chap10',
  'chap11',
  'chap12',
  'chap13',
  'chap14',
  'esos',
  'lib/lkr',
  'lib/src',
  'lib/include',
  'explorer16_100p',
  'util' ]))
