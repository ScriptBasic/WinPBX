' ########################################################################################
' Microsoft Windows
' File: AppCompatApi.inc
' Contents: Appcompat procedure declarations, constant definitions and macros
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%APPCOMPATAPI_INC = 1

DECLARE FUNCTION ApphelpCheckShellObject IMPORT "APPHELP.DLL" ALIAS "ApphelpCheckShellObject" ( _
   BYREF ObjectCLSID AS GUID _                          ' __in  REFCLSID ObjectCLSID
 , BYVAL bShimIfNecessary AS LONG _                     ' __in  BOOL bShimIfNecessary
 , BYREF pullFlags AS QUAD _                            ' __out ULONGLONG* pullFlags
 ) AS LONG                                              ' BOOL
