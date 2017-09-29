' ########################################################################################
' Microsoft Windows
' File: evalcom2.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%EVALCOM2_INC = 1

#INCLUDE ONCE "objbase.inc"

'// returned from IEvalResult::GetResultType
' enum RESULTTYPES
%ieUnknown = 0
%ieError   = 1
%ieWarning = 2
%ieInfo    = 3

'// values passed to status callback
' enum STATUSTYPES
%ieStatusGetCUB       = 0
%ieStatusICECount     = 1
%ieStatusMerge        = 2
%ieStatusSummaryInfo  = 3
%ieStatusCreateEngine = 4
%ieStatusStarting     = 5
%ieStatusRunICE       = 6
%ieStatusShutdown     = 7
%ieStatusSuccess      = 8
%ieStatusFail         = 9
%ieStatusCancel       = 10

'typedef BOOL (WINAPI* LPDISPLAYVAL)(LPVOID pContext, RESULTTYPES uiType, LPCWSTR szwVal, LPCWSTR szwDescription, LPCWSTR szwLocation);
'typedef BOOL (WINAPI* LPEVALCOMCALLBACK)(STATUSTYPES iStatus, LPCWSTR szData, LPVOID pContext);

'FUNCTION DISPLAYVAL ( _
'   BYVAL pContext AS DWORD _                            ' LPVOID pContext
' , BYVAL uiType AS LONG _                               ' RESULTTYPES uiType
' , BYREF szwVal AS WSTRINGZ _                           ' LPCWSTR szwVal
' , BYREF szwDescription AS WSTRINGZ _                   ' LPCWSTR szwDescription
' , BYREF szwLocation AS WSTRINGZ _                      ' LPCWSTR szwLocation
' ) AS LONG                                              ' BOOL

'FUNCTION EVALCOMCALLBACK ( _
'   BYVAL iStatus AS DWORD _                             ' STATUSTYPES iStatus
' , BYREF szData AS WSTRINGZ _                           ' LPCWSTR szData
' , BYVAL pContext AS DWORD _                            ' LPVOID pContext
' ) AS LONG                                              ' BOOL

$CLSID_EvalCom2 = GUID$("{6e5e1910-8053-4660-b795-6b612e29bc58}")
$IID_IValidate = GUID$("{e482e5c6-e31e-4143-a2e6-dbc3d8e4b8d3}")

' ########################################################################################
' IValidate interface
' IID = e482e5c6-e31e-4143-a2e6-dbc3d8e4b8d3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IValidate_INTERFACE_DEFINED)
    %IValidate_INTERFACE_DEFINED = 1

INTERFACE IValidate $IID_IValidate

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OpenDatabase ( _                              ' VTable offset = 12
     BYREF szDatabase AS WSTRINGZ _                     ' __in LPCOLESTR szDatabase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenCUB ( _                                   ' VTable offset = 16
     BYREF szCUBFile AS WSTRINGZ _                      ' __in LPCOLESTR szCUBFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloseDatabase ( _                             ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloseCUB ( _                                  ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDisplay ( _                                ' VTable offset = 28
     BYVAL pDisplayFunction AS DWORD _                  ' __in LPDISPLAYVAL pDisplayFunction
   , BYVAL pContext AS DWORD _                          ' __in LPVOID pContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStatus ( _                                 ' VTable offset = 32
     BYVAL pStatusFunction AS DWORD _                   ' __in LPEVALCOMCALLBACK pStatusFunction
   , BYVAL pContext AS DWORD _                          ' __in LPVOID pContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Validate ( _                                  ' VTable offset = 36
     OPTIONAL BYREF wzICEs AS WSTRINGZ _                ' __in const WCHAR *wzICEs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IValidate_INTERFACE_DEFINED__ */
