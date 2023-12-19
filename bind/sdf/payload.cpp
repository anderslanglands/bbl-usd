#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/payload.h>

namespace bblext {

PXR_NS::SdfPayload* Payload_from_asset_path(char const* assetPath) {
    return new PXR_NS::SdfPayload(assetPath);
}

PXR_NS::SdfPayload*
Payload_from_asset_path_and_prim_path(char const* assetPath,
                                      PXR_NS::SdfPath const& primPath) {
    return new PXR_NS::SdfPayload(assetPath, primPath);
}

PXR_NS::SdfPayload* Payload_from_asset_path_and_prim_path_and_layer_offset(
    char const* assetPath, PXR_NS::SdfPath const& primPath,
    PXR_NS::SdfLayerOffset const& layerOffset) {
    return new PXR_NS::SdfPayload(assetPath, primPath, layerOffset);
}

}


BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfPayload>("Payload")
        .ctor(bbl::Class<PXR_NS::SdfPayload>::Ctor<>(), "new")
        .m(&PXR_NS::SdfPayload::GetAssetPath)
        .m(&PXR_NS::SdfPayload::SetAssetPath)
        .m(&PXR_NS::SdfPayload::GetPrimPath)
        .m(&PXR_NS::SdfPayload::SetPrimPath)
        .m(&PXR_NS::SdfPayload::GetLayerOffset)
        .m(&PXR_NS::SdfPayload::SetLayerOffset)
        .m(&PXR_NS::SdfPayload::operator==, "op_eq")
        .m(&PXR_NS::SdfPayload::operator<, "op_lt")
        ;

    bbl::fn(&bblext::Payload_from_asset_path);
    bbl::fn(&bblext::Payload_from_asset_path_and_prim_path);
    bbl::fn(&bblext::Payload_from_asset_path_and_prim_path_and_layer_offset);

    bbl::Class<PXR_NS::SdfPayloadVector>("PayloadVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfPayload)
    ;
}

#endif


