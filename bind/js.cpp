#if defined(__clang__)

#include "babble"
#include "babble-std"

#include <pxr/base/js/value.h>
#include <pxr/base/js/types.h>
#include <pxr/base/tf/token.h>

BBL_MODULE(js) {
    // clang-format off
    bbl::Class<PXR_NS::JsArray>("Array")
        BBL_STD_VECTOR_METHODS(PXR_NS::JsValue)
        ;

    bbl::Class<PXR_NS::JsObject>("Object")
        ;

    bbl::Class<PXR_NS::JsValue>("Value")
        .ctor(bbl::Class<PXR_NS::JsValue>::Ctor<>(), "new")
        .ctor(bbl::Class<PXR_NS::JsValue>::Ctor<PXR_NS::JsObject const&>(), "from_object")
        .ctor(bbl::Class<PXR_NS::JsValue>::Ctor<PXR_NS::JsArray const&>(), "from_array")
        .ctor(bbl::Class<PXR_NS::JsValue>::Ctor<char const*>(), "from_string")
        .ctor(bbl::Class<PXR_NS::JsValue>::Ctor<bool>(), "from_bool")
        .ctor(bbl::Class<PXR_NS::JsValue>::Ctor<int>(), "from_int")
        .ctor(bbl::Class<PXR_NS::JsValue>::Ctor<int64_t>(), "from_int64_t")
        .ctor(bbl::Class<PXR_NS::JsValue>::Ctor<uint64_t>(), "from_uint64_t")
        .ctor(bbl::Class<PXR_NS::JsValue>::Ctor<double>(), "from_double")
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

    bbl::Class<std::pair<PXR_NS::TfToken, PXR_NS::JsValue>>("TokenValuePair")
    ;

}


#endif
