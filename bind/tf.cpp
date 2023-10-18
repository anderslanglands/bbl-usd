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
        .ctor(bbl::Ctor<PXR_NS::TfEnum>(), "new")
        .m(&PXR_NS::TfEnum::GetValueAsInt)
        .m(&PXR_NS::TfEnum::GetName)
        .m(&PXR_NS::TfEnum::GetDisplayName)
        .m(&PXR_NS::TfEnum::GetFullName)
        ;

    bbl::Class<PXR_NS::TfToken>("Token")
        .opaque_ptr()
        .ctor(bbl::Ctor<Token>(), "new")
        .m((Token& (Token::*)(Token const&))&Token::operator=, "op_assign")
        .m(&Token::GetText)
        ;

    bbl::Class<PXR_NS::TfType>("Type")
        ;

    bbl::Class<PXR_NS::TfTokenVector>("TokenVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::TfToken)
        ;
}


#endif

