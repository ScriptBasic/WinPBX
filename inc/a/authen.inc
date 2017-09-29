' ########################################################################################
' Microsoft Windows
' File: authen.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AUTHEN_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "WMSContext.inc"

$IID_IWMSAuthenticationPlugin = GUID$("{BE185FF9-6932-11D2-8B3B-006097B01206}")
$IID_IWMSAuthenticationContext = GUID$("{BE185FFA-6932-11D2-8B3B-006097B01206}")
$IID_IWMSAuthenticationCallback = GUID$("{BE185FFB-6932-11D2-8B3B-006097B01206}")


' ########################################################################################
' Interface name = IWMSAuthenticationPlugin
' IID = {BE185FF9-6932-11D2-8B3B-006097B01206}
' Provides methods for retrieving information about an authentication plugin and for accessing the plug-ins IWMSAuthenticationContext object.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMSAuthenticationPlugin_INTERFACE_DEFINED)
    %IWMSAuthenticationPlugin_INTERFACE_DEFINED = 1

' WMS_AUTHENTICATION_FLAGS enum
MACRO WMS_AUTHENTICATION_FLAGS_ENUM = DWORD
%WMS_AUTHENTICATION_TEXT_CHALLENGE  = &H1
%WMS_AUTHENTICATION_CLIENT_SHOWS_UI = &H2
%WMS_AUTHENTICATION_ANONYMOUS       = &H4
%WMS_AUTHENTICATION_CHALLENGE_FIRST = &H8

INTERFACE IWMSAuthenticationPlugin $IID_IWMSAuthenticationPlugin

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPackageName ( _                            ' VTable offset = 12
     BYREF pbstrPackageName AS WSTRING _                ' __retval_out BSTR *pbstrPackageName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProtocolName ( _                           ' VTable offset = 16
     BYREF pbstrProtocolName AS WSTRING _               ' __retval_out BSTR *pbstrProtocolName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 20
     BYREF plFlags AS LONG _                            ' __retval_out long *plFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateAuthenticationContext ( _               ' VTable offset = 24
     BYREF ppAuthenCtx AS IWMSAuthenticationContext _   ' __retval_out IWMSAuthenticationContext **ppAuthenCtx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMSAuthenticationPlugin_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMSAuthenticationContext
' IID = {BE185FFA-6932-11D2-8B3B-006097B01206}
' Provides methods that are used to authenticate a client.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMSAuthenticationContext_INTERFACE_DEFINED)
    %IWMSAuthenticationContext_INTERFACE_DEFINED = 1

INTERFACE IWMSAuthenticationContext $IID_IWMSAuthenticationContext

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAuthenticationPlugin ( _                   ' VTable offset = 12
     BYREF ppAuthenPlugin AS IWMSAuthenticationPlugin _ ' __retval_out IWMSAuthenticationPlugin **ppAuthenPlugin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Authenticate ( _                              ' VTable offset = 16
     BYVAL ResponseBlob AS VARIANT _                    ' __in VARIANT ResponseBlob
   , BYVAL pUserCtx AS IWMSContext _                    ' __in IWMSContext *pUserCtx
   , BYVAL pPresentationCtx AS IWMSContext _            ' __in IWMSContext *pPresentationCtx
   , BYVAL pCommandContext AS IWMSCommandContext _      ' __in IWMSCommandContext *pCommandContext
   , BYVAL IWMSAuthenticationCallback _                 ' __in IWMSAuthenticationCallback *pCallback
   , BYVAL pCallback AS VARIANT _                       ' __in VARIANT Context
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLogicalUserID ( _                          ' VTable offset = 20
     BYREF pbstrUserID AS WSTRING _                     ' __retval_out BSTR *pbstrUserID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetImpersonationAccountName ( _               ' VTable offset = 24
     BYREF pbstrAccountName AS WSTRING _                ' __retval_out BSTR *pbstrAccountName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetImpersonationToken ( _                     ' VTable offset = 28
     BYREF plToken AS LONG _                            ' __retval_out long *plToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMSAuthenticationContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMSAuthenticationCallback
' IID = {BE185FFB-6932-11D2-8B3B-006097B01206}
' Provides a method to notify the server of the results of an authentication request.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMSAuthenticationCallback_INTERFACE_DEFINED)
    %IWMSAuthenticationCallback_INTERFACE_DEFINED = 1

' WMS_AUTHENTICATION_RESULT enum
MACRO WMS_AUTHENTICATION_RESULT_ENUM = DWORD
%WMS_AUTHENTICATION_SUCCESS  = &H1
%WMS_AUTHENTICATION_DENIED   = &H2
%WMS_AUTHENTICATION_CONTINUE = &H3
%WMS_AUTHENTICATION_ERROR    = &H4

INTERFACE IWMSAuthenticationCallback $IID_IWMSAuthenticationCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnAuthenticateComplete ( _                    ' VTable offset = 12
     BYVAL AuthResult AS WMS_AUTHENTICATION_RESULT_ENUM _ ' __in WMS_AUTHENTICATION_RESULT AuthResult
   , BYVAL ChallengeBlob AS VARIANT _                   ' __in VARIANT ChallengeBlob
   , BYVAL Context AS VARIANT _                         ' __in VARIANT Context
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMSAuthenticationCallback_INTERFACE_DEFINED__ */
