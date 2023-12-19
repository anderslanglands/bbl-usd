#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/stageCache.h>

BBL_MODULE(usd) {
    // clang-format off

    bbl::Class<PXR_NS::UsdStageCache>("StageCache")
        .ctor(bbl::Class<PXR_NS::UsdStageCache>::Ctor<>(), "default")
        .m(&PXR_NS::UsdStageCache::GetAllStages)
        .m(&PXR_NS::UsdStageCache::Size)
        .m(&PXR_NS::UsdStageCache::IsEmpty)
        .m(&PXR_NS::UsdStageCache::Find)
        .m((PXR_NS::UsdStageRefPtr (PXR_NS::UsdStageCache::*)(PXR_NS::SdfLayerHandle const&) const)
            &PXR_NS::UsdStageCache::FindOneMatching, "FindOneMatching_with_root_layer"
        )
        .m((PXR_NS::UsdStageRefPtr (PXR_NS::UsdStageCache::*)(PXR_NS::SdfLayerHandle const&, PXR_NS::SdfLayerHandle const&) const)
            &PXR_NS::UsdStageCache::FindOneMatching, "FindOneMatching_with_root_and_session_layer"
        )
        .m((PXR_NS::UsdStageRefPtr (PXR_NS::UsdStageCache::*)(PXR_NS::SdfLayerHandle const&, PXR_NS::ArResolverContext const&) const)
            &PXR_NS::UsdStageCache::FindOneMatching, "FindOneMatching_with_root_layer_and_resolver"
        )
        .m((PXR_NS::UsdStageRefPtr (PXR_NS::UsdStageCache::*)(PXR_NS::SdfLayerHandle const&, PXR_NS::SdfLayerHandle const&, PXR_NS::ArResolverContext const&) const)
            &PXR_NS::UsdStageCache::FindOneMatching, "FindOneMatching_with_root_and_session_layer_and_resolver"
        )
        .m((PXR_NS::UsdStageRefPtrVector (PXR_NS::UsdStageCache::*)(PXR_NS::SdfLayerHandle const&) const)
            &PXR_NS::UsdStageCache::FindAllMatching, "FindAllMatching_with_root_layer"
        )
        .m((PXR_NS::UsdStageRefPtrVector (PXR_NS::UsdStageCache::*)(PXR_NS::SdfLayerHandle const&, PXR_NS::SdfLayerHandle const&) const)
            &PXR_NS::UsdStageCache::FindAllMatching, "FindAllMatching_with_root_and_session_layer"
        )
        .m((PXR_NS::UsdStageRefPtrVector (PXR_NS::UsdStageCache::*)(PXR_NS::SdfLayerHandle const&, PXR_NS::ArResolverContext const&) const)
            &PXR_NS::UsdStageCache::FindAllMatching, "FindAllMatching_with_root_layer_and_resolver"
        )
        .m((PXR_NS::UsdStageRefPtrVector (PXR_NS::UsdStageCache::*)(PXR_NS::SdfLayerHandle const&, PXR_NS::SdfLayerHandle const&, PXR_NS::ArResolverContext const&) const)
            &PXR_NS::UsdStageCache::FindAllMatching, "FindAllMatching_with_root_and_session_layer_and_resolver"
        )
        .m(&PXR_NS::UsdStageCache::GetId)
        .m((bool (PXR_NS::UsdStageCache::*)(PXR_NS::UsdStageRefPtr const&) const)
            &PXR_NS::UsdStageCache::Contains
        )
        .m((bool (PXR_NS::UsdStageCache::*)(PXR_NS::UsdStageCache::Id) const)
            &PXR_NS::UsdStageCache::Contains, "Contains_id"
        )
        .m(&PXR_NS::UsdStageCache::Insert)
        .m((bool (PXR_NS::UsdStageCache::*)(PXR_NS::UsdStageRefPtr const&))
            &PXR_NS::UsdStageCache::Erase
        )
        .m((bool (PXR_NS::UsdStageCache::*)(PXR_NS::UsdStageCache::Id))
            &PXR_NS::UsdStageCache::Erase, "Erase_id"
        )
        .m((size_t (PXR_NS::UsdStageCache::*)(PXR_NS::SdfLayerHandle const&))
            &PXR_NS::UsdStageCache::EraseAll, "EraseAll_with_root_layer"
        )
        .m((size_t (PXR_NS::UsdStageCache::*)(PXR_NS::SdfLayerHandle const&, PXR_NS::SdfLayerHandle const&))
            &PXR_NS::UsdStageCache::EraseAll, "EraseAll_with_root_and_session_layer"
        )
        .m((size_t (PXR_NS::UsdStageCache::*)(PXR_NS::SdfLayerHandle const&, PXR_NS::SdfLayerHandle const&, PXR_NS::ArResolverContext const&))
            &PXR_NS::UsdStageCache::EraseAll, "EraseAll_with_root_and_session_layer_and_resolver"
        )
        .m(&PXR_NS::UsdStageCache::Clear)
        .m(&PXR_NS::UsdStageCache::SetDebugName)
        .m(&PXR_NS::UsdStageCache::GetDebugName)
        ;

    bbl::Class<PXR_NS::UsdStageCache::Id>("StageCacheId")
        .m(&PXR_NS::UsdStageCache::Id::ToLongInt)
        .m(&PXR_NS::UsdStageCache::Id::ToString)
        .m(&PXR_NS::UsdStageCache::Id::IsValid)
        .m(&PXR_NS::UsdStageCache::Id::FromLongInt)
        .m(&PXR_NS::UsdStageCache::Id::FromString)
        ;

    bbl::Class<PXR_NS::UsdStageCacheRequest>()
        .m((bool (PXR_NS::UsdStageCacheRequest::*)(const PXR_NS::UsdStageRefPtr &) const)
            &PXR_NS::UsdStageCacheRequest::IsSatisfiedBy, "IsSatisfiedBy_stage")
        .m((bool (PXR_NS::UsdStageCacheRequest::*)(const PXR_NS::UsdStageCacheRequest &) const)
            &PXR_NS::UsdStageCacheRequest::IsSatisfiedBy, "IsSatisfiedBy_cache_request")
        .m(&PXR_NS::UsdStageCacheRequest::Manufacture)
    ;

}

#endif

