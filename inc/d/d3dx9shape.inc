' ########################################################################################
' Microsoft Windows
' File: d3dx9shape.inc
' Contents: D3DX simple shapes
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3DX9SHAPE_INC = 1

#INCLUDE ONCE "d3dx9.inc"

'///////////////////////////////////////////////////////////////////////////
'// Functions:
'///////////////////////////////////////////////////////////////////////////

'//-------------------------------------------------------------------------
'// D3DXCreatePolygon:
'// ------------------
'// Creates a mesh containing an n-sided polygon.  The polygon is centered
'// at the origin.
'//
'// Parameters:
'//
'//  pDevice     The D3D device with which the mesh is going to be used.
'//  Length      Length of each side.
'//  Sides       Number of sides the polygon has.  (Must be >= 3)
'//  ppMesh      The mesh object which will be created
'//  ppAdjacency Returns a buffer containing adjacency info.  Can be NULL.
'//-------------------------------------------------------------------------

DECLARE FUNCTION D3DXCreatePolygon IMPORT $D3DX_DLLNAME ALIAS "D3DXCreatePolygon" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9   pDevice
 , BYVAL Length AS SINGLE _                             ' __in  FLOAT               Length
 , BYVAL Sides AS DWORD _                               ' __in  UINT                Sides
 , BYREF ppMesh AS ID3DXMesh _                          ' __out LPD3DXMESH*         ppMesh
 , BYREF ppAdjacency AS ID3DXBuffer _                   ' __out LPD3DXBUFFER*       ppAdjacency
 ) AS LONG                                              ' HRESULT


'//-------------------------------------------------------------------------
'// D3DXCreateBox:
'// --------------
'// Creates a mesh containing an axis-aligned box.  The box is centered at
'// the origin.
'//
'// Parameters:
'//
'//  pDevice     The D3D device with which the mesh is going to be used.
'//  Width       Width of box (along X-axis)
'//  Height      Height of box (along Y-axis)
'//  Depth       Depth of box (along Z-axis)
'//  ppMesh      The mesh object which will be created
'//  ppAdjacency Returns a buffer containing adjacency info.  Can be NULL.
'//-------------------------------------------------------------------------

DECLARE FUNCTION D3DXCreateBox IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateBox" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9   pDevice
 , BYVAL Width AS SINGLE _                              ' __in  FLOAT               Width
 , BYVAL Height AS SINGLE _                             ' __in  FLOAT               Height
 , BYVAL Depth AS SINGLE _                              ' __in  FLOAT               Depth
 , BYREF ppMesh AS ID3DXMesh _                          ' __out LPD3DXMESH*         ppMesh
 , BYREF ppAdjacency AS ID3DXBuffer _                   ' __out LPD3DXBUFFER*       ppAdjacency
 ) AS LONG                                              ' HRESULT

'//-------------------------------------------------------------------------
'// D3DXCreateCylinder:
'// -------------------
'// Creates a mesh containing a cylinder.  The generated cylinder is
'// centered at the origin, and its axis is aligned with the Z-axis.
'//
'// Parameters:
'//
'//  pDevice     The D3D device with which the mesh is going to be used.
'//  Radius1     Radius at -Z end (should be >= 0.0f)
'//  Radius2     Radius at +Z end (should be >= 0.0f)
'//  Length      Length of cylinder (along Z-axis)
'//  Slices      Number of slices about the main axis
'//  Stacks      Number of stacks along the main axis
'//  ppMesh      The mesh object which will be created
'//  ppAdjacency Returns a buffer containing adjacency info.  Can be NULL.
'//-------------------------------------------------------------------------

DECLARE FUNCTION D3DXCreateCylinder IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateCylinder" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9   pDevice
 , BYVAL Radius1 AS SINGLE _                            ' __in  FLOAT               Radius1
 , BYVAL Radius2 AS SINGLE _                            ' __in  FLOAT               Radius2
 , BYVAL Length AS SINGLE _                             ' __in  FLOAT               Length
 , BYVAL Slices AS DWORD _                              ' __in  UINT                Slices
 , BYVAL Stacks AS DWORD _                              ' __in  UINT                Stacks
 , BYREF ppMesh AS ID3DXMesh _                          ' __out LPD3DXMESH*         ppMesh
 , BYREF ppAdjacency AS ID3DXBuffer _                   ' __out LPD3DXBUFFER*       ppAdjacency
 ) AS LONG                                              ' HRESULT


'//-------------------------------------------------------------------------
'// D3DXCreateSphere:
'// -----------------
'// Creates a mesh containing a sphere.  The sphere is centered at the
'// origin.
'//
'// Parameters:
'//
'//  pDevice     The D3D device with which the mesh is going to be used.
'//  Radius      Radius of the sphere (should be >= 0.0f)
'//  Slices      Number of slices about the main axis
'//  Stacks      Number of stacks along the main axis
'//  ppMesh      The mesh object which will be created
'//  ppAdjacency Returns a buffer containing adjacency info.  Can be NULL.
'//-------------------------------------------------------------------------

DECLARE FUNCTION D3DXCreateSphere IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateSphere" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9  pDevice
 , BYVAL Radius AS SINGLE _                             ' __in  FLOAT              Radius
 , BYVAL Slices AS DWORD _                              ' __in  UINT               Slices
 , BYVAL Stacks AS DWORD _                              ' __in  UINT               Stacks
 , BYREF ppMesh AS ID3DXMesh _                          ' __out LPD3DXMESH*        ppMesh
 , BYREF ppAdjacency AS ID3DXBuffer _                   ' __out LPD3DXBUFFER*      ppAdjacency
 ) AS LONG                                              ' HRESULT


'//-------------------------------------------------------------------------
'// D3DXCreateTorus:
'// ----------------
'// Creates a mesh containing a torus.  The generated torus is centered at
'// the origin, and its axis is aligned with the Z-axis.
'//
'// Parameters:
'//
'//  pDevice     The D3D device with which the mesh is going to be used.
'//  InnerRadius Inner radius of the torus (should be >= 0.0f)
'//  OuterRadius Outer radius of the torue (should be >= 0.0f)
'//  Sides       Number of sides in a cross-section (must be >= 3)
'//  Rings       Number of rings making up the torus (must be >= 3)
'//  ppMesh      The mesh object which will be created
'//  ppAdjacency Returns a buffer containing adjacency info.  Can be NULL.
'//-------------------------------------------------------------------------

DECLARE FUNCTION D3DXCreateTorus IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateTorus" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9   pDevice
 , BYVAL InnerRadius AS SINGLE _                        ' __in  FLOAT               InnerRadius
 , BYVAL OuterRadius AS SINGLE _                        ' __in  FLOAT               OuterRadius
 , BYVAL Sides AS DWORD _                               ' __in  UINT                Sides
 , BYVAL Rings AS DWORD _                               ' __in  UINT                Rings
 , BYREF ppMesh AS ID3DXMesh _                          ' __out LPD3DXMESH*         ppMesh
 , BYREF ppAdjacency AS ID3DXBuffer _                   ' __out LPD3DXBUFFER*       ppAdjacency
 ) AS LONG                                              ' HRESULT


'//-------------------------------------------------------------------------
'// D3DXCreateTeapot:
'// -----------------
'// Creates a mesh containing a teapot.
'//
'// Parameters:
'//
'//  pDevice     The D3D device with which the mesh is going to be used.
'//  ppMesh      The mesh object which will be created
'//  ppAdjacency Returns a buffer containing adjacency info.  Can be NULL.
'//-------------------------------------------------------------------------

DECLARE FUNCTION D3DXCreateTeapot IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateTeapot" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9   pDevice
 , BYREF ppMesh AS ID3DXMesh _                          ' __out LPD3DXMESH*         ppMesh
 , BYREF ppAdjacency AS ID3DXBuffer _                   ' __out LPD3DXBUFFER*       ppAdjacency
 ) AS LONG                                              ' HRESULT


'//-------------------------------------------------------------------------
'// D3DXCreateText:
'// ---------------
'// Creates a mesh containing the specified text using the font associated
'// with the device context.
'//
'// Parameters:
'//
'//  pDevice       The D3D device with which the mesh is going to be used.
'//  hDC           Device context, with desired font selected
'//  pText         Text to generate
'//  Deviation     Maximum chordal deviation from true font outlines
'//  Extrusion     Amount to extrude text in -Z direction
'//  ppMesh        The mesh object which will be created
'//  pGlyphMetrics Address of buffer to receive glyph metric data (or NULL)
'//-------------------------------------------------------------------------

DECLARE FUNCTION D3DXCreateTextA IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateTextA" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9   pDevice
 , BYVAL hDC AS DWORD _                                 ' __in  HDC                 hDC
 , BYREF pText AS ASCIIZ _                              ' __in  LPCSTR              pText
 , BYVAL Deviation AS SINGLE _                          ' __in  FLOAT               Deviation
 , BYVAL Extrusion AS SINGLE _                          ' __in  FLOAT               Extrusion
 , BYREF ppMesh AS ID3DXMesh _                          ' __out LPD3DXMESH*         ppMesh
 , BYREF ppAdjacency AS ID3DXBuffer _                   ' __out LPD3DXBUFFER*       ppAdjacency
 , BYREF pGlyphMetrics AS GLYPHMETRICSFLOAT _           ' __out LPGLYPHMETRICSFLOAT pGlyphMetrics
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION D3DXCreateTextW IMPORT $D3DX_DLLNAME ALIAS "D3DXCreateTextW" (_
   BYVAL pDevice AS IDirect3DDevice9 _                  ' __in  LPDIRECT3DDEVICE9   pDevice
 , BYVAL hDC AS DWORD _                                 ' __in  HDC                 hDC
 , BYREF pText AS WSTRING _                             ' __in  LPCWSTR             pText
 , BYVAL Deviation AS SINGLE _                          ' __in  FLOAT               Deviation
 , BYVAL Extrusion AS SINGLE _                          ' __in  FLOAT               Extrusion
 , BYREF ppMesh AS ID3DXMesh _                          ' __out LPD3DXMESH*         ppMesh
 , BYREF ppAdjacency AS ID3DXBuffer _                   ' __out LPD3DXBUFFER*       ppAdjacency
 , BYREF pGlyphMetrics AS GLYPHMETRICSFLOAT _           ' __out LPGLYPHMETRICSFLOAT pGlyphMetrics
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO D3DXCreateText = D3DXCreateTextW
#ELSE
   MACRO D3DXCreateText = D3DXCreateTextA
#ENDIF
