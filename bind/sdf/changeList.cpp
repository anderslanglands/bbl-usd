#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/changeList.h>

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfChangeList>("ChangeList")
    #if 0 /// XXX: these are failing to link
        .ctor(bbl::Class<PXR_NS::SdfChangeList>::Ctor<>(), "default")
        .m(&PXR_NS::SdfChangeList::DidReplaceLayerContent)
        .m(&PXR_NS::SdfChangeList::DidReloadLayerContent)
        .m(&PXR_NS::SdfChangeList::DidChangeLayerResolvedPath)
        .m(&PXR_NS::SdfChangeList::DidChangeLayerIdentifier)
        .m(&PXR_NS::SdfChangeList::DidChangeSublayerPaths)
        .m(&PXR_NS::SdfChangeList::DidAddPrim)
        .m(&PXR_NS::SdfChangeList::DidRemovePrim)
        .m(&PXR_NS::SdfChangeList::DidReorderPrims)
        .m(&PXR_NS::SdfChangeList::DidChangePrimName)
        .m(&PXR_NS::SdfChangeList::DidChangePrimVariantSets)
        .m(&PXR_NS::SdfChangeList::DidChangePrimInheritPaths)
        .m(&PXR_NS::SdfChangeList::DidChangePrimReferences)
        .m(&PXR_NS::SdfChangeList::DidChangePrimSpecializes)
        .m(&PXR_NS::SdfChangeList::DidAddProperty)
        .m(&PXR_NS::SdfChangeList::DidRemoveProperty)
        .m(&PXR_NS::SdfChangeList::DidReorderProperties)
        .m(&PXR_NS::SdfChangeList::DidChangePropertyName)
        .m(&PXR_NS::SdfChangeList::DidChangeAttributeTimeSamples)
        .m(&PXR_NS::SdfChangeList::DidChangeAttributeConnection)
        .m(&PXR_NS::SdfChangeList::DidChangeRelationshipTargets)
        .m(&PXR_NS::SdfChangeList::DidAddTarget)
        .m(&PXR_NS::SdfChangeList::DidRemoveTarget)
        // r-vbalue reference
        // .m(&PXR_NS::SdfChangeList::DidChangeInfo)
        .m(&PXR_NS::SdfChangeList::GetEntryList)
        .m(&PXR_NS::SdfChangeList::GetEntry)
        .m(&PXR_NS::SdfChangeList::FindEntry)
        .m(&PXR_NS::SdfChangeList::begin)
        .m(&PXR_NS::SdfChangeList::cbegin)
        .m(&PXR_NS::SdfChangeList::end)
        .m(&PXR_NS::SdfChangeList::cend)
    #endif
    ;

    bbl::Class<PXR_NS::SdfChangeList::Entry>("SdfChangeListEntry")
        .ctor(bbl::Class<PXR_NS::SdfChangeList::Entry>::Ctor<>(), "default")
        // .m(&PXR_NS::SdfChangeList::Entry::FindInfoChange)
        .m(&PXR_NS::SdfChangeList::Entry::HasInfoChange)
    ;

    bbl::Class<PXR_NS::SdfChangeList::EntryList>("ChangeListEntryList")
    ;

    bbl::Enum<PXR_NS::SdfChangeList::SubLayerChangeType>("SdfChangeListSubLayerChangeType");

    bbl::Class<std::pair<PXR_NS::SdfPath, PXR_NS::SdfChangeList::Entry>>("PathChangeListEntryPair")
    ;

    bbl::Class<PXR_NS::SdfLayerChangeListVec>("LayerChangeListVec")
    ;

}

#endif


