#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/layerOffset.h>

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfLayerOffset>("LayerOffset")
        .ctor(bbl::Class<PXR_NS::SdfLayerOffset>::Ctor<double, double>("offset", "scale"), "ctor")
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
}

#endif


