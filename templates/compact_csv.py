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
# **********************************************************************
# compect_csv.py - Group all processors with identical mappings together
# **********************************************************************
#
# From https://gist.github.com/samuraisam/901117
# ==============================================
import datetime, time, functools, operator, types

default_fudge = datetime.timedelta(seconds=0, microseconds=0, days=0)

def deep_eq(_v1, _v2, datetime_fudge=default_fudge, _assert=False):
  """
  Tests for deep equality between two python data structures recursing
  into sub-structures if necessary. Works with all python types including
  iterators and generators. This function was dreampt up to test API responses
  but could be used for anything. Be careful. With deeply nested structures
  you may blow the stack.

  Options:
            datetime_fudge => this is a datetime.timedelta object which, when
                              comparing dates, will accept values that differ
                              by the number of seconds specified
            _assert        => passing yes for this will raise an assertion error
                              when values do not match, instead of returning
                              false (very useful in combination with pdb)

  Doctests included:

  >>> x1, y1 = ({'a': 'b'}, {'a': 'b'})
  >>> deep_eq(x1, y1)
  True
  >>> x2, y2 = ({'a': 'b'}, {'b': 'a'})
  >>> deep_eq(x2, y2)
  False
  >>> x3, y3 = ({'a': {'b': 'c'}}, {'a': {'b': 'c'}})
  >>> deep_eq(x3, y3)
  True
  >>> x4, y4 = ({'c': 't', 'a': {'b': 'c'}}, {'a': {'b': 'n'}, 'c': 't'})
  >>> deep_eq(x4, y4)
  False
  >>> x5, y5 = ({'a': [1,2,3]}, {'a': [1,2,3]})
  >>> deep_eq(x5, y5)
  True
  >>> x6, y6 = ({'a': [1,'b',8]}, {'a': [2,'b',8]})
  >>> deep_eq(x6, y6)
  False
  >>> x7, y7 = ('a', 'a')
  >>> deep_eq(x7, y7)
  True
  >>> x8, y8 = (['p','n',['asdf']], ['p','n',['asdf']])
  >>> deep_eq(x8, y8)
  True
  >>> x9, y9 = (['p','n',['asdf',['omg']]], ['p', 'n', ['asdf',['nowai']]])
  >>> deep_eq(x9, y9)
  False
  >>> x10, y10 = (1, 2)
  >>> deep_eq(x10, y10)
  False
  >>> deep_eq((str(p) for p in xrange(10)), (str(p) for p in xrange(10)))
  True
  >>> str(deep_eq(range(4), range(4)))
  'True'
  >>> deep_eq(xrange(100), xrange(100))
  True
  >>> deep_eq(xrange(2), xrange(5))
  False
  >>> import datetime
  >>> from datetime import datetime as dt
  >>> d1, d2 = (dt.now(), dt.now() + datetime.timedelta(seconds=4))
  >>> deep_eq(d1, d2)
  False
  >>> deep_eq(d1, d2, datetime_fudge=datetime.timedelta(seconds=5))
  True
  """
  _deep_eq = functools.partial(deep_eq, datetime_fudge=datetime_fudge,
                               _assert=_assert)

  def _check_assert(R, a, b, reason=''):
    if _assert and not R:
      assert 0, "an assertion has failed in deep_eq (%s) %s != %s" % (
        reason, str(a), str(b))
    return R

  def _deep_dict_eq(d1, d2):
    k1, k2 = (sorted(d1.keys()), sorted(d2.keys()))
    if k1 != k2: # keys should be exactly equal
      return _check_assert(False, k1, k2, "keys")

    return _check_assert(operator.eq(sum(_deep_eq(d1[k], d2[k])
                                       for k in k1),
                                     len(k1)), d1, d2, "dictionaries")

  def _deep_iter_eq(l1, l2):
    if len(l1) != len(l2):
      return _check_assert(False, l1, l2, "lengths")
    return _check_assert(operator.eq(sum(_deep_eq(v1, v2)
                                      for v1, v2 in zip(l1, l2)),
                                     len(l1)), l1, l2, "iterables")

  def op(a, b):
    _op = operator.eq
    if type(a) == datetime.datetime and type(b) == datetime.datetime:
      s = datetime_fudge.seconds
      t1, t2 = (time.mktime(a.timetuple()), time.mktime(b.timetuple()))
      l = t1 - t2
      l = -l if l > 0 else l
      return _check_assert((-s if s > 0 else s) <= l, a, b, "dates")
    return _check_assert(_op(a, b), a, b, "values")

  c1, c2 = (_v1, _v2)

  # guard against strings because they are iterable and their
  # elements yield iterables infinitely.
  # I N C E P T I O N
  for t in types.StringTypes:
    if isinstance(_v1, t):
      break
  else:
    if isinstance(_v1, types.DictType):
      op = _deep_dict_eq
    else:
      try:
        c1, c2 = (list(iter(_v1)), list(iter(_v2)))
      except TypeError:
        c1, c2 = _v1, _v2
      else:
        op = _deep_iter_eq

  return op(c1, c2)











# Code for this program
# =====================
import csv

# Enumerate all ports on a PIC24 processor, returning the result as a list.
def enumeratePic24Ports():
    port_letters = [chr(i) for i in range(ord('A'), ord('K') + 1)]
    # The PIC series doesn't have port I.
    port_letters.remove('I')
    return [i + str(j) for i in port_letters
                       for j in range(16)]

# This routine builds pic24_ports_tables.h from a template. To do so:
#
# #. Open the output file and write out the header.
# #. Load in the CSV file containing pin information:
#
#    #. Load three rows; they should be labeled xxx RPy, xxx ANn, and xxx CNm, where xxx is the processor.
#    #. For each Rxy value:
#
#       #. For F/H devices: look at the corresponding RPy, ANn, and CNm. If any are non-empty, write a table entry.
#       #. For E devices: Write a #define for RPy or ANn if either are non-empty.
#
# #. Write out the footer.
def genTablesFromTemplate(csvFileName, destFileName):
    # Read in the CSV containing device information.
    processors = { }
    with open(csvFileName, "rb") as csvFile:
        csv_dict_reader = csv.DictReader(csvFile).__iter__()
        # Walk through the file
        while True:
            # Read three rows
            try:
                RPy = csv_dict_reader.next()
                ANn = csv_dict_reader.next()
                CNm = csv_dict_reader.next()
            except StopIteration:
                break
            # Get processor information and remove it (to avoid breaking the comparisons)
            processor_name = RPy['Device port / pin'][:-4]
            del RPy['Device port / pin']
            del ANn['Device port / pin']
            del CNm['Device port / pin']
            # Look for a duplicate
            processor_value = (RPy, ANn, CNm)
            found = False
            for processor in processors:
                if deep_eq(processors[processor], processor_value):
                    #print("%s duplicates %s." % (processor, processor_name))
                    found = True
                    processors[processor + ' ' + processor_name] = processor_value
                    del processors[processor]
            if not found:
                processors[processor_name] = processor_value

    # Open the output file.
    #print(processors)
    with open(destFileName, "wb") as outFile:
        portlist = enumeratePic24Ports()
        portlist.insert(0, 'Device port / pin')
        csv_dict_writer = csv.DictWriter(outFile, portlist)
        csv_dict_writer.writeheader()

        for processor in sorted(processors.keys()):
            RPy, ANn, CNm = processors[processor]
            # Remove any duplicates and write out processor names in sorted order.
            processor = ' '.join(sorted(set(processor.split(' '))))
            RPy['Device port / pin'] = processor + ' RPy'
            ANn['Device port / pin'] = processor + ' ANn'
            CNm['Device port / pin'] = processor + ' CNm'
            csv_dict_writer.writerow(RPy)
            csv_dict_writer.writerow(ANn)
            csv_dict_writer.writerow(CNm)


if __name__ == '__main__':
    genTablesFromTemplate('pic24_devices.csv' , 'pic24_devices_combined.csv')
