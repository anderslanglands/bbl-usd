#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/references.h>

BBL_MODULE(usd) {
    // clang-format off

    bbl::Class<PXR_NS::UsdReferences>("References")
        .m((bool (PXR_NS::UsdReferences::*)(PXR_NS::SdfReference const&, PXR_NS::UsdListPosition))
            &PXR_NS::UsdReferences::AddReference
        )
        .m((bool (PXR_NS::UsdReferences::*)(std::string const&, PXR_NS::SdfPath const&, PXR_NS::SdfLayerOffset const&, PXR_NS::UsdListPosition))
            &PXR_NS::UsdReferences::AddReference, "AddReference_with_identifier_and_path"
        )
        .m((bool (PXR_NS::UsdReferences::*)(std::string const&, PXR_NS::SdfLayerOffset const&, PXR_NS::UsdListPosition))
            &PXR_NS::UsdReferences::AddReference, "AddReference_with_identifier"
        )
        .m(&PXR_NS::UsdReferences::AddInternalReference)
        .m(&PXR_NS::UsdReferences::RemoveReference)
        .m(&PXR_NS::UsdReferences::ClearReferences)
        .m(&PXR_NS::UsdReferences::SetReferences)
        .m((PXR_NS::UsdPrim const& (PXR_NS::UsdReferences::*)() const)
            &PXR_NS::UsdReferences::GetPrim
        )
        .m(&PXR_NS::UsdReferences::operator bool)
    ;

}

#endif

