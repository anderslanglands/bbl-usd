#if defined(__clang__)

#include "babble"
#include "babble-std"

#include <pxr/usd/usdLux/boundableLightBase.h>
#include <pxr/usd/usdLux/cylinderLight.h>
#include <pxr/usd/usdLux/diskLight.h>
#include <pxr/usd/usdLux/distantLight.h>
#include <pxr/usd/usdLux/domeLight.h>
#include <pxr/usd/usdLux/geometryLight.h>
#include <pxr/usd/usdLux/lightFilter.h>
#include <pxr/usd/usdLux/lightListAPI.h>
#include <pxr/usd/usdLux/listAPI.h>
#include <pxr/usd/usdLux/meshLightAPI.h>
#include <pxr/usd/usdLux/nonboundableLightBase.h>
#include <pxr/usd/usdLux/pluginLight.h>
#include <pxr/usd/usdLux/pluginLightFilter.h>
#include <pxr/usd/usdLux/portalLight.h>
#include <pxr/usd/usdLux/rectLight.h>
#include <pxr/usd/usdLux/shadowAPI.h>
#include <pxr/usd/usdLux/shapingAPI.h>
#include <pxr/usd/usdLux/sphereLight.h>
#include <pxr/usd/usdLux/volumeLightAPI.h>

BBL_MODULE(usdLux) {
    // clang-format off

    bbl::Class<PXR_NS::UsdLuxBoundableLightBase>("BoundableLightBase")
        .ctor(bbl::Class<PXR_NS::UsdLuxBoundableLightBase>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdLuxBoundableLightBase>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .m(&PXR_NS::UsdLuxBoundableLightBase::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdLuxBoundableLightBase::Get)
        .m(&PXR_NS::UsdLuxBoundableLightBase::LightAPI)
        .m(&PXR_NS::UsdLuxBoundableLightBase::GetIntensityAttr)
        .m(&PXR_NS::UsdLuxBoundableLightBase::CreateIntensityAttr)
        .m(&PXR_NS::UsdLuxBoundableLightBase::GetExposureAttr)
        .m(&PXR_NS::UsdLuxBoundableLightBase::CreateExposureAttr)
        .m(&PXR_NS::UsdLuxBoundableLightBase::GetDiffuseAttr)
        .m(&PXR_NS::UsdLuxBoundableLightBase::CreateDiffuseAttr)
        .m(&PXR_NS::UsdLuxBoundableLightBase::GetSpecularAttr)
        .m(&PXR_NS::UsdLuxBoundableLightBase::CreateSpecularAttr)
        .m(&PXR_NS::UsdLuxBoundableLightBase::GetNormalizeAttr)
        .m(&PXR_NS::UsdLuxBoundableLightBase::CreateNormalizeAttr)
        .m(&PXR_NS::UsdLuxBoundableLightBase::GetColorAttr)
        .m(&PXR_NS::UsdLuxBoundableLightBase::CreateColorAttr)
        .m(&PXR_NS::UsdLuxBoundableLightBase::GetEnableColorTemperatureAttr)
        .m(&PXR_NS::UsdLuxBoundableLightBase::CreateEnableColorTemperatureAttr)
        .m(&PXR_NS::UsdLuxBoundableLightBase::GetColorTemperatureAttr)
        .m(&PXR_NS::UsdLuxBoundableLightBase::CreateColorTemperatureAttr)
        .m(&PXR_NS::UsdLuxBoundableLightBase::GetFiltersRel)
        .m(&PXR_NS::UsdLuxBoundableLightBase::CreateFiltersRel)
    ;

    bbl::Class<PXR_NS::UsdLuxCylinderLight>("CylinderLight")
        .ctor(bbl::Class<PXR_NS::UsdLuxCylinderLight>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdLuxCylinderLight>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .m(&PXR_NS::UsdLuxCylinderLight::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdLuxCylinderLight::Get)
        .m(&PXR_NS::UsdLuxCylinderLight::Define)
        .m(&PXR_NS::UsdLuxCylinderLight::GetLengthAttr)
        .m(&PXR_NS::UsdLuxCylinderLight::CreateLengthAttr)
        .m(&PXR_NS::UsdLuxCylinderLight::GetRadiusAttr)
        .m(&PXR_NS::UsdLuxCylinderLight::CreateRadiusAttr)
        .m(&PXR_NS::UsdLuxCylinderLight::GetTreatAsLineAttr)
        .m(&PXR_NS::UsdLuxCylinderLight::CreateTreatAsLineAttr)
    ;

    bbl::Class<PXR_NS::UsdLuxDiskLight>("DiskLight")
        .ctor(bbl::Class<PXR_NS::UsdLuxDiskLight>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdLuxDiskLight>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .m(&PXR_NS::UsdLuxDiskLight::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdLuxDiskLight::Get)
        .m(&PXR_NS::UsdLuxDiskLight::Define)
        .m(&PXR_NS::UsdLuxDiskLight::GetRadiusAttr)
        .m(&PXR_NS::UsdLuxDiskLight::CreateRadiusAttr)
    ;

    bbl::Class<PXR_NS::UsdLuxDistantLight>("DistantLight")
        .ctor(bbl::Class<PXR_NS::UsdLuxDistantLight>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdLuxDistantLight>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .m(&PXR_NS::UsdLuxDistantLight::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdLuxDistantLight::Get)
        .m(&PXR_NS::UsdLuxDistantLight::Define)
        .m(&PXR_NS::UsdLuxDistantLight::GetAngleAttr)
        .m(&PXR_NS::UsdLuxDistantLight::CreateAngleAttr)
        .m(&PXR_NS::UsdLuxDistantLight::operator=, "op_assign")
    ;

    bbl::Class<PXR_NS::UsdLuxDomeLight>("DomeLight")
        .ctor(bbl::Class<PXR_NS::UsdLuxDomeLight>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdLuxDomeLight>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .m(&PXR_NS::UsdLuxDomeLight::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdLuxDomeLight::Get)
        .m(&PXR_NS::UsdLuxDomeLight::Define)
        .m(&PXR_NS::UsdLuxDomeLight::GetTextureFileAttr)
        .m(&PXR_NS::UsdLuxDomeLight::CreateTextureFileAttr)
        .m(&PXR_NS::UsdLuxDomeLight::GetTextureFormatAttr)
        .m(&PXR_NS::UsdLuxDomeLight::CreateTextureFormatAttr)
        .m(&PXR_NS::UsdLuxDomeLight::GetGuideRadiusAttr)
        .m(&PXR_NS::UsdLuxDomeLight::CreateGuideRadiusAttr)
        .m(&PXR_NS::UsdLuxDomeLight::GetPortalsRel)
        .m(&PXR_NS::UsdLuxDomeLight::CreatePortalsRel)
        .m(&PXR_NS::UsdLuxDomeLight::OrientToStageUpAxis)
    ;

    bbl::Class<PXR_NS::UsdLuxGeometryLight>("GeometryLight")
        .ctor(bbl::Class<PXR_NS::UsdLuxGeometryLight>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdLuxGeometryLight>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .m(&PXR_NS::UsdLuxGeometryLight::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdLuxGeometryLight::Get)
        .m(&PXR_NS::UsdLuxGeometryLight::Define)
        .m(&PXR_NS::UsdLuxGeometryLight::GetGeometryRel)
        .m(&PXR_NS::UsdLuxGeometryLight::CreateGeometryRel)
    ;

    bbl::Class<PXR_NS::UsdLuxLightAPI>("LightAPI")
        .ctor(bbl::Class<PXR_NS::UsdLuxLightAPI>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdLuxLightAPI>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .ctor(bbl::Class<PXR_NS::UsdLuxLightAPI>::Ctor<const PXR_NS::UsdShadeConnectableAPI &>("connectable"), "from_conneactable")
        .m(&PXR_NS::UsdLuxLightAPI::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdLuxLightAPI::Get)
        .m(&PXR_NS::UsdLuxLightAPI::CanApply)
        .m(&PXR_NS::UsdLuxLightAPI::Apply)
        .m(&PXR_NS::UsdLuxLightAPI::GetShaderIdAttr)
        .m(&PXR_NS::UsdLuxLightAPI::CreateShaderIdAttr)
        .m(&PXR_NS::UsdLuxLightAPI::GetMaterialSyncModeAttr)
        .m(&PXR_NS::UsdLuxLightAPI::CreateMaterialSyncModeAttr)
        .m(&PXR_NS::UsdLuxLightAPI::GetIntensityAttr)
        .m(&PXR_NS::UsdLuxLightAPI::CreateIntensityAttr)
        .m(&PXR_NS::UsdLuxLightAPI::GetExposureAttr)
        .m(&PXR_NS::UsdLuxLightAPI::CreateExposureAttr)
        .m(&PXR_NS::UsdLuxLightAPI::GetDiffuseAttr)
        .m(&PXR_NS::UsdLuxLightAPI::CreateDiffuseAttr)
        .m(&PXR_NS::UsdLuxLightAPI::GetSpecularAttr)
        .m(&PXR_NS::UsdLuxLightAPI::CreateSpecularAttr)
        .m(&PXR_NS::UsdLuxLightAPI::GetNormalizeAttr)
        .m(&PXR_NS::UsdLuxLightAPI::CreateNormalizeAttr)
        .m(&PXR_NS::UsdLuxLightAPI::GetColorAttr)
        .m(&PXR_NS::UsdLuxLightAPI::CreateColorAttr)
        .m(&PXR_NS::UsdLuxLightAPI::GetEnableColorTemperatureAttr)
        .m(&PXR_NS::UsdLuxLightAPI::CreateEnableColorTemperatureAttr)
        .m(&PXR_NS::UsdLuxLightAPI::GetColorTemperatureAttr)
        .m(&PXR_NS::UsdLuxLightAPI::CreateColorTemperatureAttr)
        .m(&PXR_NS::UsdLuxLightAPI::GetFiltersRel)
        .m(&PXR_NS::UsdLuxLightAPI::CreateFiltersRel)
        .m(&PXR_NS::UsdLuxLightAPI::ConnectableAPI)
        .m(&PXR_NS::UsdLuxLightAPI::CreateOutput)
        .m(&PXR_NS::UsdLuxLightAPI::GetOutput)
        .m(&PXR_NS::UsdLuxLightAPI::GetOutputs)
        .m(&PXR_NS::UsdLuxLightAPI::CreateInput)
        .m(&PXR_NS::UsdLuxLightAPI::GetInput)
        .m(&PXR_NS::UsdLuxLightAPI::GetInputs)
        .m(&PXR_NS::UsdLuxLightAPI::GetLightLinkCollectionAPI)
        .m(&PXR_NS::UsdLuxLightAPI::GetShadowLinkCollectionAPI)
        .m(&PXR_NS::UsdLuxLightAPI::GetShaderIdAttrForRenderContext)
        .m(&PXR_NS::UsdLuxLightAPI::CreateShaderIdAttrForRenderContext)
        .m(&PXR_NS::UsdLuxLightAPI::GetShaderId)
    ;

    bbl::Class<PXR_NS::UsdLuxLightFilter>("LightFilter")
        .ctor(bbl::Class<PXR_NS::UsdLuxLightFilter>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdLuxLightFilter>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .ctor(bbl::Class<PXR_NS::UsdLuxLightFilter>::Ctor<const PXR_NS::UsdShadeConnectableAPI &>("connectable"), "from_conneactable")
        .m(&PXR_NS::UsdLuxLightFilter::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdLuxLightFilter::Get)
        .m(&PXR_NS::UsdLuxLightFilter::Define)
        .m(&PXR_NS::UsdLuxLightFilter::GetShaderIdAttr)
        .m(&PXR_NS::UsdLuxLightFilter::CreateShaderIdAttr)
        .m(&PXR_NS::UsdLuxLightFilter::ConnectableAPI)
        .m(&PXR_NS::UsdLuxLightFilter::CreateOutput)
        .m(&PXR_NS::UsdLuxLightFilter::GetOutput)
        .m(&PXR_NS::UsdLuxLightFilter::GetOutputs)
        .m(&PXR_NS::UsdLuxLightFilter::CreateInput)
        .m(&PXR_NS::UsdLuxLightFilter::GetInput)
        .m(&PXR_NS::UsdLuxLightFilter::GetInputs)
        .m(&PXR_NS::UsdLuxLightFilter::GetFilterLinkCollectionAPI)
        .m(&PXR_NS::UsdLuxLightFilter::GetShaderIdAttrForRenderContext)
        .m(&PXR_NS::UsdLuxLightFilter::CreateShaderIdAttrForRenderContext)
        .m(&PXR_NS::UsdLuxLightFilter::GetShaderId)
    ;

    bbl::Class<PXR_NS::UsdLuxLightListAPI>("LightListAPI")
        .ctor(bbl::Class<PXR_NS::UsdLuxLightListAPI>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdLuxLightListAPI>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .m(&PXR_NS::UsdLuxLightListAPI::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdLuxLightListAPI::Get)
        .m(&PXR_NS::UsdLuxLightListAPI::CanApply)
        .m(&PXR_NS::UsdLuxLightListAPI::Apply)
        .m(&PXR_NS::UsdLuxLightListAPI::GetLightListCacheBehaviorAttr)
        .m(&PXR_NS::UsdLuxLightListAPI::CreateLightListCacheBehaviorAttr)
        .m(&PXR_NS::UsdLuxLightListAPI::GetLightListRel)
        .m(&PXR_NS::UsdLuxLightListAPI::CreateLightListRel)
        .m(&PXR_NS::UsdLuxLightListAPI::ComputeLightList)
        .m(&PXR_NS::UsdLuxLightListAPI::StoreLightList)
        .m(&PXR_NS::UsdLuxLightListAPI::InvalidateLightList)
    ;

    bbl::Enum<PXR_NS::UsdLuxLightListAPI::ComputeMode>("LightListAPIComputeMode");

    bbl::Class<PXR_NS::UsdLuxMeshLightAPI>("MeshLightAPI")
        .ctor(bbl::Class<PXR_NS::UsdLuxMeshLightAPI>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdLuxMeshLightAPI>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .m(&PXR_NS::UsdLuxMeshLightAPI::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdLuxMeshLightAPI::Get)
        .m(&PXR_NS::UsdLuxMeshLightAPI::CanApply)
        .m(&PXR_NS::UsdLuxMeshLightAPI::Apply)
    ;

    bbl::Class<PXR_NS::UsdLuxNonboundableLightBase>("NonboundableLightBase")
        .ctor(bbl::Class<PXR_NS::UsdLuxNonboundableLightBase>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdLuxNonboundableLightBase>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .m(&PXR_NS::UsdLuxNonboundableLightBase::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdLuxNonboundableLightBase::Get)
        .m(&PXR_NS::UsdLuxNonboundableLightBase::LightAPI)
        .m(&PXR_NS::UsdLuxNonboundableLightBase::GetIntensityAttr)
        .m(&PXR_NS::UsdLuxNonboundableLightBase::CreateIntensityAttr)
        .m(&PXR_NS::UsdLuxNonboundableLightBase::GetExposureAttr)
        .m(&PXR_NS::UsdLuxNonboundableLightBase::CreateExposureAttr)
        .m(&PXR_NS::UsdLuxNonboundableLightBase::GetDiffuseAttr)
        .m(&PXR_NS::UsdLuxNonboundableLightBase::CreateDiffuseAttr)
        .m(&PXR_NS::UsdLuxNonboundableLightBase::GetSpecularAttr)
        .m(&PXR_NS::UsdLuxNonboundableLightBase::CreateSpecularAttr)
        .m(&PXR_NS::UsdLuxNonboundableLightBase::GetNormalizeAttr)
        .m(&PXR_NS::UsdLuxNonboundableLightBase::CreateNormalizeAttr)
        .m(&PXR_NS::UsdLuxNonboundableLightBase::GetColorAttr)
        .m(&PXR_NS::UsdLuxNonboundableLightBase::CreateColorAttr)
        .m(&PXR_NS::UsdLuxNonboundableLightBase::GetEnableColorTemperatureAttr)
        .m(&PXR_NS::UsdLuxNonboundableLightBase::CreateEnableColorTemperatureAttr)
        .m(&PXR_NS::UsdLuxNonboundableLightBase::GetColorTemperatureAttr)
        .m(&PXR_NS::UsdLuxNonboundableLightBase::CreateColorTemperatureAttr)
        .m(&PXR_NS::UsdLuxNonboundableLightBase::GetFiltersRel)
        .m(&PXR_NS::UsdLuxNonboundableLightBase::CreateFiltersRel)
    ;

    bbl::Class<PXR_NS::UsdLuxPluginLight>("PluginLight")
        .ctor(bbl::Class<PXR_NS::UsdLuxPluginLight>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdLuxPluginLight>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .m(&PXR_NS::UsdLuxPluginLight::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdLuxPluginLight::Get)
        .m(&PXR_NS::UsdLuxPluginLight::Define)
        .m(&PXR_NS::UsdLuxPluginLight::GetNodeDefAPI)
    ;

    bbl::Class<PXR_NS::UsdLuxPluginLightFilter>("PluginLightFilter")
        .ctor(bbl::Class<PXR_NS::UsdLuxPluginLightFilter>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdLuxPluginLightFilter>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .m(&PXR_NS::UsdLuxPluginLightFilter::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdLuxPluginLightFilter::Get)
        .m(&PXR_NS::UsdLuxPluginLightFilter::Define)
        .m(&PXR_NS::UsdLuxPluginLightFilter::GetNodeDefAPI)
    ;

    bbl::Class<PXR_NS::UsdLuxPortalLight>("PortalLight")
        .ctor(bbl::Class<PXR_NS::UsdLuxPortalLight>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdLuxPortalLight>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .m(&PXR_NS::UsdLuxPortalLight::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdLuxPortalLight::Get)
        .m(&PXR_NS::UsdLuxPortalLight::Define)
    ;

    bbl::Class<PXR_NS::UsdLuxRectLight>("RectLight")
        .ctor(bbl::Class<PXR_NS::UsdLuxRectLight>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdLuxRectLight>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .m(&PXR_NS::UsdLuxRectLight::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdLuxRectLight::Get)
        .m(&PXR_NS::UsdLuxRectLight::Define)
        .m(&PXR_NS::UsdLuxRectLight::GetWidthAttr)
        .m(&PXR_NS::UsdLuxRectLight::CreateWidthAttr)
        .m(&PXR_NS::UsdLuxRectLight::GetHeightAttr)
        .m(&PXR_NS::UsdLuxRectLight::CreateHeightAttr)
        .m(&PXR_NS::UsdLuxRectLight::GetTextureFileAttr)
        .m(&PXR_NS::UsdLuxRectLight::CreateTextureFileAttr)
    ;

    bbl::Class<PXR_NS::UsdLuxShadowAPI>("ShadowAPI")
        .ctor(bbl::Class<PXR_NS::UsdLuxShadowAPI>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdLuxShadowAPI>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .ctor(bbl::Class<PXR_NS::UsdLuxShadowAPI>::Ctor<const PXR_NS::UsdShadeConnectableAPI &>("connectable"), "from_conneactable")
        .m(&PXR_NS::UsdLuxShadowAPI::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdLuxShadowAPI::Get)
        .m(&PXR_NS::UsdLuxShadowAPI::CanApply)
        .m(&PXR_NS::UsdLuxShadowAPI::Apply)
        .m(&PXR_NS::UsdLuxShadowAPI::GetShadowEnableAttr)
        .m(&PXR_NS::UsdLuxShadowAPI::CreateShadowEnableAttr)
        .m(&PXR_NS::UsdLuxShadowAPI::GetShadowColorAttr)
        .m(&PXR_NS::UsdLuxShadowAPI::CreateShadowColorAttr)
        .m(&PXR_NS::UsdLuxShadowAPI::GetShadowDistanceAttr)
        .m(&PXR_NS::UsdLuxShadowAPI::CreateShadowDistanceAttr)
        .m(&PXR_NS::UsdLuxShadowAPI::GetShadowFalloffAttr)
        .m(&PXR_NS::UsdLuxShadowAPI::CreateShadowFalloffAttr)
        .m(&PXR_NS::UsdLuxShadowAPI::GetShadowFalloffGammaAttr)
        .m(&PXR_NS::UsdLuxShadowAPI::CreateShadowFalloffGammaAttr)
        .m(&PXR_NS::UsdLuxShadowAPI::ConnectableAPI)
        .m(&PXR_NS::UsdLuxShadowAPI::CreateOutput)
        .m(&PXR_NS::UsdLuxShadowAPI::GetOutput)
        .m(&PXR_NS::UsdLuxShadowAPI::GetOutputs)
        .m(&PXR_NS::UsdLuxShadowAPI::CreateInput)
        .m(&PXR_NS::UsdLuxShadowAPI::GetInput)
        .m(&PXR_NS::UsdLuxShadowAPI::GetInputs)
    ;

    bbl::Class<PXR_NS::UsdLuxShapingAPI>("ShapingAPI")
        .ctor(bbl::Class<PXR_NS::UsdLuxShapingAPI>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdLuxShapingAPI>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .ctor(bbl::Class<PXR_NS::UsdLuxShapingAPI>::Ctor<const PXR_NS::UsdShadeConnectableAPI &>("connectable"), "from_conneactable")
        .m(&PXR_NS::UsdLuxShapingAPI::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdLuxShapingAPI::Get)
        .m(&PXR_NS::UsdLuxShapingAPI::CanApply)
        .m(&PXR_NS::UsdLuxShapingAPI::Apply)
        .m(&PXR_NS::UsdLuxShapingAPI::GetShapingFocusAttr)
        .m(&PXR_NS::UsdLuxShapingAPI::CreateShapingFocusAttr)
        .m(&PXR_NS::UsdLuxShapingAPI::GetShapingFocusTintAttr)
        .m(&PXR_NS::UsdLuxShapingAPI::CreateShapingFocusTintAttr)
        .m(&PXR_NS::UsdLuxShapingAPI::GetShapingConeAngleAttr)
        .m(&PXR_NS::UsdLuxShapingAPI::CreateShapingConeAngleAttr)
        .m(&PXR_NS::UsdLuxShapingAPI::GetShapingConeSoftnessAttr)
        .m(&PXR_NS::UsdLuxShapingAPI::CreateShapingConeSoftnessAttr)
        .m(&PXR_NS::UsdLuxShapingAPI::GetShapingIesFileAttr)
        .m(&PXR_NS::UsdLuxShapingAPI::CreateShapingIesFileAttr)
        .m(&PXR_NS::UsdLuxShapingAPI::GetShapingIesAngleScaleAttr)
        .m(&PXR_NS::UsdLuxShapingAPI::CreateShapingIesAngleScaleAttr)
        .m(&PXR_NS::UsdLuxShapingAPI::GetShapingIesNormalizeAttr)
        .m(&PXR_NS::UsdLuxShapingAPI::CreateShapingIesNormalizeAttr)
        .m(&PXR_NS::UsdLuxShapingAPI::ConnectableAPI)
        .m(&PXR_NS::UsdLuxShapingAPI::CreateOutput)
        .m(&PXR_NS::UsdLuxShapingAPI::GetOutput)
        .m(&PXR_NS::UsdLuxShapingAPI::GetOutputs)
        .m(&PXR_NS::UsdLuxShapingAPI::CreateInput)
        .m(&PXR_NS::UsdLuxShapingAPI::GetInput)
        .m(&PXR_NS::UsdLuxShapingAPI::GetInputs)
    ;

    bbl::Class<PXR_NS::UsdLuxSphereLight>("SphereLight")
        .ctor(bbl::Class<PXR_NS::UsdLuxSphereLight>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdLuxSphereLight>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .m(&PXR_NS::UsdLuxSphereLight::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdLuxSphereLight::Get)
        .m(&PXR_NS::UsdLuxSphereLight::Define)
        .m(&PXR_NS::UsdLuxSphereLight::GetRadiusAttr)
        .m(&PXR_NS::UsdLuxSphereLight::CreateRadiusAttr)
        .m(&PXR_NS::UsdLuxSphereLight::GetTreatAsPointAttr)
        .m(&PXR_NS::UsdLuxSphereLight::CreateTreatAsPointAttr)
    ;

    bbl::Class<PXR_NS::UsdLuxVolumeLightAPI>("VolumeLightAPI")
        .ctor(bbl::Class<PXR_NS::UsdLuxVolumeLightAPI>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .ctor(bbl::Class<PXR_NS::UsdLuxVolumeLightAPI>::Ctor<const PXR_NS::UsdSchemaBase &>("schemaObj"), "from_schema")
        .m(&PXR_NS::UsdLuxVolumeLightAPI::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdLuxVolumeLightAPI::Get)
        .m(&PXR_NS::UsdLuxVolumeLightAPI::CanApply)
        .m(&PXR_NS::UsdLuxVolumeLightAPI::Apply)
    ;


}


#endif
