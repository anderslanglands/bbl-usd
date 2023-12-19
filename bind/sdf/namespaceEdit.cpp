#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/namespaceEdit.h>


namespace bblext {

PXR_NS::SdfPath const&
NamespaceEdit_get_current_path(PXR_NS::SdfNamespaceEdit const& edit) {
    return edit.currentPath;
}

PXR_NS::SdfPath const&
NamespaceEdit_get_new_path(PXR_NS::SdfNamespaceEdit const& edit) {
    return edit.newPath;
}

PXR_NS::SdfNamespaceEdit::Index const&
NamespaceEdit_get_index(PXR_NS::SdfNamespaceEdit const& edit) {
    return edit.index;
}

PXR_NS::SdfNamespaceEditDetail::Result
NamespaceEditDetail_get_result(PXR_NS::SdfNamespaceEditDetail const& detail) {
    return detail.result;
}

PXR_NS::SdfNamespaceEdit const&
NamespaceEditDetail_get_edit(PXR_NS::SdfNamespaceEditDetail const& detail) {
    return detail.edit;
}

char const*
NamespaceEditDetail_get_reason(PXR_NS::SdfNamespaceEditDetail const& detail) {
    return detail.reason.c_str();
}

}


BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfNamespaceEdit>("NamespaceEdit")
        .ctor(bbl::Class<PXR_NS::SdfNamespaceEdit>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::SdfNamespaceEdit>::Ctor<PXR_NS::SdfNamespaceEdit::Path const&, PXR_NS::SdfNamespaceEdit::Path const&, PXR_NS::SdfNamespaceEdit::Index>(), "from_paths")
        .m(&PXR_NS::SdfNamespaceEdit::Remove)
        .m(&PXR_NS::SdfNamespaceEdit::Rename)
        .m(&PXR_NS::SdfNamespaceEdit::Reorder)
        .m(&PXR_NS::SdfNamespaceEdit::Reparent)
        .m(&PXR_NS::SdfNamespaceEdit::ReparentAndRename)
        ;
    bbl::fn(&bblext::NamespaceEdit_get_current_path);
    bbl::fn(&bblext::NamespaceEdit_get_new_path);
    bbl::fn(&bblext::NamespaceEdit_get_index);

    bbl::Class<std::vector<PXR_NS::SdfNamespaceEdit>>("NamespaceEditVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfNamespaceEdit)
        ;

    
    bbl::Class<PXR_NS::SdfNamespaceEditDetail>("NamespaceEditDetail")
        .ctor(bbl::Class<PXR_NS::SdfNamespaceEditDetail>::Ctor<>(), "default")
    ;

    bbl::Enum<PXR_NS::SdfNamespaceEditDetail::Result>("NamespaceEditDetailResult")
    ;

    bbl::fn(&bblext::NamespaceEditDetail_get_edit);
    bbl::fn(&bblext::NamespaceEditDetail_get_result);
    bbl::fn(&bblext::NamespaceEditDetail_get_reason);

    bbl::Class<PXR_NS::SdfNamespaceEditDetailVector>("NamespaceEditDetailVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfNamespaceEditDetail)
        ;

    bbl::Class<PXR_NS::SdfBatchNamespaceEdit>("BatchNamespaceEdit")
        .ctor(bbl::Class<PXR_NS::SdfBatchNamespaceEdit>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::SdfBatchNamespaceEdit>::Ctor<const PXR_NS::SdfNamespaceEditVector &>("edits"), "from_edits")
        .m((void (PXR_NS::SdfBatchNamespaceEdit::*)(PXR_NS::SdfNamespaceEdit const&))
            &PXR_NS::SdfBatchNamespaceEdit::Add)
        .m((void (PXR_NS::SdfBatchNamespaceEdit::*)(PXR_NS::SdfNamespaceEdit::Path const&, PXR_NS::SdfNamespaceEdit::Path const&, PXR_NS::SdfNamespaceEdit::Index))
            &PXR_NS::SdfBatchNamespaceEdit::Add,"Add_from_paths")
        .m(&PXR_NS::SdfBatchNamespaceEdit::GetEdits)
        .m(&PXR_NS::SdfBatchNamespaceEdit::Process)
    ;

    bbl::Class<PXR_NS::SdfBatchNamespaceEdit::CanEdit>("BatchNamespaceEditCanEdit");
    bbl::Class<PXR_NS::SdfBatchNamespaceEdit::HasObjectAtPath>("BatchNamespaceEditHasObjectAtPath");

}

#endif


