' ########################################################################################
' Microsoft Windows
' File: d3dx9mesh.inc
' Contents: D3DX mesh types and functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3DX9MESH_INC = 1

#INCLUDE ONCE "d3dx9.inc"

$IID_ID3DXBaseMesh  = GUID$("{7ED943DD-52E8-40b5-A8D8-76685C406330}")
$IID_ID3DXMesh      = GUID$("{4020E5C2-1403-4929-883F-E2E849FAC195}")
$IID_ID3DXPMesh     = GUID$("{8875769A-D579-4088-AAEB-534D1AD84E96}")
$IID_ID3DXSPMesh    = GUID$("{667EA4C7-F1CD-4386-B523-7C0290B83CC5}")
$IID_ID3DXSkinInfo  = GUID$("{11EAA540-F9A6-4d49-AE6A-E19221F70CC4}")
$IID_ID3DXPatchMesh = GUID$("{3CE6CC22-DBF2-44f4-894D-F9C34A337139}")


'// patch mesh can be quads or tris
'enum D3DXPATCHMESHTYPE

%D3DXPATCHMESH_RECT        = &H001???
%D3DXPATCHMESH_TRI         = &H002???
%D3DXPATCHMESH_NPATCH      = &H003???
%D3DXPATCHMESH_FORCE_DWORD = &H7FFFFFFF???   ' /* force 32-bit size enum */

'// Mesh options - lower 3 bytes only, upper byte used by _D3DXMESHOPT option flags
' enum D3DXMESH
%D3DXMESH_32BIT                  = &H001???   ' // If set, then use 32 bit indices, if not set use 16 bit indices.
%D3DXMESH_DONOTCLIP              = &H002???   ' // Use D3DUSAGE_DONOTCLIP for VB & IB.
%D3DXMESH_POINTS                 = &H004???   ' // Use D3DUSAGE_POINTS for VB & IB.
%D3DXMESH_RTPATCHES              = &H008???   ' // Use D3DUSAGE_RTPATCHES for VB & IB.
%D3DXMESH_NPATCHES               = &H4000???  ' // Use D3DUSAGE_NPATCHES for VB & IB.
%D3DXMESH_VB_SYSTEMMEM           = &H010???   ' // Use D3DPOOL_SYSTEMMEM for VB. Overrides D3DXMESH_MANAGEDVERTEXBUFFER
%D3DXMESH_VB_MANAGED             = &H020???   ' // Use D3DPOOL_MANAGED for VB.
%D3DXMESH_VB_WRITEONLY           = &H040???   ' // Use D3DUSAGE_WRITEONLY for VB.
%D3DXMESH_VB_DYNAMIC             = &H080???   ' // Use D3DUSAGE_DYNAMIC for VB.
%D3DXMESH_VB_SOFTWAREPROCESSING  = &H8000???  ' // Use D3DUSAGE_SOFTWAREPROCESSING for VB.
%D3DXMESH_IB_SYSTEMMEM           = &H100???   ' // Use D3DPOOL_SYSTEMMEM for IB. Overrides D3DXMESH_MANAGEDINDEXBUFFER
%D3DXMESH_IB_MANAGED             = &H200???   ' // Use D3DPOOL_MANAGED for IB.
%D3DXMESH_IB_WRITEONLY           = &H400???   ' // Use D3DUSAGE_WRITEONLY for IB.
%D3DXMESH_IB_DYNAMIC             = &H800???   ' // Use D3DUSAGE_DYNAMIC for IB.
%D3DXMESH_IB_SOFTWAREPROCESSING  = &H10000??? ' // Use D3DUSAGE_SOFTWAREPROCESSING for IB.

%D3DXMESH_VB_SHARE               = &H1000???  ' // Valid for Clone* calls only, forces cloned mesh/pmesh to share vertex buffer

%D3DXMESH_USEHWONLY              = &H2000???  ' // Valid for ID3DXSkinInfo::ConvertToBlendedMesh

' // Helper options
%D3DXMESH_SYSTEMMEM              = &H110???   ' // D3DXMESH_VB_SYSTEMMEM | D3DXMESH_IB_SYSTEMMEM
%D3DXMESH_MANAGED                = &H220???   ' // D3DXMESH_VB_MANAGED | D3DXMESH_IB_MANAGED
%D3DXMESH_WRITEONLY              = &H440???   ' // D3DXMESH_VB_WRITEONLY | D3DXMESH_IB_WRITEONLY
%D3DXMESH_DYNAMIC                = &H880???   ' // D3DXMESH_VB_DYNAMIC | D3DXMESH_IB_DYNAMIC
%D3DXMESH_SOFTWAREPROCESSING     = &H18000??? ' // D3DXMESH_VB_SOFTWAREPROCESSING | D3DXMESH_IB_SOFTWAREPROCESSING


'//patch mesh options
'enum D3DXPATCHMESH {
%D3DXPATCHMESH_DEFAULT = 0???

'// option field values for specifying min value in D3DXGeneratePMesh and D3DXSimplifyMesh
'enum D3DXMESHSIMP
%D3DXMESHSIMP_VERTEX   = &H1???
%D3DXMESHSIMP_FACE     = &H2???

'enum D3DXCLEANTYPE {
%D3DXCLEAN_BACKFACING   = &H00000001???
%D3DXCLEAN_BOWTIES      = &H00000002???
   '// Helper options
%D3DXCLEAN_SKINNING       = %D3DXCLEAN_BACKFACING  ' // Bowtie cleaning modifies geometry and breaks skinning
%D3DXCLEAN_OPTIMIZATION   = %D3DXCLEAN_BACKFACING
%D3DXCLEAN_SIMPLIFICATION = %D3DXCLEAN_BACKFACING OR %D3DXCLEAN_BOWTIES

'enum MAX_FVF_DECL_SIZE
%MAX_FVF_DECL_SIZE = %MAXD3DDECLLENGTH + 1  ' // +1 for END

' // Size = 20 bytes
TYPE D3DXATTRIBUTERANGE DWORD
   AttribId    AS DWORD   ' DWORD
   FaceStart   AS DWORD   ' DWORD
   FaceCount   AS DWORD   ' DWORD
   VertexStart AS DWORD   ' DWORD
   VertexCount AS DWORD   ' DWORD
END TYPE

' // Size = 272 bytes
TYPE D3DXMATERIAL DWORD
   MatD3D           AS D3DMATERIAL9   ' D3DMATERIAL9
   pTextureFilename AS ASCIIZ PTR     ' LPSTR
END TYPE

'enum D3DXEFFECTDEFAULTTYPE
%D3DXEDT_STRING     = &H1???          ' // pValue points to a null terminated ASCII string
%D3DXEDT_FLOATS     = &H2???          ' // pValue points to an array of floats - number of floats is NumBytes / sizeof(float)
%D3DXEDT_DWORD      = &H3???          ' // pValue points to a DWORD
%D3DXEDT_FORCEDWORD = &H7FFFFFFF???

' // Size = 16 bytes
TYPE D3DXEFFECTDEFAULT DWORD
   pParamName AS ASCIIZ PTR   ' LPSTR
   Type       AS DWORD        ' D3DXEFFECTDEFAULTTYPE // type of the data pointed to by pValue
   NumBytes   AS DWORD        ' DWORD // size in bytes of the data pointed to by pValue
   pValue     AS DWORD        ' LPVOID // data for the default of the effect
END TYPE

' // Size = 12 bytes
TYPE D3DXEFFECTINSTANCE DWORD
   pEffectFilename AS ASCIIZ PTR   ' LPSTR
   NumDefaults     AS DWORD        ' DWORD
   pDefaults       AS DWORD        ' LPD3DXEFFECTDEFAULT
END TYPE

' // Size = 60 bytes
TYPE D3DXATTRIBUTEWEIGHTS DWORD
   Position    AS SINGLE   ' FLOAT
   Boundary    AS SINGLE   ' FLOAT
   Normal      AS SINGLE   ' FLOAT
   Diffuse     AS SINGLE   ' FLOAT
   Specular    AS SINGLE   ' FLOAT
   Texcoord(7) AS SINGLE   ' FLOAT[8]
   Tangent     AS SINGLE   ' FLOAT
   Binormal    AS SINGLE   ' FLOAT
END TYPE

'enum _D3DXWELDEPSILONSFLAGS
%D3DXWELDEPSILONS_WELDALL             = &H1???  ' // weld all vertices marked by adjacency as being overlapping

%D3DXWELDEPSILONS_WELDPARTIALMATCHES  = &H2???  ' // if a given vertex component is within epsilon, modify partial matched
                                                ' // vertices so that both components identical AND if all components "equal"
                                                ' // remove one of the vertices
%D3DXWELDEPSILONS_DONOTREMOVEVERTICES = &H4???  ' // instructs weld to only allow modifications to vertices and not removal
                                                ' // ONLY valid if D3DXWELDEPSILONS_WELDPARTIALMATCHES is set
                                                ' // useful to modify vertices to be equal, but not allow vertices to be removed

%D3DXWELDEPSILONS_DONOTSPLIT          = &H8???  ' // instructs weld to specify the D3DXMESHOPT_DONOTSPLIT flag when doing an Optimize(ATTR_SORT)
                                                ' // if this flag is not set, all vertices that are in separate attribute groups
                                                ' // will remain split and not welded.  Setting this flag can slow down software vertex processing

' // Size = 68 bytes
TYPE D3DXWELDEPSILONS DWORD
   Position     AS SINGLE   '  FLOAT // NOTE: This does NOT replace the epsilon in GenerateAdjacency
                            '        // in general, it should be the same value or greater than the one passed to GeneratedAdjacency
   BlendWeights AS SINGLE   '  FLOAT
   Normal       AS SINGLE   '  FLOAT
   PSize        AS SINGLE   '  FLOAT
   Specular     AS SINGLE   '  FLOAT
   Diffuse      AS SINGLE   '  FLOAT
   Texcoord(7)  AS SINGLE   '  FLOAT[8]
   Tangent      AS SINGLE   '  FLOAT
   Binormal     AS SINGLE   '  FLOAT
   TessFactor   AS SINGLE   '  FLOAT
END TYPE


'//////////////////////////////////////////////////////////////////////////////
'// ID3DXBaseMesh /////////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

INTERFACE ID3DXBaseMesh $IID_ID3DXBaseMesh

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DrawSubset ( _                                ' VTable offset = 12
     BYVAL AttribId AS DWORD _                          ' __in DWORD AttribId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumFaces ( _                               ' VTable offset = 16
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetNumVertices ( _                            ' VTable offset = 20
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetFVF ( _                                    ' VTable offset = 24
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetDeclaration ( _                            ' VTable offset = 28
     BYREF Declaration AS D3DVERTEXELEMENT9 _           ' __in_out D3DVERTEXELEMENT9 Declaration[MAX_FVF_DECL_SIZE]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumBytesPerVertex ( _                      ' VTable offset = 32
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetOptions ( _                                ' VTable offset = 36
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 40
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out LPDIRECT3DDEVICE9* ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloneMeshFVF ( _                              ' VTable offset = 44
     BYVAL Options AS DWORD _                           ' __in  DWORD Options
   , BYVAL FVF AS DWORD _                               ' __in  DWORD FVF
   , BYVAL pD3DDevice AS IDirect3DDevice9 _             ' __in  LPDIRECT3DDEVICE9 pD3DDevice
   , BYREF ppCloneMesh AS ID3DXMesh _                   ' __out LPD3DXMESH* ppCloneMesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloneMesh ( _                                 ' VTable offset = 48
     BYVAL Options AS DWORD _                           ' __in DWORD Options
   , BYREF pDeclaration AS D3DVERTEXELEMENT9 _          ' __in CONST D3DVERTEXELEMENT9 *pDeclaration
   , BYVAL pD3DDevice AS IDirect3DDevice9 _             ' __in LPDIRECT3DDEVICE9 pD3DDevice
   , BYREF ppCloneMesh AS ID3DXMesh _                   ' __out LPD3DXMESH* ppCloneMesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVertexBuffer ( _                           ' VTable offset = 52
     BYREF ppVB AS IDirect3DVertexBuffer9 _             ' __out LPDIRECT3DVERTEXBUFFER9* ppVB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIndexBuffer ( _                            ' VTable offset = 56
     BYREF ppIB AS IDirect3DIndexBuffer9 _              ' __out LPDIRECT3DINDEXBUFFER9* ppIB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockVertexBuffer ( _                          ' VTable offset = 60
     BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   , BYREF ppData AS DWORD _                            ' __out LPVOID *ppData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockVertexBuffer ( _                        ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockIndexBuffer ( _                           ' VTable offset = 68
     BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   , BYREF ppData AS DWORD _                            ' __out LPVOID *ppData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockIndexBuffer ( _                         ' VTable offset = 72
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttributeTable ( _                         ' VTable offset = 76
     BYREF pAttribTable AS D3DXATTRIBUTERANGE _         ' __in_out D3DXATTRIBUTERANGE *pAttribTable
   , BYREF pAttribTableSize AS DWORD _                  ' __in_out DWORD* pAttribTableSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertPointRepsToAdjacency ( _               ' VTable offset = 80
     BYREF pPRep AS DWORD _                             ' __in CONST DWORD* pPRep
   , BYREF pAdjacency AS DWORD _                        ' __in_out DWORD* pAdjacency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertAdjacencyToPointReps ( _               ' VTable offset = 84
     BYREF pAdjacency AS DWORD _                        ' __in CONST DWORD* pAdjacency
   , BYREF pPRep AS DWORD _                             ' __in_out DWORD* pPRep
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GenerateAdjacency ( _                         ' VTable offset = 88
     BYVAL Epsilon AS SINGLE _                          ' __in FLOAT Epsilon
   , BYREF pAdjacency AS DWORD _                        ' __in DWORD* pAdjacency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateSemantics ( _                           ' VTable offset = 92
     BYREF Declaration AS D3DVERTEXELEMENT9 _           ' __in_out D3DVERTEXELEMENT9 Declaration[MAX_FVF_DECL_SIZE]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'//////////////////////////////////////////////////////////////////////////////
'// ID3DXMesh /////////////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

INTERFACE ID3DXMesh $IID_ID3DXMesh

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3DXBaseMesh methods
   ' =====================================================================================
   METHOD DrawSubset ( _                                ' VTable offset = 12
     BYVAL AttribId AS DWORD _                          ' __in DWORD AttribId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumFaces ( _                               ' VTable offset = 16
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetNumVertices ( _                            ' VTable offset = 20
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetFVF ( _                                    ' VTable offset = 24
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetDeclaration ( _                            ' VTable offset = 28
     BYREF Declaration AS D3DVERTEXELEMENT9 _           ' __in_out D3DVERTEXELEMENT9 Declaration[MAX_FVF_DECL_SIZE]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumBytesPerVertex ( _                      ' VTable offset = 32
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetOptions ( _                                ' VTable offset = 36
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 40
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out LPDIRECT3DDEVICE9* ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloneMeshFVF ( _                              ' VTable offset = 44
     BYVAL Options AS DWORD _                           ' __in  DWORD Options
   , BYVAL FVF AS DWORD _                               ' __in  DWORD FVF
   , BYVAL pD3DDevice AS IDirect3DDevice9 _             ' __in  LPDIRECT3DDEVICE9 pD3DDevice
   , BYREF ppCloneMesh AS ID3DXMesh _                   ' __out LPD3DXMESH* ppCloneMesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloneMesh ( _                                 ' VTable offset = 48
     BYVAL Options AS DWORD _                           ' __in DWORD Options
   , BYREF pDeclaration AS D3DVERTEXELEMENT9 _          ' __in CONST D3DVERTEXELEMENT9 *pDeclaration
   , BYVAL pD3DDevice AS IDirect3DDevice9 _             ' __in LPDIRECT3DDEVICE9 pD3DDevice
   , BYREF ppCloneMesh AS ID3DXMesh _                   ' __out LPD3DXMESH* ppCloneMesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVertexBuffer ( _                           ' VTable offset = 52
     BYREF ppVB AS IDirect3DVertexBuffer9 _             ' __out LPDIRECT3DVERTEXBUFFER9* ppVB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIndexBuffer ( _                            ' VTable offset = 56
     BYREF ppIB AS IDirect3DIndexBuffer9 _              ' __out LPDIRECT3DINDEXBUFFER9* ppIB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockVertexBuffer ( _                          ' VTable offset = 60
     BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   , BYREF ppData AS DWORD _                            ' __out LPVOID *ppData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockVertexBuffer ( _                        ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockIndexBuffer ( _                           ' VTable offset = 68
     BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   , BYREF ppData AS DWORD _                            ' __out LPVOID *ppData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockIndexBuffer ( _                         ' VTable offset = 72
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttributeTable ( _                         ' VTable offset = 76
     BYREF pAttribTable AS D3DXATTRIBUTERANGE _         ' __in_out D3DXATTRIBUTERANGE *pAttribTable
   , BYREF pAttribTableSize AS DWORD _                  ' __in_out DWORD* pAttribTableSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertPointRepsToAdjacency ( _               ' VTable offset = 80
     BYREF pPRep AS DWORD _                             ' __in CONST DWORD* pPRep
   , BYREF pAdjacency AS DWORD _                        ' __in_out DWORD* pAdjacency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertAdjacencyToPointReps ( _               ' VTable offset = 84
     BYREF pAdjacency AS DWORD _                        ' __in CONST DWORD* pAdjacency
   , BYREF pPRep AS DWORD _                             ' __in_out DWORD* pPRep
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GenerateAdjacency ( _                         ' VTable offset = 88
     BYVAL Epsilon AS SINGLE _                          ' __in FLOAT Epsilon
   , BYREF pAdjacency AS DWORD _                        ' __in DWORD* pAdjacency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateSemantics ( _                           ' VTable offset = 92
     BYREF Declaration AS D3DVERTEXELEMENT9 _           ' __in_out D3DVERTEXELEMENT9 Declaration[MAX_FVF_DECL_SIZE]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3DXMesh methods
   ' =====================================================================================
   METHOD LockAttributeBuffer ( _                       ' VTable offset = 96
     BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   , BYREF ppData AS DWORD _                            ' __out DWORD** ppData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockAttributeBuffer ( _                     ' VTable offset = 100
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Optimize ( _                                  ' VTable offset = 104
     BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   , BYREF pAdjacencyIn AS DWORD _                      ' __in CONST DWORD* pAdjacencyIn
   , BYREF pAdjacencyOut AS DWORD _                     ' __in_out DWORD* pAdjacencyOut
   , BYREF pFaceRemap AS DWORD _                        ' __in_out DWORD* pFaceRemap
   , BYREF ppVertexRemap AS ID3DXBuffer _               ' __out LPD3DXBUFFER *ppVertexRemap
   , BYREF ppOptMesh AS ID3DXMesh _                     ' __out LPD3DXMESH* ppOptMesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OptimizeInplace ( _                           ' VTable offset = 108
     BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   , BYREF pAdjacencyIn AS DWORD _                      ' __in  CONST DWORD* pAdjacencyIn
   , BYREF pAdjacencyOut AS DWORD _                     ' __out DWORD* pAdjacencyOut
   , BYREF pFaceRemap AS DWORD _                        ' __out DWORD* pFaceRemap
   , BYREF ppVertexRemap AS ID3DXBuffer _               ' __out LPD3DXBUFFER *ppVertexRemap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAttributeTable ( _                         ' VTable offset = 112
     BYREF pAttribTable AS D3DXATTRIBUTERANGE _         ' __in CONST D3DXATTRIBUTERANGE *pAttribTable
   , BYVAL cAttribTableSize AS DWORD _                  ' __in DWORD cAttribTableSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'//////////////////////////////////////////////////////////////////////////////
'// ID3DXPMesh ////////////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

INTERFACE ID3DXPMesh $IID_ID3DXPMesh

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3DXBaseMesh methods
   ' =====================================================================================
   METHOD DrawSubset ( _                                ' VTable offset = 12
     BYVAL AttribId AS DWORD _                          ' __in DWORD AttribId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumFaces ( _                               ' VTable offset = 16
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetNumVertices ( _                            ' VTable offset = 20
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetFVF ( _                                    ' VTable offset = 24
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetDeclaration ( _                            ' VTable offset = 28
     BYREF Declaration AS D3DVERTEXELEMENT9 _           ' __in_out D3DVERTEXELEMENT9 Declaration[MAX_FVF_DECL_SIZE]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumBytesPerVertex ( _                      ' VTable offset = 32
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetOptions ( _                                ' VTable offset = 36
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 40
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out LPDIRECT3DDEVICE9* ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloneMeshFVF ( _                              ' VTable offset = 44
     BYVAL Options AS DWORD _                           ' __in  DWORD Options
   , BYVAL FVF AS DWORD _                               ' __in  DWORD FVF
   , BYVAL pD3DDevice AS IDirect3DDevice9 _             ' __in  LPDIRECT3DDEVICE9 pD3DDevice
   , BYREF ppCloneMesh AS ID3DXMesh _                   ' __out LPD3DXMESH* ppCloneMesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloneMesh ( _                                 ' VTable offset = 48
     BYVAL Options AS DWORD _                           ' __in DWORD Options
   , BYREF pDeclaration AS D3DVERTEXELEMENT9 _          ' __in CONST D3DVERTEXELEMENT9 *pDeclaration
   , BYVAL pD3DDevice AS IDirect3DDevice9 _             ' __in LPDIRECT3DDEVICE9 pD3DDevice
   , BYREF ppCloneMesh AS ID3DXMesh _                   ' __out LPD3DXMESH* ppCloneMesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVertexBuffer ( _                           ' VTable offset = 52
     BYREF ppVB AS IDirect3DVertexBuffer9 _             ' __out LPDIRECT3DVERTEXBUFFER9* ppVB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIndexBuffer ( _                            ' VTable offset = 56
     BYREF ppIB AS IDirect3DIndexBuffer9 _              ' __out LPDIRECT3DINDEXBUFFER9* ppIB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockVertexBuffer ( _                          ' VTable offset = 60
     BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   , BYREF ppData AS DWORD _                            ' __out LPVOID *ppData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockVertexBuffer ( _                        ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockIndexBuffer ( _                           ' VTable offset = 68
     BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   , BYREF ppData AS DWORD _                            ' __out LPVOID *ppData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockIndexBuffer ( _                         ' VTable offset = 72
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttributeTable ( _                         ' VTable offset = 76
     BYREF pAttribTable AS D3DXATTRIBUTERANGE _         ' __in_out D3DXATTRIBUTERANGE *pAttribTable
   , BYREF pAttribTableSize AS DWORD _                  ' __in_out DWORD* pAttribTableSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertPointRepsToAdjacency ( _               ' VTable offset = 80
     BYREF pPRep AS DWORD _                             ' __in CONST DWORD* pPRep
   , BYREF pAdjacency AS DWORD _                        ' __in_out DWORD* pAdjacency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertAdjacencyToPointReps ( _               ' VTable offset = 84
     BYREF pAdjacency AS DWORD _                        ' __in CONST DWORD* pAdjacency
   , BYREF pPRep AS DWORD _                             ' __in_out DWORD* pPRep
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GenerateAdjacency ( _                         ' VTable offset = 88
     BYVAL Epsilon AS SINGLE _                          ' __in FLOAT Epsilon
   , BYREF pAdjacency AS DWORD _                        ' __in DWORD* pAdjacency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateSemantics ( _                           ' VTable offset = 92
     BYREF Declaration AS D3DVERTEXELEMENT9 _           ' __in_out D3DVERTEXELEMENT9 Declaration[MAX_FVF_DECL_SIZE]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3DXPMesh methods
   ' =====================================================================================
   METHOD ClonePMeshFVF ( _                             ' VTable offset = 96
     BYVAL Options AS DWORD _                           ' __in  DWORD Options
   , BYVAL FVF AS DWORD _                               ' __in  DWORD FVF
   , BYVAL pD3DDevice AS IDirect3DDevice9 _             ' __in  LPDIRECT3DDEVICE9 pD3DDevice
   , BYREF ppCloneMesh AS ID3DXPMesh _                  ' __out LPD3DXPMESH* ppCloneMesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClonePMesh ( _                                ' VTable offset = 100
     BYVAL Options AS DWORD _                           ' __in  DWORD Options
   , BYREF pDeclaration AS D3DVERTEXELEMENT9 _          ' __in  CONST D3DVERTEXELEMENT9 *pDeclaration
   , BYVAL pD3DDevice AS IDirect3DDevice9 _             ' __in  LPDIRECT3DDEVICE9 pD3DDevice
   , BYREF ppCloneMesh AS ID3DXPMesh _                  ' __out LPD3DXPMESH* ppCloneMesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNumFaces ( _                               ' VTable offset = 104
     BYVAL Faces AS DWORD _                             ' __in DWORD Faces
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNumVertices ( _                            ' VTable offset = 108
     BYVAL Vertices AS DWORD _                          ' __in DWORD Vertices
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxFaces ( _                               ' VTable offset = 112
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetMinFaces ( _                               ' VTable offset = 116
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetMaxVertices ( _                            ' VTable offset = 120
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetMinVertices ( _                            ' VTable offset = 124
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 128
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   , BYREF pMaterials AS D3DXMATERIAL _                 ' __in CONST D3DXMATERIAL* pMaterials
   , BYREF pEffectInstances AS D3DXEFFECTINSTANCE _     ' __in CONST D3DXEFFECTINSTANCE* pEffectInstances
   , BYVAL NumMaterials AS DWORD _                      ' __in DWORD NumMaterials
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Optimize ( _                                  ' VTable offset = 132
     BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   , BYREF pAdjacencyOut AS DWORD _                     ' __out DWORD* pAdjacencyOut
   , BYREF pFaceRemap AS DWORD _                        ' __out DWORD* pFaceRemap
   , BYREF ppVertexRemap AS ID3DXBuffer _               ' __out LPD3DXBUFFER *ppVertexRemap
   , BYREF ppOptMesh AS ID3DXMesh _                     ' __out LPD3DXMESH* ppOptMesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OptimizeBaseLOD ( _                           ' VTable offset = 136
     BYVAL Flags AS DWORD _                             ' __in DWORD Flags
   , BYREF pFaceRemap AS DWORD _                        ' __in DWORD* pFaceRemap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TrimByFaces ( _                               ' VTable offset = 140
     BYVAL NewFacesMin AS DWORD _                       ' __in  DWORD NewFacesMin
   , BYVAL NewFacesMax AS DWORD _                       ' __in  DWORD NewFacesMax
   , BYREF rgiFaceRemap AS DWORD _                      ' __out DWORD *rgiFaceRemap
   , BYREF rgiVertRemap AS DWORD _                      ' __out DWORD *rgiVertRemap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TrimByVertices ( _                            ' VTable offset = 144
     BYVAL NewVerticesMin AS DWORD _                    ' __in  DWORD NewVerticesMin
   , BYVAL NewVerticesMax AS DWORD _                    ' __in  DWORD NewVerticesMax
   , BYREF rgiFaceRemap AS DWORD _                      ' __out DWORD *rgiFaceRemap
   , BYREF rgiVertRemap AS DWORD _                      ' __out DWORD *rgiVertRemap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAdjacency ( _                              ' VTable offset = 148
     BYREF pAdjacency AS DWORD _                        ' __out DWORD* pAdjacency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GenerateVertexHistory ( _                     ' VTable offset = 152
     BYREF pVertexHistory AS DWORD _                    ' __in DWORD* pVertexHistory
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'//////////////////////////////////////////////////////////////////////////////
'// ID3DXSPMesh ///////////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

INTERFACE ID3DXSPMesh $IID_ID3DXSPMesh

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNumFaces ( _                               ' VTable offset = 12
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetNumVertices ( _                            ' VTable offset = 16
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetFVF ( _                                    ' VTable offset = 20
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetDeclaration ( _                            ' VTable offset = 24
     BYREF Declaration AS D3DVERTEXELEMENT9 _                          ' __out D3DVERTEXELEMENT9 Declaration[MAX_FVF_DECL_SIZE]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOptions ( _                                ' VTable offset = 28
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 32
     BYREF ppDevice AS IDirect3DDevice9 _                           ' __out LPDIRECT3DDEVICE9* ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloneMeshFVF ( _                              ' VTable offset = 36
     BYVAL Options AS DWORD _                           ' __in  DWORD Options
   , BYVAL FVF AS DWORD _                               ' __in  DWORD FVF
   , BYVAL pD3DDevice AS IDirect3DDevice9 _             ' __in  LPDIRECT3DDEVICE9 pD3DDevice
   , BYREF pAdjacencyOut AS DWORD _                     ' __out DWORD *pAdjacencyOut
   , BYREF pVertexRemapOut AS DWORD _                   ' __out DWORD *pVertexRemapOut
   , BYREF ppCloneMesh AS ID3DXMesh _                   ' __out LPD3DXMESH* ppCloneMesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloneMesh ( _                                 ' VTable offset = 40
     BYVAL Options AS DWORD _                           ' __in  DWORD Options
   , BYREF pDeclaration AS D3DVERTEXELEMENT9 _          ' __in  CONST D3DVERTEXELEMENT9 *pDeclaration
   , BYVAL pD3DDevice AS IDirect3DDevice9 _             ' __in  LPDIRECT3DDEVICE9 pD3DDevice
   , BYREF pAdjacencyOut AS DWORD _                     ' __out DWORD *pAdjacencyOut
   , BYREF pVertexRemapOut AS DWORD _                   ' __out DWORD *pVertexRemapOut
   , BYREF ppCloneMesh AS ID3DXMesh _                   ' __out LPD3DXMESH* ppCloneMesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClonePMeshFVF ( _                             ' VTable offset = 44
     BYVAL Options AS DWORD _                           ' __in  DWORD Options
   , BYVAL FVF AS DWORD _                               ' __in  DWORD FVF
   , BYVAL pD3DDevice AS IDirect3DDevice9 _             ' __in  LPDIRECT3DDEVICE9 pD3DDevice
   , BYREF pVertexRemapOut AS DWORD _                   ' __out DWORD *pVertexRemapOut
   , BYREF pErrorsByFace AS SINGLE _                    ' __out FLOAT *pErrorsByFace
   , BYREF ppCloneMesh AS ID3DXPMesh _                  ' __out LPD3DXPMESH* ppCloneMesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClonePMesh ( _                                ' VTable offset = 48
     BYVAL Options AS DWORD _                           ' __in  DWORD Options
   , BYREF pDeclaration AS D3DVERTEXELEMENT9 _          ' __in  CONST D3DVERTEXELEMENT9 *pDeclaration
   , BYVAL pD3DDevice AS IDirect3DDevice9 _             ' __in  LPDIRECT3DDEVICE9 pD3DDevice
   , BYREF pVertexRemapOut AS DWORD _                   ' __out DWORD *pVertexRemapOut
   , BYREF pErrorsbyFace AS SINGLE _                    ' __out FLOAT *pErrorsbyFace
   , BYREF ppCloneMesh AS ID3DXPMesh _                  ' __out LPD3DXPMESH* ppCloneMesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReduceFaces ( _                               ' VTable offset = 52
     BYVAL Faces AS DWORD _                             ' __in DWORD Faces
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReduceVertices ( _                            ' VTable offset = 56
     BYVAL Vertices AS DWORD _                          ' __in DWORD Vertices
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxFaces ( _                               ' VTable offset = 60
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetMaxVertices ( _                            ' VTable offset = 64
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetVertexAttributeWeights ( _                 ' VTable offset = 68
     BYREF pVertexAttributeWeights AS D3DXATTRIBUTEWEIGHTS _ ' __out LPD3DXATTRIBUTEWEIGHTS pVertexAttributeWeights
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetVertexWeights ( _                          ' VTable offset = 72
     BYREF pVertexWeights AS SINGLE _                   ' __in_out FLOAT *pVertexWeights
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================

END INTERFACE

%UNUSED16 = &HFFFF??
%UNUSED32 = &HFFFFFFFF???

'// ID3DXMesh::Optimize options - upper byte only, lower 3 bytes used from _D3DXMESH option flags
'enum D3DXMESHOPT {
%D3DXMESHOPT_COMPACT           = &H01000000???
%D3DXMESHOPT_ATTRSORT          = &H02000000???
%D3DXMESHOPT_VERTEXCACHE       = &H04000000???
%D3DXMESHOPT_STRIPREORDER      = &H08000000???
%D3DXMESHOPT_IGNOREVERTS       = &H10000000???   ' // optimize faces only, don't touch vertices
%D3DXMESHOPT_DONOTSPLIT        = &H20000000???   ' // do not split vertices shared between attribute groups when attribute sorting
%D3DXMESHOPT_DEVICEINDEPENDENT = &H00400000???   ' // Only affects VCache.  uses a static known good cache size for all cards

' // D3DXMESHOPT_SHAREVB has been removed, please use D3DXMESH_VB_SHARE instead

'// Subset of the mesh that has the same attribute and bone combination.
'// This subset can be rendered in a single draw call
' // Size = 24 bytes
TYPE D3DXBONECOMBINATION DWORD
   AttribId    AS DWORD   ' DWORD
   FaceStart   AS DWORD   ' DWORD
   FaceCount   AS DWORD   ' DWORD
   VertexStart AS DWORD   ' DWORD
   VertexCount AS DWORD   ' DWORD
   BoneId      AS DWORD   ' DWORD
END TYPE

'// The following types of patch combinations are supported:
'// Patch type   Basis       Degree
'// Rect         Bezier      2,3,5
'// Rect         B-Spline    2,3,5
'// Rect         Catmull-Rom 3
'// Tri          Bezier      2,3,5
'// N-Patch      N/A         3

' // Size = 12 bytes
TYPE D3DXPATCHINFO DWORD
   PatchType AS DWORD   ' D3DXPATCHMESHTYPE
   Degree    AS DWORD   ' D3DDEGREETYPE
   Basis     AS DWORD   ' D3DBASISTYPE
END TYPE


'//////////////////////////////////////////////////////////////////////////////
'// ID3DXPatchMesh ////////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

INTERFACE ID3DXPatchMesh $IID_ID3DXPatchMesh

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNumPatches ( _                             ' VTable offset = 12
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetNumVertices ( _                            ' VTable offset = 16
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetDeclaration ( _                            ' VTable offset = 20
     BYREF Declaration AS D3DVERTEXELEMENT9 _           ' __out D3DVERTEXELEMENT9 Declaration[MAX_FVF_DECL_SIZE]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetControlVerticesPerPatch ( _                ' VTable offset = 24
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetOptions ( _                                ' VTable offset = 28
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 32
     BYREF ppDevice AS IDirect3DDevice9 _               ' __out LPDIRECT3DDEVICE9 *ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPatchInfo ( _                              ' VTable offset = 36
     BYREF PatchInfo AS D3DXPATCHINFO _                 ' __out LPD3DXPATCHINFO PatchInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVertexBuffer ( _                           ' VTable offset = 40
     BYREF ppVB AS IDirect3DVertexBuffer9 _             ' __out LPDIRECT3DVERTEXBUFFER9* ppVB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIndexBuffer ( _                            ' VTable offset = 44
     BYREF ppIB AS IDirect3DIndexBuffer9 _              ' __out LPDIRECT3DINDEXBUFFER9 ppIB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockVertexBuffer ( _                          ' VTable offset = 48
     BYVAL flags AS DWORD _                             ' __in  DWORD flags
   , BYREF ppData AS DWORD _                            ' __out LPVOID *ppData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockVertexBuffer ( _                        ' VTable offset = 52
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockIndexBuffer ( _                           ' VTable offset = 56
     BYVAL flags AS DWORD _                             ' __in  DWORD flags
   , BYREF ppData AS DWORD _                            ' __out LPVOID *ppData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockIndexBuffer ( _                         ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockAttributeBuffer ( _                       ' VTable offset = 64
     BYVAL flags AS DWORD _                             ' __in  DWORD flags
   , BYREF ppData AS DWORD _                            ' __out DWORD** ppData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockAttributeBuffer ( _                     ' VTable offset = 68
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTessSize ( _                               ' VTable offset = 72
     BYVAL fTessLevel AS SINGLE _                       ' __in  FLOAT fTessLevel
   , BYVAL Adaptive AS DWORD _                          ' __in  DWORD Adaptive
   , BYREF NumTriangles AS DWORD _                      ' __out DWORD *NumTriangles
   , BYREF NumVertices AS DWORD _                       ' __out DWORD *NumVertices
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GenerateAdjacency ( _                         ' VTable offset = 76
     BYVAL Tolerance AS SINGLE _                        ' __in FLOAT Tolerance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloneMesh ( _                                 ' VTable offset = 80
     BYVAL Options AS DWORD _                           ' __in  DWORD Options
   , BYREF pDecl AS D3DVERTEXELEMENT9 _                 ' __in  CONST D3DVERTEXELEMENT9 *pDecl
   , BYREF pMesh AS ID3DXPatchMesh _                    ' __out LPD3DXPATCHMESH *pMesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Optimize ( _                                  ' VTable offset = 84
     BYVAL flags AS DWORD _                             ' __in DWORD flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDisplaceParam ( _                          ' VTable offset = 88
     BYVAL Texture AS IDirect3DBaseTexture9 _           ' __in LPDIRECT3DBASETEXTURE9 Texture
   , BYVAL MinFilter AS DWORD _                         ' __in D3DTEXTUREFILTERTYPE MinFilter
   , BYVAL MagFilter AS DWORD _                         ' __in D3DTEXTUREFILTERTYPE MagFilter
   , BYVAL MipFilter AS DWORD _                         ' __in D3DTEXTUREFILTERTYPE MipFilter
   , BYVAL Wrap AS DWORD _                              ' __in D3DTEXTUREADDRESS Wrap
   , BYVAL dwLODBias AS DWORD _                         ' __in DWORD dwLODBias
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplaceParam ( _                          ' VTable offset = 92
     BYREF Texture AS IDirect3DBaseTexture9 _           ' __in LPDIRECT3DBASETEXTURE9 *Texture
   , BYREF MinFilter AS DWORD _                         ' __in D3DTEXTUREFILTERTYPE *MinFilter
   , BYREF MagFilter AS DWORD _                         ' __in D3DTEXTUREFILTERTYPE *MagFilter
   , BYREF MipFilter AS DWORD _                         ' __in D3DTEXTUREFILTERTYPE *MipFilter
   , BYREF Wrap AS DWORD _                              ' __in D3DTEXTUREADDRESS *Wrap
   , BYREF dwLODBias AS DWORD _                         ' __in DWORD *dwLODBias
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Tessellate ( _                                ' VTable offset = 96
     BYVAL fTessLevel AS SINGLE _                       ' __in FLOAT fTessLevel
   , BYVAL pMesh AS ID3DXMesh _                         ' __in LPD3DXMESH pMesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TessellateAdaptive ( _                        ' VTable offset = 100
     BYREF pTrans AS D3DXVECTOR4 _                      ' __in CONST D3DXVECTOR4 *pTrans
   , BYVAL dwMaxTessLevel AS DWORD _                    ' __in DWORD dwMaxTessLevel
   , BYVAL dwMinTessLevel AS DWORD _                    ' __in DWORD dwMinTessLevel
   , BYVAL pMesh AS ID3DXMesh _                         ' __in LPD3DXMESH pMesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'//////////////////////////////////////////////////////////////////////////////
'// ID3DXSkinInfo /////////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

INTERFACE ID3DXSkinInfo $IID_ID3DXSkinInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetBoneInfluence ( _                          ' VTable offset = 12
     BYVAL bone AS DWORD _                              ' __in DWORD bone
   , BYVAL numInfluences AS DWORD _                     ' __in DWORD numInfluences
   , BYREF vertices AS DWORD _                          ' __in CONST DWORD* vertices
   , BYREF weights AS SINGLE _                          ' __in CONST FLOAT* weights
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBoneVertexInfluence ( _                    ' VTable offset = 16
     BYVAL boneNum AS DWORD _                           ' __in DWORD boneNum
   , BYVAL influenceNum AS DWORD _                      ' __in DWORD influenceNum
   , BYVAL weight AS SINGLE _                           ' __in float weight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumBoneInfluences ( _                      ' VTable offset = 20
     BYVAL bone AS DWORD _                              ' __in DWORD bone
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetBoneInfluence ( _                          ' VTable offset = 24
     BYVAL bone AS DWORD _                              ' __in DWORD bone
   , BYREF vertices AS DWORD _                          ' __in_out DWORD* vertices
   , BYREF weights AS SINGLE _                          ' __in_out FLOAT* weights
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBoneVertexInfluence ( _                    ' VTable offset = 28
     BYVAL boneNum AS DWORD _                           ' __in DWORD boneNum
   , BYVAL influenceNum AS DWORD _                      ' __in DWORD influenceNum
   , BYREF pWeight AS SINGLE _                          ' __in_out float *pWeight
   , BYREF pVertexNum AS DWORD _                        ' __in_out DWORD *pVertexNum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxVertexInfluences ( _                    ' VTable offset = 32
     BYREF maxVertexInfluences AS DWORD _               ' __out DWORD* maxVertexInfluences
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumBones ( _                               ' VTable offset = 36
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD FindBoneVertexInfluenceIndex ( _              ' VTable offset = 40
     BYVAL boneNum AS DWORD _                           ' __in DWORD boneNum
   , BYVAL vertexNum AS DWORD _                         ' __in DWORD vertexNum
   , BYREF pInfluenceIndex AS DWORD _                   ' __in_out DWORD *pInfluenceIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxFaceInfluences ( _                      ' VTable offset = 44
     BYVAL pIB AS IDirect3DIndexBuffer9 _               ' __in LPDIRECT3DINDEXBUFFER9 pIB
   , BYVAL NumFaces AS DWORD _                          ' __in DWORD NumFaces
   , BYREF maxFaceInfluences AS DWORD _                 ' __in_out DWORD* maxFaceInfluences
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMinBoneInfluence ( _                       ' VTable offset = 48
     BYVAL MinInfl AS SINGLE _                          ' __in FLOAT MinInfl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMinBoneInfluence ( _                       ' VTable offset = 52
   ) AS SINGLE                                          ' SINGLE
   ' =====================================================================================
   METHOD SetBoneName ( _                               ' VTable offset = 56
     BYVAL Bone AS DWORD _                              ' __in DWORD Bone
   , BYREF pName AS ASCIIZ _                            ' __in LPCSTR pName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBoneName ( _                               ' VTable offset = 60
     BYVAL Bone AS DWORD _                              ' __in DWORD Bone
   ) AS DWORD                                           ' LPCSTR
   ' =====================================================================================
   METHOD SetBoneOffsetMatrix ( _                       ' VTable offset = 64
     BYVAL Bone AS DWORD _                              ' __in DWORD Bone
   , BYREF pBoneTransform AS D3DXMATRIX _               ' __in CONST D3DXMATRIX *pBoneTransform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBoneOffsetMatrix ( _                       ' VTable offset = 68
     BYVAL Bone AS DWORD _                              ' __in DWORD Bone
   ) AS D3DXMATRIX                                      ' D3DXMATRIX
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 72
     BYREF ppSkinInfo AS ID3DXSkinInfo _                ' __in_out LPD3DXSKININFO* ppSkinInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Remap ( _                                     ' VTable offset = 76
     BYVAL NumVertices AS DWORD _                       ' __in DWORD NumVertices
   , BYREF pVertexRemap AS DWORD _                      ' __in DWORD* pVertexRemap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFVF ( _                                    ' VTable offset = 80
     BYVAL FVF AS DWORD _                               ' __in DWORD FVF
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDeclaration ( _                            ' VTable offset = 84
     BYREF pDeclaration AS D3DVERTEXELEMENT9 _          ' __in CONST D3DVERTEXELEMENT9 *pDeclaration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFVF ( _                                    ' VTable offset = 88
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetDeclaration ( _                            ' VTable offset = 92
     BYREF Declaration AS D3DVERTEXELEMENT9 _           ' __in_out D3DVERTEXELEMENT9 Declaration[MAX_FVF_DECL_SIZE]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateSkinnedMesh ( _                         ' VTable offset = 96
     BYREF pBoneTransforms AS D3DXMATRIX _              ' __in CONST D3DXMATRIX* pBoneTransforms
   , BYREF pBoneInvTransposeTransforms AS D3DXMATRIX _  ' __in CONST D3DXMATRIX* pBoneInvTransposeTransforms
   , BYVAL pVerticesSrc AS DWORD _                      ' __in LPCVOID pVerticesSrc
   , BYVAL pVerticesDst AS DWORD _                      ' __in PVOID pVerticesDst
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertToBlendedMesh ( _                      ' VTable offset = 100
     BYVAL pMesh AS ID3DXMesh _                         ' __in  LPD3DXMESH pMesh
   , BYVAL Options AS DWORD _                           ' __in  DWORD Options
   , BYREF pAdjacencyIn AS DWORD _                      ' __in  CONST DWORD *pAdjacencyIn
   , BYREF pAdjacencyOut AS DWORD _                     ' __in  LPDWORD pAdjacencyOut
   , BYREF pFaceRemap AS DWORD _                        ' __out DWORD* pFaceRemap
   , BYREF ppVertexRemap AS ID3DXBuffer _               ' __out LPD3DXBUFFER *ppVertexRemap
   , BYREF pMaxFaceInfl AS DWORD _                      ' __out DWORD* pMaxFaceInfl
   , BYREF pNumBoneCombinations AS DWORD _              ' __out DWORD* pNumBoneCombinations
   , BYREF ppBoneCombinationTable AS ID3DXBuffer _      ' __out LPD3DXBUFFER* ppBoneCombinationTable
   , BYREF ppMesh AS ID3DXMesh _                        ' __out LPD3DXMESH* ppMesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertToIndexedBlendedMesh ( _               ' VTable offset = 104
     BYVAL pMesh AS ID3DXMesh _                         ' __in  LPD3DXMESH pMesh
   , BYVAL Options AS DWORD _                           ' __in  DWORD Options
   , BYVAL paletteSize AS DWORD _                       ' __in  DWORD paletteSize
   , BYREF pAdjacencyIn AS DWORD _                      ' __in  CONST DWORD *pAdjacencyIn
   , BYREF pAdjacencyOut AS DWORD _                     ' __in  LPDWORD pAdjacencyOut
   , BYREF pFaceRemap AS DWORD _                        ' __out DWORD* pFaceRemap
   , BYREF ppVertexRemap AS ID3DXBuffer _               ' __out LPD3DXBUFFER *ppVertexRemap
   , BYREF pMaxVertexInfl AS DWORD _                    ' __out DWORD* pMaxVertexInfl
   , BYREF pNumBoneCombinations AS DWORD _              ' __out DWORD* pNumBoneCombinations
   , BYREF ppBoneCombinationTable AS ID3DXBuffer _      ' __out LPD3DXBUFFER* ppBoneCombinationTable
   , BYREF ppMesh AS ID3DXMesh _                        ' __out LPD3DXMESH* ppMesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


DECLARE FUNCTION D3DXCreateMesh IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateMesh" ( _
   BYVAL NumFaces AS DWORD _                            ' __in  DWORD NumFaces
 , BYVAL NumVertices AS DWORD _                         ' __in  DWORD NumVertices
 , BYVAL Options AS DWORD _                             ' __in  DWORD Options
 , BYREF pDeclaration AS D3DVERTEXELEMENT9 _            ' __in  CONST D3DVERTEXELEMENT9 *pDeclaration
 , BYVAL pD3DDevice AS IDirect3DDevice9 _               ' __in  LPDIRECT3DDEVICE9 pD3DDevice
 , BYREF ppMesh AS ID3DXMesh _                          ' __out LPD3DXMESH* ppMesh
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateMeshFVF IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateMeshFVF" ( _
   BYVAL NumFaces AS DWORD _                            ' __in  DWORD NumFaces
 , BYVAL NumVertices AS DWORD _                         ' __in  DWORD NumVertices
 , BYVAL Options AS DWORD _                             ' __in  DWORD Options
 , BYVAL FVF AS DWORD _                                 ' __in  DWORD FVF
 , BYVAL pD3DDevice AS IDirect3DDevice9 _               ' __in  LPDIRECT3DDEVICE9 pD3DDevice
 , BYREF ppMesh AS ID3DXMesh _                          ' __out LPD3DXMESH* ppMesh
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateSPMesh IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateSPMesh" ( _
   BYVAL pMesh AS ID3DXMesh _                           ' __in  LPD3DXMESH pMesh
 , BYREF pAdjacency AS DWORD _                          ' __in  CONST DWORD* pAdjacency
 , BYREF pVertexAttributeWeights AS D3DXATTRIBUTEWEIGHTS _ ' __in  CONST D3DXATTRIBUTEWEIGHTS *pVertexAttributeWeights
 , BYREF pVertexWeights AS SINGLE _                     ' __in  CONST FLOAT *pVertexWeights
 , BYVAL ppSMesh AS ID3DXSPMesh _                       ' __out LPD3DXSPMESH* ppSMesh
 ) AS LONG                                              ' HRESULT

'// clean a mesh up for simplification, try to make manifold
DECLARE FUNCTION D3DXCleanMesh IMPORT $D3DX_DLLNAME ALIAS "D3DXCleanMesh" ( _
   BYVAL CleanType AS DWORD _                           ' __in  D3DXCLEANTYPE CleanType
 , BYVAL pMeshIn AS ID3DXMesh _                         ' __in  LPD3DXMESH pMeshIn
 , BYREF pAdjacencyIn AS DWORD _                        ' __in  CONST DWORD* pAdjacencyIn
 , BYREF ppMeshOut AS ID3DXMesh _                       ' __out LPD3DXMESH* ppMeshOut
 , BYREF pAdjacencyOut AS DWORD _                       ' __out DWORD* pAdjacencyOut
 , BYREF ppErrorsAndWarnings AS ID3DXBuffer _           ' __out LPD3DXBUFFER* ppErrorsAndWarnings
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXValidMesh IMPORT $D3DX_DLLNAME ALIAS "D3DXValidMesh" ( _
   BYVAL pMeshIn AS ID3DXMesh _                         ' __in  LPD3DXMESH pMeshIn
 , BYREF pAdjacency AS DWORD _                          ' __in  CONST DWORD* pAdjacency
 , BYREF ppErrorsAndWarnings AS ID3DXBuffer _           ' __out LPD3DXBUFFER* ppErrorsAndWarnings
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXGeneratePMesh IMPORT $D3DX_DLLNAME ALIAS "D3DXGeneratePMesh" ( _
   BYVAL pMesh AS ID3DXMesh _                           ' __in  LPD3DXMESH pMesh
 , BYREF pAdjacency AS DWORD _                          ' __in  CONST DWORD* pAdjacency
 , BYREF pVertexAttributeWeights AS D3DXATTRIBUTEWEIGHTS _ ' __in  CONST D3DXATTRIBUTEWEIGHTS *pVertexAttributeWeights
 , BYREF pVertexWeights AS SINGLE _                     ' __in  CONST FLOAT *pVertexWeights
 , BYVAL MinValue AS DWORD _                            ' __in  DWORD MinValue
 , BYVAL Options AS DWORD _                             ' __in  DWORD Options
 , BYREF ppPMesh AS ID3DXPMesh _                        ' __out LPD3DXPMESH* ppPMesh
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXSimplifyMesh IMPORT $D3DX_DLLNAME ALIAS "D3DXSimplifyMesh" ( _
   BYVAL pMesh AS ID3DXMesh _                           ' __in  LPD3DXMESH pMesh
 , BYREF pAdjacency AS DWORD _                          ' __in  CONST DWORD* pAdjacency
 , BYREF pVertexAttributeWeights AS D3DXATTRIBUTEWEIGHTS _ ' __in  CONST D3DXATTRIBUTEWEIGHTS *pVertexAttributeWeights
 , BYREF pVertexWeights AS SINGLE _                     ' __in  CONST FLOAT *pVertexWeights
 , BYVAL MinValue AS DWORD _                            ' __in  DWORD MinValue
 , BYVAL Options AS DWORD _                             ' __in  DWORD Options
 , BYREF ppMesh AS ID3DXMesh _                          ' __out LPD3DXMESH* ppMesh
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXComputeBoundingSphere IMPORT $D3DX_DLLNAME ALIAS "D3DXComputeBoundingSphere" ( _
   BYREF pFirstPosition AS D3DXVECTOR3 _                ' __in  CONST D3DXVECTOR3 *pFirstPosition
 , BYVAL NumVertices AS DWORD _                         ' __in  DWORD NumVertices
 , BYVAL dwStride AS DWORD _                            ' __in  DWORD dwStride
 , BYREF pCenter AS D3DXVECTOR3 _                       ' __out D3DXVECTOR3 *pCenter
 , BYREF pRadius AS SINGLE _                            ' __out FLOAT *pRadius
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXComputeBoundingBox IMPORT $D3DX_DLLNAME ALIAS "D3DXComputeBoundingBox" ( _
   BYREF pFirstPosition AS D3DXVECTOR3 _                ' __in  CONST D3DXVECTOR3 *pFirstPosition
 , BYVAL NumVertices AS DWORD _                         ' __in  DWORD NumVertices
 , BYVAL dwStride AS DWORD _                            ' __in  DWORD dwStride
 , BYREF pMin AS D3DXVECTOR3 _                          ' __out D3DXVECTOR3 *pMin
 , BYREF pMax AS D3DXVECTOR3 _                          ' __out D3DXVECTOR3 *pMax
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXComputeNormals IMPORT $D3DX_DLLNAME ALIAS "D3DXComputeNormals" ( _
   BYVAL pMesh AS ID3DXBaseMesh  _                      ' __in_out LPD3DXBASEMESH pMesh
 , BYREF pAdjacency AS DWORD _                          ' __in CONST DWORD *pAdjacency
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateBuffer IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateBuffer" ( _
   BYVAL NumBytes AS DWORD _                            ' __in  DWORD NumBytes
 , BYREF ppBuffer AS ID3DXBuffer _                      ' __out LPD3DXBUFFER *ppBuffer
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXLoadMeshFromXA IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadMeshFromXA" ( _
   BYREF pFilename AS ASCIIZ _                          ' __in  LPCSTR pFilename
 , BYVAL Options AS DWORD _                             ' __in  DWORD Options
 , BYVAL pD3DDevice AS IDirect3DDevice9 _               ' __in  LPDIRECT3DDEVICE9 pD3DDevice
 , BYREF ppAdjacency AS ID3DXBuffer _                   ' __out LPD3DXBUFFER *ppAdjacency
 , BYREF ppMaterials AS ID3DXBuffer _                   ' __out LPD3DXBUFFER *ppMaterials
 , BYREF ppEffectInstances AS ID3DXBuffer _             ' __out LPD3DXBUFFER *ppEffectInstances
 , BYREF pNumMaterials AS DWORD _                       ' __out DWORD *pNumMaterials
 , BYREF ppMesh AS ID3DXMesh _                          ' __out LPD3DXMESH *ppMesh
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXLoadMeshFromXW IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadMeshFromXW" ( _
   BYREF pFilename AS WSTRINGZ _                        ' __in  LPCWSTR pFilename
 , BYVAL Options AS DWORD _                             ' __in  DWORD Options
 , BYVAL pD3DDevice AS IDirect3DDevice9 _               ' __in  LPDIRECT3DDEVICE9 pD3DDevice
 , BYREF ppAdjacency AS ID3DXBuffer _                   ' __out LPD3DXBUFFER *ppAdjacency
 , BYREF ppAdjacency AS ID3DXBuffer _                   ' __out LPD3DXBUFFER *ppMaterials
 , BYREF ppEffectInstances AS ID3DXBuffer _             ' __out LPD3DXBUFFER *ppEffectInstances
 , BYREF pNumMaterials AS DWORD _                       ' __out DWORD *pNumMaterials
 , BYREF ppMesh AS ID3DXMesh _                          ' __out LPD3DXMESH *ppMesh
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXLoadMeshFromX = D3DXLoadMeshFromXW
#ELSE
   MACRO D3DXLoadMeshFromX = D3DXLoadMeshFromXA
#ENDIF

DECLARE FUNCTION D3DXLoadMeshFromXInMemory IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadMeshFromXInMemory" ( _
   BYVAL Memory AS DWORD _                              ' __in  LPCVOID Memory
 , BYVAL SizeOfMemory AS DWORD _                        ' __in  DWORD SizeOfMemory
 , BYVAL Options AS DWORD _                             ' __in  DWORD Options
 , BYVAL pD3DDevice AS IDirect3DDevice9 _               ' __in  LPDIRECT3DDEVICE9 pD3DDevice
 , BYREF ppAdjacency AS ID3DXBuffer _                   ' __out LPD3DXBUFFER *ppAdjacency
 , BYREF ppMaterials AS ID3DXBuffer _                   ' __out LPD3DXBUFFER *ppMaterials
 , BYREF ppEffectInstances AS ID3DXBuffer _             ' __out LPD3DXBUFFER *ppEffectInstances
 , BYREF pNumMaterials AS DWORD _                       ' __out DWORD *pNumMaterials
 , BYREF ppMesh AS ID3DXMesh _                          ' __out LPD3DXMESH *ppMesh
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXLoadMeshFromXResource IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadMeshFromXResource" ( _
   BYVAL Module AS DWORD _                              ' __in  HMODULE Module
 , BYREF Name AS ASCIIZ _                               ' __in  LPCSTR Name
 , BYREF Type AS ASCIIZ _                               ' __in  LPCSTR Type
 , BYVAL Options AS DWORD _                             ' __in  DWORD Options
 , BYVAL pD3DDevice AS IDirect3DDevice9 _               ' __in  LPDIRECT3DDEVICE9 pD3DDevice
 , BYREF ppAdjacency AS ID3DXBuffer _                   ' __out LPD3DXBUFFER *ppAdjacency
 , BYREF ppMaterials AS ID3DXBuffer _                   ' __out LPD3DXBUFFER *ppMaterials
 , BYREF ppEffectInstances AS ID3DXBuffer _             ' __out LPD3DXBUFFER *ppEffectInstances
 , BYREF pNumMaterials AS DWORD _                       ' __out DWORD *pNumMaterials
 , BYREF ppMesh AS ID3DXMesh _                          ' __out LPD3DXMESH *ppMesh
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXSaveMeshToXA IMPORT $D3DX_DLLNAME ALIAS "D3DXSaveMeshToXA" ( _
   BYREF pFilename AS ASCIIZ _                          ' __in LPCSTR pFilename
 , BYVAL pMesh AS ID3DXMesh _                           ' __in LPD3DXMESH pMesh
 , BYREF pAdjacency AS DWORD _                          ' __in CONST DWORD* pAdjacency
 , BYREF pMaterials AS D3DXMATERIAL _                   ' __in CONST D3DXMATERIAL* pMaterials
 , BYREF pEffectInstances AS D3DXEFFECTINSTANCE _       ' __in CONST D3DXEFFECTINSTANCE* pEffectInstances
 , BYVAL NumMaterials AS DWORD _                        ' __in DWORD NumMaterials
 , BYVAL Format AS DWORD _                              ' __in DWORD Format
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXSaveMeshToXW IMPORT $D3DX_DLLNAME ALIAS "D3DXSaveMeshToXW" ( _
   BYREF pFilename AS WSTRINGZ _                        ' __in LPCWSTR pFilename
 , BYVAL pMesh AS ID3DXMesh _                           ' __in LPD3DXMESH pMesh
 , BYREF pAdjacency AS DWORD _                          ' __in CONST DWORD* pAdjacency
 , BYREF pMaterials AS D3DXMATERIAL _                   ' __in CONST D3DXMATERIAL* pMaterials
 , BYREF pEffectInstances AS D3DXEFFECTINSTANCE _       ' __in CONST D3DXEFFECTINSTANCE* pEffectInstances
 , BYVAL NumMaterials AS DWORD _                        ' __in DWORD NumMaterials
 , BYVAL Format AS DWORD _                              ' __in DWORD Format
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXSaveMeshToX = D3DXSaveMeshToXW
#ELSE
   MACRO D3DXSaveMeshToX = D3DXSaveMeshToXA
#ENDIF

DECLARE FUNCTION D3DXCreatePMeshFromStream IMPORT $D3DX_DLLNAME ALIAS "D3DXCreatePMeshFromStream" ( _
   BYVAL pStream AS IStream _                           ' __in  IStream *pStream
 , BYVAL Options AS DWORD _                             ' __in  DWORD Options
 , BYVAL pD3DDevice AS IDirect3DDevice9 _               ' __in  LPDIRECT3DDEVICE9 pD3DDevice
 , BYREF ppMaterials AS ID3DXBuffer _                   ' __out LPD3DXBUFFER *ppMaterials
 , BYREF ppEffectInstances AS ID3DXBuffer _             ' __out LPD3DXBUFFER *ppEffectInstances
 , BYREF pNumMaterials AS DWORD _                       ' __out DWORD* pNumMaterials
 , BYREF ppPMesh AS ID3DXPMesh _                        ' __out LPD3DXPMESH *ppPMesh
 ) AS LONG                                              ' HRESULT

'// Creates a skin info object based on the number of vertices, number of bones, and a declaration describing the vertex layout of the target vertices
'// The bone names and initial bone transforms are not filled in the skin info object by this method.

DECLARE FUNCTION D3DXCreateSkinInfo IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateSkinInfo" ( _
   BYVAL NumVertices AS DWORD _                         ' __in  DWORD NumVertices
 , BYREF pDeclaration AS D3DVERTEXELEMENT9  _           ' __in  CONST D3DVERTEXELEMENT9 *pDeclaration
 , BYVAL NumBones AS DWORD _                            ' __in  DWORD NumBones
 , BYREF ppSkinInfo AS ID3DXSkinInfo _                  ' __out LPD3DXSKININFO* ppSkinInfo
 ) AS LONG                                              ' HRESULT


'// Creates a skin info object based on the number of vertices, number of bones, and a FVF describing the vertex layout of the target vertices
'// The bone names and initial bone transforms are not filled in the skin info object by this method.

DECLARE FUNCTION D3DXCreateSkinInfoFVF IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateSkinInfoFVF" ( _
   BYVAL NumVertices AS DWORD _                         ' __in  DWORD NumVertices
 , BYVAL FVF AS DWORD _                                 ' __in  DWORD FVF
 , BYVAL NumBones AS DWORD _                            ' __in  DWORD NumBones
 , BYREF ppSkinInfo AS ID3DXSkinInfo _                  ' __out LPD3DXSKININFO* ppSkinInfo
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXLoadMeshFromXof IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadMeshFromXof" ( _
   BYVAL pxofMesh AS ID3DXFileData _                    ' __in LPD3DXFILEDATA pxofMesh
 , BYVAL Options AS DWORD _                             ' __in DWORD Options
 , BYVAL pD3DDevice AS IDirect3DDevice9 _               ' __in LPDIRECT3DDEVICE9 pD3DDevice
 , BYREF ppAdjacency AS ID3DXBuffer _                   ' __out LPD3DXBUFFER *ppAdjacency
 , BYREF ppMaterials AS ID3DXBuffer _                   ' __in_out LPD3DXBUFFER *ppMaterials
 , BYREF ppEffectInstances AS ID3DXBuffer _             ' __out LPD3DXBUFFER *ppEffectInstances
 , BYREF pNumMaterials AS DWORD _                       ' __in_out DWORD *pNumMaterials
 , BYREF ppMesh AS ID3DXMesh _                          ' __out LPD3DXMESH *ppMesh
 ) AS LONG                                              ' HRESULT

'// This similar to D3DXLoadMeshFromXof, except also returns skinning info if present in the file
'// If skinning info is not present, ppSkinInfo will be NULL

DECLARE FUNCTION D3DXLoadSkinMeshFromXof IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadSkinMeshFromXof" ( _
   BYVAL pxofMesh AS ID3DXFileData _                    ' __in  LPD3DXFILEDATA pxofMesh
 , BYVAL Options AS DWORD _                             ' __in  DWORD Options
 , BYVAL pD3DDevice AS IDirect3DDevice9 _               ' __in  LPDIRECT3DDEVICE9 pD3DDevice
 , BYREF ppAdjacency AS ID3DXBuffer _                   ' __out LPD3DXBUFFER* ppAdjacency
 , BYREF ppMaterials AS ID3DXBuffer _                   ' __out LPD3DXBUFFER* ppMaterials
 , BYREF ppEffectInstances AS ID3DXBuffer _             ' __out LPD3DXBUFFER *ppEffectInstances
 , BYREF pMatOut AS DWORD _                             ' __out DWORD *pMatOut
 , BYREF ppSkinInfo AS ID3DXSkinInfo _                  ' __out LPD3DXSKININFO* ppSkinInfo
 , BYREF ppMesh AS ID3DXMesh _                          ' __out LPD3DXMESH* ppMesh
 ) AS LONG                                              ' HRESULT


'// The inverse of D3DXConvertTo{Indexed}BlendedMesh() functions. It figures out the skinning info from
'// the mesh and the bone combination table and populates a skin info object with that data. The bone
'// names and initial bone transforms are not filled in the skin info object by this method. This works
'// with either a non-indexed or indexed blended mesh. It examines the FVF or declarator of the mesh to
'// determine what type it is.

DECLARE FUNCTION D3DXCreateSkinInfoFromBlendedMesh IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateSkinInfoFromBlendedMesh" ( _
   BYVAL pMesh AS ID3DXBaseMesh _                       ' __in  LPD3DXBASEMESH pMesh
 , BYVAL NumBones AS DWORD _                            ' __in  DWORD NumBones
 , BYREF pBoneCombinationTable AS D3DXBONECOMBINATION _ ' __in  CONST D3DXBONECOMBINATION *pBoneCombinationTable
 , BYREF ppSkinInfo AS ID3DXSkinInfo _                  ' __out LPD3DXSKININFO* ppSkinInfo
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXTessellateNPatches IMPORT $D3DX_DLLNAME ALIAS "D3DXTessellateNPatches" ( _
   BYVAL pMeshIn AS ID3DXMesh _                         ' __in  LPD3DXMESH pMeshIn
 , BYREF pAdjacencyIn AS DWORD _                        ' __in  CONST DWORD* pAdjacencyIn
 , BYVAL NumSegs AS SINGLE _                            ' __in  FLOAT NumSegs
 , BYVAL QuadraticInterpNormals AS LONG _               ' __in  BOOL  QuadraticInterpNormals
 , BYREF ppMeshOut AS ID3DXMesh _                       ' __out LPD3DXMESH *ppMeshOut
 , BYREF ppAdjacencyOut AS ID3DXBuffer _                ' __out LPD3DXBUFFER *ppAdjacencyOut
 ) AS LONG                                              ' HRESULT

'//generates implied outputdecl from input decl
'//the decl generated from this should be used to generate the output decl for
'//the tessellator subroutines.

DECLARE FUNCTION D3DXGenerateOutputDecl IMPORT $D3DX_DLLNAME ALIAS "D3DXGenerateOutputDecl" (_
   BYREF pOutput AS D3DVERTEXELEMENT9 _                 ' __out D3DVERTEXELEMENT9 *pOutput
 , BYREF pInput AS D3DVERTEXELEMENT9 _                  ' __in  CONST D3DVERTEXELEMENT9 *pInput
 ) AS LONG                                              ' HRESULT

'//loads patches from an XFileData
'//since an X file can have up to 6 different patch meshes in it,
'//returns them in an array - pNumPatches will contain the number of
'//meshes in the actual file.

DECLARE FUNCTION D3DXLoadPatchMeshFromXof IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadPatchMeshFromXof" (_
   BYVAL pXofObjMesh AS ID3DXFileData _                 ' __in  LPD3DXFILEDATA pXofObjMesh
 , BYVAL Options AS DWORD _                             ' __in  DWORD Options
 , BYVAL pD3DDevice AS IDirect3DDevice9 _               ' __in  LPDIRECT3DDEVICE9 pD3DDevice
 , BYREF ppMaterials AS ID3DXBuffer _                   ' __out LPD3DXBUFFER *ppMaterials
 , BYREF ppEffectInstances AS ID3DXBuffer _             ' __out LPD3DXBUFFER *ppEffectInstances
 , BYREF pNumMaterials AS DWORD _                       ' __out PDWORD pNumMaterials
 , BYREF ppMesh AS ID3DXPatchMesh _                     ' __out LPD3DXPATCHMESH *ppMesh
 ) AS LONG                                              ' HRESULT

'//computes the size a single rect patch.

DECLARE FUNCTION D3DXRectPatchSize IMPORT $D3DX_DLLNAME ALIAS "D3DXRectPatchSize" (_
   BYVAL pfNumSegs AS SINGLE _                          ' __in  CONST FLOAT *pfNumSegs
 , BYREF pdwTriangles AS DWORD _                        ' __out DWORD *pdwTriangles
 , BYREF pdwVertices AS DWORD _                         ' __out DWORD *pdwVertices
 ) AS LONG                                              ' HRESULT

'//computes the size of a single triangle patch

DECLARE FUNCTION D3DXTriPatchSize IMPORT $D3DX_DLLNAME ALIAS "D3DXTriPatchSize" (_
   BYVAL pfNumSegs AS SINGLE _                          ' __in  CONST FLOAT *pfNumSegs
 , BYREF pdwTriangles AS DWORD _                        ' __out DWORD *pdwTriangles
 , BYREF pdwVertices AS DWORD _                         ' __out DWORD *pdwVertices
 ) AS LONG                                              ' HRESULT

'//tessellates a patch into a created mesh
'//similar to D3D RT patch

DECLARE FUNCTION D3DXTessellateRectPatch IMPORT $D3DX_DLLNAME ALIAS "D3DXTessellateRectPatch" (_
   BYVAL pVB AS IDirect3DVertexBuffer9 _                ' __in LPDIRECT3DVERTEXBUFFER9 pVB
 , BYREF pNumSegs AS SINGLE _                           ' __in CONST FLOAT *pNumSegs
 , BYREF pdwInDecl AS D3DVERTEXELEMENT9 _               ' __in CONST D3DVERTEXELEMENT9 *pdwInDecl
 , BYREF pRectPatchInfo AS D3DRECTPATCH_INFO _          ' __in CONST D3DRECTPATCH_INFO *pRectPatchInfo
 , BYREF pMesh AS ID3DXMesh _                           ' __in_out LPD3DXMESH pMesh
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXTessellateTriPatch IMPORT $D3DX_DLLNAME ALIAS "D3DXTessellateTriPatch" (_
   BYVAL pVB AS IDirect3DVertexBuffer9 _                ' __in LPDIRECT3DVERTEXBUFFER9 pVB
 , BYREF pNumSegs AS SINGLE _                           ' __in CONST FLOAT *pNumSegs
 , BYREF pInDecl AS D3DVERTEXELEMENT9 _                 ' __in CONST D3DVERTEXELEMENT9 *pInDecl
 , BYREF pTriPatchInfo AS D3DTRIPATCH_INFO _            ' __in CONST D3DTRIPATCH_INFO *pTriPatchInfo
 , BYREF pMesh AS ID3DXMesh _                           ' __in_out LPD3DXMESH pMesh
 ) AS LONG                                              ' HRESULT

'//creates an NPatch PatchMesh from a D3DXMESH

DECLARE FUNCTION D3DXCreateNPatchMesh IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateNPatchMesh" (_
   BYVAL pMeshSysMem AS ID3DXMesh  _                    ' __in LPD3DXMESH pMeshSysMem
 , BYREF pPatchMesh AS ID3DXPatchMesh _                 ' __in_out LPD3DXPATCHMESH *pPatchMesh
 ) AS LONG                                              ' HRESULT

'//creates a patch mesh

DECLARE FUNCTION D3DXCreatePatchMesh IMPORT $D3DX_DLLNAME ALIAS "D3DXCreatePatchMesh" (_
   BYREF pInfo AS D3DXPATCHINFO _                       ' __in  CONST D3DXPATCHINFO *pInfo
 , BYVAL dwNumPatches AS DWORD _                        ' __in  DWORD dwNumPatches
 , BYVAL dwNumVertices AS DWORD _                       ' __in  DWORD dwNumVertices
 , BYVAL dwOptions AS DWORD _                           ' __in  DWORD dwOptions
 , BYREF pDecl AS D3DVERTEXELEMENT9 _                   ' __in  CONST D3DVERTEXELEMENT9 *pDecl
 , BYVAL pD3DDevice AS IDirect3DDevice9 _               ' __in  LPDIRECT3DDEVICE9 pD3DDevice
 , BYREF pPatchMesh AS ID3DXPatchMesh _                 ' __out LPD3DXPATCHMESH *pPatchMesh
 ) AS LONG                                              ' HRESULT

'//returns the number of degenerates in a patch mesh -
'//text output put in string.

DECLARE FUNCTION D3DXValidPatchMesh IMPORT $D3DX_DLLNAME ALIAS "D3DXValidPatchMesh" (_
   BYVAL pMesh AS ID3DXPatchMesh _                      ' __in  LPD3DXPATCHMESH pMesh
 , BYREF dwcDegenerateVertices AS DWORD _               ' __out DWORD *dwcDegenerateVertices
 , BYREF dwcDegeneratePatches AS DWORD _                ' __out DWORD *dwcDegeneratePatches
 , BYREF ppErrorsAndWarnings AS ID3DXBuffer _           ' __out LPD3DXBUFFER *ppErrorsAndWarnings
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXGetFVFVertexSize IMPORT $D3DX_DLLNAME ALIAS "D3DXGetFVFVertexSize" (_
   BYVAL FVF AS DWORD _                                 ' __in DWORD FVF
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION D3DXGetDeclVertexSize IMPORT $D3DX_DLLNAME ALIAS "D3DXGetDeclVertexSize" (_
   BYREF pDecl AS D3DVERTEXELEMENT9  _                  ' __in CONST D3DVERTEXELEMENT9 *pDecl
 , BYVAL Stream AS DWORD _                              ' __in DWORD Stream
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION D3DXGetDeclLength IMPORT $D3DX_DLLNAME ALIAS "D3DXGetDeclLength" (_
   BYREF pDecl AS D3DVERTEXELEMENT9 _                   ' __in CONST D3DVERTEXELEMENT9 *pDecl
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION D3DXDeclaratorFromFVF IMPORT $D3DX_DLLNAME ALIAS "D3DXDeclaratorFromFVF" (_
   BYVAL FVF AS DWORD _                                 ' __in DWORD FVF
 , BYREF pDeclarator AS D3DVERTEXELEMENT9 _             ' __in_out D3DVERTEXELEMENT9 pDeclarator[MAX_FVF_DECL_SIZE]
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXFVFFromDeclarator IMPORT $D3DX_DLLNAME ALIAS "D3DXFVFFromDeclarator" (_
   BYREF pDeclarator AS D3DVERTEXELEMENT9 _             ' __in  CONST D3DVERTEXELEMENT9 *pDeclarator
 , BYREF pFVF AS DWORD _                                ' __out DWORD *pFVF
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXWeldVertices IMPORT $D3DX_DLLNAME ALIAS "D3DXWeldVertices" (_
   BYVAL pMesh AS ID3DXMesh _                           ' __in LPD3DXMESH pMesh
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF pEpsilons AS D3DXWELDEPSILONS _                ' __in CONST D3DXWELDEPSILONS *pEpsilons
 , BYREF pAdjacencyIn AS DWORD _                        ' __in_out CONST DWORD *pAdjacencyIn
 , BYVAL pAdjacencyOut AS DWORD _                       ' __in_out DWORD *pAdjacencyOut
 , BYREF pFaceRemap AS DWORD _                          ' __out DWORD *pFaceRemap
 , BYREF ppVertexRemap AS ID3DXBuffer _                 ' __out LPD3DXBUFFER *ppVertexRemap
 ) AS LONG                                              ' HRESULT

' // Size = 16 bytes
TYPE D3DXINTERSECTINFO DWORD
   FaceIndex AS DWORD    ' DWORD // index of face intersected
   U         AS SINGLE   ' FLOAT // Barycentric Hit Coordinates
   V         AS SINGLE   ' FLOAT // Barycentric Hit Coordinates
   Dist      AS SINGLE   ' FLOAT // Ray-Intersection Parameter Distance
END TYPE

DECLARE FUNCTION D3DXIntersect IMPORT $D3DX_DLLNAME ALIAS "D3DXIntersect" (_
   BYVAL pMesh AS ID3DXBaseMesh _                       ' __in  LPD3DXBASEMESH     pMesh
 , BYREF pRayPos AS D3DXVECTOR3 _                       ' __in  CONST D3DXVECTOR3 *pRayPos
 , BYREF pRayDir AS D3DXVECTOR3 _                       ' __in  CONST D3DXVECTOR3 *pRayDir
 , BYREF pHit AS LONG _                                 ' __out BOOL              *pHit
 , BYREF pFaceIndex AS DWORD _                          ' __out DWORD             *pFaceIndex
 , BYREF pU AS SINGLE _                                 ' __out FLOAT             *pU
 , BYREF pV AS SINGLE _                                 ' __out FLOAT             *pV
 , BYREF pDist AS SINGLE _                              ' __out FLOAT             *pDist
 , BYREF ppAllHits AS ID3DXBuffer _                     ' __out LPD3DXBUFFER      *ppAllHits
 , BYREF pCountOfHits AS DWORD _                        ' __out DWORD             *pCountOfHits
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXIntersectSubset IMPORT $D3DX_DLLNAME ALIAS "D3DXIntersectSubset" (_
   BYVAL pMesh AS ID3DXBaseMesh _                       ' __in  LPD3DXBASEMESH     pMesh
 , BYVAL AttribId AS DWORD _                            ' __in  DWORD              AttribId
 , BYREF pRayPos AS D3DXVECTOR3 _                       ' __in  CONST D3DXVECTOR3 *pRayPos
 , BYREF pRayDir AS D3DXVECTOR3 _                       ' __in  CONST D3DXVECTOR3 *pRayDir
 , BYREF pHit AS LONG _                                 ' __out BOOL              *pHit
 , BYREF pFaceIndex AS DWORD _                          ' __out DWORD             *pFaceIndex
 , BYREF pU AS SINGLE _                                 ' __out FLOAT             *pU
 , BYREF pV AS SINGLE _                                 ' __out FLOAT             *pV
 , BYREF pDist AS SINGLE _                              ' __out FLOAT             *pDist
 , BYREF ppAllHits AS ID3DXBuffer _                     ' __out LPD3DXBUFFER      *ppAllHits
 , BYREF pCountOfHits AS DWORD _                        ' __out DWORD             *pCountOfHits
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXSplitMesh IMPORT $D3DX_DLLNAME ALIAS "D3DXSplitMesh" (_
   BYVAL pMeshIn AS ID3DXMesh _                         ' __in  LPD3DXMESH pMeshIn
 , BYREF pAdjacencyIn AS DWORD _                        ' __in  CONST DWORD *pAdjacencyIn
 , BYVAL MaxSize AS DWORD _                             ' __in  CONST DWORD MaxSize
 , BYVAL Options AS DWORD _                             ' __in  CONST DWORD Options
 , BYREF pMeshesOut AS DWORD _                          ' __out DWORD *pMeshesOut
 , BYREF ppMeshArrayOut AS ID3DXBuffer _                ' __out LPD3DXBUFFER *ppMeshArrayOut
 , BYREF ppAdjacencyArrayOut AS ID3DXBuffer _           ' __out LPD3DXBUFFER *ppAdjacencyArrayOut
 , BYREF ppFaceRemapArrayOut AS ID3DXBuffer _           ' __out LPD3DXBUFFER *ppFaceRemapArrayOut
 , BYREF ppVertRemapArrayOut AS ID3DXBuffer _           ' __out LPD3DXBUFFER *ppVertRemapArrayOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXIntersectTri IMPORT $D3DX_DLLNAME ALIAS "D3DXIntersectTri" (_
   BYREF p0 AS D3DXVECTOR3 _                            ' __in  CONST D3DXVECTOR3 *p0
 , BYREF p1 AS D3DXVECTOR3 _                            ' __in  CONST D3DXVECTOR3 *p1
 , BYREF p2 AS D3DXVECTOR3 _                            ' __in  CONST D3DXVECTOR3 *p2
 , BYREF pRayPos AS D3DXVECTOR3 _                       ' __in  CONST D3DXVECTOR3 *pRayPos
 , BYREF pRayDir AS D3DXVECTOR3 _                       ' __in  CONST D3DXVECTOR3 *pRayDir
 , BYREF pU AS SINGLE _                                 ' __out FLOAT *pU
 , BYREF pV AS SINGLE _                                 ' __out FLOAT *pV
 , BYREF pDist AS SINGLE _                              ' __out FLOAT *pDist
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXSphereBoundProbe IMPORT $D3DX_DLLNAME ALIAS "D3DXSphereBoundProbe" (_
   BYREF pCenter AS D3DXVECTOR3 _                       ' __in CONST D3DXVECTOR3 *pCenter
 , BYVAL Radius AS SINGLE _                             ' __in FLOAT Radius
 , BYREF pRayPosition AS D3DXVECTOR3 _                  ' __in CONST D3DXVECTOR3 *pRayPosition
 , BYREF pRayDirection AS D3DXVECTOR3 _                 ' __in CONST D3DXVECTOR3 *pRayDirection
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXBoxBoundProbe IMPORT $D3DX_DLLNAME ALIAS "D3DXBoxBoundProbe" (_
   BYREF pMin AS D3DXVECTOR3 _                          ' __in CONST D3DXVECTOR3 *pMin
 , BYREF pMax AS D3DXVECTOR3 _                          ' __in CONST D3DXVECTOR3 *pMax
 , BYREF pRayPosition AS D3DXVECTOR3 _                  ' __in CONST D3DXVECTOR3 *pRayPosition
 , BYREF pRayDirection AS D3DXVECTOR3 _                 ' __in CONST D3DXVECTOR3 *pRayDirection
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXComputeTangentFrame IMPORT $D3DX_DLLNAME ALIAS "D3DXComputeTangentFrame" (_
   BYVAL pMesh AS ID3DXMesh _                           ' __in ID3DXMesh *pMesh
 , BYVAL dwOptions AS DWORD _                           ' __in DWORD dwOptions
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXComputeTangentFrameEx IMPORT $D3DX_DLLNAME ALIAS "D3DXComputeTangentFrameEx" (_
   BYVAL pMesh AS ID3DXMesh _                           ' __in  ID3DXMesh *pMesh
 , BYVAL dwTextureInSemantic AS DWORD _                 ' __in  DWORD dwTextureInSemantic
 , BYVAL dwTextureInIndex AS DWORD _                    ' __in  DWORD dwTextureInIndex
 , BYVAL dwUPartialOutSemantic AS DWORD _               ' __in  DWORD dwUPartialOutSemantic
 , BYVAL dwUPartialOutIndex AS DWORD _                  ' __in  DWORD dwUPartialOutIndex
 , BYVAL dwVPartialOutSemantic AS DWORD _               ' __in  DWORD dwVPartialOutSemantic
 , BYVAL dwVPartialOutIndex AS DWORD _                  ' __in  DWORD dwVPartialOutIndex
 , BYVAL dwNormalOutSemantic AS DWORD _                 ' __in  DWORD dwNormalOutSemantic
 , BYVAL dwNormalOutIndex AS DWORD _                    ' __in  DWORD dwNormalOutIndex
 , BYVAL dwOptions AS DWORD _                           ' __in  DWORD dwOptions
 , BYREF pdwAdjacency AS DWORD _                        ' __in  CONST DWORD *pdwAdjacency
 , BYVAL fPartialEdgeThreshold AS SINGLE _              ' __in  FLOAT fPartialEdgeThreshold
 , BYVAL fSingularPointThreshold AS SINGLE _            ' __in  FLOAT fSingularPointThreshold
 , BYVAL fNormalEdgeThreshold AS SINGLE _               ' __in  FLOAT fNormalEdgeThreshold
 , BYREF ppMeshOut AS ID3DXMesh _                       ' __out ID3DXMesh **ppMeshOut
 , BYREF ppVertexMapping AS ID3DXBuffer _               ' __out ID3DXBuffer **ppVertexMapping
 ) AS LONG                                              ' HRESULT

'//D3DXComputeTangent
'//
'//Computes the Tangent vectors for the TexStage texture coordinates
'//and places the results in the TANGENT[TangentIndex] specified in the meshes' DECL
'//puts the binorm in BINORM[BinormIndex] also specified in the decl.
'//
'//If neither the binorm or the tangnet are in the meshes declaration,
'//the function will fail.
'//
'//If a tangent or Binorm field is in the Decl, but the user does not
'//wish D3DXComputeTangent to replace them, then D3DX_DEFAULT specified
'//in the TangentIndex or BinormIndex will cause it to ignore the specified
'//semantic.
'//
'//Wrap should be specified if the texture coordinates wrap.

DECLARE FUNCTION D3DXComputeTangent IMPORT $D3DX_DLLNAME ALIAS "D3DXComputeTangent" (_
   BYVAL Mesh AS ID3DXMesh _                            ' __in LPD3DXMESH Mesh
 , BYVAL TexStage AS DWORD _                            ' __in DWORD TexStage
 , BYVAL TangentIndex AS DWORD _                        ' __in DWORD TangentIndex
 , BYVAL BinormIndex AS DWORD _                         ' __in DWORD BinormIndex
 , BYVAL Wrap AS DWORD _                                ' __in DWORD Wrap
 ) AS LONG                                              ' HRESULT

'//============================================================================
'//
'// UVAtlas apis
'//
'//============================================================================
'typedef HRESULT (WINAPI *LPD3DXUVATLASCB)(FLOAT fPercentDone,  LPVOID lpUserContext);

'// This function creates atlases for meshes. There are two modes of operation,
'// either based on the number of charts, or the maximum allowed stretch. If the
'// maximum allowed stretch is 0, then each triangle will likely be in its own
'// chart.

'//
'// The parameters are as follows:
'//  pMesh - Input mesh to calculate an atlas for. This must have a position
'//          channel and at least a 2-d texture channel.
'//  uMaxChartNumber - The maximum number of charts required for the atlas.
'//                    If this is 0, it will be parameterized based solely on
'//                    stretch.
'//  fMaxStretch - The maximum amount of stretch, if 0, no stretching is allowed,
'//                if 1, then any amount of stretching is allowed.
'//  uWidth - The width of the texture the atlas will be used on.
'//  uHeight - The height of the texture the atlas will be used on.
'//  fGutter - The minimum distance, in texels between two charts on the atlas.
'//            this gets scaled by the width, so if fGutter is 2.5, and it is
'//            used on a 512x512 texture, then the minimum distance will be
'//            2.5 / 512 in u-v space.
'//  dwTextureIndex - Specifies which texture coordinate to write to in the
'//                   output mesh (which is cloned from the input mesh). Useful
'//                   if your vertex has multiple texture coordinates.
'//  pdwAdjacency - a pointer to an array with 3 DWORDs per face, indicating
'//                 which triangles are adjacent to each other.
'//  pdwFalseEdgeAdjacency - a pointer to an array with 3 DWORDS per face, indicating
'//                          at each face, whether an edge is a false edge or not (using
'//                          the same ordering as the adjacency data structure). If this
'//                          is NULL, then it is assumed that there are no false edges. If
'//                          not NULL, then a non-false edge is indicated by -1 and a false
'//                          edge is indicated by any other value (it is not required, but
'//                          it may be useful for the caller to use the original adjacency
'//                          value). This allows you to parameterize a mesh of quads, and
'//                          the edges down the middle of each quad will not be cut when
'//                          parameterizing the mesh.
'//  pfIMTArray - a pointer to an array with 3 FLOATs per face, describing the
'//               integrated metric tensor for that face. This lets you control
'//               the way this triangle may be stretched in the atlas. The IMT
'//               passed in will be 3 floats (a,b,c) and specify a symmetric
'//               matrix (a b) that, given a vector (s,t), specifies the
'//                      (b c)
'//               distance between a vector v1 and a vector v2 = v1 + (s,t) as
'//               sqrt((s, t) * M * (s, t)^T).
'//               In other words, this lets one specify the magnitude of the
'//               stretch in an arbitrary direction in u-v space. For example
'//               if a = b = c = 1, then this scales the vector (1,1) by 2, and
'//               the vector (1,-1) by 0. Note that this is multiplying the edge
'//               length by the square of the matrix, so if you want the face to
'//               stretch to twice its
'//               size with no shearing, the IMT value should be (2, 0, 2), which
'//               is just the identity matrix times 2.
'//               Note that this assumes you have an orientation for the triangle
'//               in some 2-D space. For D3DXUVAtlas, this space is created by
'//               letting S be the direction from the first to the second
'//               vertex, and T be the cross product between the normal and S.
'//
'//  pStatusCallback - Since the atlas creation process can be very CPU intensive,
'//                    this allows the programmer to specify a function to be called
'//                    periodically, similarly to how it is done in the PRT simulation
'//                    engine.
'//  fCallbackFrequency - This lets you specify how often the callback will be
'//                       called. A decent default should be 0.0001f.
'//  pUserContext - a void pointer to be passed back to the callback function
'//  dwOptions - A combination of flags in the D3DXUVATLAS enum
'//  ppMeshOut - A pointer to a location to store a pointer for the newly created
'//              mesh.
'//  ppFacePartitioning - A pointer to a location to store a pointer for an array,
'//                       one DWORD per face, giving the final partitioning
'//                       created by the atlasing algorithm.
'//  ppVertexRemapArray - A pointer to a location to store a pointer for an array,
'//                       one DWORD per vertex, giving the vertex it was copied
'//                       from, if any vertices needed to be split.
'//  pfMaxStretchOut - A location to store the maximum stretch resulting from the
'//                    atlasing algorithm.
'//  puNumChartsOut -  A location to store the number of charts created, or if the
'//                    maximum number of charts was too low, this gives the minimum
'//                    number of charts needed to create an atlas.

DECLARE FUNCTION D3DXUVAtlasCreate IMPORT $D3DX_DLLNAME ALIAS "D3DXUVAtlasCreate" (_
   BYVAL Mesh AS ID3DXMesh _                            ' __in  LPD3DXMESH Mesh
 , BYVAL uMaxChartNumber AS DWORD _                     ' __in  UINT uMaxChartNumber
 , BYVAL fMaxStretch AS SINGLE _                        ' __in  FLOAT fMaxStretch
 , BYVAL uWidth AS DWORD _                              ' __in  UINT uWidth
 , BYVAL uHeight AS DWORD _                             ' __in  UINT uHeight
 , BYVAL fGutter AS SINGLE _                            ' __in  FLOAT fGutter
 , BYVAL dwTextureIndex AS DWORD _                      ' __in  DWORD dwTextureIndex
 , BYREF pdwAdjacency AS DWORD _                        ' __in  CONST DWORD *pdwAdjacency
 , BYREF pdwFalseEdgeAdjacency AS DWORD _               ' __in  CONST DWORD *pdwFalseEdgeAdjacency
 , BYREF pfIMTArray AS SINGLE _                         ' __in  CONST FLOAT *pfIMTArray
 , BYVAL pStatusCallback AS DWORD _                     ' __in  LPD3DXUVATLASCB pStatusCallback
 , BYVAL fCallbackFrequency AS SINGLE _                 ' __in  FLOAT fCallbackFrequency
 , BYVAL pUserContext AS DWORD _                        ' __in  LPVOID pUserContext
 , BYVAL dwOptions AS DWORD _                           ' __in  DWORD dwOptions
 , BYREF ppMeshOut AS ID3DXMesh _                       ' __in  LPD3DXMESH *ppMeshOut
 , BYREF ppFacePartitioning AS ID3DXBuffer _            ' __in  LPD3DXBUFFER *ppFacePartitioning
 , BYREF ppVertexRemapArray AS ID3DXBuffer _            ' __out LPD3DXBUFFER *ppVertexRemapArray
 , BYREF pfMaxStretchOut AS SINGLE _                    ' __out FLOAT *pfMaxStretchOut
 , BYREF puNumChartsOut AS DWORD _                      ' __out UINT *puNumChartsOut
 ) AS LONG                                              ' HRESULT

'// This has the same exact arguments as Create, except that it does not perform the
'// final packing step. This method allows one to get a partitioning out, and possibly
'// modify it before sending it to be repacked. Note that if you change the
'// partitioning, you'll also need to calculate new texture coordinates for any faces
'// that have switched charts.
'//
'// The partition result adjacency output parameter is meant to be passed to the
'// UVAtlasPack function, this adjacency cuts edges that are between adjacent
'// charts, and also can include cuts inside of a chart in order to make it
'// equivalent to a disc. For example:
'//
'// _______
'// | ___ |
'// | |_| |
'// |_____|
'//
'// In order to make this equivalent to a disc, we would need to add a cut, and it
'// Would end up looking like:
'// _______
'// | ___ |
'// | |_|_|
'// |_____|
'//
'// The resulting partition adjacency parameter cannot be NULL, because it is
'// required for the packing step.

DECLARE FUNCTION D3DXUVAtlasPartition IMPORT $D3DX_DLLNAME ALIAS "D3DXUVAtlasPartition" (_
   BYVAL Mesh AS ID3DXMesh _                            ' __in  LPD3DXMESH Mesh
 , BYVAL uMaxChartNumber AS DWORD _                     ' __in  UINT uMaxChartNumber
 , BYVAL fMaxStretch AS SINGLE _                        ' __in  FLOAT fMaxStretch
 , BYVAL dwTextureIndex AS DWORD _                      ' __in  DWORD dwTextureIndex
 , BYREF pdwAdjacency AS DWORD _                        ' __in  CONST DWORD *pdwAdjacency
 , BYREF pdwFalseEdgeAdjacency AS DWORD _               ' __in  CONST DWORD *pdwFalseEdgeAdjacency
 , BYREF pfIMTArray AS SINGLE _                         ' __in  CONST FLOAT *pfIMTArray
 , BYVAL pStatusCallback AS DWORD _                     ' __in  LPD3DXUVATLASCB pStatusCallback
 , BYVAL fCallbackFrequency AS SINGLE _                 ' __in  FLOAT fCallbackFrequency
 , BYVAL pUserContext AS DWORD _                        ' __in  LPVOID pUserContext
 , BYVAL dwOptions AS DWORD _                           ' __in  DWORD dwOptions
 , BYREF ppMeshOut AS ID3DXMesh _                       ' __out LPD3DXMESH *ppMeshOut
 , BYREF ppFacePartitioning AS ID3DXBuffer _            ' __out LPD3DXBUFFER *ppFacePartitioning
 , BYREF ppVertexRemapArray AS ID3DXBuffer _            ' __out LPD3DXBUFFER *ppVertexRemapArray
 , BYREF ppPartitionResultAdjacency AS ID3DXBuffer _    ' __out LPD3DXBUFFER *ppPartitionResultAdjacency
 , BYREF pfMaxStretchOut AS SINGLE _                    ' __out FLOAT *pfMaxStretchOut
 , BYREF puNumChartsOut AS DWORD _                      ' __out UINT *puNumChartsOut
 ) AS LONG                                              ' HRESULT


'// This takes the face partitioning result from Partition and packs it into an
'// atlas of the given size. pdwPartitionResultAdjacency should be derived from
'// the adjacency returned from the partition step. This value cannot be NULL
'// because Pack needs to know where charts were cut in the partition step in
'// order to find the edges of each chart.
'// The options parameter is currently reserved.

DECLARE FUNCTION D3DXUVAtlasPack IMPORT $D3DX_DLLNAME ALIAS "D3DXUVAtlasPack" (_
   BYVAL Mesh AS ID3DXMesh _                            ' __in LPD3DXMESH Mesh
 , BYVAL uWidth AS DWORD _                              ' __in UINT uWidth
 , BYVAL uHeight AS DWORD _                             ' __in UINT uHeight
 , BYVAL fGutter AS SINGLE _                            ' __in FLOAT fGutter
 , BYVAL dwTextureIndex AS DWORD _                      ' __in DWORD dwTextureIndex
 , BYREF pdwPartitionResultAdjacency AS DWORD _         ' __in CONST DWORD *pdwPartitionResultAdjacency
 , BYVAL pStatusCallback AS DWORD _                     ' __in LPD3DXUVATLASCB pStatusCallback
 , BYVAL fCallbackFrequency AS SINGLE _                 ' __in FLOAT fCallbackFrequency
 , BYVAL pUserContext AS DWORD _                        ' __in LPVOID pUserContext
 , BYVAL dwOptions AS DWORD _                           ' __in DWORD dwOptions
 , BYVAL pFacePartitioning AS ID3DXBuffer _             ' __in LPD3DXBUFFER pFacePartitioning
 ) AS LONG                                              ' HRESULT

'//============================================================================
'//
'// IMT Calculation apis
'//
'// These functions all compute the Integrated Metric Tensor for use in the
'// UVAtlas API. They all calculate the IMT with respect to the canonical
'// triangle, where the coordinate system is set up so that the u axis goes
'// from vertex 0 to 1 and the v axis is N x u. So, for example, the second
'// vertex's canonical uv coordinates are (d,0) where d is the distance between
'// vertices 0 and 1. This way the IMT does not depend on the parameterization
'// of the mesh, and if the signal over the surface doesn't change, then
'// the IMT doesn't need to be recalculated.
'//============================================================================

'// This callback is used by D3DXComputeIMTFromSignal.
'//
'// uv               - The texture coordinate for the vertex.
'// uPrimitiveID     - Face ID of the triangle on which to compute the signal.
'// uSignalDimension - The number of floats to store in pfSignalOut.
'// pUserData        - The pUserData pointer passed in to ComputeIMTFromSignal.
'// pfSignalOut      - A pointer to where to store the signal data.

'typedef HRESULT (WINAPI* LPD3DXIMTSIGNALCALLBACK)
'    (CONST D3DXVECTOR2 *uv,
'     UINT uPrimitiveID,
'     UINT uSignalDimension,
'     VOID *pUserData,
'     FLOAT *pfSignalOut);

'// This function is used to calculate the IMT from per vertex data. It sets
'// up a linear system over the triangle, solves for the jacobian J, then
'// constructs the IMT from that (J^TJ).
'// This function allows you to calculate the IMT based off of any value in a
'// mesh (color, normal, etc) by specifying the correct stride of the array.
'// The IMT computed will cause areas of the mesh that have similar values to
'// take up less space in the texture.
'//
'// pMesh            - The mesh to calculate the IMT for.
'// pVertexSignal    - A float array of size uSignalStride * v, where v is the
'//                    number of vertices in the mesh.
'// uSignalDimension - How many floats per vertex to use in calculating the IMT.
'// uSignalStride    - The number of bytes per vertex in the array. This must be
'//                    a multiple of sizeof(float)
'// ppIMTData        - Where to store the buffer holding the IMT data

DECLARE FUNCTION D3DXComputeIMTFromPerVertexSignal IMPORT $D3DX_DLLNAME ALIAS "D3DXComputeIMTFromPerVertexSignal" (_
   BYVAL Mesh AS ID3DXMesh _                            ' __in  LPD3DXMESH Mesh
 , BYREF pfVertexSignal AS SINGLE _                     ' __in  CONST FLOAT *pfVertexSignal // uSignalDimension floats per vertex
 , BYVAL uSignalDimension AS DWORD _                    ' __in  UINT uSignalDimension
 , BYVAL uSignalStride AS DWORD _                       ' __in  UINT uSignalStride          // stride of signal in bytes
 , BYVAL dwOptions AS DWORD _                           ' __in  DWORD dwOptions             // reserved for future use
 , BYVAL pStatusCallback AS DWORD _                     ' __in  LPD3DXUVATLASCB pStatusCallback
 , BYVAL pUserContext AS DWORD _                        ' __in  LPVOID pUserContext
 , BYREF ppIMTData AS ID3DXBuffer _                     ' __out LPD3DXBUFFER *ppIMTData
 ) AS LONG                                              ' HRESULT

'// This function is used to calculate the IMT from data that varies over the
'// surface of the mesh (generally at a higher frequency than vertex data).
'// This function requires the mesh to already be parameterized (so it already
'// has texture coordinates). It allows the user to define a signal arbitrarily
'// over the surface of the mesh.
'//
'// pMesh            - The mesh to calculate the IMT for.
'// dwTextureIndex   - This describes which set of texture coordinates in the
'//                    mesh to use.
'// uSignalDimension - How many components there are in the signal.
'// fMaxUVDistance   - The subdivision will continue until the distance between
'//                    all vertices is at most fMaxUVDistance.
'// dwOptions        - reserved for future use
'// pSignalCallback  - The callback to use to get the signal.
'// pUserData        - A pointer that will be passed in to the callback.
'// ppIMTData        - Where to store the buffer holding the IMT data

DECLARE FUNCTION D3DXComputeIMTFromSignal IMPORT $D3DX_DLLNAME ALIAS "D3DXComputeIMTFromSignal" (_
   BYVAL Mesh AS ID3DXMesh _                            ' __in  LPD3DXMESH Mesh
 , BYVAL dwTextureIndex AS DWORD _                      ' __in  DWORD dwTextureIndex
 , BYVAL uSignalDimension AS DWORD _                    ' __in  UINT uSignalDimension
 , BYVAL fMaxUVDistance AS SINGLE _                     ' __in  FLOAT fMaxUVDistance
 , BYVAL dwOptions AS DWORD _                           ' __in  DWORD dwOptions // reserved for future use
 , BYVAL pSignalCallback AS DWORD _                     ' __in  LPD3DXIMTSIGNALCALLBACK pSignalCallback
 , BYVAL pUserData AS DWORD _                           ' __in  VOID *pUserData
 , BYVAL pStatusCallback AS DWORD _                     ' __in  LPD3DXUVATLASCB pStatusCallback
 , BYVAL pUserContext AS DWORD _                        ' __in  LPVOID pUserContext
 , BYREF ppIMTData AS ID3DXBuffer _                     ' __out LPD3DXBUFFER *ppIMTData
 ) AS LONG                                              ' HRESULT

'// This function is used to calculate the IMT from texture data. Given a texture
'// that maps over the surface of the mesh, the algorithm computes the IMT for
'// each face. This will cause large areas that are very similar to take up less
'// room when parameterized with UVAtlas. The texture is assumed to be
'// interpolated over the mesh bilinearly.
'//
'// pMesh            - The mesh to calculate the IMT for.
'// pTexture         - The texture to load data from.
'// dwTextureIndex   - This describes which set of texture coordinates in the
'//                    mesh to use.
'// dwOptions        - Combination of one or more D3DXIMT flags.
'// ppIMTData        - Where to store the buffer holding the IMT data

DECLARE FUNCTION D3DXComputeIMTFromTexture IMPORT $D3DX_DLLNAME ALIAS "D3DXComputeIMTFromTexture" (_
   BYVAL Mesh AS ID3DXMesh _                            ' __in  LPD3DXMESH Mesh
 , BYVAL pTexture AS IDirect3DTexture9 _                ' __in  LPDIRECT3DTEXTURE9 pTexture
 , BYVAL dwTextureIndex AS DWORD _                      ' __in  DWORD dwTextureIndex
 , BYVAL dwOptions AS DWORD _                           ' __in  DWORD dwOptions
 , BYVAL pStatusCallback AS DWORD _                     ' __in  LPD3DXUVATLASCB pStatusCallback
 , BYVAL pUserContext AS DWORD _                        ' __in  LPVOID pUserContext
 , BYREF ppIMTData AS ID3DXBuffer _                     ' __out LPD3DXBUFFER *ppIMTData
 ) AS LONG                                              ' HRESULT

'// This function is very similar to ComputeIMTFromTexture, but it uses a
'// float array to pass in the data, and it can calculate higher dimensional
'// values than 4.
'//
'// pMesh            - The mesh to calculate the IMT for.
'// dwTextureIndex   - This describes which set of texture coordinates in the
'//                    mesh to use.
'// pfFloatArray     - a pointer to a float array of size
'//                    uWidth*uHeight*uComponents
'// uWidth           - The width of the texture
'// uHeight          - The height of the texture
'// uSignalDimension - The number of floats per texel in the signal
'// uComponents      - The number of floats in each texel
'// dwOptions        - Combination of one or more D3DXIMT flags
'// ppIMTData        - Where to store the buffer holding the IMT data

DECLARE FUNCTION D3DXComputeIMTFromPerTexelSignal IMPORT $D3DX_DLLNAME ALIAS "D3DXComputeIMTFromPerTexelSignal" (_
   BYVAL Mesh AS ID3DXMesh _                            ' __in  LPD3DXMESH Mesh
 , BYVAL dwTextureIndex AS DWORD _                      ' __in  DWORD dwTextureIndex
 , BYREF pfTexelSignal AS SINGLE _                      ' __in  FLOAT *pfTexelSignal
 , BYVAL uWidth AS DWORD _                              ' __in  UINT uWidth
 , BYVAL uHeight AS DWORD _                             ' __in  UINT uHeight
 , BYVAL uSignalDimension AS DWORD _                    ' __in  UINT uSignalDimension
 , BYVAL uComponents AS DWORD _                         ' __in  UINT uComponents
 , BYVAL dwOptions AS DWORD _                           ' __in  DWORD dwOptions
 , BYVAL pStatusCallback AS DWORD _                     ' __in  LPD3DXUVATLASCB pStatusCallback
 , BYVAL pUserContext AS DWORD _                        ' __in  LPVOID pUserContext
 , BYREF ppIMTData AS ID3DXBuffer _                     ' __out LPD3DXBUFFER *ppIMTData
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXConvertMeshSubsetToSingleStrip IMPORT $D3DX_DLLNAME ALIAS "D3DXConvertMeshSubsetToSingleStrip" (_
   BYVAL MeshIn AS ID3DXBaseMesh _                      ' __in  LPD3DXBASEMESH MeshIn
 , BYVAL AttribId AS DWORD _                            ' __in  DWORD AttribId
 , BYVAL IBOptions AS DWORD _                           ' __in  DWORD IBOptions
 , BYREF ppIndexBuffer AS IDirect3DIndexBuffer9 _       ' __out LPDIRECT3DINDEXBUFFER9 *ppIndexBuffer
 , BYREF pNumIndices AS DWORD _                         ' __out DWORD *pNumIndices
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXConvertMeshSubsetToStrips IMPORT $D3DX_DLLNAME ALIAS "D3DXConvertMeshSubsetToStrips" (_
   BYVAL MeshIn AS ID3DXBaseMesh _                      ' __in  LPD3DXBASEMESH MeshIn
 , BYVAL AttribId AS DWORD _                            ' __in  DWORD AttribId
 , BYVAL IBOptions AS DWORD _                           ' __in  DWORD IBOptions
 , BYREF ppIndexBuffer AS IDirect3DIndexBuffer9 _       ' __out LPDIRECT3DINDEXBUFFER9 *ppIndexBuffer
 , BYREF pNumIndices AS DWORD _                         ' __out DWORD *pNumIndices
 , BYREF ppStripLengths AS ID3DXBuffer _                ' __out LPD3DXBUFFER *ppStripLengths
 , BYREF pNumStrips AS DWORD _                          ' __out DWORD *pNumStrips
 ) AS LONG                                              ' HRESULT

'//============================================================================
'//
'//  D3DXOptimizeFaces:
'//  --------------------
'//  Generate a face remapping for a triangle list that more effectively utilizes
'//    vertex caches.  This optimization is identical to the one provided
'//    by ID3DXMesh::Optimize with the hardware independent option enabled.
'//
'//  Parameters:
'//   pbIndices
'//      Triangle list indices to use for generating a vertex ordering
'//   NumFaces
'//      Number of faces in the triangle list
'//   NumVertices
'//      Number of vertices referenced by the triangle list
'//   b32BitIndices
'//      TRUE if indices are 32 bit, FALSE if indices are 16 bit
'//   pFaceRemap
'//      Destination buffer to store face ordering
'//      The number stored for a given element is where in the new ordering
'//      the face will have come from.  See ID3DXMesh::Optimize for more info.
'//
'//============================================================================

DECLARE FUNCTION D3DXOptimizeFaces IMPORT $D3DX_DLLNAME ALIAS "D3DXOptimizeFaces" (_
   BYVAL pbIndices AS DWORD _                           ' __in LPCVOID pbIndices
 , BYVAL cFaces AS DWORD _                              ' __in UINT cFaces
 , BYVAL cVertices AS DWORD _                           ' __in UINT cVertices
 , BYVAL b32BitIndices AS LONG _                        ' __in BOOL b32BitIndices
 , BYVAL pFaceRemap AS DWORD _                          ' __in_out DWORD* pFaceRemap
 ) AS LONG                                              ' HRESULT

'//============================================================================
'//
'//  D3DXOptimizeVertices:
'//  --------------------
'//  Generate a vertex remapping to optimize for in order use of vertices for
'//    a given set of indices.  This is commonly used after applying the face
'//    remap generated by D3DXOptimizeFaces
'//
'//  Parameters:
'//   pbIndices
'//      Triangle list indices to use for generating a vertex ordering
'//   NumFaces
'//      Number of faces in the triangle list
'//   NumVertices
'//      Number of vertices referenced by the triangle list
'//   b32BitIndices
'//      TRUE if indices are 32 bit, FALSE if indices are 16 bit
'//   pVertexRemap
'//      Destination buffer to store vertex ordering
'//      The number stored for a given element is where in the new ordering
'//        the vertex will have come from.  See ID3DXMesh::Optimize for more info.
'//
'//============================================================================

DECLARE FUNCTION D3DXOptimizeVertices IMPORT $D3DX_DLLNAME ALIAS "D3DXOptimizeVertices" (_
   BYVAL pbIndices AS DWORD _                           ' __in LPCVOID pbIndices
 , BYVAL cFaces AS DWORD _                              ' __in UINT cFaces
 , BYVAL cVertices AS DWORD _                           ' __in UINT cVertices
 , BYVAL b32BitIndices AS LONG _                        ' __in BOOL b32BitIndices
 , BYVAL pVertexRemap AS DWORD _                        ' __in_out DWORD* pVertexRemap
 ) AS LONG                                              ' HRESULT


'//===========================================================================
'//
'//  Data structures for Spherical Harmonic Precomputation
'//
'//
'//============================================================================

'enum D3DXSHCOMPRESSQUALITYTYPE
%D3DXSHCQUAL_FASTLOWQUALITY    = 1???
%D3DXSHCQUAL_SLOWHIGHQUALITY   = 2???
%D3DXSHCQUAL_FORCE_DWORD       = &H7FFFFFFF???

'enum _D3DXSHGPUSIMOPT
%D3DXSHGPUSIMOPT_SHADOWRES256  = 1???
%D3DXSHGPUSIMOPT_SHADOWRES512  = 0???
%D3DXSHGPUSIMOPT_SHADOWRES1024 = 2???
%D3DXSHGPUSIMOPT_SHADOWRES2048 = 3???

%D3DXSHGPUSIMOPT_HIGHQUALITY   = 4???

%D3DXSHGPUSIMOPT_FORCE_DWORD   = &H7FFFFFFF???

'// for all properties that are colors the luminance is computed
'// if the simulator is run with a single channel using the following
'// formula:  R * 0.2125 + G * 0.7154 + B * 0.0721

' // Size = 60 bytes
TYPE D3DXSHMATERIAL DWORD
   Diffuse                   AS D3DCOLORVALUE   ' // Diffuse albedo of the surface.  (Ignored if object is a Mirror)
   bMirror                   AS LONG            ' BOOL // Must be set to FALSE.  bMirror == TRUE not currently supported
   bSubSurf                  AS LONG            ' BOOL // true if the object does subsurface scattering - can't do this and be a mirror
                                                ' // subsurface scattering parameters
   RelativeIndexOfRefraction AS SINGLE          ' FLOAT
   Absorption                AS D3DCOLORVALUE
   ReducedScattering         AS D3DCOLORVALUE
END TYPE

'// allocated in D3DXSHPRTCompSplitMeshSC
'// vertices are duplicated into multiple super clusters but
'// only have a valid status in one super cluster (fill in the rest)

' // Size = 12 bytes
TYPE D3DXSHPRTSPLITMESHVERTDATA DWORD
   uVertRemap   AS DWORD   ' UINT  // vertex in original mesh this corresponds to
   uSubCluster  AS DWORD   ' UINT  // cluster index relative to super cluster
   ucVertStatus AS BYTE    ' UCHAR // 1 if vertex has valid data, 0 if it is "fill"
END TYPE

'// used in D3DXSHPRTCompSplitMeshSC
'// information for each super cluster that maps into face/vert arrays

' // Size = 24 bytes
TYPE D3DXSHPRTSPLITMESHCLUSTERDATA DWORD
   uVertStart     AS DWORD   ' UINT // initial index into remapped vertex array
   uVertLength    AS DWORD   ' UINT // number of vertices in this super cluster
   uFaceStart     AS DWORD   ' UINT // initial index into face array
   uFaceLength    AS DWORD   ' UINT // number of faces in this super cluster
   uClusterStart  AS DWORD   ' UINT // initial index into cluster array
   uClusterLength AS DWORD   ' UINT // number of clusters in this super cluster
END TYPE

'// call back function for simulator
'// return S_OK to keep running the simulator - anything else represents
'// failure and the simulator will abort.

'typedef HRESULT (WINAPI *LPD3DXSHPRTSIMCB)(float fPercentDone,  LPVOID lpUserContext);

' Prototype for the callback function LPD3DXSHPRTSIMCB
' You need to declare a function like this one in your program and pass its address
' (with CODEPTR(LPD3DXSHPRTSIMCB) to the function that requires it.
'FUNCTION LPD3DXSHPRTSIMCB (BYVAL fPercentDone AS SINGLE, BYVAL lpUserContext AS DWORD) AS DWORD
'END FUNCTION

'// interfaces for PRT buffers/simulator

$IID_ID3DXPRTBuffer           = GUID$("{F1827E47-00A8-49cd-908C-9D11955F8728}")
$IID_ID3DXPRTCompBuffer       = GUID$("{A758D465-FE8D-45ad-9CF0-D01E56266A07}")
$IID_ID3DXTextureGutterHelper = GUID$("{06F57E0A-BD95-43f1-A3DA-791CF6CA297B}")
$IID_ID3DXPRTEngine           = GUID$("{C3F4ADBF-E6D2-4b7b-BFE8-9E7208746ADF}")

'// Buffer interface - contains "NumSamples" samples
'// each sample in memory is stored as NumCoeffs scalars per channel (1 or 3)
'// Same interface is used for both Vertex and Pixel PRT buffers

'//////////////////////////////////////////////////////////////////////////////
'// ID3DXPRTBuffer ////////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

INTERFACE ID3DXPRTBuffer $IID_ID3DXPRTBuffer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNumSamples ( _                             ' VTable offset = 12
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetNumCoeffs ( _                              ' VTable offset = 16
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetNumChannels ( _                            ' VTable offset = 20
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD IsTexture ( _                                 ' VTable offset = 24
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD GetWidth ( _                                  ' VTable offset = 28
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetHeight ( _                                 ' VTable offset = 32
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD Resize ( _                                     ' VTable offset = 36
     BYVAL NewSize AS DWORD _                            ' __in UINT NewSize
   ) AS LONG                                             ' HRESULT
   ' =====================================================================================
   METHOD LockBuffer ( _                                ' VTable offset = 40
     BYVAL Start AS DWORD _                             ' __in UINT Start
   , BYVAL NumSamples AS DWORD _                        ' __in UINT NumSamples
   , BYREF ppData AS SINGLE _                           ' __out FLOAT **ppData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockBuffer ( _                              ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ScaleBuffer ( _                               ' VTable offset = 48
     BYVAL Scale AS SINGLE _                            ' __in FLOAT Scale
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddBuffer ( _                                 ' VTable offset = 52
     BYVAL pBuffer AS ID3DXPRTBuffer _                  ' __in LPD3DXPRTBUFFER pBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AttachGH ( _                                  ' VTable offset = 56
     BYVAL pGH AS ID3DXTextureGutterHelper _            ' __in LPD3DXTEXTUREGUTTERHELPER pGH
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseGH ( _                                 ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EvalGH ( _                                    ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExtractTexture ( _                            ' VTable offset = 68
     BYVAL Channel AS DWORD _                           ' __in UINT Channel
   , BYVAL StartCoefficient AS DWORD _                  ' __in UINT StartCoefficient
   , BYVAL NumCoefficients AS DWORD _                   ' __in UINT NumCoefficients
   , BYVAL pTexture AS IDirect3DTexture9 _              ' __in LPDIRECT3DTEXTURE9 pTexture
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExtractToMesh ( _                             ' VTable offset = 72
     BYVAL NumCoefficients AS DWORD _                   ' __in UINT NumCoefficients
   , BYVAL Usage AS DWORD _                             ' __in D3DDECLUSAGE Usage
   , BYVAL UsageIndexStart AS DWORD _                   ' __in UINT UsageIndexStart
   , BYVAL pScene AS ID3DXMesh _                        ' __in LPD3DXMESH pScene
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' // compressed buffers stored a compressed version of a PRTBuffer

'//////////////////////////////////////////////////////////////////////////////
'// ID3DXPRTCompBuffer ////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

INTERFACE ID3DXPRTCompBuffer $IID_ID3DXPRTCompBuffer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNumSamples ( _                             ' VTable offset = 12
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetNumCoeffs ( _                              ' VTable offset = 16
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetNumChannels ( _                            ' VTable offset = 20
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD IsTexture ( _                                 ' VTable offset = 24
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD GetWidth ( _                                  ' VTable offset = 28
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetHeight ( _                                 ' VTable offset = 32
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetNumClusters ( _                            ' VTable offset = 36
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetNumPCA ( _                                 ' VTable offset = 40
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD NormalizeData ( _                             ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExtractBasis ( _                              ' VTable offset = 48
     BYVAL Cluster AS DWORD _                           ' __in UINT Cluster
   , BYREF pClusterBasis AS SINGLE _                    ' __in_out FLOAT *pClusterBasis
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExtractClusterIDs ( _                         ' VTable offset = 52
     BYREF pClusterIDs AS DWORD _                       ' __in_out UINT *pClusterIDs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExtractPCA ( _                                ' VTable offset = 56
     BYVAL StartPCA AS DWORD _                          ' __in UINT StartPCA
   , BYVAL NumExtract AS DWORD _                        ' __in UINT NumExtract
   , BYREF NumExtract AS SINGLE _                       ' __in_out FLOAT *pPCACoefficients
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExtractTexture ( _                            ' VTable offset = 60
     BYVAL StartPCA AS DWORD _                          ' __in UINT StartPCA
   , BYVAL NumpPCA AS DWORD _                           ' __in UINT NumpPCA
   , BYVAL pTexture AS IDirect3DTexture9 _              ' __in LPDIRECT3DTEXTURE9 pTexture
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExtractToMesh ( _                             ' VTable offset = 64
     BYVAL NumPCA AS DWORD _                            ' __in UINT NumPCA
   , BYVAL Usage AS DWORD _                             ' __in D3DDECLUSAGE Usage
   , BYVAL UsageIndexStart AS DWORD _                   ' __in UINT UsageIndexStart
   , BYVAL pScene AS ID3DXMesh _                        ' __in LPD3DXMESH pScene
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'// ID3DXTextureGutterHelper will build and manage
'// "gutter" regions in a texture - this will allow for
'// bi-linear interpolation to not have artifacts when rendering
'// It generates a map (in texture space) where each texel
'// is in one of 3 states:
'//   0  Invalid - not used at all
'//   1  Inside triangle
'//   2  Gutter texel
'//   4  represents a gutter texel that will be computed during PRT
'// For each Inside/Gutter texel it stores the face it
'// belongs to and barycentric coordinates for the 1st two
'// vertices of that face.  Gutter vertices are assigned to
'// the closest edge in texture space.
'//
'// When used with PRT this requires a unique parameterization
'// of the model - every texel must correspond to a single point
'// on the surface of the model and vice versa

'//////////////////////////////////////////////////////////////////////////////
'// ID3DXPRTCompBuffer ////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

INTERFACE ID3DXTextureGutterHelper $IID_ID3DXTextureGutterHelper

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetWidth ( _                                  ' VTable offset = 12
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetHeight ( _                                 ' VTable offset = 16
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD ApplyGuttersFloat ( _                         ' VTable offset = 20
     BYREF pDataIn AS SINGLE _                          ' __in FLOAT *pDataIn
   , BYVAL NumCoeffs AS DWORD _                         ' __in UINT NumCoeffs
   , BYVAL Width AS DWORD _                             ' __in UINT Width
   , BYVAL Height AS DWORD _                            ' __in UINT Height
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ApplyGuttersTex ( _                           ' VTable offset = 24
     BYVAL pTexture AS IDirect3DTexture9 _              ' __in LPDIRECT3DTEXTURE9 pTexture
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ApplyGuttersPRT ( _                           ' VTable offset = 28
     BYVAL pBuffer AS ID3DXPRTBuffer _                  ' __in LPD3DXPRTBUFFER pBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFaceMap ( _                                ' VTable offset = 32
     BYREF pFaceData AS DWORD _                         ' __in UINT *pFaceData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBaryMap ( _                                ' VTable offset = 36
     BYREF pBaryData AS D3DXVECTOR2 _                   ' __in_out D3DXVECTOR2 *pBaryData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTexelMap ( _                               ' VTable offset = 40
     BYREF pTexelData AS D3DXVECTOR2 _                  ' __out D3DXVECTOR2 *pTexelData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGutterMap ( _                              ' VTable offset = 44
     BYREF pGutterData AS BYTE _                        ' __in_out BYTE *pGutterData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFaceMap ( _                                ' VTable offset = 48
     BYREF pFaceData AS DWORD _                         ' __in UINT *pFaceData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBaryMap ( _                                ' VTable offset = 52
     BYREF pBaryData AS D3DXVECTOR2 _                   ' __in D3DXVECTOR2 *pBaryData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTexelMap ( _                               ' VTable offset = 56
     BYREF pTexelData AS D3DXVECTOR2 _                  ' __in D3DXVECTOR2 *pTexelData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGutterMap ( _                              ' VTable offset = 50
     BYREF pGutterData AS BYTE _                        ' __in BYTE *pGutterData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'// ID3DXPRTEngine is used to compute a PRT simulation
'// Use the following steps to compute PRT for SH
'// (1) create an interface (which includes a scene)
'// (2) call SetSamplingInfo
'// (3) [optional] Set MeshMaterials/albedo's (required if doing bounces)
'// (4) call ComputeDirectLightingSH
'// (5) [optional] call ComputeBounce
'// repeat step 5 for as many bounces as wanted.
'// if you want to model subsurface scattering you
'// need to call ComputeSS after direct lighting and
'// each bounce.
'// If you want to bake the albedo into the PRT signal, you
'// must call MutliplyAlbedo, otherwise the user has to multiply
'// the albedo themselves.  Not multiplying the albedo allows you
'// to model albedo variation at a finer scale then illumination, and
'// can result in better compression results.
'// Luminance values are computed from RGB values using the following
'// formula:  R * 0.2125 + G * 0.7154 + B * 0.0721

'//////////////////////////////////////////////////////////////////////////////
'// ID3DXPRTEngine ////////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

INTERFACE ID3DXPRTEngine $IID_ID3DXPRTEngine

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetMeshMaterials ( _                          ' VTable offset = 12
     BYREF ppMaterials AS D3DXSHMATERIAL _              ' __in CONST D3DXSHMATERIAL **ppMaterials
   , BYVAL NumMeshes AS DWORD _                         ' __in UINT NumMeshes
   , BYVAL NumChannels AS DWORD _                       ' __in UINT NumChannels
   , BYVAL bSetAlbedo AS LONG _                         ' __in BOOL bSetAlbedo
   , BYVAL fLengthScale AS SINGLE _                     ' __in FLOAT fLengthScale
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPerVertexAlbedo ( _                        ' VTable offset = 16
     BYVAL pDataIn AS DWORD _                           ' __in CONST VOID *pDataIn
   , BYVAL NumChannels AS DWORD _                       ' __in UINT NumChannels
   , BYVAL Stride AS DWORD _                            ' __in UINT Stride
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPerTexelAlbedo ( _                         ' VTable offset = 20
     BYVAL pAlbedoTexture AS IDirect3DTexture9 _        ' __in LPDIRECT3DTEXTURE9 pAlbedoTexture
   , BYVAL NumChannels AS DWORD _                       ' __in UINT NumChannels
   , BYVAL pGH AS ID3DXTextureGutterHelper _            ' __in LPD3DXTEXTUREGUTTERHELPER pGH
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVertexAlbedo ( _                           ' VTable offset = 24
     BYREF pVertColors AS D3DXCOLOR _                   ' __in_out D3DXCOLOR *pVertColors
   , BYVAL NumVerts AS DWORD _                          ' __in UINT NumVerts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPerTexelNormal ( _                         ' VTable offset = 28
     BYVAL pNormalTexture AS IDirect3DTexture9 _        ' __in LPDIRECT3DTEXTURE9 pNormalTexture
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExtractPerVertexAlbedo ( _                    ' VTable offset = 32
     BYVAL pMesh AS ID3DXMesh _                         ' __in LPD3DXMESH pMesh
   , BYVAL Usage AS DWORD _                             ' __in D3DDECLUSAGE Usage
   , BYVAL NumChannels AS DWORD _                       ' __in UINT NumChannels
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResampleBuffer ( _                            ' VTable offset = 36
     BYVAL pBufferIn AS ID3DXPRTBuffer _                ' __in LPD3DXPRTBUFFER pBufferIn
   , BYVAL pBufferOut AS ID3DXPRTBuffer _               ' __in_out LPD3DXPRTBUFFER pBufferOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAdaptedMesh ( _                            ' VTable offset = 40
     BYVAL pD3DDevice AS IDirect3DDevice9 _             ' __in LPDIRECT3DDEVICE9 pD3DDevice
   , BYREF pFaceRemap AS DWORD _                        ' __in_out UINT *pFaceRemap
   , BYREF pVertRemap AS DWORD _                        ' __in_out UINT *pVertRemap
   , BYREF pfVertWeights AS SINGLE _                    ' __in_out FLOAT *pfVertWeights
   , BYREF ppMesh AS ID3DXMesh _                        ' __out LPD3DXMESH *ppMesh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumVerts ( _                               ' VTable offset = 44
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD GetNumFaces ( _                               ' VTable offset = 48
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD RobustMeshRefine ( _                          ' VTable offset = 52
     BYVAL MinEdgeLength AS SINGLE _                    ' __in FLOAT MinEdgeLength
   , BYVAL MaxSubdiv AS DWORD _                         ' __in UINT MaxSubdiv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSamplingInfo ( _                           ' VTable offset = 56
     BYVAL NumRays AS DWORD _                           ' __in UINT NumRays
   , BYVAL UseSphere AS LONG _                          ' __in BOOL UseSphere
   , BYVAL UseCosine AS LONG _                          ' __in BOOL UseCosine
   , BYVAL Adaptive AS LONG _                           ' __in BOOL Adaptive
   , BYVAL AdaptiveThresh AS SINGLE _                   ' __in FLOAT AdaptiveThresh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputeDirectLightingSH ( _                   ' VTable offset = 60
     BYVAL SHOrder AS DWORD _                           ' __in UINT SHOrder
   , BYVAL pDataOut AS ID3DXPRTBuffer _                 ' __in_out LPD3DXPRTBUFFER pDataOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputeDirectLightingSHAdaptive ( _           ' VTable offset = 64
     BYVAL SHOrder AS DWORD _                           ' __in UINT SHOrder
   , BYVAL AdaptiveThresh AS SINGLE _                   ' __in FLOAT AdaptiveThresh
   , BYVAL MinEdgeLength AS SINGLE _                    ' __in FLOAT MinEdgeLength
   , BYVAL MaxSubdiv AS DWORD _                         ' __in UINT MaxSubdiv
   , BYVAL pDataOut AS ID3DXPRTBuffer _                 ' __in_out LPD3DXPRTBUFFER pDataOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputeDirectLightingSHGPU ( _                ' VTable offset = 68
     BYVAL pD3DDevice AS IDirect3DDevice9 _             ' __in LPDIRECT3DDEVICE9 pD3DDevice
   , BYVAL Flags AS DWORD _                             ' __in UINT Flags
   , BYVAL SHOrder AS DWORD _                           ' __in UINT SHOrder
   , BYVAL ZBias AS SINGLE _                            ' __in FLOAT ZBias
   , BYVAL ZAngleBias AS SINGLE _                       ' __in FLOAT ZAngleBias
   , BYVAL pDataOut AS ID3DXPRTBuffer _                 ' __in_out LPD3DXPRTBUFFER pDataOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputeSS ( _                                 ' VTable offset = 72
     BYVAL pDataIn AS ID3DXPRTBuffer _                  ' __in LPD3DXPRTBUFFER pDataIn
   , BYVAL pDataOut AS ID3DXPRTBuffer _                 ' __in_out LPD3DXPRTBUFFER pDataOut
   , BYVAL pDataTotal AS ID3DXPRTBuffer _               ' __in_out LPD3DXPRTBUFFER pDataTotal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputeBounce ( _                             ' VTable offset = 76
     BYVAL pDataIn AS ID3DXPRTBuffer _                  ' __in LPD3DXPRTBUFFER pDataIn
   , BYVAL pDataOut AS ID3DXPRTBuffer _                 ' __in LPD3DXPRTBUFFER pDataOut
   , BYVAL pDataTotal AS ID3DXPRTBuffer _               ' __in LPD3DXPRTBUFFER pDataTotal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputeBounceAdaptive ( _                     ' VTable offset = 80
     BYVAL pDataIn AS ID3DXPRTBuffer _                  ' __in LPD3DXPRTBUFFER pDataIn
   , BYVAL AdaptiveThresh AS SINGLE _                   ' __in FLOAT AdaptiveThresh
   , BYVAL MinEdgeLength AS SINGLE _                    ' __in FLOAT MinEdgeLength
   , BYVAL MaxSubdiv AS DWORD _                         ' __in UINT MaxSubdiv
   , BYVAL pDataOut AS ID3DXPRTBuffer _                 ' __in_out LPD3DXPRTBUFFER pDataOut
   , BYVAL pDataTotal AS ID3DXPRTBuffer _               ' __in_out LPD3DXPRTBUFFER pDataTotal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputeVolumeSamplesDirectSH ( _              ' VTable offset = 84
     BYVAL SHOrderIn AS DWORD _                         ' __in UINT SHOrderIn
   , BYVAL SHOrderOut AS DWORD _                        ' __in UINT SHOrderOut
   , BYVAL NumVolSamples AS DWORD _                     ' __in UINT NumVolSamples
   , BYREF pSampleLocs AS D3DXVECTOR3 _                 ' __in CONST D3DXVECTOR3 *pSampleLocs
   , BYVAL pDataOut AS ID3DXPRTBuffer _                 ' __in_out LPD3DXPRTBUFFER pDataOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputeVolumeSamples ( _                      ' VTable offset = 88
     BYVAL pSurfDataIn AS ID3DXPRTBuffer _              ' __in LPD3DXPRTBUFFER pSurfDataIn
   , BYVAL SHOrder AS DWORD _                           ' __in UINT SHOrder
   , BYVAL NumVolSamples AS DWORD _                     ' __in UINT NumVolSamples
   , BYREF pSampleLocs AS D3DXVECTOR3 _                 ' __in CONST D3DXVECTOR3 *pSampleLocs
   , BYVAL pDataOut AS ID3DXPRTBuffer _                 ' __in_out LPD3DXPRTBUFFER pDataOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeSSData ( _                                ' VTable offset = 92
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeBounceData ( _                            ' VTable offset = 96
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComputeConvCoeffs ( _                         ' VTable offset = 100
     BYVAL pDataIn AS ID3DXPRTBuffer _                  ' __in LPD3DXPRTBUFFER pDataIn
   , BYVAL SHOrder AS DWORD _                           ' __in UINT SHOrder
   , BYREF pNormOut AS D3DXVECTOR3 _                    ' __in D3DXVECTOR3 *pNormOut
   , BYVAL pDataOut AS ID3DXPRTBuffer _                 ' __in LPD3DXPRTBUFFER pDataOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ScaleMeshChunk ( _                            ' VTable offset = 104
     BYVAL uMeshChunk AS DWORD _                        ' __in UINT uMeshChunk
   , BYVAL fScale AS SINGLE _                           ' __in FLOAT fScale
   , BYVAL pDataOut AS ID3DXPRTBuffer _                 ' __in_out LPD3DXPRTBUFFER pDataOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MultiplyAlbedo ( _                            ' VTable offset = 108
     BYVAL pDataOut AS ID3DXPRTBuffer _                 ' __in LPD3DXPRTBUFFER pDataOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCallBack ( _                               ' VTable offset = 112
     BYVAL pCB AS DWORD _                               ' __in LPD3DXSHPRTSIMCB pCB
   , BYVAL Frequency AS SINGLE _                        ' __in FLOAT Frequency
   , BYVAL lpUserContext AS DWORD _                     ' __in LPVOID lpUserContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'// API functions for creating interfaces

'//============================================================================
'//
'//  D3DXCreatePRTBuffer:
'//  --------------------
'//  Generates a PRT Buffer that can be compressed or filled by a simulator
'//  This function should be used to create per-vertex or volume buffers.
'//  When buffers are created all values are initialized to zero.
'//
'//  Parameters:
'//    NumSamples
'//      Number of sample locations represented
'//    NumCoeffs
'//      Number of coefficients per sample location (order^2 for SH)
'//    NumChannels
'//      Number of color channels to represent (1 or 3)
'//    ppBuffer
'//      Buffer that will be allocated
'//
'//============================================================================

DECLARE FUNCTION D3DXCreatePRTBuffer IMPORT $D3DX_DLLNAME ALIAS "D3DXCreatePRTBuffer" (_
   BYVAL NumSamples AS DWORD _                          ' __in UINT NumSamples
 , BYVAL NumCoeffs AS DWORD _                           ' __in UINT NumCoeffs
 , BYVAL NumChannels AS DWORD _                         ' __in UINT NumChannels
 , BYREF ppBuffer AS ID3DXPRTBuffer _                   ' __in_out LPD3DXPRTBUFFER* ppBuffer
 ) AS LONG                                              ' HRESULT

'//============================================================================
'//
'//  D3DXCreatePRTBufferTex:
'//  --------------------
'//  Generates a PRT Buffer that can be compressed or filled by a simulator
'//  This function should be used to create per-pixel buffers.
'//  When buffers are created all values are initialized to zero.
'//
'//  Parameters:
'//    Width
'//      Width of texture
'//    Height
'//      Height of texture
'//    NumCoeffs
'//      Number of coefficients per sample location (order^2 for SH)
'//    NumChannels
'//      Number of color channels to represent (1 or 3)
'//    ppBuffer
'//      Buffer that will be allocated
'//
'//============================================================================

DECLARE FUNCTION D3DXCreatePRTBufferTex IMPORT $D3DX_DLLNAME ALIAS "D3DXCreatePRTBufferTex" (_
   BYVAL Width AS DWORD _                               ' __in UINT Width
 , BYVAL Height AS DWORD _                              ' __in UINT Height
 , BYVAL NumCoeffs AS DWORD _                           ' __in UINT NumCoeffs
 , BYVAL NumChannels AS DWORD _                         ' __in UINT NumChannels
 , BYREF ppBuffer AS ID3DXPRTBuffer _                   ' __in_out LPD3DXPRTBUFFER* ppBuffer
 ) AS LONG                                              ' HRESULT

'//============================================================================
'//
'//  D3DXLoadPRTBufferFromFile:
'//  --------------------
'//  Loads a PRT buffer that has been saved to disk.
'//
'//  Parameters:
'//    pFilename
'//      Name of the file to load
'//    ppBuffer
'//      Buffer that will be allocated
'//
'//============================================================================

DECLARE FUNCTION D3DXLoadPRTBufferFromFileA IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadPRTBufferFromFileA" (_
   BYREF pFilename AS ASCIIZ _                          ' __in LPCSTR pFilename
 , BYREF ppBuffer AS ID3DXPRTBuffer _                   ' __in_out LPD3DXPRTBUFFER* ppBuffer
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXLoadPRTBufferFromFileW IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadPRTBufferFromFileW" (_
   BYREF pFilename AS WSTRINGZ _                        ' __in LPCWSTR pFilename
 , BYREF ppBuffer AS ID3DXPRTBuffer _                   ' __in_out LPD3DXPRTBUFFER* ppBuffer
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXLoadPRTBufferFromFile = D3DXLoadPRTBufferFromFileW
#ELSE
   MACRO D3DXLoadPRTBufferFromFile = D3DXLoadPRTBufferFromFileA
#ENDIF

'//============================================================================
'//
'//  D3DXSavePRTBufferToFile:
'//  --------------------
'//  Saves a PRTBuffer to disk.
'//
'//  Parameters:
'//    pFilename
'//      Name of the file to save
'//    pBuffer
'//      Buffer that will be saved
'//
'//============================================================================

DECLARE FUNCTION D3DXSavePRTBufferToFileA IMPORT $D3DX_DLLNAME ALIAS "D3DXSavePRTBufferToFileA" (_
   BYREF pFilename AS ASCIIZ _                          ' __in LPCSTR pFilename
 , BYVAL pBuffer AS ID3DXPRTBuffer _                    ' __in LPD3DXPRTBUFFER pBuffer
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXSavePRTBufferToFileW IMPORT $D3DX_DLLNAME ALIAS "D3DXSavePRTBufferToFileW" (_
   BYREF pFilename AS WSTRINGZ _                        ' __in LPCWSTR pFilename
 , BYVAL pBuffer AS ID3DXPRTBuffer _                    ' __in LPD3DXPRTBUFFER pBuffer
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXSavePRTBufferToFile = D3DXSavePRTBufferToFileW
#ELSE
   MACRO D3DXSavePRTBufferToFile = D3DXSavePRTBufferToFileA
#ENDIF

'//============================================================================
'//
'//  D3DXLoadPRTCompBufferFromFile:
'//  --------------------
'//  Loads a PRTComp buffer that has been saved to disk.
'//
'//  Parameters:
'//    pFilename
'//      Name of the file to load
'//    ppBuffer
'//      Buffer that will be allocated
'//
'//============================================================================

DECLARE FUNCTION D3DXLoadPRTCompBufferFromFileA IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadPRTCompBufferFromFileA" (_
   BYREF pFilename AS ASCIIZ _                          ' __in LPCSTR pFilename
 , BYREF ppBuffer AS ID3DXPRTCompBuffer _               ' __in_out LPD3DXPRTCOMPBUFFER* ppBuffer
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXLoadPRTCompBufferFromFileW IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadPRTCompBufferFromFileW" (_
   BYREF pFilename AS WSTRINGZ _                        ' __in LPCWSTR pFilename
 , BYREF ppBuffer AS ID3DXPRTCompBuffer _               ' __in_out LPD3DXPRTCOMPBUFFER* ppBuffer
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXLoadPRTCompBufferFromFile = D3DXLoadPRTCompBufferFromFileW
#ELSE
   MACRO D3DXLoadPRTCompBufferFromFile = D3DXLoadPRTCompBufferFromFileA
#ENDIF

'//============================================================================
'//
'//  D3DXSavePRTCompBufferToFile:
'//  --------------------
'//  Saves a PRTCompBuffer to disk.
'//
'//  Parameters:
'//    pFilename
'//      Name of the file to save
'//    pBuffer
'//      Buffer that will be saved
'//
'//============================================================================

DECLARE FUNCTION D3DXSavePRTCompBufferToFileA IMPORT $D3DX_DLLNAME ALIAS "D3DXSavePRTCompBufferToFileA" (_
   BYREF pFilename AS ASCIIZ _                          ' __in LPCSTR pFilename
 , BYVAL pBuffer AS ID3DXPRTCompBuffer _                ' __in LPD3DXPRTCOMPBUFFER pBuffer
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXSavePRTCompBufferToFileW IMPORT $D3DX_DLLNAME ALIAS "D3DXSavePRTCompBufferToFileW" (_
   BYREF pFilename AS WSTRINGZ _                        ' __in LPCWSTR pFilename
 , BYVAL pBuffer AS ID3DXPRTCompBuffer _                ' __in LPD3DXPRTCOMPBUFFER pBuffer
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXSavePRTCompBufferToFile = D3DXSavePRTCompBufferToFileW
#ELSE
   MACRO D3DXSavePRTCompBufferToFile = D3DXSavePRTCompBufferToFileA
#ENDIF

'//============================================================================
'//
'//  D3DXCreatePRTCompBuffer:
'//  --------------------
'//  Compresses a PRT buffer (vertex or texel)
'//
'//  Parameters:
'//    D3DXSHCOMPRESSQUALITYTYPE
'//      Quality of compression - low is faster (computes PCA per voronoi cluster)
'//      high is slower but better quality (clusters based on distance to affine subspace)
'//    NumClusters
'//      Number of clusters to compute
'//    NumPCA
'//      Number of basis vectors to compute
'//    pCB
'//      Optional Callback function
'//    lpUserContext
'//      Optional user context
'//    pBufferIn
'//      Buffer that will be compressed
'//    ppBufferOut
'//      Compressed buffer that will be created
'//
'//============================================================================

DECLARE FUNCTION D3DXCreatePRTCompBuffer IMPORT $D3DX_DLLNAME ALIAS "D3DXCreatePRTCompBuffer" (_
   BYVAL Quality AS DWORD _                          ' __in D3DXSHCOMPRESSQUALITYTYPE Quality
 , BYVAL NumClusters AS DWORD _                      ' __in UINT NumClusters
 , BYVAL NumPCA AS DWORD _                           ' __in UINT NumPCA
 , BYVAL pCB AS DWORD _                              ' __in LPD3DXSHPRTSIMCB pCB
 , BYVAL lpUserContext AS DWORD _                    ' __in LPVOID lpUserContext
 , BYVAL pBufferIn AS ID3DXPRTBuffer _               ' __in LPD3DXPRTBUFFER  pBufferIn
 , BYREF ppBufferOut AS ID3DXPRTCompBuffer _         ' __in_out LPD3DXPRTCOMPBUFFER *ppBufferOut
 ) AS LONG                                           ' HRESULT


'//============================================================================
'//
'//  D3DXCreateTextureGutterHelper:
'//  --------------------
'//  Generates a "GutterHelper" for a given set of meshes and texture
'//  resolution
'//
'//  Parameters:
'//    Width
'//      Width of texture
'//    Height
'//      Height of texture
'//    pMesh
'//      Mesh that represents the scene
'//    GutterSize
'//      Number of texels to over rasterize in texture space
'//      this should be at least 1.0
'//    ppBuffer
'//      GutterHelper that will be created
'//
'//============================================================================

DECLARE FUNCTION D3DXCreateTextureGutterHelper IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateTextureGutterHelper" (_
   BYVAL Width AS DWORD _                               ' __in UINT Width
 , BYVAL Height AS DWORD _                              ' __in UINT Height
 , BYVAL pMesh AS ID3DXMesh _                           ' __in LPD3DXMESH pMesh
 , BYVAL GutterSize AS SINGLE _                         ' __in FLOAT GutterSize
 , BYREF ppBuffer AS ID3DXTextureGutterHelper _         ' __in_out LPD3DXTEXTUREGUTTERHELPER* ppBuffer
 ) AS LONG                                              ' HRESULT

'//============================================================================
'//
'//  D3DXCreatePRTEngine:
'//  --------------------
'//  Computes a PRTEngine which can efficiently generate PRT simulations
'//  of a scene
'//
'//  Parameters:
'//    pMesh
'//      Mesh that represents the scene - must have an AttributeTable
'//      where vertices are in a unique attribute.
'//    pAdjacency
'//      Optional adjacency information
'//    ExtractUVs
'//      Set this to true if textures are going to be used for albedos
'//      or to store PRT vectors
'//    pBlockerMesh
'//      Optional mesh that just blocks the scene
'//    ppEngine
'//      PRTEngine that will be created
'//
'//============================================================================

DECLARE FUNCTION D3DXCreatePRTEngine IMPORT $D3DX_DLLNAME ALIAS "D3DXCreatePRTEngine" ( _
   BYVAL pMesh AS ID3DXMesh _                           ' __in LPD3DXMESH pMesh
 , BYREF pAdjacency AS DWORD _                          ' __in DWORD *pAdjacency
 , BYVAL ExtractUVs AS LONG _                           ' __in BOOL ExtractUVs
 , BYVAL pBlockerMesh AS ID3DXMesh _                    ' __in LPD3DXMESH pBlockerMesh
 , BYREF ppEngine AS ID3DXPRTEngine _                   ' __in_out LPD3DXPRTENGINE* ppEngine
 ) AS LONG                                              ' HRESULT

'//============================================================================
'//
'//  D3DXConcatenateMeshes:
'//  --------------------
'//  Concatenates a group of meshes into one common mesh.  This can optionaly transform
'//  each sub mesh or its texture coordinates.  If no DECL is given it will
'//  generate a union of all of the DECL's of the sub meshes, promoting channels
'//  and types if neccesary.  It will create an AttributeTable if possible, one can
'//  call OptimizeMesh with attribute sort and compacting enabled to ensure this.
'//
'//  Parameters:
'//    ppMeshes
'//      Array of pointers to meshes that can store PRT vectors
'//    NumMeshes
'//      Number of meshes
'//    Options
'//      Passed through to D3DXCreateMesh
'//    pGeomXForms
'//      [optional] Each sub mesh is transformed by the corresponding
'//      matrix if this array is supplied
'//    pTextureXForms
'//      [optional] UV coordinates for each sub mesh are transformed
'//      by corresponding matrix if supplied
'//    pDecl
'//      [optional] Only information in this DECL is used when merging
'//      data
'//    pD3DDevice
'//      D3D device that is used to create the new mesh
'//    ppMeshOut
'//      Mesh that will be created
'//
'//============================================================================

DECLARE FUNCTION D3DXConcatenateMeshes IMPORT $D3DX_DLLNAME ALIAS "D3DXConcatenateMeshes" (_
   BYREF ppMeshes AS ID3DXMesh _                        ' __in  LPD3DXMESH *ppMeshes
 , BYVAL NumMeshes AS DWORD _                           ' __in  UINT NumMeshes
 , BYVAL Options AS DWORD _                             ' __in  DWORD Options
 , BYREF pGeomXForms AS D3DXMATRIX _                    ' __in  CONST D3DXMATRIX *pGeomXForms
 , BYREF pTextureXForms AS D3DXMATRIX _                 ' __in  CONST D3DXMATRIX *pTextureXForms
 , BYREF pDecl AS D3DVERTEXELEMENT9 _                   ' __in  CONST D3DVERTEXELEMENT9 *pDecl
 , BYVAL pD3DDevice AS IDirect3DDevice9 _               ' __in  LPDIRECT3DDEVICE9 pD3DDevice
 , BYREF ppMeshOut AS ID3DXMesh _                       ' __out LPD3DXMESH *ppMeshOut
 ) AS LONG                                              ' HRESULT

'//============================================================================
'//
'//  D3DXSHPRTCompSuperCluster:
'//  --------------------------
'//  Used with compressed results of D3DXSHPRTSimulation.
'//  Generates "super clusters" - groups of clusters that can be drawn in
'//  the same draw call.  A greedy algorithm that minimizes overdraw is used
'//  to group the clusters.
'//
'//  Parameters:
'//   pClusterIDs
'//      NumVerts cluster ID's (extracted from a compressed buffer)
'//   pScene
'//      Mesh that represents composite scene passed to the simulator
'//   MaxNumClusters
'//      Maximum number of clusters allocated per super cluster
'//   NumClusters
'//      Number of clusters computed in the simulator
'//   pSuperClusterIDs
'//      Array of length NumClusters, contains index of super cluster
'//      that corresponding cluster was assigned to
'//   pNumSuperClusters
'//      Returns the number of super clusters allocated
'//
'//============================================================================

DECLARE FUNCTION D3DXSHPRTCompSuperCluster IMPORT $D3DX_DLLNAME ALIAS "D3DXSHPRTCompSuperCluster" (_
   BYREF pClusterIDs AS DWORD _                         ' __in UINT *pClusterIDs
 , BYVAL pScene AS ID3DXMesh _                          ' __in LPD3DXMESH pScene
 , BYVAL MaxNumClusters AS DWORD _                      ' __in UINT MaxNumClusters
 , BYVAL NumClusters AS DWORD _                         ' __in UINT NumClusters
 , BYREF pSuperClusterIDs AS DWORD _                    ' __in_out UINT *pSuperClusterIDs
 , BYREF pNumSuperClusters AS DWORD _                   ' __in_out UINT *pNumSuperClusters
 ) AS LONG                                              ' HRESULT

'//============================================================================
'//
'//  D3DXSHPRTCompSplitMeshSC:
'//  -------------------------
'//  Used with compressed results of the vertex version of the PRT simulator.
'//  After D3DXSHRTCompSuperCluster has been called this function can be used
'//  to split the mesh into a group of faces/vertices per super cluster.
'//  Each super cluster contains all of the faces that contain any vertex
'//  classified in one of its clusters.  All of the vertices connected to this
'//  set of faces are also included with the returned array ppVertStatus
'//  indicating whether or not the vertex belongs to the supercluster.
'//
'//  Parameters:
'//   pClusterIDs
'//      NumVerts cluster ID's (extracted from a compressed buffer)
'//   NumVertices
'//      Number of vertices in original mesh
'//   NumClusters
'//      Number of clusters (input parameter to compression)
'//   pSuperClusterIDs
'//      Array of size NumClusters that will contain super cluster ID's (from
'//      D3DXSHCompSuerCluster)
'//   NumSuperClusters
'//      Number of superclusters allocated in D3DXSHCompSuerCluster
'//   pInputIB
'//      Raw index buffer for mesh - format depends on bInputIBIs32Bit
'//   InputIBIs32Bit
'//      Indicates whether the input index buffer is 32-bit (otherwise 16-bit
'//      is assumed)
'//   NumFaces
'//      Number of faces in the original mesh (pInputIB is 3 times this length)
'//   ppIBData
'//      LPD3DXBUFFER holds raw index buffer that will contain the resulting split faces.
'//      Format determined by bIBIs32Bit.  Allocated by function
'//   pIBDataLength
'//      Length of ppIBData, assigned in function
'//   OutputIBIs32Bit
'//      Indicates whether the output index buffer is to be 32-bit (otherwise
'//      16-bit is assumed)
'//   ppFaceRemap
'//      LPD3DXBUFFER mapping of each face in ppIBData to original faces.  Length is
'//      *pIBDataLength/3.  Optional paramter, allocated in function
'//   ppVertData
'//      LPD3DXBUFFER contains new vertex data structure.  Size of pVertDataLength
'//   pVertDataLength
'//      Number of new vertices in split mesh.  Assigned in function
'//   pSCClusterList
'//      Array of length NumClusters which pSCData indexes into (Cluster* fields)
'//      for each SC, contains clusters sorted by super cluster
'//   pSCData
'//      Structure per super cluster - contains indices into ppIBData,
'//      pSCClusterList and ppVertData
'//
'//============================================================================

DECLARE FUNCTION D3DXSHPRTCompSplitMeshSC IMPORT $D3DX_DLLNAME ALIAS "D3DXSHPRTCompSplitMeshSC" (_
   BYREF pClusterIDs AS DWORD _                         ' __in UINT *pClusterIDs
 , BYVAL NumVertices AS DWORD _                         ' __in UINT NumVertices
 , BYVAL NumClusters AS DWORD _                         ' __in UINT NumClusters
 , BYREF pSuperClusterIDs AS DWORD _                    ' __in_out UINT *pSuperClusterIDs
 , BYVAL NumSuperClusters AS DWORD _                    ' __in UINT NumSuperClusters
 , BYVAL pInputIB AS DWORD _                            ' __in LPVOID pInputIB
 , BYVAL InputIBIs32Bit AS LONG _                       ' __in BOOL InputIBIs32Bit
 , BYVAL NumFaces AS DWORD _                            ' __in UINT NumFaces
 , BYREF ppIBData AS ID3DXBuffer _                      ' __in_out LPD3DXBUFFER *ppIBData
 , BYREF pIBDataLength AS DWORD _                       ' __in_out UINT *pIBDataLength
 , BYVAL OutputIBIs32Bit AS LONG _                      ' __in BOOL OutputIBIs32Bit
 , BYREF ppFaceRemap AS ID3DXBuffer _                   ' __out LPD3DXBUFFER *ppFaceRemap
 , BYREF ppVertData AS ID3DXBuffer _                    ' __out LPD3DXBUFFER *ppVertData
 , BYREF pVertDataLength AS DWORD _                     ' __in_out UINT *pVertDataLength
 , BYREF pSCClusterList AS DWORD _                      ' __in_out UINT *pSCClusterList
 , BYREF pSCData AS D3DXSHPRTSPLITMESHCLUSTERDATA _     ' __in_out D3DXSHPRTSPLITMESHCLUSTERDATA *pSCData
 ) AS LONG                                              ' HRESULT


'//////////////////////////////////////////////////////////////////////////////
'//
'//  Definitions of .X file templates used by mesh load/save functions
'//    that are not RM standard
'//
'//////////////////////////////////////////////////////////////////////////////

$DXFILEOBJ_XSkinMeshHeader          = GUID$("{3CF169CE-FF7C-44ab-93C0-F78F62D172E2}")
$DXFILEOBJ_VertexDuplicationIndices = GUID$("{B8D65549-D7C9-4995-89CF-53A9A8B031E3}")
$DXFILEOBJ_FaceAdjacency            = GUID$("{A64C844A-E282-4756-8B80-250CDE04398C}")
$DXFILEOBJ_SkinWeights              = GUID$("{6F0D123B-BAD2-4167-A0D0-80224F25FABB}")
$DXFILEOBJ_Patch                    = GUID$("{A3EB5D44-FC22-429d-9AFB-3221CB9719A6}")
$DXFILEOBJ_PatchMesh                = GUID$("{D02C95CC-EDBA-4305-9B5D-1820D7704BBF}")
$DXFILEOBJ_PatchMesh9               = GUID$("{B9EC94E1-B9A6-4251-BA18-94893F02C0EA}")
$DXFILEOBJ_PMInfo                   = GUID$("{B6C3E656-EC8B-4b92-9B62-681659522947}")
$DXFILEOBJ_PMAttributeRange         = GUID$("{917E0427-C61E-4a14-9C64-AFE65F9E9844}")
$DXFILEOBJ_PMVSplitRecord           = GUID$("{574CCC14-F0B3-4333-822D-93E8A8A08E4C}")
$DXFILEOBJ_FVFData                  = GUID$("{B6E70A0E-8EF9-4e83-94AD-ECC8B0C04897}")
$DXFILEOBJ_VertexElement            = GUID$("{F752461C-1E23-48f6-B9F8-8350850F336F}")
$DXFILEOBJ_DeclData                 = GUID$("{BF22E553-292C-4781-9FEA-62BD554BDD93}")
$DXFILEOBJ_EffectFloats             = GUID$("{F1CFE2B3-0DE3-4e28-AFA1-155A750A282D}")
$DXFILEOBJ_EffectString             = GUID$("{D55B097E-BDB6-4c52-B03D-6051C89D0E42}")
$DXFILEOBJ_EffectDWord              = GUID$("{622C0ED0-956E-4da9-908A-2AF94F3CE716}")
$DXFILEOBJ_EffectParamFloats        = GUID$("{3014B9A0-62F5-478c-9B86-E4AC9F4E418B}")
$DXFILEOBJ_EffectParamString        = GUID$("{1DBC4C88-94C1-46ee-9076-2C28818C9481}")
$DXFILEOBJ_EffectParamDWord         = GUID$("{E13963BC-AE51-4c5d-B00F-CFA3A9D97CE5}")
$DXFILEOBJ_EffectInstance           = GUID$("{E331F7E4-0559-4cc2-8E99-1CEC1657928F}")
$DXFILEOBJ_AnimTicksPerSecond       = GUID$("{9E415A43-7BA6-4a73-8743-B73D47E88476}")
$DXFILEOBJ_CompressedAnimationSet   = GUID$("{7F9B00B3-F125-4890-876E-1CFFBF697C4D}")

' // Size = 16 bytes
TYPE XFILECOMPRESSEDANIMATIONSET BYTE
   CompressedBlockSize AS DWORD    ' DWORD
   TicksPerSec         AS SINGLE   ' FLOAT
   PlaybackType        AS DWORD    ' DWORD
   BufferLength        AS DWORD    ' DWORD
END TYPE

'#define XSKINEXP_TEMPLATES \
'        "xof 0303txt 0032\
'        template XSkinMeshHeader \
'        { \
'            <3CF169CE-FF7C-44ab-93C0-F78F62D172E2> \
'            WORD nMaxSkinWeightsPerVertex; \
'            WORD nMaxSkinWeightsPerFace; \
'            WORD nBones; \
'        } \
'        template VertexDuplicationIndices \
'        { \
'            <B8D65549-D7C9-4995-89CF-53A9A8B031E3> \
'            DWORD nIndices; \
'            DWORD nOriginalVertices; \
'            array DWORD indices[nIndices]; \
'        } \
'        template FaceAdjacency \
'        { \
'            <A64C844A-E282-4756-8B80-250CDE04398C> \
'            DWORD nIndices; \
'            array DWORD indices[nIndices]; \
'        } \
'        template SkinWeights \
'        { \
'            <6F0D123B-BAD2-4167-A0D0-80224F25FABB> \
'            STRING transformNodeName; \
'            DWORD nWeights; \
'            array DWORD vertexIndices[nWeights]; \
'            array float weights[nWeights]; \
'            Matrix4x4 matrixOffset; \
'        } \
'        template Patch \
'        { \
'            <A3EB5D44-FC22-429D-9AFB-3221CB9719A6> \
'            DWORD nControlIndices; \
'            array DWORD controlIndices[nControlIndices]; \
'        } \
'        template PatchMesh \
'        { \
'            <D02C95CC-EDBA-4305-9B5D-1820D7704BBF> \
'            DWORD nVertices; \
'            array Vector vertices[nVertices]; \
'            DWORD nPatches; \
'            array Patch patches[nPatches]; \
'            [ ... ] \
'        } \
'        template PatchMesh9 \
'        { \
'            <B9EC94E1-B9A6-4251-BA18-94893F02C0EA> \
'            DWORD Type; \
'            DWORD Degree; \
'            DWORD Basis; \
'            DWORD nVertices; \
'            array Vector vertices[nVertices]; \
'            DWORD nPatches; \
'            array Patch patches[nPatches]; \
'            [ ... ] \
'        } " \
'        "template EffectFloats \
'        { \
'            <F1CFE2B3-0DE3-4e28-AFA1-155A750A282D> \
'            DWORD nFloats; \
'            array float Floats[nFloats]; \
'        } \
'        template EffectString \
'        { \
'            <D55B097E-BDB6-4c52-B03D-6051C89D0E42> \
'            STRING Value; \
'        } \
'        template EffectDWord \
'        { \
'            <622C0ED0-956E-4da9-908A-2AF94F3CE716> \
'            DWORD Value; \
'        } " \
'        "template EffectParamFloats \
'        { \
'            <3014B9A0-62F5-478c-9B86-E4AC9F4E418B> \
'            STRING ParamName; \
'            DWORD nFloats; \
'            array float Floats[nFloats]; \
'        } " \
'        "template EffectParamString \
'        { \
'            <1DBC4C88-94C1-46ee-9076-2C28818C9481> \
'            STRING ParamName; \
'            STRING Value; \
'        } \
'        template EffectParamDWord \
'        { \
'            <E13963BC-AE51-4c5d-B00F-CFA3A9D97CE5> \
'            STRING ParamName; \
'            DWORD Value; \
'        } \
'        template EffectInstance \
'        { \
'            <E331F7E4-0559-4cc2-8E99-1CEC1657928F> \
'            STRING EffectFilename; \
'            [ ... ] \
'        } " \
'        "template AnimTicksPerSecond \
'        { \
'            <9E415A43-7BA6-4a73-8743-B73D47E88476> \
'            DWORD AnimTicksPerSecond; \
'        } \
'        template CompressedAnimationSet \
'        { \
'            <7F9B00B3-F125-4890-876E-1C42BF697C4D> \
'            DWORD CompressedBlockSize; \
'            FLOAT TicksPerSec; \
'            DWORD PlaybackType; \
'            DWORD BufferLength; \
'            array DWORD CompressedData[BufferLength]; \
'        } "

'#define XEXTENSIONS_TEMPLATES \
'        "xof 0303txt 0032\
'        template FVFData \
'        { \
'            <B6E70A0E-8EF9-4e83-94AD-ECC8B0C04897> \
'            DWORD dwFVF; \
'            DWORD nDWords; \
'            array DWORD data[nDWords]; \
'        } \
'        template VertexElement \
'        { \
'            <F752461C-1E23-48f6-B9F8-8350850F336F> \
'            DWORD Type; \
'            DWORD Method; \
'            DWORD Usage; \
'            DWORD UsageIndex; \
'        } \
'        template DeclData \
'        { \
'            <BF22E553-292C-4781-9FEA-62BD554BDD93> \
'            DWORD nElements; \
'            array VertexElement Elements[nElements]; \
'            DWORD nDWords; \
'            array DWORD data[nDWords]; \
'        } \
'        template PMAttributeRange \
'        { \
'            <917E0427-C61E-4a14-9C64-AFE65F9E9844> \
'            DWORD iFaceOffset; \
'            DWORD nFacesMin; \
'            DWORD nFacesMax; \
'            DWORD iVertexOffset; \
'            DWORD nVerticesMin; \
'            DWORD nVerticesMax; \
'        } \
'        template PMVSplitRecord \
'        { \
'            <574CCC14-F0B3-4333-822D-93E8A8A08E4C> \
'            DWORD iFaceCLW; \
'            DWORD iVlrOffset; \
'            DWORD iCode; \
'        } \
'        template PMInfo \
'        { \
'            <B6C3E656-EC8B-4b92-9B62-681659522947> \
'            DWORD nAttributes; \
'            array PMAttributeRange attributeRanges[nAttributes]; \
'            DWORD nMaxValence; \
'            DWORD nMinLogicalVertices; \
'            DWORD nMaxLogicalVertices; \
'            DWORD nVSplits; \
'            array PMVSplitRecord splitRecords[nVSplits]; \
'            DWORD nAttributeMispredicts; \
'            array DWORD attributeMispredicts[nAttributeMispredicts]; \
'        } "
