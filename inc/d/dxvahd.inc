' ########################################################################################
' Microsoft Windows
' File: dxvahd.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DXVAHD_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "d3d9.inc"

'#if 0
'typedef DWORD IDirect3DDevice9Ex;
'typedef DWORD IDirect3DSurface9;
'typedef DWORD D3DCOLOR;
'typedef DWORD D3DFORMAT;
'typedef DWORD D3DPOOL;
'#endif // 0

$IID_IDXVAHD_Device = GUID$("{95f12dfd-d77e-49be-815f-57d579634d6d}")
$IID_IDXVAHD_VideoProcessor = GUID$("{95f4edf4-6e03-4cd7-be1b-3075d665aa52}")

' enum DXVAHD_FRAME_FORMAT
%DXVAHD_FRAME_FORMAT_PROGRESSIVE                       = 0
%DXVAHD_FRAME_FORMAT_INTERLACED_TOP_FIELD_FIRST        = 1
%DXVAHD_FRAME_FORMAT_INTERLACED_BOTTOM_FIELD_FIRST     = 2

' enum DXVAHD_DEVICE_USAGE
%DXVAHD_DEVICE_USAGE_PLAYBACK_NORMAL                   = 0
%DXVAHD_DEVICE_USAGE_OPTIMAL_SPEED                     = 1
%DXVAHD_DEVICE_USAGE_OPTIMAL_QUALITY                   = 2

' enum DXVAHD_SURFACE_TYPE
%DXVAHD_SURFACE_TYPE_VIDEO_INPUT                       = 0
%DXVAHD_SURFACE_TYPE_VIDEO_INPUT_PRIVATE               = 1
%DXVAHD_SURFACE_TYPE_VIDEO_OUTPUT                      = 2

' enum DXVAHD_DEVICE_TYPE
%DXVAHD_DEVICE_TYPE_HARDWARE                           = 0
%DXVAHD_DEVICE_TYPE_SOFTWARE                           = 1
%DXVAHD_DEVICE_TYPE_REFERENCE                          = 2
%DXVAHD_DEVICE_TYPE_OTHER                              = 3

' enum DXVAHD_DEVICE_CAPS
%DXVAHD_DEVICE_CAPS_LINEAR_SPACE                       = &H1???
%DXVAHD_DEVICE_CAPS_xvYCC                              = &H2???
%DXVAHD_DEVICE_CAPS_RGB_RANGE_CONVERSION               = &H4???
%DXVAHD_DEVICE_CAPS_YCbCr_MATRIX_CONVERSION            = &H8???

' enum DXVAHD_FEATURE_CAPS
%DXVAHD_FEATURE_CAPS_ALPHA_FILL                        = &H1???
%DXVAHD_FEATURE_CAPS_CONSTRICTION                      = &H2???
%DXVAHD_FEATURE_CAPS_LUMA_KEY                          = &H4???
%DXVAHD_FEATURE_CAPS_ALPHA_PALETTE                     = &H8???

' enum DXVAHD_FILTER_CAPS
%DXVAHD_FILTER_CAPS_BRIGHTNESS                         = &H1???
%DXVAHD_FILTER_CAPS_CONTRAST                           = &H2???
%DXVAHD_FILTER_CAPS_HUE                                = &H4???
%DXVAHD_FILTER_CAPS_SATURATION                         = &H8???
%DXVAHD_FILTER_CAPS_NOISE_REDUCTION                    = &H10???
%DXVAHD_FILTER_CAPS_EDGE_ENHANCEMENT                   = &H20???
%DXVAHD_FILTER_CAPS_ANAMORPHIC_SCALING                 = &H40???

' enum DXVAHD_INPUT_FORMAT_CAPS
%DXVAHD_INPUT_FORMAT_CAPS_RGB_INTERLACED               = &H1???
%DXVAHD_INPUT_FORMAT_CAPS_RGB_PROCAMP                  = &H2???
%DXVAHD_INPUT_FORMAT_CAPS_RGB_LUMA_KEY                 = &H4???
%DXVAHD_INPUT_FORMAT_CAPS_PALETTE_INTERLACED           = &H8???

' enum DXVAHD_PROCESSOR_CAPS
%DXVAHD_PROCESSOR_CAPS_DEINTERLACE_BLEND               = &H1???
%DXVAHD_PROCESSOR_CAPS_DEINTERLACE_BOB                 = &H2???
%DXVAHD_PROCESSOR_CAPS_DEINTERLACE_ADAPTIVE            = &H4???
%DXVAHD_PROCESSOR_CAPS_DEINTERLACE_MOTION_COMPENSATION = &H8???
%DXVAHD_PROCESSOR_CAPS_INVERSE_TELECINE                = &H10???
%DXVAHD_PROCESSOR_CAPS_FRAME_RATE_CONVERSION           = &H20???

' enum DXVAHD_ITELECINE_CAPS
%DXVAHD_ITELECINE_CAPS_32                              = &H1???
%DXVAHD_ITELECINE_CAPS_22                              = &H2???
%DXVAHD_ITELECINE_CAPS_2224                            = &H4???
%DXVAHD_ITELECINE_CAPS_2332                            = &H8???
%DXVAHD_ITELECINE_CAPS_32322                           = &H10???
%DXVAHD_ITELECINE_CAPS_55                              = &H20???
%DXVAHD_ITELECINE_CAPS_64                              = &H40???
%DXVAHD_ITELECINE_CAPS_87                              = &H80???
%DXVAHD_ITELECINE_CAPS_222222222223                    = &H100???
%DXVAHD_ITELECINE_CAPS_OTHER                           = &H80000000???

' enum DXVAHD_FILTER
%DXVAHD_FILTER_BRIGHTNESS                              = 0
%DXVAHD_FILTER_CONTRAST                                = 1
%DXVAHD_FILTER_HUE                                     = 2
%DXVAHD_FILTER_SATURATION                              = 3
%DXVAHD_FILTER_NOISE_REDUCTION                         = 4
%DXVAHD_FILTER_EDGE_ENHANCEMENT                        = 5
%DXVAHD_FILTER_ANAMORPHIC_SCALING                      = 6

' enum DXVAHD_BLT_STATE
%DXVAHD_BLT_STATE_TARGET_RECT                          = 0
%DXVAHD_BLT_STATE_BACKGROUND_COLOR                     = 1
%DXVAHD_BLT_STATE_OUTPUT_COLOR_SPACE                   = 2
%DXVAHD_BLT_STATE_ALPHA_FILL                           = 3
%DXVAHD_BLT_STATE_CONSTRICTION                         = 4
%DXVAHD_BLT_STATE_PRIVATE                              = 1000

' enum DXVAHD_ALPHA_FILL_MODE
%DXVAHD_ALPHA_FILL_MODE_OPAQUE                         = 0
%DXVAHD_ALPHA_FILL_MODE_BACKGROUND                     = 1
%DXVAHD_ALPHA_FILL_MODE_DESTINATION                    = 2
%DXVAHD_ALPHA_FILL_MODE_SOURCE_STREAM                  = 3

' enum DXVAHD_STREAM_STATE
%DXVAHD_STREAM_STATE_D3DFORMAT                         = 0
%DXVAHD_STREAM_STATE_FRAME_FORMAT                      = 1
%DXVAHD_STREAM_STATE_INPUT_COLOR_SPACE                 = 2
%DXVAHD_STREAM_STATE_OUTPUT_RATE                       = 3
%DXVAHD_STREAM_STATE_SOURCE_RECT                       = 4
%DXVAHD_STREAM_STATE_DESTINATION_RECT                  = 5
%DXVAHD_STREAM_STATE_ALPHA                             = 6
%DXVAHD_STREAM_STATE_PALETTE                           = 7
%DXVAHD_STREAM_STATE_LUMA_KEY                          = 8
%DXVAHD_STREAM_STATE_ASPECT_RATIO                      = 9
%DXVAHD_STREAM_STATE_FILTER_BRIGHTNESS                 = 100
%DXVAHD_STREAM_STATE_FILTER_CONTRAST                   = 101
%DXVAHD_STREAM_STATE_FILTER_HUE                        = 102
%DXVAHD_STREAM_STATE_FILTER_SATURATION                 = 103
%DXVAHD_STREAM_STATE_FILTER_NOISE_REDUCTION            = 104
%DXVAHD_STREAM_STATE_FILTER_EDGE_ENHANCEMENT           = 105
%DXVAHD_STREAM_STATE_FILTER_ANAMORPHIC_SCALING         = 106
%DXVAHD_STREAM_STATE_PRIVATE                           = 1000

' enum DXVAHD_OUTPUT_RATE
%DXVAHD_OUTPUT_RATE_NORMAL                             = 0
%DXVAHD_OUTPUT_RATE_HALF                               = 1
%DXVAHD_OUTPUT_RATE_CUSTOM                             = 2

' // Size = 8 bytes
TYPE DXVAHD_RATIONAL DWORD
   Numerator   AS DWORD   ' UINT
   Denominator AS DWORD   ' UINT
END TYPE

' // Size = 16 bytes
TYPE DXVAHD_COLOR_RGBA DWORD
   R AS SINGLE   ' FLOAT
   G AS SINGLE   ' FLOAT
   B AS SINGLE   ' FLOAT
   A AS SINGLE   ' FLOAT
END TYPE

' // Size = 16 bytes
TYPE DXVAHD_COLOR_YCbCrA DWORD
   Y  AS SINGLE   ' FLOAT
   Cb AS SINGLE   ' FLOAT
   Cr AS SINGLE   ' FLOAT
   A  AS SINGLE   ' FLOAT
END TYPE

' // Size = 16 bytes
UNION DXVAHD_COLOR DWORD
   RGB   AS DXVAHD_COLOR_RGBA
   YCbCr AS DXVAHD_COLOR_YCbCrA
END UNION

' // Size = 36 bytes
TYPE DXVAHD_CONTENT_DESC DWORD
   InputFrameFormat AS LONG              ' DXVAHD_FRAME_FORMAT
   InputFrameRate   AS DXVAHD_RATIONAL   ' DXVAHD_RATIONAL
   InputWidth       AS DWORD             ' UINT
   InputHeight      AS DWORD             ' UINT
   OutputFrameRate  AS DXVAHD_RATIONAL   ' DXVAHD_RATIONAL
   OutputWidth      AS DWORD             ' UINT
   OutputHeight     AS DWORD             ' UINT
END TYPE

' // Size = 44 bytes
TYPE DXVAHD_VPDEVCAPS DWORD
   DeviceType          AS LONG    ' DXVAHD_DEVICE_TYPE
   DeviceCaps          AS DWORD   ' UINT
   FeatureCaps         AS DWORD   ' UINT
   FilterCaps          AS DWORD   ' UINT
   InputFormatCaps     AS DWORD   ' UINT
   InputPool           AS DWORD   ' D3DPOOL
   OutputFormatCount   AS DWORD   ' UINT
   InputFormatCount    AS DWORD   ' UINT
   VideoProcessorCount AS DWORD   ' UINT
   MaxInputStreams     AS DWORD   ' UINT
   MaxStreamStates     AS DWORD   ' UINT
END TYPE

' // Size = 36 bytes
TYPE DXVAHD_VPCAPS DWORD
   VPGuid          AS GUID    ' GUID
   PastFrames      AS DWORD   ' UINT
   FutureFrames    AS DWORD   ' UINT
   ProcessorCaps   AS DWORD   ' UINT
   ITelecineCaps   AS DWORD   ' UINT
   CustomRateCount AS DWORD   ' UINT
END TYPE

' // Size = 20 bytes
TYPE DXVAHD_CUSTOM_RATE_DATA DWORD
   CustomRate          AS DXVAHD_RATIONAL   ' DXVAHD_RATIONAL
   OutputFrames        AS DWORD             ' UINT
   InputInterlaced     AS LONG              ' BOOL
   InputFramesOrFields AS DWORD             ' UINT
END TYPE

' // Size = 16 bytes
TYPE DXVAHD_FILTER_RANGE_DATA DWORD
   Minimum    AS LONG     ' INT
   Maximum    AS LONG     ' INT
   Default    AS LONG     ' INT
   Multiplier AS SINGLE   ' FLOAT
END TYPE

' // Size = 20 bytes
TYPE DXVAHD_BLT_STATE_TARGET_RECT_DATA
   Enable     AS LONG   ' BOOL
   TargetRect AS RECT   ' RECT
END TYPE

' // Size = 20 bytes
TYPE DXVAHD_BLT_STATE_BACKGROUND_COLOR_DATA
   YCbCr           AS LONG           ' BOOL
   BackgroundColor AS DXVAHD_COLOR   ' DXVAHD_COLOR
END TYPE

' // Size = 4 bytes
TYPE DXVAHD_BLT_STATE_OUTPUT_COLOR_SPACE_DATA_UNION_STRUCT DWORD
   Usage        AS BIT * 1 IN DWORD
   RGB_Range    AS BIT * 1
   YCbCr_Matrix AS BIT * 1
   YCbCr_xvYCC  AS BIT * 1
   Reserved     AS BIT * 28
END TYPE

' // Size = 4 bytes
UNION DXVAHD_BLT_STATE_OUTPUT_COLOR_SPACE_DATA_UNION DWORD
   DXVAHD_BLT_STATE_OUTPUT_COLOR_SPACE_DATA_UNION_STRUCT
   Value AS DWORD   ' UINT
END UNION

' // Size = 4 bytes
TYPE DXVAHD_BLT_STATE_OUTPUT_COLOR_SPACE_DATA DWORD
   DXVAHD_BLT_STATE_OUTPUT_COLOR_SPACE_DATA_UNION
END TYPE

' // Size = 8 bytes
TYPE DXVAHD_BLT_STATE_ALPHA_FILL_DATA DWORD
   Mode         AS LONG    ' DXVAHD_ALPHA_FILL_MODE
   StreamNumber AS DWORD   ' UINT
END TYPE

' // Size = 12 bytes
TYPE DXVAHD_BLT_STATE_CONSTRICTION_DATA DWORD
   Enable AS LONG   ' BOOL
   Size   AS SIZE   ' SIZE
END TYPE

' // Size = 24 bytes
TYPE DXVAHD_BLT_STATE_PRIVATE_DATA DWORD
   Guid     AS GUID    ' GUID
   DataSize AS DWORD   ' UINT
   pData    AS DWORD   ' void *
END TYPE

' // Size = 4 bytes
TYPE DXVAHD_STREAM_STATE_D3DFORMAT_DATA DWORD
   Format AS DWORD   ' D3DFORMAT
END TYPE

' // Size = 4 bytes
TYPE DXVAHD_STREAM_STATE_FRAME_FORMAT_DATA DWORD
   FrameFormat AS LONG   ' DXVAHD_FRAME_FORMAT
END TYPE

' // Size = 4 bytes
TYPE DXVAHD_STREAM_STATE_INPUT_COLOR_SPACE_DATA_UNION_STRUCT DWORD
   Type         AS BIT * 1 IN DWORD
   RGB_Range    AS BIT * 1
   YCbCr_Matrix AS BIT * 1
   YCbCr_xvYCC  AS BIT * 1
   Reserved     AS BIT * 28
END TYPE

' // Size = 4 bytes
UNION DXVAHD_STREAM_STATE_INPUT_COLOR_SPACE_DATA_UNION DWORD
   DXVAHD_STREAM_STATE_INPUT_COLOR_SPACE_DATA_UNION_STRUCT
   Value AS DWORD   ' UINT
END UNION

' // Size = 4 bytes
TYPE DXVAHD_STREAM_STATE_INPUT_COLOR_SPACE_DATA DWORD
   DXVAHD_STREAM_STATE_INPUT_COLOR_SPACE_DATA_UNION
END TYPE

' // Size = 16 bytes
TYPE DXVAHD_STREAM_STATE_OUTPUT_RATE_DATA DWORD
   RepeatFrame AS LONG              ' BOOL
   OutputRate  AS LONG              ' DXVAHD_OUTPUT_RATE
   CustomRate  AS DXVAHD_RATIONAL   ' DXVAHD_RATIONAL
END TYPE

' // Size = 20 bytes
TYPE DXVAHD_STREAM_STATE_SOURCE_RECT_DATA DWORD
   Enable     AS LONG   ' BOOL
   SourceRect AS RECT   ' RECT
END TYPE

' // Size = 20 bytes
TYPE DXVAHD_STREAM_STATE_DESTINATION_RECT_DATA DWORD
   Enable          AS LONG   ' BOOL
   DestinationRect AS RECT   ' RECT
END TYPE

' // Size = 8 bytes
TYPE DXVAHD_STREAM_STATE_ALPHA_DATA DWORD
   Enable AS LONG     ' BOOL
   Alpha  AS SINGLE   ' FLOAT
END TYPE

' // Size = 8 bytes
TYPE DXVAHD_STREAM_STATE_PALETTE_DATA DWORD
   Count    AS DWORD       ' UINT
   pEntries AS DWORD PTR   ' D3DCOLOR *
END TYPE

' // Size = 12 bytes
TYPE DXVAHD_STREAM_STATE_LUMA_KEY_DATA DWORD
   Enable AS LONG     ' BOOL
   Lower  AS SINGLE   ' FLOAT
   Upper  AS SINGLE   ' FLOAT
END TYPE

' // Size = 20 bytes
TYPE DXVAHD_STREAM_STATE_ASPECT_RATIO_DATA DWORD
   Enable                 AS LONG              ' BOOL
   SourceAspectRatio      AS DXVAHD_RATIONAL   ' DXVAHD_RATIONAL
   DestinationAspectRatio AS DXVAHD_RATIONAL   ' DXVAHD_RATIONAL
END TYPE

' // Size = 8 bytes
TYPE DXVAHD_STREAM_STATE_FILTER_DATA DWORD
   Enable AS LONG   ' BOOL
   Level  AS LONG   ' INT
END TYPE

' // Size = 24 bytes
TYPE DXVAHD_STREAM_STATE_PRIVATE_DATA DWORD
   Guid     AS GUID    ' GUID
   DataSize AS DWORD   ' UINT
   pData    AS DWORD   ' void *
END TYPE

' // Size = 32 bytes
TYPE DXVAHD_STREAM_DATA DWORD
   Enable            AS LONG        ' BOOL
   OutputIndex       AS DWORD       ' UINT
   InputFrameOrField AS DWORD       ' UINT
   PastFrames        AS DWORD       ' UINT
   FutureFrames      AS DWORD       ' UINT
   ppPastSurfaces    AS DWORD PTR   ' IDirect3DSurface9 **
   pInputSurface     AS DWORD PTR   ' IDirect3DSurface9 *
   ppFutureSurfaces  AS DWORD PTR   ' IDirect3DSurface9 **
END TYPE

$DXVAHD_STREAM_STATE_PRIVATE_IVTC = GUID$("{9c601e3c-0f33-414c-a739-99540ee42da5}")

' // Size = 16 bytes
TYPE DXVAHD_STREAM_STATE_PRIVATE_IVTC_DATA DWORD
   Enable         AS LONG    ' BOOL
   ITelecineFlags AS DWORD   ' UINT
   Frames         AS DWORD   ' UINT
   InputField     AS DWORD   ' UINT
END TYPE

' ########################################################################################
' Interface name = IDXVAHD_Device
' IID = 95f12dfd-d77e-49be-815f-57d579634d6d
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDXVAHD_Device_INTERFACE_DEFINED)
    %IDXVAHD_Device_INTERFACE_DEFINED = 1

$IID_IDXVAHD_Device = GUID$("{95f12dfd-d77e-49be-815f-57d579634d6d}")

INTERFACE IDXVAHD_Device $IID_IDXVAHD_Device

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateVideoSurface ( _                        ' VTable offset = 12
     BYVAL Width AS DWORD _                             ' __in  UINT Width
   , BYVAL Height AS DWORD _                            ' __in  UINT Height
   , BYVAL Format AS DWORD _                            ' __in  D3DFORMAT Format
   , BYVAL Pool AS DWORD _                              ' __in  D3DPOOL Pool
   , BYVAL Usage AS DWORD _                             ' __in  DWORD Usage
   , BYVAL Type AS LONG _                               ' __in  DXVAHD_SURFACE_TYPE Type
   , BYVAL NumSurfaces AS DWORD _                       ' __in  UINT NumSurfaces
   , BYREF ppSurfaces AS IDirect3DSurface9 _            ' __out IDirect3DSurface9 **ppSurfaces
   , BYREF pSharedHandle AS DWORD _                     ' __inout_opt HANDLE *pSharedHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoProcessorDeviceCaps ( _               ' VTable offset = 16
     BYREF pCaps AS DXVAHD_VPDEVCAPS _                  ' __out DXVAHD_VPDEVCAPS *pCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoProcessorOutputFormats ( _            ' VTable offset = 20
     BYVAL Count AS DWORD _                             ' __in  UINT Count
   , BYREF pFormats AS DWORD _                          ' __out D3DFORMAT *pFormats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoProcessorInputFormats ( _             ' VTable offset = 24
     BYVAL Count AS DWORD _                             ' __in  UINT Count
   , BYREF pFormats AS DWORD _                          ' __out D3DFORMAT *pFormats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoProcessorCaps ( _                     ' VTable offset = 28
     BYVAL Count AS DWORD _                             ' __in  UINT Count
   , BYREF pFormats AS DXVAHD_VPCAPS _                  ' __out DXVAHD_VPCAPS *pFormats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoProcessorCustomRates ( _              ' VTable offset = 32
     BYREF pVPGuid AS GUID _                            ' __in  const GUID *pVPGuid
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   , BYREF pRates AS DXVAHD_CUSTOM_RATE_DATA _          ' __out DXVAHD_CUSTOM_RATE_DATA *pRates
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoProcessorFilterRange ( _              ' VTable offset = 36
     BYVAL Filter AS DWORD _                            ' __in  DXVAHD_FILTER Filter
   , BYREF pRange AS DXVAHD_FILTER_RANGE_DATA _         ' __out  DXVAHD_FILTER_RANGE_DATA *pRange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateVideoProcessor ( _                      ' VTable offset = 40
     BYREF pVPGuid AS GUID _                            ' __in  const GUID *pVPGuid
   , BYREF ppVideoProcessor AS IDXVAHD_VideoProcessor _ ' __out  IDXVAHD_VideoProcessor **ppVideoProcessor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXVAHD_Device_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDXVAHD_VideoProcessor
' IID = 95f4edf4-6e03-4cd7-be1b-3075d665aa52
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDXVAHD_VideoProcessor_INTERFACE_DEFINED)
    %IDXVAHD_VideoProcessor_INTERFACE_DEFINED = 1

$IID_IDXVAHD_VideoProcessor = GUID$("{95f4edf4-6e03-4cd7-be1b-3075d665aa52}")

INTERFACE IDXVAHD_VideoProcessor $IID_IDXVAHD_VideoProcessor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetVideoProcessBltState ( _                   ' VTable offset = 12
     BYVAL State AS LONG _                              ' __in DXVAHD_BLT_STATE State
   , BYVAL DataSize AS DWORD _                          ' __in UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoProcessBltState ( _                   ' VTable offset = 12
     BYVAL State AS LONG _                              ' __in DXVAHD_BLT_STATE State
   , BYVAL DataSize AS DWORD _                          ' __in UINT DataSize
   , BYVAL pData AS DWORD _                             ' __inout void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVideoProcessStreamState ( _                ' VTable offset = 16
     BYVAL StreamNumber AS DWORD _                      ' __in UINT StreamNumber
   , BYVAL State AS LONG _                              ' __in DXVAHD_STREAM_STATE State
   , BYVAL DataSize AS DWORD _                          ' __in UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoProcessStreamState ( _                ' VTable offset = 20
     BYVAL StreamNumber AS DWORD _                      ' __in UINT StreamNumber
   , BYVAL State AS LONG _                              ' __in DXVAHD_STREAM_STATE State
   , BYVAL DataSize AS DWORD _                          ' __in UINT DataSize
   , BYVAL pData AS DWORD _                             ' __inout void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD VideoProcessBltHD ( _                         ' VTable offset = 24
     BYVAL pOutputSurface AS IDirect3DSurface9 _        ' __in IDirect3DSurface9 *pOutputSurface
   , BYVAL OutputFrame AS DWORD _                       ' __in UINT OutputFrame
   , BYVAL StreamCount AS DWORD _                       ' __in UINT StreamCount
   , BYREF pStreams AS DXVAHD_STREAM_DATA _             ' __in const DXVAHD_STREAM_DATA *pStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDXVAHD_VideoProcessor_INTERFACE_DEFINED__ */

'typedef HRESULT (CALLBACK* PDXVAHDSW_CreateDevice)(
'    __in IDirect3DDevice9Ex* pD3DDevice,
'    __out HANDLE* phDevice
'    );

'FUNCTION PDXVAHDSW_CreateDevice (BYVAL pD3DDevice AS IDirect3DDevice9Ex, BYREF phDevice AS DWORD) AS LONG

'typedef HRESULT (CALLBACK* PDXVAHDSW_ProposeVideoPrivateFormat)(
'    __in HANDLE hDevice,
'    __inout D3DFORMAT* pFormat
'    );

'FUNCTION PDXVAHDSW_ProposeVideoPrivateFormat (BYVAL hDevice AS DWORD, BYREF pFormat AS DWORD) AS LONG

'typedef HRESULT (CALLBACK* PDXVAHDSW_GetVideoProcessorDeviceCaps)(
'    __in HANDLE hDevice,
'    __in const DXVAHD_CONTENT_DESC* pContentDesc,
'    __in DXVAHD_DEVICE_USAGE Usage,
'    __out DXVAHD_VPDEVCAPS* pCaps
'    );

'FUNCTION PDXVAHDSW_GetVideoProcessorDeviceCaps (BYVAL hDevice AS DWORD, BYREF pContentDesc AS DXVAHD_CONTENT_DESC, BYVAL Usage AS LONG, BYREF pCaps AS DXVAHD_VPDEVCAPS) AS LONG

'typedef HRESULT (CALLBACK* PDXVAHDSW_GetVideoProcessorOutputFormats)(
'    __in HANDLE hDevice,
'    __in const DXVAHD_CONTENT_DESC* pContentDesc,
'    __in DXVAHD_DEVICE_USAGE Usage,
'    __in UINT Count,
'    __out_ecount(Count) D3DFORMAT* pFormats
'    );

'FUNCTION PDXVAHDSW_GetVideoProcessorOutputFormats (BYVAL hDevice AS DWORD, BYREF pContentDesc AS DXVAHD_CONTENT_DESC, BYVAL Usage AS LONG, BYVAL nCount AS DWORD, BYREF pFormats AS DWORD) AS LONG

'typedef HRESULT (CALLBACK* PDXVAHDSW_GetVideoProcessorInputFormats)(
'    __in HANDLE hDevice,
'    __in const DXVAHD_CONTENT_DESC* pContentDesc,
'    __in DXVAHD_DEVICE_USAGE Usage,
'    __in UINT Count,
'    __out_ecount(Count) D3DFORMAT* pFormats
'    );

'FUNCTION PDXVAHDSW_GetVideoProcessorInputFormats (BYVAL hDevice AS DWORD, BYREF pContentDesc AS DXVAHD_CONTENT_DESC, BYVAL Usage AS LONG, BYVAL nCount AS DWORD, BYREF pFormats AS DWORD) AS LONG

'typedef HRESULT (CALLBACK* PDXVAHDSW_GetVideoProcessorCaps)(
'    __in HANDLE hDevice,
'    __in const DXVAHD_CONTENT_DESC* pContentDesc,
'    __in DXVAHD_DEVICE_USAGE Usage,
'    __in UINT Count,
'    __out_ecount(Count) DXVAHD_VPCAPS* pCaps
'    );

'FUNCTION PDXVAHDSW_GetVideoProcessorCaps (BYVAL hDevice AS DWORD, BYREF pContentDesc AS DXVAHD_CONTENT_DESC, BYVAL Usage AS LONG, BYVAL nCount AS DWORD, BYREF pCaps AS DXVAHD_VPCAPS) AS LONG

'typedef HRESULT (CALLBACK* PDXVAHDSW_GetVideoProcessorCustomRates)(
'    __in HANDLE hDevice,
'    __in const GUID* pVPGuid,
'    __in UINT Count,
'    __out_ecount(Count) DXVAHD_CUSTOM_RATE_DATA* pRates
'    );

'FUNCTION PDXVAHDSW_GetVideoProcessorCustomRates (BYVAL hDevice AS DWORD, BYREF pVPGuid AS GUID, BYVAL nCount AS DWORD, BYREF pRates AS DXVAHD_CUSTOM_RATE_DATA) AS LONG

'typedef HRESULT (CALLBACK* PDXVAHDSW_GetVideoProcessorFilterRange)(
'    __in HANDLE hDevice,
'    __in DXVAHD_FILTER Filter,
'    __out DXVAHD_FILTER_RANGE_DATA* pRange
'    );

'FUNCTION PDXVAHDSW_GetVideoProcessorFilterRange (BYVAL hDevice AS DWORD, BYVAL Filter AS DWORD, BYREF pRates AS DXVAHD_FILTER_RANGE_DATA) AS LONG

'typedef HRESULT (CALLBACK* PDXVAHDSW_DestroyDevice)(
'    __in HANDLE hDevice
'    );

'FUNCTION PDXVAHDSW_DestroyDevice (BYVAL hDevice AS DWORD) AS LONG

'typedef HRESULT (CALLBACK* PDXVAHDSW_CreateVideoProcessor)(
'    __in HANDLE hDevice,
'    __in const GUID* pVPGuid,
'    __out HANDLE* phVideoProcessor
'    );

'FUNCTION PDXVAHDSW_CreateVideoProcessor (BYVAL hDevice AS DWORD, BYREF pVPGuid AS GUID, BYREF phVideoProcessor AS DWORD) AS LONG

'typedef HRESULT (CALLBACK* PDXVAHDSW_SetVideoProcessBltState)(
'    __in HANDLE hVideoProcessor,
'    __in DXVAHD_BLT_STATE State,
'    __in UINT DataSize,
'    __in_bcount(DataSize) const void* pData
'    );

'FUNCTION PDXVAHDSW_SetVideoProcessBltState (BYVAL hVideoProcessor AS DWORD, BYVAL nState AS LONG, BYVAL DataSize AS DWORD, BYVAL pData AS DWORD) AS LONG

'typedef HRESULT (CALLBACK* PDXVAHDSW_GetVideoProcessBltStatePrivate)(
'    __in HANDLE hVideoProcessor,
'    __inout DXVAHD_BLT_STATE_PRIVATE_DATA* pData
'    );

'FUNCTION PDXVAHDSW_GetVideoProcessBltStatePrivate (BYVAL hVideoProcessor AS DWORD, BYREF pData AS DXVAHD_BLT_STATE_PRIVATE_DATA) AS LONG

'typedef HRESULT (CALLBACK* PDXVAHDSW_SetVideoProcessStreamState)(
'    __in HANDLE hVideoProcessor,
'    __in UINT StreamNumber,
'    __in DXVAHD_STREAM_STATE State,
'    __in UINT DataSize,
'    __in_bcount(DataSize) const void* pData
'    );

'FUNCTION PDXVAHDSW_SetVideoProcessStreamState (BYVAL hVideoProcessor AS DWORD, BYVAL StreamNumber AS DWORD, BYVAL nState AS LONG, BYVAL DataSize AS DWORD, BYVAL pData AS DWORD) AS LONG

'typedef HRESULT (CALLBACK* PDXVAHDSW_GetVideoProcessStreamStatePrivate)(
'    __in HANDLE hVideoProcessor,
'    __in UINT StreamNumber,
'    __inout DXVAHD_STREAM_STATE_PRIVATE_DATA* pData
'    );

'FUNCTION PDXVAHDSW_SetVideoProcessStreamState (BYVAL hVideoProcessor AS DWORD, BYVAL StreamNumber AS DWORD, BYREF pData AS DXVAHD_STREAM_STATE_PRIVATE_DATA) AS LONG

'typedef HRESULT (CALLBACK* PDXVAHDSW_VideoProcessBltHD)(
'    __in HANDLE hVideoProcessor,
'    __in IDirect3DSurface9* pOutputSurface,
'    __in UINT OutputFrame,
'    __in UINT StreamCount,
'    __in_ecount(StreamCount) const DXVAHD_STREAM_DATA* pStreams
'    );

'FUNCTION PDXVAHDSW_VideoProcessBltHD (BYVAL hVideoProcessor AS DWORD, BYVAL pOutputSurface AS IDirect3DSurface9, BYVAL OutputFrame AS DWORD, BYVAL StreamCount AS DWORD, BYREF pStreams AS DXVAHD_STREAM_DATA) AS LONG

'typedef HRESULT (CALLBACK* PDXVAHDSW_DestroyVideoProcessor)(
'    __in HANDLE hVideoProcessor
'    );

'FUNCTION PDXVAHDSW_DestroyVideoProcessor (BYVAL hVideoProcessor AS DWORD) AS LONG

' // Size = 64 bytes
TYPE DXVAHDSW_CALLBACKS DWORD
   CreateDevice                      AS DWORD   ' PDXVAHDSW_CreateDevice
   ProposeVideoPrivateFormat         AS DWORD   ' PDXVAHDSW_ProposeVideoPrivateFormat
   GetVideoProcessorDeviceCaps       AS DWORD   ' PDXVAHDSW_GetVideoProcessorDeviceCaps
   GetVideoProcessorOutputFormats    AS DWORD   ' PDXVAHDSW_GetVideoProcessorOutputFormats
   GetVideoProcessorInputFormats     AS DWORD   ' PDXVAHDSW_GetVideoProcessorInputFormats
   GetVideoProcessorCaps             AS DWORD   ' PDXVAHDSW_GetVideoProcessorCaps
   GetVideoProcessorCustomRates      AS DWORD   ' PDXVAHDSW_GetVideoProcessorCustomRates
   GetVideoProcessorFilterRange      AS DWORD   ' PDXVAHDSW_GetVideoProcessorFilterRange
   DestroyDevice                     AS DWORD   ' PDXVAHDSW_DestroyDevice
   CreateVideoProcessor              AS DWORD   ' PDXVAHDSW_CreateVideoProcessor
   SetVideoProcessBltState           AS DWORD   ' PDXVAHDSW_SetVideoProcessBltState
   GetVideoProcessBltStatePrivate    AS DWORD   ' PDXVAHDSW_GetVideoProcessBltStatePrivate
   SetVideoProcessStreamState        AS DWORD   ' PDXVAHDSW_SetVideoProcessStreamState
   GetVideoProcessStreamStatePrivate AS DWORD   ' PDXVAHDSW_GetVideoProcessStreamStatePrivate
   VideoProcessBltHD                 AS DWORD   ' PDXVAHDSW_VideoProcessBltHD
   DestroyVideoProcessor             AS DWORD   ' PDXVAHDSW_DestroyVideoProcessor
END TYPE

'typedef HRESULT (CALLBACK* PDXVAHDSW_Plugin)(
'    __in UINT Size,
'    __out_bcount(Size) void* pCallbacks
'    );

'FUNCTION PDXVAHDSW_Plugin (BYVAL nSize AS DWORD, BYREF pCallbacks AS DWORD) AS LONG

$DXVAHDControlGuid = GUID$("{a0386e75-f70c-464c-a9ce-33c44e091623}")
$DXVAHDETWGUID_CREATEVIDEOPROCESSOR = GUID$("{681e3d1e-5674-4fb3-a503-2f2055e91f60}")
$DXVAHDETWGUID_VIDEOPROCESSBLTSTATE = GUID$("{76c94b5a-193f-4692-9484-a4d999da81a8}")
$DXVAHDETWGUID_VIDEOPROCESSSTREAMSTATE = GUID$("{262c0b02-209d-47ed-94d8-82ae02b84aa7}")
$DXVAHDETWGUID_VIDEOPROCESSBLTHD = GUID$("{bef3d435-78c7-4de3-9707-cd1b083b160a}")
$DXVAHDETWGUID_VIDEOPROCESSBLTHD_STREAM = GUID$("{27ae473e-a5fc-4be5-b4e3-f24994d3c495}")
$DXVAHDETWGUID_DESTROYVIDEOPROCESSOR = GUID$("{f943f0a0-3f16-43e0-8093-105a986aa5f1}")

' // Size = 32 bytes
TYPE DXVAHDETW_CREATEVIDEOPROCESSOR   ' Must be 8 byte aligned
   pObject AS QUAD   ' ULONGLONG
   pD3D9Ex AS QUAD   ' ULONGLONG
   VPGuid  AS GUID   ' GUID
END TYPE

' // Size = 24 bytes
TYPE DXVAHDETW_VIDEOPROCESSBLTSTATE   ' Must be 8 byte aligned
   pObject    AS QUAD    ' ULONGLONG
   State      AS LONG    ' DXVAHD_BLT_STATE
   DataSize   AS DWORD   ' UINT
   SetState   AS LONG    ' BOOL
   alignment_ AS DWORD   ' // To keep 8 byte alignment
END TYPE

' // Size = 24 bytes
TYPE DXVAHDETW_VIDEOPROCESSSTREAMSTATE   ' Must be 8 byte aligned
   pObject      AS QUAD    ' ULONGLONG
   StreamNumber AS DWORD   ' U(INT
   State        AS LONG    ' DXVAHD_STREAM_STATE
   DataSize     AS DWORD   ' UINT
   SetState     AS LONG    ' BOOL
END TYPE

' // Size = 56 bytes
TYPE DXVAHDETW_VIDEOPROCESSBLTHD   ' Must be 8 byte aligned
   pObject        AS QUAD    ' ULONGLONG
   pOutputSurface AS QUAD    ' ULONGLONG
   TargetRect     AS RECT    ' RECT
   OutputFormat   AS DWORD   ' D3DFORMAT
   ColorSpace     AS DWORD   ' UINT
   OutputFrame    AS DWORD   ' UINT
   StreamCount    AS DWORD   ' UINT
   Enter          AS LONG    ' BOOL
   alignment_     AS DWORD   ' // To keep 8 byte alignment
END TYPE

' // Size = 80 bytes
TYPE DXVAHDETW_VIDEOPROCESSBLTHD_STREAM   ' Must be 8 byte aligned
   pObject           AS QUAD    ' ULONGLONG
   pInputSurface     AS QUAD    ' ULONGLONG
   SourceRect        AS RECT    ' RECT
   DestinationRect   AS RECT    ' RECT
   InputFormat       AS DWORD   ' D3DFORMAT
   FrameFormat       AS LONG    ' DXVAHD_FRAME_FORMAT
   ColorSpace        AS DWORD   ' UINT
   StreamNumber      AS DWORD   ' UINT
   OutputIndex       AS DWORD   ' UINT
   InputFrameOrField AS DWORD   ' UINT
   PastFrames        AS DWORD   ' UINT
   FutureFrames      AS DWORD   ' UINT
END TYPE

' // Size = 8 bytes
TYPE DXVAHDETW_DESTROYVIDEOPROCESSOR   ' Must be 8 byte aligned
   pObject AS QUAD   ' ULONGLONG
END TYPE

DECLARE FUNCTION DXVAHD_CreateDevice IMPORT "Dxva2.dll" ALIAS "DXVAHD_CreateDevice" ( _
   BYVAL pD3DDevice AS IDirect3DDevice9Ex _             ' __in IDirect3DDevice9Ex* pD3DDevice
 , BYREF pContentDesc AS DXVAHD_CONTENT_DESC _          ' __in const DXVAHD_CONTENT_DESC* pContentDesc
 , BYVAL Usage AS LONG _                                ' __in DXVAHD_DEVICE_USAGE Usage
 , BYVAL pPlugin AS DWORD _                             ' __in_opt PDXVAHDSW_Plugin pPlugin
 , BYREF ppDevice AS IDXVAHD_Device _                   ' __out IDXVAHD_Device** ppDevice
 ) AS LONG                                              ' HRESULT
