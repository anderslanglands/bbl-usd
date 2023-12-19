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

BBL_MODULE(sdf) {

    // clang-format off

    // Probably don't want to bind SdfAbstractData*?

    bbl::Class<PXR_NS::SdfDictionaryProxy>("DictionaryProxy");

    bbl::Class<PXR_NS::SdfInheritsProxy>("InheritsProxy");

    bbl::Class<PXR_NS::SdfNameChildrenOrderProxy>("NameChildrenOrderProxy");

    bbl::Class<PXR_NS::SdfNameEditorProxy>("NameEditorProxy");

    // bbl::Class<PXR_NS::SdfPathEditorProxy>("PathEditorProxy");


    // bbl::Class<PXR_NS::SdfPayloadsProxy>("PayloadsProxy");

    bbl::Enum<PXR_NS::SdfPermission>("Permission");



    // bbl::Class<PXR_NS::SdfReferencesProxy>("ReferencesProxy");

    bbl::Class<PXR_NS::SdfRelocatesMap>("RelocatesMap");
    bbl::Class<PXR_NS::SdfRelocatesMapProxy>("RelocatesMapProxy");

    bbl::Class<std::pair<PXR_NS::TfToken, PXR_NS::JsValue>>("TokenValuePair");

    // bbl::Class<PXR_NS::SdfSpecializesProxy>("SpecializesProxy");

    bbl::Enum<PXR_NS::SdfSpecifier>("Specifier");

    bbl::Enum<PXR_NS::SdfSpecType>("SpecType");

    bbl::Class<PXR_NS::SdfSubLayerProxy>("SubLayerProxy")
    ;

    // bbl::Class<PXR_NS::SdfTextFileFormat>("TextFileFormat")
    //     FILEFORMAT_METHODS(PXR_NS::SdfTextFileFormat)
    //     ;

    bbl::Class<PXR_NS::SdfTimeSampleMap>("TimeSampleMap");

    bbl::Class<PXR_NS::SdfTupleDimensions>("TupleDimensions")
        .value_type()
        .f(&PXR_NS::SdfTupleDimensions::d)
        .f(&PXR_NS::SdfTupleDimensions::size)
        ;

    bbl::Class<PXR_NS::SdfValueBlock>("ValueBlock")
        .ctor(bbl::Class<PXR_NS::SdfValueBlock>::Ctor<>(), "new")
    ;

    bbl::Enum<PXR_NS::SdfVariability>("Variability");

    bbl::Class<PXR_NS::SdfVariantSelectionProxy>("VariantSelectionProxy");
    // bbl::Class<PXR_NS::SdfVariantSetNamesProxy>("VariantSetNamesProxy");
    // bbl::Class<PXR_NS::SdfVariantSetsProxy>("VariantSetsProxy");

    bbl::Class<PXR_NS::SdfVariantSetsProxy>("VariantSetsProxy");

}

#endif
