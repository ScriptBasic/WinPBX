' ########################################################################################
' Microsoft Windows
' File: DocObjectService.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DOCOBJECTSERVICE_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "mshtml.inc"

' ########################################################################################
' Interface name = IDocObjectService
' IID = 3050F801-98B5-11CF-BB82-00AA00BDCE0B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDocObjectService_INTERFACE_DEFINED)
    %IDocObjectService_INTERFACE_DEFINED = 1

$IID_IDocObjectService = GUID$("{3050F801-98B5-11CF-BB82-00AA00BDCE0B}")

INTERFACE IDocObjectService $IID_IDocObjectService

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FireBeforeNavigate2 ( _                       ' VTable offset = 12
     BYVAL pDispatch AS IDispatch _                     ' __in IDispatch *pDispatch
   , BYREF lpszUrl AS WSTRINGZ _                        ' __in LPCWSTR lpszUrl
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpszFrameName AS WSTRINGZ _                  ' __in LPCWSTR lpszFrameName
   , BYVAL pPostData AS BYTE PTR _                      ' __in BYTE *pPostData
   , BYVAL cbPostData AS DWORD _                        ' __in DWORD cbPostData
   , BYREF lpszHeaders AS WSTRINGZ _                    ' __in LPCWSTR lpszHeaders
   , BYVAL fPlayNavSound AS LONG _                      ' __in BOOL fPlayNavSound
   , BYREF pfCancel AS LONG _                           ' __out BOOL *pfCancel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FireNavigateComplete2 ( _                     ' VTable offset = 16
     BYVAL pHTMLWindow2 AS IHTMLWindow2 _               ' __in IHTMLWindow2 *pHTMLWindow2
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FireDownloadBegin ( _                         ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FireDownloadComplete ( _                      ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FireDocumentComplete ( _                      ' VTable offset = 28
     BYVAL pHTMLWindow AS IHTMLWindow2 _                ' __in IHTMLWindow2 *pHTMLWindow
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateDesktopComponent ( _                    ' VTable offset = 32
     BYVAL pHTMLWindow AS IHTMLWindow2 _                ' __in IHTMLWindow2 *pHTMLWindow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPendingUrl ( _                             ' VTable offset = 36
     BYREF pbstrPendingUrl AS WSTRING _                 ' __out BSTR *pbstrPendingUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ActiveElementChanged ( _                      ' VTable offset = 40
     BYVAL pHTMLElement AS IHTMLElement _               '  __in IHTMLElement *pHTMLElement
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUrlSearchComponent ( _                     ' VTable offset = 44
     BYREF pbstrSearch AS WSTRING _                     ' __out BSTR *pbstrSearch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsErrorUrl ( _                                ' VTable offset = 48
     BYREF lpszUrlAS AS WSTRINGZ _                      ' __in LPCWSTR lpszUrl
   , BYREF pfIsError AS LONG _                          ' __out BOOL *pfIsError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDocObjectService_INTERFACE_DEFINED__ */
