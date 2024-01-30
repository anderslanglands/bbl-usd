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
    ;

    // We provide macros for automating the binding of common types' methods
    bbl::Class<std::vector<std::string>>("StringVector")
        BBL_STD_VECTOR_METHODS(std::string)
    ;

    bbl::Class<std::pair<std::string, std::string>>("StringPair")
    ;

    bbl::Class<std::vector<std::pair<std::string, std::string>>>("StringPairVector")
        BBL_STD_VECTOR_METHODS((std::pair<std::string, std::string>))
    ;

    bbl::Class<std::set<std::string>>("StringSet");
    bbl::Class<std::unordered_set<std::string>>("StringUnorderedSet");

    bbl::Class<std::vector<double>>("DoubleVector")
        BBL_STD_VECTOR_METHODS(double);

    bbl::Class<std::set<double>>("DoubleSet");

    bbl::Class<std::pair<double, double>>("DoublePair");
    bbl::Class<std::pair<float, float>>("FloatPair");
    
}


#endif

