#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/predicateExpression.h>

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfPredicateExpression>("PredicateExpression")
        .ctor(bbl::Class<PXR_NS::SdfPredicateExpression>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::SdfPredicateExpression>::Ctor<const std::string &, const std::string &>("expr", "context"), "ctor_01")
        // Need to handle rvalue refs for these: need to std::move the ref in the call
        // .m(&PXR_NS::SdfPredicateExpression::MakeNot)
        // .m(&PXR_NS::SdfPredicateExpression::MakeOp)
        // .m(&PXR_NS::SdfPredicateExpression::MakeCall)
        // .m(&PXR_NS::SdfPredicateExpression::Walk)
        // .m(&PXR_NS::SdfPredicateExpression::WalkWithOpStack)
        .m(&PXR_NS::SdfPredicateExpression::GetText)
        .m(&PXR_NS::SdfPredicateExpression::IsEmpty)
        .m(&PXR_NS::SdfPredicateExpression::operator bool, "op_bool")
        // .m((const std::string & (PXR_NS::SdfPredicateExpression::*)() const)
        //     &PXR_NS::SdfPredicateExpression::GetParseError, "GetParseError_00")
        // .m((std::string (PXR_NS::SdfPredicateExpression::*)() const)
        //     &PXR_NS::SdfPredicateExpression::GetParseError, "GetParseError_01")
    ;

    bbl::Class<PXR_NS::SdfPredicateExpression::FnArg>("PredicateExpressionFnArg")
        .ctor(bbl::Class<PXR_NS::SdfPredicateExpression::FnArg>::Ctor<>(), "default")
        .m(&PXR_NS::SdfPredicateExpression::FnArg::Positional)
        .m(&PXR_NS::SdfPredicateExpression::FnArg::Keyword)
    ;

    bbl::Class<PXR_NS::SdfPredicateExpression::FnCall>("PredicateExpressionFnCall")
        .ctor(bbl::Class<PXR_NS::SdfPredicateExpression::FnCall>::Ctor<>(), "default")
    ;

    bbl::Enum<PXR_NS::SdfPredicateExpression::FnCall::Kind>("PredicateExpressionFnCallKind");

    bbl::Enum<PXR_NS::SdfPredicateExpression::Op>("PredicateExpressionOp");


}

#endif


