' ########################################################################################
' Microsoft Windows
' File: d3dx10.inc
' Contents: D3DX10 utility library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3DX10_INC = 1

'// Defines
'#include <limits.h>
'#include <float.h>

%D3DX10_DEFAULT           = &HFFFFFFFF???   ' ((UINT) -1)
%D3DX10_FROM_FILE         = &HFFFFFFFD???   ' ((UINT) -3)
%DXGI_FORMAT_FROM_FILE    = &HFFFFFFFD???   ' ((DXGI_FORMAT) -3)

'// Includes

#INCLUDE ONCE "d3d10.inc"
#INCLUDE ONCE "d3dx10math.inc"
#INCLUDE ONCE "d3dx10core.inc"
#INCLUDE ONCE "d3dx10tex.inc"
#INCLUDE ONCE "d3dx10mesh.inc"
#INCLUDE ONCE "d3dx10async.inc"

'// Errors
%FACDD  = &H876
'#define MAKE_DDHRESULT( code )  MAKE_HRESULT( 1, _FACDD, code )
MACRO MAKE_DDHRESULT (code) = MAKE_HRESULT(1, %FACDD, code)

' enum D3DX10_ERR
%D3DX10_ERR_CANNOT_MODIFY_INDEX_BUFFER       = &H88760B54&   ' MAKE_DDHRESULT(2900)
%D3DX10_ERR_INVALID_MESH                     = &H88760B55&   ' MAKE_DDHRESULT(2901)
%D3DX10_ERR_CANNOT_ATTR_SORT                 = &H88760B56&   ' MAKE_DDHRESULT(2902)
%D3DX10_ERR_SKINNING_NOT_SUPPORTED           = &H88760B57&   ' MAKE_DDHRESULT(2903)
%D3DX10_ERR_TOO_MANY_INFLUENCES              = &H88760B58&   ' MAKE_DDHRESULT(2904)
%D3DX10_ERR_INVALID_DATA                     = &H88760B59&   ' MAKE_DDHRESULT(2905)
%D3DX10_ERR_LOADED_MESH_HAS_NO_DATA          = &H88760B5A&   ' MAKE_DDHRESULT(2906)
%D3DX10_ERR_DUPLICATE_NAMED_FRAGMENT         = &H88760B5B&   ' MAKE_DDHRESULT(2907)
%D3DX10_ERR_CANNOT_REMOVE_LAST_ITEM          = &H88760B5C&   ' MAKE_DDHRESULT(2908)
