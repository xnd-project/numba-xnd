import inspect

import llvmlite

import numba

from .c_struct_type import CStructType
from .extending import llvm_type_from_numba_type
from .llvm import char, ptr


class CFunctionIntrinsic(numba.extending._Intrinsic):
    """
    Creates an intrinsic for a C function. Also exposes the underlying codegen, if you want
    to use that from a low level.
    """

    def __init__(self, func_name, numba_ret_type, numba_arg_types):
        assert isinstance(numba_arg_types, tuple)
        assert isinstance(numba_ret_type, numba.types.Type)
        self.arg_types = []
        for t in numba_arg_types:
            # args should be either numba type instances or subclasses of CStructType
            if isinstance(t, numba.types.Type):
                self.arg_types.append(llvm_type_from_numba_type(t))
            elif issubclass(t, CStructType):
                self.arg_types.append(ptr(char))
            else:
                raise TypeError("Should either be numba type or CStruct type", t)

        self.func_name = func_name
        self.numba_ret_type = numba_ret_type
        self.numba_arg_types = numba_arg_types

        self.ret_type = llvm_type_from_numba_type(self.numba_ret_type)

        super().__init__(func_name, self.create_impl())
        self._register()

    def __str__(self):
        return f"{self.func_name}"

    def codegen(self, builder, args):
        return builder.call(
            builder.module.get_or_insert_function(
                llvmlite.ir.FunctionType(self.ret_type, self.arg_types),
                name=self.func_name,
            ),
            args,
        )

    def create_impl(self):
        def impl(typingctx, *numba_arg_types):
            for actual_type, sig_type in zip(numba_arg_types, self.numba_arg_types):
                if not (actual_type == sig_type or isinstance(actual_type, sig_type)):
                    return

            return (
                self.ret_type(*numba_arg_types),
                lambda context, builder, sig, args: self.codegen(builder, args),
            )

        impl.__name__ = self.func_name
        # change the function signature to take positional instead of variadic arguments
        # so that numba type inference will work on it properly
        # This should be like if you defined the intrinsic function explicitly with all the arguments
        impl.__signature__ = inspect.signature(impl).replace(
            parameters=[
                inspect.Parameter(
                    f"_p{i}",  # arg name doesn't matter
                    inspect.Parameter.POSITIONAL_OR_KEYWORD,
                )
                for i in range(len(self.numba_arg_types) + 1)
            ]
        )
        return impl
