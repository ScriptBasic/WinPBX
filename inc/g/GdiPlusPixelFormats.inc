' ########################################################################################
' Microsoft Windows
' File: GdiPlusPixelFormats.inc
' Contents: GDI+ Pixel Formats
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%GDIPLUSPIXELFORMATS_INC = 1

'typedef DWORD ARGB;
'typedef DWORDLONG ARGB64;

%ALPHA_SHIFT = 24
%RED_SHIFT   = 16
%GREEN_SHIFT = 8
%BLUE_SHIFT  = 0
'#define ALPHA_MASK  ((ARGB) 0xff << ALPHA_SHIFT)
%ALPHA_MASK  = &HFF000000

'// In-memory pixel data formats:
'// bits 0-7 = format index
'// bits 8-15 = pixel size (in bits)
'// bits 16-23 = flags
'// bits 24-31 = reserved

'typedef INT PixelFormat;

%PixelFormatIndexed      = &H00010000???  ' // Indexes into a palette
%PixelFormatGDI          = &H00020000???  ' // Is a GDI-supported format
%PixelFormatAlpha        = &H00040000???  ' // Has an alpha component
%PixelFormatPAlpha       = &H00080000???  ' // Pre-multiplied alpha
%PixelFormatExtended     = &H00100000???  ' // Extended color 16 bits/channel
%PixelFormatCanonical    = &H00200000???

%PixelFormatUndefined    = 0
%PixelFormatDontCare     = 0

'#define    PixelFormat1bppIndexed     (1 | ( 1 << 8) | PixelFormatIndexed | PixelFormatGDI)
'#define    PixelFormat4bppIndexed     (2 | ( 4 << 8) | PixelFormatIndexed | PixelFormatGDI)
'#define    PixelFormat8bppIndexed     (3 | ( 8 << 8) | PixelFormatIndexed | PixelFormatGDI)
'#define    PixelFormat16bppGrayScale  (4 | (16 << 8) | PixelFormatExtended)
'#define    PixelFormat16bppRGB555     (5 | (16 << 8) | PixelFormatGDI)
'#define    PixelFormat16bppRGB565     (6 | (16 << 8) | PixelFormatGDI)
'#define    PixelFormat16bppARGB1555   (7 | (16 << 8) | PixelFormatAlpha | PixelFormatGDI)
'#define    PixelFormat24bppRGB        (8 | (24 << 8) | PixelFormatGDI)
'#define    PixelFormat32bppRGB        (9 | (32 << 8) | PixelFormatGDI)
'#define    PixelFormat32bppARGB       (10 | (32 << 8) | PixelFormatAlpha | PixelFormatGDI | PixelFormatCanonical)
'#define    PixelFormat32bppPARGB      (11 | (32 << 8) | PixelFormatAlpha | PixelFormatPAlpha | PixelFormatGDI)
'#define    PixelFormat48bppRGB        (12 | (48 << 8) | PixelFormatExtended)
'#define    PixelFormat64bppARGB       (13 | (64 << 8) | PixelFormatAlpha  | PixelFormatCanonical | PixelFormatExtended)
'#define    PixelFormat64bppPARGB      (14 | (64 << 8) | PixelFormatAlpha  | PixelFormatPAlpha | PixelFormatExtended)
'#define    PixelFormat32bppCMYK       (15 | (32 << 8))
'#define    PixelFormatMax             16

%PixelFormat1bppIndexed    = 196865
%PixelFormat4bppIndexed    = 197634
%PixelFormat8bppIndexed    = 198659
%PixelFormat16bppGrayScale = 1052676
%PixelFormat16bppRGB555    = 135173
%PixelFormat16bppRGB565    = 135174
%PixelFormat16bppARGB1555  = 397319
%PixelFormat24bppRGB       = 137224
%PixelFormat32bppRGB       = 139273
%PixelFormat32bppARGB      = 2498570
%PixelFormat32bppPARGB     = 925707
%PixelFormat48bppRGB       = 1060876
%PixelFormat64bppARGB      = 3424269
%PixelFormat64bppPARGB     = 1851406
%PixelFormat32bppCMYK      = 8207
%PixelFormatMax            = 16

'inline UINT
'GetPixelFormatSize(
'                   PixelFormat pixfmt
'    )
'{
'    return (pixfmt >> 8) & 0xff;
'}

FUNCTION GdipGetPixelFormatSize (BYVAL pixfmt AS LONG) AS DWORD
   SHIFT RIGHT pixfmt, 8
   FUNCTION = pixfmt AND &HFF
END FUNCTION

'inline BOOL
'IsIndexedPixelFormat(
'                     PixelFormat pixfmt
'    )
'{
'    return (pixfmt & PixelFormatIndexed) != 0;
'}

FUNCTION GdipIsIndexedPixelFormat (BYVAL pixfmt AS LONG) AS LONG
   FUNCTION = (pixfmt AND %PixelFormatIndexed) <> 0
END FUNCTION

'inline BOOL
'IsAlphaPixelFormat(
'                     PixelFormat pixfmt
')
'{
'   return (pixfmt & PixelFormatAlpha) != 0;
'}

FUNCTION GdipIsAlphaPixelFormat (BYVAL pixfmt AS LONG) AS LONG
   FUNCTION = (pixfmt AND %PixelFormatAlpha) <> 0
END FUNCTION

'inline BOOL
'IsExtendedPixelFormat(
'                     PixelFormat pixfmt
'    )
'{
'   return (pixfmt & PixelFormatExtended) != 0;
'}

FUNCTION GdipIsExtendedPixelFormat (BYVAL pixfmt AS LONG) AS LONG
   FUNCTION = (pixfmt AND %PixelFormatExtended) <> 0
END FUNCTION

'//--------------------------------------------------------------------------
'// Determine if the Pixel Format is Canonical format:
'//   PixelFormat32bppARGB
'//   PixelFormat32bppPARGB
'//   PixelFormat64bppARGB
'//   PixelFormat64bppPARGB
'//--------------------------------------------------------------------------

'inline BOOL
'IsCanonicalPixelFormat(
'                     PixelFormat pixfmt
'    )
'{
'   return (pixfmt & PixelFormatCanonical) != 0;
'}

FUNCTION GdipIsCanonicalPixelFormat (BYVAL pixfmt AS LONG) AS LONG
   FUNCTION = (pixfmt AND %PixelFormatCanonical) <> 0
END FUNCTION

#IF (%GDIPVER >= &H0110)
'//----------------------------------------------------------------------------
'// Color format conversion parameters
'//----------------------------------------------------------------------------

' enum PaletteType

'// Arbitrary custom palette provided by caller.

%PaletteTypeCustom           = 0

'// Optimal palette generated using a median-cut algorithm.

%PaletteTypeOptimal          = 1

'// Black and white palette.

%PaletteTypeFixedBW          = 2

'// Symmetric halftone palettes.
'// Each of these halftone palettes will be a superset of the system palette.
'// E.g. Halftone8 will have it's 8-color on-off primaries and the 16 system
'// colors added. With duplicates removed, that leaves 16 colors.

%PaletteTypeFixedHalftone8   = 3 ' // 8-color, on-off primaries
%PaletteTypeFixedHalftone27  = 4 ' // 3 intensity levels of each color
%PaletteTypeFixedHalftone64  = 5 ' // 4 intensity levels of each color
%PaletteTypeFixedHalftone125 = 6 ' // 5 intensity levels of each color
%PaletteTypeFixedHalftone216 = 7 ' // 6 intensity levels of each color

'// Assymetric halftone palettes.
'// These are somewhat less useful than the symmetric ones, but are
'// included for completeness. These do not include all of the system
'// colors.

%PaletteTypeFixedHalftone252 = 8  ' // 6-red, 7-green, 6-blue intensities
%PaletteTypeFixedHalftone256 = 9  ' // 8-red, 8-green, 4-blue intensities

' enum DitherType

%DitherTypeNone          = 0

'// Solid color - picks the nearest matching color with no attempt to
'// halftone or dither. May be used on an arbitrary palette.

%DitherTypeSolid         = 1

'// Ordered dithers and spiral dithers must be used with a fixed palette.

'// NOTE: DitherOrdered4x4 is unique in that it may apply to 16bpp
'// conversions also.

%DitherTypeOrdered4x4    = 2

%DitherTypeOrdered8x8    = 3
%DitherTypeOrdered16x16  = 4
%DitherTypeSpiral4x4     = 5
%DitherTypeSpiral8x8     = 6
%DitherTypeDualSpiral4x4 = 7
%DitherTypeDualSpiral8x8 = 8

'// Error diffusion. May be used with any palette.

%DitherTypeErrorDiffusion   = 9

%DitherTypeMax              = 10

#ENDIF   ' //(%GDIPVER >= &H0110)

' enum PaletteFlags
%PaletteFlagsHasAlpha    = &H0001
%PaletteFlagsGrayScale   = &H0002
%PaletteFlagsHalftone    = &H0004

'struct ColorPalette
'{
'public:
'    UINT Flags;             // Palette flags
'    UINT Count;             // Number of color entries
'    ARGB Entries[1];        // Palette color entries
'};

' Note: Entries is a variable-length array, but since PB doesn't allow variable-length
' arrays in structures it has been dimensioned to hold 256 entries (the maximum).
' // Size = 1032 bytes
TYPE ColorPalette DWORD
   Flags AS DWORD           '  // Palette flags
   Count AS DWORD           '  // Number of color entries
   Entries(255) AS DWORD    '  // Palette color entries (256 entries)
END TYPE

' enum PaletteType
' The PaletteType enumeration is used by the GdipInitializePalette and
' GdipBitmapConvertFormat functions. The members of the enumeration identify
' several standard color palette formats.

%PaletteTypeCustom           = 0
%PaletteTypeOptimal          = 1
%PaletteTypeFixedBW          = 2
%PaletteTypeFixedHalftone8   = 3
%PaletteTypeFixedHalftone27  = 4
%PaletteTypeFixedHalftone64  = 5
%PaletteTypeFixedHalftone125 = 6
%PaletteTypeFixedHalftone216 = 7
%PaletteTypeFixedHalftone252 = 8
%PaletteTypeFixedHalftone256 = 9

' enum ItemDataPosition
' The ItemDataPosition enumeration is used to specify the location of
' custom metadata in an image file.

%ItemDataPositionAfterHeader  = &H0
%ItemDataPositionAfterPalette = &H1
%ItemDataPositionAfterBits    = &H2
