#if defined(__clang__)

#include <babble-std>
#include <babble>


#include <pxr/usd/usd/schemaRegistry.h>

namespace bblext {

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

} // namespace bblext

BBL_MODULE(usd) {
    // clang-format off

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

}

#endif


