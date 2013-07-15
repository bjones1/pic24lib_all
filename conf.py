# .. -*- coding: utf-8 -*-
#
#    Copyright (C) 2012-2013 Bryan A. Jones.
#
#    This file is part of CodeChat.
#
#    CodeChat is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
#
#    CodeChat is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License along with CodeChat.  If not, see <http://www.gnu.org/licenses/>.
#
# *********************************************************************
# template/conf.py - Template configuration file for a CodeChat project
# *********************************************************************
# This file configures Sphinx, which transforms restructured text (reST) into html. See Sphinx `build configuration file docs <http://sphinx-doc.org/config.html>`_ for more information on the settings below.
#
# This file was originally created by sphinx-quickstart, then modified by hand. Notes on its operation:
#
# * This file is ``execfile()``\d by Sphinx with the current directory set to its containing dir.
# * Not all possible configuration values are present in this autogenerated file.
# * All configuration values have a default; values that are commented out serve to show the default.

import sys, os

# If extensions (or modules to document with autodoc) are in another directory, add these directories to sys.path here. If the directory is relative to the documentation root, use os.path.abspath to make it absolute, as shown here.
##sys.path.insert(0, os.path.abspath('.'))
#
# `Project information <http://sphinx-doc.org/config.html#project-information>`_
# -------------------------------------------------------------------------------
# `project <http://sphinx-doc.org/config.html#confval-project>`_  and `copyright <http://sphinx-doc.org/config.html#confval-copyright>`_: General information about the project. **Change this** for your project.
project = u'Microcontrollers: From Assembly Language to C Using the PIC24 family, second edition'
copyright = u'2013, Bryan A. Jones, Robert B. Reese, and J. W. Bruce'

# The version info for the project you're documenting, acts as replacement for |version| and |release|, also used in various other places throughout the built documents. **Change these** for your project.
#
# `version <http://sphinx-doc.org/config.html#confval-version>`_: The short X.Y version.
version = 'Jun-2013'
# `release <http://sphinx-doc.org/config.html#confval-release>`_: The full version, including alpha/beta/rc tags.
release = '4-Jun-2013'

# There are two options for replacing |today|:
#
# \1. If you set `today <http://sphinx-doc.org/config.html#confval-today>`_ to some non-false value, then it is used:
##today = ''
# \2. Otherwise, `today_fmt <http://sphinx-doc.org/config.html#confval-today_fmt>`_ is used as the format for a strftime call.
##today_fmt = '%B %d, %Y'

# `highlight_language <http://sphinx-doc.org/config.html#confval-highlight_language>`_: The default language to highlight source code in. **CodeChat note:** This should **not** be ``python``, since Sphinx will try to parse Python fragments and fail, then refuse ot highlight the code.
highlight_language = 'python3'

# `pygments_style <http://sphinx-doc.org/config.html#confval-pygments_style>`_: The style name to use for Pygments highlighting of source code.
pygments_style = 'sphinx'

# `add_function_parentheses <http://sphinx-doc.org/config.html#confval-add_function_parentheses>`_: If true, '()' will be appended to :func: etc. cross-reference text.
##add_function_parentheses = True

# `add_module_names <http://sphinx-doc.org/config.html#confval-add_module_names>`_: If true, the current module name will be prepended to all description unit titles (such as .. function::).
##add_module_names = True

# `show_authors <http://sphinx-doc.org/config.html#confval-show_authors>`_: If true, sectionauthor and moduleauthor directives will be shown in the output. They are ignored by default.
##show_authors = False

# `modindex_common_prefix <http://sphinx-doc.org/config.html#confval-modindex_common_prefix>`_: A list of ignored prefixes for module index sorting.
##modindex_common_prefix = []

#
# `General configuration <http://sphinx-doc.org/config.html#general-configuration>`_
# -----------------------------------------------------------------------------------
# `extensions <http://sphinx-doc.org/config.html#confval-extensions>`_: If your documentation needs a minimal Sphinx version, state it here. CodeChat comes bundled with the correct version of Sphinx; you may ignore this unless you plan on building the docuumentation with an externally-installed Sphinx.
##needs_sphinx = '1.0'

# Add any Sphinx extension module names here, as strings. They can be extensions coming with Sphinx (named 'sphinx.ext.*') or your custom ones. **Important:** The ``CodeChat.CodeToRest`` extension is mandatory; without it, CodeChat will not translate source code to reST and the (via Sphinx) to html.
extensions = ['CodeChat.CodeToRest']

# `templates_path <http://sphinx-doc.org/config.html#confval-templates_path>`_: Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# `source_suffix <http://sphinx-doc.org/config.html#confval-source_suffix>`_: The suffix of source filenames.
source_suffix = '.rst'

# `source_encoding <http://sphinx-doc.org/config.html#confval-source_encoding>`_: The encoding of source files.
##source_encoding = 'utf-8-sig'

# `master_doc <http://sphinx-doc.org/config.html#confval-master_doc>`_: The master toctree document.
master_doc = 'contents'

# The language for content autogenerated by Sphinx. Refer to documentation for a list of supported languages.
##language = None

# `exclude_patterns <http://sphinx-doc.org/config.html#confval-exclude_patterns>`_: List of patterns, relative to source directory, that match files and directories to ignore when looking for source files. **CodeChat note:** This should always include the ``_build`` directory, which is where CodeChat's Sphinx output is placed.
exclude_patterns = ['_build',
                    'appg',
                    'asee_*',
                    'bin',
                    'bootloader',
                    'build',
                    'docs',
                    'esos',
                    'hex',
                    'lib',
                    'misc',
                    'conf.py.rst',
                    # Ignore MPLAB X auto-generated files.
                    '**.X/build',
                    '**.X/dist',
                    '**.X/nbproject',
                    '.hg'
                    ]

# `default_role <http://sphinx-doc.org/config.html#confval-default_role>`_: The reST default role (used for this markup: `text`) to use for all documents.
##default_role = None

# `keep_warnings <http://sphinx-doc.org/config.html#confval-keep_warnings>`_: If true, keep warnings as "system message" paragraphs in the built documents. Regardless of this setting, warnings are always written to the standard error stream when sphinx-build is run. **CodeChat note**: This should always be True; doing so places warnings next to the offending text in the web view, making them easy to find and fix.
keep_warnings = True
#
# `Options for HTML output <http://sphinx-doc.org/config.html#options-for-html-output>`_
# --------------------------------------------------------------------------------------
# `html_theme <http://sphinx-doc.org/config.html#confval-html_theme>`_: The theme to use for HTML and HTML Help pages.  **CodeChat note:** Only the ``default`` theme has been modified to work with CodeChat; only use it.
html_theme = 'default'

# `html_theme_options <http://sphinx-doc.org/config.html#confval-html_theme_options>`_: Theme options are theme-specific and customize the look and feel of a theme further. **CodeChat note:** The sidebar confuses the web preview pane, so it is disabled.
html_theme_options = { "nosidebar" : "true" }

# `html_style <http://sphinx-doc.org/config.html#confval-html_style>`_: The style sheet to use for HTML pages.
##html_style = ''

# `html_theme_path <http://sphinx-doc.org/config.html#confval-html_theme_path>`_: Add any paths that contain custom themes here, relative to this directory.
##html_theme_path = []

# `html_title <http://sphinx-doc.org/config.html#confval-html_title>`_: The name for this set of Sphinx documents.  If None, it defaults to ``<project> v<release> documentation``.
##html_title = None

# `html_short_title <http://sphinx-doc.org/config.html#confval-html_short_title>`_: A shorter title for the navigation bar.  Default is the same as html_title.
##html_short_title = None

# `html_logo <http://sphinx-doc.org/config.html#confval-html_logo>`_: The name of an image file (relative to this directory) to place at the top of the sidebar.
##html_logo = None

# `html_favicon <http://sphinx-doc.org/config.html#confval-html_favicon>`_: The name of an image file (within the static path) to use as favicon of the docs.  This file should be a Windows icon file (.ico) being 16x16 or 32x32 pixels large.
##html_favicon = None

# `html_static_path <http://sphinx-doc.org/config.html#confval-html_static_path>`_: Add any paths that contain custom static files (such as style sheets) here, relative to this directory. They are copied after the builtin static files, so a file named ``default.css`` will overwrite the builtin ``default.css``. **CodeChat note:** This must always include ``default.css``.
html_static_path = ['default.css']

# `html_last_updated_fmt <http://sphinx-doc.org/config.html#confval-html_last_updated_fmt>`_: If not '', a 'Last updated on:' timestamp is inserted at every page bottom, using the given strftime format.
html_last_updated_fmt = '%b %d, %Y'

# `html_use_smartypants <http://sphinx-doc.org/config.html#confval-html_use_smartypants>`_: If true, `SmartyPants <http://daringfireball.net/projects/smartypants/>`_ will be used to convert quotes and dashes to typographically correct entities.
html_use_smartypants = True

# `html_sidebars <http://sphinx-doc.org/config.html#confval-html_sidebars>`_: Custom sidebar templates, maps document names to template names.
##html_sidebars = {}

# `html_additional_pages <http://sphinx-doc.org/config.html#confval-html_additional_pages>`_: Additional templates that should be rendered to pages, maps page names to template names.
##html_additional_pages = {}

# `html_domain_indices <http://sphinx-doc.org/config.html#confval-html_domain_indices>`_: If false, no module index is generated.
##html_domain_indices = True

# `html_use_index <http://sphinx-doc.org/config.html#confval-html_use_index>`_: If false, no index is generated.
##html_use_index = True

# `html_split_index <http://sphinx-doc.org/config.html#confval-html_split_index>`_: If true, the index is split into individual pages for each letter.
##html_split_index = False

# `html_show_sourcelink <http://sphinx-doc.org/config.html#confval-html_show_sourcelink>`_: If true, links to the reST sources are added to the pages. **CodeChat note:** at this time, the sourcelink doesn't show the original source code, making it (mostly) useless.
html_show_sourcelink = False

# `html_show_sphinx <http://sphinx-doc.org/config.html#confval-html_show_sphinx>`_: If true, "Created using Sphinx" is shown in the HTML footer. Default is True.
##html_show_sphinx = True

# `html_show_copyright <http://sphinx-doc.org/config.html#confval-html_show_copyright>`_: If true, "(C) Copyright ..." is shown in the HTML footer. Default is True.
##html_show_copyright = True

# `html_use_opensearch <http://sphinx-doc.org/config.html#confval-html_use_opensearch>`_: If true, an OpenSearch description file will be output, and all pages will contain a <link> tag referring to it.  The value of this option must be the base URL from which the finished HTML is served.
##html_use_opensearch = ''

# `html_file_suffix <http://sphinx-doc.org/config.html#confval-html_file_suffix>`_: This is the file name suffix for HTML files (e.g. ".xhtml"). **CodeChat note:** do no change; CodeChat assumes a ``.html`` extension.
##html_file_suffix = None
