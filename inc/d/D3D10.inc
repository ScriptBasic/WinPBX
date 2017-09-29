' ########################################################################################
' Microsoft Windows
' File: D3D10.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3D10_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "dxgi.inc"

$IID_ID3D10DeviceChild        = GUID$("{9B7E4C00-342C-4106-A19F-4F2704F689F0}")
$IID_ID3D10DepthStencilState  = GUID$("{2B4B1CC8-A4AD-41F8-8322-CA86FC3EC675}")
$IID_ID3D10BlendState         = GUID$("{EDAD8D19-8A35-4D6D-8566-2EA276CDE161}")
$IID_ID3D10RasterizerState    = GUID$("{A2A07292-89AF-4345-BE2E-C53D9FBB6E9F}")
$IID_ID3D10Resource           = GUID$("{9B7E4C01-342C-4106-A19F-4F2704F689F0}")
$IID_ID3D10Buffer             = GUID$("{9B7E4C02-342C-4106-A19F-4F2704F689F0}")
$IID_ID3D10Texture1D          = GUID$("{9B7E4C03-342C-4106-A19F-4F2704F689F0}")
$IID_ID3D10Texture2D          = GUID$("{9B7E4C04-342C-4106-A19F-4F2704F689F0}")
$IID_ID3D10Texture3D          = GUID$("{9B7E4C05-342C-4106-A19F-4F2704F689F0}")
$IID_ID3D10View               = GUID$("{C902B03F-60A7-49BA-9936-2A3AB37A7E33}")
$IID_ID3D10ShaderResourceView = GUID$("{9B7E4C07-342C-4106-A19F-4F2704F689F0}")
$IID_ID3D10RenderTargetView   = GUID$("{9B7E4C08-342C-4106-A19F-4F2704F689F0}")
$IID_ID3D10DepthStencilView   = GUID$("{9B7E4C09-342C-4106-A19F-4F2704F689F0}")
$IID_ID3D10VertexShader       = GUID$("{9B7E4C0A-342C-4106-A19F-4F2704F689F0}")
$IID_ID3D10GeometryShader     = GUID$("{6316BE88-54CD-4040-AB44-20461BC81F68}")
$IID_ID3D10PixelShader        = GUID$("{4968B601-9D00-4CDE-8346-8E7F675819B6}")
$IID_ID3D10InputLayout        = GUID$("{9B7E4C0B-342C-4106-A19F-4F2704F689F0}")
$IID_ID3D10SamplerState       = GUID$("{9B7E4C0C-342C-4106-A19F-4F2704F689F0}")
$IID_ID3D10Asynchronous       = GUID$("{9B7E4C0D-342C-4106-A19F-4F2704F689F0}")
$IID_ID3D10Query              = GUID$("{9B7E4C0E-342C-4106-A19F-4F2704F689F0}")
$IID_ID3D10Predicate          = GUID$("{9B7E4C10-342C-4106-A19F-4F2704F689F0}")
$IID_ID3D10Counter            = GUID$("{9B7E4C11-342C-4106-A19F-4F2704F689F0}")
$IID_ID3D10Device             = GUID$("{9B7E4C0F-342C-4106-A19F-4F2704F689F0}")
$IID_ID3D10Multithread        = GUID$("{9B7E4E00-342C-4106-A19F-4F2704F689F0}")

#IF NOT %DEF(%D3D10_CONSTANTS)
    %D3D10_CONSTANTS = 1

%D3D10_16BIT_INDEX_STRIP_CUT_VALUE                                    = &Hffff??
%D3D10_32BIT_INDEX_STRIP_CUT_VALUE                                    = &Hffffffff???
%D3D10_8BIT_INDEX_STRIP_CUT_VALUE                                     = &Hff?
%D3D10_ARRAY_AXIS_ADDRESS_RANGE_BIT_COUNT                             = 9
%D3D10_CLIP_OR_CULL_DISTANCE_COUNT                                    = 8
%D3D10_CLIP_OR_CULL_DISTANCE_ELEMENT_COUNT                            = 2
%D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT                    = 14
%D3D10_COMMONSHADER_CONSTANT_BUFFER_COMPONENTS                        = 4
%D3D10_COMMONSHADER_CONSTANT_BUFFER_COMPONENT_BIT_COUNT               = 32
%D3D10_COMMONSHADER_CONSTANT_BUFFER_HW_SLOT_COUNT                     = 15
%D3D10_COMMONSHADER_CONSTANT_BUFFER_REGISTER_COMPONENTS               = 4
%D3D10_COMMONSHADER_CONSTANT_BUFFER_REGISTER_COUNT                    = 15
%D3D10_COMMONSHADER_CONSTANT_BUFFER_REGISTER_READS_PER_INST           = 1
%D3D10_COMMONSHADER_CONSTANT_BUFFER_REGISTER_READ_PORTS               = 1
%D3D10_COMMONSHADER_FLOWCONTROL_NESTING_LIMIT                         = 64
%D3D10_COMMONSHADER_IMMEDIATE_CONSTANT_BUFFER_REGISTER_COMPONENTS     = 4
%D3D10_COMMONSHADER_IMMEDIATE_CONSTANT_BUFFER_REGISTER_COUNT          = 1
%D3D10_COMMONSHADER_IMMEDIATE_CONSTANT_BUFFER_REGISTER_READS_PER_INST = 1
%D3D10_COMMONSHADER_IMMEDIATE_CONSTANT_BUFFER_REGISTER_READ_PORTS     = 1
%D3D10_COMMONSHADER_IMMEDIATE_VALUE_COMPONENT_BIT_COUNT               = 32
%D3D10_COMMONSHADER_INPUT_RESOURCE_REGISTER_COMPONENTS                = 1
%D3D10_COMMONSHADER_INPUT_RESOURCE_REGISTER_COUNT                     = 128
%D3D10_COMMONSHADER_INPUT_RESOURCE_REGISTER_READS_PER_INST            = 1
%D3D10_COMMONSHADER_INPUT_RESOURCE_REGISTER_READ_PORTS                = 1
%D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT                         = 128
%D3D10_COMMONSHADER_SAMPLER_REGISTER_COMPONENTS                       = 1
%D3D10_COMMONSHADER_SAMPLER_REGISTER_COUNT                            = 16
%D3D10_COMMONSHADER_SAMPLER_REGISTER_READS_PER_INST                   = 1
%D3D10_COMMONSHADER_SAMPLER_REGISTER_READ_PORTS                       = 1
%D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT                                = 16
%D3D10_COMMONSHADER_SUBROUTINE_NESTING_LIMIT                          = 32
%D3D10_COMMONSHADER_TEMP_REGISTER_COMPONENTS                          = 4
%D3D10_COMMONSHADER_TEMP_REGISTER_COMPONENT_BIT_COUNT                 = 32
%D3D10_COMMONSHADER_TEMP_REGISTER_COUNT                               = 4096
%D3D10_COMMONSHADER_TEMP_REGISTER_READS_PER_INST                      = 3
%D3D10_COMMONSHADER_TEMP_REGISTER_READ_PORTS                          = 3
%D3D10_COMMONSHADER_TEXCOORD_RANGE_REDUCTION_MAX                      = 10
%D3D10_COMMONSHADER_TEXCOORD_RANGE_REDUCTION_MIN                      = -10
%D3D10_COMMONSHADER_TEXEL_OFFSET_MAX_NEGATIVE                         = -8
%D3D10_COMMONSHADER_TEXEL_OFFSET_MAX_POSITIVE                         = 7

MACRO D3D10_DEFAULT_BLEND_FACTOR_ALPHA     = 1.0!
MACRO D3D10_DEFAULT_BLEND_FACTOR_BLUE      = 1.0!
MACRO D3D10_DEFAULT_BLEND_FACTOR_GREEN     = 1.0!
MACRO D3D10_DEFAULT_BLEND_FACTOR_RED       = 1.0!
MACRO D3D10_DEFAULT_BORDER_COLOR_COMPONENT = 0.0!
%D3D10_DEFAULT_DEPTH_BIAS = 0

MACRO D3D10_DEFAULT_DEPTH_BIAS_CLAMP = 0.0!
MACRO D3D10_DEFAULT_MAX_ANISOTROPY   = 16.0!
MACRO D3D10_DEFAULT_MIP_LOD_BIAS     = 0.0!
%D3D10_DEFAULT_RENDER_TARGET_ARRAY_INDEX = 0

%D3D10_DEFAULT_SAMPLE_MASK    = &Hffffffff???
%D3D10_DEFAULT_SCISSOR_ENDX   = 0
%D3D10_DEFAULT_SCISSOR_ENDY   = 0
%D3D10_DEFAULT_SCISSOR_STARTX = 0
%D3D10_DEFAULT_SCISSOR_STARTY = 0

MACRO D3D10_DEFAULT_SLOPE_SCALED_DEPTH_BIAS   = 0.0!
%D3D10_DEFAULT_STENCIL_READ_MASK              = &Hff
%D3D10_DEFAULT_STENCIL_REFERENCE              = 0
%D3D10_DEFAULT_STENCIL_WRITE_MASK             = &Hff
%D3D10_DEFAULT_VIEWPORT_AND_SCISSORRECT_INDEX = 0
%D3D10_DEFAULT_VIEWPORT_HEIGHT                = 0

MACRO D3D10_DEFAULT_VIEWPORT_MAX_DEPTH = 0.0!
MACRO D3D10_DEFAULT_VIEWPORT_MIN_DEPTH = 0.0!
%D3D10_DEFAULT_VIEWPORT_TOPLEFTX = 0
%D3D10_DEFAULT_VIEWPORT_TOPLEFTY = 0
%D3D10_DEFAULT_VIEWPORT_WIDTH    = 0

MACRO D3D10_FLOAT16_FUSED_TOLERANCE_IN_ULP      = 0.6!
MACRO D3D10_FLOAT32_MAX                         = 3.402823466e+38!
MACRO D3D10_FLOAT32_TO_INTEGER_TOLERANCE_IN_ULP = 0.6!
MACRO D3D10_FLOAT_TO_SRGB_EXPONENT_DENOMINATOR  = 2.4!
MACRO D3D10_FLOAT_TO_SRGB_EXPONENT_NUMERATOR    = 1.0!
MACRO D3D10_FLOAT_TO_SRGB_OFFSET                = 0.055!
MACRO D3D10_FLOAT_TO_SRGB_SCALE_1               = 12.92!
MACRO D3D10_FLOAT_TO_SRGB_SCALE_2               = 1.055!
MACRO D3D10_FLOAT_TO_SRGB_THRESHOLD             = 0.0031308!
MACRO D3D10_FTOI_INSTRUCTION_MAX_INPUT          = 2147483647.999!
MACRO D3D10_FTOI_INSTRUCTION_MIN_INPUT          = -2147483648.999!
MACRO D3D10_FTOU_INSTRUCTION_MAX_INPUT          = 4294967295.999!
MACRO D3D10_FTOU_INSTRUCTION_MIN_INPUT          = 0.0!
%D3D10_GS_INPUT_PRIM_CONST_REGISTER_COMPONENTS  = 1

%D3D10_GS_INPUT_PRIM_CONST_REGISTER_COMPONENT_BIT_COUNT = 32
%D3D10_GS_INPUT_PRIM_CONST_REGISTER_COUNT               = 1
%D3D10_GS_INPUT_PRIM_CONST_REGISTER_READS_PER_INST      = 2
%D3D10_GS_INPUT_PRIM_CONST_REGISTER_READ_PORTS          = 1
%D3D10_GS_INPUT_REGISTER_COMPONENTS                     = 4
%D3D10_GS_INPUT_REGISTER_COMPONENT_BIT_COUNT            = 32
%D3D10_GS_INPUT_REGISTER_COUNT                          = 16
%D3D10_GS_INPUT_REGISTER_READS_PER_INST                 = 2
%D3D10_GS_INPUT_REGISTER_READ_PORTS                     = 1
%D3D10_GS_INPUT_REGISTER_VERTICES                       = 6
%D3D10_GS_OUTPUT_ELEMENTS                               = 32
%D3D10_GS_OUTPUT_REGISTER_COMPONENTS                    = 4
%D3D10_GS_OUTPUT_REGISTER_COMPONENT_BIT_COUNT           = 32
%D3D10_GS_OUTPUT_REGISTER_COUNT                         = 32
%D3D10_IA_DEFAULT_INDEX_BUFFER_OFFSET_IN_BYTES          = 0
%D3D10_IA_DEFAULT_PRIMITIVE_TOPOLOGY                    = 0
%D3D10_IA_DEFAULT_VERTEX_BUFFER_OFFSET_IN_BYTES         = 0
%D3D10_IA_INDEX_INPUT_RESOURCE_SLOT_COUNT               = 1
%D3D10_IA_INSTANCE_ID_BIT_COUNT                         = 32
%D3D10_IA_INTEGER_ARITHMETIC_BIT_COUNT                  = 32
%D3D10_IA_PRIMITIVE_ID_BIT_COUNT                        = 32
%D3D10_IA_VERTEX_ID_BIT_COUNT                           = 32
%D3D10_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT              = 16
%D3D10_IA_VERTEX_INPUT_STRUCTURE_ELEMENTS_COMPONENTS    = 64
%D3D10_IA_VERTEX_INPUT_STRUCTURE_ELEMENT_COUNT          = 16
%D3D10_INTEGER_DIVIDE_BY_ZERO_QUOTIENT   = &Hffffffff???
%D3D10_INTEGER_DIVIDE_BY_ZERO_REMAINDER  = &Hffffffff???

MACRO D3D10_LINEAR_GAMMA               = 1.0!
MACRO D3D10_MAX_BORDER_COLOR_COMPONENT = 1.0!
MACRO D3D10_MAX_DEPTH                  = 1.0!
%D3D10_MAX_MAXANISOTROPY   = 16

%D3D10_MAX_MULTISAMPLE_SAMPLE_COUNT   = 32

MACRO D3D10_MAX_POSITION_VALUE   = 3.402823466e+34!
%D3D10_MAX_TEXTURE_DIMENSION_2_TO_EXP   = 17

MACRO D3D10_MIN_BORDER_COLOR_COMPONENT = 0.0!
MACRO D3D10_MIN_DEPTH                  = 0.0!
%D3D10_MIN_MAXANISOTROPY   = 0

MACRO D3D10_MIP_LOD_BIAS_MAX = 15.99!
MACRO D3D10_MIP_LOD_BIAS_MIN = -16.0!
%D3D10_MIP_LOD_FRACTIONAL_BIT_COUNT   = 6

%D3D10_MIP_LOD_RANGE_BIT_COUNT   = 8

MACRO D3D10_MULTISAMPLE_ANTIALIAS_LINE_WIDTH = 1.4!
%D3D10_NONSAMPLE_FETCH_OUT_OF_RANGE_ACCESS_RESULT = 0

%D3D10_PIXEL_ADDRESS_RANGE_BIT_COUNT             = 13
%D3D10_PRE_SCISSOR_PIXEL_ADDRESS_RANGE_BIT_COUNT = 15
%D3D10_PS_FRONTFACING_DEFAULT_VALUE              = &Hffffffff???
%D3D10_PS_FRONTFACING_FALSE_VALUE                = 0
%D3D10_PS_FRONTFACING_TRUE_VALUE                 = &Hffffffff???
%D3D10_PS_INPUT_REGISTER_COMPONENTS              = 4
%D3D10_PS_INPUT_REGISTER_COMPONENT_BIT_COUNT     = 32
%D3D10_PS_INPUT_REGISTER_COUNT                   = 32
%D3D10_PS_INPUT_REGISTER_READS_PER_INST          = 2
%D3D10_PS_INPUT_REGISTER_READ_PORTS              = 1

MACRO D3D10_PS_LEGACY_PIXEL_CENTER_FRACTIONAL_COMPONENT = 0.0!
%D3D10_PS_OUTPUT_DEPTH_REGISTER_COMPONENTS          = 1
%D3D10_PS_OUTPUT_DEPTH_REGISTER_COMPONENT_BIT_COUNT = 32
%D3D10_PS_OUTPUT_DEPTH_REGISTER_COUNT               = 1
%D3D10_PS_OUTPUT_REGISTER_COMPONENTS                = 4
%D3D10_PS_OUTPUT_REGISTER_COMPONENT_BIT_COUNT       = 32
%D3D10_PS_OUTPUT_REGISTER_COUNT                     = 8

MACRO D3D10_PS_PIXEL_CENTER_FRACTIONAL_COMPONENT       = 0.5!
%D3D10_REQ_BLEND_OBJECT_COUNT_PER_CONTEXT              = 4096
%D3D10_REQ_BUFFER_RESOURCE_TEXEL_COUNT_2_TO_EXP        = 27
%D3D10_REQ_CONSTANT_BUFFER_ELEMENT_COUNT               = 4096
%D3D10_REQ_DEPTH_STENCIL_OBJECT_COUNT_PER_CONTEXT      = 4096
%D3D10_REQ_DRAWINDEXED_INDEX_COUNT_2_TO_EXP            = 32
%D3D10_REQ_DRAW_VERTEX_COUNT_2_TO_EXP                  = 32
%D3D10_REQ_FILTERING_HW_ADDRESSABLE_RESOURCE_DIMENSION = 8192
%D3D10_REQ_GS_INVOCATION_32BIT_OUTPUT_COMPONENT_LIMIT  = 1024
%D3D10_REQ_IMMEDIATE_CONSTANT_BUFFER_ELEMENT_COUNT     = 4096
%D3D10_REQ_MAXANISOTROPY                               = 16
%D3D10_REQ_MIP_LEVELS                                  = 14
%D3D10_REQ_MULTI_ELEMENT_STRUCTURE_SIZE_IN_BYTES       = 2048
%D3D10_REQ_RASTERIZER_OBJECT_COUNT_PER_CONTEXT         = 4096
%D3D10_REQ_RENDER_TO_BUFFER_WINDOW_WIDTH               = 8192
%D3D10_REQ_RESOURCE_SIZE_IN_MEGABYTES                  = 128
%D3D10_REQ_RESOURCE_VIEW_COUNT_PER_CONTEXT_2_TO_EXP    = 20
%D3D10_REQ_SAMPLER_OBJECT_COUNT_PER_CONTEXT            = 4096
%D3D10_REQ_TEXTURE1D_ARRAY_AXIS_DIMENSION              = 512
%D3D10_REQ_TEXTURE1D_U_DIMENSION                       = 8192
%D3D10_REQ_TEXTURE2D_ARRAY_AXIS_DIMENSION              = 512
%D3D10_REQ_TEXTURE2D_U_OR_V_DIMENSION                  = 8192
%D3D10_REQ_TEXTURE3D_U_V_OR_W_DIMENSION                = 2048
%D3D10_REQ_TEXTURECUBE_DIMENSION                       = 8192
%D3D10_RESINFO_INSTRUCTION_MISSING_COMPONENT_RETVAL    = 0
%D3D10_SHADER_MAJOR_VERSION                            = 4
%D3D10_SHADER_MINOR_VERSION                            = 0
%D3D10_SHIFT_INSTRUCTION_PAD_VALUE                     = 0
%D3D10_SHIFT_INSTRUCTION_SHIFT_VALUE_BIT_COUNT         = 5
%D3D10_SIMULTANEOUS_RENDER_TARGET_COUNT                = 8
%D3D10_SO_BUFFER_MAX_STRIDE_IN_BYTES                   = 2048
%D3D10_SO_BUFFER_MAX_WRITE_WINDOW_IN_BYTES             = 256
%D3D10_SO_BUFFER_SLOT_COUNT                            = 4
%D3D10_SO_DDI_REGISTER_INDEX_DENOTING_GAP              = &Hffffffff???
%D3D10_SO_MULTIPLE_BUFFER_ELEMENTS_PER_BUFFER          = 1
%D3D10_SO_SINGLE_BUFFER_COMPONENT_LIMIT                = 64

MACRO D3D10_SRGB_GAMMA                     = 2.2!
MACRO D3D10_SRGB_TO_FLOAT_DENOMINATOR_1    = 12.92!
MACRO D3D10_SRGB_TO_FLOAT_DENOMINATOR_2    = 1.055!
MACRO D3D10_SRGB_TO_FLOAT_EXPONENT         = 2.4!
MACRO D3D10_SRGB_TO_FLOAT_OFFSET           = 0.055!
MACRO D3D10_SRGB_TO_FLOAT_THRESHOLD        = 0.04045!
MACRO D3D10_SRGB_TO_FLOAT_TOLERANCE_IN_ULP = 0.5!
%D3D10_STANDARD_COMPONENT_BIT_COUNT        = 32

%D3D10_STANDARD_COMPONENT_BIT_COUNT_DOUBLED               = 64
%D3D10_STANDARD_MAXIMUM_ELEMENT_ALIGNMENT_BYTE_MULTIPLE   = 4
%D3D10_STANDARD_PIXEL_COMPONENT_COUNT                     = 128
%D3D10_STANDARD_PIXEL_ELEMENT_COUNT                       = 32
%D3D10_STANDARD_VECTOR_SIZE                               = 4
%D3D10_STANDARD_VERTEX_ELEMENT_COUNT                      = 16
%D3D10_STANDARD_VERTEX_TOTAL_COMPONENT_COUNT              = 64
%D3D10_SUBPIXEL_FRACTIONAL_BIT_COUNT                      = 8
%D3D10_SUBTEXEL_FRACTIONAL_BIT_COUNT                      = 6
%D3D10_TEXEL_ADDRESS_RANGE_BIT_COUNT                      = 18
%D3D10_UNBOUND_MEMORY_ACCESS_RESULT                       = 0
%D3D10_VIEWPORT_AND_SCISSORRECT_MAX_INDEX                 = 15
%D3D10_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE = 16
%D3D10_VIEWPORT_BOUNDS_MAX                                = 16383
%D3D10_VIEWPORT_BOUNDS_MIN                                = -16384
%D3D10_VS_INPUT_REGISTER_COMPONENTS                       = 4
%D3D10_VS_INPUT_REGISTER_COMPONENT_BIT_COUNT              = 32
%D3D10_VS_INPUT_REGISTER_COUNT                            = 16
%D3D10_VS_INPUT_REGISTER_READS_PER_INST                   = 2
%D3D10_VS_INPUT_REGISTER_READ_PORTS                       = 1
%D3D10_VS_OUTPUT_REGISTER_COMPONENTS                      = 4
%D3D10_VS_OUTPUT_REGISTER_COMPONENT_BIT_COUNT             = 32
%D3D10_VS_OUTPUT_REGISTER_COUNT                           = 16
%D3D10_WHQL_CONTEXT_COUNT_FOR_RESOURCE_LIMIT              = 10
%D3D10_WHQL_DRAWINDEXED_INDEX_COUNT_2_TO_EXP              = 25
%D3D10_WHQL_DRAW_VERTEX_COUNT_2_TO_EXP                    = 25

%D3D_MAJOR_VERSION   = 10
%D3D_MINOR_VERSION   = 0
%D3D_SPEC_DATE_DAY   = 8
%D3D_SPEC_DATE_MONTH = 8
%D3D_SPEC_DATE_YEAR  = 2006

MACRO D3D_SPEC_VERSION = 1.050005

#ENDIF   ' #IF NOT %DEF(%D3D10_CONSTANTS)

'#if !defined( __d3d10_1_h__ ) && !(D3D10_HEADER_MINOR_VERSION >= 1)
#IF NOT %DEF(%D3D10_1_INC)
%D3D10_1_IA_VERTEX_INPUT_STRUCTURE_ELEMENT_COUNT = %D3D10_IA_VERTEX_INPUT_STRUCTURE_ELEMENT_COUNT
%D3D10_1_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT = %D3D10_IA_VERTEX_INPUT_STRUCTURE_ELEMENT_COUNT
#ENDIF

%FACD3D10 = &H879

%FACD3D10DEBUG = %FACD3D10 + 1

'#define MAKE_D3D10_HRESULT( code )  MAKE_HRESULT( 1, _FACD3D10, code )
MACRO MAKE_D3D10_HRESULT(ncode) = MAKE_HRESULT(1, %FACD3D10, ncode)
'#define MAKE_D3D10_STATUS( code )    MAKE_HRESULT( 0, _FACD3D10, code )
MACRO MAKE_D3D10_STATUS(ncode) = MAKE_HRESULT(0, %FACD3D10, ncode)
%D3D10_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS = &H88790001&
'#define D3D10_ERROR_FILE_NOT_FOUND  MAKE_D3D10_HRESULT(2)
%D3D10_ERROR_FILE_NOT_FOUND = &H88790002&

'#if __SAL_H_FULL_VER < 140050727
'#undef __in_range
'#undef __in_xcount_opt
'    %in_range(x, y)
'    %in_xcount_opt(x)
'#endif

' enum D3D10_INPUT_CLASSIFICATION
%D3D10_INPUT_PER_VERTEX_DATA   = 0
%D3D10_INPUT_PER_INSTANCE_DATA = 1

%D3D10_APPEND_ALIGNED_ELEMENT = &Hffffffff???

' // Size = 28 bytes
TYPE D3D10_INPUT_ELEMENT_DESC DWORD
   SemanticName         AS ASCIIZ PTR   ' LPCSTR
   SemanticIndex        AS DWORD        ' UINT
   Format               AS DWORD        ' DXGI_FORMAT enum
   InputSlot            AS DWORD        ' UINT
   AlignedByteOffset    AS DWORD        ' UINT
   InputSlotClass       AS DWORD        ' D3D10_INPUT_CLASSIFICATION enum
   InstanceDataStepRate AS DWORD        ' UINT
END TYPE

' enum D3D10_FILL_MODE
%D3D10_FILL_WIREFRAME = 2
%D3D10_FILL_SOLID     = 3

' enum D3D10_PRIMITIVE_TOPOLOGY
%D3D10_PRIMITIVE_TOPOLOGY_UNDEFINED         = 0
%D3D10_PRIMITIVE_TOPOLOGY_POINTLIST         = 1
%D3D10_PRIMITIVE_TOPOLOGY_LINELIST          = 2
%D3D10_PRIMITIVE_TOPOLOGY_LINESTRIP         = 3
%D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST      = 4
%D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP     = 5
%D3D10_PRIMITIVE_TOPOLOGY_LINELIST_ADJ      = 10
%D3D10_PRIMITIVE_TOPOLOGY_LINESTRIP_ADJ     = 11
%D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST_ADJ  = 12
%D3D10_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP_ADJ = 13

' enum D3D10_PRIMITIVE
%D3D10_PRIMITIVE_UNDEFINED    = 0
%D3D10_PRIMITIVE_POINT        = 1
%D3D10_PRIMITIVE_LINE         = 2
%D3D10_PRIMITIVE_TRIANGLE     = 3
%D3D10_PRIMITIVE_LINE_ADJ     = 6
%D3D10_PRIMITIVE_TRIANGLE_ADJ = 7

' enum D3D10_CULL_MODE
%D3D10_CULL_NONE  = 1
%D3D10_CULL_FRONT = 2
%D3D10_CULL_BACK  = 3

' // Size = 12 bytes
TYPE D3D10_SO_DECLARATION_ENTRY BYTE
   SemanticName   AS ASCIIZ PTR   ' LPCSTR
   SemanticIndex  AS DWORD        ' UINT
   StartComponent AS BYTE         ' BYTE
   ComponentCount AS BYTE         ' BYTE
   OutputSlot     AS BYTE         ' BYTE
   filler_        AS BYTE         ' // TO keep alignment
END TYPE

' // Size = 24 bytes
TYPE D3D10_VIEWPORT DWORD
   TopLeftX AS LONG     ' INT
   TopLeftY AS LONG     ' INT
   Width    AS DWORD    ' UINT
   Height   AS DWORD    ' UINT
   MinDepth AS SINGLE   ' FLOAT
   MaxDepth AS SINGLE   ' FLOAT
END TYPE

' enum D3D10_RESOURCE_DIMENSION
%D3D10_RESOURCE_DIMENSION_UNKNOWN   = 0
%D3D10_RESOURCE_DIMENSION_BUFFER    = 1
%D3D10_RESOURCE_DIMENSION_TEXTURE1D = 2
%D3D10_RESOURCE_DIMENSION_TEXTURE2D = 3
%D3D10_RESOURCE_DIMENSION_TEXTURE3D = 4

' enum %D3D10_SRV_DIMENSION
%D3D10_SRV_DIMENSION_UNKNOWN          = 0
%D3D10_SRV_DIMENSION_BUFFER           = 1
%D3D10_SRV_DIMENSION_TEXTURE1D        = 2
%D3D10_SRV_DIMENSION_TEXTURE1DARRAY   = 3
%D3D10_SRV_DIMENSION_TEXTURE2D        = 4
%D3D10_SRV_DIMENSION_TEXTURE2DARRAY   = 5
%D3D10_SRV_DIMENSION_TEXTURE2DMS      = 6
%D3D10_SRV_DIMENSION_TEXTURE2DMSARRAY = 7
%D3D10_SRV_DIMENSION_TEXTURE3D        = 8
%D3D10_SRV_DIMENSION_TEXTURECUBE      = 9

' enum D3D10_DSV_DIMENSION
%D3D10_DSV_DIMENSION_UNKNOWN          = 0
%D3D10_DSV_DIMENSION_TEXTURE1D        = 1
%D3D10_DSV_DIMENSION_TEXTURE1DARRAY   = 2
%D3D10_DSV_DIMENSION_TEXTURE2D        = 3
%D3D10_DSV_DIMENSION_TEXTURE2DARRAY   = 4
%D3D10_DSV_DIMENSION_TEXTURE2DMS      = 5
%D3D10_DSV_DIMENSION_TEXTURE2DMSARRAY = 6

' enum D3D10_RTV_DIMENSION
%D3D10_RTV_DIMENSION_UNKNOWN          = 0
%D3D10_RTV_DIMENSION_BUFFER           = 1
%D3D10_RTV_DIMENSION_TEXTURE1D        = 2
%D3D10_RTV_DIMENSION_TEXTURE1DARRAY   = 3
%D3D10_RTV_DIMENSION_TEXTURE2D        = 4
%D3D10_RTV_DIMENSION_TEXTURE2DARRAY   = 5
%D3D10_RTV_DIMENSION_TEXTURE2DMS      = 6
%D3D10_RTV_DIMENSION_TEXTURE2DMSARRAY = 7
%D3D10_RTV_DIMENSION_TEXTURE3D        = 8

' enum D3D10_USAGE
%D3D10_USAGE_DEFAULT   = 0
%D3D10_USAGE_IMMUTABLE = 1
%D3D10_USAGE_DYNAMIC   = 2
%D3D10_USAGE_STAGING   = 3

' enum D3D10_BIND_FLAG
%D3D10_BIND_VERTEX_BUFFER   = &H1???
%D3D10_BIND_INDEX_BUFFER    = &H2???
%D3D10_BIND_CONSTANT_BUFFER = &H4???
%D3D10_BIND_SHADER_RESOURCE = &H8???
%D3D10_BIND_STREAM_OUTPUT   = &H10???
%D3D10_BIND_RENDER_TARGET   = &H20???
%D3D10_BIND_DEPTH_STENCIL   = &H40???

' enum D3D10_CPU_ACCESS_FLAG
%D3D10_CPU_ACCESS_WRITE = &H10000???
%D3D10_CPU_ACCESS_READ  = &H20000???

' enum D3D10_RESOURCE_MISC_FLAG
%D3D10_RESOURCE_MISC_GENERATE_MIPS     = &H1???
%D3D10_RESOURCE_MISC_SHARED            = &H2???
%D3D10_RESOURCE_MISC_TEXTURECUBE       = &H4???
%D3D10_RESOURCE_MISC_SHARED_KEYEDMUTEX = &H10???
%D3D10_RESOURCE_MISC_GDI_COMPATIBLE    = &H20???

' enum D3D10_MAP
%D3D10_MAP_READ               = 1
%D3D10_MAP_WRITE              = 2
%D3D10_MAP_READ_WRITE         = 3
%D3D10_MAP_WRITE_DISCARD      = 4
%D3D10_MAP_WRITE_NO_OVERWRITE = 5

' enum D3D10_MAP_FLAG
%D3D10_MAP_FLAG_DO_NOT_WAIT = &H100000???

' enum D3D10_RAISE_FLAG
%D3D10_RAISE_FLAG_DRIVER_INTERNAL_ERROR = &H1???

' enum D3D10_CLEAR_FLAG
%D3D10_CLEAR_DEPTH   = &H1???
%D3D10_CLEAR_STENCIL = &H2???

'typedef RECT D3D10_RECT;
MACRO D3D10_RECT = RECT

' // Size = 24 bytes
TYPE D3D10_BOX DWORD
   left   AS DWORD   ' UINT
   top    AS DWORD   ' UINT
   front  AS DWORD   ' UINT
   right  AS DWORD   ' UINT
   bottom AS DWORD   ' UINT
   back   AS DWORD   ' UINT
END TYPE

' ########################################################################################
' ID3D10DeviceChild interface
' IID = 9B7E4C00-342C-4106-A19F-4F2704F689F0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ID3D10DeviceChild_INTERFACE_DEFINED)
    %ID3D10DeviceChild_INTERFACE_DEFINED = 1

INTERFACE ID3D10DeviceChild $IID_ID3D10DeviceChild

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS ID3D10Device _                   ' __out  ID3D10Device **ppDevice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 16
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF pDataSize AS DWORD _                         ' __inout  UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out_bcount_opt(*pDataSize) void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 20
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in_bcount_opt(DataSize)  const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYVAL pData AS IUnknown _                          ' __in_opt  const IUnknown *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10DeviceChild_INTERFACE_DEFINED__ */


' enum D3D10_COMPARISON_FUNC
%D3D10_COMPARISON_NEVER         = 1
%D3D10_COMPARISON_LESS          = 2
%D3D10_COMPARISON_EQUAL         = 3
%D3D10_COMPARISON_LESS_EQUAL    = 4
%D3D10_COMPARISON_GREATER       = 5
%D3D10_COMPARISON_NOT_EQUAL     = 6
%D3D10_COMPARISON_GREATER_EQUAL = 7
%D3D10_COMPARISON_ALWAYS        = 8

' enum D3D10_DEPTH_WRITE_MASK
%D3D10_DEPTH_WRITE_MASK_ZERO = 0
%D3D10_DEPTH_WRITE_MASK_ALL  = 1

' enum D3D10_STENCIL_OP
%D3D10_STENCIL_OP_KEEP     = 1
%D3D10_STENCIL_OP_ZERO     = 2
%D3D10_STENCIL_OP_REPLACE  = 3
%D3D10_STENCIL_OP_INCR_SAT = 4
%D3D10_STENCIL_OP_DECR_SAT = 5
%D3D10_STENCIL_OP_INVERT   = 6
%D3D10_STENCIL_OP_INCR     = 7
%D3D10_STENCIL_OP_DECR     = 8

' // Size = 16 bytes
TYPE D3D10_DEPTH_STENCILOP_DESC DWORD
   StencilFailOp      AS DWORD   ' D3D10_STENCIL_OP enum
   StencilDepthFailOp AS DWORD   ' D3D10_STENCIL_OP enum
   StencilPassOp      AS DWORD   ' D3D10_STENCIL_OP enum
   StencilFunc        AS DWORD   ' D3D10_COMPARISON_FUNC enum
END TYPE

' // Size = 52 bytes
TYPE D3D10_DEPTH_STENCIL_DESC WORD
   DepthEnable      AS LONG    ' BOOL
   DepthWriteMask   AS DWORD   ' D3D10_DEPTH_WRITE_MASK enum
   DepthFunc        AS DWORD   ' D3D10_COMPARISON_FUNC enum
   StencilEnable    AS LONG    ' BOOL
   StencilReadMask  AS BYTE    ' UINT8
   StencilWriteMask AS BYTE    ' UINT8
   FrontFace        AS D3D10_DEPTH_STENCILOP_DESC
   BackFace         AS D3D10_DEPTH_STENCILOP_DESC
END TYPE

' ########################################################################################
' ID3D10DepthStencilState interface
' IID = 2B4B1CC8-A4AD-41F8-8322-CA86FC3EC675
' Inherited interface = ID3D10DeviceChild
' ########################################################################################

#IF NOT %DEF(%ID3D10DepthStencilState_INTERFACE_DEFINED)
    %ID3D10DepthStencilState_INTERFACE_DEFINED = 1

INTERFACE ID3D10DepthStencilState $IID_ID3D10DepthStencilState

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3D10DeviceChild Methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS ID3D10Device _                   ' __out  ID3D10Device **ppDevice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 16
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF pDataSize AS DWORD _                         ' __inout  UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out_bcount_opt(*pDataSize)  void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 20
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in_bcount_opt(DataSize)  const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYVAL pData AS IUnknown _                          ' __in_opt  const IUnknown *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10DepthStencilState Method
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 28
     BYREF pDesc AS D3D10_DEPTH_STENCIL_DESC _          ' __out  D3D10_DEPTH_STENCIL_DESC *pDesc
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10DepthStencilState_INTERFACE_DEFINED__ */

' enum D3D10_BLEND
%D3D10_BLEND_ZERO             = 1
%D3D10_BLEND_ONE              = 2
%D3D10_BLEND_SRC_COLOR        = 3
%D3D10_BLEND_INV_SRC_COLOR    = 4
%D3D10_BLEND_SRC_ALPHA        = 5
%D3D10_BLEND_INV_SRC_ALPHA    = 6
%D3D10_BLEND_DEST_ALPHA       = 7
%D3D10_BLEND_INV_DEST_ALPHA   = 8
%D3D10_BLEND_DEST_COLOR       = 9
%D3D10_BLEND_INV_DEST_COLOR   = 10
%D3D10_BLEND_SRC_ALPHA_SAT    = 11
%D3D10_BLEND_BLEND_FACTOR     = 14
%D3D10_BLEND_INV_BLEND_FACTOR = 15
%D3D10_BLEND_SRC1_COLOR       = 16
%D3D10_BLEND_INV_SRC1_COLOR   = 17
%D3D10_BLEND_SRC1_ALPHA       = 18
%D3D10_BLEND_INV_SRC1_ALPHA   = 19

' enum D3D10_BLEND_OP
%D3D10_BLEND_OP_ADD          = 1
%D3D10_BLEND_OP_SUBTRACT     = 2
%D3D10_BLEND_OP_REV_SUBTRACT = 3
%D3D10_BLEND_OP_MIN          = 4
%D3D10_BLEND_OP_MAX          = 5

' enum D3D10_COLOR_WRITE_ENABLE
%D3D10_COLOR_WRITE_ENABLE_RED   = 1
%D3D10_COLOR_WRITE_ENABLE_GREEN = 2
%D3D10_COLOR_WRITE_ENABLE_BLUE  = 4
%D3D10_COLOR_WRITE_ENABLE_ALPHA = 8
%D3D10_COLOR_WRITE_ENABLE_ALL   = (((%D3D10_COLOR_WRITE_ENABLE_RED OR %D3D10_COLOR_WRITE_ENABLE_GREEN) OR %D3D10_COLOR_WRITE_ENABLE_BLUE ) OR %D3D10_COLOR_WRITE_ENABLE_ALPHA)

' // Size = 68 bytes
TYPE D3D10_BLEND_DESC DWORD
   AlphaToCoverageEnable    AS LONG    ' BOOL
   BlendEnable(7)           AS LONG    ' BOOL
   SrcBlend                 AS DWORD   ' D3D10_BLEND enum
   DestBlend                AS DWORD   ' D3D10_BLEND enum
   BlendOp                  AS DWORD   ' D3D10_BLEND_OP enum
   SrcBlendAlpha            AS DWORD   ' D3D10_BLEND enum
   DestBlendAlpha           AS DWORD   ' D3D10_BLEND enum
   BlendOpAlpha             AS DWORD   ' D3D10_BLEND_OP enum
   RenderTargetWriteMask(7) AS BYTE    ' UINT8
END TYPE


' ########################################################################################
' ID3D10BlendState interface
' IID = EDAD8D19-8A35-4D6D-8566-2EA276CDE161
' Inherited interface = ID3D10DeviceChild
' ########################################################################################

#IF NOT %DEF(%ID3D10BlendState_INTERFACE_DEFINED)
    %ID3D10BlendState_INTERFACE_DEFINED = 1

INTERFACE ID3D10BlendState $IID_ID3D10BlendState

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3D10DeviceChild Methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS ID3D10Device _                   ' __out  ID3D10Device **ppDevice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 16
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF pDataSize AS DWORD _                         ' __inout  UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out_bcount_opt(*pDataSize)  void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 20
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in_bcount_opt(DataSize)  const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYVAL pData AS IUnknown _                          ' __in_opt  const IUnknown *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10BlendState Method
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 28
     BYREF pDesc AS D3D10_BLEND_DESC _                  ' __out  D3D10_BLEND_DESC *pDesc
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10BlendState_INTERFACE_DEFINED__ */


' // Size = 40 bytes
TYPE D3D10_RASTERIZER_DESC DWORD
   FillMode              AS DWORD    ' D3D10_FILL_MODE enum
   CullMode              AS DWORD    ' D3D10_CULL_MODE enum
   FrontCounterClockwise AS LONG     ' BOOL
   DepthBias             AS LONG     ' INT
   DepthBiasClamp        AS SINGLE   ' FLOAT
   SlopeScaledDepthBias  AS SINGLE   ' FLOAT
   DepthClipEnable       AS LONG     ' BOOL
   ScissorEnable         AS LONG     ' BOOL
   MultisampleEnable     AS LONG     ' BOOL
   AntialiasedLineEnable AS LONG     ' BOOL
END TYPE

' ########################################################################################
' ID3D10RasterizerState interface
' IID = A2A07292-89AF-4345-BE2E-C53D9FBB6E9F
' Inherited interface = ID3D10DeviceChild
' ########################################################################################

#IF NOT %DEF(%ID3D10RasterizerState_INTERFACE_DEFINED)
    %ID3D10RasterizerState_INTERFACE_DEFINED = 1

INTERFACE ID3D10RasterizerState $IID_ID3D10RasterizerState

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3D10DeviceChild Methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS ID3D10Device _                   ' __out  ID3D10Device **ppDevice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 16
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF pDataSize AS DWORD _                         ' __inout  UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out_bcount_opt(*pDataSize)  void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 20
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in_bcount_opt(DataSize)  const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYVAL pData AS IUnknown _                          ' __in_opt  const IUnknown *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10RasterizerState Method
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 28
     BYREF pDesc AS D3D10_RASTERIZER_DESC _             ' __out  D3D10_RASTERIZER_DESC *pDesc
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10RasterizerState_INTERFACE_DEFINED__ */

'#if !defined( D3D10_NO_HELPERS ) && defined( __cplusplus )
'inline UINT D3D10CalcSubresource( UINT MipSlice, UINT ArraySlice, UINT MipLevels )
'{ return MipSlice + ArraySlice * MipLevels; }
FUNCTION D3D10CalcSubresource (BYVAL MipSlice AS DWORD, BYVAL ArraySlice AS DWORD, BYVAL MipLevels AS DWORD) AS DWORD
   FUNCTION = MipSlice + ArraySlice * MipLevels
END FUNCTION
'#endif

' // Size = 12 bytes
TYPE D3D10_SUBRESOURCE_DATA DWORD
   pSysMem          AS DWORD   ' const void *
   SysMemPitch      AS DWORD   ' UINT
   SysMemSlicePitch AS DWORD   ' UINT
END TYPE

' ########################################################################################
' ID3D10Resource interface
' IID = 9B7E4C01-342C-4106-A19F-4F2704F689F0
' Inherited interface = ID3D10DeviceChild
' ########################################################################################

#IF NOT %DEF(%ID3D10Resource_INTERFACE_DEFINED)
    %ID3D10Resource_INTERFACE_DEFINED = 1

INTERFACE ID3D10Resource $IID_ID3D10Resource

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3D10DeviceChild Methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS ID3D10Device _                   ' __out  ID3D10Device **ppDevice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 16
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF pDataSize AS DWORD _                         ' __inout  UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out_bcount_opt(*pDataSize)  void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 20
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in_bcount_opt(DataSize)  const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYVAL pData AS IUnknown _                          ' __in_opt  const IUnknown *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10Resource Methods
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 28
     BYREF rType AS DWORD _                             ' __out  D3D10_RESOURCE_DIMENSION *rType
   )                                                    ' void
   ' =====================================================================================
   METHOD SetEvictionPriority ( _                       ' VTable offset = 32
     BYVAL EvictionPriority AS DWORD _                  ' __in  UINT EvictionPriority
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEvictionPriority ( _                       ' VTable offset = 36
   ) AS DWORD                                           ' UINT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10Resource_INTERFACE_DEFINED__ */


' // Size = 20 bytes
TYPE D3D10_BUFFER_DESC DWORD
   ByteWidth      AS DWORD   ' UINT
   Usage          AS DWORD   ' D3D10_USAGE enum
   BindFlags      AS DWORD   ' UINT
   CPUAccessFlags AS DWORD   ' UINT
   MiscFlags      AS DWORD   ' UINT
END TYPE

' ########################################################################################
' ID3D10Buffer interface
' IID = 9B7E4C02-342C-4106-A19F-4F2704F689F0
' Inherited interface = ID3D10Resource
' ########################################################################################

#IF NOT %DEF(%ID3D10Buffer_INTERFACE_DEFINED)
    %ID3D10Buffer_INTERFACE_DEFINED = 1

INTERFACE ID3D10Buffer $IID_ID3D10Buffer

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3D10DeviceChild Methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS ID3D10Device _                   ' __out  ID3D10Device **ppDevice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 16
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF pDataSize AS DWORD _                         ' __inout  UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out_bcount_opt(*pDataSize)  void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 20
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in_bcount_opt(DataSize)  const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYVAL pData AS IUnknown _                          ' __in_opt  const IUnknown *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10Resource Methods
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 28
     BYREF rType AS DWORD _                             ' __out  D3D10_RESOURCE_DIMENSION *rType
   )                                                    ' void
   ' =====================================================================================
   METHOD SetEvictionPriority ( _                       ' VTable offset = 32
     BYVAL EvictionPriority AS DWORD _                  ' __in  UINT EvictionPriority
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEvictionPriority ( _                       ' VTable offset = 36
   ) AS DWORD                                           ' UINT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10Buffer Methods
   ' =====================================================================================
   METHOD Map ( _                                       ' VTable offset = 40
     BYVAL MapType AS DWORD _                           ' __in  D3D10_MAP MapType
   , BYVAL MapFlags AS DWORD _                          ' __in  UINT MapFlags
   , BYREF ppData AS DWORD _                            ' __out  void **ppData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unmap ( _                                     ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 48
     BYREF pDesc AS D3D10_BUFFER_DESC _                 ' __out  D3D10_BUFFER_DESC *pDesc
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10Buffer_INTERFACE_DEFINED__ */

' // Size = 32 bytes
TYPE D3D10_TEXTURE1D_DESC DWORD
   Width          AS DWORD   ' UINT
   MipLevels      AS DWORD   ' UINT
   ArraySize      AS DWORD   ' UINT
   Format         AS DWORD   ' DXGI_FORMAT enum
   Usage          AS DWORD   ' D3D10_USAGE
   BindFlags      AS DWORD   ' UINT
   CPUAccessFlags AS DWORD   ' UINT
   MiscFlags      AS DWORD   ' UINT
END TYPE

' ########################################################################################
' ID3D10Texture1D interface
' IID = 9B7E4C03-342C-4106-A19F-4F2704F689F0
' Inherited interface = ID3D10Resource
' ########################################################################################

#IF NOT %DEF(%ID3D10Texture1D_INTERFACE_DEFINED)
    %ID3D10Texture1D_INTERFACE_DEFINED = 1

INTERFACE ID3D10Texture1D $IID_ID3D10Texture1D

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3D10DeviceChild Methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS ID3D10Device _                   ' __out  ID3D10Device **ppDevice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 16
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF pDataSize AS DWORD _                         ' __inout  UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out_bcount_opt(*pDataSize)  void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 20
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in_bcount_opt(DataSize)  const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYVAL pData AS IUnknown _                          ' __in_opt  const IUnknown *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10Resource Methods
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 28
     BYREF rType AS DWORD _                             ' __out  D3D10_RESOURCE_DIMENSION *rType
   )                                                    ' void
   ' =====================================================================================
   METHOD SetEvictionPriority ( _                       ' VTable offset = 32
     BYVAL EvictionPriority AS DWORD _                  ' __in  UINT EvictionPriority
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEvictionPriority ( _                       ' VTable offset = 36
   ) AS DWORD                                           ' UINT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10Texture1D Methods
   ' =====================================================================================
   METHOD Map ( _                                       ' VTable offset = 40
     BYVAL Subresource AS DWORD _                       ' __in  UINT Subresource
   , BYVAL MapType AS DWORD _                           ' __in  D3D10_MAP MapType
   , BYVAL MapFlags AS DWORD _                          ' __in  UINT MapFlags
   , BYREF ppData AS DWORD _                            ' __out  void **ppData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unmap ( _                                     ' VTable offset = 44
     BYVAL Subresource AS DWORD _                       ' __in  UINT Subresource
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 48
     BYREF pDesc AS D3D10_TEXTURE1D_DESC _              ' __out  D3D10_TEXTURE1D_DESC *pDesc
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10Texture1D_INTERFACE_DEFINED__ */


' // Size = 44 bytes
TYPE D3D10_TEXTURE2D_DESC DWORD
   Width          AS DWORD              ' UINT
   Height         AS DWORD              ' UINT
   MipLevels      AS DWORD              ' UINT
   ArraySize      AS DWORD              ' UINT
   Format         AS DWORD              ' DXGI_FORMAT enum
   SampleDesc     AS DXGI_SAMPLE_DESC
   Usage          AS DWORD              ' D3D10_USAGE enum
   BindFlags      AS DWORD              ' UINT
   CPUAccessFlags AS DWORD              ' UINT
   MiscFlags      AS DWORD              ' UINT
END TYPE

' // Size = 8 bytes
TYPE D3D10_MAPPED_TEXTURE2D DWORD
   pData    AS DWORD   ' void *
   RowPitch AS DWORD   ' UINT
END TYPE

' ########################################################################################
' ID3D10Texture2D interface
' IID = 9B7E4C04-342C-4106-A19F-4F2704F689F0
' Inherited interface = ID3D10Resource
' ########################################################################################

#IF NOT %DEF(%ID3D10Texture2D_INTERFACE_DEFINED)
    %ID3D10Texture2D_INTERFACE_DEFINED = 1

INTERFACE ID3D10Texture2D $IID_ID3D10Texture2D

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3D10DeviceChild Methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS ID3D10Device _                   ' __out  ID3D10Device **ppDevice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 16
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF pDataSize AS DWORD _                         ' __inout  UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out_bcount_opt(*pDataSize)  void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 20
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in_bcount_opt(DataSize)  const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYVAL pData AS IUnknown _                          ' __in_opt  const IUnknown *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10Resource Methods
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 28
     BYREF rType AS DWORD _                             ' __out  D3D10_RESOURCE_DIMENSION *rType
   )                                                    ' void
   ' =====================================================================================
   METHOD SetEvictionPriority ( _                       ' VTable offset = 32
     BYVAL EvictionPriority AS DWORD _                  ' __in  UINT EvictionPriority
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEvictionPriority ( _                       ' VTable offset = 36
   ) AS DWORD                                           ' UINT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10Texture2D Methods
   ' =====================================================================================
   METHOD Map ( _                                       ' VTable offset = 40
     BYVAL Subresource AS DWORD _                       ' __in  UINT Subresource
   , BYVAL MapType AS DWORD _                           ' __in  D3D10_MAP MapType
   , BYVAL MapFlags AS DWORD _                          ' __in  UINT MapFlags
   , BYREF pMappedTex2D AS D3D10_MAPPED_TEXTURE2D _     ' __out  D3D10_MAPPED_TEXTURE2D *pMappedTex2D
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unmap ( _                                     ' VTable offset = 44
     BYVAL Subresource AS DWORD _                       ' __in  UINT Subresource
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 48
     BYREF pDesc AS D3D10_TEXTURE2D_DESC _              ' __out  D3D10_TEXTURE2D_DESC *pDesc
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10Texture2D_INTERFACE_DEFINED__ */


' // Size = 36 bytes
TYPE D3D10_TEXTURE3D_DESC DWORD
   Width          AS DWORD   ' UINT
   Height         AS DWORD   ' UINT
   Depth          AS DWORD   ' UINT
   MipLevels      AS DWORD   ' UINT
   Format         AS DWORD   ' DXGI_FORMAT enum
   Usage          AS DWORD   ' D3D10_USAGE
   BindFlags      AS DWORD   ' UINT
   CPUAccessFlags AS DWORD   ' UINT
   MiscFlags      AS DWORD   ' UINT
END TYPE

' // Size = 12 bytes
TYPE D3D10_MAPPED_TEXTURE3D DWORD
   pData      AS DWORD   ' void *
   RowPitch   AS DWORD   ' UINT
   DepthPitch AS DWORD   ' UINT
END TYPE

' ########################################################################################
' ID3D10Texture3D interface
' IID = 9B7E4C05-342C-4106-A19F-4F2704F689F0
' Inherited interface = ID3D10Resource
' ########################################################################################

#IF NOT %DEF(%ID3D10Texture3D_INTERFACE_DEFINED)
    %ID3D10Texture3D_INTERFACE_DEFINED = 1

INTERFACE ID3D10Texture3D $IID_ID3D10Texture3D

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3D10DeviceChild Methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS ID3D10Device _                   ' __out  ID3D10Device **ppDevice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 16
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF pDataSize AS DWORD _                         ' __inout  UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out_bcount_opt(*pDataSize)  void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 20
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in_bcount_opt(DataSize)  const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYVAL pData AS IUnknown _                          ' __in_opt  const IUnknown *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10Resource Methods
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 28
     BYREF rType AS DWORD _                             ' __out  D3D10_RESOURCE_DIMENSION *rType
   )                                                    ' void
   ' =====================================================================================
   METHOD SetEvictionPriority ( _                       ' VTable offset = 32
     BYVAL EvictionPriority AS DWORD _                  ' __in  UINT EvictionPriority
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEvictionPriority ( _                       ' VTable offset = 36
   ) AS DWORD                                           ' UINT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10Texture3D Methods
   ' =====================================================================================
   METHOD Map ( _                                       ' VTable offset = 40
     BYVAL Subresource AS DWORD _                       ' __in  UINT Subresource
   , BYVAL MapType AS DWORD _                           ' __in  D3D10_MAP MapType
   , BYVAL MapFlags AS DWORD _                          ' __in  UINT MapFlags
   , BYREF pMappedTex3D AS D3D10_MAPPED_TEXTURE3D _     ' __out  D3D10_MAPPED_TEXTURE3D *pMappedTex3D
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unmap ( _                                     ' VTable offset = 44
     BYVAL Subresource AS DWORD _                       ' __in  UINT Subresource
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 48
     BYREF pDesc AS D3D10_TEXTURE3D_DESC _              ' __out  D3D10_TEXTURE3D_DESC *pDesc
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10Texture3D_INTERFACE_DEFINED__ */


' enum D3D10_TEXTURECUBE_FACE
%D3D10_TEXTURECUBE_FACE_POSITIVE_X = 0
%D3D10_TEXTURECUBE_FACE_NEGATIVE_X = 1
%D3D10_TEXTURECUBE_FACE_POSITIVE_Y = 2
%D3D10_TEXTURECUBE_FACE_NEGATIVE_Y = 3
%D3D10_TEXTURECUBE_FACE_POSITIVE_Z = 4
%D3D10_TEXTURECUBE_FACE_NEGATIVE_Z = 5

' ########################################################################################
' ID3D10View interface
' IID = C902B03F-60A7-49BA-9936-2A3AB37A7E33
' Inherited interface = ID3D10DeviceChild
' ########################################################################################

#IF NOT %DEF(%ID3D10View_INTERFACE_DEFINED)
    %ID3D10View_INTERFACE_DEFINED = 1

INTERFACE ID3D10View $IID_ID3D10View

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3D10DeviceChild Methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS ID3D10Device _                   ' __out  ID3D10Device **ppDevice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 16
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF pDataSize AS DWORD _                         ' __inout  UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out_bcount_opt(*pDataSize)  void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 20
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in_bcount_opt(DataSize)  const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYVAL pData AS IUnknown _                          ' __in_opt  const IUnknown *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10View Method
   ' =====================================================================================
   METHOD GetResource ( _                               ' VTable offset = 28
     BYREF ppResource AS ID3D10Resource _               ' __out  ID3D10Resource **ppResource
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10View_INTERFACE_DEFINED__ */

' // Size = 4 bytes
UNION D3D10_BUFFER_SRV_UNION1 DWORD
   FirstElement  AS DWORD   ' UINT
   ElementOffset AS DWORD   ' UINT
END UNION

' // Size = 4 bytes
UNION D3D10_BUFFER_SRV_UNION2 DWORD
   NumElements  AS DWORD    ' UINT
   ElementWidth AS DWORD    ' UINT
END UNION

' // Size = 8 bytes
TYPE D3D10_BUFFER_SRV DWORD
   D3D10_BUFFER_SRV_UNION1
   D3D10_BUFFER_SRV_UNION2
END TYPE

' // Size = 8 bytes
TYPE D3D10_TEX1D_SRV DWORD
   MostDetailedMip AS DWORD   ' UINT
   MipLevels       AS DWORD   ' UINT
END TYPE

' // Size = 16 bytes
TYPE D3D10_TEX1D_ARRAY_SRV DWORD
   MostDetailedMip AS DWORD   ' UINT
   MipLevels       AS DWORD   ' UINT
   FirstArraySlice AS DWORD   ' UINT
   ArraySize       AS DWORD   ' UINT
END TYPE

' // Size = 8 bytes
TYPE D3D10_TEX2D_SRV DWORD
   MostDetailedMip AS DWORD   ' UINT
   MipLevels       AS DWORD   ' UINT
END TYPE

' // Size = 16 bytes
TYPE D3D10_TEX2D_ARRAY_SRV DWORD
   MostDetailedMip AS DWORD   ' UINT
   MipLevels       AS DWORD   ' UINT
   FirstArraySlice AS DWORD   ' UINT
   ArraySize       AS DWORD   ' UINT
END TYPE

' // Size = 8 bytes
TYPE D3D10_TEX3D_SRV DWORD
   MostDetailedMip AS DWORD   ' UINT
   MipLevels       AS DWORD   ' UINT
END TYPE

' // Size = 8 bytes
TYPE D3D10_TEXCUBE_SRV DWORD
   MostDetailedMip AS DWORD   ' UINT
   MipLevels       AS DWORD   ' UINT
END TYPE

' // Size = 4 bytes
TYPE D3D10_TEX2DMS_SRV DWORD
   UnusedField_NothingToDefine AS DWORD   ' UINT
END TYPE

' // Size = 8 bytes
TYPE D3D10_TEX2DMS_ARRAY_SRV DWORD
   FirstArraySlice AS DWORD   ' UINT
   ArraySize       AS DWORD   ' UINT
END TYPE

' // Size = 16 bytes
UNION D3D10_SHADER_RESOURCE_VIEW_DESC_UNION DWORD
   Buffer           AS D3D10_BUFFER_SRV
   Texture1D        AS D3D10_TEX1D_SRV
   Texture1DArray   AS D3D10_TEX1D_ARRAY_SRV
   Texture2D        AS D3D10_TEX2D_SRV
   Texture2DArray   AS D3D10_TEX2D_ARRAY_SRV
   Texture2DMS      AS D3D10_TEX2DMS_SRV
   Texture2DMSArray AS D3D10_TEX2DMS_ARRAY_SRV
   Texture3D        AS D3D10_TEX3D_SRV
   TextureCube      AS D3D10_TEXCUBE_SRV
END UNION

' // Size = 24 bytes
TYPE D3D10_SHADER_RESOURCE_VIEW_DESC
   Format AS DWORD          ' DXGI_FORMAT enum
   ViewDimension AS DWORD   ' D3D10_SRV_DIMENSION enum
   D3D10_SHADER_RESOURCE_VIEW_DESC_UNION
END TYPE

' ########################################################################################
' ID3D10ShaderResourceView interface
' IID = C902B03F-60A7-49BA-9936-2A3AB37A7E33
' Inherited interface = ID3D10View
' ########################################################################################

#IF NOT %DEF(%ID3D10ShaderResourceView_INTERFACE_DEFINED)
    %ID3D10ShaderResourceView_INTERFACE_DEFINED = 1

INTERFACE ID3D10ShaderResourceView $IID_ID3D10ShaderResourceView

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3D10DeviceChild Methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS ID3D10Device _                   ' __out  ID3D10Device **ppDevice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 16
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF pDataSize AS DWORD _                         ' __inout  UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out_bcount_opt(*pDataSize)  void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 20
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in_bcount_opt(DataSize)  const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYVAL pData AS IUnknown _                          ' __in_opt  const IUnknown *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10View Method
   ' =====================================================================================
   METHOD GetResource ( _                               ' VTable offset = 28
     BYREF ppResource AS ID3D10Resource _               ' __out  ID3D10Resource **ppResource
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10ShaderResourceView Method
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 32
     BYREF pDesc AS D3D10_SHADER_RESOURCE_VIEW_DESC _   ' __out  D3D10_SHADER_RESOURCE_VIEW_DESC *pDesc
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10ShaderResourceView_INTERFACE_DEFINED__ */


' // Size = 4 bytes
UNION D3D10_BUFFER_RTV_UNION1 DWORD
   FirstElement  AS DWORD   ' UINT
   ElementOffset AS DWORD   ' UINT
END UNION

' // Size = 4 bytes
UNION D3D10_BUFFER_RTV_UNION2 DWORD
   NumElements  AS DWORD    ' UINT
   ElementWidth AS DWORD    ' UINT
END UNION

' // Size = 8 bytes
TYPE D3D10_BUFFER_RTV DWORD
   D3D10_BUFFER_RTV_UNION1
   D3D10_BUFFER_RTV_UNION2
END TYPE

' // Size = 4 bytes
TYPE D3D10_TEX1D_RTV DWORD
   MipSlice AS DWORD   ' UINT
END TYPE

' // Size = 12 bytes
TYPE D3D10_TEX1D_ARRAY_RTV DWORD
   MipSlice        AS DWORD   ' UINT
   FirstArraySlice AS DWORD   ' UINT
   ArraySize       AS DWORD   ' UINT
END TYPE

' // Size = 4 bytes
TYPE D3D10_TEX2D_RTV DWORD
   MipSlice AS DWORD   ' UINT
END TYPE

' // Size = 4 bytes
TYPE D3D10_TEX2DMS_RTV DWORD
   UnusedField_NothingToDefine AS DWORD   ' UINT
END TYPE

' // Size = 12 bytes
TYPE D3D10_TEX2D_ARRAY_RTV DWORD
   MipSlice        AS DWORD   ' UINT
   FirstArraySlice AS DWORD   ' UINT
   ArraySize       AS DWORD   ' UINT
END TYPE

' // Size = 8 bytes
TYPE D3D10_TEX2DMS_ARRAY_RTV DWORD
   FirstArraySlice AS DWORD   ' UINT
   ArraySize       AS DWORD   ' UINT
END TYPE

' // Size = 12 bytes
TYPE D3D10_TEX3D_RTV DWORD
   MipSlice    AS DWORD   ' UINT
   FirstWSlice AS DWORD   ' UINT
   WSize       AS DWORD   ' UINT
END TYPE

' // Size = 12 bytes
UNION D3D10_RENDER_TARGET_VIEW_DESC_UNION DWORD
   Buffer           AS D3D10_BUFFER_RTV
   Texture1D        AS D3D10_TEX1D_RTV
   Texture1DArray   AS D3D10_TEX1D_ARRAY_RTV
   Texture2D        AS D3D10_TEX2D_RTV
   Texture2DArray   AS D3D10_TEX2D_ARRAY_RTV
   Texture2DMS      AS D3D10_TEX2DMS_RTV
   Texture2DMSArray AS D3D10_TEX2DMS_ARRAY_RTV
   Texture3D        AS D3D10_TEX3D_RTV
END UNION

' // Size = 20 bytes
TYPE D3D10_RENDER_TARGET_VIEW_DESC DWORD
   Format        AS DWORD   ' DXGI_FORMAT enum
   ViewDimension AS DWORD   ' D3D10_RTV_DIMENSION enum
   D3D10_RENDER_TARGET_VIEW_DESC_UNION
END TYPE

' ########################################################################################
' ID3D10RenderTargetView interface
' IID = 9B7E4C08-342C-4106-A19F-4F2704F689F0
' Inherited interface = ID3D10View
' ########################################################################################

#IF NOT %DEF(%ID3D10RenderTargetView_INTERFACE_DEFINED)
    %ID3D10RenderTargetView_INTERFACE_DEFINED = 1

INTERFACE ID3D10RenderTargetView $IID_ID3D10RenderTargetView

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3D10DeviceChild Methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS ID3D10Device _                   ' __out  ID3D10Device **ppDevice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 16
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF pDataSize AS DWORD _                         ' __inout  UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out_bcount_opt(*pDataSize)  void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 20
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in_bcount_opt(DataSize)  const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYVAL pData AS IUnknown _                          ' __in_opt  const IUnknown *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10View Method
   ' =====================================================================================
   METHOD GetResource ( _                               ' VTable offset = 28
     BYREF ppResource AS ID3D10Resource _               ' __out  ID3D10Resource **ppResource
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10RenderTargetView Method
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 32
     BYREF pDesc AS D3D10_RENDER_TARGET_VIEW_DESC _     ' __out  D3D10_RENDER_TARGET_VIEW_DESC *pDesc
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10RenderTargetView_INTERFACE_DEFINED__ */


' // Size = 4 bytes
TYPE D3D10_TEX1D_DSV DWORD
   MipSlice AS DWORD   ' UINT
END TYPE

' // Size = 12 bytes
TYPE D3D10_TEX1D_ARRAY_DSV DWORD
   MipSlice        AS DWORD   ' UINT
   FirstArraySlice AS DWORD   ' UINT
   ArraySize       AS DWORD   ' UINT
END TYPE

' // Size = 4 bytes
TYPE D3D10_TEX2D_DSV DWORD
   MipSlice AS DWORD   ' UINT
END TYPE

' // Size = 12 bytes
TYPE D3D10_TEX2D_ARRAY_DSV DWORD
   MipSlice        AS DWORD   ' UINT
   FirstArraySlice AS DWORD   ' UINT
   ArraySize       AS DWORD   ' UINT
END TYPE

' // Size = 4 bytes
TYPE D3D10_TEX2DMS_DSV DWORD
   UnusedField_NothingToDefine AS DWORD   ' UINT
END TYPE

' // Size = 8 bytes
TYPE D3D10_TEX2DMS_ARRAY_DSV DWORD
   FirstArraySlice AS DWORD   ' UINT
   ArraySize       AS DWORD   ' UINT
END TYPE

' // Size = 12 bytes
UNION D3D10_DEPTH_STENCIL_VIEW_DESC_UNION DWORD
   Texture1D        AS D3D10_TEX1D_DSV
   Texture1DArray   AS D3D10_TEX1D_ARRAY_DSV
   Texture2D        AS D3D10_TEX2D_DSV
   Texture2DArray   AS D3D10_TEX2D_ARRAY_DSV
   Texture2DMS      AS D3D10_TEX2DMS_DSV
   Texture2DMSArray AS D3D10_TEX2DMS_ARRAY_DSV
END UNION

' // Size = 20 bytes
TYPE D3D10_DEPTH_STENCIL_VIEW_DESC DWORD
   Format        AS DWORD   ' DXGI_FORMAT enum
   ViewDimension AS DWORD   ' D3D10_DSV_DIMENSION enum
   D3D10_DEPTH_STENCIL_VIEW_DESC_UNION
END TYPE

' ########################################################################################
' ID3D10DepthStencilView interface
' IID = 9B7E4C09-342C-4106-A19F-4F2704F689F0
' Inherited interface = ID3D10View
' ########################################################################################

#IF NOT %DEF(%ID3D10DepthStencilView_INTERFACE_DEFINED)
    %ID3D10DepthStencilView_INTERFACE_DEFINED = 1

INTERFACE ID3D10DepthStencilView $IID_ID3D10DepthStencilView

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3D10DeviceChild Methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS ID3D10Device _                   ' __out  ID3D10Device **ppDevice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 16
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF pDataSize AS DWORD _                         ' __inout  UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out_bcount_opt(*pDataSize)  void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 20
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in_bcount_opt(DataSize)  const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYVAL pData AS IUnknown _                          ' __in_opt  const IUnknown *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10View Method
   ' =====================================================================================
   METHOD GetResource ( _                               ' VTable offset = 28
     BYREF ppResource AS ID3D10Resource _               ' __out  ID3D10Resource **ppResource
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10DepthStencilView Method
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 32
     BYREF pDesc AS D3D10_DEPTH_STENCIL_VIEW_DESC _     ' __out  D3D10_DEPTH_STENCIL_VIEW_DESC *pDesc
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10DepthStencilView_INTERFACE_DEFINED__ */

' ########################################################################################
' ID3D10VertexShader interface
' IID = 9B7E4C0A-342C-4106-A19F-4F2704F689F0
' Inherited interface = ID3D10DeviceChild
' ########################################################################################

#IF NOT %DEF(%ID3D10VertexShader_INTERFACE_DEFINED)
    %ID3D10VertexShader_INTERFACE_DEFINED = 1

INTERFACE ID3D10VertexShader $IID_ID3D10VertexShader

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3D10DeviceChild Methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS ID3D10Device _                   ' __out  ID3D10Device **ppDevice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 16
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF pDataSize AS DWORD _                         ' __inout  UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out_bcount_opt(*pDataSize)  void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 20
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in_bcount_opt(DataSize)  const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYVAL pData AS IUnknown _                          ' __in_opt  const IUnknown *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10VertexShader_INTERFACE_DEFINED__ */

' ########################################################################################
' ID3D10GeometryShader interface
' IID = 6316BE88-54CD-4040-AB44-20461BC81F68
' Inherited interface = ID3D10DeviceChild
' ########################################################################################

#IF NOT %DEF(%ID3D10GeometryShader_INTERFACE_DEFINED)
    %ID3D10GeometryShader_INTERFACE_DEFINED = 1

INTERFACE ID3D10GeometryShader $IID_ID3D10GeometryShader

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3D10DeviceChild Methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS ID3D10Device _                   ' __out  ID3D10Device **ppDevice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 16
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF pDataSize AS DWORD _                         ' __inout  UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out_bcount_opt(*pDataSize)  void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 20
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in_bcount_opt(DataSize)  const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYVAL pData AS IUnknown _                          ' __in_opt  const IUnknown *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10GeometryShader_INTERFACE_DEFINED__ */

' ########################################################################################
' ID3D10PixelShader interface
' IID = 4968B601-9D00-4CDE-8346-8E7F675819B6
' Inherited interface = ID3D10DeviceChild
' ########################################################################################

#IF NOT %DEF(%ID3D10PixelShader_INTERFACE_DEFINED)
    %ID3D10PixelShader_INTERFACE_DEFINED = 1

INTERFACE ID3D10PixelShader $IID_ID3D10PixelShader

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3D10DeviceChild Methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS ID3D10Device _                   ' __out  ID3D10Device **ppDevice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 16
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF pDataSize AS DWORD _                         ' __inout  UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out_bcount_opt(*pDataSize)  void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 20
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in_bcount_opt(DataSize)  const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYVAL pData AS IUnknown _                          ' __in_opt  const IUnknown *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10PixelShader_INTERFACE_DEFINED__ */

' ########################################################################################
' ID3D10InputLayout interface
' IID = 9B7E4C0B-342C-4106-A19F-4F2704F689F0
' Inherited interface = ID3D10DeviceChild
' ########################################################################################

#IF NOT %DEF(%ID3D10InputLayout_INTERFACE_DEFINED)
    %ID3D10InputLayout_INTERFACE_DEFINED = 1

INTERFACE ID3D10InputLayout $IID_ID3D10InputLayout

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3D10DeviceChild Methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS ID3D10Device _                   ' __out  ID3D10Device **ppDevice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 16
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF pDataSize AS DWORD _                         ' __inout  UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out_bcount_opt(*pDataSize)  void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 20
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in_bcount_opt(DataSize)  const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYVAL pData AS IUnknown _                          ' __in_opt  const IUnknown *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10InputLayout_INTERFACE_DEFINED__ */


' enum D3D10_FILTER
%D3D10_FILTER_MIN_MAG_MIP_POINT                          = 0???
%D3D10_FILTER_MIN_MAG_POINT_MIP_LINEAR                   = &H1???
%D3D10_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT             = &H4???
%D3D10_FILTER_MIN_POINT_MAG_MIP_LINEAR                   = &H5???
%D3D10_FILTER_MIN_LINEAR_MAG_MIP_POINT                   = &H10???
%D3D10_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR            = &H11???
%D3D10_FILTER_MIN_MAG_LINEAR_MIP_POINT                   = &H14???
%D3D10_FILTER_MIN_MAG_MIP_LINEAR                         = &H15???
%D3D10_FILTER_ANISOTROPIC                                = &H55???
%D3D10_FILTER_COMPARISON_MIN_MAG_MIP_POINT               = &H80???
%D3D10_FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR        = &H81???
%D3D10_FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT  = &H84???
%D3D10_FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR        = &H85???
%D3D10_FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT        = &H90???
%D3D10_FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR = &H91???
%D3D10_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT        = &H94???
%D3D10_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR              = &H95???
%D3D10_FILTER_COMPARISON_ANISOTROPIC                     = &Hd5???
%D3D10_FILTER_TEXT_1BIT                                  = &H80000000???

' enum D3D10_FILTER_TYPE
%D3D10_FILTER_TYPE_POINT  = 0???
%D3D10_FILTER_TYPE_LINEAR = 1???

%D3D10_FILTER_TYPE_MASK          = &H3???
%D3D10_MIN_FILTER_SHIFT          = 4???
%D3D10_MAG_FILTER_SHIFT          = 2???
%D3D10_MIP_FILTER_SHIFT          = 0???
%D3D10_COMPARISON_FILTERING_BIT  = &H80???
%D3D10_ANISOTROPIC_FILTERING_BIT = &H40???
%D3D10_TEXT_1BIT_BIT             = &H80000000???

'#define D3D10_ENCODE_BASIC_FILTER( min, mag, mip, bComparison )                                           \
'                                   ( ( D3D10_FILTER ) (                                                   \
'                                   ( ( bComparison ) ? D3D10_COMPARISON_FILTERING_BIT : 0 ) |             \
'                                   ( ( ( min ) & D3D10_FILTER_TYPE_MASK ) << D3D10_MIN_FILTER_SHIFT ) |   \
'                                   ( ( ( mag ) & D3D10_FILTER_TYPE_MASK ) << D3D10_MAG_FILTER_SHIFT ) |   \
'                                   ( ( ( mip ) & D3D10_FILTER_TYPE_MASK ) << D3D10_MIP_FILTER_SHIFT ) ) )

FUNCTION D3D10_ENCODE_BASIC_FILTER (BYVAL nMin AS DWORD, BYVAL mag AS DWORD, BYVAL mip AS DWORD, BYVAL bComparison AS LONG) AS DWORD
   LOCAL xComparison, xMin, xMag, xMip AS DWORD
   xComparison = IIF&(bComparison = %TRUE, %D3D10_COMPARISON_FILTERING_BIT, 0)
   xMin = nMin AND %D3D10_FILTER_TYPE_MASK
   SHIFT LEFT xMin, %D3D10_MIN_FILTER_SHIFT
   xMag = mag AND %D3D10_FILTER_TYPE_MASK
   SHIFT LEFT xMag, %D3D10_MAG_FILTER_SHIFT
   xMip = mip AND %D3D10_FILTER_TYPE_MASK
   SHIFT LEFT xMip, %D3D10_MIP_FILTER_SHIFT
   FUNCTION = xComparison OR xMin OR xMag OR xMip
END FUNCTION

'#define D3D10_ENCODE_ANISOTROPIC_FILTER( bComparison )                                                \
'                                         ( ( D3D10_FILTER ) (                                         \
'                                         D3D10_ANISOTROPIC_FILTERING_BIT |                            \
'                                         D3D10_ENCODE_BASIC_FILTER( D3D10_FILTER_TYPE_LINEAR,         \
'                                                                    D3D10_FILTER_TYPE_LINEAR,         \
'                                                                    D3D10_FILTER_TYPE_LINEAR,         \
'                                                                    bComparison ) ) )

FUNCTION D3D10_ENCODE_ANISOTROPIC_FILTER (BYVAL bComparison AS LONG) AS DWORD
   FUNCTION = %D3D10_ANISOTROPIC_FILTERING_BIT OR D3D10_ENCODE_BASIC_FILTER(%D3D10_FILTER_TYPE_LINEAR, %D3D10_FILTER_TYPE_LINEAR, %D3D10_FILTER_TYPE_LINEAR, bComparison)
END FUNCTION

'#define D3D10_DECODE_MIN_FILTER( d3d10Filter )                                                              \
'                                 ( ( D3D10_FILTER_TYPE )                                                    \
'                                 ( ( ( d3d10Filter ) >> D3D10_MIN_FILTER_SHIFT ) & D3D10_FILTER_TYPE_MASK ) )

FUNCTION D3D10_DECODE_MIN_FILTER (BYVAL d3d10Filter AS DWORD) AS DWORD
   SHIFT RIGHT d3d10Filter, %D3D10_MIN_FILTER_SHIFT
   FUNCTION = d3d10Filter AND %D3D10_FILTER_TYPE_MASK
END FUNCTION

'#define D3D10_DECODE_MAG_FILTER( d3d10Filter )                                                              \
'                                 ( ( D3D10_FILTER_TYPE )                                                    \
'                                 ( ( ( d3d10Filter ) >> D3D10_MAG_FILTER_SHIFT ) & D3D10_FILTER_TYPE_MASK ) )

FUNCTION D3D10_DECODE_MAG_FILTER (BYVAL d3d10Filter AS DWORD) AS DWORD
   SHIFT RIGHT d3d10Filter, %D3D10_MAG_FILTER_SHIFT
   FUNCTION = d3d10Filter AND %D3D10_FILTER_TYPE_MASK
END FUNCTION

'#define D3D10_DECODE_MIP_FILTER( d3d10Filter )                                                              \
'                                 ( ( D3D10_FILTER_TYPE )                                                    \
'                                 ( ( ( d3d10Filter ) >> D3D10_MIP_FILTER_SHIFT ) & D3D10_FILTER_TYPE_MASK ) )

FUNCTION D3D10_DECODE_MIP_FILTER (BYVAL d3d10Filter AS DWORD) AS DWORD
   SHIFT RIGHT d3d10Filter, %D3D10_MIP_FILTER_SHIFT
   FUNCTION = d3d10Filter AND %D3D10_FILTER_TYPE_MASK
END FUNCTION

'#define D3D10_DECODE_IS_COMPARISON_FILTER( d3d10Filter )                                                    \
'                                 ( ( d3d10Filter ) & D3D10_COMPARISON_FILTERING_BIT )

FUNCTION D3D10_DECODE_IS_COMPARISON_FILTER (BYVAL d3d10Filter AS DWORD) AS LONG
   FUNCTION = d3d10Filter AND %D3D10_COMPARISON_FILTERING_BIT
END FUNCTION

'#define D3D10_DECODE_IS_ANISOTROPIC_FILTER( d3d10Filter )                                               \
'                            ( ( ( d3d10Filter ) & D3D10_ANISOTROPIC_FILTERING_BIT ) &&                  \
'                            ( D3D10_FILTER_TYPE_LINEAR == D3D10_DECODE_MIN_FILTER( d3d10Filter ) ) &&   \
'                            ( D3D10_FILTER_TYPE_LINEAR == D3D10_DECODE_MAG_FILTER( d3d10Filter ) ) &&   \
'                            ( D3D10_FILTER_TYPE_LINEAR == D3D10_DECODE_MIP_FILTER( d3d10Filter ) ) )

FUNCTION D3D10_DECODE_IS_ANISOTROPIC_FILTER (BYVAL d3d10Filter AS DWORD) AS LONG
   FUNCTION = ((d3d10Filter AND %D3D10_ANISOTROPIC_FILTERING_BIT) AND _
              (%D3D10_FILTER_TYPE_LINEAR = D3D10_DECODE_MIN_FILTER(d3d10Filter)) AND _
              (%D3D10_FILTER_TYPE_LINEAR = D3D10_DECODE_MAG_FILTER(d3d10Filter)) AND _
              (%D3D10_FILTER_TYPE_LINEAR = D3D10_DECODE_MIP_FILTER( d3d10Filter)))
END FUNCTION

'#define D3D10_DECODE_IS_TEXT_1BIT_FILTER( d3d10Filter )                                             \
'                                 ( ( d3d10Filter ) == D3D10_TEXT_1BIT_BIT )

FUNCTION D3D10_DECODE_IS_TEXT_1BIT_FILTER (BYVAL d3d10Filter AS DWORD) AS LONG
   FUNCTION = d3d10Filter = %D3D10_TEXT_1BIT_BIT
END FUNCTION

' enum D3D10_TEXTURE_ADDRESS_MODE
%D3D10_TEXTURE_ADDRESS_WRAP        = 1???
%D3D10_TEXTURE_ADDRESS_MIRROR      = 2???
%D3D10_TEXTURE_ADDRESS_CLAMP       = 3???
%D3D10_TEXTURE_ADDRESS_BORDER      = 4???
%D3D10_TEXTURE_ADDRESS_MIRROR_ONCE = 5???

' // Size = 52 bytes
TYPE D3D10_SAMPLER_DESC DWORD
   Filter         AS DWORD    ' D3D10_FILTER enum
   AddressU       AS DWORD    ' D3D10_TEXTURE_ADDRESS_MODE enum
   AddressV       AS DWORD    ' D3D10_TEXTURE_ADDRESS_MODE enum
   AddressW       AS DWORD    ' D3D10_TEXTURE_ADDRESS_MODE enum
   MipLODBias     AS SINGLE   ' FLOAT
   MaxAnisotropy  AS DWORD    ' UINT
   ComparisonFunc AS DWORD    ' D3D10_COMPARISON_FUNC enum
   BorderColor(3) AS SINGLE   ' FLOAT[4]
   MinLOD         AS SINGLE   ' FLOAT
   MaxLOD         AS SINGLE   ' FLOAT
END TYPE

' ########################################################################################
' ID3D10SamplerState interface
' IID = 9B7E4C0C-342C-4106-A19F-4F2704F689F0
' Inherited interface = ID3D10DeviceChild
' ########################################################################################

#IF NOT %DEF(%ID3D10SamplerState_INTERFACE_DEFINED)
    %ID3D10SamplerState_INTERFACE_DEFINED = 1

INTERFACE ID3D10SamplerState $IID_ID3D10SamplerState

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3D10DeviceChild Methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS ID3D10Device _                   ' __out  ID3D10Device **ppDevice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 16
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF pDataSize AS DWORD _                         ' __inout  UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out_bcount_opt(*pDataSize)  void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 20
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in_bcount_opt(DataSize)  const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYVAL pData AS IUnknown _                          ' __in_opt  const IUnknown *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10SamplerState Method
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 28
     BYREF pDesc AS D3D10_SAMPLER_DESC _                ' __out  D3D10_SAMPLER_DESC *pDesc
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10SamplerState_INTERFACE_DEFINED__ */


' enum D3D10_FORMAT_SUPPORT
%D3D10_FORMAT_SUPPORT_BUFFER                   = &H1???
%D3D10_FORMAT_SUPPORT_IA_VERTEX_BUFFER         = &H2???
%D3D10_FORMAT_SUPPORT_IA_INDEX_BUFFER          = &H4???
%D3D10_FORMAT_SUPPORT_SO_BUFFER                = &H8???
%D3D10_FORMAT_SUPPORT_TEXTURE1D                = &H10???
%D3D10_FORMAT_SUPPORT_TEXTURE2D                = &H20???
%D3D10_FORMAT_SUPPORT_TEXTURE3D                = &H40???
%D3D10_FORMAT_SUPPORT_TEXTURECUBE              = &H80???
%D3D10_FORMAT_SUPPORT_SHADER_LOAD              = &H100???
%D3D10_FORMAT_SUPPORT_SHADER_SAMPLE            = &H200???
%D3D10_FORMAT_SUPPORT_SHADER_SAMPLE_COMPARISON = &H400???
%D3D10_FORMAT_SUPPORT_SHADER_SAMPLE_MONO_TEXT  = &H800???
%D3D10_FORMAT_SUPPORT_MIP                      = &H1000???
%D3D10_FORMAT_SUPPORT_MIP_AUTOGEN              = &H2000???
%D3D10_FORMAT_SUPPORT_RENDER_TARGET            = &H4000???
%D3D10_FORMAT_SUPPORT_BLENDABLE                = &H8000???
%D3D10_FORMAT_SUPPORT_DEPTH_STENCIL            = &H10000???
%D3D10_FORMAT_SUPPORT_CPU_LOCKABLE             = &H20000???
%D3D10_FORMAT_SUPPORT_MULTISAMPLE_RESOLVE      = &H40000???
%D3D10_FORMAT_SUPPORT_DISPLAY                  = &H80000???
%D3D10_FORMAT_SUPPORT_CAST_WITHIN_BIT_LAYOUT   = &H100000???
%D3D10_FORMAT_SUPPORT_MULTISAMPLE_RENDERTARGET = &H200000???
%D3D10_FORMAT_SUPPORT_MULTISAMPLE_LOAD         = &H400000???
%D3D10_FORMAT_SUPPORT_SHADER_GATHER            = &H800000???
%D3D10_FORMAT_SUPPORT_BACK_BUFFER_CAST         = &H1000000???


' ########################################################################################
' ID3D10Asynchronous interface
' IID = 9B7E4C0D-342C-4106-A19F-4F2704F689F0
' Inherited interface = ID3D10DeviceChild
' ########################################################################################

#IF NOT %DEF(%ID3D10Asynchronous_INTERFACE_DEFINED)
    %ID3D10Asynchronous_INTERFACE_DEFINED = 1

INTERFACE ID3D10Asynchronous $IID_ID3D10Asynchronous

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3D10DeviceChild Methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS ID3D10Device _                   ' __out  ID3D10Device **ppDevice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 16
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF pDataSize AS DWORD _                         ' __inout  UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out_bcount_opt(*pDataSize)  void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 20
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in_bcount_opt(DataSize)  const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYVAL pData AS IUnknown _                          ' __in_opt  const IUnknown *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10Asynchronous Methods
   ' =====================================================================================
   METHOD Begin ( _                                     ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD End ( _                                       ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 36
     BYREF pData AS DWORD _                             ' __out_bcount_opt(DataSize)  void *pData
   , BYVAL DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL GetDataFlags AS DWORD _                      ' __in  UINT GetDataFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDataSize ( _                               ' VTable offset = 40
   ) AS DWORD                                           ' UINT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10Asynchronous_INTERFACE_DEFINED__ */


' enum D3D10_ASYNC_GETDATA_FLAG
%D3D10_ASYNC_GETDATA_DONOTFLUSH = &H1???

' enum D3D10_QUERY
%D3D10_QUERY_EVENT                 = 0???
%D3D10_QUERY_OCCLUSION             = (%D3D10_QUERY_EVENT               + 1)
%D3D10_QUERY_TIMESTAMP             = (%D3D10_QUERY_OCCLUSION           + 1)
%D3D10_QUERY_TIMESTAMP_DISJOINT    = (%D3D10_QUERY_TIMESTAMP           + 1)
%D3D10_QUERY_PIPELINE_STATISTICS   = (%D3D10_QUERY_TIMESTAMP_DISJOINT  + 1)
%D3D10_QUERY_OCCLUSION_PREDICATE   = (%D3D10_QUERY_PIPELINE_STATISTICS + 1)
%D3D10_QUERY_SO_STATISTICS         = (%D3D10_QUERY_OCCLUSION_PREDICATE + 1)
%D3D10_QUERY_SO_OVERFLOW_PREDICATE = (%D3D10_QUERY_SO_STATISTICS       + 1)

' enum D3D10_QUERY_MISC_FLAG
%D3D10_QUERY_MISC_PREDICATEHINT    = &H1???

' // Size = 8 bytes
TYPE D3D10_QUERY_DESC DWORD
   Query     AS DWORD   ' D3D10_QUERY
   MiscFlags AS DWORD   ' UINT
END TYPE


' ########################################################################################
' ID3D10Query interface
' IID = 9B7E4C0E-342C-4106-A19F-4F2704F689F0
' Inherited interface = ID3D10Asynchronous
' ########################################################################################

#IF NOT %DEF(%ID3D10Query_INTERFACE_DEFINED)
    %ID3D10Query_INTERFACE_DEFINED = 1

INTERFACE ID3D10Query $IID_ID3D10Query

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3D10DeviceChild Methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS ID3D10Device _                   ' __out  ID3D10Device **ppDevice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 16
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF pDataSize AS DWORD _                         ' __inout  UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out_bcount_opt(*pDataSize)  void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 20
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in_bcount_opt(DataSize)  const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYVAL pData AS IUnknown _                          ' __in_opt  const IUnknown *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10Asynchronous Methods
   ' =====================================================================================
   METHOD Begin ( _                                     ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD End ( _                                       ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 36
     BYREF pData AS DWORD _                             ' __out_bcount_opt(DataSize)  void *pData
   , BYVAL DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL GetDataFlags AS DWORD _                      ' __in  UINT GetDataFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDataSize ( _                               ' VTable offset = 40
   ) AS DWORD                                           ' UINT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10Query Method
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 44
     BYREF pDesc AS D3D10_QUERY_DESC _                  ' __out  D3D10_QUERY_DESC *pDesc
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10Query_INTERFACE_DEFINED__ */

' ########################################################################################
' ID3D10Predicate interface
' IID = 9B7E4C10-342C-4106-A19F-4F2704F689F0
' Inherited interface = ID3D10Query
' ########################################################################################

#IF NOT %DEF(%ID3D10Predicate_INTERFACE_DEFINED)
    %ID3D10Predicate_INTERFACE_DEFINED = 1

INTERFACE ID3D10Predicate $IID_ID3D10Predicate

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3D10DeviceChild Methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS ID3D10Device _                   ' __out  ID3D10Device **ppDevice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 16
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF pDataSize AS DWORD _                         ' __inout  UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out_bcount_opt(*pDataSize)  void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 20
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in_bcount_opt(DataSize)  const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYVAL pData AS IUnknown _                          ' __in_opt  const IUnknown *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10Asynchronous Methods
   ' =====================================================================================
   METHOD Begin ( _                                     ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD End ( _                                       ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 36
     BYREF pData AS DWORD _                             ' __out_bcount_opt(DataSize)  void *pData
   , BYVAL DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL GetDataFlags AS DWORD _                      ' __in  UINT GetDataFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDataSize ( _                               ' VTable offset = 40
   ) AS DWORD                                           ' UINT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10Query Method
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 44
     BYREF pDesc AS D3D10_QUERY_DESC _                  ' __out  D3D10_QUERY_DESC *pDesc
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10Predicate_INTERFACE_DEFINED__ */


' // Size = 8 bytes
TYPE D3D10_QUERY_DATA_TIMESTAMP_DISJOINT DWORD
   Frequency AS QUAD   ' UINT64
   Disjoint  AS LONG   ' BOOL
END TYPE

' // Size = 64 bytes
TYPE D3D10_QUERY_DATA_PIPELINE_STATISTICS QWORD
   IAVertices    AS QUAD   ' UINT64
   IAPrimitives  AS QUAD   ' UINT64
   VSInvocations AS QUAD   ' UINT64
   GSInvocations AS QUAD   ' UINT64
   GSPrimitives  AS QUAD   ' UINT64
   CInvocations  AS QUAD   ' UINT64
   CPrimitives   AS QUAD   ' UINT64
   PSInvocations AS QUAD   ' UINT64
END TYPE

' // Size = 16 bytes
TYPE D3D10_QUERY_DATA_SO_STATISTICS QWORD
   NumPrimitivesWritten    AS QUAD   ' UINT64
   PrimitivesStorageNeeded AS QUAD   ' UINT64
END TYPE

' enum D3D10_COUNTER
%D3D10_COUNTER_GPU_IDLE                              = 0???
%D3D10_COUNTER_VERTEX_PROCESSING                     = (%D3D10_COUNTER_GPU_IDLE                              + 1)
%D3D10_COUNTER_GEOMETRY_PROCESSING                   = (%D3D10_COUNTER_VERTEX_PROCESSING                     + 1)
%D3D10_COUNTER_PIXEL_PROCESSING                      = (%D3D10_COUNTER_GEOMETRY_PROCESSING                   + 1)
%D3D10_COUNTER_OTHER_GPU_PROCESSING                  = (%D3D10_COUNTER_PIXEL_PROCESSING                      + 1)
%D3D10_COUNTER_HOST_ADAPTER_BANDWIDTH_UTILIZATION    = (%D3D10_COUNTER_OTHER_GPU_PROCESSING                  + 1)
%D3D10_COUNTER_LOCAL_VIDMEM_BANDWIDTH_UTILIZATION    = (%D3D10_COUNTER_HOST_ADAPTER_BANDWIDTH_UTILIZATION    + 1)
%D3D10_COUNTER_VERTEX_THROUGHPUT_UTILIZATION         = (%D3D10_COUNTER_LOCAL_VIDMEM_BANDWIDTH_UTILIZATION    + 1)
%D3D10_COUNTER_TRIANGLE_SETUP_THROUGHPUT_UTILIZATION = (%D3D10_COUNTER_VERTEX_THROUGHPUT_UTILIZATION         + 1)
%D3D10_COUNTER_FILLRATE_THROUGHPUT_UTILIZATION       = (%D3D10_COUNTER_TRIANGLE_SETUP_THROUGHPUT_UTILIZATION + 1)
%D3D10_COUNTER_VS_MEMORY_LIMITED                     = (%D3D10_COUNTER_FILLRATE_THROUGHPUT_UTILIZATION       + 1)
%D3D10_COUNTER_VS_COMPUTATION_LIMITED                = (%D3D10_COUNTER_VS_MEMORY_LIMITED                     + 1)
%D3D10_COUNTER_GS_MEMORY_LIMITED                     = (%D3D10_COUNTER_VS_COMPUTATION_LIMITED                + 1)
%D3D10_COUNTER_GS_COMPUTATION_LIMITED                = (%D3D10_COUNTER_GS_MEMORY_LIMITED                     + 1)
%D3D10_COUNTER_PS_MEMORY_LIMITED                     = (%D3D10_COUNTER_GS_COMPUTATION_LIMITED                + 1)
%D3D10_COUNTER_PS_COMPUTATION_LIMITED                = (%D3D10_COUNTER_PS_MEMORY_LIMITED                     + 1)
%D3D10_COUNTER_POST_TRANSFORM_CACHE_HIT_RATE         = (%D3D10_COUNTER_PS_COMPUTATION_LIMITED                + 1)
%D3D10_COUNTER_TEXTURE_CACHE_HIT_RATE                = (%D3D10_COUNTER_POST_TRANSFORM_CACHE_HIT_RATE         + 1)
%D3D10_COUNTER_DEVICE_DEPENDENT_0                    = &H40000000???

' enum D3D10_COUNTER_TYPE
%D3D10_COUNTER_TYPE_FLOAT32 = 0???
%D3D10_COUNTER_TYPE_UINT16  = (%D3D10_COUNTER_TYPE_FLOAT32 + 1)
%D3D10_COUNTER_TYPE_UINT32  = (%D3D10_COUNTER_TYPE_UINT16  + 1)
%D3D10_COUNTER_TYPE_UINT64  = (%D3D10_COUNTER_TYPE_UINT32  + 1)

' // Size = 8 bytes
TYPE D3D10_COUNTER_DESC DWOrd
   Counter   AS DWORD   ' D3D10_COUNTER
   MiscFlags AS DWORD   ' UINT
END TYPE

' // Size = 12 bytes
TYPE D3D10_COUNTER_INFO DWORD
   LastDeviceDependentCounter AS DWORD   ' D3D10_COUNTER
   NumSimultaneousCounters    AS DWORD   ' UINT
   NumDetectableParallelUnits AS BYTE    ' UINT8
END TYPE

' ########################################################################################
' ID3D10Counter interface
' IID = 9B7E4C11-342C-4106-A19F-4F2704F689F0
' Inherited interface = ID3D10Asynchronous
' ########################################################################################

#IF NOT %DEF(%ID3D10Counter_INTERFACE_DEFINED)
    %ID3D10Counter_INTERFACE_DEFINED = 1

INTERFACE ID3D10Counter $IID_ID3D10Counter

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3D10DeviceChild Methods
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 12
     BYREF ppDevice AS ID3D10Device _                   ' __out  ID3D10Device **ppDevice
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 16
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF pDataSize AS DWORD _                         ' __inout  UINT *pDataSize
   , BYREF pData AS DWORD _                             ' __out_bcount_opt(*pDataSize)  void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 20
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in_bcount_opt(DataSize)  const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 24
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYVAL pData AS IUnknown _                          ' __in_opt  const IUnknown *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10Asynchronous Methods
   ' =====================================================================================
   METHOD Begin ( _                                     ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD End ( _                                       ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 36
     BYREF pData AS DWORD _                             ' __out_bcount_opt(DataSize)  void *pData
   , BYVAL DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL GetDataFlags AS DWORD _                      ' __in  UINT GetDataFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDataSize ( _                               ' VTable offset = 40
   ) AS DWORD                                           ' UINT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3D10Counter Method
   ' =====================================================================================
   METHOD GetDesc ( _                                   ' VTable offset = 44
     BYREF pDesc AS D3D10_COUNTER_DESC _                ' __out  D3D10_COUNTER_DESC *pDesc
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10Counter_INTERFACE_DEFINED__ */


' ########################################################################################
' ID3D10Device interface
' IID = 9B7E4C0F-342C-4106-A19F-4F2704F689F0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ID3D10Device_INTERFACE_DEFINED)
    %ID3D10Device_INTERFACE_DEFINED = 1

INTERFACE ID3D10Device $IID_ID3D10Device

   INHERIT IUnknown

   ' =====================================================================================
   METHOD VSSetConstantBuffers ( _                      ' VTable offset = 12
     BYVAL StartSlot AS DWORD _                         ' __in UINT StartSlot
   , BYVAL NumBuffers AS DWORD _                        ' __in UINT NumBuffers
   , BYREF ppConstantBuffers AS ID3D10Buffer _          ' __in ID3D10Buffer *const *ppConstantBuffers
   )                                                    ' void
   ' =====================================================================================
   METHOD PSSetShaderResources ( _                      ' VTable offset = 16
     BYVAL StartSlot AS DWORD _                         ' __in UINT StartSlot
   , BYVAL NumViews AS DWORD _                          ' __in UINT NumViews
   , BYREF ppShaderResourceViews AS ID3D10ShaderResourceView _ ' __in ID3D10ShaderResourceView *const *ppShaderResourceViews
   )                                                    ' void
   ' =====================================================================================
   METHOD PSSetShader ( _                               ' VTable offset = 20
     BYVAL pPixelShader AS ID3D10PixelShader _          ' __in_opt  ID3D10PixelShader *pPixelShader
   )                                                    ' void
   ' =====================================================================================
   METHOD PSSetSamplers ( _                             ' VTable offset = 24
     BYVAL StartSlot AS DWORD _                         ' __in UINT StartSlot
   , BYVAL NumSamplers AS DWORD _                       ' __in UINT NumSamplers
   , BYREF ppSamplers AS ID3D10SamplerState _           ' __in ID3D10SamplerState *const *ppSamplers
   )                                                    ' void
   ' =====================================================================================
   METHOD VSSetShader ( _                               ' VTable offset = 28
     BYVAL pVertexShader AS ID3D10VertexShader _        ' __in_opt  ID3D10VertexShader *pVertexShader
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawIndexed ( _                               ' VTable offset = 32
     BYVAL IndexCount AS DWORD _                        ' __in  UINT IndexCount
   , BYVAL StartIndexLocation AS DWORD _                ' __in  UINT StartIndexLocation
   , BYVAL BaseVertexLocation AS LONG _                 ' __in  INT BaseVertexLocation
   )                                                    ' void
   ' =====================================================================================
   METHOD Draw ( _                                      ' VTable offset = 36
     BYVAL VertexCount AS DWORD _                       ' __in  UINT VertexCount
   , BYVAL StartVertexLocation AS DWORD _               ' __in  UINT StartVertexLocation
   )                                                    ' void
   ' =====================================================================================
   METHOD PSSetConstantBuffers ( _                      ' VTable offset = 40
     BYVAL StartSlot AS DWORD _                         ' __in UINT StartSlot
   , BYVAL NumBuffers AS DWORD _                        ' __in UINT NumBuffers
   , BYREF ppConstantBuffers AS ID3D10Buffer _          ' __in ID3D10Buffer *const *ppConstantBuffers
   )                                                    ' void
   ' =====================================================================================
   METHOD IASetInputLayout ( _                          ' VTable offset = 44
     BYVAL pInputLayout AS ID3D10InputLayout _          ' __in_opt  ID3D10InputLayout *pInputLayout
   )                                                    ' void
   ' =====================================================================================
   METHOD IASetVertexBuffers ( _                        ' VTable offset = 48
     BYVAL StartSlot AS DWORD _                         ' __in UINT StartSlot
   , BYVAL NumBuffers AS DWORD _                        ' __in UINT NumBuffers
   , BYREF ppVertexBuffers AS ID3D10Buffer _            ' __in ID3D10Buffer *const *ppVertexBuffers
   , BYREF pStrides AS DWORD _                          ' __in const UINT *pStrides
   , BYREF pOffsets AS DWORD _                          ' __in const UINT *pOffsets
   )                                                    ' void
   ' =====================================================================================
   METHOD IASetIndexBuffer ( _                          ' VTable offset = 52
     BYVAL pIndexBuffer AS ID3D10Buffer _               ' __in_opt  ID3D10Buffer *pIndexBuffer
   , BYVAL Format AS DWORD _                            ' __in  DXGI_FORMAT Format
   , BYVAL Offset AS DWORD _                            ' __in  UINT Offset
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawIndexedInstanced ( _                      ' VTable offset = 56
     BYVAL IndexCountPerInstance AS DWORD _             ' __in  UINT IndexCountPerInstance
   , BYVAL InstanceCount AS DWORD _                     ' __in  UINT InstanceCount
   , BYVAL StartIndexLocation AS DWORD _                ' __in  UINT StartIndexLocation
   , BYVAL BaseVertexLocation AS LONG _                 ' __in  INT BaseVertexLocation
   , BYVAL StartInstanceLocation AS DWORD _             ' __in  UINT StartInstanceLocation
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawInstanced ( _                             ' VTable offset = 60
     BYVAL VertexCountPerInstance AS DWORD _            ' __in  UINT VertexCountPerInstance
   , BYVAL InstanceCount AS DWORD _                     ' __in  UINT InstanceCount
   , BYVAL StartVertexLocation AS DWORD _               ' __in  UINT StartVertexLocation
   , BYVAL StartInstanceLocation AS DWORD _             ' __in  UINT StartInstanceLocation
   )                                                    ' void
   ' =====================================================================================
   METHOD GSSetConstantBuffers ( _                      ' VTable offset = 64
     BYVAL StartSlot AS DWORD _                         ' __in UINT StartSlot
   , BYVAL NumBuffers AS DWORD _                        ' __in UINT NumBuffers
   , BYREF ppConstantBuffers AS ID3D10Buffer _          ' __in ID3D10Buffer *const *ppConstantBuffers
   )                                                    ' void
   ' =====================================================================================
   METHOD GSSetShader ( _                               ' VTable offset = 68
     BYVAL pShader AS ID3D10GeometryShader _            ' __in_opt  ID3D10GeometryShader *pShader
   )                                                    ' void
   ' =====================================================================================
   METHOD IASetPrimitiveTopology ( _                    ' VTable offset = 72
     BYVAL Topology AS DWORD _                          ' __in  D3D10_PRIMITIVE_TOPOLOGY Topology
   )                                                    ' void
   ' =====================================================================================
   METHOD VSSetShaderResources ( _                      ' VTable offset = 76
     BYVAL StartSlot AS DWORD _                         ' __in UINT StartSlot
   , BYVAL NumViews AS DWORD _                          ' __in UINT NumViews
   , BYREF ppShaderResourceViews AS ID3D10ShaderResourceView _ ' __in ID3D10ShaderResourceView *const *ppShaderResourceViews
   )                                                    ' void
   ' =====================================================================================
   METHOD VSSetSamplers ( _                             ' VTable offset = 80
     BYVAL StartSlot AS DWORD _                         ' __in UINT StartSlot
   , BYVAL NumSamplers AS DWORD _                       ' __in UINT NumSamplers
   , BYREF ppSamplers AS ID3D10SamplerState _           ' __in ID3D10SamplerState *const *ppSamplers
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPredication ( _                            ' VTable offset = 84
     BYVAL pPredicate AS ID3D10Predicate _              ' __in_opt  ID3D10Predicate *pPredicate
   , BYVAL PredicateValue AS LONG _                     ' __in  BOOL PredicateValue
   )                                                    ' void
   ' =====================================================================================
   METHOD GSSetShaderResources ( _                      ' VTable offset = 88
     BYVAL StartSlot AS DWORD _                         ' __in UINT StartSlot
   , BYVAL NumViews AS DWORD _                          ' __in UINT NumViews
   , BYREF ppShaderResourceViews AS ID3D10ShaderResourceView _ ' __in ID3D10ShaderResourceView *const *ppShaderResourceViews
   )                                                    ' void
   ' =====================================================================================
   METHOD GSSetSamplers ( _                             ' VTable offset = 92
     BYVAL StartSlot AS DWORD _                         ' __in UINT StartSlot
   , BYVAL NumSamplers AS DWORD _                       ' __in UINT NumSamplers
   , BYREF ppSamplers AS ID3D10SamplerState _           ' __in ID3D10SamplerState *const *ppSamplers
   )                                                    ' void
   ' =====================================================================================
   METHOD OMSetRenderTargets ( _                        ' VTable offset = 96
     BYVAL NumViews AS DWORD _                          ' __in UINT NumViews
   , BYREF ppRenderTargetViews AS ID3D10RenderTargetView _ ' __in ID3D10RenderTargetView *const *ppRenderTargetViews
   , BYVAL pDepthStencilView AS ID3D10DepthStencilView _   ' __in_opt  ID3D10DepthStencilView *pDepthStencilView
   )                                                    ' void
   ' =====================================================================================
   METHOD OMSetBlendState ( _                           ' VTable offset = 100
     BYVAL pBlendState AS ID3D10BlendState _            ' __in_opt  ID3D10BlendState *pBlendState
   , BYREF BlendFactor AS SINGLE _                      ' __in  const FLOAT BlendFactor[ 4 ]
   , BYVAL SampleMask AS DWORD _                        ' __in  UINT SampleMask
   )                                                    ' void
   ' =====================================================================================
   METHOD OMSetDepthStencilState ( _                    ' VTable offset = 104
     BYVAL pDepthStencilState AS ID3D10DepthStencilState _ ' __in_opt  ID3D10DepthStencilState *pDepthStencilState
   , BYVAL StencilRef AS DWORD _                        ' __in  UINT StencilRef
   )                                                    ' void
   ' =====================================================================================
   METHOD SOSetTargets ( _                              ' VTable offset = 108
     BYVAL NumBuffers AS DWORD _                        ' __in UINT NumBuffers
   , BYREF ppSOTargets AS ID3D10Buffer _                ' __in ID3D10Buffer *const *ppSOTargets
   , BYREF pOffsets AS DWORD _                          ' __in const UINT *pOffsets
   )                                                    ' void
   ' =====================================================================================
   METHOD DrawAuto ( _                                  ' VTable offset = 112
   )                                                    ' void
   ' =====================================================================================
   METHOD RSSetState ( _                                ' VTable offset = 116
     BYVAL pRasterizerState AS ID3D10RasterizerState _  ' __in_opt  ID3D10RasterizerState *pRasterizerState
   )                                                    ' void
   ' =====================================================================================
   METHOD RSSetViewports ( _                            ' VTable offset = 120
     BYVAL NumViewports AS DWORD _                      ' __in UINT NumViewports
   , BYREF pViewports AS D3D10_VIEWPORT _               ' __in const D3D10_VIEWPORT *pViewports
   )                                                    ' void
   ' =====================================================================================
   METHOD RSSetScissorRects ( _                         ' VTable offset = 124
     BYVAL NumRects AS DWORD _                          ' __in UINT NumRects
   , BYREF pRects AS D3D10_RECT _                       ' __in const D3D10_RECT *pRects
   )                                                    ' void
   ' =====================================================================================
   METHOD CopySubresourceRegion ( _                     ' VTable offset = 128
     BYVAL pDstResource AS ID3D10Resource _             ' __in  ID3D10Resource *pDstResource
   , BYVAL DstSubresource AS DWORD _                    ' __in  UINT DstSubresource
   , BYVAL DstX AS DWORD _                              ' __in  UINT DstX
   , BYVAL DstY AS DWORD _                              ' __in  UINT DstY
   , BYVAL DstZ AS DWORD _                              ' __in  UINT DstZ
   , BYVAL pSrcResource AS ID3D10Resource _             ' __in  ID3D10Resource *pSrcResource
   , BYVAL SrcSubresource AS DWORD _                    ' __in  UINT SrcSubresource
   , BYREF pSrcBox AS D3D10_BOX _                       ' __in_opt  const D3D10_BOX *pSrcBox
   )                                                    ' void
   ' =====================================================================================
   METHOD CopyResource ( _                              ' VTable offset = 132
     BYVAL pDstResource AS ID3D10Resource _             ' __in  ID3D10Resource *pDstResource
   , BYVAL pSrcResource AS ID3D10Resource _             ' __in  ID3D10Resource *pSrcResource
   )                                                    ' void
   ' =====================================================================================
   METHOD UpdateSubresource ( _                         ' VTable offset = 136
     BYVAL pDstResource AS ID3D10Resource _             ' __in  ID3D10Resource *pDstResource
   , BYVAL DstSubresource AS DWORD _                    ' __in  UINT DstSubresource
   , BYREF pDstBox AS D3D10_BOX _                       ' __in_opt  const D3D10_BOX *pDstBox
   , BYVAL pSrcData AS DWORD _                          ' __in  const void *pSrcData
   , BYVAL SrcRowPitch AS DWORD _                       ' __in  UINT SrcRowPitch
   , BYVAL SrcDepthPitch AS DWORD _                     ' __in  UINT SrcDepthPitch
   )                                                    ' void
   ' =====================================================================================
   METHOD ClearRenderTargetView ( _                     ' VTable offset = 140
     BYVAL pRenderTargetView AS ID3D10RenderTargetView _ ' __in  ID3D10RenderTargetView *pRenderTargetView
   , BYREF ColorRGBA AS SINGLE _                        ' __in  const FLOAT ColorRGBA[ 4 ]
   )                                                    ' void
   ' =====================================================================================
   METHOD ClearDepthStencilView ( _                     ' VTable offset = 144
     BYVAL pDepthStencilView AS ID3D10DepthStencilView _ ' __in  ID3D10DepthStencilView *pDepthStencilView
   , BYVAL ClearFlags AS DWORD _                        ' __in  UINT ClearFlags
   , BYVAL Depth AS SINGLE _                            ' __in  FLOAT Depth
   , BYVAL Stencil AS BYTE _                            ' __in  UINT8 Stencil
   )                                                    ' void
   ' =====================================================================================
   METHOD GenerateMips ( _                              ' VTable offset = 148
     BYVAL pShaderResourceView AS ID3D10ShaderResourceView _ ' __in  ID3D10ShaderResourceView *pShaderResourceView
   )                                                    ' void
   ' =====================================================================================
   METHOD ResolveSubresource ( _                        ' VTable offset = 152
     BYVAL pDstResource AS ID3D10Resource _             ' __in  ID3D10Resource *pDstResource
   , BYVAL DstSubresource AS DWORD _                    ' __in  UINT DstSubresource
   , BYVAL pSrcResource AS ID3D10Resource _             ' __in  ID3D10Resource *pSrcResource
   , BYVAL SrcSubresource AS DWORD _                    ' __in  UINT SrcSubresource
   , BYVAL Format As DWORD _                            ' __in  DXGI_FORMAT Format
   )                                                    ' void
   ' =====================================================================================
   METHOD VSGetConstantBuffers ( _                      ' VTable offset = 156
     BYVAL StartSlot AS DWORD _                         ' __in UINT StartSlot
   , BYVAL NumBuffers AS DWORD _                        ' __in UINT NumBuffers
   , BYREF ppConstantBuffers AS ID3D10Buffer _          ' __out ID3D10Buffer **ppConstantBuffers
   )                                                    ' void
   ' =====================================================================================
   METHOD PSGetShaderResources ( _                      ' VTable offset = 160
     BYVAL StartSlot AS DWORD _                         ' __in UINT StartSlot
   , BYVAL NumViews AS DWORD _                          ' __in UINT NumViews
   , BYREF ppShaderResourceViews AS ID3D10ShaderResourceView _ ' __out ID3D10ShaderResourceView **ppShaderResourceViews
   )                                                    ' void
   ' =====================================================================================
   METHOD PSGetShader ( _                               ' VTable offset = 164
     BYREF ppPixelShader AS ID3D10PixelShader _         ' __out  ID3D10PixelShader **ppPixelShader
   )                                                    ' void
   ' =====================================================================================
   METHOD PSGetSamplers ( _                             ' VTable offset = 168
     BYVAL StartSlot AS DWORD _                         ' __in UINT StartSlot
   , BYVAL NumSamplers AS DWORD _                       ' __in UINT NumSamplers
   , BYREF ppSamplers AS ID3D10SamplerState _           ' __out ID3D10SamplerState **ppSamplers
   )                                                    ' void
   ' =====================================================================================
   METHOD VSGetShader ( _                               ' VTable offset = 172
     BYREF ppVertexShader AS ID3D10VertexShader _       ' __out  ID3D10VertexShader **ppVertexShader
   )                                                    ' void
   ' =====================================================================================
   METHOD PSGetConstantBuffers ( _                      ' VTable offset = 176
     BYVAL StartSlot AS DWORD _                         ' __in UINT StartSlot
   , BYVAL NumBuffers AS DWORD _                        ' __in UINT NumBuffers
   , BYREF ppConstantBuffers AS ID3D10Buffer _          ' __out ID3D10Buffer **ppConstantBuffers
   )                                                    ' void
   ' =====================================================================================
   METHOD IAGetInputLayout ( _                          ' VTable offset = 180
     BYREF ppInputLayout AS ID3D10InputLayout _         ' __out  ID3D10InputLayout **ppInputLayout
   )                                                    ' void
   ' =====================================================================================
   METHOD IAGetVertexBuffers ( _                        ' VTable offset = 184
     BYVAL StartSlot AS DWORD _                         ' __in UINT StartSlot
   , BYVAL NumBuffers AS DWORD _                        ' __in UINT NumBuffers
   , BYREF ppVertexBuffers AS ID3D10Buffer _            ' __out ID3D10Buffer **ppVertexBuffers
   , BYREF pStrides AS DWORD _                          ' __out UINT *pStrides
   , BYREF pOffsets AS DWORD _                          ' __out UINT *pOffsets
   )                                                    ' void
   ' =====================================================================================
   METHOD IAGetIndexBuffer ( _                          ' VTable offset = 188
     BYREF pIndexBuffer AS ID3D10Buffer _               ' __out_opt  ID3D10Buffer **pIndexBuffer
   , BYREF Format AS DWORD _                            ' __out_opt  DXGI_FORMAT *Format
   , BYREF Offset AS DWORD _                            ' __out_opt  UINT *Offset
   )                                                    ' void
   ' =====================================================================================
   METHOD GSGetConstantBuffers ( _                      ' VTable offset = 192
     BYVAL StartSlot AS DWORD _                         ' __in UINT StartSlot
   , BYVAL NumBuffers AS DWORD _                        ' __in UINT NumBuffers
   , BYREF ppConstantBuffers AS ID3D10Buffer _          ' __out ID3D10Buffer **ppConstantBuffers
   )                                                    ' void
   ' =====================================================================================
   METHOD GSGetShader ( _                               ' VTable offset = 196
     BYREF ppGeometryShader AS ID3D10GeometryShader _   ' __out  ID3D10GeometryShader **ppGeometryShader
   )                                                    ' void
   ' =====================================================================================
   METHOD IAGetPrimitiveTopology ( _                    ' VTable offset = 200
     BYREF pTopology AS DWORD _                         ' __out  D3D10_PRIMITIVE_TOPOLOGY *pTopology
   )                                                    ' void
   ' =====================================================================================
   METHOD VSGetShaderResources ( _                      ' VTable offset = 204
     BYVAL StartSlot AS DWORD _                         ' __in UINT StartSlot
   , BYVAL NumViews AS DWORD _                          ' __in UINT NumViews
   , BYREF ppShaderResourceViews AS ID3D10ShaderResourceView _ ' __out ID3D10ShaderResourceView **ppShaderResourceViews
   )                                                    ' void
   ' =====================================================================================
   METHOD VSGetSamplers ( _                             ' VTable offset = 208
     BYVAL StartSlot AS DWORD _                         ' __in UINT StartSlot
   , BYVAL NumSamplers AS DWORD _                       ' __in UINT NumSamplers
   , BYREF ppSamplers AS ID3D10SamplerState _           ' __out ID3D10SamplerState **ppSamplers
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPredication ( _                            ' VTable offset = 212
     BYREF ppPredicate AS ID3D10Predicate _             ' __out_opt  ID3D10Predicate **ppPredicate
   , BYREF pPredicateValue AS LONG _                    ' __out_opt  BOOL *pPredicateValue
   )                                                    ' void
   ' =====================================================================================
   METHOD GSGetShaderResources ( _                      ' VTable offset = 216
     BYVAL StartSlot AS DWORD _                         ' __in UINT StartSlot
   , BYVAL NumViews AS DWORD _                          ' __in UINT NumViews
   , BYREF ppShaderResourceViews AS ID3D10ShaderResourceView _ ' __out ID3D10ShaderResourceView **ppShaderResourceViews
   )                                                    ' void
   ' =====================================================================================
   METHOD GSGetSamplers ( _                             ' VTable offset = 220
     BYVAL StartSlot AS DWORD _                         ' __in UINT StartSlot
   , BYVAL NumSamplers As DWORD _                       ' __in UINT NumSamplers
   , BYREF ppSamplers AS ID3D10SamplerState _           ' __out ID3D10SamplerState **ppSamplers
   )                                                    ' void
   ' =====================================================================================
   METHOD OMGetRenderTargets ( _                        ' VTable offset = 224
     BYVAL NumViews AS DWORD _                          ' __in UINT NumViews
   , BYREF ppRenderTargetViews AS ID3D10RenderTargetView _ ' __out ID3D10RenderTargetView **ppRenderTargetViews
   , BYREF ppDepthStencilView AS ID3D10DepthStencilView _  ' __out ID3D10DepthStencilView **ppDepthStencilView
   )                                                    ' void
   ' =====================================================================================
   METHOD OMGetBlendState ( _                           ' VTable offset = 228
     BYREF ppBlendState AS ID3D10BlendState _           ' __out_opt  ID3D10BlendState **ppBlendState
   , BYREF BlendFactor AS SINGLE _                      ' __out_opt  FLOAT BlendFactor[ 4 ]
   , BYREF pSampleMask AS DWORD _                       ' __out_opt  UINT *pSampleMask
   )                                                    ' void
   ' =====================================================================================
   METHOD OMGetDepthStencilState ( _                    ' VTable offset = 232
     BYREF ppDepthStencilState AS ID3D10DepthStencilState _ ' __out_opt  ID3D10DepthStencilState **ppDepthStencilState
   , BYREF pStencilRef AS DWORD _                       ' __out_opt  UINT *pStencilRef
   )                                                    ' void
   ' =====================================================================================
   METHOD SOGetTargets ( _                              ' VTable offset = 236
     BYVAL NumBuffers AS DWORD _                        ' __in UINT NumBuffers
   , BYREF ppSOTargets AS ID3D10Buffer _                ' __out ID3D10Buffer **ppSOTargets
   , BYREF pOffsets AS DWORD _                          ' __out UINT *pOffsets
   )                                                    ' void
   ' =====================================================================================
   METHOD RSGetState ( _                                ' VTable offset = 240
     BYREF ppRasterizerState AS ID3D10RasterizerState _ ' __out  ID3D10RasterizerState **ppRasterizerState
   )                                                    ' void
   ' =====================================================================================
   METHOD RSGetViewports ( _                            ' VTable offset = 244
     BYREF NumViewports AS DWORD _                      ' __inout  UINT *NumViewports
   , BYREF pViewports AS D3D10_VIEWPORT _               ' __out D3D10_VIEWPORT *pViewports
   )                                                    ' void
   ' =====================================================================================
   METHOD RSGetScissorRects ( _                         ' VTable offset = 248
     BYREF NumRects AS DWORD _                          ' __inout UINT *NumRects
   , BYREF pRects AS D3D10_RECT _                       ' __out D3D10_RECT *pRects
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDeviceRemovedReason ( _                    ' VTable offset = 252
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetExceptionMode ( _                          ' VTable offset = 256
     BYVAL RaiseFlags AS DWORD _                        ' __in UINT RaiseFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetExceptionMode ( _                          ' VTable offset = 260
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetPrivateData ( _                            ' VTable offset = 264
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYREF pDataSize AS DWORD _                         ' __inout  UINT *pDataSize
   , BYVAL pData AS DWORD _                             ' __out void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateData ( _                            ' VTable offset = 268
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYVAL DataSize AS DWORD _                          ' __in  UINT DataSize
   , BYVAL pData AS DWORD _                             ' __in  const void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateDataInterface ( _                   ' VTable offset = 272
     BYREF guid AS GUID _                               ' __in  REFGUID guid
   , BYVAL pData AS IUnknown _                          ' __in_opt  const IUnknown *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearState ( _                                ' VTable offset = 276
   )                                                    ' void
   ' =====================================================================================
   METHOD Flush ( _                                     ' VTable offset = 280
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateBuffer ( _                              ' VTable offset = 284
     BYREF pDesc AS D3D10_BUFFER_DESC _                 ' __in  const D3D10_BUFFER_DESC *pDesc
   , BYREF pInitialData AS D3D10_SUBRESOURCE_DATA _     ' __in_opt  const D3D10_SUBRESOURCE_DATA *pInitialData
   , BYREF ppBuffer AS ID3D10Buffer _                   ' __out_opt  ID3D10Buffer **ppBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateTexture1D ( _                           ' VTable offset = 288
     BYREF pDesc AS D3D10_TEXTURE1D_DESC _              ' __in  const D3D10_TEXTURE1D_DESC *pDesc
   , BYREF pInitialData AS D3D10_SUBRESOURCE_DATA _     ' __in D3D10_SUBRESOURCE_DATA *pInitialData
   , BYREF ppTexture1D AS ID3D10Texture1D _             ' __out  ID3D10Texture1D **ppTexture1D
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateTexture2D ( _                           ' VTable offset = 292
     BYREF pDesc AS D3D10_TEXTURE2D_DESC _              ' __in  const D3D10_TEXTURE2D_DESC *pDesc
   , BYREF pInitialData AS D3D10_SUBRESOURCE_DATA _     ' __in D3D10_SUBRESOURCE_DATA *pInitialData
   , BYREF ppTexture2D AS ID3D10Texture2D _             ' __out  ID3D10Texture2D **ppTexture2D
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateTexture3D ( _                           ' VTable offset = 296
     BYREF pDesc AS D3D10_TEXTURE3D_DESC _              ' __in  const D3D10_TEXTURE3D_DESC *pDesc
   , BYREF pInitialData AS D3D10_SUBRESOURCE_DATA _     ' __in D3D10_SUBRESOURCE_DATA *pInitialData
   , BYREF ppTexture3D AS ID3D10Texture3D _             ' __out  ID3D10Texture3D **ppTexture3D
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateShaderResourceView ( _                  ' VTable offset = 300
     BYVAL pResource AS ID3D10Resource _                ' __in  ID3D10Resource *pResource
   , BYREF pDesc AS D3D10_SHADER_RESOURCE_VIEW_DESC _   ' __in_opt  const D3D10_SHADER_RESOURCE_VIEW_DESC *pDesc
   , BYREF ppSRView AS ID3D10ShaderResourceView _       ' __out_opt  ID3D10ShaderResourceView **ppSRView
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRenderTargetView ( _                    ' VTable offset = 304
     BYVAL pResource AS ID3D10Resource _                ' __in  ID3D10Resource *pResource
   , BYREF pDesc AS D3D10_RENDER_TARGET_VIEW_DESC _     ' __in_opt  const D3D10_RENDER_TARGET_VIEW_DESC *pDesc
   , BYREF ppRTView AS ID3D10RenderTargetView _         ' __out_opt  ID3D10RenderTargetView **ppRTView
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDepthStencilView ( _                    ' VTable offset = 308
     BYVAL pResource AS ID3D10Resource _                ' __in  ID3D10Resource *pResource
   , BYREF pDesc AS D3D10_DEPTH_STENCIL_VIEW_DESC _     ' __in_opt  const D3D10_DEPTH_STENCIL_VIEW_DESC *pDesc
   , BYREF ppDepthStencilView AS ID3D10DepthStencilView _ ' __out_opt  ID3D10DepthStencilView **ppDepthStencilView
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateInputLayout ( _                         ' VTable offset = 312
     BYREF pInputElementDescs AS D3D10_INPUT_ELEMENT_DESC _ ' __in const D3D10_INPUT_ELEMENT_DESC *pInputElementDescs
   , BYVAL NumElements AS DWORD _                       ' __in UINT NumElements
   , BYVAL pShaderBytecodeWithInputSignature AS DWORD _ ' __in  const void *pShaderBytecodeWithInputSignature
   , BYVAL BytecodeLength AS DWORD _                    ' __in  SIZE_T BytecodeLength
   , BYREF ppInputLayout AS ID3D10InputLayout _         ' __out_opt  ID3D10InputLayout **ppInputLayout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateVertexShader ( _                        ' VTable offset = 316
     BYVAL pShaderBytecode AS DWORD _                   ' __in  const void *pShaderBytecode
   , BYVAL BytecodeLength AS DWORD _                    ' __in  SIZE_T BytecodeLength
   , BYREF ppVertexShader AS ID3D10VertexShader _       ' __out_opt  ID3D10VertexShader **ppVertexShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateGeometryShader ( _                      ' VTable offset = 320
     BYVAL pShaderBytecode AS DWORD _                   ' __in  const void *pShaderBytecode
   , BYVAL BytecodeLength AS DWORD _                    ' __in  SIZE_T BytecodeLength
   , BYREF ppGeometryShader AS ID3D10GeometryShader _   ' __out_opt  ID3D10GeometryShader **ppGeometryShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateGeometryShaderWithStreamOutput ( _      ' VTable offset = 324
     BYVAL pShaderBytecode AS DWORD _                   ' __in  const void *pShaderBytecode
   , BYVAL BytecodeLength AS DWORD _                    ' __in  SIZE_T BytecodeLength
   , BYREF pSODeclaration AS D3D10_SO_DECLARATION_ENTRY _ ' __in  const D3D10_SO_DECLARATION_ENTRY *pSODeclaration
   , BYVAL NumEntries AS DWORD _                        ' __in  UINT NumEntries
   , BYVAL OutputStreamStride AS DWORD _                ' __in  UINT OutputStreamStride
   , BYREF ppGeometryShader AS ID3D10GeometryShader _   ' __out_opt  ID3D10GeometryShader **ppGeometryShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePixelShader ( _                         ' VTable offset = 328
     BYVAL pShaderBytecode AS DWORD _                   ' __in  const void *pShaderBytecode
   , BYVAL BytecodeLength AS DWORD _                    ' __in  SIZE_T BytecodeLength
   , BYREF ppPixelShader AS ID3D10PixelShader _         ' __out_opt  ID3D10PixelShader **ppPixelShader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBlendState ( _                          ' VTable offset = 332
     BYREF pBlendStateDesc AS D3D10_BLEND_DESC _        ' __in  const D3D10_BLEND_DESC *pBlendStateDesc
   , BYREF ppBlendState AS ID3D10BlendState _           ' __out_opt  ID3D10BlendState **ppBlendState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDepthStencilState ( _                   ' VTable offset = 336
     BYREF pDepthStencilDesc AS D3D10_DEPTH_STENCIL_DESC _  ' __in  const D3D10_DEPTH_STENCIL_DESC *pDepthStencilDesc
   , BYREF ppDepthStencilState AS ID3D10DepthStencilState _ ' __out_opt  ID3D10DepthStencilState **ppDepthStencilState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRasterizerState ( _                     ' VTable offset = 340
     BYREF pRasterizerDesc AS D3D10_RASTERIZER_DESC _   ' __in  const D3D10_RASTERIZER_DESC *pRasterizerDesc
   , BYREF ppRasterizerState AS ID3D10RasterizerState _ ' __out_opt  ID3D10RasterizerState **ppRasterizerState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSamplerState ( _                        ' VTable offset = 344
     BYREF pSamplerDesc AS D3D10_SAMPLER_DESC _         ' __in  const D3D10_SAMPLER_DESC *pSamplerDesc
   , BYREF ppSamplerState AS ID3D10SamplerState _       ' __out_opt  ID3D10SamplerState **ppSamplerState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateQuery ( _                               ' VTable offset = 348
     BYREF pQueryDesc AS D3D10_QUERY_DESC _             ' __in  const D3D10_QUERY_DESC *pQueryDesc
   , BYREF ppQuery AS ID3D10Query _                     ' __out_opt  ID3D10Query **ppQuery
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePredicate ( _                           ' VTable offset = 352
     BYREF pPredicateDesc AS D3D10_QUERY_DESC _         ' __in  const D3D10_QUERY_DESC *pPredicateDesc
   , BYREF ppPredicate AS ID3D10Predicate _             ' __out_opt  ID3D10Predicate **ppPredicate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateCounter ( _                             ' VTable offset = 356
     BYREF pCounterDesc AS D3D10_COUNTER_DESC _         ' __in  const D3D10_COUNTER_DESC *pCounterDesc
   , BYREF ppCounter AS ID3D10Counter _                 ' __out_opt  ID3D10Counter **ppCounter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckFormatSupport ( _                        ' VTable offset = 360
     BYVAL Format AS DWORD _                            ' __in  DXGI_FORMAT Format
   , BYREF pFormatSupport AS DWORD _                    ' __out  UINT *pFormatSupport
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckMultisampleQualityLevels ( _             ' VTable offset = 364
     BYVAL Format AS DWORD _                            ' __in  DXGI_FORMAT Format
   , BYVAL SampleCount AS DWORD _                       ' __in  UINT SampleCount
   , BYREF pNumQualityLevels AS DWORD _                 ' __out  UINT *pNumQualityLevels
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckCounterInfo ( _                          ' VTable offset = 368
     BYREF pCounterInfo AS D3D10_COUNTER_INFO _         ' __out  D3D10_COUNTER_INFO *pCounterInfo
   )                                                    ' void
   ' =====================================================================================
   METHOD CheckCounter ( _                              ' VTable offset = 372
     BYREF pDesc AS D3D10_COUNTER_DESC _                ' __in  const D3D10_COUNTER_DESC *pDesc
   , BYREF pType AS DWORD _                             ' __out D3D10_COUNTER_TYPE *pType
   , BYREF pActiveCounters AS DWORD _                   ' __out UINT *pActiveCounters
   , BYREF szName AS ASCIIZ _                           ' __out LPSTR szName
   , BYREF pNameLength AS DWORD _                       ' __inout_opt UINT *pNameLength
   , BYREF szUnits AS ASCIIZ _                          ' __out LPSTR szUnits
   , BYREF pUnitsLength AS DWORD _                      ' __inout_opt UINT *pUnitsLength
   , BYREF szDescription AS ASCIIZ _                    ' __out LPSTR szDescription
   , BYREF pDescriptionLength AS DWORD _                ' __inout_opt UINT *pDescriptionLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCreationFlags ( _                          ' VTable offset = 376
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD OpenSharedResource ( _                        ' VTable offset = 380
     BYVAL hResource AS DWORD _                         ' __in  HANDLE hResource
   , BYREF ReturnedInterface AS GUID _                  ' __in  REFIID ReturnedInterface
   , BYREF ppResource AS IUnknown _                     ' __out_opt  void **ppResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTextFilterSize ( _                         ' VTable offset = 384
     BYVAL Width AS DWORD _                             ' __in  UINT Width
   , BYVAL Height AS DWORD _                            ' __in  UINT Height
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTextFilterSize ( _                         ' VTable offset = 388
     BYREF pWidth AS DWORD _                            ' __out_opt  UINT *pWidth
   , BYREF pHeight AS DWORD _                           ' __out_opt  UINT *pHeight
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10Device_INTERFACE_DEFINED__ */

' ########################################################################################
' ID3D10Multithread interface
' IID = 9B7E4E00-342C-4106-A19F-4F2704F689F0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ID3D10Multithread_INTERFACE_DEFINED)
    %ID3D10Multithread_INTERFACE_DEFINED = 1

INTERFACE ID3D10Multithread $IID_ID3D10Multithread

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Enter ( _                                     ' VTable offset = 12
   )                                                    ' void
   ' =====================================================================================
   METHOD Leave ( _                                     ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   METHOD SetMultithreadProtected ( _                   ' VTable offset = 20
     BYVAL bMTProtect AS LONG _                         ' __in  BOOL bMTProtect
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD GetMultithreadProtected ( _                   ' VTable offset = 24
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10Multithread_INTERFACE_DEFINED__ */


' enum D3D10_CREATE_DEVICE_FLAG
%D3D10_CREATE_DEVICE_SINGLETHREADED                           = &H1???
%D3D10_CREATE_DEVICE_DEBUG                                    = &H2???
%D3D10_CREATE_DEVICE_SWITCH_TO_REF                            = &H4???
%D3D10_CREATE_DEVICE_PREVENT_INTERNAL_THREADING_OPTIMIZATIONS = &H8???
%D3D10_CREATE_DEVICE_ALLOW_NULL_FROM_MAP                      = &H10???
%D3D10_CREATE_DEVICE_BGRA_SUPPORT                             = &H20???
%D3D10_CREATE_DEVICE_STRICT_VALIDATION                        = &H200???


%D3D10_SDK_VERSION = 29

#IF NOT %DEF(%D3D10_IGNORE_SDK_LAYERS)
#INCLUDE ONCE "d3d10sdklayers.inc"
#ENDIF

#INCLUDE ONCE "d3d10misc.inc"
#INCLUDE ONCE "d3d10shader.inc"
#INCLUDE ONCE "d3d10effect.inc"
