#if defined(__clang__)

#include "babble"

#include <pxr/usdImaging/usdImagingGL/engine.h>
#include <pxr/usdImaging/usdImagingGL/renderParams.h>
#include <pxr/base/gf/camera.h>
#include <pxr/usd/usdGeom/camera.h>

namespace bblext {
    void render(PXR_NS::UsdImagingGLEngine& engine, const PXR_NS::UsdPrim& prim) {
        pxr::UsdImagingGLRenderParams params;
        params.enableLighting = false;
        engine.Render(prim, params);
    }
}

BBL_MODULE(usdImaging) {
    bbl::fn(&bblext::render, "render");

    bbl::Class<PXR_NS::UsdImagingGLEngine>("GLEngine")
        .ctor(bbl::Class<PXR_NS::UsdImagingGLEngine>::Ctor<>(), "new")
        .m(&PXR_NS::UsdImagingGLEngine::SetRenderViewport)
        .m(&PXR_NS::UsdImagingGLEngine::SetCameraState)
        .m(&PXR_NS::UsdImagingGLEngine::Render);

}


#endif
