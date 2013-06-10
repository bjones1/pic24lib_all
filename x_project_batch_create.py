# -*- coding: utf-8 -*-

import glob
import os
import shutil

# This script should batch create a group of MPLAB X projects based on the template in ./template.X. For each *.s / *.c file in the given directory, it copies the template to file_base_name.X and edits file_base_name.X/nbproject/configurations.xml to replace <itemPath>../template.s</itemPath> with <itemPath>../file_base_name.ext</itemPath>.

# Directory to operate on:
working_dir = 'chap3'

# File extension to assume:
file_extension = '.s'

# Given a configuration file, this routine replaces:
# <itemPath>../template.s</itemPath>
# with
#  <itemPath>../<replacement_file_name></itemPath>.
def replace_in_config_file(file_name, replacement_file_name, originaL_file_name = 'template.s'):
    item_path_template = '<itemPath>../%s</itemPath>'
    original_string = item_path_template % originaL_file_name
    # The replacement file name should contain just the base name, with no leading path components.
    replacement_file_name = os.path.split(replacement_file_name)[1]
    replacement_string = item_path_template % replacement_file_name
    replace_in_file(file_name, original_string, replacement_string)

# This routine searches for original_text in the contents of file_name, replacing it with replacement_text.
def replace_in_file(file_name, replacement_string, original_string):
    print('Replacing\n %s\nwith\n %s\nin %s.\n' % (original_string, replacement_string, file_name))


def shutil_copytree(src, dest):
    print('Copying dir %s to %s.' % (src, dest))

# Get a list of files for which to create projects.
source_files = glob.glob(os.path.join(working_dir, '*' + file_extension))
# Walk through each one.
for f in source_files:
    # Determine the destination directory based on the file name.
    dest_dir = os.path.splitext(f)[0] + '.X'
    # Create the project by copying it.
    shutil_copytree('template.X', dest_dir)
    # Edit the configurations to include the source file.
    config_file = os.path.join(working_dir, dest_dir, 'nbproject', 'configurations.xml')
    replace_in_config_file(config_file, f)
