#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/layerTree.h>

BBL_MODULE(sdf) {
    // clang-format off

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
}

#endif


