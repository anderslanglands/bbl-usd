#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/notice.h>



BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfNotice>("Notice")
    ;

    bbl::Class<PXR_NS::SdfNotice::Base>("NoticeBase")
        .ctor(bbl::Class<PXR_NS::SdfNotice::Base>::Ctor<>(), "default")
    ;

    bbl::Class<PXR_NS::SdfNotice::BaseLayersDidChange>("NoticeBaseLayersDidChange")
        .ctor(bbl::Class<PXR_NS::SdfNotice::BaseLayersDidChange>::Ctor<const PXR_NS::SdfLayerChangeListVec &, size_t>("changeVec", "serialNumber"), "ctor")
        .m(&PXR_NS::SdfNotice::BaseLayersDidChange::GetLayers)
        .m(&PXR_NS::SdfNotice::BaseLayersDidChange::GetChangeListVec)
        .m(&PXR_NS::SdfNotice::BaseLayersDidChange::begin)
        .m(&PXR_NS::SdfNotice::BaseLayersDidChange::cbegin)
        .m(&PXR_NS::SdfNotice::BaseLayersDidChange::end)
        .m(&PXR_NS::SdfNotice::BaseLayersDidChange::cend)
        .m(&PXR_NS::SdfNotice::BaseLayersDidChange::find)
        .m(&PXR_NS::SdfNotice::BaseLayersDidChange::count)
        .m(&PXR_NS::SdfNotice::BaseLayersDidChange::GetSerialNumber)
    ;

    bbl::Class<PXR_NS::SdfNotice::BaseLayersDidChange::const_iterator>("NoticeBaseLayersDidChangeConstIterator")
    ;

    bbl::Class<PXR_NS::SdfNotice::LayersDidChangeSentPerLayer>("NoticeLayersDidChangeSentPerLayer")
        .ctor(bbl::Class<PXR_NS::SdfNotice::LayersDidChangeSentPerLayer>::Ctor<const PXR_NS::SdfLayerChangeListVec &, size_t>("changeVec", "serialNumber"), "ctor")
    ;

    bbl::Class<PXR_NS::SdfNotice::LayersDidChange>("NoticeLayersDidChange")
        .ctor(bbl::Class<PXR_NS::SdfNotice::LayersDidChange>::Ctor<const PXR_NS::SdfLayerChangeListVec &, size_t>("changeVec", "serialNumber"), "ctor")
    ;

    bbl::Class<PXR_NS::SdfNotice::LayerInfoDidChange>("NoticeLayerInfoDidChange")
        .ctor(bbl::Class<PXR_NS::SdfNotice::LayerInfoDidChange>::Ctor<const PXR_NS::TfToken &>("key"), "ctor")
        .m(&PXR_NS::SdfNotice::LayerInfoDidChange::key)
    ;

    bbl::Class<PXR_NS::SdfNotice::LayerIdentifierDidChange>("NoticeLayerIdentifierDidChange")
        .ctor(bbl::Class<PXR_NS::SdfNotice::LayerIdentifierDidChange>::Ctor<const std::string &, const std::string &>("oldIdentifier", "newIdentifier"), "ctor")
        .m(&PXR_NS::SdfNotice::LayerIdentifierDidChange::GetOldIdentifier)
        .m(&PXR_NS::SdfNotice::LayerIdentifierDidChange::GetNewIdentifier)
    ;

    bbl::Class<PXR_NS::SdfNotice::LayerDidReplaceContent>("NoticeLayerDidReplaceContent")
    ;

    bbl::Class<PXR_NS::SdfNotice::LayerDidReloadContent>("NoticeLayerDidReloadContent")
    ;

    bbl::Class<PXR_NS::SdfNotice::LayerDidSaveLayerToFile>("NoticeDidSaveLayerToFile")
    ;

    bbl::Class<PXR_NS::SdfNotice::LayerDirtinessChanged>("NoticeLayerDirtinessChanged")
    ;

    bbl::Class<PXR_NS::SdfNotice::LayerMutenessChanged>("NoticeLayerMutenessChanged")
        .ctor(bbl::Class<PXR_NS::SdfNotice::LayerMutenessChanged>::Ctor<const std::string &, bool>("layerPath", "wasMuted"), "ctor")
        .m(&PXR_NS::SdfNotice::LayerMutenessChanged::GetLayerPath)
        .m(&PXR_NS::SdfNotice::LayerMutenessChanged::WasMuted)
    ;


}

#endif


