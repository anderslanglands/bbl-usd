#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/changeBlock.h>

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfChangeBlock>("ChangeBlock")
        .ctor(bbl::Class<PXR_NS::SdfChangeBlock>::Ctor<>(), "default")
        ;

}

#endif


