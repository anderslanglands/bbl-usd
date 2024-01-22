#if defined(__clang__)

#include "babble"
#include "babble-std"

#include <pxr/usd/pcp/arc.h>
#include <pxr/usd/pcp/cache.h>
#include <pxr/usd/pcp/changes.h>
#include <pxr/usd/pcp/dependency.h>
#include <pxr/usd/pcp/dynamicFileFormatContext.h>
#include <pxr/usd/pcp/dynamicFileFormatDependencyData.h>
#include <pxr/usd/pcp/dynamicFileFormatInterface.h>
#include <pxr/usd/pcp/expressionVariables.h>
#include <pxr/usd/pcp/expressionVariablesDependencyData.h>
#include <pxr/usd/pcp/instanceKey.h>
#include <pxr/usd/pcp/iterator.h>
#include <pxr/usd/pcp/layerStack.h>
#include <pxr/usd/pcp/layerStackIdentifier.h>
#include <pxr/usd/pcp/mapExpression.h>
#include <pxr/usd/pcp/mapFunction.h>
#include <pxr/usd/pcp/namespaceEdits.h>
#include <pxr/usd/pcp/node.h>
#include <pxr/usd/pcp/primIndex.h>
#include <pxr/usd/pcp/propertyIndex.h>
#include <pxr/usd/pcp/site.h>
#include <pxr/usd/pcp/targetIndex.h>
#include <pxr/usd/pcp/types.h>

namespace bblext {

PXR_NS::PcpArcType Arc_get_type(PXR_NS::PcpArc const& arc) {
    return arc.type;
}

PXR_NS::PcpNodeRef Arc_get_parent(PXR_NS::PcpArc const& arc) {
    return arc.parent;
}

PXR_NS::PcpNodeRef Arc_get_origin(PXR_NS::PcpArc const& arc) {
    return arc.origin;
}

PXR_NS::PcpMapExpression const& Arc_get_map_to_parent(PXR_NS::PcpArc const& arc) {
    return arc.mapToParent;
}

int Arc_get_sibling_num_at_origin(PXR_NS::PcpArc const& arc) {
    return arc.siblingNumAtOrigin;
}

int Arc_get_namespace_depth(PXR_NS::PcpArc const& arc) {
    return arc.namespaceDepth;
}


}

BBL_MODULE(pcp) {

    // clang-format off

    bbl::Class<PXR_NS::PcpArc>("Arc")
        .ctor(bbl::Class<PXR_NS::PcpArc>::Ctor<>(), "default")
    ;

    bbl::fn(&bblext::Arc_get_type, "Arc_get_type");
    bbl::fn(&bblext::Arc_get_parent, "Arc_get_parent");
    bbl::fn(&bblext::Arc_get_origin, "Arc_get_origin");
    bbl::fn(&bblext::Arc_get_map_to_parent, "Arc_get_map_to_parent");
    bbl::fn(&bblext::Arc_get_sibling_num_at_origin, "Arc_get_sibling_num_at_origin");
    bbl::fn(&bblext::Arc_get_namespace_depth, "Arc_get_namespace_depth");

    bbl::Enum<PXR_NS::PcpArcType>("ArcType");

    bbl::Class<PXR_NS::PcpCache>("Cache")
        .ctor(bbl::Class<PXR_NS::PcpCache>::Ctor<const PXR_NS::PcpLayerStackIdentifier &, const std::string &, bool>("layerStackIdentifier", "fileFormatTarget", "usd"), "ctor_00")
        .m(&PXR_NS::PcpCache::GetLayerStackIdentifier)
        .m(&PXR_NS::PcpCache::GetLayerStack)
        .m((bool (PXR_NS::PcpCache::*)(const PXR_NS::PcpLayerStackRefPtr &) const)
            &PXR_NS::PcpCache::HasRootLayerStack, "HasRootLayerStack_00")
        .m((bool (PXR_NS::PcpCache::*)(const PXR_NS::PcpLayerStackPtr &) const)
            &PXR_NS::PcpCache::HasRootLayerStack, "HasRootLayerStack_01")
        .m(&PXR_NS::PcpCache::IsUsd)
        .m(&PXR_NS::PcpCache::GetFileFormatTarget)
        .m(&PXR_NS::PcpCache::GetVariantFallbacks)
        .m(&PXR_NS::PcpCache::SetVariantFallbacks)
        .m(&PXR_NS::PcpCache::IsPayloadIncluded)
        .m(&PXR_NS::PcpCache::GetIncludedPayloads)
        .m(&PXR_NS::PcpCache::RequestPayloads)
        .m(&PXR_NS::PcpCache::RequestLayerMuting)
        .m(&PXR_NS::PcpCache::GetMutedLayers)
        .m((bool (PXR_NS::PcpCache::*)(const std::string &) const)
            &PXR_NS::PcpCache::IsLayerMuted, "IsLayerMuted_00")
        .m((bool (PXR_NS::PcpCache::*)(const PXR_NS::SdfLayerHandle &, const std::string &, std::string *) const)
            &PXR_NS::PcpCache::IsLayerMuted, "IsLayerMuted_01")
        .m(&PXR_NS::PcpCache::GetPrimIndexInputs)
        .m(&PXR_NS::PcpCache::ComputeLayerStack)
        .m(&PXR_NS::PcpCache::FindLayerStack)
        .m(&PXR_NS::PcpCache::UsesLayerStack)
        .m(&PXR_NS::PcpCache::ComputePrimIndex)
        /** TODO: instantiate this template
        .m((void (PXR_NS::PcpCache::*)(const SdfPath &, PcpErrorVector *, const ChildrenPredicate &, const PayloadPredicate &))
            &PXR_NS::PcpCache::ComputePrimIndexesInParallel, "ComputePrimIndexesInParallel_00")
        */
        /** TODO: instantiate this template
        .m((void (PXR_NS::PcpCache::*)(const SdfPath &, PcpErrorVector *, const ChildrenPredicate &, const PayloadPredicate &, const char *, const char *))
            &PXR_NS::PcpCache::ComputePrimIndexesInParallel, "ComputePrimIndexesInParallel_01")
        */
        /** TODO: instantiate this template
        .m((void (PXR_NS::PcpCache::*)(const SdfPathVector &, PcpErrorVector *, const ChildrenPredicate &, const PayloadPredicate &))
            &PXR_NS::PcpCache::ComputePrimIndexesInParallel, "ComputePrimIndexesInParallel_02")
        */
        /** TODO: instantiate this template
        .m((void (PXR_NS::PcpCache::*)(const SdfPathVector &, PcpErrorVector *, const ChildrenPredicate &, const PayloadPredicate &, const char *, const char *))
            &PXR_NS::PcpCache::ComputePrimIndexesInParallel, "ComputePrimIndexesInParallel_03")
        */
        .m(&PXR_NS::PcpCache::FindPrimIndex)
        /** TODO: instantiate this template
        .m(&PXR_NS::PcpCache::ForEachPrimIndex)
        */
        .m(&PXR_NS::PcpCache::ComputePropertyIndex)
        .m(&PXR_NS::PcpCache::FindPropertyIndex)
        .m(&PXR_NS::PcpCache::ComputeRelationshipTargetPaths)
        .m(&PXR_NS::PcpCache::ComputeAttributeConnectionPaths)
        .m(&PXR_NS::PcpCache::GetUsedLayers)
        .m(&PXR_NS::PcpCache::GetUsedLayersRevision)
        .m(&PXR_NS::PcpCache::GetUsedRootLayers)
        .m(&PXR_NS::PcpCache::FindAllLayerStacksUsingLayer)
        /** TODO: instantiate this template
        .m(&PXR_NS::PcpCache::ForEachLayerStack)
        */
        .m((PXR_NS::PcpDependencyVector (PXR_NS::PcpCache::*)(const PXR_NS::PcpLayerStackPtr &, const PXR_NS::SdfPath &, PXR_NS::PcpDependencyFlags, bool, bool, bool) const)
            &PXR_NS::PcpCache::FindSiteDependencies, "FindSiteDependencies_00")
        .m((PXR_NS::PcpDependencyVector (PXR_NS::PcpCache::*)(const PXR_NS::SdfLayerHandle &, const PXR_NS::SdfPath &, PXR_NS::PcpDependencyFlags, bool, bool, bool) const)
            &PXR_NS::PcpCache::FindSiteDependencies, "FindSiteDependencies_01")
        .m(&PXR_NS::PcpCache::CanHaveOpinionForSite)
        .m(&PXR_NS::PcpCache::GetInvalidSublayerIdentifiers)
        .m(&PXR_NS::PcpCache::IsInvalidSublayerIdentifier)
        .m(&PXR_NS::PcpCache::GetInvalidAssetPaths)
        .m(&PXR_NS::PcpCache::IsInvalidAssetPath)
        .m(&PXR_NS::PcpCache::HasAnyDynamicFileFormatArgumentFieldDependencies)
        .m(&PXR_NS::PcpCache::HasAnyDynamicFileFormatArgumentAttributeDependencies)
        .m(&PXR_NS::PcpCache::IsPossibleDynamicFileFormatArgumentField)
        .m(&PXR_NS::PcpCache::IsPossibleDynamicFileFormatArgumentAttribute)
        .m(&PXR_NS::PcpCache::GetDynamicFileFormatArgumentDependencyData)
        .m(&PXR_NS::PcpCache::GetPrimsUsingExpressionVariablesFromLayerStack)
        .m(&PXR_NS::PcpCache::GetExpressionVariablesFromLayerStackUsedByPrim)
        /// XXX: PcpLifeboat doesn't link
        // .m(&PXR_NS::PcpCache::Apply)
        .m(&PXR_NS::PcpCache::Reload)
        .m(&PXR_NS::PcpCache::ReloadReferences)
        .m(&PXR_NS::PcpCache::PrintStatistics)
    ;

    bbl::Class<std::map<PXR_NS::SdfPath, std::vector<std::string>, PXR_NS::SdfPath::FastLessThan>>("InvalidAssetPathMap")
    ;

    bbl::Class<PXR_NS::PcpCache::PayloadSet>("CachePayloadSet")
    ;

    bbl::Class<PXR_NS::PcpChanges>("Changes")
        .ctor(bbl::Class<PXR_NS::PcpChanges>::Ctor<>(), "default")
        .m(&PXR_NS::PcpChanges::DidChange)
        .m(&PXR_NS::PcpChanges::DidMaybeFixSublayer)
        .m(&PXR_NS::PcpChanges::DidMaybeFixAsset)
        .m(&PXR_NS::PcpChanges::DidMuteLayer)
        .m(&PXR_NS::PcpChanges::DidUnmuteLayer)
#if PXR_VERSION <= 2308
        .m(&PXR_NS::PcpChanges::DidChangeLayers)
        .m(&PXR_NS::PcpChanges::DidChangeLayerOffsets)
        .m(&PXR_NS::PcpChanges::DidChangeRelocates)
#endif
        .m(&PXR_NS::PcpChanges::DidChangeSignificantly)
        .m(&PXR_NS::PcpChanges::DidChangeSpecs)
        .m(&PXR_NS::PcpChanges::DidChangeSpecStack)
        .m(&PXR_NS::PcpChanges::DidChangeTargets)
        .m(&PXR_NS::PcpChanges::DidChangePaths)
        .m(&PXR_NS::PcpChanges::DidDestroyCache)
        .m(&PXR_NS::PcpChanges::DidChangeAssetResolver)
        .m(&PXR_NS::PcpChanges::Swap)
        .m(&PXR_NS::PcpChanges::IsEmpty)
        .m(&PXR_NS::PcpChanges::GetLayerStackChanges)
        .m(&PXR_NS::PcpChanges::GetCacheChanges)
        /// XXX: lifeboat doesnt link
        // .m(&PXR_NS::PcpChanges::GetLifeboat)
        .m(&PXR_NS::PcpChanges::Apply)
    ;

    bbl::Class<PXR_NS::PcpChanges::CacheChanges>("PcpChangesCacheChanges")
    ;

    bbl::Class<PXR_NS::PcpChanges::LayerStackChanges>("PcpLayerStackChanges")
    ;

    bbl::Class<PXR_NS::PcpCacheChanges>("CacheChanges")
    ;

    bbl::Enum<PXR_NS::PcpCacheChanges::TargetType>("CacheChangesTargetType");

    bbl::Class<PXR_NS::Pcp_CompressedSdSite>("CompressedSdSite")
    ;

    bbl::Class<PXR_NS::PcpSourceArcInfo>("SourceArcInfo")
    ;

    bbl::Class<PXR_NS::PcpSourceArcInfoVector>("SourceArcInfoVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::PcpSourceArcInfo)
    ;

    bbl::Class<PXR_NS::PcpDependency>("Dependency")
    ;

    bbl::Class<PXR_NS::PcpDependencyVector>("DependencyVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::PcpDependency)
    ;

    bbl::Class<PXR_NS::PcpCulledDependency>("CulledDependency")
    ;

    bbl::Enum<PXR_NS::PcpDependencyType>("DependencyType");

    bbl::Class<PXR_NS::PcpDynamicFileFormatContext>("DynamicFileFormatContext")
        .m(&PXR_NS::PcpDynamicFileFormatContext::ComposeValue)
        .m(&PXR_NS::PcpDynamicFileFormatContext::ComposeValueStack)
        .m(&PXR_NS::PcpDynamicFileFormatContext::ComposeAttributeDefaultValue)
    ;

    bbl::Class<PXR_NS::PcpDynamicFileFormatDependencyData>("DynamicFileFormatDependencyData")
        .ctor(bbl::Class<PXR_NS::PcpDynamicFileFormatDependencyData>::Ctor<>(), "default")
        .m(&PXR_NS::PcpDynamicFileFormatDependencyData::Swap)
        .m(&PXR_NS::PcpDynamicFileFormatDependencyData::swap)
        .m(&PXR_NS::PcpDynamicFileFormatDependencyData::IsEmpty)
        /// XXX: rvalue ref
        // .m(&PXR_NS::PcpDynamicFileFormatDependencyData::AddDependencyContext)
        // .m(&PXR_NS::PcpDynamicFileFormatDependencyData::AppendDependencyData)
        .m(&PXR_NS::PcpDynamicFileFormatDependencyData::GetRelevantFieldNames)
        .m(&PXR_NS::PcpDynamicFileFormatDependencyData::GetRelevantAttributeNames)
        .m(&PXR_NS::PcpDynamicFileFormatDependencyData::CanFieldChangeAffectFileFormatArguments)
        .m(&PXR_NS::PcpDynamicFileFormatDependencyData::CanAttributeDefaultValueChangeAffectFileFormatArguments)
    ;

    bbl::Class<PXR_NS::PcpDynamicFileFormatInterface>("DynamicFileFormatInterface")
        .m(&PXR_NS::PcpDynamicFileFormatInterface::ComposeFieldsForFileFormatArguments)
        .m(&PXR_NS::PcpDynamicFileFormatInterface::CanFieldChangeAffectFileFormatArguments)
        .m(&PXR_NS::PcpDynamicFileFormatInterface::CanAttributeDefaultValueChangeAffectFileFormatArguments)
    ;

    bbl::Class<PXR_NS::PcpErrorBase>("ErrorBase")
        .m(&PXR_NS::PcpErrorBase::ToString)
    ;

    bbl::Class<std::shared_ptr<PXR_NS::PcpErrorBase>>("ErrorBaseSharedPtr")
        .smartptr_to<PXR_NS::PcpErrorBase>()
    ;

    bbl::Class<std::vector<std::shared_ptr<PXR_NS::PcpErrorBase>>>("ErrorBaseSharedPtrVector")
        BBL_STD_VECTOR_METHODS((std::shared_ptr<PXR_NS::PcpErrorBase>))
    ;

    bbl::Class<PXR_NS::PcpErrorArcCycle>("ErrorArcCycle")
    ;

    bbl::Class<PXR_NS::PcpErrorArcPermissionDenied>("ErrorArcPermissionDenied")
    ;

    bbl::Class<PXR_NS::PcpErrorCapacityExceeded>("ErrorCapacityExceeded")
    ;

    bbl::Class<PXR_NS::PcpErrorInconsistentPropertyBase>("ErrorInconsistentPropertyBase")
    ;

    bbl::Class<std::shared_ptr<PXR_NS::PcpErrorInconsistentPropertyBase>>("ErrorInconsistentPropertyBaseSharedPtr")
        .smartptr_to<PXR_NS::PcpErrorInconsistentPropertyBase>()
    ;

    bbl::Class<PXR_NS::PcpErrorInconsistentPropertyType>("ErrorInconsistentPropertyType")
    ;

    bbl::Class<PXR_NS::PcpErrorInconsistentAttributeType>("ErrorInconsistentAttributeType")
    ;

    bbl::Class<PXR_NS::PcpErrorInconsistentAttributeVariability>("ErrorInconsistentAttributeVariability")
    ;

    bbl::Class<PXR_NS::PcpErrorInvalidPrimPath>("ErrorInvalidPrimPath")
    ;

    bbl::Class<PXR_NS::PcpErrorInvalidAssetPathBase>("ErrorInvalidAssetPathBase")
    ;

    bbl::Class<std::shared_ptr<PXR_NS::PcpErrorInvalidAssetPathBase>>("ErrorInvalidAssetPathBaseSharedPtr")
        .smartptr_to<PXR_NS::PcpErrorInvalidAssetPathBase>()
    ;

    bbl::Class<PXR_NS::PcpErrorInvalidAssetPath>("ErrorInvalidAssetPath")
    ;

    bbl::Class<PXR_NS::PcpErrorMutedAssetPath>("ErrorMutedAssetPath")
    ;

    bbl::Class<PXR_NS::PcpErrorTargetPathBase>("ErrorTargetPathBase")
    ;

    bbl::Class<std::shared_ptr<PXR_NS::PcpErrorTargetPathBase>>("ErrorTargetPathBaseSharedPtr")
        .smartptr_to<PXR_NS::PcpErrorTargetPathBase>()
    ;

    bbl::Class<PXR_NS::PcpErrorInvalidInstanceTargetPath>("ErrorInvalidInstaceTargetPath")
    ;

    bbl::Class<PXR_NS::PcpErrorInvalidExternalTargetPath>("ErrorInvalidExternalTargetPath")
    ;

    bbl::Class<PXR_NS::PcpErrorInvalidTargetPath>("ErrorInvalidTargetPath")
    ;

    bbl::Class<PXR_NS::PcpErrorInvalidSublayerOffset>("ErrorInvalidSublayerOffset")
    ;

    bbl::Class<PXR_NS::PcpErrorInvalidReferenceOffset>("ErrorInvalidReferenceOffset")
    ;

    bbl::Class<PXR_NS::PcpErrorInvalidSublayerOwnership>("ErrorInvalidSublayerOwnership")
    ;

    bbl::Class<PXR_NS::PcpErrorInvalidSublayerPath>("ErrorInvalidSublayerPath")
    ;

    bbl::Class<PXR_NS::PcpErrorOpinionAtRelocationSource>("ErrorOpinionAtRelocationSource")
    ;

    bbl::Class<PXR_NS::PcpErrorPrimPermissionDenied>("ErrorPrimPermissionDenied")
    ;

    bbl::Class<PXR_NS::PcpErrorPropertyPermissionDenied>("ErrorPropertyPermissionDenied")
    ;

    bbl::Class<PXR_NS::PcpErrorSublayerCycle>("ErrorSublayerCycle")
    ;

    bbl::Class<PXR_NS::PcpErrorTargetPermissionDenied>("ErrorTargetPermissionDenied")
    ;

    bbl::Class<PXR_NS::PcpErrorUnresolvedPrimPath>("ErrorUnresolvedPrimPath")
    ;

    bbl::Class<PXR_NS::PcpErrorVariableExpressionError>("ErrorVariableExpressionError")
    ;

    bbl::Enum<PXR_NS::PcpErrorType>("ErrorType");

    bbl::Class<PXR_NS::PcpExpressionVariables>("ExpressionVariables")
        .ctor(bbl::Class<PXR_NS::PcpExpressionVariables>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::PcpExpressionVariables>::Ctor<const PXR_NS::PcpExpressionVariablesSource &, const PXR_NS::VtDictionary &>("source", "expressionVariables"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::PcpExpressionVariables>::Ctor<PXR_NS::PcpExpressionVariablesSource &&, PXR_NS::VtDictionary &&>("source", "expressionVariables"), "ctor_02")
        .m(&PXR_NS::PcpExpressionVariables::Compute)
        .m(&PXR_NS::PcpExpressionVariables::operator==, "op_eq")
        .m(&PXR_NS::PcpExpressionVariables::operator!=, "op_neq")
        .m(&PXR_NS::PcpExpressionVariables::GetSource)
        .m(&PXR_NS::PcpExpressionVariables::GetVariables)
        .m(&PXR_NS::PcpExpressionVariables::SetVariables)
    ;

    bbl::Class<PXR_NS::PcpExpressionVariableCachingComposer>("ExpressionVariableCachingComposer")
        .ctor(bbl::Class<PXR_NS::PcpExpressionVariableCachingComposer>::Ctor<const PXR_NS::PcpLayerStackIdentifier &>("rootLayerStackIdentifier"), "ctor_00")
        .m(&PXR_NS::PcpExpressionVariableCachingComposer::ComputeExpressionVariables)
    ;

    bbl::Class<PXR_NS::PcpExpressionVariablesDependencyData>("ExpressionVariablesDependencyData")
        .ctor(bbl::Class<PXR_NS::PcpExpressionVariablesDependencyData>::Ctor<>(), "default")
        .m(&PXR_NS::PcpExpressionVariablesDependencyData::IsEmpty)
        /// XXX: rvalue ref
        // .m(&PXR_NS::PcpExpressionVariablesDependencyData::AppendDependencyData)
        // .m(&PXR_NS::PcpExpressionVariablesDependencyData::AddDependencies)
        .m(&PXR_NS::PcpExpressionVariablesDependencyData::GetDependenciesForLayerStack)
    ;

    bbl::Class<PXR_NS::PcpExpressionVariablesSource>("ExpressionVariablesSource")
        .ctor(bbl::Class<PXR_NS::PcpExpressionVariablesSource>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::PcpExpressionVariablesSource>::Ctor<const PXR_NS::PcpLayerStackIdentifier &, const PXR_NS::PcpLayerStackIdentifier &>("layerStackIdentifier", "rootLayerStackIdentifier"), "ctor_01")
        .m(&PXR_NS::PcpExpressionVariablesSource::operator==, "op_eq")
        .m(&PXR_NS::PcpExpressionVariablesSource::operator!=, "op_neq")
        .m(&PXR_NS::PcpExpressionVariablesSource::operator<, "op_lt")
        .m(&PXR_NS::PcpExpressionVariablesSource::GetHash)
        .m(&PXR_NS::PcpExpressionVariablesSource::IsRootLayerStack)
        .m(&PXR_NS::PcpExpressionVariablesSource::GetLayerStackIdentifier)
        .m((const PXR_NS::PcpLayerStackIdentifier & (PXR_NS::PcpExpressionVariablesSource::*)(const PXR_NS::PcpLayerStackIdentifier &) const)
            &PXR_NS::PcpExpressionVariablesSource::ResolveLayerStackIdentifier, "ResolveLayerStackIdentifier_00")
        .m((const PXR_NS::PcpLayerStackIdentifier & (PXR_NS::PcpExpressionVariablesSource::*)(const PXR_NS::PcpCache &) const)
            &PXR_NS::PcpExpressionVariablesSource::ResolveLayerStackIdentifier, "ResolveLayerStackIdentifier_01")
    ;

    bbl::Class<PXR_NS::PcpInstanceKey>("InstanceKey")
        .ctor(bbl::Class<PXR_NS::PcpInstanceKey>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::PcpInstanceKey>::Ctor<const PXR_NS::PcpPrimIndex &>("primIndex"), "ctor_01")
        .m(&PXR_NS::PcpInstanceKey::operator==, "op_eq")
        .m(&PXR_NS::PcpInstanceKey::operator!=, "op_neq")
        .m(&PXR_NS::PcpInstanceKey::GetString)
    ;

    bbl::Class<PXR_NS::PcpLayerStackSite>("LayerStackSite")
    ;

    bbl::Class<PXR_NS::PcpNodeIterator>("NodeIterator")
        .ctor(bbl::Class<PXR_NS::PcpNodeIterator>::Ctor<>(), "default")
        .m(&PXR_NS::PcpNodeIterator::GetCompressedSdSite)
    ;

    bbl::Class<PXR_NS::PcpNodeReverseIterator>("NodeReverseIterator")
        .ctor(bbl::Class<PXR_NS::PcpNodeReverseIterator>::Ctor<>(), "default")
    ;

    bbl::Class<PXR_NS::PcpPrimIterator>("PrimIterator")
        .ctor(bbl::Class<PXR_NS::PcpPrimIterator>::Ctor<>(), "default")
        .m(&PXR_NS::PcpPrimIterator::GetNode)
        .m(&PXR_NS::PcpPrimIterator::_GetSiteRef)
    ;

    bbl::Class<PXR_NS::PcpPrimReverseIterator>("PrimReverseIterator")
        .ctor(bbl::Class<PXR_NS::PcpPrimReverseIterator>::Ctor<>(), "default")
        .m(&PXR_NS::PcpPrimReverseIterator::GetNode)
    ;

    bbl::Class<PXR_NS::PcpPropertyIterator>("PropertyIterator")
        .ctor(bbl::Class<PXR_NS::PcpPropertyIterator>::Ctor<>(), "default")
        .m(&PXR_NS::PcpPropertyIterator::GetNode)
        .m(&PXR_NS::PcpPropertyIterator::IsLocal)
    ;

    bbl::Class<PXR_NS::PcpPropertyReverseIterator>("PropertyReverseIterator")
        .ctor(bbl::Class<PXR_NS::PcpPropertyReverseIterator>::Ctor<>(), "default")
        .m(&PXR_NS::PcpPropertyReverseIterator::GetNode)
        .m(&PXR_NS::PcpPropertyReverseIterator::IsLocal)
    ;

    bbl::Class<PXR_NS::PcpLayerStack>("LayerStack")
        .m(&PXR_NS::PcpLayerStack::GetIdentifier)
        .m(&PXR_NS::PcpLayerStack::GetLayers)
        .m(&PXR_NS::PcpLayerStack::GetSessionLayers)
        .m(&PXR_NS::PcpLayerStack::GetLayerTree)
        .m((const PXR_NS::SdfLayerOffset * (PXR_NS::PcpLayerStack::*)(const PXR_NS::SdfLayerHandle &) const)
            &PXR_NS::PcpLayerStack::GetLayerOffsetForLayer, "GetLayerOffsetForLayer_00")
        .m((const PXR_NS::SdfLayerOffset * (PXR_NS::PcpLayerStack::*)(const PXR_NS::SdfLayerRefPtr &) const)
            &PXR_NS::PcpLayerStack::GetLayerOffsetForLayer, "GetLayerOffsetForLayer_01")
        .m((const PXR_NS::SdfLayerOffset * (PXR_NS::PcpLayerStack::*)(size_t) const)
            &PXR_NS::PcpLayerStack::GetLayerOffsetForLayer, "GetLayerOffsetForLayer_02")
        .m(&PXR_NS::PcpLayerStack::GetMutedLayers)
        .m(&PXR_NS::PcpLayerStack::GetLocalErrors)
        .m((bool (PXR_NS::PcpLayerStack::*)(const PXR_NS::SdfLayerHandle &) const)
            &PXR_NS::PcpLayerStack::HasLayer, "HasLayer_00")
        .m((bool (PXR_NS::PcpLayerStack::*)(const PXR_NS::SdfLayerRefPtr &) const)
            &PXR_NS::PcpLayerStack::HasLayer, "HasLayer_01")
        .m(&PXR_NS::PcpLayerStack::GetExpressionVariables)
        .m(&PXR_NS::PcpLayerStack::GetExpressionVariableDependencies)
        .m(&PXR_NS::PcpLayerStack::GetTimeCodesPerSecond)
        .m(&PXR_NS::PcpLayerStack::GetRelocatesSourceToTarget)
        .m(&PXR_NS::PcpLayerStack::GetRelocatesTargetToSource)
        .m(&PXR_NS::PcpLayerStack::GetIncrementalRelocatesSourceToTarget)
        .m(&PXR_NS::PcpLayerStack::GetIncrementalRelocatesTargetToSource)
        .m(&PXR_NS::PcpLayerStack::GetPathsToPrimsWithRelocates)
        /// XXX: lifeboat doesn't link
        // .m(&PXR_NS::PcpLayerStack::Apply)
        .m(&PXR_NS::PcpLayerStack::GetExpressionForRelocatesAtPath)
    ;

    bbl::Class<PXR_NS::PcpLayerStackChanges>("LayerStackChanges")
    ;

    bbl::Class<PXR_NS::PcpLayerStackPtr>("LayerStackPtr")
        .smartptr_to<PXR_NS::PcpLayerStack>()
    ;

    bbl::Class<PXR_NS::PcpLayerStackPtrVector>("LayerStackPtrVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::PcpLayerStackPtr)
    ;

    bbl::Class<PXR_NS::PcpLayerStackRefPtr>("LayerStackRefPtr")
        .smartptr_to<PXR_NS::PcpLayerStack>()
    ;

    bbl::Class<PXR_NS::PcpLayerStackIdentifier>("LayerStackIdentifier")
        .ctor(bbl::Class<PXR_NS::PcpLayerStackIdentifier>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::PcpLayerStackIdentifier>::Ctor<const PXR_NS::SdfLayerHandle &, const PXR_NS::SdfLayerHandle &, const PXR_NS::ArResolverContext &, const PXR_NS::PcpExpressionVariablesSource &>("rootLayer", "sessionLayer", "pathResolverContext", "expressionVariablesOverrideSource"), "ctor_01")
        .m(&PXR_NS::PcpLayerStackIdentifier::operator bool)
        .m(&PXR_NS::PcpLayerStackIdentifier::operator==, "op_eq")
        .m(&PXR_NS::PcpLayerStackIdentifier::operator!=, "op_neq")
        .m(&PXR_NS::PcpLayerStackIdentifier::operator<, "op_lt")
        .m(&PXR_NS::PcpLayerStackIdentifier::operator<=, "op_lte")
        .m(&PXR_NS::PcpLayerStackIdentifier::operator>, "op_gt")
        .m(&PXR_NS::PcpLayerStackIdentifier::operator>=, "op_gte")
        .m(&PXR_NS::PcpLayerStackIdentifier::GetHash)
    ;

    // Can't link destructor
    // bbl::Class<PXR_NS::PcpLifeboat>("Lifeboat")
    // ;

    bbl::Class<PXR_NS::PcpMapExpression>("MapExpression")
        .ctor(bbl::Class<PXR_NS::PcpMapExpression>::Ctor<>(), "default")
        .m(&PXR_NS::PcpMapExpression::Evaluate)
        .m(&PXR_NS::PcpMapExpression::Swap)
        .m(&PXR_NS::PcpMapExpression::IsNull)
        .m(&PXR_NS::PcpMapExpression::Identity)
        .m(&PXR_NS::PcpMapExpression::Constant)
        /// XXX: rvalue ref
        // .m(&PXR_NS::PcpMapExpression::NewVariable)
        .m(&PXR_NS::PcpMapExpression::Compose)
        .m(&PXR_NS::PcpMapExpression::Inverse)
        .m(&PXR_NS::PcpMapExpression::AddRootIdentity)
        .m(&PXR_NS::PcpMapExpression::IsConstantIdentity)
        .m(&PXR_NS::PcpMapExpression::IsIdentity)
        .m(&PXR_NS::PcpMapExpression::MapSourceToTarget)
        .m(&PXR_NS::PcpMapExpression::MapTargetToSource)
        .m(&PXR_NS::PcpMapExpression::GetTimeOffset)
        .m(&PXR_NS::PcpMapExpression::GetString)
    ;

    bbl::Class<PXR_NS::PcpMapExpression::Variable>("MapExpressionVariable")
        .m(&PXR_NS::PcpMapExpression::Variable::GetValue)
        /// XXX: rvalue ref
        // .m(&PXR_NS::PcpMapExpression::Variable::SetValue)
        .m(&PXR_NS::PcpMapExpression::Variable::GetExpression)
    ;

    bbl::Class<PXR_NS::PcpMapExpression::VariableUniquePtr>("MapExpressionVariableUniquePtr")
        .smartptr_to<PXR_NS::PcpMapExpression::Variable>()
    ;

    bbl::Class<PXR_NS::PcpMapFunction>("MapFunction")
        .ctor(bbl::Class<PXR_NS::PcpMapFunction>::Ctor<>(), "default")
        .m(&PXR_NS::PcpMapFunction::IsNull)
        .m(&PXR_NS::PcpMapFunction::IsIdentity)
        .m(&PXR_NS::PcpMapFunction::IsIdentityPathMapping)
        .m(&PXR_NS::PcpMapFunction::HasRootIdentity)
#if PXR_VERSION <= 2308
        .m(&PXR_NS::PcpMapFunction::MapSourceToTarget)
        .m(&PXR_NS::PcpMapFunction::MapTargetToSource)
#endif
        .m(&PXR_NS::PcpMapFunction::Compose)
        .m(&PXR_NS::PcpMapFunction::ComposeOffset)
        .m(&PXR_NS::PcpMapFunction::GetInverse)
        .m(&PXR_NS::PcpMapFunction::GetSourceToTargetMap)
        .m(&PXR_NS::PcpMapFunction::GetTimeOffset)
        .m(&PXR_NS::PcpMapFunction::GetString)
        .m(&PXR_NS::PcpMapFunction::Hash)
        .m(&PXR_NS::PcpMapFunction::Create)
        .m(&PXR_NS::PcpMapFunction::Identity)
        .m(&PXR_NS::PcpMapFunction::IdentityPathMap)
    ;

    bbl::Class<PXR_NS::PcpMapFunction::PathMap>("MapFunctionPathMap")
    ;


    bbl::Class<PXR_NS::PcpNamespaceEdits>("NamespaceEdits")
        .m(&PXR_NS::PcpNamespaceEdits::Swap)
    ;

    bbl::Class<PXR_NS::PcpNamespaceEdits::CacheSite>("NamespaceEditsCacheSite")
    ;

    bbl::Class<PXR_NS::PcpNamespaceEdits::LayerStackSite>("NamespaceEditsLayerStackSite")
    ;

    bbl::Enum<PXR_NS::PcpNamespaceEdits::EditType>();


    bbl::Class<PXR_NS::PcpNodeRef>("NodeRef")
        .ctor(bbl::Class<PXR_NS::PcpNodeRef>::Ctor<>(), "default")
        .m(&PXR_NS::PcpNodeRef::operator==, "op_eq")
        .m(&PXR_NS::PcpNodeRef::operator!=, "op_neq")
        .m(&PXR_NS::PcpNodeRef::operator<, "op_lt")
        .m(&PXR_NS::PcpNodeRef::operator<=, "op_lte")
        .m(&PXR_NS::PcpNodeRef::operator>, "op_gt")
        .m(&PXR_NS::PcpNodeRef::operator>=, "op_gte")
        .m(&PXR_NS::PcpNodeRef::GetOwningGraph)
        .m(&PXR_NS::PcpNodeRef::GetUniqueIdentifier)
        .m(&PXR_NS::PcpNodeRef::GetArcType)
        .m(&PXR_NS::PcpNodeRef::GetParentNode)
        .m(&PXR_NS::PcpNodeRef::GetChildrenRange)
        .m(&PXR_NS::PcpNodeRef::InsertChild)
        .m(&PXR_NS::PcpNodeRef::InsertChildSubgraph)
        .m(&PXR_NS::PcpNodeRef::GetOriginNode)
        .m(&PXR_NS::PcpNodeRef::GetOriginRootNode)
        .m(&PXR_NS::PcpNodeRef::GetRootNode)
        .m(&PXR_NS::PcpNodeRef::GetMapToParent)
        .m(&PXR_NS::PcpNodeRef::GetMapToRoot)
        .m(&PXR_NS::PcpNodeRef::GetSiblingNumAtOrigin)
        .m(&PXR_NS::PcpNodeRef::GetNamespaceDepth)
        .m(&PXR_NS::PcpNodeRef::GetDepthBelowIntroduction)
        .m(&PXR_NS::PcpNodeRef::GetPathAtIntroduction)
        .m(&PXR_NS::PcpNodeRef::GetIntroPath)
        .m(&PXR_NS::PcpNodeRef::GetSite)
        .m(&PXR_NS::PcpNodeRef::GetPath)
        .m(&PXR_NS::PcpNodeRef::GetLayerStack)
        .m(&PXR_NS::PcpNodeRef::IsRootNode)
        .m(&PXR_NS::PcpNodeRef::SetIsDueToAncestor)
        .m(&PXR_NS::PcpNodeRef::IsDueToAncestor)
        .m(&PXR_NS::PcpNodeRef::SetHasSymmetry)
        .m(&PXR_NS::PcpNodeRef::HasSymmetry)
        .m(&PXR_NS::PcpNodeRef::SetPermission)
        .m(&PXR_NS::PcpNodeRef::GetPermission)
        .m(&PXR_NS::PcpNodeRef::SetInert)
        .m(&PXR_NS::PcpNodeRef::IsInert)
        .m(&PXR_NS::PcpNodeRef::SetCulled)
        .m(&PXR_NS::PcpNodeRef::IsCulled)
        .m(&PXR_NS::PcpNodeRef::SetRestricted)
        .m(&PXR_NS::PcpNodeRef::IsRestricted)
        .m(&PXR_NS::PcpNodeRef::CanContributeSpecs)
        .m(&PXR_NS::PcpNodeRef::SetHasSpecs)
        .m(&PXR_NS::PcpNodeRef::HasSpecs)
        .m(&PXR_NS::PcpNodeRef::GetCompressedSdSite)
    ;

    bbl::Class<PXR_NS::PcpNodeRange>("NodeRange")
    ;

    bbl::Class<PXR_NS::PcpNodeRef::child_const_iterator>("NodeRef_child_const_iterator")
    ;

    bbl::Class<PXR_NS::PcpNodeRef::child_const_reverse_iterator>("NodeRef_child_const_reverse_iterator")
    ;

    bbl::Class<PXR_NS::PcpNodeRef::child_const_range>("NodeRef_child_const_range")
    ;

    bbl::Class<PXR_NS::PcpPrimIndex>("PrimIndex")
        .ctor(bbl::Class<PXR_NS::PcpPrimIndex>::Ctor<>(), "default")
        .m(&PXR_NS::PcpPrimIndex::Swap)
        .m(&PXR_NS::PcpPrimIndex::swap)
        .m(&PXR_NS::PcpPrimIndex::IsValid)
        .m(&PXR_NS::PcpPrimIndex::SetGraph)
        .m(&PXR_NS::PcpPrimIndex::GetGraph)
        .m(&PXR_NS::PcpPrimIndex::GetRootNode)
        .m(&PXR_NS::PcpPrimIndex::GetPath)
        .m(&PXR_NS::PcpPrimIndex::HasSpecs)
        .m(&PXR_NS::PcpPrimIndex::HasAnyPayloads)
        .m(&PXR_NS::PcpPrimIndex::IsUsd)
        .m(&PXR_NS::PcpPrimIndex::IsInstanceable)
        .m(&PXR_NS::PcpPrimIndex::GetNodeRange)
        .m(&PXR_NS::PcpPrimIndex::GetNodeIteratorAtNode)
        .m(&PXR_NS::PcpPrimIndex::GetPrimRange)
        .m(&PXR_NS::PcpPrimIndex::GetPrimRangeForNode)
        .m((PXR_NS::PcpNodeRef (PXR_NS::PcpPrimIndex::*)(const PXR_NS::SdfPrimSpecHandle &) const)
            &PXR_NS::PcpPrimIndex::GetNodeProvidingSpec, "GetNodeProvidingSpec_00")
        .m((PXR_NS::PcpNodeRef (PXR_NS::PcpPrimIndex::*)(const PXR_NS::SdfLayerHandle &, const PXR_NS::SdfPath &) const)
            &PXR_NS::PcpPrimIndex::GetNodeProvidingSpec, "GetNodeProvidingSpec_01")
        .m(&PXR_NS::PcpPrimIndex::GetLocalErrors)
        .m(&PXR_NS::PcpPrimIndex::PrintStatistics)
        .m(&PXR_NS::PcpPrimIndex::DumpToString)
        .m(&PXR_NS::PcpPrimIndex::DumpToDotGraph)
        .m(&PXR_NS::PcpPrimIndex::ComputePrimChildNames)
        .m(&PXR_NS::PcpPrimIndex::ComputePrimPropertyNames)
        .m(&PXR_NS::PcpPrimIndex::ComposeAuthoredVariantSelections)
        .m(&PXR_NS::PcpPrimIndex::GetSelectionAppliedForVariantSet)
    ;

    bbl::Class<PXR_NS::PcpPrimIndexOutputs>("PrimIndexOutputs")
        /// XXX: rvalue ref
        // .m(&PXR_NS::PcpPrimIndexOutputs::Append)
    ;

    bbl::Class<PXR_NS::PcpPrimIndexInputs>("PrimIndexInputs")
        .ctor(bbl::Class<PXR_NS::PcpPrimIndexInputs>::Ctor<>(), "default")
        /// XXX: link fails
        // .m(&PXR_NS::PcpPrimIndexInputs::IsEquivalentTo)
        .m(&PXR_NS::PcpPrimIndexInputs::Cache)
        .m(&PXR_NS::PcpPrimIndexInputs::VariantFallbacks)
        .m(&PXR_NS::PcpPrimIndexInputs::IncludedPayloads)
        /// XXX: tbb mutex
        // .m(&PXR_NS::PcpPrimIndexInputs::IncludedPayloadsMutex)
        .m(&PXR_NS::PcpPrimIndexInputs::IncludePayloadPredicate)
        .m(&PXR_NS::PcpPrimIndexInputs::Cull)
        .m(&PXR_NS::PcpPrimIndexInputs::USD)
        .m(&PXR_NS::PcpPrimIndexInputs::FileFormatTarget)
    ;

    bbl::ClassIncomplete<PXR_NS::PcpPrimIndex_Graph>("PrimIndex_Graph")
    ;

    bbl::Class<PXR_NS::PcpPrimIndex_GraphRefPtr>("PrimIndex_GraphRefPtr")
        .smartptr_to<PXR_NS::PcpPrimIndex_Graph>()
    ;

    bbl::Class<PXR_NS::PcpPrimRange>("PrimRange")
    ;

    bbl::Class<PXR_NS::PcpPropertyIndex>("PropertyIndex")
        .ctor(bbl::Class<PXR_NS::PcpPropertyIndex>::Ctor<>(), "default")
        .m(&PXR_NS::PcpPropertyIndex::Swap)
        .m(&PXR_NS::PcpPropertyIndex::IsEmpty)
        .m(&PXR_NS::PcpPropertyIndex::GetPropertyRange)
        .m(&PXR_NS::PcpPropertyIndex::GetLocalErrors)
        .m(&PXR_NS::PcpPropertyIndex::GetNumLocalSpecs)
    ;

    bbl::Class<PXR_NS::PcpPropertyRange>("PropertyRange")
    ;

    bbl::Class<PXR_NS::Pcp_SdSiteRef>("SdSiteRef")
    ;

    bbl::Class<PXR_NS::PcpSite>("Site")
        .ctor(bbl::Class<PXR_NS::PcpSite>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::PcpSite>::Ctor<const PXR_NS::PcpLayerStackIdentifier &, const PXR_NS::SdfPath &>("param_00", "path"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::PcpSite>::Ctor<const PXR_NS::PcpLayerStackPtr &, const PXR_NS::SdfPath &>("param_00", "path"), "ctor_02")
        .ctor(bbl::Class<PXR_NS::PcpSite>::Ctor<const PXR_NS::SdfLayerHandle &, const PXR_NS::SdfPath &>("param_00", "path"), "ctor_03")
        .ctor(bbl::Class<PXR_NS::PcpSite>::Ctor<const PXR_NS::PcpLayerStackSite &>("param_00"), "ctor_04")
        .m(&PXR_NS::PcpSite::operator==, "op_eq")
        .m(&PXR_NS::PcpSite::operator!=, "op_neq")
        .m(&PXR_NS::PcpSite::operator<, "op_lt")
        .m(&PXR_NS::PcpSite::operator<=, "op_lte")
        .m(&PXR_NS::PcpSite::operator>, "op_gt")
        .m(&PXR_NS::PcpSite::operator>=, "op_gte")
        .m((PXR_NS::PcpSite & (PXR_NS::PcpSite::*)(const PXR_NS::PcpSite &))
            &PXR_NS::PcpSite::operator=, "op_assign_00")
        .m((PXR_NS::PcpSite & (PXR_NS::PcpSite::*)(PXR_NS::PcpSite &&))
            &PXR_NS::PcpSite::operator=, "op_assign_01")
    ;

    bbl::Class<PXR_NS::PcpTargetIndex>("TargetIndex")
    ;

    bbl::Class<PXR_NS::PcpTokenSet>("TokenSet")
    ;

    bbl::Class<PXR_NS::PcpVariantFallbackMap>("VariantFallbackMap")
    ;

    bbl::Class<PXR_NS::PcpSiteTrackerSegment>("SiteTrackerSegment")
    ;

    bbl::fn(&PXR_NS::PcpIsInheritArc);

    bbl::fn(&PXR_NS::PcpIsSpecializeArc);

    bbl::fn(&PXR_NS::PcpIsClassBasedArc);

    bbl::Enum<PXR_NS::PcpRangeType>();

}


#endif
