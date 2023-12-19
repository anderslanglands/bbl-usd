#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/variantSets.h>

BBL_MODULE(usd) {
    // clang-format off

    bbl::Class<PXR_NS::UsdVariantSet>()
        .m(&PXR_NS::UsdVariantSet::AddVariant)
        .m(&PXR_NS::UsdVariantSet::GetVariantNames)
        .m(&PXR_NS::UsdVariantSet::HasAuthoredVariant)
        .m(&PXR_NS::UsdVariantSet::GetVariantSelection)
        .m(&PXR_NS::UsdVariantSet::HasAuthoredVariantSelection)
        .m(&PXR_NS::UsdVariantSet::SetVariantSelection)
        .m(&PXR_NS::UsdVariantSet::ClearVariantSelection)
        .m(&PXR_NS::UsdVariantSet::BlockVariantSelection)
        .m(&PXR_NS::UsdVariantSet::GetVariantEditTarget)
        .m(&PXR_NS::UsdVariantSet::GetVariantEditContext)
        .m(&PXR_NS::UsdVariantSet::GetPrim)
        .m(&PXR_NS::UsdVariantSet::GetName)
        .m(&PXR_NS::UsdVariantSet::IsValid)
        .m(&PXR_NS::UsdVariantSet::operator bool)
    ;

    bbl::Class<PXR_NS::UsdVariantSets>()
        .m(&PXR_NS::UsdVariantSets::AddVariantSet)
        .m((bool (PXR_NS::UsdVariantSets::*)(std::vector<std::string> *) const)
            &PXR_NS::UsdVariantSets::GetNames, "GetNames_into")
        .m((std::vector<std::string> (PXR_NS::UsdVariantSets::*)() const)
            &PXR_NS::UsdVariantSets::GetNames, "GetNames")
        .m(&PXR_NS::UsdVariantSets::operator[], "op_index")
        .m(&PXR_NS::UsdVariantSets::GetVariantSet)
        .m(&PXR_NS::UsdVariantSets::HasVariantSet)
        .m(&PXR_NS::UsdVariantSets::GetVariantSelection)
        .m(&PXR_NS::UsdVariantSets::SetSelection)
        .m(&PXR_NS::UsdVariantSets::GetAllVariantSelections)
    ;

    bbl::Class<std::pair<PXR_NS::UsdStagePtr, PXR_NS::UsdEditTarget>>("StageEditTargetPair")
    ;

}

#endif

