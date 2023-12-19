#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/pathExpression.h>



BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfPathExpression>()
        .ctor(bbl::Class<PXR_NS::SdfPathExpression>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::SdfPathExpression>::Ctor<const std::string &, const std::string &>("expr", "parseContext"), "ctor_01")
        .m((PXR_NS::SdfPathExpression (*)(PXR_NS::SdfPathExpression &&))
            &PXR_NS::SdfPathExpression::MakeComplement, "MakeComplement_00")
        .m((PXR_NS::SdfPathExpression (*)(const PXR_NS::SdfPathExpression &))
            &PXR_NS::SdfPathExpression::MakeComplement, "MakeComplement_01")
        .m((PXR_NS::SdfPathExpression (*)(PXR_NS::SdfPathExpression::Op, PXR_NS::SdfPathExpression &&, PXR_NS::SdfPathExpression &&))
            &PXR_NS::SdfPathExpression::MakeOp, "MakeOp_00")
        .m((PXR_NS::SdfPathExpression (*)(PXR_NS::SdfPathExpression::Op, const PXR_NS::SdfPathExpression &, const PXR_NS::SdfPathExpression &))
            &PXR_NS::SdfPathExpression::MakeOp, "MakeOp_01")
        .m((PXR_NS::SdfPathExpression (*)(const PXR_NS::SdfPathExpression::ExpressionReference &))
            &PXR_NS::SdfPathExpression::MakeAtom, "MakeAtom_01")
        .m((PXR_NS::SdfPathExpression (*)(const PXR_NS::SdfPathExpression::PathPattern &))
            &PXR_NS::SdfPathExpression::MakeAtom, "MakeAtom_03")
        // .m(&PXR_NS::SdfPathExpression::Walk)
        // .m((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(const PXR_NS::SdfPath &, const PXR_NS::SdfPath &) const)
        //     &PXR_NS::SdfPathExpression::ReplacePrefix, "ReplacePrefix_00")
        // .m((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(const PXR_NS::SdfPath &, const PXR_NS::SdfPath &))
        //     &PXR_NS::SdfPathExpression::ReplacePrefix, "ReplacePrefix_01")
        // .m(&PXR_NS::SdfPathExpression::IsAbsolute)
        // .m((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(const PXR_NS::SdfPath &) const)
        //     &PXR_NS::SdfPathExpression::MakeAbsolute, "MakeAbsolute_00")
        // .m((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(const PXR_NS::SdfPath &))
        //     &PXR_NS::SdfPathExpression::MakeAbsolute, "MakeAbsolute_01")
        // .m(&PXR_NS::SdfPathExpression::ContainsExpressionReferences)
        // .m((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(TfFunctionRef<SdfPathExpression (const PXR_NS::SdfPathExpression::ExpressionReference &)>) const)
        //     &PXR_NS::SdfPathExpression::ResolveReferences, "ResolveReferences_00")
        // .m((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(TfFunctionRef<SdfPathExpression (const PXR_NS::SdfPathExpression::ExpressionReference &)>))
        //     &PXR_NS::SdfPathExpression::ResolveReferences, "ResolveReferences_01")
        // .m((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(const PXR_NS::SdfPathExpression &) const)
        //     &PXR_NS::SdfPathExpression::ComposeOver, "ComposeOver_00")
        // .m((PXR_NS::SdfPathExpression (PXR_NS::SdfPathExpression::*)(const PXR_NS::SdfPathExpression &))
        //     &PXR_NS::SdfPathExpression::ComposeOver, "ComposeOver_01")
        .m(&PXR_NS::SdfPathExpression::IsComplete)
        .m(&PXR_NS::SdfPathExpression::GetDebugString)
        .m(&PXR_NS::SdfPathExpression::IsEmpty)
        .m(&PXR_NS::SdfPathExpression::operator bool, "op_bool")
        .m(&PXR_NS::SdfPathExpression::GetParseError)
    ;

    bbl::Class<PXR_NS::SdfPathExpression::PathPattern>()
        .ctor(bbl::Class<PXR_NS::SdfPathExpression::PathPattern>::Ctor<>(), "default")
        .m((void (PXR_NS::SdfPathExpression::PathPattern::*)(const std::string &, PXR_NS::SdfPredicateExpression &&))
            &PXR_NS::SdfPathExpression::PathPattern::AppendChild, "AppendChild_00")
        .m((void (PXR_NS::SdfPathExpression::PathPattern::*)(const std::string &, const PXR_NS::SdfPredicateExpression &))
            &PXR_NS::SdfPathExpression::PathPattern::AppendChild, "AppendChild_01")
        .m((void (PXR_NS::SdfPathExpression::PathPattern::*)(const std::string &))
            &PXR_NS::SdfPathExpression::PathPattern::AppendChild, "AppendChild_02")
        .m((void (PXR_NS::SdfPathExpression::PathPattern::*)(const std::string &, PXR_NS::SdfPredicateExpression &&))
            &PXR_NS::SdfPathExpression::PathPattern::AppendProperty, "AppendProperty_00")
        .m((void (PXR_NS::SdfPathExpression::PathPattern::*)(const std::string &, const PXR_NS::SdfPredicateExpression &))
            &PXR_NS::SdfPathExpression::PathPattern::AppendProperty, "AppendProperty_01")
        .m((void (PXR_NS::SdfPathExpression::PathPattern::*)(const std::string &))
            &PXR_NS::SdfPathExpression::PathPattern::AppendProperty, "AppendProperty_02")
        // .m((const PXR_NS::SdfPath & (PXR_NS::SdfPathExpression::PathPattern::*)() const)
        //     &PXR_NS::SdfPathExpression::PathPattern::GetPrefix, "GetPrefix_00")
        // .m((PXR_NS::SdfPath (PXR_NS::SdfPathExpression::PathPattern::*)())
        //     &PXR_NS::SdfPathExpression::PathPattern::GetPrefix, "GetPrefix_01")
        .m((void (PXR_NS::SdfPathExpression::PathPattern::*)(PXR_NS::SdfPath &&))
            &PXR_NS::SdfPathExpression::PathPattern::SetPrefix, "SetPrefix_00")
        .m((void (PXR_NS::SdfPathExpression::PathPattern::*)(const PXR_NS::SdfPath &))
            &PXR_NS::SdfPathExpression::PathPattern::SetPrefix, "SetPrefix_01")
        .m(&PXR_NS::SdfPathExpression::PathPattern::GetDebugString)
        // .m((const std::vector<PXR_NS::SdfPathExpression::PathPattern::Component> & (PXR_NS::SdfPathExpression::PathPattern::*)() const)
        //     &PXR_NS::SdfPathExpression::PathPattern::GetComponents, "GetComponents_00")
        // .m((std::vector<PXR_NS::SdfPathExpression::PathPattern::Component> (PXR_NS::SdfPathExpression::PathPattern::*)())
        //     &PXR_NS::SdfPathExpression::PathPattern::GetComponents, "GetComponents_01")
        // .m((const std::vector<PXR_NS::SdfPredicateExpression> & (PXR_NS::SdfPathExpression::PathPattern::*)() const)
        //     &PXR_NS::SdfPathExpression::PathPattern::GetPredicateExprs, "GetPredicateExprs_00")
        // .m((std::vector<PXR_NS::SdfPredicateExpression> (PXR_NS::SdfPathExpression::PathPattern::*)())
        //     &PXR_NS::SdfPathExpression::PathPattern::GetPredicateExprs, "GetPredicateExprs_01")
        .m(&PXR_NS::SdfPathExpression::PathPattern::IsProperty)
        .m(&PXR_NS::SdfPathExpression::PathPattern::operator bool, "op_bool")
    ;

    bbl::Class<PXR_NS::SdfPathExpression::PathPattern::Component>()
        .ctor(bbl::Class<PXR_NS::SdfPathExpression::PathPattern::Component>::Ctor<>(), "default")
        .m(&PXR_NS::SdfPathExpression::PathPattern::Component::IsStretch)
    ;

    bbl::Class<PXR_NS::SdfPathExpression::ExpressionReference>()
        .ctor(bbl::Class<PXR_NS::SdfPathExpression::ExpressionReference>::Ctor<>(), "default")
    ;

    bbl::Enum<PXR_NS::SdfPathExpression::Op>();

}

#endif


