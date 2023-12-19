#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/specializes.h>

BBL_MODULE(usd) {
    // clang-format off

    bbl::Class<PXR_NS::UsdSpecializes>("Specializes")
        .m(&PXR_NS::UsdSpecializes::AddSpecialize)
        .m(&PXR_NS::UsdSpecializes::RemoveSpecialize)
        .m(&PXR_NS::UsdSpecializes::ClearSpecializes)
        .m(&PXR_NS::UsdSpecializes::SetSpecializes)
        .m((PXR_NS::UsdPrim const& (PXR_NS::UsdSpecializes::*)() const)
            &PXR_NS::UsdSpecializes::GetPrim
        )
        .m(&PXR_NS::UsdSpecializes::operator bool, "op_bool")
    ;

}

#endif

