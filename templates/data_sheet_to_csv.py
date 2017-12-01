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
# *****************************************************************************************
# data_sheet_to_csv.py - GUI to assist in translating Microchip data sheets to pin mappings
# *****************************************************************************************
# This program accepts text copied and pasted from a Microchip data sheet (in
# PDF format) of the pinout for a given package, then translates it into an
# Rxy/RPy/ANn/CNm mapping.
#
# To build as an executable::
#
#   pyinstaller data_sheet_to_csv.py -y

import re
import sys
import csv
import os

# The excellent `PyQt5 library <http://pyqt.sourceforge.net/Docs/PyQt5/>`_ provides the GUI for this package.
from PyQt5 import QtWidgets, QtGui, QtCore, uic

from compact_csv import enumeratePic24Ports


def text_pinout_to_mapping(text):
    pins = text.split()
    RPy = {}
    ANn = {}
    CNm = {}
    last_failure = ''
    last_pin = ''
    for pin in pins:
        # Look for Rxy. If not found, we can't do anything with this pin.
        mo = re.search('R([A-K]\d\d?)', pin)
        if mo:
            Rxy = mo.group(1)
        else:
            # No Rxy pin here, so we can't map. Do error checking anyway.
            Rxy = ''

        # Look for RPy.
        mo = re.search('RPI?(\d\d?\d?)', pin)
        if mo:
            if not Rxy:
                last_failure = 'Warning: found RPy without finding Rxy in ' + pin
                last_pin = pin
            else:
                RPy[Rxy] = mo.group(1)

        # Look for ANn.
        mo = re.search('AN(\d\d?)', pin)
        if mo:
            if not Rxy:
                last_failure = 'Warning: found ANn without finding Rxy in ' + pin
                last_pin = pin
            else:
                ANn[Rxy] = mo.group(1)

        # Look for CNm.
        mo = re.search('CN(\d\d?)', pin)
        if mo:
            if not Rxy:
                last_failure = 'Warning: found CNm without finding Rxy in ' + pin
                last_pin = pin
            else:
                CNm[Rxy] = mo.group(1)

    return RPy, ANn, CNm, last_failure, last_pin

form_class, base_class = uic.loadUiType('data_sheet_to_csv.ui')

class main_dialog(QtWidgets.QMainWindow, form_class):
    def __init__(self):
        # Let Qt and PyQt run their init first.
        super().__init__()
        self.setupUi(self)

        # Store portlist, which is used several times.
        self.portlist = enumeratePic24Ports()
        self.portlist.insert(0, 'Device port / pin')

    def parse_gui_text(self):
        # Read the GUI text fields and parse out pin mapping and procesor name.
        pinout_text = self.pinout_text_edit.toPlainText()
        RPy, ANn, CNm, last_failure, last_pin = text_pinout_to_mapping(pinout_text)
        self.statusBar().showMessage(last_failure)
        if last_pin:
            # Select failing text, assuming it was unique
            cursor = self.pinout_text_edit.textCursor()
            i = pinout_text.index(last_pin)
            cursor.setPosition(i)
            cursor.setPosition(i + len(last_pin), QtGui.QTextCursor.KeepAnchor)
            self.pinout_text_edit.setTextCursor(cursor)
        processor_names = ' '.join([s for s in self.processors_text_edit.toPlainText().split() if 'PIC' in s])
        return processor_names, RPy, ANn, CNm

    def on_pinout_text_edit_textChanged(self):
        self.update_table()

    def on_processors_text_edit_textChanged(self):
        self.update_table()

    # A helper to create an uneditable QTableWidgetItem
    def QTableWidgetItemUneditable(self, o):
        qtwi = QtWidgets.QTableWidgetItem(o)
        qtwi.setFlags(qtwi.flags() & ~QtCore.Qt.ItemIsEditable)
        return qtwi

    # Display results for the user.
    def update_table(self):
        processor_names, RPy, ANn, CNm = self.parse_gui_text()
        self.results_label.setText('Results: ' + processor_names)
        self.results_table_widget.clearContents()
        self.results_table_widget.setRowCount(128)
        row = 0
        for Rxy in self.portlist[1:]:
            if (Rxy in RPy) or (Rxy in ANn) or (Rxy in CNm):
                self.results_table_widget.setItem(row, 0, self.QTableWidgetItemUneditable(RPy.get(Rxy, '')))

                self.results_table_widget.setItem(row, 1, self.QTableWidgetItemUneditable(ANn.get(Rxy, '')))

                self.results_table_widget.setItem(row, 2, self.QTableWidgetItemUneditable(CNm.get(Rxy, '')))

                self.results_table_widget.setVerticalHeaderItem(row, QtWidgets.QTableWidgetItem(Rxy))

                row += 1

        self.results_table_widget.setRowCount(row)

    # This is called when OK is clicked. Append a CSV entry.
    def on_buttonBox_accepted(self):
        processor_names, RPy, ANn, CNm = self.parse_gui_text()

        # Prepare for appending to the CSV.
        with open('pic24_devices.csv', 'a+', newline='', encoding='utf-8') as outFile:
            csv_dict_writer = csv.DictWriter(outFile, self.portlist)
            # Write the header only if the file is empty. (Leaving out the seek always reports 0 for the tell).
            outFile.seek(0, os.SEEK_END)
            if outFile.tell() == 0:
                csv_dict_writer.writeheader()

            # Write it to the CSV.
            RPy['Device port / pin'] = processor_names + ' RPy'
            ANn['Device port / pin'] = processor_names + ' ANn'
            CNm['Device port / pin'] = processor_names + ' CNm'
            csv_dict_writer.writerow(RPy)
            csv_dict_writer.writerow(ANn)
            csv_dict_writer.writerow(CNm)

        # Display success, set up for next run.
        self.statusBar().showMessage('CSV updated.', 3000)
        self.processors_text_edit.clear()
        self.pinout_text_edit.clear()
        self.results_label.setText('Results')

# This routine runs the CodeChat GUI.
def main():
    # Instantiate the app and GUI.
    app = QtWidgets.QApplication(sys.argv)
    window = main_dialog()
    # Run the program.
    window.show()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
