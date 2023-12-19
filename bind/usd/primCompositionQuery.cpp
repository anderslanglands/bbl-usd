#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/primCompositionQuery.h>

BBL_MODULE(usd) {
    // clang-format off

    bbl::Class<PXR_NS::UsdPrimCompositionQuery>("PrimCompositionQuery")
        .ctor(bbl::Class<PXR_NS::UsdPrimCompositionQuery>::Ctor<PXR_NS::UsdPrim const&, PXR_NS::UsdPrimCompositionQuery::Filter const&>("prim", "filter"))
        .m(&PXR_NS::UsdPrimCompositionQuery::SetFilter)
        .m(&PXR_NS::UsdPrimCompositionQuery::GetFilter)
        .m(&PXR_NS::UsdPrimCompositionQuery::GetCompositionArcs)
        .m(&PXR_NS::UsdPrimCompositionQuery::GetDirectInherits)
        .m(&PXR_NS::UsdPrimCompositionQuery::GetDirectReferences)
        .m(&PXR_NS::UsdPrimCompositionQuery::GetDirectRootLayerArcs);

    bbl::Class<PXR_NS::UsdPrimCompositionQueryArc>("PrimCompositionQueryArc")
        .m(&PXR_NS::UsdPrimCompositionQueryArc::GetTargetNode)
        .m(&PXR_NS::UsdPrimCompositionQueryArc::GetIntroducingNode)

        // Arc target details
        .m(&PXR_NS::UsdPrimCompositionQueryArc::GetTargetLayer)
        .m(&PXR_NS::UsdPrimCompositionQueryArc::GetTargetPrimPath)
        .m(&PXR_NS::UsdPrimCompositionQueryArc::MakeResolveTargetUpTo)
        .m(&PXR_NS::UsdPrimCompositionQueryArc::MakeResolveTargetStrongerThan)

        // Arc editing
        .m(&PXR_NS::UsdPrimCompositionQueryArc::GetIntroducingLayer)
        .m(&PXR_NS::UsdPrimCompositionQueryArc::GetIntroducingPrimPath)
        .m((bool(PXR_NS::UsdPrimCompositionQueryArc::*)(PXR_NS::SdfReferenceEditorProxy*, PXR_NS::SdfReference*) const) 
            &PXR_NS::UsdPrimCompositionQueryArc::GetIntroducingListEditor, "GetIntroducingListEditor_reference"
        )
        .m((bool(PXR_NS::UsdPrimCompositionQueryArc::*)(PXR_NS::SdfPayloadEditorProxy*, PXR_NS::SdfPayload*) const) 
            &PXR_NS::UsdPrimCompositionQueryArc::GetIntroducingListEditor, "GetIntroducingListEditor_payload"
        )
        .m((bool(PXR_NS::UsdPrimCompositionQueryArc::*)( PXR_NS::SdfPathEditorProxy*, PXR_NS::SdfPath*) const) 
            &PXR_NS::UsdPrimCompositionQueryArc::GetIntroducingListEditor, "GetIntroducingListEditor_path"
        )
        .m((bool(PXR_NS::UsdPrimCompositionQueryArc::*)(PXR_NS::SdfNameEditorProxy*, std::string*) const) 
            &PXR_NS::UsdPrimCompositionQueryArc::GetIntroducingListEditor, "GetIntroducingListEditor_name"
        )

        // Arc classification
        .m(&PXR_NS::UsdPrimCompositionQueryArc::GetArcType)
        .m(&PXR_NS::UsdPrimCompositionQueryArc::IsImplicit)
        .m(&PXR_NS::UsdPrimCompositionQueryArc::IsAncestral)
        .m(&PXR_NS::UsdPrimCompositionQueryArc::HasSpecs)
        .m(&PXR_NS::UsdPrimCompositionQueryArc::IsIntroducedInRootLayerStack)
        .m(&PXR_NS::UsdPrimCompositionQueryArc::
               IsIntroducedInRootLayerPrimSpec);

    bbl::Class<std::vector<PXR_NS::UsdPrimCompositionQueryArc>>("PrimCompositionQueryArcVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdPrimCompositionQueryArc)
    ;

    bbl::Class<PXR_NS::UsdPrimCompositionQuery::Filter>(
        "PrimCompositionQueryFilter")
        .value_type()
        .f(&PXR_NS::UsdPrimCompositionQuery::Filter::arcTypeFilter)
        .f(&PXR_NS::UsdPrimCompositionQuery::Filter::dependencyTypeFilter)
        .f(&PXR_NS::UsdPrimCompositionQuery::Filter::arcIntroducedFilter)
        .f(&PXR_NS::UsdPrimCompositionQuery::Filter::hasSpecsFilter)
        ;

    bbl::Enum<PXR_NS::UsdPrimCompositionQuery::ArcTypeFilter>(
        "PrimCompositionQueryArcTypeFilter");
    bbl::Enum<PXR_NS::UsdPrimCompositionQuery::ArcIntroducedFilter>(
        "PrimCompositionQueryArcIntroducedFilter");
    bbl::Enum<PXR_NS::UsdPrimCompositionQuery::DependencyTypeFilter>(
        "PrimCompositionQueryDependencyTypeFilter");
    bbl::Enum<PXR_NS::UsdPrimCompositionQuery::HasSpecsFilter>(
        "PrimCompositionQueryHasSpecsFilter");

}

#endif

