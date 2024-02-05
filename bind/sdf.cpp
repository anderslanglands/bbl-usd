#if defined(__clang__)

#include "babble"
#include "babble-std"

#include <pxr/base/js/types.h>
#include <pxr/base/js/value.h>
#include <pxr/base/tf/token.h>
#include <pxr/base/vt/array.h>
#include <pxr/base/vt/dictionary.h>
#include <pxr/base/vt/value.h>

#include <pxr/usd/sdf/abstractData.h>
#include <pxr/usd/sdf/allowed.h>
#include <pxr/usd/sdf/assetPath.h>
#include <pxr/usd/sdf/attributeSpec.h>
#include <pxr/usd/sdf/changeBlock.h>
#include <pxr/usd/sdf/changeList.h>
#include <pxr/usd/sdf/copyUtils.h>
#include <pxr/usd/sdf/data.h>
#include <pxr/usd/sdf/declareHandles.h>
#include <pxr/usd/sdf/fileFormat.h>
#include <pxr/usd/sdf/layer.h>
#include <pxr/usd/sdf/layerOffset.h>
#include <pxr/usd/sdf/layerStateDelegate.h>
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

struct TimeCode {
    double time;
};

namespace bblext {

PXR_NS::SdfAssetPath AssetPath_from_path(char const* path) {
    return PXR_NS::SdfAssetPath(path);
}

PXR_NS::SdfAssetPath AssetPath_from_path_and_resolved_path(char const* path, char const* resolved_path) {
    return PXR_NS::SdfAssetPath(path, resolved_path);
}

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

class FileFormatBase : public PXR_NS::SdfFileFormat {
public:
    // expose protected members
    FileFormatBase(PXR_NS::TfToken const& formatId, PXR_NS::TfToken const& versionString, PXR_NS::TfToken const& target, char const* extension)
    : PXR_NS::SdfFileFormat(formatId, versionString, target, extension)
    {}

    virtual ~FileFormatBase() {}

    virtual auto CanRead(std::string const& file) const -> bool override {
        return false;
    }

    virtual auto Read(PXR_NS::SdfLayer* layer, std::string const& resolvedPath, bool metadaOnly) const -> bool override {
        return false;
    }

    // Helper function for _ReadDetached
    auto _ReadAndCopyLayerDataToMemory(PXR_NS::SdfLayer* layer, char const* resolvedPath, bool metadataOnly, bool* didCopyData) const -> bool {
        return PXR_NS::SdfFileFormat::_ReadAndCopyLayerDataToMemory(layer, resolvedPath, metadataOnly, didCopyData);
    }

    virtual auto _InstantiateNewLayer(PXR_NS::SdfFileFormatConstPtr const& fileFormat, const std::string &identifier, const std::string &realPath, const PXR_NS::ArAssetInfo &assetInfo, const PXR_NS::SdfFileFormat::FileFormatArguments &args) const -> PXR_NS::SdfLayer* override {
        return PXR_NS::SdfFileFormat::_InstantiateNewLayer(fileFormat, identifier, realPath, assetInfo, args);
    }

    auto _InstantiateNewLayer_base(PXR_NS::SdfFileFormatConstPtr const& fileFormat, char const* identifier, char const* realPath, const PXR_NS::ArAssetInfo &assetInfo, const PXR_NS::SdfFileFormat::FileFormatArguments &args) const -> PXR_NS::SdfLayer* {
        return PXR_NS::SdfFileFormat::_InstantiateNewLayer(fileFormat, identifier, realPath, assetInfo, args);
    }

    virtual auto _ShouldSkipAnonymousReload() const -> bool override {
        return PXR_NS::SdfFileFormat::ShouldSkipAnonymousReload();
    }

    auto _ShouldSkipAnonymousReload_base() const -> bool {
        return PXR_NS::SdfFileFormat::ShouldSkipAnonymousReload();
    }

    virtual auto _ShouldReadAnonymousLayers() const -> bool override {
        return PXR_NS::SdfFileFormat::ShouldReadAnonymousLayers();
    }

    auto _ShouldReadAnonymousLayers_base() const -> bool {
        return PXR_NS::SdfFileFormat::ShouldReadAnonymousLayers();
    }

    virtual auto _InitDetachedData(PXR_NS::SdfFileFormat::FileFormatArguments const& args) const -> PXR_NS::SdfAbstractDataRefPtr  override {
        return PXR_NS::SdfFileFormat::InitDetachedData(args);
    }

    auto _InitDetachedData_base(PXR_NS::SdfFileFormat::FileFormatArguments const& args) const -> PXR_NS::SdfAbstractDataRefPtr {
        return PXR_NS::SdfFileFormat::_InitDetachedData(args);
    }

    virtual bool _ReadDetached(PXR_NS::SdfLayer *layer, const std::string &resolvedPath, bool metadataOnly) const override {
        return PXR_NS::SdfFileFormat::_ReadDetached(layer, resolvedPath, metadataOnly);
    }

    bool _ReadDetached_base(PXR_NS::SdfLayer *layer, const std::string &resolvedPath, bool metadataOnly) const {
        return PXR_NS::SdfFileFormat::_ReadDetached(layer, resolvedPath, metadataOnly);
    }

    // static protected member functions
    static void _SetLayerData(PXR_NS::SdfLayer* layer, PXR_NS::SdfAbstractDataRefPtr& data) {
        PXR_NS::SdfFileFormat::_SetLayerData(layer, data);
    }

    static void _SetLayerData_with_hints(PXR_NS::SdfLayer* layer, PXR_NS::SdfAbstractDataRefPtr& data, PXR_NS::SdfLayerHints hints) {
        PXR_NS::SdfFileFormat::_SetLayerData(layer, data, hints);
    }

    static auto _GetLayerData(PXR_NS::SdfLayer const& layer) -> PXR_NS::SdfAbstractDataConstPtr {
        return PXR_NS::SdfFileFormat::_GetLayerData(layer);
    }
};

bool LayerHandle_ExportToString(
    const PXR_NS::SdfLayerHandle& layer,
    std::string** output
) {
    return layer->ExportToString(*output);
}

bool LayerRefPtr_ExportToString(
    const PXR_NS::SdfLayerRefPtr& layer,
    std::string** output
) {
    return layer->ExportToString(*output);
}

}

BBL_MODULE(sdf) {

    // clang-format off

    bbl::Class<PXR_NS::SdfAbstractData>("AbstractData")
        .m(&PXR_NS::SdfAbstractData::CopyFrom)
        .m(&PXR_NS::SdfAbstractData::StreamsData)
        .m(&PXR_NS::SdfAbstractData::IsDetached)
        .m(&PXR_NS::SdfAbstractData::IsEmpty)
        .m(&PXR_NS::SdfAbstractData::Equals)
        // requires binding std::ostream
        // .m(&PXR_NS::SdfAbstractData::WriteToStream)
        .m(&PXR_NS::SdfAbstractData::CreateSpec)
        .m(&PXR_NS::SdfAbstractData::HasSpec)
        .m(&PXR_NS::SdfAbstractData::EraseSpec)
        .m(&PXR_NS::SdfAbstractData::MoveSpec)
        .m(&PXR_NS::SdfAbstractData::GetSpecType)
        // missing SdfAbstractDataSpecVisitor
        // .m(&PXR_NS::SdfAbstractData::VisitSpecs)
        .m((bool (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, PXR_NS::SdfAbstractDataValue *) const)
            &PXR_NS::SdfAbstractData::Has, "Has_00")
        .m((bool (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, PXR_NS::VtValue *) const)
            &PXR_NS::SdfAbstractData::Has, "Has_01")
        .m((bool (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, PXR_NS::SdfAbstractDataValue *, PXR_NS::SdfSpecType *) const)
            &PXR_NS::SdfAbstractData::HasSpecAndField, "HasSpecAndField_00")
        .m((bool (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, PXR_NS::VtValue *, PXR_NS::SdfSpecType *) const)
            &PXR_NS::SdfAbstractData::HasSpecAndField, "HasSpecAndField_01")
        .m(&PXR_NS::SdfAbstractData::Get)
        // missing type_info
        // .m(&PXR_NS::SdfAbstractData::GetTypeid)
        .m((void (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::VtValue &))
            &PXR_NS::SdfAbstractData::Set, "Set_00")
        .m((void (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::SdfAbstractDataConstValue &))
            &PXR_NS::SdfAbstractData::Set, "Set_01")
        .m(&PXR_NS::SdfAbstractData::Erase)
        .m(&PXR_NS::SdfAbstractData::List)
        /** TODO: instantiate this template
        .m(&PXR_NS::SdfAbstractData::GetAs)
        */
        .m((bool (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::TfToken &, PXR_NS::SdfAbstractDataValue *) const)
            &PXR_NS::SdfAbstractData::HasDictKey, "HasDictKey_00")
        .m((bool (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::TfToken &, PXR_NS::VtValue *) const)
            &PXR_NS::SdfAbstractData::HasDictKey, "HasDictKey_01")
        .m(&PXR_NS::SdfAbstractData::GetDictValueByKey)
        .m((void (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::TfToken &, const PXR_NS::VtValue &))
            &PXR_NS::SdfAbstractData::SetDictValueByKey, "SetDictValueByKey_00")
        .m((void (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::TfToken &, const PXR_NS::SdfAbstractDataConstValue &))
            &PXR_NS::SdfAbstractData::SetDictValueByKey, "SetDictValueByKey_01")
        .m(&PXR_NS::SdfAbstractData::EraseDictValueByKey)
        .m(&PXR_NS::SdfAbstractData::ListDictKeys)
        .m(&PXR_NS::SdfAbstractData::ListAllTimeSamples)
        .m(&PXR_NS::SdfAbstractData::ListTimeSamplesForPath)
        .m(&PXR_NS::SdfAbstractData::GetBracketingTimeSamples)
        .m(&PXR_NS::SdfAbstractData::GetNumTimeSamplesForPath)
        .m(&PXR_NS::SdfAbstractData::GetBracketingTimeSamplesForPath)
        .m((bool (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, double, PXR_NS::VtValue *) const)
            &PXR_NS::SdfAbstractData::QueryTimeSample, "QueryTimeSample_00")
        .m((bool (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, double, PXR_NS::SdfAbstractDataValue *) const)
            &PXR_NS::SdfAbstractData::QueryTimeSample, "QueryTimeSample_01")
        .m(&PXR_NS::SdfAbstractData::SetTimeSample)
        .m(&PXR_NS::SdfAbstractData::EraseTimeSample)
    ;

    bbl::Class<PXR_NS::SdfAbstractDataPtr>("AbstractDataPtr")
        .smartptr_to<PXR_NS::SdfAbstractData>()
    ;

    bbl::Class<PXR_NS::SdfAbstractDataPtrVector>("AbstractDataPtrVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfAbstractDataPtr)
    ;

    bbl::Class<PXR_NS::SdfAbstractDataConstPtr>("AbstractDataConstPtr")
        .smartptr_to<PXR_NS::SdfAbstractData const>()
    ;

    bbl::Class<PXR_NS::SdfAbstractDataConstPtrVector>("AbstractDataConstPtrVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfAbstractDataConstPtr)
    ;

    bbl::Class<PXR_NS::SdfAbstractDataRefPtr>("AbstractDataRefPtr")
        .smartptr_to<PXR_NS::SdfAbstractData>()
    ;

    bbl::Class<PXR_NS::SdfAbstractDataRefPtrVector>("AbstractDataRefPtrVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfAbstractDataRefPtr)
    ;

    bbl::Class<PXR_NS::SdfAbstractDataConstRefPtr>("AbstractDataConstRefPtr")
        .smartptr_to<PXR_NS::SdfAbstractData const>()
    ;

    bbl::Class<PXR_NS::SdfAbstractDataConstRefPtrVector>("AbstractDataConstRefPtrVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfAbstractDataConstRefPtr)
    ;

    bbl::Class<PXR_NS::SdfAbstractDataValue>("AbstractDataValue")
        .m((bool (PXR_NS::SdfAbstractDataValue::*)(const PXR_NS::VtValue &))
            &PXR_NS::SdfAbstractDataValue::StoreValue, "StoreValue")
        .m((bool (PXR_NS::SdfAbstractDataValue::*)(const PXR_NS::SdfValueBlock &))
            &PXR_NS::SdfAbstractDataValue::StoreValue, "StoreValue_block")
    ;

    bbl::Class<PXR_NS::SdfAbstractDataConstValue>("AbstractDataConstValue")
        .m((bool (PXR_NS::SdfAbstractDataConstValue::*)(PXR_NS::VtValue *) const)
            &PXR_NS::SdfAbstractDataConstValue::GetValue, "GetValue")
        .m(&PXR_NS::SdfAbstractDataConstValue::IsEqual)
    ;

    bbl::Class<PXR_NS::SdfAllowed>("Allowed")
        .ctor(bbl::Class<PXR_NS::SdfAllowed>::Ctor<>(), "new")
        .ctor(bbl::Class<PXR_NS::SdfAllowed>::Ctor<bool>(), "from_bool")
        .ctor(bbl::Class<PXR_NS::SdfAllowed>::Ctor<char const*>(), "from_string")
        .ctor(bbl::Class<PXR_NS::SdfAllowed>::Ctor<bool, char const*>(),
              "from_bool_and_string")
        .m(&PXR_NS::SdfAllowed::IsAllowed)
        .m(&PXR_NS::SdfAllowed::GetWhyNot)
    ;

    bbl::Class<PXR_NS::SdfAssetPath>("AssetPath")
        .ctor(bbl::Class<PXR_NS::SdfAssetPath>::Ctor<>(), "new")
        .m(&pxrInternal_v0_23__pxrReserved__::SdfAssetPath::operator==, "op_eq")
        .m(&pxrInternal_v0_23__pxrReserved__::SdfAssetPath::operator!=, "op_neq")
        .m(&pxrInternal_v0_23__pxrReserved__::SdfAssetPath::operator<, "op_lt")
    ;

    // we bind specific wrapper functions for these as there's no point
    // generating an intermediary string&
    bbl::fn(&bblext::AssetPath_from_path);
    bbl::fn(&bblext::AssetPath_from_path_and_resolved_path);
    bbl::fn(&bblext::AssetPath_GetAssetPath);
    bbl::fn(&bblext::AssetPath_GetResolvedPath);

    bbl::Class<PXR_NS::VtArray<PXR_NS::SdfAssetPath>>("AssetPathArray");

    bbl::Class<PXR_NS::SdfAttributeSpec>("AttributeSpec")
        .ctor(bbl::Class<PXR_NS::SdfAttributeSpec>::Ctor<>(), "default")
        .m(&PXR_NS::SdfAttributeSpec::New)
        .m(&PXR_NS::SdfAttributeSpec::HasConnectionPaths)
        .m(&PXR_NS::SdfAttributeSpec::ClearConnectionPaths)
        .m(&PXR_NS::SdfAttributeSpec::GetAllowedTokens)
        .m(&PXR_NS::SdfAttributeSpec::HasAllowedTokens)
        .m(&PXR_NS::SdfAttributeSpec::SetAllowedTokens)
        // missing SdfListEditorProxy<SdfPathKeyPolicy>
        // .m(&PXR_NS::SdfAttributeSpec::GetConnectionPathList)
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
    ;

    bbl::Class<PXR_NS::SdfAttributeSpecHandle>("AttributeSpecHandle")
        .smartptr_to<PXR_NS::SdfAttributeSpec>()
    ;

    bbl::Class<PXR_NS::SdfAttributeSpecHandleVector>("AttributeSpecHandleVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfAttributeSpecHandle)
    ;

    
    /// XXX: what's this
    bbl::Class<PXR_NS::SdfAttributeSpecView>("AttributeSpecView");

    bbl::Class<PXR_NS::SdfChangeBlock>("ChangeBlock")
        .ctor(bbl::Class<PXR_NS::SdfChangeBlock>::Ctor<>(), "default")
        ;

    bbl::Class<PXR_NS::SdfChangeList>("ChangeList")
    #if 0 /// XXX: these are failing to link
        .ctor(bbl::Class<PXR_NS::SdfChangeList>::Ctor<>(), "default")
        .m(&PXR_NS::SdfChangeList::DidReplaceLayerContent)
        .m(&PXR_NS::SdfChangeList::DidReloadLayerContent)
        .m(&PXR_NS::SdfChangeList::DidChangeLayerResolvedPath)
        .m(&PXR_NS::SdfChangeList::DidChangeLayerIdentifier)
        .m(&PXR_NS::SdfChangeList::DidChangeSublayerPaths)
        .m(&PXR_NS::SdfChangeList::DidAddPrim)
        .m(&PXR_NS::SdfChangeList::DidRemovePrim)
        .m(&PXR_NS::SdfChangeList::DidReorderPrims)
        .m(&PXR_NS::SdfChangeList::DidChangePrimName)
        .m(&PXR_NS::SdfChangeList::DidChangePrimVariantSets)
        .m(&PXR_NS::SdfChangeList::DidChangePrimInheritPaths)
        .m(&PXR_NS::SdfChangeList::DidChangePrimReferences)
        .m(&PXR_NS::SdfChangeList::DidChangePrimSpecializes)
        .m(&PXR_NS::SdfChangeList::DidAddProperty)
        .m(&PXR_NS::SdfChangeList::DidRemoveProperty)
        .m(&PXR_NS::SdfChangeList::DidReorderProperties)
        .m(&PXR_NS::SdfChangeList::DidChangePropertyName)
        .m(&PXR_NS::SdfChangeList::DidChangeAttributeTimeSamples)
        .m(&PXR_NS::SdfChangeList::DidChangeAttributeConnection)
        .m(&PXR_NS::SdfChangeList::DidChangeRelationshipTargets)
        .m(&PXR_NS::SdfChangeList::DidAddTarget)
        .m(&PXR_NS::SdfChangeList::DidRemoveTarget)
        // r-vbalue reference
        // .m(&PXR_NS::SdfChangeList::DidChangeInfo)
        .m(&PXR_NS::SdfChangeList::GetEntryList)
        .m(&PXR_NS::SdfChangeList::GetEntry)
        .m(&PXR_NS::SdfChangeList::FindEntry)
        .m(&PXR_NS::SdfChangeList::begin)
        .m(&PXR_NS::SdfChangeList::cbegin)
        .m(&PXR_NS::SdfChangeList::end)
        .m(&PXR_NS::SdfChangeList::cend)
    #endif
    ;

    bbl::Class<PXR_NS::SdfChangeList::Entry>("SdfChangeListEntry")
        .ctor(bbl::Class<PXR_NS::SdfChangeList::Entry>::Ctor<>(), "default")
        // .m(&PXR_NS::SdfChangeList::Entry::FindInfoChange)
        .m(&PXR_NS::SdfChangeList::Entry::HasInfoChange)
    ;

    bbl::Class<PXR_NS::SdfChangeList::EntryList>("ChangeListEntryList")
    ;

    bbl::Enum<PXR_NS::SdfChangeList::SubLayerChangeType>("SdfChangeListSubLayerChangeType");

    bbl::Class<std::pair<PXR_NS::SdfPath, PXR_NS::SdfChangeList::Entry>>("PathChangeListEntryPair")
    ;

    bbl::Class<PXR_NS::SdfLayerChangeListVec>("LayerChangeListVec")
    ;

    bbl::Class<PXR_NS::SdfCopySpecsValueEdit>()
        // editfunction missing a type
        // .ctor(bbl::Class<PXR_NS::SdfCopySpecsValueEdit>::Ctor<const PXR_NS::SdfCopySpecsValueEdit::EditFunction &>("edit"), "ctor_00")
        // Need to return a function here... not possible?
        // .m(&PXR_NS::SdfCopySpecsValueEdit::GetEditFunction)
    ;

    bbl::Class<PXR_NS::SdfCopySpecsValueEdit::EditFunction>("SdfCopySpecsValueEditEditFunction");

    bbl::Class<PXR_NS::SdfData>()
        .ctor(bbl::Class<PXR_NS::SdfData>::Ctor<>(), "default")
        .m(&PXR_NS::SdfData::StreamsData)
        .m(&PXR_NS::SdfData::IsDetached)
        .m(&PXR_NS::SdfData::CreateSpec)
        .m(&PXR_NS::SdfData::HasSpec)
        .m(&PXR_NS::SdfData::EraseSpec)
        .m(&PXR_NS::SdfData::MoveSpec)
        .m(&PXR_NS::SdfData::GetSpecType)
        .m((bool (PXR_NS::SdfData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, PXR_NS::SdfAbstractDataValue *) const)
            &PXR_NS::SdfData::Has, "Has_00")
        .m((bool (PXR_NS::SdfData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, PXR_NS::VtValue *) const)
            &PXR_NS::SdfData::Has, "Has_01")
        .m((bool (PXR_NS::SdfData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, PXR_NS::SdfAbstractDataValue *, PXR_NS::SdfSpecType *) const)
            &PXR_NS::SdfData::HasSpecAndField, "HasSpecAndField_00")
        .m((bool (PXR_NS::SdfData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, PXR_NS::VtValue *, PXR_NS::SdfSpecType *) const)
            &PXR_NS::SdfData::HasSpecAndField, "HasSpecAndField_01")
        .m(&PXR_NS::SdfData::Get)
        .m((void (PXR_NS::SdfData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::VtValue &))
            &PXR_NS::SdfData::Set, "Set_00")
        .m((void (PXR_NS::SdfData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::SdfAbstractDataConstValue &))
            &PXR_NS::SdfData::Set, "Set_01")
        .m(&PXR_NS::SdfData::Erase)
        .m(&PXR_NS::SdfData::List)
        .m(&PXR_NS::SdfData::ListAllTimeSamples)
        .m(&PXR_NS::SdfData::ListTimeSamplesForPath)
        .m(&PXR_NS::SdfData::GetBracketingTimeSamples)
        .m(&PXR_NS::SdfData::GetNumTimeSamplesForPath)
        .m(&PXR_NS::SdfData::GetBracketingTimeSamplesForPath)
        .m(&PXR_NS::SdfData::SetTimeSample)
        .m(&PXR_NS::SdfData::EraseTimeSample)
    ;

    bbl::Class<PXR_NS::SdfFileFormat>()
        .m(&PXR_NS::SdfFileFormat::GetSchema)
        .m(&PXR_NS::SdfFileFormat::GetFormatId)
        .m(&PXR_NS::SdfFileFormat::GetTarget)
        .m(&PXR_NS::SdfFileFormat::GetFileCookie)
        .m(&PXR_NS::SdfFileFormat::GetVersionString)
        .m(&PXR_NS::SdfFileFormat::IsPrimaryFormatForExtensions)
        .m(&PXR_NS::SdfFileFormat::GetFileExtensions)
        .m(&PXR_NS::SdfFileFormat::GetPrimaryFileExtension)
        .m(&PXR_NS::SdfFileFormat::IsSupportedExtension)
        .m(&PXR_NS::SdfFileFormat::IsPackage)
        .m(&PXR_NS::SdfFileFormat::GetPackageRootLayerPath)
        .m(&PXR_NS::SdfFileFormat::GetDefaultFileFormatArguments)
        .m(&PXR_NS::SdfFileFormat::InitData)
        .m(&PXR_NS::SdfFileFormat::InitDetachedData)
        .m(&PXR_NS::SdfFileFormat::NewLayer)
        .m(&PXR_NS::SdfFileFormat::ShouldSkipAnonymousReload)
        .m(&PXR_NS::SdfFileFormat::ShouldReadAnonymousLayers)
        .m(&PXR_NS::SdfFileFormat::CanRead)
        .m(&PXR_NS::SdfFileFormat::Read)
        .m(&PXR_NS::SdfFileFormat::ReadDetached)
        .m(&PXR_NS::SdfFileFormat::WriteToFile)
        .m(&PXR_NS::SdfFileFormat::ReadFromString)
        // .m(&PXR_NS::SdfFileFormat::WriteToStream)
        .m(&PXR_NS::SdfFileFormat::WriteToString)
        .m(&PXR_NS::SdfFileFormat::GetExternalAssetDependencies)
        .m(&PXR_NS::SdfFileFormat::SupportsReading)
        .m(&PXR_NS::SdfFileFormat::SupportsWriting)
        .m(&PXR_NS::SdfFileFormat::SupportsEditing)
        .m(&PXR_NS::SdfFileFormat::GetFileExtension)
        .m(&PXR_NS::SdfFileFormat::FindAllFileFormatExtensions)
        .m(&PXR_NS::SdfFileFormat::FindAllDerivedFileFormatExtensions)
        .m(&PXR_NS::SdfFileFormat::FormatSupportsReading)
        .m(&PXR_NS::SdfFileFormat::FormatSupportsWriting)
        .m(&PXR_NS::SdfFileFormat::FormatSupportsEditing)
        .m(&PXR_NS::SdfFileFormat::FindById)
        .m((PXR_NS::SdfFileFormatConstPtr (*)(const std::string &, const std::string &))
            &PXR_NS::SdfFileFormat::FindByExtension, "FindByExtension_00")
        .m((PXR_NS::SdfFileFormatConstPtr (*)(const std::string &, const PXR_NS::SdfFileFormat::FileFormatArguments &))
            &PXR_NS::SdfFileFormat::FindByExtension, "FindByExtension_01")
    ;

    bbl::Superclass<bblext::FileFormatBase>()
        .ctor(bbl::Superclass<bblext::FileFormatBase>::Ctor<PXR_NS::TfToken const&, PXR_NS::TfToken const&, PXR_NS::TfToken const&, char const*>("formatId", "versionString", "target", "extension"), "ctor")
        .m(&bblext::FileFormatBase::_ReadAndCopyLayerDataToMemory)
        .m(&bblext::FileFormatBase::_InstantiateNewLayer)
        .m(&bblext::FileFormatBase::_InstantiateNewLayer_base)
        .m(&bblext::FileFormatBase::_ShouldSkipAnonymousReload)
        .m(&bblext::FileFormatBase::_ShouldSkipAnonymousReload_base)
        .m(&bblext::FileFormatBase::_ShouldReadAnonymousLayers)
        .m(&bblext::FileFormatBase::_ShouldReadAnonymousLayers_base)
        .m(&bblext::FileFormatBase::_InitDetachedData)
        .m(&bblext::FileFormatBase::_InitDetachedData_base)
        .m(&bblext::FileFormatBase::_ReadDetached)
        .m(&bblext::FileFormatBase::_ReadDetached_base)
        .m(&bblext::FileFormatBase::_SetLayerData)
        .m(&bblext::FileFormatBase::_SetLayerData_with_hints)
        .m(&bblext::FileFormatBase::_GetLayerData)
    ;

    bbl::Class<PXR_NS::SdfFileFormatConstPtr>("FileFormatConstPtr")
        .smartptr_to<PXR_NS::SdfFileFormat const>()
    ;

    bbl::Class<PXR_NS::SdfFileFormat::FileFormatArguments>("FileFormatFileFormatArguments")
        .ctor(bbl::Class<PXR_NS::SdfFileFormat::FileFormatArguments>::Ctor(), "default");

    bbl::Class<PXR_NS::SdfLayer>("Layer")
        // Constructors
        .m((PXR_NS::SdfLayerRefPtr(*)(const std::string&, const PXR_NS::SdfLayer::FileFormatArguments&))
            &PXR_NS::SdfLayer::CreateAnonymous)
        .m(&PXR_NS::SdfLayer::ImportFromString)
        .m(&PXR_NS::SdfLayer::FindOrOpen)

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
        .m(&PXR_NS::SdfLayer::GetIdentifier)

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

    bbl::fn(&bblext::LayerHandle_ExportToString);
    bbl::fn(&bblext::LayerRefPtr_ExportToString);

    bbl::Class<PXR_NS::SdfLayerHandle>("LayerHandle")
        .smartptr_to<PXR_NS::SdfLayer>()
    ;

    bbl::Class<PXR_NS::SdfLayerRefPtr>("LayerRefPtr")
        .smartptr_to<PXR_NS::SdfLayer>()
    ;

    bbl::Class<PXR_NS::SdfLayerHandleVector>("LayerHandleVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfLayerHandle)
    ;

    bbl::Class<PXR_NS::SdfLayerRefPtrVector>("LayerRefPtrVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfLayerRefPtr)
    ;

    bbl::Class<PXR_NS::SdfLayerHandleSet>("LayerHandleSet")
    ;

    bbl::Class<PXR_NS::SdfLayerHints>("LayerHints")
        .value_type()
        .f(&PXR_NS::SdfLayerHints::mightHaveRelocates)
    ;

    bbl::Class<PXR_NS::SdfLayerOffset>("LayerOffset")
        .ctor(bbl::Class<PXR_NS::SdfLayerOffset>::Ctor<double, double>("offset", "scale"), "ctor")
        .ctor(bbl::Class<PXR_NS::SdfLayerOffset>::Ctor(), "default")
        .m(&PXR_NS::SdfLayerOffset::GetOffset)
        .m(&PXR_NS::SdfLayerOffset::GetScale)
        .m(&PXR_NS::SdfLayerOffset::SetOffset)
        .m(&PXR_NS::SdfLayerOffset::SetScale)
        .m(&PXR_NS::SdfLayerOffset::IsIdentity)
        .m(&PXR_NS::SdfLayerOffset::IsValid)
        .m(&PXR_NS::SdfLayerOffset::GetInverse)
        .m(&PXR_NS::SdfLayerOffset::GetHash)
        .m(&PXR_NS::SdfLayerOffset::operator==, "op_eq")
        .m(&PXR_NS::SdfLayerOffset::operator<, "op_lt")
        .m((PXR_NS::SdfLayerOffset (PXR_NS::SdfLayerOffset::*)(const PXR_NS::SdfLayerOffset &) const)
            &PXR_NS::SdfLayerOffset::operator*, "op_mul_00")
        .m((double (PXR_NS::SdfLayerOffset::*)(double) const)
            &PXR_NS::SdfLayerOffset::operator*, "op_mul_01")
        .m((PXR_NS::SdfTimeCode (PXR_NS::SdfLayerOffset::*)(const PXR_NS::SdfTimeCode &) const)
            &PXR_NS::SdfLayerOffset::operator*, "op_mul_02")
    ;

    bbl::Class<PXR_NS::SdfLayerOffsetVector>("LayerOffsetVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfLayerOffset)
        ;

    bbl::Class<PXR_NS::SdfLayerStateDelegateBase>("LayerStateDelegate")
        .m(&PXR_NS::SdfLayerStateDelegateBase::IsDirty)
        .m((void (PXR_NS::SdfLayerStateDelegateBase::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::VtValue &, PXR_NS::VtValue *))
            &PXR_NS::SdfLayerStateDelegateBase::SetField, "SetField_00")
        .m((void (PXR_NS::SdfLayerStateDelegateBase::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::SdfAbstractDataConstValue &, PXR_NS::VtValue *))
            &PXR_NS::SdfLayerStateDelegateBase::SetField, "SetField_01")
        .m((void (PXR_NS::SdfLayerStateDelegateBase::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::TfToken &, const PXR_NS::VtValue &, PXR_NS::VtValue *))
            &PXR_NS::SdfLayerStateDelegateBase::SetFieldDictValueByKey, "SetFieldDictValueByKey_00")
        .m((void (PXR_NS::SdfLayerStateDelegateBase::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::TfToken &, const PXR_NS::SdfAbstractDataConstValue &, PXR_NS::VtValue *))
            &PXR_NS::SdfLayerStateDelegateBase::SetFieldDictValueByKey, "SetFieldDictValueByKey_01")
        .m((void (PXR_NS::SdfLayerStateDelegateBase::*)(const PXR_NS::SdfPath &, double, const PXR_NS::VtValue &))
            &PXR_NS::SdfLayerStateDelegateBase::SetTimeSample, "SetTimeSample_00")
        .m((void (PXR_NS::SdfLayerStateDelegateBase::*)(const PXR_NS::SdfPath &, double, const PXR_NS::SdfAbstractDataConstValue &))
            &PXR_NS::SdfLayerStateDelegateBase::SetTimeSample, "SetTimeSample_01")
        .m(&PXR_NS::SdfLayerStateDelegateBase::CreateSpec)
        .m(&PXR_NS::SdfLayerStateDelegateBase::DeleteSpec)
        .m(&PXR_NS::SdfLayerStateDelegateBase::MoveSpec)
        .m((void (PXR_NS::SdfLayerStateDelegateBase::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::TfToken &))
            &PXR_NS::SdfLayerStateDelegateBase::PushChild, "PushChild_00")
        .m((void (PXR_NS::SdfLayerStateDelegateBase::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::SdfPath &))
            &PXR_NS::SdfLayerStateDelegateBase::PushChild, "PushChild_01")
        .m((void (PXR_NS::SdfLayerStateDelegateBase::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::TfToken &))
            &PXR_NS::SdfLayerStateDelegateBase::PopChild, "PopChild_00")
        .m((void (PXR_NS::SdfLayerStateDelegateBase::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, const PXR_NS::SdfPath &))
            &PXR_NS::SdfLayerStateDelegateBase::PopChild, "PopChild_01")
    ;

    bbl::Class<PXR_NS::SdfLayerTree>("LayerTree")
        .m(&PXR_NS::SdfLayerTree::New)
        .m(&PXR_NS::SdfLayerTree::GetLayer)
        .m(&PXR_NS::SdfLayerTree::GetOffset)
        .m(&PXR_NS::SdfLayerTree::GetChildTrees)
    ;

    bbl::Class<PXR_NS::SdfLayerTreeHandle>("LayerTreeHandle")
        .smartptr_to<PXR_NS::SdfLayerTree>()
    ;

    bbl::Class<PXR_NS::SdfLayerTreeHandleVector>("LayerTreeHandleVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfLayerTreeHandle)
    ;

    using StringListOp = PXR_NS::SdfListOp<std::string>;

    bbl::Class<PXR_NS::SdfListOp<std::string>>("StringListOp")
        .ctor(bbl::Class<StringListOp>::Ctor<>(), "default")
        .m(&StringListOp::HasKeys)
        .m(&StringListOp::IsExplicit)
        .m(&StringListOp::GetExplicitItems)
        .m(&StringListOp::GetAddedItems)
        .m(&StringListOp::GetPrependedItems)
        .m(&StringListOp::GetAppendedItems)
        .m(&StringListOp::GetDeletedItems)
        .m(&StringListOp::GetOrderedItems)
        .m(&StringListOp::GetAppliedItems)
        .m(&StringListOp::GetItems)
        .m(&StringListOp::GetAppliedItems)
        .m(&StringListOp::SetExplicitItems)
        .m(&StringListOp::SetAddedItems)
        .m(&StringListOp::SetPrependedItems)
        .m(&StringListOp::SetAppendedItems)
        .m(&StringListOp::SetDeletedItems)
        .m(&StringListOp::SetOrderedItems)
        .m(&StringListOp::SetItems)
        .m(&StringListOp::Clear)
        .m(&StringListOp::ClearAndMakeExplicit)
        // .m((void (StringListOp::*)(StringListOp::ItemVector *, const StringListOp::ApplyCallback &) const)
        //     &StringListOp::ApplyOperations, "ApplyOperations")
        // .m(&StringListOp::ModifyOperations)
        .m(&StringListOp::ReplaceOperations)
        .m(&StringListOp::ComposeOperations)
        ;

    // bbl::Class<StringListOp::ApplyCallback>("StringListOpApplyCallback")
    // ;

    // bbl::Class<StringListOp::ModifyCallback>("StringListOpModifyCallback")
    // ;

    bbl::Enum<PXR_NS::SdfListOpType>("ListOpType");

    bbl::Class<PXR_NS::SdfNamespaceEdit>("NamespaceEdit")
        .ctor(bbl::Class<PXR_NS::SdfNamespaceEdit>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::SdfNamespaceEdit>::Ctor<PXR_NS::SdfNamespaceEdit::Path const&, PXR_NS::SdfNamespaceEdit::Path const&, PXR_NS::SdfNamespaceEdit::Index>(), "from_paths")
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
        .ctor(bbl::Class<PXR_NS::SdfNamespaceEditDetail>::Ctor<>(), "default")
    ;

    bbl::Enum<PXR_NS::SdfNamespaceEditDetail::Result>("NamespaceEditDetailResult")
    ;

    bbl::fn(&bblext::NamespaceEditDetail_get_edit);
    bbl::fn(&bblext::NamespaceEditDetail_get_result);
    bbl::fn(&bblext::NamespaceEditDetail_get_reason);

    bbl::Class<PXR_NS::SdfNamespaceEditDetailVector>("NamespaceEditDetailVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfNamespaceEditDetail)
        ;

    bbl::Class<PXR_NS::SdfBatchNamespaceEdit>("BatchNamespaceEdit")
        .ctor(bbl::Class<PXR_NS::SdfBatchNamespaceEdit>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::SdfBatchNamespaceEdit>::Ctor<const PXR_NS::SdfNamespaceEditVector &>("edits"), "from_edits")
        .m((void (PXR_NS::SdfBatchNamespaceEdit::*)(PXR_NS::SdfNamespaceEdit const&))
            &PXR_NS::SdfBatchNamespaceEdit::Add)
        .m((void (PXR_NS::SdfBatchNamespaceEdit::*)(PXR_NS::SdfNamespaceEdit::Path const&, PXR_NS::SdfNamespaceEdit::Path const&, PXR_NS::SdfNamespaceEdit::Index))
            &PXR_NS::SdfBatchNamespaceEdit::Add,"Add_from_paths")
        .m(&PXR_NS::SdfBatchNamespaceEdit::GetEdits)
        .m(&PXR_NS::SdfBatchNamespaceEdit::Process)
    ;

    bbl::Class<PXR_NS::SdfBatchNamespaceEdit::CanEdit>("BatchNamespaceEditCanEdit");
    bbl::Class<PXR_NS::SdfBatchNamespaceEdit::HasObjectAtPath>("BatchNamespaceEditHasObjectAtPath");

    bbl::Class<PXR_NS::SdfNotice>("Notice")
    ;

    bbl::Class<PXR_NS::SdfNotice::Base>("NoticeBase")
        .ctor(bbl::Class<PXR_NS::SdfNotice::Base>::Ctor<>(), "default")
    ;

    bbl::Class<PXR_NS::SdfNotice::BaseLayersDidChange>("NoticeBaseLayersDidChange")
        .ctor(bbl::Class<PXR_NS::SdfNotice::BaseLayersDidChange>::Ctor<const PXR_NS::SdfLayerChangeListVec &, size_t>("changeVec", "serialNumber"), "ctor")
        .m(&PXR_NS::SdfNotice::BaseLayersDidChange::GetLayers)
        .m(&PXR_NS::SdfNotice::BaseLayersDidChange::GetChangeListVec)
        .m(&PXR_NS::SdfNotice::BaseLayersDidChange::begin)
        .m(&PXR_NS::SdfNotice::BaseLayersDidChange::cbegin)
        .m(&PXR_NS::SdfNotice::BaseLayersDidChange::end)
        .m(&PXR_NS::SdfNotice::BaseLayersDidChange::cend)
        .m(&PXR_NS::SdfNotice::BaseLayersDidChange::find)
        .m(&PXR_NS::SdfNotice::BaseLayersDidChange::count)
        .m(&PXR_NS::SdfNotice::BaseLayersDidChange::GetSerialNumber)
    ;

    bbl::Class<PXR_NS::SdfNotice::BaseLayersDidChange::const_iterator>("NoticeBaseLayersDidChangeConstIterator")
    ;

    bbl::Class<PXR_NS::SdfNotice::LayersDidChangeSentPerLayer>("NoticeLayersDidChangeSentPerLayer")
        .ctor(bbl::Class<PXR_NS::SdfNotice::LayersDidChangeSentPerLayer>::Ctor<const PXR_NS::SdfLayerChangeListVec &, size_t>("changeVec", "serialNumber"), "ctor")
    ;

    bbl::Class<PXR_NS::SdfNotice::LayersDidChange>("NoticeLayersDidChange")
        .ctor(bbl::Class<PXR_NS::SdfNotice::LayersDidChange>::Ctor<const PXR_NS::SdfLayerChangeListVec &, size_t>("changeVec", "serialNumber"), "ctor")
    ;

    bbl::Class<PXR_NS::SdfNotice::LayerInfoDidChange>("NoticeLayerInfoDidChange")
        .ctor(bbl::Class<PXR_NS::SdfNotice::LayerInfoDidChange>::Ctor<const PXR_NS::TfToken &>("key"), "ctor")
        .m(&PXR_NS::SdfNotice::LayerInfoDidChange::key)
    ;

    bbl::Class<PXR_NS::SdfNotice::LayerIdentifierDidChange>("NoticeLayerIdentifierDidChange")
        .ctor(bbl::Class<PXR_NS::SdfNotice::LayerIdentifierDidChange>::Ctor<const std::string &, const std::string &>("oldIdentifier", "newIdentifier"), "ctor")
        .m(&PXR_NS::SdfNotice::LayerIdentifierDidChange::GetOldIdentifier)
        .m(&PXR_NS::SdfNotice::LayerIdentifierDidChange::GetNewIdentifier)
    ;

    bbl::Class<PXR_NS::SdfNotice::LayerDidReplaceContent>("NoticeLayerDidReplaceContent")
    ;

    bbl::Class<PXR_NS::SdfNotice::LayerDidReloadContent>("NoticeLayerDidReloadContent")
    ;

    bbl::Class<PXR_NS::SdfNotice::LayerDidSaveLayerToFile>("NoticeDidSaveLayerToFile")
    ;

    bbl::Class<PXR_NS::SdfNotice::LayerDirtinessChanged>("NoticeLayerDirtinessChanged")
    ;

    bbl::Class<PXR_NS::SdfNotice::LayerMutenessChanged>("NoticeLayerMutenessChanged")
        .ctor(bbl::Class<PXR_NS::SdfNotice::LayerMutenessChanged>::Ctor<const std::string &, bool>("layerPath", "wasMuted"), "ctor")
        .m(&PXR_NS::SdfNotice::LayerMutenessChanged::GetLayerPath)
        .m(&PXR_NS::SdfNotice::LayerMutenessChanged::WasMuted)
    ;

    bbl::Class<PXR_NS::SdfPath>("Path")
        .ctor(bbl::Class<PXR_NS::SdfPath>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::SdfPath>::Ctor<char const*>("path"), "from_string")
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
        .m(&PXR_NS::SdfPath::RemoveAncestorPaths)
    ;

    bbl::Class<PXR_NS::SdfPathSet>("PathSet")
    ;

    bbl::Class<PXR_NS::SdfPathVector>("PathVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfPath)
    ;

    bbl::Class<PXR_NS::SdfPathExpression>()
        .ctor(bbl::Class<PXR_NS::SdfPathExpression>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::SdfPathExpression>::Ctor<const std::string &, const std::string &>("expr", "parseContext"), "ctor_01")
        .m((PXR_NS::SdfPathExpression (*)(PXR_NS::SdfPathExpression &&))
            &PXR_NS::SdfPathExpression::MakeComplement, "MakeComplement_00")
        .m((PXR_NS::SdfPathExpression (*)(const PXR_NS::SdfPathExpression &))
            &PXR_NS::SdfPathExpression::MakeComplement, "MakeComplement_01")
        .m((PXR_NS::SdfPathExpression (*)(PXR_NS::SdfPathExpression::Op, PXR_NS::SdfPathExpression &&, PXR_NS::SdfPathExpression &&))
            &PXR_NS::SdfPathExpression::MakeOp, "MakeOp_00")
        .m((PXR_NS::SdfPathExpression (*)(PXR_NS::SdfPathExpression::Op, const PXR_NS::SdfPathExpression &, const PXR_NS::SdfPathExpression &))
            &PXR_NS::SdfPathExpression::MakeOp, "MakeOp_01")
        .m((PXR_NS::SdfPathExpression (*)(const PXR_NS::SdfPathExpression::ExpressionReference &))
            &PXR_NS::SdfPathExpression::MakeAtom, "MakeAtom_01")
        .m((PXR_NS::SdfPathExpression (*)(const PXR_NS::SdfPathExpression::PathPattern &))
            &PXR_NS::SdfPathExpression::MakeAtom, "MakeAtom_03")
        // .m(&PXR_NS::SdfPathExpression::Walk)
        // .m((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(const PXR_NS::SdfPath &, const PXR_NS::SdfPath &) const)
        //     &PXR_NS::SdfPathExpression::ReplacePrefix, "ReplacePrefix_00")
        // .m((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(const PXR_NS::SdfPath &, const PXR_NS::SdfPath &))
        //     &PXR_NS::SdfPathExpression::ReplacePrefix, "ReplacePrefix_01")
        // .m(&PXR_NS::SdfPathExpression::IsAbsolute)
        // .m((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(const PXR_NS::SdfPath &) const)
        //     &PXR_NS::SdfPathExpression::MakeAbsolute, "MakeAbsolute_00")
        // .m((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(const PXR_NS::SdfPath &))
        //     &PXR_NS::SdfPathExpression::MakeAbsolute, "MakeAbsolute_01")
        // .m(&PXR_NS::SdfPathExpression::ContainsExpressionReferences)
        // .m((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(TfFunctionRef<SdfPathExpression (const PXR_NS::SdfPathExpression::ExpressionReference &)>) const)
        //     &PXR_NS::SdfPathExpression::ResolveReferences, "ResolveReferences_00")
        // .m((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(TfFunctionRef<SdfPathExpression (const PXR_NS::SdfPathExpression::ExpressionReference &)>))
        //     &PXR_NS::SdfPathExpression::ResolveReferences, "ResolveReferences_01")
        // .m((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(const PXR_NS::SdfPathExpression &) const)
        //     &PXR_NS::SdfPathExpression::ComposeOver, "ComposeOver_00")
        // .m((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(const PXR_NS::SdfPathExpression &))
        //     &PXR_NS::SdfPathExpression::ComposeOver, "ComposeOver_01")
        .m(&PXR_NS::SdfPathExpression::IsComplete)
#if PXR_VERSION <= 2308
        .m(&PXR_NS::SdfPathExpression::GetDebugString)
#endif
        .m(&PXR_NS::SdfPathExpression::IsEmpty)
        .m(&PXR_NS::SdfPathExpression::operator bool, "op_bool")
        .m(&PXR_NS::SdfPathExpression::GetParseError)
    ;

    bbl::Class<PXR_NS::SdfPathExpression::PathPattern>()
        .ctor(bbl::Class<PXR_NS::SdfPathExpression::PathPattern>::Ctor<>(), "default")
        .m((void (PXR_NS::SdfPathExpression::PathPattern::*)(const std::string &, PXR_NS::SdfPredicateExpression &&))
            &PXR_NS::SdfPathExpression::PathPattern::AppendChild, "AppendChild_00")
        .m((void (PXR_NS::SdfPathExpression::PathPattern::*)(const std::string &, const PXR_NS::SdfPredicateExpression &))
            &PXR_NS::SdfPathExpression::PathPattern::AppendChild, "AppendChild_01")
        .m((void (PXR_NS::SdfPathExpression::PathPattern::*)(const std::string &))
            &PXR_NS::SdfPathExpression::PathPattern::AppendChild, "AppendChild_02")
        .m((void (PXR_NS::SdfPathExpression::PathPattern::*)(const std::string &, PXR_NS::SdfPredicateExpression &&))
            &PXR_NS::SdfPathExpression::PathPattern::AppendProperty, "AppendProperty_00")
        .m((void (PXR_NS::SdfPathExpression::PathPattern::*)(const std::string &, const PXR_NS::SdfPredicateExpression &))
            &PXR_NS::SdfPathExpression::PathPattern::AppendProperty, "AppendProperty_01")
        .m((void (PXR_NS::SdfPathExpression::PathPattern::*)(const std::string &))
            &PXR_NS::SdfPathExpression::PathPattern::AppendProperty, "AppendProperty_02")
        // .m((const PXR_NS::SdfPath & (PXR_NS::SdfPathExpression::PathPattern::*)() const)
        //     &PXR_NS::SdfPathExpression::PathPattern::GetPrefix, "GetPrefix_00")
        // .m((PXR_NS::SdfPath (PXR_NS::SdfPathExpression::PathPattern::*)())
        //     &PXR_NS::SdfPathExpression::PathPattern::GetPrefix, "GetPrefix_01")
        .m((void (PXR_NS::SdfPathExpression::PathPattern::*)(PXR_NS::SdfPath &&))
            &PXR_NS::SdfPathExpression::PathPattern::SetPrefix, "SetPrefix_00")
        .m((void (PXR_NS::SdfPathExpression::PathPattern::*)(const PXR_NS::SdfPath &))
            &PXR_NS::SdfPathExpression::PathPattern::SetPrefix, "SetPrefix_01")
#if PXR_VERSION <= 2308
        .m(&PXR_NS::SdfPathExpression::PathPattern::GetDebugString)
#endif
        // .m((const std::vector<PXR_NS::SdfPathExpression::PathPattern::Component> & (PXR_NS::SdfPathExpression::PathPattern::*)() const)
        //     &PXR_NS::SdfPathExpression::PathPattern::GetComponents, "GetComponents_00")
        // .m((std::vector<PXR_NS::SdfPathExpression::PathPattern::Component> (PXR_NS::SdfPathExpression::PathPattern::*)())
        //     &PXR_NS::SdfPathExpression::PathPattern::GetComponents, "GetComponents_01")
        // .m((const std::vector<PXR_NS::SdfPredicateExpression> & (PXR_NS::SdfPathExpression::PathPattern::*)() const)
        //     &PXR_NS::SdfPathExpression::PathPattern::GetPredicateExprs, "GetPredicateExprs_00")
        // .m((std::vector<PXR_NS::SdfPredicateExpression> (PXR_NS::SdfPathExpression::PathPattern::*)())
        //     &PXR_NS::SdfPathExpression::PathPattern::GetPredicateExprs, "GetPredicateExprs_01")
        .m(&PXR_NS::SdfPathExpression::PathPattern::IsProperty)
        .m(&PXR_NS::SdfPathExpression::PathPattern::operator bool, "op_bool")
    ;

    bbl::Class<PXR_NS::SdfPathExpression::PathPattern::Component>()
        .ctor(bbl::Class<PXR_NS::SdfPathExpression::PathPattern::Component>::Ctor<>(), "default")
        .m(&PXR_NS::SdfPathExpression::PathPattern::Component::IsStretch)
    ;

    bbl::Class<PXR_NS::SdfPathExpression::ExpressionReference>()
        .ctor(bbl::Class<PXR_NS::SdfPathExpression::ExpressionReference>::Ctor<>(), "default")
    ;

    bbl::Enum<PXR_NS::SdfPathExpression::Op>();

    bbl::Class<PXR_NS::SdfPayload>("Payload")
        .ctor(bbl::Class<PXR_NS::SdfPayload>::Ctor<>(), "new")
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

    bbl::Class<PXR_NS::SdfPayloadVector>("PayloadVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfPayload)
    ;

    bbl::Class<PXR_NS::SdfPredicateExpression>("PredicateExpression")
        .ctor(bbl::Class<PXR_NS::SdfPredicateExpression>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::SdfPredicateExpression>::Ctor<const std::string &, const std::string &>("expr", "context"), "ctor_01")
        // Need to handle rvalue refs for these: need to std::move the ref in the call
        // .m(&PXR_NS::SdfPredicateExpression::MakeNot)
        // .m(&PXR_NS::SdfPredicateExpression::MakeOp)
        // .m(&PXR_NS::SdfPredicateExpression::MakeCall)
        // .m(&PXR_NS::SdfPredicateExpression::Walk)
        // .m(&PXR_NS::SdfPredicateExpression::WalkWithOpStack)
        .m(&PXR_NS::SdfPredicateExpression::GetText)
        .m(&PXR_NS::SdfPredicateExpression::IsEmpty)
        .m(&PXR_NS::SdfPredicateExpression::operator bool, "op_bool")
        // .m((const std::string & (PXR_NS::SdfPredicateExpression::*)() const)
        //     &PXR_NS::SdfPredicateExpression::GetParseError, "GetParseError_00")
        // .m((std::string (PXR_NS::SdfPredicateExpression::*)() const)
        //     &PXR_NS::SdfPredicateExpression::GetParseError, "GetParseError_01")
    ;

    bbl::Class<PXR_NS::SdfPredicateExpression::FnArg>("PredicateExpressionFnArg")
        .ctor(bbl::Class<PXR_NS::SdfPredicateExpression::FnArg>::Ctor<>(), "default")
        .m(&PXR_NS::SdfPredicateExpression::FnArg::Positional)
        .m(&PXR_NS::SdfPredicateExpression::FnArg::Keyword)
    ;

    bbl::Class<PXR_NS::SdfPredicateExpression::FnCall>("PredicateExpressionFnCall")
        .ctor(bbl::Class<PXR_NS::SdfPredicateExpression::FnCall>::Ctor<>(), "default")
    ;

    bbl::Enum<PXR_NS::SdfPredicateExpression::FnCall::Kind>("PredicateExpressionFnCallKind");

    bbl::Enum<PXR_NS::SdfPredicateExpression::Op>("PredicateExpressionOp");

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

    bbl::Class<PXR_NS::SdfPropertySpec>("PropertySpec")
        .ctor(bbl::Class<PXR_NS::SdfPropertySpec>::Ctor<>(), "default")
        .m(&PXR_NS::SdfPropertySpec::GetName)
        .m(&PXR_NS::SdfPropertySpec::GetNameToken)
        .m(&PXR_NS::SdfPropertySpec::CanSetName)
        .m(&PXR_NS::SdfPropertySpec::SetName)
        .m(&PXR_NS::SdfPropertySpec::IsValidName)
        .m(&PXR_NS::SdfPropertySpec::GetOwner)
        .m(&PXR_NS::SdfPropertySpec::GetCustomData)
        .m(&PXR_NS::SdfPropertySpec::GetAssetInfo)
        .m(&PXR_NS::SdfPropertySpec::SetCustomData)
        .m(&PXR_NS::SdfPropertySpec::SetAssetInfo)
        .m(&PXR_NS::SdfPropertySpec::GetDisplayGroup)
        .m(&PXR_NS::SdfPropertySpec::SetDisplayGroup)
        .m(&PXR_NS::SdfPropertySpec::GetDisplayName)
        .m(&PXR_NS::SdfPropertySpec::SetDisplayName)
        .m(&PXR_NS::SdfPropertySpec::GetDocumentation)
        .m(&PXR_NS::SdfPropertySpec::SetDocumentation)
        .m(&PXR_NS::SdfPropertySpec::GetHidden)
        .m(&PXR_NS::SdfPropertySpec::SetHidden)
        .m(&PXR_NS::SdfPropertySpec::GetPermission)
        .m(&PXR_NS::SdfPropertySpec::SetPermission)
        .m(&PXR_NS::SdfPropertySpec::GetPrefix)
        .m(&PXR_NS::SdfPropertySpec::SetPrefix)
        .m(&PXR_NS::SdfPropertySpec::GetSuffix)
        .m(&PXR_NS::SdfPropertySpec::SetSuffix)
        .m(&PXR_NS::SdfPropertySpec::GetSymmetricPeer)
        .m(&PXR_NS::SdfPropertySpec::SetSymmetricPeer)
        .m(&PXR_NS::SdfPropertySpec::GetSymmetryArguments)
        .m(&PXR_NS::SdfPropertySpec::SetSymmetryArgument)
        .m(&PXR_NS::SdfPropertySpec::GetSymmetryFunction)
        .m(&PXR_NS::SdfPropertySpec::SetSymmetryFunction)
        .m(&PXR_NS::SdfPropertySpec::GetTimeSampleMap)
        .m(&PXR_NS::SdfPropertySpec::GetValueType)
        .m(&PXR_NS::SdfPropertySpec::GetTypeName)
        .m(&PXR_NS::SdfPropertySpec::GetDefaultValue)
        .m(&PXR_NS::SdfPropertySpec::SetDefaultValue)
        .m(&PXR_NS::SdfPropertySpec::HasDefaultValue)
        .m(&PXR_NS::SdfPropertySpec::ClearDefaultValue)
        .m(&PXR_NS::SdfPropertySpec::GetComment)
        .m(&PXR_NS::SdfPropertySpec::SetComment)
        .m(&PXR_NS::SdfPropertySpec::IsCustom)
        .m(&PXR_NS::SdfPropertySpec::SetCustom)
        .m(&PXR_NS::SdfPropertySpec::GetVariability)
        .m(&PXR_NS::SdfPropertySpec::HasOnlyRequiredFields)
    ;

    bbl::Class<PXR_NS::SdfPropertySpecHandle>("PropertySpecHandle")
        .smartptr_to<PXR_NS::SdfPropertySpec>()
    ;

    bbl::Class<PXR_NS::SdfPropertySpecHandleVector>("PropertySpecHandleVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfPropertySpecHandle)
    ;

    bbl::Class<std::pair<PXR_NS::SdfPropertySpecHandle, PXR_NS::SdfLayerOffset>>("PropertySpecHandleOffsetPair");

    bbl::Class<std::vector<std::pair<PXR_NS::SdfPropertySpecHandle, PXR_NS::SdfLayerOffset>>>("PropertySpecHandleOffsetPairVector")
        BBL_STD_VECTOR_METHODS((std::pair<PXR_NS::SdfPropertySpecHandle, PXR_NS::SdfLayerOffset>))
    ;

    bbl::Class<PXR_NS::SdfPropertySpecView>("PropertySpecView");

    bbl::Class<PXR_NS::SdfDictionaryProxy>("DictionaryProxy")
    ;

    bbl::Class<PXR_NS::SdfNameOrderProxy>("NameOrderProxy")
    ;

    bbl::Class<PXR_NS::SdfSubLayerProxy>("SubLayerProxy")
    ;

    bbl::Class<PXR_NS::SdfNameEditorProxy>("NameEditorProxy")
    ;

    bbl::Class<PXR_NS::SdfPathEditorProxy>("PathEditorProxy")
    ;

    bbl::Class<PXR_NS::SdfPayloadEditorProxy>("PayloadEditorProxy")
    ;

    bbl::Class<PXR_NS::SdfReferenceEditorProxy>("ReferenceEditorProxy")
    ;

    bbl::Class<PXR_NS::SdfVariantSelectionProxy>("VariantSelectionProxy")
    ;

    bbl::Class<PXR_NS::SdfRelocatesMapProxy>("RelocatesMapProxy")
    ;

    bbl::Class<PXR_NS::SdfVariantSetsProxy>("VariantSetsProxy")
    ;

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

    // bbl::Class<PXR_NS::SdfReferenceEditorProxy>("ReferenceEditorProxy");

    bbl::Class<PXR_NS::SdfReferenceVector>("ReferenceVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfReference);

    bbl::Class<PXR_NS::SdfRelationshipSpec>("RelationshipSpec")
        .m(&PXR_NS::SdfRelationshipSpec::New)
        .m(&PXR_NS::SdfRelationshipSpec::GetNoLoadHint)
        .m(&PXR_NS::SdfRelationshipSpec::SetNoLoadHint)
        .m(&PXR_NS::SdfRelationshipSpec::GetTargetPathList)
        .m(&PXR_NS::SdfRelationshipSpec::HasTargetPathList)
        .m(&PXR_NS::SdfRelationshipSpec::ClearTargetPathList)
        .m(&PXR_NS::SdfRelationshipSpec::ReplaceTargetPath)
        .m(&PXR_NS::SdfRelationshipSpec::RemoveTargetPath)
        ;


    bbl::Class<PXR_NS::SdfRelationshipSpecHandle>("RelationshipSpecHandle")
        .smartptr_to<PXR_NS::SdfRelationshipSpec>()
    ;

    bbl::Class<PXR_NS::SdfRelationshipSpecHandleVector>("RelationshipSpecHandleVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfRelationshipSpecHandle)
    ;

    bbl::Class<PXR_NS::SdfRelationshipSpecView>("RelationshipSpecView");

    bbl::Class<std::pair<PXR_NS::SdfRelationshipSpecHandle, PXR_NS::SdfLayerOffset>>("RelationshipSpecHandleOffsetPair")
    ;

    bbl::Class<std::vector< std::pair<PXR_NS::SdfRelationshipSpecHandle, PXR_NS::SdfLayerOffset>>>( "RelationshipSpecHandleOffsetPairVector") 
        BBL_STD_VECTOR_METHODS((std::pair<PXR_NS::SdfRelationshipSpecHandle, PXR_NS::SdfLayerOffset>))
    ;

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

    bbl::Class<PXR_NS::SdfSpec>()
        .ctor(bbl::Class<PXR_NS::SdfSpec>::Ctor<>(), "default")
        .m(&PXR_NS::SdfSpec::GetSchema)
        .m(&PXR_NS::SdfSpec::GetSpecType)
        .m(&PXR_NS::SdfSpec::IsDormant)
        .m(&PXR_NS::SdfSpec::GetLayer)
        .m(&PXR_NS::SdfSpec::GetPath)
        .m(&PXR_NS::SdfSpec::PermissionToEdit)
        .m(&PXR_NS::SdfSpec::ListInfoKeys)
        .m(&PXR_NS::SdfSpec::GetMetaDataInfoKeys)
        .m(&PXR_NS::SdfSpec::GetMetaDataDisplayGroup)
        .m(&PXR_NS::SdfSpec::GetInfo)
        .m(&PXR_NS::SdfSpec::SetInfo)
        .m(&PXR_NS::SdfSpec::SetInfoDictionaryValue)
        .m(&PXR_NS::SdfSpec::HasInfo)
        .m(&PXR_NS::SdfSpec::ClearInfo)
        .m(&PXR_NS::SdfSpec::GetTypeForInfo)
        .m(&PXR_NS::SdfSpec::GetFallbackForInfo)
        // need std::ostream for this
        // .m(&PXR_NS::SdfSpec::WriteToStream)
        .m(&PXR_NS::SdfSpec::IsInert)
        .m(&PXR_NS::SdfSpec::ListFields)
        .m((bool (PXR_NS::SdfSpec::*)(const PXR_NS::TfToken &) const)
            &PXR_NS::SdfSpec::HasField, "HasField_00")
        /** TODO: instantiate this template
        .m((bool (PXR_NS::SdfSpec::*)(const PXR_NS::TfToken &, T *) const)
            &PXR_NS::SdfSpec::HasField, "HasField_01")
        */
        .m(&PXR_NS::SdfSpec::GetField)
        /** TODO: instantiate this template
        .m(&PXR_NS::SdfSpec::GetFieldAs)
        */
        .m((bool (PXR_NS::SdfSpec::*)(const PXR_NS::TfToken &, const PXR_NS::VtValue &))
            &PXR_NS::SdfSpec::SetField, "SetField_00")
        /** TODO: instantiate this template
        .m((bool (PXR_NS::SdfSpec::*)(const PXR_NS::TfToken &, const T &))
            &PXR_NS::SdfSpec::SetField, "SetField_01")
        */
        .m(&PXR_NS::SdfSpec::ClearField)
        .m(&PXR_NS::SdfSpec::operator==, "op_eq")
        .m(&PXR_NS::SdfSpec::operator<, "op_lt")
    ;

    bbl::Class<PXR_NS::SdfSpecHandle>("SpecHandle")
        .smartptr_to<PXR_NS::SdfSpec>()
    ;

    bbl::Class<PXR_NS::SdfTimeCode>("TimeCode")
        .replace_with<TimeCode>()
        .ctor(bbl::Class<PXR_NS::SdfTimeCode>::Ctor<double>(), "from_time")
    ;

    bbl::Enum<PXR_NS::SdfPermission>("Permission");
    bbl::Class<PXR_NS::SdfRelocatesMap>("RelocatesMap");
    bbl::Enum<PXR_NS::SdfSpecifier>("Specifier");
    bbl::Enum<PXR_NS::SdfSpecType>("SpecType");
    bbl::Class<PXR_NS::SdfTimeSampleMap>("TimeSampleMap");
    bbl::Enum<PXR_NS::SdfVariability>("Variability");
    bbl::Class<PXR_NS::SdfValueBlock>("ValueBlock");

    bbl::Class<PXR_NS::SdfValueTypeName>("ValueTypeName")
        .ctor(bbl::Class<PXR_NS::SdfValueTypeName>::Ctor<>(), "new")
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

    bbl::Class<PXR_NS::SdfTupleDimensions>("TupleDimensions")
        .value_type()
        .f(&PXR_NS::SdfTupleDimensions::d)
        .f(&PXR_NS::SdfTupleDimensions::size)
    ;

    bbl::Class<PXR_NS::SdfVariableExpression>("VariableExpression")
        .ctor(bbl::Class<PXR_NS::SdfVariableExpression>::Ctor<>(), "default")
        .m(&PXR_NS::SdfVariableExpression::IsExpression)
        .m(&PXR_NS::SdfVariableExpression::IsValidVariableType)
        .m(&PXR_NS::SdfVariableExpression::operator bool, "op_bool")
        .m(&PXR_NS::SdfVariableExpression::GetString)
        .m(&PXR_NS::SdfVariableExpression::GetErrors)
        .m(&PXR_NS::SdfVariableExpression::Evaluate)
    ;

    bbl::Class<PXR_NS::SdfVariableExpression::Result>("VariableExpressionResult")
    ;

    bbl::Class<PXR_NS::SdfVariantSetSpec>("VariantSetSpec")
        .ctor(bbl::Class<PXR_NS::SdfVariantSetSpec>::Ctor<>(), "default")
        .m((PXR_NS::SdfVariantSetSpecHandle (*)(const PXR_NS::SdfPrimSpecHandle &, const std::string &))
            &PXR_NS::SdfVariantSetSpec::New, "New_00")
        .m((PXR_NS::SdfVariantSetSpecHandle (*)(const PXR_NS::SdfVariantSpecHandle &, const std::string &))
            &PXR_NS::SdfVariantSetSpec::New, "New_01")
        .m(&PXR_NS::SdfVariantSetSpec::GetName)
        .m(&PXR_NS::SdfVariantSetSpec::GetNameToken)
        .m(&PXR_NS::SdfVariantSetSpec::GetOwner)
        .m(&PXR_NS::SdfVariantSetSpec::GetVariants)
        .m(&PXR_NS::SdfVariantSetSpec::GetVariantList)
        .m(&PXR_NS::SdfVariantSetSpec::RemoveVariant)
        ;

    bbl::Class<PXR_NS::SdfVariantSetSpecHandle>("VariantSetSpecHandle");

    bbl::Class<PXR_NS::SdfVariantSpec>("VariantSpec")
        .ctor(bbl::Class<PXR_NS::SdfVariantSpec>::Ctor<>(), "default")
        .m(&PXR_NS::SdfVariantSpec::New)
        .m(&PXR_NS::SdfVariantSpec::GetName)
        .m(&PXR_NS::SdfVariantSpec::GetNameToken)
        .m(&PXR_NS::SdfVariantSpec::GetOwner)
        .m(&PXR_NS::SdfVariantSpec::GetPrimSpec)
        .m(&PXR_NS::SdfVariantSpec::GetVariantSets)
        .m(&PXR_NS::SdfVariantSpec::GetVariantNames)
    ;
    
    bbl::Class<PXR_NS::SdfVariantSpecHandle>("VariantSpecHandle");

    bbl::Class<PXR_NS::SdfVariantSpecHandleVector>("VariantSpecHandleVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfVariantSpecHandle)
    ;
    
    bbl::Class<PXR_NS::SdfVariantView>("VariantView");

}

#endif
