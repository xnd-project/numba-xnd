import ndtypes
import xnd_structinfo as xinfo

# print('\n'.join(sorted(dir(xinfo))))
n = ndtypes.ndt("2 * 3 * float64")
print(n)
cn = xinfo.capsulate_NdtObject(n)
ndt = xinfo.get_NdtObject_ndt(cn)


def show_ndt_members(ndt, tab=""):

    tag = xinfo.value_int32(xinfo.get_ndt_t_tag(ndt))
    access = xinfo.value_int32(xinfo.get_ndt_t_access(ndt))
    flags = xinfo.value_int32(xinfo.get_ndt_t_flags(ndt))
    ndim = xinfo.value_int32(xinfo.get_ndt_t_ndim(ndt))
    datasize = xinfo.value_int64(xinfo.get_ndt_t_datasize(ndt))
    shape = xinfo.value_int64(xinfo.get_ndt_t_FixedDim_shape(ndt))

    print(
        f"{tab}tag={tag}, access={access}, flags={flags}, ndim={ndim}, datasize={datasize}"
    )

    if ndim > 0:
        show_ndt_members(xinfo.get_ndt_t_FixedDim_type(ndt), tab=tab + "  ")


show_ndt_members(ndt)
