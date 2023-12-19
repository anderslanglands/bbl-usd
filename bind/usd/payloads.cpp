#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/payloads.h>

BBL_MODULE(usd) {
    // clang-format off

    bbl::Class<PXR_NS::UsdPayloads>("Payloads")
        .m((bool (PXR_NS::UsdPayloads::*)(PXR_NS::SdfPayload const&, PXR_NS::UsdListPosition))
            &PXR_NS::UsdPayloads::AddPayload
        )
        .m((bool (PXR_NS::UsdPayloads::*)(std::string const&, PXR_NS::SdfPath const&, PXR_NS::SdfLayerOffset const&, PXR_NS::UsdListPosition))
            &PXR_NS::UsdPayloads::AddPayload, "AddPayload_with_identifier_and_path"
        )
        .m((bool (PXR_NS::UsdPayloads::*)(std::string const&, PXR_NS::SdfLayerOffset const&, PXR_NS::UsdListPosition))
            &PXR_NS::UsdPayloads::AddPayload, "AddPayload_with_identifier"
        )
        .m(&PXR_NS::UsdPayloads::AddInternalPayload)
        .m(&PXR_NS::UsdPayloads::RemovePayload)
        .m(&PXR_NS::UsdPayloads::ClearPayloads)
        .m(&PXR_NS::UsdPayloads::SetPayloads)
        .m((PXR_NS::UsdPrim const&(PXR_NS::UsdPayloads::*)() const)
            &PXR_NS::UsdPayloads::GetPrim
        )
        .m(&PXR_NS::UsdPayloads::operator bool, "op_bool")
    ;

}

#endif

