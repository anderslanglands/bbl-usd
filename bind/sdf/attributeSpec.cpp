#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/attributeSpec.h>

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfAttributeSpec>("AttributeSpec")
        .ctor(bbl::Class<PXR_NS::SdfAttributeSpec>::Ctor<>(), "default")
        .m(&PXR_NS::SdfAttributeSpec::New)
        .m(&PXR_NS::SdfAttributeSpec::HasConnectionPaths)
        .m(&PXR_NS::SdfAttributeSpec::ClearConnectionPaths)
        .m(&PXR_NS::SdfAttributeSpec::GetAllowedTokens)
        .m(&PXR_NS::SdfAttributeSpec::HasAllowedTokens)
        .m(&PXR_NS::SdfAttributeSpec::SetAllowedTokens)
        // missing SdfListEditorProxy<SdfPathKeyPolicy>
        // .m(&PXR_NS::SdfAttributeSpec::GetConnectionPathList)
        .m(&PXR_NS::SdfAttributeSpec::ClearAllowedTokens)
        .m(&PXR_NS::SdfAttributeSpec::GetDisplayUnit)
        .m(&PXR_NS::SdfAttributeSpec::SetDisplayUnit)
        .m(&PXR_NS::SdfAttributeSpec::HasDisplayUnit)
        .m(&PXR_NS::SdfAttributeSpec::ClearDisplayUnit)
        .m(&PXR_NS::SdfAttributeSpec::GetColorSpace)
        .m(&PXR_NS::SdfAttributeSpec::SetColorSpace)
        .m(&PXR_NS::SdfAttributeSpec::HasColorSpace)
        .m(&PXR_NS::SdfAttributeSpec::ClearColorSpace)
        .m(&PXR_NS::SdfAttributeSpec::GetRoleName)
    ;

    bbl::Class<PXR_NS::SdfAttributeSpecHandle>("AttributeSpecHandle")
        .smartptr_to<PXR_NS::SdfAttributeSpec>()
    ;

    bbl::Class<PXR_NS::SdfAttributeSpecHandleVector>("AttributeSpecHandleVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfAttributeSpecHandle)
    ;

    
    /// XXX: what's this
    bbl::Class<PXR_NS::SdfAttributeSpecView>("AttributeSpecView");

}

#endif


