' ########################################################################################
' Microsoft Windows
' File: WbemTran.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: WbemTransports_v1
' Version: 0.0, Locale ID = 0
' Library GUID: {027947F3-D731-11CE-A357-000000000001}
' ########################################################################################

#INCLUDE THIS ONCE
%WBEMTRAN_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "oleidl.inc"
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "wbemcli.inc"

'/*******************************************************************************/
'/*                                                                             */
'/*    Copyright (c) Microsoft Corporation.  All rights reserved.               */
'/*                                                                             */
'/*    This IDL file contains interfaces needed only by implementors of custom  */
'/*    transports and custom security systems. These interfaces are not needed  */
'/*    for either client or provider access to CIMOM.                           */
'/*                                                                             */
'/*    See WBEMCLI.IDL for client interfaces, and WBEMPROV.IDL for provider     */
'/*    extensions                                                               */
'/*                                                                             */
'/*******************************************************************************/

$LIBID_WbemTransports_v1 = GUID$("{027947F3-D731-11CE-A357-000000000001}")

#IF NOT %DEF(%WbemTransports_v1_LIBRARY_DEFINED)
    %WbemTransports_v1_LIBRARY_DEFINED = 1

$CLSID_WbemDCOMTransport = GUID$("{F7CE2E13-8C90-11D1-9E7B-00C04FC324A8}")
$CLSID_WbemLevel1Login = GUID$("{8BC3F05E-D86B-11D0-A075-00C04FB68820}")
$CLSID_WbemLocalAddrRes = GUID$("{A1044801-8F7E-11D1-9E7C-00C04FC324A8}")
$CLSID_WbemUninitializedClassObject = GUID$("{7A0227F6-7108-11D1-AD90-00C04FD8FDFF}")

' enum WBEM_LOGIN_TYPE
%WBEM_FLAG_INPROC_LOGIN            = 0
%WBEM_FLAG_LOCAL_LOGIN             = 1
%WBEM_FLAG_REMOTE_LOGIN            = 2
%WBEM_AUTHENTICATION_METHOD_MASK   = &Hf
%WBEM_FLAG_USE_MULTIPLE_CHALLENGES = &H10

'typedef /* [length_is][size_is] */ BYTE *WBEM_128BITS;

' ########################################################################################
' Interface name = IWbemTransport
' IID = {553FE584-2156-11D0-B6AE-00AA003240C7}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemTransport_INTERFACE_DEFINED)
    %IWbemTransport_INTERFACE_DEFINED = 1

$IID_IWbemTransport = GUID$("{553FE584-2156-11D0-B6AE-00AA003240C7}")

INTERFACE IWbemTransport $IID_IWbemTransport

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemTransport_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemLevel1Login
' IID = {F309AD18-D86A-11D0-A075-00C04FB68820}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemLevel1Login_INTERFACE_DEFINED)
    %IWbemLevel1Login_INTERFACE_DEFINED = 1

$IID_IWbemLevel1Login = GUID$("{F309AD18-D86A-11D0-A075-00C04FB68820}")

INTERFACE IWbemLevel1Login $IID_IWbemLevel1Login

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EstablishPosition ( _                         ' VTable offset = 12
     BYREF wszLocaleList AS WSTRINGZ _                  ' __in LPWSTR wszLocaleList
   , BYVAL dwNumLocales AS DWORD _                      ' __in DWORD dwNumLocales
   , BYREF reserved AS DWORD _                          ' __out DWORD *reserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestChallenge ( _                          ' VTable offset = 16
     BYREF wszNetworkResource AS WSTRINGZ _             ' __in LPWSTR wszNetworkResource
   , BYREF wszUser AS WSTRINGZ _                        ' __in LPWSTR wszUser
   , BYREF Nonce AS BYTE _                              ' __out WBEM_128BITS Nonce
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WBEMLogin ( _                                 ' VTable offset = 20
     BYREF wszPreferredLocale AS WSTRINGZ _             ' __in LPWSTR wszPreferredLocale
   , BYREF AccessToken AS BYTE _                        ' __in WBEM_128BITS AccessToken
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYREF ppNamespace AS IWbemServices _               ' __out IWbemServices **ppNamespace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NTLMLogin ( _                                 ' VTable offset = 24
     BYREF wszNetworkResource AS WSTRINGZ _             ' __in LPWSTR wszNetworkResource
   , BYREF wszPreferredLocale AS WSTRINGZ _             ' __in LPWSTR wszPreferredLocale
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYREF ppNamespace AS IWbemServices _               ' __out IWbemServices **ppNamespace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemLevel1Login_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemConnectorLogin
' IID = {D8EC9CB1-B135-4F10-8B1B-C7188BB0D186}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemConnectorLogin_INTERFACE_DEFINED)
    %IWbemConnectorLogin_INTERFACE_DEFINED = 1

$IID_IWbemConnectorLogin = GUID$("{D8EC9CB1-B135-4F10-8B1B-C7188BB0D186}")

INTERFACE IWbemConnectorLogin $IID_IWbemConnectorLogin

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ConnectorLogin ( _                            ' VTable offset = 12
     BYREF wszNetworkResource AS WSTRINGZ _             ' __in LPWSTR wszNetworkResource
   , BYREF wszPreferredLocale AS WSTRINGZ _             ' __in LPWSTR wszPreferredLocale
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYREF riid AS GUID _                               ' __in REFIID *riid
   , BYREF pInterface AS DWORD _                        ' __out void **pInterface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemConnectorLogin_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemAddressResolution
' IID = {F7CE2E12-8C90-11D1-9E7B-00C04FC324A8}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemAddressResolution_INTERFACE_DEFINED)
    %IWbemAddressResolution_INTERFACE_DEFINED = 1

$IID_IWbemAddressResolution = GUID$("{F7CE2E12-8C90-11D1-9E7B-00C04FC324A8}")

INTERFACE IWbemAddressResolution $IID_IWbemAddressResolution

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Resolve ( _                                   ' VTable offset = 12
     BYREF wszNamespacePath AS WSTRINGZ _               ' __in LPWSTR wszNamespacePath
   , BYREF wszAddressType AS WSTRINGZ _                 ' __out LPWSTR wszAddressType
   , BYREF pdwAddressLength AS DWORD _                  ' __out DWORD *pdwAddressLength
   , BYREF pabBinaryAddress AS DWORD _                  ' __out BYTE **pabBinaryAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemAddressResolution_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemClientTransport
' IID = {F7CE2E11-8C90-11D1-9E7B-00C04FC324A8}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemClientTransport_INTERFACE_DEFINED)
    %IWbemClientTransport_INTERFACE_DEFINED = 1

$IID_IWbemClientTransport = GUID$("{F7CE2E11-8C90-11D1-9E7B-00C04FC324A8}")

INTERFACE IWbemClientTransport $IID_IWbemClientTransport

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ConnectServer ( _                             ' VTable offset = 12
     BYVAL strAddressType AS WSTRING _                  ' __in BSTR strAddressType
   , BYVAL dwBinaryAddressLength AS DWORD _             ' __in DWORD dwBinaryAddressLength
   , BYREF abBinaryAddress AS BYTE _                    ' __in BYTE *abBinaryAddress
   , BYVAL strNetworkResource AS WSTRING _              ' __in BSTR strNetworkResource
   , BYVAL strUser AS WSTRING _                         ' __in BSTR strUser
   , BYVAL strPassword AS WSTRING _                     ' __in BSTR strPassword
   , BYVAL strLocale AS WSTRING _                       ' __in BSTR strLocale
   , BYVAL lSecurityFlags AS LONG _                     ' __in long lSecurityFlags
   , BYVAL strAuthority AS WSTRING _                    ' __in BSTR strAuthority
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYREF ppNamespace AS IWbemServices _               ' __out IWbemServices **ppNamespace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemClientTransport_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemClientConnectionTransport
' IID = {A889C72A-FCC1-4A9E-AF61-ED071333FB5B}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemClientConnectionTransport_INTERFACE_DEFINED)
    %IWbemClientConnectionTransport_INTERFACE_DEFINED = 1

$IID_IWbemClientConnectionTransport = GUID$("{A889C72A-FCC1-4A9E-AF61-ED071333FB5B}")

INTERFACE IWbemClientConnectionTransport $IID_IWbemClientConnectionTransport

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Open ( _                                      ' VTable offset = 12
     BYVAL strAddressType AS WSTRING _                  ' __in BSTR strAddressType
   , BYVAL dwBinaryAddressLength AS DWORD _             ' __in DWORD dwBinaryAddressLength
   , BYREF abBinaryAddress AS BYTE _                    ' __in BYTE *abBinaryAddress
   , BYVAL strObject AS WSTRING _                       ' __in BSTR strObject
   , BYVAL strUser AS WSTRING _                         ' __in BSTR strUser
   , BYVAL strPassword AS WSTRING _                     ' __in BSTR strPassword
   , BYVAL strLocale AS WSTRING _                       ' __in BSTR strLocale
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYREF riid AS GUID _                               ' __in REFIID *riid
   , BYREF pInterface AS DWORD _                        ' __out void **pInterface
   , BYREF pCallRes AS IWbemCallResult _                ' __out IWbemCallResult **pCallRes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenAsync ( _                                 ' VTable offset = 16
     BYVAL strAddressType AS WSTRING _                  ' __in BSTR strAddressType
   , BYVAL dwBinaryAddressLength AS DWORD _             ' __in DWORD dwBinaryAddressLength
   , BYREF abBinaryAddress AS BYTE _                    ' __in BYTE *abBinaryAddress
   , BYVAL strObject AS WSTRING _                       ' __in BSTR strObject
   , BYVAL strUser AS WSTRING _                         ' __in BSTR strUser
   , BYVAL strPassword AS WSTRING _                     ' __in BSTR strPassword
   , BYVAL strLocale AS WSTRING _                       ' __in BSTR strLocale
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYREF riid AS GUID _                               ' __in REFIID *riid
   , BYVAL pResponseHandler AS IWbemObjectSink _        ' __in IWbemObjectSink *pResponseHandler
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 20
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pHandler AS IWbemObjectSink _                ' __in IWbemObjectSink *pHandler
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemClientConnectionTransport_INTERFACE_DEFINED__ */

#ENDIF   ' #IF NOT %DEF(%WbemTransports_v1_LIBRARY_DEFINED)

' ########################################################################################
' Interface name = IWbemConstructClassObject
' IID = {9EF76194-70D5-11D1-AD90-00C04FD8FDFF}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemConstructClassObject_INTERFACE_DEFINED)
    %IWbemConstructClassObject_INTERFACE_DEFINED = 1

$IID_IWbemConstructClassObject = GUID$("{9EF76194-70D5-11D1-AD90-00C04FD8FDFF}")

INTERFACE IWbemConstructClassObject $IID_IWbemConstructClassObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetInheritanceChain ( _                       ' VTable offset = 12
     BYVAL lNumAntecedents AS LONG _                    ' __in long lNumAntecedents
   , BYREF awszAntecedents AS DWORD _                   ' __in LPWSTR *awszAntecedents
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPropertyOrigin ( _                         ' VTable offset = 16
     BYREF wszPropertyName AS WSTRINGZ _                ' __in LPWSTR wszPropertyName
   , BYVAL lOriginIndex AS LONG _                       ' __in long lOriginIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMethodOrigin ( _                           ' VTable offset = 20
     BYREF wszMethodName AS WSTRINGZ _                  ' __in LPWSTR wszMethodName
   , BYVAL lOriginIndex AS LONG _                       ' __in long lOriginIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetServerNamespace ( _                        ' VTable offset = 24
     BYREF wszServer AS WSTRINGZ _                      ' __in LPWSTR wszServer
   , BYREF wszNamespace AS WSTRINGZ _                   ' __in LPWSTR wszNamespace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemConstructClassObject_INTERFACE_DEFINED__ */
