#if defined(__clang__)

#include "babble"

#include <pxr/usdImaging/usdImagingGL/engine.h>
#include <pxr/usdImaging/usdImagingGL/renderParams.h>

namespace bblext {
    void GLRenderParams_SetEnableLighting(PXR_NS::UsdImagingGLRenderParams& params, bool enableLighting) {
        params.enableLighting = enableLighting;
    }
}

BBL_MODULE(usdImaging) {
    bbl::Class<PXR_NS::UsdImagingGLEngine>("GLEngine")
        .ctor(bbl::Class<PXR_NS::UsdImagingGLEngine>::Ctor<>(), "new")
        .m(&PXR_NS::UsdImagingGLEngine::SetRenderViewport)
        .m(&PXR_NS::UsdImagingGLEngine::SetCameraState)
        .m(&PXR_NS::UsdImagingGLEngine::Render)
        .m(&PXR_NS::UsdImagingGLEngine::SetRendererSetting);

    bbl::Class<PXR_NS::UsdImagingGLRenderParams>("GLRenderParams")
        .ctor(bbl::Class<PXR_NS::UsdImagingGLRenderParams>::Ctor<>(), "new");

    bbl::fn(&bblext::GLRenderParams_SetEnableLighting, "GLRenderParams_SetEnableLighting");
}


#endif
