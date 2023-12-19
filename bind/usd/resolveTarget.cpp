#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/resolveTarget.h>

BBL_MODULE(usd) {
    // clang-format off

    bbl::Class<PXR_NS::UsdResolveTarget>("ResolveTarget")
        .ctor(bbl::Class<PXR_NS::UsdResolveTarget>::Ctor<>(), "default")
        .m(&PXR_NS::UsdResolveTarget::GetPrimIndex)
        .m(&PXR_NS::UsdResolveTarget::GetStartNode)
        .m(&PXR_NS::UsdResolveTarget::GetStartLayer)
        .m(&PXR_NS::UsdResolveTarget::GetStopNode)
        .m(&PXR_NS::UsdResolveTarget::GetStopLayer)
        .m(&PXR_NS::UsdResolveTarget::IsNull)
    ;

}

#endif

