#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/common.h>
#include <pxr/usd/usd/interpolation.h>
#include <pxr/base/vt/value.h>

BBL_MODULE(usd) {
    // clang-format off

    bbl::Enum<PXR_NS::UsdInterpolationType>("InterpolationType");
    bbl::Enum<PXR_NS::UsdListPosition>("ListPosition");
    bbl::Enum<PXR_NS::UsdLoadPolicy>("LoadPolicy");
    bbl::Enum<PXR_NS::UsdSchemaKind>("SchemaKind");

    bbl::Class<PXR_NS::UsdMetadataValueMap>("MetadataValueMap")
        .m((PXR_NS::UsdMetadataValueMap::mapped_type const& (PXR_NS::UsdMetadataValueMap::*)(PXR_NS::UsdMetadataValueMap::key_type const&) const)
            &PXR_NS::UsdMetadataValueMap::at, "at_const"
        )
        .m((PXR_NS::UsdMetadataValueMap::mapped_type& (PXR_NS::UsdMetadataValueMap::*)(PXR_NS::UsdMetadataValueMap::key_type const&))
            &PXR_NS::UsdMetadataValueMap::at
        )
        ;

}

#endif

