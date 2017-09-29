' ########################################################################################
' Microsoft Windows
' File: wcmconfig.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WCMCONFIG_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

$CLSID_SettingsEngine = GUID$("{9F7D7BB5-20B3-11DA-81A5-0030F1642E3C}")

' enum WcmTargetMode
%OfflineMode = 1
%OnlineMode  = 2

' enum WcmNamespaceEnumerationFlags
%SharedEnumeration = 1
%UserEnumeration   = 2
%AllEnumeration    = %SharedEnumeration OR %UserEnumeration

' enum WcmDataType
%dataTypeByte      = 1
%dataTypeSByte     = 2
%dataTypeUInt16    = 3
%dataTypeInt16     = 4
%dataTypeUInt32    = 5
%dataTypeInt32     = 6
%dataTypeUInt64    = 7
%dataTypeInt64     = 8
%dataTypeBoolean   = 11
%dataTypeString    = 12
%dataTypeFlagArray = &H8000&

' enum WcmSettingType
%settingTypeScalar  = 1
%settingTypeComplex = 2
%settingTypeList    = 3

' enum WcmRestrictionFacets
%restrictionFacetMaxLength    = &H1
%restrictionFacetEnumeration  = &H2
%restrictionFacetMaxInclusive = &H4
%restrictionFacetMinInclusive = &H8

' enum WcmUserStatus
%UnknownStatus    = 0
%UserRegistered   = 1
%UserUnregistered = 2
%UserLoaded       = 3
%UserUnloaded     = 4

' enum WcmNamespaceAccess
%ReadOnlyAccess  = 1
%ReadWriteAccess = 2


' ########################################################################################
' Interface name = IItemEnumerator
' IID = 9F7D7BB7-20B3-11DA-81A5-0030F1642E3C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IItemEnumerator_INTERFACE_DEFINED)
    %IItemEnumerator_INTERFACE_DEFINED = 1

$IID_IItemEnumerator = GUID$("{9F7D7BB7-20B3-11DA-81A5-0030F1642E3C}")

INTERFACE IItemEnumerator $IID_IItemEnumerator

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Current ( _                                   ' VTable offset = 12
   ) AS VARIANT                                         ' __retval_out VARIANT *Item
   ' =====================================================================================
   METHOD MoveNext ( _                                  ' VTable offset = 16
   ) AS LONG                                            ' __retval_out BOOL *ItemValid
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IItemEnumerator_INTERFACE_DEFINED__ */

$$WCM_SETTINGS_ID_NAME            = "name"$$
$$WCM_SETTINGS_ID_VERSION         = "version"$$
$$WCM_SETTINGS_ID_LANGUAGE        = "language"$$
$$WCM_SETTINGS_ID_ARCHITECTURE    = "architecture"$$
$$WCM_SETTINGS_ID_TOKEN           = "token"$$
$$WCM_SETTINGS_ID_URI             = "uri"$$
$$WCM_SETTINGS_ID_VERSION_SCOPE   = "versionScope"$$

%WCM_SETTINGS_ID_FLAG_REFERENCE  = &H00000000
%WCM_SETTINGS_ID_FLAG_DEFINITION = &H00000001


' ########################################################################################
' Interface name = ISettingsIdentity
' IID = 9F7D7BB6-20B3-11DA-81A5-0030F1642E3C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISettingsIdentity_INTERFACE_DEFINED)
    %ISettingsIdentity_INTERFACE_DEFINED = 1

$IID_ISettingsIdentity = GUID$("{9F7D7BB6-20B3-11DA-81A5-0030F1642E3C}")

INTERFACE ISettingsIdentity $IID_ISettingsIdentity

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetAttribute ( _                              ' VTable offset = 12
     BYVAL Reserved AS DWORD _                          ' __in void *Reserved
   , BYREF Name AS WSTRINGZ _                           ' __in const WCHAR *Name
   ) AS WSTRING                                         ' __retval_out BSTR *Value
   ' =====================================================================================
   METHOD SetAttribute ( _                              ' VTable offset = 16
     BYVAL Reserved AS DWORD _                          ' __in void *Reserved
   , BYREF Name AS WSTRINGZ _                           ' __in const WCHAR *Name
   , BYREF Value AS WSTRINGZ _                          ' __in const WCHAR *Value
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 20
   ) AS DWORD                                           ' __retval_out DWORD *Flags
   ' =====================================================================================
   METHOD SetFlags ( _                                  ' VTable offset = 24
     BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISettingsIdentity_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITargetInfo
' IID = 9F7D7BB8-20B3-11DA-81A5-0030F1642E3C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITargetInfo_INTERFACE_DEFINED)
    %ITargetInfo_INTERFACE_DEFINED = 1

$IID_ITargetInfo = GUID$("{9F7D7BB8-20B3-11DA-81A5-0030F1642E3C}")

INTERFACE ITargetInfo $IID_ITargetInfo

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetTargetMode ( _                             ' VTable offset = 12
   ) AS LONG                                            ' __retval_out WcmTargetMode *TargetMode
   ' =====================================================================================
   METHOD SetTargetMode ( _                             ' VTable offset = 16
     BYVAL TargetMode AS LONG _                         ' __in WcmTargetMode TargetMode
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTemporaryStoreLocation ( _                 ' VTable offset = 20
   ) AS WSTRING                                         ' __retval_out BSTR *TemporaryStoreLocation
   ' =====================================================================================
   METHOD SetTemporaryStoreLocation ( _                 ' VTable offset = 24
     BYREF TemporaryStoreLocation AS WSTRINGZ _         ' __in const WCHAR *TemporaryStoreLocation
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTargetID ( _                               ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *TargetID
   ' =====================================================================================
   METHOD SetTargetID ( _                               ' VTable offset = 32
     BYVAL TargetID AS GUID _                           ' __in GUID TargetID
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTargetProcessorArchitecture ( _            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *ProcessorArchitecture
   ' =====================================================================================
   METHOD SetTargetProcessorArchitecture ( _            ' VTable offset = 40
     BYREF ProcessorArchitecture AS WSTRINGZ _          ' __in const WCHAR *ProcessorArchitecture
   )                                                    ' void
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 44
     BYVAL Offline AS LONG _                            ' __in BOOL Offline
   , BYREF Property AS WSTRINGZ _                       ' __in const WCHAR *Property
   ) AS WSTRING                                         ' __retval_out BSTR *Value
   ' =====================================================================================
   METHOD SetProperty ( _                               ' VTable offset = 48
     BYVAL Offline AS LONG _                            ' __in BOOL Offline
   , BYREF Property AS WSTRINGZ _                       ' __in const WCHAR *Property
   , BYREF Value AS WSTRINGZ _                          ' __in const WCHAR *Value
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEnumerator ( _                             ' VTable offset = 52
   ) AS IItemEnumerator                                 ' __retval_out IItemEnumerator **Enumerator
   ' =====================================================================================
   METHOD ExpandTarget ( _                              ' VTable offset = 56
     BYVAL Offline AS LONG _                            ' __in BOOL Offline
   , BYREF Location AS WSTRINGZ _                       ' __in const WCHAR *Location
   ) AS WSTRING                                         ' __retval_out BSTR *ExpandedLocation
   ' =====================================================================================
   METHOD ExpandTargetPath ( _                          ' VTable offset = 60
     BYVAL Offline AS LONG _                            ' __in BOOL Offline
   , BYREF Location AS WSTRINGZ _                       ' __in const WCHAR *Location
   ) AS WSTRING                                         ' __retval_out BSTR *ExpandedLocation
   ' =====================================================================================
   METHOD SetModulePath ( _                             ' VTable offset = 64
     BYREF Module AS WSTRINGZ _                         ' __in const WCHAR *Module
   , BYREF Path AS WSTRINGZ _                           ' __in const WCHAR *Path
   )                                                    ' void
   ' =====================================================================================
   METHOD LoadModule ( _                                ' VTable offset = 68
     BYREF Module AS WSTRINGZ _                         ' __in const WCHAR *Module
   ) AS DWORD                                           ' __retval_out HMODULE *ModuleHandle
   ' =====================================================================================
   METHOD SetWow64Context ( _                           ' VTable offset = 72
     BYREF InstallerModule AS WSTRINGZ _                ' __in const WCHAR *InstallerModule
   , BYVAL Wow64Context AS BYTE PTR _                   ' __in BYTE *Wow64Context
   )                                                    ' void
   ' =====================================================================================
   METHOD TranslateWow64 ( _                            ' VTable offset = 76
     BYREF ClientArchitecture AS WSTRINGZ _             ' __in const WCHAR *ClientArchitecture
   , BYREF Value AS WSTRINGZ _                          ' __in const WCHAR *Value
   ) AS WSTRING                                         ' __retval_out BSTR *TranslatedValue
   ' =====================================================================================
   METHOD SetSchemaHiveLocation ( _                     ' VTable offset = 80
     BYREF pwzHiveDir AS WSTRINGZ _                     ' __in LPCWSTR pwzHiveDir
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSchemaHiveLocation ( _                     ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pHiveLocation
   ' =====================================================================================
   METHOD SetSchemaHiveMountName ( _                    ' VTable offset = 88
     BYREF pwzMountName AS WSTRINGZ _                   ' __in LPCWSTR pwzMountName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSchemaHiveMountName ( _                    ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *pMountName
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITargetInfo_INTERFACE_DEFINED__ */


%LINK_STORE_TO_ENGINE_INSTANCE = &H00000001


' ########################################################################################
' Interface name = ISettingsEngine
' IID = 9F7D7BB9-20B3-11DA-81A5-0030F1642E3C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISettingsEngine_INTERFACE_DEFINED)
    %ISettingsEngine_INTERFACE_DEFINED = 1

$IID_ISettingsEngine = GUID$("{9F7D7BB9-20B3-11DA-81A5-0030F1642E3C}")

INTERFACE ISettingsEngine $IID_ISettingsEngine

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetNamespaces ( _                             ' VTable offset = 12
     BYVAL Flags AS LONG _                              ' __in WcmNamespaceEnumerationFlags Flags
   , BYVAL Reserved AS DWORD _                          ' __in void *Reserved
   ) AS IItemEnumerator                                 ' __retval_out IItemEnumerator **Namespaces
   ' =====================================================================================
   METHOD GetNamespace ( _                              ' VTable offset = 16
     BYVAL SettingsID AS ISettingsIdentity _            ' __in ISettingsIdentity *SettingsID
   , BYVAL Access AS LONG _                             ' __in WcmNamespaceAccess Access
   , BYVAL Reserved AS DWORD _                          ' __in void *Reserved
   ) AS ISettingsNamespace                              ' __retval_out ISettingsNamespace **NamespaceItem
   ' =====================================================================================
   METHOD GetErrorDescription ( _                       ' VTable offset = 20
     BYVAL HResult AS LONG _                            ' __in LONG HResult
   ) AS WSTRING                                         ' __retval_out BSTR *Message
   ' =====================================================================================
   METHOD CreateSettingsIdentity ( _                    ' VTable offset = 24
   ) AS ISettingsIdentity                               ' __retval_out ISettingsIdentity **SettingsID
   ' =====================================================================================
   METHOD GetStoreStatus ( _                            ' VTable offset = 28
     BYVAL Reserved AS DWORD _                          ' __in void *Reserved
   ) AS LONG                                            ' __out WcmUserStatus *Status
   ' =====================================================================================
   METHOD LoadStore ( _                                 ' VTable offset = 32
     BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   )                                                    ' void
   ' =====================================================================================
   METHOD UnloadStore ( _                               ' VTable offset = 36
     BYVAL Reserved AS DWORD _                          ' __in void *Reserved
   )                                                    ' void
   ' =====================================================================================
   METHOD RegisterNamespace ( _                         ' VTable offset = 40
     BYVAL SettingsID AS ISettingsIdentity _            ' __in ISettingsIdentity *SettingsID
   , BYVAL Stream AS IStream _                          ' __in IStream *Stream
   , BYVAL PushSettings AS LONG _                       ' __in BOOL PushSettings
   ) AS VARIANT                                         ' __retval_out VARIANT *Results
   ' =====================================================================================
   METHOD UnregisterNamespace ( _                       ' VTable offset = 44
     BYVAL SettingsID AS ISettingsIdentity _            ' __in ISettingsIdentity *SettingsID
   , BYVAL RemoveSettings AS LONG _                     ' __in BOOL RemoveSettings
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateTargetInfo ( _                          ' VTable offset = 48
   ) AS ITargetInfo                                     ' __retval_out ITargetInfo **Target
   ' =====================================================================================
   METHOD GetTargetInfo ( _                             ' VTable offset = 52
   ) AS ITargetInfo                                     ' __retval_out ITargetInfo **Target
   ' =====================================================================================
   METHOD SetTargetInfo ( _                             ' VTable offset = 56
     BYVAL Target AS ITargetInfo _                      ' __in ITargetInfo *Target
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateSettingsContext ( _                     ' VTable offset = 60
     BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   , BYVAL Reserved AS DWORD _                          ' __in void *Reserved
   ) AS ISettingsContext                                ' __retval_out ISettingsContext **SettingsContext
   ' =====================================================================================
   METHOD SetSettingsContext ( _                        ' VTable offset = 64
     BYVAL SettingsContext AS ISettingsContext _        ' __in ISettingsContext *SettingsContext
   )                                                    ' void
   ' =====================================================================================
   METHOD ApplySettingsContext ( _                      ' VTable offset = 68
     BYVAL SettingsContext AS ISettingsContext _        ' __in ISettingsContext *SettingsContext
   , BYREF pppwzIdentities AS DWORD _                   ' __out LPWSTR **pppwzIdentities
   ) AS DWORD                                           ' __retval_out SIZE_T *pcIdentities
   ' =====================================================================================
   METHOD GetSettingsContext ( _                        ' VTable offset = 72
   ) AS ISettingsContext                                ' __retval_out ISettingsContext **SettingsContext
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISettingsEngine_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISettingsItem
' IID = 9F7D7BBB-20B3-11DA-81A5-0030F1642E3C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISettingsItem_INTERFACE_DEFINED)
    %ISettingsItem_INTERFACE_DEFINED = 1

$IID_ISettingsItem = GUID$("{9F7D7BBB-20B3-11DA-81A5-0030F1642E3C}")

INTERFACE ISettingsItem $IID_ISettingsItem

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 16
   ) AS VARIANT                                         ' __retval_out VARIANT *Value
   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 20
     BYREF Value AS VARIANT _                           ' __in const VARIANT *Value
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSettingType ( _                            ' VTable offset = 24
   ) AS LONG                                            ' __retval_out WcmSettingType *Type
   ' =====================================================================================
   METHOD GetDataType ( _                               ' VTable offset = 28
   ) AS LONG                                            ' __retval_out WcmDataType *Type
   ' =====================================================================================
   METHOD GetValueRaw ( _                               ' VTable offset = 32
     BYREF Data AS DWORD _                              ' __out BYTE **Data
   ) AS DWORD                                           ' __retval_out ULONG *DataSize
   ' =====================================================================================
   METHOD SetValueRaw ( _                               ' VTable offset = 36
     BYVAL DataType AS LONG _                           ' __in LONG DataType
   , BYVAL Data AS BYTE PTR _                           ' __in const BYTE *Data
   , BYVAL DataSize AS DWORD _                          ' __in ULONG DataSize
   )                                                    ' void
   ' =====================================================================================
   METHOD HasChild ( _                                  ' VTable offset = 40
   ) AS LONG                                            ' __retval_out BOOL *ItemHasChild
   ' =====================================================================================
   METHOD Children ( _                                  ' VTable offset = 44
   ) AS IItemEnumerator                                 ' __retval_out IItemEnumerator **Children
   ' =====================================================================================
   METHOD GetChild ( _                                  ' VTable offset = 48
     BYREF Name AS WSTRINGZ _                           ' __in const WCHAR *Name
   ) AS ISettingsItem                                   ' __retval_out ISettingsItem **Child
   ' =====================================================================================
   METHOD GetSettingByPath ( _                          ' VTable offset = 52
     BYREF Path AS WSTRINGZ _                           ' __in const WCHAR *Path
   ) AS ISettingsItem                                   ' __retval_out ISettingsItem **Setting
   ' =====================================================================================
   METHOD CreateSettingByPath ( _                       ' VTable offset = 56
     BYREF Path AS WSTRINGZ _                           ' __in const WCHAR *Path
   ) AS ISettingsItem                                   ' __retval_out ISettingsItem **Setting
   ' =====================================================================================
   METHOD RemoveSettingByPath ( _                       ' VTable offset = 60
     BYREF Path AS WSTRINGZ _                           ' __in const WCHAR *Path
   )                                                    ' void
   ' =====================================================================================
   METHOD GetListKeyInformation ( _                     ' VTable offset = 64
     BYREF KeyName AS WSTRING _                         ' __out BSTR *KeyName
   ) AS LONG                                            ' __retval_out WcmDataType *DataType
   ' =====================================================================================
   METHOD CreateListElement ( _                         ' VTable offset = 68
     BYREF KeyData AS VARIANT _                         ' __in const VARIANT *KeyData
   ) AS ISettingsItem                                   ' __retval_out ISettingsItem **Child
   ' =====================================================================================
   METHOD RemoveListElement ( _                         ' VTable offset = 72
     BYREF ElementName AS WSTRINGZ _                    ' __in LPCWSTR ElementName
   )                                                    ' void
   ' =====================================================================================
   METHOD Attributes ( _                                ' VTable offset = 76
   ) AS IItemEnumerator                                 ' __retval_out IItemEnumerator **Attributes
   ' =====================================================================================
   METHOD GetAttribute ( _                              ' VTable offset = 80
     BYREF Name AS WSTRINGZ _                           ' __in const WCHAR *Name
   ) AS VARIANT                                         ' __retval_out VARIANT *Value
   ' =====================================================================================
   METHOD GetPath ( _                                   ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *Path
   ' =====================================================================================
   METHOD GetRestrictionFacets ( _                      ' VTable offset = 88
   ) AS LONG                                            ' __retval_out WcmRestrictionFacets *RestrictionFacets
   ' =====================================================================================
   METHOD GetRestriction ( _                            ' VTable offset = 92
     BYVAL RestrictionFacet AS LONG _                   ' __in WcmRestrictionFacets RestrictionFacet
   ) AS VARIANT                                         ' __retval_out VARIANT *FacetData
   ' =====================================================================================
   METHOD GetKeyValue ( _                               ' VTable offset = 96
   ) AS VARIANT                                         ' __retval_out VARIANT *Value
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISettingsItem_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISettingsNamespace
' IID = 9F7D7BBA-20B3-11DA-81A5-0030F1642E3C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISettingsNamespace_INTERFACE_DEFINED)
    %ISettingsNamespace_INTERFACE_DEFINED = 1

$IID_ISettingsNamespace = GUID$("{9F7D7BBA-20B3-11DA-81A5-0030F1642E3C}")

INTERFACE ISettingsNamespace $IID_ISettingsNamespace

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetIdentity ( _                               ' VTable offset = 12
   ) AS ISettingsIdentity                               ' __retval_out ISettingsIdentity **SettingsID
   ' =====================================================================================
   METHOD Settings ( _                                  ' VTable offset = 16
   ) AS IItemEnumerator                                 ' __retval_out IItemEnumerator **Settings
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 20
     BYVAL PushSettings AS LONG _                       ' __in BOOL PushSettings
   ) AS ISettingsResult                                 ' __retval_out ISettingsResult **Result
   ' =====================================================================================
   METHOD GetSettingByPath ( _                          ' VTable offset = 24
     BYREF Path AS WSTRINGZ _                           ' __in const WCHAR *Path
   ) AS ISettingsItem                                   ' __retval_out ISettingsItem **Setting
   ' =====================================================================================
   METHOD CreateSettingByPath ( _                       ' VTable offset = 28
     BYREF Path AS WSTRINGZ _                           ' __in const WCHAR *Path
   ) AS ISettingsItem                                   ' __retval_out ISettingsItem **Setting
   ' =====================================================================================
   METHOD RemoveSettingByPath ( _                       ' VTable offset = 32
     BYREF Path AS WSTRINGZ _                           ' __in const WCHAR *Path
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAttribute ( _                              ' VTable offset = 36
     BYREF Name AS WSTRINGZ _                           ' __in const WCHAR *Name
   ) AS VARIANT                                         ' __retval_out VARIANT *Value
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISettingsNamespace_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ISettingsResult
' IID = 9F7D7BBC-20B3-11DA-81A5-0030F1642E3C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISettingsResult_INTERFACE_DEFINED)
    %ISettingsResult_INTERFACE_DEFINED = 1

$IID_ISettingsResult = GUID$("{9F7D7BBC-20B3-11DA-81A5-0030F1642E3C}")

INTERFACE ISettingsResult $IID_ISettingsResult

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetDescription ( _                            ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *description
   ' =====================================================================================
   METHOD GetErrorCode ( _                              ' VTable offset = 16
   ) AS LONG                                            ' __retval_out HRESULT *hrOut
   ' =====================================================================================
   METHOD GetContextDescription ( _                     ' VTable offset = 20
   ) AS WSTRING                                         ' __retval_out BSTR *description
   ' =====================================================================================
   METHOD GetLine ( _                                   ' VTable offset = 24
   ) AS DWORD                                           ' __retval_out DWORD *dwLine
   ' =====================================================================================
   METHOD GetColumn ( _                                 ' VTable offset = 28
   ) AS DWORD                                           ' __retval_out DWORD *dwColumn
   ' =====================================================================================
   METHOD GetSource ( _                                 ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *file
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISettingsResult_INTERFACE_DEFINED__ */


%LIMITED_VALIDATION_MODE = &H00000001


' ########################################################################################
' Interface name = ISettingsContext
' IID = 9F7D7BBD-20B3-11DA-81A5-0030F1642E3C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISettingsContext_INTERFACE_DEFINED)
    %ISettingsContext_INTERFACE_DEFINED = 1

$IID_ISettingsContext = GUID$("{9F7D7BBD-20B3-11DA-81A5-0030F1642E3C}")

INTERFACE ISettingsContext $IID_ISettingsContext

   INHERIT IAutomation

   ' =====================================================================================
   METHOD Serialize ( _                                 ' VTable offset = 12
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   , BYVAL pTarget AS ITargetInfo _                     ' __in ITargetInfo *pTarget
   )                                                    ' void
   ' =====================================================================================
   METHOD Deserialize ( _                               ' VTable offset = 16
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   , BYVAL pTarget AS ITargetInfo _                     ' __in ITargetInfo *pTarget
   , BYREF pppResults AS ISettingsResult _              ' __out ISettingsResult ***pppResults
   ) AS DWORD                                           ' __retval_out SIZE_T *pcResultCount
   ' =====================================================================================
   METHOD SetUserData ( _                               ' VTable offset = 20
     BYVAL pUserData AS DWORD _                         ' __in void *pUserData
   )                                                    ' void
   ' =====================================================================================
   METHOD GetUserData ( _                               ' VTable offset = 24
   ) AS DWORD                                           ' __retval_out void **pUserData
   ' =====================================================================================
   METHOD GetNamespaces ( _                             ' VTable offset = 28
   ) AS IItemEnumerator                                 ' __retval_out IItemEnumerator **ppNamespaceIds
   ' =====================================================================================
   METHOD GetStoredSettings ( _                         ' VTable offset = 32
     BYVAL pIdentity AS ISettingsIdentity _             ' __in ISettingsIdentity *pIdentity
   , BYREF ppAddedSettings AS IItemEnumerator _         ' __out IItemEnumerator **ppAddedSettings
   , BYREF ppModifiedSettings AS IItemEnumerator _      ' __out IItemEnumerator **ppModifiedSettings
   , BYREF ppDeletedSettings AS IItemEnumerator _       ' __out IItemEnumerator **ppDeletedSettings
   )                                                    ' void
   ' =====================================================================================
   METHOD RevertSetting ( _                             ' VTable offset = 36
     BYVAL pIdentity AS ISettingsIdentity _             ' __in ISettingsIdentity *pIdentity
   , BYREF pwzSetting AS WSTRINGZ _                     ' __in LPCWSTR pwzSetting
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISettingsContext_INTERFACE_DEFINED__ */
