#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/stageLoadRules.h>

BBL_MODULE(usd) {
    // clang-format off

    bbl::Class<PXR_NS::UsdStageLoadRules>("StageLoadRules")
        .ctor(bbl::Class<PXR_NS::UsdStageLoadRules>::Ctor<>(), "default")
        .m(&PXR_NS::UsdStageLoadRules::LoadWithDescendants)
        .m(&PXR_NS::UsdStageLoadRules::LoadWithoutDescendants)
        .m(&PXR_NS::UsdStageLoadRules::Unload)
        .m(&PXR_NS::UsdStageLoadRules::LoadAndUnload)
        .m(&PXR_NS::UsdStageLoadRules::AddRule)
        // SetRules
        .m(&PXR_NS::UsdStageLoadRules::Minimize)
        .m(&PXR_NS::UsdStageLoadRules::IsLoaded)
        .m(&PXR_NS::UsdStageLoadRules::IsLoadedWithAllDescendants)
        .m(&PXR_NS::UsdStageLoadRules::IsLoadedWithNoDescendants)
        .m(&PXR_NS::UsdStageLoadRules::GetEffectiveRuleForPath)
        .m(&PXR_NS::UsdStageLoadRules::GetRules)
        .m(&PXR_NS::UsdStageLoadRules::LoadAll)
        .m(&PXR_NS::UsdStageLoadRules::LoadNone)
        ;

    bbl::Class<std::pair<PXR_NS::SdfPath, PXR_NS::UsdStageLoadRules::Rule>>("PathStageLoadRulesRulePair");
    bbl::Class<std::vector<std::pair<PXR_NS::SdfPath, PXR_NS::UsdStageLoadRules::Rule>>>("PathStageLoadRulesRulePairVector")
        BBL_STD_VECTOR_METHODS((std::pair<PXR_NS::SdfPath, PXR_NS::UsdStageLoadRules::Rule>))
        ;

    bbl::Enum<PXR_NS::UsdStageLoadRules::Rule>("StageLoadRulesRule");

}

#endif

