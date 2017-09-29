' ########################################################################################
' Microsoft Windows
' File: d3dx9shader.inc
' Contents: D3DX Shader APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3DX9SHADER_INC = 1

'//---------------------------------------------------------------------------
'// D3DXTX_VERSION:
'// --------------
'// Version token used to create a procedural texture filler in effects
'// Used by D3DXFill[]TX functions
'//---------------------------------------------------------------------------
'#define D3DXTX_VERSION(_Major,_Minor) (('T' << 24) | ('X' << 16) | ((_Major) << 8) | (_Minor))


'//----------------------------------------------------------------------------
'// D3DXSHADER flags:
'// -----------------
'// D3DXSHADER_DEBUG
'//   Insert debug file/line/type/symbol information.
'//
'// D3DXSHADER_SKIPVALIDATION
'//   Do not validate the generated code against known capabilities and
'//   constraints.  This option is only recommended when compiling shaders
'//   you KNOW will work.  (ie. have compiled before without this option.)
'//   Shaders are always validated by D3D before they are set to the device.
'//
'// D3DXSHADER_SKIPOPTIMIZATION
'//   Instructs the compiler to skip optimization steps during code generation.
'//   Unless you are trying to isolate a problem in your code using this option
'//   is not recommended.
'//
'// D3DXSHADER_PACKMATRIX_ROWMAJOR
'//   Unless explicitly specified, matrices will be packed in row-major order
'//   on input and output from the shader.
'//
'// D3DXSHADER_PACKMATRIX_COLUMNMAJOR
'//   Unless explicitly specified, matrices will be packed in column-major
'//   order on input and output from the shader.  This is generally more
'//   efficient, since it allows vector-matrix multiplication to be performed
'//   using a series of dot-products.
'//
'// D3DXSHADER_PARTIALPRECISION
'//   Force all computations in resulting shader to occur at partial precision.
'//   This may result in faster evaluation of shaders on some hardware.
'//
'// D3DXSHADER_FORCE_VS_SOFTWARE_NOOPT
'//   Force compiler to compile against the next highest available software
'//   target for vertex shaders.  This flag also turns optimizations off,
'//   and debugging on.
'//
'// D3DXSHADER_FORCE_PS_SOFTWARE_NOOPT
'//   Force compiler to compile against the next highest available software
'//   target for pixel shaders.  This flag also turns optimizations off,
'//   and debugging on.
'//
'// D3DXSHADER_NO_PRESHADER
'//   Disables Preshaders. Using this flag will cause the compiler to not
'//   pull out static expression for evaluation on the host cpu
'//
'// D3DXSHADER_AVOID_FLOW_CONTROL
'//   Hint compiler to avoid flow-control constructs where possible.
'//
'// D3DXSHADER_PREFER_FLOW_CONTROL
'//   Hint compiler to prefer flow-control constructs where possible.
'//
'//----------------------------------------------------------------------------

%D3DXSHADER_DEBUG                           = &H1      ' (1 << 0)
%D3DXSHADER_SKIPVALIDATION                  = &H2      ' (1 << 1)
%D3DXSHADER_SKIPOPTIMIZATION                = &H4      ' (1 << 2)
%D3DXSHADER_PACKMATRIX_ROWMAJOR             = &H8      ' (1 << 3)
%D3DXSHADER_PACKMATRIX_COLUMNMAJOR          = &H10     ' (1 << 4)
%D3DXSHADER_PARTIALPRECISION                = &H20     ' (1 << 5)
%D3DXSHADER_FORCE_VS_SOFTWARE_NOOPT         = &H40     ' (1 << 6)
%D3DXSHADER_FORCE_PS_SOFTWARE_NOOPT         = &H80     ' (1 << 7)
%D3DXSHADER_NO_PRESHADER                    = &H100    ' (1 << 8)
%D3DXSHADER_AVOID_FLOW_CONTROL              = &H200    ' (1 << 9)
%D3DXSHADER_PREFER_FLOW_CONTROL             = &H400    ' (1 << 10)
%D3DXSHADER_ENABLE_BACKWARDS_COMPATIBILITY  = &H1000   ' (1 << 12)
%D3DXSHADER_IEEE_STRICTNESS                 = &H2000   ' (1 << 13)
%D3DXSHADER_USE_LEGACY_D3DX9_31_DLL         = &H10000  ' (1 << 16)

'// optimization level flags
%D3DXSHADER_OPTIMIZATION_LEVEL0             = &H4000    ' (1 << 14)
%D3DXSHADER_OPTIMIZATION_LEVEL1             = 0
%D3DXSHADER_OPTIMIZATION_LEVEL2             = &HC000    ' ((1 << 14) | (1 << 15))
%D3DXSHADER_OPTIMIZATION_LEVEL3             = &H8000    ' (1 << 15)


'//----------------------------------------------------------------------------
'// D3DXHANDLE:
'// -----------
'// Handle values used to efficiently reference shader and effect parameters.
'// Strings can be used as handles.  However, handles are not always strings.
'//----------------------------------------------------------------------------

'typedef LPCSTR D3DXHANDLE;
'typedef D3DXHANDLE *LPD3DXHANDLE;


'//----------------------------------------------------------------------------
'// D3DXMACRO:
'// ----------
'// Preprocessor macro definition.  The application pass in a NULL-terminated
'// array of this structure to various D3DX APIs.  This enables the application
'// to #define tokens at runtime, before the file is parsed.
'//----------------------------------------------------------------------------

' // Size = 8 bytes
TYPE D3DXMACRO DWORD
   Name        AS ASCIIZ PTR   ' LPCSTR
   pDefinition AS ASCIIZ PTR   ' LPCSTR
END TYPE

' Must be included after D3DXMACRO because this structure is used by another include file.
#INCLUDE ONCE "d3dx9.inc"

'//----------------------------------------------------------------------------
'// D3DXSEMANTIC:
'//----------------------------------------------------------------------------

' // Size = 8 bytes
TYPE D3DXSEMANTIC DWORD
   Usage      AS DWORD   ' UINT
   UsageIndex AS DWORD   ' UINT
END TYPE


'//----------------------------------------------------------------------------
'// D3DXFRAGMENT_DESC:
'//----------------------------------------------------------------------------

' // Size = 8 bytes
TYPE D3DXFRAGMENT_DESC DWORD
   Name   AS ASCIIZ PTR   ' LPCSTR
   Target AS DWORD        ' DWORD
END TYPE


'//----------------------------------------------------------------------------
'// D3DXREGISTER_SET:
'//----------------------------------------------------------------------------

%D3DXRS_BOOL        = 0???
%D3DXRS_INT4        = 1???
%D3DXRS_FLOAT4      = 2???
%D3DXRS_SAMPLER     = 3???
' // force 32-bit size enum
%D3DXRS_FORCE_DWORD = &H7FFFFFFF???


'//----------------------------------------------------------------------------
'// D3DXPARAMETER_CLASS:
'//----------------------------------------------------------------------------

%D3DXPC_SCALAR         = 0???
%D3DXPC_VECTOR         = 1???
%D3DXPC_MATRIX_ROWS    = 2???
%D3DXPC_MATRIX_COLUMNS = 3???
%D3DXPC_OBJECT         = 4???
%D3DXPC_STRUCT         = 5???

' // force 32-bit size enum
%D3DXPC_FORCE_DWORD    = &H7FFFFFFF???

'//----------------------------------------------------------------------------
'// D3DXPARAMETER_TYPE:
'//----------------------------------------------------------------------------

%D3DXPT_VOID           = 0???
%D3DXPT_BOOL           = 1???
%D3DXPT_INT            = 2???
%D3DXPT_FLOAT          = 3???
%D3DXPT_STRING         = 4???
%D3DXPT_TEXTURE        = 5???
%D3DXPT_TEXTURE1D      = 6???
%D3DXPT_TEXTURE2D      = 7???
%D3DXPT_TEXTURE3D      = 8???
%D3DXPT_TEXTURECUBE    = 9???
%D3DXPT_SAMPLER        = 10???
%D3DXPT_SAMPLER1D      = 11???
%D3DXPT_SAMPLER2D      = 12???
%D3DXPT_SAMPLER3D      = 13???
%D3DXPT_SAMPLERCUBE    = 14???
%D3DXPT_PIXELSHADER    = 15???
%D3DXPT_VERTEXSHADER   = 16???
%D3DXPT_PIXELFRAGMENT  = 17???
%D3DXPT_VERTEXFRAGMENT = 18???

' // force 32-bit size enum
%D3DXPT_FORCE_DWORD    = &H7FFFFFFF???


'//----------------------------------------------------------------------------
'// D3DXCONSTANTTABLE_DESC:
'//----------------------------------------------------------------------------

' // Size = 12 bytes
TYPE D3DXCONSTANTTABLE_DESC DWORD
   Creator   AS ASCIIZ PTR   '  LPCSTR // Creator string
   Version   AS DWORD        '  DWORD  // Shader version
   Constants AS DWORD        '  UINT   // Number of constants
END TYPE

'//----------------------------------------------------------------------------
'// D3DXCONSTANT_DESC:
'//----------------------------------------------------------------------------

' // Size = 48 bytes
TYPE D3DXCONSTANT_DESC DWORD
   Name          AS ASCIIZ PTR   ' LPCSTR // Constant name
   RegisterSet   AS DWORD        ' D3DXREGISTER_SET // Register set
   RegisterIndex AS DWORD        ' UINT // Register index
   RegisterCount AS DWORD        ' UINT // Number of registers occupied
   Class         AS DWORD        ' D3DXPARAMETER_CLASS // Class
   Type          AS DWORD        ' D3DXPARAMETER_TYPE // Component type
   Rows          AS DWORD        ' UINT // Number of rows
   Columns       AS DWORD        ' UINT // Number of columns
   Elements      AS DWORD        ' UINT // Number of array elements
   StructMembers AS DWORD        ' UINT // Number of structure member sub-parameters
   Bytes         AS DWORD        ' UINT // Data size, in bytes
   DefaultValue  AS DWORD        ' LPCVOID // Pointer to default value
END TYPE

$IID_ID3DXConstantTable  = GUID$("{AB3C758F-093E-4356-B762-4DB18F1B3A01}")
$IID_ID3DXTextureShader  = GUID$("{3E3D67F8-AA7A-405d-A857-BA01D4758426}")
$IID_ID3DXFragmentLinker = GUID$("{1A2C0CC2-E5B6-4ebc-9E8D-390E057811B6}")


'//----------------------------------------------------------------------------
'// ID3DXConstantTable:
'//----------------------------------------------------------------------------

INTERFACE ID3DXConstantTable $IID_ID3DXConstantTable

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetBufferPointer ( _                          ' VTable offset = 12
   ) AS DWORD                                           ' LPVOID
   ' =====================================================================================
   METHOD GetBufferSize ( _                             ' VTable offset = 16
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 20
     BYREF pDesc AS D3DXCONSTANTTABLE_DESC _            ' __in_out D3DXCONSTANTTABLE_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConstantDesc ( _                           ' VTable offset = 24
     BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYREF pConstantDesc AS D3DXCONSTANT_DESC _         ' __in_out D3DXCONSTANT_DESC *pConstantDesc
   , BYREF pCount AS DWORD _                            ' __in_out UINT *pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSamplerIndex ( _                           ' VTable offset = 28
     BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetConstant ( _                               ' VTable offset = 32
     BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetConstantByName ( _                         ' VTable offset = 36
     BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYREF pName AS ASCIIZ _                            ' __in LPCSTR pName
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetConstantElement ( _                        ' VTable offset = 40
     BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD SetDefaults ( _                               ' VTable offset = 44
     BYVAL pDevice AS IDirect3DDevice9 _                ' __in LPDIRECT3DDEVICE9 pDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 48
     BYVAL pDevice AS IDirect3DDevice9 _                ' __in LPDIRECT3DDEVICE9 pDevice
   , BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYVAL pData AS DWORD _                             ' __in LPCVOID pData
   , BYVAL Bytes AS DWORD _                             ' __in UINT Bytes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBool ( _                                   ' VTable offset = 52
     BYVAL pDevice AS IDirect3DDevice9 _                ' __in LPDIRECT3DDEVICE9 pDevice
   , BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYVAL b AS LONG _                                  ' __in BOOL b
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBoolArray ( _                              ' VTable offset = 56
     BYVAL pDevice AS IDirect3DDevice9 _                ' __in LPDIRECT3DDEVICE9 pDevice
   , BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYREF pb AS LONG _                                 ' __in BOOL* pb
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInt ( _                                    ' VTable offset = 60
     BYVAL pDevice AS IDirect3DDevice9 _                ' __in LPDIRECT3DDEVICE9 pDevice
   , BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYVAL n AS LONG _                                  ' __in INT n
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIntArray ( _                               ' VTable offset = 64
     BYVAL pDevice AS IDirect3DDevice9 _                ' __in LPDIRECT3DDEVICE9 pDevice
   , BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYREF pn AS LONG _                                 ' __in CONST INT* pn
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFloat ( _                                  ' VTable offset = 68
     BYVAL pDevice AS IDirect3DDevice9 _                ' __in LPDIRECT3DDEVICE9 pDevice
   , BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYVAL f AS SINGLE _                                ' __in FLOAT f
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFloatArray ( _                             ' VTable offset = 72
     BYVAL pDevice AS IDirect3DDevice9 _                ' __in LPDIRECT3DDEVICE9 pDevice
   , BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYREF pf AS SINGLE _                               ' __in CONST FLOAT* pf
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVector ( _                                 ' VTable offset = 76
     BYVAL pDevice AS IDirect3DDevice9 _                ' __in LPDIRECT3DDEVICE9 pDevice
   , BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYREF pVector AS D3DXVECTOR4 _                     ' __in CONST D3DXVECTOR4* pVector
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVectorArray ( _                            ' VTable offset = 80
     BYVAL pDevice AS IDirect3DDevice9 _                ' __in LPDIRECT3DDEVICE9 pDevice
   , BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYREF pVector AS D3DXVECTOR4 _                     ' __in CONST D3DXVECTOR4* pVector
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrix ( _                                 ' VTable offset = 84
     BYVAL pDevice AS IDirect3DDevice9 _                ' __in LPDIRECT3DDEVICE9 pDevice
   , BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYREF pMatrix AS D3DXMATRIX _                      ' __in CONST D3DXMATRIX* pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixArray ( _                            ' VTable offset = 88
     BYVAL pDevice AS IDirect3DDevice9 _                ' __in LPDIRECT3DDEVICE9 pDevice
   , BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYREF pMatrix AS D3DXMATRIX _                      ' __in CONST D3DXMATRIX* pMatrix
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixPointerArray ( _                     ' VTable offset = 92
     BYVAL pDevice AS IDirect3DDevice9 _                ' __in LPDIRECT3DDEVICE9 pDevice
   , BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYVAL ppMatrix AS DWORD _                          ' __in CONST D3DXMATRIX** ppMatrix
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixTranspose ( _                        ' VTable offset = 96
     BYVAL pDevice AS IDirect3DDevice9 _                ' __in LPDIRECT3DDEVICE9 pDevice
   , BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYREF pMatrix AS D3DXMATRIX _                      ' __in CONST D3DXMATRIX* pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixTransposeArray ( _                   ' VTable offset = 100
     BYVAL pDevice AS IDirect3DDevice9 _                ' __in LPDIRECT3DDEVICE9 pDevice
   , BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYREF pMatrix AS D3DXMATRIX _                      ' __in CONST D3DXMATRIX* pMatrix
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixTransposePointerArray ( _            ' VTable offset = 104
     BYVAL pDevice AS IDirect3DDevice9 _                ' __in LPDIRECT3DDEVICE9 pDevice
   , BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYVAL ppMatrix AS DWORD _                          ' __in CONST D3DXMATRIX** ppMatrix
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'//----------------------------------------------------------------------------
'// ID3DXTextureShader:
'//----------------------------------------------------------------------------

INTERFACE ID3DXTextureShader $IID_ID3DXTextureShader

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFunction ( _                               ' VTable offset = 12
     BYREF ppFunction AS ID3DXBuffer _                  ' __in LPD3DXBUFFER *ppFunction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConstantBuffer ( _                         ' VTable offset = 16
     BYREF ppConstantBuffer AS ID3DXBuffer _            ' __out LPD3DXBUFFER *ppConstantBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 20
     BYREF pDesc AS D3DXCONSTANTTABLE_DESC _            ' __in_out D3DXCONSTANTTABLE_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConstantDesc ( _                           ' VTable offset = 24
     BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYREF pConstantDesc AS D3DXCONSTANT_DESC _         ' __in_out D3DXCONSTANT_DESC *pConstantDesc
   , BYREF pCount AS DWORD _                            ' __in_out UINT *pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConstant ( _                               ' VTable offset = 28
     BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetConstantByName ( _                         ' VTable offset = 32
     BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYREF pName AS ASCIIZ _                            ' __in LPCSTR pName
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetConstantElement ( _                        ' VTable offset = 36
     BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD SetDefaults ( _                               ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 44
     BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYVAL pData AS DWORD _                             ' __in LPCVOID pData
   , BYVAL Bytes AS DWORD _                             ' __in UINT Bytes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBool ( _                                   ' VTable offset = 48
     BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYVAL b AS LONG _                                  ' __in BOOL b
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBoolArray ( _                              ' VTable offset = 52
     BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYREF pb AS LONG _                                 ' __in CONST BOOL* pb
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInt ( _                                    ' VTable offset = 56
     BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYVAL n AS LONG _                                  ' __in INT n
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIntArray ( _                               ' VTable offset = 60
     BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYREF pn AS LONG _                                 ' __in CONST INT* pn
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFloat ( _                                  ' VTable offset = 64
     BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYVAL f AS SINGLE _                                ' __in FLOAT f
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFloatArray ( _                             ' VTable offset = 68
     BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYREF pf AS SINGLE _                               ' __in FLOAT* pf
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVector ( _                                 ' VTable offset = 72
     BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYREF pVector AS D3DXVECTOR4 _                     ' __in CONST D3DXVECTOR4* pVector
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVectorArray ( _                            ' VTable offset = 76
     BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYREF pVector AS D3DXVECTOR4 _                     ' __in CONST D3DXVECTOR4* pVector
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrix ( _                                 ' VTable offset = 80
     BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYREF pMatrix AS D3DXMATRIX _                      ' __in CONST D3DXMATRIX* pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixArray ( _                            ' VTable offset = 84
     BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYREF pMatrix AS D3DXMATRIX _                      ' __in CONST D3DXMATRIX* pMatrix
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixPointerArray ( _                     ' VTable offset = 88
     BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYVAL ppMatrix AS DWORD _                          ' __in CONST D3DXMATRIX** ppMatrix
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixTranspose ( _                        ' VTable offset = 92
     BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYREF pMatrix AS D3DXMATRIX _                      ' __in CONST D3DXMATRIX* pMatrix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixTransposeArray ( _                   ' VTable offset = 96
     BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYREF pMatrix AS D3DXMATRIX _                      ' __in CONST D3DXMATRIX* pMatrix
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMatrixTransposePointerArray ( _            ' VTable offset = 100
     BYVAL hConstant AS DWORD _                         ' __in D3DXHANDLE hConstant
   , BYVAL ppMatrix AS DWORD _                          ' __in CONST D3DXMATRIX** ppMatrix
   , BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'//----------------------------------------------------------------------------
'// ID3DXFragmentLinker
'//----------------------------------------------------------------------------

INTERFACE ID3DXFragmentLinker $IID_ID3DXFragmentLinker

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out LPDIRECT3DDEVICE9* ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberOfFragments ( _                      ' VTable offset = 16
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetFragmentHandleByIndex ( _                  ' VTable offset = 20
     BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetFragmentHandleByName ( _                   ' VTable offset = 24
     BYREF Name AS ASCIIZ _                             ' __in LPCSTR Name
   ) AS DWORD                                           ' D3DXHANDLE
   ' =====================================================================================
   METHOD GetFragmentDesc ( _                           ' VTable offset = 28
     BYVAL Name AS DWORD _                              ' __in D3DXHANDLE Name
   , BYREF FragDesc AS D3DXFRAGMENT_DESC _              ' __in_out LPD3DXFRAGMENT_DESC FragDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddFragments ( _                              ' VTable offset = 32
     BYREF Fragments AS DWORD _                         ' __in CONST DWORD *Fragments
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllFragments ( _                           ' VTable offset = 36
     BYREF ppBuffer AS ID3DXBuffer _                    ' __out LPD3DXBUFFER *ppBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFragment ( _                               ' VTable offset = 40
     BYVAL Name AS DWORD _                              ' __in D3DXHANDLE Name
   , BYREF ppBuffer AS ID3DXBuffer _                    ' __out LPD3DXBUFFER *ppBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LinkShader ( _                                ' VTable offset = 44
     BYREF pProfile AS ASCIIZ _                         ' __in  LPCSTR pProfile
   , BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   , BYREF rgFragmentHandles AS DWORD _                 ' __in  CONST D3DXHANDLE *rgFragmentHandles
   , BYVAL cFragments AS DWORD _                        ' __in  UINT cFragments
   , BYREF ppBuffer AS ID3DXBuffer _                    ' __out LPD3DXBUFFER *ppBuffer
   , BYREF ppErrorMsgs AS ID3DXBuffer _                 ' __out LPD3DXBUFFER *ppErrorMsgs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LinkVertexShader ( _                          ' VTable offset = 48
     BYREF pProfile AS ASCIIZ _                         ' __in  LPCSTR pProfile
   , BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   , BYREF rgFragmentHandles AS DWORD _                 ' __in  CONST D3DXHANDLE *rgFragmentHandles
   , BYVAL cFragments AS DWORD _                        ' __in  UINT cFragments
   , BYREF pVShader AS IDirect3DVertexShader9 _         ' __out LPDIRECT3DVERTEXSHADER9 *pVShader
   , BYREF ppErrorMsgs AS ID3DXBuffer _                 ' __out LPD3DXBUFFER *ppErrorMsgs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LinkPixelShader ( _                           ' VTable offset = 52
     BYREF pProfile AS ASCIIZ _                         ' __in  LPCSTR pProfile
   , BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   , BYREF rgFragmentHandles AS DWORD _                 ' __in  CONST D3DXHANDLE *rgFragmentHandles
   , BYVAL cFragments AS DWORD _                        ' __in  UINT cFragments
   , BYREF pPShader AS IDirect3DPixelShader9 _          ' __out LPDIRECT3DPIXELSHADER9 *pPShader
   , BYREF ppErrorMsgs AS ID3DXBuffer _                 ' __out LPD3DXBUFFER *ppErrorMsgs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearCache ( _                                ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'//----------------------------------------------------------------------------
'// D3DXINCLUDE_TYPE:
'//----------------------------------------------------------------------------

%D3DXINC_LOCAL       = 0???
%D3DXINC_SYSTEM      = 1???

' // force 32-bit size enum
%D3DXINC_FORCE_DWORD = &H7FFFFFFF???


'//----------------------------------------------------------------------------
'// ID3DXInclude:
'// -------------
'// This interface is intended to be implemented by the application, and can
'// be used by various D3DX APIs.  This enables application-specific handling
'// of #include directives in source files.
'//
'// Open()
'//    Opens an include file.  If successful, it should fill in ppData and
'//    pBytes.  The data pointer returned must remain valid until Close is
'//    subsequently called.
'// Close()
'//    Closes an include file.  If Open was successful, Close is guaranteed
'//    to be called before the API using this interface returns.
'//----------------------------------------------------------------------------

'DECLARE_INTERFACE(ID3DXInclude)

'    STDMETHOD(Open)(THIS_ D3DXINCLUDE_TYPE IncludeType, LPCSTR pFileName, LPCVOID pParentData, LPCVOID *ppData, UINT *pBytes) PURE;
'    STDMETHOD(Close)(THIS_ LPCVOID pData) PURE;
'};


'//////////////////////////////////////////////////////////////////////////////
'// APIs //////////////////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

'//----------------------------------------------------------------------------
'// D3DXAssembleShader:
'// -------------------
'// Assembles a shader.
'//
'// Parameters:
'//  pSrcFile
'//      Source file name
'//  hSrcModule
'//      Module handle. if NULL, current module will be used
'//  pSrcResource
'//      Resource name in module
'//  pSrcData
'//      Pointer to source code
'//  SrcDataLen
'//      Size of source code, in bytes
'//  pDefines
'//      Optional NULL-terminated array of preprocessor macro definitions.
'//  pInclude
'//      Optional interface pointer to use for handling #include directives.
'//      If this parameter is NULL, #includes will be honored when assembling
'//      from file, and will error when assembling from resource or memory.
'//  Flags
'//      See D3DXSHADER_xxx flags
'//  ppShader
'//      Returns a buffer containing the created shader.  This buffer contains
'//      the assembled shader code, as well as any embedded debug info.
'//  ppErrorMsgs
'//      Returns a buffer containing a listing of errors and warnings that were
'//      encountered during assembly.  If you are running in a debugger,
'//      these are the same messages you will see in your debug output.
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXAssembleShaderFromFileA IMPORT $D3DX_DLLNAME ALIAS "D3DXAssembleShaderFromFileA" (_
   BYREF pSrcFile AS ASCIIZ _                           ' __in  LPCSTR           pSrcFile
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO* pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE    pInclude
 , BYVAL Flags AS DWORD _                               ' __in  DWORD            Flags
 , BYREF ppShader AS ID3DXBuffer _                      ' __out LPD3DXBUFFER*    ppShader
 , BYREF ppErrorMsgs AS ID3DXBuffer _                   ' __out LPD3DXBUFFER*    ppErrorMsgs
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXAssembleShaderFromFileW IMPORT $D3DX_DLLNAME ALIAS "D3DXAssembleShaderFromFileW" (_
   BYREF pSrcFile AS WSTRINGZ _                         ' __in  LPCWSTR          pSrcFile
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO* pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE    pInclude
 , BYVAL Flags AS DWORD _                               ' __in  DWORD            Flags
 , BYREF ppShader AS ID3DXBuffer _                      ' __out LPD3DXBUFFER*    ppShader
 , BYREF ppErrorMsgs AS ID3DXBuffer _                   ' __out LPD3DXBUFFER*    ppErrorMsgs
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXAssembleShaderFromFile = D3DXAssembleShaderFromFileW
#ELSE
   MACRO D3DXAssembleShaderFromFile = D3DXAssembleShaderFromFileA
#ENDIF

DECLARE FUNCTION D3DXAssembleShaderFromResourceA IMPORT $D3DX_DLLNAME ALIAS "D3DXAssembleShaderFromResourceA" (_
   BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE          hSrcModule
 , BYREF pSrcResource AS ASCIIZ _                       ' __in  LPCSTR           pSrcResource
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO* pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE    pInclude
 , BYVAL Flags AS DWORD _                               ' __in  DWORD            Flags
 , BYREF ppShader AS ID3DXBuffer _                      ' __out LPD3DXBUFFER*    ppShader
 , BYREF ppErrorMsgs AS ID3DXBuffer _                   ' __out LPD3DXBUFFER*    ppErrorMsgs
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXAssembleShaderFromResourceW IMPORT $D3DX_DLLNAME ALIAS "D3DXAssembleShaderFromResourceW" (_
   BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE          hSrcModule
 , BYREF pSrcResource AS WSTRINGZ _                     ' __in  LPCWSTR          pSrcResource
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO* pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE    pInclude
 , BYVAL Flags AS DWORD _                               ' __in  DWORD            Flags
 , BYREF ppShader AS ID3DXBuffer _                      ' __out LPD3DXBUFFER*    ppShader
 , BYREF ppErrorMsgs AS ID3DXBuffer _                   ' __out LPD3DXBUFFER*    ppErrorMsgs
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXAssembleShaderFromResource = D3DXAssembleShaderFromResourceW
#ELSE
   MACRO D3DXAssembleShaderFromResource = D3DXAssembleShaderFromResourceA
#ENDIF

DECLARE FUNCTION D3DXAssembleShader IMPORT $D3DX_DLLNAME ALIAS "D3DXAssembleShader" (_
   BYREF pSrcData AS ASCIIZ _                           ' __in  LPCSTR           pSrcData
 , BYVAL SrcDataLen AS DWORD _                          ' __in  UINT             SrcDataLen
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO* pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE    pInclude
 , BYVAL Flags AS DWORD _                               ' __in  DWORD            Flags
 , BYREF ppShader AS ID3DXBuffer _                      ' __out LPD3DXBUFFER*    ppShader
 , BYREF ppErrorMsgs AS ID3DXBuffer _                   ' __out LPD3DXBUFFER*    ppErrorMsgs
 ) AS LONG                                              ' HRESULT


'//----------------------------------------------------------------------------
'// D3DXCompileShader:
'// ------------------
'// Compiles a shader.
'//
'// Parameters:
'//  pSrcFile
'//      Source file name.
'//  hSrcModule
'//      Module handle. if NULL, current module will be used.
'//  pSrcResource
'//      Resource name in module.
'//  pSrcData
'//      Pointer to source code.
'//  SrcDataLen
'//      Size of source code, in bytes.
'//  pDefines
'//      Optional NULL-terminated array of preprocessor macro definitions.
'//  pInclude
'//      Optional interface pointer to use for handling #include directives.
'//      If this parameter is NULL, #includes will be honored when compiling
'//      from file, and will error when compiling from resource or memory.
'//  pFunctionName
'//      Name of the entrypoint function where execution should begin.
'//  pProfile
'//      Instruction set to be used when generating code.  Currently supported
'//      profiles are "vs_1_1", "vs_2_0", "vs_2_a", "vs_2_sw", "ps_1_1",
'//      "ps_1_2", "ps_1_3", "ps_1_4", "ps_2_0", "ps_2_a", "ps_2_sw", "tx_1_0"
'//  Flags
'//      See D3DXSHADER_xxx flags.
'//  ppShader
'//      Returns a buffer containing the created shader.  This buffer contains
'//      the compiled shader code, as well as any embedded debug and symbol
'//      table info.  (See D3DXGetShaderConstantTable)
'//  ppErrorMsgs
'//      Returns a buffer containing a listing of errors and warnings that were
'//      encountered during the compile.  If you are running in a debugger,
'//      these are the same messages you will see in your debug output.
'//  ppConstantTable
'//      Returns a ID3DXConstantTable object which can be used to set
'//      shader constants to the device.  Alternatively, an application can
'//      parse the D3DXSHADER_CONSTANTTABLE block embedded as a comment within
'//      the shader.
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXCompileShaderFromFileA IMPORT $D3DX_DLLNAME ALIAS "D3DXCompileShaderFromFileA" (_
   BYREF pSrcFile AS ASCIIZ _                           ' __in  LPCSTR               pSrcFile
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO*     pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE        pInclude
 , BYREF pFunctionName AS ASCIIZ _                      ' __in  LPCSTR               pFunctionName
 , BYREF pProfile AS ASCIIZ _                           ' __in  LPCSTR               pProfile
 , BYVAL Flags AS DWORD _                               ' __in  DWORD                Flags
 , BYREF ppShader AS ID3DXBuffer _                      ' __out LPD3DXBUFFER*        ppShader
 , BYREF ppErrorMsgs AS ID3DXBuffer _                   ' __out LPD3DXBUFFER*        ppErrorMsgs
 , BYREF ppConstantTable AS ID3DXConstantTable _        ' __out LPD3DXCONSTANTTABLE* ppConstantTable
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCompileShaderFromFileW IMPORT $D3DX_DLLNAME ALIAS "D3DXCompileShaderFromFileW" (_
   BYREF pSrcFile AS WSTRINGZ _                         ' __in  LPCWSTR               pSrcFile
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO*     pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE        pInclude
 , BYREF pFunctionName AS WSTRINGZ _                    ' __in  LPCWSTR               pFunctionName
 , BYREF pProfile AS WSTRINGZ _                         ' __in  LPCWSTR               pProfile
 , BYVAL Flags AS DWORD _                               ' __in  DWORD                Flags
 , BYREF ppShader AS ID3DXBuffer _                      ' __out LPD3DXBUFFER*        ppShader
 , BYREF ppErrorMsgs AS ID3DXBuffer _                   ' __out LPD3DXBUFFER*        ppErrorMsgs
 , BYREF ppConstantTable AS ID3DXConstantTable _        ' __out LPD3DXCONSTANTTABLE* ppConstantTable
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXCompileShaderFromFile = D3DXCompileShaderFromFileW
#ELSE
   MACRO D3DXCompileShaderFromFile = D3DXCompileShaderFromFileA
#ENDIF

DECLARE FUNCTION D3DXCompileShaderFromResourceA IMPORT $D3DX_DLLNAME ALIAS "D3DXCompileShaderFromResourceA" (_
   BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE              hSrcModule
 , BYREF pSrcResource AS ASCIIZ _                       ' __in  LPCSTR               pSrcResource
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO*     pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE        pInclude
 , BYREF pFunctionName AS ASCIIZ _                      ' __in  LPCSTR               pFunctionName
 , BYREF pProfile AS ASCIIZ _                           ' __in  LPCSTR               pProfile
 , BYVAL Flags AS DWORD _                               ' __in  DWORD                Flags
 , BYREF ppShader AS ID3DXBuffer _                      ' __out LPD3DXBUFFER*        ppShader
 , BYREF ppErrorMsgs AS ID3DXBuffer _                   ' __out LPD3DXBUFFER*        ppErrorMsgs
 , BYREF ppConstantTable AS ID3DXConstantTable _        ' __out LPD3DXCONSTANTTABLE* ppConstantTable
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCompileShaderFromResourceW IMPORT $D3DX_DLLNAME ALIAS "D3DXCompileShaderFromResourceW" (_
   BYVAL hSrcModule AS DWORD _                          ' __in  HMODULE              hSrcModule
 , BYREF pSrcResource AS WSTRINGZ _                     ' __in  LPCWSTR              pSrcResource
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO*     pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE        pInclude
 , BYREF pFunctionName AS WSTRINGZ _                    ' __in  LPCWSTR              pFunctionName
 , BYREF pProfile AS WSTRINGZ _                         ' __in  LPCWSTR              pProfile
 , BYVAL Flags AS DWORD _                               ' __in  DWORD                Flags
 , BYREF ppShader AS ID3DXBuffer _                      ' __out LPD3DXBUFFER*        ppShader
 , BYREF ppErrorMsgs AS ID3DXBuffer _                   ' __out LPD3DXBUFFER*        ppErrorMsgs
 , BYREF ppConstantTable AS ID3DXConstantTable _        ' __out LPD3DXCONSTANTTABLE* ppConstantTable
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXCompileShaderFromResource = D3DXCompileShaderFromResourceW
#ELSE
   MACRO D3DXCompileShaderFromResource = D3DXCompileShaderFromResourceA
#ENDIF

DECLARE FUNCTION D3DXCompileShader IMPORT $D3DX_DLLNAME ALIAS "D3DXCompileShader" (_
   BYREF pSrcData AS ASCIIZ _                           ' __in  LPCSTR               pSrcData
 , BYVAL SrcDataLen AS DWORD _                          ' __in  UINT                 SrcDataLen
 , BYREF pDefines AS D3DXMACRO _                        ' __in  CONST D3DXMACRO*     pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3DXINCLUDE        pInclude
 , BYREF pFunctionName AS ASCIIZ _                      ' __in  LPCSTR               pFunctionName
 , BYREF pProfile AS ASCIIZ _                           ' __in  LPCSTR               pProfile
 , BYVAL Flags AS DWORD _                               ' __in  DWORD                Flags
 , BYREF ppShader AS ID3DXBuffer _                      ' __out LPD3DXBUFFER*        ppShader
 , BYREF ppErrorMsgs AS ID3DXBuffer _                   ' __out LPD3DXBUFFER*        ppErrorMsgs
 , BYREF ppConstantTable AS ID3DXConstantTable _        ' __out LPD3DXCONSTANTTABLE* ppConstantTable
 ) AS LONG                                              ' HRESULT


'//----------------------------------------------------------------------------
'// D3DXDisassembleShader:
'// ----------------------
'// Takes a binary shader, and returns a buffer containing text assembly.
'//
'// Parameters:
'//  pShader
'//      Pointer to the shader byte code.
'//  ShaderSizeInBytes
'//      Size of the shader byte code in bytes.
'//  EnableColorCode
'//      Emit HTML tags for color coding the output?
'//  pComments
'//      Pointer to a comment string to include at the top of the shader.
'//  ppDisassembly
'//      Returns a buffer containing the disassembled shader.
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXDisassembleShader IMPORT $D3DX_DLLNAME ALIAS "D3DXDisassembleShader" (_
   BYVAL pShader AS DWORD _                             ' __in  CONST DWORD*  pShader
 , BYVAL EnableColorCode AS LONG _                      ' __in  BOOL          EnableColorCode
 , BYREF pComments AS ASCIIZ _                          ' __in  LPCSTR        pComments
 , BYREF ppDisassembly AS ID3DXBuffer _                 ' __out LPD3DXBUFFER* ppDisassembly
 ) AS LONG                                              ' HRESULT


'//----------------------------------------------------------------------------
'// D3DXGetPixelShaderProfile/D3DXGetVertexShaderProfile:
'// -----------------------------------------------------
'// Returns the name of the HLSL profile best suited to a given device.
'//
'// Parameters:
'//  pDevice
'//      Pointer to the device in question
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXGetPixelShaderProfile IMPORT $D3DX_DLLNAME ALIAS "D3DXGetPixelShaderProfile" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in LPDIRECT3DDEVICE9 pDevice
 ) AS DWORD                                             ' LPCSTR

DECLARE FUNCTION D3DXGetVertexShaderProfile IMPORT $D3DX_DLLNAME ALIAS "D3DXGetVertexShaderProfile" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in LPDIRECT3DDEVICE9 pDevice
 ) AS DWORD                                             ' LPCSTR


'//----------------------------------------------------------------------------
'// D3DXFindShaderComment:
'// ----------------------
'// Searches through a shader for a particular comment, denoted by a FourCC in
'// the first DWORD of the comment.  If the comment is not found, and no other
'// error has occurred, S_FALSE is returned.
'//
'// Parameters:
'//  pFunction
'//      Pointer to the function DWORD stream
'//  FourCC
'//      FourCC used to identify the desired comment block.
'//  ppData
'//      Returns a pointer to the comment data (not including comment token
'//      and FourCC).  Can be NULL.
'//  pSizeInBytes
'//      Returns the size of the comment data in bytes.  Can be NULL.
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXFindShaderComment IMPORT $D3DX_DLLNAME ALIAS "D3DXFindShaderComment" (_
   BYVAL pFunction AS DWORD _                           ' __in  CONST DWORD* pFunction
 , BYVAL FourCC AS DWORD _                              ' __in  DWORD        FourCC
 , BYREF ppData AS ANY _                                ' __in  LPCVOID*     ppData
 , BYREF pSizeInBytes AS DWORD _                        ' __out UINT*        pSizeInBytes
 ) AS LONG                                              ' HRESULT


'//----------------------------------------------------------------------------
'// D3DXGetShaderSize:
'// ------------------
'// Returns the size of the shader byte-code, in bytes.
'//
'// Parameters:
'//  pFunction
'//      Pointer to the function DWORD stream
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXGetShaderSize IMPORT $D3DX_DLLNAME ALIAS "D3DXGetShaderSize" (_
   BYVAL pFunction AS DWORD _                           ' __in CONST DWORD* pFunction
 ) AS DWORD                                             ' UINT


'//----------------------------------------------------------------------------
'// D3DXGetShaderVersion:
'// -----------------------
'// Returns the shader version of a given shader.  Returns zero if the shader
'// function is NULL.
'//
'// Parameters:
'//  pFunction
'//      Pointer to the function DWORD stream
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXGetShaderVersion IMPORT $D3DX_DLLNAME ALIAS "D3DXGetShaderVersion" (_
   BYVAL pFunction AS DWORD _                           ' __in CONST DWORD* pFunction
 ) AS DWORD                                             ' DWORD


'//----------------------------------------------------------------------------
'// D3DXGetShaderSemantics:
'// -----------------------
'// Gets semantics for all input elements referenced inside a given shader.
'//
'// Parameters:
'//  pFunction
'//      Pointer to the function DWORD stream
'//  pSemantics
'//      Pointer to an array of D3DXSEMANTIC structures.  The function will
'//      fill this array with the semantics for each input element referenced
'//      inside the shader.  This array is assumed to contain at least
'//      MAXD3DDECLLENGTH elements.
'//  pCount
'//      Returns the number of elements referenced by the shader
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXGetShaderInputSemantics IMPORT $D3DX_DLLNAME ALIAS "D3DXGetShaderInputSemantics" (_
   BYVAL pFunction AS DWORD _                           ' __in  CONST DWORD*  pFunction
 , BYREF pSemantics AS D3DXSEMANTIC  _                  ' __in  D3DXSEMANTIC* pSemantics
 , BYREF pCount AS DWORD _                              ' __out UINT*         pCount
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXGetShaderOutputSemantics IMPORT $D3DX_DLLNAME ALIAS "D3DXGetShaderOutputSemantics" (_
   BYVAL pFunction AS DWORD _                           ' __in  CONST DWORD*  pFunction
 , BYREF pSemantics AS D3DXSEMANTIC  _                  ' __in  D3DXSEMANTIC* pSemantics
 , BYREF pCount AS DWORD _                              ' __out UINT*         pCount
 ) AS LONG                                              ' HRESULT


'//----------------------------------------------------------------------------
'// D3DXGetShaderSamplers:
'// ----------------------
'// Gets semantics for all input elements referenced inside a given shader.
'//
'// pFunction
'//      Pointer to the function DWORD stream
'// pSamplers
'//      Pointer to an array of LPCSTRs.  The function will fill this array
'//      with pointers to the sampler names contained within pFunction, for
'//      each sampler referenced inside the shader.  This array is assumed to
'//      contain at least 16 elements.
'// pCount
'//      Returns the number of samplers referenced by the shader
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXGetShaderSamplers IMPORT $D3DX_DLLNAME ALIAS "D3DXGetShaderSamplers" (_
   BYVAL pFunction AS DWORD _                           ' __in CONST DWORD* pFunction
 , BYREF pSamplers AS ASCIIZ _                          ' __in_out LPCSTR*  pSamplers
 , BYREF pCount AS DWORD _                              ' __out UINT*       pCount
 ) AS LONG                                              ' HRESULT


'//----------------------------------------------------------------------------
'// D3DXGetShaderConstantTable:
'// ---------------------------
'// Gets shader constant table embedded inside shader.  A constant table is
'// generated by D3DXAssembleShader and D3DXCompileShader, and is embedded in
'// the body of the shader.
'//
'// Parameters:
'//  pFunction
'//      Pointer to the function DWORD stream
'//  ppConstantTable
'//      Returns a ID3DXConstantTable object which can be used to set
'//      shader constants to the device.  Alternatively, an application can
'//      parse the D3DXSHADER_CONSTANTTABLE block embedded as a comment within
'//      the shader.
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXGetShaderConstantTable IMPORT $D3DX_DLLNAME ALIAS "D3DXGetShaderConstantTable" (_
   BYVAL pFunction AS DWORD _                           ' __in  CONST DWORD*         pFunction
 , BYREF ppConstantTable AS ID3DXConstantTable _        ' __out LPD3DXCONSTANTTABLE* ppConstantTable
 ) AS LONG                                              ' HRESULT


'//----------------------------------------------------------------------------
'// D3DXCreateTextureShader:
'// ------------------------
'// Creates a texture shader object, given the compiled shader.
'//
'// Parameters
'//  pFunction
'//      Pointer to the function DWORD stream
'//  ppTextureShader
'//      Returns a ID3DXTextureShader object which can be used to procedurally
'//      fill the contents of a texture using the D3DXFillTextureTX functions.
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXCreateTextureShader IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateTextureShader" (_
   BYVAL pFunction AS DWORD _                           ' __in  CONST DWORD*         pFunction
 , BYREF ppTextureShader AS ID3DXTextureShader _        ' __out LPD3DXTEXTURESHADER* ppTextureShader
 ) AS LONG                                              ' HRESULT


'//----------------------------------------------------------------------------
'// D3DXGatherFragments:
'// -------------------
'// Assembles shader fragments into a buffer to be passed to a fragment linker.
'//   will generate shader fragments for all fragments in the file
'//
'// Parameters:
'//  pSrcFile
'//      Source file name
'//  hSrcModule
'//      Module handle. if NULL, current module will be used
'//  pSrcResource
'//      Resource name in module
'//  pSrcData
'//      Pointer to source code
'//  SrcDataLen
'//      Size of source code, in bytes
'//  pDefines
'//      Optional NULL-terminated array of preprocessor macro definitions.
'//  pInclude
'//      Optional interface pointer to use for handling #include directives.
'//      If this parameter is NULL, #includes will be honored when assembling
'//      from file, and will error when assembling from resource or memory.
'//  Flags
'//      See D3DXSHADER_xxx flags
'//  ppShader
'//      Returns a buffer containing the created shader fragments.  This buffer contains
'//      the assembled shader code, as well as any embedded debug info.
'//  ppErrorMsgs
'//      Returns a buffer containing a listing of errors and warnings that were
'//      encountered during assembly.  If you are running in a debugger,
'//      these are the same messages you will see in your debug output.
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXGatherFragmentsFromFileA IMPORT $D3DX_DLLNAME ALIAS "D3DXGatherFragmentsFromFileA" (_
   BYREF pSrcFile AS ASCIIZ _                           ' __in LPCSTR            pSrcFile
 , BYREF pDefines AS D3DXMACRO _                        ' __in CONST D3DXMACRO*  pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in LPD3DXINCLUDE     pInclude
 , BYVAL Flags AS DWORD _                               ' __in DWORD             Flags
 , BYREF ppShader AS ID3DXBuffer _                      ' __in_out LPD3DXBUFFER* ppShader
 , BYREF ppErrorMsgs AS ID3DXBuffer _                   ' __in_out LPD3DXBUFFER* ppErrorMsgs
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXGatherFragmentsFromFileW IMPORT $D3DX_DLLNAME ALIAS "D3DXGatherFragmentsFromFileW" (_
   BYREF pSrcFile AS WSTRINGZ _                         ' __in LPCWSTR           pSrcFile
 , BYREF pDefines AS D3DXMACRO _                        ' __in CONST D3DXMACRO*  pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in LPD3DXINCLUDE     pInclude
 , BYVAL Flags AS DWORD _                               ' __in DWORD             Flags
 , BYREF ppShader AS ID3DXBuffer _                      ' __in_out LPD3DXBUFFER* ppShader
 , BYREF ppErrorMsgs AS ID3DXBuffer _                   ' __in_out LPD3DXBUFFER* ppErrorMsgs
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXGatherFragmentsFromFile = D3DXGatherFragmentsFromFileW
#ELSE
   MACRO D3DXGatherFragmentsFromFile = D3DXGatherFragmentsFromFileA
#ENDIF

DECLARE FUNCTION D3DXGatherFragmentsFromResourceA IMPORT $D3DX_DLLNAME ALIAS "D3DXGatherFragmentsFromResourceA" (_
   BYVAL hSrcModule AS DWORD _                          ' __in HMODULE           hSrcModule
 , BYREF pSrcResource AS ASCIIZ _                       ' __in LPCSTR            pSrcResource
 , BYREF pDefines AS D3DXMACRO _                        ' __in CONST D3DXMACRO*  pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in LPD3DXINCLUDE     pInclude
 , BYVAL Flags AS DWORD _                               ' __in DWORD             Flags
 , BYREF ppShader AS ID3DXBuffer _                      ' __in_out LPD3DXBUFFER* ppShader
 , BYREF ppErrorMsgs AS ID3DXBuffer _                   ' __in_out LPD3DXBUFFER* ppErrorMsgs
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXGatherFragmentsFromResourceW IMPORT $D3DX_DLLNAME ALIAS "D3DXGatherFragmentsFromResourceW" (_
   BYVAL hSrcModule AS DWORD _                          ' __in HMODULE           hSrcModule
 , BYREF pSrcResource AS WSTRINGZ _                     ' __in LPCWSTR           pSrcResource
 , BYREF pDefines AS D3DXMACRO _                        ' __in CONST D3DXMACRO*  pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in LPD3DXINCLUDE     pInclude
 , BYVAL Flags AS DWORD _                               ' __in DWORD             Flags
 , BYREF ppShader AS ID3DXBuffer _                      ' __in_out LPD3DXBUFFER* ppShader
 , BYREF ppErrorMsgs AS ID3DXBuffer _                   ' __in_out LPD3DXBUFFER* ppErrorMsgs
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXGatherFragmentsFromResource = D3DXGatherFragmentsFromResourceW
#ELSE
   MACRO D3DXGatherFragmentsFromResource = D3DXGatherFragmentsFromResourceA
#ENDIF

DECLARE FUNCTION D3DXGatherFragments IMPORT $D3DX_DLLNAME ALIAS "D3DXGatherFragments" (_
   BYREF pSrcData AS ASCIIZ _                           ' __in LPCSTR            pSrcData
 , BYVAL SrcDataLen AS DWORD _                          ' __in UINT              SrcDataLen
 , BYREF pDefines AS D3DXMACRO _                        ' __in CONST D3DXMACRO*  pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in LPD3DXINCLUDE     pInclude
 , BYVAL Flags AS DWORD _                               ' __in DWORD             Flags
 , BYREF ppShader AS ID3DXBuffer _                      ' __in_out LPD3DXBUFFER* ppShader
 , BYREF ppErrorMsgs AS ID3DXBuffer _                   ' __in_out LPD3DXBUFFER* ppErrorMsgs
 ) AS LONG                                              ' HRESULT


'//----------------------------------------------------------------------------
'// D3DXCreateFragmentLinker:
'// -------------------------
'// Creates a fragment linker with a given cache size.  The interface returned
'// can be used to link together shader fragments.  (both HLSL & ASM fragements)
'//
'// Parameters:
'//  pDevice
'//      Pointer to the device on which to create the shaders
'//  ShaderCacheSize
'//      Size of the shader cache
'//  ppFragmentLinker
'//      pointer to a memory location to put the created interface pointer
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXCreateFragmentLinker IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateFragmentLinker" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9     pDevice
 , BYVAL ShaderCacheSize AS DWORD _                     ' __in  UINT                  ShaderCacheSize
 , BYREF ppFragmentLinker AS ID3DXFragmentLinker _      ' __out LPD3DXFRAGMENTLINKER* ppFragmentLinker
 ) AS LONG                                              ' HRESULT


'//////////////////////////////////////////////////////////////////////////////
'// Shader comment block layouts //////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

'//----------------------------------------------------------------------------
'// D3DXSHADER_CONSTANTTABLE:
'// -------------------------
'// Shader constant information; included as an CTAB comment block inside
'// shaders.  All offsets are BYTE offsets from start of CONSTANTTABLE struct.
'// Entries in the table are sorted by Name in ascending order.
'//----------------------------------------------------------------------------

' // Size = 28 bytes
TYPE D3DXSHADER_CONSTANTTABLE DWORD
   Size         AS DWORD   ' DWORD // sizeof(D3DXSHADER_CONSTANTTABLE)
   Creator      AS DWORD   ' DWORD // LPCSTR offset
   Version      AS DWORD   ' DWORD // shader version
   Constants    AS DWORD   ' DWORD // number of constants
   ConstantInfo AS DWORD   ' DWORD // D3DXSHADER_CONSTANTINFO[Constants] offset
   Flags        AS DWORD   ' DWORD // flags shader was compiled with
   Target       AS DWORD   ' DWORD // LPCSTR offset
END TYPE

' // Size = 20 bytes
TYPE D3DXSHADER_CONSTANTINFO WORD
   Name          AS DWORD   ' DWORD // LPCSTR offset
   RegisterSet   AS WORD    ' WORD  // D3DXREGISTER_SET
   RegisterIndex AS WORD    ' WORD  // register number
   RegisterCount AS WORD    ' WORD  // number of registers
   Reserved      AS WORD    ' WORD  // reserved
   TypeInfo      AS DWORD   ' DWORD // D3DXSHADER_TYPEINFO offset
   DefaultValue  AS DWORD   ' DWORD // offset of default value
END TYPE

' // Size = 16 bytes
TYPE D3DXSHADER_TYPEINFO WORD
   Class            AS WORD    ' WORD  // D3DXPARAMETER_CLASS
   Type             AS WORD    ' WORD  // D3DXPARAMETER_TYPE
   Rows             AS WORD    ' WORD  // number of rows (matrices)
   Columns          AS WORD    ' WORD  // number of columns (vectors and matrices)
   Elements         AS WORD    ' WORD  // array dimension
   StructMembers    AS WORD    ' WORD  // number of struct members
   StructMemberInfo AS DWORD   ' DWORD // D3DXSHADER_STRUCTMEMBERINFO[Members] offset
END TYPE

' // Size = 8 bytes
TYPE D3DXSHADER_STRUCTMEMBERINFO DWORD
   Name     AS DWORD   ' DWORD // LPCSTR offset
   TypeInfo AS DWORD   ' DWORD // D3DXSHADER_TYPEINFO offset
END TYPE
