' ########################################################################################
' Microsoft Windows
' File: GdiplusColorMatrix.inc
' Contents: GDI+ Color Matrix structures and constants
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%GDIPLUSCOLORMATRIX_INC = 1

#IF (%GDIPVER >= &H0110)
'//----------------------------------------------------------------------------
'// Color channel look up table (LUT)
'//----------------------------------------------------------------------------

'typedef BYTE ColorChannelLUT[256];

'//----------------------------------------------------------------------------
'// Per-channel Histogram for 8bpp images.
'//----------------------------------------------------------------------------

'enum HistogramFormat
%HistogramFormatARGB  = 0
%HistogramFormatPARGB = 1
%HistogramFormatRGB   = 2
%HistogramFormatGray  = 3
%HistogramFormatB     = 4
%HistogramFormatG     = 5
%HistogramFormatR     = 6
%HistogramFormatA     = 7

#ENDIF   ' //(%GDIPVER >= &H0110)

'//----------------------------------------------------------------------------
'// Color matrix
'//----------------------------------------------------------------------------

' // Size = 100 bytes
TYPE ColorMatrix DWORD
   m (4, 4) AS SINGLE   ' REAL[5,5]
END TYPE

'//----------------------------------------------------------------------------
'// Color Matrix flags
'//----------------------------------------------------------------------------

' enum ColorMatrixFlags
%ColorMatrixFlagsDefault   = 0
%ColorMatrixFlagsSkipGrays = 1
%ColorMatrixFlagsAltGray   = 2

'//----------------------------------------------------------------------------
'// Color Adjust Type
'//----------------------------------------------------------------------------

'enum ColorAdjustType
%ColorAdjustTypeDefault = 0
%ColorAdjustTypeBitmap  = 1
%ColorAdjustTypeBrush   = 2
%ColorAdjustTypePen     = 3
%ColorAdjustTypeText    = 4
%ColorAdjustTypeCount   = 5
%ColorAdjustTypeAny     = 6  ' Reserved

'//----------------------------------------------------------------------------
'// Color Map
'//----------------------------------------------------------------------------

'struct ColorMap
'{
'    Color oldColor;
'    Color newColor;
'};

' // The name conflicts with the ColorMap structure defined in COMMCTRL.INC.
' // Changed to a union in COMMCTRL.INC to allow to use ColorMap with GDI+.
' // Size = 8 bytes
TYPE GDIP_COLORMAP DWORD
   oldColor AS DWORD   ' Color
   newColor AS DWORD   ' Color
END TYPE
MACRO GpColorMap = GDIP_COLORMAP
