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
`SCons <http://www.scons.org/>`_ provides automated library building and testing.Capabilities include:

.. toctree::
   :titlesonly:

   runAStyle.bat
   runscons.bat
   SConstruct.py


Code generation tools
=====================
The files below assist in generating and maintaining a mapping between the Rxy pins on a PIC and its associated CNm, ANn pins for many processors.

.. toctree::
   :titlesonly:

   templates/data_sheet_to_csv.py
   templates/compact_csv.py


Testing
=======
The following programs provide some unit testing of various libary-related routines.

.. toctree::
   :titlesonly:

   util/dataXfer_test.c
   util/test_ports.X/test_ports.c
   util/unitTests.c
   util/unittest_rounding.c
