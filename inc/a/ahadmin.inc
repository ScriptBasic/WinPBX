' ########################################################################################
' Microsoft Windows
' File: ahadmin.inc
' Library name: AppHostAdminLibrary
' Version: 1.0, Locale ID = 0
' Contents: Application Host Administration Interface
' Library GUID: {598F9C7D-D2D7-4980-B234-F1E753CD9FD9}
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AHADMIN_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "oaidl.inc"

$LIBID_AppHostAdminLibrary = GUID$("{598F9C7D-D2D7-4980-B234-F1E753CD9FD9}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_AppHostAdminManager = GUID$("{228FB8F7-FB53-4FD5-8C7B-FF59DE606C5B}")
$CLSID_AppHostWritableAdminManager = GUID$("{2B72133B-3F5B-4602-8952-803546CE3344}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IAppHostAdminManager = GUID$("{9BE77978-73ED-4A9A-87FD-13F09FEC1B13}")
$IID_IAppHostChangeHandler = GUID$("{09829352-87C2-418D-8D79-4133969A489D}")
$IID_IAppHostChildElementCollection = GUID$("{08A90F5F-0702-48D6-B45F-02A9885A9768}")
$IID_IAppHostCollectionSchema = GUID$("{DE095DB1-5368-4D11-81F6-EFEF619B7BCF}")
$IID_IAppHostConfigException = GUID$("{4DFA1DF3-8900-4BC7-BBB5-D1A458C52410}")
$IID_IAppHostConfigFile = GUID$("{ADA4E6FB-E025-401E-A5D0-C3134A281F07}")
$IID_IAppHostConfigLocation = GUID$("{370AF178-7758-4DAD-8146-7391F6E18585}")
$IID_IAppHostConfigLocationCollection = GUID$("{832A32F7-B3EA-4B8C-B260-9A2923001184}")
$IID_IAppHostConfigManager = GUID$("{8F6D760F-F0CB-4D69-B5F6-848B33E9BDC6}")
$IID_IAppHostConstantValue = GUID$("{0716CAF8-7D05-4A46-8099-77594BE91394}")
$IID_IAppHostConstantValueCollection = GUID$("{5B5A68E6-8B9F-45E1-8199-A95FFCCDFFFF}")
$IID_IAppHostElement = GUID$("{64FF8CCC-B287-4DAE-B08A-A72CBF45F453}")
$IID_IAppHostElementCollection = GUID$("{C8550BFF-5281-4B1E-AC34-99B6FA38464D}")
$IID_IAppHostElementExtension = GUID$("{518EB37D-1FF4-42DD-86C3-3140BC35B823}")
$IID_IAppHostElementSchema = GUID$("{EF13D885-642C-4709-99EC-B89561C6BC69}")
$IID_IAppHostElementSchemaCollection = GUID$("{0344CDDA-151E-4CBF-82DA-66AE61E97754}")
$IID_IAppHostMappingExtension = GUID$("{31A83EA0-C0E4-4A2C-8A01-353CC2A4C60A}")
$IID_IAppHostMethod = GUID$("{7883CA1C-1112-4447-84C3-52FBEB38069D}")
$IID_IAppHostMethodCollection = GUID$("{D6C7CD8F-BB8D-4F96-B591-D3A5F1320269}")
$IID_IAppHostMethodExtension = GUID$("{70184AC9-7673-4770-96B1-445CE035CF70}")
$IID_IAppHostMethodInstance = GUID$("{B80F3C42-60E0-4AE0-9007-F52852D3DBED}")
$IID_IAppHostMethodSchema = GUID$("{2D9915FB-9D42-4328-B782-1B46819FAB9E}")
$IID_IAppHostPathMapper = GUID$("{E7927575-5CC3-403B-822E-328A6B904BEE}")
$IID_IAppHostPathMapper2 = GUID$("{0F80E901-8F4C-449A-BF90-13D5D082F187}")
$IID_IAppHostProperty = GUID$("{ED35F7A1-5024-4E7B-A44D-07DDAF4B524D}")
$IID_IAppHostPropertyCollection = GUID$("{0191775E-BCFF-445A-B4F4-3BDDA54E2816}")
$IID_IAppHostPropertyException = GUID$("{EAFE4895-A929-41EA-B14D-613E23F62B71}")
$IID_IAppHostPropertyExtension = GUID$("{88E220F3-33E8-4534-AFAC-B4A98ECCF9AE}")
$IID_IAppHostPropertySchema = GUID$("{450386DB-7409-4667-935E-384DBBEE2A9E}")
$IID_IAppHostPropertySchemaCollection = GUID$("{8BED2C68-A5FB-4B28-8581-A0DC5267419F}")
$IID_IAppHostSectionDefinition = GUID$("{C5C04795-321C-4014-8FD6-D44658799393}")
$IID_IAppHostSectionDefinitionCollection = GUID$("{B7D381EE-8860-47A1-8AF4-1F33B2B1F325}")
$IID_IAppHostSectionGroup = GUID$("{0DD8A158-EBE6-4008-A1D9-B7ECC8F1104B}")
$IID_IAppHostWritableAdminManager = GUID$("{FA7660F6-7B3F-4237-A8BF-ED0AD0DCBBD9}")

' ########################################################################################
' Interface name = IAppHostAdminManager
' IID = {9BE77978-73ED-4A9A-87FD-13F09FEC1B13}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostAdminManager_INTERFACE_DEFINED)
    %IAppHostAdminManager_INTERFACE_DEFINED = 1

INTERFACE IAppHostAdminManager $IID_IAppHostAdminManager

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetAdminSection ( _                           ' VTable offset = 12
     BYVAL bstrSectionName AS WSTRING _                 ' __in BSTR bstrSectionName
   , BYVAL bstrPath AS WSTRING _                        ' __in BSTR bstrPath
   ) AS IAppHostElement                                 ' __retval_out IAppHostElement **ppAdminSection
   ' =====================================================================================
   METHOD GetMetadata ( _                               ' VTable offset = 16
     BYVAL bstrMetadataType AS WSTRING _                ' __in BSTR bstrMetadataType
   ) AS VARIANT                                         ' __retval_out VARIANT *pValue
   ' =====================================================================================
   METHOD SetMetadata ( _                               ' VTable offset = 20
     BYVAL bstrMetadataType AS WSTRING _                ' __in BSTR bstrMetadataType
   , BYVAL Value AS VARIANT _                           ' __in VARIANT Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ConfigManager ( _                       ' VTable offset = 24
   ) AS IAppHostConfigManager                           ' __retval_out IAppHostConfigManager **ppConfigManager
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostAdminManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostElement
' IID = {64FF8CCC-B287-4DAE-B08A-A72CBF45F453}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostElement_INTERFACE_DEFINED)
    %IAppHostElement_INTERFACE_DEFINED = 1

INTERFACE IAppHostElement $IID_IAppHostElement

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET Collection ( _                          ' VTable offset = 16
   ) AS IAppHostElementCollection                       ' __retval_out IAppHostElementCollection **ppCollection
   ' =====================================================================================
   PROPERTY GET Properties ( _                          ' VTable offset = 20
   ) AS IAppHostPropertyCollection                      ' __retval_out IAppHostPropertyCollection **ppProperties
   ' =====================================================================================
   PROPERTY GET ChildElements ( _                       ' VTable offset = 24
   ) AS IAppHostChildElementCollection                  ' __retval_out IAppHostChildElementCollection **ppElements
   ' =====================================================================================
   METHOD GetMetadata ( _                               ' VTable offset = 28
     BYVAL bstrMetadataType AS WSTRING _                ' __in BSTR bstrMetadataType VT_BSTR
   ) AS VARIANT                                         ' __retval_out VARIANT *pValue
   ' =====================================================================================
   METHOD SetMetadata ( _                               ' VTable offset = 32
     BYVAL bstrMetadataType AS WSTRING _                ' __in BSTR bstrMetadataType
   , BYVAL Value AS VARIANT _                           ' __in VARIANT Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Schema ( _                              ' VTable offset = 36
   ) AS IAppHostElementSchema                           ' __retval_out IAppHostElementSchema **ppSchema
   ' =====================================================================================
   METHOD GetElementByName ( _                          ' VTable offset = 40
     BYVAL bstrSubName AS WSTRING _                     ' __in BSTR bstrSubName
   ) AS IAppHostElement                                 ' __retval_out IAppHostElement **ppElement
   ' =====================================================================================
   METHOD GetPropertyByName ( _                         ' VTable offset = 44
     BYVAL bstrSubName AS WSTRING _                     ' __in BSTR bstrSubName
   ) AS IAppHostProperty                                ' __retval_out IAppHostProperty **ppProperty
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Methods ( _                             ' VTable offset = 52
   ) AS IAppHostMethodCollection                        ' __retval_out IAppHostMethodCollection **ppMethods
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostElement_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostElementCollection
' IID = {C8550BFF-5281-4B1E-AC34-99B6FA38464D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostElementCollection_INTERFACE_DEFINED)
    %IAppHostElementCollection_INTERFACE_DEFINED = 1

INTERFACE IAppHostElementCollection $IID_IAppHostElementCollection

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Count ( _                               ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out DWORD *pcElementCount
   ' =====================================================================================
   PROPERTY GET Item ( _                                ' VTable offset = 16
     BYVAL cIndex AS VARIANT _                          ' __in VARIANT cIndex
   ) AS IAppHostElement                                 ' __retval_out IAppHostElement **ppElement
   ' =====================================================================================
   METHOD AddElement ( _                                ' VTable offset = 20
     BYVAL pElement AS IAppHostElement _                ' __in IAppHostElement *pElement
   , OPTIONAL BYVAL cPosition AS LONG _                 ' __in_opt INT cPosition = -1
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteElement ( _                             ' VTable offset = 24
     BYVAL cIndex AS VARIANT _                          ' __in VARIANT cIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateNewElement ( _                          ' VTable offset = 32
     OPTIONAL BYVAL bstrElementName AS WSTRING _        ' __in_opt BSTR bstrElementName = ""
   ) AS IAppHostElement                                 ' __retval_out IAppHostElement **ppElement
   ' =====================================================================================
   PROPERTY GET Schema ( _                              ' VTable offset = 36
   ) AS IAppHostCollectionSchema                        ' __retval_out IAppHostCollectionSchema **ppSchema
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostElementCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostCollectionSchema
' IID = {DE095DB1-5368-4D11-81F6-EFEF619B7BCF}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostCollectionSchema_INTERFACE_DEFINED)
    %IAppHostCollectionSchema_INTERFACE_DEFINED = 1

INTERFACE IAppHostCollectionSchema $IID_IAppHostCollectionSchema

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET AddElementNames ( _                     ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrElementName
   ' =====================================================================================
   METHOD GetAddElementSchema ( _                       ' VTable offset = 16
     BYVAL bstrElementName AS WSTRING _                 ' __in BSTR bstrElementName
   ) AS IAppHostElementSchema                           ' __retval_out IAppHostElementSchema **ppSchema
   ' =====================================================================================
   PROPERTY GET RemoveElementSchema ( _                 ' VTable offset = 20
   ) AS IAppHostElementSchema                           ' __retval_out IAppHostElementSchema **ppSchema
   ' =====================================================================================
   PROPERTY GET ClearElementSchema ( _                  ' VTable offset = 24
   ) AS IAppHostElementSchema                           ' __retval_out IAppHostElementSchema **ppSchema
   ' =====================================================================================
   PROPERTY GET IsMergeAppend ( _                       ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfIsMergeAppend
   ' =====================================================================================
   METHOD GetMetadata ( _                               ' VTable offset = 32
     BYVAL bstrMetadataType AS WSTRING _                ' __in BSTR bstrMetadataType
   ) AS VARIANT                                         ' __retval_out VARIANT *pValue
   ' =====================================================================================
   PROPERTY GET DoesAllowDuplicates ( _                 ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfAllowDuplicates
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostCollectionSchema_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostElementSchema
' IID = {EF13D885-642C-4709-99EC-B89561C6BC69}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostElementSchema_INTERFACE_DEFINED)
    %IAppHostElementSchema_INTERFACE_DEFINED = 1

INTERFACE IAppHostElementSchema $IID_IAppHostElementSchema

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET DoesAllowUnschematizedProperties ( _    ' VTable offset = 16
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfAllowUnschematized
   ' =====================================================================================
   METHOD GetMetadata ( _                               ' VTable offset = 20
     BYVAL bstrMetadataType AS WSTRING _                ' __in BSTR bstrMetadataType
   ) AS VARIANT                                         ' __retval_out VARIANT *pValue
   ' =====================================================================================
   PROPERTY GET CollectionSchema ( _                    ' VTable offset = 24
   ) AS IAppHostCollectionSchema                        ' __retval_out IAppHostCollectionSchema **ppCollectionSchema
   ' =====================================================================================
   PROPERTY GET ChildElementSchemas ( _                 ' VTable offset = 28
   ) AS IAppHostElementSchemaCollection                 ' __retval_out IAppHostElementSchemaCollection **ppChildSchemas
   ' =====================================================================================
   PROPERTY GET PropertySchemas ( _                     ' VTable offset = 32
   ) AS IAppHostPropertySchemaCollection                ' __retval_out IAppHostPropertySchemaCollection **ppPropertySchemas
   ' =====================================================================================
   PROPERTY GET IsCollectionDefault ( _                 ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfIsCollectionDefault
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostElementSchema_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostElementSchemaCollection
' IID = {0344CDDA-151E-4CBF-82DA-66AE61E97754}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostElementSchemaCollection_INTERFACE_DEFINED)
    %IAppHostElementSchemaCollection_INTERFACE_DEFINED = 1

INTERFACE IAppHostElementSchemaCollection $IID_IAppHostElementSchemaCollection

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Count ( _                               ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out DWORD *pcCount
   ' =====================================================================================
   PROPERTY GET Item ( _                                ' VTable offset = 16
     BYVAL cIndex AS VARIANT _                          ' __in VARIANT cIndex VT_VARIANT
   ) AS IAppHostElementSchema                           ' __retval_out IAppHostElementSchema **ppElementSchema
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostElementSchemaCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostPropertySchemaCollection
' IID = {8BED2C68-A5FB-4B28-8581-A0DC5267419F}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostPropertySchemaCollection_INTERFACE_DEFINED)
    %IAppHostPropertySchemaCollection_INTERFACE_DEFINED = 1

INTERFACE IAppHostPropertySchemaCollection $IID_IAppHostPropertySchemaCollection

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Count ( _                               ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out DWORD *pcCount
   ' =====================================================================================
   PROPERTY GET Item ( _                                ' VTable offset = 16
     BYVAL cIndex AS VARIANT _                          ' __in VARIANT cIndex
   ) AS IAppHostPropertySchema                          ' __retval_out IAppHostPropertySchema **ppPropertySchema
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostPropertySchemaCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostPropertySchema
' IID = {450386DB-7409-4667-935E-384DBBEE2A9E}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostPropertySchema_INTERFACE_DEFINED)
    %IAppHostPropertySchema_INTERFACE_DEFINED = 1

INTERFACE IAppHostPropertySchema $IID_IAppHostPropertySchema

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET Type ( _                                ' VTable offset = 16
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrType
   ' =====================================================================================
   PROPERTY GET DefaultValue ( _                        ' VTable offset = 20
   ) AS VARIANT                                         ' __retval_out VARIANT *pDefaultValue
   ' =====================================================================================
   PROPERTY GET IsRequired ( _                          ' VTable offset = 24
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfIsRequired
   ' =====================================================================================
   PROPERTY GET IsUniqueKey ( _                         ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfIsUniqueKey
   ' =====================================================================================
   PROPERTY GET IsCombinedKey ( _                       ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfIsCombinedKey
   ' =====================================================================================
   PROPERTY GET IsExpanded ( _                          ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfIsExpanded
   ' =====================================================================================
   PROPERTY GET ValidationType ( _                      ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrValidationType
   ' =====================================================================================
   PROPERTY GET ValidationParameter ( _                 ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrValidationParameter
   ' =====================================================================================
   METHOD GetMetadata ( _                               ' VTable offset = 48
     BYVAL bstrMetadataType AS WSTRING _                ' __in BSTR bstrMetadataType
   ) AS VARIANT                                         ' __retval_out VARIANT *pValue
   ' =====================================================================================
   PROPERTY GET IsCaseSensitive ( _                     ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfIsCaseSensitive
   ' =====================================================================================
   PROPERTY GET PossibleValues ( _                      ' VTable offset = 56
   ) AS IAppHostConstantValueCollection                 ' __retval_out IAppHostConstantValueCollection **ppValues
   ' =====================================================================================
   PROPERTY GET DoesAllowInfinite ( _                   ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfAllowInfinite
   ' =====================================================================================
   PROPERTY GET IsEncrypted ( _                         ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfIsEncrypted
   ' =====================================================================================
   PROPERTY GET TimeSpanFormat ( _                      ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTimeSpanFormat
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostPropertySchema_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostConstantValueCollection
' IID = {5B5A68E6-8B9F-45E1-8199-A95FFCCDFFFF}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostConstantValueCollection_INTERFACE_DEFINED)
    %IAppHostConstantValueCollection_INTERFACE_DEFINED = 1

INTERFACE IAppHostConstantValueCollection $IID_IAppHostConstantValueCollection

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Count ( _                               ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out DWORD *pcCount
   ' =====================================================================================
   PROPERTY GET Item ( _                                ' VTable offset = 16
     BYVAL cIndex AS VARIANT _                          ' __in VARIANT cIndex
   ) AS IAppHostConstantValue                           ' __retval_out IAppHostConstantValue **ppConstantValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostConstantValueCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostConstantValue
' IID = {0716CAF8-7D05-4A46-8099-77594BE91394}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostConstantValue_INTERFACE_DEFINED)
    %IAppHostConstantValue_INTERFACE_DEFINED = 1

INTERFACE IAppHostConstantValue $IID_IAppHostConstantValue

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET Value ( _                               ' VTable offset = 16
   ) AS DWORD                                           ' __retval_out DWORD *pdwValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostConstantValue_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostPropertyCollection
' IID = {0191775E-BCFF-445A-B4F4-3BDDA54E2816}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostPropertyCollection_INTERFACE_DEFINED)
    %IAppHostPropertyCollection_INTERFACE_DEFINED = 1

INTERFACE IAppHostPropertyCollection $IID_IAppHostPropertyCollection

   INHERIT IUnknown

   ' =====================================================================================
   PROPERTY GET Count ( _                               ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out DWORD *pcCount
   ' =====================================================================================
   PROPERTY GET Item ( _                                ' VTable offset = 16
     BYVAL cIndex AS VARIANT _                          ' __in VARIANT cIndex
   ) AS IAppHostProperty                                ' __retval_out IAppHostProperty **ppProperty
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostPropertyCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostProperty
' IID = {ED35F7A1-5024-4E7B-A44D-07DDAF4B524D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostProperty_INTERFACE_DEFINED)
    %IAppHostProperty_INTERFACE_DEFINED = 1

INTERFACE IAppHostProperty $IID_IAppHostProperty

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET Value ( _                               ' VTable offset = 16
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   PROPERTY SET Value ( _                               ' VTable offset = 20
     BYVAL pVariant AS VARIANT _                        ' __in VARIANT pVariant
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 24
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StringValue ( _                         ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrValue
   ' =====================================================================================
   PROPERTY GET Exception ( _                           ' VTable offset = 32
   ) AS IAppHostPropertyException                       ' __retval_out IAppHostPropertyException **ppException
   ' =====================================================================================
   METHOD GetMetadata ( _                               ' VTable offset = 36
     BYVAL bstrMetadataType AS WSTRING _                ' __in BSTR bstrMetadataType
   ) AS VARIANT                                         ' __retval_out VARIANT *pValue
   ' =====================================================================================
   METHOD SetMetadata ( _                               ' VTable offset = 40
     BYVAL bstrMetadataType AS WSTRING _                ' __in BSTR bstrMetadataType
   , BYVAL Value AS VARIANT _                           ' __in VARIANT Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Schema ( _                              ' VTable offset = 44
   ) AS IAppHostPropertySchema                          ' __retval_out IAppHostPropertySchema **ppSchema
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostProperty_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostPropertyException
' IID = {EAFE4895-A929-41EA-B14D-613E23F62B71}
' Inherited interface = IAppHostConfigException
' ########################################################################################

#IF NOT %DEF(%IAppHostPropertyException_INTERFACE_DEFINED)
    %IAppHostPropertyException_INTERFACE_DEFINED = 1

INTERFACE IAppHostPropertyException $IID_IAppHostPropertyException

   INHERIT IAutomation

   ' =====================================================================================
   ' IAppHostConfigException Methods
   ' =====================================================================================
   PROPERTY GET LineNumber ( _                          ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out ULONG *pcLineNumber
   ' =====================================================================================
   PROPERTY GET FileName ( _                            ' VTable offset = 16
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFileName
   ' =====================================================================================
   PROPERTY GET ConfigPath ( _                          ' VTable offset = 20
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrConfigPath
   ' =====================================================================================
   PROPERTY GET ErrorLine ( _                           ' VTable offset = 24
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrErrorLine
   ' =====================================================================================
   PROPERTY GET PreErrorLine ( _                        ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPreErrorLine
   ' =====================================================================================
   PROPERTY GET PostErrorLine ( _                       ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPostErrorLine
   ' =====================================================================================
   PROPERTY GET ErrorString ( _                         ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrErrorString
   ' =====================================================================================

   ' =====================================================================================
   ' IAppHostPropertyException Methods
   ' =====================================================================================
   PROPERTY GET InvalidValue ( _                        ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrValue
   ' =====================================================================================
   PROPERTY GET ValidationFailureReason ( _             ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrValidationReason
   ' =====================================================================================
   PROPERTY GET ValidationFailureParameters ( _         ' VTable offset = 48
   ) AS DWORD                                           ' __retval_out SAFEARRAY **pParameterArray
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostPropertyException_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostConfigException
' IID = {4DFA1DF3-8900-4BC7-BBB5-D1A458C52410}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostConfigException_INTERFACE_DEFINED)
    %IAppHostConfigException_INTERFACE_DEFINED = 1

INTERFACE IAppHostConfigException $IID_IAppHostConfigException

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET LineNumber ( _                          ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out ULONG *pcLineNumber
   ' =====================================================================================
   PROPERTY GET FileName ( _                            ' VTable offset = 16
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFileName
   ' =====================================================================================
   PROPERTY GET ConfigPath ( _                          ' VTable offset = 20
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrConfigPath
   ' =====================================================================================
   PROPERTY GET ErrorLine ( _                           ' VTable offset = 24
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrErrorLine
   ' =====================================================================================
   PROPERTY GET PreErrorLine ( _                        ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPreErrorLine
   ' =====================================================================================
   PROPERTY GET PostErrorLine ( _                       ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPostErrorLine
   ' =====================================================================================
   PROPERTY GET ErrorString ( _                         ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrErrorString
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostConfigException_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostChildElementCollection
' IID = {08A90F5F-0702-48D6-B45F-02A9885A9768}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostChildElementCollection_INTERFACE_DEFINED)
    %IAppHostChildElementCollection_INTERFACE_DEFINED = 1

INTERFACE IAppHostChildElementCollection $IID_IAppHostChildElementCollection

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Count ( _                               ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out DWORD *pcCount
   ' =====================================================================================
   PROPERTY GET Item ( _                                ' VTable offset = 16
     BYVAL cIndex AS VARIANT _                          ' __in VARIANT cIndex
   ) AS IAppHostElement                                 ' __retval_out IAppHostElement **ppElement
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostChildElementCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostMethodCollection
' IID = {D6C7CD8F-BB8D-4F96-B591-D3A5F1320269}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostMethodCollection_INTERFACE_DEFINED)
    %IAppHostMethodCollection_INTERFACE_DEFINED = 1

INTERFACE IAppHostMethodCollection $IID_IAppHostMethodCollection

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Count ( _                               ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out DWORD *pcCount
   ' =====================================================================================
   PROPERTY GET Item ( _                                ' VTable offset = 16
     BYVAL cIndex AS VARIANT _                          ' __in VARIANT cIndex
   ) AS IAppHostMethod                                  ' __retval_out IAppHostMethod **ppMethod
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostMethodCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostMethod
' IID = {7883CA1C-1112-4447-84C3-52FBEB38069D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostMethod_INTERFACE_DEFINED)
    %IAppHostMethod_INTERFACE_DEFINED = 1

INTERFACE IAppHostMethod $IID_IAppHostMethod

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET Schema ( _                              ' VTable offset = 16
   ) AS IAppHostMethodSchema                            ' __retval_out IAppHostMethodSchema **ppMethodSchema
   ' =====================================================================================
   METHOD CreateInstance ( _                            ' VTable offset = 20
   ) AS IAppHostMethodInstance                          ' __retval_out IAppHostMethodInstance **ppMethodInstance
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostMethod_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostMethodSchema
' IID = {2D9915FB-9D42-4328-B782-1B46819FAB9E}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostMethodSchema_INTERFACE_DEFINED)
    %IAppHostMethodSchema_INTERFACE_DEFINED = 1

INTERFACE IAppHostMethodSchema $IID_IAppHostMethodSchema

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET InputSchema ( _                         ' VTable offset = 16
   ) AS IAppHostElementSchema                           ' __retval_out IAppHostElementSchema **ppInputSchema
   ' =====================================================================================
   PROPERTY GET OutputSchema ( _                        ' VTable offset = 20
   ) AS IAppHostElementSchema                           ' __retval_out IAppHostElementSchema **ppOutputSchema
   ' =====================================================================================
   METHOD GetMetadata ( _                               ' VTable offset = 24
     BYVAL bstrMetadataType AS WSTRING _                ' __in BSTR bstrMetadataType
   ) AS VARIANT                                         ' __retval_out VARIANT *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostMethodSchema_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostMethodInstance
' IID = {B80F3C42-60E0-4AE0-9007-F52852D3DBED}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostMethodInstance_INTERFACE_DEFINED)
    %IAppHostMethodInstance_INTERFACE_DEFINED = 1

INTERFACE IAppHostMethodInstance $IID_IAppHostMethodInstance

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Input ( _                               ' VTable offset = 12
   ) AS IAppHostElement                                 ' __retval_out IAppHostElement **ppInputElement
   ' =====================================================================================
   PROPERTY GET Output ( _                              ' VTable offset = 16
   ) AS IAppHostElement                                 ' __retval_out IAppHostElement **ppOutputElement
   ' =====================================================================================
   METHOD Execute ( _                                   ' VTable offset = 20
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMetadata ( _                               ' VTable offset = 24
     BYVAL bstrMetadataType AS WSTRING _                ' __in BSTR bstrMetadataType
   ) AS VARIANT                                         ' __retval_out VARIANT *pValue
   ' =====================================================================================
   METHOD SetMetadata ( _                               ' VTable offset = 28
     BYVAL bstrMetadataType AS WSTRING _                ' __in BSTR bstrMetadataType
   , BYVAL Value AS VARIANT _                           ' __in VARIANT Value
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostMethodInstance_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostConfigManager
' IID = {8F6D760F-F0CB-4D69-B5F6-848B33E9BDC6}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostConfigManager_INTERFACE_DEFINED)
    %IAppHostConfigManager_INTERFACE_DEFINED = 1

INTERFACE IAppHostConfigManager $IID_IAppHostConfigManager

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetConfigFile ( _                             ' VTable offset = 12
     BYVAL bstrConfigPath AS WSTRING _                  ' __in BSTR bstrConfigPath
   ) AS IAppHostConfigFile                              ' __retval_out IAppHostConfigFile **ppConfigFile
   ' =====================================================================================
   METHOD GetUniqueConfigPath ( _                       ' VTable offset = 16
     BYVAL bstrConfigPath AS WSTRING _                  ' __in BSTR bstrConfigPath
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUniquePath
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostConfigManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostConfigFile
' IID = {ADA4E6FB-E025-401E-A5D0-C3134A281F07}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostConfigFile_INTERFACE_DEFINED)
    %IAppHostConfigFile_INTERFACE_DEFINED = 1

INTERFACE IAppHostConfigFile $IID_IAppHostConfigFile

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET ConfigPath ( _                          ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrConfigPath
   ' =====================================================================================
   PROPERTY GET FilePath ( _                            ' VTable offset = 16
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFilePath
   ' =====================================================================================
   PROPERTY GET Locations ( _                           ' VTable offset = 20
   ) AS IAppHostConfigLocationCollection                ' __retval_out IAppHostConfigLocationCollection **ppLocations
   ' =====================================================================================
   METHOD GetAdminSection ( _                           ' VTable offset = 24
     BYVAL bstrSectionName AS WSTRING _                 ' __in BSTR bstrSectionName
   , BYVAL bstrPath AS WSTRING _                        ' __in BSTR bstrPath
   ) AS IAppHostElement                                 ' __retval_out IAppHostElement **ppAdminSection
   ' =====================================================================================
   METHOD GetMetadata ( _                               ' VTable offset = 28
     BYVAL bstrMetadataType AS WSTRING _                ' __in BSTR bstrMetadataType
   ) AS VARIANT                                         ' __retval_out VARIANT *pValue
   ' =====================================================================================
   METHOD SetMetadata ( _                               ' VTable offset = 32
     BYVAL bstrMetadataType AS WSTRING _                ' __in BSTR bstrMetadataType
   , BYVAL Value AS VARIANT _                           ' __in VARIANT Value VT_VARIANT
   )                                                    ' void
   ' =====================================================================================
   METHOD ClearInvalidSections ( _                      ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RootSectionGroup ( _                    ' VTable offset = 40
   ) AS IAppHostSectionGroup                            ' __retval_out IAppHostSectionGroup **ppSectionGroups
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostConfigFile_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostConfigLocationCollection
' IID = {832A32F7-B3EA-4B8C-B260-9A2923001184}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostConfigLocationCollection_INTERFACE_DEFINED)
    %IAppHostConfigLocationCollection_INTERFACE_DEFINED = 1

INTERFACE IAppHostConfigLocationCollection $IID_IAppHostConfigLocationCollection

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Count ( _                               ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out DWORD *pcCount
   ' =====================================================================================
   PROPERTY GET Item ( _                                ' VTable offset = 16
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS IAppHostConfigLocation                          ' __retval_out IAppHostConfigLocation **ppLocation
   ' =====================================================================================
   METHOD AddLocation ( _                               ' VTable offset = 20
     BYVAL bstrLocationPath AS WSTRING _                ' __in BSTR bstrLocationPath
   ) AS IAppHostConfigLocation                          ' __retval_out IAppHostConfigLocation **ppNewLocation
   ' =====================================================================================
   METHOD DeleteLocation ( _                            ' VTable offset = 24
     BYVAL cIndex AS VARIANT _                          ' __in VARIANT cIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD RenameLocation ( _                            ' VTable offset = 28
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   , BYVAL bstrLocationPath AS WSTRING _                ' __in BSTR bstrLocationPath
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostConfigLocationCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostConfigLocation
' IID = {370AF178-7758-4DAD-8146-7391F6E18585}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostConfigLocation_INTERFACE_DEFINED)
    %IAppHostConfigLocation_INTERFACE_DEFINED = 1

INTERFACE IAppHostConfigLocation $IID_IAppHostConfigLocation

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Path ( _                                ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrLocationPath
   ' =====================================================================================
   PROPERTY GET Count ( _                               ' VTable offset = 16
   ) AS DWORD                                           ' __retval_out DWORD *pcCount
   ' =====================================================================================
   PROPERTY GET Item ( _                                ' VTable offset = 20
     BYVAL cIndex AS VARIANT _                          ' __in VARIANT cIndex
   ) AS IAppHostElement                                 ' __retval_out IAppHostElement **ppSection  <interface>
   ' =====================================================================================
   METHOD AddConfigSection ( _                          ' VTable offset = 24
     BYVAL bstrSectionName AS WSTRING _                 ' __in BSTR bstrSectionName
   ) AS IAppHostElement                                 ' __retval_out IAppHostElement **ppAdminElement
   ' =====================================================================================
   METHOD DeleteConfigSection ( _                       ' VTable offset = 28
     BYVAL cIndex AS VARIANT _                          ' __in VARIANT cIndex
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostConfigLocation_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostSectionGroup
' IID = {0DD8A158-EBE6-4008-A1D9-B7ECC8F1104B}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostSectionGroup_INTERFACE_DEFINED)
    %IAppHostSectionGroup_INTERFACE_DEFINED = 1

INTERFACE IAppHostSectionGroup $IID_IAppHostSectionGroup

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Count ( _                               ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out ULONG *pcSectionGroup
   ' =====================================================================================
   PROPERTY GET Item ( _                                ' VTable offset = 16
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS IAppHostSectionGroup                            ' __retval_out IAppHostSectionGroup **ppSectionGroup
   ' =====================================================================================
   PROPERTY GET Sections ( _                            ' VTable offset = 20
   ) AS IAppHostSectionDefinitionCollection             ' __retval_out IAppHostSectionDefinitionCollection **ppSections
   ' =====================================================================================
   METHOD AddSectionGroup ( _                           ' VTable offset = 24
     BYVAL bstrSectionGroupName AS WSTRING _            ' __in BSTR bstrSectionGroupName
   ) AS IAppHostSectionGroup                            ' __retval_out IAppHostSectionGroup **ppSectionGroup
   ' =====================================================================================
   METHOD DeleteSectionGroup ( _                        ' VTable offset = 28
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET Type ( _                                ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrType
   ' =====================================================================================
   PROPERTY SET Type ( _                                ' VTable offset = 40
     BYVAL pbstrType AS WSTRING _                       ' __in BSTR pbstrType
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostSectionGroup_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostSectionDefinitionCollection
' IID = {B7D381EE-8860-47A1-8AF4-1F33B2B1F325}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostSectionDefinitionCollection_INTERFACE_DEFINED)
    %IAppHostSectionDefinitionCollection_INTERFACE_DEFINED = 1

INTERFACE IAppHostSectionDefinitionCollection $IID_IAppHostSectionDefinitionCollection

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Count ( _                               ' VTable offset = 12
   ) AS DWORD                                           ' __retval_out ULONG *pcCount
   ' =====================================================================================
   PROPERTY GET Item ( _                                ' VTable offset = 16
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   ) AS IAppHostSectionDefinition                       ' __retval_out IAppHostSectionDefinition **ppConfigSection
   ' =====================================================================================
   METHOD AddSection ( _                                ' VTable offset = 20
     BYVAL bstrSectionName AS WSTRING _                 ' __in BSTR bstrSectionName
   ) AS IAppHostSectionDefinition                       ' __retval_out IAppHostSectionDefinition **ppConfigSection
   ' =====================================================================================
   METHOD DeleteSection ( _                             ' VTable offset = 24
     BYVAL varIndex AS VARIANT _                        ' __in VARIANT varIndex
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostSectionDefinitionCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostSectionDefinition
' IID = {C5C04795-321C-4014-8FD6-D44658799393}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostSectionDefinition_INTERFACE_DEFINED)
    %IAppHostSectionDefinition_INTERFACE_DEFINED = 1

INTERFACE IAppHostSectionDefinition $IID_IAppHostSectionDefinition

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Name ( _                                ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET Type ( _                                ' VTable offset = 16
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrType
   ' =====================================================================================
   PROPERTY SET Type ( _                                ' VTable offset = 20
     BYVAL pbstrType AS WSTRING _                       ' __in BSTR pbstrType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OverrideModeDefault ( _                 ' VTable offset = 24
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrOverrideModeDefault
   ' =====================================================================================
   PROPERTY SET OverrideModeDefault ( _                 ' VTable offset = 28
     BYVAL pbstrOverrideModeDefault AS WSTRING _        ' __in BSTR pbstrOverrideModeDefault
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowDefinition ( _                     ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrAllowDefinition
   ' =====================================================================================
   PROPERTY SET AllowDefinition ( _                     ' VTable offset = 36
     BYVAL pbstrAllowDefinition AS WSTRING _            ' __in BSTR pbstrAllowDefinition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowLocation ( _                       ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrAllowLocation
   ' =====================================================================================
   PROPERTY SET AllowLocation ( _                       ' VTable offset = 44
     BYVAL pbstrAllowLocation AS WSTRING _              ' __in BSTR pbstrAllowLocation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RequirePermission ( _                   ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfRequirePermission
   ' =====================================================================================
   PROPERTY SET RequirePermission ( _                   ' VTable offset = 52
     BYVAL pfRequirePermission AS INTEGER _             ' __in VARIANT_BOOL pfRequirePermission
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostSectionDefinition_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostWritableAdminManager
' IID = {FA7660F6-7B3F-4237-A8BF-ED0AD0DCBBD9}
' Inherited interface = IAppHostAdminManager
' ########################################################################################

#IF NOT %DEF(%IAppHostWritableAdminManager_INTERFACE_DEFINED)
    %IAppHostWritableAdminManager_INTERFACE_DEFINED = 1

INTERFACE IAppHostWritableAdminManager $IID_IAppHostWritableAdminManager

   INHERIT IAutomation

   ' =====================================================================================
   ' IAppHostAdminManager Methods
   ' =====================================================================================
   METHOD GetAdminSection ( _                           ' VTable offset = 12
     BYVAL bstrSectionName AS WSTRING _                 ' __in BSTR bstrSectionName
   , BYVAL bstrPath AS WSTRING _                        ' __in BSTR bstrPath
   ) AS IAppHostElement                                 ' __retval_out IAppHostElement **ppAdminSection
   ' =====================================================================================
   METHOD GetMetadata ( _                               ' VTable offset = 16
     BYVAL bstrMetadataType AS WSTRING _                ' __in BSTR bstrMetadataType
   ) AS VARIANT                                         ' __retval_out VARIANT *pValue
   ' =====================================================================================
   METHOD SetMetadata ( _                               ' VTable offset = 20
     BYVAL bstrMetadataType AS WSTRING _                ' __in BSTR bstrMetadataType
   , BYVAL Value AS VARIANT _                           ' __in VARIANT Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ConfigManager ( _                       ' VTable offset = 24
   ) AS IAppHostConfigManager                           ' __retval_out IAppHostConfigManager **ppConfigManager
   ' =====================================================================================

   ' =====================================================================================
   ' IAppHostWritableAdminManager Methods
   ' =====================================================================================
   METHOD CommitChanges ( _                             ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CommitPath ( _                          ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCommitPath
   ' =====================================================================================
   PROPERTY SET CommitPath ( _                          ' VTable offset = 36
     BYVAL pbstrCommitPath AS WSTRING _                 ' __in BSTR pbstrCommitPath
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostWritableAdminManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostMappingExtension
' IID = {31A83EA0-C0E4-4A2C-8A01-353CC2A4C60A}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostMappingExtension_INTERFACE_DEFINED)
    %IAppHostMappingExtension_INTERFACE_DEFINED = 1

INTERFACE IAppHostMappingExtension $IID_IAppHostMappingExtension

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetSiteNameFromSiteId ( _                     ' VTable offset = 12
     BYVAL dwSiteId AS DWORD _                          ' __in DWORD dwSiteId
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSiteName
   ' =====================================================================================
   METHOD GetSiteIdFromSiteName ( _                     ' VTable offset = 16
     BYVAL bstrSiteName AS WSTRING _                    ' __in BSTR bstrSiteName
   ) AS DWORD                                           ' __retval_out DWORD *pdwSiteId
   ' =====================================================================================
   METHOD GetSiteElementFromSiteId ( _                  ' VTable offset = 20
     BYVAL dwSiteId AS DWORD _                          ' __in DWORD dwSiteId
   ) AS IAppHostElement                                 ' __retval_out IAppHostElement **ppSiteElement
   ' =====================================================================================
   METHOD MapPath ( _                                   ' VTable offset = 24
     BYVAL bstrSiteName AS WSTRING _                    ' __in BSTR bstrSiteName
   , BYVAL bstrVirtualPath AS WSTRING _                 ' __in BSTR bstrVirtualPath
   , BYREF pbstrPhysicalPath AS WSTRING _               ' __out BSTR *pbstrPhysicalPath
   , BYREF ppVirtualDirectoryElement AS IAppHostElement _ ' __out IAppHostElement **ppVirtualDirectoryElement
   , BYREF ppApplicationElement AS IAppHostElement _    ' __out IAppHostElement **ppApplicationElement
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostMappingExtension_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostPathMapper
' IID = {E7927575-5CC3-403B-822E-328A6B904BEE}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostPathMapper_INTERFACE_DEFINED)
    %IAppHostPathMapper_INTERFACE_DEFINED = 1

INTERFACE IAppHostPathMapper $IID_IAppHostPathMapper

   INHERIT IAutomation

   ' =====================================================================================
   METHOD MapPath ( _                                   ' VTable offset = 12
     BYVAL bstrConfigPath AS WSTRING _                  ' __in BSTR bstrConfigPath
   , BYVAL bstrMappedPhysicalPath AS WSTRING _          ' __in BSTR bstrMappedPhysicalPath
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrNewPhysicalPath
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostPathMapper_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostChangeHandler
' IID = {09829352-87C2-418D-8D79-4133969A489D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostChangeHandler_INTERFACE_DEFINED)
    %IAppHostChangeHandler_INTERFACE_DEFINED = 1

INTERFACE IAppHostChangeHandler $IID_IAppHostChangeHandler

   INHERIT IAutomation

   ' =====================================================================================
   METHOD OnSectionChanges ( _                          ' VTable offset = 12
     BYVAL bstrSectionName AS WSTRING _                 ' __in BSTR bstrSectionName
   , BYVAL bstrConfigPath AS WSTRING _                  ' __in BSTR bstrConfigPath
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostChangeHandler_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostPropertyExtension
' IID = {88E220F3-33E8-4534-AFAC-B4A98ECCF9AE}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostPropertyExtension_INTERFACE_DEFINED)
    %IAppHostPropertyExtension_INTERFACE_DEFINED = 1

INTERFACE IAppHostPropertyExtension $IID_IAppHostPropertyExtension

   INHERIT IAutomation

   ' =====================================================================================
   METHOD ProvideElement ( _                            ' VTable offset = 12
     BYVAL pNewElement AS IAppHostElement _             ' __in IAppHostElement *pNewElement
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostPropertyExtension_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostElementExtension
' IID = {518EB37D-1FF4-42DD-86C3-3140BC35B823}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostElementExtension_INTERFACE_DEFINED)
    %IAppHostElementExtension_INTERFACE_DEFINED = 1

INTERFACE IAppHostElementExtension $IID_IAppHostElementExtension

   INHERIT IAutomation

   ' =====================================================================================
   METHOD ProvideElement ( _                            ' VTable offset = 12
     BYVAL pNewElement AS IAppHostElement _             ' __in IAppHostElement *pNewElement
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostElementExtension_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostMethodExtension
' IID = {70184AC9-7673-4770-96B1-445CE035CF70}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostMethodExtension_INTERFACE_DEFINED)
    %IAppHostMethodExtension_INTERFACE_DEFINED = 1

INTERFACE IAppHostMethodExtension $IID_IAppHostMethodExtension

   INHERIT IAutomation

   ' =====================================================================================
   METHOD ProvideMethod ( _                             ' VTable offset = 12
     BYVAL pMethod AS IAppHostMethod _                  ' __in IAppHostMethod *pMethod
   , BYVAL pMethodInstance AS IAppHostMethodInstance _  ' __in IAppHostMethodInstance *pMethodInstance
   , BYVAL pElement AS IAppHostElement _                ' __in IAppHostElement *pElement
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostMethodExtension_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAppHostPathMapper2
' IID = {0F80E901-8F4C-449A-BF90-13D5D082F187}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAppHostPathMapper2_INTERFACE_DEFINED)
    %IAppHostPathMapper2_INTERFACE_DEFINED = 1

INTERFACE IAppHostPathMapper2 $IID_IAppHostPathMapper2

   INHERIT IAutomation

   ' =====================================================================================
   METHOD MapPath ( _                                   ' VTable offset = 12
     BYVAL bstrConfigPath AS WSTRING _                  ' __in BSTR bstrConfigPath
   , BYVAL bstrMappedPhysicalPath AS WSTRING _          ' __in BSTR bstrMappedPhysicalPath
   , BYREF pbstrNewPhysicalPath AS WSTRING _            ' __out BSTR *pbstrNewPhysicalPath
   , BYREF phImpersonationToken AS DWORD _              ' __out HANDLE **phImpersonationToken
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppHostPathMapper2_INTERFACE_DEFINED__ */
