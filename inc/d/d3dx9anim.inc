' ########################################################################################
' Microsoft Windows
' File: d3dx9anim.inc
' Contents: D3DX mesh types and functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3DX9ANIM_INC = 1

#INCLUDE ONCE "d3dx9.inc"

$IID_ID3DXAnimationSet           = GUID$("{698CFB3F-9289-4d95-9A57-33A94B5A65F9}")
$IID_ID3DXKeyframedAnimationSet  = GUID$("{FA4E8E3A-9786-407d-8B4C-5995893764AF}")
$IID_ID3DXCompressedAnimationSet = GUID$("{6CC2480D-3808-4739-9F88-DE49FACD8D4C}")
$IID_ID3DXAnimationController    = GUID$("{AC8948EC-F86D-43e2-96DE-31FC35F96D9E}")

'//----------------------------------------------------------------------------
'// D3DXMESHDATATYPE:
'// -----------------
'// This enum defines the type of mesh data present in a MeshData structure.
'//----------------------------------------------------------------------------
%D3DXMESHTYPE_MESH      = &H001???            ' // Normal ID3DXMesh data
%D3DXMESHTYPE_PMESH     = &H002???            ' // Progressive Mesh - ID3DXPMesh
%D3DXMESHTYPE_PATCHMESH = &H003???            ' // Patch Mesh - ID3DXPatchMesh

%D3DXMESHTYPE_FORCE_DWORD = &H7FFFFFFF???     ' /* force 32-bit size enum */

'//----------------------------------------------------------------------------
'// D3DXMESHDATA:
'// -------------
'// This struct encapsulates a the mesh data that can be present in a mesh
'// container.  The supported mesh types are pMesh, pPMesh, pPatchMesh.
'// The valid way to access this is determined by the Type enum.
'//----------------------------------------------------------------------------

' // Size = 4 bytes
UNION D3DXMESHDATA_UNION DWORD
   pMesh      AS DWORD   ' LPD3DXMESH
   pPMesh     AS DWORD   ' LPD3DXPMESH
   pPatchMesh AS DWORD   ' LPD3DXPATCHMESH
END UNION

' // Size = 8 bytes
TYPE D3DXMESHDATA DWORD
   Type AS DWORD         ' D3DXMESHDATATYPE
   D3DXMESHDATA_UNION
END TYPE

'//----------------------------------------------------------------------------
'// D3DXMESHCONTAINER:
'// ------------------
'// This struct encapsulates a mesh object in a transformation frame
'// hierarchy. The app can derive from this structure to add other app specific
'// data to this.
'//----------------------------------------------------------------------------
' // Size = 32 bytes
TYPE D3DXMESHCONTAINER DWORD
   Name               AS ASCIIZ PTR              ' LPSTR
   MeshData           AS DWORD                   ' D3DXMESHDATA
   pMaterials         AS DWORD                   ' LPD3DXMATERIAL
   pEffects           AS DWORD                   ' LPD3DXEFFECTINSTANCE
   NumMaterials       AS DWORD                   ' DWORD
   pAdjacency         AS DWORD PTR               ' DWORD *
   pSkinInfo          AS DWORD                   ' LPD3DXSKININFO
   pNextMeshContainer AS D3DXMESHCONTAINER PTR   ' struct _D3DXMESHCONTAINER *
END TYPE

'//----------------------------------------------------------------------------
'// D3DXFRAME:
'// ----------
'// This struct is the encapsulates a transform frame in a transformation frame
'// hierarchy. The app can derive from this structure to add other app specific
'// data to this
'//----------------------------------------------------------------------------
' // Size = 20 bytes
TYPE D3DXFRAME DWORD
   Name                 AS ASCIIZ PTR      ' LPSTR
   TransformationMatrix AS DWORD           ' D3DXMATRIX
   pMeshContainer       AS DWORD           ' LPD3DXMESHCONTAINER
   pFrameSibling        AS D3DXFRAME PTR   ' struct _D3DXFRAME *
   pFrameFirstChild     AS D3DXFRAME PTR   ' struct _D3DXFRAME *
END TYPE

'//----------------------------------------------------------------------------
'// ID3DXAllocateHierarchy:
'// -----------------------
'// This interface is implemented by the application to allocate/free frame and
'// mesh container objects. Methods on this are called during loading and
'// destroying frame hierarchies
'//----------------------------------------------------------------------------

'DECLARE_INTERFACE(ID3DXAllocateHierarchy)
'{
'    // ID3DXAllocateHierarchy

'	//------------------------------------------------------------------------
'	// CreateFrame:
'	// ------------
'	// Requests allocation of a frame object.
'	//
'	// Parameters:
'	//  Name
'	//		Name of the frame to be created
'	//	ppNewFrame
'	//		Returns the created frame object
'	//
'	//------------------------------------------------------------------------
'    STDMETHOD(CreateFrame)(THIS_ LPCSTR Name,
'                            LPD3DXFRAME *ppNewFrame) PURE;

'	//------------------------------------------------------------------------
'	// CreateMeshContainer:
'	// --------------------
'	// Requests allocation of a mesh container object.
'	//
'	// Parameters:
'	//  Name
'	//		Name of the mesh
'	//	pMesh
'	//		Pointer to the mesh object if basic polygon data found
'	//	pPMesh
'	//		Pointer to the progressive mesh object if progressive mesh data found
'	//	pPatchMesh
'	//		Pointer to the patch mesh object if patch data found
'	//	pMaterials
'	//		Array of materials used in the mesh
'	//	pEffectInstances
'	//		Array of effect instances used in the mesh
'	//	NumMaterials
'	//		Num elements in the pMaterials array
'	//	pAdjacency
'	//		Adjacency array for the mesh
'	//	pSkinInfo
'	//		Pointer to the skininfo object if the mesh is skinned
'	//	pBoneNames
'	//		Array of names, one for each bone in the skinned mesh.
'	//		The numberof bones can be found from the pSkinMesh object
'	//	pBoneOffsetMatrices
'	//		Array of matrices, one for each bone in the skinned mesh.
'	//
'	//------------------------------------------------------------------------
'    STDMETHOD(CreateMeshContainer)(THIS_
'        LPCSTR Name,
'        CONST D3DXMESHDATA *pMeshData,
'        CONST D3DXMATERIAL *pMaterials,
'        CONST D3DXEFFECTINSTANCE *pEffectInstances,
'        DWORD NumMaterials,
'        CONST DWORD *pAdjacency,
'        LPD3DXSKININFO pSkinInfo,
'        LPD3DXMESHCONTAINER *ppNewMeshContainer) PURE;

'	//------------------------------------------------------------------------
'	// DestroyFrame:
'	// -------------
'	// Requests de-allocation of a frame object.
'	//
'	// Parameters:
'	//  pFrameToFree
'	//		Pointer to the frame to be de-allocated
'	//
'	//------------------------------------------------------------------------
'    STDMETHOD(DestroyFrame)(THIS_ LPD3DXFRAME pFrameToFree) PURE;

'	//------------------------------------------------------------------------
'	// DestroyMeshContainer:
'	// ---------------------
'	// Requests de-allocation of a mesh container object.
'	//
'	// Parameters:
'	//  pMeshContainerToFree
'	//		Pointer to the mesh container object to be de-allocated
'	//
'	//------------------------------------------------------------------------
'    STDMETHOD(DestroyMeshContainer)(THIS_ LPD3DXMESHCONTAINER pMeshContainerToFree) PURE;
'};

'//----------------------------------------------------------------------------
'// ID3DXLoadUserData:
'// ------------------
'// This interface is implemented by the application to load user data in a .X file
'// When user data is found, these callbacks will be used to allow the application
'// to load the data.
'//----------------------------------------------------------------------------

'DECLARE_INTERFACE(ID3DXLoadUserData)
'{
'    STDMETHOD(LoadTopLevelData)(LPD3DXFILEDATA pXofChildData) PURE;

'    STDMETHOD(LoadFrameChildData)(LPD3DXFRAME pFrame,
'                            LPD3DXFILEDATA pXofChildData) PURE;

'    STDMETHOD(LoadMeshChildData)(LPD3DXMESHCONTAINER pMeshContainer,
'                            LPD3DXFILEDATA pXofChildData) PURE;
'};

'//----------------------------------------------------------------------------
'// ID3DXSaveUserData:
'// ------------------
'// This interface is implemented by the application to save user data in a .X file
'// The callbacks are called for all data saved.  The user can then add any
'// child data objects to the object provided to the callback.
'//----------------------------------------------------------------------------

'DECLARE_INTERFACE(ID3DXSaveUserData)
'{
'    STDMETHOD(AddFrameChildData)(CONST D3DXFRAME *pFrame,
'                            LPD3DXFILESAVEOBJECT pXofSave,
'                            LPD3DXFILESAVEDATA pXofFrameData) PURE;

'    STDMETHOD(AddMeshChildData)(CONST D3DXMESHCONTAINER *pMeshContainer,
'                            LPD3DXFILESAVEOBJECT pXofSave,
'                            LPD3DXFILESAVEDATA pXofMeshData) PURE;

'    // NOTE: this is called once per Save.  All top level objects should be added using the
'    //    provided interface.  One call adds objects before the frame hierarchy, the other after
'    STDMETHOD(AddTopLevelDataObjectsPre)(LPD3DXFILESAVEOBJECT pXofSave) PURE;
'    STDMETHOD(AddTopLevelDataObjectsPost)(LPD3DXFILESAVEOBJECT pXofSave) PURE;

'    // callbacks for the user to register and then save templates to the XFile
'    STDMETHOD(RegisterTemplates)(LPD3DXFILE pXFileApi) PURE;
'    STDMETHOD(SaveTemplates)(LPD3DXFILESAVEOBJECT pXofSave) PURE;
'};


'//----------------------------------------------------------------------------
'// D3DXCALLBACK_SEARCH_FLAGS:
'// --------------------------
'// Flags that can be passed into ID3DXAnimationSet::GetCallback.
'//----------------------------------------------------------------------------
%D3DXCALLBACK_SEARCH_EXCLUDING_INITIAL_POSITION = &H01??? ' // exclude callbacks at the initial position from the search
%D3DXCALLBACK_SEARCH_BEHIND_INITIAL_POSITION    = &H02??? ' // reverse the callback search direction

%D3DXCALLBACK_SEARCH_FORCE_DWORD                = &H7FFFFFFF???

'//----------------------------------------------------------------------------
'// ID3DXAnimationSet:
'// ------------------
'// This interface implements an animation set.
'//----------------------------------------------------------------------------

INTERFACE ID3DXAnimationSet $IID_ID3DXAnimationSet

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
   ) AS DWORD                                           ' LPCSTR
   ' =====================================================================================
   METHOD GetPeriod ( _                                 ' VTable offset = 16
   ) AS DOUBLE                                          ' DOUBLE
   ' =====================================================================================
   METHOD GetPeriodicPosition ( _                       ' VTable offset = 20
   ) AS DOUBLE                                          ' DOUBLE
   ' =====================================================================================
   METHOD GetNumAnimations ( _                          ' VTable offset = 24
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetAnimationNameByIndex ( _                   ' VTable offset = 28
     BYVAL Index AS DWORD _                             ' __in  UINT Index
   , BYREF ppName AS ASCIIZ _                           ' __out LPCSTR *ppName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAnimationIndexByName ( _                   ' VTable offset = 32
     BYREF pName AS ASCIIZ _                            ' __in  LPCSTR pName
   , BYREF pIndex AS DWORD _                            ' __out UINT *pIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSRT ( _                                    ' VTable offset = 36
     BYVAL PeriodicPosition AS DOUBLE _                 ' __in  DOUBLE PeriodicPosition
   , BYVAL Animation AS DWORD _                         ' __in  UINT Animation
   , BYREF pScale AS D3DXVECTOR3 _                      ' __out D3DXVECTOR3 *pScale
   , BYREF pRotation AS D3DXQUATERNION _                ' __out D3DXQUATERNION *pRotation
   , BYREF pTranslation AS D3DXVECTOR3 _                ' __out D3DXVECTOR3 *pTranslation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCallback ( _                               ' VTable offset = 40
     BYVAL Position AS DOUBLE _                         ' __in  DOUBLE Position
   , BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   , BYREF pCallbackPosition AS DOUBLE _                ' __out DOUBLE *pCallbackPosition
   , BYREF ppCallbackData AS DWORD _                    ' __out LPVOID *ppCallbackData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

'//----------------------------------------------------------------------------
'// D3DXPLAYBACK_TYPE:
'// ------------------
'// This enum defines the type of animation set loop modes.
'//----------------------------------------------------------------------------
%D3DXPLAY_LOOP          = 0???
%D3DXPLAY_ONCE          = 1???
%D3DXPLAY_PINGPONG      = 2???

%D3DXPLAY_FORCE_DWORD   = &H7FFFFFFF???  ' /* force 32-bit size enum */

'//----------------------------------------------------------------------------
'// D3DXKEY_VECTOR3:
'// ----------------
'// This structure describes a vector key for use in keyframe animation.
'// It specifies a vector Value at a given Time. This is used for scale and
'// translation keys.
'//----------------------------------------------------------------------------
' // Size = 16 bytes
TYPE D3DXKEY_VECTOR3 DWORD
   Time  AS SINGLE
   Value AS D3DXVECTOR3
END TYPE

'//----------------------------------------------------------------------------
'// D3DXKEY_QUATERNION:
'// -------------------
'// This structure describes a quaternion key for use in keyframe animation.
'// It specifies a quaternion Value at a given Time. This is used for rotation
'// keys.
'//----------------------------------------------------------------------------
' // Size = 20 bytes
TYPE D3DXKEY_QUATERNION DWORD
   Time  AS SINGLE
   Value AS D3DXQUATERNION
END TYPE

'//----------------------------------------------------------------------------
'// D3DXKEY_CALLBACK:
'// -----------------
'// This structure describes an callback key for use in keyframe animation.
'// It specifies a pointer to user data at a given Time.
'//----------------------------------------------------------------------------
' // Size = 8 bytes
TYPE D3DXKEY_CALLBACK DWORD
   Time          AS SINGLE
   pCallbackData AS DWORD
END TYPE

'//----------------------------------------------------------------------------
'// D3DXCOMPRESSION_FLAGS:
'// ----------------------
'// Flags that can be passed into ID3DXKeyframedAnimationSet::Compress.
'//----------------------------------------------------------------------------
%D3DXCOMPRESS_DEFAULT     = &H00???
%D3DXCOMPRESS_FORCE_DWORD = &H7FFFFFFF???

'//----------------------------------------------------------------------------
'// ID3DXKeyframedAnimationSet:
'// ---------------------------
'// This interface implements a compressable keyframed animation set.
'//----------------------------------------------------------------------------

INTERFACE ID3DXKeyframedAnimationSet $IID_ID3DXKeyframedAnimationSet

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3DXAnimationSet methods
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
   ) AS DWORD                                           ' LPCSTR
   ' =====================================================================================
   METHOD GetPeriod ( _                                 ' VTable offset = 16
   ) AS DOUBLE                                          ' DOUBLE
   ' =====================================================================================
   METHOD GetPeriodicPosition ( _                       ' VTable offset = 20
   ) AS DOUBLE                                          ' DOUBLE
   ' =====================================================================================
   METHOD GetNumAnimations ( _                          ' VTable offset = 24
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetAnimationNameByIndex ( _                   ' VTable offset = 28
     BYVAL Index AS DWORD _                             ' __in  UINT Index
   , BYREF ppName AS ASCIIZ _                           ' __out LPCSTR *ppName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAnimationIndexByName ( _                   ' VTable offset = 32
     BYREF pName AS ASCIIZ _                            ' __in  LPCSTR pName
   , BYREF pIndex AS DWORD _                            ' __out UINT *pIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSRT ( _                                    ' VTable offset = 36
     BYVAL PeriodicPosition AS DOUBLE _                 ' __in  DOUBLE PeriodicPosition
   , BYVAL Animation AS DWORD _                         ' __in  UINT Animation
   , BYREF pScale AS D3DXVECTOR3 _                      ' __out D3DXVECTOR3 *pScale
   , BYREF pRotation AS D3DXQUATERNION _                ' __out D3DXQUATERNION *pRotation
   , BYREF pTranslation AS D3DXVECTOR3 _                ' __out D3DXVECTOR3 *pTranslation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCallback ( _                               ' VTable offset = 40
     BYVAL Position AS DOUBLE _                         ' __in  DOUBLE Position
   , BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   , BYREF pCallbackPosition AS DOUBLE _                ' __out DOUBLE *pCallbackPosition
   , BYREF ppCallbackData AS DWORD _                    ' __out LPVOID *ppCallbackData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3DXKeyframedAnimationSet methods
   ' =====================================================================================
   METHOD GetPlaybackType ( _                           ' VTable offset = 44
   ) AS DWORD                                           ' D3DXPLAYBACK_TYPE
   ' =====================================================================================
   METHOD GetSourceTicksPerSecond ( _                   ' VTable offset = 48
   ) AS DOUBLE                                          ' DOUBLE
   ' =====================================================================================
   METHOD GetNumScaleKeys ( _                           ' VTable offset = 52
     BYVAL DWORD _                                      ' __in UINT Animation
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetScaleKeys ( _                              ' VTable offset = 56
     BYVAL Animation AS DWORD _                         ' __in  UINT Animation
   , BYREF pScaleKeys AS D3DXKEY_VECTOR3 _              ' __out LPD3DXKEY_VECTOR3 pScaleKeys
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetScaleKey ( _                               ' VTable offset = 60
     BYVAL Animation AS DWORD _                         ' __in  UINT Animation
   , BYVAL Key AS DWORD _                               ' __in  UINT Key
   , BYREF pScaleKey AS D3DXKEY_VECTOR3 _               ' __out LPD3DXKEY_VECTOR3 pScaleKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetScaleKey ( _                               ' VTable offset = 64
     BYVAL Animation AS DWORD _                         ' __in  UINT Animation
   , BYVAL Key AS DWORD _                               ' __in  UINT Key
   , BYREF pScaleKey AS D3DXKEY_VECTOR3 _               ' __out LPD3DXKEY_VECTOR3 pScaleKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumRotationKeys ( _                        ' VTable offset = 68
     BYVAL Animation AS DWORD _                         ' __in UINT Animation
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetRotationKeys ( _                           ' VTable offset = 72
     BYVAL Animation AS DWORD _                         ' __in UINT Animation
   , BYREF pRotationKeys AS D3DXKEY_QUATERNION _        ' __out LPD3DXKEY_QUATERNION pRotationKeys
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetRotationKey ( _                            ' VTable offset = 76
     BYVAL Animation AS DWORD _                         ' __in  UINT Animation
   , BYVAL Key AS DWORD _                               ' __in  UINT Key
   , BYREF pRotationKey AS D3DXKEY_QUATERNION _         ' __out LPD3DXKEY_QUATERNION pRotationKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRotationKey ( _                            ' VTable offset = 80
     BYVAL Animation AS DWORD _                         ' __in UINT Animation
   , BYVAL Key AS DWORD _                               ' __in UINT Key
   , BYREF pRotationKey AS D3DXKEY_QUATERNION _         ' __in LPD3DXKEY_QUATERNION pRotationKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumTranslationKeys ( _                     ' VTable offset = 84
     BYVAL Animation AS DWORD _                         ' __in UINT Animation
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetTranslationKeys ( _                        ' VTable offset = 88
     BYVAL Animation AS DWORD _                         ' __in  UINT Animation
   , BYREF pTranslationKeys AS D3DXKEY_VECTOR3 _        ' __out LPD3DXKEY_VECTOR3 pTranslationKeys
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTranslationKey ( _                         ' VTable offset = 92
     BYVAL Animation AS DWORD _                         ' __in  UINT Animation
   , BYVAL Key AS DWORD _                               ' __in  UINT Key
   , BYREF pTranslationKey AS D3DXKEY_VECTOR3 _         ' __out LPD3DXKEY_VECTOR3 pTranslationKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTranslationKey ( _                         ' VTable offset = 96
     BYVAL Animation AS DWORD _                         ' __in UINT Animation
   , BYVAL Key AS DWORD _                               ' __in UINT Key
   , BYREF pTranslationKey AS D3DXKEY_VECTOR3 _         ' __in LPD3DXKEY_VECTOR3 pTranslationKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumCallbackKeys ( _                        ' VTable offset = 100
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetCallbackKeys ( _                           ' VTable offset = 104
     BYREF pCallbackKeys AS DWORD _                     ' __out LPD3DXKEY_CALLBACK pCallbackKeys
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCallbackKey ( _                            ' VTable offset = 108
     BYVAL Key AS DWORD _                               ' __in  UINT Key
   , BYREF pCallbackKey AS DWORD _                      ' __out LPD3DXKEY_CALLBACK pCallbackKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCallbackKey ( _                            ' VTable offset = 112
     BYVAL Key AS DWORD _                               ' __in UINT Key
   , BYREF pCallbackKey AS DWORD _                      ' __in LPD3DXKEY_CALLBACK pCallbackKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterScaleKey ( _                        ' VTable offset = 116
     BYVAL Animation AS DWORD _                         ' __in UINT Animation
   , BYVAL Key AS DWORD _                               ' __in UINT Key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterRotationKey ( _                     ' VTable offset = 120
     BYVAL Animation AS DWORD _                         ' __in UINT Animation
   , BYVAL Key AS DWORD _                               ' __in UINT Key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterTranslationKey ( _                  ' VTable offset = 124
     BYVAL Animation AS DWORD _                         ' __in UINT Animation
   , BYVAL Key AS DWORD _                               ' __in UINT Key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterAnimationSRTKeys ( _                  ' VTable offset = 128
     BYREF pName AS ASCIIZ _                            ' __in  LPCSTR pName
   , BYVAL NumScaleKeys AS DWORD _                      ' __in  UINT NumScaleKeys
   , BYVAL NumRotationKeys AS DWORD _                   ' __in  UINT NumRotationKeys
   , BYVAL NumTranslationKeys AS DWORD _                ' __in  UINT NumTranslationKeys
   , BYREF pScaleKeys AS D3DXKEY_VECTOR3 _              ' __in  CONST D3DXKEY_VECTOR3 *pScaleKeys
   , BYREF pRotationKeys AS D3DXKEY_QUATERNION _        ' __in  CONST D3DXKEY_QUATERNION *pRotationKeys
   , BYREF pTranslationKeys AS D3DXKEY_VECTOR3 _        ' __in  CONST D3DXKEY_VECTOR3 *pTranslationKeys
   , BYREF pAnimationIndex AS DWORD _                   ' __out DWORD *pAnimationIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compress ( _                                  ' VTable offset = 132
     BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   , BYVAL Lossiness AS SINGLE _                        ' __in  FLOAT Lossiness
   , BYREF pHierarchy AS D3DXFRAME _                    ' __in  LPD3DXFRAME pHierarchy
   , BYREF ppCompressedData AS ID3DXBuffer _            ' __out LPD3DXBUFFER *ppCompressedData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterAnimation ( _                       ' VTable offset = 136
     BYVAL Index AS DWORD _                             ' __in UINT Index
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

'//----------------------------------------------------------------------------
'// ID3DXCompressedAnimationSet:
'// ----------------------------
'// This interface implements a compressed keyframed animation set.
'//----------------------------------------------------------------------------

INTERFACE ID3DXCompressedAnimationSet $IID_ID3DXCompressedAnimationSet

   INHERIT IUnknown

   ' =====================================================================================
   ' ID3DXAnimationSet methods
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
   ) AS DWORD                                           ' LPCSTR
   ' =====================================================================================
   METHOD GetPeriod ( _                                 ' VTable offset = 16
   ) AS DOUBLE                                          ' DOUBLE
   ' =====================================================================================
   METHOD GetPeriodicPosition ( _                       ' VTable offset = 20
   ) AS DOUBLE                                          ' DOUBLE
   ' =====================================================================================
   METHOD GetNumAnimations ( _                          ' VTable offset = 24
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetAnimationNameByIndex ( _                   ' VTable offset = 28
     BYVAL Index AS DWORD _                             ' __in  UINT Index
   , BYREF ppName AS ASCIIZ _                           ' __out LPCSTR *ppName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAnimationIndexByName ( _                   ' VTable offset = 32
     BYREF pName AS ASCIIZ _                            ' __in  LPCSTR pName
   , BYREF pIndex AS DWORD _                            ' __out UINT *pIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSRT ( _                                    ' VTable offset = 36
     BYVAL PeriodicPosition AS DOUBLE _                 ' __in  DOUBLE PeriodicPosition
   , BYVAL Animation AS DWORD _                         ' __in  UINT Animation
   , BYREF pScale AS D3DXVECTOR3 _                      ' __out D3DXVECTOR3 *pScale
   , BYREF pRotation AS D3DXQUATERNION _                ' __out D3DXQUATERNION *pRotation
   , BYREF pTranslation AS D3DXVECTOR3 _                ' __out D3DXVECTOR3 *pTranslation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCallback ( _                               ' VTable offset = 40
     BYVAL Position AS DOUBLE _                         ' __in  DOUBLE Position
   , BYVAL Flags AS DWORD _                             ' __in  DWORD Flags
   , BYREF pCallbackPosition AS DOUBLE _                ' __out DOUBLE *pCallbackPosition
   , BYREF ppCallbackData AS DWORD _                    ' __out LPVOID *ppCallbackData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ID3DXCompressedAnimationSet methods
   ' =====================================================================================
   METHOD GetPlaybackType ( _                           ' VTable offset = 44
   ) AS DWORD                                           ' D3DXPLAYBACK_TYPE
   ' =====================================================================================
   METHOD GetSourceTicksPerSecond ( _                   ' VTable offset = 48
   ) AS DOUBLE                                          ' DOUBLE
   ' =====================================================================================
   METHOD GetCompressedData ( _                         ' VTable offset = 52
     BYREF ppCompressedData AS ID3DXBuffer _            ' __out LPD3DXBUFFER *ppCompressedData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumCallbackKeys ( _                        ' VTable offset = 56
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetCallbackKeys ( _                           ' VTable offset = 60
     BYREF pCallbackKeys AS DWORD _                     ' __out LPD3DXKEY_CALLBACK pCallbackKeys
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

'//----------------------------------------------------------------------------
'// D3DXPRIORITY_TYPE:
'// ------------------
'// This enum defines the type of priority group that a track can be assigned to.
'//----------------------------------------------------------------------------
%D3DXPRIORITY_LOW         = 0???          ' // This track should be blended with all low priority tracks before mixed with the high priority result
%D3DXPRIORITY_HIGH        = 1???          ' // This track should be blended with all high priority tracks before mixed with the low priority result
%D3DXPRIORITY_FORCE_DWORD = &H7FFFFFFF??? ' /* force 32-bit size enum */

'//----------------------------------------------------------------------------
'// D3DXTRACK_DESC:
'// ---------------
'// This structure describes the mixing information of an animation track.
'// The mixing information consists of the current position, speed, and blending
'// weight for the track.  The Flags field also specifies whether the track is
'// low or high priority.  Tracks with the same priority are blended together
'// and then the two resulting values are blended using the priority blend factor.
'// A track also has an animation set (stored separately) associated with it.
'//----------------------------------------------------------------------------
' // Size = 24 bytes
TYPE D3DXTRACK_DESC DWORD
   Priority AS DWORD    ' D3DXPRIORITY_TYPE
   Weight   AS SINGLE   ' FLOAT
   Speed    AS SINGLE   ' FLOAT
   Position AS DOUBLE   ' DOUBLE
   Enable   AS LONG     ' BOOL
END TYPE

'//----------------------------------------------------------------------------
'// D3DXEVENT_TYPE:
'// ---------------
'// This enum defines the type of events keyable via the animation controller.
'//----------------------------------------------------------------------------
%D3DXEVENT_TRACKSPEED    = 0???
%D3DXEVENT_TRACKWEIGHT   = 1???
%D3DXEVENT_TRACKPOSITION = 2???
%D3DXEVENT_TRACKENABLE   = 3???
%D3DXEVENT_PRIORITYBLEND = 4???
%D3DXEVENT_FORCE_DWORD   = &H7FFFFFFF???   ' /* force 32-bit size enum */

'//----------------------------------------------------------------------------
'// D3DXTRANSITION_TYPE:
'// --------------------
'// This enum defines the type of transtion performed on a event that
'// transitions from one value to another.
'//----------------------------------------------------------------------------
%D3DXTRANSITION_LINEAR        = &H000???       ' // Linear transition from one value to the next
%D3DXTRANSITION_EASEINEASEOUT = &H001???       ' // Ease-In Ease-Out spline transtion from one value to the next
%D3DXTRANSITION_FORCE_DWORD   = &H7FFFFFFF???  ' /* force 32-bit size enum */


'//----------------------------------------------------------------------------
'// D3DXEVENT_DESC:
'// ---------------
'// This structure describes a animation controller event.
'// It gives the event's type, track (if the event is a track event), global
'// start time, duration, transition method, and target value.
'//----------------------------------------------------------------------------

' // Size = 8 bytes
UNION D3DXEVENT_DESC_UNION DWORD
   Weight   AS SINGLE      ' FLOAT
   Speed    AS SINGLE      ' FLOAT
   Position AS DOUBLE      ' FLOAT
   Enable   AS LONG        ' BOOL
END UNION

' // Size = 36 bytes
TYPE D3DXEVENT_DESC DWORD
   Type       AS DWORD     ' D3DXEVENT_TYPE
   Track      AS DWORD     ' UINT
   StartTime  AS DOUBLE    ' DOUBLE
   Duration   AS DOUBLE    ' DOUBLE
   Transition AS DWORD     ' D3DXTRANSITION_TYPE
   D3DXEVENT_DESC_UNION
END TYPE

'//----------------------------------------------------------------------------
'// D3DXEVENTHANDLE:
'// ----------------
'// Handle values used to efficiently reference animation controller events.
'//----------------------------------------------------------------------------
'MACRO D3DXEVENTHANDLE = DWORD
'MACRO LPD3DXEVENTHANDLE = D3DXEVENTHANDLE PTR

'//----------------------------------------------------------------------------
'// ID3DXAnimationCallbackHandler:
'// ------------------------------
'// This interface is intended to be implemented by the application, and can
'// be used to handle callbacks in animation sets generated when
'// ID3DXAnimationController::AdvanceTime() is called.
'//----------------------------------------------------------------------------

'DECLARE_INTERFACE(ID3DXAnimationCallbackHandler)
'{
'    //----------------------------------------------------------------------------
'    // ID3DXAnimationCallbackHandler::HandleCallback:
'    // ----------------------------------------------
'    // This method gets called when a callback occurs for an animation set in one
'    // of the tracks during the ID3DXAnimationController::AdvanceTime() call.
'    //
'    // Parameters:
'    //  Track
'    //      Index of the track on which the callback occured.
'    //  pCallbackData
'    //      Pointer to user owned callback data.
'    //
'    //----------------------------------------------------------------------------
'    STDMETHOD(HandleCallback)(THIS_ UINT Track, LPVOID pCallbackData) PURE;
'};


'//----------------------------------------------------------------------------
'// ID3DXAnimationController:
'// -------------------------
'// This interface implements the main animation functionality. It connects
'// animation sets with the transform frames that are being animated. Allows
'// mixing multiple animations for blended animations or for transistions
'// It adds also has methods to modify blending parameters over time to
'// enable smooth transistions and other effects.
'//----------------------------------------------------------------------------

INTERFACE ID3DXAnimationController $IID_ID3DXAnimationController

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetMaxNumAnimationOutputs ( _                 ' VTable offset = 12
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetMaxNumAnimationSets ( _                    ' VTable offset = 16
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetMaxNumTracks ( _                           ' VTable offset = 20
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetMaxNumEvents ( _                           ' VTable offset = 24
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD RegisterAnimationOutput ( _                   ' VTable offset = 28
     BYREF pName AS ASCIIZ _                            ' __in LPCSTR pName
   , BYREF pMatrix AS D3DXMATRIX _                      ' __in D3DXMATRIX *pMatrix
   , BYREF pScale AS D3DXVECTOR3 _                      ' __in D3DXVECTOR3 *pScale
   , BYREF pRotation AS D3DXQUATERNION _                ' __in D3DXQUATERNION *pRotation
   , BYREF pTranslation AS D3DXVECTOR3 _                ' __in D3DXVECTOR3 *pTranslation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterAnimationSet ( _                      ' VTable offset = 32
     BYVAL pAnimSet AS ID3DXAnimationSet _              ' __in LPD3DXANIMATIONSET pAnimSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterAnimationSet ( _                    ' VTable offset = 36
     BYVAL pAnimSet AS ID3DXAnimationSet _              ' __in LPD3DXANIMATIONSET pAnimSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumAnimationSets ( _                       ' VTable offset = 40
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetAnimationSet ( _                           ' VTable offset = 44
     BYVAL Index AS DWORD _                             ' __in  UINT Index
   , BYREF ppAnimationSet AS ID3DXAnimationSet _        ' __out LPD3DXANIMATIONSET *ppAnimationSet
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetAnimationSetByName ( _                     ' VTable offset = 48
     BYREF szName AS ASCIIZ _                           ' __in  LPCSTR szName
   , BYREF ppAnimationSet AS ID3DXAnimationSet _        ' __out LPD3DXANIMATIONSET *ppAnimationSet
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD AdvanceTime ( _                               ' VTable offset = 52
     BYVAL TimeDelta AS DOUBLE _                        ' __in DOUBLE TimeDelta
   , BYVAL pCallbackHandler AS DWORD _                  ' __in LPD3DXANIMATIONCALLBACKHANDLER pCallbackHandler
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD ResetTime ( _                                 ' VTable offset = 56
   ) AS DWORD                                           ' UINT
   ' =====================================================================================
   METHOD GetTime ( _                                   ' VTable offset = 60
   ) AS DOUBLE                                          ' DOUBLE
   ' =====================================================================================
   METHOD SetTrackAnimationSet ( _                      ' VTable offset = 64
     BYVAL Track AS DWORD _                             ' __in UINT Track
   , BYVAL pAnimSet AS ID3DXAnimationSet _              ' __in LPD3DXANIMATIONSET pAnimSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTrackAnimationSet ( _                      ' VTable offset = 68
     BYVAL Track AS DWORD _                             ' __in UINT Track
   , BYREF ppAnimSet AS ID3DXAnimationSet _             ' __in LPD3DXANIMATIONSET *ppAnimSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTrackPriority ( _                          ' VTable offset = 72
     BYVAL Track AS DWORD _                             ' __in UINT Track
   , BYVAL Priority AS DWORD _                          ' __in D3DXPRIORITY_TYPE Priority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTrackSpeed ( _                             ' VTable offset = 76
     BYVAL Track AS DWORD _                             ' __in UINT Track
   , BYVAL Speed AS SINGLE _                            ' __in FLOAT Speed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTrackWeight ( _                            ' VTable offset = 80
     BYVAL Track AS DWORD _                             ' __in UINT Track
   , BYVAL Weight AS SINGLE _                           ' __in FLOAT Weight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTrackPosition ( _                          ' VTable offset = 84
     BYVAL Track AS DWORD _                             ' __in UINT Track
   , BYVAL Position AS DOUBLE _                         ' __in DOUBLE Position
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTrackEnable ( _                            ' VTable offset = 88
     BYVAL Track AS DWORD _                             ' __in UINT Track
   , BYVAL Enable AS LONG _                             ' __in BOOL Enable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTrackDesc ( _                              ' VTable offset = 92
     BYVAL Track AS DWORD _                             ' __in UINT Track
   , BYREF pDesc AS D3DXTRACK_DESC _                    ' __in LPD3DXTRACK_DESC pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTrackDesc ( _                              ' VTable offset = 96
     BYVAL Track AS DWORD _                             ' __in  UINT Track
   , BYREF pDesc AS D3DXTRACK_DESC _                    ' __out LPD3DXTRACK_DESC pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPriorityBlend ( _                          ' VTable offset = 100
     BYVAL BlendWeight AS SINGLE _                      ' __in FLOAT BlendWeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPriorityBlend ( _                          ' VTable offset = 104
   ) AS SINGLE                                          ' SINGLE
   ' =====================================================================================
   METHOD KeyTrackSpeed ( _                             ' VTable offset = 108
     BYVAL Track AS DWORD _                             ' __in UINT Track
   , BYVAL NewSpeed AS SINGLE _                         ' __in FLOAT NewSpeed
   , BYVAL StartTime AS DOUBLE _                        ' __in DOUBLE StartTime
   , BYVAL Duration AS DOUBLE _                         ' __in DOUBLE Duration
   , BYVAL Transition AS DWORD _                        ' __in D3DXTRANSITION_TYPE Transition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD KeyTrackWeight ( _                            ' VTable offset = 112
     BYVAL Track AS DWORD _                             ' __in UINT Track
   , BYVAL NewWeight AS SINGLE _                        ' __in FLOAT NewWeight
   , BYVAL StartTime AS DOUBLE _                        ' __in DOUBLE StartTime
   , BYVAL Duration AS DOUBLE _                         ' __in DOUBLE Duration
   , BYVAL Transition AS DWORD _                        ' __in D3DXTRANSITION_TYPE Transition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD KeyTrackPosition ( _                          ' VTable offset = 116
     BYVAL Track AS DWORD _                             ' __in UINT Track
   , BYVAL NewPosition AS SINGLE _                      ' __in FLOAT NewPosition
   , BYVAL StartTime AS DOUBLE _                        ' __in DOUBLE StartTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD KeyTrackEnable ( _                            ' VTable offset = 120
     BYVAL Track AS DWORD _                             ' __in UINT Track
   , BYVAL NewEnable AS LONG _                          ' __in FLOAT NewEnable
   , BYVAL StartTime AS DOUBLE _                        ' __in DOUBLE StartTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD KeyPriorityBlend ( _                          ' VTable offset = 124
     BYVAL NewBlendWeight AS SINGLE _                   ' __in FLOAT NewBlendWeight
   , BYVAL StartTime AS DOUBLE _                        ' __in DOUBLE StartTime
   , BYVAL Duration AS DOUBLE _                         ' __in DOUBLE Duration
   , BYVAL Transition AS DWORD _                        ' __in D3DXTRANSITION_TYPE Transition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnkeyEvent ( _                                ' VTable offset = 128
     BYVAL hEvent AS DWORD _                            ' __in D3DXEVENTHANDLE hEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnkeyAllTrackEvents ( _                       ' VTable offset = 132
     BYVAL Track AS DWORD _                             ' __in UINT Track
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnkeyAllPriorityBlends ( _                    ' VTable offset = 136
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentTrackEvent ( _                      ' VTable offset = 140
     BYVAL Track AS DWORD _                             ' __in UINT Track
   , BYVAL EventType AS DWORD _                         ' __in D3DXEVENT_TYPE EventType
   ) AS DWORD                                           ' D3DXEVENTHANDLE
   ' =====================================================================================
   METHOD GetCurrentPriorityBlend ( _                   ' VTable offset = 144
   ) AS DWORD                                           ' D3DXEVENTHANDLE
   ' =====================================================================================
   METHOD GetUpcomingTrackEvent ( _                     ' VTable offset = 148
     BYVAL Track AS DWORD _                             ' __in UINT Track
   , BYVAL hEvent AS DWORD _                            ' __in D3DXEVENTHANDLE hEvent
   ) AS DWORD                                           ' D3DXEVENTHANDLE
   ' =====================================================================================
   METHOD GetUpcomingPriorityBlend ( _                  ' VTable offset = 152
     BYVAL hEvent AS DWORD _                            ' __in D3DXEVENTHANDLE hEvent
   ) AS DWORD                                           ' D3DXEVENTHANDLE
   ' =====================================================================================
   METHOD ValidateEvent ( _                             ' VTable offset = 156
     BYVAL hEvent AS DWORD _                            ' __in D3DXEVENTHANDLE hEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEventDesc ( _                              ' VTable offset = 160
     BYVAL hEvent AS DWORD _                            ' __in  D3DXEVENTHANDLE hEvent
   , BYREF pDesc AS D3DXEVENT_DESC _                    ' __out LPD3DXEVENT_DESC pDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloneAnimationController ( _                  ' VTable offset = 164
     BYVAL MaxNumAnimationOutputs AS DWORD _            ' __in UINT MaxNumAnimationOutputs
   , BYVAL MaxNumAnimationSets AS DWORD _               ' __in UINT MaxNumAnimationSets
   , BYVAL MaxNumTracks AS DWORD _                      ' __in UINT MaxNumTracks
   , BYVAL MaxNumEvents AS DWORD _                      ' __in UINT MaxNumEvents
   , BYREF ppAnimController AS ID3DXAnimationController _ ' LPD3DXANIMATIONCONTROLLER *ppAnimController
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

'//----------------------------------------------------------------------------
'// D3DXLoadMeshHierarchyFromX:
'// ---------------------------
'// Loads the first frame hierarchy in a .X file.
'//
'// Parameters:
'//  Filename
'//      Name of the .X file
'//  MeshOptions
'//      Mesh creation options for meshes in the file (see d3dx9mesh.h)
'//  pD3DDevice
'//      D3D9 device on which meshes in the file are created in
'//  pAlloc
'//      Allocation interface used to allocate nodes of the frame hierarchy
'//  pUserDataLoader
'//      Application provided interface to allow loading of user data
'//  ppFrameHierarchy
'//      Returns root node pointer of the loaded frame hierarchy
'//  ppAnimController
'//      Returns pointer to an animation controller corresponding to animation
'//		in the .X file. This is created with default max tracks and events
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXLoadMeshHierarchyFromXA IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadMeshHierarchyFromXA" (_
   BYREF Filename AS ASCIIZ _                           ' __in  LPCSTR Filename
 , BYVAL MeshOptions AS DWORD _                         ' __in  DWORD MeshOptions
 , BYVAL pD3DDevice AS IDirect3DDevice9 _               ' __in  LPDIRECT3DDEVICE9 pD3DDevice
 , BYVAL pAlloc AS IUnknown _                           ' __in  LPD3DXALLOCATEHIERARCHY pAlloc
 , BYVAL pUserDataLoader AS IUnknown _                  ' __in  LPD3DXLOADUSERDATA pUserDataLoader
 , BYREF ppFrameHierarchy AS D3DXFRAME _                ' __out LPD3DXFRAME *ppFrameHierarchy
 , BYREF ppAnimController AS ID3DXAnimationController _ ' __out LPD3DXANIMATIONCONTROLLER *ppAnimController
 ) AS LONG                                              ' HRESULT


DECLARE FUNCTION D3DXLoadMeshHierarchyFromXW IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadMeshHierarchyFromXW" (_
   BYREF Filename AS WSTRINGZ _                         ' __in  LPCWSTR Filename
 , BYVAL MeshOptions AS DWORD _                         ' __in  DWORD MeshOptions
 , BYVAL pD3DDevice AS IDirect3DDevice9 _               ' __in  LPDIRECT3DDEVICE9 pD3DDevice
 , BYVAL pAlloc AS IUnknown _                           ' __in  LPD3DXALLOCATEHIERARCHY pAlloc
 , BYVAL pUserDataLoader AS IUnknown _                  ' __in  LPD3DXLOADUSERDATA pUserDataLoader
 , BYREF ppFrameHierarchy AS D3DXFRAME _                ' __out LPD3DXFRAME *ppFrameHierarchy
 , BYREF ppAnimController AS ID3DXAnimationController _ ' __out LPD3DXANIMATIONCONTROLLER *ppAnimController
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXLoadMeshHierarchyFromX = D3DXLoadMeshHierarchyFromXW
#ELSE
   MACRO D3DXLoadMeshHierarchyFromX = D3DXLoadMeshHierarchyFromXA
#ENDIF

DECLARE FUNCTION D3DXLoadMeshHierarchyFromXInMemory IMPORT $D3DX_DLLNAME ALIAS "D3DXLoadMeshHierarchyFromXInMemory" (_
   BYVAL Memory AS DWORD _                              ' __in  LPCVOID Memory
 , BYVAL SizeOfMemory AS DWORD _                        ' __in  DWORD SizeOfMemory
 , BYVAL MeshOptions AS DWORD _                         ' __in  DWORD MeshOptions
 , BYVAL pD3DDevice AS IDirect3DDevice9 _               ' __in  LPDIRECT3DDEVICE9 pD3DDevice
 , BYVAL pAlloc AS IUnknown _                           ' __in  LPD3DXALLOCATEHIERARCHY pAlloc
 , BYVAL pUserDataLoader AS IUnknown _                  ' __in  LPD3DXLOADUSERDATA pUserDataLoader
 , BYREF ppFrameHierarchy AS D3DXFRAME _                ' __out LPD3DXFRAME *ppFrameHierarchy
 , BYREF ppAnimController AS ID3DXAnimationController _ ' __out LPD3DXANIMATIONCONTROLLER *ppAnimController
 ) AS LONG                                              ' HRESULT


'//----------------------------------------------------------------------------
'// D3DXSaveMeshHierarchyToFile:
'// ----------------------------
'// Creates a .X file and saves the mesh hierarchy and corresponding animations
'// in it
'//
'// Parameters:
'//  Filename
'//      Name of the .X file
'//  XFormat
'//      Format of the .X file (text or binary, compressed or not, etc)
'//  pFrameRoot
'//      Root node of the hierarchy to be saved
'//  pAnimController
'//      The animation controller whose animation sets are to be stored
'//  pUserDataSaver
'//      Application provided interface to allow adding of user data to
'//        data objects saved to .X file
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXSaveMeshHierarchyToFileA IMPORT $D3DX_DLLNAME ALIAS "D3DXSaveMeshHierarchyToFileA" (_
   BYREF Filename AS ASCIIZ _                           ' __in LPCSTR Filename
 , BYVAL XFormat AS DWORD _                             ' __in DWORD XFormat
 , BYREF pFrameRoot AS D3DXFRAME _                      ' __in CONST D3DXFRAME *pFrameRoot
 , BYVAL pAnimcontroller AS ID3DXAnimationController _  ' __in LPD3DXANIMATIONCONTROLLER pAnimcontroller
 , BYVAL pUserDataSaver AS IUnknown _                   ' __in LPD3DXSAVEUSERDATA pUserDataSaver
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXSaveMeshHierarchyToFileW IMPORT $D3DX_DLLNAME ALIAS "D3DXSaveMeshHierarchyToFileW" (_
   BYREF Filename AS WSTRINGZ _                         ' __in LPCWSTR Filename
 , BYVAL XFormat AS DWORD _                             ' __in DWORD XFormat
 , BYREF pFrameRoot AS D3DXFRAME _                      ' __in CONST D3DXFRAME *pFrameRoot
 , BYVAL pAnimcontroller AS ID3DXAnimationController _  ' __in LPD3DXANIMATIONCONTROLLER pAnimcontroller
 , BYVAL pUserDataSaver AS IUnknown _                   ' __in LPD3DXSAVEUSERDATA pUserDataSaver
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXSaveMeshHierarchyToFile = D3DXSaveMeshHierarchyToFileW
#ELSE
   MACRO D3DXSaveMeshHierarchyToFile = D3DXSaveMeshHierarchyToFileA
#ENDIF

'//----------------------------------------------------------------------------
'// D3DXFrameDestroy:
'// -----------------
'// Destroys the subtree of frames under the root, including the root
'//
'// Parameters:
'//	pFrameRoot
'//		Pointer to the root node
'//  pAlloc
'//      Allocation interface used to de-allocate nodes of the frame hierarchy
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXFrameDestroy IMPORT $D3DX_DLLNAME ALIAS "D3DXFrameDestroy" (_
   BYREF pFrameRoot AS D3DXFRAME _                      ' __in LPD3DXFRAME pFrameRoot
 , BYVAL pAlloc AS IUnknown _                           ' __in LPD3DXALLOCATEHIERARCHY pAlloc
 ) AS LONG                                              ' HRESULT

'//----------------------------------------------------------------------------
'// D3DXFrameAppendChild:
'// ---------------------
'// Add a child frame to a frame
'//
'// Parameters:
'//	pFrameParent
'//		Pointer to the parent node
'//  pFrameChild
'//      Pointer to the child node
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXFrameAppendChild IMPORT $D3DX_DLLNAME ALIAS "D3DXFrameAppendChild" (_
   BYREF pFrameParent AS D3DXFRAME _                    ' __in LPD3DXFRAME pFrameParent
 , BYREF pFrameChild AS D3DXFRAME _                     ' __in CONST D3DXFRAME *pFrameChild
 ) AS LONG                                              ' HRESULT

'//----------------------------------------------------------------------------
'// D3DXFrameFind:
'// --------------
'// Finds a frame with the given name.  Returns NULL if no frame found.
'//
'// Parameters:
'//	pFrameRoot
'//		Pointer to the root node
'//  Name
'//      Name of frame to find
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXFrameFind IMPORT $D3DX_DLLNAME ALIAS "D3DXFrameFind" (_
   BYREF pFrameRoot AS D3DXFRAME _                      ' __in CONST D3DXFRAME *pFrameRoot
 , BYREF Name AS ASCIIZ _                               ' __in LPCSTR Name
 ) AS DWORD                                             ' LPD3DXFRAME

'//----------------------------------------------------------------------------
'// D3DXFrameRegisterNamedMatrices:
'// -------------------------------
'// Finds all frames that have non-null names and registers each of those frame
'// matrices to the given animation controller
'//
'// Parameters:
'//	pFrameRoot
'//		Pointer to the root node
'//	pAnimController
'//		Pointer to the animation controller where the matrices are registered
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXFrameRegisterNamedMatrices IMPORT $D3DX_DLLNAME ALIAS "D3DXFrameRegisterNamedMatrices" (_
   BYREF pFrameRoot AS D3DXFRAME _                      ' __in LPD3DXFRAME pFrameRoot
 , BYVAL pAnimController AS ID3DXAnimationController _  ' __in LPD3DXANIMATIONCONTROLLER pAnimController
 ) AS LONG                                              ' HRESULT

'//----------------------------------------------------------------------------
'// D3DXFrameNumNamedMatrices:
'// --------------------------
'// Counts number of frames in a subtree that have non-null names
'//
'// Parameters:
'//	pFrameRoot
'//		Pointer to the root node of the subtree
'// Return Value:
'//		Count of frames
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXFrameNumNamedMatrices IMPORT $D3DX_DLLNAME ALIAS "D3DXFrameNumNamedMatrices" (_
   BYREF pFrameRoot AS D3DXFRAME _                      ' __in CONST D3DXFRAME *pFrameRoot
 ) AS DWORD                                             ' UINT

'//----------------------------------------------------------------------------
'// D3DXFrameCalculateBoundingSphere:
'// ---------------------------------
'// Computes the bounding sphere of all the meshes in the frame hierarchy.
'//
'// Parameters:
'//	pFrameRoot
'//		Pointer to the root node
'//	pObjectCenter
'//		Returns the center of the bounding sphere
'//	pObjectRadius
'//		Returns the radius of the bounding sphere
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION D3DXFrameCalculateBoundingSphere IMPORT $D3DX_DLLNAME ALIAS "D3DXFrameCalculateBoundingSphere" (_
   BYREF pFrameRoot AS D3DXFRAME _                      ' __in  CONST D3DXFRAME *pFrameRoot
 , BYREF pObjectCenter AS D3DXVECTOR3 _                 ' __in  LPD3DXVECTOR3 pObjectCenter
 , BYREF pObjectRadius AS SINGLE _                      ' __out FLOAT *pObjectRadius
 ) AS LONG                                              ' HRESULT

'//----------------------------------------------------------------------------
'// D3DXCreateKeyframedAnimationSet:
'// --------------------------------
'// This function creates a compressable keyframed animations set interface.
'//
'// Parameters:
'//  pName
'//      Name of the animation set
'//  TicksPerSecond
'//      Number of keyframe ticks that elapse per second
'//  Playback
'//      Playback mode of keyframe looping
'//  NumAnimations
'//      Number of SRT animations
'//  NumCallbackKeys
'//      Number of callback keys
'//  pCallbackKeys
'//      Array of callback keys
'//  ppAnimationSet
'//      Returns the animation set interface
'//
'//-----------------------------------------------------------------------------

DECLARE FUNCTION D3DXCreateKeyframedAnimationSet IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateKeyframedAnimationSet" (_
   BYREF pName AS ASCIIZ _                              ' __in  LPCSTR pName
 , BYVAL TicksPerSecond AS DOUBLE _                     ' __in  DOUBLE TicksPerSecond
 , BYVAL Playback AS DWORD _                            ' __in  D3DXPLAYBACK_TYPE Playback
 , BYVAL NumAnimations AS DWORD _                       ' __in  UINT NumAnimations
 , BYVAL NumCallbackKeys AS DWORD _                     ' __in  UINT NumCallbackKeys
 , BYREF pCallbackKeys AS D3DXKEY_CALLBACK _            ' __in  CONST D3DXKEY_CALLBACK *pCallbackKeys
 , BYREF ppAnimationSet AS ID3DXKeyframedAnimationSet _ ' __out LPD3DXKEYFRAMEDANIMATIONSET *ppAnimationSet
 ) AS LONG                                              ' HRESULT

'//----------------------------------------------------------------------------
'// D3DXCreateCompressedAnimationSet:
'// --------------------------------
'// This function creates a compressed animations set interface from
'// compressed data.
'//
'// Parameters:
'//  pName
'//      Name of the animation set
'//  TicksPerSecond
'//      Number of keyframe ticks that elapse per second
'//  Playback
'//      Playback mode of keyframe looping
'//  pCompressedData
'//      Compressed animation SRT data
'//  NumCallbackKeys
'//      Number of callback keys
'//  pCallbackKeys
'//      Array of callback keys
'//  ppAnimationSet
'//      Returns the animation set interface
'//
'//-----------------------------------------------------------------------------

DECLARE FUNCTION D3DXCreateCompressedAnimationSet IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateCompressedAnimationSet" (_
   BYREF pName AS ASCIIZ _                              ' __in  LPCSTR pName
 , BYVAL TicksPerSecond AS DOUBLE _                     ' __in  DOUBLE TicksPerSecond
 , BYVAL Playback AS DWORD _                            ' __in  D3DXPLAYBACK_TYPE Playback
 , BYVAL pCompressedData AS ID3DXBuffer _               ' __in  LPD3DXBUFFER pCompressedData
 , BYVAL NumCallbackKeys AS DWORD _                     ' __in  UINT NumCallbackKeys
 , BYREF pCallbackKeys AS D3DXKEY_CALLBACK _            ' __in  CONST D3DXKEY_CALLBACK *pCallbackKeys
 , BYREF ppAnimationSet AS ID3DXCompressedAnimationSet _ ' __out LPD3DXCOMPRESSEDANIMATIONSET *ppAnimationSet
 ) AS LONG                                              ' HRESULT

'//----------------------------------------------------------------------------
'// D3DXCreateAnimationController:
'// ------------------------------
'// This function creates an animation controller object.
'//
'// Parameters:
'//  MaxNumMatrices
'//      Maximum number of matrices that can be animated
'//  MaxNumAnimationSets
'//      Maximum number of animation sets that can be played
'//  MaxNumTracks
'//      Maximum number of animation sets that can be blended
'//  MaxNumEvents
'//      Maximum number of outstanding events that can be scheduled at any given time
'//  ppAnimController
'//      Returns the animation controller interface
'//
'//-----------------------------------------------------------------------------

DECLARE FUNCTION D3DXCreateAnimationController IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateAnimationController" (_
   BYVAL MaxNumMatrices AS DWORD _                      ' __in  UINT MaxNumMatrices
 , BYVAL MaxNumAnimationSets AS DWORD _                 ' __in  UINT MaxNumAnimationSets
 , BYVAL MaxNumTracks AS DWORD _                        ' __in  UINT MaxNumTracks
 , BYVAL MaxNumEvents AS DWORD _                        ' __in  UINT MaxNumEvents
 , BYREF ppAnimController AS ID3DXAnimationController _ ' __out LPD3DXANIMATIONCONTROLLER *ppAnimController
 ) AS LONG                                              ' HRESULT
