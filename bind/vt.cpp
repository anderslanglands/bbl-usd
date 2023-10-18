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

BBL_MODULE(vt) {
    // clang-format off

    using Value = PXR_NS::VtValue;

    bbl::Class<PXR_NS::VtValue>("Value")
        .ctor(bbl::Ctor<Value>(), "new")
        .ctor(bbl::Ctor<Value, float>("obj"))
        .m(&Value::IsArrayValued)
        .m(&Value::IsEmpty)
        .m(&Value::GetArraySize)
        .m(&Value::GetType)
        .m(&Value::GetTypeName)

        .ctor(bbl::Ctor<Value, bool>("value"), "from_bool")
        .m((bool (Value::*)() const)
            &Value::IsHolding<bool>, "IsHolding_bool"
        )
        .m((bool const& (Value::*)() const&)
            &Value::Get<bool>, "Get_bool"
        ) 

        .ctor(bbl::Ctor<Value, int>("value"), "from_int")
        .m((bool (Value::*)() const)
            &Value::IsHolding<int>, "IsHolding_int"
        )
        .m((int const& (Value::*)() const&)
            &Value::Get<int>, "Get_int"
        ) 

        .ctor(bbl::Ctor<Value, float>("value"), "from_float")
        .m((bool (Value::*)() const)
            &Value::IsHolding<float>, "IsHolding_float"
        )
        .m((float const& (Value::*)() const&)
            &Value::Get<float>, "Get_float"
        ) 

        .ctor(bbl::Ctor<Value, double>("value"), "from_double")
        .m((bool (Value::*)() const)
            &Value::IsHolding<double>, "IsHolding_double"
        )
        .m((double const& (Value::*)() const&)
            &Value::Get<double>, "Get_double"
        ) 

        .ctor(bbl::Ctor<Value, PXR_NS::TfToken>("value"), "from_TfToken")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::TfToken>, "IsHolding_TfToken"
        )
        .m((PXR_NS::TfToken const& (Value::*)() const&)
            &Value::Get<PXR_NS::TfToken>, "Get_TfToken"
        ) 

        .ctor(bbl::Ctor<Value, PXR_NS::SdfAssetPath>("value"), "from_SdfAssetPath")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::SdfAssetPath>, "IsHolding_SdfAssetPath"
        )
        .m((PXR_NS::SdfAssetPath const& (Value::*)() const&)
            &Value::Get<PXR_NS::SdfAssetPath>, "Get_SdfAssetPath"
        ) 

        .ctor(bbl::Ctor<Value, std::string>("value"), "from_string")
        .m((bool (Value::*)() const)
            &Value::IsHolding<std::string>, "IsHolding_string"
        )
        .m((std::string const& (Value::*)() const&)
            &Value::Get<std::string>, "Get_string"
        ) 

        .ctor(bbl::Ctor<Value, PXR_NS::GfVec2d>("value"), "from_GfVec2d")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfVec2d>, "IsHolding_GfVec2d"
        )
        .m((PXR_NS::GfVec2d const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfVec2d>, "Get_GfVec2d"
        ) 

        .ctor(bbl::Ctor<Value, PXR_NS::GfVec2h>("value"), "from_GfVec2h")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfVec2h>, "IsHolding_GfVec2h"
        )
        .m((PXR_NS::GfVec2h const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfVec2h>, "Get_GfVec2h"
        ) 

        .ctor(bbl::Ctor<Value, PXR_NS::GfVec2f>("value"), "from_GfVec2f")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfVec2f>, "IsHolding_GfVec2f"
        )
        .m((PXR_NS::GfVec2f const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfVec2f>, "Get_GfVec2f"
        ) 

        .ctor(bbl::Ctor<Value, PXR_NS::GfVec2i>("value"), "from_GfVec2i")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfVec2i>, "IsHolding_GfVec2i"
        )
        .m((PXR_NS::GfVec2i const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfVec2i>, "Get_GfVec2i"
        ) 

        .ctor(bbl::Ctor<Value, PXR_NS::GfVec3d>("value"), "from_GfVec3d")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfVec3d>, "IsHolding_GfVec3d"
        )
        .m((PXR_NS::GfVec3d const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfVec3d>, "Get_GfVec3d"
        ) 

        .ctor(bbl::Ctor<Value, PXR_NS::GfVec3h>("value"), "from_GfVec3h")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfVec3h>, "IsHolding_GfVec3h"
        )
        .m((PXR_NS::GfVec3h const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfVec3h>, "Get_GfVec3h"
        ) 

        .ctor(bbl::Ctor<Value, PXR_NS::GfVec3f>("value"), "from_GfVec3f")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfVec3f>, "IsHolding_GfVec3f"
        )
        .m((PXR_NS::GfVec3f const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfVec3f>, "Get_GfVec3f"
        ) 

        .ctor(bbl::Ctor<Value, PXR_NS::GfVec3i>("value"), "from_GfVec3i")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfVec3i>, "IsHolding_GfVec3i"
        )
        .m((PXR_NS::GfVec3i const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfVec3i>, "Get_GfVec3i"
        ) 

        .ctor(bbl::Ctor<Value, PXR_NS::GfVec4d>("value"), "from_GfVec4d")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfVec4d>, "IsHolding_GfVec4d"
        )
        .m((PXR_NS::GfVec4d const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfVec4d>, "Get_GfVec4d"
        ) 

        .ctor(bbl::Ctor<Value, PXR_NS::GfVec4h>("value"), "from_GfVec4h")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfVec4h>, "IsHolding_GfVec4h"
        )
        .m((PXR_NS::GfVec4h const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfVec4h>, "Get_GfVec4h"
        ) 

        .ctor(bbl::Ctor<Value, PXR_NS::GfVec4f>("value"), "from_GfVec4f")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfVec4f>, "IsHolding_GfVec4f"
        )
        .m((PXR_NS::GfVec4f const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfVec4f>, "Get_GfVec4f"
        ) 

        .ctor(bbl::Ctor<Value, PXR_NS::GfVec4i>("value"), "from_GfVec4i")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfVec4i>, "IsHolding_GfVec4i"
        )
        .m((PXR_NS::GfVec4i const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfVec4i>, "Get_GfVec4i"
        ) 

        .ctor(bbl::Ctor<Value, PXR_NS::GfQuatd>("value"), "from_GfQuatd")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfQuatd>, "IsHolding_GfQuatd"
        )
        .m((PXR_NS::GfQuatd const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfQuatd>, "Get_GfQuatd"
        ) 

        .ctor(bbl::Ctor<Value, PXR_NS::GfQuatf>("value"), "from_GfQuatf")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfQuatf>, "IsHolding_GfQuatf"
        )
        .m((PXR_NS::GfQuatf const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfQuatf>, "Get_GfQuatf"
        ) 

        .ctor(bbl::Ctor<Value, PXR_NS::GfQuath>("value"), "from_GfQuath")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfQuath>, "IsHolding_GfQuath"
        )
        .m((PXR_NS::GfQuath const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfQuath>, "Get_GfQuath"
        ) 

        .ctor(bbl::Ctor<Value, PXR_NS::GfMatrix2d>("value"), "from_GfMatrix2d")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfMatrix2d>, "IsHolding_GfMatrix2d"
        )
        .m((PXR_NS::GfMatrix2d const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfMatrix2d>, "Get_GfMatrix2d"
        ) 

        .ctor(bbl::Ctor<Value, PXR_NS::GfMatrix2f>("value"), "from_GfMatrix2f")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfMatrix2f>, "IsHolding_GfMatrix2f"
        )
        .m((PXR_NS::GfMatrix2f const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfMatrix2f>, "Get_GfMatrix2f"
        ) 

        .ctor(bbl::Ctor<Value, PXR_NS::GfMatrix3d>("value"), "from_GfMatrix3d")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfMatrix3d>, "IsHolding_GfMatrix3d"
        )
        .m((PXR_NS::GfMatrix3d const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfMatrix3d>, "Get_GfMatrix3d"
        ) 

        .ctor(bbl::Ctor<Value, PXR_NS::GfMatrix3f>("value"), "from_GfMatrix3f")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfMatrix3f>, "IsHolding_GfMatrix3f"
        )
        .m((PXR_NS::GfMatrix3f const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfMatrix3f>, "Get_GfMatrix3f"
        ) 

        .ctor(bbl::Ctor<Value, PXR_NS::GfMatrix4d>("value"), "from_GfMatrix4d")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfMatrix4d>, "IsHolding_GfMatrix4d"
        )
        .m((PXR_NS::GfMatrix4d const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfMatrix4d>, "Get_GfMatrix4d"
        ) 

        .ctor(bbl::Ctor<Value, PXR_NS::GfMatrix4f>("value"), "from_GfMatrix4f")
        .m((bool (Value::*)() const)
            &Value::IsHolding<PXR_NS::GfMatrix4f>, "IsHolding_GfMatrix4f"
        )
        .m((PXR_NS::GfMatrix4f const& (Value::*)() const&)
            &Value::Get<PXR_NS::GfMatrix4f>, "Get_GfMatrix4f"
        ) 

        ;

    bbl::Class<PXR_NS::VtTokenArray>("TokenArray")
        VTARRAY_METHODS(PXR_NS::TfToken)
        ;

    bbl::Class<PXR_NS::VtBoolArray>("BoolArray")
        VTARRAY_METHODS(bool)
        ;

    bbl::Class<PXR_NS::VtIntArray>("IntArray")
        VTARRAY_METHODS(int)
        ;

    bbl::Class<PXR_NS::VtFloatArray>("FloatArray")
        VTARRAY_METHODS(float)
        ;

    bbl::Class<PXR_NS::VtDoubleArray>("DoubleArray")
        VTARRAY_METHODS(double)
        ;

    bbl::Class<PXR_NS::VtDictionary>("Dictionary")
        ;
}


#endif

