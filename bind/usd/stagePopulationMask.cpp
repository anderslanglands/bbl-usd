#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/stagePopulationMask.h>

BBL_MODULE(usd) {
    // clang-format off

    bbl::Class<PXR_NS::UsdStagePopulationMask>()
        .ctor(bbl::Class<PXR_NS::UsdStagePopulationMask>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::UsdStagePopulationMask>::Ctor<const std::vector<PXR_NS::SdfPath> &>("paths"), "from_paths")
        .m(&PXR_NS::UsdStagePopulationMask::All)
        /** TODO: instantiate this template
        .m(&PXR_NS::UsdStagePopulationMask::UsdStagePopulationMask)
        */
        .m(&PXR_NS::UsdStagePopulationMask::Union)
        .m((PXR_NS::UsdStagePopulationMask (PXR_NS::UsdStagePopulationMask::*)(const PXR_NS::UsdStagePopulationMask &) const)
            &PXR_NS::UsdStagePopulationMask::GetUnion, "GetUnion"
        )
        .m((PXR_NS::UsdStagePopulationMask (PXR_NS::UsdStagePopulationMask::*)(const PXR_NS::SdfPath &) const)
            &PXR_NS::UsdStagePopulationMask::GetUnion, "GetUnion_with_path"
        )
        .m(&PXR_NS::UsdStagePopulationMask::Intersection)
        .m(&PXR_NS::UsdStagePopulationMask::GetIntersection)
        .m((bool (PXR_NS::UsdStagePopulationMask::*)(const PXR_NS::UsdStagePopulationMask &) const)
            &PXR_NS::UsdStagePopulationMask::Includes, "Includes"
        )
        .m((bool (PXR_NS::UsdStagePopulationMask::*)(const PXR_NS::SdfPath &) const)
            &PXR_NS::UsdStagePopulationMask::Includes, "Includes_path"
        )
        .m(&PXR_NS::UsdStagePopulationMask::IncludesSubtree)
        .m(&PXR_NS::UsdStagePopulationMask::IsEmpty)
        .m(&PXR_NS::UsdStagePopulationMask::GetIncludedChildNames)
        .m(&PXR_NS::UsdStagePopulationMask::GetPaths)
        .m((PXR_NS::UsdStagePopulationMask & (PXR_NS::UsdStagePopulationMask::*)(const PXR_NS::UsdStagePopulationMask &))
            &PXR_NS::UsdStagePopulationMask::Add, "Add"
        )
        .m((PXR_NS::UsdStagePopulationMask & (PXR_NS::UsdStagePopulationMask::*)(const PXR_NS::SdfPath &))
            &PXR_NS::UsdStagePopulationMask::Add, "Add_path"
        )
        .m(&PXR_NS::UsdStagePopulationMask::operator==, "op_eq")
        .m(&PXR_NS::UsdStagePopulationMask::operator!=, "op_neq")
        .m(&PXR_NS::UsdStagePopulationMask::swap)
    ;
}

#endif

