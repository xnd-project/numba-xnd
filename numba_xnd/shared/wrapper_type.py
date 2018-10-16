import typing

import ndtypes
import numba.extending
import numba.types
import numba.typing.templates

from .c_struct_type import CStructModel, CStructType


class WrapperType(numba.types.Type):
    def __init__(self, nrt_allocated: bool, ndt_value: ndtypes.ndt):
        assert isinstance(ndt_value, ndtypes.ndt)
        self.ndt_value = ndt_value
        self.nrt_allocated = nrt_allocated
        super().__init__(name=f"{type(self).__name__}({nrt_allocated}, {ndt_value})")

    @property
    def key(self):
        return self.ndt_value

    def can_convert_from(self, typingctx, other):
        """
        Support conversions from unwrapped to wrapped types implicitly.
        """
        if (
            isinstance(other, self.inner_type)
            and other.nrt_allocated == self.nrt_allocated
        ):
            return numba.typeconv.Conversion.promote

    def __init_subclass__(cls, inner_type: typing.Type[CStructType], **kwargs):
        super().__init_subclass__(**kwargs)

        cls.inner_type = inner_type
        numba.extending.register_model(cls)(CStructModel)

        # allow casting from unwrapped to wrapped value
        numba.extending.lower_cast(inner_type, cls)(
            lambda context, builder, fromty, toty, val: val
        )

        cls.wrap = numba.extending.intrinsic(support_literals=True)(cls.wrap_impl)
        cls.unwrap = numba.extending.intrinsic(cls.unwrap_impl)

    @classmethod
    def wrap_impl(cls, typingctx, inner_t, ndt_type_t):
        if not isinstance(inner_t, cls.inner_type):
            return
        # supports passing in strings as ndt's
        if isinstance(ndt_type_t, numba.types.Const):
            n = ndtypes.ndt(ndt_type_t.value)
            arg_type = numba.types.string
        elif hasattr(ndt_type_t, "ndt_value"):
            n = ndt_type_t.ndt_value
            arg_type = ndt_type_t
        else:
            return

        sig = cls(inner_t.nrt_allocated, n)(inner_t, arg_type)

        def codegen(context, builder, sig, args):
            return args[0]

        return sig, codegen

    @classmethod
    def unwrap_impl(cls, typingctx, wrapper_t):
        if not isinstance(wrapper_t, cls):
            return

        sig = cls.inner_type(wrapper_t.nrt_allocated)(wrapper_t)

        def codegen(context, builder, sig, args):
            return args[0]

        return sig, codegen
