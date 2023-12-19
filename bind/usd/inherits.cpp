#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/inherits.h>

BBL_MODULE(usd) {
    // clang-format off

    bbl::Class<PXR_NS::UsdInherits>("Inherits")
        .m(&PXR_NS::UsdInherits::AddInherit)
        .m(&PXR_NS::UsdInherits::RemoveInherit)
        .m(&PXR_NS::UsdInherits::ClearInherits)
        .m(&PXR_NS::UsdInherits::SetInherits)
        .m(&PXR_NS::UsdInherits::GetAllDirectInherits)
        .m((PXR_NS::UsdPrim const&(PXR_NS::UsdInherits::*)() const)
            &PXR_NS::UsdInherits::GetPrim
        )
        .m(&PXR_NS::UsdInherits::operator bool, "op_bool")
    ;

}

#endif

