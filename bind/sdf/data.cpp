#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/data.h>

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfData>()
        .ctor(bbl::Class<PXR_NS::SdfData>::Ctor<>(), "default")
        .m(&PXR_NS::SdfData::StreamsData)
        .m(&PXR_NS::SdfData::IsDetached)
        .m(&PXR_NS::SdfData::CreateSpec)
        .m(&PXR_NS::SdfData::HasSpec)
        .m(&PXR_NS::SdfData::EraseSpec)
        .m(&PXR_NS::SdfData::MoveSpec)
        .m(&PXR_NS::SdfData::GetSpecType)
        .m((bool (PXR_NS::SdfData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, PXR_NS::SdfAbstractDataValue *) const)
            &PXR_NS::SdfData::Has, "Has_00")
        .m((bool (PXR_NS::SdfData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, PXR_NS::VtValue *) const)
            &PXR_NS::SdfData::Has, "Has_01")
        .m((bool (PXR_NS::SdfData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, PXR_NS::SdfAbstractDataValue *, PXR_NS::SdfSpecType *) const)
            &PXR_NS::SdfData::HasSpecAndField, "HasSpecAndField_00")
        .m((bool (PXR_NS::SdfData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, PXR_NS::VtValue *, PXR_NS::SdfSpecType *) const)
            &PXR_NS::SdfData::HasSpecAndField, "HasSpecAndField_01")
        .m(&PXR_NS::SdfData::Get)
        .m((void (PXR_NS::SdfData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::VtValue &))
            &PXR_NS::SdfData::Set, "Set_00")
        .m((void (PXR_NS::SdfData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::SdfAbstractDataConstValue &))
            &PXR_NS::SdfData::Set, "Set_01")
        .m(&PXR_NS::SdfData::Erase)
        .m(&PXR_NS::SdfData::List)
        .m(&PXR_NS::SdfData::ListAllTimeSamples)
        .m(&PXR_NS::SdfData::ListTimeSamplesForPath)
        .m(&PXR_NS::SdfData::GetBracketingTimeSamples)
        .m(&PXR_NS::SdfData::GetNumTimeSamplesForPath)
        .m(&PXR_NS::SdfData::GetBracketingTimeSamplesForPath)
        .m(&PXR_NS::SdfData::SetTimeSample)
        .m(&PXR_NS::SdfData::EraseTimeSample)
    ;
}

#endif


