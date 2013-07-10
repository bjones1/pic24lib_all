# Bring in path for SCons use.
import os
env = Environment(ENV = {'PATH' : os.environ['PATH']})

# Update docs.
env.Execute('doxygen')

# Copy updated CodeChat docs into Doxygen output.
env.Execute('..\..\..\..\documentation\code_chat.py')
env.Execute(Delete('docs/sphinx', must_exist = 0))
env.Execute(Copy('docs/sphinx', '_build/html'))


# Define a single target to build the zip file.
zip_file = '../pic24_code_examples.zip'
env.Default(env.Zip(zip_file, [
  'readme.txt',
  'standard_header.txt',
  'bin',
  'bootloader',
  'docs',
  'hex',
  'chap03',
  'chap04',
  'chap06',
  'chap07',
  'chap08',
  'chap09',
  'chap10',
  'chap11',
  'chap12',
  'chap13',
  'chap14',
  'chap15',
  'esos',
  'lib/lkr',
  'lib/src',
  'lib/include',
  'explorer16_100p',
  'util' ]))
