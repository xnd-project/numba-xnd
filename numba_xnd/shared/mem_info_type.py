import typing

import numba

from .c_struct_type import CStructType
from .llvm import i64, index


class SimpleMemInfoModel(numba.datamodel.models.OpaqueModel):
    """
    Like numba.datamodel.models.MemInfoModel, but just returns False for contains_nrt_meminfo instead of traversing types
    """

    def contains_nrt_meminfo(self):
        return False

    def has_nrt_meminfo(self):
        return True

    def get_nrt_meminfo(self, builder, value):
        return value


class MemInfoType(numba.types.Type):
    def __init__(self):
        super().__init__(name=str(self.inner_type))

    def __init_subclass__(cls, inner_type: typing.Type[CStructType], **kwargs):
        super().__init_subclass__(**kwargs)
        cls.inner_type = inner_type

        numba.extending.register_model(cls)(SimpleMemInfoModel)

        @numba.extending.infer_getattr
        class Template(numba.typing.templates.AttributeTemplate):
            key = cls

            def resolve_data(self, val):
                return inner_type()

            def resolve_size(self, val):
                return numba.types.int64

            def resolve_refct(self, val):
                return numba.types.int64

        @numba.extending.lower_getattr(cls, "data")
        def get_data_impl(context, builder, ty, val):
            # context.nrt.incref(builder, cls(), val)

            return context.nrt.meminfo_data(builder, val)

        @numba.extending.lower_getattr(cls, "size")
        def get_size_impl(context, builder, ty, val):
            # copied from _define_nrt_meminfo_data
            struct_ptr = builder.bitcast(
                val, numba.runtime.nrtdynmod._meminfo_struct_type.as_pointer()
            )
            return builder.load(builder.gep(struct_ptr, [index(0), index(4)], True))

        @numba.extending.lower_getattr(cls, "refct")
        def get_refct_impl(context, builder, ty, val):
            # copied from _define_nrt_meminfo_data
            struct_ptr = builder.bitcast(
                val, numba.runtime.nrtdynmod._meminfo_struct_type.as_pointer()
            )
            return builder.load(builder.gep(struct_ptr, [index(0), index(0)], True))

        n_bytes = i64(inner_type.n_bytes)

        @numba.extending.intrinsic
        def alloc(typingctx, n_t=numba.types.Const(1)):
            n = None
            if isinstance(n_t, numba.types.Const):
                n = i64(n_t.value)
            elif not isinstance(n_t, numba.types.Integer):
                return

            sig = cls()(n_t)

            def codegen(context, builder, sig, args, n=n):
                if n is None:
                    n = args[0]
                return context.nrt.meminfo_alloc(builder, size=builder.mul(n, n_bytes))

            return sig, codegen

        cls.alloc = alloc
