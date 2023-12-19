#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/copyUtils.h>

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfCopySpecsValueEdit>()
        // editfunction missing a type
        // .ctor(bbl::Class<PXR_NS::SdfCopySpecsValueEdit>::Ctor<const PXR_NS::SdfCopySpecsValueEdit::EditFunction &>("edit"), "ctor_00")
        // Need to return a function here... not possible?
        // .m(&PXR_NS::SdfCopySpecsValueEdit::GetEditFunction)
    ;

    bbl::Class<PXR_NS::SdfCopySpecsValueEdit::EditFunction>("SdfCopySpecsValueEditEditFunction");
}

#endif


