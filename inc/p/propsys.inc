' ########################################################################################
' Microsoft Windows
' File: propsys.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: PropSysObjects
' Version: 1.0, Locale ID = 0
' Library GUID: {2CDA3294-6C4F-4020-B161-27C530C81FA6}
' ########################################################################################

#INCLUDE THIS ONCE
%PROPSYS_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "oleidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "shtypes.inc"
#INCLUDE ONCE "StructuredQueryCondition.inc"
'#INCLUDE ONCE "propkeydef.inc"

$LIBID_PropSysObjectse = GUID$("{2cda3294-6c4f-4020-b161-27c530c81fa6}")   ' // not registered

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_InMemoryPropertyStore = GUID$("{9A02E012-6303-4E1E-B9A1-630F802592C5}")
$CLSID_PropertySystem = GUID$("{B8967F85-58AE-4F46-9FB2-5D7904798F4B}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IInitializeWithFile = GUID$("{B7D14566-0509-4CCE-A71F-0A554233BD9B}")
$IID_IInitializeWithStream = GUID$("{B824B49D-22AC-4161-AC8A-9916E8FA3F7F}")
$IID_IPropertyStore = GUID$("{886D8EEB-8CF2-4446-8D02-CDBA1DBDCF99}")
$IID_INamedPropertyStore = GUID$("{71604B0F-97B0-4764-8577-2F13E98A1422}")
$IID_IObjectWithPropertyKey = GUID$("{FC0CA0A7-C316-4FD2-9031-3E628E6D4F23}")
$IID_IPropertyChange = GUID$("{F917BC8A-1BBA-4478-A245-1BDE03EB9431}")
$IID_IPropertyChangeArray = GUID$("{380F5CAD-1B5E-42F2-805D-637FD392D31E}")
$IID_IPropertyStoreCapabilities = GUID$("{C8E2D566-186E-4D49-BF41-6909EAD56ACC}")
$IID_IPropertyStoreCache = GUID$("{3017056D-9A91-4E90-937D-746C72ABBF4F}")
$IID_IPropertyEnumType = GUID$("{11E1FBF9-2D56-4A6B-8DB3-7CD193A471F2}")
$IID_IPropertyEnumType2 = GUID$("{9b6e051c-5ddd-4321-9070-fe2acb55e794}")
$IID_IPropertyEnumTypeList = GUID$("{A99400F4-3D84-4557-94BA-1242FB2CC9A6}")
$IID_IPropertyDescription = GUID$("{6F79D558-3E96-4549-A1D1-7D75D2288814}")
$IID_IPropertyDescription2 = GUID$("{57d2eded-5062-400e-b107-5dae79fe57a6}")
$IID_IPropertyDescriptionAliasInfo = GUID$("{F67104FC-2AF9-46FD-B32D-243C1404F3D1}")
$IID_IPropertyDescriptionSearchInfo = GUID$("{078F91BD-29A2-440F-924E-46A291524520}")
$IID_IPropertyDescriptionRelatedPropertyInfo = GUID$("{507393f4-2a3d-4a60-b59e-d9c75716c2dd}")
$IID_IPropertySystem = GUID$("{CA724E8A-C3E6-442B-88A4-6FB0DB8035A3}")
$IID_IPropertyDescriptionList = GUID$("{1F9FC1D0-C39B-4B26-817F-011967D3440E}")
$IID_IPropertyStoreFactory = GUID$("{BC110B6D-57E8-4148-A9C6-91015AB2F3A5}")
$IID_IDelayedPropertyStoreFactory = GUID$("{40D4577F-E237-4BDB-BD69-58F089431B6A}")
$IID_IPersistSerializedPropStorage = GUID$("{E318AD57-0AA0-450F-ACA5-6FAB7103D917}")
$IID_IPersistSerializedPropStorage2 = GUID$("{77effa68-4f98-4366-ba72-573b3d880571}")
$IID_IPropertySystemChangeNotify = GUID$("{FA955FD9-38BE-4879-A6CE-824CF52D609F}")
$IID_ICreateObject = GUID$("{75121952-E0D0-43E5-9380-1D80483ACF72}")

' ########################################################################################
' Interface name = IInitializeWithFile
' IID = B7D14566-0509-4CCE-A71F-0A554233BD9B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInitializeWithFile_INTERFACE_DEFINED)
    %IInitializeWithFile_INTERFACE_DEFINED = 1

INTERFACE IInitializeWithFile $IID_IInitializeWithFile

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnDeviceStateChanged ( _                      ' VTable offset = 12
     BYREF pszFilePath AS WSTRINGZ _                    ' __in LPCWSTR pszFilePath
   , BYVAL grfMode AS DWORD _                           ' __in DWORD grfMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInitializeWithFile_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IInitializeWithStream
' IID = B824B49D-22AC-4161-AC8A-9916E8FA3F7F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInitializeWithStream_INTERFACE_DEFINED)
    %IInitializeWithStream_INTERFACE_DEFINED = 1

INTERFACE IInitializeWithStream $IID_IInitializeWithStream

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pstream AS IStream _                         ' __in IStream *pstream
   , BYVAL grfMode AS DWORD _                           ' __in DWORD grfMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInitializeWithStream_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPropertyStore
' IID = 886D8EEB-8CF2-4446-8D02-CDBA1DBDCF99
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPropertyStore_INTERFACE_DEFINED)
    %IPropertyStore_INTERFACE_DEFINED = 1

INTERFACE IPropertyStore $IID_IPropertyStore

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF cProps AS DWORD _                            ' __out DWORD *cProps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL iProp AS DWORD _                             ' __in DWORD iProp
   , BYREF pkey AS PROPERTYKEY _                        ' __out PROPERTYKEY *pkey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 20
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   , BYREF pv AS PROPVARIANT _                          ' __out PROPVARIANT *pv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 24
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   , BYREF propvar AS PROPVARIANT _                     ' __in REFPROPVARIANT propvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertyStore_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = INamedPropertyStore
' IID = 71604B0F-97B0-4764-8577-2F13E98A1422
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%INamedPropertyStore_INTERFACE_DEFINED)
    %INamedPropertyStore_INTERFACE_DEFINED = 1

INTERFACE INamedPropertyStore $IID_INamedPropertyStore

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNamedValue ( _                             ' VTable offset = 12
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF ppropvar AS PROPVARIANT _                    ' __out PROPVARIANT *ppropvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNamedValue ( _                             ' VTable offset = 16
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF propvar AS PROPVARIANT _                     ' __in REFPROPVARIANT propvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNameCount ( _                              ' VTable offset = 20
     BYREF pdwCount AS DWORD _                          ' __out DWORD *pdwCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNameAt ( _                                 ' VTable offset = 24
     BYVAL iProp AS DWORD _                             ' __in DWORD iProp
   , BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INamedPropertyStore_INTERFACE_DEFINED__ */


' enum GETPROPERTYSTOREFLAGS
%GPS_DEFAULT               = 0&
%GPS_HANDLERPROPERTIESONLY = &H1&
%GPS_READWRITE             = &H2&
%GPS_TEMPORARY             = &H4&
%GPS_FASTPROPERTIESONLY    = &H8&
%GPS_OPENSLOWITEM          = &H10&
%GPS_DELAYCREATION         = &H20&
%GPS_BESTEFFORT            = &H40&
%GPS_NO_OPLOCK             = &H80&
%GPS_MASK_VALID            = &Hff&


' ########################################################################################
' Interface name = IObjectWithPropertyKey
' IID = FC0CA0A7-C316-4FD2-9031-3E628E6D4F23
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IObjectWithPropertyKey_INTERFACE_DEFINED)
    %IObjectWithPropertyKey_INTERFACE_DEFINED = 1

INTERFACE IObjectWithPropertyKey $IID_IObjectWithPropertyKey

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetPropertyKey ( _                            ' VTable offset = 12
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyKey ( _                            ' VTable offset = 16
     BYREF pkey AS PROPERTYKEY _                        ' __out PROPERTYKEY *pkey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectWithPropertyKey_INTERFACE_DEFINED__ */


' enum PKA_FLAGS
%PKA_SET    = 0
%PKA_APPEND = %PKA_SET    + 1
%PKA_DELETE = %PKA_APPEND + 1


' ########################################################################################
' Interface name = IPropertyChange
' IID = F917BC8A-1BBA-4478-A245-1BDE03EB9431
' Inherited interface = IObjectWithPropertyKey
' ########################################################################################

#IF NOT %DEF(%IPropertyChange_INTERFACE_DEFINED)
    %IPropertyChange_INTERFACE_DEFINED = 1

INTERFACE IPropertyChange $IID_IPropertyChange

   INHERIT IUnknown

   ' =====================================================================================
   ' IObjectWithPropertyKey methods
   ' =====================================================================================
   METHOD SetPropertyKey ( _                            ' VTable offset = 12
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyKey ( _                            ' VTable offset = 16
     BYREF pkey AS PROPERTYKEY _                        ' __out PROPERTYKEY *pkey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPropertyChange method
   ' =====================================================================================
   METHOD ApplyToPropVariant ( _                        ' VTable offset = 20
     BYREF propvarIn AS PROPVARIANT _                   ' __in REFPROPVARIANT propvarIn
   , BYREF ppropvarOut AS PROPVARIANT _                 ' __out PROPVARIANT *ppropvarOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertyChange_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPropertyChangeArray
' IID = 380F5CAD-1B5E-42F2-805D-637FD392D31E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPropertyChangeArray_INTERFACE_DEFINED)
    %IPropertyChangeArray_INTERFACE_DEFINED = 1

INTERFACE IPropertyChangeArray $IID_IPropertyChangeArray

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF pcOperations AS DWORD _                      ' __out UINT *pcOperations
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL iIndex AS DWORD _                            ' __in UINT iIndex
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertAt ( _                                  ' VTable offset = 20
     BYVAL iIndex AS DWORD _                            ' __in UINT iIndex
   , BYVAL ppropChange AS IPropertyChange _             ' __in IPropertyChange *ppropChange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Append ( _                                    ' VTable offset = 24
     BYVAL ppropChange AS IPropertyChange _             ' __in IPropertyChange *ppropChange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AppendOrReplace ( _                           ' VTable offset = 28
     BYVAL ppropChange AS IPropertyChange _             ' __in IPropertyChange *ppropChange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAt ( _                                  ' VTable offset = 32
     BYVAL iIndex AS DWORD _                            ' __in UINT iIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsKeyInArray ( _                              ' VTable offset = 36
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertyChangeArray_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPropertyStoreCapabilities
' IID = C8E2D566-186E-4D49-BF41-6909EAD56ACC
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPropertyStoreCapabilities_INTERFACE_DEFINED)
    %IPropertyStoreCapabilities_INTERFACE_DEFINED = 1

INTERFACE IPropertyStoreCapabilities $IID_IPropertyStoreCapabilities

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsPropertyWritable ( _                        ' VTable offset = 12
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertyStoreCapabilities_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPropertyStoreCache
' IID = 3017056D-9A91-4E90-937D-746C72ABBF4F
' Inherited interface = IPropertyStore
' ########################################################################################

#IF NOT %DEF(%IPropertyStoreCache_INTERFACE_DEFINED)
    %IPropertyStoreCache_INTERFACE_DEFINED = 1

' enum PSC_STATE
%PSC_NORMAL      = 0
%PSC_NOTINSOURCE = 1
%PSC_DIRTY       = 2
%PSC_READONLY    = 3

INTERFACE IPropertyStoreCache $IID_IPropertyStoreCache

   INHERIT IUnknown

   ' =====================================================================================
   ' IPropertyStore methods
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF cProps AS DWORD _                            ' __out DWORD *cProps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL iProp AS DWORD _                             ' __in DWORD iProp
   , BYREF pkey AS PROPERTYKEY _                        ' __out PROPERTYKEY *pkey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 20
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   , BYREF pv AS PROPVARIANT _                          ' __out PROPVARIANT *pv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 24
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   , BYREF propvar AS PROPVARIANT _                     ' __in REFPROPVARIANT propvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPropertyStoreCache methods
   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 32
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   , BYREF pstate AS LONG _                             ' __out PSC_STATE *pstate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValueAndState ( _                          ' VTable offset = 36
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   , BYREF ppropvar AS PROPVARIANT _                    ' __out PROPVARIANT *ppropvar
   , BYREF pstate AS LONG _                             ' __out PSC_STATE *pstate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetState ( _                                  ' VTable offset = 40
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   , BYVAL state AS LONG _                              ' __in PSC_STATE state
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetValueAndState ( _                          ' VTable offset = 44
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   , BYREF ppropvar AS PROPVARIANT _                    ' __in const PROPVARIANT *ppropvar
   , BYVAL state AS LONG _                              ' __in PSC_STATE state
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertyStoreCache_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPropertyEnumType
' IID = 11E1FBF9-2D56-4A6B-8DB3-7CD193A471F2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPropertyEnumType_INTERFACE_DEFINED)
    %IPropertyEnumType_INTERFACE_DEFINED = 1

' enum PROPENUMTYPE
%PET_DISCRETEVALUE = 0
%PET_RANGEDVALUE   = 1
%PET_DEFAULTVALUE  = 2
%PET_ENDRANGE      = 3

INTERFACE IPropertyEnumType $IID_IPropertyEnumType

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetEnumType ( _                               ' VTable offset = 12
     BYREF penumtype AS LONG _                          ' __out PROPENUMTYPE *penumtype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 16
     BYREF ppropvar AS PROPVARIANT _                    ' __out PROPVARIANT *ppropvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRangeMinValue ( _                          ' VTable offset = 20
     BYREF ppropvarMin AS PROPVARIANT _                 ' __out PROPVARIANT *ppropvarMin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRangeSetValue ( _                          ' VTable offset = 24
     BYREF ppropvarSet AS PROPVARIANT _                 ' __out PROPVARIANT *ppropvarSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayText ( _                            ' VTable offset = 28
     BYREF ppszDisplay AS DWORD _                       ' __out LPWSTR *ppszDisplay
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertyEnumType_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPropertyEnumType2
' IID = 9b6e051c-5ddd-4321-9070-fe2acb55e794
' Inherited interface = IPropertyEnumType
' ########################################################################################

#IF NOT %DEF(%IPropertyEnumType2_INTERFACE_DEFINED)
    %IPropertyEnumType2_INTERFACE_DEFINED = 1

INTERFACE IPropertyEnumType2 $IID_IPropertyEnumType2

   INHERIT IUnknown

   ' =====================================================================================
   ' IPropertyEnumType methods
   ' =====================================================================================
   METHOD GetEnumType ( _                               ' VTable offset = 12
     BYREF penumtype AS LONG _                          ' __out PROPENUMTYPE *penumtype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 16
     BYREF ppropvar AS PROPVARIANT _                    ' __out PROPVARIANT *ppropvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRangeMinValue ( _                          ' VTable offset = 20
     BYREF ppropvarMin AS PROPVARIANT _                 ' __out PROPVARIANT *ppropvarMin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRangeSetValue ( _                          ' VTable offset = 24
     BYREF ppropvarSet AS PROPVARIANT _                 ' __out PROPVARIANT *ppropvarSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayText ( _                            ' VTable offset = 28
     BYREF ppszDisplay AS DWORD _                       ' __out LPWSTR *ppszDisplay
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPropertyEnumType2 methods
   ' =====================================================================================
   METHOD GetImageReference ( _                         ' VTable offset = 32
     BYREF ppszImageRes AS DWORD _                      ' __out LPWSTR *ppszImageRes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertyEnumType2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPropertyEnumTypeList
' IID = A99400F4-3D84-4557-94BA-1242FB2CC9A6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPropertyEnumTypeList_INTERFACE_DEFINED)
    %IPropertyEnumTypeList_INTERFACE_DEFINED= 1

INTERFACE IPropertyEnumTypeList $IID_IPropertyEnumTypeList

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF pctypes AS DWORD _                           ' __out UINT *pctypes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL itype AS DWORD _                             ' __in UINT itype
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConditionAt ( _                            ' VTable offset = 20
     BYVAL nIndex AS DWORD _                            ' __in UINT nIndex
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindMatchingIndex ( _                         ' VTable offset = 24
     BYREF propvarCmp AS PROPVARIANT _                  ' __in REFPROPVARIANT propvarCmp
   , BYREF pnIndex AS DWORD _                           ' __out UINT *pnIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertyEnumTypeList_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPropertyDescription
' IID = 6F79D558-3E96-4549-A1D1-7D75D2288814
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPropertyDescription_INTERFACE_DEFINED)
    %IPropertyDescription_INTERFACE_DEFINED = 1

' enum PROPDESC_TYPE_FLAGS
%PDTF_DEFAULT                = 0&
%PDTF_MULTIPLEVALUES         = &H1&
%PDTF_ISINNATE               = &H2&
%PDTF_ISGROUP                = &H4&
%PDTF_CANGROUPBY             = &H8&
%PDTF_CANSTACKBY             = &H10&
%PDTF_ISTREEPROPERTY         = &H20&
%PDTF_INCLUDEINFULLTEXTQUERY = &H40&
%PDTF_ISVIEWABLE             = &H80&
%PDTF_ISQUERYABLE            = &H100&
%PDTF_CANBEPURGED	           = &H200
%PDTF_SEARCHRAWVALUE         = &H400&
%PDTF_ISSYSTEMPROPERTY       = &H80000000&
%PDTF_MASK_ALL               = &H800007ff&

' enum PROPDESC_VIEW_FLAGS
%PDVF_DEFAULT             = 0&
%PDVF_CENTERALIGN         = &H1&
%PDVF_RIGHTALIGN          = &H2&
%PDVF_BEGINNEWGROUP       = &H4&
%PDVF_FILLAREA            = &H8&
%PDVF_SORTDESCENDING      = &H10&
%PDVF_SHOWONLYIFPRESENT   = &H20&
%PDVF_SHOWBYDEFAULT       = &H40&
%PDVF_SHOWINPRIMARYLIST   = &H80&
%PDVF_SHOWINSECONDARYLIST = &H100&
%PDVF_HIDELABEL           = &H200&
%PDVF_HIDDEN              = &H800&
%PDVF_CANWRAP             = &H1000&
%PDVF_MASK_ALL            = &H1bff&

' enum PROPDESC_DISPLAYTYPE
%PDDT_STRING     = 0
%PDDT_NUMBER     = 1
%PDDT_BOOLEAN    = 2
%PDDT_DATETIME   = 3
%PDDT_ENUMERATED = 4

' enum PROPDESC_GROUPING_RANGE
%PDGR_DISCRETE     = 0
%PDGR_ALPHANUMERIC = 1
%PDGR_SIZE         = 2
%PDGR_DYNAMIC      = 3
%PDGR_DATE         = 4
%PDGR_PERCENT      = 5
%PDGR_ENUMERATED   = 6

' enum PROPDESC_FORMAT_FLAGS
%PDFF_DEFAULT              = 0&
%PDFF_PREFIXNAME           = &H1&
%PDFF_FILENAME             = &H2&
%PDFF_ALWAYSKB             = &H4&
%PDFF_RESERVED_RIGHTTOLEFT = &H8&
%PDFF_SHORTTIME            = &H10&
%PDFF_LONGTIME             = &H20&
%PDFF_HIDETIME             = &H40&
%PDFF_SHORTDATE            = &H80&
%PDFF_LONGDATE             = &H100&
%PDFF_HIDEDATE             = &H200&
%PDFF_RELATIVEDATE         = &H400&
%PDFF_USEEDITINVITATION    = &H800&
%PDFF_READONLY             = &H1000&
%PDFF_NOAUTOREADINGORDER   = &H2000&

' enum PROPDESC_SORTDESCRIPTION
%PDSD_GENERAL          = 0
%PDSD_A_Z              = 1
%PDSD_LOWEST_HIGHEST   = 2
%PDSD_SMALLEST_BIGGEST = 3
%PDSD_OLDEST_NEWEST    = 4

' enum PROPDESC_RELATIVEDESCRIPTION_TYPE
%PDRDT_GENERAL  = 0
%PDRDT_DATE     = 1
%PDRDT_SIZE     = 2
%PDRDT_COUNT    = 3
%PDRDT_REVISION = 4
%PDRDT_LENGTH   = 5
%PDRDT_DURATION = 6
%PDRDT_SPEED    = 7
%PDRDT_RATE     = 8
%PDRDT_RATING   = 9
%PDRDT_PRIORITY = 10

' enum PROPDESC_AGGREGATION_TYPE
%PDAT_DEFAULT   = 0
%PDAT_FIRST     = 1
%PDAT_SUM       = 2
%PDAT_AVERAGE   = 3
%PDAT_DATERANGE = 4
%PDAT_UNION     = 5
%PDAT_MAX       = 6
%PDAT_MIN       = 7

' enum PROPDESC_CONDITION_TYPE
%PDCOT_NONE     = 0
%PDCOT_STRING   = 1
%PDCOT_SIZE     = 2
%PDCOT_DATETIME = 3
%PDCOT_BOOLEAN  = 4
%PDCOT_NUMBER   = 5

INTERFACE IPropertyDescription $IID_IPropertyDescription

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPropertyKey ( _                            ' VTable offset = 12
     BYREF pkey AS PROPERTYKEY _                        ' __out PROPERTYKEY *pkey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCanonicalName ( _                          ' VTable offset = 16
     BYREF ppszName AS DWORD _                          ' __out LPWSTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyType ( _                           ' VTable offset = 20
     BYREF pvartype AS WORD _                           ' __out VARTYPE *pvartype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayName ( _                            ' VTable offset = 24
     BYREF ppszName AS DWORD _                          ' __out LPWSTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEditInvitation ( _                         ' VTable offset = 28
     BYREF ppszInvite AS DWORD _                        ' __out LPWSTR *ppszInvite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTypeFlags ( _                              ' VTable offset = 32
     BYVAL mask AS LONG _                               ' __in PROPDESC_TYPE_FLAGS mask
   , BYREF ppdtFlags AS LONG _                          ' __out PROPDESC_TYPE_FLAGS *ppdtFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetViewFlags ( _                              ' VTable offset = 36
     BYREF ppdvFlags AS LONG _                          ' __out PROPDESC_VIEW_FLAGS *ppdvFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultColumnWidth ( _                     ' VTable offset = 40
     BYREF pcxChars AS DWORD _                          ' __out UINT *pcxChars
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayType ( _                            ' VTable offset = 44
     BYREF pdisplaytype AS LONG _                       ' __out PROPDESC_DISPLAYTYPE *pdisplaytype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColumnState ( _                            ' VTable offset = 48
     BYREF pcsFlags AS DWORD _                          ' __out SHCOLSTATEF *pcsFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGroupingRange ( _                          ' VTable offset = 48
     BYREF pgr AS LONG _                                ' __out PROPDESC_GROUPING_RANGE *pgr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRelativeDescriptionType ( _                ' VTable offset = 52
     BYREF prdt AS LONG _                               ' __out PROPDESC_RELATIVEDESCRIPTION_TYPE *prdt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRelativeDescription ( _                    ' VTable offset = 56
     BYREF propvar1 AS PROPVARIANT _                    ' __in REFPROPVARIANT propvar1
   , BYREF propvar2 AS PROPVARIANT _                    ' __in REFPROPVARIANT propvar2
   , BYREF ppszDesc1 AS DWORD _                         ' __out LPWSTR *ppszDesc1
   , BYREF ppszDesc2 AS DWORD _                         ' __out LPWSTR *ppszDesc2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSortDescription ( _                        ' VTable offset = 60
     BYREF psd AS LONG _                                ' __out PROPDESC_SORTDESCRIPTION *psd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSortDescriptionLabel ( _                   ' VTable offset = 64
     BYVAL fDescending AS LONG _                        ' __in BOOL fDescending
   , BYREF ppszDescription AS DWORD _                   ' __out LPWSTR *ppszDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAggregationType ( _                        ' VTable offset = 68
     BYREF paggtype AS LONG _                           ' __out PROPDESC_AGGREGATION_TYPE *paggtype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConditionType ( _                          ' VTable offset = 72
     BYREF pcontype AS LONG _                           ' __out PROPDESC_CONDITION_TYPE *pcontype
   , BYREF popDefault AS LONG _                         ' __out CONDITION_OPERATION *popDefault
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEnumTypeList ( _                           ' VTable offset = 76
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CoerceToCanonicalValue ( _                    ' VTable offset = 80
     BYREF ppropvar AS PROPVARIANT _                    ' __in_out PROPVARIANT *ppropvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FormatForDisplay ( _                          ' VTable offset = 84
     BYREF propvar AS PROPVARIANT _                     ' __in REFPROPVARIANT propvar
   , BYVAL pdfFlags AS LONG _                           ' __in PROPDESC_FORMAT_FLAGS pdfFlags
   , BYREF ppszDisplay AS DWORD _                       ' __out LPWSTR *ppszDisplay
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsValueCanonical ( _                          ' VTable offset = 88
     BYREF propvar AS PROPVARIANT _                     ' __in REFPROPVARIANT propvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertyDescription_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPropertyDescription2
' IID = 57d2eded-5062-400e-b107-5dae79fe57a6
' Inherited interface = IPropertyDescription
' ########################################################################################

#IF NOT %DEF(%IPropertyDescription2_INTERFACE_DEFINED)
    %IPropertyDescription2_INTERFACE_DEFINED = 1

INTERFACE IPropertyDescription2 $IID_IPropertyDescription2

   INHERIT IUnknown

   ' =====================================================================================
   ' IPropertyDescription methods
   ' =====================================================================================
   METHOD GetPropertyKey ( _                            ' VTable offset = 12
     BYREF pkey AS PROPERTYKEY _                        ' __out PROPERTYKEY *pkey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCanonicalName ( _                          ' VTable offset = 16
     BYREF ppszName AS DWORD _                          ' __out LPWSTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyType ( _                           ' VTable offset = 20
     BYREF pvartype AS WORD _                           ' __out VARTYPE *pvartype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayName ( _                            ' VTable offset = 24
     BYREF ppszName AS DWORD _                          ' __out LPWSTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEditInvitation ( _                         ' VTable offset = 28
     BYREF ppszInvite AS DWORD _                        ' __out LPWSTR *ppszInvite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTypeFlags ( _                              ' VTable offset = 32
     BYVAL mask AS LONG _                               ' __in PROPDESC_TYPE_FLAGS mask
   , BYREF ppdtFlags AS LONG _                          ' __out PROPDESC_TYPE_FLAGS *ppdtFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetViewFlags ( _                              ' VTable offset = 36
     BYREF ppdvFlags AS LONG _                          ' __out PROPDESC_VIEW_FLAGS *ppdvFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultColumnWidth ( _                     ' VTable offset = 40
     BYREF pcxChars AS DWORD _                          ' __out UINT *pcxChars
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayType ( _                            ' VTable offset = 44
     BYREF pdisplaytype AS LONG _                       ' __out PROPDESC_DISPLAYTYPE *pdisplaytype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColumnState ( _                            ' VTable offset = 48
     BYREF pcsFlags AS DWORD _                          ' __out SHCOLSTATEF *pcsFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGroupingRange ( _                          ' VTable offset = 48
     BYREF pgr AS LONG _                                ' __out PROPDESC_GROUPING_RANGE *pgr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRelativeDescriptionType ( _                ' VTable offset = 52
     BYREF prdt AS LONG _                               ' __out PROPDESC_RELATIVEDESCRIPTION_TYPE *prdt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRelativeDescription ( _                    ' VTable offset = 56
     BYREF propvar1 AS PROPVARIANT _                    ' __in REFPROPVARIANT propvar1
   , BYREF propvar2 AS PROPVARIANT _                    ' __in REFPROPVARIANT propvar2
   , BYREF ppszDesc1 AS DWORD _                         ' __out LPWSTR *ppszDesc1
   , BYREF ppszDesc2 AS DWORD _                         ' __out LPWSTR *ppszDesc2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSortDescription ( _                        ' VTable offset = 60
     BYREF psd AS LONG _                                ' __out PROPDESC_SORTDESCRIPTION *psd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSortDescriptionLabel ( _                   ' VTable offset = 64
     BYVAL fDescending AS LONG _                        ' __in BOOL fDescending
   , BYREF ppszDescription AS DWORD _                   ' __out LPWSTR *ppszDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAggregationType ( _                        ' VTable offset = 68
     BYREF paggtype AS LONG _                           ' __out PROPDESC_AGGREGATION_TYPE *paggtype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConditionType ( _                          ' VTable offset = 72
     BYREF pcontype AS LONG _                           ' __out PROPDESC_CONDITION_TYPE *pcontype
   , BYREF popDefault AS LONG _                         ' __out CONDITION_OPERATION *popDefault
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEnumTypeList ( _                           ' VTable offset = 76
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CoerceToCanonicalValue ( _                    ' VTable offset = 80
     BYREF ppropvar AS PROPVARIANT _                    ' __in_out PROPVARIANT *ppropvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FormatForDisplay ( _                          ' VTable offset = 84
     BYREF propvar AS PROPVARIANT _                     ' __in REFPROPVARIANT propvar
   , BYVAL pdfFlags AS LONG _                           ' __in PROPDESC_FORMAT_FLAGS pdfFlags
   , BYREF ppszDisplay AS DWORD _                       ' __out LPWSTR *ppszDisplay
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsValueCanonical ( _                          ' VTable offset = 88
     BYREF propvar AS PROPVARIANT _                     ' __in REFPROPVARIANT propvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPropertyDescription2 methods
   ' =====================================================================================
   METHOD GetImageReferenceForValue ( _                 ' VTable offset = 92
     BYREF propvar AS PROPVARIANT _                     ' __in REFPROPVARIANT propvar
   , BYREF ppszImageRes AS DWORD _                      ' __out LPWSTR *ppszImageRes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertyDescription2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPropertyDescriptionAliasInfo
' IID = F67104FC-2AF9-46FD-B32D-243C1404F3D1
' Inherited interface = IPropertyDescription
' ########################################################################################

#IF NOT %DEF(%IPropertyDescriptionAliasInfo_INTERFACE_DEFINED)
    %IPropertyDescriptionAliasInfo_INTERFACE_DEFINED = 1

INTERFACE IPropertyDescriptionAliasInfo $IID_IPropertyDescriptionAliasInfo

   INHERIT IUnknown

   ' =====================================================================================
   ' IPropertyDescription methods
   ' =====================================================================================
   METHOD GetPropertyKey ( _                            ' VTable offset = 12
     BYREF pkey AS PROPERTYKEY _                        ' __out PROPERTYKEY *pkey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCanonicalName ( _                          ' VTable offset = 16
     BYREF ppszName AS DWORD _                          ' __out LPWSTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyType ( _                           ' VTable offset = 20
     BYREF pvartype AS WORD _                           ' __out VARTYPE *pvartype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayName ( _                            ' VTable offset = 24
     BYREF ppszName AS DWORD _                          ' __out LPWSTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEditInvitation ( _                         ' VTable offset = 28
     BYREF ppszInvite AS DWORD _                        ' __out LPWSTR *ppszInvite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTypeFlags ( _                              ' VTable offset = 32
     BYVAL mask AS LONG _                               ' __in PROPDESC_TYPE_FLAGS mask
   , BYREF ppdtFlags AS LONG _                          ' __out PROPDESC_TYPE_FLAGS *ppdtFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetViewFlags ( _                              ' VTable offset = 36
     BYREF ppdvFlags AS LONG _                          ' __out PROPDESC_VIEW_FLAGS *ppdvFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultColumnWidth ( _                     ' VTable offset = 40
     BYREF pcxChars AS DWORD _                          ' __out UINT *pcxChars
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayType ( _                            ' VTable offset = 44
     BYREF pdisplaytype AS LONG _                       ' __out PROPDESC_DISPLAYTYPE *pdisplaytype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColumnState ( _                            ' VTable offset = 48
     BYREF pcsFlags AS DWORD _                          ' __out SHCOLSTATEF *pcsFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGroupingRange ( _                          ' VTable offset = 48
     BYREF pgr AS LONG _                                ' __out PROPDESC_GROUPING_RANGE *pgr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRelativeDescriptionType ( _                ' VTable offset = 52
     BYREF prdt AS LONG _                               ' __out PROPDESC_RELATIVEDESCRIPTION_TYPE *prdt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRelativeDescription ( _                    ' VTable offset = 56
     BYREF propvar1 AS PROPVARIANT _                    ' __in REFPROPVARIANT propvar1
   , BYREF propvar2 AS PROPVARIANT _                    ' __in REFPROPVARIANT propvar2
   , BYREF ppszDesc1 AS DWORD _                         ' __out LPWSTR *ppszDesc1
   , BYREF ppszDesc2 AS DWORD _                         ' __out LPWSTR *ppszDesc2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSortDescription ( _                        ' VTable offset = 60
     BYREF psd AS LONG _                                ' __out PROPDESC_SORTDESCRIPTION *psd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSortDescriptionLabel ( _                   ' VTable offset = 64
     BYVAL fDescending AS LONG _                        ' __in BOOL fDescending
   , BYREF ppszDescription AS DWORD _                   ' __out LPWSTR *ppszDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAggregationType ( _                        ' VTable offset = 68
     BYREF paggtype AS LONG _                           ' __out PROPDESC_AGGREGATION_TYPE *paggtype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConditionType ( _                          ' VTable offset = 72
     BYREF pcontype AS LONG _                           ' __out PROPDESC_CONDITION_TYPE *pcontype
   , BYREF popDefault AS LONG _                         ' __out CONDITION_OPERATION *popDefault
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEnumTypeList ( _                           ' VTable offset = 76
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CoerceToCanonicalValue ( _                    ' VTable offset = 80
     BYREF ppropvar AS PROPVARIANT _                    ' __in_out PROPVARIANT *ppropvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FormatForDisplay ( _                          ' VTable offset = 84
     BYREF propvar AS PROPVARIANT _                     ' __in REFPROPVARIANT propvar
   , BYVAL pdfFlags AS LONG _                           ' __in PROPDESC_FORMAT_FLAGS pdfFlags
   , BYREF ppszDisplay AS DWORD _                       ' __out LPWSTR *ppszDisplay
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsValueCanonical ( _                          ' VTable offset = 88
     BYREF propvar AS PROPVARIANT _                     ' __in REFPROPVARIANT propvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPropertyDescriptionAliasInfo methods
   ' =====================================================================================
   METHOD GetSortByAlias ( _                            ' VTable offset = 92
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAdditionalSortByAliases ( _                ' VTable offset = 96
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertyDescriptionAliasInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPropertyDescriptionSearchInfo
' IID = 078F91BD-29A2-440F-924E-46A291524520
' Inherited interface = IPropertyDescription
' ########################################################################################

#IF NOT %DEF(%IPropertyDescriptionSearchInfo_INTERFACE_DEFINED)
    %IPropertyDescriptionSearchInfo_INTERFACE_DEFINED = 1

' enum PROPDESC_SEARCHINFO_FLAGS
%PDSIF_DEFAULT         = 0&
%PDSIF_ININVERTEDINDEX = &H1&
%PDSIF_ISCOLUMN        = &H2&
%PDSIF_ISCOLUMNSPARSE  = &H4&
%PDSIF_ALWAYSINCLUDE   = &H8&

' enum PROPDESC_COLUMNINDEX_TYPE
%PDCIT_NONE         = 0
%PDCIT_ONDISK       = 1
%PDCIT_INMEMORY     = 2
%PDCIT_ONDEMAND     = 3
%PDCIT_ONDISKALL    = 4
%PDCIT_ONDISKVECTOR = 5

INTERFACE IPropertyDescriptionSearchInfo $IID_IPropertyDescriptionSearchInfo

   INHERIT IUnknown

   ' =====================================================================================
   ' IPropertyDescription methods
   ' =====================================================================================
   METHOD GetPropertyKey ( _                            ' VTable offset = 12
     BYREF pkey AS PROPERTYKEY _                        ' __out PROPERTYKEY *pkey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCanonicalName ( _                          ' VTable offset = 16
     BYREF ppszName AS DWORD _                          ' __out LPWSTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyType ( _                           ' VTable offset = 20
     BYREF pvartype AS WORD _                           ' __out VARTYPE *pvartype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayName ( _                            ' VTable offset = 24
     BYREF ppszName AS DWORD _                          ' __out LPWSTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEditInvitation ( _                         ' VTable offset = 28
     BYREF ppszInvite AS DWORD _                        ' __out LPWSTR *ppszInvite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTypeFlags ( _                              ' VTable offset = 32
     BYVAL mask AS LONG _                               ' __in PROPDESC_TYPE_FLAGS mask
   , BYREF ppdtFlags AS LONG _                          ' __out PROPDESC_TYPE_FLAGS *ppdtFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetViewFlags ( _                              ' VTable offset = 36
     BYREF ppdvFlags AS LONG _                          ' __out PROPDESC_VIEW_FLAGS *ppdvFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultColumnWidth ( _                     ' VTable offset = 40
     BYREF pcxChars AS DWORD _                          ' __out UINT *pcxChars
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayType ( _                            ' VTable offset = 44
     BYREF pdisplaytype AS LONG _                       ' __out PROPDESC_DISPLAYTYPE *pdisplaytype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColumnState ( _                            ' VTable offset = 48
     BYREF pcsFlags AS DWORD _                          ' __out SHCOLSTATEF *pcsFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGroupingRange ( _                          ' VTable offset = 48
     BYREF pgr AS LONG _                                ' __out PROPDESC_GROUPING_RANGE *pgr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRelativeDescriptionType ( _                ' VTable offset = 52
     BYREF prdt AS LONG _                               ' __out PROPDESC_RELATIVEDESCRIPTION_TYPE *prdt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRelativeDescription ( _                    ' VTable offset = 56
     BYREF propvar1 AS PROPVARIANT _                    ' __in REFPROPVARIANT propvar1
   , BYREF propvar2 AS PROPVARIANT _                    ' __in REFPROPVARIANT propvar2
   , BYREF ppszDesc1 AS DWORD _                         ' __out LPWSTR *ppszDesc1
   , BYREF ppszDesc2 AS DWORD _                         ' __out LPWSTR *ppszDesc2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSortDescription ( _                        ' VTable offset = 60
     BYREF psd AS LONG _                                ' __out PROPDESC_SORTDESCRIPTION *psd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSortDescriptionLabel ( _                   ' VTable offset = 64
     BYVAL fDescending AS LONG _                        ' __in BOOL fDescending
   , BYREF ppszDescription AS DWORD _                   ' __out LPWSTR *ppszDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAggregationType ( _                        ' VTable offset = 68
     BYREF paggtype AS LONG _                           ' __out PROPDESC_AGGREGATION_TYPE *paggtype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConditionType ( _                          ' VTable offset = 72
     BYREF pcontype AS LONG _                           ' __out PROPDESC_CONDITION_TYPE *pcontype
   , BYREF popDefault AS LONG _                         ' __out CONDITION_OPERATION *popDefault
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEnumTypeList ( _                           ' VTable offset = 76
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CoerceToCanonicalValue ( _                    ' VTable offset = 80
     BYREF ppropvar AS PROPVARIANT _                    ' __in_out PROPVARIANT *ppropvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FormatForDisplay ( _                          ' VTable offset = 84
     BYREF propvar AS PROPVARIANT _                     ' __in REFPROPVARIANT propvar
   , BYVAL pdfFlags AS LONG _                           ' __in PROPDESC_FORMAT_FLAGS pdfFlags
   , BYREF ppszDisplay AS DWORD _                       ' __out LPWSTR *ppszDisplay
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsValueCanonical ( _                          ' VTable offset = 88
     BYREF propvar AS PROPVARIANT _                     ' __in REFPROPVARIANT propvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPropertyDescriptionSearchInfo methods
   ' =====================================================================================
   METHOD GetSearchInfoFlags ( _                        ' VTable offset = 92
     BYREF ppdsiFlags AS LONG _                         ' __out PROPDESC_SEARCHINFO_FLAGS *ppdsiFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColumnIndexType ( _                        ' VTable offset = 96
     BYREF ppdciType AS LONG _                          ' __out PROPDESC_COLUMNINDEX_TYPE *ppdciType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProjectionString ( _                       ' VTable offset = 100
     BYREF ppszProjection AS DWORD _                    ' __out LPWSTR *ppszProjection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxSize ( _                                ' VTable offset = 104
     BYREF pcbMaxSize AS DWORD _                        ' __out UINT *pcbMaxSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertyDescriptionSearchInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPropertyDescriptionRelatedPropertyInfo
' IID = 507393f4-2a3d-4a60-b59e-d9c75716c2dd
' Inherited interface = IPropertyDescription
' ########################################################################################

#IF NOT %DEF(%IPropertyDescriptionRelatedPropertyInfo_INTERFACE_DEFINED)
    %IPropertyDescriptionRelatedPropertyInfo_INTERFACE_DEFINED = 1

INTERFACE IPropertyDescriptionRelatedPropertyInfo $IID_IPropertyDescriptionRelatedPropertyInfo

   INHERIT IUnknown

   ' =====================================================================================
   ' IPropertyDescription methods
   ' =====================================================================================
   METHOD GetPropertyKey ( _                            ' VTable offset = 12
     BYREF pkey AS PROPERTYKEY _                        ' __out PROPERTYKEY *pkey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCanonicalName ( _                          ' VTable offset = 16
     BYREF ppszName AS DWORD _                          ' __out LPWSTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyType ( _                           ' VTable offset = 20
     BYREF pvartype AS WORD _                           ' __out VARTYPE *pvartype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayName ( _                            ' VTable offset = 24
     BYREF ppszName AS DWORD _                          ' __out LPWSTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEditInvitation ( _                         ' VTable offset = 28
     BYREF ppszInvite AS DWORD _                        ' __out LPWSTR *ppszInvite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTypeFlags ( _                              ' VTable offset = 32
     BYVAL mask AS LONG _                               ' __in PROPDESC_TYPE_FLAGS mask
   , BYREF ppdtFlags AS LONG _                          ' __out PROPDESC_TYPE_FLAGS *ppdtFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetViewFlags ( _                              ' VTable offset = 36
     BYREF ppdvFlags AS LONG _                          ' __out PROPDESC_VIEW_FLAGS *ppdvFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultColumnWidth ( _                     ' VTable offset = 40
     BYREF pcxChars AS DWORD _                          ' __out UINT *pcxChars
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayType ( _                            ' VTable offset = 44
     BYREF pdisplaytype AS LONG _                       ' __out PROPDESC_DISPLAYTYPE *pdisplaytype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColumnState ( _                            ' VTable offset = 48
     BYREF pcsFlags AS DWORD _                          ' __out SHCOLSTATEF *pcsFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGroupingRange ( _                          ' VTable offset = 48
     BYREF pgr AS LONG _                                ' __out PROPDESC_GROUPING_RANGE *pgr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRelativeDescriptionType ( _                ' VTable offset = 52
     BYREF prdt AS LONG _                               ' __out PROPDESC_RELATIVEDESCRIPTION_TYPE *prdt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRelativeDescription ( _                    ' VTable offset = 56
     BYREF propvar1 AS PROPVARIANT _                    ' __in REFPROPVARIANT propvar1
   , BYREF propvar2 AS PROPVARIANT _                    ' __in REFPROPVARIANT propvar2
   , BYREF ppszDesc1 AS DWORD _                         ' __out LPWSTR *ppszDesc1
   , BYREF ppszDesc2 AS DWORD _                         ' __out LPWSTR *ppszDesc2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSortDescription ( _                        ' VTable offset = 60
     BYREF psd AS LONG _                                ' __out PROPDESC_SORTDESCRIPTION *psd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSortDescriptionLabel ( _                   ' VTable offset = 64
     BYVAL fDescending AS LONG _                        ' __in BOOL fDescending
   , BYREF ppszDescription AS DWORD _                   ' __out LPWSTR *ppszDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAggregationType ( _                        ' VTable offset = 68
     BYREF paggtype AS LONG _                           ' __out PROPDESC_AGGREGATION_TYPE *paggtype
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConditionType ( _                          ' VTable offset = 72
     BYREF pcontype AS LONG _                           ' __out PROPDESC_CONDITION_TYPE *pcontype
   , BYREF popDefault AS LONG _                         ' __out CONDITION_OPERATION *popDefault
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEnumTypeList ( _                           ' VTable offset = 76
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CoerceToCanonicalValue ( _                    ' VTable offset = 80
     BYREF ppropvar AS PROPVARIANT _                    ' __in_out PROPVARIANT *ppropvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FormatForDisplay ( _                          ' VTable offset = 84
     BYREF propvar AS PROPVARIANT _                     ' __in REFPROPVARIANT propvar
   , BYVAL pdfFlags AS LONG _                           ' __in PROPDESC_FORMAT_FLAGS pdfFlags
   , BYREF ppszDisplay AS DWORD _                       ' __out LPWSTR *ppszDisplay
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsValueCanonical ( _                          ' VTable offset = 88
     BYREF propvar AS PROPVARIANT _                     ' __in REFPROPVARIANT propvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPropertyDescriptionSearchInfo methods
   ' =====================================================================================
   METHOD GetRelatedProperty ( _                        ' VTable offset = 92
     BYREF pszRelationshipName AS WSTRINGZ _            ' __in LPCWSTR pszRelationshipName
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertyDescriptionSearchInfo_INTERFACE_DEFINED__ */

' enum PROPDESC_ENUMFILTER
%PDEF_ALL             = 0
%PDEF_SYSTEM          = 1
%PDEF_NONSYSTEM       = 2
%PDEF_VIEWABLE        = 3
%PDEF_QUERYABLE       = 4
%PDEF_INFULLTEXTQUERY = 5
%PDEF_COLUMN          = 6


' ########################################################################################
' Interface name = IPropertySystem
' IID = CA724E8A-C3E6-442B-88A4-6FB0DB8035A3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPropertySystem_INTERFACE_DEFINED)
    %IPropertySystem_INTERFACE_DEFINED = 1

INTERFACE IPropertySystem $IID_IPropertySystem

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPropertyDescription ( _                    ' VTable offset = 12
     BYREF propkey AS PROPERTYKEY _                     ' __in REFPROPERTYKEY propkey
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyDescriptionByName ( _              ' VTable offset = 16
     BYREF pszCanonicalName AS WSTRINGZ _               ' __in LPCWSTR pszCanonicalName
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyDescriptionListFromString ( _      ' VTable offset = 20
     BYREF pszPropList AS WSTRINGZ _                    ' __in LPCWSTR pszPropList
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumeratePropertyDescriptions ( _             ' VTable offset = 24
     BYVAL filterOn AS LONG _                           ' __in PROPDESC_ENUMFILTER filterOn
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FormatForDisplay ( _                          ' VTable offset = 28
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   , BYREF propvar AS PROPVARIANT _                     ' __in REFPROPVARIANT propvar
   , BYVAL pdff AS LONG _                               ' __in PROPDESC_FORMAT_FLAGS pdff
   , BYREF pszText AS WSTRINGZ _                        ' __out (cchText) LPWSTR pszText
   , BYREF cchText AS DWORD _                           ' __in DWORD cchText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FormatForDisplayAlloc ( _                     ' VTable offset = 32
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   , BYREF propvar AS PROPVARIANT _                     ' __in REFPROPVARIANT propvar
   , BYVAL pdff AS LONG _                               ' __in PROPDESC_FORMAT_FLAGS pdff
   , BYREF ppszDisplay AS DWORD _                       ' __out LPWSTR *ppszDisplay
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterPropertySchema ( _                    ' VTable offset = 36
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterPropertySchema ( _                  ' VTable offset = 40
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RefreshPropertySchema ( _                     ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertySystem_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPropertyDescriptionList
' IID = 1F9FC1D0-C39B-4B26-817F-011967D3440E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPropertyDescriptionList_INTERFACE_DEFINED)
    %IPropertyDescriptionList_INTERFACE_DEFINED = 1

INTERFACE IPropertyDescriptionList $IID_IPropertyDescriptionList

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF pcElem AS DWORD _                            ' __out UINT *pcElem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL iElem AS DWORD _                             ' __in UINT iElem
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertyDescriptionList_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPropertyStoreFactory
' IID = BC110B6D-57E8-4148-A9C6-91015AB2F3A5
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPropertyStoreFactory_INTERFACE_DEFINED)
    %IPropertyStoreFactory_INTERFACE_DEFINED = 1

INTERFACE IPropertyStoreFactory $IID_IPropertyStoreFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPropertyStore ( _                          ' VTable offset = 12
     BYVAL flags AS LONG _                              ' __in GETPROPERTYSTOREFLAGS flags
   , BYVAL pUnkFactory AS IUnknown _                    ' __in IUnknown *pUnkFactory
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyStoreForKeys ( _                   ' VTable offset = 16
     BYREF rgKeys AS PROPERTYKEY _                      ' __in const PROPERTYKEY *rgKeys
   , BYVAL cKeys AS DWORD _                             ' __in UINT cKeys
   , BYVAL flags AS LONG _                              ' __in GETPROPERTYSTOREFLAGS flags
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertyStoreFactory_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDelayedPropertyStoreFactory
' IID = 40D4577F-E237-4BDB-BD69-58F089431B6A
' Inherited interface = IPropertyStoreFactory
' ########################################################################################

#IF NOT %DEF(%IDelayedPropertyStoreFactory_INTERFACE_DEFINED)
    %IDelayedPropertyStoreFactory_INTERFACE_DEFINED = 1

INTERFACE IDelayedPropertyStoreFactory $IID_IDelayedPropertyStoreFactory

   INHERIT IUnknown

   ' =====================================================================================
   ' IPropertyStoreFactory methods
   ' =====================================================================================
   METHOD GetPropertyStore ( _                          ' VTable offset = 12
     BYVAL flags AS LONG _                              ' __in GETPROPERTYSTOREFLAGS flags
   , BYVAL pUnkFactory AS IUnknown _                    ' __in IUnknown *pUnkFactory
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyStoreForKeys ( _                   ' VTable offset = 16
     BYREF rgKeys AS PROPERTYKEY _                      ' __in const PROPERTYKEY *rgKeys
   , BYVAL cKeys AS DWORD _                             ' __in UINT cKeys
   , BYVAL flags AS LONG _                              ' __in GETPROPERTYSTOREFLAGS flags
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDelayedPropertyStoreFactory methods
   ' =====================================================================================
   METHOD GetDelayedPropertyStore ( _                   ' VTable offset = 20
     BYVAL flags AS LONG _                              ' __in GETPROPERTYSTOREFLAGS flags
   , BYVAL dwStoreId AS DWORD _                         ' __in DWORD dwStoreId
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDelayedPropertyStoreFactory_INTERFACE_DEFINED__ */


' enum PERSIST_SPROPSTORE_FLAGS
%FPSPS_DEFAULT  = 0
%FPSPS_READONLY = &H1

'typedef int PERSIST_SPROPSTORE_FLAGS;
'typedef struct tagSERIALIZEDPROPSTORAGE SERIALIZEDPROPSTORAGE;
'typedef SERIALIZEDPROPSTORAGE __unaligned *PUSERIALIZEDPROPSTORAGE;
'typedef const SERIALIZEDPROPSTORAGE __unaligned *PCUSERIALIZEDPROPSTORAGE;


' ########################################################################################
' Interface name = IPersistSerializedPropStorage
' IID = E318AD57-0AA0-450F-ACA5-6FAB7103D917
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPersistSerializedPropStorage_INTERFACE_DEFINED)
    %IPersistSerializedPropStorage_INTERFACE_DEFINED = 1

INTERFACE IPersistSerializedPropStorage $IID_IPersistSerializedPropStorage

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetFlags ( _                                  ' VTable offset = 12
     BYVAL flags AS LONG _                              ' __in PERSIST_SPROPSTORE_FLAGS flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPropertyStorage ( _                        ' VTable offset = 16
     BYVAL psps AS BYTE PTR _                           ' __in bcount(cb)  PCUSERIALIZEDPROPSTORAGE psps
   , BYVAL cb AS DWORD _                                ' __in DWORD cb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyStorage ( _                        ' VTable offset = 20
     BYREF ppsps AS DWORD _                             ' __out bcount(*pcb)  SERIALIZEDPROPSTORAGE **ppsps
   , BYREF pcb AS DWORD _                               ' __out DWORD *pcb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPersistSerializedPropStorage_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPersistSerializedPropStorage2
' IID = 77effa68-4f98-4366-ba72-573b3d880571
' Inherited interface = IPersistSerializedPropStorage
' ########################################################################################

#IF NOT %DEF(%IPersistSerializedPropStorage2_INTERFACE_DEFINED)
    %IPersistSerializedPropStorage2_INTERFACE_DEFINED = 1

INTERFACE IPersistSerializedPropStorage2 $IID_IPersistSerializedPropStorage2

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersistSerializedPropStorage methods
   ' =====================================================================================
   METHOD SetFlags ( _                                  ' VTable offset = 12
     BYVAL flags AS LONG _                              ' __in PERSIST_SPROPSTORE_FLAGS flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPropertyStorage ( _                        ' VTable offset = 16
     BYVAL psps AS BYTE PTR _                           ' __in bcount(cb)  PCUSERIALIZEDPROPSTORAGE psps
   , BYVAL cb AS DWORD _                                ' __in DWORD cb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyStorage ( _                        ' VTable offset = 20
     BYREF ppsps AS DWORD _                             ' __out bcount(*pcb)  SERIALIZEDPROPSTORAGE **ppsps
   , BYREF pcb AS DWORD _                               ' __out DWORD *pcb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPersistSerializedPropStorage2 methods
   ' =====================================================================================
   METHOD GetPropertyStorageSize ( _                    ' VTable offset = 24
     BYREF pcb AS DWORD _                               ' __out DWORD *pcb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyStorageBuffer ( _                  ' VTable offset = 28
     BYREF psps AS DWORD _                              ' __out SERIALIZEDPROPSTORAGE *psps
   , BYVAL cb AS DWORD _                                ' __in DWORD cb
   , BYREF pcbWritten AS DWORD _                        ' __out DWORD *pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPersistSerializedPropStorage2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPropertySystemChangeNotify
' IID = FA955FD9-38BE-4879-A6CE-824CF52D609F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPropertySystemChangeNotify_INTERFACE_DEFINED)
    %IPropertySystemChangeNotify_INTERFACE_DEFINED = 1

INTERFACE IPropertySystemChangeNotify $IID_IPropertySystemChangeNotify

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SchemaRefreshed ( _                           ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertySystemChangeNotify_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICreateObject
' IID = 75121952-E0D0-43E5-9380-1D80483ACF72
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICreateObject_INTERFACE_DEFINED)
    %ICreateObject_INTERFACE_DEFINED = 1

INTERFACE ICreateObject $IID_ICreateObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateObject ( _                              ' VTable offset = 12
     BYREF clsid AS GUID _                              ' __in REFCLSID clsid
   , BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICreateObject_INTERFACE_DEFINED__ */


DECLARE FUNCTION PSFormatForDisplay IMPORT "PROPSYS.DLL" ALIAS "PSFormatForDisplay" ( _
   BYREF propkey AS PROPERTYKEY _                       ' __in  REFPROPERTYKEY propkey
 , BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYVAL pdfFlags AS LONG _                             ' __in  PROPDESC_FORMAT_FLAGS pdfFlags
 , BYREF pwszText AS WSTRINGZ _                         ' __out LPWSTR pwszText
 , BYVAL cchText AS DWORD _                             ' __in  DWORD cchText
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSFormatForDisplayAlloc IMPORT "PROPSYS.DLL" ALIAS "PSFormatForDisplayAlloc" ( _
   BYREF key AS PROPERTYKEY _                           ' __in  REFPROPERTYKEY key
 , BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYVAL pdff AS LONG _                                 ' __in  PROPDESC_FORMAT_FLAGS pdff
 , BYREF ppszDisplay AS DWORD _                         ' __out PWSTR *ppszDisplay
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSFormatPropertyValue IMPORT "PROPSYS.DLL" ALIAS "PSFormatPropertyValue" ( _
   BYVAL pps AS IPropertyStore _                        ' __in  IPropertyStore *pps
 , BYVAL ppd AS IPropertyDescription _                  ' __in  IPropertyDescription *ppd
 , BYVAL pdff AS LONG _                                 ' __in  PROPDESC_FORMAT_FLAGS pdff
 , BYREF ppszDisplay AS DWORD _                         ' __out LPWSTR *ppszDisplay
 ) AS LONG                                              ' HRESULT

'// Retrieve the image reference associated with a property value (if specified)
DECLARE FUNCTION PSGetImageReferenceForValue IMPORT "PROPSYS.DLL" ALIAS "PSGetImageReferenceForValue" ( _
   BYREF propkey AS PROPERTYKEY _                       ' __in REFPROPERTYKEY propkey
 , BYREF propvar AS PROPVARIANT _                       ' __in REFPROPVARIANT propvar
 , BYREF ppszImageRes AS DWORD _                        ' __out PWSTR *ppszImageRes
 ) AS LONG                                              ' HRESULT

%PKEY_PIDSTR_MAX    = 10  ' // will take care of any long integer value
%GUIDSTRING_MAX     = (1 + 8 + 1 + 4 + 1 + 4 + 1 + 4 + 1 + 12 + 1 + 1)  ' // "{12345678-1234-1234-1234-123456789012}"
%PKEYSTR_MAX        = (%GUIDSTRING_MAX + 1 + %PKEY_PIDSTR_MAX)

'// Convert a PROPERTYKEY to and from a PWSTR
DECLARE FUNCTION PSStringFromPropertyKey IMPORT "PROPSYS.DLL" ALIAS "PSStringFromPropertyKey" ( _
   BYREF pkey AS PROPERTYKEY _                          ' __in  REFPROPERTYKEY pkey
 , BYREF psz AS WSTRINGZ _                              ' __out LPWSTR psz
 , BYVAL cch AS DWORD _                                 ' __in  UINT cch
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyKeyFromString IMPORT "PROPSYS.DLL" ALIAS "PSPropertyKeyFromString" ( _
   BYREF pszString AS WSTRINGZ _                        ' __in  LPCWSTR pszString
 , BYREF pkey AS PROPERTYKEY _                          ' __out PROPERTYKEY *pkey
 ) AS LONG                                              ' HRESULT

'// Creates an in-memory property store
'// Returns an IPropertyStore, IPersistSerializedPropStorage, and related interfaces interface
DECLARE FUNCTION PSCreateMemoryPropertyStore IMPORT "PROPSYS.DLL" ALIAS "PSCreateMemoryPropertyStore" ( _
   BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

'// Create a read-only, delay-bind multiplexing property store
'// Returns an IPropertyStore interface or related interfaces
DECLARE FUNCTION PSCreateDelayedMultiplexPropertyStore IMPORT "PROPSYS.DLL" ALIAS "PSCreateDelayedMultiplexPropertyStore" ( _
   BYVAL flags AS LONG _                                ' __in  GETPROPERTYSTOREFLAGS flags
 , BYVAL pdpsf AS IDelayedPropertyStoreFactory _        ' __in  IDelayedPropertyStoreFactory *pdpsf
 , BYREF rgStoreIds AS DWORD _                          ' __in  const DWORD *rgStoreIds
 , BYVAL cStores AS DWORD _                             ' __in  DWORD cStores
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

'// Create a read-only property store from one or more sources (which each must support either IPropertyStore or IPropertySetStorage)
'// Returns an IPropertyStore interface or related interfaces
DECLARE FUNCTION PSCreateMultiplexPropertyStore IMPORT "PROPSYS.DLL" ALIAS "PSCreateMultiplexPropertyStore" ( _
   BYVAL prgpunkStores AS IUnknown _                    ' __in  IUnknown **prgpunkStores
 , BYVAL cStores AS DWORD _                             ' __in  DWORD cStores
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

'// Create a container for IPropertyChanges
'// Returns an IPropertyChangeArray interface
DECLARE FUNCTION PSCreatePropertyChangeArray IMPORT "PROPSYS.DLL" ALIAS "PSCreatePropertyChangeArray" ( _
   BYREF rgpropkey AS PROPERTYKEY _                     ' __in  const PROPERTYKEY *rgpropkey
 , BYREF rgflags AS LONG _                              ' __in  const PKA_FLAGS *rgflags
 , BYREF rgpropvar AS ANY _                             ' __in  const PROPVARIANT *rgpropvar
 , BYVAL cChanges AS DWORD _                            ' __in  UINT cChanges
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

'// Create a simple property change
'// Returns an IPropertyChange interface
DECLARE FUNCTION PSCreateSimplePropertyChange IMPORT "PROPSYS.DLL" ALIAS "PSCreateSimplePropertyChange" ( _
   BYVAL flags AS LONG _                                ' __in  PKA_FLAGS flags
 , BYREF key AS PROPERTYKEY _                           ' __in  REFPROPERTYKEY key
 , BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

'// Get a property description
'// Returns an IPropertyDescription interface
DECLARE FUNCTION PSGetPropertyDescription IMPORT "PROPSYS.DLL" ALIAS "PSGetPropertyDescription" ( _
   BYREF propkey AS PROPERTYKEY _                       ' __in  REFPROPERTYKEY propkey
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSGetPropertyDescriptionByName IMPORT "PROPSYS.DLL" ALIAS "PSGetPropertyDescriptionByName" ( _
   BYREF pszCanonicalName AS WSTRINGZ _                 ' __in  LPCWSTR pszCanonicalName
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

'// Lookup a per-machine registered file property handler
DECLARE FUNCTION PSLookupPropertyHandlerCLSID IMPORT "PROPSYS.DLL" ALIAS "PSLookupPropertyHandlerCLSID" ( _
   BYREF pszFilePath AS WSTRINGZ _                      ' __in  PCWSTR pszFilePath
 , BYREF pclsid AS GUID _                               ' __out CLSID *pclsid
 ) AS LONG                                              ' HRESULT

'// Get a property handler, on Vista or downlevel to XP
'// punkItem is a shell item created with an SHCreateItemXXX API
'// Returns an IPropertyStore
DECLARE FUNCTION PSGetItemPropertyHandler IMPORT "PROPSYS.DLL" ALIAS "PSGetItemPropertyHandler" ( _
   BYVAL punkItem AS IUnknown _                         ' __in  IUnknown *punkItem
 , BYVAL fReadWrite AS LONG _                           ' __in  BOOL fReadWrite
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

'// Get a property handler, on Vista or downlevel to XP
'// punkItem is a shell item created with an SHCreateItemXXX API
'// punkCreateObject supports ICreateObject
'// Returns an IPropertyStore
DECLARE FUNCTION PSGetItemPropertyHandlerWithCreateObject IMPORT "PROPSYS.DLL" ALIAS "PSGetItemPropertyHandlerWithCreateObject" ( _
   BYVAL punkItem AS IUnknown _                         ' __in  IUnknown *punkItem
 , BYVAL fReadWrite AS LONG _                           ' __in  BOOL fReadWrite
 , BYVAL punkCreateObject AS IUnknown _                 ' __in  IUnknown *punkCreateObject
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

'// Get or set a property value from a store
DECLARE FUNCTION PSGetPropertyValue IMPORT "PROPSYS.DLL" ALIAS "PSGetPropertyValue" ( _
   BYVAL pps AS IPropertyStore _                        ' __in  IPropertyStore *pps
 , BYVAL ppd AS IPropertyDescription _                  ' __in  IPropertyDescription *ppd
 , BYREF ppropvar AS ANY _                              ' __out PROPVARIANT *ppropvar
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSSetPropertyValue IMPORT "PROPSYS.DLL" ALIAS "PSSetPropertyValue" ( _
   BYVAL pps AS IPropertyStore _                        ' __in IPropertyStore *pps
 , BYVAL ppd AS IPropertyDescription _                  ' __in IPropertyDescription *ppd
 , BYREF propvar AS ANY _                               ' __in REFPROPVARIANT propvar
 ) AS LONG                                              ' HRESULT

'// Interact with the set of property descriptions
DECLARE FUNCTION PSRegisterPropertySchema IMPORT "PROPSYS.DLL" ALIAS "PSRegisterPropertySchema" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in PCWSTR pszPath
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSUnregisterPropertySchema IMPORT "PROPSYS.DLL" ALIAS "PSUnregisterPropertySchema" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in PCWSTR pszPath
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSRefreshPropertySchema IMPORT "PROPSYS.DLL" ALIAS "PSRefreshPropertySchema" ( _
 ) AS LONG                                              ' HRESULT

'// Returns either: IPropertyDescriptionList or IEnumUnknown interfaces
DECLARE FUNCTION PSEnumeratePropertyDescriptions IMPORT "PROPSYS.DLL" ALIAS "PSEnumeratePropertyDescriptions" ( _
   BYVAL filterOn AS LONG _                             ' __in  PROPDESC_ENUMFILTER filterOn
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

'// Convert between a PROPERTYKEY and its canonical name
DECLARE FUNCTION PSGetPropertyKeyFromName IMPORT "PROPSYS.DLL" ALIAS "PSGetPropertyKeyFromName" ( _
   BYREF pszName AS WSTRINGZ _                          ' __in  PCWSTR pszName
 , BYREF ppropkey AS PROPERTYKEY _                      ' __out PROPERTYKEY *ppropkey
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSGetNameFromPropertyKey IMPORT "PROPSYS.DLL" ALIAS "PSGetNameFromPropertyKey" ( _
   BYREF propkey AS PROPERTYKEY _                       ' __in  REFPROPERTYKEY propkey
 , BYREF ppszCanonicalName AS DWORD _                   ' __out PWSTR *ppszCanonicalName
 ) AS LONG                                              ' HRESULT

'// Coerce and canonicalize a property value
DECLARE FUNCTION PSCoerceToCanonicalValue IMPORT "PROPSYS.DLL" ALIAS "PSCoerceToCanonicalValue" ( _
   BYREF key AS PROPERTYKEY _                           ' __in    REFPROPERTYKEY key
 , BYREF ppropvar AS ANY _                              ' __inout PROPVARIANT *ppropvar
 ) AS LONG                                              ' HRESULT

'// Convert a 'prop:' string into a list of property descriptions
'// Returns an IPropertyDescriptionList interface
DECLARE FUNCTION PSGetPropertyDescriptionListFromString IMPORT "PROPSYS.DLL" ALIAS "PSGetPropertyDescriptionListFromString" ( _
   BYREF pszPropList AS WSTRINGZ _                      ' __in  LPCWSTR pszPropList
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

'// Wrap an IPropertySetStorage interface in an IPropertyStore interface
'// Returns an IPropertyStore or related interface
DECLARE FUNCTION PSCreatePropertyStoreFromPropertySetStorage IMPORT "PROPSYS.DLL" ALIAS "PSCreatePropertyStoreFromPropertySetStorage" ( _
   BYVAL ppss AS IPropertySetStorage _                  ' __in  IPropertySetStorage *ppss
 , BYVAL grfMode AS DWORD _                             ' __in  DWORD grfMode
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

'// punkSource must support IPropertyStore or IPropertySetStorage
'// On success, the returned ppv is guaranteed to support IPropertyStore.
'// If punkSource already supports IPropertyStore, no wrapper is created.
DECLARE FUNCTION PSCreatePropertyStoreFromObject IMPORT "PROPSYS.DLL" ALIAS "PSCreatePropertyStoreFromObject" ( _
   BYVAL punk AS IUnknown _                             ' __in  IUnknown *punk
 , BYVAL grfMode AS DWORD _                             ' __in  DWORD grfMode
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

'// punkSource must support IPropertyStore
'// riid may be IPropertyStore, IPropertySetStorage, IPropertyStoreCapabilities, or IObjectProvider
DECLARE FUNCTION PSCreateAdapterFromPropertyStore IMPORT "PROPSYS.DLL" ALIAS "PSCreateAdapterFromPropertyStore" ( _
   BYVAL pps AS IPropertyStore _                        ' __in  IPropertyStore *pps
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

'// Talk to the property system using an interface
'// Returns an IPropertySystem interface
DECLARE FUNCTION PSGetPropertySystem IMPORT "PROPSYS.DLL" ALIAS "PSGetPropertySystem" ( _
   BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

'// Obtain a value from serialized property storage
DECLARE FUNCTION PSGetPropertyFromPropertyStorage IMPORT "PROPSYS.DLL" ALIAS "PSGetPropertyFromPropertyStorage" ( _
   BYVAL psps AS BYTE PTR _                             ' __in  PCUSERIALIZEDPROPSTORAGE psps
 , BYVAL cb AS DWORD _                                  ' __in  DWORD cb
 , BYREF rpkey AS PROPERTYKEY _                         ' __in  REFPROPERTYKEY rpkey
 , BYREF ppropvar AS ANY _                              ' __out PROPVARIANT *ppropvar
 ) AS LONG                                              ' HRESULT

'// Obtain a named value from serialized property storage
DECLARE FUNCTION PSGetNamedPropertyFromPropertyStorage IMPORT "PROPSYS.DLL" ALIAS "PSGetNamedPropertyFromPropertyStorage" ( _
   BYVAL psps AS BYTE PTR _                             ' __in  PCUSERIALIZEDPROPSTORAGE psps
 , BYVAL cb AS DWORD _                                  ' __in  DWORD cb
 , BYREF pszName AS WSTRINGZ _                          ' __in  LPCWSTR pszName
 , BYREF ppropvar AS ANY _                              ' __out PROPVARIANT *ppropvar
 ) AS LONG                                              ' HRESULT

'// Helper functions for reading and writing values from IPropertyBag's.
DECLARE FUNCTION PSPropertyBag_ReadType IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_ReadType" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYREF var AS VARIANT _                               ' __out VARIANT *var
 , BYVAL type AS WORD _                                 ' __in VARTYPE type
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_ReadStr IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_ReadStr" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYREF value AS WSTRINGZ _                            ' __out LPWSTR value
 , BYVAL characterCount AS LONG _                       ' __in int characterCount
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_ReadStrAlloc IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_ReadStrAlloc" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYREF value AS DWORD _                               ' __out PWSTR *value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_ReadBSTR IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_ReadBSTR" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYREF value AS WSTRING _                             ' __out BSTR *value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_WriteStr IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_WriteStr" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYREF value AS WSTRINGZ _                            ' __in LPCWSTR value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_WriteBSTR IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_WriteBSTR" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYVAL value AS WSTRING _                             ' __in BSTR value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_ReadInt IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_ReadInt" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYREF value AS LONG _                                ' __out INT *value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_WriteInt IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_WriteInt" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYVAL value AS LONG _                                ' __in INT value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_ReadSHORT IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_ReadSHORT" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYREF value AS INTEGER _                             ' __out SHORT *value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_WriteSHORT IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_WriteSHORT" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYVAL value AS INTEGER _                             ' __in SHORT value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_ReadLONG IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_ReadLONG" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYREF value AS LONG _                                ' __out LONG *value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_WriteLONG IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_WriteLONG" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYVAL value AS LONG _                                ' __in LONG value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_ReadDWORD IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_ReadDWORD" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYREF value AS DWORD _                               ' __out DWORD *value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_WriteDWORD IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_WriteDWORD" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYVAL value AS DWORD _                               ' __in DWORD value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_ReadBOOL IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_ReadBOOL" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYREF value AS LONG _                                ' __out BOOL *value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_WriteBOOL IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_WriteBOOL" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYVAL value AS LONG _                                ' __in BOOL value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_ReadPOINTL IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_ReadPOINTL" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYREF value AS POINTL _                              ' __out POINTL *value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_WritePOINTL IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_WritePOINTL" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYREF value AS POINTL _                              ' __in const POINTL *value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_ReadPOINTS IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_ReadPOINTS" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYREF value AS POINTS _                              ' __out POINTS *value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_WritePOINTS IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_WritePOINTS" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYREF value AS POINTS _                              ' __in const POINTS *value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_ReadRECTL IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_ReadRECTL" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYREF value AS RECTL _                               ' __out RECTL *value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_WriteRECTL IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_WriteRECTL" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYREF value AS RECTL _                               ' __in const RECTL *value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_ReadStream IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_ReadStream" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYREF value AS IStream _                             ' __out IStream **value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_WriteStream IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_WriteStream" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYVAL value AS IStream _                             ' __in IStream *value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_Delete IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_Delete" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_ReadULONGLONG IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_ReadULONGLONG" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYREF value AS QUAD _                                ' __out ULONGLONG *value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_WriteULONGLONG IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_WriteULONGLONG" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYVAL value AS QUAD _                                ' __in ULONGLONG value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_ReadUnknown IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_ReadUnknown" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_WriteUnknown IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_WriteUnknown" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYVAL punk AS IUnknown _                             ' __in IUnknown *punk
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_ReadGUID IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_ReadGUID" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYREF value AS GUID _                                ' __out GUID *value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_WriteGUID IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_WriteGUID" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYREF value AS GUID _                                ' __in const GUID *value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_ReadPropertyKey IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_ReadPropertyKey" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYREF value AS PROPERTYKEY _                         ' __out PROPERTYKEY *value
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PSPropertyBag_WritePropertyKey IMPORT "PROPSYS.DLL" ALIAS "PSPropertyBag_WritePropertyKey" ( _
   BYVAL propBag AS IPropertyBag _                      ' __in IPropertyBag *propBag
 , BYREF propName AS WSTRINGZ _                         ' __in LPCWSTR propName
 , BYREF value AS PROPERTYKEY _                         ' __in REFPROPERTYKEY value
 ) AS LONG                                              ' HRESULT
