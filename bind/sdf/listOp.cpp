#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/listOp.h>

BBL_MODULE(sdf) {
    // clang-format off
    using StringListOp = PXR_NS::SdfListOp<std::string>;

    bbl::Class<PXR_NS::SdfListOp<std::string>>("StringListOp")
        .ctor(bbl::Class<StringListOp>::Ctor<>(), "default")
        .m(&StringListOp::HasKeys)
        .m(&StringListOp::IsExplicit)
        .m(&StringListOp::GetExplicitItems)
        .m(&StringListOp::GetAddedItems)
        .m(&StringListOp::GetPrependedItems)
        .m(&StringListOp::GetAppendedItems)
        .m(&StringListOp::GetDeletedItems)
        .m(&StringListOp::GetOrderedItems)
        .m(&StringListOp::GetAppliedItems)
        .m(&StringListOp::GetItems)
        .m(&StringListOp::GetAppliedItems)
        .m(&StringListOp::SetExplicitItems)
        .m(&StringListOp::SetAddedItems)
        .m(&StringListOp::SetPrependedItems)
        .m(&StringListOp::SetAppendedItems)
        .m(&StringListOp::SetDeletedItems)
        .m(&StringListOp::SetOrderedItems)
        .m(&StringListOp::SetItems)
        .m(&StringListOp::Clear)
        .m(&StringListOp::ClearAndMakeExplicit)
        // .m((void (StringListOp::*)(StringListOp::ItemVector *, const StringListOp::ApplyCallback &) const)
        //     &StringListOp::ApplyOperations, "ApplyOperations")
        // .m(&StringListOp::ModifyOperations)
        .m(&StringListOp::ReplaceOperations)
        .m(&StringListOp::ComposeOperations)
        ;

    // bbl::Class<StringListOp::ApplyCallback>("StringListOpApplyCallback")
    // ;

    // bbl::Class<StringListOp::ModifyCallback>("StringListOpModifyCallback")
    // ;

    bbl::Enum<PXR_NS::SdfListOpType>("ListOpType");

}

#endif


