#if defined(__clang__)

#include "babble"
#include "babble-std"

#include <pxr/usd/ar/asset.h>
#include <pxr/usd/ar/assetInfo.h>
#include <pxr/usd/ar/resolver.h>
#include <pxr/usd/ar/resolvedPath.h>
#include <pxr/usd/ar/resolverContext.h>
#include <pxr/usd/ar/timestamp.h>
#include <pxr/usd/ar/writableAsset.h>

BBL_MODULE(ar) {
    bbl::Class<PXR_NS::ArAsset>()
        .m(&PXR_NS::ArAsset::GetSize)
        .m(&PXR_NS::ArAsset::GetBuffer)
        .m(&PXR_NS::ArAsset::Read)
        .m(&PXR_NS::ArAsset::GetFileUnsafe)
        .m(&PXR_NS::ArAsset::GetDetachedAsset)
    ;

    bbl::Class<std::shared_ptr<PXR_NS::ArAsset>>("AssetSharedPtr")
        .smartptr_to<PXR_NS::ArAsset>()
    ;

    bbl::Class<std::shared_ptr<char const>>("ConstCharSharedPtr")
        .m(&std::shared_ptr<char const>::get)
    ;

    bbl::Class<std::pair<FILE*, size_t>>("FileSizePair")
    ;


    bbl::Class<PXR_NS::ArAssetInfo>("AssetInfo")
        .ctor(bbl::Class<PXR_NS::ArAssetInfo>::Ctor<>(), "default")
    ;

    bbl::Class<PXR_NS::ArResolvedPath>("ResolvedPath")
        .ctor(bbl::Class<PXR_NS::ArResolvedPath>::Ctor<std::string const&>("resolvedPath"), "ctor")
        .m(&PXR_NS::ArResolvedPath::GetPathString)
        .m(&PXR_NS::ArResolvedPath::GetHash)
        .m(&PXR_NS::ArResolvedPath::IsEmpty)
    ;

    bbl::Class<PXR_NS::ArResolver>("Resolver")
        .m(&PXR_NS::ArResolver::CreateIdentifier)
        .m(&PXR_NS::ArResolver::CreateIdentifierForNewAsset)
        .m(&PXR_NS::ArResolver::Resolve)
        .m(&PXR_NS::ArResolver::ResolveForNewAsset)
        .m(&PXR_NS::ArResolver::BindContext)
        .m(&PXR_NS::ArResolver::UnbindContext)
        .m(&PXR_NS::ArResolver::CreateDefaultContext)
        .m(&PXR_NS::ArResolver::CreateDefaultContextForAsset)
        .m((PXR_NS::ArResolverContext (PXR_NS::ArResolver::*)(const std::string &) const)
            &PXR_NS::ArResolver::CreateContextFromString, "CreateContextFromString_00")
        .m((PXR_NS::ArResolverContext (PXR_NS::ArResolver::*)(const std::string &, const std::string &) const)
            &PXR_NS::ArResolver::CreateContextFromString, "CreateContextFromString_01")
        .m(&PXR_NS::ArResolver::CreateContextFromStrings)
        .m(&PXR_NS::ArResolver::RefreshContext)
        .m(&PXR_NS::ArResolver::GetCurrentContext)
        .m(&PXR_NS::ArResolver::IsContextDependentPath)
        .m(&PXR_NS::ArResolver::GetExtension)
        .m(&PXR_NS::ArResolver::GetAssetInfo)
        .m(&PXR_NS::ArResolver::GetModificationTimestamp)
        .m(&PXR_NS::ArResolver::OpenAsset)
        .m(&PXR_NS::ArResolver::OpenAssetForWrite)
        .m(&PXR_NS::ArResolver::CanWriteAssetToPath)
        .m(&PXR_NS::ArResolver::BeginCacheScope)
        .m(&PXR_NS::ArResolver::EndCacheScope)
        .m(&PXR_NS::ArResolver::IsRepositoryPath)
        /** TODO: instantiate this template
        .m(&PXR_NS::ArResolver::_GetCurrentContextObject)
        */
    ;

    bbl::Enum<PXR_NS::ArResolver::WriteMode>("ResolvedWriteMode");

    bbl::Class<PXR_NS::ArResolverContext>("ResolverContext")
        .ctor(bbl::Class<PXR_NS::ArResolverContext>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::ArResolverContext>::Ctor<const std::vector<PXR_NS::ArResolverContext> &>("ctxs"), "ctor")
        /** TODO: instantiate this template
        .m(&PXR_NS::ArResolverContext::ArResolverContext)
        */
        .m(&PXR_NS::ArResolverContext::IsEmpty)
        /** TODO: instantiate this template
        .m(&PXR_NS::ArResolverContext::Get)
        */
        .m(&PXR_NS::ArResolverContext::GetDebugString)
        .m(&PXR_NS::ArResolverContext::operator==, "op_eq")
        .m(&PXR_NS::ArResolverContext::operator!=, "op_neq")
        .m(&PXR_NS::ArResolverContext::operator<, "op_lt")
    ;

    bbl::Class<std::vector<PXR_NS::ArResolverContext>>("ResolverContextVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::ArResolverContext)
    ;

    bbl::Class<PXR_NS::ArTimestamp>("Timestamp")
        .ctor(bbl::Class<PXR_NS::ArTimestamp>::Ctor<>(), "default")
        .ctor(bbl::Class<PXR_NS::ArTimestamp>::Ctor<double>("time"), "from_time")
        .m(&PXR_NS::ArTimestamp::IsValid)
        .m(&PXR_NS::ArTimestamp::GetTime)
    ;

    bbl::Class<PXR_NS::ArWritableAsset>("WritableAsset")
        .m(&PXR_NS::ArWritableAsset::Close)
        .m(&PXR_NS::ArWritableAsset::Write)
    ;

    bbl::Class<std::shared_ptr<PXR_NS::ArWritableAsset>>("WritableAssetSharedPtr")
        .smartptr_to<PXR_NS::ArWritableAsset>()
    ;


}


#endif

