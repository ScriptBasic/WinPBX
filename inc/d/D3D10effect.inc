' ########################################################################################
' Microsoft Windows
' File: D3D10Effect.inc
' Contents: D3D10 Stateblock/Effect Types & APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3D10EFFECT_INC = 1

#INCLUDE ONCE "D3D10Shader.inc"
#INCLUDE ONCE "d3d10.inc"

' //////////////////////////////////////////////////////////////////////////////
' // File contents:
' //
' // 1) Stateblock enums, structs, interfaces, flat APIs
' // 2) Effect enums, structs, interfaces, flat APIs
' //////////////////////////////////////////////////////////////////////////////

' //----------------------------------------------------------------------------
' // D3D10_DEVICE_STATE_TYPES:
' //
' // Used in ID3D10StateBlockMask function calls
' //
' //----------------------------------------------------------------------------

' D3D10_DEVICE_STATE_TYPES

%D3D10_DST_SO_BUFFERS = 1               ' // Single-value state (atomical gets/sets)
%D3D10_DST_OM_RENDER_TARGETS = 2        ' // Single-value state (atomical gets/sets)
%D3D10_DST_OM_DEPTH_STENCIL_STATE = 3   ' // Single-value state
%D3D10_DST_OM_BLEND_STATE = 4           ' // Single-value state

%D3D10_DST_VS = 5                       ' // Single-value state
%D3D10_DST_VS_SAMPLERS = 6              ' // Count: %D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT
%D3D10_DST_VS_SHADER_RESOURCES = 7      ' // Count: %D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT
%D3D10_DST_VS_CONSTANT_BUFFERS = 8      ' // Count:

%D3D10_DST_GS = 9                       ' // Single-value state
%D3D10_DST_GS_SAMPLERS = 10             ' // Count: %D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT
%D3D10_DST_GS_SHADER_RESOURCES = 11     ' // Count: %D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT
%D3D10_DST_GS_CONSTANT_BUFFERS = 12     ' // Count: %D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT

%D3D10_DST_PS = 13                      ' // Single-value state
%D3D10_DST_PS_SAMPLERS = 14             ' // Count: %D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT
%D3D10_DST_PS_SHADER_RESOURCES = 15     ' // Count: %D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT
%D3D10_DST_PS_CONSTANT_BUFFERS = 16     ' // Count: %D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT

%D3D10_DST_IA_VERTEX_BUFFERS = 17       ' // Count: %D3D10_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT
%D3D10_DST_IA_INDEX_BUFFER = 18         ' // Single-value state
%D3D10_DST_IA_INPUT_LAYOUT = 19         ' // Single-value state
%D3D10_DST_IA_PRIMITIVE_TOPOLOGY = 20   ' // Single-value state

%D3D10_DST_RS_VIEWPORTS = 21            ' // Single-value state (atomical gets/sets)
%D3D10_DST_RS_SCISSOR_RECTS = 22        ' // Single-value state (atomical gets/sets)
%D3D10_DST_RS_RASTERIZER_STATE = 23     ' // Single-value state

%D3D10_DST_PREDICATION = 24             ' // Single-value state

' //----------------------------------------------------------------------------
' // D3D10_DEVICE_STATE_TYPES:
' //
' // Used in ID3D10StateBlockMask function calls
' //
' //----------------------------------------------------------------------------

#IF NOT %DEF(%D3D10_BYTES_FROM_BITS_DEFINED)
%D3D10_BYTES_FROM_BITS_DEFINED = 1
'#define D3D10_BYTES_FROM_BITS(x) (((x) + 7) / 8)
MACRO D3D10_BYTES_FROM_BITS(x) = (x + 7) \ 8
#ENDIF ' // D3D10_BYTES_FROM_BITS

'TYPE D3D10_STATE_BLOCK_MASK
'    BYTE VS;
'    BYTE VSSamplers[D3D10_BYTES_FROM_BITS(D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT)];
'    BYTE VSShaderResources[D3D10_BYTES_FROM_BITS(D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT)];
'    BYTE VSConstantBuffers[D3D10_BYTES_FROM_BITS(D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT)];

'    BYTE GS;
'    BYTE GSSamplers[D3D10_BYTES_FROM_BITS(D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT)];
'    BYTE GSShaderResources[D3D10_BYTES_FROM_BITS(D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT)];
'    BYTE GSConstantBuffers[D3D10_BYTES_FROM_BITS(D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT)];

'    BYTE PS;
'    BYTE PSSamplers[D3D10_BYTES_FROM_BITS(D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT)];
'    BYTE PSShaderResources[D3D10_BYTES_FROM_BITS(D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT)];
'    BYTE PSConstantBuffers[D3D10_BYTES_FROM_BITS(D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT)];

'    BYTE IAVertexBuffers[D3D10_BYTES_FROM_BITS(D3D10_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT)];
'    BYTE IAIndexBuffer;
'    BYTE IAInputLayout;
'    BYTE IAPrimitiveTopology;

'    BYTE OMRenderTargets;
'    BYTE OMDepthStencilState;
'    BYTE OMBlendState;

'    BYTE RSViewports;
'    BYTE RSScissorRects;
'    BYTE RSRasterizerState;

'    BYTE SOBuffers;

'    BYTE Predication;
'END TYPE

' // Size = 76 bytes
TYPE D3D10_STATE_BLOCK_MASK BYTE
   VS                    AS BYTE
   VSSamplers(1)         AS BYTE
   VSShaderResources(15) AS BYTE
   VSConstantBuffers(1)  AS BYTE

   GS                    AS BYTE
   GSSamplers(1)         AS BYTE
   GSShaderResources(15) AS BYTE
   GSConstantBuffers(1)  AS BYTE

   PS                    AS BYTE
   PSSamplers(1)         AS BYTE
   PSShaderResources(15) AS BYTE
   PSConstantBuffers(1)  AS BYTE

   IAVertexBuffers(1)    AS BYTE
   IAIndexBuffer         AS BYTE
   IAInputLayout         AS BYTE
   IAPrimitiveTopology   AS BYTE

   OMRenderTargets       AS BYTE
   OMDepthStencilState   AS BYTE
   OMBlendState          AS BYTE

   RSViewports           AS BYTE
   RSScissorRects        AS BYTE
   RSRasterizerState     AS BYTE

   SOBuffers             AS BYTE

   Predication           AS BYTE
END TYPE

' ########################################################################################
' ID3D10StateBlock interface
' IID = 0803425A-57F5-4DD6-9465-A87570834A08
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ID3D10StateBlock_INTERFACE_DEFINED)
    %ID3D10StateBlock_INTERFACE_DEFINED = 1

$IID_ID3D10StateBlock = GUID$("{0803425A-57F5-4DD6-9465-A87570834A08}")

INTERFACE ID3D10StateBlock $IID_ID3D10StateBlock

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Capture ( _                                   ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Apply ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseAllDeviceObjects ( _                   ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 24
     BYREF ppDevice AS ID3D10Device _                   ' __out ID3D10Device **ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10StateBlock_INTERFACE_DEFINED__ */

' //----------------------------------------------------------------------------
' // D3D10_STATE_BLOCK_MASK and manipulation functions
' // -------------------------------------------------
' //
' // These functions exist to facilitate working with the D3D10_STATE_BLOCK_MASK
' // structure.
' //
' // D3D10_STATE_BLOCK_MASK *pResult or *pMask
' //   The state block mask to operate on
' //
' // D3D10_STATE_BLOCK_MASK *pA, *pB
' //   The source state block masks for the binary union/intersect/difference
' //   operations.
' //
' // D3D10_DEVICE_STATE_TYPES StateType
' //   The specific state type to enable/disable/query
' //
' // UINT RangeStart, RangeLength, Entry
' //   The specific bit or range of bits for a given state type to operate on.
' //   Consult the comments for D3D10_DEVICE_STATE_TYPES and
' //   D3D10_STATE_BLOCK_MASK for information on the valid bit ranges for
' //   each state.
' //
' //----------------------------------------------------------------------------

DECLARE FUNCTION D3D10StateBlockMaskUnion IMPORT "D3D10.DLL" ALIAS "D3D10StateBlockMaskUnion" ( _
   BYREF pA AS D3D10_STATE_BLOCK_MASK _                 ' __in  D3D10_STATE_BLOCK_MASK *pA
 , BYREF pB AS D3D10_STATE_BLOCK_MASK _                 ' __in  D3D10_STATE_BLOCK_MASK *pB
 , BYREF pResult AS D3D10_STATE_BLOCK_MASK _            ' __out D3D10_STATE_BLOCK_MASK *pResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3D10StateBlockMaskIntersect IMPORT "D3D10.DLL" ALIAS "D3D10StateBlockMaskIntersect" ( _
   BYREF pA AS D3D10_STATE_BLOCK_MASK _                 ' __in  D3D10_STATE_BLOCK_MASK *pA
 , BYREF pB AS D3D10_STATE_BLOCK_MASK _                 ' __in  D3D10_STATE_BLOCK_MASK *pB
 , BYREF pResult AS D3D10_STATE_BLOCK_MASK _            ' __out D3D10_STATE_BLOCK_MASK *pResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3D10StateBlockMaskDifference IMPORT "D3D10.DLL" ALIAS "D3D10StateBlockMaskDifference" ( _
   BYREF pA AS D3D10_STATE_BLOCK_MASK _                 ' __in  D3D10_STATE_BLOCK_MASK *pA
 , BYREF pB AS D3D10_STATE_BLOCK_MASK _                 ' __in  D3D10_STATE_BLOCK_MASK *pB
 , BYREF pResult AS D3D10_STATE_BLOCK_MASK _            ' __out D3D10_STATE_BLOCK_MASK *pResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3D10StateBlockMaskEnableCapture IMPORT "D3D10.DLL" ALIAS "D3D10StateBlockMaskEnableCapture" ( _
   BYREF pMask AS D3D10_STATE_BLOCK_MASK _              ' __in_out D3D10_STATE_BLOCK_MASK *pMask
 , BYVAL StateType AS DWORD _                           ' __in D3D10_DEVICE_STATE_TYPES StateType
 , BYVAL RangeLength AS DWORD _                         ' __in UINT RangeLength
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3D10StateBlockMaskDisableCapture IMPORT "D3D10.DLL" ALIAS "D3D10StateBlockMaskDisableCapture" ( _
   BYREF pMask AS D3D10_STATE_BLOCK_MASK _              ' __in D3D10_STATE_BLOCK_MASK *pMask
 , BYVAL StateType AS DWORD _                           ' __in D3D10_DEVICE_STATE_TYPES StateType
 , BYVAL RangeStart AS DWORD _                          ' __in UINT RangeStart
 , BYVAL RangeLength AS DWORD _                         ' __in UINT RangeLength
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3D10StateBlockMaskEnableAll IMPORT "D3D10.DLL" ALIAS "D3D10StateBlockMaskEnableAll" ( _
   BYREF D3D10_STATE_BLOCK_MASK _                       ' __out D3D10_STATE_BLOCK_MASK *pMask
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3D10StateBlockMaskDisableAll IMPORT "D3D10.DLL" ALIAS "D3D10StateBlockMaskDisableAll" ( _
   BYREF pMask AS D3D10_STATE_BLOCK_MASK _              ' __out D3D10_STATE_BLOCK_MASK *pMask
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3D10StateBlockMaskGetSetting IMPORT "D3D10.DLL" ALIAS "D3D10StateBlockMaskGetSetting" ( _
   BYREF pMask AS D3D10_STATE_BLOCK_MASK _              ' __inD3D10_STATE_BLOCK_MASK *pMask
 , BYVAL StateType AS DWORD _                           ' __inD3D10_DEVICE_STATE_TYPES StateType
 , BYVAL Entry AS DWORD _                               ' __in UINT Entry
 ) AS LONG                                              ' BOOL

' //----------------------------------------------------------------------------
' // D3D10CreateStateBlock
' // ---------------------
' //
' // Creates a state block object based on the mask settings specified
' //   in a D3D10_STATE_BLOCK_MASK structure.
' //
' // ID3D10Device *pDevice
' //      The device interface to associate with this state block
' //
' // D3D10_STATE_BLOCK_MASK *pStateBlockMask
' //      A bit mask whose settings are used to generate a state block
' //      object.
' //
' // ID3D10StateBlock **ppStateBlock
' //      The resulting state block object.  This object will save/restore
' //      only those pieces of state that were set in the state block
' //      bit mask
' //----------------------------------------------------------------------------

DECLARE FUNCTION D3D10CreateStateBlock IMPORT "D3D10.DLL" ALIAS "D3D10CreateStateBlock" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device *pDevice
 , BYREF pStateBlockMask AS D3D10_STATE_BLOCK_MASK _    ' __in  D3D10_STATE_BLOCK_MASK *pStateBlockMask
 , BYREF ppStateBlock AS ID3D10StateBlock _             ' __out ID3D10StateBlock **ppStateBlock
 ) AS LONG                                              ' HRESULT

' //----------------------------------------------------------------------------
' // D3D10_COMPILE & D3D10_EFFECT flags:
' // -------------------------------------
' //
' // These flags are passed in when creating an effect, and affect
' // either compilation behavior or runtime effect behavior
' //
' // D3D10_EFFECT_COMPILE_CHILD_EFFECT
' //   Compile this .fx file to a child effect. Child effects have no initializers
' //   for any shared values as these are initialied in the master effect (pool).
' //
' // D3D10_EFFECT_COMPILE_ALLOW_SLOW_OPS
' //   By default, performance mode is enabled.  Performance mode disallows
' //   mutable state objects by preventing non-literal expressions from appearing in
' //   state object definitions.  Specifying this flag will disable the mode and allow
' //   for mutable state objects.
' //
' // D3D10_EFFECT_SINGLE_THREADED
' //   Do not attempt to synchronize with other threads loading effects into the
' //   same pool.
' //
' //----------------------------------------------------------------------------

%D3D10_EFFECT_COMPILE_CHILD_EFFECT   = &H1   ' 1 << 0
%D3D10_EFFECT_COMPILE_ALLOW_SLOW_OPS = &H2   ' 1 << 1
%D3D10_EFFECT_SINGLE_THREADED        = &H8   ' 1 << 3


' //----------------------------------------------------------------------------
' // D3D10_EFFECT_VARIABLE flags:
' // ----------------------------
' //
' // These flags describe an effect variable (global or annotation),
' // and are returned in D3D10_EFFECT_VARIABLE_DESC::Flags.
' //
' // D3D10_EFFECT_VARIABLE_POOLED
' //   Indicates that the this variable or constant buffer resides
' //   in an effect pool. If this flag is not set, then the variable resides
' //   in a standalone effect (if ID3D10Effect::GetPool returns NULL)
' //   or a child effect (if ID3D10Effect::GetPool returns non-NULL)
' //
' // D3D10_EFFECT_VARIABLE_ANNOTATION
' //   Indicates that this is an annotation on a technique, pass, or global
' //   variable. Otherwise, this is a global variable. Annotations cannot
' //   be shared.
' //
' // D3D10_EFFECT_VARIABLE_EXPLICIT_BIND_POINT
' //   Indicates that the variable has been explicitly bound using the
' //   register keyword.
' //----------------------------------------------------------------------------

%D3D10_EFFECT_VARIABLE_POOLED              = &H1   ' 1 << 0
%D3D10_EFFECT_VARIABLE_ANNOTATION          = &H2   ' 1 << 1
%D3D10_EFFECT_VARIABLE_EXPLICIT_BIND_POINT = &H4   ' 1 << 2

' //////////////////////////////////////////////////////////////////////////////
' // ID3D10EffectType //////////////////////////////////////////////////////////
' //////////////////////////////////////////////////////////////////////////////

' //----------------------------------------------------------------------------
' // D3D10_EFFECT_TYPE_DESC:
' //
' // Retrieved by ID3D10EffectType::GetDesc()
' //----------------------------------------------------------------------------

' // Size = 4 bytes
TYPE D3D10_EFFECT_TYPE_DESC DWORD
   TypeName     AS ASCIIZ PTR  ' LPCSTR // Name of the type
                               ' // (e.g. "float4" or "MyStruct")
   Class        AS DWORD        ' D3D10_SHADER_VARIABLE_CLASS // (e.g. scalar, vector, object, etc.)
   Type         AS DWORD        ' D3D10_SHADER_VARIABLE_TYPE  // (e.g. float, texture, vertexshader, etc.)
   Elements     AS DWORD        ' UINT // Number of elements in this type
                                '      // (0 if not an array)
   Members      AS DWORD        ' UINT // Number of members
                                '      // (0 if not a structure)
   Rows         AS DWORD        ' UINT // Number of rows in this type
                                '      // (0 if not a numeric primitive)
   Columns      AS DWORD        ' UINT // Number of columns in this type
                                '      // (0 if not a numeric primitive)
   PackedSize   AS DWORD        ' UINT // Number of bytes required to represent
                                '      // this data type, when tightly packed
   UnpackedSize AS DWORD        ' UINT // Number of bytes occupied by this data
                                '      // type, when laid out in a constant buffer
   Stride       AS DWORD        ' UINT // Number of bytes to seek between elements,
                                '      // when laid out in a constant buffer
END TYPE

$IID_ID3D10EffectType = GUID$("{4E9E1DDC-CD9D-4772-A837-00180B9B88FD}")

' This interface is the definition of a C++ class
'DECLARE_INTERFACE(ID3D10EffectType)
'{
'    STDMETHOD_(BOOL, IsValid)(THIS) PURE;
'    STDMETHOD(GetDesc)(THIS_ D3D10_EFFECT_TYPE_DESC *pDesc) PURE;
'    STDMETHOD_(ID3D10EffectType*, GetMemberTypeByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectType*, GetMemberTypeByName)(THIS_ LPCSTR Name) PURE;
'    STDMETHOD_(ID3D10EffectType*, GetMemberTypeBySemantic)(THIS_ LPCSTR Semantic) PURE;
'    STDMETHOD_(LPCSTR, GetMemberName)(THIS_ UINT Index) PURE;
'    STDMETHOD_(LPCSTR, GetMemberSemantic)(THIS_ UINT Index) PURE;
'};

'FUNCTION ID3D10EffectType_IsValid (BYVAL pthis AS DWORD PTR) AS LONG
'   LOCAL BRESULT AS LONG
'   CALL DWORD @@pthis[0] USING ID3D10EffectType_IsValid(pthis) TO BRESULT
'   FUNCTION = BRESULT
'END FUNCTION

'FUNCTION ID3D10EffectType_GetDesc (BYVAL pthis AS DWORD PTR, BYREF pDesc AS D3D10_EFFECT_TYPE_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[1] USING ID3D10EffectType_GetDesc(pthis, pDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectType_GetMemberTypeByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[2] USING ID3D10EffectType_GetMemberTypeByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectType_GetMemberTypeByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[3] USING ID3D10EffectType_GetMemberTypeByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectType_GetMemberTypeBySemantic (BYVAL pthis AS DWORD PTR, BYREF szSemantic AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[4] USING ID3D10EffectType_GetMemberTypeByName(pthis, szSemantic) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'DECLARE FUNCTION Proto_ID3D10EffectType_GetMemberName (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'FUNCTION ID3D10EffectType_GetMemberName (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS STRING
'   LOCAL pszName AS ASCIIZ PTR
'   CALL DWORD @@pthis[5] USING Proto_ID3D10EffectType_GetMemberName(pthis, Index) TO pszName
'   IF pszName THEN FUNCTION = @pszName
'END FUNCTION

'DECLARE FUNCTION Proto_ID3D10EffectType_GetMemberSemantic (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'FUNCTION ID3D10EffectType_GetMemberSemantic (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS STRING
'   LOCAL pszSemantic AS ASCIIZ PTR
'   CALL DWORD @@pthis[6] USING Proto_ID3D10EffectType_GetMemberSemantic(pthis, Index) TO pszSemantic
'   IF pszSemantic THEN FUNCTION = @pszSemantic
'END FUNCTION


' //////////////////////////////////////////////////////////////////////////////
' // ID3D10EffectVariable //////////////////////////////////////////////////////
' //////////////////////////////////////////////////////////////////////////////

' //----------------------------------------------------------------------------
' // D3D10_EFFECT_VARIABLE_DESC:
' //
' // Retrieved by ID3D10EffectVariable::GetDesc()
' //----------------------------------------------------------------------------

' // Size = 24 bytes
TYPE D3D10_EFFECT_VARIABLE_DESC DWORD
   Name              AS ASCIIZ PTR   ' LPCSTR // Name of this variable, annotation,
                                     '        // or structure member
   Semantic          AS ASCIIZ PTR   ' LPCSTR // Semantic string of this variable
                                     '        // or structure member (NULL for
                                     '        // annotations or if not present)
   Flags             AS DWORD        ' UINT   // D3D10_EFFECT_VARIABLE_* flags
   Annotations       AS DWORD        ' UINT   // Number of annotations on this variable
                                     '        // (always 0 for annotations)
   BufferOffset      AS DWORD        ' UINT   // Offset into containing cbuffer or tbuffer
                                     '        // (always 0 for annotations or variables
                                     '        // not in constant buffers)

   ExplicitBindPoint AS DWORD        ' UINT   // Used if the variable has been explicitly bound
                                     '        // using the register keyword. Check Flags for
                                     '        // D3D10_EFFECT_VARIABLE_EXPLICIT_BIND_POINT;
END TYPE

$IID_ID3D10EffectVariable = GUID$("{AE897105-00E6-45BF-BB8E-281DD6DB8E1B}")

' This interface is the definition of a C++ class
'DECLARE_INTERFACE(ID3D10EffectVariable)
'{
'    STDMETHOD_(BOOL, IsValid)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectType*, GetType)(THIS) PURE;
'    STDMETHOD(GetDesc)(THIS_ D3D10_EFFECT_VARIABLE_DESC *pDesc) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByName)(THIS_ LPCSTR Name) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByName)(THIS_ LPCSTR Name) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberBySemantic)(THIS_ LPCSTR Semantic) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetElement)(THIS_ UINT Index) PURE;

'    STDMETHOD_(ID3D10EffectConstantBuffer*, GetParentConstantBuffer)(THIS) PURE;

'    STDMETHOD_(ID3D10EffectScalarVariable*, AsScalar)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectVectorVariable*, AsVector)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectMatrixVariable*, AsMatrix)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectStringVariable*, AsString)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderResourceVariable*, AsShaderResource)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRenderTargetViewVariable*, AsRenderTargetView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilViewVariable*, AsDepthStencilView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectConstantBuffer*, AsConstantBuffer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderVariable*, AsShader)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectBlendVariable*, AsBlend)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilVariable*, AsDepthStencil)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRasterizerVariable*, AsRasterizer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectSamplerVariable*, AsSampler)(THIS) PURE;

'    STDMETHOD(SetRawValue)(THIS_ void *pData, UINT Offset, UINT Count) PURE;
'    STDMETHOD(GetRawValue)(THIS_ void *pData, UINT Offset, UINT Count) PURE;
'};

'FUNCTION ID3D10EffectVariable_IsValid (BYVAL pthis AS DWORD PTR) AS LONG
'   LOCAL BRESULT AS LONG
'   CALL DWORD @@pthis[0] USING ID3D10EffectVariable_IsValid(pthis) TO BRESULT
'   FUNCTION = BRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVariable_GetType (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[1] USING ID3D10EffectVariable_GetType(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVariable_GetDesc (BYVAL pthis AS DWORD PTR, BYREF pDesc AS D3D10_EFFECT_VARIABLE_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[2] USING ID3D10EffectVariable_GetDesc(pthis, pDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVariable_GetAnnotationByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[3] USING ID3D10EffectVariable_GetAnnotationByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVariable_GetAnnotationByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[4] USING ID3D10EffectVariable_GetAnnotationByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVariable_GetMemberByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[5] USING ID3D10EffectVariable_GetMemberByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVariable_GetMemberByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[6] USING ID3D10EffectVariable_GetMemberByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVariable_GetMemberBySemantic (BYVAL pthis AS DWORD PTR, BYREF szSemantic AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[7] USING ID3D10EffectVariable_GetMemberBySemantic(pthis, szSemantic) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVariable_GetElement (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[8] USING ID3D10EffectVariable_GetElement(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVariable_GetParentConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[9] USING ID3D10EffectVariable_GetParentConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVariable_AsScalar (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[10] USING ID3D10EffectVariable_AsScalar(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVariable_AsVector (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[11] USING ID3D10EffectVariable_AsVector(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVariable_AsMatrix (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[12] USING ID3D10EffectVariable_AsMatrix(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVariable_AsString (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[13] USING ID3D10EffectVariable_AsString(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVariable_AsShaderResource (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[14] USING ID3D10EffectVariable_AsShaderResource(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVariable_AsRenderTargetView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[15] USING ID3D10EffectVariable_AsRenderTargetView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVariable_AsDepthStencilView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[16] USING ID3D10EffectVariable_AsDepthStencilView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVariable_AsConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[17] USING ID3D10EffectVariable_AsConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVariable_AsShader (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[18] USING ID3D10EffectVariable_AsShader(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVariable_AsBlend (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[19] USING ID3D10EffectVariable_AsBlend(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVariable_AsDepthStencil (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[20] USING ID3D10EffectVariable_AsDepthStencil(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVariable_AsRasterizer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[21] USING ID3D10EffectVariable_AsRasterizer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVariable_AsSampler (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[22] USING ID3D10EffectVariable_AsSampler(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVariable_SetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[23] USING ID3D10EffectVariable_SetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVariable_GetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[24] USING ID3D10EffectVariable_GetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

' //////////////////////////////////////////////////////////////////////////////
' // ID3D10EffectScalarVariable ////////////////////////////////////////////////
' //////////////////////////////////////////////////////////////////////////////

$IID_ID3D10EffectScalarVariable = GUID$("{00E48F7B-D2C8-49e8-A86C-022DEE53431F}")

' This interface is the definition of a C++ class
'DECLARE_INTERFACE_(ID3D10EffectScalarVariable, ID3D10EffectVariable)
'{
'    STDMETHOD_(BOOL, IsValid)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectType*, GetType)(THIS) PURE;
'    STDMETHOD(GetDesc)(THIS_ D3D10_EFFECT_VARIABLE_DESC *pDesc) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByName)(THIS_ LPCSTR Name) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByName)(THIS_ LPCSTR Name) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberBySemantic)(THIS_ LPCSTR Semantic) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetElement)(THIS_ UINT Index) PURE;

'    STDMETHOD_(ID3D10EffectConstantBuffer*, GetParentConstantBuffer)(THIS) PURE;

'    STDMETHOD_(ID3D10EffectScalarVariable*, AsScalar)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectVectorVariable*, AsVector)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectMatrixVariable*, AsMatrix)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectStringVariable*, AsString)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderResourceVariable*, AsShaderResource)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRenderTargetViewVariable*, AsRenderTargetView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilViewVariable*, AsDepthStencilView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectConstantBuffer*, AsConstantBuffer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderVariable*, AsShader)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectBlendVariable*, AsBlend)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilVariable*, AsDepthStencil)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRasterizerVariable*, AsRasterizer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectSamplerVariable*, AsSampler)(THIS) PURE;

'    STDMETHOD(SetRawValue)(THIS_ void *pData, UINT ByteOffset, UINT ByteCount) PURE;
'    STDMETHOD(GetRawValue)(THIS_ void *pData, UINT ByteOffset, UINT ByteCount) PURE;

'    STDMETHOD(SetFloat)(THIS_ float Value) PURE;
'    STDMETHOD(GetFloat)(THIS_ float *pValue) PURE;

'    STDMETHOD(SetFloatArray)(THIS_ float *pData, UINT Offset, UINT Count) PURE;
'    STDMETHOD(GetFloatArray)(THIS_ float *pData, UINT Offset, UINT Count) PURE;

'    STDMETHOD(SetInt)(THIS_ int Value) PURE;
'    STDMETHOD(GetInt)(THIS_ int *pValue) PURE;

'    STDMETHOD(SetIntArray)(THIS_ int *pData, UINT Offset, UINT Count) PURE;
'    STDMETHOD(GetIntArray)(THIS_ int *pData, UINT Offset, UINT Count) PURE;

'    STDMETHOD(SetBool)(THIS_ BOOL Value) PURE;
'    STDMETHOD(GetBool)(THIS_ BOOL *pValue) PURE;

'    STDMETHOD(SetBoolArray)(THIS_ BOOL *pData, UINT Offset, UINT Count) PURE;
'    STDMETHOD(GetBoolArray)(THIS_ BOOL *pData, UINT Offset, UINT Count) PURE;
'};

'FUNCTION ID3D10EffectScalarVariable_IsValid (BYVAL pthis AS DWORD PTR) AS LONG
'   LOCAL BRESULT AS LONG
'   CALL DWORD @@pthis[0] USING ID3D10EffectScalarVariable_IsValid(pthis) TO BRESULT
'   FUNCTION = BRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_GetType (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[1] USING ID3D10EffectScalarVariable_GetType(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_GetDesc (BYVAL pthis AS DWORD PTR, BYREF pDesc AS D3D10_EFFECT_VARIABLE_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[2] USING ID3D10EffectScalarVariable_GetDesc(pthis, pDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_GetAnnotationByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[3] USING ID3D10EffectScalarVariable_GetAnnotationByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_GetAnnotationByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[4] USING ID3D10EffectScalarVariable_GetAnnotationByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_GetMemberByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[5] USING ID3D10EffectScalarVariable_GetMemberByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_GetMemberByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[6] USING ID3D10EffectScalarVariable_GetMemberByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_GetMemberBySemantic (BYVAL pthis AS DWORD PTR, BYREF szSemantic AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[7] USING ID3D10EffectScalarVariable_GetMemberBySemantic(pthis, szSemantic) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_GetElement (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[8] USING ID3D10EffectScalarVariable_GetElement(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_GetParentConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[9] USING ID3D10EffectScalarVariable_GetParentConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_AsScalar (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[10] USING ID3D10EffectScalarVariable_AsScalar(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_AsVector (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[11] USING ID3D10EffectScalarVariable_AsVector(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_AsMatrix (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[12] USING ID3D10EffectScalarVariable_AsMatrix(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_AsString (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[13] USING ID3D10EffectScalarVariable_AsString(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_AsShaderResource (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[14] USING ID3D10EffectScalarVariable_AsShaderResource(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_AsRenderTargetView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[15] USING ID3D10EffectScalarVariable_AsRenderTargetView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_AsDepthStencilView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[16] USING ID3D10EffectScalarVariable_AsDepthStencilView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_AsConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[17] USING ID3D10EffectScalarVariable_AsConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_AsShader (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[18] USING ID3D10EffectScalarVariable_AsShader(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_AsBlend (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[19] USING ID3D10EffectScalarVariable_AsBlend(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_AsDepthStencil (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[20] USING ID3D10EffectScalarVariable_AsDepthStencil(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_AsRasterizer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[21] USING ID3D10EffectScalarVariable_AsRasterizer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_AsSampler (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[22] USING ID3D10EffectScalarVariable_AsSampler(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_SetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[23] USING ID3D10EffectScalarVariable_SetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_GetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[24] USING ID3D10EffectScalarVariable_GetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_SetFloat (BYVAL pthis AS DWORD PTR, BYVAL Value AS SINGLE) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[25] USING ID3D10EffectScalarVariable_SetFloat(pthis, Value) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_GetFloat (BYVAL pthis AS DWORD PTR, BYREF pValue AS SINGLE) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[26] USING ID3D10EffectScalarVariable_GetFloat(pthis, pValue) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_SetFloatArray (BYVAL pthis AS DWORD PTR, BYREF pData AS SINGLE, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[27] USING ID3D10EffectScalarVariable_SetFloatArray(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_GetFloatArray (BYVAL pthis AS DWORD PTR, BYREF pData AS SINGLE, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[28] USING ID3D10EffectScalarVariable_GetFloatArray(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_SetInt (BYVAL pthis AS DWORD PTR, BYVAL Value AS LONG) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[29] USING ID3D10EffectScalarVariable_SetInt(pthis, Value) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_GetInt (BYVAL pthis AS DWORD PTR, BYREF pValue AS LONG) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[30] USING ID3D10EffectScalarVariable_GetInt(pthis, pValue) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_SetIntArray (BYVAL pthis AS DWORD PTR, BYREF pData AS LONG, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[31] USING ID3D10EffectScalarVariable_SetIntArray(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_GetIntArray (BYVAL pthis AS DWORD PTR, BYREF pData AS LONG, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[32] USING ID3D10EffectScalarVariable_GetIntArray(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_SetBool (BYVAL pthis AS DWORD PTR, BYVAL Value AS LONG) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[33] USING ID3D10EffectScalarVariable_SetBool(pthis, Value) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_GetBool (BYVAL pthis AS DWORD PTR, BYREF pValue AS LONG) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[34] USING ID3D10EffectScalarVariable_GetBool(pthis, pValue) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_SetBoolArray (BYVAL pthis AS DWORD PTR, BYREF pData AS LONG, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[35] USING ID3D10EffectScalarVariable_SetBoolArray(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectScalarVariable_GetBoolArray (BYVAL pthis AS DWORD PTR, BYREF pData AS LONG, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[36] USING ID3D10EffectScalarVariable_GetBoolArray(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION


' //////////////////////////////////////////////////////////////////////////////
' // ID3D10EffectVectorVariable ////////////////////////////////////////////////
' //////////////////////////////////////////////////////////////////////////////

$IID_ID3D10EffectVectorVariable = GUID$("{62B98C44-1F82-4C67-BCD0-72CF8F217E81}")

' This interface is the definition of a C++ class
'DECLARE_INTERFACE_(ID3D10EffectVectorVariable, ID3D10EffectVariable)
'{
'    STDMETHOD_(BOOL, IsValid)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectType*, GetType)(THIS) PURE;
'    STDMETHOD(GetDesc)(THIS_ D3D10_EFFECT_VARIABLE_DESC *pDesc) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByName)(THIS_ LPCSTR Name) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByName)(THIS_ LPCSTR Name) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberBySemantic)(THIS_ LPCSTR Semantic) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetElement)(THIS_ UINT Index) PURE;

'    STDMETHOD_(ID3D10EffectConstantBuffer*, GetParentConstantBuffer)(THIS) PURE;

'    STDMETHOD_(ID3D10EffectScalarVariable*, AsScalar)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectVectorVariable*, AsVector)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectMatrixVariable*, AsMatrix)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectStringVariable*, AsString)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderResourceVariable*, AsShaderResource)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRenderTargetViewVariable*, AsRenderTargetView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilViewVariable*, AsDepthStencilView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectConstantBuffer*, AsConstantBuffer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderVariable*, AsShader)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectBlendVariable*, AsBlend)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilVariable*, AsDepthStencil)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRasterizerVariable*, AsRasterizer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectSamplerVariable*, AsSampler)(THIS) PURE;

'    STDMETHOD(SetRawValue)(THIS_ void *pData, UINT ByteOffset, UINT ByteCount) PURE;
'    STDMETHOD(GetRawValue)(THIS_ void *pData, UINT ByteOffset, UINT ByteCount) PURE;

'    STDMETHOD(SetBoolVector) (THIS_ BOOL *pData) PURE;
'    STDMETHOD(SetIntVector)  (THIS_ int *pData) PURE;
'    STDMETHOD(SetFloatVector)(THIS_ float *pData) PURE;

'    STDMETHOD(GetBoolVector) (THIS_ BOOL *pData) PURE;
'    STDMETHOD(GetIntVector)  (THIS_ int *pData) PURE;
'    STDMETHOD(GetFloatVector)(THIS_ float *pData) PURE;

'    STDMETHOD(SetBoolVectorArray) (THIS_ BOOL *pData, UINT Offset, UINT Count) PURE;
'    STDMETHOD(SetIntVectorArray)  (THIS_ int *pData, UINT Offset, UINT Count) PURE;
'    STDMETHOD(SetFloatVectorArray)(THIS_ float *pData, UINT Offset, UINT Count) PURE;

'    STDMETHOD(GetBoolVectorArray) (THIS_ BOOL *pData, UINT Offset, UINT Count) PURE;
'    STDMETHOD(GetIntVectorArray)  (THIS_ int *pData, UINT Offset, UINT Count) PURE;
'    STDMETHOD(GetFloatVectorArray)(THIS_ float *pData, UINT Offset, UINT Count) PURE;
'};

'FUNCTION ID3D10EffectVectorVariable_IsValid (BYVAL pthis AS DWORD PTR) AS LONG
'   LOCAL BRESULT AS LONG
'   CALL DWORD @@pthis[0] USING ID3D10EffectVectorVariable_IsValid(pthis) TO BRESULT
'   FUNCTION = BRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_GetType (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[1] USING ID3D10EffectVectorVariable_GetType(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_GetDesc (BYVAL pthis AS DWORD PTR, BYREF pDesc AS D3D10_EFFECT_VARIABLE_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[2] USING ID3D10EffectVectorVariable_GetDesc(pthis, pDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_GetAnnotationByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[3] USING ID3D10EffectVectorVariable_GetAnnotationByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_GetAnnotationByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[4] USING ID3D10EffectVectorVariable_GetAnnotationByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_GetMemberByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[5] USING ID3D10EffectVectorVariable_GetMemberByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_GetMemberByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[6] USING ID3D10EffectVectorVariable_GetMemberByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_GetMemberBySemantic (BYVAL pthis AS DWORD PTR, BYREF szSemantic AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[7] USING ID3D10EffectVectorVariable_GetMemberBySemantic(pthis, szSemantic) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_GetElement (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[8] USING ID3D10EffectVectorVariable_GetElement(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_GetParentConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[9] USING ID3D10EffectVectorVariable_GetParentConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_AsScalar (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[10] USING ID3D10EffectVectorVariable_AsScalar(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_AsVector (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[11] USING ID3D10EffectVectorVariable_AsVector(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_AsMatrix (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[12] USING ID3D10EffectVectorVariable_AsMatrix(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_AsString (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[13] USING ID3D10EffectVectorVariable_AsString(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_AsShaderResource (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[14] USING ID3D10EffectVectorVariable_AsShaderResource(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_AsRenderTargetView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[15] USING ID3D10EffectVectorVariable_AsRenderTargetView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_AsDepthStencilView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[16] USING ID3D10EffectVectorVariable_AsDepthStencilView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_AsConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[17] USING ID3D10EffectVectorVariable_AsConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_AsShader (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[18] USING ID3D10EffectVectorVariable_AsShader(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_AsBlend (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[19] USING ID3D10EffectVectorVariable_AsBlend(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_AsDepthStencil (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[20] USING ID3D10EffectVectorVariable_AsDepthStencil(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_AsRasterizer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[21] USING ID3D10EffectVectorVariable_AsRasterizer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_AsSampler (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[22] USING ID3D10EffectVectorVariable_AsSampler(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_SetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[23] USING ID3D10EffectVectorVariable_SetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_GetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[24] USING ID3D10EffectVectorVariable_GetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_SetBoolVector (BYVAL pthis AS DWORD PTR, BYREF pData AS LONG) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[25] USING ID3D10EffectVectorVariable_SetBoolVector(pthis, pData) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_SetIntVector (BYVAL pthis AS DWORD PTR, BYREF pData AS LONG) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[26] USING ID3D10EffectVectorVariable_SetIntVector(pthis, pData) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_SetFloatVector (BYVAL pthis AS DWORD PTR, BYREF pData AS SINGLE) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[27] USING ID3D10EffectVectorVariable_SetFloatVector(pthis, pData) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_GetBoolVector (BYVAL pthis AS DWORD PTR, BYREF pData AS LONG) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[28] USING ID3D10EffectVectorVariable_GetBoolVector(pthis, pData) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_GetIntVector (BYVAL pthis AS DWORD PTR, BYREF pData AS LONG) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[29] USING ID3D10EffectVectorVariable_GetIntVector(pthis, pData) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_GetFloatVector (BYVAL pthis AS DWORD PTR, BYREF pData AS SINGLE) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[30] USING ID3D10EffectVectorVariable_GetFloatVector(pthis, pData) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_SetBoolVectorArray (BYVAL pthis AS DWORD PTR, BYREF pData AS LONG, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[31] USING ID3D10EffectVectorVariable_SetBoolVectorArray(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_SetIntVectorArray (BYVAL pthis AS DWORD PTR, BYREF pData AS LONG, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[32] USING ID3D10EffectVectorVariable_SetIntVectorArray(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_SetFloatVectorArray (BYVAL pthis AS DWORD PTR, BYREF pData AS SINGLE, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[33] USING ID3D10EffectVectorVariable_SetFloatVectorArray(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_GetBoolVectorArray (BYVAL pthis AS DWORD PTR, BYREF pData AS LONG, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[34] USING ID3D10EffectVectorVariable_GetBoolVectorArray(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_GetIntVectorArray (BYVAL pthis AS DWORD PTR, BYREF pData AS LONG, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[35] USING ID3D10EffectVectorVariable_GetIntVectorArray(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectVectorVariable_GetFloatVectorArray (BYVAL pthis AS DWORD PTR, BYREF pData AS SINGLE, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[36] USING ID3D10EffectVectorVariable_GetFloatVectorArray(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

' //////////////////////////////////////////////////////////////////////////////
' // ID3D10EffectMatrixVariable ////////////////////////////////////////////////
' //////////////////////////////////////////////////////////////////////////////

$IID_ID3D10EffectMatrixVariable = GUID$("{50666C24-B82F-4EED-A172-5B6E7E8522E0}")

' This interface is the definition of a C++ class
'DECLARE_INTERFACE_(ID3D10EffectMatrixVariable, ID3D10EffectVariable)
'{
'    STDMETHOD_(BOOL, IsValid)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectType*, GetType)(THIS) PURE;
'    STDMETHOD(GetDesc)(THIS_ D3D10_EFFECT_VARIABLE_DESC *pDesc) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByName)(THIS_ LPCSTR Name) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByName)(THIS_ LPCSTR Name) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberBySemantic)(THIS_ LPCSTR Semantic) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetElement)(THIS_ UINT Index) PURE;

'    STDMETHOD_(ID3D10EffectConstantBuffer*, GetParentConstantBuffer)(THIS) PURE;

'    STDMETHOD_(ID3D10EffectScalarVariable*, AsScalar)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectVectorVariable*, AsVector)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectMatrixVariable*, AsMatrix)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectStringVariable*, AsString)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderResourceVariable*, AsShaderResource)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRenderTargetViewVariable*, AsRenderTargetView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilViewVariable*, AsDepthStencilView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectConstantBuffer*, AsConstantBuffer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderVariable*, AsShader)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectBlendVariable*, AsBlend)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilVariable*, AsDepthStencil)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRasterizerVariable*, AsRasterizer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectSamplerVariable*, AsSampler)(THIS) PURE;

'    STDMETHOD(SetRawValue)(THIS_ void *pData, UINT ByteOffset, UINT ByteCount) PURE;
'    STDMETHOD(GetRawValue)(THIS_ void *pData, UINT ByteOffset, UINT ByteCount) PURE;

'    STDMETHOD(SetMatrix)(THIS_ float *pData) PURE;
'    STDMETHOD(GetMatrix)(THIS_ float *pData) PURE;

'    STDMETHOD(SetMatrixArray)(THIS_ float *pData, UINT Offset, UINT Count) PURE;
'    STDMETHOD(GetMatrixArray)(THIS_ float *pData, UINT Offset, UINT Count) PURE;

'    STDMETHOD(SetMatrixTranspose)(THIS_ float *pData) PURE;
'    STDMETHOD(GetMatrixTranspose)(THIS_ float *pData) PURE;

'    STDMETHOD(SetMatrixTransposeArray)(THIS_ float *pData, UINT Offset, UINT Count) PURE;
'    STDMETHOD(GetMatrixTransposeArray)(THIS_ float *pData, UINT Offset, UINT Count) PURE;
'};

'FUNCTION ID3D10EffectMatrixVariable_IsValid (BYVAL pthis AS DWORD PTR) AS LONG
'   LOCAL BRESULT AS LONG
'   CALL DWORD @@pthis[0] USING ID3D10EffectMatrixVariable_IsValid(pthis) TO BRESULT
'   FUNCTION = BRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_GetType (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[1] USING ID3D10EffectMatrixVariable_GetType(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_GetDesc (BYVAL pthis AS DWORD PTR, BYREF pDesc AS D3D10_EFFECT_VARIABLE_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[2] USING ID3D10EffectMatrixVariable_GetDesc(pthis, pDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_GetAnnotationByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[3] USING ID3D10EffectMatrixVariable_GetAnnotationByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_GetAnnotationByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[4] USING ID3D10EffectMatrixVariable_GetAnnotationByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_GetMemberByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[5] USING ID3D10EffectMatrixVariable_GetMemberByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_GetMemberByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[6] USING ID3D10EffectMatrixVariable_GetMemberByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_GetMemberBySemantic (BYVAL pthis AS DWORD PTR, BYREF szSemantic AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[7] USING ID3D10EffectMatrixVariable_GetMemberBySemantic(pthis, szSemantic) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_GetElement (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[8] USING ID3D10EffectMatrixVariable_GetElement(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_GetParentConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[9] USING ID3D10EffectMatrixVariable_GetParentConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_AsScalar (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[10] USING ID3D10EffectMatrixVariable_AsScalar(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_AsVector (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[11] USING ID3D10EffectMatrixVariable_AsVector(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_AsMatrix (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[12] USING ID3D10EffectMatrixVariable_AsMatrix(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_AsString (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[13] USING ID3D10EffectMatrixVariable_AsString(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_AsShaderResource (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[14] USING ID3D10EffectMatrixVariable_AsShaderResource(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_AsRenderTargetView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[15] USING ID3D10EffectMatrixVariable_AsRenderTargetView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_AsDepthStencilView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[16] USING ID3D10EffectMatrixVariable_AsDepthStencilView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_AsConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[17] USING ID3D10EffectMatrixVariable_AsConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_AsShader (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[18] USING ID3D10EffectMatrixVariable_AsShader(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_AsBlend (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[19] USING ID3D10EffectMatrixVariable_AsBlend(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_AsDepthStencil (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[20] USING ID3D10EffectMatrixVariable_AsDepthStencil(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_AsRasterizer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[21] USING ID3D10EffectMatrixVariable_AsRasterizer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_AsSampler (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[22] USING ID3D10EffectMatrixVariable_AsSampler(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_SetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[23] USING ID3D10EffectMatrixVariable_SetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_GetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[24] USING ID3D10EffectMatrixVariable_GetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_SetMatrix (BYVAL pthis AS DWORD PTR, BYREF pData AS SINGLE) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[25] USING ID3D10EffectMatrixVariable_SetMatrix(pthis, pData) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_GetMatrix (BYVAL pthis AS DWORD PTR, BYREF pData AS SINGLE) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[26] USING ID3D10EffectMatrixVariable_GetMatrix(pthis, pData) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_SetMatrixArray (BYVAL pthis AS DWORD PTR, BYREF pData AS SINGLE, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[27] USING ID3D10EffectMatrixVariable_SetMatrixArray(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_GetMatrixArray (BYVAL pthis AS DWORD PTR, BYREF pData AS SINGLE, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[28] USING ID3D10EffectMatrixVariable_GetMatrixArray(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_SetMatrixTranspose (BYVAL pthis AS DWORD PTR, BYREF pData AS SINGLE) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[29] USING ID3D10EffectMatrixVariable_SetMatrixTranspose(pthis, pData) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_GetMatrixTranspose (BYVAL pthis AS DWORD PTR, BYREF pData AS SINGLE) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[30] USING ID3D10EffectMatrixVariable_GetMatrixTranspose(pthis, pData) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_SetMatrixTransposeArray (BYVAL pthis AS DWORD PTR, BYREF pData AS SINGLE, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[31] USING ID3D10EffectMatrixVariable_SetMatrixTransposeArray(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectMatrixVariable_GetMatrixTransposeArray (BYVAL pthis AS DWORD PTR, BYREF pData AS SINGLE, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[32] USING ID3D10EffectMatrixVariable_GetMatrixTransposeArray(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

' //////////////////////////////////////////////////////////////////////////////
' // ID3D10EffectStringVariable ////////////////////////////////////////////////
' //////////////////////////////////////////////////////////////////////////////

$IID_ID3D10EffectStringVariable = GUID$("{71417501-8DF9-4E0A-A78A-255F9756BAFF}")

' This interface is the definition of a C++ class
'DECLARE_INTERFACE_(ID3D10EffectStringVariable, ID3D10EffectVariable)
'{
'    STDMETHOD_(BOOL, IsValid)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectType*, GetType)(THIS) PURE;
'    STDMETHOD(GetDesc)(THIS_ D3D10_EFFECT_VARIABLE_DESC *pDesc) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByName)(THIS_ LPCSTR Name) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByName)(THIS_ LPCSTR Name) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberBySemantic)(THIS_ LPCSTR Semantic) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetElement)(THIS_ UINT Index) PURE;

'    STDMETHOD_(ID3D10EffectConstantBuffer*, GetParentConstantBuffer)(THIS) PURE;

'    STDMETHOD_(ID3D10EffectScalarVariable*, AsScalar)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectVectorVariable*, AsVector)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectMatrixVariable*, AsMatrix)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectStringVariable*, AsString)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderResourceVariable*, AsShaderResource)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRenderTargetViewVariable*, AsRenderTargetView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilViewVariable*, AsDepthStencilView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectConstantBuffer*, AsConstantBuffer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderVariable*, AsShader)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectBlendVariable*, AsBlend)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilVariable*, AsDepthStencil)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRasterizerVariable*, AsRasterizer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectSamplerVariable*, AsSampler)(THIS) PURE;

'    STDMETHOD(SetRawValue)(THIS_ void *pData, UINT Offset, UINT Count) PURE;
'    STDMETHOD(GetRawValue)(THIS_ void *pData, UINT Offset, UINT Count) PURE;

'    STDMETHOD(GetString)(THIS_ LPCSTR *ppString) PURE;
'    STDMETHOD(GetStringArray)(THIS_ LPCSTR *ppStrings, UINT Offset, UINT Count) PURE;
'};

'FUNCTION ID3D10EffectStringVariable_IsValid (BYVAL pthis AS DWORD PTR) AS LONG
'   LOCAL BRESULT AS LONG
'   CALL DWORD @@pthis[0] USING ID3D10EffectStringVariable_IsValid(pthis) TO BRESULT
'   FUNCTION = BRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_GetType (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[1] USING ID3D10EffectStringVariable_GetType(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_GetDesc (BYVAL pthis AS DWORD PTR, BYREF pDesc AS D3D10_EFFECT_VARIABLE_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[2] USING ID3D10EffectStringVariable_GetDesc(pthis, pDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_GetAnnotationByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[3] USING ID3D10EffectStringVariable_GetAnnotationByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_GetAnnotationByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[4] USING ID3D10EffectStringVariable_GetAnnotationByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_GetMemberByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[5] USING ID3D10EffectStringVariable_GetMemberByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_GetMemberByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[6] USING ID3D10EffectStringVariable_GetMemberByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_GetMemberBySemantic (BYVAL pthis AS DWORD PTR, BYREF szSemantic AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[7] USING ID3D10EffectStringVariable_GetMemberBySemantic(pthis, szSemantic) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_GetElement (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[8] USING ID3D10EffectStringVariable_GetElement(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_GetParentConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[9] USING ID3D10EffectStringVariable_GetParentConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_AsScalar (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[10] USING ID3D10EffectStringVariable_AsScalar(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_AsVector (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[11] USING ID3D10EffectStringVariable_AsVector(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_AsMatrix (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[12] USING ID3D10EffectStringVariable_AsMatrix(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_AsString (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[13] USING ID3D10EffectStringVariable_AsString(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_AsShaderResource (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[14] USING ID3D10EffectStringVariable_AsShaderResource(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_AsRenderTargetView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[15] USING ID3D10EffectStringVariable_AsRenderTargetView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_AsDepthStencilView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[16] USING ID3D10EffectStringVariable_AsDepthStencilView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_AsConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[17] USING ID3D10EffectStringVariable_AsConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_AsShader (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[18] USING ID3D10EffectStringVariable_AsShader(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_AsBlend (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[19] USING ID3D10EffectStringVariable_AsBlend(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_AsDepthStencil (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[20] USING ID3D10EffectStringVariable_AsDepthStencil(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_AsRasterizer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[21] USING ID3D10EffectStringVariable_AsRasterizer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_AsSampler (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[22] USING ID3D10EffectStringVariable_AsSampler(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_SetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[23] USING ID3D10EffectStringVariable_SetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_GetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[24] USING ID3D10EffectStringVariable_GetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_GetString (BYVAL pthis AS DWORD PTR, BYREF ppString AS ASCIIZ) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[25] USING ID3D10EffectStringVariable_GetString(pthis, ppString) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectStringVariable_GetStringArray (BYVAL pthis AS DWORD PTR, BYREF ppStrings AS ASCIIZ, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[26] USING ID3D10EffectStringVariable_GetStringArray(pthis, ppStrings, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

' //////////////////////////////////////////////////////////////////////////////
' // ID3D10EffectShaderResourceVariable ////////////////////////////////////////
' //////////////////////////////////////////////////////////////////////////////

$IID_ID3D10EffectShaderResourceVariable = GUID$("{C0A7157B-D872-4B1D-8073-EFC2ACD4B1FC}")

' This interface is the definition of a C++ class
'DECLARE_INTERFACE_(ID3D10EffectShaderResourceVariable, ID3D10EffectVariable)
'{
'    STDMETHOD_(BOOL, IsValid)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectType*, GetType)(THIS) PURE;
'    STDMETHOD(GetDesc)(THIS_ D3D10_EFFECT_VARIABLE_DESC *pDesc) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByName)(THIS_ LPCSTR Name) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByName)(THIS_ LPCSTR Name) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberBySemantic)(THIS_ LPCSTR Semantic) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetElement)(THIS_ UINT Index) PURE;

'    STDMETHOD_(ID3D10EffectConstantBuffer*, GetParentConstantBuffer)(THIS) PURE;

'    STDMETHOD_(ID3D10EffectScalarVariable*, AsScalar)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectVectorVariable*, AsVector)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectMatrixVariable*, AsMatrix)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectStringVariable*, AsString)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderResourceVariable*, AsShaderResource)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRenderTargetViewVariable*, AsRenderTargetView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilViewVariable*, AsDepthStencilView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectConstantBuffer*, AsConstantBuffer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderVariable*, AsShader)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectBlendVariable*, AsBlend)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilVariable*, AsDepthStencil)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRasterizerVariable*, AsRasterizer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectSamplerVariable*, AsSampler)(THIS) PURE;

'    STDMETHOD(SetRawValue)(THIS_ void *pData, UINT Offset, UINT Count) PURE;
'    STDMETHOD(GetRawValue)(THIS_ void *pData, UINT Offset, UINT Count) PURE;

'    STDMETHOD(SetResource)(THIS_ ID3D10ShaderResourceView *pResource) PURE;
'    STDMETHOD(GetResource)(THIS_ ID3D10ShaderResourceView **ppResource) PURE;

'    STDMETHOD(SetResourceArray)(THIS_ ID3D10ShaderResourceView **ppResources, UINT Offset, UINT Count) PURE;
'    STDMETHOD(GetResourceArray)(THIS_ ID3D10ShaderResourceView **ppResources, UINT Offset, UINT Count) PURE;
'};

'FUNCTION ID3D10EffectShaderResourceVariable_IsValid (BYVAL pthis AS DWORD PTR) AS LONG
'   LOCAL BRESULT AS LONG
'   CALL DWORD @@pthis[0] USING ID3D10EffectShaderResourceVariable_IsValid(pthis) TO BRESULT
'   FUNCTION = BRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_GetType (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[1] USING ID3D10EffectShaderResourceVariable_GetType(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_GetDesc (BYVAL pthis AS DWORD PTR, BYREF pDesc AS D3D10_EFFECT_VARIABLE_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[2] USING ID3D10EffectShaderResourceVariable_GetDesc(pthis, pDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_GetAnnotationByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[3] USING ID3D10EffectShaderResourceVariable_GetAnnotationByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_GetAnnotationByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[4] USING ID3D10EffectShaderResourceVariable_GetAnnotationByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_GetMemberByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[5] USING ID3D10EffectShaderResourceVariable_GetMemberByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_GetMemberByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[6] USING ID3D10EffectShaderResourceVariable_GetMemberByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_GetMemberBySemantic (BYVAL pthis AS DWORD PTR, BYREF szSemantic AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[7] USING ID3D10EffectShaderResourceVariable_GetMemberBySemantic(pthis, szSemantic) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_GetElement (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[8] USING ID3D10EffectShaderResourceVariable_GetElement(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_GetParentConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[9] USING ID3D10EffectShaderResourceVariable_GetParentConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_AsScalar (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[10] USING ID3D10EffectShaderResourceVariable_AsScalar(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_AsVector (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[11] USING ID3D10EffectShaderResourceVariable_AsVector(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_AsMatrix (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[12] USING ID3D10EffectShaderResourceVariable_AsMatrix(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_AsString (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[13] USING ID3D10EffectShaderResourceVariable_AsString(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_AsShaderResource (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[14] USING ID3D10EffectShaderResourceVariable_AsShaderResource(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_AsRenderTargetView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[15] USING ID3D10EffectShaderResourceVariable_AsRenderTargetView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_AsDepthStencilView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[16] USING ID3D10EffectShaderResourceVariable_AsDepthStencilView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_AsConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[17] USING ID3D10EffectShaderResourceVariable_AsConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_AsShader (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[18] USING ID3D10EffectShaderResourceVariable_AsShader(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_AsBlend (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[19] USING ID3D10EffectShaderResourceVariable_AsBlend(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_AsDepthStencil (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[20] USING ID3D10EffectShaderResourceVariable_AsDepthStencil(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_AsRasterizer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[21] USING ID3D10EffectShaderResourceVariable_AsRasterizer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_AsSampler (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[22] USING ID3D10EffectShaderResourceVariable_AsSampler(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_SetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[23] USING ID3D10EffectShaderResourceVariable_SetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_GetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[24] USING ID3D10EffectShaderResourceVariable_GetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_SetResource (BYVAL pthis AS DWORD PTR, BYVAL pResource AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[25] USING ID3D10EffectShaderResourceVariable_SetResource(pthis, pResource) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_GetResource (BYVAL pthis AS DWORD PTR, BYREF ppResource AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[26] USING ID3D10EffectShaderResourceVariable_GetResource(pthis, ppResource) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_SetResourceArray (BYVAL pthis AS DWORD PTR, BYREF ppResources AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[27] USING ID3D10EffectShaderResourceVariable_SetResourceArray(pthis, ppResources, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderResourceVariable_GetResourceArray (BYVAL pthis AS DWORD PTR, BYREF ppResources AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[28] USING ID3D10EffectShaderResourceVariable_GetResourceArray(pthis, ppResources, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

' //////////////////////////////////////////////////////////////////////////////
' // ID3D10EffectRenderTargetViewVariable //////////////////////////////////////
' //////////////////////////////////////////////////////////////////////////////

$IID_ID3D10EffectRenderTargetViewVariable = GUID$("{28CA0CC3-C2C9-40BB-B57F-67B737122B17}")

' This interface is the definition of a C++ class
'DECLARE_INTERFACE_(ID3D10EffectRenderTargetViewVariable, ID3D10EffectVariable)
'{
'    STDMETHOD_(BOOL, IsValid)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectType*, GetType)(THIS) PURE;
'    STDMETHOD(GetDesc)(THIS_ D3D10_EFFECT_VARIABLE_DESC *pDesc) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByName)(THIS_ LPCSTR Name) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByName)(THIS_ LPCSTR Name) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberBySemantic)(THIS_ LPCSTR Semantic) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetElement)(THIS_ UINT Index) PURE;

'    STDMETHOD_(ID3D10EffectConstantBuffer*, GetParentConstantBuffer)(THIS) PURE;

'    STDMETHOD_(ID3D10EffectScalarVariable*, AsScalar)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectVectorVariable*, AsVector)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectMatrixVariable*, AsMatrix)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectStringVariable*, AsString)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderResourceVariable*, AsShaderResource)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRenderTargetViewVariable*, AsRenderTargetView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilViewVariable*, AsDepthStencilView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectConstantBuffer*, AsConstantBuffer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderVariable*, AsShader)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectBlendVariable*, AsBlend)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilVariable*, AsDepthStencil)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRasterizerVariable*, AsRasterizer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectSamplerVariable*, AsSampler)(THIS) PURE;

'    STDMETHOD(SetRawValue)(THIS_ void *pData, UINT Offset, UINT Count) PURE;
'    STDMETHOD(GetRawValue)(THIS_ void *pData, UINT Offset, UINT Count) PURE;

'    STDMETHOD(SetRenderTarget)(THIS_ ID3D10RenderTargetView *pResource) PURE;
'    STDMETHOD(GetRenderTarget)(THIS_ ID3D10RenderTargetView **ppResource) PURE;

'    STDMETHOD(SetRenderTargetArray)(THIS_ ID3D10RenderTargetView **ppResources, UINT Offset, UINT Count) PURE;
'    STDMETHOD(GetRenderTargetArray)(THIS_ ID3D10RenderTargetView **ppResources, UINT Offset, UINT Count) PURE;
'};

'FUNCTION ID3D10EffectRenderTargetViewVariable_IsValid (BYVAL pthis AS DWORD PTR) AS LONG
'   LOCAL BRESULT AS LONG
'   CALL DWORD @@pthis[0] USING ID3D10EffectRenderTargetViewVariable_IsValid(pthis) TO BRESULT
'   FUNCTION = BRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_GetType (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[1] USING ID3D10EffectRenderTargetViewVariable_GetType(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_GetDesc (BYVAL pthis AS DWORD PTR, BYREF pDesc AS D3D10_EFFECT_VARIABLE_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[2] USING ID3D10EffectRenderTargetViewVariable_GetDesc(pthis, pDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_GetAnnotationByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[3] USING ID3D10EffectRenderTargetViewVariable_GetAnnotationByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_GetAnnotationByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[4] USING ID3D10EffectRenderTargetViewVariable_GetAnnotationByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_GetMemberByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[5] USING ID3D10EffectRenderTargetViewVariable_GetMemberByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_GetMemberByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[6] USING ID3D10EffectRenderTargetViewVariable_GetMemberByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_GetMemberBySemantic (BYVAL pthis AS DWORD PTR, BYREF szSemantic AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[7] USING ID3D10EffectRenderTargetViewVariable_GetMemberBySemantic(pthis, szSemantic) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_GetElement (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[8] USING ID3D10EffectRenderTargetViewVariable_GetElement(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_GetParentConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[9] USING ID3D10EffectRenderTargetViewVariable_GetParentConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_AsScalar (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[10] USING ID3D10EffectRenderTargetViewVariable_AsScalar(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_AsVector (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[11] USING ID3D10EffectRenderTargetViewVariable_AsVector(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_AsMatrix (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[12] USING ID3D10EffectRenderTargetViewVariable_AsMatrix(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_AsString (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[13] USING ID3D10EffectRenderTargetViewVariable_AsString(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_AsShaderResource (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[14] USING ID3D10EffectRenderTargetViewVariable_AsShaderResource(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_AsRenderTargetView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[15] USING ID3D10EffectRenderTargetViewVariable_AsRenderTargetView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_AsDepthStencilView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[16] USING ID3D10EffectRenderTargetViewVariable_AsDepthStencilView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_AsConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[17] USING ID3D10EffectRenderTargetViewVariable_AsConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_AsShader (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[18] USING ID3D10EffectRenderTargetViewVariable_AsShader(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_AsBlend (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[19] USING ID3D10EffectRenderTargetViewVariable_AsBlend(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_AsDepthStencil (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[20] USING ID3D10EffectRenderTargetViewVariable_AsDepthStencil(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_AsRasterizer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[21] USING ID3D10EffectRenderTargetViewVariable_AsRasterizer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_AsSampler (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[22] USING ID3D10EffectRenderTargetViewVariable_AsSampler(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_SetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[23] USING ID3D10EffectRenderTargetViewVariable_SetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_GetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[24] USING ID3D10EffectRenderTargetViewVariable_GetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_SetRenderTarget (BYVAL pthis AS DWORD PTR, BYVAL pResource AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[25] USING ID3D10EffectRenderTargetViewVariable_SetRenderTarget(pthis, pResource) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_GetRenderTarget (BYVAL pthis AS DWORD PTR, BYREF ppResource AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[26] USING ID3D10EffectRenderTargetViewVariable_GetRenderTarget(pthis, ppResource) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_SetRenderTargetArray (BYVAL pthis AS DWORD PTR, BYREF ppResources AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[27] USING ID3D10EffectRenderTargetViewVariable_SetRenderTargetArray(pthis, ppResources, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRenderTargetViewVariable_GetRenderTargetArray (BYVAL pthis AS DWORD PTR, BYREF ppResources AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[28] USING ID3D10EffectRenderTargetViewVariable_GetRenderTargetArray(pthis, ppResources, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION


' //////////////////////////////////////////////////////////////////////////////
' // ID3D10EffectDepthStencilViewVariable //////////////////////////////////////
' //////////////////////////////////////////////////////////////////////////////

$IID_ID3D10EffectDepthStencilViewVariable = GUID$("{3E02C918-CC79-4985-B622-2D92AD701623}")

' This interface is the definition of a C++ class
'DECLARE_INTERFACE_(ID3D10EffectDepthStencilViewVariable, ID3D10EffectVariable)
'{
'    STDMETHOD_(BOOL, IsValid)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectType*, GetType)(THIS) PURE;
'    STDMETHOD(GetDesc)(THIS_ D3D10_EFFECT_VARIABLE_DESC *pDesc) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByName)(THIS_ LPCSTR Name) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByName)(THIS_ LPCSTR Name) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberBySemantic)(THIS_ LPCSTR Semantic) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetElement)(THIS_ UINT Index) PURE;

'    STDMETHOD_(ID3D10EffectConstantBuffer*, GetParentConstantBuffer)(THIS) PURE;

'    STDMETHOD_(ID3D10EffectScalarVariable*, AsScalar)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectVectorVariable*, AsVector)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectMatrixVariable*, AsMatrix)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectStringVariable*, AsString)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderResourceVariable*, AsShaderResource)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRenderTargetViewVariable*, AsRenderTargetView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilViewVariable*, AsDepthStencilView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectConstantBuffer*, AsConstantBuffer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderVariable*, AsShader)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectBlendVariable*, AsBlend)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilVariable*, AsDepthStencil)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRasterizerVariable*, AsRasterizer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectSamplerVariable*, AsSampler)(THIS) PURE;

'    STDMETHOD(SetRawValue)(THIS_ void *pData, UINT Offset, UINT Count) PURE;
'    STDMETHOD(GetRawValue)(THIS_ void *pData, UINT Offset, UINT Count) PURE;

'    STDMETHOD(SetDepthStencil)(THIS_ ID3D10DepthStencilView *pResource) PURE;
'    STDMETHOD(GetDepthStencil)(THIS_ ID3D10DepthStencilView **ppResource) PURE;

'    STDMETHOD(SetDepthStencilArray)(THIS_ ID3D10DepthStencilView **ppResources, UINT Offset, UINT Count) PURE;
'    STDMETHOD(GetDepthStencilArray)(THIS_ ID3D10DepthStencilView **ppResources, UINT Offset, UINT Count) PURE;
'};

'FUNCTION ID3D10EffectDepthStencilViewVariable_IsValid (BYVAL pthis AS DWORD PTR) AS LONG
'   LOCAL BRESULT AS LONG
'   CALL DWORD @@pthis[0] USING ID3D10EffectDepthStencilViewVariable_IsValid(pthis) TO BRESULT
'   FUNCTION = BRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_GetType (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[1] USING ID3D10EffectDepthStencilViewVariable_GetType(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_GetDesc (BYVAL pthis AS DWORD PTR, BYREF pDesc AS D3D10_EFFECT_VARIABLE_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[2] USING ID3D10EffectDepthStencilViewVariable_GetDesc(pthis, pDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_GetAnnotationByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[3] USING ID3D10EffectDepthStencilViewVariable_GetAnnotationByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_GetAnnotationByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[4] USING ID3D10EffectDepthStencilViewVariable_GetAnnotationByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_GetMemberByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[5] USING ID3D10EffectDepthStencilViewVariable_GetMemberByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_GetMemberByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[6] USING ID3D10EffectDepthStencilViewVariable_GetMemberByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_GetMemberBySemantic (BYVAL pthis AS DWORD PTR, BYREF szSemantic AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[7] USING ID3D10EffectDepthStencilViewVariable_GetMemberBySemantic(pthis, szSemantic) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_GetElement (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[8] USING ID3D10EffectDepthStencilViewVariable_GetElement(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_GetParentConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[9] USING ID3D10EffectDepthStencilViewVariable_GetParentConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_AsScalar (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[10] USING ID3D10EffectDepthStencilViewVariable_AsScalar(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_AsVector (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[11] USING ID3D10EffectDepthStencilViewVariable_AsVector(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_AsMatrix (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[12] USING ID3D10EffectDepthStencilViewVariable_AsMatrix(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_AsString (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[13] USING ID3D10EffectDepthStencilViewVariable_AsString(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_AsShaderResource (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[14] USING ID3D10EffectDepthStencilViewVariable_AsShaderResource(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_AsRenderTargetView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[15] USING ID3D10EffectDepthStencilViewVariable_AsRenderTargetView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_AsDepthStencilView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[16] USING ID3D10EffectDepthStencilViewVariable_AsDepthStencilView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_AsConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[17] USING ID3D10EffectDepthStencilViewVariable_AsConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_AsShader (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[18] USING ID3D10EffectDepthStencilViewVariable_AsShader(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_AsBlend (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[19] USING ID3D10EffectDepthStencilViewVariable_AsBlend(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_AsDepthStencil (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[20] USING ID3D10EffectDepthStencilViewVariable_AsDepthStencil(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_AsRasterizer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[21] USING ID3D10EffectDepthStencilViewVariable_AsRasterizer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_AsSampler (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[22] USING ID3D10EffectDepthStencilViewVariable_AsSampler(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_SetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[23] USING ID3D10EffectDepthStencilViewVariable_SetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_GetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[24] USING ID3D10EffectDepthStencilViewVariable_GetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_SetDepthStencil (BYVAL pthis AS DWORD PTR, BYVAL pResource AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[25] USING ID3D10EffectDepthStencilViewVariable_SetDepthStencil(pthis, pResource) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_GetDepthStencil (BYVAL pthis AS DWORD PTR, BYREF ppResource AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[26] USING ID3D10EffectDepthStencilViewVariable_GetDepthStencil(pthis, ppResource) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_SetDepthStencilArray (BYVAL pthis AS DWORD PTR, BYREF ppResources AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[27] USING ID3D10EffectDepthStencilViewVariable_SetDepthStencilArray(pthis, ppResources, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilViewVariable_GetDepthStencilArray (BYVAL pthis AS DWORD PTR, BYREF ppResources AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[28] USING ID3D10EffectDepthStencilViewVariable_GetDepthStencilArray(pthis, ppResources, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION


' //////////////////////////////////////////////////////////////////////////////
' // ID3D10EffectConstantBuffer ////////////////////////////////////////////////
' //////////////////////////////////////////////////////////////////////////////

$IID_ID3D10EffectConstantBuffer = GUID$("{56648F4D-CC8B-4444-A5AD-B5A3D76E91B3}")

' This interface is the definition of a C++ class
'DECLARE_INTERFACE_(ID3D10EffectConstantBuffer, ID3D10EffectVariable)
'{
'    STDMETHOD_(ID3D10EffectType*, GetType)(THIS) PURE;
'    STDMETHOD(GetDesc)(THIS_ D3D10_EFFECT_VARIABLE_DESC *pDesc) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByName)(THIS_ LPCSTR Name) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByName)(THIS_ LPCSTR Name) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberBySemantic)(THIS_ LPCSTR Semantic) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetElement)(THIS_ UINT Index) PURE;

'    STDMETHOD_(ID3D10EffectConstantBuffer*, GetParentConstantBuffer)(THIS) PURE;

'    STDMETHOD_(ID3D10EffectScalarVariable*, AsScalar)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectVectorVariable*, AsVector)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectMatrixVariable*, AsMatrix)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectStringVariable*, AsString)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderResourceVariable*, AsShaderResource)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRenderTargetViewVariable*, AsRenderTargetView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilViewVariable*, AsDepthStencilView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectConstantBuffer*, AsConstantBuffer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderVariable*, AsShader)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectBlendVariable*, AsBlend)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilVariable*, AsDepthStencil)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRasterizerVariable*, AsRasterizer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectSamplerVariable*, AsSampler)(THIS) PURE;

'    STDMETHOD(SetRawValue)(THIS_ void *pData, UINT Offset, UINT Count) PURE;
'    STDMETHOD(GetRawValue)(THIS_ void *pData, UINT Offset, UINT Count) PURE;

'    STDMETHOD(SetConstantBuffer)(THIS_ ID3D10Buffer *pConstantBuffer) PURE;
'    STDMETHOD(GetConstantBuffer)(THIS_ ID3D10Buffer **ppConstantBuffer) PURE;

'    STDMETHOD(SetTextureBuffer)(THIS_ ID3D10ShaderResourceView *pTextureBuffer) PURE;
'    STDMETHOD(GetTextureBuffer)(THIS_ ID3D10ShaderResourceView **ppTextureBuffer) PURE;
'};

'FUNCTION ID3D10EffectConstantBuffer_IsValid (BYVAL pthis AS DWORD PTR) AS LONG
'   LOCAL BRESULT AS LONG
'   CALL DWORD @@pthis[0] USING ID3D10EffectConstantBuffer_IsValid(pthis) TO BRESULT
'   FUNCTION = BRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_GetType (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[1] USING ID3D10EffectConstantBuffer_GetType(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_GetDesc (BYVAL pthis AS DWORD PTR, BYREF pDesc AS D3D10_EFFECT_VARIABLE_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[2] USING ID3D10EffectConstantBuffer_GetDesc(pthis, pDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_GetAnnotationByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[3] USING ID3D10EffectConstantBuffer_GetAnnotationByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_GetAnnotationByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[4] USING ID3D10EffectConstantBuffer_GetAnnotationByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_GetMemberByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[5] USING ID3D10EffectConstantBuffer_GetMemberByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_GetMemberByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[6] USING ID3D10EffectConstantBuffer_GetMemberByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_GetMemberBySemantic (BYVAL pthis AS DWORD PTR, BYREF szSemantic AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[7] USING ID3D10EffectConstantBuffer_GetMemberBySemantic(pthis, szSemantic) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_GetElement (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[8] USING ID3D10EffectConstantBuffer_GetElement(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_GetParentConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[9] USING ID3D10EffectConstantBuffer_GetParentConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_AsScalar (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[10] USING ID3D10EffectConstantBuffer_AsScalar(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_AsVector (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[11] USING ID3D10EffectConstantBuffer_AsVector(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_AsMatrix (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[12] USING ID3D10EffectConstantBuffer_AsMatrix(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_AsString (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[13] USING ID3D10EffectConstantBuffer_AsString(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_AsShaderResource (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[14] USING ID3D10EffectConstantBuffer_AsShaderResource(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_AsRenderTargetView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[15] USING ID3D10EffectConstantBuffer_AsRenderTargetView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_AsDepthStencilView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[16] USING ID3D10EffectConstantBuffer_AsDepthStencilView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_AsConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[17] USING ID3D10EffectConstantBuffer_AsConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_AsShader (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[18] USING ID3D10EffectConstantBuffer_AsShader(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_AsBlend (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[19] USING ID3D10EffectConstantBuffer_AsBlend(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_AsDepthStencil (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[20] USING ID3D10EffectConstantBuffer_AsDepthStencil(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_AsRasterizer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[21] USING ID3D10EffectConstantBuffer_AsRasterizer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_AsSampler (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[22] USING ID3D10EffectConstantBuffer_AsSampler(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_SetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[23] USING ID3D10EffectConstantBuffer_SetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_GetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[24] USING ID3D10EffectConstantBuffer_GetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_SetConstantBuffer (BYVAL pthis AS DWORD PTR, BYVAL pConstantBuffer AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[25] USING ID3D10EffectConstantBuffer_SetConstantBuffer(pthis, pConstantBuffer) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_GetConstantBuffer (BYVAL pthis AS DWORD PTR, BYREF ppConstantBuffer AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[26] USING ID3D10EffectConstantBuffer_GetConstantBuffer(pthis, ppConstantBuffer) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_SetTextureBuffer (BYVAL pthis AS DWORD PTR, BYVAL pTextureBuffer AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[27] USING ID3D10EffectConstantBuffer_SetTextureBuffer(pthis, pTextureBuffer) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectConstantBuffer_GetTextureBuffer (BYVAL pthis AS DWORD PTR, BYREF ppTextureBuffer AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[28] USING ID3D10EffectConstantBuffer_GetTextureBuffer(pthis, ppTextureBuffer) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION


' //////////////////////////////////////////////////////////////////////////////
' // ID3D10EffectShaderVariable ////////////////////////////////////////////////
' //////////////////////////////////////////////////////////////////////////////

' //----------------------------------------------------------------------------
' // D3D10_EFFECT_SHADER_DESC:
' //
' // Retrieved by ID3D10EffectShaderVariable::GetShaderDesc()
' //----------------------------------------------------------------------------

' // Size = 28 bytes
TYPE D3D10_EFFECT_SHADER_DESC DWORD
   pInputSignature           AS BYTE PTR     ' CONST BYTE * // Passed into CreateInputLayout,
                                             ' // valid on VS and GS only

   IsInline                  AS LONG         ' BOOL // Is this an anonymous shader variable
                                             '      // resulting from an inline shader assignment?


   ' // -- The following fields are not valid after Optimize() --
   pBytecode                 AS BYTE PTR     ' CONST BYTE * // Shader bytecode
   BytecodeLength            AS DWORD        ' UINT

   SODecl                    AS ASCIIZ PTR   ' LPCSTR // Stream out declaration string (for GS with SO)

   NumInputSignatureEntries  AS DWORD        ' UINT // Number of entries in the input signature
   NumOutputSignatureEntries AS DWORD        ' UINT // Number of entries in the output signature
END TYPE

$IID_ID3D10EffectShaderVariable = GUID$("{80849279-C799-4797-8C33-0407A07D9E06}")

' This interface is the definition of a C++ class
'DECLARE_INTERFACE_(ID3D10EffectShaderVariable, ID3D10EffectVariable)
'{
'    STDMETHOD_(ID3D10EffectType*, GetType)(THIS) PURE;
'    STDMETHOD(GetDesc)(THIS_ D3D10_EFFECT_VARIABLE_DESC *pDesc) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByName)(THIS_ LPCSTR Name) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByName)(THIS_ LPCSTR Name) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberBySemantic)(THIS_ LPCSTR Semantic) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetElement)(THIS_ UINT Index) PURE;

'    STDMETHOD_(ID3D10EffectConstantBuffer*, GetParentConstantBuffer)(THIS) PURE;

'    STDMETHOD_(ID3D10EffectScalarVariable*, AsScalar)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectVectorVariable*, AsVector)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectMatrixVariable*, AsMatrix)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectStringVariable*, AsString)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderResourceVariable*, AsShaderResource)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRenderTargetViewVariable*, AsRenderTargetView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilViewVariable*, AsDepthStencilView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectConstantBuffer*, AsConstantBuffer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderVariable*, AsShader)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectBlendVariable*, AsBlend)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilVariable*, AsDepthStencil)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRasterizerVariable*, AsRasterizer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectSamplerVariable*, AsSampler)(THIS) PURE;

'    STDMETHOD(SetRawValue)(THIS_ void *pData, UINT Offset, UINT Count) PURE;
'    STDMETHOD(GetRawValue)(THIS_ void *pData, UINT Offset, UINT Count) PURE;

'    STDMETHOD(GetShaderDesc)(THIS_ UINT ShaderIndex, D3D10_EFFECT_SHADER_DESC *pDesc) PURE;

'    STDMETHOD(GetVertexShader)(THIS_ UINT ShaderIndex, ID3D10VertexShader **ppVS) PURE;
'    STDMETHOD(GetGeometryShader)(THIS_ UINT ShaderIndex, ID3D10GeometryShader **ppGS) PURE;
'    STDMETHOD(GetPixelShader)(THIS_ UINT ShaderIndex, ID3D10PixelShader **ppPS) PURE;

'    STDMETHOD(GetInputSignatureElementDesc)(THIS_ UINT ShaderIndex, UINT Element, D3D10_SIGNATURE_PARAMETER_DESC *pDesc) PURE;
'    STDMETHOD(GetOutputSignatureElementDesc)(THIS_ UINT ShaderIndex, UINT Element, D3D10_SIGNATURE_PARAMETER_DESC *pDesc) PURE;
'};

'FUNCTION ID3D10EffectShaderVariable_IsValid (BYVAL pthis AS DWORD PTR) AS LONG
'   LOCAL BRESULT AS LONG
'   CALL DWORD @@pthis[0] USING ID3D10EffectShaderVariable_IsValid(pthis) TO BRESULT
'   FUNCTION = BRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_GetType (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[1] USING ID3D10EffectShaderVariable_GetType(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_GetDesc (BYVAL pthis AS DWORD PTR, BYREF pDesc AS D3D10_EFFECT_VARIABLE_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[2] USING ID3D10EffectShaderVariable_GetDesc(pthis, pDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_GetAnnotationByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[3] USING ID3D10EffectShaderVariable_GetAnnotationByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_GetAnnotationByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[4] USING ID3D10EffectShaderVariable_GetAnnotationByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_GetMemberByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[5] USING ID3D10EffectShaderVariable_GetMemberByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_GetMemberByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[6] USING ID3D10EffectShaderVariable_GetMemberByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_GetMemberBySemantic (BYVAL pthis AS DWORD PTR, BYREF szSemantic AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[7] USING ID3D10EffectShaderVariable_GetMemberBySemantic(pthis, szSemantic) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_GetElement (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[8] USING ID3D10EffectShaderVariable_GetElement(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_GetParentConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[9] USING ID3D10EffectShaderVariable_GetParentConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_AsScalar (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[10] USING ID3D10EffectShaderVariable_AsScalar(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_AsVector (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[11] USING ID3D10EffectShaderVariable_AsVector(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_AsMatrix (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[12] USING ID3D10EffectShaderVariable_AsMatrix(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_AsString (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[13] USING ID3D10EffectShaderVariable_AsString(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_AsShaderResource (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[14] USING ID3D10EffectShaderVariable_AsShaderResource(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_AsRenderTargetView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[15] USING ID3D10EffectShaderVariable_AsRenderTargetView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_AsDepthStencilView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[16] USING ID3D10EffectShaderVariable_AsDepthStencilView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_AsConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[17] USING ID3D10EffectShaderVariable_AsConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_AsShader (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[18] USING ID3D10EffectShaderVariable_AsShader(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_AsBlend (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[19] USING ID3D10EffectShaderVariable_AsBlend(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_AsDepthStencil (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[20] USING ID3D10EffectShaderVariable_AsDepthStencil(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_AsRasterizer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[21] USING ID3D10EffectShaderVariable_AsRasterizer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_AsSampler (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[22] USING ID3D10EffectShaderVariable_AsSampler(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_SetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[23] USING ID3D10EffectShaderVariable_SetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_GetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[24] USING ID3D10EffectShaderVariable_GetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_GetShaderDesc (BYVAL pthis AS DWORD PTR, BYREF pDesc AS D3D10_EFFECT_SHADER_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[25] USING ID3D10EffectShaderVariable_GetShaderDesc(pthis, pDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_GetVertexShader (BYVAL pthis AS DWORD PTR, BYVAL ShaderIndex AS DWORD, BYREF ppVS AS ID3D10VertexShader) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[26] USING ID3D10EffectShaderVariable_GetVertexShader(pthis, ShaderIndex, ppVS) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_GetGeometryShader (BYVAL pthis AS DWORD PTR, BYVAL ShaderIndex AS DWORD, BYREF ppGS AS ID3D10GeometryShader) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[27] USING ID3D10EffectShaderVariable_GetGeometryShader(pthis, ShaderIndex, ppGS) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_GetPixelShader (BYVAL pthis AS DWORD PTR, BYVAL ShaderIndex AS DWORD, BYREF ppPS AS ID3D10PixelShader) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[28] USING ID3D10EffectShaderVariable_GetPixelShader(pthis, ShaderIndex, ppPS) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_GetInputSignatureElementDesc (BYVAL pthis AS DWORD PTR, BYVAL ShaderIndex AS DWORD, BYVAL dwElement AS DWORD, BYREF pDesc AS D3D10_SIGNATURE_PARAMETER_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[29] USING ID3D10EffectShaderVariable_GetInputSignatureElementDesc(pthis, ShaderIndex, dwElement, pDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectShaderVariable_GetOutputSignatureElementDesc (BYVAL pthis AS DWORD PTR, BYVAL ShaderIndex AS DWORD, BYVAL dwElement AS DWORD, BYREF pDesc AS D3D10_SIGNATURE_PARAMETER_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[30] USING ID3D10EffectShaderVariable_GetOutputSignatureElementDesc(pthis, ShaderIndex, dwElement, pDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

' //////////////////////////////////////////////////////////////////////////////
' // ID3D10EffectBlendVariable /////////////////////////////////////////////////
' //////////////////////////////////////////////////////////////////////////////

$IID_ID3D10EffectBlendVariable = GUID$("{1FCD2294-DF6D-4EAE-86B3-0E9160CFB07B}")

' This interface is the definition of a C++ class
'DECLARE_INTERFACE_(ID3D10EffectBlendVariable, ID3D10EffectVariable)
'{
'    STDMETHOD_(ID3D10EffectType*, GetType)(THIS) PURE;
'    STDMETHOD(GetDesc)(THIS_ D3D10_EFFECT_VARIABLE_DESC *pDesc) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByName)(THIS_ LPCSTR Name) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByName)(THIS_ LPCSTR Name) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberBySemantic)(THIS_ LPCSTR Semantic) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetElement)(THIS_ UINT Index) PURE;

'    STDMETHOD_(ID3D10EffectConstantBuffer*, GetParentConstantBuffer)(THIS) PURE;

'    STDMETHOD_(ID3D10EffectScalarVariable*, AsScalar)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectVectorVariable*, AsVector)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectMatrixVariable*, AsMatrix)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectStringVariable*, AsString)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderResourceVariable*, AsShaderResource)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRenderTargetViewVariable*, AsRenderTargetView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilViewVariable*, AsDepthStencilView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectConstantBuffer*, AsConstantBuffer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderVariable*, AsShader)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectBlendVariable*, AsBlend)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilVariable*, AsDepthStencil)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRasterizerVariable*, AsRasterizer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectSamplerVariable*, AsSampler)(THIS) PURE;

'    STDMETHOD(SetRawValue)(THIS_ void *pData, UINT Offset, UINT Count) PURE;
'    STDMETHOD(GetRawValue)(THIS_ void *pData, UINT Offset, UINT Count) PURE;

'    STDMETHOD(GetBlendState)(THIS_ UINT Index, ID3D10BlendState **ppBlendState) PURE;
'    STDMETHOD(GetBackingStore)(THIS_ UINT Index, D3D10_BLEND_DESC *pBlendDesc) PURE;
'};

'FUNCTION ID3D10EffectBlendVariable_IsValid (BYVAL pthis AS DWORD PTR) AS LONG
'   LOCAL BRESULT AS LONG
'   CALL DWORD @@pthis[0] USING ID3D10EffectBlendVariable_IsValid(pthis) TO BRESULT
'   FUNCTION = BRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_GetType (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[1] USING ID3D10EffectBlendVariable_GetType(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_GetDesc (BYVAL pthis AS DWORD PTR, BYREF pDesc AS D3D10_EFFECT_VARIABLE_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[2] USING ID3D10EffectBlendVariable_GetDesc(pthis, pDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_GetAnnotationByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[3] USING ID3D10EffectBlendVariable_GetAnnotationByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_GetAnnotationByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[4] USING ID3D10EffectBlendVariable_GetAnnotationByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_GetMemberByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[5] USING ID3D10EffectBlendVariable_GetMemberByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_GetMemberByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[6] USING ID3D10EffectBlendVariable_GetMemberByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_GetMemberBySemantic (BYVAL pthis AS DWORD PTR, BYREF szSemantic AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[7] USING ID3D10EffectBlendVariable_GetMemberBySemantic(pthis, szSemantic) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_GetElement (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[8] USING ID3D10EffectBlendVariable_GetElement(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_GetParentConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[9] USING ID3D10EffectBlendVariable_GetParentConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_AsScalar (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[10] USING ID3D10EffectBlendVariable_AsScalar(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_AsVector (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[11] USING ID3D10EffectBlendVariable_AsVector(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_AsMatrix (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[12] USING ID3D10EffectBlendVariable_AsMatrix(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_AsString (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[13] USING ID3D10EffectBlendVariable_AsString(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_AsShaderResource (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[14] USING ID3D10EffectBlendVariable_AsShaderResource(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_AsRenderTargetView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[15] USING ID3D10EffectBlendVariable_AsRenderTargetView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_AsDepthStencilView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[16] USING ID3D10EffectBlendVariable_AsDepthStencilView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_AsConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[17] USING ID3D10EffectBlendVariable_AsConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_AsShader (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[18] USING ID3D10EffectBlendVariable_AsShader(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_AsBlend (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[19] USING ID3D10EffectBlendVariable_AsBlend(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_AsDepthStencil (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[20] USING ID3D10EffectBlendVariable_AsDepthStencil(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_AsRasterizer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[21] USING ID3D10EffectBlendVariable_AsRasterizer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_AsSampler (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[22] USING ID3D10EffectBlendVariable_AsSampler(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_SetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[23] USING ID3D10EffectBlendVariable_SetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_GetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[24] USING ID3D10EffectBlendVariable_GetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_GetBlendState (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD, BYREF ppBlendState AS ID3D10BlendState) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[25] USING ID3D10EffectBlendVariable_GetBlendState(pthis, Index, ppBlendState) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectBlendVariable_GetBackingStore (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD, BYREF pBlendDesc AS D3D10_BLEND_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[26] USING ID3D10EffectBlendVariable_GetBackingStore(pthis, Index, pBlendDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION


' //////////////////////////////////////////////////////////////////////////////
' // ID3D10EffectDepthStencilVariable //////////////////////////////////////////
' //////////////////////////////////////////////////////////////////////////////

$IID_ID3D10EffectDepthStencilVariable = GUID$("{AF482368-330A-46A5-9A5C-01C71AF24C8D}")

' This interface is the definition of a C++ class
'DECLARE_INTERFACE_(ID3D10EffectDepthStencilVariable, ID3D10EffectVariable)
'{
'    STDMETHOD_(ID3D10EffectType*, GetType)(THIS) PURE;
'    STDMETHOD(GetDesc)(THIS_ D3D10_EFFECT_VARIABLE_DESC *pDesc) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByName)(THIS_ LPCSTR Name) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByName)(THIS_ LPCSTR Name) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberBySemantic)(THIS_ LPCSTR Semantic) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetElement)(THIS_ UINT Index) PURE;

'    STDMETHOD_(ID3D10EffectConstantBuffer*, GetParentConstantBuffer)(THIS) PURE;

'    STDMETHOD_(ID3D10EffectScalarVariable*, AsScalar)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectVectorVariable*, AsVector)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectMatrixVariable*, AsMatrix)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectStringVariable*, AsString)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderResourceVariable*, AsShaderResource)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRenderTargetViewVariable*, AsRenderTargetView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilViewVariable*, AsDepthStencilView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectConstantBuffer*, AsConstantBuffer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderVariable*, AsShader)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectBlendVariable*, AsBlend)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilVariable*, AsDepthStencil)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRasterizerVariable*, AsRasterizer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectSamplerVariable*, AsSampler)(THIS) PURE;

'    STDMETHOD(SetRawValue)(THIS_ void *pData, UINT Offset, UINT Count) PURE;
'    STDMETHOD(GetRawValue)(THIS_ void *pData, UINT Offset, UINT Count) PURE;

'    STDMETHOD(GetDepthStencilState)(THIS_ UINT Index, ID3D10DepthStencilState **ppDepthStencilState) PURE;
'    STDMETHOD(GetBackingStore)(THIS_ UINT Index, D3D10_DEPTH_STENCIL_DESC *pDepthStencilDesc) PURE;
'};

'FUNCTION ID3D10EffectDepthStencilVariable_IsValid (BYVAL pthis AS DWORD PTR) AS LONG
'   LOCAL BRESULT AS LONG
'   CALL DWORD @@pthis[0] USING ID3D10EffectDepthStencilVariable_IsValid(pthis) TO BRESULT
'   FUNCTION = BRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_GetType (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[1] USING ID3D10EffectDepthStencilVariable_GetType(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_GetDesc (BYVAL pthis AS DWORD PTR, BYREF pDesc AS D3D10_EFFECT_VARIABLE_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[2] USING ID3D10EffectDepthStencilVariable_GetDesc(pthis, pDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_GetAnnotationByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[3] USING ID3D10EffectDepthStencilVariable_GetAnnotationByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_GetAnnotationByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[4] USING ID3D10EffectDepthStencilVariable_GetAnnotationByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_GetMemberByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[5] USING ID3D10EffectDepthStencilVariable_GetMemberByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_GetMemberByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[6] USING ID3D10EffectDepthStencilVariable_GetMemberByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_GetMemberBySemantic (BYVAL pthis AS DWORD PTR, BYREF szSemantic AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[7] USING ID3D10EffectDepthStencilVariable_GetMemberBySemantic(pthis, szSemantic) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_GetElement (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[8] USING ID3D10EffectDepthStencilVariable_GetElement(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_GetParentConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[9] USING ID3D10EffectDepthStencilVariable_GetParentConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_AsScalar (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[10] USING ID3D10EffectDepthStencilVariable_AsScalar(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_AsVector (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[11] USING ID3D10EffectDepthStencilVariable_AsVector(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_AsMatrix (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[12] USING ID3D10EffectDepthStencilVariable_AsMatrix(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_AsString (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[13] USING ID3D10EffectDepthStencilVariable_AsString(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_AsShaderResource (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[14] USING ID3D10EffectDepthStencilVariable_AsShaderResource(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_AsRenderTargetView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[15] USING ID3D10EffectDepthStencilVariable_AsRenderTargetView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_AsDepthStencilView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[16] USING ID3D10EffectDepthStencilVariable_AsDepthStencilView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_AsConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[17] USING ID3D10EffectDepthStencilVariable_AsConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_AsShader (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[18] USING ID3D10EffectDepthStencilVariable_AsShader(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_AsBlend (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[19] USING ID3D10EffectDepthStencilVariable_AsBlend(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_AsDepthStencil (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[20] USING ID3D10EffectDepthStencilVariable_AsDepthStencil(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_AsRasterizer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[21] USING ID3D10EffectDepthStencilVariable_AsRasterizer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_AsSampler (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[22] USING ID3D10EffectDepthStencilVariable_AsSampler(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_SetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[23] USING ID3D10EffectDepthStencilVariable_SetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_GetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[24] USING ID3D10EffectDepthStencilVariable_GetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_GetDepthStencilState (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD, BYREF ppDepthStencilState AS ID3D10DepthStencilState) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[25] USING ID3D10EffectDepthStencilVariable_GetDepthStencilState(pthis, Index, ppDepthStencilState) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectDepthStencilVariable_GetBackingStore (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD, BYREF pDepthStencilDesc AS D3D10_DEPTH_STENCIL_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[26] USING ID3D10EffectDepthStencilVariable_GetBackingStore(pthis, Index, pDepthStencilDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION


' //////////////////////////////////////////////////////////////////////////////
' // ID3D10EffectRasterizerVariable ////////////////////////////////////////////
' //////////////////////////////////////////////////////////////////////////////

$IID_ID3D10EffectRasterizerVariable = GUID$("{21AF9F0E-4D94-4EA9-9785-2CB76B8C0B34}")

' This interface is the definition of a C++ class
'DECLARE_INTERFACE_(ID3D10EffectRasterizerVariable, ID3D10EffectVariable)
'{
'    STDMETHOD_(ID3D10EffectType*, GetType)(THIS) PURE;
'    STDMETHOD(GetDesc)(THIS_ D3D10_EFFECT_VARIABLE_DESC *pDesc) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByName)(THIS_ LPCSTR Name) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByName)(THIS_ LPCSTR Name) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberBySemantic)(THIS_ LPCSTR Semantic) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetElement)(THIS_ UINT Index) PURE;

'    STDMETHOD_(ID3D10EffectConstantBuffer*, GetParentConstantBuffer)(THIS) PURE;

'    STDMETHOD_(ID3D10EffectScalarVariable*, AsScalar)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectVectorVariable*, AsVector)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectMatrixVariable*, AsMatrix)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectStringVariable*, AsString)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderResourceVariable*, AsShaderResource)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRenderTargetViewVariable*, AsRenderTargetView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilViewVariable*, AsDepthStencilView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectConstantBuffer*, AsConstantBuffer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderVariable*, AsShader)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectBlendVariable*, AsBlend)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilVariable*, AsDepthStencil)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRasterizerVariable*, AsRasterizer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectSamplerVariable*, AsSampler)(THIS) PURE;

'    STDMETHOD(SetRawValue)(THIS_ void *pData, UINT Offset, UINT Count) PURE;
'    STDMETHOD(GetRawValue)(THIS_ void *pData, UINT Offset, UINT Count) PURE;

'    STDMETHOD(GetRasterizerState)(THIS_ UINT Index, ID3D10RasterizerState **ppRasterizerState) PURE;
'    STDMETHOD(GetBackingStore)(THIS_ UINT Index, D3D10_RASTERIZER_DESC *pRasterizerDesc) PURE;
'};

'FUNCTION ID3D10EffectRasterizerVariable_IsValid (BYVAL pthis AS DWORD PTR) AS LONG
'   LOCAL BRESULT AS LONG
'   CALL DWORD @@pthis[0] USING ID3D10EffectRasterizerVariable_IsValid(pthis) TO BRESULT
'   FUNCTION = BRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_GetType (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[1] USING ID3D10EffectRasterizerVariable_GetType(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_GetDesc (BYVAL pthis AS DWORD PTR, BYREF pDesc AS D3D10_EFFECT_VARIABLE_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[2] USING ID3D10EffectRasterizerVariable_GetDesc(pthis, pDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_GetAnnotationByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[3] USING ID3D10EffectRasterizerVariable_GetAnnotationByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_GetAnnotationByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[4] USING ID3D10EffectRasterizerVariable_GetAnnotationByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_GetMemberByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[5] USING ID3D10EffectRasterizerVariable_GetMemberByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_GetMemberByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[6] USING ID3D10EffectRasterizerVariable_GetMemberByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_GetMemberBySemantic (BYVAL pthis AS DWORD PTR, BYREF szSemantic AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[7] USING ID3D10EffectRasterizerVariable_GetMemberBySemantic(pthis, szSemantic) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_GetElement (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[8] USING ID3D10EffectRasterizerVariable_GetElement(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_GetParentConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[9] USING ID3D10EffectRasterizerVariable_GetParentConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_AsScalar (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[10] USING ID3D10EffectRasterizerVariable_AsScalar(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_AsVector (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[11] USING ID3D10EffectRasterizerVariable_AsVector(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_AsMatrix (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[12] USING ID3D10EffectRasterizerVariable_AsMatrix(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_AsString (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[13] USING ID3D10EffectRasterizerVariable_AsString(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_AsShaderResource (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[14] USING ID3D10EffectRasterizerVariable_AsShaderResource(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_AsRenderTargetView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[15] USING ID3D10EffectRasterizerVariable_AsRenderTargetView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_AsDepthStencilView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[16] USING ID3D10EffectRasterizerVariable_AsDepthStencilView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_AsConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[17] USING ID3D10EffectRasterizerVariable_AsConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_AsShader (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[18] USING ID3D10EffectRasterizerVariable_AsShader(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_AsBlend (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[19] USING ID3D10EffectRasterizerVariable_AsBlend(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_AsDepthStencil (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[20] USING ID3D10EffectRasterizerVariable_AsDepthStencil(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_AsRasterizer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[21] USING ID3D10EffectRasterizerVariable_AsRasterizer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_AsSampler (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[22] USING ID3D10EffectRasterizerVariable_AsSampler(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_SetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[23] USING ID3D10EffectRasterizerVariable_SetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_GetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[24] USING ID3D10EffectRasterizerVariable_GetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_GetRasterizerState (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD, BYREF ppRasterizerState AS ID3D10RasterizerState) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[25] USING ID3D10EffectRasterizerVariable_GetRasterizerState(pthis, Index, ppRasterizerState) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectRasterizerVariable_GetBackingStore (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD, BYREF pRasterizerDesc AS D3D10_RASTERIZER_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[26] USING ID3D10EffectRasterizerVariable_GetBackingStore(pthis, Index, pRasterizerDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION


' //////////////////////////////////////////////////////////////////////////////
' // ID3D10EffectSamplerVariable ///////////////////////////////////////////////
' //////////////////////////////////////////////////////////////////////////////

$IID_ID3D10EffectSamplerVariable = GUID$("{6530D5C7-07E9-4271-A418-E7CE4BD1E480}")

' This interface is the definition of a C++ class
'DECLARE_INTERFACE_(ID3D10EffectSamplerVariable, ID3D10EffectVariable)
'{
'    STDMETHOD_(ID3D10EffectType*, GetType)(THIS) PURE;
'    STDMETHOD(GetDesc)(THIS_ D3D10_EFFECT_VARIABLE_DESC *pDesc) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByName)(THIS_ LPCSTR Name) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberByName)(THIS_ LPCSTR Name) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetMemberBySemantic)(THIS_ LPCSTR Semantic) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetElement)(THIS_ UINT Index) PURE;

'    STDMETHOD_(ID3D10EffectConstantBuffer*, GetParentConstantBuffer)(THIS) PURE;

'    STDMETHOD_(ID3D10EffectScalarVariable*, AsScalar)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectVectorVariable*, AsVector)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectMatrixVariable*, AsMatrix)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectStringVariable*, AsString)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderResourceVariable*, AsShaderResource)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRenderTargetViewVariable*, AsRenderTargetView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilViewVariable*, AsDepthStencilView)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectConstantBuffer*, AsConstantBuffer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectShaderVariable*, AsShader)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectBlendVariable*, AsBlend)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectDepthStencilVariable*, AsDepthStencil)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectRasterizerVariable*, AsRasterizer)(THIS) PURE;
'    STDMETHOD_(ID3D10EffectSamplerVariable*, AsSampler)(THIS) PURE;

'    STDMETHOD(SetRawValue)(THIS_ void *pData, UINT Offset, UINT Count) PURE;
'    STDMETHOD(GetRawValue)(THIS_ void *pData, UINT Offset, UINT Count) PURE;

'    STDMETHOD(GetSampler)(THIS_ UINT Index, ID3D10SamplerState **ppSampler) PURE;
'    STDMETHOD(GetBackingStore)(THIS_ UINT Index, D3D10_SAMPLER_DESC *pSamplerDesc) PURE;
'};

'FUNCTION ID3D10EffectSamplerVariable_IsValid (BYVAL pthis AS DWORD PTR) AS LONG
'   LOCAL BRESULT AS LONG
'   CALL DWORD @@pthis[0] USING ID3D10EffectSamplerVariable_IsValid(pthis) TO BRESULT
'   FUNCTION = BRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_GetType (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[1] USING ID3D10EffectSamplerVariable_GetType(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_GetDesc (BYVAL pthis AS DWORD PTR, BYREF pDesc AS D3D10_EFFECT_VARIABLE_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[2] USING ID3D10EffectSamplerVariable_GetDesc(pthis, pDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_GetAnnotationByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[3] USING ID3D10EffectSamplerVariable_GetAnnotationByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_GetAnnotationByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[4] USING ID3D10EffectSamplerVariable_GetAnnotationByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_GetMemberByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[5] USING ID3D10EffectSamplerVariable_GetMemberByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_GetMemberByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[6] USING ID3D10EffectSamplerVariable_GetMemberByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_GetMemberBySemantic (BYVAL pthis AS DWORD PTR, BYREF szSemantic AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[7] USING ID3D10EffectSamplerVariable_GetMemberBySemantic(pthis, szSemantic) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_GetElement (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[8] USING ID3D10EffectSamplerVariable_GetElement(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_GetParentConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[9] USING ID3D10EffectSamplerVariable_GetParentConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_AsScalar (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[10] USING ID3D10EffectSamplerVariable_AsScalar(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_AsVector (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[11] USING ID3D10EffectSamplerVariable_AsVector(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_AsMatrix (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[12] USING ID3D10EffectSamplerVariable_AsMatrix(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_AsString (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[13] USING ID3D10EffectSamplerVariable_AsString(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_AsShaderResource (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[14] USING ID3D10EffectSamplerVariable_AsShaderResource(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_AsRenderTargetView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[15] USING ID3D10EffectSamplerVariable_AsRenderTargetView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_AsDepthStencilView (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[16] USING ID3D10EffectSamplerVariable_AsDepthStencilView(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_AsConstantBuffer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[17] USING ID3D10EffectSamplerVariable_AsConstantBuffer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_AsShader (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[18] USING ID3D10EffectSamplerVariable_AsShader(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_AsBlend (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[19] USING ID3D10EffectSamplerVariable_AsBlend(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_AsDepthStencil (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[20] USING ID3D10EffectSamplerVariable_AsDepthStencil(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_AsRasterizer (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[21] USING ID3D10EffectSamplerVariable_AsRasterizer(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_AsSampler (BYVAL pthis AS DWORD PTR) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[22] USING ID3D10EffectSamplerVariable_AsSampler(pthis) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_SetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[23] USING ID3D10EffectSamplerVariable_SetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_GetRawValue (BYVAL pthis AS DWORD PTR, BYVAL pData AS DWORD, BYVAL dwOffset AS DWORD, BYVAL dwCount AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[24] USING ID3D10EffectSamplerVariable_GetRawValue(pthis, pData, dwOffset, dwCount) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_GetSampler (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD, BYREF ppSampler AS ID3D10SamplerState) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[25] USING ID3D10EffectSamplerVariable_GetSampler(pthis, Index, ppSampler) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectSamplerVariable_GetBackingStore (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD, BYREF pSamplerDesc AS D3D10_SAMPLER_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[26] USING ID3D10EffectSamplerVariable_GetBackingStore(pthis, Index, pSamplerDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION


' //////////////////////////////////////////////////////////////////////////////
' // ID3D10EffectPass //////////////////////////////////////////////////////////
' //////////////////////////////////////////////////////////////////////////////

' //----------------------------------------------------------------------------
' // D3D10_PASS_DESC:
' //
' // Retrieved by ID3D10EffectPass::GetDesc()
' //----------------------------------------------------------------------------

' // Size = 40 bytes
TYPE D3D10_PASS_DESC DWORD
   Name                 AS ASCIIZ PTR   ' LPCSTR // Name of this pass (NULL if not anonymous)
   Annotations          AS DWORD        ' UINT // Number of annotations on this pass
   pIAInputSignature    AS BYTE PTR     ' BYTE * // Signature from VS or GS (if there is no VS)
                                        '        // or NULL if neither exists
   IAInputSignatureSize AS DWORD        ' SIZE_T // Singature size in bytes
   StencilRef           AS DWORD        ' UINT // Specified in SetDepthStencilState()
   SampleMask           AS DWORD        ' UINT // Specified in SetBlendState()
   BlendFactor(3)       AS SINGLE       ' FLOAT // Specified in SetBlendState()
END TYPE

' //----------------------------------------------------------------------------
' // D3D10_PASS_SHADER_DESC:
' //
' // Retrieved by ID3D10EffectPass::Get**ShaderDesc()
' //----------------------------------------------------------------------------

' // Size = 8 bytes
TYPE D3D10_PASS_SHADER_DESC DWORD
   pShaderVariable AS DWORD PTR   ' ID3D10EffectShaderVariable * // The variable that this shader came from.
                                  ' // If this is an inline shader assignment,
                                  ' //   the returned interface will be an
                                  ' //   anonymous shader variable, which is
                                  ' //   not retrievable any other way.  It's
                                  ' //   name in the variable description will
                                  ' //   be "$Anonymous".
                                  ' // If there is no assignment of this type in
                                  ' //   the pass block, pShaderVariable != NULL,
                                  ' //   but pShaderVariable->IsValid() == FALSE.

   ShaderIndex     AS DWORD       ' UINT // The element of pShaderVariable (if an array)
                                  ' // or 0 if not applicable
END TYPE

$IID_ID3D10EffectPass = GUID$("{5CFBEB89-1A06-46E0-B282-E3F9BFA36A54}")

' This interface is the definition of a C++ class
'DECLARE_INTERFACE(ID3D10EffectPass)
'{
'    STDMETHOD_(BOOL, IsValid)(THIS) PURE;
'    STDMETHOD(GetDesc)(THIS_ D3D10_PASS_DESC *pDesc) PURE;

'    STDMETHOD(GetVertexShaderDesc)(THIS_ D3D10_PASS_SHADER_DESC *pDesc) PURE;
'    STDMETHOD(GetGeometryShaderDesc)(THIS_ D3D10_PASS_SHADER_DESC *pDesc) PURE;
'    STDMETHOD(GetPixelShaderDesc)(THIS_ D3D10_PASS_SHADER_DESC *pDesc) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByName)(THIS_ LPCSTR Name) PURE;

'    STDMETHOD(Apply)(THIS_ UINT Flags) PURE;

'    STDMETHOD(ComputeStateBlockMask)(THIS_ D3D10_STATE_BLOCK_MASK *pStateBlockMask) PURE;
'};

'FUNCTION ID3D10EffectPass_IsValid (BYVAL pthis AS DWORD PTR) AS LONG
'   LOCAL BRESULT AS LONG
'   CALL DWORD @@pthis[0] USING ID3D10EffectPass_IsValid(pthis) TO BRESULT
'   FUNCTION = BRESULT
'END FUNCTION

'FUNCTION ID3D10EffectPass_GetDesc (BYVAL pthis AS DWORD PTR, BYREF pDesc AS D3D10_PASS_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[1] USING ID3D10EffectPass_GetDesc(pthis, pDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectPass_GetVertexShaderDesc (BYVAL pthis AS DWORD PTR, BYREF pDesc AS D3D10_PASS_SHADER_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[2] USING ID3D10EffectPass_GetVertexShaderDesc(pthis, pDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectPass_GetGeometryShaderDesc (BYVAL pthis AS DWORD PTR, BYREF pDesc AS D3D10_PASS_SHADER_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[3] USING ID3D10EffectPass_GetGeometryShaderDesc(pthis, pDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectPass_GetPixelShaderDesc (BYVAL pthis AS DWORD PTR, BYREF pDesc AS D3D10_PASS_SHADER_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[4] USING ID3D10EffectPass_GetPixelShaderDesc(pthis, pDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectPass_GetAnnotationByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[5] USING ID3D10EffectPass_GetAnnotationByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectPass_GetAnnotationByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[6] USING ID3D10EffectPass_GetAnnotationByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectPass_Apply (BYVAL pthis AS DWORD PTR, BYVAL dwFlags AS DWORD) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[7] USING ID3D10EffectPass_Apply(pthis, dwFlags) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectPass_ComputeStateBlockMask (BYVAL pthis AS DWORD PTR, BYREF pStateBlockMask AS D3D10_STATE_BLOCK_MASK) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[8] USING ID3D10EffectPass_ComputeStateBlockMask(pthis, pStateBlockMask) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION


' //////////////////////////////////////////////////////////////////////////////
' // ID3D10EffectTechnique /////////////////////////////////////////////////////
' //////////////////////////////////////////////////////////////////////////////

' //----------------------------------------------------------------------------
' // D3D10_TECHNIQUE_DESC:
' //
' // Retrieved by ID3D10EffectTechnique::GetDesc()
' //----------------------------------------------------------------------------

' // Size = 12 bytes
TYPE D3D10_TECHNIQUE_DESC DWORD
   Name        AS ASCIIZ PTR   ' LPCSTR // Name of this technique (NULL if not anonymous)
   Passes      AS DWORD        ' UINT // Number of passes contained within
   Annotations AS DWORD        ' UINT // Number of annotations on this technique
END TYPE

$IID_ID3D10EffectTechnique = GUID$("{DB122CE8-D1C9-4292-B237-24ED3DE8B175}")

' This interface is the definition of a C++ class
'DECLARE_INTERFACE(ID3D10EffectTechnique)
'{
'    STDMETHOD_(BOOL, IsValid)(THIS) PURE;
'    STDMETHOD(GetDesc)(THIS_ D3D10_TECHNIQUE_DESC *pDesc) PURE;

'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectVariable*, GetAnnotationByName)(THIS_ LPCSTR Name) PURE;

'    STDMETHOD_(ID3D10EffectPass*, GetPassByIndex)(THIS_ UINT Index) PURE;
'    STDMETHOD_(ID3D10EffectPass*, GetPassByName)(THIS_ LPCSTR Name) PURE;

'    STDMETHOD(ComputeStateBlockMask)(THIS_ D3D10_STATE_BLOCK_MASK *pStateBlockMask) PURE;
'};

'FUNCTION ID3D10EffectTechnique_IsValid (BYVAL pthis AS DWORD PTR) AS LONG
'   LOCAL BRESULT AS LONG
'   CALL DWORD @@pthis[0] USING ID3D10EffectTechnique_IsValid(pthis) TO BRESULT
'   FUNCTION = BRESULT
'END FUNCTION

'FUNCTION ID3D10EffectTechnique_GetDesc (BYVAL pthis AS DWORD PTR, BYREF pDesc AS D3D10_TECHNIQUE_DESC) AS LONG
'   LOCAL HRESULT AS LONG
'   CALL DWORD @@pthis[1] USING ID3D10EffectTechnique_GetDesc(pthis, pDesc) TO HRESULT
'   FUNCTION = HRESULT
'END FUNCTION

'FUNCTION ID3D10EffectTechnique_GetAnnotationByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[3] USING ID3D10EffectTechnique_GetAnnotationByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectTechnique_GetAnnotationByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[4] USING ID3D10EffectTechnique_GetAnnotationByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectTechnique_GetPassByIndex (BYVAL pthis AS DWORD PTR, BYVAL Index AS DWORD) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[5] USING ID3D10EffectTechnique_GetPassByIndex(pthis, Index) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectTechnique_GetPassByName (BYVAL pthis AS DWORD PTR, BYREF szName AS ASCIIZ) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[6] USING ID3D10EffectTechnique_GetPassByName(pthis, szName) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION

'FUNCTION ID3D10EffectTechnique_ComputeStateBlockMask (BYVAL pthis AS DWORD PTR, BYREF pStateBlockMask AS D3D10_STATE_BLOCK_MASK) AS DWORD
'   LOCAL DWRESULT AS LONG
'   CALL DWORD @@pthis[7] USING ID3D10EffectTechnique_ComputeStateBlockMask(pthis, pStateBlockMask) TO DWRESULT
'   FUNCTION = DWRESULT
'END FUNCTION


' //////////////////////////////////////////////////////////////////////////////
' // ID3D10Effect //////////////////////////////////////////////////////////////
' //////////////////////////////////////////////////////////////////////////////

' //----------------------------------------------------------------------------
' // D3D10_EFFECT_DESC:
' //
' // Retrieved by ID3D10Effect::GetDesc()
' //----------------------------------------------------------------------------

' // Size = 24 bytes
TYPE D3D10_EFFECT_DESC DWORD
   IsChildEffect         AS LONG    ' BOOL // TRUE if this is a child effect,
                                    ' // FALSE if this is standalone or an effect pool.
   ConstantBuffers       AS DWORD   ' UINT // Number of constant buffers in this effect,
                                    ' // excluding the effect pool.
   SharedConstantBuffers AS DWORD   ' UINT // Number of constant buffers shared in this
                                    ' // effect's pool.

   GlobalVariables       AS DWORD   ' UINT // Number of global variables in this effect,
                                    ' // excluding the effect pool.
   SharedGlobalVariables AS DWORD   ' UINT // Number of global variables shared in this
                                    ' // effect's pool.

   Techniques            AS DWORD   ' UINT // Number of techniques in this effect,
                                    ' // excluding the effect pool.
END TYPE

' ########################################################################################
' ID3D10Effect interface
' IID = AEC22FB8-76F3-4639-9BE0-28EB43A67A2E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ID3D10Effect_INTERFACE_DEFINED)
    %ID3D10Effect_INTERFACE_DEFINED = 1

$IID_ID3D10Effect = GUID$("{51B0CA8B-EC0B-4519-870D-8EE1CB5017C7}")

INTERFACE ID3D10Effect $IID_ID3D10Effect

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsValid ( _                                   ' VTable offset = 12
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD IsPool ( _                                    ' VTable offset = 16
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 20
     BYREF ppDevice AS ID3D10Device _                   ' __out ID3D10Device** ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 24
     BYREF pDesc AS D3D10_EFFECT_DESC _                 ' __out D3D10_EFFECT_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConstantBufferByIndex ( _                  ' VTable offset = 28
     BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' ID3D10EffectConstantBuffer *
   ' =====================================================================================
   METHOD GetConstantBufferByName ( _                   ' VTable offset = 32
     BYVAL Name AS DWORD _                              ' __in LPCSTR Name
   ) AS DWORD                                           ' ID3D10EffectConstantBuffer *
   ' =====================================================================================
   METHOD GetVariableByIndex ( _                        ' VTable offset = 36
     BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' ID3D10EffectVariable *
   ' =====================================================================================
   METHOD GetVariableByName ( _                         ' VTable offset = 40
     BYVAL Name AS DWORD _                              ' __in LPCSTR Name
   ) AS DWORD                                           ' ID3D10EffectVariable *
   ' =====================================================================================
   METHOD GetVariableBySemantic ( _                     ' VTable offset = 44
     BYVAL Semantic AS DWORD _                          ' __in LPCSTR Semantic
   ) AS DWORD                                           ' ID3D10EffectVariable *
   ' =====================================================================================
   METHOD GetTechniqueByIndex ( _                       ' VTable offset = 48
     BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' ID3D10EffectTechnique *
   ' =====================================================================================
   METHOD GetTechniqueByName ( _                        ' VTable offset = 52
     BYVAL Name AS DWORD _                              ' __in LPCSTR Name
   ) AS DWORD                                           ' ID3D10EffectTechnique *
   ' =====================================================================================
   METHOD Optimize ( _                                  ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsOptimized ( _                               ' VTable offset = 60
   ) AS LONG                                            ' BOOL
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10Effect_INTERFACE_DEFINED__ */

' ########################################################################################
' ID3D10EffectPool interface
' IID = 9537AB04-3250-412E-8213-FCD2F8677933
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ID3D10EffectPool_INTERFACE_DEFINED)
    %ID3D10EffectPool_INTERFACE_DEFINED = 1

$IID_ID3D10EffectPool = GUID$("{9537AB04-3250-412E-8213-FCD2F8677933}")

INTERFACE ID3D10EffectPool $IID_ID3D10EffectPool

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AsEffect ( _                                  ' VTable offset = 12
   ) AS ID3D10Effect                                    ' ID3D10Effect *
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10EffectPool_INTERFACE_DEFINED__ */


' //////////////////////////////////////////////////////////////////////////////
' // APIs //////////////////////////////////////////////////////////////////////
' //////////////////////////////////////////////////////////////////////////////


' //----------------------------------------------------------------------------
' // D3D10CreateEffectFromXXXX:
' // --------------------------
' // Creates an effect from a binary effect or file
' //
' // Parameters:
' //
' // [in]
' //
' //
' //  pData
' //      Blob of effect data, either ASCII (uncompiled, for D3D10CompileEffectFromMemory) or binary (compiled, for D3D10CreateEffect*)
' //  DataLength
' //      Length of the data blob
' //
' //  pSrcFileName
' //      Name of the ASCII Effect file pData was obtained from
' //
' //  pDefines
' //      Optional NULL-terminated array of preprocessor macro definitions.
' //  pInclude
' //      Optional interface pointer to use for handling #include directives.
' //      If this parameter is NULL, #includes will be honored when compiling
' //      from file, and will error when compiling from resource or memory.
' //  HLSLFlags
' //      Compilation flags pertaining to shaders and data types, honored by
' //      the HLSL compiler
' //  FXFlags
' //      Compilation flags pertaining to Effect compilation, honored
' //      by the Effect compiler
' //  pDevice
' //      Pointer to the D3D10 device on which to create Effect resources
' //  pEffectPool
' //      Pointer to an Effect pool to share variables with or NULL
' //
' // [out]
' //
' //  ppEffect
' //      Address of the newly created Effect interface
' //  ppEffectPool
' //      Address of the newly created Effect pool interface
' //  ppErrors
' //      If non-NULL, address of a buffer with error messages that occurred
' //      during parsing or compilation
' //
' //----------------------------------------------------------------------------

DECLARE FUNCTION D3D10CompileEffectFromMemory IMPORT "D3D10.DLL" ALIAS "D3D10CompileEffectFromMemory" ( _
   BYVAL pData AS DWORD _                               ' __in  void *pData
 , BYVAL DataLength AS DWORD _                          ' __in  SIZE_T DataLength
 , BYREF pSrcFileName AS ASCIIZ _                       ' __in  LPCSTR pSrcFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO *pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  ID3D10Include *pInclude
 , BYVAL HLSLFlags AS DWORD _                           ' __in  UINT HLSLFlags
 , BYVAL FXFlags AS DWORD _                             ' __in  UINT FXFlags
 , BYREF ppCompiledEffect AS ID3D10Blob _               ' __out ID3D10Blob **ppCompiledEffect
 , BYREF ppErrors AS ID3D10Blob _                       ' __out ID3D10Blob **ppErrors
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3D10CreateEffectFromMemory IMPORT "D3D10.DLL" ALIAS "D3D10CreateEffectFromMemory" ( _
   BYVAL pData AS DWORD _                               ' __in  void *pData
 , BYVAL DataLength AS DWORD _                          ' __in  SIZE_T DataLength
 , BYVAL FXFlags AS DWORD _                             ' __in  UINT FXFlags
 , BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device *pDevice
 , BYVAL pEffectPool AS ID3D10EffectPool _              ' __in  ID3D10EffectPool *pEffectPool
 , BYVAL ppEffect AS ID3D10Effect _                     ' __out ID3D10Effect **ppEffect
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3D10CreateEffectPoolFromMemory IMPORT "D3D10.DLL" ALIAS "D3D10CreateEffectPoolFromMemory" ( _
   BYVAL pData AS DWORD _                               ' __in  void *pData
 , BYVAL DataLength AS DWORD _                          ' __in  SIZE_T DataLength
 , BYVAL FXFlags AS DWORD _                             ' __in  UINT FXFlags
 , BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device *pDevice
 , BYREF ppEffectPool AS ID3D10EffectPool _             ' __out ID3D10EffectPool **ppEffectPool
 ) AS LONG                                              ' HRESULT

' //----------------------------------------------------------------------------
' // D3D10DisassembleEffect:
' // -----------------------
' // Takes an effect interface, and returns a buffer containing text assembly.
' //
' // Parameters:
' //  pEffect
' //      Pointer to the runtime effect interface.
' //  EnableColorCode
' //      Emit HTML tags for color coding the output?
' //  ppDisassembly
' //      Returns a buffer containing the disassembled effect.
' //----------------------------------------------------------------------------

DECLARE FUNCTION D3D10DisassembleEffect IMPORT "D3D10.DLL" ALIAS "D3D10DisassembleEffect" ( _
   BYVAL pEffect AS ID3D10Effect _                      ' __in  ID3D10Effect *pEffect
 , BYVAL EnableColorCode AS LONG _                      ' __in  BOOL EnableColorCode
 , BYREF ppDisassembly AS ID3D10Blob _                  ' __out ID3D10Blob **ppDisassembly
 ) AS LONG                                              ' HRESULT
