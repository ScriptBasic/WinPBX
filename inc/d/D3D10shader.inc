' ########################################################################################
' Microsoft Windows
' File: D3D10Shader.inc
' Contents: D3D10 Shader Types and APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3D10SHADER_INC = 1

'//---------------------------------------------------------------------------
'// D3D10_TX_VERSION:
'// --------------
'// Version token used to create a procedural texture filler in effects
'// Used by D3D10Fill[]TX functions
'//---------------------------------------------------------------------------
'#define D3D10_TX_VERSION(_Major,_Minor) (('T' << 24) | ('X' << 16) | ((_Major) << 8) | (_Minor))

FUNCTION D3D10_TX_VERSION (BYVAL dwMajor AS DWORD, BYVAL dwMinor AS DWORD) AS DWORD
   LOCAL dwT AS DWORD
   LOCAL dwX AS DWORD
   dwT = ASC("T")
   dwX = ASC("X")
   SHIFT LEFT dwT, 24
   SHIFT LEFT dwX, 16
   SHIFT LEFT dwMajor, 8
   FUNCTION = dwT OR dwX OR dwMajor OR dwMinor
END FUNCTION


'//----------------------------------------------------------------------------
'// D3D10SHADER flags:
'// -----------------
'// D3D10_SHADER_DEBUG
'//   Insert debug file/line/type/symbol information.
'//
'// D3D10_SHADER_SKIP_VALIDATION
'//   Do not validate the generated code against known capabilities and
'//   constraints.  This option is only recommended when compiling shaders
'//   you KNOW will work.  (ie. have compiled before without this option.)
'//   Shaders are always validated by D3D before they are set to the device.
'//
'// D3D10_SHADER_SKIP_OPTIMIZATION
'//   Instructs the compiler to skip optimization steps during code generation.
'//   Unless you are trying to isolate a problem in your code using this option
'//   is not recommended.
'//
'// D3D10_SHADER_PACK_MATRIX_ROW_MAJOR
'//   Unless explicitly specified, matrices will be packed in row-major order
'//   on input and output from the shader.
'//
'// D3D10_SHADER_PACK_MATRIX_COLUMN_MAJOR
'//   Unless explicitly specified, matrices will be packed in column-major
'//   order on input and output from the shader.  This is generally more
'//   efficient, since it allows vector-matrix multiplication to be performed
'//   using a series of dot-products.
'//
'// D3D10_SHADER_PARTIAL_PRECISION
'//   Force all computations in resulting shader to occur at partial precision.
'//   This may result in faster evaluation of shaders on some hardware.
'//
'// D3D10_SHADER_FORCE_VS_SOFTWARE_NO_OPT
'//   Force compiler to compile against the next highest available software
'//   target for vertex shaders.  This flag also turns optimizations off,
'//   and debugging on.
'//
'// D3D10_SHADER_FORCE_PS_SOFTWARE_NO_OPT
'//   Force compiler to compile against the next highest available software
'//   target for pixel shaders.  This flag also turns optimizations off,
'//   and debugging on.
'//
'// D3D10_SHADER_NO_PRESHADER
'//   Disables Preshaders. Using this flag will cause the compiler to not
'//   pull out static expression for evaluation on the host cpu
'//
'// D3D10_SHADER_AVOID_FLOW_CONTROL
'//   Hint compiler to avoid flow-control constructs where possible.
'//
'// D3D10_SHADER_PREFER_FLOW_CONTROL
'//   Hint compiler to prefer flow-control constructs where possible.
'//
'// D3D10_SHADER_ENABLE_STRICTNESS
'//   By default, the HLSL/Effect compilers are not strict on deprecated syntax.
'//   Specifying this flag enables the strict mode. Deprecated syntax may be
'//   removed in a future release, and enabling syntax is a good way to make sure
'//   your shaders comply to the latest spec.
'//
'// D3D10_SHADER_ENABLE_BACKWARDS_COMPATIBILITY
'//   This enables older shaders to compile to 4_0 targets.
'//
'//----------------------------------------------------------------------------

%D3D10_SHADER_DEBUG                          = &H1???      ' 1 << 0
%D3D10_SHADER_SKIP_VALIDATION                = &H2???      ' 1 << 1
%D3D10_SHADER_SKIP_OPTIMIZATION              = &H4???      ' 1 << 2
%D3D10_SHADER_PACK_MATRIX_ROW_MAJOR          = &H8???      ' 1 << 3
%D3D10_SHADER_PACK_MATRIX_COLUMN_MAJOR       = &H10???     ' 1 << 4
%D3D10_SHADER_PARTIAL_PRECISION              = &H20???     ' 1 << 5
%D3D10_SHADER_FORCE_VS_SOFTWARE_NO_OPT       = &H40???     ' 1 << 6
%D3D10_SHADER_FORCE_PS_SOFTWARE_NO_OPT       = &H80???     ' 1 << 7
%D3D10_SHADER_NO_PRESHADER                   = &H100???    ' 1 << 8
%D3D10_SHADER_AVOID_FLOW_CONTROL             = &H200???    ' 1 << 9
%D3D10_SHADER_PREFER_FLOW_CONTROL            = &H400???    ' 1 << 10
%D3D10_SHADER_ENABLE_STRICTNESS              = &H800???    ' 1 << 11
%D3D10_SHADER_ENABLE_BACKWARDS_COMPATIBILITY = &H1000???   ' 1 << 12
%D3D10_SHADER_IEEE_STRICTNESS                = &H2000???   ' 1 << 13
%D3D10_SHADER_WARNINGS_ARE_ERRORS            = &H4000???   ' (1 << 18)


'// optimization level flags
%D3D10_SHADER_OPTIMIZATION_LEVEL0            = &H4000???   ' 1 << 14
%D3D10_SHADER_OPTIMIZATION_LEVEL1            = 0???
%D3D10_SHADER_OPTIMIZATION_LEVEL2            = &H4000??? OR &H8000???   ' 1 << 14 | 1 << 15
%D3D10_SHADER_OPTIMIZATION_LEVEL3            = &H8000???   ' 1 << 15


'//----------------------------------------------------------------------------
'// D3D10_SHADER_MACRO:
'// ----------
'// Preprocessor macro definition.  The application pass in a NULL-terminated
'// array of this structure to various D3D10 APIs.  This enables the application
'// to #define tokens at runtime, before the file is parsed.
'//----------------------------------------------------------------------------

' // Size = 8 bytes
TYPE D3D10_SHADER_MACRO DWORD
   Name       AS ASCIIZ PTR   ' LPCSTR
   Definition AS ASCIIZ PTR   ' LPCSTR
END TYPE

'//----------------------------------------------------------------------------
'// D3D10_SHADER_VARIABLE_CLASS:
'//----------------------------------------------------------------------------

' enum D3D10_SHADER_VARIABLE_CLASS
%D3D10_SVC_SCALAR            = 0???
%D3D10_SVC_VECTOR            = 1???
%D3D10_SVC_MATRIX_ROWS       = 2???
%D3D10_SVC_MATRIX_COLUMNS    = 3???
%D3D10_SVC_OBJECT            = 4???
%D3D10_SVC_STRUCT            = 5???
%D3D11_SVC_INTERFACE_CLASS   = 6???
%D3D11_SVC_INTERFACE_POINTER = 7???

' // force 32-bit size enum
%D3D10_SVC_FORCE_DWORD = &H7fffffff???

' enum _D3D10_SHADER_VARIABLE_FLAGS
%D3D10_SVF_USERPACKED        = 1???
%D3D10_SVF_USED              = 2???
%D3D11_SVF_INTERFACE_POINTER = 4???

' // force 32-bit size enum
%D3D10_SVF_FORCE_DWORD = &H7fffffff???

'//----------------------------------------------------------------------------
'// D3D10_SHADER_VARIABLE_TYPE:
'//----------------------------------------------------------------------------
' enum D3D10_SHADER_VARIABLE_TYPE
%D3D10_SVT_VOID              = 0???
%D3D10_SVT_BOOL              = 1???
%D3D10_SVT_INT               = 2???
%D3D10_SVT_FLOAT             = 3???
%D3D10_SVT_STRING            = 4???
%D3D10_SVT_TEXTURE           = 5???
%D3D10_SVT_TEXTURE1D         = 6???
%D3D10_SVT_TEXTURE2D         = 7???
%D3D10_SVT_TEXTURE3D         = 8???
%D3D10_SVT_TEXTURECUBE       = 9???
%D3D10_SVT_SAMPLER           = 10???
%D3D10_SVT_PIXELSHADER       = 15???
%D3D10_SVT_VERTEXSHADER      = 16???
%D3D10_SVT_UINT              = 19???
%D3D10_SVT_UINT8             = 20???
%D3D10_SVT_GEOMETRYSHADER    = 21???
%D3D10_SVT_RASTERIZER        = 22???
%D3D10_SVT_DEPTHSTENCIL      = 23???
%D3D10_SVT_BLEND             = 24???
%D3D10_SVT_BUFFER            = 25???
%D3D10_SVT_CBUFFER           = 26???
%D3D10_SVT_TBUFFER           = 27???
%D3D10_SVT_TEXTURE1DARRAY    = 28???
%D3D10_SVT_TEXTURE2DARRAY    = 29???
%D3D10_SVT_RENDERTARGETVIEW  = 30???
%D3D10_SVT_DEPTHSTENCILVIEW  = 31???

%D3D10_SVT_TEXTURE2DMS       = 32???
%D3D10_SVT_TEXTURE2DMSARRAY  = 33???

%D3D10_SVT_TEXTURECUBEARRAY  = 34???

%D3D11_SVT_HULLSHADER        = 35???
%D3D11_SVT_DOMAINSHADER      = 36???

%D3D11_SVT_INTERFACE_POINTER = 37???
%D3D11_SVT_COMPUTESHADER     = 38???

%D3D11_SVT_DOUBLE            = 39???

' // force 32-bit size enum
%D3D10_SVT_FORCE_DWORD       = &H7fffffff???

' enum D3D10_SHADER_INPUT_FLAGS
%D3D10_SIF_USERPACKED          = 1???
%D3D10_SIF_COMPARISON_SAMPLER  = 2???   ' // is this a comparison sampler?
%D3D10_SIF_TEXTURE_COMPONENT_0 = 4???   ' // this 2-bit value encodes c - 1, where c
%D3D10_SIF_TEXTURE_COMPONENT_1 = 8???   ' // is the number of components in the texture
%D3D10_SIF_TEXTURE_COMPONENTS  = 12???

' // force 32-bit size enum
%D3D10_SIF_FORCE_DWORD = &H7fffffff???

'//----------------------------------------------------------------------------
'// D3D10_SHADER_INPUT_TYPE
'//----------------------------------------------------------------------------
' enum D3D10_SHADER_INPUT_TYPE
%D3D10_SIT_CBUFFER                       = 0
%D3D10_SIT_TBUFFER                       = 1
%D3D10_SIT_TEXTURE                       = 2
%D3D10_SIT_SAMPLER                       = 3
%D3D11_SIT_UAV_RWTYPED                   = 4
%D3D11_SIT_STRUCTURED                    = 5
%D3D11_SIT_UAV_RWSTRUCTURED              = 6
%D3D11_SIT_BYTEADDRESS                   = 7
%D3D11_SIT_UAV_RWBYTEADDRESS             = 8
%D3D11_SIT_UAV_APPEND_STRUCTURED         = 9
%D3D11_SIT_UAV_CONSUME_STRUCTURED        = 10
%D3D11_SIT_UAV_RWSTRUCTURED_WITH_COUNTER = 11

' enum D3D10_SHADER_CBUFFER_FLAGS
%D3D10_CBF_USERPACKED = 1???
' // force 32-bit size enum
%D3D10_CBF_FORCE_DWORD = &H7fffffff???

' enum D3D10_CBUFFER_TYPE
%D3D10_CT_CBUFFER = 0
%D3D10_CT_TBUFFER = 1

' enum D3D10_NAME
%D3D10_NAME_UNDEFINED = 0

' // Names meaningful to both HLSL and hardware
%D3D10_NAME_POSITION                      = 1
%D3D10_NAME_CLIP_DISTANCE                 = 2
%D3D10_NAME_CULL_DISTANCE                 = 3
%D3D10_NAME_RENDER_TARGET_ARRAY_INDEX     = 4
%D3D10_NAME_VIEWPORT_ARRAY_INDEX          = 5
%D3D10_NAME_VERTEX_ID                     = 6
%D3D10_NAME_PRIMITIVE_ID                  = 7
%D3D10_NAME_INSTANCE_ID                   = 8
%D3D10_NAME_IS_FRONT_FACE                 = 9
%D3D10_NAME_SAMPLE_INDEX                  = 10
%D3D11_NAME_FINAL_QUAD_EDGE_TESSFACTOR    = 11
%D3D11_NAME_FINAL_QUAD_INSIDE_TESSFACTOR  = 12
%D3D11_NAME_FINAL_TRI_EDGE_TESSFACTOR     = 13
%D3D11_NAME_FINAL_TRI_INSIDE_TESSFACTOR   = 14
%D3D11_NAME_FINAL_LINE_DETAIL_TESSFACTOR  = 15
%D3D11_NAME_FINAL_LINE_DENSITY_TESSFACTOR = 16

' // Names meaningful to HLSL only
%D3D10_NAME_TARGET              = 64
%D3D10_NAME_DEPTH               = 65
%D3D10_NAME_COVERAGE            = 66
%D3D11_NAME_DEPTH_GREATER_EQUAL = 67
%D3D11_NAME_DEPTH_LESS_EQUAL    = 68

' enum D3D10_RESOURCE_RETURN_TYPE
%D3D10_RETURN_TYPE_UNORM = 1
%D3D10_RETURN_TYPE_SNORM = 2
%D3D10_RETURN_TYPE_SINT  = 3
%D3D10_RETURN_TYPE_UINT  = 4
%D3D10_RETURN_TYPE_FLOAT = 5
%D3D10_RETURN_TYPE_MIXED = 6

' enum D3D10_REGISTER_COMPONENT_TYPE
%D3D10_REGISTER_COMPONENT_UNKNOWN = 0
%D3D10_REGISTER_COMPONENT_UINT32  = 1
%D3D10_REGISTER_COMPONENT_SINT32  = 2
%D3D10_REGISTER_COMPONENT_FLOAT32 = 3


'//----------------------------------------------------------------------------
'// D3D10_INCLUDE_TYPE:
'//----------------------------------------------------------------------------

' enum D3D10_INCLUDE_TYPE
%D3D10_INCLUDE_LOCAL  = 0???
%D3D10_INCLUDE_SYSTEM = 1???
' // force 32-bit size enum
%D3D10_INCLUDE_FORCE_DWORD = &H7fffffff???


'//----------------------------------------------------------------------------
'// ID3D10Include:
'// -------------
'// This interface is intended to be implemented by the application, and can
'// be used by various D3D10 APIs.  This enables application-specific handling
'// of #include directives in source files.
'//
'// Open()
'//    Opens an include file.  If successful, it should fill in ppData and
'//    pBytes.  The data pointer returned must remain valid until Close is
'//    subsequently called.  The name of the file is encoded in UTF-8 format.
'// Close()
'//    Closes an include file.  If Open was successful, Close is guaranteed
'//    to be called before the API using this interface returns.
'//----------------------------------------------------------------------------

'INTERFACE ID3D10Include $IID_ID3D10Include

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD Open ( _                                      ' VTable offset = 12
'     BYVAL IncludeType AS DWORD _                       ' __in  D3D10_INCLUDE_TYPE IncludeType
'   , BYREF pFileName AS ASCIIZ _                        ' __in  LPCSTR pFileName
'   , BYVAL pParentData AS DWORD _                       ' __in  LPCVOID pParentData
'   , BYREF ppData AS DWORD _                            ' __out LPCVOID *ppData
'   , BYREF pBytes AS DWORD _                            ' __out UINT *pBytes
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD Close ( _                                     ' VTable offset = 16
'     BYVAL pData AS DWORD _                             ' __in LPCVOID pData
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE

'//----------------------------------------------------------------------------
'// ID3D10ShaderReflection:
'//----------------------------------------------------------------------------

'//
'// Structure definitions
'//

' // Size = 112 bytes
TYPE D3D10_SHADER_DESC DWORD
   Version                     AS DWORD        ' UINT // Shader version
   Creator                     AS ASCIIZ PTR   ' LPCSTR // Creator string
   Flags                       AS DWORD        ' UINT // Shader compilation/parse flags

   ConstantBuffers             AS DWORD        ' UINT // Number of constant buffers
   BoundResources              AS DWORD        ' UINT // Number of bound resources
   InputParameters             AS DWORD        ' UINT // Number of parameters in the input signature
   OutputParameters            AS DWORD        ' UINT // Number of parameters in the output signature

   InstructionCount            AS DWORD        ' UINT // Number of emitted instructions
   TempRegisterCount           AS DWORD        ' UINT // Number of temporary registers used
   TempArrayCount              AS DWORD        ' UINT // Number of temporary arrays used
   DefCount                    AS DWORD        ' UINT // Number of constant defines
   DclCount                    AS DWORD        ' UINT // Number of declarations (input + output)
   TextureNormalInstructions   AS DWORD        ' UINT // Number of non-categorized texture instructions
   TextureLoadInstructions     AS DWORD        ' UINT // Number of texture load instructions
   TextureCompInstructions     AS DWORD        ' UINT // Number of texture comparison instructions
   TextureBiasInstructions     AS DWORD        ' UINT // Number of texture bias instructions
   TextureGradientInstructions AS DWORD        ' UINT // Number of texture gradient instructions
   FloatInstructionCount       AS DWORD        ' UINT // Number of floating point arithmetic instructions used
   IntInstructionCount         AS DWORD        ' UINT // Number of signed integer arithmetic instructions used
   UintInstructionCount        AS DWORD        ' UINT // Number of unsigned integer arithmetic instructions used
   StaticFlowControlCount      AS DWORD        ' UINT // Number of static flow control instructions used
   DynamicFlowControlCount     AS DWORD        ' UINT // Number of dynamic flow control instructions used
   MacroInstructionCount       AS DWORD        ' UINT // Number of macro instructions used
   ArrayInstructionCount       AS DWORD        ' UINT // Number of array instructions used
   CutInstructionCount         AS DWORD        ' UINT // Number of cut instructions used
   EmitInstructionCount        AS DWORD        ' UINT // Number of emit instructions used
   GSOutputTopology            AS DWORD        ' D3D10_PRIMITIVE_TOPOLOGY // Geometry shader output topology
   GSMaxOutputVertexCount      AS DWORD        ' UINT // Geometry shader maximum output vertex count
END TYPE

' // Size = 20 bytes
TYPE D3D10_SHADER_BUFFER_DESC DWORD
   Name      AS ASCIIZ PTR   ' LPCSTR // Name of the constant buffer
   Type      AS DWORD        ' D3D10_CBUFFER_TYPE // Indicates that this is a CBuffer or TBuffer
   Variables AS DWORD        ' UINT // Number of member variables
   Size      AS DWORD        ' UINT // Size of CB (in bytes)
   uFlags    AS DWORD        ' UINT // Buffer description flags
END TYPE

' // Size = 20 bytes
TYPE D3D10_SHADER_VARIABLE_DESC DWORD
   Name         AS ASCIIZ PTR   ' LPCSTR // Name of the variable
   StartOffset  AS DWORD        ' UINT // Offset in constant buffer's backing store
   Size         AS DWORD        ' UINT // Size of variable (in bytes)
   uFlags       AS DWORD        ' UINT // Variable flags
   DefaultValue AS DWORD        ' LPVOID // Raw pointer to default value
END TYPE

' // Size = 28 bytes
TYPE D3D10_SHADER_TYPE_DESC DWORD
   Class    AS DWORD   ' D3D10_SHADER_VARIABLE_CLASS // Variable class (e.g. object, matrix, etc.)
   Type     AS DWORD   ' D3D10_SHADER_VARIABLE_TYPE // Variable type (e.g. float, sampler, etc.)
   Rows     AS DWORD   ' UINT // Number of rows (for matrices, 1 for other numeric, 0 if not applicable)
   Columns  AS DWORD   ' UINT // Number of columns (for vectors & matrices, 1 for other numeric, 0 if not applicable)
   Elements AS DWORD   ' UINT // Number of elements (0 if not an array)
   Members  AS DWORD   ' UINT // Number of members (0 if not a structure)
   Offset   AS DWORD   ' UINT // Offset from the start of structure (0 if not a structure member)
END TYPE

' // Size = 32 bytes
TYPE D3D10_SHADER_INPUT_BIND_DESC DWORD
   Name       AS ASCIIZ PTR   ' LPCSTR // Name of the resource
   Type       AS DWORD        ' D3D10_SHADER_INPUT_TYPE // Type of resource (e.g. texture, cbuffer, etc.)
   BindPoint  AS DWORD        ' UINT // Starting bind point
   BindCount  AS DWORD        ' UINT // Number of contiguous bind points (for arrays)

   uFlags     AS DWORD        ' UINT // Input binding flags
   ReturnType AS DWORD        ' D3D10_RESOURCE_RETURN_TYPE // Return type (if texture)
   Dimension  AS DWORD        ' D3D10_SRV_DIMENSION // Dimension (if texture)
   NumSamples AS DWORD        ' UINT // Number of samples (0 if not MS texture)
END TYPE

' // Size = 24 bytes
TYPE D3D10_SIGNATURE_PARAMETER_DESC WORD
   SemanticName    AS ASCIIZ PTR   ' LPCSTR // Name of the semantic
   SemanticIndex   AS DWORD        ' UINT // Index of the semantic
   Register        AS DWORD        ' UINT // Number of member variables
   SystemValueType AS DWORD        ' D3D10_NAME // A predefined system value, or D3D10_NAME_UNDEFINED if not applicable
   ComponentType   AS DWORD        ' D3D10_REGISTER_COMPONENT_TYPE // Scalar type (e.g. uint, float, etc.)
   Mask            AS BYTE         ' BYTE // Mask to indicate which components of the register
                                   '      // are used (combination of D3D10_COMPONENT_MASK values)
   ReadWriteMask   AS BYTE         ' BYTE // Mask to indicate whether a given component is
                                   '      // never written (if this is an output signature) or
                                   '      // always read (if this is an input signature).
                                   '      // (combination of D3D10_COMPONENT_MASK values)
END TYPE

' Must be placed after D3D10_SIGNATURE_PARAMETER_DESC because D310Effect.inc uses it.
#INCLUDE ONCE "d3d10.inc"

'//
'// Interface definitions
'//

' ########################################################################################
' ID3D10ShaderReflectionType interface
' IID = C530AD7D-9B16-4395-A979-BA2ECFF83ADD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ID3D10ShaderReflectionType_INTERFACE_DEFINED)
    %ID3D10ShaderReflectionType_INTERFACE_DEFINED = 1

$IID_ID3D10ShaderReflectionType = GUID$("{C530AD7D-9B16-4395-A979-BA2ECFF83ADD}")

INTERFACE ID3D10ShaderReflectionType $IID_ID3D10ShaderReflectionType

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 12
     BYREF pDesc AS D3D10_SHADER_TYPE_DESC _            ' __out D3D10_SHADER_TYPE_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMemberTypeByIndex ( _                      ' VTable offset = 16
     BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS ID3D10ShaderReflectionType                      ' ID3D10ShaderReflectionType*
   ' =====================================================================================
   METHOD GetMemberTypeByName ( _                       ' VTable offset = 24
     BYREF Name AS ASCIIZ _                             ' __in LPCSTR Name
   ) AS ID3D10ShaderReflectionType                      ' ID3D10ShaderReflectionType*
   ' =====================================================================================
   METHOD GetMemberTypeName ( _                         ' VTable offset = 28
     BYREF Index AS DWORD _                             ' __in UINT Index
   ) AS DWORD                                           ' LPCSTR
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IID_ID3D10ShaderReflectionType_INTERFACE_DEFINED__ */


' ########################################################################################
' ID3D10ShaderReflectionVariable interface
' IID = 1BF63C95-2650-405D-99C1-3636BD1DA0A1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ID3D10ShaderReflectionVariable_INTERFACE_DEFINED)
    %ID3D10ShaderReflectionVariable_INTERFACE_DEFINED = 1

$IID_ID3D10ShaderReflectionVariable = GUID$("{1BF63C95-2650-405D-99C1-3636BD1DA0A1}")

INTERFACE ID3D10ShaderReflectionVariable $IID_ID3D10ShaderReflectionVariable

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 12
     BYREF pDesc AS D3D10_SHADER_TYPE_DESC _            ' __out D3D10_SHADER_TYPE_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 16
   ) AS ID3D10ShaderReflectionType                      ' ID3D10ShaderReflectionType*
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IID_ID3D10ShaderReflectionVariable_INTERFACE_DEFINED__ */


' ########################################################################################
' ID3D10ShaderReflectionConstantBuffer interface
' IID = 66C66A94-DDDD-4B62-A66A-F0DA33C2B4D0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ID3D10ShaderReflectionConstantBuffer_INTERFACE_DEFINED)
    %ID3D10ShaderReflectionConstantBuffer_INTERFACE_DEFINED = 1

$IID_ID3D10ShaderReflectionConstantBuffer = GUID$("{66C66A94-DDDD-4B62-A66A-F0DA33C2B4D0}")

INTERFACE ID3D10ShaderReflectionConstantBuffer $IID_ID3D10ShaderReflectionConstantBuffer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 12
     BYREF pDesc AS D3D10_SHADER_TYPE_DESC _            ' __out D3D10_SHADER_TYPE_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVariableByIndex ( _                        ' VTable offset = 16
     BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS ID3D10ShaderReflectionVariable                  ' ID3D10ShaderReflectionVariable*
   ' =====================================================================================
   METHOD GetVariableByName ( _                         ' VTable offset = 16
     BYREF Name AS ASCIIZ _                             ' __in LPCSTR Name
   ) AS ID3D10ShaderReflectionVariable                  ' ID3D10ShaderReflectionVariable*
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IID_ID3D10ShaderReflectionConstantBuffer_INTERFACE_DEFINED__ */


' ########################################################################################
' ID3D10ShaderReflection interface
' IID = D40E20B6-F8F7-42AD-AB20-4BAF8F15DFAA
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ID3D10ShaderReflection_INTERFACE_DEFINED)
    %ID3D10ShaderReflection_INTERFACE_DEFINED = 1

$IID_ID3D10ShaderReflection = GUID$("{D40E20B6-F8F7-42AD-AB20-4BAF8F15DFAA}")

INTERFACE ID3D10ShaderReflection $IID_ID3D10ShaderReflection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 12
     BYREF pDesc AS D3D10_SHADER_TYPE_DESC _            ' __out D3D10_SHADER_TYPE_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConstantBufferByIndex ( _                  ' VTable offset = 16
     BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS ID3D10ShaderReflectionConstantBuffer            ' ID3D10ShaderReflectionConstantBuffer*
   ' =====================================================================================
   METHOD GetConstantBufferByName ( _                   ' VTable offset = 20
     BYREF Name AS ASCIIZ _                             ' __in LPCSTR Name
   ) AS ID3D10ShaderReflectionConstantBuffer            ' ID3D10ShaderReflectionConstantBuffer*
   ' =====================================================================================
   METHOD GetResourceBindingDesc ( _                    ' VTable offset = 24
     BYVAL ResourceIndex AS DWORD _                     ' __in  UINT ResourceIndex
   , BYREF pDesc AS D3D10_SHADER_INPUT_BIND_DESC _      ' __out D3D10_SHADER_INPUT_BIND_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputParameterDesc ( _                     ' VTable offset = 28
     BYVAL ParameterIndex AS DWORD _                    ' __in  UINT ParameterIndex
   , BYREF pDesc AS D3D10_SIGNATURE_PARAMETER_DESC _    ' __out D3D10_SIGNATURE_PARAMETER_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputParameterDesc ( _                    ' VTable offset = 32
     BYVAL ParameterIndex AS DWORD _                    ' __in  UINT ParameterIndex
   , BYREF pDesc AS D3D10_SIGNATURE_PARAMETER_DESC _    ' __out D3D10_SIGNATURE_PARAMETER_DESC *pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IID_ID3D10ShaderReflection_INTERFACE_DEFINED__ */

'//////////////////////////////////////////////////////////////////////////////
'// APIs //////////////////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

'//----------------------------------------------------------------------------
'// D3D10CompileShader:
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
'//      Instruction set to be used when generating code.  The D3D10 entry
'//      point currently supports only "vs_4_0", "ps_4_0", and "gs_4_0".
'//  Flags
'//      See D3D10_SHADER_xxx flags.
'//  ppShader
'//      Returns a buffer containing the created shader.  This buffer contains
'//      the compiled shader code, as well as any embedded debug and symbol
'//      table info.  (See D3D10GetShaderConstantTable)
'//  ppErrorMsgs
'//      Returns a buffer containing a listing of errors and warnings that were
'//      encountered during the compile.  If you are running in a debugger,
'//      these are the same messages you will see in your debug output.
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3D10CompileShader IMPORT "D3D10.DLL" ALIAS "D3D10CompileShader" ( _
   BYREF pSrcData AS ASCIIZ _                           ' __in  LPCSTR pSrcData
 , BYVAL SrcDataLen AS DWORD _                          ' __in  SIZE_T SrcDataLen
 , BYREF pFileName AS ASCIIZ _                          ' __in  LPCSTR pFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO *pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3D10INCLUDE *pInclude
 , BYREF pFunctionName AS ASCIIZ _                      ' __in  LPCSTR pFunctionName
 , BYREF pProfile AS ASCIIZ _                           ' __in  LPCSTR pProfile
 , BYVAL Flags AS DWORD _                               ' __in  UINT Flags
 , BYREF ppShader AS ID3D10Blob _                       ' __out ID3D10Blob **ppShader
 , BYREF ppErrorMsgs AS ID3D10Blob _                    ' __out ID3D10Blob **ppErrorMsgs
 ) AS LONG                                              ' HRESULT

'//----------------------------------------------------------------------------
'// D3D10DisassembleShader:
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

DECLARE FUNCTION D3D10DisassembleShader IMPORT "D3D10.DLL" ALIAS "D3D10DisassembleShader" ( _
   BYVAL pShader AS DWORD _                             ' __in  CONST void *pShader
 , BYVAL BytecodeLength AS DWORD _                      ' __in  SIZE_T BytecodeLength
 , BYVAL EnableColorCode AS LONG _                      ' __in  BOOL EnableColorCode
 , BYREF pComments AS ASCIIZ _                          ' __in  LPCSTR pComments
 , BYREF ppDisassembly AS ID3D10Blob _                  ' __out ID3D10Blob **ppDisassembly
 ) AS LONG                                              ' HRESULT


'//----------------------------------------------------------------------------
'// D3D10GetPixelShaderProfile/D3D10GetVertexShaderProfile/D3D10GetGeometryShaderProfile:
'// -----------------------------------------------------
'// Returns the name of the HLSL profile best suited to a given device.
'//
'// Parameters:
'//  pDevice
'//      Pointer to the device in question
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3D10GetPixelShaderProfile IMPORT "D3D10.DLL" ALIAS "D3D10GetPixelShaderProfile" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in ID3D10Device *pDevice
 ) AS DWORD                                             ' LPCSTR

DECLARE FUNCTION D3D10GetVertexShaderProfile IMPORT "D3D10.DLL" ALIAS "D3D10GetVertexShaderProfile" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in ID3D10Device *pDevice
 ) AS DWORD                                             ' LPCSTR

DECLARE FUNCTION D3D10GetGeometryShaderProfile IMPORT "D3D10.DLL" ALIAS "D3D10GetGeometryShaderProfile" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in ID3D10Device *pDevice
 ) AS DWORD                                             ' LPCSTR

'//----------------------------------------------------------------------------
'// D3D10ReflectShader:
'// ------------------
'// Creates a shader reflection object that can be used to retrieve information
'// about a compiled shader
'//
'// Parameters:
'//  pShaderBytecode
'//      Pointer to a compiled shader (same pointer that is passed into
'//      ID3D10Device::CreateShader)
'//  BytecodeLength
'//      Length of the shader bytecode buffer
'//  ppReflector
'//      [out] Returns a ID3D10ShaderReflection object that can be used to
'//      retrieve shader resource and constant buffer information
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3D10ReflectShader IMPORT "D3D10.DLL" ALIAS "D3D10ReflectShader" ( _
   BYVAL pShaderBytecode AS DWORD _                     ' __in  CONST void *pShaderBytecode
 , BYVAL BytecodeLength AS DWORD _                      ' __in  SIZE_T BytecodeLength
 , BYREF ppReflector AS ID3D10ShaderReflection _        ' __out ID3D10ShaderReflection **ppReflector
 ) AS LONG                                              ' HRESULT

'//----------------------------------------------------------------------------
'// D3D10PreprocessShader
'// ---------------------
'// Creates a shader reflection object that can be used to retrieve information
'// about a compiled shader
'//
'// Parameters:
'//  pSrcData
'//      Pointer to source code
'//  SrcDataLen
'//      Size of source code, in bytes
'//  pFileName
'//      Source file name (used for error output)
'//  pDefines
'//      Optional NULL-terminated array of preprocessor macro definitions.
'//  pInclude
'//      Optional interface pointer to use for handling #include directives.
'//      If this parameter is NULL, #includes will be honored when assembling
'//      from file, and will error when assembling from resource or memory.
'//  ppShaderText
'//      Returns a buffer containing a single large string that represents
'//      the resulting formatted token stream
'//  ppErrorMsgs
'//      Returns a buffer containing a listing of errors and warnings that were
'//      encountered during assembly.  If you are running in a debugger,
'//      these are the same messages you will see in your debug output.
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3D10PreprocessShader IMPORT "D3D10.DLL" ALIAS "D3D10PreprocessShader" ( _
   BYREF pSrcData AS ASCIIZ _                           ' __in  LPCSTR pSrcData
 , BYVAL SrcDataSize AS DWORD _                         ' __in  SIZE_T SrcDataSize
 , BYREF pFileName AS ASCIIZ _                          ' __in  LPCSTR pFileName
 , BYREF pDefines AS D3D10_SHADER_MACRO _               ' __in  CONST D3D10_SHADER_MACRO *pDefines
 , BYVAL pInclude AS IUnknown _                         ' __in  LPD3D10INCLUDE *pInclude
 , BYREF ppShaderText AS ID3D10Blob _                   ' __out ID3D10Blob **ppShaderText
 , BYREF ppErrorMsgs AS ID3D10Blob _                    ' __out ID3D10Blob **ppErrorMsgs
 ) AS LONG                                              ' HRESULT

'//////////////////////////////////////////////////////////////////////////
'//
'// Shader blob manipulation routines
'// ---------------------------------
'//
'// void *pShaderBytecode - a buffer containing the result of an HLSL
'//  compilation.  Typically this opaque buffer contains several
'//  discrete sections including the shader executable code, the input
'//  signature, and the output signature.  This can typically be retrieved
'//  by calling ID3D10Blob::GetBufferPointer() on the returned blob
'//  from HLSL's compile APIs.
'//
'// UINT BytecodeLength - the length of pShaderBytecode.  This can
'//  typically be retrieved by calling ID3D10Blob::GetBufferSize()
'//  on the returned blob from HLSL's compile APIs.
'//
'// ID3D10Blob **ppSignatureBlob(s) - a newly created buffer that
'//  contains only the signature portions of the original bytecode.
'//  This is a copy; the original bytecode is not modified.  You may
'//  specify NULL for this parameter to have the bytecode validated
'//  for the presence of the corresponding signatures without actually
'//  copying them and creating a new blob.
'//
'// Returns E_INVALIDARG if any required parameters are NULL
'// Returns E_FAIL is the bytecode is corrupt or missing signatures
'// Returns S_OK on success
'//
'//////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION D3D10GetInputSignatureBlob IMPORT "D3D10.DLL" ALIAS "D3D10GetInputSignatureBlob" ( _
   BYVAL pShaderBytecode AS DWORD _                     ' __in  CONST void *pShaderBytecode
 , BYVAL BytecodeLength AS DWORD _                      ' __in  SIZE_T BytecodeLength
 , BYREF ppSignatureBlob AS ID3D10Blob _                ' __out ID3D10Blob **ppSignatureBlob
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3D10GetOutputSignatureBlob IMPORT "D3D10.DLL" ALIAS "D3D10GetOutputSignatureBlob" ( _
   BYVAL pShaderBytecode AS DWORD _                     ' __in  CONST void *pShaderBytecode
 , BYVAL BytecodeLength AS DWORD _                      ' __in  SIZE_T BytecodeLength
 , BYREF ppSignatureBlob AS ID3D10Blob _                ' __out ID3D10Blob **ppSignatureBlob
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3D10GetInputAndOutputSignatureBlob IMPORT "D3D10.DLL" ALIAS "D3D10GetInputAndOutputSignatureBlob" ( _
   BYVAL pShaderBytecode AS DWORD _                     ' __in  CONST void *pShaderBytecode
 , BYVAL BytecodeLength AS DWORD _                      ' __in  SIZE_T BytecodeLength
 , BYREF ppSignatureBlob AS ID3D10Blob _                ' __out ID3D10Blob **ppSignatureBlob
 ) AS LONG                                              ' HRESULT

'//----------------------------------------------------------------------------
'// D3D10GetShaderDebugInfo:
'// -----------------------
'// Gets shader debug info.  Debug info is generated by D3D10CompileShader and is
'// embedded in the body of the shader.
'//
'// Parameters:
'//  pShaderBytecode
'//      Pointer to the function bytecode
'//  BytecodeLength
'//      Length of the shader bytecode buffer
'//  ppDebugInfo
'//      Buffer used to return debug info.  For information about the layout
'//      of this buffer, see definition of D3D10_SHADER_DEBUG_INFO above.
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3D10GetShaderDebugInfo IMPORT "D3D10.DLL" ALIAS "D3D10GetShaderDebugInfo" ( _
   BYVAL pShaderBytecode AS DWORD _                     ' __in  CONST void *pShaderBytecode
 , BYVAL BytecodeLength AS DWORD _                      ' __in  SIZE_T BytecodeLength
 , BYREF ppDebugInfo AS ID3D10Blob _                    ' __out ID3D10Blob **ppDebugInfo
 ) AS LONG                                              ' HRESULT
