#if defined(__clang__)

#include "babble"
#include "babble-std"

#include <pxr/usd/ndr/declare.h>
#include <pxr/usd/ndr/discoveryPlugin.h>
#include <pxr/usd/ndr/filesystemDiscoveryHelpers.h>
#include <pxr/usd/ndr/node.h>
#include <pxr/usd/ndr/nodeDiscoveryResult.h>
#include <pxr/usd/ndr/parserPlugin.h>
#include <pxr/usd/ndr/property.h>
#include <pxr/usd/ndr/registry.h>
#include <pxr/usd/sdf/valueTypeName.h>

BBL_MODULE(ndr) {
    // clang-format off

    bbl::Class<PXR_NS::NdrVersion>()
        .ctor(bbl::Class<PXR_NS::NdrVersion>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::NdrVersion>::Ctor<int, int>("major", "minor"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::NdrVersion>::Ctor<const std::string &>("x"), "ctor_02")
        .m(&PXR_NS::NdrVersion::GetAsDefault)
        .m(&PXR_NS::NdrVersion::GetMajor)
        .m(&PXR_NS::NdrVersion::GetMinor)
        .m(&PXR_NS::NdrVersion::IsDefault)
        .m(&PXR_NS::NdrVersion::GetString)
        .m(&PXR_NS::NdrVersion::GetStringSuffix)
        .m(&PXR_NS::NdrVersion::GetHash)
        .m(&PXR_NS::NdrVersion::operator bool, "op_bool")
        .m(&PXR_NS::NdrVersion::operator!, "op_not")
    ;

    bbl::fn(&PXR_NS::NdrGetIdentifierString);

    bbl::Enum<PXR_NS::NdrVersionFilter>("VersionFilter");

    bbl::Class<PXR_NS::NdrDiscoveryPluginContext>("DiscoveryPluginContext")
        .m(&PXR_NS::NdrDiscoveryPluginContext::GetSourceType)
    ;

    bbl::Class<PXR_NS::NdrDiscoveryPlugin>("DiscoveryPlugin")
        .m(&PXR_NS::NdrDiscoveryPlugin::DiscoverNodes)
        .m(&PXR_NS::NdrDiscoveryPlugin::GetSearchURIs)
    ;

    bbl::Class<PXR_NS::NdrDiscoveryPluginRefPtr>("DiscoveryPluginRefPtr")
        .smartptr_to<PXR_NS::NdrDiscoveryPlugin>()
    ;

    bbl::Class<PXR_NS::NdrDiscoveryUri>("DiscoveryUri")
    ;

    bbl::Class<PXR_NS::NdrNode>("Node")
        /// XXX: rvalue ref
        // .ctor(bbl::Class<PXR_NS::NdrNode>::Ctor<const PXR_NS::NdrIdentifier &, const PXR_NS::NdrVersion &, const std::string &, const PXR_NS::TfToken &, const PXR_NS::TfToken &, const PXR_NS::TfToken &, const std::string &, const std::string &, PXR_NS::NdrPropertyUniquePtrVec &&, const PXR_NS::NdrTokenMap &, const std::string &>("identifier", "version", "name", "family", "context", "sourceType", "definitionURI", "implementationURI", "properties", "metadata", "sourceCode"), "ctor_00")
        .m(&PXR_NS::NdrNode::GetIdentifier)
        .m(&PXR_NS::NdrNode::GetVersion)
        .m(&PXR_NS::NdrNode::GetName)
        .m(&PXR_NS::NdrNode::GetFamily)
        .m(&PXR_NS::NdrNode::GetContext)
        .m(&PXR_NS::NdrNode::GetSourceType)
        .m(&PXR_NS::NdrNode::GetResolvedDefinitionURI)
        .m(&PXR_NS::NdrNode::GetResolvedImplementationURI)
        .m(&PXR_NS::NdrNode::GetSourceCode)
        .m(&PXR_NS::NdrNode::IsValid)
        .m(&PXR_NS::NdrNode::GetInfoString)
        .m(&PXR_NS::NdrNode::GetInputNames)
        .m(&PXR_NS::NdrNode::GetOutputNames)
        .m(&PXR_NS::NdrNode::GetInput)
        .m(&PXR_NS::NdrNode::GetOutput)
        .m(&PXR_NS::NdrNode::GetMetadata)
    ;

    bbl::Class<PXR_NS::NdrNodeUniquePtr>("NodeUniquePtr")
        .smartptr_to<PXR_NS::NdrNode>()
    ;

    bbl::Class<PXR_NS::NdrNodeConstPtrVec>("NodeConstPtrVec")
        BBL_STD_VECTOR_METHODS(PXR_NS::NdrNodeConstPtr)
    ;

    bbl::Class<PXR_NS::NdrNodeDiscoveryResult>("NodeDiscoveryResult")
        .ctor(bbl::Class<PXR_NS::NdrNodeDiscoveryResult>::Ctor<const PXR_NS::NdrIdentifier &, const PXR_NS::NdrVersion &, const std::string &, const PXR_NS::TfToken &, const PXR_NS::TfToken &, const PXR_NS::TfToken &, const std::string &, const std::string &, const std::string &, const PXR_NS::NdrTokenMap &, const std::string &, const PXR_NS::TfToken &>("identifier", "version", "name", "family", "discoveryType", "sourceType", "uri", "resolvedUri", "sourceCode", "metadata", "blindData", "subIdentifier"), "ctor_00")
    ;

    bbl::Class<std::vector<PXR_NS::NdrNodeDiscoveryResult>>("NodeDiscoveryResultVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::NdrNodeDiscoveryResult)
    ;

    bbl::Class<PXR_NS::NdrParserPlugin>("ParserPlugin")
        .m(&PXR_NS::NdrParserPlugin::Parse)
        .m(&PXR_NS::NdrParserPlugin::GetDiscoveryTypes)
        .m(&PXR_NS::NdrParserPlugin::GetSourceType)
        .m(&PXR_NS::NdrParserPlugin::GetInvalidNode)
    ;

    bbl::Class<PXR_NS::NdrProperty>("Property")
        .ctor(bbl::Class<PXR_NS::NdrProperty>::Ctor<const PXR_NS::TfToken &, const PXR_NS::TfToken &, const PXR_NS::VtValue &, bool, size_t, bool, const PXR_NS::NdrTokenMap &>("name", "type", "defaultValue", "isOutput", "arraySize", "isDynamicArray", "metadata"), "ctor_00")
        .m(&PXR_NS::NdrProperty::GetName)
        .m(&PXR_NS::NdrProperty::GetType)
        .m(&PXR_NS::NdrProperty::GetDefaultValue)
        .m(&PXR_NS::NdrProperty::IsOutput)
        .m(&PXR_NS::NdrProperty::IsArray)
        .m(&PXR_NS::NdrProperty::IsDynamicArray)
        .m(&PXR_NS::NdrProperty::GetArraySize)
        .m(&PXR_NS::NdrProperty::GetInfoString)
        .m(&PXR_NS::NdrProperty::GetMetadata)
        .m(&PXR_NS::NdrProperty::IsConnectable)
        .m(&PXR_NS::NdrProperty::CanConnectTo)
        .m(&PXR_NS::NdrProperty::GetTypeAsSdfType)
        .m(&PXR_NS::NdrProperty::GetDefaultValueAsSdfType)
    ;

    bbl::Class<PXR_NS::NdrPropertyUniquePtr>("PropertyUniquePtr")
        .smartptr_to<PXR_NS::NdrProperty>()
    ;

    bbl::Class<PXR_NS::NdrPropertyUniquePtrVec>("PropertyUniquePtrVec")
        BBL_STD_VECTOR_METHODS(PXR_NS::NdrPropertyUniquePtr)
    ;

    bbl::Class<PXR_NS::NdrSdfTypeIndicator>("SdfTypeIndicator")
    ;

    bbl::Class<PXR_NS::NdrRegistry>("Registry")
        .m((void (PXR_NS::NdrRegistry::*)(PXR_NS::NdrRegistry::DiscoveryPluginRefPtrVec))
            &PXR_NS::NdrRegistry::SetExtraDiscoveryPlugins, "SetExtraDiscoveryPlugins_00")
        .m((void (PXR_NS::NdrRegistry::*)(const std::vector<PXR_NS::TfType> &))
            &PXR_NS::NdrRegistry::SetExtraDiscoveryPlugins, "SetExtraDiscoveryPlugins_01")
        .m((void (PXR_NS::NdrRegistry::*)(PXR_NS::NdrNodeDiscoveryResult &&))
            &PXR_NS::NdrRegistry::AddDiscoveryResult, "AddDiscoveryResult_00")
        .m((void (PXR_NS::NdrRegistry::*)(const PXR_NS::NdrNodeDiscoveryResult &))
            &PXR_NS::NdrRegistry::AddDiscoveryResult, "AddDiscoveryResult_01")
        .m(&PXR_NS::NdrRegistry::SetExtraParserPlugins)
        .m(&PXR_NS::NdrRegistry::GetNodeFromAsset)
        .m(&PXR_NS::NdrRegistry::GetNodeFromSourceCode)
        .m(&PXR_NS::NdrRegistry::GetSearchURIs)
        .m(&PXR_NS::NdrRegistry::GetNodeIdentifiers)
        .m(&PXR_NS::NdrRegistry::GetNodeNames)
        .m(&PXR_NS::NdrRegistry::GetNodeByIdentifier)
        .m(&PXR_NS::NdrRegistry::GetNodeByIdentifierAndType)
        .m(&PXR_NS::NdrRegistry::GetNodeByName)
        .m(&PXR_NS::NdrRegistry::GetNodeByNameAndType)
        .m(&PXR_NS::NdrRegistry::GetNodesByIdentifier)
        .m(&PXR_NS::NdrRegistry::GetNodesByName)
        .m(&PXR_NS::NdrRegistry::GetNodesByFamily)
        .m(&PXR_NS::NdrRegistry::GetAllNodeSourceTypes)
    ;

    bbl::Class<PXR_NS::NdrRegistry::DiscoveryPluginRefPtrVec>("NdrRegistryDiscoveryPluginRefPtrVec")
        BBL_STD_VECTOR_METHODS(PXR_NS::NdrDiscoveryPluginRefPtr)
    ;

    bbl::Class<PXR_NS::NdrTokenMap>("TokenMap");

    bbl::Class<PXR_NS::NdrOptionVec>("OptionVec")
        BBL_STD_VECTOR_METHODS((std::pair<PXR_NS::TfToken, PXR_NS::TfToken>))
    ;

}


#endif
