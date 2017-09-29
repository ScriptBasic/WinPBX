' ########################################################################################
' Microsoft Windows
' File: NetFw.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: NetFwTypeLib
' Version: 1.0, Locale ID = 0
' Description: NetFwTypeLib
' Path: C:\WINDOWS\system32\hnetcfg.dll\3 (XP)
' Path: C:\Windows\system32\FirewallAPI.dll (WIN7)
' Library GUID: {58FBCF7C-E7A9-467C-80B3-FC65E8FCCA08}
' ########################################################################################

#INCLUDE THIS ONCE
%NETFW_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "icftypes.inc"
#INCLUDE ONCE "oaidl.inc"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {EC9846B3-2762-4A6B-A214-6ACB603462D2}
$PROGID_NetFwAuthorizedApplication = "HNetCfg.FwAuthorizedApplication"
' CLSID = {304CE942-6E39-40D8-943A-B913C40C9CD4}
$PROGID_NetFwMgr = "HNetCfg.FwMgr"
' CLSID = {0CA545C6-37AD-4A6C-BF92-9F7610067EF5}
$PROGID_NetFwOpenPort = "HNetCfg.FwOpenPort"
' CLSID = {E2B3C97F-6AE1-41AC-817A-F6F92166D7DD}
$PROGID_NetFwPolicy22 = "HNetCfg.FwPolicy2"
' CLSID = {9D745ED8-C514-4D1D-BF42-751FED2D5AC7}
$PROGID_NetFwProduct = "HNetCfg.FwProduct"
' CLSID = {CC19079B-8272-4D73-BB70-CDB533527B61}
$PROGID_NetFwProducts = "HNetCfg.FwProducts"
' CLSID = {2C5BC43E-3369-4C33-AB0C-BE9469677AF4}
$PROGID_NetFwRule = "HNetCfg.FwRule"

' ========================================================================================
' CLSIDs (Class identifiers)
' ========================================================================================

$CLSID_NetFwAuthorizedApplication = GUID$("{EC9846B3-2762-4A6B-A214-6ACB603462D2}")
$CLSID_NetFwMgr = GUID$("{304CE942-6E39-40D8-943A-B913C40C9CD4}")
$CLSID_NetFwOpenPort = GUID$("{0CA545C6-37AD-4A6C-BF92-9F7610067EF5}")
$CLSID_NetFwPolicy2 = GUID$("{E2B3C97F-6AE1-41AC-817A-F6F92166D7DD}")
$CLSID_NetFwProduct = GUID$("{9D745ED8-C514-4D1D-BF42-751FED2D5AC7}")
$CLSID_NetFwProducts = GUID$("{CC19079B-8272-4D73-BB70-CDB533527B61}")
$CLSID_NetFwRule = GUID$("{2C5BC43E-3369-4C33-AB0C-BE9469677AF4}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_INetFwAuthorizedApplication = GUID$("{B5E64FFA-C2C5-444E-A301-FB5E00018050}")
$IID_INetFwAuthorizedApplications = GUID$("{644EFD52-CCF9-486C-97A2-39F352570B30}")
$IID_INetFwIcmpSettings = GUID$("{A6207B2E-7CDD-426A-951E-5E1CBC5AFEAD}")
$IID_INetFwMgr = GUID$("{F7898AF5-CAC4-4632-A2EC-DA06E5111AF2}")
$IID_INetFwOpenPort = GUID$("{E0483BA0-47FF-4D9C-A6D6-7741D0B195F7}")
$IID_INetFwOpenPorts = GUID$("{C0E9D7FA-E07E-430A-B19A-090CE82D92E2}")
$IID_INetFwPolicy = GUID$("{D46D2478-9AC9-4008-9DC7-5563CE5536CC}")
$IID_INetFwPolicy2 = GUID$("{98325047-C671-4174-8D81-DEFCD3F03186}")
$IID_INetFwProduct = GUID$("{71881699-18F4-458B-B892-3FFCE5E07F75}")
$IID_INetFwProducts = GUID$("{39EB36E0-2097-40BD-8AF2-63A13B525362}")
$IID_INetFwProfile = GUID$("{174A0DDA-E9F9-449D-993B-21AB667CA456}")
$IID_INetFwRemoteAdminSettings = GUID$("{D4BECDDF-6F73-4A83-B832-9C66874CD20E}")
$IID_INetFwRule = GUID$("{AF230D27-BABA-4E42-ACED-F524F22CFCE2}")
$IID_INetFwRule2 = GUID$("{9C27C8DA-189B-4DDE-89F7-8B39A316782C}")
$IID_INetFwRules = GUID$("{9C4C6277-5027-441E-AFAE-CA1F542DA009}")
$IID_INetFwService = GUID$("{79FD57C8-908E-4A36-9888-D5B3F0A444CF}")
$IID_INetFwServiceRestriction = GUID$("{8267BBE3-F890-491C-B7B6-2DB1EF0E5D2B}")
$IID_INetFwServices = GUID$("{79649BB4-903E-421B-94C9-79848E79F6EE}")

' ########################################################################################
' Interface name = INetFwRemoteAdminSettings
' IID = {D4BECDDF-6F73-4A83-B832-9C66874CD20E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetFwRemoteAdminSettings_INTERFACE_DEFINED)
    %INetFwRemoteAdminSettings_INTERFACE_DEFINED = 1

INTERFACE INetFwRemoteAdminSettings $IID_INetFwRemoteAdminSettings

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET IpVersion <1> ( _                       ' VTable offset = 28
   ) AS LONG                                            ' __retval_out NET_FW_IP_VERSION *ipVersion
   ' =====================================================================================
   PROPERTY SET IpVersion <1> ( _                       ' VTable offset = 32
     BYVAL ipVersion AS LONG _                          ' __in NET_FW_IP_VERSION ipVersion
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Scope <2> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out NET_FW_SCOPE *scope
   ' =====================================================================================
   PROPERTY SET Scope <2> ( _                           ' VTable offset = 40
     BYVAL scope AS LONG _                              ' __in NET_FW_SCOPE scope
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RemoteAddresses <3> ( _                 ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *remoteAddrs
   ' =====================================================================================
   PROPERTY SET RemoteAddresses <3> ( _                 ' VTable offset = 48
     BYVAL remoteAddrs AS WSTRING _                     ' __in BSTR remoteAddrs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <4> ( _                         ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *enabled
   ' =====================================================================================
   PROPERTY SET Enabled <4> ( _                         ' VTable offset = 56
     BYVAL enabled AS INTEGER _                         ' __in VARIANT_BOOL enabled
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetFwRemoteAdminSettings_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = INetFwIcmpSettings
' IID = {A6207B2E-7CDD-426A-951E-5E1CBC5AFEAD}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetFwIcmpSettings_INTERFACE_DEFINED)
    %INetFwIcmpSettings_INTERFACE_DEFINED = 1

INTERFACE INetFwIcmpSettings $IID_INetFwIcmpSettings

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET AllowOutboundDestinationUnreachable <1> ( _ ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *allow
   ' =====================================================================================
   PROPERTY SET AllowOutboundDestinationUnreachable <1> ( _ ' VTable offset = 32
     BYVAL allow AS INTEGER _                           ' __in VARIANT_BOOL allow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowRedirect <2> ( _                   ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *allow
   ' =====================================================================================
   PROPERTY SET AllowRedirect <2> ( _                   ' VTable offset = 40
     BYVAL allow AS INTEGER _                           ' __in VARIANT_BOOL allow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowInboundEchoRequest <3> ( _         ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *allow
   ' =====================================================================================
   PROPERTY SET AllowInboundEchoRequest <3> ( _         ' VTable offset = 48
     BYVAL allow AS INTEGER _                           ' __in VARIANT_BOOL allow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowOutboundTimeExceeded <4> ( _       ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *allow
   ' =====================================================================================
   PROPERTY SET AllowOutboundTimeExceeded <4> ( _       ' VTable offset = 56
     BYVAL INTEGER _                                    ' __in VARIANT_BOOL allow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowOutboundParameterProblem <5> ( _   ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *allow
   ' =====================================================================================
   PROPERTY SET AllowOutboundParameterProblem <5> ( _   ' VTable offset = 64
     BYVAL allow AS INTEGER _                           ' __in VARIANT_BOOL allow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowOutboundSourceQuench <6> ( _       ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *allow
   ' =====================================================================================
   PROPERTY SET AllowOutboundSourceQuench <6> ( _       ' VTable offset = 72
     BYVAL allow AS INTEGER _                           ' __in VARIANT_BOOL allow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowInboundRouterRequest <7> ( _       ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *allow
   ' =====================================================================================
   PROPERTY SET AllowInboundRouterRequest <7> ( _       ' VTable offset = 80
     BYVAL allow AS INTEGER _                           ' __in VARIANT_BOOL allow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowInboundTimestampRequest <8> ( _    ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *allow
   ' =====================================================================================
   PROPERTY SET AllowInboundTimestampRequest <8> ( _    ' VTable offset = 88
     BYVAL allow AS INTEGER _                           ' __in VARIANT_BOOL allow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowInboundMaskRequest <9> ( _         ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *allow
   ' =====================================================================================
   PROPERTY SET AllowInboundMaskRequest <9> ( _         ' VTable offset = 96
     BYVAL allow AS INTEGER _                           ' __in VARIANT_BOOL allow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowOutboundPacketTooBig <10> ( _      ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *allow
   ' =====================================================================================
   PROPERTY SET AllowOutboundPacketTooBig <10> ( _      ' VTable offset = 104
     BYVAL allow AS INTEGER _                           ' __in VARIANT_BOOL allow
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetFwIcmpSettings_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = INetFwOpenPort
' IID = {E0483BA0-47FF-4D9C-A6D6-7741D0B195F7}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetFwOpenPort_INTERFACE_DEFINED)
    %INetFwOpenPort_INTERFACE_DEFINED = 1

INTERFACE INetFwOpenPort $IID_INetFwOpenPort

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   PROPERTY SET Name <1> ( _                            ' VTable offset = 32
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IpVersion <2> ( _                       ' VTable offset = 36
   ) AS LONG                                            ' __retval_out NET_FW_IP_VERSION *ipVersion
   ' =====================================================================================
   PROPERTY SET IpVersion <2> ( _                       ' VTable offset = 40
     BYVAL ipVersion AS LONG _                          ' __in NET_FW_IP_VERSION ipVersion
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Protocol <3> ( _                        ' VTable offset = 44
   ) AS LONG                                            ' __retval_out NET_FW_IP_PROTOCOL *ipProtocol
   ' =====================================================================================
   PROPERTY SET Protocol <3> ( _                        ' VTable offset = 48
     BYVAL ipProtocol AS LONG _                         ' __in NET_FW_IP_PROTOCOL ipProtocol
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Port <4> ( _                            ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *portNumber
   ' =====================================================================================
   PROPERTY SET Port <4> ( _                            ' VTable offset = 56
     BYVAL portNumber AS LONG _                         ' __in LONG portNumber
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Scope <5> ( _                           ' VTable offset = 60
   ) AS LONG                                            ' __retval_out NET_FW_SCOPE *scope
   ' =====================================================================================
   PROPERTY SET Scope <5> ( _                           ' VTable offset = 64
     BYVAL scope AS LONG _                              ' __in NET_FW_SCOPE scope
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RemoteAddresses <6> ( _                 ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *remoteAddrs
   ' =====================================================================================
   PROPERTY SET RemoteAddresses <6> ( _                 ' VTable offset = 72
     BYVAL remoteAddrs AS WSTRING _                     ' __in BSTR remoteAddrs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <7> ( _                         ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *enabled
   ' =====================================================================================
   PROPERTY SET Enabled <7> ( _                         ' VTable offset = 80
     BYVAL enabled AS INTEGER _                         ' __in VARIANT_BOOL enabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BuiltIn <8> ( _                         ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *builtIn
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetFwOpenPort_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = INetFwOpenPorts
' IID = {C0E9D7FA-E07E-430A-B19A-090CE82D92E2}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetFwOpenPorts_INTERFACE_DEFINED)
    %INetFwOpenPorts_INTERFACE_DEFINED = 1

INTERFACE INetFwOpenPorts $IID_INetFwOpenPorts

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *count
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 32
     BYVAL port AS INetFwOpenPort _                     ' __in INetFwOpenPort *port
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 36
     BYVAL portNumber AS LONG _                         ' __in LONG portNumber
   , BYVAL ipProtocol AS LONG _                         ' __in NET_FW_IP_PROTOCOL ipProtocol
   )                                                    ' void
   ' =====================================================================================
   METHOD Item <4> ( _                                  ' VTable offset = 40
     BYVAL portNumber AS LONG _                         ' __in LONG portNumber
   , BYVAL ipProtocol AS LONG _                         ' __in NET_FW_IP_PROTOCOL ipProtocol
   ) AS INetFwOpenPort                                  ' __retval_out INetFwOpenPort **openPort
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 44
   ) AS IUnknown                                        ' __retval_out IUnknown **newEnum
   ' =====================================================================================

END INTERFACE


#ENDIF   ' /* __INetFwOpenPorts_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = INetFwService
' IID = {79FD57C8-908E-4A36-9888-D5B3F0A444CF}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetFwService_INTERFACE_DEFINED)
    %INetFwService_INTERFACE_DEFINED = 1

INTERFACE INetFwService $IID_INetFwService

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   PROPERTY GET Type <2> ( _                            ' VTable offset = 32
   ) AS LONG                                            ' __retval_out NET_FW_SERVICE_TYPE *type
   ' =====================================================================================
   PROPERTY GET Customized <3> ( _                      ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *customized
   ' =====================================================================================
   PROPERTY GET IpVersion <4> ( _                       ' VTable offset = 40
   ) AS LONG                                            ' __retval_out NET_FW_IP_VERSION *ipVersion
   ' =====================================================================================
   PROPERTY SET IpVersion <4> ( _                       ' VTable offset = 44
     BYVAL ipVersion AS LONG _                          ' __in NET_FW_IP_VERSION ipVersion
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Scope <5> ( _                           ' VTable offset = 48
   ) AS LONG                                            ' __retval_out NET_FW_SCOPE *scope
   ' =====================================================================================
   PROPERTY SET Scope <5> ( _                           ' VTable offset = 52
     BYVAL scope AS LONG _                              ' __in NET_FW_SCOPE scope
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RemoteAddresses <6> ( _                 ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *remoteAddrs
   ' =====================================================================================
   PROPERTY SET RemoteAddresses <6> ( _                 ' VTable offset = 60
     BYVAL remoteAddrs AS WSTRING _                     ' __in BSTR remoteAddrs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <7> ( _                         ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *enabled
   ' =====================================================================================
   PROPERTY SET Enabled <7> ( _                         ' VTable offset = 68
     BYVAL enabled AS INTEGER _                         ' __in VARIANT_BOOL enabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GloballyOpenPorts <8> ( _               ' VTable offset = 72
   ) AS INetFwOpenPorts                                 ' __retval_out INetFwOpenPorts **openPorts
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetFwService_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = INetFwServices
' IID = {79649BB4-903E-421B-94C9-79848E79F6EE}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetFwServices_INTERFACE_DEFINED)
    %INetFwServices_INTERFACE_DEFINED = 1

INTERFACE INetFwServices $IID_INetFwServices

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *count
   ' =====================================================================================
   METHOD Item <2> ( _                                  ' VTable offset = 32
     BYVAL svcType AS LONG _                            ' __in NET_FW_SERVICE_TYPE svcType
   ) AS INetFwService                                   ' __retval_out INetFwService **service
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **newEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetFwServices_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = INetFwAuthorizedApplication
' IID = {B5E64FFA-C2C5-444E-A301-FB5E00018050}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetFwAuthorizedApplication_INTERFACE_DEFINED)
    %INetFwAuthorizedApplication_INTERFACE_DEFINED = 1

INTERFACE INetFwAuthorizedApplication $IID_INetFwAuthorizedApplication

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   PROPERTY SET Name <1> ( _                            ' VTable offset = 32
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProcessImageFileName <2> ( _            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *imageFileName
   ' =====================================================================================
   PROPERTY SET ProcessImageFileName <2> ( _            ' VTable offset = 40
     BYVAL imageFileName AS WSTRING _                   ' __in BSTR imageFileName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IpVersion <3> ( _                       ' VTable offset = 44
   ) AS LONG                                            ' __retval_out NET_FW_IP_VERSION *ipVersion
   ' =====================================================================================
   PROPERTY SET IpVersion <3> ( _                       ' VTable offset = 48
     BYVAL ipVersion AS LONG _                          ' __in NET_FW_IP_VERSION ipVersion
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Scope <4> ( _                           ' VTable offset = 52
   ) AS LONG                                            ' __retval_out NET_FW_SCOPE *scope
   ' =====================================================================================
   PROPERTY SET Scope <4> ( _                           ' VTable offset = 56
     BYVAL scope AS LONG _                              ' __in NET_FW_SCOPE scope
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RemoteAddresses <5> ( _                 ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *remoteAddrs
   ' =====================================================================================
   PROPERTY SET RemoteAddresses <5> ( _                 ' VTable offset = 64
     BYVAL remoteAddrs AS WSTRING _                     ' __in BSTR remoteAddrs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <6> ( _                         ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *enabled
   ' =====================================================================================
   PROPERTY SET Enabled <6> ( _                         ' VTable offset = 72
     BYVAL enabled AS INTEGER _                         ' __in VARIANT_BOOL enabled
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetFwAuthorizedApplication_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = INetFwAuthorizedApplications
' IID = {644EFD52-CCF9-486C-97A2-39F352570B30}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetFwAuthorizedApplications_INTERFACE_DEFINED)
    %INetFwAuthorizedApplications_INTERFACE_DEFINED = 1

INTERFACE INetFwAuthorizedApplications $IID_INetFwAuthorizedApplications

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *count
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 32
     BYVAL app AS INetFwAuthorizedApplication _         ' __in INetFwAuthorizedApplication *app
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 36
     BYVAL imageFileName AS WSTRING _                   ' __in BSTR imageFileName
   )                                                    ' void
   ' =====================================================================================
   METHOD Item <4> ( _                                  ' VTable offset = 40
     BYVAL imageFileName AS WSTRING _                   ' __in BSTR imageFileName
   ) AS INetFwAuthorizedApplication                     ' __retval_out INetFwAuthorizedApplication **app
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 44
   ) AS IUnknown                                        ' __retval_out IUnknown **newEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetFwAuthorizedApplications_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = INetFwRule
' IID = {AF230D27-BABA-4E42-ACED-F524F22CFCE2}
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetFwRule_INTERFACE_DEFINED)
    %INetFwRule_INTERFACE_DEFINED = 1

INTERFACE INetFwRule $IID_INetFwRule

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   PROPERTY SET Name <1> ( _                            ' VTable offset = 32
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <2> ( _                     ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *desc
   ' =====================================================================================
   PROPERTY SET Description <2> ( _                     ' VTable offset = 40
     BYVAL desc AS WSTRING _                            ' __in BSTR desc
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationName <3> ( _                 ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *imageFileName
   ' =====================================================================================
   PROPERTY SET ApplicationName <3> ( _                 ' VTable offset = 48
     BYVAL imageFileName AS WSTRING _                   ' __in BSTR imageFileName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ServiceName <4> ( _                     ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *serviceName
   ' =====================================================================================
   PROPERTY SET ServiceName <4> ( _                     ' VTable offset = 56
     BYVAL serviceName AS WSTRING _                     ' __in BSTR serviceName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Protocol <5> ( _                        ' VTable offset = 60
   ) AS LONG                                            ' __retval_out LONG *protocol
   ' =====================================================================================
   PROPERTY SET Protocol <5> ( _                        ' VTable offset = 64
     BYVAL protocol AS LONG _                           ' __in LONG protocol
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LocalPorts <6> ( _                      ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *portNumbers
   ' =====================================================================================
   PROPERTY SET LocalPorts <6> ( _                      ' VTable offset = 72
     BYVAL portNumbers AS WSTRING _                     ' __in BSTR portNumbers
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RemotePorts <7> ( _                     ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *portNumbers
   ' =====================================================================================
   PROPERTY SET RemotePorts <7> ( _                     ' VTable offset = 80
     BYVAL portNumbers AS WSTRING _                     ' __in BSTR portNumbers
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LocalAddresses <8> ( _                  ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *localAddrs
   ' =====================================================================================
   PROPERTY SET LocalAddresses <8> ( _                  ' VTable offset = 88
     BYVAL localAddrs AS WSTRING _                      ' __in BSTR localAddrs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RemoteAddresses <9> ( _                 ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *remoteAddrs
   ' =====================================================================================
   PROPERTY SET RemoteAddresses <9> ( _                 ' VTable offset = 96
     BYVAL remoteAddrs AS WSTRING _                     ' __in BSTR remoteAddrs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IcmpTypesAndCodes <10> ( _              ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR *icmpTypesAndCodes
   ' =====================================================================================
   PROPERTY SET IcmpTypesAndCodes <10> ( _              ' VTable offset = 104
     BYVAL icmpTypesAndCodes AS WSTRING _               ' __in BSTR icmpTypesAndCodes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Direction <11> ( _                      ' VTable offset = 108
   ) AS LONG                                            ' __retval_out NET_FW_RULE_DIRECTION *dir
   ' =====================================================================================
   PROPERTY SET Direction <11> ( _                      ' VTable offset = 112
     BYVAL dir AS LONG _                                ' __in NET_FW_RULE_DIRECTION dir
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Interfaces <12> ( _                     ' VTable offset = 116
   ) AS VARIANT                                         ' __retval_out VARIANT *interfaces
   ' =====================================================================================
   PROPERTY SET Interfaces <12> ( _                     ' VTable offset = 120
     BYVAL interfaces AS VARIANT _                      ' __in VARIANT interfaces
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InterfaceTypes <13> ( _                 ' VTable offset = 124
   ) AS WSTRING                                         ' __retval_out BSTR *interfaceTypes
   ' =====================================================================================
   PROPERTY SET InterfaceTypes <13> ( _                 ' VTable offset = 128
     BYVAL interfaceTypes AS WSTRING _                  ' __in BSTR interfaceTypes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <14> ( _                        ' VTable offset = 132
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *enabled
   ' =====================================================================================
   PROPERTY SET Enabled <14> ( _                        ' VTable offset = 136
     BYVAL enabled AS INTEGER _                         ' __in VARIANT_BOOL enabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Grouping <15> ( _                       ' VTable offset = 140
   ) AS WSTRING                                         ' __retval_out BSTR *context
   ' =====================================================================================
   PROPERTY SET Grouping <15> ( _                       ' VTable offset = 144
     BYVAL context AS WSTRING _                         ' __in BSTR context
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Profiles <16> ( _                       ' VTable offset = 148
   ) AS LONG                                            ' __retval_out long *profileTypesBitmask
   ' =====================================================================================
   PROPERTY SET Profiles <16> ( _                       ' VTable offset = 152
     BYVAL profileTypesBitmask AS LONG _                ' __in long profileTypesBitmask
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EdgeTraversal <17> ( _                  ' VTable offset = 156
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *enabled
   ' =====================================================================================
   PROPERTY SET EdgeTraversal <17> ( _                  ' VTable offset = 160
     BYVAL enabled AS INTEGER _                         ' __in VARIANT_BOOL enabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Action <18> ( _                         ' VTable offset = 164
   ) AS LONG                                            ' __retval_out NET_FW_ACTION *action
   ' =====================================================================================
   PROPERTY SET Action <18> ( _                         ' VTable offset = 168
     BYVAL action AS LONG _                             ' __in NET_FW_ACTION action
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetFwRule_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = INetFwRule2
' IID = {9C27C8DA-189B-4DDE-89F7-8B39A316782C}
' Inherited interface = INetFwRule
' ########################################################################################

#IF NOT %DEF(%INetFwRule2_INTERFACE_DEFINED)
    %INetFwRule2_INTERFACE_DEFINED = 1

INTERFACE INetFwRule2 $IID_INetFwRule2

   INHERIT IDispatch

   ' =====================================================================================
   ' INetFwRule methods
   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   PROPERTY SET Name <1> ( _                            ' VTable offset = 32
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <2> ( _                     ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *desc
   ' =====================================================================================
   PROPERTY SET Description <2> ( _                     ' VTable offset = 40
     BYVAL desc AS WSTRING _                            ' __in BSTR desc
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ApplicationName <3> ( _                 ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *imageFileName
   ' =====================================================================================
   PROPERTY SET ApplicationName <3> ( _                 ' VTable offset = 48
     BYVAL imageFileName AS WSTRING _                   ' __in BSTR imageFileName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ServiceName <4> ( _                     ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *serviceName
   ' =====================================================================================
   PROPERTY SET ServiceName <4> ( _                     ' VTable offset = 56
     BYVAL serviceName AS WSTRING _                     ' __in BSTR serviceName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Protocol <5> ( _                        ' VTable offset = 60
   ) AS LONG                                            ' __retval_out LONG *protocol
   ' =====================================================================================
   PROPERTY SET Protocol <5> ( _                        ' VTable offset = 64
     BYVAL protocol AS LONG _                           ' __in LONG protocol
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LocalPorts <6> ( _                      ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *portNumbers
   ' =====================================================================================
   PROPERTY SET LocalPorts <6> ( _                      ' VTable offset = 72
     BYVAL portNumbers AS WSTRING _                     ' __in BSTR portNumbers
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RemotePorts <7> ( _                     ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *portNumbers
   ' =====================================================================================
   PROPERTY SET RemotePorts <7> ( _                     ' VTable offset = 80
     BYVAL portNumbers AS WSTRING _                     ' __in BSTR portNumbers
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LocalAddresses <8> ( _                  ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *localAddrs
   ' =====================================================================================
   PROPERTY SET LocalAddresses <8> ( _                  ' VTable offset = 88
     BYVAL localAddrs AS WSTRING _                      ' __in BSTR localAddrs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RemoteAddresses <9> ( _                 ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *remoteAddrs
   ' =====================================================================================
   PROPERTY SET RemoteAddresses <9> ( _                 ' VTable offset = 96
     BYVAL remoteAddrs AS WSTRING _                     ' __in BSTR remoteAddrs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IcmpTypesAndCodes <10> ( _              ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR *icmpTypesAndCodes
   ' =====================================================================================
   PROPERTY SET IcmpTypesAndCodes <10> ( _              ' VTable offset = 104
     BYVAL icmpTypesAndCodes AS WSTRING _               ' __in BSTR icmpTypesAndCodes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Direction <11> ( _                      ' VTable offset = 108
   ) AS LONG                                            ' __retval_out NET_FW_RULE_DIRECTION *dir
   ' =====================================================================================
   PROPERTY SET Direction <11> ( _                      ' VTable offset = 112
     BYVAL dir AS LONG _                                ' __in NET_FW_RULE_DIRECTION dir
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Interfaces <12> ( _                     ' VTable offset = 116
   ) AS VARIANT                                         ' __retval_out VARIANT *interfaces
   ' =====================================================================================
   PROPERTY SET Interfaces <12> ( _                     ' VTable offset = 120
     BYVAL interfaces AS VARIANT _                      ' __in VARIANT interfaces
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InterfaceTypes <13> ( _                 ' VTable offset = 124
   ) AS WSTRING                                         ' __retval_out BSTR *interfaceTypes
   ' =====================================================================================
   PROPERTY SET InterfaceTypes <13> ( _                 ' VTable offset = 128
     BYVAL interfaceTypes AS WSTRING _                  ' __in BSTR interfaceTypes
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <14> ( _                        ' VTable offset = 132
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *enabled
   ' =====================================================================================
   PROPERTY SET Enabled <14> ( _                        ' VTable offset = 136
     BYVAL enabled AS INTEGER _                         ' __in VARIANT_BOOL enabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Grouping <15> ( _                       ' VTable offset = 140
   ) AS WSTRING                                         ' __retval_out BSTR *context
   ' =====================================================================================
   PROPERTY SET Grouping <15> ( _                       ' VTable offset = 144
     BYVAL context AS WSTRING _                         ' __in BSTR context
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Profiles <16> ( _                       ' VTable offset = 148
   ) AS LONG                                            ' __retval_out long *profileTypesBitmask
   ' =====================================================================================
   PROPERTY SET Profiles <16> ( _                       ' VTable offset = 152
     BYVAL profileTypesBitmask AS LONG _                ' __in long profileTypesBitmask
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EdgeTraversal <17> ( _                  ' VTable offset = 156
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *enabled
   ' =====================================================================================
   PROPERTY SET EdgeTraversal <17> ( _                  ' VTable offset = 160
     BYVAL enabled AS INTEGER _                         ' __in VARIANT_BOOL enabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Action <18> ( _                         ' VTable offset = 164
   ) AS LONG                                            ' __retval_out NET_FW_ACTION *action
   ' =====================================================================================
   PROPERTY SET Action <18> ( _                         ' VTable offset = 168
     BYVAL action AS LONG _                             ' __in NET_FW_ACTION action
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' INetFwRule2 methods
   ' =====================================================================================
   PROPERTY GET EdgeTraversalOptions <19> ( _           ' VTable offset = 172
   ) AS LONG                                            ' __retval_out long *lOptions
   ' =====================================================================================
   PROPERTY SET EdgeTraversalOptions <19> ( _           ' VTable offset = 176
     BYVAL lOptions AS LONG _                           ' __in long lOptions
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetFwRule2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = INetFwRules
' IID = {9C4C6277-5027-441E-AFAE-CA1F542DA009}
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetFwRules_INTERFACE_DEFINED)
    %INetFwRules_INTERFACE_DEFINED = 1

INTERFACE INetFwRules $IID_INetFwRules

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *count
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 32
     BYVAL rule AS IDispatch _                          ' __in INetFwRule *rule
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 36
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' void
   ' =====================================================================================
   METHOD Item <4> ( _                                  ' VTable offset = 40
     BYVAL name AS WSTRING _                            ' __in BSTR name
   ) AS INetFwRule                                      ' __retval_out INetFwRule **rule
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 44
   ) AS IUnknown                                        ' __retval_out IUnknown **newEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetFwRules_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = INetFwServiceRestriction
' IID = {8267BBE3-F890-491C-B7B6-2DB1EF0E5D2B}
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetFwServiceRestriction_INTERFACE_DEFINED)
    %INetFwServiceRestriction_INTERFACE_DEFINED = 1

INTERFACE INetFwServiceRestriction $IID_INetFwServiceRestriction

   INHERIT IDispatch

   ' =====================================================================================
   METHOD RestrictService <1> ( _                       ' VTable offset = 28
     BYVAL serviceName AS WSTRING _                     ' __in BSTR serviceName
   , BYVAL appName AS WSTRING _                         ' __in BSTR appName
   , BYVAL restrictService AS INTEGER _                 ' __in VARIANT_BOOL restrictService
   , BYVAL serviceSidRestricted AS INTEGER _            ' __in VARIANT_BOOL serviceSidRestricted
   )                                                    ' void
   ' =====================================================================================
   METHOD ServiceRestricted <2> ( _                     ' VTable offset = 32
     BYVAL serviceName AS WSTRING _                     ' __in BSTR serviceName
   , BYVAL appName AS WSTRING _                         ' __in BSTR appName
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *serviceRestricted
   ' =====================================================================================
   PROPERTY GET Rules <3> ( _                           ' VTable offset = 36
   ) AS INetFwRules                                     ' __retval_out INetFwRules **rules
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetFwServiceRestriction_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = INetFwProfile
' IID = {174A0DDA-E9F9-449D-993B-21AB667CA456}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetFwProfile_INTERFACE_DEFINED)
    %INetFwProfile_INTERFACE_DEFINED = 1

INTERFACE INetFwProfile $IID_INetFwProfile

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out NET_FW_PROFILE_TYPE *type
   ' =====================================================================================
   PROPERTY GET FirewallEnabled <2> ( _                 ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *enabled
   ' =====================================================================================
   PROPERTY SET FirewallEnabled <2> ( _                 ' VTable offset = 36
     BYVAL enabled AS INTEGER _                         ' __in VARIANT_BOOL enabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExceptionsNotAllowed <3> ( _            ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *notAllowed
   ' =====================================================================================
   PROPERTY SET ExceptionsNotAllowed <3> ( _            ' VTable offset = 44
     BYVAL notAllowed AS INTEGER _                      ' __in VARIANT_BOOL notAllowed
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NotificationsDisabled <4> ( _           ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *disabled
   ' =====================================================================================
   PROPERTY SET NotificationsDisabled <4> ( _           ' VTable offset = 52
     BYVAL disabled AS INTEGER _                        ' __in VARIANT_BOOL disabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UnicastResponsesToMulticastBroadcastDisabled <5> ( _ ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *disabled
   ' =====================================================================================
   PROPERTY SET UnicastResponsesToMulticastBroadcastDisabled <5> ( _ ' VTable offset = 60
     BYVAL disabled AS INTEGER _                        ' __in VARIANT_BOOL disabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RemoteAdminSettings <6> ( _             ' VTable offset = 64
   ) AS INetFwRemoteAdminSettings                       ' __retval_out INetFwRemoteAdminSettings **remoteAdminSettings
   ' =====================================================================================
   PROPERTY GET IcmpSettings <7> ( _                    ' VTable offset = 68
   ) AS INetFwIcmpSettings                              ' __retval_out INetFwIcmpSettings **icmpSettings
   ' =====================================================================================
   PROPERTY GET GloballyOpenPorts <8> ( _               ' VTable offset = 72
   ) AS INetFwOpenPorts                                 ' __retval_out INetFwOpenPorts **openPorts
   ' =====================================================================================
   PROPERTY GET Services <9> ( _                        ' VTable offset = 76
   ) AS INetFwServices                                  ' __retval_out INetFwServices **services
   ' =====================================================================================
   PROPERTY GET AuthorizedApplications <10> ( _         ' VTable offset = 80
   ) AS INetFwAuthorizedApplications                    ' __retval_out INetFwAuthorizedApplications **apps
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetFwProfile_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = INetFwPolicy
' IID = {D46D2478-9AC9-4008-9DC7-5563CE5536CC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetFwPolicy_INTERFACE_DEFINED)
    %INetFwPolicy_INTERFACE_DEFINED = 1

INTERFACE INetFwPolicy $IID_INetFwPolicy

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET CurrentProfile <1> ( _                  ' VTable offset = 28
   ) AS INetFwProfile                                   ' __retval_out INetFwProfile **profile
   ' =====================================================================================
   METHOD GetProfileByType <2> ( _                      ' VTable offset = 32
     BYVAL profileType AS LONG _                        ' __in NET_FW_PROFILE_TYPE profileType
   ) AS INetFwProfile                                   ' __retval_out INetFwProfile **profile
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetFwPolicy_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = INetFwPolicy2
' IID = {98325047-C671-4174-8D81-DEFCD3F03186}
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetFwPolicy2_INTERFACE_DEFINED)
    %INetFwPolicy2_INTERFACE_DEFINED = 1

INTERFACE INetFwPolicy2 $IID_INetFwPolicy2

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET CurrentProfileTypes <1> ( _             ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *profileTypesBitmask
   ' =====================================================================================
   PROPERTY GET FirewallEnabled <2> ( _                 ' VTable offset = 32
     BYVAL profileType AS LONG _                        ' __in NET_FW_PROFILE_TYPE2 profileType
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *enabled
   ' =====================================================================================
   PROPERTY SET FirewallEnabled <2> ( _                 ' VTable offset = 36
     BYVAL profileType AS LONG _                        ' __in NET_FW_PROFILE_TYPE2 profileType
   , BYVAL enabled AS INTEGER _                         ' __in VARIANT_BOOL enabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExcludedInterfaces <3> ( _              ' VTable offset = 40
     BYVAL profileType AS LONG _                        ' __in NET_FW_PROFILE_TYPE2 profileType
   ) AS VARIANT                                         ' __retval_out VARIANT *interfaces
   ' =====================================================================================
   PROPERTY SET ExcludedInterfaces <3> ( _              ' VTable offset = 44
     BYVAL profileType AS LONG _                        ' __in NET_FW_PROFILE_TYPE2 profileType
   , BYVAL interfaces AS VARIANT _                      ' __in VARIANT interfaces
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BlockAllInboundTraffic <4> ( _          ' VTable offset = 48
     BYVAL profileType AS LONG _                        ' __in NET_FW_PROFILE_TYPE2 profileType
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Block
   ' =====================================================================================
   PROPERTY SET BlockAllInboundTraffic <4> ( _          ' VTable offset = 52
     BYVAL profileType AS LONG _                        ' __in NET_FW_PROFILE_TYPE2 profileType
   , BYVAL Block AS INTEGER _                           ' __in VARIANT_BOOL Block
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NotificationsDisabled <5> ( _           ' VTable offset = 56
     BYVAL profileType AS LONG _                        ' __in NET_FW_PROFILE_TYPE2 profileType
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *disabled
   ' =====================================================================================
   PROPERTY SET NotificationsDisabled <5> ( _           ' VTable offset = 60
     BYVAL profileType AS LONG _                        ' __in NET_FW_PROFILE_TYPE2 profileType
   , BYVAL disabled AS INTEGER _                        ' __in VARIANT_BOOL disabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UnicastResponsesToMulticastBroadcastDisabled <6> ( _ ' VTable offset = 64
     BYVAL profileType AS LONG _                        ' __in NET_FW_PROFILE_TYPE2 profileType
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *disabled
   ' =====================================================================================
   PROPERTY SET UnicastResponsesToMulticastBroadcastDisabled <6> ( _ ' VTable offset = 68
     BYVAL profileType AS LONG _                        ' __in NET_FW_PROFILE_TYPE2 profileType
   , BYVAL disabled AS INTEGER _                        ' __in VARIANT_BOOL disabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Rules <7> ( _                           ' VTable offset = 72
   ) AS INetFwRules                                     ' __retval_out INetFwRules **rules
   ' =====================================================================================
   PROPERTY GET ServiceRestriction <8> ( _              ' VTable offset = 76
   ) AS INetFwServiceRestriction                        ' __retval_out INetFwServiceRestriction **ServiceRestriction
   ' =====================================================================================
   METHOD EnableRuleGroup <9> ( _                       ' VTable offset = 80
     BYVAL profileTypesBitmask AS LONG _                ' __in long profileTypesBitmask
   , BYVAL group AS WSTRING _                           ' __in BSTR group
   , BYVAL enable AS INTEGER _                          ' __in VARIANT_BOOL enable
   )                                                    ' void
   ' =====================================================================================
   METHOD IsRuleGroupEnabled <10> ( _                   ' VTable offset = 84
     BYVAL profileTypesBitmask AS LONG _                ' __in long profileTypesBitmask
   , BYVAL group AS WSTRING _                           ' __in BSTR group
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *enabled
   ' =====================================================================================
   METHOD RestoreLocalFirewallDefaults <11> ( _         ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultInboundAction <12> ( _           ' VTable offset = 92
     BYVAL profileType AS LONG _                        ' __in NET_FW_PROFILE_TYPE2 profileType
   ) AS LONG                                            ' __retval_out NET_FW_ACTION *action
   ' =====================================================================================
   PROPERTY SET DefaultInboundAction <12> ( _           ' VTable offset = 96
     BYVAL profileType AS LONG _                        ' __in NET_FW_PROFILE_TYPE2 profileType
   , BYVAL action AS LONG _                             ' __in NET_FW_ACTION action
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultOutboundAction <13> ( _          ' VTable offset = 100
     BYVAL profileType AS LONG _                        ' __in NET_FW_PROFILE_TYPE2 profileType
   ) AS LONG                                            ' __retval_out NET_FW_ACTION *action
   ' =====================================================================================
   PROPERTY SET DefaultOutboundAction <13> ( _          ' VTable offset = 104
     BYVAL profileType AS LONG _                        ' __in NET_FW_PROFILE_TYPE2 profileType
   , BYVAL action AS LONG _                             ' __in NET_FW_ACTION action
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsRuleGroupCurrentlyEnabled <14> ( _    ' VTable offset = 108
     BYVAL group AS WSTRING _                           ' __in BSTR group
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *enabled
   ' =====================================================================================
   PROPERTY GET LocalPolicyModifyState <15> ( _         ' VTable offset = 112
   ) AS LONG                                            ' __retval_out NET_FW_MODIFY_STATE *modifyState
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetFwPolicy2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = INetFwMgr
' IID = {F7898AF5-CAC4-4632-A2EC-DA06E5111AF2}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetFwMgr_INTERFACE_DEFINED)
    %INetFwMgr_INTERFACE_DEFINED = 1

INTERFACE INetFwMgr $IID_INetFwMgr

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET LocalPolicy <1> ( _                     ' VTable offset = 28
   ) AS INetFwPolicy                                    ' __retval_out INetFwPolicy **localPolicy
   ' =====================================================================================
   PROPERTY GET CurrentProfileType <2> ( _              ' VTable offset = 32
   ) AS LONG                                            ' __retval_out NET_FW_PROFILE_TYPE *profileType
   ' =====================================================================================
   METHOD RestoreDefaults <3> ( _                       ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD IsPortAllowed <4> ( _                         ' VTable offset = 40
     BYVAL imageFileName AS WSTRING _                   ' __in BSTR imageFileName
   , BYVAL ipVersion AS LONG _                          ' __in NET_FW_IP_VERSION ipVersion
   , BYVAL portNumber AS LONG _                         ' __in LONG portNumber
   , BYVAL localAddress AS WSTRING _                    ' __in BSTR localAddress
   , BYVAL ipProtocol AS LONG _                         ' __in NET_FW_IP_PROTOCOL ipProtocol
   , BYREF allowed AS VARIANT _                         ' __out VARIANT *allowed
   , BYREF restricted AS VARIANT _                      ' __out VARIANT *restricted
   )                                                    ' void
   ' =====================================================================================
   METHOD IsIcmpTypeAllowed <5> ( _                     ' VTable offset = 44
     BYVAL ipVersion AS LONG _                          ' __in NET_FW_IP_VERSION ipVersion
   , BYVAL localAddress AS WSTRING _                    ' __in BSTR localAddress
   , BYVAL type AS BYTE _                               ' __in BYTE type
   , BYREF allowed AS VARIANT _                         ' __out VARIANT *allowed
   , BYREF restricted AS VARIANT _                      ' __out VARIANT *restricted
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetFwMgr_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INetFwProduct
' IID = {71881699-18F4-458B-B892-3FFCE5E07F75}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetFwProduct_INTERFACE_DEFINED)
    %INetFwProduct_INTERFACE_DEFINED = 1

INTERFACE INetFwProduct $IID_INetFwProduct

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET RuleCategories <1> ( _                  ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *RuleCategories
   ' =====================================================================================
   PROPERTY SET RuleCategories <1> ( _                  ' VTable offset = 32
     BYVAL RuleCategories AS VARIANT _                  ' __in VARIANT RuleCategories
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisplayName <2> ( _                     ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *DisplayName
   ' =====================================================================================
   PROPERTY SET DisplayName <2> ( _                     ' VTable offset = 40
     BYVAL DisplayName AS WSTRING _                     ' __in BSTR DisplayName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PathToSignedProductExe <3> ( _          ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *path
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetFwProduct_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = INetFwProducts
' IID = {39EB36E0-2097-40BD-8AF2-63A13B525362}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%INetFwProducts_INTERFACE_DEFINED)
    %INetFwProducts_INTERFACE_DEFINED = 1

INTERFACE INetFwProducts $IID_INetFwProducts

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   METHOD Register <2> ( _                              ' VTable offset = 32
     BYVAL product AS INetFwProduct _                   ' __in INetFwProduct *product
   ) AS IUnknown                                        ' __retval_out IUnknown **registration
   ' =====================================================================================
   METHOD Item <3> ( _                                  ' VTable offset = 36
     BYVAL index AS LONG _                              ' __in long index
   ) AS INetFwProduct                                   ' __retval_out INetFwProduct **product
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 40
   ) AS IUnknown                                        ' __retval_out IUnknown **newEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetFwProducts_INTERFACE_DEFINED__ */
