#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/types.h>

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Enum<PXR_NS::SdfPermission>("Permission");
    bbl::Class<PXR_NS::SdfRelocatesMap>("RelocatesMap");
    bbl::Enum<PXR_NS::SdfSpecifier>("Specifier");
    bbl::Enum<PXR_NS::SdfSpecType>("SpecType");
    bbl::Class<PXR_NS::SdfTimeSampleMap>("TimeSampleMap");
    bbl::Enum<PXR_NS::SdfVariability>("Variability");
    bbl::Class<PXR_NS::SdfValueBlock>("ValueBlock");
}

#endif


