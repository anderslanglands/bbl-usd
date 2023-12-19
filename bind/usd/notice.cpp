#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/notice.h>

BBL_MODULE(usd) {
    // clang-format off

    bbl::Class<PXR_NS::UsdNotice>("Notice")
    ;

    bbl::Class<PXR_NS::UsdNotice::StageNotice>("StageNotice")
        .ctor(bbl::Class<PXR_NS::UsdNotice::StageNotice>::Ctor<const PXR_NS::UsdStageWeakPtr &>("stage"), "ctor_00")
        .m(&PXR_NS::UsdNotice::StageNotice::GetStage)
    ;

    bbl::Class<PXR_NS::UsdNotice::StageContentsChanged>("StageContentsChanged")
        .ctor(bbl::Class<PXR_NS::UsdNotice::StageContentsChanged>::Ctor<const PXR_NS::UsdStageWeakPtr &>("stage"), "ctor_00")
    ;

    bbl::Class<PXR_NS::UsdNotice::ObjectsChanged>("ObjectsChanged")
        .m(&PXR_NS::UsdNotice::ObjectsChanged::AffectedObject)
        .m(&PXR_NS::UsdNotice::ObjectsChanged::ResyncedObject)
        .m(&PXR_NS::UsdNotice::ObjectsChanged::ChangedInfoOnly)
        .m(&PXR_NS::UsdNotice::ObjectsChanged::GetResyncedPaths)
        .m(&PXR_NS::UsdNotice::ObjectsChanged::GetChangedInfoOnlyPaths)
        .m((PXR_NS::TfTokenVector (PXR_NS::UsdNotice::ObjectsChanged::*)(const PXR_NS::UsdObject &) const)
            &PXR_NS::UsdNotice::ObjectsChanged::GetChangedFields, "GetChangedFields_00")
        .m((PXR_NS::TfTokenVector (PXR_NS::UsdNotice::ObjectsChanged::*)(const PXR_NS::SdfPath &) const)
            &PXR_NS::UsdNotice::ObjectsChanged::GetChangedFields, "GetChangedFields_01")
        .m((bool (PXR_NS::UsdNotice::ObjectsChanged::*)(const PXR_NS::UsdObject &) const)
            &PXR_NS::UsdNotice::ObjectsChanged::HasChangedFields, "HasChangedFields_00")
        .m((bool (PXR_NS::UsdNotice::ObjectsChanged::*)(const PXR_NS::SdfPath &) const)
            &PXR_NS::UsdNotice::ObjectsChanged::HasChangedFields, "HasChangedFields_01")
    ;

    bbl::Class<PXR_NS::UsdNotice::ObjectsChanged::PathRange>("ObjectsChangedPathRange")
        .ctor(bbl::Class<PXR_NS::UsdNotice::ObjectsChanged::PathRange>::Ctor<>(), "default")
        .m(&PXR_NS::UsdNotice::ObjectsChanged::PathRange::empty)
        .m(&PXR_NS::UsdNotice::ObjectsChanged::PathRange::size)
        .m(&PXR_NS::UsdNotice::ObjectsChanged::PathRange::begin)
        .m(&PXR_NS::UsdNotice::ObjectsChanged::PathRange::cbegin)
        .m(&PXR_NS::UsdNotice::ObjectsChanged::PathRange::end)
        .m(&PXR_NS::UsdNotice::ObjectsChanged::PathRange::cend)
        .m(&PXR_NS::UsdNotice::ObjectsChanged::PathRange::find)
    ;

    bbl::Class<PXR_NS::UsdNotice::ObjectsChanged::PathRange::iterator>("ObjectsChangedPathRangeIterator")
        .ctor(bbl::Class<PXR_NS::UsdNotice::ObjectsChanged::PathRange::iterator>::Ctor<>(), "default")
        .m(&PXR_NS::UsdNotice::ObjectsChanged::PathRange::iterator::GetChangedFields)
        .m(&PXR_NS::UsdNotice::ObjectsChanged::PathRange::iterator::HasChangedFields)
    ;

    bbl::Class<PXR_NS::UsdNotice::StageEditTargetChanged>("StageEditTargetChanged")
        .ctor(bbl::Class<PXR_NS::UsdNotice::StageEditTargetChanged>::Ctor<const PXR_NS::UsdStageWeakPtr &>("stage"), "ctor_00")
    ;

    bbl::Class<PXR_NS::UsdNotice::LayerMutingChanged>("LayerMutingChanged")
        .ctor(bbl::Class<PXR_NS::UsdNotice::LayerMutingChanged>::Ctor<const PXR_NS::UsdStageWeakPtr &, const std::vector<std::string> &, const std::vector<std::string> &>("stage", "mutedLayers", "unmutedLayers"), "ctor_00")
        .m(&PXR_NS::UsdNotice::LayerMutingChanged::GetMutedLayers)
        .m(&PXR_NS::UsdNotice::LayerMutingChanged::GetUnmutedLayers)
    ;


}

#endif

