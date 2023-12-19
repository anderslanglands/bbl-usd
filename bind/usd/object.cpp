#if defined(__clang__)

#include <babble>
#include <babble-std>

#include <pxr/usd/usd/object.h>
#include <pxr/usd/usd/attribute.h>
#include <pxr/usd/usd/relationship.h>
#include <pxr/usd/usd/property.h>
#include <pxr/usd/usd/prim.h>

namespace bblext {

auto UsdPrim_GetProperties(PXR_NS::UsdPrim prim) -> std::vector<PXR_NS::UsdProperty> {
    return prim.GetProperties();
}

auto UsdPrim_GetAuthoredProperties(PXR_NS::UsdPrim prim) -> std::vector<PXR_NS::UsdProperty> {
    return prim.GetAuthoredProperties();
}

}

BBL_MODULE(usd) {
    // clang-format off
    bbl::Class<PXR_NS::UsdAttribute>("Attribute")
        .ctor(bbl::Class<PXR_NS::UsdAttribute>::Ctor<>(), "default")
        .m(&PXR_NS::UsdAttribute::GetVariability)                                                   
        .m(&PXR_NS::UsdAttribute::SetVariability)                                               
        .m(&PXR_NS::UsdAttribute::GetTypeName)                                                  
        .m(&PXR_NS::UsdAttribute::SetTypeName)                                                  
        .m(&PXR_NS::UsdAttribute::GetRoleName)                                                  
        .m(&PXR_NS::UsdAttribute::AddConnection)                                                
        .m(&PXR_NS::UsdAttribute::RemoveConnection)                                             
        .m(&PXR_NS::UsdAttribute::SetConnections)                                               
        .m(&PXR_NS::UsdAttribute::ClearConnections)                                             
        .m(&PXR_NS::UsdAttribute::GetConnections)                                               
        .m(&PXR_NS::UsdAttribute::HasAuthoredConnections)                                       
        .m(&PXR_NS::UsdAttribute::GetColorSpace)                                                
        .m(&PXR_NS::UsdAttribute::SetColorSpace)                                                
        .m(&PXR_NS::UsdAttribute::HasColorSpace)                                                
        .m(&PXR_NS::UsdAttribute::ClearColorSpace)                                              
        .m(&PXR_NS::UsdAttribute::GetTimeSamples)                                               
        .m(&PXR_NS::UsdAttribute::GetTimeSamplesInInterval)                                     
        .m(&PXR_NS::UsdAttribute::GetNumTimeSamples)                                            
        .m(&PXR_NS::UsdAttribute::GetBracketingTimeSamples)                                     
        .m(&PXR_NS::UsdAttribute::HasValue)                                                     
        .m(&PXR_NS::UsdAttribute::HasAuthoredValueOpinion)                                      
        .m(&PXR_NS::UsdAttribute::HasAuthoredValue)                                             
        .m(&PXR_NS::UsdAttribute::HasFallbackValue)                                             
        .m(&PXR_NS::UsdAttribute::ValueMightBeTimeVarying)                                      
        .m((bool(PXR_NS::UsdAttribute::*)(PXR_NS::VtValue*, PXR_NS::UsdTimeCode) const) 
            &PXR_NS::UsdAttribute::Get
        ) 
        .m((PXR_NS::UsdResolveInfo(PXR_NS::UsdAttribute::*)(PXR_NS::UsdTimeCode) const) 
            &PXR_NS::UsdAttribute::GetResolveInfo, "GetResolveInfo_at_time"
        )
        .m((PXR_NS::UsdResolveInfo(PXR_NS::UsdAttribute::*)() const) 
            &PXR_NS::UsdAttribute::GetResolveInfo
        ) 
        .m((bool(PXR_NS::UsdAttribute::*)(PXR_NS::VtValue const&, PXR_NS::UsdTimeCode) const) 
            &PXR_NS::UsdAttribute::Set
        ) 
        .m(&PXR_NS::UsdAttribute::Clear)                                                        
        .m(&PXR_NS::UsdAttribute::ClearAtTime)                                                  
        .m(&PXR_NS::UsdAttribute::ClearDefault)                                                 
        .m(&PXR_NS::UsdAttribute::Block)                                                        
        .m(&PXR_NS::UsdAttribute::GetUnionedTimeSamples)                                        
        .m(&PXR_NS::UsdAttribute::GetUnionedTimeSamplesInInterval)
    ;

    bbl::Class<std::vector<PXR_NS::UsdAttribute>>("AttributeVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdAttribute);


    bbl::Class<PXR_NS::UsdObject>("Object")
        .ctor(bbl::Class<PXR_NS::UsdObject>::Ctor<>(), "default")
        .m(&PXR_NS::UsdObject::Is<PXR_NS::UsdAttribute>, "Is_Attribute")
        .m(&PXR_NS::UsdObject::Is<PXR_NS::UsdRelationship>, "Is_Relationship")
        .m(&PXR_NS::UsdObject::Is<PXR_NS::UsdProperty>, "Is_Property")
        .m(&PXR_NS::UsdObject::Is<PXR_NS::UsdPrim>, "Is_Prim")
        .m(&PXR_NS::UsdObject::As<PXR_NS::UsdAttribute>, "As_Attribute")
        .m(&PXR_NS::UsdObject::As<PXR_NS::UsdRelationship>, "As_Relationship")
        .m(&PXR_NS::UsdObject::As<PXR_NS::UsdProperty>, "As_Property")
        .m(&PXR_NS::UsdObject::As<PXR_NS::UsdPrim>, "As_Prim")
        .m((bool(PXR_NS::UsdObject::*)(PXR_NS::TfToken const&, PXR_NS::VtValue*) const) 
            &PXR_NS::UsdObject::GetMetadata, "GetMetadata_value"
        )
        .m((bool(PXR_NS::UsdObject::*)(PXR_NS::TfToken const&, PXR_NS::VtValue const&) const) 
            &PXR_NS::UsdObject::SetMetadata, "SetMetadata_value"
        )
        .m(&PXR_NS::UsdObject::ClearMetadata)                                                
        .m(&PXR_NS::UsdObject::HasMetadata)                                                  
        .m(&PXR_NS::UsdObject::HasAuthoredMetadata)                                          
        .m((bool(PXR_NS::UsdObject::*)(PXR_NS::TfToken const&, PXR_NS::TfToken const&, PXR_NS::VtValue*) const) 
            &PXR_NS::UsdObject::GetMetadataByDictKey, "GetMetadataByDictKey_value"
        )
        .m((bool(PXR_NS::UsdObject::*)(PXR_NS::TfToken const&, PXR_NS::TfToken const&, PXR_NS::VtValue const&) const)
            &PXR_NS::UsdObject::SetMetadataByDictKey, "SetMetadataByDictKey_value"
        )                                       
        .m(&PXR_NS::UsdObject::ClearMetadataByDictKey)                                       
        .m(&PXR_NS::UsdObject::HasMetadataDictKey)                                           
        .m(&PXR_NS::UsdObject::HasAuthoredMetadataDictKey)                                   
        .m(&PXR_NS::UsdObject::GetAllMetadata)                                               
        .m(&PXR_NS::UsdObject::GetAllAuthoredMetadata)                                       
        .m(&PXR_NS::UsdObject::IsHidden)                                                     
        .m(&PXR_NS::UsdObject::SetHidden)                                                    
        .m(&PXR_NS::UsdObject::ClearHidden)                                                  
        .m(&PXR_NS::UsdObject::HasAuthoredHidden)                                            
        .m(&PXR_NS::UsdObject::GetCustomData)                                                
        .m(&PXR_NS::UsdObject::GetCustomDataByKey)                                           
        .m(&PXR_NS::UsdObject::SetCustomData)                                                
        .m(&PXR_NS::UsdObject::SetCustomDataByKey)                                           
        .m(&PXR_NS::UsdObject::ClearCustomData)                                              
        .m(&PXR_NS::UsdObject::ClearCustomDataByKey)                                         
        .m(&PXR_NS::UsdObject::HasCustomData)                                                
        .m(&PXR_NS::UsdObject::HasCustomDataKey)                                             
        .m(&PXR_NS::UsdObject::HasAuthoredCustomData)                                        
        .m(&PXR_NS::UsdObject::HasAuthoredCustomDataKey)                                     
        .m(&PXR_NS::UsdObject::GetAssetInfo)                                                 
        .m(&PXR_NS::UsdObject::GetAssetInfoByKey)                                            
        .m(&PXR_NS::UsdObject::SetAssetInfo)                                                 
        .m(&PXR_NS::UsdObject::SetAssetInfoByKey)                                            
        .m(&PXR_NS::UsdObject::ClearAssetInfo)                                               
        .m(&PXR_NS::UsdObject::ClearAssetInfoByKey)                                          
        .m(&PXR_NS::UsdObject::HasAssetInfo)                                                 
        .m(&PXR_NS::UsdObject::HasAssetInfoKey)                                              
        .m(&PXR_NS::UsdObject::HasAuthoredAssetInfo)                                         
        .m(&PXR_NS::UsdObject::HasAuthoredAssetInfoKey)                                      
        .m(&PXR_NS::UsdObject::GetDocumentation)                                             
        .m(&PXR_NS::UsdObject::SetDocumentation)                                             
        .m(&PXR_NS::UsdObject::ClearDocumentation)                                           
        .m(&PXR_NS::UsdObject::HasAuthoredDocumentation)                                     
        .m(&PXR_NS::UsdObject::GetDisplayName)                                               
        .m(&PXR_NS::UsdObject::SetDisplayName)                                               
        .m(&PXR_NS::UsdObject::ClearDisplayName)                                             
        .m(&PXR_NS::UsdObject::HasAuthoredDisplayName)                                       
        .m(&PXR_NS::UsdObject::IsValid)                                                      
        .m(&PXR_NS::UsdObject::GetStage)                                                     
        .m(&PXR_NS::UsdObject::GetPath)                                                      
        .m(&PXR_NS::UsdObject::GetPrimPath)                                                  
        .m(&PXR_NS::UsdObject::GetPrim)                                                      
        .m(&PXR_NS::UsdObject::GetName)                                                      
        .m(&PXR_NS::UsdObject::GetNamespaceDelimiter)                                        
        .m(&PXR_NS::UsdObject::GetDescription)
    ;

    bbl::Enum<PXR_NS::UsdObjType>();
    bbl::fn(&PXR_NS::UsdIsSubtype);
    bbl::fn(&PXR_NS::UsdIsConvertible);
    bbl::fn(&PXR_NS::UsdIsConcrete);

    bbl::Class<std::set<PXR_NS::UsdObject>>("ObjectSet")
        .ctor(bbl::Class<std::set<PXR_NS::UsdObject>>::Ctor<>(), "default")
    ;

    bbl::Class<PXR_NS::UsdPrim>("Prim")
        .opaque_ptr()
        .ctor(bbl::Class<PXR_NS::UsdPrim>::Ctor<>(), "default")
        .m(&PXR_NS::UsdPrim::GetPrimTypeInfo)
        .m(&PXR_NS::UsdPrim::GetPrimDefinition)
        .m(&PXR_NS::UsdPrim::GetSpecifier)
        .m(&PXR_NS::UsdPrim::SetSpecifier)
        .m(&PXR_NS::UsdPrim::GetPrimStack)
        .m(&PXR_NS::UsdPrim::GetPrimStackWithLayerOffsets)
        .m(&PXR_NS::UsdPrim::GetTypeName)
        .m(&PXR_NS::UsdPrim::SetTypeName)
        .m(&PXR_NS::UsdPrim::ClearTypeName)
        .m(&PXR_NS::UsdPrim::HasAuthoredTypeName)
        .m(&PXR_NS::UsdPrim::IsActive)
        .m(&PXR_NS::UsdPrim::SetActive)
        .m(&PXR_NS::UsdPrim::ClearActive)
        .m(&PXR_NS::UsdPrim::HasAuthoredActive)
        .m(&PXR_NS::UsdPrim::IsLoaded)
        .m(&PXR_NS::UsdPrim::IsModel)
        .m(&PXR_NS::UsdPrim::IsGroup)
        .m(&PXR_NS::UsdPrim::IsAbstract)
        .m(&PXR_NS::UsdPrim::IsDefined)
        .m(&PXR_NS::UsdPrim::HasDefiningSpecifier)
        .m(&PXR_NS::UsdPrim::GetAppliedSchemas)
        .m(&PXR_NS::UsdPrim::GetPropertyNames)
        .m(&PXR_NS::UsdPrim::GetAuthoredPropertyNames)
        .m(&PXR_NS::UsdPrim::GetProperties, "GetProperties_matching_predicate")
        .m(&PXR_NS::UsdPrim::GetAuthoredProperties, "GetAuthoredProperties_matching_predicate")
        .m((std::vector<PXR_NS::UsdProperty>(PXR_NS::UsdPrim::*)(std::string const&) const) 
            &PXR_NS::UsdPrim::GetPropertiesInNamespace
        )
        .m((std::vector<PXR_NS::UsdProperty>(PXR_NS::UsdPrim::*)(std::string const&) const) 
            &PXR_NS::UsdPrim::GetAuthoredPropertiesInNamespace
        )
        .m(&PXR_NS::UsdPrim::GetPropertyOrder)
        .m(&PXR_NS::UsdPrim::SetPropertyOrder)
        .m(&PXR_NS::UsdPrim::ClearPropertyOrder)
        .m(&PXR_NS::UsdPrim::RemoveProperty)
        .m(&PXR_NS::UsdPrim::GetProperty)
        .m(&PXR_NS::UsdPrim::HasProperty)
        .m(&PXR_NS::UsdPrim::AddAppliedSchema)
        .m(&PXR_NS::UsdPrim::RemoveAppliedSchema)

        // IsA
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&) const) 
            &PXR_NS::UsdPrim::IsA
        )

        // methods can be renamed to give useful names to overloads
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&, PXR_NS::UsdSchemaVersion) const) 
            &PXR_NS::UsdPrim::IsA, "IsA_with_version"
        )

        // IsInFamily
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&) const) 
            &PXR_NS::UsdPrim::IsInFamily
        )
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&, PXR_NS::UsdSchemaRegistry::VersionPolicy) const) 
            &PXR_NS::UsdPrim::IsInFamily, "IsInFamily_with_policy"
        )
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&, PXR_NS::UsdSchemaVersion, PXR_NS::UsdSchemaRegistry::VersionPolicy) const) 
            &PXR_NS::UsdPrim::IsInFamily, "IsInFamily_with_policy_and_version"
        )
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfType const&, PXR_NS::UsdSchemaRegistry::VersionPolicy) const) 
            &PXR_NS::UsdPrim::IsInFamily, "IsInFamily_with_type"
        )
        .m(&PXR_NS::UsdPrim::GetVersionIfIsInFamily)

        // HasAPI
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfType const&) const) 
            &PXR_NS::UsdPrim::HasAPI
        )
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfType const&, PXR_NS::TfToken const&) const) 
            &PXR_NS::UsdPrim::HasAPI, "HasAPI_with_instance_name"
        )
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&) const) 
            &PXR_NS::UsdPrim::HasAPI, "HasAPI_with_schema_identifier"
        )
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&, PXR_NS::TfToken const&) const) 
            &PXR_NS::UsdPrim::HasAPI, "HasAPI_with_instance_name_and_schema_identifier"
        )

        // HasAPIInFamily
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&) const) 
            &PXR_NS::UsdPrim::HasAPIInFamily
        )
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&, PXR_NS::TfToken const&) const) 
            &PXR_NS::UsdPrim::HasAPIInFamily, "HasAPIInFamily_with_instance"
        )
        .m((bool(PXR_NS::UsdPrim::*)( PXR_NS::TfToken const&, PXR_NS::UsdSchemaVersion, PXR_NS::UsdSchemaRegistry::VersionPolicy) const) 
            &PXR_NS::UsdPrim::HasAPIInFamily, "HasAPIInFamily_with_version"
        )
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&, PXR_NS::UsdSchemaVersion, PXR_NS::UsdSchemaRegistry::VersionPolicy, PXR_NS::TfToken const&) const) 
            &PXR_NS::UsdPrim::HasAPIInFamily, "HasAPIInFamily_with_version_and_instance"
        )
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfType const&,
        //                              PXR_NS::UsdSchemaRegistry::VersionPolicy)
        //         const) &
        //    PXR_NS::UsdPrim::HasAPIInFamily)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfType const&,
        //                              PXR_NS::UsdSchemaRegistry::VersionPolicy,
        //                              PXR_NS::TfToken const&) const) &
        //    PXR_NS::UsdPrim::HasAPIInFamily)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&,
        //                              PXR_NS::UsdSchemaRegistry::VersionPolicy)
        //         const) &
        //    PXR_NS::UsdPrim::HasAPIInFamily)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&,
        //                              PXR_NS::UsdSchemaRegistry::VersionPolicy,
        //                              PXR_NS::TfToken const&) const) &
        //    PXR_NS::UsdPrim::HasAPIInFamily)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&,
        //                              PXR_NS::UsdSchemaVersion*) const) &
        //    PXR_NS::UsdPrim::GetVersionIfHasAPIInFamily)
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&, PXR_NS::TfToken const&, PXR_NS::UsdSchemaVersion*) const) 
            &PXR_NS::UsdPrim::GetVersionIfHasAPIInFamily
        )

        // CanApplyAPI
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfType const&, std::string*) const) 
            &PXR_NS::UsdPrim::CanApplyAPI
        ) 
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfType const&,
        //                              PXR_NS::TfToken const&, std::string*)
        //         const) &
        //    PXR_NS::UsdPrim::CanApplyAPI)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&, std::string*)
        //         const) &
        //    PXR_NS::UsdPrim::CanApplyAPI)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&,
        //                              PXR_NS::TfToken const&, std::string*)
        //         const) &
        //    PXR_NS::UsdPrim::CanApplyAPI)
        // .m((bool(PXR_NS::UsdPrim::*)(
        //        PXR_NS::TfToken const&, PXR_NS::UsdSchemaVersion,
        //        PXR_NS::TfToken const&, std::string*) const) &
        //    PXR_NS::UsdPrim::CanApplyAPI)

        // ApplyAPI
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfType const&) const) 
            &PXR_NS::UsdPrim::ApplyAPI
        )
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfType const&,
        //                              PXR_NS::TfToken const&) const) &
        //    PXR_NS::UsdPrim::ApplyAPI)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&) const) &
        //    PXR_NS::UsdPrim::ApplyAPI)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&,
        //                              PXR_NS::TfToken const&) const) &
        //    PXR_NS::UsdPrim::ApplyAPI)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&,
        //                              PXR_NS::UsdSchemaVersion) const) &
        //    PXR_NS::UsdPrim::ApplyAPI)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&,
        //                              PXR_NS::UsdSchemaVersion,
        //                              PXR_NS::TfToken const&) const) &
        //    PXR_NS::UsdPrim::ApplyAPI)

        // RemoveAPI
        .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfType const&) const) 
            &PXR_NS::UsdPrim::RemoveAPI
        )
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfType const&,
        //                              PXR_NS::TfToken const&) const) &
        //    PXR_NS::UsdPrim::RemoveAPI)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&) const) &
        //    PXR_NS::UsdPrim::RemoveAPI)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&,
        //                              PXR_NS::TfToken const&) const) &
        //    PXR_NS::UsdPrim::RemoveAPI)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&,
        //                              PXR_NS::UsdSchemaVersion) const) &
        //    PXR_NS::UsdPrim::RemoveAPI)
        // .m((bool(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&,
        //                              PXR_NS::UsdSchemaVersion,
        //                              PXR_NS::TfToken const&) const) &
        //    PXR_NS::UsdPrim::RemoveAPI)

        // PXR_NS::UsdPrim Children
        .m(&PXR_NS::UsdPrim::GetChild)
        .m(&PXR_NS::UsdPrim::GetChildren)
        .m(&PXR_NS::UsdPrim::GetAllChildren)
        .m(&PXR_NS::UsdPrim::GetFilteredChildren)
        .m(&PXR_NS::UsdPrim::GetChildrenNames)
        .m(&PXR_NS::UsdPrim::GetFilteredChildrenNames)
        .m(&PXR_NS::UsdPrim::GetDescendants)
        .m(&PXR_NS::UsdPrim::GetAllDescendants)
        .m(&PXR_NS::UsdPrim::GetFilteredDescendants)
        .m(&PXR_NS::UsdPrim::GetChildrenReorder)
        .m(&PXR_NS::UsdPrim::SetChildrenReorder)
        .m(&PXR_NS::UsdPrim::ClearChildrenReorder)

        // Parent & Stage
        .m(&PXR_NS::UsdPrim::GetParent)
        .m(&PXR_NS::UsdPrim::GetNextSibling)
        .m(&PXR_NS::UsdPrim::GetFilteredNextSibling)
        .m(&PXR_NS::UsdPrim::IsPseudoRoot)
        .m(&PXR_NS::UsdPrim::GetPrimAtPath)
        .m(&PXR_NS::UsdPrim::GetObjectAtPath)
        .m(&PXR_NS::UsdPrim::GetPropertyAtPath)
        .m(&PXR_NS::UsdPrim::GetAttributeAtPath)
        .m(&PXR_NS::UsdPrim::GetRelationshipAtPath)

        // Variants
        .m(&PXR_NS::UsdPrim::GetVariantSets)
        .m(&PXR_NS::UsdPrim::GetVariantSet)
        .m(&PXR_NS::UsdPrim::HasVariantSets)

        // Attributes
        // We'll only do one of these create methods as the rest are for
        // convenience, and we should do convenience on the FFI side
        .m((PXR_NS::UsdAttribute(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&, PXR_NS::SdfValueTypeName const&, bool, PXR_NS::SdfVariability) const) 
            &PXR_NS::UsdPrim::CreateAttribute
        )
        .m(&PXR_NS::UsdPrim::GetAttributes)
        .m(&PXR_NS::UsdPrim::GetAuthoredAttributes)
        .m(&PXR_NS::UsdPrim::GetAttribute)
        .m(&PXR_NS::UsdPrim::HasAttribute)
        .m(&PXR_NS::UsdPrim::FindAllAttributeConnectionPaths)

        // Relationships
        .m((PXR_NS::UsdRelationship(PXR_NS::UsdPrim::*)(PXR_NS::TfToken const&, bool) const) 
            &PXR_NS::UsdPrim::CreateRelationship
        )
        .m(&PXR_NS::UsdPrim::GetRelationships)
        .m(&PXR_NS::UsdPrim::GetAuthoredRelationships)
        .m(&PXR_NS::UsdPrim::GetRelationship)
        .m(&PXR_NS::UsdPrim::HasRelationship)
        .m(&PXR_NS::UsdPrim::FindAllRelationshipTargetPaths)

        // Payloads, load and unload
        .m(&PXR_NS::UsdPrim::GetPayloads)
        .m(&PXR_NS::UsdPrim::HasAuthoredPayloads)
        .m(&PXR_NS::UsdPrim::Load)
        .m(&PXR_NS::UsdPrim::Unload)

        // References
        .m(&PXR_NS::UsdPrim::GetReferences)
        .m(&PXR_NS::UsdPrim::HasAuthoredReferences)

        // Inherits
        .m(&PXR_NS::UsdPrim::GetInherits)
        .m(&PXR_NS::UsdPrim::HasAuthoredInherits)

        // Specializes
        .m(&PXR_NS::UsdPrim::GetSpecializes)
        .m(&PXR_NS::UsdPrim::HasAuthoredSpecializes)

        // Instances
        .m(&PXR_NS::UsdPrim::IsInstanceable)
        .m(&PXR_NS::UsdPrim::SetInstanceable)
        .m(&PXR_NS::UsdPrim::ClearInstanceable)
        .m(&PXR_NS::UsdPrim::HasAuthoredInstanceable)
        .m(&PXR_NS::UsdPrim::IsInstance)
        .m(&PXR_NS::UsdPrim::IsInstanceProxy)
        .m(&PXR_NS::UsdPrim::IsPrototypePath)
        .m(&PXR_NS::UsdPrim::IsPathInPrototype)
        .m(&PXR_NS::UsdPrim::IsPrototype)
        .m(&PXR_NS::UsdPrim::IsInPrototype)
        .m(&PXR_NS::UsdPrim::GetPrototype)
        .m(&PXR_NS::UsdPrim::GetPrimInPrototype)
        .m(&PXR_NS::UsdPrim::GetInstances)

        // Composition
        .m(&PXR_NS::UsdPrim::GetPrimIndex)
        .m(&PXR_NS::UsdPrim::ComputeExpandedPrimIndex)
        .m(&PXR_NS::UsdPrim::MakeResolveTargetUpToEditTarget)
        .m(&PXR_NS::UsdPrim::MakeResolveTargetStrongerThanEditTarget)
        ;

    bbl::Class<PXR_NS::UsdPrimTypeInfo>("PrimTypeInfo")
        .m(&PXR_NS::UsdPrimTypeInfo::GetTypeName)
        .m(&PXR_NS::UsdPrimTypeInfo::GetAppliedAPISchemas)
        .m(&PXR_NS::UsdPrimTypeInfo::GetSchemaType)
        .m(&PXR_NS::UsdPrimTypeInfo::GetSchemaTypeName)
        .m(&PXR_NS::UsdPrimTypeInfo::GetPrimDefinition)
        .m(&PXR_NS::UsdPrimTypeInfo::GetEmptyPrimType)
    ;

    bbl::Class<std::vector<PXR_NS::UsdPrim>>("PrimVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdPrim);
    bbl::Class<PXR_NS::Usd_PrimFlagsPredicate>("PrimFlagsPredicate");

    // Manually generate overrides that don't take a stdfunction for convenience
    bbl::fn(&bblext::UsdPrim_GetProperties, "Prim_GetProperties");
    bbl::fn(&bblext::UsdPrim_GetAuthoredProperties, "Prim_GetAuthoredProperties");

    bbl::Class<PXR_NS::UsdProperty>("Property")
        .ctor(bbl::Class<PXR_NS::UsdProperty>::Ctor<>(), "default")
        .m(&PXR_NS::UsdProperty::GetPropertyStack)                                                 
        .m(&PXR_NS::UsdProperty::GetPropertyStackWithLayerOffsets)                             
        .m(&PXR_NS::UsdProperty::GetBaseName)                                                  
        .m(&PXR_NS::UsdProperty::GetNamespace)                                                 
        .m(&PXR_NS::UsdProperty::SplitName)                                                    
        .m(&PXR_NS::UsdProperty::GetDisplayGroup)                                              
        .m(&PXR_NS::UsdProperty::SetDisplayGroup)                                              
        .m(&PXR_NS::UsdProperty::ClearDisplayGroup)                                            
        .m(&PXR_NS::UsdProperty::HasAuthoredDisplayGroup)                                      
        .m(&PXR_NS::UsdProperty::GetNestedDisplayGroups)                                       
        .m(&PXR_NS::UsdProperty::SetNestedDisplayGroups)                                       
        .m(&PXR_NS::UsdProperty::IsCustom)                                                     
        .m(&PXR_NS::UsdProperty::SetCustom)                                                    
        .m(&PXR_NS::UsdProperty::IsDefined)                                                    
        .m(&PXR_NS::UsdProperty::IsAuthored)                                                   
        .m(&PXR_NS::UsdProperty::IsAuthoredAt)                                                 
        .m((PXR_NS::UsdProperty (PXR_NS::UsdProperty::*)(PXR_NS::UsdPrim const&) const) 
            &PXR_NS::UsdProperty::FlattenTo, "FlattenTo_prim"
        )                                                   
        .m((PXR_NS::UsdProperty(PXR_NS::UsdProperty::*)(PXR_NS::UsdPrim const&, PXR_NS::TfToken const&) const)
            & PXR_NS::UsdProperty::FlattenTo, "FlattenTo_named_property"
        )  
        .m((PXR_NS::UsdProperty(PXR_NS::UsdProperty::*)(PXR_NS::UsdProperty const&) const) 
            &PXR_NS::UsdProperty::FlattenTo, "FlattenTo_property"
        )
    ;

    bbl::Class<PXR_NS::UsdPrim::PropertyPredicateFunc>("PropertyPredicateFunc");

    bbl::Class<std::vector<PXR_NS::UsdProperty>>("PropertyVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdProperty)
    ;

    bbl::Class<PXR_NS::UsdRelationship>("Relationship")
        .ctor(bbl::Class<PXR_NS::UsdRelationship>::Ctor<>(), "default")
        .m(&PXR_NS::UsdRelationship::AddTarget)
        .m(&PXR_NS::UsdRelationship::RemoveTarget)
        .m(&PXR_NS::UsdRelationship::SetTargets)
        .m(&PXR_NS::UsdRelationship::ClearTargets)
        .m(&PXR_NS::UsdRelationship::GetTargets)
        .m(&PXR_NS::UsdRelationship::GetForwardedTargets)
        .m(&PXR_NS::UsdRelationship::HasAuthoredTargets)
        ;
    ;

    bbl::Class<std::vector<PXR_NS::UsdRelationship>>("RelationshipVector")
        BBL_STD_VECTOR_METHODS(PXR_NS::UsdRelationship)
    ;

    bbl::Class<std::function<bool(PXR_NS::UsdAttribute const&)>>("FindAttributePredicate");
    bbl::Class<std::function<bool(PXR_NS::UsdRelationship const&)>>("FindRelationshipPredicate");


}

#endif

