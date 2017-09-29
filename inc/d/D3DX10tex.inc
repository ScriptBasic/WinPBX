' ########################################################################################
' Microsoft Windows
' File: d3dx10tex.inc
' Contents: D3DX10 texturing APIs
' Copyright (c) 2010 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3DX10TEX_INC = 1

'//----------------------------------------------------------------------------
'// D3DX10_FILTER flags:
'// ------------------
'//
'// A valid filter must contain one of these values:
'//
'//  D3DX10_FILTER_NONE
'//      No scaling or filtering will take place.  Pixels outside the bounds
'//      of the source image are assumed to be transparent black.
'//  D3DX10_FILTER_POINT
'//      Each destination pixel is computed by sampling the nearest pixel
'//      from the source image.
'//  D3DX10_FILTER_LINEAR
'//      Each destination pixel is computed by linearly interpolating between
'//      the nearest pixels in the source image.  This filter works best
'//      when the scale on each axis is less than 2.
'//  D3DX10_FILTER_TRIANGLE
'//      Every pixel in the source image contributes equally to the
'//      destination image.  This is the slowest of all the filters.
'//  D3DX10_FILTER_BOX
'//      Each pixel is computed by averaging a 2x2(x2) box pixels from
'//      the source image. Only works when the dimensions of the
'//      destination are half those of the source. (as with mip maps)
'//
'// And can be OR'd with any of these optional flags:
'//
'//  D3DX10_FILTER_MIRROR_U
'//      Indicates that pixels off the edge of the texture on the U-axis
'//      should be mirrored, not wraped.
'//  D3DX10_FILTER_MIRROR_V
'//      Indicates that pixels off the edge of the texture on the V-axis
'//      should be mirrored, not wraped.
'//  D3DX10_FILTER_MIRROR_W
'//      Indicates that pixels off the edge of the texture on the W-axis
'//      should be mirrored, not wraped.
'//  D3DX10_FILTER_MIRROR
'//      Same as specifying D3DX10_FILTER_MIRROR_U | D3DX10_FILTER_MIRROR_V |
'//      D3DX10_FILTER_MIRROR_V
'//  D3DX10_FILTER_DITHER
'//      Dithers the resulting image using a 4x4 order dither pattern.
'//  D3DX10_FILTER_SRGB_IN
'//      Denotes that the input data is in sRGB (gamma 2.2) colorspace.
'//  D3DX10_FILTER_SRGB_OUT
'//      Denotes that the output data is in sRGB (gamma 2.2) colorspace.
'//  D3DX10_FILTER_SRGB
'//      Same as specifying D3DX10_FILTER_SRGB_IN | D3DX10_FILTER_SRGB_OUT
'//
'//----------------------------------------------------------------------------

' enum D3DX10_FILTER_FLAG
%D3DX10_FILTER_NONE             = 1???          ' (1 << 0)
%D3DX10_FILTER_POINT            = 2???          ' (2 << 0)
%D3DX10_FILTER_LINEAR           = 3???          ' (3 << 0)
%D3DX10_FILTER_TRIANGLE         = 4???          ' (4 << 0)
%D3DX10_FILTER_BOX              = 5???          ' (5 << 0)

%D3DX10_FILTER_MIRROR_U         = &H10000???    ' (1 << 16)
%D3DX10_FILTER_MIRROR_V         = &H20000???    ' (2 << 16)
%D3DX10_FILTER_MIRROR_W         = &H40000???    ' (4 << 16)
%D3DX10_FILTER_MIRROR           = &H70000???    ' (7 << 16)

%D3DX10_FILTER_DITHER           = &H80000???    ' (1 << 19)
%D3DX10_FILTER_DITHER_DIFFUSION = &H100000???   ' (2 << 19)

%D3DX10_FILTER_SRGB_IN          = &H200000???   ' (1 << 21)
%D3DX10_FILTER_SRGB_OUT         = &H400000???   ' (2 << 21)
%D3DX10_FILTER_SRGB             = &H600000???   ' (3 << 21)

'//----------------------------------------------------------------------------
'// D3DX10_NORMALMAP flags:
'// ---------------------
'// These flags are used to control how D3DX10ComputeNormalMap generates normal
'// maps.  Any number of these flags may be OR'd together in any combination.
'//
'//  D3DX10_NORMALMAP_MIRROR_U
'//      Indicates that pixels off the edge of the texture on the U-axis
'//      should be mirrored, not wraped.
'//  D3DX10_NORMALMAP_MIRROR_V
'//      Indicates that pixels off the edge of the texture on the V-axis
'//      should be mirrored, not wraped.
'//  D3DX10_NORMALMAP_MIRROR
'//      Same as specifying D3DX10_NORMALMAP_MIRROR_U | D3DX10_NORMALMAP_MIRROR_V
'//  D3DX10_NORMALMAP_INVERTSIGN
'//      Inverts the direction of each normal
'//  D3DX10_NORMALMAP_COMPUTE_OCCLUSION
'//      Compute the per pixel Occlusion term and encodes it into the alpha.
'//      An Alpha of 1 means that the pixel is not obscured in anyway, and
'//      an alpha of 0 would mean that the pixel is completly obscured.
'//
'//----------------------------------------------------------------------------

' enum D3DX10_NORMALMAP_FLAG
%D3DX10_NORMALMAP_MIRROR_U          = &H10000???    ' (1 << 16)
%D3DX10_NORMALMAP_MIRROR_V          = &H20000???    ' (2 << 16)
%D3DX10_NORMALMAP_MIRROR            = &H30000???    ' (3 << 16)
%D3DX10_NORMALMAP_INVERTSIGN        = &H80000???    ' (8 << 16)
%D3DX10_NORMALMAP_COMPUTE_OCCLUSION = &H100000???   ' (16 << 16)

'//----------------------------------------------------------------------------
'// D3DX10_CHANNEL flags:
'// -------------------
'// These flags are used by functions which operate on or more channels
'// in a texture.
'//
'// D3DX10_CHANNEL_RED
'//     Indicates the red channel should be used
'// D3DX10_CHANNEL_BLUE
'//     Indicates the blue channel should be used
'// D3DX10_CHANNEL_GREEN
'//     Indicates the green channel should be used
'// D3DX10_CHANNEL_ALPHA
'//     Indicates the alpha channel should be used
'// D3DX10_CHANNEL_LUMINANCE
'//     Indicates the luminaces of the red green and blue channels should be
'//     used.
'//
'//----------------------------------------------------------------------------

' enum D3DX10_CHANNEL_FLAG
%D3DX10_CHANNEL_RED           = &H1???    ' (1 << 0)
%D3DX10_CHANNEL_BLUE          = &H2???    ' (1 << 1)
%D3DX10_CHANNEL_GREEN         = &H4???    ' (1 << 2)
%D3DX10_CHANNEL_ALPHA         = &H8???    ' (1 << 3)
%D3DX10_CHANNEL_LUMINANCE     = &H10???   ' (1 << 4)


'//----------------------------------------------------------------------------
'// D3DX10_IMAGE_FILE_FORMAT:
'// ---------------------
'// This enum is used to describe supported image file formats.
'//
'//----------------------------------------------------------------------------

' enum D3DX10_IMAGE_FILE_FORMAT
%D3DX10_IFF_BMP         = 0???
%D3DX10_IFF_JPG         = 1???
%D3DX10_IFF_PNG         = 3???
%D3DX10_IFF_DDS         = 4???
%D3DX10_IFF_TIFF        = 10???
%D3DX10_IFF_GIF         = 11???
%D3DX10_IFF_WMP         = 12???
%D3DX10_IFF_FORCE_DWORD = &H7fffffff???


'//----------------------------------------------------------------------------
'// D3DX10_SAVE_TEXTURE_FLAG:
'// ---------------------
'// This enum is used to support texture saving options.
'//
'//----------------------------------------------------------------------------

' enum D3DX10_SAVE_TEXTURE_FLAG
%D3DX10_STF_USEINPUTBLOB = &H0001???

'//----------------------------------------------------------------------------
'// D3DX10_IMAGE_INFO:
'// ---------------
'// This structure is used to return a rough description of what the
'// the original contents of an image file looked like.
'//
'//  Width
'//      Width of original image in pixels
'//  Height
'//      Height of original image in pixels
'//  Depth
'//      Depth of original image in pixels
'//  ArraySize
'//      Array size in textures
'//  MipLevels
'//      Number of mip levels in original image
'//  MiscFlags
'//      Miscellaneous flags
'//  Format
'//      D3D format which most closely describes the data in original image
'//  ResourceDimension
'//      D3D10_RESOURCE_DIMENSION representing the dimension of texture stored in the file.
'//      D3D10_RESOURCE_DIMENSION_TEXTURE1D, 2D, 3D
'//  ImageFileFormat
'//      D3DX10_IMAGE_FILE_FORMAT representing the format of the image file.
'//----------------------------------------------------------------------------

' // Size = 36 bytes
TYPE D3DX10_IMAGE_INFO DWORD
   Width             AS DWORD   ' UINT
   Height            AS DWORD   ' UINT
   Depth             AS DWORD   ' UINT
   ArraySize         AS DWORD   ' UINT
   MipLevels         AS DWORD   ' UINT
   MiscFlags         AS DWORD   ' UINT
   Format            AS DWORD   ' DXGI_FORMAT
   ResourceDimension AS DWORD   ' D3D10_RESOURCE_DIMENSION
   ImageFileFormat   AS DWORD   ' D3DX10_IMAGE_FILE_FORMAT
END TYPE

'//////////////////////////////////////////////////////////////////////////////
'// Image File APIs ///////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

'//----------------------------------------------------------------------------
'// D3DX10_IMAGE_LOAD_INFO:
'// ---------------
'// This structure can be optionally passed in to texture loader APIs to
'// control how textures get loaded. Pass in D3DX10_DEFAULT for any of these
'// to have D3DX automatically pick defaults based on the source file.
'//
'//  Width
'//      Rescale texture to Width texels wide
'//  Height
'//      Rescale texture to Height texels high
'//  Depth
'//      Rescale texture to Depth texels deep
'//  FirstMipLevel
'//      First mip level to load
'//  MipLevels
'//      Number of mip levels to load after the first level
'//  Usage
'//      D3D10_USAGE flag for the new texture
'//  BindFlags
'//      D3D10 Bind flags for the new texture
'//  CpuAccessFlags
'//      D3D10 CPU Access flags for the new texture
'//  MiscFlags
'//      Reserved. Must be 0
'//  Format
'//      Resample texture to the specified format
'//  Filter
'//      Filter the texture using the specified filter (only when resampling)
'//  MipFilter
'//      Filter the texture mip levels using the specified filter (only if
'//      generating mips)
'//  pSrcInfo
'//      (optional) pointer to a D3DX10_IMAGE_INFO structure that will get
'//      populated with source image information
'//----------------------------------------------------------------------------

' // Size = 52 bytes
TYPE D3DX10_IMAGE_LOAD_INFO DWORD
   Width          AS DWORD                   ' UINT
   Height         AS DWORD                   ' UINT
   Depth          AS DWORD                   ' UINT
   FirstMipLevel  AS DWORD                   ' UINT
   MipLevels      AS DWORD                   ' UINT
   Usage          AS DWORD                   ' D3D10_USAGE
   BindFlags      AS DWORD                   ' UINT
   CpuAccessFlags AS DWORD                   ' UINT
   MiscFlags      AS DWORD                   ' UINT
   Format         AS DWORD                   ' DXGI_FORMAT
   Filter         AS DWORD                   ' UINT
   MipFilter      AS DWORD                   ' UINT
   pSrcInfo       AS D3DX10_IMAGE_INFO PTR   ' D3DX10_IMAGE_INFO *
END TYPE

' Must be included here because D3DX10_IMAGE_LOAD_INFO is used by other include file.
#INCLUDE ONCE "d3dx10.inc"

'//-------------------------------------------------------------------------------
'// GetImageInfoFromFile/Resource/Memory:
'// ------------------------------
'// Fills in a D3DX10_IMAGE_INFO struct with information about an image file.
'//
'// Parameters:
'//  pSrcFile
'//      File name of the source image.
'//  pSrcModule
'//      Module where resource is located, or NULL for module associated
'//      with image the os used to create the current process.
'//  pSrcResource
'//      Resource name.
'//  pSrcData
'//      Pointer to file in memory.
'//  SrcDataSize
'//      Size in bytes of file in memory.
'//  pPump
'//      Optional pointer to a thread pump object to use.
'//  pSrcInfo
'//      Pointer to a D3DX10_IMAGE_INFO structure to be filled in with the
'//      description of the data in the source image file.
'//  pHResult
'//      Pointer to a memory location to receive the return value upon completion.
'//      Maybe NULL if not needed.
'//      If pPump != NULL, pHResult must be a valid memory location until the
'//      the asynchronous execution completes.
'//-------------------------------------------------------------------------------

DECLARE FUNCTION D3DX10GetImageInfoFromFileA IMPORT $D3DX10_DLLNAME ALIAS "D3DX10GetImageInfoFromFileA" ( _
   BYREF pSrcFile AS ASCIIZ _                           ' __in  LPCSTR                    pSrcFile
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump*        pPump
 , BYREF pSrcInfo AS D3DX10_IMAGE_INFO _                ' __in  D3DX10_IMAGE_INFO*        pSrcInfo
 , BYREF pHResult AS LONG _                             ' __out HRESULT*                  pHResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10GetImageInfoFromFileW IMPORT $D3DX10_DLLNAME ALIAS "D3DX10GetImageInfoFromFileW" ( _
   BYREF pSrcFile AS WSTRINGZ _                         ' __in  LPCWSTR                   pSrcFile
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump*        pPump
 , BYREF pSrcInfo AS D3DX10_IMAGE_INFO _                ' __in  D3DX10_IMAGE_INFO*        pSrcInfo
 , BYREF pHResult AS LONG _                             ' __out HRESULT*                  pHResult
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DX10GetImageInfoFromFile = D3DX10GetImageInfoFromFileW
#ELSE
   MACRO D3DX10GetImageInfoFromFile = D3DX10GetImageInfoFromFileA
#ENDIF

DECLARE FUNCTION D3DX10GetImageInfoFromResourceA IMPORT $D3DX10_DLLNAME ALIAS "D3DX10GetImageInfoFromResourceA" ( _
   BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE                   hSrcModule
 , BYREF pSrcResource AS ASCIIZ _                       ' __in  LPCSTR                    pSrcResource
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump*        pPump
 , BYREF pSrcInfo AS D3DX10_IMAGE_INFO _                ' __in  D3DX10_IMAGE_INFO*        pSrcInfo
 , BYREF pHResult AS LONG _                             ' __out HRESULT*                  pHResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10GetImageInfoFromResourceW IMPORT $D3DX10_DLLNAME ALIAS "D3DX10GetImageInfoFromResourceW" ( _
   BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE                   hSrcModule
 , BYREF pSrcResource AS WSTRINGZ _                     ' __in  LPCWSTR                   pSrcResource
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump*        pPump
 , BYREF pSrcInfo AS D3DX10_IMAGE_INFO _                ' __in  D3DX10_IMAGE_INFO*        pSrcInfo
 , BYREF pHResult AS LONG _                             ' __out HRESULT*                  pHResult
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DX10GetImageInfoFromResource = D3DX10GetImageInfoFromResourceW
#ELSE
   MACRO D3DX10GetImageInfoFromResource = D3DX10GetImageInfoFromResourceA
#ENDIF

DECLARE FUNCTION D3DX10GetImageInfoFromMemory IMPORT $D3DX10_DLLNAME ALIAS "D3DX10GetImageInfoFromMemory" ( _
   BYVAL pSrcData AS DWORD _                            ' __in  LPCVOID                   pSrcData
 , BYVAL SrcDataSize AS DWORD _                         ' __in  SIZE_T                    SrcDataSize
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump*        pPump
 , BYREF pSrcInfo AS D3DX10_IMAGE_INFO _                ' __in  D3DX10_IMAGE_INFO*        pSrcInfo
 , BYREF pHResult AS LONG _                             ' __out HRESULT*                  pHResult
 ) AS LONG                                              ' HRESULT

'//////////////////////////////////////////////////////////////////////////////
'// Create/Save Texture APIs //////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

'//----------------------------------------------------------------------------
'// D3DX10CreateTextureFromFile/Resource/Memory:
'// D3DX10CreateShaderResourceViewFromFile/Resource/Memory:
'// -----------------------------------
'// Create a texture object from a file or resource.
'//
'// Parameters:
'//
'//  pDevice
'//      The D3D device with which the texture is going to be used.
'//  pSrcFile
'//      File name.
'//  hSrcModule
'//      Module handle. if NULL, current module will be used.
'//  pSrcResource
'//      Resource name in module
'//  pvSrcData
'//      Pointer to file in memory.
'//  SrcDataSize
'//      Size in bytes of file in memory.
'//  pLoadInfo
'//      Optional pointer to a D3DX10_IMAGE_LOAD_INFO structure that
'//      contains additional loader parameters.
'//  pPump
'//      Optional pointer to a thread pump object to use.
'//  ppTexture
'//      [out] Created texture object.
'//  ppShaderResourceView
'//      [out] Shader resource view object created.
'//  pHResult
'//      Pointer to a memory location to receive the return value upon completion.
'//      Maybe NULL if not needed.
'//      If pPump != NULL, pHResult must be a valid memory location until the
'//      the asynchronous execution completes.
'//
'//----------------------------------------------------------------------------


'// FromFile

DECLARE FUNCTION D3DX10CreateShaderResourceViewFromFileA IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateShaderResourceViewFromFileA" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device*               pDevice
 , BYREF pSrcFile AS ASCIIZ _                           ' __in  LPCSTR                      pSrcFile
 , BYREF pLoadInfo AS D3DX10_IMAGE_LOAD_INFO _          ' __in  D3DX10_IMAGE_LOAD_INFO      *pLoadInfo
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump*          pPump
 , BYREF ppShaderResourceView AS ID3D10ShaderResourceView _ ' __out ID3D10ShaderResourceView**  ppShaderResourceView
 , BYREF pHResult AS LONG _                             ' __out HRESULT*                    pHResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10CreateShaderResourceViewFromFileW IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateShaderResourceViewFromFileW" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device*               pDevice
 , BYREF pSrcFile AS WSTRINGZ _                         ' __in  LPCWSTR                     pSrcFile
 , BYREF pLoadInfo AS D3DX10_IMAGE_LOAD_INFO _          ' __in  D3DX10_IMAGE_LOAD_INFO      *pLoadInfo
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump*          pPump
 , BYREF ppShaderResourceView AS ID3D10ShaderResourceView _ ' __out ID3D10ShaderResourceView**  ppShaderResourceView
 , BYREF pHResult AS LONG _                             ' __out HRESULT*                    pHResult
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DX10CreateShaderResourceViewFromFile = D3DX10CreateShaderResourceViewFromFileW
#ELSE
   MACRO D3DX10CreateShaderResourceViewFromFile = D3DX10CreateShaderResourceViewFromFileA
#ENDIF

DECLARE FUNCTION D3DX10CreateTextureFromFileA IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateTextureFromFileA" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device*               pDevice
 , BYREF pSrcFile AS ASCIIZ _                           ' __in  LPCSTR                      pSrcFile
 , BYREF pLoadInfo AS D3DX10_IMAGE_LOAD_INFO _          ' __in  D3DX10_IMAGE_LOAD_INFO      *pLoadInfo
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump*          pPump
 , BYREF ppTexture AS ID3D10Resource _                  ' __out ID3D10Resource**            ppTexture
 , BYREF pHResult AS LONG _                             ' __out HRESULT*                    pHResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10CreateTextureFromFileW IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateTextureFromFileW" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device*               pDevice
 , BYREF pSrcFile AS WSTRINGZ _                         ' __in  LPCWSTR                     pSrcFile
 , BYREF pLoadInfo AS D3DX10_IMAGE_LOAD_INFO _          ' __in  D3DX10_IMAGE_LOAD_INFO      *pLoadInfo
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump*          pPump
 , BYREF ppTexture AS ID3D10Resource _                  ' __out ID3D10Resource**            ppTexture
 , BYREF pHResult AS LONG _                             ' __out HRESULT*                    pHResult
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DX10CreateTextureFromFile = D3DX10CreateTextureFromFileW
#ELSE
   MACRO D3DX10CreateTextureFromFile = D3DX10CreateTextureFromFileA
#ENDIF

'// FromResource (resources in dll/exes)

DECLARE FUNCTION D3DX10CreateShaderResourceViewFromResourceA IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateShaderResourceViewFromResourceA" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device*               pDevice
 , BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE                     hSrcModule
 , BYREF pSrcResource AS ASCIIZ _                       ' __in  LPCSTR                      pSrcResource
 , BYREF pLoadInfo AS D3DX10_IMAGE_LOAD_INFO _          ' __in  D3DX10_IMAGE_LOAD_INFO*     pLoadInfo
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump*          pPump
 , BYREF ppShaderResourceView AS ID3D10ShaderResourceView _ ' __out ID3D10ShaderResourceView**  ppShaderResourceView
 , BYREF pHResult AS LONG _                             ' __out HRESULT*                    pHResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10CreateShaderResourceViewFromResourceW IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateShaderResourceViewFromResourceW" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device*               pDevice
 , BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE                     hSrcModule
 , BYREF pSrcResource AS WSTRINGZ _                     ' __in  LPCWSTR                     pSrcResource
 , BYREF pLoadInfo AS D3DX10_IMAGE_LOAD_INFO _          ' __in  D3DX10_IMAGE_LOAD_INFO*     pLoadInfo
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump*          pPump
 , BYREF ppShaderResourceView AS ID3D10ShaderResourceView _ ' __out ID3D10ShaderResourceView**  ppShaderResourceView
 , BYREF pHResult AS LONG _                             ' __out HRESULT*                    pHResult
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DX10CreateShaderResourceViewFromResource = D3DX10CreateShaderResourceViewFromResourceW
#ELSE
   MACRO D3DX10CreateShaderResourceViewFromResource = D3DX10CreateShaderResourceViewFromResourceA
#ENDIF

DECLARE FUNCTION D3DX10CreateTextureFromResourceA IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateTextureFromResourceA" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device*               pDevice
 , BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE                     hSrcModule
 , BYREF hSrcModule AS ASCIIZ _                         ' __in  LPCSTR                      pSrcResource
 , BYREF pLoadInfo AS D3DX10_IMAGE_LOAD_INFO _          ' __in  D3DX10_IMAGE_LOAD_INFO*     pLoadInfo
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump*          pPump
 , BYREF ppTexture AS ID3D10Resource _                  ' __out ID3D10Resource**            ppTexture
 , BYREF pHResult AS LONG _                             ' __out HRESULT*                    pHResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10CreateTextureFromResourceW IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateTextureFromResourceW" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device*               pDevice
 , BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE                     hSrcModule
 , BYREF pSrcResource AS WSTRINGZ _                     ' __in  LPCWSTR                     pSrcResource
 , BYREF pLoadInfo AS D3DX10_IMAGE_LOAD_INFO _          ' __in  D3DX10_IMAGE_LOAD_INFO*     pLoadInfo
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump*          pPump
 , BYREF ppTexture AS ID3D10Resource _                  ' __out ID3D10Resource**            ppTexture
 , BYREF pHResult AS LONG _                             ' __out HRESULT*                    pHResult
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DX10CreateTextureFromResource = D3DX10CreateTextureFromResourceW
#ELSE
   MACRO D3DX10CreateTextureFromResource = D3DX10CreateTextureFromResourceA
#ENDIF

'// FromFileInMemory

DECLARE FUNCTION D3DX10CreateShaderResourceViewFromMemory IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateShaderResourceViewFromMemory" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device*               pDevice
 , BYVAL pSrcData AS DWORD _                            ' __in  LPCVOID                     pSrcData
 , BYVAL SrcDataSize AS DWORD _                         ' __in  SIZE_T                      SrcDataSize
 , BYREF pLoadInfo AS D3DX10_IMAGE_LOAD_INFO _          ' __in  D3DX10_IMAGE_LOAD_INFO*     pLoadInfo
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump*          pPump
 , BYREF ppShaderResourceView AS ID3D10ShaderResourceView _ ' __out ID3D10ShaderResourceView**  ppShaderResourceView
 , BYREF pHResult AS LONG _                             ' __out HRESULT*                    pHResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10CreateTextureFromMemory IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateTextureFromMemory" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device*               pDevice
 , BYVAL pSrcData AS DWORD _                            ' __in  LPCVOID                     pSrcData
 , BYVAL SrcDataSize AS DWORD _                         ' __in  SIZE_T                      SrcDataSize
 , BYREF pLoadInfo AS D3DX10_IMAGE_LOAD_INFO _          ' __in  D3DX10_IMAGE_LOAD_INFO*     pLoadInfo
 , BYVAL pPump AS ID3DX10ThreadPump _                   ' __in  ID3DX10ThreadPump*          pPump
 , BYREF ppShaderResourceView AS ID3D10Resource _       ' __out ID3D10Resource**            ppShaderResourceView
 , BYREF pHResult AS LONG _                             ' __out HRESULT*                    pHResult
 ) AS LONG                                              ' HRESULT

'//////////////////////////////////////////////////////////////////////////////
'// Misc Texture APIs /////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

'//----------------------------------------------------------------------------
'// D3DX10_TEXTURE_LOAD_INFO:
'// ------------------------
'//
'//----------------------------------------------------------------------------

' // Size = 40 bytes
TYPE D3DX10_TEXTURE_LOAD_INFO DWORD
   pSrcBox         AS D3D10_BOX PTR   ' D3D10_BOX *
   pDstBox         AS D3D10_BOX PTR   ' D3D10_BOX *
   SrcFirstMip     AS DWORD           ' UINT
   DstFirstMip     AS DWORD           ' UINT
   NumMips         AS DWORD           ' UINT
   SrcFirstElement AS DWORD           ' UINT
   DstFirstElement AS DWORD           ' UINT
   NumElements     AS DWORD           ' UINT
   Filter          AS DWORD           ' UINT
   MipFilter       AS DWORD           ' UINT
END TYPE


'//----------------------------------------------------------------------------
'// D3DX10LoadTextureFromTexture:
'// ----------------------------
'// Load a texture from a texture.
'//
'// Parameters:
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DX10LoadTextureFromTexture IMPORT $D3DX10_DLLNAME ALIAS "D3DX10LoadTextureFromTexture" ( _
   BYVAL pSrcTexture AS ID3D10Resource _                ' __in ID3D10Resource           *pSrcTexture
 , BYREF pLoadInfo AS D3DX10_TEXTURE_LOAD_INFO _        ' __in D3DX10_TEXTURE_LOAD_INFO *pLoadInfo
 , BYVAL pDstTexture AS ID3D10Resource _                ' __in_out ID3D10Resource       *pDstTexture
 ) AS LONG                                              ' HRESULT

'//----------------------------------------------------------------------------
'// D3DX10FilterTexture:
'// ------------------
'// Filters mipmaps levels of a texture.
'//
'// Parameters:
'//  pBaseTexture
'//      The texture object to be filtered
'//  SrcLevel
'//      The level whose image is used to generate the subsequent levels.
'//  MipFilter
'//      D3DX10_FILTER flags controlling how each miplevel is filtered.
'//      Or D3DX10_DEFAULT for D3DX10_FILTER_BOX,
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DX10FilterTexture IMPORT $D3DX10_DLLNAME ALIAS "D3DX10FilterTexture" ( _
   BYVAL pTexture AS ID3D10Resource _                   ' __in ID3D10Resource  *pTexture
 , BYVAL SrcLevel AS DWORD _                            ' __in UINT            SrcLevel
 , BYVAL MipFilter AS DWORD _                           ' __in UINT            MipFilter
 ) AS LONG                                              ' HRESULT

'//----------------------------------------------------------------------------
'// D3DX10SaveTextureToFile:
'// ----------------------
'// Save a texture to a file.
'//
'// Parameters:
'//  pDestFile
'//      File name of the destination file
'//  DestFormat
'//      D3DX10_IMAGE_FILE_FORMAT specifying file format to use when saving.
'//  pSrcTexture
'//      Source texture, containing the image to be saved
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DX10SaveTextureToFileA IMPORT $D3DX10_DLLNAME ALIAS "D3DX10SaveTextureToFileA" ( _
   BYVAL pSrcTexture AS ID3D10Resource _                ' __in ID3D10Resource           *pSrcTexture
 , BYREF DestFormat AS DWORD _                          ' __in D3DX10_IMAGE_FILE_FORMAT DestFormat
 , BYREF pDestFile AS ASCIIZ _                          ' __in LPCSTR                   pDestFile
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10SaveTextureToFileW IMPORT $D3DX10_DLLNAME ALIAS "D3DX10SaveTextureToFileW" ( _
   BYVAL pSrcTexture AS ID3D10Resource _                ' __in ID3D10Resource           *pSrcTexture
 , BYREF DestFormat AS DWORD _                          ' __in D3DX10_IMAGE_FILE_FORMAT DestFormat
 , BYREF pDestFile AS WSTRINGZ _                        ' __in LPCWSTR                  pDestFile
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DX10SaveTextureToFile = D3DX10SaveTextureToFileW
#ELSE
   MACRO D3DX10SaveTextureToFile = D3DX10SaveTextureToFileA
#ENDIF

'//----------------------------------------------------------------------------
'// D3DX10SaveTextureToMemory:
'// ----------------------
'// Save a texture to a blob.
'//
'// Parameters:
'//  pSrcTexture
'//      Source texture, containing the image to be saved
'//  DestFormat
'//      D3DX10_IMAGE_FILE_FORMAT specifying file format to use when saving.
'//  ppDestBuf
'//      address of a d3dxbuffer pointer to return the image data
'//  Flags
'//      optional flags
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DX10SaveTextureToMemory IMPORT $D3DX10_DLLNAME ALIAS "D3DX10SaveTextureToMemory" ( _
   BYVAL pSrcTexture AS ID3D10Resource _                ' __in ID3D10Resource           *pSrcTexture
 , BYREF DestFormat AS DWORD _                          ' __in D3DX10_IMAGE_FILE_FORMAT DestFormat
 , BYVAL ppDestBuf AS ID3D10Blob _                      ' __in_out LPD3D10BLOB*         ppDestBuf
 , BYVAL Flags AS DWORD _                               ' __in UINT                     Flags
 ) AS LONG                                              ' HRESULT

'//----------------------------------------------------------------------------
'// D3DX10ComputeNormalMap:
'// ---------------------
'// Converts a height map into a normal map.  The (x,y,z) components of each
'// normal are mapped to the (r,g,b) channels of the output texture.
'//
'// Parameters
'//  pSrcTexture
'//      Pointer to the source heightmap texture
'//  Flags
'//      D3DX10_NORMALMAP flags
'//  Channel
'//      D3DX10_CHANNEL specifying source of height information
'//  Amplitude
'//      The constant value which the height information is multiplied by.
'//  pDestTexture
'//      Pointer to the destination texture
'//---------------------------------------------------------------------------

DECLARE FUNCTION D3DX10ComputeNormalMap IMPORT $D3DX10_DLLNAME ALIAS "D3DX10ComputeNormalMap" ( _
   BYVAL pSrcTexture AS ID3D10Texture2D _               ' __in ID3D10Texture2D *pSrcTexture
 , BYVAL Flags AS DWORD _                               ' __in UINT            Flags
 , BYVAL Channel AS DWORD _                             ' __in UINT            Channel
 , BYVAL Amplitude AS SINGLE _                          ' __in FLOAT           Amplitude
 , BYVAL pDestTexture AS ID3D10Texture2D _              ' __in ID3D10Texture2D *pDestTexture
 ) AS LONG                                              ' HRESULT

'//----------------------------------------------------------------------------
'// D3DX10SHProjectCubeMap:
'// ----------------------
'//  Projects a function represented in a cube map into spherical harmonics.
'//
'//  Parameters:
'//   Order
'//      Order of the SH evaluation, generates Order^2 coefs, degree is Order-1
'//   pCubeMap
'//      CubeMap that is going to be projected into spherical harmonics
'//   pROut
'//      Output SH vector for Red.
'//   pGOut
'//      Output SH vector for Green
'//   pBOut
'//      Output SH vector for Blue
'//
'//---------------------------------------------------------------------------

DECLARE FUNCTION D3DX10SHProjectCubeMap IMPORT $D3DX10_DLLNAME ALIAS "D3DX10SHProjectCubeMap" ( _
   BYVAL Order AS DWORD _                               ' __in  UINT            Order
 , BYVAL pCubeMap AS ID3D10Texture2D _                  ' __in  ID3D10Texture2D *pCubeMap
 , BYREF pROut AS SINGLE _                              ' __out FLOAT           *pROut
 , BYREF pGOut AS SINGLE _                              ' __out FLOAT           *pGOut
 , BYREF pBOut AS SINGLE _                              ' __out FLOAT           *pBOut
 ) AS LONG                                              ' HRESULT
