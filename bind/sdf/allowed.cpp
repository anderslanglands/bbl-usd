#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/allowed.h>

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfAllowed>("Allowed")
        .ctor(bbl::Class<PXR_NS::SdfAllowed>::Ctor<>(), "new")
        .ctor(bbl::Class<PXR_NS::SdfAllowed>::Ctor<bool>(), "from_bool")
        .ctor(bbl::Class<PXR_NS::SdfAllowed>::Ctor<char const*>(), "from_string")
        .ctor(bbl::Class<PXR_NS::SdfAllowed>::Ctor<bool, char const*>(),
              "from_bool_and_string")
        .m(&PXR_NS::SdfAllowed::IsAllowed)
        .m(&PXR_NS::SdfAllowed::GetWhyNot)
    ;

}

#endif


