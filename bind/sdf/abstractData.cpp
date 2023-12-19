#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/abstractData.h>

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfAbstractData>("AbstractData")
        .m(&PXR_NS::SdfAbstractData::CopyFrom)
        .m(&PXR_NS::SdfAbstractData::StreamsData)
        .m(&PXR_NS::SdfAbstractData::IsDetached)
        .m(&PXR_NS::SdfAbstractData::IsEmpty)
        .m(&PXR_NS::SdfAbstractData::Equals)
        // requires binding std::ostream
        // .m(&PXR_NS::SdfAbstractData::WriteToStream)
        .m(&PXR_NS::SdfAbstractData::CreateSpec)
        .m(&PXR_NS::SdfAbstractData::HasSpec)
        .m(&PXR_NS::SdfAbstractData::EraseSpec)
        .m(&PXR_NS::SdfAbstractData::MoveSpec)
        .m(&PXR_NS::SdfAbstractData::GetSpecType)
        // missing SdfAbstractDataSpecVisitor
        // .m(&PXR_NS::SdfAbstractData::VisitSpecs)
        .m((bool (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, PXR_NS::SdfAbstractDataValue *) const)
            &PXR_NS::SdfAbstractData::Has, "Has_00")
        .m((bool (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, PXR_NS::VtValue *) const)
            &PXR_NS::SdfAbstractData::Has, "Has_01")
        .m((bool (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, PXR_NS::SdfAbstractDataValue *, PXR_NS::SdfSpecType *) const)
            &PXR_NS::SdfAbstractData::HasSpecAndField, "HasSpecAndField_00")
        .m((bool (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, PXR_NS::VtValue *, PXR_NS::SdfSpecType *) const)
            &PXR_NS::SdfAbstractData::HasSpecAndField, "HasSpecAndField_01")
        .m(&PXR_NS::SdfAbstractData::Get)
        // missing type_info
        // .m(&PXR_NS::SdfAbstractData::GetTypeid)
        .m((void (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::VtValue &))
            &PXR_NS::SdfAbstractData::Set, "Set_00")
        .m((void (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::SdfAbstractDataConstValue &))
            &PXR_NS::SdfAbstractData::Set, "Set_01")
        .m(&PXR_NS::SdfAbstractData::Erase)
        .m(&PXR_NS::SdfAbstractData::List)
        /** TODO: instantiate this template
        .m(&PXR_NS::SdfAbstractData::GetAs)
        */
        .m((bool (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::TfToken &, PXR_NS::SdfAbstractDataValue *) const)
            &PXR_NS::SdfAbstractData::HasDictKey, "HasDictKey_00")
        .m((bool (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::TfToken &, PXR_NS::VtValue *) const)
            &PXR_NS::SdfAbstractData::HasDictKey, "HasDictKey_01")
        .m(&PXR_NS::SdfAbstractData::GetDictValueByKey)
        .m((void (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::TfToken &, const PXR_NS::VtValue &))
            &PXR_NS::SdfAbstractData::SetDictValueByKey, "SetDictValueByKey_00")
        .m((void (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::TfToken &, const PXR_NS::SdfAbstractDataConstValue &))
            &PXR_NS::SdfAbstractData::SetDictValueByKey, "SetDictValueByKey_01")
        .m(&PXR_NS::SdfAbstractData::EraseDictValueByKey)
        .m(&PXR_NS::SdfAbstractData::ListDictKeys)
        .m(&PXR_NS::SdfAbstractData::ListAllTimeSamples)
        .m(&PXR_NS::SdfAbstractData::ListTimeSamplesForPath)
        .m(&PXR_NS::SdfAbstractData::GetBracketingTimeSamples)
        .m(&PXR_NS::SdfAbstractData::GetNumTimeSamplesForPath)
        .m(&PXR_NS::SdfAbstractData::GetBracketingTimeSamplesForPath)
        .m((bool (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, double, PXR_NS::VtValue *) const)
            &PXR_NS::SdfAbstractData::QueryTimeSample, "QueryTimeSample_00")
        .m((bool (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, double, PXR_NS::SdfAbstractDataValue *) const)
            &PXR_NS::SdfAbstractData::QueryTimeSample, "QueryTimeSample_01")
        .m(&PXR_NS::SdfAbstractData::SetTimeSample)
        .m(&PXR_NS::SdfAbstractData::EraseTimeSample)
    ;

    bbl::Class<PXR_NS::SdfAbstractDataPtr>("AbstractDataPtr")
        .smartptr_to<PXR_NS::SdfAbstractData>()
    ;

    bbl::Class<PXR_NS::SdfAbstractDataPtrVector>("AbstractDataPtrVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfAbstractDataPtr)
    ;

    bbl::Class<PXR_NS::SdfAbstractDataConstPtr>("AbstractDataConstPtr")
        .smartptr_to<PXR_NS::SdfAbstractData const>()
    ;

    bbl::Class<PXR_NS::SdfAbstractDataConstPtrVector>("AbstractDataConstPtrVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfAbstractDataConstPtr)
    ;

    bbl::Class<PXR_NS::SdfAbstractDataRefPtr>("AbstractDataRefPtr")
        .smartptr_to<PXR_NS::SdfAbstractData>()
    ;

    bbl::Class<PXR_NS::SdfAbstractDataRefPtrVector>("AbstractDataRefPtrVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfAbstractDataRefPtr)
    ;

    bbl::Class<PXR_NS::SdfAbstractDataConstRefPtr>("AbstractDataConstRefPtr")
        .smartptr_to<PXR_NS::SdfAbstractData const>()
    ;

    bbl::Class<PXR_NS::SdfAbstractDataConstRefPtrVector>("AbstractDataConstRefPtrVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfAbstractDataConstRefPtr)
    ;

    bbl::Class<PXR_NS::SdfAbstractDataValue>("AbstractDataValue")
        .m((bool (PXR_NS::SdfAbstractDataValue::*)(const PXR_NS::VtValue &))
            &PXR_NS::SdfAbstractDataValue::StoreValue, "StoreValue")
        .m((bool (PXR_NS::SdfAbstractDataValue::*)(const PXR_NS::SdfValueBlock &))
            &PXR_NS::SdfAbstractDataValue::StoreValue, "StoreValue_block")
    ;

    bbl::Class<PXR_NS::SdfAbstractDataConstValue>("AbstractDataConstValue")
        .m((bool (PXR_NS::SdfAbstractDataConstValue::*)(PXR_NS::VtValue *) const)
            &PXR_NS::SdfAbstractDataConstValue::GetValue, "GetValue")
        .m(&PXR_NS::SdfAbstractDataConstValue::IsEqual)
    ;

}

#endif


