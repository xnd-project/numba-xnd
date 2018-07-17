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

    return InnerType()


def create_opaque_struct(c_struct_name, attrs):
    """
    Creates a Numba type and model for the c struct `c_struct_name`

    Returns numba type, llvm type, and a create function.

    It also registers typing and lowering for it's attributes.
    `attrs` should be a dictionary mapping attribute names to a tuple of the numba type of that attribute
    and the llvm type of that attribute.
    """
    struct_llvm_type = llvmlite.ir.ArrayType(
        char, getattr(xnd_structinfo, f"sizeof_{c_struct_name}")()
    )

    class InnerType(numba.types.Type):
        def __init__(self):
            super().__init__(
                name="".join(
                    word.capitalize()
                    for word in c_struct_name.split("_")
                    if word != "t"
                )
            )

    inner_type = InnerType()

    @numba.extending.register_model(InnerType)
    class _InnerModel(numba.extending.models.PrimitiveModel):
        def __init__(self, dmm, fe_type):
            super().__init__(dmm, fe_type, ptr(struct_llvm_type))

    @numba.extending.infer_getattr
    class _InnerTemplate(numba.typing.templates.AttributeTemplate):
        key = InnerType

        def generic_resolve(self, val, attr):
            try:
                return attrs[attr][0]
            except IndexError:
                raise NotImplementedError(
                    f"Did not register `${attr}` attribute on ${c_struct_name}"
                )

    for attr, val in attrs.items():
        _, attr_llvm_type = val

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
