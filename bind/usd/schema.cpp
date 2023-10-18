#if defined(__clang__)

#include "babble"
#include "babble-std"

#include <pxr/usd/usd/clipsAPI.h>
#include <pxr/usd/usd/collectionAPI.h>
#include <pxr/usd/usd/collectionMembershipQuery.h>
#include <pxr/usd/usd/modelAPI.h>
#include <pxr/base/tf/token.h>
#include <pxr/usd/sdf/path.h>

BBL_MODULE(usd) {
    #define APISCHEMABASE_METHODS(CLS) \
        .m(&CLS::IsConcrete) \
        .m(&CLS::IsTyped) \
        .m(&CLS::IsAPISchema) \
        .m(&CLS::IsAppliedAPISchema) \
        .m(&CLS::IsMultipleApplyAPISchema) \
        .m(&CLS::GetSchemaKind) \
        .m(&CLS::GetPrim) \
        .m(&CLS::GetPath) \
        .m(&CLS::GetSchemaClassPrimDefinition)

    bbl::Class<PXR_NS::UsdClipsAPI>("ClipsAPI")
        .ctor(bbl::Ctor<PXR_NS::UsdClipsAPI, PXR_NS::UsdPrim const&>(), "on_prim")
        .ctor(bbl::Ctor<PXR_NS::UsdClipsAPI, PXR_NS::UsdSchemaBase const&>(), "on_schema_obj")
        APISCHEMABASE_METHODS(PXR_NS::UsdClipsAPI)

        .m(&PXR_NS::UsdClipsAPI::Get)
        .m(&PXR_NS::UsdClipsAPI::GetSchemaAttributeNames)
        
        // Value Clip Info
        .m(&PXR_NS::UsdClipsAPI::GetClips)
        .m(&PXR_NS::UsdClipsAPI::SetClips)
        .m(&PXR_NS::UsdClipsAPI::GetClipSets)
        .m(&PXR_NS::UsdClipsAPI::SetClipSets)
        .m((PXR_NS::VtArray<PXR_NS::SdfAssetPath> (PXR_NS::UsdClipsAPI::*)(std::string const&) const)
            &PXR_NS::UsdClipsAPI::ComputeClipAssetPaths, "ComputeClipAssetPaths_on_clip_set"
        )
        .m((PXR_NS::VtArray<PXR_NS::SdfAssetPath> (PXR_NS::UsdClipsAPI::*)() const)
            &PXR_NS::UsdClipsAPI::ComputeClipAssetPaths
        )
        .m((bool (PXR_NS::UsdClipsAPI::*)(PXR_NS::VtArray<PXR_NS::SdfAssetPath>*, std::string const&) const)
            &PXR_NS::UsdClipsAPI::GetClipAssetPaths, "GetClipAssetPaths_from_clip_set"
        )
        .m((bool (PXR_NS::UsdClipsAPI::*)(PXR_NS::VtArray<PXR_NS::SdfAssetPath>*) const)
            &PXR_NS::UsdClipsAPI::GetClipAssetPaths
        )
        .m((bool (PXR_NS::UsdClipsAPI::*)(PXR_NS::VtArray<PXR_NS::SdfAssetPath> const&, std::string const&))
            &PXR_NS::UsdClipsAPI::SetClipAssetPaths, "SetClipAssetPaths_on_clip_set"
        )
        .m((bool (PXR_NS::UsdClipsAPI::*)(PXR_NS::VtArray<PXR_NS::SdfAssetPath> const&))
            &PXR_NS::UsdClipsAPI::SetClipAssetPaths
        )
        .m((bool (PXR_NS::UsdClipsAPI::*)(std::string*, std::string const&) const)
            &PXR_NS::UsdClipsAPI::GetClipPrimPath, "GetClipPrimPath_from_clip_set"
        )
        .m((bool (PXR_NS::UsdClipsAPI::*)(std::string*) const)
            &PXR_NS::UsdClipsAPI::GetClipPrimPath
        )
        .m((bool (PXR_NS::UsdClipsAPI::*)(std::string const&, std::string const&))
            &PXR_NS::UsdClipsAPI::SetClipPrimPath, "SetClipPrimPath_from_clip_set"
        )
        .m((bool (PXR_NS::UsdClipsAPI::*)(std::string const&))
            &PXR_NS::UsdClipsAPI::SetClipPrimPath
        )
        /// XXX: fill the rest of this dirge out
    ;

    bbl::Class<PXR_NS::UsdCollectionAPI>("CollectionAPI")
        .ctor(bbl::Ctor<PXR_NS::UsdCollectionAPI, PXR_NS::UsdPrim const&, PXR_NS::TfToken const&>(), "on_prim")
        .ctor(bbl::Ctor<PXR_NS::UsdCollectionAPI, PXR_NS::UsdSchemaBase const&, PXR_NS::TfToken const&>(), "on_schema_obj")
        .m(&PXR_NS::UsdCollectionAPI::GetName)
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
        .m(&PXR_NS::UsdCollectionAPI::GetCollectionPath)
        .m((PXR_NS::UsdCollectionMembershipQuery (PXR_NS::UsdCollectionAPI::*)() const)
            &PXR_NS::UsdCollectionAPI::ComputeMembershipQuery
        )
        .m((void (PXR_NS::UsdCollectionAPI::*)(PXR_NS::UsdCollectionMembershipQuery*) const)
            &PXR_NS::UsdCollectionAPI::ComputeMembershipQuery, "ComputeMembershipQuery_in"
        )
        .m(&PXR_NS::UsdCollectionAPI::HasNoIncludedPaths)
        .m(&PXR_NS::UsdCollectionAPI::Validate)
        .m(&PXR_NS::UsdCollectionAPI::ResetCollection)
        .m(&PXR_NS::UsdCollectionAPI::BlockCollection)

        // Collection Authoring API
        .m(&PXR_NS::UsdCollectionAPI::IncludePath)
        .m(&PXR_NS::UsdCollectionAPI::ExcludePath)
        APISCHEMABASE_METHODS(PXR_NS::UsdCollectionAPI)


        // Static
        .m((PXR_NS::TfTokenVector const& (*)(bool))
            &PXR_NS::UsdCollectionAPI::GetSchemaAttributeNames
        )
        .m((PXR_NS::TfTokenVector(*)(bool, PXR_NS::TfToken const&))
            &PXR_NS::UsdCollectionAPI::GetSchemaAttributeNames, "GetSchemaAttributeNames_for_instance"
        )
        .m((PXR_NS::UsdCollectionAPI (*)(PXR_NS::UsdStagePtr const&, PXR_NS::SdfPath const&))
            &PXR_NS::UsdCollectionAPI::Get
        )
        .m((PXR_NS::UsdCollectionAPI (*)(PXR_NS::UsdPrim const&, PXR_NS::TfToken const&))
            &PXR_NS::UsdCollectionAPI::Get, "Get_from_prim"
        )
        .m(&PXR_NS::UsdCollectionAPI::GetAll)
        .m(&PXR_NS::UsdCollectionAPI::IsSchemaPropertyBaseName)
        .m(&PXR_NS::UsdCollectionAPI::IsCollectionAPIPath)
        .m(&PXR_NS::UsdCollectionAPI::CanApply)
        .m(&PXR_NS::UsdCollectionAPI::Apply)
        .m((PXR_NS::UsdCollectionAPI (*)(PXR_NS::UsdStagePtr const&, PXR_NS::SdfPath const&))
            &PXR_NS::UsdCollectionAPI::GetCollection
        )
        .m((PXR_NS::UsdCollectionAPI (*)(PXR_NS::UsdPrim const&, PXR_NS::TfToken const&))
            &PXR_NS::UsdCollectionAPI::GetCollection, "GetCollection_from_prim"
        )
        .m(&PXR_NS::UsdCollectionAPI::GetAllCollections)
        .m(&PXR_NS::UsdCollectionAPI::GetNamedCollectionPath)
        .m(&PXR_NS::UsdCollectionAPI::ComputeIncludedObjects)
        .m(&PXR_NS::UsdCollectionAPI::ComputeIncludedPaths)
        .m(&PXR_NS::UsdCollectionAPI::CanContainPropertyName)
    ;

    bbl::Class<std::vector<PXR_NS::UsdCollectionAPI>>("CollectionAPIVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdCollectionAPI)
        ;

    bbl::Class<PXR_NS::UsdCollectionMembershipQuery>("CollectionMembershipQuery")
        .ctor(bbl::Ctor<PXR_NS::UsdCollectionMembershipQuery>(), "default")
        .ctor(bbl::Ctor<PXR_NS::UsdCollectionMembershipQuery, PXR_NS::UsdCollectionMembershipQuery::PathExpansionRuleMap, PXR_NS::SdfPathSet const&>(), "default")
        .m((bool (PXR_NS::UsdCollectionMembershipQuery::*)(PXR_NS::SdfPath const&, PXR_NS::TfToken*) const)
            &PXR_NS::UsdCollectionMembershipQuery::IsPathIncluded
        )
        .m((bool (PXR_NS::UsdCollectionMembershipQuery::*)(PXR_NS::SdfPath const&, PXR_NS::TfToken const&, PXR_NS::TfToken*) const)
            &PXR_NS::UsdCollectionMembershipQuery::IsPathIncluded, "IsPathIncluded_with_parent_expansion_rule"
        )
        .m(&PXR_NS::UsdCollectionMembershipQuery::HasExcludes)
        .m(&PXR_NS::UsdCollectionMembershipQuery::operator==, "op_eq")
        .m(&PXR_NS::UsdCollectionMembershipQuery::GetAsPathExpansionRuleMap)
        .m(&PXR_NS::UsdCollectionMembershipQuery::GetIncludedCollections)
    ;

    using Perm = PXR_NS::UsdCollectionMembershipQuery::PathExpansionRuleMap;
    using PermIter = PXR_NS::UsdCollectionMembershipQuery::PathExpansionRuleMap::iterator;
    bbl::Class<PXR_NS::UsdCollectionMembershipQuery::PathExpansionRuleMap>("CollectionMembershipQueryPathExpansionRuleMap")
        .ctor(bbl::Ctor<Perm>(), "default")
        // .m((PermIter (Perm::*)())
        //     &Perm::begin
        // )
        // .m((PermIter (Perm::*)())
        //     &Perm::end
        // )
        .m((Perm::mapped_type& (Perm::*)(Perm::key_type const&))
            &Perm::at
        )
    ;

    // bbl::Class<PXR_NS::UsdCollectionMembershipQuery::PathExpansionRuleMap::iterator>("CollectionMembershipQueryPathExpansionRuleMapIterator")
    //     .ctor(bbl::Ctor<PermIter>(), "default")
    //     .m(&PermIter::operator->, "get")
    //     .m((PermIter& (PermIter::*)())
    //         &PXR_NS::UsdCollectionMembershipQuery::PathExpansionRuleMap::iterator::operator++, "op_inc"
    //     )
    //     .m(&PermIter::operator==, "op_eq")
    // ;

    bbl::Class<PXR_NS::UsdModelAPI>("ModelAPI")
        .ctor(bbl::Ctor<PXR_NS::UsdModelAPI, PXR_NS::UsdPrim const&>(), "on_prim")
        .ctor(bbl::Ctor<PXR_NS::UsdModelAPI, PXR_NS::UsdSchemaBase const&>(), "on_schema_obj")
        APISCHEMABASE_METHODS(PXR_NS::UsdModelAPI)
        .m(&PXR_NS::UsdModelAPI::GetAssetIdentifier)
        .m(&PXR_NS::UsdModelAPI::SetAssetIdentifier)
        .m(&PXR_NS::UsdModelAPI::GetAssetName)
        .m(&PXR_NS::UsdModelAPI::SetAssetName)
        .m(&PXR_NS::UsdModelAPI::GetAssetVersion)
        .m(&PXR_NS::UsdModelAPI::SetAssetVersion)
        .m(&PXR_NS::UsdModelAPI::GetPayloadAssetDependencies)
        .m(&PXR_NS::UsdModelAPI::SetPayloadAssetDependencies)
        .m(&PXR_NS::UsdModelAPI::GetAssetInfo)
        .m(&PXR_NS::UsdModelAPI::SetAssetInfo)

        .m(&PXR_NS::UsdModelAPI::Get)
        .m(&PXR_NS::UsdModelAPI::GetSchemaAttributeNames)

        // Kind-ness and Model-ness
        .m(&PXR_NS::UsdModelAPI::GetKind)
        .m(&PXR_NS::UsdModelAPI::SetKind)
        .m(&PXR_NS::UsdModelAPI::IsKind)
        .m(&PXR_NS::UsdModelAPI::IsModel)
        .m(&PXR_NS::UsdModelAPI::IsGroup)
        ;

    bbl::Enum<PXR_NS::UsdModelAPI::KindValidation>("ModelAPIKindValidation");

}


#endif