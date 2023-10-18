#if defined(__clang__)

#include "babble"
#include "babble-std"

#include <pxr/usd/pcp/arc.h>
#include <pxr/usd/pcp/cache.h>
#include <pxr/usd/pcp/node.h>
#include <pxr/usd/pcp/primIndex.h>
#include <pxr/usd/pcp/mapFunction.h>
#include <pxr/usd/pcp/mapExpression.h>
#include <pxr/usd/pcp/types.h>

namespace bblext {

PXR_NS::PcpArcType Arc_get_type(PXR_NS::PcpArc const& arc) {
    return arc.type;
}

PXR_NS::PcpNodeRef Arc_get_parent(PXR_NS::PcpArc const& arc) {
    return arc.parent;
}

PXR_NS::PcpNodeRef Arc_get_origin(PXR_NS::PcpArc const& arc) {
    return arc.origin;
}

PXR_NS::PcpMapExpression const& Arc_get_map_to_parent(PXR_NS::PcpArc const& arc) {
    return arc.mapToParent;
}

int Arc_get_sibling_num_at_origin(PXR_NS::PcpArc const& arc) {
    return arc.siblingNumAtOrigin;
}

int Arc_get_namespace_depth(PXR_NS::PcpArc const& arc) {
    return arc.namespaceDepth;
}


}

BBL_MODULE(pcp) {

    // clang-format off

    bbl::Class<PXR_NS::PcpArc>("Arc")
        ;

    bbl::fn(&bblext::Arc_get_type);
    bbl::fn(&bblext::Arc_get_parent);
    bbl::fn(&bblext::Arc_get_origin);
    bbl::fn(&bblext::Arc_get_map_to_parent);
    bbl::fn(&bblext::Arc_get_sibling_num_at_origin);
    bbl::fn(&bblext::Arc_get_namespace_depth);

    bbl::Enum<PXR_NS::PcpArcType>("ArcType");

    bbl::Class<PXR_NS::PcpCache>("Cache")
    ;

    bbl::Class<PXR_NS::PcpMapFunction>("MapFunction")
        .ctor(bbl::Ctor<PXR_NS::PcpMapFunction>(), "default")
        .m(&PXR_NS::PcpMapFunction::IsNull)
        .m(&PXR_NS::PcpMapFunction::IsIdentity)
        .m(&PXR_NS::PcpMapFunction::IsIdentityPathMapping)
        .m(&PXR_NS::PcpMapFunction::HasRootIdentity)
        .m(&PXR_NS::PcpMapFunction::MapSourceToTarget)
        .m(&PXR_NS::PcpMapFunction::MapTargetToSource)
        .m(&PXR_NS::PcpMapFunction::Compose)
        .m(&PXR_NS::PcpMapFunction::ComposeOffset)
        .m(&PXR_NS::PcpMapFunction::GetInverse)
        .m(&PXR_NS::PcpMapFunction::GetSourceToTargetMap)
        .m(&PXR_NS::PcpMapFunction::GetTimeOffset)
        .m(&PXR_NS::PcpMapFunction::GetString)
        .m(&PXR_NS::PcpMapFunction::Hash)
        .m(&PXR_NS::PcpMapFunction::Create)
        .m(&PXR_NS::PcpMapFunction::Identity)
        .m(&PXR_NS::PcpMapFunction::IdentityPathMap)
        ;

    bbl::Class<PXR_NS::PcpNodeRef>("NodeRef")
        ;

    bbl::Class<PXR_NS::PcpMapExpression>("MapExpression")
    ;

    bbl::Class<PXR_NS::PcpMapFunction::PathMap>("MapFunctionPathMap")
    ;

    bbl::Class<PXR_NS::PcpPrimIndex>("PrimIndex");

    bbl::Class<PXR_NS::PcpVariantFallbackMap>("VariantFallbackMap")
        ;
}


#endif

