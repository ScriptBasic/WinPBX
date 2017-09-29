' ########################################################################################
' Microsoft Windows
' File: PortableDeviceApi.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PORTABLEDEVICEAPI_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "propidl.inc"
#INCLUDE ONCE "PortableDeviceTypes.inc"

$LIBID_PortableDeviceApiLib = GUID$("{1F001332-1A57-4934-BE31-AFFC99F4EE0A}")

'#if (_WIN32_WINNT >= 0x0501) // XP and later

$CLSID_PortableDevice = GUID$("{728A21C5-3D9E-48D7-9810-864848F0F404}")
$CLSID_PortableDeviceManager = GUID$("{0AF10CEC-2ECD-4B92-9581-34F6AE0637F3}")
$CLSID_PortableDeviceService = GUID$("{EF5DB4C2-9312-422C-9152-411CD9C4DD84}")
$CLSID_PortableDeviceDispatchFactory = GUID$("{43232233-8338-4658-AE01-0B4AE830B6B0}")
$CLSID_PortableDeviceFTM = GUID$("{F7C0039A-4762-488A-B4B3-760EF9A1BA9B}")
$CLSID_PortableDeviceServiceFTM = GUID$("{1649B154-C794-497A-9B03-F3F0121302F3}")

' ########################################################################################
' Interface name = IPortableDeviceManager
' IID = {A1567595-4C2F-4574-A6FA-ECEF917B9A40}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPortableDeviceManager_INTERFACE_DEFINED)
    %IPortableDeviceManager_INTERFACE_DEFINED = 1

$IID_IPortableDeviceManager = GUID$("{A1567595-4C2F-4574-A6FA-ECEF917B9A40}")

INTERFACE IPortableDeviceManager $IID_IPortableDeviceManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDevices ( _                                ' VTable offset = 12
     BYREF pPnPDeviceIDs AS DWORD _                     ' __inout LPWSTR *pPnPDeviceIDs [array of WSTRINGZ pointers]
   , BYREF pcPnPDeviceIDs AS DWORD _                    ' __inout DWORD *pcPnPDeviceIDs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RefreshDeviceList ( _                         ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceFriendlyName ( _                     ' VTable offset = 20
     BYVAL pszPnPDeviceID AS WSTRINGZ PTR _             ' __in LPCWSTR pszPnPDeviceID
   , BYVAL pDeviceFriendlyName AS WSTRINGZ PTR _        ' __inout WCHAR *pDeviceFriendlyName
   , BYREF pcchDeviceFriendlyName AS DWORD _            ' __inout DWORD *pcchDeviceFriendlyName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceDescription ( _                      ' VTable offset = 24
     BYVAL pszPnPDeviceID AS WSTRINGZ PTR _             ' __in LPCWSTR pszPnPDeviceID
   , BYVAL pDeviceDescription AS WSTRINGZ PTR _         ' __inout WCHAR *pDeviceDescription
   , BYREF pcchDeviceDescription AS DWORD _             ' __inout DWORD *pcchDeviceDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceManufacturer ( _                     ' VTable offset = 28
     BYVAL pszPnPDeviceID AS WSTRINGZ PTR _             ' __in LPCWSTR pszPnPDeviceID
   , BYVAL pDeviceManufacturer AS WSTRINGZ PTR _        ' __inout WCHAR *pDeviceManufacturer
   , BYREF pcchDeviceManufacturer AS DWORD _            ' __inout DWORD *pcchDeviceManufacturer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceProperty ( _                         ' VTable offset = 32
     BYVAL pszPnPDeviceID AS WSTRINGZ PTR _             ' __in LPCWSTR pszPnPDeviceID
   , BYREF pszDevicePropertyName AS WSTRINGZ _          ' __in LPCWSTR pszDevicePropertyName
   , BYVAL pData AS BYTE PTR _                          ' __inout BYTE *pData
   , BYREF pcbData AS DWORD _                           ' __inout DWORD *pcbData
   , BYREF pdwType AS DWORD _                           ' __inout DWORD *pdwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateDevices ( _                         ' VTable offset = 36
     BYREF pPnPDeviceIDs AS DWORD _                     ' __inout LPWSTR *pPnPDeviceIDs [array of WSTRINGZ pointers]
   , BYREF pcPnPDeviceIDs AS DWORD _                    ' __inout DWORD* pcPnPDeviceIDs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPortableDeviceManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPortableDevice
' IID = {625E2DF8-6392-4CF0-9AD1-3CFA5F17775C}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPortableDevice_INTERFACE_DEFINED)
    %IPortableDevice_INTERFACE_DEFINED = 1

$IID_IPortableDevice = GUID$("{625E2DF8-6392-4CF0-9AD1-3CFA5F17775C}")

INTERFACE IPortableDevice $IID_IPortableDevice

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Open ( _                                      ' VTable offset = 12
     BYVAL pszPnPDeviceID AS WSTRINGZ PTR _             ' __in LPCWSTR pszPnPDeviceID
   , BYVAL pClientInfo AS IPortableDeviceValues _       ' __in IPortableDeviceValues *pClientInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendCommand ( _                               ' VTable offset = 16
     BYVAL dwFlags AS DWORD _                           ' __in const DWORD dwFlags
   , BYVAL pParameters AS IPortableDeviceValues _       ' __in IPortableDeviceValues *pParameters IPortableDeviceValues
   , BYREF ppResults AS IPortableDeviceValues _         ' __out IPortableDeviceValues **ppResults IPortableDeviceValues
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Content ( _                                   ' VTable offset = 20
     BYREF ppContent AS IPortableDeviceContent _        ' __out IPortableDeviceContent **ppContent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Capabilities ( _                              ' VTable offset = 24
     BYREF ppCapabilities AS IPortableDeviceCapabilities _ ' __out IPortableDeviceCapabilities **ppCapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 36
     BYVAL dwFlags AS DWORD _                           ' __in const DWORD dwFlags
   , BYVAL pCallback AS IPortableDeviceEventCallback _  ' __in IPortableDeviceEventCallback *pCallback
   , BYVAL pParameters AS IPortableDeviceValues _       ' __in IPortableDeviceValues *pParameters
   , BYREF ppszCookie AS DWORD _                        ' __out LPWSTR *ppszCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 40
     BYREF pszCookie AS WSTRINGZ _                      ' __in LPCWSTR pszCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPnPDeviceID ( _                            ' VTable offset = 44
     BYVAL ppszPnPDeviceID AS WSTRINGZ PTR _            ' __out LPWSTR *ppszPnPDeviceID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPortableDevice_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPortableDeviceContent
' IID = {6A96ED84-7C73-4480-9938-BF5AF477D426}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPortableDeviceContent_INTERFACE_DEFINED)
    %IPortableDeviceContent_INTERFACE_DEFINED = 1

$IID_IPortableDeviceContent = GUID$("{6A96ED84-7C73-4480-9938-BF5AF477D426}")

INTERFACE IPortableDeviceContent $IID_IPortableDeviceContent

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EnumObjects ( _                               ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in const DWORD dwFlags
   , BYREF pszParentObjectID AS WSTRINGZ _              ' __in LPCWSTR pszParentObjectID
   , BYVAL pFilter AS IPortableDeviceValues _           ' __in IPortableDeviceValues *pFilter
   , BYREF ppenum AS IEnumPortableDeviceObjectIDs _     ' __out IEnumPortableDeviceObjectIDs **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Properties ( _                                ' VTable offset = 16
     BYREF ppProperties AS IPortableDeviceProperties _  ' __out IPortableDeviceProperties **ppProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Transfer ( _                                  ' VTable offset = 20
     BYREF ppResources AS IPortableDeviceResources _    ' __out IPortableDeviceResources **ppResources
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateObjectWithPropertiesOnly ( _            ' VTable offset = 24
     BYVAL pValues AS IPortableDeviceValues _           ' __in IPortableDeviceValues* pValues
   , BYREF ppszObjectID AS DWORD _                      ' __inout LPWSTR* ppszObjectID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateObjectWithPropertiesAndData ( _         ' VTable offset = 28
     BYVAL pValues AS IPortableDeviceValues _           ' __in IPortableDeviceValues *pValues
   , BYREF ppData AS IStream _                          ' __out IStream **ppData
   , BYREF pdwOptimalWriteBufferSize AS DWORD _         ' __inout DWORD *pdwOptimalWriteBufferSize
   , BYREF ppszCookie AS DWORD _                        ' __inout LPWSTR *ppszCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 32
     BYVAL dwOptions AS DWORD _                         ' __in const DWORD dwOptions
   , BYVAL pObjectIDs AS IPortableDevicePropVariantCollection _ ' __in IPortableDevicePropVariantCollection *pObjectIDs
   , BYREF ppResults AS IPortableDevicePropVariantCollection _ ' __inout IPortableDevicePropVariantCollection **ppResults
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectIDsFromPersistentUniqueIDs ( _       ' VTable offset = 36
     BYVAL pPersistentUniqueIDs AS IPortableDevicePropVariantCollection _ ' __in IPortableDevicePropVariantCollection* pPersistentUniqueIDs
   , BYREF ppObjectIDs AS IPortableDevicePropVariantCollection _ ' __out IPortableDevicePropVariantCollection** ppObjectIDs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Move ( _                                      ' VTable offset = 44
     BYVAL pObjectIDs AS IPortableDevicePropVariantCollection _ ' __in IPortableDevicePropVariantCollection *pObjectIDs
   , BYREF pszDestinationFolderObjectID AS WSTRINGZ _   ' __in LPCWSTR pszDestinationFolderObjectID
   , BYREF ppResults AS IPortableDevicePropVariantCollection _ ' __inout IPortableDevicePropVariantCollection **ppResults
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Copy ( _                                      ' VTable offset = 48
     BYVAL pObjectIDs AS IPortableDevicePropVariantCollection _  ' __in IPortableDevicePropVariantCollection *pObjectIDs
   , BYREF pszDestinationFolderObjectID AS WSTRINGZ _    ' __in LPCWSTR pszDestinationFolderObjectID
   , BYREF ppResults AS IPortableDevicePropVariantCollection _ ' __inout IPortableDevicePropVariantCollection **ppResults
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPortableDeviceContent_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPortableDeviceContent2
' IID = 9b4add96-f6bf-4034-8708-eca72bf10554
' Inherited interface = IPortableDeviceContent
' ########################################################################################

#IF NOT %DEF(%IPortableDeviceContent2_INTERFACE_DEFINED)
    %IPortableDeviceContent2_INTERFACE_DEFINED = 1

$IID_IPortableDeviceContent2 = GUID$("{9b4add96-f6bf-4034-8708-eca72bf10554}")

INTERFACE IPortableDeviceContent2 $IID_IPortableDeviceContent2

   INHERIT IUnknown

   ' =====================================================================================
   ' IPortableDeviceContent methods
   ' =====================================================================================
   METHOD EnumObjects ( _                               ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in const DWORD dwFlags
   , BYREF pszParentObjectID AS WSTRINGZ _              ' __in LPCWSTR pszParentObjectID
   , BYVAL pFilter AS IPortableDeviceValues _           ' __in IPortableDeviceValues *pFilter
   , BYREF ppenum AS IEnumPortableDeviceObjectIDs _     ' __out IEnumPortableDeviceObjectIDs **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Properties ( _                                ' VTable offset = 16
     BYREF ppProperties AS IPortableDeviceProperties _  ' __out IPortableDeviceProperties **ppProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Transfer ( _                                  ' VTable offset = 20
     BYREF ppResources AS IPortableDeviceResources _    ' __out IPortableDeviceResources **ppResources
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateObjectWithPropertiesOnly ( _            ' VTable offset = 24
     BYVAL pValues AS IPortableDeviceValues _           ' __in IPortableDeviceValues* pValues
   , BYREF ppszObjectID AS DWORD _                      ' __inout LPWSTR* ppszObjectID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateObjectWithPropertiesAndData ( _         ' VTable offset = 28
     BYVAL pValues AS IPortableDeviceValues _           ' __in IPortableDeviceValues *pValues
   , BYREF ppData AS IStream _                          ' __out IStream **ppData
   , BYREF pdwOptimalWriteBufferSize AS DWORD _         ' __inout DWORD *pdwOptimalWriteBufferSize
   , BYREF ppszCookie AS DWORD _                        ' __inout LPWSTR *ppszCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 32
     BYVAL dwOptions AS DWORD _                         ' __in const DWORD dwOptions
   , BYVAL pObjectIDs AS IPortableDevicePropVariantCollection _ ' __in IPortableDevicePropVariantCollection *pObjectIDs
   , BYREF ppResults AS IPortableDevicePropVariantCollection _ ' __inout IPortableDevicePropVariantCollection **ppResults
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectIDsFromPersistentUniqueIDs ( _       ' VTable offset = 36
     BYVAL pPersistentUniqueIDs AS IPortableDevicePropVariantCollection _ ' __in IPortableDevicePropVariantCollection* pPersistentUniqueIDs
   , BYREF ppObjectIDs AS IPortableDevicePropVariantCollection _ ' __out IPortableDevicePropVariantCollection** ppObjectIDs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Move ( _                                      ' VTable offset = 44
     BYVAL pObjectIDs AS IPortableDevicePropVariantCollection _ ' __in IPortableDevicePropVariantCollection *pObjectIDs
   , BYREF pszDestinationFolderObjectID AS WSTRINGZ _   ' __in LPCWSTR pszDestinationFolderObjectID
   , BYREF ppResults AS IPortableDevicePropVariantCollection _ ' __inout IPortableDevicePropVariantCollection **ppResults
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Copy ( _                                      ' VTable offset = 48
     BYVAL pObjectIDs AS IPortableDevicePropVariantCollection _  ' __in IPortableDevicePropVariantCollection *pObjectIDs
   , BYREF pszDestinationFolderObjectID AS WSTRINGZ _    ' __in LPCWSTR pszDestinationFolderObjectID
   , BYREF ppResults AS IPortableDevicePropVariantCollection _ ' __inout IPortableDevicePropVariantCollection **ppResults
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPortableDeviceContent2 methods
   ' =====================================================================================
   METHOD UpdateObjectWithPropertiesAndData ( _         ' VTable offset = 52
     BYVAL pszObjectID AS WSTRINGZ PTR _                ' __in LPCWSTR pszObjectID
   , BYVAL pProperties AS IPortableDeviceValues _       ' __in IPortableDeviceValues *pProperties
   , BYREF ppData AS IStream _                          ' __out IStream **ppData
   , BYREF pdwOptimalWriteBufferSize AS DWORD _         ' __inout DWORD *pdwOptimalWriteBufferSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPortableDeviceContent2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumPortableDeviceObjectIDs
' IID = {10ECE955-CF41-4728-BFA0-41EEDF1BBF19}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumPortableDeviceObjectIDs_INTERFACE_DEFINED)
    %IEnumPortableDeviceObjectIDs_INTERFACE_DEFINED = 1

$IID_IEnumPortableDeviceObjectIDs = GUID$("{10ECE955-CF41-4728-BFA0-41EEDF1BBF19}")

INTERFACE IEnumPortableDeviceObjectIDs $IID_IEnumPortableDeviceObjectIDs

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cObjects AS DWORD _                          ' __in ULONG cObjects
   , BYREF pObjIDs AS WSTRINGZ _                        ' __out LPWSTR *pObjIDs
   , BYREF pcFetched AS DWORD _                         ' __inout ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cObjects AS DWORD _                          ' __in ULONG cObjects
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumPortableDeviceObjectIDs _     ' __out IEnumPortableDeviceObjectIDs **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumPortableDeviceObjectIDs_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPortableDeviceProperties
' IID = {7F6D695C-03DF-4439-A809-59266BEEE3A6}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPortableDeviceProperties_INTERFACE_DEFINED)
    %IPortableDeviceProperties_INTERFACE_DEFINED = 1

$IID_IPortableDeviceProperties = GUID$("{7F6D695C-03DF-4439-A809-59266BEEE3A6}")

INTERFACE IPortableDeviceProperties $IID_IPortableDeviceProperties

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSupportedProperties ( _                    ' VTable offset = 12
     BYVAL pszObjectID AS WSTRINGZ PTR _                ' __in LPCWSTR pszObjectID
   , BYREF ppKeys AS IPortableDeviceKeyCollection _     ' __out IPortableDeviceKeyCollection **ppKeys
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyAttributes ( _                     ' VTable offset = 16
     BYVAL pszObjectID AS WSTRINGZ PTR _                ' __in LPCWSTR pszObjectID
   , BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY *key
   , BYREF ppAttributes AS IPortableDeviceValues _      ' __out IPortableDeviceValues **ppAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValues ( _                                 ' VTable offset = 20
     BYVAL pszObjectID AS WSTRINGZ PTR _                ' __in LPCWSTR pszObjectID
   , BYVAL pKeys AS IPortableDeviceKeyCollection _      ' __in IPortableDeviceKeyCollection *pKeys
   , BYREF ppValues AS IPortableDeviceValues _          ' __out IPortableDeviceValues **ppValues
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetValues ( _                                 ' VTable offset = 24
     BYVAL pszObjectID AS WSTRINGZ PTR _                ' __in LPCWSTR pszObjectID
   , BYVAL pValues AS IPortableDeviceValues _           ' __in IPortableDeviceValues *pValues
   , BYREF ppResults AS IPortableDeviceValues _         ' __out IPortableDeviceValues **ppResults
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 28
     BYVAL pszObjectID AS WSTRINGZ PTR _                ' __in LPCWSTR pszObjectID
   , BYVAL pKeys AS IPortableDeviceKeyCollection _      ' __in IPortableDeviceKeyCollection *pKeys
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPortableDeviceProperties_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPortableDeviceResources
' IID = {FD8878AC-D841-4D17-891C-E6829CDB6934}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPortableDeviceResources_INTERFACE_DEFINED)
    %IPortableDeviceResources_INTERFACE_DEFINED = 1

$IID_IPortableDeviceResources = GUID$("{FD8878AC-D841-4D17-891C-E6829CDB6934}")

INTERFACE IPortableDeviceResources $IID_IPortableDeviceResources

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSupportedResources ( _                     ' VTable offset = 12
     BYVAL pszObjectID AS WSTRINGZ PTR _                ' __in LPCWSTR pszObjectID
   , BYREF IPortableDeviceKeyCollection AS IPortableDeviceKeyCollection _ ' __out IPortableDeviceKeyCollection **ppKeys
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResourceAttributes ( _                     ' VTable offset = 16
     BYVAL pszObjectID AS WSTRINGZ PTR _                ' __in LPCWSTR pszObjectID
   , BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY *key
   , BYREF ppResourceAttributes AS IPortableDeviceValues _ ' __out IPortableDeviceValues **ppResourceAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStream ( _                                 ' VTable offset = 20
     BYVAL pszObjectID AS WSTRINGZ PTR _                ' __in LPCWSTR pszObjectID
   , BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY *key
   , BYVAL dwMode AS DWORD _                            ' __in DWORD dwMode
   , BYREF pdwOptimalBufferSize AS DWORD _              ' __inout DWORD *pdwOptimalBufferSize
   , BYREF ppStream AS IStream _                        ' __out IStream **ppStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 24
     BYVAL pszObjectID AS WSTRINGZ PTR _                ' __in LPCWSTR pszObjectID
   , BYVAL pKeys AS IPortableDeviceKeyCollection _      ' __in IPortableDeviceKeyCollection *pKeys
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateResource ( _                            ' VTable offset = 32
     BYVAL pResourceAttributes AS IPortableDeviceValues _ ' __in IPortableDeviceValues *pResourceAttributes
   , BYREF ppData AS IStream _                          ' __out IStream **ppData
   , OPTIONAL BYREF pdwOptimalWriteBufferSize AS DWORD _ ' __inout DWORD *pdwOptimalWriteBufferSize
   , OPTIONAL BYREF ppszCookie AS DWORD _               ' __inout LPWSTR *ppszCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPortableDeviceResources_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPortableDeviceCapabilities
' IID = {2C8C6DBF-E3DC-4061-BECC-8542E810D126}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPortableDeviceCapabilities_INTERFACE_DEFINED)
    %IPortableDeviceCapabilities_INTERFACE_DEFINED = 1

$IID_IPortableDeviceCapabilities = GUID$("{2C8C6DBF-E3DC-4061-BECC-8542E810D126}")

INTERFACE IPortableDeviceCapabilities $IID_IPortableDeviceCapabilities

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSupportedCommands ( _                      ' VTable offset = 12
     BYREF ppCommands AS IPortableDeviceKeyCollection _ ' __out IPortableDeviceKeyCollection **ppCommands
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCommandOptions ( _                         ' VTable offset = 16
     BYREF Command AS PROPERTYKEY _                     ' __in PROPERTYKEY *Command
   , BYREF ppOptions AS IPortableDeviceValues _         ' __out IPortableDeviceValues **ppOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFunctionalCategories ( _                   ' VTable offset = 20
     BYREF ppCategories AS IPortableDevicePropVariantCollection _ ' __out IPortableDevicePropVariantCollection **ppCategories
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFunctionalObjects ( _                      ' VTable offset = 24
     BYREF Category AS GUID _                           ' __in REFGUID* Category
   , BYREF ppObjectIDs AS IPortableDevicePropVariantCollection _ ' __out IPortableDevicePropVariantCollection **ppObjectIDs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSupportedContentTypes ( _                  ' VTable offset = 28
     BYREF Category AS GUID _                           ' __in REFGUID* Category
   , BYREF ppContentTypes AS IPortableDevicePropVariantCollection _ ' __out IPortableDevicePropVariantCollection **ppContentTypes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSupportedFormats ( _                       ' VTable offset = 32
     BYREF ContentType AS GUID _                        ' __in REFGUID *ContentType
   , BYREF ppFormats AS IPortableDevicePropVariantCollection _ ' __out IPortableDevicePropVariantCollection **ppFormats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSupportedFormatProperties ( _              ' VTable offset = 36
     BYREF Format AS GUID _                             ' __in REFGUID *Format
   , BYREF ppKeys AS IPortableDeviceKeyCollection _     ' __out IPortableDeviceKeyCollection **ppKeys
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFixedPropertyAttributes ( _                ' VTable offset = 40
     BYREF Format AS GUID _                             ' __in REFGUID *Format
   , BYREF key AS PROPERTYKEY _                         ' __in PROPERTYKEY *key
   , BYREF ppAttributes AS IPortableDeviceValues _      ' __out IPortableDeviceValues **ppAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSupportedEvents ( _                        ' VTable offset = 48
     BYREF ppEvents AS IPortableDevicePropVariantCollection _ ' __out IPortableDevicePropVariantCollection **ppEvents
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEventOptions ( _                           ' VTable offset = 52
     BYREF Event AS GUID _                              ' __in REFGUID *Event
   , BYREF ppOptions AS IPortableDeviceValues _         ' __out IPortableDeviceValues **ppOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPortableDeviceCapabilities_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPortableDeviceEventCallback
' IID = {A8792A31-F385-493C-A893-40F64EB45F6E}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPortableDeviceEventCallback_INTERFACE_DEFINED)
    %IPortableDeviceEventCallback_INTERFACE_DEFINED = 1

$IID_IPortableDeviceEventCallback = GUID$("{A8792A31-F385-493C-A893-40F64EB45F6E}")

INTERFACE IPortableDeviceEventCallback $IID_IPortableDeviceEventCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnEvent ( _                                   ' VTable offset = 12
     BYVAL pEventParameters AS IPortableDeviceValues _  ' __in IPortableDeviceValues *pEventParameters
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPortableDeviceEventCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPortableDeviceDataStream
' IID = {A8792A31-F385-493C-A893-40F64EB45F6E}
' Inherited interface = IStream
' ########################################################################################

#IF NOT %DEF(%IPortableDeviceDataStream_INTERFACE_DEFINED)
    %IPortableDeviceDataStream_INTERFACE_DEFINED = 1

$IID_IPortableDeviceDataStream = GUID$("{88E04DB3-1012-4D64-9996-F703A950D3F4}")

INTERFACE IPortableDeviceDataStream $IID_IPortableDeviceDataStream

   INHERIT IUnknown

   ' =====================================================================================
   ' ISequentialStream Methods
   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 12
     BYVAL pv AS DWORD _                                ' __out void* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbRead AS DWORD _                           ' __out ULONG *pcbRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Write ( _                                     ' VTable offset = 16
     BYVAL pv AS DWORD _                                ' __in void const* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbWritten AS DWORD _                        ' __out ULONG *pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IStream Methods
   ' =====================================================================================
   METHOD Seek ( _                                      ' VTable offset = 20
     BYVAL dlibMove AS QUAD _                                       ' __in LARGE_INTEGER dlibMove
   , BYVAL dwOrigin AS DWORD _                                      ' __in DWORD dwOrigin
   , BYREF plibNewPosition AS QUAD _                                       ' __out ULARGE_INTEGER* plibNewPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSize ( _                                   ' VTable offset = 24
     BYVAL libNewSize AS QUAD _                                       ' __in ULARGE_INTEGER libNewSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offset = 28
     BYVAL pstm AS IStream _                            ' __in IStream* pstm
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYREF pcbRead AS QUAD _                            ' __out ULARGE_INTEGER* pcbRead
   , BYREF pcbWritten AS QUAD _                         ' __out ULARGE_INTEGER* pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 32
     BYVAL grfCommitFlags AS DWORD _                    ' __in DWORD grfCommitFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Revert ( _                                    ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockRegion ( _                                ' VTable offset = 40
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockRegion ( _                              ' VTable offset = 44
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stat ( _                                      ' VTable offset = 48
     BYREF pstatstg AS STATSTG _                        ' __out STATSTG* pstatstg
   , BYVAL grfStatFlag AS DWORD _                       ' __in DWORD grfStatFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 52
     BYREF ppstm AS IStream _                           ' __out IStream** ppstm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPortableDeviceDataStream Methods
   ' =====================================================================================
   METHOD GetObjectID ( _                               ' VTable offset = 56
     BYREF ppszObjectID AS DWORD _                      ' __out LPWSTR *ppszObjectID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPortableDeviceDataStream_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPortableDevicePropertiesBulk
' IID = 482B05C0-4056-44ED-9E0F-5E23B009DA93
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPortableDevicePropertiesBulk_INTERFACE_DEFINED)
    %IPortableDevicePropertiesBulk_INTERFACE_DEFINED = 1

$IID_IPortableDevicePropertiesBulk = GUID$("{482B05C0-4056-44ED-9E0F-5E23B009DA93}")

INTERFACE IPortableDevicePropertiesBulk $IID_IPortableDevicePropertiesBulk

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueueGetValuesByObjectList ( _                ' VTable offset = 12
     BYVAL pObjectIDs AS IPortableDevicePropVariantCollection _ ' __in IPortableDevicePropVariantCollection *pObjectIDs
   , BYVAL pKeys AS IPortableDeviceKeyCollection _      ' __in IPortableDeviceKeyCollection *pKeys
   , BYVAL pCallback AS IPortableDevicePropertiesBulkCallback _ ' __in IPortableDevicePropertiesBulkCallback *pCallback
   , BYREF pContext AS GUID _                           ' __out GUID *pContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueueGetValuesByObjectFormat ( _              ' VTable offset = 16
     BYREF pguidObjectFormat AS GUID _                  ' __in REFGUID pguidObjectFormat
   , BYREF pszParentObjectID AS WSTRINGZ _              ' __in LPCWSTR pszParentObjectID
   , BYVAL dwDepth AS DWORD _                           ' __in const DWORD dwDepth
   , BYVAL pKeys AS IPortableDeviceKeyCollection _      ' __in IPortableDeviceKeyCollection *pKeys
   , BYVAL pCallback AS IPortableDevicePropertiesBulkCallback _ ' __in IPortableDevicePropertiesBulkCallback *pCallback
   , BYREF pContext AS GUID _                           ' __out GUID *pContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueueSetValuesByObjectList ( _                ' VTable offset = 20
     BYVAL pObjectValues AS IPortableDeviceValuesCollection _ ' __in IPortableDeviceValuesCollection *pObjectValues
   , BYVAL pCallback AS IPortableDevicePropertiesBulkCallback _ ' __in IPortableDevicePropertiesBulkCallback *pCallback
   , BYREF pContext AS GUID _                           ' __out GUID *pContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 24
     BYREF pContext AS GUID _                           ' __in REFGUID pContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 28
     BYREF pContext AS GUID _                           ' __in REFGUID pContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPortableDevicePropertiesBulk_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPortableDevicePropertiesBulkCallback
' IID = 9DEACB80-11E8-40E3-A9F3-F557986A7845
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPortableDevicePropertiesBulkCallback_INTERFACE_DEFINED)
    %IPortableDevicePropertiesBulkCallback_INTERFACE_DEFINED = 1

$IID_IPortableDevicePropertiesBulkCallback = GUID$("{9DEACB80-11E8-40E3-A9F3-F557986A7845}")

INTERFACE IPortableDevicePropertiesBulkCallback $IID_IPortableDevicePropertiesBulkCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnStart ( _                                   ' VTable offset = 12
     BYREF pContext AS GUID _                           ' __in REFGUID pContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnProgress ( _                                ' VTable offset = 16
     BYREF pContext AS GUID _                           ' __in REFGUID pContext
   , BYVAL pResults AS IPortableDeviceValuesCollection _ ' __in IPortableDeviceValuesCollection *pResults
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnEnd ( _                                     ' VTable offset = 20
     BYREF pContext AS GUID _                           ' __in REFGUID pContext
   , BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPortableDevicePropertiesBulkCallback_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPortableDeviceServiceManager
' IID = a8abc4e9-a84a-47a9-80b3-c5d9b172a961
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPortableDeviceServiceManager_INTERFACE_DEFINED)
    %IPortableDeviceServiceManager_INTERFACE_DEFINED = 1

$IID_IPortableDeviceServiceManager = GUID$("{a8abc4e9-a84a-47a9-80b3-c5d9b172a961}")

INTERFACE IPortableDeviceServiceManager $IID_IPortableDeviceServiceManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDeviceServices ( _                         ' VTable offset = 12
     BYVAL pszPnPDeviceID AS WSTRINGZ PTR _             ' __in LPCWSTR pszPnPDeviceID
   , BYREF guidServiceCategory AS GUID _                ' __in REFGUID guidServiceCategory
   , BYREF pServices AS DWORD _                         ' __inout LPWSTR *pServices [array of WSTRINGZ pointers]
   , BYREF pcServices AS DWORD _                        ' __inout DWORD *pcServices
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceForService ( _                       ' VTable offset = 16
     BYVAL pszPnPServiceID AS WSTRINGZ PTR _            ' __in LPCWSTR pszPnPServiceID
   , BYREF ppszPnPDeviceID AS DWORD _                   ' __out LPWSTR *ppszPnPDeviceID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPortableDeviceServiceManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPortableDeviceService
' IID = d3bd3a44-d7b5-40a9-98b7-2fa4d01dec08
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPortableDeviceService_INTERFACE_DEFINED)
    %IPortableDeviceService_INTERFACE_DEFINED = 1

$IID_IPortableDeviceService = GUID$("{d3bd3a44-d7b5-40a9-98b7-2fa4d01dec08}")

INTERFACE IPortableDeviceService $IID_IPortableDeviceService

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Open ( _                                      ' VTable offset = 12
     BYREF pszPnPServiceID AS WSTRINGZ _                ' __in LPCWSTR pszPnPServiceID
   , BYVAL pClientInfo AS IPortableDeviceValues _       ' __in IPortableDeviceValues *pClientInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Capabilities ( _                              ' VTable offset = 16
     BYREF ppCapabilities AS IPortableDeviceServiceCapabilities _ ' __out IPortableDeviceServiceCapabilities **ppCapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Content ( _                                   ' VTable offset = 20
     BYREF ppContent AS IPortableDeviceContent2 _       ' __out IPortableDeviceContent2 **ppContent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Methods ( _                                   ' VTable offset = 24
     BYREF ppMethods AS IPortableDeviceServiceMethods _ ' __out IPortableDeviceServiceMethods **ppMethods
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceObjectID ( _                        ' VTable offset = 36
     BYREF ppszServiceObjectID AS DWORD _               ' __out LPWSTR *ppszServiceObjectID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPnPServiceID ( _                           ' VTable offset = 40
     BYREF ppszPnPServiceID AS DWORD _                  ' __out LPWSTR *ppszPnPServiceID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 44
     BYVAL dwFlags AS DWORD _                           ' __in const DWORD dwFlags
   , BYVAL pCallback AS DWORD _                         ' __in IPortableDeviceEventCallback *pCallback
   , BYVAL pParameters AS IPortableDeviceValues _       ' __in IPortableDeviceValues *pParameters
   , BYREF ppszCookie AS DWORD _                        ' __out LPWSTR *ppszCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 48
     BYREF pszCookie AS WSTRINGZ _                      ' __in LPCWSTR pszCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendCommand ( _                               ' VTable offset = 52
     BYVAL dwFlags AS DWORD _                           ' __in const DWORD dwFlags
   , BYVAL pParameters AS IPortableDeviceValues _       ' __in IPortableDeviceValues *pParameters
   , BYREF ppResults AS IPortableDeviceValues _         ' __out IPortableDeviceValues **ppResults
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPortableDeviceService_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPortableDeviceServiceCapabilities
' IID = 24dbd89d-413e-43e0-bd5b-197f3c56c886
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPortableDeviceServiceCapabilities_INTERFACE_DEFINED)
    %IPortableDeviceServiceCapabilities_INTERFACE_DEFINED = 1

$IID_IPortableDeviceServiceCapabilities = GUID$("{24dbd89d-413e-43e0-bd5b-197f3c56c886}")

INTERFACE IPortableDeviceServiceCapabilities $IID_IPortableDeviceServiceCapabilities

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSupportedMethods ( _                       ' VTable offset = 12
     BYREF ppMethods AS IPortableDevicePropVariantCollection _ ' __out IPortableDevicePropVariantCollection **ppMethods
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSupportedMethodsByFormat ( _               ' VTable offset = 16
     BYREF Format AS GUID _                             ' __in REFGUID Format
   , BYREF ppMethods AS IPortableDevicePropVariantCollection _ ' __out IPortableDevicePropVariantCollection **ppMethods
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMethodAttributes ( _                       ' VTable offset = 20
     BYREF Method AS GUID _                             ' __in REFGUID Method
   , BYREF ppAttributes AS IPortableDeviceValues _      ' __out IPortableDeviceValues **ppAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMethodParameterAttributes ( _              ' VTable offset = 24
     BYREF Method AS GUID _                             ' __in REFGUID Method
   , BYREF Parameter AS PROPERTYKEY _                   ' __in REFPROPERTYKEY Parameter
   , BYREF ppAttributes AS IPortableDeviceValues _      ' __out IPortableDeviceValues **ppAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSupportedFormats ( _                       ' VTable offset = 28
     BYREF ppFormats AS IPortableDevicePropVariantCollection _ ' __out IPortableDevicePropVariantCollection **ppFormats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFormatAttributes ( _                       ' VTable offset = 32
     BYREF Format AS GUID _                             ' __in REFGUID Format
   , BYREF ppAttributes AS IPortableDeviceValues _      ' __out IPortableDeviceValues **ppAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSupportedFormatProperties ( _              ' VTable offset = 36
     BYREF Format AS GUID _                             ' __in REFGUID Format
   , BYREF ppKeys AS IPortableDeviceKeyCollection _     ' __out IPortableDeviceKeyCollection **ppKeys
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFormatPropertyAttributes ( _               ' VTable offset = 40
     BYREF Format AS GUID _                             ' __in REFGUID Format
   , BYREF Property AS PROPERTYKEY _                    ' __in REFPROPERTYKEY Property
   , BYREF ppAttributes AS IPortableDeviceValues _      ' __out IPortableDeviceValues **ppAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSupportedEvents ( _                        ' VTable offset = 44
     BYREF ppEvents AS IPortableDevicePropVariantCollection _ ' __out IPortableDevicePropVariantCollection **ppEvents
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEventAttributes ( _                        ' VTable offset = 48
     BYREF Event AS GUID _                              ' __in REFGUID Event
   , BYREF ppAttributes AS IPortableDeviceValues _      ' __out IPortableDeviceValues **ppAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEventParameterAttributes ( _               ' VTable offset = 52
     BYREF Event AS GUID _                              ' __in REFGUID Event
   , BYREF Parameter AS PROPERTYKEY _                   ' __in REFPROPERTYKEY Parameter
   , BYREF ppAttributes AS IPortableDeviceValues _      ' __out IPortableDeviceValues **ppAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInheritedServices ( _                      ' VTable offset = 56
     BYVAL dwInheritanceType AS DWORD _                 ' __in const DWORD dwInheritanceType
   , BYREF ppServices AS IPortableDevicePropVariantCollection _ ' __out IPortableDevicePropVariantCollection **ppServices
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFormatRenderingProfiles ( _                ' VTable offset = 60
     BYREF Format AS GUID _                             ' __in REFGUID Format
   , BYREF ppRenderingProfiles AS IPortableDeviceValuesCollection _ '__out IPortableDeviceValuesCollection **ppRenderingProfiles
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSupportedCommands ( _                      ' VTable offset = 64
     BYREF ppCommands AS IPortableDeviceKeyCollection _ ' __out IPortableDeviceKeyCollection **ppCommands
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCommandOptions ( _                         ' VTable offset = 68
     BYREF Command AS PROPERTYKEY _                     ' __in REFPROPERTYKEY Command
   , BYREF ppOptions AS IPortableDeviceValues _         ' __out IPortableDeviceValues **ppOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 72
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPortableDeviceServiceCapabilities_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPortableDeviceServiceMethods
' IID = e20333c9-fd34-412d-a381-cc6f2d820df7
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPortableDeviceServiceMethods_INTERFACE_DEFINED)
    %IPortableDeviceServiceMethods_INTERFACE_DEFINED = 1

$IID_IPortableDeviceServiceMethods = GUID$("{e20333c9-fd34-412d-a381-cc6f2d820df7}")

INTERFACE IPortableDeviceServiceMethods $IID_IPortableDeviceServiceMethods

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Invoke ( _                                    ' VTable offset = 12
     BYREF Method AS GUID _                             ' __in REFGUID Method
   , BYVAL pParameters AS IPortableDeviceValues _       ' __in IPortableDeviceValues *pParameters
   , BYREF ppResults AS IPortableDeviceValues _         ' __inout IPortableDeviceValues **ppResults
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InvokeAsync ( _                               ' VTable offset = 16
     BYREF Method AS GUID _                             ' __in REFGUID Method
   , BYVAL pParameters AS IPortableDeviceValues _       ' __in IPortableDeviceValues *pParameters
   , BYVAL pCallback AS IPortableDeviceServiceMethodCallback _ ' __in IPortableDeviceServiceMethodCallback *pCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 20
     BYVAL pCallback AS IPortableDeviceServiceMethodCallback _ '__in IPortableDeviceServiceMethodCallback *pCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPortableDeviceServiceMethods_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPortableDeviceServiceMethodCallback
' IID = c424233c-afce-4828-a756-7ed7a2350083
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPortableDeviceServiceMethodCallback_INTERFACE_DEFINED)
    %IPortableDeviceServiceMethodCallback_INTERFACE_DEFINED = 1

$IID_IPortableDeviceServiceMethodCallback = GUID$("{c424233c-afce-4828-a756-7ed7a2350083}")

INTERFACE IPortableDeviceServiceMethodCallback $IID_IPortableDeviceServiceMethodCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnComplete ( _                                ' VTable offset = 12
     BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   , BYVAL pResults AS IPortableDeviceValues _          ' __in IPortableDeviceValues *pResults
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPortableDeviceServiceMethodCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPortableDeviceDispatchFactory
' IID = 5e1eafc3-e3d7-4132-96fa-759c0f9d1e0f
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPortableDeviceDispatchFactory_INTERFACE_DEFINED)
    %IPortableDeviceDispatchFactory_INTERFACE_DEFINED = 1

$IID_IPortableDeviceDispatchFactory = GUID$("{5e1eafc3-e3d7-4132-96fa-759c0f9d1e0f}")

INTERFACE IPortableDeviceDispatchFactory $IID_IPortableDeviceDispatchFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDeviceDispatch ( _                         ' VTable offset = 12
     BYVAL pszPnPDeviceID AS WSTRINGZ PTR _             ' __in LPCWSTR pszPnPDeviceID
   , BYREF ppDeviceDispatch AS IDispatch _              ' __out IDispatch **ppDeviceDispatch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPortableDeviceDispatchFactory_INTERFACE_DEFINED__ */
