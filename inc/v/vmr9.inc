' ########################################################################################
' Microsoft Windows
' File: vmr9.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%VMR9_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "strmif.inc"
#INCLUDE ONCE "d3d9.inc"

' enum VMR9PresentationFlags
%VMR9Sample_SyncPoint        = &H1
%VMR9Sample_Preroll          = &H2
%VMR9Sample_Discontinuity    = &H4
%VMR9Sample_TimeValid        = &H8
%VMR9Sample_SrcDstRectsValid = &H10

' // Size = 72 bytes
TYPE VMR9PresentationInfo   ' Must be 8 byte aligned
   dwFlags       AS DWORD         ' DWORD dwFlags
   lpSurf        AS DWORD PTR     ' IDirect3DSurface9 *lpSurf
   rtStart       AS QUAD          ' REFERENCE_TIME rtStart
   rtEnd         AS QUAD          ' REFERENCE_TIME rtEnd
   szAspectRatio AS SIZE          ' SIZE szAspectRatio
   rcSrc         AS RECT          ' RECT rcSrc
   rcDst         AS RECT          ' RECT rcDst
   dwReserved1   AS DWORD         ' DWORD dwReserved1
   dwReserved2   AS DWORD         ' DWORD dwReserved2
END TYPE

' ########################################################################################
' Interface name = IVMRImagePresenter9
' IID = {69188C61-12A3-40F0-8FFC-342E7B433FD7}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IVMRImagePresenter9 = GUID$("{69188C61-12A3-40F0-8FFC-342E7B433FD7}")

INTERFACE IVMRImagePresenter9 $IID_IVMRImagePresenter9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD StartPresenting ( _                           ' VTable offset = 12
     BYVAL dwUserID AS DWORD _                          ' __in DWORD_PTR dwUserID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StopPresenting ( _                            ' VTable offset = 16
     BYVAL dwUserID AS DWORD _                          ' __in DWORD_PTR dwUserID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PresentImage ( _                              ' VTable offset = 29
     BYVAL dwUserID AS DWORD _                          ' __in DWORD_PTR dwUserID
   , BYREF lpPresInfo AS VMR9PresentationInfo _         ' __in VMR9PresentationInfo *lpPresInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################

' enum VMR9SurfaceAllocationFlags
%VMR9AllocFlag_3DRenderTarget   = &H1
%VMR9AllocFlag_DXVATarget       = &H2
%VMR9AllocFlag_TextureSurface   = &H4
%VMR9AllocFlag_OffscreenSurface = &H8
%VMR9AllocFlag_RGBDynamicSwitch = &H10
%VMR9AllocFlag_UsageReserved    = &HE0
%VMR9AllocFlag_UsageMask        = &HFF

' // Size = 40 bytes
TYPE VMR9AllocationInfo DWORD
   dwFlags       AS DWORD     ' DWORD dwFlags
   dwWidth       AS DWORD   ' DWORD dwWidth
   dwHeight      AS DWORD   ' DWORD dwHeight
   Format        AS DWORD   ' D3DFORMAT Format
   Pool          AS DWORD   ' D3DPOOL Pool
   MinBuffers    AS DWORD   ' DWORD MinBuffers
   szAspectRatio AS SIZE    ' SIZE szAspectRatio
   szNativeSize  AS SIZE    ' SIZE szNativeSize
END TYPE


' ########################################################################################
' Interface name = IVMRSurfaceAllocator9
' IID = {8D5148EA-3F5D-46CF-9DF1-D1B896EEDB1F}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IVMRSurfaceAllocator9 = GUID$("{8D5148EA-3F5D-46CF-9DF1-D1B896EEDB1F}")

INTERFACE IVMRSurfaceAllocator9 $IID_IVMRSurfaceAllocator9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitializeDevice ( _                          ' VTable offset = 12
     BYVAL dwUserID AS DWORD _                          ' __in DWORD_PTR dwUserID
   , BYREF lpAllocInfo AS VMR9AllocationInfo _          ' __in VMR9AllocationInfo *lpAllocInfo
   , BYREF lpNumBuffers AS DWORD _                      ' __inout DWORD *lpNumBuffers
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TerminateDevice ( _                           ' VTable offset = 16
     BYVAL dwID AS DWORD _                              ' __in DWORD_PTR dwID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSurface ( _                                ' VTable offset = 20
     BYVAL dwUserID AS DWORD _                          ' __in DWORD_PTR dwUserID
   , BYVAL SurfaceIndex AS DWORD _                      ' __in DWORD SurfaceIndex
   , BYVAL SurfaceFlags AS DWORD _                      ' __in DWORD SurfaceFlags
   , BYREF lplpSurface AS IDirect3DSurface9 _           ' __out IDirect3DSurface9 **lplpSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AdviseNotify ( _                              ' VTable offset = 24
     BYVAL lpIVMRSurfAllocNotify AS IVMRSurfaceAllocatorNotify9 _ ' __in IVMRSurfaceAllocatorNotify9 *lpIVMRSurfAllocNotify
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' Interface name = IVMRSurfaceAllocatorEx9
' IID = {8D5148EA-3F5D-46CF-9DF1-D1B896EEDB1F}
' Inherited interface = IVMRSurfaceAllocator9
' ########################################################################################

$IID_IVMRSurfaceAllocatorEx9 = GUID$("{6DE9A68A-A928-4522-BF57-655AE3866456}")

INTERFACE IVMRSurfaceAllocatorEx9 $IID_IVMRSurfaceAllocatorEx9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitializeDevice ( _                          ' VTable offset = 12
     BYVAL dwUserID AS DWORD _                          ' __in DWORD_PTR dwUserID
   , BYREF lpAllocInfo AS VMR9AllocationInfo _          ' __in VMR9AllocationInfo *lpAllocInfo
   , BYREF lpNumBuffers AS DWORD _                      ' __inout DWORD *lpNumBuffers
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TerminateDevice ( _                           ' VTable offset = 16
     BYVAL dwID AS DWORD _                              ' __in DWORD_PTR dwID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSurface ( _                                ' VTable offset = 20
     BYVAL dwUserID AS DWORD _                          ' __in DWORD_PTR dwUserID
   , BYVAL SurfaceIndex AS DWORD _                      ' __in DWORD SurfaceIndex
   , BYVAL SurfaceFlags AS DWORD _                      ' __in DWORD SurfaceFlags
   , BYREF lplpSurface AS IDirect3DSurface9 _           ' __out IDirect3DSurface9 **lplpSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AdviseNotify ( _                              ' VTable offset = 24
     BYVAL lpIVMRSurfAllocNotify AS IVMRSurfaceAllocatorNotify9 _ ' __in IVMRSurfaceAllocatorNotify9 *lpIVMRSurfAllocNotify
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSurfaceEx ( _                              ' VTable offset = 28
     BYVAL dwUserID AS DWORD _                          ' __in DWORD_PTR dwUserID
   , BYVAL SurfaceIndex AS DWORD _                      ' __in DWORD SurfaceIndex
   , BYVAL SurfaceFlags AS DWORD _                      ' __in DWORD SurfaceFlags
   , BYREF lplpSurface AS IDirect3DSurface9 _           ' __out IDirect3DSurface9 **lplpSurface
   , BYREF lprcDst AS RECT _                            ' __out RECT *lprcDst
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' Interface name = IVMRSurfaceAllocatorNotify9
' IID = {DCA3F5DF-BB3A-4D03-BD81-84614BFBFA0C}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IVMRSurfaceAllocatorNotify9 = GUID$("{DCA3F5DF-BB3A-4D03-BD81-84614BFBFA0C}")

INTERFACE IVMRSurfaceAllocatorNotify9 $IID_IVMRSurfaceAllocatorNotify9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AdviseSurfaceAllocator ( _                    ' VTable offset = 12
     BYVAL dwUserID AS DWORD _                          ' __in DWORD_PTR dwUserID
   , BYVAL lpIVRMSurfaceAllocator AS IVMRSurfaceAllocator9 _ ' __in IVMRSurfaceAllocator9 *lpIVRMSurfaceAllocator
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetD3DDevice ( _                              ' VTable offset = 16
     BYVAL lpD3DDevice AS IDirect3DDevice9 _            ' __in IDirect3DDevice9 *lpD3DDevice
   , BYVAL hMonitor AS DWORD _                          ' __in HMONITOR hMonitor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ChangeD3DDevice ( _                           ' VTable offset = 20
     BYVAL lpD3DDevice AS IDirect3DDevice9 _            ' __in IDirect3DDevice9 *lpD3DDevice
   , BYVAL hMonitor AS DWORD _                          ' __in HMONITOR hMonitor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AllocateSurfaceHelper ( _                     ' VTable offset = 24
     BYVAL lpAllocInfo AS VMR9AllocationInfo _          ' __in VMR9AllocationInfo *lpAllocInfo
   , BYREF lpNumBuffers AS DWORD _                      ' __inout DWORD *lpNumBuffers
   , BYREF lplpSurface AS IDirect3DSurface9 _           ' __out IDirect3DSurface9 **lplpSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NotifyEvent ( _                               ' VTable offset = 28
     BYVAL EventCode AS LONG _                          ' __in LONG EventCode
   , BYVAL Param1 AS LONG _                             ' __in LONG_PTR Param1
   , BYVAL Param2 AS LONG _                             ' __in LONG_PTR Param2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' enum VMR9AspectRatioMode
%VMR9ARMode_None      = 0
%VMR9ARMode_LetterBox = %VMR9ARMode_None + 1


' ########################################################################################
' Interface name = IVMRWindowlessControl9
' IID = {8F537D09-F85E-4414-B23B-502E54C79927}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IVMRWindowlessControl9 = GUID$("{8F537D09-F85E-4414-B23B-502E54C79927}")

INTERFACE IVMRWindowlessControl9 $IID_IVMRWindowlessControl9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNativeVideoSize ( _                        ' VTable offset = 12
     BYREF lpWidth AS LONG _                            ' __out LONG *lpWidth
   , BYREF lpHeight AS LONG _                           ' __out LONG *lpHeight
   , BYREF lpARWidth AS LONG _                          ' __out LONG *lpARWidth
   , BYREF lpARHeight AS LONG _                         ' __out LONG *lpARHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMinIdealVideoSize ( _                      ' VTable offset = 16
     BYREF lpWidth AS LONG _                            ' __out LONG *lpWidth
   , BYREF lpHeight AS LONG _                           ' __out LONG *lpHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxIdealVideoSize ( _                      ' VTable offset = 20
     BYREF lpWidth AS LONG _                            ' __out LONG *lpWidth
   , BYREF lpHeight AS LONG _                           ' __out LONG *lpHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVideoPosition ( _                          ' VTable offset = 24
     BYREF lpSRCRect AS RECT _                          ' __in const LPRECT lpSRCRect
   , BYREF lpDSTRect AS RECT _                          ' __in const LPRECT lpDSTRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoPosition ( _                          ' VTable offset = 28
     BYREF lpSRCRect AS RECT _                          ' __out LPRECT lpSRCRect
   , BYREF lpDSTRect AS RECT _                          ' __out LPRECT lpDSTRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAspectRatioMode ( _                        ' VTable offset = 32
     BYREF lpAspectRatioMode AS DWORD _                 ' __out DWORD *lpAspectRatioMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAspectRatioMode ( _                        ' VTable offset = 36
     BYVAL AspectRatioMode AS DWORD _                   ' __in DWORD AspectRatioMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVideoClippingWindow ( _                    ' VTable offset = 40
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RepaintVideo ( _                              ' VTable offset = 44
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL hdc AS DWORD _                               ' __in HDC hdc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisplayModeChanged ( _                        ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentImage ( _                           ' VTable offset = 52
     BYREF lpDib AS DWORD _                             ' __out BYTE **lpDib
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBorderColor ( _                            ' VTable offset = 56
     BYVAL Clr AS DWORD _                               ' __in COLORREF Clr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBorderColor ( _                            ' VTable offset = 60
     BYREF lpClr AS DWORD _                             ' __out COLORREF *lpClr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' enum VMR9MixerPrefs
%MixerPref9_NoDecimation           = &H1
%MixerPref9_DecimateOutput         = &H2
%MixerPref9_ARAdjustXorY           = &H4
%MixerPref9_NonSquareMixing        = &H8
%MixerPref9_DecimateMask           = &Hf
%MixerPref9_BiLinearFiltering      = &H10
%MixerPref9_PointFiltering         = &H20
%MixerPref9_AnisotropicFiltering   = &H40
%MixerPref9_PyramidalQuadFiltering = &H80
%MixerPref9_GaussianQuadFiltering  = &H100
%MixerPref9_FilteringReserved      = &He00
%MixerPref9_FilteringMask          = &Hff0
%MixerPref9_RenderTargetRGB        = &H1000
%MixerPref9_RenderTargetYUV        = &H2000
%MixerPref9_RenderTargetMask       = &Hff000
%MixerPref9_DynamicSwitchToBOB     = &H100000
%MixerPref9_DynamicDecimateBy2     = &H200000
%MixerPref9_DynamicReserved        = &Hc00000
%MixerPref9_DynamicMask            = &Hf00000

' // Size = 16 bytes
TYPE VMR9NormalizedRect DWORD
   left   AS SINGLE
   top    AS SINGLE
   right  AS SINGLE
   bottom AS SINGLE
END TYPE

' enum VMR9ProcAmpControlFlags
%ProcAmpControl9_Brightness = &H1
%ProcAmpControl9_Contrast   = &H2
%ProcAmpControl9_Hue        = &H4
%ProcAmpControl9_Saturation = &H8
%ProcAmpControl9_Mask       = &Hf

' // Size = 24 bytes
TYPE VMR9ProcAmpControl DWORD
   dwSize     AS DWORD
   dwFlags    AS DWORD
   Brightness AS SINGLE
   Contrast   AS SINGLE
   Hue        AS SINGLE
   Saturation AS SINGLE
END TYPE

' // Size = 24 bytes
TYPE VMR9ProcAmpControlRange DWORD
   dwSize       AS DWORD    ' DWORD
   dwProperty   AS DWORD    ' VMR9ProcAmpControlFlags
   MinValue     AS SINGLE   ' float
   MaxValue     AS SINGLE   ' float
   DefaultValue AS SINGLE   ' float
   StepSize     AS SINGLE   ' float
END TYPE


' ########################################################################################
' Interface name = IVMRMixerControl9
' IID = {1A777EAA-47C8-4930-B2C9-8FEE1C1B0F3B}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IVMRMixerControl9 = GUID$("{1A777EAA-47C8-4930-B2C9-8FEE1C1B0F3B}")

INTERFACE IVMRMixerControl9 $IID_IVMRMixerControl9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNativeVideoSize ( _                        ' VTable offset = 12
     BYVAL dwStreamID AS DWORD _                        ' __in DWORD dwStreamID
   , BYVAL Alpha AS SINGLE _                            ' __in float Alpha
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAlpha ( _                                  ' VTable offset = 16
     BYVAL dwStreamID AS DWORD _                        ' __in DWORD dwStreamID
   , BYREF pAlpha AS SINGLE _                           ' __out float *pAlpha
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetZOrder ( _                                 ' VTable offset = 20
     BYVAL dwStreamID AS DWORD _                        ' __in DWORD dwStreamID
   , BYVAL dwZ AS DWORD _                               ' __in DWORD dwZ
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetZOrder ( _                                 ' VTable offset = 24
     BYVAL dwStreamID AS DWORD _                        ' __in DWORD dwStreamID
   , BYREF pZ AS DWORD _                                ' __out DWORD *pZ
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOutputRect ( _                             ' VTable offset = 28
     BYVAL dwStreamID AS DWORD _                        ' __in DWORD dwStreamID
   , BYVAL pRect AS VMR9NormalizedRect _                ' __in const VMR9NormalizedRect *pRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputRect ( _                             ' VTable offset = 32
     BYVAL dwStreamID AS DWORD _                        ' __in DWORD dwStreamID
   , BYREF pRect AS VMR9NormalizedRect _                ' __out VMR9NormalizedRect *pRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBackgroundClr ( _                          ' VTable offset = 36
     BYVAL ClrBkg AS DWORD _                            ' __in COLORREF ClrBkg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBackgroundClr ( _                          ' VTable offset = 40
     BYVAL lpClrBkg AS DWORD _                          ' __in COLORREF *lpClrBkg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMixingPrefs ( _                            ' VTable offset = 44
     BYVAL dwMixerPrefs AS DWORD _                      ' __in DWORD dwMixerPrefs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMixingPrefs ( _                            ' VTable offset = 48
     BYREF pdwMixerPrefs AS DWORD _                     ' __out DWORD *pdwMixerPrefs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProcAmpControl ( _                         ' VTable offset = 52
     BYVAL dwStreamID AS DWORD _                        ' __in DWORD dwStreamID
   , BYVAL lpClrControl AS VMR9ProcAmpControl _         ' __in VMR9ProcAmpControl *lpClrControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProcAmpControl ( _                         ' VTable offset = 56
     BYVAL dwStreamID AS DWORD _                        ' __in DWORD dwStreamID
   , BYREF lpClrControl AS VMR9ProcAmpControl _         ' __inout VMR9ProcAmpControl *lpClrControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProcAmpControlRange ( _                    ' VTable offset = 60
     BYVAL dwStreamID AS DWORD _                        ' __in DWORD dwStreamID
   , BYREF lpClrControl AS VMR9ProcAmpControlRange _    ' __inout VMR9ProcAmpControlRange *lpClrControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' // Size = 56 bytes
TYPE VMR9AlphaBitmap DWORD
   dwFlags      AS DWORD                 ' DWORD dwFlags
   hdc          AS DWORD                 ' HDC hdc
   pDDS         AS DWORD PTR             ' IDirect3DSurface9 *pDDS
   rSrc         AS RECT                  ' RECT rSrc
   rDest        AS VMR9NormalizedRect    ' VMR9NormalizedRect rDest
   fAlpha       AS SINGLE                ' FLOAT fAlpha
   clrSrcKey    AS DWORD                 ' COLORREF clrSrcKey
   dwFilterMode AS DWORD                 ' DWORD dwFilterMode
END TYPE

' enum VMR9AlphaBitmapFlags
%VMR9AlphaBitmap_Disable     = &H1
%VMR9AlphaBitmap_hDC         = &H2
%VMR9AlphaBitmap_EntireDDS   = &H4
%VMR9AlphaBitmap_SrcColorKey = &H8
%VMR9AlphaBitmap_SrcRect     = &H10
%VMR9AlphaBitmap_FilterMode  = &H20


' ########################################################################################
' Interface name = IVMRMixerBitmap9
' IID = {CED175E5-1935-4820-81BD-FF6AD00C9108}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IVMRMixerBitmap9 = GUID$("{CED175E5-1935-4820-81BD-FF6AD00C9108}")

INTERFACE IVMRMixerBitmap9 $IID_IVMRMixerBitmap9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAlphaBitmap ( _                            ' VTable offset = 12
     BYVAL pBmpParms AS DWORD _                         ' __in const VMR9AlphaBitmap *pBmpParms
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateAlphaBitmapParameters ( _               ' VTable offset = 16
     BYVAL pBmpParms AS DWORD _                         ' __in const VMR9AlphaBitmap *pBmpParms
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAlphaBitmapParameters ( _                  ' VTable offset = 24
     BYREF pBmpParms AS DWORD _                         ' __out VMR9AlphaBitmap *pBmpParms
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IVMRSurface9
' IID = {DFC581A1-6E1F-4C3A-8D0A-5E9792EA2AFC}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IVMRSurface9 = GUID$("{DFC581A1-6E1F-4C3A-8D0A-5E9792EA2AFC}")

INTERFACE IVMRSurface9 $IID_IVMRSurface9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsSurfaceLocked ( _                           ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockSurface ( _                               ' VTable offset = 16
     BYREF lpSurface AS DWORD _                         ' __out BYTE **lpSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockSurface ( _                             ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSurface ( _                                ' VTable offset = 24
     BYREF lplpSurface AS IDirect3DSurface9 _           ' __out IDirect3DSurface9 **lplpSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' enum VMR9RenderPrefs
%RenderPrefs9_DoNotRenderBorder = &H1
%RenderPrefs9_Mask              = &H1


' ########################################################################################
' Interface name = IVMRImagePresenterConfig9
' IID = {45C15CAB-6E22-420A-8043-AE1F0AC02C7D}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IVMRImagePresenterConfig9 = GUID$("{45C15CAB-6E22-420A-8043-AE1F0AC02C7D}")

INTERFACE IVMRImagePresenterConfig9 $IID_IVMRImagePresenterConfig9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetRenderingPrefs ( _                         ' VTable offset = 12
     BYVAL dwRenderFlags AS DWORD _                     ' __in DWORD dwRenderFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRenderingPrefs ( _                         ' VTable offset = 16
     BYREF dwRenderFlags AS DWORD _                     ' __out DWORD *dwRenderFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IVMRVideoStreamControl9
' IID = {D0CFE38B-93E7-4772-8957-0400C49A4485}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IVMRVideoStreamControl9 = GUID$("{D0CFE38B-93E7-4772-8957-0400C49A4485}")

INTERFACE IVMRVideoStreamControl9 $IID_IVMRVideoStreamControl9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetStreamActiveState ( _                      ' VTable offset = 12
     BYVAL fActive AS LONG _                            ' __in BOOL fActive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamActiveState ( _                      ' VTable offset = 16
     BYREF lpfActive AS LONG _                          ' __out BOOL *lpfActive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' enum VMR9Mode
%VMR9Mode_Windowed   = &H1
%VMR9Mode_Windowless = &H2
%VMR9Mode_Renderless = &H4
%VMR9Mode_Mask       = &H7


' ########################################################################################
' Interface name = IVMRFilterConfig9
' IID = {5A804648-4F66-4867-9C43-4F5C822CF1B8}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IVMRFilterConfig9 = GUID$("{5A804648-4F66-4867-9C43-4F5C822CF1B8}")

INTERFACE IVMRFilterConfig9 $IID_IVMRFilterConfig9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetImageCompositor ( _                        ' VTable offset = 12
     BYVAL lpVMRImgCompositor AS IVMRImageCompositor9 _ ' __in IVMRImageCompositor9 *lpVMRImgCompositor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNumberOfStreams ( _                        ' VTable offset = 16
     BYVAL dwMaxStreams AS DWORD _                      ' __in DWORD dwMaxStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberOfStreams ( _                        ' VTable offset = 20
     BYREF pdwMaxStreams AS DWORD _                     ' __out DWORD *pdwMaxStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRenderingPrefs ( _                         ' VTable offset = 24
     BYVAL dwRenderFlags AS DWORD _                     ' __in DWORD dwRenderFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRenderingPrefs ( _                         ' VTable offset = 28
     BYREF pdwRenderFlags AS DWORD _                    ' __out DWORD *pdwRenderFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRenderingMode ( _                          ' VTable offset = 32
     BYVAL Mode AS DWORD _                              ' __in DWORD Mode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRenderingMode ( _                          ' VTable offset = 36
     BYREF pMode AS DWORD _                             ' __out DWORD *pMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IVMRAspectRatioControl9
' IID = {00D96C29-BBDE-4EFC-9901-BB5036392146}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IVMRAspectRatioControl9 = GUID$("{00D96C29-BBDE-4EFC-9901-BB5036392146}")

INTERFACE IVMRAspectRatioControl9 $IID_IVMRAspectRatioControl9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAspectRatioMode ( _                        ' VTable offset = 12
     BYREF lpdwARMode AS DWORD _                        ' __out LPDWORD lpdwARMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAspectRatioMode ( _                        ' VTable offset = 12
     BYVAL dwARMode AS DWORD _                          ' __in DWORD dwARMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' // Size = 1144 bytes
TYPE VMR9MonitorInfo QWORD FILL
   uDevID          AS DWORD            ' UINT uDevID
   rcMonitor       AS RECT             ' RECT rcMonitor
   hMon            AS DWORD            ' HMONITOR hMon
   dwFlags         AS DWORD            ' DWORD dwFlags
   szDevice        AS WSTRINGZ * 32    ' wchar_t szDevice[ 32 ]
   szDescription   AS WSTRINGZ * 512   ' wchar_t szDescription[ 512 ]
   liDriverVersion AS QUAD             ' LARGE_INTEGER liDriverVersion
   dwVendorId      AS DWORD            ' DWORD dwVendorId
   dwDeviceId      AS DWORD            ' DWORD dwDeviceId
   dwSubSysId      AS DWORD            ' DWORD dwSubSysId
   dwRevision      AS DWORD            ' DWORD dwRevision
END TYPE


' ########################################################################################
' Interface name = IVMRMonitorConfig9
' IID = {46C2E457-8BA0-4EEF-B80B-0680F0978749}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IVMRMonitorConfig9 = GUID$("{46C2E457-8BA0-4EEF-B80B-0680F0978749}")

INTERFACE IVMRMonitorConfig9 $IID_IVMRMonitorConfig9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetMonitor ( _                                ' VTable offset = 12
     BYVAL uDev AS DWORD _                              ' __in UINT uDev
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMonitor ( _                                ' VTable offset = 16
     BYREF puDev AS DWORD _                             ' __out UINT *puDev
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultMonitor ( _                         ' VTable offset = 20
     BYVAL uDev AS DWORD _                              ' __in UINT uDev
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultMonitor ( _                         ' VTable offset = 24
     BYREF puDev AS DWORD _                             ' __out UINT *puDev
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAvailableMonitors ( _                      ' VTable offset = 28
     BYREF pInfo AS VMR9MonitorInfo _                   ' __out VMR9MonitorInfo *pInfo
   , BYVAL dwMaxInfoArraySize AS DWORD _                ' __in DWORD dwMaxInfoArraySize
   , BYREF pdwNumDevices AS DWORD _                     ' __out DWORD *pdwNumDevices
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' enum VMR9DeinterlacePrefs
%DeinterlacePref9_NextBest            = &H1
%DeinterlacePref9_BOB                 = &H2
%DeinterlacePref9_Weave               = &H4
%DeinterlacePref9_Mask                = &H7

' enum VMR9DeinterlaceTech
%DeinterlaceTech9_Unknown             = 0
%DeinterlaceTech9_BOBLineReplicate    = &H1
%DeinterlaceTech9_BOBVerticalStretch  = &H2
%DeinterlaceTech9_MedianFiltering     = &H4
%DeinterlaceTech9_EdgeFiltering       = &H10
%DeinterlaceTech9_FieldAdaptive       = &H20
%DeinterlaceTech9_PixelAdaptive       = &H40
%DeinterlaceTech9_MotionVectorSteered = &H80

' // Size = 8 bytes
TYPE VMR9Frequency DWORD
   dwNumerator   AS DWORD
   dwDenominator AS DWORD
END TYPE

' enum VMR9_SampleFormat
%VMR9_SampleReserved                  = 1
%VMR9_SampleProgressiveFrame          = 2
%VMR9_SampleFieldInterleavedEvenFirst = 3
%VMR9_SampleFieldInterleavedOddFirst  = 4
%VMR9_SampleFieldSingleEven           = 5
%VMR9_SampleFieldSingleOdd            = 6

' // Size = 36 bytes
TYPE VMR9VideoDesc DWORD
   dwSize          AS DWORD           ' DWORD dwSize
   dwSampleWidth   AS DWORD           ' DWORD dwSampleWidth
   dwSampleHeight  AS DWORD           ' DWORD dwSampleHeight
   SampleFormat    AS DWORD           ' VMR9_SampleFormat SampleFormat
   dwFourCC        AS DWORD           ' DWORD dwFourCC
   InputSampleFreq AS VMR9Frequency   ' VMR9Frequency InputSampleFreq
   OutputFrameFreq AS VMR9Frequency   ' VMR9Frequency OutputFrameFreq
END TYPE

' // Size = 20 bytes
TYPE VMR9DeinterlaceCaps DWORD
   dwSize                    AS DWORD   ' DWORD dwSize
   dwNumPreviousOutputFrames AS DWORD   ' DWORD dwNumPreviousOutputFrames
   dwNumForwardRefSamples    AS DWORD   ' DWORD dwNumForwardRefSamples
   dwNumBackwardRefSamples   AS DWORD   ' DWORD dwNumBackwardRefSamples
   DeinterlaceTechnology     AS DWORD   ' VMR9DeinterlaceTech DeinterlaceTechnology
END TYPE


' ########################################################################################
' Interface name = IVMRDeinterlaceControl9
' IID = {A215FB8D-13C2-4F7F-993C-003D6271A459}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IVMRDeinterlaceControl9 = GUID$("{A215FB8D-13C2-4F7F-993C-003D6271A459}")

INTERFACE IVMRDeinterlaceControl9 $IID_IVMRDeinterlaceControl9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNumberOfDeinterlaceModes ( _               ' VTable offset = 12
     BYREF lpVideoDescription AS VMR9VideoDesc _        ' __in VMR9VideoDesc *lpVideoDescription
   , BYREF lpdwNumDeinterlaceModes AS DWORD _           ' __inout LPDWORD lpdwNumDeinterlaceModes
   , BYREF lpDeinterlaceModes AS GUID _                 ' __out LPGUID lpDeinterlaceModes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeinterlaceModeCaps ( _                    ' VTable offset = 16
     BYREF lpDeinterlaceMode AS GUID _                  ' __in LPGUID lpDeinterlaceMode
   , BYREF lpVideoDescription AS VMR9VideoDesc _        ' __in VMR9VideoDesc *lpVideoDescription
   , BYREF lpDeinterlaceCaps AS VMR9DeinterlaceCaps _   ' __out VMR9DeinterlaceCaps *lpDeinterlaceCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeinterlaceMode ( _                        ' VTable offset = 20
     BYVAL dwStreamID AS DWORD _                        ' __in DWORD dwStreamID
   , BYREF lpDeinterlaceMode AS GUID _                  ' __out LPGUID lpDeinterlaceMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDeinterlaceMode ( _                        ' VTable offset = 24
     BYVAL dwStreamID AS DWORD _                        ' __in DWORD dwStreamID
   , BYREF lpDeinterlaceMode AS GUID _                  ' __in LPGUID lpDeinterlaceMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeinterlacePrefs ( _                       ' VTable offset = 28
     BYREF lpdwDeinterlacePrefs AS DWORD _              ' __out LPDWORD lpdwDeinterlacePrefs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDeinterlacePrefs ( _                       ' VTable offset = 32
     BYVAL dwDeinterlacePrefs AS DWORD _                ' __in DWORD dwDeinterlacePrefs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActualDeinterlaceMode ( _                  ' VTable offset = 36
     BYVAL dwStreamID AS DWORD _                        ' __in DWORD dwStreamID
   , BYREF lpDeinterlaceMode AS GUID _                  ' __out LPGUID lpDeinterlaceMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' // Size = 64 bytes
TYPE VMR9VideoStreamInfo QWORD FILL  ' Must be 8 byte aligned
   pddsVideoSurface AS DWORD PTR            ' IDirect3DSurface9 *pddsVideoSurface
   dwWidth          AS DWORD                ' DWORD dwWidth
   dwHeight         AS DWORD                ' DWORD dwHeight
   dwStrmID         AS DWORD                ' DWORD dwStrmID
   fAlpha           AS SINGLE               ' FLOAT fAlpha
   rNormal          AS VMR9NormalizedRect   ' VMR9NormalizedRect rNormal
   rtStart          AS QUAD                 ' REFERENCE_TIME rtStart
   rtEnd            AS QUAD                 ' REFERENCE_TIME rtEnd
   SampleFormat     AS DWORD                ' VMR9_SampleFormat SampleFormat
   alignment__      AS DWORD                ' // To keep 8 byte alignment
END TYPE


' ########################################################################################
' Interface name = IVMRImageCompositor9
' IID = {4A5C89EB-DF51-4654-AC2A-E48E02BBABF6}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IVMRImageCompositor9 = GUID$("{4A5C89EB-DF51-4654-AC2A-E48E02BBABF6}")

INTERFACE IVMRImageCompositor9 $IID_IVMRImageCompositor9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitCompositionDevice ( _                     ' VTable offset = 12
     BYVAL pD3DDevice AS IUnknown _                     ' __in IUnknown *pD3DDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TermCompositionDevice ( _                     ' VTable offset = 16
     BYVAL pD3DDevice AS IUnknown _                     ' __in IUnknown *pD3DDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStreamMediaType ( _                        ' VTable offset = 20
     BYVAL dwStrmID AS DWORD _                          ' __in DWORD dwStrmID
   , BYREF pmt AS AM_MEDIA_TYPE _                       ' __in AM_MEDIA_TYPE *pmt
   , BYVAL fTexture AS LONG _                           ' __in BOOL fTexture
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompositeImage ( _                            ' VTable offset = 24
     BYVAL pD3DDevice AS IUnknown _                     ' __in IUnknown *pD3DDevice
   , BYVAL pddsRenderTarget AS IDirect3DSurface9 _      ' __in IDirect3DSurface9 *pddsRenderTarget
   , BYREF pmtRenderTarget AS AM_MEDIA_TYPE _           ' __in AM_MEDIA_TYPE *pmtRenderTarget
   , BYVAL rtStart AS QUAD _                            ' __in REFERENCE_TIME rtStart
   , BYVAL rtEnd AS QUAD _                              ' __in REFERENCE_TIME rtEnd
   , BYVAL dwClrBkGnd AS DWORD _                        ' __in D3DCOLOR dwClrBkGnd
   , BYREF pVideoStreamInfo AS VMR9VideoStreamInfo _    ' __in VMR9VideoStreamInfo *pVideoStreamInfo
   , BYVAL cStreams AS DWORD _                          ' __in UINT cStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE
