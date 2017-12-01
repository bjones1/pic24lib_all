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
# **************
# convert_gld.py
# **************
# Given Microchip's standard GLD files, create GLD files for the bootloader and for programs for use with the bootloader.
#
# The documentation of expected Microchip GLD contents was copied from xc16 v1.30.
#
# Imports
# =======
# These are listed in the order prescribed by `PEP 8
# <http://www.python.org/dev/peps/pep-0008/#imports>`_.
#
# Standard library
# ----------------
import os, sys, string
#
# Third-party imports
# -------------------
# None.
#
# Local application imports
# -------------------------
# None.
#
# Create a GLD file for use with an application using the bootloader.
def makeAppGld(infileName, bootGldName, vectorList, startAddr, family):

    # Open the input file.
    try:
        infile = open(infileName, 'r')
    except:
        print(f"Cannot open file {infileName}")
        sys.exit(-1)

    # Open the output file.
    try:
        outfile = open(bootGldName, 'w')
    except:
        print(f"Cannot open file {bootGldName}")
        sys.exit(-1)
    outfile.write("/* GLD file for PIC24 application using the Bully bootloader. */\n")

    state = 0
    for line in infile.readlines():
        words = line.split()

        # State 0: before the memory section. Simply echo what's read.
        if state == 0:
            outfile.write(line)
            # Look for the line ``MEMORY``, in which the memory regions are defined.
            if len(words) == 1 and words[0] == 'MEMORY':
                state += 1
                continue

        # State 1: in the memory region definition.
        if state == 1:
            # Look for the line (word indexes added above; ``ws`` represents leading whitespace):
            #
            # .. code-block:: none
            #   :linenos:
            #
            #   ws   0      1    2    3   4    5              6   7    8
            #     program (xr)   : ORIGIN = 0x200,         LENGTH = 0x55EC
            #
            # (leading spaced removed; addresses will, of course, vary).
            if len(words) > 3 and words[0] == 'program':
                # Add a section of jump vectors for a remapped IVT, whose size varies for the new E family parts versus the older H/F parts. Note that the starting address begins after the `timeout value`_, which takes 1 word of program memory (2 bytes), hence the - 2 factor below.
                if family == 'PIC24E' or family == 'dsPIC33E':
                    s = '  j_ivt          : ORIGIN = 0x%x,          LENGTH = 0x300\n' % (startAddr - 2)
                    progStart = startAddr + 0x300 - 2
                else:
                    s = '  j_ivt          : ORIGIN = 0x%x,          LENGTH = 0x200\n' % (startAddr - 2)
                    progStart = startAddr + 0x200 - 2
                outfile.write(s)
                # Get the address of the ``ORIGIN``, stripping of the trailing comma and converting to an int.
                origin = words[5]
                origin = origin.replace(',', '')
                origin = int(origin, 16)
                # Get the length of this section as an int.
                length = int(words[8], 16)
                # Compute the change in this section's length: the difference of the new starting location and the old (original) starting location.
                delta = progStart - origin
                newLength = length - delta
                # Adjust this to make room for the bootloader.
                s = '  program (xr)   : ORIGIN = 0x%x,         LENGTH = 0x%x\n' % (progStart, newLength)
                outfile.write(s)
                state += 1
                continue
            else:
                # Echo everything else.
                outfile.write(line)

        # State 2: after the program section is defined.
        if state == 2:
            outfile.write(line)
            # Look for the closing brace of the memory section.
            if len(words) == 1 and words[0] == '}':
                state += 1
                # Write out the addresses for the remapped IVT.
                s = '__JIVT_BASE          = 0x%x;\n' % (startAddr - 2)
                outfile.write(s)
                for vector in vectorList:
                    s = "%s = 0x%x;\n" % ('J' + vector, startAddr)
                    startAddr += 4
                    outfile.write(s)
                continue

        # State 3: until the end of the reset instruction.
        if state == 3:
            outfile.write(line)
            # Look for the line:
            #
            # .. code-block:: none
            #   :linenos:
            #
            #   ws0   1
            #     } >reset
            if len(words) == 2 and words[0] == '}' and words[1] == '>reset':
                state += 1
                continue

        # State 4: until the end of the Interrupt Vector Tables comment.
        if state == 4:
            outfile.write(line)
            # The previous lines:
            #
            # .. code-block:: none
            #   :linenos:
            #
            #   ws 0
            #     /*
            #     ** Interrupt Vector Tables
            #     **
            #     ** The primary and alternate tables are loaded
            #     ** here, between sections .reset and .text.
            #     ** Vector table source code appears below.
            #     */
            if len(words) == 1 and words[0] == '*/':
                state += 1
                # Begin a section containing the _`remapped IVT` (a series of jump, e.g. GOTO statements).
                outfile.write('.j_ivt __JIVT_BASE :\n')
                outfile.write(' {\n')
                # The first word in the IVT is the _`timeout value`.
                outfile.write(' SHORT(0x02);  /* timeout value */\n')
                outfile.write(' SHORT(0x00);\n')
                for vector in vectorList:
                    s = '    SHORT(DEFINED(%s) ? ABSOLUTE(%s) : \n' % (vector, vector)
                    outfile.write(s)
                    outfile.write('     ABSOLUTE(__DefaultInterrupt));\n')
                    outfile.write('     SHORT(0x04);\n')
                    s = '    SHORT(((DEFINED(%s) ? ABSOLUTE(%s) : \n' % (vector, vector)
                    outfile.write(s)
                    outfile.write("     ABSOLUTE(__DefaultInterrupt)) >> 16) & 0x7F);\n")
                    outfile.write('     SHORT(0);\n')
                    outfile.write('\n')
                outfile.write(' } >j_ivt\n')
                continue

        # State 5: until ``#if __XC16_VERSION < 1026``
        if state == 5:
            # Look for a #if that excludes the IVT.
            if line.startswith('#if __XC16_VERSION < 1026'):
                outfile.write('#if 1  /* Always include the IVT. Was: #if __XC16_VERSION < 1026 */\n')
                state += 1
                continue
            outfile.write(line)

        # State 6: until the _`beginning of the IVT`.
        if state == 6:
            outfile.write(line)
            # Replace it with the address of the remapped IVT. The expected line is:
            #
            # .. code-block:: none
            #   :linenos:
            #
            #     0      1      2
            #   .ivt __IVT_BASE :
            if len(words) >= 2 and words[0] == '.ivt':
                state += 1
                outfile.write('{\n')
                for vector in vectorList:
                    s = "LONG(%s);\n" % ('J' + vector)
                    outfile.write(s)
                continue

        # State 7: until the _`end of the IVT`.
        if state == 7:
            # Skip everything until the closing brace.
            # The expected line is:
            #
            # .. code-block:: none
            #   :linenos:
            #
            #   ws0  1
            #     } >ivt
            if len(words) == 2 and words[0] == '}':
                outfile.write(line)
                state += 1
                continue


        # State 8: until the _`beginning of the AIVT`. The process is the same as the IVT. Note that not all chips have this defined.
        if state == 8:
            outfile.write(line)
            if len(words) >= 2 and words[0] == '.aivt':
                state += 1
                outfile.write('{\n')
                for vector in vectorList:
                    s = "LONG(%s);\n" % ('J' + vector)
                    outfile.write(s)
                continue

        # State 9: until the _`end of the AIVT`.
        if state == 9:
            # The expected line is:
            #
            # .. code-block:: none
            #   :linenos:
            #
            #   ws0  1
            #     } >aivt
            if len(words) == 2 and words[0] == '}':
                outfile.write(line)
                state += 1
                continue

        # State 10: until the end of the file. Just echo everything.
        if state == 10:
            outfile.write(line)

    outfile.close()
    infile.close()


def makeBootGld(infileName, bootGldName, vectorList, startAddr, family):

    # Open the input file.
    try:
        infile = open(infileName, 'r')
    except:
        print(f"Cannot open file {infileName}")
        sys.exit(-1)

    # Open the output file.
    try:
        outfile = open(bootGldName, 'w')
    except:
        print(f"Cannot open file {bootGldName}")
        sys.exit(-1)

    outfile.write("/* GLD file for Bully bootloader firmware */\n")

    state = 0
    for line in infile.readlines():
        words = line.split()

        # State 0: before the memory section. Simply echo what's read.
        if state == 0:
            outfile.write(line)
            # Look for the line ``MEMORY``, in which the memory regions are defined.
            if len(words) == 1 and words[0] == 'MEMORY':
                state += 1
                continue

        # State 1: until the end of the memory section. Echo what's read.
        if state == 1:
            outfile.write(line)
            # Look for the closing brace of the memory section.
            if len(words) == 1 and words[0] == '}':
                state += 1

                # Write out the IVT addresses which point to the application's `remapped IVT`_.
                for vector in vectorList:
                    s = "%s = 0x%x;\n" % ('J' + vector, startAddr)
                    startAddr += 4
                    outfile.write(s)
                continue

        # State 2: until ``#if __XC16_VERSION < 1026``
        if state == 2:
            # Look for a #if that excludes the IVT.
            if line.startswith('#if __XC16_VERSION < 1026'):
                outfile.write('#if 1  // Always include the IVT. Was: #if __XC16_VERSION < 1026\n')
                state += 1
                continue
            outfile.write(line)

        # State 3: until the `beginning of the IVT`_ -- see docs there for this state.
        if state == 3:
            outfile.write(line)
            if len(words) >= 2 and words[0] == '.ivt':
                state += 1
                outfile.write('{\n')
                for vector in vectorList:
                    s = "LONG(%s);\n" % ('J' + vector)
                    outfile.write(s)
                continue

        # State 4: until the `end of the IVT`_ -- see docs there for this state.
        if state == 4:
            if len(words) == 2 and words[0] == '}':
                outfile.write(line)
                state += 1
                continue

        # State 5: until the `beginning of the AIVT`_ -- see docs there for this state.
        if state == 5:
            outfile.write(line)
            if len(words) >= 2 and words[0] == '.aivt':
                state += 1
                outfile.write('{\n')
                for vector in vectorList:
                    s = "LONG(%s);\n" % ('J' + vector)
                    outfile.write(s)
                continue

        # State 6: until the `end of the AIVT`_.
        if state == 6:
            if len(words) == 2 and words[0] == '}':
                outfile.write(line)
                state += 1
                continue

        # State 7: until the end of the file. Just echo everything.
        if state == 7:
            outfile.write(line)

    outfile.close()
    infile.close()


def parseGldFile(infileName, bootGldName, appGldName, family):
    # First read all vectors.
    try:
        infile = open(infileName, 'r')
    except:
        print(f"Cannot open file {infileName}")
        sys.exit(-1)

    vectorList = []
    state = 0
    # Set up to replace parentheses with spaces.
    maptable = str.maketrans('()', '  ')
    for line in infile.readlines():
        # Replace parentheses with spaces.
        line = line.translate(maptable)
        words = line.split()

        # State 0: until the `beginning of the IVT`_ -- see docs there.
        if state == 0 and len(words) >= 2:
            if words[0] == '.ivt' and words[1] == '__IVT_BASE':
                state += 1
                continue

        # State 5: until the `beginning of the AIVT`_ -- see docs there for this state.
        if state == 1 and len(words) >= 2:
            # When the AIVT starts, we're done.
            if words[0] == '.aivt':
                break
            # Look for interrupt vectors. The expected line (recall that parents will becomes spaces):
            #
            # .. code-block:: none
            #   :linenos:
            #
            #   ws0      1            2            3    4             5
            #   LONG( DEFINED(__OscillatorFail)    ? ABSOLUTE(__OscillatorFail)    :
            #        ABSOLUTE(__DefaultInterrupt));
            if words[0] == 'LONG' and words[1] == 'DEFINED':
                vectorList.append(words[2])

    infile.close()

    # Now create the bootloader GLD file.
    if (family == 'PIC24E' or family == 'dsPIC33E'):
        startAddr = 0x1002  # this is because of larger erase page size on most PIC24E/PIC33E family members
    else:
        startAddr = 0xC02
    makeBootGld(infileName, bootGldName, vectorList, startAddr, family)
    makeAppGld(infileName, appGldName, vectorList, startAddr, family)

# Convert a directory of GLD files.
def convertDir(srcdir, dstdir, family):
    for infile in os.listdir(srcdir):
        (root, ext) = os.path.splitext(infile)
        if ext == ".gld":
            appfile = root + "_bootldr.gld"
            apppath = os.path.join(dstdir, appfile)
            srcpath = os.path.join(srcdir, infile)
            print(f"Converting: {infile}")
            parseGldFile(srcpath, infile, apppath, family)


xc16_version = 'v1.30'
C30_homedir = r"C:\Program Files (x86)\Microchip\xc16\{}\support".format(xc16_version)

if not os.path.exists(C30_homedir):
    C30_homedir = r"C:\Program Files\Microchip\xc16\{}\support".format(xc16_version)
    if not os.path.exists(C30_homedir):
        print("Cannot determine Microchip xc16 home directory, exiting.\n")
        exit(0)


dstdir = os.path.join("..", "..", "..", "lib", "lkr")

tdir = os.path.join(C30_homedir, "PIC24H", "gld")
convertDir(tdir, dstdir, "PIC24H")

tdir = os.path.join(C30_homedir, "PIC24F", "gld")
convertDir(tdir, dstdir, "PIC24F")

tdir = os.path.join(C30_homedir, "PIC24E", "gld")
convertDir(tdir, dstdir, "PIC24E")

tdir = os.path.join(C30_homedir, "dsPIC33F", "gld")
convertDir(tdir, dstdir, "dsPIC33F")

tdir = os.path.join(C30_homedir, "dsPIC33E", "gld")
convertDir(tdir, dstdir, "dsPIC33E")



#parseGldFile(sys.argv[1])
