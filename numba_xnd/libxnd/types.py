from numba import types


class XndType(types.Type):
    def __init__(self):
        super().__init__(name="Xnd")


xnd_type = XndType()
