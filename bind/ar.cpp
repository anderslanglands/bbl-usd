#if defined(__clang__)

#include "babble"
#include "babble-std"

#include <pxr/usd/ar/resolverContext.h>

BBL_MODULE(ar) {
    bbl::Class<PXR_NS::ArResolverContext>("ResolverContext")
        ;
}


#endif

