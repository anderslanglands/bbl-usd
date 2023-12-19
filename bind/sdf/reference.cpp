#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/reference.h>

namespace bblext {

PXR_NS::SdfReference* Reference_from_asset_path(char const* assetPath) {
    return new PXR_NS::SdfReference(assetPath);
}

PXR_NS::SdfReference*
Reference_from_asset_path_and_prim_path(char const* assetPath,
                                        PXR_NS::SdfPath const& primPath) {
    return new PXR_NS::SdfReference(assetPath, primPath);
}

PXR_NS::SdfReference* Reference_from_asset_path_and_prim_path_and_layer_offset(
    char const* assetPath, PXR_NS::SdfPath const& primPath,
    PXR_NS::SdfLayerOffset const& layerOffset) {
    return new PXR_NS::SdfReference(assetPath, primPath, layerOffset);
}

PXR_NS::SdfReference*
Reference_from_asset_path_and_prim_path_and_layer_offset_and_custom_data(
    char const* assetPath, PXR_NS::SdfPath const& primPath,
    PXR_NS::SdfLayerOffset const& layerOffset,
    PXR_NS::VtDictionary const& customData) {
    return new PXR_NS::SdfReference(assetPath, primPath, layerOffset,
                                    customData);
}

}

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfReference>("Reference")
        .m(&PXR_NS::SdfReference::GetAssetPath)
        .m(&PXR_NS::SdfReference::SetAssetPath)
        .m(&PXR_NS::SdfReference::GetPrimPath)
        .m(&PXR_NS::SdfReference::SetPrimPath)
        .m(&PXR_NS::SdfReference::GetLayerOffset)
        .m(&PXR_NS::SdfReference::SetLayerOffset)
        .m(&PXR_NS::SdfReference::GetCustomData)
        .m((void (PXR_NS::SdfReference::*)(PXR_NS::VtDictionary const&))
            &PXR_NS::SdfReference::SetCustomData)
        .m((void (PXR_NS::SdfReference::*)(std::string const& name, PXR_NS::VtValue const&))
            &PXR_NS::SdfReference::SetCustomData, "SetCustomData_value")
        .m(&PXR_NS::SdfReference::SwapCustomData)
        .m(&PXR_NS::SdfReference::IsInternal)
        .m(&PXR_NS::SdfReference::operator==, "op_eq")
        .m(&PXR_NS::SdfReference::operator<, "op_lt")
        ;

    bbl::fn(&bblext::Reference_from_asset_path);
    bbl::fn(&bblext::Reference_from_asset_path_and_prim_path);
    bbl::fn(&bblext::Reference_from_asset_path_and_prim_path_and_layer_offset);
    bbl::fn(&bblext::Reference_from_asset_path_and_prim_path_and_layer_offset_and_custom_data);

    // bbl::Class<PXR_NS::SdfReferenceEditorProxy>("ReferenceEditorProxy");

    bbl::Class<PXR_NS::SdfReferenceVector>("ReferenceVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfReference);

}

#endif


