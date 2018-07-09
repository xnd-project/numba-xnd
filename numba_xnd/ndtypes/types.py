from numba import types


class PyNdtType(types.Type):
    def __init__(self):
        super().__init__(name="PyNdt")


py_ndt_type = PyNdtType()
