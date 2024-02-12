#if defined(__clang__)

#include "babble"
#include "babble-std"

#include <vector>
#include <string>
#include <set>
#include <unordered_set>

BBL_MODULE(std) {

    bbl::Class<std::string>("String")
        .ctor(bbl::Class<std::string>::Ctor<>(), "default")
        .ctor(bbl::Class<std::string>::Ctor<char const*>(), "from_char_ptr")
        .ctor(bbl::Class<std::string>::Ctor<char const*, size_t>(), "from_char_ptr_and_count")
        .ctor(bbl::Class<std::string>::Ctor<std::string&>(), "from_string")
        .m(&std::string::c_str)
        .m((void (std::string::*)(size_t)) &std::string::resize)
        .m((char* (std::string::*)()) &std::string::data)
        .m((const char* (std::string::*)() const) &std::string::data, "data_const")
        .m(&std::string::size)

        .ignore_all_unbound()
    ;

    // We provide macros for automating the binding of common types' methods
    bbl::Class<std::vector<std::string>>("StringVector")
        BBL_STD_VECTOR_METHODS(std::string)
    ;

    BBL_STD_PAIR((std::pair<std::string, std::string>), StringPair);
    BBL_STD_PAIR((std::pair<std::string, bool>), StringBoolPair);

    bbl::Class<std::vector<std::pair<std::string, std::string>>>("StringPairVector")
        BBL_STD_VECTOR_METHODS((std::pair<std::string, std::string>))
    ;

    BBL_STD_SET(std::set<std::string>, StringSet);
    BBL_STD_SET(std::unordered_set<std::string>, StringUnorderedSet);

    bbl::Class<std::vector<double>>("DoubleVector")
        BBL_STD_VECTOR_METHODS(double)
    ;

    bbl::Class<std::vector<bool>>("BoolVector")
        .m(&std::vector<bool>::size)
        .m(&std::vector<bool>::empty)
        .m((bool (std::vector<bool>::*)(size_t) const)
            &std::vector<bool>::at
        )

        .ignore_all_unbound()
    ;

    BBL_STD_SET(std::set<double>, DoubleSet);

    BBL_STD_PAIR((std::pair<double, double>), DoublePair);
    BBL_STD_PAIR((std::pair<float, float>), FloatPair);
    
    bbl::Class<std::type_info>("StdTypeInfo")
        .m(&std::type_info::name)
        .m(&std::type_info::hash_code)

        .ignore_all_unbound()
    ;
}


#endif

