' ########################################################################################
' Microsoft Windows
' File: HttpRequest.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%HTTPREQUEST_INC = 1

#INCLUDE ONCE "httprequestid.inc"

' ========================================================================================
' Constants
' ========================================================================================

'typedef [public] long   HTTPREQUEST_PROXY_SETTING;
'MACRO HTTPREQUEST_PROXY_SETTING = LONG
%HTTPREQUEST_PROXYSETTING_DEFAULT      = &H00000000&
%HTTPREQUEST_PROXYSETTING_PRECONFIG    = &H00000000&
%HTTPREQUEST_PROXYSETTING_DIRECT       = &H00000001&
%HTTPREQUEST_PROXYSETTING_PROXY        = &H00000002&

'typedef [public] long   HTTPREQUEST_SETCREDENTIALS_FLAGS;
'MACRO HTTPREQUEST_SETCREDENTIALS_FLAGS = LONG
%HTTPREQUEST_SETCREDENTIALS_FOR_SERVER = &H00000000&
%HTTPREQUEST_SETCREDENTIALS_FOR_PROXY  = &H00000001&


' ########################################################################################
' Library name: WinHttp
' Version: 5.1
' Documentation string: Microsoft WinHTTP Services, version 5.1
' Path: C:\WINDOWS\system32\WINHTTP.dll
' Library GUID: {662901FC-6951-4854-9EB2-D9A2570F2B2E}
' ########################################################################################

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {2087C2F4-2CEF-4953-A8AB-66779B670495}
$PROGID_WinHttpRequest51 = "WinHttp.WinHttpRequest.5.1"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_WinHttpRequest = GUID$("{2087C2F4-2CEF-4953-A8AB-66779B670495}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IWinHttpRequest = GUID$("{016FE2EC-B2C8-45F8-B23B-39E53A75396B}")
$IID_IWinHttpRequestEvents = GUID$("{F97F4E15-B787-4212-80D1-D380CBBF982E}")

' ========================================================================================
' WinHttpRequestOption enum
' IID: {12782009-FE90-4877-9730-E5E183669B19}
' WinHttpRequest Options
' ========================================================================================

%WinHttpRequestOption_UserAgentString                   = 0            ' &H0
%WinHttpRequestOption_URL                               = 1            ' &H1
%WinHttpRequestOption_URLCodePage                       = 2            ' &H2
%WinHttpRequestOption_EscapePercentInURL                = 3            ' &H3
%WinHttpRequestOption_SslErrorIgnoreFlags               = 4            ' &H4
%WinHttpRequestOption_SelectCertificate                 = 5            ' &H5
%WinHttpRequestOption_EnableRedirects                   = 6            ' &H6
%WinHttpRequestOption_UrlEscapeDisable                  = 7            ' &H7
%WinHttpRequestOption_UrlEscapeDisableQuery             = 8            ' &H8
%WinHttpRequestOption_SecureProtocols                   = 9            ' &H9
%WinHttpRequestOption_EnableTracing                     = 10           ' &HA
%WinHttpRequestOption_RevertImpersonationOverSsl        = 11           ' &HB
%WinHttpRequestOption_EnableHttpsToHttpRedirects        = 12           ' &HC
%WinHttpRequestOption_EnablePassportAuthentication      = 13           ' &HD
%WinHttpRequestOption_MaxAutomaticRedirects             = 14           ' &HE
%WinHttpRequestOption_MaxResponseHeaderSize             = 15           ' &HF
%WinHttpRequestOption_MaxResponseDrainSize              = 16           ' &H10
%WinHttpRequestOption_EnableHttp1_1                     = 17           ' &H11
%WinHttpRequestOption_EnableCertificateRevocationCheck  = 18           ' &H12

' ========================================================================================
' WinHttpRequestAutoLogonPolicy enum
' IID: {9D8A6DF8-13DE-4B1F-A330-67C719D62514}
' ========================================================================================

%AutoLogonPolicy_Always                                 = 0            ' &H0
%AutoLogonPolicy_OnlyIfBypassProxy                      = 1            ' &H1
%AutoLogonPolicy_Never                                  = 2            ' &H2

' ========================================================================================
' WinHttpRequestSslErrorFlags enum
' IID: {152A1CA2-55A9-43A3-B187-0605BB886349}
' ========================================================================================

%SslErrorFlag_UnknownCA                                 = &H00000100   ' 256
%SslErrorFlag_CertWrongUsage                            = &H00000200   ' 512
%SslErrorFlag_CertCNInvalid                             = &H00001000   ' 4096
%SslErrorFlag_CertDateInvalid                           = &H00002000   ' 8192
%SslErrorFlag_Ignore_All                                = &H00003300   ' 13056

' ========================================================================================
' WinHttpRequestSecureProtocols enum
' IID: {6B2C51C1-A8EA-46BD-B928-C9B76F9F14DD}
' ========================================================================================

%SecureProtocol_SSL2                                    = &H00000008   ' 8
%SecureProtocol_SSL3                                    = &H00000020   ' 32
%SecureProtocol_TLS1                                    = &H00000080   ' 128
%SecureProtocol_ALL                                     = &H000000A8   ' 168

' ########################################################################################
' Interface name = IWinHttpRequest
' IID = {016FE2EC-B2C8-45F8-B23B-39E53A75396B}
' IWinHttpRequest Interface
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWinHttpRequest_INTERFACE_DEFINED)
    %IWinHttpRequest_INTERFACE_DEFINED = 1

INTERFACE IWinHttpRequest $IID_IWinHttpRequest

   INHERIT IDispatch

   ' =====================================================================================
   METHOD SetProxy <13> ( _                             ' VTable offset = 28
     BYVAL ProxySetting AS LONG _                       ' __in HTTPREQUEST_PROXY_SETTING ProxySetting
   , OPTIONAL BYVAL ProxyServer AS VARIANT _            ' __in_opt VARIANT ProxyServer
   , OPTIONAL BYVAL BypassList AS VARIANT _             ' __in_opt VARIANT BypassList
   )                                                    ' VOID
   ' =====================================================================================
   METHOD SetCredentials <14> ( _                       ' VTable offset = 32
     BYVAL UserName AS WSTRING _                        ' __in BSTR UserName
   , BYVAL Password AS WSTRING _                        ' __in BSTR Password
   , BYVAL Flags AS LONG _                              ' __in HTTPREQUEST_SETCREDENTIALS_FLAGS Flags
   )                                                    ' VOID
   ' =====================================================================================
   METHOD Open <1> ( _                                  ' VTable offset = 36
     BYVAL Method AS WSTRING _                          ' __in BSTR Method
   , BYVAL Url AS WSTRING _                             ' __in BSTR Url
   , OPTIONAL BYVAL Async AS VARIANT _                  ' __in_opt VARIANT Async
   )                                                    ' VOID
   ' =====================================================================================
   METHOD SetRequestHeader <2> ( _                      ' VTable offset = 40
     BYVAL Header AS WSTRING _                          ' __in BSTR Header
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' VOID
   ' =====================================================================================
   METHOD GetResponseHeader <3> ( _                     ' VTable offset = 44
     BYVAL Header AS WSTRING _                          ' __in BSTR Header
   ) AS WSTRING                                         ' __retval_out BSTR * Value
   ' =====================================================================================
   METHOD GetAllResponseHeaders <4> ( _                 ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR * Headers
   ' =====================================================================================
   METHOD Send <5> ( _                                  ' VTable offset = 52
     OPTIONAL BYVAL Body AS VARIANT _                   ' __in_opt VARIANT Body
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET Status <7> ( _                          ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long * Status
   ' =====================================================================================
   PROPERTY GET StatusText <8> ( _                      ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR * Status
   ' =====================================================================================
   PROPERTY GET ResponseText <9> ( _                    ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR * Body
   ' =====================================================================================
   PROPERTY GET ResponseBody <10> ( _                   ' VTable offset = 68
   ) AS VARIANT                                         ' __retval_out VARIANT * Body
   ' =====================================================================================
   PROPERTY GET ResponseStream <11> ( _                 ' VTable offset = 72
   ) AS VARIANT                                         ' __retval_out VARIANT * Body
   ' =====================================================================================
   PROPERTY GET Option <6> ( _                          ' VTable offset = 76
     BYVAL Option AS LONG _                             ' __in WinHttpRequestOption Option
   ) AS VARIANT                                         ' __retval_out VARIANT * Value
   ' =====================================================================================
   PROPERTY SET Option <6> ( _                          ' VTable offset = 80
     BYVAL Option AS LONG _                             ' __in WinHttpRequestOption Option
   , BYVAL Value AS VARIANT _                           ' __in VARIANT Value
   )                                                    ' VOID
   ' =====================================================================================
   METHOD WaitForResponse <15> ( _                      ' VTable offset = 84
     OPTIONAL BYVAL Timeout AS VARIANT _                ' __in_opt VARIANT Timeout
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL * Succeeded
   ' =====================================================================================
   METHOD Abort <12> ( _                                ' VTable offset = 88
   )                                                    ' VOID
   ' =====================================================================================
   METHOD SetTimeouts <16> ( _                          ' VTable offset = 92
     BYVAL ResolveTimeout AS LONG _                     ' __in long ResolveTimeout
   , BYVAL ConnectTimeout AS LONG _                     ' __in long ConnectTimeout
   , BYVAL SendTimeout AS LONG _                        ' __in long SendTimeout
   , BYVAL ReceiveTimeout AS LONG _                     ' __in long ReceiveTimeout
   )                                                    ' VOID
   ' =====================================================================================
   METHOD SetClientCertificate <17> ( _                 ' VTable offset = 96
     BYVAL ClientCertificate AS WSTRING _               ' __in BSTR ClientCertificate
   )                                                    ' VOID
   ' =====================================================================================
   METHOD SetAutoLogonPolicy <18> ( _                   ' VTable offset = 100
     BYVAL AutoLogonPolicy AS LONG _                    ' __in WinHttpRequestAutoLogonPolicy AutoLogonPolicy
   )                                                    ' VOID
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWinHttpRequest_INTERFACE_DEFINED__ */
