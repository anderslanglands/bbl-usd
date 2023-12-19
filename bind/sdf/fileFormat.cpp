#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/sdf/fileFormat.h>

BBL_MODULE(sdf) {
    // clang-format off

    bbl::Class<PXR_NS::SdfFileFormat>()
        .m(&PXR_NS::SdfFileFormat::GetSchema)
        .m(&PXR_NS::SdfFileFormat::GetFormatId)
        .m(&PXR_NS::SdfFileFormat::GetTarget)
        .m(&PXR_NS::SdfFileFormat::GetFileCookie)
        .m(&PXR_NS::SdfFileFormat::GetVersionString)
        .m(&PXR_NS::SdfFileFormat::IsPrimaryFormatForExtensions)
        .m(&PXR_NS::SdfFileFormat::GetFileExtensions)
        .m(&PXR_NS::SdfFileFormat::GetPrimaryFileExtension)
        .m(&PXR_NS::SdfFileFormat::IsSupportedExtension)
        .m(&PXR_NS::SdfFileFormat::IsPackage)
        .m(&PXR_NS::SdfFileFormat::GetPackageRootLayerPath)
        .m(&PXR_NS::SdfFileFormat::GetDefaultFileFormatArguments)
        .m(&PXR_NS::SdfFileFormat::InitData)
        .m(&PXR_NS::SdfFileFormat::InitDetachedData)
        .m(&PXR_NS::SdfFileFormat::NewLayer)
        .m(&PXR_NS::SdfFileFormat::ShouldSkipAnonymousReload)
        .m(&PXR_NS::SdfFileFormat::ShouldReadAnonymousLayers)
        .m(&PXR_NS::SdfFileFormat::CanRead)
        .m(&PXR_NS::SdfFileFormat::Read)
        .m(&PXR_NS::SdfFileFormat::ReadDetached)
        .m(&PXR_NS::SdfFileFormat::WriteToFile)
        .m(&PXR_NS::SdfFileFormat::ReadFromString)
        // .m(&PXR_NS::SdfFileFormat::WriteToStream)
        .m(&PXR_NS::SdfFileFormat::WriteToString)
        .m(&PXR_NS::SdfFileFormat::GetExternalAssetDependencies)
        .m(&PXR_NS::SdfFileFormat::SupportsReading)
        .m(&PXR_NS::SdfFileFormat::SupportsWriting)
        .m(&PXR_NS::SdfFileFormat::SupportsEditing)
        .m(&PXR_NS::SdfFileFormat::GetFileExtension)
        .m(&PXR_NS::SdfFileFormat::FindAllFileFormatExtensions)
        .m(&PXR_NS::SdfFileFormat::FindAllDerivedFileFormatExtensions)
        .m(&PXR_NS::SdfFileFormat::FormatSupportsReading)
        .m(&PXR_NS::SdfFileFormat::FormatSupportsWriting)
        .m(&PXR_NS::SdfFileFormat::FormatSupportsEditing)
        .m(&PXR_NS::SdfFileFormat::FindById)
        .m((PXR_NS::SdfFileFormatConstPtr (*)(const std::string &, const std::string &))
            &PXR_NS::SdfFileFormat::FindByExtension, "FindByExtension_00")
        .m((PXR_NS::SdfFileFormatConstPtr (*)(const std::string &, const PXR_NS::SdfFileFormat::FileFormatArguments &))
            &PXR_NS::SdfFileFormat::FindByExtension, "FindByExtension_01")
    ;

    bbl::Class<PXR_NS::SdfFileFormatConstPtr>("FileFormatConstPtr")
        .smartptr_to<PXR_NS::SdfFileFormat const>()
    ;

    bbl::Class<PXR_NS::SdfFileFormat::FileFormatArguments>("FileFormatFileFormatArguments");
}

#endif


