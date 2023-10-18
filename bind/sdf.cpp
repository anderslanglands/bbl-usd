#if defined(__clang__)

#include "babble"
#include "babble-std"

#include <pxr/base/js/types.h>
#include <pxr/base/js/value.h>
#include <pxr/base/tf/token.h>
#include <pxr/base/vt/array.h>
#include <pxr/base/vt/dictionary.h>
#include <pxr/base/vt/value.h>
#include <pxr/usd/sdf/allowed.h>
#include <pxr/usd/sdf/assetPath.h>
#include <pxr/usd/sdf/attributeSpec.h>
#include <pxr/usd/sdf/changeBlock.h>
#include <pxr/usd/sdf/changeList.h>
#include <pxr/usd/sdf/declareHandles.h>
#include <pxr/usd/sdf/fileFormat.h>
#include <pxr/usd/sdf/layer.h>
#include <pxr/usd/sdf/layerOffset.h>
#include <pxr/usd/sdf/layerTree.h>
#include <pxr/usd/sdf/listEditorProxy.h>
#include <pxr/usd/sdf/namespaceEdit.h>
#include <pxr/usd/sdf/notice.h>
#include <pxr/usd/sdf/path.h>
#include <pxr/usd/sdf/pathExpression.h>
#include <pxr/usd/sdf/payload.h>
#include <pxr/usd/sdf/primSpec.h>
#include <pxr/usd/sdf/propertySpec.h>
#include <pxr/usd/sdf/proxyTypes.h>
#include <pxr/usd/sdf/reference.h>
#include <pxr/usd/sdf/relationshipSpec.h>
#include <pxr/usd/sdf/schema.h>
#include <pxr/usd/sdf/spec.h>
#include <pxr/usd/sdf/textFileFormat.h>
#include <pxr/usd/sdf/timeCode.h>
#include <pxr/usd/sdf/types.h>
#include <pxr/usd/sdf/valueTypeName.h>
#include <pxr/usd/sdf/variableExpression.h>
#include <pxr/usd/sdf/variantSetSpec.h>
#include <pxr/usd/sdf/variantSpec.h>

namespace bblext {

char const* AssetPath_GetAssetPath(PXR_NS::SdfAssetPath const& path) {
    return path.GetAssetPath().c_str();
}

char const* AssetPath_GetResolvedPath(PXR_NS::SdfAssetPath const& path) {
    return path.GetResolvedPath().c_str();
}

PXR_NS::SdfPath const&
NamespaceEdit_get_current_path(PXR_NS::SdfNamespaceEdit const& edit) {
    return edit.currentPath;
}

PXR_NS::SdfPath const&
NamespaceEdit_get_new_path(PXR_NS::SdfNamespaceEdit const& edit) {
    return edit.newPath;
}

PXR_NS::SdfNamespaceEdit::Index const&
NamespaceEdit_get_index(PXR_NS::SdfNamespaceEdit const& edit) {
    return edit.index;
}

PXR_NS::SdfNamespaceEditDetail::Result
NamespaceEditDetail_get_result(PXR_NS::SdfNamespaceEditDetail const& detail) {
    return detail.result;
}

PXR_NS::SdfNamespaceEdit const&
NamespaceEditDetail_get_edit(PXR_NS::SdfNamespaceEditDetail const& detail) {
    return detail.edit;
}

char const*
NamespaceEditDetail_get_reason(PXR_NS::SdfNamespaceEditDetail const& detail) {
    return detail.reason.c_str();
}

PXR_NS::SdfPathExpression*
PathExpression_from_string(char const* expr, char const* parseContext) {
    return new PXR_NS::SdfPathExpression(expr, parseContext);
}

PXR_NS::SdfPayload* Payload_from_asset_path(char const* assetPath) {
    return new PXR_NS::SdfPayload(assetPath);
}

PXR_NS::SdfPayload*
Payload_from_asset_path_and_prim_path(char const* assetPath,
                                      PXR_NS::SdfPath const& primPath) {
    return new PXR_NS::SdfPayload(assetPath, primPath);
}

PXR_NS::SdfPayload* Payload_from_asset_path_and_prim_path_and_layer_offset(
    char const* assetPath, PXR_NS::SdfPath const& primPath,
    PXR_NS::SdfLayerOffset const& layerOffset) {
    return new PXR_NS::SdfPayload(assetPath, primPath, layerOffset);
}

PXR_NS::SdfReference* Reference_from_asset_path(char const* assetPath) {
    return new PXR_NS::SdfReference(assetPath);
}

PXR_NS::SdfReference*
Reference_from_asset_path_and_prim_path(char const* assetPath,
                                        PXR_NS::SdfPath const& primPath) {
    return new PXR_NS::SdfReference(assetPath, primPath);
}

PXR_NS::SdfReference* Reference_from_asset_path_and_prim_path_and_layer_offset(
    char const* assetPath, PXR_NS::SdfPath const& primPath,
    PXR_NS::SdfLayerOffset const& layerOffset) {
    return new PXR_NS::SdfReference(assetPath, primPath, layerOffset);
}

PXR_NS::SdfReference*
Reference_from_asset_path_and_prim_path_and_layer_offset_and_custom_data(
    char const* assetPath, PXR_NS::SdfPath const& primPath,
    PXR_NS::SdfLayerOffset const& layerOffset,
    PXR_NS::VtDictionary const& customData) {
    return new PXR_NS::SdfReference(assetPath, primPath, layerOffset,
                                    customData);
}

char const* ValueTypeName_GetCPPTypeName(PXR_NS::SdfValueTypeName const& vtn) {
    return vtn.GetCPPTypeName().c_str();
}

PXR_NS::SdfVariableExpression* VariableExpression_from_string(char const* str) {
    return new PXR_NS::SdfVariableExpression(str);
}

char const*
VariableExpression_GetString(PXR_NS::SdfVariableExpression const& ve) {
    return ve.GetString().c_str();
}

PXR_NS::VtValue const& VariableExpressionResult_value(
    PXR_NS::SdfVariableExpression::Result const& ver) {
    return ver.value;
}

} // namespace bblext

BBL_MODULE(sdf) {

    // clang-format off

    // Probably don't want to bind SdfAbstractData*?

    bbl::Class<PXR_NS::SdfAllowed>("Allowed")
        .ctor(bbl::Ctor<PXR_NS::SdfAllowed>(), "new")
        .ctor(bbl::Ctor<PXR_NS::SdfAllowed, bool>(), "from_bool")
        .ctor(bbl::Ctor<PXR_NS::SdfAllowed, char const*>(), "from_string")
        .ctor(bbl::Ctor<PXR_NS::SdfAllowed, bool, char const*>(),
              "from_bool_and_string")
        .m(&PXR_NS::SdfAllowed::IsAllowed);

    bbl::Class<PXR_NS::SdfAssetPath>("AssetPath")
        .ctor(bbl::Ctor<PXR_NS::SdfAssetPath>(), "new");

    // we bind specific wrapper functions for these as there's no point
    // generating an intermediary string&
    bbl::fn(&bblext::AssetPath_GetAssetPath);
    bbl::fn(&bblext::AssetPath_GetResolvedPath);

    bbl::Class<PXR_NS::VtArray<PXR_NS::SdfAssetPath>>("AssetPathArray");

#define SPEC_METHODS(CLS)                                                      \
    .m(&CLS::GetSchema)                                                        \
        .m(&CLS::GetSpecType)                                                  \
        .m(&CLS::IsDormant)                                                    \
        .m(&CLS::GetLayer)                                                     \
        .m(&CLS::GetPath)                                                      \
        .m(&CLS::PermissionToEdit)                                             \
        .m(&CLS::ListInfoKeys)                                                 \
        .m(&CLS::GetMetaDataInfoKeys)                                          \
        .m(&CLS::GetMetaDataDisplayGroup)                                      \
        .m(&CLS::GetInfo)                                                      \
        .m(&CLS::SetInfo)                                                      \
        .m(&CLS::SetInfoDictionaryValue)                                       \
        .m(&CLS::HasInfo)                                                      \
        .m(&CLS::ClearInfo)                                                    \
        .m(&CLS::GetTypeForInfo)                                               \
        .m(&CLS::GetFallbackForInfo)                                           \
        .m(&CLS::IsInert)                                                      \
        .m(&CLS::ListFields)                                                   \
        .m((bool(CLS::*)(PXR_NS::TfToken const&) const) & CLS::HasField)       \
        .m(&CLS::GetField)                                                     \
        .m((bool(CLS::*)(PXR_NS::TfToken const&, PXR_NS::VtValue const&)) &    \
           CLS::SetField)                                                      \
        .m(&CLS::operator==, "op_eq")

#define PROPERTYSPEC_METHODS(CLS)                                              \
    .m(&CLS::GetOwner)                                                         \
        .m(&CLS::GetCustomData)                                                \
        .m(&CLS::GetAssetInfo)                                                 \
        .m(&CLS::SetCustomData)                                                \
        .m(&CLS::SetAssetInfo)                                                 \
        .m(&CLS::GetDisplayGroup)                                              \
        .m(&CLS::SetDisplayGroup)                                              \
        .m(&CLS::GetDisplayName)                                               \
        .m(&CLS::SetDisplayName)                                               \
        .m(&CLS::GetDocumentation)                                             \
        .m(&CLS::SetDocumentation)                                             \
        .m(&CLS::GetHidden)                                                    \
        .m(&CLS::SetHidden)                                                    \
        .m(&CLS::GetPermission)                                                \
        .m(&CLS::SetPermission)                                                \
        .m(&CLS::GetPrefix)                                                    \
        .m(&CLS::SetPrefix)                                                    \
        .m(&CLS::GetSuffix)                                                    \
        .m(&CLS::SetSuffix)                                                    \
        .m(&CLS::GetSymmetricPeer)                                             \
        .m(&CLS::SetSymmetricPeer)                                             \
        .m(&CLS::GetSymmetryArguments)                                         \
        .m(&CLS::SetSymmetryArgument)                                          \
        .m(&CLS::GetSymmetryFunction)                                          \
        .m(&CLS::SetSymmetryFunction)                                          \
        .m(&CLS::GetTimeSampleMap)                                             \
        .m(&CLS::GetValueType)                                                 \
        .m(&CLS::GetTypeName)                                                  \
        .m(&CLS::GetDefaultValue)                                              \
        .m(&CLS::SetDefaultValue)                                              \
        .m(&CLS::HasDefaultValue)                                              \
        .m(&CLS::ClearDefaultValue)                                            \
        .m(&CLS::GetComment)                                                   \
        .m(&CLS::SetComment)                                                   \
        .m(&CLS::IsCustom)                                                     \
        .m(&CLS::SetCustom)                                                    \
        .m(&CLS::GetVariability)                                               \
        .m(&CLS::HasOnlyRequiredFields)                                        \
        .m(&CLS::GetName)                                                      \
        .m(&CLS::GetNameToken)                                                 \
        .m(&CLS::CanSetName)                                                   \
        .m(&CLS::SetName)                                                      \
        .m(&CLS::IsValidName)

    bbl::Class<PXR_NS::SdfAttributeSpec>("AttributeSpec")
        .m(&PXR_NS::SdfAttributeSpec::New)
        .m(&PXR_NS::SdfAttributeSpec::HasConnectionPaths)
        .m(&PXR_NS::SdfAttributeSpec::ClearConnectionPaths)
        .m(&PXR_NS::SdfAttributeSpec::GetAllowedTokens)
        .m(&PXR_NS::SdfAttributeSpec::HasAllowedTokens)
        .m(&PXR_NS::SdfAttributeSpec::SetAllowedTokens)
        .m(&PXR_NS::SdfAttributeSpec::GetConnectionPathList)
        .m(&PXR_NS::SdfAttributeSpec::ClearAllowedTokens)
        .m(&PXR_NS::SdfAttributeSpec::GetDisplayUnit)
        .m(&PXR_NS::SdfAttributeSpec::SetDisplayUnit)
        .m(&PXR_NS::SdfAttributeSpec::HasDisplayUnit)
        .m(&PXR_NS::SdfAttributeSpec::ClearDisplayUnit)
        .m(&PXR_NS::SdfAttributeSpec::GetColorSpace)
        .m(&PXR_NS::SdfAttributeSpec::SetColorSpace)
        .m(&PXR_NS::SdfAttributeSpec::HasColorSpace)
        .m(&PXR_NS::SdfAttributeSpec::ClearColorSpace)
        .m(&PXR_NS::SdfAttributeSpec::GetRoleName)

        PROPERTYSPEC_METHODS(PXR_NS::SdfAttributeSpec)
        SPEC_METHODS(PXR_NS::SdfAttributeSpec)
        ;

    // XXX: figure this mess out
    #define HANDLE_METHODS(CLS) 

    bbl::Class<PXR_NS::SdfAttributeSpecHandle>("AttributeSpecHandle")
        HANDLE_METHODS(PXR_NS::SdfAttributeSpecHandle)
        ;

    bbl::Class<PXR_NS::SdfAttributeSpecHandleVector>("AttributeSpecHandleVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfAttributeSpecHandle)
        ;

    
    bbl::Class<PXR_NS::SdfAttributeSpecView>("AttributeSpecView");

    bbl::Class<PXR_NS::SdfBatchNamespaceEdit>("BatchNamespaceEdit")
        .ctor(bbl::Ctor<PXR_NS::SdfBatchNamespaceEdit>(), "new")
        .m((void (PXR_NS::SdfBatchNamespaceEdit::*)(PXR_NS::SdfNamespaceEdit const&))
            &PXR_NS::SdfBatchNamespaceEdit::Add)
        .m((void (PXR_NS::SdfBatchNamespaceEdit::*)(PXR_NS::SdfNamespaceEdit::Path const&, PXR_NS::SdfNamespaceEdit::Path const&, PXR_NS::SdfNamespaceEdit::Index))
            &PXR_NS::SdfBatchNamespaceEdit::Add,"Add_from_paths")
        .m(&PXR_NS::SdfBatchNamespaceEdit::GetEdits)
        ;

    bbl::Class<PXR_NS::SdfChangeBlock>("ChangeBlock")
        .ctor(bbl::Ctor<PXR_NS::SdfChangeBlock>(), "new")
        ;

    bbl::Class<PXR_NS::SdfChangeList>("ChangeList")
        .ctor(bbl::Ctor<PXR_NS::SdfChangeList>(), "new")
        // XXX: Getting link errors with these
        // .m(&PXR_NS::SdfChangeList::DidReplaceLayerContent)
        // .m(&PXR_NS::SdfChangeList::DidReloadLayerContent)
        // .m(&PXR_NS::SdfChangeList::DidChangeLayerResolvedPath)
        // .m(&PXR_NS::SdfChangeList::DidChangeLayerIdentifier)
        // .m(&PXR_NS::SdfChangeList::DidChangeSublayerPaths)
        // .m(&PXR_NS::SdfChangeList::DidAddPrim)
        // .m(&PXR_NS::SdfChangeList::DidRemovePrim)
        // .m(&PXR_NS::SdfChangeList::DidReorderPrims)
        // .m(&PXR_NS::SdfChangeList::DidChangePrimName)
        // .m(&PXR_NS::SdfChangeList::DidChangePrimVariantSets)
        // .m(&PXR_NS::SdfChangeList::DidChangePrimInheritPaths)
        // .m(&PXR_NS::SdfChangeList::DidChangePrimReferences)
        // .m(&PXR_NS::SdfChangeList::DidChangePrimSpecializes)
        // .m(&PXR_NS::SdfChangeList::DidAddProperty)
        // .m(&PXR_NS::SdfChangeList::DidRemoveProperty)
        // .m(&PXR_NS::SdfChangeList::DidReorderProperties)
        // .m(&PXR_NS::SdfChangeList::DidChangePropertyName)
        // .m(&PXR_NS::SdfChangeList::DidChangeAttributeTimeSamples)
        // .m(&PXR_NS::SdfChangeList::DidChangeAttributeConnection)
        // .m(&PXR_NS::SdfChangeList::DidChangeRelationshipTargets)
        // .m(&PXR_NS::SdfChangeList::DidAddTarget)
        // .m(&PXR_NS::SdfChangeList::DidRemoveTarget)
        // XXX: R-Value reference in here. Need to sort that out
        // .m(&PXR_NS::SdfChangeList::DidChangeInfo)
        .m(&PXR_NS::SdfChangeList::GetEntryList)
        .m(&PXR_NS::SdfChangeList::GetEntry)
        .m(&PXR_NS::SdfChangeList::FindEntry)
        ;

    bbl::Class<PXR_NS::SdfChangeList::Entry>("ChangeListEntry")
        .ctor(bbl::Ctor<PXR_NS::SdfChangeList::Entry>(), "new")
        ;

    bbl::Class<std::pair<PXR_NS::SdfPath, PXR_NS::SdfChangeList::Entry>>("PathChangeListEntryPair")
        ;

    bbl::Class<PXR_NS::SdfChangeList::EntryList>("ChangeListEntryList")
        ;

    bbl::Enum<PXR_NS::SdfChangeList::SubLayerChangeType>("ChangleListSubLayerChangeType")
    ;

    bbl::Class<PXR_NS::SdfDictionaryProxy>("DictionaryProxy");

    #define FILEFORMAT_METHODS(CLS) \
        .m(&CLS::GetSchema) \
        .m(&CLS::GetFormatId) \
        .m(&CLS::GetTarget) \
        .m(&CLS::GetFileCookie) \
        .m(&CLS::GetVersionString) \
        .m(&CLS::IsPrimaryFormatForExtensions) \
        .m(&CLS::GetFileExtensions) \
        .m(&CLS::GetPrimaryFileExtension) \
        .m(&CLS::IsSupportedExtension) \
        .m(&CLS::IsPackage) \
        .m(&CLS::GetPackageRootLayerPath) \
        .m(&CLS::ShouldSkipAnonymousReload) \
        .m(&CLS::ShouldReadAnonymousLayers) \
        .m(&CLS::ReadDetached) \
        .m(&CLS::GetExternalAssetDependencies) \
        .m(&CLS::SupportsReading) \
        .m(&CLS::SupportsWriting) \
        .m(&CLS::SupportsEditing) \
        .m(&CLS::GetFileExtension) \
        .m(&CLS::FindAllFileFormatExtensions) \
        .m(&CLS::FindAllDerivedFileFormatExtensions) \
        .m(&CLS::FormatSupportsReading) \
        .m(&CLS::FormatSupportsWriting) \
        .m(&CLS::FormatSupportsEditing) \
        .m(&CLS::CanRead) \
        .m(&CLS::Read) \
        .m(&CLS::WriteToFile) \
        .m(&CLS::ReadFromString) \
        .m(&CLS::WriteToString) \


    bbl::Class<PXR_NS::SdfFileFormat>("FileFormat")
        FILEFORMAT_METHODS(PXR_NS::SdfFileFormat)
    ;

    bbl::Class<PXR_NS::SdfInheritsProxy>("InheritsProxy");

    bbl::Class<PXR_NS::SdfLayer::FileFormatArguments>(
        "LayerFileFormatArguments");

    bbl::Class<PXR_NS::SdfLayer>("Layer")
        // External References
        .m(&PXR_NS::SdfLayer::GetExternalReferences)
        .m(&PXR_NS::SdfLayer::UpdateExternalReference)
        .m(&PXR_NS::SdfLayer::GetCompositionAssetDependencies)
        .m(&PXR_NS::SdfLayer::UpdateCompositionAssetDependency)
        .m(&PXR_NS::SdfLayer::GetExternalAssetDependencies)

        // Fields
        .m(&PXR_NS::SdfLayer::GetSpecType)
        .m(&PXR_NS::SdfLayer::HasSpec)
        .m(&PXR_NS::SdfLayer::ListFields)
        .m((bool (PXR_NS::SdfLayer::*)(PXR_NS::SdfPath const&, PXR_NS::TfToken const&, PXR_NS::VtValue*) const)
            &PXR_NS::SdfLayer::HasField)
        .m((bool (PXR_NS::SdfLayer::*)(PXR_NS::SdfPath const&, PXR_NS::TfToken const&, PXR_NS::TfToken const&, PXR_NS::VtValue*) const)
            &PXR_NS::SdfLayer::HasFieldDictKey)
        .m(&PXR_NS::SdfLayer::GetField)
        .m(&PXR_NS::SdfLayer::GetFieldDictValueByKey)
        .m((void (PXR_NS::SdfLayer::*)(PXR_NS::SdfPath const&, PXR_NS::TfToken const&, PXR_NS::VtValue const&))
            &PXR_NS::SdfLayer::SetField)
        .m((void (PXR_NS::SdfLayer::*)(PXR_NS::SdfPath const&, PXR_NS::TfToken const&, PXR_NS::TfToken const&, PXR_NS::VtValue const&))
            &PXR_NS::SdfLayer::SetFieldDictValueByKey)
        .m(&PXR_NS::SdfLayer::EraseField)
        .m(&PXR_NS::SdfLayer::EraseFieldDictValueByKey)

        // Metadata
        .m(&PXR_NS::SdfLayer::GetColorConfiguration)
        .m(&PXR_NS::SdfLayer::SetColorConfiguration)
        .m(&PXR_NS::SdfLayer::HasColorConfiguration)
        .m(&PXR_NS::SdfLayer::ClearColorConfiguration)
        .m(&PXR_NS::SdfLayer::GetColorManagementSystem)
        .m(&PXR_NS::SdfLayer::SetColorManagementSystem)
        .m(&PXR_NS::SdfLayer::HasColorManagementSystem)
        .m(&PXR_NS::SdfLayer::ClearColorManagementSystem)
        .m(&PXR_NS::SdfLayer::GetComment)
        .m(&PXR_NS::SdfLayer::SetComment)
        .m(&PXR_NS::SdfLayer::GetDefaultPrim)
        .m(&PXR_NS::SdfLayer::SetDefaultPrim)
        .m(&PXR_NS::SdfLayer::HasDefaultPrim)
        .m(&PXR_NS::SdfLayer::ClearDefaultPrim)
        .m(&PXR_NS::SdfLayer::GetDocumentation)
        .m(&PXR_NS::SdfLayer::SetDocumentation)
        .m(&PXR_NS::SdfLayer::GetStartTimeCode)
        .m(&PXR_NS::SdfLayer::SetStartTimeCode)
        .m(&PXR_NS::SdfLayer::HasStartTimeCode)
        .m(&PXR_NS::SdfLayer::ClearStartTimeCode)
        .m(&PXR_NS::SdfLayer::GetEndTimeCode)
        .m(&PXR_NS::SdfLayer::SetEndTimeCode)
        .m(&PXR_NS::SdfLayer::HasEndTimeCode)
        .m(&PXR_NS::SdfLayer::ClearEndTimeCode)
        .m(&PXR_NS::SdfLayer::GetTimeCodesPerSecond)
        .m(&PXR_NS::SdfLayer::SetTimeCodesPerSecond)
        .m(&PXR_NS::SdfLayer::HasTimeCodesPerSecond)
        .m(&PXR_NS::SdfLayer::ClearTimeCodesPerSecond)
        .m(&PXR_NS::SdfLayer::GetFramesPerSecond)
        .m(&PXR_NS::SdfLayer::SetFramesPerSecond)
        .m(&PXR_NS::SdfLayer::HasFramesPerSecond)
        .m(&PXR_NS::SdfLayer::ClearFramesPerSecond)
        .m(&PXR_NS::SdfLayer::GetFramePrecision)
        .m(&PXR_NS::SdfLayer::SetFramePrecision)
        .m(&PXR_NS::SdfLayer::HasFramePrecision)
        .m(&PXR_NS::SdfLayer::ClearFramePrecision)
        .m(&PXR_NS::SdfLayer::GetOwner)
        .m(&PXR_NS::SdfLayer::SetOwner)
        .m(&PXR_NS::SdfLayer::HasOwner)
        .m(&PXR_NS::SdfLayer::ClearOwner)
        .m(&PXR_NS::SdfLayer::GetSessionOwner)
        .m(&PXR_NS::SdfLayer::SetSessionOwner)
        .m(&PXR_NS::SdfLayer::HasSessionOwner)
        .m(&PXR_NS::SdfLayer::ClearSessionOwner)
        .m(&PXR_NS::SdfLayer::GetHasOwnedSubLayers)
        .m(&PXR_NS::SdfLayer::SetHasOwnedSubLayers)
        .m(&PXR_NS::SdfLayer::GetCustomLayerData)
        .m(&PXR_NS::SdfLayer::SetCustomLayerData)
        .m(&PXR_NS::SdfLayer::HasCustomLayerData)
        .m(&PXR_NS::SdfLayer::ClearCustomLayerData)
        .m(&PXR_NS::SdfLayer::GetExpressionVariables)
        .m(&PXR_NS::SdfLayer::SetExpressionVariables)
        .m(&PXR_NS::SdfLayer::HasExpressionVariables)
        .m(&PXR_NS::SdfLayer::ClearExpressionVariables)

        // Sublayers
        .m(&PXR_NS::SdfLayer::GetSubLayerPaths)
        .m(&PXR_NS::SdfLayer::SetSubLayerPaths)
        .m(&PXR_NS::SdfLayer::GetNumSubLayerPaths)
        .m(&PXR_NS::SdfLayer::InsertSubLayerPath)
        .m(&PXR_NS::SdfLayer::RemoveSubLayerPath)
        .m(&PXR_NS::SdfLayer::GetSubLayerOffsets)
        .m(&PXR_NS::SdfLayer::GetSubLayerOffset)
        .m(&PXR_NS::SdfLayer::SetSubLayerOffset)

        // Lookup
        .m(&PXR_NS::SdfLayer::GetPseudoRoot)
        .m(&PXR_NS::SdfLayer::GetObjectAtPath)
        .m(&PXR_NS::SdfLayer::GetPrimAtPath)
        .m(&PXR_NS::SdfLayer::GetPropertyAtPath)
        .m(&PXR_NS::SdfLayer::GetAttributeAtPath)
        .m(&PXR_NS::SdfLayer::GetRelationshipAtPath)

        // Permissions
        .m(&PXR_NS::SdfLayer::PermissionToEdit)
        .m(&PXR_NS::SdfLayer::PermissionToSave)
        .m(&PXR_NS::SdfLayer::SetPermissionToEdit)
        .m(&PXR_NS::SdfLayer::SetPermissionToSave)

        // Batch namespace editing
        .m(&PXR_NS::SdfLayer::CanApply)
        .m(&PXR_NS::SdfLayer::Apply)

        // Layer state
        .m(&PXR_NS::SdfLayer::IsDirty)

        // Time sample API
        .m(&PXR_NS::SdfLayer::ListAllTimeSamples)
        .m(&PXR_NS::SdfLayer::ListTimeSamplesForPath)
        .m(&PXR_NS::SdfLayer::GetBracketingTimeSamplesForPath)
        .m(&PXR_NS::SdfLayer::GetBracketingTimeSamples)
        .m(&PXR_NS::SdfLayer::GetNumTimeSamplesForPath)
        .m((bool (PXR_NS::SdfLayer::*)(PXR_NS::SdfPath const&, double, PXR_NS::VtValue*) const)
            &PXR_NS::SdfLayer::QueryTimeSample)
        .m((void (PXR_NS::SdfLayer::*)(PXR_NS::SdfPath const&, double, PXR_NS::VtValue const&))
            &PXR_NS::SdfLayer::SetTimeSample)
        .m(&PXR_NS::SdfLayer::EraseTimeSample)

        // static
        .m(&PXR_NS::SdfLayer::DumpLayerInfo)
    ;

    bbl::Class<PXR_NS::SdfLayerHandle>("LayerHandle")
        HANDLE_METHODS(PXR_NS::SdfAttributeSpecHandle)
    ;

    bbl::Class<PXR_NS::SdfLayerHandleVector>("LayerHandleVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfLayerHandle)
    ;

    bbl::Class<PXR_NS::SdfLayerOffset>("LayerOffset")
        .ctor(bbl::Ctor<PXR_NS::SdfLayerOffset, double, double>("offset", "scale"), "new")
        .m(&PXR_NS::SdfLayerOffset::GetOffset)
        .m(&PXR_NS::SdfLayerOffset::GetScale)
        .m(&PXR_NS::SdfLayerOffset::SetOffset)
        .m(&PXR_NS::SdfLayerOffset::SetScale)
        .m(&PXR_NS::SdfLayerOffset::IsIdentity)
        .m(&PXR_NS::SdfLayerOffset::IsValid)
        .m(&PXR_NS::SdfLayerOffset::GetInverse)
        .m(&PXR_NS::SdfLayerOffset::operator==, "op_eq")
        .m(&PXR_NS::SdfLayerOffset::operator<, "op_lt")
        .m((PXR_NS::SdfLayerOffset (PXR_NS::SdfLayerOffset::*)(PXR_NS::SdfLayerOffset const&) const)
            &PXR_NS::SdfLayerOffset::operator*, "apply")
        .m((double (PXR_NS::SdfLayerOffset::*)(double) const)
            &PXR_NS::SdfLayerOffset::operator*, "apply_to_double")
        .m((PXR_NS::SdfTimeCode (PXR_NS::SdfLayerOffset::*)(PXR_NS::SdfTimeCode const&) const)
            &PXR_NS::SdfLayerOffset::operator*, "apply_to_timecode")
        ;

    bbl::Class<PXR_NS::SdfLayerOffsetVector>("LayerOffsetVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfLayerOffset)
        ;

    bbl::Class<PXR_NS::SdfLayerRefPtr>("LayerRefPtr");


    bbl::Class<PXR_NS::SdfLayerTree>("LayerTree")
        .m(&PXR_NS::SdfLayerTree::GetLayer)
        .m(&PXR_NS::SdfLayerTree::GetOffset)
        .m(&PXR_NS::SdfLayerTree::GetChildTrees)
        ;

    bbl::Class<PXR_NS::SdfLayerTreeHandle>("LayerTreeHandle")
        ;

    bbl::Class<PXR_NS::SdfLayerTreeHandleVector>("LayerTreeHandleVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfLayerTreeHandle)
        ;

    using StringListOp = PXR_NS::SdfListOp<std::string>;
    bbl::Class<PXR_NS::SdfListOp<std::string>>("StringListOp")
        .ctor(bbl::Ctor<StringListOp>(), "new")
        .m(&StringListOp::HasKeys)
        .m(&StringListOp::IsExplicit)
        .m(&StringListOp::GetExplicitItems)
        .m(&StringListOp::GetAddedItems)
        .m(&StringListOp::GetPrependedItems)
        .m(&StringListOp::GetAppendedItems)
        .m(&StringListOp::GetDeletedItems)
        .m(&StringListOp::GetOrderedItems)
        .m(&StringListOp::GetAppliedItems)
        ;

    bbl::Class<PXR_NS::SdfNameChildrenOrderProxy>("NameChildrenOrderProxy");

    bbl::Class<PXR_NS::SdfNameEditorProxy>("NameEditorProxy");

    bbl::Class<PXR_NS::SdfNamespaceEdit>("NamespaceEdit")
        .ctor(bbl::Ctor<PXR_NS::SdfNamespaceEdit>(), "new")
        .ctor(bbl::Ctor<PXR_NS::SdfNamespaceEdit, PXR_NS::SdfNamespaceEdit::Path const&, PXR_NS::SdfNamespaceEdit::Path const&, PXR_NS::SdfNamespaceEdit::Index>(), "from_paths")
        .m(&PXR_NS::SdfNamespaceEdit::Remove)
        .m(&PXR_NS::SdfNamespaceEdit::Rename)
        .m(&PXR_NS::SdfNamespaceEdit::Reorder)
        .m(&PXR_NS::SdfNamespaceEdit::Reparent)
        .m(&PXR_NS::SdfNamespaceEdit::ReparentAndRename)
        ;
    bbl::fn(&bblext::NamespaceEdit_get_current_path);
    bbl::fn(&bblext::NamespaceEdit_get_new_path);
    bbl::fn(&bblext::NamespaceEdit_get_index);

    bbl::Class<std::vector<PXR_NS::SdfNamespaceEdit>>("NamespaceEditVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfNamespaceEdit)
        ;

    
    bbl::Class<PXR_NS::SdfNamespaceEditDetail>("NamespaceEditDetail")
        ;

    bbl::Enum<PXR_NS::SdfNamespaceEditDetail::Result>("NamespaceEditDetailResult")
        ;

    bbl::fn(&bblext::NamespaceEditDetail_get_edit);
    bbl::fn(&bblext::NamespaceEditDetail_get_result);
    bbl::fn(&bblext::NamespaceEditDetail_get_reason);

    bbl::Class<PXR_NS::SdfNamespaceEditDetailVector>("NamespaceEditDetailVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfNamespaceEditDetail)
        ;

    bbl::Class<PXR_NS::SdfNotice::Base>("NoticeBase");
    bbl::Class<PXR_NS::SdfNotice::BaseLayersDidChange>("NoticeBaseLayersDidChange");
    bbl::Class<PXR_NS::SdfNotice::LayerDidReloadContent>("NoticeLayerDidReloadContent");
    bbl::Class<PXR_NS::SdfNotice::LayerDidReplaceContent>("NoticeLayerDidReplaceContent");
    bbl::Class<PXR_NS::SdfNotice::LayerDidSaveLayerToFile>("NoticeLayerDidSaveLayerToFile");
    bbl::Class<PXR_NS::SdfNotice::LayerIdentifierDidChange>("NoticeLayerIdentifierDidChange");
    bbl::Class<PXR_NS::SdfNotice::LayerInfoDidChange>("NoticeLayerInfoDidChange");
    bbl::Class<PXR_NS::SdfNotice::LayerMutenessChanged>("NoticeLayerMutenessChanged");
    bbl::Class<PXR_NS::SdfNotice::LayersDidChange>("NoticeLayersDidChange");
    bbl::Class<PXR_NS::SdfNotice::LayersDidChangeSentPerLayer>("NoticeLayersDidChangeSentPerLayer");

    bbl::Class<PXR_NS::SdfPath>("Path")
        .opaque_ptr()
        .ctor(bbl::Ctor<PXR_NS::SdfPath>(), "new")
        .m(&PXR_NS::SdfPath::GetPathElementCount)
        .m(&PXR_NS::SdfPath::IsAbsolutePath)
        .m(&PXR_NS::SdfPath::IsAbsoluteRootPath)
        .m(&PXR_NS::SdfPath::IsPrimPath)
        .m(&PXR_NS::SdfPath::IsAbsoluteRootOrPrimPath)
        .m(&PXR_NS::SdfPath::IsRootPrimPath)
        .m(&PXR_NS::SdfPath::IsPropertyPath)
        .m(&PXR_NS::SdfPath::IsPrimPropertyPath)
        .m(&PXR_NS::SdfPath::IsNamespacedPropertyPath)
        .m(&PXR_NS::SdfPath::IsPrimVariantSelectionPath)
        .m(&PXR_NS::SdfPath::IsPrimOrPrimVariantSelectionPath)
        .m(&PXR_NS::SdfPath::ContainsPrimVariantSelection)
        .m(&PXR_NS::SdfPath::ContainsPropertyElements)
        .m(&PXR_NS::SdfPath::ContainsTargetPath)
        .m(&PXR_NS::SdfPath::IsRelationalAttributePath)
        .m(&PXR_NS::SdfPath::IsTargetPath)
        .m(&PXR_NS::SdfPath::IsMapperPath)
        .m(&PXR_NS::SdfPath::IsMapperArgPath)
        .m(&PXR_NS::SdfPath::IsExpressionPath)
        .m(&PXR_NS::SdfPath::IsEmpty)
        .m(&PXR_NS::SdfPath::GetAsToken)
        .m(&PXR_NS::SdfPath::GetAsString)
        .m(&PXR_NS::SdfPath::GetString)
        .m(&PXR_NS::SdfPath::GetText)
        .m((PXR_NS::SdfPathVector(PXR_NS::SdfPath::*)() const) &
           PXR_NS::SdfPath::GetPrefixes)
        .m((PXR_NS::SdfPathVector(PXR_NS::SdfPath::*)(size_t) const) &
               PXR_NS::SdfPath::GetPrefixes,
           "GetPrefixes_up_to")
        .m((void(PXR_NS::SdfPath::*)(PXR_NS::SdfPathVector*) const) &
               PXR_NS::SdfPath::GetPrefixes,
           "GetPrefixes_in")
        .m((void(PXR_NS::SdfPath::*)(PXR_NS::SdfPathVector*, size_t) const) &
               PXR_NS::SdfPath::GetPrefixes,
           "GetPrefixes_in_up_to")
        // GetAncestorsRange
        .m(&PXR_NS::SdfPath::GetName)
        .m(&PXR_NS::SdfPath::GetNameToken)
        .m(&PXR_NS::SdfPath::GetElementString)
        .m(&PXR_NS::SdfPath::GetElementToken)
        .m(&PXR_NS::SdfPath::ReplaceName)
        .m(&PXR_NS::SdfPath::GetTargetPath)
        .m(&PXR_NS::SdfPath::GetAllTargetPathsRecursively)
        // GetVariantSelection
        .m(&PXR_NS::SdfPath::HasPrefix)
        .m(&PXR_NS::SdfPath::GetParentPath)
        .m(&PXR_NS::SdfPath::GetPrimPath)
        .m(&PXR_NS::SdfPath::GetPrimOrPrimVariantSelectionPath)
        .m(&PXR_NS::SdfPath::GetAbsoluteRootOrPrimPath)
        .m(&PXR_NS::SdfPath::StripAllVariantSelections)
        .m(&PXR_NS::SdfPath::AppendPath)
        .m(&PXR_NS::SdfPath::AppendChild)
        .m(&PXR_NS::SdfPath::AppendProperty)
        .m(&PXR_NS::SdfPath::AppendVariantSelection)
        .m(&PXR_NS::SdfPath::AppendTarget)
        .m(&PXR_NS::SdfPath::AppendRelationalAttribute)
        .m(&PXR_NS::SdfPath::ReplaceTargetPath)
        .m(&PXR_NS::SdfPath::AppendMapper)
        .m(&PXR_NS::SdfPath::AppendMapperArg)
        .m(&PXR_NS::SdfPath::AppendExpression)
        .m(&PXR_NS::SdfPath::AppendElementString)
        .m(&PXR_NS::SdfPath::AppendElementToken)
        .m(&PXR_NS::SdfPath::ReplacePrefix)
        .m(&PXR_NS::SdfPath::GetCommonPrefix)
        // .m(&PXR_NS::SdfPath::RemoveCommonSuffix)
        .m(&PXR_NS::SdfPath::MakeAbsolutePath)
        .m(&PXR_NS::SdfPath::MakeRelativePath)
        .m(&PXR_NS::SdfPath::EmptyPath)
        .m(&PXR_NS::SdfPath::AbsoluteRootPath)
        .m(&PXR_NS::SdfPath::ReflexiveRelativePath)
        .m(&PXR_NS::SdfPath::IsValidIdentifier)
        .m(&PXR_NS::SdfPath::IsValidNamespacedIdentifier)
        .m(&PXR_NS::SdfPath::TokenizeIdentifier)
        .m(&PXR_NS::SdfPath::TokenizeIdentifierAsTokens)
        .m(&PXR_NS::SdfPath::IsValidPathString)
        .m(&PXR_NS::SdfPath::GetConciseRelativePaths)
        .m(&PXR_NS::SdfPath::RemoveDescendentPaths)
        .m(&PXR_NS::SdfPath::RemoveAncestorPaths);

    // bbl::Class<PXR_NS::SdfPathEditorProxy>("PathEditorProxy");

    bbl::Class<PXR_NS::SdfPathExpression>("PathExpression")
        .ctor(bbl::Ctor<PXR_NS::SdfPathExpression>(), "new")
        .m((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(PXR_NS::SdfPath const&, PXR_NS::SdfPath const&) const&)
            &PXR_NS::SdfPathExpression::ReplacePrefix)
        .m(&PXR_NS::SdfPathExpression::IsAbsolute)
        .m((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(PXR_NS::SdfPath const&) const&)
            &PXR_NS::SdfPathExpression::MakeAbsolute)
        .m(&PXR_NS::SdfPathExpression::ContainsExpressionReferences)
        .m((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(PXR_NS::SdfPathExpression const&) const&)
            &PXR_NS::SdfPathExpression::ComposeOver)
        .m(&PXR_NS::SdfPathExpression::IsComplete)
        .m(&PXR_NS::SdfPathExpression::GetDebugString)
        .m(&PXR_NS::SdfPathExpression::IsEmpty)
        .m(&PXR_NS::SdfPathExpression::GetParseError)

        // static
        .m((PXR_NS::SdfPathExpression (*)(PXR_NS::SdfPathExpression const&))
            &PXR_NS::SdfPathExpression::MakeComplement)
        ;
    
    bbl::fn(&bblext::PathExpression_from_string);

    bbl::Class<PXR_NS::SdfPathSet>("PathSet");

    bbl::Class<PXR_NS::SdfPathVector>("PathVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfPath);

    bbl::Class<PXR_NS::SdfPayload>("Payload")
        .ctor(bbl::Ctor<PXR_NS::SdfPayload>(), "new")
        .m(&PXR_NS::SdfPayload::GetAssetPath)
        .m(&PXR_NS::SdfPayload::SetAssetPath)
        .m(&PXR_NS::SdfPayload::GetPrimPath)
        .m(&PXR_NS::SdfPayload::SetPrimPath)
        .m(&PXR_NS::SdfPayload::GetLayerOffset)
        .m(&PXR_NS::SdfPayload::SetLayerOffset)
        .m(&PXR_NS::SdfPayload::operator==, "op_eq")
        .m(&PXR_NS::SdfPayload::operator<, "op_lt")
        ;

    bbl::fn(&bblext::Payload_from_asset_path);
    bbl::fn(&bblext::Payload_from_asset_path_and_prim_path);
    bbl::fn(&bblext::Payload_from_asset_path_and_prim_path_and_layer_offset);

    bbl::Class<PXR_NS::SdfPayloadEditorProxy>("PayloadEditorProxy");

    bbl::Class<PXR_NS::SdfPayloadVector>("PayloadVector");

    // bbl::Class<PXR_NS::SdfPayloadsProxy>("PayloadsProxy");

    bbl::Enum<PXR_NS::SdfPermission>("Permission");

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

        SPEC_METHODS(PXR_NS::SdfPrimSpec)
    ;

    bbl::Class<PXR_NS::SdfPrimSpecHandle>("PrimSpecHandle")
        HANDLE_METHODS(PXR_NS::SdfPrimSpecHandle)
        ;

    bbl::Class<PXR_NS::SdfPrimSpecHandleVector>("PrimSpecHandleVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfPrimSpecHandle)
        ;

    bbl::Class<std::pair<PXR_NS::SdfPrimSpecHandle, PXR_NS::SdfLayerOffset>>(
        "PrimSpecHandleOffsetPair");

    bbl::Class<std::vector<
        std::pair<PXR_NS::SdfPrimSpecHandle, PXR_NS::SdfLayerOffset>>>(
        "PrimSpecHandleOffsetPairVector")
        BBL_STD_VECTOR_METHODS(
            (std::pair<PXR_NS::SdfPrimSpecHandle, PXR_NS::SdfLayerOffset>));

    bbl::Class<PXR_NS::SdfPrimSpecView>("PrimSpecView");

    // bbl::Class<PXR_NS::SdfPropertyOrderProxy>("PropertyOrderProxy");

    bbl::Class<PXR_NS::SdfPropertySpec>("PropertySpec")
        PROPERTYSPEC_METHODS(PXR_NS::SdfPropertySpec)
        SPEC_METHODS(PXR_NS::SdfPropertySpec)
        ;

    bbl::Class<PXR_NS::SdfPropertySpecHandle>("PropertySpecHandle")
        HANDLE_METHODS(PXR_NS::SdfPropertySpecHandle)
        ;

    bbl::Class<PXR_NS::SdfPropertySpecHandleVector>("PropertySpecHandleVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfPropertySpecHandle)
        ;

    bbl::Class<std::pair<PXR_NS::SdfPropertySpecHandle, PXR_NS::SdfLayerOffset>>("PropertySpecHandleOffsetPair");

    bbl::Class<std::vector<std::pair<PXR_NS::SdfPropertySpecHandle, PXR_NS::SdfLayerOffset>>>("PropertySpecHandleOffsetPairVector")
        BBL_STD_VECTOR_METHODS((std::pair<PXR_NS::SdfPropertySpecHandle, PXR_NS::SdfLayerOffset>))
        ;

    bbl::Class<PXR_NS::SdfPropertySpecView>("PropertySpecView");

    bbl::Class<PXR_NS::SdfReference>("Reference")
        .m(&PXR_NS::SdfReference::GetAssetPath)
        .m(&PXR_NS::SdfReference::SetAssetPath)
        .m(&PXR_NS::SdfReference::GetPrimPath)
        .m(&PXR_NS::SdfReference::SetPrimPath)
        .m(&PXR_NS::SdfReference::GetLayerOffset)
        .m(&PXR_NS::SdfReference::SetLayerOffset)
        .m(&PXR_NS::SdfReference::GetCustomData)
        .m((void (PXR_NS::SdfReference::*)(PXR_NS::VtDictionary const&))
            &PXR_NS::SdfReference::SetCustomData)
        .m((void (PXR_NS::SdfReference::*)(std::string const& name, PXR_NS::VtValue const&))
            &PXR_NS::SdfReference::SetCustomData, "SetCustomData_value")
        .m(&PXR_NS::SdfReference::SwapCustomData)
        .m(&PXR_NS::SdfReference::IsInternal)
        .m(&PXR_NS::SdfReference::operator==, "op_eq")
        .m(&PXR_NS::SdfReference::operator<, "op_lt")
        ;

    bbl::fn(&bblext::Reference_from_asset_path);
    bbl::fn(&bblext::Reference_from_asset_path_and_prim_path);
    bbl::fn(&bblext::Reference_from_asset_path_and_prim_path_and_layer_offset);
    bbl::fn(&bblext::Reference_from_asset_path_and_prim_path_and_layer_offset_and_custom_data);

    bbl::Class<PXR_NS::SdfReferenceEditorProxy>("ReferenceEditorProxy");

    bbl::Class<PXR_NS::SdfReferenceVector>("ReferenceVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfReference);

    // bbl::Class<PXR_NS::SdfReferencesProxy>("ReferencesProxy");

    bbl::Class<PXR_NS::SdfRelationshipSpec>("RelationshipSpec")
        .m(&PXR_NS::SdfRelationshipSpec::New)
        .m(&PXR_NS::SdfRelationshipSpec::GetNoLoadHint)
        .m(&PXR_NS::SdfRelationshipSpec::SetNoLoadHint)
        .m(&PXR_NS::SdfRelationshipSpec::GetTargetPathList)
        .m(&PXR_NS::SdfRelationshipSpec::HasTargetPathList)
        .m(&PXR_NS::SdfRelationshipSpec::ClearTargetPathList)
        .m(&PXR_NS::SdfRelationshipSpec::ReplaceTargetPath)
        .m(&PXR_NS::SdfRelationshipSpec::RemoveTargetPath)

        PROPERTYSPEC_METHODS(PXR_NS::SdfRelationshipSpec)
        SPEC_METHODS(PXR_NS::SdfRelationshipSpec)
        ;


    bbl::Class<PXR_NS::SdfRelationshipSpecHandle>("RelationshipSpecHandle")
        HANDLE_METHODS(PXR_NS::SdfRelationshipSpecHandle)
    ;

    bbl::Class<PXR_NS::SdfRelationshipSpecHandleVector>("RelationshipSpecHandleVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfRelationshipSpecHandle)
    ;

    bbl::Class<PXR_NS::SdfRelationshipSpecView>("RelationshipSpecView");

    bbl::Class<
        std::pair<PXR_NS::SdfRelationshipSpecHandle, PXR_NS::SdfLayerOffset>>(
        "RelationshipSpecHandleOffsetPair");

    bbl::Class<std::vector<
        std::pair<PXR_NS::SdfRelationshipSpecHandle, PXR_NS::SdfLayerOffset>>>(
        "RelationshipSpecHandleOffsetPairVector")
        BBL_STD_VECTOR_METHODS((std::pair<PXR_NS::SdfRelationshipSpecHandle,
                                          PXR_NS::SdfLayerOffset>));

    bbl::Class<PXR_NS::SdfRelocatesMap>("RelocatesMap");
    bbl::Class<PXR_NS::SdfRelocatesMapProxy>("RelocatesMapProxy");

    bbl::Class<PXR_NS::SdfSchemaBase>("SchemaBase")
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
        .m(&PXR_NS::SdfSchemaBase::IsValidValue)
        .m(&PXR_NS::SdfSchemaBase::GetAllTypes)
        .m((PXR_NS::SdfValueTypeName(PXR_NS::SdfSchemaBase::*)(
               PXR_NS::TfToken const&) const) &
           PXR_NS::SdfSchemaBase::FindType)
        .m((PXR_NS::SdfValueTypeName(PXR_NS::SdfSchemaBase::*)(
               PXR_NS::TfType const&, PXR_NS::TfToken const&) const) &
               PXR_NS::SdfSchemaBase::FindType,
           "FindType_with_role")
        .m(&PXR_NS::SdfSchemaBase::FindOrCreateType)

        // Static
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
        .m(&PXR_NS::SdfSchemaBase::IsValidVariantSelection);

    bbl::Class<PXR_NS::SdfSchemaBase::FieldDefinition>(
        "SchemaBaseFieldDefinition")
        // .ctor(bbl::Ctor<PXR_NS::SdfSchemaBase::FieldDefinition,
        // PXR_NS::SdfSchemaBase const&, PXR_NS::TfToken const&, PXR_NS::VtValue
        // const&>(), "new")
        .m(&PXR_NS::SdfSchemaBase::FieldDefinition::GetName)
        .m(&PXR_NS::SdfSchemaBase::FieldDefinition::GetFallbackValue)
        .m(&PXR_NS::SdfSchemaBase::FieldDefinition::GetInfo)
        .m(&PXR_NS::SdfSchemaBase::FieldDefinition::IsPlugin)
        .m(&PXR_NS::SdfSchemaBase::FieldDefinition::IsReadOnly)
        .m(&PXR_NS::SdfSchemaBase::FieldDefinition::HoldsChildren)
        // Getting link errors on these
        // .m(&PXR_NS::SdfSchemaBase::FieldDefinition::Plugin)
        // .m(&PXR_NS::SdfSchemaBase::FieldDefinition::Children)
        // .m(&PXR_NS::SdfSchemaBase::FieldDefinition::ReadOnly)
        // .m(&PXR_NS::SdfSchemaBase::FieldDefinition::AddInfo)
        ;

    bbl::Class<PXR_NS::SdfSchemaBase::FieldDefinition::InfoVec>(
        "SchemaBaseFieldDefinitionInfoVec")
        BBL_STD_VECTOR_METHODS((std::pair<PXR_NS::TfToken, PXR_NS::JsValue>));

    bbl::Class<std::pair<PXR_NS::TfToken, PXR_NS::JsValue>>("TokenValuePair");

    bbl::Class<PXR_NS::SdfSchemaBase::SpecDefinition>(
        "SchemaBaseSpecDefinition");

    bbl::Class<PXR_NS::SdfSpec>("Spec") SPEC_METHODS(PXR_NS::SdfSpec);

    // bbl::Class<PXR_NS::SdfSpecializesProxy>("SpecializesProxy");

    bbl::Enum<PXR_NS::SdfSpecifier>("Specifier");

    bbl::Enum<PXR_NS::SdfSpecType>("SpecType");

    bbl::Class<PXR_NS::SdfSpecHandle>("SpecHandle")
        HANDLE_METHODS(PXR_NS::SdfSpecHandle)
    ;

    bbl::Class<PXR_NS::SdfSubLayerProxy>("SubLayerProxy")
    ;

    bbl::Class<PXR_NS::SdfTextFileFormat>("TextFileFormat")
        FILEFORMAT_METHODS(PXR_NS::SdfTextFileFormat)
        ;

    bbl::Class<PXR_NS::SdfTimeCode>("TimeCode")
        .ctor(bbl::Ctor<PXR_NS::SdfTimeCode, double>(), "from_time")
        .m(&PXR_NS::SdfTimeCode::GetValue);

    bbl::Class<PXR_NS::SdfTimeSampleMap>("TimeSampleMap");

    bbl::Class<PXR_NS::SdfTupleDimensions>("TupleDimensions")
        .value_type()
        .f(&PXR_NS::SdfTupleDimensions::d)
        .f(&PXR_NS::SdfTupleDimensions::size)
        ;

    bbl::Class<PXR_NS::SdfValueBlock>("ValueBlock")
        .ctor(bbl::Ctor<PXR_NS::SdfValueBlock>(), "new")
    ;

    bbl::Class<PXR_NS::SdfValueTypeName>("ValueTypeName")
        .ctor(bbl::Ctor<PXR_NS::SdfValueTypeName>(), "new")
        .m(&PXR_NS::SdfValueTypeName::GetAsToken)
        .m(&PXR_NS::SdfValueTypeName::GetType)
        .m(&PXR_NS::SdfValueTypeName::GetRole)
        .m(&PXR_NS::SdfValueTypeName::GetDefaultValue)
        .m(&PXR_NS::SdfValueTypeName::GetDefaultUnit)
        .m(&PXR_NS::SdfValueTypeName::GetScalarType)
        .m(&PXR_NS::SdfValueTypeName::GetArrayType)
        .m(&PXR_NS::SdfValueTypeName::IsScalar)
        .m(&PXR_NS::SdfValueTypeName::IsArray)
        .m(&PXR_NS::SdfValueTypeName::GetDimensions)
        .m(&PXR_NS::SdfValueTypeName::GetAliasesAsTokens)
        ;

    bbl::fn(&bblext::ValueTypeName_GetCPPTypeName);


    bbl::Class<std::vector<PXR_NS::SdfValueTypeName>>("ValueTypeNameVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfValueTypeName);

    bbl::Enum<PXR_NS::SdfVariability>("Variability");

    bbl::Class<PXR_NS::SdfVariableExpression>("VariableExpression")
        .ctor(bbl::Ctor<PXR_NS::SdfVariableExpression>(), "new")
        .m(&PXR_NS::SdfVariableExpression::GetErrors)
        .m(&PXR_NS::SdfVariableExpression::Evaluate)
        ;

    bbl::Class<PXR_NS::SdfVariableExpression::Result>("VariableExpressionResult");

    bbl::Class<PXR_NS::SdfVariantSelectionProxy>("VariantSelectionProxy");
    // bbl::Class<PXR_NS::SdfVariantSetNamesProxy>("VariantSetNamesProxy");
    // bbl::Class<PXR_NS::SdfVariantSetsProxy>("VariantSetsProxy");

    bbl::Class<PXR_NS::SdfVariantSetSpec>("VariantSetSpec")
        .m(&PXR_NS::SdfVariantSetSpec::GetName)
        .m(&PXR_NS::SdfVariantSetSpec::GetNameToken)
        .m(&PXR_NS::SdfVariantSetSpec::GetOwner)
        .m(&PXR_NS::SdfVariantSetSpec::GetVariants)
        .m(&PXR_NS::SdfVariantSetSpec::GetVariantList)
        .m(&PXR_NS::SdfVariantSetSpec::RemoveVariant)
        SPEC_METHODS(PXR_NS::SdfVariantSetSpec)
        ;

    bbl::Class<PXR_NS::SdfVariantSetsProxy>("VariantSetsProxy");

    bbl::Class<PXR_NS::SdfVariantSpec>("VariantSpec")
        .m(&PXR_NS::SdfVariantSpec::GetName)
        .m(&PXR_NS::SdfVariantSpec::GetNameToken)
        .m(&PXR_NS::SdfVariantSpec::GetOwner)
        .m(&PXR_NS::SdfVariantSpec::GetPrimSpec)
        .m(&PXR_NS::SdfVariantSpec::GetVariantSets)
        .m(&PXR_NS::SdfVariantSpec::GetVariantNames)
        SPEC_METHODS(PXR_NS::SdfVariantSpec)
        ;
    
    bbl::Class<PXR_NS::SdfVariantSetSpecHandle>("VariantSetSpecHandle");

    bbl::Class<PXR_NS::SdfVariantSpecHandle>("VariantSpecHandle");

    bbl::Class<PXR_NS::SdfVariantSpecHandleVector>("VariantSpecHandleVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfVariantSpecHandle)
        ;

    
    bbl::Class<PXR_NS::SdfVariantView>("VariantView");
}

#endif
