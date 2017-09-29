' ########################################################################################
' Microsoft Windows
' File: dxva2SWDev.inc
' Contents: DirectX Video Acceleration 2 header file for software video processing devices
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DXVA2SWDEV_INC = 1

#INCLUDE ONCE "dxva2api.inc"

' enum DXVA2_SampleFlags
%DXVA2_SampleFlag_Palette_Changed         = &H00000001???
%DXVA2_SampleFlag_SrcRect_Changed         = &H00000002???
%DXVA2_SampleFlag_DstRect_Changed         = &H00000004???
%DXVA2_SampleFlag_ColorData_Changed       = &H00000008???
%DXVA2_SampleFlag_PlanarAlpha_Changed     = &H00000010???
%DXVA2_SampleFlag_RFF                     = &H00010000???
%DXVA2_SampleFlag_TFF                     = &H00020000???
%DXVA2_SampleFlag_RFF_TFF_Present         = &H00040000???
%DXVA2_SampleFlagsMask                    = &HFFFF001F???

' enum DXVA2_DestinationFlags
%DXVA2_DestinationFlag_Background_Changed = &H00000001???
%DXVA2_DestinationFlag_TargetRect_Changed = &H00000002???
%DXVA2_DestinationFlag_ColorData_Changed  = &H00000004???
%DXVA2_DestinationFlag_Alpha_Changed      = &H00000008???
%DXVA2_DestinationFlag_RFF                = &H00010000???
%DXVA2_DestinationFlag_TFF                = &H00020000???
%DXVA2_DestinationFlag_RFF_TFF_Present    = &H00040000???
%DXVA2_DestinationFlagMask                = &HFFFF000F???

' Already defined in dxva2api.inc
'typedef struct _DXVA2_VIDEOSAMPLE
'{
'    REFERENCE_TIME           Start;
'    REFERENCE_TIME           End;
'    DXVA2_ExtendedFormat     SampleFormat;
'    UINT                     SampleFlags;
'    VOID*                    SrcResource;
'    RECT                     SrcRect;
'    RECT                     DstRect;
'    DXVA2_AYUVSample8        Pal[16];
'    DXVA2_Fixed32            PlanarAlpha;
'} DXVA2_VIDEOSAMPLE;

' // Size = 128 bytes
TYPE DXVA2_VIDEOPROCESSBLT DWORD
   TargetFrame        AS QUAD                      ' REFERENCE_TIME
   TargetRect         AS RECT
   ConstrictionSize   AS SIZE                      ' SIZE
   StreamingFlags     AS DWORD                     ' UINT
   BackgroundColor    AS DXVA2_AYUVSample16
   DestFormat         AS DXVA2_ExtendedFormat
   DestFlags          AS DWORD                     ' UINT
   ProcAmpValues      AS DXVA2_ProcAmpValues
   Alpha              AS DXVA2_Fixed32
   NoiseFilterLuma    AS DXVA2_FilterValues
   NoiseFilterChroma  AS DXVA2_FilterValues
   DetailFilterLuma   AS DXVA2_FilterValues
   DetailFilterChroma AS DXVA2_FilterValues
   pSrcSurfaces       AS DXVA2_VIDEOSAMPLE PTR
   NumSrcSurfaces     AS DWORD                     ' UINT
END TYPE

'#if defined(_D3D9_H_) || defined(_d3d9P_H_)

'typedef HRESULT (CALLBACK* PDXVA2SW_GETVIDEOPROCESSORRENDERTARGETCOUNT)(
'    __in const DXVA2_VideoDesc* pVideoDesc,
'    __out UINT* pCount
'    );

'FUNCTION DXVA2SW_GETVIDEOPROCESSORRENDERTARGETCOUNT ( _
'   BYREF pVideoDesc AS DXVA2_VideoDesc _                ' __in const DXVA2_VideoDesc* pVideoDesc
' , BYREF pCount AS DWORD _                              ' __out UINT* pCount
' ) AS LONG                                              ' HRESULT

'typedef HRESULT (CALLBACK* PDXVA2SW_GETVIDEOPROCESSORRENDERTARGETS)(
'    __in const DXVA2_VideoDesc* pVideoDesc,
'    __in UINT Count,
'    __out_ecount(Count) D3DFORMAT* pFormats
'    );

'FUNCTION DXVA2SW_GETVIDEOPROCESSORRENDERTARGETS ( _
'   BYREF pVideoDesc AS DXVA2_VideoDesc _                ' __in const DXVA2_VideoDesc* pVideoDesc
' , BYVAL Count AS DWORD _                               ' __in UINT Count
' , BYVAL pFormats AS DWORD _                            ' __out_ecount(Count) D3DFORMAT* pFormats
' ) AS LONG                                              ' HRESULT

'typedef HRESULT (CALLBACK* PDXVA2SW_GETVIDEOPROCESSORCAPS)(
'    __in const DXVA2_VideoDesc* pVideoDesc,
'    __in D3DFORMAT RenderTargetFormat,
'    __out DXVA2_VideoProcessorCaps* pCaps
'    );

'FUNCTION DXVA2SW_GETVIDEOPROCESSORCAPS ( _
'   BYREF pVideoDesc AS DXVA2_VideoDesc _                ' __in const DXVA2_VideoDesc* pVideoDesc
' , BYVAL RenderTargetFormat AS DWORD _                  ' __in D3DFORMAT RenderTargetFormat
' , BYREF pCaps AS DXVA2_VideoProcessorCaps _            ' __out DXVA2_VideoProcessorCaps* pCaps
' ) AS LONG                                              ' HRESULT

'typedef HRESULT (CALLBACK* PDXVA2SW_GETVIDEOPROCESSORSUBSTREAMFORMATCOUNT)(
'    __in const DXVA2_VideoDesc* pVideoDesc,
'    __in D3DFORMAT RenderTargetFormat,
'    __out UINT* pCount
'    );

'FUNCTION DXVA2SW_GETVIDEOPROCESSORSUBSTREAMFORMATCOUNT ( _
'   BYREF pVideoDesc AS DXVA2_VideoDesc _                ' __in const DXVA2_VideoDesc* pVideoDesc
' , BYVAL RenderTargetFormat AS DWORD _                  ' __in D3DFORMAT RenderTargetFormat
' , BYREF pCount AS DWORD _                              ' __out UINT* pCount
' ) AS LONG                                              ' HRESULT

'typedef HRESULT (CALLBACK* PDXVA2SW_GETVIDEOPROCESSORSUBSTREAMFORMATS)(
'    __in const DXVA2_VideoDesc* pVideoDesc,
'    __in D3DFORMAT RenderTargetFormat,
'    __in UINT Count,
'    __out_ecount(Count) D3DFORMAT* pFormats
'    );

'FUNCTION DXVA2SW_GETVIDEOPROCESSORSUBSTREAMFORMATS ( _
'   BYREF pVideoDesc AS DXVA2_VideoDesc _                ' __in const DXVA2_VideoDesc* pVideoDesc
' , BYVAL RenderTargetFormat AS DWORD _                  ' __in D3DFORMAT RenderTargetFormat
' , BYVAL Count AS DWORD _                               ' __in UINT Count
' , BYREF pFormats AS DWORD _                            ' __out_ecount(Count) D3DFORMAT* pFormats
' ) AS LONG                                              ' HRESULT

'typedef HRESULT (CALLBACK* PDXVA2SW_GETPROCAMPRANGE)(
'    __in const DXVA2_VideoDesc* pVideoDesc,
'    __in D3DFORMAT RenderTargetFormat,
'    __in UINT ProcAmpCap,
'    __out DXVA2_ValueRange* pRange
'    );

'FUNCTION DXVA2SW_GETPROCAMPRANGE ( _
'   BYREF pVideoDesc AS DXVA2_VideoDesc _                ' __in const DXVA2_VideoDesc* pVideoDesc
' , BYVAL RenderTargetFormat AS DWORD _                  ' __in D3DFORMAT RenderTargetFormat
' , BYVAL ProcAmpCap AS DWORD _                          ' __in UINT ProcAmpCap
' , BYREF pRange AS DXVA2_ValueRange _                   ' __out DXVA2_ValueRange* pRange
' ) AS LONG                                              ' HRESULT

'typedef HRESULT (CALLBACK* PDXVA2SW_GETFILTERPROPERTYRANGE)(
'    __in const DXVA2_VideoDesc* pVideoDesc,
'    __in D3DFORMAT RenderTargetFormat,
'    __in UINT FilterSetting,
'    __out DXVA2_ValueRange* pRange
'    );

'FUNCTION DXVA2SW_GETFILTERPROPERTYRANGE ( _
'   BYREF pVideoDesc AS DXVA2_VideoDesc _                ' __in const DXVA2_VideoDesc* pVideoDesc
' , BYVAL RenderTargetFormat AS DWORD _                  ' __in D3DFORMAT RenderTargetFormat
' , BYVAL FilterSetting AS DWORD _                       ' __in UINT FilterSetting
' , BYREF pRange AS DXVA2_ValueRange _                   ' __out DXVA2_ValueRange* pRange
' ) AS LONG                                              ' HRESULT

'typedef HRESULT (CALLBACK* PDXVA2SW_CREATEVIDEOPROCESSDEVICE)(
'    __in IDirect3DDevice9* pD3DD9,
'    __in const DXVA2_VideoDesc* pVideoDesc,
'    __in D3DFORMAT RenderTargetFormat,
'    __in UINT MaxSubStreams,
'    __out HANDLE* phDevice
'    );

'FUNCTION DXVA2SW_CREATEVIDEOPROCESSDEVICE ( _
'   BYVAL pD3DD9 AS IDirect3DDevice9 _                   ' __in IDirect3DDevice9* pD3DD9
' , BYREF pVideoDesc AS DXVA2_VideoDesc _                ' __in const DXVA2_VideoDesc* pVideoDesc
' , BYVAL RenderTargetFormat AS DWORD _                  ' __in D3DFORMAT RenderTargetFormat
' , BYVAL MaxSubStreams AS DWORD _                       ' __in UINT MaxSubStreams
' , BYREF phDevice AS DWORD _                            ' __out HANDLE* phDevice
' ) AS LONG                                              ' HRESULT

'typedef HRESULT (CALLBACK* PDXVA2SW_DESTROYVIDEOPROCESSDEVICE)(
'    __in HANDLE hDevice
'    );

'FUNCTION DXVA2SW_DESTROYVIDEOPROCESSDEVICE ( _
'   BYVAL hDevice AS DWORD _                             ' __in HANDLE hDevice
' ) AS LONG                                              ' HRESULT

'typedef HRESULT (CALLBACK* PDXVA2SW_VIDEOPROCESSBEGINFRAME)(
'    __in HANDLE hDevice
'    );

'FUNCTION DXVA2SW_VIDEOPROCESSBEGINFRAME ( _
'   BYVAL hDevice AS DWORD _                             ' __in HANDLE hDevice
' ) AS LONG                                              ' HRESULT

'typedef HRESULT (CALLBACK* PDXVA2SW_VIDEOPROCESSENDFRAME)(
'    __in HANDLE hDevice,
'    __inout_opt HANDLE* pHandleComplete
'    );

'FUNCTION DXVA2SW_VIDEOPROCESSENDFRAME ( _
'   BYVAL hDevice AS DWORD _                             ' __in HANDLE hDevice
' , BYREF pHandleComplete AS DWORD _                     ' __inout_opt HANDLE* pHandleComplete
' ) AS LONG                                              ' HRESULT

'typedef HRESULT (CALLBACK* PDXVA2SW_VIDEOPROCESSSETRENDERTARGET)(
'    __in HANDLE hDevice,
'    __in IDirect3DSurface9* pRenderTarget
'    );

'FUNCTION DXVA2SW_VIDEOPROCESSSETRENDERTARGET ( _
'   BYVAL hDevice AS DWORD _                             ' __in HANDLE hDevice
' , BYVAL pRenderTarget AS IDirect3DSurface9 _           ' __in IDirect3DSurface9* pRenderTarget
' ) AS LONG                                              ' HRESULT

'typedef HRESULT (CALLBACK* PDXVA2SW_VIDEOPROCESSBLT)(
'    __in HANDLE hDevice,
'    __in const DXVA2_VIDEOPROCESSBLT* pBlt
'    );

'FUNCTION DXVA2SW_VIDEOPROCESSBLT ( _
'   BYVAL hDevice AS DWORD _                             ' __in HANDLE hDevice
' , BYREF pBlt AS DXVA2_VIDEOPROCESSBLT _                ' __in const DXVA2_VIDEOPROCESSBLT* pBlt
' ) AS LONG                                              ' HRESULT

' // Size = 56 bytes
TYPE DXVA2SW_CALLBACKS DWORD
   Size                                  AS DWORD   ' UINT
   GetVideoProcessorRenderTargetCount    AS DWORD   ' PDXVA2SW_GETVIDEOPROCESSORRENDERTARGETCOUNT
   GetVideoProcessorRenderTargets        AS DWORD   ' PDXVA2SW_GETVIDEOPROCESSORRENDERTARGETS
   GetVideoProcessorCaps                 AS DWORD   ' PDXVA2SW_GETVIDEOPROCESSORCAPS
   GetVideoProcessorSubStreamFormatCount AS DWORD   ' PDXVA2SW_GETVIDEOPROCESSORSUBSTREAMFORMATCOUNT
   GetVideoProcessorSubStreamFormats     AS DWORD   ' PDXVA2SW_GETVIDEOPROCESSORSUBSTREAMFORMATS
   GetProcAmpRange                       AS DWORD   ' PDXVA2SW_GETPROCAMPRANGE
   GetFilterPropertyRange                AS DWORD   ' PDXVA2SW_GETFILTERPROPERTYRANGE
   CreateVideoProcessDevice              AS DWORD   ' PDXVA2SW_CREATEVIDEOPROCESSDEVICE
   DestroyVideoProcessDevice             AS DWORD   ' PDXVA2SW_DESTROYVIDEOPROCESSDEVICE
   VideoProcessBeginFrame                AS DWORD   ' PDXVA2SW_VIDEOPROCESSBEGINFRAME
   VideoProcessEndFrame                  AS DWORD   ' PDXVA2SW_VIDEOPROCESSENDFRAME
   VideoProcessSetRenderTarget           AS DWORD   ' PDXVA2SW_VIDEOPROCESSSETRENDERTARGET
   VideoProcessBlt                       AS DWORD   ' PDXVA2SW_VIDEOPROCESSBLT
END TYPE

'#endif  // _D3D9_H_
