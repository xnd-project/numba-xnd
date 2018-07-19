import inspect

import llvmlite.ir

import numba.extending
import numba.types
import numba.typing.templates
import xnd_structinfo

from .llvm import char, ptr


def create_numba_type(name, llvm_type):
    """
    Creates an empty type class with a name and returns and instance of it.
    """

    class InnerType(numba.types.Type):
        def __init__(self):
            super().__init__(name=name)

    @numba.extending.register_model(InnerType)
    class InnerModel(numba.extending.models.PrimitiveModel):
        def __init__(self, dmm, fe_type):
            super().__init__(dmm, fe_type, llvm_type)

    return InnerType


def create_opaque_struct(c_struct_name, attrs):
    """
    Creates a Numba type and model for the c struct `c_struct_name`

    Returns numba type, llvm type, and a create function.

    It also registers typing and lowering for it's attributes.
    `attrs` should be a dictionary mapping attribute names to the numba type of that attribute.
    """
    struct_llvm_type = llvmlite.ir.ArrayType(
        char, getattr(xnd_structinfo, f"sizeof_{c_struct_name}")()
    )

    InnerType = create_numba_type(
        "".join(word.capitalize() for word in c_struct_name.split("_") if word != "t"),
        ptr(struct_llvm_type),
    )
    inner_type = InnerType()

    @numba.extending.infer_getattr
    class _InnerTemplate(numba.typing.templates.AttributeTemplate):
        key = InnerType

        def generic_resolve(self, val, attr):
            try:
                return attrs[attr]
            except IndexError:
                raise NotImplementedError(
                    f"Did not register `${attr}` attribute on ${c_struct_name}"
                )

    def _get_attr(builder, value, attr):
        attr_llvm_type = llvm_type_from_numba_type(attrs[attr])

        # we only get a ptr to the return type if isn't a pointer already
        # https://github.com/plures/xndtools/blob/8c46cdfddc1ff7ffd9dd40a33d102bdd543e4280/xndtools/structinfo_generator.py#L180-L186
        is_scalar = not attr_llvm_type.is_pointer
        return_type = ptr(attr_llvm_type) if is_scalar else attr_llvm_type
        return_value = builder.call(
            builder.module.get_or_insert_function(
                llvmlite.ir.FunctionType(return_type, [ptr(struct_llvm_type)]),
                name=f"get_{c_struct_name}_{attr}",
            ),
            [value],
        )
        return is_scalar, return_value

    @numba.extending.lower_getattr_generic(InnerType)
    def _inner_getattr_impl(context, builder, typ, value, attr):
        is_scalar, return_value = _get_attr(builder, value, attr)
        return builder.load(return_value) if is_scalar else return_value

    @numba.extending.lower_setattr_generic(InnerType)
    def _inner_settattr_impl(context, builder, sig, args, attr):
        target, value = args
        is_scalar, target_attr = _get_attr(builder, target, attr)
        builder.store(
            value=value if is_scalar else builder.load(value), ptr=target_attr
        )

    @numba.extending.intrinsic(support_literals=True)
    def create_inner(typingctx, n_t=numba.types.Const(1)):
        if not isinstance(n_t, numba.types.Const):
            return

        def codegen(context, builder, sig, args):
            return builder.alloca(struct_llvm_type, n_t.value)

        return inner_type(numba.types.int64), codegen

    return inner_type, struct_llvm_type, create_inner


def llvm_type_from_numba_type(numba_type):
    datamodel = numba.datamodel.registry.default_manager.lookup(numba_type)
    return datamodel.get_value_type()


def wrap_c_func(func_name, numba_ret_type, numba_arg_types):
    def intrinsic_inner(typingctx, *numba_arg_types_):
        if numba_arg_types_ != numba_arg_types:
            return

        sig = numba_ret_type(*numba_arg_types)

        def codegen(context, builder, sig, args):
            return builder.call(
                builder.module.get_or_insert_function(
                    llvmlite.ir.FunctionType(
                        llvm_type_from_numba_type(numba_ret_type),
                        [llvm_type_from_numba_type(t) for t in numba_arg_types],
                    ),
                    name=func_name,
                ),
                args,
            )

        return sig, codegen

    intrinsic_inner.__name__ = func_name
    # change the function signature to take positional instead of variadic arguments
    # so that numba type inference will work on it properly
    # This should be like if you defined the intrinsic function explicitly with all the arguments
    intrinsic_inner.__signature__ = inspect.signature(intrinsic_inner).replace(
        parameters=[
            inspect.Parameter(f"_p{i}", inspect.Parameter.POSITIONAL_OR_KEYWORD)
            for i in range(len(numba_arg_types) + 1)
        ]
    )
    return numba.extending.intrinsic(intrinsic_inner)
