' ########################################################################################
' Microsoft Windows
' File: BiDiSpl.inc
' Contents: Bidi Printer Communication.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%BIDISPL_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

'EXTERN_C const IID LIBID_IBidiSplLib;
$CLSID_BidiRequest          = GUID$("{B9162A23-45F9-47CC-80F5-FE0FE9B9E1A2}")
$CLSID_BidiRequestContainer = GUID$("{FC5B8A24-DB05-4A01-8388-22EDF6C2BBBA}")
$CLSID_BidiSpl              = GUID$("{2A614240-A4C5-4C33-BD87-1BC709331639}")

' ########################################################################################
' IBidiRequest interface
' IID = 8F348BD7-4B47-4755-8A9D-0F422DF3DC89
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBidiRequest_INTERFACE_DEFINED)
    %IBidiRequest_INTERFACE_DEFINED = 1

$IID_IBidiRequest = GUID$("{8F348BD7-4B47-4755-8A9D-0F422DF3DC89}")

INTERFACE IBidiRequest $IID_IBidiRequest

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetSchema ( _                                 ' VTable offset = 12
     BYREF pszSchema AS WSTRINGZ _                      ' __in const LPCWSTR pszSchema
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInputData ( _                              ' VTable offset = 16
     BYVAL dwType AS DWORD _                            ' __in const DWORD dwType
   , BYVAL pData AS BYTE PTR _                          ' __in const BYTE *pData
   , BYVAL uSize AS DWORD _                             ' __in const UINT uSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResult ( _                                 ' VTable offset = 20
     BYREF phr AS LONG _                                ' __out HRESULT *phr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputData ( _                             ' VTable offset = 24
     BYVAL dwIndex AS DWORD _                           ' __in const DWORD dwIndex
   , BYREF ppszSchema AS DWORD _                        ' __out LPWSTR *ppszSchema
   , BYREF pdwType AS DWORD _                           ' __out DWORD *pdwType
   , BYREF ppData AS DWORD _                            ' __out BYTE **ppData
   , BYREF uSize AS DWORD _                             ' __out ULONG *uSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEnumCount ( _                              ' VTable offset = 28
     BYREF pdwTotal AS DWORD _                          ' __out DWORD *pdwTotal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBidiRequest_INTERFACE_DEFINED__ */


' ########################################################################################
' IBidiRequestContainer interface
' IID = D752F6C0-94A8-4275-A77D-8F1D1A1121AE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBidiRequestContainer_INTERFACE_DEFINED)
    %IBidiRequestContainer_INTERFACE_DEFINED = 1

$IID_IBidiRequestContainer = GUID$("{D752F6C0-94A8-4275-A77D-8F1D1A1121AE}")

INTERFACE IBidiRequestContainer $IID_IBidiRequestContainer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddRequest ( _                                ' VTable offset = 12
     BYVAL pRequest AS IBidiRequest _                   ' __in IBidiRequest *pRequest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEnumObject ( _                             ' VTable offset = 16
     BYREF ppenum AS IEnumUnknown _                     ' __out IEnumUnknown **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRequestCount ( _                           ' VTable offset = 20
     BYREF puCount AS DWORD _                           ' __out ULONG *puCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBidiRequestContainer_INTERFACE_DEFINED__ */


' ########################################################################################
' IBidiSpl interface
' IID = D580DC0E-DE39-4649-BAA8-BF0B85A03A97
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBidiSpl_INTERFACE_DEFINED)
    %IBidiSpl_INTERFACE_DEFINED = 1

$IID_IBidiSpl = GUID$("{D580DC0E-DE39-4649-BAA8-BF0B85A03A97}")

INTERFACE IBidiSpl $IID_IBidiSpl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD BindDevice ( _                                ' VTable offset = 12
     BYREF pszDeviceName AS WSTRINGZ _                  ' __in const LPCWSTR pszDeviceName
   , BYVAL dwAccess AS DWORD _                          ' __in const DWORD dwAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnbindDevice ( _                              ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendRecv ( _                                  ' VTable offset = 20
     BYREF pszAction AS WSTRINGZ _                      ' __in const LPCWSTR pszAction
   , BYVAL pRequest AS IBidiRequest _                   ' __in IBidiRequest *pRequest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MultiSendRecv ( _                             ' VTable offset = 24
     BYREF pszAction AS WSTRINGZ _                      ' __in const LPCWSTR pszAction
   , BYVAL pRequestContainer AS IBidiRequestContainer _ ' __in IBidiRequestContainer *pRequestContainer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBidiSpl_INTERFACE_DEFINED__ */


' ########################################################################################
' IBidiSpl2 interface
' IID = 0E8F51B8-8273-4906-8E7B-BE453FFD2E2B
' Inherited interface = IUnknown
' Note: Requires Windows Vista.
' ########################################################################################

#IF NOT %DEF(%IBidiSpl2_INTERFACE_DEFINED)
    %IBidiSpl2_INTERFACE_DEFINED = 1

$IID_IBidiSpl2 = GUID$("{0E8F51B8-8273-4906-8E7B-BE453FFD2E2B}")

INTERFACE IBidiSpl2 $IID_IBidiSpl2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD BindDevice ( _                                ' VTable offset = 12
     BYREF pszDeviceName AS WSTRINGZ _                  ' __in const LPCWSTR pszDeviceName
   , BYVAL dwAccess AS DWORD _                          ' __in const DWORD dwAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnbindDevice ( _                              ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendRecvXMLString ( _                         ' VTable offset = 20
     BYVAL bstrRequest AS WSTRING _                     ' __in BSTR bstrRequest
   , BYREF pbstrResponse AS WSTRING _                   ' __out BSTR *pbstrResponse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendRecvXMLStream ( _                         ' VTable offset = 24
     BYVAL pSRequest AS IStream _                       ' __in IStream *pSRequest
   , BYREF ppSResponse AS IStream _                     ' __out IStream **ppSResponse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBidiSpl2_INTERFACE_DEFINED__ */
