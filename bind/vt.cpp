#if defined(__clang__)

#include "babble"
#include "babble-std"
#include "babble-vt"

#include <pxr/base/vt/dictionary.h>
#include <pxr/base/vt/value.h>
#include <pxr/base/vt/array.h>
#include <pxr/base/vt/types.h>

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


#include <pxr/base/tf/token.h>
#include <pxr/usd/sdf/assetPath.h>
#include <pxr/usd/sdf/timeCode.h>



BBL_MODULE(vt) {

    // clang-format off

    using Value = PXR_NS::VtValue;

    bbl::Class<PXR_NS::VtValue>("Value")
        .ctor(bbl::Class<Value>::Ctor<>(), "new")
        .ctor(bbl::Class<Value>::Ctor<float>("obj"))
        .m(&Value::IsArrayValued)
        .m(&Value::IsEmpty)
        .m(&Value::GetArraySize)
        .m(&Value::GetType)
        .m(&Value::GetTypeName)

        .ctor(bbl::Class<Value>::Ctor<bool>("value"), "from_bool")
        .m((bool (Value::*)() const)
            &Value::IsHolding<bool>, "IsHolding_bool"
        )
        .m((bool const& (Value::*)() const&)
            &Value::Get<bool>, "Get_bool"
        )

        .ctor(bbl::Class<Value>::Ctor<uint8_t>("value"), "from_uchar")
        .m((bool (Value::*)() const)
            &Value::IsHolding<uint8_t>, "IsHolding_uchar"
        )
        .m((uint8_t const& (Value::*)() const&)
            &Value::Get<uint8_t>, "Get_uchar"
        )

        .ctor(bbl::Class<Value>::Ctor<uint32_t>("value"), "from_uint")
        .m((bool (Value::*)() const)
            &Value::IsHolding<uint32_t>, "IsHolding_uint"
        )
        .m((uint32_t const& (Value::*)() const&)
            &Value::Get<uint32_t>, "Get_uint"
        )

        .ctor(bbl::Class<Value>::Ctor<int>("value"), "from_int")
        .m((bool (Value::*)() const)
            &Value::IsHolding<int>, "IsHolding_int"
        )
        .m((int const& (Value::*)() const&)
            &Value::Get<int>, "Get_int"
        )

        .ctor(bbl::Class<Value>::Ctor<uint64_t>("value"), "from_uint64")
        .m((bool (Value::*)() const)
            &Value::IsHolding<uint64_t>, "IsHolding_uint64"
        )
        .m((uint64_t const& (Value::*)() const&)
            &Value::Get<uint64_t>, "Get_uint64"
        )

        .ctor(bbl::Class<Value>::Ctor<int64_t>("value"), "from_int64")
        .m((bool (Value::*)() const)
            &Value::IsHolding<int64_t>, "IsHolding_int64"
        )
        .m((int64_t const& (Value::*)() const&)
            &Value::Get<int64_t>, "Get_int64"
        )

        .ctor(bbl::Class<Value>::Ctor<float>("value"), "from_float")
        .m((bool (Value::*)() const)
            &Value::IsHolding<float>, "IsHolding_float"
        )
        .m((float const& (Value::*)() const&)
            &Value::Get<float>, "Get_float"
        )

        .ctor(bbl::Class<Value>::Ctor<double>("value"), "from_double")
        .m((bool (Value::*)() const)
            &Value::IsHolding<double>, "IsHolding_double"
        )
        .m((double const& (Value::*)() const&)
            &Value::Get<double>, "Get_double"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::TfToken>("value"), "from_TfToken")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::TfToken>, "IsHolding_TfToken"
        )
        .m((PXR_NS::TfToken const& (Value::*)() const&)
            &Value::Get<PXR_NS::TfToken>, "Get_TfToken"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::SdfAssetPath>("value"), "from_SdfAssetPath")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::SdfAssetPath>, "IsHolding_SdfAssetPath"
        )
        .m((PXR_NS::SdfAssetPath const& (Value::*)() const&)
            &Value::Get<PXR_NS::SdfAssetPath>, "Get_SdfAssetPath"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::SdfTimeCode>("value"), "from_SdfTimeCode")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::SdfTimeCode>, "IsHolding_SdfTimeCode"
        )
        .m((PXR_NS::SdfTimeCode const& (Value::*)() const&)
            &Value::Get<PXR_NS::SdfTimeCode>, "Get_SdfTimeCode"
        )

        .ctor(bbl::Class<Value>::Ctor<std::string>("value"), "from_string")
        .m((bool (Value::*)() const)
            &Value::IsHolding<std::string>, "IsHolding_string"
        )
        .m((std::string const& (Value::*)() const&)
            &Value::Get<std::string>, "Get_string"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::GfVec2d>("value"), "from_GfVec2d")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfVec2d>, "IsHolding_GfVec2d"
        )
        .m((PXR_NS::GfVec2d const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfVec2d>, "Get_GfVec2d"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::GfVec2h>("value"), "from_GfVec2h")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfVec2h>, "IsHolding_GfVec2h"
        )
        .m((PXR_NS::GfVec2h const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfVec2h>, "Get_GfVec2h"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::GfVec2f>("value"), "from_GfVec2f")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfVec2f>, "IsHolding_GfVec2f"
        )
        .m((PXR_NS::GfVec2f const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfVec2f>, "Get_GfVec2f"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::GfVec2i>("value"), "from_GfVec2i")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfVec2i>, "IsHolding_GfVec2i"
        )
        .m((PXR_NS::GfVec2i const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfVec2i>, "Get_GfVec2i"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::GfVec3d>("value"), "from_GfVec3d")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfVec3d>, "IsHolding_GfVec3d"
        )
        .m((PXR_NS::GfVec3d const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfVec3d>, "Get_GfVec3d"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::GfVec3h>("value"), "from_GfVec3h")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfVec3h>, "IsHolding_GfVec3h"
        )
        .m((PXR_NS::GfVec3h const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfVec3h>, "Get_GfVec3h"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::GfVec3f>("value"), "from_GfVec3f")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfVec3f>, "IsHolding_GfVec3f"
        )
        .m((PXR_NS::GfVec3f const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfVec3f>, "Get_GfVec3f"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::GfVec3i>("value"), "from_GfVec3i")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfVec3i>, "IsHolding_GfVec3i"
        )
        .m((PXR_NS::GfVec3i const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfVec3i>, "Get_GfVec3i"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::GfVec4d>("value"), "from_GfVec4d")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfVec4d>, "IsHolding_GfVec4d"
        )
        .m((PXR_NS::GfVec4d const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfVec4d>, "Get_GfVec4d"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::GfVec4h>("value"), "from_GfVec4h")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfVec4h>, "IsHolding_GfVec4h"
        )
        .m((PXR_NS::GfVec4h const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfVec4h>, "Get_GfVec4h"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::GfVec4f>("value"), "from_GfVec4f")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfVec4f>, "IsHolding_GfVec4f"
        )
        .m((PXR_NS::GfVec4f const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfVec4f>, "Get_GfVec4f"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::GfVec4i>("value"), "from_GfVec4i")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfVec4i>, "IsHolding_GfVec4i"
        )
        .m((PXR_NS::GfVec4i const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfVec4i>, "Get_GfVec4i"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::GfQuatd>("value"), "from_GfQuatd")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfQuatd>, "IsHolding_GfQuatd"
        )
        .m((PXR_NS::GfQuatd const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfQuatd>, "Get_GfQuatd"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::GfQuatf>("value"), "from_GfQuatf")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfQuatf>, "IsHolding_GfQuatf"
        )
        .m((PXR_NS::GfQuatf const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfQuatf>, "Get_GfQuatf"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::GfQuath>("value"), "from_GfQuath")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfQuath>, "IsHolding_GfQuath"
        )
        .m((PXR_NS::GfQuath const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfQuath>, "Get_GfQuath"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::GfMatrix2d>("value"), "from_GfMatrix2d")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfMatrix2d>, "IsHolding_GfMatrix2d"
        )
        .m((PXR_NS::GfMatrix2d const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfMatrix2d>, "Get_GfMatrix2d"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::GfMatrix2f>("value"), "from_GfMatrix2f")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfMatrix2f>, "IsHolding_GfMatrix2f"
        )
        .m((PXR_NS::GfMatrix2f const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfMatrix2f>, "Get_GfMatrix2f"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::GfMatrix3d>("value"), "from_GfMatrix3d")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfMatrix3d>, "IsHolding_GfMatrix3d"
        )
        .m((PXR_NS::GfMatrix3d const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfMatrix3d>, "Get_GfMatrix3d"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::GfMatrix3f>("value"), "from_GfMatrix3f")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfMatrix3f>, "IsHolding_GfMatrix3f"
        )
        .m((PXR_NS::GfMatrix3f const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfMatrix3f>, "Get_GfMatrix3f"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::GfMatrix4d>("value"), "from_GfMatrix4d")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfMatrix4d>, "IsHolding_GfMatrix4d"
        )
        .m((PXR_NS::GfMatrix4d const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfMatrix4d>, "Get_GfMatrix4d"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::GfMatrix4f>("value"), "from_GfMatrix4f")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfMatrix4f>, "IsHolding_GfMatrix4f"
        )
        .m((PXR_NS::GfMatrix4f const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfMatrix4f>, "Get_GfMatrix4f"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtTokenArray>("value"), "from_VtTokenArray")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtTokenArray>, "IsHolding_VtTokenArray"
        )
        .m((PXR_NS::VtTokenArray const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtTokenArray>, "Get_VtTokenArray"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtStringArray>("value"), "from_VtStringArray")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtStringArray>, "IsHolding_VtStringArray"
        )
        .m((PXR_NS::VtStringArray const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtStringArray>, "Get_VtStringArray"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtBoolArray>("value"), "from_VtBoolArray")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtBoolArray>, "IsHolding_VtBoolArray"
        )
        .m((PXR_NS::VtBoolArray const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtBoolArray>, "Get_VtBoolArray"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtUCharArray>("value"), "from_VtUCharArray")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtUCharArray>, "IsHolding_VtUCharArray"
        )
        .m((PXR_NS::VtUCharArray const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtUCharArray>, "Get_VtUCharArray"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtUIntArray>("value"), "from_VtUIntArray")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtUIntArray>, "IsHolding_VtUIntArray"
        )
        .m((PXR_NS::VtUIntArray const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtUIntArray>, "Get_VtUIntArray"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtIntArray>("value"), "from_VtIntArray")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtIntArray>, "IsHolding_VtIntArray"
        )
        .m((PXR_NS::VtIntArray const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtIntArray>, "Get_VtIntArray"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtUInt64Array>("value"), "from_VtUInt64Array")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtUInt64Array>, "IsHolding_VtUInt64Array"
        )
        .m((PXR_NS::VtUInt64Array const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtUInt64Array>, "Get_VtUInt64Array"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtInt64Array>("value"), "from_VtInt64Array")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtInt64Array>, "IsHolding_VtInt64Array"
        )
        .m((PXR_NS::VtInt64Array const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtInt64Array>, "Get_VtInt64Array"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtFloatArray>("value"), "from_VtFloatArray")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtFloatArray>, "IsHolding_VtFloatArray"
        )
        .m((PXR_NS::VtFloatArray const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtFloatArray>, "Get_VtFloatArray"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtDoubleArray>("value"), "from_VtDoubleArray")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtDoubleArray>, "IsHolding_VtDoubleArray"
        )
        .m((PXR_NS::VtDoubleArray const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtDoubleArray>, "Get_VtDoubleArray"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtVec2fArray>("value"), "from_VtVec2fArray")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtVec2fArray>, "IsHolding_VtVec2fArray"
        )
        .m((PXR_NS::VtVec2fArray const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtVec2fArray>, "Get_VtVec2fArray"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtVec3fArray>("value"), "from_VtVec3fArray")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtVec3fArray>, "IsHolding_VtVec3fArray"
        )
        .m((PXR_NS::VtVec3fArray const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtVec3fArray>, "Get_VtVec3fArray"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtVec4fArray>("value"), "from_VtVec4fArray")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtVec4fArray>, "IsHolding_VtVec4fArray"
        )
        .m((PXR_NS::VtVec4fArray const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtVec4fArray>, "Get_VtVec4fArray"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtVec2dArray>("value"), "from_VtVec2dArray")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtVec2dArray>, "IsHolding_VtVec2dArray"
        )
        .m((PXR_NS::VtVec2dArray const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtVec2dArray>, "Get_VtVec2dArray"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtVec3dArray>("value"), "from_VtVec3dArray")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtVec3dArray>, "IsHolding_VtVec3dArray"
        )
        .m((PXR_NS::VtVec3dArray const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtVec3dArray>, "Get_VtVec3dArray"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtVec4dArray>("value"), "from_VtVec4dArray")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtVec4dArray>, "IsHolding_VtVec4dArray"
        )
        .m((PXR_NS::VtVec4dArray const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtVec4dArray>, "Get_VtVec4dArray"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtVec2hArray>("value"), "from_VtVec2hArray")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtVec2hArray>, "IsHolding_VtVec2hArray"
        )
        .m((PXR_NS::VtVec2hArray const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtVec2hArray>, "Get_VtVec2hArray"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtVec3hArray>("value"), "from_VtVec3hArray")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtVec3hArray>, "IsHolding_VtVec3hArray"
        )
        .m((PXR_NS::VtVec3hArray const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtVec3hArray>, "Get_VtVec3hArray"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtVec4hArray>("value"), "from_VtVec4hArray")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtVec4hArray>, "IsHolding_VtVec4hArray"
        )
        .m((PXR_NS::VtVec4hArray const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtVec4hArray>, "Get_VtVec4hArray"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtQuatfArray>("value"), "from_VtQuatfArray")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtQuatfArray>, "IsHolding_VtQuatfArray"
        )
        .m((PXR_NS::VtQuatfArray const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtQuatfArray>, "Get_VtQuatfArray"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtQuatdArray>("value"), "from_VtQuatdArray")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtQuatdArray>, "IsHolding_VtQuatdArray"
        )
        .m((PXR_NS::VtQuatdArray const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtQuatdArray>, "Get_VtQuatdArray"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtQuathArray>("value"), "from_VtQuathArray")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtQuathArray>, "IsHolding_VtQuathArray"
        )
        .m((PXR_NS::VtQuathArray const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtQuathArray>, "Get_VtQuathArray"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtMatrix2dArray>("value"), "from_VtMatrix2dArray")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtMatrix2dArray>, "IsHolding_VtMatrix2dArray"
        )
        .m((PXR_NS::VtMatrix2dArray const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtMatrix2dArray>, "Get_VtMatrix2dArray"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtMatrix3dArray>("value"), "from_VtMatrix3dArray")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtMatrix3dArray>, "IsHolding_VtMatrix3dArray"
        )
        .m((PXR_NS::VtMatrix3dArray const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtMatrix3dArray>, "Get_VtMatrix3dArray"
        )

        .ctor(bbl::Class<Value>::Ctor<PXR_NS::VtMatrix4dArray>("value"), "from_VtMatrix4dArray")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::VtMatrix4dArray>, "IsHolding_VtMatrix4dArray"
        )
        .m((PXR_NS::VtMatrix4dArray const& (Value::*)() const&)
            &Value::Get<PXR_NS::VtMatrix4dArray>, "Get_VtMatrix4dArray"
        )

    ;

    bbl::Class<std::vector<PXR_NS::VtValue>>("ValueVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::VtValue)
    ;

    bbl::Class<PXR_NS::VtTokenArray>("TokenArray")
        VTARRAY_METHODS(PXR_NS::TfToken)
    ;

    bbl::Class<PXR_NS::VtStringArray>("StringArray")
        VTARRAY_METHODS(std::string)
    ;

    bbl::Class<PXR_NS::VtBoolArray>("BoolArray")
        VTARRAY_METHODS(bool)
    ;

    bbl::Class<PXR_NS::VtUCharArray>("UCharArray")
        VTARRAY_METHODS(uint8_t)
    ;

    bbl::Class<PXR_NS::VtIntArray>("IntArray")
        VTARRAY_METHODS(int)
    ;

    bbl::Class<PXR_NS::VtUIntArray>("UIntArray")
        VTARRAY_METHODS(uint32_t)
    ;

    bbl::Class<PXR_NS::VtInt64Array>("Int64Array")
        VTARRAY_METHODS(int64_t)
    ;

    bbl::Class<PXR_NS::VtUInt64Array>("UInt64Array")
        VTARRAY_METHODS(uint64_t)
    ;

    bbl::Class<PXR_NS::VtFloatArray>("FloatArray")
        VTARRAY_METHODS(float)
    ;

    bbl::Class<PXR_NS::VtDoubleArray>("DoubleArray")
        VTARRAY_METHODS(double)
    ;

    bbl::Class<PXR_NS::VtDictionary>("Dictionary")
        .m(&PXR_NS::VtDictionary::operator[], "op_index")
    ;
}


#endif
