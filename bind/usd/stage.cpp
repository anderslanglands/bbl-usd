#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/stage.h>

namespace bblext {

// make Stage_Open just take a char const* rather than having to build a std::string
PXR_NS::UsdStageRefPtr Stage_Open(char const* filename, PXR_NS::UsdStage::InitialLoadSet loadSet) {
    return PXR_NS::UsdStage::Open(filename, loadSet);
}

}

BBL_MODULE(usd) {
    // clang-format off

    bbl::Class<PXR_NS::UsdStage>("Stage")
        // Layer Serialization
        .m(&PXR_NS::UsdStage::Save)
        .m(&PXR_NS::UsdStage::SaveSessionLayers)

        // Working Set Management
        .m(&PXR_NS::UsdStage::Load)
        .m(&PXR_NS::UsdStage::Unload)
        .m(&PXR_NS::UsdStage::LoadAndUnload)
        .m(&PXR_NS::UsdStage::GetLoadSet)
        .m(&PXR_NS::UsdStage::FindLoadable)
        .m(&PXR_NS::UsdStage::GetLoadRules)
        .m(&PXR_NS::UsdStage::SetLoadRules)
        .m(&PXR_NS::UsdStage::GetPopulationMask)
        .m(&PXR_NS::UsdStage::SetPopulationMask)
        .m(&PXR_NS::UsdStage::ExpandPopulationMask) 

        // Layers and Edit Targets
        .m(&PXR_NS::UsdStage::GetSessionLayer)
        .m(&PXR_NS::UsdStage::GetRootLayer)
        .m(&PXR_NS::UsdStage::GetPathResolverContext)
        .m(&PXR_NS::UsdStage::ResolveIdentifierToEditTarget)
        .m(&PXR_NS::UsdStage::GetLayerStack)
        .m(&PXR_NS::UsdStage::GetUsedLayers)
        .m(&PXR_NS::UsdStage::HasLocalLayer)
        .m(&PXR_NS::UsdStage::GetEditTarget)
        .m((PXR_NS::UsdEditTarget(PXR_NS::UsdStage::*)(PXR_NS::SdfLayerHandle const&))
            &PXR_NS::UsdStage::GetEditTargetForLocalLayer
        )
        .m((PXR_NS::UsdEditTarget(PXR_NS::UsdStage::*)(size_t))
            &PXR_NS::UsdStage::GetEditTargetForLocalLayer, "GetEditTargetForLocalLayer_with_index"
        )
        .m(&PXR_NS::UsdStage::SetEditTarget)
        .m(&PXR_NS::UsdStage::MuteLayer)
        .m(&PXR_NS::UsdStage::UnmuteLayer)
        .m(&PXR_NS::UsdStage::MuteAndUnmuteLayers)
        .m(&PXR_NS::UsdStage::GetMutedLayers)
        .m(&PXR_NS::UsdStage::IsLayerMuted)

        // Flatten & Export Utilities
        .m(&PXR_NS::UsdStage::Export)
        .m(&PXR_NS::UsdStage::ExportToString)
        .m(&PXR_NS::UsdStage::Flatten)

        // PXR_NS::UsdStage Metadata
        .m((bool (PXR_NS::UsdStage::*)(PXR_NS::TfToken const&, PXR_NS::VtValue*) const)
            &PXR_NS::UsdStage::GetMetadata
        )
        .m(&PXR_NS::UsdStage::HasMetadata)
        .m(&PXR_NS::UsdStage::HasAuthoredMetadata)
        .m((bool (PXR_NS::UsdStage::*)(PXR_NS::TfToken const&, PXR_NS::VtValue const&) const)
            &PXR_NS::UsdStage::SetMetadata
        )
        .m(&PXR_NS::UsdStage::ClearMetadata)
        .m((bool (PXR_NS::UsdStage::*)(PXR_NS::TfToken const&, PXR_NS::TfToken const&, PXR_NS::VtValue*) const)
            &PXR_NS::UsdStage::GetMetadataByDictKey
        )
        .m(&PXR_NS::UsdStage::HasMetadataDictKey)
        .m(&PXR_NS::UsdStage::HasAuthoredMetadataDictKey)
        .m((bool (PXR_NS::UsdStage::*)(PXR_NS::TfToken const&, PXR_NS::TfToken const&, PXR_NS::VtValue const&) const)
            &PXR_NS::UsdStage::SetMetadataByDictKey
        )
        .m(&PXR_NS::UsdStage::ClearMetadataByDictKey)
        .m(&PXR_NS::UsdStage::WriteFallbackPrimTypes)

        // TimeCode API
        .m(&PXR_NS::UsdStage::GetStartTimeCode)
        .m(&PXR_NS::UsdStage::SetStartTimeCode)
        .m(&PXR_NS::UsdStage::GetEndTimeCode)
        .m(&PXR_NS::UsdStage::SetEndTimeCode)
        .m(&PXR_NS::UsdStage::HasAuthoredTimeCodeRange)
        .m(&PXR_NS::UsdStage::GetTimeCodesPerSecond)
        .m(&PXR_NS::UsdStage::SetTimeCodesPerSecond)
        .m(&PXR_NS::UsdStage::GetFramesPerSecond)
        .m(&PXR_NS::UsdStage::SetFramesPerSecond)

        // Attribute value Interpolation
        .m(&PXR_NS::UsdStage::SetInterpolationType)
        .m(&PXR_NS::UsdStage::GetInterpolationType)

        // Instancing
        .m(&PXR_NS::UsdStage::GetPrototypes)

        // Variant Management
        .m(&PXR_NS::UsdStage::GetGlobalVariantFallbacks)
        .m(&PXR_NS::UsdStage::SetGlobalVariantFallbacks)

        // Lifetime Management
        .m((PXR_NS::UsdStageRefPtr(*)(std::string const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::CreateNew
        )
        .m((PXR_NS::UsdStageRefPtr(*)(std::string const&, PXR_NS::SdfLayerHandle const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::CreateNew, "CreateNew_with_session_layer"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(std::string const&, PXR_NS::SdfLayerHandle const&, PXR_NS::ArResolverContext const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::CreateNew, "CreateNew_with_session_layer_and_resolver_context"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(std::string const&, PXR_NS::ArResolverContext const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::CreateNew, "CreateNew_with_resolver_context"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::CreateInMemory
        )
        .m((PXR_NS::UsdStageRefPtr(*)(std::string const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::CreateInMemory, "CreateInMemory_with_identifier"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(std::string const&, PXR_NS::ArResolverContext const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::CreateInMemory, "CreateInMemory_with_resolver_context"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(std::string const&, PXR_NS::SdfLayerHandle const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::CreateInMemory, "CreateInMemory_with_session_layer"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(std::string const&, PXR_NS::SdfLayerHandle const&, PXR_NS::ArResolverContext const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::CreateInMemory, "CreateInMemory_with_session_layer_and_resolver_context"
        )
        // we'll override this to take a char* instead
        // .m((PXR_NS::UsdStageRefPtr(*)(std::string const&, PXR_NS::UsdStage::InitialLoadSet))
        //     &PXR_NS::UsdStage::Open
        // )
        .m((PXR_NS::UsdStageRefPtr(*)(std::string const&, PXR_NS::ArResolverContext const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::Open, "Open_with_resolver_context"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(PXR_NS::SdfLayerHandle const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::Open, "Open_at_root"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(PXR_NS::SdfLayerHandle const&, PXR_NS::ArResolverContext const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::Open, "Open_at_root_with_resolver_context"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(PXR_NS::SdfLayerHandle const&, PXR_NS::SdfLayerHandle const&, PXR_NS::ArResolverContext const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::Open, "Open_at_root_with_session_layer_and_resolver_context"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(PXR_NS::SdfLayerHandle const&, PXR_NS::SdfLayerHandle const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::Open, "Open_at_root_with_session_layer"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(std::string const&, PXR_NS::UsdStagePopulationMask const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::OpenMasked
        )
        .m((PXR_NS::UsdStageRefPtr(*)(std::string const&, PXR_NS::ArResolverContext const&, PXR_NS::UsdStagePopulationMask const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::OpenMasked, "OpenMasked_with_resolver_context"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(PXR_NS::SdfLayerHandle const&, PXR_NS::UsdStagePopulationMask const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::OpenMasked, "OpenMasked_at_root"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(PXR_NS::SdfLayerHandle const&, PXR_NS::ArResolverContext const&, PXR_NS::UsdStagePopulationMask const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::OpenMasked, "OpenMasked_at_root_with_resolver_context"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(PXR_NS::SdfLayerHandle const&, PXR_NS::SdfLayerHandle const&, PXR_NS::ArResolverContext const&, PXR_NS::UsdStagePopulationMask const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::OpenMasked, "OpenMasked_at_root_with_session_layer_and_resolver_context"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(PXR_NS::SdfLayerHandle const&, PXR_NS::SdfLayerHandle const&, PXR_NS::UsdStagePopulationMask const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::OpenMasked, "OpenMasked_at_root_with_session_layer"
        )
        .m(&PXR_NS::UsdStage::IsSupportedFile)
        .m(&PXR_NS::UsdStage::Reload)

        // Color Configuration API
        .m(&PXR_NS::UsdStage::GetColorConfigFallbacks)
        .m(&PXR_NS::UsdStage::SetColorConfigFallbacks)
        .m(&PXR_NS::UsdStage::SetColorConfiguration)
        .m(&PXR_NS::UsdStage::GetColorConfiguration)
        .m(&PXR_NS::UsdStage::SetColorManagementSystem)
        .m(&PXR_NS::UsdStage::GetColorManagementSystem)

        // Prim Access, Creation and Mutation
        .m(&PXR_NS::UsdStage::GetPseudoRoot)
        .m(&PXR_NS::UsdStage::GetDefaultPrim)
        .m(&PXR_NS::UsdStage::SetDefaultPrim)
        .m(&PXR_NS::UsdStage::ClearDefaultPrim)
        .m(&PXR_NS::UsdStage::HasDefaultPrim)
        .m(&PXR_NS::UsdStage::GetPrimAtPath)
        .m(&PXR_NS::UsdStage::GetObjectAtPath)
        .m(&PXR_NS::UsdStage::GetPropertyAtPath)
        .m(&PXR_NS::UsdStage::GetAttributeAtPath)
        .m(&PXR_NS::UsdStage::GetRelationshipAtPath)
        // Cannot bind Traverse because it returns a PrimRange by value and PrimRange has no default constructor
        // Could possibly work around this by defining one ourselves that just zeroed the memory...
        .m(&PXR_NS::UsdStage::OverridePrim)
        .m(&PXR_NS::UsdStage::DefinePrim)
        .m(&PXR_NS::UsdStage::CreateClassPrim)
        .m(&PXR_NS::UsdStage::RemovePrim)
        ;

    bbl::fn(&bblext::Stage_Open);

    bbl::Enum<PXR_NS::UsdStage::InitialLoadSet>("StageInitialLoadSet");

    bbl::Class<PXR_NS::UsdStageRefPtr>("StageRefPtr")
        .ctor(bbl::Class<PXR_NS::UsdStageRefPtr>::Ctor<>(), "ctor")
        .smartptr_to<PXR_NS::UsdStage>()
        .m(&PXR_NS::UsdStageRefPtr::operator->, "get")
        .m(&PXR_NS::UsdStageRefPtr::operator!, "is_invalid")
    ;


    bbl::Class<PXR_NS::UsdStageRefPtrVector>("StageRefPtrVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdStageRefPtr)
    ;

    bbl::Class<PXR_NS::UsdStageWeakPtr>("StageWeakPtr")
        .ctor(bbl::Class<PXR_NS::UsdStageWeakPtr>::Ctor<>(), "ctor")
        .m(&PXR_NS::UsdStageWeakPtr::operator->, "get")
        .m(&PXR_NS::UsdStageWeakPtr::operator!, "is_invalid")
    ;

}

#endif

