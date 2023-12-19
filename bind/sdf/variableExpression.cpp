#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/variableExpression.h>

namespace bblext {

PXR_NS::SdfVariableExpression* VariableExpression_from_string(char const* str) {
    return new PXR_NS::SdfVariableExpression(str);
}

char const*
VariableExpression_GetString(PXR_NS::SdfVariableExpression const& ve) {
    return ve.GetString().c_str();
}

PXR_NS::VtValue const& VariableExpressionResult_value(
    PXR_NS::SdfVariableExpression::Result const& ver) {
    return ver.value;
}

} // namespace bblext

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfVariableExpression>("VariableExpression")
        .ctor(bbl::Class<PXR_NS::SdfVariableExpression>::Ctor<>(), "default")
        .m(&PXR_NS::SdfVariableExpression::IsExpression)
        .m(&PXR_NS::SdfVariableExpression::IsValidVariableType)
        .m(&PXR_NS::SdfVariableExpression::operator bool, "op_bool")
        .m(&PXR_NS::SdfVariableExpression::GetString)
        .m(&PXR_NS::SdfVariableExpression::GetErrors)
        .m(&PXR_NS::SdfVariableExpression::Evaluate)
    ;

    bbl::Class<PXR_NS::SdfVariableExpression::Result>("VariableExpressionResult")
    ;

}

#endif

