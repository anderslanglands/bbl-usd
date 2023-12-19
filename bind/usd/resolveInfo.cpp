#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/resolveInfo.h>

BBL_MODULE(usd) {
    // clang-format off

    bbl::Class<PXR_NS::UsdResolveInfo>("ResolveInfo")
        .ctor(bbl::Class<PXR_NS::UsdResolveInfo>::Ctor<>(), "default")
        .m(&PXR_NS::UsdResolveInfo::GetSource)
        .m(&PXR_NS::UsdResolveInfo::HasAuthoredValueOpinion)
        .m(&PXR_NS::UsdResolveInfo::HasAuthoredValue)
        .m(&PXR_NS::UsdResolveInfo::GetNode)
        .m(&PXR_NS::UsdResolveInfo::ValueIsBlocked)
    ;

    bbl::Enum<PXR_NS::UsdResolveInfoSource>("ResolveInfoSource");


}

#endif

