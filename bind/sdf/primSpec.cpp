#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/primSpec.h>

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfPrimSpec>("PrimSpec")
        // Namespace hierarchy
        .m(&PXR_NS::SdfPrimSpec::GetNameRoot)
        .m(&PXR_NS::SdfPrimSpec::GetNameParent)
        .m(&PXR_NS::SdfPrimSpec::GetRealNameParent)
        .m(&PXR_NS::SdfPrimSpec::GetNameChildren)
        .m(&PXR_NS::SdfPrimSpec::SetNameChildren)
        .m(&PXR_NS::SdfPrimSpec::InsertNameChild)
        .m(&PXR_NS::SdfPrimSpec::RemoveNameChild)
        .m(&PXR_NS::SdfPrimSpec::GetNameChildrenOrder)
        .m(&PXR_NS::SdfPrimSpec::HasNameChildrenOrder)
        .m(&PXR_NS::SdfPrimSpec::SetNameChildrenOrder)
        .m(&PXR_NS::SdfPrimSpec::InsertInNameChildrenOrder)
        .m(&PXR_NS::SdfPrimSpec::RemoveFromNameChildrenOrder)
        .m(&PXR_NS::SdfPrimSpec::RemoveFromNameChildrenOrderByIndex)
        .m(&PXR_NS::SdfPrimSpec::ApplyNameChildrenOrder)

        // Properties
        .m(&PXR_NS::SdfPrimSpec::GetProperties)
        .m(&PXR_NS::SdfPrimSpec::SetProperties)
        .m(&PXR_NS::SdfPrimSpec::InsertProperty)
        .m(&PXR_NS::SdfPrimSpec::RemoveProperty)
        .m(&PXR_NS::SdfPrimSpec::GetAttributes)
        .m(&PXR_NS::SdfPrimSpec::GetRelationships)
        .m(&PXR_NS::SdfPrimSpec::GetPropertyOrder)
        .m(&PXR_NS::SdfPrimSpec::HasPropertyOrder)
        .m(&PXR_NS::SdfPrimSpec::SetPropertyOrder)
        .m(&PXR_NS::SdfPrimSpec::InsertInPropertyOrder)
        .m(&PXR_NS::SdfPrimSpec::RemoveFromPropertyOrder)
        .m(&PXR_NS::SdfPrimSpec::RemoveFromPropertyOrderByIndex)
        .m(&PXR_NS::SdfPrimSpec::ApplyPropertyOrder)

        // Lookup
        .m(&PXR_NS::SdfPrimSpec::GetObjectAtPath)
        .m(&PXR_NS::SdfPrimSpec::GetPrimAtPath)
        .m(&PXR_NS::SdfPrimSpec::GetPropertyAtPath)
        .m(&PXR_NS::SdfPrimSpec::GetAttributeAtPath)
        .m(&PXR_NS::SdfPrimSpec::GetRelationshipAtPath)

        // Metadata
        .m(&PXR_NS::SdfPrimSpec::GetTypeName)
        .m(&PXR_NS::SdfPrimSpec::SetTypeName)
        .m(&PXR_NS::SdfPrimSpec::GetComment)
        .m(&PXR_NS::SdfPrimSpec::SetComment)
        .m(&PXR_NS::SdfPrimSpec::GetDocumentation)
        .m(&PXR_NS::SdfPrimSpec::SetDocumentation)
        .m(&PXR_NS::SdfPrimSpec::GetActive)
        .m(&PXR_NS::SdfPrimSpec::SetActive)
        .m(&PXR_NS::SdfPrimSpec::HasActive)
        .m(&PXR_NS::SdfPrimSpec::ClearActive)
        .m(&PXR_NS::SdfPrimSpec::GetHidden)
        .m(&PXR_NS::SdfPrimSpec::SetHidden)
        .m(&PXR_NS::SdfPrimSpec::GetKind)
        .m(&PXR_NS::SdfPrimSpec::SetKind)
        .m(&PXR_NS::SdfPrimSpec::HasKind)
        .m(&PXR_NS::SdfPrimSpec::ClearKind)
        .m(&PXR_NS::SdfPrimSpec::GetSymmetryFunction)
        .m(&PXR_NS::SdfPrimSpec::SetSymmetryFunction)
        .m(&PXR_NS::SdfPrimSpec::GetSymmetricPeer)
        .m(&PXR_NS::SdfPrimSpec::SetSymmetricPeer)
        .m(&PXR_NS::SdfPrimSpec::GetPrefix)
        .m(&PXR_NS::SdfPrimSpec::SetPrefix)
        .m(&PXR_NS::SdfPrimSpec::GetSuffix)
        .m(&PXR_NS::SdfPrimSpec::SetSuffix)
        .m(&PXR_NS::SdfPrimSpec::GetCustomData)
        .m(&PXR_NS::SdfPrimSpec::SetCustomData)
        .m(&PXR_NS::SdfPrimSpec::GetAssetInfo)
        .m(&PXR_NS::SdfPrimSpec::SetAssetInfo)
        .m(&PXR_NS::SdfPrimSpec::GetSpecifier)
        .m(&PXR_NS::SdfPrimSpec::SetSpecifier)
        .m(&PXR_NS::SdfPrimSpec::GetPermission)
        .m(&PXR_NS::SdfPrimSpec::SetPermission)
        .m(&PXR_NS::SdfPrimSpec::GetPrefixSubstitutions)
        .m(&PXR_NS::SdfPrimSpec::SetPrefixSubstitutions)
        .m(&PXR_NS::SdfPrimSpec::GetSuffixSubstitutions)
        .m(&PXR_NS::SdfPrimSpec::SetSuffixSubstitutions)
        .m(&PXR_NS::SdfPrimSpec::GetInstanceable)
        .m(&PXR_NS::SdfPrimSpec::SetInstanceable)
        .m(&PXR_NS::SdfPrimSpec::HasInstanceable)
        .m(&PXR_NS::SdfPrimSpec::ClearInstanceable)

        // Payloads
        .m(&PXR_NS::SdfPrimSpec::GetPayloadList)
        .m(&PXR_NS::SdfPrimSpec::HasPayloads)
        .m(&PXR_NS::SdfPrimSpec::ClearPayloadList)

        // Inherits
        .m(&PXR_NS::SdfPrimSpec::GetInheritPathList)
        .m(&PXR_NS::SdfPrimSpec::HasInheritPaths)
        .m(&PXR_NS::SdfPrimSpec::ClearInheritPathList)

        // Specializes
        .m(&PXR_NS::SdfPrimSpec::GetSpecializesList)
        .m(&PXR_NS::SdfPrimSpec::HasSpecializes)
        .m(&PXR_NS::SdfPrimSpec::ClearSpecializesList)

        // References
        .m(&PXR_NS::SdfPrimSpec::GetReferenceList)
        .m(&PXR_NS::SdfPrimSpec::HasReferences)
        .m(&PXR_NS::SdfPrimSpec::ClearReferenceList)

        // Variant sets
        .m(&PXR_NS::SdfPrimSpec::GetVariantSetNameList)
        .m(&PXR_NS::SdfPrimSpec::HasVariantSetNames)
        .m(&PXR_NS::SdfPrimSpec::GetVariantNames)
        .m(&PXR_NS::SdfPrimSpec::RemoveVariantSet)
        .m(&PXR_NS::SdfPrimSpec::GetVariantSelections)
        .m(&PXR_NS::SdfPrimSpec::BlockVariantSelection)

        // Relocates
        .m(&PXR_NS::SdfPrimSpec::GetRelocates)
        .m(&PXR_NS::SdfPrimSpec::SetRelocates)
        .m(&PXR_NS::SdfPrimSpec::HasRelocates)
        .m(&PXR_NS::SdfPrimSpec::ClearRelocates)

        // static
        // spec creation
        .m((PXR_NS::SdfPrimSpecHandle (*)(PXR_NS::SdfLayerHandle const&, std::string const&, PXR_NS::SdfSpecifier, std::string const&))
            &PXR_NS::SdfPrimSpec::New)
        .m((PXR_NS::SdfPrimSpecHandle (*)(PXR_NS::SdfPrimSpecHandle const&, std::string const&, PXR_NS::SdfSpecifier, std::string const&))
            &PXR_NS::SdfPrimSpec::New, "New_under_parent")

        // name
        .m(&PXR_NS::SdfPrimSpec::IsValidName)
        .m(&PXR_NS::SdfPrimSpec::GetName)
        .m(&PXR_NS::SdfPrimSpec::GetNameToken)
        .m(&PXR_NS::SdfPrimSpec::CanSetName)
        .m(&PXR_NS::SdfPrimSpec::SetName)

    ;

    bbl::Class<PXR_NS::SdfPrimSpecHandle>("PrimSpecHandle")
        .smartptr_to<PXR_NS::SdfPrimSpec>()
    ;

    bbl::Class<PXR_NS::SdfPrimSpecHandleVector>("PrimSpecHandleVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfPrimSpecHandle)
    ;

    bbl::Class<std::pair<PXR_NS::SdfPrimSpecHandle, PXR_NS::SdfLayerOffset>>("PrimSpecHandleOffsetPair")
    ;

    bbl::Class<std::vector<std::pair<PXR_NS::SdfPrimSpecHandle, PXR_NS::SdfLayerOffset>>>("PrimSpecHandleOffsetPairVector")
        BBL_STD_VECTOR_METHODS((std::pair<PXR_NS::SdfPrimSpecHandle, PXR_NS::SdfLayerOffset>))
    ;

    bbl::Class<PXR_NS::SdfPrimSpecView>("PrimSpecView");

}

#endif


