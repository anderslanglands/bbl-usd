#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/api.h>
#include <pxr/usd/sdf/spec.h>
#include <pxr/usd/sdf/types.h>
#include <pxr/usd/sdf/declareSpec.h>
#include <pxr/usd/sdf/proxyTypes.h>
#include <pxr/usd/sdf/variantSetSpec.h>

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfVariantSetSpec>("VariantSetSpec")
        .ctor(bbl::Class<PXR_NS::SdfVariantSetSpec>::Ctor<>(), "default")
        .m((PXR_NS::SdfVariantSetSpecHandle (*)(const PXR_NS::SdfPrimSpecHandle &, const std::string &))
            &PXR_NS::SdfVariantSetSpec::New, "New_00")
        .m((PXR_NS::SdfVariantSetSpecHandle (*)(const PXR_NS::SdfVariantSpecHandle &, const std::string &))
            &PXR_NS::SdfVariantSetSpec::New, "New_01")
        .m(&PXR_NS::SdfVariantSetSpec::GetName)
        .m(&PXR_NS::SdfVariantSetSpec::GetNameToken)
        .m(&PXR_NS::SdfVariantSetSpec::GetOwner)
        .m(&PXR_NS::SdfVariantSetSpec::GetVariants)
        .m(&PXR_NS::SdfVariantSetSpec::GetVariantList)
        .m(&PXR_NS::SdfVariantSetSpec::RemoveVariant)
        ;

    bbl::Class<PXR_NS::SdfVariantSetSpecHandle>("VariantSetSpecHandle");

}

#endif

