' ########################################################################################
' Microsoft Windows
' File: HTIframe.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%HTIFRAME_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "oleidl.inc"

'//--------------------------------------------------------------------------
'// OLE Hyperlinking ITargetFrame2 Interfaces.

%TF_NAVIGATE = &H7FAEABAC
$TARGET_NOTIFY_OBJECT_NAME = "863A99A0-21BC-11D0-82B4-00A0C90C29C5"

' ########################################################################################
' Interface name = ITargetNotify
' IID = {863a99a0-21bc-11d0-82b4-00a0c90c29c5}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITargetNotify_INTERFACE_DEFINED)
    %ITargetNotify_INTERFACE_DEFINED = 1

$IID_ITargetNotify = GUID$("{863A99A0-21BC-11D0-82B4-00A0C90C29C5}")

INTERFACE ITargetNotify $IID_ITargetNotify

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnCreate ( _                                  ' VTable offset = 12
     BYVAL pUnkDestination AS IUnknown _                ' __in IUnknown *pUnkDestination
   , BYVAL cbCookie AS DWORD _                          ' __in ULONG cbCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnReuse ( _                                   ' VTable offset = 16
     BYVAL pUnkDestination AS IUnknown _                ' __in IUnknown *pUnkDestination
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITargetNotify_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITargetNotify2
' IID = {3050F6B1-98B5-11CF-BB82-00AA00BDCE0B}
' Inherited interface = ITargetNotify
' ########################################################################################

#IF NOT %DEF(%ITargetNotify2_INTERFACE_DEFINED)
    %ITargetNotify2_INTERFACE_DEFINED = 1

$IID_ITargetNotify2 = GUID$("{3050F6B1-98B5-11CF-BB82-00AA00BDCE0B}")

INTERFACE ITargetNotify2 $IID_ITargetNotify2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnCreate ( _                                  ' VTable offset = 12
     BYVAL pUnkDestination AS IUnknown _                ' __in IUnknown *pUnkDestination
   , BYVAL cbCookie AS DWORD _                          ' __in ULONG cbCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnReuse ( _                                   ' VTable offset = 16
     BYVAL pUnkDestination AS IUnknown _                ' __in IUnknown *pUnkDestination
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOptionString ( _                           ' VTable offset = 20
     BYREF pbstrOptions AS WSTRING _                    ' __inout BSTR *pbstrOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITargetNotify2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITargetFrame2
' IID = {86D52E11-94A8-11D0-82AF-00C04FD5AE38}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITargetFrame2_INTERFACE_DEFINED)
    %ITargetFrame2_INTERFACE_DEFINED = 1

' FINDFRAME_FLAGS enum
%FINDFRAME_NONE              = 0
%FINDFRAME_JUSTTESTEXISTENCE = 1
%FINDFRAME_INTERNAL          = &H80000000

' FRAMEOPTIONS_FLAGS enum
%FRAMEOPTIONS_SCROLL_YES    = &H1
%FRAMEOPTIONS_SCROLL_NO     = &H2
%FRAMEOPTIONS_SCROLL_AUTO   = &H4
%FRAMEOPTIONS_NORESIZE      = &H8
%FRAMEOPTIONS_NO3DBORDER    = &H10
%FRAMEOPTIONS_DESKTOP       = &H20
%FRAMEOPTIONS_BROWSERBAND   = &H40

$IID_ITargetFrame2 = GUID$("{86D52E11-94A8-11D0-82AF-00C04FD5AE38}")

INTERFACE ITargetFrame2 $IID_ITargetFrame2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetFrameName ( _                              ' VTable offset = 12
     BYREF pszFrameName AS WSTRINGZ _                   ' __in LPCWSTR pszFrameName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFrameName ( _                              ' VTable offset = 16
     BYREF ppszFrameName AS DWORD _                     ' __out LPWSTR *ppszFrameName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParentFrame ( _                            ' VTable offset = 20
     BYREF ppunkParent AS IUnknown _                    ' __out IUnknown **ppunkParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFrameSrc ( _                               ' VTable offset = 24
     BYREF pszFrameSrc AS WSTRINGZ _                    ' __in LPCWSTR pszFrameSrc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFrameSrc ( _                               ' VTable offset = 28
     BYREF ppszFrameSrc AS DWORD _                      ' __out LPWSTR *ppszFrameSrc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFramesContainer ( _                        ' VTable offset = 32
     BYREF ppContainer AS IOleContainer _               ' __out IOleContainer **ppContainer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFrameOptions ( _                           ' VTable offset = 36
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFrameOptions ( _                           ' VTable offset = 40
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFrameMargins ( _                           ' VTable offset = 44
     BYVAL dwWidth AS DWORD _                           ' __in DWORD dwWidth
   , BYVAL dwHeight AS DWORD _                          ' __in DWORD dwHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFrameMargins ( _                           ' VTable offset = 44
     BYREF pdwWidth AS DWORD _                          ' __out DWORD *pdwWidth
   , BYREF pdwHeight AS DWORD _                         ' __out DWORD *pdwHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindFrame ( _                                 ' VTable offset = 48
     BYREF pszTargetName AS WSTRINGZ _                  ' __in LPCWSTR pszTargetName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppunkTargetFrame AS IUnknown _               ' __out IUnknown **ppunkTargetFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTargetAlias ( _                            ' VTable offset = 52
     BYREF pszTargetName AS WSTRINGZ _                  ' __in LPCWSTR pszTargetName
   , BYREF ppszTargetAlias AS DWORD _                   ' __out LPWSTR *ppszTargetAlias
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITargetFrame2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITargetContainer
' IID = {7847EC01-2BEC-11D0-82B4-00A0C90C29C5}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITargetContainer_INTERFACE_DEFINED)
    %ITargetContainer_INTERFACE_DEFINED = 1

$IID_ITargetContainer = GUID$("{7847EC01-2BEC-11D0-82B4-00A0C90C29C5}")

INTERFACE ITargetContainer $IID_ITargetContainer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFrameUrl ( _                               ' VTable offset = 12
     BYREF ppszFrameSrc AS DWORD _                      ' __out LPWSTR *ppszFrameSrc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFramesContainer ( _                        ' VTable offset = 16
     BYREF ppContainer AS IOleContainer _               ' __out IOleContainer **ppContainer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITargetContainer_INTERFACE_DEFINED__ */
