#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/crateInfo.h>

BBL_MODULE(usd) {
    // clang-format off

    bbl::Class<PXR_NS::UsdCrateInfo>("CrateInfo")
        .m(&PXR_NS::UsdCrateInfo::Open)
        .m(&PXR_NS::UsdCrateInfo::GetSummaryStats)
        .m(&PXR_NS::UsdCrateInfo::GetSections)
        .m(&PXR_NS::UsdCrateInfo::GetFileVersion)
        .m(&PXR_NS::UsdCrateInfo::GetSoftwareVersion)
        .m(&PXR_NS::UsdCrateInfo::operator bool, "op_bool")
    ;

    bbl::Class<PXR_NS::UsdCrateInfo::Section>("CrateInfoSection")
        .ctor(bbl::Class<PXR_NS::UsdCrateInfo::Section>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::UsdCrateInfo::Section>::Ctor<const std::string &, int64_t, int64_t>("name", "start", "size"), "ctor_01")
    ;

    bbl::Class<std::vector<PXR_NS::UsdCrateInfo::Section>>("CratreInfoSectionVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdCrateInfo::Section)
    ;

    bbl::Class<PXR_NS::UsdCrateInfo::SummaryStats>("CrateInfoSummaryStats")
        .value_type()
        .f(&PXR_NS::UsdCrateInfo::SummaryStats::numSpecs)
        .f(&PXR_NS::UsdCrateInfo::SummaryStats::numUniquePaths)
        .f(&PXR_NS::UsdCrateInfo::SummaryStats::numUniqueTokens)
        .f(&PXR_NS::UsdCrateInfo::SummaryStats::numUniqueStrings)
        .f(&PXR_NS::UsdCrateInfo::SummaryStats::numUniqueFields)
        .f(&PXR_NS::UsdCrateInfo::SummaryStats::numUniqueFieldSets)
    ;

}

#endif

