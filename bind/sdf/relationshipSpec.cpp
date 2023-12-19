#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/relationshipSpec.h>
#include <pxr/usd/sdf/layerOffset.h>

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfRelationshipSpec>("RelationshipSpec")
        .m(&PXR_NS::SdfRelationshipSpec::New)
        .m(&PXR_NS::SdfRelationshipSpec::GetNoLoadHint)
        .m(&PXR_NS::SdfRelationshipSpec::SetNoLoadHint)
        .m(&PXR_NS::SdfRelationshipSpec::GetTargetPathList)
        .m(&PXR_NS::SdfRelationshipSpec::HasTargetPathList)
        .m(&PXR_NS::SdfRelationshipSpec::ClearTargetPathList)
        .m(&PXR_NS::SdfRelationshipSpec::ReplaceTargetPath)
        .m(&PXR_NS::SdfRelationshipSpec::RemoveTargetPath)
        ;


    bbl::Class<PXR_NS::SdfRelationshipSpecHandle>("RelationshipSpecHandle")
        .smartptr_to<PXR_NS::SdfRelationshipSpec>()
    ;

    bbl::Class<PXR_NS::SdfRelationshipSpecHandleVector>("RelationshipSpecHandleVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::SdfRelationshipSpecHandle)
    ;

    bbl::Class<PXR_NS::SdfRelationshipSpecView>("RelationshipSpecView");

    bbl::Class<std::pair<PXR_NS::SdfRelationshipSpecHandle, PXR_NS::SdfLayerOffset>>("RelationshipSpecHandleOffsetPair")
    ;

    bbl::Class<std::vector< std::pair<PXR_NS::SdfRelationshipSpecHandle, PXR_NS::SdfLayerOffset>>>( "RelationshipSpecHandleOffsetPairVector") 
        BBL_STD_VECTOR_METHODS((std::pair<PXR_NS::SdfRelationshipSpecHandle, PXR_NS::SdfLayerOffset>))
    ;

}

#endif


