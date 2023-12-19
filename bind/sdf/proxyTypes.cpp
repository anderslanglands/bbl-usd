#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/proxyTypes.h>

BBL_MODULE(sdf) {
    // clang-format off
    
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

}

#endif


