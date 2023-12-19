#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/timeCode.h>

struct TimeCode {
    double time;
};

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfTimeCode>("TimeCode")
        .replace_with<TimeCode>()
        .ctor(bbl::Class<PXR_NS::SdfTimeCode>::Ctor<double>(), "from_time")
    ;

    // bbl::Class<std::vector<PXR_NS::UsdTimeCode>>("TimeCodeVector")
    //     BBL_STD_VECTOR_METHODS(PXR_NS::UsdTimeCode)
    //     ;

}

#endif

