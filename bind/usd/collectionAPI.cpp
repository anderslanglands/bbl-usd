#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/collectionAPI.h>

BBL_MODULE(usd) {
    // clang-format off

    bbl::Class<PXR_NS::UsdCollectionAPI>("CollectionAPI")
        .ctor(bbl::Class<PXR_NS::UsdCollectionAPI>::Ctor<const PXR_NS::UsdPrim &, const PXR_NS::TfToken &>("prim", "name"), "ctor_00")
        .ctor(bbl::Class<PXR_NS::UsdCollectionAPI>::Ctor<const PXR_NS::UsdSchemaBase &, const PXR_NS::TfToken &>("schemaObj", "name"), "ctor_01")
        .m((const PXR_NS::TfTokenVector & (*)(bool))
            &PXR_NS::UsdCollectionAPI::GetSchemaAttributeNames, "GetSchemaAttributeNames_00")
        .m((PXR_NS::TfTokenVector (*)(bool, const PXR_NS::TfToken &))
            &PXR_NS::UsdCollectionAPI::GetSchemaAttributeNames, "GetSchemaAttributeNames_01")
        .m(&PXR_NS::UsdCollectionAPI::GetName)
        .m((PXR_NS::UsdCollectionAPI (*)(const PXR_NS::UsdStagePtr &, const PXR_NS::SdfPath &))
            &PXR_NS::UsdCollectionAPI::Get, "Get_from_path")
        .m((PXR_NS::UsdCollectionAPI (*)(const PXR_NS::UsdPrim &, const PXR_NS::TfToken &))
            &PXR_NS::UsdCollectionAPI::Get, "Get")
        .m(&PXR_NS::UsdCollectionAPI::GetAll)
        .m(&PXR_NS::UsdCollectionAPI::IsSchemaPropertyBaseName)
        .m(&PXR_NS::UsdCollectionAPI::IsCollectionAPIPath)
        .m(&PXR_NS::UsdCollectionAPI::CanApply)
        .m(&PXR_NS::UsdCollectionAPI::Apply)
        .m(&PXR_NS::UsdCollectionAPI::GetExpansionRuleAttr)
        .m(&PXR_NS::UsdCollectionAPI::CreateExpansionRuleAttr)
        .m(&PXR_NS::UsdCollectionAPI::GetIncludeRootAttr)
        .m(&PXR_NS::UsdCollectionAPI::CreateIncludeRootAttr)
        .m(&PXR_NS::UsdCollectionAPI::GetCollectionAttr)
        .m(&PXR_NS::UsdCollectionAPI::CreateCollectionAttr)
        .m(&PXR_NS::UsdCollectionAPI::GetIncludesRel)
        .m(&PXR_NS::UsdCollectionAPI::CreateIncludesRel)
        .m(&PXR_NS::UsdCollectionAPI::GetExcludesRel)
        .m(&PXR_NS::UsdCollectionAPI::CreateExcludesRel)
        .m((PXR_NS::UsdCollectionAPI (*)(const PXR_NS::UsdStagePtr &, const PXR_NS::SdfPath &))
            &PXR_NS::UsdCollectionAPI::GetCollection, "GetCollection_from_path")
        .m((PXR_NS::UsdCollectionAPI (*)(const PXR_NS::UsdPrim &, const PXR_NS::TfToken &))
            &PXR_NS::UsdCollectionAPI::GetCollection, "GetCollection")
        .m(&PXR_NS::UsdCollectionAPI::GetAllCollections)
        .m(&PXR_NS::UsdCollectionAPI::GetCollectionPath)
        .m(&PXR_NS::UsdCollectionAPI::GetNamedCollectionPath)
        .m((PXR_NS::UsdCollectionMembershipQuery (PXR_NS::UsdCollectionAPI::*)() const)
            &PXR_NS::UsdCollectionAPI::ComputeMembershipQuery, "ComputeMembershipQuery_00")
        .m((void (PXR_NS::UsdCollectionAPI::*)(PXR_NS::UsdCollectionMembershipQuery *) const)
            &PXR_NS::UsdCollectionAPI::ComputeMembershipQuery, "ComputeMembershipQuery_01")
        .m(&PXR_NS::UsdCollectionAPI::HasNoIncludedPaths)
        .m(&PXR_NS::UsdCollectionAPI::ComputeIncludedObjects)
        .m(&PXR_NS::UsdCollectionAPI::ComputeIncludedPaths)
        .m(&PXR_NS::UsdCollectionAPI::IncludePath)
        .m(&PXR_NS::UsdCollectionAPI::ExcludePath)
        .m(&PXR_NS::UsdCollectionAPI::Validate)
        .m(&PXR_NS::UsdCollectionAPI::ResetCollection)
        .m(&PXR_NS::UsdCollectionAPI::BlockCollection)
        .m(&PXR_NS::UsdCollectionAPI::CanContainPropertyName)
    ;

    bbl::Class<std::vector<PXR_NS::UsdCollectionAPI>>("CollectionAPIVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdCollectionAPI)
    ;

}

#endif

