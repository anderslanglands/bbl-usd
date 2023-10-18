#if defined(__clang__)

#include "babble"
#include "babble-std"
#include "babble-usd"

#include <pxr/usd/usd/primTypeInfo.h>
#include <pxr/usd/sdf/proxyTypes.h>
#include <pxr/usd/sdf/reference.h>
#include <pxr/usd/usd/prim.h>
#include <pxr/usd/usd/primCompositionQuery.h>
#include <pxr/usd/usd/primDefinition.h>
#include <pxr/usd/usd/primRange.h>
#include <pxr/usd/usd/schemaRegistry.h>
#include <pxr/usd/usd/property.h>

#include <vector>

namespace bblext {

auto UsdPrim_GetProperties(PXR_NS::UsdPrim prim) -> std::vector<PXR_NS::UsdProperty> {
    return prim.GetProperties();
}

}

BBL_MODULE(usd) {
    using Prim = PXR_NS::UsdPrim;
    using PrimRange = PXR_NS::UsdPrimRange;
    using PrimRangeIterator = PXR_NS::UsdPrimRange::iterator;
    using Property = PXR_NS::UsdProperty;
    using Attribute = PXR_NS::UsdAttribute;
    using Relationship = PXR_NS::UsdRelationship;
    using Object = PXR_NS::UsdObject;
    using Token = PXR_NS::TfToken;
    using Type = PXR_NS::TfType;
    using SchemaVersion = PXR_NS::UsdSchemaVersion;
    using SchemaRegistry = PXR_NS::UsdSchemaRegistry;

    // Binding a class looks like this
    bbl::Class<PXR_NS::UsdPrim>("Prim")
        .ctor(bbl::Ctor<Prim>(), "new")
        .opaque_ptr()
        // Binding a (default) constructor looks like this
        // Method bindings just take the member function pointer and all
        // parameters with known types are extracted automatically
        .m(&Prim::GetPrimTypeInfo)
        .m(&Prim::GetPrimDefinition)
        .m(&Prim::GetSpecifier)
        .m(&Prim::SetSpecifier)
        .m(&Prim::GetPrimStack)
        .m(&Prim::GetPrimStackWithLayerOffsets)
        .m(&Prim::GetTypeName)
        .m(&Prim::SetTypeName)
        .m(&Prim::ClearTypeName)
        .m(&Prim::HasAuthoredTypeName)
        .m(&Prim::IsActive)
        .m(&Prim::SetActive)
        .m(&Prim::ClearActive)
        .m(&Prim::HasAuthoredActive)
        .m(&Prim::IsLoaded)
        .m(&Prim::IsModel)
        .m(&Prim::IsGroup)
        .m(&Prim::IsAbstract)
        .m(&Prim::IsDefined)
        .m(&Prim::GetName)
        .m(&Prim::HasDefiningSpecifier)
        .m(&Prim::GetAppliedSchemas)
        // Can't handle std::function properly yet...
        // probably need to create wrapper objects (yuck)
        //   .m(&Prim::GetPropertyNames)
        //   .m(&Prim::GetAuthoredPropertyNames)
        // .m(&Prim::GetProperties)
        // .m(&Prim::GetAuthoredProperties)
        // Overloads require casting the member function pointer to select a
        // particular one
        .m((std::vector<Property>(Prim::*)(std::string const&) const) &
           Prim::GetPropertiesInNamespace)
        .m((std::vector<Property>(Prim::*)(std::string const&) const) &
           Prim::GetAuthoredPropertiesInNamespace)
        .m(&Prim::GetPropertyOrder)
        .m(&Prim::SetPropertyOrder)
        .m(&Prim::ClearPropertyOrder)
        .m(&Prim::RemoveProperty)
        .m(&Prim::GetProperty)
        .m(&Prim::HasProperty)
        .m(&Prim::AddAppliedSchema)
        .m(&Prim::RemoveAppliedSchema)

        // IsA
        .m((bool(Prim::*)(Token const&) const) & Prim::IsA)
        // methods can be renamed to give useful names to overloads
        .m((bool(Prim::*)(Token const&, SchemaVersion) const) & Prim::IsA,
           "IsA_with_version")

        // IsInFamily
        .m((bool(Prim::*)(Token const&) const) & Prim::IsInFamily)
        .m((bool(Prim::*)(Token const&, SchemaRegistry::VersionPolicy) const) &
               Prim::IsInFamily,
           "IsInFamily_with_policy")
        .m((bool(Prim::*)(Token const&, SchemaVersion,
                          SchemaRegistry::VersionPolicy) const) &
               Prim::IsInFamily,
           "IsInFamily_with_policy_and_version")
        .m((bool(Prim::*)(Type const&, SchemaRegistry::VersionPolicy) const) &
               Prim::IsInFamily,
           "IsInFamily_with_type")
        .m(&Prim::GetVersionIfIsInFamily)

        // HasAPI
        .m((bool(Prim::*)(Type const&) const) & Prim::HasAPI)
        .m((bool(Prim::*)(Type const&, Token const&) const) & Prim::HasAPI,
           "HasAPI_with_instance_name")
        .m((bool(Prim::*)(Token const&) const) & Prim::HasAPI,
           "HasAPI_with_schema_identifier")
        .m((bool(Prim::*)(Token const&, Token const&) const) & Prim::HasAPI,
           "HasAPI_with_instance_name_and_schema_identifier")

        // HasAPIInFamily
        .m((bool(Prim::*)(Token const&) const) & Prim::HasAPIInFamily)
        // .m((bool(Prim::*)(Token const&,
        //                              Token const&) const) &
        //    Prim::HasAPIInFamily)
        // .m((bool(Prim::*)(
        //        Token const&, SchemaVersion,
        //        SchemaRegistry::VersionPolicy) const) &
        //    Prim::HasAPIInFamily)
        // .m((bool(Prim::*)(Token const&,
        //                              SchemaVersion,
        //                              SchemaRegistry::VersionPolicy,
        //                              Token const&) const) &
        //    Prim::HasAPIInFamily)
        // .m((bool(Prim::*)(Type const&,
        //                              SchemaRegistry::VersionPolicy)
        //         const) &
        //    Prim::HasAPIInFamily)
        // .m((bool(Prim::*)(Type const&,
        //                              SchemaRegistry::VersionPolicy,
        //                              Token const&) const) &
        //    Prim::HasAPIInFamily)
        // .m((bool(Prim::*)(Token const&,
        //                              SchemaRegistry::VersionPolicy)
        //         const) &
        //    Prim::HasAPIInFamily)
        // .m((bool(Prim::*)(Token const&,
        //                              SchemaRegistry::VersionPolicy,
        //                              Token const&) const) &
        //    Prim::HasAPIInFamily)
        // .m((bool(Prim::*)(Token const&,
        //                              SchemaVersion*) const) &
        //    Prim::GetVersionIfHasAPIInFamily)
        .m((bool(Prim::*)(Token const&, Token const&, SchemaVersion*) const) &
           Prim::GetVersionIfHasAPIInFamily)

        // CanApplyAPI
        .m((bool(Prim::*)(Type const&, std::string*) const) & Prim::CanApplyAPI)
        // .m((bool(Prim::*)(Type const&,
        //                              Token const&, std::string*)
        //         const) &
        //    Prim::CanApplyAPI)
        // .m((bool(Prim::*)(Token const&, std::string*)
        //         const) &
        //    Prim::CanApplyAPI)
        // .m((bool(Prim::*)(Token const&,
        //                              Token const&, std::string*)
        //         const) &
        //    Prim::CanApplyAPI)
        // .m((bool(Prim::*)(
        //        Token const&, SchemaVersion,
        //        Token const&, std::string*) const) &
        //    Prim::CanApplyAPI)

        // ApplyAPI
        .m((bool(Prim::*)(Type const&) const) & Prim::ApplyAPI)
        // .m((bool(Prim::*)(Type const&,
        //                              Token const&) const) &
        //    Prim::ApplyAPI)
        // .m((bool(Prim::*)(Token const&) const) &
        //    Prim::ApplyAPI)
        // .m((bool(Prim::*)(Token const&,
        //                              Token const&) const) &
        //    Prim::ApplyAPI)
        // .m((bool(Prim::*)(Token const&,
        //                              SchemaVersion) const) &
        //    Prim::ApplyAPI)
        // .m((bool(Prim::*)(Token const&,
        //                              SchemaVersion,
        //                              Token const&) const) &
        //    Prim::ApplyAPI)

        // RemoveAPI
        .m((bool(Prim::*)(Type const&) const) & Prim::RemoveAPI)
        // .m((bool(Prim::*)(Type const&,
        //                              Token const&) const) &
        //    Prim::RemoveAPI)
        // .m((bool(Prim::*)(Token const&) const) &
        //    Prim::RemoveAPI)
        // .m((bool(Prim::*)(Token const&,
        //                              Token const&) const) &
        //    Prim::RemoveAPI)
        // .m((bool(Prim::*)(Token const&,
        //                              SchemaVersion) const) &
        //    Prim::RemoveAPI)
        // .m((bool(Prim::*)(Token const&,
        //                              SchemaVersion,
        //                              Token const&) const) &
        //    Prim::RemoveAPI)

        // Prim Children
        .m(&Prim::GetChild)
        .m(&Prim::GetChildren)
        .m(&Prim::GetAllChildren)
        .m(&Prim::GetFilteredChildren)
        .m(&Prim::GetChildrenNames)
        .m(&Prim::GetFilteredChildrenNames)
        .m(&Prim::GetDescendants)
        .m(&Prim::GetAllDescendants)
        .m(&Prim::GetFilteredDescendants)
        .m(&Prim::GetChildrenReorder)

        // Parent & Stage
        .m(&Prim::GetParent)
        .m(&Prim::GetNextSibling)
        .m(&Prim::GetFilteredNextSibling)
        .m(&Prim::IsPseudoRoot)
        .m(&Prim::GetPrimAtPath)
        .m(&Prim::GetObjectAtPath)
        .m(&Prim::GetPropertyAtPath)
        .m(&Prim::GetAttributeAtPath)
        .m(&Prim::GetRelationshipAtPath)

        // Variants
        .m(&Prim::GetVariantSets)
        .m(&Prim::GetVariantSet)
        .m(&Prim::HasVariantSets)

        // Attributes
        // We'll only do one of these create methods as the rest are for
        // convenience, and we should do convenience on the FFI side
        .m((Attribute(Prim::*)(Token const&, PXR_NS::SdfValueTypeName const&,
                               bool, PXR_NS::SdfVariability) const) &
           Prim::CreateAttribute)
        .m(&Prim::GetAttributes)
        .m(&Prim::GetAuthoredAttributes)
        .m(&Prim::GetAttribute)
        .m(&Prim::HasAttribute)
        // .m(&Prim::FindAllAttributeConnectionPaths)

        // Relationships
        .m((Relationship(Prim::*)(Token const&, bool) const) &
           Prim::CreateRelationship)
        .m(&Prim::GetRelationships)
        .m(&Prim::GetAuthoredRelationships)
        .m(&Prim::GetRelationship)
        .m(&Prim::HasRelationship)
        // .m(&Prim::FindAllRelationshipTargetPaths)

        // Payloads, load and unload
        .m(&Prim::GetPayloads)
        .m(&Prim::HasAuthoredPayloads)
        .m(&Prim::Load)
        .m(&Prim::Unload)

        // References
        .m(&Prim::GetReferences)
        .m(&Prim::HasAuthoredReferences)

        // Inherits
        .m(&Prim::GetInherits)
        .m(&Prim::HasAuthoredInherits)

        // Specializes
        .m(&Prim::GetSpecializes)
        .m(&Prim::HasAuthoredSpecializes)

        // Composition
        .m(&Prim::GetPrimIndex)
        .m(&Prim::ComputeExpandedPrimIndex)
        .m(&Prim::MakeResolveTargetUpToEditTarget)
        .m(&Prim::MakeResolveTargetStrongerThanEditTarget)
        
        OBJECT_METHODS(PXR_NS::UsdPrim)
        ;

    // end Prim

    // we'll inject a function to get around the lack of std::function support
    bbl::fn(&bblext::UsdPrim_GetProperties, "Prim_GetProperties");

    bbl::Class<PXR_NS::UsdPrimCompositionQuery>("PrimCompositionQuery")
        .ctor(bbl::Ctor<PXR_NS::UsdPrimCompositionQuery, PXR_NS::UsdPrim const&,
                        PXR_NS::UsdPrimCompositionQuery::Filter const&>(
            "prim", "filter"))
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
        .m((bool(PXR_NS::UsdPrimCompositionQueryArc::*)(
               PXR_NS::SdfReferenceEditorProxy*, PXR_NS::SdfReference*) const) &
               PXR_NS::UsdPrimCompositionQueryArc::GetIntroducingListEditor,
           "GetIntroducingListEditor_reference")
        .m((bool(PXR_NS::UsdPrimCompositionQueryArc::*)(
               PXR_NS::SdfPayloadEditorProxy*, PXR_NS::SdfPayload*) const) &
               PXR_NS::UsdPrimCompositionQueryArc::GetIntroducingListEditor,
           "GetIntroducingListEditor_payload")
        .m((bool(PXR_NS::UsdPrimCompositionQueryArc::*)(
               PXR_NS::SdfPathEditorProxy*, PXR_NS::SdfPath*) const) &
               PXR_NS::UsdPrimCompositionQueryArc::GetIntroducingListEditor,
           "GetIntroducingListEditor_path")
        .m((bool(PXR_NS::UsdPrimCompositionQueryArc::*)(
               PXR_NS::SdfNameEditorProxy*, std::string*) const) &
               PXR_NS::UsdPrimCompositionQueryArc::GetIntroducingListEditor,
           "GetIntroducingListEditor_name")

        // Arc classification
        .m(&PXR_NS::UsdPrimCompositionQueryArc::GetArcType)
        .m(&PXR_NS::UsdPrimCompositionQueryArc::IsImplicit)
        .m(&PXR_NS::UsdPrimCompositionQueryArc::IsAncestral)
        .m(&PXR_NS::UsdPrimCompositionQueryArc::HasSpecs)
        .m(&PXR_NS::UsdPrimCompositionQueryArc::IsIntroducedInRootLayerStack)
        .m(&PXR_NS::UsdPrimCompositionQueryArc::
               IsIntroducedInRootLayerPrimSpec);

    bbl::Class<std::vector<PXR_NS::UsdPrimCompositionQueryArc>>(
        "PrimCompositionQueryArcVector");
        // BBL_STD_VECTOR_METHODS(PXR_NS::UsdPrimCompositionQueryArc);

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
        .m((bool(PXR_NS::UsdPrimDefinition::*)(PXR_NS::SdfLayerHandle const&,
                                               PXR_NS::SdfPath const&,
                                               PXR_NS::SdfSpecifier) const) &
           PXR_NS::UsdPrimDefinition::FlattenTo)
        .m((PXR_NS::UsdPrim(PXR_NS::UsdPrimDefinition::*)(
               PXR_NS::UsdPrim const&, PXR_NS::TfToken const& name,
               PXR_NS::SdfSpecifier) const) &
               PXR_NS::UsdPrimDefinition::FlattenTo,
           "FlattenTo_prim_under_parent")
        .m((PXR_NS::UsdPrim(PXR_NS::UsdPrimDefinition::*)(
               PXR_NS::UsdPrim const&, PXR_NS::SdfSpecifier) const) &
               PXR_NS::UsdPrimDefinition::FlattenTo,
           "FlattenTo_prim");

    bbl::Class<PXR_NS::Usd_PrimFlagsPredicate>("PrimFlagsPredicate");

    bbl::Class<PXR_NS::UsdPrimRange>("PrimRange")
        .opaque_ptr()
        .ctor(bbl::Ctor<PrimRange, Prim>("start"), "from_prim")
        .m(&PrimRange::begin)
        .m(&PrimRange::end);

    bbl::Class<PXR_NS::UsdPrimRange::iterator>("PrimRangeIterator")
        .opaque_ptr()
        .ctor(bbl::Ctor<PrimRangeIterator>(), "new")
        .m(&PrimRangeIterator::operator++, "op_inc")
        .m((PrimRangeIterator &
            (PrimRangeIterator::*)(PrimRangeIterator const&)) &
               PrimRangeIterator::operator=,
           "op_assign")
        .m((bool(PrimRangeIterator::*)(PrimRangeIterator const&) const) &
               PrimRangeIterator::operator==,
           "op_eq")
        .m(&PrimRangeIterator::operator*, "deref");

    bbl::Class<PXR_NS::UsdPrimSiblingRange>("PrimSiblingRange")
        .m(&PXR_NS::UsdPrimSiblingRange::begin)
        .m(&PXR_NS::UsdPrimSiblingRange::end);

    bbl::Class<PXR_NS::UsdPrimSiblingIterator>("PrimSiblingIterator")
        .m(&PXR_NS::UsdPrimSiblingIterator::operator*, "deref")
        .m(&PXR_NS::UsdPrimSiblingIterator::operator++, "op_inc");

    bbl::Class<PXR_NS::UsdPrimSubtreeRange>("PrimSubtreeRange")
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
}

#endif