' ########################################################################################
' Microsoft Windows
' File: d3dx10math.inl
' Contents: D3DX10 math inline functions
' Copyright (c) 2010 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE

'//===========================================================================
'//
'// Inline functions
'//
'//===========================================================================


'//--------------------------
'// 2D Vector
'//--------------------------

'D3DX10INLINE FLOAT D3DXVec2Length
'    ( CONST D3DXVECTOR2 *pV )
'{
'#ifdef D3DX10_DEBUG
'    if(!pV)
'        return 0.0f;
'#endif

'#ifdef __cplusplus
'    return sqrtf(pV->x * pV->x + pV->y * pV->y);
'#else
'    return (FLOAT) sqrt(pV->x * pV->x + pV->y * pV->y);
'#endif
'}

' Returns the length of a 2D vector.
FUNCTION D3DXVec2Length (BYREF pV AS D3DXVECTOR2) AS SINGLE
   IF VARPTR(pV) = %NULL THEN EXIT FUNCTION
   FUNCTION = SQR(pV.x * pV.x + pV.y * pV.y)
END FUNCTION

'D3DX10INLINE FLOAT D3DXVec2LengthSq
'    ( CONST D3DXVECTOR2 *pV )
'{
'#ifdef D3DX10_DEBUG
'    if(!pV)
'        return 0.0f;
'#endif

'    return pV->x * pV->x + pV->y * pV->y;
'}

' Returns the square of the length of a 2D vector.
FUNCTION D3DXVec2LengthSq (BYREF pV AS D3DXVECTOR2) AS SINGLE
   IF VARPTR(pV) = %NULL THEN EXIT FUNCTION
   FUNCTION = pV.x * pV.x + pV.y * pV.y
END FUNCTION

'D3DX10INLINE FLOAT D3DXVec2Dot
'    ( CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2 )
'{
'#ifdef D3DX10_DEBUG
'    if(!pV1 || !pV2)
'        return 0.0f;
'#endif

'    return pV1->x * pV2->x + pV1->y * pV2->y;
'}

' Determines the dot product of two 2D vectors.
FUNCTION D3DXVec2Dot (BYREF pV1 AS D3DXVECTOR2, BYREF pV2 AS D3DXVECTOR2) AS SINGLE
   IF VARPTR(pV1) = %NULL OR VARPTR(pV2) = %NULL THEN EXIT FUNCTION
   FUNCTION = pV1.x * pV2.x + pV1.y * pV2.y
END FUNCTION

'D3DX10INLINE FLOAT D3DXVec2CCW
'    ( CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2 )
'{
'#ifdef D3DX10_DEBUG
'    if(!pV1 || !pV2)
'        return 0.0f;
'#endif

'    return pV1->x * pV2->y - pV1->y * pV2->x;
'}

' Returns the z-component by taking the cross product of two 2D vectors.
FUNCTION D3DXVec2CCW (BYREF pV1 AS D3DXVECTOR2, BYREF pV2 AS D3DXVECTOR2) AS SINGLE
   IF VARPTR(pV1) = %NULL OR VARPTR(pV2) = %NULL THEN EXIT FUNCTION
   FUNCTION = pV1.x * pV2.y - pV1.y * pV2.x
END FUNCTION

'D3DX10INLINE D3DXVECTOR2* D3DXVec2Add
'    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2 )
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pV1 || !pV2)
'        return NULL;
'#endif

'    pOut->x = pV1->x + pV2->x;
'    pOut->y = pV1->y + pV2->y;
'    return pOut;
'}

' Adds two 2D vectors.
SUB D3DXVec2Add (BYREF pOut AS D3DXVECTOR2, BYREF pV1 AS D3DXVECTOR2, BYREF pV2 AS D3DXVECTOR2)
   IF VARPTR(pOut) = %NULL OR VARPTR(pV1) = %NULL OR VARPTR(pV2) = %NULL THEN EXIT SUB
   pOut.x = pV1.x + pV2.x
   pOut.y = pV1.y + pV2.y
END SUB

'D3DX10INLINE D3DXVECTOR2* D3DXVec2Subtract
'    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2 )
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pV1 || !pV2)
'        return NULL;
'#endif

'    pOut->x = pV1->x - pV2->x;
'    pOut->y = pV1->y - pV2->y;
'    return pOut;
'}

' Subtracts two 2D vectors.
SUB D3DXVec2Subtract (BYREF pOut AS D3DXVECTOR2, BYREF pV1 AS D3DXVECTOR2, BYREF pV2 AS D3DXVECTOR2)
   IF VARPTR(pOut) = %NULL OR VARPTR(pV1) = %NULL OR VARPTR(pV2) = %NULL THEN EXIT SUB
   pOut.x = pV1.x - pV2.x
   pOut.y = pV1.y - pV2.y
END SUB

'D3DX10INLINE D3DXVECTOR2* D3DXVec2Minimize
'    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2 )
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pV1 || !pV2)
'        return NULL;
'#endif

'    pOut->x = pV1->x < pV2->x ? pV1->x : pV2->x;
'    pOut->y = pV1->y < pV2->y ? pV1->y : pV2->y;
'    return pOut;
'}

' Returns a 2D vector that is made up of the smallest components of two 2D vectors.
SUB D3DXVec2Minimize (BYREF pOut AS D3DXVECTOR2, BYREF pV1 AS D3DXVECTOR2, BYREF pV2 AS D3DXVECTOR2)
   IF VARPTR(pOut) = %NULL OR VARPTR(pV1) = %NULL OR VARPTR(pV2) = %NULL THEN EXIT SUB
   pOut.x = IIF(pV1.x < pV2.x, pV1.x, pV2.x)
   pOut.y = IIF(pV1.y < pV2.y, pV1.y, pV2.y)
END SUB

'D3DX10INLINE D3DXVECTOR2* D3DXVec2Maximize
'    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2 )
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pV1 || !pV2)
'        return NULL;
'#endif

'    pOut->x = pV1->x > pV2->x ? pV1->x : pV2->x;
'    pOut->y = pV1->y > pV2->y ? pV1->y : pV2->y;
'    return pOut;
'}

' Returns a 2D vector that is made up of the largest components of two 2D vectors.
SUB D3DXVec2Maximize (BYREF pOut AS D3DXVECTOR2, BYREF pV1 AS D3DXVECTOR2, BYREF pV2 AS D3DXVECTOR2)
   IF VARPTR(pOut) = %NULL OR VARPTR(pV1) = %NULL OR VARPTR(pV2) = %NULL THEN EXIT SUB
   pOut.x = IIF(pV1.x > pV2.x, pV1.x, pV2.x)
   pOut.y = IIF(pV1.y > pV2.y, pV1.y, pV2.y)
END SUB

'D3DX10INLINE D3DXVECTOR2* D3DXVec2Scale
'    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV, FLOAT s )
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pV)
'        return NULL;
'#endif

'    pOut->x = pV->x * s;
'    pOut->y = pV->y * s;
'    return pOut;
'}

' Scales a 2D vector.
SUB D3DXVec2Scale (BYREF pOut AS D3DXVECTOR2, BYREF pV AS D3DXVECTOR2, BYVAL s AS SINGLE)
   IF VARPTR(pOut) = %NULL OR VARPTR(pV) = %NULL THEN EXIT SUB
   pOut.x = pV.x * s
   pOut.y = pV.y * s
END SUB

'D3DX10INLINE D3DXVECTOR2* D3DXVec2Lerp
'    ( D3DXVECTOR2 *pOut, CONST D3DXVECTOR2 *pV1, CONST D3DXVECTOR2 *pV2,
'      FLOAT s )
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pV1 || !pV2)
'        return NULL;
'#endif

'    pOut->x = pV1->x + s * (pV2->x - pV1->x);
'    pOut->y = pV1->y + s * (pV2->y - pV1->y);
'    return pOut;
'}

' Performs a linear interpolation between two 2D vectors.
SUB D3DXVec2Lerp (BYREF pOut AS D3DXVECTOR2, BYREF pV1 AS D3DXVECTOR2, BYREF pV2 AS D3DXVECTOR2, BYVAL s AS SINGLE)
   IF VARPTR(pOut) = %NULL OR VARPTR(pV1) = %NULL OR VARPTR(pV2) = %NULL THEN EXIT SUB
   pOut.x = pV1.x + s * (pV2.x - pV1.x)
   pOut.y = pV1.y + s * (pV2.y - pV1.y)
END SUB

'//--------------------------
'// 3D Vector
'//--------------------------

'D3DX10INLINE FLOAT D3DXVec3Length
'    ( CONST D3DXVECTOR3 *pV )
'{
'#ifdef D3DX10_DEBUG
'    if(!pV)
'        return 0.0f;
'#endif

'#ifdef __cplusplus
'    return sqrtf(pV->x * pV->x + pV->y * pV->y + pV->z * pV->z);
'#else
'    return (FLOAT) sqrt(pV->x * pV->x + pV->y * pV->y + pV->z * pV->z);
'#endif
'}

' Returns the length of a 3D vector.
FUNCTION D3DXVec3Length (BYREF pV AS D3DXVECTOR3) AS SINGLE
   IF VARPTR(pV) = %NULL THEN EXIT FUNCTION
   FUNCTION = SQR(pV.x * pV.x + pV.y * pV.y + pV.z * pV.z)
END FUNCTION

'D3DX10INLINE FLOAT D3DXVec3LengthSq
'    ( CONST D3DXVECTOR3 *pV )
'{
'#ifdef D3DX10_DEBUG
'    if(!pV)
'        return 0.0f;
'#endif

'    return pV->x * pV->x + pV->y * pV->y + pV->z * pV->z;
'}

' Returns the square of the length of a 3D vector.
FUNCTION D3DXVec3LengthSq (BYREF pV AS D3DXVECTOR3) AS SINGLE
   IF VARPTR(pV) = %NULL THEN EXIT FUNCTION
   FUNCTION = pV.x * pV.x + pV.y * pV.y + pV.z * pV.z
END FUNCTION

'D3DX10INLINE FLOAT D3DXVec3Dot
'    ( CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 )
'{
'#ifdef D3DX10_DEBUG
'    if(!pV1 || !pV2)
'        return 0.0f;
'#endif

'    return pV1->x * pV2->x + pV1->y * pV2->y + pV1->z * pV2->z;
'}

' Determines the dot-product of two 3D vectors.
FUNCTION D3DXVec3Dot (BYREF pV1 AS D3DXVECTOR3, BYREF pV2 AS D3DXVECTOR3) AS SINGLE
   IF VARPTR(pV1) = %NULL OR VARPTR(pV2) = %NULL THEN EXIT FUNCTION
   FUNCTION = pV1.x * pV2.x + pV1.y * pV2.y + pV1.z * pV2.z
END FUNCTION

'D3DX10INLINE D3DXVECTOR3* D3DXVec3Cross
'    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 )
'{
'    D3DXVECTOR3 v;

'#ifdef D3DX10_DEBUG
'    if(!pOut || !pV1 || !pV2)
'        return NULL;
'#endif

'    v.x = pV1->y * pV2->z - pV1->z * pV2->y;
'    v.y = pV1->z * pV2->x - pV1->x * pV2->z;
'    v.z = pV1->x * pV2->y - pV1->y * pV2->x;

'    *pOut = v;
'    return pOut;
'}

' Determines the cross-product of two 3D vectors.
SUB D3DXVec3Cross (BYREF pOut AS D3DXVECTOR3, BYREF pV1 AS D3DXVECTOR3, BYREF pV2 AS D3DXVECTOR3)
   IF VARPTR(pOut) = %NULL OR VARPTR(pV1) = %NULL OR VARPTR(pV2) = %NULL THEN EXIT SUB
   pOut.x = pV1.y * pV2.z - pV1.z * pV2.y
   pOut.y = pV1.z * pV2.x - pV1.x * pV2.z
   pOut.z = pV1.x * pV2.y - pV1.y * pV2.x
END SUB

'D3DX10INLINE D3DXVECTOR3* D3DXVec3Add
'    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 )
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pV1 || !pV2)
'        return NULL;
'#endif

'    pOut->x = pV1->x + pV2->x;
'    pOut->y = pV1->y + pV2->y;
'    pOut->z = pV1->z + pV2->z;
'    return pOut;
'}

' Adds two 3D vectors.
SUB D3DXVec3Add (BYREF pOut AS D3DXVECTOR3, BYREF pV1 AS D3DXVECTOR3, BYREF pV2 AS D3DXVECTOR3)
   IF VARPTR(pOut) = %NULL OR VARPTR(pV1) = %NULL OR VARPTR(pV2) = %NULL THEN EXIT SUB
   pOut.x = pV1.x + pV2.x
   pOut.y = pV1.y + pV2.y
   pOut.z = pV1.z + pV2.z
END SUB

'D3DX10INLINE D3DXVECTOR3* D3DXVec3Subtract
'    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 )
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pV1 || !pV2)
'        return NULL;
'#endif

'    pOut->x = pV1->x - pV2->x;
'    pOut->y = pV1->y - pV2->y;
'    pOut->z = pV1->z - pV2->z;
'    return pOut;
'}

' Subtracts two 3D vectors.
SUB D3DXVec3Subtract (BYREF pOut AS D3DXVECTOR3, BYREF pV1 AS D3DXVECTOR3, BYREF pV2 AS D3DXVECTOR3)
   IF VARPTR(pOut) = %NULL OR VARPTR(pV1) = %NULL OR VARPTR(pV2) = %NULL THEN EXIT SUB
   pOut.x = pV1.x - pV2.x
   pOut.y = pV1.y - pV2.y
   pOut.z = pV1.z - pV2.z
END SUB

'D3DX10INLINE D3DXVECTOR3* D3DXVec3Minimize
'    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 )
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pV1 || !pV2)
'        return NULL;
'#endif

'    pOut->x = pV1->x < pV2->x ? pV1->x : pV2->x;
'    pOut->y = pV1->y < pV2->y ? pV1->y : pV2->y;
'    pOut->z = pV1->z < pV2->z ? pV1->z : pV2->z;
'    return pOut;
'}

' Returns a 3D vector that is made up of the smallest components of two 3D vectors.
SUB D3DXVec3Minimize (BYREF pOut AS D3DXVECTOR3, BYREF pV1 AS D3DXVECTOR3, BYREF pV2 AS D3DXVECTOR3)
   IF VARPTR(pOut) = %NULL OR VARPTR(pV1) = %NULL OR VARPTR(pV2) = %NULL THEN EXIT SUB
   pOut.x = IIF(pV1.x < pV2.x, pV1.x, pV2.x)
   pOut.y = IIF(pV1.y < pV2.y, pV1.y, pV2.y)
   pOut.z = IIF(pV1.z < pV2.z, pV1.z, pV2.z)
END SUB

'D3DX10INLINE D3DXVECTOR3* D3DXVec3Maximize
'    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2 )
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pV1 || !pV2)
'        return NULL;
'#endif

'    pOut->x = pV1->x > pV2->x ? pV1->x : pV2->x;
'    pOut->y = pV1->y > pV2->y ? pV1->y : pV2->y;
'    pOut->z = pV1->z > pV2->z ? pV1->z : pV2->z;
'    return pOut;
'}

' Returns a 3D vector that is made up of the largest components of two 3D vectors.
SUB D3DXVec3Maximize (BYREF pOut AS D3DXVECTOR3, BYREF pV1 AS D3DXVECTOR3, BYREF pV2 AS D3DXVECTOR3)
   IF VARPTR(pOut) = %NULL OR VARPTR(pV1) = %NULL OR VARPTR(pV2) = %NULL THEN EXIT SUB
   pOut.x = IIF(pV1.x > pV2.x, pV1.x, pV2.x)
   pOut.y = IIF(pV1.y > pV2.y, pV1.y, pV2.y)
   pOut.z = IIF(pV1.z > pV2.z, pV1.z, pV2.z)
END SUB

'D3DX10INLINE D3DXVECTOR3* D3DXVec3Scale
'    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV, FLOAT s)
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pV)
'        return NULL;
'#endif

'    pOut->x = pV->x * s;
'    pOut->y = pV->y * s;
'    pOut->z = pV->z * s;
'    return pOut;
'}

' Scales a 3D vector.
SUB D3DXVec3Scale (BYREF pOut AS D3DXVECTOR3, BYREF pV AS D3DXVECTOR3, BYVAL s AS SINGLE)
   IF VARPTR(pOut) = %NULL OR VARPTR(pV) = %NULL THEN EXIT SUB
   pOut.x = pV.x * s
   pOut.y = pV.y * s
   pOut.z = pV.z * s
END SUB

'D3DX10INLINE D3DXVECTOR3* D3DXVec3Lerp
'    ( D3DXVECTOR3 *pOut, CONST D3DXVECTOR3 *pV1, CONST D3DXVECTOR3 *pV2,
'      FLOAT s )
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pV1 || !pV2)
'        return NULL;
'#endif

'    pOut->x = pV1->x + s * (pV2->x - pV1->x);
'    pOut->y = pV1->y + s * (pV2->y - pV1->y);
'    pOut->z = pV1->z + s * (pV2->z - pV1->z);
'    return pOut;
'}

' Performs a linear interpolation between two 3D vectors.
SUB D3DXVec3Lerp (BYREF pOut AS D3DXVECTOR3, BYREF pV1 AS D3DXVECTOR3, BYREF pV2 AS D3DXVECTOR3, BYVAL s AS SINGLE)
   IF VARPTR(pOut) = %NULL OR VARPTR(pV1) = %NULL OR VARPTR(pV2) = %NULL THEN EXIT SUB
   pOut.x = pV1.x + s * (pV2.x - pV1.x)
   pOut.y = pV1.y + s * (pV2.y - pV1.y)
   pOut.z = pV1.z + s * (pV2.z - pV1.z)
END SUB

'//--------------------------
'// 4D Vector
'//--------------------------

'D3DX10INLINE FLOAT D3DXVec4Length
'    ( CONST D3DXVECTOR4 *pV )
'{
'#ifdef D3DX10_DEBUG
'    if(!pV)
'        return 0.0f;
'#endif

'#ifdef __cplusplus
'    return sqrtf(pV->x * pV->x + pV->y * pV->y + pV->z * pV->z + pV->w * pV->w);
'#else
'    return (FLOAT) sqrt(pV->x * pV->x + pV->y * pV->y + pV->z * pV->z + pV->w * pV->w);
'#endif
'}

' Returns the length of a 4D vector.
FUNCTION D3DXVec4Length (BYREF pV AS D3DXVECTOR4) AS SINGLE
   IF VARPTR(pV) = %NULL THEN EXIT FUNCTION
   FUNCTION = SQR(pV.x * pV.x + pV.y * pV.y + pV.z * pV.z + pV.w * pV.w)
END FUNCTION

'D3DX10INLINE FLOAT D3DXVec4LengthSq
'    ( CONST D3DXVECTOR4 *pV )
'{
'#ifdef D3DX10_DEBUG
'    if(!pV)
'        return 0.0f;
'#endif

'    return pV->x * pV->x + pV->y * pV->y + pV->z * pV->z + pV->w * pV->w;
'}

' Returns the square of the length of a 4D vector.
FUNCTION D3DXVec4LengthSq (BYREF pV AS D3DXVECTOR4) AS SINGLE
   IF VARPTR(pV) = %NULL THEN EXIT FUNCTION
   FUNCTION = pV.x * pV.x + pV.y * pV.y + pV.z * pV.z + pV.w * pV.w
END FUNCTION

'D3DX10INLINE FLOAT D3DXVec4Dot
'    ( CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2 )
'{
'#ifdef D3DX10_DEBUG
'    if(!pV1 || !pV2)
'        return 0.0f;
'#endif

'    return pV1->x * pV2->x + pV1->y * pV2->y + pV1->z * pV2->z + pV1->w * pV2->w;
'}

' Determines the dot product of two 4D vectors.
FUNCTION D3DXVec4Dot (BYREF pV1 AS D3DXVECTOR4, BYREF pV2 AS D3DXVECTOR4) AS SINGLE
   IF VARPTR(pV1) = %NULL OR VARPTR(pV2) = %NULL THEN EXIT FUNCTION
   FUNCTION = pV1.x * pV2.x + pV1.y * pV2.y + pV1.z * pV2.z + pV1.w * pV2.w
END FUNCTION

'D3DX10INLINE D3DXVECTOR4* D3DXVec4Add
'    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2)
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pV1 || !pV2)
'        return NULL;
'#endif

'    pOut->x = pV1->x + pV2->x;
'    pOut->y = pV1->y + pV2->y;
'    pOut->z = pV1->z + pV2->z;
'    pOut->w = pV1->w + pV2->w;
'    return pOut;
'}

' Adds two 4D vectors.
SUB D3DXVec4Add (BYREF pOut AS D3DXVECTOR4, BYREF pV1 AS D3DXVECTOR4, BYREF pV2 AS D3DXVECTOR4)
   IF VARPTR(pOut) = %NULL OR VARPTR(pV1) = %NULL OR VARPTR(pV2) = %NULL THEN EXIT SUB
   pOut.x = pV1.x + pV2.x
   pOut.y = pV1.y + pV2.y
   pOut.z = pV1.z + pV2.z
   pOut.w = pV1.w + pV2.w
END SUB

'D3DX10INLINE D3DXVECTOR4* D3DXVec4Subtract
'    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2)
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pV1 || !pV2)
'        return NULL;
'#endif

'    pOut->x = pV1->x - pV2->x;
'    pOut->y = pV1->y - pV2->y;
'    pOut->z = pV1->z - pV2->z;
'    pOut->w = pV1->w - pV2->w;
'    return pOut;
'}

' Subtracts two 4D vectors.
SUB D3DXVec4Subtract (BYREF pOut AS D3DXVECTOR4, BYREF pV1 AS D3DXVECTOR4, BYREF pV2 AS D3DXVECTOR4)
   IF VARPTR(pOut) = %NULL OR VARPTR(pV1) = %NULL OR VARPTR(pV2) = %NULL THEN EXIT SUB
   pOut.x = pV1.x - pV2.x
   pOut.y = pV1.y - pV2.y
   pOut.z = pV1.z - pV2.z
   pOut.w = pV1.w - pV2.w
END SUB

'D3DX10INLINE D3DXVECTOR4* D3DXVec4Minimize
'    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2)
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pV1 || !pV2)
'        return NULL;
'#endif

'    pOut->x = pV1->x < pV2->x ? pV1->x : pV2->x;
'    pOut->y = pV1->y < pV2->y ? pV1->y : pV2->y;
'    pOut->z = pV1->z < pV2->z ? pV1->z : pV2->z;
'    pOut->w = pV1->w < pV2->w ? pV1->w : pV2->w;
'    return pOut;
'}

' Returns a 4D vector that is made up of the smallest components of two 4D vectors.
SUB D3DXVec4Minimize (BYREF pOut AS D3DXVECTOR4, BYREF pV1 AS D3DXVECTOR4, BYREF pV2 AS D3DXVECTOR4)
   IF VARPTR(pOut) = %NULL OR VARPTR(pV1) = %NULL OR VARPTR(pV2) = %NULL THEN EXIT SUB
   pOut.x = IIF(pV1.x < pV2.x, pV1.x, pV2.x)
   pOut.y = IIF(pV1.y < pV2.y, pV1.y, pV2.y)
   pOut.z = IIF(pV1.z < pV2.z, pV1.z, pV2.z)
   pOut.w = IIF(pV1.w < pV2.w, pV1.w, pV2.w)
END SUB

'D3DX10INLINE D3DXVECTOR4* D3DXVec4Maximize
'    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2)
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pV1 || !pV2)
'        return NULL;
'#endif

'    pOut->x = pV1->x > pV2->x ? pV1->x : pV2->x;
'    pOut->y = pV1->y > pV2->y ? pV1->y : pV2->y;
'    pOut->z = pV1->z > pV2->z ? pV1->z : pV2->z;
'    pOut->w = pV1->w > pV2->w ? pV1->w : pV2->w;
'    return pOut;
'}

' Returns a 4D vector that is made up of the largest components of two 4D vectors.
SUB D3DXVec4Maximize (BYREF pOut AS D3DXVECTOR4, BYREF pV1 AS D3DXVECTOR4, BYREF pV2 AS D3DXVECTOR4)
   IF VARPTR(pOut) = %NULL OR VARPTR(pV1) = %NULL OR VARPTR(pV2) = %NULL THEN EXIT SUB
   pOut.x = IIF(pV1.x > pV2.x, pV1.x, pV2.x)
   pOut.y = IIF(pV1.y > pV2.y, pV1.y, pV2.y)
   pOut.z = IIF(pV1.z > pV2.z, pV1.z, pV2.z)
   pOut.w = IIF(pV1.w > pV2.w, pV1.w, pV2.w)
END SUB

'D3DX10INLINE D3DXVECTOR4* D3DXVec4Scale
'    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV, FLOAT s)
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pV)
'        return NULL;
'#endif

'    pOut->x = pV->x * s;
'    pOut->y = pV->y * s;
'    pOut->z = pV->z * s;
'    pOut->w = pV->w * s;
'    return pOut;
'}

' Scales a 4D vector.
SUB D3DXVec4Scale (BYREF pOut AS D3DXVECTOR4, BYREF pV AS D3DXVECTOR4, BYVAL s AS SINGLE)
   IF VARPTR(pOut) = %NULL OR VARPTR(pV) = %NULL THEN EXIT SUB
   pOut.x = pV.x * s
   pOut.y = pV.y * s
   pOut.z = pV.z * s
   pOut.w = pV.w * s
END SUB

'D3DX10INLINE D3DXVECTOR4* D3DXVec4Lerp
'    ( D3DXVECTOR4 *pOut, CONST D3DXVECTOR4 *pV1, CONST D3DXVECTOR4 *pV2,
'      FLOAT s )
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pV1 || !pV2)
'        return NULL;
'#endif

'    pOut->x = pV1->x + s * (pV2->x - pV1->x);
'    pOut->y = pV1->y + s * (pV2->y - pV1->y);
'    pOut->z = pV1->z + s * (pV2->z - pV1->z);
'    pOut->w = pV1->w + s * (pV2->w - pV1->w);
'    return pOut;
'}

' Performs a linear interpolation between two 4D vectors.
SUB D3DXVec4Lerp (BYREF pOut AS D3DXVECTOR4, BYREF pV1 AS D3DXVECTOR4, BYREF pV2 AS D3DXVECTOR4, BYVAL s AS SINGLE)
   IF VARPTR(pOut) = %NULL OR VARPTR(pV1) = %NULL OR VARPTR(pV2) = %NULL THEN EXIT SUB
   pOut.x = pV1.x + s * (pV2.x - pV1.x)
   pOut.y = pV1.y + s * (pV2.y - pV1.y)
   pOut.z = pV1.z + s * (pV2.z - pV1.z)
   pOut.w = pV1.w + s * (pV2.w - pV1.w)
END SUB

'//--------------------------
'// 4D Matrix
'//--------------------------

'D3DX10INLINE D3DXMATRIX* D3DXMatrixIdentity
'    ( D3DXMATRIX *pOut )
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut)
'        return NULL;
'#endif

'    pOut->m[0][1] = pOut->m[0][2] = pOut->m[0][3] =
'    pOut->m[1][0] = pOut->m[1][2] = pOut->m[1][3] =
'    pOut->m[2][0] = pOut->m[2][1] = pOut->m[2][3] =
'    pOut->m[3][0] = pOut->m[3][1] = pOut->m[3][2] = 0.0f;

'    pOut->m[0][0] = pOut->m[1][1] = pOut->m[2][2] = pOut->m[3][3] = 1.0f;
'    return pOut;
'}

' Creates an identity matrix.
SUB D3DXMatrixIdentity (BYREF pOut AS D3DXMATRIX)
   IF VARPTR(pOut) = %NULL THEN EXIT SUB
   pOut.m12 = 0.0! : pOut.m13 = 0.0! : pOut.m14 = 0.0!
   pOut.m21 = 0.0! : pOut.m23 = 0.0! : pOut.m24 = 0.0!
   pOut.m31 = 0.0! : pOut.m32 = 0.0! : pOut.m34 = 0.0!
   pOut.m41 = 0.0! : pOut.m42 = 0.0! : pOut.m43 = 0.0!
   pOut.m11 = 1.0! : pOut.m22 = 1.0! : pOut.m33 = 1.0! : pOut.m44 = 1.0!
END SUB

'D3DX10INLINE BOOL D3DXMatrixIsIdentity
'    ( CONST D3DXMATRIX *pM )
'{
'#ifdef D3DX10_DEBUG
'    if(!pM)
'        return FALSE;
'#endif

'    return pM->m[0][0] == 1.0f && pM->m[0][1] == 0.0f && pM->m[0][2] == 0.0f && pM->m[0][3] == 0.0f &&
'           pM->m[1][0] == 0.0f && pM->m[1][1] == 1.0f && pM->m[1][2] == 0.0f && pM->m[1][3] == 0.0f &&
'           pM->m[2][0] == 0.0f && pM->m[2][1] == 0.0f && pM->m[2][2] == 1.0f && pM->m[2][3] == 0.0f &&
'           pM->m[3][0] == 0.0f && pM->m[3][1] == 0.0f && pM->m[3][2] == 0.0f && pM->m[3][3] == 1.0f;
'}

' Determines if a matrix is an identity matrix.
FUNCTION D3DXMatrixIsIdentity (BYREF pM AS D3DXMATRIX) AS LONG
   IF VARPTR(pM) = %NULL THEN EXIT FUNCTION
   FUNCTION = (pM.m11 = 1.0! AND pM.m12 = 0.0! AND pM.m13 = 0.0! AND pM.m14 = 0.0! AND _
               pM.m21 = 0.0! AND pM.m22 = 1.0! AND pM.m23 = 0.0! AND pM.m24 = 0.0! AND _
               pM.m31 = 0.0! AND pM.m32 = 0.0! AND pM.m33 = 1.0! AND pM.m34 = 0.0! AND _
               pM.m41 = 0.0! AND pM.m42 = 0.0! AND pM.m43 = 0.0! AND pM.m44 = 1.0!)
END FUNCTION

'//--------------------------
'// Quaternion
'//--------------------------

'D3DX10INLINE FLOAT D3DXQuaternionLength
'    ( CONST D3DXQUATERNION *pQ )
'{
'#ifdef D3DX10_DEBUG
'    if(!pQ)
'        return 0.0f;
'#endif

'#ifdef __cplusplus
'    return sqrtf(pQ->x * pQ->x + pQ->y * pQ->y + pQ->z * pQ->z + pQ->w * pQ->w);
'#else
'    return (FLOAT) sqrt(pQ->x * pQ->x + pQ->y * pQ->y + pQ->z * pQ->z + pQ->w * pQ->w);
'#endif
'}

' Returns the length of a quaternion.
FUNCTION D3DXQuaternionLength (BYREF pQ AS D3DXQUATERNION) AS SINGLE
   IF VARPTR(pQ) = %NULL THEN EXIT FUNCTION
   FUNCTION = SQR(pQ.x * pQ.x + pQ.y * pQ.y + pQ.z * pQ.z + pQ.w * pQ.w)
END FUNCTION

'D3DX10INLINE FLOAT D3DXQuaternionLengthSq
'    ( CONST D3DXQUATERNION *pQ )
'{
'#ifdef D3DX10_DEBUG
'    if(!pQ)
'        return 0.0f;
'#endif

'    return pQ->x * pQ->x + pQ->y * pQ->y + pQ->z * pQ->z + pQ->w * pQ->w;
'}

FUNCTION D3DXQuaternionLengthSq (BYREF pQ AS D3DXQUATERNION) AS SINGLE
   IF VARPTR(pQ) = %NULL THEN EXIT FUNCTION
   FUNCTION = pQ.x * pQ.x + pQ.y * pQ.y + pQ.z * pQ.z + pQ.w * pQ.w
END FUNCTION

'D3DX10INLINE FLOAT D3DXQuaternionDot
'    ( CONST D3DXQUATERNION *pQ1, CONST D3DXQUATERNION *pQ2 )
'{
'#ifdef D3DX10_DEBUG
'    if(!pQ1 || !pQ2)
'        return 0.0f;
'#endif

'    return pQ1->x * pQ2->x + pQ1->y * pQ2->y + pQ1->z * pQ2->z + pQ1->w * pQ2->w;
'}

' Returns the dot product of two quaternions.
FUNCTION D3DXQuaternionDot (BYREF pQ1 AS D3DXQUATERNION, BYREF pQ2 AS D3DXQUATERNION) AS SINGLE
   IF VARPTR(pQ1) = %NULL OR VARPTR(pQ2) = %NULL THEN EXIT FUNCTION
   FUNCTION = pQ1.x * pQ2.x + pQ1.y * pQ2.y + pQ1.z * pQ2.z + pQ1.w * pQ2.w
END FUNCTION

'D3DX10INLINE D3DXQUATERNION* D3DXQuaternionIdentity
'    ( D3DXQUATERNION *pOut )
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut)
'        return NULL;
'#endif

'    pOut->x = pOut->y = pOut->z = 0.0f;
'    pOut->w = 1.0f;
'    return pOut;
'}

' Returns the identity quaternion.
SUB D3DXQuaternionIdentity (BYREF pOut AS D3DXQUATERNION)
   IF VARPTR(pOut) = %NULL THEN EXIT SUB
   pOut.x = 0.0!
   pOut.y = 0.0!
   pOut.z = 0.0!
   pOut.w = 1.0!
END SUB

'D3DX10INLINE BOOL D3DXQuaternionIsIdentity
'    ( CONST D3DXQUATERNION *pQ )
'{
'#ifdef D3DX10_DEBUG
'    if(!pQ)
'        return FALSE;
'#endif

'    return pQ->x == 0.0f && pQ->y == 0.0f && pQ->z == 0.0f && pQ->w == 1.0f;
'}

' Determines if a quaternion is an identity quaternion.
FUNCTION D3DXQuaternionIsIdentity (BYREF pQ AS D3DXQUATERNION) AS LONG
   IF VARPTR(pQ) = %NULL THEN EXIT FUNCTION
   FUNCTION = pQ.x = 0.0! AND pQ.y = 0.0! AND pQ.z = 0.0! AND pQ.w = 1.0!
END FUNCTION

'D3DX10INLINE D3DXQUATERNION* D3DXQuaternionConjugate
'    ( D3DXQUATERNION *pOut, CONST D3DXQUATERNION *pQ )
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pQ)
'        return NULL;
'#endif

'    pOut->x = -pQ->x;
'    pOut->y = -pQ->y;
'    pOut->z = -pQ->z;
'    pOut->w =  pQ->w;
'    return pOut;
'}

' Returns the conjugate of a quaternion.
SUB D3DXQuaternionConjugate (BYREF pOut AS D3DXQUATERNION, BYREF pQ AS D3DXQUATERNION)
   IF VARPTR(pOut) = %NULL OR VARPTR(pQ) = %NULL THEN EXIT SUB
   pOut.x = -pQ.x
   pOut.y = -pQ.y
   pOut.z = -pQ.z
   pOut.w =  pQ.w
END SUB

'//--------------------------
'// Plane
'//--------------------------

'D3DX10INLINE FLOAT D3DXPlaneDot
'    ( CONST D3DXPLANE *pP, CONST D3DXVECTOR4 *pV)
'{
'#ifdef D3DX10_DEBUG
'    if(!pP || !pV)
'        return 0.0f;
'#endif

'    return pP->a * pV->x + pP->b * pV->y + pP->c * pV->z + pP->d * pV->w;
'}

' Computes the dot product of a plane and a 4D vector.
FUNCTION D3DXPlaneDot (BYREF pP AS D3DXPLANE, BYREF pV AS D3DXVECTOR4) AS SINGLE
   IF VARPTR(pP) = %NULL OR VARPTR(pV) = %NULL THEN EXIT FUNCTION
   FUNCTION = pP.a * pV.x + pP.b * pV.y + pP.c * pV.z + pP.d * pV.w
END FUNCTION

'D3DX10INLINE FLOAT D3DXPlaneDotCoord
'    ( CONST D3DXPLANE *pP, CONST D3DXVECTOR3 *pV)
'{
'#ifdef D3DX10_DEBUG
'    if(!pP || !pV)
'        return 0.0f;
'#endif

'    return pP->a * pV->x + pP->b * pV->y + pP->c * pV->z + pP->d;
'}

' Computes the dot product of a plane and a 3D vector. The w parameter of the vector is assumed to be 1.
FUNCTION D3DXPlaneDotCoord (BYREF pP AS D3DXPLANE, BYREF pV AS D3DXVECTOR4) AS SINGLE
   IF VARPTR(pP) = %NULL OR VARPTR(pV) = %NULL THEN EXIT FUNCTION
   FUNCTION = pP.a * pV.x + pP.b * pV.y + pP.c * pV.z + pP.d
END FUNCTION

'D3DX10INLINE FLOAT D3DXPlaneDotNormal
'    ( CONST D3DXPLANE *pP, CONST D3DXVECTOR3 *pV)
'{
'#ifdef D3DX10_DEBUG
'    if(!pP || !pV)
'        return 0.0f;
'#endif

'    return pP->a * pV->x + pP->b * pV->y + pP->c * pV->z;
'}

' Computes the dot product of a plane and a 3D vector. The w parameter of the vector is assumed to be 0.
FUNCTION D3DXPlaneDotNormal (BYREF pP AS D3DXPLANE, BYREF pV AS D3DXVECTOR4) AS SINGLE
   IF VARPTR(pP) = %NULL OR VARPTR(pV) = %NULL THEN EXIT FUNCTION
   FUNCTION = pP.a * pV.x + pP.b * pV.y + pP.c * pV.z
END FUNCTION

'D3DX10INLINE D3DXPLANE* D3DXPlaneScale
'    (D3DXPLANE *pOut, CONST D3DXPLANE *pP, FLOAT s)
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pP)
'        return NULL;
'#endif

'    pOut->a = pP->a * s;
'    pOut->b = pP->b * s;
'    pOut->c = pP->c * s;
'    pOut->d = pP->d * s;
'    return pOut;
'}

' Scale the plane with the given scaling factor.
SUB D3DXPlaneScale (BYREF pOut AS D3DXPLANE, BYREF pP AS D3DXPLANE, BYVAL s AS SINGLE)
   IF VARPTR(pOut) = %NULL OR VARPTR(pP) = %NULL THEN EXIT SUB
   pOut.a = pP.a * s
   pOut.b = pP.b * s
   pOut.c = pP.c * s
   pOut.d = pP.d * s
END SUB

'//--------------------------
'// Color
'//--------------------------

'D3DX10INLINE D3DXCOLOR* D3DXColorNegative
'    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC)
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pC)
'        return NULL;
'#endif

'    pOut->r = 1.0f - pC->r;
'    pOut->g = 1.0f - pC->g;
'    pOut->b = 1.0f - pC->b;
'    pOut->a = pC->a;
'    return pOut;
'}

' Creates the negative color value of a color value.
SUB D3DXColorNegative (BYREF pOut AS D3DXCOLOR, BYREF pC AS D3DXCOLOR)
   IF VARPTR(pOut) = %NULL OR VARPTR(pC) = %NULL THEN EXIT SUB
   pOut.r = 1.0! - pC.r
   pOut.g = 1.0! - pC.g
   pOut.b = 1.0! - pC.b
   pOut.a = pC.a
END SUB

'D3DX10INLINE D3DXCOLOR* D3DXColorAdd
'    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC1, CONST D3DXCOLOR *pC2)
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pC1 || !pC2)
'        return NULL;
'#endif

'    pOut->r = pC1->r + pC2->r;
'    pOut->g = pC1->g + pC2->g;
'    pOut->b = pC1->b + pC2->b;
'    pOut->a = pC1->a + pC2->a;
'    return pOut;
'}

' Adds two color values together to create a new color value.
SUB D3DXColorAdd (BYREF pOut AS D3DXCOLOR, BYREF pC1 AS D3DXCOLOR, BYREF pC2 AS D3DXCOLOR)
   IF VARPTR(pOut) = %NULL OR VARPTR(pC1) = %NULL OR VARPTR(pC2) = %NULL THEN EXIT SUB
   pOut.r = pC1.r + pC2.r
   pOut.g = pC1.g + pC2.g
   pOut.b = pC1.b + pC2.b
   pOut.a = pC1.a + pC2.a
END SUB

'D3DX10INLINE D3DXCOLOR* D3DXColorSubtract
'    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC1, CONST D3DXCOLOR *pC2)
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pC1 || !pC2)
'        return NULL;
'#endif

'    pOut->r = pC1->r - pC2->r;
'    pOut->g = pC1->g - pC2->g;
'    pOut->b = pC1->b - pC2->b;
'    pOut->a = pC1->a - pC2->a;
'    return pOut;
'}

' Subtracts two color values to create a new color value.
SUB D3DXColorSubtract (BYREF pOut AS D3DXCOLOR, BYREF pC1 AS D3DXCOLOR, BYREF pC2 AS D3DXCOLOR)
   IF VARPTR(pOut) = %NULL OR VARPTR(pC1) = %NULL OR VARPTR(pC2) = %NULL THEN EXIT SUB
   pOut.r = pC1.r - pC2.r
   pOut.g = pC1.g - pC2.g
   pOut.b = pC1.b - pC2.b
   pOut.a = pC1.a - pC2.a
END SUB

'D3DX10INLINE D3DXCOLOR* D3DXColorScale
'    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC, FLOAT s)
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pC)
'        return NULL;
'#endif

'    pOut->r = pC->r * s;
'    pOut->g = pC->g * s;
'    pOut->b = pC->b * s;
'    pOut->a = pC->a * s;
'    return pOut;
'}

' Scales a color value.
SUB D3DXColorScale (BYREF pOut AS D3DXCOLOR, BYREF pC AS D3DXCOLOR, BYVAL s AS SINGLE)
   IF VARPTR(pOut) = %NULL OR VARPTR(pC) = %NULL THEN EXIT SUB
   pOut.r = pC.r * s
   pOut.g = pC.g * s
   pOut.b = pC.b * s
   pOut.a = pC.a * s
END SUB

'D3DX10INLINE D3DXCOLOR* D3DXColorModulate
'    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC1, CONST D3DXCOLOR *pC2)
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pC1 || !pC2)
'        return NULL;
'#endif

'    pOut->r = pC1->r * pC2->r;
'    pOut->g = pC1->g * pC2->g;
'    pOut->b = pC1->b * pC2->b;
'    pOut->a = pC1->a * pC2->a;
'    return pOut;
'}

' Blends two colors.
SUB D3DXColorModulate (BYREF pOut AS D3DXCOLOR, BYREF pC1 AS D3DXCOLOR, BYREF pC2 AS D3DXCOLOR)
   IF VARPTR(pOut) = %NULL OR VARPTR(pC1) = %NULL OR VARPTR(pC2) = %NULL THEN EXIT SUB
   pOut.r = pC1.r * pC2.r
   pOut.g = pC1.g * pC2.g
   pOut.b = pC1.b * pC2.b
   pOut.a = pC1.a * pC2.a
END SUB

'D3DX10INLINE D3DXCOLOR* D3DXColorLerp
'    (D3DXCOLOR *pOut, CONST D3DXCOLOR *pC1, CONST D3DXCOLOR *pC2, FLOAT s)
'{
'#ifdef D3DX10_DEBUG
'    if(!pOut || !pC1 || !pC2)
'        return NULL;
'#endif

'    pOut->r = pC1->r + s * (pC2->r - pC1->r);
'    pOut->g = pC1->g + s * (pC2->g - pC1->g);
'    pOut->b = pC1->b + s * (pC2->b - pC1->b);
'    pOut->a = pC1->a + s * (pC2->a - pC1->a);
'    return pOut;
'}

' Uses linear interpolation to create a color value.
SUB D3DXColorLerp (BYREF pOut AS D3DXCOLOR, BYREF pC1 AS D3DXCOLOR, BYREF pC2 AS D3DXCOLOR, BYVAL s AS SINGLE)
   IF VARPTR(pOut) = %NULL OR VARPTR(pC1) = %NULL OR VARPTR(pC2) = %NULL THEN EXIT SUB
   pOut.r = pC1.r + s * (pC2.r - pC1.r)
   pOut.g = pC1.g + s * (pC2.g - pC1.g)
   pOut.b = pC1.b + s * (pC2.b - pC1.b)
   pOut.a = pC1.a + s * (pC2.a - pC1.a)
END SUB
