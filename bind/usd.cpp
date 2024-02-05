#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/attributeQuery.h>
#include <pxr/usd/usd/clipsAPI.h>
#include <pxr/usd/usd/collectionAPI.h>
#include <pxr/usd/usd/collectionMembershipQuery.h>
#include <pxr/usd/usd/common.h>
#include <pxr/usd/usd/interpolation.h>
#include <pxr/base/vt/value.h>
#include <pxr/usd/usd/crateInfo.h>
#include <pxr/usd/usd/editTarget.h>
#include <pxr/usd/usd/inherits.h>
#include <pxr/usd/usd/modelAPI.h>
#include <pxr/usd/usd/notice.h>
#include <pxr/usd/usd/object.h>
#include <pxr/usd/usd/attribute.h>
#include <pxr/usd/usd/relationship.h>
#include <pxr/usd/usd/property.h>
#include <pxr/usd/usd/prim.h>
#include <pxr/usd/usd/payloads.h>
#include <pxr/usd/usd/primCompositionQuery.h>
#include <pxr/usd/usd/primDefinition.h>
#include <pxr/usd/usd/primRange.h>
#include <pxr/usd/usd/references.h>
#include <pxr/usd/usd/resolveInfo.h>
#include <pxr/usd/usd/resolveTarget.h>
#include <pxr/usd/usd/apiSchemaBase.h>
#include <pxr/usd/usd/schemaBase.h>
#include <pxr/usd/usd/schemaRegistry.h>
#include <pxr/usd/usd/specializes.h>
#include <pxr/usd/usd/stage.h>
#include <pxr/usd/usd/stageCache.h>
#include <pxr/usd/usd/stageLoadRules.h>
#include <pxr/usd/usd/stagePopulationMask.h>
#include <pxr/usd/usd/timeCode.h>
#include <pxr/usd/usd/variantSets.h>

struct TimeCode {
    double time;
};


namespace bblext {

auto UsdPrim_GetProperties(PXR_NS::UsdPrim prim) -> std::vector<PXR_NS::UsdProperty> {
    return prim.GetProperties();
}

auto UsdPrim_GetAuthoredProperties(PXR_NS::UsdPrim prim) -> std::vector<PXR_NS::UsdProperty> {
    return prim.GetAuthoredProperties();
}

auto PrimSiblingIterator_op_eq(PXR_NS::UsdPrimSiblingIterator const& lhs, PXR_NS::UsdPrimSiblingIterator const& rhs) -> bool {
    return lhs == rhs;
}

auto UsdSchemaRegistrySchemaInfo_identifier(
    PXR_NS::UsdSchemaRegistry::SchemaInfo const& info) -> PXR_NS::TfToken {
    return info.identifier;
}

auto UsdSchemaRegistrySchemaInfo_type(
    PXR_NS::UsdSchemaRegistry::SchemaInfo const& info) -> PXR_NS::TfType {
    return info.type;
}

auto UsdSchemaRegistrySchemaInfo_family(
    PXR_NS::UsdSchemaRegistry::SchemaInfo const& info) -> PXR_NS::TfToken {
    return info.family;
}

auto UsdSchemaRegistrySchemaInfo_version(
    PXR_NS::UsdSchemaRegistry::SchemaInfo const& info)
    -> PXR_NS::UsdSchemaVersion {
    return info.version;
}

auto UsdSchemaRegistrySchemaInfo_kind(
    PXR_NS::UsdSchemaRegistry::SchemaInfo const& info)
    -> PXR_NS::UsdSchemaKind {
    return info.kind;
}

PXR_NS::UsdStageRefPtr Stage_Open(char const* filename, PXR_NS::UsdStage::InitialLoadSet loadSet) {
    return PXR_NS::UsdStage::Open(filename, loadSet);
}

bool StageRefPtr_ExportToString(
    const PXR_NS::UsdStageRefPtr& stage,
    std::string** output,
    bool addSourceFileComment = true
) {
    return stage->ExportToString(*output, addSourceFileComment);
}

}


BBL_MODULE(usd) {
    // clang-format off

    bbl::Class<PXR_NS::UsdAttributeQuery>("AttributeQuery")
        .ctor(bbl::Class<PXR_NS::UsdAttributeQuery>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::UsdAttributeQuery>::Ctor<PXR_NS::UsdPrim const&, PXR_NS::TfToken const&>(), "from_prim_and_attribute_name")
        .ctor(bbl::Class<PXR_NS::UsdAttributeQuery>::Ctor<PXR_NS::UsdAttribute const&, PXR_NS::UsdResolveTarget const&>(), "from_attribute_and_resolve_target")
        .m(&PXR_NS::UsdAttributeQuery::CreateQueries)
        .m(&PXR_NS::UsdAttributeQuery::GetAttribute)
        .m(&PXR_NS::UsdAttributeQuery::IsValid)
        // Value and Time Sample Accessors
        // Get
        .m((bool (PXR_NS::UsdAttributeQuery::*)(PXR_NS::VtValue*, PXR_NS::UsdTimeCode) const)
            &PXR_NS::UsdAttributeQuery::Get, "Get_value"
        )
        .m(&PXR_NS::UsdAttributeQuery::GetTimeSamples)
        .m(&PXR_NS::UsdAttributeQuery::GetTimeSamplesInInterval)
        .m(&PXR_NS::UsdAttributeQuery::GetNumTimeSamples)
        .m(&PXR_NS::UsdAttributeQuery::GetBracketingTimeSamples)
        .m(&PXR_NS::UsdAttributeQuery::HasValue)
        .m(&PXR_NS::UsdAttributeQuery::HasAuthoredValueOpinion)
        .m(&PXR_NS::UsdAttributeQuery::HasAuthoredValue)
        .m(&PXR_NS::UsdAttributeQuery::HasFallbackValue)
        .m(&PXR_NS::UsdAttributeQuery::ValueMightBeTimeVarying)
        .m(&PXR_NS::UsdAttributeQuery::GetUnionedTimeSamples)
        .m(&PXR_NS::UsdAttributeQuery::GetUnionedTimeSamplesInInterval)
    ;

    bbl::Class<std::vector<PXR_NS::UsdAttributeQuery>>("AttributeQueryVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdAttributeQuery);

    bbl::Class<PXR_NS::UsdClipsAPI>("ClipsAPI")
        .ctor(bbl::Class<PXR_NS::UsdClipsAPI>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdClipsAPI>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .m(&PXR_NS::UsdClipsAPI::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdClipsAPI::Get)
        .m(&PXR_NS::UsdClipsAPI::GetClips)
        .m(&PXR_NS::UsdClipsAPI::SetClips)
        .m(&PXR_NS::UsdClipsAPI::GetClipSets)
        .m(&PXR_NS::UsdClipsAPI::SetClipSets)
        .m((PXR_NS::VtArray<PXR_NS::SdfAssetPath> (PXR_NS::UsdClipsAPI::*)(const std::string &) const)
            &PXR_NS::UsdClipsAPI::ComputeClipAssetPaths, "ComputeClipAssetPaths_00")
        .m((PXR_NS::VtArray<PXR_NS::SdfAssetPath> (PXR_NS::UsdClipsAPI::*)() const)
            &PXR_NS::UsdClipsAPI::ComputeClipAssetPaths, "ComputeClipAssetPaths_01")
        .m((bool (PXR_NS::UsdClipsAPI::*)(PXR_NS::VtArray<PXR_NS::SdfAssetPath> *, const std::string &) const)
            &PXR_NS::UsdClipsAPI::GetClipAssetPaths, "GetClipAssetPaths_00")
        .m((bool (PXR_NS::UsdClipsAPI::*)(PXR_NS::VtArray<PXR_NS::SdfAssetPath> *) const)
            &PXR_NS::UsdClipsAPI::GetClipAssetPaths, "GetClipAssetPaths_01")
        .m((bool (PXR_NS::UsdClipsAPI::*)(const PXR_NS::VtArray<PXR_NS::SdfAssetPath> &, const std::string &))
            &PXR_NS::UsdClipsAPI::SetClipAssetPaths, "SetClipAssetPaths_00")
        .m((bool (PXR_NS::UsdClipsAPI::*)(const PXR_NS::VtArray<PXR_NS::SdfAssetPath> &))
            &PXR_NS::UsdClipsAPI::SetClipAssetPaths, "SetClipAssetPaths_01")
        .m((bool (PXR_NS::UsdClipsAPI::*)(std::string *, const std::string &) const)
            &PXR_NS::UsdClipsAPI::GetClipPrimPath, "GetClipPrimPath_00")
        .m((bool (PXR_NS::UsdClipsAPI::*)(std::string *) const)
            &PXR_NS::UsdClipsAPI::GetClipPrimPath, "GetClipPrimPath_01")
        .m((bool (PXR_NS::UsdClipsAPI::*)(const std::string &, const std::string &))
            &PXR_NS::UsdClipsAPI::SetClipPrimPath, "SetClipPrimPath_00")
        .m((bool (PXR_NS::UsdClipsAPI::*)(const std::string &))
            &PXR_NS::UsdClipsAPI::SetClipPrimPath, "SetClipPrimPath_01")
        .m((bool (PXR_NS::UsdClipsAPI::*)(PXR_NS::VtVec2dArray *, const std::string &) const)
            &PXR_NS::UsdClipsAPI::GetClipActive, "GetClipActive_00")
        .m((bool (PXR_NS::UsdClipsAPI::*)(PXR_NS::VtVec2dArray *) const)
            &PXR_NS::UsdClipsAPI::GetClipActive, "GetClipActive_01")
        .m((bool (PXR_NS::UsdClipsAPI::*)(const PXR_NS::VtVec2dArray &, const std::string &))
            &PXR_NS::UsdClipsAPI::SetClipActive, "SetClipActive_00")
        .m((bool (PXR_NS::UsdClipsAPI::*)(const PXR_NS::VtVec2dArray &))
            &PXR_NS::UsdClipsAPI::SetClipActive, "SetClipActive_01")
        .m((bool (PXR_NS::UsdClipsAPI::*)(PXR_NS::VtVec2dArray *, const std::string &) const)
            &PXR_NS::UsdClipsAPI::GetClipTimes, "GetClipTimes_00")
        .m((bool (PXR_NS::UsdClipsAPI::*)(PXR_NS::VtVec2dArray *) const)
            &PXR_NS::UsdClipsAPI::GetClipTimes, "GetClipTimes_01")
        .m((bool (PXR_NS::UsdClipsAPI::*)(const PXR_NS::VtVec2dArray &, const std::string &))
            &PXR_NS::UsdClipsAPI::SetClipTimes, "SetClipTimes_00")
        .m((bool (PXR_NS::UsdClipsAPI::*)(const PXR_NS::VtVec2dArray &))
            &PXR_NS::UsdClipsAPI::SetClipTimes, "SetClipTimes_01")
        .m((bool (PXR_NS::UsdClipsAPI::*)(PXR_NS::SdfAssetPath *, const std::string &) const)
            &PXR_NS::UsdClipsAPI::GetClipManifestAssetPath, "GetClipManifestAssetPath_00")
        .m((bool (PXR_NS::UsdClipsAPI::*)(PXR_NS::SdfAssetPath *) const)
            &PXR_NS::UsdClipsAPI::GetClipManifestAssetPath, "GetClipManifestAssetPath_01")
        .m((bool (PXR_NS::UsdClipsAPI::*)(const PXR_NS::SdfAssetPath &, const std::string &))
            &PXR_NS::UsdClipsAPI::SetClipManifestAssetPath, "SetClipManifestAssetPath_00")
        .m((bool (PXR_NS::UsdClipsAPI::*)(const PXR_NS::SdfAssetPath &))
            &PXR_NS::UsdClipsAPI::SetClipManifestAssetPath, "SetClipManifestAssetPath_01")
        .m((PXR_NS::SdfLayerRefPtr (PXR_NS::UsdClipsAPI::*)(const std::string &, bool) const)
            &PXR_NS::UsdClipsAPI::GenerateClipManifest, "GenerateClipManifest_00")
        .m((PXR_NS::SdfLayerRefPtr (PXR_NS::UsdClipsAPI::*)(bool) const)
            &PXR_NS::UsdClipsAPI::GenerateClipManifest, "GenerateClipManifest_01")
        .m(&PXR_NS::UsdClipsAPI::GenerateClipManifestFromLayers)
        .m((bool (PXR_NS::UsdClipsAPI::*)(bool *, const std::string &) const)
            &PXR_NS::UsdClipsAPI::GetInterpolateMissingClipValues, "GetInterpolateMissingClipValues_00")
        .m((bool (PXR_NS::UsdClipsAPI::*)(bool *) const)
            &PXR_NS::UsdClipsAPI::GetInterpolateMissingClipValues, "GetInterpolateMissingClipValues_01")
        .m((bool (PXR_NS::UsdClipsAPI::*)(bool, const std::string &))
            &PXR_NS::UsdClipsAPI::SetInterpolateMissingClipValues, "SetInterpolateMissingClipValues_00")
        .m((bool (PXR_NS::UsdClipsAPI::*)(bool))
            &PXR_NS::UsdClipsAPI::SetInterpolateMissingClipValues, "SetInterpolateMissingClipValues_01")
        .m((bool (PXR_NS::UsdClipsAPI::*)(std::string *, const std::string &) const)
            &PXR_NS::UsdClipsAPI::GetClipTemplateAssetPath, "GetClipTemplateAssetPath_00")
        .m((bool (PXR_NS::UsdClipsAPI::*)(std::string *) const)
            &PXR_NS::UsdClipsAPI::GetClipTemplateAssetPath, "GetClipTemplateAssetPath_01")
        .m((bool (PXR_NS::UsdClipsAPI::*)(const std::string &, const std::string &))
            &PXR_NS::UsdClipsAPI::SetClipTemplateAssetPath, "SetClipTemplateAssetPath_00")
        .m((bool (PXR_NS::UsdClipsAPI::*)(const std::string &))
            &PXR_NS::UsdClipsAPI::SetClipTemplateAssetPath, "SetClipTemplateAssetPath_01")
        .m((bool (PXR_NS::UsdClipsAPI::*)(double *, const std::string &) const)
            &PXR_NS::UsdClipsAPI::GetClipTemplateStride, "GetClipTemplateStride_00")
        .m((bool (PXR_NS::UsdClipsAPI::*)(double *) const)
            &PXR_NS::UsdClipsAPI::GetClipTemplateStride, "GetClipTemplateStride_01")
        .m((bool (PXR_NS::UsdClipsAPI::*)(const double, const std::string &))
            &PXR_NS::UsdClipsAPI::SetClipTemplateActiveOffset, "SetClipTemplateActiveOffset_00")
        .m((bool (PXR_NS::UsdClipsAPI::*)(const double))
            &PXR_NS::UsdClipsAPI::SetClipTemplateActiveOffset, "SetClipTemplateActiveOffset_01")
        .m((bool (PXR_NS::UsdClipsAPI::*)(double *, const std::string &) const)
            &PXR_NS::UsdClipsAPI::GetClipTemplateActiveOffset, "GetClipTemplateActiveOffset_00")
        .m((bool (PXR_NS::UsdClipsAPI::*)(double *) const)
            &PXR_NS::UsdClipsAPI::GetClipTemplateActiveOffset, "GetClipTemplateActiveOffset_01")
        .m((bool (PXR_NS::UsdClipsAPI::*)(const double, const std::string &))
            &PXR_NS::UsdClipsAPI::SetClipTemplateStride, "SetClipTemplateStride_00")
        .m((bool (PXR_NS::UsdClipsAPI::*)(const double))
            &PXR_NS::UsdClipsAPI::SetClipTemplateStride, "SetClipTemplateStride_01")
        .m((bool (PXR_NS::UsdClipsAPI::*)(double *, const std::string &) const)
            &PXR_NS::UsdClipsAPI::GetClipTemplateStartTime, "GetClipTemplateStartTime_00")
        .m((bool (PXR_NS::UsdClipsAPI::*)(double *) const)
            &PXR_NS::UsdClipsAPI::GetClipTemplateStartTime, "GetClipTemplateStartTime_01")
        .m((bool (PXR_NS::UsdClipsAPI::*)(const double, const std::string &))
            &PXR_NS::UsdClipsAPI::SetClipTemplateStartTime, "SetClipTemplateStartTime_00")
        .m((bool (PXR_NS::UsdClipsAPI::*)(const double))
            &PXR_NS::UsdClipsAPI::SetClipTemplateStartTime, "SetClipTemplateStartTime_01")
        .m((bool (PXR_NS::UsdClipsAPI::*)(double *, const std::string &) const)
            &PXR_NS::UsdClipsAPI::GetClipTemplateEndTime, "GetClipTemplateEndTime_00")
        .m((bool (PXR_NS::UsdClipsAPI::*)(double *) const)
            &PXR_NS::UsdClipsAPI::GetClipTemplateEndTime, "GetClipTemplateEndTime_01")
        .m((bool (PXR_NS::UsdClipsAPI::*)(const double, const std::string &))
            &PXR_NS::UsdClipsAPI::SetClipTemplateEndTime, "SetClipTemplateEndTime_00")
        .m((bool (PXR_NS::UsdClipsAPI::*)(const double))
            &PXR_NS::UsdClipsAPI::SetClipTemplateEndTime, "SetClipTemplateEndTime_01")
    ;

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

    bbl::Enum<PXR_NS::UsdInterpolationType>("InterpolationType");
    bbl::Enum<PXR_NS::UsdListPosition>("ListPosition");
    bbl::Enum<PXR_NS::UsdLoadPolicy>("LoadPolicy");
    bbl::Enum<PXR_NS::UsdSchemaKind>("SchemaKind");

    bbl::Class<PXR_NS::UsdMetadataValueMap>("MetadataValueMap")
        .m((PXR_NS::UsdMetadataValueMap::mapped_type const& (PXR_NS::UsdMetadataValueMap::*)(PXR_NS::UsdMetadataValueMap::key_type const&) const)
            &PXR_NS::UsdMetadataValueMap::at, "at_const"
        )
        .m((PXR_NS::UsdMetadataValueMap::mapped_type& (PXR_NS::UsdMetadataValueMap::*)(PXR_NS::UsdMetadataValueMap::key_type const&))
            &PXR_NS::UsdMetadataValueMap::at
        )
    ;

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

    bbl::Class<PXR_NS::UsdEditTarget>("EditTarget")
        .ctor(bbl::Class<PXR_NS::UsdEditTarget>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::UsdEditTarget>::Ctor<PXR_NS::SdfLayerHandle, PXR_NS::SdfLayerOffset>(), "from_layer_handle")
        .ctor(bbl::Class<PXR_NS::UsdEditTarget>::Ctor<PXR_NS::SdfLayerRefPtr, PXR_NS::SdfLayerOffset>(), "from_layer_ref_ptr")
        .ctor(bbl::Class<PXR_NS::UsdEditTarget>::Ctor<PXR_NS::SdfLayerHandle, PXR_NS::PcpNodeRef>(), "from_layer_handle_and_node")
        .m(&PXR_NS::UsdEditTarget::operator==, "op_eq")
        .m(&PXR_NS::UsdEditTarget::IsNull)
        .m(&PXR_NS::UsdEditTarget::IsValid)
        .m((PXR_NS::SdfLayerHandle const& (PXR_NS::UsdEditTarget::*)() const&)
            &PXR_NS::UsdEditTarget::GetLayer
        )
        .m(&PXR_NS::UsdEditTarget::MapToSpecPath)
        .m(&PXR_NS::UsdEditTarget::GetPrimSpecForScenePath)
        .m(&PXR_NS::UsdEditTarget::GetPropertySpecForScenePath)
        .m(&PXR_NS::UsdEditTarget::GetSpecForScenePath)
        .m(&PXR_NS::UsdEditTarget::GetMapFunction)
        .m(&PXR_NS::UsdEditTarget::ComposeOver)
        .m(&PXR_NS::UsdEditTarget::ForLocalDirectVariant)
        ;

    bbl::Class<PXR_NS::UsdInherits>("Inherits")
        .m(&PXR_NS::UsdInherits::AddInherit)
        .m(&PXR_NS::UsdInherits::RemoveInherit)
        .m(&PXR_NS::UsdInherits::ClearInherits)
        .m(&PXR_NS::UsdInherits::SetInherits)
        .m(&PXR_NS::UsdInherits::GetAllDirectInherits)
        .m((PXR_NS::UsdPrim const&(PXR_NS::UsdInherits::*)() const)
            &PXR_NS::UsdInherits::GetPrim
        )
        .m(&PXR_NS::UsdInherits::operator bool, "op_bool")
    ;

    bbl::Class<PXR_NS::UsdModelAPI>("ModelAPI")
        .ctor(bbl::Class<PXR_NS::UsdModelAPI>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdModelAPI>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .m(&PXR_NS::UsdModelAPI::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdModelAPI::Get)
        .m(&PXR_NS::UsdModelAPI::GetKind)
        .m(&PXR_NS::UsdModelAPI::SetKind)
        .m(&PXR_NS::UsdModelAPI::IsKind)
        .m(&PXR_NS::UsdModelAPI::IsModel)
        .m(&PXR_NS::UsdModelAPI::IsGroup)
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
        /** TODO: instantiate this template
        .m(&PXR_NS::UsdModelAPI::_GetAssetInfoByKey)
        */
    ;

    bbl::Enum<PXR_NS::UsdModelAPI::KindValidation>("ModelAPIKindValidation");

    bbl::Class<PXR_NS::UsdNotice>("Notice")
    ;

    bbl::Class<PXR_NS::UsdNotice::StageNotice>("StageNotice")
        .ctor(bbl::Class<PXR_NS::UsdNotice::StageNotice>::Ctor<const PXR_NS::UsdStageWeakPtr &>("stage"), "ctor_00")
        .m(&PXR_NS::UsdNotice::StageNotice::GetStage)
    ;

    bbl::Class<PXR_NS::UsdNotice::StageContentsChanged>("StageContentsChanged")
        .ctor(bbl::Class<PXR_NS::UsdNotice::StageContentsChanged>::Ctor<const PXR_NS::UsdStageWeakPtr &>("stage"), "ctor_00")
    ;

    bbl::Class<PXR_NS::UsdNotice::ObjectsChanged>("ObjectsChanged")
        .m(&PXR_NS::UsdNotice::ObjectsChanged::AffectedObject)
        .m(&PXR_NS::UsdNotice::ObjectsChanged::ResyncedObject)
        .m(&PXR_NS::UsdNotice::ObjectsChanged::ChangedInfoOnly)
        .m(&PXR_NS::UsdNotice::ObjectsChanged::GetResyncedPaths)
        .m(&PXR_NS::UsdNotice::ObjectsChanged::GetChangedInfoOnlyPaths)
        .m((PXR_NS::TfTokenVector (PXR_NS::UsdNotice::ObjectsChanged::*)(const PXR_NS::UsdObject &) const)
            &PXR_NS::UsdNotice::ObjectsChanged::GetChangedFields, "GetChangedFields_00")
        .m((PXR_NS::TfTokenVector (PXR_NS::UsdNotice::ObjectsChanged::*)(const PXR_NS::SdfPath &) const)
            &PXR_NS::UsdNotice::ObjectsChanged::GetChangedFields, "GetChangedFields_01")
        .m((bool (PXR_NS::UsdNotice::ObjectsChanged::*)(const PXR_NS::UsdObject &) const)
            &PXR_NS::UsdNotice::ObjectsChanged::HasChangedFields, "HasChangedFields_00")
        .m((bool (PXR_NS::UsdNotice::ObjectsChanged::*)(const PXR_NS::SdfPath &) const)
            &PXR_NS::UsdNotice::ObjectsChanged::HasChangedFields, "HasChangedFields_01")
    ;

    bbl::Class<PXR_NS::UsdNotice::ObjectsChanged::PathRange>("ObjectsChangedPathRange")
        .ctor(bbl::Class<PXR_NS::UsdNotice::ObjectsChanged::PathRange>::Ctor<>(), "default")
        .m(&PXR_NS::UsdNotice::ObjectsChanged::PathRange::empty)
        .m(&PXR_NS::UsdNotice::ObjectsChanged::PathRange::size)
        .m(&PXR_NS::UsdNotice::ObjectsChanged::PathRange::begin)
        .m(&PXR_NS::UsdNotice::ObjectsChanged::PathRange::cbegin)
        .m(&PXR_NS::UsdNotice::ObjectsChanged::PathRange::end)
        .m(&PXR_NS::UsdNotice::ObjectsChanged::PathRange::cend)
        .m(&PXR_NS::UsdNotice::ObjectsChanged::PathRange::find)
    ;

    bbl::Class<PXR_NS::UsdNotice::ObjectsChanged::PathRange::iterator>("ObjectsChangedPathRangeIterator")
        .ctor(bbl::Class<PXR_NS::UsdNotice::ObjectsChanged::PathRange::iterator>::Ctor<>(), "default")
        .m(&PXR_NS::UsdNotice::ObjectsChanged::PathRange::iterator::GetChangedFields)
        .m(&PXR_NS::UsdNotice::ObjectsChanged::PathRange::iterator::HasChangedFields)
    ;

    bbl::Class<PXR_NS::UsdNotice::StageEditTargetChanged>("StageEditTargetChanged")
        .ctor(bbl::Class<PXR_NS::UsdNotice::StageEditTargetChanged>::Ctor<const PXR_NS::UsdStageWeakPtr &>("stage"), "ctor_00")
    ;

    bbl::Class<PXR_NS::UsdNotice::LayerMutingChanged>("LayerMutingChanged")
        .ctor(bbl::Class<PXR_NS::UsdNotice::LayerMutingChanged>::Ctor<const PXR_NS::UsdStageWeakPtr &, const std::vector<std::string> &, const std::vector<std::string> &>("stage", "mutedLayers", "unmutedLayers"), "ctor_00")
        .m(&PXR_NS::UsdNotice::LayerMutingChanged::GetMutedLayers)
        .m(&PXR_NS::UsdNotice::LayerMutingChanged::GetUnmutedLayers)
    ;

    bbl::Class<PXR_NS::UsdAttribute>("Attribute")
        .ctor(bbl::Class<PXR_NS::UsdAttribute>::Ctor<>(), "default")
        .m(&PXR_NS::UsdAttribute::GetVariability)                                                   
        .m(&PXR_NS::UsdAttribute::SetVariability)                                               
        .m(&PXR_NS::UsdAttribute::GetTypeName)                                                  
        .m(&PXR_NS::UsdAttribute::SetTypeName)                                                  
        .m(&PXR_NS::UsdAttribute::GetRoleName)                                                  
        .m(&PXR_NS::UsdAttribute::AddConnection)                                                
        .m(&PXR_NS::UsdAttribute::RemoveConnection)                                             
        .m(&PXR_NS::UsdAttribute::SetConnections)                                               
        .m(&PXR_NS::UsdAttribute::ClearConnections)                                             
        .m(&PXR_NS::UsdAttribute::GetConnections)                                               
        .m(&PXR_NS::UsdAttribute::HasAuthoredConnections)                                       
        .m(&PXR_NS::UsdAttribute::GetColorSpace)                                                
        .m(&PXR_NS::UsdAttribute::SetColorSpace)                                                
        .m(&PXR_NS::UsdAttribute::HasColorSpace)                                                
        .m(&PXR_NS::UsdAttribute::ClearColorSpace)                                              
        .m(&PXR_NS::UsdAttribute::GetTimeSamples)                                               
        .m(&PXR_NS::UsdAttribute::GetTimeSamplesInInterval)                                     
        .m(&PXR_NS::UsdAttribute::GetNumTimeSamples)                                            
        .m(&PXR_NS::UsdAttribute::GetBracketingTimeSamples)                                     
        .m(&PXR_NS::UsdAttribute::HasValue)                                                     
        .m(&PXR_NS::UsdAttribute::HasAuthoredValueOpinion)                                      
        .m(&PXR_NS::UsdAttribute::HasAuthoredValue)                                             
        .m(&PXR_NS::UsdAttribute::HasFallbackValue)                                             
        .m(&PXR_NS::UsdAttribute::ValueMightBeTimeVarying)                                      
        .m((bool(PXR_NS::UsdAttribute::*)(PXR_NS::VtValue*, PXR_NS::UsdTimeCode) const) 
            &PXR_NS::UsdAttribute::Get
        ) 
        .m((PXR_NS::UsdResolveInfo(PXR_NS::UsdAttribute::*)(PXR_NS::UsdTimeCode) const) 
            &PXR_NS::UsdAttribute::GetResolveInfo, "GetResolveInfo_at_time"
        )
        .m((PXR_NS::UsdResolveInfo(PXR_NS::UsdAttribute::*)() const) 
            &PXR_NS::UsdAttribute::GetResolveInfo
        ) 
        .m((bool(PXR_NS::UsdAttribute::*)(PXR_NS::VtValue const&, PXR_NS::UsdTimeCode) const) 
            &PXR_NS::UsdAttribute::Set
        ) 
        .m(&PXR_NS::UsdAttribute::Clear)                                                        
        .m(&PXR_NS::UsdAttribute::ClearAtTime)                                                  
        .m(&PXR_NS::UsdAttribute::ClearDefault)                                                 
        .m(&PXR_NS::UsdAttribute::Block)                                                        
        .m(&PXR_NS::UsdAttribute::GetUnionedTimeSamples)                                        
        .m(&PXR_NS::UsdAttribute::GetUnionedTimeSamplesInInterval)
    ;

    bbl::Class<std::vector<PXR_NS::UsdAttribute>>("AttributeVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdAttribute);


    bbl::Class<PXR_NS::UsdObject>("Object")
        .ctor(bbl::Class<PXR_NS::UsdObject>::Ctor<>(), "default")
        .m(&PXR_NS::UsdObject::Is<PXR_NS::UsdAttribute>, "Is_Attribute")
        .m(&PXR_NS::UsdObject::Is<PXR_NS::UsdRelationship>, "Is_Relationship")
        .m(&PXR_NS::UsdObject::Is<PXR_NS::UsdProperty>, "Is_Property")
        .m(&PXR_NS::UsdObject::Is<PXR_NS::UsdPrim>, "Is_Prim")
        .m(&PXR_NS::UsdObject::As<PXR_NS::UsdAttribute>, "As_Attribute")
        .m(&PXR_NS::UsdObject::As<PXR_NS::UsdRelationship>, "As_Relationship")
        .m(&PXR_NS::UsdObject::As<PXR_NS::UsdProperty>, "As_Property")
        .m(&PXR_NS::UsdObject::As<PXR_NS::UsdPrim>, "As_Prim")
        .m((bool(PXR_NS::UsdObject::*)(PXR_NS::TfToken const&, PXR_NS::VtValue*) const) 
            &PXR_NS::UsdObject::GetMetadata, "GetMetadata_value"
        )
        .m((bool(PXR_NS::UsdObject::*)(PXR_NS::TfToken const&, PXR_NS::VtValue const&) const) 
            &PXR_NS::UsdObject::SetMetadata, "SetMetadata_value"
        )
        .m(&PXR_NS::UsdObject::ClearMetadata)                                                
        .m(&PXR_NS::UsdObject::HasMetadata)                                                  
        .m(&PXR_NS::UsdObject::HasAuthoredMetadata)                                          
        .m((bool(PXR_NS::UsdObject::*)(PXR_NS::TfToken const&, PXR_NS::TfToken const&, PXR_NS::VtValue*) const) 
            &PXR_NS::UsdObject::GetMetadataByDictKey, "GetMetadataByDictKey_value"
        )
        .m((bool(PXR_NS::UsdObject::*)(PXR_NS::TfToken const&, PXR_NS::TfToken const&, PXR_NS::VtValue const&) const)
            &PXR_NS::UsdObject::SetMetadataByDictKey, "SetMetadataByDictKey_value"
        )                                       
        .m(&PXR_NS::UsdObject::ClearMetadataByDictKey)                                       
        .m(&PXR_NS::UsdObject::HasMetadataDictKey)                                           
        .m(&PXR_NS::UsdObject::HasAuthoredMetadataDictKey)                                   
        .m(&PXR_NS::UsdObject::GetAllMetadata)                                               
        .m(&PXR_NS::UsdObject::GetAllAuthoredMetadata)                                       
        .m(&PXR_NS::UsdObject::IsHidden)                                                     
        .m(&PXR_NS::UsdObject::SetHidden)                                                    
        .m(&PXR_NS::UsdObject::ClearHidden)                                                  
        .m(&PXR_NS::UsdObject::HasAuthoredHidden)                                            
        .m(&PXR_NS::UsdObject::GetCustomData)                                                
        .m(&PXR_NS::UsdObject::GetCustomDataByKey)                                           
        .m(&PXR_NS::UsdObject::SetCustomData)                                                
        .m(&PXR_NS::UsdObject::SetCustomDataByKey)                                           
        .m(&PXR_NS::UsdObject::ClearCustomData)                                              
        .m(&PXR_NS::UsdObject::ClearCustomDataByKey)                                         
        .m(&PXR_NS::UsdObject::HasCustomData)                                                
        .m(&PXR_NS::UsdObject::HasCustomDataKey)                                             
        .m(&PXR_NS::UsdObject::HasAuthoredCustomData)                                        
        .m(&PXR_NS::UsdObject::HasAuthoredCustomDataKey)                                     
        .m(&PXR_NS::UsdObject::GetAssetInfo)                                                 
        .m(&PXR_NS::UsdObject::GetAssetInfoByKey)                                            
        .m(&PXR_NS::UsdObject::SetAssetInfo)                                                 
        .m(&PXR_NS::UsdObject::SetAssetInfoByKey)                                            
        .m(&PXR_NS::UsdObject::ClearAssetInfo)                                               
        .m(&PXR_NS::UsdObject::ClearAssetInfoByKey)                                          
        .m(&PXR_NS::UsdObject::HasAssetInfo)                                                 
        .m(&PXR_NS::UsdObject::HasAssetInfoKey)                                              
        .m(&PXR_NS::UsdObject::HasAuthoredAssetInfo)                                         
        .m(&PXR_NS::UsdObject::HasAuthoredAssetInfoKey)                                      
        .m(&PXR_NS::UsdObject::GetDocumentation)                                             
        .m(&PXR_NS::UsdObject::SetDocumentation)                                             
        .m(&PXR_NS::UsdObject::ClearDocumentation)                                           
        .m(&PXR_NS::UsdObject::HasAuthoredDocumentation)                                     
        .m(&PXR_NS::UsdObject::GetDisplayName)                                               
        .m(&PXR_NS::UsdObject::SetDisplayName)                                               
        .m(&PXR_NS::UsdObject::ClearDisplayName)                                             
        .m(&PXR_NS::UsdObject::HasAuthoredDisplayName)                                       
        .m(&PXR_NS::UsdObject::IsValid)                                                      
        .m(&PXR_NS::UsdObject::GetStage)                                                     
        .m(&PXR_NS::UsdObject::GetPath)                                                      
        .m(&PXR_NS::UsdObject::GetPrimPath)                                                  
        .m(&PXR_NS::UsdObject::GetPrim)                                                      
        .m(&PXR_NS::UsdObject::GetName)                                                      
        .m(&PXR_NS::UsdObject::GetNamespaceDelimiter)                                        
        .m(&PXR_NS::UsdObject::GetDescription)
    ;

    bbl::Enum<PXR_NS::UsdObjType>();
    bbl::fn(&PXR_NS::UsdIsSubtype);
    bbl::fn(&PXR_NS::UsdIsConvertible);
    bbl::fn(&PXR_NS::UsdIsConcrete);

    bbl::Class<std::set<PXR_NS::UsdObject>>("ObjectSet")
        .ctor(bbl::Class<std::set<PXR_NS::UsdObject>>::Ctor<>(), "default")
    ;

    bbl::Class<PXR_NS::UsdPrim>("Prim")
        .opaque_ptr()
        .ctor(bbl::Class<PXR_NS::UsdPrim>::Ctor<>(), "default")
        .m(&PXR_NS::UsdPrim::GetPrimTypeInfo)
        .m(&PXR_NS::UsdPrim::GetPrimDefinition)
        .m(&PXR_NS::UsdPrim::GetSpecifier)
        .m(&PXR_NS::UsdPrim::SetSpecifier)
        .m(&PXR_NS::UsdPrim::GetPrimStack)
        .m(&PXR_NS::UsdPrim::GetPrimStackWithLayerOffsets)
        .m(&PXR_NS::UsdPrim::GetTypeName)
        .m(&PXR_NS::UsdPrim::SetTypeName)
        .m(&PXR_NS::UsdPrim::ClearTypeName)
        .m(&PXR_NS::UsdPrim::HasAuthoredTypeName)
        .m(&PXR_NS::UsdPrim::IsActive)
        .m(&PXR_NS::UsdPrim::SetActive)
        .m(&PXR_NS::UsdPrim::ClearActive)
        .m(&PXR_NS::UsdPrim::HasAuthoredActive)
        .m(&PXR_NS::UsdPrim::IsLoaded)
        .m(&PXR_NS::UsdPrim::IsModel)
        .m(&PXR_NS::UsdPrim::IsGroup)
        .m(&PXR_NS::UsdPrim::IsAbstract)
        .m(&PXR_NS::UsdPrim::IsDefined)
        .m(&PXR_NS::UsdPrim::HasDefiningSpecifier)
        .m(&PXR_NS::UsdPrim::GetAppliedSchemas)
        .m(&PXR_NS::UsdPrim::GetPropertyNames)
        .m(&PXR_NS::UsdPrim::GetAuthoredPropertyNames)
        .m(&PXR_NS::UsdPrim::GetProperties, "GetProperties_matching_predicate")
        .m(&PXR_NS::UsdPrim::GetAuthoredProperties, "GetAuthoredProperties_matching_predicate")
        .m((std::vector<PXR_NS::UsdProperty>(PXR_NS::UsdPrim::*)(std::string const&) const) 
            &PXR_NS::UsdPrim::GetPropertiesInNamespace
        )
        .m((std::vector<PXR_NS::UsdProperty>(PXR_NS::UsdPrim::*)(std::string const&) const) 
            &PXR_NS::UsdPrim::GetAuthoredPropertiesInNamespace
        )
        .m(&PXR_NS::UsdPrim::GetPropertyOrder)
        .m(&PXR_NS::UsdPrim::SetPropertyOrder)
        .m(&PXR_NS::UsdPrim::ClearPropertyOrder)
        .m(&PXR_NS::UsdPrim::RemoveProperty)
        .m(&PXR_NS::UsdPrim::GetProperty)
        .m(&PXR_NS::UsdPrim::HasProperty)
        .m(&PXR_NS::UsdPrim::AddAppliedSchema)
        .m(&PXR_NS::UsdPrim::RemoveAppliedSchema)

        // IsA
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&) const) 
            &PXR_NS::UsdPrim::IsA
        )

        // methods can be renamed to give useful names to overloads
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&, PXR_NS::UsdSchemaVersion) const) 
            &PXR_NS::UsdPrim::IsA, "IsA_with_version"
        )

        // IsInFamily
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&) const) 
            &PXR_NS::UsdPrim::IsInFamily
        )
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&, PXR_NS::UsdSchemaRegistry::VersionPolicy) const) 
            &PXR_NS::UsdPrim::IsInFamily, "IsInFamily_with_policy"
        )
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&, PXR_NS::UsdSchemaVersion, PXR_NS::UsdSchemaRegistry::VersionPolicy) const) 
            &PXR_NS::UsdPrim::IsInFamily, "IsInFamily_with_policy_and_version"
        )
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfType const&, PXR_NS::UsdSchemaRegistry::VersionPolicy) const) 
            &PXR_NS::UsdPrim::IsInFamily, "IsInFamily_with_type"
        )
        .m(&PXR_NS::UsdPrim::GetVersionIfIsInFamily)

        // HasAPI
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfType const&) const) 
            &PXR_NS::UsdPrim::HasAPI
        )
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfType const&, PXR_NS::TfToken const&) const) 
            &PXR_NS::UsdPrim::HasAPI, "HasAPI_with_instance_name"
        )
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&) const) 
            &PXR_NS::UsdPrim::HasAPI, "HasAPI_with_schema_identifier"
        )
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&, PXR_NS::TfToken const&) const) 
            &PXR_NS::UsdPrim::HasAPI, "HasAPI_with_instance_name_and_schema_identifier"
        )

        // HasAPIInFamily
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&) const) 
            &PXR_NS::UsdPrim::HasAPIInFamily
        )
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&, PXR_NS::TfToken const&) const) 
            &PXR_NS::UsdPrim::HasAPIInFamily, "HasAPIInFamily_with_instance"
        )
        .m((bool(PXR_NS::UsdPrim::*)( PXR_NS::TfToken const&, PXR_NS::UsdSchemaVersion, PXR_NS::UsdSchemaRegistry::VersionPolicy) const) 
            &PXR_NS::UsdPrim::HasAPIInFamily, "HasAPIInFamily_with_version"
        )
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&, PXR_NS::UsdSchemaVersion, PXR_NS::UsdSchemaRegistry::VersionPolicy, PXR_NS::TfToken const&) const) 
            &PXR_NS::UsdPrim::HasAPIInFamily, "HasAPIInFamily_with_version_and_instance"
        )
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfType const&,
        //                              PXR_NS::UsdSchemaRegistry::VersionPolicy)
        //         const) &
        //    PXR_NS::UsdPrim::HasAPIInFamily)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfType const&,
        //                              PXR_NS::UsdSchemaRegistry::VersionPolicy,
        //                              PXR_NS::TfToken const&) const) &
        //    PXR_NS::UsdPrim::HasAPIInFamily)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&,
        //                              PXR_NS::UsdSchemaRegistry::VersionPolicy)
        //         const) &
        //    PXR_NS::UsdPrim::HasAPIInFamily)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&,
        //                              PXR_NS::UsdSchemaRegistry::VersionPolicy,
        //                              PXR_NS::TfToken const&) const) &
        //    PXR_NS::UsdPrim::HasAPIInFamily)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&,
        //                              PXR_NS::UsdSchemaVersion*) const) &
        //    PXR_NS::UsdPrim::GetVersionIfHasAPIInFamily)
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&, PXR_NS::TfToken const&, PXR_NS::UsdSchemaVersion*) const) 
            &PXR_NS::UsdPrim::GetVersionIfHasAPIInFamily
        )

        // CanApplyAPI
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfType const&, std::string*) const) 
            &PXR_NS::UsdPrim::CanApplyAPI
        ) 
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfType const&,
        //                              PXR_NS::TfToken const&, std::string*)
        //         const) &
        //    PXR_NS::UsdPrim::CanApplyAPI)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&, std::string*)
        //         const) &
        //    PXR_NS::UsdPrim::CanApplyAPI)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&,
        //                              PXR_NS::TfToken const&, std::string*)
        //         const) &
        //    PXR_NS::UsdPrim::CanApplyAPI)
        // .m((bool(PXR_NS::UsdPrim::*)(
        //        PXR_NS::TfToken const&, PXR_NS::UsdSchemaVersion,
        //        PXR_NS::TfToken const&, std::string*) const) &
        //    PXR_NS::UsdPrim::CanApplyAPI)

        // ApplyAPI
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfType const&) const) 
            &PXR_NS::UsdPrim::ApplyAPI
        )
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfType const&,
        //                              PXR_NS::TfToken const&) const) &
        //    PXR_NS::UsdPrim::ApplyAPI)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&) const) &
        //    PXR_NS::UsdPrim::ApplyAPI)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&,
        //                              PXR_NS::TfToken const&) const) &
        //    PXR_NS::UsdPrim::ApplyAPI)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&,
        //                              PXR_NS::UsdSchemaVersion) const) &
        //    PXR_NS::UsdPrim::ApplyAPI)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&,
        //                              PXR_NS::UsdSchemaVersion,
        //                              PXR_NS::TfToken const&) const) &
        //    PXR_NS::UsdPrim::ApplyAPI)

        // RemoveAPI
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfType const&) const) 
            &PXR_NS::UsdPrim::RemoveAPI
        )
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfType const&,
        //                              PXR_NS::TfToken const&) const) &
        //    PXR_NS::UsdPrim::RemoveAPI)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&) const) &
        //    PXR_NS::UsdPrim::RemoveAPI)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&,
        //                              PXR_NS::TfToken const&) const) &
        //    PXR_NS::UsdPrim::RemoveAPI)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&,
        //                              PXR_NS::UsdSchemaVersion) const) &
        //    PXR_NS::UsdPrim::RemoveAPI)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&,
        //                              PXR_NS::UsdSchemaVersion,
        //                              PXR_NS::TfToken const&) const) &
        //    PXR_NS::UsdPrim::RemoveAPI)

        // PXR_NS::UsdPrim Children
        .m(&PXR_NS::UsdPrim::GetChild)
        .m(&PXR_NS::UsdPrim::GetChildren)
        .m(&PXR_NS::UsdPrim::GetAllChildren)
        .m(&PXR_NS::UsdPrim::GetFilteredChildren)
        .m(&PXR_NS::UsdPrim::GetChildrenNames)
        .m(&PXR_NS::UsdPrim::GetFilteredChildrenNames)
        .m(&PXR_NS::UsdPrim::GetDescendants)
        .m(&PXR_NS::UsdPrim::GetAllDescendants)
        .m(&PXR_NS::UsdPrim::GetFilteredDescendants)
        .m(&PXR_NS::UsdPrim::GetChildrenReorder)
        .m(&PXR_NS::UsdPrim::SetChildrenReorder)
        .m(&PXR_NS::UsdPrim::ClearChildrenReorder)

        // Parent & Stage
        .m(&PXR_NS::UsdPrim::GetParent)
        .m(&PXR_NS::UsdPrim::GetNextSibling)
        .m(&PXR_NS::UsdPrim::GetFilteredNextSibling)
        .m(&PXR_NS::UsdPrim::IsPseudoRoot)
        .m(&PXR_NS::UsdPrim::GetPrimAtPath)
        .m(&PXR_NS::UsdPrim::GetObjectAtPath)
        .m(&PXR_NS::UsdPrim::GetPropertyAtPath)
        .m(&PXR_NS::UsdPrim::GetAttributeAtPath)
        .m(&PXR_NS::UsdPrim::GetRelationshipAtPath)

        // Variants
        .m(&PXR_NS::UsdPrim::GetVariantSets)
        .m(&PXR_NS::UsdPrim::GetVariantSet)
        .m(&PXR_NS::UsdPrim::HasVariantSets)

        // Attributes
        // We'll only do one of these create methods as the rest are for
        // convenience, and we should do convenience on the FFI side
        .m((PXR_NS::UsdAttribute(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&, PXR_NS::SdfValueTypeName const&, bool, PXR_NS::SdfVariability) const) 
            &PXR_NS::UsdPrim::CreateAttribute
        )
        .m(&PXR_NS::UsdPrim::GetAttributes)
        .m(&PXR_NS::UsdPrim::GetAuthoredAttributes)
        .m(&PXR_NS::UsdPrim::GetAttribute)
        .m(&PXR_NS::UsdPrim::HasAttribute)
        .m(&PXR_NS::UsdPrim::FindAllAttributeConnectionPaths)

        // Relationships
        .m((PXR_NS::UsdRelationship(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&, bool) const) 
            &PXR_NS::UsdPrim::CreateRelationship
        )
        .m(&PXR_NS::UsdPrim::GetRelationships)
        .m(&PXR_NS::UsdPrim::GetAuthoredRelationships)
        .m(&PXR_NS::UsdPrim::GetRelationship)
        .m(&PXR_NS::UsdPrim::HasRelationship)
        .m(&PXR_NS::UsdPrim::FindAllRelationshipTargetPaths)

        // Payloads, load and unload
        .m(&PXR_NS::UsdPrim::GetPayloads)
        .m(&PXR_NS::UsdPrim::HasAuthoredPayloads)
        .m(&PXR_NS::UsdPrim::Load)
        .m(&PXR_NS::UsdPrim::Unload)

        // References
        .m(&PXR_NS::UsdPrim::GetReferences)
        .m(&PXR_NS::UsdPrim::HasAuthoredReferences)

        // Inherits
        .m(&PXR_NS::UsdPrim::GetInherits)
        .m(&PXR_NS::UsdPrim::HasAuthoredInherits)

        // Specializes
        .m(&PXR_NS::UsdPrim::GetSpecializes)
        .m(&PXR_NS::UsdPrim::HasAuthoredSpecializes)

        // Instances
        .m(&PXR_NS::UsdPrim::IsInstanceable)
        .m(&PXR_NS::UsdPrim::SetInstanceable)
        .m(&PXR_NS::UsdPrim::ClearInstanceable)
        .m(&PXR_NS::UsdPrim::HasAuthoredInstanceable)
        .m(&PXR_NS::UsdPrim::IsInstance)
        .m(&PXR_NS::UsdPrim::IsInstanceProxy)
        .m(&PXR_NS::UsdPrim::IsPrototypePath)
        .m(&PXR_NS::UsdPrim::IsPathInPrototype)
        .m(&PXR_NS::UsdPrim::IsPrototype)
        .m(&PXR_NS::UsdPrim::IsInPrototype)
        .m(&PXR_NS::UsdPrim::GetPrototype)
        .m(&PXR_NS::UsdPrim::GetPrimInPrototype)
        .m(&PXR_NS::UsdPrim::GetInstances)

        // Composition
        .m(&PXR_NS::UsdPrim::GetPrimIndex)
        .m(&PXR_NS::UsdPrim::ComputeExpandedPrimIndex)
        .m(&PXR_NS::UsdPrim::MakeResolveTargetUpToEditTarget)
        .m(&PXR_NS::UsdPrim::MakeResolveTargetStrongerThanEditTarget)
        ;

    bbl::Class<PXR_NS::UsdPrimTypeInfo>("PrimTypeInfo")
        .m(&PXR_NS::UsdPrimTypeInfo::GetTypeName)
        .m(&PXR_NS::UsdPrimTypeInfo::GetAppliedAPISchemas)
        .m(&PXR_NS::UsdPrimTypeInfo::GetSchemaType)
        .m(&PXR_NS::UsdPrimTypeInfo::GetSchemaTypeName)
        .m(&PXR_NS::UsdPrimTypeInfo::GetPrimDefinition)
        .m(&PXR_NS::UsdPrimTypeInfo::GetEmptyPrimType)
    ;

    bbl::Class<std::vector<PXR_NS::UsdPrim>>("PrimVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdPrim);
    bbl::Class<PXR_NS::Usd_PrimFlagsPredicate>("PrimFlagsPredicate");

    // Manually generate overrides that don't take a stdfunction for convenience
    bbl::fn(&bblext::UsdPrim_GetProperties, "Prim_GetProperties");
    bbl::fn(&bblext::UsdPrim_GetAuthoredProperties, "Prim_GetAuthoredProperties");

    bbl::Class<PXR_NS::UsdProperty>("Property")
        .ctor(bbl::Class<PXR_NS::UsdProperty>::Ctor<>(), "default")
        .m(&PXR_NS::UsdProperty::GetPropertyStack)                                                 
        .m(&PXR_NS::UsdProperty::GetPropertyStackWithLayerOffsets)                             
        .m(&PXR_NS::UsdProperty::GetBaseName)                                                  
        .m(&PXR_NS::UsdProperty::GetNamespace)                                                 
        .m(&PXR_NS::UsdProperty::SplitName)                                                    
        .m(&PXR_NS::UsdProperty::GetDisplayGroup)                                              
        .m(&PXR_NS::UsdProperty::SetDisplayGroup)                                              
        .m(&PXR_NS::UsdProperty::ClearDisplayGroup)                                            
        .m(&PXR_NS::UsdProperty::HasAuthoredDisplayGroup)                                      
        .m(&PXR_NS::UsdProperty::GetNestedDisplayGroups)                                       
        .m(&PXR_NS::UsdProperty::SetNestedDisplayGroups)                                       
        .m(&PXR_NS::UsdProperty::IsCustom)                                                     
        .m(&PXR_NS::UsdProperty::SetCustom)                                                    
        .m(&PXR_NS::UsdProperty::IsDefined)                                                    
        .m(&PXR_NS::UsdProperty::IsAuthored)                                                   
        .m(&PXR_NS::UsdProperty::IsAuthoredAt)                                                 
        .m((PXR_NS::UsdProperty (PXR_NS::UsdProperty::*)(PXR_NS::UsdPrim const&) const) 
            &PXR_NS::UsdProperty::FlattenTo, "FlattenTo_prim"
        )                                                   
        .m((PXR_NS::UsdProperty(PXR_NS::UsdProperty::*)(PXR_NS::UsdPrim const&, PXR_NS::TfToken const&) const)
            & PXR_NS::UsdProperty::FlattenTo, "FlattenTo_named_property"
        )  
        .m((PXR_NS::UsdProperty(PXR_NS::UsdProperty::*)(PXR_NS::UsdProperty const&) const) 
            &PXR_NS::UsdProperty::FlattenTo, "FlattenTo_property"
        )
    ;

    bbl::Class<PXR_NS::UsdPrim::PropertyPredicateFunc>("PropertyPredicateFunc");

    bbl::Class<std::vector<PXR_NS::UsdProperty>>("PropertyVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdProperty)
    ;

    bbl::Class<PXR_NS::UsdRelationship>("Relationship")
        .ctor(bbl::Class<PXR_NS::UsdRelationship>::Ctor<>(), "default")
        .m(&PXR_NS::UsdRelationship::AddTarget)
        .m(&PXR_NS::UsdRelationship::RemoveTarget)
        .m(&PXR_NS::UsdRelationship::SetTargets)
        .m(&PXR_NS::UsdRelationship::ClearTargets)
        .m(&PXR_NS::UsdRelationship::GetTargets)
        .m(&PXR_NS::UsdRelationship::GetForwardedTargets)
        .m(&PXR_NS::UsdRelationship::HasAuthoredTargets)
        ;
    ;

    bbl::Class<std::vector<PXR_NS::UsdRelationship>>("RelationshipVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdRelationship)
    ;

    bbl::Class<std::function<bool(PXR_NS::UsdAttribute const&)>>("FindAttributePredicate");
    bbl::Class<std::function<bool(PXR_NS::UsdRelationship const&)>>("FindRelationshipPredicate");

    bbl::Class<PXR_NS::UsdPayloads>("Payloads")
        .m((bool (PXR_NS::UsdPayloads::*)(PXR_NS::SdfPayload const&, PXR_NS::UsdListPosition))
            &PXR_NS::UsdPayloads::AddPayload
        )
        .m((bool (PXR_NS::UsdPayloads::*)(std::string const&, PXR_NS::SdfPath const&, PXR_NS::SdfLayerOffset const&, PXR_NS::UsdListPosition))
            &PXR_NS::UsdPayloads::AddPayload, "AddPayload_with_identifier_and_path"
        )
        .m((bool (PXR_NS::UsdPayloads::*)(std::string const&, PXR_NS::SdfLayerOffset const&, PXR_NS::UsdListPosition))
            &PXR_NS::UsdPayloads::AddPayload, "AddPayload_with_identifier"
        )
        .m(&PXR_NS::UsdPayloads::AddInternalPayload)
        .m(&PXR_NS::UsdPayloads::RemovePayload)
        .m(&PXR_NS::UsdPayloads::ClearPayloads)
        .m(&PXR_NS::UsdPayloads::SetPayloads)
        .m((PXR_NS::UsdPrim const&(PXR_NS::UsdPayloads::*)() const)
            &PXR_NS::UsdPayloads::GetPrim
        )
        .m(&PXR_NS::UsdPayloads::operator bool, "op_bool")
    ;

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


    bbl::Class<PXR_NS::UsdPrimDefinition>("PrimDefinition")
        .m(&PXR_NS::UsdPrimDefinition::GetPropertyNames)
        .m(&PXR_NS::UsdPrimDefinition::GetAppliedAPISchemas)
        .m(&PXR_NS::UsdPrimDefinition::GetPropertyDefinition)
        .m(&PXR_NS::UsdPrimDefinition::GetAttributeDefinition)
        .m(&PXR_NS::UsdPrimDefinition::GetRelationshipDefinition)
        .m(&PXR_NS::UsdPrimDefinition::GetSpecType)
        .m(&PXR_NS::UsdPrimDefinition::GetSchemaPropertySpec)
        .m(&PXR_NS::UsdPrimDefinition::GetSchemaAttributeSpec)
        .m(&PXR_NS::UsdPrimDefinition::GetSchemaRelationshipSpec)
        /// GetAttriutFallbackValue
        .m(&PXR_NS::UsdPrimDefinition::ListMetadataFields)
        // GetMetadata
        // GetMetadataByDictKey
        .m(&PXR_NS::UsdPrimDefinition::GetDocumentation)
        .m(&PXR_NS::UsdPrimDefinition::ListPropertyMetadataFields)
        // GetPropertyMetadata
        // GetPropertyMetadataByDictKey
        .m(&PXR_NS::UsdPrimDefinition::GetPropertyDocumentation)
        .m((bool(PXR_NS::UsdPrimDefinition::*)(PXR_NS::SdfLayerHandle const&, PXR_NS::SdfPath const&, PXR_NS::SdfSpecifier) const) 
            &PXR_NS::UsdPrimDefinition::FlattenTo
        )
        .m((PXR_NS::UsdPrim(PXR_NS::UsdPrimDefinition::*)( PXR_NS::UsdPrim const&, PXR_NS::TfToken const& name, PXR_NS::SdfSpecifier) const) 
            &PXR_NS::UsdPrimDefinition::FlattenTo, "FlattenTo_prim_under_parent"
        )
        .m((PXR_NS::UsdPrim(PXR_NS::UsdPrimDefinition::*)( PXR_NS::UsdPrim const&, PXR_NS::SdfSpecifier) const) 
            &PXR_NS::UsdPrimDefinition::FlattenTo, "FlattenTo_prim"
        )
    ;

    bbl::Class<PXR_NS::UsdPrimDefinition::Property>("PrimDefinitionProperty")
        .ctor(bbl::Class<PXR_NS::UsdPrimDefinition::Property>::Ctor<>(), "default")
        .m(&PXR_NS::UsdPrimDefinition::Property::GetName)
        .m(&PXR_NS::UsdPrimDefinition::Property::operator bool)
        .m(&PXR_NS::UsdPrimDefinition::Property::IsAttribute)
        .m(&PXR_NS::UsdPrimDefinition::Property::IsRelationship)
        .m(&PXR_NS::UsdPrimDefinition::Property::GetSpecType)
        .m(&PXR_NS::UsdPrimDefinition::Property::ListMetadataFields)
        /** TODO: instantiate this template
        .m(&PXR_NS::UsdPrimDefinition::Property::GetMetadata)
        */
        /** TODO: instantiate this template
        .m(&PXR_NS::UsdPrimDefinition::Property::GetMetadataByDictKey)
        */
        .m(&PXR_NS::UsdPrimDefinition::Property::GetVariability)
        .m(&PXR_NS::UsdPrimDefinition::Property::GetDocumentation)
    ;

    bbl::Class<PXR_NS::UsdPrimDefinition::Attribute>("PrimDefinitionAttribute")
        .ctor(bbl::Class<PXR_NS::UsdPrimDefinition::Attribute>::Ctor<>(), "default")
        .m(&PXR_NS::UsdPrimDefinition::Attribute::GetTypeName)
        .m(&PXR_NS::UsdPrimDefinition::Attribute::GetTypeNameToken)
        /** TODO: instantiate this template
        .m(&PXR_NS::UsdPrimDefinition::Attribute::GetFallbackValue)
        */
    ;

    bbl::Class<PXR_NS::UsdPrimDefinition::Relationship>("PrimDefinitionRelationship")
        .ctor(bbl::Class<PXR_NS::UsdPrimDefinition::Relationship>::Ctor<>(), "default")
    ;

    bbl::Class<PXR_NS::UsdPrimRange>("PrimRange")
        .opaque_ptr()
        .ctor(bbl::Class<PXR_NS::UsdPrimRange>::Ctor<PXR_NS::UsdPrim>("start"), "from_prim")
        .m(&PXR_NS::UsdPrimRange::begin)
        .m(&PXR_NS::UsdPrimRange::end);

    bbl::Class<PXR_NS::UsdPrimRange::iterator>("PrimRangeIterator")
        .opaque_ptr()
        .ctor(bbl::Class<PXR_NS::UsdPrimRange::iterator>::Ctor<>(), "new")
#if PXR_VERSION <= 2308
        .m(&PXR_NS::UsdPrimRange::iterator::operator++, "op_inc")
#else
        .m((PXR_NS::UsdPrimRange::iterator & (PXR_NS::UsdPrimRange::iterator::*)())
            &PXR_NS::UsdPrimRange::iterator::operator++, "op_inc"
        )
#endif
        .m((PXR_NS::UsdPrimRange::iterator & (PXR_NS::UsdPrimRange::iterator::*)(PXR_NS::UsdPrimRange::iterator const&))
            &PXR_NS::UsdPrimRange::iterator::operator=, "op_assign"
        )
        .m((bool(PXR_NS::UsdPrimRange::iterator::*)(PXR_NS::UsdPrimRange::iterator const&) const) 
            &PXR_NS::UsdPrimRange::iterator::operator==, "op_eq"
        )
        .m(&PXR_NS::UsdPrimRange::iterator::operator*, "deref");

    bbl::Class<PXR_NS::UsdPrimSiblingRange>("PrimSiblingRange")
        .m(&PXR_NS::UsdPrimSiblingRange::begin)
        .m(&PXR_NS::UsdPrimSiblingRange::end)
    ;

    bbl::Class<PXR_NS::UsdPrimSiblingIterator>("PrimSiblingIterator")
        .m(&PXR_NS::UsdPrimSiblingIterator::operator*, "deref")
    #if PXR_VERSION <= 2308
        .m(&PXR_NS::UsdPrimSiblingIterator::operator++, "op_inc")
#else
        .m((PXR_NS::UsdPrimSiblingIterator & (PXR_NS::UsdPrimSiblingIterator::*)())
            &PXR_NS::UsdPrimSiblingIterator::operator++, "op_inc"
        )
#endif
    ;

    bbl::fn(&bblext::PrimSiblingIterator_op_eq);

    bbl::Class<PXR_NS::UsdPrimSubtreeRange>("PrimSubtreeRange")
    ;

    bbl::Class<PXR_NS::UsdReferences>("References")
        .m((bool (PXR_NS::UsdReferences::*)(PXR_NS::SdfReference const&, PXR_NS::UsdListPosition))
            &PXR_NS::UsdReferences::AddReference
        )
        .m((bool (PXR_NS::UsdReferences::*)(std::string const&, PXR_NS::SdfPath const&, PXR_NS::SdfLayerOffset const&, PXR_NS::UsdListPosition))
            &PXR_NS::UsdReferences::AddReference, "AddReference_with_identifier_and_path"
        )
        .m((bool (PXR_NS::UsdReferences::*)(std::string const&, PXR_NS::SdfLayerOffset const&, PXR_NS::UsdListPosition))
            &PXR_NS::UsdReferences::AddReference, "AddReference_with_identifier"
        )
        .m(&PXR_NS::UsdReferences::AddInternalReference)
        .m(&PXR_NS::UsdReferences::RemoveReference)
        .m(&PXR_NS::UsdReferences::ClearReferences)
        .m(&PXR_NS::UsdReferences::SetReferences)
        .m((PXR_NS::UsdPrim const& (PXR_NS::UsdReferences::*)() const)
            &PXR_NS::UsdReferences::GetPrim
        )
        .m(&PXR_NS::UsdReferences::operator bool)
    ;

    bbl::Class<PXR_NS::UsdResolveInfo>("ResolveInfo")
        .ctor(bbl::Class<PXR_NS::UsdResolveInfo>::Ctor<>(), "default")
        .m(&PXR_NS::UsdResolveInfo::GetSource)
        .m(&PXR_NS::UsdResolveInfo::HasAuthoredValueOpinion)
        .m(&PXR_NS::UsdResolveInfo::HasAuthoredValue)
        .m(&PXR_NS::UsdResolveInfo::GetNode)
        .m(&PXR_NS::UsdResolveInfo::ValueIsBlocked)
    ;

    bbl::Enum<PXR_NS::UsdResolveInfoSource>("ResolveInfoSource");

    bbl::Class<PXR_NS::UsdResolveTarget>("ResolveTarget")
        .ctor(bbl::Class<PXR_NS::UsdResolveTarget>::Ctor<>(), "default")
        .m(&PXR_NS::UsdResolveTarget::GetPrimIndex)
        .m(&PXR_NS::UsdResolveTarget::GetStartNode)
        .m(&PXR_NS::UsdResolveTarget::GetStartLayer)
        .m(&PXR_NS::UsdResolveTarget::GetStopNode)
        .m(&PXR_NS::UsdResolveTarget::GetStopLayer)
        .m(&PXR_NS::UsdResolveTarget::IsNull)
    ;

    bbl::Class<PXR_NS::UsdAPISchemaBase>("APISchemaBase")
        .m(&PXR_NS::UsdAPISchemaBase::GetSchemaAttributeNames)
    ;

    bbl::Class<PXR_NS::UsdSchemaBase>("SchemaBase")
        .ctor(bbl::Class<PXR_NS::UsdSchemaBase>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .m(&PXR_NS::UsdSchemaBase::IsConcrete)
        .m(&PXR_NS::UsdSchemaBase::IsTyped)
        .m(&PXR_NS::UsdSchemaBase::IsAPISchema)
        .m(&PXR_NS::UsdSchemaBase::IsAppliedAPISchema)
        .m(&PXR_NS::UsdSchemaBase::IsMultipleApplyAPISchema)
        .m(&PXR_NS::UsdSchemaBase::GetSchemaKind)
        .m(&PXR_NS::UsdSchemaBase::GetPrim)
        .m(&PXR_NS::UsdSchemaBase::GetPath)
        .m(&PXR_NS::UsdSchemaBase::GetSchemaClassPrimDefinition)
        .m(&PXR_NS::UsdSchemaBase::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdSchemaBase::operator bool)
    ;

    bbl::Class<PXR_NS::UsdSchemaRegistry>("SchemaRegistry")
        .m(&PXR_NS::UsdSchemaRegistry::GetInstance)
        .m(&PXR_NS::UsdSchemaRegistry::MakeSchemaIdentifierForFamilyAndVersion)
        .m(&PXR_NS::UsdSchemaRegistry::ParseSchemaFamilyAndVersionFromIdentifier)
        .m(&PXR_NS::UsdSchemaRegistry::IsAllowedSchemaFamily)
        .m(&PXR_NS::UsdSchemaRegistry::IsAllowedSchemaIdentifier)
        .m((const PXR_NS::UsdSchemaRegistry::SchemaInfo * (*)(const PXR_NS::TfType &))
            &PXR_NS::UsdSchemaRegistry::FindSchemaInfo, "FindSchemaInfo"
        )
        /** TODO: instantiate this template
        .m((const PXR_NS::UsdSchemaRegistry::SchemaInfo * (*)())
            &PXR_NS::UsdSchemaRegistry::FindSchemaInfo, "FindSchemaInfo_01")
        */
        .m((const PXR_NS::UsdSchemaRegistry::SchemaInfo * (*)(const PXR_NS::TfToken &))
            &PXR_NS::UsdSchemaRegistry::FindSchemaInfo, "FindSchemaInfo_by_name"
        )
        .m((const PXR_NS::UsdSchemaRegistry::SchemaInfo * (*)(const PXR_NS::TfToken &, PXR_NS::UsdSchemaVersion))
            &PXR_NS::UsdSchemaRegistry::FindSchemaInfo, "FindSchemaInfo_03"
        )
        .m((const std::vector<const PXR_NS::UsdSchemaRegistry::SchemaInfo *> & (*)(const PXR_NS::TfToken &))
            &PXR_NS::UsdSchemaRegistry::FindSchemaInfosInFamily, "FindSchemaInfosInFamily_00"
        )
        .m((std::vector<const PXR_NS::UsdSchemaRegistry::SchemaInfo *> (*)(const PXR_NS::TfToken &, PXR_NS::UsdSchemaVersion, PXR_NS::UsdSchemaRegistry::VersionPolicy))
            &PXR_NS::UsdSchemaRegistry::FindSchemaInfosInFamily, "FindSchemaInfosInFamily_01"
        )
        .m((PXR_NS::TfToken (*)(const PXR_NS::TfType &))
            &PXR_NS::UsdSchemaRegistry::GetSchemaTypeName, "GetSchemaTypeName")
        /** TODO: instantiate this template
        .m((PXR_NS::TfToken (*)())
            &PXR_NS::UsdSchemaRegistry::GetSchemaTypeName, "GetSchemaTypeName_01")
        */
        .m(&PXR_NS::UsdSchemaRegistry::GetConcreteSchemaTypeName)
        .m(&PXR_NS::UsdSchemaRegistry::GetAPISchemaTypeName)
        .m(&PXR_NS::UsdSchemaRegistry::GetTypeFromSchemaTypeName)
        .m(&PXR_NS::UsdSchemaRegistry::GetConcreteTypeFromSchemaTypeName)
        .m(&PXR_NS::UsdSchemaRegistry::GetAPITypeFromSchemaTypeName)
        .m(&PXR_NS::UsdSchemaRegistry::IsDisallowedField)
        .m(&PXR_NS::UsdSchemaRegistry::IsTyped)
        .m((PXR_NS::UsdSchemaKind (*)(const PXR_NS::TfType &))
            &PXR_NS::UsdSchemaRegistry::GetSchemaKind, "GetSchemaKind_00"
        )
        .m((PXR_NS::UsdSchemaKind (*)(const PXR_NS::TfToken &))
            &PXR_NS::UsdSchemaRegistry::GetSchemaKind, "GetSchemaKind_01"
        )
        .m((bool (*)(const PXR_NS::TfType &))
            &PXR_NS::UsdSchemaRegistry::IsConcrete, "IsConcrete"
        )
        .m((bool (*)(const PXR_NS::TfToken &))
            &PXR_NS::UsdSchemaRegistry::IsConcrete, "IsConcrete_by_name"
        )
        .m((bool (*)(const PXR_NS::TfType &))
            &PXR_NS::UsdSchemaRegistry::IsAbstract, "IsAbstract"
        )
        .m((bool (*)(const PXR_NS::TfToken &))
            &PXR_NS::UsdSchemaRegistry::IsAbstract, "IsAbstract_by_name"
        )
        .m((bool (*)(const PXR_NS::TfType &))
            &PXR_NS::UsdSchemaRegistry::IsAppliedAPISchema, "IsAppliedAPISchema"
        )
        .m((bool (*)(const PXR_NS::TfToken &))
            &PXR_NS::UsdSchemaRegistry::IsAppliedAPISchema, "IsAppliedAPISchema_by_name"
        )
        .m((bool (*)(const PXR_NS::TfType &))
            &PXR_NS::UsdSchemaRegistry::IsMultipleApplyAPISchema, "IsMultipleApplyAPISchema"
        )
        .m((bool (*)(const PXR_NS::TfToken &))
            &PXR_NS::UsdSchemaRegistry::IsMultipleApplyAPISchema, "IsMultipleApplyAPISchema_by_name"
        )
        .m(&PXR_NS::UsdSchemaRegistry::GetTypeFromName)
        .m(&PXR_NS::UsdSchemaRegistry::GetTypeNameAndInstance)
        .m(&PXR_NS::UsdSchemaRegistry::IsAllowedAPISchemaInstanceName)
        .m(&PXR_NS::UsdSchemaRegistry::GetAPISchemaCanOnlyApplyToTypeNames)
        .m(&PXR_NS::UsdSchemaRegistry::GetAutoApplyAPISchemas)
        .m(&PXR_NS::UsdSchemaRegistry::CollectAddtionalAutoApplyAPISchemasFromPlugins)
        .m(&PXR_NS::UsdSchemaRegistry::MakeMultipleApplyNameTemplate)
        .m(&PXR_NS::UsdSchemaRegistry::MakeMultipleApplyNameInstance)
        .m(&PXR_NS::UsdSchemaRegistry::GetMultipleApplyNameTemplateBaseName)
        .m(&PXR_NS::UsdSchemaRegistry::IsMultipleApplyNameTemplate)
        .m(&PXR_NS::UsdSchemaRegistry::FindConcretePrimDefinition)
        .m(&PXR_NS::UsdSchemaRegistry::FindAppliedAPIPrimDefinition)
        .m(&PXR_NS::UsdSchemaRegistry::GetEmptyPrimDefinition)
        .m(&PXR_NS::UsdSchemaRegistry::BuildComposedPrimDefinition)
        .m(&PXR_NS::UsdSchemaRegistry::GetFallbackPrimTypes)
    ;

    bbl::Class<PXR_NS::UsdSchemaRegistry::SchemaInfo>("SchemaRegistrySchemaInfo")
    ;

    bbl::Class<std::vector<PXR_NS::UsdSchemaRegistry::SchemaInfo const*>>("SchemaRegistrySchemaInfoConstPtrVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdSchemaRegistry::SchemaInfo const*)
    ;

    bbl::fn(&bblext::UsdSchemaRegistrySchemaInfo_identifier);
    bbl::fn(&bblext::UsdSchemaRegistrySchemaInfo_type);
    bbl::fn(&bblext::UsdSchemaRegistrySchemaInfo_family);
    bbl::fn(&bblext::UsdSchemaRegistrySchemaInfo_version);
    bbl::fn(&bblext::UsdSchemaRegistrySchemaInfo_kind);

    bbl::Enum<PXR_NS::UsdSchemaRegistry::VersionPolicy>("SchemaRegistryVersionPolicy");

    bbl::Class<std::pair<PXR_NS::TfToken, PXR_NS::UsdSchemaVersion>>("TokenSchemaVersionPair")
    ;

    bbl::Class<PXR_NS::UsdSchemaRegistry::TokenToTokenVectorMap>("SchemaRegistryTokenToTokenVectorMap")
    ;

    bbl::Class<std::unique_ptr<PXR_NS::UsdPrimDefinition>>("PrimDefinitionPtr")
        .smartptr_to<PXR_NS::UsdPrimDefinition>()
    ;

    bbl::Class<PXR_NS::UsdSpecializes>("Specializes")
        .m(&PXR_NS::UsdSpecializes::AddSpecialize)
        .m(&PXR_NS::UsdSpecializes::RemoveSpecialize)
        .m(&PXR_NS::UsdSpecializes::ClearSpecializes)
        .m(&PXR_NS::UsdSpecializes::SetSpecializes)
        .m((PXR_NS::UsdPrim const& (PXR_NS::UsdSpecializes::*)() const)
            &PXR_NS::UsdSpecializes::GetPrim
        )
        .m(&PXR_NS::UsdSpecializes::operator bool, "op_bool")
    ;

    bbl::Class<PXR_NS::UsdStage>("Stage")
        // Layer Serialization
        .m(&PXR_NS::UsdStage::Save)
        .m(&PXR_NS::UsdStage::SaveSessionLayers)

        // Working Set Management
        .m(&PXR_NS::UsdStage::Load)
        .m(&PXR_NS::UsdStage::Unload)
        .m(&PXR_NS::UsdStage::LoadAndUnload)
        .m(&PXR_NS::UsdStage::GetLoadSet)
        .m(&PXR_NS::UsdStage::FindLoadable)
        .m(&PXR_NS::UsdStage::GetLoadRules)
        .m(&PXR_NS::UsdStage::SetLoadRules)
        .m(&PXR_NS::UsdStage::GetPopulationMask)
        .m(&PXR_NS::UsdStage::SetPopulationMask)
        .m(&PXR_NS::UsdStage::ExpandPopulationMask) 

        // Layers and Edit Targets
        .m(&PXR_NS::UsdStage::GetSessionLayer)
        .m(&PXR_NS::UsdStage::GetRootLayer)
        .m(&PXR_NS::UsdStage::GetPathResolverContext)
        .m(&PXR_NS::UsdStage::ResolveIdentifierToEditTarget)
        .m(&PXR_NS::UsdStage::GetLayerStack)
        .m(&PXR_NS::UsdStage::GetUsedLayers)
        .m(&PXR_NS::UsdStage::HasLocalLayer)
        .m(&PXR_NS::UsdStage::GetEditTarget)
        .m((PXR_NS::UsdEditTarget(PXR_NS::UsdStage::*)(PXR_NS::SdfLayerHandle const&))
            &PXR_NS::UsdStage::GetEditTargetForLocalLayer
        )
        .m((PXR_NS::UsdEditTarget(PXR_NS::UsdStage::*)(size_t))
            &PXR_NS::UsdStage::GetEditTargetForLocalLayer, "GetEditTargetForLocalLayer_with_index"
        )
        .m(&PXR_NS::UsdStage::SetEditTarget)
        .m(&PXR_NS::UsdStage::MuteLayer)
        .m(&PXR_NS::UsdStage::UnmuteLayer)
        .m(&PXR_NS::UsdStage::MuteAndUnmuteLayers)
        .m(&PXR_NS::UsdStage::GetMutedLayers)
        .m(&PXR_NS::UsdStage::IsLayerMuted)

        // Flatten & Export Utilities
        .m(&PXR_NS::UsdStage::Export)
        .m(&PXR_NS::UsdStage::Flatten)

        // PXR_NS::UsdStage Metadata
        .m((bool (PXR_NS::UsdStage::*)(PXR_NS::TfToken const&, PXR_NS::VtValue*) const)
            &PXR_NS::UsdStage::GetMetadata
        )
        .m(&PXR_NS::UsdStage::HasMetadata)
        .m(&PXR_NS::UsdStage::HasAuthoredMetadata)
        .m((bool (PXR_NS::UsdStage::*)(PXR_NS::TfToken const&, PXR_NS::VtValue const&) const)
            &PXR_NS::UsdStage::SetMetadata
        )
        .m(&PXR_NS::UsdStage::ClearMetadata)
        .m((bool (PXR_NS::UsdStage::*)(PXR_NS::TfToken const&, PXR_NS::TfToken const&, PXR_NS::VtValue*) const)
            &PXR_NS::UsdStage::GetMetadataByDictKey
        )
        .m(&PXR_NS::UsdStage::HasMetadataDictKey)
        .m(&PXR_NS::UsdStage::HasAuthoredMetadataDictKey)
        .m((bool (PXR_NS::UsdStage::*)(PXR_NS::TfToken const&, PXR_NS::TfToken const&, PXR_NS::VtValue const&) const)
            &PXR_NS::UsdStage::SetMetadataByDictKey
        )
        .m(&PXR_NS::UsdStage::ClearMetadataByDictKey)
        .m(&PXR_NS::UsdStage::WriteFallbackPrimTypes)

        // TimeCode API
        .m(&PXR_NS::UsdStage::GetStartTimeCode)
        .m(&PXR_NS::UsdStage::SetStartTimeCode)
        .m(&PXR_NS::UsdStage::GetEndTimeCode)
        .m(&PXR_NS::UsdStage::SetEndTimeCode)
        .m(&PXR_NS::UsdStage::HasAuthoredTimeCodeRange)
        .m(&PXR_NS::UsdStage::GetTimeCodesPerSecond)
        .m(&PXR_NS::UsdStage::SetTimeCodesPerSecond)
        .m(&PXR_NS::UsdStage::GetFramesPerSecond)
        .m(&PXR_NS::UsdStage::SetFramesPerSecond)

        // Attribute value Interpolation
        .m(&PXR_NS::UsdStage::SetInterpolationType)
        .m(&PXR_NS::UsdStage::GetInterpolationType)

        // Instancing
        .m(&PXR_NS::UsdStage::GetPrototypes)

        // Variant Management
        .m(&PXR_NS::UsdStage::GetGlobalVariantFallbacks)
        .m(&PXR_NS::UsdStage::SetGlobalVariantFallbacks)

        // Lifetime Management
        .m((PXR_NS::UsdStageRefPtr(*)(std::string const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::CreateNew
        )
        .m((PXR_NS::UsdStageRefPtr(*)(std::string const&, PXR_NS::SdfLayerHandle const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::CreateNew, "CreateNew_with_session_layer"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(std::string const&, PXR_NS::SdfLayerHandle const&, PXR_NS::ArResolverContext const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::CreateNew, "CreateNew_with_session_layer_and_resolver_context"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(std::string const&, PXR_NS::ArResolverContext const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::CreateNew, "CreateNew_with_resolver_context"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::CreateInMemory
        )
        .m((PXR_NS::UsdStageRefPtr(*)(std::string const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::CreateInMemory, "CreateInMemory_with_identifier"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(std::string const&, PXR_NS::ArResolverContext const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::CreateInMemory, "CreateInMemory_with_resolver_context"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(std::string const&, PXR_NS::SdfLayerHandle const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::CreateInMemory, "CreateInMemory_with_session_layer"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(std::string const&, PXR_NS::SdfLayerHandle const&, PXR_NS::ArResolverContext const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::CreateInMemory, "CreateInMemory_with_session_layer_and_resolver_context"
        )
        // we'll override this to take a char* instead
        // .m((PXR_NS::UsdStageRefPtr(*)(std::string const&, PXR_NS::UsdStage::InitialLoadSet))
        //     &PXR_NS::UsdStage::Open
        // )
        .m((PXR_NS::UsdStageRefPtr(*)(std::string const&, PXR_NS::ArResolverContext const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::Open, "Open_with_resolver_context"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(PXR_NS::SdfLayerHandle const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::Open, "Open_at_root"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(PXR_NS::SdfLayerHandle const&, PXR_NS::ArResolverContext const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::Open, "Open_at_root_with_resolver_context"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(PXR_NS::SdfLayerHandle const&, PXR_NS::SdfLayerHandle const&, PXR_NS::ArResolverContext const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::Open, "Open_at_root_with_session_layer_and_resolver_context"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(PXR_NS::SdfLayerHandle const&, PXR_NS::SdfLayerHandle const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::Open, "Open_at_root_with_session_layer"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(std::string const&, PXR_NS::UsdStagePopulationMask const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::OpenMasked
        )
        .m((PXR_NS::UsdStageRefPtr(*)(std::string const&, PXR_NS::ArResolverContext const&, PXR_NS::UsdStagePopulationMask const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::OpenMasked, "OpenMasked_with_resolver_context"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(PXR_NS::SdfLayerHandle const&, PXR_NS::UsdStagePopulationMask const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::OpenMasked, "OpenMasked_at_root"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(PXR_NS::SdfLayerHandle const&, PXR_NS::ArResolverContext const&, PXR_NS::UsdStagePopulationMask const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::OpenMasked, "OpenMasked_at_root_with_resolver_context"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(PXR_NS::SdfLayerHandle const&, PXR_NS::SdfLayerHandle const&, PXR_NS::ArResolverContext const&, PXR_NS::UsdStagePopulationMask const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::OpenMasked, "OpenMasked_at_root_with_session_layer_and_resolver_context"
        )
        .m((PXR_NS::UsdStageRefPtr(*)(PXR_NS::SdfLayerHandle const&, PXR_NS::SdfLayerHandle const&, PXR_NS::UsdStagePopulationMask const&, PXR_NS::UsdStage::InitialLoadSet))
            &PXR_NS::UsdStage::OpenMasked, "OpenMasked_at_root_with_session_layer"
        )
        .m(&PXR_NS::UsdStage::IsSupportedFile)
        .m(&PXR_NS::UsdStage::Reload)

        // Color Configuration API
        .m(&PXR_NS::UsdStage::GetColorConfigFallbacks)
        .m(&PXR_NS::UsdStage::SetColorConfigFallbacks)
        .m(&PXR_NS::UsdStage::SetColorConfiguration)
        .m(&PXR_NS::UsdStage::GetColorConfiguration)
        .m(&PXR_NS::UsdStage::SetColorManagementSystem)
        .m(&PXR_NS::UsdStage::GetColorManagementSystem)

        // Prim Access, Creation and Mutation
        .m(&PXR_NS::UsdStage::GetPseudoRoot)
        .m(&PXR_NS::UsdStage::GetDefaultPrim)
        .m(&PXR_NS::UsdStage::SetDefaultPrim)
        .m(&PXR_NS::UsdStage::ClearDefaultPrim)
        .m(&PXR_NS::UsdStage::HasDefaultPrim)
        .m(&PXR_NS::UsdStage::GetPrimAtPath)
        .m(&PXR_NS::UsdStage::GetObjectAtPath)
        .m(&PXR_NS::UsdStage::GetPropertyAtPath)
        .m(&PXR_NS::UsdStage::GetAttributeAtPath)
        .m(&PXR_NS::UsdStage::GetRelationshipAtPath)
        // Cannot bind Traverse because it returns a PrimRange by value and PrimRange has no default constructor
        // Could possibly work around this by defining one ourselves that just zeroed the memory...
        .m(&PXR_NS::UsdStage::OverridePrim)
        .m(&PXR_NS::UsdStage::DefinePrim)
        .m(&PXR_NS::UsdStage::CreateClassPrim)
        .m(&PXR_NS::UsdStage::RemovePrim)
        ;

    bbl::fn(&bblext::Stage_Open);
    bbl::fn(&bblext::StageRefPtr_ExportToString);

    bbl::Enum<PXR_NS::UsdStage::InitialLoadSet>("StageInitialLoadSet");

    bbl::Class<PXR_NS::UsdStageRefPtr>("StageRefPtr")
        .ctor(bbl::Class<PXR_NS::UsdStageRefPtr>::Ctor<>(), "ctor")
        .smartptr_to<PXR_NS::UsdStage>()
        .m(&PXR_NS::UsdStageRefPtr::operator->, "get")
        .m(&PXR_NS::UsdStageRefPtr::operator!, "is_invalid")
    ;


    bbl::Class<PXR_NS::UsdStageRefPtrVector>("StageRefPtrVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdStageRefPtr)
    ;

    bbl::Class<PXR_NS::UsdStageWeakPtr>("StageWeakPtr")
        .ctor(bbl::Class<PXR_NS::UsdStageWeakPtr>::Ctor<>(), "ctor")
        .m(&PXR_NS::UsdStageWeakPtr::operator->, "get")
        .m(&PXR_NS::UsdStageWeakPtr::operator!, "is_invalid")
    ;

    bbl::Class<PXR_NS::UsdStageCache>("StageCache")
        .ctor(bbl::Class<PXR_NS::UsdStageCache>::Ctor<>(), "default")
        .m(&PXR_NS::UsdStageCache::GetAllStages)
        .m(&PXR_NS::UsdStageCache::Size)
        .m(&PXR_NS::UsdStageCache::IsEmpty)
        .m(&PXR_NS::UsdStageCache::Find)
        .m((PXR_NS::UsdStageRefPtr (PXR_NS::UsdStageCache::*)(PXR_NS::SdfLayerHandle const&) const)
            &PXR_NS::UsdStageCache::FindOneMatching, "FindOneMatching_with_root_layer"
        )
        .m((PXR_NS::UsdStageRefPtr (PXR_NS::UsdStageCache::*)(PXR_NS::SdfLayerHandle const&, PXR_NS::SdfLayerHandle const&) const)
            &PXR_NS::UsdStageCache::FindOneMatching, "FindOneMatching_with_root_and_session_layer"
        )
        .m((PXR_NS::UsdStageRefPtr (PXR_NS::UsdStageCache::*)(PXR_NS::SdfLayerHandle const&, PXR_NS::ArResolverContext const&) const)
            &PXR_NS::UsdStageCache::FindOneMatching, "FindOneMatching_with_root_layer_and_resolver"
        )
        .m((PXR_NS::UsdStageRefPtr (PXR_NS::UsdStageCache::*)(PXR_NS::SdfLayerHandle const&, PXR_NS::SdfLayerHandle const&, PXR_NS::ArResolverContext const&) const)
            &PXR_NS::UsdStageCache::FindOneMatching, "FindOneMatching_with_root_and_session_layer_and_resolver"
        )
        .m((PXR_NS::UsdStageRefPtrVector (PXR_NS::UsdStageCache::*)(PXR_NS::SdfLayerHandle const&) const)
            &PXR_NS::UsdStageCache::FindAllMatching, "FindAllMatching_with_root_layer"
        )
        .m((PXR_NS::UsdStageRefPtrVector (PXR_NS::UsdStageCache::*)(PXR_NS::SdfLayerHandle const&, PXR_NS::SdfLayerHandle const&) const)
            &PXR_NS::UsdStageCache::FindAllMatching, "FindAllMatching_with_root_and_session_layer"
        )
        .m((PXR_NS::UsdStageRefPtrVector (PXR_NS::UsdStageCache::*)(PXR_NS::SdfLayerHandle const&, PXR_NS::ArResolverContext const&) const)
            &PXR_NS::UsdStageCache::FindAllMatching, "FindAllMatching_with_root_layer_and_resolver"
        )
        .m((PXR_NS::UsdStageRefPtrVector (PXR_NS::UsdStageCache::*)(PXR_NS::SdfLayerHandle const&, PXR_NS::SdfLayerHandle const&, PXR_NS::ArResolverContext const&) const)
            &PXR_NS::UsdStageCache::FindAllMatching, "FindAllMatching_with_root_and_session_layer_and_resolver"
        )
        .m(&PXR_NS::UsdStageCache::GetId)
        .m((bool (PXR_NS::UsdStageCache::*)(PXR_NS::UsdStageRefPtr const&) const)
            &PXR_NS::UsdStageCache::Contains
        )
        .m((bool (PXR_NS::UsdStageCache::*)(PXR_NS::UsdStageCache::Id) const)
            &PXR_NS::UsdStageCache::Contains, "Contains_id"
        )
        .m(&PXR_NS::UsdStageCache::Insert)
        .m((bool (PXR_NS::UsdStageCache::*)(PXR_NS::UsdStageRefPtr const&))
            &PXR_NS::UsdStageCache::Erase
        )
        .m((bool (PXR_NS::UsdStageCache::*)(PXR_NS::UsdStageCache::Id))
            &PXR_NS::UsdStageCache::Erase, "Erase_id"
        )
        .m((size_t (PXR_NS::UsdStageCache::*)(PXR_NS::SdfLayerHandle const&))
            &PXR_NS::UsdStageCache::EraseAll, "EraseAll_with_root_layer"
        )
        .m((size_t (PXR_NS::UsdStageCache::*)(PXR_NS::SdfLayerHandle const&, PXR_NS::SdfLayerHandle const&))
            &PXR_NS::UsdStageCache::EraseAll, "EraseAll_with_root_and_session_layer"
        )
        .m((size_t (PXR_NS::UsdStageCache::*)(PXR_NS::SdfLayerHandle const&, PXR_NS::SdfLayerHandle const&, PXR_NS::ArResolverContext const&))
            &PXR_NS::UsdStageCache::EraseAll, "EraseAll_with_root_and_session_layer_and_resolver"
        )
        .m(&PXR_NS::UsdStageCache::Clear)
        .m(&PXR_NS::UsdStageCache::SetDebugName)
        .m(&PXR_NS::UsdStageCache::GetDebugName)
        ;

    bbl::Class<PXR_NS::UsdStageCache::Id>("StageCacheId")
        .m(&PXR_NS::UsdStageCache::Id::ToLongInt)
        .m(&PXR_NS::UsdStageCache::Id::ToString)
        .m(&PXR_NS::UsdStageCache::Id::IsValid)
        .m(&PXR_NS::UsdStageCache::Id::FromLongInt)
        .m(&PXR_NS::UsdStageCache::Id::FromString)
        ;

    bbl::Class<PXR_NS::UsdStageCacheRequest>()
        .m((bool (PXR_NS::UsdStageCacheRequest::*)(const PXR_NS::UsdStageRefPtr &) const)
            &PXR_NS::UsdStageCacheRequest::IsSatisfiedBy, "IsSatisfiedBy_stage")
        .m((bool (PXR_NS::UsdStageCacheRequest::*)(const PXR_NS::UsdStageCacheRequest &) const)
            &PXR_NS::UsdStageCacheRequest::IsSatisfiedBy, "IsSatisfiedBy_cache_request")
        .m(&PXR_NS::UsdStageCacheRequest::Manufacture)
    ;

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

