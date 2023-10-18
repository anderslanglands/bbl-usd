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

    #define APISCHEMABASE_METHODS(CLS) \
        .m(&CLS::IsConcrete) \
        .m(&CLS::IsTyped) \
        .m(&CLS::IsAPISchema) \
        .m(&CLS::IsAppliedAPISchema) \
        .m(&CLS::IsMultipleApplyAPISchema) \
        .m(&CLS::GetSchemaKind) \
        .m(&CLS::GetPrim) \
        .m(&CLS::GetPath) \
        .m(&CLS::GetSchemaClassPrimDefinition)

    #define IMAGEABLE_METHODS(CLS) \
        .m(&CLS::GetVisibilityAttr) \
        .m(&CLS::CreateVisibilityAttr) \
        .m(&CLS::GetPurposeAttr) \
        .m(&CLS::CreatePurposeAttr) \
        .m(&CLS::GetProxyPrimRel) \
        .m(&CLS::CreateProxyPrimRel) \
        .m(&CLS::MakeVisible) \
        .m(&CLS::MakeInvisible) \
        .m(&CLS::ComputeVisibility) \
        .m(&CLS::GetPurposeVisibilityAttr) \
        .m((PXR_NS::UsdGeomImageable::PurposeInfo (PXR_NS::UsdGeomImageable::*)() const) \
            &CLS::ComputePurposeInfo) \
        .m((PXR_NS::UsdGeomImageable::PurposeInfo (PXR_NS::UsdGeomImageable::*)(PXR_NS::UsdGeomImageable::PurposeInfo const&) const) \
            &CLS::ComputePurposeInfo, "ComputePurposeInfo_given_parent") \
        .m(&CLS::ComputePurpose) \
        .m(&CLS::ComputeProxyPrim) \
        .m((bool (PXR_NS::UsdGeomImageable::*)(PXR_NS::UsdPrim const&) const) \
            &CLS::SetProxyPrim) \
        .m(&CLS::ComputeWorldBound) \
        .m(&CLS::ComputeLocalBound) \
        .m(&CLS::ComputeUntransformedBound) \
        .m(&CLS::ComputeLocalToWorldTransform) \
        .m(&CLS::ComputeParentToWorldTransform)

    #define BOUNDABLE_METHODS(CLS)\
        .m(&CLS::GetExtentAttr) \
        .m(&CLS::CreateExtentAttr)
        // XXX: ComputeExtent

    #define GPRIM_METHODS(CLS) \
        .m(&CLS::GetDisplayColorAttr) \
        .m(&CLS::CreateDisplayColorAttr) \
        .m(&CLS::GetDisplayOpacityAttr) \
        .m(&CLS::CreateDisplayOpacityAttr) \
        .m(&CLS::GetDoubleSidedAttr) \
        .m(&CLS::CreateDoubleSidedAttr) \
        .m(&CLS::GetOrientationAttr) \
        .m(&CLS::CreateOrientationAttr) \
        .m(&CLS::GetDisplayColorPrimvar) \
        .m(&CLS::CreateDisplayColorPrimvar)
 
    #define POINTBASED_METHODS(CLS) \
        .m(&CLS::GetPointsAttr) \
        .m(&CLS::CreatePointsAttr) \
        .m(&CLS::GetVelocitiesAttr) \
        .m(&CLS::CreateVelocitiesAttr) \
        .m(&CLS::GetAccelerationsAttr) \
        .m(&CLS::CreateAccelerationsAttr) \
        .m(&CLS::GetNormalsAttr) \
        .m(&CLS::CreateNormalsAttr) \
        .m(&CLS::GetNormalsInterpolation) \
        .m(&CLS::SetNormalsInterpolation) \
        .m((bool (PXR_NS::UsdGeomPointBased::*)(PXR_NS::VtArray<PXR_NS::GfVec3f>*, PXR_NS::UsdTimeCode const, PXR_NS::UsdTimeCode const) const) \
            &CLS::ComputePointsAtTime)

    #define CURVES_METHODS(CLS) \
        .m(&CLS::GetCurveVertexCountsAttr) \
        .m(&CLS::CreateCurveVertexCountsAttr) \
        .m(&CLS::GetWidthsAttr) \
        .m(&CLS::CreateWidthsAttr) \
        .m(&CLS::GetWidthsInterpolation) \
        .m(&CLS::SetWidthsInterpolation) \
        .m(&CLS::GetCurveCount)

    #define XFORMABLE_METHODS(CLS) \
        .m(&CLS::GetXformOpOrderAttr) \
        .m(&CLS::AddXformOp) \
        .m(&CLS::AddTranslateOp) \
        .m(&CLS::AddScaleOp) \
        .m(&CLS::AddRotateXOp) \
        .m(&CLS::AddRotateYOp) \
        .m(&CLS::AddRotateZOp) \
        .m(&CLS::AddRotateXYZOp) \
        .m(&CLS::AddRotateXZYOp) \
        .m(&CLS::AddRotateYXZOp) \
        .m(&CLS::AddRotateYZXOp) \
        .m(&CLS::AddRotateZXYOp) \
        .m(&CLS::AddRotateZYXOp) \
        .m(&CLS::AddOrientOp) \
        .m(&CLS::AddTransformOp) \
        .m(&CLS::SetResetXformStack) \
        .m(&CLS::SetXformOpOrder) \
        .m(&CLS::GetOrderedXformOps) \
        .m(&CLS::ClearXformOpOrder) \
        .m(&CLS::MakeMatrixXform) \
        .m((bool (PXR_NS::UsdGeomXformable::*)() const) \
            &CLS::TransformMightBeTimeVarying) \
        .m((bool (PXR_NS::UsdGeomXformable::*)(std::vector<PXR_NS::UsdGeomXformOp> const&) const) \
            &CLS::TransformMightBeTimeVarying, "TransformMightBeTimeVarying_using") \
        .m((bool (PXR_NS::UsdGeomXformable::*)(std::vector<double>*) const) \
            &CLS::GetTimeSamples) \
        .m((bool (PXR_NS::UsdGeomXformable::*)(PXR_NS::GfInterval const&, std::vector<double>*) const) \
            &CLS::GetTimeSamplesInInterval) \
        .m((bool (PXR_NS::UsdGeomXformable::*)(PXR_NS::GfMatrix4d*, bool*, PXR_NS::UsdTimeCode const) const) \
            &CLS::GetLocalTransformation) \
        .m((bool (PXR_NS::UsdGeomXformable::*)(PXR_NS::GfMatrix4d*, bool*, std::vector<PXR_NS::UsdGeomXformOp> const&, PXR_NS::UsdTimeCode const) const) \
            &CLS::GetLocalTransformation, "GetLocalTransformation_with_ops")

    bbl::Class<PXR_NS::UsdGeomBasisCurves>("BasisCurves")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomBasisCurves, PXR_NS::UsdPrim const&>(), "new")

        .m(&PXR_NS::UsdGeomBasisCurves::GetTypeAttr)
        .m(&PXR_NS::UsdGeomBasisCurves::CreateTypeAttr)
        .m(&PXR_NS::UsdGeomBasisCurves::GetBasisAttr)
        .m(&PXR_NS::UsdGeomBasisCurves::CreateBasisAttr)
        .m(&PXR_NS::UsdGeomBasisCurves::GetWrapAttr)
        .m(&PXR_NS::UsdGeomBasisCurves::CreateWrapAttr)

        CURVES_METHODS(PXR_NS::UsdGeomBasisCurves)
        POINTBASED_METHODS(PXR_NS::UsdGeomBasisCurves)
        GPRIM_METHODS(PXR_NS::UsdGeomBasisCurves)
        BOUNDABLE_METHODS(PXR_NS::UsdGeomBasisCurves)
        XFORMABLE_METHODS(PXR_NS::UsdGeomBasisCurves)
        IMAGEABLE_METHODS(PXR_NS::UsdGeomBasisCurves)
        APISCHEMABASE_METHODS(PXR_NS::UsdGeomBasisCurves)
        ;

    bbl::Class<PXR_NS::UsdGeomBBoxCache>("BBoxCache")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomBBoxCache, PXR_NS::UsdTimeCode, PXR_NS::TfTokenVector, bool, bool>("time", "includedPurposes", "useExtentsHint", "ignoreVisibility"))
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

    bbl::Class<PXR_NS::TfHashMap<PXR_NS::SdfPath, PXR_NS::GfMatrix4d>>("PathMatrixHashMap");


    bbl::Class<PXR_NS::UsdGeomBoundable>("Boundable")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomBoundable, PXR_NS::UsdPrim const&>(), "new")

        BOUNDABLE_METHODS(PXR_NS::UsdGeomBoundable)
        XFORMABLE_METHODS(PXR_NS::UsdGeomBoundable)
        IMAGEABLE_METHODS(PXR_NS::UsdGeomBoundable)
        APISCHEMABASE_METHODS(PXR_NS::UsdGeomBoundable)
        ;

    bbl::Class<PXR_NS::UsdGeomCamera>("Camera")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomCamera, PXR_NS::UsdPrim const&>(), "new")

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

        XFORMABLE_METHODS(PXR_NS::UsdGeomCamera)
        IMAGEABLE_METHODS(PXR_NS::UsdGeomCamera)
        APISCHEMABASE_METHODS(PXR_NS::UsdGeomCamera)
        ;

    bbl::Class<PXR_NS::UsdGeomCapsule>("Capsule")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomCapsule, PXR_NS::UsdPrim const&>(), "new")

        .m(&PXR_NS::UsdGeomCapsule::GetHeightAttr)
        .m(&PXR_NS::UsdGeomCapsule::CreateHeightAttr)
        .m(&PXR_NS::UsdGeomCapsule::GetRadiusAttr)
        .m(&PXR_NS::UsdGeomCapsule::CreateRadiusAttr)
        .m(&PXR_NS::UsdGeomCapsule::GetAxisAttr)
        .m(&PXR_NS::UsdGeomCapsule::CreateAxisAttr)

        GPRIM_METHODS(PXR_NS::UsdGeomCapsule)
        BOUNDABLE_METHODS(PXR_NS::UsdGeomCapsule)
        XFORMABLE_METHODS(PXR_NS::UsdGeomCapsule)
        IMAGEABLE_METHODS(PXR_NS::UsdGeomCapsule)
        APISCHEMABASE_METHODS(PXR_NS::UsdGeomCapsule)
        ;

    bbl::Class<PXR_NS::UsdGeomCone>("Cone")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomCone, PXR_NS::UsdPrim const&>(), "new")

        .m(&PXR_NS::UsdGeomCone::GetHeightAttr)
        .m(&PXR_NS::UsdGeomCone::CreateHeightAttr)
        .m(&PXR_NS::UsdGeomCone::GetRadiusAttr)
        .m(&PXR_NS::UsdGeomCone::CreateRadiusAttr)
        .m(&PXR_NS::UsdGeomCone::GetAxisAttr)
        .m(&PXR_NS::UsdGeomCone::CreateAxisAttr)

        GPRIM_METHODS(PXR_NS::UsdGeomCone)
        BOUNDABLE_METHODS(PXR_NS::UsdGeomCone)
        XFORMABLE_METHODS(PXR_NS::UsdGeomCone)
        IMAGEABLE_METHODS(PXR_NS::UsdGeomCone)
        APISCHEMABASE_METHODS(PXR_NS::UsdGeomCone)
        ;

    bbl::Class<PXR_NS::UsdGeomConstraintTarget>("ConstraintTarget")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomConstraintTarget, PXR_NS::UsdAttribute const&>(), "new")
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
        .ctor(bbl::Ctor<PXR_NS::UsdGeomCube, PXR_NS::UsdPrim const&>(), "new")

        .m(&PXR_NS::UsdGeomCube::GetSizeAttr)
        .m(&PXR_NS::UsdGeomCube::CreateSizeAttr)

        GPRIM_METHODS(PXR_NS::UsdGeomCube)
        BOUNDABLE_METHODS(PXR_NS::UsdGeomCube)
        XFORMABLE_METHODS(PXR_NS::UsdGeomCube)
        IMAGEABLE_METHODS(PXR_NS::UsdGeomCube)
        APISCHEMABASE_METHODS(PXR_NS::UsdGeomCube)
        ;

    bbl::Class<PXR_NS::UsdGeomCurves>("Curves")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomCurves, PXR_NS::UsdPrim const&>(), "new")

        CURVES_METHODS(PXR_NS::UsdGeomCurves)
        POINTBASED_METHODS(PXR_NS::UsdGeomCurves)
        GPRIM_METHODS(PXR_NS::UsdGeomCurves)
        BOUNDABLE_METHODS(PXR_NS::UsdGeomCurves)
        XFORMABLE_METHODS(PXR_NS::UsdGeomCurves)
        IMAGEABLE_METHODS(PXR_NS::UsdGeomCurves)
        APISCHEMABASE_METHODS(PXR_NS::UsdGeomCurves)
        ;

    bbl::Class<PXR_NS::UsdGeomCylinder>("Cylinder")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomCylinder, PXR_NS::UsdPrim const&>(), "new")

        .m(&PXR_NS::UsdGeomCylinder::GetHeightAttr)
        .m(&PXR_NS::UsdGeomCylinder::CreateHeightAttr)
        .m(&PXR_NS::UsdGeomCylinder::GetRadiusAttr)
        .m(&PXR_NS::UsdGeomCylinder::CreateRadiusAttr)
        .m(&PXR_NS::UsdGeomCylinder::GetAxisAttr)
        .m(&PXR_NS::UsdGeomCylinder::CreateAxisAttr)

        GPRIM_METHODS(PXR_NS::UsdGeomCylinder)
        BOUNDABLE_METHODS(PXR_NS::UsdGeomCylinder)
        XFORMABLE_METHODS(PXR_NS::UsdGeomCylinder)
        IMAGEABLE_METHODS(PXR_NS::UsdGeomCylinder)
        APISCHEMABASE_METHODS(PXR_NS::UsdGeomCylinder)
        ;


    bbl::Class<PXR_NS::UsdGeomGprim>("Gprim")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomGprim, PXR_NS::UsdPrim const&>(), "new")

        GPRIM_METHODS(PXR_NS::UsdGeomGprim)
        BOUNDABLE_METHODS(PXR_NS::UsdGeomGprim)
        XFORMABLE_METHODS(PXR_NS::UsdGeomGprim)
        IMAGEABLE_METHODS(PXR_NS::UsdGeomGprim)
        APISCHEMABASE_METHODS(PXR_NS::UsdGeomGprim)
        ;

    bbl::Class<PXR_NS::UsdGeomHermiteCurves>("HermiteCurves")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomHermiteCurves, PXR_NS::UsdPrim const&>(), "new")

        .m(&PXR_NS::UsdGeomHermiteCurves::GetTangentsAttr)
        .m(&PXR_NS::UsdGeomHermiteCurves::CreateTangentsAttr)

        CURVES_METHODS(PXR_NS::UsdGeomHermiteCurves)
        POINTBASED_METHODS(PXR_NS::UsdGeomHermiteCurves)
        GPRIM_METHODS(PXR_NS::UsdGeomHermiteCurves)
        BOUNDABLE_METHODS(PXR_NS::UsdGeomHermiteCurves)
        XFORMABLE_METHODS(PXR_NS::UsdGeomHermiteCurves)
        IMAGEABLE_METHODS(PXR_NS::UsdGeomHermiteCurves)
        APISCHEMABASE_METHODS(PXR_NS::UsdGeomHermiteCurves)
        ;


    bbl::Class<PXR_NS::UsdGeomImageable>("Imageable")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomImageable, PXR_NS::UsdPrim const&>(), "new")

        IMAGEABLE_METHODS(PXR_NS::UsdGeomImageable)
        APISCHEMABASE_METHODS(PXR_NS::UsdGeomImageable)
        ;

    bbl::Class<PXR_NS::UsdGeomImageable::PurposeInfo>("ImageablePurposeInfo");

    bbl::Class<PXR_NS::UsdGeomMesh>("Mesh")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomMesh, PXR_NS::UsdPrim const&>(), "new")

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

        POINTBASED_METHODS(PXR_NS::UsdGeomMesh)
        GPRIM_METHODS(PXR_NS::UsdGeomMesh)
        BOUNDABLE_METHODS(PXR_NS::UsdGeomMesh)
        XFORMABLE_METHODS(PXR_NS::UsdGeomMesh)
        IMAGEABLE_METHODS(PXR_NS::UsdGeomMesh)
        APISCHEMABASE_METHODS(PXR_NS::UsdGeomMesh)
        ;

    bbl::Class<PXR_NS::UsdGeomModelAPI>("ModelAPI")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomModelAPI, PXR_NS::UsdPrim const&>(), "new")

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

        APISCHEMABASE_METHODS(PXR_NS::UsdGeomModelAPI)
        ;

    bbl::Class<PXR_NS::UsdGeomMotionAPI>("MotionAPI")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomMotionAPI, PXR_NS::UsdPrim const&>(), "new")

        .m(&PXR_NS::UsdGeomMotionAPI::GetMotionBlurScaleAttr)
        .m(&PXR_NS::UsdGeomMotionAPI::CreateMotionBlurScaleAttr)
        .m(&PXR_NS::UsdGeomMotionAPI::GetVelocityScaleAttr)
        .m(&PXR_NS::UsdGeomMotionAPI::CreateVelocityScaleAttr)
        .m(&PXR_NS::UsdGeomMotionAPI::GetNonlinearSampleCountAttr)
        .m(&PXR_NS::UsdGeomMotionAPI::CreateNonlinearSampleCountAttr)
        .m(&PXR_NS::UsdGeomMotionAPI::ComputeVelocityScale)
        .m(&PXR_NS::UsdGeomMotionAPI::ComputeMotionBlurScale)
        .m(&PXR_NS::UsdGeomMotionAPI::ComputeNonlinearSampleCount)

        APISCHEMABASE_METHODS(PXR_NS::UsdGeomMotionAPI)
        ;

    bbl::Class<PXR_NS::UsdGeomNurbsCurves>("NurbsCurves")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomNurbsCurves, PXR_NS::UsdPrim const&>(), "new")

        .m(&PXR_NS::UsdGeomNurbsCurves::GetOrderAttr)
        .m(&PXR_NS::UsdGeomNurbsCurves::CreateOrderAttr)
        .m(&PXR_NS::UsdGeomNurbsCurves::GetKnotsAttr)
        .m(&PXR_NS::UsdGeomNurbsCurves::CreateKnotsAttr)
        .m(&PXR_NS::UsdGeomNurbsCurves::GetRangesAttr)
        .m(&PXR_NS::UsdGeomNurbsCurves::CreateRangesAttr)
        .m(&PXR_NS::UsdGeomNurbsCurves::GetPointWeightsAttr)
        .m(&PXR_NS::UsdGeomNurbsCurves::CreatePointWeightsAttr)

        CURVES_METHODS(PXR_NS::UsdGeomNurbsCurves)
        POINTBASED_METHODS(PXR_NS::UsdGeomNurbsCurves)
        GPRIM_METHODS(PXR_NS::UsdGeomNurbsCurves)
        BOUNDABLE_METHODS(PXR_NS::UsdGeomNurbsCurves)
        XFORMABLE_METHODS(PXR_NS::UsdGeomNurbsCurves)
        IMAGEABLE_METHODS(PXR_NS::UsdGeomNurbsCurves)
        APISCHEMABASE_METHODS(PXR_NS::UsdGeomNurbsCurves)
        ;

    bbl::Class<PXR_NS::UsdGeomNurbsPatch>("NurbsPatch")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomNurbsPatch, PXR_NS::UsdPrim const&>(), "new")

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

        POINTBASED_METHODS(PXR_NS::UsdGeomNurbsPatch)
        GPRIM_METHODS(PXR_NS::UsdGeomNurbsPatch)
        BOUNDABLE_METHODS(PXR_NS::UsdGeomNurbsPatch)
        XFORMABLE_METHODS(PXR_NS::UsdGeomNurbsPatch)
        IMAGEABLE_METHODS(PXR_NS::UsdGeomNurbsPatch)
        APISCHEMABASE_METHODS(PXR_NS::UsdGeomNurbsPatch)
        ;

    bbl::Class<PXR_NS::UsdGeomPlane>("Plane")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomPlane, PXR_NS::UsdPrim const&>(), "new")

        .m(&PXR_NS::UsdGeomPlane::GetWidthAttr)
        .m(&PXR_NS::UsdGeomPlane::CreateWidthAttr)
        .m(&PXR_NS::UsdGeomPlane::GetLengthAttr)
        .m(&PXR_NS::UsdGeomPlane::CreateLengthAttr)
        .m(&PXR_NS::UsdGeomPlane::GetAxisAttr)
        .m(&PXR_NS::UsdGeomPlane::CreateAxisAttr)

        GPRIM_METHODS(PXR_NS::UsdGeomPlane)
        BOUNDABLE_METHODS(PXR_NS::UsdGeomPlane)
        XFORMABLE_METHODS(PXR_NS::UsdGeomPlane)
        IMAGEABLE_METHODS(PXR_NS::UsdGeomPlane)
        APISCHEMABASE_METHODS(PXR_NS::UsdGeomPlane)
        ;


    bbl::Class<PXR_NS::UsdGeomPointBased>("PointBased")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomPointBased, PXR_NS::UsdPrim const&>(), "new")

        POINTBASED_METHODS(PXR_NS::UsdGeomPointBased)
        GPRIM_METHODS(PXR_NS::UsdGeomPointBased)
        BOUNDABLE_METHODS(PXR_NS::UsdGeomPointBased)
        XFORMABLE_METHODS(PXR_NS::UsdGeomPointBased)
        IMAGEABLE_METHODS(PXR_NS::UsdGeomPointBased)
        APISCHEMABASE_METHODS(PXR_NS::UsdGeomPointBased)
        ;

    bbl::Class<PXR_NS::UsdGeomPointInstancer>("PointInstancer")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomPointInstancer, PXR_NS::UsdPrim const&>(), "new")

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

        BOUNDABLE_METHODS(PXR_NS::UsdGeomPointInstancer)
        XFORMABLE_METHODS(PXR_NS::UsdGeomPointInstancer)
        IMAGEABLE_METHODS(PXR_NS::UsdGeomPointInstancer)
        APISCHEMABASE_METHODS(PXR_NS::UsdGeomPointInstancer)
        ;
    
    bbl::Enum<PXR_NS::UsdGeomPointInstancer::ProtoXformInclusion>("ProtoXformInclusion");
    bbl::Enum<PXR_NS::UsdGeomPointInstancer::MaskApplication>("MaskApplication");

    bbl::Class<PXR_NS::UsdGeomPoints>("Points")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomPoints, PXR_NS::UsdPrim const&>(), "new")

        .m(&PXR_NS::UsdGeomPoints::GetWidthsAttr)
        .m(&PXR_NS::UsdGeomPoints::CreateWidthsAttr)
        .m(&PXR_NS::UsdGeomPoints::GetIdsAttr)
        .m(&PXR_NS::UsdGeomPoints::CreateIdsAttr)
        .m(&PXR_NS::UsdGeomPoints::GetWidthsInterpolation)
        .m(&PXR_NS::UsdGeomPoints::SetWidthsInterpolation)
        .m(&PXR_NS::UsdGeomPoints::GetPointCount)

        POINTBASED_METHODS(PXR_NS::UsdGeomPoints)
        GPRIM_METHODS(PXR_NS::UsdGeomPoints)
        BOUNDABLE_METHODS(PXR_NS::UsdGeomPoints)
        XFORMABLE_METHODS(PXR_NS::UsdGeomPoints)
        IMAGEABLE_METHODS(PXR_NS::UsdGeomPoints)
        APISCHEMABASE_METHODS(PXR_NS::UsdGeomPoints)
        ;

    bbl::Class<PXR_NS::UsdGeomPrimvar>("Primvar")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomPrimvar, PXR_NS::UsdAttribute const&>(), "new")

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
        .ctor(bbl::Ctor<PXR_NS::UsdGeomPrimvarsAPI, PXR_NS::UsdPrim const&>(), "new")

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

        APISCHEMABASE_METHODS(PXR_NS::UsdGeomPrimvarsAPI)
        ;

    bbl::Class<PXR_NS::UsdGeomScope>("Scope")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomScope, PXR_NS::UsdPrim const&>(), "new")

        .m(&PXR_NS::UsdGeomScope::Get)
        .m(&PXR_NS::UsdGeomScope::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdGeomScope::Define)

        IMAGEABLE_METHODS(PXR_NS::UsdGeomScope)
        APISCHEMABASE_METHODS(PXR_NS::UsdGeomScope)
        ;

    bbl::Class<PXR_NS::UsdGeomSphere>("Sphere")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomSphere, PXR_NS::UsdPrim const&>(), "new")

        .m(&PXR_NS::UsdGeomSphere::GetRadiusAttr)
        .m(&PXR_NS::UsdGeomSphere::CreateRadiusAttr)

        GPRIM_METHODS(PXR_NS::UsdGeomSphere)
        BOUNDABLE_METHODS(PXR_NS::UsdGeomSphere)
        XFORMABLE_METHODS(PXR_NS::UsdGeomSphere)
        IMAGEABLE_METHODS(PXR_NS::UsdGeomSphere)
        APISCHEMABASE_METHODS(PXR_NS::UsdGeomSphere)
        ;

    bbl::Class<PXR_NS::UsdGeomSubset>("Subset")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomSubset, PXR_NS::UsdPrim const&>(), "new")

        .m(&PXR_NS::UsdGeomSubset::GetElementTypeAttr)
        .m(&PXR_NS::UsdGeomSubset::CreateElementTypeAttr)
        .m(&PXR_NS::UsdGeomSubset::GetIndicesAttr)
        .m(&PXR_NS::UsdGeomSubset::CreateIndicesAttr)
        .m(&PXR_NS::UsdGeomSubset::GetFamilyNameAttr)
        .m(&PXR_NS::UsdGeomSubset::CreateFamilyNameAttr)

        // sttic
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

        APISCHEMABASE_METHODS(PXR_NS::UsdGeomSubset)
        ;

    bbl::Class<std::vector<PXR_NS::UsdGeomSubset>>("SubsetVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdGeomSubset)
        ;

    // XXX: figure out how to use UsdGeomTokensType


    bbl::Class<PXR_NS::UsdGeomVisibilityAPI>("VisibilityAPI")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomVisibilityAPI, PXR_NS::UsdPrim const&>(), "new")

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

        APISCHEMABASE_METHODS(PXR_NS::UsdGeomVisibilityAPI)
        ;


    bbl::Class<PXR_NS::UsdGeomXform>("Xform")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomXform>(), "new")

        .m(&PXR_NS::UsdGeomXform::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdGeomXform::Get)
        .m(&PXR_NS::UsdGeomXform::Define)

        XFORMABLE_METHODS(PXR_NS::UsdGeomXform)
        IMAGEABLE_METHODS(PXR_NS::UsdGeomXform)
        APISCHEMABASE_METHODS(PXR_NS::UsdGeomXform)
        ;

    bbl::Class<PXR_NS::UsdGeomXformCache>("XformCache")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomXformCache, PXR_NS::UsdTimeCode>("time"), "new")

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
        .ctor(bbl::Ctor<PXR_NS::UsdGeomXformCommonAPI, PXR_NS::UsdPrim const&>(), "new")

        .m(&PXR_NS::UsdGeomXformCommonAPI::SetXformVectors)
        // .m(&PXR_NS::UsdGeomXformCommonAPI::GetXformVectors)
        // .m(&PXR_NS::UsdGeomXformCommonAPI::GetXformVectorsByAccumulation)
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

        APISCHEMABASE_METHODS(PXR_NS::UsdGeomXformCommonAPI)
        ;

    bbl::Class<PXR_NS::UsdGeomXformCommonAPI::Ops>("XformCommonAPIOps");
    bbl::Enum<PXR_NS::UsdGeomXformCommonAPI::RotationOrder>("XformCommonAPIRotationOrder");
    bbl::Enum<PXR_NS::UsdGeomXformCommonAPI::OpFlags>("XformCommonAPIOpFlags");


    bbl::Class<PXR_NS::UsdGeomXformable>("Xformable")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomXformable>(), "new")

        XFORMABLE_METHODS(PXR_NS::UsdGeomXformable)
        IMAGEABLE_METHODS(PXR_NS::UsdGeomXformable)
        APISCHEMABASE_METHODS(PXR_NS::UsdGeomXformable)
        ;

    bbl::Class<PXR_NS::UsdGeomXformOp>("XformOp")
        .ctor(bbl::Ctor<PXR_NS::UsdGeomXformOp, PXR_NS::UsdAttribute const&, bool>("attr", "isInverseOp"), "new")

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
