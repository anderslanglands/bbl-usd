#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/apiSchemaBase.h>
#include <pxr/usd/usd/schemaBase.h>

BBL_MODULE(usd) {
    // clang-format off

    bbl::Class<PXR_NS::UsdAPISchemaBase>("APISchemaBase")
        .m(&PXR_NS::UsdAPISchemaBase::GetSchemaAttributeNames)
    ;

    bbl::Class<PXR_NS::UsdSchemaBase>("SchemaBase")
        .ctor(bbl::Class<PXR_NS::UsdSchemaBase>::Ctor<const PXR_NS::UsdPrim &>("prim"), "from_prim")
        .m(&PXR_NS::UsdSchemaBase::IsConcrete)
        .m(&PXR_NS::UsdSchemaBase::IsTyped)
        .m(&PXR_NS::UsdSchemaBase::IsAPISchema)
        .m(&PXR_NS::UsdSchemaBase::IsAppliedAPISchema)
        .m(&PXR_NS::UsdSchemaBase::IsMultipleApplyAPISchema)
        .m(&PXR_NS::UsdSchemaBase::GetSchemaKind)
        .m(&PXR_NS::UsdSchemaBase::GetPrim)
        .m(&PXR_NS::UsdSchemaBase::GetPath)
        .m(&PXR_NS::UsdSchemaBase::GetSchemaClassPrimDefinition)
        .m(&PXR_NS::UsdSchemaBase::GetSchemaAttributeNames)
        .m(&PXR_NS::UsdSchemaBase::operator bool)
    ;

}

#endif


