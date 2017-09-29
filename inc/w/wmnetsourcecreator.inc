' ########################################################################################
' Microsoft Windows
' File: wmnetsourcecreator.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WMNETSOURCECREATOR_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"

$CLSID_ClientNetManager = GUID$("{CD12A3CE-9C42-11D2-BEED-0060082F2054}")
$IID_INSNetSourceCreator = GUID$("{0C0E4080-9081-11D2-BEEC-0060082F2054}")

'typedef unsigned __int64 QWORD;

' ########################################################################################
' Interface name = INSNetSourceCreator
' IID = 0C0E4080-9081-11D2-BEEC-0060082F2054
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%INSNetSourceCreator_INTERFACE_DEFINED)
    %INSNetSourceCreator_INTERFACE_DEFINED = 1

INTERFACE INSNetSourceCreator $IID_INSNetSourceCreator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateNetSource ( _                           ' VTable offset = 16
     BYREF pszStreamName AS WSTRINGZ _                  ' __in LPCWSTR pszStreamName
   , BYVAL pMonitor AS IUnknown _                       ' __in IUnknown *pMonitor
   , BYVAL pData AS BYTE PTR _                          ' __in BYTE *pData
   , BYVAL pUserContext AS IUnknown _                   ' __in IUnknown *pUserContext
   , BYVAL pCallback AS IUnknown _                      ' __in IUnknown *pCallback
   , BYVAL qwContext AS QUAD _                          ' __in QWORD qwContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNetSourceProperties ( _                    ' VTable offset = 20
     BYREF pszStreamName AS WSTRINGZ _                  ' __in LPCWSTR pszStreamName
   , BYREF ppPropertiesNode AS IUnknown _               ' __out IUnknown **ppPropertiesNode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNetSourceSharedNamespace ( _               ' VTable offset = 24
     BYREF ppSharedNamespace AS IUnknown _              ' __out IUnknown **ppSharedNamespace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNetSourceAdminInterface ( _                ' VTable offset = 28
     BYREF pszStreamName AS WSTRINGZ _                  ' __in LPCWSTR pszStreamName
   , BYREF pVal AS VARIANT _                            ' __out VARIANT *pVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumProtocolsSupported ( _                  ' VTable offset = 32
     BYREF pcProtocols AS DWORD _                       ' __out DWORD *pcProtocols
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProtocolName ( _                           ' VTable offset = 36
     BYVAL dwProtocolNum AS DWORD _                     ' __in DWORD dwProtocolNum
   , BYREF pwszProtocolName AS DWORD _                  ' __out WCHAR *pwszProtocolName
   , BYREF pcchProtocolName AS WORD _                   ' __inout WORD *pcchProtocolName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INSNetSourceCreator_INTERFACE_DEFINED__ */
