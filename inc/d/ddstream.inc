' ########################################################################################
' Microsoft Windows
' File: ddstream.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DDSTREAM_INC = 1

#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "mmstream.inc"
#INCLUDE ONCE "ddraw.inc"

'enum __MIDL___MIDL_itf_ddstream_0000_0001
%DDSFF_PROGRESSIVERENDER = &H1

' ########################################################################################
' Interface name = IDirectDrawMediaStream
' IID = {F4104FCE-9A70-11D0-8FDE-00C04FD9189D}
' Inherited interface = IMediaStream
' ########################################################################################

#IF NOT %DEF(%IDirectDrawMediaStream_INTERFACE_DEFINED)
    %IDirectDrawMediaStream_INTERFACE_DEFINED = 1

$IID_IDirectDrawMediaStream = GUID$("{F4104FCE-9A70-11D0-8FDE-00C04FD9189D}")

INTERFACE IDirectDrawMediaStream $IID_IDirectDrawMediaStream

   INHERIT IUnknown

   ' =====================================================================================
   ' IMediaStream Methods
   ' =====================================================================================
   METHOD GetMultiMediaStream ( _                       ' VTable offset = 12
     BYREF ppMultiMediaStream AS IMultiMediaStream _    ' __out IMultiMediaStream **ppMultiMediaStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInformation ( _                            ' VTable offset = 16
     BYREF pPurposeId AS GUID _                         ' __out MSPID *pPurposeId
   , BYREF pType AS DWORD _                             ' __out STREAM_TYPE *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSameFormat ( _                             ' VTable offset = 20
     BYVAL pStreamThatHasDesiredFormat AS IMediaStream _  ' __in IMediaStream *pStreamThatHasDesiredFormat
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AllocateSample ( _                            ' VTable offset = 24
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppSample AS IStreamSample _                  ' __out IStreamSample **ppSample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSharedSample ( _                        ' VTable offset = 28
     BYVAL pExistingSample AS IStreamSample _           ' __in IStreamSample *pExistingSample
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppNewSample AS IStreamSample _               ' __out IStreamSample **ppNewSample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendEndOfStream ( _                           ' VTable offset = 32
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectDrawMediaStream
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 36
     BYREF pDDSDCurrent AS DDSURFACEDESC _              ' __out DDSURFACEDESC *pDDSDCurrent
   , BYREF ppDirectDrawPalette AS IDirectDrawPalette _  ' __out IDirectDrawPalette **ppDirectDrawPalette
   , BYREF DDSURFACEDESC _                              ' __out DDSURFACEDESC *pDDSDDesired
   , BYREF pDDSDDesired AS DWORD _                      ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFormat ( _                                 ' VTable offset = 40
     BYREF pDDSurfaceDesc AS DDSURFACEDESC _            ' __in const DDSURFACEDESC *pDDSurfaceDesc
   , BYVAL pDirectDrawPalette AS IDirectDrawPalette _   ' __in IDirectDrawPalette *pDirectDrawPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDirectDraw ( _                             ' VTable offset = 44
     BYREF ppDirectDraw AS IDirectDraw _                ' __out IDirectDraw **ppDirectDraw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDirectDraw ( _                             ' VTable offset = 48
     BYVAL pDirectDraw AS IDirectDraw _                 ' __in IDirectDraw *pDirectDraw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSample ( _                              ' VTable offset = 52
     BYVAL pSurface AS IDirectDrawSurface _             ' __in IDirectDrawSurface *pSurface
   , BYREF pRect AS RECT _                              ' __in const RECT *pRect
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppSample AS IDirectDrawStreamSample _        ' __out IDirectDrawStreamSample **ppSample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTimePerFrame ( _                           ' VTable offset = 56
     BYREF pFrameTime AS QUAD _                         ' __out STREAM_TIME *pFrameTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDirectDrawMediaStream_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDirectDrawStreamSample
' IID = {F4104FCF-9A70-11D0-8FDE-00C04FD9189D}
' Inherited interface = IStreamSample
' ########################################################################################

#IF NOT %DEF(%IDirectDrawStreamSample_INTERFACE_DEFINED)
   %IDirectDrawStreamSample_INTERFACE_DEFINED = 1

$IID_IDirectDrawStreamSample = GUID$("{F4104FCF-9A70-11D0-8FDE-00C04FD9189D}")

INTERFACE IDirectDrawStreamSample $IID_IDirectDrawStreamSample

   INHERIT IUnknown

   ' =====================================================================================
   ' IStreamSample Methods
   ' =====================================================================================
   METHOD GetMediaStream ( _                            ' VTable offset = 12
     BYREF ppMediaStream AS IMediaStream _              ' __out IMediaStream **ppMediaStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSampleTimes ( _                            ' VTable offset = 16
     BYREF pStartTime AS QUAD _                         ' __out STREAM_TIME *pStartTime
   , BYREF pEndTime AS QUAD _                           ' __out STREAM_TIME *pEndTime
   , BYREF pCurrentTime AS QUAD _                       ' __out STREAM_TIME *pCurrentTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSampleTimes ( _                            ' VTable offset = 20
     BYVAL pStartTime AS QUAD _                         ' __in const STREAM_TIME *pStartTime
   , BYVAL pEndTime AS QUAD _                           ' __in const STREAM_TIME *pEndTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Update ( _                                    ' VTable offset = 24
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL hEvent AS DWORD _                            ' __in HANDLE hEvent
   , BYVAL pfnAPC AS DWORD _                            ' __in PAPCFUNC pfnAPC
   , BYVAL dwAPCData AS DWORD _                         ' __in DWORD_PTR dwAPCData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompletionStatus ( _                          ' VTable offset = 28
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwMilliseconds AS DWORD _                    ' __in DWORD dwMilliseconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectDrawStreamSample Methods
   ' =====================================================================================
   METHOD GetSurface ( _                                ' VTable offset = 32
     BYREF ppDirectDrawSurface AS IDirectDrawSurface _  ' __out IDirectDrawSurface **ppDirectDrawSurface
   , BYREF pRect AS RECT _                              ' __out RECT *pRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRect ( _                                   ' VTable offset = 36
     BYREF pRect AS RECT _                              ' __in const RECT *pRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDirectDrawStreamSample_INTERFACE_DEFINED__ */
