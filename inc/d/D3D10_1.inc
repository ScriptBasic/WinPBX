' ########################################################################################
' Microsoft Windows
' File: D3D10_1.inc
' Contents: Error code definitions for the background file copier
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE

' // The %D3D10_1_INC constant is checked in D3D10_1.inc
#IF NOT %DEF(%D3D10_1_INC)
%D3D10_1_INC = 1
#ENDIF

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

'#if defined( __d3d10_h__ ) && !defined( D3D10_ARBITRARY_HEADER_ORDERING )
'#error d3d10.h is included before d3d10_1.h, and it will confuse tools that honor SAL annotations. \
'If possibly targeting d3d10.1, include d3d10_1.h instead of d3d10.h, or ensure d3d10_1.h is included before d3d10.h
'#endif

$IID_ID3D10BlendState1         = GUID$("{EDAD8D99-8A35-4D6D-8566-2EA276CDE161}")
$IID_ID3D10ShaderResourceView1 = GUID$("{9B7E4C87-342C-4106-A19F-4F2704F689F0}")
$IID_ID3D10Device1             = GUID$("{9B7E4C8F-342C-4106-A19F-4F2704F689F0}")

#IF NOT %DEF(%D3D10_1_CONSTANTS)
%D3D10_1_CONSTANTS = 1

%D3D10_1_DEFAULT_SAMPLE_MASK   = &Hffffffff???

MACRO D3D10_1_FLOAT16_FUSED_TOLERANCE_IN_ULP      = 0.6!
MACRO D3D10_1_FLOAT32_TO_INTEGER_TOLERANCE_IN_ULP = 0.6!

%D3D10_1_GS_INPUT_REGISTER_COUNT                       = 32
' %D3D10_1_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT is defined with a different value in D3D10.inc
#IF NOT %DEF(%D3D10_1_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT)
%D3D10_1_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT           = 32
#ENDIF
%D3D10_1_IA_VERTEX_INPUT_STRUCTURE_ELEMENTS_COMPONENTS = 128
' %D3D10_1_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT is defined with a different value in D3D10.inc
#IF NOT %DEF(%D3D10_1_IA_VERTEX_INPUT_STRUCTURE_ELEMENT_COUNT)
%D3D10_1_IA_VERTEX_INPUT_STRUCTURE_ELEMENT_COUNT       = 32
#ENDIF
%D3D10_1_PS_OUTPUT_MASK_REGISTER_COMPONENTS            = 1
%D3D10_1_PS_OUTPUT_MASK_REGISTER_COMPONENT_BIT_COUNT   = 32
%D3D10_1_PS_OUTPUT_MASK_REGISTER_COUNT                 = 1
%D3D10_1_SHADER_MAJOR_VERSION                          = 4
%D3D10_1_SHADER_MINOR_VERSION                          = 1
%D3D10_1_SO_BUFFER_MAX_STRIDE_IN_BYTES                 = 2048
%D3D10_1_SO_BUFFER_MAX_WRITE_WINDOW_IN_BYTES           = 256
%D3D10_1_SO_BUFFER_SLOT_COUNT                          = 4
%D3D10_1_SO_MULTIPLE_BUFFER_ELEMENTS_PER_BUFFER        = 1
%D3D10_1_SO_SINGLE_BUFFER_COMPONENT_LIMIT              = 64
%D3D10_1_STANDARD_VERTEX_ELEMENT_COUNT                 = 32
%D3D10_1_SUBPIXEL_FRACTIONAL_BIT_COUNT                 = 8
%D3D10_1_VS_INPUT_REGISTER_COUNT                       = 32
%D3D10_1_VS_OUTPUT_REGISTER_COUNT                      = 32

#ENDIF   ' #IF NOT %DEF(%D3D10_1_CONSTANTS)

#INCLUDE ONCE "d3d10.inc"

' enum D3D10_FEATURE_LEVEL1
%D3D10_FEATURE_LEVEL_10_0 = &Ha000???
%D3D10_FEATURE_LEVEL_10_1 = &Ha100???
%D3D10_FEATURE_LEVEL_9_1  = &H9100???
%D3D10_FEATURE_LEVEL_9_2  = &H9200???
%D3D10_FEATURE_LEVEL_9_3  = &H9300???

' // Size = 32 bytes
TYPE D3D10_RENDER_TARGET_BLEND_DESC1 DWORD
   BlendEnable           AS LONG    ' BOOL
   SrcBlend              AS DWORD   ' D3D10_BLEND
   DestBlend             AS DWORD   ' D3D10_BLEND
   BlendOp               AS DWORD   ' D3D10_BLEND
   SrcBlendAlpha         AS DWORD   ' D3D10_BLEND
   DestBlendAlpha        AS DWORD   ' D3D10_BLEND
   BlendOpAlpha          AS DWORD   ' D3D10_BLEND
   RenderTargetWriteMask AS BYTE    ' UINT8
END TYPE

' // Size = 264 bytes
TYPE D3D10_BLEND_DESC1 DWORD
   AlphaToCoverageEnable  AS LONG   ' BOOL
   IndependentBlendEnable AS LONG   ' BOOL
   RenderTarget(7) AS D3D10_RENDER_TARGET_BLEND_DESC1
END TYPE


' ########################################################################################
' ID3D10BlendState1 interface
' IID = EDAD8D99-8A35-4D6D-8566-2EA276CDE161
' Inherited interface = ID3D10BlendState
' ########################################################################################

#IF NOT %DEF(%ID3D10BlendState1_INTERFACE_DEFINED)
    %ID3D10BlendState1_INTERFACE_DEFINED = 1

INTERFACE ID3D10BlendState1 $IID_ID3D10BlendState1

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

   ' =====================================================================================
   ' ID3D10BlendState Method
   ' =====================================================================================
   METHOD GetDesc1 ( _                                  ' VTable offset = 32
     BYREF pDesc AS D3D10_BLEND_DESC1 _                 ' __out  D3D10_BLEND_DESC1 *pDesc
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10BlendState1_INTERFACE_DEFINED__ */


' // Size = 16 bytes
TYPE D3D10_TEXCUBE_ARRAY_SRV1 DWORD
   MostDetailedMip  AS DWORD   ' UINT
   MipLevels        AS DWORD   ' UINT
   First2DArrayFace AS DWORD   ' UINT
   NumCubes         AS DWORD   ' UINT
END TYPE

' enum D3D10_SRV_DIMENSION1
%D3D10_1_SRV_DIMENSION_UNKNOWN          = 0
%D3D10_1_SRV_DIMENSION_BUFFER           = 1
%D3D10_1_SRV_DIMENSION_TEXTURE1D        = 2
%D3D10_1_SRV_DIMENSION_TEXTURE1DARRAY   = 3
%D3D10_1_SRV_DIMENSION_TEXTURE2D        = 4
%D3D10_1_SRV_DIMENSION_TEXTURE2DARRAY   = 5
%D3D10_1_SRV_DIMENSION_TEXTURE2DMS      = 6
%D3D10_1_SRV_DIMENSION_TEXTURE2DMSARRAY = 7
%D3D10_1_SRV_DIMENSION_TEXTURE3D        = 8
%D3D10_1_SRV_DIMENSION_TEXTURECUBE      = 9
%D3D10_1_SRV_DIMENSION_TEXTURECUBEARRAY = 10

' // Size = 16 bytes
UNION D3D10_SHADER_RESOURCE_VIEW_DESC1_UNION DWORD
   Buffer           AS D3D10_BUFFER_SRV
   Texture1D        AS D3D10_TEX1D_SRV
   Texture1DArray   AS D3D10_TEX1D_ARRAY_SRV
   Texture2D        AS D3D10_TEX2D_SRV
   Texture2DArray   AS D3D10_TEX2D_ARRAY_SRV
   Texture2DMS      AS D3D10_TEX2DMS_SRV
   Texture2DMSArray AS D3D10_TEX2DMS_ARRAY_SRV
   Texture3D        AS D3D10_TEX3D_SRV
   TextureCube      AS D3D10_TEXCUBE_SRV
   TextureCubeArray AS D3D10_TEXCUBE_ARRAY_SRV1
END UNION

' // Size = 24 bytes
TYPE D3D10_SHADER_RESOURCE_VIEW_DESC1 DWORD
   Format        AS DWORD   ' DXGI_FORMAT
   ViewDimension AS DWORD   ' D3D10_SRV_DIMENSION1
   D3D10_SHADER_RESOURCE_VIEW_DESC1_UNION
END TYPE


' ########################################################################################
' ID3D10ShaderResourceView1 interface
' IID = 9B7E4C87-342C-4106-A19F-4F2704F689F0
' Inherited interface = ID3D10ShaderResourceView
' ########################################################################################

#IF NOT %DEF(%ID3D10ShaderResourceView1_INTERFACE_DEFINED)
    %ID3D10ShaderResourceView1_INTERFACE_DEFINED = 1

INTERFACE ID3D10ShaderResourceView1 $IID_ID3D10ShaderResourceView1

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

   ' =====================================================================================
   ' ID3D10ShaderResourceView1 Method
   ' =====================================================================================
   METHOD GetDesc1 ( _                                  ' VTable offset = 32
     BYREF pDesc AS D3D10_SHADER_RESOURCE_VIEW_DESC1 _  ' __out  D3D10_SHADER_RESOURCE_VIEW_DESC1 *pDesc
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10ShaderResourceView1_INTERFACE_DEFINED__ */


' enum D3D10_STANDARD_MULTISAMPLE_QUALITY_LEVELS
%D3D10_STANDARD_MULTISAMPLE_PATTERN = &Hffffffff???
%D3D10_CENTER_MULTISAMPLE_PATTERN   = &Hfffffffe???


' ########################################################################################
' ID3D10Device1 interface
' IID = 9B7E4C8F-342C-4106-A19F-4F2704F689F0
' Inherited interface = ID3D10Device
' ########################################################################################

#IF NOT %DEF(%ID3D10Device1_INTERFACE_DEFINED)
    %ID3D10Device1_INTERFACE_DEFINED = 1

INTERFACE ID3D10Device1 $IID_ID3D10Device1

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3D10Device Methods
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

   ' =====================================================================================
   ' ID3D10Device1 Methods
   ' =====================================================================================
   METHOD CreateShaderResourceView1 ( _                 ' VTable offset = 392
     BYVAL pResource AS ID3D10Resource _                ' __in  ID3D10Resource *pResource
   , BYREF pDesc AS D3D10_SHADER_RESOURCE_VIEW_DESC1 _  ' __in_opt  const D3D10_SHADER_RESOURCE_VIEW_DESC1 *pDesc
   , BYREF ppSRView AS ID3D10ShaderResourceView1 _      ' __out_opt  ID3D10ShaderResourceView1 **ppSRView
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBlendState1 ( _                         ' VTable offset = 396
     BYREF pBlendStateDesc AS D3D10_BLEND_DESC1 _       ' __in  const D3D10_BLEND_DESC1 *pBlendStateDesc
   , BYREF ppBlendState AS ID3D10BlendState1 _          ' __out_opt  ID3D10BlendState1 **ppBlendState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFeatureLevel ( _                           ' VTable offset = 400
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3D10Device1_INTERFACE_DEFINED__ */


%D3D10_1_SDK_VERSION   = 0 + &H20

#INCLUDE ONCE "d3d10_1shader.inc"

'///////////////////////////////////////////////////////////////////////////
'// D3D10CreateDevice1
'// ------------------
'//
'// pAdapter
'//      If NULL, D3D10CreateDevice1 will choose the primary adapter and
'//      create a new instance from a temporarily created IDXGIFactory.
'//      If non-NULL, D3D10CreateDevice1 will register the appropriate
'//      device, if necessary (via IDXGIAdapter::RegisterDrver), before
'//      creating the device.
'// DriverType
'//      Specifies the driver type to be created: hardware, reference or
'//      null.
'// Software
'//      HMODULE of a DLL implementing a software rasterizer. Must be NULL for
'//      non-Software driver types.
'// Flags
'//      Any of those documented for D3D10CreateDeviceAndSwapChain1.
'// HardwareLevel
'//      Any of those documented for D3D10CreateDeviceAndSwapChain1.
'// SDKVersion
'//      SDK version. Use the D3D10_1_SDK_VERSION macro.
'// ppDevice
'//      Pointer to returned interface.
'//
'// Return Values
'//  Any of those documented for
'//          CreateDXGIFactory
'//          IDXGIFactory::EnumAdapters
'//          IDXGIAdapter::RegisterDriver
'//          D3D10CreateDevice1
'//
'///////////////////////////////////////////////////////////////////////////

'typedef HRESULT (WINAPI* PFN_D3D10_CREATE_DEVICE1)(IDXGIAdapter *,
'    D3D10_DRIVER_TYPE, HMODULE, UINT, D3D10_FEATURE_LEVEL1, UINT, ID3D10Device1**);

DECLARE FUNCTION D3D10CreateDevice1 IMPORT "D3D10.DLL" ALIAS "D3D10CreateDevice1" ( _
   BYVAL pAdapter AS IDXGIAdapter _                     ' __in  IDXGIAdapter *pAdapter
 , BYVAL DriverType AS DWORD _                          ' __in  D3D10_DRIVER_TYPE DriverType
 , BYVAL Software AS DWORD _                            ' __in  HMODULE Software
 , BYVAL Flags AS DWORD _                               ' __in  UINT Flags
 , BYVAL HardwareLevel AS DWORD _                       ' __in  D3D10_FEATURE_LEVEL1 HardwareLevel
 , BYVAL SDKVersion AS DWORD _                          ' __in  UINT SDKVersion
 , BYREF ppDevice AS ID3D10Device1 _                    ' __out ID3D10Device1 **ppDevice
 ) AS LONG                                              ' HRESULT

'///////////////////////////////////////////////////////////////////////////
'// D3D10CreateDeviceAndSwapChain1
'// ------------------------------
'//
'// ppAdapter
'//      If NULL, D3D10CreateDevice1 will choose the primary adapter and
'//      create a new instance from a temporarily created IDXGIFactory.
'//      If non-NULL, D3D10CreateDevice1 will register the appropriate
'//      device, if necessary (via IDXGIAdapter::RegisterDrver), before
'//      creating the device.
'// DriverType
'//      Specifies the driver type to be created: hardware, reference or
'//      null.
'// Software
'//      HMODULE of a DLL implementing a software rasterizer. Must be NULL for
'//      non-Software driver types.
'// Flags
'//      Any of those documented for D3D10CreateDevice1.
'// HardwareLevel
'//      Any of:
'//          D3D10_CREATE_LEVEL_10_0
'//          D3D10_CREATE_LEVEL_10_1
'// SDKVersion
'//      SDK version. Use the D3D10_1_SDK_VERSION macro.
'// pSwapChainDesc
'//      Swap chain description, may be NULL.
'// ppSwapChain
'//      Pointer to returned interface. May be NULL.
'// ppDevice
'//      Pointer to returned interface.
'//
'// Return Values
'//  Any of those documented for
'//          CreateDXGIFactory
'//          IDXGIFactory::EnumAdapters
'//          IDXGIAdapter::RegisterDriver
'//          D3D10CreateDevice1
'//          IDXGIFactory::CreateSwapChain
'//
'///////////////////////////////////////////////////////////////////////////

'typedef HRESULT (WINAPI* PFN_D3D10_CREATE_DEVICE_AND_SWAP_CHAIN1)(IDXGIAdapter *,
'    D3D10_DRIVER_TYPE, HMODULE, UINT, D3D10_FEATURE_LEVEL1, UINT, DXGI_SWAP_CHAIN_DESC *, IDXGISwapChain **, ID3D10Device1 **);

DECLARE FUNCTION D3D10CreateDeviceAndSwapChain1 IMPORT "D3D10.DLL" ALIAS "D3D10CreateDeviceAndSwapChain1" ( _
   BYVAL pAdapter AS IDXGIAdapter _                     ' __in  IDXGIAdapter *pAdapter
 , BYVAL DriverType AS DWORD _                          ' __in  D3D10_DRIVER_TYPE DriverType
 , BYVAL Software AS DWORD _                            ' __in  HMODULE Software
 , BYVAL Flags AS DWORD _                               ' __in  UINT Flags
 , BYVAL HardwareLevel AS DWORD _                       ' __in  D3D10_FEATURE_LEVEL1 HardwareLevel
 , BYVAL SDKVersion AS DWORD _                          ' __in  UINT SDKVersion
 , BYREF pSwapChainDesc AS DXGI_SWAP_CHAIN_DESC _       ' __in  DXGI_SWAP_CHAIN_DESC *pSwapChainDesc
 , BYREF ppSwapChain AS IDXGISwapChain _                ' __out IDXGISwapChain **ppSwapChain
 , BYREF ppDevice AS ID3D10Device1 _                    ' __out ID3D10Device1 **ppDevice
 ) AS LONG                                              ' HRESULT
