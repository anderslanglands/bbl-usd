#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/spec.h>

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfSpec>()
        .ctor(bbl::Class<PXR_NS::SdfSpec>::Ctor<>(), "default")
        .m(&PXR_NS::SdfSpec::GetSchema)
        .m(&PXR_NS::SdfSpec::GetSpecType)
        .m(&PXR_NS::SdfSpec::IsDormant)
        .m(&PXR_NS::SdfSpec::GetLayer)
        .m(&PXR_NS::SdfSpec::GetPath)
        .m(&PXR_NS::SdfSpec::PermissionToEdit)
        .m(&PXR_NS::SdfSpec::ListInfoKeys)
        .m(&PXR_NS::SdfSpec::GetMetaDataInfoKeys)
        .m(&PXR_NS::SdfSpec::GetMetaDataDisplayGroup)
        .m(&PXR_NS::SdfSpec::GetInfo)
        .m(&PXR_NS::SdfSpec::SetInfo)
        .m(&PXR_NS::SdfSpec::SetInfoDictionaryValue)
        .m(&PXR_NS::SdfSpec::HasInfo)
        .m(&PXR_NS::SdfSpec::ClearInfo)
        .m(&PXR_NS::SdfSpec::GetTypeForInfo)
        .m(&PXR_NS::SdfSpec::GetFallbackForInfo)
        // need std::ostream for this
        // .m(&PXR_NS::SdfSpec::WriteToStream)
        .m(&PXR_NS::SdfSpec::IsInert)
        .m(&PXR_NS::SdfSpec::ListFields)
        .m((bool (PXR_NS::SdfSpec::*)(const PXR_NS::TfToken &) const)
            &PXR_NS::SdfSpec::HasField, "HasField_00")
        /** TODO: instantiate this template
        .m((bool (PXR_NS::SdfSpec::*)(const PXR_NS::TfToken &, T *) const)
            &PXR_NS::SdfSpec::HasField, "HasField_01")
        */
        .m(&PXR_NS::SdfSpec::GetField)
        /** TODO: instantiate this template
        .m(&PXR_NS::SdfSpec::GetFieldAs)
        */
        .m((bool (PXR_NS::SdfSpec::*)(const PXR_NS::TfToken &, const PXR_NS::VtValue &))
            &PXR_NS::SdfSpec::SetField, "SetField_00")
        /** TODO: instantiate this template
        .m((bool (PXR_NS::SdfSpec::*)(const PXR_NS::TfToken &, const T &))
            &PXR_NS::SdfSpec::SetField, "SetField_01")
        */
        .m(&PXR_NS::SdfSpec::ClearField)
        .m(&PXR_NS::SdfSpec::operator==, "op_eq")
        .m(&PXR_NS::SdfSpec::operator<, "op_lt")
    ;

    bbl::Class<PXR_NS::SdfSpecHandle>("SpecHandle")
        .smartptr_to<PXR_NS::SdfSpec>()
    ;

}

#endif


