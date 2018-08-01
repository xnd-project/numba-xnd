"""
Configuration file to structinfo_generator.


"""
import os

import gumath
import ndtypes
import xnd

NDTYPES_ROOT = os.path.dirname(ndtypes.__file__)
XND_ROOT = os.path.dirname(xnd.__file__)
GUMATH_ROOT = os.path.dirname(gumath.__file__)

PREFIX = os.environ["CONDA_PREFIX"]

output_filename = "xnd_structinfo.c"
modulename = "xnd_structinfo"

include_dirs = [NDTYPES_ROOT, XND_ROOT, GUMATH_ROOT, os.path.join(PREFIX, "include")]
library_dirs = [os.path.join(PREFIX, "lib")]
includes = ["pyndtypes.h", "pyxnd.h", "pygumath.h"]
libraries = []

# Additional C code to be added to output
c_source = """
extern PyObject* ndt_from_type(ndt_t* val) { return Ndt_FromType(val); }
extern PyObject* xnd_from_type_xnd(PyTypeObject* t, xnd_t* val) { return Xnd_FromXnd(t, val); };
extern PyObject* xnd_view_move_ndt(const PyObject *v, ndt_t *t) { return Xnd_ViewMoveNdt(v, t); };
//extern PyObject* xnd_from_xndonly(xnd_t *val) { return Xnd_FromXndOnly(val); };
extern void print_bytes(const void *object, size_t size)
{
    // This is for C++; in C just drop the static_cast<>() and assign.
    const unsigned char *const bytes = object;
    size_t i;

    printf("Bytes: [ ");
    for (i = 0; i < size; i++)
    {
        printf("%lld ", (int64_t)bytes[i]);
    }
    printf("]\\n");

    const int64_t *bytes2 = object;
    size_t i2;
    printf("Ints: [ ");
    for (i2 = 0; i2 < (size / 8); i2++)
    {
        printf("%lld ", bytes2[i2]);
    }
    printf("]\\n\\n");
}
extern
"""

# Additional Python C/API code to be added to output
pycapi_source = """
"""

# Additional lines to be included in PyMethodDef struct initialization
PyMethodDef_items = """
"""

# Additional C code to be inserted to module initialization function
PyInit_source = """
  import_ndtypes();
  import_xnd();
  import_gumath();
"""
