#if defined(__clang__)

#include "babble"

#include <pxr/usd/usdRender/denoisePass.h>
#include <pxr/usd/usdRender/pass.h>
#include <pxr/usd/usdRender/product.h>
#include <pxr/usd/usdRender/settings.h>
#include <pxr/usd/usdRender/settingsBase.h>
#include <pxr/usd/usdRender/spec.h>
#include <pxr/usd/usdRender/var.h>

BBL_MODULE(usdRender) {
    // clang-format off

    bbl::Class<PXR_NS::UsdRenderDenoisePass>("DenoisePass")
        .ctor(bbl::Class<PXR_NS::UsdRenderDenoisePass>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdRenderDenoisePass>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .m(&PXR_NS::UsdRenderDenoisePass::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdRenderDenoisePass::Get)
        .m(&PXR_NS::UsdRenderDenoisePass::Define)
    ;

    bbl::Class<PXR_NS::UsdRenderPass>("Pass")
        .ctor(bbl::Class<PXR_NS::UsdRenderPass>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdRenderPass>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .m(&PXR_NS::UsdRenderPass::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdRenderPass::Get)
        .m(&PXR_NS::UsdRenderPass::Define)
        .m(&PXR_NS::UsdRenderPass::GetPassTypeAttr)
        .m(&PXR_NS::UsdRenderPass::CreatePassTypeAttr)
        .m(&PXR_NS::UsdRenderPass::GetCommandAttr)
        .m(&PXR_NS::UsdRenderPass::CreateCommandAttr)
        .m(&PXR_NS::UsdRenderPass::GetFileNameAttr)
        .m(&PXR_NS::UsdRenderPass::CreateFileNameAttr)
        .m(&PXR_NS::UsdRenderPass::GetDenoiseEnableAttr)
        .m(&PXR_NS::UsdRenderPass::CreateDenoiseEnableAttr)
        .m(&PXR_NS::UsdRenderPass::GetRenderSourceRel)
        .m(&PXR_NS::UsdRenderPass::CreateRenderSourceRel)
        .m(&PXR_NS::UsdRenderPass::GetInputPassesRel)
        .m(&PXR_NS::UsdRenderPass::CreateInputPassesRel)
        .m(&PXR_NS::UsdRenderPass::GetDenoisePassRel)
        .m(&PXR_NS::UsdRenderPass::CreateDenoisePassRel)
        .m(&PXR_NS::UsdRenderPass::GetRenderVisibilityCollectionAPI)
    ;

    bbl::Class<PXR_NS::UsdRenderProduct>("Product")
        .ctor(bbl::Class<PXR_NS::UsdRenderProduct>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdRenderProduct>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .m(&PXR_NS::UsdRenderProduct::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdRenderProduct::Get)
        .m(&PXR_NS::UsdRenderProduct::Define)
        .m(&PXR_NS::UsdRenderProduct::GetProductTypeAttr)
        .m(&PXR_NS::UsdRenderProduct::CreateProductTypeAttr)
        .m(&PXR_NS::UsdRenderProduct::GetProductNameAttr)
        .m(&PXR_NS::UsdRenderProduct::CreateProductNameAttr)
        .m(&PXR_NS::UsdRenderProduct::GetOrderedVarsRel)
        .m(&PXR_NS::UsdRenderProduct::CreateOrderedVarsRel)
    ;

    bbl::Class<PXR_NS::UsdRenderSettings>("Settings")
        .ctor(bbl::Class<PXR_NS::UsdRenderSettings>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdRenderSettings>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .m(&PXR_NS::UsdRenderSettings::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdRenderSettings::Get)
        .m(&PXR_NS::UsdRenderSettings::Define)
        .m(&PXR_NS::UsdRenderSettings::GetIncludedPurposesAttr)
        .m(&PXR_NS::UsdRenderSettings::CreateIncludedPurposesAttr)
        .m(&PXR_NS::UsdRenderSettings::GetMaterialBindingPurposesAttr)
        .m(&PXR_NS::UsdRenderSettings::CreateMaterialBindingPurposesAttr)
        .m(&PXR_NS::UsdRenderSettings::GetRenderingColorSpaceAttr)
        .m(&PXR_NS::UsdRenderSettings::CreateRenderingColorSpaceAttr)
        .m(&PXR_NS::UsdRenderSettings::GetProductsRel)
        .m(&PXR_NS::UsdRenderSettings::CreateProductsRel)
        .m(&PXR_NS::UsdRenderSettings::GetStageRenderSettings)
        .m(&PXR_NS::UsdRenderSettings::operator=, "op_assign")
    ;

    bbl::Class<PXR_NS::UsdRenderSettingsBase>("SettingsBase")
        .ctor(bbl::Class<PXR_NS::UsdRenderSettingsBase>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdRenderSettingsBase>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .m(&PXR_NS::UsdRenderSettingsBase::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdRenderSettingsBase::Get)
        .m(&PXR_NS::UsdRenderSettingsBase::GetResolutionAttr)
        .m(&PXR_NS::UsdRenderSettingsBase::CreateResolutionAttr)
        .m(&PXR_NS::UsdRenderSettingsBase::GetPixelAspectRatioAttr)
        .m(&PXR_NS::UsdRenderSettingsBase::CreatePixelAspectRatioAttr)
        .m(&PXR_NS::UsdRenderSettingsBase::GetAspectRatioConformPolicyAttr)
        .m(&PXR_NS::UsdRenderSettingsBase::CreateAspectRatioConformPolicyAttr)
        .m(&PXR_NS::UsdRenderSettingsBase::GetDataWindowNDCAttr)
        .m(&PXR_NS::UsdRenderSettingsBase::CreateDataWindowNDCAttr)
        .m(&PXR_NS::UsdRenderSettingsBase::GetInstantaneousShutterAttr)
        .m(&PXR_NS::UsdRenderSettingsBase::CreateInstantaneousShutterAttr)
        .m(&PXR_NS::UsdRenderSettingsBase::GetDisableMotionBlurAttr)
        .m(&PXR_NS::UsdRenderSettingsBase::CreateDisableMotionBlurAttr)
        .m(&PXR_NS::UsdRenderSettingsBase::GetCameraRel)
        .m(&PXR_NS::UsdRenderSettingsBase::CreateCameraRel)
    ;

    bbl::Class<PXR_NS::UsdRenderSpec>("Spec")
    ;

    bbl::Class<PXR_NS::UsdRenderSpec::Product>("SpecProduct")
    ;

    bbl::Class<PXR_NS::UsdRenderSpec::RenderVar>("SpecRenderVar")
    ;

    bbl::Class<PXR_NS::UsdRenderVar>("Var")
        .ctor(bbl::Class<PXR_NS::UsdRenderVar>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdRenderVar>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .m(&PXR_NS::UsdRenderVar::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdRenderVar::Get)
        .m(&PXR_NS::UsdRenderVar::Define)
        .m(&PXR_NS::UsdRenderVar::GetDataTypeAttr)
        .m(&PXR_NS::UsdRenderVar::CreateDataTypeAttr)
        .m(&PXR_NS::UsdRenderVar::GetSourceNameAttr)
        .m(&PXR_NS::UsdRenderVar::CreateSourceNameAttr)
        .m(&PXR_NS::UsdRenderVar::GetSourceTypeAttr)
        .m(&PXR_NS::UsdRenderVar::CreateSourceTypeAttr)
    ;


}


#endif
