#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/timeCode.h>

struct TimeCode {
    double time;
};

BBL_MODULE(usd) {
    // clang-format off

    bbl::Class<PXR_NS::UsdTimeCode>("TimeCode")
        .replace_with<TimeCode>()
        .ctor(bbl::Class<PXR_NS::UsdTimeCode>::Ctor<double>(), "from_time")
        .ctor(bbl::Class<PXR_NS::UsdTimeCode>::Ctor<PXR_NS::SdfTimeCode>(), "from_sdf_timecode")
        .m(&PXR_NS::UsdTimeCode::IsEarliestTime)
        .m(&PXR_NS::UsdTimeCode::IsDefault)
        .m(&PXR_NS::UsdTimeCode::IsNumeric)
        .m(&PXR_NS::UsdTimeCode::GetValue)
        .m(&PXR_NS::UsdTimeCode::EarliestTime)
        .m(&PXR_NS::UsdTimeCode::Default)
        .m(&PXR_NS::UsdTimeCode::SafeStep)
        ;

    bbl::Class<std::vector<PXR_NS::UsdTimeCode>>("TimeCodeVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdTimeCode)
        ;

}

#endif

