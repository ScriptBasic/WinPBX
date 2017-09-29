' ########################################################################################
' Microsoft Windows
' File: d3dx10core.inc
' Contents: D3DX10 core types and functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3DX10CORE_INC = 1

#INCLUDE ONCE "D3D10_1.inc"

'// Current name of the DLL shipped in the same SDK as this header.

'#define D3DX10_DLL_W L"d3dx10_35.dll"
'#define D3DX10_DLL_A "d3dx10_35.dll"

'#ifdef UNICODE
'    #define D3DX10_DLL D3DX10_DLL_W
'#else
'    #define D3DX10_DLL D3DX10_DLL_A
'#endif

#IF NOT %DEF($D3DX10_DLLNAME)
$D3DX10_DLLNAME = "d3dx10_35.dll"   ' --> change as needed
#ENDIF

#INCLUDE ONCE "d3dx10.inc"

'///////////////////////////////////////////////////////////////////////////
'// D3DX10_SDK_VERSION:
'// -----------------
'// This identifier is passed to D3DX10CheckVersion in order to ensure that an
'// application was built against the correct header files and IMPORT files.
'// This number is incremented whenever a header (or other) change would
'// require applications to be rebuilt. If the version doesn't match,
'// D3DX10CreateVersion will return FALSE. (The number itself has no meaning.)
'///////////////////////////////////////////////////////////////////////////


%D3DX10_SDK_VERSION = 35


'///////////////////////////////////////////////////////////////////////////
'// D3DX10CreateDevice
'// D3DX10CreateDeviceAndSwapChain
'// D3DX10GetFeatureLevel1
'///////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION D3DX10CreateDevice IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateDevice" ( _
   BYVAL pAdapter AS IDXGIAdapter _                     ' __in  IDXGIAdapter *pAdapter
 , BYVAL DriverType AS DWORD _                          ' __in  D3D10_DRIVER_TYPE DriverType
 , BYVAL Software AS DWORD _                            ' __in  HMODULE Software
 , BYVAL Flags AS DWORD _                               ' __in  UINT Flags
 , BYREF ppDevice AS ID3D10Device _                     ' __out ID3D10Device **ppDevice
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10CreateDeviceAndSwapChain IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateDeviceAndSwapChain" ( _
   BYVAL pAdapter AS IDXGIAdapter _                     ' __in  IDXGIAdapter *pAdapter
 , BYVAL DriverType AS DWORD _                          ' __in  D3D10_DRIVER_TYPE DriverType
 , BYVAL Software AS DWORD _                            ' __in  HMODULE Software
 , BYVAL Flags AS DWORD _                               ' __in  UINT Flags
 , BYREF pSwapChainDesc AS DXGI_SWAP_CHAIN_DESC _       ' __in  DXGI_SWAP_CHAIN_DESC *pSwapChainDesc
 , BYREF ppSwapChain AS IDXGISwapChain _                ' __out IDXGISwapChain **ppSwapChain
 , BYREF ppDevice AS ID3D10Device _                     ' __out ID3D10Device **ppDevice
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10GetFeatureLevel1 IMPORT $D3DX10_DLLNAME ALIAS "D3DX10GetFeatureLevel1" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device *pDevice
 , BYREF ppDevice1 AS ID3D10Device1 _                   ' __out ID3D10Device1 ppDevice1
 ) AS LONG                                              ' HRESULT

'#ifdef D3D10_DEBUG
DECLARE FUNCTION D3DX10DebugMute IMPORT $D3DX10_DLLNAME ALIAS "D3DX10DebugMute" ( _
   BYVAL Mute AS LONG _                                 ' __in BOOL Mute
 ) AS LONG                                              ' BOOL
'#endif

DECLARE FUNCTION D3DX10CheckVersion IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CheckVersion" ( _
   BYVAL D3DSdkVersion AS DWORD _                       ' __in UINT D3DSdkVersion
 , BYVAL D3DX10SdkVersion AS DWORD _                    ' __in UINT D3DX10SdkVersion
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10GetDriverLevel IMPORT $D3DX10_DLLNAME ALIAS "D3DX10GetDriverLevel" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in ID3D10Device *pDevice
 ) AS LONG                                              ' BOOL

'//////////////////////////////////////////////////////////////////////////////
'// D3DX10_SPRITE flags:
'// -----------------
'// D3DX10_SPRITE_SAVE_STATE
'//   Specifies device state should be saved and restored in Begin/End.
'// D3DX10SPRITE_SORT_TEXTURE
'//   Sprites are sorted by texture prior to drawing.  This is recommended when
'//   drawing non-overlapping sprites of uniform depth.  For example, drawing
'//   screen-aligned text with ID3DX10Font.
'// D3DX10SPRITE_SORT_DEPTH_FRONT_TO_BACK
'//   Sprites are sorted by depth front-to-back prior to drawing.  This is
'//   recommended when drawing opaque sprites of varying depths.
'// D3DX10SPRITE_SORT_DEPTH_BACK_TO_FRONT
'//   Sprites are sorted by depth back-to-front prior to drawing.  This is
'//   recommended when drawing transparent sprites of varying depths.
'// D3DX10SPRITE_ADDREF_TEXTURES
'//   AddRef/Release all textures passed in to DrawSpritesBuffered
'//////////////////////////////////////////////////////////////////////////////

' enum D3DX10_SPRITE_FLAG
%D3DX10_SPRITE_SORT_TEXTURE              = &H01???
%D3DX10_SPRITE_SORT_DEPTH_BACK_TO_FRONT  = &H02???
%D3DX10_SPRITE_SORT_DEPTH_FRONT_TO_BACK  = &H04???
%D3DX10_SPRITE_SAVE_STATE                = &H08???
%D3DX10_SPRITE_ADDREF_TEXTURES           = &H10???

' // Size = 104 bytes
TYPE D3DX10_SPRITE DWORD
   matWorld      AS D3DXMATRIX
   TexCoord      AS D3DXVECTOR2
   TexSize       AS D3DXVECTOR2
   ColorModulate AS D3DXCOLOR
   pTexture      AS DWORD PTR   ' ID3D10ShaderResourceView
   TextureIndex  AS DWORD       ' UINT
END TYPE


'//////////////////////////////////////////////////////////////////////////////
'// ID3DX10Sprite:
'// ------------
'// This object intends to provide an easy way to drawing sprites using D3D.
'//
'// Begin -
'//    Prepares device for drawing sprites.
'//
'// Draw -
'//    Draws a sprite
'//
'// Flush -
'//    Forces all batched sprites to submitted to the device.
'//
'// End -
'//    Restores device state to how it was when Begin was called.
'//
'//////////////////////////////////////////////////////////////////////////////

' ########################################################################################
' ID3DX10Sprite interface
' IID = 9B7E4E00-342C-4106-A19F-4F2704F689F0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ID3DX10Sprite_INTERFACE_DEFINED)
    %ID3DX10Sprite_INTERFACE_DEFINED = 1

$IID_ID3DX10Sprite = GUID$("{BA0B762D-8D28-43EC-B9DC-2F84443B0614}")

INTERFACE ID3DX10Sprite $IID_ID3DX10Sprite

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Begin ( _                                     ' VTable offset = 12
     BYVAL flags AS DWORD _                             ' __in UINT flags
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD DrawSpritesBuffered ( _                       ' VTable offset = 16
     BYREF pSprites AS D3DX10_SPRITE _                  ' __in D3DX10_SPRITE *pSprites
   , BYVAL cSprites AS DWORD _                          ' __in UINT cSprites
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD Flush ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD DrawSpritesImmediate ( _                      ' VTable offset = 24
     BYREF pSprites AS D3DX10_SPRITE _                  ' __in D3DX10_SPRITE *pSprites
   , BYVAL cSprites AS DWORD _                          ' __in UINT cSprites
   , BYVAL cbSprite AS DWORD _                          ' __in UINT cbSprite
   , BYVAL flags AS DWORD _                             ' __in UINT flags
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD End ( _                                       ' VTable offset = 28
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD GetViewTransform ( _                          ' VTable offset = 32
     BYREF pViewTransform AS D3DXMATRIX _               ' __out D3DXMATRIX *pViewTransform
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD SetViewTransform ( _                          ' VTable offset = 36
     BYREF pViewTransform AS D3DXMATRIX _               ' __in D3DXMATRIX *pViewTransform
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD GetProjectionTransform ( _                    ' VTable offset = 40
     BYREF pProjectionTransform AS D3DXMATRIX _         ' __out D3DXMATRIX *pProjectionTransform
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD SetProjectionTransform ( _                    ' VTable offset = 44
     BYREF pProjectionTransform AS D3DXMATRIX _         ' __in D3DXMATRIX *pProjectionTransform
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 48
     BYREF ppDevice AS ID3D10Device _                   ' __out ID3D10Device** ppDevice
   ) AS LONG                                            ' BOOL
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3DX10Sprite_INTERFACE_DEFINED__ */


DECLARE FUNCTION D3DX10CreateSprite IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateSprite" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device*         pDevice
 , BYVAL cDeviceBufferSize AS DWORD _                   ' __in  UINT                  cDeviceBufferSize
 , BYREF ppSprite AS ID3DX10Sprite _                    ' __out LPD3DX10SPRITE*       ppSprite
 ) AS LONG                                              ' HRESULT


' ########################################################################################
' ID3DX10ThreadPump interface
' IID = C93FECFA-6967-478A-ABBC-402D90621FCB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ID3DX10ThreadPump_INTERFACE_DEFINED)
    %ID3DX10ThreadPump_INTERFACE_DEFINED = 1

$IID_ID3DX10ThreadPump = GUID$("{C93FECFA-6967-478A-ABBC-402D90621FCB}")

INTERFACE ID3DX10ThreadPump $IID_ID3DX10ThreadPump

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddWorkItem ( _                               ' VTable offset = 12
     BYVAL pDataLoader AS DWORD _                       ' __in  ID3DX10DataLoader *pDataLoader
   , BYVAL pDataProcessor AS DWORD _                    ' __in  ID3DX10DataProcessor *pDataProcessor
   , BYREF pHResult AS LONG _                           ' __in  HRESULT *pHResult
   , BYREF ppDeviceObject AS DWORD _                    ' __out void **ppDeviceObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWorkItemCount ( _                          ' VTable offset = 16
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD WaitForAllItems ( _                           ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessDeviceWorkItems ( _                    ' VTable offset = 24
     BYVAL iWorkItemCount AS DWORD _                    ' __in UINT iWorkItemCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PurgeAllItems ( _                             ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetQueueStatus ( _                            ' VTable offset = 32
     BYREF pIoQueue AS DWORD _                          ' __out UINT *pIoQueue
   , BYREF pProcessQueue AS DWORD _                     ' __out UINT *pProcessQueue
   , BYREF pDeviceQueue AS DWORD _                      ' __out UINT *pDeviceQueue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3DX10ThreadPump_INTERFACE_DEFINED__ */


DECLARE FUNCTION D3DX10CreateThreadPump IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateThreadPump" ( _
   BYVAL cIoThreads AS DWORD _                          ' __in  UINT cIoThreads
 , BYVAL cProcThreads AS DWORD _                        ' __in  UINT cProcThreads
 , BYREF ppThreadPump AS ID3DX10ThreadPump _            ' __out ID3DX10ThreadPump **ppThreadPump
 ) AS LONG                                              ' HRESULT


'//////////////////////////////////////////////////////////////////////////////
'// ID3DX10Font:
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
'//////////////////////////////////////////////////////////////////////////////

' // Size = 56 bytes
TYPE D3DX10_FONT_DESCA BYTE
   Height          AS LONG                    ' INT
   Width           AS DWORD                   ' UINT
   Weight          AS DWORD                   ' UINT
   MipLevels       AS DWORD                   ' UINT
   Italic          AS LONG                    ' BOOL
   CharSet         AS BYTE                    ' BYTE
   OutputPrecision AS BYTE                    ' BYTE
   Quality         AS BYTE                    ' BYTE
   PitchAndFamily  AS BYTE                    ' BYTE
   FaceName        AS ASCIIZ * %LF_FACESIZE   ' CHAR
END TYPE

MACRO D3DX10_FONT_DESC = D3DX10_FONT_DESCA

' // Size = 88 bytes
TYPE D3DX10_FONT_DESCW BYTE
   Height          AS LONG                      ' INT
   Width           AS DWORD                     ' UINT
   Weight          AS DWORD                     ' UINT
   MipLevels       AS DWORD                     ' UINT
   Italic          AS LONG                      ' BOOL
   CharSet         AS BYTE                      ' BYTE
   OutputPrecision AS BYTE                      ' BYTE
   Quality         AS BYTE                      ' BYTE
   PitchAndFamily  AS BYTE                      ' BYTE
   FaceName        AS WSTRINGZ * %LF_FACESIZE   ' WCHAR
END TYPE

' ########################################################################################
' ID3DX10Font interface
' IID = D79DBB70-5F21-4D36-BBC2-FF525C213CDC}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ID3DX10Font_INTERFACE_DEFINED)
    %ID3DX10Font_INTERFACE_DEFINED = 1

$IID_ID3DX10Font = GUID$("{D79DBB70-5F21-4D36-BBC2-FF525C213CDC}}")

INTERFACE ID3DX10Font $IID_ID3DX10Font

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS ID3D10Device _                   ' __out ID3D10Device** ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 16
     BYREF pDesc AS D3DX10_FONT_DESC _                  ' __out D3DX10_FONT_DESCA *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescW ( _                                  ' VTable offset = 20
     BYREF pDesc AS D3DX10_FONT_DESCW _                 ' __out D3DX10_FONT_DESCW *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTextMetrics ( _                            ' VTable offset = 24
     BYREF pTextMetrics AS TEXTMETRIC _                 ' __out TEXTMETRICA *pTextMetrics
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD GetTextMetricsW ( _                           ' VTable offset = 28
     BYREF pTextMetrics AS TEXTMETRICW _                ' __out TEXTMETRICW *pTextMetrics
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD GetDC ( _                                     ' VTable offset = 32
   ) AS DWORD                                           ' HDC
   ' =====================================================================================
   METHOD GetGlyphData ( _                              ' VTable offset = 32
     BYVAL Glyph AS DWORD _                             ' __in  UINT Glyph
   , BYREF ppTexture AS ID3D10ShaderResourceView _      ' __out ID3D10ShaderResourceView** ppTexture
   , BYREF pBlackBox AS RECT _                          ' __out RECT *pBlackBox
   , BYREF pCellInc AS POINT _                          ' __out POINT *pCellInc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PreloadCharacters ( _                         ' VTable offset = 36
     BYVAL First AS DWORD _                             ' __in UINT First
   , BYVAL Last AS DWORD _                              ' __in UINT Last
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PreloadGlyphs ( _                             ' VTable offset = 40
     BYVAL First AS DWORD _                             ' __in UINT First
   , BYVAL Last AS DWORD _                              ' __in UINT Last
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PreloadText ( _                               ' VTable offset = 44
     BYREF pString AS ASCIIZ _                          ' __in LPCSTR pString
   , BYVAL Count AS LONG _                              ' __in INT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PreloadTextW ( _                              ' VTable offset = 48
     BYREF pString AS WSTRINGZ _                        ' __in LPCWSTR pString
   , BYVAL Count AS LONG _                              ' __in INT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DrawText ( _                                  ' VTable offset = 52
     BYVAL pSprite AS ID3DX10Sprite _                   ' __in LPD3DX10SPRITE pSprite
   , BYREF pString AS ASCIIZ _                          ' __in LPCSTR pString
   , BYVAL Count AS LONG _                              ' __in INT Count
   , BYREF pRect AS RECT _                              ' __in LPRECT pRect
   , BYVAL Format AS DWORD _                            ' __in UINT Format
   , BYREF Color AS D3DXCOLOR _                         ' __in D3DXCOLOR Color
   ) AS LONG                                            ' INT
   ' =====================================================================================
   METHOD DrawTextW ( _                                 ' VTable offset = 56
     BYVAL pSprite AS ID3DX10Sprite _                   ' __in LPD3DX10SPRITE pSprite
   , BYREF pString AS WSTRINGZ _                        ' __in LPCWSTR pString
   , BYVAL Count AS LONG _                              ' __in INT Count
   , BYREF pRect AS RECT _                              ' __in LPRECT pRect
   , BYVAL Format AS DWORD _                            ' __in UINT Format
   , BYREF Color AS D3DXCOLOR _                         ' __in D3DXCOLOR Color
   ) AS LONG                                            ' INT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3DX10Font_INTERFACE_DEFINED__ */


DECLARE FUNCTION D3DX10CreateFontA IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateFontA" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device* pDevice
 , BYVAL Height AS LONG _                               ' __in  INT           Height
 , BYVAL Width AS DWORD _                               ' __in  UINT          Width
 , BYVAL Weight AS DWORD _                              ' __in  UINT          Weight
 , BYVAL MipLevels AS DWORD _                           ' __in  UINT          MipLevels
 , BYVAL Italic AS LONG _                               ' __in  BOOL          Italic
 , BYVAL CharSet AS DWORD _                             ' __in  UINT          CharSet
 , BYVAL OutputPrecision AS DWORD _                     ' __in  UINT          OutputPrecision
 , BYVAL Quality AS DWORD _                             ' __in  UINT          Quality
 , BYVAL PitchAndFamily AS DWORD _                      ' __in  UINT          PitchAndFamily
 , BYREF pFaceName AS ASCIIZ _                          ' __in  LPCSTR        pFaceName
 , BYREF ppFont AS ID3DX10Font _                        ' __out LPD3DX10FONT* ppFont
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10CreateFontW IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateFontW" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device* pDevice
 , BYVAL Height AS LONG _                               ' __in  INT           Height
 , BYVAL Width AS DWORD _                               ' __in  UINT          Width
 , BYVAL Weight AS DWORD _                              ' __in  UINT          Weight
 , BYVAL MipLevels AS DWORD _                           ' __in  UINT          MipLevels
 , BYVAL Italic AS LONG _                               ' __in  BOOL          Italic
 , BYVAL CharSet AS DWORD _                             ' __in  UINT          CharSet
 , BYVAL OutputPrecision AS DWORD _                     ' __in  UINT          OutputPrecision
 , BYVAL Quality AS DWORD _                             ' __in  UINT          Quality
 , BYVAL PitchAndFamily AS DWORD _                      ' __in  UINT          PitchAndFamily
 , BYREF pFaceName AS WSTRINGZ _                        ' __in  LPCWSTR       pFaceName
 , BYREF ppFont AS ID3DX10Font _                        ' __out LPD3DX10FONT* ppFont
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DX10CreateFont = D3DX10CreateFontW
#ELSE
   MACRO D3DX10CreateFont = D3DX10CreateFontA
#ENDIF

DECLARE FUNCTION D3DX10CreateFontIndirectA IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateFontIndirectA" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device*            pDevice
 , BYREF pDesc AS D3DX10_FONT_DESC _                    ' __in  CONST D3DX10_FONT_DESCA* pDesc
 , BYREF ppFont AS ID3DX10Font _                        ' __out LPD3DX10FONT*            ppFont
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DX10CreateFontIndirectW IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateFontIndirectW" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device*            pDevice
 , BYREF pDesc AS D3DX10_FONT_DESCW _                   ' __in  CONST D3DX10_FONT_DESCW* pDesc
 , BYREF ppFont AS ID3DX10Font _                        ' __out LPD3DX10FONT*            ppFont
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DX10CreateFontIndirect = D3DX10CreateFontIndirectW
#ELSE
   MACRO D3DX10CreateFontIndirect = D3DX10CreateFontIndirectA
#ENDIF

DECLARE FUNCTION D3DX10UnsetAllDeviceObjects IMPORT $D3DX10_DLLNAME ALIAS "D3DX10UnsetAllDeviceObjects" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in ID3D10Device*            pDevice
 ) AS LONG                                              ' HRESULT

'//////////////////////////////////////////////////////////////////////////////
'// D3DX10ReflectShader
'// ----------
'// Shader code contains metadata that can be inspected via the
'// reflection APIs.
'//
'// Parameters:
'//  ppReflector -
'//    Returns a reflection API interface for the given shader code.
'//
'//////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION D3DX10ReflectShader IMPORT $D3DX10_DLLNAME ALIAS "D3DX10ReflectShader" ( _
   BYVAL pShaderBytecode AS DWORD _                     ' __in  CONST void *pShaderBytecode
 , BYVAL BytecodeLength AS DWORD _                      ' __in  SIZE_T BytecodeLength
 , BYREF ppReflector AS ID3D10ShaderReflection1 _       ' __out interface ID3D10ShaderReflection1 **ppReflector
 ) AS LONG                                              ' HRESULT

'//----------------------------------------------------------------------------
'// D3DX10DisassembleShader:
'// ----------------------
'// Takes a binary shader, and returns a buffer containing text assembly.
'//
'// Parameters:
'//  pShader
'//      Pointer to the shader byte code.
'//  BytecodeLength
'//      Size of the shader byte code in bytes.
'//  EnableColorCode
'//      Emit HTML tags for color coding the output?
'//  pComments
'//      Pointer to a comment string to include at the top of the shader.
'//  ppDisassembly
'//      Returns a buffer containing the disassembled shader.
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DX10DisassembleShader IMPORT $D3DX10_DLLNAME ALIAS "D3DX10DisassembleShader" ( _
   BYVAL pShader AS DWORD _                             ' __in  CONST void *pShader
 , BYVAL BytecodeLength AS DWORD _                      ' __in  SIZE_T BytecodeLength
 , BYVAL EnableColorCode AS LONG _                      ' __in  BOOL EnableColorCode
 , BYREF pComments AS ASCIIZ _                          ' __in  LPCSTR pComments
 , BYREF ppDisassembly AS ID3D10Blob _                  ' __out interface ID3D10Blob** ppDisassembly
 ) AS LONG                                              ' HRESULT

'//----------------------------------------------------------------------------
'// D3DX10DisassembleEffect:
'// -----------------------
'// Takes an effect interface, and returns a buffer containing text assembly.
'//
'// Parameters:
'//  pEffect
'//      Pointer to the runtime effect interface.
'//  EnableColorCode
'//      Emit HTML tags for color coding the output?
'//  ppDisassembly
'//      Returns a buffer containing the disassembled effect.
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DX10DisassembleEffect IMPORT $D3DX10_DLLNAME ALIAS "D3DX10DisassembleEffect" ( _
   BYVAL pEffect AS ID3D10Effect _                      ' __in  interface ID3D10Effect *pEffect
 , BYVAL EnableColorCode AS LONG _                      ' __in  BOOL EnableColorCode
 , BYREF ppDisassembly AS ID3D10Blob _                  ' __out interface ID3D10Blob **ppDisassembly
 ) AS LONG                                              ' HRESULT

'///////////////////////////////////////////////////////////////////////////

%FACD3D = &H876

MACRO MAKE_D3DHRESULT(code) = MAKE_HRESULT(1, %FACD3D, code)
MACRO MAKE_D3DSTATUS(code)  = MAKE_HRESULT(0, %FACD3D, code)

'#define D3DERR_INVALIDCALL                      MAKE_D3DHRESULT(2156)
'#define D3DERR_WASSTILLDRAWING                  MAKE_D3DHRESULT(540)

%D3DERR_INVALIDCALL     = &H8876086C&
%D3DERR_WASSTILLDRAWING = &H8876021C&
