# -*- coding: utf-8 -*-
"""
Created on Mon Jun 03 09:43:43 2013

@author: bjones
"""

# This program accepts text copied and pasted from a Microchip data sheet (in PDF format) of the pinout for a given package, then translates it into an Rxy/RPy/ANn/CNm mapping.

import re
import sys
import csv

import sip
sip.setapi('QString', 2)
sip.setapi('QVariant', 2)

from compact_csv import enumeratePic24Ports


# The excellent `PyQt4 library <http://www.riverbankcomputing.co.uk/static/Docs/PyQt4/html/classes.html>`_ provides the GUI for this package.
from PyQt4 import QtGui, uic

def text_pinout_to_mapping(text):
    pins = text.split()
    RPy = { }
    ANn = { }
    CNm = { }
    processor_names = []
    for pin in pins:
        # Look for a processor name.
        mo = re.search('PIC', pin)
        if mo:
            processor_names.append(pin)

        # Look for Rxy. If not found, we can't do anything with this pin.
        mo = re.search('R([A-G]\d\d?)', pin)
        if mo:
            Rxy = mo.group(1)
        else:
            # No Rxy pin here, so we can't map. Do error checking anyway.
            Rxy = ''

        # Look for RPy.
        mo = re.search('RPI?(\d\d?\d?)', pin)
        if mo:
            assert Rxy
            RPy[Rxy] = mo.group(1)

        # Look for ANn.
        mo = re.search('AN(\d\d?)', pin)
        if mo:
            assert Rxy
            ANn[Rxy] = mo.group(1)
                # Look for ANn.
        mo = re.search('CN(\d\d?)', pin)
        if mo:
            assert Rxy
            CNm[Rxy] = mo.group(1)

    return ' '.join(processor_names), RPy, ANn, CNm

form_class, base_class = uic.loadUiType('data_sheet_to_csv.ui')

class main_dialog(QtGui.QDialog, form_class):
    def __init__(self):
        # Let Qt and PyQt run their init first.
        QtGui.QDialog.__init__(self)
        self.setupUi(self)

    # This is called when the pinout text box changes (typically, when a paste is done).
    def on_pinout_text_edit_textChanged(self):
        processor_names, RPy, ANn, CNm = text_pinout_to_mapping(self.pinout_text_edit.toPlainText())
        self.processors_text_edit.setPlainText(processor_names)
        self.pins = (processor_names, RPy, ANn, CNm)

    # This is called when OK is clicked. Append a CSV entry.
    def on_buttonBox_accepted(self):
        with open('data_sheet_to_csv.csv', 'a+b') as outFile:
            portlist = enumeratePic24Ports()
            portlist.insert(0, 'Device port / pin')
            csv_dict_writer = csv.DictWriter(outFile, portlist)
            csv_dict_writer.writeheader()

            processor_names, RPy, ANn, CNm = self.pins
            RPy['Device port / pin'] = processor_names + ' RPy'
            ANn['Device port / pin'] = processor_names + ' ANn'
            CNm['Device port / pin'] = processor_names + ' CNm'
            csv_dict_writer.writerow(RPy)
            csv_dict_writer.writerow(ANn)
            csv_dict_writer.writerow(CNm)

# This routine runs the CodeChat GUI.
def main():
    # Instantiate the app and GUI.
    app = QtGui.QApplication(sys.argv)
    window = main_dialog()
    # Run the program.
    window.show()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
