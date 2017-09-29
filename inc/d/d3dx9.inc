' ########################################################################################
' Microsoft Windows
' File: d3dx9.inc
' Contents: D3DX utility library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3DX9_INC = 1

#INCLUDE ONCE "windows.inc"

'// Defines
'#include <limits.h>

%D3DX_DEFAULT = &HFFFFFFFF???   ' ((UINT) -1)
%D3DX_DEFAULT_NONPOW2 = &HFFFFFFFE???   ' ((UINT) -2)
MACRO D3DX_DEFAULT_FLOAT = 3.402823466e+38   ' FLT_MAX
%D3DX_FROM_FILE = &HFFFFFFFD???   ' ((UINT) -3)
%D3DFMT_FROM_FILE = &HFFFFFFFD???   ' ((D3DFORMAT) -3)

'// Includes

#IF NOT %DEF($D3DX_DLLNAME)
' DirectX End-User Runtimes (June 2010)
' http://www.microsoft.com/download/en/confirmation.aspx?id=8109
$D3DX_DLLNAME = "d3dx9_43.dll"   ' --> change as needed
#ENDIF

#INCLUDE ONCE "d3dxerr.inc"   ' not included in the latest SDK
#INCLUDE ONCE "d3d9.inc"
#INCLUDE ONCE "d3dx9math.inc"
#INCLUDE ONCE "d3dx9core.inc"
#INCLUDE ONCE "d3dx9xof.inc"
#INCLUDE ONCE "d3dx9mesh.inc"
#INCLUDE ONCE "d3dx9shader.inc"
#INCLUDE ONCE "d3dx9effect.inc"
#INCLUDE ONCE "d3dx9tex.inc"
#INCLUDE ONCE "d3dx9shape.inc"
#INCLUDE ONCE "d3dx9anim.inc"

'// Errors
'#define _FACDD  0x876
'#define MAKE_DDHRESULT( code )  MAKE_HRESULT( 1, _FACDD, code )

%FACDD = &H876
MACRO MAKE_DDHRESULT(code) = MAKE_HRESULT(1,%FACDD,code)

'enum _D3DXERR {
%D3DXERR_CANNOTMODIFYINDEXBUFFER     = &H88760B54   ' MAKE_DDHRESULT(2900)
%D3DXERR_INVALIDMESH                 = &H88760B55   ' MAKE_DDHRESULT(2901)
%D3DXERR_CANNOTATTRSORT              = &H88760B56   ' MAKE_DDHRESULT(2902)
%D3DXERR_SKINNINGNOTSUPPORTED        = &H88760B57   ' MAKE_DDHRESULT(2903)
%D3DXERR_TOOMANYINFLUENCES           = &H88760B58   ' MAKE_DDHRESULT(2904)
%D3DXERR_INVALIDDATA                 = &H88760B59   ' MAKE_DDHRESULT(2905)
%D3DXERR_LOADEDMESHASNODATA          = &H88760B5A   ' MAKE_DDHRESULT(2906)
%D3DXERR_DUPLICATENAMEDFRAGMENT      = &H88760B5B   ' MAKE_DDHRESULT(2907)
%D3DXERR_CANNOTREMOVELASTITEM        = &H88760B5C   ' MAKE_DDHRESULT(2908)
