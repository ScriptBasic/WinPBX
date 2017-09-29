' ########################################################################################
' Microsoft Windows
' File: HTIface.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%HTIFACE_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "oleidl.inc"
#INCLUDE ONCE "urlmon.inc"

'//--------------------------------------------------------------------------
'// OLE Hyperlinking ITargetFrame Interfaces.

#INCLUDE ONCE "htiframe.inc"


' ########################################################################################
' Interface name = ITargetFrame
' IID = {86D52E11-94A8-11d0-82AF-00C04FD5AE38}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITargetFrame_INTERFACE_DEFINED)
    %ITargetFrame_INTERFACE_DEFINED = 1

' NAVIGATEFRAME_FLAGS enum
%NAVIGATEFRAME_FL_RECORD                   = &H1
%NAVIGATEFRAME_FL_POST                     = &H2
%NAVIGATEFRAME_FL_NO_DOC_CACHE             = &H4
%NAVIGATEFRAME_FL_NO_IMAGE_CACHE           = &H8
%NAVIGATEFRAME_FL_AUTH_FAIL_CACHE_OK       = &H10
%NAVIGATEFRAME_FL_SENDING_FROM_FORM        = &H20
%NAVIGATEFRAME_FL_REALLY_SENDING_FROM_FORM = &H40

' // Size = 20 bytes
TYPE NAVIGATEDATA DWORD
   ulTarget   AS DWORD   ' ULONG ulTarget
   ulURL      AS DWORD   ' ULONG ulURL
   ulRefURL   AS DWORD   ' ULONG ulRefURL
   ulPostData AS DWORD   ' ULONG ulPostData
   dwFlags    AS DWORD   ' DWORD dwFlags
END TYPE

$IID_ITargetFrame = GUID$("{D5F78C80-5252-11CF-90FA-00AA0042106E}")

INTERFACE ITargetFrame $IID_ITargetFrame

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
   METHOD FindFrame ( _                                 ' VTable offset = 24
     BYREF pszTargetName AS WSTRINGZ _                  ' __in LPCWSTR pszTargetName
   , BYVAL ppunkContextFrame AS IUnknown _              ' __in IUnknown *ppunkContextFrame
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppunkTargetFrame AS IUnknown _               ' __out IUnknown **ppunkTargetFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFrameSrc ( _                               ' VTable offset = 28
     BYREF pszFrameSrc AS WSTRINGZ _                    ' __in LPCWSTR pszFrameSrc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFrameSrc ( _                               ' VTable offset = 32
     BYREF ppszFrameSrc AS DWORD _                      ' __out LPWSTR *ppszFrameSrc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFramesContainer ( _                        ' VTable offset = 36
     BYREF ppContainer AS IOleContainer _               ' __out IOleContainer **ppContainer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFrameOptions ( _                           ' VTable offset = 40
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFrameOptions ( _                           ' VTable offset = 44
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFrameMargins ( _                           ' VTable offset = 48
     BYVAL dwWidth AS DWORD _                           ' __in DWORD dwWidth
   , BYVAL dwHeight AS DWORD _                          ' __in DWORD dwHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFrameMargins ( _                           ' VTable offset = 52
     BYREF pdwWidth AS DWORD _                          ' __out DWORD *pdwWidth
   , BYREF pdwHeight AS DWORD _                         ' __out DWORD *pdwHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoteNavigate ( _                            ' VTable offset = 56
     BYVAL cLength AS DWORD _                           ' __in ULONG cLength
   , BYVAL pulData AS DWORD _                           ' __in ULONG *pulData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnChildFrameActivate ( _                      ' VTable offset = 60
     BYVAL pUnkChildFrame AS IUnknown _                 ' __in IUnknown *pUnkChildFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnChildFrameDeactivate ( _                    ' VTable offset = 64
     BYVAL pUnkChildFrame AS IUnknown _                 ' __in IUnknown *pUnkChildFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITargetFrame_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITargetEmbedding
' IID = {548793C0-9E74-11CF-9655-00A0C9034923}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITargetEmbedding_INTERFACE_DEFINED)
    %ITargetEmbedding_INTERFACE_DEFINED = 1

$IID_ITargetEmbedding = GUID$("{548793C0-9E74-11CF-9655-00A0C9034923}")

INTERFACE ITargetEmbedding $IID_ITargetEmbedding

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTargetFrame ( _                            ' VTable offset = 12
     BYREF ppTargetFrame AS ITargetFrame _              ' __out ITargetFrame **ppTargetFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITargetEmbedding_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITargetFramePriv
' IID = {9216E421-2BF5-11D0-82B4-00A0C90C29C5}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITargetFramePriv_INTERFACE_DEFINED)
    %ITargetFramePriv_INTERFACE_DEFINED = 1

$IID_ITargetFramePriv = GUID$("{9216E421-2BF5-11D0-82B4-00A0C90C29C5}")

INTERFACE ITargetFramePriv $IID_ITargetFramePriv

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FindFrameDownwards ( _                        ' VTable offset = 12
     BYREF pszTargetName AS WSTRINGZ _                  ' __in LPCWSTR pszTargetName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppunkTargetFrame AS IUnknown _               ' __out IUnknown **ppunkTargetFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindFrameInContext ( _                        ' VTable offset = 16
     BYREF pszTargetName AS WSTRINGZ _                  ' __in LPCWSTR pszTargetName
   , BYREF punkContextFrame AS IUnknown _               ' __out IUnknown *punkContextFrame
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppunkTargetFrame AS IUnknown _               ' __out IUnknown **ppunkTargetFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnChildFrameActivate ( _                      ' VTable offset = 20
     BYVAL pUnkChildFrame AS IUnknown _                 ' __in IUnknown *pUnkChildFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnChildFrameDeactivate ( _                    ' VTable offset = 24
     BYVAL pUnkChildFrame AS IUnknown _                 ' __in IUnknown *pUnkChildFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NavigateHack ( _                              ' VTable offset = 28
     BYVAL grfHLNF AS DWORD _                           ' __in DWORD grfHLNF
   , BYVAL pbc AS IBindCtx _                            ' __in LPBC pbc
   , BYVAL pibsc AS IBindStatusCallback _               ' __in IBindStatusCallback *pibsc
   , BYREF pszTargetName AS WSTRINGZ _                  ' __in LPCWSTR pszTargetName
   , BYREF pszUrl AS WSTRINGZ _                         ' __in LPCWSTR pszUrl
   , BYREF pszLocation AS WSTRINGZ _                    ' __in LPCWSTR pszLocation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindBrowserByIndex ( _                        ' VTable offset = 32
     BYVAL dwID AS DWORD _                              ' __in DWORD dwID
   , BYREF ppunkBrowser AS IUnknown _                   ' __out IUnknown **ppunkBrowser
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITargetFramePriv_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITargetFramePriv2
' IID = {B2C867E6-69D6-46F2-A611-DED9A4BD7FEF}
' Inherited interface = ITargetFramePriv
' ########################################################################################

#IF NOT %DEF(%ITargetFramePriv2_INTERFACE_DEFINED)
    %ITargetFramePriv2_INTERFACE_DEFINED = 1

$IID_ITargetFramePriv2 = GUID$("{B2C867E6-69D6-46F2-A611-DED9A4BD7FEF}")

INTERFACE ITargetFramePriv2 $IID_ITargetFramePriv2

   INHERIT IUnknown

   ' =====================================================================================
   ' ITargetFramePriv methods
   ' =====================================================================================
   METHOD FindFrameDownwards ( _                        ' VTable offset = 12
     BYREF pszTargetName AS WSTRINGZ _                  ' __in LPCWSTR pszTargetName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppunkTargetFrame AS IUnknown _               ' __out IUnknown **ppunkTargetFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindFrameInContext ( _                        ' VTable offset = 16
     BYREF pszTargetName AS WSTRINGZ _                  ' __in LPCWSTR pszTargetName
   , BYREF punkContextFrame AS IUnknown _               ' __out IUnknown *punkContextFrame
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppunkTargetFrame AS IUnknown _               ' __out IUnknown **ppunkTargetFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnChildFrameActivate ( _                      ' VTable offset = 20
     BYVAL pUnkChildFrame AS IUnknown _                 ' __in IUnknown *pUnkChildFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnChildFrameDeactivate ( _                    ' VTable offset = 24
     BYVAL pUnkChildFrame AS IUnknown _                 ' __in IUnknown *pUnkChildFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NavigateHack ( _                              ' VTable offset = 28
     BYVAL grfHLNF AS DWORD _                           ' __in DWORD grfHLNF
   , BYVAL pbc AS IBindCtx _                            ' __in LPBC pbc
   , BYVAL pibsc AS IBindStatusCallback _               ' __in IBindStatusCallback *pibsc
   , BYREF pszTargetName AS WSTRINGZ _                  ' __in LPCWSTR pszTargetName
   , BYREF pszUrl AS WSTRINGZ _                         ' __in LPCWSTR pszUrl
   , BYREF pszLocation AS WSTRINGZ _                    ' __in LPCWSTR pszLocation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindBrowserByIndex ( _                        ' VTable offset = 32
     BYVAL dwID AS DWORD _                              ' __in DWORD dwID
   , BYREF ppunkBrowser AS IUnknown _                   ' __out IUnknown **ppunkBrowser
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ITargetFramePriv2 methods
   ' =====================================================================================
   METHOD AggregatedNavigation2 ( _                     ' VTable offset = 36
     BYVAL grfHLNF AS DWORD _                           ' __in DWORD grfHLNF
   , BYVAL pbc AS IBindCtx _                            ' __in LPBC pbc
   , BYVAL pibsc AS IBindStatusCallback _               ' __in IBindStatusCallback *pibsc
   , BYREF pszTargetName AS WSTRINGZ _                  ' __in LPCWSTR pszTargetName
   , BYVAL pUri AS IUri _                               ' __in IUri *pUri
   , BYREF pszLocation AS WSTRINGZ _                    ' __in LPCWSTR pszLocation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITargetFramePriv2_INTERFACE_DEFINED__ */
