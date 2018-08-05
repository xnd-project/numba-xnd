import inspect

import llvmlite.ir
import ndtypes

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

    return InnerType()


# TODO: Convert to class to be able to accesss functions/types as attributes instead of unpacking return arguments
def create_opaque_struct(
    c_struct_name, attrs, embedded=tuple(), create_wrapper=False, is_python_object=False
):
    """
    Creates a Numba type and model for the c struct `c_struct_name`

    Returns numba type, llvm type, and a create function.

    It also registers typing and lowering for it's attributes.
    `attrs` should be a dictionary mapping attribute names to the numba type of that attribute.

    `embedded` is a set of attribute names that actually are embedded in the struct instead of referenced.
    So if `hi` is an attribute that has a numba type with a data model of `some_other_thing*`, then if `hi`
    is in `embedded`, this struct has `some_other_thing` embedded in it, instead of a pointer to it.

    If `create_wrapper` is true, then this also creates a wrapper type that has same datamodel, but requires a
    `ndt_type` attribute that holds a ndtypes.ndt instance. In this case, it also returns a wrapper type, wrap function,
    and unwrap function.

    If `is_python_object` is true, then adds incrementing reference to boxing.
    """
    struct_llvm_type = llvmlite.ir.ArrayType(
        char, getattr(xnd_structinfo, f"sizeof_{c_struct_name}")()
    )

    llvm_repr = ptr(struct_llvm_type)

    class InnerType(numba.types.Type):
        def __init__(self):
            super().__init__(name=c_struct_name)

    @numba.extending.register_model(InnerType)
    class InnerModel(numba.extending.models.PrimitiveModel):
        def __init__(self, dmm, fe_type):
            super().__init__(dmm, fe_type, llvm_repr)

    inner_type = InnerType()

    @numba.extending.infer_getattr
    class _InnerTemplate(numba.typing.templates.AttributeTemplate):
        key = InnerType

        def generic_resolve(self, val, attr):
            if attr in attrs:
                return attrs[attr]

    def _get_attr(builder, value, attr, is_embedded):
        attr_llvm_type = llvm_type_from_numba_type(attrs[attr])
        ret_type = attr_llvm_type if is_embedded else ptr(attr_llvm_type)
        fn = builder.module.get_or_insert_function(
            llvmlite.ir.FunctionType(ret_type, [llvm_repr]),
            name=f"get_{c_struct_name}_{attr}",
        )
        return_value = builder.call(fn, [value])
        return return_value

    @numba.extending.lower_getattr_generic(InnerType)
    def _inner_getattr_impl(context, builder, typ, value, attr):
        is_embedded = attr in embedded
        ret = _get_attr(builder, value, attr, is_embedded)
        return ret if is_embedded else builder.load(ret)

    @numba.extending.lower_setattr_generic(InnerType)
    def _inner_settattr_impl(context, builder, sig, args, attr):
        target, value = args
        is_embedded = attr in embedded
        builder.store(
            value=builder.load(value) if is_embedded else value,
            ptr=_get_attr(builder, target, attr, is_embedded),
        )

    @numba.extending.intrinsic(support_literals=True)
    def create_inner(typingctx, n_t=numba.types.Const(1)):
        if not isinstance(n_t, numba.types.Const):
            return

        def codegen(context, builder, sig, args):
            return builder.alloca(struct_llvm_type, n_t.value)

        return inner_type(numba.types.int64), codegen

    # Add default unboxing as just itself, so that creating a gumath kernel with xnd_t and ndt_context_t
    # works.
    @numba.extending.unbox(InnerType)
    def unbox_inner(typ, obj, c):
        return numba.extending.NativeValue(c.builder.bitcast(obj, llvm_repr))

    @numba.extending.box(InnerType)
    def box_inner(typ, val, c):
        ret = c.builder.bitcast(val, ptr(char))
        if is_python_object:
            c.pyapi.incref(ret)
        return ret

    # add support for indexing that moves pointer over if multiple are allocated
    @numba.extending.type_callable("getitem")
    def type_array_wrap(context):
        def typer(val_t, i_t):
            if val_t == inner_type and isinstance(i_t, numba.types.Integer):
                return inner_type

        return typer

    @numba.targets.imputils.lower_builtin("getitem", InnerType, numba.types.Integer)
    def getitem_inner(context, builder, sig, args):
        x, i = args
        return builder.gep(x, [i])

    return_vals = inner_type, struct_llvm_type, create_inner
    if not create_wrapper:
        return return_vals

    class WrapperType(numba.types.Type):
        def __init__(self, n):
            assert isinstance(n, ndtypes.ndt)
            self.ndt_value = n
            super().__init__(f"{c_struct_name}Wrapper({n})")

        def can_convert_from(self, typingctx, other):
            """
            Support conversions from unwrapped to wrapped types implicitly.
            """
            if other == inner_type:
                return numba.typeconv.Conversion.promote

    numba.extending.register_model(WrapperType)(InnerModel)

    @numba.extending.lower_cast(InnerType, WrapperType)
    def inner_to_wrapper(context, builder, fromty, toty, val):
        return val

    # Need boxing/unboxing for intrinsics to work
    numba.extending.unbox(WrapperType)(unbox_inner)
    numba.extending.box(WrapperType)(box_inner)

    @numba.extending.intrinsic(support_literals=True)
    def wrap_inner(typingctx, inner_t, ndt_type_t):
        if inner_t != inner_type:
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

        sig = WrapperType(n)(inner_type, arg_type)

        def codegen(context, builder, sig, args):
            return args[0]

        return sig, codegen

    @numba.extending.intrinsic
    def unwrap_inner(typingctx, wrapper_t):
        if not isinstance(wrapper_t, WrapperType):
            return

        sig = inner_type(wrapper_t)

        def codegen(context, builder, sig, args):
            return args[0]

        return sig, codegen

    return return_vals + (WrapperType, wrap_inner, unwrap_inner)


def llvm_type_from_numba_type(numba_type):
    datamodel = numba.datamodel.registry.default_manager.lookup(numba_type)
    return datamodel.get_value_type()


def overload_any(func):
    """
    Like `numba.extending.overload` but works for things like `getitem`, etc.

    Used likes `generated_jit`:

        @overload_any("getitem")
        def getitem_const(val, i):
            if val.value == "hi":
                return lambda val, i: i
            elif val.value == "there":
                return lambda val, i: -i
    """

    def inner(overload_func):
        # lower dispatcher based on `numba.typing.templates._OverloadMethodTemplate.do_class_init`
        dispatcher = numba.generated_jit(nopython=True)(overload_func)
        disp_type = numba.types.Dispatcher(dispatcher)

        def impl(context, builder, sig, args):
            call = context.get_function(disp_type, sig)
            return call(builder, args)

        @numba.extending.type_callable(func)
        def type_inner(context):
            # need to pass in `dispatcher` or get "underlying object has vanished"
            def typer(*args, dispatcher=dispatcher):
                try:
                    sig = disp_type.get_call_type(context, args, {})
                except TypeError:  # None returned by overloaded function
                    return
                if sig:
                    # ideally, instead of adding a lowering for this specific type, we would just return the `impl`
                    # with the typing so it doesn't have to look it up. I am not sure how to do this in `type_callable`, though.
                    numba.targets.imputils.lower_builtin(func, *sig.args)(impl)
                    return sig.return_type

            return typer

    return inner


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
            inspect.Parameter(
                f"_p{i}",  # arg name doesn't matter
                inspect.Parameter.POSITIONAL_OR_KEYWORD,
            )
            for i in range(len(numba_arg_types) + 1)
        ]
    )

    return numba.extending.intrinsic(intrinsic_inner)
