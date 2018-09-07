import types

import llvmlite.ir

import numba.extending
import numba.types
import numba.typing.templates
import xnd_structinfo

from .extending import llvm_type_from_numba_type
from .llvm import char_ptr, i64, index, ptr

SIZEOF_MEMINFO = 20  # in bytes


class CStructModel(numba.datamodel.models.OpaqueModel):
    def contains_nrt_meminfo(self):
        return False

    def has_nrt_meminfo(self):
        return self.fe_type.nrt_allocated

    def get_nrt_meminfo(self, builder: llvmlite.ir.IRBuilder, value):
        """
        nrt meminfo pointer begins before the allocated data pointer. So we subtract size of meminfo to get to this pointer
        """
        # move back `SIZEOF_MEMINFO` bytes (since this is ptr(char))
        return builder.gep(value, [index(-SIZEOF_MEMINFO)])


class CStructType(numba.types.Type):
    """
    Creates a Numba type for the C struct called `c_name`

    It registers typing and lowering for it's attributes.
    `attrs` should be a dictionary mapping attribute names to the numba type of that attribute.

    `embedded` is a set of attribute names that actually are embedded in the struct instead of referenced.
    So if `hi` is an attribute that has a numba type with a data model of `some_other_thing*`, then if `hi`
    is in `embedded`, this struct has `some_other_thing` embedded in it, instead of a pointer to it.

    Supports `t.<field_name>(i)` for getting values and `t.<field_name>(i, val)` for setting values.
    """

    muatable = True

    def __init__(self, nrt_allocated):
        self.nrt_allocated = nrt_allocated
        super().__init__(name=f"CStruct({self.c_name}, {nrt_allocated})")

    def __init_subclass__(cls, c_name, attrs, embedded=tuple(), **kwargs):
        super().__init_subclass__(**kwargs)

        cls.c_name, cls.attrs, cls.embedded = c_name, attrs, embedded
        cls.n_bytes = getattr(xnd_structinfo, f"sizeof_{c_name}")()

        numba.extending.register_model(cls)(CStructModel)

        resolvers = {
            field: cls._type_and_lower_field(field, numba_type)
            for field, numba_type in attrs.items()
        }

        @numba.extending.infer_getattr
        class CStructTemplate(numba.typing.templates.AttributeTemplate):
            key = cls

            def resolve(self, value, attr):
                if attr in resolvers:
                    return resolvers[attr](self, value)

        cls.alloc = numba.extending.intrinsic(cls._alloc)

    @classmethod
    def _type_and_lower_field(cls, field: str, numba_type: numba.types.Type):
        # Validate input type
        if not isinstance(numba_type, numba.types.Type):
            raise TypeError(
                f"{cls.c_name}.{field}: {numba_type} should be an instance of a numba type"
            )

        # Type function
        fn_key = f"{cls.c_name}.{field}"

        @numba.typing.templates.bound_function(fn_key)
        def resolve(self, ty, args, kws):
            print("Trying", fn_key, ty, args, kws)
            if kws or not args or not isinstance(args[0], numba.types.Integer):
                return
            print("Resolved!")
            # getting value
            if len(args) == 1:
                return numba.typing.templates.signature(numba_type, *args)
            # setting value
            if len(args) == 2:  # and args[1] == numba_type:
                print(args)
                return numba.typing.templates.signature(
                    numba.types.none, args[0], numba_type
                )
            print("no resolved", len(args), args[1], numba_type)

        # Lower function
        @numba.targets.imputils.lower_builtin(fn_key, cls, numba.types.Integer)
        def lower_get(context, builder, sig, args):
            return cls.getattr_impl(builder, field, *args)

        @numba.targets.imputils.lower_builtin(
            fn_key, cls, numba.types.Integer, type(numba_type)
        )
        def lower_set(context, builder, sig, args):
            return cls.setattr_impl(builder, field, *args)

        return resolve

    @classmethod
    def _call_get_function(cls, builder, attr, struct, i, is_embedded):
        attr_llvm_type = llvm_type_from_numba_type(cls.attrs[attr])
        ret_type = attr_llvm_type if is_embedded else ptr(attr_llvm_type)
        return builder.call(
            builder.module.get_or_insert_function(
                llvmlite.ir.FunctionType(ret_type, [char_ptr]),
                name=f"get_{cls.c_name}_{attr}",
            ),
            [builder.gep(struct, [i])],
        )

    @classmethod
    def _alloc(cls, typingctx, n_t):
        if not isinstance(n_t, numba.types.Integer):
            return

        sig = cls(nrt_allocated=True)(n_t)

        def codegen(context, builder, sig, args):
            n, = args
            mi = context.nrt.meminfo_alloc(
                builder, size=builder.mul(n, i64(cls.n_bytes))
            )
            # move forward to data which is allocated after meminfo
            return builder.gep(mi, [index(SIZEOF_MEMINFO)])

        return sig, codegen

    @classmethod
    def getattr_impl(cls, builder, attr, struct, i):
        is_embedded = attr in cls.embedded
        ret = cls._call_get_function(builder, attr, struct, i, is_embedded)
        return ret if is_embedded else builder.load(ret)

    @classmethod
    def setattr_impl(cls, builder, attr, struct, i, value):
        is_embedded = attr in cls.embedded
        builder.store(
            value=builder.load(value) if is_embedded else value,
            ptr=cls._call_get_function(builder, attr, struct, i, is_embedded),
        )
