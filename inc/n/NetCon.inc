' ########################################################################################
' Microsoft Windows
' File: NetCon.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: NETCONLib
' Version: 1.0, Locale ID = 0
' Description: NetCon 1.0 Type Library
' Path: C:\WINDOWS\system32\hnetcfg.dll
' Library GUID: {43E734CA-043D-4A70-9A2C-A8F254063D91}
' ########################################################################################

#INCLUDE THIS ONCE
%NETCON_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "prsht.inc"

$LIBID_NETCONLib = GUID$("{43E734CA-043D-4A70-9A2C-A8F254063D91}")

$PROGID_NetSharingManager1 = "HNetCfg.HNetShare.1"
$PROGID_NetSharingManager = "HNetCfg.HNetShare"

$CLSID_ConnectionManager = GUID$("{BA126AD1-2166-11D1-B1D0-00805FC1270E}")
$CLSID_NetSharingManager = GUID$("{5C63C1AD-3956-4FF8-8486-40034758315B}")

%NETCON_MAX_NAME_LEN = 256

' ########################################################################################
' Interface name = IEnumNetConnection
' IID = C08956A0-1CD3-11D1-B1C5-00805FC1270E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumNetConnection_INTERFACE_DEFINED)
    %IEnumNetConnection_INTERFACE_DEFINED = 1

$IID_IEnumNetConnection = GUID$("{C08956A0-1CD3-11D1-B1C5-00805FC1270E}")

INTERFACE IEnumNetConnection $IID_IEnumNetConnection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS INetConnection _                    ' __out INetConnection **rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumNetConnection _               ' __out IEnumNetConnection **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumNetConnection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INetConnection
' IID = {C08956A1-1CD3-11D1-B1C5-00805FC1270E}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%INetConnection_INTERFACE_DEFINED)
    %INetConnection_INTERFACE_DEFINED = 1

' enum NETCON_CHARACTERISTIC_FLAGS
%NCCF_NONE              = 0???
%NCCF_ALL_USERS         = &H1???
%NCCF_ALLOW_DUPLICATION = &H2???
%NCCF_ALLOW_REMOVAL     = &H4???
%NCCF_ALLOW_RENAME      = &H8???
%NCCF_INCOMING_ONLY     = &H20???
%NCCF_OUTGOING_ONLY     = &H40???
%NCCF_BRANDED           = &H80???
%NCCF_SHARED            = &H100???
%NCCF_BRIDGED           = &H200???
%NCCF_FIREWALLED        = &H400???
%NCCF_DEFAULT           = &H800???
%NCCF_HOMENET_CAPABLE   = &H1000???
%NCCF_SHARED_PRIVATE    = &H2000???
%NCCF_QUARANTINED       = &H4000???
%NCCF_RESERVED          = &H8000???
%NCCF_HOSTED_NETWORK    = &H10000???
%NCCF_VIRTUAL_STATION   = &H20000???
%NCCF_BLUETOOTH_MASK    = &Hf0000???
%NCCF_LAN_MASK          = &Hf00000???

' enum NETCON_STATUS
%NCS_DISCONNECTED             = 0
%NCS_CONNECTING               = %NCS_DISCONNECTED             + 1
%NCS_CONNECTED                = %NCS_CONNECTING               + 1
%NCS_DISCONNECTING            = %NCS_CONNECTED                + 1
%NCS_HARDWARE_NOT_PRESENT     = %NCS_DISCONNECTING            + 1
%NCS_HARDWARE_DISABLED        = %NCS_HARDWARE_NOT_PRESENT     + 1
%NCS_HARDWARE_MALFUNCTION     = %NCS_HARDWARE_DISABLED        + 1
%NCS_MEDIA_DISCONNECTED       = %NCS_HARDWARE_MALFUNCTION     + 1
%NCS_AUTHENTICATING           = %NCS_MEDIA_DISCONNECTED       + 1
%NCS_AUTHENTICATION_SUCCEEDED = %NCS_AUTHENTICATING           + 1
%NCS_AUTHENTICATION_FAILED    = %NCS_AUTHENTICATION_SUCCEEDED + 1
%NCS_INVALID_ADDRESS          = %NCS_AUTHENTICATION_FAILED    + 1
%NCS_CREDENTIALS_REQUIRED     = %NCS_INVALID_ADDRESS          + 1

' enum NETCON_TYPE
%NCT_DIRECT_CONNECT = 0
%NCT_INBOUND        = 1
%NCT_INTERNET       = %NCT_INBOUND  + 1
%NCT_LAN            = %NCT_INTERNET + 1
%NCT_PHONE          = %NCT_LAN      + 1
%NCT_TUNNEL         = %NCT_PHONE    + 1
%NCT_BRIDGE         = %NCT_TUNNEL   + 1

' enum NETCON_MEDIATYPE
%NCM_NONE                 = 0
%NCM_DIRECT               = %NCM_NONE                 + 1
%NCM_ISDN                 = 2
%NCM_LAN                  = %NCM_ISDN                 + 1
%NCM_PHONE                = %NCM_LAN                  + 1
%NCM_TUNNEL               = %NCM_PHONE                + 1
%NCM_PPPOE                = %NCM_TUNNEL               + 1
%NCM_BRIDGE               = %NCM_PPPOE                + 1
%NCM_SHAREDACCESSHOST_LAN = %NCM_BRIDGE               + 1
%NCM_SHAREDACCESSHOST_RAS = %NCM_SHAREDACCESSHOST_LAN + 1

' // Size = 68 bytes
TYPE NETCON_PROPERTIES DWORD
   guidId          AS GUID           ' GUID
   pszwName        AS WSTRINGZ PTR   ' LPWSTR
   pszwDeviceName  AS WSTRINGZ PTR   ' LPWSTR
   Status          AS LONG           ' NETCON_STATUS enum
   MediaType       AS LONG           ' NETCON_MEDIATYPE enum
   dwCharacter     AS DWORD          ' DWORD
   clsidThisObject AS GUID           ' CLSID
   clsidUiObject   AS GUID           ' CLSID
END TYPE

%S_OBJECT_NO_LONGER_VALID = &H00000002&

$IID_INetConnection = GUID$("{C08956A1-1CD3-11D1-B1C5-00805FC1270E}")

INTERFACE INetConnection $IID_INetConnection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Connect ( _                                   ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Disconnect ( _                                ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Duplicate ( _                                 ' VTable offset = 24
     BYREF pszwDuplicateName AS WSTRINGZ _              ' __in LPCWSTR pszwDuplicateName
   , BYREF ppCon AS INetConnection _                    ' __out INetConnection **ppCon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperties ( _                             ' VTable offset = 28
     BYREF ppProps AS NETCON_PROPERTIES _               ' __out NETCON_PROPERTIES **ppProps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUiObjectClassId ( _                        ' VTable offset = 32
     BYREF pclsid AS GUID _                             ' __out CLSID *pclsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Rename ( _                                    ' VTable offset = 36
     BYREF pszwNewName AS WSTRINGZ _                    ' __in LPCWSTR pszwNewName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetConnection_INTERFACE_DEFINED__ */

DECLARE SUB NcFreeNetconProperties IMPORT "Netshell.dll" ALIAS "NcFreeNetconProperties" ( _
   BYREF pProps AS NETCON_PROPERTIES _                  ' __in NETCON_PROPERTIES* pProps
 )                                                      ' void

DECLARE FUNCTION NcIsValidConnectionName IMPORT "Netshell.dll" ALIAS "NcIsValidConnectionName" ( _
   BYREF pszwName AS WSTRINGZ _                         ' __in PCWSTR pszwName
 ) AS LONG                                              ' BOOL

' ########################################################################################
' Interface name = INetConnectionManager
' IID = C08956A2-1CD3-11D1-B1C5-00805FC1270E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%INetConnectionManager_INTERFACE_DEFINED)
    %INetConnectionManager_INTERFACE_DEFINED = 1

' enum NETCONMGR_ENUM_FLAGS
%NCME_DEFAULT = 0???
%NCME_HIDDEN  = &H1???

$IID_INetConnectionManager = GUID$("{C08956A2-1CD3-11D1-B1C5-00805FC1270E}")

INTERFACE INetConnectionManager $IID_INetConnectionManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EnumConnections ( _                           ' VTable offset = 12
     BYVAL Flags AS DWORD _                             ' __in NETCONMGR_ENUM_FLAGS Flags
   , BYREF ppEnum AS IEnumNetConnection _               ' __out IEnumNetConnection **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetConnectionManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INetConnectionConnectUi
' IID = C08956A3-1CD3-11D1-B1C5-00805FC1270E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%INetConnectionConnectUi_INTERFACE_DEFINED)
    %INetConnectionConnectUi_INTERFACE_DEFINED = 1

' enum NETCONUI_CONNECT_FLAGS
%NCUC_DEFAULT        = 0???
%NCUC_NO_UI          = &H1???
%NCUC_ENABLE_DISABLE = &H2???

$IID_INetConnectionConnectUi = GUID$("{C08956A3-1CD3-11D1-B1C5-00805FC1270E}")

INTERFACE INetConnectionConnectUi $IID_INetConnectionConnectUi

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetConnection ( _                             ' VTable offset = 12
     BYVAL pCon AS INetConnection _                     ' __in INetConnection *pCon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Connect ( _                                   ' VTable offset = 16
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Disconnect ( _                                ' VTable offset = 20
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetConnectionConnectUi_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumNetSharingPortMapping
' IID = C08956B0-1CD3-11D1-B1C5-00805FC1270E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumNetSharingPortMapping_INTERFACE_DEFINED)
    %IEnumNetSharingPortMapping_INTERFACE_DEFINED = 1

$IID_IEnumNetSharingPortMapping = GUID$("{C08956B0-1CD3-11D1-B1C5-00805FC1270E}")

INTERFACE IEnumNetSharingPortMapping $IID_IEnumNetSharingPortMapping

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgVar AS VARIANT _                           ' __out VARIANT *rgVar
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumNetSharingPortMapping _       ' __out IEnumNetSharingPortMapping **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumNetSharingPortMapping_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INetSharingPortMappingProps
' IID = {24B7E9B5-E38F-4685-851B-00892CF5F940}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetSharingPortMappingProps_INTERFACE_DEFINED)
    %INetSharingPortMappingProps_INTERFACE_DEFINED = 1

$IID_INetSharingPortMappingProps = GUID$("{24B7E9B5-E38F-4685-851B-00892CF5F940}")

INTERFACE INetSharingPortMappingProps $IID_INetSharingPortMappingProps

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET IPProtocol <2> ( _                      ' VTable offset = 32
   ) AS BYTE                                            ' __retval_out UCHAR *pucIPProt
   ' =====================================================================================
   PROPERTY GET ExternalPort <3> ( _                    ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pusPort
   ' =====================================================================================
   PROPERTY GET InternalPort <4> ( _                    ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *pusPort
   ' =====================================================================================
   PROPERTY GET Options <5> ( _                         ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *pdwOptions
   ' =====================================================================================
   PROPERTY GET TargetName <6> ( _                      ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTargetName
   ' =====================================================================================
   PROPERTY GET TargetIPAddress <7> ( _                 ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrTargetIPAddress
   ' =====================================================================================
   PROPERTY GET Enabled <8> ( _                         ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbool
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetSharingPortMappingProps_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INetSharingPortMapping
' IID = {C08956B1-1CD3-11D1-B1C5-00805FC1270E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetSharingPortMapping_INTERFACE_DEFINED)
    %INetSharingPortMapping_INTERFACE_DEFINED = 1

$IID_INetSharingPortMapping = GUID$("{C08956B1-1CD3-11D1-B1C5-00805FC1270E}")

INTERFACE INetSharingPortMapping $IID_INetSharingPortMapping

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Disable <1> ( _                               ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD Enable <2> ( _                                ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Properties <3> ( _                      ' VTable offset = 36
   ) AS INetSharingPortMappingProps                     ' __retval_out INetSharingPortMappingProps **ppNSPMP
   ' =====================================================================================
   METHOD Delete <4> ( _                                ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetSharingPortMapping_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumNetSharingEveryConnection
' IID = C08956B8-1CD3-11D1-B1C5-00805FC1270E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumNetSharingEveryConnection_INTERFACE_DEFINED)
    %IEnumNetSharingEveryConnection_INTERFACE_DEFINED = 1

$IID_IEnumNetSharingEveryConnection = GUID$("{C08956B8-1CD3-11D1-B1C5-00805FC1270E}")

INTERFACE IEnumNetSharingEveryConnection $IID_IEnumNetSharingEveryConnection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgVar AS VARIANT _                           ' __out VARIANT *rgVar
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumNetSharingEveryConnection _   ' __out IEnumNetSharingEveryConnection **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumNetSharingEveryConnection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumNetSharingPublicConnection
' IID = C08956B4-1CD3-11D1-B1C5-00805FC1270E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumNetSharingPublicConnection_INTERFACE_DEFINED)
    %IEnumNetSharingPublicConnection_INTERFACE_DEFINED = 1

$IID_IEnumNetSharingPublicConnection = GUID$("{C08956B4-1CD3-11D1-B1C5-00805FC1270E}")

INTERFACE IEnumNetSharingPublicConnection $IID_IEnumNetSharingPublicConnection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgVar AS VARIANT _                           ' __out VARIANT *rgVar
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumNetSharingPublicConnection _  ' __out IEnumNetSharingPublicConnection **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumNetSharingPublicConnection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumNetSharingPrivateConnection
' IID = C08956B5-1CD3-11D1-B1C5-00805FC1270E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumNetSharingPrivateConnection_INTERFACE_DEFINED)
    %IEnumNetSharingPrivateConnection_INTERFACE_DEFINED = 1

$IID_IEnumNetSharingPrivateConnection = GUID$("{C08956B5-1CD3-11D1-B1C5-00805FC1270E}")

INTERFACE IEnumNetSharingPrivateConnection $IID_IEnumNetSharingPrivateConnection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgVar AS VARIANT _                           ' __out VARIANT *rgVar
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumNetSharingPrivateConnection _ ' __out IEnumNetSharingPrivateConnection **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumNetSharingPrivateConnection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INetSharingPortMappingCollection
' IID = {02E4A2DE-DA20-4E34-89C8-AC22275A010B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetSharingPortMappingCollection_INTERFACE_DEFINED)
    %INetSharingPortMappingCollection_INTERFACE_DEFINED = 1

$IID_INetSharingPortMappingCollection = GUID$("{02E4A2DE-DA20-4E34-89C8-AC22275A010B}")

INTERFACE INetSharingPortMappingCollection $IID_INetSharingPortMappingCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetSharingPortMappingCollection_INTERFACE_DEFINED__ */

'// properties for INetConnection (wraps NETCON_PROPERTIES)

' ########################################################################################
' Interface name = INetConnectionProps
' IID = {F4277C95-CE5B-463D-8167-5662D9BCAA72}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetConnectionProps_INTERFACE_DEFINED)
    %INetConnectionProps_INTERFACE_DEFINED = 1

$IID_INetConnectionProps = GUID$("{F4277C95-CE5B-463D-8167-5662D9BCAA72}")

INTERFACE INetConnectionProps $IID_INetConnectionProps

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Guid <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGuid
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY GET DeviceName <3> ( _                      ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDeviceName
   ' =====================================================================================
   PROPERTY GET Status <4> ( _                          ' VTable offset = 40
   ) AS LONG                                            ' __retval_out NETCON_STATUS *pStatus
   ' =====================================================================================
   PROPERTY GET MediaType <5> ( _                       ' VTable offset = 44
   ) AS LONG                                            ' __retval_out NETCON_MEDIATYPE *pMediaType
   ' =====================================================================================
   PROPERTY GET Characteristics <6> ( _                 ' VTable offset = 48
   ) AS DWORD                                           ' __retval_out DWORD *pdwFlags
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetConnectionProps_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INetSharingConfiguration
' IID = {C08956B6-1CD3-11D1-B1C5-00805FC1270E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetSharingConfiguration_INTERFACE_DEFINED)
    %INetSharingConfiguration_INTERFACE_DEFINED = 1

' enum SHARINGCONNECTIONTYPE
%ICSSHARINGTYPE_PUBLIC  = 0
%ICSSHARINGTYPE_PRIVATE = %ICSSHARINGTYPE_PUBLIC + 1

' enum SHARINGCONNECTION_ENUM_FLAGS
%ICSSC_DEFAULT = 0
%ICSSC_ENABLED = %ICSSC_DEFAULT + 1

' enum ICS_TARGETTYPE
%ICSTT_NAME      = 0
%ICSTT_IPADDRESS = %ICSTT_NAME + 1

$IID_INetSharingConfiguration = GUID$("{C08956B6-1CD3-11D1-B1C5-00805FC1270E}")

INTERFACE INetSharingConfiguration $IID_INetSharingConfiguration

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET SharingEnabled <1> ( _                  ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY GET SharingConnectionType <2> ( _           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out SHARINGCONNECTIONTYPE *pType
   ' =====================================================================================
   METHOD DisableSharing <3> ( _                        ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD EnableSharing <4> ( _                         ' VTable offset = 40
     BYVAL Type AS LONG _                               ' __in SHARINGCONNECTIONTYPE Type
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InternetFirewallEnabled <5> ( _         ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   METHOD DisableInternetFirewall <6> ( _               ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD EnableInternetFirewall <7> ( _                ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnumPortMappings <8> ( _                ' VTable offset = 56
     BYVAL Flags AS LONG _                              ' __in SHARINGCONNECTION_ENUM_FLAGS Flags
   ) AS INetSharingPortMappingCollection                ' __retval_out INetSharingPortMappingCollection **ppColl
   ' =====================================================================================
   METHOD AddPortMapping <9> ( _                        ' VTable offset = 60
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYVAL ucIPProtocol AS BYTE _                       ' __in UCHAR ucIPProtocol
   , BYVAL usExternalPort AS WORD _                     ' __in USHORT usExternalPort
   , BYVAL usInternalPort AS WORD _                     ' __in USHORT usInternalPort
   , BYVAL dwOptions AS DWORD _                         ' __in DWORD dwOptions
   , BYVAL bstrTargetNameOrIPAddress AS WSTRING _       ' __in BSTR bstrTargetNameOrIPAddress
   , BYVAL eTargetType AS LONG _                        ' __in ICS_TARGETTYPE eTargetType
   ) AS INetSharingPortMapping                          ' __retval_out INetSharingPortMapping **ppMapping
   ' =====================================================================================
   METHOD RemovePortMapping <10> ( _                    ' VTable offset = 64
     BYVAL pMapping AS INetSharingPortMapping _         ' __in INetSharingPortMapping *pMapping
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetSharingConfiguration_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INetSharingEveryConnectionCollection
' IID = {33C4643C-7811-46FA-A89A-768597BD7223}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetSharingEveryConnectionCollection_INTERFACE_DEFINED)
    %INetSharingEveryConnectionCollection_INTERFACE_DEFINED = 1

$IID_INetSharingEveryConnectionCollection = GUID$("{33C4643C-7811-46FA-A89A-768597BD7223}")

INTERFACE INetSharingEveryConnectionCollection $IID_INetSharingEveryConnectionCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetSharingEveryConnectionCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INetSharingPublicConnectionCollection
' IID = {7D7A6355-F372-4971-A149-BFC927BE762A}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetSharingPublicConnectionCollection_INTERFACE_DEFINED)
    %INetSharingPublicConnectionCollection_INTERFACE_DEFINED = 1

$IID_INetSharingPublicConnectionCollection = GUID$("{7D7A6355-F372-4971-A149-BFC927BE762A}")

INTERFACE INetSharingPublicConnectionCollection $IID_INetSharingPublicConnectionCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetSharingPublicConnectionCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INetSharingPrivateConnectionCollection
' IID = {38AE69E0-4409-402A-A2CB-E965C727F840}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetSharingPrivateConnectionCollection_INTERFACE_DEFINED)
    %INetSharingPrivateConnectionCollection_INTERFACE_DEFINED = 1

$IID_INetSharingPrivateConnectionCollection = GUID$("{38AE69E0-4409-402A-A2CB-E965C727F840}")

INTERFACE INetSharingPrivateConnectionCollection $IID_INetSharingPrivateConnectionCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetSharingPrivateConnectionCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INetSharingManager
' IID = {C08956B7-1CD3-11D1-B1C5-00805FC1270E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetSharingManager_INTERFACE_DEFINED)
    %INetSharingManager_INTERFACE_DEFINED = 1

$IID_INetSharingManager = GUID$("{C08956B7-1CD3-11D1-B1C5-00805FC1270E}")

INTERFACE INetSharingManager $IID_INetSharingManager

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET SharingInstalled <1> ( _                ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbInstalled
   ' =====================================================================================
   PROPERTY GET EnumPublicConnections <2> ( _           ' VTable offset = 32
     BYVAL Flags AS LONG _                              ' __in SHARINGCONNECTION_ENUM_FLAGS Flags
   ) AS INetSharingPublicConnectionCollection           ' __retval_out INetSharingPublicConnectionCollection **ppColl
   ' =====================================================================================
   PROPERTY GET EnumPrivateConnections <3> ( _          ' VTable offset = 36
     BYVAL Flags AS LONG _                              ' __in SHARINGCONNECTION_ENUM_FLAGS Flags
   ) AS INetSharingPrivateConnectionCollection          ' __retval_out INetSharingPrivateConnectionCollection **ppColl
   ' =====================================================================================
   PROPERTY GET INetSharingConfigurationForINetConnection <6> ( _ ' VTable offset = 40
     BYVAL pNetConnection AS INetConnection _           ' __in INetConnection *pNetConnection
   ) AS INetSharingConfiguration                        ' __retval_out INetSharingConfiguration **ppNetSharingConfiguration
   ' =====================================================================================
   PROPERTY GET EnumEveryConnection <7> ( _             ' VTable offset = 44
   ) AS INetSharingEveryConnectionCollection            ' __retval_out INetSharingEveryConnectionCollection **ppColl
   ' =====================================================================================
   PROPERTY GET NetConnectionProps <8> ( _              ' VTable offset = 48
     BYVAL pNetConnection AS INetConnection _           ' __in INetConnection* pNetConnection
   ) AS INetConnectionProps                             ' __retval_out INetConnectionProps **ppProps
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetSharingManager_INTERFACE_DEFINED__ */
