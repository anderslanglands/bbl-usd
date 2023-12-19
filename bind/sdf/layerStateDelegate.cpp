#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/layerStateDelegate.h>

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfLayerStateDelegateBase>("LayerStateDelegate")
        .m(&PXR_NS::SdfLayerStateDelegateBase::IsDirty)
        .m((void (PXR_NS::SdfLayerStateDelegateBase::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::VtValue &, PXR_NS::VtValue *))
            &PXR_NS::SdfLayerStateDelegateBase::SetField, "SetField_00")
        .m((void (PXR_NS::SdfLayerStateDelegateBase::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::SdfAbstractDataConstValue &, PXR_NS::VtValue *))
            &PXR_NS::SdfLayerStateDelegateBase::SetField, "SetField_01")
        .m((void (PXR_NS::SdfLayerStateDelegateBase::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::TfToken &, const PXR_NS::VtValue &, PXR_NS::VtValue *))
            &PXR_NS::SdfLayerStateDelegateBase::SetFieldDictValueByKey, "SetFieldDictValueByKey_00")
        .m((void (PXR_NS::SdfLayerStateDelegateBase::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::TfToken &, const PXR_NS::SdfAbstractDataConstValue &, PXR_NS::VtValue *))
            &PXR_NS::SdfLayerStateDelegateBase::SetFieldDictValueByKey, "SetFieldDictValueByKey_01")
        .m((void (PXR_NS::SdfLayerStateDelegateBase::*)(const PXR_NS::SdfPath &, double, const PXR_NS::VtValue &))
            &PXR_NS::SdfLayerStateDelegateBase::SetTimeSample, "SetTimeSample_00")
        .m((void (PXR_NS::SdfLayerStateDelegateBase::*)(const PXR_NS::SdfPath &, double, const PXR_NS::SdfAbstractDataConstValue &))
            &PXR_NS::SdfLayerStateDelegateBase::SetTimeSample, "SetTimeSample_01")
        .m(&PXR_NS::SdfLayerStateDelegateBase::CreateSpec)
        .m(&PXR_NS::SdfLayerStateDelegateBase::DeleteSpec)
        .m(&PXR_NS::SdfLayerStateDelegateBase::MoveSpec)
        .m((void (PXR_NS::SdfLayerStateDelegateBase::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::TfToken &))
            &PXR_NS::SdfLayerStateDelegateBase::PushChild, "PushChild_00")
        .m((void (PXR_NS::SdfLayerStateDelegateBase::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::SdfPath &))
            &PXR_NS::SdfLayerStateDelegateBase::PushChild, "PushChild_01")
        .m((void (PXR_NS::SdfLayerStateDelegateBase::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::TfToken &))
            &PXR_NS::SdfLayerStateDelegateBase::PopChild, "PopChild_00")
        .m((void (PXR_NS::SdfLayerStateDelegateBase::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::SdfPath &))
            &PXR_NS::SdfLayerStateDelegateBase::PopChild, "PopChild_01")
    ;


}

#endif


