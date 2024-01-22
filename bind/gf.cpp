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

#include <pxr/base/gf/dualQuatd.h>
#include <pxr/base/gf/dualQuatf.h>
#include <pxr/base/gf/dualQuath.h>

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

#include <pxr/base/gf/line.h>
#include <pxr/base/gf/line2d.h>
#include <pxr/base/gf/lineSeg.h>
#include <pxr/base/gf/lineSeg2d.h>
#include <pxr/base/gf/multiInterval.h>
#include <pxr/base/gf/rect2i.h>
#include <pxr/base/gf/size2.h>
#include <pxr/base/gf/size3.h>
#include <pxr/base/gf/transform.h>

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

    bbl::Class<PXR_NS::GfBBox3d>("BBox3d")
        .ctor(bbl::Class<PXR_NS::GfBBox3d>::Ctor<>(), "new")
        .ctor(bbl::Class<PXR_NS::GfBBox3d>::Ctor<PXR_NS::GfRange3d const&>("box"), "from_range")
        .ctor(bbl::Class<PXR_NS::GfBBox3d>::Ctor<PXR_NS::GfRange3d const&, PXR_NS::GfMatrix4d&>("box", "matrix"), "from_range_and_transform")
        .m(&PXR_NS::GfBBox3d::Set)
        .m(&PXR_NS::GfBBox3d::SetMatrix)
        .m(&PXR_NS::GfBBox3d::SetRange)
        .m(&PXR_NS::GfBBox3d::GetRange)
        .m(&PXR_NS::GfBBox3d::GetBox)
        .m(&PXR_NS::GfBBox3d::GetMatrix)
        .m(&PXR_NS::GfBBox3d::GetInverseMatrix)
        .m(&PXR_NS::GfBBox3d::SetHasZeroAreaPrimitives)
        .m(&PXR_NS::GfBBox3d::HasZeroAreaPrimitives)
        .m(&PXR_NS::GfBBox3d::GetVolume)
        .m(&PXR_NS::GfBBox3d::Transform)
        .m(&PXR_NS::GfBBox3d::ComputeAlignedRange)
        .m(&PXR_NS::GfBBox3d::ComputeAlignedBox)
        .m(&PXR_NS::GfBBox3d::Combine)
        .m(&PXR_NS::GfBBox3d::ComputeCentroid)
        .m(&PXR_NS::GfBBox3d::operator==, "op_eq")
        ;

    bbl::Class<PXR_NS::GfCamera>("Camera")
        .ctor(bbl::Class<PXR_NS::GfCamera>::Ctor<PXR_NS::GfMatrix4d const&, PXR_NS::GfCamera::Projection, float, float, float, float, float, PXR_NS::GfRange1f, std::vector<PXR_NS::GfVec4f> const&, float, float >(
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

    bbl::Class<PXR_NS::GfDualQuatd>("DualQuatd")
        .ctor(bbl::Class<PXR_NS::GfDualQuatd>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfDualQuatd>::Ctor<double>("realVal"), "from_double")
        .ctor(bbl::Class<PXR_NS::GfDualQuatd>::Ctor<const PXR_NS::GfQuatd &>("real"), "from_real")
        .ctor(bbl::Class<PXR_NS::GfDualQuatd>::Ctor<const PXR_NS::GfQuatd &, const PXR_NS::GfQuatd &>("real", "dual"), "ctor")
        .ctor(bbl::Class<PXR_NS::GfDualQuatd>::Ctor<const PXR_NS::GfQuatd &, const PXR_NS::GfVec3d &>("rotation", "translation"), "from_rotation_translation")
        .ctor(bbl::Class<PXR_NS::GfDualQuatd>::Ctor<const PXR_NS::GfDualQuatf &>("other"), "from_dualquatf")
        .ctor(bbl::Class<PXR_NS::GfDualQuatd>::Ctor<const PXR_NS::GfDualQuath &>("other"), "from_dualquath")
        .m(&PXR_NS::GfDualQuatd::SetReal)
        .m(&PXR_NS::GfDualQuatd::SetDual)
        .m(&PXR_NS::GfDualQuatd::GetReal)
        .m(&PXR_NS::GfDualQuatd::GetDual)
        .m(&PXR_NS::GfDualQuatd::GetZero)
        .m(&PXR_NS::GfDualQuatd::GetIdentity)
        .m(&PXR_NS::GfDualQuatd::GetLength)
        .m(&PXR_NS::GfDualQuatd::GetNormalized)
        .m(&PXR_NS::GfDualQuatd::Normalize)
        .m(&PXR_NS::GfDualQuatd::GetConjugate)
        .m(&PXR_NS::GfDualQuatd::GetInverse)
        .m(&PXR_NS::GfDualQuatd::SetTranslation)
        .m(&PXR_NS::GfDualQuatd::GetTranslation)
        .m(&PXR_NS::GfDualQuatd::operator==, "op_eq")
        .m(&PXR_NS::GfDualQuatd::operator!=, "op_neq")
        .m(&PXR_NS::GfDualQuatd::operator+=, "op_add_assign")
        .m(&PXR_NS::GfDualQuatd::operator-=, "op_sub_assign")
        .m(&PXR_NS::GfDualQuatd::operator/=, "op_div_assign")
        .m((PXR_NS::GfDualQuatd & (PXR_NS::GfDualQuatd::*)(const PXR_NS::GfDualQuatd &))
            &PXR_NS::GfDualQuatd::operator*=, "op_mul_assign_quatd")
        .m((PXR_NS::GfDualQuatd & (PXR_NS::GfDualQuatd::*)(double))
            &PXR_NS::GfDualQuatd::operator*=, "op_mul_assign_double")
        .m(&PXR_NS::GfDualQuatd::Transform)
    ;

    bbl::fn((double (*)(const PXR_NS::GfDualQuatd &, const PXR_NS::GfDualQuatd &))
            &PXR_NS::GfDot, "GfDot_dualquatd");

    bbl::Class<PXR_NS::GfDualQuatf>("DualQuatf")
        .ctor(bbl::Class<PXR_NS::GfDualQuatf>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfDualQuatf>::Ctor<float>("realVal"), "from_float")
        .ctor(bbl::Class<PXR_NS::GfDualQuatf>::Ctor<const PXR_NS::GfQuatf &>("real"), "from_real")
        .ctor(bbl::Class<PXR_NS::GfDualQuatf>::Ctor<const PXR_NS::GfQuatf &, const PXR_NS::GfQuatf &>("real", "dual"), "ctor")
        .ctor(bbl::Class<PXR_NS::GfDualQuatf>::Ctor<const PXR_NS::GfQuatf &, const PXR_NS::GfVec3f &>("rotation", "translation"), "from_rotation_translation")
        .ctor(bbl::Class<PXR_NS::GfDualQuatf>::Ctor<const PXR_NS::GfDualQuatd &>("other"), "from_dualquatd")
        .ctor(bbl::Class<PXR_NS::GfDualQuatf>::Ctor<const PXR_NS::GfDualQuath &>("other"), "from_dualquath")
        .m(&PXR_NS::GfDualQuatf::SetReal)
        .m(&PXR_NS::GfDualQuatf::SetDual)
        .m(&PXR_NS::GfDualQuatf::GetReal)
        .m(&PXR_NS::GfDualQuatf::GetDual)
        .m(&PXR_NS::GfDualQuatf::GetZero)
        .m(&PXR_NS::GfDualQuatf::GetIdentity)
        .m(&PXR_NS::GfDualQuatf::GetLength)
        .m(&PXR_NS::GfDualQuatf::GetNormalized)
        .m(&PXR_NS::GfDualQuatf::Normalize)
        .m(&PXR_NS::GfDualQuatf::GetConjugate)
        .m(&PXR_NS::GfDualQuatf::GetInverse)
        .m(&PXR_NS::GfDualQuatf::SetTranslation)
        .m(&PXR_NS::GfDualQuatf::GetTranslation)
        .m(&PXR_NS::GfDualQuatf::operator==, "op_eq")
        .m(&PXR_NS::GfDualQuatf::operator!=, "op_neq")
        .m(&PXR_NS::GfDualQuatf::operator+=, "op_add_assign")
        .m(&PXR_NS::GfDualQuatf::operator-=, "op_sub_assign")
        .m((PXR_NS::GfDualQuatf & (PXR_NS::GfDualQuatf::*)(const PXR_NS::GfDualQuatf &))
            &PXR_NS::GfDualQuatf::operator*=, "op_mul_assign_dualquatf")
        .m((PXR_NS::GfDualQuatf & (PXR_NS::GfDualQuatf::*)(float))
            &PXR_NS::GfDualQuatf::operator*=, "op_mul_assign_float")
        .m(&PXR_NS::GfDualQuatf::operator/=, "op_div_assign")
        .m(&PXR_NS::GfDualQuatf::Transform)
    ;

    bbl::fn((float (*)(const PXR_NS::GfDualQuatf &, const PXR_NS::GfDualQuatf &))
            &PXR_NS::GfDot, "GfDot_dualquatf");


    bbl::Class<PXR_NS::GfDualQuath>("DualQuath")
        .ctor(bbl::Class<PXR_NS::GfDualQuath>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfDualQuath>::Ctor<PXR_NS::GfHalf>("realVal"), "from_half")
        .ctor(bbl::Class<PXR_NS::GfDualQuath>::Ctor<const PXR_NS::GfQuath &>("real"), "from_real")
        .ctor(bbl::Class<PXR_NS::GfDualQuath>::Ctor<const PXR_NS::GfQuath &, const PXR_NS::GfQuath &>("real", "dual"), "ctor")
        .ctor(bbl::Class<PXR_NS::GfDualQuath>::Ctor<const PXR_NS::GfQuath &, const PXR_NS::GfVec3h &>("rotation", "translation"), "from_rotation_translation")
        .ctor(bbl::Class<PXR_NS::GfDualQuath>::Ctor<const PXR_NS::GfDualQuatd &>("other"), "from_dualquatd")
        .ctor(bbl::Class<PXR_NS::GfDualQuath>::Ctor<const PXR_NS::GfDualQuatf &>("other"), "from_dualquatf")
        .m(&PXR_NS::GfDualQuath::SetReal)
        .m(&PXR_NS::GfDualQuath::SetDual)
        .m(&PXR_NS::GfDualQuath::GetReal)
        .m(&PXR_NS::GfDualQuath::GetDual)
        .m(&PXR_NS::GfDualQuath::GetZero)
        .m(&PXR_NS::GfDualQuath::GetIdentity)
        .m(&PXR_NS::GfDualQuath::GetLength)
        .m(&PXR_NS::GfDualQuath::GetNormalized)
        .m(&PXR_NS::GfDualQuath::Normalize)
        .m(&PXR_NS::GfDualQuath::GetConjugate)
        .m(&PXR_NS::GfDualQuath::GetInverse)
        .m(&PXR_NS::GfDualQuath::SetTranslation)
        .m(&PXR_NS::GfDualQuath::GetTranslation)
        .m(&PXR_NS::GfDualQuath::operator==, "op_eq")
        .m(&PXR_NS::GfDualQuath::operator!=, "op_neq")
        .m(&PXR_NS::GfDualQuath::operator+=, "op_add_assign")
        .m(&PXR_NS::GfDualQuath::operator-=, "op_sub_assign")
        .m((PXR_NS::GfDualQuath & (PXR_NS::GfDualQuath::*)(const PXR_NS::GfDualQuath &))
            &PXR_NS::GfDualQuath::operator*=, "op_mul_assign_dualquath")
        .m((PXR_NS::GfDualQuath & (PXR_NS::GfDualQuath::*)(PXR_NS::GfHalf))
            &PXR_NS::GfDualQuath::operator*=, "op_mul_assign_half")
        .m(&PXR_NS::GfDualQuath::operator/=, "op_div_assign")
        .m(&PXR_NS::GfDualQuath::Transform)
    ;

    bbl::fn((PXR_NS::GfHalf (*)(const PXR_NS::GfDualQuath &, const PXR_NS::GfDualQuath &))
            &PXR_NS::GfDot, "GfDot_dualquath");


    bbl::Class<PXR_NS::GfFrustum>("Frustum")
        .ctor(bbl::Class<PXR_NS::GfFrustum>::Ctor<>(), "new")
        .ctor(bbl::Class<PXR_NS::GfFrustum>::Ctor<PXR_NS::GfVec3f const&, PXR_NS::GfRotation const&, PXR_NS::GfRange2d const&, PXR_NS::GfRange1d const&, PXR_NS::GfFrustum::ProjectionType, double>("position", "rotation", "window", "nearFar", "projectionType", "viewDistance"), "from_position_and_rotation")
        .ctor(bbl::Class<PXR_NS::GfFrustum>::Ctor<PXR_NS::GfMatrix4d const&, PXR_NS::GfRange2d const&, PXR_NS::GfRange1d const&, PXR_NS::GfFrustum::ProjectionType, double>("camToWorldXF", "window", "nearFar", "projectionType", "viewDistance"), "from_transform")

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

    bbl::Class<PXR_NS::GfHalf>("Half")
    ;

    bbl::Class<std::pair<PXR_NS::GfHalf, PXR_NS::GfHalf>>("HalfPair");

    bbl::Class<PXR_NS::GfInterval>("Interval")
        .ctor(bbl::Class<PXR_NS::GfInterval>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfInterval>::Ctor<double>("val"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::GfInterval>::Ctor<double, double, bool, bool>("min", "max", "minClosed", "maxClosed"), "ctor_02")
        .m(&PXR_NS::GfInterval::operator==, "op_eq")
        .m(&PXR_NS::GfInterval::operator!=, "op_neq")
        .m(&PXR_NS::GfInterval::operator<, "op_lt")
        .m(&PXR_NS::GfInterval::Hash)
        .m(&PXR_NS::GfInterval::GetMin)
        .m(&PXR_NS::GfInterval::GetMax)
        .m((void (PXR_NS::GfInterval::*)(double))
            &PXR_NS::GfInterval::SetMin, "SetMin_00")
        .m((void (PXR_NS::GfInterval::*)(double, bool))
            &PXR_NS::GfInterval::SetMin, "SetMin_01")
        .m((void (PXR_NS::GfInterval::*)(double))
            &PXR_NS::GfInterval::SetMax, "SetMax_00")
        .m((void (PXR_NS::GfInterval::*)(double, bool))
            &PXR_NS::GfInterval::SetMax, "SetMax_01")
        .m(&PXR_NS::GfInterval::IsMinClosed)
        .m(&PXR_NS::GfInterval::IsMaxClosed)
        .m(&PXR_NS::GfInterval::IsMinOpen)
        .m(&PXR_NS::GfInterval::IsMaxOpen)
        .m(&PXR_NS::GfInterval::IsMaxFinite)
        .m(&PXR_NS::GfInterval::IsMinFinite)
        .m(&PXR_NS::GfInterval::IsFinite)
        .m(&PXR_NS::GfInterval::IsEmpty)
        .m(&PXR_NS::GfInterval::GetSize)
        .m(&PXR_NS::GfInterval::Size)
        .m((bool (PXR_NS::GfInterval::*)(double) const)
            &PXR_NS::GfInterval::Contains, "Contains_00")
        .m((bool (PXR_NS::GfInterval::*)(const PXR_NS::GfInterval &) const)
            &PXR_NS::GfInterval::Contains, "Contains_01")
        .m(&PXR_NS::GfInterval::In)
        .m(&PXR_NS::GfInterval::Intersects)
        .m(&PXR_NS::GfInterval::operator&=, "op_bit_assign")
        .m(&PXR_NS::GfInterval::operator|=, "op_bitor_assign")
        .m(&PXR_NS::GfInterval::operator+=, "op_add_assign")
        .m(&PXR_NS::GfInterval::operator-=, "op_sub_assign")
        .m((PXR_NS::GfInterval (PXR_NS::GfInterval::*)() const)
            &PXR_NS::GfInterval::operator-, "op_neg")
        .m((PXR_NS::GfInterval (PXR_NS::GfInterval::*)(const PXR_NS::GfInterval &) const)
            &PXR_NS::GfInterval::operator-, "op_sub")
        .m(&PXR_NS::GfInterval::operator*=, "op_mul_assign")
        .m(&PXR_NS::GfInterval::operator>, "op_gt")
        .m(&PXR_NS::GfInterval::operator<=, "op_lte")
        .m(&PXR_NS::GfInterval::operator>=, "op_gte")
        .m(&PXR_NS::GfInterval::operator|, "op_bitor")
        .m(&PXR_NS::GfInterval::operator&, "op_bitand")
        .m(&PXR_NS::GfInterval::operator+, "op_add")
        .m(&PXR_NS::GfInterval::operator*, "op_mul")
        .m(&PXR_NS::GfInterval::GetFullInterval)
    ;

    bbl::Class<std::vector<PXR_NS::GfInterval>>("IntervalVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::GfInterval)
    ;

    bbl::Class<PXR_NS::GfLine>("Line")
        .ctor(bbl::Class<PXR_NS::GfLine>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfLine>::Ctor<const PXR_NS::GfVec3d &, const PXR_NS::GfVec3d &>("p0", "dir"), "ctor_01")
        .m(&PXR_NS::GfLine::Set)
        .m(&PXR_NS::GfLine::GetPoint)
        .m(&PXR_NS::GfLine::GetDirection)
        .m(&PXR_NS::GfLine::FindClosestPoint)
        .m(&PXR_NS::GfLine::operator==, "op_eq")
    ;

    bbl::Class<PXR_NS::GfLine2d>("Line2d")
        .ctor(bbl::Class<PXR_NS::GfLine2d>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfLine2d>::Ctor<const PXR_NS::GfVec2d &, const PXR_NS::GfVec2d &>("p0", "dir"), "ctor_01")
        .m(&PXR_NS::GfLine2d::Set)
        .m(&PXR_NS::GfLine2d::GetPoint)
        .m(&PXR_NS::GfLine2d::GetDirection)
        .m(&PXR_NS::GfLine2d::FindClosestPoint)
        .m(&PXR_NS::GfLine2d::operator==, "op_eq")
    ;

    bbl::Class<PXR_NS::GfLineSeg>("LineSeg")
        .ctor(bbl::Class<PXR_NS::GfLineSeg>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfLineSeg>::Ctor<const PXR_NS::GfVec3d &, const PXR_NS::GfVec3d &>("p0", "p1"), "ctor_01")
        .m(&PXR_NS::GfLineSeg::GetPoint)
        .m(&PXR_NS::GfLineSeg::GetDirection)
        .m(&PXR_NS::GfLineSeg::GetLength)
        .m(&PXR_NS::GfLineSeg::FindClosestPoint)
        .m(&PXR_NS::GfLineSeg::operator==, "op_eq")
    ;

    bbl::Class<PXR_NS::GfLineSeg2d>("LineSeg2d")
        .ctor(bbl::Class<PXR_NS::GfLineSeg2d>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfLineSeg2d>::Ctor<const PXR_NS::GfVec2d &, const PXR_NS::GfVec2d &>("p0", "p1"), "ctor_01")
        .m(&PXR_NS::GfLineSeg2d::GetPoint)
        .m(&PXR_NS::GfLineSeg2d::GetDirection)
        .m(&PXR_NS::GfLineSeg2d::GetLength)
        .m(&PXR_NS::GfLineSeg2d::FindClosestPoint)
        .m(&PXR_NS::GfLineSeg2d::operator==, "op_eq")
        .m(&PXR_NS::GfLineSeg2d::operator!=, "op_neq")
    ;

    bbl::Class<PXR_NS::GfMatrix2d>("Matrix2d")
        .replace_with<Matrix2d>()
        .ctor(bbl::Class<PXR_NS::GfMatrix2d>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfMatrix2d>::Ctor<double, double, double, double>("m00", "m01", "m10", "m11"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::GfMatrix2d>::Ctor<const double (*)[2]>("m"), "ctor_02")
        .ctor(bbl::Class<PXR_NS::GfMatrix2d>::Ctor<double>("s"), "ctor_03")
        .ctor(bbl::Class<PXR_NS::GfMatrix2d>::Ctor<int>("s"), "ctor_04")
        .ctor(bbl::Class<PXR_NS::GfMatrix2d>::Ctor<const PXR_NS::GfVec2d &>("v"), "ctor_05")
        .m(&PXR_NS::GfMatrix2d::SetRow)
        .m(&PXR_NS::GfMatrix2d::SetColumn)
        .m(&PXR_NS::GfMatrix2d::GetRow)
        .m(&PXR_NS::GfMatrix2d::GetColumn)
        .m((PXR_NS::GfMatrix2d & (PXR_NS::GfMatrix2d::*)(double, double, double, double))
            &PXR_NS::GfMatrix2d::Set, "Set_00")
        .m((PXR_NS::GfMatrix2d & (PXR_NS::GfMatrix2d::*)(const double (*)[2]))
            &PXR_NS::GfMatrix2d::Set, "Set_01")
        .m(&PXR_NS::GfMatrix2d::SetIdentity)
        .m(&PXR_NS::GfMatrix2d::SetZero)
        .m((PXR_NS::GfMatrix2d & (PXR_NS::GfMatrix2d::*)(double))
            &PXR_NS::GfMatrix2d::SetDiagonal, "SetDiagonal_00")
        .m((PXR_NS::GfMatrix2d & (PXR_NS::GfMatrix2d::*)(const PXR_NS::GfVec2d &))
            &PXR_NS::GfMatrix2d::SetDiagonal, "SetDiagonal_01")
        .m(&PXR_NS::GfMatrix2d::Get)
        .m((double * (PXR_NS::GfMatrix2d::*)())
            &PXR_NS::GfMatrix2d::data, "data_00")
        .m((const double * (PXR_NS::GfMatrix2d::*)() const)
            &PXR_NS::GfMatrix2d::data, "data_01")
        .m((double * (PXR_NS::GfMatrix2d::*)())
            &PXR_NS::GfMatrix2d::GetArray, "GetArray_00")
        .m((const double * (PXR_NS::GfMatrix2d::*)() const)
            &PXR_NS::GfMatrix2d::GetArray, "GetArray_01")
        .m((double * (PXR_NS::GfMatrix2d::*)(int))
            &PXR_NS::GfMatrix2d::operator[], "op_index_00")
        .m((const double * (PXR_NS::GfMatrix2d::*)(int) const)
            &PXR_NS::GfMatrix2d::operator[], "op_index_01")
        .m((bool (PXR_NS::GfMatrix2d::*)(const PXR_NS::GfMatrix2d &) const)
            &PXR_NS::GfMatrix2d::operator==, "op_eq_00")
        .m((bool (PXR_NS::GfMatrix2d::*)(const PXR_NS::GfMatrix2f &) const)
            &PXR_NS::GfMatrix2d::operator==, "op_eq_01")
        .m((bool (PXR_NS::GfMatrix2d::*)(const PXR_NS::GfMatrix2d &) const)
            &PXR_NS::GfMatrix2d::operator!=, "op_neq_00")
        .m((bool (PXR_NS::GfMatrix2d::*)(const PXR_NS::GfMatrix2f &) const)
            &PXR_NS::GfMatrix2d::operator!=, "op_neq_01")
        .m(&PXR_NS::GfMatrix2d::GetTranspose)
        .m(&PXR_NS::GfMatrix2d::GetInverse)
        .m(&PXR_NS::GfMatrix2d::GetDeterminant)
        .m((PXR_NS::GfMatrix2d & (PXR_NS::GfMatrix2d::*)(const PXR_NS::GfMatrix2d &))
            &PXR_NS::GfMatrix2d::operator*=, "op_mul_assign_00")
        .m((PXR_NS::GfMatrix2d & (PXR_NS::GfMatrix2d::*)(double))
            &PXR_NS::GfMatrix2d::operator*=, "op_mul_assign_01")
        .m(&PXR_NS::GfMatrix2d::operator+=, "op_add_assign")
        .m(&PXR_NS::GfMatrix2d::operator-=, "op_sub_assign")
    ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfMatrix2d>>("Matrix2dArray")
        VTARRAY_METHODS(PXR_NS::GfMatrix2d)
    ;

    bbl::Class<PXR_NS::GfMatrix3d>("Matrix3d")
        .replace_with<Matrix3d>()
        .ctor(bbl::Class<PXR_NS::GfMatrix3d>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfMatrix3d>::Ctor<double, double, double, double, double, double, double, double, double>("m00", "m01", "m02", "m10", "m11", "m12", "m20", "m21", "m22"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::GfMatrix3d>::Ctor<const double (*)[3]>("m"), "ctor_02")
        .ctor(bbl::Class<PXR_NS::GfMatrix3d>::Ctor<double>("s"), "ctor_03")
        .ctor(bbl::Class<PXR_NS::GfMatrix3d>::Ctor<int>("s"), "ctor_04")
        .ctor(bbl::Class<PXR_NS::GfMatrix3d>::Ctor<const PXR_NS::GfVec3d &>("v"), "ctor_05")
        .ctor(bbl::Class<PXR_NS::GfMatrix3d>::Ctor<const PXR_NS::GfRotation &>("rot"), "ctor_08")
        .ctor(bbl::Class<PXR_NS::GfMatrix3d>::Ctor<const PXR_NS::GfQuatd &>("rot"), "ctor_09")
        .m(&PXR_NS::GfMatrix3d::SetRow)
        .m(&PXR_NS::GfMatrix3d::SetColumn)
        .m(&PXR_NS::GfMatrix3d::GetRow)
        .m(&PXR_NS::GfMatrix3d::GetColumn)
        .m((PXR_NS::GfMatrix3d & (PXR_NS::GfMatrix3d::*)(double, double, double, double, double, double, double, double, double))
            &PXR_NS::GfMatrix3d::Set, "Set_00")
        .m((PXR_NS::GfMatrix3d & (PXR_NS::GfMatrix3d::*)(const double (*)[3]))
            &PXR_NS::GfMatrix3d::Set, "Set_01")
        .m(&PXR_NS::GfMatrix3d::SetIdentity)
        .m(&PXR_NS::GfMatrix3d::SetZero)
        .m((PXR_NS::GfMatrix3d & (PXR_NS::GfMatrix3d::*)(double))
            &PXR_NS::GfMatrix3d::SetDiagonal, "SetDiagonal_00")
        .m((PXR_NS::GfMatrix3d & (PXR_NS::GfMatrix3d::*)(const PXR_NS::GfVec3d &))
            &PXR_NS::GfMatrix3d::SetDiagonal, "SetDiagonal_01")
        .m(&PXR_NS::GfMatrix3d::Get)
        .m((double * (PXR_NS::GfMatrix3d::*)())
            &PXR_NS::GfMatrix3d::data, "data_00")
        .m((const double * (PXR_NS::GfMatrix3d::*)() const)
            &PXR_NS::GfMatrix3d::data, "data_01")
        .m((double * (PXR_NS::GfMatrix3d::*)())
            &PXR_NS::GfMatrix3d::GetArray, "GetArray_00")
        .m((const double * (PXR_NS::GfMatrix3d::*)() const)
            &PXR_NS::GfMatrix3d::GetArray, "GetArray_01")
        .m((double * (PXR_NS::GfMatrix3d::*)(int))
            &PXR_NS::GfMatrix3d::operator[], "op_index_00")
        .m((const double * (PXR_NS::GfMatrix3d::*)(int) const)
            &PXR_NS::GfMatrix3d::operator[], "op_index_01")
        .m((bool (PXR_NS::GfMatrix3d::*)(const PXR_NS::GfMatrix3d &) const)
            &PXR_NS::GfMatrix3d::operator==, "op_eq_00")
        .m((bool (PXR_NS::GfMatrix3d::*)(const PXR_NS::GfMatrix3f &) const)
            &PXR_NS::GfMatrix3d::operator==, "op_eq_01")
        .m((bool (PXR_NS::GfMatrix3d::*)(const PXR_NS::GfMatrix3d &) const)
            &PXR_NS::GfMatrix3d::operator!=, "op_neq_00")
        .m((bool (PXR_NS::GfMatrix3d::*)(const PXR_NS::GfMatrix3f &) const)
            &PXR_NS::GfMatrix3d::operator!=, "op_neq_01")
        .m(&PXR_NS::GfMatrix3d::GetTranspose)
        .m(&PXR_NS::GfMatrix3d::GetInverse)
        .m(&PXR_NS::GfMatrix3d::GetDeterminant)
        .m(&PXR_NS::GfMatrix3d::Orthonormalize)
        .m(&PXR_NS::GfMatrix3d::GetOrthonormalized)
        .m(&PXR_NS::GfMatrix3d::GetHandedness)
        .m(&PXR_NS::GfMatrix3d::IsRightHanded)
        .m(&PXR_NS::GfMatrix3d::IsLeftHanded)
        .m((PXR_NS::GfMatrix3d & (PXR_NS::GfMatrix3d::*)(const PXR_NS::GfMatrix3d &))
            &PXR_NS::GfMatrix3d::operator*=, "op_mul_assign_00")
        .m((PXR_NS::GfMatrix3d & (PXR_NS::GfMatrix3d::*)(double))
            &PXR_NS::GfMatrix3d::operator*=, "op_mul_assign_01")
        .m(&PXR_NS::GfMatrix3d::operator+=, "op_add_assign")
        .m(&PXR_NS::GfMatrix3d::operator-=, "op_sub_assign")
        .m((PXR_NS::GfMatrix3d & (PXR_NS::GfMatrix3d::*)(double))
            &PXR_NS::GfMatrix3d::SetScale, "SetScale_00")
        .m((PXR_NS::GfMatrix3d & (PXR_NS::GfMatrix3d::*)(const PXR_NS::GfVec3d &))
            &PXR_NS::GfMatrix3d::SetScale, "SetScale_01")
        .m((PXR_NS::GfMatrix3d & (PXR_NS::GfMatrix3d::*)(const PXR_NS::GfQuatd &))
            &PXR_NS::GfMatrix3d::SetRotate, "SetRotate_00")
        .m((PXR_NS::GfMatrix3d & (PXR_NS::GfMatrix3d::*)(const PXR_NS::GfRotation &))
            &PXR_NS::GfMatrix3d::SetRotate, "SetRotate_01")
        .m(&PXR_NS::GfMatrix3d::ExtractRotation)
        .m(&PXR_NS::GfMatrix3d::DecomposeRotation)
        .m(&PXR_NS::GfMatrix3d::ExtractRotationQuaternion)
        ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfMatrix3d>>("Matrix3dArray")
        VTARRAY_METHODS(PXR_NS::GfMatrix3d)
    ;

    bbl::Class<PXR_NS::GfMatrix4d>("Matrix4d")
        .replace_with<Matrix4d>()
        .ctor(bbl::Class<PXR_NS::GfMatrix4d>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfMatrix4d>::Ctor<double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double>("m00", "m01", "m02", "m03", "m10", "m11", "m12", "m13", "m20", "m21", "m22", "m23", "m30", "m31", "m32", "m33"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::GfMatrix4d>::Ctor<const double (*)[4]>("m"), "ctor_02")
        .ctor(bbl::Class<PXR_NS::GfMatrix4d>::Ctor<double>("s"), "ctor_03")
        .ctor(bbl::Class<PXR_NS::GfMatrix4d>::Ctor<const PXR_NS::GfVec4d &>("v"), "ctor_04")
        .ctor(bbl::Class<PXR_NS::GfMatrix4d>::Ctor<const PXR_NS::GfRotation &, const PXR_NS::GfVec3d &>("rotate", "translate"), "ctor_09")
        .ctor(bbl::Class<PXR_NS::GfMatrix4d>::Ctor<const PXR_NS::GfMatrix3d &, const PXR_NS::GfVec3d &>("rotmx", "translate"), "ctor_10")
        .m(&PXR_NS::GfMatrix4d::SetRow)
        .m(&PXR_NS::GfMatrix4d::SetColumn)
        .m(&PXR_NS::GfMatrix4d::GetRow)
        .m(&PXR_NS::GfMatrix4d::GetColumn)
        .m((PXR_NS::GfMatrix4d & (PXR_NS::GfMatrix4d::*)(double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double))
            &PXR_NS::GfMatrix4d::Set, "Set_00")
        .m((PXR_NS::GfMatrix4d & (PXR_NS::GfMatrix4d::*)(const double (*)[4]))
            &PXR_NS::GfMatrix4d::Set, "Set_01")
        .m(&PXR_NS::GfMatrix4d::SetIdentity)
        .m(&PXR_NS::GfMatrix4d::SetZero)
        .m((PXR_NS::GfMatrix4d & (PXR_NS::GfMatrix4d::*)(double))
            &PXR_NS::GfMatrix4d::SetDiagonal, "SetDiagonal_00")
        .m((PXR_NS::GfMatrix4d & (PXR_NS::GfMatrix4d::*)(const PXR_NS::GfVec4d &))
            &PXR_NS::GfMatrix4d::SetDiagonal, "SetDiagonal_01")
        .m(&PXR_NS::GfMatrix4d::Get)
        .m((double * (PXR_NS::GfMatrix4d::*)())
            &PXR_NS::GfMatrix4d::data, "data_00")
        .m((const double * (PXR_NS::GfMatrix4d::*)() const)
            &PXR_NS::GfMatrix4d::data, "data_01")
        .m((double * (PXR_NS::GfMatrix4d::*)())
            &PXR_NS::GfMatrix4d::GetArray, "GetArray_00")
        .m((const double * (PXR_NS::GfMatrix4d::*)() const)
            &PXR_NS::GfMatrix4d::GetArray, "GetArray_01")
        .m((double * (PXR_NS::GfMatrix4d::*)(int))
            &PXR_NS::GfMatrix4d::operator[], "op_index_00")
        .m((const double * (PXR_NS::GfMatrix4d::*)(int) const)
            &PXR_NS::GfMatrix4d::operator[], "op_index_01")
        .m((bool (PXR_NS::GfMatrix4d::*)(const PXR_NS::GfMatrix4d &) const)
            &PXR_NS::GfMatrix4d::operator==, "op_eq_00")
        .m((bool (PXR_NS::GfMatrix4d::*)(const PXR_NS::GfMatrix4f &) const)
            &PXR_NS::GfMatrix4d::operator==, "op_eq_01")
        .m((bool (PXR_NS::GfMatrix4d::*)(const PXR_NS::GfMatrix4d &) const)
            &PXR_NS::GfMatrix4d::operator!=, "op_neq_00")
        .m((bool (PXR_NS::GfMatrix4d::*)(const PXR_NS::GfMatrix4f &) const)
            &PXR_NS::GfMatrix4d::operator!=, "op_neq_01")
        .m(&PXR_NS::GfMatrix4d::GetTranspose)
        .m(&PXR_NS::GfMatrix4d::GetInverse)
        .m(&PXR_NS::GfMatrix4d::GetDeterminant)
        .m(&PXR_NS::GfMatrix4d::SetRow3)
        .m(&PXR_NS::GfMatrix4d::GetRow3)
        .m(&PXR_NS::GfMatrix4d::GetDeterminant3)
        .m(&PXR_NS::GfMatrix4d::HasOrthogonalRows3)
        .m(&PXR_NS::GfMatrix4d::Orthonormalize)
        .m(&PXR_NS::GfMatrix4d::GetOrthonormalized)
        .m(&PXR_NS::GfMatrix4d::GetHandedness)
        .m(&PXR_NS::GfMatrix4d::IsRightHanded)
        .m(&PXR_NS::GfMatrix4d::IsLeftHanded)
        .m((PXR_NS::GfMatrix4d & (PXR_NS::GfMatrix4d::*)(const PXR_NS::GfMatrix4d &))
            &PXR_NS::GfMatrix4d::operator*=, "op_mul_assign_00")
        .m((PXR_NS::GfMatrix4d & (PXR_NS::GfMatrix4d::*)(double))
            &PXR_NS::GfMatrix4d::operator*=, "op_mul_assign_01")
        .m(&PXR_NS::GfMatrix4d::operator+=, "op_add_assign")
        .m(&PXR_NS::GfMatrix4d::operator-=, "op_sub_assign")
        .m((PXR_NS::GfMatrix4d & (PXR_NS::GfMatrix4d::*)(double))
            &PXR_NS::GfMatrix4d::SetScale, "SetScale_00")
        .m((PXR_NS::GfMatrix4d & (PXR_NS::GfMatrix4d::*)(const PXR_NS::GfVec3d &))
            &PXR_NS::GfMatrix4d::SetScale, "SetScale_01")
        .m(&PXR_NS::GfMatrix4d::RemoveScaleShear)
        .m((PXR_NS::GfMatrix4d & (PXR_NS::GfMatrix4d::*)(const PXR_NS::GfQuatd &))
            &PXR_NS::GfMatrix4d::SetRotate, "SetRotate_00")
        .m((PXR_NS::GfMatrix4d & (PXR_NS::GfMatrix4d::*)(const PXR_NS::GfRotation &))
            &PXR_NS::GfMatrix4d::SetRotate, "SetRotate_01")
        .m((PXR_NS::GfMatrix4d & (PXR_NS::GfMatrix4d::*)(const PXR_NS::GfMatrix3d &))
            &PXR_NS::GfMatrix4d::SetRotate, "SetRotate_02")
        .m((PXR_NS::GfMatrix4d & (PXR_NS::GfMatrix4d::*)(const PXR_NS::GfQuatd &))
            &PXR_NS::GfMatrix4d::SetRotateOnly, "SetRotateOnly_00")
        .m((PXR_NS::GfMatrix4d & (PXR_NS::GfMatrix4d::*)(const PXR_NS::GfRotation &))
            &PXR_NS::GfMatrix4d::SetRotateOnly, "SetRotateOnly_01")
        .m((PXR_NS::GfMatrix4d & (PXR_NS::GfMatrix4d::*)(const PXR_NS::GfMatrix3d &))
            &PXR_NS::GfMatrix4d::SetRotateOnly, "SetRotateOnly_02")
        .m(&PXR_NS::GfMatrix4d::SetTranslate)
        .m(&PXR_NS::GfMatrix4d::SetTranslateOnly)
        .m((PXR_NS::GfMatrix4d & (PXR_NS::GfMatrix4d::*)(const PXR_NS::GfRotation &, const PXR_NS::GfVec3d &))
            &PXR_NS::GfMatrix4d::SetTransform, "SetTransform_00")
        .m((PXR_NS::GfMatrix4d & (PXR_NS::GfMatrix4d::*)(const PXR_NS::GfMatrix3d &, const PXR_NS::GfVec3d &))
            &PXR_NS::GfMatrix4d::SetTransform, "SetTransform_01")
        .m((PXR_NS::GfMatrix4d & (PXR_NS::GfMatrix4d::*)(const PXR_NS::GfVec3d &, const PXR_NS::GfVec3d &, const PXR_NS::GfVec3d &))
            &PXR_NS::GfMatrix4d::SetLookAt, "SetLookAt_00")
        .m((PXR_NS::GfMatrix4d & (PXR_NS::GfMatrix4d::*)(const PXR_NS::GfVec3d &, const PXR_NS::GfRotation &))
            &PXR_NS::GfMatrix4d::SetLookAt, "SetLookAt_01")
        .m(&PXR_NS::GfMatrix4d::Factor)
        .m(&PXR_NS::GfMatrix4d::ExtractTranslation)
        .m(&PXR_NS::GfMatrix4d::ExtractRotation)
        .m(&PXR_NS::GfMatrix4d::ExtractRotationQuat)
        .m(&PXR_NS::GfMatrix4d::DecomposeRotation)
        .m(&PXR_NS::GfMatrix4d::ExtractRotationMatrix)
        .m((PXR_NS::GfVec3d (PXR_NS::GfMatrix4d::*)(const PXR_NS::GfVec3d &) const)
            &PXR_NS::GfMatrix4d::Transform, "Transform_00")
        .m((PXR_NS::GfVec3f (PXR_NS::GfMatrix4d::*)(const PXR_NS::GfVec3f &) const)
            &PXR_NS::GfMatrix4d::Transform, "Transform_01")
        .m((PXR_NS::GfVec3d (PXR_NS::GfMatrix4d::*)(const PXR_NS::GfVec3d &) const)
            &PXR_NS::GfMatrix4d::TransformDir, "TransformDir_00")
        .m((PXR_NS::GfVec3f (PXR_NS::GfMatrix4d::*)(const PXR_NS::GfVec3f &) const)
            &PXR_NS::GfMatrix4d::TransformDir, "TransformDir_01")
        .m((PXR_NS::GfVec3d (PXR_NS::GfMatrix4d::*)(const PXR_NS::GfVec3d &) const)
            &PXR_NS::GfMatrix4d::TransformAffine, "TransformAffine_00")
        .m((PXR_NS::GfVec3f (PXR_NS::GfMatrix4d::*)(const PXR_NS::GfVec3f &) const)
            &PXR_NS::GfMatrix4d::TransformAffine, "TransformAffine_01")
    ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfMatrix4d>>("Matrix4dArray")
        VTARRAY_METHODS(PXR_NS::GfMatrix4d)
    ;

    bbl::Class<std::vector<PXR_NS::VtMatrix4dArray>>("Matrix4dArrayVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::VtMatrix4dArray)
    ;

    bbl::Class<PXR_NS::GfMatrix2f>("Matrix2f")
        .replace_with<Matrix2f>()
        .ctor(bbl::Class<PXR_NS::GfMatrix2f>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfMatrix2f>::Ctor<float, float, float, float>("m00", "m01", "m10", "m11"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::GfMatrix2f>::Ctor<const float (*)[2]>("m"), "ctor_02")
        .ctor(bbl::Class<PXR_NS::GfMatrix2f>::Ctor<float>("s"), "ctor_03")
        .ctor(bbl::Class<PXR_NS::GfMatrix2f>::Ctor<int>("s"), "ctor_04")
        .ctor(bbl::Class<PXR_NS::GfMatrix2f>::Ctor<const PXR_NS::GfVec2f &>("v"), "ctor_05")
        .ctor(bbl::Class<PXR_NS::GfMatrix2f>::Ctor<const PXR_NS::GfMatrix2d &>("m"), "ctor_08")
        .m(&PXR_NS::GfMatrix2f::SetRow)
        .m(&PXR_NS::GfMatrix2f::SetColumn)
        .m(&PXR_NS::GfMatrix2f::GetRow)
        .m(&PXR_NS::GfMatrix2f::GetColumn)
        .m((PXR_NS::GfMatrix2f & (PXR_NS::GfMatrix2f::*)(float, float, float, float))
            &PXR_NS::GfMatrix2f::Set, "Set_00")
        .m((PXR_NS::GfMatrix2f & (PXR_NS::GfMatrix2f::*)(const float (*)[2]))
            &PXR_NS::GfMatrix2f::Set, "Set_01")
        .m(&PXR_NS::GfMatrix2f::SetIdentity)
        .m(&PXR_NS::GfMatrix2f::SetZero)
        .m((PXR_NS::GfMatrix2f & (PXR_NS::GfMatrix2f::*)(float))
            &PXR_NS::GfMatrix2f::SetDiagonal, "SetDiagonal_00")
        .m((PXR_NS::GfMatrix2f & (PXR_NS::GfMatrix2f::*)(const PXR_NS::GfVec2f &))
            &PXR_NS::GfMatrix2f::SetDiagonal, "SetDiagonal_01")
        .m(&PXR_NS::GfMatrix2f::Get)
        .m((float * (PXR_NS::GfMatrix2f::*)())
            &PXR_NS::GfMatrix2f::data, "data_00")
        .m((const float * (PXR_NS::GfMatrix2f::*)() const)
            &PXR_NS::GfMatrix2f::data, "data_01")
        .m((float * (PXR_NS::GfMatrix2f::*)())
            &PXR_NS::GfMatrix2f::GetArray, "GetArray_00")
        .m((const float * (PXR_NS::GfMatrix2f::*)() const)
            &PXR_NS::GfMatrix2f::GetArray, "GetArray_01")
        .m((float * (PXR_NS::GfMatrix2f::*)(int))
            &PXR_NS::GfMatrix2f::operator[], "op_index_00")
        .m((const float * (PXR_NS::GfMatrix2f::*)(int) const)
            &PXR_NS::GfMatrix2f::operator[], "op_index_01")
        .m((bool (PXR_NS::GfMatrix2f::*)(const PXR_NS::GfMatrix2d &) const)
            &PXR_NS::GfMatrix2f::operator==, "op_eq_00")
        .m((bool (PXR_NS::GfMatrix2f::*)(const PXR_NS::GfMatrix2f &) const)
            &PXR_NS::GfMatrix2f::operator==, "op_eq_01")
        .m((bool (PXR_NS::GfMatrix2f::*)(const PXR_NS::GfMatrix2d &) const)
            &PXR_NS::GfMatrix2f::operator!=, "op_neq_00")
        .m((bool (PXR_NS::GfMatrix2f::*)(const PXR_NS::GfMatrix2f &) const)
            &PXR_NS::GfMatrix2f::operator!=, "op_neq_01")
        .m(&PXR_NS::GfMatrix2f::GetTranspose)
        .m(&PXR_NS::GfMatrix2f::GetInverse)
        .m(&PXR_NS::GfMatrix2f::GetDeterminant)
        .m((PXR_NS::GfMatrix2f & (PXR_NS::GfMatrix2f::*)(const PXR_NS::GfMatrix2f &))
            &PXR_NS::GfMatrix2f::operator*=, "op_mul_assign_00")
        .m((PXR_NS::GfMatrix2f & (PXR_NS::GfMatrix2f::*)(double))
            &PXR_NS::GfMatrix2f::operator*=, "op_mul_assign_01")
        .m(&PXR_NS::GfMatrix2f::operator+=, "op_add_assign")
        .m(&PXR_NS::GfMatrix2f::operator-=, "op_sub_assign")
        ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfMatrix2f>>("Matrix2fArray")
        VTARRAY_METHODS(PXR_NS::GfMatrix2f)
    ;


    bbl::Class<PXR_NS::GfMatrix3f>("Matrix3f")
        .replace_with<Matrix3f>()
        .ctor(bbl::Class<PXR_NS::GfMatrix3f>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfMatrix3f>::Ctor<float, float, float, float, float, float, float, float, float>("m00", "m01", "m02", "m10", "m11", "m12", "m20", "m21", "m22"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::GfMatrix3f>::Ctor<const float (*)[3]>("m"), "ctor_02")
        .ctor(bbl::Class<PXR_NS::GfMatrix3f>::Ctor<float>("s"), "ctor_03")
        .ctor(bbl::Class<PXR_NS::GfMatrix3f>::Ctor<int>("s"), "ctor_04")
        .ctor(bbl::Class<PXR_NS::GfMatrix3f>::Ctor<const PXR_NS::GfVec3f &>("v"), "ctor_05")
        .ctor(bbl::Class<PXR_NS::GfMatrix3f>::Ctor<const PXR_NS::GfRotation &>("rot"), "ctor_08")
        .ctor(bbl::Class<PXR_NS::GfMatrix3f>::Ctor<const PXR_NS::GfQuatf &>("rot"), "ctor_09")
        .m(&PXR_NS::GfMatrix3f::SetRow)
        .m(&PXR_NS::GfMatrix3f::SetColumn)
        .m(&PXR_NS::GfMatrix3f::GetRow)
        .m(&PXR_NS::GfMatrix3f::GetColumn)
        .m((PXR_NS::GfMatrix3f & (PXR_NS::GfMatrix3f::*)(float, float, float, float, float, float, float, float, float))
            &PXR_NS::GfMatrix3f::Set, "Set_00")
        .m((PXR_NS::GfMatrix3f & (PXR_NS::GfMatrix3f::*)(const float (*)[3]))
            &PXR_NS::GfMatrix3f::Set, "Set_01")
        .m(&PXR_NS::GfMatrix3f::SetIdentity)
        .m(&PXR_NS::GfMatrix3f::SetZero)
        .m((PXR_NS::GfMatrix3f & (PXR_NS::GfMatrix3f::*)(float))
            &PXR_NS::GfMatrix3f::SetDiagonal, "SetDiagonal_00")
        .m((PXR_NS::GfMatrix3f & (PXR_NS::GfMatrix3f::*)(const PXR_NS::GfVec3f &))
            &PXR_NS::GfMatrix3f::SetDiagonal, "SetDiagonal_01")
        .m(&PXR_NS::GfMatrix3f::Get)
        .m((float * (PXR_NS::GfMatrix3f::*)())
            &PXR_NS::GfMatrix3f::data, "data_00")
        .m((const float * (PXR_NS::GfMatrix3f::*)() const)
            &PXR_NS::GfMatrix3f::data, "data_01")
        .m((float * (PXR_NS::GfMatrix3f::*)())
            &PXR_NS::GfMatrix3f::GetArray, "GetArray_00")
        .m((const float * (PXR_NS::GfMatrix3f::*)() const)
            &PXR_NS::GfMatrix3f::GetArray, "GetArray_01")
        .m((float * (PXR_NS::GfMatrix3f::*)(int))
            &PXR_NS::GfMatrix3f::operator[], "op_index_00")
        .m((const float * (PXR_NS::GfMatrix3f::*)(int) const)
            &PXR_NS::GfMatrix3f::operator[], "op_index_01")
        .m((bool (PXR_NS::GfMatrix3f::*)(const PXR_NS::GfMatrix3d &) const)
            &PXR_NS::GfMatrix3f::operator==, "op_eq_00")
        .m((bool (PXR_NS::GfMatrix3f::*)(const PXR_NS::GfMatrix3f &) const)
            &PXR_NS::GfMatrix3f::operator==, "op_eq_01")
        .m((bool (PXR_NS::GfMatrix3f::*)(const PXR_NS::GfMatrix3d &) const)
            &PXR_NS::GfMatrix3f::operator!=, "op_neq_00")
        .m((bool (PXR_NS::GfMatrix3f::*)(const PXR_NS::GfMatrix3f &) const)
            &PXR_NS::GfMatrix3f::operator!=, "op_neq_01")
        .m(&PXR_NS::GfMatrix3f::GetTranspose)
        .m(&PXR_NS::GfMatrix3f::GetInverse)
        .m(&PXR_NS::GfMatrix3f::GetDeterminant)
        .m(&PXR_NS::GfMatrix3f::Orthonormalize)
        .m(&PXR_NS::GfMatrix3f::GetOrthonormalized)
        .m(&PXR_NS::GfMatrix3f::GetHandedness)
        .m(&PXR_NS::GfMatrix3f::IsRightHanded)
        .m(&PXR_NS::GfMatrix3f::IsLeftHanded)
        .m((PXR_NS::GfMatrix3f & (PXR_NS::GfMatrix3f::*)(const PXR_NS::GfMatrix3f &))
            &PXR_NS::GfMatrix3f::operator*=, "op_mul_assign_00")
        .m((PXR_NS::GfMatrix3f & (PXR_NS::GfMatrix3f::*)(double))
            &PXR_NS::GfMatrix3f::operator*=, "op_mul_assign_01")
        .m(&PXR_NS::GfMatrix3f::operator+=, "op_add_assign")
        .m(&PXR_NS::GfMatrix3f::operator-=, "op_sub_assign")
        .m((PXR_NS::GfMatrix3f & (PXR_NS::GfMatrix3f::*)(float))
            &PXR_NS::GfMatrix3f::SetScale, "SetScale_00")
        .m((PXR_NS::GfMatrix3f & (PXR_NS::GfMatrix3f::*)(const PXR_NS::GfVec3f &))
            &PXR_NS::GfMatrix3f::SetScale, "SetScale_01")
        .m((PXR_NS::GfMatrix3f & (PXR_NS::GfMatrix3f::*)(const PXR_NS::GfQuatf &))
            &PXR_NS::GfMatrix3f::SetRotate, "SetRotate_00")
        .m((PXR_NS::GfMatrix3f & (PXR_NS::GfMatrix3f::*)(const PXR_NS::GfRotation &))
            &PXR_NS::GfMatrix3f::SetRotate, "SetRotate_01")
        .m(&PXR_NS::GfMatrix3f::ExtractRotation)
        .m(&PXR_NS::GfMatrix3f::DecomposeRotation)
        .m(&PXR_NS::GfMatrix3f::ExtractRotationQuaternion)
        ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfMatrix3f>>("Matrix3fArray")
        VTARRAY_METHODS(PXR_NS::GfMatrix3f)
    ;

    bbl::Class<PXR_NS::GfMatrix4f>("Matrix4f")
        .replace_with<Matrix4f>()
        .ctor(bbl::Class<PXR_NS::GfMatrix4f>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfMatrix4f>::Ctor<float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float>("m00", "m01", "m02", "m03", "m10", "m11", "m12", "m13", "m20", "m21", "m22", "m23", "m30", "m31", "m32", "m33"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::GfMatrix4f>::Ctor<const float (*)[4]>("m"), "ctor_02")
        .ctor(bbl::Class<PXR_NS::GfMatrix4f>::Ctor<float>("s"), "ctor_03")
        .ctor(bbl::Class<PXR_NS::GfMatrix4f>::Ctor<const PXR_NS::GfVec4f &>("v"), "ctor_04")
        .ctor(bbl::Class<PXR_NS::GfMatrix4f>::Ctor<const PXR_NS::GfRotation &, const PXR_NS::GfVec3f &>("rotate", "translate"), "ctor_09")
        .ctor(bbl::Class<PXR_NS::GfMatrix4f>::Ctor<const PXR_NS::GfMatrix3f &, const PXR_NS::GfVec3f &>("rotmx", "translate"), "ctor_10")
        .ctor(bbl::Class<PXR_NS::GfMatrix4f>::Ctor<const class PXR_NS::GfMatrix4d &>("m"), "ctor_11")
        .m(&PXR_NS::GfMatrix4f::SetRow)
        .m(&PXR_NS::GfMatrix4f::SetColumn)
        .m(&PXR_NS::GfMatrix4f::GetRow)
        .m(&PXR_NS::GfMatrix4f::GetColumn)
        .m((PXR_NS::GfMatrix4f & (PXR_NS::GfMatrix4f::*)(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float))
            &PXR_NS::GfMatrix4f::Set, "Set_00")
        .m((PXR_NS::GfMatrix4f & (PXR_NS::GfMatrix4f::*)(const float (*)[4]))
            &PXR_NS::GfMatrix4f::Set, "Set_01")
        .m(&PXR_NS::GfMatrix4f::SetIdentity)
        .m(&PXR_NS::GfMatrix4f::SetZero)
        .m((PXR_NS::GfMatrix4f & (PXR_NS::GfMatrix4f::*)(float))
            &PXR_NS::GfMatrix4f::SetDiagonal, "SetDiagonal_00")
        .m((PXR_NS::GfMatrix4f & (PXR_NS::GfMatrix4f::*)(const PXR_NS::GfVec4f &))
            &PXR_NS::GfMatrix4f::SetDiagonal, "SetDiagonal_01")
        .m(&PXR_NS::GfMatrix4f::Get)
        .m((float * (PXR_NS::GfMatrix4f::*)())
            &PXR_NS::GfMatrix4f::data, "data_00")
        .m((const float * (PXR_NS::GfMatrix4f::*)() const)
            &PXR_NS::GfMatrix4f::data, "data_01")
        .m((float * (PXR_NS::GfMatrix4f::*)())
            &PXR_NS::GfMatrix4f::GetArray, "GetArray_00")
        .m((const float * (PXR_NS::GfMatrix4f::*)() const)
            &PXR_NS::GfMatrix4f::GetArray, "GetArray_01")
        .m((float * (PXR_NS::GfMatrix4f::*)(int))
            &PXR_NS::GfMatrix4f::operator[], "op_index_00")
        .m((const float * (PXR_NS::GfMatrix4f::*)(int) const)
            &PXR_NS::GfMatrix4f::operator[], "op_index_01")
        .m((bool (PXR_NS::GfMatrix4f::*)(const PXR_NS::GfMatrix4d &) const)
            &PXR_NS::GfMatrix4f::operator==, "op_eq_00")
        .m((bool (PXR_NS::GfMatrix4f::*)(const PXR_NS::GfMatrix4f &) const)
            &PXR_NS::GfMatrix4f::operator==, "op_eq_01")
        .m((bool (PXR_NS::GfMatrix4f::*)(const PXR_NS::GfMatrix4d &) const)
            &PXR_NS::GfMatrix4f::operator!=, "op_neq_00")
        .m((bool (PXR_NS::GfMatrix4f::*)(const PXR_NS::GfMatrix4f &) const)
            &PXR_NS::GfMatrix4f::operator!=, "op_neq_01")
        .m(&PXR_NS::GfMatrix4f::GetTranspose)
        .m(&PXR_NS::GfMatrix4f::GetInverse)
        .m(&PXR_NS::GfMatrix4f::GetDeterminant)
        .m(&PXR_NS::GfMatrix4f::SetRow3)
        .m(&PXR_NS::GfMatrix4f::GetRow3)
        .m(&PXR_NS::GfMatrix4f::GetDeterminant3)
        .m(&PXR_NS::GfMatrix4f::HasOrthogonalRows3)
        .m(&PXR_NS::GfMatrix4f::Orthonormalize)
        .m(&PXR_NS::GfMatrix4f::GetOrthonormalized)
        .m(&PXR_NS::GfMatrix4f::GetHandedness)
        .m(&PXR_NS::GfMatrix4f::IsRightHanded)
        .m(&PXR_NS::GfMatrix4f::IsLeftHanded)
        .m((PXR_NS::GfMatrix4f & (PXR_NS::GfMatrix4f::*)(const PXR_NS::GfMatrix4f &))
            &PXR_NS::GfMatrix4f::operator*=, "op_mul_assign_00")
        .m((PXR_NS::GfMatrix4f & (PXR_NS::GfMatrix4f::*)(double))
            &PXR_NS::GfMatrix4f::operator*=, "op_mul_assign_01")
        .m(&PXR_NS::GfMatrix4f::operator+=, "op_add_assign")
        .m(&PXR_NS::GfMatrix4f::operator-=, "op_sub_assign")
        .m((PXR_NS::GfMatrix4f & (PXR_NS::GfMatrix4f::*)(float))
            &PXR_NS::GfMatrix4f::SetScale, "SetScale_00")
        .m((PXR_NS::GfMatrix4f & (PXR_NS::GfMatrix4f::*)(const PXR_NS::GfVec3f &))
            &PXR_NS::GfMatrix4f::SetScale, "SetScale_01")
        .m(&PXR_NS::GfMatrix4f::RemoveScaleShear)
        .m((PXR_NS::GfMatrix4f & (PXR_NS::GfMatrix4f::*)(const PXR_NS::GfQuatf &))
            &PXR_NS::GfMatrix4f::SetRotate, "SetRotate_00")
        .m((PXR_NS::GfMatrix4f & (PXR_NS::GfMatrix4f::*)(const PXR_NS::GfRotation &))
            &PXR_NS::GfMatrix4f::SetRotate, "SetRotate_01")
        .m((PXR_NS::GfMatrix4f & (PXR_NS::GfMatrix4f::*)(const PXR_NS::GfMatrix3f &))
            &PXR_NS::GfMatrix4f::SetRotate, "SetRotate_02")
        .m((PXR_NS::GfMatrix4f & (PXR_NS::GfMatrix4f::*)(const PXR_NS::GfQuatf &))
            &PXR_NS::GfMatrix4f::SetRotateOnly, "SetRotateOnly_00")
        .m((PXR_NS::GfMatrix4f & (PXR_NS::GfMatrix4f::*)(const PXR_NS::GfRotation &))
            &PXR_NS::GfMatrix4f::SetRotateOnly, "SetRotateOnly_01")
        .m((PXR_NS::GfMatrix4f & (PXR_NS::GfMatrix4f::*)(const PXR_NS::GfMatrix3f &))
            &PXR_NS::GfMatrix4f::SetRotateOnly, "SetRotateOnly_02")
        .m(&PXR_NS::GfMatrix4f::SetTranslate)
        .m(&PXR_NS::GfMatrix4f::SetTranslateOnly)
        .m((PXR_NS::GfMatrix4f & (PXR_NS::GfMatrix4f::*)(const PXR_NS::GfRotation &, const PXR_NS::GfVec3f &))
            &PXR_NS::GfMatrix4f::SetTransform, "SetTransform_00")
        .m((PXR_NS::GfMatrix4f & (PXR_NS::GfMatrix4f::*)(const PXR_NS::GfMatrix3f &, const PXR_NS::GfVec3f &))
            &PXR_NS::GfMatrix4f::SetTransform, "SetTransform_01")
        .m((PXR_NS::GfMatrix4f & (PXR_NS::GfMatrix4f::*)(const PXR_NS::GfVec3f &, const PXR_NS::GfVec3f &, const PXR_NS::GfVec3f &))
            &PXR_NS::GfMatrix4f::SetLookAt, "SetLookAt_00")
        .m((PXR_NS::GfMatrix4f & (PXR_NS::GfMatrix4f::*)(const PXR_NS::GfVec3f &, const PXR_NS::GfRotation &))
            &PXR_NS::GfMatrix4f::SetLookAt, "SetLookAt_01")
        .m(&PXR_NS::GfMatrix4f::Factor)
        .m(&PXR_NS::GfMatrix4f::ExtractTranslation)
        .m(&PXR_NS::GfMatrix4f::ExtractRotation)
        .m(&PXR_NS::GfMatrix4f::ExtractRotationQuat)
        .m(&PXR_NS::GfMatrix4f::DecomposeRotation)
        .m(&PXR_NS::GfMatrix4f::ExtractRotationMatrix)
        .m((PXR_NS::GfVec3d (PXR_NS::GfMatrix4f::*)(const PXR_NS::GfVec3d &) const)
            &PXR_NS::GfMatrix4f::Transform, "Transform_00")
        .m((PXR_NS::GfVec3f (PXR_NS::GfMatrix4f::*)(const PXR_NS::GfVec3f &) const)
            &PXR_NS::GfMatrix4f::Transform, "Transform_01")
        .m((PXR_NS::GfVec3d (PXR_NS::GfMatrix4f::*)(const PXR_NS::GfVec3d &) const)
            &PXR_NS::GfMatrix4f::TransformDir, "TransformDir_00")
        .m((PXR_NS::GfVec3f (PXR_NS::GfMatrix4f::*)(const PXR_NS::GfVec3f &) const)
            &PXR_NS::GfMatrix4f::TransformDir, "TransformDir_01")
        .m((PXR_NS::GfVec3d (PXR_NS::GfMatrix4f::*)(const PXR_NS::GfVec3d &) const)
            &PXR_NS::GfMatrix4f::TransformAffine, "TransformAffine_00")
        .m((PXR_NS::GfVec3f (PXR_NS::GfMatrix4f::*)(const PXR_NS::GfVec3f &) const)
            &PXR_NS::GfMatrix4f::TransformAffine, "TransformAffine_01")
        .m((PXR_NS::GfMatrix4f & (PXR_NS::GfMatrix4f::*)(const PXR_NS::GfMatrix4f &))
            &PXR_NS::GfMatrix4f::operator=, "op_assign_00")
        .m((PXR_NS::GfMatrix4f & (PXR_NS::GfMatrix4f::*)(PXR_NS::GfMatrix4f &&))
            &PXR_NS::GfMatrix4f::operator=, "op_assign_01")
    ;

    bbl::Class<PXR_NS::VtArray<PXR_NS::GfMatrix4f>>("Matrix4fArray")
        VTARRAY_METHODS(PXR_NS::GfMatrix4f)
    ;

    bbl::Class<PXR_NS::GfMultiInterval>("MultiInterval")
        .ctor(bbl::Class<PXR_NS::GfMultiInterval>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfMultiInterval>::Ctor<const PXR_NS::GfInterval &>("i"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::GfMultiInterval>::Ctor<const std::vector<PXR_NS::GfInterval> &>("intervals"), "ctor_02")
        .m(&PXR_NS::GfMultiInterval::operator==, "op_eq")
        .m(&PXR_NS::GfMultiInterval::operator!=, "op_neq")
        .m(&PXR_NS::GfMultiInterval::operator<, "op_lt")
        .m(&PXR_NS::GfMultiInterval::operator>=, "op_gte")
        .m(&PXR_NS::GfMultiInterval::operator>, "op_gt")
        .m(&PXR_NS::GfMultiInterval::operator<=, "op_lte")
        .m(&PXR_NS::GfMultiInterval::Hash)
        .m(&PXR_NS::GfMultiInterval::IsEmpty)
        .m(&PXR_NS::GfMultiInterval::GetSize)
        .m(&PXR_NS::GfMultiInterval::GetBounds)
        .m((bool (PXR_NS::GfMultiInterval::*)(double) const)
            &PXR_NS::GfMultiInterval::Contains, "Contains_00")
        .m((bool (PXR_NS::GfMultiInterval::*)(const PXR_NS::GfInterval &) const)
            &PXR_NS::GfMultiInterval::Contains, "Contains_01")
        .m((bool (PXR_NS::GfMultiInterval::*)(const PXR_NS::GfMultiInterval &) const)
            &PXR_NS::GfMultiInterval::Contains, "Contains_02")
        .m(&PXR_NS::GfMultiInterval::Clear)
        .m((void (PXR_NS::GfMultiInterval::*)(const PXR_NS::GfInterval &))
            &PXR_NS::GfMultiInterval::Add, "Add_00")
        .m((void (PXR_NS::GfMultiInterval::*)(const PXR_NS::GfMultiInterval &))
            &PXR_NS::GfMultiInterval::Add, "Add_01")
        .m(&PXR_NS::GfMultiInterval::ArithmeticAdd)
        .m((void (PXR_NS::GfMultiInterval::*)(const PXR_NS::GfInterval &))
            &PXR_NS::GfMultiInterval::Remove, "Remove_00")
        .m((void (PXR_NS::GfMultiInterval::*)(const PXR_NS::GfMultiInterval &))
            &PXR_NS::GfMultiInterval::Remove, "Remove_01")
        .m((void (PXR_NS::GfMultiInterval::*)(const PXR_NS::GfInterval &))
            &PXR_NS::GfMultiInterval::Intersect, "Intersect_00")
        .m((void (PXR_NS::GfMultiInterval::*)(const PXR_NS::GfMultiInterval &))
            &PXR_NS::GfMultiInterval::Intersect, "Intersect_01")
        .m(&PXR_NS::GfMultiInterval::GetComplement)
        .m(&PXR_NS::GfMultiInterval::begin)
        .m(&PXR_NS::GfMultiInterval::end)
        .m(&PXR_NS::GfMultiInterval::lower_bound)
        .m(&PXR_NS::GfMultiInterval::upper_bound)
        .m(&PXR_NS::GfMultiInterval::GetNextNonContainingInterval)
        .m(&PXR_NS::GfMultiInterval::GetPriorNonContainingInterval)
        .m(&PXR_NS::GfMultiInterval::GetContainingInterval)
        .m(&PXR_NS::GfMultiInterval::GetFullInterval)
        .m(&PXR_NS::GfMultiInterval::swap)
        .m((PXR_NS::GfMultiInterval & (PXR_NS::GfMultiInterval::*)(const PXR_NS::GfMultiInterval &))
            &PXR_NS::GfMultiInterval::operator=, "op_assign_00")
        .m((PXR_NS::GfMultiInterval & (PXR_NS::GfMultiInterval::*)(PXR_NS::GfMultiInterval &&))
            &PXR_NS::GfMultiInterval::operator=, "op_assign_01")
    ;

    bbl::Class<PXR_NS::GfMultiInterval::Set>("MultiIntervalSet")
    ;

    bbl::Class<PXR_NS::GfMultiInterval::iterator>("MultiIntervalIterator")
    ;

    bbl::Class<PXR_NS::GfPlane>("Plane")
        .ctor(bbl::Class<PXR_NS::GfPlane>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfPlane>::Ctor<const PXR_NS::GfVec3d &, double>("normal", "distanceToOrigin"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::GfPlane>::Ctor<const PXR_NS::GfVec3d &, const PXR_NS::GfVec3d &>("normal", "point"), "ctor_02")
        .ctor(bbl::Class<PXR_NS::GfPlane>::Ctor<const PXR_NS::GfVec3d &, const PXR_NS::GfVec3d &, const PXR_NS::GfVec3d &>("p0", "p1", "p2"), "ctor_03")
        .ctor(bbl::Class<PXR_NS::GfPlane>::Ctor<const PXR_NS::GfVec4d &>("eqn"), "ctor_04")
        .m((void (PXR_NS::GfPlane::*)(const PXR_NS::GfVec3d &, double))
            &PXR_NS::GfPlane::Set, "Set_00")
        .m((void (PXR_NS::GfPlane::*)(const PXR_NS::GfVec3d &, const PXR_NS::GfVec3d &))
            &PXR_NS::GfPlane::Set, "Set_01")
        .m((void (PXR_NS::GfPlane::*)(const PXR_NS::GfVec3d &, const PXR_NS::GfVec3d &, const PXR_NS::GfVec3d &))
            &PXR_NS::GfPlane::Set, "Set_02")
        .m((void (PXR_NS::GfPlane::*)(const PXR_NS::GfVec4d &))
            &PXR_NS::GfPlane::Set, "Set_03")
        .m(&PXR_NS::GfPlane::GetNormal)
        .m(&PXR_NS::GfPlane::GetDistanceFromOrigin)
        .m(&PXR_NS::GfPlane::GetEquation)
        .m(&PXR_NS::GfPlane::operator==, "op_eq")
        .m(&PXR_NS::GfPlane::operator!=, "op_neq")
        .m(&PXR_NS::GfPlane::GetDistance)
        .m(&PXR_NS::GfPlane::Project)
        .m(&PXR_NS::GfPlane::Transform)
        .m(&PXR_NS::GfPlane::Reorient)
        .m((bool (PXR_NS::GfPlane::*)(const PXR_NS::GfRange3d &) const)
            &PXR_NS::GfPlane::IntersectsPositiveHalfSpace, "IntersectsPositiveHalfSpace_00")
        .m((bool (PXR_NS::GfPlane::*)(const PXR_NS::GfVec3d &) const)
            &PXR_NS::GfPlane::IntersectsPositiveHalfSpace, "IntersectsPositiveHalfSpace_01")
    ;

    bbl::Class<PXR_NS::GfQuaternion>("Quaternion")
        .ctor(bbl::Class<PXR_NS::GfQuaternion>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfQuaternion>::Ctor<int>("realVal"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::GfQuaternion>::Ctor<double, const PXR_NS::GfVec3d &>("real", "imaginary"), "ctor_02")
        .m(&PXR_NS::GfQuaternion::SetReal)
        .m(&PXR_NS::GfQuaternion::SetImaginary)
        .m(&PXR_NS::GfQuaternion::GetReal)
        .m(&PXR_NS::GfQuaternion::GetImaginary)
        .m(&PXR_NS::GfQuaternion::GetZero)
        .m(&PXR_NS::GfQuaternion::GetIdentity)
        .m(&PXR_NS::GfQuaternion::GetLength)
        .m(&PXR_NS::GfQuaternion::GetNormalized)
        .m(&PXR_NS::GfQuaternion::Normalize)
        .m(&PXR_NS::GfQuaternion::GetInverse)
        .m(&PXR_NS::GfQuaternion::operator==, "op_eq")
        .m(&PXR_NS::GfQuaternion::operator!=, "op_neq")
        .m((PXR_NS::GfQuaternion & (PXR_NS::GfQuaternion::*)(const PXR_NS::GfQuaternion &))
            &PXR_NS::GfQuaternion::operator*=, "op_mul_assign_00")
        .m((PXR_NS::GfQuaternion & (PXR_NS::GfQuaternion::*)(double))
            &PXR_NS::GfQuaternion::operator*=, "op_mul_assign_01")
        .m(&PXR_NS::GfQuaternion::operator/=, "op_div_assign")
        .m(&PXR_NS::GfQuaternion::operator+=, "op_add_assign")
        .m(&PXR_NS::GfQuaternion::operator-=, "op_sub_assign")
    ;

    bbl::fn((double (*)(const PXR_NS::GfQuaternion &, const PXR_NS::GfQuaternion &))
            &PXR_NS::GfDot, "GfDot_18");


    bbl::Class<PXR_NS::GfQuatd>("Quatd")
        .replace_with<Vec4d>()
        .ctor(bbl::Class<PXR_NS::GfQuatd>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfQuatd>::Ctor<double>("realVal"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::GfQuatd>::Ctor<double, double, double, double>("real", "i", "j", "k"), "ctor_02")
        .ctor(bbl::Class<PXR_NS::GfQuatd>::Ctor<double, const PXR_NS::GfVec3d &>("real", "imaginary"), "ctor_03")
        .ctor(bbl::Class<PXR_NS::GfQuatd>::Ctor<const class PXR_NS::GfQuatf &>("other"), "ctor_04")
        .ctor(bbl::Class<PXR_NS::GfQuatd>::Ctor<const class PXR_NS::GfQuath &>("other"), "ctor_05")
        .m(&PXR_NS::GfQuatd::GetZero)
        .m(&PXR_NS::GfQuatd::GetIdentity)
        .m(&PXR_NS::GfQuatd::GetReal)
        .m(&PXR_NS::GfQuatd::SetReal)
        .m(&PXR_NS::GfQuatd::GetImaginary)
        .m((void (PXR_NS::GfQuatd::*)(const PXR_NS::GfVec3d &))
            &PXR_NS::GfQuatd::SetImaginary, "SetImaginary_00")
        .m((void (PXR_NS::GfQuatd::*)(double, double, double))
            &PXR_NS::GfQuatd::SetImaginary, "SetImaginary_01")
        .m(&PXR_NS::GfQuatd::GetLength)
        .m(&PXR_NS::GfQuatd::GetNormalized)
        .m(&PXR_NS::GfQuatd::Normalize)
        .m(&PXR_NS::GfQuatd::GetConjugate)
        .m(&PXR_NS::GfQuatd::GetInverse)
        .m(&PXR_NS::GfQuatd::Transform)
        .m(&PXR_NS::GfQuatd::operator-, "op_sub")
        .m(&PXR_NS::GfQuatd::operator==, "op_eq")
        .m(&PXR_NS::GfQuatd::operator!=, "op_neq")
        .m((PXR_NS::GfQuatd & (PXR_NS::GfQuatd::*)(const PXR_NS::GfQuatd &))
            &PXR_NS::GfQuatd::operator*=, "op_mul_assign_00")
        .m((PXR_NS::GfQuatd & (PXR_NS::GfQuatd::*)(double))
            &PXR_NS::GfQuatd::operator*=, "op_mul_assign_01")
        .m(&PXR_NS::GfQuatd::operator/=, "op_div_assign")
        .m(&PXR_NS::GfQuatd::operator+=, "op_add_assign")
        .m(&PXR_NS::GfQuatd::operator-=, "op_sub_assign")
        .m((PXR_NS::GfQuatd & (PXR_NS::GfQuatd::*)(const PXR_NS::GfQuatd &))
            &PXR_NS::GfQuatd::operator=, "op_assign_00")
        .m((PXR_NS::GfQuatd & (PXR_NS::GfQuatd::*)(PXR_NS::GfQuatd &&))
            &PXR_NS::GfQuatd::operator=, "op_assign_01")
    ;

    bbl::fn((double (*)(const PXR_NS::GfQuatd &, const PXR_NS::GfQuatd &))
            &PXR_NS::GfDot, "GfDot_quatd");



    bbl::Class<PXR_NS::VtArray<PXR_NS::GfQuatd>>("QuatdArray")
        VTARRAY_METHODS(PXR_NS::GfQuatd)
    ;

    bbl::Class<PXR_NS::GfQuatf>("Quatf")
        .replace_with<Vec4f>()
        .ctor(bbl::Class<PXR_NS::GfQuatf>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfQuatf>::Ctor<float>("realVal"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::GfQuatf>::Ctor<float, float, float, float>("real", "i", "j", "k"), "ctor_02")
        .ctor(bbl::Class<PXR_NS::GfQuatf>::Ctor<float, const PXR_NS::GfVec3f &>("real", "imaginary"), "ctor_03")
        .ctor(bbl::Class<PXR_NS::GfQuatf>::Ctor<const class PXR_NS::GfQuatd &>("other"), "ctor_04")
        .ctor(bbl::Class<PXR_NS::GfQuatf>::Ctor<const class PXR_NS::GfQuath &>("other"), "ctor_05")
        .m(&PXR_NS::GfQuatf::GetZero)
        .m(&PXR_NS::GfQuatf::GetIdentity)
        .m(&PXR_NS::GfQuatf::GetReal)
        .m(&PXR_NS::GfQuatf::SetReal)
        .m(&PXR_NS::GfQuatf::GetImaginary)
        .m((void (PXR_NS::GfQuatf::*)(const PXR_NS::GfVec3f &))
            &PXR_NS::GfQuatf::SetImaginary, "SetImaginary_00")
        .m((void (PXR_NS::GfQuatf::*)(float, float, float))
            &PXR_NS::GfQuatf::SetImaginary, "SetImaginary_01")
        .m(&PXR_NS::GfQuatf::GetLength)
        .m(&PXR_NS::GfQuatf::GetNormalized)
        .m(&PXR_NS::GfQuatf::Normalize)
        .m(&PXR_NS::GfQuatf::GetConjugate)
        .m(&PXR_NS::GfQuatf::GetInverse)
        .m(&PXR_NS::GfQuatf::Transform)
        .m(&PXR_NS::GfQuatf::operator-, "op_sub")
        .m(&PXR_NS::GfQuatf::operator==, "op_eq")
        .m(&PXR_NS::GfQuatf::operator!=, "op_neq")
        .m((PXR_NS::GfQuatf & (PXR_NS::GfQuatf::*)(const PXR_NS::GfQuatf &))
            &PXR_NS::GfQuatf::operator*=, "op_mul_assign_00")
        .m((PXR_NS::GfQuatf & (PXR_NS::GfQuatf::*)(float))
            &PXR_NS::GfQuatf::operator*=, "op_mul_assign_01")
        .m(&PXR_NS::GfQuatf::operator/=, "op_div_assign")
        .m(&PXR_NS::GfQuatf::operator+=, "op_add_assign")
        .m(&PXR_NS::GfQuatf::operator-=, "op_sub_assign")
        .m((PXR_NS::GfQuatf & (PXR_NS::GfQuatf::*)(const PXR_NS::GfQuatf &))
            &PXR_NS::GfQuatf::operator=, "op_assign_00")
        .m((PXR_NS::GfQuatf & (PXR_NS::GfQuatf::*)(PXR_NS::GfQuatf &&))
            &PXR_NS::GfQuatf::operator=, "op_assign_01")
    ;

    bbl::fn((float (*)(const PXR_NS::GfQuatf &, const PXR_NS::GfQuatf &))
            &PXR_NS::GfDot, "GfDot_quatf");


    bbl::Class<PXR_NS::VtArray<PXR_NS::GfQuatf>>("QuatfArray")
        VTARRAY_METHODS(PXR_NS::GfQuatf)
    ;

    bbl::Class<PXR_NS::GfQuath>("Quath")
        .replace_with<Vec4h>()
        .ctor(bbl::Class<PXR_NS::GfQuath>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfQuath>::Ctor<PXR_NS::GfHalf>("realVal"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::GfQuath>::Ctor<PXR_NS::GfHalf, PXR_NS::GfHalf, PXR_NS::GfHalf, PXR_NS::GfHalf>("real", "i", "j", "k"), "ctor_02")
        .ctor(bbl::Class<PXR_NS::GfQuath>::Ctor<PXR_NS::GfHalf, const PXR_NS::GfVec3h &>("real", "imaginary"), "ctor_03")
        .ctor(bbl::Class<PXR_NS::GfQuath>::Ctor<const class PXR_NS::GfQuatd &>("other"), "ctor_04")
        .ctor(bbl::Class<PXR_NS::GfQuath>::Ctor<const class PXR_NS::GfQuatf &>("other"), "ctor_05")
        .m(&PXR_NS::GfQuath::GetZero)
        .m(&PXR_NS::GfQuath::GetIdentity)
        .m(&PXR_NS::GfQuath::GetReal)
        .m(&PXR_NS::GfQuath::SetReal)
        .m(&PXR_NS::GfQuath::GetImaginary)
        .m((void (PXR_NS::GfQuath::*)(const PXR_NS::GfVec3h &))
            &PXR_NS::GfQuath::SetImaginary, "SetImaginary_00")
        .m((void (PXR_NS::GfQuath::*)(PXR_NS::GfHalf, PXR_NS::GfHalf, PXR_NS::GfHalf))
            &PXR_NS::GfQuath::SetImaginary, "SetImaginary_01")
        .m(&PXR_NS::GfQuath::GetLength)
        .m(&PXR_NS::GfQuath::GetNormalized)
        .m(&PXR_NS::GfQuath::Normalize)
        .m(&PXR_NS::GfQuath::GetConjugate)
        .m(&PXR_NS::GfQuath::GetInverse)
        .m(&PXR_NS::GfQuath::Transform)
        .m(&PXR_NS::GfQuath::operator-, "op_sub")
        .m(&PXR_NS::GfQuath::operator==, "op_eq")
        .m(&PXR_NS::GfQuath::operator!=, "op_neq")
        .m((PXR_NS::GfQuath & (PXR_NS::GfQuath::*)(const PXR_NS::GfQuath &))
            &PXR_NS::GfQuath::operator*=, "op_mul_assign_00")
        .m((PXR_NS::GfQuath & (PXR_NS::GfQuath::*)(PXR_NS::GfHalf))
            &PXR_NS::GfQuath::operator*=, "op_mul_assign_01")
        .m(&PXR_NS::GfQuath::operator/=, "op_div_assign")
        .m(&PXR_NS::GfQuath::operator+=, "op_add_assign")
        .m(&PXR_NS::GfQuath::operator-=, "op_sub_assign")
        .m((PXR_NS::GfQuath & (PXR_NS::GfQuath::*)(const PXR_NS::GfQuath &))
            &PXR_NS::GfQuath::operator=, "op_assign_00")
        .m((PXR_NS::GfQuath & (PXR_NS::GfQuath::*)(PXR_NS::GfQuath &&))
            &PXR_NS::GfQuath::operator=, "op_assign_01")
    ;

    bbl::fn((PXR_NS::GfHalf (*)(const PXR_NS::GfQuath &, const PXR_NS::GfQuath &))
            &PXR_NS::GfDot, "GfDot_quath");


    bbl::Class<PXR_NS::VtArray<PXR_NS::GfQuath>>("QuathArray")
        VTARRAY_METHODS(PXR_NS::GfQuath)
    ;

    bbl::Class<PXR_NS::GfRange1d>("Range1d")
        .replace_with<Range1d>()
        .ctor(bbl::Class<PXR_NS::GfRange1d>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfRange1d>::Ctor<double, double>("min", "max"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::GfRange1d>::Ctor<const class PXR_NS::GfRange1f &>("other"), "ctor_02")
        .m(&PXR_NS::GfRange1d::SetEmpty)
        .m(&PXR_NS::GfRange1d::GetMin)
        .m(&PXR_NS::GfRange1d::GetMax)
        .m(&PXR_NS::GfRange1d::GetSize)
        .m(&PXR_NS::GfRange1d::GetMidpoint)
        .m(&PXR_NS::GfRange1d::SetMin)
        .m(&PXR_NS::GfRange1d::SetMax)
        .m(&PXR_NS::GfRange1d::IsEmpty)
        .m((void (PXR_NS::GfRange1d::*)(double))
            &PXR_NS::GfRange1d::ExtendBy, "ExtendBy_00")
        .m((void (PXR_NS::GfRange1d::*)(const PXR_NS::GfRange1d &))
            &PXR_NS::GfRange1d::ExtendBy, "ExtendBy_01")
        .m((bool (PXR_NS::GfRange1d::*)(double) const)
            &PXR_NS::GfRange1d::Contains, "Contains_00")
        .m((bool (PXR_NS::GfRange1d::*)(const PXR_NS::GfRange1d &) const)
            &PXR_NS::GfRange1d::Contains, "Contains_01")
        .m((bool (PXR_NS::GfRange1d::*)(double) const)
            &PXR_NS::GfRange1d::IsInside, "IsInside_00")
        .m((bool (PXR_NS::GfRange1d::*)(const PXR_NS::GfRange1d &) const)
            &PXR_NS::GfRange1d::IsInside, "IsInside_01")
        .m(&PXR_NS::GfRange1d::IsOutside)
        .m(&PXR_NS::GfRange1d::GetUnion)
        .m((const PXR_NS::GfRange1d & (PXR_NS::GfRange1d::*)(const PXR_NS::GfRange1d &))
            &PXR_NS::GfRange1d::UnionWith, "UnionWith_00")
        .m((const PXR_NS::GfRange1d & (PXR_NS::GfRange1d::*)(double))
            &PXR_NS::GfRange1d::UnionWith, "UnionWith_01")
        .m((PXR_NS::GfRange1d (*)(const PXR_NS::GfRange1d &, const PXR_NS::GfRange1d &))
            &PXR_NS::GfRange1d::Union, "Union_00")
        .m((const PXR_NS::GfRange1d & (PXR_NS::GfRange1d::*)(const PXR_NS::GfRange1d &))
            &PXR_NS::GfRange1d::Union, "Union_01")
        .m((const PXR_NS::GfRange1d & (PXR_NS::GfRange1d::*)(double))
            &PXR_NS::GfRange1d::Union, "Union_02")
        .m(&PXR_NS::GfRange1d::GetIntersection)
        .m((PXR_NS::GfRange1d (*)(const PXR_NS::GfRange1d &, const PXR_NS::GfRange1d &))
            &PXR_NS::GfRange1d::Intersection, "Intersection_00")
        .m((const PXR_NS::GfRange1d & (PXR_NS::GfRange1d::*)(const PXR_NS::GfRange1d &))
            &PXR_NS::GfRange1d::Intersection, "Intersection_01")
        .m(&PXR_NS::GfRange1d::IntersectWith)
        .m(&PXR_NS::GfRange1d::operator+=, "op_add_assign")
        .m(&PXR_NS::GfRange1d::operator-=, "op_sub_assign")
        .m(&PXR_NS::GfRange1d::operator*=, "op_mul_assign")
        .m(&PXR_NS::GfRange1d::operator/=, "op_div_assign")
        .m(&PXR_NS::GfRange1d::operator+, "op_add")
        .m(&PXR_NS::GfRange1d::operator-, "op_sub")
        .m((bool (PXR_NS::GfRange1d::*)(const PXR_NS::GfRange1d &) const)
            &PXR_NS::GfRange1d::operator==, "op_eq_00")
        .m((bool (PXR_NS::GfRange1d::*)(const PXR_NS::GfRange1f &) const)
            &PXR_NS::GfRange1d::operator==, "op_eq_01")
        .m((bool (PXR_NS::GfRange1d::*)(const PXR_NS::GfRange1d &) const)
            &PXR_NS::GfRange1d::operator!=, "op_neq_00")
        .m((bool (PXR_NS::GfRange1d::*)(const PXR_NS::GfRange1f &) const)
            &PXR_NS::GfRange1d::operator!=, "op_neq_01")
        .m(&PXR_NS::GfRange1d::GetDistanceSquared)
        .m((PXR_NS::GfRange1d & (PXR_NS::GfRange1d::*)(const PXR_NS::GfRange1d &))
            &PXR_NS::GfRange1d::operator=, "op_assign_00")
        .m((PXR_NS::GfRange1d & (PXR_NS::GfRange1d::*)(PXR_NS::GfRange1d &&))
            &PXR_NS::GfRange1d::operator=, "op_assign_01")
    ;

    bbl::Class<PXR_NS::GfRange1f>("Range1f")
        .replace_with<Range1f>()
        .ctor(bbl::Class<PXR_NS::GfRange1f>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfRange1f>::Ctor<float, float>("min", "max"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::GfRange1f>::Ctor<const class PXR_NS::GfRange1d &>("other"), "ctor_02")
        .m(&PXR_NS::GfRange1f::SetEmpty)
        .m(&PXR_NS::GfRange1f::GetMin)
        .m(&PXR_NS::GfRange1f::GetMax)
        .m(&PXR_NS::GfRange1f::GetSize)
        .m(&PXR_NS::GfRange1f::GetMidpoint)
        .m(&PXR_NS::GfRange1f::SetMin)
        .m(&PXR_NS::GfRange1f::SetMax)
        .m(&PXR_NS::GfRange1f::IsEmpty)
        .m((void (PXR_NS::GfRange1f::*)(float))
            &PXR_NS::GfRange1f::ExtendBy, "ExtendBy_00")
        .m((void (PXR_NS::GfRange1f::*)(const PXR_NS::GfRange1f &))
            &PXR_NS::GfRange1f::ExtendBy, "ExtendBy_01")
        .m((bool (PXR_NS::GfRange1f::*)(float) const)
            &PXR_NS::GfRange1f::Contains, "Contains_00")
        .m((bool (PXR_NS::GfRange1f::*)(const PXR_NS::GfRange1f &) const)
            &PXR_NS::GfRange1f::Contains, "Contains_01")
        .m((bool (PXR_NS::GfRange1f::*)(float) const)
            &PXR_NS::GfRange1f::IsInside, "IsInside_00")
        .m((bool (PXR_NS::GfRange1f::*)(const PXR_NS::GfRange1f &) const)
            &PXR_NS::GfRange1f::IsInside, "IsInside_01")
        .m(&PXR_NS::GfRange1f::IsOutside)
        .m(&PXR_NS::GfRange1f::GetUnion)
        .m((const PXR_NS::GfRange1f & (PXR_NS::GfRange1f::*)(const PXR_NS::GfRange1f &))
            &PXR_NS::GfRange1f::UnionWith, "UnionWith_00")
        .m((const PXR_NS::GfRange1f & (PXR_NS::GfRange1f::*)(float))
            &PXR_NS::GfRange1f::UnionWith, "UnionWith_01")
        .m((PXR_NS::GfRange1f (*)(const PXR_NS::GfRange1f &, const PXR_NS::GfRange1f &))
            &PXR_NS::GfRange1f::Union, "Union_00")
        .m((const PXR_NS::GfRange1f & (PXR_NS::GfRange1f::*)(const PXR_NS::GfRange1f &))
            &PXR_NS::GfRange1f::Union, "Union_01")
        .m((const PXR_NS::GfRange1f & (PXR_NS::GfRange1f::*)(float))
            &PXR_NS::GfRange1f::Union, "Union_02")
        .m(&PXR_NS::GfRange1f::GetIntersection)
        .m((PXR_NS::GfRange1f (*)(const PXR_NS::GfRange1f &, const PXR_NS::GfRange1f &))
            &PXR_NS::GfRange1f::Intersection, "Intersection_00")
        .m((const PXR_NS::GfRange1f & (PXR_NS::GfRange1f::*)(const PXR_NS::GfRange1f &))
            &PXR_NS::GfRange1f::Intersection, "Intersection_01")
        .m(&PXR_NS::GfRange1f::IntersectWith)
        .m(&PXR_NS::GfRange1f::operator+=, "op_add_assign")
        .m(&PXR_NS::GfRange1f::operator-=, "op_sub_assign")
        .m(&PXR_NS::GfRange1f::operator*=, "op_mul_assign")
        .m(&PXR_NS::GfRange1f::operator/=, "op_div_assign")
        .m(&PXR_NS::GfRange1f::operator+, "op_add")
        .m(&PXR_NS::GfRange1f::operator-, "op_sub")
        .m((bool (PXR_NS::GfRange1f::*)(const PXR_NS::GfRange1f &) const)
            &PXR_NS::GfRange1f::operator==, "op_eq_00")
        .m((bool (PXR_NS::GfRange1f::*)(const PXR_NS::GfRange1d &) const)
            &PXR_NS::GfRange1f::operator==, "op_eq_01")
        .m((bool (PXR_NS::GfRange1f::*)(const PXR_NS::GfRange1f &) const)
            &PXR_NS::GfRange1f::operator!=, "op_neq_00")
        .m((bool (PXR_NS::GfRange1f::*)(const PXR_NS::GfRange1d &) const)
            &PXR_NS::GfRange1f::operator!=, "op_neq_01")
        .m(&PXR_NS::GfRange1f::GetDistanceSquared)
        .m((PXR_NS::GfRange1f & (PXR_NS::GfRange1f::*)(const PXR_NS::GfRange1f &))
            &PXR_NS::GfRange1f::operator=, "op_assign_00")
        .m((PXR_NS::GfRange1f & (PXR_NS::GfRange1f::*)(PXR_NS::GfRange1f &&))
            &PXR_NS::GfRange1f::operator=, "op_assign_01")
    ;


    bbl::Class<PXR_NS::GfRange2d>("Range2d")
        .replace_with<Range2d>()
        .ctor(bbl::Class<PXR_NS::GfRange2d>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfRange2d>::Ctor<const PXR_NS::GfVec2d &, const PXR_NS::GfVec2d &>("min", "max"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::GfRange2d>::Ctor<const class PXR_NS::GfRange2f &>("other"), "ctor_02")
        .m(&PXR_NS::GfRange2d::SetEmpty)
        .m(&PXR_NS::GfRange2d::GetMin)
        .m(&PXR_NS::GfRange2d::GetMax)
        .m(&PXR_NS::GfRange2d::GetSize)
        .m(&PXR_NS::GfRange2d::GetMidpoint)
        .m(&PXR_NS::GfRange2d::SetMin)
        .m(&PXR_NS::GfRange2d::SetMax)
        .m(&PXR_NS::GfRange2d::IsEmpty)
        .m((void (PXR_NS::GfRange2d::*)(const PXR_NS::GfVec2d &))
            &PXR_NS::GfRange2d::ExtendBy, "ExtendBy_00")
        .m((void (PXR_NS::GfRange2d::*)(const PXR_NS::GfRange2d &))
            &PXR_NS::GfRange2d::ExtendBy, "ExtendBy_01")
        .m((bool (PXR_NS::GfRange2d::*)(const PXR_NS::GfVec2d &) const)
            &PXR_NS::GfRange2d::Contains, "Contains_00")
        .m((bool (PXR_NS::GfRange2d::*)(const PXR_NS::GfRange2d &) const)
            &PXR_NS::GfRange2d::Contains, "Contains_01")
        .m((bool (PXR_NS::GfRange2d::*)(const PXR_NS::GfVec2d &) const)
            &PXR_NS::GfRange2d::IsInside, "IsInside_00")
        .m((bool (PXR_NS::GfRange2d::*)(const PXR_NS::GfRange2d &) const)
            &PXR_NS::GfRange2d::IsInside, "IsInside_01")
        .m(&PXR_NS::GfRange2d::IsOutside)
        .m(&PXR_NS::GfRange2d::GetUnion)
        .m((const PXR_NS::GfRange2d & (PXR_NS::GfRange2d::*)(const PXR_NS::GfRange2d &))
            &PXR_NS::GfRange2d::UnionWith, "UnionWith_00")
        .m((const PXR_NS::GfRange2d & (PXR_NS::GfRange2d::*)(const PXR_NS::GfVec2d &))
            &PXR_NS::GfRange2d::UnionWith, "UnionWith_01")
        .m((PXR_NS::GfRange2d (*)(const PXR_NS::GfRange2d &, const PXR_NS::GfRange2d &))
            &PXR_NS::GfRange2d::Union, "Union_00")
        .m((const PXR_NS::GfRange2d & (PXR_NS::GfRange2d::*)(const PXR_NS::GfRange2d &))
            &PXR_NS::GfRange2d::Union, "Union_01")
        .m((const PXR_NS::GfRange2d & (PXR_NS::GfRange2d::*)(const PXR_NS::GfVec2d &))
            &PXR_NS::GfRange2d::Union, "Union_02")
        .m(&PXR_NS::GfRange2d::GetIntersection)
        .m((PXR_NS::GfRange2d (*)(const PXR_NS::GfRange2d &, const PXR_NS::GfRange2d &))
            &PXR_NS::GfRange2d::Intersection, "Intersection_00")
        .m((const PXR_NS::GfRange2d & (PXR_NS::GfRange2d::*)(const PXR_NS::GfRange2d &))
            &PXR_NS::GfRange2d::Intersection, "Intersection_01")
        .m(&PXR_NS::GfRange2d::IntersectWith)
        .m(&PXR_NS::GfRange2d::operator+=, "op_add_assign")
        .m(&PXR_NS::GfRange2d::operator-=, "op_sub_assign")
        .m(&PXR_NS::GfRange2d::operator*=, "op_mul_assign")
        .m(&PXR_NS::GfRange2d::operator/=, "op_div_assign")
        .m(&PXR_NS::GfRange2d::operator+, "op_add")
        .m(&PXR_NS::GfRange2d::operator-, "op_sub")
        .m((bool (PXR_NS::GfRange2d::*)(const PXR_NS::GfRange2d &) const)
            &PXR_NS::GfRange2d::operator==, "op_eq_00")
        .m((bool (PXR_NS::GfRange2d::*)(const PXR_NS::GfRange2f &) const)
            &PXR_NS::GfRange2d::operator==, "op_eq_01")
        .m((bool (PXR_NS::GfRange2d::*)(const PXR_NS::GfRange2d &) const)
            &PXR_NS::GfRange2d::operator!=, "op_neq_00")
        .m((bool (PXR_NS::GfRange2d::*)(const PXR_NS::GfRange2f &) const)
            &PXR_NS::GfRange2d::operator!=, "op_neq_01")
        .m(&PXR_NS::GfRange2d::GetDistanceSquared)
        .m(&PXR_NS::GfRange2d::GetCorner)
        .m(&PXR_NS::GfRange2d::GetQuadrant)
        .m((PXR_NS::GfRange2d & (PXR_NS::GfRange2d::*)(const PXR_NS::GfRange2d &))
            &PXR_NS::GfRange2d::operator=, "op_assign_00")
        .m((PXR_NS::GfRange2d & (PXR_NS::GfRange2d::*)(PXR_NS::GfRange2d &&))
            &PXR_NS::GfRange2d::operator=, "op_assign_01")
    ;


    bbl::Class<PXR_NS::GfRange2f>("Range2f")
        .replace_with<Range2f>()
        .ctor(bbl::Class<PXR_NS::GfRange2f>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfRange2f>::Ctor<const PXR_NS::GfVec2f &, const PXR_NS::GfVec2f &>("min", "max"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::GfRange2f>::Ctor<const class PXR_NS::GfRange2d &>("other"), "ctor_02")
        .m(&PXR_NS::GfRange2f::SetEmpty)
        .m(&PXR_NS::GfRange2f::GetMin)
        .m(&PXR_NS::GfRange2f::GetMax)
        .m(&PXR_NS::GfRange2f::GetSize)
        .m(&PXR_NS::GfRange2f::GetMidpoint)
        .m(&PXR_NS::GfRange2f::SetMin)
        .m(&PXR_NS::GfRange2f::SetMax)
        .m(&PXR_NS::GfRange2f::IsEmpty)
        .m((void (PXR_NS::GfRange2f::*)(const PXR_NS::GfVec2f &))
            &PXR_NS::GfRange2f::ExtendBy, "ExtendBy_00")
        .m((void (PXR_NS::GfRange2f::*)(const PXR_NS::GfRange2f &))
            &PXR_NS::GfRange2f::ExtendBy, "ExtendBy_01")
        .m((bool (PXR_NS::GfRange2f::*)(const PXR_NS::GfVec2f &) const)
            &PXR_NS::GfRange2f::Contains, "Contains_00")
        .m((bool (PXR_NS::GfRange2f::*)(const PXR_NS::GfRange2f &) const)
            &PXR_NS::GfRange2f::Contains, "Contains_01")
        .m((bool (PXR_NS::GfRange2f::*)(const PXR_NS::GfVec2f &) const)
            &PXR_NS::GfRange2f::IsInside, "IsInside_00")
        .m((bool (PXR_NS::GfRange2f::*)(const PXR_NS::GfRange2f &) const)
            &PXR_NS::GfRange2f::IsInside, "IsInside_01")
        .m(&PXR_NS::GfRange2f::IsOutside)
        .m(&PXR_NS::GfRange2f::GetUnion)
        .m((const PXR_NS::GfRange2f & (PXR_NS::GfRange2f::*)(const PXR_NS::GfRange2f &))
            &PXR_NS::GfRange2f::UnionWith, "UnionWith_00")
        .m((const PXR_NS::GfRange2f & (PXR_NS::GfRange2f::*)(const PXR_NS::GfVec2f &))
            &PXR_NS::GfRange2f::UnionWith, "UnionWith_01")
        .m((PXR_NS::GfRange2f (*)(const PXR_NS::GfRange2f &, const PXR_NS::GfRange2f &))
            &PXR_NS::GfRange2f::Union, "Union_00")
        .m((const PXR_NS::GfRange2f & (PXR_NS::GfRange2f::*)(const PXR_NS::GfRange2f &))
            &PXR_NS::GfRange2f::Union, "Union_01")
        .m((const PXR_NS::GfRange2f & (PXR_NS::GfRange2f::*)(const PXR_NS::GfVec2f &))
            &PXR_NS::GfRange2f::Union, "Union_02")
        .m(&PXR_NS::GfRange2f::GetIntersection)
        .m((PXR_NS::GfRange2f (*)(const PXR_NS::GfRange2f &, const PXR_NS::GfRange2f &))
            &PXR_NS::GfRange2f::Intersection, "Intersection_00")
        .m((const PXR_NS::GfRange2f & (PXR_NS::GfRange2f::*)(const PXR_NS::GfRange2f &))
            &PXR_NS::GfRange2f::Intersection, "Intersection_01")
        .m(&PXR_NS::GfRange2f::IntersectWith)
        .m(&PXR_NS::GfRange2f::operator+=, "op_add_assign")
        .m(&PXR_NS::GfRange2f::operator-=, "op_sub_assign")
        .m(&PXR_NS::GfRange2f::operator*=, "op_mul_assign")
        .m(&PXR_NS::GfRange2f::operator/=, "op_div_assign")
        .m(&PXR_NS::GfRange2f::operator+, "op_add")
        .m(&PXR_NS::GfRange2f::operator-, "op_sub")
        .m((bool (PXR_NS::GfRange2f::*)(const PXR_NS::GfRange2f &) const)
            &PXR_NS::GfRange2f::operator==, "op_eq_00")
        .m((bool (PXR_NS::GfRange2f::*)(const PXR_NS::GfRange2d &) const)
            &PXR_NS::GfRange2f::operator==, "op_eq_01")
        .m((bool (PXR_NS::GfRange2f::*)(const PXR_NS::GfRange2f &) const)
            &PXR_NS::GfRange2f::operator!=, "op_neq_00")
        .m((bool (PXR_NS::GfRange2f::*)(const PXR_NS::GfRange2d &) const)
            &PXR_NS::GfRange2f::operator!=, "op_neq_01")
        .m(&PXR_NS::GfRange2f::GetDistanceSquared)
        .m(&PXR_NS::GfRange2f::GetCorner)
        .m(&PXR_NS::GfRange2f::GetQuadrant)
        .m((PXR_NS::GfRange2f & (PXR_NS::GfRange2f::*)(const PXR_NS::GfRange2f &))
            &PXR_NS::GfRange2f::operator=, "op_assign_00")
        .m((PXR_NS::GfRange2f & (PXR_NS::GfRange2f::*)(PXR_NS::GfRange2f &&))
            &PXR_NS::GfRange2f::operator=, "op_assign_01")
    ;


    bbl::Class<PXR_NS::GfRange3d>("Range3d")
        .replace_with<Range3d>()
        .ctor(bbl::Class<PXR_NS::GfRange3d>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfRange3d>::Ctor<const PXR_NS::GfVec3d &, const PXR_NS::GfVec3d &>("min", "max"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::GfRange3d>::Ctor<const class PXR_NS::GfRange3f &>("other"), "ctor_02")
        .m(&PXR_NS::GfRange3d::SetEmpty)
        .m(&PXR_NS::GfRange3d::GetMin)
        .m(&PXR_NS::GfRange3d::GetMax)
        .m(&PXR_NS::GfRange3d::GetSize)
        .m(&PXR_NS::GfRange3d::GetMidpoint)
        .m(&PXR_NS::GfRange3d::SetMin)
        .m(&PXR_NS::GfRange3d::SetMax)
        .m(&PXR_NS::GfRange3d::IsEmpty)
        .m((void (PXR_NS::GfRange3d::*)(const PXR_NS::GfVec3d &))
            &PXR_NS::GfRange3d::ExtendBy, "ExtendBy_00")
        .m((void (PXR_NS::GfRange3d::*)(const PXR_NS::GfRange3d &))
            &PXR_NS::GfRange3d::ExtendBy, "ExtendBy_01")
        .m((bool (PXR_NS::GfRange3d::*)(const PXR_NS::GfVec3d &) const)
            &PXR_NS::GfRange3d::Contains, "Contains_00")
        .m((bool (PXR_NS::GfRange3d::*)(const PXR_NS::GfRange3d &) const)
            &PXR_NS::GfRange3d::Contains, "Contains_01")
        .m((bool (PXR_NS::GfRange3d::*)(const PXR_NS::GfVec3d &) const)
            &PXR_NS::GfRange3d::IsInside, "IsInside_00")
        .m((bool (PXR_NS::GfRange3d::*)(const PXR_NS::GfRange3d &) const)
            &PXR_NS::GfRange3d::IsInside, "IsInside_01")
        .m(&PXR_NS::GfRange3d::IsOutside)
        .m(&PXR_NS::GfRange3d::GetUnion)
        .m((const PXR_NS::GfRange3d & (PXR_NS::GfRange3d::*)(const PXR_NS::GfRange3d &))
            &PXR_NS::GfRange3d::UnionWith, "UnionWith_00")
        .m((const PXR_NS::GfRange3d & (PXR_NS::GfRange3d::*)(const PXR_NS::GfVec3d &))
            &PXR_NS::GfRange3d::UnionWith, "UnionWith_01")
        .m((PXR_NS::GfRange3d (*)(const PXR_NS::GfRange3d &, const PXR_NS::GfRange3d &))
            &PXR_NS::GfRange3d::Union, "Union_00")
        .m((const PXR_NS::GfRange3d & (PXR_NS::GfRange3d::*)(const PXR_NS::GfRange3d &))
            &PXR_NS::GfRange3d::Union, "Union_01")
        .m((const PXR_NS::GfRange3d & (PXR_NS::GfRange3d::*)(const PXR_NS::GfVec3d &))
            &PXR_NS::GfRange3d::Union, "Union_02")
        .m(&PXR_NS::GfRange3d::GetIntersection)
        .m((PXR_NS::GfRange3d (*)(const PXR_NS::GfRange3d &, const PXR_NS::GfRange3d &))
            &PXR_NS::GfRange3d::Intersection, "Intersection_00")
        .m((const PXR_NS::GfRange3d & (PXR_NS::GfRange3d::*)(const PXR_NS::GfRange3d &))
            &PXR_NS::GfRange3d::Intersection, "Intersection_01")
        .m(&PXR_NS::GfRange3d::IntersectWith)
        .m(&PXR_NS::GfRange3d::operator+=, "op_add_assign")
        .m(&PXR_NS::GfRange3d::operator-=, "op_sub_assign")
        .m(&PXR_NS::GfRange3d::operator*=, "op_mul_assign")
        .m(&PXR_NS::GfRange3d::operator/=, "op_div_assign")
        .m(&PXR_NS::GfRange3d::operator+, "op_add")
        .m(&PXR_NS::GfRange3d::operator-, "op_sub")
        .m((bool (PXR_NS::GfRange3d::*)(const PXR_NS::GfRange3d &) const)
            &PXR_NS::GfRange3d::operator==, "op_eq_00")
        .m((bool (PXR_NS::GfRange3d::*)(const PXR_NS::GfRange3f &) const)
            &PXR_NS::GfRange3d::operator==, "op_eq_01")
        .m((bool (PXR_NS::GfRange3d::*)(const PXR_NS::GfRange3d &) const)
            &PXR_NS::GfRange3d::operator!=, "op_neq_00")
        .m((bool (PXR_NS::GfRange3d::*)(const PXR_NS::GfRange3f &) const)
            &PXR_NS::GfRange3d::operator!=, "op_neq_01")
        .m(&PXR_NS::GfRange3d::GetDistanceSquared)
        .m(&PXR_NS::GfRange3d::GetCorner)
        .m(&PXR_NS::GfRange3d::GetOctant)
        .m((PXR_NS::GfRange3d & (PXR_NS::GfRange3d::*)(const PXR_NS::GfRange3d &))
            &PXR_NS::GfRange3d::operator=, "op_assign_00")
        .m((PXR_NS::GfRange3d & (PXR_NS::GfRange3d::*)(PXR_NS::GfRange3d &&))
            &PXR_NS::GfRange3d::operator=, "op_assign_01")
    ;


    bbl::Class<PXR_NS::GfRange3f>("Range3f")
        .replace_with<Range3f>()
        .ctor(bbl::Class<PXR_NS::GfRange3f>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfRange3f>::Ctor<const PXR_NS::GfVec3f &, const PXR_NS::GfVec3f &>("min", "max"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::GfRange3f>::Ctor<const class PXR_NS::GfRange3d &>("other"), "ctor_02")
        .m(&PXR_NS::GfRange3f::SetEmpty)
        .m(&PXR_NS::GfRange3f::GetMin)
        .m(&PXR_NS::GfRange3f::GetMax)
        .m(&PXR_NS::GfRange3f::GetSize)
        .m(&PXR_NS::GfRange3f::GetMidpoint)
        .m(&PXR_NS::GfRange3f::SetMin)
        .m(&PXR_NS::GfRange3f::SetMax)
        .m(&PXR_NS::GfRange3f::IsEmpty)
        .m((void (PXR_NS::GfRange3f::*)(const PXR_NS::GfVec3f &))
            &PXR_NS::GfRange3f::ExtendBy, "ExtendBy_00")
        .m((void (PXR_NS::GfRange3f::*)(const PXR_NS::GfRange3f &))
            &PXR_NS::GfRange3f::ExtendBy, "ExtendBy_01")
        .m((bool (PXR_NS::GfRange3f::*)(const PXR_NS::GfVec3f &) const)
            &PXR_NS::GfRange3f::Contains, "Contains_00")
        .m((bool (PXR_NS::GfRange3f::*)(const PXR_NS::GfRange3f &) const)
            &PXR_NS::GfRange3f::Contains, "Contains_01")
        .m((bool (PXR_NS::GfRange3f::*)(const PXR_NS::GfVec3f &) const)
            &PXR_NS::GfRange3f::IsInside, "IsInside_00")
        .m((bool (PXR_NS::GfRange3f::*)(const PXR_NS::GfRange3f &) const)
            &PXR_NS::GfRange3f::IsInside, "IsInside_01")
        .m(&PXR_NS::GfRange3f::IsOutside)
        .m(&PXR_NS::GfRange3f::GetUnion)
        .m((const PXR_NS::GfRange3f & (PXR_NS::GfRange3f::*)(const PXR_NS::GfRange3f &))
            &PXR_NS::GfRange3f::UnionWith, "UnionWith_00")
        .m((const PXR_NS::GfRange3f & (PXR_NS::GfRange3f::*)(const PXR_NS::GfVec3f &))
            &PXR_NS::GfRange3f::UnionWith, "UnionWith_01")
        .m((PXR_NS::GfRange3f (*)(const PXR_NS::GfRange3f &, const PXR_NS::GfRange3f &))
            &PXR_NS::GfRange3f::Union, "Union_00")
        .m((const PXR_NS::GfRange3f & (PXR_NS::GfRange3f::*)(const PXR_NS::GfRange3f &))
            &PXR_NS::GfRange3f::Union, "Union_01")
        .m((const PXR_NS::GfRange3f & (PXR_NS::GfRange3f::*)(const PXR_NS::GfVec3f &))
            &PXR_NS::GfRange3f::Union, "Union_02")
        .m(&PXR_NS::GfRange3f::GetIntersection)
        .m((PXR_NS::GfRange3f (*)(const PXR_NS::GfRange3f &, const PXR_NS::GfRange3f &))
            &PXR_NS::GfRange3f::Intersection, "Intersection_00")
        .m((const PXR_NS::GfRange3f & (PXR_NS::GfRange3f::*)(const PXR_NS::GfRange3f &))
            &PXR_NS::GfRange3f::Intersection, "Intersection_01")
        .m(&PXR_NS::GfRange3f::IntersectWith)
        .m(&PXR_NS::GfRange3f::operator+=, "op_add_assign")
        .m(&PXR_NS::GfRange3f::operator-=, "op_sub_assign")
        .m(&PXR_NS::GfRange3f::operator*=, "op_mul_assign")
        .m(&PXR_NS::GfRange3f::operator/=, "op_div_assign")
        .m(&PXR_NS::GfRange3f::operator+, "op_add")
        .m(&PXR_NS::GfRange3f::operator-, "op_sub")
        .m((bool (PXR_NS::GfRange3f::*)(const PXR_NS::GfRange3f &) const)
            &PXR_NS::GfRange3f::operator==, "op_eq_00")
        .m((bool (PXR_NS::GfRange3f::*)(const PXR_NS::GfRange3d &) const)
            &PXR_NS::GfRange3f::operator==, "op_eq_01")
        .m((bool (PXR_NS::GfRange3f::*)(const PXR_NS::GfRange3f &) const)
            &PXR_NS::GfRange3f::operator!=, "op_neq_00")
        .m((bool (PXR_NS::GfRange3f::*)(const PXR_NS::GfRange3d &) const)
            &PXR_NS::GfRange3f::operator!=, "op_neq_01")
        .m(&PXR_NS::GfRange3f::GetDistanceSquared)
        .m(&PXR_NS::GfRange3f::GetCorner)
        .m(&PXR_NS::GfRange3f::GetOctant)
    ;



    bbl::Class<PXR_NS::GfRay>("Ray")
        .value_type()
        .replace_with<Ray>()
        .ctor(bbl::Class<PXR_NS::GfRay>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfRay>::Ctor<const PXR_NS::GfVec3d &, const PXR_NS::GfVec3d &>("startPoint", "direction"), "ctor_01")
        .m(&PXR_NS::GfRay::SetPointAndDirection)
        .m(&PXR_NS::GfRay::SetEnds)
        .m(&PXR_NS::GfRay::GetStartPoint)
        .m(&PXR_NS::GfRay::GetDirection)
        .m(&PXR_NS::GfRay::GetPoint)
        .m(&PXR_NS::GfRay::Transform)
        .m(&PXR_NS::GfRay::FindClosestPoint)
        .m(&PXR_NS::GfRay::operator==, "op_eq")
        .m(&PXR_NS::GfRay::operator!=, "op_neq")
        .m((bool (PXR_NS::GfRay::*)(const PXR_NS::GfVec3d &, const PXR_NS::GfVec3d &, const PXR_NS::GfVec3d &, double *, PXR_NS::GfVec3d *, bool *, double) const)
            &PXR_NS::GfRay::Intersect, "Intersect_00")
        .m((bool (PXR_NS::GfRay::*)(const PXR_NS::GfPlane &, double *, bool *) const)
            &PXR_NS::GfRay::Intersect, "Intersect_plane")
        .m((bool (PXR_NS::GfRay::*)(const PXR_NS::GfRange3d &, double *, double *) const)
            &PXR_NS::GfRay::Intersect, "Intersect_range3d")
        .m((bool (PXR_NS::GfRay::*)(const PXR_NS::GfBBox3d &, double *, double *) const)
            &PXR_NS::GfRay::Intersect, "Intersect_bbox3d")
        .m((bool (PXR_NS::GfRay::*)(const PXR_NS::GfVec3d &, double, double *, double *) const)
            &PXR_NS::GfRay::Intersect, "Intersect_04")
        .m((bool (PXR_NS::GfRay::*)(const PXR_NS::GfVec3d &, const PXR_NS::GfVec3d &, const double, double *, double *) const)
            &PXR_NS::GfRay::Intersect, "Intersect_05")
        .m((bool (PXR_NS::GfRay::*)(const PXR_NS::GfVec3d &, const PXR_NS::GfVec3d &, const double, const double, double *, double *) const)
            &PXR_NS::GfRay::Intersect, "Intersect_06")
    ;

    bbl::Class<PXR_NS::GfRect2i>("Rect2i")
        .ctor(bbl::Class<PXR_NS::GfRect2i>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfRect2i>::Ctor<const PXR_NS::GfVec2i &, const PXR_NS::GfVec2i &>("min", "max"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::GfRect2i>::Ctor<const PXR_NS::GfVec2i &, int, int>("min", "width", "height"), "ctor_02")
        .m(&PXR_NS::GfRect2i::IsNull)
        .m(&PXR_NS::GfRect2i::IsEmpty)
        .m(&PXR_NS::GfRect2i::IsValid)
        .m(&PXR_NS::GfRect2i::GetNormalized)
        .m(&PXR_NS::GfRect2i::GetMin)
        .m(&PXR_NS::GfRect2i::GetMax)
        .m(&PXR_NS::GfRect2i::GetMinX)
        .m(&PXR_NS::GfRect2i::SetMinX)
        .m(&PXR_NS::GfRect2i::GetMaxX)
        .m(&PXR_NS::GfRect2i::SetMaxX)
        .m(&PXR_NS::GfRect2i::GetMinY)
        .m(&PXR_NS::GfRect2i::SetMinY)
        .m(&PXR_NS::GfRect2i::GetMaxY)
        .m(&PXR_NS::GfRect2i::SetMaxY)
        .m(&PXR_NS::GfRect2i::SetMin)
        .m(&PXR_NS::GfRect2i::SetMax)
        .m(&PXR_NS::GfRect2i::GetCenter)
        .m(&PXR_NS::GfRect2i::Translate)
        .m(&PXR_NS::GfRect2i::GetArea)
        .m(&PXR_NS::GfRect2i::GetSize)
        .m(&PXR_NS::GfRect2i::GetWidth)
        .m(&PXR_NS::GfRect2i::GetHeight)
        .m(&PXR_NS::GfRect2i::GetIntersection)
        .m(&PXR_NS::GfRect2i::Intersect)
        .m(&PXR_NS::GfRect2i::GetUnion)
        .m(&PXR_NS::GfRect2i::Union)
        .m(&PXR_NS::GfRect2i::Contains)
        .m(&PXR_NS::GfRect2i::operator+=, "op_add_assign")
        .m((PXR_NS::GfRect2i & (PXR_NS::GfRect2i::*)(const PXR_NS::GfRect2i &))
            &PXR_NS::GfRect2i::operator=, "op_assign_00")
        .m((PXR_NS::GfRect2i & (PXR_NS::GfRect2i::*)(PXR_NS::GfRect2i &&))
            &PXR_NS::GfRect2i::operator=, "op_assign_01")
    ;


    bbl::Class<PXR_NS::GfRotation>("Rotation")
        .value_type()
        .replace_with<Rotation>()
        .ctor(bbl::Class<PXR_NS::GfRotation>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfRotation>::Ctor<const PXR_NS::GfVec3d &, double>("axis", "angle"), "from_axis_angle")
        .ctor(bbl::Class<PXR_NS::GfRotation>::Ctor<const PXR_NS::GfQuaternion &>("quaternion"), "from_quaternion")
        .ctor(bbl::Class<PXR_NS::GfRotation>::Ctor<const PXR_NS::GfQuatd &>("quat"), "from_quatd")
        .ctor(bbl::Class<PXR_NS::GfRotation>::Ctor<const PXR_NS::GfVec3d &, const PXR_NS::GfVec3d &>("rotateFrom", "rotateTo"), "from_to")
        .m(&PXR_NS::GfRotation::SetAxisAngle)
        .m(&PXR_NS::GfRotation::SetQuat)
        .m(&PXR_NS::GfRotation::SetQuaternion)
        .m(&PXR_NS::GfRotation::SetRotateInto)
        .m(&PXR_NS::GfRotation::SetIdentity)
        .m(&PXR_NS::GfRotation::GetAxis)
        .m(&PXR_NS::GfRotation::GetAngle)
        .m(&PXR_NS::GfRotation::GetQuaternion)
        .m(&PXR_NS::GfRotation::GetQuat)
        .m(&PXR_NS::GfRotation::GetInverse)
        .m(&PXR_NS::GfRotation::Decompose)
        .m(&PXR_NS::GfRotation::DecomposeRotation)
        .m(&PXR_NS::GfRotation::RotateOntoProjected)
        .m(&PXR_NS::GfRotation::MatchClosestEulerRotation)
        .m((PXR_NS::GfVec3f (PXR_NS::GfRotation::*)(const PXR_NS::GfVec3f &) const)
            &PXR_NS::GfRotation::TransformDir, "TransformDir_00")
        .m((PXR_NS::GfVec3d (PXR_NS::GfRotation::*)(const PXR_NS::GfVec3d &) const)
            &PXR_NS::GfRotation::TransformDir, "TransformDir_01")
        .m(&PXR_NS::GfRotation::operator==, "op_eq")
        .m(&PXR_NS::GfRotation::operator!=, "op_neq")
        .m((PXR_NS::GfRotation & (PXR_NS::GfRotation::*)(const PXR_NS::GfRotation &))
            &PXR_NS::GfRotation::operator*=, "op_mul_assign_00")
        .m((PXR_NS::GfRotation & (PXR_NS::GfRotation::*)(double))
            &PXR_NS::GfRotation::operator*=, "op_mul_assign_01")
        .m(&PXR_NS::GfRotation::operator/=, "op_div_assign")
    ;

    bbl::Class<PXR_NS::GfSize2>("Size2")
        .ctor(bbl::Class<PXR_NS::GfSize2>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfSize2>::Ctor<const PXR_NS::GfVec2i &>("o"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::GfSize2>::Ctor<const size_t *>("v"), "ctor_02")
        .ctor(bbl::Class<PXR_NS::GfSize2>::Ctor<size_t, size_t>("v0", "v1"), "ctor_03")
        .m((PXR_NS::GfSize2 & (PXR_NS::GfSize2::*)(const size_t *))
            &PXR_NS::GfSize2::Set, "Set_00")
        .m((PXR_NS::GfSize2 & (PXR_NS::GfSize2::*)(size_t, size_t))
            &PXR_NS::GfSize2::Set, "Set_01")
        .m((size_t & (PXR_NS::GfSize2::*)(size_t))
            &PXR_NS::GfSize2::operator[], "op_index_00")
        .m((const size_t & (PXR_NS::GfSize2::*)(size_t) const)
            &PXR_NS::GfSize2::operator[], "op_index_01")
        .m(&PXR_NS::GfSize2::operator==, "op_eq")
        .m(&PXR_NS::GfSize2::operator!=, "op_neq")
        .m(&PXR_NS::GfSize2::operator+=, "op_add_assign")
        .m(&PXR_NS::GfSize2::operator-=, "op_sub_assign")
        .m((PXR_NS::GfSize2 & (PXR_NS::GfSize2::*)(const PXR_NS::GfSize2 &))
            &PXR_NS::GfSize2::operator*=, "op_mul_assign_00")
        .m((PXR_NS::GfSize2 & (PXR_NS::GfSize2::*)(int))
            &PXR_NS::GfSize2::operator*=, "op_mul_assign_01")
        .m(&PXR_NS::GfSize2::operator/=, "op_div_assign")
        .m(&PXR_NS::GfSize2::operator=, "op_assign")
    ;

    bbl::Class<PXR_NS::GfSize3>("Size3")
        .ctor(bbl::Class<PXR_NS::GfSize3>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfSize3>::Ctor<const PXR_NS::GfVec3i &>("o"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::GfSize3>::Ctor<const size_t *>("v"), "ctor_02")
        .ctor(bbl::Class<PXR_NS::GfSize3>::Ctor<size_t, size_t, size_t>("v0", "v1", "v2"), "ctor_03")
        .m((PXR_NS::GfSize3 & (PXR_NS::GfSize3::*)(const size_t *))
            &PXR_NS::GfSize3::Set, "Set_00")
        .m((PXR_NS::GfSize3 & (PXR_NS::GfSize3::*)(size_t, size_t, size_t))
            &PXR_NS::GfSize3::Set, "Set_01")
        .m((size_t & (PXR_NS::GfSize3::*)(size_t))
            &PXR_NS::GfSize3::operator[], "op_index_00")
        .m((const size_t & (PXR_NS::GfSize3::*)(size_t) const)
            &PXR_NS::GfSize3::operator[], "op_index_01")
        .m(&PXR_NS::GfSize3::operator==, "op_eq")
        .m(&PXR_NS::GfSize3::operator!=, "op_neq")
        .m(&PXR_NS::GfSize3::operator+=, "op_add_assign")
        .m(&PXR_NS::GfSize3::operator-=, "op_sub_assign")
        .m((PXR_NS::GfSize3 & (PXR_NS::GfSize3::*)(const PXR_NS::GfSize3 &))
            &PXR_NS::GfSize3::operator*=, "op_mul_assign_00")
        .m((PXR_NS::GfSize3 & (PXR_NS::GfSize3::*)(size_t))
            &PXR_NS::GfSize3::operator*=, "op_mul_assign_01")
        .m(&PXR_NS::GfSize3::operator/=, "op_div_assign")
        .m(&PXR_NS::GfSize3::operator=, "op_assign")
    ;

    bbl::Class<PXR_NS::GfTransform>("Transform")
        .ctor(bbl::Class<PXR_NS::GfTransform>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::GfTransform>::Ctor<const PXR_NS::GfVec3d &, const PXR_NS::GfRotation &, const PXR_NS::GfRotation &, const PXR_NS::GfVec3d &, const PXR_NS::GfVec3d &>("scale", "pivotOrientation", "rotation", "pivotPosition", "translation"), "ctor_01")
        .ctor(bbl::Class<PXR_NS::GfTransform>::Ctor<const PXR_NS::GfVec3d &, const PXR_NS::GfRotation &, const PXR_NS::GfVec3d &, const PXR_NS::GfVec3d &, const PXR_NS::GfRotation &>("translation", "rotation", "scale", "pivotPosition", "pivotOrientation"), "ctor_02")
        .ctor(bbl::Class<PXR_NS::GfTransform>::Ctor<const PXR_NS::GfMatrix4d &>("m"), "ctor_03")
        .m((PXR_NS::GfTransform & (PXR_NS::GfTransform::*)(const PXR_NS::GfVec3d &, const PXR_NS::GfRotation &, const PXR_NS::GfRotation &, const PXR_NS::GfVec3d &, const PXR_NS::GfVec3d &))
            &PXR_NS::GfTransform::Set, "Set_00")
        .m((PXR_NS::GfTransform & (PXR_NS::GfTransform::*)(const PXR_NS::GfVec3d &, const PXR_NS::GfRotation &, const PXR_NS::GfVec3d &, const PXR_NS::GfVec3d &, const PXR_NS::GfRotation &))
            &PXR_NS::GfTransform::Set, "Set_01")
        .m(&PXR_NS::GfTransform::SetMatrix)
        .m(&PXR_NS::GfTransform::SetIdentity)
        .m(&PXR_NS::GfTransform::SetScale)
        .m(&PXR_NS::GfTransform::SetPivotOrientation)
        .m(&PXR_NS::GfTransform::SetScaleOrientation)
        .m(&PXR_NS::GfTransform::SetRotation)
        .m(&PXR_NS::GfTransform::SetPivotPosition)
        .m(&PXR_NS::GfTransform::SetCenter)
        .m(&PXR_NS::GfTransform::SetTranslation)
        .m(&PXR_NS::GfTransform::GetScale)
        .m(&PXR_NS::GfTransform::GetPivotOrientation)
        .m(&PXR_NS::GfTransform::GetScaleOrientation)
        .m(&PXR_NS::GfTransform::GetRotation)
        .m(&PXR_NS::GfTransform::GetPivotPosition)
        .m(&PXR_NS::GfTransform::GetCenter)
        .m(&PXR_NS::GfTransform::GetTranslation)
        .m(&PXR_NS::GfTransform::GetMatrix)
        .m(&PXR_NS::GfTransform::operator==, "op_eq")
        .m(&PXR_NS::GfTransform::operator!=, "op_neq")
        .m(&PXR_NS::GfTransform::operator*=, "op_mul_assign")
    ;

}


#endif
