.. "Copyright (c) 2008 Robert B. Reese, Bryan A. Jones, J. W. Bruce ("AUTHORS")"
   All rights reserved.
   (R. Reese, reese_AT_ece.msstate.edu, Mississippi State University)
   (B. A. Jones, bjones_AT_ece.msstate.edu, Mississippi State University)
   (J. W. Bruce, jwbruce_AT_ece.msstate.edu, Mississippi State University)
 
   Permission to use, copy, modify, and distribute this software and its
   documentation for any purpose, without fee, and without written agreement is
   hereby granted, provided that the above copyright notice, the following
   two paragraphs and the authors appear in all copies of this software.
 
   IN NO EVENT SHALL THE "AUTHORS" BE LIABLE TO ANY PARTY FOR
   DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
   OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE "AUTHORS"
   HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
   THE "AUTHORS" SPECIFICALLY DISCLAIMS ANY WARRANTIES,
   INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
   AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
   ON AN "AS IS" BASIS, AND THE "AUTHORS" HAS NO OBLIGATION TO
   PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
 
   Please maintain this header in its entirety when copying/modifying
   these files.
 
 
*********
Utilities
*********
The utilities below provide support for library development and maintenance.

Build tools
===========
`SCons <http://www.scons.org/>`_ provides automated library building and testing. See :doc:`SConstruct.py` for documentation of this process. Capabilities include:

- Automated build of almost all code in the library.
- Automated build of the bootloader over many PICs.
- Automated build of a .zip file and associated documentation.
- Support for multiple copies of a device, such as the UART, I\ :sup:`2`\ C, and SPI, is auto-generated from templates which contain a single copy of the code. The templates/  directory contains the templates from which these files are built.


The code resides in a `Mercurial <http://mercurial.selenic.com/>`_ publicly-readable, web-accessible `repository <http://bitbucket.org/bjones/pic24lib_all>`_. Please send any updates or fixes to the authors for incorporation into the library!

Contents
--------

.. toctree::
   :titlesonly:

   runAStyle.bat
   runscons.bat
   SConstruct.py
   SCons_bootloader.py
   SCons_build.py
   SCons_esos.py
   SCons_zipit.py
   templates/SConscript.py
   
Code generation tools
=====================
The files below assist in generating and maintaining a mapping between the Rxy pins on a PIC and its associated CNm, ANn pins for many processors.

Contents
--------

.. toctree::
   :titlesonly:

   templates/data_sheet_to_csv.py
   templates/compact_csv.py
   templates/build-exe.bat
   templates/data_sheet_to_csv.bat

Testing
=======
The following programs provide some unit testing of various libary-related routines.

Contents
--------

.. toctree::
   :titlesonly:

   util/dataXfer_test.c
   util/test_ports.X/test_ports.c
   util/unitTests.c
   util/unittest_rounding.c
