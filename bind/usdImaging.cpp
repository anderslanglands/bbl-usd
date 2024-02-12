#if defined(__clang__)

#include "babble"

#include <pxr/usdImaging/usdImagingGL/engine.h>
#include <pxr/usdImaging/usdImagingGL/renderParams.h>
#include <pxr/imaging/hd/renderBuffer.h>
#include <pxr/imaging/hgi/texture.h>

namespace bblext {
    void GLRenderParams_SetEnableLighting(PXR_NS::UsdImagingGLRenderParams& params, bool enableLighting) {
        params.enableLighting = enableLighting;
    }

    void GLRenderParams_SetCullStyle(PXR_NS::UsdImagingGLRenderParams& params, PXR_NS::UsdImagingGLCullStyle cullStyle) {
        params.cullStyle = cullStyle;
    }
}

BBL_MODULE(usdImaging) {

    bbl::Class<PXR_NS::CameraUtilFraming>()
        // .value_type()
        // .f(&PXR_NS::CameraUtilFraming::displayWindow)
        // .f(&PXR_NS::CameraUtilFraming::dataWindow)
        // .f(&PXR_NS::CameraUtilFraming::pixelAspectRatio)
        .m(&PXR_NS::CameraUtilFraming::IsValid)
        .m(&PXR_NS::CameraUtilFraming::ApplyToProjectionMatrix)
        .m(&PXR_NS::CameraUtilFraming::ComputeFilmbackWindow)
        .m(&PXR_NS::CameraUtilFraming::operator==)
        .ignore(&PXR_NS::CameraUtilFraming::operator!=)
    ;

    bbl::Enum<PXR_NS::CameraUtilConformWindowPolicy>();

    bbl::Class<PXR_NS::UsdImagingGLEngine>("GLEngine")
        .ctor(bbl::Class<PXR_NS::UsdImagingGLEngine>::Ctor<>(), "new")
        .m(&PXR_NS::UsdImagingGLEngine::SetRenderViewport)
        .m(&PXR_NS::UsdImagingGLEngine::SetCameraState)
        .m(&PXR_NS::UsdImagingGLEngine::Render)
        .m(&PXR_NS::UsdImagingGLEngine::SetRendererSetting)
#if 0
        .m(&PXR_NS::UsdImagingGLEngine::TestIntersection)
        .m(&PXR_NS::UsdImagingGLEngine::PrepareBatch)
        .m(&PXR_NS::UsdImagingGLEngine::RenderBatch)
        .m(&PXR_NS::UsdImagingGLEngine::IsColorCorrectionCapable)
        .m(&PXR_NS::UsdImagingGLEngine::IsConverged)
        .m(&PXR_NS::UsdImagingGLEngine::SetRootTransform)
        .m(&PXR_NS::UsdImagingGLEngine::SetRootVisibility)
        .m(&PXR_NS::UsdImagingGLEngine::SetCameraPath)
        .m(&PXR_NS::UsdImagingGLEngine::SetFraming)
        .m(&PXR_NS::UsdImagingGLEngine::SetOverrideWindowPolicy)
        .m(&PXR_NS::UsdImagingGLEngine::SetRenderBufferSize)
        .m(&PXR_NS::UsdImagingGLEngine::GetHgi)
        .m(&PXR_NS::UsdImagingGLEngine::SetWindowPolicy)
        .m(&PXR_NS::UsdImagingGLEngine::GetRenderStats)
        .m((void (PXR_NS::UsdImagingGLEngine::*)(PXR_NS::GlfSimpleLightingContextPtr const&))
            &PXR_NS::UsdImagingGLEngine::SetLightingState, "SetLightingState_with_context"
        )
        .m((void (PXR_NS::UsdImagingGLEngine::*)(PXR_NS::GlfSimpleLightVector const&, PXR_NS::GlfSimpleMaterial const&, PXR_NS::GfVec4f const&))
            &PXR_NS::UsdImagingGLEngine::SetLightingState
        )
        .m(&PXR_NS::UsdImagingGLEngine::SetSelected)
        .m(&PXR_NS::UsdImagingGLEngine::ClearSelected)
        .m(&PXR_NS::UsdImagingGLEngine::AddSelected)
        .m(&PXR_NS::UsdImagingGLEngine::SetSelectionColor)
        .m(&PXR_NS::UsdImagingGLEngine::RestartRenderer)
        .m(&PXR_NS::UsdImagingGLEngine::DecodeIntersection)
        .m(&PXR_NS::UsdImagingGLEngine::GetRendererPlugins)
        .m(&PXR_NS::UsdImagingGLEngine::GetRendererDisplayName)
        .m(&PXR_NS::UsdImagingGLEngine::GetGPUEnabled)
        .m(&PXR_NS::UsdImagingGLEngine::GetCurrentRendererId)
        .m(&PXR_NS::UsdImagingGLEngine::SetRendererPlugin)
        .m(&PXR_NS::UsdImagingGLEngine::GetRendererAovs)
        .m(&PXR_NS::UsdImagingGLEngine::SetRendererAov)
        .m(&PXR_NS::UsdImagingGLEngine::GetAovTexture)
        .m(&PXR_NS::UsdImagingGLEngine::GetAovRenderBuffer)
        .m(&PXR_NS::UsdImagingGLEngine::GetRendererSettingsList)
        .m(&PXR_NS::UsdImagingGLEngine::GetRendererSetting)
        .m(&PXR_NS::UsdImagingGLEngine::SetColorCorrectionSettings)
        .m(&PXR_NS::UsdImagingGLEngine::SetActiveRenderSettingsPrimPath)
        .m(&PXR_NS::UsdImagingGLEngine::GetAvailableRenderSettingsPrimPaths)
        .m(&PXR_NS::UsdImagingGLEngine::SetEnablePresentation)
        .m(&PXR_NS::UsdImagingGLEngine::SetPresentationOutput)
        .m(&PXR_NS::UsdImagingGLEngine::GetRendererCommandDescriptors)
        .m(&PXR_NS::UsdImagingGLEngine::InvokeRendererCommand)
        .m(&PXR_NS::UsdImagingGLEngine::IsPauseRendererSupported)
        .m(&PXR_NS::UsdImagingGLEngine::PauseRenderer)
        .m(&PXR_NS::UsdImagingGLEngine::ResumeRenderer)
        .m(&PXR_NS::UsdImagingGLEngine::IsStopRendererSupported)
        .m(&PXR_NS::UsdImagingGLEngine::StopRenderer)
#endif
        .ignore_all_unbound()
    ;

    bbl::Class<PXR_NS::UsdImagingGLRenderParams>("GLRenderParams")
        .ctor(bbl::Class<PXR_NS::UsdImagingGLRenderParams>::Ctor<>(), "new")
        .m(&PXR_NS::UsdImagingGLRenderParams::operator==)
        .ignore(&PXR_NS::UsdImagingGLRenderParams::operator!=)
    ;

    bbl::Enum<PXR_NS::UsdImagingGLCullStyle>("GLCullStyle");

    bbl::fn(&bblext::GLRenderParams_SetEnableLighting);
    bbl::fn(&bblext::GLRenderParams_SetCullStyle);

    // bbl::Class<PXR_NS::HdRenderBuffer>()
    //     .m(&PXR_NS::HdRenderBuffer::GetInitialDirtyBitsMask)
    //     .m(&PXR_NS::HdRenderBuffer::Sync)
    //     .m(&PXR_NS::HdRenderBuffer::Finalize)
    //     .m(&PXR_NS::HdRenderBuffer::Allocate)
    //     .m(&PXR_NS::HdRenderBuffer::GetWidth)
    //     .m(&PXR_NS::HdRenderBuffer::GetHeight)
    //     .m(&PXR_NS::HdRenderBuffer::GetDepth)
    //     .m(&PXR_NS::HdRenderBuffer::GetFormat)
    //     .m(&PXR_NS::HdRenderBuffer::IsMultiSampled)
    //     .m(&PXR_NS::HdRenderBuffer::Map)
    //     .m(&PXR_NS::HdRenderBuffer::Unmap)
    //     .m(&PXR_NS::HdRenderBuffer::IsMapped)
    //     .m(&PXR_NS::HdRenderBuffer::Resolve)
    //     .m(&PXR_NS::HdRenderBuffer::IsConverged)
    //     .m(&PXR_NS::HdRenderBuffer::GetResource)
    // ;

    // bbl::Enum<PXR_NS::HdRenderBuffer::DirtyBits>();

    // bbl::Class<PXR_NS::Hgi>()
    //     .ignore_all_unbound()
    // ;

    // bbl::Class<PXR_NS::HgiTextureHandle>()
    //     .m(&PXR_NS::HgiTextureHandle::operator bool)
    //     .m(&PXR_NS::HgiTextureHandle::operator==)
    // ;
}


#endif
