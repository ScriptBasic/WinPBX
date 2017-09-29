' ########################################################################################
' Microsoft Windows
' File: ocmm.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%OCMM_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "oleidl.inc"

%SURFACE_LOCK_EXCLUSIVE          = &H01
%SURFACE_LOCK_ALLOW_DISCARD      = &H02
%SURFACE_LOCK_WAIT               = &H04

%E_SURFACE_NOSURFACE             = &H8000C000???
%E_SURFACE_UNKNOWN_FORMAT        = &H8000C001???
%E_SURFACE_NOTMYPOINTER          = &H8000C002???
%E_SURFACE_DISCARDED             = &H8000C003???
%E_SURFACE_NODC                  = &H8000C004???
%E_SURFACE_NOTMYDC               = &H8000C005???
%S_SURFACE_DISCARDED             = &H0000C003???

'typedef GUID BFID;

'#ifndef RGBQUAD_DEFINED
'#define RGBQUAD_DEFINED
'typedef struct tagRGBQUAD RGBQUAD;
'#endif

$BFID_MONOCHROME  = GUID$("{E436EB78-524F-11CE-9F53-0020AF0BA770}")
$BFID_RGB_4       = GUID$("{E436EB79-524F-11CE-9F53-0020AF0BA770}")
$BFID_RGB_8       = GUID$("{E436EB7A-524F-11CE-9F53-0020AF0BA770}")
$BFID_RGB_555     = GUID$("{E436EB7C-524F-11CE-9F53-0020AF0BA770}")
$BFID_RGB_565     = GUID$("{E436EB7B-524F-11CE-9F53-0020AF0BA770}")
$BFID_RGB_24      = GUID$("{E436EB7D-524F-11CE-9F53-0020AF0BA770}")
$BFID_RGB_32      = GUID$("{E436EB7E-524F-11CE-9F53-0020AF0BA770}")
$BFID_RGBA_32     = GUID$("{773C9AC0-3274-110D-B724-00AA006C1A01}")
$BFID_GRAY_8      = GUID$("{D93DE910-449C-11D0-918C-00AA006C1A01}")
$BFID_GRAY_16     = GUID$("{F9D6BC00-449C-11D0-918C-00AA006C1A01}")

'#define SID_SDirectDraw3 IID_IDirectDraw3
$IID_IDirectDraw3 = GUID$("{618F8AD4-8B7A-11D0-8FCC-00C04FD9189D}")

%COLOR_NO_TRANSPARENT = &HFFFFFFFF

%IMGDECODE_EVENT_PROGRESS     = &H01
%IMGDECODE_EVENT_PALETTE      = &H02
%IMGDECODE_EVENT_BEGINBITS    = &H04
%IMGDECODE_EVENT_BITSCOMPLETE = &H08
%IMGDECODE_EVENT_USEDDRAW     = &H10

%IMGDECODE_HINT_TOPDOWN       = &H01
%IMGDECODE_HINT_BOTTOMUP      = &H02
%IMGDECODE_HINT_FULLWIDTH     = &H04

%MAPMIME_DEFAULT              = 0
%MAPMIME_CLSID                = 1
%MAPMIME_DISABLE              = 2
%MAPMIME_DEFAULT_ALWAYS       = 3

$BFID_INDEXED_RGB_8 = $BFID_RGB_8
$BFID_INDEXED_RGB_4 = $BFID_RGB_4
$BFID_INDEXED_RGB_1 = $BFID_MONOCHROME

$CLSID_IImageDecodeFilter = GUID$("{607FD4E8-0A03-11D1-AB1D-00C04FC9B304}")

$NAMEDTIMER_DRAW = GUID$("{3050F362-98B5-11CF-BB82-00AA00BDCE0B}")


' ########################################################################################
' Interface name = ITimerService
' IID = 3050F35F-98B5-11CF-BB82-00AA00BDCE0B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITimerService_INTERFACE_DEFINED)
    %ITimerService_INTERFACE_DEFINED = 1

$IID_ITimerService = GUID$("{3050F35F-98B5-11CF-BB82-00AA00BDCE0B}")

INTERFACE ITimerService $IID_ITimerService

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateTimer ( _                               ' VTable offset = 12
     BYVAL pReferenceTimer AS ITimer _                  ' __in ITimer *pReferenceTimer
   , BYREF ppNewTimer AS ITimer _                       ' __out ITimer **ppNewTimer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNamedTimer ( _                             ' VTable offset = 16
     BYREF rguidName AS GUID _                          ' __in REFGUID rguidName
   , BYREF ppTimer AS ITimer _                          ' __out ITimer **ppTimer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNamedTimerReference ( _                    ' VTable offset = 20
     BYREF rguidName AS GUID _                          ' __in REFGUID rguidName
   , BYVAL pReferenceTimer AS ITimer _                  ' __in ITimer *pReferenceTimer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITimerService_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITimer
' IID = 3050F360-98B5-11CF-BB82-00AA00BDCE0B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITimer_INTERFACE_DEFINED)
    %ITimer_INTERFACE_DEFINED = 1

$IID_ITimer = GUID$("{3050F360-98B5-11CF-BB82-00AA00BDCE0B}")

INTERFACE ITimer $IID_ITimer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 12
     BYVAL vtimeMin AS VARIANT _                        ' __in VARIANT vtimeMin
   , BYVAL vtimeMax AS VARIANT _                        ' __in VARIANT vtimeMax
   , BYVAL vtimeInterval AS VARIANT _                   ' __in VARIANT vtimeInterval
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pTimerSink AS ITimerSink _                   ' __in ITimerSink *pTimerSink
   , BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 16
     BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Freeze ( _                                    ' VTable offset = 20
     BYVAL fFreeze AS LONG _                            ' __in BOOL fFreeze
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTime ( _                                   ' VTable offset = 24
     BYREF pvtime AS VARIANT _                          ' __out VARIANT *pvtime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITimer_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITimerEx
' IID = 30510414-98B5-11CF-BB82-00AA00BDCE0B
' Inherited interface = ITimer
' ########################################################################################

#IF NOT %DEF(%ITimerEx_INTERFACE_DEFINED)
    %ITimerEx_INTERFACE_DEFINED = 1

$IID_ITimerEx = GUID$("{30510414-98B5-11CF-BB82-00AA00BDCE0B}")

INTERFACE ITimerEx $IID_ITimerEx

   INHERIT IUnknown

   ' =====================================================================================
   ' ITimer methods
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 12
     BYVAL vtimeMin AS VARIANT _                        ' __in VARIANT vtimeMin
   , BYVAL vtimeMax AS VARIANT _                        ' __in VARIANT vtimeMax
   , BYVAL vtimeInterval AS VARIANT _                   ' __in VARIANT vtimeInterval
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pTimerSink AS ITimerSink _                   ' __in ITimerSink *pTimerSink
   , BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 16
     BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Freeze ( _                                    ' VTable offset = 20
     BYVAL fFreeze AS LONG _                            ' __in BOOL fFreeze
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTime ( _                                   ' VTable offset = 24
     BYREF pvtime AS VARIANT _                          ' __out VARIANT *pvtime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ITimerEx methods
   ' =====================================================================================
   METHOD SetMode ( _                                   ' VTable offset = 28
     BYVAL dwMode AS DWORD _                            ' __in DWORD dwMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITimerEx_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ITimerSink
' IID = 3050F361-98B5-11CF-BB82-00AA00BDCE0B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITimerSink_INTERFACE_DEFINED)
    %ITimerSink_INTERFACE_DEFINED = 1

$IID_ITimerSink = GUID$("{3050F361-98B5-11CF-BB82-00AA00BDCE0B}")

INTERFACE ITimerSink $IID_ITimerSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnTimer ( _                                   ' VTable offset = 12
     BYVAL vtimeAdvise AS VARIANT _                     ' __in VARIANT vtimeAdvise
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITimerSink_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMapMIMEToCLSID
' IID = D9E89500-30FA-11D0-B724-00AA006C1A01
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMapMIMEToCLSID_INTERFACE_DEFINED)
    %IMapMIMEToCLSID_INTERFACE_DEFINED = 1

$IID_IMapMIMEToCLSID = GUID$("{D9E89500-30FA-11D0-B724-00AA006C1A01}")

INTERFACE IMapMIMEToCLSID $IID_IMapMIMEToCLSID

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EnableDefaultMappings ( _                     ' VTable offset = 12
     BYVAL bEnable AS LONG _                            ' __in BOOL bEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MapMIMEToCLSID ( _                            ' VTable offset = 16
     BYREF pszMIMEType AS WSTRINGZ _                    ' __in LPCOLESTR pszMIMEType
   , BYREF pCLSID AS GUID _                             ' __in CLSID *pCLSID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMapping ( _                                ' VTable offset = 20
     BYREF pszMIMEType AS WSTRINGZ _                    ' __in LPCOLESTR pszMIMEType
   , BYVAL dwMapMode AS DWORD _                         ' __in DWORD dwMapMode
   , BYREF pCLSID AS GUID _                             ' __in CLSID *pCLSID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMapMIMEToCLSID_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IImageDecodeFilter
' IID = A3CCEDF3-2DE2-11D0-86F4-00A0C913F750
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IImageDecodeFilter_INTERFACE_DEFINED)
    %IImageDecodeFilter_INTERFACE_DEFINED = 1

$IID_IImageDecodeFilter = GUID$("{A3CCEDF3-2DE2-11D0-86F4-00A0C913F750}")

INTERFACE IImageDecodeFilter $IID_IImageDecodeFilter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pEventSink AS IImageDecodeEventSink _        ' __in IImageDecodeEventSink *pEventSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Process ( _                                   ' VTable offset = 16
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Terminate ( _                                 ' VTable offset = 20
     BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IImageDecodeFilter_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IImageDecodeEventSink
' IID = A3CCEDF3-2DE2-11D0-86F4-00A0C913F750
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IImageDecodeEventSink_INTERFACE_DEFINED)
    %IImageDecodeEventSink_INTERFACE_DEFINED = 1

$IID_IImageDecodeEventSink = GUID$("{A3CCEDF3-2DE2-11D0-86F4-00A0C913F750}")

INTERFACE IImageDecodeEventSink $IID_IImageDecodeEventSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSurface ( _                                ' VTable offset = 12
     BYVAL nWidth AS LONG _                             ' __in LONG nWidth
   , BYVAL nHeight AS LONG _                            ' __in LONG nHeight
   , BYREF bfid AS GUID _                               ' __in REFGUID bfid
   , BYVAL nPasses AS DWORD _                           ' __in ULONG nPasses
   , BYVAL dwHints AS DWORD _                           ' __in DWORD dwHints
   , BYREF ppSurface AS IUnknown _                      ' __out IUnknown **ppSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnBeginDecode ( _                             ' VTable offset = 16
     BYREF pdwEvents AS DWORD _                         ' __out DWORD *pdwEvents
   , BYREF pnFormats AS DWORD _                         ' __out ULONG *pnFormats
   , BYREF ppFormats AS GUID _                          ' __out BFID **ppFormats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnBitsComplete ( _                            ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDecodeComplete ( _                          ' VTable offset = 24
     BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnPalette ( _                                 ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnProgress ( _                                ' VTable offset = 32
     BYREF pBounds AS RECT _                            ' __in RECT *pBounds
   , BYVAL bComplete AS LONG _                          ' __in BOOL bComplete
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IImageDecodeEventSink_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IImageDecodeEventSink2
' IID = 8EBD8A57-8A96-48C9-84A6-962E2DB9C931
' Inherited interface = IImageDecodeEventSink
' ########################################################################################

#IF NOT %DEF(%IImageDecodeEventSink2_INTERFACE_DEFINED)
    %IImageDecodeEventSink2_INTERFACE_DEFINED = 1

$IID_IImageDecodeEventSink2 = GUID$("{8EBD8A57-8A96-48C9-84A6-962E2DB9C931}")

INTERFACE IImageDecodeEventSink2 $IID_IImageDecodeEventSink2

   INHERIT IUnknown

   ' =====================================================================================
   ' IImageDecodeEventSink methods
   ' =====================================================================================
   METHOD GetSurface ( _                                ' VTable offset = 12
     BYVAL nWidth AS LONG _                             ' __in LONG nWidth
   , BYVAL nHeight AS LONG _                            ' __in LONG nHeight
   , BYREF bfid AS GUID _                               ' __in REFGUID bfid
   , BYVAL nPasses AS DWORD _                           ' __in ULONG nPasses
   , BYVAL dwHints AS DWORD _                           ' __in DWORD dwHints
   , BYREF ppSurface AS IUnknown _                      ' __out IUnknown **ppSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnBeginDecode ( _                             ' VTable offset = 16
     BYREF pdwEvents AS DWORD _                         ' __out DWORD *pdwEvents
   , BYREF pnFormats AS DWORD _                         ' __out ULONG *pnFormats
   , BYREF ppFormats AS GUID _                          ' __out BFID **ppFormats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnBitsComplete ( _                            ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDecodeComplete ( _                          ' VTable offset = 24
     BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnPalette ( _                                 ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnProgress ( _                                ' VTable offset = 32
     BYREF pBounds AS RECT _                            ' __in RECT *pBounds
   , BYVAL bComplete AS LONG _                          ' __in BOOL bComplete
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IImageDecodeEventSink2 methods
   ' =====================================================================================
   METHOD IsAlphaPremultRequired ( _                    ' VTable offset = 36
     BYREF pfPremultAlpha AS LONG _                     ' __out BOOL *pfPremultAlpha
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IImageDecodeEventSink2_INTERFACE_DEFINED__ */
