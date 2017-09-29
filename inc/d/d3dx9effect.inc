' ########################################################################################
' Microsoft Windows
' File: d3dx9effect.inc
' Contents: D3DX effect types and Shaders
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3DX9EFFECT_INC = 1

#INCLUDE ONCE "d3dx9.inc"

'//----------------------------------------------------------------------------
'// D3DXFX_DONOTSAVESTATE
'//   This flag is used as a parameter to ID3DXEffect::Begin().  When this flag
'//   is specified, device state is not saved or restored in Begin/End.
'// D3DXFX_DONOTSAVESHADERSTATE
'//   This flag is used as a parameter to ID3DXEffect::Begin().  When this flag
'//   is specified, shader device state is not saved or restored in Begin/End.
'//   This includes pixel/vertex shaders and shader constants
'// D3DXFX_DONOTSAVESAMPLERSTATE
'//   This flag is used as a parameter to ID3DXEffect::Begin(). When this flag
'//   is specified, sampler device state is not saved or restored in Begin/End.
'// D3DXFX_NOT_CLONEABLE
'//   This flag is used as a parameter to the D3DXCreateEffect family of APIs.
'//   When this flag is specified, the effect will be non-cloneable and will not
'//   contain any shader binary data.
'//   Furthermore, GetPassDesc will not return shader function pointers.
'//   Setting this flag reduces effect memory usage by about 50%.
'//----------------------------------------------------------------------------

%D3DXFX_DONOTSAVESTATE        = 1         ' (1 << 0)
%D3DXFX_DONOTSAVESHADERSTATE  = 2         ' (1 << 1)
%D3DXFX_DONOTSAVESAMPLERSTATE = 4         ' (1 << 2)

%D3DXFX_NOT_CLONEABLE         = &H800     ' (1 << 11)
%D3DXFX_LARGEADDRESSAWARE     = &H20000   ' (1 << 17)

'//----------------------------------------------------------------------------
'// D3DX_PARAMETER_SHARED
'//   Indicates that the value of a parameter will be shared with all effects
'//   which share the same namespace.  Changing the value in one effect will
'//   change it in all.
'//
'// D3DX_PARAMETER_LITERAL
'//   Indicates that the value of this parameter can be treated as literal.
'//   Literal parameters can be marked when the effect is compiled, and their
'//   cannot be changed after the effect is compiled.  Shared parameters cannot
'//   be literal.
'//----------------------------------------------------------------------------

%D3DX_PARAMETER_SHARED      = 1   ' (1 << 0)
%D3DX_PARAMETER_LITERAL     = 2   ' (1 << 1)
%D3DX_PARAMETER_ANNOTATION  = 4   ' (1 << 2)

'//----------------------------------------------------------------------------
'// D3DXEFFECT_DESC:
'//----------------------------------------------------------------------------

' // Size = 16 bytes
TYPE D3DXEFFECT_DESC DWORD
   Creator    AS ASCIIZ PTR   ' LPCSTR // Creator string
   Parameters AS DWORD        ' UINT   // Number of parameters
   Techniques AS DWORD        ' UINT   // Number of techniques
   Functions  AS DWORD        ' UINT   // Number of function entrypoints
END TYPE

'//----------------------------------------------------------------------------
'// D3DXPARAMETER_DESC:
'//----------------------------------------------------------------------------

' // Size = 44 bytes
TYPE D3DXPARAMETER_DESC DWORD
   Name          AS ASCIIZ PTR   ' LPCSTR // Parameter name
   Semantic      AS ASCIIZ PTR   ' LPCSTR // Parameter semantic
   Class         AS DWORD        ' D3DXPARAMETER_CLASS // Class
   Type          AS DWORD        ' D3DXPARAMETER_TYPE // Component type
   Rows          AS DWORD        ' UINT   // Number of rows
   Columns       AS DWORD        ' UINT   // Number of columns
   Elements      AS DWORD        ' UINT   // Number of array elements
   Annotations   AS DWORD        ' UINT   // Number of annotations
   StructMembers AS DWORD        ' UINT   // Number of structure member sub-parameters
   Flags         AS DWORD        ' DWORD  // D3DX_PARAMETER_* flags
   Bytes         AS DWORD        ' UINT   // Parameter size, in bytes
END TYPE

'//----------------------------------------------------------------------------
'// D3DXTECHNIQUE_DESC:
'//----------------------------------------------------------------------------

' // Size = 12 bytes
TYPE D3DXTECHNIQUE_DESC DWORD
   Name        AS ASCIIZ PTR   ' LPCSTR // Technique name
   Passes      AS DWORD        ' UINT   // Number of passes
   Annotations AS DWORD        ' UINT   // Number of annotations
END TYPE

'//----------------------------------------------------------------------------
'// D3DXPASS_DESC:
'//----------------------------------------------------------------------------

' // Size = 16 bytes
TYPE D3DXPASS_DESC DWORD
   Name                  AS ASCIIZ PTR   ' LPCSTR // Pass name
   Annotations           AS DWORD        ' UINT   // Number of annotations
   pVertexShaderFunction AS DWORD        ' CONST DWORD * // Vertex shader function
   pPixelShaderFunction  AS DWORD        ' CONST DWORD * // Pixel shader function
END TYPE

'//----------------------------------------------------------------------------
'// D3DXFUNCTION_DESC:
'//----------------------------------------------------------------------------

' // Size = 8 bytes
TYPE D3DXFUNCTION_DESC DWORD
   Name        AS ASCIIZ PTR   ' LPCSTR // Function name
   Annotations AS DWORD        ' UINT   // Number of annotations
END TYPE


'//////////////////////////////////////////////////////////////////////////////
'// ID3DXEffectPool ///////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

$IID_ID3DXEffectPool = GUID$("{9537AB04-3250-412e-8213-FCD2F8677933}")

INTERFACE ID3DXEffectPool $IID_ID3DXEffectPool

   INHERIT IUnknown

   ' // No public methods

END INTERFACE


'//////////////////////////////////////////////////////////////////////////////
'// ID3DXBaseEffect ///////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

$IID_ID3DXBaseEffect = GUID$("{3B7A6FFB-3A69-46d7-BC01-A6B2AD4C2BB0}")

INTERFACE ID3DXBaseEffect $IID_ID3DXBaseEffect

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 12
     BYREF pDesc AS D3DXEFFECT_DESC _                   ' __out D3DXEFFECT_DESC* pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParameterDesc ( _                          ' VTable offset = 16
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pDesc AS D3DXPARAMETER_DESC _                ' __out D3DXPARAMETER_DESC* pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTechniqueDesc ( _                          ' VTable offset = 20
     BYVAL hTechnique AS DWORD _                        ' __in  D3DXHANDLE hTechnique
   , BYREF pDesc AS D3DXTECHNIQUE_DESC _                ' __out D3DXTECHNIQUE_DESC* pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPassDesc ( _                               ' VTable offset = 24
     BYVAL hTechnique AS DWORD _                        ' __in  D3DXHANDLE hTechnique
   , BYREF pDesc AS D3DXPASS_DESC _                     ' __out D3DXPASS_DESC* pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFunctionDesc ( _                           ' VTable offset = 28
     BYVAL hShader AS DWORD _                           ' __in  D3DXHANDLE hShader
   , BYREF pDesc AS D3DXFUNCTION_DESC _                 ' __out D3DXFUNCTION_DESC* pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParameter ( _                              ' VTable offset = 32
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetParameterByName ( _                        ' VTable offset = 36
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pName AS ASCIIZ _                            ' __in LPCSTR pName
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetParameterBySemantic ( _                    ' VTable offset = 40
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pSemantic AS ASCIIZ _                        ' __in LPCSTR pSemantic
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetParameterElement ( _                       ' VTable offset = 44
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetTechnique ( _                              ' VTable offset = 48
     BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetTechniqueByName ( _                        ' VTable offset = 52
     BYREF pName AS ASCIIZ _                            ' __in LPCSTR pName
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetPass ( _                                   ' VTable offset = 56
     BYVAL hTechnique AS DWORD _                        ' __in D3DXHANDLE hTechnique
   , BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetPassByName ( _                             ' VTable offset = 60
     BYVAL hTechnique AS DWORD _                        ' __in D3DXHANDLE hTechnique
   , BYREF pName AS ASCIIZ _                            ' __in LPCSTR pName
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetFunction ( _                               ' VTable offset = 64
     BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetFunctionByName ( _                         ' VTable offset = 68
     BYREF pName AS ASCIIZ _                            ' __in LPCSTR pName
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetAnnotation ( _                             ' VTable offset = 72
     BYVAL hObject AS DWORD _                           ' __in D3DXHANDLE hObject
   , BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetAnnotationByName ( _                       ' VTable offset = 76
     BYVAL hObject AS DWORD _                           ' __in D3DXHANDLE hObject
   , BYREF pName AS ASCIIZ _                            ' __in LPCSTR pName
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 80
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL pData AS DWORD _                             ' __in LPCVOID pData
   , BYVAL Bytes AS DWORD _                             ' __in UINT Bytes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 84
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL pData AS DWORD _                             ' __in LPVOID pData
   , BYVAL Bytes AS DWORD _                             ' __in UINT Bytes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBool ( _                                   ' VTable offset = 88
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL b AS LONG _                                  ' __in BOOL b
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBool ( _                                   ' VTable offset = 92
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pb AS LONG _                                 ' __out BOOL* pb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBoolArray ( _                              ' VTable offset = 96
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pb AS LONG _                                 ' __in BOOL* pb
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBoolArray ( _                              ' VTable offset = 100
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pb AS LONG _                                 ' __out BOOL* pb
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInt ( _                                    ' VTable offset = 104
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL n AS LONG _                                  ' __in INT n
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInt ( _                                    ' VTable offset = 108
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pn AS LONG _                                 ' __out INT* pn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIntArray ( _                               ' VTable offset = 112
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pn AS LONG _                                 ' __in CONST INT* pn
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIntArray ( _                               ' VTable offset = 116
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pn AS LONG _                                 ' __out INT* pn
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFloat ( _                                  ' VTable offset = 120
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL f AS SINGLE _                                ' __in FLOAT f
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFloat ( _                                  ' VTable offset = 124
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pf AS SINGLE _                               ' __out FLOAT* pf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFloatArray ( _                             ' VTable offset = 128
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pf AS SINGLE _                               ' __in CONST FLOAT* pf
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFloatArray ( _                             ' VTable offset = 132
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pf AS SINGLE _                               ' __out FLOAT* pf
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVector ( _                                 ' VTable offset = 136
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pVector AS D3DXVECTOR4 _                     ' __in CONST D3DXVECTOR4* pVector
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVector ( _                                 ' VTable offset = 140
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pVector AS D3DXVECTOR4 _                     ' __out D3DXVECTOR4* pVector
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVectorArray ( _                            ' VTable offset = 144
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pVector AS D3DXVECTOR4 _                     ' __in CONST D3DXVECTOR4* pVector
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVectorArray ( _                            ' VTable offset = 148
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pVector AS D3DXVECTOR4 _                     ' __out D3DXVECTOR4* pVector
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrix ( _                                 ' VTable offset = 152
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pMatrix AS D3DXMATRIX _                      ' __in CONST D3DXMATRIX* pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMatrix ( _                                 ' VTable offset = 156
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pMatrix AS D3DXMATRIX _                      ' __out D3DXMATRIX* pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixArray ( _                            ' VTable offset = 160
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pMatrix AS D3DXMATRIX _                      ' __in CONST D3DXMATRIX* pMatrix
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMatrixArray ( _                            ' VTable offset = 164
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pMatrix AS D3DXMATRIX _                      ' __out D3DXMATRIX* pMatrix
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixPointerArray ( _                     ' VTable offset = 168
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL pMatrix AS DWORD _                           ' __in CONST D3DXMATRIX** pMatrix
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMatrixPointerArray ( _                     ' VTable offset = 172
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pMatrix AS DWORD _                           ' __out D3DXMATRIX** pMatrix
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixTranspose ( _                        ' VTable offset = 176
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL pMatrix AS D3DXMATRIX _                      ' __in CONST D3DXMATRIX* pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMatrixTranspose ( _                        ' VTable offset = 180
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYVAL pMatrix AS D3DXMATRIX _                      ' __out D3DXMATRIX* pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixTransposeArray ( _                   ' VTable offset = 184
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL pMatrix AS D3DXMATRIX _                      ' __in CONST D3DXMATRIX* pMatrix
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMatrixTransposeArray ( _                   ' VTable offset = 188
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYVAL pMatrix AS D3DXMATRIX _                      ' __out D3DXMATRIX* pMatrix
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixTransposePointerArray ( _            ' VTable offset = 192
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL ppMatrix AS DWORD _                          ' __in D3DXMATRIX** ppMatrix
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMatrixTransposePointerArray ( _            ' VTable offset = 196
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF ppMatrix AS DWORD _                          ' __out D3DXMATRIX** ppMatrix
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetString ( _                                 ' VTable offset = 200
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pString AS ASCIIZ _                          ' __in LPCSTR pString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 204
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pString AS ASCIIZ _                          ' __out LPCSTR* pString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTexture ( _                                ' VTable offset = 208
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL pTexture AS IDirect3DBaseTexture9 _          ' __in LPDIRECT3DBASETEXTURE9 pTexture
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTexture ( _                                ' VTable offset = 212
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF ppTexture AS IDirect3DBaseTexture9 _         ' __out LPDIRECT3DBASETEXTURE9 *ppTexture
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPixelShader ( _                            ' VTable offset = 216
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL pPShader AS IDirect3DPixelShader9 _          ' __in LPDIRECT3DPIXELSHADER9 pPShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelShader ( _                            ' VTable offset = 220
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF ppPShader AS IDirect3DPixelShader9 _         ' __out LPDIRECT3DPIXELSHADER9 *ppPShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVertexShader ( _                           ' VTable offset = 224
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL pVShader AS IDirect3DVertexShader9 _         ' __in LPDIRECT3DVERTEXSHADER9 pVShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVertexShader ( _                           ' VTable offset = 228
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF ppVShader AS IDirect3DVertexShader9 _        ' __out LPDIRECT3DVERTEXSHADER9 *ppVShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetArrayRange ( _                             ' VTable offset = 232
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL uStart AS DWORD _                            ' __in UINT uStart
   , BYVAL uEnd AS DWORD _                              ' __in UINT uEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'//----------------------------------------------------------------------------
'// ID3DXEffectStateManager:
'// ------------------------
'// This is a user implemented interface that can be used to manage device
'// state changes made by an Effect.
'//----------------------------------------------------------------------------

$IID_ID3DXEffectStateManager = GUID$("{79AAB587-6DBC-4fa7-82DE-37FA1781C5CE}")

'DECLARE_INTERFACE_(ID3DXEffectStateManager, IUnknown)
'{
'    // The user must correctly implement QueryInterface, AddRef, and Release.

'    // IUnknown
'    STDMETHOD(QueryInterface)(THIS_ REFIID iid, LPVOID *ppv) PURE;
'    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
'    STDMETHOD_(ULONG, Release)(THIS) PURE;

'    // The following methods are called by the Effect when it wants to make
'    // the corresponding device call.  Note that:
'    // 1. Users manage the state and are therefore responsible for making the
'    //    the corresponding device calls themselves inside their callbacks.
'    // 2. Effects pay attention to the return values of the callbacks, and so
'    //    users must pay attention to what they return in their callbacks.

'    STDMETHOD(SetTransform)(THIS_ D3DTRANSFORMSTATETYPE State, CONST D3DMATRIX *pMatrix) PURE;
'    STDMETHOD(SetMaterial)(THIS_ CONST D3DMATERIAL9 *pMaterial) PURE;
'    STDMETHOD(SetLight)(THIS_ DWORD Index, CONST D3DLIGHT9 *pLight) PURE;
'    STDMETHOD(LightEnable)(THIS_ DWORD Index, BOOL Enable) PURE;
'    STDMETHOD(SetRenderState)(THIS_ D3DRENDERSTATETYPE State, DWORD Value) PURE;
'    STDMETHOD(SetTexture)(THIS_ DWORD Stage, LPDIRECT3DBASETEXTURE9 pTexture) PURE;
'    STDMETHOD(SetTextureStageState)(THIS_ DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value) PURE;
'    STDMETHOD(SetSamplerState)(THIS_ DWORD Sampler, D3DSAMPLERSTATETYPE Type, DWORD Value) PURE;
'    STDMETHOD(SetNPatchMode)(THIS_ FLOAT NumSegments) PURE;
'    STDMETHOD(SetFVF)(THIS_ DWORD FVF) PURE;
'    STDMETHOD(SetVertexShader)(THIS_ LPDIRECT3DVERTEXSHADER9 pShader) PURE;
'    STDMETHOD(SetVertexShaderConstantF)(THIS_ UINT RegisterIndex, CONST FLOAT *pConstantData, UINT RegisterCount) PURE;
'    STDMETHOD(SetVertexShaderConstantI)(THIS_ UINT RegisterIndex, CONST INT *pConstantData, UINT RegisterCount) PURE;
'    STDMETHOD(SetVertexShaderConstantB)(THIS_ UINT RegisterIndex, CONST BOOL *pConstantData, UINT RegisterCount) PURE;
'    STDMETHOD(SetPixelShader)(THIS_ LPDIRECT3DPIXELSHADER9 pShader) PURE;
'    STDMETHOD(SetPixelShaderConstantF)(THIS_ UINT RegisterIndex, CONST FLOAT *pConstantData, UINT RegisterCount) PURE;
'    STDMETHOD(SetPixelShaderConstantI)(THIS_ UINT RegisterIndex, CONST INT *pConstantData, UINT RegisterCount) PURE;
'    STDMETHOD(SetPixelShaderConstantB)(THIS_ UINT RegisterIndex, CONST BOOL *pConstantData, UINT RegisterCount) PURE;
'};


'//////////////////////////////////////////////////////////////////////////////
'// ID3DXEffect ///////////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

$IID_ID3DXEffect = GUID$("{0F0DCC9F-6152-4117-A933-FFAC29C43AA4}")

INTERFACE ID3DXEffect $IID_ID3DXEffect

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3DXBaseEffect methods
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 12
     BYREF pDesc AS D3DXEFFECT_DESC _                   ' __out D3DXEFFECT_DESC* pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParameterDesc ( _                          ' VTable offset = 16
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pDesc AS D3DXPARAMETER_DESC _                ' __out D3DXPARAMETER_DESC* pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTechniqueDesc ( _                          ' VTable offset = 20
     BYVAL hTechnique AS DWORD _                        ' __in  D3DXHANDLE hTechnique
   , BYREF pDesc AS D3DXTECHNIQUE_DESC _                ' __out D3DXTECHNIQUE_DESC* pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPassDesc ( _                               ' VTable offset = 24
     BYVAL hTechnique AS DWORD _                        ' __in  D3DXHANDLE hTechnique
   , BYREF pDesc AS D3DXPASS_DESC _                     ' __out D3DXPASS_DESC* pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFunctionDesc ( _                           ' VTable offset = 28
     BYVAL hShader AS DWORD _                           ' __in  D3DXHANDLE hShader
   , BYREF pDesc AS D3DXFUNCTION_DESC _                 ' __out D3DXFUNCTION_DESC* pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParameter ( _                              ' VTable offset = 32
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetParameterByName ( _                        ' VTable offset = 36
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pName AS ASCIIZ _                            ' __in LPCSTR pName
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetParameterBySemantic ( _                    ' VTable offset = 40
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pSemantic AS ASCIIZ _                        ' __in LPCSTR pSemantic
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetParameterElement ( _                       ' VTable offset = 44
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetTechnique ( _                              ' VTable offset = 48
     BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetTechniqueByName ( _                        ' VTable offset = 52
     BYREF pName AS ASCIIZ _                            ' __in LPCSTR pName
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetPass ( _                                   ' VTable offset = 56
     BYVAL hTechnique AS DWORD _                        ' __in D3DXHANDLE hTechnique
   , BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetPassByName ( _                             ' VTable offset = 60
     BYVAL hTechnique AS DWORD _                        ' __in D3DXHANDLE hTechnique
   , BYREF pName AS ASCIIZ _                            ' __in LPCSTR pName
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetFunction ( _                               ' VTable offset = 64
     BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetFunctionByName ( _                         ' VTable offset = 68
     BYREF pName AS ASCIIZ _                            ' __in LPCSTR pName
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetAnnotation ( _                             ' VTable offset = 72
     BYVAL hObject AS DWORD _                           ' __in D3DXHANDLE hObject
   , BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetAnnotationByName ( _                       ' VTable offset = 76
     BYVAL hObject AS DWORD _                           ' __in D3DXHANDLE hObject
   , BYREF pName AS ASCIIZ _                            ' __in LPCSTR pName
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 80
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL pData AS DWORD _                             ' __in LPCVOID pData
   , BYVAL Bytes AS DWORD _                             ' __in UINT Bytes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 84
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL pData AS DWORD _                             ' __in LPVOID pData
   , BYVAL Bytes AS DWORD _                             ' __in UINT Bytes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBool ( _                                   ' VTable offset = 88
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL b AS LONG _                                  ' __in BOOL b
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBool ( _                                   ' VTable offset = 92
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pb AS LONG _                                 ' __out BOOL* pb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBoolArray ( _                              ' VTable offset = 96
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pb AS LONG _                                 ' __in BOOL* pb
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBoolArray ( _                              ' VTable offset = 100
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pb AS LONG _                                 ' __out BOOL* pb
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInt ( _                                    ' VTable offset = 104
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL n AS LONG _                                  ' __in INT n
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInt ( _                                    ' VTable offset = 108
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pn AS LONG _                                 ' __out INT* pn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIntArray ( _                               ' VTable offset = 112
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pn AS LONG _                                 ' __in CONST INT* pn
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIntArray ( _                               ' VTable offset = 116
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pn AS LONG _                                 ' __out INT* pn
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFloat ( _                                  ' VTable offset = 120
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL f AS SINGLE _                                ' __in FLOAT f
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFloat ( _                                  ' VTable offset = 124
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pf AS SINGLE _                               ' __out FLOAT* pf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFloatArray ( _                             ' VTable offset = 128
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pf AS SINGLE _                               ' __in CONST FLOAT* pf
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFloatArray ( _                             ' VTable offset = 132
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pf AS SINGLE _                               ' __out FLOAT* pf
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVector ( _                                 ' VTable offset = 136
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pVector AS D3DXVECTOR4 _                     ' __in CONST D3DXVECTOR4* pVector
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVector ( _                                 ' VTable offset = 140
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pVector AS D3DXVECTOR4 _                     ' __out D3DXVECTOR4* pVector
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVectorArray ( _                            ' VTable offset = 144
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pVector AS D3DXVECTOR4 _                     ' __in CONST D3DXVECTOR4* pVector
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVectorArray ( _                            ' VTable offset = 148
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pVector AS D3DXVECTOR4 _                     ' __out D3DXVECTOR4* pVector
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrix ( _                                 ' VTable offset = 152
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pMatrix AS D3DXMATRIX _                      ' __in CONST D3DXMATRIX* pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMatrix ( _                                 ' VTable offset = 156
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pMatrix AS D3DXMATRIX _                      ' __out D3DXMATRIX* pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixArray ( _                            ' VTable offset = 160
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pMatrix AS D3DXMATRIX _                      ' __in CONST D3DXMATRIX* pMatrix
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMatrixArray ( _                            ' VTable offset = 164
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pMatrix AS D3DXMATRIX _                      ' __out D3DXMATRIX* pMatrix
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixPointerArray ( _                     ' VTable offset = 168
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL pMatrix AS DWORD _                           ' __in CONST D3DXMATRIX** pMatrix
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMatrixPointerArray ( _                     ' VTable offset = 172
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pMatrix AS DWORD _                           ' __out D3DXMATRIX** pMatrix
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixTranspose ( _                        ' VTable offset = 176
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL pMatrix AS D3DXMATRIX _                      ' __in CONST D3DXMATRIX* pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMatrixTranspose ( _                        ' VTable offset = 180
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYVAL pMatrix AS D3DXMATRIX _                      ' __out D3DXMATRIX* pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixTransposeArray ( _                   ' VTable offset = 184
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL pMatrix AS D3DXMATRIX _                      ' __in CONST D3DXMATRIX* pMatrix
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMatrixTransposeArray ( _                   ' VTable offset = 188
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYVAL pMatrix AS D3DXMATRIX _                      ' __out D3DXMATRIX* pMatrix
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixTransposePointerArray ( _            ' VTable offset = 192
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL ppMatrix AS DWORD _                          ' __in D3DXMATRIX** ppMatrix
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMatrixTransposePointerArray ( _            ' VTable offset = 196
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF ppMatrix AS DWORD _                          ' __out D3DXMATRIX** ppMatrix
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetString ( _                                 ' VTable offset = 200
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pString AS ASCIIZ _                          ' __in LPCSTR pString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 204
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pString AS ASCIIZ _                          ' __out LPCSTR* pString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTexture ( _                                ' VTable offset = 208
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL pTexture AS IDirect3DBaseTexture9 _          ' __in LPDIRECT3DBASETEXTURE9 pTexture
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTexture ( _                                ' VTable offset = 212
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF ppTexture AS IDirect3DBaseTexture9 _         ' __out LPDIRECT3DBASETEXTURE9 *ppTexture
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPixelShader ( _                            ' VTable offset = 216
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL pPShader AS IDirect3DPixelShader9 _          ' __in LPDIRECT3DPIXELSHADER9 pPShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelShader ( _                            ' VTable offset = 220
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF ppPShader AS IDirect3DPixelShader9 _         ' __out LPDIRECT3DPIXELSHADER9 *ppPShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVertexShader ( _                           ' VTable offset = 224
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL pVShader AS IDirect3DVertexShader9 _         ' __in LPDIRECT3DVERTEXSHADER9 pVShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVertexShader ( _                           ' VTable offset = 228
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF ppVShader AS IDirect3DVertexShader9 _        ' __out LPDIRECT3DVERTEXSHADER9 *ppVShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetArrayRange ( _                             ' VTable offset = 232
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL uStart AS DWORD _                            ' __in UINT uStart
   , BYVAL uEnd AS DWORD _                              ' __in UINT uEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3DXEffect methods
   ' =====================================================================================
   METHOD GetPool ( _                                   ' VTable offset = 236
     BYREF ppPool AS ID3DXEffectPool _                  ' __out LPD3DXEFFECTPOOL* ppPool
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTechnique ( _                              ' VTable offset = 240
     BYVAL hTechnique AS DWORD _                        ' __in D3DXHANDLE hTechnique
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentTechnique ( _                       ' VTable offset = 244
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD ValidateTechnique ( _                         ' VTable offset = 248
     BYVAL hTechnique AS DWORD _                        ' __in D3DXHANDLE hTechnique
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindNextValidTechnique ( _                    ' VTable offset = 252
     BYVAL hTechnique AS DWORD _                        ' __in D3DXHANDLE hTechnique
   , BYREF DWORD _                                      ' __in D3DXHANDLE *pTechnique
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsParameterUsed ( _                           ' VTable offset = 256
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL hTechnique AS DWORD _                        ' __in D3DXHANDLE hTechnique
   ) AS LONG                                            ' LONG
   ' =====================================================================================
   METHOD Begin ( _                                     ' VTable offset = 260
     BYREF pPasses AS DWORD _                           ' __in UINT *pPasses
   , BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginPass ( _                                 ' VTable offset = 264
     BYVAL Pass AS DWORD _                              ' __in UINT Pass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CommitChanges ( _                             ' VTable offset = 268
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndPass ( _                                   ' VTable offset = 272
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD End ( _                                       ' VTable offset = 276
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 280
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out LPDIRECT3DDEVICE9* ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnLostDevice ( _                              ' VTable offset = 284
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnResetDevice ( _                             ' VTable offset = 288
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStateManager ( _                           ' VTable offset = 292
     BYVAL pManager AS IUnknown _                       ' __in LPD3DXEFFECTSTATEMANAGER pManager
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStateManager ( _                           ' VTable offset = 296
     BYREF ppManager AS IUnknown _                      ' __out LPD3DXEFFECTSTATEMANAGER *ppManager
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginParameterBlock ( _                       ' VTable offset = 300
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndParameterBlock ( _                         ' VTable offset = 304
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD ApplyParameterBlock ( _                       ' VTable offset = 308
     BYVAL hParameterBlock AS DWORD _                   ' __in D3DXHANDLE hParameterBlock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloneEffect ( _                               ' VTable offset = 312
     BYVAL pDevice AS IDirect3DDevice9 _                ' __in  LPDIRECT3DDEVICE9 pDevice
   , BYREF ppEffect AS ID3DXEffect _                    ' __out LPD3DXEFFECT* ppEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'//////////////////////////////////////////////////////////////////////////////
'// ID3DXEffectCompiler ///////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

$IID_ID3DXEffectCompiler = GUID$("{15A709EB-5A8E-40a0-86A9-0C024124339B}")

INTERFACE ID3DXEffectCompiler $IID_ID3DXEffectCompiler

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3DXBaseEffect methods
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 12
     BYREF pDesc AS D3DXEFFECT_DESC _                   ' __out D3DXEFFECT_DESC* pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParameterDesc ( _                          ' VTable offset = 16
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pDesc AS D3DXPARAMETER_DESC _                ' __out D3DXPARAMETER_DESC* pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTechniqueDesc ( _                          ' VTable offset = 20
     BYVAL hTechnique AS DWORD _                        ' __in  D3DXHANDLE hTechnique
   , BYREF pDesc AS D3DXTECHNIQUE_DESC _                ' __out D3DXTECHNIQUE_DESC* pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPassDesc ( _                               ' VTable offset = 24
     BYVAL hTechnique AS DWORD _                        ' __in  D3DXHANDLE hTechnique
   , BYREF pDesc AS D3DXPASS_DESC _                     ' __out D3DXPASS_DESC* pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFunctionDesc ( _                           ' VTable offset = 28
     BYVAL hShader AS DWORD _                           ' __in  D3DXHANDLE hShader
   , BYREF pDesc AS D3DXFUNCTION_DESC _                 ' __out D3DXFUNCTION_DESC* pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParameter ( _                              ' VTable offset = 32
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetParameterByName ( _                        ' VTable offset = 36
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pName AS ASCIIZ _                            ' __in LPCSTR pName
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetParameterBySemantic ( _                    ' VTable offset = 40
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pSemantic AS ASCIIZ _                        ' __in LPCSTR pSemantic
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetParameterElement ( _                       ' VTable offset = 44
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetTechnique ( _                              ' VTable offset = 48
     BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetTechniqueByName ( _                        ' VTable offset = 52
     BYREF pName AS ASCIIZ _                            ' __in LPCSTR pName
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetPass ( _                                   ' VTable offset = 56
     BYVAL hTechnique AS DWORD _                        ' __in D3DXHANDLE hTechnique
   , BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetPassByName ( _                             ' VTable offset = 60
     BYVAL hTechnique AS DWORD _                        ' __in D3DXHANDLE hTechnique
   , BYREF pName AS ASCIIZ _                            ' __in LPCSTR pName
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetFunction ( _                               ' VTable offset = 64
     BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetFunctionByName ( _                         ' VTable offset = 68
     BYREF pName AS ASCIIZ _                            ' __in LPCSTR pName
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetAnnotation ( _                             ' VTable offset = 72
     BYVAL hObject AS DWORD _                           ' __in D3DXHANDLE hObject
   , BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetAnnotationByName ( _                       ' VTable offset = 76
     BYVAL hObject AS DWORD _                           ' __in D3DXHANDLE hObject
   , BYREF pName AS ASCIIZ _                            ' __in LPCSTR pName
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 80
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL pData AS DWORD _                             ' __in LPCVOID pData
   , BYVAL Bytes AS DWORD _                             ' __in UINT Bytes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 84
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL pData AS DWORD _                             ' __in LPVOID pData
   , BYVAL Bytes AS DWORD _                             ' __in UINT Bytes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBool ( _                                   ' VTable offset = 88
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL b AS LONG _                                  ' __in BOOL b
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBool ( _                                   ' VTable offset = 92
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pb AS LONG _                                 ' __out BOOL* pb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBoolArray ( _                              ' VTable offset = 96
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pb AS LONG _                                 ' __in BOOL* pb
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBoolArray ( _                              ' VTable offset = 100
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pb AS LONG _                                 ' __out BOOL* pb
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInt ( _                                    ' VTable offset = 104
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL n AS LONG _                                  ' __in INT n
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInt ( _                                    ' VTable offset = 108
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pn AS LONG _                                 ' __out INT* pn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIntArray ( _                               ' VTable offset = 112
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pn AS LONG _                                 ' __in CONST INT* pn
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIntArray ( _                               ' VTable offset = 116
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pn AS LONG _                                 ' __out INT* pn
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFloat ( _                                  ' VTable offset = 120
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL f AS SINGLE _                                ' __in FLOAT f
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFloat ( _                                  ' VTable offset = 124
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pf AS SINGLE _                               ' __out FLOAT* pf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFloatArray ( _                             ' VTable offset = 128
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pf AS SINGLE _                               ' __in CONST FLOAT* pf
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFloatArray ( _                             ' VTable offset = 132
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pf AS SINGLE _                               ' __out FLOAT* pf
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVector ( _                                 ' VTable offset = 136
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pVector AS D3DXVECTOR4 _                     ' __in CONST D3DXVECTOR4* pVector
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVector ( _                                 ' VTable offset = 140
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pVector AS D3DXVECTOR4 _                     ' __out D3DXVECTOR4* pVector
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVectorArray ( _                            ' VTable offset = 144
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pVector AS D3DXVECTOR4 _                     ' __in CONST D3DXVECTOR4* pVector
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVectorArray ( _                            ' VTable offset = 148
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pVector AS D3DXVECTOR4 _                     ' __out D3DXVECTOR4* pVector
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrix ( _                                 ' VTable offset = 152
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pMatrix AS D3DXMATRIX _                      ' __in CONST D3DXMATRIX* pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMatrix ( _                                 ' VTable offset = 156
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pMatrix AS D3DXMATRIX _                      ' __out D3DXMATRIX* pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixArray ( _                            ' VTable offset = 160
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pMatrix AS D3DXMATRIX _                      ' __in CONST D3DXMATRIX* pMatrix
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMatrixArray ( _                            ' VTable offset = 164
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pMatrix AS D3DXMATRIX _                      ' __out D3DXMATRIX* pMatrix
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixPointerArray ( _                     ' VTable offset = 168
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL pMatrix AS DWORD _                           ' __in CONST D3DXMATRIX** pMatrix
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMatrixPointerArray ( _                     ' VTable offset = 172
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pMatrix AS DWORD _                           ' __out D3DXMATRIX** pMatrix
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixTranspose ( _                        ' VTable offset = 176
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL pMatrix AS D3DXMATRIX _                      ' __in CONST D3DXMATRIX* pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMatrixTranspose ( _                        ' VTable offset = 180
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYVAL pMatrix AS D3DXMATRIX _                      ' __out D3DXMATRIX* pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixTransposeArray ( _                   ' VTable offset = 184
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL pMatrix AS D3DXMATRIX _                      ' __in CONST D3DXMATRIX* pMatrix
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMatrixTransposeArray ( _                   ' VTable offset = 188
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYVAL pMatrix AS D3DXMATRIX _                      ' __out D3DXMATRIX* pMatrix
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixTransposePointerArray ( _            ' VTable offset = 192
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL ppMatrix AS DWORD _                          ' __in D3DXMATRIX** ppMatrix
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMatrixTransposePointerArray ( _            ' VTable offset = 196
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF ppMatrix AS DWORD _                          ' __out D3DXMATRIX** ppMatrix
   , BYVAL Count AS DWORD _                             ' __in  UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetString ( _                                 ' VTable offset = 200
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYREF pString AS ASCIIZ _                          ' __in LPCSTR pString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 204
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pString AS ASCIIZ _                          ' __out LPCSTR* pString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTexture ( _                                ' VTable offset = 208
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL pTexture AS IDirect3DBaseTexture9 _          ' __in LPDIRECT3DBASETEXTURE9 pTexture
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTexture ( _                                ' VTable offset = 212
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF ppTexture AS IDirect3DBaseTexture9 _         ' __out LPDIRECT3DBASETEXTURE9 *ppTexture
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPixelShader ( _                            ' VTable offset = 216
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL pPShader AS IDirect3DPixelShader9 _          ' __in LPDIRECT3DPIXELSHADER9 pPShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelShader ( _                            ' VTable offset = 220
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF ppPShader AS IDirect3DPixelShader9 _         ' __out LPDIRECT3DPIXELSHADER9 *ppPShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVertexShader ( _                           ' VTable offset = 224
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL pVShader AS IDirect3DVertexShader9 _         ' __in LPDIRECT3DVERTEXSHADER9 pVShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVertexShader ( _                           ' VTable offset = 228
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF ppVShader AS IDirect3DVertexShader9 _        ' __out LPDIRECT3DVERTEXSHADER9 *ppVShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetArrayRange ( _                             ' VTable offset = 232
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL uStart AS DWORD _                            ' __in UINT uStart
   , BYVAL uEnd AS DWORD _                              ' __in UINT uEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3DXEffectCompiler methods
   ' =====================================================================================
   METHOD SetLiteral ( _                                ' VTable offset = 236
     BYVAL hParameter AS DWORD _                        ' __in D3DXHANDLE hParameter
   , BYVAL Literal AS LONG _                            ' __in BOOL Literal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLiteral ( _                                ' VTable offset = 240
     BYVAL hParameter AS DWORD _                        ' __in  D3DXHANDLE hParameter
   , BYREF pLiteral AS LONG _                           ' __out BOOL *pLiteral
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompileEffect ( _                             ' VTable offset = 244
     BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   , BYREF ppEffect AS ID3DXBuffer _                    ' __out LPD3DXBUFFER* ppEffect
   , BYREF ppErrorMsgs AS ID3DXBuffer _                 ' __out LPD3DXBUFFER* ppErrorMsgs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompileShader ( _                             ' VTable offset = 248
     BYVAL hFunction AS DWORD _                         ' __in  D3DXHANDLE hFunction
   , BYREF pTarget AS ASCIIZ _                          ' __in  LPCSTR pTarget
   , BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   , BYREF ppShader AS ID3DXBuffer _                    ' __out LPD3DXBUFFER* ppShader
   , BYREF ppErrorMsgs AS ID3DXBuffer _                 ' __out LPD3DXBUFFER* ppErrorMsgs
   , BYREF ppConstantTable AS ID3DXConstantTable _      ' __out LPD3DXCONSTANTTABLE* ppConstantTable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'//////////////////////////////////////////////////////////////////////////////
'// APIs //////////////////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////


'//----------------------------------------------------------------------------
'// D3DXCreateEffectPool:
'// ---------------------
'// Creates an effect pool.  Pools are used for sharing parameters between
'// multiple effects.  For all effects within a pool, shared parameters of the
'// same name all share the same value.
'//
'// Parameters:
'//  ppPool
'//      Returns the created pool.
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXCreateEffectPool IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateEffectPool" (_
   BYREF ppPool AS ID3DXEffectPool _                    ' __out LPD3DXEFFECTPOOL* ppPool
 ) AS LONG                                              ' HRESULT

'//----------------------------------------------------------------------------
'// D3DXCreateEffect:
'// -----------------
'// Creates an effect from an ascii or binary effect description.
'//
'// Parameters:
'//  pDevice
'//      Pointer of the device on which to create the effect
'//  pSrcFile
'//      Name of the file containing the effect description
'//  hSrcModule
'//      Module handle. if NULL, current module will be used.
'//  pSrcResource
'//      Resource name in module
'//  pSrcData
'//      Pointer to effect description
'//  SrcDataSize
'//      Size of the effect description in bytes
'//  pDefines
'//      Optional NULL-terminated array of preprocessor macro definitions.
'//  pInclude
'//      Optional interface pointer to use for handling #include directives.
'//      If this parameter is NULL, #includes will be honored when compiling
'//      from file, and will error when compiling from resource or memory.
'//  pPool
'//      Pointer to ID3DXEffectPool object to use for shared parameters.
'//      If NULL, no parameters will be shared.
'//  ppEffect
'//      Returns a buffer containing created effect.
'//  ppCompilationErrors
'//      Returns a buffer containing any error messages which occurred during
'//      compile.  Or NULL if you do not care about the error messages.
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXCreateEffectFromFileA IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateEffectFromFileA" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9 pDevice
 , BYREF pSrcFile AS ASCIIZ _                           ' __in  LPCSTR            pSrcFile
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO*  pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE     pInclude
 , BYVAL Flags AS DWORD _                               ' __in  DWORD             Flags
 , BYVAL pPool AS ID3DXEffectPool _                     ' __in  LPD3DXEFFECTPOOL  pPool
 , BYREF ppEffect AS ID3DXEffect _                      ' __out LPD3DXEFFECT*     ppEffect
 , BYREF ppCompilationErrors AS ID3DXBuffer _           ' __out LPD3DXBUFFER*     ppCompilationErrors
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateEffectFromFileW IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateEffectFromFileW" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9 pDevice
 , BYREF pSrcFile AS WSTRINGZ _                         ' __in  LPCWSTR           pSrcFile
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO*  pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE     pInclude
 , BYVAL Flags AS DWORD _                               ' __in  DWORD             Flags
 , BYVAL pPool AS ID3DXEffectPool _                     ' __in  LPD3DXEFFECTPOOL  pPool
 , BYREF ppEffect AS ID3DXEffect _                      ' __out LPD3DXEFFECT*     ppEffect
 , BYREF ppCompilationErrors AS ID3DXBuffer _           ' __out LPD3DXBUFFER*     ppCompilationErrors
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXCreateEffectFromFile = D3DXCreateEffectFromFileW
#ELSE
   MACRO D3DXCreateEffectFromFile = D3DXCreateEffectFromFileA
#ENDIF


DECLARE FUNCTION D3DXCreateEffectFromResourceA IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateEffectFromResourceA" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9 pDevice
 , BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE           hSrcModule
 , BYREF pSrcResource AS ASCIIZ _                       ' __in  LPCSTR            pSrcResource
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO*  pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE     pInclude
 , BYVAL Flags AS DWORD _                               ' __in  DWORD             Flags
 , BYVAL pPool AS ID3DXEffectPool _                     ' __in  LPD3DXEFFECTPOOL  pPool
 , BYREF ppEffect AS ID3DXEffect _                      ' __out LPD3DXEFFECT*     ppEffect
 , BYREF ppCompilationErrors AS ID3DXBuffer _           ' __out LPD3DXBUFFER*     ppCompilationErrors
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateEffectFromResourceW IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateEffectFromResourceW" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9 pDevice
 , BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE           hSrcModule
 , BYREF pSrcResource AS WSTRINGZ _                     ' __in  LPCWSTR           pSrcResource
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO*  pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE     pInclude
 , BYVAL Flags AS DWORD _                               ' __in  DWORD             Flags
 , BYVAL pPool AS ID3DXEffectPool _                     ' __in  LPD3DXEFFECTPOOL  pPool
 , BYREF ppEffect AS ID3DXEffect _                      ' __out LPD3DXEFFECT*     ppEffect
 , BYREF ppCompilationErrors AS ID3DXBuffer _           ' __out LPD3DXBUFFER*     ppCompilationErrors
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXCreateEffectFromResource = D3DXCreateEffectFromResourceW
#ELSE
   MACRO D3DXCreateEffectFromResource = D3DXCreateEffectFromResourceA
#ENDIF

DECLARE FUNCTION D3DXCreateEffect IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateEffect" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9 pDevice
 , BYVAL pSrcData AS DWORD _                            ' __in  LPCVOID           pSrcData
 , BYVAL SrcDataLen AS DWORD _                          ' __in  UINT              SrcDataLen
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO*  pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE     pInclude
 , BYVAL Flags AS DWORD _                               ' __in  DWORD             Flags
 , BYVAL pPool AS ID3DXEffectPool _                     ' __in  LPD3DXEFFECTPOOL  pPool
 , BYREF ppEffect AS ID3DXEffect _                      ' __out LPD3DXEFFECT*     ppEffect
 , BYREF ppCompilationErrors AS ID3DXBuffer _           ' __out LPD3DXBUFFER*     ppCompilationErrors
 ) AS LONG                                              ' HRESULT


'//
'// Ex functions that accept pSkipConstants in addition to other parameters
'//

DECLARE FUNCTION D3DXCreateEffectFromFileExA IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateEffectFromFileExA" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9 pDevice
 , BYREF pSrcFile AS ASCIIZ _                           ' __in  LPCSTR            pSrcFile
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO*  pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE     pInclude
 , BYREF pSkipConstants AS ASCIIZ _                     ' __in  LPCSTR            pSkipConstants
 , BYVAL Flags AS DWORD _                               ' __in  DWORD             Flags
 , BYVAL pPool AS ID3DXEffectPool _                     ' __in  LPD3DXEFFECTPOOL  pPool
 , BYREF ppEffect AS ID3DXEffect _                      ' __out LPD3DXEFFECT*     ppEffect
 , BYREF ppCompilationErrors AS ID3DXBuffer _           ' __out LPD3DXBUFFER*     ppCompilationErrors
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateEffectFromFileExW IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateEffectFromFileExW" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9 pDevice
 , BYREF pSrcFile AS WSTRINGZ _                         ' __in  LPCWSTR           pSrcFile
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO*  pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE     pInclude
 , BYREF pSkipConstants AS ASCIIZ _                     ' __in  LPCSTR            pSkipConstants
 , BYVAL Flags AS DWORD _                               ' __in  DWORD             Flags
 , BYVAL pPool AS ID3DXEffectPool _                     ' __in  LPD3DXEFFECTPOOL  pPool
 , BYREF ppEffect AS ID3DXEffect _                      ' __out LPD3DXEFFECT*     ppEffect
 , BYREF ppCompilationErrors AS ID3DXBuffer _           ' __out LPD3DXBUFFER*     ppCompilationErrors
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXCreateEffectFromFileEx = D3DXCreateEffectFromFileExW
#ELSE
   MACRO D3DXCreateEffectFromFileEx = D3DXCreateEffectFromFileExA
#ENDIF

DECLARE FUNCTION D3DXCreateEffectFromResourceExA IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateEffectFromResourceExA" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9 pDevice
 , BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE           hSrcModule
 , BYREF pSrcResource AS ASCIIZ _                       ' __in  LPCSTR            pSrcResource
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO*  pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE     pInclude
 , BYREF pSkipConstants AS ASCIIZ _                     ' __in  LPCSTR            pSkipConstants
 , BYVAL Flags AS DWORD _                               ' __in  DWORD             Flags
 , BYVAL pPool AS ID3DXEffectPool _                     ' __in  LPD3DXEFFECTPOOL  pPool
 , BYREF ppEffect AS ID3DXEffect _                      ' __out LPD3DXEFFECT*     ppEffect
 , BYREF ppCompilationErrors AS ID3DXBuffer _           ' __out LPD3DXBUFFER*     ppCompilationErrors
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateEffectFromResourceExW IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateEffectFromResourceExW" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9 pDevice
 , BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE           hSrcModule
 , BYREF pSrcResource AS WSTRINGZ _                     ' __in  LPCWSTR           pSrcResource
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO*  pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE     pInclude
 , BYREF pSkipConstants AS ASCIIZ _                     ' __in  LPCSTR            pSkipConstants
 , BYVAL Flags AS DWORD _                               ' __in  DWORD             Flags
 , BYVAL pPool AS ID3DXEffectPool _                     ' __in  LPD3DXEFFECTPOOL  pPool
 , BYREF ppEffect AS ID3DXEffect _                      ' __out LPD3DXEFFECT*     ppEffect
 , BYREF ppCompilationErrors AS ID3DXBuffer _           ' __out LPD3DXBUFFER*     ppCompilationErrors
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXCreateEffectFromResourceEx = D3DXCreateEffectFromResourceExW
#ELSE
   MACRO D3DXCreateEffectFromResourceEx = D3DXCreateEffectFromResourceExA
#ENDIF

DECLARE FUNCTION D3DXCreateEffectEx IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateEffectEx" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9 pDevice
 , BYVAL pSrcData AS DWORD _                            ' __in  LPCVOID           pSrcData
 , BYVAL SrcDataLen AS DWORD _                          ' __in  UINT              SrcDataLen
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO*  pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE     pInclude
 , BYREF pSkipConstants AS ASCIIZ _                     ' __in  LPCSTR            pSkipConstants
 , BYVAL Flags AS DWORD _                               ' __in  DWORD             Flags
 , BYVAL pPool AS ID3DXEffectPool _                     ' __in  LPD3DXEFFECTPOOL  pPool
 , BYREF ppEffect AS ID3DXEffect _                      ' __out LPD3DXEFFECT*     ppEffect
 , BYREF ppCompilationErrors AS ID3DXBuffer _           ' __out LPD3DXBUFFER*     ppCompilationErrors
 ) AS LONG                                              ' HRESULT

'//----------------------------------------------------------------------------
'// D3DXCreateEffectCompiler:
'// -------------------------
'// Creates an effect from an ascii or binary effect description.
'//
'// Parameters:
'//  pSrcFile
'//      Name of the file containing the effect description
'//  hSrcModule
'//      Module handle. if NULL, current module will be used.
'//  pSrcResource
'//      Resource name in module
'//  pSrcData
'//      Pointer to effect description
'//  SrcDataSize
'//      Size of the effect description in bytes
'//  pDefines
'//      Optional NULL-terminated array of preprocessor macro definitions.
'//  pInclude
'//      Optional interface pointer to use for handling #include directives.
'//      If this parameter is NULL, #includes will be honored when compiling
'//      from file, and will error when compiling from resource or memory.
'//  pPool
'//      Pointer to ID3DXEffectPool object to use for shared parameters.
'//      If NULL, no parameters will be shared.
'//  ppCompiler
'//      Returns a buffer containing created effect compiler.
'//  ppParseErrors
'//      Returns a buffer containing any error messages which occurred during
'//      parse.  Or NULL if you do not care about the error messages.
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXCreateEffectCompilerFromFileA IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateEffectCompilerFromFileA" (_
   BYREF pSrcFile AS ASCIIZ _                           ' __in  LPCSTR                pSrcFile
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO*      pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE         pInclude
 , BYVAL Flags AS DWORD _                               ' __in  DWORD                 Flags
 , BYREF ppCompiler AS ID3DXEffectCompiler _            ' __out LPD3DXEFFECTCOMPILER* ppCompiler
 , BYREF ppParseErrors AS ID3DXBuffer _                 ' __out LPD3DXBUFFER*         ppParseErrors
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateEffectCompilerFromFileW IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateEffectCompilerFromFileW" (_
   BYREF pSrcFile AS WSTRINGZ _                         ' __in  LPCWSTR               pSrcFile
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO*      pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE         pInclude
 , BYVAL Flags AS DWORD _                               ' __in  DWORD                 Flags
 , BYREF ppCompiler AS ID3DXEffectCompiler _            ' __out LPD3DXEFFECTCOMPILER* ppCompiler
 , BYREF ppParseErrors AS ID3DXBuffer _                 ' __out LPD3DXBUFFER*         ppParseErrors
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXCreateEffectCompilerFromFile = D3DXCreateEffectCompilerFromFileW
#ELSE
   MACRO D3DXCreateEffectCompilerFromFile = D3DXCreateEffectCompilerFromFileA
#ENDIF

DECLARE FUNCTION D3DXCreateEffectCompilerFromResourceA IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateEffectCompilerFromResourceA" (_
   BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE               hSrcModule
 , BYREF pSrcResource AS ASCIIZ _                       ' __in  LPCSTR                pSrcResource
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO*      pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE         pInclude
 , BYVAL Flags AS DWORD _                               ' __in  DWORD                 Flags
 , BYREF ppCompiler AS ID3DXEffectCompiler _            ' __out LPD3DXEFFECTCOMPILER* ppCompiler
 , BYREF ppParseErrors AS ID3DXBuffer _                 ' __out LPD3DXBUFFER*         ppParseErrors
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateEffectCompilerFromResourceW IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateEffectCompilerFromResourceW" (_
   BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE               hSrcModule
 , BYREF pSrcResource AS WSTRINGZ _                     ' __in  LPCWSTR               pSrcResource
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO*      pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE         pInclude
 , BYVAL Flags AS DWORD _                               ' __in  DWORD                 Flags
 , BYREF ppCompiler AS ID3DXEffectCompiler _            ' __out LPD3DXEFFECTCOMPILER* ppCompiler
 , BYREF ppParseErrors AS ID3DXBuffer _                 ' __out LPD3DXBUFFER*         ppParseErrors
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXCreateEffectCompilerFromResource = D3DXCreateEffectCompilerFromResourceW
#ELSE
   MACRO D3DXCreateEffectCompilerFromResource = D3DXCreateEffectCompilerFromResourceA
#ENDIF

DECLARE FUNCTION D3DXCreateEffectCompiler IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateEffectCompiler" (_
   BYREF pSrcData AS ASCIIZ _                           ' __in  LPCSTR                pSrcData
 , BYVAL SrcDataLen AS DWORD _                          ' __in  UINT                  SrcDataLen
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO*      pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE         pInclude
 , BYVAL Flags AS DWORD _                               ' __in  DWORD                 Flags
 , BYREF ppCompiler AS ID3DXEffectCompiler _            ' __out LPD3DXEFFECTCOMPILER* ppCompiler
 , BYREF ppParseErrors AS ID3DXBuffer _                 ' __out LPD3DXBUFFER*         ppParseErrors
 ) AS LONG                                              ' HRESULT

'//----------------------------------------------------------------------------
'// D3DXDisassembleEffect:
'// -----------------------
'//
'// Parameters:
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXDisassembleEffect IMPORT $D3DX_DLLNAME ALIAS "D3DXDisassembleEffect" (_
   BYVAL pEffect AS ID3DXEffect _                       ' __in  LPD3DXEFFECT pEffect
 , BYVAL EnableColorCode AS LONG _                      ' __in  BOOL EnableColorCode
 , BYREF ppDisassembly AS ID3DXBuffer _                 ' __out LPD3DXBUFFER *ppDisassembly
 ) AS LONG                                              ' HRESULT
