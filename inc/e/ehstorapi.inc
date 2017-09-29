' ########################################################################################
' Microsoft Windows
' File: EhStorAPI.inc
' Library name: EnhancedStorageAPILib
' Version: 1.0, Locale ID = 0
' Library GUID: {FF9D683B-B90A-49B4-9649-F93756BAD71F}
' Path: C:\Windows\system32\EhStorAPI.dll
' Contents: EnhancedStorageAPI 1.0 Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%EHSTORAPI_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "propidl.inc"
#INCLUDE ONCE "portabledeviceapi.inc"

$LIBID_EnhancedStorageAPILib = GUID$("{FF9D683B-B90A-49B4-9649-F93756BAD71F}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_EnhancedStorageACT = GUID$("{AF076A15-2ECE-4AD4-BB21-29F040E176D8}")
$CLSID_EnhancedStorageSilo = GUID$("{CB25220C-76C7-4FEE-842B-F3383CD022BC}")
$CLSID_EnhancedStorageSiloAction = GUID$("{886D29DD-B506-466B-9FBF-B44FF383FB3F}")
$CLSID_EnumEnhancedStorageACT = GUID$("{FE841493-835C-4FA3-B6CC-B4B2D4719848}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IEnhancedStorageACT = GUID$("{6E7781F4-E0F2-4239-B976-A01ABAB52930}")
$IID_IEnhancedStorageACT2 = GUID$("{4DA57D2E-8EB3-41F6-A07E-98B52B88242B}")
$IID_IEnhancedStorageSilo = GUID$("{5AEF78C6-2242-4703-BF49-44B29357A359}")
$IID_IEnhancedStorageSiloAction = GUID$("{B6F7F311-206F-4FF8-9C4B-27EFEE77A86F}")
$IID_IEnumEnhancedStorageACT = GUID$("{09B224BD-1335-4631-A7FF-CFD3A92646D7}")

' ========================================================================================
' ACT_AUTHORIZATION_STATE structure
' ========================================================================================

' // Size = 4 bytes
TYPE ACT_AUTHORIZATION_STATE DWORD
   ulState AS DWORD   ' ULONG
END TYPE

' ========================================================================================
' SILO_INFO structure
' ========================================================================================

' // Size = 12 bytes
TYPE SILO_INFO
   ulSTID              AS DWORD   ' ULONG
   SpecificationMajor  AS BYTE    ' UCHAR
   SpecificationMinor  AS BYTE    ' UCHAR
   ImplementationMajor AS BYTE    ' UCHAR
   ImplementationMinor AS BYTE    ' UCHAR
   type                AS BYTE    ' UCHAR
   capabilities        AS BYTE    ' UCHAR
   alignment__         AS WORD    ' // To keep DWORD alignment
END TYPE

' ########################################################################################
' Interface name = IEnumEnhancedStorageACT
' IID = {09B224BD-1335-4631-A7FF-CFD3A92646D7}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumEnhancedStorageACT_INTERFACE_DEFINED)
    %IEnumEnhancedStorageACT_INTERFACE_DEFINED = 1

INTERFACE IEnumEnhancedStorageACT $IID_IEnumEnhancedStorageACT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetACTs ( _                                   ' VTable offset = 12
     BYVAL pppIEnhancedStorageACTs AS IEnhancedStorageACT _ ' __out IEnhancedStorageACT ***pppIEnhancedStorageACTs
   , BYREF pcEnhancedStorageACTs AS DWORD _             ' __out ULONG *pcEnhancedStorageACTs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMatchingACT ( _                            ' VTable offset = 16
     BYREF szVolume AS WSTRINGZ _                       ' __in LPCWSTR szVolume
   , BYREF ppIEnhancedStorageACT AS IEnhancedStorageACT _ ' __out IEnhancedStorageACT **ppIEnhancedStorageACT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumEnhancedStorageACT_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnhancedStorageACT
' IID = {6E7781F4-E0F2-4239-B976-A01ABAB52930}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnhancedStorageACT_INTERFACE_DEFINED)
    %IEnhancedStorageACT_INTERFACE_DEFINED = 1

INTERFACE IEnhancedStorageACT $IID_IEnhancedStorageACT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Authorize ( _                                 ' VTable offset = 12
     BYVAL hwndParent AS DWORD _                        ' __in DWORD hwndParent
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unauthorize ( _                               ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAuthorizationState ( _                     ' VTable offset = 20
     BYREF pState AS ACT_AUTHORIZATION_STATE _          ' __out ACT_AUTHORIZATION_STATE *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMatchingVolume ( _                         ' VTable offset = 24
     BYREF ppwszVolume AS DWORD _                       ' __out LPWSTR *ppwszVolume
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUniqueIdentity ( _                         ' VTable offset = 28
     BYREF ppwszIdentity AS DWORD _                     ' __out LPWSTR *ppwszIdentity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSilos ( _                                  ' VTable offset = 32
     BYVAL pppIEnhancedStorageSilos AS IEnhancedStorageSilo _ ' __out IEnhancedStorageSilo ***pppIEnhancedStorageSilos
   , BYREF pcEnhancedStorageSilos AS DWORD _            ' __out ULONG *pcEnhancedStorageSilos
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnhancedStorageACT_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnhancedStorageACT2
' IID = {4DA57D2E-8EB3-41F6-A07E-98B52B88242B}
' Inherited interface = IEnhancedStorageACT
' ########################################################################################

#IF NOT %DEF(%IEnhancedStorageACT2_INTERFACE_DEFINED)
    %IEnhancedStorageACT2_INTERFACE_DEFINED = 1

INTERFACE IEnhancedStorageACT2 $IID_IEnhancedStorageACT2

   INHERIT IUnknown

   ' =====================================================================================
   ' IEnhancedStorageACT methods
   ' =====================================================================================
   METHOD Authorize ( _                                 ' VTable offset = 12
     BYVAL hwndParent AS DWORD _                        ' __in DWORD hwndParent
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unauthorize ( _                               ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAuthorizationState ( _                     ' VTable offset = 20
     BYREF pState AS ACT_AUTHORIZATION_STATE _          ' __out ACT_AUTHORIZATION_STATE *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMatchingVolume ( _                         ' VTable offset = 24
     BYREF ppwszVolume AS DWORD _                       ' __out LPWSTR *ppwszVolume
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUniqueIdentity ( _                         ' VTable offset = 28
     BYREF ppwszIdentity AS DWORD _                     ' __out LPWSTR *ppwszIdentity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSilos ( _                                  ' VTable offset = 32
     BYVAL pppIEnhancedStorageSilos AS IEnhancedStorageSilo _ ' __out IEnhancedStorageSilo ***pppIEnhancedStorageSilos
   , BYREF pcEnhancedStorageSilos AS DWORD _            ' __out ULONG *pcEnhancedStorageSilos
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IEnhancedStorageACT2 methods
   ' =====================================================================================
   METHOD GetDeviceName ( _                             ' VTable offset = 36
     BYREF ppwszDeviceName AS DWORD _                   ' __out LPWSTR *ppwszDeviceName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDeviceRemovable ( _                         ' VTable offset = 40
     BYREF ppwszDeviceName AS LONG _                    ' __out BOOL *pIsDeviceRemovable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnhancedStorageACT2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnhancedStorageSilo
' IID = {5AEF78C6-2242-4703-BF49-44B29357A359}
' IEnhancedStorageSilo Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnhancedStorageSilo_INTERFACE_DEFINED)
    %IEnhancedStorageSilo_INTERFACE_DEFINED = 1

INTERFACE IEnhancedStorageSilo $IID_IEnhancedStorageSilo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetInfo ( _                                   ' VTable offset = 12
     BYREF pSiloInfo AS SILO_INFO _                     ' __out SILO_INFO *pSiloInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActions ( _                                ' VTable offset = 16
     BYVAL pppIEnhancedStorageSiloActions AS IEnhancedStorageSiloAction _ ' __out IEnhancedStorageSiloAction ***pppIEnhancedStorageSiloActions
   , BYREF pcEnhancedStorageSiloActions AS DWORD _      ' __out ULONG *pcEnhancedStorageSiloActions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendCommand ( _                               ' VTable offset = 20
     BYVAL Command AS BYTE _                            ' __in UCHAR Command
   , BYREF pbCommandBuffer AS BYTE _                    ' __in BYTE *pbCommandBuffer
   , BYVAL cbCommandBuffer AS DWORD _                   ' __in ULONG cbCommandBuffer
   , BYREF pbResponseBuffer AS BYTE _                   ' __out BYTE *pbResponseBuffer
   , BYREF pcbResponseBuffer AS DWORD _                 ' __inout ULONG *pcbResponseBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPortableDevice ( _                         ' VTable offset = 24
     BYREF ppIPortableDevice AS IPortableDevice _       ' __out IPortableDevice **ppIPortableDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDevicePath ( _                             ' VTable offset = 28
     BYREF ppwszSiloDevicePath AS DWORD _               ' __out LPWSTR *ppwszSiloDevicePath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnhancedStorageSilo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnhancedStorageSiloAction
' IID = {B6F7F311-206F-4FF8-9C4B-27EFEE77A86F}
' IEnhancedStorageSiloAction Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnhancedStorageSiloAction_INTERFACE_DEFINED)
    %IEnhancedStorageSiloAction_INTERFACE_DEFINED = 1

INTERFACE IEnhancedStorageSiloAction $IID_IEnhancedStorageSiloAction

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
     BYREF ppwszActionName AS DWORD _                   ' __out LPWSTR *ppwszActionName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescription ( _                            ' VTable offset = 16
     BYREF ppwszActionDescription AS DWORD _            ' __out LPWSTR *ppwszActionDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Invoke ( _                                    ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnhancedStorageSiloAction_INTERFACE_DEFINED__ */
