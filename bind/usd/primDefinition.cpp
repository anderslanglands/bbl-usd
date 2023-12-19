#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/primDefinition.h>

BBL_MODULE(usd) {
    // clang-format off

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

}

#endif

