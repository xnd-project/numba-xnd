#!/usr/bin/env python


# xnd_structinfo.c is generated using the following command:
#   structinfo_generator structinfo_config.py
# TODO: run structinfo_generator from setup.py, it would require xndtools installed
import structinfo_config as xinfo_config

try:
    from setuptools import setup, Extension, find_packages
except ImportError:
    from distutils.core import setup, Extension

extra_compile_args = []
extra_link_args = []
runtime_library_dirs = []


ext_structinfo = Extension(
    xinfo_config.modulename,
    include_dirs=xinfo_config.include_dirs,
    library_dirs=xinfo_config.library_dirs,
    depends=[xinfo_config.output_filename, xinfo_config.__file__],
    sources=[xinfo_config.output_filename],
    libraries=xinfo_config.libraries,
    extra_compile_args=extra_compile_args,
    extra_link_args=extra_link_args,
    runtime_library_dirs=runtime_library_dirs,
    define_macros=[("PYTHON_MODULE", None)],
)

ext_modules = [ext_structinfo]

setup(
    name="numba-xnd",
    license="BSD",
    version="0.1",
    url="https://github.com/Quansight/numba-xnd",
    packages=find_packages(),
    ext_modules=[ext for ext in ext_modules if ext is not None],
)
