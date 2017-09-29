' ########################################################################################
' Microsoft Windows
' File: d3dx9tex.inc
' Contents: D3DX texturing APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3DX9TEX_INC = 1

#INCLUDE ONCE "d3dx9.inc"

'//----------------------------------------------------------------------------
'// D3DX_FILTER flags:
'// ------------------
'//
'// A valid filter must contain one of these values:
'//
'//  D3DX_FILTER_NONE
'//      No scaling or filtering will take place.  Pixels outside the bounds
'//      of the source image are assumed to be transparent black.
'//  D3DX_FILTER_POINT
'//      Each destination pixel is computed by sampling the nearest pixel
'//      from the source image.
'//  D3DX_FILTER_LINEAR
'//      Each destination pixel is computed by linearly interpolating between
'//      the nearest pixels in the source image.  This filter works best
'//      when the scale on each axis is less than 2.
'//  D3DX_FILTER_TRIANGLE
'//      Every pixel in the source image contributes equally to the
'//      destination image.  This is the slowest of all the filters.
'//  D3DX_FILTER_BOX
'//      Each pixel is computed by averaging a 2x2(x2) box pixels from
'//      the source image. Only works when the dimensions of the
'//      destination are half those of the source. (as with mip maps)
'//
'// And can be OR'd with any of these optional flags:
'//
'//  D3DX_FILTER_MIRROR_U
'//      Indicates that pixels off the edge of the texture on the U-axis
'//      should be mirrored, not wraped.
'//  D3DX_FILTER_MIRROR_V
'//      Indicates that pixels off the edge of the texture on the V-axis
'//      should be mirrored, not wraped.
'//  D3DX_FILTER_MIRROR_W
'//      Indicates that pixels off the edge of the texture on the W-axis
'//      should be mirrored, not wraped.
'//  D3DX_FILTER_MIRROR
'//      Same as specifying D3DX_FILTER_MIRROR_U | D3DX_FILTER_MIRROR_V |
'//      D3DX_FILTER_MIRROR_V
'//  D3DX_FILTER_DITHER
'//      Dithers the resulting image using a 4x4 order dither pattern.
'//  D3DX_FILTER_SRGB_IN
'//      Denotes that the input data is in sRGB (gamma 2.2) colorspace.
'//  D3DX_FILTER_SRGB_OUT
'//      Denotes that the output data is in sRGB (gamma 2.2) colorspace.
'//  D3DX_FILTER_SRGB
'//      Same as specifying D3DX_FILTER_SRGB_IN | D3DX_FILTER_SRGB_OUT
'//
'//----------------------------------------------------------------------------

%D3DX_FILTER_NONE             = 1???          ' (1 << 0)
%D3DX_FILTER_POINT            = 2???          ' (2 << 0)
%D3DX_FILTER_LINEAR           = 3???          ' (3 << 0)
%D3DX_FILTER_TRIANGLE         = 4???          ' (4 << 0)
%D3DX_FILTER_BOX              = 5???          ' (5 << 0)

%D3DX_FILTER_MIRROR_U         = &H10000???    ' (1 << 16)
%D3DX_FILTER_MIRROR_V         = &H20000???    ' (2 << 16)
%D3DX_FILTER_MIRROR_W         = &H40000???    ' (4 << 16)
%D3DX_FILTER_MIRROR           = &H70000???    ' (7 << 16)

%D3DX_FILTER_DITHER           = &H80000???    ' (1 << 19)
%D3DX_FILTER_DITHER_DIFFUSION = &H100000???   ' (2 << 19)

%D3DX_FILTER_SRGB_IN          = &H200000???   ' (1 << 21)
%D3DX_FILTER_SRGB_OUT         = &H400000???   ' (2 << 21)
%D3DX_FILTER_SRGB             = &H600000???   ' (3 << 21)

'//-----------------------------------------------------------------------------
'// D3DX_SKIP_DDS_MIP_LEVELS is used to skip mip levels when loading a DDS file:
'//-----------------------------------------------------------------------------

%D3DX_SKIP_DDS_MIP_LEVELS_MASK   = &H1F
%D3DX_SKIP_DDS_MIP_LEVELS_SHIFT  = 26

'#define D3DX_SKIP_DDS_MIP_LEVELS(levels, filter) ((((levels) & D3DX_SKIP_DDS_MIP_LEVELS_MASK) << D3DX_SKIP_DDS_MIP_LEVELS_SHIFT) | ((filter) == D3DX_DEFAULT ? D3DX_FILTER_BOX : (filter)))

'//----------------------------------------------------------------------------
'// D3DX_NORMALMAP flags:
'// ---------------------
'// These flags are used to control how D3DXComputeNormalMap generates normal
'// maps.  Any number of these flags may be OR'd together in any combination.
'//
'//  D3DX_NORMALMAP_MIRROR_U
'//      Indicates that pixels off the edge of the texture on the U-axis
'//      should be mirrored, not wraped.
'//  D3DX_NORMALMAP_MIRROR_V
'//      Indicates that pixels off the edge of the texture on the V-axis
'//      should be mirrored, not wraped.
'//  D3DX_NORMALMAP_MIRROR
'//      Same as specifying D3DX_NORMALMAP_MIRROR_U | D3DX_NORMALMAP_MIRROR_V
'//  D3DX_NORMALMAP_INVERTSIGN
'//      Inverts the direction of each normal
'//  D3DX_NORMALMAP_COMPUTE_OCCLUSION
'//      Compute the per pixel Occlusion term and encodes it into the alpha.
'//      An Alpha of 1 means that the pixel is not obscured in anyway, and
'//      an alpha of 0 would mean that the pixel is completly obscured.
'//
'//----------------------------------------------------------------------------

%D3DX_NORMALMAP_MIRROR_U          = &H10000???    ' (1 << 16)
%D3DX_NORMALMAP_MIRROR_V          = &H20000???    ' (2 << 16)
%D3DX_NORMALMAP_MIRROR            = &H30000???    ' (3 << 16)
%D3DX_NORMALMAP_INVERTSIGN        = &H80000???    ' (8 << 16)
%D3DX_NORMALMAP_COMPUTE_OCCLUSION = &H100000???   ' (16 << 16)

'//----------------------------------------------------------------------------
'// D3DX_CHANNEL flags:
'// -------------------
'// These flags are used by functions which operate on or more channels
'// in a texture.
'//
'// D3DX_CHANNEL_RED
'//     Indicates the red channel should be used
'// D3DX_CHANNEL_BLUE
'//     Indicates the blue channel should be used
'// D3DX_CHANNEL_GREEN
'//     Indicates the green channel should be used
'// D3DX_CHANNEL_ALPHA
'//     Indicates the alpha channel should be used
'// D3DX_CHANNEL_LUMINANCE
'//     Indicates the luminaces of the red green and blue channels should be
'//     used.
'//
'//----------------------------------------------------------------------------

%D3DX_CHANNEL_RED         = 1???    ' (1 << 0)
%D3DX_CHANNEL_BLUE        = 2???    ' (1 << 1)
%D3DX_CHANNEL_GREEN       = 4???    ' (1 << 2)
%D3DX_CHANNEL_ALPHA       = 8???    ' (1 << 3)
%D3DX_CHANNEL_LUMINANCE   = 10???   ' (1 << 4)


'//----------------------------------------------------------------------------
'// D3DXIMAGE_FILEFORMAT:
'// ---------------------
'// This enum is used to describe supported image file formats.
'//
'//----------------------------------------------------------------------------

%D3DXIFF_BMP         = 0???
%D3DXIFF_JPG         = 1???
%D3DXIFF_TGA         = 2???
%D3DXIFF_PNG         = 3???
%D3DXIFF_DDS         = 4???
%D3DXIFF_PPM         = 5???
%D3DXIFF_DIB         = 6???
%D3DXIFF_HDR         = 7???      ' //high dynamic range formats
%D3DXIFF_PFM         = 8???
%D3DXIFF_FORCE_DWORD = &H7FFFFFFF???


'//----------------------------------------------------------------------------
'// LPD3DXFILL2D and LPD3DXFILL3D:
'// ------------------------------
'// Function types used by the texture fill functions.
'//
'// Parameters:
'//  pOut
'//      Pointer to a vector which the function uses to return its result.
'//      X,Y,Z,W will be mapped to R,G,B,A respectivly.
'//  pTexCoord
'//      Pointer to a vector containing the coordinates of the texel currently
'//      being evaluated.  Textures and VolumeTexture texcoord components
'//      range from 0 to 1. CubeTexture texcoord component range from -1 to 1.
'//  pTexelSize
'//      Pointer to a vector containing the dimensions of the current texel.
'//  pData
'//      Pointer to user data.
'//
'//----------------------------------------------------------------------------

'typedef VOID (WINAPI *LPD3DXFILL2D)(D3DXVECTOR4 *pOut,
'    CONST D3DXVECTOR2 *pTexCoord, CONST D3DXVECTOR2 *pTexelSize, LPVOID pData);

' Prototype for the LPD3DXFILL2D callback function
' You need to declare a procedure like this one in your program and pass its address
' (with CODEPTR(LPD3DXFILL2D) to the function that requires it.
'SUB LPD3DXFILL2D ( _
'    BYREF pOut AS D3DXVECTOR4, _
'    BYREF pTexCoord AS D3DXVECTOR2, _
'    BYREF pTexelSize AS D3DXVECTOR2, _
'    BYVAL pData AS DWORD)
'END SUB

'typedef VOID (WINAPI *LPD3DXFILL3D)(D3DXVECTOR4 *pOut,
'    CONST D3DXVECTOR3 *pTexCoord, CONST D3DXVECTOR3 *pTexelSize, LPVOID pData);

' Prototype for the LPD3DXFILL3D callback function
' You need to declare a procedure like this one in your program and pass its address
' (with CODEPTR(LPD3DXFILL3D) to the function that requires it.
'SUB LPD3DXFILL3D ( _
'    BYREF pOut AS D3DXVECTOR4, _
'    BYREF pTexCoord AS D3DXVECTOR3, _
'    BYREF pTexelSize AS D3DXVECTOR3, _
'    BYVAL pData AS DWORD)
'END SUB

'//----------------------------------------------------------------------------
'// D3DXIMAGE_INFO:
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
'//  MipLevels
'//      Number of mip levels in original image
'//  Format
'//      D3D format which most closely describes the data in original image
'//  ResourceType
'//      D3DRESOURCETYPE representing the type of texture stored in the file.
'//      D3DRTYPE_TEXTURE, D3DRTYPE_VOLUMETEXTURE, or D3DRTYPE_CUBETEXTURE.
'//  ImageFileFormat
'//      D3DXIMAGE_FILEFORMAT representing the format of the image file.
'//
'//----------------------------------------------------------------------------

' // Size = 28 bytes
TYPE D3DXIMAGE_INFO DWORD
   Width           AS DWORD   ' UINT
   Height          AS DWORD   ' UINT
   Depth           AS DWORD   ' UINT
   MipLevels       AS DWORD   ' UINT
   Format          AS DWORD   ' D3DFORMAT
   ResourceType    AS DWORD   ' D3DRESOURCETYPE
   ImageFileFormat AS DWORD   ' D3DXIMAGE_FILEFORMAT
END TYPE


'//////////////////////////////////////////////////////////////////////////////
'// Image File APIs ///////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////
';
'//----------------------------------------------------------------------------
'// GetImageInfoFromFile/Resource:
'// ------------------------------
'// Fills in a D3DXIMAGE_INFO struct with information about an image file.
'//
'// Parameters:
'//  pSrcFile
'//      File name of the source image.
'//  pSrcModule
'//      Module where resource is located, or NULL for module associated
'//      with image the os used to create the current process.
'//  pSrcResource
'//      Resource name
'//  pSrcData
'//      Pointer to file in memory.
'//  SrcDataSize
'//      Size in bytes of file in memory.
'//  pSrcInfo
'//      Pointer to a D3DXIMAGE_INFO structure to be filled in with the
'//      description of the data in the source image file.
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXGetImageInfoFromFileA IMPORT $D3DX_DLLNAME ALIAS "D3DXGetImageInfoFromFileA" (_
   BYREF pSrcFile AS ASCIIZ _                           ' __in LPCSTR              pSrcFile
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO* pSrcInfo
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXGetImageInfoFromFileW IMPORT $D3DX_DLLNAME ALIAS "D3DXGetImageInfoFromFileW" (_
   BYREF pSrcFile AS WSTRINGZ _                         ' __in LPCWSTR             pSrcFile
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO* pSrcInfo
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXGetImageInfoFromFile = D3DXGetImageInfoFromFileW
#ELSE
   MACRO D3DXGetImageInfoFromFile = D3DXGetImageInfoFromFileA
#ENDIF

DECLARE FUNCTION D3DXGetImageInfoFromResourceA IMPORT $D3DX_DLLNAME ALIAS "D3DXGetImageInfoFromResourceA" (_
   BYVAL hSrcModule AS DWORD _                          ' __in HMODULE             hSrcModule
 , BYREF pSrcResource AS ASCIIZ _                       ' __in LPCSTR              pSrcResource
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO* pSrcInfo
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXGetImageInfoFromResourceW IMPORT $D3DX_DLLNAME ALIAS "D3DXGetImageInfoFromResourceW" (_
   BYVAL hSrcModule AS DWORD _                          ' __in HMODULE             hSrcModule
 , BYREF pSrcResource AS WSTRINGZ _                     ' __in LPCWSTR             pSrcResource
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO* pSrcInfo
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXGetImageInfoFromResource = D3DXGetImageInfoFromResourceW
#ELSE
   MACRO D3DXGetImageInfoFromResource = D3DXGetImageInfoFromResourceA
#ENDIF

DECLARE FUNCTION D3DXGetImageInfoFromFileInMemory IMPORT $D3DX_DLLNAME ALIAS "D3DXGetImageInfoFromFileInMemory" (_
   BYVAL pSrcData AS DWORD _                            ' __in LPCVOID             pSrcData
 , BYVAL SrcDataSize AS DWORD _                         ' __in UINT                SrcDataSize
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO* pSrcInfo
 ) AS LONG                                              ' HRESULT


'//////////////////////////////////////////////////////////////////////////////
'// Load/Save Surface APIs ////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

'//----------------------------------------------------------------------------
'// D3DXLoadSurfaceFromFile/Resource:
'// ---------------------------------
'// Load surface from a file or resource
'//
'// Parameters:
'//  pDestSurface
'//      Destination surface, which will receive the image.
'//  pDestPalette
'//      Destination palette of 256 colors, or NULL
'//  pDestRect
'//      Destination rectangle, or NULL for entire surface
'//  pSrcFile
'//      File name of the source image.
'//  pSrcModule
'//      Module where resource is located, or NULL for module associated
'//      with image the os used to create the current process.
'//  pSrcResource
'//      Resource name
'//  pSrcData
'//      Pointer to file in memory.
'//  SrcDataSize
'//      Size in bytes of file in memory.
'//  pSrcRect
'//      Source rectangle, or NULL for entire image
'//  Filter
'//      D3DX_FILTER flags controlling how the image is filtered.
'//      Or D3DX_DEFAULT for D3DX_FILTER_TRIANGLE.
'//  ColorKey
'//      Color to replace with transparent black, or 0 to disable colorkey.
'//      This is always a 32-bit ARGB color, independent of the source image
'//      format.  Alpha is significant, and should usually be set to FF for
'//      opaque colorkeys.  (ex. Opaque black == 0xff000000)
'//  pSrcInfo
'//      Pointer to a D3DXIMAGE_INFO structure to be filled in with the
'//      description of the data in the source image file, or NULL.
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXLoadSurfaceFromFileA IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadSurfaceFromFileA" (_
   BYVAL pDestSurface AS IDirect3DSurface9 _            ' __in LPDIRECT3DSURFACE9   pDestSurface
 , BYREF pDestPalette AS PALETTEENTRY _                 ' __in CONST PALETTEENTRY*  pDestPalette
 , BYREF pDestRect AS RECT _                            ' __in CONST RECT*          pDestRect
 , BYREF pSrcFile AS ASCIIZ _                           ' __in LPCSTR               pSrcFile
 , BYREF pSrcRect AS RECT _                             ' __in CONST RECT*          pSrcRect
 , BYVAL Filter AS DWORD _                              ' __in DWORD                Filter
 , BYVAL ColorKey AS DWORD _                            ' __in D3DCOLOR             ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO*  pSrcInfo
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXLoadSurfaceFromFileW IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadSurfaceFromFileW" (_
   BYVAL pDestSurface AS IDirect3DSurface9 _            ' __in LPDIRECT3DSURFACE9  pDestSurface
 , BYREF pDestPalette AS PALETTEENTRY _                 ' __in CONST PALETTEENTRY* pDestPalette
 , BYREF pDestRect AS RECT _                            ' __in CONST RECT*         pDestRect
 , BYREF pSrcFile AS WSTRINGZ _                         ' __in LPCWSTR             pSrcFile
 , BYREF pSrcRect AS RECT _                             ' __in CONST RECT*         pSrcRect
 , BYVAL Filter AS DWORD _                              ' __in DWORD               Filter
 , BYVAL ColorKey AS DWORD _                            ' __in D3DCOLOR            ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO* pSrcInfo
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXLoadSurfaceFromFile = D3DXLoadSurfaceFromFileW
#ELSE
   MACRO D3DXLoadSurfaceFromFile = D3DXLoadSurfaceFromFileA
#ENDIF

DECLARE FUNCTION D3DXLoadSurfaceFromResourceA IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadSurfaceFromResourceA" (_
   BYVAL pDestSurface AS IDirect3DSurface9 _            ' __in LPDIRECT3DSURFACE9  pDestSurface
 , BYREF pDestPalette AS PALETTEENTRY _                 ' __in CONST PALETTEENTRY* pDestPalette
 , BYREF pDestRect AS RECT _                            ' __in CONST RECT*         pDestRect
 , BYVAL hSrcModule AS DWORD _                          ' __in HMODULE             hSrcModule
 , BYREF pSrcResource AS ASCIIZ _                       ' __in LPCSTR              pSrcResource
 , BYREF pSrcRect AS RECT _                             ' __in CONST RECT*         pSrcRect
 , BYVAL Filter AS DWORD _                              ' __in DWORD               Filter
 , BYVAL ColorKey AS DWORD _                            ' __in D3DCOLOR            ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO* pSrcInfo
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXLoadSurfaceFromResourceW IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadSurfaceFromResourceW" (_
   BYVAL pDestSurface AS IDirect3DSurface9 _            ' __in LPDIRECT3DSURFACE9  pDestSurface
 , BYREF pDestPalette AS PALETTEENTRY _                 ' __in CONST PALETTEENTRY* pDestPalette
 , BYREF pDestRect AS RECT _                            ' __in CONST RECT*         pDestRect
 , BYVAL hSrcModule AS DWORD _                          ' __in HMODULE             hSrcModule
 , BYREF pSrcResource AS WSTRINGZ _                     ' __in LPCWSTR             pSrcResource
 , BYREF pSrcRect AS RECT _                             ' __in CONST RECT*         pSrcRect
 , BYVAL Filter AS DWORD _                              ' __in DWORD               Filter
 , BYVAL ColorKey AS DWORD _                            ' __in D3DCOLOR            ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO* pSrcInfo
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXLoadSurfaceFromResource = D3DXLoadSurfaceFromResourceW
#ELSE
   MACRO D3DXLoadSurfaceFromResource = D3DXLoadSurfaceFromResourceA
#ENDIF

DECLARE FUNCTION D3DXLoadSurfaceFromFileInMemory IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadSurfaceFromFileInMemory" (_
   BYVAL pDestSurface AS IDirect3DSurface9 _            ' __in LPDIRECT3DSURFACE9  pDestSurface
 , BYREF pDestPalette AS PALETTEENTRY _                 ' __in CONST PALETTEENTRY* pDestPalette
 , BYREF pDestRect AS RECT _                            ' __in CONST RECT*         pDestRect
 , BYVAL pSrcData AS DWORD _                            ' __in LPCVOID             pSrcData
 , BYVAL SrcDataSize AS DWORD _                         ' __in UINT                SrcDataSize
 , BYREF pSrcRect AS RECT _                             ' __in CONST RECT*         pSrcRect
 , BYVAL Filter AS DWORD _                              ' __in DWORD               Filter
 , BYVAL ColorKey AS DWORD _                            ' __in D3DCOLOR            ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO* pSrcInfo
 ) AS LONG                                              ' HRESULT


'//----------------------------------------------------------------------------
'// D3DXLoadSurfaceFromSurface:
'// ---------------------------
'// Load surface from another surface (with color conversion)
'//
'// Parameters:
'//  pDestSurface
'//      Destination surface, which will receive the image.
'//  pDestPalette
'//      Destination palette of 256 colors, or NULL
'//  pDestRect
'//      Destination rectangle, or NULL for entire surface
'//  pSrcSurface
'//      Source surface
'//  pSrcPalette
'//      Source palette of 256 colors, or NULL
'//  pSrcRect
'//      Source rectangle, or NULL for entire surface
'//  Filter
'//      D3DX_FILTER flags controlling how the image is filtered.
'//      Or D3DX_DEFAULT for D3DX_FILTER_TRIANGLE.
'//  ColorKey
'//      Color to replace with transparent black, or 0 to disable colorkey.
'//      This is always a 32-bit ARGB color, independent of the source image
'//      format.  Alpha is significant, and should usually be set to FF for
'//      opaque colorkeys.  (ex. Opaque black == 0xff000000)
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXLoadSurfaceFromSurface IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadSurfaceFromSurface" (_
   BYVAL pDestSurface AS IDirect3DSurface9 _            ' __in LPDIRECT3DSURFACE9  pDestSurface
 , BYREF pDestPalette AS PALETTEENTRY _                 ' __in CONST PALETTEENTRY* pDestPalette
 , BYREF pDestRect AS RECT _                            ' __in CONST RECT*         pDestRect
 , BYVAL pSrcSurface AS IDirect3DSurface9 _             ' __in LPDIRECT3DSURFACE9  pSrcSurface
 , BYREF pSrcPalette AS PALETTEENTRY _                  ' __in CONST PALETTEENTRY* pSrcPalette
 , BYREF pSrcRect AS RECT _                             ' __in CONST RECT*         pSrcRect
 , BYVAL Filter AS DWORD _                              ' __in DWORD               Filter
 , BYVAL ColorKey AS DWORD _                            ' __in D3DCOLOR            ColorKey
 ) AS LONG                                              ' HRESULT


'//----------------------------------------------------------------------------
'// D3DXLoadSurfaceFromMemory:
'// --------------------------
'// Load surface from memory.
'//
'// Parameters:
'//  pDestSurface
'//      Destination surface, which will receive the image.
'//  pDestPalette
'//      Destination palette of 256 colors, or NULL
'//  pDestRect
'//      Destination rectangle, or NULL for entire surface
'//  pSrcMemory
'//      Pointer to the top-left corner of the source image in memory
'//  SrcFormat
'//      Pixel format of the source image.
'//  SrcPitch
'//      Pitch of source image, in bytes.  For DXT formats, this number
'//      should represent the width of one row of cells, in bytes.
'//  pSrcPalette
'//      Source palette of 256 colors, or NULL
'//  pSrcRect
'//      Source rectangle.
'//  Filter
'//      D3DX_FILTER flags controlling how the image is filtered.
'//      Or D3DX_DEFAULT for D3DX_FILTER_TRIANGLE.
'//  ColorKey
'//      Color to replace with transparent black, or 0 to disable colorkey.
'//      This is always a 32-bit ARGB color, independent of the source image
'//      format.  Alpha is significant, and should usually be set to FF for
'//      opaque colorkeys.  (ex. Opaque black == 0xff000000)
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXLoadSurfaceFromMemory IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadSurfaceFromMemory" (_
   BYVAL pDestSurface AS IDirect3DSurface9 _            ' __in LPDIRECT3DSURFACE9  pDestSurface
 , BYREF pDestPalette AS PALETTEENTRY _                 ' __in CONST PALETTEENTRY* pDestPalette
 , BYREF pDestRect AS RECT _                            ' __in CONST RECT*         pDestRect
 , BYVAL pSrcMemory AS DWORD _                          ' __in LPCVOID             pSrcMemory
 , BYVAL SrcFormat AS DWORD _                           ' __in D3DFORMAT           SrcFormat
 , BYVAL SrcPitch AS DWORD _                            ' __in UINT                SrcPitch
 , BYREF pSrcPalette AS PALETTEENTRY _                  ' __in CONST PALETTEENTRY* pSrcPalette
 , BYREF pSrcRect AS RECT _                             ' __in CONST RECT*         pSrcRect
 , BYVAL Filter AS DWORD _                              ' __in DWORD               Filter
 , BYVAL ColorKey AS DWORD _                            ' __in D3DCOLOR            ColorKey
 ) AS LONG                                              ' HRESULT


'//----------------------------------------------------------------------------
'// D3DXSaveSurfaceToFile:
'// ----------------------
'// Save a surface to a image file.
'//
'// Parameters:
'//  pDestFile
'//      File name of the destination file
'//  DestFormat
'//      D3DXIMAGE_FILEFORMAT specifying file format to use when saving.
'//  pSrcSurface
'//      Source surface, containing the image to be saved
'//  pSrcPalette
'//      Source palette of 256 colors, or NULL
'//  pSrcRect
'//      Source rectangle, or NULL for the entire image
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXSaveSurfaceToFileA IMPORT $D3DX_DLLNAME ALIAS "D3DXSaveSurfaceToFileA" (_
   BYREF pDestFile AS ASCIIZ _                          ' __in LPCSTR               pDestFile
 , BYVAL DestFormat AS  DWORD _                         ' __in D3DXIMAGE_FILEFORMAT DestFormat
 , BYVAL pSrcSurface AS IDirect3DSurface9 _             ' __in LPDIRECT3DSURFACE9   pSrcSurface
 , BYREF pSrcPalette AS PALETTEENTRY _                  ' __in CONST PALETTEENTRY*  pSrcPalette
 , BYREF pSrcRect AS RECT _                             ' __in CONST RECT*          pSrcRect
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXSaveSurfaceToFileW IMPORT $D3DX_DLLNAME ALIAS "D3DXSaveSurfaceToFileW" (_
   BYREF pDestFile AS WSTRINGZ _                        ' __in LPCWSTR              pDestFile
 , BYVAL DestFormat AS DWORD _                          ' __in D3DXIMAGE_FILEFORMAT DestFormat
 , BYVAL pSrcSurface AS IDirect3DSurface9 _             ' __in LPDIRECT3DSURFACE9   pSrcSurface
 , BYREF pSrcPalette AS PALETTEENTRY _                  ' __in CONST PALETTEENTRY*  pSrcPalette
 , BYREF pSrcRect AS RECT _                             ' __in CONST RECT*          pSrcRect
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXSaveSurfaceToFile = D3DXSaveSurfaceToFileW
#ELSE
   MACRO D3DXSaveSurfaceToFile = D3DXSaveSurfaceToFileA
#ENDIF

'//----------------------------------------------------------------------------
'// D3DXSaveSurfaceToFileInMemory:
'// ----------------------
'// Save a surface to a image file.
'//
'// Parameters:
'//  ppDestBuf
'//      address of pointer to d3dxbuffer for returning data bits
'//  DestFormat
'//      D3DXIMAGE_FILEFORMAT specifying file format to use when saving.
'//  pSrcSurface
'//      Source surface, containing the image to be saved
'//  pSrcPalette
'//      Source palette of 256 colors, or NULL
'//  pSrcRect
'//      Source rectangle, or NULL for the entire image
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXSaveSurfaceToFileInMemory IMPORT $D3DX_DLLNAME ALIAS "D3DXSaveSurfaceToFileInMemory" (_
   BYREF ppDestBuf AS ID3DXBuffer _                     ' __our LPD3DXBUFFER*        ppDestBuf
 , BYVAL DestFormat AS DWORD _                          ' __in  D3DXIMAGE_FILEFORMAT DestFormat
 , BYVAL pSrcSurface AS IDirect3DSurface9 _             ' __in  LPDIRECT3DSURFACE9   pSrcSurface
 , BYREF pSrcPalette AS PALETTEENTRY _                  ' __in  CONST PALETTEENTRY*  pSrcPalette
 , BYREF pSrcRect AS RECT _                             ' __in  CONST RECT*          pSrcRect
 ) AS LONG                                              ' HRESULT


'//////////////////////////////////////////////////////////////////////////////
'// Load/Save Volume APIs /////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

'//----------------------------------------------------------------------------
'// D3DXLoadVolumeFromFile/Resource:
'// --------------------------------
'// Load volume from a file or resource
'//
'// Parameters:
'//  pDestVolume
'//      Destination volume, which will receive the image.
'//  pDestPalette
'//      Destination palette of 256 colors, or NULL
'//  pDestBox
'//      Destination box, or NULL for entire volume
'//  pSrcFile
'//      File name of the source image.
'//  pSrcModule
'//      Module where resource is located, or NULL for module associated
'//      with image the os used to create the current process.
'//  pSrcResource
'//      Resource name
'//  pSrcData
'//      Pointer to file in memory.
'//  SrcDataSize
'//      Size in bytes of file in memory.
'//  pSrcBox
'//      Source box, or NULL for entire image
'//  Filter
'//      D3DX_FILTER flags controlling how the image is filtered.
'//      Or D3DX_DEFAULT for D3DX_FILTER_TRIANGLE.
'//  ColorKey
'//      Color to replace with transparent black, or 0 to disable colorkey.
'//      This is always a 32-bit ARGB color, independent of the source image
'//      format.  Alpha is significant, and should usually be set to FF for
'//      opaque colorkeys.  (ex. Opaque black == 0xff000000)
'//  pSrcInfo
'//      Pointer to a D3DXIMAGE_INFO structure to be filled in with the
'//      description of the data in the source image file, or NULL.
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXLoadVolumeFromFileA IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadVolumeFromFileA" (_
   BYVAL pDestVolume AS IDirect3DVolume9 _              ' __in LPDIRECT3DVOLUME9   pDestVolume
 , BYREF pDestPalette AS PALETTEENTRY _                 ' __in CONST PALETTEENTRY* pDestPalette
 , BYREF pDestBox AS D3DBOX _                           ' __in CONST D3DBOX*       pDestBox
 , BYREF pSrcFile AS ASCIIZ _                           ' __in LPCSTR              pSrcFile
 , BYREF pSrcBox AS D3DBOX _                            ' __in CONST D3DBOX*       pSrcBox
 , BYVAL Filter AS DWORD _                              ' __in DWORD               Filter
 , BYVAL ColorKey AS DWORD _                            ' __in D3DCOLOR            ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO* pSrcInfo
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXLoadVolumeFromFileW IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadVolumeFromFileW" (_
   BYVAL pDestVolume AS IDirect3DVolume9 _              ' __in LPDIRECT3DVOLUME9   pDestVolume
 , BYREF pDestPalette AS PALETTEENTRY _                 ' __in CONST PALETTEENTRY* pDestPalette
 , BYREF pDestBox AS D3DBOX _                           ' __in CONST D3DBOX*       pDestBox
 , BYREF pSrcFile AS WSTRINGZ _                         ' __in LPCWSTR             pSrcFile
 , BYREF pSrcBox AS D3DBOX _                            ' __in CONST D3DBOX*       pSrcBox
 , BYVAL Filter AS DWORD _                              ' __in DWORD               Filter
 , BYVAL ColorKey AS DWORD _                            ' __in D3DCOLOR            ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO* pSrcInfo
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXLoadVolumeFromFile = D3DXLoadVolumeFromFileW
#ELSE
   MACRO D3DXLoadVolumeFromFile = D3DXLoadVolumeFromFileA
#ENDIF

DECLARE FUNCTION D3DXLoadVolumeFromResourceA IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadVolumeFromResourceA" (_
   BYVAL pDestVolume AS IDirect3DVolume9 _              ' __in LPDIRECT3DVOLUME9   pDestVolume
 , BYREF pDestPalette AS PALETTEENTRY _                 ' __in CONST PALETTEENTRY* pDestPalette
 , BYREF pDestBox AS D3DBOX _                           ' __in CONST D3DBOX*       pDestBox
 , BYVAL hSrcModule AS DWORD _                          ' __in HMODULE             hSrcModule
 , BYREF pSrcResource AS ASCIIZ _                       ' __in LPCSTR              pSrcResource
 , BYREF pSrcBox AS D3DBOX _                            ' __in CONST D3DBOX*       pSrcBox
 , BYVAL Filter AS DWORD _                              ' __in DWORD               Filter
 , BYVAL ColorKey AS DWORD _                            ' __in D3DCOLOR            ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO* pSrcInfo
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXLoadVolumeFromResourceW IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadVolumeFromResourceW" (_
   BYVAL pDestVolume AS IDirect3DVolume9 _              ' __in LPDIRECT3DVOLUME9   pDestVolume
 , BYREF pDestPalette AS PALETTEENTRY _                 ' __in CONST PALETTEENTRY* pDestPalette
 , BYREF pDestBox AS D3DBOX _                           ' __in CONST D3DBOX*       pDestBox
 , BYVAL hSrcModule AS DWORD _                          ' __in HMODULE             hSrcModule
 , BYREF pSrcResource AS WSTRINGZ _                     ' __in LPCWSTR             pSrcResource
 , BYREF pSrcBox AS D3DBOX _                            ' __in CONST D3DBOX*       pSrcBox
 , BYVAL Filter AS DWORD _                              ' __in DWORD               Filter
 , BYVAL ColorKey AS DWORD _                            ' __in D3DCOLOR            ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO* pSrcInfo
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXLoadVolumeFromResource = D3DXLoadVolumeFromResourceW
#ELSE
   MACRO D3DXLoadVolumeFromResource = D3DXLoadVolumeFromResourceA
#ENDIF

DECLARE FUNCTION D3DXLoadVolumeFromFileInMemory IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadVolumeFromFileInMemory" (_
   BYVAL pDestVolume AS IDirect3DVolume9 _              ' __in LPDIRECT3DVOLUME9   pDestVolume
 , BYREF pDestPalette AS PALETTEENTRY _                 ' __in CONST PALETTEENTRY* pDestPalette
 , BYREF pDestBox AS D3DBOX _                           ' __in CONST D3DBOX*       pDestBox
 , BYVAL pSrcData AS DWORD _                            ' __in LPCVOID             pSrcData
 , BYVAL SrcDataSize AS DWORD _                         ' __in UINT                SrcDataSize
 , BYREF pSrcBox AS D3DBOX _                            ' __in CONST D3DBOX*       pSrcBox
 , BYVAL Filter AS DWORD _                              ' __in DWORD               Filter
 , BYVAL ColorKey AS DWORD _                            ' __in D3DCOLOR            ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO* pSrcInfo
 ) AS LONG                                              ' HRESULT


'//----------------------------------------------------------------------------
'// D3DXLoadVolumeFromVolume:
'// -------------------------
'// Load volume from another volume (with color conversion)
'//
'// Parameters:
'//  pDestVolume
'//      Destination volume, which will receive the image.
'//  pDestPalette
'//      Destination palette of 256 colors, or NULL
'//  pDestBox
'//      Destination box, or NULL for entire volume
'//  pSrcVolume
'//      Source volume
'//  pSrcPalette
'//      Source palette of 256 colors, or NULL
'//  pSrcBox
'//      Source box, or NULL for entire volume
'//  Filter
'//      D3DX_FILTER flags controlling how the image is filtered.
'//      Or D3DX_DEFAULT for D3DX_FILTER_TRIANGLE.
'//  ColorKey
'//      Color to replace with transparent black, or 0 to disable colorkey.
'//      This is always a 32-bit ARGB color, independent of the source image
'//      format.  Alpha is significant, and should usually be set to FF for
'//      opaque colorkeys.  (ex. Opaque black == 0xff000000)
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXLoadVolumeFromVolume IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadVolumeFromVolume" (_
   BYVAL pDestVolume AS IDirect3DVolume9 _              ' __in LPDIRECT3DVOLUME9         pDestVolume
 , BYREF pDestPalette AS PALETTEENTRY _                 ' __in CONST PALETTEENTRY*       pDestPalette
 , BYREF pDestBox AS D3DBOX _                           ' __in CONST D3DBOX*             pDestBox
 , BYVAL pSrcVolume AS IUnknown _                       ' __in LPDIRECT3DVOLUME9         pSrcVolume
 , BYREF pSrcPalette AS PALETTEENTRY _                  ' __in CONST PALETTEENTRY*       pSrcPalette
 , BYREF pSrcBox AS D3DBOX _                            ' __in CONST D3DBOX*             pSrcBox
 , BYVAL Filter AS DWORD _                              ' __in DWORD                     Filter
 , BYVAL ColorKey AS DWORD _                            ' __in D3DCOLOR                  ColorKey
 ) AS LONG                                              ' HRESULT


'//----------------------------------------------------------------------------
'// D3DXLoadVolumeFromMemory:
'// -------------------------
'// Load volume from memory.
'//
'// Parameters:
'//  pDestVolume
'//      Destination volume, which will receive the image.
'//  pDestPalette
'//      Destination palette of 256 colors, or NULL
'//  pDestBox
'//      Destination box, or NULL for entire volume
'//  pSrcMemory
'//      Pointer to the top-left corner of the source volume in memory
'//  SrcFormat
'//      Pixel format of the source volume.
'//  SrcRowPitch
'//      Pitch of source image, in bytes.  For DXT formats, this number
'//      should represent the size of one row of cells, in bytes.
'//  SrcSlicePitch
'//      Pitch of source image, in bytes.  For DXT formats, this number
'//      should represent the size of one slice of cells, in bytes.
'//  pSrcPalette
'//      Source palette of 256 colors, or NULL
'//  pSrcBox
'//      Source box.
'//  Filter
'//      D3DX_FILTER flags controlling how the image is filtered.
'//      Or D3DX_DEFAULT for D3DX_FILTER_TRIANGLE.
'//  ColorKey
'//      Color to replace with transparent black, or 0 to disable colorkey.
'//      This is always a 32-bit ARGB color, independent of the source image
'//      format.  Alpha is significant, and should usually be set to FF for
'//      opaque colorkeys.  (ex. Opaque black == 0xff000000)
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXLoadVolumeFromMemory IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadVolumeFromMemory" (_
   BYVAL pDestVolume AS IDirect3DVolume9 _              ' __in LPDIRECT3DVOLUME9         pDestVolume
 , BYREF pDestPalette AS PALETTEENTRY _                 ' __in CONST PALETTEENTRY*       pDestPalette
 , BYREF pDestBox AS D3DBOX _                           ' __in CONST D3DBOX*             pDestBox
 , BYVAL pSrcMemory AS DWORD _                          ' __in LPCVOID                   pSrcMemory
 , BYVAL SrcFormat AS DWORD _                           ' __in D3DFORMAT                 SrcFormat
 , BYVAL SrcRowPitch AS DWORD _                         ' __in UINT                      SrcRowPitch
 , BYVAL SrcSlicePitch AS DWORD _                       ' __in UINT                      SrcSlicePitch
 , BYREF pSrcPalette AS PALETTEENTRY _                  ' __in CONST PALETTEENTRY*       pSrcPalette
 , BYREF pSrcBox AS D3DBOX _                            ' __in CONST D3DBOX*             pSrcBox
 , BYVAL Filter AS DWORD _                              ' __in DWORD                     Filter
 , BYVAL ColorKey AS DWORD _                            ' __in D3DCOLOR                  ColorKey
 ) AS LONG                                              ' HRESULT


'//----------------------------------------------------------------------------
'// D3DXSaveVolumeToFile:
'// ---------------------
'// Save a volume to a image file.
'//
'// Parameters:
'//  pDestFile
'//      File name of the destination file
'//  DestFormat
'//      D3DXIMAGE_FILEFORMAT specifying file format to use when saving.
'//  pSrcVolume
'//      Source volume, containing the image to be saved
'//  pSrcPalette
'//      Source palette of 256 colors, or NULL
'//  pSrcBox
'//      Source box, or NULL for the entire volume
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXSaveVolumeToFileA IMPORT $D3DX_DLLNAME ALIAS "D3DXSaveVolumeToFileA" (_
   BYREF pDestFile AS ASCIIZ _                          ' __in LPCSTR               pDestFile
 , BYVAL DestFormat AS DWORD _                          ' __in D3DXIMAGE_FILEFORMAT DestFormat
 , BYVAL pSrcVolume AS IDirect3DVolume9 _               ' __in LPDIRECT3DVOLUME9    pSrcVolume
 , BYREF pSrcPalette AS PALETTEENTRY _                  ' __in CONST PALETTEENTRY*  pSrcPalette
 , BYREF pSrcBox AS D3DBOX _                            ' __in CONST D3DBOX*        pSrcBox
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXSaveVolumeToFileW IMPORT $D3DX_DLLNAME ALIAS "D3DXSaveVolumeToFileW" (_
   BYREF pDestFile AS WSTRINGZ _                        ' __in LPCWSTR              pDestFile
 , BYVAL DestFormat AS DWORD _                          ' __in D3DXIMAGE_FILEFORMAT DestFormat
 , BYVAL pSrcVolume AS IDirect3DVolume9 _               ' __in LPDIRECT3DVOLUME9    pSrcVolume
 , BYREF pSrcPalette AS PALETTEENTRY _                  ' __in CONST PALETTEENTRY*  pSrcPalette
 , BYREF pSrcBox AS D3DBOX _                            ' __in CONST D3DBOX*        pSrcBox
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXSaveVolumeToFile = D3DXSaveVolumeToFileW
#ELSE
   MACRO D3DXSaveVolumeToFile = D3DXSaveVolumeToFileA
#ENDIF

'//----------------------------------------------------------------------------
'// D3DXSaveVolumeToFileInMemory:
'// ---------------------
'// Save a volume to a image file.
'//
'// Parameters:
'//  pDestFile
'//      File name of the destination file
'//  DestFormat
'//      D3DXIMAGE_FILEFORMAT specifying file format to use when saving.
'//  pSrcVolume
'//      Source volume, containing the image to be saved
'//  pSrcPalette
'//      Source palette of 256 colors, or NULL
'//  pSrcBox
'//      Source box, or NULL for the entire volume
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXSaveVolumeToFileInMemory IMPORT $D3DX_DLLNAME ALIAS "D3DXSaveVolumeToFileInMemory" (_
   BYREF ppDestBuf AS ID3DXBuffer _                     ' __out LPD3DXBUFFER*        ppDestBuf
 , BYVAL DestFormat AS DWORD _                          ' __in  D3DXIMAGE_FILEFORMAT DestFormat
 , BYVAL pSrcVolume AS IDirect3DVolume9 _               ' __in  LPDIRECT3DVOLUME9    pSrcVolume
 , BYREF pSrcPalette AS PALETTEENTRY _                  ' __in  CONST PALETTEENTRY*  pSrcPalette
 , BYREF pSrcBox AS D3DBOX _                            ' __in  CONST D3DBOX*        pSrcBox
 ) AS LONG                                              ' HRESULT


'//////////////////////////////////////////////////////////////////////////////
'// Create/Save Texture APIs //////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

'//----------------------------------------------------------------------------
'// D3DXCheckTextureRequirements:
'// -----------------------------
'// Checks texture creation parameters.  If parameters are invalid, this
'// function returns corrected parameters.
'//
'// Parameters:
'//
'//  pDevice
'//      The D3D device to be used
'//  pWidth, pHeight, pDepth, pSize
'//      Desired size in pixels, or NULL.  Returns corrected size.
'//  pNumMipLevels
'//      Number of desired mipmap levels, or NULL.  Returns corrected number.
'//  Usage
'//      Texture usage flags
'//  pFormat
'//      Desired pixel format, or NULL.  Returns corrected format.
'//  Pool
'//      Memory pool to be used to create texture
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXCheckTextureRequirements IMPORT $D3DX_DLLNAME ALIAS "D3DXCheckTextureRequirements" (_
   BYVAL pDevice AS IDirect3DDevice9  _                 ' __in LPDIRECT3DDEVICE9 pDevice
 , BYREF pWidth AS DWORD _                              ' __in_out UINT*         pWidth
 , BYREF pHeight AS DWORD _                             ' __in_out UINT*         pHeight
 , BYREF pNumMipLevels AS DWORD _                       ' __in_out UINT*         pNumMipLevels
 , BYVAL Usage AS DWORD _                               ' __in DWORD             Usage
 , BYREF pFormat AS DWORD _                             ' __in_out D3DFORMAT*    pFormat
 , BYVAL Pool AS DWORD _                                ' __in D3DPOOL           Pool
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCheckCubeTextureRequirements IMPORT $D3DX_DLLNAME ALIAS "D3DXCheckCubeTextureRequirements" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in LPDIRECT3DDEVICE9 pDevice
 , BYREF pSize AS DWORD _                               ' __in_out UINT*         pSize
 , BYREF pNumMipLevels AS DWORD _                       ' __in_out UINT*         pNumMipLevels
 , BYVAL Usage AS DWORD _                               ' __in DWORD             Usage
 , BYREF pFormat AS DWORD _                             ' __in_out D3DFORMAT*    pFormat
 , BYVAL Pool AS DWORD _                                ' __in D3DPOOL           Pool
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCheckVolumeTextureRequirements IMPORT $D3DX_DLLNAME ALIAS "D3DXCheckVolumeTextureRequirements" (_
   BYVAL pDevice AS IDirect3DDevice9  _                 ' __in LPDIRECT3DDEVICE9 pDevice
 , BYREF pWidth AS DWORD _                              ' __in_out UINT*         pWidth
 , BYREF pHeight AS DWORD _                             ' __in_out UINT*         pHeight
 , BYREF pDepth AS DWORD _                              ' __in_out UINT*         pDepth
 , BYREF pNumMipLevels AS DWORD _                       ' __in_out UINT*         pNumMipLevels
 , BYVAL Usage AS DWORD _                               ' __in DWORD             Usage
 , BYREF pFormat AS DWORD _                             ' __in_out D3DFORMAT*    pFormat
 , BYVAL Pool AS DWORD _                                ' __in D3DPOOL           Pool
 ) AS LONG                                              ' HRESULT


'//----------------------------------------------------------------------------
'// D3DXCreateTexture:
'// ------------------
'// Create an empty texture
'//
'// Parameters:
'//
'//  pDevice
'//      The D3D device with which the texture is going to be used.
'//  Width, Height, Depth, Size
'//      size in pixels. these must be non-zero
'//  MipLevels
'//      number of mip levels desired. if zero or D3DX_DEFAULT, a complete
'//      mipmap chain will be created.
'//  Usage
'//      Texture usage flags
'//  Format
'//      Pixel format.
'//  Pool
'//      Memory pool to be used to create texture
'//  ppTexture, ppCubeTexture, ppVolumeTexture
'//      The texture object that will be created
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXCreateTexture IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateTexture" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9   pDevice
 , BYVAL Width AS DWORD _                               ' __in  UINT                Width
 , BYVAL Height AS DWORD _                              ' __in  UINT                Height
 , BYVAL MipLevels AS DWORD _                           ' __in  UINT                MipLevels
 , BYVAL Usage AS DWORD _                               ' __in  DWORD               Usage
 , BYVAL Format AS DWORD _                              ' __in  D3DFORMAT           Format
 , BYVAL Pool AS DWORD _                                ' __in  D3DPOOL             Pool
 , BYREF ppTexture AS IDirect3DTexture9 _               ' __out LPDIRECT3DTEXTURE9* ppTexture
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateCubeTexture IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateCubeTexture" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9       pDevice
 , BYVAL Size AS DWORD _                                ' __in  UINT                    Size
 , BYVAL MipLevels AS DWORD _                           ' __in  UINT                    MipLevels
 , BYVAL Usage AS DWORD _                               ' __in  DWORD                   Usage
 , BYVAL Format AS DWORD _                              ' __in  D3DFORMAT               Format
 , BYVAL Pool AS DWORD _                                ' __in  D3DPOOL                 Pool
 , BYREF ppCubeTexture AS IDirect3DCubeTexture9 _       ' __out LPDIRECT3DCUBETEXTURE9* ppCubeTexture
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateVolumeTexture IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateVolumeTexture" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9         pDevice
 , BYVAL Width AS DWORD _                               ' __in  UINT                      Width
 , BYVAL Height AS DWORD _                              ' __in  UINT                      Height
 , BYVAL Depth AS DWORD _                               ' __in  UINT                      Depth
 , BYVAL MipLevels AS DWORD _                           ' __in  UINT                      MipLevels
 , BYVAL Usage AS DWORD _                               ' __in  DWORD                     Usage
 , BYVAL Format AS DWORD _                              ' __in  D3DFORMAT                 Format
 , BYVAL Pool AS DWORD _                                ' __in  D3DPOOL                   Pool
 , BYREF ppVolumeTexture AS IDirect3DVolumeTexture9 _   ' __out LPDIRECT3DVOLUMETEXTURE9* ppVolumeTexture
 ) AS LONG                                              ' HRESULT


'//----------------------------------------------------------------------------
'// D3DXCreateTextureFromFile/Resource:
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
'//  Width, Height, Depth, Size
'//      Size in pixels.  If zero or D3DX_DEFAULT, the size will be taken from
'//      the file and rounded up to a power of two.  If D3DX_DEFAULT_NONPOW2,
'//      and the device supports NONPOW2 textures, the size will not be rounded.
'//      If D3DX_FROM_FILE, the size will be taken exactly as it is in the file,
'//      and the call will fail if this violates device capabilities.
'//  MipLevels
'//      Number of mip levels.  If zero or D3DX_DEFAULT, a complete mipmap
'//      chain will be created.  If D3DX_FROM_FILE, the size will be taken
'//      exactly as it is in the file, and the call will fail if this violates
'//      device capabilities.
'//  Usage
'//      Texture usage flags
'//  Format
'//      Desired pixel format.  If D3DFMT_UNKNOWN, the format will be
'//      taken from the file.  If D3DFMT_FROM_FILE, the format will be taken
'//      exactly as it is in the file, and the call will fail if the device does
'//      not support the given format.
'//  Pool
'//      Memory pool to be used to create texture
'//  Filter
'//      D3DX_FILTER flags controlling how the image is filtered.
'//      Or D3DX_DEFAULT for D3DX_FILTER_TRIANGLE.
'//  MipFilter
'//      D3DX_FILTER flags controlling how each miplevel is filtered.
'//      Or D3DX_DEFAULT for D3DX_FILTER_BOX,
'//  ColorKey
'//      Color to replace with transparent black, or 0 to disable colorkey.
'//      This is always a 32-bit ARGB color, independent of the source image
'//      format.  Alpha is significant, and should usually be set to FF for
'//      opaque colorkeys.  (ex. Opaque black == 0xff000000)
'//  pSrcInfo
'//      Pointer to a D3DXIMAGE_INFO structure to be filled in with the
'//      description of the data in the source image file, or NULL.
'//  pPalette
'//      256 color palette to be filled in, or NULL
'//  ppTexture, ppCubeTexture, ppVolumeTexture
'//      The texture object that will be created
'//
'//----------------------------------------------------------------------------


'// FromFile

DECLARE FUNCTION D3DXCreateTextureFromFileA IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateTextureFromFileA" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9   pDevice
 , BYREF pSrcFile AS ASCIIZ _                           ' __in  LPCSTR              pSrcFile
 , BYREF ppTexture AS IDirect3DTexture9 _               ' __out LPDIRECT3DTEXTURE9* ppTexture
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateTextureFromFileW IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateTextureFromFileW" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9   pDevice
 , BYREF pSrcFile AS WSTRINGZ _                         ' __in  LPCWSTR             pSrcFile
 , BYREF ppTexture AS IDirect3DTexture9 _               ' __out LPDIRECT3DTEXTURE9* ppTexture
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXCreateTextureFromFile = D3DXCreateTextureFromFileW
#ELSE
   MACRO D3DXCreateTextureFromFile = D3DXCreateTextureFromFileA
#ENDIF

DECLARE FUNCTION D3DXCreateCubeTextureFromFileA IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateCubeTextureFromFileA" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9       pDevice
 , BYREF pSrcFile AS ASCIIZ _                           ' __in  LPCSTR                  pSrcFile
 , BYREF ppCubeTexture AS IDirect3DCubeTexture9 _       ' __out LPDIRECT3DCUBETEXTURE9* ppCubeTexture
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateCubeTextureFromFileW IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateCubeTextureFromFileW" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9       pDevice
 , BYREF pSrcFile AS WSTRINGZ _                         ' __in  LPCWSTR                 pSrcFile
 , BYREF ppCubeTexture AS IDirect3DCubeTexture9 _       ' __out LPDIRECT3DCUBETEXTURE9* ppCubeTexture
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXCreateCubeTextureFromFile = D3DXCreateCubeTextureFromFileW
#ELSE
   MACRO D3DXCreateCubeTextureFromFile = D3DXCreateCubeTextureFromFileA
#ENDIF

DECLARE FUNCTION D3DXCreateVolumeTextureFromFileA IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateVolumeTextureFromFileA" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9         pDevice
 , BYREF pSrcFile AS ASCIIZ _                           ' __in  LPCSTR                    pSrcFile
 , BYREF ppVolumeTexture AS IDirect3DVolumeTexture9 _   ' __out LPDIRECT3DVOLUMETEXTURE9* ppVolumeTexture
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateVolumeTextureFromFileW IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateVolumeTextureFromFileW" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9         pDevice
 , BYREF pSrcFile AS WSTRINGZ _                         ' __in  LPCWSTR                   pSrcFile
 , BYREF ppVolumeTexture AS IDirect3DVolumeTexture9 _   ' __out LPDIRECT3DVOLUMETEXTURE9* ppVolumeTexture
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXCreateVolumeTextureFromFile = D3DXCreateVolumeTextureFromFileW
#ELSE
   MACRO D3DXCreateVolumeTextureFromFile = D3DXCreateVolumeTextureFromFileA
#ENDIF

'// FromResource

DECLARE FUNCTION D3DXCreateTextureFromResourceA IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateTextureFromResourceA" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9   pDevice
 , BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE             hSrcModule
 , BYREF pSrcResource AS ASCIIZ _                       ' __in  LPCSTR              pSrcResource
 , BYREF ppTexture AS IDirect3DTexture9 _               ' __out LPDIRECT3DTEXTURE9* ppTexture
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateTextureFromResourceW IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateTextureFromResourceW" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9   pDevice
 , BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE             hSrcModule
 , BYREF pSrcResource AS WSTRINGZ _                     ' __in  LPCWSTR             pSrcResource
 , BYREF ppTexture AS IDirect3DTexture9 _               ' __out LPDIRECT3DTEXTURE9* ppTexture
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXCreateTextureFromResource = D3DXCreateTextureFromResourceW
#ELSE
   MACRO D3DXCreateTextureFromResource = D3DXCreateTextureFromResourceA
#ENDIF

DECLARE FUNCTION D3DXCreateCubeTextureFromResourceA IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateCubeTextureFromResourceA" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9       pDevice
 , BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE                 hSrcModule
 , BYREF pSrcResource AS ASCIIZ _                       ' __in  LPCSTR                  pSrcResource
 , BYREF ppCubeTexture AS IDirect3DCubeTexture9 _       ' __out LPDIRECT3DCUBETEXTURE9* ppCubeTexture
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateCubeTextureFromResourceW IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateCubeTextureFromResourceW" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9       pDevice
 , BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE                 hSrcModule
 , BYREF pSrcResource AS WSTRINGZ _                     ' __in  LPCWSTR                 pSrcResource
 , BYREF ppCubeTexture AS IDirect3DCubeTexture9 _       ' __out LPDIRECT3DCUBETEXTURE9* ppCubeTexture
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXCreateCubeTextureFromResource = D3DXCreateCubeTextureFromResourceW
#ELSE
   MACRO D3DXCreateCubeTextureFromResource = D3DXCreateCubeTextureFromResourceA
#ENDIF

DECLARE FUNCTION D3DXCreateVolumeTextureFromResourceA IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateVolumeTextureFromResourceA" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9         pDevice
 , BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE                   hSrcModule
 , BYREF pSrcResource AS ASCIIZ _                       ' __in  LPCSTR                    pSrcResource
 , BYREF ppVolumeTexture AS IDirect3DVolumeTexture9 _   ' __out LPDIRECT3DVOLUMETEXTURE9* ppVolumeTexture
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateVolumeTextureFromResourceW IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateVolumeTextureFromResourceW" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9         pDevice
 , BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE                   hSrcModule
 , BYREF pSrcResource AS WSTRINGZ _                     ' __in  LPCWSTR                   pSrcResource
 , BYREF ppVolumeTexture AS IDirect3DVolumeTexture9 _   ' __out LPDIRECT3DVOLUMETEXTURE9* ppVolumeTexture
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXCreateVolumeTextureFromResource = D3DXCreateVolumeTextureFromResourceW
#ELSE
   MACRO D3DXCreateVolumeTextureFromResource = D3DXCreateVolumeTextureFromResourceA
#ENDIF

'// FromFileEx

DECLARE FUNCTION D3DXCreateTextureFromFileExA IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateTextureFromFileExA" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9   pDevice
 , BYREF pSrcFile AS ASCIIZ _                           ' __in  LPCSTR              pSrcFile
 , BYVAL Width AS DWORD _                               ' __in  UINT                Width
 , BYVAL Height AS DWORD _                              ' __in  UINT                Height
 , BYVAL MipLevels AS DWORD _                           ' __in  UINT                MipLevels
 , BYVAL Usage AS DWORD _                               ' __in  DWORD               Usage
 , BYVAL Format AS DWORD _                              ' __in  D3DFORMAT           Format
 , BYVAL Pool AS DWORD _                                ' __in  D3DPOOL             Pool
 , BYVAL Filter AS DWORD _                              ' __in  DWORD               Filter
 , BYVAL MipFilter AS DWORD _                           ' __in  DWORD               MipFilter
 , BYVAL ColorKey AS DWORD _                            ' __in  D3DCOLOR            ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO*  pSrcInfo
 , BYREF pPalette AS PALETTEENTRY _                     ' __out PALETTEENTRY*       pPalette
 , BYREF ppTexture AS IDirect3DTexture9 _               ' __out LPDIRECT3DTEXTURE9* ppTexture
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateTextureFromFileExW IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateTextureFromFileExW" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9   pDevice
 , BYREF pSrcFile AS WSTRINGZ _                         ' __in  LPCWSTR             pSrcFile
 , BYVAL Width AS DWORD _                               ' __in  UINT                Width
 , BYVAL Height AS DWORD _                              ' __in  UINT                Height
 , BYVAL MipLevels AS DWORD _                           ' __in  UINT                MipLevels
 , BYVAL Usage AS DWORD _                               ' __in  DWORD               Usage
 , BYVAL Format AS DWORD _                              ' __in  D3DFORMAT           Format
 , BYVAL Pool AS DWORD _                                ' __in  D3DPOOL             Pool
 , BYVAL Filter AS DWORD _                              ' __in  DWORD               Filter
 , BYVAL MipFilter AS DWORD _                           ' __in  DWORD               MipFilter
 , BYVAL ColorKey AS DWORD _                            ' __in  D3DCOLOR            ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO*  pSrcInfo
 , BYREF pPalette AS PALETTEENTRY _                     ' __out PALETTEENTRY*       pPalette
 , BYREF ppTexture AS IDirect3DTexture9 _               ' __out LPDIRECT3DTEXTURE9* ppTexture
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXCreateTextureFromFileEx = D3DXCreateTextureFromFileExW
#ELSE
   MACRO D3DXCreateTextureFromFileEx = D3DXCreateTextureFromFileExA
#ENDIF

DECLARE FUNCTION D3DXCreateCubeTextureFromFileExA IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateCubeTextureFromFileExA" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9       pDevice
 , BYREF pSrcFile AS ASCIIZ _                           ' __in  LPCSTR                  pSrcFile
 , BYVAL Size AS DWORD _                                ' __in  UINT                    Size
 , BYVAL MipLevels AS DWORD _                           ' __in  UINT                    MipLevels
 , BYVAL Usage AS DWORD _                               ' __in  DWORD                   Usage
 , BYVAL Format AS DWORD _                              ' __in  D3DFORMAT               Format
 , BYVAL Pool AS DWORD _                                ' __in  D3DPOOL                 Pool
 , BYVAL Filter AS DWORD _                              ' __in  DWORD                   Filter
 , BYVAL MipFilter AS DWORD _                           ' __in  DWORD                   MipFilter
 , BYVAL ColorKey AS DWORD _                            ' __in  D3DCOLOR                ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO*      pSrcInfo
 , BYREF pPalette AS PALETTEENTRY _                     ' __out PALETTEENTRY*           pPalette
 , BYREF ppCubeTexture AS IDirect3DCubeTexture9 _       ' __out LPDIRECT3DCUBETEXTURE9* ppCubeTexture
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateCubeTextureFromFileExW IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateCubeTextureFromFileExW" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9       pDevice
 , BYREF pSrcFile AS WSTRINGZ _                         ' __in  LPCWSTR                 pSrcFile
 , BYVAL Size AS DWORD _                                ' __in  UINT                    Size
 , BYVAL MipLevels AS DWORD _                           ' __in  UINT                    MipLevels
 , BYVAL Usage AS DWORD _                               ' __in  DWORD                   Usage
 , BYVAL Format AS DWORD _                              ' __in  D3DFORMAT               Format
 , BYVAL Pool AS DWORD _                                ' __in  D3DPOOL                 Pool
 , BYVAL Filter AS DWORD _                              ' __in  DWORD                   Filter
 , BYVAL MipFilter AS DWORD _                           ' __in  DWORD                   MipFilter
 , BYVAL ColorKey AS DWORD _                            ' __in  D3DCOLOR                ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO*      pSrcInfo
 , BYREF pPalette AS PALETTEENTRY _                     ' __out PALETTEENTRY*           pPalette
 , BYREF ppCubeTexture AS IDirect3DCubeTexture9 _       ' __out LPDIRECT3DCUBETEXTURE9* ppCubeTexture
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXCreateCubeTextureFromFileEx = D3DXCreateCubeTextureFromFileExW
#ELSE
   MACRO D3DXCreateCubeTextureFromFileEx = D3DXCreateCubeTextureFromFileExA
#ENDIF

DECLARE FUNCTION D3DXCreateVolumeTextureFromFileExA IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateVolumeTextureFromFileExA" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9         pDevice
 , BYREF pSrcFile AS ASCIIZ _                           ' __in  LPCSTR                    pSrcFile
 , BYVAL Width AS DWORD _                               ' __in  UINT                      Width
 , BYVAL Height AS DWORD _                              ' __in  UINT                      Height
 , BYVAL Depth AS DWORD _                               ' __in  UINT                      Depth
 , BYVAL MipLevels AS DWORD _                           ' __in  UINT                      MipLevels
 , BYVAL Usage AS DWORD _                               ' __in  DWORD                     Usage
 , BYVAL Format AS DWORD _                              ' __in  D3DFORMAT                 Format
 , BYVAL Pool AS DWORD _                                ' __in  D3DPOOL                   Pool
 , BYVAL Filter AS DWORD _                              ' __in  DWORD                     Filter
 , BYVAL MipFilter AS DWORD _                           ' __in  DWORD                     MipFilter
 , BYVAL ColorKey AS DWORD _                            ' __in  D3DCOLOR                  ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO*        pSrcInfo
 , BYREF pPalette AS PALETTEENTRY _                     ' __out PALETTEENTRY*             pPalette
 , BYREF ppVolumeTexture AS IDirect3DVolumeTexture9 _   ' __out LPDIRECT3DVOLUMETEXTURE9* ppVolumeTexture
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateVolumeTextureFromFileExW IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateVolumeTextureFromFileExW" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9         pDevice
 , BYREF pSrcFile AS WSTRINGZ _                         ' __in  LPCWSTR                   pSrcFile
 , BYVAL Width AS DWORD _                               ' __in  UINT                      Width
 , BYVAL Height AS DWORD _                              ' __in  UINT                      Height
 , BYVAL Depth AS DWORD _                               ' __in  UINT                      Depth
 , BYVAL MipLevels AS DWORD _                           ' __in  UINT                      MipLevels
 , BYVAL Usage AS DWORD _                               ' __in  DWORD                     Usage
 , BYVAL Format AS DWORD _                              ' __in  D3DFORMAT                 Format
 , BYVAL Pool AS DWORD _                                ' __in  D3DPOOL                   Pool
 , BYVAL Filter AS DWORD _                              ' __in  DWORD                     Filter
 , BYVAL MipFilter AS DWORD _                           ' __in  DWORD                     MipFilter
 , BYVAL ColorKey AS DWORD _                            ' __in  D3DCOLOR                  ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO*        pSrcInfo
 , BYREF pPalette AS PALETTEENTRY _                     ' __out PALETTEENTRY*             pPalette
 , BYREF ppVolumeTexture AS IDirect3DVolumeTexture9 _   ' __out LPDIRECT3DVOLUMETEXTURE9* ppVolumeTexture
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXCreateVolumeTextureFromFileEx = D3DXCreateVolumeTextureFromFileExW
#ELSE
   MACRO D3DXCreateVolumeTextureFromFileEx = D3DXCreateVolumeTextureFromFileExA
#ENDIF

'// FromResourceEx

DECLARE FUNCTION D3DXCreateTextureFromResourceExA IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateTextureFromResourceExA" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9   pDevice
 , BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE             hSrcModule
 , BYREF pSrcResource AS ASCIIZ _                       ' __in  LPCSTR              pSrcResource
 , BYVAL Width AS DWORD _                               ' __in  UINT                Width
 , BYVAL Height AS DWORD _                              ' __in  UINT                Height
 , BYVAL MipLevels AS DWORD _                           ' __in  UINT                MipLevels
 , BYVAL Usage AS DWORD _                               ' __in  DWORD               Usage
 , BYVAL Format AS DWORD _                              ' __in  D3DFORMAT           Format
 , BYVAL Pool AS DWORD _                                ' __in  D3DPOOL             Pool
 , BYVAL Filter AS DWORD _                              ' __in  DWORD               Filter
 , BYVAL MipFilter AS DWORD _                           ' __in  DWORD               MipFilter
 , BYVAL ColorKey AS DWORD _                            ' __in  D3DCOLOR            ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO*  pSrcInfo
 , BYREF pPalette AS PALETTEENTRY _                     ' __out PALETTEENTRY*       pPalette
 , BYREF ppTexture AS IDirect3DTexture9 _               ' __out LPDIRECT3DTEXTURE9* ppTexture
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateTextureFromResourceExW IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateTextureFromResourceExW" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9   pDevice
 , BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE             hSrcModule
 , BYREF pSrcResource AS WSTRINGZ _                     ' __in  LPCWSTR             pSrcResource
 , BYVAL Width AS DWORD _                               ' __in  UINT                Width
 , BYVAL Height AS DWORD _                              ' __in  UINT                Height
 , BYVAL MipLevels AS DWORD _                           ' __in  UINT                MipLevels
 , BYVAL Usage AS DWORD _                               ' __in  DWORD               Usage
 , BYVAL Format AS DWORD _                              ' __in  D3DFORMAT           Format
 , BYVAL Pool AS DWORD _                                ' __in  D3DPOOL             Pool
 , BYVAL Filter AS DWORD _                              ' __in  DWORD               Filter
 , BYVAL MipFilter AS DWORD _                           ' __in  DWORD               MipFilter
 , BYVAL ColorKey AS DWORD _                            ' __in  D3DCOLOR            ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO*  pSrcInfo
 , BYREF pPalette AS PALETTEENTRY _                     ' __out PALETTEENTRY*       pPalette
 , BYREF ppTexture AS IDirect3DTexture9 _               ' __out LPDIRECT3DTEXTURE9* ppTexture
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXCreateTextureFromResourceEx = D3DXCreateTextureFromResourceExW
#ELSE
   MACRO D3DXCreateTextureFromResourceEx = D3DXCreateTextureFromResourceExA
#ENDIF

DECLARE FUNCTION D3DXCreateCubeTextureFromResourceExA IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateCubeTextureFromResourceExA" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9       pDevice
 , BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE                 hSrcModule
 , BYREF pSrcResource AS ASCIIZ _                       ' __in  LPCSTR                  pSrcResource
 , BYVAL Size AS DWORD _                                ' __in  UINT                    Size
 , BYVAL MipLevels AS DWORD _                           ' __in  UINT                    MipLevels
 , BYVAL Usage AS DWORD _                               ' __in  DWORD                   Usage
 , BYVAL Format AS DWORD _                              ' __in  D3DFORMAT               Format
 , BYVAL Pool AS DWORD _                                ' __in  D3DPOOL                 Pool
 , BYVAL Filter AS DWORD _                              ' __in  DWORD                   Filter
 , BYVAL MipFilter AS DWORD _                           ' __in  DWORD                   MipFilter
 , BYVAL ColorKey AS DWORD _                            ' __in  D3DCOLOR                ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO*      pSrcInfo
 , BYREF pPalette AS PALETTEENTRY _                     ' __out PALETTEENTRY*           pPalette
 , BYREF ppCubeTexture AS IDirect3DCubeTexture9 _       ' __out LPDIRECT3DCUBETEXTURE9* ppCubeTexture
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateCubeTextureFromResourceExW IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateCubeTextureFromResourceExW" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9       pDevice
 , BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE                 hSrcModule
 , BYREF pSrcResource AS WSTRINGZ _                     ' __in  LPCWSTR                 pSrcResource
 , BYVAL Size AS DWORD _                                ' __in  UINT                    Size
 , BYVAL MipLevels AS DWORD _                           ' __in  UINT                    MipLevels
 , BYVAL Usage AS DWORD _                               ' __in  DWORD                   Usage
 , BYVAL Format AS DWORD _                              ' __in  D3DFORMAT               Format
 , BYVAL Pool AS DWORD _                                ' __in  D3DPOOL                 Pool
 , BYVAL Filter AS DWORD _                              ' __in  DWORD                   Filter
 , BYVAL MipFilter AS DWORD _                           ' __in  DWORD                   MipFilter
 , BYVAL ColorKey AS DWORD _                            ' __in  D3DCOLOR                ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO*      pSrcInfo
 , BYREF pPalette AS PALETTEENTRY _                     ' __out PALETTEENTRY*           pPalette
 , BYREF ppCubeTexture AS IDirect3DCubeTexture9 _       ' __out LPDIRECT3DCUBETEXTURE9* ppCubeTexture
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXCreateCubeTextureFromResourceEx = D3DXCreateCubeTextureFromResourceExW
#ELSE
   MACRO D3DXCreateCubeTextureFromResourceEx = D3DXCreateCubeTextureFromResourceExA
#ENDIF

DECLARE FUNCTION D3DXCreateVolumeTextureFromResourceExA IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateVolumeTextureFromResourceExA" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9         pDevice
 , BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE                   hSrcModule
 , BYREF pSrcResource AS ASCIIZ _                       ' __in  LPCSTR                    pSrcResource
 , BYVAL Width AS DWORD _                               ' __in  UINT                      Width
 , BYVAL Height AS DWORD _                              ' __in  UINT                      Height
 , BYVAL Depth AS DWORD _                               ' __in  UINT                      Depth
 , BYVAL MipLevels AS DWORD _                           ' __in  UINT                      MipLevels
 , BYVAL Usage AS DWORD _                               ' __in  DWORD                     Usage
 , BYVAL Format AS DWORD _                              ' __in  D3DFORMAT                 Format
 , BYVAL Pool AS DWORD _                                ' __in  D3DPOOL                   Pool
 , BYVAL Filter AS DWORD _                              ' __in  DWORD                     Filter
 , BYVAL MipFilter AS DWORD _                           ' __in  DWORD                     MipFilter
 , BYVAL ColorKey AS DWORD _                            ' __in  D3DCOLOR                  ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO*        pSrcInfo
 , BYREF pPalette AS PALETTEENTRY _                     ' __out PALETTEENTRY*             pPalette
 , BYREF ppVolumeTexture AS IDirect3DVolumeTexture9 _   ' __out LPDIRECT3DVOLUMETEXTURE9* ppVolumeTexture
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateVolumeTextureFromResourceExW IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateVolumeTextureFromResourceExW" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9         pDevice
 , BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE                   hSrcModule
 , BYREF pSrcResource AS WSTRINGZ _                     ' __in  LPCWSTR                   pSrcResource
 , BYVAL Width AS DWORD _                               ' __in  UINT                      Width
 , BYVAL Height AS DWORD _                              ' __in  UINT                      Height
 , BYVAL Depth AS DWORD _                               ' __in  UINT                      Depth
 , BYVAL MipLevels AS DWORD _                           ' __in  UINT                      MipLevels
 , BYVAL Usage AS DWORD _                               ' __in  DWORD                     Usage
 , BYVAL Format AS DWORD _                              ' __in  D3DFORMAT                 Format
 , BYVAL Pool AS DWORD _                                ' __in  D3DPOOL                   Pool
 , BYVAL Filter AS DWORD _                              ' __in  DWORD                     Filter
 , BYVAL MipFilter AS DWORD _                           ' __in  DWORD                     MipFilter
 , BYVAL ColorKey AS DWORD _                            ' __in  D3DCOLOR                  ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO*        pSrcInfo
 , BYREF pPalette AS PALETTEENTRY _                     ' __out PALETTEENTRY*             pPalette
 , BYREF ppVolumeTexture AS IDirect3DVolumeTexture9 _   ' __out LPDIRECT3DVOLUMETEXTURE9* ppVolumeTexture
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXCreateVolumeTextureFromResourceEx = D3DXCreateVolumeTextureFromResourceExW
#ELSE
   MACRO D3DXCreateVolumeTextureFromResourceEx = D3DXCreateVolumeTextureFromResourceExA
#ENDIF

'// FromFileInMemory

DECLARE FUNCTION D3DXCreateTextureFromFileInMemory IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateTextureFromFileInMemory" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9   pDevice
 , BYVAL pSrcData AS DWORD _                            ' __in  LPCVOID             pSrcData
 , BYVAL SrcDataSize AS DWORD _                         ' __in  UINT                SrcDataSize
 , BYREF ppTexture AS IDirect3DTexture9 _               ' __out LPDIRECT3DTEXTURE9* ppTexture
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateCubeTextureFromFileInMemory IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateCubeTextureFromFileInMemory" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9       pDevice
 , BYVAL pSrcData AS DWORD _                            ' __in  LPCVOID                 pSrcData
 , BYVAL SrcDataSize AS DWORD _                         ' __in  UINT                    SrcDataSize
 , BYREF ppCubeTexture AS IDirect3DCubeTexture9 _       ' __out LPDIRECT3DCUBETEXTURE9* ppCubeTexture
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateVolumeTextureFromFileInMemory IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateVolumeTextureFromFileInMemory" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9       pDevice
 , BYVAL pSrcData AS DWORD _                            ' __in  LPCVOID                 pSrcData
 , BYVAL SrcDataSize AS DWORD _                         ' __in  UINT                    SrcDataSize
 , BYREF ppVolumeTexture AS IDirect3DVolumeTexture9 _   ' __out LPDIRECT3DVOLUMETEXTURE9* ppVolumeTexture
 ) AS LONG                                              ' HRESULT

'// FromFileInMemoryEx

DECLARE FUNCTION D3DXCreateTextureFromFileInMemoryEx IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateTextureFromFileInMemoryEx" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9   pDevice
 , BYVAL pSrcData AS DWORD _                            ' __in  LPCVOID             pSrcData
 , BYVAL SrcDataSize AS DWORD _                         ' __in  UINT                SrcDataSize
 , BYVAL Width AS DWORD _                               ' __in  UINT                Width
 , BYVAL Height AS DWORD _                              ' __in  UINT                Height
 , BYVAL MipLevels AS DWORD _                           ' __in  UINT                MipLevels
 , BYVAL Usage AS DWORD _                               ' __in  DWORD               Usage
 , BYVAL Format AS DWORD _                              ' __in  D3DFORMAT           Format
 , BYVAL Pool AS DWORD _                                ' __in  D3DPOOL             Pool
 , BYVAL Filter AS DWORD _                              ' __in  DWORD               Filter
 , BYVAL MipFilter AS DWORD _                           ' __in  DWORD               MipFilter
 , BYVAL ColorKey AS DWORD _                            ' __in  D3DCOLOR            ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO*  pSrcInfo
 , BYREF pPalette AS PALETTEENTRY _                     ' __out PALETTEENTRY*       pPalette
 , BYREF ppTexture AS IDirect3DTexture9 _               ' __out LPDIRECT3DTEXTURE9* ppTexture
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateCubeTextureFromFileInMemoryEx IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateCubeTextureFromFileInMemoryEx" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9       pDevice
 , BYVAL pSrcData AS DWORD _                            ' __in  LPCVOID                 pSrcData
 , BYVAL SrcDataSize AS DWORD _                         ' __in  UINT                    SrcDataSize
 , BYVAL Size AS DWORD _                                ' __in  UINT                    Size
 , BYVAL MipLevels AS DWORD _                           ' __in  UINT                    MipLevels
 , BYVAL Usage AS DWORD _                               ' __in  DWORD                   Usage
 , BYVAL Format AS DWORD _                              ' __in  D3DFORMAT               Format
 , BYVAL Pool AS DWORD _                                ' __in  D3DPOOL                 Pool
 , BYVAL Filter AS DWORD _                              ' __in  DWORD                   Filter
 , BYVAL MipFilter AS DWORD _                           ' __in  DWORD                   MipFilter
 , BYVAL ColorKey AS DWORD _                            ' __in  D3DCOLOR                ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO*      pSrcInfo
 , BYREF pPalette AS PALETTEENTRY _                     ' __out PALETTEENTRY*           pPalette
 , BYREF ppCubeTexture AS IDirect3DCubeTexture9 _       ' __out LPDIRECT3DCUBETEXTURE9* ppCubeTexture
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateVolumeTextureFromFileInMemoryEx IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateVolumeTextureFromFileInMemoryEx" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9         pDevice
 , BYVAL pSrcData AS DWORD _                            ' __in  LPCVOID                   pSrcData
 , BYVAL SrcDataSize AS DWORD _                         ' __in  UINT                      SrcDataSize
 , BYVAL Width AS DWORD _                               ' __in  UINT                      Width
 , BYVAL Height AS DWORD _                              ' __in  UINT                      Height
 , BYVAL Depth AS DWORD _                               ' __in  UINT                      Depth
 , BYVAL MipLevels AS DWORD _                           ' __in  UINT                      MipLevels
 , BYVAL Usage AS DWORD _                               ' __in  DWORD                     Usage
 , BYVAL Format AS DWORD _                              ' __in  D3DFORMAT                 Format
 , BYVAL Pool AS DWORD _                                ' __in  D3DPOOL                   Pool
 , BYVAL Filter AS DWORD _                              ' __in  DWORD                     Filter
 , BYVAL MipFilter AS DWORD _                           ' __in  DWORD                     MipFilter
 , BYVAL ColorKey AS DWORD _                            ' __in  D3DCOLOR                  ColorKey
 , BYREF pSrcInfo AS D3DXIMAGE_INFO _                   ' __in_out D3DXIMAGE_INFO*        pSrcInfo
 , BYREF pPalette AS PALETTEENTRY _                     ' __out PALETTEENTRY*             pPalette
 , BYREF ppVolumeTexture AS IDirect3DVolumeTexture9 _   ' __out LPDIRECT3DVOLUMETEXTURE9* ppVolumeTexture
 ) AS LONG                                              ' HRESULT


'//----------------------------------------------------------------------------
'// D3DXSaveTextureToFile:
'// ----------------------
'// Save a texture to a file.
'//
'// Parameters:
'//  pDestFile
'//      File name of the destination file
'//  DestFormat
'//      D3DXIMAGE_FILEFORMAT specifying file format to use when saving.
'//  pSrcTexture
'//      Source texture, containing the image to be saved
'//  pSrcPalette
'//      Source palette of 256 colors, or NULL
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXSaveTextureToFileA IMPORT $D3DX_DLLNAME ALIAS "D3DXSaveTextureToFileA" (_
   BYREF pDestFile AS ASCIIZ _                          ' __in LPCSTR                 pDestFile
 , BYVAL DestFormat AS DWORD _                          ' __in D3DXIMAGE_FILEFORMAT   DestFormat
 , BYVAL pSrcTexture AS IDirect3DBaseTexture9 _         ' __in LPDIRECT3DBASETEXTURE9 pSrcTexture
 , BYREF pSrcPalette AS PALETTEENTRY _                  ' __in CONST PALETTEENTRY*    pSrcPalette
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXSaveTextureToFileW IMPORT $D3DX_DLLNAME ALIAS "D3DXSaveTextureToFileW" (_
   BYREF pDestFile AS WSTRINGZ _                        ' __in LPCWSTR                pDestFile
 , BYVAL DestFormat AS DWORD _                          ' __in D3DXIMAGE_FILEFORMAT   DestFormat
 , BYVAL pSrcTexture AS IDirect3DBaseTexture9 _         ' __in LPDIRECT3DBASETEXTURE9 pSrcTexture
 , BYREF pSrcPalette AS PALETTEENTRY _                  ' __in CONST PALETTEENTRY*    pSrcPalette
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXSaveTextureToFile = D3DXSaveTextureToFileW
#ELSE
   MACRO D3DXSaveTextureToFile = D3DXSaveTextureToFileA
#ENDIF

'//----------------------------------------------------------------------------
'// D3DXSaveTextureToFileInMemory:
'// ----------------------
'// Save a texture to a file.
'//
'// Parameters:
'//  ppDestBuf
'//      address of a d3dxbuffer pointer to return the image data
'//  DestFormat
'//      D3DXIMAGE_FILEFORMAT specifying file format to use when saving.
'//  pSrcTexture
'//      Source texture, containing the image to be saved
'//  pSrcPalette
'//      Source palette of 256 colors, or NULL
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXSaveTextureToFileInMemory IMPORT $D3DX_DLLNAME ALIAS "D3DXSaveTextureToFileInMemory" (_
   BYREF ppDestBuf AS ID3DXBuffer _                     ' __out LPD3DXBUFFER*          ppDestBuf
 , BYVAL DestFormat AS DWORD _                          ' __in  D3DXIMAGE_FILEFORMAT   DestFormat
 , BYVAL pSrcTexture AS IDirect3DBaseTexture9 _         ' __in  LPDIRECT3DBASETEXTURE9 pSrcTexture
 , BYREF pSrcPalette AS PALETTEENTRY _                  ' __in  CONST PALETTEENTRY*    pSrcPalette
 ) AS LONG                                              ' HRESULT


'//////////////////////////////////////////////////////////////////////////////
'// Misc Texture APIs /////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

'//----------------------------------------------------------------------------
'// D3DXFilterTexture:
'// ------------------
'// Filters mipmaps levels of a texture.
'//
'// Parameters:
'//  pBaseTexture
'//      The texture object to be filtered
'//  pPalette
'//      256 color palette to be used, or NULL for non-palettized formats
'//  SrcLevel
'//      The level whose image is used to generate the subsequent levels.
'//  Filter
'//      D3DX_FILTER flags controlling how each miplevel is filtered.
'//      Or D3DX_DEFAULT for D3DX_FILTER_BOX,
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXFilterTexture IMPORT $D3DX_DLLNAME ALIAS "D3DXFilterTexture" (_
   BYVAL pBaseTexture AS IDirect3DBaseTexture9 _        ' __in  LPDIRECT3DBASETEXTURE9 pBaseTexture
 , BYREF pPalette AS PALETTEENTRY _                     ' __out CONST PALETTEENTRY*    pPalette
 , BYVAL SrcLevel AS DWORD _                            ' __in  UINT                   SrcLevel
 , BYVAL Filter AS DWORD _                              ' __in  DWORD                  Filter
 ) AS LONG                                              ' HRESULT


'//----------------------------------------------------------------------------
'// D3DXFillTexture:
'// ----------------
'// Uses a user provided function to fill each texel of each mip level of a
'// given texture.
'//
'// Paramters:
'//  pTexture, pCubeTexture, pVolumeTexture
'//      Pointer to the texture to be filled.
'//  pFunction
'//      Pointer to user provided evalutor function which will be used to
'//      compute the value of each texel.
'//  pData
'//      Pointer to an arbitrary block of user defined data.  This pointer
'//      will be passed to the function provided in pFunction
'//-----------------------------------------------------------------------------

DECLARE FUNCTION D3DXFillTexture IMPORT $D3DX_DLLNAME ALIAS "D3DXFillTexture" (_
   BYVAL pTexture AS IDirect3DTexture9 _                ' __in_out LPDIRECT3DTEXTURE9 pTexture
 , BYVAL pFunction AS DWORD _                           ' __in LPD3DXFILL2D           pFunction
 , BYVAL pData AS DWORD _                               ' __in LPVOID                 pData
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXFillCubeTexture IMPORT $D3DX_DLLNAME ALIAS "D3DXFillCubeTexture" (_
   BYVAL pCubeTexture AS IDirect3DCubeTexture9 _        ' __in_out LPDIRECT3DCUBETEXTURE9 pCubeTexture
 , BYVAL pFunction AS DWORD _                           ' __in LPD3DXFILL3D               pFunction
 , BYVAL pData AS DWORD _                               ' __in LPVOID                     pData
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXFillVolumeTexture IMPORT $D3DX_DLLNAME ALIAS "D3DXFillVolumeTexture" (_
   BYVAL pVolumeTexture AS IDirect3DVolumeTexture9 _    ' __in_out LPDIRECT3DVOLUMETEXTURE9 pVolumeTexture
 , BYVAL pFunction AS DWORD _                           ' __in LPD3DXFILL3D                 pFunction
 , BYVAL pData AS DWORD _                               ' __in LPVOID                       pData
 ) AS LONG                                              ' HRESULT


'//---------------------------------------------------------------------------
'// D3DXFillTextureTX:
'// ------------------
'// Uses a TX Shader target to function to fill each texel of each mip level
'// of a given texture. The TX Shader target should be a compiled function
'// taking 2 paramters and returning a float4 color.
'//
'// Paramters:
'//  pTexture, pCubeTexture, pVolumeTexture
'//      Pointer to the texture to be filled.
'//  pTextureShader
'//      Pointer to the texture shader to be used to fill in the texture
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXFillTextureTX IMPORT $D3DX_DLLNAME ALIAS "D3DXFillTextureTX" (_
   BYVAL pTexture AS IDirect3DTexture9 _                ' __in_out LPDIRECT3DTEXTURE9 pTexture
 , BYVAL pTextureShader AS ID3DXTextureShader _         ' __in LPD3DXTEXTURESHADER    pTextureShader
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXFillCubeTextureTX IMPORT $D3DX_DLLNAME ALIAS "D3DXFillCubeTextureTX" (_
   BYVAL pCubeTexture AS IDirect3DCubeTexture9 _        ' __in_out LPDIRECT3DCUBETEXTURE9 pCubeTexture
 , BYVAL pTextureShader AS ID3DXTextureShader _         ' __in LPD3DXTEXTURESHADER        pTextureShader
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXFillVolumeTextureTX IMPORT $D3DX_DLLNAME ALIAS "D3DXFillVolumeTextureTX" (_
   BYVAL pVolumeTexture AS IDirect3DVolumeTexture9 _    ' __in_out LPDIRECT3DVOLUMETEXTURE9 pVolumeTexture
 , BYVAL pTextureShader AS ID3DXTextureShader _         ' __in LPD3DXTEXTURESHADER          pTextureShader
 ) AS LONG                                              ' HRESULT


'//----------------------------------------------------------------------------
'// D3DXComputeNormalMap:
'// ---------------------
'// Converts a height map into a normal map.  The (x,y,z) components of each
'// normal are mapped to the (r,g,b) channels of the output texture.
'//
'// Parameters
'//  pTexture
'//      Pointer to the destination texture
'//  pSrcTexture
'//      Pointer to the source heightmap texture
'//  pSrcPalette
'//      Source palette of 256 colors, or NULL
'//  Flags
'//      D3DX_NORMALMAP flags
'//  Channel
'//      D3DX_CHANNEL specifying source of height information
'//  Amplitude
'//      The constant value which the height information is multiplied by.
'//---------------------------------------------------------------------------

DECLARE FUNCTION D3DXComputeNormalMap IMPORT $D3DX_DLLNAME ALIAS "D3DXComputeNormalMap" (_
   BYVAL pTexture AS IDirect3DTexture9 _                ' __in_out LPDIRECT3DTEXTURE9  pTexture
 , BYVAL pSrcTexture AS IDirect3DTexture9 _             ' __in LPDIRECT3DTEXTURE9      pSrcTexture
 , BYREF pSrcPalette AS PALETTEENTRY _                  ' __in CONST PALETTEENTRY*     pSrcPalette
 , BYVAL Flags AS DWORD _                               ' __in DWORD                   Flags
 , BYVAL Channel AS DWORD _                             ' __in DWORD                   Channel
 , BYVAL Amplitude AS SINGLE _                          ' __in FLOAT                   Amplitude
 ) AS LONG                                              ' HRESULT
