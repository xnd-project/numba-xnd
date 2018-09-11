/* This file is generated using structinfo_generator from the xndtools project */
#include "pyndtypes.h"
#include "pyxnd.h"
#include "pygumath.h"
#include "nrt.c"

extern PyObject* ndt_from_type(ndt_t* val) { return Ndt_FromType(val); }
extern PyObject* xnd_from_type_xnd(PyTypeObject* t, xnd_t* val) { return Xnd_FromXnd(t, val); };
extern PyObject* xnd_view_move_ndt(const PyObject *v, ndt_t *t) { return Xnd_ViewMoveNdt(v, t); };
extern PyObject* xnd_from_xnd_view(xnd_view_t *v) {return Xnd_FromXndView(v); };
extern void print_pointer(void* ptr){printf("%p\n", ptr);}
//extern PyObject* xnd_from_xndonly(xnd_t *val) { return Xnd_FromXndOnly(val); };
extern void print_bytes(const void *object, size_t size)
{
    // This is for C++; in C just drop the static_cast<>() and assign.
    const unsigned char *const bytes = object;
    size_t i;
    printf("Bytes: [ ");
    for (i = 0; i < size; i++)
    {
        printf("%lld ", (int64_t)bytes[i]);
    }
    printf("]\n");
    const int64_t *bytes2 = object;
    size_t i2;
    printf("Ints: [ ");
    for (i2 = 0; i2 < (size / 8); i2++)
    {
        printf("%lld ", bytes2[i2]);
    }
    printf("]\n\n");
}

extern size_t sizeof_char_opt_t(void){ return sizeof(char_opt_t); }
extern /* pointer to `enum ndt_option` */ void * get_char_opt_t_tag(void* ptr){ return &(((char_opt_t*)ptr)->tag); }
extern size_t offsetof_char_opt_t_tag(void){ return offsetof(char_opt_t, tag); }
extern /* pointer to `char` */ void * get_char_opt_t_Some(void* ptr){ return &(((char_opt_t*)ptr)->Some); }
extern size_t offsetof_char_opt_t_Some(void){ return offsetof(char_opt_t, Some); }
extern size_t sizeof_int64_opt_t(void){ return sizeof(int64_opt_t); }
extern /* pointer to `enum ndt_option` */ void * get_int64_opt_t_tag(void* ptr){ return &(((int64_opt_t*)ptr)->tag); }
extern size_t offsetof_int64_opt_t_tag(void){ return offsetof(int64_opt_t, tag); }
extern /* pointer to `int64_t` */ void * get_int64_opt_t_Some(void* ptr){ return &(((int64_opt_t*)ptr)->Some); }
extern size_t offsetof_int64_opt_t_Some(void){ return offsetof(int64_opt_t, Some); }
extern size_t sizeof_uint16_opt_t(void){ return sizeof(uint16_opt_t); }
extern /* pointer to `enum ndt_option` */ void * get_uint16_opt_t_tag(void* ptr){ return &(((uint16_opt_t*)ptr)->tag); }
extern size_t offsetof_uint16_opt_t_tag(void){ return offsetof(uint16_opt_t, tag); }
extern /* pointer to `uint16_t` */ void * get_uint16_opt_t_Some(void* ptr){ return &(((uint16_opt_t*)ptr)->Some); }
extern size_t offsetof_uint16_opt_t_Some(void){ return offsetof(uint16_opt_t, Some); }
extern size_t sizeof_ndt_meta_t(void){ return sizeof(ndt_meta_t); }
extern /* pointer to `int` */ void * get_ndt_meta_t_ndims(void* ptr){ return &(((ndt_meta_t*)ptr)->ndims); }
extern size_t offsetof_ndt_meta_t_ndims(void){ return offsetof(ndt_meta_t, ndims); }
extern /* pointer to `int32_t*` */ void * get_ndt_meta_t_noffsets(void* ptr){ return &(((ndt_meta_t*)ptr)->noffsets); }
extern size_t offsetof_ndt_meta_t_noffsets(void){ return offsetof(ndt_meta_t, noffsets); }
extern /* pointer to `int32_t**` */ void * get_ndt_meta_t_offsets(void* ptr){ return &(((ndt_meta_t*)ptr)->offsets); }
extern size_t offsetof_ndt_meta_t_offsets(void){ return offsetof(ndt_meta_t, offsets); }
extern size_t sizeof_ndt_field_t(void){ return sizeof(ndt_field_t); }
extern /* pointer to `enum ndt_access` */ void * get_ndt_field_t_access(void* ptr){ return &(((ndt_field_t*)ptr)->access); }
extern size_t offsetof_ndt_field_t_access(void){ return offsetof(ndt_field_t, access); }
extern /* pointer to `char*` */ void * get_ndt_field_t_name(void* ptr){ return &(((ndt_field_t*)ptr)->name); }
extern size_t offsetof_ndt_field_t_name(void){ return offsetof(ndt_field_t, name); }
extern /* pointer to `ndt_t*` */ void * get_ndt_field_t_type(void* ptr){ return &(((ndt_field_t*)ptr)->type); }
extern size_t offsetof_ndt_field_t_type(void){ return offsetof(ndt_field_t, type); }
extern /* pointer to `uint16_t` */ void * get_ndt_field_t_Concrete_align(void* ptr){ return &(((ndt_field_t*)ptr)->Concrete.align); }
extern size_t offsetof_ndt_field_t_Concrete_align(void){ return offsetof(ndt_field_t, Concrete.align); }
extern /* pointer to `bool` */ void * get_ndt_field_t_Concrete_explicit_align(void* ptr){ return &(((ndt_field_t*)ptr)->Concrete.explicit_align); }
extern size_t offsetof_ndt_field_t_Concrete_explicit_align(void){ return offsetof(ndt_field_t, Concrete.explicit_align); }
extern /* pointer to `uint16_t` */ void * get_ndt_field_t_Concrete_pad(void* ptr){ return &(((ndt_field_t*)ptr)->Concrete.pad); }
extern size_t offsetof_ndt_field_t_Concrete_pad(void){ return offsetof(ndt_field_t, Concrete.pad); }
extern /* pointer to `bool` */ void * get_ndt_field_t_Concrete_explicit_pad(void* ptr){ return &(((ndt_field_t*)ptr)->Concrete.explicit_pad); }
extern size_t offsetof_ndt_field_t_Concrete_explicit_pad(void){ return offsetof(ndt_field_t, Concrete.explicit_pad); }
extern size_t sizeof_ndt_value_t(void){ return sizeof(ndt_value_t); }
extern /* pointer to `enum ndt_value` */ void * get_ndt_value_t_tag(void* ptr){ return &(((ndt_value_t*)ptr)->tag); }
extern size_t offsetof_ndt_value_t_tag(void){ return offsetof(ndt_value_t, tag); }
extern /* pointer to `bool` */ void * get_ndt_value_t_ValBool(void* ptr){ return &(((ndt_value_t*)ptr)->ValBool); }
extern size_t offsetof_ndt_value_t_ValBool(void){ return offsetof(ndt_value_t, ValBool); }
extern /* pointer to `int64_t` */ void * get_ndt_value_t_ValInt64(void* ptr){ return &(((ndt_value_t*)ptr)->ValInt64); }
extern size_t offsetof_ndt_value_t_ValInt64(void){ return offsetof(ndt_value_t, ValInt64); }
extern /* pointer to `double` */ void * get_ndt_value_t_ValFloat64(void* ptr){ return &(((ndt_value_t*)ptr)->ValFloat64); }
extern size_t offsetof_ndt_value_t_ValFloat64(void){ return offsetof(ndt_value_t, ValFloat64); }
extern /* pointer to `char*` */ void * get_ndt_value_t_ValString(void* ptr){ return &(((ndt_value_t*)ptr)->ValString); }
extern size_t offsetof_ndt_value_t_ValString(void){ return offsetof(ndt_value_t, ValString); }
extern size_t sizeof_ndt_slice_t(void){ return sizeof(ndt_slice_t); }
extern /* pointer to `int64_t` */ void * get_ndt_slice_t_start(void* ptr){ return &(((ndt_slice_t*)ptr)->start); }
extern size_t offsetof_ndt_slice_t_start(void){ return offsetof(ndt_slice_t, start); }
extern /* pointer to `int64_t` */ void * get_ndt_slice_t_stop(void* ptr){ return &(((ndt_slice_t*)ptr)->stop); }
extern size_t offsetof_ndt_slice_t_stop(void){ return offsetof(ndt_slice_t, stop); }
extern /* pointer to `int64_t` */ void * get_ndt_slice_t_step(void* ptr){ return &(((ndt_slice_t*)ptr)->step); }
extern size_t offsetof_ndt_slice_t_step(void){ return offsetof(ndt_slice_t, step); }
extern size_t sizeof_ndt_constraint_t(void){ return sizeof(ndt_constraint_t); }
extern /* pointer to `ndt_func_constraint_t` */ void * get_ndt_constraint_t_f(void* ptr){ return &(((ndt_constraint_t*)ptr)->f); }
extern size_t offsetof_ndt_constraint_t_f(void){ return offsetof(ndt_constraint_t, f); }
extern /* pointer to `int` */ void * get_ndt_constraint_t_nin(void* ptr){ return &(((ndt_constraint_t*)ptr)->nin); }
extern size_t offsetof_ndt_constraint_t_nin(void){ return offsetof(ndt_constraint_t, nin); }
extern /* pointer to `int` */ void * get_ndt_constraint_t_nout(void* ptr){ return &(((ndt_constraint_t*)ptr)->nout); }
extern size_t offsetof_ndt_constraint_t_nout(void){ return offsetof(ndt_constraint_t, nout); }
extern /* pointer to `const char**` */ void * get_ndt_constraint_t_symbols(void* ptr){ return &(((ndt_constraint_t*)ptr)->symbols); }
extern size_t offsetof_ndt_constraint_t_symbols(void){ return offsetof(ndt_constraint_t, symbols); }
extern size_t sizeof_ndt_methods_t(void){ return sizeof(ndt_methods_t); }
extern /* pointer to `ndt_init_t` */ void * get_ndt_methods_t_init(void* ptr){ return &(((ndt_methods_t*)ptr)->init); }
extern size_t offsetof_ndt_methods_t_init(void){ return offsetof(ndt_methods_t, init); }
extern /* pointer to `ndt_tdef_constraint_t` */ void * get_ndt_methods_t_constraint(void* ptr){ return &(((ndt_methods_t*)ptr)->constraint); }
extern size_t offsetof_ndt_methods_t_constraint(void){ return offsetof(ndt_methods_t, constraint); }
extern /* pointer to `ndt_repr_t` */ void * get_ndt_methods_t_repr(void* ptr){ return &(((ndt_methods_t*)ptr)->repr); }
extern size_t offsetof_ndt_methods_t_repr(void){ return offsetof(ndt_methods_t, repr); }
extern size_t sizeof_ndt_t(void){ return sizeof(ndt_t); }
extern /* pointer to `enum ndt` */ void * get_ndt_t_tag(void* ptr){ return &(((ndt_t*)ptr)->tag); }
extern size_t offsetof_ndt_t_tag(void){ return offsetof(ndt_t, tag); }
extern /* pointer to `enum ndt_access` */ void * get_ndt_t_access(void* ptr){ return &(((ndt_t*)ptr)->access); }
extern size_t offsetof_ndt_t_access(void){ return offsetof(ndt_t, access); }
extern /* pointer to `uint32_t` */ void * get_ndt_t_flags(void* ptr){ return &(((ndt_t*)ptr)->flags); }
extern size_t offsetof_ndt_t_flags(void){ return offsetof(ndt_t, flags); }
extern /* pointer to `int` */ void * get_ndt_t_ndim(void* ptr){ return &(((ndt_t*)ptr)->ndim); }
extern size_t offsetof_ndt_t_ndim(void){ return offsetof(ndt_t, ndim); }
extern /* pointer to `int64_t` */ void * get_ndt_t_datasize(void* ptr){ return &(((ndt_t*)ptr)->datasize); }
extern size_t offsetof_ndt_t_datasize(void){ return offsetof(ndt_t, datasize); }
extern /* pointer to `uint16_t` */ void * get_ndt_t_align(void* ptr){ return &(((ndt_t*)ptr)->align); }
extern size_t offsetof_ndt_t_align(void){ return offsetof(ndt_t, align); }
extern /* pointer to `char*` */ void * get_ndt_t_Module_name(void* ptr){ return &(((ndt_t*)ptr)->Module.name); }
extern size_t offsetof_ndt_t_Module_name(void){ return offsetof(ndt_t, Module.name); }
extern /* pointer to `ndt_t*` */ void * get_ndt_t_Module_type(void* ptr){ return &(((ndt_t*)ptr)->Module.type); }
extern size_t offsetof_ndt_t_Module_type(void){ return offsetof(ndt_t, Module.type); }
extern /* pointer to `bool` */ void * get_ndt_t_Function_elemwise(void* ptr){ return &(((ndt_t*)ptr)->Function.elemwise); }
extern size_t offsetof_ndt_t_Function_elemwise(void){ return offsetof(ndt_t, Function.elemwise); }
extern /* pointer to `int64_t` */ void * get_ndt_t_Function_nin(void* ptr){ return &(((ndt_t*)ptr)->Function.nin); }
extern size_t offsetof_ndt_t_Function_nin(void){ return offsetof(ndt_t, Function.nin); }
extern /* pointer to `int64_t` */ void * get_ndt_t_Function_nout(void* ptr){ return &(((ndt_t*)ptr)->Function.nout); }
extern size_t offsetof_ndt_t_Function_nout(void){ return offsetof(ndt_t, Function.nout); }
extern /* pointer to `int64_t` */ void * get_ndt_t_Function_nargs(void* ptr){ return &(((ndt_t*)ptr)->Function.nargs); }
extern size_t offsetof_ndt_t_Function_nargs(void){ return offsetof(ndt_t, Function.nargs); }
extern /* pointer to `ndt_t**` */ void * get_ndt_t_Function_types(void* ptr){ return &(((ndt_t*)ptr)->Function.types); }
extern size_t offsetof_ndt_t_Function_types(void){ return offsetof(ndt_t, Function.types); }
extern /* pointer to `enum ndt_contig` */ void * get_ndt_t_FixedDim_tag(void* ptr){ return &(((ndt_t*)ptr)->FixedDim.tag); }
extern size_t offsetof_ndt_t_FixedDim_tag(void){ return offsetof(ndt_t, FixedDim.tag); }
extern /* pointer to `int64_t` */ void * get_ndt_t_FixedDim_shape(void* ptr){ return &(((ndt_t*)ptr)->FixedDim.shape); }
extern size_t offsetof_ndt_t_FixedDim_shape(void){ return offsetof(ndt_t, FixedDim.shape); }
extern /* pointer to `ndt_t*` */ void * get_ndt_t_FixedDim_type(void* ptr){ return &(((ndt_t*)ptr)->FixedDim.type); }
extern size_t offsetof_ndt_t_FixedDim_type(void){ return offsetof(ndt_t, FixedDim.type); }
extern /* pointer to `ndt_t*` */ void * get_ndt_t_VarDim_type(void* ptr){ return &(((ndt_t*)ptr)->VarDim.type); }
extern size_t offsetof_ndt_t_VarDim_type(void){ return offsetof(ndt_t, VarDim.type); }
extern /* pointer to `enum ndt_contig` */ void * get_ndt_t_SymbolicDim_tag(void* ptr){ return &(((ndt_t*)ptr)->SymbolicDim.tag); }
extern size_t offsetof_ndt_t_SymbolicDim_tag(void){ return offsetof(ndt_t, SymbolicDim.tag); }
extern /* pointer to `char*` */ void * get_ndt_t_SymbolicDim_name(void* ptr){ return &(((ndt_t*)ptr)->SymbolicDim.name); }
extern size_t offsetof_ndt_t_SymbolicDim_name(void){ return offsetof(ndt_t, SymbolicDim.name); }
extern /* pointer to `ndt_t*` */ void * get_ndt_t_SymbolicDim_type(void* ptr){ return &(((ndt_t*)ptr)->SymbolicDim.type); }
extern size_t offsetof_ndt_t_SymbolicDim_type(void){ return offsetof(ndt_t, SymbolicDim.type); }
extern /* pointer to `enum ndt_contig` */ void * get_ndt_t_EllipsisDim_tag(void* ptr){ return &(((ndt_t*)ptr)->EllipsisDim.tag); }
extern size_t offsetof_ndt_t_EllipsisDim_tag(void){ return offsetof(ndt_t, EllipsisDim.tag); }
extern /* pointer to `char*` */ void * get_ndt_t_EllipsisDim_name(void* ptr){ return &(((ndt_t*)ptr)->EllipsisDim.name); }
extern size_t offsetof_ndt_t_EllipsisDim_name(void){ return offsetof(ndt_t, EllipsisDim.name); }
extern /* pointer to `ndt_t*` */ void * get_ndt_t_EllipsisDim_type(void* ptr){ return &(((ndt_t*)ptr)->EllipsisDim.type); }
extern size_t offsetof_ndt_t_EllipsisDim_type(void){ return offsetof(ndt_t, EllipsisDim.type); }
extern /* pointer to `enum ndt_variadic` */ void * get_ndt_t_Tuple_flag(void* ptr){ return &(((ndt_t*)ptr)->Tuple.flag); }
extern size_t offsetof_ndt_t_Tuple_flag(void){ return offsetof(ndt_t, Tuple.flag); }
extern /* pointer to `int64_t` */ void * get_ndt_t_Tuple_shape(void* ptr){ return &(((ndt_t*)ptr)->Tuple.shape); }
extern size_t offsetof_ndt_t_Tuple_shape(void){ return offsetof(ndt_t, Tuple.shape); }
extern /* pointer to `ndt_t**` */ void * get_ndt_t_Tuple_types(void* ptr){ return &(((ndt_t*)ptr)->Tuple.types); }
extern size_t offsetof_ndt_t_Tuple_types(void){ return offsetof(ndt_t, Tuple.types); }
extern /* pointer to `enum ndt_variadic` */ void * get_ndt_t_Record_flag(void* ptr){ return &(((ndt_t*)ptr)->Record.flag); }
extern size_t offsetof_ndt_t_Record_flag(void){ return offsetof(ndt_t, Record.flag); }
extern /* pointer to `int64_t` */ void * get_ndt_t_Record_shape(void* ptr){ return &(((ndt_t*)ptr)->Record.shape); }
extern size_t offsetof_ndt_t_Record_shape(void){ return offsetof(ndt_t, Record.shape); }
extern /* pointer to `char**` */ void * get_ndt_t_Record_names(void* ptr){ return &(((ndt_t*)ptr)->Record.names); }
extern size_t offsetof_ndt_t_Record_names(void){ return offsetof(ndt_t, Record.names); }
extern /* pointer to `ndt_t**` */ void * get_ndt_t_Record_types(void* ptr){ return &(((ndt_t*)ptr)->Record.types); }
extern size_t offsetof_ndt_t_Record_types(void){ return offsetof(ndt_t, Record.types); }
extern /* pointer to `ndt_t*` */ void * get_ndt_t_Ref_type(void* ptr){ return &(((ndt_t*)ptr)->Ref.type); }
extern size_t offsetof_ndt_t_Ref_type(void){ return offsetof(ndt_t, Ref.type); }
extern /* pointer to `char*` */ void * get_ndt_t_Constr_name(void* ptr){ return &(((ndt_t*)ptr)->Constr.name); }
extern size_t offsetof_ndt_t_Constr_name(void){ return offsetof(ndt_t, Constr.name); }
extern /* pointer to `ndt_t*` */ void * get_ndt_t_Constr_type(void* ptr){ return &(((ndt_t*)ptr)->Constr.type); }
extern size_t offsetof_ndt_t_Constr_type(void){ return offsetof(ndt_t, Constr.type); }
extern /* pointer to `char*` */ void * get_ndt_t_Nominal_name(void* ptr){ return &(((ndt_t*)ptr)->Nominal.name); }
extern size_t offsetof_ndt_t_Nominal_name(void){ return offsetof(ndt_t, Nominal.name); }
extern /* pointer to `ndt_t*` */ void * get_ndt_t_Nominal_type(void* ptr){ return &(((ndt_t*)ptr)->Nominal.type); }
extern size_t offsetof_ndt_t_Nominal_type(void){ return offsetof(ndt_t, Nominal.type); }
extern /* pointer to `const ndt_methods_t*` */ void * get_ndt_t_Nominal_meth(void* ptr){ return &(((ndt_t*)ptr)->Nominal.meth); }
extern size_t offsetof_ndt_t_Nominal_meth(void){ return offsetof(ndt_t, Nominal.meth); }
extern /* pointer to `int64_t` */ void * get_ndt_t_Categorical_ntypes(void* ptr){ return &(((ndt_t*)ptr)->Categorical.ntypes); }
extern size_t offsetof_ndt_t_Categorical_ntypes(void){ return offsetof(ndt_t, Categorical.ntypes); }
extern /* pointer to `ndt_value_t*` */ void * get_ndt_t_Categorical_types(void* ptr){ return &(((ndt_t*)ptr)->Categorical.types); }
extern size_t offsetof_ndt_t_Categorical_types(void){ return offsetof(ndt_t, Categorical.types); }
extern /* pointer to `int64_t` */ void * get_ndt_t_FixedString_size(void* ptr){ return &(((ndt_t*)ptr)->FixedString.size); }
extern size_t offsetof_ndt_t_FixedString_size(void){ return offsetof(ndt_t, FixedString.size); }
extern /* pointer to `enum ndt_encoding` */ void * get_ndt_t_FixedString_encoding(void* ptr){ return &(((ndt_t*)ptr)->FixedString.encoding); }
extern size_t offsetof_ndt_t_FixedString_encoding(void){ return offsetof(ndt_t, FixedString.encoding); }
extern /* pointer to `int64_t` */ void * get_ndt_t_FixedBytes_size(void* ptr){ return &(((ndt_t*)ptr)->FixedBytes.size); }
extern size_t offsetof_ndt_t_FixedBytes_size(void){ return offsetof(ndt_t, FixedBytes.size); }
extern /* pointer to `uint16_t` */ void * get_ndt_t_FixedBytes_align(void* ptr){ return &(((ndt_t*)ptr)->FixedBytes.align); }
extern size_t offsetof_ndt_t_FixedBytes_align(void){ return offsetof(ndt_t, FixedBytes.align); }
extern /* pointer to `uint16_t` */ void * get_ndt_t_Bytes_target_align(void* ptr){ return &(((ndt_t*)ptr)->Bytes.target_align); }
extern size_t offsetof_ndt_t_Bytes_target_align(void){ return offsetof(ndt_t, Bytes.target_align); }
extern /* pointer to `enum ndt_encoding` */ void * get_ndt_t_Char_encoding(void* ptr){ return &(((ndt_t*)ptr)->Char.encoding); }
extern size_t offsetof_ndt_t_Char_encoding(void){ return offsetof(ndt_t, Char.encoding); }
extern /* pointer to `char*` */ void * get_ndt_t_Typevar_name(void* ptr){ return &(((ndt_t*)ptr)->Typevar.name); }
extern size_t offsetof_ndt_t_Typevar_name(void){ return offsetof(ndt_t, Typevar.name); }
extern /* pointer to `int64_t` */ void * get_ndt_t_Concrete_FixedDim_itemsize(void* ptr){ return &(((ndt_t*)ptr)->Concrete.FixedDim.itemsize); }
extern size_t offsetof_ndt_t_Concrete_FixedDim_itemsize(void){ return offsetof(ndt_t, Concrete.FixedDim.itemsize); }
extern /* pointer to `int64_t` */ void * get_ndt_t_Concrete_FixedDim_step(void* ptr){ return &(((ndt_t*)ptr)->Concrete.FixedDim.step); }
extern size_t offsetof_ndt_t_Concrete_FixedDim_step(void){ return offsetof(ndt_t, Concrete.FixedDim.step); }
extern /* pointer to `enum ndt_offsets` */ void * get_ndt_t_Concrete_VarDim_flag(void* ptr){ return &(((ndt_t*)ptr)->Concrete.VarDim.flag); }
extern size_t offsetof_ndt_t_Concrete_VarDim_flag(void){ return offsetof(ndt_t, Concrete.VarDim.flag); }
extern /* pointer to `int64_t` */ void * get_ndt_t_Concrete_VarDim_itemsize(void* ptr){ return &(((ndt_t*)ptr)->Concrete.VarDim.itemsize); }
extern size_t offsetof_ndt_t_Concrete_VarDim_itemsize(void){ return offsetof(ndt_t, Concrete.VarDim.itemsize); }
extern /* pointer to `int32_t` */ void * get_ndt_t_Concrete_VarDim_noffsets(void* ptr){ return &(((ndt_t*)ptr)->Concrete.VarDim.noffsets); }
extern size_t offsetof_ndt_t_Concrete_VarDim_noffsets(void){ return offsetof(ndt_t, Concrete.VarDim.noffsets); }
extern /* pointer to `const int32_t*` */ void * get_ndt_t_Concrete_VarDim_offsets(void* ptr){ return &(((ndt_t*)ptr)->Concrete.VarDim.offsets); }
extern size_t offsetof_ndt_t_Concrete_VarDim_offsets(void){ return offsetof(ndt_t, Concrete.VarDim.offsets); }
extern /* pointer to `int` */ void * get_ndt_t_Concrete_VarDim_nslices(void* ptr){ return &(((ndt_t*)ptr)->Concrete.VarDim.nslices); }
extern size_t offsetof_ndt_t_Concrete_VarDim_nslices(void){ return offsetof(ndt_t, Concrete.VarDim.nslices); }
extern /* pointer to `ndt_slice_t*` */ void * get_ndt_t_Concrete_VarDim_slices(void* ptr){ return &(((ndt_t*)ptr)->Concrete.VarDim.slices); }
extern size_t offsetof_ndt_t_Concrete_VarDim_slices(void){ return offsetof(ndt_t, Concrete.VarDim.slices); }
extern /* pointer to `int64_t*` */ void * get_ndt_t_Concrete_Tuple_offset(void* ptr){ return &(((ndt_t*)ptr)->Concrete.Tuple.offset); }
extern size_t offsetof_ndt_t_Concrete_Tuple_offset(void){ return offsetof(ndt_t, Concrete.Tuple.offset); }
extern /* pointer to `uint16_t*` */ void * get_ndt_t_Concrete_Tuple_align(void* ptr){ return &(((ndt_t*)ptr)->Concrete.Tuple.align); }
extern size_t offsetof_ndt_t_Concrete_Tuple_align(void){ return offsetof(ndt_t, Concrete.Tuple.align); }
extern /* pointer to `uint16_t*` */ void * get_ndt_t_Concrete_Tuple_pad(void* ptr){ return &(((ndt_t*)ptr)->Concrete.Tuple.pad); }
extern size_t offsetof_ndt_t_Concrete_Tuple_pad(void){ return offsetof(ndt_t, Concrete.Tuple.pad); }
extern /* pointer to `int64_t*` */ void * get_ndt_t_Concrete_Record_offset(void* ptr){ return &(((ndt_t*)ptr)->Concrete.Record.offset); }
extern size_t offsetof_ndt_t_Concrete_Record_offset(void){ return offsetof(ndt_t, Concrete.Record.offset); }
extern /* pointer to `uint16_t*` */ void * get_ndt_t_Concrete_Record_align(void* ptr){ return &(((ndt_t*)ptr)->Concrete.Record.align); }
extern size_t offsetof_ndt_t_Concrete_Record_align(void){ return offsetof(ndt_t, Concrete.Record.align); }
extern /* pointer to `uint16_t*` */ void * get_ndt_t_Concrete_Record_pad(void* ptr){ return &(((ndt_t*)ptr)->Concrete.Record.pad); }
extern size_t offsetof_ndt_t_Concrete_Record_pad(void){ return offsetof(ndt_t, Concrete.Record.pad); }
extern /* pointer to `char*` */ void * get_ndt_t_extra(void* ptr){ return &(((ndt_t*)ptr)->extra); }
extern size_t offsetof_ndt_t_extra(void){ return offsetof(ndt_t, extra); }
extern size_t sizeof_ndt_context_t(void){ return sizeof(ndt_context_t); }
extern /* pointer to `uint32_t` */ void * get_ndt_context_t_flags(void* ptr){ return &(((ndt_context_t*)ptr)->flags); }
extern size_t offsetof_ndt_context_t_flags(void){ return offsetof(ndt_context_t, flags); }
extern /* pointer to `enum ndt_error` */ void * get_ndt_context_t_err(void* ptr){ return &(((ndt_context_t*)ptr)->err); }
extern size_t offsetof_ndt_context_t_err(void){ return offsetof(ndt_context_t, err); }
extern /* pointer to `enum ndt_msg` */ void * get_ndt_context_t_msg(void* ptr){ return &(((ndt_context_t*)ptr)->msg); }
extern size_t offsetof_ndt_context_t_msg(void){ return offsetof(ndt_context_t, msg); }
extern /* pointer to `const char*` */ void * get_ndt_context_t_ConstMsg(void* ptr){ return &(((ndt_context_t*)ptr)->ConstMsg); }
extern size_t offsetof_ndt_context_t_ConstMsg(void){ return offsetof(ndt_context_t, ConstMsg); }
extern /* pointer to `char*` */ void * get_ndt_context_t_DynamicMsg(void* ptr){ return &(((ndt_context_t*)ptr)->DynamicMsg); }
extern size_t offsetof_ndt_context_t_DynamicMsg(void){ return offsetof(ndt_context_t, DynamicMsg); }
extern size_t sizeof_ndt_ndarray_t(void){ return sizeof(ndt_ndarray_t); }
extern /* pointer to `int` */ void * get_ndt_ndarray_t_ndim(void* ptr){ return &(((ndt_ndarray_t*)ptr)->ndim); }
extern size_t offsetof_ndt_ndarray_t_ndim(void){ return offsetof(ndt_ndarray_t, ndim); }
extern /* pointer to `int64_t` */ void * get_ndt_ndarray_t_itemsize(void* ptr){ return &(((ndt_ndarray_t*)ptr)->itemsize); }
extern size_t offsetof_ndt_ndarray_t_itemsize(void){ return offsetof(ndt_ndarray_t, itemsize); }
extern /* pointer to `int64_t*` */ void * get_ndt_ndarray_t_shape(void* ptr){ return &(((ndt_ndarray_t*)ptr)->shape); }
extern size_t offsetof_ndt_ndarray_t_shape(void){ return offsetof(ndt_ndarray_t, shape); }
extern /* pointer to `int64_t*` */ void * get_ndt_ndarray_t_strides(void* ptr){ return &(((ndt_ndarray_t*)ptr)->strides); }
extern size_t offsetof_ndt_ndarray_t_strides(void){ return offsetof(ndt_ndarray_t, strides); }
extern /* pointer to `int64_t*` */ void * get_ndt_ndarray_t_steps(void* ptr){ return &(((ndt_ndarray_t*)ptr)->steps); }
extern size_t offsetof_ndt_ndarray_t_steps(void){ return offsetof(ndt_ndarray_t, steps); }
extern size_t sizeof_ndt_apply_spec_t(void){ return sizeof(ndt_apply_spec_t); }
extern /* pointer to `uint32_t` */ void * get_ndt_apply_spec_t_flags(void* ptr){ return &(((ndt_apply_spec_t*)ptr)->flags); }
extern size_t offsetof_ndt_apply_spec_t_flags(void){ return offsetof(ndt_apply_spec_t, flags); }
extern /* pointer to `int` */ void * get_ndt_apply_spec_t_nout(void* ptr){ return &(((ndt_apply_spec_t*)ptr)->nout); }
extern size_t offsetof_ndt_apply_spec_t_nout(void){ return offsetof(ndt_apply_spec_t, nout); }
extern /* pointer to `int` */ void * get_ndt_apply_spec_t_nbroadcast(void* ptr){ return &(((ndt_apply_spec_t*)ptr)->nbroadcast); }
extern size_t offsetof_ndt_apply_spec_t_nbroadcast(void){ return offsetof(ndt_apply_spec_t, nbroadcast); }
extern /* pointer to `int` */ void * get_ndt_apply_spec_t_outer_dims(void* ptr){ return &(((ndt_apply_spec_t*)ptr)->outer_dims); }
extern size_t offsetof_ndt_apply_spec_t_outer_dims(void){ return offsetof(ndt_apply_spec_t, outer_dims); }
extern /* pointer to `ndt_t**` */ void * get_ndt_apply_spec_t_out(void* ptr){ return &(((ndt_apply_spec_t*)ptr)->out); }
extern size_t offsetof_ndt_apply_spec_t_out(void){ return offsetof(ndt_apply_spec_t, out); }
extern /* pointer to `ndt_t**` */ void * get_ndt_apply_spec_t_broadcast(void* ptr){ return &(((ndt_apply_spec_t*)ptr)->broadcast); }
extern size_t offsetof_ndt_apply_spec_t_broadcast(void){ return offsetof(ndt_apply_spec_t, broadcast); }
extern size_t sizeof_ndt_typedef_t(void){ return sizeof(ndt_typedef_t); }
extern /* pointer to `const ndt_t*` */ void * get_ndt_typedef_t_type(void* ptr){ return &(((ndt_typedef_t*)ptr)->type); }
extern size_t offsetof_ndt_typedef_t_type(void){ return offsetof(ndt_typedef_t, type); }
extern /* pointer to `ndt_methods_t` */ void * get_ndt_typedef_t_meth(void* ptr){ return &(((ndt_typedef_t*)ptr)->meth); }
extern size_t offsetof_ndt_typedef_t_meth(void){ return offsetof(ndt_typedef_t, meth); }
extern size_t sizeof_ndt_bytes_t(void){ return sizeof(ndt_bytes_t); }
extern /* pointer to `int64_t` */ void * get_ndt_bytes_t_size(void* ptr){ return &(((ndt_bytes_t*)ptr)->size); }
extern size_t offsetof_ndt_bytes_t_size(void){ return offsetof(ndt_bytes_t, size); }
extern /* pointer to `uint8_t*` */ void * get_ndt_bytes_t_data(void* ptr){ return &(((ndt_bytes_t*)ptr)->data); }
extern size_t offsetof_ndt_bytes_t_data(void){ return offsetof(ndt_bytes_t, data); }
extern size_t sizeof_NdtObject(void){ return sizeof(NdtObject); }
extern /* pointer to `PyObject*` */ void * get_NdtObject_rbuf(void* ptr){ return &(((NdtObject*)ptr)->rbuf); }
extern size_t offsetof_NdtObject_rbuf(void){ return offsetof(NdtObject, rbuf); }
extern /* pointer to `ndt_t*` */ void * get_NdtObject_ndt(void* ptr){ return &(((NdtObject*)ptr)->ndt); }
extern size_t offsetof_NdtObject_ndt(void){ return offsetof(NdtObject, ndt); }
extern size_t sizeof_xnd_bitmap_t(void){ return sizeof(xnd_bitmap_t); }
extern /* pointer to `uint8_t*` */ void * get_xnd_bitmap_t_data(void* ptr){ return &(((xnd_bitmap_t*)ptr)->data); }
extern size_t offsetof_xnd_bitmap_t_data(void){ return offsetof(xnd_bitmap_t, data); }
extern /* pointer to `int64_t` */ void * get_xnd_bitmap_t_size(void* ptr){ return &(((xnd_bitmap_t*)ptr)->size); }
extern size_t offsetof_xnd_bitmap_t_size(void){ return offsetof(xnd_bitmap_t, size); }
extern /* pointer to `xnd_bitmap_t*` */ void * get_xnd_bitmap_t_next(void* ptr){ return &(((xnd_bitmap_t*)ptr)->next); }
extern size_t offsetof_xnd_bitmap_t_next(void){ return offsetof(xnd_bitmap_t, next); }
extern size_t sizeof_xnd_t(void){ return sizeof(xnd_t); }
extern /* pointer to `xnd_bitmap_t` */ void * get_xnd_t_bitmap(void* ptr){ return &(((xnd_t*)ptr)->bitmap); }
extern size_t offsetof_xnd_t_bitmap(void){ return offsetof(xnd_t, bitmap); }
extern /* pointer to `int64_t` */ void * get_xnd_t_index(void* ptr){ return &(((xnd_t*)ptr)->index); }
extern size_t offsetof_xnd_t_index(void){ return offsetof(xnd_t, index); }
extern /* pointer to `const ndt_t*` */ void * get_xnd_t_type(void* ptr){ return &(((xnd_t*)ptr)->type); }
extern size_t offsetof_xnd_t_type(void){ return offsetof(xnd_t, type); }
extern /* pointer to `char*` */ void * get_xnd_t_ptr(void* ptr){ return &(((xnd_t*)ptr)->ptr); }
extern size_t offsetof_xnd_t_ptr(void){ return offsetof(xnd_t, ptr); }
extern size_t sizeof_xnd_master_t(void){ return sizeof(xnd_master_t); }
extern /* pointer to `uint32_t` */ void * get_xnd_master_t_flags(void* ptr){ return &(((xnd_master_t*)ptr)->flags); }
extern size_t offsetof_xnd_master_t_flags(void){ return offsetof(xnd_master_t, flags); }
extern /* pointer to `xnd_t` */ void * get_xnd_master_t_master(void* ptr){ return &(((xnd_master_t*)ptr)->master); }
extern size_t offsetof_xnd_master_t_master(void){ return offsetof(xnd_master_t, master); }
extern size_t sizeof_xnd_index_t(void){ return sizeof(xnd_index_t); }
extern /* pointer to `enum xnd_key` */ void * get_xnd_index_t_tag(void* ptr){ return &(((xnd_index_t*)ptr)->tag); }
extern size_t offsetof_xnd_index_t_tag(void){ return offsetof(xnd_index_t, tag); }
extern /* pointer to `int64_t` */ void * get_xnd_index_t_Index(void* ptr){ return &(((xnd_index_t*)ptr)->Index); }
extern size_t offsetof_xnd_index_t_Index(void){ return offsetof(xnd_index_t, Index); }
extern /* pointer to `const char*` */ void * get_xnd_index_t_FieldName(void* ptr){ return &(((xnd_index_t*)ptr)->FieldName); }
extern size_t offsetof_xnd_index_t_FieldName(void){ return offsetof(xnd_index_t, FieldName); }
extern /* pointer to `ndt_slice_t` */ void * get_xnd_index_t_Slice(void* ptr){ return &(((xnd_index_t*)ptr)->Slice); }
extern size_t offsetof_xnd_index_t_Slice(void){ return offsetof(xnd_index_t, Slice); }
extern size_t sizeof_xnd_view_t(void){ return sizeof(xnd_view_t); }
extern /* pointer to `uint32_t` */ void * get_xnd_view_t_flags(void* ptr){ return &(((xnd_view_t*)ptr)->flags); }
extern size_t offsetof_xnd_view_t_flags(void){ return offsetof(xnd_view_t, flags); }
extern /* pointer to `const void*` */ void * get_xnd_view_t_obj(void* ptr){ return &(((xnd_view_t*)ptr)->obj); }
extern size_t offsetof_xnd_view_t_obj(void){ return offsetof(xnd_view_t, obj); }
extern /* pointer to `xnd_t` */ void * get_xnd_view_t_view(void* ptr){ return &(((xnd_view_t*)ptr)->view); }
extern size_t offsetof_xnd_view_t_view(void){ return offsetof(xnd_view_t, view); }
extern size_t sizeof_MemoryBlockObject(void){ return sizeof(MemoryBlockObject); }
extern /* pointer to `PyObject*` */ void * get_MemoryBlockObject_type(void* ptr){ return &(((MemoryBlockObject*)ptr)->type); }
extern size_t offsetof_MemoryBlockObject_type(void){ return offsetof(MemoryBlockObject, type); }
extern /* pointer to `xnd_master_t*` */ void * get_MemoryBlockObject_xnd(void* ptr){ return &(((MemoryBlockObject*)ptr)->xnd); }
extern size_t offsetof_MemoryBlockObject_xnd(void){ return offsetof(MemoryBlockObject, xnd); }
extern /* pointer to `Py_buffer*` */ void * get_MemoryBlockObject_view(void* ptr){ return &(((MemoryBlockObject*)ptr)->view); }
extern size_t offsetof_MemoryBlockObject_view(void){ return offsetof(MemoryBlockObject, view); }
extern size_t sizeof_XndObject(void){ return sizeof(XndObject); }
extern /* pointer to `MemoryBlockObject*` */ void * get_XndObject_mblock(void* ptr){ return &(((XndObject*)ptr)->mblock); }
extern size_t offsetof_XndObject_mblock(void){ return offsetof(XndObject, mblock); }
extern /* pointer to `PyObject*` */ void * get_XndObject_type(void* ptr){ return &(((XndObject*)ptr)->type); }
extern size_t offsetof_XndObject_type(void){ return offsetof(XndObject, type); }
extern /* pointer to `xnd_t` */ void * get_XndObject_xnd(void* ptr){ return &(((XndObject*)ptr)->xnd); }
extern size_t offsetof_XndObject_xnd(void){ return offsetof(XndObject, xnd); }
extern size_t sizeof_gm_kernel_set_t(void){ return sizeof(gm_kernel_set_t); }
extern /* pointer to `ndt_t*` */ void * get_gm_kernel_set_t_sig(void* ptr){ return &(((gm_kernel_set_t*)ptr)->sig); }
extern size_t offsetof_gm_kernel_set_t_sig(void){ return offsetof(gm_kernel_set_t, sig); }
extern /* pointer to `const ndt_constraint_t*` */ void * get_gm_kernel_set_t_constraint(void* ptr){ return &(((gm_kernel_set_t*)ptr)->constraint); }
extern size_t offsetof_gm_kernel_set_t_constraint(void){ return offsetof(gm_kernel_set_t, constraint); }
extern /* pointer to `gm_xnd_kernel_t` */ void * get_gm_kernel_set_t_Opt(void* ptr){ return &(((gm_kernel_set_t*)ptr)->Opt); }
extern size_t offsetof_gm_kernel_set_t_Opt(void){ return offsetof(gm_kernel_set_t, Opt); }
extern /* pointer to `gm_xnd_kernel_t` */ void * get_gm_kernel_set_t_C(void* ptr){ return &(((gm_kernel_set_t*)ptr)->C); }
extern size_t offsetof_gm_kernel_set_t_C(void){ return offsetof(gm_kernel_set_t, C); }
extern /* pointer to `gm_xnd_kernel_t` */ void * get_gm_kernel_set_t_Fortran(void* ptr){ return &(((gm_kernel_set_t*)ptr)->Fortran); }
extern size_t offsetof_gm_kernel_set_t_Fortran(void){ return offsetof(gm_kernel_set_t, Fortran); }
extern /* pointer to `gm_xnd_kernel_t` */ void * get_gm_kernel_set_t_Xnd(void* ptr){ return &(((gm_kernel_set_t*)ptr)->Xnd); }
extern size_t offsetof_gm_kernel_set_t_Xnd(void){ return offsetof(gm_kernel_set_t, Xnd); }
extern /* pointer to `gm_strided_kernel_t` */ void * get_gm_kernel_set_t_Strided(void* ptr){ return &(((gm_kernel_set_t*)ptr)->Strided); }
extern size_t offsetof_gm_kernel_set_t_Strided(void){ return offsetof(gm_kernel_set_t, Strided); }
extern size_t sizeof_gm_typedef_init_t(void){ return sizeof(gm_typedef_init_t); }
extern /* pointer to `const char*` */ void * get_gm_typedef_init_t_name(void* ptr){ return &(((gm_typedef_init_t*)ptr)->name); }
extern size_t offsetof_gm_typedef_init_t_name(void){ return offsetof(gm_typedef_init_t, name); }
extern /* pointer to `const char*` */ void * get_gm_typedef_init_t_type(void* ptr){ return &(((gm_typedef_init_t*)ptr)->type); }
extern size_t offsetof_gm_typedef_init_t_type(void){ return offsetof(gm_typedef_init_t, type); }
extern /* pointer to `const ndt_methods_t*` */ void * get_gm_typedef_init_t_meth(void* ptr){ return &(((gm_typedef_init_t*)ptr)->meth); }
extern size_t offsetof_gm_typedef_init_t_meth(void){ return offsetof(gm_typedef_init_t, meth); }
extern size_t sizeof_gm_kernel_init_t(void){ return sizeof(gm_kernel_init_t); }
extern /* pointer to `const char*` */ void * get_gm_kernel_init_t_name(void* ptr){ return &(((gm_kernel_init_t*)ptr)->name); }
extern size_t offsetof_gm_kernel_init_t_name(void){ return offsetof(gm_kernel_init_t, name); }
extern /* pointer to `const char*` */ void * get_gm_kernel_init_t_sig(void* ptr){ return &(((gm_kernel_init_t*)ptr)->sig); }
extern size_t offsetof_gm_kernel_init_t_sig(void){ return offsetof(gm_kernel_init_t, sig); }
extern /* pointer to `const ndt_constraint_t*` */ void * get_gm_kernel_init_t_constraint(void* ptr){ return &(((gm_kernel_init_t*)ptr)->constraint); }
extern size_t offsetof_gm_kernel_init_t_constraint(void){ return offsetof(gm_kernel_init_t, constraint); }
extern /* pointer to `gm_xnd_kernel_t` */ void * get_gm_kernel_init_t_Opt(void* ptr){ return &(((gm_kernel_init_t*)ptr)->Opt); }
extern size_t offsetof_gm_kernel_init_t_Opt(void){ return offsetof(gm_kernel_init_t, Opt); }
extern /* pointer to `gm_xnd_kernel_t` */ void * get_gm_kernel_init_t_C(void* ptr){ return &(((gm_kernel_init_t*)ptr)->C); }
extern size_t offsetof_gm_kernel_init_t_C(void){ return offsetof(gm_kernel_init_t, C); }
extern /* pointer to `gm_xnd_kernel_t` */ void * get_gm_kernel_init_t_Fortran(void* ptr){ return &(((gm_kernel_init_t*)ptr)->Fortran); }
extern size_t offsetof_gm_kernel_init_t_Fortran(void){ return offsetof(gm_kernel_init_t, Fortran); }
extern /* pointer to `gm_xnd_kernel_t` */ void * get_gm_kernel_init_t_Xnd(void* ptr){ return &(((gm_kernel_init_t*)ptr)->Xnd); }
extern size_t offsetof_gm_kernel_init_t_Xnd(void){ return offsetof(gm_kernel_init_t, Xnd); }
extern /* pointer to `gm_strided_kernel_t` */ void * get_gm_kernel_init_t_Strided(void* ptr){ return &(((gm_kernel_init_t*)ptr)->Strided); }
extern size_t offsetof_gm_kernel_init_t_Strided(void){ return offsetof(gm_kernel_init_t, Strided); }
extern size_t sizeof_gm_kernel_t(void){ return sizeof(gm_kernel_t); }
extern /* pointer to `uint32_t` */ void * get_gm_kernel_t_flag(void* ptr){ return &(((gm_kernel_t*)ptr)->flag); }
extern size_t offsetof_gm_kernel_t_flag(void){ return offsetof(gm_kernel_t, flag); }
extern /* pointer to `const gm_kernel_set_t*` */ void * get_gm_kernel_t_set(void* ptr){ return &(((gm_kernel_t*)ptr)->set); }
extern size_t offsetof_gm_kernel_t_set(void){ return offsetof(gm_kernel_t, set); }
extern size_t sizeof_gm_func_t(void){ return sizeof(gm_func_t); }
extern /* pointer to `char*` */ void * get_gm_func_t_name(void* ptr){ return &(((gm_func_t*)ptr)->name); }
extern size_t offsetof_gm_func_t_name(void){ return offsetof(gm_func_t, name); }
extern /* pointer to `gm_typecheck_t` */ void * get_gm_func_t_typecheck(void* ptr){ return &(((gm_func_t*)ptr)->typecheck); }
extern size_t offsetof_gm_func_t_typecheck(void){ return offsetof(gm_func_t, typecheck); }
extern /* pointer to `int` */ void * get_gm_func_t_nkernels(void* ptr){ return &(((gm_func_t*)ptr)->nkernels); }
extern size_t offsetof_gm_func_t_nkernels(void){ return offsetof(gm_func_t, nkernels); }
extern /* pointer to `gm_kernel_set_t*` */ void * get_gm_func_t_kernels(void* ptr){ return &(((gm_func_t*)ptr)->kernels); }
extern size_t offsetof_gm_func_t_kernels(void){ return offsetof(gm_func_t, kernels); }
extern size_t sizeof_GufuncObject(void){ return sizeof(GufuncObject); }
extern /* pointer to `const gm_tbl_t*` */ void * get_GufuncObject_tbl(void* ptr){ return &(((GufuncObject*)ptr)->tbl); }
extern size_t offsetof_GufuncObject_tbl(void){ return offsetof(GufuncObject, tbl); }
extern /* pointer to `char*` */ void * get_GufuncObject_name(void* ptr){ return &(((GufuncObject*)ptr)->name); }
extern size_t offsetof_GufuncObject_name(void){ return offsetof(GufuncObject, name); }
extern size_t sizeof_NRT_MemInfo(void){ return sizeof(NRT_MemInfo); }
extern /* pointer to `size_t` */ void * get_NRT_MemInfo_refct(void* ptr){ return &(((NRT_MemInfo*)ptr)->refct); }
extern size_t offsetof_NRT_MemInfo_refct(void){ return offsetof(NRT_MemInfo, refct); }
extern /* pointer to `NRT_dtor_function` */ void * get_NRT_MemInfo_dtor(void* ptr){ return &(((NRT_MemInfo*)ptr)->dtor); }
extern size_t offsetof_NRT_MemInfo_dtor(void){ return offsetof(NRT_MemInfo, dtor); }
extern /* pointer to `void*` */ void * get_NRT_MemInfo_dtor_info(void* ptr){ return &(((NRT_MemInfo*)ptr)->dtor_info); }
extern size_t offsetof_NRT_MemInfo_dtor_info(void){ return offsetof(NRT_MemInfo, dtor_info); }
extern /* pointer to `void*` */ void * get_NRT_MemInfo_data(void* ptr){ return &(((NRT_MemInfo*)ptr)->data); }
extern size_t offsetof_NRT_MemInfo_data(void){ return offsetof(NRT_MemInfo, data); }
extern /* pointer to `size_t` */ void * get_NRT_MemInfo_size(void* ptr){ return &(((NRT_MemInfo*)ptr)->size); }
extern size_t offsetof_NRT_MemInfo_size(void){ return offsetof(NRT_MemInfo, size); }
extern size_t sizeof_NRT_MemSys(void){ return sizeof(NRT_MemSys); }
extern /* pointer to `NRT_atomic_inc_dec_func atomic_inc,` */ void * get_NRT_MemSys_atomic_dec(void* ptr){ return &(((NRT_MemSys*)ptr)->atomic_dec); }
extern size_t offsetof_NRT_MemSys_atomic_dec(void){ return offsetof(NRT_MemSys, atomic_dec); }
extern /* pointer to `atomic_meminfo_cas_func` */ void * get_NRT_MemSys_atomic_cas(void* ptr){ return &(((NRT_MemSys*)ptr)->atomic_cas); }
extern size_t offsetof_NRT_MemSys_atomic_cas(void){ return offsetof(NRT_MemSys, atomic_cas); }
extern /* pointer to `int` */ void * get_NRT_MemSys_shutting(void* ptr){ return &(((NRT_MemSys*)ptr)->shutting); }
extern size_t offsetof_NRT_MemSys_shutting(void){ return offsetof(NRT_MemSys, shutting); }
extern /* pointer to `size_t stats_alloc,stats_free,stats_mi_alloc,` */ void * get_NRT_MemSys_stats_mi_free(void* ptr){ return &(((NRT_MemSys*)ptr)->stats_mi_free); }
extern size_t offsetof_NRT_MemSys_stats_mi_free(void){ return offsetof(NRT_MemSys, stats_mi_free); }
extern /* pointer to `NRT_malloc_func` */ void * get_NRT_MemSys_allocator_malloc(void* ptr){ return &(((NRT_MemSys*)ptr)->allocator.malloc); }
extern size_t offsetof_NRT_MemSys_allocator_malloc(void){ return offsetof(NRT_MemSys, allocator.malloc); }
extern /* pointer to `NRT_realloc_func` */ void * get_NRT_MemSys_allocator_realloc(void* ptr){ return &(((NRT_MemSys*)ptr)->allocator.realloc); }
extern size_t offsetof_NRT_MemSys_allocator_realloc(void){ return offsetof(NRT_MemSys, allocator.realloc); }
extern /* pointer to `NRT_free_func` */ void * get_NRT_MemSys_allocator_free(void* ptr){ return &(((NRT_MemSys*)ptr)->allocator.free); }
extern size_t offsetof_NRT_MemSys_allocator_free(void){ return offsetof(NRT_MemSys, allocator.free); }
#ifdef PYTHON_MODULE
#include "Python.h"


static PyObject *pyc_sizeof_char_opt_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_char_opt_t())); }
static PyObject *pyc_get_char_opt_t_tag(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "char_opt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_char_opt_t_tag(PyCapsule_GetPointer(ptr, "char_opt_t*")), "enum ndt_option", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted char_opt_t");
  return NULL;
}
static PyObject *pyc_offsetof_char_opt_t_tag(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_char_opt_t_tag())); }
static PyObject *pyc_get_char_opt_t_Some(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "char_opt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_char_opt_t_Some(PyCapsule_GetPointer(ptr, "char_opt_t*")), "char", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted char_opt_t");
  return NULL;
}
static PyObject *pyc_offsetof_char_opt_t_Some(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_char_opt_t_Some())); }
static PyObject *pyc_sizeof_int64_opt_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_int64_opt_t())); }
static PyObject *pyc_get_int64_opt_t_tag(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "int64_opt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_int64_opt_t_tag(PyCapsule_GetPointer(ptr, "int64_opt_t*")), "enum ndt_option", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted int64_opt_t");
  return NULL;
}
static PyObject *pyc_offsetof_int64_opt_t_tag(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_int64_opt_t_tag())); }
static PyObject *pyc_get_int64_opt_t_Some(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "int64_opt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_int64_opt_t_Some(PyCapsule_GetPointer(ptr, "int64_opt_t*")), "int64_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted int64_opt_t");
  return NULL;
}
static PyObject *pyc_offsetof_int64_opt_t_Some(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_int64_opt_t_Some())); }
static PyObject *pyc_sizeof_uint16_opt_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_uint16_opt_t())); }
static PyObject *pyc_get_uint16_opt_t_tag(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "uint16_opt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_uint16_opt_t_tag(PyCapsule_GetPointer(ptr, "uint16_opt_t*")), "enum ndt_option", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted uint16_opt_t");
  return NULL;
}
static PyObject *pyc_offsetof_uint16_opt_t_tag(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_uint16_opt_t_tag())); }
static PyObject *pyc_get_uint16_opt_t_Some(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "uint16_opt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_uint16_opt_t_Some(PyCapsule_GetPointer(ptr, "uint16_opt_t*")), "uint16_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted uint16_opt_t");
  return NULL;
}
static PyObject *pyc_offsetof_uint16_opt_t_Some(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_uint16_opt_t_Some())); }
static PyObject *pyc_sizeof_ndt_meta_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_ndt_meta_t())); }
static PyObject *pyc_get_ndt_meta_t_ndims(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_meta_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_meta_t_ndims(PyCapsule_GetPointer(ptr, "ndt_meta_t*")), "int", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_meta_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_meta_t_ndims(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_meta_t_ndims())); }
static PyObject *pyc_get_ndt_meta_t_noffsets(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_meta_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_meta_t_noffsets(PyCapsule_GetPointer(ptr, "ndt_meta_t*")), "int32_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_meta_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_meta_t_noffsets(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_meta_t_noffsets())); }
static PyObject *pyc_get_ndt_meta_t_offsets(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_meta_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_meta_t_offsets(PyCapsule_GetPointer(ptr, "ndt_meta_t*")), "int32_t**", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_meta_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_meta_t_offsets(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_meta_t_offsets())); }
static PyObject *pyc_sizeof_ndt_field_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_ndt_field_t())); }
static PyObject *pyc_get_ndt_field_t_access(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_field_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_field_t_access(PyCapsule_GetPointer(ptr, "ndt_field_t*")), "enum ndt_access", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_field_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_field_t_access(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_field_t_access())); }
static PyObject *pyc_get_ndt_field_t_name(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_field_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_field_t_name(PyCapsule_GetPointer(ptr, "ndt_field_t*")), "char*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_field_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_field_t_name(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_field_t_name())); }
static PyObject *pyc_get_ndt_field_t_type(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_field_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_field_t_type(PyCapsule_GetPointer(ptr, "ndt_field_t*")), "ndt_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_field_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_field_t_type(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_field_t_type())); }
static PyObject *pyc_get_ndt_field_t_Concrete_align(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_field_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_field_t_Concrete_align(PyCapsule_GetPointer(ptr, "ndt_field_t*")), "uint16_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_field_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_field_t_Concrete_align(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_field_t_Concrete_align())); }
static PyObject *pyc_get_ndt_field_t_Concrete_explicit_align(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_field_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_field_t_Concrete_explicit_align(PyCapsule_GetPointer(ptr, "ndt_field_t*")), "bool", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_field_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_field_t_Concrete_explicit_align(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_field_t_Concrete_explicit_align())); }
static PyObject *pyc_get_ndt_field_t_Concrete_pad(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_field_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_field_t_Concrete_pad(PyCapsule_GetPointer(ptr, "ndt_field_t*")), "uint16_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_field_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_field_t_Concrete_pad(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_field_t_Concrete_pad())); }
static PyObject *pyc_get_ndt_field_t_Concrete_explicit_pad(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_field_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_field_t_Concrete_explicit_pad(PyCapsule_GetPointer(ptr, "ndt_field_t*")), "bool", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_field_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_field_t_Concrete_explicit_pad(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_field_t_Concrete_explicit_pad())); }
static PyObject *pyc_sizeof_ndt_value_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_ndt_value_t())); }
static PyObject *pyc_get_ndt_value_t_tag(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_value_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_value_t_tag(PyCapsule_GetPointer(ptr, "ndt_value_t*")), "enum ndt_value", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_value_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_value_t_tag(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_value_t_tag())); }
static PyObject *pyc_get_ndt_value_t_ValBool(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_value_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_value_t_ValBool(PyCapsule_GetPointer(ptr, "ndt_value_t*")), "bool", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_value_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_value_t_ValBool(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_value_t_ValBool())); }
static PyObject *pyc_get_ndt_value_t_ValInt64(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_value_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_value_t_ValInt64(PyCapsule_GetPointer(ptr, "ndt_value_t*")), "int64_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_value_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_value_t_ValInt64(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_value_t_ValInt64())); }
static PyObject *pyc_get_ndt_value_t_ValFloat64(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_value_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_value_t_ValFloat64(PyCapsule_GetPointer(ptr, "ndt_value_t*")), "double", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_value_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_value_t_ValFloat64(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_value_t_ValFloat64())); }
static PyObject *pyc_get_ndt_value_t_ValString(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_value_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_value_t_ValString(PyCapsule_GetPointer(ptr, "ndt_value_t*")), "char*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_value_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_value_t_ValString(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_value_t_ValString())); }
static PyObject *pyc_sizeof_ndt_slice_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_ndt_slice_t())); }
static PyObject *pyc_get_ndt_slice_t_start(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_slice_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_slice_t_start(PyCapsule_GetPointer(ptr, "ndt_slice_t*")), "int64_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_slice_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_slice_t_start(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_slice_t_start())); }
static PyObject *pyc_get_ndt_slice_t_stop(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_slice_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_slice_t_stop(PyCapsule_GetPointer(ptr, "ndt_slice_t*")), "int64_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_slice_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_slice_t_stop(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_slice_t_stop())); }
static PyObject *pyc_get_ndt_slice_t_step(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_slice_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_slice_t_step(PyCapsule_GetPointer(ptr, "ndt_slice_t*")), "int64_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_slice_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_slice_t_step(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_slice_t_step())); }
static PyObject *pyc_sizeof_ndt_constraint_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_ndt_constraint_t())); }
static PyObject *pyc_get_ndt_constraint_t_f(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_constraint_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_constraint_t_f(PyCapsule_GetPointer(ptr, "ndt_constraint_t*")), "ndt_func_constraint_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_constraint_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_constraint_t_f(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_constraint_t_f())); }
static PyObject *pyc_get_ndt_constraint_t_nin(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_constraint_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_constraint_t_nin(PyCapsule_GetPointer(ptr, "ndt_constraint_t*")), "int", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_constraint_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_constraint_t_nin(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_constraint_t_nin())); }
static PyObject *pyc_get_ndt_constraint_t_nout(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_constraint_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_constraint_t_nout(PyCapsule_GetPointer(ptr, "ndt_constraint_t*")), "int", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_constraint_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_constraint_t_nout(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_constraint_t_nout())); }
static PyObject *pyc_get_ndt_constraint_t_symbols(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_constraint_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_constraint_t_symbols(PyCapsule_GetPointer(ptr, "ndt_constraint_t*")), "const char**", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_constraint_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_constraint_t_symbols(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_constraint_t_symbols())); }
static PyObject *pyc_sizeof_ndt_methods_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_ndt_methods_t())); }
static PyObject *pyc_get_ndt_methods_t_init(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_methods_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_methods_t_init(PyCapsule_GetPointer(ptr, "ndt_methods_t*")), "ndt_init_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_methods_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_methods_t_init(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_methods_t_init())); }
static PyObject *pyc_get_ndt_methods_t_constraint(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_methods_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_methods_t_constraint(PyCapsule_GetPointer(ptr, "ndt_methods_t*")), "ndt_tdef_constraint_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_methods_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_methods_t_constraint(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_methods_t_constraint())); }
static PyObject *pyc_get_ndt_methods_t_repr(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_methods_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_methods_t_repr(PyCapsule_GetPointer(ptr, "ndt_methods_t*")), "ndt_repr_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_methods_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_methods_t_repr(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_methods_t_repr())); }
static PyObject *pyc_sizeof_ndt_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_ndt_t())); }
static PyObject *pyc_get_ndt_t_tag(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_tag(PyCapsule_GetPointer(ptr, "ndt_t*")), "enum ndt", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_tag(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_tag())); }
static PyObject *pyc_get_ndt_t_access(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_access(PyCapsule_GetPointer(ptr, "ndt_t*")), "enum ndt_access", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_access(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_access())); }
static PyObject *pyc_get_ndt_t_flags(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_flags(PyCapsule_GetPointer(ptr, "ndt_t*")), "uint32_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_flags(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_flags())); }
static PyObject *pyc_get_ndt_t_ndim(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_ndim(PyCapsule_GetPointer(ptr, "ndt_t*")), "int", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_ndim(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_ndim())); }
static PyObject *pyc_get_ndt_t_datasize(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_datasize(PyCapsule_GetPointer(ptr, "ndt_t*")), "int64_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_datasize(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_datasize())); }
static PyObject *pyc_get_ndt_t_align(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_align(PyCapsule_GetPointer(ptr, "ndt_t*")), "uint16_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_align(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_align())); }
static PyObject *pyc_get_ndt_t_Module_name(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Module_name(PyCapsule_GetPointer(ptr, "ndt_t*")), "char*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Module_name(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Module_name())); }
static PyObject *pyc_get_ndt_t_Module_type(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Module_type(PyCapsule_GetPointer(ptr, "ndt_t*")), "ndt_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Module_type(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Module_type())); }
static PyObject *pyc_get_ndt_t_Function_elemwise(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Function_elemwise(PyCapsule_GetPointer(ptr, "ndt_t*")), "bool", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Function_elemwise(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Function_elemwise())); }
static PyObject *pyc_get_ndt_t_Function_nin(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Function_nin(PyCapsule_GetPointer(ptr, "ndt_t*")), "int64_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Function_nin(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Function_nin())); }
static PyObject *pyc_get_ndt_t_Function_nout(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Function_nout(PyCapsule_GetPointer(ptr, "ndt_t*")), "int64_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Function_nout(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Function_nout())); }
static PyObject *pyc_get_ndt_t_Function_nargs(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Function_nargs(PyCapsule_GetPointer(ptr, "ndt_t*")), "int64_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Function_nargs(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Function_nargs())); }
static PyObject *pyc_get_ndt_t_Function_types(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Function_types(PyCapsule_GetPointer(ptr, "ndt_t*")), "ndt_t**", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Function_types(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Function_types())); }
static PyObject *pyc_get_ndt_t_FixedDim_tag(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_FixedDim_tag(PyCapsule_GetPointer(ptr, "ndt_t*")), "enum ndt_contig", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_FixedDim_tag(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_FixedDim_tag())); }
static PyObject *pyc_get_ndt_t_FixedDim_shape(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_FixedDim_shape(PyCapsule_GetPointer(ptr, "ndt_t*")), "int64_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_FixedDim_shape(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_FixedDim_shape())); }
static PyObject *pyc_get_ndt_t_FixedDim_type(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_FixedDim_type(PyCapsule_GetPointer(ptr, "ndt_t*")), "ndt_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_FixedDim_type(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_FixedDim_type())); }
static PyObject *pyc_get_ndt_t_VarDim_type(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_VarDim_type(PyCapsule_GetPointer(ptr, "ndt_t*")), "ndt_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_VarDim_type(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_VarDim_type())); }
static PyObject *pyc_get_ndt_t_SymbolicDim_tag(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_SymbolicDim_tag(PyCapsule_GetPointer(ptr, "ndt_t*")), "enum ndt_contig", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_SymbolicDim_tag(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_SymbolicDim_tag())); }
static PyObject *pyc_get_ndt_t_SymbolicDim_name(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_SymbolicDim_name(PyCapsule_GetPointer(ptr, "ndt_t*")), "char*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_SymbolicDim_name(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_SymbolicDim_name())); }
static PyObject *pyc_get_ndt_t_SymbolicDim_type(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_SymbolicDim_type(PyCapsule_GetPointer(ptr, "ndt_t*")), "ndt_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_SymbolicDim_type(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_SymbolicDim_type())); }
static PyObject *pyc_get_ndt_t_EllipsisDim_tag(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_EllipsisDim_tag(PyCapsule_GetPointer(ptr, "ndt_t*")), "enum ndt_contig", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_EllipsisDim_tag(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_EllipsisDim_tag())); }
static PyObject *pyc_get_ndt_t_EllipsisDim_name(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_EllipsisDim_name(PyCapsule_GetPointer(ptr, "ndt_t*")), "char*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_EllipsisDim_name(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_EllipsisDim_name())); }
static PyObject *pyc_get_ndt_t_EllipsisDim_type(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_EllipsisDim_type(PyCapsule_GetPointer(ptr, "ndt_t*")), "ndt_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_EllipsisDim_type(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_EllipsisDim_type())); }
static PyObject *pyc_get_ndt_t_Tuple_flag(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Tuple_flag(PyCapsule_GetPointer(ptr, "ndt_t*")), "enum ndt_variadic", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Tuple_flag(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Tuple_flag())); }
static PyObject *pyc_get_ndt_t_Tuple_shape(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Tuple_shape(PyCapsule_GetPointer(ptr, "ndt_t*")), "int64_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Tuple_shape(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Tuple_shape())); }
static PyObject *pyc_get_ndt_t_Tuple_types(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Tuple_types(PyCapsule_GetPointer(ptr, "ndt_t*")), "ndt_t**", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Tuple_types(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Tuple_types())); }
static PyObject *pyc_get_ndt_t_Record_flag(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Record_flag(PyCapsule_GetPointer(ptr, "ndt_t*")), "enum ndt_variadic", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Record_flag(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Record_flag())); }
static PyObject *pyc_get_ndt_t_Record_shape(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Record_shape(PyCapsule_GetPointer(ptr, "ndt_t*")), "int64_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Record_shape(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Record_shape())); }
static PyObject *pyc_get_ndt_t_Record_names(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Record_names(PyCapsule_GetPointer(ptr, "ndt_t*")), "char**", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Record_names(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Record_names())); }
static PyObject *pyc_get_ndt_t_Record_types(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Record_types(PyCapsule_GetPointer(ptr, "ndt_t*")), "ndt_t**", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Record_types(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Record_types())); }
static PyObject *pyc_get_ndt_t_Ref_type(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Ref_type(PyCapsule_GetPointer(ptr, "ndt_t*")), "ndt_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Ref_type(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Ref_type())); }
static PyObject *pyc_get_ndt_t_Constr_name(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Constr_name(PyCapsule_GetPointer(ptr, "ndt_t*")), "char*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Constr_name(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Constr_name())); }
static PyObject *pyc_get_ndt_t_Constr_type(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Constr_type(PyCapsule_GetPointer(ptr, "ndt_t*")), "ndt_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Constr_type(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Constr_type())); }
static PyObject *pyc_get_ndt_t_Nominal_name(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Nominal_name(PyCapsule_GetPointer(ptr, "ndt_t*")), "char*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Nominal_name(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Nominal_name())); }
static PyObject *pyc_get_ndt_t_Nominal_type(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Nominal_type(PyCapsule_GetPointer(ptr, "ndt_t*")), "ndt_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Nominal_type(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Nominal_type())); }
static PyObject *pyc_get_ndt_t_Nominal_meth(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Nominal_meth(PyCapsule_GetPointer(ptr, "ndt_t*")), "const ndt_methods_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Nominal_meth(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Nominal_meth())); }
static PyObject *pyc_get_ndt_t_Categorical_ntypes(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Categorical_ntypes(PyCapsule_GetPointer(ptr, "ndt_t*")), "int64_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Categorical_ntypes(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Categorical_ntypes())); }
static PyObject *pyc_get_ndt_t_Categorical_types(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Categorical_types(PyCapsule_GetPointer(ptr, "ndt_t*")), "ndt_value_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Categorical_types(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Categorical_types())); }
static PyObject *pyc_get_ndt_t_FixedString_size(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_FixedString_size(PyCapsule_GetPointer(ptr, "ndt_t*")), "int64_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_FixedString_size(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_FixedString_size())); }
static PyObject *pyc_get_ndt_t_FixedString_encoding(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_FixedString_encoding(PyCapsule_GetPointer(ptr, "ndt_t*")), "enum ndt_encoding", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_FixedString_encoding(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_FixedString_encoding())); }
static PyObject *pyc_get_ndt_t_FixedBytes_size(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_FixedBytes_size(PyCapsule_GetPointer(ptr, "ndt_t*")), "int64_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_FixedBytes_size(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_FixedBytes_size())); }
static PyObject *pyc_get_ndt_t_FixedBytes_align(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_FixedBytes_align(PyCapsule_GetPointer(ptr, "ndt_t*")), "uint16_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_FixedBytes_align(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_FixedBytes_align())); }
static PyObject *pyc_get_ndt_t_Bytes_target_align(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Bytes_target_align(PyCapsule_GetPointer(ptr, "ndt_t*")), "uint16_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Bytes_target_align(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Bytes_target_align())); }
static PyObject *pyc_get_ndt_t_Char_encoding(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Char_encoding(PyCapsule_GetPointer(ptr, "ndt_t*")), "enum ndt_encoding", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Char_encoding(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Char_encoding())); }
static PyObject *pyc_get_ndt_t_Typevar_name(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Typevar_name(PyCapsule_GetPointer(ptr, "ndt_t*")), "char*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Typevar_name(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Typevar_name())); }
static PyObject *pyc_get_ndt_t_Concrete_FixedDim_itemsize(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Concrete_FixedDim_itemsize(PyCapsule_GetPointer(ptr, "ndt_t*")), "int64_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Concrete_FixedDim_itemsize(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Concrete_FixedDim_itemsize())); }
static PyObject *pyc_get_ndt_t_Concrete_FixedDim_step(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Concrete_FixedDim_step(PyCapsule_GetPointer(ptr, "ndt_t*")), "int64_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Concrete_FixedDim_step(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Concrete_FixedDim_step())); }
static PyObject *pyc_get_ndt_t_Concrete_VarDim_flag(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Concrete_VarDim_flag(PyCapsule_GetPointer(ptr, "ndt_t*")), "enum ndt_offsets", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Concrete_VarDim_flag(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Concrete_VarDim_flag())); }
static PyObject *pyc_get_ndt_t_Concrete_VarDim_itemsize(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Concrete_VarDim_itemsize(PyCapsule_GetPointer(ptr, "ndt_t*")), "int64_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Concrete_VarDim_itemsize(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Concrete_VarDim_itemsize())); }
static PyObject *pyc_get_ndt_t_Concrete_VarDim_noffsets(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Concrete_VarDim_noffsets(PyCapsule_GetPointer(ptr, "ndt_t*")), "int32_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Concrete_VarDim_noffsets(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Concrete_VarDim_noffsets())); }
static PyObject *pyc_get_ndt_t_Concrete_VarDim_offsets(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Concrete_VarDim_offsets(PyCapsule_GetPointer(ptr, "ndt_t*")), "const int32_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Concrete_VarDim_offsets(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Concrete_VarDim_offsets())); }
static PyObject *pyc_get_ndt_t_Concrete_VarDim_nslices(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Concrete_VarDim_nslices(PyCapsule_GetPointer(ptr, "ndt_t*")), "int", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Concrete_VarDim_nslices(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Concrete_VarDim_nslices())); }
static PyObject *pyc_get_ndt_t_Concrete_VarDim_slices(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Concrete_VarDim_slices(PyCapsule_GetPointer(ptr, "ndt_t*")), "ndt_slice_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Concrete_VarDim_slices(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Concrete_VarDim_slices())); }
static PyObject *pyc_get_ndt_t_Concrete_Tuple_offset(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Concrete_Tuple_offset(PyCapsule_GetPointer(ptr, "ndt_t*")), "int64_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Concrete_Tuple_offset(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Concrete_Tuple_offset())); }
static PyObject *pyc_get_ndt_t_Concrete_Tuple_align(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Concrete_Tuple_align(PyCapsule_GetPointer(ptr, "ndt_t*")), "uint16_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Concrete_Tuple_align(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Concrete_Tuple_align())); }
static PyObject *pyc_get_ndt_t_Concrete_Tuple_pad(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Concrete_Tuple_pad(PyCapsule_GetPointer(ptr, "ndt_t*")), "uint16_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Concrete_Tuple_pad(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Concrete_Tuple_pad())); }
static PyObject *pyc_get_ndt_t_Concrete_Record_offset(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Concrete_Record_offset(PyCapsule_GetPointer(ptr, "ndt_t*")), "int64_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Concrete_Record_offset(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Concrete_Record_offset())); }
static PyObject *pyc_get_ndt_t_Concrete_Record_align(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Concrete_Record_align(PyCapsule_GetPointer(ptr, "ndt_t*")), "uint16_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Concrete_Record_align(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Concrete_Record_align())); }
static PyObject *pyc_get_ndt_t_Concrete_Record_pad(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_Concrete_Record_pad(PyCapsule_GetPointer(ptr, "ndt_t*")), "uint16_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_Concrete_Record_pad(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_Concrete_Record_pad())); }
static PyObject *pyc_get_ndt_t_extra(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_t_extra(PyCapsule_GetPointer(ptr, "ndt_t*")), "char*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_t_extra(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_t_extra())); }
static PyObject *pyc_sizeof_ndt_context_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_ndt_context_t())); }
static PyObject *pyc_get_ndt_context_t_flags(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_context_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_context_t_flags(PyCapsule_GetPointer(ptr, "ndt_context_t*")), "uint32_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_context_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_context_t_flags(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_context_t_flags())); }
static PyObject *pyc_get_ndt_context_t_err(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_context_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_context_t_err(PyCapsule_GetPointer(ptr, "ndt_context_t*")), "enum ndt_error", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_context_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_context_t_err(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_context_t_err())); }
static PyObject *pyc_get_ndt_context_t_msg(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_context_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_context_t_msg(PyCapsule_GetPointer(ptr, "ndt_context_t*")), "enum ndt_msg", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_context_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_context_t_msg(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_context_t_msg())); }
static PyObject *pyc_get_ndt_context_t_ConstMsg(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_context_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_context_t_ConstMsg(PyCapsule_GetPointer(ptr, "ndt_context_t*")), "const char*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_context_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_context_t_ConstMsg(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_context_t_ConstMsg())); }
static PyObject *pyc_get_ndt_context_t_DynamicMsg(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_context_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_context_t_DynamicMsg(PyCapsule_GetPointer(ptr, "ndt_context_t*")), "char*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_context_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_context_t_DynamicMsg(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_context_t_DynamicMsg())); }
static PyObject *pyc_sizeof_ndt_ndarray_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_ndt_ndarray_t())); }
static PyObject *pyc_get_ndt_ndarray_t_ndim(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_ndarray_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_ndarray_t_ndim(PyCapsule_GetPointer(ptr, "ndt_ndarray_t*")), "int", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_ndarray_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_ndarray_t_ndim(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_ndarray_t_ndim())); }
static PyObject *pyc_get_ndt_ndarray_t_itemsize(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_ndarray_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_ndarray_t_itemsize(PyCapsule_GetPointer(ptr, "ndt_ndarray_t*")), "int64_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_ndarray_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_ndarray_t_itemsize(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_ndarray_t_itemsize())); }
static PyObject *pyc_get_ndt_ndarray_t_shape(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_ndarray_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_ndarray_t_shape(PyCapsule_GetPointer(ptr, "ndt_ndarray_t*")), "int64_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_ndarray_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_ndarray_t_shape(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_ndarray_t_shape())); }
static PyObject *pyc_get_ndt_ndarray_t_strides(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_ndarray_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_ndarray_t_strides(PyCapsule_GetPointer(ptr, "ndt_ndarray_t*")), "int64_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_ndarray_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_ndarray_t_strides(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_ndarray_t_strides())); }
static PyObject *pyc_get_ndt_ndarray_t_steps(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_ndarray_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_ndarray_t_steps(PyCapsule_GetPointer(ptr, "ndt_ndarray_t*")), "int64_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_ndarray_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_ndarray_t_steps(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_ndarray_t_steps())); }
static PyObject *pyc_sizeof_ndt_apply_spec_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_ndt_apply_spec_t())); }
static PyObject *pyc_get_ndt_apply_spec_t_flags(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_apply_spec_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_apply_spec_t_flags(PyCapsule_GetPointer(ptr, "ndt_apply_spec_t*")), "uint32_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_apply_spec_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_apply_spec_t_flags(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_apply_spec_t_flags())); }
static PyObject *pyc_get_ndt_apply_spec_t_nout(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_apply_spec_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_apply_spec_t_nout(PyCapsule_GetPointer(ptr, "ndt_apply_spec_t*")), "int", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_apply_spec_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_apply_spec_t_nout(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_apply_spec_t_nout())); }
static PyObject *pyc_get_ndt_apply_spec_t_nbroadcast(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_apply_spec_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_apply_spec_t_nbroadcast(PyCapsule_GetPointer(ptr, "ndt_apply_spec_t*")), "int", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_apply_spec_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_apply_spec_t_nbroadcast(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_apply_spec_t_nbroadcast())); }
static PyObject *pyc_get_ndt_apply_spec_t_outer_dims(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_apply_spec_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_apply_spec_t_outer_dims(PyCapsule_GetPointer(ptr, "ndt_apply_spec_t*")), "int", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_apply_spec_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_apply_spec_t_outer_dims(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_apply_spec_t_outer_dims())); }
static PyObject *pyc_get_ndt_apply_spec_t_out(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_apply_spec_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_apply_spec_t_out(PyCapsule_GetPointer(ptr, "ndt_apply_spec_t*")), "ndt_t**", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_apply_spec_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_apply_spec_t_out(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_apply_spec_t_out())); }
static PyObject *pyc_get_ndt_apply_spec_t_broadcast(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_apply_spec_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_apply_spec_t_broadcast(PyCapsule_GetPointer(ptr, "ndt_apply_spec_t*")), "ndt_t**", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_apply_spec_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_apply_spec_t_broadcast(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_apply_spec_t_broadcast())); }
static PyObject *pyc_sizeof_ndt_typedef_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_ndt_typedef_t())); }
static PyObject *pyc_get_ndt_typedef_t_type(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_typedef_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_typedef_t_type(PyCapsule_GetPointer(ptr, "ndt_typedef_t*")), "const ndt_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_typedef_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_typedef_t_type(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_typedef_t_type())); }
static PyObject *pyc_get_ndt_typedef_t_meth(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_typedef_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_typedef_t_meth(PyCapsule_GetPointer(ptr, "ndt_typedef_t*")), "ndt_methods_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_typedef_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_typedef_t_meth(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_typedef_t_meth())); }
static PyObject *pyc_sizeof_ndt_bytes_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_ndt_bytes_t())); }
static PyObject *pyc_get_ndt_bytes_t_size(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_bytes_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_bytes_t_size(PyCapsule_GetPointer(ptr, "ndt_bytes_t*")), "int64_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_bytes_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_bytes_t_size(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_bytes_t_size())); }
static PyObject *pyc_get_ndt_bytes_t_data(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "ndt_bytes_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_ndt_bytes_t_data(PyCapsule_GetPointer(ptr, "ndt_bytes_t*")), "uint8_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted ndt_bytes_t");
  return NULL;
}
static PyObject *pyc_offsetof_ndt_bytes_t_data(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_ndt_bytes_t_data())); }
static PyObject *pyc_capsulate_NdtObject(PyObject *self, PyObject *args) {
  PyObject* obj=NULL;
  if (!PyArg_UnpackTuple(args, "NdtObject_instance", 0, 1, &obj))
    return NULL;
  if (Ndt_CheckExact(obj)) {
    Py_INCREF(obj);
    return PyCapsule_New(obj, "NdtObject*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected NdtObject instance");
  return NULL;
}
static PyObject *pyc_sizeof_NdtObject(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_NdtObject())); }
static PyObject *pyc_get_NdtObject_rbuf(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "NdtObject", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_NdtObject_rbuf(PyCapsule_GetPointer(ptr, "NdtObject*")), "PyObject*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted NdtObject");
  return NULL;
}
static PyObject *pyc_offsetof_NdtObject_rbuf(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_NdtObject_rbuf())); }
static PyObject *pyc_get_NdtObject_ndt(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "NdtObject", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_NdtObject_ndt(PyCapsule_GetPointer(ptr, "NdtObject*")), "ndt_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted NdtObject");
  return NULL;
}
static PyObject *pyc_offsetof_NdtObject_ndt(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_NdtObject_ndt())); }
static PyObject *pyc_sizeof_xnd_bitmap_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_xnd_bitmap_t())); }
static PyObject *pyc_get_xnd_bitmap_t_data(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "xnd_bitmap_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_xnd_bitmap_t_data(PyCapsule_GetPointer(ptr, "xnd_bitmap_t*")), "uint8_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted xnd_bitmap_t");
  return NULL;
}
static PyObject *pyc_offsetof_xnd_bitmap_t_data(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_xnd_bitmap_t_data())); }
static PyObject *pyc_get_xnd_bitmap_t_size(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "xnd_bitmap_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_xnd_bitmap_t_size(PyCapsule_GetPointer(ptr, "xnd_bitmap_t*")), "int64_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted xnd_bitmap_t");
  return NULL;
}
static PyObject *pyc_offsetof_xnd_bitmap_t_size(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_xnd_bitmap_t_size())); }
static PyObject *pyc_get_xnd_bitmap_t_next(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "xnd_bitmap_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_xnd_bitmap_t_next(PyCapsule_GetPointer(ptr, "xnd_bitmap_t*")), "xnd_bitmap_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted xnd_bitmap_t");
  return NULL;
}
static PyObject *pyc_offsetof_xnd_bitmap_t_next(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_xnd_bitmap_t_next())); }
static PyObject *pyc_sizeof_xnd_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_xnd_t())); }
static PyObject *pyc_get_xnd_t_bitmap(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "xnd_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_xnd_t_bitmap(PyCapsule_GetPointer(ptr, "xnd_t*")), "xnd_bitmap_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted xnd_t");
  return NULL;
}
static PyObject *pyc_offsetof_xnd_t_bitmap(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_xnd_t_bitmap())); }
static PyObject *pyc_get_xnd_t_index(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "xnd_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_xnd_t_index(PyCapsule_GetPointer(ptr, "xnd_t*")), "int64_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted xnd_t");
  return NULL;
}
static PyObject *pyc_offsetof_xnd_t_index(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_xnd_t_index())); }
static PyObject *pyc_get_xnd_t_type(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "xnd_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_xnd_t_type(PyCapsule_GetPointer(ptr, "xnd_t*")), "const ndt_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted xnd_t");
  return NULL;
}
static PyObject *pyc_offsetof_xnd_t_type(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_xnd_t_type())); }
static PyObject *pyc_get_xnd_t_ptr(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "xnd_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_xnd_t_ptr(PyCapsule_GetPointer(ptr, "xnd_t*")), "char*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted xnd_t");
  return NULL;
}
static PyObject *pyc_offsetof_xnd_t_ptr(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_xnd_t_ptr())); }
static PyObject *pyc_sizeof_xnd_master_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_xnd_master_t())); }
static PyObject *pyc_get_xnd_master_t_flags(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "xnd_master_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_xnd_master_t_flags(PyCapsule_GetPointer(ptr, "xnd_master_t*")), "uint32_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted xnd_master_t");
  return NULL;
}
static PyObject *pyc_offsetof_xnd_master_t_flags(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_xnd_master_t_flags())); }
static PyObject *pyc_get_xnd_master_t_master(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "xnd_master_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_xnd_master_t_master(PyCapsule_GetPointer(ptr, "xnd_master_t*")), "xnd_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted xnd_master_t");
  return NULL;
}
static PyObject *pyc_offsetof_xnd_master_t_master(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_xnd_master_t_master())); }
static PyObject *pyc_sizeof_xnd_index_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_xnd_index_t())); }
static PyObject *pyc_get_xnd_index_t_tag(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "xnd_index_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_xnd_index_t_tag(PyCapsule_GetPointer(ptr, "xnd_index_t*")), "enum xnd_key", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted xnd_index_t");
  return NULL;
}
static PyObject *pyc_offsetof_xnd_index_t_tag(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_xnd_index_t_tag())); }
static PyObject *pyc_get_xnd_index_t_Index(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "xnd_index_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_xnd_index_t_Index(PyCapsule_GetPointer(ptr, "xnd_index_t*")), "int64_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted xnd_index_t");
  return NULL;
}
static PyObject *pyc_offsetof_xnd_index_t_Index(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_xnd_index_t_Index())); }
static PyObject *pyc_get_xnd_index_t_FieldName(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "xnd_index_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_xnd_index_t_FieldName(PyCapsule_GetPointer(ptr, "xnd_index_t*")), "const char*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted xnd_index_t");
  return NULL;
}
static PyObject *pyc_offsetof_xnd_index_t_FieldName(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_xnd_index_t_FieldName())); }
static PyObject *pyc_get_xnd_index_t_Slice(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "xnd_index_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_xnd_index_t_Slice(PyCapsule_GetPointer(ptr, "xnd_index_t*")), "ndt_slice_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted xnd_index_t");
  return NULL;
}
static PyObject *pyc_offsetof_xnd_index_t_Slice(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_xnd_index_t_Slice())); }
static PyObject *pyc_sizeof_xnd_view_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_xnd_view_t())); }
static PyObject *pyc_get_xnd_view_t_flags(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "xnd_view_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_xnd_view_t_flags(PyCapsule_GetPointer(ptr, "xnd_view_t*")), "uint32_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted xnd_view_t");
  return NULL;
}
static PyObject *pyc_offsetof_xnd_view_t_flags(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_xnd_view_t_flags())); }
static PyObject *pyc_get_xnd_view_t_obj(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "xnd_view_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_xnd_view_t_obj(PyCapsule_GetPointer(ptr, "xnd_view_t*")), "const void*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted xnd_view_t");
  return NULL;
}
static PyObject *pyc_offsetof_xnd_view_t_obj(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_xnd_view_t_obj())); }
static PyObject *pyc_get_xnd_view_t_view(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "xnd_view_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_xnd_view_t_view(PyCapsule_GetPointer(ptr, "xnd_view_t*")), "xnd_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted xnd_view_t");
  return NULL;
}
static PyObject *pyc_offsetof_xnd_view_t_view(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_xnd_view_t_view())); }
static PyObject *pyc_sizeof_MemoryBlockObject(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_MemoryBlockObject())); }
static PyObject *pyc_get_MemoryBlockObject_type(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "MemoryBlockObject", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_MemoryBlockObject_type(PyCapsule_GetPointer(ptr, "MemoryBlockObject*")), "PyObject*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted MemoryBlockObject");
  return NULL;
}
static PyObject *pyc_offsetof_MemoryBlockObject_type(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_MemoryBlockObject_type())); }
static PyObject *pyc_get_MemoryBlockObject_xnd(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "MemoryBlockObject", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_MemoryBlockObject_xnd(PyCapsule_GetPointer(ptr, "MemoryBlockObject*")), "xnd_master_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted MemoryBlockObject");
  return NULL;
}
static PyObject *pyc_offsetof_MemoryBlockObject_xnd(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_MemoryBlockObject_xnd())); }
static PyObject *pyc_get_MemoryBlockObject_view(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "MemoryBlockObject", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_MemoryBlockObject_view(PyCapsule_GetPointer(ptr, "MemoryBlockObject*")), "Py_buffer*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted MemoryBlockObject");
  return NULL;
}
static PyObject *pyc_offsetof_MemoryBlockObject_view(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_MemoryBlockObject_view())); }
static PyObject *pyc_capsulate_XndObject(PyObject *self, PyObject *args) {
  PyObject* obj=NULL;
  if (!PyArg_UnpackTuple(args, "XndObject_instance", 0, 1, &obj))
    return NULL;
  if (Ndt_Check(obj)) {
    Py_INCREF(obj);
    return PyCapsule_New(obj, "XndObject*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected XndObject instance");
  return NULL;
}
static PyObject *pyc_sizeof_XndObject(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_XndObject())); }
static PyObject *pyc_get_XndObject_mblock(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "XndObject", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_XndObject_mblock(PyCapsule_GetPointer(ptr, "XndObject*")), "MemoryBlockObject*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted XndObject");
  return NULL;
}
static PyObject *pyc_offsetof_XndObject_mblock(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_XndObject_mblock())); }
static PyObject *pyc_get_XndObject_type(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "XndObject", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_XndObject_type(PyCapsule_GetPointer(ptr, "XndObject*")), "PyObject*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted XndObject");
  return NULL;
}
static PyObject *pyc_offsetof_XndObject_type(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_XndObject_type())); }
static PyObject *pyc_get_XndObject_xnd(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "XndObject", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_XndObject_xnd(PyCapsule_GetPointer(ptr, "XndObject*")), "xnd_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted XndObject");
  return NULL;
}
static PyObject *pyc_offsetof_XndObject_xnd(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_XndObject_xnd())); }
static PyObject *pyc_sizeof_gm_kernel_set_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_gm_kernel_set_t())); }
static PyObject *pyc_get_gm_kernel_set_t_sig(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "gm_kernel_set_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_gm_kernel_set_t_sig(PyCapsule_GetPointer(ptr, "gm_kernel_set_t*")), "ndt_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted gm_kernel_set_t");
  return NULL;
}
static PyObject *pyc_offsetof_gm_kernel_set_t_sig(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_gm_kernel_set_t_sig())); }
static PyObject *pyc_get_gm_kernel_set_t_constraint(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "gm_kernel_set_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_gm_kernel_set_t_constraint(PyCapsule_GetPointer(ptr, "gm_kernel_set_t*")), "const ndt_constraint_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted gm_kernel_set_t");
  return NULL;
}
static PyObject *pyc_offsetof_gm_kernel_set_t_constraint(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_gm_kernel_set_t_constraint())); }
static PyObject *pyc_get_gm_kernel_set_t_Opt(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "gm_kernel_set_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_gm_kernel_set_t_Opt(PyCapsule_GetPointer(ptr, "gm_kernel_set_t*")), "gm_xnd_kernel_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted gm_kernel_set_t");
  return NULL;
}
static PyObject *pyc_offsetof_gm_kernel_set_t_Opt(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_gm_kernel_set_t_Opt())); }
static PyObject *pyc_get_gm_kernel_set_t_C(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "gm_kernel_set_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_gm_kernel_set_t_C(PyCapsule_GetPointer(ptr, "gm_kernel_set_t*")), "gm_xnd_kernel_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted gm_kernel_set_t");
  return NULL;
}
static PyObject *pyc_offsetof_gm_kernel_set_t_C(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_gm_kernel_set_t_C())); }
static PyObject *pyc_get_gm_kernel_set_t_Fortran(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "gm_kernel_set_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_gm_kernel_set_t_Fortran(PyCapsule_GetPointer(ptr, "gm_kernel_set_t*")), "gm_xnd_kernel_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted gm_kernel_set_t");
  return NULL;
}
static PyObject *pyc_offsetof_gm_kernel_set_t_Fortran(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_gm_kernel_set_t_Fortran())); }
static PyObject *pyc_get_gm_kernel_set_t_Xnd(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "gm_kernel_set_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_gm_kernel_set_t_Xnd(PyCapsule_GetPointer(ptr, "gm_kernel_set_t*")), "gm_xnd_kernel_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted gm_kernel_set_t");
  return NULL;
}
static PyObject *pyc_offsetof_gm_kernel_set_t_Xnd(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_gm_kernel_set_t_Xnd())); }
static PyObject *pyc_get_gm_kernel_set_t_Strided(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "gm_kernel_set_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_gm_kernel_set_t_Strided(PyCapsule_GetPointer(ptr, "gm_kernel_set_t*")), "gm_strided_kernel_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted gm_kernel_set_t");
  return NULL;
}
static PyObject *pyc_offsetof_gm_kernel_set_t_Strided(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_gm_kernel_set_t_Strided())); }
static PyObject *pyc_sizeof_gm_typedef_init_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_gm_typedef_init_t())); }
static PyObject *pyc_get_gm_typedef_init_t_name(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "gm_typedef_init_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_gm_typedef_init_t_name(PyCapsule_GetPointer(ptr, "gm_typedef_init_t*")), "const char*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted gm_typedef_init_t");
  return NULL;
}
static PyObject *pyc_offsetof_gm_typedef_init_t_name(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_gm_typedef_init_t_name())); }
static PyObject *pyc_get_gm_typedef_init_t_type(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "gm_typedef_init_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_gm_typedef_init_t_type(PyCapsule_GetPointer(ptr, "gm_typedef_init_t*")), "const char*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted gm_typedef_init_t");
  return NULL;
}
static PyObject *pyc_offsetof_gm_typedef_init_t_type(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_gm_typedef_init_t_type())); }
static PyObject *pyc_get_gm_typedef_init_t_meth(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "gm_typedef_init_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_gm_typedef_init_t_meth(PyCapsule_GetPointer(ptr, "gm_typedef_init_t*")), "const ndt_methods_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted gm_typedef_init_t");
  return NULL;
}
static PyObject *pyc_offsetof_gm_typedef_init_t_meth(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_gm_typedef_init_t_meth())); }
static PyObject *pyc_sizeof_gm_kernel_init_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_gm_kernel_init_t())); }
static PyObject *pyc_get_gm_kernel_init_t_name(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "gm_kernel_init_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_gm_kernel_init_t_name(PyCapsule_GetPointer(ptr, "gm_kernel_init_t*")), "const char*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted gm_kernel_init_t");
  return NULL;
}
static PyObject *pyc_offsetof_gm_kernel_init_t_name(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_gm_kernel_init_t_name())); }
static PyObject *pyc_get_gm_kernel_init_t_sig(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "gm_kernel_init_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_gm_kernel_init_t_sig(PyCapsule_GetPointer(ptr, "gm_kernel_init_t*")), "const char*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted gm_kernel_init_t");
  return NULL;
}
static PyObject *pyc_offsetof_gm_kernel_init_t_sig(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_gm_kernel_init_t_sig())); }
static PyObject *pyc_get_gm_kernel_init_t_constraint(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "gm_kernel_init_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_gm_kernel_init_t_constraint(PyCapsule_GetPointer(ptr, "gm_kernel_init_t*")), "const ndt_constraint_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted gm_kernel_init_t");
  return NULL;
}
static PyObject *pyc_offsetof_gm_kernel_init_t_constraint(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_gm_kernel_init_t_constraint())); }
static PyObject *pyc_get_gm_kernel_init_t_Opt(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "gm_kernel_init_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_gm_kernel_init_t_Opt(PyCapsule_GetPointer(ptr, "gm_kernel_init_t*")), "gm_xnd_kernel_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted gm_kernel_init_t");
  return NULL;
}
static PyObject *pyc_offsetof_gm_kernel_init_t_Opt(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_gm_kernel_init_t_Opt())); }
static PyObject *pyc_get_gm_kernel_init_t_C(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "gm_kernel_init_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_gm_kernel_init_t_C(PyCapsule_GetPointer(ptr, "gm_kernel_init_t*")), "gm_xnd_kernel_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted gm_kernel_init_t");
  return NULL;
}
static PyObject *pyc_offsetof_gm_kernel_init_t_C(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_gm_kernel_init_t_C())); }
static PyObject *pyc_get_gm_kernel_init_t_Fortran(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "gm_kernel_init_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_gm_kernel_init_t_Fortran(PyCapsule_GetPointer(ptr, "gm_kernel_init_t*")), "gm_xnd_kernel_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted gm_kernel_init_t");
  return NULL;
}
static PyObject *pyc_offsetof_gm_kernel_init_t_Fortran(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_gm_kernel_init_t_Fortran())); }
static PyObject *pyc_get_gm_kernel_init_t_Xnd(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "gm_kernel_init_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_gm_kernel_init_t_Xnd(PyCapsule_GetPointer(ptr, "gm_kernel_init_t*")), "gm_xnd_kernel_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted gm_kernel_init_t");
  return NULL;
}
static PyObject *pyc_offsetof_gm_kernel_init_t_Xnd(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_gm_kernel_init_t_Xnd())); }
static PyObject *pyc_get_gm_kernel_init_t_Strided(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "gm_kernel_init_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_gm_kernel_init_t_Strided(PyCapsule_GetPointer(ptr, "gm_kernel_init_t*")), "gm_strided_kernel_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted gm_kernel_init_t");
  return NULL;
}
static PyObject *pyc_offsetof_gm_kernel_init_t_Strided(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_gm_kernel_init_t_Strided())); }
static PyObject *pyc_sizeof_gm_kernel_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_gm_kernel_t())); }
static PyObject *pyc_get_gm_kernel_t_flag(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "gm_kernel_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_gm_kernel_t_flag(PyCapsule_GetPointer(ptr, "gm_kernel_t*")), "uint32_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted gm_kernel_t");
  return NULL;
}
static PyObject *pyc_offsetof_gm_kernel_t_flag(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_gm_kernel_t_flag())); }
static PyObject *pyc_get_gm_kernel_t_set(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "gm_kernel_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_gm_kernel_t_set(PyCapsule_GetPointer(ptr, "gm_kernel_t*")), "const gm_kernel_set_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted gm_kernel_t");
  return NULL;
}
static PyObject *pyc_offsetof_gm_kernel_t_set(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_gm_kernel_t_set())); }
static PyObject *pyc_sizeof_gm_func_t(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_gm_func_t())); }
static PyObject *pyc_get_gm_func_t_name(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "gm_func_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_gm_func_t_name(PyCapsule_GetPointer(ptr, "gm_func_t*")), "char*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted gm_func_t");
  return NULL;
}
static PyObject *pyc_offsetof_gm_func_t_name(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_gm_func_t_name())); }
static PyObject *pyc_get_gm_func_t_typecheck(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "gm_func_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_gm_func_t_typecheck(PyCapsule_GetPointer(ptr, "gm_func_t*")), "gm_typecheck_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted gm_func_t");
  return NULL;
}
static PyObject *pyc_offsetof_gm_func_t_typecheck(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_gm_func_t_typecheck())); }
static PyObject *pyc_get_gm_func_t_nkernels(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "gm_func_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_gm_func_t_nkernels(PyCapsule_GetPointer(ptr, "gm_func_t*")), "int", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted gm_func_t");
  return NULL;
}
static PyObject *pyc_offsetof_gm_func_t_nkernels(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_gm_func_t_nkernels())); }
static PyObject *pyc_get_gm_func_t_kernels(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "gm_func_t", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_gm_func_t_kernels(PyCapsule_GetPointer(ptr, "gm_func_t*")), "gm_kernel_set_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted gm_func_t");
  return NULL;
}
static PyObject *pyc_offsetof_gm_func_t_kernels(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_gm_func_t_kernels())); }
static PyObject *pyc_sizeof_GufuncObject(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_GufuncObject())); }
static PyObject *pyc_get_GufuncObject_tbl(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "GufuncObject", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_GufuncObject_tbl(PyCapsule_GetPointer(ptr, "GufuncObject*")), "const gm_tbl_t*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted GufuncObject");
  return NULL;
}
static PyObject *pyc_offsetof_GufuncObject_tbl(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_GufuncObject_tbl())); }
static PyObject *pyc_get_GufuncObject_name(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "GufuncObject", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_GufuncObject_name(PyCapsule_GetPointer(ptr, "GufuncObject*")), "char*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted GufuncObject");
  return NULL;
}
static PyObject *pyc_offsetof_GufuncObject_name(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_GufuncObject_name())); }
static PyObject *pyc_sizeof_NRT_MemInfo(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_NRT_MemInfo())); }
static PyObject *pyc_get_NRT_MemInfo_refct(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "NRT_MemInfo", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_NRT_MemInfo_refct(PyCapsule_GetPointer(ptr, "NRT_MemInfo*")), "size_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted NRT_MemInfo");
  return NULL;
}
static PyObject *pyc_offsetof_NRT_MemInfo_refct(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_NRT_MemInfo_refct())); }
static PyObject *pyc_get_NRT_MemInfo_dtor(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "NRT_MemInfo", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_NRT_MemInfo_dtor(PyCapsule_GetPointer(ptr, "NRT_MemInfo*")), "NRT_dtor_function", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted NRT_MemInfo");
  return NULL;
}
static PyObject *pyc_offsetof_NRT_MemInfo_dtor(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_NRT_MemInfo_dtor())); }
static PyObject *pyc_get_NRT_MemInfo_dtor_info(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "NRT_MemInfo", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_NRT_MemInfo_dtor_info(PyCapsule_GetPointer(ptr, "NRT_MemInfo*")), "void*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted NRT_MemInfo");
  return NULL;
}
static PyObject *pyc_offsetof_NRT_MemInfo_dtor_info(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_NRT_MemInfo_dtor_info())); }
static PyObject *pyc_get_NRT_MemInfo_data(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "NRT_MemInfo", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_NRT_MemInfo_data(PyCapsule_GetPointer(ptr, "NRT_MemInfo*")), "void*", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted NRT_MemInfo");
  return NULL;
}
static PyObject *pyc_offsetof_NRT_MemInfo_data(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_NRT_MemInfo_data())); }
static PyObject *pyc_get_NRT_MemInfo_size(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "NRT_MemInfo", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_NRT_MemInfo_size(PyCapsule_GetPointer(ptr, "NRT_MemInfo*")), "size_t", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted NRT_MemInfo");
  return NULL;
}
static PyObject *pyc_offsetof_NRT_MemInfo_size(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_NRT_MemInfo_size())); }
static PyObject *pyc_sizeof_NRT_MemSys(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(sizeof_NRT_MemSys())); }
static PyObject *pyc_get_NRT_MemSys_atomic_dec(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "NRT_MemSys", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_NRT_MemSys_atomic_dec(PyCapsule_GetPointer(ptr, "NRT_MemSys*")), "NRT_atomic_inc_dec_func atomic_inc,", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted NRT_MemSys");
  return NULL;
}
static PyObject *pyc_offsetof_NRT_MemSys_atomic_dec(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_NRT_MemSys_atomic_dec())); }
static PyObject *pyc_get_NRT_MemSys_atomic_cas(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "NRT_MemSys", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_NRT_MemSys_atomic_cas(PyCapsule_GetPointer(ptr, "NRT_MemSys*")), "atomic_meminfo_cas_func", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted NRT_MemSys");
  return NULL;
}
static PyObject *pyc_offsetof_NRT_MemSys_atomic_cas(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_NRT_MemSys_atomic_cas())); }
static PyObject *pyc_get_NRT_MemSys_shutting(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "NRT_MemSys", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_NRT_MemSys_shutting(PyCapsule_GetPointer(ptr, "NRT_MemSys*")), "int", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted NRT_MemSys");
  return NULL;
}
static PyObject *pyc_offsetof_NRT_MemSys_shutting(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_NRT_MemSys_shutting())); }
static PyObject *pyc_get_NRT_MemSys_stats_mi_free(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "NRT_MemSys", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_NRT_MemSys_stats_mi_free(PyCapsule_GetPointer(ptr, "NRT_MemSys*")), "size_t stats_alloc,stats_free,stats_mi_alloc,", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted NRT_MemSys");
  return NULL;
}
static PyObject *pyc_offsetof_NRT_MemSys_stats_mi_free(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_NRT_MemSys_stats_mi_free())); }
static PyObject *pyc_get_NRT_MemSys_allocator_malloc(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "NRT_MemSys", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_NRT_MemSys_allocator_malloc(PyCapsule_GetPointer(ptr, "NRT_MemSys*")), "NRT_malloc_func", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted NRT_MemSys");
  return NULL;
}
static PyObject *pyc_offsetof_NRT_MemSys_allocator_malloc(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_NRT_MemSys_allocator_malloc())); }
static PyObject *pyc_get_NRT_MemSys_allocator_realloc(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "NRT_MemSys", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_NRT_MemSys_allocator_realloc(PyCapsule_GetPointer(ptr, "NRT_MemSys*")), "NRT_realloc_func", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted NRT_MemSys");
  return NULL;
}
static PyObject *pyc_offsetof_NRT_MemSys_allocator_realloc(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_NRT_MemSys_allocator_realloc())); }
static PyObject *pyc_get_NRT_MemSys_allocator_free(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "NRT_MemSys", 0, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    return PyCapsule_New( get_NRT_MemSys_allocator_free(PyCapsule_GetPointer(ptr, "NRT_MemSys*")), "NRT_free_func", NULL);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsuleted NRT_MemSys");
  return NULL;
}
static PyObject *pyc_offsetof_NRT_MemSys_allocator_free(PyObject *self, PyObject *args) { return PyLong_FromLong((long)(offsetof_NRT_MemSys_allocator_free())); }

static PyObject *pyc_capsule_to_int32(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "capsule", 1, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    const char* name = PyCapsule_GetName(ptr);
    int32_t value = *((int32_t*)PyCapsule_GetPointer(ptr, name));
    return PyLong_FromLong((long)value);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsule instance");
  return NULL;
}

static PyObject *pyc_capsule_to_int64(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  if (!PyArg_UnpackTuple(args, "capsule", 1, 1, &ptr))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    const char* name = PyCapsule_GetName(ptr);
    int64_t value = *((int64_t*)PyCapsule_GetPointer(ptr, name));
    return PyLong_FromLong((long)value);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsule instance");
  return NULL;
}

static PyObject *pyc_capsule_to_bytes(PyObject *self, PyObject *args) {
  PyObject* ptr=NULL;
  PyObject* size=NULL;
  if (!PyArg_UnpackTuple(args, "capsule", 1, 2, &ptr, &size))
    return NULL;
  if (PyCapsule_CheckExact(ptr)) {
    const char* name = PyCapsule_GetName(ptr);
    const char* value = ((const char*)PyCapsule_GetPointer(ptr, name));
    if (size==NULL)
      return PyBytes_FromString(value); // DANGER: if ptr does not contain 0 terminated string, the result is unpredictable
    Py_ssize_t sz = PyLong_AsLong(size);
    if (sz < 0)
      return NULL;
    return PyBytes_FromStringAndSize(value, sz);
  }
  PyErr_SetString(PyExc_TypeError, "expected capsule instance");
  return NULL;
}

static PyMethodDef xnd_structinfo_methods[] = {
  

  {"sizeof_char_opt_t", (PyCFunction)pyc_sizeof_char_opt_t, METH_VARARGS, "sizeof_char_opt_t() -> int"},
  {"get_char_opt_t_tag", (PyCFunction)pyc_get_char_opt_t_tag, METH_VARARGS, "get_char_opt_t_tag(< capsule(char_opt_t) >) -> < capsule( &char_opt_t->tag ) >"},
  {"offsetof_char_opt_t_tag", (PyCFunction)pyc_offsetof_char_opt_t_tag, METH_VARARGS, "offsetof_char_opt_t_tag() -> int"},
  {"get_char_opt_t_Some", (PyCFunction)pyc_get_char_opt_t_Some, METH_VARARGS, "get_char_opt_t_Some(< capsule(char_opt_t) >) -> < capsule( &char_opt_t->Some ) >"},
  {"offsetof_char_opt_t_Some", (PyCFunction)pyc_offsetof_char_opt_t_Some, METH_VARARGS, "offsetof_char_opt_t_Some() -> int"},
  {"sizeof_int64_opt_t", (PyCFunction)pyc_sizeof_int64_opt_t, METH_VARARGS, "sizeof_int64_opt_t() -> int"},
  {"get_int64_opt_t_tag", (PyCFunction)pyc_get_int64_opt_t_tag, METH_VARARGS, "get_int64_opt_t_tag(< capsule(int64_opt_t) >) -> < capsule( &int64_opt_t->tag ) >"},
  {"offsetof_int64_opt_t_tag", (PyCFunction)pyc_offsetof_int64_opt_t_tag, METH_VARARGS, "offsetof_int64_opt_t_tag() -> int"},
  {"get_int64_opt_t_Some", (PyCFunction)pyc_get_int64_opt_t_Some, METH_VARARGS, "get_int64_opt_t_Some(< capsule(int64_opt_t) >) -> < capsule( &int64_opt_t->Some ) >"},
  {"offsetof_int64_opt_t_Some", (PyCFunction)pyc_offsetof_int64_opt_t_Some, METH_VARARGS, "offsetof_int64_opt_t_Some() -> int"},
  {"sizeof_uint16_opt_t", (PyCFunction)pyc_sizeof_uint16_opt_t, METH_VARARGS, "sizeof_uint16_opt_t() -> int"},
  {"get_uint16_opt_t_tag", (PyCFunction)pyc_get_uint16_opt_t_tag, METH_VARARGS, "get_uint16_opt_t_tag(< capsule(uint16_opt_t) >) -> < capsule( &uint16_opt_t->tag ) >"},
  {"offsetof_uint16_opt_t_tag", (PyCFunction)pyc_offsetof_uint16_opt_t_tag, METH_VARARGS, "offsetof_uint16_opt_t_tag() -> int"},
  {"get_uint16_opt_t_Some", (PyCFunction)pyc_get_uint16_opt_t_Some, METH_VARARGS, "get_uint16_opt_t_Some(< capsule(uint16_opt_t) >) -> < capsule( &uint16_opt_t->Some ) >"},
  {"offsetof_uint16_opt_t_Some", (PyCFunction)pyc_offsetof_uint16_opt_t_Some, METH_VARARGS, "offsetof_uint16_opt_t_Some() -> int"},
  {"sizeof_ndt_meta_t", (PyCFunction)pyc_sizeof_ndt_meta_t, METH_VARARGS, "sizeof_ndt_meta_t() -> int"},
  {"get_ndt_meta_t_ndims", (PyCFunction)pyc_get_ndt_meta_t_ndims, METH_VARARGS, "get_ndt_meta_t_ndims(< capsule(ndt_meta_t) >) -> < capsule( &ndt_meta_t->ndims ) >"},
  {"offsetof_ndt_meta_t_ndims", (PyCFunction)pyc_offsetof_ndt_meta_t_ndims, METH_VARARGS, "offsetof_ndt_meta_t_ndims() -> int"},
  {"get_ndt_meta_t_noffsets", (PyCFunction)pyc_get_ndt_meta_t_noffsets, METH_VARARGS, "get_ndt_meta_t_noffsets(< capsule(ndt_meta_t) >) -> < capsule( &ndt_meta_t->noffsets ) >"},
  {"offsetof_ndt_meta_t_noffsets", (PyCFunction)pyc_offsetof_ndt_meta_t_noffsets, METH_VARARGS, "offsetof_ndt_meta_t_noffsets() -> int"},
  {"get_ndt_meta_t_offsets", (PyCFunction)pyc_get_ndt_meta_t_offsets, METH_VARARGS, "get_ndt_meta_t_offsets(< capsule(ndt_meta_t) >) -> < capsule( &ndt_meta_t->offsets ) >"},
  {"offsetof_ndt_meta_t_offsets", (PyCFunction)pyc_offsetof_ndt_meta_t_offsets, METH_VARARGS, "offsetof_ndt_meta_t_offsets() -> int"},
  {"sizeof_ndt_field_t", (PyCFunction)pyc_sizeof_ndt_field_t, METH_VARARGS, "sizeof_ndt_field_t() -> int"},
  {"get_ndt_field_t_access", (PyCFunction)pyc_get_ndt_field_t_access, METH_VARARGS, "get_ndt_field_t_access(< capsule(ndt_field_t) >) -> < capsule( &ndt_field_t->access ) >"},
  {"offsetof_ndt_field_t_access", (PyCFunction)pyc_offsetof_ndt_field_t_access, METH_VARARGS, "offsetof_ndt_field_t_access() -> int"},
  {"get_ndt_field_t_name", (PyCFunction)pyc_get_ndt_field_t_name, METH_VARARGS, "get_ndt_field_t_name(< capsule(ndt_field_t) >) -> < capsule( &ndt_field_t->name ) >"},
  {"offsetof_ndt_field_t_name", (PyCFunction)pyc_offsetof_ndt_field_t_name, METH_VARARGS, "offsetof_ndt_field_t_name() -> int"},
  {"get_ndt_field_t_type", (PyCFunction)pyc_get_ndt_field_t_type, METH_VARARGS, "get_ndt_field_t_type(< capsule(ndt_field_t) >) -> < capsule( &ndt_field_t->type ) >"},
  {"offsetof_ndt_field_t_type", (PyCFunction)pyc_offsetof_ndt_field_t_type, METH_VARARGS, "offsetof_ndt_field_t_type() -> int"},
  {"get_ndt_field_t_Concrete_align", (PyCFunction)pyc_get_ndt_field_t_Concrete_align, METH_VARARGS, "get_ndt_field_t_Concrete_align(< capsule(ndt_field_t) >) -> < capsule( &ndt_field_t->Concrete.align ) >"},
  {"offsetof_ndt_field_t_Concrete_align", (PyCFunction)pyc_offsetof_ndt_field_t_Concrete_align, METH_VARARGS, "offsetof_ndt_field_t_Concrete_align() -> int"},
  {"get_ndt_field_t_Concrete_explicit_align", (PyCFunction)pyc_get_ndt_field_t_Concrete_explicit_align, METH_VARARGS, "get_ndt_field_t_Concrete_explicit_align(< capsule(ndt_field_t) >) -> < capsule( &ndt_field_t->Concrete.explicit_align ) >"},
  {"offsetof_ndt_field_t_Concrete_explicit_align", (PyCFunction)pyc_offsetof_ndt_field_t_Concrete_explicit_align, METH_VARARGS, "offsetof_ndt_field_t_Concrete_explicit_align() -> int"},
  {"get_ndt_field_t_Concrete_pad", (PyCFunction)pyc_get_ndt_field_t_Concrete_pad, METH_VARARGS, "get_ndt_field_t_Concrete_pad(< capsule(ndt_field_t) >) -> < capsule( &ndt_field_t->Concrete.pad ) >"},
  {"offsetof_ndt_field_t_Concrete_pad", (PyCFunction)pyc_offsetof_ndt_field_t_Concrete_pad, METH_VARARGS, "offsetof_ndt_field_t_Concrete_pad() -> int"},
  {"get_ndt_field_t_Concrete_explicit_pad", (PyCFunction)pyc_get_ndt_field_t_Concrete_explicit_pad, METH_VARARGS, "get_ndt_field_t_Concrete_explicit_pad(< capsule(ndt_field_t) >) -> < capsule( &ndt_field_t->Concrete.explicit_pad ) >"},
  {"offsetof_ndt_field_t_Concrete_explicit_pad", (PyCFunction)pyc_offsetof_ndt_field_t_Concrete_explicit_pad, METH_VARARGS, "offsetof_ndt_field_t_Concrete_explicit_pad() -> int"},
  {"sizeof_ndt_value_t", (PyCFunction)pyc_sizeof_ndt_value_t, METH_VARARGS, "sizeof_ndt_value_t() -> int"},
  {"get_ndt_value_t_tag", (PyCFunction)pyc_get_ndt_value_t_tag, METH_VARARGS, "get_ndt_value_t_tag(< capsule(ndt_value_t) >) -> < capsule( &ndt_value_t->tag ) >"},
  {"offsetof_ndt_value_t_tag", (PyCFunction)pyc_offsetof_ndt_value_t_tag, METH_VARARGS, "offsetof_ndt_value_t_tag() -> int"},
  {"get_ndt_value_t_ValBool", (PyCFunction)pyc_get_ndt_value_t_ValBool, METH_VARARGS, "get_ndt_value_t_ValBool(< capsule(ndt_value_t) >) -> < capsule( &ndt_value_t->ValBool ) >"},
  {"offsetof_ndt_value_t_ValBool", (PyCFunction)pyc_offsetof_ndt_value_t_ValBool, METH_VARARGS, "offsetof_ndt_value_t_ValBool() -> int"},
  {"get_ndt_value_t_ValInt64", (PyCFunction)pyc_get_ndt_value_t_ValInt64, METH_VARARGS, "get_ndt_value_t_ValInt64(< capsule(ndt_value_t) >) -> < capsule( &ndt_value_t->ValInt64 ) >"},
  {"offsetof_ndt_value_t_ValInt64", (PyCFunction)pyc_offsetof_ndt_value_t_ValInt64, METH_VARARGS, "offsetof_ndt_value_t_ValInt64() -> int"},
  {"get_ndt_value_t_ValFloat64", (PyCFunction)pyc_get_ndt_value_t_ValFloat64, METH_VARARGS, "get_ndt_value_t_ValFloat64(< capsule(ndt_value_t) >) -> < capsule( &ndt_value_t->ValFloat64 ) >"},
  {"offsetof_ndt_value_t_ValFloat64", (PyCFunction)pyc_offsetof_ndt_value_t_ValFloat64, METH_VARARGS, "offsetof_ndt_value_t_ValFloat64() -> int"},
  {"get_ndt_value_t_ValString", (PyCFunction)pyc_get_ndt_value_t_ValString, METH_VARARGS, "get_ndt_value_t_ValString(< capsule(ndt_value_t) >) -> < capsule( &ndt_value_t->ValString ) >"},
  {"offsetof_ndt_value_t_ValString", (PyCFunction)pyc_offsetof_ndt_value_t_ValString, METH_VARARGS, "offsetof_ndt_value_t_ValString() -> int"},
  {"sizeof_ndt_slice_t", (PyCFunction)pyc_sizeof_ndt_slice_t, METH_VARARGS, "sizeof_ndt_slice_t() -> int"},
  {"get_ndt_slice_t_start", (PyCFunction)pyc_get_ndt_slice_t_start, METH_VARARGS, "get_ndt_slice_t_start(< capsule(ndt_slice_t) >) -> < capsule( &ndt_slice_t->start ) >"},
  {"offsetof_ndt_slice_t_start", (PyCFunction)pyc_offsetof_ndt_slice_t_start, METH_VARARGS, "offsetof_ndt_slice_t_start() -> int"},
  {"get_ndt_slice_t_stop", (PyCFunction)pyc_get_ndt_slice_t_stop, METH_VARARGS, "get_ndt_slice_t_stop(< capsule(ndt_slice_t) >) -> < capsule( &ndt_slice_t->stop ) >"},
  {"offsetof_ndt_slice_t_stop", (PyCFunction)pyc_offsetof_ndt_slice_t_stop, METH_VARARGS, "offsetof_ndt_slice_t_stop() -> int"},
  {"get_ndt_slice_t_step", (PyCFunction)pyc_get_ndt_slice_t_step, METH_VARARGS, "get_ndt_slice_t_step(< capsule(ndt_slice_t) >) -> < capsule( &ndt_slice_t->step ) >"},
  {"offsetof_ndt_slice_t_step", (PyCFunction)pyc_offsetof_ndt_slice_t_step, METH_VARARGS, "offsetof_ndt_slice_t_step() -> int"},
  {"sizeof_ndt_constraint_t", (PyCFunction)pyc_sizeof_ndt_constraint_t, METH_VARARGS, "sizeof_ndt_constraint_t() -> int"},
  {"get_ndt_constraint_t_f", (PyCFunction)pyc_get_ndt_constraint_t_f, METH_VARARGS, "get_ndt_constraint_t_f(< capsule(ndt_constraint_t) >) -> < capsule( &ndt_constraint_t->f ) >"},
  {"offsetof_ndt_constraint_t_f", (PyCFunction)pyc_offsetof_ndt_constraint_t_f, METH_VARARGS, "offsetof_ndt_constraint_t_f() -> int"},
  {"get_ndt_constraint_t_nin", (PyCFunction)pyc_get_ndt_constraint_t_nin, METH_VARARGS, "get_ndt_constraint_t_nin(< capsule(ndt_constraint_t) >) -> < capsule( &ndt_constraint_t->nin ) >"},
  {"offsetof_ndt_constraint_t_nin", (PyCFunction)pyc_offsetof_ndt_constraint_t_nin, METH_VARARGS, "offsetof_ndt_constraint_t_nin() -> int"},
  {"get_ndt_constraint_t_nout", (PyCFunction)pyc_get_ndt_constraint_t_nout, METH_VARARGS, "get_ndt_constraint_t_nout(< capsule(ndt_constraint_t) >) -> < capsule( &ndt_constraint_t->nout ) >"},
  {"offsetof_ndt_constraint_t_nout", (PyCFunction)pyc_offsetof_ndt_constraint_t_nout, METH_VARARGS, "offsetof_ndt_constraint_t_nout() -> int"},
  {"get_ndt_constraint_t_symbols", (PyCFunction)pyc_get_ndt_constraint_t_symbols, METH_VARARGS, "get_ndt_constraint_t_symbols(< capsule(ndt_constraint_t) >) -> < capsule( &ndt_constraint_t->symbols ) >"},
  {"offsetof_ndt_constraint_t_symbols", (PyCFunction)pyc_offsetof_ndt_constraint_t_symbols, METH_VARARGS, "offsetof_ndt_constraint_t_symbols() -> int"},
  {"sizeof_ndt_methods_t", (PyCFunction)pyc_sizeof_ndt_methods_t, METH_VARARGS, "sizeof_ndt_methods_t() -> int"},
  {"get_ndt_methods_t_init", (PyCFunction)pyc_get_ndt_methods_t_init, METH_VARARGS, "get_ndt_methods_t_init(< capsule(ndt_methods_t) >) -> < capsule( &ndt_methods_t->init ) >"},
  {"offsetof_ndt_methods_t_init", (PyCFunction)pyc_offsetof_ndt_methods_t_init, METH_VARARGS, "offsetof_ndt_methods_t_init() -> int"},
  {"get_ndt_methods_t_constraint", (PyCFunction)pyc_get_ndt_methods_t_constraint, METH_VARARGS, "get_ndt_methods_t_constraint(< capsule(ndt_methods_t) >) -> < capsule( &ndt_methods_t->constraint ) >"},
  {"offsetof_ndt_methods_t_constraint", (PyCFunction)pyc_offsetof_ndt_methods_t_constraint, METH_VARARGS, "offsetof_ndt_methods_t_constraint() -> int"},
  {"get_ndt_methods_t_repr", (PyCFunction)pyc_get_ndt_methods_t_repr, METH_VARARGS, "get_ndt_methods_t_repr(< capsule(ndt_methods_t) >) -> < capsule( &ndt_methods_t->repr ) >"},
  {"offsetof_ndt_methods_t_repr", (PyCFunction)pyc_offsetof_ndt_methods_t_repr, METH_VARARGS, "offsetof_ndt_methods_t_repr() -> int"},
  {"sizeof_ndt_t", (PyCFunction)pyc_sizeof_ndt_t, METH_VARARGS, "sizeof_ndt_t() -> int"},
  {"get_ndt_t_tag", (PyCFunction)pyc_get_ndt_t_tag, METH_VARARGS, "get_ndt_t_tag(< capsule(ndt_t) >) -> < capsule( &ndt_t->tag ) >"},
  {"offsetof_ndt_t_tag", (PyCFunction)pyc_offsetof_ndt_t_tag, METH_VARARGS, "offsetof_ndt_t_tag() -> int"},
  {"get_ndt_t_access", (PyCFunction)pyc_get_ndt_t_access, METH_VARARGS, "get_ndt_t_access(< capsule(ndt_t) >) -> < capsule( &ndt_t->access ) >"},
  {"offsetof_ndt_t_access", (PyCFunction)pyc_offsetof_ndt_t_access, METH_VARARGS, "offsetof_ndt_t_access() -> int"},
  {"get_ndt_t_flags", (PyCFunction)pyc_get_ndt_t_flags, METH_VARARGS, "get_ndt_t_flags(< capsule(ndt_t) >) -> < capsule( &ndt_t->flags ) >"},
  {"offsetof_ndt_t_flags", (PyCFunction)pyc_offsetof_ndt_t_flags, METH_VARARGS, "offsetof_ndt_t_flags() -> int"},
  {"get_ndt_t_ndim", (PyCFunction)pyc_get_ndt_t_ndim, METH_VARARGS, "get_ndt_t_ndim(< capsule(ndt_t) >) -> < capsule( &ndt_t->ndim ) >"},
  {"offsetof_ndt_t_ndim", (PyCFunction)pyc_offsetof_ndt_t_ndim, METH_VARARGS, "offsetof_ndt_t_ndim() -> int"},
  {"get_ndt_t_datasize", (PyCFunction)pyc_get_ndt_t_datasize, METH_VARARGS, "get_ndt_t_datasize(< capsule(ndt_t) >) -> < capsule( &ndt_t->datasize ) >"},
  {"offsetof_ndt_t_datasize", (PyCFunction)pyc_offsetof_ndt_t_datasize, METH_VARARGS, "offsetof_ndt_t_datasize() -> int"},
  {"get_ndt_t_align", (PyCFunction)pyc_get_ndt_t_align, METH_VARARGS, "get_ndt_t_align(< capsule(ndt_t) >) -> < capsule( &ndt_t->align ) >"},
  {"offsetof_ndt_t_align", (PyCFunction)pyc_offsetof_ndt_t_align, METH_VARARGS, "offsetof_ndt_t_align() -> int"},
  {"get_ndt_t_Module_name", (PyCFunction)pyc_get_ndt_t_Module_name, METH_VARARGS, "get_ndt_t_Module_name(< capsule(ndt_t) >) -> < capsule( &ndt_t->Module.name ) >"},
  {"offsetof_ndt_t_Module_name", (PyCFunction)pyc_offsetof_ndt_t_Module_name, METH_VARARGS, "offsetof_ndt_t_Module_name() -> int"},
  {"get_ndt_t_Module_type", (PyCFunction)pyc_get_ndt_t_Module_type, METH_VARARGS, "get_ndt_t_Module_type(< capsule(ndt_t) >) -> < capsule( &ndt_t->Module.type ) >"},
  {"offsetof_ndt_t_Module_type", (PyCFunction)pyc_offsetof_ndt_t_Module_type, METH_VARARGS, "offsetof_ndt_t_Module_type() -> int"},
  {"get_ndt_t_Function_elemwise", (PyCFunction)pyc_get_ndt_t_Function_elemwise, METH_VARARGS, "get_ndt_t_Function_elemwise(< capsule(ndt_t) >) -> < capsule( &ndt_t->Function.elemwise ) >"},
  {"offsetof_ndt_t_Function_elemwise", (PyCFunction)pyc_offsetof_ndt_t_Function_elemwise, METH_VARARGS, "offsetof_ndt_t_Function_elemwise() -> int"},
  {"get_ndt_t_Function_nin", (PyCFunction)pyc_get_ndt_t_Function_nin, METH_VARARGS, "get_ndt_t_Function_nin(< capsule(ndt_t) >) -> < capsule( &ndt_t->Function.nin ) >"},
  {"offsetof_ndt_t_Function_nin", (PyCFunction)pyc_offsetof_ndt_t_Function_nin, METH_VARARGS, "offsetof_ndt_t_Function_nin() -> int"},
  {"get_ndt_t_Function_nout", (PyCFunction)pyc_get_ndt_t_Function_nout, METH_VARARGS, "get_ndt_t_Function_nout(< capsule(ndt_t) >) -> < capsule( &ndt_t->Function.nout ) >"},
  {"offsetof_ndt_t_Function_nout", (PyCFunction)pyc_offsetof_ndt_t_Function_nout, METH_VARARGS, "offsetof_ndt_t_Function_nout() -> int"},
  {"get_ndt_t_Function_nargs", (PyCFunction)pyc_get_ndt_t_Function_nargs, METH_VARARGS, "get_ndt_t_Function_nargs(< capsule(ndt_t) >) -> < capsule( &ndt_t->Function.nargs ) >"},
  {"offsetof_ndt_t_Function_nargs", (PyCFunction)pyc_offsetof_ndt_t_Function_nargs, METH_VARARGS, "offsetof_ndt_t_Function_nargs() -> int"},
  {"get_ndt_t_Function_types", (PyCFunction)pyc_get_ndt_t_Function_types, METH_VARARGS, "get_ndt_t_Function_types(< capsule(ndt_t) >) -> < capsule( &ndt_t->Function.types ) >"},
  {"offsetof_ndt_t_Function_types", (PyCFunction)pyc_offsetof_ndt_t_Function_types, METH_VARARGS, "offsetof_ndt_t_Function_types() -> int"},
  {"get_ndt_t_FixedDim_tag", (PyCFunction)pyc_get_ndt_t_FixedDim_tag, METH_VARARGS, "get_ndt_t_FixedDim_tag(< capsule(ndt_t) >) -> < capsule( &ndt_t->FixedDim.tag ) >"},
  {"offsetof_ndt_t_FixedDim_tag", (PyCFunction)pyc_offsetof_ndt_t_FixedDim_tag, METH_VARARGS, "offsetof_ndt_t_FixedDim_tag() -> int"},
  {"get_ndt_t_FixedDim_shape", (PyCFunction)pyc_get_ndt_t_FixedDim_shape, METH_VARARGS, "get_ndt_t_FixedDim_shape(< capsule(ndt_t) >) -> < capsule( &ndt_t->FixedDim.shape ) >"},
  {"offsetof_ndt_t_FixedDim_shape", (PyCFunction)pyc_offsetof_ndt_t_FixedDim_shape, METH_VARARGS, "offsetof_ndt_t_FixedDim_shape() -> int"},
  {"get_ndt_t_FixedDim_type", (PyCFunction)pyc_get_ndt_t_FixedDim_type, METH_VARARGS, "get_ndt_t_FixedDim_type(< capsule(ndt_t) >) -> < capsule( &ndt_t->FixedDim.type ) >"},
  {"offsetof_ndt_t_FixedDim_type", (PyCFunction)pyc_offsetof_ndt_t_FixedDim_type, METH_VARARGS, "offsetof_ndt_t_FixedDim_type() -> int"},
  {"get_ndt_t_VarDim_type", (PyCFunction)pyc_get_ndt_t_VarDim_type, METH_VARARGS, "get_ndt_t_VarDim_type(< capsule(ndt_t) >) -> < capsule( &ndt_t->VarDim.type ) >"},
  {"offsetof_ndt_t_VarDim_type", (PyCFunction)pyc_offsetof_ndt_t_VarDim_type, METH_VARARGS, "offsetof_ndt_t_VarDim_type() -> int"},
  {"get_ndt_t_SymbolicDim_tag", (PyCFunction)pyc_get_ndt_t_SymbolicDim_tag, METH_VARARGS, "get_ndt_t_SymbolicDim_tag(< capsule(ndt_t) >) -> < capsule( &ndt_t->SymbolicDim.tag ) >"},
  {"offsetof_ndt_t_SymbolicDim_tag", (PyCFunction)pyc_offsetof_ndt_t_SymbolicDim_tag, METH_VARARGS, "offsetof_ndt_t_SymbolicDim_tag() -> int"},
  {"get_ndt_t_SymbolicDim_name", (PyCFunction)pyc_get_ndt_t_SymbolicDim_name, METH_VARARGS, "get_ndt_t_SymbolicDim_name(< capsule(ndt_t) >) -> < capsule( &ndt_t->SymbolicDim.name ) >"},
  {"offsetof_ndt_t_SymbolicDim_name", (PyCFunction)pyc_offsetof_ndt_t_SymbolicDim_name, METH_VARARGS, "offsetof_ndt_t_SymbolicDim_name() -> int"},
  {"get_ndt_t_SymbolicDim_type", (PyCFunction)pyc_get_ndt_t_SymbolicDim_type, METH_VARARGS, "get_ndt_t_SymbolicDim_type(< capsule(ndt_t) >) -> < capsule( &ndt_t->SymbolicDim.type ) >"},
  {"offsetof_ndt_t_SymbolicDim_type", (PyCFunction)pyc_offsetof_ndt_t_SymbolicDim_type, METH_VARARGS, "offsetof_ndt_t_SymbolicDim_type() -> int"},
  {"get_ndt_t_EllipsisDim_tag", (PyCFunction)pyc_get_ndt_t_EllipsisDim_tag, METH_VARARGS, "get_ndt_t_EllipsisDim_tag(< capsule(ndt_t) >) -> < capsule( &ndt_t->EllipsisDim.tag ) >"},
  {"offsetof_ndt_t_EllipsisDim_tag", (PyCFunction)pyc_offsetof_ndt_t_EllipsisDim_tag, METH_VARARGS, "offsetof_ndt_t_EllipsisDim_tag() -> int"},
  {"get_ndt_t_EllipsisDim_name", (PyCFunction)pyc_get_ndt_t_EllipsisDim_name, METH_VARARGS, "get_ndt_t_EllipsisDim_name(< capsule(ndt_t) >) -> < capsule( &ndt_t->EllipsisDim.name ) >"},
  {"offsetof_ndt_t_EllipsisDim_name", (PyCFunction)pyc_offsetof_ndt_t_EllipsisDim_name, METH_VARARGS, "offsetof_ndt_t_EllipsisDim_name() -> int"},
  {"get_ndt_t_EllipsisDim_type", (PyCFunction)pyc_get_ndt_t_EllipsisDim_type, METH_VARARGS, "get_ndt_t_EllipsisDim_type(< capsule(ndt_t) >) -> < capsule( &ndt_t->EllipsisDim.type ) >"},
  {"offsetof_ndt_t_EllipsisDim_type", (PyCFunction)pyc_offsetof_ndt_t_EllipsisDim_type, METH_VARARGS, "offsetof_ndt_t_EllipsisDim_type() -> int"},
  {"get_ndt_t_Tuple_flag", (PyCFunction)pyc_get_ndt_t_Tuple_flag, METH_VARARGS, "get_ndt_t_Tuple_flag(< capsule(ndt_t) >) -> < capsule( &ndt_t->Tuple.flag ) >"},
  {"offsetof_ndt_t_Tuple_flag", (PyCFunction)pyc_offsetof_ndt_t_Tuple_flag, METH_VARARGS, "offsetof_ndt_t_Tuple_flag() -> int"},
  {"get_ndt_t_Tuple_shape", (PyCFunction)pyc_get_ndt_t_Tuple_shape, METH_VARARGS, "get_ndt_t_Tuple_shape(< capsule(ndt_t) >) -> < capsule( &ndt_t->Tuple.shape ) >"},
  {"offsetof_ndt_t_Tuple_shape", (PyCFunction)pyc_offsetof_ndt_t_Tuple_shape, METH_VARARGS, "offsetof_ndt_t_Tuple_shape() -> int"},
  {"get_ndt_t_Tuple_types", (PyCFunction)pyc_get_ndt_t_Tuple_types, METH_VARARGS, "get_ndt_t_Tuple_types(< capsule(ndt_t) >) -> < capsule( &ndt_t->Tuple.types ) >"},
  {"offsetof_ndt_t_Tuple_types", (PyCFunction)pyc_offsetof_ndt_t_Tuple_types, METH_VARARGS, "offsetof_ndt_t_Tuple_types() -> int"},
  {"get_ndt_t_Record_flag", (PyCFunction)pyc_get_ndt_t_Record_flag, METH_VARARGS, "get_ndt_t_Record_flag(< capsule(ndt_t) >) -> < capsule( &ndt_t->Record.flag ) >"},
  {"offsetof_ndt_t_Record_flag", (PyCFunction)pyc_offsetof_ndt_t_Record_flag, METH_VARARGS, "offsetof_ndt_t_Record_flag() -> int"},
  {"get_ndt_t_Record_shape", (PyCFunction)pyc_get_ndt_t_Record_shape, METH_VARARGS, "get_ndt_t_Record_shape(< capsule(ndt_t) >) -> < capsule( &ndt_t->Record.shape ) >"},
  {"offsetof_ndt_t_Record_shape", (PyCFunction)pyc_offsetof_ndt_t_Record_shape, METH_VARARGS, "offsetof_ndt_t_Record_shape() -> int"},
  {"get_ndt_t_Record_names", (PyCFunction)pyc_get_ndt_t_Record_names, METH_VARARGS, "get_ndt_t_Record_names(< capsule(ndt_t) >) -> < capsule( &ndt_t->Record.names ) >"},
  {"offsetof_ndt_t_Record_names", (PyCFunction)pyc_offsetof_ndt_t_Record_names, METH_VARARGS, "offsetof_ndt_t_Record_names() -> int"},
  {"get_ndt_t_Record_types", (PyCFunction)pyc_get_ndt_t_Record_types, METH_VARARGS, "get_ndt_t_Record_types(< capsule(ndt_t) >) -> < capsule( &ndt_t->Record.types ) >"},
  {"offsetof_ndt_t_Record_types", (PyCFunction)pyc_offsetof_ndt_t_Record_types, METH_VARARGS, "offsetof_ndt_t_Record_types() -> int"},
  {"get_ndt_t_Ref_type", (PyCFunction)pyc_get_ndt_t_Ref_type, METH_VARARGS, "get_ndt_t_Ref_type(< capsule(ndt_t) >) -> < capsule( &ndt_t->Ref.type ) >"},
  {"offsetof_ndt_t_Ref_type", (PyCFunction)pyc_offsetof_ndt_t_Ref_type, METH_VARARGS, "offsetof_ndt_t_Ref_type() -> int"},
  {"get_ndt_t_Constr_name", (PyCFunction)pyc_get_ndt_t_Constr_name, METH_VARARGS, "get_ndt_t_Constr_name(< capsule(ndt_t) >) -> < capsule( &ndt_t->Constr.name ) >"},
  {"offsetof_ndt_t_Constr_name", (PyCFunction)pyc_offsetof_ndt_t_Constr_name, METH_VARARGS, "offsetof_ndt_t_Constr_name() -> int"},
  {"get_ndt_t_Constr_type", (PyCFunction)pyc_get_ndt_t_Constr_type, METH_VARARGS, "get_ndt_t_Constr_type(< capsule(ndt_t) >) -> < capsule( &ndt_t->Constr.type ) >"},
  {"offsetof_ndt_t_Constr_type", (PyCFunction)pyc_offsetof_ndt_t_Constr_type, METH_VARARGS, "offsetof_ndt_t_Constr_type() -> int"},
  {"get_ndt_t_Nominal_name", (PyCFunction)pyc_get_ndt_t_Nominal_name, METH_VARARGS, "get_ndt_t_Nominal_name(< capsule(ndt_t) >) -> < capsule( &ndt_t->Nominal.name ) >"},
  {"offsetof_ndt_t_Nominal_name", (PyCFunction)pyc_offsetof_ndt_t_Nominal_name, METH_VARARGS, "offsetof_ndt_t_Nominal_name() -> int"},
  {"get_ndt_t_Nominal_type", (PyCFunction)pyc_get_ndt_t_Nominal_type, METH_VARARGS, "get_ndt_t_Nominal_type(< capsule(ndt_t) >) -> < capsule( &ndt_t->Nominal.type ) >"},
  {"offsetof_ndt_t_Nominal_type", (PyCFunction)pyc_offsetof_ndt_t_Nominal_type, METH_VARARGS, "offsetof_ndt_t_Nominal_type() -> int"},
  {"get_ndt_t_Nominal_meth", (PyCFunction)pyc_get_ndt_t_Nominal_meth, METH_VARARGS, "get_ndt_t_Nominal_meth(< capsule(ndt_t) >) -> < capsule( &ndt_t->Nominal.meth ) >"},
  {"offsetof_ndt_t_Nominal_meth", (PyCFunction)pyc_offsetof_ndt_t_Nominal_meth, METH_VARARGS, "offsetof_ndt_t_Nominal_meth() -> int"},
  {"get_ndt_t_Categorical_ntypes", (PyCFunction)pyc_get_ndt_t_Categorical_ntypes, METH_VARARGS, "get_ndt_t_Categorical_ntypes(< capsule(ndt_t) >) -> < capsule( &ndt_t->Categorical.ntypes ) >"},
  {"offsetof_ndt_t_Categorical_ntypes", (PyCFunction)pyc_offsetof_ndt_t_Categorical_ntypes, METH_VARARGS, "offsetof_ndt_t_Categorical_ntypes() -> int"},
  {"get_ndt_t_Categorical_types", (PyCFunction)pyc_get_ndt_t_Categorical_types, METH_VARARGS, "get_ndt_t_Categorical_types(< capsule(ndt_t) >) -> < capsule( &ndt_t->Categorical.types ) >"},
  {"offsetof_ndt_t_Categorical_types", (PyCFunction)pyc_offsetof_ndt_t_Categorical_types, METH_VARARGS, "offsetof_ndt_t_Categorical_types() -> int"},
  {"get_ndt_t_FixedString_size", (PyCFunction)pyc_get_ndt_t_FixedString_size, METH_VARARGS, "get_ndt_t_FixedString_size(< capsule(ndt_t) >) -> < capsule( &ndt_t->FixedString.size ) >"},
  {"offsetof_ndt_t_FixedString_size", (PyCFunction)pyc_offsetof_ndt_t_FixedString_size, METH_VARARGS, "offsetof_ndt_t_FixedString_size() -> int"},
  {"get_ndt_t_FixedString_encoding", (PyCFunction)pyc_get_ndt_t_FixedString_encoding, METH_VARARGS, "get_ndt_t_FixedString_encoding(< capsule(ndt_t) >) -> < capsule( &ndt_t->FixedString.encoding ) >"},
  {"offsetof_ndt_t_FixedString_encoding", (PyCFunction)pyc_offsetof_ndt_t_FixedString_encoding, METH_VARARGS, "offsetof_ndt_t_FixedString_encoding() -> int"},
  {"get_ndt_t_FixedBytes_size", (PyCFunction)pyc_get_ndt_t_FixedBytes_size, METH_VARARGS, "get_ndt_t_FixedBytes_size(< capsule(ndt_t) >) -> < capsule( &ndt_t->FixedBytes.size ) >"},
  {"offsetof_ndt_t_FixedBytes_size", (PyCFunction)pyc_offsetof_ndt_t_FixedBytes_size, METH_VARARGS, "offsetof_ndt_t_FixedBytes_size() -> int"},
  {"get_ndt_t_FixedBytes_align", (PyCFunction)pyc_get_ndt_t_FixedBytes_align, METH_VARARGS, "get_ndt_t_FixedBytes_align(< capsule(ndt_t) >) -> < capsule( &ndt_t->FixedBytes.align ) >"},
  {"offsetof_ndt_t_FixedBytes_align", (PyCFunction)pyc_offsetof_ndt_t_FixedBytes_align, METH_VARARGS, "offsetof_ndt_t_FixedBytes_align() -> int"},
  {"get_ndt_t_Bytes_target_align", (PyCFunction)pyc_get_ndt_t_Bytes_target_align, METH_VARARGS, "get_ndt_t_Bytes_target_align(< capsule(ndt_t) >) -> < capsule( &ndt_t->Bytes.target_align ) >"},
  {"offsetof_ndt_t_Bytes_target_align", (PyCFunction)pyc_offsetof_ndt_t_Bytes_target_align, METH_VARARGS, "offsetof_ndt_t_Bytes_target_align() -> int"},
  {"get_ndt_t_Char_encoding", (PyCFunction)pyc_get_ndt_t_Char_encoding, METH_VARARGS, "get_ndt_t_Char_encoding(< capsule(ndt_t) >) -> < capsule( &ndt_t->Char.encoding ) >"},
  {"offsetof_ndt_t_Char_encoding", (PyCFunction)pyc_offsetof_ndt_t_Char_encoding, METH_VARARGS, "offsetof_ndt_t_Char_encoding() -> int"},
  {"get_ndt_t_Typevar_name", (PyCFunction)pyc_get_ndt_t_Typevar_name, METH_VARARGS, "get_ndt_t_Typevar_name(< capsule(ndt_t) >) -> < capsule( &ndt_t->Typevar.name ) >"},
  {"offsetof_ndt_t_Typevar_name", (PyCFunction)pyc_offsetof_ndt_t_Typevar_name, METH_VARARGS, "offsetof_ndt_t_Typevar_name() -> int"},
  {"get_ndt_t_Concrete_FixedDim_itemsize", (PyCFunction)pyc_get_ndt_t_Concrete_FixedDim_itemsize, METH_VARARGS, "get_ndt_t_Concrete_FixedDim_itemsize(< capsule(ndt_t) >) -> < capsule( &ndt_t->Concrete.FixedDim.itemsize ) >"},
  {"offsetof_ndt_t_Concrete_FixedDim_itemsize", (PyCFunction)pyc_offsetof_ndt_t_Concrete_FixedDim_itemsize, METH_VARARGS, "offsetof_ndt_t_Concrete_FixedDim_itemsize() -> int"},
  {"get_ndt_t_Concrete_FixedDim_step", (PyCFunction)pyc_get_ndt_t_Concrete_FixedDim_step, METH_VARARGS, "get_ndt_t_Concrete_FixedDim_step(< capsule(ndt_t) >) -> < capsule( &ndt_t->Concrete.FixedDim.step ) >"},
  {"offsetof_ndt_t_Concrete_FixedDim_step", (PyCFunction)pyc_offsetof_ndt_t_Concrete_FixedDim_step, METH_VARARGS, "offsetof_ndt_t_Concrete_FixedDim_step() -> int"},
  {"get_ndt_t_Concrete_VarDim_flag", (PyCFunction)pyc_get_ndt_t_Concrete_VarDim_flag, METH_VARARGS, "get_ndt_t_Concrete_VarDim_flag(< capsule(ndt_t) >) -> < capsule( &ndt_t->Concrete.VarDim.flag ) >"},
  {"offsetof_ndt_t_Concrete_VarDim_flag", (PyCFunction)pyc_offsetof_ndt_t_Concrete_VarDim_flag, METH_VARARGS, "offsetof_ndt_t_Concrete_VarDim_flag() -> int"},
  {"get_ndt_t_Concrete_VarDim_itemsize", (PyCFunction)pyc_get_ndt_t_Concrete_VarDim_itemsize, METH_VARARGS, "get_ndt_t_Concrete_VarDim_itemsize(< capsule(ndt_t) >) -> < capsule( &ndt_t->Concrete.VarDim.itemsize ) >"},
  {"offsetof_ndt_t_Concrete_VarDim_itemsize", (PyCFunction)pyc_offsetof_ndt_t_Concrete_VarDim_itemsize, METH_VARARGS, "offsetof_ndt_t_Concrete_VarDim_itemsize() -> int"},
  {"get_ndt_t_Concrete_VarDim_noffsets", (PyCFunction)pyc_get_ndt_t_Concrete_VarDim_noffsets, METH_VARARGS, "get_ndt_t_Concrete_VarDim_noffsets(< capsule(ndt_t) >) -> < capsule( &ndt_t->Concrete.VarDim.noffsets ) >"},
  {"offsetof_ndt_t_Concrete_VarDim_noffsets", (PyCFunction)pyc_offsetof_ndt_t_Concrete_VarDim_noffsets, METH_VARARGS, "offsetof_ndt_t_Concrete_VarDim_noffsets() -> int"},
  {"get_ndt_t_Concrete_VarDim_offsets", (PyCFunction)pyc_get_ndt_t_Concrete_VarDim_offsets, METH_VARARGS, "get_ndt_t_Concrete_VarDim_offsets(< capsule(ndt_t) >) -> < capsule( &ndt_t->Concrete.VarDim.offsets ) >"},
  {"offsetof_ndt_t_Concrete_VarDim_offsets", (PyCFunction)pyc_offsetof_ndt_t_Concrete_VarDim_offsets, METH_VARARGS, "offsetof_ndt_t_Concrete_VarDim_offsets() -> int"},
  {"get_ndt_t_Concrete_VarDim_nslices", (PyCFunction)pyc_get_ndt_t_Concrete_VarDim_nslices, METH_VARARGS, "get_ndt_t_Concrete_VarDim_nslices(< capsule(ndt_t) >) -> < capsule( &ndt_t->Concrete.VarDim.nslices ) >"},
  {"offsetof_ndt_t_Concrete_VarDim_nslices", (PyCFunction)pyc_offsetof_ndt_t_Concrete_VarDim_nslices, METH_VARARGS, "offsetof_ndt_t_Concrete_VarDim_nslices() -> int"},
  {"get_ndt_t_Concrete_VarDim_slices", (PyCFunction)pyc_get_ndt_t_Concrete_VarDim_slices, METH_VARARGS, "get_ndt_t_Concrete_VarDim_slices(< capsule(ndt_t) >) -> < capsule( &ndt_t->Concrete.VarDim.slices ) >"},
  {"offsetof_ndt_t_Concrete_VarDim_slices", (PyCFunction)pyc_offsetof_ndt_t_Concrete_VarDim_slices, METH_VARARGS, "offsetof_ndt_t_Concrete_VarDim_slices() -> int"},
  {"get_ndt_t_Concrete_Tuple_offset", (PyCFunction)pyc_get_ndt_t_Concrete_Tuple_offset, METH_VARARGS, "get_ndt_t_Concrete_Tuple_offset(< capsule(ndt_t) >) -> < capsule( &ndt_t->Concrete.Tuple.offset ) >"},
  {"offsetof_ndt_t_Concrete_Tuple_offset", (PyCFunction)pyc_offsetof_ndt_t_Concrete_Tuple_offset, METH_VARARGS, "offsetof_ndt_t_Concrete_Tuple_offset() -> int"},
  {"get_ndt_t_Concrete_Tuple_align", (PyCFunction)pyc_get_ndt_t_Concrete_Tuple_align, METH_VARARGS, "get_ndt_t_Concrete_Tuple_align(< capsule(ndt_t) >) -> < capsule( &ndt_t->Concrete.Tuple.align ) >"},
  {"offsetof_ndt_t_Concrete_Tuple_align", (PyCFunction)pyc_offsetof_ndt_t_Concrete_Tuple_align, METH_VARARGS, "offsetof_ndt_t_Concrete_Tuple_align() -> int"},
  {"get_ndt_t_Concrete_Tuple_pad", (PyCFunction)pyc_get_ndt_t_Concrete_Tuple_pad, METH_VARARGS, "get_ndt_t_Concrete_Tuple_pad(< capsule(ndt_t) >) -> < capsule( &ndt_t->Concrete.Tuple.pad ) >"},
  {"offsetof_ndt_t_Concrete_Tuple_pad", (PyCFunction)pyc_offsetof_ndt_t_Concrete_Tuple_pad, METH_VARARGS, "offsetof_ndt_t_Concrete_Tuple_pad() -> int"},
  {"get_ndt_t_Concrete_Record_offset", (PyCFunction)pyc_get_ndt_t_Concrete_Record_offset, METH_VARARGS, "get_ndt_t_Concrete_Record_offset(< capsule(ndt_t) >) -> < capsule( &ndt_t->Concrete.Record.offset ) >"},
  {"offsetof_ndt_t_Concrete_Record_offset", (PyCFunction)pyc_offsetof_ndt_t_Concrete_Record_offset, METH_VARARGS, "offsetof_ndt_t_Concrete_Record_offset() -> int"},
  {"get_ndt_t_Concrete_Record_align", (PyCFunction)pyc_get_ndt_t_Concrete_Record_align, METH_VARARGS, "get_ndt_t_Concrete_Record_align(< capsule(ndt_t) >) -> < capsule( &ndt_t->Concrete.Record.align ) >"},
  {"offsetof_ndt_t_Concrete_Record_align", (PyCFunction)pyc_offsetof_ndt_t_Concrete_Record_align, METH_VARARGS, "offsetof_ndt_t_Concrete_Record_align() -> int"},
  {"get_ndt_t_Concrete_Record_pad", (PyCFunction)pyc_get_ndt_t_Concrete_Record_pad, METH_VARARGS, "get_ndt_t_Concrete_Record_pad(< capsule(ndt_t) >) -> < capsule( &ndt_t->Concrete.Record.pad ) >"},
  {"offsetof_ndt_t_Concrete_Record_pad", (PyCFunction)pyc_offsetof_ndt_t_Concrete_Record_pad, METH_VARARGS, "offsetof_ndt_t_Concrete_Record_pad() -> int"},
  {"get_ndt_t_extra", (PyCFunction)pyc_get_ndt_t_extra, METH_VARARGS, "get_ndt_t_extra(< capsule(ndt_t) >) -> < capsule( &ndt_t->extra ) >"},
  {"offsetof_ndt_t_extra", (PyCFunction)pyc_offsetof_ndt_t_extra, METH_VARARGS, "offsetof_ndt_t_extra() -> int"},
  {"sizeof_ndt_context_t", (PyCFunction)pyc_sizeof_ndt_context_t, METH_VARARGS, "sizeof_ndt_context_t() -> int"},
  {"get_ndt_context_t_flags", (PyCFunction)pyc_get_ndt_context_t_flags, METH_VARARGS, "get_ndt_context_t_flags(< capsule(ndt_context_t) >) -> < capsule( &ndt_context_t->flags ) >"},
  {"offsetof_ndt_context_t_flags", (PyCFunction)pyc_offsetof_ndt_context_t_flags, METH_VARARGS, "offsetof_ndt_context_t_flags() -> int"},
  {"get_ndt_context_t_err", (PyCFunction)pyc_get_ndt_context_t_err, METH_VARARGS, "get_ndt_context_t_err(< capsule(ndt_context_t) >) -> < capsule( &ndt_context_t->err ) >"},
  {"offsetof_ndt_context_t_err", (PyCFunction)pyc_offsetof_ndt_context_t_err, METH_VARARGS, "offsetof_ndt_context_t_err() -> int"},
  {"get_ndt_context_t_msg", (PyCFunction)pyc_get_ndt_context_t_msg, METH_VARARGS, "get_ndt_context_t_msg(< capsule(ndt_context_t) >) -> < capsule( &ndt_context_t->msg ) >"},
  {"offsetof_ndt_context_t_msg", (PyCFunction)pyc_offsetof_ndt_context_t_msg, METH_VARARGS, "offsetof_ndt_context_t_msg() -> int"},
  {"get_ndt_context_t_ConstMsg", (PyCFunction)pyc_get_ndt_context_t_ConstMsg, METH_VARARGS, "get_ndt_context_t_ConstMsg(< capsule(ndt_context_t) >) -> < capsule( &ndt_context_t->ConstMsg ) >"},
  {"offsetof_ndt_context_t_ConstMsg", (PyCFunction)pyc_offsetof_ndt_context_t_ConstMsg, METH_VARARGS, "offsetof_ndt_context_t_ConstMsg() -> int"},
  {"get_ndt_context_t_DynamicMsg", (PyCFunction)pyc_get_ndt_context_t_DynamicMsg, METH_VARARGS, "get_ndt_context_t_DynamicMsg(< capsule(ndt_context_t) >) -> < capsule( &ndt_context_t->DynamicMsg ) >"},
  {"offsetof_ndt_context_t_DynamicMsg", (PyCFunction)pyc_offsetof_ndt_context_t_DynamicMsg, METH_VARARGS, "offsetof_ndt_context_t_DynamicMsg() -> int"},
  {"sizeof_ndt_ndarray_t", (PyCFunction)pyc_sizeof_ndt_ndarray_t, METH_VARARGS, "sizeof_ndt_ndarray_t() -> int"},
  {"get_ndt_ndarray_t_ndim", (PyCFunction)pyc_get_ndt_ndarray_t_ndim, METH_VARARGS, "get_ndt_ndarray_t_ndim(< capsule(ndt_ndarray_t) >) -> < capsule( &ndt_ndarray_t->ndim ) >"},
  {"offsetof_ndt_ndarray_t_ndim", (PyCFunction)pyc_offsetof_ndt_ndarray_t_ndim, METH_VARARGS, "offsetof_ndt_ndarray_t_ndim() -> int"},
  {"get_ndt_ndarray_t_itemsize", (PyCFunction)pyc_get_ndt_ndarray_t_itemsize, METH_VARARGS, "get_ndt_ndarray_t_itemsize(< capsule(ndt_ndarray_t) >) -> < capsule( &ndt_ndarray_t->itemsize ) >"},
  {"offsetof_ndt_ndarray_t_itemsize", (PyCFunction)pyc_offsetof_ndt_ndarray_t_itemsize, METH_VARARGS, "offsetof_ndt_ndarray_t_itemsize() -> int"},
  {"get_ndt_ndarray_t_shape", (PyCFunction)pyc_get_ndt_ndarray_t_shape, METH_VARARGS, "get_ndt_ndarray_t_shape(< capsule(ndt_ndarray_t) >) -> < capsule( &ndt_ndarray_t->shape ) >"},
  {"offsetof_ndt_ndarray_t_shape", (PyCFunction)pyc_offsetof_ndt_ndarray_t_shape, METH_VARARGS, "offsetof_ndt_ndarray_t_shape() -> int"},
  {"get_ndt_ndarray_t_strides", (PyCFunction)pyc_get_ndt_ndarray_t_strides, METH_VARARGS, "get_ndt_ndarray_t_strides(< capsule(ndt_ndarray_t) >) -> < capsule( &ndt_ndarray_t->strides ) >"},
  {"offsetof_ndt_ndarray_t_strides", (PyCFunction)pyc_offsetof_ndt_ndarray_t_strides, METH_VARARGS, "offsetof_ndt_ndarray_t_strides() -> int"},
  {"get_ndt_ndarray_t_steps", (PyCFunction)pyc_get_ndt_ndarray_t_steps, METH_VARARGS, "get_ndt_ndarray_t_steps(< capsule(ndt_ndarray_t) >) -> < capsule( &ndt_ndarray_t->steps ) >"},
  {"offsetof_ndt_ndarray_t_steps", (PyCFunction)pyc_offsetof_ndt_ndarray_t_steps, METH_VARARGS, "offsetof_ndt_ndarray_t_steps() -> int"},
  {"sizeof_ndt_apply_spec_t", (PyCFunction)pyc_sizeof_ndt_apply_spec_t, METH_VARARGS, "sizeof_ndt_apply_spec_t() -> int"},
  {"get_ndt_apply_spec_t_flags", (PyCFunction)pyc_get_ndt_apply_spec_t_flags, METH_VARARGS, "get_ndt_apply_spec_t_flags(< capsule(ndt_apply_spec_t) >) -> < capsule( &ndt_apply_spec_t->flags ) >"},
  {"offsetof_ndt_apply_spec_t_flags", (PyCFunction)pyc_offsetof_ndt_apply_spec_t_flags, METH_VARARGS, "offsetof_ndt_apply_spec_t_flags() -> int"},
  {"get_ndt_apply_spec_t_nout", (PyCFunction)pyc_get_ndt_apply_spec_t_nout, METH_VARARGS, "get_ndt_apply_spec_t_nout(< capsule(ndt_apply_spec_t) >) -> < capsule( &ndt_apply_spec_t->nout ) >"},
  {"offsetof_ndt_apply_spec_t_nout", (PyCFunction)pyc_offsetof_ndt_apply_spec_t_nout, METH_VARARGS, "offsetof_ndt_apply_spec_t_nout() -> int"},
  {"get_ndt_apply_spec_t_nbroadcast", (PyCFunction)pyc_get_ndt_apply_spec_t_nbroadcast, METH_VARARGS, "get_ndt_apply_spec_t_nbroadcast(< capsule(ndt_apply_spec_t) >) -> < capsule( &ndt_apply_spec_t->nbroadcast ) >"},
  {"offsetof_ndt_apply_spec_t_nbroadcast", (PyCFunction)pyc_offsetof_ndt_apply_spec_t_nbroadcast, METH_VARARGS, "offsetof_ndt_apply_spec_t_nbroadcast() -> int"},
  {"get_ndt_apply_spec_t_outer_dims", (PyCFunction)pyc_get_ndt_apply_spec_t_outer_dims, METH_VARARGS, "get_ndt_apply_spec_t_outer_dims(< capsule(ndt_apply_spec_t) >) -> < capsule( &ndt_apply_spec_t->outer_dims ) >"},
  {"offsetof_ndt_apply_spec_t_outer_dims", (PyCFunction)pyc_offsetof_ndt_apply_spec_t_outer_dims, METH_VARARGS, "offsetof_ndt_apply_spec_t_outer_dims() -> int"},
  {"get_ndt_apply_spec_t_out", (PyCFunction)pyc_get_ndt_apply_spec_t_out, METH_VARARGS, "get_ndt_apply_spec_t_out(< capsule(ndt_apply_spec_t) >) -> < capsule( &ndt_apply_spec_t->out ) >"},
  {"offsetof_ndt_apply_spec_t_out", (PyCFunction)pyc_offsetof_ndt_apply_spec_t_out, METH_VARARGS, "offsetof_ndt_apply_spec_t_out() -> int"},
  {"get_ndt_apply_spec_t_broadcast", (PyCFunction)pyc_get_ndt_apply_spec_t_broadcast, METH_VARARGS, "get_ndt_apply_spec_t_broadcast(< capsule(ndt_apply_spec_t) >) -> < capsule( &ndt_apply_spec_t->broadcast ) >"},
  {"offsetof_ndt_apply_spec_t_broadcast", (PyCFunction)pyc_offsetof_ndt_apply_spec_t_broadcast, METH_VARARGS, "offsetof_ndt_apply_spec_t_broadcast() -> int"},
  {"sizeof_ndt_typedef_t", (PyCFunction)pyc_sizeof_ndt_typedef_t, METH_VARARGS, "sizeof_ndt_typedef_t() -> int"},
  {"get_ndt_typedef_t_type", (PyCFunction)pyc_get_ndt_typedef_t_type, METH_VARARGS, "get_ndt_typedef_t_type(< capsule(ndt_typedef_t) >) -> < capsule( &ndt_typedef_t->type ) >"},
  {"offsetof_ndt_typedef_t_type", (PyCFunction)pyc_offsetof_ndt_typedef_t_type, METH_VARARGS, "offsetof_ndt_typedef_t_type() -> int"},
  {"get_ndt_typedef_t_meth", (PyCFunction)pyc_get_ndt_typedef_t_meth, METH_VARARGS, "get_ndt_typedef_t_meth(< capsule(ndt_typedef_t) >) -> < capsule( &ndt_typedef_t->meth ) >"},
  {"offsetof_ndt_typedef_t_meth", (PyCFunction)pyc_offsetof_ndt_typedef_t_meth, METH_VARARGS, "offsetof_ndt_typedef_t_meth() -> int"},
  {"sizeof_ndt_bytes_t", (PyCFunction)pyc_sizeof_ndt_bytes_t, METH_VARARGS, "sizeof_ndt_bytes_t() -> int"},
  {"get_ndt_bytes_t_size", (PyCFunction)pyc_get_ndt_bytes_t_size, METH_VARARGS, "get_ndt_bytes_t_size(< capsule(ndt_bytes_t) >) -> < capsule( &ndt_bytes_t->size ) >"},
  {"offsetof_ndt_bytes_t_size", (PyCFunction)pyc_offsetof_ndt_bytes_t_size, METH_VARARGS, "offsetof_ndt_bytes_t_size() -> int"},
  {"get_ndt_bytes_t_data", (PyCFunction)pyc_get_ndt_bytes_t_data, METH_VARARGS, "get_ndt_bytes_t_data(< capsule(ndt_bytes_t) >) -> < capsule( &ndt_bytes_t->data ) >"},
  {"offsetof_ndt_bytes_t_data", (PyCFunction)pyc_offsetof_ndt_bytes_t_data, METH_VARARGS, "offsetof_ndt_bytes_t_data() -> int"},
  {"capsulate_NdtObject", (PyCFunction)pyc_capsulate_NdtObject, METH_VARARGS, NULL},
  {"sizeof_NdtObject", (PyCFunction)pyc_sizeof_NdtObject, METH_VARARGS, "sizeof_NdtObject() -> int"},
  {"get_NdtObject_rbuf", (PyCFunction)pyc_get_NdtObject_rbuf, METH_VARARGS, "get_NdtObject_rbuf(< capsule(NdtObject) >) -> < capsule( &NdtObject->rbuf ) >"},
  {"offsetof_NdtObject_rbuf", (PyCFunction)pyc_offsetof_NdtObject_rbuf, METH_VARARGS, "offsetof_NdtObject_rbuf() -> int"},
  {"get_NdtObject_ndt", (PyCFunction)pyc_get_NdtObject_ndt, METH_VARARGS, "get_NdtObject_ndt(< capsule(NdtObject) >) -> < capsule( &NdtObject->ndt ) >"},
  {"offsetof_NdtObject_ndt", (PyCFunction)pyc_offsetof_NdtObject_ndt, METH_VARARGS, "offsetof_NdtObject_ndt() -> int"},
  {"sizeof_xnd_bitmap_t", (PyCFunction)pyc_sizeof_xnd_bitmap_t, METH_VARARGS, "sizeof_xnd_bitmap_t() -> int"},
  {"get_xnd_bitmap_t_data", (PyCFunction)pyc_get_xnd_bitmap_t_data, METH_VARARGS, "get_xnd_bitmap_t_data(< capsule(xnd_bitmap_t) >) -> < capsule( &xnd_bitmap_t->data ) >"},
  {"offsetof_xnd_bitmap_t_data", (PyCFunction)pyc_offsetof_xnd_bitmap_t_data, METH_VARARGS, "offsetof_xnd_bitmap_t_data() -> int"},
  {"get_xnd_bitmap_t_size", (PyCFunction)pyc_get_xnd_bitmap_t_size, METH_VARARGS, "get_xnd_bitmap_t_size(< capsule(xnd_bitmap_t) >) -> < capsule( &xnd_bitmap_t->size ) >"},
  {"offsetof_xnd_bitmap_t_size", (PyCFunction)pyc_offsetof_xnd_bitmap_t_size, METH_VARARGS, "offsetof_xnd_bitmap_t_size() -> int"},
  {"get_xnd_bitmap_t_next", (PyCFunction)pyc_get_xnd_bitmap_t_next, METH_VARARGS, "get_xnd_bitmap_t_next(< capsule(xnd_bitmap_t) >) -> < capsule( &xnd_bitmap_t->next ) >"},
  {"offsetof_xnd_bitmap_t_next", (PyCFunction)pyc_offsetof_xnd_bitmap_t_next, METH_VARARGS, "offsetof_xnd_bitmap_t_next() -> int"},
  {"sizeof_xnd_t", (PyCFunction)pyc_sizeof_xnd_t, METH_VARARGS, "sizeof_xnd_t() -> int"},
  {"get_xnd_t_bitmap", (PyCFunction)pyc_get_xnd_t_bitmap, METH_VARARGS, "get_xnd_t_bitmap(< capsule(xnd_t) >) -> < capsule( &xnd_t->bitmap ) >"},
  {"offsetof_xnd_t_bitmap", (PyCFunction)pyc_offsetof_xnd_t_bitmap, METH_VARARGS, "offsetof_xnd_t_bitmap() -> int"},
  {"get_xnd_t_index", (PyCFunction)pyc_get_xnd_t_index, METH_VARARGS, "get_xnd_t_index(< capsule(xnd_t) >) -> < capsule( &xnd_t->index ) >"},
  {"offsetof_xnd_t_index", (PyCFunction)pyc_offsetof_xnd_t_index, METH_VARARGS, "offsetof_xnd_t_index() -> int"},
  {"get_xnd_t_type", (PyCFunction)pyc_get_xnd_t_type, METH_VARARGS, "get_xnd_t_type(< capsule(xnd_t) >) -> < capsule( &xnd_t->type ) >"},
  {"offsetof_xnd_t_type", (PyCFunction)pyc_offsetof_xnd_t_type, METH_VARARGS, "offsetof_xnd_t_type() -> int"},
  {"get_xnd_t_ptr", (PyCFunction)pyc_get_xnd_t_ptr, METH_VARARGS, "get_xnd_t_ptr(< capsule(xnd_t) >) -> < capsule( &xnd_t->ptr ) >"},
  {"offsetof_xnd_t_ptr", (PyCFunction)pyc_offsetof_xnd_t_ptr, METH_VARARGS, "offsetof_xnd_t_ptr() -> int"},
  {"sizeof_xnd_master_t", (PyCFunction)pyc_sizeof_xnd_master_t, METH_VARARGS, "sizeof_xnd_master_t() -> int"},
  {"get_xnd_master_t_flags", (PyCFunction)pyc_get_xnd_master_t_flags, METH_VARARGS, "get_xnd_master_t_flags(< capsule(xnd_master_t) >) -> < capsule( &xnd_master_t->flags ) >"},
  {"offsetof_xnd_master_t_flags", (PyCFunction)pyc_offsetof_xnd_master_t_flags, METH_VARARGS, "offsetof_xnd_master_t_flags() -> int"},
  {"get_xnd_master_t_master", (PyCFunction)pyc_get_xnd_master_t_master, METH_VARARGS, "get_xnd_master_t_master(< capsule(xnd_master_t) >) -> < capsule( &xnd_master_t->master ) >"},
  {"offsetof_xnd_master_t_master", (PyCFunction)pyc_offsetof_xnd_master_t_master, METH_VARARGS, "offsetof_xnd_master_t_master() -> int"},
  {"sizeof_xnd_index_t", (PyCFunction)pyc_sizeof_xnd_index_t, METH_VARARGS, "sizeof_xnd_index_t() -> int"},
  {"get_xnd_index_t_tag", (PyCFunction)pyc_get_xnd_index_t_tag, METH_VARARGS, "get_xnd_index_t_tag(< capsule(xnd_index_t) >) -> < capsule( &xnd_index_t->tag ) >"},
  {"offsetof_xnd_index_t_tag", (PyCFunction)pyc_offsetof_xnd_index_t_tag, METH_VARARGS, "offsetof_xnd_index_t_tag() -> int"},
  {"get_xnd_index_t_Index", (PyCFunction)pyc_get_xnd_index_t_Index, METH_VARARGS, "get_xnd_index_t_Index(< capsule(xnd_index_t) >) -> < capsule( &xnd_index_t->Index ) >"},
  {"offsetof_xnd_index_t_Index", (PyCFunction)pyc_offsetof_xnd_index_t_Index, METH_VARARGS, "offsetof_xnd_index_t_Index() -> int"},
  {"get_xnd_index_t_FieldName", (PyCFunction)pyc_get_xnd_index_t_FieldName, METH_VARARGS, "get_xnd_index_t_FieldName(< capsule(xnd_index_t) >) -> < capsule( &xnd_index_t->FieldName ) >"},
  {"offsetof_xnd_index_t_FieldName", (PyCFunction)pyc_offsetof_xnd_index_t_FieldName, METH_VARARGS, "offsetof_xnd_index_t_FieldName() -> int"},
  {"get_xnd_index_t_Slice", (PyCFunction)pyc_get_xnd_index_t_Slice, METH_VARARGS, "get_xnd_index_t_Slice(< capsule(xnd_index_t) >) -> < capsule( &xnd_index_t->Slice ) >"},
  {"offsetof_xnd_index_t_Slice", (PyCFunction)pyc_offsetof_xnd_index_t_Slice, METH_VARARGS, "offsetof_xnd_index_t_Slice() -> int"},
  {"sizeof_xnd_view_t", (PyCFunction)pyc_sizeof_xnd_view_t, METH_VARARGS, "sizeof_xnd_view_t() -> int"},
  {"get_xnd_view_t_flags", (PyCFunction)pyc_get_xnd_view_t_flags, METH_VARARGS, "get_xnd_view_t_flags(< capsule(xnd_view_t) >) -> < capsule( &xnd_view_t->flags ) >"},
  {"offsetof_xnd_view_t_flags", (PyCFunction)pyc_offsetof_xnd_view_t_flags, METH_VARARGS, "offsetof_xnd_view_t_flags() -> int"},
  {"get_xnd_view_t_obj", (PyCFunction)pyc_get_xnd_view_t_obj, METH_VARARGS, "get_xnd_view_t_obj(< capsule(xnd_view_t) >) -> < capsule( &xnd_view_t->obj ) >"},
  {"offsetof_xnd_view_t_obj", (PyCFunction)pyc_offsetof_xnd_view_t_obj, METH_VARARGS, "offsetof_xnd_view_t_obj() -> int"},
  {"get_xnd_view_t_view", (PyCFunction)pyc_get_xnd_view_t_view, METH_VARARGS, "get_xnd_view_t_view(< capsule(xnd_view_t) >) -> < capsule( &xnd_view_t->view ) >"},
  {"offsetof_xnd_view_t_view", (PyCFunction)pyc_offsetof_xnd_view_t_view, METH_VARARGS, "offsetof_xnd_view_t_view() -> int"},
  {"sizeof_MemoryBlockObject", (PyCFunction)pyc_sizeof_MemoryBlockObject, METH_VARARGS, "sizeof_MemoryBlockObject() -> int"},
  {"get_MemoryBlockObject_type", (PyCFunction)pyc_get_MemoryBlockObject_type, METH_VARARGS, "get_MemoryBlockObject_type(< capsule(MemoryBlockObject) >) -> < capsule( &MemoryBlockObject->type ) >"},
  {"offsetof_MemoryBlockObject_type", (PyCFunction)pyc_offsetof_MemoryBlockObject_type, METH_VARARGS, "offsetof_MemoryBlockObject_type() -> int"},
  {"get_MemoryBlockObject_xnd", (PyCFunction)pyc_get_MemoryBlockObject_xnd, METH_VARARGS, "get_MemoryBlockObject_xnd(< capsule(MemoryBlockObject) >) -> < capsule( &MemoryBlockObject->xnd ) >"},
  {"offsetof_MemoryBlockObject_xnd", (PyCFunction)pyc_offsetof_MemoryBlockObject_xnd, METH_VARARGS, "offsetof_MemoryBlockObject_xnd() -> int"},
  {"get_MemoryBlockObject_view", (PyCFunction)pyc_get_MemoryBlockObject_view, METH_VARARGS, "get_MemoryBlockObject_view(< capsule(MemoryBlockObject) >) -> < capsule( &MemoryBlockObject->view ) >"},
  {"offsetof_MemoryBlockObject_view", (PyCFunction)pyc_offsetof_MemoryBlockObject_view, METH_VARARGS, "offsetof_MemoryBlockObject_view() -> int"},
  {"capsulate_XndObject", (PyCFunction)pyc_capsulate_XndObject, METH_VARARGS, NULL},
  {"sizeof_XndObject", (PyCFunction)pyc_sizeof_XndObject, METH_VARARGS, "sizeof_XndObject() -> int"},
  {"get_XndObject_mblock", (PyCFunction)pyc_get_XndObject_mblock, METH_VARARGS, "get_XndObject_mblock(< capsule(XndObject) >) -> < capsule( &XndObject->mblock ) >"},
  {"offsetof_XndObject_mblock", (PyCFunction)pyc_offsetof_XndObject_mblock, METH_VARARGS, "offsetof_XndObject_mblock() -> int"},
  {"get_XndObject_type", (PyCFunction)pyc_get_XndObject_type, METH_VARARGS, "get_XndObject_type(< capsule(XndObject) >) -> < capsule( &XndObject->type ) >"},
  {"offsetof_XndObject_type", (PyCFunction)pyc_offsetof_XndObject_type, METH_VARARGS, "offsetof_XndObject_type() -> int"},
  {"get_XndObject_xnd", (PyCFunction)pyc_get_XndObject_xnd, METH_VARARGS, "get_XndObject_xnd(< capsule(XndObject) >) -> < capsule( &XndObject->xnd ) >"},
  {"offsetof_XndObject_xnd", (PyCFunction)pyc_offsetof_XndObject_xnd, METH_VARARGS, "offsetof_XndObject_xnd() -> int"},
  {"sizeof_gm_kernel_set_t", (PyCFunction)pyc_sizeof_gm_kernel_set_t, METH_VARARGS, "sizeof_gm_kernel_set_t() -> int"},
  {"get_gm_kernel_set_t_sig", (PyCFunction)pyc_get_gm_kernel_set_t_sig, METH_VARARGS, "get_gm_kernel_set_t_sig(< capsule(gm_kernel_set_t) >) -> < capsule( &gm_kernel_set_t->sig ) >"},
  {"offsetof_gm_kernel_set_t_sig", (PyCFunction)pyc_offsetof_gm_kernel_set_t_sig, METH_VARARGS, "offsetof_gm_kernel_set_t_sig() -> int"},
  {"get_gm_kernel_set_t_constraint", (PyCFunction)pyc_get_gm_kernel_set_t_constraint, METH_VARARGS, "get_gm_kernel_set_t_constraint(< capsule(gm_kernel_set_t) >) -> < capsule( &gm_kernel_set_t->constraint ) >"},
  {"offsetof_gm_kernel_set_t_constraint", (PyCFunction)pyc_offsetof_gm_kernel_set_t_constraint, METH_VARARGS, "offsetof_gm_kernel_set_t_constraint() -> int"},
  {"get_gm_kernel_set_t_Opt", (PyCFunction)pyc_get_gm_kernel_set_t_Opt, METH_VARARGS, "get_gm_kernel_set_t_Opt(< capsule(gm_kernel_set_t) >) -> < capsule( &gm_kernel_set_t->Opt ) >"},
  {"offsetof_gm_kernel_set_t_Opt", (PyCFunction)pyc_offsetof_gm_kernel_set_t_Opt, METH_VARARGS, "offsetof_gm_kernel_set_t_Opt() -> int"},
  {"get_gm_kernel_set_t_C", (PyCFunction)pyc_get_gm_kernel_set_t_C, METH_VARARGS, "get_gm_kernel_set_t_C(< capsule(gm_kernel_set_t) >) -> < capsule( &gm_kernel_set_t->C ) >"},
  {"offsetof_gm_kernel_set_t_C", (PyCFunction)pyc_offsetof_gm_kernel_set_t_C, METH_VARARGS, "offsetof_gm_kernel_set_t_C() -> int"},
  {"get_gm_kernel_set_t_Fortran", (PyCFunction)pyc_get_gm_kernel_set_t_Fortran, METH_VARARGS, "get_gm_kernel_set_t_Fortran(< capsule(gm_kernel_set_t) >) -> < capsule( &gm_kernel_set_t->Fortran ) >"},
  {"offsetof_gm_kernel_set_t_Fortran", (PyCFunction)pyc_offsetof_gm_kernel_set_t_Fortran, METH_VARARGS, "offsetof_gm_kernel_set_t_Fortran() -> int"},
  {"get_gm_kernel_set_t_Xnd", (PyCFunction)pyc_get_gm_kernel_set_t_Xnd, METH_VARARGS, "get_gm_kernel_set_t_Xnd(< capsule(gm_kernel_set_t) >) -> < capsule( &gm_kernel_set_t->Xnd ) >"},
  {"offsetof_gm_kernel_set_t_Xnd", (PyCFunction)pyc_offsetof_gm_kernel_set_t_Xnd, METH_VARARGS, "offsetof_gm_kernel_set_t_Xnd() -> int"},
  {"get_gm_kernel_set_t_Strided", (PyCFunction)pyc_get_gm_kernel_set_t_Strided, METH_VARARGS, "get_gm_kernel_set_t_Strided(< capsule(gm_kernel_set_t) >) -> < capsule( &gm_kernel_set_t->Strided ) >"},
  {"offsetof_gm_kernel_set_t_Strided", (PyCFunction)pyc_offsetof_gm_kernel_set_t_Strided, METH_VARARGS, "offsetof_gm_kernel_set_t_Strided() -> int"},
  {"sizeof_gm_typedef_init_t", (PyCFunction)pyc_sizeof_gm_typedef_init_t, METH_VARARGS, "sizeof_gm_typedef_init_t() -> int"},
  {"get_gm_typedef_init_t_name", (PyCFunction)pyc_get_gm_typedef_init_t_name, METH_VARARGS, "get_gm_typedef_init_t_name(< capsule(gm_typedef_init_t) >) -> < capsule( &gm_typedef_init_t->name ) >"},
  {"offsetof_gm_typedef_init_t_name", (PyCFunction)pyc_offsetof_gm_typedef_init_t_name, METH_VARARGS, "offsetof_gm_typedef_init_t_name() -> int"},
  {"get_gm_typedef_init_t_type", (PyCFunction)pyc_get_gm_typedef_init_t_type, METH_VARARGS, "get_gm_typedef_init_t_type(< capsule(gm_typedef_init_t) >) -> < capsule( &gm_typedef_init_t->type ) >"},
  {"offsetof_gm_typedef_init_t_type", (PyCFunction)pyc_offsetof_gm_typedef_init_t_type, METH_VARARGS, "offsetof_gm_typedef_init_t_type() -> int"},
  {"get_gm_typedef_init_t_meth", (PyCFunction)pyc_get_gm_typedef_init_t_meth, METH_VARARGS, "get_gm_typedef_init_t_meth(< capsule(gm_typedef_init_t) >) -> < capsule( &gm_typedef_init_t->meth ) >"},
  {"offsetof_gm_typedef_init_t_meth", (PyCFunction)pyc_offsetof_gm_typedef_init_t_meth, METH_VARARGS, "offsetof_gm_typedef_init_t_meth() -> int"},
  {"sizeof_gm_kernel_init_t", (PyCFunction)pyc_sizeof_gm_kernel_init_t, METH_VARARGS, "sizeof_gm_kernel_init_t() -> int"},
  {"get_gm_kernel_init_t_name", (PyCFunction)pyc_get_gm_kernel_init_t_name, METH_VARARGS, "get_gm_kernel_init_t_name(< capsule(gm_kernel_init_t) >) -> < capsule( &gm_kernel_init_t->name ) >"},
  {"offsetof_gm_kernel_init_t_name", (PyCFunction)pyc_offsetof_gm_kernel_init_t_name, METH_VARARGS, "offsetof_gm_kernel_init_t_name() -> int"},
  {"get_gm_kernel_init_t_sig", (PyCFunction)pyc_get_gm_kernel_init_t_sig, METH_VARARGS, "get_gm_kernel_init_t_sig(< capsule(gm_kernel_init_t) >) -> < capsule( &gm_kernel_init_t->sig ) >"},
  {"offsetof_gm_kernel_init_t_sig", (PyCFunction)pyc_offsetof_gm_kernel_init_t_sig, METH_VARARGS, "offsetof_gm_kernel_init_t_sig() -> int"},
  {"get_gm_kernel_init_t_constraint", (PyCFunction)pyc_get_gm_kernel_init_t_constraint, METH_VARARGS, "get_gm_kernel_init_t_constraint(< capsule(gm_kernel_init_t) >) -> < capsule( &gm_kernel_init_t->constraint ) >"},
  {"offsetof_gm_kernel_init_t_constraint", (PyCFunction)pyc_offsetof_gm_kernel_init_t_constraint, METH_VARARGS, "offsetof_gm_kernel_init_t_constraint() -> int"},
  {"get_gm_kernel_init_t_Opt", (PyCFunction)pyc_get_gm_kernel_init_t_Opt, METH_VARARGS, "get_gm_kernel_init_t_Opt(< capsule(gm_kernel_init_t) >) -> < capsule( &gm_kernel_init_t->Opt ) >"},
  {"offsetof_gm_kernel_init_t_Opt", (PyCFunction)pyc_offsetof_gm_kernel_init_t_Opt, METH_VARARGS, "offsetof_gm_kernel_init_t_Opt() -> int"},
  {"get_gm_kernel_init_t_C", (PyCFunction)pyc_get_gm_kernel_init_t_C, METH_VARARGS, "get_gm_kernel_init_t_C(< capsule(gm_kernel_init_t) >) -> < capsule( &gm_kernel_init_t->C ) >"},
  {"offsetof_gm_kernel_init_t_C", (PyCFunction)pyc_offsetof_gm_kernel_init_t_C, METH_VARARGS, "offsetof_gm_kernel_init_t_C() -> int"},
  {"get_gm_kernel_init_t_Fortran", (PyCFunction)pyc_get_gm_kernel_init_t_Fortran, METH_VARARGS, "get_gm_kernel_init_t_Fortran(< capsule(gm_kernel_init_t) >) -> < capsule( &gm_kernel_init_t->Fortran ) >"},
  {"offsetof_gm_kernel_init_t_Fortran", (PyCFunction)pyc_offsetof_gm_kernel_init_t_Fortran, METH_VARARGS, "offsetof_gm_kernel_init_t_Fortran() -> int"},
  {"get_gm_kernel_init_t_Xnd", (PyCFunction)pyc_get_gm_kernel_init_t_Xnd, METH_VARARGS, "get_gm_kernel_init_t_Xnd(< capsule(gm_kernel_init_t) >) -> < capsule( &gm_kernel_init_t->Xnd ) >"},
  {"offsetof_gm_kernel_init_t_Xnd", (PyCFunction)pyc_offsetof_gm_kernel_init_t_Xnd, METH_VARARGS, "offsetof_gm_kernel_init_t_Xnd() -> int"},
  {"get_gm_kernel_init_t_Strided", (PyCFunction)pyc_get_gm_kernel_init_t_Strided, METH_VARARGS, "get_gm_kernel_init_t_Strided(< capsule(gm_kernel_init_t) >) -> < capsule( &gm_kernel_init_t->Strided ) >"},
  {"offsetof_gm_kernel_init_t_Strided", (PyCFunction)pyc_offsetof_gm_kernel_init_t_Strided, METH_VARARGS, "offsetof_gm_kernel_init_t_Strided() -> int"},
  {"sizeof_gm_kernel_t", (PyCFunction)pyc_sizeof_gm_kernel_t, METH_VARARGS, "sizeof_gm_kernel_t() -> int"},
  {"get_gm_kernel_t_flag", (PyCFunction)pyc_get_gm_kernel_t_flag, METH_VARARGS, "get_gm_kernel_t_flag(< capsule(gm_kernel_t) >) -> < capsule( &gm_kernel_t->flag ) >"},
  {"offsetof_gm_kernel_t_flag", (PyCFunction)pyc_offsetof_gm_kernel_t_flag, METH_VARARGS, "offsetof_gm_kernel_t_flag() -> int"},
  {"get_gm_kernel_t_set", (PyCFunction)pyc_get_gm_kernel_t_set, METH_VARARGS, "get_gm_kernel_t_set(< capsule(gm_kernel_t) >) -> < capsule( &gm_kernel_t->set ) >"},
  {"offsetof_gm_kernel_t_set", (PyCFunction)pyc_offsetof_gm_kernel_t_set, METH_VARARGS, "offsetof_gm_kernel_t_set() -> int"},
  {"sizeof_gm_func_t", (PyCFunction)pyc_sizeof_gm_func_t, METH_VARARGS, "sizeof_gm_func_t() -> int"},
  {"get_gm_func_t_name", (PyCFunction)pyc_get_gm_func_t_name, METH_VARARGS, "get_gm_func_t_name(< capsule(gm_func_t) >) -> < capsule( &gm_func_t->name ) >"},
  {"offsetof_gm_func_t_name", (PyCFunction)pyc_offsetof_gm_func_t_name, METH_VARARGS, "offsetof_gm_func_t_name() -> int"},
  {"get_gm_func_t_typecheck", (PyCFunction)pyc_get_gm_func_t_typecheck, METH_VARARGS, "get_gm_func_t_typecheck(< capsule(gm_func_t) >) -> < capsule( &gm_func_t->typecheck ) >"},
  {"offsetof_gm_func_t_typecheck", (PyCFunction)pyc_offsetof_gm_func_t_typecheck, METH_VARARGS, "offsetof_gm_func_t_typecheck() -> int"},
  {"get_gm_func_t_nkernels", (PyCFunction)pyc_get_gm_func_t_nkernels, METH_VARARGS, "get_gm_func_t_nkernels(< capsule(gm_func_t) >) -> < capsule( &gm_func_t->nkernels ) >"},
  {"offsetof_gm_func_t_nkernels", (PyCFunction)pyc_offsetof_gm_func_t_nkernels, METH_VARARGS, "offsetof_gm_func_t_nkernels() -> int"},
  {"get_gm_func_t_kernels", (PyCFunction)pyc_get_gm_func_t_kernels, METH_VARARGS, "get_gm_func_t_kernels(< capsule(gm_func_t) >) -> < capsule( &gm_func_t->kernels ) >"},
  {"offsetof_gm_func_t_kernels", (PyCFunction)pyc_offsetof_gm_func_t_kernels, METH_VARARGS, "offsetof_gm_func_t_kernels() -> int"},
  {"sizeof_GufuncObject", (PyCFunction)pyc_sizeof_GufuncObject, METH_VARARGS, "sizeof_GufuncObject() -> int"},
  {"get_GufuncObject_tbl", (PyCFunction)pyc_get_GufuncObject_tbl, METH_VARARGS, "get_GufuncObject_tbl(< capsule(GufuncObject) >) -> < capsule( &GufuncObject->tbl ) >"},
  {"offsetof_GufuncObject_tbl", (PyCFunction)pyc_offsetof_GufuncObject_tbl, METH_VARARGS, "offsetof_GufuncObject_tbl() -> int"},
  {"get_GufuncObject_name", (PyCFunction)pyc_get_GufuncObject_name, METH_VARARGS, "get_GufuncObject_name(< capsule(GufuncObject) >) -> < capsule( &GufuncObject->name ) >"},
  {"offsetof_GufuncObject_name", (PyCFunction)pyc_offsetof_GufuncObject_name, METH_VARARGS, "offsetof_GufuncObject_name() -> int"},
  {"sizeof_NRT_MemInfo", (PyCFunction)pyc_sizeof_NRT_MemInfo, METH_VARARGS, "sizeof_NRT_MemInfo() -> int"},
  {"get_NRT_MemInfo_refct", (PyCFunction)pyc_get_NRT_MemInfo_refct, METH_VARARGS, "get_NRT_MemInfo_refct(< capsule(NRT_MemInfo) >) -> < capsule( &NRT_MemInfo->refct ) >"},
  {"offsetof_NRT_MemInfo_refct", (PyCFunction)pyc_offsetof_NRT_MemInfo_refct, METH_VARARGS, "offsetof_NRT_MemInfo_refct() -> int"},
  {"get_NRT_MemInfo_dtor", (PyCFunction)pyc_get_NRT_MemInfo_dtor, METH_VARARGS, "get_NRT_MemInfo_dtor(< capsule(NRT_MemInfo) >) -> < capsule( &NRT_MemInfo->dtor ) >"},
  {"offsetof_NRT_MemInfo_dtor", (PyCFunction)pyc_offsetof_NRT_MemInfo_dtor, METH_VARARGS, "offsetof_NRT_MemInfo_dtor() -> int"},
  {"get_NRT_MemInfo_dtor_info", (PyCFunction)pyc_get_NRT_MemInfo_dtor_info, METH_VARARGS, "get_NRT_MemInfo_dtor_info(< capsule(NRT_MemInfo) >) -> < capsule( &NRT_MemInfo->dtor_info ) >"},
  {"offsetof_NRT_MemInfo_dtor_info", (PyCFunction)pyc_offsetof_NRT_MemInfo_dtor_info, METH_VARARGS, "offsetof_NRT_MemInfo_dtor_info() -> int"},
  {"get_NRT_MemInfo_data", (PyCFunction)pyc_get_NRT_MemInfo_data, METH_VARARGS, "get_NRT_MemInfo_data(< capsule(NRT_MemInfo) >) -> < capsule( &NRT_MemInfo->data ) >"},
  {"offsetof_NRT_MemInfo_data", (PyCFunction)pyc_offsetof_NRT_MemInfo_data, METH_VARARGS, "offsetof_NRT_MemInfo_data() -> int"},
  {"get_NRT_MemInfo_size", (PyCFunction)pyc_get_NRT_MemInfo_size, METH_VARARGS, "get_NRT_MemInfo_size(< capsule(NRT_MemInfo) >) -> < capsule( &NRT_MemInfo->size ) >"},
  {"offsetof_NRT_MemInfo_size", (PyCFunction)pyc_offsetof_NRT_MemInfo_size, METH_VARARGS, "offsetof_NRT_MemInfo_size() -> int"},
  {"sizeof_NRT_MemSys", (PyCFunction)pyc_sizeof_NRT_MemSys, METH_VARARGS, "sizeof_NRT_MemSys() -> int"},
  {"get_NRT_MemSys_atomic_dec", (PyCFunction)pyc_get_NRT_MemSys_atomic_dec, METH_VARARGS, "get_NRT_MemSys_atomic_dec(< capsule(NRT_MemSys) >) -> < capsule( &NRT_MemSys->atomic_dec ) >"},
  {"offsetof_NRT_MemSys_atomic_dec", (PyCFunction)pyc_offsetof_NRT_MemSys_atomic_dec, METH_VARARGS, "offsetof_NRT_MemSys_atomic_dec() -> int"},
  {"get_NRT_MemSys_atomic_cas", (PyCFunction)pyc_get_NRT_MemSys_atomic_cas, METH_VARARGS, "get_NRT_MemSys_atomic_cas(< capsule(NRT_MemSys) >) -> < capsule( &NRT_MemSys->atomic_cas ) >"},
  {"offsetof_NRT_MemSys_atomic_cas", (PyCFunction)pyc_offsetof_NRT_MemSys_atomic_cas, METH_VARARGS, "offsetof_NRT_MemSys_atomic_cas() -> int"},
  {"get_NRT_MemSys_shutting", (PyCFunction)pyc_get_NRT_MemSys_shutting, METH_VARARGS, "get_NRT_MemSys_shutting(< capsule(NRT_MemSys) >) -> < capsule( &NRT_MemSys->shutting ) >"},
  {"offsetof_NRT_MemSys_shutting", (PyCFunction)pyc_offsetof_NRT_MemSys_shutting, METH_VARARGS, "offsetof_NRT_MemSys_shutting() -> int"},
  {"get_NRT_MemSys_stats_mi_free", (PyCFunction)pyc_get_NRT_MemSys_stats_mi_free, METH_VARARGS, "get_NRT_MemSys_stats_mi_free(< capsule(NRT_MemSys) >) -> < capsule( &NRT_MemSys->stats_mi_free ) >"},
  {"offsetof_NRT_MemSys_stats_mi_free", (PyCFunction)pyc_offsetof_NRT_MemSys_stats_mi_free, METH_VARARGS, "offsetof_NRT_MemSys_stats_mi_free() -> int"},
  {"get_NRT_MemSys_allocator_malloc", (PyCFunction)pyc_get_NRT_MemSys_allocator_malloc, METH_VARARGS, "get_NRT_MemSys_allocator_malloc(< capsule(NRT_MemSys) >) -> < capsule( &NRT_MemSys->allocator.malloc ) >"},
  {"offsetof_NRT_MemSys_allocator_malloc", (PyCFunction)pyc_offsetof_NRT_MemSys_allocator_malloc, METH_VARARGS, "offsetof_NRT_MemSys_allocator_malloc() -> int"},
  {"get_NRT_MemSys_allocator_realloc", (PyCFunction)pyc_get_NRT_MemSys_allocator_realloc, METH_VARARGS, "get_NRT_MemSys_allocator_realloc(< capsule(NRT_MemSys) >) -> < capsule( &NRT_MemSys->allocator.realloc ) >"},
  {"offsetof_NRT_MemSys_allocator_realloc", (PyCFunction)pyc_offsetof_NRT_MemSys_allocator_realloc, METH_VARARGS, "offsetof_NRT_MemSys_allocator_realloc() -> int"},
  {"get_NRT_MemSys_allocator_free", (PyCFunction)pyc_get_NRT_MemSys_allocator_free, METH_VARARGS, "get_NRT_MemSys_allocator_free(< capsule(NRT_MemSys) >) -> < capsule( &NRT_MemSys->allocator.free ) >"},
  {"offsetof_NRT_MemSys_allocator_free", (PyCFunction)pyc_offsetof_NRT_MemSys_allocator_free, METH_VARARGS, "offsetof_NRT_MemSys_allocator_free() -> int"},
  {"value_int32", (PyCFunction)pyc_capsule_to_int32, METH_VARARGS, "(capsule) -> <capsule int32 value>"},
  {"value_int64", (PyCFunction)pyc_capsule_to_int64, METH_VARARGS, "(capsule) -> <capsule int64 value>"},
  {"value_bytes", (PyCFunction)pyc_capsule_to_bytes, METH_VARARGS, "(capsule[, size]) -> <capsule content as bytes>"},
  {NULL, NULL, 0, NULL}   /* sentinel */
};

static struct PyModuleDef xnd_structinfomodule = {
  PyModuleDef_HEAD_INIT,
  "xnd_structinfo",   /* name of module */
  NULL,             /* module documentation */
  -1,
  xnd_structinfo_methods
};

PyMODINIT_FUNC
PyInit_xnd_structinfo(void) {
  
  import_ndtypes();
  import_xnd();
  import_gumath();

  return PyModule_Create(&xnd_structinfomodule); 
}
#endif
