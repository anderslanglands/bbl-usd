#if defined(__clang__)

#include "babble"
#include "babble-std"
#include "babble-usd"

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
#include <pxr/usd/sdf/site.h>
#include <pxr/usd/sdf/textFileFormat.h>
#include <pxr/usd/sdf/timeCode.h>
#include <pxr/usd/sdf/types.h>
#include <pxr/usd/sdf/valueTypeName.h>
#include <pxr/usd/sdf/variableExpression.h>
#include <pxr/usd/sdf/variantSetSpec.h>
#include <pxr/usd/sdf/variantSpec.h>

#define SDF_CHILDREN_VIEW(TY, NAME) \
    bbl::Class<TY>(#NAME) \
        .m(&bbl::detail::argument_type<void(TY)>::type::size) \
        .m(&bbl::detail::argument_type<void(TY)>::type::empty) \
        .m(&bbl::detail::argument_type<void(TY)>::type::values) \
        .m(&bbl::detail::argument_type<void(TY)>::type::count) \
        .m(&bbl::detail::argument_type<void(TY)>::type::keys) \
        .m((bool (bbl::detail::argument_type<void(TY)>::type::*)(bbl::detail::argument_type<void(TY)>::type::key_type const&) const) \
            &bbl::detail::argument_type<void(TY)>::type::has) \
        .m((bool (bbl::detail::argument_type<void(TY)>::type::*)(bbl::detail::argument_type<void(TY)>::type::value_type const&) const) \
            &bbl::detail::argument_type<void(TY)>::type::has, "has_value") \
        .m((bbl::detail::argument_type<void(TY)>::type::value_type (bbl::detail::argument_type<void(TY)>::type::*)(bbl::detail::argument_type<void(TY)>::type::key_type const&) const) \
            &bbl::detail::argument_type<void(TY)>::type::get) \
        .ignore(&bbl::detail::argument_type<void(TY)>::type::GetChildren) \
        .ignore(&bbl::detail::argument_type<void(TY)>::type::GetPredicate) \
        .ignore_all_unbound()

#define SDF_MAPEDIT_PROXY(TY, NAME)                                         \
    bbl::Class<TY>(#NAME)                                                   \
        .m((TY::iterator (TY::*)())                                         \
            &TY::begin)                                                     \
        .m((TY::const_iterator (TY::*)() const)                             \
            &TY::begin, "begin_const")                                      \
        .m((TY::iterator (TY::*)())                                         \
            &TY::end)                                                       \
        .m((TY::const_iterator (TY::*)() const)                             \
            &TY::end, "end_const")                                          \
        .m((TY::iterator (TY::*)(TY::key_type const&))                      \
            &TY::find)                                                      \
        .m((TY::const_iterator (TY::*)(TY::key_type const&) const)          \
            &TY::find, "find_const")                                        \
        .ignore_all_unbound()                                               \
    ;                                                                       \
                                                                            \
    bbl::Class<TY::iterator>(#NAME "Iterator")                              \
        .ignore_all_unbound()                                               \
    ;                                                                       \
                                                                            \
    bbl::fn([](TY::iterator& _this) -> TY::key_type {                       \
        return _this->first;                                                \
    }, #NAME "Iterator_first");                                             \
                                                                            \
    bbl::fn([](TY::iterator& _this) -> TY::mapped_type {                    \
        return _this->second;                                               \
    }, #NAME "Iterator_second");                                            \
                                                                            \
   bbl::fn([](TY::iterator& _this, TY::iterator& rhs) -> bool {             \
        return _this == rhs;                                                \
   }, #NAME "Iterator_op_eq");                                              \
                                                                            \
    bbl::Class<TY::const_iterator>(#NAME "ConstIterator")                   \
        .ignore_all_unbound()                                               \
    ;                                                                       \
                                                                            \
    bbl::fn([](TY::const_iterator const& _this) -> TY::key_type {           \
        return _this->first;                                                \
    }, #NAME "ConstIterator_first");                                        \
                                                                            \
    bbl::fn([](TY::const_iterator const& _this) -> TY::mapped_type {        \
        return _this->second;                                               \
    }, #NAME "ConstIterator_second");                                       \
   bbl::fn([](TY::const_iterator const& _this, TY::const_iterator const& rhs) -> bool { \
        return _this == rhs;                                                \
   }, #NAME "ConstIterator_op_eq");


#define SDF_LIST_PROXY(TY, NAME)                                            \
    bbl::Class<TY>(#NAME)                                                   \
        .m(&TY::size)                                                       \
        .ignore_all_unbound()                                               \
    ;                                                                       \
    bbl::fn([](TY& _this, size_t index) -> TY::value_type {                 \
        return _this[index];                                                \
    }, #NAME "_op_index"); 

#define SDF_LISTEDITOR_PROXY(TY, NAME) \
    bbl::Class<TY>(#NAME) \
        .m(&TY::IsExpired) \
        .m(&TY::IsExplicit) \
        .m(&TY::IsOrderedOnly) \
        .m(&TY::HasKeys) \
        .m((void (TY::*)(TY::value_vector_type*) const) \
            &TY::ApplyEditsToList \
        ) \
        .m(&TY::CopyItems) \
        .m(&TY::ClearEdits) \
        .m(&TY::ClearEditsAndMakeExplicit) \
        .m(&TY::ContainsItemEdit) \
        .m(&TY::RemoveItemEdits) \
        .m(&TY::ReplaceItemEdits) \
        .m(&TY::GetExplicitItems) \
        .m(&TY::GetAddedOrExplicitItems) \
        .m(&TY::GetAddedItems) \
        .m(&TY::GetPrependedItems) \
        .m(&TY::GetAppendedItems) \
        .m(&TY::GetDeletedItems) \
        .m(&TY::GetOrderedItems) \
        .m(&TY::GetAppliedItems) \
        .m(&TY::Add) \
        .m(&TY::Prepend) \
        .m(&TY::Append) \
        .m(&TY::Remove) \
        .m(&TY::Erase) \
        .m(&TY::operator bool) \
        .ignore_all_unbound() \
    ;

struct TimeCode {
    double time;
};

namespace bblext {

PXR_NS::SdfAssetPath AssetPath_from_path(char const* path) {
    return PXR_NS::SdfAssetPath(path);
}

PXR_NS::SdfAssetPath
AssetPath_from_path_and_resolved_path(char const* path,
                                      char const* resolved_path) {
    return PXR_NS::SdfAssetPath(path, resolved_path);
}

char const* AssetPath_GetAssetPath(PXR_NS::SdfAssetPath const& path) {
    return path.GetAssetPath().c_str();
}

char const* AssetPath_GetResolvedPath(PXR_NS::SdfAssetPath const& path) {
    return path.GetResolvedPath().c_str();
}

PXR_NS::SdfLayerRefPtr Layer_CreateAnonymous(char const* tag) {
    return PXR_NS::SdfLayer::CreateAnonymous(tag);
}

PXR_NS::SdfLayerHandle LayerRefPtr_as_handle(PXR_NS::SdfLayerRefPtr& ref) {
    return ref;
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
    char const* assetPath,
    PXR_NS::SdfPath const& primPath,
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
    char const* assetPath,
    PXR_NS::SdfPath const& primPath,
    PXR_NS::SdfLayerOffset const& layerOffset) {
    return new PXR_NS::SdfReference(assetPath, primPath, layerOffset);
}

PXR_NS::SdfReference*
Reference_from_asset_path_and_prim_path_and_layer_offset_and_custom_data(
    char const* assetPath,
    PXR_NS::SdfPath const& primPath,
    PXR_NS::SdfLayerOffset const& layerOffset,
    PXR_NS::VtDictionary const& customData) {
    return new PXR_NS::SdfReference(
        assetPath, primPath, layerOffset, customData);
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
    FileFormatBase(PXR_NS::TfToken const& formatId,
                   PXR_NS::TfToken const& versionString,
                   PXR_NS::TfToken const& target,
                   char const* extension)
        : PXR_NS::SdfFileFormat(formatId, versionString, target, extension) {}

    virtual ~FileFormatBase() {}

    virtual auto CanRead(std::string const& file) const -> bool override {
        return false;
    }

    virtual auto Read(PXR_NS::SdfLayer* layer,
                      std::string const& resolvedPath,
                      bool metadaOnly) const -> bool override {
        return false;
    }

    // Helper function for _ReadDetached
    auto _ReadAndCopyLayerDataToMemory(PXR_NS::SdfLayer* layer,
                                       char const* resolvedPath,
                                       bool metadataOnly,
                                       bool* didCopyData) const -> bool {
        return PXR_NS::SdfFileFormat::_ReadAndCopyLayerDataToMemory(
            layer, resolvedPath, metadataOnly, didCopyData);
    }

    virtual auto _InstantiateNewLayer(
        PXR_NS::SdfFileFormatConstPtr const& fileFormat,
        const std::string& identifier,
        const std::string& realPath,
        const PXR_NS::ArAssetInfo& assetInfo,
        const PXR_NS::SdfFileFormat::FileFormatArguments& args) const
        -> PXR_NS::SdfLayer* override {
        return PXR_NS::SdfFileFormat::_InstantiateNewLayer(
            fileFormat, identifier, realPath, assetInfo, args);
    }

    auto _InstantiateNewLayer_base(
        PXR_NS::SdfFileFormatConstPtr const& fileFormat,
        char const* identifier,
        char const* realPath,
        const PXR_NS::ArAssetInfo& assetInfo,
        const PXR_NS::SdfFileFormat::FileFormatArguments& args) const
        -> PXR_NS::SdfLayer* {
        return PXR_NS::SdfFileFormat::_InstantiateNewLayer(
            fileFormat, identifier, realPath, assetInfo, args);
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

    virtual auto _InitDetachedData(
        PXR_NS::SdfFileFormat::FileFormatArguments const& args) const
        -> PXR_NS::SdfAbstractDataRefPtr override {
        return PXR_NS::SdfFileFormat::InitDetachedData(args);
    }

    auto _InitDetachedData_base(
        PXR_NS::SdfFileFormat::FileFormatArguments const& args) const
        -> PXR_NS::SdfAbstractDataRefPtr {
        return PXR_NS::SdfFileFormat::_InitDetachedData(args);
    }

    virtual bool _ReadDetached(PXR_NS::SdfLayer* layer,
                               const std::string& resolvedPath,
                               bool metadataOnly) const override {
        return PXR_NS::SdfFileFormat::_ReadDetached(
            layer, resolvedPath, metadataOnly);
    }

    bool _ReadDetached_base(PXR_NS::SdfLayer* layer,
                            const std::string& resolvedPath,
                            bool metadataOnly) const {
        return PXR_NS::SdfFileFormat::_ReadDetached(
            layer, resolvedPath, metadataOnly);
    }

    // static protected member functions
    static void _SetLayerData(PXR_NS::SdfLayer* layer,
                              PXR_NS::SdfAbstractDataRefPtr& data) {
        PXR_NS::SdfFileFormat::_SetLayerData(layer, data);
    }

    static void _SetLayerData_with_hints(PXR_NS::SdfLayer* layer,
                                         PXR_NS::SdfAbstractDataRefPtr& data,
                                         PXR_NS::SdfLayerHints hints) {
        PXR_NS::SdfFileFormat::_SetLayerData(layer, data, hints);
    }

    static auto _GetLayerData(PXR_NS::SdfLayer const& layer)
        -> PXR_NS::SdfAbstractDataConstPtr {
        return PXR_NS::SdfFileFormat::_GetLayerData(layer);
    }
};

auto define_file_format(char const* name,
                        char const* formatId,
                        char const* versionString,
                        char const* target,
                        char const* extension,
                        void* fn_can_read,
                        void* fn_read) -> void {

    typedef bool (*CanReadFn)(char const* file);
    typedef bool (*ReadFn)(
        PXR_NS::SdfLayer* layer, char const* resolvedPath, bool metadataOnly);

    class FileFormatDerived : public PXR_NS::SdfFileFormat {
        CanReadFn _fn_can_read;
        ReadFn _fn_read;

    public:
        FileFormatDerived(char const* formatId,
                          char const* versionString,
                          char const* target,
                          char const* extension,
                          CanReadFn fn_can_read,
                          ReadFn fn_read)
            : PXR_NS::SdfFileFormat(PXR_NS::TfToken(formatId),
                                    PXR_NS::TfToken(versionString),
                                    PXR_NS::TfToken(target),
                                    extension),
              _fn_can_read(fn_can_read), _fn_read(fn_read) {}

        virtual auto CanRead(std::string const& file) const -> bool override {
            printf("CanRead\n");
            return _fn_can_read(file.c_str());
        }

        virtual auto Read(PXR_NS::SdfLayer* layer,
                          std::string const& resolvedPath,
                          bool metadataOnly) const -> bool override {
            printf("Read\n");
            return _fn_read(layer, resolvedPath.c_str(), metadataOnly);
        }
    };

    class FileFormatFactory : public PXR_NS::Sdf_FileFormatFactoryBase {
        std::string _formatId;
        std::string _versionString;
        std::string _target;
        std::string _extension;
        CanReadFn _fn_can_read;
        ReadFn _fn_read;

    public:
        FileFormatFactory(char const* formatId,
                          char const* versionString,
                          char const* target,
                          char const* extension,
                          CanReadFn fn_can_read,
                          ReadFn fn_read)
            : _formatId(formatId), _versionString(versionString),
              _target(target), _extension(extension), _fn_can_read(fn_can_read),
              _fn_read(fn_read) {}

        virtual auto New() const -> PXR_NS::SdfFileFormatRefPtr override {
            printf("NEW FILE FORMAT\n");
            printf("    formatId: \"%s\"\n", _formatId.c_str());
            printf("    versionString: \"%s\"\n", _versionString.c_str());
            printf("    target: \"%s\"\n", _target.c_str());
            printf("    extension: \"%s\"\n", _extension.c_str());
            return PXR_NS::SdfFileFormatRefPtr(
                new FileFormatDerived(_formatId.c_str(),
                                      _versionString.c_str(),
                                      _target.c_str(),
                                      _extension.c_str(),
                                      _fn_can_read,
                                      _fn_read));
        }
    };

    printf("Defining \"%s\"\n", name);
    printf("    formatId: \"%s\"\n", formatId);
    printf("    versionString: \"%s\"\n", versionString);
    printf("    target: \"%s\"\n", target);
    printf("    extension: \"%s\"\n", extension);

    PXR_NS::TfType::Declare(name).SetFactory(
        std::make_unique<FileFormatFactory>(formatId,
                                            versionString,
                                            target,
                                            extension,
                                            (CanReadFn)fn_can_read,
                                            (ReadFn)fn_read));
}

} // namespace bblext

BBL_MODULE(sdf) {

    // clang-format off

    bbl::fn(&bblext::define_file_format);

    bbl::Class<PXR_NS::SdfAbstractData>("AbstractData")
        .m(&PXR_NS::SdfAbstractData::CopyFrom)
        .m(&PXR_NS::SdfAbstractData::StreamsData)
        .m(&PXR_NS::SdfAbstractData::IsDetached)
        .m(&PXR_NS::SdfAbstractData::IsEmpty)
        .m(&PXR_NS::SdfAbstractData::Equals)
        .m(&PXR_NS::SdfAbstractData::CreateSpec)
        .m(&PXR_NS::SdfAbstractData::HasSpec)
        .m(&PXR_NS::SdfAbstractData::EraseSpec)
        .m(&PXR_NS::SdfAbstractData::MoveSpec)
        .m(&PXR_NS::SdfAbstractData::GetSpecType)
        .m((bool (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, PXR_NS::SdfAbstractDataValue *) const)
            &PXR_NS::SdfAbstractData::Has, "Has_00")
        .m((bool (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, PXR_NS::VtValue *) const)
            &PXR_NS::SdfAbstractData::Has, "Has_01")
        .m((bool (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, PXR_NS::SdfAbstractDataValue *, PXR_NS::SdfSpecType *) const)
            &PXR_NS::SdfAbstractData::HasSpecAndField, "HasSpecAndField_00")
        .m((bool (PXR_NS::SdfAbstractData::*)(const PXR_NS::SdfPath &, const PXR_NS::TfToken &, PXR_NS::VtValue *, PXR_NS::SdfSpecType *) const)
            &PXR_NS::SdfAbstractData::HasSpecAndField, "HasSpecAndField_01")
        .m(&PXR_NS::SdfAbstractData::Get)
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

        // missing type_info
        .ignore(&PXR_NS::SdfAbstractData::GetTypeid)
        // requires binding std::ostream
        .ignore(&PXR_NS::SdfAbstractData::WriteToStream)
        // missing SdfAbstractDataSpecVisitor
        .ignore(&PXR_NS::SdfAbstractData::VisitSpecs)
    ;

    bbl::Class<PXR_NS::SdfAbstractDataPtr>("AbstractDataPtr")
        .smartptr_to<PXR_NS::SdfAbstractData>()
        .m(&PXR_NS::SdfAbstractDataPtr::IsExpired)
        .m(&PXR_NS::SdfAbstractDataPtr::IsInvalid)
        .ignore_all_unbound()
    ;

    bbl::Class<PXR_NS::SdfAbstractDataPtrVector>("AbstractDataPtrVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfAbstractDataPtr)
    ;

    bbl::Class<PXR_NS::SdfAbstractDataConstPtr>("AbstractDataConstPtr")
        .smartptr_to<PXR_NS::SdfAbstractData const>()
        .m(&PXR_NS::SdfAbstractDataConstPtr::IsExpired)
        .m(&PXR_NS::SdfAbstractDataConstPtr::IsInvalid)
        .ignore_all_unbound()
    ;

    bbl::Class<PXR_NS::SdfAbstractDataConstPtrVector>("AbstractDataConstPtrVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfAbstractDataConstPtr)
    ;

    bbl::Class<PXR_NS::SdfAbstractDataRefPtr>("AbstractDataRefPtr")
        .smartptr_to<PXR_NS::SdfAbstractData>()
        .ignore_all_unbound()
    ;

    bbl::Class<PXR_NS::SdfAbstractDataRefPtrVector>("AbstractDataRefPtrVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfAbstractDataRefPtr)
    ;

    bbl::Class<PXR_NS::SdfAbstractDataConstRefPtr>("AbstractDataConstRefPtr")
        .smartptr_to<PXR_NS::SdfAbstractData const>()
        .ignore_all_unbound()
    ;

    bbl::Class<PXR_NS::SdfAbstractDataConstRefPtrVector>("AbstractDataConstRefPtrVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfAbstractDataConstRefPtr)
    ;

    bbl::Class<PXR_NS::SdfAbstractDataValue>("AbstractDataValue")
        .m((bool (PXR_NS::SdfAbstractDataValue::*)(const PXR_NS::VtValue &))
            &PXR_NS::SdfAbstractDataValue::StoreValue, "StoreValue")
        .m((bool (PXR_NS::SdfAbstractDataValue::*)(const PXR_NS::SdfValueBlock &))
            &PXR_NS::SdfAbstractDataValue::StoreValue, "StoreValue_block")

        .ignore((bool (PXR_NS::SdfAbstractDataValue::*)(PXR_NS::VtValue &&))
            &PXR_NS::SdfAbstractDataValue::StoreValue)
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
        .m(&PXR_NS::SdfAllowed::operator==)

        .ignore(&PXR_NS::SdfAllowed::operator!)
        .ignore(&PXR_NS::SdfAllowed::operator!=)
        .ignore(&PXR_NS::SdfAllowed::operator boost::optional<std::string> PXR_NS::SdfAllowed::*)
    ;

    bbl::Class<PXR_NS::SdfAssetPath>("AssetPath")
        .ctor(bbl::Class<PXR_NS::SdfAssetPath>::Ctor<>(), "new")
        .m(&PXR_NS::SdfAssetPath::operator==, "op_eq")
        .m(&PXR_NS::SdfAssetPath::operator!=, "op_neq")
        .m(&PXR_NS::SdfAssetPath::operator<, "op_lt")
        .m(&PXR_NS::SdfAssetPath::GetHash)

        .ignore(&PXR_NS::SdfAssetPath::GetAssetPath)
        .ignore(&PXR_NS::SdfAssetPath::GetResolvedPath)
        .ignore(&PXR_NS::SdfAssetPath::operator>)
        .ignore(&PXR_NS::SdfAssetPath::operator<=)
        .ignore(&PXR_NS::SdfAssetPath::operator>=)
    ;

    // we bind specific wrapper functions for these as there's no point
    // generating an intermediary string&
    bbl::fn(&bblext::AssetPath_from_path);
    bbl::fn(&bblext::AssetPath_from_path_and_resolved_path);
    bbl::fn(&bblext::AssetPath_GetAssetPath);
    bbl::fn(&bblext::AssetPath_GetResolvedPath);

    bbl::Class<PXR_NS::VtArray<PXR_NS::SdfAssetPath>>("AssetPathArray")
        VTARRAY_METHODS(PXR_NS::SdfAssetPath)
    ;

    bbl::Class<PXR_NS::SdfAttributeSpec>("AttributeSpec")
        .ctor(bbl::Class<PXR_NS::SdfAttributeSpec>::Ctor<>(), "default")
        .m(&PXR_NS::SdfAttributeSpec::New)
        .m(&PXR_NS::SdfAttributeSpec::HasConnectionPaths)
        .m(&PXR_NS::SdfAttributeSpec::ClearConnectionPaths)
        .m(&PXR_NS::SdfAttributeSpec::GetAllowedTokens)
        .m(&PXR_NS::SdfAttributeSpec::HasAllowedTokens)
        .m(&PXR_NS::SdfAttributeSpec::SetAllowedTokens)
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

        // missing SdfListEditorProxy<SdfPathKeyPolicy>
        .ignore(&PXR_NS::SdfAttributeSpec::GetConnectionPathList)
    ;

    bbl::Class<PXR_NS::SdfAttributeSpecHandle>("AttributeSpecHandle")
        .smartptr_to<PXR_NS::SdfAttributeSpec>()
        .ignore_all_unbound()
    ;

    bbl::Class<PXR_NS::SdfAttributeSpecHandleVector>("AttributeSpecHandleVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfAttributeSpecHandle)
    ;
    
    SDF_CHILDREN_VIEW(PXR_NS::SdfAttributeSpecView, AttributeSpecView);

    bbl::Class<PXR_NS::SdfChangeBlock>("ChangeBlock")
        .ctor(bbl::Class<PXR_NS::SdfChangeBlock>::Ctor<>(), "default")
        ;

    bbl::Class<PXR_NS::SdfChangeList>("ChangeList")
        .ignore_all_unbound()
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
        TF_SMALLVECTOR_METHODS(PXR_NS::SdfChangeList::EntryList)
    ;

    bbl::Enum<PXR_NS::SdfChangeList::SubLayerChangeType>("SdfChangeListSubLayerChangeType");

    BBL_STD_PAIR((std::pair<PXR_NS::SdfPath, PXR_NS::SdfChangeList::Entry>), PathChangeListEntryPair);

    bbl::Class<PXR_NS::SdfLayerChangeListVec>("LayerChangeListVec")
        BBL_STD_VECTOR_METHODS((std::pair<PXR_NS::SdfLayerHandle, PXR_NS::SdfChangeList>))
    ;

    BBL_STD_PAIR((std::pair<PXR_NS::SdfLayerHandle, PXR_NS::SdfChangeList>), LayerHandleChangeListPair);

    bbl::Class<PXR_NS::SdfCopySpecsValueEdit>()
        // editfunction missing a type
        // .ctor(bbl::Class<PXR_NS::SdfCopySpecsValueEdit>::Ctor<const PXR_NS::SdfCopySpecsValueEdit::EditFunction &>("edit"), "ctor_00")
        // Need to return a function here... not possible?
        // .m(&PXR_NS::SdfCopySpecsValueEdit::GetEditFunction)
    ;

    bbl::Class<PXR_NS::SdfCopySpecsValueEdit::EditFunction>("SdfCopySpecsValueEditEditFunction");

    bbl::Class<PXR_NS::SdfData>("Data")
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

    bbl::Class<PXR_NS::SdfDataRefPtr>("DataRefPtr")
        .smartptr_to<PXR_NS::SdfData>()

        .ignore_all_unbound()
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
        .ctor(bbl::Class<PXR_NS::SdfFileFormat::FileFormatArguments>::Ctor<>(), "default")
        BBL_STD_MAP_METHODS(PXR_NS::SdfFileFormat::FileFormatArguments)
    ;

    bbl::Class<PXR_NS::SdfLayer>("Layer")
        // Constructors
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
        .m((bool (PXR_NS::SdfLayer::*)(PXR_NS::SdfPath const&, PXR_NS::TfToken const&, PXR_NS::SdfAbstractDataValue*) const)
            &PXR_NS::SdfLayer::HasField, "HasField_abstract_data")
        .m((bool (PXR_NS::SdfLayer::*)(PXR_NS::SdfPath const&, PXR_NS::TfToken const&, PXR_NS::TfToken const&, PXR_NS::VtValue*) const)
            &PXR_NS::SdfLayer::HasFieldDictKey)
        .m((bool (PXR_NS::SdfLayer::*)(PXR_NS::SdfPath const&, PXR_NS::TfToken const&, PXR_NS::TfToken const&, PXR_NS::SdfAbstractDataValue*) const)
            &PXR_NS::SdfLayer::HasFieldDictKey, "HasFieldDictKey_abstract_data")
        .m(&PXR_NS::SdfLayer::GetField)
        .m(&PXR_NS::SdfLayer::GetFieldDictValueByKey)
        .m((void (PXR_NS::SdfLayer::*)(PXR_NS::SdfPath const&, PXR_NS::TfToken const&, PXR_NS::VtValue const&))
            &PXR_NS::SdfLayer::SetField)
        .m((void (PXR_NS::SdfLayer::*)(PXR_NS::SdfPath const&, PXR_NS::TfToken const&, PXR_NS::SdfAbstractDataConstValue const&))
            &PXR_NS::SdfLayer::SetField, "SetField_abstract_data")
        .m((void (PXR_NS::SdfLayer::*)(PXR_NS::SdfPath const&, PXR_NS::TfToken const&, PXR_NS::TfToken const&, PXR_NS::VtValue const&))
            &PXR_NS::SdfLayer::SetFieldDictValueByKey)
        .m((void (PXR_NS::SdfLayer::*)(PXR_NS::SdfPath const&, PXR_NS::TfToken const&, PXR_NS::TfToken const&, PXR_NS::SdfAbstractDataConstValue const&))
            &PXR_NS::SdfLayer::SetFieldDictValueByKey, "SetFieldDictValueByKey_abstract_data")
        .m(&PXR_NS::SdfLayer::EraseField)
        .m(&PXR_NS::SdfLayer::EraseFieldDictValueByKey)
        .m(&PXR_NS::SdfLayer::GetIdentifier)
        /// XXX: ignore due to not binding type info
        .ignore(&PXR_NS::SdfLayer::GetFieldTypeid)

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
        .m((bool (PXR_NS::SdfLayer::*)(PXR_NS::SdfPath const&, double, PXR_NS::SdfAbstractDataValue*) const)
            &PXR_NS::SdfLayer::QueryTimeSample, "QueryTimeSample_abstract_data")
        .m((void (PXR_NS::SdfLayer::*)(PXR_NS::SdfPath const&, double, PXR_NS::VtValue const&))
            &PXR_NS::SdfLayer::SetTimeSample)
        .m((void (PXR_NS::SdfLayer::*)(PXR_NS::SdfPath const&, double, PXR_NS::SdfAbstractDataConstValue const&))
            &PXR_NS::SdfLayer::SetTimeSample, "SetTimeSample_abstract_data")
        .m(&PXR_NS::SdfLayer::EraseTimeSample)

        // static
        .m(&PXR_NS::SdfLayer::DumpLayerInfo)

        // Primary API
        .m(&PXR_NS::SdfLayer::TransferContent)

        .m(&PXR_NS::SdfLayer::GetSchema)
        .m(&PXR_NS::SdfLayer::GetFileFormat)
        .m(&PXR_NS::SdfLayer::GetFileFormatArguments)
        .m(bbl::Wrap((PXR_NS::SdfLayerRefPtr (*)(std::string const&, PXR_NS::SdfLayer::FileFormatArguments const&))&PXR_NS::SdfLayer::CreateNew, [](char const* identifier, PXR_NS::SdfLayer::FileFormatArguments const& args) -> PXR_NS::SdfLayerRefPtr {
            return PXR_NS::SdfLayer::CreateNew(identifier, args);
        }))
        .m(bbl::Wrap((PXR_NS::SdfLayerRefPtr (*)(PXR_NS::SdfFileFormatConstPtr const&, std::string const&, PXR_NS::SdfLayer::FileFormatArguments const&))&PXR_NS::SdfLayer::CreateNew, [](PXR_NS::SdfFileFormatConstPtr const& fileFormat, char const* identifier, PXR_NS::SdfLayer::FileFormatArguments const& args) -> PXR_NS::SdfLayerRefPtr {
            return PXR_NS::SdfLayer::CreateNew(fileFormat, identifier, args);
        }), "CreateNew_with_format")
        .m(bbl::Wrap(&PXR_NS::SdfLayer::New, [](PXR_NS::SdfFileFormatConstPtr const& fileFormat, char const* identifier, PXR_NS::SdfLayer::FileFormatArguments const& args) -> PXR_NS::SdfLayerRefPtr {
            return PXR_NS::SdfLayer::New(fileFormat, identifier, args);
        }))
        .m(bbl::Wrap(&PXR_NS::SdfLayer::Find, [](char const* identifier, PXR_NS::SdfLayer::FileFormatArguments const& args) -> PXR_NS::SdfLayerHandle {
            return PXR_NS::SdfLayer::Find(identifier, args);
        }))
        .m(bbl::Wrap(&PXR_NS::SdfLayer::FindRelativeToLayer, [](PXR_NS::SdfLayerHandle const& anchor, char const* identifier, PXR_NS::SdfLayer::FileFormatArguments const& args) -> PXR_NS::SdfLayerHandle {
            return PXR_NS::SdfLayer::FindRelativeToLayer(anchor, identifier, args);
        }))
        .m(bbl::Wrap(&PXR_NS::SdfLayer::FindOrOpenRelativeToLayer, [](PXR_NS::SdfLayerHandle const& anchor, char const* identifier, PXR_NS::SdfLayer::FileFormatArguments const& args) -> PXR_NS::SdfLayerRefPtr {
            return PXR_NS::SdfLayer::FindOrOpenRelativeToLayer(anchor, identifier, args);
        }))
        .m(bbl::Wrap(&PXR_NS::SdfLayer::AddToMutedLayers, [](char const* mutedPath) -> void {
            return PXR_NS::SdfLayer::AddToMutedLayers(mutedPath);
        }))
        .m(bbl::Wrap(&PXR_NS::SdfLayer::OpenAsAnonymous, [](char const* layerPath, bool metadataOnly, char const* tag) -> PXR_NS::SdfLayerRefPtr {
            return PXR_NS::SdfLayer::OpenAsAnonymous(layerPath, metadataOnly, tag);
        }))
        .m(&PXR_NS::SdfLayer::GetMetadata)
        .m(&PXR_NS::SdfLayer::GetHints)
        .m(&PXR_NS::SdfLayer::GetLoadedLayers)
        .m(&PXR_NS::SdfLayer::IsEmpty)
        .m(&PXR_NS::SdfLayer::StreamsData)
        .m(&PXR_NS::SdfLayer::IsDetached)
        .m(bbl::Wrap(&PXR_NS::SdfLayer::RemoveFromMutedLayers, [](char const* mutedPath) -> void {
            return PXR_NS::SdfLayer::RemoveFromMutedLayers(mutedPath);
        }))
        .m(bbl::Wrap((PXR_NS::SdfLayerRefPtr (*)(std::string const&, PXR_NS::SdfLayer::FileFormatArguments const&))&PXR_NS::SdfLayer::CreateAnonymous, [](char const* tag, PXR_NS::SdfLayer::FileFormatArguments const& args) -> PXR_NS::SdfLayerRefPtr {
            return PXR_NS::SdfLayer::CreateAnonymous(tag, args);
        }), "CreateAnonymous_with_args")
        .m(bbl::Wrap((PXR_NS::SdfLayerRefPtr (*)(std::string const&, PXR_NS::SdfFileFormatConstPtr const&, PXR_NS::SdfLayer::FileFormatArguments const&))&PXR_NS::SdfLayer::CreateAnonymous, [](char const* tag, PXR_NS::SdfFileFormatConstPtr const& fileFormat, PXR_NS::SdfLayer::FileFormatArguments const& args) -> PXR_NS::SdfLayerRefPtr {
            return PXR_NS::SdfLayer::CreateAnonymous(tag, fileFormat, args);
        }), "CreateAnonymous_with_format")
        .m(&PXR_NS::SdfLayer::IsAnonymous)
        .m(bbl::Wrap(&PXR_NS::SdfLayer::IsAnonymousLayerIdentifier, [](char const* identifier) -> bool {
            return PXR_NS::SdfLayer::IsAnonymousLayerIdentifier(identifier);
        }))
        .m(bbl::Wrap(&PXR_NS::SdfLayer::GetDisplayNameFromIdentifier, [](char const* identifier) -> std::string {
            return PXR_NS::SdfLayer::GetDisplayNameFromIdentifier(identifier);
        }))
        .m(&PXR_NS::SdfLayer::Save)
        .m(bbl::Wrap(&PXR_NS::SdfLayer::Export, [](PXR_NS::SdfLayer const& _this, char const* filename, char const* comment, PXR_NS::SdfLayer::FileFormatArguments const& args) -> bool {
            return _this.Export(filename, comment, args);
        }))
        .m(&PXR_NS::SdfLayer::ExportToString)
        .m(bbl::Wrap(&PXR_NS::SdfLayer::WriteDataFile, [](PXR_NS::SdfLayer& _this, char const* identifier) -> bool {
            return _this.WriteDataFile(identifier);
        }))
        .m(&PXR_NS::SdfLayer::Clear)
        .m(&PXR_NS::SdfLayer::Reload)
        .m(&PXR_NS::SdfLayer::ReloadLayers)
        .m(bbl::Wrap(&PXR_NS::SdfLayer::Import, [](PXR_NS::SdfLayer& _this, char const* identifier) -> bool {
            return _this.Import(identifier);
        }))
        .m(&PXR_NS::SdfLayer::SetMuted)
        .m((bool (PXR_NS::SdfLayer::*)() const)
            &PXR_NS::SdfLayer::IsMuted
        )
        .m(bbl::Wrap((bool (*)(std::string const&))&PXR_NS::SdfLayer::IsMuted, [](char const* path) -> bool {
            return PXR_NS::SdfLayer::IsMuted(path);
        }), "IsMuted_at_path")
        .m(&PXR_NS::SdfLayer::GetMutedLayers)
        .m(&PXR_NS::SdfLayer::SplitIdentifier)
        .m(&PXR_NS::SdfLayer::CreateIdentifier)
        .m(&PXR_NS::SdfLayer::InsertRootPrim)
        .m(bbl::Wrap(&PXR_NS::SdfLayer::SetIdentifier, [](PXR_NS::SdfLayer& _this, char const* identifier) -> void {
            _this.SetIdentifier(identifier);
        }))
        .m(&PXR_NS::SdfLayer::UpdateAssetInfo)
        .m(&PXR_NS::SdfLayer::GetDisplayName)
        .m(&PXR_NS::SdfLayer::GetResolvedPath)
        .m(bbl::Wrap(&PXR_NS::SdfLayer::GetRealPath, [](PXR_NS::SdfLayer const& _this) -> char const* {
            return _this.GetRealPath().c_str();
        }))
        .m(&PXR_NS::SdfLayer::GetFileExtension)
        .m(bbl::Wrap(&PXR_NS::SdfLayer::GetVersion, [](PXR_NS::SdfLayer const& _this) -> char const* {
            return _this.GetVersion().c_str();
        }))
        .m(bbl::Wrap(&PXR_NS::SdfLayer::GetRepositoryPath, [](PXR_NS::SdfLayer const& _this) -> char const* {
            return _this.GetRepositoryPath().c_str();
        }))
        .m(bbl::Wrap(&PXR_NS::SdfLayer::GetAssetName, [](PXR_NS::SdfLayer const& _this) -> char const* {
            return _this.GetAssetName().c_str();
        }))
        .m(&PXR_NS::SdfLayer::GetAssetInfo)
        .m(bbl::Wrap(&PXR_NS::SdfLayer::ComputeAbsolutePath, [](PXR_NS::SdfLayer& _this, char const* identifier) -> std::string {
            return _this.ComputeAbsolutePath(identifier);
        }))
        .m(&PXR_NS::SdfLayer::GetDetachedLayerRules)
        .m(bbl::Wrap((bool (*)(std::string const&))&PXR_NS::SdfLayer::IsIncludedByDetachedLayerRules, [](char const* identifier) -> bool {
            return PXR_NS::SdfLayer::IsIncludedByDetachedLayerRules(identifier);
        }))
        .m(&PXR_NS::SdfLayer::SetDetachedLayerRules)
        .m(&PXR_NS::SdfLayer::RemoveInertSceneDescription)
        .m(&PXR_NS::SdfLayer::RemovePropertyIfHasOnlyRequiredFields)
        .m(&PXR_NS::SdfLayer::SetStateDelegate)
        .m(&PXR_NS::SdfLayer::GetStateDelegate)
        .m(&PXR_NS::SdfLayer::RemovePrimIfInert)
        .m(&PXR_NS::SdfLayer::ScheduleRemoveIfInert)
        .m(&PXR_NS::SdfLayer::RemoveRootPrim)
        .m(&PXR_NS::SdfLayer::Traverse)
        .m(&PXR_NS::SdfLayer::SetRootPrims)
        .m(&PXR_NS::SdfLayer::GetRootPrims)
        .m(&PXR_NS::SdfLayer::ApplyRootPrimOrder)
        .m(&PXR_NS::SdfLayer::RemoveFromRootPrimOrder)
        .m(&PXR_NS::SdfLayer::RemoveFromRootPrimOrderByIndex)
        .m(&PXR_NS::SdfLayer::InsertInRootPrimOrder)
        .m(&PXR_NS::SdfLayer::SetRootPrimOrder)
        .m(&PXR_NS::SdfLayer::GetRootPrimOrder)
    ;

    bbl::fn(&bblext::Layer_CreateAnonymous);

    bbl::Class<PXR_NS::SdfLayer::TraversalFunction>("SdfLayerTraversalFunction")
    ;

    bbl::Class<PXR_NS::SdfLayer::DetachedLayerRules>("SdfLayerDetachedLayerRules")
        .m(&PXR_NS::SdfLayer::DetachedLayerRules::IncludeAll)
        .m(&PXR_NS::SdfLayer::DetachedLayerRules::Include)
        .m(&PXR_NS::SdfLayer::DetachedLayerRules::Exclude)
        .m(&PXR_NS::SdfLayer::DetachedLayerRules::IncludedAll)
        .m(&PXR_NS::SdfLayer::DetachedLayerRules::GetIncluded)
        .m(&PXR_NS::SdfLayer::DetachedLayerRules::GetExcluded)
        .m(bbl::Wrap(&PXR_NS::SdfLayer::DetachedLayerRules::IsIncluded, [](PXR_NS::SdfLayer::DetachedLayerRules const& _this, char const* identifier) -> bool {
            return _this.IsIncluded(identifier);
        }))
    ;

    bbl::Class<PXR_NS::SdfLayerHandle>("LayerHandle")
        .smartptr_to<PXR_NS::SdfLayer>()

        .ignore_all_unbound()
    ;

    bbl::Class<PXR_NS::SdfLayerRefPtr>("LayerRefPtr")
        .smartptr_to<PXR_NS::SdfLayer>()

        .ignore_all_unbound()
    ;

    bbl::fn(&bblext::LayerRefPtr_as_handle);

    bbl::Class<PXR_NS::SdfLayerHandleVector>("LayerHandleVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfLayerHandle)
    ;

    bbl::Class<PXR_NS::SdfLayerRefPtrVector>("LayerRefPtrVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfLayerRefPtr)
    ;

    BBL_STD_SET(PXR_NS::SdfLayerHandleSet, LayerHandleSet);

    bbl::Class<PXR_NS::SdfLayerHints>("LayerHints")
        .value_type()
        .f(&PXR_NS::SdfLayerHints::mightHaveRelocates)
    ;

    bbl::Class<PXR_NS::SdfLayerOffset>("LayerOffset")
        .ctor(bbl::Class<PXR_NS::SdfLayerOffset>::Ctor<double, double>("offset", "scale"), "ctor")
        .ctor(bbl::Class<PXR_NS::SdfLayerOffset>::Ctor<>(), "default")
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
            &PXR_NS::SdfLayerOffset::operator*, "compose_with")
        .m((double (PXR_NS::SdfLayerOffset::*)(double) const)
            &PXR_NS::SdfLayerOffset::operator*, "apply_to_double")
        .m((PXR_NS::SdfTimeCode (PXR_NS::SdfLayerOffset::*)(const PXR_NS::SdfTimeCode &) const)
            &PXR_NS::SdfLayerOffset::operator*, "apply_to_time_code")

        .ignore(&PXR_NS::SdfLayerOffset::operator<)
#if PXR_VERSION >= 2311
        .ignore(&PXR_NS::SdfLayerOffset::operator>=)
        .ignore(&PXR_NS::SdfLayerOffset::operator<=)
        .ignore(&PXR_NS::SdfLayerOffset::operator!=)
#endif
    ;

    bbl::Class<PXR_NS::SdfLayerOffsetVector>("LayerOffsetVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfLayerOffset)
    ;

    bbl::Class<PXR_NS::SdfLayerStateDelegateBase>("LayerStateDelegateBase")
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

    bbl::Class<PXR_NS::SdfLayerStateDelegateBaseRefPtr>("LayerStateDelegateBaseRefPtr")
        .smartptr_to<PXR_NS::SdfLayerStateDelegateBase>()

        .ignore_all_unbound()
    ;

    bbl::Class<PXR_NS::SdfLayerStateDelegateBasePtr>("LayerStateDelegateBasePtr")
        .smartptr_to<PXR_NS::SdfLayerStateDelegateBase>()

        .ignore_all_unbound()
    ;

    bbl::Class<PXR_NS::SdfLayerTree>("LayerTree")
        .m(&PXR_NS::SdfLayerTree::New)
        .m(&PXR_NS::SdfLayerTree::GetLayer)
        .m(&PXR_NS::SdfLayerTree::GetOffset)
        .m(&PXR_NS::SdfLayerTree::GetChildTrees)
    ;

    bbl::Class<PXR_NS::SdfLayerTreeHandle>("LayerTreeHandle")
        .smartptr_to<PXR_NS::SdfLayerTree>()

        .ignore_all_unbound()
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
        .m(&StringListOp::SetExplicitItems)
        .m(&StringListOp::SetAddedItems)
        .m(&StringListOp::SetPrependedItems)
        .m(&StringListOp::SetAppendedItems)
        .m(&StringListOp::SetDeletedItems)
        .m(&StringListOp::SetOrderedItems)
        .m(&StringListOp::SetItems)
        .m(&StringListOp::Clear)
        .m(&StringListOp::ClearAndMakeExplicit)
        .m(&StringListOp::ReplaceOperations)
        .m(&StringListOp::ComposeOperations)
        .m(&StringListOp::CreateExplicit)
        .m(&StringListOp::Create)
        .m(&StringListOp::Swap)
        .m(&StringListOp::operator==)
        .m(&StringListOp::HasItem)

        .ignore((void (StringListOp::*)(StringListOp::ItemVector *, const StringListOp::ApplyCallback &) const)
            &StringListOp::ApplyOperations)
        .ignore((boost::optional<PXR_NS::SdfListOp<std::string>> (PXR_NS::SdfListOp<std::string>::*)(PXR_NS::SdfListOp<std::string> const&) const)
            &PXR_NS::SdfListOp<std::string>::ApplyOperations)
        .ignore(&StringListOp::ModifyOperations)
        .ignore(&StringListOp::operator!=)
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
        .m(&PXR_NS::SdfNamespaceEdit::operator==)

        .ignore(&PXR_NS::SdfNamespaceEdit::operator!=)
    ;
    bbl::fn(&bblext::NamespaceEdit_get_current_path);
    bbl::fn(&bblext::NamespaceEdit_get_new_path);
    bbl::fn(&bblext::NamespaceEdit_get_index);

    bbl::Class<std::vector<PXR_NS::SdfNamespaceEdit>>("NamespaceEditVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfNamespaceEdit)
    ;

    
    bbl::Class<PXR_NS::SdfNamespaceEditDetail>("NamespaceEditDetail")
        .ctor(bbl::Class<PXR_NS::SdfNamespaceEditDetail>::Ctor<>(), "default")
        .m(&PXR_NS::SdfNamespaceEditDetail::operator==)

        .ignore(&PXR_NS::SdfNamespaceEditDetail::operator!=)
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

    // bbl::Class<PXR_NS::SdfBatchNamespaceEdit::HasObjectAtPath>("BatchNamespaceEditHasObjectAtPath");

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

    BBL_STD_ITERATOR(PXR_NS::SdfNotice::BaseLayersDidChange::const_iterator, NoticeBaseLayersDidChangeConstIterator);

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
        .m(&PXR_NS::SdfPath::RemoveCommonSuffix)
        .m(&PXR_NS::SdfPath::GetVariantSelection)
        .m(&PXR_NS::SdfPath::GetHash)
        .m(&PXR_NS::SdfPath::GetToken)
        .m(&PXR_NS::SdfPath::operator==)
        .m(&PXR_NS::SdfPath::operator<)
        .m(bbl::Wrap(&PXR_NS::SdfPath::StripPrefixNamespace, [](char const* name, char const* matchNamespace) -> std::pair<std::string, bool> {
            return PXR_NS::SdfPath::StripPrefixNamespace(name, matchNamespace);
        }))

        .ignore((std::string (*)(std::string const&, std::string const&))
            &PXR_NS::SdfPath::JoinIdentifier)
        .ignore((std::string (*)(PXR_NS::TfTokenVector const&))
            &PXR_NS::SdfPath::JoinIdentifier)
        .ignore((std::string (*)(std::vector<std::string> const&))
            &PXR_NS::SdfPath::JoinIdentifier)
        .m(&PXR_NS::SdfPath::operator<=)
        .m(&PXR_NS::SdfPath::operator>=)
        .m(&PXR_NS::SdfPath::operator>)
        .m(&PXR_NS::SdfPath::operator!=)
    ;

    BBL_STD_SET(PXR_NS::SdfPathSet, PathSet);

    bbl::Class<PXR_NS::SdfPathVector>("PathVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfPath)
    ;

    BBL_STD_PAIR((std::pair<PXR_NS::SdfPath, PXR_NS::SdfPath>), PathPathPair);

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
        .ignore((PXR_NS::SdfPathExpression (*)(PXR_NS::SdfPathExpression::PathPattern &&))
            &PXR_NS::SdfPathExpression::MakeAtom)
        // .m(&PXR_NS::SdfPathExpression::Walk)
        .m((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(const PXR_NS::SdfPath &, const PXR_NS::SdfPath &) const&)
            &PXR_NS::SdfPathExpression::ReplacePrefix)
        // .ignore((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(const PXR_NS::SdfPath &, const PXR_NS::SdfPath &)&&)
        //     &PXR_NS::SdfPathExpression::ReplacePrefix)
        // .m(&PXR_NS::SdfPathExpression::IsAbsolute)
        .m((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(const PXR_NS::SdfPath &) const &)
            &PXR_NS::SdfPathExpression::MakeAbsolute)
        // .ignore((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(const PXR_NS::SdfPath &))
        //     &PXR_NS::SdfPathExpression::MakeAbsolute, "MakeAbsolute_01")
        // .m(&PXR_NS::SdfPathExpression::ContainsExpressionReferences)
        // .ignore((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(PXR_NS::TfFunctionRef<PXR_NS::SdfPathExpression (const PXR_NS::SdfPathExpression::ExpressionReference &)>) const)
        //     &PXR_NS::SdfPathExpression::ResolveReferences)
        // .ignore((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(PXR_NS::TfFunctionRef<PXR_NS::SdfPathExpression (const PXR_NS::SdfPathExpression::ExpressionReference &)>))
        //     &PXR_NS::SdfPathExpression::ResolveReferences)
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
        .m(&PXR_NS::SdfPathExpression::ComposeOver)
        .m(&PXR_NS::SdfPathExpression::IsAbsolute)
        .m(&PXR_NS::SdfPathExpression::ContainsExpressionReferences)
#if PXR_VERSION >= 2311
        .m(&PXR_NS::SdfPathExpression::Everything)
        .m(&PXR_NS::SdfPathExpression::EveryDescendant)
        .m(&PXR_NS::SdfPathExpression::Nothing)
        .m(&PXR_NS::SdfPathExpression::WeakerRef)
        .m(&PXR_NS::SdfPathExpression::ContainsWeakerExpressionReference)
        .m(&PXR_NS::SdfPathExpression::GetText)
#endif
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
        .m((const PXR_NS::SdfPath & (PXR_NS::SdfPathExpression::PathPattern::*)() const&)
            &PXR_NS::SdfPathExpression::PathPattern::GetPrefix)
        // .ignore((PXR_NS::SdfPath (PXR_NS::SdfPathExpression::PathPattern::*)())
        //     &PXR_NS::SdfPathExpression::PathPattern::GetPrefix, "GetPrefix_01")
        .m((void (PXR_NS::SdfPathExpression::PathPattern::*)(PXR_NS::SdfPath &&))
            &PXR_NS::SdfPathExpression::PathPattern::SetPrefix, "SetPrefix_00")
        .m((void (PXR_NS::SdfPathExpression::PathPattern::*)(const PXR_NS::SdfPath &))
            &PXR_NS::SdfPathExpression::PathPattern::SetPrefix, "SetPrefix_01")
#if PXR_VERSION <= 2308
        .m(&PXR_NS::SdfPathExpression::PathPattern::GetDebugString)
#endif
        .m((const std::vector<PXR_NS::SdfPathExpression::PathPattern::Component> & (PXR_NS::SdfPathExpression::PathPattern::*)() const &)
            &PXR_NS::SdfPathExpression::PathPattern::GetComponents)
        // .ignore((std::vector<PXR_NS::SdfPathExpression::PathPattern::Component> (PXR_NS::SdfPathExpression::PathPattern::*)())
        //     &PXR_NS::SdfPathExpression::PathPattern::GetComponents, "GetComponents_01")
        .m((const std::vector<PXR_NS::SdfPredicateExpression> & (PXR_NS::SdfPathExpression::PathPattern::*)() const &)
            &PXR_NS::SdfPathExpression::PathPattern::GetPredicateExprs)
        // .ignore((std::vector<PXR_NS::SdfPredicateExpression> (PXR_NS::SdfPathExpression::PathPattern::*)())
        //     &PXR_NS::SdfPathExpression::PathPattern::GetPredicateExprs, "GetPredicateExprs_01")
        .m(&PXR_NS::SdfPathExpression::PathPattern::IsProperty)
        .m(&PXR_NS::SdfPathExpression::PathPattern::operator bool, "op_bool")
#if PXR_VERSION >= 2311
        .m(&PXR_NS::SdfPathExpression::PathPattern::GetText)
#endif
    ;

    bbl::Class<std::vector<PXR_NS::SdfPathExpression::PathPattern>>("PathExpressionPathPatternVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfPathExpression::PathPattern)
    ;

    bbl::Class<PXR_NS::SdfPathExpression::PathPattern::Component>()
        .ctor(bbl::Class<PXR_NS::SdfPathExpression::PathPattern::Component>::Ctor<>(), "default")
        .m(&PXR_NS::SdfPathExpression::PathPattern::Component::IsStretch)
    ;

    bbl::Class<std::vector<PXR_NS::SdfPathExpression::PathPattern::Component>>("PathExpressionPathPatternComponentVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfPathExpression::PathPattern::Component)
    ;

    bbl::Class<PXR_NS::SdfPathExpression::ExpressionReference>("PathExpressionExpressionReference")
        .ctor(bbl::Class<PXR_NS::SdfPathExpression::ExpressionReference>::Ctor<>(), "default")
    ;

    bbl::Class<std::vector<PXR_NS::SdfPathExpression::ExpressionReference>>("PathExpressionExpressionReferenceVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfPathExpression::ExpressionReference)
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

#if PXR_VERSION >= 2311
        .ignore(&PXR_NS::SdfPayload::operator>=)
        .ignore(&PXR_NS::SdfPayload::operator<=)
        .ignore(&PXR_NS::SdfPayload::operator>)
        .ignore(&PXR_NS::SdfPayload::operator!=)
#endif
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
        .ignore(&PXR_NS::SdfPredicateExpression::MakeNot)
        .ignore(&PXR_NS::SdfPredicateExpression::MakeOp)
        .ignore(&PXR_NS::SdfPredicateExpression::MakeCall)
        .ignore(&PXR_NS::SdfPredicateExpression::Walk)
        .ignore(&PXR_NS::SdfPredicateExpression::WalkWithOpStack)
        .m(&PXR_NS::SdfPredicateExpression::GetText)
        .m(&PXR_NS::SdfPredicateExpression::IsEmpty)
        .m(&PXR_NS::SdfPredicateExpression::operator bool, "op_bool")
        .m((const std::string & (PXR_NS::SdfPredicateExpression::*)() const &)
            &PXR_NS::SdfPredicateExpression::GetParseError)
        // .ignore((std::string (PXR_NS::SdfPredicateExpression::*)() const &&)
        //     &PXR_NS::SdfPredicateExpression::GetParseError)
    ;

    bbl::Class<std::vector<PXR_NS::SdfPredicateExpression>>("PredicateExpressionVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfPredicateExpression)
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

        .m(&PXR_NS::SdfPrimSpec::SetSymmetryArgument)
        .m(&PXR_NS::SdfPrimSpec::GetSymmetryArguments)
        .m(&PXR_NS::SdfPrimSpec::GetVariantSets)
        .m(&PXR_NS::SdfPrimSpec::SetVariantSelection)

    ;

    bbl::Class<PXR_NS::SdfPrimSpecHandle>("PrimSpecHandle")
        .smartptr_to<PXR_NS::SdfPrimSpec>()
        .ignore_all_unbound()
    ;

    bbl::Class<PXR_NS::SdfPrimSpecHandleVector>("PrimSpecHandleVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfPrimSpecHandle)
    ;

    BBL_STD_PAIR((std::pair<PXR_NS::SdfPrimSpecHandle, PXR_NS::SdfLayerOffset>), PrimSpecHandleOffsetPair);

    bbl::Class<std::vector<std::pair<PXR_NS::SdfPrimSpecHandle, PXR_NS::SdfLayerOffset>>>("PrimSpecHandleOffsetPairVector")
        BBL_STD_VECTOR_METHODS((std::pair<PXR_NS::SdfPrimSpecHandle, PXR_NS::SdfLayerOffset>))
    ;

    SDF_CHILDREN_VIEW(PXR_NS::SdfPrimSpecView, PrimSpecView);

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
        .ignore_all_unbound()
    ;

    bbl::Class<PXR_NS::SdfPropertySpecHandleVector>("PropertySpecHandleVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfPropertySpecHandle)
    ;

    BBL_STD_PAIR((std::pair<PXR_NS::SdfPropertySpecHandle, PXR_NS::SdfLayerOffset>), PropertySpecHandleOffsetPair);

    bbl::Class<std::vector<std::pair<PXR_NS::SdfPropertySpecHandle, PXR_NS::SdfLayerOffset>>>("PropertySpecHandleOffsetPairVector")
        BBL_STD_VECTOR_METHODS((std::pair<PXR_NS::SdfPropertySpecHandle, PXR_NS::SdfLayerOffset>))
    ;

    SDF_CHILDREN_VIEW(PXR_NS::SdfPropertySpecView, PropertySpecView);

    SDF_MAPEDIT_PROXY(PXR_NS::SdfDictionaryProxy, DictionaryProxy);
    
    SDF_LIST_PROXY(PXR_NS::SdfNameOrderProxy, NameOrderProxy);

    SDF_LIST_PROXY(PXR_NS::SdfSubLayerProxy, SubLayerProxy);

    SDF_LISTEDITOR_PROXY(PXR_NS::SdfNameEditorProxy, NameEditorProxy);

    SDF_LIST_PROXY(PXR_NS::SdfListProxy<PXR_NS::SdfNameKeyPolicy>, NameKeyPolicyListProxy);

    SDF_LIST_PROXY(PXR_NS::SdfListProxy<PXR_NS::SdfPathKeyPolicy>, PathKeyPolicyListProxy);

    SDF_LIST_PROXY(PXR_NS::SdfListProxy<PXR_NS::SdfPayloadTypePolicy>, PayloadTypePolicyListProxy);

    SDF_LIST_PROXY(PXR_NS::SdfListProxy<PXR_NS::SdfReferenceTypePolicy>, ReferenceTypePolicyListProxy);

    bbl::Class<PXR_NS::SdfNameKeyPolicy>("NameKeyPolicy")
        .ignore_all_unbound()
    ;

    bbl::Class<PXR_NS::SdfNameTokenKeyPolicy>("NameTokenKeyPolicy")
        .ignore_all_unbound()
    ;

    bbl::Class<PXR_NS::SdfPathKeyPolicy>("PathKeyPolicy")
        .m((PXR_NS::SdfPathKeyPolicy::value_type (PXR_NS::SdfPathKeyPolicy::*)(PXR_NS::SdfPathKeyPolicy::value_type const&) const)
            &PXR_NS::SdfPathKeyPolicy::Canonicalize
        )
        .m((std::vector<PXR_NS::SdfPathKeyPolicy::value_type> (PXR_NS::SdfPathKeyPolicy::*)(std::vector<PXR_NS::SdfPathKeyPolicy::value_type> const&) const)
            &PXR_NS::SdfPathKeyPolicy::Canonicalize, "Canonicalize_vector"
        )
        .ignore_all_unbound()
    ;

    bbl::Class<PXR_NS::SdfPayloadTypePolicy>("PayloadTypePolicy")
        .ignore_all_unbound()
    ;

    bbl::Class<PXR_NS::SdfReferenceTypePolicy>("ReferenceTypePolicy")
        .ignore_all_unbound()
    ;

    bbl::Class<PXR_NS::SdfSubLayerTypePolicy>("SubLayerTypePolicy")
        .ignore_all_unbound()
    ;


    SDF_LISTEDITOR_PROXY(PXR_NS::SdfPathEditorProxy, PathEditorProxy);

    SDF_LISTEDITOR_PROXY(PXR_NS::SdfPayloadEditorProxy, PayloadEditorProxy);

    SDF_LISTEDITOR_PROXY(PXR_NS::SdfReferenceEditorProxy, ReferenceEditorProxy);

    SDF_MAPEDIT_PROXY(PXR_NS::SdfVariantSelectionProxy, VariantSelectionProxy);

    SDF_MAPEDIT_PROXY(PXR_NS::SdfRelocatesMapProxy, RelocatesMapProxy);

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

    SDF_CHILDREN_VIEW(PXR_NS::SdfRelationshipSpecView, RelationshipSpecView);

    BBL_STD_PAIR((std::pair<PXR_NS::SdfRelationshipSpecHandle, PXR_NS::SdfLayerOffset>), RelationshipSpecHandleOffsetPair);

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
        .ignore_all_unbound()
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

    bbl::Class<PXR_NS::SdfSite>("Site")
        .ctor(bbl::Class<PXR_NS::SdfSite>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::SdfSite>::Ctor<PXR_NS::SdfLayerHandle const&, PXR_NS::SdfPath const&>("layer", "path"), "ctor")
        .m(&PXR_NS::SdfSite::operator==)
        .m(&PXR_NS::SdfSite::operator bool)

        .ignore(&PXR_NS::SdfSite::operator<)
#if PXR_VERSION >= 2311
        .ignore(&PXR_NS::SdfSite::operator!=)
        .ignore(&PXR_NS::SdfSite::operator<=)
        .ignore(&PXR_NS::SdfSite::operator>)
        .ignore(&PXR_NS::SdfSite::operator>=)
#endif
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

        .ignore_all_unbound()
    ;

    bbl::Class<PXR_NS::SdfTimeCode>("TimeCode")
        .replace_with<TimeCode>()
        .ctor(bbl::Class<PXR_NS::SdfTimeCode>::Ctor<double>(), "from_time")

        .ignore_all_unbound()
    ;

    bbl::Enum<PXR_NS::SdfPermission>("Permission");

    BBL_STD_MAP(PXR_NS::SdfRelocatesMap, RelocatesMap);

    bbl::Enum<PXR_NS::SdfSpecifier>("Specifier");
    bbl::Enum<PXR_NS::SdfSpecType>("SpecType");


    BBL_STD_MAP(PXR_NS::SdfTimeSampleMap, TimeSampleMap);

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
        .m(&PXR_NS::SdfValueTypeName::GetHash)
        .m(bbl::Wrap(&PXR_NS::SdfValueTypeName::GetCPPTypeName, [](PXR_NS::SdfValueTypeName const& _this) -> char const* {
            return _this.GetCPPTypeName().c_str();
        }))
        .m((bool (PXR_NS::SdfValueTypeName::*)(PXR_NS::SdfValueTypeName const&) const)
            &PXR_NS::SdfValueTypeName::operator==
        )
        .m((bool (PXR_NS::SdfValueTypeName::*)(PXR_NS::TfToken const&) const)
            &PXR_NS::SdfValueTypeName::operator==, "op_eq_token"
        )
        .m(bbl::Wrap((bool (PXR_NS::SdfValueTypeName::*)(std::string const&) const)
            &PXR_NS::SdfValueTypeName::operator==, [](PXR_NS::SdfValueTypeName const& _this, char const* rhs) -> bool {
                return _this == rhs;
            }), "op_eq_c_str"
        )
        .m(&PXR_NS::SdfValueTypeName::operator bool)
        .ignore((bool (PXR_NS::SdfValueTypeName::*)(PXR_NS::SdfValueTypeName const&) const)
            &PXR_NS::SdfValueTypeName::operator!=
        )
        .ignore((bool (PXR_NS::SdfValueTypeName::*)(std::string const&) const)
            &PXR_NS::SdfValueTypeName::operator!=
        )
        .ignore((bool (PXR_NS::SdfValueTypeName::*)(PXR_NS::TfToken const&) const)
            &PXR_NS::SdfValueTypeName::operator!=
        )
    ;

    bbl::Class<std::vector<PXR_NS::SdfValueTypeName>>("ValueTypeNameVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfValueTypeName);

    bbl::Class<PXR_NS::SdfTupleDimensions>("TupleDimensions")
        .value_type()
        .f(&PXR_NS::SdfTupleDimensions::d)
        .f(&PXR_NS::SdfTupleDimensions::size)
        .m(&PXR_NS::SdfTupleDimensions::operator==)
        .ignore(&PXR_NS::SdfTupleDimensions::operator!=)
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

    bbl::Class<PXR_NS::SdfVariantSetSpecHandle>("VariantSetSpecHandle")
        .smartptr_to<PXR_NS::SdfVariantSetSpec>()
        .ignore_all_unbound()
    ;

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
    
    bbl::Class<PXR_NS::SdfVariantSpecHandle>("VariantSpecHandle")
        .smartptr_to<PXR_NS::SdfVariantSpec>()
        .ignore_all_unbound()
    ;

    bbl::Class<PXR_NS::SdfVariantSpecHandleVector>("VariantSpecHandleVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfVariantSpecHandle)
    ;
    
    SDF_CHILDREN_VIEW(PXR_NS::SdfVariantView, VariantView);
}

#endif
