' ########################################################################################
' Microsoft Windows
' File: d3d9caps.inc
' Contents: Direct3D capabilities include file
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3D9CAPS_INC = 1

#IF NOT %DEF(%DIRECT3D_VERSION)
%DIRECT3D_VERSION = &H0900
#ENDIF

'// include this file content only if compiling for DX9 interfaces
'#if(DIRECT3D_VERSION >= 0x0900)

'#if defined(_X86_) || defined(_IA64_)
'#pragma pack(4)
'#endif

' // Size = 16 bytes
TYPE D3DVSHADERCAPS2_0 DWORD
   Caps                    AS DWORD
   DynamicFlowControlDepth AS LONG
   NumTemps                AS LONG
   StaticFlowControlDepth  AS LONG
END TYPE

%D3DVS20CAPS_PREDICATION   = 1    ' (1<<0)

%D3DVS20_MAX_DYNAMICFLOWCONTROLDEPTH = 24
%D3DVS20_MIN_DYNAMICFLOWCONTROLDEPTH = 0
%D3DVS20_MAX_NUMTEMPS                = 32
%D3DVS20_MIN_NUMTEMPS                = 12
%D3DVS20_MAX_STATICFLOWCONTROLDEPTH  = 4
%D3DVS20_MIN_STATICFLOWCONTROLDEPTH  = 1

' // Size = 20 bytes
TYPE D3DPSHADERCAPS2_0 DWORD
   Caps                    AS DWORD
   DynamicFlowControlDepth AS LONG
   NumTemps                AS LONG
   StaticFlowControlDepth  AS LONG
   NumInstructionSlots     AS LONG
END TYPE

%D3DPS20CAPS_ARBITRARYSWIZZLE        = 1       '  (1<<0)
%D3DPS20CAPS_GRADIENTINSTRUCTIONS    = 2       '  (1<<1)
%D3DPS20CAPS_PREDICATION             = 4       '  (1<<2)
%D3DPS20CAPS_NODEPENDENTREADLIMIT    = 8       '  (1<<3)
%D3DPS20CAPS_NOTEXINSTRUCTIONLIMIT   = 16      '  (1<<4)

%D3DPS20_MAX_DYNAMICFLOWCONTROLDEPTH = 24
%D3DPS20_MIN_DYNAMICFLOWCONTROLDEPTH = 0
%D3DPS20_MAX_NUMTEMPS                = 32
%D3DPS20_MIN_NUMTEMPS                = 12
%D3DPS20_MAX_STATICFLOWCONTROLDEPTH  = 4
%D3DPS20_MIN_STATICFLOWCONTROLDEPTH  = 0
%D3DPS20_MAX_NUMINSTRUCTIONSLOTS     = 512
%D3DPS20_MIN_NUMINSTRUCTIONSLOTS     = 96

%D3DMIN30SHADERINSTRUCTIONS          = 512
%D3DMAX30SHADERINSTRUCTIONS          = 32768

' // Size = 12 bytes
TYPE D3DOVERLAYCAPS DWORD
   Caps                    AS DWORD   ' UINT
   MaxOverlayDisplayWidth  AS DWORD   ' UINT
   MaxOverlayDisplayHeight AS DWORD   ' UINT
END TYPE

%D3DOVERLAYCAPS_FULLRANGERGB          = &H00000001???
%D3DOVERLAYCAPS_LIMITEDRANGERGB       = &H00000002???
%D3DOVERLAYCAPS_YCbCr_BT601           = &H00000004???
%D3DOVERLAYCAPS_YCbCr_BT709           = &H00000008???
%D3DOVERLAYCAPS_YCbCr_BT601_xvYCC     = &H00000010???
%D3DOVERLAYCAPS_YCbCr_BT709_xvYCC     = &H00000020???
%D3DOVERLAYCAPS_STRETCHX              = &H00000040???
%D3DOVERLAYCAPS_STRETCHY              = &H00000080???

' // Size = 36 bytes
TYPE D3DCONTENTPROTECTIONCAPS DWORD
   Caps                 AS DWORD   ' DWORD
   KeyExchangeType      AS GUID    ' GUID
   BufferAlignmentStart AS DWORD   ' UINT
   BlockAlignmentSize   AS DWORD   ' UINT
   ProtectedMemorySize  AS QUAD    ' ULONGLONG
END TYPE

%D3DCPCAPS_SOFTWARE              = &H00000001???
%D3DCPCAPS_HARDWARE              = &H00000002???
%D3DCPCAPS_PROTECTIONALWAYSON    = &H00000004???
%D3DCPCAPS_PARTIALDECRYPTION     = &H00000008???
%D3DCPCAPS_CONTENTKEY            = &H00000010???
%D3DCPCAPS_FRESHENSESSIONKEY     = &H00000020???
%D3DCPCAPS_ENCRYPTEDREADBACK     = &H00000040???
%D3DCPCAPS_ENCRYPTEDREADBACKKEY  = &H00000080???
%D3DCPCAPS_SEQUENTIAL_CTR_IV     = &H00000100???
%D3DCPCAPS_ENCRYPTSLICEDATAONLY  = &H00000200???

$D3DCRYPTOTYPE_AES128_CTR = GUID$("{9B6BD711-4F74-41C9-9E7B-0BE2D7D93B4F}")
$D3DCRYPTOTYPE_PROPRIETARY = GUID$("{AB4E9AFD-1D1C-46E6-A72F-0869917B0DE8}")
$D3DKEYEXCHANGE_RSAES_OAEP = GUID$("{C1949895-D72A-4A1D-8E5D-ED857D171520}")
$D3DKEYEXCHANGE_DXVA = GUID$("{43D3775C-38E5-4924-8D86-D3FCCF153E9B}")

' // Size = 300 bytes
TYPE D3DCAPS9 DWORD
   ' /* Device Info */
   DeviceType                        AS DWORD
   AdapterOrdinal                    AS DWORD
   ' /* Caps from DX7 Draw */
   Caps                              AS DWORD
   Caps2                             AS DWORD
   Caps3                             AS DWORD
   PresentationIntervals             AS DWORD
   ' /* Cursor Caps */
   CursorCaps                        AS DWORD
   ' /* 3D Device Caps */
   DevCaps                           AS DWORD
   '
   PrimitiveMiscCaps                 AS DWORD
   RasterCaps                        AS DWORD
   ZCmpCaps                          AS DWORD
   SrcBlendCaps                      AS DWORD
   DestBlendCaps                     AS DWORD
   AlphaCmpCaps                      AS DWORD
   ShadeCaps                         AS DWORD
   TextureCaps                       AS DWORD
   TextureFilterCaps                 AS DWORD    ' // D3DPTFILTERCAPS for IDirect3DTexture9's
   CubeTextureFilterCaps             AS DWORD    ' // D3DPTFILTERCAPS for IDirect3DCubeTexture9's
   VolumeTextureFilterCaps           AS DWORD    ' // D3DPTFILTERCAPS for IDirect3DVolumeTexture9's
   TextureAddressCaps                AS DWORD    ' // D3DPTADDRESSCAPS for IDirect3DTexture9's
   VolumeTextureAddressCaps          AS DWORD    ' // D3DPTADDRESSCAPS for IDirect3DVolumeTexture9's
   LineCaps                          AS DWORD    ' // D3DLINECAPS
   MaxTextureWidth                   AS DWORD
   MaxTextureHeight                  AS DWORD
   MaxVolumeExtent                   AS DWORD
   MaxTextureRepeat                  AS DWORD
   MaxTextureAspectRatio             AS DWORD
   MaxAnisotropy                     AS DWORD
   MaxVertexW                        AS SINGLE
   GuardBandLeft                     AS SINGLE
   GuardBandTop                      AS SINGLE
   GuardBandRight                    AS SINGLE
   GuardBandBottom                   AS SINGLE
   ExtentsAdjust                     AS SINGLE
   StencilCaps                       AS DWORD
   FVFCaps                           AS DWORD
   TextureOpCaps                     AS DWORD
   MaxTextureBlendStages             AS DWORD
   MaxSimultaneousTextures           AS DWORD
   VertexProcessingCaps              AS DWORD
   MaxActiveLights                   AS DWORD
   MaxUserClipPlanes                 AS DWORD
   MaxVertexBlendMatrices            AS DWORD
   MaxVertexBlendMatrixIndex         AS DWORD
   MaxPointSize                      AS SINGLE
   MaxPrimitiveCount                 AS DWORD    ' // max number of primitives per DrawPrimitive call
   MaxVertexIndex                    AS DWORD
   MaxStreams                        AS DWORD
   MaxStreamStride                   AS DWORD    ' // max stride for SetStreamSource
   VertexShaderVersion               AS DWORD
   MaxVertexShaderConst              AS DWORD    ' // number of vertex shader constant registers
   PixelShaderVersion                AS DWORD
   PixelShader1xMaxValue             AS SINGLE   ' // max value storable in registers of ps.1.x shaders
   ' // Here are the DX9 specific ones
   DevCaps2                          AS DWORD
   MaxNpatchTessellationLevel        AS SINGLE
   Reserved5                         AS DWORD
   '
   MasterAdapterOrdinal              AS DWORD    ' // ordinal of master adaptor for adapter group
   AdapterOrdinalInGroup             AS DWORD    ' // ordinal inside the adapter group
   NumberOfAdaptersInGroup           AS DWORD    ' // number of adapters in this adapter group (only if master)
   DeclTypes                         AS DWORD    ' // Data types, supported in vertex declarations
   NumSimultaneousRTs                AS DWORD    ' // Will be at least 1
   StretchRectFilterCaps             AS DWORD    ' // Filter caps supported by StretchRect
   VS20Caps                          AS D3DVSHADERCAPS2_0
   PS20Caps                          AS D3DVSHADERCAPS2_0
   VertexTextureFilterCaps           AS DWORD    ' // D3DPTFILTERCAPS for IDirect3DTexture9's for texture, used in vertex shaders
   MaxVShaderInstructionsExecuted    AS DWORD    ' // maximum number of vertex shader instructions that can be executed
   MaxPShaderInstructionsExecuted    AS DWORD    ' // maximum number of pixel shader instructions that can be executed
   MaxVertexShader30InstructionSlots AS DWORD
   MaxPixelShader30InstructionSlots  AS DWORD
END TYPE

'//
'// BIT DEFINES FOR D3DCAPS9 DWORD MEMBERS
'//

'//
'// Caps
'//
%D3DCAPS_OVERLAY                  = &H00000800???
%D3DCAPS_READ_SCANLINE            = &H00020000???

'//
'// Caps2
'//
%D3DCAPS2_FULLSCREENGAMMA         = &H00020000???
%D3DCAPS2_CANCALIBRATEGAMMA       = &H00100000???
%D3DCAPS2_RESERVED                = &H02000000???
%D3DCAPS2_CANMANAGERESOURCE       = &H10000000???
%D3DCAPS2_DYNAMICTEXTURES         = &H20000000???
%D3DCAPS2_CANAUTOGENMIPMAP        = &H40000000???

'/* D3D9Ex only -- */
#IF NOT %DEF(%D3D_DISABLE_9EX)
%D3DCAPS2_CANSHARERESOURCE        = &H80000000???
#ENDIF   ' // !D3D_DISABLE_9EX
'/* -- D3D9Ex only */

'//
'// Caps3
'//
%D3DCAPS3_RESERVED                = &H8000001f???

'// Indicates that the device can respect the ALPHABLENDENABLE render state
'// when fullscreen while using the FLIP or DISCARD swap effect.
'// COPY and COPYVSYNC swap effects work whether or not this flag is set.
%D3DCAPS3_ALPHA_FULLSCREEN_FLIP_OR_DISCARD    = &H00000020???

'// Indicates that the device can perform a gamma correction from
'// a windowed back buffer containing linear content to the sRGB desktop.
%D3DCAPS3_LINEAR_TO_SRGB_PRESENTATION  = &H00000080???

%D3DCAPS3_COPY_TO_VIDMEM          = &H00000100???  ' /* Device can acclerate copies from sysmem to local vidmem */
%D3DCAPS3_COPY_TO_SYSTEMMEM       = &H00000200???  ' /* Device can acclerate copies from local vidmem to sysmem */
%D3DCAPS3_DXVAHD                  = &H00000400???


'//
'// PresentationIntervals
'//
%D3DPRESENT_INTERVAL_DEFAULT      = &H00000000???
%D3DPRESENT_INTERVAL_ONE          = &H00000001???
%D3DPRESENT_INTERVAL_TWO          = &H00000002???
%D3DPRESENT_INTERVAL_THREE        = &H00000004???
%D3DPRESENT_INTERVAL_FOUR         = &H00000008???
%D3DPRESENT_INTERVAL_IMMEDIATE    = &H80000000???

'//
'// CursorCaps
'//
'// Driver supports HW color cursor in at least hi-res modes(height >=400)
%D3DCURSORCAPS_COLOR              = &H00000001???
'// Driver supports HW cursor also in low-res modes(height < 400)
%D3DCURSORCAPS_LOWRES             = &H00000002???

'//
'// DevCaps
'//
%D3DDEVCAPS_EXECUTESYSTEMMEMORY     = &H00000010???   ' /* Device can use execute buffers from system memory */
%D3DDEVCAPS_EXECUTEVIDEOMEMORY      = &H00000020???   ' /* Device can use execute buffers from video memory */
%D3DDEVCAPS_TLVERTEXSYSTEMMEMORY    = &H00000040???   ' /* Device can use TL buffers from system memory */
%D3DDEVCAPS_TLVERTEXVIDEOMEMORY     = &H00000080???   ' /* Device can use TL buffers from video memory */
%D3DDEVCAPS_TEXTURESYSTEMMEMORY     = &H00000100???   ' /* Device can texture from system memory */
%D3DDEVCAPS_TEXTUREVIDEOMEMORY      = &H00000200???   ' /* Device can texture from device memory */
%D3DDEVCAPS_DRAWPRIMTLVERTEX        = &H00000400???   ' /* Device can draw TLVERTEX primitives */
%D3DDEVCAPS_CANRENDERAFTERFLIP      = &H00000800???   ' /* Device can render without waiting for flip to complete */
%D3DDEVCAPS_TEXTURENONLOCALVIDMEM   = &H00001000???   ' /* Device can texture from nonlocal video memory */
%D3DDEVCAPS_DRAWPRIMITIVES2         = &H00002000???   ' /* Device can support DrawPrimitives2 */
%D3DDEVCAPS_SEPARATETEXTUREMEMORIES = &H00004000???   ' /* Device is texturing from separate memory pools */
%D3DDEVCAPS_DRAWPRIMITIVES2EX       = &H00008000???   ' /* Device can support Extended DrawPrimitives2 i.e. DX7 compliant driver*/
%D3DDEVCAPS_HWTRANSFORMANDLIGHT     = &H00010000???   ' /* Device can support transformation and lighting in hardware and DRAWPRIMITIVES2EX must be also */
%D3DDEVCAPS_CANBLTSYSTONONLOCAL     = &H00020000???   ' /* Device supports a Tex Blt from system memory to non-local vidmem */
%D3DDEVCAPS_HWRASTERIZATION         = &H00080000???   ' /* Device has HW acceleration for rasterization */
%D3DDEVCAPS_PUREDEVICE              = &H00100000???   ' /* Device supports D3DCREATE_PUREDEVICE */
%D3DDEVCAPS_QUINTICRTPATCHES        = &H00200000???   ' /* Device supports quintic Beziers and BSplines */
%D3DDEVCAPS_RTPATCHES               = &H00400000???   ' /* Device supports Rect and Tri patches */
%D3DDEVCAPS_RTPATCHHANDLEZERO       = &H00800000???   ' /* Indicates that RT Patches may be drawn efficiently using handle 0 */
%D3DDEVCAPS_NPATCHES                = &H01000000???   ' /* Device supports N-Patches */

'//
'// PrimitiveMiscCaps
'//
%D3DPMISCCAPS_MASKZ                      = &H00000002???
%D3DPMISCCAPS_CULLNONE                   = &H00000010???
%D3DPMISCCAPS_CULLCW                     = &H00000020???
%D3DPMISCCAPS_CULLCCW                    = &H00000040???
%D3DPMISCCAPS_COLORWRITEENABLE           = &H00000080???
%D3DPMISCCAPS_CLIPPLANESCALEDPOINTS      = &H00000100???   ' /* Device correctly clips scaled points to clip planes */
%D3DPMISCCAPS_CLIPTLVERTS                = &H00000200???   ' /* device will clip post-transformed vertex primitives */
%D3DPMISCCAPS_TSSARGTEMP                 = &H00000400???   ' /* device supports D3DTA_TEMP for temporary register */
%D3DPMISCCAPS_BLENDOP                    = &H00000800???   ' /* device supports D3DRS_BLENDOP */
%D3DPMISCCAPS_NULLREFERENCE              = &H00001000???   ' /* Reference Device that doesnt render */
%D3DPMISCCAPS_INDEPENDENTWRITEMASKS      = &H00004000???   ' /* Device supports independent write masks for MET or MRT */
%D3DPMISCCAPS_PERSTAGECONSTANT           = &H00008000???   ' /* Device supports per-stage constants */
%D3DPMISCCAPS_FOGANDSPECULARALPHA        = &H00010000???   ' /* Device supports separate fog and specular alpha (many devices
                                                           ' use the specular alpha channel to store fog factor) */
%D3DPMISCCAPS_SEPARATEALPHABLEND         = &H00020000???   ' /* Device supports separate blend settings for the alpha channel */
%D3DPMISCCAPS_MRTINDEPENDENTBITDEPTHS    = &H00040000???   ' /* Device supports different bit depths for MRT */
%D3DPMISCCAPS_MRTPOSTPIXELSHADERBLENDING = &H00080000???   ' /* Device supports post-pixel shader operations for MRT */
%D3DPMISCCAPS_FOGVERTEXCLAMPED           = &H00100000???   ' /* Device clamps fog blend factor per vertex */

'/* D3D9Ex only -- */
#IF NOT %DEF(%D3D_DISABLE_9EX)
%D3DPMISCCAPS_POSTBLENDSRGBCONVERT       = &H00200000???   ' /* Indicates device can perform conversion to sRGB after blending. */
#ENDIF   ' // !D3D_DISABLE_9EX
'/* -- D3D9Ex only */

'//
'// LineCaps
'//
%D3DLINECAPS_TEXTURE              = &H00000001???
%D3DLINECAPS_ZTEST                = &H00000002???
%D3DLINECAPS_BLEND                = &H00000004???
%D3DLINECAPS_ALPHACMP             = &H00000008???
%D3DLINECAPS_FOG                  = &H00000010???
%D3DLINECAPS_ANTIALIAS            = &H00000020???

'//
'// RasterCaps
'//
%D3DPRASTERCAPS_DITHER                  = &H00000001???
%D3DPRASTERCAPS_ZTEST                   = &H00000010???
%D3DPRASTERCAPS_FOGVERTEX               = &H00000080???
%D3DPRASTERCAPS_FOGTABLE                = &H00000100???
%D3DPRASTERCAPS_MIPMAPLODBIAS           = &H00002000???
%D3DPRASTERCAPS_ZBUFFERLESSHSR          = &H00008000???
%D3DPRASTERCAPS_FOGRANGE                = &H00010000???
%D3DPRASTERCAPS_ANISOTROPY              = &H00020000???
%D3DPRASTERCAPS_WBUFFER                 = &H00040000???
%D3DPRASTERCAPS_WFOG                    = &H00100000???
%D3DPRASTERCAPS_ZFOG                    = &H00200000???
%D3DPRASTERCAPS_COLORPERSPECTIVE        = &H00400000???  ' /* Device iterates colors perspective correct */
%D3DPRASTERCAPS_SCISSORTEST             = &H01000000???
%D3DPRASTERCAPS_SLOPESCALEDEPTHBIAS     = &H02000000???
%D3DPRASTERCAPS_DEPTHBIAS               = &H04000000???
%D3DPRASTERCAPS_MULTISAMPLE_TOGGLE      = &H08000000???

'//
'// ZCmpCaps, AlphaCmpCaps
'//
%D3DPCMPCAPS_NEVER                = &H00000001???
%D3DPCMPCAPS_LESS                 = &H00000002???
%D3DPCMPCAPS_EQUAL                = &H00000004???
%D3DPCMPCAPS_LESSEQUAL            = &H00000008???
%D3DPCMPCAPS_GREATER              = &H00000010???
%D3DPCMPCAPS_NOTEQUAL             = &H00000020???
%D3DPCMPCAPS_GREATEREQUAL         = &H00000040???
%D3DPCMPCAPS_ALWAYS               = &H00000080???

'//
'// SourceBlendCaps, DestBlendCaps
'//
%D3DPBLENDCAPS_ZERO               = &H00000001???
%D3DPBLENDCAPS_ONE                = &H00000002???
%D3DPBLENDCAPS_SRCCOLOR           = &H00000004???
%D3DPBLENDCAPS_INVSRCCOLOR        = &H00000008???
%D3DPBLENDCAPS_SRCALPHA           = &H00000010???
%D3DPBLENDCAPS_INVSRCALPHA        = &H00000020???
%D3DPBLENDCAPS_DESTALPHA          = &H00000040???
%D3DPBLENDCAPS_INVDESTALPHA       = &H00000080???
%D3DPBLENDCAPS_DESTCOLOR          = &H00000100???
%D3DPBLENDCAPS_INVDESTCOLOR       = &H00000200???
%D3DPBLENDCAPS_SRCALPHASAT        = &H00000400???
%D3DPBLENDCAPS_BOTHSRCALPHA       = &H00000800???
%D3DPBLENDCAPS_BOTHINVSRCALPHA    = &H00001000???
%D3DPBLENDCAPS_BLENDFACTOR        = &H00002000???  ' /* Supports both D3DBLEND_BLENDFACTOR and D3DBLEND_INVBLENDFACTOR */

'/* D3D9Ex only -- */
#IF NOT %DEF(%D3D_DISABLE_9EX)
%D3DPBLENDCAPS_SRCCOLOR2          = &H00004000???
%D3DPBLENDCAPS_INVSRCCOLOR2       = &H00008000???
#ENDIF   ' // !D3D_DISABLE_9EX
'/* -- D3D9Ex only */

'//
'// ShadeCaps
'//
%D3DPSHADECAPS_COLORGOURAUDRGB        = &H00000008???
%D3DPSHADECAPS_SPECULARGOURAUDRGB     = &H00000200???
%D3DPSHADECAPS_ALPHAGOURAUDBLEND      = &H00004000???
%D3DPSHADECAPS_FOGGOURAUD             = &H00080000???

'//
'// TextureCaps
'//
%D3DPTEXTURECAPS_PERSPECTIVE              = &H00000001???   ' /* Perspective-correct texturing is supported */
%D3DPTEXTURECAPS_POW2                     = &H00000002???   ' /* Power-of-2 texture dimensions are required - applies to non-Cube/Volume textures only. */
%D3DPTEXTURECAPS_ALPHA                    = &H00000004???   ' /* Alpha in texture pixels is supported */
%D3DPTEXTURECAPS_SQUAREONLY               = &H00000020???   ' /* Only square textures are supported */
%D3DPTEXTURECAPS_TEXREPEATNOTSCALEDBYSIZE = &H00000040???   ' /* Texture indices are not scaled by the texture size prior to interpolation */
%D3DPTEXTURECAPS_ALPHAPALETTE             = &H00000080???   ' /* Device can draw alpha from texture palettes */
'// Device can use non-POW2 textures if:
'//  1) D3DTEXTURE_ADDRESS is set to CLAMP for this texture's stage
'//  2) D3DRS_WRAP(N) is zero for this texture's coordinates
'//  3) mip mapping is not enabled (use magnification filter only)
%D3DPTEXTURECAPS_NONPOW2CONDITIONAL   = &H00000100???
%D3DPTEXTURECAPS_PROJECTED            = &H00000400???  ' /* Device can do D3DTTFF_PROJECTED */
%D3DPTEXTURECAPS_CUBEMAP              = &H00000800???  ' /* Device can do cubemap textures */
%D3DPTEXTURECAPS_VOLUMEMAP            = &H00002000???  ' /* Device can do volume textures */
%D3DPTEXTURECAPS_MIPMAP               = &H00004000???  ' /* Device can do mipmapped textures */
%D3DPTEXTURECAPS_MIPVOLUMEMAP         = &H00008000???  ' /* Device can do mipmapped volume textures */
%D3DPTEXTURECAPS_MIPCUBEMAP           = &H00010000???  ' /* Device can do mipmapped cube maps */
%D3DPTEXTURECAPS_CUBEMAP_POW2         = &H00020000???  ' /* Device requires that cubemaps be power-of-2 dimension */
%D3DPTEXTURECAPS_VOLUMEMAP_POW2       = &H00040000???  ' /* Device requires that volume maps be power-of-2 dimension */
%D3DPTEXTURECAPS_NOPROJECTEDBUMPENV   = &H00200000???  ' /* Device does not support projected bump env lookup operation
                                                     '    in programmable and fixed function pixel shaders */

'//
'// TextureFilterCaps, StretchRectFilterCaps
'//
%D3DPTFILTERCAPS_MINFPOINT            = &H00000100???  ' /* Min Filter */
%D3DPTFILTERCAPS_MINFLINEAR           = &H00000200???
%D3DPTFILTERCAPS_MINFANISOTROPIC      = &H00000400???
%D3DPTFILTERCAPS_MINFPYRAMIDALQUAD    = &H00000800???
%D3DPTFILTERCAPS_MINFGAUSSIANQUAD     = &H00001000???
%D3DPTFILTERCAPS_MIPFPOINT            = &H00010000???  ' /* Mip Filter */
%D3DPTFILTERCAPS_MIPFLINEAR           = &H00020000???

'/* D3D9Ex only -- */
#IF NOT %DEF(%D3D_DISABLE_9EX)
%D3DPTFILTERCAPS_CONVOLUTIONMONO      = &H00040000???  ' /* Min and Mag for the convolution mono filter */
#ENDIF   ' // !D3D_DISABLE_9EX
'/* -- D3D9Ex only */

%D3DPTFILTERCAPS_MAGFPOINT            = &H01000000???  ' /* Mag Filter */
%D3DPTFILTERCAPS_MAGFLINEAR           = &H02000000???
%D3DPTFILTERCAPS_MAGFANISOTROPIC      = &H04000000???
%D3DPTFILTERCAPS_MAGFPYRAMIDALQUAD    = &H08000000???
%D3DPTFILTERCAPS_MAGFGAUSSIANQUAD     = &H10000000???

'//
'// TextureAddressCaps
'//
%D3DPTADDRESSCAPS_WRAP            = &H00000001???
%D3DPTADDRESSCAPS_MIRROR          = &H00000002???
%D3DPTADDRESSCAPS_CLAMP           = &H00000004???
%D3DPTADDRESSCAPS_BORDER          = &H00000008???
%D3DPTADDRESSCAPS_INDEPENDENTUV   = &H00000010???
%D3DPTADDRESSCAPS_MIRRORONCE      = &H00000020???

'//
'// StencilCaps
'//
%D3DSTENCILCAPS_KEEP              = &H00000001???
%D3DSTENCILCAPS_ZERO              = &H00000002???
%D3DSTENCILCAPS_REPLACE           = &H00000004???
%D3DSTENCILCAPS_INCRSAT           = &H00000008???
%D3DSTENCILCAPS_DECRSAT           = &H00000010???
%D3DSTENCILCAPS_INVERT            = &H00000020???
%D3DSTENCILCAPS_INCR              = &H00000040???
%D3DSTENCILCAPS_DECR              = &H00000080???
%D3DSTENCILCAPS_TWOSIDED          = &H00000100???

'//
'// TextureOpCaps
'//
%D3DTEXOPCAPS_DISABLE                     = &H00000001???
%D3DTEXOPCAPS_SELECTARG1                  = &H00000002???
%D3DTEXOPCAPS_SELECTARG2                  = &H00000004???
%D3DTEXOPCAPS_MODULATE                    = &H00000008???
%D3DTEXOPCAPS_MODULATE2X                  = &H00000010???
%D3DTEXOPCAPS_MODULATE4X                  = &H00000020???
%D3DTEXOPCAPS_ADD                         = &H00000040???
%D3DTEXOPCAPS_ADDSIGNED                   = &H00000080???
%D3DTEXOPCAPS_ADDSIGNED2X                 = &H00000100???
%D3DTEXOPCAPS_SUBTRACT                    = &H00000200???
%D3DTEXOPCAPS_ADDSMOOTH                   = &H00000400???
%D3DTEXOPCAPS_BLENDDIFFUSEALPHA           = &H00000800???
%D3DTEXOPCAPS_BLENDTEXTUREALPHA           = &H00001000???
%D3DTEXOPCAPS_BLENDFACTORALPHA            = &H00002000???
%D3DTEXOPCAPS_BLENDTEXTUREALPHAPM         = &H00004000???
%D3DTEXOPCAPS_BLENDCURRENTALPHA           = &H00008000???
%D3DTEXOPCAPS_PREMODULATE                 = &H00010000???
%D3DTEXOPCAPS_MODULATEALPHA_ADDCOLOR      = &H00020000???
%D3DTEXOPCAPS_MODULATECOLOR_ADDALPHA      = &H00040000???
%D3DTEXOPCAPS_MODULATEINVALPHA_ADDCOLOR   = &H00080000???
%D3DTEXOPCAPS_MODULATEINVCOLOR_ADDALPHA   = &H00100000???
%D3DTEXOPCAPS_BUMPENVMAP                  = &H00200000???
%D3DTEXOPCAPS_BUMPENVMAPLUMINANCE         = &H00400000???
%D3DTEXOPCAPS_DOTPRODUCT3                 = &H00800000???
%D3DTEXOPCAPS_MULTIPLYADD                 = &H01000000???
%D3DTEXOPCAPS_LERP                        = &H02000000???

'//
'// FVFCaps
'//
%D3DFVFCAPS_TEXCOORDCOUNTMASK     = &H0000FFFF???  ' /* mask for texture coordinate count field */
%D3DFVFCAPS_DONOTSTRIPELEMENTS    = &H00080000???  ' /* Device prefers that vertex elements not be stripped */
%D3DFVFCAPS_PSIZE                 = &H00100000???  ' /* Device can receive point size */

'//
'// VertexProcessingCaps
'//
%D3DVTXPCAPS_TEXGEN               = &H00000001???  ' /* device can do texgen */
%D3DVTXPCAPS_MATERIALSOURCE7      = &H00000002???  ' /* device can do DX7-level colormaterialsource ops */
%D3DVTXPCAPS_DIRECTIONALLIGHTS    = &H00000008???  ' /* device can do directional lights */
%D3DVTXPCAPS_POSITIONALLIGHTS     = &H00000010???  ' /* device can do positional lights (includes point and spot) */
%D3DVTXPCAPS_LOCALVIEWER          = &H00000020???  ' /* device can do local viewer */
%D3DVTXPCAPS_TWEENING             = &H00000040???  ' /* device can do vertex tweening */
%D3DVTXPCAPS_TEXGEN_SPHEREMAP     = &H00000100???  ' /* device supports D3DTSS_TCI_SPHEREMAP */
%D3DVTXPCAPS_NO_TEXGEN_NONLOCALVIEWER = &H00000200???  ' /* device does not support TexGen in non-local
                                                       '    viewer mode */

'//
'// DevCaps2
'//
%D3DDEVCAPS2_STREAMOFFSET                         = &H00000001???  ' /* Device supports offsets in streams. Must be set by DX9 drivers */
%D3DDEVCAPS2_DMAPNPATCH                           = &H00000002???  ' /* Device supports displacement maps for N-Patches*/
%D3DDEVCAPS2_ADAPTIVETESSRTPATCH                  = &H00000004???  ' /* Device supports adaptive tesselation of RT-patches*/
%D3DDEVCAPS2_ADAPTIVETESSNPATCH                   = &H00000008???  ' /* Device supports adaptive tesselation of N-patches*/
%D3DDEVCAPS2_CAN_STRETCHRECT_FROM_TEXTURES        = &H00000010???  ' /* Device supports StretchRect calls with a texture as the source*/
%D3DDEVCAPS2_PRESAMPLEDDMAPNPATCH                 = &H00000020???  ' /* Device supports presampled displacement maps for N-Patches */
%D3DDEVCAPS2_VERTEXELEMENTSCANSHARESTREAMOFFSET   = &H00000040???  ' /* Vertex elements in a vertex declaration can share the same stream offset */

'//
'// DeclTypes
'//
%D3DDTCAPS_UBYTE4      = &H00000001???
%D3DDTCAPS_UBYTE4N     = &H00000002???
%D3DDTCAPS_SHORT2N     = &H00000004???
%D3DDTCAPS_SHORT4N     = &H00000008???
%D3DDTCAPS_USHORT2N    = &H00000010???
%D3DDTCAPS_USHORT4N    = &H00000020???
%D3DDTCAPS_UDEC3       = &H00000040???
%D3DDTCAPS_DEC3N       = &H00000080???
%D3DDTCAPS_FLOAT16_2   = &H00000100???
%D3DDTCAPS_FLOAT16_4   = &H00000200???

'#pragma pack()

'#endif /* (DIRECT3D_VERSION >= 0x0900) */
