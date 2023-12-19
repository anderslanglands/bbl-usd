#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/editTarget.h>

BBL_MODULE(usd) {
    // clang-format off

    bbl::Class<PXR_NS::UsdEditTarget>("EditTarget")
        .ctor(bbl::Class<PXR_NS::UsdEditTarget>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::UsdEditTarget>::Ctor<PXR_NS::SdfLayerHandle, PXR_NS::SdfLayerOffset>(), "from_layer")
        .ctor(bbl::Class<PXR_NS::UsdEditTarget>::Ctor<PXR_NS::SdfLayerHandle, PXR_NS::PcpNodeRef>(), "from_layer_and_node")
        .m(&PXR_NS::UsdEditTarget::operator==, "op_eq")
        .m(&PXR_NS::UsdEditTarget::IsNull)
        .m(&PXR_NS::UsdEditTarget::IsValid)
        .m((PXR_NS::SdfLayerHandle const& (PXR_NS::UsdEditTarget::*)() const&)
            &PXR_NS::UsdEditTarget::GetLayer
        )
        .m(&PXR_NS::UsdEditTarget::MapToSpecPath)
        .m(&PXR_NS::UsdEditTarget::GetPrimSpecForScenePath)
        .m(&PXR_NS::UsdEditTarget::GetPropertySpecForScenePath)
        .m(&PXR_NS::UsdEditTarget::GetSpecForScenePath)
        .m(&PXR_NS::UsdEditTarget::GetMapFunction)
        .m(&PXR_NS::UsdEditTarget::ComposeOver)
        .m(&PXR_NS::UsdEditTarget::ForLocalDirectVariant)
        ;

}

#endif

