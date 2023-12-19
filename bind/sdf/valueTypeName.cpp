#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/valueTypeName.h>

namespace bblext {

char const* ValueTypeName_GetCPPTypeName(PXR_NS::SdfValueTypeName const& vtn) {
    return vtn.GetCPPTypeName().c_str();
}

}

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfValueTypeName>("ValueTypeName")
        .ctor(bbl::Class<PXR_NS::SdfValueTypeName>::Ctor<>(), "new")
        .m(&PXR_NS::SdfValueTypeName::GetAsToken)
        .m(&PXR_NS::SdfValueTypeName::GetType)
        .m(&PXR_NS::SdfValueTypeName::GetRole)
        .m(&PXR_NS::SdfValueTypeName::GetDefaultValue)
        .m(&PXR_NS::SdfValueTypeName::GetDefaultUnit)
        .m(&PXR_NS::SdfValueTypeName::GetScalarType)
        .m(&PXR_NS::SdfValueTypeName::GetArrayType)
        .m(&PXR_NS::SdfValueTypeName::IsScalar)
        .m(&PXR_NS::SdfValueTypeName::IsArray)
        .m(&PXR_NS::SdfValueTypeName::GetDimensions)
        .m(&PXR_NS::SdfValueTypeName::GetAliasesAsTokens)
        ;

    bbl::fn(&bblext::ValueTypeName_GetCPPTypeName);

    bbl::Class<std::vector<PXR_NS::SdfValueTypeName>>("ValueTypeNameVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfValueTypeName);

    bbl::Class<PXR_NS::SdfTupleDimensions>("TupleDimensions")
        .value_type()
        .f(&PXR_NS::SdfTupleDimensions::d)
        .f(&PXR_NS::SdfTupleDimensions::size)
    ;

}

#endif

