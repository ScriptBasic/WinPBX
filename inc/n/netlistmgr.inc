' ########################################################################################
' Microsoft Windows
' File: netlistmgr.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: NETWORKLIST
' Version: 1.0, Locale ID = 0
' Description: Network List Manager 1.0 Type Library
' Documentation string: Network List 1.0 Type Library
' Path: C:\Windows\system32\netprofm.dll
' Library GUID: {DCB00D01-570F-4A9B-8D69-199FDBA5723B}
' ########################################################################################

#INCLUDE THIS ONCE
%NETLISTMGR_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

$$NA_DomainAuthenticationFailed  = "NA_DomainAuthenticationFailed"$$
$$NA_NetworkClass                = "NA_NetworkClass"$$
$$NA_NameSetByPolicy             = "NA_NameSetByPolicy"$$
$$NA_IconSetByPolicy             = "NA_IconSetByPolicy"$$
$$NA_DescriptionSetByPolicy      = "NA_DescriptionSetByPolicy"$$
$$NA_CategorySetByPolicy         = "NA_CategorySetByPolicy"$$
$$NA_NameReadOnly                = "NA_NameReadOnly"$$
$$NA_IconReadOnly                = "NA_IconReadOnly"$$
$$NA_DescriptionReadOnly         = "NA_DescriptionReadOnly"$$
$$NA_CategoryReadOnly            = "NA_CategoryReadOnly"$$
$$NA_AllowMerge                  = "NA_AllowMerge"$$
$$NA_InternetConnectivityV4      = "NA_InternetConnectivityV4"$$
$$NA_InternetConnectivityV6      = "NA_InternetConnectivityV6"$$

' enum NLM_NETWORK_CLASS
%NLM_NETWORK_IDENTIFYING  = &H1???
%NLM_NETWORK_IDENTIFIED   = &H2???
%NLM_NETWORK_UNIDENTIFIED = &H3???

' enum NLM_INTERNET_CONNECTIVITY
%NLM_INTERNET_CONNECTIVITY_WEBHIJACK = &H1???
%NLM_INTERNET_CONNECTIVITY_PROXIED   = &H2???
%NLM_INTERNET_CONNECTIVITY_CORPORATE = &H4???

' enum NLM_CONNECTIVITY
%NLM_CONNECTIVITY_DISCONNECTED      = 0???
%NLM_CONNECTIVITY_IPV4_NOTRAFFIC    = &H1???
%NLM_CONNECTIVITY_IPV6_NOTRAFFIC    = &H2???
%NLM_CONNECTIVITY_IPV4_SUBNET       = &H10???
%NLM_CONNECTIVITY_IPV4_LOCALNETWORK = &H20???
%NLM_CONNECTIVITY_IPV4_INTERNET     = &H40???
%NLM_CONNECTIVITY_IPV6_SUBNET       = &H100???
%NLM_CONNECTIVITY_IPV6_LOCALNETWORK = &H200???
%NLM_CONNECTIVITY_IPV6_INTERNET     = &H400???

' enum NLM_DOMAIN_TYPE
%NLM_DOMAIN_TYPE_NON_DOMAIN_NETWORK   = 0???
%NLM_DOMAIN_TYPE_DOMAIN_NETWORK       = &H1???
%NLM_DOMAIN_TYPE_DOMAIN_AUTHENTICATED = &H2???

$LIBID_NETWORKLIST = GUID$("{DCB00D01-570F-4A9B-8D69-199FDBA5723B}")
$CLSID_NetworkListManager = GUID$("{DCB00C01-570F-4A9B-8D69-199FDBA5723B}")

' ########################################################################################
' Interface name = INetworkListManager
' IID = {DCB00000-570F-4A9B-8D69-199FDBA5723B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetworkListManager_INTERFACE_DEFINED)
    %INetworkListManager_INTERFACE_DEFINED = 1

' enum NLM_ENUM_NETWORK
%NLM_ENUM_NETWORK_CONNECTED    = &H1???
%NLM_ENUM_NETWORK_DISCONNECTED = &H2???
%NLM_ENUM_NETWORK_ALL          = &H3???

$IID_INetworkListManager = GUID$("{DCB00000-570F-4A9B-8D69-199FDBA5723B}")

INTERFACE INetworkListManager $IID_INetworkListManager

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetNetworks <1> ( _                           ' VTable offset = 28
     BYVAL Flags AS DWORD _                             ' __in NLM_ENUM_NETWORK Flags
   ) AS IEnumNetworks                                   ' __retval_out IEnumNetworks **ppEnumNetwork
   ' =====================================================================================
   METHOD GetNetwork <2> ( _                            ' VTable offset = 32
     BYVAL gdNetworkId AS GUID _                        ' __in GUID gdNetworkId
   ) AS INetwork                                        ' __retval_out INetwork** ppNetwork
   ' =====================================================================================
   METHOD GetNetworkConnections <3> ( _                 ' VTable offset = 36
   ) AS IEnumNetworkConnections                         ' __retval_out IEnumNetworkConnections **ppEnum
   ' =====================================================================================
   METHOD GetNetworkConnection <4> ( _                  ' VTable offset = 40
     BYVAL gdNetworkConnectionId AS GUID _              ' __in GUID gdNetworkConnectionId
   ) AS INetworkConnection                              ' __retval_out INetworkConnection **ppNetworkConnection
   ' =====================================================================================
   PROPERTY GET IsConnectedToInternet <5> ( _           ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIsConnected
   ' =====================================================================================
   PROPERTY GET IsConnected <6> ( _                     ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIsConnected
   ' =====================================================================================
   METHOD GetConnectivity <7> ( _                       ' VTable offset = 52
   ) AS DWORD                                           ' __retval_out NLM_CONNECTIVITY *pConnectivity
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetworkListManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INetworkListManagerEvents
' IID = DCB00001-570F-4A9B-8D69-199FDBA5723B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%INetworkListManagerEvents_INTERFACE_DEFINED)
    %INetworkListManagerEvents_INTERFACE_DEFINED = 1

$IID_INetworkListManagerEvents = GUID$("{DCB00001-570F-4A9B-8D69-199FDBA5723B}")

'INTERFACE INetworkListManagerEvents $IID_INetworkListManagerEvents

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD ConnectivityChanged ( _
'     BYVAL DWORD _                                      ' __in NLM_CONNECTIVITY newConnectivity
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE

#ENDIF   ' /* __INetworkListManagerEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INetwork
' IID = {DCB00002-570F-4A9B-8D69-199FDBA5723B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetwork_INTERFACE_DEFINED)
    %INetwork_INTERFACE_DEFINED = 1

' enum NLM_NETWORK_CATEGORY
%NLM_NETWORK_CATEGORY_PUBLIC               = 0???
%NLM_NETWORK_CATEGORY_PRIVATE              = &H1???
%NLM_NETWORK_CATEGORY_DOMAIN_AUTHENTICATED = &H2???

$IID_INetwork = GUID$("{DCB00002-570F-4A9B-8D69-199FDBA5723B}")

INTERFACE INetwork $IID_INetwork

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetName <1> ( _                               ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pszNetworkName
   ' =====================================================================================
   METHOD SetName <2> ( _                               ' VTable offset = 32
     BYVAL szNetworkNewName AS WSTRING _                ' __in BSTR szNetworkNewName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDescription <3> ( _                        ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pszDescription
   ' =====================================================================================
   METHOD SetDescription <4> ( _                        ' VTable offset = 40
     BYVAL szDescription AS WSTRING _                   ' __in BSTR szDescription
   )                                                    ' void
   ' =====================================================================================
   METHOD GetNetworkId <5> ( _                          ' VTable offset = 44
   ) AS GUID                                            ' __retval_out GUID* pgdGuidNetworkId
   ' =====================================================================================
   METHOD GetDomainType <6> ( _                         ' VTable offset = 48
   ) AS DWORD                                           ' __retval_out NLM_DOMAIN_TYPE *pNetworkType
   ' =====================================================================================
   METHOD GetNetworkConnections <7> ( _                 ' VTable offset = 52
   ) AS IEnumNetworkConnections                         ' __retval_out IEnumNetworkConnections **ppEnumNetworkConnection
   ' =====================================================================================
   METHOD GetTimeCreatedAndConnected <8> ( _            ' VTable offset = 56
     BYREF pdwLowDateTimeCreated AS DWORD _             ' __out DWORD *pdwLowDateTimeCreated
   , BYREF pdwHighDateTimeCreated AS DWORD _            ' __out DWORD *pdwHighDateTimeCreated
   , BYREF pdwLowDateTimeConnected AS DWORD _           ' __out DWORD *pdwLowDateTimeConnected
   , BYREF pdwHighDateTimeConnected AS DWORD _          ' __out DWORD *pdwHighDateTimeConnected
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsConnectedToInternet <9> ( _           ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIsConnected
   ' =====================================================================================
   PROPERTY GET IsConnected <10> ( _                    ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIsConnected
   ' =====================================================================================
   METHOD GetConnectivity <11> ( _                      ' VTable offset = 68
   ) AS DWORD                                           ' __retval_out NLM_CONNECTIVITY *pConnectivity
   ' =====================================================================================
   METHOD GetCategory <12> ( _                          ' VTable offset = 72
   ) AS DWORD                                           ' __retval_out NLM_NETWORK_CATEGORY *pCategory
   ' =====================================================================================
   METHOD SetCategory <13> ( _                          ' VTable offset = 76
     BYVAL NewCategory AS DWORD _                       ' __in NLM_NETWORK_CATEGORY NewCategory
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetwork_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumNetworks
' IID = {DCB00003-570F-4A9B-8D69-199FDBA5723B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEnumNetworks_INTERFACE_DEFINED)
    %IEnumNetworks_INTERFACE_DEFINED = 1

$IID_IEnumNetworks = GUID$("{DCB00003-570F-4A9B-8D69-199FDBA5723B}")

INTERFACE IEnumNetworks $IID_IEnumNetworks

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **ppEnumVar
   ' =====================================================================================
   METHOD Next <1> ( _                                  ' VTable offset = 32
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS INetwork _                          ' __out INetwork **rgelt
   , BYREF pceltFetched AS DWORD _                      ' __in_out ULONG *pceltFetched
   )                                                    ' void
   ' =====================================================================================
   METHOD Skip <2> ( _                                  ' VTable offset = 36
     BYVAL celt AS DWORD _                                      ' __in ULONG celt
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset <3> ( _                                 ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <4> ( _                                 ' VTable offset = 44
   ) AS IEnumNetworks                                   ' __retval_out IEnumNetworks **ppEnumNetwork
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumNetworks_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INetworkEvents
' IID = DCB00004-570F-4A9B-8D69-199FDBA5723B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%INetworkEvents_INTERFACE_DEFINED)
    %INetworkEvents_INTERFACE_DEFINED = 1

' enum NLM_NETWORK_PROPERTY_CHANGE
%NLM_NETWORK_PROPERTY_CHANGE_CONNECTION     = &H1???
%NLM_NETWORK_PROPERTY_CHANGE_DESCRIPTION    = &H2???
%NLM_NETWORK_PROPERTY_CHANGE_NAME           = &H4???
%NLM_NETWORK_PROPERTY_CHANGE_ICON           = &H8???
%NLM_NETWORK_PROPERTY_CHANGE_CATEGORY_VALUE = &H10???

$IID_INetworkEvents = GUID$("{DCB00004-570F-4A9B-8D69-199FDBA5723B}")

'INTERFACE INetworkEvents $IID_INetworkEvents

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD NetworkAdded ( _
'     BYVAL GUID _                                       ' __in GUID networkId
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD NetworkDeleted ( _
'     BYVAL GUID _                                       ' __in GUID networkId
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD NetworkConnectivityChanged ( _
'     BYVAL networkId AS GUID _                          ' __in GUID networkId
'   , BYVAL newConnectivity AS DWORD _                   ' __in NLM_CONNECTIVITY newConnectivity
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD NetworkPropertyChanged ( _
'     BYVAL networkId AS GUID _                          ' __in GUID networkId
'   , BYVAL flags AS DWORD _                             ' __in NLM_NETWORK_PROPERTY_CHANGE flags
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE

#ENDIF   ' /* __INetworkEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INetworkConnection
' IID = {DCB00005-570F-4A9B-8D69-199FDBA5723B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetworkConnection_INTERFACE_DEFINED)
    %INetworkConnection_INTERFACE_DEFINED = 1

$IID_INetworkConnection = GUID$("{DCB00005-570F-4A9B-8D69-199FDBA5723B}")

INTERFACE INetworkConnection $IID_INetworkConnection

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetNetwork <1> ( _                            ' VTable offset = 28
   ) AS INetwork                                        ' __retval_out INetwork **ppNetwork
   ' =====================================================================================
   PROPERTY GET IsConnectedToInternet <2> ( _           ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIsConnected
   ' =====================================================================================
   PROPERTY GET IsConnected <3> ( _                     ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbIsConnected
   ' =====================================================================================
   METHOD GetConnectivity <4> ( _                       ' VTable offset = 40
   ) AS DWORD                                           ' __retval_out NLM_CONNECTIVITY *pConnectivity
   ' =====================================================================================
   METHOD GetConnectionId <5> ( _                       ' VTable offset = 44
   ) AS GUID                                            ' __retval_out GUID *pgdConnectionId
   ' =====================================================================================
   METHOD GetAdapterId <6> ( _                          ' VTable offset = 48
   ) AS GUID                                            ' __retval_out GUID *pgdAdapterId
   ' =====================================================================================
   METHOD GetDomainType <7> ( _                         ' VTable offset = 52
   ) AS DWORD                                           ' __retval_out NLM_DOMAIN_TYPE *pDomainType
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetworkConnection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumNetworkConnections
' IID = {DCB00006-570F-4A9B-8D69-199FDBA5723B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IEnumNetworkConnections_INTERFACE_DEFINED)
    %IEnumNetworkConnections_INTERFACE_DEFINED = 1

$IID_IEnumNetworkConnections = GUID$("{DCB00006-570F-4A9B-8D69-199FDBA5723B}")

INTERFACE IEnumNetworkConnections $IID_IEnumNetworkConnections

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **ppEnumVar
   ' =====================================================================================
   METHOD Next <1> ( _                                  ' VTable offset = 32
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS INetworkConnection _                ' __out INetworkConnection **rgelt
   , BYREF pceltFetched AS DWORD _                      ' __in_out ULONG *pceltFetched
   )                                                    ' void
   ' =====================================================================================
   METHOD Skip <2> ( _                                  ' VTable offset = 36
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset <3> ( _                                 ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <4> ( _                                 ' VTable offset = 44
   ) AS IEnumNetworkConnections                         ' __retval_out IEnumNetworkConnections **ppEnumNetwork
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumNetworkConnections_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INetworkConnectionEvents
' IID = DCB00007-570F-4A9B-8D69-199FDBA5723B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%INetworkConnectionEvents_INTERFACE_DEFINED)
    %INetworkConnectionEvents_INTERFACE_DEFINED = 1

' enum NLM_CONNECTION_PROPERTY_CHANGE
%NLM_CONNECTION_PROPERTY_CHANGE_AUTHENTICATION = &H1???

$IID_INetworkConnectionEvents = GUID$("{DCB00007-570F-4A9B-8D69-199FDBA5723B}")

'INTERFACE INetworkConnectionEvents $IID_INetworkConnectionEvents

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD NetworkConnectionConnectivityChanged ( _
'     BYVAL connectionId AS GUID _                       ' __in GUID connectionId
'   , BYVAL newConnectivity AS DWORD _                   ' __in NLM_CONNECTIVITY newConnectivity
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD NetworkConnectionPropertyChanged ( _
'     BYVAL connectionId AS GUID _                       ' __in GUID connectionId
'   , BYVAL flags AS DWORD _                             ' __in NLM_CONNECTION_PROPERTY_CHANGE flags
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE

#ENDIF   ' /* __INetworkConnectionEvents_INTERFACE_DEFINED__ */
