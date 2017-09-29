' ########################################################################################
' Microsoft Windows
' File: mixerocx.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MIXEROCX_INC = 1

#INCLUDE ONCE "unknwn.inc"

' ########################################################################################
' Interface name = IMixerOCXNotify
' IID = {81A3BD31-DEE1-11D1-8508-00A0C91F9CA0}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IMixerOCXNotify = GUID$("{81A3BD31-DEE1-11D1-8508-00A0C91F9CA0}")

INTERFACE IMixerOCXNotify $IID_IMixerOCXNotify

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnInvalidateRect ( _                          ' VTable offset = 12
     BYREF lpcRect AS RECT _                            ' __in LPCRECT lpcRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnStatusChange ( _                            ' VTable offset = 16
     BYVAL ulStatusFlags AS DWORD _                     ' __in ULONG ulStatusFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDataChange ( _                              ' VTable offset = 20
     BYVAL ulDataFlags AS DWORD _                       ' __in ULONG ulDataFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IMixerOCX
' IID = {81A3BD32-DEE1-11D1-8508-00A0C91F9CA0}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IMixerOCX = GUID$("{81A3BD32-DEE1-11D1-8508-00A0C91F9CA0}")

INTERFACE IMixerOCX $IID_IMixerOCX

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnDisplayChange ( _                           ' VTable offset = 12
     BYVAL ulBitsPerPixel AS DWORD _                    ' __in ULONG ulBitsPerPixel
   , BYVAL ulScreenWidth AS DWORD _                     ' __in ULONG ulScreenWidth
   , BYVAL ulScreenHeight AS DWORD _                    ' __in ULONG ulScreenHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAspectRatio ( _                            ' VTable offset = 16
     BYREF pdwPictAspectRatioX AS DWORD _               ' __out LPDWORD pdwPictAspectRatioX
   , BYREF pdwPictAspectRatioY AS DWORD _               ' __out LPDWORD pdwPictAspectRatioY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoSize ( _                              ' VTable offset = 20
     BYREF pdwVideoWidth AS DWORD _                     ' __out LPDWORD pdwVideoWidth
   , BYREF pdwVideoHeight AS DWORD _                    ' __out LPDWORD pdwVideoHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 24
     BYREF pdwStatus AS DWORD _                         ' __out LPDWORD *pdwStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDrawRegion ( _                             ' VTable offset = 28
     BYVAL hdcDraw AS DWORD _                           ' __in HDC hdcDraw
   , BYREF prcDraw AS RECT _                            ' __in LPCRECT prcDraw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDraw ( _                                    ' VTable offset = 32
     BYREF lpptTopLeftSC AS POINT _                     ' __in LPPOINT lpptTopLeftSC
   , BYREF prcDrawCC AS RECT _                          ' __in LPCRECT prcDrawCC
   , BYREF lprcClip AS RECT _                           ' __in LPCRECT lprcClip
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 36
     BYVAL pmdns AS IMixerOCXNotify _                   ' __in IMixerOCXNotify *pmdns
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE
