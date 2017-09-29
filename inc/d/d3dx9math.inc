' ########################################################################################
' Microsoft Windows
' File: d3dx9math.inc
' Contents: D3DX math types and functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3DX9MATH_INC = 1

'//===========================================================================
'//
'// General purpose utilities
'//
'//===========================================================================
'#define D3DX_PI    ((FLOAT)  3.141592654f)
'#define D3DX_1BYPI ((FLOAT)  0.318309886f)

MACRO D3DX_PI  =  3.141592654!
MACRO D3DX_1BYPI = 0.318309886!

'#define D3DXToRadian( degree ) ((degree) * (D3DX_PI / 180.0f))
'#define D3DXToDegree( radian ) ((radian) * (180.0f / D3DX_PI))

MACRO D3DXToRadian(degree) = ((degree) * (D3DX_PI / 180.0))
MACRO D3DXToDegree(radian) = ((radian) * (180.0 / D3DX_PI))


'//===========================================================================
'//
'// Vectors
'//
'//===========================================================================


'//--------------------------
'// 2D Vector
'//--------------------------

' // Size = 8 bytes
TYPE D3DXVECTOR2 DWORD
   x AS SINGLE   ' FLOAT
   y AS SINGLE   ' FLOAT
END TYPE


'//--------------------------
'// 3D Vector
'//--------------------------

' // Size = 12 bytes
TYPE D3DXVECTOR3 DWORD
   x AS SINGLE   ' FLOAT
   y AS SINGLE   ' FLOAT
   z AS SINGLE   ' FLOAT
END TYPE


'//--------------------------
'// 4D Vector
'//--------------------------

' // Size = 16 bytes
TYPE D3DXVECTOR4 DWORD
   x AS SINGLE   ' FLOAT
   y AS SINGLE   ' FLOAT
   z AS SINGLE   ' FLOAT
   w AS SINGLE   ' FLOAT
END TYPE

'//===========================================================================
'//
'// Matrices
'//
'//===========================================================================

' // Size = 64 bytes
TYPE D3DXMATRIX DWORD
   m11 AS SINGLE   ' FLOAT
   m12 AS SINGLE   ' FLOAT
   m13 AS SINGLE   ' FLOAT
   m14 AS SINGLE   ' FLOAT
   m21 AS SINGLE   ' FLOAT
   m22 AS SINGLE   ' FLOAT
   m23 AS SINGLE   ' FLOAT
   m24 AS SINGLE   ' FLOAT
   m31 AS SINGLE   ' FLOAT
   m32 AS SINGLE   ' FLOAT
   m33 AS SINGLE   ' FLOAT
   m34 AS SINGLE   ' FLOAT
   m41 AS SINGLE   ' FLOAT
   m42 AS SINGLE   ' FLOAT
   m43 AS SINGLE   ' FLOAT
   m44 AS SINGLE   ' FLOAT
END TYPE


'//===========================================================================
'//
'//    Quaternions
'//
'//===========================================================================

' // Size = 16 bytes
TYPE D3DXQUATERNION DWORD
   x AS SINGLE   ' FLOAT
   y AS SINGLE   ' FLOAT
   z AS SINGLE   ' FLOAT
   w AS SINGLE   ' FLOAT
END TYPE

'//===========================================================================
'//
'// Planes
'//
'//===========================================================================

' // Size = 16 bytes
TYPE D3DXPLANE DWORD
   a AS SINGLE   ' FLOAT
   b AS SINGLE   ' FLOAT
   c AS SINGLE   ' FLOAT
   d AS SINGLE   ' FLOAT
END TYPE

'//===========================================================================
'//
'// Colors
'//
'//===========================================================================

' // Size = 16 bytes
TYPE D3DXCOLOR DWORD
   r AS SINGLE   ' FLOAT
   g AS SINGLE   ' FLOAT
   b AS SINGLE   ' FLOAT
   a AS SINGLE   ' FLOAT
END TYPE

' Must be placed here because the above structures are also used by other include files.
#INCLUDE ONCE "d3dx9.inc"

'//===========================================================================
'//
'// D3DX math functions:
'//
'// NOTE:
'//  * All these functions can take the same object as in and out parameters.
'//
'//  * Out parameters are typically also returned as return values, so that
'//    the output of one function may be used as a parameter to another.
'//
'//===========================================================================

'//--------------------------
'// 2D Vector
'//--------------------------

DECLARE FUNCTION D3DXVec2Normalize IMPORT $D3DX_DLLNAME ALIAS "D3DXVec2Normalize" (_
   BYREF pOut AS D3DXVECTOR2 _                          ' __in_out D3DXVECTOR2 *pOut
 , BYREF pV AS D3DXVECTOR2 _                            ' __in CONST D3DXVECTOR2 *pV
 ) AS DWORD                                             ' D3DXVECTOR2


'// Hermite interpolation between position V1, tangent T1 (when s == 0)
'// and position V2, tangent T2 (when s == 1).

DECLARE FUNCTION D3DXVec2Hermite IMPORT $D3DX_DLLNAME ALIAS "D3DXVec2Hermite" (_
   BYREF pOut AS D3DXVECTOR2 _                          ' __in_out D3DXVECTOR2 *pOut
 , BYREF pV1 AS D3DXVECTOR2 _                           ' __in CONST D3DXVECTOR2 *pV1
 , BYREF pT1 AS D3DXVECTOR2 _                           ' __in CONST D3DXVECTOR2 *pT1
 , BYREF pV2 AS D3DXVECTOR2 _                           ' __in CONST D3DXVECTOR2 *pV2
 , BYREF pT2 AS D3DXVECTOR2 _                           ' __in CONST D3DXVECTOR2 *pT2
 , BYVAL s AS SINGLE _                                  ' __in FLOAT s
 ) AS DWORD                                             ' D3DXVECTOR2


'// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1)

DECLARE FUNCTION D3DXVec2CatmullRom IMPORT $D3DX_DLLNAME ALIAS "D3DXVec2CatmullRom" (_
   BYREF pOut AS D3DXVECTOR2 _                          ' __in_out D3DXVECTOR2 *pOut
 , BYREF pV0 AS D3DXVECTOR2 _                           ' __in CONST D3DXVECTOR2 *pV0
 , BYREF pV1 AS D3DXVECTOR2 _                           ' __in CONST D3DXVECTOR2 *pV1
 , BYREF pV2 AS D3DXVECTOR2 _                           ' __in CONST D3DXVECTOR2 *pV2
 , BYREF pV3 AS D3DXVECTOR2 _                           ' __in CONST D3DXVECTOR2 *pV3
 , BYVAL s AS SINGLE _                                  ' __in FLOAT s
 ) AS DWORD                                             ' D3DXVECTOR2

'// Barycentric coordinates.  V1 + f(V2-V1) + g(V3-V1)

DECLARE FUNCTION D3DXVec2BaryCentric IMPORT $D3DX_DLLNAME ALIAS "D3DXVec2BaryCentric" (_
   BYREF pOut AS D3DXVECTOR2 _                          ' __in_out D3DXVECTOR2 *pOut
 , BYREF pV1 AS D3DXVECTOR2 _                           ' __in CONST D3DXVECTOR2 *pV1
 , BYREF pV2 AS D3DXVECTOR2 _                           ' __in CONST D3DXVECTOR2 *pV2
 , BYREF pV3 AS D3DXVECTOR2 _                           ' __in CONST D3DXVECTOR2 *pV3
 , BYVAL f AS SINGLE _                                  ' __in FLOAT f
 , BYVAL g AS SINGLE _                                  ' __in FLOAT g
 ) AS DWORD                                             ' D3DXVECTOR2

'// Transform (x, y, 0, 1) by matrix.

DECLARE FUNCTION D3DXVec2Transform IMPORT $D3DX_DLLNAME ALIAS "D3DXVec2Transform" (_
   BYREF pOut AS D3DXVECTOR4 _                          ' __in_out D3DXVECTOR4 *pOut
 , BYREF pV AS D3DXVECTOR2 _                            ' __in CONST D3DXVECTOR2 *pV
 , BYREF pM AS D3DMATRIX _                              ' __in CONST D3DXMATRIX *pM
 ) AS DWORD                                             ' D3DXVECTOR4

'// Transform (x, y, 0, 1) by matrix, project result back into w=1.

DECLARE FUNCTION D3DXVec2TransformCoord IMPORT $D3DX_DLLNAME ALIAS "D3DXVec2TransformCoord" (_
   BYREF pOut AS D3DXVECTOR2 _                          ' __in_out D3DXVECTOR2 *pOut
 , BYREF pV AS D3DXVECTOR2 _                            ' __in CONST D3DXVECTOR2 *pV
 , BYREF pM AS D3DMATRIX _                              ' __in CONST D3DXMATRIX *pM
 ) AS DWORD                                             ' D3DXVECTOR2

'// Transform (x, y, 0, 0) by matrix.

DECLARE FUNCTION D3DXVec2TransformNormal IMPORT $D3DX_DLLNAME ALIAS "D3DXVec2TransformNormal" (_
   BYREF pOut AS D3DXVECTOR2 _                          ' __in_out D3DXVECTOR2 *pOut
 , BYREF pV AS D3DXVECTOR2 _                            ' __in CONST D3DXVECTOR2 *pV
 , BYREF pM AS D3DMATRIX _                              ' __in CONST D3DXMATRIX *pM
 ) AS DWORD                                             ' D3DXVECTOR2

'// Transform Array (x, y, 0, 1) by matrix.

DECLARE FUNCTION D3DXVec2TransformArray IMPORT $D3DX_DLLNAME ALIAS "D3DXVec2TransformArray" (_
   BYREF pOut AS D3DXVECTOR4 _                          ' __in_out D3DXVECTOR4 *pOut
 , BYVAL OutStride AS DWORD _                           ' __in UINT OutStride
 , BYREF pV AS D3DXVECTOR2 _                            ' __in CONST D3DXVECTOR2 *pV
 , BYVAL VStride AS DWORD _                             ' __in UINT VStride
 , BYREF pM AS D3DMATRIX _                              ' __in CONST D3DXMATRIX *pM
 , BYVAL n AS DWORD _                                   ' __in UINT n
 ) AS DWORD                                             ' D3DXVECTOR4

'// Transform Array (x, y, 0, 1) by matrix, project result back into w=1.

DECLARE FUNCTION D3DXVec2TransformCoordArray IMPORT $D3DX_DLLNAME ALIAS "D3DXVec2TransformCoordArray" (_
   BYREF pOut AS D3DXVECTOR2 _                          ' __in_out D3DXVECTOR2 *pOut
 , BYVAL OutStride AS DWORD _                           ' __in UINT OutStride
 , BYREF pV AS D3DXVECTOR2 _                            ' __in CONST D3DXVECTOR2 *pV
 , BYVAL VStride AS DWORD _                             ' __in UINT VStride
 , BYREF pM AS D3DMATRIX _                              ' __in CONST D3DXMATRIX *pM
 , BYVAL n AS DWORD _                                   ' __in UINT n
 ) AS DWORD                                             ' D3DXVECTOR2

'// Transform Array (x, y, 0, 0) by matrix.

DECLARE FUNCTION D3DXVec2TransformNormalArray IMPORT $D3DX_DLLNAME ALIAS "D3DXVec2TransformNormalArray" (_
   BYREF pOut AS D3DXVECTOR2 _                          ' __in_out D3DXVECTOR2 *pOut
 , BYVAL OutStride AS DWORD _                           ' __in UINT OutStride
 , BYREF pV AS D3DXVECTOR2 _                            ' __in CONST D3DXVECTOR2 *pV
 , BYVAL VStride AS DWORD _                             ' __in UINT VStride
 , BYREF pM AS D3DMATRIX _                              ' __in CONST D3DXMATRIX *pM
 , BYVAL n AS DWORD _                                   ' __in UINT n
 ) AS DWORD                                             ' D3DXVECTOR2


'//--------------------------
'// 3D Vector
'//--------------------------

DECLARE FUNCTION D3DXVec3Normalize IMPORT $D3DX_DLLNAME ALIAS "D3DXVec3Normalize" (_
   BYREF pOut AS D3DXVECTOR3 _                          ' __in_out D3DXVECTOR3 *pOut
 , BYREF pV AS D3DXVECTOR3 _                            ' __in CONST D3DXVECTOR3 *pV
 ) AS DWORD                                             ' D3DXVECTOR3

'// Hermite interpolation between position V1, tangent T1 (when s == 0)
'// and position V2, tangent T2 (when s == 1).

DECLARE FUNCTION D3DXVec3Hermite IMPORT $D3DX_DLLNAME ALIAS "D3DXVec3Hermite" (_
   BYREF pOut AS D3DXVECTOR3 _                          ' __in_out D3DXVECTOR3 *pOut
 , BYREF pV1 AS D3DXVECTOR3 _                           ' __in CONST D3DXVECTOR3 *pV1
 , BYREF pT1 AS D3DXVECTOR3 _                           ' __in CONST D3DXVECTOR3 *pT1
 , BYREF pV2 AS D3DXVECTOR3 _                           ' __in CONST D3DXVECTOR3 *pV2
 , BYREF pT2 AS D3DXVECTOR3 _                           ' __in CONST D3DXVECTOR3 *pT2
 , BYVAL s AS SINGLE _                                  ' __in FLOAT s
 ) AS DWORD                                             ' D3DXVECTOR3

'// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1)

DECLARE FUNCTION D3DXVec3CatmullRom IMPORT $D3DX_DLLNAME ALIAS "D3DXVec3CatmullRom" (_
   BYREF pOut AS D3DXVECTOR3 _                          ' __in_out D3DXVECTOR3 *pOut
 , BYREF pV0 AS D3DXVECTOR3 _                           ' __in CONST D3DXVECTOR3 *pV0
 , BYREF pV1 AS D3DXVECTOR3 _                           ' __in CONST D3DXVECTOR3 *pV1
 , BYREF pV2 AS D3DXVECTOR3 _                           ' __in CONST D3DXVECTOR3 *pV2
 , BYREF pV3 AS D3DXVECTOR3 _                           ' __in CONST D3DXVECTOR3 *pV3
 , BYVAL s AS SINGLE _                                  ' __in FLOAT s
 ) AS DWORD                                             ' D3DXVECTOR3

'// Barycentric coordinates.  V1 + f(V2-V1) + g(V3-V1)

DECLARE FUNCTION D3DXVec3BaryCentric IMPORT $D3DX_DLLNAME ALIAS "D3DXVec3BaryCentric" (_
   BYREF pOut AS D3DXVECTOR3 _                          ' __in_out D3DXVECTOR3 *pOut
 , BYREF pV1 AS D3DXVECTOR3 _                           ' __in CONST D3DXVECTOR3 *pV1
 , BYREF pV2 AS D3DXVECTOR3 _                           ' __in CONST D3DXVECTOR3 *pV2
 , BYREF pV3 AS D3DXVECTOR3 _                           ' __in CONST D3DXVECTOR3 *pV3
 , BYVAL f AS SINGLE _                                  ' __in FLOAT f
 , BYVAL g AS SINGLE _                                  ' __in FLOAT g
 ) AS DWORD                                             ' D3DXVECTOR3

'// Transform (x, y, z, 1) by matrix.

DECLARE FUNCTION D3DXVec3Transform IMPORT $D3DX_DLLNAME ALIAS "D3DXVec3Transform" (_
   BYREF pOut AS D3DXVECTOR4 _                          ' __in_out D3DXVECTOR4 *pOut
 , BYREF pV AS D3DXVECTOR3 _                            ' __in CONST D3DXVECTOR3 *pV
 , BYREF pM AS D3DMATRIX _                              ' __in CONST D3DXMATRIX *pM
 ) AS DWORD                                             ' D3DXVECTOR4

'// Transform (x, y, z, 1) by matrix, project result back into w=1.

DECLARE FUNCTION D3DXVec3TransformCoord IMPORT $D3DX_DLLNAME ALIAS "D3DXVec3TransformCoord" (_
   BYREF pOut AS D3DXVECTOR3 _                          ' __in_out D3DXVECTOR3 *pOut
 , BYREF pV AS D3DXVECTOR3 _                            ' __in CONST D3DXVECTOR3 *pV
 , BYREF pM AS D3DMATRIX _                              ' __in CONST D3DXMATRIX *pM
 ) AS DWORD                                             ' D3DXVECTOR3

'// Transform (x, y, z, 0) by matrix.  If you transforming a normal by a
'// non-affine matrix, the matrix you pass to this function should be the
'// transpose of the inverse of the matrix you would use to transform a coord.

DECLARE FUNCTION D3DXVec3TransformNormal IMPORT $D3DX_DLLNAME ALIAS "D3DXVec3TransformNormal" (_
   BYREF pOut AS D3DXVECTOR3 _                          ' __in_out D3DXVECTOR3 *pOut
 , BYREF pV AS D3DXVECTOR3 _                            ' __in CONST D3DXVECTOR3 *pV
 , BYREF pM As D3DMATRIX _                              ' __in CONST D3DXMATRIX *pM
 ) AS DWORD                                             ' D3DXVECTOR3

'// Transform Array (x, y, z, 1) by matrix.

DECLARE FUNCTION D3DXVec3TransformArray IMPORT $D3DX_DLLNAME ALIAS "D3DXVec3TransformArray" (_
   BYREF pOut AS D3DXVECTOR4 _                          ' __in_out D3DXVECTOR4 *pOut
 , BYVAL OutStride AS DWORD _                           ' __in UINT OutStride
 , BYREF pV AS D3DXVECTOR3 _                            ' __in CONST D3DXVECTOR3 *pV
 , BYVAL VStride AS DWORD _                             ' __in UINT VStride
 , BYREF pM AS D3DMATRIX _                              ' __in CONST D3DXMATRIX *pM
 , BYVAL n AS DWORD _                                   ' __in UINT n
 ) AS DWORD                                             ' D3DXVECTOR4

'// Transform Array (x, y, z, 1) by matrix, project result back into w=1.

DECLARE FUNCTION D3DXVec3TransformCoordArray IMPORT $D3DX_DLLNAME ALIAS "D3DXVec3TransformCoordArray" (_
   BYREF pOut AS D3DXVECTOR3 _                          ' __in_out D3DXVECTOR3 *pOut
 , BYVAL OutStride AS DWORD _                           ' __in UINT OutStride
 , BYREF pV AS D3DXVECTOR3 _                            ' __in CONST D3DXVECTOR3 *pV
 , BYVAL VStride AS DWORD _                             ' __in UINT VStride
 , BYREF pM AS D3DMATRIX _                              ' __in CONST D3DXMATRIX *pM
 , BYVAL n AS DWORD _                                   ' __in UINT n
 ) AS DWORD                                             ' D3DXVECTOR3

'// Transform (x, y, z, 0) by matrix.  If you transforming a normal by a
'// non-affine matrix, the matrix you pass to this function should be the
'// transpose of the inverse of the matrix you would use to transform a coord.

DECLARE FUNCTION D3DXVec3TransformNormalArray IMPORT $D3DX_DLLNAME ALIAS "D3DXVec3TransformNormalArray" (_
   BYREF pOut AS D3DXVECTOR3 _                          ' __in_out D3DXVECTOR3 *pOut
 , BYVAL OutStride AS DWORD _                           ' __in UINT OutStride
 , BYREF pV AS D3DXVECTOR3 _                            ' __in CONST D3DXVECTOR3 *pV
 , BYVAL VStride AS DWORD _                             ' __in UINT VStride
 , BYREF pM AS D3DMATRIX _                              ' __in CONST D3DXMATRIX *pM
 , BYVAL n AS DWORD _                                   ' __in UINT n
 ) AS DWORD                                             ' D3DXVECTOR3

'// Project vector from object space into screen space

DECLARE FUNCTION D3DXVec3Project IMPORT $D3DX_DLLNAME ALIAS "D3DXVec3Project" (_
   BYREF pOut AS D3DXVECTOR3 _                          ' __in_out D3DXVECTOR3 *pOut
 , BYREF pV AS D3DXVECTOR3 _                            ' __in CONST D3DXVECTOR3 *pV
 , BYREF pViewport AS D3DVIEWPORT9 _                    ' __in CONST D3DVIEWPORT9 *pViewport
 , BYREF pProjection AS D3DMATRIX _                     ' __in CONST D3DXMATRIX *pProjection
 , BYREF pView AS D3DMATRIX _                           ' __in CONST D3DXMATRIX *pView
 , BYREF pWorld AS D3DMATRIX _                          ' __in CONST D3DXMATRIX *pWorld
 ) AS DWORD                                             ' D3DXVECTOR3

'// Project vector from screen space into object space

DECLARE FUNCTION D3DXVec3Unproject IMPORT $D3DX_DLLNAME ALIAS "D3DXVec3Uproject" (_
   BYREF pOut AS D3DXVECTOR3 _                          ' __in_out D3DXVECTOR3 *pOut
 , BYREF pV AS D3DXVECTOR3 _                            ' __in CONST D3DXVECTOR3 *pV
 , BYREF pViewport AS D3DVIEWPORT9 _                    ' __in CONST D3DVIEWPORT9 *pViewport
 , BYREF pProjection AS D3DMATRIX _                     ' __in CONST D3DXMATRIX *pProjection
 , BYREF pView AS D3DMATRIX _                           ' __in CONST D3DXMATRIX *pView
 , BYREF pWorld AS D3DMATRIX _                          ' __in CONST D3DXMATRIX *pWorld
 ) AS DWORD                                             ' D3DXVECTOR3

'// Project vector Array from object space into screen space

DECLARE FUNCTION D3DXVec3ProjectArray IMPORT $D3DX_DLLNAME ALIAS "D3DXVec3ProjectArray" (_
   BYREF pOut AS D3DXVECTOR3 _                          ' __in_out D3DXVECTOR3 *pOut
 , BYVAL OutStride AS DWORD _                           ' __in UINT OutStride
 , BYREF pV AS D3DXVECTOR3 _                            ' __in CONST D3DXVECTOR3 *pV
 , BYVAL VStride AS DWORD _                             ' __in UINT VStride
 , BYREF pViewport AS D3DVIEWPORT9 _                    ' __in CONST D3DVIEWPORT9 *pViewport
 , BYREF pProjection AS D3DMATRIX _                     ' __in CONST D3DXMATRIX *pProjection
 , BYREF pView AS D3DMATRIX _                           ' __in CONST D3DXMATRIX *pView
 , BYREF pWorld AS D3DMATRIX _                          ' __in CONST D3DXMATRIX *pWorld
 , BYVAL n AS DWORD _                                   ' __in UINT n
 ) AS DWORD                                             ' D3DXVECTOR3

'// Project vector Array from screen space into object space

DECLARE FUNCTION D3DXVec3UnprojectArray IMPORT $D3DX_DLLNAME ALIAS "D3DXVec3UprojectArray" (_
   BYREF pOut AS D3DXVECTOR3 _                          ' __in_out D3DXVECTOR3 *pOut
 , BYVAL OutStride AS DWORD _                           ' __in UINT OutStride
 , BYREF pV AS D3DXVECTOR3 _                            ' __in CONST D3DXVECTOR3 *pV
 , BYVAL VStride AS DWORD _                             ' __in UINT VStride
 , BYREF pViewport AS D3DVIEWPORT9 _                    ' __in CONST D3DVIEWPORT9 *pViewport
 , BYREF pProjection AS D3DMATRIX _                     ' __in CONST D3DXMATRIX *pProjection
 , BYREF pView AS D3DMATRIX _                           ' __in CONST D3DXMATRIX *pView
 , BYREF pWorld AS D3DMATRIX _                          ' __in CONST D3DXMATRIX *pWorld
 , BYVAL n AS DWORD _                                   ' __in UINT n
 ) AS DWORD                                             ' D3DXVECTOR3


'//--------------------------
'// 4D Vector
'//--------------------------

'// Cross-product in 4 dimensions.

DECLARE FUNCTION D3DXVec4Cross IMPORT $D3DX_DLLNAME ALIAS "D3DXVec4Cross" (_
   BYREF pOut AS D3DXVECTOR4 _                          ' __in_out D3DXVECTOR4 *pOut
 , BYREF pV1 AS D3DXVECTOR4 _                           ' __in CONST D3DXVECTOR4 *pV1
 , BYREF pV2 AS D3DXVECTOR4 _                           ' __in CONST D3DXVECTOR4 *pV2
 , BYREF pV3 AS D3DXVECTOR4 _                           ' __in CONST D3DXVECTOR4 *pV3
 ) AS DWORD                                             ' D3DXVECTOR4

DECLARE FUNCTION D3DXVec4Normalize IMPORT $D3DX_DLLNAME ALIAS "D3DXVec4Normalize" (_
   BYREF pOut AS D3DXVECTOR4 _                          ' __in_out D3DXVECTOR4 *pOut
 , BYREF pV AS D3DXVECTOR4 _                            ' __in CONST D3DXVECTOR4 *pV
 ) AS DWORD                                             ' D3DXVECTOR4

'// Hermite interpolation between position V1, tangent T1 (when s == 0)
'// and position V2, tangent T2 (when s == 1).

DECLARE FUNCTION D3DXVec4Hermite IMPORT $D3DX_DLLNAME ALIAS "D3DXVec4Hermite" (_
   BYREF pOut AS D3DXVECTOR4 _                          ' __in_out D3DXVECTOR4 *pOut
 , BYREF pV1 AS D3DXVECTOR4 _                           ' __in CONST D3DXVECTOR4 *pV1
 , BYREF pT1 AS D3DXVECTOR4 _                           ' __in CONST D3DXVECTOR4 *pT1
 , BYREF pV2 AS D3DXVECTOR4 _                           ' __in CONST D3DXVECTOR4 *pV2
 , BYREF pT2 AS D3DXVECTOR4 _                           ' __in CONST D3DXVECTOR4 *pT2
 , BYVAL s AS SINGLE _                                  ' __in FLOAT s
 ) AS DWORD                                             ' D3DXVECTOR4

'// CatmullRom interpolation between V1 (when s == 0) and V2 (when s == 1)

DECLARE FUNCTION D3DXVec4CatmullRom IMPORT $D3DX_DLLNAME ALIAS "D3DXVec4CatmullRom" (_
   BYREF pOut AS D3DXVECTOR4 _                          ' __in_out D3DXVECTOR4 *pOut
 , BYREF pV0 AS D3DXVECTOR4 _                           ' __in CONST D3DXVECTOR4 *pV0
 , BYREF pV1 AS D3DXVECTOR4 _                           ' __in CONST D3DXVECTOR4 *pV1
 , BYREF pV2 AS D3DXVECTOR4 _                           ' __in CONST D3DXVECTOR4 *pV2
 , BYREF pV3 AS D3DXVECTOR4 _                           ' __in CONST D3DXVECTOR4 *pV3
 , BYVAL s AS SINGLE _                                  ' __in FLOAT s
 ) AS DWORD                                             ' D3DXVECTOR4

'// Barycentric coordinates.  V1 + f(V2-V1) + g(V3-V1)

DECLARE FUNCTION D3DXVec4BaryCentric IMPORT $D3DX_DLLNAME ALIAS "D3DXVec4BaryCentric" (_
   BYREF pOut AS D3DXVECTOR4 _                          ' __in_out D3DXVECTOR4 *pOut
 , BYREF pV1 AS D3DXVECTOR4 _                           ' __in CONST D3DXVECTOR4 *pV1
 , BYREF pV2 AS D3DXVECTOR4 _                           ' __in CONST D3DXVECTOR4 *pV2
 , BYREF pV3 AS D3DXVECTOR4 _                           ' __in CONST D3DXVECTOR4 *pV3
 , BYVAL f AS SINGLE _                                  ' __in FLOAT f
 , BYVAL s AS SINGLE _                                  ' __in FLOAT s
 ) AS DWORD                                             ' D3DXVECTOR4

'// Transform vector by matrix.

DECLARE FUNCTION D3DXVec4Transform IMPORT $D3DX_DLLNAME ALIAS "D3DXVec4Transform" (_
   BYREF pOut AS D3DXVECTOR4 _                          ' __in_out D3DXVECTOR4 *pOut
 , BYREF pV AS D3DXVECTOR4 _                            ' __in CONST D3DXVECTOR4 *pV
 , BYREF pM AS D3DMATRIX _                              ' __in CONST D3DXMATRIX *pM
 ) AS DWORD                                             ' D3DXVECTOR4

'// Transform vector array by matrix.

DECLARE FUNCTION D3DXVec4TransformArray IMPORT $D3DX_DLLNAME ALIAS "D3DXVec4TransformArray" (_
   BYREF pOut AS D3DXVECTOR4 _                          ' __in_out D3DXVECTOR4 *pOut
 , BYVAL OutStride AS DWORD _                           ' __in UINT OutStride
 , BYREF pV AS D3DXVECTOR4 _                            ' __in CONST D3DXVECTOR4 *pV
 , BYVAL VStride AS DWORD _                             ' __in UINT VStride
 , BYREF pM AS D3DMATRIX _                              ' __in CONST D3DXMATRIX *pM
 , BYVAL n AS DWORD _                                   ' __in UINT n
 ) AS DWORD                                             ' D3DXVECTOR4


'//--------------------------
'// 4D Matrix
'//--------------------------

DECLARE FUNCTION D3DXMatrixDeterminant IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixDeterminant" (_
   BYREF pM AS D3DMATRIX _                              ' __in CONST D3DXMATRIX *pM
 ) AS SINGLE                                            ' FLOAT

DECLARE FUNCTION D3DXMatrixDecompose IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixDecompose" (_
   BYREF pOutScale AS D3DXVECTOR3 _                     ' __in_out D3DXVECTOR3 *pOutScale
 , BYREF pOutRotation AS D3DXQUATERNION _               ' __in D3DXQUATERNION *pOutRotation
 , BYREF pOutTranslation AS D3DXVECTOR3 _               ' __in D3DXVECTOR3 *pOutTranslation
 , BYREF pM AS D3DMATRIX _                              ' __in CONST D3DXMATRIX *pM
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXMatrixTranspose IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixTranspose" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYREF pM AS D3DMATRIX _                              ' __in CONST D3DXMATRIX *pM
 ) AS DWORD                                             ' D3DXMATRIX

'// Matrix multiplication.  The result represents the transformation M2
'// followed by the transformation M1.  (Out = M1 * M2)

DECLARE FUNCTION D3DXMatrixMultiply IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixMultiply" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYREF pM1 AS D3DMATRIX _                             ' __in CONST D3DXMATRIX *pM1
 , BYREF pM2 AS D3DMATRIX _                             ' __in CONST D3DXMATRIX *pM2
 ) AS DWORD                                             ' D3DXMATRIX

'// Matrix multiplication, followed by a transpose. (Out = T(M1 * M2))

DECLARE FUNCTION D3DXMatrixMultiplyTranspose IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixMultiplyTranspose" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYREF pM1 AS D3DMATRIX _                             ' __in CONST D3DXMATRIX *pM1
 , BYREF pM2 AS D3DMATRIX _                             ' __in CONST D3DXMATRIX *pM2
 ) AS DWORD                                             ' D3DXMATRIX

'// Calculate inverse of matrix.  Inversion my fail, in which case NULL will
'// be returned.  The determinant of pM is also returned it pfDeterminant
'// is non-NULL.

DECLARE FUNCTION D3DXMatrixInverse IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixInverse" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYREF pDeterminant AS SINGLE _                       ' __in FLOAT *pDeterminant
 , BYREF pM AS D3DMATRIX _                              ' __in CONST D3DXMATRIX *pM
 ) AS DWORD                                             ' D3DXMATRIX

'// Build a matrix which scales by (sx, sy, sz)

DECLARE FUNCTION D3DXMatrixScaling IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixScaling" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYVAL sx AS SINGLE _                                 ' __in FLOAT sx
 , BYVAL sy AS SINGLE _                                 ' __in FLOAT sy
 , BYVAL sz AS SINGLE _                                 ' __in FLOAT sz
 ) AS DWORD                                             ' D3DXMATRIX

'// Build a matrix which translates by (x, y, z)

DECLARE FUNCTION D3DXMatrixTranslation IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixTranslation" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYVAL x AS SINGLE _                                  ' __in FLOAT x
 , BYVAL y AS SINGLE _                                  ' __in FLOAT y
 , BYVAL z AS SINGLE _                                  ' __in FLOAT z
 ) AS DWORD                                             ' D3DXMATRIX

'// Build a matrix which rotates around the X axis

DECLARE FUNCTION D3DXMatrixRotationX IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixRotationX" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYVAL Angle AS SINGLE _                              ' __in FLOAT Angle
 ) AS DWORD                                             ' D3DXMATRIX

'// Build a matrix which rotates around the Y axis

DECLARE FUNCTION D3DXMatrixRotationY IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixRotationY" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYVAL Angle AS SINGLE _                              ' __in FLOAT Angle
 ) AS DWORD                                             ' D3DXMATRIX

'// Build a matrix which rotates around the Z axis

DECLARE FUNCTION D3DXMatrixRotationZ IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixRotationZ" (_
   BYREF pOut AS D3DMATRIX _                            ' D3DXMATRIX *pOut
 , BYVAL Angle AS SINGLE _                              ' FLOAT Angle
 ) AS DWORD                                             ' D3DXMATRIX

'// Build a matrix which rotates around an arbitrary axis

DECLARE FUNCTION D3DXMatrixRotationAxis IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixRotationAxis" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYREF pV AS D3DXVECTOR3 _                            ' __in CONST D3DXVECTOR3 *pV
 , BYVAL Angle AS SINGLE _                              ' __in FLOAT Angle
 ) AS DWORD                                             ' D3DXMATRIX

'// Build a matrix from a quaternion

DECLARE FUNCTION D3DXMatrixRotationQuaternion IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixRotationQuaternion" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYREF pQ AS D3DXQUATERNION _                         ' __in CONST D3DXQUATERNION *pQ
 ) AS DWORD                                             ' D3DXMATRIX

'// Yaw around the Y axis, a pitch around the X axis,
'// and a roll around the Z axis.

DECLARE FUNCTION D3DXMatrixRotationYawPitchRoll IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixRotationYawPitchRoll" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYVAL Yaw AS SINGLE _                                ' __in FLOAT Yaw
 , BYVAL Pitch AS SINGLE _                              ' __in FLOAT Pitch
 , BYVAL Roll AS SINGLE _                               ' __in FLOAT Roll
 ) AS DWORD                                             ' D3DXMATRIX

'// Build transformation matrix.  NULL arguments are treated as identity.
'// Mout = Msc-1 * Msr-1 * Ms * Msr * Msc * Mrc-1 * Mr * Mrc * Mt

DECLARE FUNCTION D3DXMatrixTransformation IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixTransformation" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYREF pScalingCenter AS D3DXVECTOR3 _                ' __in CONST D3DXVECTOR3 *pScalingCenter
 , BYREF pScalingRotation AS D3DXQUATERNION _           ' __in CONST D3DXQUATERNION *pScalingRotation
 , BYREF pScaling AS D3DXVECTOR3 _                      ' __in CONST D3DXVECTOR3 *pScaling
 , BYREF pRotationCenter AS D3DXVECTOR3 _               ' __in CONST D3DXVECTOR3 *pRotationCenter
 , BYREF pRotation AS D3DXQUATERNION _                  ' __in CONST D3DXQUATERNION *pRotation
 , BYREF pTranslation AS D3DXVECTOR3 _                  ' __in CONST D3DXVECTOR3 *pTranslation
 ) AS DWORD                                             ' D3DXMATRIX

'// Build 2D transformation matrix in XY plane.  NULL arguments are treated as identity.
'// Mout = Msc-1 * Msr-1 * Ms * Msr * Msc * Mrc-1 * Mr * Mrc * Mt

DECLARE FUNCTION D3DXMatrixTransformation2D IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixTransformation2D" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYREF pScalingCenter AS D3DXVECTOR2 _                ' __in CONST D3DXVECTOR2* pScalingCenter
 , BYVAL ScalingRotation AS SINGLE _                    ' __in FLOAT ScalingRotation
 , BYREF pScaling AS D3DXVECTOR2 _                      ' __in CONST D3DXVECTOR2* pScaling
 , BYREF pRotationCenter AS D3DXVECTOR2 _               ' __in CONST D3DXVECTOR2* pRotationCenter
 , BYVAL Rotation AS SINGLE _                           ' __in FLOAT Rotation
 , BYREF pTranslation AS D3DXVECTOR2 _                  ' __in CONST D3DXVECTOR2* pTranslation
 ) AS DWORD                                             ' D3DXMATRIX

'// Build affine transformation matrix.  NULL arguments are treated as identity.
'// Mout = Ms * Mrc-1 * Mr * Mrc * Mt

DECLARE FUNCTION D3DXMatrixAffineTransformation IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixAffineTransformation" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYVAL Scaling AS SINGLE _                            ' __in FLOAT Scaling
 , BYREF pRotationCenter AS D3DXVECTOR3 _               ' __in CONST D3DXVECTOR3 *pRotationCenter
 , BYREF pRotation AS D3DXQUATERNION _                  ' __in CONST D3DXQUATERNION *pRotation
 , BYREF pTranslation AS D3DXVECTOR3 _                  ' __in CONST D3DXVECTOR3 *pTranslation
 ) AS DWORD                                             ' D3DXMATRIX

'// Build 2D affine transformation matrix in XY plane.  NULL arguments are treated as identity.
'// Mout = Ms * Mrc-1 * Mr * Mrc * Mt

DECLARE FUNCTION D3DXMatrixAffineTransformation2D IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixAffineTransformation2D" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYVAL Scaling AS SINGLE _                            ' __in FLOAT Scaling
 , BYREF pRotationCenter AS D3DXVECTOR2 _               ' __in CONST D3DXVECTOR2* pRotationCenter
 , BYVAL Rotation AS SINGLE _                           ' __in FLOAT Rotation
 , BYREF pTranslation AS D3DXVECTOR2 _                  ' __in CONST D3DXVECTOR2* pTranslation
 ) AS DWORD                                             ' D3DXMATRIX

'// Build a lookat matrix. (right-handed)

DECLARE FUNCTION D3DXMatrixLookAtRH IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixLookAtRH" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYREF pEye AS D3DXVECTOR3 _                          ' __in CONST D3DXVECTOR3 *pEye
 , BYREF pAt AS D3DXVECTOR3 _                           ' __in CONST D3DXVECTOR3 *pAt
 , BYREF pUp AS D3DXVECTOR3 _                           ' __in CONST D3DXVECTOR3 *pUp
 ) AS DWORD                                             ' D3DXMATRIX

'// Build a lookat matrix. (left-handed)

DECLARE FUNCTION D3DXMatrixLookAtLH IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixLookAtLH" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYREF pEye AS D3DXVECTOR3 _                          ' __in CONST D3DXVECTOR3 *pEye
 , BYREF pAt AS D3DXVECTOR3 _                           ' __in CONST D3DXVECTOR3 *pAt
 , BYREF pUp AS D3DXVECTOR3 _                           ' __in CONST D3DXVECTOR3 *pUp
 ) AS DWORD                                             ' D3DXMATRIX

'// Build a perspective projection matrix. (right-handed)

DECLARE FUNCTION D3DXMatrixPerspectiveRH IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixPerspectiveRH" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYVAL w AS SINGLE _                                  ' __in FLOAT w
 , BYVAL h AS SINGLE _                                  ' __in FLOAT h
 , BYVAL zn AS SINGLE _                                 ' __in FLOAT zn
 , BYVAL zf AS SINGLE _                                 ' __in FLOAT zf
 ) AS DWORD                                             ' D3DXMATRIX

'// Build a perspective projection matrix. (left-handed)

DECLARE FUNCTION D3DXMatrixPerspectiveLH IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixPerspectiveLH" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYVAL w AS SINGLE _                                  ' __in FLOAT w
 , BYVAL h AS SINGLE _                                  ' __in FLOAT h
 , BYVAL zn AS SINGLE _                                 ' __in FLOAT zn
 , BYVAL zf AS SINGLE _                                 ' __in FLOAT zf
 ) AS DWORD                                             ' D3DXMATRIX

'// Build a perspective projection matrix. (right-handed)

DECLARE FUNCTION D3DXMatrixPerspectiveFovRH IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixPerspectiveFovRH" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYVAL fovy AS SINGLE _                               ' __in FLOAT fovy
 , BYVAL Aspect AS SINGLE _                             ' __in FLOAT Aspect
 , BYVAL zn AS SINGLE _                                 ' __in FLOAT zn
 , BYVAL zf AS SINGLE _                                 ' __in FLOAT zf
 ) AS DWORD                                             ' D3DXMATRIX

'// Build a perspective projection matrix. (left-handed)

DECLARE FUNCTION D3DXMatrixPerspectiveFovLH IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixPerspectiveFovLH" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYVAL fovy AS SINGLE _                               ' __in FLOAT fovy
 , BYVAL Aspect AS SINGLE _                             ' __in FLOAT Aspect
 , BYVAL zn AS SINGLE _                                 ' __in FLOAT zn
 , BYVAL zf AS SINGLE _                                 ' __in FLOAT zf
 ) AS DWORD                                             ' D3DXMATRIX

'// Build a perspective projection matrix. (right-handed)

DECLARE FUNCTION D3DXMatrixPerspectiveOffCenterRH IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixPerspectiveOffCenterRH" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYVAL l AS SINGLE _                                  ' __in FLOAT l
 , BYVAL r AS SINGLE _                                  ' __in FLOAT r
 , BYVAL b AS SINGLE _                                  ' __in FLOAT b
 , BYVAL t AS SINGLE _                                  ' __in FLOAT t
 , BYVAL zn AS SINGLE _                                 ' __in FLOAT zn
 , BYVAL zf AS SINGLE _                                 ' __in FLOAT zf
 ) AS DWORD                                             ' D3DXMATRIX

'// Build a perspective projection matrix. (left-handed)

DECLARE FUNCTION D3DXMatrixPerspectiveOffCenterLH IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixPerspectiveOffCenterLH" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYVAL l AS SINGLE _                                  ' __in FLOAT l
 , BYVAL r AS SINGLE _                                  ' __in FLOAT r
 , BYVAL b AS SINGLE _                                  ' __in FLOAT b
 , BYVAL t AS SINGLE _                                  ' __in FLOAT t
 , BYVAL zn AS SINGLE _                                 ' __in FLOAT zn
 , BYVAL zf AS SINGLE _                                 ' __in FLOAT zf
 ) AS DWORD                                             ' D3DXMATRIX

'// Build an ortho projection matrix. (right-handed)

DECLARE FUNCTION D3DXMatrixOrthoRH IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixOrthoRH" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYVAL w AS SINGLE _                                  ' __in FLOAT w
 , BYVAL h AS SINGLE _                                  ' __in FLOAT h
 , BYVAL zn AS SINGLE _                                 ' __in FLOAT zn
 , BYVAL zf AS SINGLE _                                 ' __in FLOAT zf
 ) AS DWORD                                             ' D3DXMATRIX

'// Build an ortho projection matrix. (left-handed)

DECLARE FUNCTION D3DXMatrixOrthoLH IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixOrthoLH" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYVAL w AS SINGLE _                                  ' __in FLOAT w
 , BYVAL h AS SINGLE _                                  ' __in FLOAT h
 , BYVAL zn AS SINGLE _                                 ' __in FLOAT zn
 , BYVAL zf AS SINGLE _                                 ' __in FLOAT zf
 ) AS DWORD                                             ' D3DXMATRIX

'// Build an ortho projection matrix. (right-handed)

DECLARE FUNCTION D3DXMatrixOrthoOffCenterRH IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixOrthoOffCenterRH" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYVAL l AS SINGLE _                                  ' __in FLOAT l
 , BYVAL r AS SINGLE _                                  ' __in FLOAT r
 , BYVAL b AS SINGLE _                                  ' __in FLOAT b
 , BYVAL t AS SINGLE _                                  ' __in FLOAT t
 , BYVAL zn AS SINGLE _                                 ' __in FLOAT zn
 , BYVAL zf AS SINGLE _                                 ' __in FLOAT zf
 ) AS DWORD                                             ' D3DXMATRIX

'// Build an ortho projection matrix. (left-handed)

DECLARE FUNCTION D3DXMatrixOrthoOffCenterLH IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixOrthoOffCenterLH" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYVAL l AS SINGLE _                                  ' __in FLOAT l
 , BYVAL r AS SINGLE _                                  ' __in FLOAT r
 , BYVAL b AS SINGLE _                                  ' __in FLOAT b
 , BYVAL t AS SINGLE _                                  ' __in FLOAT t
 , BYVAL zn AS SINGLE _                                 ' __in FLOAT zn
 , BYVAL zf AS SINGLE _                                 ' __in FLOAT zf
 ) AS DWORD                                             ' D3DXMATRIX

'// Build a matrix which flattens geometry into a plane, as if casting
'// a shadow from a light.

DECLARE FUNCTION D3DXMatrixShadow IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixShadow" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYREF pLight AS D3DXVECTOR4 _                        ' __in CONST D3DXVECTOR4 *pLight
 , BYREF pPlane AS D3DXPLANE _                          ' __in CONST D3DXPLANE *pPlane
 ) AS DWORD                                             ' D3DXMATRIX

'// Build a matrix which reflects the coordinate system about a plane

DECLARE FUNCTION D3DXMatrixReflect IMPORT $D3DX_DLLNAME ALIAS "D3DXMatrixReflect" (_
   BYREF pOut AS D3DMATRIX _                            ' __in_out D3DXMATRIX *pOut
 , BYREF pPlane AS D3DXPLANE _                          ' __in CONST D3DXPLANE *pPlane
 ) AS DWORD                                             ' D3DXMATRIX


'//--------------------------
'// Quaternion
'//--------------------------

'// Compute a quaternin's axis and angle of rotation. Expects unit quaternions.
DECLARE SUB D3DXQuaternionToAxisAngle IMPORT $D3DX_DLLNAME ALIAS "D3DXQuaternionToAxisAngle" (_
   BYREF pQ AS D3DXQUATERNION _                         ' __in CONST D3DXQUATERNION *pQ
 , BYREF pAxis AS D3DXVECTOR3 _                         ' __in_out D3DXVECTOR3 *pAxis
 , BYREF pAngle AS SINGLE _                             ' __in_out FLOAT *pAngle
 )                                                      ' void

'// Build a quaternion from a rotation matrix.

DECLARE FUNCTION D3DXQuaternionRotationMatrix IMPORT $D3DX_DLLNAME ALIAS "D3DXQuaternionRotationMatrix" (_
   BYREF pOut AS D3DXQUATERNION _                       ' __in_out D3DXQUATERNION *pOut
 , BYREF pM AS D3DMATRIX _                              ' __in CONST D3DXMATRIX *pM
 ) AS DWORD                                             ' D3DXQUATERNION

'// Rotation about arbitrary axis.

DECLARE FUNCTION D3DXQuaternionRotationAxis IMPORT $D3DX_DLLNAME ALIAS "D3DXQuaternionRotationAxis" (_
   BYREF pOut AS D3DXQUATERNION _                       ' __in_out D3DXQUATERNION *pOut
 , BYREF pV AS D3DXVECTOR3 _                            ' __in CONST D3DXVECTOR3 *pV
 , BYVAL Angle AS SINGLE _                              ' __in FLOAT Angle
 ) AS DWORD                                             ' D3DXQUATERNION

'// Yaw around the Y axis, a pitch around the X axis,
'// and a roll around the Z axis.

DECLARE FUNCTION D3DXQuaternionRotationYawPitchRoll IMPORT $D3DX_DLLNAME ALIAS "D3DXQuaternionRotationYawPitchRoll" (_
   BYREF pOut AS D3DXQUATERNION _                       ' __in_out D3DXQUATERNION *pOut
 , BYVAL Yaw AS SINGLE _                                ' __in FLOAT Yaw
 , BYVAL Pitch AS SINGLE _                              ' __in FLOAT Pitch
 , BYVAL Roll AS SINGLE _                               ' __in FLOAT Roll
 ) AS DWORD                                             ' D3DXQUATERNION

'// Quaternion multiplication.  The result represents the rotation Q2
'// followed by the rotation Q1.  (Out = Q2 * Q1)

DECLARE FUNCTION D3DXQuaternionMultiply IMPORT $D3DX_DLLNAME ALIAS "D3DXQuaternionMultiply" (_
   BYREF pOut AS D3DXQUATERNION _                       ' __in_out D3DXQUATERNION *pOut
 , BYREF pQ1 AS D3DXQUATERNION _                        ' __in CONST D3DXQUATERNION *pQ1
 , BYREF pQ2 AS D3DXQUATERNION _                        ' __in CONST D3DXQUATERNION *pQ2
 ) AS DWORD                                             ' D3DXQUATERNION

DECLARE FUNCTION D3DXQuaternionNormalize IMPORT $D3DX_DLLNAME ALIAS "D3DXQuaternionNormalize" (_
   BYREF pOut AS D3DXQUATERNION _                       ' __in_out D3DXQUATERNION *pOut
 , BYREF pQ AS D3DXQUATERNION _                         ' __in CONST D3DXQUATERNION *pQ
 ) AS DWORD                                             ' D3DXQUATERNION

'// Conjugate and re-norm

DECLARE FUNCTION D3DXQuaternionInverse IMPORT $D3DX_DLLNAME ALIAS "D3DXQuaternionInverse" (_
   BYREF pOut AS D3DXQUATERNION _                       ' __in_out D3DXQUATERNION *pOut
 , BYREF pQ AS D3DXQUATERNION _                         ' __in CONST D3DXQUATERNION *pQ
 ) AS DWORD                                             ' D3DXQUATERNION

'// Expects unit quaternions.
'// if q = (cos(theta), sin(theta) * v); ln(q) = (0, theta * v)

DECLARE FUNCTION D3DXQuaternionLn IMPORT $D3DX_DLLNAME ALIAS "D3DXQuaternionLn" (_
   BYREF pOut AS D3DXQUATERNION _                       ' __in_out D3DXQUATERNION *pOut
 , BYREF pQ AS D3DXQUATERNION _                         ' __in CONST D3DXQUATERNION *pQ
 ) AS DWORD                                             ' D3DXQUATERNION

'// Expects pure quaternions. (w == 0)  w is ignored in calculation.
'// if q = (0, theta * v); exp(q) = (cos(theta), sin(theta) * v)

DECLARE FUNCTION D3DXQuaternionExp IMPORT $D3DX_DLLNAME ALIAS "D3DXQuaternionExp" (_
   BYREF pOut AS D3DXQUATERNION _                       ' __in_out D3DXQUATERNION *pOut
 , BYREF pQ AS D3DXQUATERNION _                         ' __in CONST D3DXQUATERNION *pQ
 ) AS DWORD                                             ' D3DXQUATERNION

'// Spherical linear interpolation between Q1 (t == 0) and Q2 (t == 1).
'// Expects unit quaternions.

DECLARE FUNCTION D3DXQuaternionSlerp IMPORT $D3DX_DLLNAME ALIAS "D3DXQuaternionSlerp" (_
   BYREF pOut AS D3DXQUATERNION _                       ' __in_out D3DXQUATERNION *pOut
 , BYREF pQ1 AS D3DXQUATERNION _                        ' __in CONST D3DXQUATERNION *pQ1
 , BYREF pQ2 AS D3DXQUATERNION _                        ' __in CONST D3DXQUATERNION *pQ2
 , BYVAL t AS SINGLE _                                  ' __in FLOAT t
 ) AS DWORD                                             ' D3DXQUATERNION

'// Spherical quadrangle interpolation.
'// Slerp(Slerp(Q1, C, t), Slerp(A, B, t), 2t(1-t))

DECLARE FUNCTION D3DXQuaternionSquad IMPORT $D3DX_DLLNAME ALIAS "D3DXQuaternionSquad" (_
   BYREF pOut AS D3DXQUATERNION _                       ' __in_out D3DXQUATERNION *pOut
 , BYREF pQ1 AS D3DXQUATERNION _                        ' __in CONST D3DXQUATERNION *pQ1
 , BYREF pA AS D3DXQUATERNION _                         ' __in CONST D3DXQUATERNION *pA
 , BYREF pB AS D3DXQUATERNION _                         ' __in CONST D3DXQUATERNION *pB
 , BYREF pC AS D3DXQUATERNION _                         ' __in CONST D3DXQUATERNION *pC
 , BYVAL t AS SINGLE _                                  ' __in FLOAT t
 ) AS DWORD                                             ' D3DXQUATERNION


'// Setup control points for spherical quadrangle interpolation
'// from Q1 to Q2.  The control points are chosen in such a way
'// to ensure the continuity of tangents with adjacent segments.

DECLARE SUB D3DXQuaternionSquadSetup IMPORT $D3DX_DLLNAME ALIAS "D3DXQuaternionSquadSetup" (_
   BYREF pAOut AS D3DXQUATERNION _                      ' __out D3DXQUATERNION *pAOut
 , BYREF pBOut AS D3DXQUATERNION _                      ' __out D3DXQUATERNION *pBOut
 , BYREF pCOut AS D3DXQUATERNION _                      ' __out D3DXQUATERNION *pCOut
 , BYREF pQ0 AS D3DXQUATERNION _                        ' __in  D3DXQUATERNION *pQ0
 , BYREF pQ1 AS D3DXQUATERNION _                        ' __in  D3DXQUATERNION *pQ1
 , BYREF pQ2 AS D3DXQUATERNION _                        ' __in  D3DXQUATERNION *pQ2
 , BYREF pQ3 AS D3DXQUATERNION _                        ' __in  D3DXQUATERNION *pQ3
 )                                                      ' void

'// Barycentric interpolation.
'// Slerp(Slerp(Q1, Q2, f+g), Slerp(Q1, Q3, f+g), g/(f+g))

DECLARE FUNCTION D3DXQuaternionBaryCentric IMPORT $D3DX_DLLNAME ALIAS "D3DXQuaternionBaryCentric" (_
   BYREF pOut AS D3DXQUATERNION _                       ' __in_out D3DXQUATERNION *pOut
 , BYREF pQ1 AS D3DXQUATERNION _                        ' __in CONST D3DXQUATERNION *pQ1
 , BYREF pQ2 AS D3DXQUATERNION _                        ' __in CONST D3DXQUATERNION *pQ2
 , BYREF pQ3 AS D3DXQUATERNION _                        ' __in CONST D3DXQUATERNION *pQ3
 , BYVAL f AS SINGLE _                                  ' __in FLOAT f
 , BYVAL g AS SINGLE _                                  ' __in FLOAT g
 ) AS DWORD                                             ' D3DXQUATERNION


'//--------------------------
'// Plane
'//--------------------------

'// Normalize plane (so that |a,b,c| == 1)

DECLARE FUNCTION D3DXPlaneNormalize IMPORT $D3DX_DLLNAME ALIAS "D3DXPlaneNormalize" (_
   BYREF pOut AS D3DXPLANE _                            ' __in_out D3DXPLANE *pOut
 , BYREF pP AS D3DXPLANE _                              ' __in CONST D3DXPLANE *pP
 ) AS DWORD                                             ' D3DXPLANE

'// Find the intersection between a plane and a line.  If the line is
'// parallel to the plane, NULL is returned.

DECLARE FUNCTION D3DXPlaneIntersectLine IMPORT $D3DX_DLLNAME ALIAS "D3DXPlaneIntersectLine" (_
   BYREF pOut AS D3DXVECTOR3 _                          ' __in_out D3DXVECTOR3 *pOut
 , BYREF pP AS D3DXPLANE _                              ' __in CONST D3DXPLANE *pP
 , BYREF pV1 AS D3DXVECTOR3 _                           ' __in CONST D3DXVECTOR3 *pV1
 , BYREF pV2 AS D3DXVECTOR3 _                           ' __in CONST D3DXVECTOR3 *pV2
 ) AS DWORD                                             ' D3DXVECTOR3

'// Construct a plane from a point and a normal

DECLARE FUNCTION D3DXPlaneFromPointNormal IMPORT $D3DX_DLLNAME ALIAS "D3DXPlaneFromPointNormal" (_
   BYREF pOut AS D3DXPLANE _                            ' __in_out D3DXPLANE *pOut
 , BYREF pPoint AS D3DXVECTOR3 _                        ' __in CONST D3DXVECTOR3 *pPoint
 , BYREF pNormal AS D3DXVECTOR3 _                       ' __in CONST D3DXVECTOR3 *pNormal
 ) AS DWORD                                             ' D3DXPLANE

'// Construct a plane from 3 points

DECLARE FUNCTION D3DXPlaneFromPoints IMPORT $D3DX_DLLNAME ALIAS "D3DXPlaneFromPoints" (_
   BYREF pOut AS D3DXPLANE _                            ' __in_out D3DXPLANE *pOut
 , BYREF pV1 AS D3DXVECTOR3 _                           ' __in CONST D3DXVECTOR3 *pV1
 , BYREF pV2 AS D3DXVECTOR3 _                           ' __in CONST D3DXVECTOR3 *pV2
 , BYREF pV3 AS D3DXVECTOR3 _                           ' __in CONST D3DXVECTOR3 *pV3
 ) AS DWORD                                             ' D3DXPLANE

'// Transform a plane by a matrix.  The vector (a,b,c) must be normal.
'// M should be the inverse transpose of the transformation desired.

DECLARE FUNCTION D3DXPlaneTransform IMPORT $D3DX_DLLNAME ALIAS "D3DXPlaneTransform" (_
   BYREF pOut AS D3DXPLANE _                            ' __in_out D3DXPLANE *pOut
 , BYREF pP AS D3DXPLANE _                              ' __in CONST D3DXPLANE *pP
 , BYREF pM AS D3DMATRIX _                              ' __in CONST D3DXMATRIX *pM
 ) AS DWORD                                             ' D3DXPLANE

'// Transform an array of planes by a matrix.  The vectors (a,b,c) must be normal.
'// M should be the inverse transpose of the transformation desired.

DECLARE FUNCTION D3DXPlaneTransformArray IMPORT $D3DX_DLLNAME ALIAS "D3DXPlaneTransformArray" (_
   BYREF pOut AS D3DXPLANE _                            ' __in_out D3DXPLANE *pOut
 , BYVAL OutStride AS DWORD _                           ' __in UINT OutStride
 , BYREF pP AS D3DXPLANE _                              ' __in CONST D3DXPLANE *pP
 , BYVAL PStride AS DWORD _                             ' __in UINT PStride
 , BYREF pM AS D3DMATRIX _                              ' __in CONST D3DXMATRIX *pM
 , BYVAL n AS DWORD _                                   ' __in UINT n
 ) AS DWORD                                             ' D3DXPLANE

'//--------------------------
'// Color
'//--------------------------

'// Interpolate r,g,b between desaturated color and color.
'// DesaturatedColor + s(Color - DesaturatedColor)

DECLARE FUNCTION D3DXColorAdjustSaturation IMPORT $D3DX_DLLNAME ALIAS "D3DXColorAdjustSaturation" (_
   BYREF pOut AS D3DXCOLOR _                            ' __in_out D3DXCOLOR *pOut
 , BYREF pC AS D3DXCOLOR _                              ' __in CONST D3DXCOLOR *pC
 , BYVAL s AS SINGLE _                                  ' __in FLOAT s
 ) AS DWORD                                             ' D3DXCOLOR

'// Interpolate r,g,b between 50% grey and color.  Grey + s(Color - Grey)

DECLARE FUNCTION D3DXColorAdjustContrast IMPORT $D3DX_DLLNAME ALIAS "D3DXColorAdjustContrast" (_
   BYREF pOut AS D3DXCOLOR _                            ' __in_out D3DXCOLOR *pOut
 , BYREF pC AS D3DXCOLOR _                              ' __in CONST D3DXCOLOR *pC
 , BYVAL s AS SINGLE _                                  ' __in FLOAT s
 ) AS DWORD                                             ' D3DXCOLOR


'//--------------------------
'// Misc
'//--------------------------

'// Calculate Fresnel term given the cosine of theta (likely obtained by
'// taking the dot of two normals), and the refraction index of the material.

DECLARE FUNCTION D3DXFresnelTerm IMPORT $D3DX_DLLNAME ALIAS "D3DXFresnelTerm" (_
   BYVAL CosTheta AS SINGLE _                           ' __in FLOAT CosTheta
 , BYVAL RefractionIndex AS SINGLE _                    ' __in FLOAT RefractionIndex
 ) AS SINGLE                                            ' FLOAT



'//===========================================================================
'//
'//    Matrix Stack
'//
'//===========================================================================

$IID_ID3DXMatrixStack = GUID$("{C7885BA7-F990-4fe7-922D-8515E477DD85}")

INTERFACE ID3DXMatrixStack $IID_ID3DXMatrixStack

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Pop ( _                                       ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Push ( _                                      ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadIdentity ( _                              ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadMatrix ( _                                ' VTable offset = 24
     BYREF pM AS D3DXMATRIX _                           ' __in CONST D3DXMATRIX* pM
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MultMatrix ( _                                ' VTable offset = 28
     BYREF pM AS D3DXMATRIX _                           ' __in CONST D3DXMATRIX* pM
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MultMatrixLocal ( _                           ' VTable offset = 32
     BYREF pM AS D3DXMATRIX _                           ' __in CONST D3DXMATRIX* pM
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RotateAxis ( _                                ' VTable offset = 36
     BYREF pV AS D3DXVECTOR3 _                          ' __in CONST D3DXVECTOR3* pV
   , BYVAL Angle AS SINGLE _                            ' __in FLOAT Angle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RotateAxisLocal ( _                           ' VTable offset = 40
     BYREF pV AS D3DXVECTOR3 _                          ' __in CONST D3DXVECTOR3* pV
   , BYVAL Angle AS SINGLE _                            ' __in FLOAT Angle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RotateYawPitchRoll ( _                        ' VTable offset = 44
     BYVAL Yaw AS SINGLE _                              ' __in FLOAT Yaw
   , BYVAL Pitch AS SINGLE _                            ' __in FLOAT Pitch
   , BYVAL Roll AS SINGLE _                             ' __in FLOAT Roll
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RotateYawPitchRollLocal ( _                   ' VTable offset = 48
     BYVAL Yaw AS SINGLE _                              ' __in FLOAT Yaw
   , BYVAL Pitch AS SINGLE _                            ' __in FLOAT Pitch
   , BYVAL Roll AS SINGLE _                             ' __in FLOAT Roll
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Scale ( _                                     ' VTable offset = 52
     BYVAL x AS SINGLE _                                ' __in FLOAT x
   , BYVAL y AS SINGLE _                                ' __in FLOAT y
   , BYVAL x AS SINGLE _                                ' __in FLOAT z
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ScaleLocal ( _                                ' VTable offset = 56
     BYVAL x AS SINGLE _                                ' __in FLOAT x
   , BYVAL y AS SINGLE _                                ' __in FLOAT y
   , BYVAL x AS SINGLE _                                ' __in FLOAT z
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Translate ( _                                 ' VTable offset = 60
     BYVAL x AS SINGLE _                                ' __in FLOAT x
   , BYVAL y AS SINGLE _                                ' __in FLOAT y
   , BYVAL x AS SINGLE _                                ' __in FLOAT z
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TranslateLocal ( _                            ' VTable offset = 64
     BYVAL x AS SINGLE _                                ' __in FLOAT x
   , BYVAL y AS SINGLE _                                ' __in FLOAT y
   , BYVAL x AS SINGLE _                                ' __in FLOAT z
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTop ( _                                    ' VTable offset = 68
   ) AS D3DXMATRIX                                      ' D3DXMATRIX
   ' =====================================================================================

END INTERFACE


DECLARE FUNCTION D3DXCreateMatrixStack IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateMatrixStack" (_
   BYVAL Flags AS DWORD _                               ' __in  DWORD               Flags
 , BYREF ppStack AS ID3DXMATRIXStack _                  ' __out LPD3DXMATRIXSTACK* ppStack
 ) AS LONG                                              ' HRESULT


'//===========================================================================
'//
'//  Spherical Harmonic Runtime Routines
'//
'// NOTE:
'//  * Most of these functions can take the same object as in and out parameters.
'//    The exceptions are the rotation functions.
'//
'//  * Out parameters are typically also returned as return values, so that
'//    the output of one function may be used as a parameter to another.
'//
'//============================================================================


'//============================================================================
'//
'//  Basic Spherical Harmonic math routines
'//
'//============================================================================

%D3DXSH_MINORDER = 2
%D3DXSH_MAXORDER = 6

'//============================================================================
'//
'//  D3DXSHEvalDirection:
'//  --------------------
'//  Evaluates the Spherical Harmonic basis functions
'//
'//  Parameters:
'//   pOut
'//      Output SH coefficients - basis function Ylm is stored at l*l + m+l
'//      This is the pointer that is returned.
'//   Order
'//      Order of the SH evaluation, generates Order^2 coefs, degree is Order-1
'//   pDir
'//      Direction to evaluate in - assumed to be normalized
'//
'//============================================================================

DECLARE FUNCTION D3DXSHEvalDirection IMPORT $D3DX_DLLNAME ALIAS "D3DXSHEvalDirection" (_
   BYREF pOut AS SINGLE _                               ' __out FLOAT *pOut
 , BYVAL Order AS DWORD _                               ' __in  UINT Order
 , BYREF pDir AS D3DXVECTOR3 _                          ' __in  CONST D3DXVECTOR3 *pDir
 ) AS SINGLE                                            ' FLOAT

'//============================================================================
'//
'//  D3DXSHRotate:
'//  --------------------
'//  Rotates SH vector by a rotation matrix
'//
'//  Parameters:
'//   pOut
'//      Output SH coefficients - basis function Ylm is stored at l*l + m+l
'//      This is the pointer that is returned (should not alias with pIn.)
'//   Order
'//      Order of the SH evaluation, generates Order^2 coefs, degree is Order-1
'//   pMatrix
'//      Matrix used for rotation - rotation sub matrix should be orthogonal
'//      and have a unit determinant.
'//   pIn
'//      Input SH coeffs (rotated), incorect results if this is also output.
'//
'//============================================================================

DECLARE FUNCTION D3DXSHRotate IMPORT $D3DX_DLLNAME ALIAS "D3DXSHRotate" (_
   BYREF pOut AS SINGLE _                               ' __out FLOAT *pOut
 , BYVAL Order AS DWORD _                               ' __in  UINT Order
 , BYREF pMatrix AS D3DMATRIX _                         ' __in  CONST D3DXMATRIX *pMatrix
 , BYREF pIn AS SINGLE _                                ' __in  CONST FLOAT *pIn
 ) AS SINGLE                                            ' FLOAT

'//============================================================================
'//
'//  D3DXSHRotateZ:
'//  --------------------
'//  Rotates the SH vector in the Z axis by an angle
'//
'//  Parameters:
'//   pOut
'//      Output SH coefficients - basis function Ylm is stored at l*l + m+l
'//      This is the pointer that is returned (should not alias with pIn.)
'//   Order
'//      Order of the SH evaluation, generates Order^2 coefs, degree is Order-1
'//   Angle
'//      Angle in radians to rotate around the Z axis.
'//   pIn
'//      Input SH coeffs (rotated), incorect results if this is also output.
'//
'//============================================================================

DECLARE FUNCTION D3DXSHRotateZ IMPORT $D3DX_DLLNAME ALIAS "D3DXSHRotateZ" (_
   BYREF pOut AS SINGLE _                               ' __out FLOAT *pOut
 , BYVAL Order AS DWORD _                               ' __in  UINT Order
 , BYVAL Angle AS SINGLE _                              ' __in  FLOAT Angle
 , BYREF pIn AS SINGLE _                                ' __in  CONST FLOAT *pIn
 ) AS SINGLE                                            ' FLOAT

'//============================================================================
'//
'//  D3DXSHAdd:
'//  --------------------
'//  Adds two SH vectors, pOut[i] = pA[i] + pB[i];
'//
'//  Parameters:
'//   pOut
'//      Output SH coefficients - basis function Ylm is stored at l*l + m+l
'//      This is the pointer that is returned.
'//   Order
'//      Order of the SH evaluation, generates Order^2 coefs, degree is Order-1
'//   pA
'//      Input SH coeffs.
'//   pB
'//      Input SH coeffs (second vector.)
'//
'//============================================================================

DECLARE FUNCTION D3DXSHAdd IMPORT $D3DX_DLLNAME ALIAS "D3DXSHAdd" (_
   BYREF pOut AS SINGLE _                               ' __out FLOAT *pOut
 , BYVAL Order AS DWORD _                               ' __in  UINT Order
 , BYREF pA AS SINGLE _                                 ' __in  CONST FLOAT *pA
 , BYREF pB AS SINGLE _                                 ' __in  CONST FLOAT *pB
 ) AS SINGLE                                            ' FLOAT

'//============================================================================
'//
'//  D3DXSHScale:
'//  --------------------
'//  Adds two SH vectors, pOut[i] = pA[i]*Scale;
'//
'//  Parameters:
'//   pOut
'//      Output SH coefficients - basis function Ylm is stored at l*l + m+l
'//      This is the pointer that is returned.
'//   Order
'//      Order of the SH evaluation, generates Order^2 coefs, degree is Order-1
'//   pIn
'//      Input SH coeffs.
'//   Scale
'//      Scale factor.
'//
'//============================================================================

DECLARE FUNCTION D3DXSHScale IMPORT $D3DX_DLLNAME ALIAS "D3DXSHScale" (_
   BYREF pOut AS SINGLE _                               ' __out FLOAT *pOut
 , BYVAL Order AS DWORD _                               ' __in  UINT Order
 , BYREF pIn AS SINGLE _                                ' __in  CONST FLOAT *pIn
 , BYVAL Scale AS SINGLE _                              ' __in  CONST FLOAT Scale
 ) AS SINGLE                                            ' FLOAT


'//============================================================================
'//
'//  D3DXSHDot:
'//  --------------------
'//  Computes the dot product of two SH vectors
'//
'//  Parameters:
'//   Order
'//      Order of the SH evaluation, generates Order^2 coefs, degree is Order-1
'//   pA
'//      Input SH coeffs.
'//   pB
'//      Second set of input SH coeffs.
'//
'//============================================================================

DECLARE FUNCTION D3DXSHDot IMPORT $D3DX_DLLNAME ALIAS "D3DXSHDot" (_
   BYVAL Order AS DWORD _                               ' __in UINT Order
 , BYREF pA AS SINGLE _                                 ' __in CONST FLOAT *pA
 , BYREF pB AS SINGLE _                                 ' __in CONST FLOAT *pB
 ) AS SINGLE                                            ' FLOAT

'//============================================================================
'//
'//  Basic Spherical Harmonic lighting routines
'//
'//============================================================================

'//============================================================================
'//
'//  D3DXSHEvalDirectionalLight:
'//  --------------------
'//  Evaluates a directional light and returns spectral SH data.  The output
'//  vector is computed so that if the intensity of R/G/B is unit the resulting
'//  exit radiance of a point directly under the light on a diffuse object with
'//  an albedo of 1 would be 1.0.  This will compute 3 spectral samples, pROut
'//  has to be specified, while pGout and pBout are optional.
'//
'//  Parameters:
'//   Order
'//      Order of the SH evaluation, generates Order^2 coefs, degree is Order-1
'//   pDir
'//      Direction light is coming from (assumed to be normalized.)
'//   RIntensity
'//      Red intensity of light.
'//   GIntensity
'//      Green intensity of light.
'//   BIntensity
'//      Blue intensity of light.
'//   pROut
'//      Output SH vector for Red.
'//   pGOut
'//      Output SH vector for Green (optional.)
'//   pBOut
'//      Output SH vector for Blue (optional.)
'//
'//============================================================================

DECLARE FUNCTION D3DXSHEvalDirectionalLight IMPORT $D3DX_DLLNAME ALIAS "D3DXSHEvalDirectionalLight" (_
   BYVAL Order AS DWORD _                               ' __in  UINT Order
 , BYREF pDir AS D3DXVECTOR3 _                          ' __in  CONST D3DXVECTOR3 *pDir
 , BYVAL RIntensity AS SINGLE _                         ' __in  FLOAT RIntensity
 , BYVAL GIntensity AS SINGLE _                         ' __in  FLOAT GIntensity
 , BYVAL BIntensity AS SINGLE _                         ' __in  FLOAT BIntensity
 , BYREF pROut AS SINGLE _                              ' __out FLOAT *pROut
 , BYREF pGOut AS SINGLE _                              ' __out FLOAT *pGOut
 , BYREF pBOut AS SINGLE _                              ' __out FLOAT *pBOut
 ) AS LONG                                              ' HRESULT

'//============================================================================
'//
'//  D3DXSHEvalSphericalLight:
'//  --------------------
'//  Evaluates a spherical light and returns spectral SH data.  There is no
'//  normalization of the intensity of the light like there is for directional
'//  lights, care has to be taken when specifiying the intensities.  This will
'//  compute 3 spectral samples, pROut has to be specified, while pGout and
'//  pBout are optional.
'//
'//  Parameters:
'//   Order
'//      Order of the SH evaluation, generates Order^2 coefs, degree is Order-1
'//   pPos
'//      Position of light - reciever is assumed to be at the origin.
'//   Radius
'//      Radius of the spherical light source.
'//   RIntensity
'//      Red intensity of light.
'//   GIntensity
'//      Green intensity of light.
'//   BIntensity
'//      Blue intensity of light.
'//   pROut
'//      Output SH vector for Red.
'//   pGOut
'//      Output SH vector for Green (optional.)
'//   pBOut
'//      Output SH vector for Blue (optional.)
'//
'//============================================================================

DECLARE FUNCTION D3DXSHEvalSphericalLight IMPORT $D3DX_DLLNAME ALIAS "D3DXSHEvalSphericalLight" (_
   BYVAL Order AS DWORD _                               ' __in  UINT Order
 , BYREF pPos AS D3DXVECTOR3 _                          ' __in  CONST D3DXVECTOR3 *pPos
 , BYVAL Radius AS SINGLE _                             ' __in  FLOAT Radius
 , BYVAL RIntensity AS SINGLE _                         ' __in  FLOAT RIntensity
 , BYVAL GIntensity AS SINGLE _                         ' __in  FLOAT GIntensity
 , BYVAL BIntensity AS SINGLE _                         ' __in  FLOAT BIntensity
 , BYREF pROut AS SINGLE _                              ' __out FLOAT *pROut
 , BYREF pGOut AS SINGLE _                              ' __out FLOAT *pGOut
 , BYREF pBOut AS SINGLE _                              ' __out FLOAT *pBOut
 ) AS LONG                                              ' HRESULT

'//============================================================================
'//
'//  D3DXSHEvalConeLight:
'//  --------------------
'//  Evaluates a light that is a cone of constant intensity and returns spectral
'//  SH data.  The output vector is computed so that if the intensity of R/G/B is
'//  unit the resulting exit radiance of a point directly under the light oriented
'//  in the cone direction on a diffuse object with an albedo of 1 would be 1.0.
'//  This will compute 3 spectral samples, pROut has to be specified, while pGout
'//  and pBout are optional.
'//
'//  Parameters:
'//   Order
'//      Order of the SH evaluation, generates Order^2 coefs, degree is Order-1
'//   pDir
'//      Direction light is coming from (assumed to be normalized.)
'//   Radius
'//      Radius of cone in radians.
'//   RIntensity
'//      Red intensity of light.
'//   GIntensity
'//      Green intensity of light.
'//   BIntensity
'//      Blue intensity of light.
'//   pROut
'//      Output SH vector for Red.
'//   pGOut
'//      Output SH vector for Green (optional.)
'//   pBOut
'//      Output SH vector for Blue (optional.)
'//
'//============================================================================

DECLARE FUNCTION D3DXSHEvalConeLight IMPORT $D3DX_DLLNAME ALIAS "D3DXSHEvalConeLight" (_
   BYVAL Order AS DWORD _                               ' __in  UINT Order
 , BYREF pDir AS D3DXVECTOR3 _                          ' __in  CONST D3DXVECTOR3 *pDir
 , BYVAL Radius AS SINGLE _                             ' __in  FLOAT Radius
 , BYVAL RIntensity AS SINGLE _                         ' __in  FLOAT RIntensity
 , BYVAL GIntensity AS SINGLE _                         ' __in  FLOAT GIntensity
 , BYVAL BIntensity AS SINGLE _                         ' __in  FLOAT BIntensity
 , BYREF pROut AS SINGLE _                              ' __out FLOAT *pROut
 , BYREF pGOut AS SINGLE _                              ' __out FLOAT *pGOut
 , BYREF pBOut AS SINGLE _                              ' __out FLOAT *pBOut
 ) AS LONG                                              ' HRESULT

'//============================================================================
'//
'//  D3DXSHEvalHemisphereLight:
'//  --------------------
'//  Evaluates a light that is a linear interpolant between two colors over the
'//  sphere.  The interpolant is linear along the axis of the two points, not
'//  over the surface of the sphere (ie: if the axis was (0,0,1) it is linear in
'//  Z, not in the azimuthal angle.)  The resulting spherical lighting function
'//  is normalized so that a point on a perfectly diffuse surface with no
'//  shadowing and a normal pointed in the direction pDir would result in exit
'//  radiance with a value of 1 if the top color was white and the bottom color
'//  was black.  This is a very simple model where Top represents the intensity
'//  of the "sky" and Bottom represents the intensity of the "ground".
'//
'//  Parameters:
'//   Order
'//      Order of the SH evaluation, generates Order^2 coefs, degree is Order-1
'//   pDir
'//      Axis of the hemisphere.
'//   Top
'//      Color of the upper hemisphere.
'//   Bottom
'//      Color of the lower hemisphere.
'//   pROut
'//      Output SH vector for Red.
'//   pGOut
'//      Output SH vector for Green
'//   pBOut
'//      Output SH vector for Blue
'//
'//============================================================================

DECLARE FUNCTION D3DXSHEvalHemisphereLight IMPORT $D3DX_DLLNAME ALIAS "D3DXSHEvalHemisphereLight" (_
   BYVAL Order AS DWORD _                               ' __in  UINT Order
 , BYREF pDir AS D3DXVECTOR3 _                          ' __in  CONST D3DXVECTOR3 *pDir
 , BYREF Top AS D3DXCOLOR _                             ' __in  D3DXCOLOR Top
 , BYREF Bottom AS D3DXCOLOR _                          ' __in  D3DXCOLOR Bottom
 , BYREF pROut AS SINGLE _                              ' __out FLOAT *pROut
 , BYREF pGOut AS SINGLE _                              ' __out FLOAT *pGOut
 , BYREF pBOut AS SINGLE _                              ' __out FLOAT *pBOut
 ) AS LONG                                              ' HRESULT

'//============================================================================
'//
'//  Basic Spherical Harmonic projection routines
'//
'//============================================================================

'//============================================================================
'//
'//  D3DXSHProjectCubeMap:
'//  --------------------
'//  Projects a function represented on a cube map into spherical harmonics.
'//
'//  Parameters:
'//   Order
'//      Order of the SH evaluation, generates Order^2 coefs, degree is Order-1
'//   pCubeMap
'//      CubeMap that is going to be projected into spherical harmonics
'//   pROut
'//      Output SH vector for Red.
'//   pGOut
'//      Output SH vector for Green
'//   pBOut
'//      Output SH vector for Blue
'//
'//============================================================================

DECLARE FUNCTION D3DXSHProjectCubeMap IMPORT $D3DX_DLLNAME ALIAS "D3DXSHProjectCubeMap" (_
   BYVAL uOrder AS DWORD _                              ' __in  UINT uOrder
 , BYVAL pCubeMap AS IDirect3DCubeTexture9 _            ' __in  LPDIRECT3DCUBETEXTURE9 pCubeMap
 , BYREF pROut AS SINGLE _                              ' __out FLOAT *pROut
 , BYREF pGOut AS SINGLE _                              ' __out FLOAT *pGOut
 , BYREF pBOut AS SINGLE _                              ' __out FLOAT *pBOut
 ) AS LONG                                              ' HRESULT

#INCLUDE ONCE "d3dx9math.inl"
