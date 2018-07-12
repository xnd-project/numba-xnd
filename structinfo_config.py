"""
Configuration file to structinfo_generator.


"""
import os

import ndtypes
import xnd
import gumath

NDTYPES_ROOT = os.path.dirname(ndtypes.__file__)
XND_ROOT = os.path.dirname(xnd.__file__)
GUMATH_ROOT = os.path.dirname(gumath.__file__)

PREFIX=os.environ['CONDA_PREFIX']

output_filename = 'xnd_structinfo.c'
modulename = 'xnd_structinfo'

include_dirs = [NDTYPES_ROOT, XND_ROOT, GUMATH_ROOT, os.path.join(PREFIX, 'include')]
library_dirs = [os.path.join(PREFIX, 'lib')]
includes = ['pyndtypes.h', 'pyxnd.h', 'gumath.h']
libraries = []

# Additional C code to be added to output
c_source = '''
extern PyObject* ndt_from_type(ndt_t* val) { return Ndt_FromType(val); }
'''

# Additional Python C/API code to be added to output
pycapi_source  = '''
'''

# Additional lines to be included in PyMethodDef struct initialization
PyMethodDef_items = '''
'''

# Additional C code to be inserted to module initialization function
PyInit_source = '''
  import_ndtypes();
  import_xnd();
'''
