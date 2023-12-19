#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/api.h>
#include <pxr/usd/sdf/spec.h>
#include <pxr/usd/sdf/types.h>
#include <pxr/usd/sdf/declareSpec.h>
#include <pxr/usd/sdf/proxyTypes.h>
#include <pxr/usd/sdf/variantSpec.h>

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfVariantSpec>("VariantSpec")
        .ctor(bbl::Class<PXR_NS::SdfVariantSpec>::Ctor<>(), "default")
        .m(&PXR_NS::SdfVariantSpec::New)
        .m(&PXR_NS::SdfVariantSpec::GetName)
        .m(&PXR_NS::SdfVariantSpec::GetNameToken)
        .m(&PXR_NS::SdfVariantSpec::GetOwner)
        .m(&PXR_NS::SdfVariantSpec::GetPrimSpec)
        .m(&PXR_NS::SdfVariantSpec::GetVariantSets)
        .m(&PXR_NS::SdfVariantSpec::GetVariantNames)
    ;
    
    bbl::Class<PXR_NS::SdfVariantSpecHandle>("VariantSpecHandle");

    bbl::Class<PXR_NS::SdfVariantSpecHandleVector>("VariantSpecHandleVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfVariantSpecHandle)
    ;
    
    bbl::Class<PXR_NS::SdfVariantView>("VariantView");
}

#endif

