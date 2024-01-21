#if defined(__clang__)

#include "babble"
#include "babble-std"

#include <pxr/base/gf/bbox3d.h>
#include <pxr/base/gf/matrix4d.h>
#include <pxr/base/tf/hashmap.h>
#include <pxr/base/tf/token.h>
#include <pxr/base/vt/types.h>
#include <pxr/base/vt/value.h>
#include <pxr/usd/sdf/path.h>
#include <pxr/usd/usd/attribute.h>
#include <pxr/usd/usd/prim.h>
#include <pxr/usd/usd/timeCode.h>
#include <pxr/usd/usd/apiSchemaBase.h>
#include <pxr/usd/usdGeom/basisCurves.h>
#include <pxr/usd/usdGeom/bboxCache.h>
#include <pxr/usd/usdGeom/boundable.h>
#include <pxr/usd/usdGeom/camera.h>
#include <pxr/usd/usdGeom/capsule.h>
#include <pxr/usd/usdGeom/cone.h>
#include <pxr/usd/usdGeom/constraintTarget.h>
#include <pxr/usd/usdGeom/cube.h>
#include <pxr/usd/usdGeom/curves.h>
#include <pxr/usd/usdGeom/cylinder.h>
#include <pxr/usd/usdGeom/gprim.h>
#include <pxr/usd/usdGeom/hermiteCurves.h>
#include <pxr/usd/usdGeom/imageable.h>
#include <pxr/usd/usdGeom/mesh.h>
#include <pxr/usd/usdGeom/modelAPI.h>
#include <pxr/usd/usdGeom/motionAPI.h>
#include <pxr/usd/usdGeom/nurbsCurves.h>
#include <pxr/usd/usdGeom/nurbsPatch.h>
#include <pxr/usd/usdGeom/plane.h>
#include <pxr/usd/usdGeom/pointBased.h>
#include <pxr/usd/usdGeom/pointInstancer.h>
#include <pxr/usd/usdGeom/points.h>
#include <pxr/usd/usdGeom/primvar.h>
#include <pxr/usd/usdGeom/primvarsAPI.h>
#include <pxr/usd/usdGeom/scope.h>
#include <pxr/usd/usdGeom/sphere.h>
#include <pxr/usd/usdGeom/subset.h>
#include <pxr/usd/usdGeom/visibilityAPI.h>
#include <pxr/usd/usdGeom/xform.h>
#include <pxr/usd/usdGeom/xformCache.h>
#include <pxr/usd/usdGeom/xformCommonAPI.h>
#include <pxr/usd/usdGeom/xformOp.h>
#include <pxr/usd/usdGeom/xformable.h>

BBL_MODULE(usdGeom) {
    // clang-format off

    bbl::Class<PXR_NS::UsdGeomBasisCurves>("BasisCurves")
        .ctor(bbl::Class<PXR_NS::UsdGeomBasisCurves>::Ctor<PXR_NS::UsdPrim const&>(), "new")

        .m(&PXR_NS::UsdGeomBasisCurves::GetTypeAttr)
        .m(&PXR_NS::UsdGeomBasisCurves::CreateTypeAttr)
        .m(&PXR_NS::UsdGeomBasisCurves::GetBasisAttr)
        .m(&PXR_NS::UsdGeomBasisCurves::CreateBasisAttr)
        .m(&PXR_NS::UsdGeomBasisCurves::GetWrapAttr)
        .m(&PXR_NS::UsdGeomBasisCurves::CreateWrapAttr)
        ;

    bbl::Class<PXR_NS::UsdGeomBBoxCache>("BBoxCache")
        .ctor(bbl::Class<PXR_NS::UsdGeomBBoxCache>::Ctor<PXR_NS::UsdTimeCode, PXR_NS::TfTokenVector, bool, bool>("time", "includedPurposes", "useExtentsHint", "ignoreVisibility"))
        .m(&PXR_NS::UsdGeomBBoxCache::ComputeWorldBound)
        .m(&PXR_NS::UsdGeomBBoxCache::ComputeWorldBoundWithOverrides)
        .m(&PXR_NS::UsdGeomBBoxCache::ComputeRelativeBound)
        .m(&PXR_NS::UsdGeomBBoxCache::ComputeLocalBound)
        .m((PXR_NS::GfBBox3d (PXR_NS::UsdGeomBBoxCache::*)(PXR_NS::UsdPrim const&))
            &PXR_NS::UsdGeomBBoxCache::ComputeUntransformedBound)
        .m(&PXR_NS::UsdGeomBBoxCache::ComputePointInstanceWorldBound)
        .m(&PXR_NS::UsdGeomBBoxCache::ComputePointInstanceWorldBounds)
        .m(&PXR_NS::UsdGeomBBoxCache::ComputePointInstanceRelativeBounds)
        .m(&PXR_NS::UsdGeomBBoxCache::ComputePointInstanceRelativeBound)
        .m(&PXR_NS::UsdGeomBBoxCache::ComputePointInstanceLocalBounds)
        .m(&PXR_NS::UsdGeomBBoxCache::ComputePointInstanceLocalBound)
        .m(&PXR_NS::UsdGeomBBoxCache::ComputePointInstanceUntransformedBounds)
        .m(&PXR_NS::UsdGeomBBoxCache::ComputePointInstanceUntransformedBound)
        .m(&PXR_NS::UsdGeomBBoxCache::Clear)
        .m(&PXR_NS::UsdGeomBBoxCache::SetIncludedPurposes)
        .m(&PXR_NS::UsdGeomBBoxCache::GetIncludedPurposes)
        .m(&PXR_NS::UsdGeomBBoxCache::GetUseExtentsHint)
        .m(&PXR_NS::UsdGeomBBoxCache::GetIgnoreVisibility)
        .m(&PXR_NS::UsdGeomBBoxCache::SetTime)
        .m(&PXR_NS::UsdGeomBBoxCache::GetTime)
        .m(&PXR_NS::UsdGeomBBoxCache::SetBaseTime)
        .m(&PXR_NS::UsdGeomBBoxCache::GetBaseTime)
        .m(&PXR_NS::UsdGeomBBoxCache::ClearBaseTime)
        .m(&PXR_NS::UsdGeomBBoxCache::HasBaseTime)
    ;

    bbl::Class<PXR_NS::TfHashMap<PXR_NS::SdfPath, PXR_NS::GfMatrix4d, PXR_NS::SdfPath::Hash>>("PathMatrixHashMap")
    ;


    bbl::Class<PXR_NS::UsdGeomBoundable>("Boundable")
        .ctor(bbl::Class<PXR_NS::UsdGeomBoundable>::Ctor<PXR_NS::UsdPrim const&>(), "new")

        .m(&PXR_NS::UsdGeomBoundable::GetExtentAttr)
        .m(&PXR_NS::UsdGeomBoundable::CreateExtentAttr)
        // XXX: ComputeExtent

        ;

    bbl::Class<PXR_NS::UsdGeomCamera>("Camera")
        .ctor(bbl::Class<PXR_NS::UsdGeomCamera>::Ctor<PXR_NS::UsdPrim const&>(), "new")

        .m(&PXR_NS::UsdGeomCamera::GetProjectionAttr)
        .m(&PXR_NS::UsdGeomCamera::CreateProjectionAttr)
        .m(&PXR_NS::UsdGeomCamera::GetHorizontalApertureAttr)
        .m(&PXR_NS::UsdGeomCamera::CreateHorizontalApertureAttr)
        .m(&PXR_NS::UsdGeomCamera::GetVerticalApertureAttr)
        .m(&PXR_NS::UsdGeomCamera::CreateVerticalApertureAttr)
        .m(&PXR_NS::UsdGeomCamera::GetHorizontalApertureOffsetAttr)
        .m(&PXR_NS::UsdGeomCamera::CreateHorizontalApertureOffsetAttr)
        .m(&PXR_NS::UsdGeomCamera::GetVerticalApertureOffsetAttr)
        .m(&PXR_NS::UsdGeomCamera::CreateVerticalApertureOffsetAttr)
        .m(&PXR_NS::UsdGeomCamera::GetFocalLengthAttr)
        .m(&PXR_NS::UsdGeomCamera::CreateFocalLengthAttr)
        .m(&PXR_NS::UsdGeomCamera::GetClippingRangeAttr)
        .m(&PXR_NS::UsdGeomCamera::CreateClippingRangeAttr)
        .m(&PXR_NS::UsdGeomCamera::GetClippingPlanesAttr)
        .m(&PXR_NS::UsdGeomCamera::CreateClippingPlanesAttr)
        .m(&PXR_NS::UsdGeomCamera::GetFStopAttr)
        .m(&PXR_NS::UsdGeomCamera::CreateFStopAttr)
        .m(&PXR_NS::UsdGeomCamera::GetFocusDistanceAttr)
        .m(&PXR_NS::UsdGeomCamera::CreateFocusDistanceAttr)
        .m(&PXR_NS::UsdGeomCamera::GetStereoRoleAttr)
        .m(&PXR_NS::UsdGeomCamera::CreateStereoRoleAttr)
        .m(&PXR_NS::UsdGeomCamera::GetShutterOpenAttr)
        .m(&PXR_NS::UsdGeomCamera::CreateShutterOpenAttr)
        .m(&PXR_NS::UsdGeomCamera::GetShutterCloseAttr)
        .m(&PXR_NS::UsdGeomCamera::CreateShutterCloseAttr)
        .m(&PXR_NS::UsdGeomCamera::GetExposureAttr)
        .m(&PXR_NS::UsdGeomCamera::CreateExposureAttr)
        .m(&PXR_NS::UsdGeomCamera::GetCamera)
        .m(&PXR_NS::UsdGeomCamera::SetFromCamera)
        ;

    bbl::Class<PXR_NS::UsdGeomCapsule>("Capsule")
        .ctor(bbl::Class<PXR_NS::UsdGeomCapsule>::Ctor<PXR_NS::UsdPrim const&>(), "new")

        .m(&PXR_NS::UsdGeomCapsule::GetHeightAttr)
        .m(&PXR_NS::UsdGeomCapsule::CreateHeightAttr)
        .m(&PXR_NS::UsdGeomCapsule::GetRadiusAttr)
        .m(&PXR_NS::UsdGeomCapsule::CreateRadiusAttr)
        .m(&PXR_NS::UsdGeomCapsule::GetAxisAttr)
        .m(&PXR_NS::UsdGeomCapsule::CreateAxisAttr)
        ;

    bbl::Class<PXR_NS::UsdGeomCone>("Cone")
        .ctor(bbl::Class<PXR_NS::UsdGeomCone>::Ctor<PXR_NS::UsdPrim const&>(), "new")

        .m(&PXR_NS::UsdGeomCone::GetHeightAttr)
        .m(&PXR_NS::UsdGeomCone::CreateHeightAttr)
        .m(&PXR_NS::UsdGeomCone::GetRadiusAttr)
        .m(&PXR_NS::UsdGeomCone::CreateRadiusAttr)
        .m(&PXR_NS::UsdGeomCone::GetAxisAttr)
        .m(&PXR_NS::UsdGeomCone::CreateAxisAttr)
        ;

    bbl::Class<PXR_NS::UsdGeomConstraintTarget>("ConstraintTarget")
        .ctor(bbl::Class<PXR_NS::UsdGeomConstraintTarget>::Ctor<PXR_NS::UsdAttribute const&>(), "new")
        .m(&PXR_NS::UsdGeomConstraintTarget::IsValid)
        .m(&PXR_NS::UsdGeomConstraintTarget::GetAttr)
        .m(&PXR_NS::UsdGeomConstraintTarget::IsDefined)
        .m(&PXR_NS::UsdGeomConstraintTarget::Get)
        .m(&PXR_NS::UsdGeomConstraintTarget::Set)
        .m(&PXR_NS::UsdGeomConstraintTarget::GetIdentifier)
        .m(&PXR_NS::UsdGeomConstraintTarget::SetIdentifier)
        .m(&PXR_NS::UsdGeomConstraintTarget::ComputeInWorldSpace)
        .m(&PXR_NS::UsdGeomConstraintTarget::GetConstraintAttrName)
        ;

    bbl::Class<std::vector<PXR_NS::UsdGeomConstraintTarget>>("ConstraintTargetVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdGeomConstraintTarget)
        ;

    bbl::Class<PXR_NS::UsdGeomCube>("Cube")
        .ctor(bbl::Class<PXR_NS::UsdGeomCube>::Ctor<PXR_NS::UsdPrim const&>(), "new")

        .m(&PXR_NS::UsdGeomCube::GetSizeAttr)
        .m(&PXR_NS::UsdGeomCube::CreateSizeAttr)
        ;

    bbl::Class<PXR_NS::UsdGeomCurves>("Curves")
        .ctor(bbl::Class<PXR_NS::UsdGeomCurves>::Ctor<PXR_NS::UsdPrim const&>(), "new")
        .m(&PXR_NS::UsdGeomCurves::GetCurveVertexCountsAttr) 
        .m(&PXR_NS::UsdGeomCurves::CreateCurveVertexCountsAttr) 
        .m(&PXR_NS::UsdGeomCurves::GetWidthsAttr) 
        .m(&PXR_NS::UsdGeomCurves::CreateWidthsAttr) 
        .m(&PXR_NS::UsdGeomCurves::GetWidthsInterpolation) 
        .m(&PXR_NS::UsdGeomCurves::SetWidthsInterpolation) 
        .m(&PXR_NS::UsdGeomCurves::GetCurveCount)
        ;

    bbl::Class<PXR_NS::UsdGeomCylinder>("Cylinder")
        .ctor(bbl::Class<PXR_NS::UsdGeomCylinder>::Ctor<PXR_NS::UsdPrim const&>(), "new")
        .m(&PXR_NS::UsdGeomCylinder::GetHeightAttr)
        .m(&PXR_NS::UsdGeomCylinder::CreateHeightAttr)
        .m(&PXR_NS::UsdGeomCylinder::GetRadiusAttr)
        .m(&PXR_NS::UsdGeomCylinder::CreateRadiusAttr)
        .m(&PXR_NS::UsdGeomCylinder::GetAxisAttr)
        .m(&PXR_NS::UsdGeomCylinder::CreateAxisAttr)
        ;


    bbl::Class<PXR_NS::UsdGeomGprim>("Gprim")
        .ctor(bbl::Class<PXR_NS::UsdGeomGprim>::Ctor<PXR_NS::UsdPrim const&>(), "new")
        .m(&PXR_NS::UsdGeomGprim::GetDisplayColorAttr) 
        .m(&PXR_NS::UsdGeomGprim::CreateDisplayColorAttr) 
        .m(&PXR_NS::UsdGeomGprim::GetDisplayOpacityAttr) 
        .m(&PXR_NS::UsdGeomGprim::CreateDisplayOpacityAttr) 
        .m(&PXR_NS::UsdGeomGprim::GetDoubleSidedAttr) 
        .m(&PXR_NS::UsdGeomGprim::CreateDoubleSidedAttr) 
        .m(&PXR_NS::UsdGeomGprim::GetOrientationAttr) 
        .m(&PXR_NS::UsdGeomGprim::CreateOrientationAttr) 
        .m(&PXR_NS::UsdGeomGprim::GetDisplayColorPrimvar) 
        .m(&PXR_NS::UsdGeomGprim::CreateDisplayColorPrimvar)
        ;

    bbl::Class<PXR_NS::UsdGeomHermiteCurves>("HermiteCurves")
        .ctor(bbl::Class<PXR_NS::UsdGeomHermiteCurves>::Ctor<PXR_NS::UsdPrim const&>(), "new")
        .m(&PXR_NS::UsdGeomHermiteCurves::GetTangentsAttr)
        .m(&PXR_NS::UsdGeomHermiteCurves::CreateTangentsAttr)
        ;


    bbl::Class<PXR_NS::UsdGeomImageable>("Imageable")
        .ctor(bbl::Class<PXR_NS::UsdGeomImageable>::Ctor<PXR_NS::UsdPrim const&>(), "new")
        .m(&PXR_NS::UsdGeomImageable::GetVisibilityAttr) 
        .m(&PXR_NS::UsdGeomImageable::CreateVisibilityAttr) 
        .m(&PXR_NS::UsdGeomImageable::GetPurposeAttr) 
        .m(&PXR_NS::UsdGeomImageable::CreatePurposeAttr) 
        .m(&PXR_NS::UsdGeomImageable::GetProxyPrimRel) 
        .m(&PXR_NS::UsdGeomImageable::CreateProxyPrimRel) 
        .m(&PXR_NS::UsdGeomImageable::MakeVisible) 
        .m(&PXR_NS::UsdGeomImageable::MakeInvisible) 
        .m(&PXR_NS::UsdGeomImageable::ComputeVisibility) 
        .m(&PXR_NS::UsdGeomImageable::GetPurposeVisibilityAttr) 
        .m((PXR_NS::UsdGeomImageable::PurposeInfo (PXR_NS::UsdGeomImageable::*)() const) 
            &PXR_NS::UsdGeomImageable::ComputePurposeInfo) 
        .m((PXR_NS::UsdGeomImageable::PurposeInfo (PXR_NS::UsdGeomImageable::*)(PXR_NS::UsdGeomImageable::PurposeInfo const&) const) 
            &PXR_NS::UsdGeomImageable::ComputePurposeInfo, "ComputePurposeInfo_given_parent") 
        .m(&PXR_NS::UsdGeomImageable::ComputePurpose) 
        .m(&PXR_NS::UsdGeomImageable::ComputeProxyPrim) 
        .m((bool (PXR_NS::UsdGeomImageable::*)(PXR_NS::UsdPrim const&) const) 
            &PXR_NS::UsdGeomImageable::SetProxyPrim) 
        .m(&PXR_NS::UsdGeomImageable::ComputeWorldBound) 
        .m(&PXR_NS::UsdGeomImageable::ComputeLocalBound) 
        .m(&PXR_NS::UsdGeomImageable::ComputeUntransformedBound) 
        .m(&PXR_NS::UsdGeomImageable::ComputeLocalToWorldTransform) 
        .m(&PXR_NS::UsdGeomImageable::ComputeParentToWorldTransform)
        ;

    bbl::Class<PXR_NS::UsdGeomImageable::PurposeInfo>("ImageablePurposeInfo");

    bbl::Class<PXR_NS::UsdGeomMesh>("Mesh")
        .ctor(bbl::Class<PXR_NS::UsdGeomMesh>::Ctor<PXR_NS::UsdPrim const&>(), "new")
        .m(&PXR_NS::UsdGeomMesh::GetFaceVertexIndicesAttr)
        .m(&PXR_NS::UsdGeomMesh::CreateFaceVertexIndicesAttr)
        .m(&PXR_NS::UsdGeomMesh::GetFaceVertexCountsAttr)
        .m(&PXR_NS::UsdGeomMesh::CreateFaceVertexCountsAttr)
        .m(&PXR_NS::UsdGeomMesh::GetSubdivisionSchemeAttr)
        .m(&PXR_NS::UsdGeomMesh::CreateSubdivisionSchemeAttr)
        .m(&PXR_NS::UsdGeomMesh::GetInterpolateBoundaryAttr)
        .m(&PXR_NS::UsdGeomMesh::CreateInterpolateBoundaryAttr)
        .m(&PXR_NS::UsdGeomMesh::GetFaceVaryingLinearInterpolationAttr)
        .m(&PXR_NS::UsdGeomMesh::CreateFaceVaryingLinearInterpolationAttr)
        .m(&PXR_NS::UsdGeomMesh::GetTriangleSubdivisionRuleAttr)
        .m(&PXR_NS::UsdGeomMesh::CreateTriangleSubdivisionRuleAttr)
        .m(&PXR_NS::UsdGeomMesh::GetHoleIndicesAttr)
        .m(&PXR_NS::UsdGeomMesh::CreateHoleIndicesAttr)
        .m(&PXR_NS::UsdGeomMesh::GetCornerIndicesAttr)
        .m(&PXR_NS::UsdGeomMesh::CreateCornerIndicesAttr)
        .m(&PXR_NS::UsdGeomMesh::GetCornerSharpnessesAttr)
        .m(&PXR_NS::UsdGeomMesh::CreateCornerSharpnessesAttr)
        .m(&PXR_NS::UsdGeomMesh::GetCreaseIndicesAttr)
        .m(&PXR_NS::UsdGeomMesh::CreateCreaseIndicesAttr)
        .m(&PXR_NS::UsdGeomMesh::GetCreaseLengthsAttr)
        .m(&PXR_NS::UsdGeomMesh::CreateCreaseLengthsAttr)
        .m(&PXR_NS::UsdGeomMesh::GetCreaseSharpnessesAttr)
        .m(&PXR_NS::UsdGeomMesh::CreateCreaseSharpnessesAttr)
        .m(&PXR_NS::UsdGeomMesh::GetFaceCount)
        ;

    bbl::Class<PXR_NS::UsdGeomModelAPI>("ModelAPI")
        .ctor(bbl::Class<PXR_NS::UsdGeomModelAPI>::Ctor<PXR_NS::UsdPrim const&>(), "new")
        .m(&PXR_NS::UsdGeomModelAPI::GetModelDrawModeAttr)
        .m(&PXR_NS::UsdGeomModelAPI::CreateModelDrawModeAttr)
        .m(&PXR_NS::UsdGeomModelAPI::GetModelDrawModeColorAttr)
        .m(&PXR_NS::UsdGeomModelAPI::CreateModelDrawModeColorAttr)
        .m(&PXR_NS::UsdGeomModelAPI::GetModelCardGeometryAttr)
        .m(&PXR_NS::UsdGeomModelAPI::CreateModelCardGeometryAttr)
        .m(&PXR_NS::UsdGeomModelAPI::GetModelCardTextureXPosAttr)
        .m(&PXR_NS::UsdGeomModelAPI::CreateModelCardTextureXPosAttr)
        .m(&PXR_NS::UsdGeomModelAPI::GetModelCardTextureXNegAttr)
        .m(&PXR_NS::UsdGeomModelAPI::CreateModelCardTextureXNegAttr)
        .m(&PXR_NS::UsdGeomModelAPI::GetModelCardTextureYPosAttr)
        .m(&PXR_NS::UsdGeomModelAPI::CreateModelCardTextureYPosAttr)
        .m(&PXR_NS::UsdGeomModelAPI::GetModelCardTextureYNegAttr)
        .m(&PXR_NS::UsdGeomModelAPI::CreateModelCardTextureYNegAttr)
        .m(&PXR_NS::UsdGeomModelAPI::GetModelCardTextureZPosAttr)
        .m(&PXR_NS::UsdGeomModelAPI::CreateModelCardTextureZPosAttr)
        .m(&PXR_NS::UsdGeomModelAPI::GetModelCardTextureZNegAttr)
        .m(&PXR_NS::UsdGeomModelAPI::CreateModelCardTextureZNegAttr)
        .m(&PXR_NS::UsdGeomModelAPI::ComputeModelDrawMode)

        .m(&PXR_NS::UsdGeomModelAPI::GetExtentsHint)
        .m(&PXR_NS::UsdGeomModelAPI::SetExtentsHint)
        .m(&PXR_NS::UsdGeomModelAPI::GetExtentsHintAttr)
        .m(&PXR_NS::UsdGeomModelAPI::ComputeExtentsHint)

        .m(&PXR_NS::UsdGeomModelAPI::GetConstraintTarget)
        .m(&PXR_NS::UsdGeomModelAPI::GetConstraintTargets)
        .m(&PXR_NS::UsdGeomModelAPI::CreateConstraintTarget)
        ;

    bbl::Class<PXR_NS::UsdGeomMotionAPI>("MotionAPI")
        .ctor(bbl::Class<PXR_NS::UsdGeomMotionAPI>::Ctor<PXR_NS::UsdPrim const&>(), "new")
        .m(&PXR_NS::UsdGeomMotionAPI::GetMotionBlurScaleAttr)
        .m(&PXR_NS::UsdGeomMotionAPI::CreateMotionBlurScaleAttr)
        .m(&PXR_NS::UsdGeomMotionAPI::GetVelocityScaleAttr)
        .m(&PXR_NS::UsdGeomMotionAPI::CreateVelocityScaleAttr)
        .m(&PXR_NS::UsdGeomMotionAPI::GetNonlinearSampleCountAttr)
        .m(&PXR_NS::UsdGeomMotionAPI::CreateNonlinearSampleCountAttr)
        .m(&PXR_NS::UsdGeomMotionAPI::ComputeVelocityScale)
        .m(&PXR_NS::UsdGeomMotionAPI::ComputeMotionBlurScale)
        .m(&PXR_NS::UsdGeomMotionAPI::ComputeNonlinearSampleCount)
        ;

    bbl::Class<PXR_NS::UsdGeomNurbsCurves>("NurbsCurves")
        .ctor(bbl::Class<PXR_NS::UsdGeomNurbsCurves>::Ctor<PXR_NS::UsdPrim const&>(), "new")
        .m(&PXR_NS::UsdGeomNurbsCurves::GetOrderAttr)
        .m(&PXR_NS::UsdGeomNurbsCurves::CreateOrderAttr)
        .m(&PXR_NS::UsdGeomNurbsCurves::GetKnotsAttr)
        .m(&PXR_NS::UsdGeomNurbsCurves::CreateKnotsAttr)
        .m(&PXR_NS::UsdGeomNurbsCurves::GetRangesAttr)
        .m(&PXR_NS::UsdGeomNurbsCurves::CreateRangesAttr)
        .m(&PXR_NS::UsdGeomNurbsCurves::GetPointWeightsAttr)
        .m(&PXR_NS::UsdGeomNurbsCurves::CreatePointWeightsAttr)
        ;

    bbl::Class<PXR_NS::UsdGeomNurbsPatch>("NurbsPatch")
        .ctor(bbl::Class<PXR_NS::UsdGeomNurbsPatch>::Ctor<PXR_NS::UsdPrim const&>(), "new")
        .m(&PXR_NS::UsdGeomNurbsPatch::GetUVertexCountAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::CreateUVertexCountAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::GetVVertexCountAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::CreateVVertexCountAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::GetUOrderAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::CreateUOrderAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::GetVOrderAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::CreateVOrderAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::GetUKnotsAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::CreateUKnotsAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::GetVKnotsAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::CreateVKnotsAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::GetUFormAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::CreateUFormAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::GetVFormAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::CreateVFormAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::GetURangeAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::CreateURangeAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::GetVRangeAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::CreateVRangeAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::GetPointWeightsAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::CreatePointWeightsAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::GetTrimCurveCountsAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::CreateTrimCurveCountsAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::GetTrimCurveOrdersAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::CreateTrimCurveOrdersAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::GetTrimCurveVertexCountsAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::CreateTrimCurveVertexCountsAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::GetTrimCurveKnotsAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::CreateTrimCurveKnotsAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::GetTrimCurveRangesAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::CreateTrimCurveRangesAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::GetTrimCurvePointsAttr)
        .m(&PXR_NS::UsdGeomNurbsPatch::CreateTrimCurvePointsAttr)
        ;

    bbl::Class<PXR_NS::UsdGeomPlane>("Plane")
        .ctor(bbl::Class<PXR_NS::UsdGeomPlane>::Ctor<PXR_NS::UsdPrim const&>(), "new")
        .m(&PXR_NS::UsdGeomPlane::GetWidthAttr)
        .m(&PXR_NS::UsdGeomPlane::CreateWidthAttr)
        .m(&PXR_NS::UsdGeomPlane::GetLengthAttr)
        .m(&PXR_NS::UsdGeomPlane::CreateLengthAttr)
        .m(&PXR_NS::UsdGeomPlane::GetAxisAttr)
        .m(&PXR_NS::UsdGeomPlane::CreateAxisAttr)
        ;


    bbl::Class<PXR_NS::UsdGeomPointBased>("PointBased")
        .ctor(bbl::Class<PXR_NS::UsdGeomPointBased>::Ctor<PXR_NS::UsdPrim const&>(), "new")
        .m(&PXR_NS::UsdGeomPointBased::GetPointsAttr) 
        .m(&PXR_NS::UsdGeomPointBased::CreatePointsAttr) 
        .m(&PXR_NS::UsdGeomPointBased::GetVelocitiesAttr) 
        .m(&PXR_NS::UsdGeomPointBased::CreateVelocitiesAttr) 
        .m(&PXR_NS::UsdGeomPointBased::GetAccelerationsAttr) 
        .m(&PXR_NS::UsdGeomPointBased::CreateAccelerationsAttr) 
        .m(&PXR_NS::UsdGeomPointBased::GetNormalsAttr) 
        .m(&PXR_NS::UsdGeomPointBased::CreateNormalsAttr) 
        .m(&PXR_NS::UsdGeomPointBased::GetNormalsInterpolation) 
        .m(&PXR_NS::UsdGeomPointBased::SetNormalsInterpolation) 
        .m((bool (PXR_NS::UsdGeomPointBased::*)(PXR_NS::VtArray<PXR_NS::GfVec3f>*, PXR_NS::UsdTimeCode const, PXR_NS::UsdTimeCode const) const) 
            &PXR_NS::UsdGeomPointBased::ComputePointsAtTime)

        ;

    bbl::Class<PXR_NS::UsdGeomPointInstancer>("PointInstancer")
        .ctor(bbl::Class<PXR_NS::UsdGeomPointInstancer>::Ctor<PXR_NS::UsdPrim const&>(), "new")
        .m(&PXR_NS::UsdGeomPointInstancer::GetProtoIndicesAttr)
        .m(&PXR_NS::UsdGeomPointInstancer::CreateProtoIndicesAttr)
        .m(&PXR_NS::UsdGeomPointInstancer::GetIdsAttr)
        .m(&PXR_NS::UsdGeomPointInstancer::CreateIdsAttr)
        .m(&PXR_NS::UsdGeomPointInstancer::GetPositionsAttr)
        .m(&PXR_NS::UsdGeomPointInstancer::CreatePositionsAttr)
        .m(&PXR_NS::UsdGeomPointInstancer::CreateOrientationsAttr)
        .m(&PXR_NS::UsdGeomPointInstancer::GetOrientationsAttr)
        .m(&PXR_NS::UsdGeomPointInstancer::GetScalesAttr)
        .m(&PXR_NS::UsdGeomPointInstancer::CreateScalesAttr)
        .m(&PXR_NS::UsdGeomPointInstancer::GetVelocitiesAttr)
        .m(&PXR_NS::UsdGeomPointInstancer::CreateVelocitiesAttr)
        .m(&PXR_NS::UsdGeomPointInstancer::GetAccelerationsAttr)
        .m(&PXR_NS::UsdGeomPointInstancer::CreateAccelerationsAttr)
        .m(&PXR_NS::UsdGeomPointInstancer::GetAngularVelocitiesAttr)
        .m(&PXR_NS::UsdGeomPointInstancer::CreateAngularVelocitiesAttr)
        .m(&PXR_NS::UsdGeomPointInstancer::GetPrototypesRel)
        .m(&PXR_NS::UsdGeomPointInstancer::CreatePrototypesRel)
        .m((bool (PXR_NS::UsdGeomPointInstancer::*)(PXR_NS::VtMatrix4dArray*, PXR_NS::UsdTimeCode const, PXR_NS::UsdTimeCode const, PXR_NS::UsdGeomPointInstancer::ProtoXformInclusion const, PXR_NS::UsdGeomPointInstancer::MaskApplication) const)
            &PXR_NS::UsdGeomPointInstancer::ComputeInstanceTransformsAtTime)
        .m(&PXR_NS::UsdGeomPointInstancer::ComputeInstanceTransformsAtTimes)
        .m((bool (PXR_NS::UsdGeomPointInstancer::*)(PXR_NS::VtVec3fArray*, PXR_NS::UsdTimeCode const, PXR_NS::UsdTimeCode const) const)
            &PXR_NS::UsdGeomPointInstancer::ComputeExtentAtTime)
        .m((bool (PXR_NS::UsdGeomPointInstancer::*)(PXR_NS::VtVec3fArray*, PXR_NS::UsdTimeCode const, PXR_NS::UsdTimeCode const, PXR_NS::GfMatrix4d const&) const)
            &PXR_NS::UsdGeomPointInstancer::ComputeExtentAtTime, "ComputeExtentAtTime_with_transform")
        .m((bool (PXR_NS::UsdGeomPointInstancer::*)(std::vector<PXR_NS::VtVec3fArray>*, std::vector<PXR_NS::UsdTimeCode> const&, PXR_NS::UsdTimeCode const) const)
            &PXR_NS::UsdGeomPointInstancer::ComputeExtentAtTimes)
        .m((bool (PXR_NS::UsdGeomPointInstancer::*)(std::vector<PXR_NS::VtVec3fArray>*, std::vector<PXR_NS::UsdTimeCode> const&, PXR_NS::UsdTimeCode const, PXR_NS::GfMatrix4d const&) const)
            &PXR_NS::UsdGeomPointInstancer::ComputeExtentAtTimes, "ComputeExtentAtTimes_with_transform")
        .m(&PXR_NS::UsdGeomPointInstancer::GetInstanceCount)
        ;
    
    bbl::Enum<PXR_NS::UsdGeomPointInstancer::ProtoXformInclusion>("ProtoXformInclusion");
    bbl::Enum<PXR_NS::UsdGeomPointInstancer::MaskApplication>("MaskApplication");

    bbl::Class<PXR_NS::UsdGeomPoints>("Points")
        .ctor(bbl::Class<PXR_NS::UsdGeomPoints>::Ctor<PXR_NS::UsdPrim const&>(), "new")
        .m(&PXR_NS::UsdGeomPoints::GetWidthsAttr)
        .m(&PXR_NS::UsdGeomPoints::CreateWidthsAttr)
        .m(&PXR_NS::UsdGeomPoints::GetIdsAttr)
        .m(&PXR_NS::UsdGeomPoints::CreateIdsAttr)
        .m(&PXR_NS::UsdGeomPoints::GetWidthsInterpolation)
        .m(&PXR_NS::UsdGeomPoints::SetWidthsInterpolation)
        .m(&PXR_NS::UsdGeomPoints::GetPointCount)
        ;

    bbl::Class<PXR_NS::UsdGeomPrimvar>("Primvar")
        .ctor(bbl::Class<PXR_NS::UsdGeomPrimvar>::Ctor<PXR_NS::UsdAttribute const&>(), "new")
        .m(&PXR_NS::UsdGeomPrimvar::GetInterpolation)
        .m(&PXR_NS::UsdGeomPrimvar::SetInterpolation)
        .m(&PXR_NS::UsdGeomPrimvar::HasAuthoredInterpolation)
        .m(&PXR_NS::UsdGeomPrimvar::GetElementSize)
        .m(&PXR_NS::UsdGeomPrimvar::SetElementSize)
        .m(&PXR_NS::UsdGeomPrimvar::HasAuthoredElementSize)
        .m(&PXR_NS::UsdGeomPrimvar::GetDeclarationInfo)
        .m((bool (PXR_NS::UsdGeomPrimvar::*)(PXR_NS::VtValue*, PXR_NS::UsdTimeCode) const)
            &PXR_NS::UsdGeomPrimvar::Get)

        // attribute api
        .m(&PXR_NS::UsdGeomPrimvar::GetAttr)
        .m(&PXR_NS::UsdGeomPrimvar::IsDefined)
        .m(&PXR_NS::UsdGeomPrimvar::HasValue)
        .m(&PXR_NS::UsdGeomPrimvar::HasAuthoredValue)
        .m(&PXR_NS::UsdGeomPrimvar::GetPrimvarName)
        .m(&PXR_NS::UsdGeomPrimvar::GetName)
        .m(&PXR_NS::UsdGeomPrimvar::NameContainsNamespaces)
        .m(&PXR_NS::UsdGeomPrimvar::GetBaseName)
        .m(&PXR_NS::UsdGeomPrimvar::GetNamespace)
        .m(&PXR_NS::UsdGeomPrimvar::GetTypeName)
        .m(&PXR_NS::UsdGeomPrimvar::SplitName)
        .m(&PXR_NS::UsdGeomPrimvar::GetTimeSamples)
        .m(&PXR_NS::UsdGeomPrimvar::GetTimeSamplesInInterval)
        .m(&PXR_NS::UsdGeomPrimvar::ValueMightBeTimeVarying)

        // id api
        .m(&PXR_NS::UsdGeomPrimvar::IsIdTarget)
        .m(&PXR_NS::UsdGeomPrimvar::SetIdTarget)

        // static
        .m(&PXR_NS::UsdGeomPrimvar::IsPrimvar)
        .m(&PXR_NS::UsdGeomPrimvar::IsValidPrimvarName)
        .m(&PXR_NS::UsdGeomPrimvar::StripPrimvarsName)
        .m(&PXR_NS::UsdGeomPrimvar::IsValidInterpolation)
        ;

    bbl::Class<std::vector<PXR_NS::UsdGeomPrimvar>>("PrimvarVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdGeomPrimvar)
        ;
    

    bbl::Class<PXR_NS::UsdGeomPrimvarsAPI>("PrimvarsAPI")
        .ctor(bbl::Class<PXR_NS::UsdGeomPrimvarsAPI>::Ctor<PXR_NS::UsdPrim const&>(), "new")
        .m(&PXR_NS::UsdGeomPrimvarsAPI::CreatePrimvar)
        .m(&PXR_NS::UsdGeomPrimvarsAPI::RemovePrimvar)
        .m(&PXR_NS::UsdGeomPrimvarsAPI::BlockPrimvar)
        .m(&PXR_NS::UsdGeomPrimvarsAPI::GetPrimvar)
        .m(&PXR_NS::UsdGeomPrimvarsAPI::GetPrimvars)
        .m(&PXR_NS::UsdGeomPrimvarsAPI::GetAuthoredPrimvars)
        .m(&PXR_NS::UsdGeomPrimvarsAPI::GetPrimvarsWithValues)
        .m(&PXR_NS::UsdGeomPrimvarsAPI::GetPrimvarsWithAuthoredValues)
        .m(&PXR_NS::UsdGeomPrimvarsAPI::FindInheritablePrimvars)
        .m(&PXR_NS::UsdGeomPrimvarsAPI::FindIncrementallyInheritablePrimvars)
        .m((PXR_NS::UsdGeomPrimvar (PXR_NS::UsdGeomPrimvarsAPI::*)(PXR_NS::TfToken const&) const)
            &PXR_NS::UsdGeomPrimvarsAPI::FindPrimvarWithInheritance)
        .m((PXR_NS::UsdGeomPrimvar (PXR_NS::UsdGeomPrimvarsAPI::*)(PXR_NS::TfToken const&, std::vector<PXR_NS::UsdGeomPrimvar> const&) const)
            &PXR_NS::UsdGeomPrimvarsAPI::FindPrimvarWithInheritance, "FindPrimvarWIthInheritance_from")
        .m((std::vector<PXR_NS::UsdGeomPrimvar> (PXR_NS::UsdGeomPrimvarsAPI::*)() const)
            &PXR_NS::UsdGeomPrimvarsAPI::FindPrimvarsWithInheritance)
        .m((std::vector<PXR_NS::UsdGeomPrimvar> (PXR_NS::UsdGeomPrimvarsAPI::*)(std::vector<PXR_NS::UsdGeomPrimvar> const&) const)
            &PXR_NS::UsdGeomPrimvarsAPI::FindPrimvarsWithInheritance, "FindPrimvarsWIthInheritance_from")
        .m(&PXR_NS::UsdGeomPrimvarsAPI::HasPrimvar)
        .m(&PXR_NS::UsdGeomPrimvarsAPI::HasPossiblyInheritedPrimvar)

        // static
        .m(&PXR_NS::UsdGeomPrimvarsAPI::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdGeomPrimvarsAPI::Get)
        .m(&PXR_NS::UsdGeomPrimvarsAPI::CanContainPropertyName)
        ;

    bbl::Class<PXR_NS::UsdGeomScope>("Scope")
        .ctor(bbl::Class<PXR_NS::UsdGeomScope>::Ctor<PXR_NS::UsdPrim const&>(), "new")
        .m(&PXR_NS::UsdGeomScope::Get)
        .m(&PXR_NS::UsdGeomScope::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdGeomScope::Define)
        ;

    bbl::Class<PXR_NS::UsdGeomSphere>("Sphere")
        .ctor(bbl::Class<PXR_NS::UsdGeomSphere>::Ctor<PXR_NS::UsdPrim const&>(), "new")
        .m(&PXR_NS::UsdGeomSphere::GetRadiusAttr)
        .m(&PXR_NS::UsdGeomSphere::CreateRadiusAttr)
        ;

    bbl::Class<PXR_NS::UsdGeomSubset>("Subset")
        .ctor(bbl::Class<PXR_NS::UsdGeomSubset>::Ctor<PXR_NS::UsdPrim const&>(), "new")
        .m(&PXR_NS::UsdGeomSubset::GetElementTypeAttr)
        .m(&PXR_NS::UsdGeomSubset::CreateElementTypeAttr)
        .m(&PXR_NS::UsdGeomSubset::GetIndicesAttr)
        .m(&PXR_NS::UsdGeomSubset::CreateIndicesAttr)
        .m(&PXR_NS::UsdGeomSubset::GetFamilyNameAttr)
        .m(&PXR_NS::UsdGeomSubset::CreateFamilyNameAttr)

        // static
        .m(&PXR_NS::UsdGeomSubset::Get)
        .m(&PXR_NS::UsdGeomSubset::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdGeomSubset::Define)
        .m(&PXR_NS::UsdGeomSubset::CreateGeomSubset)
        .m(&PXR_NS::UsdGeomSubset::CreateUniqueGeomSubset)
        .m(&PXR_NS::UsdGeomSubset::GetAllGeomSubsets)
        .m(&PXR_NS::UsdGeomSubset::GetGeomSubsets)
        .m(&PXR_NS::UsdGeomSubset::SetFamilyType)
        .m(&PXR_NS::UsdGeomSubset::GetFamilyType)
        .m(&PXR_NS::UsdGeomSubset::GetUnassignedIndices)
        .m(&PXR_NS::UsdGeomSubset::ValidateSubsets)
        .m(&PXR_NS::UsdGeomSubset::ValidateFamily)
        ;

    bbl::Class<std::vector<PXR_NS::UsdGeomSubset>>("SubsetVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdGeomSubset)
        ;

    // XXX: figure out how to use UsdGeomTokensType


    bbl::Class<PXR_NS::UsdGeomVisibilityAPI>("VisibilityAPI")
        .ctor(bbl::Class<PXR_NS::UsdGeomVisibilityAPI>::Ctor<PXR_NS::UsdPrim const&>(), "new")
        .m(&PXR_NS::UsdGeomVisibilityAPI::GetGuideVisibilityAttr)
        .m(&PXR_NS::UsdGeomVisibilityAPI::CreateGuideVisibilityAttr)
        .m(&PXR_NS::UsdGeomVisibilityAPI::GetProxyVisibilityAttr)
        .m(&PXR_NS::UsdGeomVisibilityAPI::CreateProxyVisibilityAttr)
        .m(&PXR_NS::UsdGeomVisibilityAPI::GetRenderVisibilityAttr)
        .m(&PXR_NS::UsdGeomVisibilityAPI::CreateRenderVisibilityAttr)
        .m(&PXR_NS::UsdGeomVisibilityAPI::GetPurposeVisibilityAttr)

        // static
        .m(&PXR_NS::UsdGeomVisibilityAPI::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdGeomVisibilityAPI::Get)
        .m(&PXR_NS::UsdGeomVisibilityAPI::CanApply)
        .m(&PXR_NS::UsdGeomVisibilityAPI::Apply)
        ;


    bbl::Class<PXR_NS::UsdGeomXform>("Xform")
        .ctor(bbl::Class<PXR_NS::UsdGeomXform>::Ctor<>(), "new")
        .m(&PXR_NS::UsdGeomXform::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdGeomXform::Get)
        .m(&PXR_NS::UsdGeomXform::Define)
        ;

    bbl::Class<PXR_NS::UsdGeomXformCache>("XformCache")
        .ctor(bbl::Class<PXR_NS::UsdGeomXformCache>::Ctor<PXR_NS::UsdTimeCode>("time"), "new")
        .m(&PXR_NS::UsdGeomXformCache::GetLocalToWorldTransform)
        .m(&PXR_NS::UsdGeomXformCache::GetParentToWorldTransform)
        .m(&PXR_NS::UsdGeomXformCache::GetLocalTransformation)
        .m(&PXR_NS::UsdGeomXformCache::ComputeRelativeTransform)
        .m(&PXR_NS::UsdGeomXformCache::IsAttributeIncludedInLocalTransform)
        .m(&PXR_NS::UsdGeomXformCache::TransformMightBeTimeVarying)
        .m(&PXR_NS::UsdGeomXformCache::GetResetXformStack)
        .m(&PXR_NS::UsdGeomXformCache::Clear)
        .m(&PXR_NS::UsdGeomXformCache::GetTime)
        .m(&PXR_NS::UsdGeomXformCache::SetTime)
        .m(&PXR_NS::UsdGeomXformCache::Swap)
        ;

    bbl::Class<PXR_NS::UsdGeomXformCommonAPI>("XformCommonAPI")
        .ctor(bbl::Class<PXR_NS::UsdGeomXformCommonAPI>::Ctor<PXR_NS::UsdPrim const&>(), "new")
        .m(&PXR_NS::UsdGeomXformCommonAPI::SetXformVectors)
        .m(&PXR_NS::UsdGeomXformCommonAPI::GetXformVectors)
        .m(&PXR_NS::UsdGeomXformCommonAPI::GetXformVectorsByAccumulation)
        .m(&PXR_NS::UsdGeomXformCommonAPI::GetResetXformStack)
        .m(&PXR_NS::UsdGeomXformCommonAPI::SetResetXformStack)
        .m(&PXR_NS::UsdGeomXformCommonAPI::SetTranslate)
        .m(&PXR_NS::UsdGeomXformCommonAPI::SetPivot)
        .m(&PXR_NS::UsdGeomXformCommonAPI::SetRotate)
        .m(&PXR_NS::UsdGeomXformCommonAPI::SetScale)
        .m((PXR_NS::UsdGeomXformCommonAPI::Ops (PXR_NS::UsdGeomXformCommonAPI::*)(PXR_NS::UsdGeomXformCommonAPI::RotationOrder, PXR_NS::UsdGeomXformCommonAPI::OpFlags, PXR_NS::UsdGeomXformCommonAPI::OpFlags, PXR_NS::UsdGeomXformCommonAPI::OpFlags, PXR_NS::UsdGeomXformCommonAPI::OpFlags) const)
            &PXR_NS::UsdGeomXformCommonAPI::CreateXformOps, "CreateXformOps_with_rotation_order")
        .m((PXR_NS::UsdGeomXformCommonAPI::Ops (PXR_NS::UsdGeomXformCommonAPI::*)(PXR_NS::UsdGeomXformCommonAPI::OpFlags, PXR_NS::UsdGeomXformCommonAPI::OpFlags, PXR_NS::UsdGeomXformCommonAPI::OpFlags, PXR_NS::UsdGeomXformCommonAPI::OpFlags) const)
            &PXR_NS::UsdGeomXformCommonAPI::CreateXformOps)

        // static
        .m(&PXR_NS::UsdGeomXformCommonAPI::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdGeomXformCommonAPI::Get)
        .m(&PXR_NS::UsdGeomXformCommonAPI::ConvertRotationOrderToOpType)
        .m(&PXR_NS::UsdGeomXformCommonAPI::ConvertOpTypeToRotationOrder)
        .m(&PXR_NS::UsdGeomXformCommonAPI::CanConvertOpTypeToRotationOrder)
        .m(&PXR_NS::UsdGeomXformCommonAPI::GetRotationTransform)
        ;

    bbl::Class<PXR_NS::UsdGeomXformCommonAPI::Ops>("XformCommonAPIOps");
    bbl::Enum<PXR_NS::UsdGeomXformCommonAPI::RotationOrder>("XformCommonAPIRotationOrder");
    bbl::Enum<PXR_NS::UsdGeomXformCommonAPI::OpFlags>("XformCommonAPIOpFlags");


    bbl::Class<PXR_NS::UsdGeomXformable>("Xformable")
        .ctor(bbl::Class<PXR_NS::UsdGeomXformable>::Ctor<PXR_NS::UsdPrim const&>(),"new")
        .m(&PXR_NS::UsdGeomXformable::GetXformOpOrderAttr)
        .m(&PXR_NS::UsdGeomXformable::AddXformOp)
        .m(&PXR_NS::UsdGeomXformable::GetXformOp)
        .m(&PXR_NS::UsdGeomXformable::AddTranslateOp)
        .m(&PXR_NS::UsdGeomXformable::AddScaleOp)
        .m(&PXR_NS::UsdGeomXformable::AddRotateXOp)
        .m(&PXR_NS::UsdGeomXformable::AddRotateYOp)
        .m(&PXR_NS::UsdGeomXformable::AddRotateZOp)
        .m(&PXR_NS::UsdGeomXformable::AddRotateXYZOp)
        .m(&PXR_NS::UsdGeomXformable::AddRotateXZYOp)
        .m(&PXR_NS::UsdGeomXformable::AddRotateYXZOp)
        .m(&PXR_NS::UsdGeomXformable::AddRotateYZXOp)
        .m(&PXR_NS::UsdGeomXformable::AddRotateZXYOp)
        .m(&PXR_NS::UsdGeomXformable::AddRotateZYXOp)
        .m(&PXR_NS::UsdGeomXformable::AddOrientOp)
        .m(&PXR_NS::UsdGeomXformable::AddTransformOp)
        .m(&PXR_NS::UsdGeomXformable::SetResetXformStack)
        .m(&PXR_NS::UsdGeomXformable::SetXformOpOrder)
        .m(&PXR_NS::UsdGeomXformable::GetOrderedXformOps)
        .m(&PXR_NS::UsdGeomXformable::ClearXformOpOrder)
        .m(&PXR_NS::UsdGeomXformable::MakeMatrixXform)
        .m((bool (PXR_NS::UsdGeomXformable::*)() const)
            &PXR_NS::UsdGeomXformable::TransformMightBeTimeVarying)
        .m((bool (PXR_NS::UsdGeomXformable::*)(std::vector<PXR_NS::UsdGeomXformOp> const&) const)
            &PXR_NS::UsdGeomXformable::TransformMightBeTimeVarying, "TransformMightBeTimeVarying_using")
        .m((bool (PXR_NS::UsdGeomXformable::*)(std::vector<double>*) const)
            &PXR_NS::UsdGeomXformable::GetTimeSamples)
        .m((bool (PXR_NS::UsdGeomXformable::*)(PXR_NS::GfInterval const&, std::vector<double>*) const)
            &PXR_NS::UsdGeomXformable::GetTimeSamplesInInterval)
        .m((bool (PXR_NS::UsdGeomXformable::*)(PXR_NS::GfMatrix4d*, bool*, PXR_NS::UsdTimeCode const) const)
            &PXR_NS::UsdGeomXformable::GetLocalTransformation)
        .m((bool (PXR_NS::UsdGeomXformable::*)(PXR_NS::GfMatrix4d*, bool*, std::vector<PXR_NS::UsdGeomXformOp> const&, PXR_NS::UsdTimeCode const) const)
            &PXR_NS::UsdGeomXformable::GetLocalTransformation, "GetLocalTransformation_with_ops")
        ;

    bbl::Class<PXR_NS::UsdGeomXformOp>("XformOp")
        .ctor(bbl::Class<PXR_NS::UsdGeomXformOp>::Ctor<PXR_NS::UsdAttribute const&, bool>("attr", "isInverseOp"), "new")
        .m((bool (PXR_NS::UsdGeomXformOp::*)(const PXR_NS::VtValue&, PXR_NS::UsdTimeCode) const)
            &PXR_NS::UsdGeomXformOp::Set)
        .m(&PXR_NS::UsdGeomXformOp::GetOpType)
        .m(&PXR_NS::UsdGeomXformOp::GetPrecision)
        .m(&PXR_NS::UsdGeomXformOp::IsInverseOp)
        .m((PXR_NS::TfToken (PXR_NS::UsdGeomXformOp::*)() const)
            &PXR_NS::UsdGeomXformOp::GetOpName)
        .m(&PXR_NS::UsdGeomXformOp::HasSuffix)

        // attribute api
        .m(&PXR_NS::UsdGeomXformOp::GetAttr)
        .m(&PXR_NS::UsdGeomXformOp::IsDefined)
        .m(&PXR_NS::UsdGeomXformOp::GetName)
        .m(&PXR_NS::UsdGeomXformOp::GetBaseName)
        .m(&PXR_NS::UsdGeomXformOp::GetNamespace)
        .m(&PXR_NS::UsdGeomXformOp::SplitName)
        .m(&PXR_NS::UsdGeomXformOp::GetTypeName)
        .m(&PXR_NS::UsdGeomXformOp::GetTimeSamples)
        .m(&PXR_NS::UsdGeomXformOp::GetTimeSamplesInInterval)
        .m(&PXR_NS::UsdGeomXformOp::GetNumTimeSamples)
        .m((PXR_NS::GfMatrix4d (PXR_NS::UsdGeomXformOp::*)(PXR_NS::UsdTimeCode) const)
            &PXR_NS::UsdGeomXformOp::GetOpTransform)
        .m(&PXR_NS::UsdGeomXformOp::MightBeTimeVarying)
    ;

    bbl::Enum<PXR_NS::UsdGeomXformOp::Type>("XformOpType");
    bbl::Enum<PXR_NS::UsdGeomXformOp::Precision>("XformOpPrecision");

    bbl::Class<std::vector<PXR_NS::UsdGeomXformOp>>("XformOpVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdGeomXformOp)
        ;
}

#endif
