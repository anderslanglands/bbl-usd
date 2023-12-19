#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/modelAPI.h>

BBL_MODULE(usd) {
    // clang-format off

    bbl::Class<PXR_NS::UsdModelAPI>("ModelAPI")
        .ctor(bbl::Class<PXR_NS::UsdModelAPI>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdModelAPI>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .m(&PXR_NS::UsdModelAPI::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdModelAPI::Get)
        .m(&PXR_NS::UsdModelAPI::GetKind)
        .m(&PXR_NS::UsdModelAPI::SetKind)
        .m(&PXR_NS::UsdModelAPI::IsKind)
        .m(&PXR_NS::UsdModelAPI::IsModel)
        .m(&PXR_NS::UsdModelAPI::IsGroup)
        .m(&PXR_NS::UsdModelAPI::GetAssetIdentifier)
        .m(&PXR_NS::UsdModelAPI::SetAssetIdentifier)
        .m(&PXR_NS::UsdModelAPI::GetAssetName)
        .m(&PXR_NS::UsdModelAPI::SetAssetName)
        .m(&PXR_NS::UsdModelAPI::GetAssetVersion)
        .m(&PXR_NS::UsdModelAPI::SetAssetVersion)
        .m(&PXR_NS::UsdModelAPI::GetPayloadAssetDependencies)
        .m(&PXR_NS::UsdModelAPI::SetPayloadAssetDependencies)
        .m(&PXR_NS::UsdModelAPI::GetAssetInfo)
        .m(&PXR_NS::UsdModelAPI::SetAssetInfo)
        /** TODO: instantiate this template
        .m(&PXR_NS::UsdModelAPI::_GetAssetInfoByKey)
        */
    ;

    bbl::Enum<PXR_NS::UsdModelAPI::KindValidation>("ModelAPIKindValidation");

}

#endif

