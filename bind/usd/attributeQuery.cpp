#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/attributeQuery.h>

BBL_MODULE(usd) {
    // clang-format off

    bbl::Class<PXR_NS::UsdAttributeQuery>("AttributeQuery")
        .ctor(bbl::Class<PXR_NS::UsdAttributeQuery>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::UsdAttributeQuery>::Ctor<PXR_NS::UsdPrim const&, PXR_NS::TfToken const&>(), "from_prim_and_attribute_name")
        .ctor(bbl::Class<PXR_NS::UsdAttributeQuery>::Ctor<PXR_NS::UsdAttribute const&, PXR_NS::UsdResolveTarget const&>(), "from_attribute_and_resolve_target")
        .m(&PXR_NS::UsdAttributeQuery::CreateQueries)
        .m(&PXR_NS::UsdAttributeQuery::GetAttribute)
        .m(&PXR_NS::UsdAttributeQuery::IsValid)
        // Value and Time Sample Accessors
        // Get
        .m((bool (PXR_NS::UsdAttributeQuery::*)(PXR_NS::VtValue*, PXR_NS::UsdTimeCode) const)
            &PXR_NS::UsdAttributeQuery::Get, "Get_value"
        )
        .m(&PXR_NS::UsdAttributeQuery::GetTimeSamples)
        .m(&PXR_NS::UsdAttributeQuery::GetTimeSamplesInInterval)
        .m(&PXR_NS::UsdAttributeQuery::GetNumTimeSamples)
        .m(&PXR_NS::UsdAttributeQuery::GetBracketingTimeSamples)
        .m(&PXR_NS::UsdAttributeQuery::HasValue)
        .m(&PXR_NS::UsdAttributeQuery::HasAuthoredValueOpinion)
        .m(&PXR_NS::UsdAttributeQuery::HasAuthoredValue)
        .m(&PXR_NS::UsdAttributeQuery::HasFallbackValue)
        .m(&PXR_NS::UsdAttributeQuery::ValueMightBeTimeVarying)
        .m(&PXR_NS::UsdAttributeQuery::GetUnionedTimeSamples)
        .m(&PXR_NS::UsdAttributeQuery::GetUnionedTimeSamplesInInterval)
    ;

    bbl::Class<std::vector<PXR_NS::UsdAttributeQuery>>("AttributeQueryVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdAttributeQuery);

}

#endif
