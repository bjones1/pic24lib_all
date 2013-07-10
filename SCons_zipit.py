# Update docs. Not sure why I must give the full path here.
Execute(r'C:\Program Files\doxygen\bin\doxygen')

# Copy updated CodeChat docs into Doxygen output.
Execute('..\\..\\documentation\\code_chat.py')
Execute(Delete('docs/sphinx', must_exist = 0))
Execute(Copy('docs/sphinx', '_build/html'))

# Zip it!
zipNode = env.Zip('../pic24_code_examples.zip', [
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
  'util' ])
