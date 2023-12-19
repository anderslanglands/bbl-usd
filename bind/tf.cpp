#if defined(__clang__)

#include "babble"
#include "babble-std"

#include <pxr/base/tf/token.h>
#include <pxr/base/tf/type.h>
#include <pxr/base/tf/enum.h>

using Token = PXR_NS::TfToken;

BBL_MODULE(tf) {
    // clang-format off

    bbl::Class<PXR_NS::TfEnum>("Enum")
        .ctor(bbl::Class<PXR_NS::TfEnum>::Ctor<>(), "new")
        .m(&PXR_NS::TfEnum::GetValueAsInt)
        .m(&PXR_NS::TfEnum::GetName)
        .m(&PXR_NS::TfEnum::GetDisplayName)
        .m(&PXR_NS::TfEnum::GetFullName)
        ;

    bbl::Class<PXR_NS::TfToken>("Token")
        .opaque_ptr()
        .ctor(bbl::Class<Token>::Ctor<>(), "new")
        .m(&Token::GetText)
        ;

    bbl::Class<PXR_NS::TfType>("Type")
        ;

    bbl::Class<PXR_NS::TfTokenVector>("TokenVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::TfToken)
        ;

    bbl::Class<std::pair<PXR_NS::TfToken, PXR_NS::TfToken>>("TokenTokenPair")
    ;
}


#endif

