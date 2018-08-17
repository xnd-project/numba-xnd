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


# TODO: Make this a subclass of numba type, however each instance of it should have
# be a different singleton type
class WrappedCStruct:
    def __init__(self, name, attrs, embedded=tuple(), create_wrapper=False):
        """
        Creates a Numba type and model for the c struct `name`

        It also registers typing and lowering for it's attributes.
        `attrs` should be a dictionary mapping attribute names to the numba type of that attribute.

        `embedded` is a set of attribute names that actually are embedded in the struct instead of referenced.
        So if `hi` is an attribute that has a numba type with a data model of `some_other_thing*`, then if `hi`
        is in `embedded`, this struct has `some_other_thing` embedded in it, instead of a pointer to it.

        If `create_wrapper` is true, then this also creates a wrapper type that has same datamodel, but requires a
        `ndt_type` attribute that holds a ndtypes.ndt instance.
        """
        for t in attrs.values():
            assert isinstance(t, numba.types.Type)

        self.name, self.attrs, self.embedded = name, attrs, embedded

        self.n_bytes = getattr(xnd_structinfo, f"sizeof_{name}")()
        self.llvm_type = llvmlite.ir.ArrayType(char, self.n_bytes)

        self.llvm_ptr_type = ptr(self.llvm_type)

        self.NumbaType = self._create_numba_type()
        self.numba_type = self.NumbaType()

        self.NumbaModel = numba.extending.register_model(self.NumbaType)(
            self._create_numba_model()
        )

        numba.extending.infer_getattr(self._create_getattr_template())

        numba.extending.lower_getattr_generic(self.NumbaType)(self.getattr_impl)
        numba.extending.lower_setattr_generic(self.NumbaType)(self.settattr_impl)
        self.create = numba.extending.intrinsic(support_literals=True)(self.create_impl)

        numba.extending.type_callable("getitem")(self.type_getitem)
        numba.targets.imputils.lower_builtin(
            "getitem", self.NumbaType, numba.types.Integer
        )(self.lower_getitem)

        if not create_wrapper:
            return

        self.WrapperNumbaType = self.create_wrapper_numba_type()
        numba.extending.register_model(self.WrapperNumbaType)(self.NumbaModel)
        numba.extending.lower_cast(self.NumbaType, self.WrapperNumbaType)(
            lambda context, builder, fromty, toty, val: val
        )

        self.wrap = numba.extending.intrinsic(support_literals=True)(self.wrap_impl)
        self.unwrap = numba.extending.intrinsic(self.unwrap_impl)

    def __str__(self):
        return f"{self.name}({self.llvm_type})"

    def _create_numba_type(self):
        name = self.name

        class NumbaType(numba.types.Type):
            def __init__(self):
                super().__init__(name=name)

        return NumbaType

    def _create_numba_model(self):
        be_type = self.llvm_ptr_type
        llvm_type = self.llvm_type

        class NumbaModel(numba.extending.models.PrimitiveModel):
            def __init__(self, dmm, fe_type):
                super().__init__(dmm, fe_type, be_type)

            def get_return_type(self):
                return llvm_type

            def get_data_type(self):
                return llvm_type

            def as_return(self, builder, value):
                return builder.load(value)

            def from_return(self, builder, value):
                return numba.cgutils.alloca_once_value(builder, value)

            def as_data(self, builder, value):
                return builder.load(value)

            def from_data(self, builder, value):
                return numba.cgutils.alloca_once_value(builder, value)

        return NumbaModel

    def _create_getattr_template(self):
        attrs = self.attrs

        class GetattrTemplate(numba.typing.templates.AttributeTemplate):
            key = self.NumbaType

            def generic_resolve(self, val, attr):
                if attr in attrs:
                    return attrs[attr]

        return GetattrTemplate

    def _call_get_function(self, builder, value, attr, is_embedded):
        attr_llvm_type = llvm_type_from_numba_type(self.attrs[attr])
        ret_type = attr_llvm_type if is_embedded else ptr(attr_llvm_type)
        fn = builder.module.get_or_insert_function(
            llvmlite.ir.FunctionType(ret_type, [self.llvm_ptr_type]),
            name=f"get_{self.name}_{attr}",
        )
        return_value = builder.call(fn, [value])
        return return_value

    def getattr_impl(self, context, builder, typ, value, attr):
        is_embedded = attr in self.embedded
        ret = self._call_get_function(builder, value, attr, is_embedded)
        return ret if is_embedded else builder.load(ret)

    def settattr_impl(self, context, builder, sig, args, attr):
        target, value = args
        is_embedded = attr in self.embedded
        builder.store(
            value=builder.load(value) if is_embedded else value,
            ptr=self._call_get_function(builder, target, attr, is_embedded),
        )

    def create_impl(self, typingctx, n_t=numba.types.Const(1)):
        if not isinstance(n_t, numba.types.Const):
            return

        def codegen(context, builder, sig, args):
            return numba.cgutils.alloca_once(builder, self.llvm_type, n_t.value)

        return self.numba_type(numba.types.int64), codegen

    def type_getitem(self, context):
        def typer(val_t, i_t):
            if val_t == self.numba_type and isinstance(i_t, numba.types.Integer):
                return self.numba_type

        return typer

    def lower_getitem(self, context, builder, sig, args):
        x, i = args
        return builder.gep(x, [i])

    def create_wrapper_numba_type(self):
        name = self.name
        numba_type = self.numba_type

        class WrapperNumbaType(numba.types.Type):
            def __init__(self, n):
                assert isinstance(n, ndtypes.ndt)
                self.ndt_value = n
                super().__init__(f"{name}Wrapper({n})")

            def can_convert_from(self, typingctx, other):
                """
                Support conversions from unwrapped to wrapped types implicitly.
                """
                if other == numba_type:
                    return numba.typeconv.Conversion.promote

        return WrapperNumbaType

    def wrap_impl(self, typingctx, inner_t, ndt_type_t):
        if inner_t != self.numba_type:
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

        sig = self.WrapperNumbaType(n)(self.numba_type, arg_type)

        def codegen(context, builder, sig, args):
            return args[0]

        return sig, codegen

    def unwrap_impl(self, typingctx, wrapper_t):
        if not isinstance(wrapper_t, self.WrapperNumbaType):
            return

        sig = self.numba_type(wrapper_t)

        def codegen(context, builder, sig, args):
            return args[0]

        return sig, codegen


def llvm_type_from_numba_type(numba_type):
    datamodel = numba.datamodel.registry.default_manager.lookup(numba_type)
    return datamodel.get_value_type()


def dispatcher_cres(dispatcher, sig):
    """
    Compiles the dispatcher for `sig` and return the resulting compilation result.
    """
    entry_point = dispatcher.compile(sig)
    return [
        cres
        for cres in dispatcher.overloads.values()
        if cres.entry_point == entry_point
    ][0]


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

        @numba.extending.type_callable(func)
        def type_inner(context):
            # need to pass in `dispatcher` or get "underlying object has vanished"
            def typer(*args, dispatcher=dispatcher):
                try:
                    cres = dispatcher_cres(dispatcher, args)
                except TypeError:  # None returned by overloaded function
                    return
                dispatcher.targetctx.insert_user_function(
                    func, cres.fndesc, [cres.library]
                )
                return cres.signature.return_type

            return typer

    return inner


class WrappedCFunction(numba.extending._Intrinsic):
    """
    Creates an intrinsic for a C function. Also exposes the underlying codegen, if you want
    to use that from a low level.
    """

    def __init__(
        self, func_name, numba_ret_type, numba_arg_types, accepts_return=False
    ):
        assert isinstance(numba_arg_types, tuple)
        for t in (numba_ret_type, *numba_arg_types):
            assert isinstance(t, numba.types.Type)

        self.func_name = func_name
        self.numba_ret_type = numba_ret_type
        self.numba_arg_types = numba_arg_types
        self.accepts_return = accepts_return
        self.sig = self.numba_ret_type(*self.numba_arg_types)

        self.ret_type = llvm_type_from_numba_type(self.numba_ret_type)
        self.arg_types = [llvm_type_from_numba_type(t) for t in self.numba_arg_types]

        # c functions that return struct values sometimes actually take in a pointer to that struct as the first argument
        if accepts_return:
            self.arg_types = (self.ret_type, *self.arg_types)
            self.ret_type = llvmlite.ir.VoidType()

        super().__init__(func_name, self.create_impl())
        self._register()

    def __str__(self):
        return f"{self.func_name}"

    def codegen(self, builder, args):
        if self.accepts_return:
            ret_ptr = builder.alloca(self.arg_types[0].pointee)
            args = (ret_ptr, *args)
        res = builder.call(
            builder.module.get_or_insert_function(
                llvmlite.ir.FunctionType(self.ret_type, self.arg_types),
                name=self.func_name,
            ),
            args,
        )
        if self.accepts_return:
            return ret_ptr
        return res

    def create_impl(self):
        def impl(typingctx, *numba_arg_types_):
            if numba_arg_types_ != self.numba_arg_types:
                return

            return (
                self.sig,
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
