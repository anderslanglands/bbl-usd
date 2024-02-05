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
#include <pxr/usd/ar/inMemoryAsset.h>
#include <pxr/usd/ar/defineResolver.h>
#include <iostream>

namespace bblext {
    std::shared_ptr<PXR_NS::ArAsset> asset_from_bytes(const char* bytes, size_t len) {
        char* buf = new char[len];
        memcpy(buf, bytes, len);

        std::shared_ptr<char> buffer;
        buffer.reset(buf, std::default_delete<char[]>());

        return PXR_NS::ArInMemoryAsset::FromBuffer(buffer, len);
    }

    void set_ar_resolver_factory(
        const PXR_NS::TfType& type,
        void* create_identifier_for_new_asset,
        void* create_identifier,
        void* open_asset,
        void* resolve,
        void* resolve_for_new_asset,
        void* open_asset_for_write,
        void* get_extension,
        void* get_modification_timestamp,
        void* close_writeable_asset,
        void* open_writable_asset,
        void* write_writable_asset
    ) {
        typedef void (*CREATE_IDENTIFIER_FN_PTR)(const std::string *assetPath, const PXR_NS::ArResolvedPath *anchorAssetPath, std::string** output);
        typedef void (*OPEN_ASSET_FN_PTR)(const PXR_NS::ArResolvedPath *resolvedPath, std::shared_ptr<PXR_NS::ArAsset>** output);
        typedef void (*RESOLVE_FN_PTR)(const std::string *assetPath, PXR_NS::ArResolvedPath** output);
        typedef void (*OPEN_ASSET_FOR_WRITE_FN_PTR)(const PXR_NS::ArResolvedPath *, PXR_NS::ArResolver::WriteMode, std::shared_ptr<PXR_NS::ArWritableAsset>** output);
        typedef void (*GET_EXTENSION_FN_PTR)(const std::string* assetPath, std::string** output);
        typedef void (*GET_MODIFICATION_TIMESTAMP_FN_PTR)(const std::string *assetPath, const PXR_NS::ArResolvedPath *resolvedPath, PXR_NS::ArTimestamp** output);
        typedef bool (*CLOSE_WRITABLE_ASSET_FN_PTR)(void*);
        typedef void* (*OPEN_WRITABLE_ASSET_FN_PTR)(const PXR_NS::ArResolvedPath *resolvedPath, PXR_NS::ArResolver::WriteMode);
        typedef size_t (*WRITE_WRITABLE_ASSET_FN_PTR)(void*, const void*, size_t, size_t);

        class CustomFunctionWriteableAsset: public PXR_NS::ArWritableAsset {
            public:
                void* custom_data;
                CLOSE_WRITABLE_ASSET_FN_PTR close_writeable_asset;
                WRITE_WRITABLE_ASSET_FN_PTR write_writable_asset;

                CustomFunctionWriteableAsset(
                    const PXR_NS::ArResolvedPath &resolved_path,
                    PXR_NS::ArResolver::WriteMode writeMode,
                    CLOSE_WRITABLE_ASSET_FN_PTR close_writeable_asset_,
                    OPEN_WRITABLE_ASSET_FN_PTR open_writable_asset,
                    WRITE_WRITABLE_ASSET_FN_PTR write_writable_asset_
                ): write_writable_asset(write_writable_asset_), custom_data(open_writable_asset(&resolved_path, writeMode)), close_writeable_asset(close_writeable_asset_) {

                }

                bool Close() {
                    return close_writeable_asset(custom_data);
                }

                size_t Write(const void* src, size_t count, size_t offset) {
                    return write_writable_asset(custom_data, src, count, offset);
                }
        };

        struct Functions {
            CREATE_IDENTIFIER_FN_PTR create_identifier_for_new_asset;
            CREATE_IDENTIFIER_FN_PTR create_identifier;
            OPEN_ASSET_FN_PTR open_asset;
            RESOLVE_FN_PTR resolve;
            RESOLVE_FN_PTR resolve_for_new_asset;
            OPEN_ASSET_FOR_WRITE_FN_PTR open_asset_for_write;
            GET_EXTENSION_FN_PTR get_extension;
            GET_MODIFICATION_TIMESTAMP_FN_PTR get_modification_timestamp;
            CLOSE_WRITABLE_ASSET_FN_PTR close_writeable_asset;
            OPEN_WRITABLE_ASSET_FN_PTR open_writable_asset;
            WRITE_WRITABLE_ASSET_FN_PTR write_writable_asset;
        };

        Functions functions = {
            (CREATE_IDENTIFIER_FN_PTR) create_identifier_for_new_asset,
            (CREATE_IDENTIFIER_FN_PTR) create_identifier,
            (OPEN_ASSET_FN_PTR) open_asset,
            (RESOLVE_FN_PTR) resolve,
            (RESOLVE_FN_PTR) resolve_for_new_asset,
            (OPEN_ASSET_FOR_WRITE_FN_PTR) open_asset_for_write,
            (GET_EXTENSION_FN_PTR) get_extension,
            (GET_MODIFICATION_TIMESTAMP_FN_PTR) get_modification_timestamp,
            (CLOSE_WRITABLE_ASSET_FN_PTR) close_writeable_asset,
            (OPEN_WRITABLE_ASSET_FN_PTR) open_writable_asset,
            (WRITE_WRITABLE_ASSET_FN_PTR) write_writable_asset
        };

        class CustomFunctionArResolver : public PXR_NS::ArResolver {
            Functions functions;

        public:
            CustomFunctionArResolver(
                Functions functions_
            ): functions(functions_) {}

            std::string _CreateIdentifierForNewAsset(const std::string &assetPath, const PXR_NS::ArResolvedPath &anchorAssetPath) const override {
                std::cout << "_CreateIdentifierForNewAsset" << std::endl;
                std::string output;
                std::string* output_ptr = &output;
                functions.create_identifier_for_new_asset(&assetPath, &anchorAssetPath, &output_ptr);
                output = *output_ptr;
                return output;
            }

            std::string _CreateIdentifier(const std::string &assetPath, const PXR_NS::ArResolvedPath &anchorAssetPath) const override {
                std::cout << "_CreateIdentifier" << std::endl;
                if (functions.create_identifier) {
                    std::string output;
                    std::string* output_ptr = &output;
                    functions.create_identifier(&assetPath, &anchorAssetPath, &output_ptr);
                    output = *output_ptr;
                    return output;
                } else {
                    return assetPath;
                }
            }

            PXR_NS::ArResolvedPath _Resolve(const std::string &assetPath) const override {
                std::cout << "_Resolve" << std::endl;
                if (functions.resolve) {
                    PXR_NS::ArResolvedPath output;
                    PXR_NS::ArResolvedPath* output_ptr = &output;
                    functions.resolve(&assetPath, &output_ptr);
                    output = *output_ptr;
                    return output;
                } else {
                    return PXR_NS::ArResolvedPath(assetPath);
                }
            }

            PXR_NS::ArResolvedPath _ResolveForNewAsset(const std::string &assetPath) const override {
                std::cout << "_ResolveForNewAsset" << std::endl;
                if (functions.resolve_for_new_asset) {
                    PXR_NS::ArResolvedPath output;
                    PXR_NS::ArResolvedPath* output_ptr = &output;
                    functions.resolve_for_new_asset(&assetPath, &output_ptr);
                    output = *output_ptr;
                    return output;
                } else {
                    return PXR_NS::ArResolvedPath();
                }
            }

            std::shared_ptr<PXR_NS::ArAsset> _OpenAsset(const PXR_NS::ArResolvedPath &resolvedPath) const override {
                std::cout << "_OpenAsset" << std::endl;
                std::shared_ptr<PXR_NS::ArAsset> output;
                std::shared_ptr<PXR_NS::ArAsset>* output_ptr = &output;
                functions.open_asset(&resolvedPath, &output_ptr);
                output = *output_ptr;
                return output;
            }

            PXR_NS::ArTimestamp _GetModificationTimestamp(const std::string &assetPath, const PXR_NS::ArResolvedPath &resolvedPath) const override {
                std::cout << "_GetModificationTimestamp" << std::endl;

                if (functions.get_modification_timestamp) {
                    PXR_NS::ArTimestamp output;
                    PXR_NS::ArTimestamp* output_ptr = &output;
                    functions.get_modification_timestamp(&assetPath, &resolvedPath, &output_ptr);
                    output = *output_ptr;
                    return output;
                } else {
                    return PXR_NS::ArResolver::_GetModificationTimestamp(assetPath, resolvedPath);
                }
            }

            std::string _GetExtension(const std::string& assetPath) const override {
                std::cout << "_GetExtension" << std::endl;

                if (functions.get_extension) {
                    std::string output;
                    std::string* output_ptr = &output;
                    functions.get_extension(&assetPath, &output_ptr);
                    output = *output_ptr;
                    return output;
                } else {
                    return PXR_NS::ArResolver::_GetExtension(assetPath);
                }
            }

            std::shared_ptr<PXR_NS::ArWritableAsset> _OpenAssetForWrite(
                const PXR_NS::ArResolvedPath &resolvedPath,
                PXR_NS::ArResolver::WriteMode writeMode
            ) const override {
                std::cout << "_OpenAssetForWrite" << std::endl;
                return std::make_shared<CustomFunctionWriteableAsset>(resolvedPath, writeMode, functions.close_writeable_asset, functions.open_writable_asset, functions.write_writable_asset);
            }
        };

        class CustomFunctionArResolverFactory: public PXR_NS::Ar_ResolverFactoryBase {
            Functions functions;

        public:
            CustomFunctionArResolverFactory(
                Functions functions_
            ): functions(functions_) {}

            virtual PXR_NS::ArResolver* New() const {
                return new CustomFunctionArResolver(functions);
            }
        };

        type.SetFactory(
            std::unique_ptr<PXR_NS::TfType::FactoryBase>(
                new CustomFunctionArResolverFactory(functions)
            )
        );
    }
}

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

    bbl::fn(&bblext::set_ar_resolver_factory);
    bbl::fn(&bblext::asset_from_bytes);
}


#endif

