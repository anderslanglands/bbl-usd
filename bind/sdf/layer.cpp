#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/layer.h>

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfLayer>("Layer")
        // External References
        .m(&PXR_NS::SdfLayer::GetExternalReferences)
        .m(&PXR_NS::SdfLayer::UpdateExternalReference)
        .m(&PXR_NS::SdfLayer::GetCompositionAssetDependencies)
        .m(&PXR_NS::SdfLayer::UpdateCompositionAssetDependency)
        .m(&PXR_NS::SdfLayer::GetExternalAssetDependencies)

        // Fields
        .m(&PXR_NS::SdfLayer::GetSpecType)
        .m(&PXR_NS::SdfLayer::HasSpec)
        .m(&PXR_NS::SdfLayer::ListFields)
        .m((bool (PXR_NS::SdfLayer::*)(PXR_NS::SdfPath const&, PXR_NS::TfToken const&, PXR_NS::VtValue*) const)
            &PXR_NS::SdfLayer::HasField)
        .m((bool (PXR_NS::SdfLayer::*)(PXR_NS::SdfPath const&, PXR_NS::TfToken const&, PXR_NS::TfToken const&, PXR_NS::VtValue*) const)
            &PXR_NS::SdfLayer::HasFieldDictKey)
        .m(&PXR_NS::SdfLayer::GetField)
        .m(&PXR_NS::SdfLayer::GetFieldDictValueByKey)
        .m((void (PXR_NS::SdfLayer::*)(PXR_NS::SdfPath const&, PXR_NS::TfToken const&, PXR_NS::VtValue const&))
            &PXR_NS::SdfLayer::SetField)
        .m((void (PXR_NS::SdfLayer::*)(PXR_NS::SdfPath const&, PXR_NS::TfToken const&, PXR_NS::TfToken const&, PXR_NS::VtValue const&))
            &PXR_NS::SdfLayer::SetFieldDictValueByKey)
        .m(&PXR_NS::SdfLayer::EraseField)
        .m(&PXR_NS::SdfLayer::EraseFieldDictValueByKey)

        // Metadata
        .m(&PXR_NS::SdfLayer::GetColorConfiguration)
        .m(&PXR_NS::SdfLayer::SetColorConfiguration)
        .m(&PXR_NS::SdfLayer::HasColorConfiguration)
        .m(&PXR_NS::SdfLayer::ClearColorConfiguration)
        .m(&PXR_NS::SdfLayer::GetColorManagementSystem)
        .m(&PXR_NS::SdfLayer::SetColorManagementSystem)
        .m(&PXR_NS::SdfLayer::HasColorManagementSystem)
        .m(&PXR_NS::SdfLayer::ClearColorManagementSystem)
        .m(&PXR_NS::SdfLayer::GetComment)
        .m(&PXR_NS::SdfLayer::SetComment)
        .m(&PXR_NS::SdfLayer::GetDefaultPrim)
        .m(&PXR_NS::SdfLayer::SetDefaultPrim)
        .m(&PXR_NS::SdfLayer::HasDefaultPrim)
        .m(&PXR_NS::SdfLayer::ClearDefaultPrim)
        .m(&PXR_NS::SdfLayer::GetDocumentation)
        .m(&PXR_NS::SdfLayer::SetDocumentation)
        .m(&PXR_NS::SdfLayer::GetStartTimeCode)
        .m(&PXR_NS::SdfLayer::SetStartTimeCode)
        .m(&PXR_NS::SdfLayer::HasStartTimeCode)
        .m(&PXR_NS::SdfLayer::ClearStartTimeCode)
        .m(&PXR_NS::SdfLayer::GetEndTimeCode)
        .m(&PXR_NS::SdfLayer::SetEndTimeCode)
        .m(&PXR_NS::SdfLayer::HasEndTimeCode)
        .m(&PXR_NS::SdfLayer::ClearEndTimeCode)
        .m(&PXR_NS::SdfLayer::GetTimeCodesPerSecond)
        .m(&PXR_NS::SdfLayer::SetTimeCodesPerSecond)
        .m(&PXR_NS::SdfLayer::HasTimeCodesPerSecond)
        .m(&PXR_NS::SdfLayer::ClearTimeCodesPerSecond)
        .m(&PXR_NS::SdfLayer::GetFramesPerSecond)
        .m(&PXR_NS::SdfLayer::SetFramesPerSecond)
        .m(&PXR_NS::SdfLayer::HasFramesPerSecond)
        .m(&PXR_NS::SdfLayer::ClearFramesPerSecond)
        .m(&PXR_NS::SdfLayer::GetFramePrecision)
        .m(&PXR_NS::SdfLayer::SetFramePrecision)
        .m(&PXR_NS::SdfLayer::HasFramePrecision)
        .m(&PXR_NS::SdfLayer::ClearFramePrecision)
        .m(&PXR_NS::SdfLayer::GetOwner)
        .m(&PXR_NS::SdfLayer::SetOwner)
        .m(&PXR_NS::SdfLayer::HasOwner)
        .m(&PXR_NS::SdfLayer::ClearOwner)
        .m(&PXR_NS::SdfLayer::GetSessionOwner)
        .m(&PXR_NS::SdfLayer::SetSessionOwner)
        .m(&PXR_NS::SdfLayer::HasSessionOwner)
        .m(&PXR_NS::SdfLayer::ClearSessionOwner)
        .m(&PXR_NS::SdfLayer::GetHasOwnedSubLayers)
        .m(&PXR_NS::SdfLayer::SetHasOwnedSubLayers)
        .m(&PXR_NS::SdfLayer::GetCustomLayerData)
        .m(&PXR_NS::SdfLayer::SetCustomLayerData)
        .m(&PXR_NS::SdfLayer::HasCustomLayerData)
        .m(&PXR_NS::SdfLayer::ClearCustomLayerData)
        .m(&PXR_NS::SdfLayer::GetExpressionVariables)
        .m(&PXR_NS::SdfLayer::SetExpressionVariables)
        .m(&PXR_NS::SdfLayer::HasExpressionVariables)
        .m(&PXR_NS::SdfLayer::ClearExpressionVariables)

        // Sublayers
        .m(&PXR_NS::SdfLayer::GetSubLayerPaths)
        .m(&PXR_NS::SdfLayer::SetSubLayerPaths)
        .m(&PXR_NS::SdfLayer::GetNumSubLayerPaths)
        .m(&PXR_NS::SdfLayer::InsertSubLayerPath)
        .m(&PXR_NS::SdfLayer::RemoveSubLayerPath)
        .m(&PXR_NS::SdfLayer::GetSubLayerOffsets)
        .m(&PXR_NS::SdfLayer::GetSubLayerOffset)
        .m(&PXR_NS::SdfLayer::SetSubLayerOffset)

        // Lookup
        .m(&PXR_NS::SdfLayer::GetPseudoRoot)
        .m(&PXR_NS::SdfLayer::GetObjectAtPath)
        .m(&PXR_NS::SdfLayer::GetPrimAtPath)
        .m(&PXR_NS::SdfLayer::GetPropertyAtPath)
        .m(&PXR_NS::SdfLayer::GetAttributeAtPath)
        .m(&PXR_NS::SdfLayer::GetRelationshipAtPath)

        // Permissions
        .m(&PXR_NS::SdfLayer::PermissionToEdit)
        .m(&PXR_NS::SdfLayer::PermissionToSave)
        .m(&PXR_NS::SdfLayer::SetPermissionToEdit)
        .m(&PXR_NS::SdfLayer::SetPermissionToSave)

        // Batch namespace editing
        .m(&PXR_NS::SdfLayer::CanApply)
        .m(&PXR_NS::SdfLayer::Apply)

        // Layer state
        .m(&PXR_NS::SdfLayer::IsDirty)

        // Time sample API
        .m(&PXR_NS::SdfLayer::ListAllTimeSamples)
        .m(&PXR_NS::SdfLayer::ListTimeSamplesForPath)
        .m(&PXR_NS::SdfLayer::GetBracketingTimeSamplesForPath)
        .m(&PXR_NS::SdfLayer::GetBracketingTimeSamples)
        .m(&PXR_NS::SdfLayer::GetNumTimeSamplesForPath)
        .m((bool (PXR_NS::SdfLayer::*)(PXR_NS::SdfPath const&, double, PXR_NS::VtValue*) const)
            &PXR_NS::SdfLayer::QueryTimeSample)
        .m((void (PXR_NS::SdfLayer::*)(PXR_NS::SdfPath const&, double, PXR_NS::VtValue const&))
            &PXR_NS::SdfLayer::SetTimeSample)
        .m(&PXR_NS::SdfLayer::EraseTimeSample)

        // static
        .m(&PXR_NS::SdfLayer::DumpLayerInfo)
    ;

    bbl::Class<PXR_NS::SdfLayerHandle>("LayerHandle")
        .smartptr_to<PXR_NS::SdfLayer>()
    ;

    bbl::Class<PXR_NS::SdfLayerRefPtr>("LayerRefPtr")
        .smartptr_to<PXR_NS::SdfLayer>()
    ;

    bbl::Class<PXR_NS::SdfLayerHandleVector>("LayerHandleVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfLayerHandle)
    ;

    bbl::Class<PXR_NS::SdfLayerHints>("LayerHints")
        .value_type()
        .f(&PXR_NS::SdfLayerHints::mightHaveRelocates)
    ;


}

#endif


