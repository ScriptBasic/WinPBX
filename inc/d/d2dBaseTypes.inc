' ########################################################################################
' Microsoft Windows
' File: D2DBaseTypes.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D2DBASETYPES_INC = 1

'#ifndef COM_NO_WINDOWS_H
'#include <windows.h>
'#endif // #ifndef COM_NO_WINDOWS_H

#INCLUDE ONCE "windows.inc"

'#ifndef D3DCOLORVALUE_DEFINED

'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D3DCOLORVALUE
'//
'//------------------------------------------------------------------------------
'typedef struct D3DCOLORVALUE
'{
'    FLOAT r;
'    FLOAT g;
'    FLOAT b;
'    FLOAT a;

'} D3DCOLORVALUE;

'#define D3DCOLORVALUE_DEFINED
'#endif

#IF NOT %DEF(%D3DCOLORVALUE_DEFINED)
' // Size = 16 bytes
TYPE D3DCOLORVALUE DWORD
   r AS SINGLE
   g AS SINGLE
   b AS SINGLE
   a AS SINGLE
END TYPE
%D3DCOLORVALUE_DEFINED = 1
#ENDIF


'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D_POINT_2U
'//
'//------------------------------------------------------------------------------
'typedef struct D2D_POINT_2U
'{
'    UINT32 x;
'    UINT32 y;

'} D2D_POINT_2U;

' // Size = 8 bytes
TYPE D2D_POINT_2U DWORD
   x AS DWORD   ' UINT32
   y AS DWORD   ' UINT32
END TYPE

'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D_POINT_2F
'//
'//------------------------------------------------------------------------------
'typedef struct D2D_POINT_2F
'{
'    FLOAT x;
'    FLOAT y;

'} D2D_POINT_2F;

' // Size = 8 bytes
TYPE D2D_POINT_2F DWORD
   x AS SINGLE   ' FLOAT
   y AS SINGLE   ' FLOAT
END TYPE

'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D_RECT_F
'//
'//------------------------------------------------------------------------------
'typedef struct D2D_RECT_F
'{
'    FLOAT left;
'    FLOAT top;
'    FLOAT right;
'    FLOAT bottom;

'} D2D_RECT_F;

' // Size = 16 bytes
TYPE D2D_RECT_F DWORD
   left   AS SINGLE   ' FLOAT
   top    AS SINGLE   ' FLOAT
   right  AS SINGLE   ' FLOAT
   bottom AS SINGLE   ' FLOAT
END TYPE

'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D_RECT_U
'//
'//------------------------------------------------------------------------------
'typedef struct D2D_RECT_U
'{
'    UINT32 left;
'    UINT32 top;
'    UINT32 right;
'    UINT32 bottom;

'} D2D_RECT_U;

' // Size = 16 bytes
TYPE D2D_RECT_U DWORD
   left   AS DWORD   ' UINT32
   top    AS DWORD   ' UINT32
   right  AS DWORD   ' UINT32
   bottom AS DWORD   ' UINT32
END TYPE

'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D_SIZE_F
'//
'//------------------------------------------------------------------------------
'typedef struct D2D_SIZE_F
'{
'    FLOAT width;
'    FLOAT height;

'} D2D_SIZE_F;

' // Size = 8 bytes
TYPE D2D_SIZE_F DWORD
   width  AS SINGLE   ' FLOAT
   height AS SINGLE   ' FLOAT
END TYPE

'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D_SIZE_U
'//
'//------------------------------------------------------------------------------
'typedef struct D2D_SIZE_U
'{
'    UINT32 width;
'    UINT32 height;

'} D2D_SIZE_U;

' // Size = 8 bytes
TYPE D2D_SIZE_U DWORD
   width  AS DWORD   ' UINT32
   height AS DWORD   ' UINT32
END TYPE

'typedef D3DCOLORVALUE D2D_COLOR_F;
MACRO D2D_COLOR_F = D3DCOLORVALUE

'//+-----------------------------------------------------------------------------
'//
'//  Struct:
'//      D2D_MATRIX_3X2_F
'//
'//------------------------------------------------------------------------------
'typedef struct D2D_MATRIX_3X2_F
'{
'    FLOAT _11;
'    FLOAT _12;
'    FLOAT _21;
'    FLOAT _22;
'    FLOAT _31;
'    FLOAT _32;

'} D2D_MATRIX_3X2_F;

' // Size = 24 bytes
TYPE D2D_MATRIX_3X2_F DWORD
   m11 AS SINGLE   ' FLOAT
   m12 AS SINGLE   ' FLOAT
   m21 AS SINGLE   ' FLOAT
   m22 AS SINGLE   ' FLOAT
   m31 AS SINGLE   ' FLOAT
   m32 AS SINGLE   ' FLOAT
END TYPE
