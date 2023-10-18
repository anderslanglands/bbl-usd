#if defined(__clang__)

#include "babble"
#include "babble-std"
#include "babble-usd"

#include <pxr/base/vt/array.h>
#include <pxr/base/vt/value.h>
#include <pxr/usd/ar/resolverContext.h>
#include <pxr/usd/sdf/assetPath.h>
#include <pxr/usd/sdf/layerOffset.h>
#include <pxr/usd/sdf/payload.h>
#include <pxr/usd/sdf/reference.h>
#include <pxr/usd/sdf/types.h>
#include <pxr/usd/usd/attribute.h>
#include <pxr/usd/usd/attributeQuery.h>
#include <pxr/usd/usd/common.h>
#include <pxr/usd/usd/editTarget.h>
#include <pxr/usd/usd/inherits.h>
#include <pxr/usd/usd/interpolation.h>
#include <pxr/usd/usd/object.h>
#include <pxr/usd/usd/payloads.h>
#include <pxr/usd/usd/prim.h>
#include <pxr/usd/usd/primDefinition.h>
#include <pxr/usd/usd/primRange.h>
#include <pxr/usd/usd/property.h>
#include <pxr/usd/usd/references.h>
#include <pxr/usd/usd/relationship.h>
#include <pxr/usd/usd/resolveInfo.h>
#include <pxr/usd/usd/resolveTarget.h>
#include <pxr/usd/usd/schemaBase.h>
#include <pxr/usd/usd/schemaRegistry.h>
#include <pxr/usd/usd/specializes.h>
#include <pxr/usd/usd/stageCache.h>
#include <pxr/usd/usd/stagePopulationMask.h>
#include <pxr/usd/usd/timeCode.h>
#include <pxr/usd/usd/variantSets.h>
#include <pxr/usd/sdf/path.h>
#include <pxr/usd/usd/stageLoadRules.h>
#include <pxr/usd/usd/stage.h>


#include <pxr/base/tf/token.h>

struct TimeCode {
    double time;
};

// we can define extension functions in namespace bblext
namespace bblext {

// make Stage_Open just take a char const* rather than having to build a std::string
PXR_NS::UsdStageRefPtr Stage_Open(char const* filename, PXR_NS::UsdStage::InitialLoadSet loadSet) {
    return PXR_NS::UsdStage::Open(filename, loadSet);
}

}

// We define modules that just act as a way to group binding declarations
// together. These would then likely be turned into real modules in languages
// that support them like Rust or Python
BBL_MODULE(usd) {

    // clang-format off

    using Token = PXR_NS::TfToken;
    using Type = PXR_NS::TfType;
    using Payloads = PXR_NS::UsdPayloads;
    using Property = PXR_NS::UsdProperty;
    using Attribute = PXR_NS::UsdAttribute;
    using Relationship = PXR_NS::UsdRelationship;
    using Object = PXR_NS::UsdObject;
    using Prim = PXR_NS::UsdPrim;
    using PrimRange = PXR_NS::UsdPrimRange;
    using PrimRangeIterator = PXR_NS::UsdPrimRange::iterator;
    using NodeRef = PXR_NS::PcpNodeRef;
    using SchemaVersion = PXR_NS::UsdSchemaVersion;
    using SchemaRegistry = PXR_NS::UsdSchemaRegistry;
    using Stage = PXR_NS::UsdStage;
    using StageRefPtr = PXR_NS::UsdStageRefPtr;
    using EditTarget = PXR_NS::UsdEditTarget;
    using LayerHandle = PXR_NS::SdfLayerHandle;
    using LayerOffset = PXR_NS::SdfLayerOffset;
    using Value = PXR_NS::VtValue;
    using StageInitialLoadSet = PXR_NS::UsdStage::InitialLoadSet;
    using ResolverContext = PXR_NS::ArResolverContext;
    using StagePopulationMask = PXR_NS::UsdStagePopulationMask;

#define PROPERTY_METHODS(CLS)                                                  \
    .m(&CLS::GetPropertyStack)                                                 \
        .m(&CLS::GetPropertyStackWithLayerOffsets)                             \
        .m(&CLS::GetBaseName)                                                  \
        .m(&CLS::GetNamespace)                                                 \
        .m(&CLS::SplitName)                                                    \
        .m(&CLS::GetDisplayGroup)                                              \
        .m(&CLS::SetDisplayGroup)                                              \
        .m(&CLS::ClearDisplayGroup)                                            \
        .m(&CLS::HasAuthoredDisplayGroup)                                      \
        .m(&CLS::GetNestedDisplayGroups)                                       \
        .m(&CLS::SetNestedDisplayGroups)                                       \
        .m(&CLS::IsCustom)                                                     \
        .m(&CLS::SetCustom)                                                    \
        .m(&CLS::IsDefined)                                                    \
        .m(&CLS::IsAuthored)                                                   \
        .m(&CLS::IsAuthoredAt)                                                 \
        .m((PXR_NS::UsdProperty (CLS::*)(PXR_NS::UsdPrim const&) const) & CLS::FlattenTo,  \
           "FlattenTo_prim")                                                   \
        .m((PXR_NS::UsdProperty(CLS::*)(PXR_NS::UsdPrim const&, PXR_NS::TfToken const&) const) &    \
               CLS::FlattenTo,                                                 \
           "FlattenTo_named_property")                                         \
        .m((PXR_NS::UsdProperty(CLS::*)(PXR_NS::UsdProperty const&) const) & CLS::FlattenTo,         \
           "FlattenTo_property")


#define ATTRIBUTE_METHODS(CLS)                                                 \
    .m(&CLS::GetVariability)                                                   \
        .m(&CLS::SetVariability)                                               \
        .m(&CLS::GetTypeName)                                                  \
        .m(&CLS::SetTypeName)                                                  \
        .m(&CLS::GetRoleName)                                                  \
        .m(&CLS::AddConnection)                                                \
        .m(&CLS::RemoveConnection)                                             \
        .m(&CLS::SetConnections)                                               \
        .m(&CLS::ClearConnections)                                             \
        .m(&CLS::GetConnections)                                               \
        .m(&CLS::HasAuthoredConnections)                                       \
        .m(&CLS::GetColorSpace)                                                \
        .m(&CLS::SetColorSpace)                                                \
        .m(&CLS::HasColorSpace)                                                \
        .m(&CLS::ClearColorSpace)                                              \
        .m(&CLS::GetTimeSamples)                                               \
        .m(&CLS::GetTimeSamplesInInterval)                                     \
        .m(&CLS::GetNumTimeSamples)                                            \
        .m(&CLS::GetBracketingTimeSamples)                                     \
        .m(&CLS::HasValue)                                                     \
        .m(&CLS::HasAuthoredValueOpinion)                                      \
        .m(&CLS::HasAuthoredValue)                                             \
        .m(&CLS::HasFallbackValue)                                             \
        .m(&CLS::ValueMightBeTimeVarying)                                      \
        .m((bool(PXR_NS::UsdAttribute::*)(PXR_NS::VtValue*,                    \
                                          PXR_NS::UsdTimeCode) const) &        \
           PXR_NS::UsdAttribute::Get)                                          \
        .m((PXR_NS::UsdResolveInfo(PXR_NS::UsdAttribute::*)(                   \
               PXR_NS::UsdTimeCode) const) &                                   \
               PXR_NS::UsdAttribute::GetResolveInfo,                           \
           "GetResolveInfo_at_time")                                           \
        .m((PXR_NS::UsdResolveInfo(PXR_NS::UsdAttribute::*)() const) &         \
           PXR_NS::UsdAttribute::GetResolveInfo)                               \
        .m((bool(PXR_NS::UsdAttribute::*)(PXR_NS::VtValue const&,              \
                                          PXR_NS::UsdTimeCode) const) &        \
           PXR_NS::UsdAttribute::Set)                                          \
        .m(&CLS::Clear)                                                        \
        .m(&CLS::ClearAtTime)                                                  \
        .m(&CLS::ClearDefault)                                                 \
        .m(&CLS::Block)                                                        \
        .m(&CLS::GetUnionedTimeSamples)                                        \
        .m(&CLS::GetUnionedTimeSamplesInInterval)

    bbl::Class<PXR_NS::UsdAttribute>("Attribute")
        .ctor(bbl::Ctor<Attribute>(), "default")

        ATTRIBUTE_METHODS(Attribute)
        PROPERTY_METHODS(Attribute)
        OBJECT_METHODS(Attribute)
    ;

    bbl::Class<PXR_NS::UsdAttributeQuery>("AttributeQuery")
        .ctor(bbl::Ctor<PXR_NS::UsdAttributeQuery>(), "default")
        .ctor(bbl::Ctor<PXR_NS::UsdAttributeQuery, PXR_NS::UsdPrim const&, PXR_NS::TfToken const&>(), "from_prim_and_attribute_name")
        .ctor(bbl::Ctor<PXR_NS::UsdAttributeQuery, PXR_NS::UsdAttribute const&, PXR_NS::UsdResolveTarget const&>(), "from_attribute_and_resolve_target")
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

    bbl::Class<std::vector<PXR_NS::UsdAttribute>>("AttributeVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdAttribute);

    bbl::Class<PXR_NS::UsdEditTarget>("EditTarget")
        .ctor(bbl::Ctor<EditTarget>(), "default")
        .ctor(bbl::Ctor<EditTarget, LayerHandle, LayerOffset>(), "from_layer")
        .ctor(bbl::Ctor<EditTarget, LayerHandle, NodeRef>(), "from_layer_and_node")
        .m(&EditTarget::operator==, "op_eq")
        .m(&EditTarget::IsNull)
        .m(&EditTarget::IsValid)
        .m((LayerHandle const& (EditTarget::*)() const&)
            &EditTarget::GetLayer
        )
        .m(&EditTarget::MapToSpecPath)
        .m(&EditTarget::GetPrimSpecForScenePath)
        .m(&EditTarget::GetPropertySpecForScenePath)
        .m(&EditTarget::GetSpecForScenePath)
        .m(&EditTarget::GetMapFunction)
        .m(&EditTarget::ComposeOver)
        .m(&EditTarget::ForLocalDirectVariant)
        ;

    bbl::Class<PXR_NS::UsdInherits>("Inherits")
        .m(&PXR_NS::UsdInherits::AddInherit)
        .m(&PXR_NS::UsdInherits::RemoveInherit)
        .m(&PXR_NS::UsdInherits::ClearInherits)
        .m(&PXR_NS::UsdInherits::SetInherits)
        .m(&PXR_NS::UsdInherits::GetAllDirectInherits)
        .m((Prim const&(PXR_NS::UsdInherits::*)() const)
            &PXR_NS::UsdInherits::GetPrim
        )
        ;

    bbl::Enum<PXR_NS::UsdInterpolationType>("InterpolationType");
    bbl::Enum<PXR_NS::UsdListPosition>("ListPosition");
    bbl::Enum<PXR_NS::UsdLoadPolicy>("LoadPolicy");

    bbl::Class<PXR_NS::UsdMetadataValueMap>("MetadataValueMap")
        .m((PXR_NS::UsdMetadataValueMap::mapped_type const& (PXR_NS::UsdMetadataValueMap::*)(PXR_NS::UsdMetadataValueMap::key_type const&) const)
            &PXR_NS::UsdMetadataValueMap::at, "at_const"
        )
        .m((PXR_NS::UsdMetadataValueMap::mapped_type& (PXR_NS::UsdMetadataValueMap::*)(PXR_NS::UsdMetadataValueMap::key_type const&))
            &PXR_NS::UsdMetadataValueMap::at
        )
        ;

    bbl::Class<PXR_NS::UsdObject>("Object")
        .ctor(bbl::Ctor<Object>(), "default")
        .m(&PXR_NS::UsdObject::Is<PXR_NS::UsdAttribute>, "Is_Attribute")
        .m(&PXR_NS::UsdObject::Is<PXR_NS::UsdRelationship>, "Is_Relationship")
        .m(&PXR_NS::UsdObject::Is<PXR_NS::UsdProperty>, "Is_Property")
        .m(&PXR_NS::UsdObject::Is<PXR_NS::UsdPrim>, "Is_Prim")
        .m(&PXR_NS::UsdObject::As<PXR_NS::UsdAttribute>, "As_Attribute")
        .m(&PXR_NS::UsdObject::As<PXR_NS::UsdRelationship>, "As_Relationship")
        .m(&PXR_NS::UsdObject::As<PXR_NS::UsdProperty>, "As_Property")
        .m(&PXR_NS::UsdObject::As<PXR_NS::UsdPrim>, "As_Prim")
        OBJECT_METHODS(Object)
        ;

    bbl::Class<std::set<PXR_NS::UsdObject>>("ObjectSet")
        .ctor(bbl::Ctor<std::set<PXR_NS::UsdObject>>(), "default")
        ;

    bbl::Class<PXR_NS::UsdPayloads>("Payloads")
        .m((bool (Payloads::*)(PXR_NS::SdfPayload const&, PXR_NS::UsdListPosition))
            &Payloads::AddPayload
        )
        .m((bool (Payloads::*)(std::string const&, PXR_NS::SdfPath const&, PXR_NS::SdfLayerOffset const&, PXR_NS::UsdListPosition))
            &Payloads::AddPayload, "AddPayload_with_identifier_and_path"
        )
        .m((bool (Payloads::*)(std::string const&, PXR_NS::SdfLayerOffset const&, PXR_NS::UsdListPosition))
            &Payloads::AddPayload, "AddPayload_with_identifier"
        )
        .m(&Payloads::AddInternalPayload)
        .m(&Payloads::RemovePayload)
        .m(&Payloads::ClearPayloads)
        .m(&Payloads::SetPayloads)
        .m((Prim const&(PXR_NS::UsdPayloads::*)() const)
            &PXR_NS::UsdPayloads::GetPrim
        )
        ;

    bbl::Class<PXR_NS::UsdProperty>("Property")
        .ctor(bbl::Ctor<Property>(), "default")
        .m(&PXR_NS::UsdProperty::Is<PXR_NS::UsdAttribute>, "Is_Attribute")
        .m(&PXR_NS::UsdProperty::Is<PXR_NS::UsdRelationship>, "Is_Relationship")
        .m(&PXR_NS::UsdProperty::Is<PXR_NS::UsdProperty>, "Is_Property")
        .m(&PXR_NS::UsdProperty::Is<PXR_NS::UsdPrim>, "Is_Prim")
        .m(&PXR_NS::UsdProperty::As<PXR_NS::UsdAttribute>, "As_Attribute")
        .m(&PXR_NS::UsdProperty::As<PXR_NS::UsdRelationship>, "As_Relationship")
        .m(&PXR_NS::UsdProperty::As<PXR_NS::UsdProperty>, "As_Property")
        .m(&PXR_NS::UsdProperty::As<PXR_NS::UsdPrim>, "As_Prim")
        PROPERTY_METHODS(Property)
        OBJECT_METHODS(Property)
        ;

    bbl::Class<PXR_NS::UsdPrim::PropertyPredicateFunc>("PropertyPredicateFunc");

    bbl::Class<std::vector<PXR_NS::UsdProperty>>("PropertyVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdProperty);

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
    ;

    bbl::Class<PXR_NS::UsdRelationship>("Relationship")
        .ctor(bbl::Ctor<Relationship>(), "default")
        .m(&Relationship::AddTarget)
        .m(&Relationship::RemoveTarget)
        .m(&Relationship::SetTargets)
        .m(&Relationship::ClearTargets)
        .m(&Relationship::GetTargets)
        .m(&Relationship::GetForwardedTargets)
        .m(&Relationship::HasAuthoredTargets)

        PROPERTY_METHODS(Property)
        OBJECT_METHODS(Property)
        ;
    ;

    bbl::Class<std::vector<PXR_NS::UsdRelationship>>("RelationshipVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdRelationship);

    bbl::Class<PXR_NS::UsdResolveInfo>("ResolveInfo")
        .m(&PXR_NS::UsdResolveInfo::GetSource)
        .m(&PXR_NS::UsdResolveInfo::HasAuthoredValueOpinion)
        .m(&PXR_NS::UsdResolveInfo::HasAuthoredValue)
        .m(&PXR_NS::UsdResolveInfo::GetNode)
        .m(&PXR_NS::UsdResolveInfo::ValueIsBlocked)
    ;

    bbl::Enum<PXR_NS::UsdResolveInfoSource>("ResolveInfoSource");

    bbl::Class<PXR_NS::UsdResolveTarget>("ResolveTarget")
        .m(&PXR_NS::UsdResolveTarget::GetPrimIndex)
        .m(&PXR_NS::UsdResolveTarget::GetStartNode)
        .m(&PXR_NS::UsdResolveTarget::GetStartLayer)
        .m(&PXR_NS::UsdResolveTarget::GetStopNode)
        .m(&PXR_NS::UsdResolveTarget::GetStopLayer)
        .m(&PXR_NS::UsdResolveTarget::IsNull)
    ;

    bbl::Enum<PXR_NS::UsdSchemaRegistry::VersionPolicy>(
        "SchemaRegistryVersionPolicy");

    bbl::Enum<PXR_NS::UsdSchemaKind>("SchemaKind");

    bbl::Class<PXR_NS::UsdSpecializes>("Specializes")
        .m(&PXR_NS::UsdSpecializes::AddSpecialize)
        .m(&PXR_NS::UsdSpecializes::RemoveSpecialize)
        .m(&PXR_NS::UsdSpecializes::ClearSpecializes)
        .m(&PXR_NS::UsdSpecializes::SetSpecializes)
        .m((PXR_NS::UsdPrim const& (PXR_NS::UsdSpecializes::*)() const)
            &PXR_NS::UsdSpecializes::GetPrim)
        ;

    bbl::Class<PXR_NS::UsdVariantSet>("VariantSet");

    bbl::Class<PXR_NS::UsdVariantSets>("VariantSets");


    // bbl::Class<std::function<bool(PXR_NS::UsdAttribute const&)>>(
    //     "FindAttributePredicate");
    // bbl::Class<std::function<bool(PXR_NS::UsdRelationship const&)>>(
    //     "FindRelationshipPredicate");

    bbl::Class<PXR_NS::UsdStage>("Stage")
        // Layer Serialization
        .m(&Stage::Save)
        .m(&Stage::SaveSessionLayers)

        // Working Set Management
        .m(&Stage::Load)
        .m(&Stage::Unload)
        .m(&Stage::LoadAndUnload)
        .m(&Stage::GetLoadSet)
        .m(&Stage::FindLoadable)
        .m(&Stage::GetLoadRules)
        .m(&Stage::SetLoadRules)
        .m(&Stage::GetPopulationMask)
        .m(&Stage::SetPopulationMask)
        // .m(&Stage::ExpandPopulationMask) //< need std::function

        // Layers and Edit Targets
        .m(&Stage::GetSessionLayer)
        .m(&Stage::GetRootLayer)
        .m(&Stage::GetPathResolverContext)
        .m(&Stage::ResolveIdentifierToEditTarget)
        .m(&Stage::GetLayerStack)
        .m(&Stage::GetUsedLayers)
        .m(&Stage::HasLocalLayer)
        .m(&Stage::GetEditTarget)
        .m((EditTarget(Stage::*)(LayerHandle const&))
            &Stage::GetEditTargetForLocalLayer
        )
        .m((EditTarget(Stage::*)(size_t))
            &Stage::GetEditTargetForLocalLayer, "GetEditTargetForLocalLayer_with_index"
        )
        .m(&Stage::SetEditTarget)
        .m(&Stage::MuteLayer)
        .m(&Stage::UnmuteLayer)
        .m(&Stage::MuteAndUnmuteLayers)
        .m(&Stage::GetMutedLayers)
        .m(&Stage::IsLayerMuted)

        // Flatten & Export Utilities
        .m(&Stage::Export)
        .m(&Stage::ExportToString)
        .m(&Stage::Flatten)

        // Stage Metadata
        .m((bool (Stage::*)(Token const&, Value*) const)
            &Stage::GetMetadata
        )
        .m(&Stage::HasMetadata)
        .m(&Stage::HasAuthoredMetadata)
        .m((bool (Stage::*)(Token const&, Value const&) const)
            &Stage::SetMetadata
        )
        .m(&Stage::ClearMetadata)
        .m((bool (Stage::*)(Token const&, Token const&, Value*) const)
            &Stage::GetMetadataByDictKey
        )
        .m(&Stage::HasMetadataDictKey)
        .m(&Stage::HasAuthoredMetadataDictKey)
        .m((bool (Stage::*)(Token const&, Token const&, Value const&) const)
            &Stage::SetMetadataByDictKey
        )
        .m(&Stage::ClearMetadataByDictKey)
        .m(&Stage::WriteFallbackPrimTypes)

        // TimeCode API
        .m(&Stage::GetStartTimeCode)
        .m(&Stage::SetStartTimeCode)
        .m(&Stage::GetEndTimeCode)
        .m(&Stage::SetEndTimeCode)
        .m(&Stage::HasAuthoredTimeCodeRange)
        .m(&Stage::GetTimeCodesPerSecond)
        .m(&Stage::SetTimeCodesPerSecond)
        .m(&Stage::GetFramesPerSecond)
        .m(&Stage::SetFramesPerSecond)

        // Attribute Value Interpolation
        .m(&Stage::SetInterpolationType)
        .m(&Stage::GetInterpolationType)

        // Instancing
        .m(&Stage::GetPrototypes)

        // Variant Management
        .m(&Stage::GetGlobalVariantFallbacks)
        .m(&Stage::SetGlobalVariantFallbacks)

        // Lifetime Management
        .m((StageRefPtr(*)(std::string const&, StageInitialLoadSet))
            &Stage::CreateNew
        )
        .m((StageRefPtr(*)(std::string const&, LayerHandle const&, StageInitialLoadSet))
            &Stage::CreateNew, "CreateNew_with_session_layer"
        )
        .m((StageRefPtr(*)(std::string const&, LayerHandle const&, ResolverContext const&, StageInitialLoadSet))
            &Stage::CreateNew, "CreateNew_with_session_layer_and_resolver_context"
        )
        .m((StageRefPtr(*)(std::string const&, ResolverContext const&, StageInitialLoadSet))
            &Stage::CreateNew, "CreateNew_with_resolver_context"
        )
        .m((StageRefPtr(*)(StageInitialLoadSet))
            &Stage::CreateInMemory
        )
        .m((StageRefPtr(*)(std::string const&, StageInitialLoadSet))
            &Stage::CreateInMemory, "CreateInMemory_with_identifier"
        )
        .m((StageRefPtr(*)(std::string const&, ResolverContext const&, StageInitialLoadSet))
            &Stage::CreateInMemory, "CreateInMemory_with_resolver_context"
        )
        .m((StageRefPtr(*)(std::string const&, LayerHandle const&, StageInitialLoadSet))
            &Stage::CreateInMemory, "CreateInMemory_with_session_layer"
        )
        .m((StageRefPtr(*)(std::string const&, LayerHandle const&, ResolverContext const&, StageInitialLoadSet))
            &Stage::CreateInMemory, "CreateInMemory_with_session_layer_and_resolver_context"
        )
        // we'll override this to take a char* instead
        // .m((StageRefPtr(*)(std::string const&, Stage::InitialLoadSet))
        //     &Stage::Open
        // )
        .m((StageRefPtr(*)(std::string const&, ResolverContext const&, Stage::InitialLoadSet))
            &Stage::Open, "Open_with_resolver_context"
        )
        .m((StageRefPtr(*)(LayerHandle const&, Stage::InitialLoadSet))
            &Stage::Open, "Open_at_root"
        )
        .m((StageRefPtr(*)(LayerHandle const&, ResolverContext const&, Stage::InitialLoadSet))
            &Stage::Open, "Open_at_root_with_resolver_context"
        )
        .m((StageRefPtr(*)(LayerHandle const&, LayerHandle const&, ResolverContext const&, Stage::InitialLoadSet))
            &Stage::Open, "Open_at_root_with_session_layer_and_resolver_context"
        )
        .m((StageRefPtr(*)(LayerHandle const&, LayerHandle const&, Stage::InitialLoadSet))
            &Stage::Open, "Open_at_root_with_session_layer"
        )
        .m((StageRefPtr(*)(std::string const&, StagePopulationMask const&, Stage::InitialLoadSet))
            &Stage::OpenMasked
        )
        .m((StageRefPtr(*)(std::string const&, ResolverContext const&, StagePopulationMask const&, Stage::InitialLoadSet))
            &Stage::OpenMasked, "OpenMasked_with_resolver_context"
        )
        .m((StageRefPtr(*)(LayerHandle const&, StagePopulationMask const&, Stage::InitialLoadSet))
            &Stage::OpenMasked, "OpenMasked_at_root"
        )
        .m((StageRefPtr(*)(LayerHandle const&, ResolverContext const&, StagePopulationMask const&, Stage::InitialLoadSet))
            &Stage::OpenMasked, "OpenMasked_at_root_with_resolver_context"
        )
        .m((StageRefPtr(*)(LayerHandle const&, LayerHandle const&, ResolverContext const&, StagePopulationMask const&, Stage::InitialLoadSet))
            &Stage::OpenMasked, "OpenMasked_at_root_with_session_layer_and_resolver_context"
        )
        .m((StageRefPtr(*)(LayerHandle const&, LayerHandle const&, StagePopulationMask const&, Stage::InitialLoadSet))
            &Stage::OpenMasked, "OpenMasked_at_root_with_session_layer"
        )
        .m(&Stage::IsSupportedFile)
        .m(&Stage::Reload)

        // Color Configuration API
        .m(&Stage::GetColorConfigFallbacks)
        .m(&Stage::SetColorConfigFallbacks)
        .m(&Stage::SetColorConfiguration)
        .m(&Stage::GetColorConfiguration)
        .m(&Stage::SetColorManagementSystem)
        .m(&Stage::GetColorManagementSystem)

        // Prim Access, Creation and Mutation
        .m(&Stage::GetPseudoRoot)
        .m(&Stage::GetDefaultPrim)
        .m(&Stage::SetDefaultPrim)
        .m(&Stage::ClearDefaultPrim)
        .m(&Stage::HasDefaultPrim)
        .m(&Stage::GetPrimAtPath)
        .m(&Stage::GetObjectAtPath)
        .m(&Stage::GetPropertyAtPath)
        .m(&Stage::GetAttributeAtPath)
        .m(&Stage::GetRelationshipAtPath)
        // Cannot bind Traverse because it returns a PrimRange by value and PrimRange has no default constructor
        // Could possibly work around this by defining one ourselves that just zeroed the memory...
        .m(&Stage::OverridePrim)
        .m(&Stage::DefinePrim)
        .m(&Stage::CreateClassPrim)
        .m(&Stage::RemovePrim)
        ;

    bbl::fn(&bblext::Stage_Open);

    bbl::Enum<PXR_NS::UsdStage::InitialLoadSet>("StageInitialLoadSet");

    bbl::Class<PXR_NS::UsdStageCache>("StageCache")
        .ctor(bbl::Ctor<PXR_NS::UsdStageCache>(), "default")
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

    bbl::Class<PXR_NS::UsdStageLoadRules>("StageLoadRules")
        .ctor(bbl::Ctor<PXR_NS::UsdStageLoadRules>(), "default")
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

    bbl::Class<PXR_NS::UsdStagePopulationMask>("StagePopulationMask")
        .ctor(bbl::Ctor<PXR_NS::UsdStagePopulationMask>(), "default")
        .ctor(bbl::Ctor<PXR_NS::UsdStagePopulationMask, PXR_NS::SdfPathVector>(), "from_path_vector")
        ;

    bbl::Class<PXR_NS::UsdStageRefPtr>("StageRefPtr")
        .ctor(bbl::Ctor<StageRefPtr>(), "ctor")
        .smartptr_to<PXR_NS::UsdStage>()
        .m(&StageRefPtr::operator->, "get")
        .m(&StageRefPtr::operator!, "is_invalid")
        ;

    bbl::Class<PXR_NS::UsdStageRefPtrVector>("StageRefPtrVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdStageRefPtr)
        ;

    bbl::Class<PXR_NS::UsdStageWeakPtr>("StageWeakPtr")
        .ctor(bbl::Ctor<PXR_NS::UsdStageWeakPtr>(), "ctor")
        .m(&PXR_NS::UsdStageWeakPtr::operator->, "get");

    bbl::Class<PXR_NS::UsdTimeCode>("TimeCode")
        .replace_with<TimeCode>()
        .ctor(bbl::Ctor<PXR_NS::UsdTimeCode, double>(), "from_time")
        .ctor(bbl::Ctor<PXR_NS::UsdTimeCode, PXR_NS::SdfTimeCode>(), "from_sdf_timecode")
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

    // bbl::fn((bool (*)(PXR_NS::UsdTimeCode const&, PXR_NS::UsdTimeCode const&))&PXR_NS::operator==, "TimeCode_op_eq")

    // clang-format off
}

#endif