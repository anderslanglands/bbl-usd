#if defined(__clang__)

#include "babble"
#include "babble-std"
#include "babble-vt"

#include <pxr/base/gf/interval.h>
#include <pxr/base/gf/vec2f.h>
#include <pxr/base/gf/vec3f.h>
#include <pxr/base/gf/vec4f.h>

#include <pxr/base/gf/vec2h.h>
#include <pxr/base/gf/vec3h.h>
#include <pxr/base/gf/vec4h.h>

#include <pxr/base/gf/vec2d.h>
#include <pxr/base/gf/vec3d.h>
#include <pxr/base/gf/vec4d.h>

#include <pxr/base/gf/vec2i.h>
#include <pxr/base/gf/vec3i.h>
#include <pxr/base/gf/vec4i.h>

#include <pxr/base/gf/matrix2d.h>
#include <pxr/base/gf/matrix3d.h>
#include <pxr/base/gf/matrix4d.h>

#include <pxr/base/gf/matrix2f.h>
#include <pxr/base/gf/matrix3f.h>
#include <pxr/base/gf/matrix4f.h>

#include <pxr/base/gf/quatd.h>
#include <pxr/base/gf/quatf.h>
#include <pxr/base/gf/quath.h>

#include <pxr/base/gf/bbox3d.h>

#include <pxr/base/gf/range1d.h>
#include <pxr/base/gf/range1f.h>
#include <pxr/base/gf/range2d.h>
#include <pxr/base/gf/range2f.h>
#include <pxr/base/gf/range3d.h>
#include <pxr/base/gf/range3f.h>

#include <pxr/base/gf/camera.h>
#include <pxr/base/gf/declare.h>
#include <pxr/base/gf/frustum.h>
#include <pxr/base/gf/range1f.h>
#include <pxr/base/gf/rotation.h>
#include <pxr/base/vt/types.h>

#include <pxr/base/vt/array.h>

#include <stddef.h>


struct Vec2f {
    float x;
    float y;
};

struct Vec3f {
    float x;
    float y;
    float z;
};

struct Vec4f {
    float x;
    float y;
    float z;
    float w;
};

struct Vec2h {
    short x;
    short y;
};

struct Vec3h {
    short x;
    short y;
    short z;
};

struct Vec4h {
    short x;
    short y;
    short z;
    short w;
};

struct Vec2d {
    double x;
    double y;
};

struct Vec3d {
    double x;
    double y;
    double z;
};

struct Vec4d {
    double x;
    double y;
    double z;
    double w;
};

struct Vec2i {
    int x;
    int y;
};

struct Vec3i {
    int x;
    int y;
    int z;
};

struct Vec4i {
    int x;
    int y;
    int z;
    int w;
};

struct Matrix2d {
    double m[4];
};

struct Matrix3d {
    double m[9];
};

struct Matrix4d {
    double m[16];
};

struct Matrix2f {
    float m[4];
};

struct Matrix3f {
    float m[9];
};

struct Matrix4f {
    float m[16];
};

struct Range1d {
    double mn;
    double mx;
};

struct Range1f {
    float mn;
    float mx;
};

struct Range2d {
    PXR_NS::GfVec2d mn;
    PXR_NS::GfVec2d mx;
};

struct Range2f {
    PXR_NS::GfVec2f mn;
    PXR_NS::GfVec2f mx;
};

struct Range3d {
    PXR_NS::GfVec3d mn;
    PXR_NS::GfVec3d mx;
};

struct Range3f {
    PXR_NS::GfVec3f mn;
    PXR_NS::GfVec3f mx;
};

struct Ray {
    PXR_NS::GfVec3d startPoint;
    PXR_NS::GfVec3d direction;
};

struct Rotation {
    PXR_NS::GfVec3d axis;
    double angle;
};

BBL_MODULE(gf) {
    // clang-format off

    // We don't bind methods for simple classes like this and will poke at the members directly or build that 
    // functionality in higher-level language bindings
    bbl::Class<PXR_NS::GfVec2f>("Vec2f")
        .replace_with<Vec2f>()
        ;
    
    bbl::Class<PXR_NS::VtArray<PXR_NS::GfVec2f>>("Vec2fArray")
        VTARRAY_METHODS(PXR_NS::GfVec2f)
    ;

    bbl::Class<PXR_NS::GfVec3f>("Vec3f")
        .replace_with<Vec3f>()
        ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfVec3f>>("Vec3fArray")
        VTARRAY_METHODS(PXR_NS::GfVec3f)
    ;

    bbl::Class<std::vector<PXR_NS::VtVec3fArray>>("Vec3fArrayVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::VtVec3fArray)
    ;

    bbl::Class<PXR_NS::GfVec4f>("Vec4f")
        .replace_with<Vec4f>()
        ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfVec4f>>("Vec4fArray")
        VTARRAY_METHODS(PXR_NS::GfVec4f)
    ;

    bbl::Class<std::vector<PXR_NS::GfVec4f>>("Vec4fVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::GfVec4f)
        ;

    bbl::Class<PXR_NS::GfVec2h>("Vec2h")
        .replace_with<Vec2h>()
        ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfVec2h>>("Vec2hArray")
        VTARRAY_METHODS(PXR_NS::GfVec2h)
    ;

    bbl::Class<PXR_NS::GfVec3h>("Vec3h")
        .replace_with<Vec3h>()
        ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfVec3h>>("Vec3hArray")
        VTARRAY_METHODS(PXR_NS::GfVec3h)
    ;

    bbl::Class<PXR_NS::GfVec4h>("Vec4h")
        .replace_with<Vec4h>()
        ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfVec4h>>("Vec4hArray")
        VTARRAY_METHODS(PXR_NS::GfVec4h)
    ;

    bbl::Class<PXR_NS::GfVec2d>("Vec2d")
        .replace_with<Vec2d>()
        ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfVec2d>>("Vec2dArray")
        VTARRAY_METHODS(PXR_NS::GfVec2d)
    ;

    bbl::Class<PXR_NS::GfVec3d>("Vec3d")
        .replace_with<Vec3d>()
        ;

    bbl::Class<std::vector<PXR_NS::GfVec3d>>("Vec3dVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::GfVec3d)
    ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfVec3d>>("Vec3dArray")
        VTARRAY_METHODS(PXR_NS::GfVec3d)
    ;

    bbl::Class<PXR_NS::GfVec4d>("Vec4d")
        .replace_with<Vec4d>()
        ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfVec4d>>("Vec4dArray")
        VTARRAY_METHODS(PXR_NS::GfVec4d)
    ;

    bbl::Class<PXR_NS::GfVec2i>("Vec2i")
        .replace_with<Vec2i>()
        ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfVec2i>>("Vec2iArray")
        VTARRAY_METHODS(PXR_NS::GfVec2i)
    ;

    bbl::Class<PXR_NS::GfVec3i>("Vec3i")
        .replace_with<Vec3i>()
        ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfVec3i>>("Vec3iArray")
        VTARRAY_METHODS(PXR_NS::GfVec3i)
    ;

    bbl::Class<PXR_NS::GfVec4i>("Vec4i")
        .replace_with<Vec4i>()
        ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfVec4i>>("Vec4iArray")
        VTARRAY_METHODS(PXR_NS::GfVec4i)
    ;

    bbl::Class<PXR_NS::GfMatrix2d>("Matrix2d")
        .replace_with<Matrix2d>()
        ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfMatrix2d>>("Matrix2dArray")
        VTARRAY_METHODS(PXR_NS::GfMatrix2d)
    ;

    bbl::Class<PXR_NS::GfMatrix3d>("Matrix3d")
        .replace_with<Matrix3d>()
        ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfMatrix3d>>("Matrix3dArray")
        VTARRAY_METHODS(PXR_NS::GfMatrix3d)
    ;

    bbl::Class<PXR_NS::GfMatrix4d>("Matrix4d")
        .replace_with<Matrix4d>()
        ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfMatrix4d>>("Matrix4dArray")
        VTARRAY_METHODS(PXR_NS::GfMatrix4d)
    ;
    
    bbl::Class<std::vector<PXR_NS::VtMatrix4dArray>>("Matrix4dArrayVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::VtMatrix4dArray)
    ;
    
    bbl::Class<PXR_NS::GfMatrix2f>("Matrix2f")
        .replace_with<Matrix2f>()
        ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfMatrix2f>>("Matrix2fArray")
        VTARRAY_METHODS(PXR_NS::GfMatrix2f)
    ;


    bbl::Class<PXR_NS::GfMatrix3f>("Matrix3f")
        .replace_with<Matrix3f>()
        ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfMatrix3f>>("Matrix3fArray")
        VTARRAY_METHODS(PXR_NS::GfMatrix3f)
    ;

    bbl::Class<PXR_NS::GfMatrix4f>("Matrix4f")
        .replace_with<Matrix4f>()
        ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfMatrix4f>>("Matrix4fArray")
        VTARRAY_METHODS(PXR_NS::GfMatrix4f)
    ;

    bbl::Class<PXR_NS::GfQuatd>("Quatd")
        .replace_with<Vec4d>()
        ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfQuatd>>("QuatdArray")
        VTARRAY_METHODS(PXR_NS::GfQuatd)
    ;

    bbl::Class<PXR_NS::GfQuatf>("Quatf")
        .replace_with<Vec4f>()
        ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfQuatf>>("QuatfArray")
        VTARRAY_METHODS(PXR_NS::GfQuatf)
    ;

    bbl::Class<PXR_NS::GfQuath>("Quath")
        .replace_with<Vec4h>()
        ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfQuath>>("QuathArray")
        VTARRAY_METHODS(PXR_NS::GfQuath)
    ;

    bbl::Class<PXR_NS::GfInterval>("Interval")
        .ctor(bbl::Ctor<PXR_NS::GfInterval>(), "default")
        .m(&PXR_NS::GfInterval::GetMin)
        .m(&PXR_NS::GfInterval::GetMax)
        .m(&PXR_NS::GfInterval::GetSize)
        ;

    bbl::Class<PXR_NS::GfBBox3d>("BBox3d")
        .ctor(bbl::Ctor<PXR_NS::GfBBox3d>(), "new")
        .ctor(bbl::Ctor<PXR_NS::GfBBox3d, PXR_NS::GfRange3d const&>("box"), "from_range")
        .ctor(bbl::Ctor<PXR_NS::GfBBox3d, PXR_NS::GfRange3d const&, PXR_NS::GfMatrix4d&>("box", "matrix"), "from_range_and_transform")
        .m(&PXR_NS::GfBBox3d::Set)
        .m(&PXR_NS::GfBBox3d::SetMatrix)
        .m(&PXR_NS::GfBBox3d::SetRange)
        ;

    bbl::Class<PXR_NS::GfRange1d>("Range1d")
        .replace_with<Range1d>()
        ;

    bbl::Class<PXR_NS::GfRange1f>("Range1f")
        .replace_with<Range1f>()
        ;

    bbl::Class<PXR_NS::GfRange2d>("Range2d")
        .replace_with<Range2d>()
        ;

    bbl::Class<PXR_NS::GfRange2f>("Range2f")
        .replace_with<Range2f>()
        ;

    bbl::Class<PXR_NS::GfRange3d>("Range3d")
        .replace_with<Range3d>()
        ;

    bbl::Class<PXR_NS::GfRange3f>("Range3f")
        .replace_with<Range3f>()
        ;

    bbl::Class<PXR_NS::GfCamera>("Camera")
        .ctor(bbl::Ctor<PXR_NS::GfCamera,
            PXR_NS::GfMatrix4d const&,
            PXR_NS::GfCamera::Projection,
            float,
            float,
            float,
            float,
            float,
            PXR_NS::GfRange1f,
            std::vector<PXR_NS::GfVec4f> const&,
            float,
            float
        >(
            "transform",
            "projection",
            "horizontalAperture",
            "verticalAperture",
            "horizontalApertureOffset",
            "verticalApertureOffset",
            "focalLength",
            "clippingRange",
            "clippingPlanes",
            "fStop",
            "focusDistance"
        ), "new")

        .m(&PXR_NS::GfCamera::SetTransform)
        .m(&PXR_NS::GfCamera::SetClippingRange)
        .m(&PXR_NS::GfCamera::SetClippingPlanes)
        .m(&PXR_NS::GfCamera::SetFStop)
        .m(&PXR_NS::GfCamera::SetFocusDistance)
        .m(&PXR_NS::GfCamera::SetFocalLength)
        .m(&PXR_NS::GfCamera::SetHorizontalAperture)
        .m(&PXR_NS::GfCamera::SetHorizontalApertureOffset)
        .m(&PXR_NS::GfCamera::SetVerticalAperture)
        .m(&PXR_NS::GfCamera::SetVerticalApertureOffset)
        .m(&PXR_NS::GfCamera::GetTransform)
        .m(&PXR_NS::GfCamera::GetClippingRange)
        .m(&PXR_NS::GfCamera::GetClippingPlanes)
        .m(&PXR_NS::GfCamera::GetFStop)
        .m(&PXR_NS::GfCamera::GetFocusDistance)
        .m(&PXR_NS::GfCamera::GetFocalLength)
        .m(&PXR_NS::GfCamera::GetHorizontalAperture)
        .m(&PXR_NS::GfCamera::GetHorizontalApertureOffset)
        .m(&PXR_NS::GfCamera::GetVerticalAperture)
        .m(&PXR_NS::GfCamera::GetVerticalApertureOffset)

        .m(&PXR_NS::GfCamera::GetFieldOfView)
        .m(&PXR_NS::GfCamera::GetFrustum)
        .m(&PXR_NS::GfCamera::SetPerspectiveFromAspectRatioAndFieldOfView)
        .m(&PXR_NS::GfCamera::SetOrthographicFromAspectRatioAndSize)
        .m(&PXR_NS::GfCamera::SetFromViewAndProjectionMatrix)
        ;

    bbl::Enum<PXR_NS::GfCamera::Projection>("CameraProjection");
    bbl::Enum<PXR_NS::GfCamera::FOVDirection>("CameraFOVDirection");

    bbl::Class<PXR_NS::GfFrustum>("Frustum")
        .ctor(bbl::Ctor<PXR_NS::GfFrustum>(), "new")
        .ctor(bbl::Ctor<PXR_NS::GfFrustum, PXR_NS::GfVec3f const&, PXR_NS::GfRotation const&, PXR_NS::GfRange2d const&, PXR_NS::GfRange1d const&, PXR_NS::GfFrustum::ProjectionType, double>("position", "rotation", "window", "nearFar", "projectionType", "viewDistance"), "from_position_and_rotation")
        .ctor(bbl::Ctor<PXR_NS::GfFrustum, PXR_NS::GfMatrix4d const&, PXR_NS::GfRange2d const&, PXR_NS::GfRange1d const&, PXR_NS::GfFrustum::ProjectionType, double>("camToWorldXF", "window", "nearFar", "projectionType", "viewDistance"), "from_transform")

        .m((void (PXR_NS::GfFrustum::*)(double, bool, double, double, double))
            &PXR_NS::GfFrustum::SetPerspective)
        .m((bool (PXR_NS::GfFrustum::*)(bool, double*, double*, double*, double*) const)
            &PXR_NS::GfFrustum::GetPerspective)

        .m(&PXR_NS::GfFrustum::GetFOV)
        .m(&PXR_NS::GfFrustum::GetOrthographic)
        .m(&PXR_NS::GfFrustum::SetOrthographic)
        .m(&PXR_NS::GfFrustum::FitToSphere)
        .m(&PXR_NS::GfFrustum::Transform)
        .m(&PXR_NS::GfFrustum::ComputeViewDirection)
        .m(&PXR_NS::GfFrustum::ComputeViewFrame)
        .m(&PXR_NS::GfFrustum::ComputeLookAtPoint)
        .m(&PXR_NS::GfFrustum::ComputeViewMatrix)
        .m(&PXR_NS::GfFrustum::ComputeViewInverse)
        .m(&PXR_NS::GfFrustum::ComputeProjectionMatrix)
        .m(&PXR_NS::GfFrustum::ComputeAspectRatio)
        .m(&PXR_NS::GfFrustum::ComputeCorners)
        .m(&PXR_NS::GfFrustum::ComputeCornersAtDistance)
        .m((PXR_NS::GfFrustum (PXR_NS::GfFrustum::*)(PXR_NS::GfVec2d const&, PXR_NS::GfVec2d const&) const)
            &PXR_NS::GfFrustum::ComputeNarrowedFrustum)
        .m((PXR_NS::GfRay (PXR_NS::GfFrustum::*)(PXR_NS::GfVec3d const&) const)
            &PXR_NS::GfFrustum::ComputeRay, "ComputeRay_to_point")
        .m((PXR_NS::GfRay (PXR_NS::GfFrustum::*)(PXR_NS::GfVec2d const&) const)
            &PXR_NS::GfFrustum::ComputeRay, "ComputeRay_from_screen")
        .m((PXR_NS::GfRay (PXR_NS::GfFrustum::*)(PXR_NS::GfVec3d const&) const)
            &PXR_NS::GfFrustum::ComputePickRay, "ComputePickRay_to_point")
        .m((PXR_NS::GfRay (PXR_NS::GfFrustum::*)(PXR_NS::GfVec2d const&) const)
            &PXR_NS::GfFrustum::ComputePickRay, "ComputePickRay_from_screen")

        .m(&PXR_NS::GfFrustum::SetPosition)
        .m(&PXR_NS::GfFrustum::GetPosition)
        .m(&PXR_NS::GfFrustum::GetRotation)
        .m(&PXR_NS::GfFrustum::SetRotation)
        .m(&PXR_NS::GfFrustum::SetPositionAndRotationFromMatrix)
        .m(&PXR_NS::GfFrustum::SetWindow)
        .m(&PXR_NS::GfFrustum::GetWindow)
        .m(&PXR_NS::GfFrustum::SetNearFar)
        .m(&PXR_NS::GfFrustum::GetNearFar)
        .m(&PXR_NS::GfFrustum::SetViewDistance)
        .m(&PXR_NS::GfFrustum::GetViewDistance)
        .m(&PXR_NS::GfFrustum::SetProjectionType)
        .m(&PXR_NS::GfFrustum::GetProjectionType)
        .m(&PXR_NS::GfFrustum::GetReferencePlaneDepth)

        .m((bool (PXR_NS::GfFrustum::*)(PXR_NS::GfBBox3d const&) const)
            &PXR_NS::GfFrustum::Intersects, "Intersects_box")
        .m((bool (PXR_NS::GfFrustum::*)(PXR_NS::GfVec3d const&) const)
            &PXR_NS::GfFrustum::Intersects, "Intersects_point")
        .m((bool (PXR_NS::GfFrustum::*)(PXR_NS::GfVec3d const&, PXR_NS::GfVec3d const&) const)
            &PXR_NS::GfFrustum::Intersects, "Intersects_line")
        .m((bool (PXR_NS::GfFrustum::*)(PXR_NS::GfVec3d const&, PXR_NS::GfVec3d const&, PXR_NS::GfVec3d const&) const)
            &PXR_NS::GfFrustum::Intersects, "Intersects_triangle")

        .m(&PXR_NS::GfFrustum::IntersectsViewVolume)
    ;

    bbl::Enum<PXR_NS::GfFrustum::ProjectionType>("FrustumProjectionType");

    bbl::Class<PXR_NS::GfRay>("Ray")
        .value_type()
        .replace_with<Ray>()

        .m(&PXR_NS::GfRay::GetStartPoint)
        .m(&PXR_NS::GfRay::GetDirection)
        .m(&PXR_NS::GfRay::GetPoint)
    ;

    bbl::Class<PXR_NS::GfRotation>("Rotation")
        .value_type()
        .replace_with<Rotation>()
        ;

}


#endif

