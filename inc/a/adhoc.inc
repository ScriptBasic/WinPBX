' ########################################################################################
' Microsoft Windows
' File: adhoc.inc
' Library name: ADHOCLib
' Contents: AdHoc 1.0 Type Library
' Version: 1.0, Locale ID = 0
' Library GUID: {45357166-FF38-4302-8F5C-DF5B703A6E3D}
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ADHOC_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"

$LIBID_ADHOCLib = GUID$("{45357166-FF38-4302-8F5C-DF5B703A6E3D}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_Dot11AdHocManager = GUID$("{DD06A84F-83BD-4D01-8AB9-2389FEA0869E}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IDot11AdHocInterface = GUID$("{8F10CC2B-CF0D-42A0-ACBE-E2DE7007384D}")
$IID_IDot11AdHocInterfaceNotificationSink = GUID$("{8F10CC2F-CF0D-42A0-ACBE-E2DE7007384D}")
$IID_IDot11AdHocManager = GUID$("{8F10CC26-CF0D-42A0-ACBE-E2DE7007384D}")
$IID_IDot11AdHocManagerNotificationSink = GUID$("{8F10CC27-CF0D-42a0-ACBE-E2DE7007384D}")
$IID_IDot11AdHocNetwork = GUID$("{8F10CC29-CF0D-42A0-ACBE-E2DE7007384D}")
$IID_IDot11AdHocNetworkNotificationSink = GUID$("{8F10CC2A-CF0D-42A0-ACBE-E2DE7007384D}")
$IID_IDot11AdHocSecuritySettings = GUID$("{8F10CC2E-CF0D-42A0-ACBE-E2DE7007384D}")
$IID_IEnumDot11AdHocInterfaces = GUID$("{8F10CC2C-CF0D-42A0-ACBE-E2DE7007384D}")
$IID_IEnumDot11AdHocNetworks = GUID$("{8F10CC28-CF0D-42A0-ACBE-E2DE7007384D}")
$IID_IEnumDot11AdHocSecuritySettings = GUID$("{8F10CC2D-CF0D-42A0-ACBE-E2DE7007384D}")

' ========================================================================================
' enum DOT11_ADHOC_CIPHER_ALGORITHM
' ========================================================================================

MACRO DOT11_ADHOC_CIPHER_ALGORITHM_ENUM = LONG
%DOT11_ADHOC_CIPHER_ALGO_INVALID                    = -1
%DOT11_ADHOC_CIPHER_ALGO_NONE                       = 0
%DOT11_ADHOC_CIPHER_ALGO_CCMP                       = &H4
%DOT11_ADHOC_CIPHER_ALGO_WEP                        = &H101

' ========================================================================================
' enum DOT11_ADHOC_AUTH_ALGORITHM
' ========================================================================================

MACRO DOT11_ADHOC_AUTH_ALGORITHM_ENUM = LONG
%DOT11_ADHOC_AUTH_ALGO_INVALID                      = -1
%DOT11_ADHOC_AUTH_ALGO_80211_OPEN                   = 1
%DOT11_ADHOC_AUTH_ALGO_RSNA_PSK                     = 7

' ========================================================================================
' enum DOT11_ADHOC_NETWORK_CONNECTION_STATUS
' ========================================================================================

MACRO DOT11_ADHOC_NETWORK_CONNECTION_STATUS_ENUM = LONG
%DOT11_ADHOC_NETWORK_CONNECTION_STATUS_INVALID      = 0
%DOT11_ADHOC_NETWORK_CONNECTION_STATUS_DISCONNECTED = 11
%DOT11_ADHOC_NETWORK_CONNECTION_STATUS_CONNECTING   = 12
%DOT11_ADHOC_NETWORK_CONNECTION_STATUS_CONNECTED    = 13
%DOT11_ADHOC_NETWORK_CONNECTION_STATUS_FORMED       = 14

' ========================================================================================
' enum DOT11_ADHOC_CONNECT_FAIL_REASON
' ========================================================================================

MACRO DOT11_ADHOC_CONNECT_FAIL_REASON_ENUM = LONG
%DOT11_ADHOC_CONNECT_FAIL_DOMAIN_MISMATCH           = 0
%DOT11_ADHOC_CONNECT_FAIL_PASSPHRASE_MISMATCH       = 1
%DOT11_ADHOC_CONNECT_FAIL_OTHER                     = 2

' ########################################################################################
' IDot11AdHocManager interface
' IID = 8F10CC26-CF0D-42A0-ACBE-E2DE7007384D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDot11AdHocManager_INTERFACE_DEFINED)
    %IDot11AdHocManager_INTERFACE_DEFINED = 1

INTERFACE IDot11AdHocManager $IID_IDot11AdHocManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateNetwork ( _                             ' VTable offset = 12
     BYREF Name AS WSTRINGZ _                           ' __in LPCWSTR Name
   , BYREF Password AS WSTRINGZ _                       ' __in LPCWSTR Password
   , BYVAL GeographicalId AS LONG _                     ' __in LONG GeographicalId
   , BYVAL pInterface AS IDot11AdHocInterface _         ' __in IDot11AdHocInterface *pInterface
   , BYVAL pSecurity AS IDot11AdHocSecuritySettings _   ' __in IDot11AdHocSecuritySettings *pSecurity
   , BYREF pContextGuid AS GUID _                       ' __in GUID *pContextGuid
   , BYREF pIAdHoc AS IDot11AdHocNetwork _              ' __out IDot11AdHocNetwork **pIAdHoc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CommitCreatedNetwork ( _                      ' VTable offset = 16
     BYVAL pIAdHoc AS IDot11AdHocNetwork _              ' __in IDot11AdHocNetwork *pIAdHoc
   , BYVAL fSaveProfile AS BYTE _                       ' __in BOOLEAN fSaveProfile
   , BYVAL fMakeSavedProfileUserSpecific AS BYTE _      ' __in BOOLEAN fMakeSavedProfileUserSpecific
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIEnumDot11AdHocNetworks ( _                ' VTable offset = 20
     BYREF pContextGuid AS GUID _                       ' __in GUID *pContextGuid
   , BYREF ppEnum AS IEnumDot11AdHocNetworks _          ' __out IEnumDot11AdHocNetworks **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIEnumDot11AdHocInterfaces ( _              ' VTable offset = 24
     BYREF ppEnum AS IEnumDot11AdHocInterfaces _        ' __out IEnumDot11AdHocInterfaces **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNetwork ( _                                ' VTable offset = 28
     BYREF NetworkSignature AS GUID _                   ' __in GUID *NetworkSignature
   , BYREF pNetwork AS IDot11AdHocNetwork _             ' __out IDot11AdHocNetwork **pNetwork
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDot11AdHocManager_INTERFACE_DEFINED__ */

' ########################################################################################
' IDot11AdHocManagerNotificationSink interface
' IID = 8F10CC27-CF0D-42a0-ACBE-E2DE7007384D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDot11AdHocManagerNotificationSink_INTERFACE_DEFINED)
    %IDot11AdHocManagerNotificationSink_INTERFACE_DEFINED = 1

INTERFACE IDot11AdHocManagerNotificationSink $IID_IDot11AdHocManagerNotificationSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnNetworkAdd ( _                              ' VTable offset = 12
     BYVAL pIAdHocNetwork AS IDot11AdHocNetwork _       ' __in IDot11AdHocNetwork *pIAdHocNetwork
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnNetworkRemove ( _                           ' VTable offset = 16
     BYREF Signature AS GUID _                          ' __in GUID *Signature
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnInterfaceAdd ( _                            ' VTable offset = 20
     BYVAL pIAdHocInterface AS IDot11AdHocInterface _   ' __in IDot11AdHocInterface *pIAdHocInterface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnInterfaceRemove ( _                         ' VTable offset = 24
     BYREF Signature AS GUID _                          ' __in GUID *Signature
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDot11AdHocManagerNotificationSink_INTERFACE_DEFINED__ */

' ########################################################################################
' IEnumDot11AdHocNetworks interface
' IID = 8F10CC28-CF0D-42A0-ACBE-E2DE7007384D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumDot11AdHocNetworks_INTERFACE_DEFINED)
    %IEnumDot11AdHocNetworks_INTERFACE_DEFINED = 1

INTERFACE IEnumDot11AdHocNetworks $IID_IEnumDot11AdHocNetworks

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cElt AS DWORD _                              ' __in ULONG cElt
   , BYREF rgElt AS IDot11AdHocNetwork _                ' __out IDot11AdHocNetwork **rgElt
   , BYREF pcEltFetched AS DWORD _                      ' __out ULONG *pcEltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cElt AS DWORD _                              ' __in ULONG cElt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumDot11AdHocNetworks _          ' __out IEnumDot11AdHocNetworks **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumDot11AdHocNetworks_INTERFACE_DEFINED__ */

' ########################################################################################
' IDot11AdHocNetwork interface
' IID = 8F10CC29-CF0D-42A0-ACBE-E2DE7007384D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDot11AdHocNetwork_INTERFACE_DEFINED)
    %IDot11AdHocNetwork_INTERFACE_DEFINED = 1

INTERFACE IDot11AdHocNetwork $IID_IDot11AdHocNetwork

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 12
     BYREF eStatus AS DOT11_ADHOC_NETWORK_CONNECTION_STATUS_ENUM _ ' __inout DOT11_ADHOC_NETWORK_CONNECTION_STATUS *eStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSSID ( _                                   ' VTable offset = 16
     BYREF ppszwSSID AS DWORD _                         ' __out LPWSTR *ppszwSSID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HasProfile ( _                                ' VTable offset = 20
     BYREF pf11d AS BYTE _                              ' __inout BOOLEAN *pf11d
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProfileName ( _                            ' VTable offset = 24
     BYREF ppszwProfileName AS DWORD _                  ' __out LPWSTR *ppszwProfileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteProfile ( _                             ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSignalQuality ( _                          ' VTable offset = 32
     BYREF puStrengthValue AS DWORD _                   ' __out ULONG *puStrengthValue
   , BYREF puStrengthMax AS DWORD _                     ' __out ULONG *puStrengthMax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSecuritySetting ( _                        ' VTable offset = 36
     BYREF pAdHocSecuritySetting AS IDot11AdHocSecuritySettings _ ' __out IDot11AdHocSecuritySettings **pAdHocSecuritySetting
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContextGuid ( _                            ' VTable offset = 40
     BYREF pContextGuid AS GUID _                       ' __inout GUID *pContextGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSignature ( _                              ' VTable offset = 44
     BYREF pSignature AS GUID _                         ' __inout GUID *pSignature
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInterface ( _                              ' VTable offset = 48
     BYREF pAdHocInterface AS IDot11AdHocInterface _    ' __out IDot11AdHocInterface **pAdHocInterface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Connect ( _                                   ' VTable offset = 52
     BYREF Passphrase AS WSTRINGZ _                     ' __in LPCWSTR Passphrase
   , BYVAL GeographicalId AS LONG _                     ' __in LONG GeographicalId
   , BYVAL fSaveProfile AS BYTE _                       ' __in BOOLEAN fSaveProfile
   , BYVAL fMakeSavedProfileUserSpecific AS BYTE _      ' __in BOOLEAN fMakeSavedProfileUserSpecific
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Disconnect ( _                                ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDot11AdHocNetwork_INTERFACE_DEFINED__ */

' ########################################################################################
' IDot11AdHocNetworkNotificationSink interface
' IID = 8F10CC2A-CF0D-42A0-ACBE-E2DE7007384D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDot11AdHocNetworkNotificationSink_INTERFACE_DEFINED)
    %IDot11AdHocNetworkNotificationSink_INTERFACE_DEFINED = 1

INTERFACE IDot11AdHocNetworkNotificationSink $IID_IDot11AdHocNetworkNotificationSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnStatusChange ( _                            ' VTable offset = 12
     BYVAL eStatus AS DOT11_ADHOC_NETWORK_CONNECTION_STATUS_ENUM _ ' __in DOT11_ADHOC_NETWORK_CONNECTION_STATUS eStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnConnectFail ( _                             ' VTable offset = 16
     BYVAL eFailReason AS DOT11_ADHOC_CONNECT_FAIL_REASON_ENUM _ ' __in DOT11_ADHOC_CONNECT_FAIL_REASON eFailReason
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDot11AdHocNetworkNotificationSink_INTERFACE_DEFINED__ */

' ########################################################################################
' IDot11AdHocInterface interface
' IID = 8F10CC2B-CF0D-42A0-ACBE-E2DE7007384D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDot11AdHocInterface_INTERFACE_DEFINED)
    %IDot11AdHocInterface_INTERFACE_DEFINED = 1

INTERFACE IDot11AdHocInterface $IID_IDot11AdHocInterface

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDeviceSignature ( _                        ' VTable offset = 12
     BYREF pSignature AS GUID _                         ' __inout GUID *pSignature
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFriendlyName ( _                           ' VTable offset = 16
     BYREF ppszName AS DWORD _                          ' __out LPWSTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDot11d ( _                                  ' VTable offset = 20
     BYREF pf11d AS BYTE _                              ' __inout BOOLEAN *pf11d
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsAdHocCapable ( _                            ' VTable offset = 24
     BYREF pfAdHocCapable AS BYTE _                     ' __inout BOOLEAN *pfAdHocCapable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsRadioOn ( _                                 ' VTable offset = 28
     BYREF pfIsRadioOn AS BYTE _                        ' __inout BOOLEAN *pfIsRadioOn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActiveNetwork ( _                          ' VTable offset = 32
     BYREF ppNetwork AS IDot11AdHocNetwork _            ' __out IDot11AdHocNetwork **ppNetwork
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIEnumSecuritySettings ( _                  ' VTable offset = 36
     BYREF ppEnum AS IEnumDot11AdHocSecuritySettings _  ' __out IEnumDot11AdHocSecuritySettings **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIEnumDot11AdHocNetworks ( _                ' VTable offset = 40
     BYREF pFilterGuid AS GUID _                        ' __in GUID *pFilterGuid
   , BYREF ppEnum AS IEnumDot11AdHocNetworks _          ' __out IEnumDot11AdHocNetworks **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 44
     BYREF pState AS DOT11_ADHOC_NETWORK_CONNECTION_STATUS_ENUM _ ' __inout DOT11_ADHOC_NETWORK_CONNECTION_STATUS *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDot11AdHocInterface_INTERFACE_DEFINED__ */

' ########################################################################################
' IEnumDot11AdHocInterfaces interface
' IID = 8F10CC2C-CF0D-42a0-ACBE-E2DE7007384D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumDot11AdHocInterfaces_INTERFACE_DEFINED)
    %IEnumDot11AdHocInterfaces_INTERFACE_DEFINED = 1

INTERFACE IEnumDot11AdHocInterfaces $IID_IEnumDot11AdHocInterfaces

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cElt AS DWORD _                              ' __in ULONG cElt
   , BYREF rgElt AS IDot11AdHocInterface _              ' __out IDot11AdHocInterface **rgElt
   , BYREF pcEltFetched AS DWORD _                      ' __out ULONG *pcEltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cElt AS DWORD _                              ' __in ULONG cElt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumDot11AdHocInterfaces _        ' __out IEnumDot11AdHocInterfaces **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumDot11AdHocInterfaces_INTERFACE_DEFINED__ */

' ########################################################################################
' IEnumDot11AdHocSecuritySettings interface
' IID = 8F10CC2D-CF0D-42a0-ACBE-E2DE7007384D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumDot11AdHocSecuritySettings_INTERFACE_DEFINED)
    %IEnumDot11AdHocSecuritySettings_INTERFACE_DEFINED = 1

INTERFACE IEnumDot11AdHocSecuritySettings $IID_IEnumDot11AdHocSecuritySettings

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cElt AS DWORD _                              ' __in ULONG cElt
   , BYREF rgElt AS IDot11AdHocSecuritySettings _       ' __out IDot11AdHocSecuritySettings **rgElt
   , BYREF pcEltFetched AS DWORD _                      ' __out ULONG *pcEltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cElt AS DWORD _                              ' __in ULONG cElt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumDot11AdHocSecuritySettings _  ' __out IEnumDot11AdHocSecuritySettings **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumDot11AdHocSecuritySettings_INTERFACE_DEFINED__ */

' ########################################################################################
' IDot11AdHocSecuritySettings interface
' IID = 8F10CC2E-CF0D-42A0-ACBE-E2DE7007384D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDot11AdHocSecuritySettings_INTERFACE_DEFINED)
    %IDot11AdHocSecuritySettings_INTERFACE_DEFINED = 1

INTERFACE IDot11AdHocSecuritySettings $IID_IDot11AdHocSecuritySettings

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDot11AuthAlgorithm ( _                     ' VTable offset = 12
     BYREF pAuth AS DOT11_ADHOC_AUTH_ALGORITHM_ENUM _   ' __inout DOT11_ADHOC_AUTH_ALGORITHM *pAuth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDot11CipherAlgorithm ( _                   ' VTable offset = 16
     BYREF pCipher AS DOT11_ADHOC_CIPHER_ALGORITHM_ENUM _ ' __inout DOT11_ADHOC_CIPHER_ALGORITHM *pCipher
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDot11AdHocSecuritySettings_INTERFACE_DEFINED__ */

' ########################################################################################
' IDot11AdHocInterfaceNotificationSink interface
' IID = 8F10CC2F-CF0D-42A0-ACBE-E2DE7007384D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDot11AdHocInterfaceNotificationSink_INTERFACE_DEFINED)
    %IDot11AdHocInterfaceNotificationSink_INTERFACE_DEFINED = 1

INTERFACE IDot11AdHocInterfaceNotificationSink $IID_IDot11AdHocInterfaceNotificationSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnConnectionStatusChange ( _                  ' VTable offset = 12
     BYVAL eStatus AS DOT11_ADHOC_NETWORK_CONNECTION_STATUS_ENUM _ ' __in DOT11_ADHOC_NETWORK_CONNECTION_STATUS eStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDot11AdHocInterfaceNotificationSink_INTERFACE_DEFINED__ */
