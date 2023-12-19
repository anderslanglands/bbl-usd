#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/primRange.h>

namespace bblext {

auto PrimSiblingIterator_op_eq(PXR_NS::UsdPrimSiblingIterator const& lhs, PXR_NS::UsdPrimSiblingIterator const& rhs) -> bool {
    return lhs == rhs;
}

}

BBL_MODULE(usd) {
    // clang-format off

    bbl::Class<PXR_NS::UsdPrimRange>("PrimRange")
        .opaque_ptr()
        .ctor(bbl::Class<PXR_NS::UsdPrimRange>::Ctor<PXR_NS::UsdPrim>("start"), "from_prim")
        .m(&PXR_NS::UsdPrimRange::begin)
        .m(&PXR_NS::UsdPrimRange::end);

    bbl::Class<PXR_NS::UsdPrimRange::iterator>("PrimRangeIterator")
        .opaque_ptr()
        .ctor(bbl::Class<PXR_NS::UsdPrimRange::iterator>::Ctor<>(), "new")
        .m(&PXR_NS::UsdPrimRange::iterator::operator++, "op_inc")
        .m((PXR_NS::UsdPrimRange::iterator & (PXR_NS::UsdPrimRange::iterator::*)(PXR_NS::UsdPrimRange::iterator const&)) 
            &PXR_NS::UsdPrimRange::iterator::operator=, "op_assign"
        )
        .m((bool(PXR_NS::UsdPrimRange::iterator::*)(PXR_NS::UsdPrimRange::iterator const&) const) 
            &PXR_NS::UsdPrimRange::iterator::operator==, "op_eq"
        )
        .m(&PXR_NS::UsdPrimRange::iterator::operator*, "deref");

    bbl::Class<PXR_NS::UsdPrimSiblingRange>("PrimSiblingRange")
        .m(&PXR_NS::UsdPrimSiblingRange::begin)
        .m(&PXR_NS::UsdPrimSiblingRange::end)
    ;

    bbl::Class<PXR_NS::UsdPrimSiblingIterator>("PrimSiblingIterator")
        .m(&PXR_NS::UsdPrimSiblingIterator::operator*, "deref")
        .m(&PXR_NS::UsdPrimSiblingIterator::operator++, "op_inc")
    ;

    bbl::fn(&bblext::PrimSiblingIterator_op_eq);

    bbl::Class<PXR_NS::UsdPrimSubtreeRange>("PrimSubtreeRange")
    ;

}

#endif

