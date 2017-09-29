' ########################################################################################
' Microsoft Windows
' File: D3DCommon.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%D3DCOMMON_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

' enum D3D_DRIVER_TYPE
%D3D_DRIVER_TYPE_UNKNOWN   = 0
%D3D_DRIVER_TYPE_HARDWARE  = %D3D_DRIVER_TYPE_UNKNOWN   + 1
%D3D_DRIVER_TYPE_REFERENCE = %D3D_DRIVER_TYPE_HARDWARE  + 1
%D3D_DRIVER_TYPE_NULL      = %D3D_DRIVER_TYPE_REFERENCE + 1
%D3D_DRIVER_TYPE_SOFTWARE  = %D3D_DRIVER_TYPE_NULL      + 1
%D3D_DRIVER_TYPE_WARP      = %D3D_DRIVER_TYPE_SOFTWARE  + 1

' enum D3D_FEATURE_LEVEL
%D3D_FEATURE_LEVEL_9_1  = &H9100???
%D3D_FEATURE_LEVEL_9_2  = &H9200???
%D3D_FEATURE_LEVEL_9_3  = &H9300???
%D3D_FEATURE_LEVEL_10_0 = &Ha000???
%D3D_FEATURE_LEVEL_10_1 = &Ha100???
%D3D_FEATURE_LEVEL_11_0 = &Hb000???

$WKPDID_D3DDebugObjectName = GUID$("{429B8C22-9188-4B0C-8742-ACB0BF85C200}")
