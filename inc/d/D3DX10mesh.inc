' ########################################################################################
' Microsoft Windows
' File: d3dx10mesh.inc
' Contents: D3DX10 mesh types and functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3DX10MESH_INC = 1

#INCLUDE ONCE "d3dx10.inc"

$IID_ID3DX10BaseMesh   = GUID$("{7ED943DD-52E8-40B5-A8D8-76685C406330}")
$IID_ID3DX10MeshBuffer = GUID$("{04B0D117-1041-46B1-AA8A-3952848BA22E}")
$IID_ID3DX10Mesh       = GUID$("{4020E5C2-1403-4929-883F-E2E849FAC195}")
$IID_ID3DX10PMesh      = GUID$("{8875769A-D579-4088-AAEB-534D1AD84E96}")
$IID_ID3DX10SPMesh     = GUID$("{667EA4C7-F1CD-4386-B523-7C0290B83CC5}")
$IID_ID3DX10PatchMesh  = GUID$("{3CE6CC22-DBF2-44f4-894D-F9C34A337139}")


'// Mesh options - lower 3 bytes only, upper byte used by D3DX10MESHOPT option flags
' enum D3DX10_MESH
%D3DX10_MESH_32_BIT       = &H001???   ' // If set, then use 32 bit indices, if not set use 16 bit indices.
%D3DX10_MESH_GS_ADJACENCY = &H004???   ' // If set, mesh contains GS adjacency info. Not valid on input.

' // Size = 20 bytes
TYPE D3DX10_ATTRIBUTE_RANGE DWORD
   AttribId    AS DWORD   ' UINT
   FaceStart   AS DWORD   ' UINT
   FaceCount   AS DWORD   ' UINT
   VertexStart AS DWORD   ' UINT
   VertexCount AS DWORD   ' UINT
END TYPE

' enum D3DX10_MESH_DISCARD_FLAGS
%D3DX10_MESH_DISCARD_ATTRIBUTE_BUFFER = &H01???
%D3DX10_MESH_DISCARD_ATTRIBUTE_TABLE  = &H02???
%D3DX10_MESH_DISCARD_POINTREPS        = &H04???
%D3DX10_MESH_DISCARD_ADJACENCY        = &H08???
%D3DX10_MESH_DISCARD_DEVICE_BUFFERS   = &H10???

' // Size = 68 bytes
TYPE D3DX10_WELD_EPSILONS DWORD
   Position     AS SINGLE   ' FLOAT // NOTE: This does NOT replace the epsilon in GenerateAdjacency
                            ' // in general, it should be the same value or greater than the one passed to GeneratedAdjacency
   BlendWeights AS SINGLE   ' FLOAT
   Normal       AS SINGLE   ' FLOAT
   PSize        AS SINGLE   ' FLOAT
   Specular     AS SINGLE   ' FLOAT
   Diffuse      AS SINGLE   ' FLOAT
   Texcoord(7)  AS SINGLE   ' FLOAT
   Tangent      AS SINGLE   ' FLOAT
   Binormal     AS SINGLE   ' FLOAT
   TessFactor   AS SINGLE   ' FLOAT
END TYPE

' // Size = 16 bytes
TYPE D3DX10_INTERSECT_INFO DWORD
   FaceIndex AS DWORD    ' UINT // index of face intersected
   U         AS SINGLE   ' FLOAT // Barycentric Hit Coordinates
   V         AS SINGLE   ' FLOAT // Barycentric Hit Coordinates
   Dist      AS SINGLE   ' FLOAT // Ray-Intersection Parameter Distance
END TYPE

'// ID3DX10MeshBuffer is used by D3DX10Mesh vertex and index buffers

' ########################################################################################
' ID3DX10MeshBuffer interface
' IID = 04B0D117-1041-46B1-AA8A-3952848BA22E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ID3DX10MeshBuffer_INTERFACE_DEFINED)
    %ID3DX10MeshBuffer_INTERFACE_DEFINED = 1

INTERFACE ID3DX10MeshBuffer $IID_ID3DX10MeshBuffer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Map ( _                                       ' VTable offset = 12
     BYREF pData AS DWORD _                             ' __out void **pData
   , BYREF pSize AS DWORD _                             ' __out SIZE_T *pSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unmap ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 20
   ) AS DWORD                                           ' SIZE_T
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3DX10MeshBuffer_INTERFACE_DEFINED__ */

'// D3DX10 Mesh interfaces

' ########################################################################################
' ID3DX10Mesh interface
' IID = 04B0D117-1041-46B1-AA8A-3952848BA22E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ID3DX10Mesh_INTERFACE_DEFINED)
    %ID3DX10Mesh_INTERFACE_DEFINED = 1

INTERFACE ID3DX10Mesh $IID_ID3DX10Mesh

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFaceCount ( _                              ' VTable offset = 12
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetVertexCount ( _                            ' VTable offset = 16
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetVertexBufferCount ( _                      ' VTable offset = 20
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 24
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetVertexDescription ( _                      ' VTable offset = 28
     BYREF ppDesc AS D3D10_INPUT_ELEMENT_DESC _         ' __out CONST D3D10_INPUT_ELEMENT_DESC **ppDesc
   , BYREF pDeclCount AS DWORD _                        ' __out UINT *pDeclCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVertexData ( _                             ' VTable offset = 32
     BYVAL iBuffer AS DWORD _                           ' __in UINT iBuffer
   , BYVAL pData AS DWORD _                             ' __in CONST void *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVertexBuffer ( _                           ' VTable offset = 36
     BYVAL iBuffer AS DWORD _                           ' __in  UINT iBuffer
   , BYREF ppVertexBuffer AS ID3DX10MeshBuffer _        ' __out ID3DX10MeshBuffer **ppVertexBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAttributeData ( _                          ' VTable offset = 40
     BYVAL pData AS DWORD _                             ' __in CONST UINT *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttributeBuffer ( _                        ' VTable offset = 44
     BYREF ppAttributeBuffer AS ID3DX10MeshBuffer _     ' __out ID3DX10MeshBuffer **ppAttributeBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAttributeTable ( _                         ' VTable offset = 48
     BYREF pAttribTable AS D3DX10_ATTRIBUTE_RANGE _     ' __in D3DX10_ATTRIBUTE_RANGE *pAttribTable
   , BYVAL cAttribTableSize AS DWORD _                  ' __in UINT cAttribTableSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttributeTable ( _                         ' VTable offset = 52
     BYREF pAttribTable AS D3DX10_ATTRIBUTE_RANGE _     ' __in_out D3DX10_ATTRIBUTE_RANGE *pAttribTable
   , BYREF pAttribTableSize AS DWORD _                  ' __in_out UINT *pAttribTableSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GenerateAdjacencyAndPointReps ( _             ' VTable offset = 56
     BYVAL Epsilon AS SINGLE _                          ' __in FLOAT Epsilon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GenerateGSAdjacency ( _                       ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAdjacencyData ( _                          ' VTable offset = 64
     BYREF pAdjacency AS DWORD _                        ' __in CONST UINT *pAdjacency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAdjacencyBuffer ( _                        ' VTable offset = 68
     BYREF ppAdjacency AS ID3DX10MeshBuffer _           ' __out ID3DX10MeshBuffer **ppAdjacency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPointRepData ( _                           ' VTable offset = 72
     BYREF pPointReps AS DWORD _                        ' __in CONST UINT *pPointReps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPointRepBuffer ( _                         ' VTable offset = 76
     BYREF ppPointReps AS ID3DX10MeshBuffer _           ' __out ID3DX10MeshBuffer **ppPointReps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Discard ( _                                   ' VTable offset = 80
     BYVAL dwDiscard AS DWORD _                         ' __in D3DX10_MESH_DISCARD_FLAGS dwDiscard
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloneMesh ( _                                 ' VTable offset = 84
     BYVAL Flags AS DWORD _                             ' __in  UINT Flags
   , BYREF pPosSemantic AS ASCIIZ _                     ' __in  LPCSTR pPosSemantic
   , BYREF pDesc AS D3D10_INPUT_ELEMENT_DESC _          ' __in  CONST D3D10_INPUT_ELEMENT_DESC *pDesc
   , BYVAL DeclCount AS DWORD _                         ' __in  UINT DeclCount
   , BYREF ppCloneMesh AS ID3DX10Mesh _                 ' __out ID3DX10Mesh** ppCloneMesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Optimize ( _                                  ' VTable offset = 88
     BYVAL Flags AS DWORD _                             ' __in  UINT Flags
   , BYREF pFaceRemap AS DWORD _                        ' __in  UINT * pFaceRemap
   , BYVAL ppVertexRemap AS ID3D10Blob _                ' __out LPD3D10BLOB *ppVertexRemap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GenerateAttributeBufferFromTable ( _          ' VTable offset = 92
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Intersect ( _                                 ' VTable offset = 96
     BYREF pRayPos AS D3DXVECTOR3 _                     ' __in  D3DXVECTOR3 *pRayPos
   , BYREF pRayDir AS D3DXVECTOR3 _                     ' __in  D3DXVECTOR3 *pRayDir
   , BYREF pHitCount AS DWORD _                         ' __in  UINT *pHitCount
   , BYREF pFaceIndex AS DWORD _                        ' __in  UINT *pFaceIndex
   , BYREF pU AS SINGLE _                               ' __in  float *pU
   , BYREF pV AS SINGLE _                               ' __in  float *pV
   , BYREF pDist AS SINGLE _                            ' __in  float *pDist
   , BYREF ppAllHits AS ID3D10Blob _                    ' __out ID3D10Blob **ppAllHits
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IntersectSubset ( _                           ' VTable offset = 100
     BYREF pRayPos AS D3DXVECTOR3 _                     ' __in  D3DXVECTOR3 *pRayPos
   , BYREF pRayDir AS D3DXVECTOR3 _                     ' __in  D3DXVECTOR3 *pRayDir
   , BYREF pHitCount AS DWORD _                         ' __in  UINT *pHitCount
   , BYREF pFaceIndex AS DWORD _                        ' __in  UINT *pFaceIndex
   , BYREF pU AS SINGLE _                               ' __in  float *pU
   , BYREF pV AS SINGLE _                               ' __in  float *pV
   , BYREF pDist AS SINGLE _                            ' __in  float *pDist
   , BYREF ppAllHits AS ID3D10Blob _                    ' __out ID3D10Blob **ppAllHits
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CommitToDevice ( _                            ' VTable offset = 104
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DrawSubset ( _                                ' VTable offset = 108
     BYVAL AttribId AS DWORD _                          ' __in UINT AttribId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DrawSubsetInstanced ( _                       ' VTable offset = 112
     BYVAL AttribId AS DWORD _                          ' __in UINT AttribId
   , BYVAL InstanceCount AS DWORD _                     ' __in UINT InstanceCount
   , BYVAL StartInstanceLocation AS DWORD _             ' __in UINT StartInstanceLocation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceVertexBuffer ( _                     ' VTable offset = 116
     BYVAL iBuffer AS DWORD _                           ' __in  UINT iBuffer
   , BYREF ppVertexBuffer AS ID3D10Buffer _             ' __out ID3D10Buffer **ppVertexBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceIndexBuffer ( _                      ' VTable offset = 120
     BYVAL iBuffer AS DWORD _                           ' __in  UINT iBuffer
   , BYREF ppIndexBuffer AS ID3D10Buffer _              ' __out ID3D10Buffer **ppIndexBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3DX10Mesh_INTERFACE_DEFINED__ */


'// Flat API

DECLARE FUNCTION D3DX10CreateMesh IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateMesh" ( _
   BYVAL pDevice AS ID3D10Device _                      ' __in  ID3D10Device *pDevice
 , BYREF pDeclaration AS D3D10_INPUT_ELEMENT_DESC _     ' __in  CONST D3D10_INPUT_ELEMENT_DESC *pDeclaration
 , BYVAL DeclCount AS DWORD _                           ' __in  UINT  DeclCount
 , BYREF pPositionSemantic AS ASCIIZ _                  ' __in  LPCSTR pPositionSemantic
 , BYVAL VertexCount AS DWORD _                         ' __in  UINT  VertexCount
 , BYVAL FaceCount AS DWORD _                           ' __in  UINT  FaceCount
 , BYVAL Options AS DWORD _                             ' __in  UINT  Options
 , BYREF ppMesh AS ID3DX10Mesh _                        ' __out ID3DX10Mesh **ppMesh
 ) AS LONG                                              ' HRESULT


'// ID3DX10Mesh::Optimize options - upper byte only, lower 3 bytes used from _D3DX10MESH option flags
' enum D3DX10_MESHOPT
%D3DX10_MESHOPT_COMPACT            = &H01000000???
%D3DX10_MESHOPT_ATTR_SORT          = &H02000000???
%D3DX10_MESHOPT_VERTEX_CACHE       = &H04000000???
%D3DX10_MESHOPT_STRIP_REORDER      = &H08000000???
%D3DX10_MESHOPT_IGNORE_VERTS       = &H10000000???   ' // optimize faces only, don't touch vertices
%D3DX10_MESHOPT_DO_NOT_SPLIT       = &H20000000???   ' // do not split vertices shared between attribute groups when attribute sorting
%D3DX10_MESHOPT_DEVICE_INDEPENDENT = &H00400000???   ' // Only affects VCache.  uses a static known good cache size for all cards

'// D3DX10_MESHOPT_SHAREVB has been removed, please use D3DX10MESH_VB_SHARE instead


' ########################################################################################
' ID3DX10SkinInfo interface
' IID = 420BD604-1C76-4A34-A466-E45D0658A32C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ID3DX10SkinInfo_INTERFACE_DEFINED)
    %ID3DX10SkinInfo_INTERFACE_DEFINED = 1

$IID_ID3DX10SkinInfo = GUID$("{420BD604-1C76-4A34-A466-E45D0658A32C}")

'// scaling modes for ID3DX10SkinInfo::Compact() & ID3DX10SkinInfo::UpdateMesh()
%D3DX10_SKININFO_NO_SCALING     = 0
%D3DX10_SKININFO_SCALE_TO_1     = 1
%D3DX10_SKININFO_SCALE_TO_TOTAL = 2

' // Size = 12 bytes
TYPE D3DX10_SKINNING_CHANNEL DWORD
   SrcOffset  AS DWORD   ' UINT
   DestOffset AS DWORD   ' UINT
   IsNormal   AS LONG    ' BOOL
END TYPE

INTERFACE ID3DX10SkinInfo $IID_ID3DX10SkinInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNumVertices ( _                            ' VTable offset = 12
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetNumBones ( _                               ' VTable offset = 16
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetMaxBoneInfluences ( _                      ' VTable offset = 20
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD AddVertices ( _                               ' VTable offset = 24
     BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD RemapVertices ( _                             ' VTable offset = 28
     BYVAL NewVertexCount AS DWORD _                    ' __in UINT NewVertexCount
   , BYREF pVertexRemap AS DWORD _                      ' __in UINT *pVertexRemap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddBones ( _                                  ' VTable offset = 32
     BYVAL Count AS DWORD _                             ' __in UINT Count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveBone ( _                                ' VTable offset = 36
     BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemapBones ( _                                ' VTable offset = 40
     BYVAL NewBoneCount AS DWORD _                      ' __in UINT  NewBoneCount
   , BYREF pBoneRemap AS DWORD _                        ' __in UINT *pBoneRemap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddBoneInfluences ( _                         ' VTable offset = 44
     BYVAL BoneIndex AS DWORD _                         ' __in UINT  BoneIndex
   , BYVAL InfluenceCount AS DWORD _                    ' __in UINT  InfluenceCount
   , BYREF pIndices AS DWORD _                          ' __in UINT  *pIndices
   , BYREF pWeights AS SINGLE _                         ' __in float *pWeights
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearBoneInfluences ( _                       ' VTable offset = 48
     BYVAL BoneIndex AS DWORD _                         ' __in UINT  BoneIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBoneInfluenceCount ( _                     ' VTable offset = 52
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetBoneInfluences ( _                         ' VTable offset = 56
     BYVAL BoneIndex AS DWORD _                         ' __in UINT  BoneIndex
   , BYVAL Offset AS DWORD _                            ' __in UINT  Offset
   , BYVAL Count AS DWORD _                             ' __in UINT  Count
   , BYREF pDestIndices AS DWORD _                      ' __in_out UINT  *pDestIndices
   , BYREF pDestWeights AS SINGLE _                     ' __in_out float *pDestWeights
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindBoneInfluenceIndex ( _                    ' VTable offset = 60
     BYVAL BoneIndex AS DWORD _                         ' __in UINT  BoneIndex
   , BYVAL VertexIndex AS DWORD _                       ' __in UINT  VertexIndex
   , BYREF pInfluenceIndex AS DWORD _                   ' __out UINT *pInfluenceIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBoneInfluence ( _                          ' VTable offset = 64
     BYVAL BoneIndex AS DWORD _                         ' __in UINT  BoneIndex
   , BYVAL InfluenceIndex AS DWORD _                    ' __in UINT  InfluenceIndex
   , BYVAL Weight AS SINGLE _                           ' __in float Weight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBoneInfluence ( _                          ' VTable offset = 68
     BYVAL BoneIndex AS DWORD _                         ' __in  UINT  BoneIndex
   , BYVAL InfluenceIndex AS DWORD _                    ' __in  UINT  InfluenceIndex
   , BYREF pWeight AS SINGLE _                          ' __out float *pWeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compact ( _                                   ' VTable offset = 72
     BYVAL MaxPerVertexInfluences AS DWORD _            ' __in UINT  MaxPerVertexInfluences
   , BYVAL ScaleMode AS DWORD _                         ' __in UINT  ScaleMode
   , BYVAL MinWeight AS SINGLE _                        ' __in float MinWeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoSoftwareSkinning ( _                        ' VTable offset = 76
     BYVAL StartVertex AS DWORD _                       ' __in UINT  StartVertex
   , BYVAL VertexCount AS DWORD _                       ' __in UINT  VertexCount
   , BYVAL pSrcVertices AS DWORD _                      ' __in void *pSrcVertices
   , BYVAL SrcStride AS DWORD _                         ' __in UINT  SrcStride
   , BYVAL pDestVertices AS DWORD _                     ' __in_out void *pDestVertices
   , BYVAL DestStride AS DWORD _                        ' __in UINT  DestStride
   , BYREF pBoneMatrices AS D3DXMATRIX _                ' __in D3DXMATRIX *pBoneMatrices
   , BYREF pInverseTransposeBoneMatrices AS D3DXMATRIX _ ' __in D3DXMATRIX *pInverseTransposeBoneMatrices
   , BYREF pChannelDescs AS D3DX10_SKINNING_CHANNEL _   ' __in D3DX10_SKINNING_CHANNEL *pChannelDescs
   , BYVAL NumChannels AS DWORD _                       ' __in UINT  NumChannels
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ID3DX10SkinInfo_INTERFACE_DEFINED__ */


DECLARE FUNCTION D3DX10CreateSkinInfo IMPORT $D3DX10_DLLNAME ALIAS "D3DX10CreateSkinInfo" ( _
   BYREF ppSkinInfo AS ID3DX10SkinInfo _                ' __out LPD3DX10SKININFO* ppSkinInfo
 ) AS LONG                                              ' HRESULT


' // Size = 60 bytes
TYPE D3DX10_ATTRIBUTE_WEIGHTS DWORD
   Position    AS SINGLE   ' FLOAT
   Boundary    AS SINGLE   ' FLOAT
   Normal      AS SINGLE   ' FLOAT
   Diffuse     AS SINGLE   ' FLOAT
   Specular    AS SINGLE   ' FLOAT
   Texcoord(7) AS SINGLE   ' FLOAT[8]
   Tangent     AS SINGLE   ' FLOAT
   Binormal    AS SINGLE   ' FLOAT
END TYPE
