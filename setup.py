#!/usr/bin/env python

import os, sys
try:
    from setuptools import setup, Extension
except ImportError:
    from distutils.core import setup, Extension

# Assuming conda based development, requires gumath installed
CONDA_PREFIX=os.environ['CONDA_PREFIX']
include_dirs = [os.path.join(CONDA_PREFIX, 'include')]
library_dirs = [os.path.join(CONDA_PREFIX, 'lib')]
libraries = []
extra_compile_args = []
extra_link_args = []
runtime_library_dirs = []

#
# `structinfo_generator gumath.h -I$CONDA_PREFIX/include -o xnd_structinfo.c`
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
