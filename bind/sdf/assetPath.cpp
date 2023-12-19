#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/assetPath.h>
#include <pxr/base/vt/array.h>

namespace bblext {

PXR_NS::SdfAssetPath AssetPath_from_path(char const* path) {
    return PXR_NS::SdfAssetPath(path);
}

PXR_NS::SdfAssetPath AssetPath_from_path_and_resolved_path(char const* path, char const* resolved_path) {
    return PXR_NS::SdfAssetPath(path, resolved_path);
}

char const* AssetPath_GetAssetPath(PXR_NS::SdfAssetPath const& path) {
    return path.GetAssetPath().c_str();
}

char const* AssetPath_GetResolvedPath(PXR_NS::SdfAssetPath const& path) {
    return path.GetResolvedPath().c_str();
}

}

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfAssetPath>("AssetPath")
        .ctor(bbl::Class<PXR_NS::SdfAssetPath>::Ctor<>(), "new")
        .m(&pxrInternal_v0_23__pxrReserved__::SdfAssetPath::operator==, "op_eq")
        .m(&pxrInternal_v0_23__pxrReserved__::SdfAssetPath::operator!=, "op_neq")
        .m(&pxrInternal_v0_23__pxrReserved__::SdfAssetPath::operator<, "op_lt")
    ;

    // we bind specific wrapper functions for these as there's no point
    // generating an intermediary string&
    bbl::fn(&bblext::AssetPath_from_path);
    bbl::fn(&bblext::AssetPath_from_path_and_resolved_path);
    bbl::fn(&bblext::AssetPath_GetAssetPath);
    bbl::fn(&bblext::AssetPath_GetResolvedPath);

    bbl::Class<PXR_NS::VtArray<PXR_NS::SdfAssetPath>>("AssetPathArray");

}

#endif


