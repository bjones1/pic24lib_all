# .. "Copyright (c) 2017 Robert B. Reese, Bryan A. Jones, J. W. Bruce ("AUTHORS")"
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
# ************************************************
# SConscript.py - Build source files from template
# ************************************************
# Note the .py extension on this file, necessary so that
# Doxygen parses as a Python script (but not necessary
# for SCons).
#
# This file builds various files from templates in the
# templates/ directory in which this file resides. It should
# be called from the main SConscript.py script.
#
#
# Setup for template building
# ===========================

import os
from string import Template
import csv
import re

from compact_csv import enumeratePic24Ports

# Import environment from calling SConstruct context
Import('env')


# Functions supporting template file builds
# =========================================

# A function to do search and replaces on a file, optionally
#  appending the results to the output file.
def searchAndReplace(
# Name of the source file
  sourceFile,
# Name of the destination file
  destFileName,
# A dictionary of key=value pairs used by
# template to perform the search and replace operation.
  mapping,
#  Mode with which to open the destination file.
#  Use the default of 'w' to overwrite the
#  destination file with the replaced source file. Use 'a' to
#  append the replaced source file to the destination file.
 openMode='w'):

  # Use newline='' to preserve current line endings; in particular, this
  # keeps line endings Unix-style, even when run under Windows.
  with open(destFileName, openMode, encoding='utf-8', newline='') as outFile:
    template = Template(open(sourceFile).read())
    outFile.write(template.substitute(mapping))

# A function to create a .c/.h file from multiple replaces through
#  a template.
def genFromTemplate(
# Name of the template file to use
  templateFileName,
# Name of the destination file to create
# by accumulating multiple passes through the template
# file
  destFileName,
# Number of iterations (passes) through the file
# to make. During each iteration, $x is replaced by the
# iteration number.
  iters):

  openMode = 'w'
  for i in range(1, iters + 1):
    searchAndReplace(templateFileName, destFileName,
      {'x' : str(i)}, openMode)
    openMode = 'a'

# Builds a .c from a template -- SCons Builder function formation.
# Function will build the .c as requested.  Has the proper
# inputs, outputs and returns value to be registered SCons environment
# as a builder function
def c_template_builder(
# Target file for this function to build
  target,
# File on which target is built from
  source,
# Environment (if needed)
  env):

  s=str(source[0])
  t=str(target[0])
  f=os.path.split(str(target[0]))[-1]
  g=os.path.splitext(f)[0]
  if (g == "pic24_uart"):
    genFromTemplate(s, t, 4)
  if (g == "pic24_i2c"):
    genFromTemplate(s, t, 2)
  if (g == "pic24_ecan"):
    genFromTemplate(s, t, 2)
  if (g == "pic24_spi"):
    genFromTemplate(s, t, 2)

# This routine builds a pic24_ports_config.h file from its template. To do so:
#
# #. Open the output and template files.
# #. Write the header.
# #. For each port/pin, write a replaced template.
def genConfigFromTemplate(templateFileName, destFileName):
  # Read in the template.
  with open(templateFileName, "r", encoding='utf-8', newline='') as templateFile:
    template = Template(templateFile.read())
  # Open the output file.
  with open(destFileName, "w", encoding='utf-8', newline='') as outFile:
    # Write the header
    outFile.write(c_license_header)
    outFile.write('/// \\brief Define GPIO configuration macros for all pins of a device.\n' +
                  '/// See pic24_ports.h for more details.\n\n\n');

    # Iterate over every port
    portlist = enumeratePic24Ports()
    # Add in some extra ports for unit testing
    portlist.extend(['T1', 'T2', 'T3'])
    for Rxy in portlist:
      # Evaluate the template for this port/pin.
      outFile.write(template.substitute({'x' : Rxy}))

# This helper routine splits a string containing a space-separated list of processors into a list. The last element of the list gives the port, which is returned separately.
#
# An asterisk (*) after a processor name is removed; this makes it easier to mark which csv entries have been hand-checked.
def splitProcessorNames(port_dict):
  processors = re.split('\*? ', port_dict['Device port / pin'])
  port = processors.pop()
  return processors, port


# This routine builds pic24_ports_tables.h from a template. To do so:
#
# #. Open the output file and write out the header.
# #. Load in the CSV file containing pin information:
#
#    #. Load three rows; they should be labeled xxx RPy, xxx ANn, and xxx CNm, where xxx is the processor.
#    #. For each Rxy value:
#
#       #. For F/H devices: look at the corresponding RPy, ANn, and CNm. If any are non-empty, write a table entry.
#       #. For E devices: Write a #define for RPy or ANn if either are non-empty.
# #. Write out the footer.
def genTablesFromTemplate(csvFileName, destFileName):
  portlist = enumeratePic24Ports()
  # Read in the CSV containing device information.
  with open(csvFileName, "r", encoding='utf-8') as csvFile:
    csv_dict_reader = csv.DictReader(csvFile).__iter__()
    # Open the output file.
    with open(destFileName, "w", encoding='utf-8', newline='') as outFile:
      # Write the header
      outFile.write(c_license_header)
      outFile.write('/// \\brief Define device-specific mappings from Rxy to RPy, ANn, and CNm pins.\n\n#if 0\n')
      # Walk through the file
      while True:
          # Read three rows
          try:
              RPy = csv_dict_reader.__next__()
              ANn = csv_dict_reader.__next__()
              CNm = csv_dict_reader.__next__()
          except StopIteration:
              break
          # Gather processor information. Make sure all three rows refer to the same processors and to the expected ports.
          processors, port = splitProcessorNames(RPy)
          assert port == 'RPy'
          # Check: all processors in this group should be unique.
          if len(processors) > len(set(processors)):
              print(" ".join(processors) + " contains duplicates.")
              assert False
          processors_temp, port = splitProcessorNames(ANn)
          assert processors == processors_temp
          assert port == 'ANn'
          processors_temp, port = splitProcessorNames(CNm)
          assert processors == processors_temp
          assert port == 'CNm'
          # Write out processor information.
          outFile.write('\n#elif defined(__' + '__) || \\\n      defined(__'.join(processors) + '__)\n')
          # Walk through each Rxy on this processor
          for Rxy in portlist:
              # Get the specific values for this Rxy.
              _RPy = RPy[Rxy]
              _ANn = ANn[Rxy]
              _CNm = CNm[Rxy]
              if _RPy:
                  outFile.write('# define R%s_RP %s\n' % (Rxy, _RPy))
              if _ANn:
                  outFile.write('# define R%s_AN %s\n' % (Rxy, _ANn))
              if _CNm:
                  outFile.write('# define R%s_CN %s\n' % (Rxy, _CNm))
      # Write footer
      outFile.write('#else\n# error "Port information not defined."\n#endif\n')

# Builds a .h from a .csv -- SCons Builder function formation.
# Has the proper
# inputs, outputs and returns value to be registered SCons environment as a builder function.
def csv_template_builder(
#  Target file for this function to build
  target,
#  File on which target is built from
  source,
#  Environment (if needed)
  env):

  s=str(source[0])
  t=str(target[0])
  f=os.path.split(str(target[0]))[-1]
  g=os.path.splitext(f)[0]
  genTablesFromTemplate(s, t)

# Builds a .h from a template -- SCons Builder function formation.
# Function will build the .c as requested.  Has the proper
# inputs, outputs and returns value to be registered SCons environment
# as a builder function
def h_template_builder(
# Target file for this function to build
  target,
# File on which target is built from
  source,
# Environment (if needed)
  env):

  s=str(source[0])
  t=str(target[0])
  f=os.path.split(str(target[0]))[-1]
  g=os.path.splitext(f)[0]
  if (g == "pic24_uart"):
    genFromTemplate(s, t, 4)
  if (g == "pic24_i2c"):
    genFromTemplate(s, t, 2)
  if (g == "pic24_ecan"):
    genFromTemplate(s, t, 2)
  if (g == "pic24_ports_config"):
    genConfigFromTemplate(s, t)

# Define and register a template-driven builder for .c files
cbldr = Builder(action = c_template_builder, suffix='.c', src_suffix='.c-template')
env.Append(BUILDERS = {'CTemplate' : cbldr})

# Define and register a template-driven builder for .h files
hbldr = Builder(action = h_template_builder, suffix='.h', src_suffix='.h-template')
env.Append(BUILDERS = {'HTemplate' : hbldr})

# Define and register a CVS-driven builder for .csv files
csvbldr = Builder(action = csv_template_builder, suffix='.h', src_suffix='.csv')
env.Append(BUILDERS = {'CSVTemplate' : csvbldr})



# Calls to build templates
# ========================

# Specify which files are produced by templates
env.HTemplate('../lib/include/pic24_uart','pic24_uart')
env.HTemplate('../lib/include/pic24_i2c','pic24_i2c')
env.HTemplate('../lib/include/pic24_ecan','pic24_ecan')
env.HTemplate('../lib/include/pic24_ports_config','pic24_ports_config')
env.CSVTemplate('../lib/include/pic24_ports_mapping','pic24_devices')
env.CTemplate('../lib/src/pic24_uart','pic24_uart')
env.CTemplate('../lib/src/pic24_i2c','pic24_i2c')
env.CTemplate('../lib/src/pic24_ecan','pic24_ecan')
env.CTemplate('../lib/src/pic24_spi','pic24_spi')

env.Alias('template-build', ['../lib/include/pic24_uart.h',
                             '../lib/include/pic24_i2c.h',
                             '../lib/include/pic24_ecan.h',
                             '../lib/include/pic24_ports_config.h',
                             '../lib/include/pic24_ports_mapping.h',
                             '../lib/src/pic24_uart.c',
                             '../lib/src/pic24_i2c.c',
                             '../lib/src/pic24_spi.c',
                             '../lib/src/pic24_ecan.c']);




# Header, containing the license as a C comment.
c_license_header = """/*
 * "Copyright (c) 2017 Robert B. Reese, Bryan A. Jones, J. W. Bruce ("AUTHORS")"
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

/// \\file
"""
