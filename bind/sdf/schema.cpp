#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/schema.h>
#include <pxr/base/js/value.h>

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfSchemaBase>()
        .m(&PXR_NS::SdfSchemaBase::GetFieldDefinition)
        .m(&PXR_NS::SdfSchemaBase::GetSpecDefinition)
        .m(&PXR_NS::SdfSchemaBase::IsRegistered)
        .m(&PXR_NS::SdfSchemaBase::HoldsChildren)
        .m(&PXR_NS::SdfSchemaBase::GetFallback)
        .m(&PXR_NS::SdfSchemaBase::CastToTypeOf)
        .m(&PXR_NS::SdfSchemaBase::IsValidFieldForSpec)
        .m(&PXR_NS::SdfSchemaBase::GetFields)
        .m(&PXR_NS::SdfSchemaBase::GetMetadataFields)
        .m(&PXR_NS::SdfSchemaBase::GetMetadataFieldDisplayGroup)
        .m(&PXR_NS::SdfSchemaBase::GetRequiredFields)
        .m(&PXR_NS::SdfSchemaBase::IsRequiredFieldName)
        .m(&PXR_NS::SdfSchemaBase::IsValidAttributeConnectionPath)
        .m(&PXR_NS::SdfSchemaBase::IsValidIdentifier)
        .m(&PXR_NS::SdfSchemaBase::IsValidNamespacedIdentifier)
        .m(&PXR_NS::SdfSchemaBase::IsValidInheritPath)
        .m(&PXR_NS::SdfSchemaBase::IsValidPayload)
        .m(&PXR_NS::SdfSchemaBase::IsValidReference)
        .m(&PXR_NS::SdfSchemaBase::IsValidRelationshipTargetPath)
        .m(&PXR_NS::SdfSchemaBase::IsValidRelocatesPath)
        .m(&PXR_NS::SdfSchemaBase::IsValidSpecializesPath)
        .m(&PXR_NS::SdfSchemaBase::IsValidSubLayer)
        .m(&PXR_NS::SdfSchemaBase::IsValidVariantIdentifier)
        .m(&PXR_NS::SdfSchemaBase::IsValidVariantSelection)
        .m(&PXR_NS::SdfSchemaBase::IsValidValue)
        .m(&PXR_NS::SdfSchemaBase::GetAllTypes)
        .m((PXR_NS::SdfValueTypeName (PXR_NS::SdfSchemaBase::*)(const PXR_NS::TfToken &) const)
            &PXR_NS::SdfSchemaBase::FindType, "FindType_00")
        .m((PXR_NS::SdfValueTypeName (PXR_NS::SdfSchemaBase::*)(const char *) const)
            &PXR_NS::SdfSchemaBase::FindType, "FindType_01")
        .m((PXR_NS::SdfValueTypeName (PXR_NS::SdfSchemaBase::*)(const std::string &) const)
            &PXR_NS::SdfSchemaBase::FindType, "FindType_02")
        .m((PXR_NS::SdfValueTypeName (PXR_NS::SdfSchemaBase::*)(const PXR_NS::TfType &, const PXR_NS::TfToken &) const)
            &PXR_NS::SdfSchemaBase::FindType, "FindType_03")
        .m((PXR_NS::SdfValueTypeName (PXR_NS::SdfSchemaBase::*)(const PXR_NS::VtValue &, const PXR_NS::TfToken &) const)
            &PXR_NS::SdfSchemaBase::FindType, "FindType_04")
        .m(&PXR_NS::SdfSchemaBase::FindOrCreateType)
    ;

    bbl::Class<PXR_NS::SdfSchemaBase::FieldDefinition>()
    #if 0 /// XXX: These are failing to link
        .ctor(bbl::Class<PXR_NS::SdfSchemaBase::FieldDefinition>::Ctor<const PXR_NS::SdfSchemaBase &, const PXR_NS::TfToken &, const PXR_NS::VtValue &>("schema", "name", "fallbackValue"), "ctor")
        .m(&PXR_NS::SdfSchemaBase::FieldDefinition::GetName)
        .m(&PXR_NS::SdfSchemaBase::FieldDefinition::GetFallbackValue)
        .m(&PXR_NS::SdfSchemaBase::FieldDefinition::GetInfo)
        .m(&PXR_NS::SdfSchemaBase::FieldDefinition::IsPlugin)
        .m(&PXR_NS::SdfSchemaBase::FieldDefinition::IsReadOnly)
        .m(&PXR_NS::SdfSchemaBase::FieldDefinition::HoldsChildren)
        /** TODO: instantiate this template
        .m(&PXR_NS::SdfSchemaBase::FieldDefinition::IsValidValue)
        */
        /** TODO: instantiate this template
        .m(&PXR_NS::SdfSchemaBase::FieldDefinition::IsValidListValue)
        */
        /** TODO: instantiate this template
        .m(&PXR_NS::SdfSchemaBase::FieldDefinition::IsValidMapKey)
        */
        /** TODO: instantiate this template
        .m(&PXR_NS::SdfSchemaBase::FieldDefinition::IsValidMapValue)
        */
        .m(&PXR_NS::SdfSchemaBase::FieldDefinition::FallbackValue)
        .m(&PXR_NS::SdfSchemaBase::FieldDefinition::Plugin)
        .m(&PXR_NS::SdfSchemaBase::FieldDefinition::Children)
        .m(&PXR_NS::SdfSchemaBase::FieldDefinition::ReadOnly)
        .m(&PXR_NS::SdfSchemaBase::FieldDefinition::AddInfo)
        // Requires C-style function pointer with C++ types
        // will need to write dedicated wrapper
        // .m(&PXR_NS::SdfSchemaBase::FieldDefinition::ValueValidator)
        // .m(&PXR_NS::SdfSchemaBase::FieldDefinition::ListValueValidator)
        // .m(&PXR_NS::SdfSchemaBase::FieldDefinition::MapKeyValidator)
        // .m(&PXR_NS::SdfSchemaBase::FieldDefinition::MapValueValidator)
    #endif
    ;

    bbl::Class<PXR_NS::SdfSchemaBase::SpecDefinition>()
        .m(&PXR_NS::SdfSchemaBase::SpecDefinition::GetFields)
        .m(&PXR_NS::SdfSchemaBase::SpecDefinition::GetRequiredFields)
        .m(&PXR_NS::SdfSchemaBase::SpecDefinition::GetMetadataFields)
        .m(&PXR_NS::SdfSchemaBase::SpecDefinition::IsValidField)
        .m(&PXR_NS::SdfSchemaBase::SpecDefinition::IsMetadataField)
        .m(&PXR_NS::SdfSchemaBase::SpecDefinition::GetMetadataFieldDisplayGroup)
        .m(&PXR_NS::SdfSchemaBase::SpecDefinition::IsRequiredField)
    ;

    bbl::Class<PXR_NS::SdfSchema>()
        .m(&PXR_NS::SdfSchema::GetInstance)
    ;


    bbl::Class<PXR_NS::SdfSchemaBase::FieldDefinition::InfoVec>("SchemaBaseFieldDefinitionInfoVec")
        BBL_STD_VECTOR_METHODS((std::pair<PXR_NS::TfToken, PXR_NS::JsValue>))
    ;

}

#endif


