' ########################################################################################
' Microsoft Windows
' File: d3dx9core.inc
' Contents: D3DX core types and functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3DX9CORE_INC = 1

#INCLUDE ONCE "d3dx9math.inc"
#INCLUDE ONCE "d3dx9.inc"

'///////////////////////////////////////////////////////////////////////////
'// D3DX_SDK_VERSION:
'// -----------------
'// This identifier is passed to D3DXCheckVersion in order to ensure that an
'// application was built against the correct header files and IMPORT files.
'// This number is incremented whenever a header (or other) change would
'// require applications to be rebuilt. If the version doesn't match,
'// D3DXCreateVersion will return FALSE. (The number itself has no meaning.)
'///////////////////////////////////////////////////////////////////////////

%D3DX_VERSION = &H0902
%D3DX_SDK_VERSION = 22

DECLARE FUNCTION D3DXCheckVersion IMPORT $D3DX_DLLNAME ALIAS "D3DXCheckVersion" ( _
   BYVAL D3DSdkVersion AS DWORD _                       ' __in UINT D3DSdkVersion
 , BYVAL D3DXSdkVersion AS DWORD _                      ' __in UINT D3DXSdkVersion
 ) AS LONG                                              ' BOOL

'///////////////////////////////////////////////////////////////////////////
'// D3DXDebugMute
'//    Mutes D3DX and D3D debug spew (TRUE - mute, FALSE - not mute)
'//
'//  returns previous mute value
'//
'///////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION D3DXDebugMute IMPORT $D3DX_DLLNAME ALIAS "D3DXDebugMute" ( _
   BYVAL Mute AS LONG _                                 ' __in BOOL Mute
 ) AS LONG                                              ' BOOL

'///////////////////////////////////////////////////////////////////////////
'// D3DXGetDriverLevel:
'//    Returns driver version information:
'//
'//    700 - DX7 level driver
'//    800 - DX8 level driver
'//    900 - DX9 level driver
'///////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION D3DXGetDriverLevel IMPORT $D3DX_DLLNAME ALIAS "D3DXGetDriverLevel" ( _
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in LPDIRECT3DDEVICE9 pDevice
 ) AS DWORD                                             ' UINT


'///////////////////////////////////////////////////////////////////////////
'// ID3DXBuffer:
'// ------------
'// The buffer object is used by D3DX to return arbitrary size data.
'//
'// GetBufferPointer -
'//    Returns a pointer to the beginning of the buffer.
'//
'// GetBufferSize -
'//    Returns the size of the buffer, in bytes.
'///////////////////////////////////////////////////////////////////////////

$IID_ID3DXBuffer = GUID$("{8BA5FB08-5195-40E2-AC58-0D989C3A0102}")

INTERFACE ID3DXBuffer $IID_ID3DXBuffer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetBufferPointer ( _                          ' VTable offset = 12
   ) AS DWORD                                           ' LPVOID
   ' =====================================================================================
   METHOD GetBufferSize ( _                             ' VTable offset = 16
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================

END INTERFACE


'//////////////////////////////////////////////////////////////////////////////
'// D3DXSPRITE flags:
'// -----------------
'// D3DXSPRITE_DONOTSAVESTATE
'//   Specifies device state is not to be saved and restored in Begin/End.
'// D3DXSPRITE_DONOTMODIFY_RENDERSTATE
'//   Specifies device render state is not to be changed in Begin.  The device
'//   is assumed to be in a valid state to draw vertices containing POSITION0,
'//   TEXCOORD0, and COLOR0 data.
'// D3DXSPRITE_OBJECTSPACE
'//   The WORLD, VIEW, and PROJECTION transforms are NOT modified.  The
'//   transforms currently set to the device are used to transform the sprites
'//   when the batch is drawn (at Flush or End).  If this is not specified,
'//   WORLD, VIEW, and PROJECTION transforms are modified so that sprites are
'//   drawn in screenspace coordinates.
'// D3DXSPRITE_BILLBOARD
'//   Rotates each sprite about its center so that it is facing the viewer.
'// D3DXSPRITE_ALPHABLEND
'//   Enables ALPHABLEND(SRCALPHA, INVSRCALPHA) and ALPHATEST(alpha > 0).
'//   ID3DXFont expects this to be set when drawing text.
'// D3DXSPRITE_SORT_TEXTURE
'//   Sprites are sorted by texture prior to drawing.  This is recommended when
'//   drawing non-overlapping sprites of uniform depth.  For example, drawing
'//   screen-aligned text with ID3DXFont.
'// D3DXSPRITE_SORT_DEPTH_FRONTTOBACK
'//   Sprites are sorted by depth front-to-back prior to drawing.  This is
'//   recommended when drawing opaque sprites of varying depths.
'// D3DXSPRITE_SORT_DEPTH_BACKTOFRONT
'//   Sprites are sorted by depth back-to-front prior to drawing.  This is
'//   recommended when drawing transparent sprites of varying depths.
'//////////////////////////////////////////////////////////////////////////////

%D3DXSPRITE_DONOTSAVESTATE           =   1   ' (1 << 0)
%D3DXSPRITE_DONOTMODIFY_RENDERSTATE  =   2   ' (1 << 1)
%D3DXSPRITE_OBJECTSPACE              =   4   ' (1 << 2)
%D3DXSPRITE_BILLBOARD                =   8   ' (1 << 3)
%D3DXSPRITE_ALPHABLEND               =  16   ' (1 << 4)
%D3DXSPRITE_SORT_TEXTURE             =  32   ' (1 << 5)
%D3DXSPRITE_SORT_DEPTH_FRONTTOBACK   =  64   ' (1 << 6)
%D3DXSPRITE_SORT_DEPTH_BACKTOFRONT   = 128   ' (1 << 7)


'//////////////////////////////////////////////////////////////////////////////
'// ID3DXSprite:
'// ------------
'// This object intends to provide an easy way to drawing sprites using D3D.
'//
'// Begin -
'//    Prepares device for drawing sprites.
'//
'// Draw -
'//    Draws a sprite.  Before transformation, the sprite is the size of
'//    SrcRect, with its top-left corner specified by Position.  The color
'//    and alpha channels are modulated by Color.
'//
'// Flush -
'//    Forces all batched sprites to submitted to the device.
'//
'// End -
'//    Restores device state to how it was when Begin was called.
'//
'// OnLostDevice, OnResetDevice -
'//    Call OnLostDevice() on this object before calling Reset() on the
'//    device, so that this object can release any stateblocks and video
'//    memory resources.  After Reset(), the call OnResetDevice().
'//////////////////////////////////////////////////////////////////////////////

$IID_ID3DXSprite = GUID$("{BA0B762D-7D28-43EC-B9DC-2F84443B0614}")

INTERFACE ID3DXSprite $IID_ID3DXSprite

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out LPDIRECT3DDEVICE9* ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransform ( _                              ' VTable offset = 16
     BYREF pTransform AS D3DXMATRIX _                   ' __out D3DXMATRIX *pTransform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransform ( _                              ' VTable offset = 20
     BYREF pTransform AS D3DXMATRIX _                   ' __in D3DXMATRIX *pTransform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetWorldViewRH ( _                            ' VTable offset = 24
     BYREF pWorld AS D3DXMATRIX _                       ' __in CONST D3DXMATRIX *pWorld
   , BYREF pView AS D3DXMATRIX _                        ' __in CONST D3DXMATRIX *pView
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetWorldViewLH ( _                            ' VTable offset = 28
     BYREF pWorld AS D3DXMATRIX _                       ' __in CONST D3DXMATRIX *pWorld
   , BYREF pView AS D3DXMATRIX _                        ' __in CONST D3DXMATRIX *pView
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin ( _                                     ' VTable offset = 32
     BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Draw ( _                                      ' VTable offset = 36
     BYVAL pTexture AS IDirect3DTexture9 _              ' __in LPDIRECT3DTEXTURE9 pTexture
   , BYREF pSrcRect AS RECT _                           ' __in CONST RECT *pSrcRect
   , BYREF pCenter AS D3DXVECTOR3 _                     ' __in CONST D3DXVECTOR3 *pCenter
   , BYREF pPosition AS D3DXVECTOR3 _                   ' __in CONST D3DXVECTOR3 *pPosition
   , BYVAL Color AS DWORD _                             ' __in D3DCOLOR Color
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Flush ( _                                     ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD End ( _                                       ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnLostDevice ( _                              ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnResetDevice ( _                             ' VTable offset = 52
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


DECLARE FUNCTION D3DXCreateSprite IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateSprite" ( _
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9 pDevice
 , BYREF ppSprite AS ID3DXSprite _                      ' __out LPD3DXSPRITE*     ppSprite
 ) AS LONG                                              ' HRESULT


'//////////////////////////////////////////////////////////////////////////////
'// ID3DXFont:
'// ----------
'// Font objects contain the textures and resources needed to render a specific
'// font on a specific device.
'//
'// GetGlyphData -
'//    Returns glyph cache data, for a given glyph.
'//
'// PreloadCharacters/PreloadGlyphs/PreloadText -
'//    Preloads glyphs into the glyph cache textures.
'//
'// DrawText -
'//    Draws formatted text on a D3D device.  Some parameters are
'//    surprisingly similar to those of GDI's DrawText function.  See GDI
'//    documentation for a detailed description of these parameters.
'//    If pSprite is NULL, an internal sprite object will be used.
'//
'// OnLostDevice, OnResetDevice -
'//    Call OnLostDevice() on this object before calling Reset() on the
'//    device, so that this object can release any stateblocks and video
'//    memory resources.  After Reset(), the call OnResetDevice().
'//////////////////////////////////////////////////////////////////////////////

' // Size = 56 byes
TYPE D3DXFONT_DESCA BYTE
   Height          AS LONG    ' INT
   Width           AS DWORD   ' UINT
   Weight          AS DWORD   ' UINT
   MipLevels       AS DWORD   ' UINT
   Italic          AS LONG    ' BOOL
   CharSet         AS BYTE    ' BYTE
   OutputPrecision AS BYTE    ' BYTE
   Quality         AS BYTE    ' BYTE
   PitchAndFamily  AS BYTE    ' BYTE
   FaceName        AS ASCIIZ * %LF_FACESIZE   ' CHAR FaceName[LF_FACESIZE]
END TYPE

' // Size = 88 bytes
TYPE D3DXFONT_DESCW BYTE
   Height          AS LONG    ' INT
   Width           AS DWORD   ' UINT
   Weight          AS DWORD   ' UINT
   MipLevels       AS DWORD   ' UINT
   Italic          AS LONG    ' BOOL
   CharSet         AS BYTE    ' BYTE
   OutputPrecision AS BYTE    ' BYTE
   Quality         AS BYTE    ' BYTE
   PitchAndFamily  AS BYTE    ' BYTE
   FaceName        AS WSTRINGZ * %LF_FACESIZE   ' WCHAR FaceName[LF_FACESIZE]
END TYPE

#IF %DEF(%UNICODE)
   MACRO D3DXFONT_DESC = D3DXFONT_DESCW
#ELSE
   MACRO D3DXFONT_DESC = D3DXFONT_DESCA
#ENDIF

$IID_ID3DXFont = GUID$("{D79DBB70-5F21-4d36-BBC2-FF525C213CDC}")

INTERFACE ID3DXFont $IID_ID3DXFont

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out LPDIRECT3DDEVICE9 *ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescA ( _                                  ' VTable offset = 16
     BYREF pDesc AS D3DXFONT_DESCA _                    ' __out D3DXFONT_DESCA *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescW ( _                                  ' VTable offset = 20
     BYREF pDesc AS D3DXFONT_DESCW _                    ' __out D3DXFONT_DESCW *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTextMetricsA ( _                           ' VTable offset = 24
     BYREF pTextMetrics AS TEXTMETRIC _                 ' __out TEXTMETRICA *pTextMetrics
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTextMetricsW ( _                           ' VTable offset = 28
     BYREF pTextMetrics AS TEXTMETRIC _                 ' __out TEXTMETRICW *pTextMetrics
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDC ( _                                     ' VTable offset = 32
   ) AS DWORD                                           ' HDC
   ' =====================================================================================
   METHOD GetGlyphData ( _                              ' VTable offset = 36
     BYVAL Glyph AS DWORD _                             ' __in  UINT Glyph
   , BYREF ppTexture AS IDirect3DTexture9 _             ' __out LPDIRECT3DTEXTURE9 *ppTexture
   , BYREF pBlackBox AS RECT _                          ' __out RECT *pBlackBox
   , BYREF pCellInc AS POINT _                          ' __out POINT *pCellInc
   ) AS DWORD                                           ' HDC
   ' =====================================================================================
   METHOD PreloadCharacters ( _                         ' VTable offset = 40
     BYVAL First AS DWORD _                             ' __in UINT First
   , BYVAL Last AS DWORD _                              ' __in UINT Last
   ) AS DWORD                                           ' HDC
   ' =====================================================================================
   METHOD PreloadGlyphs ( _                             ' VTable offset = 44
     BYVAL First AS DWORD _                             ' __in UINT First
   , BYVAL Last AS DWORD _                              ' __in UINT Last
   ) AS DWORD                                           ' HDC
   ' =====================================================================================
   METHOD PreloadTextA ( _                              ' VTable offset = 48
     BYREF pString AS ASCIIZ _                          ' __in LPCSTR pString
   , BYVAL Count AS LONG _                              ' __in INT Count
   ) AS DWORD                                           ' HDC
   ' =====================================================================================
   METHOD PreloadTextW ( _                              ' VTable offset = 52
     BYREF pString AS WSTRINGZ _                        ' __in LPCWSTR pString
   , BYVAL Count AS LONG _                              ' __in INT Count
   ) AS DWORD                                           ' HDC
   ' =====================================================================================
   METHOD DrawTextA ( _                                 ' VTable offset = 56
     BYVAL pSprite AS ID3DXSprite _                     ' __in LPD3DXSPRITE pSprite
   , BYREF pString AS ASCIIZ _                          ' __in LPCSTR pString
   , BYVAL Count AS LONG _                              ' __in INT Count
   , BYREF pRect AS RECT _                              ' __in LPRECT pRect
   , BYVAL Format AS DWORD _                            ' __in DWORD Format
   , BYVAL Color AS DWORD _                             ' __in D3DCOLOR Color
   ) AS LONG                                            ' LONG
   ' =====================================================================================
   METHOD DrawTextW ( _                                 ' VTable offset = 60
     BYVAL pSprite AS ID3DXSprite _                     ' __in LPD3DXSPRITE pSprite
   , BYREF pString AS WSTRINGZ _                        ' __in LPCWSTR pString
   , BYVAL Count AS LONG _                              ' __in INT Count
   , BYREF pRect AS RECT _                              ' __in LPRECT pRect
   , BYVAL Format AS DWORD _                            ' __in DWORD Format
   , BYVAL Color AS DWORD _                             ' __in D3DCOLOR Color
   ) AS LONG                                            ' LONG
   ' =====================================================================================
   METHOD OnLostDevice ( _                              ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnResetDevice ( _                             ' VTable offset = 68
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


DECLARE FUNCTION D3DXCreateFontA IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateFontA" ( _
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9 pDevice
 , BYVAL Height AS LONG _                               ' __in  INT               Height
 , BYVAL Width AS DWORD _                               ' __in  UINT              Width
 , BYVAL Weight AS DWORD _                              ' __in  UINT              Weight
 , BYVAL MipLevels AS DWORD _                           ' __in  UINT              MipLevels
 , BYVAL Italic AS LONG _                               ' __in  BOOL              Italic
 , BYVAL CharSet AS DWORD _                             ' __in  DWORD             CharSet
 , BYVAL OutputPrecision AS DWORD _                     ' __in  DWORD             OutputPrecision
 , BYVAL Quality AS DWORD _                             ' __in  DWORD             Quality
 , BYVAL PitchAndFamily AS DWORD _                      ' __in  DWORD             PitchAndFamily
 , BYREF pFaceName AS ASCIIZ _                          ' __in  LPCSTR            pFaceName
 , BYREF ppFont AS ID3DXFont _                          ' __out LPD3DXFONT*       ppFont
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateFontW IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateFontW" ( _
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9 pDevice
 , BYVAL Height AS LONG _                               ' __in  INT               Height
 , BYVAL Width AS DWORD _                               ' __in  UINT              Width
 , BYVAL Weight AS DWORD _                              ' __in  UINT              Weight
 , BYVAL MipLevels AS DWORD _                           ' __in  UINT              MipLevels
 , BYVAL Italic AS LONG _                               ' __in  BOOL              Italic
 , BYVAL CharSet AS DWORD _                             ' __in  DWORD             CharSet
 , BYVAL OutputPrecision AS DWORD _                     ' __in  DWORD             OutputPrecision
 , BYVAL Quality AS DWORD _                             ' __in  DWORD             Quality
 , BYVAL PitchAndFamily AS DWORD _                      ' __in  DWORD             PitchAndFamily
 , BYREF FaceName AS WSTRINGZ _                         ' __in  LPCWSTR           FaceName
 , BYREF ppFont AS ID3DXFont _                          ' __out LPD3DXFONT*       ppFont
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXCreateFont = D3DXCreateFontW
#ELSE
   MACRO D3DXCreateFont = D3DXCreateFontA
#ENDIF

DECLARE FUNCTION D3DXCreateFontIndirectA IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateFontIndirectA" ( _
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9     pDevice
 , BYREF pDesc AS D3DXFONT_DESCA _                      ' __in  CONST D3DXFONT_DESCA* pDesc
 , BYREF ppFont AS ID3DXFont _                          ' __out LPD3DXFONT*           ppFont
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateFontIndirectW IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateFontIndirectW" ( _
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9     pDevice
 , BYREF pDesc AS D3DXFONT_DESCW _                      ' __in  CONST D3DXFONT_DESCW* pDesc
 , BYREF ppFont AS ID3DXFont _                          ' __out LPD3DXFONT*           ppFont
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXCreateFontIndirect = D3DXCreateFontIndirectW
#ELSE
   MACRO D3DXCreateFontIndirect = D3DXCreateFontIndirectA
#ENDIF

'///////////////////////////////////////////////////////////////////////////
'// ID3DXRenderToSurface:
'// ---------------------
'// This object abstracts rendering to surfaces.  These surfaces do not
'// necessarily need to be render targets.  If they are not, a compatible
'// render target is used, and the result copied into surface at end scene.
'//
'// BeginScene, EndScene -
'//    Call BeginScene() and EndScene() at the beginning and ending of your
'//    scene.  These calls will setup and restore render targets, viewports,
'//    etc..
'//
'// OnLostDevice, OnResetDevice -
'//    Call OnLostDevice() on this object before calling Reset() on the
'//    device, so that this object can release any stateblocks and video
'//    memory resources.  After Reset(), the call OnResetDevice().
'///////////////////////////////////////////////////////////////////////////

' // Size = 20 bytes
TYPE D3DXRTS_DESC DWORD
   Width              AS DWORD   ' UINT
   Height             AS DWORD   ' UINT
   Format             AS DWORD   ' D3DFORMAT
   DepthStencil       AS LONG    ' BOOL
   DepthStencilFormat AS DWORD   ' D3DFORMAT
END TYPE

$IID_ID3DXRenderToSurface = GUID$("{6985F346-2C3D-43B3-BE8B-DAAE8A03D894}")

INTERFACE ID3DXRenderToSurface $IID_ID3DXRenderToSurface

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out LPDIRECT3DDEVICE9* ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 16
     BYREF pDesc AS D3DXRTS_DESC _                      ' __out D3DXRTS_DESC* pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginScene ( _                                ' VTable offset = 20
     BYVAL pSurface AS IDirect3DSurface9 _              ' __in LPDIRECT3DSURFACE9 pSurface
   , BYREF pViewport AS D3DVIEWPORT9 _                  ' __in CONST D3DVIEWPORT9* pViewport
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndScene ( _                                  ' VTable offset = 24
     BYVAL MipFilter AS DWORD _                         ' __in DWORD MipFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnLostDevice ( _                              ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnResetDevice ( _                             ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


DECLARE FUNCTION D3DXCreateRenderToSurface IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateRenderToSurface" ( _
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9      pDevice
 , BYVAL Width AS DWORD _                               ' __in  UINT                   Width
 , BYVAL Height AS DWORD _                              ' __in  UINT                   Height
 , BYVAL Format AS DWORD _                              ' __in  D3DFORMAT              Format
 , BYVAL DepthStencil AS LONG _                         ' __in  BOOL                   DepthStencil
 , BYVAL DepthStencilFormat AS DWORD _                  ' __in  D3DFORMAT              DepthStencilFormat
 , BYREF ppRenderToSurface AS ID3DXRenderToSurface _    ' __out LPD3DXRENDERTOSURFACE* ppRenderToSurface
 ) AS LONG                                              ' HRESULT

'///////////////////////////////////////////////////////////////////////////
'// ID3DXRenderToEnvMap:
'// --------------------
'// This object abstracts rendering to environment maps.  These surfaces
'// do not necessarily need to be render targets.  If they are not, a
'// compatible render target is used, and the result copied into the
'// environment map at end scene.
'//
'// BeginCube, BeginSphere, BeginHemisphere, BeginParabolic -
'//    This function initiates the rendering of the environment map.  As
'//    parameters, you pass the textures in which will get filled in with
'//    the resulting environment map.
'//
'// Face -
'//    Call this function to initiate the drawing of each face.  For each
'//    environment map, you will call this six times.. once for each face
'//    in D3DCUBEMAP_FACES.
'//
'// End -
'//    This will restore all render targets, and if needed compose all the
'//    rendered faces into the environment map surfaces.
'//
'// OnLostDevice, OnResetDevice -
'//    Call OnLostDevice() on this object before calling Reset() on the
'//    device, so that this object can release any stateblocks and video
'//    memory resources.  After Reset(), the call OnResetDevice().
'///////////////////////////////////////////////////////////////////////////

' // Size = 20 bytes
TYPE D3DXRTE_DESC DWORD
   Size               AS DWORD   ' UINT
   MipLevels          AS DWORD   ' UINT
   Format             AS DWORD   ' D3DFORMAT
   DepthStencil       AS LONG    ' BOOL
   DepthStencilFormat AS DWORD   ' D3DFORMAT
END TYPE


$IID_ID3DXRenderToEnvMap = GUID$("{313F1B4B-C7B0-4FA2-9D9D-8D380B64385E}")

INTERFACE ID3DXRenderToEnvMap $IID_ID3DXRenderToEnvMap

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out LPDIRECT3DDEVICE9* ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 16
     BYREF pDesc AS D3DXRTE_DESC _                      ' __out D3DXRTE_DESC* pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginCube ( _                                 ' VTable offset = 20
     BYVAL pCubeTex AS IDirect3DCubeTexture9 _          ' __in LPDIRECT3DCUBETEXTURE9 pCubeTex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginSphere ( _                               ' VTable offset = 24
     BYVAL pTex AS IDirect3DTexture9 _                  ' __in LPDIRECT3DTEXTURE9 pTex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginHemisphere ( _                           ' VTable offset = 28
     BYVAL pTexZPos AS IDirect3DTexture9 _              ' __in LPDIRECT3DTEXTURE9 pTexZPos
   , BYVAL pTexZNeg AS IDirect3DTexture9 _              ' __in LPDIRECT3DTEXTURE9 pTexZNeg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginParabolic ( _                            ' VTable offset = 32
     BYVAL pTexZPos AS IDirect3DTexture9 _              ' __in LPDIRECT3DTEXTURE9 pTexZPos
   , BYVAL pTexZNeg AS IDirect3DTexture9 _              ' __in LPDIRECT3DTEXTURE9 pTexZNeg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Face ( _                                      ' VTable offset = 36
     BYVAL Face AS DWORD _                              ' __in D3DCUBEMAP_FACES Face
   , BYVAL MipFilter AS DWORD _                         ' __in DWORD MipFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD End ( _                                       ' VTable offset = 40
     BYVAL MipFilter AS DWORD _                         ' __in DWORD MipFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnLostDevice ( _                              ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnResetDevice ( _                             ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


DECLARE FUNCTION D3DXCreateRenderToEnvMap IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateRenderToEnvMap" ( _
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9     pDevice
 , BYVAL Size AS DWORD _                                ' __in  UINT                  Size
 , BYVAL MipLevels AS DWORD _                           ' __in  UINT                  MipLevels
 , BYVAL Format AS DWORD _                              ' __in  D3DFORMAT             Format
 , BYVAL DepthStencil AS LONG _                         ' __in  BOOL                  DepthStencil
 , BYVAL DepthStencilFormat AS DWORD _                  ' __in  D3DFORMAT             DepthStencilFormat
 , BYREF ppRenderToEnvMap AS ID3DXRenderToEnvMap _      ' __out LPD3DXRenderToEnvMap* ppRenderToEnvMap
 ) AS LONG                                              ' HRESULT


'///////////////////////////////////////////////////////////////////////////
'// ID3DXLine:
'// ------------
'// This object intends to provide an easy way to draw lines using D3D.
'//
'// Begin -
'//    Prepares device for drawing lines
'//
'// Draw -
'//    Draws a line strip in screen-space.
'//    Input is in the form of a array defining points on the line strip. of D3DXVECTOR2
'//
'// DrawTransform -
'//    Draws a line in screen-space with a specified input transformation matrix.
'//
'// End -
'//     Restores device state to how it was when Begin was called.
'//
'// SetPattern -
'//     Applies a stipple pattern to the line.  Input is one 32-bit
'//     DWORD which describes the stipple pattern. 1 is opaque, 0 is
'//     transparent.
'//
'// SetPatternScale -
'//     Stretches the stipple pattern in the u direction.  Input is one
'//     floating-point value.  0.0f is no scaling, whereas 1.0f doubles
'//     the length of the stipple pattern.
'//
'// SetWidth -
'//     Specifies the thickness of the line in the v direction.  Input is
'//     one floating-point value.
'//
'// SetAntialias -
'//     Toggles line antialiasing.  Input is a BOOL.
'//     TRUE  = Antialiasing on.
'//     FALSE = Antialiasing off.
'//
'// SetGLLines -
'//     Toggles non-antialiased OpenGL line emulation.  Input is a BOOL.
'//     TRUE  = OpenGL line emulation on.
'//     FALSE = OpenGL line emulation off.
'//
'// OpenGL line:     Regular line:
'//   *\                *\
'//   | \              /  \
'//   |  \            *\   \
'//   *\  \             \   \
'//     \  \             \   \
'//      \  *             \   *
'//       \ |              \ /
'//        \|               *
'//         *
'//
'// OnLostDevice, OnResetDevice -
'//    Call OnLostDevice() on this object before calling Reset() on the
'//    device, so that this object can release any stateblocks and video
'//    memory resources.  After Reset(), the call OnResetDevice().
'///////////////////////////////////////////////////////////////////////////


$IID_ID3DXLine = GUID$("{D379BA7F-9042-4AC4-9F5E-58192A4C6BD8}")

INTERFACE ID3DXLine $IID_ID3DXLine

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out LPDIRECT3DDEVICE9* ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Draw ( _                                      ' VTable offset = 20
     BYREF pVertexList AS D3DXVECTOR2 _                 ' __in CONST D3DXVECTOR2 *pVertexList
   , BYVAL dwVertexListCount AS DWORD _                 ' __in DWORD dwVertexListCount
   , BYVAL Color AS DWORD _                             ' __in D3DCOLOR Color
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DrawTransform ( _                             ' VTable offset = 24
     BYREF pVertexList AS D3DXVECTOR3 _                 ' __in CONST D3DXVECTOR3 *pVertexList
   , BYVAL dwVertexListCount AS DWORD _                 ' __in DWORD dwVertexListCount
   , BYREF pTransform AS D3DXMATRIX _                   ' __in CONST D3DXMATRIX* pTransform
   , BYVAL Color AS DWORD _                             ' __in D3DCOLOR Color
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPattern ( _                                ' VTable offset = 28
     BYVAL dwPattern AS DWORD _                         ' __in DWORD dwPattern
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPattern ( _                                ' VTable offset = 32
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD SetPatternScale ( _                           ' VTable offset = 36
     BYVAL fPatternScale AS SINGLE _                    ' __in FLOAT fPatternScale
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPatternScale ( _                           ' VTable offset = 40
   ) AS SINGLE                                          ' SINGLE
   ' =====================================================================================
   METHOD SetWidth ( _                                  ' VTable offset = 44
     BYVAL fWidth AS SINGLE _                           ' __in FLOAT fWidth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWidth ( _                                  ' VTable offset = 44
   ) AS SINGLE                                          ' SINGLE
   ' =====================================================================================
   METHOD SetAntialias ( _                              ' VTable offset = 48
     BYVAL bAntialias AS LONG _                         ' __in BOOL bAntialias
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAntialias ( _                              ' VTable offset = 52
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD SetGLLines ( _                                ' VTable offset = 56
     BYVAL bGLLines AS LONG _                           ' __in BOOL bGLLines
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGLLines ( _                                ' VTable offset = 60
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD End ( _                                       ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnLostDevice ( _                              ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnResetDevice ( _                             ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


DECLARE FUNCTION D3DXCreateLine IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateLine" ( _
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9 pDevice
 , BYREF ppLine AS ID3DXLine _                          ' __out LPD3DXLINE*       ppLine
 ) AS LONG                                              ' HRESULT
