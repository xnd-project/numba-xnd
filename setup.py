#!/usr/bin/env python

import os, sys
try:
    from setuptools import setup, Extension
except ImportError:
    from distutils.core import setup, Extension

import ndtypes
NDTYPES_ROOT = os.path.dirname(ndtypes.__file__)
import xnd
XND_ROOT = os.path.dirname(xnd.__file__)
import gumath
GUMATH_ROOT = os.path.dirname(gumath.__file__)
    
# Assuming conda based development, requires gumath installed
CONDA_PREFIX=os.environ['CONDA_PREFIX']
include_dirs = [NDTYPES_ROOT, XND_ROOT, GUMATH_ROOT, os.path.join(CONDA_PREFIX, 'include')]
library_dirs = [os.path.join(CONDA_PREFIX, 'lib')]
libraries = []
extra_compile_args = []
extra_link_args = []
runtime_library_dirs = []

# xnd_structinfo.c is generated using the following command:
#   structinfo_generator Python.h pyndtypes.h pyxnd.h gumath.h -I$CONDA_PREFIX/lib/python3.6/site-packages/xnd/  -I$CONDA_PREFIX/lib/python3.6/site-packages/ndtypes/ -I$CONDA_PREFIX/lib/python3.6/site-packages/gumath/  -o xnd_structinfo.c
#
# TODO: run structinfo_generator from setup.py, it would require xndtools installed
ext_structinfo = Extension(
    "xnd_structinfo",
    include_dirs = include_dirs,
    library_dirs = library_dirs,
    depends = ['xnd_structinfo.c'],
    sources = ['xnd_structinfo.c'],
    libraries = libraries,
    extra_compile_args = extra_compile_args,
    extra_link_args = extra_link_args,
    runtime_library_dirs = runtime_library_dirs,
    define_macros=[('PYTHON_MODULE', None)],
)

ext_modules = [ ext_structinfo ]

setup(
    name='numba-xnd',
    license='BSD',
    version='0.1',
    url='https://github.com/Quansight/numba-xnd',
    packages=['numba_xnd'],
    ext_modules = [ext for ext in ext_modules if ext is not None],
)
