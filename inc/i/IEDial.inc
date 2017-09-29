' ########################################################################################
' Microsoft Windows
' File: IEDial.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IEDIAL_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "ocidl.inc"

' ########################################################################################
' IDialEventSink interface
' IID = 2D86F4FF-6E2D-4488-B2E9-6934AFD41BEA
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDialEventSink_INTERFACE_DEFINED)
    %IDialEventSink_INTERFACE_DEFINED = 1

$IID_IDialEventSink = GUID$("{2D86F4FF-6E2D-4488-B2E9-6934AFD41BEA}")

INTERFACE IDialEventSink $IID_IDialEventSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnEvent ( _                                   ' VTable offset = 12
     BYVAL dwEvent AS DWORD _                           ' __in DWORD dwEvent
   , BYVAL dwStatus AS DWORD _                          ' __in DWORD dwStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDialEventSink_INTERFACE_DEFINED__ */


' ########################################################################################
' IDialEngine interface
' IID = 39FD782B-7905-40D5-9148-3C9B190423D5
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDialEngine_INTERFACE_DEFINED)
    %IDialEngine_INTERFACE_DEFINED = 1

$IID_IDialEngine = GUID$("{39FD782B-7905-40D5-9148-3C9B190423D5}")

INTERFACE IDialEngine $IID_IDialEngine

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYREF pwzConnectoid AS WSTRINGZ _                  ' __in LPCWSTR pwzConnectoid
   , BYVAL pIDES AS IUnknown _                          ' __in IDialEventSink *pIDES
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 16
     BYREF pwzProperty AS WSTRINGZ _                    ' __in LPCWSTR pwzProperty
   , BYREF pwzValue AS WSTRINGZ _                       ' __in LPWSTR pwzValue
   , BYVAL dwBufSize AS DWORD _                         ' __in DWORD dwBufSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProperty ( _                               ' VTable offset = 20
     BYREF pwzProperty AS WSTRINGZ _                    ' __in LPCWSTR pwzProperty
   , BYREF pwzValue AS WSTRINGZ _                       ' __in LPCWSTR pwzValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Dial ( _                                      ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HangUp ( _                                    ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConnectedState ( _                         ' VTable offset = 32
     BYREF pdwState AS DWORD _                          ' __out DWORD *pdwState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConnectHandle ( _                          ' VTable offset = 36
     BYREF pdwHandle AS DWORD _                         ' __out DWORD_PTR *pdwHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDialEngine_INTERFACE_DEFINED__ */


' ########################################################################################
' IDialBranding interface
' IID = 8AECAFA9-4306-43CC-8C5A-765F2979CC16
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDialBranding_INTERFACE_DEFINED)
    %IDialBranding_INTERFACE_DEFINED = 1

$IID_IDialBranding = GUID$("{8AECAFA9-4306-43CC-8C5A-765F2979CC16}")

INTERFACE IDialBranding $IID_IDialBranding

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYREF pwzConnectoid AS WSTRINGZ _                  ' __in LPCWSTR pwzConnectoid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBitmap ( _                                 ' VTable offset = 16
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF phBitmap AS DWORD _                          ' __out HBITMAP *phBitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDialBranding_INTERFACE_DEFINED__ */

$$DIALPROP_USERNAME       = "UserName"$$
$$DIALPROP_PASSWORD       = "Password"$$
$$DIALPROP_DOMAIN         = "Domain"$$
$$DIALPROP_SAVEPASSWORD   = "SavePassword"$$
$$DIALPROP_REDIALCOUNT    = "RedialCount"$$
$$DIALPROP_REDIALINTERVAL = "RedialInterval"$$
$$DIALPROP_PHONENUMBER    = "PhoneNumber"$$
$$DIALPROP_LASTERROR      = "LastError"$$
$$DIALPROP_RESOLVEDPHONE  = "ResolvedPhone"$$

%DIALENG_OperationComplete   = &H10000
%DIALENG_RedialAttempt       = &H10001
%DIALENG_RedialWait          = &H10002
