' ########################################################################################
' Microsoft Windows
' File: GdiPlus.inc
' Contents: GDI+ public header file
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%GDIPLUS_INC = 1

'struct IDirectDrawSurface7;

'// Define the Current GDIPlus Version
#IF NOT %DEF(%GDIPVER)
%GDIPVER = &H0110
#ENDIF

'typedef signed   short   INT16;
'typedef unsigned short  UINT16;

#INCLUDE ONCE "Windows.inc"
#INCLUDE ONCE "GdiplusMem.inc"
#INCLUDE ONCE "GdiplusEnums.inc"
#INCLUDE ONCE "GdiplusTypes.inc"
#INCLUDE ONCE "GdiplusInit.inc"
#INCLUDE ONCE "GdiplusPixelFormats.inc"
#INCLUDE ONCE "GdiplusColor.inc"
#INCLUDE ONCE "GdiplusMetaHeader.inc"
#INCLUDE ONCE "GdiplusImaging.inc"
#INCLUDE ONCE "GdiplusColorMatrix.inc"
#IF (%GDIPVER >= &H0110)
#INCLUDE ONCE "GdiplusEffects.inc"
#ENDIF
#INCLUDE ONCE "GdiplusFlat.inc"

' // Helper functions
#INCLUDE ONCE "GDIPUTILS.INC"
