# -*- coding: utf-8 -*-

import glob
import os
import shutil
import uuid

# This script should batch create a group of MPLAB X projects based on the template in ./template.X. For each *.s / *.c file in the given directory, it copies the template to file_base_name.X and:
#
# #. Edits file_base_name.X/nbproject/configurations.xml to replace <itemPath>../template.s</itemPath> with <itemPath>../file_base_name.ext</itemPath>.
# Edots file_base_name.X/nmproject/project.xml to replace <name>template</name> with <name>file_base_name</name> and picks a unique / random creation-uuid.

# Directory to operate on:
working_dir = 'chap3'

# File extension to assume:
file_extension = '.s'

# Given a project direcotry, this function performs the following replacement in the configuration file:
# <itemPath>../template.s</itemPath>
# with
#  <itemPath>../<replacement_file_name></itemPath>.
def replace_in_config_file(project_dir, replacement_file_name):
    # Determine the config file name given the project directory.
    config_file_name = os.path.join(project_dir, 'nbproject', 'configurations.xml')
    # The replacement file name should contain just the base name, with no leading path components.
    replacement_file_name = os.path.split(replacement_file_name)[1]
    replace_in_xml_file(config_file_name, 'template.s', replacement_file_name, '<itemPath>../%s</itemPath>')

# Given a project directory, this routine performs two replacements in the project file:
#  <name>template</name>
# becomes
#  <name>base_file_name</name>
# and
#  <creation-uuid>a5112a0d-040c-46aa-9aba-41388c6882f9</creation-uuid>
# becomes
#  <creation-uuid>{another v4 uuid}</creation-uuid>
def replace_in_project_file(project_dir, replacement_file_name):
    # Determine the config file name given the project directory.
    project_file_name = os.path.join(project_dir, 'nbproject', 'project.xml')
    # The replacement file name should contain just the base name, with no leading path components.
    replacement_file_name = os.path.split(replacement_file_name)[1]
    replacement_file_name = os.path.splitext(replacement_file_name)[0]
    replace_in_xml_file(project_file_name, 'template', replacement_file_name, '<name>%s</name>')
    replace_in_xml_file(project_file_name, 'a5112a0d-040c-46aa-9aba-41388c6882f9', str(uuid.uuid4()), '<creation-uuid>%s</creation-uuid>')

# This routine replaces data in XML format, given a simple template.
def replace_in_xml_file(file_name, original_value, replacement_value, xml_template):
    original_string = xml_template % original_value
    replacement_string = xml_template % replacement_value
    replace_in_file(file_name, original_string, replacement_string)

# This routine searches for original_text in the contents of file_name, replacing it with replacement_text.
def replace_in_file(file_name, original_string, replacement_string):
    print('Replacing\n %s\nwith\n %s\nin %s.\n' % (original_string, replacement_string, file_name))
    with open(file_name, 'rb+') as f:
        # Read in the contents.
        contents = f.read()
        # Perform the edit.
        new_contents = contents.replace(original_string, replacement_string)
        assert new_contents != contents
        # Write it out.
        f.seek(0, os.SEEK_SET)
        f.write(new_contents)

def shutil_copytree(src, dest):
    print('Copying dir %s to %s.' % (src, dest))
    shutil.copytree(src, dest)

# Get a list of files for which to create projects.
source_files = glob.glob(os.path.join(working_dir, '*' + file_extension))
# Walk through each one.
for f in source_files:
    # Determine the destination directory based on the file name.
    dest_dir = os.path.splitext(f)[0] + '.X'
    # Create the project by copying it.
    shutil_copytree('template.X', dest_dir)
    # Edit the configurations to include the source file.
    config_file = os.path.join(dest_dir, 'nbproject', 'configurations.xml')
    replace_in_config_file(dest_dir, f)
    replace_in_project_file(dest_dir, f)
