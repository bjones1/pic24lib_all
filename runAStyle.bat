: .. "Copyright (c) 2008 Robert B. Reese, Bryan A. Jones, J. W. Bruce ("AUTHORS")"
:    All rights reserved.
:    (R. Reese, reese_AT_ece.msstate.edu, Mississippi State University)
:    (B. A. Jones, bjones_AT_ece.msstate.edu, Mississippi State University)
:    (J. W. Bruce, jwbruce_AT_ece.msstate.edu, Mississippi State University)
:
:     Permission to use, copy, modify, and distribute this software and its
:     documentation for any purpose, without fee, and without written agreement is
:     hereby granted, provided that the above copyright notice, the following
:     two paragraphs and the authors appear in all copies of this software.
: 
:     IN NO EVENT SHALL THE "AUTHORS" BE LIABLE TO ANY PARTY FOR
:     DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
:     OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE "AUTHORS"
:     HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
: 
:     THE "AUTHORS" SPECIFICALLY DISCLAIMS ANY WARRANTIES,
:     INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
:     AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
:     ON AN "AS IS" BASIS, AND THE "AUTHORS" HAS NO OBLIGATION TO
:     PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS."
: 
:     Please maintain this header in its entirety when copying/modifying
:     these files.
:
: .. highlight:: BatchLexer
:
: *************************************************
: runAStyle.bat - enforce code formatting standards
: *************************************************
: To maintain a consistent style, this batch file runs the `Artistic Style <http://astyle.sourceforge.net/>`_ code formatter on all sources in the library.

bin\astyle --brackets=attach --indent-switches --indent=spaces=2 --recursive --exclude=build --lineend=linux --suffix=none --formatted --convert-tabs *.c *.h
@echo off
: Notes on options (see http://astyle.sourceforge.net/astyle.html for more information):
:
: --brackets=attach, -a    Attach brackets to their pre-block statements (e.g. Java / K&R style).
: --indent-switches, -S   Indent ``switch`` blocks so that the ``case X:`` statements are indented in the switch block. The entire case block is indented.
: --indent=spaces, -s<#>  Indent using # spaces per indent
: --recursive, -r, -R     For each directory in the command line, process all subdirectories recursively.
: --suffix=none, -n       Do not retain a backup of the original file. The original file is purged after it is formatted.
: --lineend=linux         Force use of the specified line end style. Also -z2.
: --formatted, -Q         Formatted files display  mode. Display only the files that have been formatted. Do not display files that are unchanged.
: --convert-tabs, -c      Converts tabs into spaces in the non-indentation part of the line. 
: