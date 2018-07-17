import inspect
import llvmlite.ir
import xnd_structinfo
import numba.extending
import numba.typing.templates
import numba.types
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

    for attr, val in attrs.items():
        attr_llvm_type = llvm_type_from_numba_type(val)

        @numba.extending.lower_getattr(InnerType, attr)
        def _inner_getattr_impl(
            context, builder, typ, value, attr_llvm_type=attr_llvm_type, attr=attr
        ):
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
            return builder.load(return_value) if is_scalar else return_value

    @numba.extending.intrinsic
    def create_inner(typingctx):
        def codegen(context, builder, sig, args):
            return builder.alloca(struct_llvm_type)

        return inner_type(), codegen

    return inner_type, struct_llvm_type, create_inner


def llvm_type_from_numba_type(numba_type):
    datamodel = numba.datamodel.registry.default_manager.lookup(numba_type)
    return datamodel.get_value_type()


def wrap_c_func(func_name, numba_ret_type, numba_arg_types):
    def intrinsic_inner(typingctx, *numba_arg_types_):
        if numba_arg_types_ != numba_arg_types:
            return

        sig = numba_ret_type(*numba_arg_types)
        print("SIG", sig)

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
