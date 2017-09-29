' ########################################################################################
' Microsoft Windows
' File: GdiPlusMem.inc
' Contents: GDI+ Private Memory Management APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%GDIPLUSMEM_INC = 1

'//----------------------------------------------------------------------------
'// Memory Allocation APIs
'//----------------------------------------------------------------------------

DECLARE FUNCTION GdipAlloc IMPORT "GDIPLUS.DLL" ALIAS "GdipAlloc" ( _
   BYVAL size AS DWORD _                                ' __in size_t size
 ) AS DWORD                                             ' void*

DECLARE SUB GdipFree IMPORT "GDIPLUS.DLL" ALIAS "GdipFree" ( _
   BYVAL ptr AS DWORD _                                 ' __in void *ptr
 )                                                      ' void
