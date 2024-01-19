#if defined(__clang__)

#include "babble"

#include <pxr/usdImaging/usdImagingGL/engine.h>
#include <pxr/usdImaging/usdImagingGL/renderParams.h>
#include <pxr/base/gf/camera.h>
#include <pxr/usd/usdGeom/camera.h>

namespace bblext {
    void set_camera(PXR_NS::UsdImagingGLEngine& engine, const PXR_NS::UsdPrim& cameraPrim) {
        auto camera = pxr::UsdGeomCamera(cameraPrim).GetCamera(pxr::UsdTimeCode::Default());

        engine.SetCameraState(camera.GetFrustum().ComputeViewMatrix(),
            camera.GetFrustum().ComputeProjectionMatrix());
    }

    void render(PXR_NS::UsdImagingGLEngine& engine, const PXR_NS::UsdPrim& prim) {
        pxr::UsdImagingGLRenderParams params;
        params.enableLighting = false;
        engine.Render(prim, params);

    }
}

BBL_MODULE(usdImaging) {
    bbl::fn(&bblext::render, "render");
    bbl::fn(&bblext::set_camera, "set_camera");

    bbl::Class<PXR_NS::UsdImagingGLEngine>("GLEngine")
        .ctor(bbl::Class<PXR_NS::UsdImagingGLEngine>::Ctor<>(), "new")
        .m(&PXR_NS::UsdImagingGLEngine::SetRenderViewport);

}


#endif
