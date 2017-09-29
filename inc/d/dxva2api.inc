' ########################################################################################
' Microsoft Windows
' File: dxva2api.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DXVA2API_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "d3d9.inc"
#INCLUDE ONCE "unknwn.inc"

'#ifndef DXVA2_API_DEFINED
'#define DXVA2_API_DEFINED

$DXVA2_ModeMPEG2_MoComp           = GUID$("{e6a9f44b-61b0-4563-9ea4-63d2a3c6fe66}")
$DXVA2_ModeMPEG2_IDCT             = GUID$("{bf22ad00-03ea-4690-8077-473346209b7e}")
$DXVA2_ModeMPEG2_VLD              = GUID$("{ee27417f-5e28-4e65-beea-1d26b508adc9}")
$DXVA2_ModeH264_A                 = GUID$("{1b81be64-a0c7-11d3-b984-00c04f2e73c5}")
$DXVA2_ModeH264_B                 = GUID$("{1b81be65-a0c7-11d3-b984-00c04f2e73c5}")
$DXVA2_ModeH264_C                 = GUID$("{1b81be66-a0c7-11d3-b984-00c04f2e73c5}")
$DXVA2_ModeH264_D                 = GUID$("{1b81be67-a0c7-11d3-b984-00c04f2e73c5}")
$DXVA2_ModeH264_E                 = GUID$("{1b81be68-a0c7-11d3-b984-00c04f2e73c5}")
$DXVA2_ModeH264_F                 = GUID$("{1b81be69-a0c7-11d3-b984-00c04f2e73c5}")
$DXVA2_ModeWMV8_A                 = GUID$("{1b81be80-a0c7-11d3-b984-00c04f2e73c5}")
$DXVA2_ModeWMV8_B                 = GUID$("{1b81be81-a0c7-11d3-b984-00c04f2e73c5}")
$DXVA2_ModeWMV9_A                 = GUID$("{1b81be90-a0c7-11d3-b984-00c04f2e73c5}")
$DXVA2_ModeWMV9_B                 = GUID$("{1b81be91-a0c7-11d3-b984-00c04f2e73c5}")
$DXVA2_ModeWMV9_C                 = GUID$("{1b81be94-a0c7-11d3-b984-00c04f2e73c5}")
$DXVA2_ModeVC1_A                  = GUID$("{1b81beA0-a0c7-11d3-b984-00c04f2e73c5}")
$DXVA2_ModeVC1_B                  = GUID$("{1b81beA1-a0c7-11d3-b984-00c04f2e73c5}")
$DXVA2_ModeVC1_C                  = GUID$("{1b81beA2-a0c7-11d3-b984-00c04f2e73c5}")
$DXVA2_ModeVC1_D                  = GUID$("{1b81beA3-a0c7-11d3-b984-00c04f2e73c5}")
$DXVA2_NoEncrypt                  = GUID$("{1b81beD0-a0c7-11d3-b984-00c04f2e73c5}")
$DXVA2_VideoProcProgressiveDevice = GUID$("{5a54a0c9-c7ec-4bd9-8ede-f3c75dc4393b}")
$DXVA2_VideoProcBobDevice         = GUID$("{335aa36e-7884-43a4-9c91-7f87faf3e37e}")
$DXVA2_VideoProcSoftwareDevice    = GUID$("{4553d47f-ee7e-4e3f-9475-dbf1376c4810}")

'#define DXVA2_ModeMPEG2_MOCOMP      DXVA2_ModeMPEG2_MoComp
$DXVA2_ModeWMV8_PostProc     = $DXVA2_ModeWMV8_A
$DXVA2_ModeWMV8_MoComp       = $DXVA2_ModeWMV8_B
$DXVA2_ModeWMV9_PostProc     = $DXVA2_ModeWMV9_A
$DXVA2_ModeWMV9_MoComp       = $DXVA2_ModeWMV9_B
$DXVA2_ModeWMV9_IDCT         = $DXVA2_ModeWMV9_C
$DXVA2_ModeVC1_PostProc      = $DXVA2_ModeVC1_A
$DXVA2_ModeVC1_MoComp        = $DXVA2_ModeVC1_B
$DXVA2_ModeVC1_IDCT          = $DXVA2_ModeVC1_C
$DXVA2_ModeVC1_VLD           = $DXVA2_ModeVC1_D
$DXVA2_ModeH264_MoComp_NoFGT = $DXVA2_ModeH264_A
$DXVA2_ModeH264_MoComp_FGT   = $DXVA2_ModeH264_B
$DXVA2_ModeH264_IDCT_NoFGT   = $DXVA2_ModeH264_C
$DXVA2_ModeH264_IDCT_FGT     = $DXVA2_ModeH264_D
$DXVA2_ModeH264_VLD_NoFGT    = $DXVA2_ModeH264_E
$DXVA2_ModeH264_VLD_FGT      = $DXVA2_ModeH264_F

%DXVA2_E_NOT_INITIALIZED     = &H80041000&
%DXVA2_E_NEW_VIDEO_DEVICE    = &H80041001&
%DXVA2_E_VIDEO_DEVICE_LOCKED = &H80041002&
%DXVA2_E_NOT_AVAILABLE       = &H80041003&

'#if defined(_WIN32) && !defined(_NO_COM)
$IID_IDirect3DDeviceManager9          = GUID$("{a0cade0f-06d5-4cf4-a1c7-f3cdd725aa75}")
$IID_IDirectXVideoAccelerationService = GUID$("{fc51a550-d5e7-11d9-af55-00054e43ff02}")
$IID_IDirectXVideoDecoderService      = GUID$("{fc51a551-d5e7-11d9-af55-00054e43ff02}")
$IID_IDirectXVideoProcessorService    = GUID$("{fc51a552-d5e7-11d9-af55-00054e43ff02}")
$IID_IDirectXVideoDecoder             = GUID$("{f2b0810a-fd00-43c9-918c-df94e2d8ef7d}")
$IID_IDirectXVideoProcessor           = GUID$("{8c3a39f0-916e-4690-804f-4c8001355d25}")
$IID_IDirectXVideoMemoryConfiguration = GUID$("{b7f916dd-db3b-49c1-84d7-e45ef99ec726}")
'#endif

#IF NOT %DEF(%MAX_DEINTERLACE_SURFACES)
%MAX_DEINTERLACE_SURFACES = 32
#ENDIF

#IF NOT %DEF(%MAX_SUBSTREAMS)
%MAX_SUBSTREAMS = 15
#ENDIF

' // Sizse = 4 bytes
UNION DXVA2_ExtendedFormat_STRUCT DWORD
   SampleFormat           AS BIT * 8 IN DWORD
   VideoChromaSubsampling AS BIT * 4
   NominalRange           AS BIT * 3
   VideoTransferMatrix    AS BIT * 3
   VideoLighting          AS BIT * 4
   VideoPrimaries         AS BIT * 5
   VideoTransferFunction  AS BIT * 5
   value AS DWORD   ' UINT
END UNION

' // Sizse = 4 bytes
TYPE DXVA2_ExtendedFormat DWORD
   DXVA2_ExtendedFormat_STRUCT
END TYPE

' enum DXVA2_SampleFormat
%DXVA2_SampleFormatMask                = &Hff
%DXVA2_SampleUnknown                   = 0
%DXVA2_SampleProgressiveFrame          = 2
%DXVA2_SampleFieldInterleavedEvenFirst = 3
%DXVA2_SampleFieldInterleavedOddFirst  = 4
%DXVA2_SampleFieldSingleEven           = 5
%DXVA2_SampleFieldSingleOdd            = 6
%DXVA2_SampleSubStream                 = 7

' enum %DXVA2_VideoChromaSubSampling
%DXVA2_VideoChromaSubsamplingMask                            = &Hf
%DXVA2_VideoChromaSubsampling_Unknown                        = 0
%DXVA2_VideoChromaSubsampling_ProgressiveChroma              = &H8
%DXVA2_VideoChromaSubsampling_Horizontally_Cosited           = &H4
%DXVA2_VideoChromaSubsampling_Vertically_Cosited             = &H2
%DXVA2_VideoChromaSubsampling_Vertically_AlignedChromaPlanes = &H1
%DXVA2_VideoChromaSubsampling_MPEG2                          = %DXVA2_VideoChromaSubsampling_Horizontally_Cosited  OR %DXVA2_VideoChromaSubsampling_Vertically_AlignedChromaPlanes
%DXVA2_VideoChromaSubsampling_MPEG1                          = %DXVA2_VideoChromaSubsampling_Vertically_AlignedChromaPlanes
%DXVA2_VideoChromaSubsampling_DV_PAL                         = %DXVA2_VideoChromaSubsampling_Horizontally_Cosited  OR %DXVA2_VideoChromaSubsampling_Vertically_Cosited
%DXVA2_VideoChromaSubsampling_Cosited                        = (%DXVA2_VideoChromaSubsampling_Horizontally_Cosited OR %DXVA2_VideoChromaSubsampling_Vertically_Cosited) OR %DXVA2_VideoChromaSubsampling_Vertically_AlignedChromaPlanes

' enum DXVA2_NominalRange
%DXVA2_NominalRangeMask     = &H7
%DXVA2_NominalRange_Unknown = 0
%DXVA2_NominalRange_Normal  = 1
%DXVA2_NominalRange_Wide    = 2
%DXVA2_NominalRange_0_255   = 1
%DXVA2_NominalRange_16_235  = 2
%DXVA2_NominalRange_48_208  = 3

' enum DXVA2_VideoTransferMatrix
%DXVA2_VideoTransferMatrixMask       = &H7
%DXVA2_VideoTransferMatrix_Unknown   = 0
%DXVA2_VideoTransferMatrix_BT709     = 1
%DXVA2_VideoTransferMatrix_BT601     = 2
%DXVA2_VideoTransferMatrix_SMPTE240M = 3

' enum _DXVA2_VideoLighting
%DXVA2_VideoLightingMask     = &Hf
%DXVA2_VideoLighting_Unknown = 0
%DXVA2_VideoLighting_bright  = 1
%DXVA2_VideoLighting_office  = 2
%DXVA2_VideoLighting_dim     = 3
%DXVA2_VideoLighting_dark    = 4

' enum DXVA2_VideoPrimaries
%DXVA2_VideoPrimariesMask           = &H1f
%DXVA2_VideoPrimaries_Unknown       = 0
%DXVA2_VideoPrimaries_reserved      = 1
%DXVA2_VideoPrimaries_BT709         = 2
%DXVA2_VideoPrimaries_BT470_2_SysM  = 3
%DXVA2_VideoPrimaries_BT470_2_SysBG = 4
%DXVA2_VideoPrimaries_SMPTE170M     = 5
%DXVA2_VideoPrimaries_SMPTE240M     = 6
%DXVA2_VideoPrimaries_EBU3213       = 7
%DXVA2_VideoPrimaries_SMPTE_C       = 8

' enum DXVA2_VideoTransferFunction
%DXVA2_VideoTransFuncMask     = &H1f
%DXVA2_VideoTransFunc_Unknown = 0
%DXVA2_VideoTransFunc_10      = 1
%DXVA2_VideoTransFunc_18      = 2
%DXVA2_VideoTransFunc_20      = 3
%DXVA2_VideoTransFunc_22      = 4
%DXVA2_VideoTransFunc_709     = 5
%DXVA2_VideoTransFunc_240M    = 6
%DXVA2_VideoTransFunc_sRGB    = 7
%DXVA2_VideoTransFunc_28      = 8

'//
'// Deprecated labels - please use the ones in the DXVA2_VideoTransferFunction enum.
'//
%DXVA2_VideoTransFunc_22_709         = %DXVA2_VideoTransFunc_709
%DXVA2_VideoTransFunc_22_240M        = %DXVA2_VideoTransFunc_240M
%DXVA2_VideoTransFunc_22_8bit_sRGB   = %DXVA2_VideoTransFunc_sRGB

' // Size = 8 bytes
TYPE DXVA2_Frequency DWORD
   Numerator   AS DWORD   ' UINT
   Denominator AS DWORD   ' UINT
END TYPE

' // Size = 40 bytes
TYPE DXVA2_VideoDesc DWORD
   SampleWidth        AS DWORD                  ' UINT
   SampleHeight       AS DWORD                  ' UINT
   SampleFormat       AS DXVA2_ExtendedFormat
   Format             AS DWORD                  ' D3DFORMAT
   InputSampleFreq    AS DXVA2_Frequency
   OutputFrameFreq    AS DXVA2_Frequency
   UABProtectionLevel AS DWORD                  ' UINT
   Reserved           AS DWORD                  ' UINT
END TYPE


' enum MIDL___MIDL_itf_dxva2api_0000_0000_0003
%DXVA2_DeinterlaceTech_Unknown                = 0
%DXVA2_DeinterlaceTech_BOBLineReplicate       = &H1
%DXVA2_DeinterlaceTech_BOBVerticalStretch     = &H2
%DXVA2_DeinterlaceTech_BOBVerticalStretch4Tap = &H4
%DXVA2_DeinterlaceTech_MedianFiltering        = &H8
%DXVA2_DeinterlaceTech_EdgeFiltering          = &H10
%DXVA2_DeinterlaceTech_FieldAdaptive          = &H20
%DXVA2_DeinterlaceTech_PixelAdaptive          = &H40
%DXVA2_DeinterlaceTech_MotionVectorSteered    = &H80
%DXVA2_DeinterlaceTech_InverseTelecine        = &H100
%DXVA2_DeinterlaceTech_Mask                   = &H1ff

' enum __MIDL___MIDL_itf_dxva2api_0000_0000_0004
%DXVA2_NoiseFilterLumaLevel        = 1
%DXVA2_NoiseFilterLumaThreshold    = 2
%DXVA2_NoiseFilterLumaRadius       = 3
%DXVA2_NoiseFilterChromaLevel      = 4
%DXVA2_NoiseFilterChromaThreshold  = 5
%DXVA2_NoiseFilterChromaRadius     = 6
%DXVA2_DetailFilterLumaLevel       = 7
%DXVA2_DetailFilterLumaThreshold   = 8
%DXVA2_DetailFilterLumaRadius      = 9
%DXVA2_DetailFilterChromaLevel     = 10
%DXVA2_DetailFilterChromaThreshold = 11
%DXVA2_DetailFilterChromaRadius    = 12

' enum __MIDL___MIDL_itf_dxva2api_0000_0000_0005
%DXVA2_NoiseFilterTech_Unsupported   = 0
%DXVA2_NoiseFilterTech_Unknown       = &H1
%DXVA2_NoiseFilterTech_Median        = &H2
%DXVA2_NoiseFilterTech_Temporal      = &H4
%DXVA2_NoiseFilterTech_BlockNoise    = &H8
%DXVA2_NoiseFilterTech_MosquitoNoise = &H10
%DXVA2_NoiseFilterTech_Mask          = &H1f

' enum __MIDL___MIDL_itf_dxva2api_0000_0000_0006
%DXVA2_DetailFilterTech_Unsupported = 0
%DXVA2_DetailFilterTech_Unknown     = &H1
%DXVA2_DetailFilterTech_Edge        = &H2
%DXVA2_DetailFilterTech_Sharpening  = &H4
%DXVA2_DetailFilterTech_Mask        = &H7

' enum __MIDL___MIDL_itf_dxva2api_0000_0000_0007
%DXVA2_ProcAmp_None       = 0
%DXVA2_ProcAmp_Brightness = &H1
%DXVA2_ProcAmp_Contrast   = &H2
%DXVA2_ProcAmp_Hue        = &H4
%DXVA2_ProcAmp_Saturation = &H8
%DXVA2_ProcAmp_Mask       = &Hf

' enum __MIDL___MIDL_itf_dxva2api_0000_0000_0008
%DXVA2_VideoProcess_None                       = 0
%DXVA2_VideoProcess_YUV2RGB                    = &H1
%DXVA2_VideoProcess_StretchX                   = &H2
%DXVA2_VideoProcess_StretchY                   = &H4
%DXVA2_VideoProcess_AlphaBlend                 = &H8
%DXVA2_VideoProcess_SubRects                   = &H10
%DXVA2_VideoProcess_SubStreams                 = &H20
%DXVA2_VideoProcess_SubStreamsExtended         = &H40
%DXVA2_VideoProcess_YUV2RGBExtended            = &H80
%DXVA2_VideoProcess_AlphaBlendExtended         = &H100
%DXVA2_VideoProcess_Constriction               = &H200
%DXVA2_VideoProcess_NoiseFilter                = &H400
%DXVA2_VideoProcess_DetailFilter               = &H800
%DXVA2_VideoProcess_PlanarAlpha                = &H1000
%DXVA2_VideoProcess_LinearScaling              = &H2000
%DXVA2_VideoProcess_GammaCompensated           = &H4000
%DXVA2_VideoProcess_MaintainsOriginalFieldData = &H8000
%DXVA2_VideoProcess_Mask                       = &Hffff

' enum __MIDL___MIDL_itf_dxva2api_0000_0000_0009
%DXVA2_VPDev_HardwareDevice = &H1
%DXVA2_VPDev_EmulatedDXVA1  = &H2
%DXVA2_VPDev_SoftwareDevice = &H4
%DXVA2_VPDev_Mask           = &H7

' enum __MIDL___MIDL_itf_dxva2api_0000_0000_0010
%DXVA2_SampleData_RFF             = &H1
%DXVA2_SampleData_TFF             = &H2
%DXVA2_SampleData_RFF_TFF_Present = &H4
%DXVA2_SampleData_Mask            = &Hffff

' enum __MIDL___MIDL_itf_dxva2api_0000_0000_0011
%DXVA2_DestData_RFF             = &H1
%DXVA2_DestData_TFF             = &H2
%DXVA2_DestData_RFF_TFF_Present = &H4
%DXVA2_DestData_Mask            = &Hffff

' // Size = 40 bytes
TYPE DXVA2_VideoProcessorCaps DWORD
   DeviceCaps               AS DWORD   ' UINT
   InputPool                AS DWORD   ' D3DPOOL
   NumForwardRefSamples     AS DWORD   ' UINT
   NumBackwardRefSamples    AS DWORD   ' UINT
   Reserved                 AS DWORD   ' UINT
   DeinterlaceTechnology    AS DWORD   ' UINT
   ProcAmpControlCaps       AS DWORD   ' UINT
   VideoProcessorOperations AS DWORD   ' UINT
   NoiseFilterTechnology    AS DWORD   ' UINT
   DetailFilterTechnology   AS DWORD   ' UINT
END TYPE

'#ifdef __midl
'typedef LONG DXVA2_Fixed32;

'#else
'typedef struct _DXVA2_Fixed32
'{
'    union {
'        struct {
'            USHORT  Fraction;
'            SHORT   Value;
'        };
'        LONG ll;
'    };
'} DXVA2_Fixed32;
'#endif

' // Size = 4 bytes
TYPE DXVA2_Fixed32_STRUCT WORD
   Fraction AS WORD   ' USHORT
   Value    AS INTEGER   ' SHORT
END TYPE

' // Size = 4 bytes
UNION DXVA2_Fixed32 WORD
   DXVA2_Fixed32_STRUCT
   ll AS LONG   ' LONG
END UNION

' // Size = 4 bytes
TYPE DXVA2_AYUVSample8 BYTE
   Cr    AS BYTE   ' UCHAR
   Cb    AS BYTE   ' UCHAR
   Y     AS BYTE   ' UCHAR
   Alpha AS BYTE   ' UCHAR
END TYPE

' // Size = 8 bytes
TYPE DXVA2_AYUVSample16 WORD
   Cr    AS WORD   ' USHORT
   Cb    AS WORD   ' USHORT
   Y     AS WORD   ' USHORT
   Alpha AS WORD   ' USHORT
END TYPE

'typedef LONGLONG REFERENCE_TIME;

'#if defined(_D3D9_H_) || defined(_d3d9P_H_)
' // Size = 128 bytes
TYPE DXVA2_VideoSample DWORD
   Start        AS QUAD                   ' REFERENCE_TIME
   rtEnd        AS QUAD                   ' REFERENCE_TIME
   SampleFormat AS DXVA2_ExtendedFormat
   SrcSurface   AS DWORD PTR              ' IDirect3DSurface9
   SrcRect      AS RECT
   DstRect      AS RECT
   Pal(15)      AS DXVA2_AYUVSample8
   PlanarAlpha  AS DXVA2_Fixed32
   SampleData   AS DWORD                  ' DWORD
END TYPE
'#endif  // _D3D9_H_

' // Size = 16 bytes
TYPE DXVA2_ValueRange DWORD
   MinValue     AS DXVA2_Fixed32
   MaxValue     AS DXVA2_Fixed32
   DefaultValue AS DXVA2_Fixed32
   StepSize     AS DXVA2_Fixed32
END TYPE

' // Size = 16 bytes
TYPE DXVA2_ProcAmpValues DWORD
   Brightness AS DXVA2_Fixed32
   Contrast   AS DXVA2_Fixed32
   Hue        AS DXVA2_Fixed32
   Saturation AS DXVA2_Fixed32
END TYPE

' // Size = 12 bytes
TYPE DXVA2_FilterValues DWORD
   Level     AS DXVA2_Fixed32
   Threshold AS DXVA2_Fixed32
   Radius    AS DXVA2_Fixed32
END TYPE

' // Size = 120 bytes
TYPE DXVA2_VideoProcessBltParams DWORD
   TargetFrame        AS QUAD                   ' REFERENCE_TIME
   TargetRect         AS RECT
   ConstrictionSize   AS SIZE                   ' SIZE
   StreamingFlags     AS DWORD                  ' UINT
   BackgroundColor    AS DXVA2_AYUVSample16
   DestFormat         AS DXVA2_ExtendedFormat
   ProcAmpValues      AS DXVA2_ProcAmpValues
   Alpha              AS DXVA2_Fixed32
   NoiseFilterLuma    AS DXVA2_FilterValues
   NoiseFilterChroma  AS DXVA2_FilterValues
   DetailFilterLuma   AS DXVA2_FilterValues
   DetailFilterChroma AS DXVA2_FilterValues
   DestData           AS DWORD                  ' DWORD
END TYPE

' enum __MIDL___MIDL_itf_dxva2api_0000_0000_0012
%DXVA2_PictureParametersBufferType         = 0
%DXVA2_MacroBlockControlBufferType         = 1
%DXVA2_ResidualDifferenceBufferType        = 2
%DXVA2_DeblockingControlBufferType         = 3
%DXVA2_InverseQuantizationMatrixBufferType = 4
%DXVA2_SliceControlBufferType              = 5
%DXVA2_BitStreamDateBufferType             = 6
%DXVA2_MotionVectorBuffer                  = 7
%DXVA2_FilmGrainBuffer                     = 8

' enum __MIDL___MIDL_itf_dxva2api_0000_0000_0013
%DXVA2_VideoDecoderRenderTarget   = 0
%DXVA2_VideoProcessorRenderTarget = 1
%DXVA2_VideoSoftwareRenderTarget  = 2

' // Size = 120 bytes
TYPE DXVA2_ConfigPictureDecode DWORD FILL
   guidConfigBitstreamEncryption  AS GUID    ' GUID
   guidConfigMBcontrolEncryption  AS GUID    ' GUID
   guidConfigResidDiffEncryption  AS GUID    ' GUID
   ConfigBitstreamRaw             AS DWORD   ' UINT
   ConfigMBcontrolRasterOrder     AS DWORD   ' UINT
   ConfigResidDiffHost            AS DWORD   ' UINT
   ConfigSpatialResid8            AS DWORD   ' UINT
   ConfigResid8Subtraction        AS DWORD   ' UINT
   ConfigSpatialHost8or9Clipping  AS DWORD   ' UINT
   ConfigSpatialResidInterleaved  AS DWORD   ' UINT
   ConfigIntraResidUnsigned       AS DWORD   ' UINT
   ConfigResidDiffAccelerator     AS DWORD   ' UINT
   ConfigHostInverseScan          AS DWORD   ' UINT
   ConfigSpecificIDCT             AS DWORD   ' UINT
   Config4GroupedCoefs            AS DWORD   ' UINT
   ConfigMinRenderTargetBuffCount AS WORD    ' USHORT
   ConfigDecoderSpecific          AS WORD    ' USHORT
END TYPE

' // Size = 44 bytes
TYPE DXVA2_DecodeBufferDesc DWORD
   CompressedBufferType AS DWORD   ' DWORD
   BufferIndex          AS DWORD   ' UINT
   DataOffset           AS DWORD   ' UINT
   DataSize             AS DWORD   ' UINT
   FirstMBaddress       AS DWORD   ' UINT
   NumMBsInBuffer       AS DWORD   ' UINT
   Width                AS DWORD   ' UINT
   Height               AS DWORD   ' UINT
   Stride               AS DWORD   ' UINT
   ReservedBits         AS DWORD   ' UINT
   pvPVPState           AS DWORD   ' PVOID
END TYPE

'// The value in pvPVPState depends on the type of crypo used.  For
'// D3DCRYPTOTYPE_AES128_CTR, pvPState points to the following structure:

' // Size = 16 bytes
TYPE DXVA2_AES_CTR_IV QWORD
   IV    AS QUAD   ' UINT64
   Count AS QUAD   ' UINT64
END TYPE

' // Size = 20 bytes
TYPE DXVA2_DecodeExtensionData DWORD
   Function              AS DWORD   ' UINT
   pPrivateInputData     AS DWORD   ' PVOID
   PrivateInputDataSize  AS DWORD   ' UINT
   pPrivateOutputData    AS DWORD   ' PVOID
   PrivateOutputDataSize AS DWORD   ' UINT
END TYPE

'// DXVA2_DECODE_GET_DRIVER_HANDLE is an extension function that allows the
'// driver to return a handle for the DXVA2 decode device that can be used to
'// associate it with a IDirect3DCryptoSession9 interface.  When this function
'// is used:
'//     pPrivateInputData = NULL
'//     pPrivateInputDataSize = 0
'//     pPrivateOutputData = HANDLE*
'//     pPrivateOutputDataSize = sizeof(HANDLE)
%DXVA2_DECODE_GET_DRIVER_HANDLE = &H725

'// DXVA2_DECODE_SPECIFY_ENCRYPTED_BLOCKS is an extension function that that allows
'// the decoder to specify which portions of the compressed buffers are encrypted.
'// If this fucntion is not used to specify this information, it is assumed that
'// the entire buffer is encrypted.
'//     pPrivateInputData = D3DENCRYPTED_BLOCK_INFO*;
'//     PrivateInputDataSize = sizeof(D3DENCRYPTED_BLOCK_INFO);
'//     pPrivateOutputData = NULL;
'//     PrivateOutputDataSize = 0;
%DXVA2_DECODE_SPECIFY_ENCRYPTED_BLOCKS = &H724

' // Size = 12 bytes
TYPE DXVA2_DecodeExecuteParams DWORD
   NumCompBuffers     AS DWORD                           ' UINT
   pCompressedBuffers AS DXVA2_DecodeBufferDesc PTR      ' DXVA2_DecodeBufferDesc*
   pExtensionData     AS DXVA2_DecodeExtensionData PTR   ' DXVA2_DecodeExtensionData*
END TYPE

'#if defined(_D3D9_H_) || defined(_d3d9P_H_)


' ########################################################################################
' Interface name = IDirect3DDeviceManager9
' IID = a0cade0f-06d5-4cf4-a1c7-f3cdd725aa75
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDirect3DDeviceManager9_INTERFACE_DEFINED)
    %IDirect3DDeviceManager9_INTERFACE_DEFINED = 1

INTERFACE IDirect3DDeviceManager9 $IID_IDirect3DDeviceManager9

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ResetDevice ( _                               ' VTable offset = 12
     BYVAL pDevice AS IDirect3DDevice9 _                ' __in IDirect3DDevice9 *pDevice
   , BYVAL resetToken AS DWORD _                        ' __in UINT resetToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenDeviceHandle ( _                          ' VTable offset = 16
     BYREF phDevice AS DWORD _                          ' __out HANDLE *phDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloseDeviceHandle ( _                         ' VTable offset = 20
     BYVAL hDevice AS DWORD _                           ' __in HANDLE hDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TestDevice ( _                                ' VTable offset = 24
     BYVAL hDevice AS DWORD _                           ' __in HANDLE hDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockDevice ( _                                ' VTable offset = 28
     BYVAL hDevice AS DWORD _                           ' __in HANDLE hDevice
   , BYREF ppDevice AS IDirect3DDevice9 _               ' __out IDirect3DDevice9 **ppDevice
   , BYVAL fBlock AS LONG _                             ' __in BOOL fBlock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockDevice ( _                              ' VTable offset = 32
     BYVAL hDevice AS DWORD _                           ' __in HANDLE hDevice
   , BYVAL fSaveState AS LONG _                         ' __in BOOL fSaveState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoService ( _                           ' VTable offset = 36
     BYVAL hDevice AS DWORD _                           ' __in HANDLE hDevice
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppService AS IUnknown _                      ' __out void **ppService
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDirect3DDeviceManager9_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDirectXVideoAccelerationService
' IID = fc51a550-d5e7-11d9-af55-00054e43ff02
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDirectXVideoAccelerationService_INTERFACE_DEFINED)
    %IDirectXVideoAccelerationService_INTERFACE_DEFINED = 1

INTERFACE IDirectXVideoAccelerationService $IID_IDirectXVideoAccelerationService

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateSurface ( _                             ' VTable offset = 12
     BYVAL Width AS DWORD _                             ' __in UINT Width
   , BYVAL Height AS DWORD _                            ' __in UINT Height
   , BYVAL BackBuffers AS DWORD _                       ' __in UINT BackBuffers
   , BYVAL Format AS DWORD _                            ' __in D3DFORMAT Format
   , BYVAL Pool AS DWORD _                              ' __in D3DPOOL Pool
   , BYVAL Usage AS DWORD _                             ' __in DWORD Usage
   , BYVAL DxvaType AS DWORD _                          ' __in DWORD DxvaType
   , BYREF ppSurface AS IDirect3DSurface9 _             ' __out IDirect3DSurface9 **ppSurface
   , BYREF pSharedHandle AS DWORD _                     ' __inout HANDLE *pSharedHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDirectXVideoAccelerationService_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDirectXVideoDecoderService
' IID = fc51a551-d5e7-11d9-af55-00054e43ff02
' Inherited interface = IDirectXVideoAccelerationService
' ########################################################################################

#IF NOT %DEF(%IDirectXVideoDecoderService_INTERFACE_DEFINED)
    %IDirectXVideoDecoderService_INTERFACE_DEFINED = 1

INTERFACE IDirectXVideoDecoderService $IID_IDirectXVideoDecoderService

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirectXVideoAccelerationService method
   ' =====================================================================================
   METHOD CreateSurface ( _                             ' VTable offset = 12
     BYVAL Width AS DWORD _                             ' __in UINT Width
   , BYVAL Height AS DWORD _                            ' __in UINT Height
   , BYVAL BackBuffers AS DWORD _                       ' __in UINT BackBuffers
   , BYVAL Format AS DWORD _                            ' __in D3DFORMAT Format
   , BYVAL Pool AS DWORD _                              ' __in D3DPOOL Pool
   , BYVAL Usage AS DWORD _                             ' __in DWORD Usage
   , BYVAL DxvaType AS DWORD _                          ' __in DWORD DxvaType
   , BYREF ppSurface AS IDirect3DSurface9 _             ' __out IDirect3DSurface9 **ppSurface
   , BYREF pSharedHandle AS DWORD _                     ' __inout HANDLE *pSharedHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectXVideoDecoderService methods
   ' =====================================================================================
   METHOD GetDecoderDeviceGuids ( _                     ' VTable offset = 16
     BYREF pCount AS DWORD _                            ' __out UINT *pCount
   , BYREF pGuids AS GUID _                             ' __out GUID **pGuids
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDecoderRenderTargets ( _                   ' VTable offset = 20
     BYREF Guid AS GUID _                               ' __in REFGUID Guid
   , BYREF pCount AS DWORD _                            ' __out UINT *pCount
   , BYREF pFormats AS DWORD _                          ' __out D3DFORMAT **pFormats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDecoderConfigurations ( _                  ' VTable offset = 24
     BYREF Guid AS GUID _                               ' __in REFGUID Guid
   , BYREF pVideoDesc AS DXVA2_VideoDesc _              ' __in DXVA2_VideoDesc *pVideoDesc
   , BYVAL pReserved AS DWORD _                         ' __in void *pReserved
   , BYREF pCount AS DWORD _                            ' __out UINT *pCount
   , BYREF ppConfigs AS DXVA2_ConfigPictureDecode _     ' __out DXVA2_ConfigPictureDecode **ppConfigs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateVideoDecoder ( _                        ' VTable offset = 28
     BYREF Guid AS GUID _                               ' __in REFGUID Guid
   , BYREF pVideoDesc AS DXVA2_VideoDesc _              ' __in DXVA2_VideoDesc *pVideoDesc
   , BYREF pConfig AS DXVA2_ConfigPictureDecode _       ' __in const DXVA2_ConfigPictureDecode *pConfig
   , BYREF ppDecoderRenderTargets AS IDirect3DSurface9 _ ' __in IDirect3DSurface9 **ppDecoderRenderTargets
   , BYVAL NumRenderTargets AS DWORD _                  ' __in UINT NumRenderTargets
   , BYREF ppDecode AS IUnknown _                       ' __out **ppDecode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDirectXVideoDecoderService_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDirectXVideoProcessorService
' IID = fc51a552-d5e7-11d9-af55-00054e43ff02
' Inherited interface = IDirectXVideoAccelerationService
' ########################################################################################

#IF NOT %DEF(%IDirectXVideoProcessorService_INTERFACE_DEFINED)
    %IDirectXVideoProcessorService_INTERFACE_DEFINED = 1

INTERFACE IDirectXVideoProcessorService $IID_IDirectXVideoProcessorService

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirectXVideoAccelerationService method
   ' =====================================================================================
   METHOD CreateSurface ( _                             ' VTable offset = 12
     BYVAL Width AS DWORD _                             ' __in UINT Width
   , BYVAL Height AS DWORD _                            ' __in UINT Height
   , BYVAL BackBuffers AS DWORD _                       ' __in UINT BackBuffers
   , BYVAL Format AS DWORD _                            ' __in D3DFORMAT Format
   , BYVAL Pool AS DWORD _                              ' __in D3DPOOL Pool
   , BYVAL Usage AS DWORD _                             ' __in DWORD Usage
   , BYVAL DxvaType AS DWORD _                          ' __in DWORD DxvaType
   , BYREF ppSurface AS IDirect3DSurface9 _             ' __out IDirect3DSurface9 **ppSurface
   , BYREF pSharedHandle AS DWORD _                     ' __inout HANDLE *pSharedHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectXVideoProcessorService methods
   ' =====================================================================================
   METHOD RegisterVideoProcessorSoftwareDevice ( _      ' VTable offset = 16
     BYVAL pCallbacks AS DWORD _                        ' __in void *pCallbacks
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoProcessorDeviceGuids ( _              ' VTable offset = 20
     BYREF pVideoDesc AS DXVA2_VideoDesc _              ' __in const DXVA2_VideoDesc *pVideoDesc
   , BYREF pCount AS DWORD _                            ' __out UINT *pCount
   , BYREF pGuids AS GUID _                             ' __out GUID **pGuids
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoProcessorRenderTargets ( _            ' VTable offset = 24
     BYREF VideoProcDeviceGuid AS GUID _                ' __in REFGUID VideoProcDeviceGuid
   , BYREF pVideoDesc AS DXVA2_VideoDesc _              ' __in const DXVA2_VideoDesc *pVideoDesc
   , BYREF pCount AS DWORD _                            ' __out UINT *pCount
   , BYREF pFormats AS DWORD _                          ' __out D3DFORMAT **pFormats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoProcessorSubStreamFormats ( _         ' VTable offset = 28
     BYREF VideoProcDeviceGuid AS GUID _                ' __in REFGUID VideoProcDeviceGuid
   , BYREF pVideoDesc AS DXVA2_VideoDesc _              ' __in const DXVA2_VideoDesc *pVideoDesc
   , BYVAL RenderTargetFormat AS DWORD _                ' __in D3DFORMAT RenderTargetFormat
   , BYREF pCount AS DWORD _                            ' __out UINT *pCount
   , BYREF pFormats AS DWORD _                          ' __out D3DFORMAT **pFormats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoProcessorCaps ( _                     ' VTable offset = 32
     BYREF VideoProcDeviceGuid AS GUID _                ' __in REFGUID VideoProcDeviceGuid
   , BYREF pVideoDesc AS DXVA2_VideoDesc _              ' __in const DXVA2_VideoDesc *pVideoDesc
   , BYVAL RenderTargetFormat AS DWORD _                ' __in D3DFORMAT RenderTargetFormat
   , BYREF pCaps AS DXVA2_VideoProcessorCaps _          ' __out DXVA2_VideoProcessorCaps *pCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProcAmpRange ( _                           ' VTable offset = 36
     BYREF VideoProcDeviceGuid AS GUID _                ' __in REFGUID VideoProcDeviceGuid
   , BYREF pVideoDesc AS DXVA2_VideoDesc _              ' __in const DXVA2_VideoDesc *pVideoDesc
   , BYVAL RenderTargetFormat AS DWORD _                ' __in D3DFORMAT RenderTargetFormat
   , BYVAL ProcAmpCap AS DWORD _                        ' __in UINT ProcAmpCap
   , BYREF pRange AS DXVA2_ValueRange _                 ' __out DXVA2_ValueRange *pRange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFilterPropertyRange ( _                    ' VTable offset = 40
     BYREF VideoProcDeviceGuid AS GUID _                ' __in REFGUID VideoProcDeviceGuid
   , BYREF pVideoDesc AS DXVA2_VideoDesc _              ' __in const DXVA2_VideoDesc *pVideoDesc
   , BYVAL RenderTargetFormat AS DWORD _                ' __in D3DFORMAT RenderTargetFormat
   , BYVAL FilterSetting AS DWORD _                     ' __in UINT FilterSetting
   , BYREF pRange AS DXVA2_ValueRange _                 ' __out DXVA2_ValueRange *pRange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateVideoProcessor ( _                      ' VTable offset = 44
     BYREF VideoProcDeviceGuid AS GUID _                ' __in REFGUID VideoProcDeviceGuid
   , BYREF pVideoDesc AS DXVA2_VideoDesc _              ' __in const DXVA2_VideoDesc *pVideoDesc
   , BYVAL RenderTargetFormat AS DWORD _                ' __in D3DFORMAT RenderTargetFormat
   , BYVAL MaxNumSubStreams AS DWORD _                  ' __in UINT MaxNumSubStreams
   , BYREF ppVidProcess AS IDirectXVideoProcessor _     ' __out IDirectXVideoProcessor **ppVidProcess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDirectXVideoProcessorService_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDirectXVideoDecoder
' IID = f2b0810a-fd00-43c9-918c-df94e2d8ef7d
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDirectXVideoDecoder_INTERFACE_DEFINED)
    %IDirectXVideoDecoder_INTERFACE_DEFINED = 1

INTERFACE IDirectXVideoDecoder $IID_IDirectXVideoDecoder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetVideoDecoderService ( _                    ' VTable offset = 12
     BYREF ppService AS IDirectXVideoDecoderService _   ' __out IDirectXVideoDecoderService **ppService
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCreationParameters ( _                     ' VTable offset = 16
     BYREF pDeviceGuid AS GUID _                        ' __out GUID *pDeviceGuid
   , BYREF pVideoDesc AS DXVA2_VideoDesc _              ' __out DXVA2_VideoDesc *pVideoDesc
   , BYREF pConfig AS DXVA2_ConfigPictureDecode _       ' __out DXVA2_ConfigPictureDecode *pConfig
   , BYREF pDecoderRenderTargets AS IDirect3DSurface9 _ ' __out IDirect3DSurface9 ***pDecoderRenderTargets
   , BYREF pNumSurfaces AS DWORD _                      ' __out UINT *pNumSurfaces
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBuffer ( _                                 ' VTable offset = 20
     BYVAL BufferType AS DWORD _                        ' __in UINT BufferType
   , BYREF ppBuffer AS DWORD _                          ' __out void **ppBuffer
   , BYREF pBufferSize AS DWORD _                       ' __out UINT *pBufferSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseBuffer ( _                             ' VTable offset = 24
     BYVAL BufferType AS DWORD _                        ' __in UINT BufferType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginFrame ( _                                ' VTable offset = 28
     BYVAL pRenderTarget AS IDirect3DSurface9 _         ' __in IDirect3DSurface9 *pRenderTarget
   , BYVAL pvPVPData AS DWORD _                         ' __in void *pvPVPData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndFrame ( _                                  ' VTable offset = 32
     BYREF pHandleComplete AS DWORD _                   ' __out HANDLE *pHandleComplete
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Execute ( _                                   ' VTable offset = 36
     BYREF pExecuteParams AS DXVA2_DecodeExecuteParams _ ' __in const DXVA2_DecodeExecuteParams *pExecuteParams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDirectXVideoDecoder_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDirectXVideoProcessor
' IID = 8c3a39f0-916e-4690-804f-4c8001355d25
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDirectXVideoProcessor_INTERFACE_DEFINED)
    %IDirectXVideoProcessor_INTERFACE_DEFINED = 1

INTERFACE IDirectXVideoProcessor $IID_IDirectXVideoProcessor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetVideoProcessorService ( _                  ' VTable offset = 12
     BYREF ppService AS IDirectXVideoProcessorService _ ' __out IDirectXVideoProcessorService **ppService
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCreationParameters ( _                     ' VTable offset = 16
     BYREF pDeviceGuid AS GUID _                        ' __out GUID *pDeviceGuid
   , BYREF pVideoDesc AS DXVA2_VideoDesc _              ' __out DXVA2_VideoDesc *pVideoDesc
   , BYREF pRenderTargetFormat AS DWORD _               ' __out D3DFORMAT *pRenderTargetFormat
   , BYREF pMaxNumSubStreams AS DWORD _                 ' __out UINT *pMaxNumSubStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoProcessorCaps ( _                     ' VTable offset = 20
     BYREF pCaps AS DXVA2_VideoProcessorCaps _          ' __out DXVA2_VideoProcessorCaps *pCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProcAmpRange ( _                           ' VTable offset = 24
     BYVAL ProcAmpCap AS DWORD _                        ' __in UINT ProcAmpCap
   , BYREF pRange AS DXVA2_ValueRange _                 ' __out DXVA2_ValueRange *pRange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFilterPropertyRange ( _                    ' VTable offset = 28
     BYVAL FilterSetting AS DWORD _                     ' __in UINT FilterSetting
   , BYREF pRange AS DXVA2_ValueRange _                 ' __out DXVA2_ValueRange *pRange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD VideoProcessBlt ( _                           ' VTable offset = 32
     BYVAL pRenderTarget AS IDirect3DSurface9 _         ' __in IDirect3DSurface9 *pRenderTarget
   , BYREF pBltParams AS DXVA2_VideoProcessBltParams _  ' __in const DXVA2_VideoProcessBltParams *pBltParams
   , BYREF pSamples AS DXVA2_VideoSample _              ' __in const DXVA2_VideoSample *pSamples
   , BYVAL NumSamples AS DWORD _                        ' __in UINT NumSamples
   , BYREF pHandleComplete AS DWORD _                   ' __out HANDLE *pHandleComplete
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDirectXVideoProcessor_INTERFACE_DEFINED__ */


' enum DXVA2_SurfaceType
%DXVA2_SurfaceType_DecoderRenderTarget    = 0
%DXVA2_SurfaceType_ProcessorRenderTarget  = 1
%DXVA2_SurfaceType_D3DRenderTargetTexture = 2


' ########################################################################################
' Interface name = IDirectXVideoMemoryConfiguration
' IID = b7f916dd-db3b-49c1-84d7-e45ef99ec726
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDirectXVideoMemoryConfiguration_INTERFACE_DEFINED)
    %IDirectXVideoMemoryConfiguration_INTERFACE_DEFINED = 1

INTERFACE IDirectXVideoMemoryConfiguration $IID_IDirectXVideoMemoryConfiguration

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAvailableSurfaceTypeByIndex ( _            ' VTable offset = 12
     BYVAL dwTypeIndex AS DWORD _                       ' __in DWORD dwTypeIndex
   , BYREF pdwType AS LONG _                            ' __out DXVA2_SurfaceType *pdwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSurfaceType ( _                            ' VTable offset = 16
     BYREF dwType AS LONG _                             ' __in DXVA2_SurfaceType dwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDirectXVideoMemoryConfiguration_INTERFACE_DEFINED__ */


DECLARE FUNCTION DXVA2CreateDirect3DDeviceManager9 IMPORT "dxva2.dll" ALIAS "DXVA2CreateDirect3DDeviceManager9" ( _
   BYREF pResetToken AS DWORD _                         ' __out UINT* pResetToken
 , BYREF ppDeviceManager AS IDirect3DDeviceManager9 _   ' __deref_out IDirect3DDeviceManager9** ppDeviceManager
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DXVA2CreateVideoService IMPORT "dxva2.dll" ALIAS "DXVA2CreateVideoService" ( _
   BYVAL pDD AS IDirect3DDevice9 _                      ' __in IDirect3DDevice9* pDD
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppService AS IUnknown _                        ' __deref_out void** ppService
 ) AS LONG                                              ' HRESULT

'#endif  // _D3D9_H_

'__inline DXVA2_Fixed32 DXVA2FloatToFixed(__in const float _float_)
'{
'    DXVA2_Fixed32 _fixed_;
'    _fixed_.Fraction = LOWORD(_float_ * 0x10000);
'    _fixed_.Value = HIWORD(_float_ * 0x10000);
'    return _fixed_;
'}

SUB DXVA2FloatToFixed (BYREF xfixed AS DXVA2_Fixed32, BYVAL xfloat AS SINGLE)
   xfixed.Fraction = LO(WORD, xfloat * &H10000)
   xfixed.Value = HI(WORD, xfloat * 10000)
END SUB

'__inline float DXVA2FixedToFloat(__in const DXVA2_Fixed32 _fixed_)
'{
'    return (FLOAT)_fixed_.Value + (FLOAT)_fixed_.Fraction / 0x10000;
'}

FUNCTION DXVA2FixedToFloat (BYREF xfixed AS DXVA2_Fixed32) AS SINGLE
   FUNCTION = xfixed.Value + xfixed.Fraction / &H10000
END FUNCTION

'__inline const DXVA2_Fixed32 DXVA2_Fixed32TransparentAlpha()
'{
'    DXVA2_Fixed32 _fixed_ = {0, 0};
'    return _fixed_;
'}

SUB DXVA2_Fixed32TransparentAlpha (BYREF xfixed AS DXVA2_Fixed32)
   xfixed.Fraction = 0
   xfixed.Value = 0
END SUB

'__inline const DXVA2_Fixed32 DXVA2_Fixed32OpaqueAlpha()
'{
'    DXVA2_Fixed32 _fixed_ = {0, 1};
'    return _fixed_;
'}

SUB DXVA2_Fixed32OpaqueAlpha (BYREF xfixed AS DXVA2_Fixed32)
   xfixed.Fraction = 0
   xfixed.Value = 1
END SUB

'#endif
