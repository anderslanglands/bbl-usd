#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/collectionMembershipQuery.h>

BBL_MODULE(usd) {
    // clang-format off

    bbl::Class<PXR_NS::UsdCollectionMembershipQuery>("CollectionMembershipQuery")
        .ctor(bbl::Class<PXR_NS::UsdCollectionMembershipQuery>::Ctor<>(), "default")
        /// XXX: this one fails to link
        // .ctor(bbl::Class<PXR_NS::UsdCollectionMembershipQuery>::Ctor<const PXR_NS::UsdCollectionMembershipQuery::PathExpansionRuleMap &, const PXR_NS::SdfPathSet &>("pathExpansionRuleMap", "includedCollections"), "ctor_01")
        .m((bool (PXR_NS::UsdCollectionMembershipQuery::*)(const PXR_NS::SdfPath &, PXR_NS::TfToken *) const)
            &PXR_NS::UsdCollectionMembershipQuery::IsPathIncluded, "IsPathIncluded_00")
        .m((bool (PXR_NS::UsdCollectionMembershipQuery::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, PXR_NS::TfToken *) const)
            &PXR_NS::UsdCollectionMembershipQuery::IsPathIncluded, "IsPathIncluded_01")
        .m(&PXR_NS::UsdCollectionMembershipQuery::HasExcludes)
        .m(&PXR_NS::UsdCollectionMembershipQuery::operator==, "op_eq")
        .m(&PXR_NS::UsdCollectionMembershipQuery::operator!=, "op_neq")
        .m(&PXR_NS::UsdCollectionMembershipQuery::GetHash)
        .m(&PXR_NS::UsdCollectionMembershipQuery::GetAsPathExpansionRuleMap)
        .m(&PXR_NS::UsdCollectionMembershipQuery::GetIncludedCollections)
    ;

    bbl::Class<PXR_NS::UsdCollectionMembershipQuery::Hash>("CollectionMembershipQueryHash")
        .ctor(bbl::Class<PXR_NS::UsdCollectionMembershipQuery::Hash>::Ctor<>(), "default")
    ;

    bbl::Class<PXR_NS::UsdCollectionMembershipQuery::PathExpansionRuleMap>("CollectionMembershipQueryPathExpansionRuleMap")
        .ctor(bbl::Class<PXR_NS::UsdCollectionMembershipQuery::PathExpansionRuleMap>::Ctor<>(), "default")
    ;

}

#endif

