from numba import types


class NdtType(types.Type):
    def __init__(self):
        super().__init__(name="Ndt")


class NdtNdarrayType(types.Type):
    def __init__(self):
        super().__init__(name="NdtNdarray")


class NdtContextType(types.Type):
    def __init__(self):
        super().__init__(name="NdtContext")


ndt_type = NdtType()
ndt_ndarray_type = NdtNdarrayType()
ndt_context_type = NdtContextType()
shape_type = types.List(types.int64)
