#if defined(__clang__)

#include "babble"
#include "babble-std"

#include <pxr/usd/sdr/registry.h>
#include <pxr/usd/sdr/shaderNode.h>
#include <pxr/usd/sdr/shaderProperty.h>

BBL_MODULE(sdr) {

    // clang-format off
    bbl::Class<PXR_NS::SdrRegistry>("Registry")
        .m(&PXR_NS::SdrRegistry::GetInstance)
        .m(&PXR_NS::SdrRegistry::GetShaderNodeByIdentifier)
        .m(&PXR_NS::SdrRegistry::GetShaderNodeByIdentifierAndType)
        .m(&PXR_NS::SdrRegistry::GetShaderNodeByName)
        .m(&PXR_NS::SdrRegistry::GetShaderNodeByNameAndType)
        .m(&PXR_NS::SdrRegistry::GetShaderNodeFromAsset)
        .m(&PXR_NS::SdrRegistry::GetShaderNodeFromSourceCode)
        .m(&PXR_NS::SdrRegistry::GetShaderNodesByIdentifier)
        .m(&PXR_NS::SdrRegistry::GetShaderNodesByName)
        .m(&PXR_NS::SdrRegistry::GetShaderNodesByFamily)
    ;

    bbl::Class<PXR_NS::SdrShaderNode>("ShaderNode")
        /// XXX: rvalue ref
        // .ctor(bbl::Class<PXR_NS::SdrShaderNode>::Ctor<const PXR_NS::NdrIdentifier &, const PXR_NS::NdrVersion &, const std::string &, const PXR_NS::TfToken &, const PXR_NS::TfToken &, const PXR_NS::TfToken &, const std::string &, const std::string &, PXR_NS::NdrPropertyUniquePtrVec &&, const PXR_NS::NdrTokenMap &, const std::string &>("identifier", "version", "name", "family", "context", "sourceType", "definitionURI", "implementationURI", "properties", "metadata", "sourceCode"), "ctor_00")
        .m(&PXR_NS::SdrShaderNode::GetShaderInput)
        .m(&PXR_NS::SdrShaderNode::GetShaderOutput)
        .m(&PXR_NS::SdrShaderNode::GetAssetIdentifierInputNames)
        .m(&PXR_NS::SdrShaderNode::GetDefaultInput)
        .m(&PXR_NS::SdrShaderNode::GetLabel)
        .m(&PXR_NS::SdrShaderNode::GetCategory)
        .m(&PXR_NS::SdrShaderNode::GetRole)
        .m(&PXR_NS::SdrShaderNode::GetHelp)
        .m(&PXR_NS::SdrShaderNode::GetDepartments)
        .m(&PXR_NS::SdrShaderNode::GetPages)
        .m(&PXR_NS::SdrShaderNode::GetPrimvars)
        .m(&PXR_NS::SdrShaderNode::GetAdditionalPrimvarProperties)
        .m(&PXR_NS::SdrShaderNode::GetImplementationName)
        .m(&PXR_NS::SdrShaderNode::GetPropertyNamesForPage)
        .m(&PXR_NS::SdrShaderNode::GetAllVstructNames)
    ;

    bbl::Class<std::vector<PXR_NS::SdrShaderNode>>("ShaderNodeVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdrShaderNode)
    ;

    bbl::Class<PXR_NS::SdrShaderNodePtrVec>("ShaderNodePtrVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdrShaderNode const*)
    ;

    bbl::Class<PXR_NS::SdrShaderProperty>("ShaderProperty")
        .ctor(bbl::Class<PXR_NS::SdrShaderProperty>::Ctor<const PXR_NS::TfToken &, const PXR_NS::TfToken &, const PXR_NS::VtValue &, bool, size_t, const PXR_NS::NdrTokenMap &, const PXR_NS::NdrTokenMap &, const PXR_NS::NdrOptionVec &>("name", "type", "defaultValue", "isOutput", "arraySize", "metadata", "hints", "options"), "ctor_00")
        .m(&PXR_NS::SdrShaderProperty::GetLabel)
        .m(&PXR_NS::SdrShaderProperty::GetHelp)
        .m(&PXR_NS::SdrShaderProperty::GetPage)
        .m(&PXR_NS::SdrShaderProperty::GetWidget)
        .m(&PXR_NS::SdrShaderProperty::GetHints)
        .m(&PXR_NS::SdrShaderProperty::GetOptions)
        .m(&PXR_NS::SdrShaderProperty::GetImplementationName)
        .m(&PXR_NS::SdrShaderProperty::GetVStructMemberOf)
        .m(&PXR_NS::SdrShaderProperty::GetVStructMemberName)
        .m(&PXR_NS::SdrShaderProperty::IsVStructMember)
        .m(&PXR_NS::SdrShaderProperty::IsVStruct)
        .m(&PXR_NS::SdrShaderProperty::GetVStructConditionalExpr)
        .m(&PXR_NS::SdrShaderProperty::IsConnectable)
        .m(&PXR_NS::SdrShaderProperty::GetValidConnectionTypes)
        .m(&PXR_NS::SdrShaderProperty::CanConnectTo)
        .m(&PXR_NS::SdrShaderProperty::GetTypeAsSdfType)
        .m(&PXR_NS::SdrShaderProperty::GetDefaultValueAsSdfType)
        .m(&PXR_NS::SdrShaderProperty::IsAssetIdentifier)
        .m(&PXR_NS::SdrShaderProperty::IsDefaultInput)
    ;


}


#endif
