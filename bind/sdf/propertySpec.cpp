#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/propertySpec.h>
#include <pxr/usd/sdf/layerOffset.h>

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfPropertySpec>("PropertySpec")
        .ctor(bbl::Class<PXR_NS::SdfPropertySpec>::Ctor<>(), "default")
        .m(&PXR_NS::SdfPropertySpec::GetName)
        .m(&PXR_NS::SdfPropertySpec::GetNameToken)
        .m(&PXR_NS::SdfPropertySpec::CanSetName)
        .m(&PXR_NS::SdfPropertySpec::SetName)
        .m(&PXR_NS::SdfPropertySpec::IsValidName)
        .m(&PXR_NS::SdfPropertySpec::GetOwner)
        .m(&PXR_NS::SdfPropertySpec::GetCustomData)
        .m(&PXR_NS::SdfPropertySpec::GetAssetInfo)
        .m(&PXR_NS::SdfPropertySpec::SetCustomData)
        .m(&PXR_NS::SdfPropertySpec::SetAssetInfo)
        .m(&PXR_NS::SdfPropertySpec::GetDisplayGroup)
        .m(&PXR_NS::SdfPropertySpec::SetDisplayGroup)
        .m(&PXR_NS::SdfPropertySpec::GetDisplayName)
        .m(&PXR_NS::SdfPropertySpec::SetDisplayName)
        .m(&PXR_NS::SdfPropertySpec::GetDocumentation)
        .m(&PXR_NS::SdfPropertySpec::SetDocumentation)
        .m(&PXR_NS::SdfPropertySpec::GetHidden)
        .m(&PXR_NS::SdfPropertySpec::SetHidden)
        .m(&PXR_NS::SdfPropertySpec::GetPermission)
        .m(&PXR_NS::SdfPropertySpec::SetPermission)
        .m(&PXR_NS::SdfPropertySpec::GetPrefix)
        .m(&PXR_NS::SdfPropertySpec::SetPrefix)
        .m(&PXR_NS::SdfPropertySpec::GetSuffix)
        .m(&PXR_NS::SdfPropertySpec::SetSuffix)
        .m(&PXR_NS::SdfPropertySpec::GetSymmetricPeer)
        .m(&PXR_NS::SdfPropertySpec::SetSymmetricPeer)
        .m(&PXR_NS::SdfPropertySpec::GetSymmetryArguments)
        .m(&PXR_NS::SdfPropertySpec::SetSymmetryArgument)
        .m(&PXR_NS::SdfPropertySpec::GetSymmetryFunction)
        .m(&PXR_NS::SdfPropertySpec::SetSymmetryFunction)
        .m(&PXR_NS::SdfPropertySpec::GetTimeSampleMap)
        .m(&PXR_NS::SdfPropertySpec::GetValueType)
        .m(&PXR_NS::SdfPropertySpec::GetTypeName)
        .m(&PXR_NS::SdfPropertySpec::GetDefaultValue)
        .m(&PXR_NS::SdfPropertySpec::SetDefaultValue)
        .m(&PXR_NS::SdfPropertySpec::HasDefaultValue)
        .m(&PXR_NS::SdfPropertySpec::ClearDefaultValue)
        .m(&PXR_NS::SdfPropertySpec::GetComment)
        .m(&PXR_NS::SdfPropertySpec::SetComment)
        .m(&PXR_NS::SdfPropertySpec::IsCustom)
        .m(&PXR_NS::SdfPropertySpec::SetCustom)
        .m(&PXR_NS::SdfPropertySpec::GetVariability)
        .m(&PXR_NS::SdfPropertySpec::HasOnlyRequiredFields)
    ;

    bbl::Class<PXR_NS::SdfPropertySpecHandle>("PropertySpecHandle")
        .smartptr_to<PXR_NS::SdfPropertySpec>()
    ;

    bbl::Class<PXR_NS::SdfPropertySpecHandleVector>("PropertySpecHandleVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfPropertySpecHandle)
    ;

    bbl::Class<std::pair<PXR_NS::SdfPropertySpecHandle, PXR_NS::SdfLayerOffset>>("PropertySpecHandleOffsetPair");

    bbl::Class<std::vector<std::pair<PXR_NS::SdfPropertySpecHandle, PXR_NS::SdfLayerOffset>>>("PropertySpecHandleOffsetPairVector")
        BBL_STD_VECTOR_METHODS((std::pair<PXR_NS::SdfPropertySpecHandle, PXR_NS::SdfLayerOffset>))
    ;

    bbl::Class<PXR_NS::SdfPropertySpecView>("PropertySpecView");

}

#endif


