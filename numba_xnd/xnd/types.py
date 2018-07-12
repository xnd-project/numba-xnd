from numba import types


class PyXndType(types.Type):
    def __init__(self):
        super().__init__(name="PyXnd")


py_xnd_type = PyXndType()
