#if defined(__clang__)

#include "babble"
#include "babble-std"

#include <pxr/base/js/value.h>
#include <pxr/base/js/types.h>

BBL_MODULE(js) {
    // clang-format off
    bbl::Class<PXR_NS::JsArray>("Array")
        BBL_STD_VECTOR_METHODS(PXR_NS::JsValue)
        ;

    bbl::Class<PXR_NS::JsObject>("Object")
        ;

    bbl::Class<PXR_NS::JsValue>("Value")
        .ctor(bbl::Ctor<PXR_NS::JsValue>(), "new")
        .ctor(bbl::Ctor<PXR_NS::JsValue, PXR_NS::JsObject const&>(), "from_object")
        .ctor(bbl::Ctor<PXR_NS::JsValue, PXR_NS::JsArray const&>(), "from_array")
        .ctor(bbl::Ctor<PXR_NS::JsValue, char const*>(), "from_string")
        .ctor(bbl::Ctor<PXR_NS::JsValue, bool>(), "from_bool")
        .ctor(bbl::Ctor<PXR_NS::JsValue, int>(), "from_int")
        .ctor(bbl::Ctor<PXR_NS::JsValue, int64_t>(), "from_int64_t")
        .ctor(bbl::Ctor<PXR_NS::JsValue, uint64_t>(), "from_uint64_t")
        .ctor(bbl::Ctor<PXR_NS::JsValue, double>(), "from_double")
        .m(&PXR_NS::JsValue::GetJsObject)
        .m(&PXR_NS::JsValue::GetJsArray)
        .m(&PXR_NS::JsValue::GetBool)
        .m(&PXR_NS::JsValue::GetInt)
        .m(&PXR_NS::JsValue::GetInt64)
        .m(&PXR_NS::JsValue::GetUInt64)
        .m(&PXR_NS::JsValue::GetReal)
        .m(&PXR_NS::JsValue::IsObject)
        .m(&PXR_NS::JsValue::IsArray)
        .m(&PXR_NS::JsValue::IsBool)
        .m(&PXR_NS::JsValue::IsInt)
        .m(&PXR_NS::JsValue::IsUInt64)
        .m(&PXR_NS::JsValue::IsReal)
        ;

}


#endif