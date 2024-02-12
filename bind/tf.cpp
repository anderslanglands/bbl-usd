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
        .m(&PXR_NS::TfEnum::AddName)
        .m(&PXR_NS::TfEnum::_AddName)
        .m(&PXR_NS::TfEnum::GetValueFromFullName)
        .m(&PXR_NS::TfEnum::IsKnownEnumType)
        .m((std::vector<std::string> (*)(PXR_NS::TfEnum))
            &PXR_NS::TfEnum::GetAllNames
        )
        .m((bool (PXR_NS::TfEnum::*)(PXR_NS::TfEnum const&) const)
            &PXR_NS::TfEnum::operator==
        )
        .m((bool (PXR_NS::TfEnum::*)(PXR_NS::TfEnum const&) const)
            &PXR_NS::TfEnum::operator<
        )
        .ignore((bool (PXR_NS::TfEnum::*)(PXR_NS::TfEnum const&) const)
            &PXR_NS::TfEnum::operator!=
        )
        .ignore((bool (PXR_NS::TfEnum::*)(PXR_NS::TfEnum const&) const)
            &PXR_NS::TfEnum::operator<=
        )
        .ignore((bool (PXR_NS::TfEnum::*)(PXR_NS::TfEnum const&) const)
            &PXR_NS::TfEnum::operator>=
        )
        .ignore((bool (PXR_NS::TfEnum::*)(PXR_NS::TfEnum const&) const)
            &PXR_NS::TfEnum::operator>
        )
        .ignore((bool (PXR_NS::TfEnum::*)(std::type_info const&) const)
            &PXR_NS::TfEnum::IsA
        )
        .ignore(&PXR_NS::TfEnum::GetType)
        .ignore(&PXR_NS::TfEnum::GetTypeFromName)
        .ignore((PXR_NS::TfEnum (*)(std::type_info const&, std::string const&, bool*))
            &PXR_NS::TfEnum::GetValueFromName
        )
        .m((std::vector<std::string> (*)(std::type_info const&))
            &PXR_NS::TfEnum::GetAllNames, "GetAllNames_from_type_info"
        )
    ;

    bbl::Class<PXR_NS::TfToken>("Token")
        .opaque_ptr()
        .ctor(bbl::Class<Token>::Ctor<const char*>(), "new")
        .m(&Token::GetText)
        .m(&Token::Hash)
        .m(&Token::size)
        .m(&Token::IsImmortal)
        .m(&Token::IsEmpty)
        .m(&Token::Find)
        .m(&Token::Swap)
        .m((bool (Token::*)(Token const&) const)
            &Token::operator==
        )
        .m((bool (Token::*)(char const*) const)
            &Token::operator==, "op_eq_c_str"
        )
        .m(&Token::operator<)
        .ignore(&Token::operator<=)
        .ignore(&Token::operator>=)
        .ignore(&Token::operator>)
        .ignore((bool (Token::*)(Token const&) const)
            &Token::operator!=
        )
        .ignore((bool (Token::*)(char const*) const)
            &Token::operator!=
        )
        .ignore((bool (Token::*)(std::string const&) const)
            &Token::operator!=
        )
        .ignore((bool (Token::*)(std::string const&) const)
            &Token::operator==
        )
        .ignore(&Token::operator std::string const&)
        .ignore(&Token::data)
        .ignore(&Token::GetString)
    ;

    bbl::Class<PXR_NS::TfType>("Type")
        .ctor(bbl::Class<PXR_NS::TfType>::Ctor<>(), "default")
        .m(&PXR_NS::TfType::GetUnknownType)
        .m(&PXR_NS::TfType::operator==, "op_eq")
        .m(&PXR_NS::TfType::operator!=, "op_neq")
        .m(&PXR_NS::TfType::operator<, "op_lt")
        .m(&PXR_NS::TfType::operator>, "op_gt")
        .m(&PXR_NS::TfType::operator<=, "op_lte")
        .m(&PXR_NS::TfType::operator>=, "op_gte")
        .m(&PXR_NS::TfType::FindByName)
        .m((const PXR_NS::TfType & (PXR_NS::TfType::*)(const std::string &) const)
            &PXR_NS::TfType::FindDerivedByName, "FindDerivedByName")
        .m(&PXR_NS::TfType::GetRoot)
        .m(&PXR_NS::TfType::GetTypeName)
        .m(&PXR_NS::TfType::GetAliases)
        .m(&PXR_NS::TfType::GetBaseTypes)
        .m(&PXR_NS::TfType::GetNBaseTypes)
        .m(&PXR_NS::TfType::GetDirectlyDerivedTypes)
        .m(&PXR_NS::TfType::GetCanonicalType)
        .m(&PXR_NS::TfType::GetAllDerivedTypes)
        .m(&PXR_NS::TfType::GetAllAncestorTypes)
        .m((bool (PXR_NS::TfType::*)(PXR_NS::TfType) const)
            &PXR_NS::TfType::IsA, "IsA")
        .m(&PXR_NS::TfType::IsUnknown)
        .m(&PXR_NS::TfType::operator!, "op_not")
        .m(&PXR_NS::TfType::IsRoot)
        .m(&PXR_NS::TfType::IsEnumType)
        .m(&PXR_NS::TfType::IsPlainOldDataType)
        .m(&PXR_NS::TfType::GetSizeof)
        .m((const PXR_NS::TfType & (*)(const std::string &))
            &PXR_NS::TfType::Declare, "Declare")
        .ignore((PXR_NS::TfType const& (PXR_NS::TfType::*)(std::unique_ptr<PXR_NS::TfType::FactoryBase>) const)
            &PXR_NS::TfType::Factory
        )
    ;

    BBL_STD_SET(std::set<PXR_NS::TfType>, TypeSet);

    bbl::Class<std::vector<PXR_NS::TfType>>("TypeVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::TfType)
    ;

    bbl::Class<PXR_NS::TfTokenVector>("TokenVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::TfToken)
    ;

    BBL_STD_SET(PXR_NS::TfToken::Set, TokenSet);

    BBL_STD_PAIR((std::pair<PXR_NS::TfToken, PXR_NS::TfToken>), TokenTokenPair);
}


#endif

