' ########################################################################################
' Microsoft Windows
' File: propapi.inc
' Contents: Structured storage properties APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PROPAPI_INC = 1

'typedef VOID* NTPROP;

#INCLUDE ONCE "propidl.inc"

DECLARE FUNCTION StgPropertyLengthAsVariant IMPORT "OLE32.DLL" ALIAS "StgPropertyLengthAsVariant" ( _
   BYREF pProp AS ANY _                                 ' __in const SERIALIZEDPROPERTYVALUE* pProp
 , BYVAL cbProp AS DWORD _                              ' __in ULONG cbProp
 , BYVAL CodePage AS WORD _                             ' __in USHORT CodePage
 , BYVAL bReserved AS BYTE _                            ' __reserved BYTE bReserved
 ) AS DWORD                                             ' ULONG
