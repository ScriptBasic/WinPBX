' ########################################################################################
' Microsoft Windows
' File: dwrite.inc
' Contents: DirectX Typography Services public API definitions.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' Note: Do not include this file directly because d2d1.inc must be included first, but can't
' be done here. Include d2d1.inc instead.

#INCLUDE THIS ONCE
%DWRITE_INC = 1

'#ifndef DWRITE_NO_WINDOWS_H

'#include <specstrings.h>
'#include <unknwn.h>

'#endif // DWRITE_NO_WINDOWS_H

#INCLUDE ONCE "dcommon.inc"

' enum DWRITE_FONT_FILE_TYPE
%DWRITE_FONT_FILE_TYPE_UNKNOWN             = 0
%DWRITE_FONT_FILE_TYPE_CFF                 = 1
%DWRITE_FONT_FILE_TYPE_TRUETYPE            = 2
%DWRITE_FONT_FILE_TYPE_TRUETYPE_COLLECTION = 3
%DWRITE_FONT_FILE_TYPE_TYPE1_PFM           = 4
%DWRITE_FONT_FILE_TYPE_TYPE1_PFB           = 5
%DWRITE_FONT_FILE_TYPE_VECTOR              = 6
%DWRITE_FONT_FILE_TYPE_BITMAP              = 7

' enum DWRITE_FONT_FACE_TYPE
%DWRITE_FONT_FACE_TYPE_CFF                 = 0
%DWRITE_FONT_FACE_TYPE_TRUETYPE            = 1
%DWRITE_FONT_FACE_TYPE_TRUETYPE_COLLECTION = 2
%DWRITE_FONT_FACE_TYPE_TYPE1               = 3
%DWRITE_FONT_FACE_TYPE_VECTOR              = 4
%DWRITE_FONT_FACE_TYPE_BITMAP              = 5
%DWRITE_FONT_FACE_TYPE_UNKNOWN             = 6

' enum DWRITE_FONT_SIMULATIONS
%DWRITE_FONT_SIMULATIONS_NONE    = &H0000???
%DWRITE_FONT_SIMULATIONS_BOLD    = &H0001???
%DWRITE_FONT_SIMULATIONS_OBLIQUE = &H0002???

'#ifdef DEFINE_ENUM_FLAG_OPERATORS
'DEFINE_ENUM_FLAG_OPERATORS(DWRITE_FONT_SIMULATIONS);
'#endif

' enum DWRITE_FONT_WEIGHT
%DWRITE_FONT_WEIGHT_THIN        = 100
%DWRITE_FONT_WEIGHT_EXTRA_LIGHT = 200
%DWRITE_FONT_WEIGHT_ULTRA_LIGHT = 200
%DWRITE_FONT_WEIGHT_LIGHT       = 300
%DWRITE_FONT_WEIGHT_NORMAL      = 400
%DWRITE_FONT_WEIGHT_REGULAR     = 400
%DWRITE_FONT_WEIGHT_MEDIUM      = 500
%DWRITE_FONT_WEIGHT_DEMI_BOLD   = 600
%DWRITE_FONT_WEIGHT_SEMI_BOLD   = 600
%DWRITE_FONT_WEIGHT_BOLD        = 700
%DWRITE_FONT_WEIGHT_EXTRA_BOLD  = 800
%DWRITE_FONT_WEIGHT_ULTRA_BOLD  = 800
%DWRITE_FONT_WEIGHT_BLACK       = 900
%DWRITE_FONT_WEIGHT_HEAVY       = 900
%DWRITE_FONT_WEIGHT_EXTRA_BLACK = 950
%DWRITE_FONT_WEIGHT_ULTRA_BLACK = 950

' enum DWRITE_FONT_STRETCH
%DWRITE_FONT_STRETCH_UNDEFINED       = 0
%DWRITE_FONT_STRETCH_ULTRA_CONDENSED = 1
%DWRITE_FONT_STRETCH_EXTRA_CONDENSED = 2
%DWRITE_FONT_STRETCH_CONDENSED       = 3
%DWRITE_FONT_STRETCH_SEMI_CONDENSED  = 4
%DWRITE_FONT_STRETCH_NORMAL          = 5
%DWRITE_FONT_STRETCH_MEDIUM          = 5
%DWRITE_FONT_STRETCH_SEMI_EXPANDED   = 6
%DWRITE_FONT_STRETCH_EXPANDED        = 7
%DWRITE_FONT_STRETCH_EXTRA_EXPANDED  = 8
%DWRITE_FONT_STRETCH_ULTRA_EXPANDED  = 9

' enum DWRITE_FONT_STYLE
%DWRITE_FONT_STYLE_NORMAL  = 0
%DWRITE_FONT_STYLE_OBLIQUE = 1
%DWRITE_FONT_STYLE_ITALIC  = 2

' enum DWRITE_INFORMATIONAL_STRING_ID
%DWRITE_INFORMATIONAL_STRING_NONE                      = 0
%DWRITE_INFORMATIONAL_STRING_COPYRIGHT_NOTICE          = 1
%DWRITE_INFORMATIONAL_STRING_VERSION_STRINGS           = 2
%DWRITE_INFORMATIONAL_STRING_TRADEMARK                 = 3
%DWRITE_INFORMATIONAL_STRING_MANUFACTURER              = 4
%DWRITE_INFORMATIONAL_STRING_DESIGNER                  = 5
%DWRITE_INFORMATIONAL_STRING_DESIGNER_URL              = 6
%DWRITE_INFORMATIONAL_STRING_DESCRIPTION               = 7
%DWRITE_INFORMATIONAL_STRING_FONT_VENDOR_URL           = 8
%DWRITE_INFORMATIONAL_STRING_LICENSE_DESCRIPTION       = 9
%DWRITE_INFORMATIONAL_STRING_LICENSE_INFO_URL          = 10
%DWRITE_INFORMATIONAL_STRING_WIN32_FAMILY_NAMES        = 11
%DWRITE_INFORMATIONAL_STRING_WIN32_SUBFAMILY_NAMES     = 12
%DWRITE_INFORMATIONAL_STRING_PREFERRED_FAMILY_NAMES    = 13
%DWRITE_INFORMATIONAL_STRING_PREFERRED_SUBFAMILY_NAMES = 14
%DWRITE_INFORMATIONAL_STRING_SAMPLE_TEXT               = 15

' // Size = 20 bytes
TYPE DWRITE_FONT_METRICS WORD
   designUnitsPerEm       AS WORD      ' UINT16
   ascent                 AS WORD      ' UINT16
   descent                AS WORD      ' UINT16
   lineGap                AS INTEGER   ' INT16
   capHeight              AS WORD      ' UINT16
   xHeight                AS WORD      ' UINT16
   underlinePosition      AS INTEGER   ' INT16
   underlineThickness     AS WORD      ' UINT16
   strikethroughPosition  AS INTEGER   ' INT16
   strikethroughThickness AS WORD      ' UINT16
END TYPE

' // Size = 28 bytes
TYPE DWRITE_GLYPH_METRICS DWORD
   leftSideBearing   AS LONG    ' INT32
   advanceWidth      AS DWORD   ' UINT32
   rightSideBearing  AS LONG    ' INT32
   topSideBearing    AS LONG    ' INT32
   advanceHeight     AS DWORD   ' UINT32
   bottomSideBearing AS LONG    ' INT32
   verticalOriginY   AS LONG    ' INT32
END TYPE

' // Size = 8 bytes
TYPE DWRITE_GLYPH_OFFSET DWORD
   advanceOffset  AS SINGLE   ' FLOAT
   ascenderOffset AS SINGLE   ' FLOAT
END TYPE

' enum DWRITE_FACTORY_TYPE
%DWRITE_FACTORY_TYPE_SHARED = 0
%DWRITE_FACTORY_TYPE_ISOLATED = 1

'// Creates an OpenType tag as a 32bit integer such that
'// the first character in the tag is the lowest byte,
'// (least significant on little endian architectures)
'// which can be used to compare with tags in the font file.
'// This macro is compatible with DWRITE_FONT_FEATURE_TAG.
'//
'// Example: DWRITE_MAKE_OPENTYPE_TAG('c','c','m','p')
'// Dword:   0x706D6363
'//
'#define DWRITE_MAKE_OPENTYPE_TAG(a,b,c,d) ( \
'    (static_cast<UINT32>(static_cast<UINT8>(d)) << 24) | \
'    (static_cast<UINT32>(static_cast<UINT8>(c)) << 16) | \
'    (static_cast<UINT32>(static_cast<UINT8>(b)) << 8)  | \
'     static_cast<UINT32>(static_cast<UINT8>(a)))

FUNCTION DWRITE_MAKE_OPENTYPE_TAG (BYVAL a AS STRING, BYVAL b AS STRING, BYVAL c AS STRING, BYVAL d AS STRING) AS DWORD
   LOCAL cha AS DWORD, chb AS DWORD, chc AS DWORD, chd AS DWORD
   cha = ASC(a)
   chb = ASC(b)
   chc = ASC(c)
   chd = ASC(d)
   SHIFT LEFT chd, 24
   SHIFT LEFT chc, 16
   SHIFT LEFT chb, 8
   FUNCTION = chd OR chc OR chb OR cha
END FUNCTION

' ########################################################################################
' IDWriteFontFileLoader interface
' IID = 727cad4e-d6af-4c9e-8a08-d695b11caa49
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDWriteFontFileLoader = GUID$("{727cad4e-d6af-4c9e-8a08-d695b11caa49}")

INTERFACE IDWriteFontFileLoader $IID_IDWriteFontFileLoader

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateStreamFromKey ( _                       ' VTable offset = 12
     BYREF fontFileReferenceKey AS DWORD _              ' __in_bcount(fontFileReferenceKeySize) void const* fontFileReferenceKey
   , BYVAL fontFileReferenceKeySize AS DWORD _          ' __in UINT32 fontFileReferenceKeySize
   , BYREF fontFileStream AS IDWriteFontFileStream _    ' __out IDWriteFontFileStream** fontFileStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDWriteLocalFontFileLoader interface
' IID = b2d9f3ec-c9fe-4a11-a2ec-d86208f7c0a2
' Inherited interface = IDWriteFontFileLoader
' ########################################################################################

$IID_IDWriteLocalFontFileLoader = GUID$("{b2d9f3ec-c9fe-4a11-a2ec-d86208f7c0a2}")

INTERFACE IDWriteLocalFontFileLoader $IID_IDWriteLocalFontFileLoader

   INHERIT IUnknown

   ' =====================================================================================
   ' IDWriteFontFileLoader method
   ' =====================================================================================
   METHOD CreateStreamFromKey ( _                       ' VTable offset = 12
     BYREF fontFileReferenceKey AS DWORD _              ' __in_bcount(fontFileReferenceKeySize) void const* fontFileReferenceKey
   , BYVAL fontFileReferenceKeySize AS DWORD _          ' __in UINT32 fontFileReferenceKeySize
   , BYREF fontFileStream AS IDWriteFontFileStream _    ' __out IDWriteFontFileStream** fontFileStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDWriteLocalFontFileLoader methods
   ' =====================================================================================
   METHOD GetFilePathLengthFromKey ( _                  ' VTable offset = 16
     BYREF fontFileReferenceKey AS DWORD _              ' __in_bcount(fontFileReferenceKeySize) void const* fontFileReferenceKey
   , BYVAL fontFileReferenceKeySize AS DWORD _          ' __in UINT32 fontFileReferenceKeySize
   , BYREF filePathLength AS DWORD _                    ' __out UINT32* filePathLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFilePathFromKey ( _                        ' VTable offset = 20
     BYREF fontFileReferenceKey AS DWORD _              ' __in_bcount(fontFileReferenceKeySize) void const* fontFileReferenceKey
   , BYVAL fontFileReferenceKeySize AS DWORD _          ' __in UINT32 fontFileReferenceKeySize
   , BYREF filePath AS WSTRINGZ _                       ' __out_ecount_z(filePathSize) WCHAR* filePath
   , BYVAL filePathSize AS DWORD _                      ' __in UINT32 filePathSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastWriteTimeFromKey ( _                   ' VTable offset = 24
     BYREF fontFileReferenceKey AS DWORD _              ' __in_bcount(fontFileReferenceKeySize) void const* fontFileReferenceKey
   , BYVAL fontFileReferenceKeySize AS DWORD _          ' __in UINT32 fontFileReferenceKeySize
   , BYREF lastWriteTime AS FILETIME _                  ' __out FILETIME* lastWriteTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDWriteFontFileStream interface
' IID = 6d4865fe-0ab8-4d91-8f62-5dd6be34a3e0
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDWriteFontFileStream = GUID$("{6d4865fe-0ab8-4d91-8f62-5dd6be34a3e0}")

INTERFACE IDWriteFontFileStream $IID_IDWriteFontFileStream

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ReadFileFragment ( _                          ' VTable offset = 12
     BYREF fragmentStart AS DWORD _                     ' __out void const** fragmentStart
   , BYVAL fileOffset AS QUAD _                         ' __in UINT64 fileOffset
   , BYVAL fragmentSize AS QUAD _                       ' __in UINT64 fragmentSize
   , BYREF fragmentContext AS DWORD _                   ' __out void** fragmentContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseFileFragment ( _                       ' VTable offset = 16
     BYVAL fragmentContext AS DWORD _                   ' __in void* fragmentContext
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFileSize ( _                               ' VTable offset = 20
     BYREF fileSize AS QUAD _                           ' __out UINT64* fileSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastWriteTime ( _                          ' VTable offset = 24
     BYREF lastWriteTime AS QUAD _                      ' __out UINT64* lastWriteTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDWriteFontFile interface
' IID = 739d886a-cef5-47dc-8769-1a8b41bebbb0
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDWriteFontFile = GUID$("{739d886a-cef5-47dc-8769-1a8b41bebbb0}")

INTERFACE IDWriteFontFile $IID_IDWriteFontFile

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetReferenceKey ( _                           ' VTable offset = 12
     BYREF fontFileReferenceKey AS DWORD _              ' __deref_out_bcount(*fontFileReferenceKeySize) void const** fontFileReferenceKey
   , BYREF fontFileReferenceKeySize AS DWORD _          ' __out UINT32* fontFileReferenceKeySize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLoader ( _                                 ' VTable offset = 16
     BYREF fontFileLoader AS IDWriteFontFileLoader _    ' __out IDWriteFontFileLoader** fontFileLoader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Analyze ( _                                   ' VTable offset = 20
     BYREF isSupportedFontType AS LONG _                ' __out BOOL* isSupportedFontType
   , BYREF fontFileType AS LONG _                       ' __out DWRITE_FONT_FILE_TYPE* fontFileType
   , BYREF fontFaceType AS LONG _                       ' __out_opt DWRITE_FONT_FACE_TYPE* fontFaceType
   , BYREF numberOfFaces AS DWORD _                     ' __out UINT32* numberOfFaces
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#IF NOT %DEF(%DWRITE_PIXEL_GEOMETRY_DEFINED)
' enum DWRITE_PIXEL_GEOMETRY
%DWRITE_PIXEL_GEOMETRY_FLAT = 0
%DWRITE_PIXEL_GEOMETRY_RGB = 1
%DWRITE_PIXEL_GEOMETRY_BGR = 2

%DWRITE_PIXEL_GEOMETRY_DEFINED = 1
#ENDIF

' enum DWRITE_RENDERING_MODE
%DWRITE_RENDERING_MODE_DEFAULT = 0
%DWRITE_RENDERING_MODE_ALIASED = 1
%DWRITE_RENDERING_MODE_CLEARTYPE_GDI_CLASSIC = 2
%DWRITE_RENDERING_MODE_CLEARTYPE_GDI_NATURAL = 3
%DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL = 4
%DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL_SYMMETRIC = 5
%DWRITE_RENDERING_MODE_OUTLINE = 6

' // Size = 24 bytes
TYPE DWRITE_MATRIX DWORD
   m11 AS SINGLE   ' FLOAT
   m12 AS SINGLE   ' FLOAT
   m21 AS SINGLE   ' FLOAT
   m22 AS SINGLE   ' FLOAT
   dx  AS SINGLE   ' FLOAT
   dy  AS SINGLE   ' FLOAT
END TYPE


' ########################################################################################
' IDWriteRenderingParams interface
' IID = 2f0da53a-2add-47cd-82ee-d9ec34688e75
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDWriteRenderingParams = GUID$("{2f0da53a-2add-47cd-82ee-d9ec34688e75}")

INTERFACE IDWriteRenderingParams $IID_IDWriteRenderingParams

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetGamma ( _                                  ' VTable offset = 12
   ) AS SINGLE                                          ' FLOAT
   ' =====================================================================================
   METHOD GetEnhancedContrast ( _                       ' VTable offset = 16
   ) AS SINGLE                                          ' FLOAT
   ' =====================================================================================
   METHOD GetClearTypeLevel ( _                         ' VTable offset = 20
   ) AS SINGLE                                          ' FLOAT
   ' =====================================================================================
   METHOD GetPixelGeometry ( _                          ' VTable offset = 24
   ) AS LONG                                            ' DWRITE_PIXEL_GEOMETRY
   ' =====================================================================================
   METHOD GetRenderingMode ( _                          ' VTable offset = 28
   ) AS LONG                                            ' DWRITE_RENDERING_MODE
   ' =====================================================================================

END INTERFACE

'typedef ID2D1SimplifiedGeometrySink IDWriteGeometrySink;
MACRO IDWriteGeometrySink = ID2D1SimplifiedGeometrySink

' ########################################################################################
' IDWriteFontFace interface
' IID = 5f49804d-7024-4d43-bfa9-d25984f53849
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDWriteFontFace = GUID$("{5f49804d-7024-4d43-bfa9-d25984f53849}")

INTERFACE IDWriteFontFace $IID_IDWriteFontFace

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 12
   ) AS LONG                                            ' DWRITE_FONT_FACE_TYPE
   ' =====================================================================================
   METHOD GetFiles ( _                                  ' VTable offset = 16
     BYREF numberOfFiles AS DWORD _                     ' __inout UINT32* numberOfFiles
   , BYREF fontFiles AS IDWriteFontFile _               ' __out IDWriteFontFile** fontFiles
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIndex ( _                                  ' VTable offset = 20
   ) AS DWORD                                           ' UINT32
   ' =====================================================================================
   METHOD GetSimulations ( _                            ' VTable offset = 24
   ) AS DWORD                                           ' DWRITE_FONT_SIMULATIONS
   ' =====================================================================================
   METHOD IsSymbolFont ( _                              ' VTable offset = 28
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD GetMetrics ( _                                ' VTable offset = 32
     BYREF fontFaceMetrics AS DWRITE_FONT_METRICS _     ' __out DWRITE_FONT_METRICS* fontFaceMetrics
   )                                                    ' void
   ' =====================================================================================
   METHOD GetGlyphCount ( _                             ' VTable offset = 36
   ) AS WORD                                            ' UINT16
   ' =====================================================================================
   METHOD GetDesignGlyphMetrics ( _                     ' VTable offset = 40
     BYREF glyphIndices AS WORD _                       ' __in UINT16 const* glyphIndices
   , BYVAL glyphCount AS DWORD _                        ' __in UINT32 glyphCount
   , BYREF glyphMetrics AS DWRITE_GLYPH_METRICS _       ' __out DWRITE_GLYPH_METRICS* glyphMetrics
   , BYVAL isSideways AS LONG _                         ' __in BOOL isSideways = FALSE
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGlyphIndices ( _                           ' VTable offset = 44
     BYREF codePoints AS DWORD _                        ' __in UINT32 const* codePoints
   , BYVAL codePointCount AS DWORD _                    ' __in UINT32 codePointCount
   , BYREF glyphIndices AS WORD _                       ' __out UINT16* glyphIndices
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TryGetFontTable ( _                           ' VTable offset = 48
     BYVAL openTypeTableTag AS DWORD _                  ' __in UINT32 openTypeTableTag
   , BYREF tableData AS DWORD _                         ' __out const void** tableData
   , BYREF tableSize AS DWORD _                         ' __out UINT32* tableSize
   , BYREF tableContext AS DWORD _                      ' __out void** tableContext
   , BYREF exists AS LONG _                             ' __out BOOL* exists
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseFontTable ( _                          ' VTable offset = 52
     BYVAL tableContext AS DWORD _                      ' __in void* tableContext
   )                                                    ' void
   ' =====================================================================================
   METHOD GetGlyphRunOutline ( _                        ' VTable offset = 56
     BYVAL emSize AS SINGLE _                           ' __in FLOAT emSize
   , BYREF glyphIndices AS WORD _                       ' __in UINT16 const* glyphIndices
   , BYREF glyphAdvances AS SINGLE _                    ' __in FLOAT const* glyphAdvances
   , BYREF glyphOffsets AS DWRITE_GLYPH_OFFSET _        ' __in DWRITE_GLYPH_OFFSET const* glyphOffsets
   , BYVAL glyphCount AS DWORD _                        ' __in UINT32 glyphCount
   , BYVAL isSideways AS LONG _                         ' __in BOOL isSideways
   , BYVAL isRightToLeft AS LONG _                      ' __in BOOL isRightToLeft
   , BYVAL geometrySink AS IDWriteGeometrySink _        ' __in IDWriteGeometrySink* geometrySink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecommendedRenderingMode ( _               ' VTable offset = 60
     BYVAL emSize AS SINGLE _                           ' __in FLOAT emSize
   , BYVAL pixelsPerDip AS SINGLE _                     ' __in FLOAT pixelsPerDip
   , BYVAL measuringMode AS LONG _                      ' __in DWRITE_MEASURING_MODE measuringMode
   , BYVAL renderingParams AS IDWriteRenderingParams _  ' __in IDWriteRenderingParams* renderingParams
   , BYREF renderingMode AS LONG _                      ' __out DWRITE_RENDERING_MODE* renderingMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGdiCompatibleMetrics ( _                   ' VTable offset = 64
     BYVAL emSize AS SINGLE _                           ' __in FLOAT emSize
   , BYVAL pixelsPerDip AS SINGLE _                     ' __in FLOAT pixelsPerDip
   , BYREF transform AS DWRITE_MATRIX _                 ' __in_opt DWRITE_MATRIX const* transform
   , BYREF fontFaceMetrics AS DWRITE_FONT_METRICS _     ' __out DWRITE_FONT_METRICS* fontFaceMetrics
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGdiCompatibleGlyphMetrics ( _              ' VTable offset = 64
     BYVAL emSize AS SINGLE _                           ' __in FLOAT emSize
   , BYVAL pixelsPerDip AS SINGLE _                     ' __in FLOAT pixelsPerDip
   , BYREF transform AS DWRITE_MATRIX _                 ' __in_opt DWRITE_MATRIX const* transform
   , BYVAL useGdiNatural AS LONG _                      ' __in BOOL useGdiNatural
   , BYREF glyphIndices AS WORD _                       ' __in UINT16 const* glyphIndices
   , BYVAL glyphCount AS DWORD _                        ' __in UINT32 glyphCount
   , BYREF glyphMetrics AS DWRITE_GLYPH_METRICS _       ' __out DWRITE_GLYPH_METRICS* glyphMetrics
   , BYVAL isSideways AS LONG _                         ' __in BOOL isSideways = FALSE
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDWriteFontCollectionLoader interface
' IID = cca920e4-52f0-492b-bfa8-29c72ee0a468
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDWriteFontCollectionLoader = GUID$("{cca920e4-52f0-492b-bfa8-29c72ee0a468}")

INTERFACE IDWriteFontCollectionLoader $IID_IDWriteFontCollectionLoader

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateEnumeratorFromKey ( _                   ' VTable offset = 12
     BYVAL factory AS IDWriteFactory _                  ' __in IDWriteFactory* factory
   , BYREF collectionKey AS DWORD _                     ' __in void const* collectionKey
   , BYVAL collectionKeySize AS DWORD _                 ' __in UINT32 collectionKeySize
   , BYREF fontFileEnumerator AS IDWriteFontFileEnumerator _ ' __out IDWriteFontFileEnumerator** fontFileEnumerator
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDWriteFontFileEnumerator interface
' IID = 72755049-5ff7-435d-8348-4be97cfa6c7c
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDWriteFontFileEnumerator = GUID$("{72755049-5ff7-435d-8348-4be97cfa6c7c}")

INTERFACE IDWriteFontFileEnumerator $IID_IDWriteFontFileEnumerator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD MoveNext ( _                                  ' VTable offset = 12
     BYREF hasCurrentFile AS LONG _                     ' __out BOOL* hasCurrentFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentFontFile ( _                        ' VTable offset = 16
     BYREF fontFile AS IDWriteFontFile _                ' __out IDWriteFontFile** fontFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDWriteLocalizedStrings interface
' IID = 08256209-099a-4b34-b86d-c22b110e7771
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDWriteLocalizedStrings = GUID$("{08256209-099a-4b34-b86d-c22b110e7771}")

INTERFACE IDWriteLocalizedStrings $IID_IDWriteLocalizedStrings

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
   ) AS DWORD                                           ' UINT32
   ' =====================================================================================
   METHOD FindLocaleName ( _                            ' VTable offset = 16
     BYREF localeName AS WSTRINGZ _                     ' __in_z WCHAR const* localeName
   , BYREF index AS DWORD _                             ' __out UINT32* index
   , BYREF exists AS LONG _                             ' __out BOOL* exists
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLocaleNameLength ( _                       ' VTable offset = 20
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF length AS DWORD _                            ' __out UINT32* length
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLocaleName ( _                             ' VTable offset = 24
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF localeName AS WSTRINGZ _                     ' __out WCHAR* localeName
   , BYVAL size AS DWORD _                              ' __in UINT32 size
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringLength ( _                           ' VTable offset = 28
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF length AS DWORD _                            ' __out UINT32* length
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 32
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF stringBuffer AS WSTRINGZ _                   ' __out WCHAR* stringBuffer
   , BYVAL size AS DWORD _                              ' __in UINT32 size
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDWriteFontCollection interface
' IID = a84cee02-3eea-4eee-a827-87c1a02a0fcc
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDWriteFontCollection = GUID$("{a84cee02-3eea-4eee-a827-87c1a02a0fcc}")

INTERFACE IDWriteFontCollection $IID_IDWriteFontCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFontFamilyCount ( _                        ' VTable offset = 12
   ) AS DWORD                                           ' UINT32
   ' =====================================================================================
   METHOD GetFontFamily ( _                             ' VTable offset = 16
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF fontFamily AS IDWriteFontFamily _            ' __out IDWriteFontFamily** fontFamily
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindFamilyName ( _                            ' VTable offset = 20
     BYREF familyName AS WSTRINGZ _                     ' __in WCHAR const* familyName
   , BYREF index AS DWORD _                             ' __out UINT32* index
   , BYREF exists AS LONG _                             ' __out BOOL* exists
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFontFromFontFace ( _                       ' VTable offset = 24
     BYVAL fontFace AS IDWriteFontFace _                ' __in IDWriteFontFace* fontFace
   , BYREF font AS IDWriteFont _                        ' __out IDWriteFont** font
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDWriteFontList interface
' IID = 1a0d8438-1d97-4ec1-aef9-a2fb86ed6acb
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDWriteFontList = GUID$("{1a0d8438-1d97-4ec1-aef9-a2fb86ed6acb}")

INTERFACE IDWriteFontList $IID_IDWriteFontList

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFontCollection ( _                         ' VTable offset = 12
     BYREF fontCollection AS IDWriteFontCollection _    ' __out IDWriteFontCollection** fontCollection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFontCount ( _                              ' VTable offset = 16
   ) AS DWORD                                           ' UINT32
   ' =====================================================================================
   METHOD GetFont ( _                                   ' VTable offset = 20
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF font AS IDWriteFont _                        ' __out IDWriteFont** font
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDWriteFontFamily interface
' IID = da20d8ef-812a-4c43-9802-62ec4abd7add
' Inherited interface = IDWriteFontList
' ########################################################################################

$IID_IDWriteFontFamily = GUID$("{da20d8ef-812a-4c43-9802-62ec4abd7add}")

INTERFACE IDWriteFontFamily $IID_IDWriteFontFamily

   INHERIT IUnknown

   ' =====================================================================================
   ' IDWriteFontList methods
   ' =====================================================================================
   METHOD GetFontCollection ( _                         ' VTable offset = 12
     BYREF fontCollection AS IDWriteFontCollection _    ' __out IDWriteFontCollection** fontCollection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFontCount ( _                              ' VTable offset = 16
   ) AS DWORD                                           ' UINT32
   ' =====================================================================================
   METHOD GetFont ( _                                   ' VTable offset = 20
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF font AS IDWriteFont _                        ' __out IDWriteFont** font
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDWriteFontFamily methods
   ' =====================================================================================
   METHOD GetFamilyNames ( _                            ' VTable offset = 24
     BYREF names AS IDWriteLocalizedStrings _           ' __out IDWriteLocalizedStrings** names
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFirstMatchingFont ( _                      ' VTable offset = 28
     BYVAL weight AS LONG _                             ' __in DWRITE_FONT_WEIGHT weight
   , BYVAL stretch AS LONG _                            ' __in DWRITE_FONT_STRETCH stretch
   , BYVAL style AS LONG _                              ' __in DWRITE_FONT_STYLE style
   , BYREF matchingFont AS IDWriteFont _                ' __out IDWriteFont** matchingFont
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMatchingFonts ( _                          ' VTable offset = 32
     BYVAL weight AS LONG _                             ' __in DWRITE_FONT_WEIGHT weight
   , BYVAL stretch AS LONG _                            ' __in DWRITE_FONT_STRETCH stretch
   , BYVAL style AS LONG _                              ' __in DWRITE_FONT_STYLE style
   , BYREF matchingFont AS IDWriteFontList _            ' __out IDWriteFontList** matchingFonts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDWriteFont interface
' IID = acd16696-8c14-4f5d-877e-fe3fc1d32737
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDWriteFont = GUID$("{acd16696-8c14-4f5d-877e-fe3fc1d32737}")

INTERFACE IDWriteFont $IID_IDWriteFont

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFontFamily ( _                             ' VTable offset = 12
     BYREF fontFamily AS IDWriteFontFamily _            ' __out IDWriteFontFamily** fontFamily
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWeight ( _                                 ' VTable offset = 16
   ) AS LONG                                            ' DWRITE_FONT_WEIGHT
   ' =====================================================================================
   METHOD GetStretch ( _                                ' VTable offset = 20
   ) AS LONG                                            ' DWRITE_FONT_STRETCH
   ' =====================================================================================
   METHOD GetStyle ( _                                  ' VTable offset = 24
   ) AS LONG                                            ' DWRITE_FONT_STYLE
   ' =====================================================================================
   METHOD IsSymbolFont ( _                              ' VTable offset = 28
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD GetFaceNames ( _                              ' VTable offset = 32
     BYREF names AS IDWriteLocalizedStrings _           ' __out IDWriteLocalizedStrings** names
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInformationalStrings ( _                   ' VTable offset = 36
     BYVAL informationalStringID AS LONG _              ' __in DWRITE_INFORMATIONAL_STRING_ID informationalStringID
   , BYREF informationalStrings AS IDWriteLocalizedStrings _ ' __out IDWriteLocalizedStrings** informationalStrings
   , BYREF exists AS LONG _                             ' __out BOOL* exists
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSimulations ( _                            ' VTable offset = 40
   ) AS DWORD                                           ' DWRITE_FONT_SIMULATIONS
   ' =====================================================================================
   METHOD GetMetrics ( _                                ' VTable offset = 44
     BYREF fontMetrics AS DWRITE_FONT_METRICS _         ' __out DWRITE_FONT_METRICS* fontMetrics
   )                                                    ' void
   ' =====================================================================================
   METHOD HasCharacter ( _                              ' VTable offset = 48
     BYVAL unicodeValue AS DWORD _                      ' __in UINT32 unicodeValue
   , BYREF exists AS LONG _                             ' __out BOOL* exists
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateFontFace ( _                            ' VTable offset = 52
     BYREF fontFace AS IDWriteFontFace _                ' __out IDWriteFontFace** fontFace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' enum DWRITE_READING_DIRECTION
%DWRITE_READING_DIRECTION_LEFT_TO_RIGHT = 0
%DWRITE_READING_DIRECTION_RIGHT_TO_LEFT = 1

' enum DWRITE_FLOW_DIRECTION
%DWRITE_FLOW_DIRECTION_TOP_TO_BOTTOM = 0

' enum DWRITE_TEXT_ALIGNMENT
%DWRITE_TEXT_ALIGNMENT_LEADING = 0
%DWRITE_TEXT_ALIGNMENT_TRAILING = 1
%DWRITE_TEXT_ALIGNMENT_CENTER = 2

' enum DWRITE_PARAGRAPH_ALIGNMENT
%DWRITE_PARAGRAPH_ALIGNMENT_NEAR = 0
%DWRITE_PARAGRAPH_ALIGNMENT_FAR = 1
%DWRITE_PARAGRAPH_ALIGNMENT_CENTER = 2

' enum DWRITE_WORD_WRAPPING
%DWRITE_WORD_WRAPPING_WRAP = 0
%DWRITE_WORD_WRAPPING_NO_WRAP = 1

' enum DWRITE_LINE_SPACING_METHOD
%DWRITE_LINE_SPACING_METHOD_DEFAULT = 0
%DWRITE_LINE_SPACING_METHOD_UNIFORM = 1

' enum DWRITE_TRIMMING_GRANULARITY
%DWRITE_TRIMMING_GRANULARITY_NONE = 0
%DWRITE_TRIMMING_GRANULARITY_CHARACTER = 1
%DWRITE_TRIMMING_GRANULARITY_WORD = 2

' enum DWRITE_FONT_FEATURE_TAG
%DWRITE_FONT_FEATURE_TAG_ALTERNATIVE_FRACTIONS               = &H63726661???   ' // 'afrc'
%DWRITE_FONT_FEATURE_TAG_PETITE_CAPITALS_FROM_CAPITALS       = &H63703263???   ' // 'c2pc'
%DWRITE_FONT_FEATURE_TAG_SMALL_CAPITALS_FROM_CAPITALS        = &H63733263???   ' // 'c2sc'
%DWRITE_FONT_FEATURE_TAG_CONTEXTUAL_ALTERNATES               = &H746c6163???   ' // 'calt'
%DWRITE_FONT_FEATURE_TAG_CASE_SENSITIVE_FORMS                = &H65736163???   ' // 'case'
%DWRITE_FONT_FEATURE_TAG_GLYPH_COMPOSITION_DECOMPOSITION     = &H706d6363???   ' // 'ccmp'
%DWRITE_FONT_FEATURE_TAG_CONTEXTUAL_LIGATURES                = &H67696c63???   ' // 'clig'
%DWRITE_FONT_FEATURE_TAG_CAPITAL_SPACING                     = &H70737063???   ' // 'cpsp'
%DWRITE_FONT_FEATURE_TAG_CONTEXTUAL_SWASH                    = &H68777363???   ' // 'cswh'
%DWRITE_FONT_FEATURE_TAG_CURSIVE_POSITIONING                 = &H73727563???   ' // 'curs'
%DWRITE_FONT_FEATURE_TAG_DEFAULT                             = &H746c6664???   ' // 'dflt'
%DWRITE_FONT_FEATURE_TAG_DISCRETIONARY_LIGATURES             = &H67696c64???   ' // 'dlig'
%DWRITE_FONT_FEATURE_TAG_EXPERT_FORMS                        = &H74707865???   ' // 'expt'
%DWRITE_FONT_FEATURE_TAG_FRACTIONS                           = &H63617266???   ' // 'frac'
%DWRITE_FONT_FEATURE_TAG_FULL_WIDTH                          = &H64697766???   ' // 'fwid'
%DWRITE_FONT_FEATURE_TAG_HALF_FORMS                          = &H666c6168???   ' // 'half'
%DWRITE_FONT_FEATURE_TAG_HALANT_FORMS                        = &H6e6c6168???   ' // 'haln'
%DWRITE_FONT_FEATURE_TAG_ALTERNATE_HALF_WIDTH                = &H746c6168???   ' // 'halt'
%DWRITE_FONT_FEATURE_TAG_HISTORICAL_FORMS                    = &H74736968???   ' // 'hist'
%DWRITE_FONT_FEATURE_TAG_HORIZONTAL_KANA_ALTERNATES          = &H616e6b68???   ' // 'hkna'
%DWRITE_FONT_FEATURE_TAG_HISTORICAL_LIGATURES                = &H67696c68???   ' // 'hlig'
%DWRITE_FONT_FEATURE_TAG_HALF_WIDTH                          = &H64697768???   ' // 'hwid'
%DWRITE_FONT_FEATURE_TAG_HOJO_KANJI_FORMS                    = &H6f6a6f68???   ' // 'hojo'
%DWRITE_FONT_FEATURE_TAG_JIS04_FORMS                         = &H3430706a???   ' // 'jp04'
%DWRITE_FONT_FEATURE_TAG_JIS78_FORMS                         = &H3837706a???   ' // 'jp78'
%DWRITE_FONT_FEATURE_TAG_JIS83_FORMS                         = &H3338706a???   ' // 'jp83'
%DWRITE_FONT_FEATURE_TAG_JIS90_FORMS                         = &H3039706a???   ' // 'jp90'
%DWRITE_FONT_FEATURE_TAG_KERNING                             = &H6e72656b???   ' // 'kern'
%DWRITE_FONT_FEATURE_TAG_STANDARD_LIGATURES                  = &H6167696c???   ' // 'liga'
%DWRITE_FONT_FEATURE_TAG_LINING_FIGURES                      = &H6d756e6c???   ' // 'lnum'
%DWRITE_FONT_FEATURE_TAG_LOCALIZED_FORMS                     = &H6c636f6c???   ' // 'locl'
%DWRITE_FONT_FEATURE_TAG_MARK_POSITIONING                    = &H6b72616d???   ' // 'mark'
%DWRITE_FONT_FEATURE_TAG_MATHEMATICAL_GREEK                  = &H6b72676d???   ' // 'mgrk'
%DWRITE_FONT_FEATURE_TAG_MARK_TO_MARK_POSITIONING            = &H6b6d6b6d???   ' // 'mkmk'
%DWRITE_FONT_FEATURE_TAG_ALTERNATE_ANNOTATION_FORMS          = &H746c616e???   ' // 'nalt'
%DWRITE_FONT_FEATURE_TAG_NLC_KANJI_FORMS                     = &H6b636c6e???   ' // 'nlck'
%DWRITE_FONT_FEATURE_TAG_OLD_STYLE_FIGURES                   = &H6d756e6f???   ' // 'onum'
%DWRITE_FONT_FEATURE_TAG_ORDINALS                            = &H6e64726f???   ' // 'ordn'
%DWRITE_FONT_FEATURE_TAG_PROPORTIONAL_ALTERNATE_WIDTH        = &H746c6170???   ' // 'palt'
%DWRITE_FONT_FEATURE_TAG_PETITE_CAPITALS                     = &H70616370???   ' // 'pcap'
%DWRITE_FONT_FEATURE_TAG_PROPORTIONAL_FIGURES                = &H6d756e70???   ' // 'pnum'
%DWRITE_FONT_FEATURE_TAG_PROPORTIONAL_WIDTHS                 = &H64697770???   ' // 'pwid'
%DWRITE_FONT_FEATURE_TAG_QUARTER_WIDTHS                      = &H64697771???   ' // 'qwid'
%DWRITE_FONT_FEATURE_TAG_REQUIRED_LIGATURES                  = &H67696c72???   ' // 'rlig'
%DWRITE_FONT_FEATURE_TAG_RUBY_NOTATION_FORMS                 = &H79627572???   ' // 'ruby'
%DWRITE_FONT_FEATURE_TAG_STYLISTIC_ALTERNATES                = &H746c6173???   ' // 'salt'
%DWRITE_FONT_FEATURE_TAG_SCIENTIFIC_INFERIORS                = &H666e6973???   ' // 'sinf'
%DWRITE_FONT_FEATURE_TAG_SMALL_CAPITALS                      = &H70636d73???   ' // 'smcp'
%DWRITE_FONT_FEATURE_TAG_SIMPLIFIED_FORMS                    = &H6c706d73???   ' // 'smpl'
%DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_1                     = &H31307373???   ' // 'ss01'
%DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_2                     = &H32307373???   ' // 'ss02'
%DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_3                     = &H33307373???   ' // 'ss03'
%DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_4                     = &H34307373???   ' // 'ss04'
%DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_5                     = &H35307373???   ' // 'ss05'
%DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_6                     = &H36307373???   ' // 'ss06'
%DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_7                     = &H37307373???   ' // 'ss07'
%DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_8                     = &H38307373???   ' // 'ss08'
%DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_9                     = &H39307373???   ' // 'ss09'
%DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_10                    = &H30317373???   ' // 'ss10'
%DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_11                    = &H31317373???   ' // 'ss11'
%DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_12                    = &H32317373???   ' // 'ss12'
%DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_13                    = &H33317373???   ' // 'ss13'
%DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_14                    = &H34317373???   ' // 'ss14'
%DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_15                    = &H35317373???   ' // 'ss15'
%DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_16                    = &H36317373???   ' // 'ss16'
%DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_17                    = &H37317373???   ' // 'ss17'
%DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_18                    = &H38317373???   ' // 'ss18'
%DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_19                    = &H39317373???   ' // 'ss19'
%DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_20                    = &H30327373???   ' // 'ss20'
%DWRITE_FONT_FEATURE_TAG_SUBSCRIPT                           = &H73627573???   ' // 'subs'
%DWRITE_FONT_FEATURE_TAG_SUPERSCRIPT                         = &H73707573???   ' // 'sups'
%DWRITE_FONT_FEATURE_TAG_SWASH                               = &H68737773???   ' // 'swsh'
%DWRITE_FONT_FEATURE_TAG_TITLING                             = &H6c746974???   ' // 'titl'
%DWRITE_FONT_FEATURE_TAG_TRADITIONAL_NAME_FORMS              = &H6d616e74???   ' // 'tnam'
%DWRITE_FONT_FEATURE_TAG_TABULAR_FIGURES                     = &H6d756e74???   ' // 'tnum'
%DWRITE_FONT_FEATURE_TAG_TRADITIONAL_FORMS                   = &H64617274???   ' // 'trad'
%DWRITE_FONT_FEATURE_TAG_THIRD_WIDTHS                        = &H64697774???   ' // 'twid'
%DWRITE_FONT_FEATURE_TAG_UNICASE                             = &H63696e75???   ' // 'unic'
%DWRITE_FONT_FEATURE_TAG_SLASHED_ZERO                        = &H6f72657a???   ' // 'zero'

' // Size = 8 bytes
TYPE DWRITE_TEXT_RANGE DWORD
   startPosition AS DWORD   ' UINT32
   length        AS DWORD   ' UINT32
END TYPE

' // Size = 8 bytes
TYPE DWRITE_FONT_FEATURE DWORD
   nameTag   AS DWORD   ' DWRITE_FONT_FEATURE_TAG
   parameter AS DWORD   ' UINT32
END TYPE

' // Size = 8 bytes
TYPE DWRITE_TYPOGRAPHIC_FEATURES DWORD
   features     AS DWRITE_FONT_FEATURE PTR   ' __field_ecount(featureCount) DWRITE_FONT_FEATURE* features;
   featureCount AS DWORD                     ' UINT32
END TYPE

' // Size = 12 bytes
TYPE DWRITE_TRIMMING DWORD
   granularity    AS LONG    ' DWRITE_TRIMMING_GRANULARITY
   delimiter      AS DWORD   ' UINT32
   delimiterCount AS DWORD   ' UINT32
END TYPE


' ########################################################################################
' IDWriteTextFormat interface
' IID = 9c906818-31d7-4fd3-a151-7c5e225db55a
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDWriteTextFormat = GUID$("{9c906818-31d7-4fd3-a151-7c5e225db55a}")

INTERFACE IDWriteTextFormat $IID_IDWriteTextFormat

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetTextAlignment ( _                          ' VTable offset = 12
     BYVAL textAlignment AS LONG _                      ' __in DWRITE_TEXT_ALIGNMENT textAlignment
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetParagraphAlignment ( _                     ' VTable offset = 16
     BYVAL paragraphAlignment AS LONG _                 ' __in DWRITE_PARAGRAPH_ALIGNMENT paragraphAlignment
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetWordWrapping ( _                           ' VTable offset = 20
     BYVAL wordWrapping AS LONG _                       ' __in DWRITE_WORD_WRAPPING wordWrapping
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetReadingDirection ( _                       ' VTable offset = 24
     BYVAL readingDirection AS LONG _                   ' __in DWRITE_READING_DIRECTION readingDirection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFlowDirection ( _                          ' VTable offset = 28
     BYVAL flowDirection AS LONG _                      ' __in DWRITE_FLOW_DIRECTION flowDirection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIncrementalTabStop ( _                     ' VTable offset = 32
     BYVAL incrementalTabStop AS SINGLE _               ' __in FLOAT incrementalTabStop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTrimming ( _                               ' VTable offset = 36
     BYREF trimmingOptions AS DWRITE_TRIMMING _         ' __in DWRITE_TRIMMING const* trimmingOptions
   , BYVAL trimmingSign AS IDWriteInlineObject _        ' __in IDWriteInlineObject* trimmingSign
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLineSpacing ( _                            ' VTable offset = 40
     BYVAL lineSpacingMethod AS LONG _                  ' __in DWRITE_LINE_SPACING_METHOD lineSpacingMethod
   , BYVAL lineSpacing AS SINGLE _                      ' __in FLOAT lineSpacing
   , BYVAL baseline AS SINGLE _                         ' __in FLOAT baseline
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTextAlignment ( _                          ' VTable offset = 44
   ) AS LONG                                            ' DWRITE_TEXT_ALIGNMENT
   ' =====================================================================================
   METHOD GetParagraphAlignment ( _                     ' VTable offset = 48
   ) AS LONG                                            ' DWRITE_PARAGRAPH_ALIGNMENT
   ' =====================================================================================
   METHOD GetWordWrapping ( _                           ' VTable offset = 52
   ) AS LONG                                            ' DWRITE_WORD_WRAPPING
   ' =====================================================================================
   METHOD GetReadingDirection ( _                       ' VTable offset = 56
   ) AS LONG                                            ' DWRITE_READING_DIRECTION
   ' =====================================================================================
   METHOD GetFlowDirection ( _                          ' VTable offset = 60
   ) AS LONG                                            ' DWRITE_FLOW_DIRECTION
   ' =====================================================================================
   METHOD GetIncrementalTabStop ( _                     ' VTable offset = 64
   ) AS SINGLE                                          ' FLOAT
   ' =====================================================================================
   METHOD GetTrimming ( _                               ' VTable offset = 68
     BYREF trimmingOptions AS LONG _                    ' __out DWRITE_TRIMMING* trimmingOptions
   , BYREF trimmingSign AS IDWriteInlineObject _        ' __out IDWriteInlineObject** trimmingSign
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLineSpacing ( _                            ' VTable offset = 72
     BYREF lineSpacingMethod AS LONG _                  ' __out DWRITE_LINE_SPACING_METHOD* lineSpacingMethod
   , BYREF lineSpacing AS SINGLE _                      ' __out FLOAT* lineSpacing
   , BYREF baseline AS SINGLE _                         ' __out FLOAT* baseline
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFontCollection ( _                         ' VTable offset = 76
     BYREF fontCollection AS IDWriteFontCollection _    ' __out IDWriteFontCollection** fontCollection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFontFamilyNameLength ( _                   ' VTable offset = 80
   ) AS DWORD                                           ' UINT32
   ' =====================================================================================
   METHOD GetFontFamilyName ( _                         ' VTable offset = 84
     BYREF fontFamilyName AS WSTRINGZ _                 ' __out WCHAR* fontFamilyName
   , BYVAL nameSize AS DWORD _                          ' __in UINT32 nameSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFontWeight ( _                             ' VTable offset = 88
   ) AS LONG                                            ' DWRITE_FONT_WEIGHT
   ' =====================================================================================
   METHOD GetFontStyle ( _                              ' VTable offset = 92
   ) AS LONG                                            ' DWRITE_FONT_STYLE
   ' =====================================================================================
   METHOD GetFontStretch ( _                            ' VTable offset = 96
   ) AS LONG                                            ' DWRITE_FONT_STRETCH
   ' =====================================================================================
   METHOD GetFontSize ( _                               ' VTable offset = 100
   ) AS SINGLE                                          ' FLOAT
   ' =====================================================================================
   METHOD GetLocaleNameLength ( _                       ' VTable offset = 104
   ) AS DWORD                                           ' UINT32
   ' =====================================================================================
   METHOD GetLocaleName ( _                             ' VTable offset = 108
     BYREF localeName AS WSTRINGZ _                     ' __out WCHAR* localeName
   , BYVAL nameSize AS DWORD _                          ' __in UINT32 nameSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDWriteTypography interface
' IID = 55f1112b-1dc2-4b3c-9541-f46894ed85b6
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDWriteTypography = GUID$("{55f1112b-1dc2-4b3c-9541-f46894ed85b6}")

INTERFACE IDWriteTypography $IID_IDWriteTypography

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddFontFeature ( _                            ' VTable offset = 12
     BYVAL fontFeature AS DWRITE_FONT_FEATURE _         ' __in DWRITE_FONT_FEATURE fontFeature
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFontFeatureCount ( _                       ' VTable offset = 16
   ) AS DWORD                                           ' UINT32
   ' =====================================================================================
   METHOD GetFontFeature ( _                            ' VTable offset = 20
     BYVAL fontFeatureIndex AS DWORD _                  ' __in UINT32 fontFeatureIndex
   , BYREF fontFeature AS DWRITE_FONT_FEATURE _         ' __out DWRITE_FONT_FEATURE* fontFeature
   ) AS DWORD                                           ' UINT32
   ' =====================================================================================

END INTERFACE

' enum DWRITE_SCRIPT_SHAPES
%DWRITE_SCRIPT_SHAPES_DEFAULT = 0&
%DWRITE_SCRIPT_SHAPES_NO_VISUAL = 1&

'#ifdef DEFINE_ENUM_FLAG_OPERATORS
'DEFINE_ENUM_FLAG_OPERATORS(DWRITE_SCRIPT_SHAPES);
'#endif

' // Size = 8 bytes
TYPE DWRITE_SCRIPT_ANALYSIS DWORD FILL
   script AS WORD   ' UINT16
   shapes AS LONG   ' DWRITE_SCRIPT_SHAPES
END TYPE

' enum DWRITE_BREAK_CONDITION
%DWRITE_BREAK_CONDITION_NEUTRAL = 0
%DWRITE_BREAK_CONDITION_CAN_BREAK = 1
%DWRITE_BREAK_CONDITION_MAY_NOT_BREAK = 2
%DWRITE_BREAK_CONDITION_MUST_BREAK = 3

' // Size = 1 byte
TYPE DWRITE_LINE_BREAKPOINT BYTE
   breakConditionBefore AS BIT * 2 IN BYTE   ' UINT8
   breakConditionAfter  AS BIT * 2
   isWhitespace         AS BIT * 1
   isSoftHyphen         AS BIT * 1
   padding              AS BIT * 2
END TYPE

' enum DWRITE_NUMBER_SUBSTITUTION_METHOD
%DWRITE_NUMBER_SUBSTITUTION_METHOD_FROM_CULTURE = 0
%DWRITE_NUMBER_SUBSTITUTION_METHOD_CONTEXTUAL = 1
%DWRITE_NUMBER_SUBSTITUTION_METHOD_NONE = 2
%DWRITE_NUMBER_SUBSTITUTION_METHOD_NATIONAL = 3
%DWRITE_NUMBER_SUBSTITUTION_METHOD_TRADITIONAL = 4


' ########################################################################################
' IDWriteNumberSubstitution interface
' IID = 14885CC9-BAB0-4f90-B6ED-5C366A2CD03D
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDWriteNumberSubstitution = GUID$("{14885CC9-BAB0-4f90-B6ED-5C366A2CD03D}")

INTERFACE IDWriteNumberSubstitution $IID_IDWriteNumberSubstitution

   INHERIT IUnknown

END INTERFACE

' // Size = 2 bytes
TYPE DWRITE_SHAPING_TEXT_PROPERTIES WORD
   isShapedAlone AS BIT * 1 IN WORD  ' UINT16
   reserved      AS BIT * 15
END TYPE

' // Size = 2 bytes
TYPE DWRITE_SHAPING_GLYPH_PROPERTIES WORD
   justification    AS BIT * 4 IN WORD   ' UINT16
   isClusterStart   AS BIT * 1
   isDiacritic      AS BIT * 1
   isZeroWidthSpace AS BIT * 1
   reserved         AS BIT * 9
END TYPE


' ########################################################################################
' IDWriteTextAnalysisSource interface
' IID = 688e1a58-5094-47c8-adc8-fbcea60ae92b
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDWriteTextAnalysisSource = GUID$("{688e1a58-5094-47c8-adc8-fbcea60ae92b}")

INTERFACE IDWriteTextAnalysisSource $IID_IDWriteTextAnalysisSource

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTextAtPosition ( _                         ' VTable offset = 12
     BYVAL textPosition AS DWORD _                      ' __in UINT32 textPosition
   , BYREF textString AS WSTRINGZ _                     ' __out WCHAR const** textString
   , BYREF textLength AS DWORD _                        ' __out UINT32* textLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTextBeforePosition ( _                     ' VTable offset = 16
     BYVAL textPosition AS DWORD _                      ' __in UINT32 textPosition
   , BYREF textString AS WSTRINGZ _                     ' __out WCHAR const** textString
   , BYREF textLength AS DWORD _                        ' __out UINT32* textLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParagraphReadingDirection ( _              ' VTable offset = 20
   ) AS LONG                                            ' DWRITE_READING_DIRECTION
   ' =====================================================================================
   METHOD GetLocaleName ( _                             ' VTable offset = 24
     BYVAL textPosition AS DWORD _                      ' __in UINT32 textPosition
   , BYREF textLength AS DWORD _                        ' __out UINT32* textLength
   , BYREF localeName AS WSTRINGZ _                     ' __out WCHAR const** localeName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberSubstitution ( _                     ' VTable offset = 28
     BYVAL textPosition AS DWORD _                      ' __in UINT32 textPosition
   , BYREF textLength AS DWORD _                        ' __out UINT32* textLength
   , BYREF numberSubstitution AS IDWriteNumberSubstitution _ ' __out IDWriteNumberSubstitution** numberSubstitution
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDWriteTextAnalysisSink interface
' IID = 5810cd44-0ca0-4701-b3fa-bec5182ae4f6
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDWriteTextAnalysisSink = GUID$("{5810cd44-0ca0-4701-b3fa-bec5182ae4f6}")

INTERFACE IDWriteTextAnalysisSink $IID_IDWriteTextAnalysisSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetScriptAnalysis ( _                         ' VTable offset = 12
     BYVAL textPosition AS DWORD _                      ' __in UINT32 textPosition
   , BYVAL textLength AS DWORD _                        ' __in UINT32 textLength
   , BYREF scriptAnalysis AS DWRITE_SCRIPT_ANALYSIS _   ' __in DWRITE_SCRIPT_ANALYSIS const* scriptAnalysis
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLineBreakpoints ( _                        ' VTable offset = 16
     BYVAL textPosition AS DWORD _                      ' __in UINT32 textPosition
   , BYVAL textLength AS DWORD _                        ' __in UINT32 textLength
   , BYREF lineBreakpoints AS DWRITE_LINE_BREAKPOINT _  ' __in DWRITE_LINE_BREAKPOINT const* lineBreakpoints
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBidiLevel ( _                              ' VTable offset = 20
     BYVAL textPosition AS DWORD _                      ' __in UINT32 textPosition
   , BYVAL textLength AS DWORD _                        ' __in UINT32 textLength
   , BYVAL explicitLevel AS WORD _                      ' __in UINT8 explicitLevel
   , BYVAL resolvedLevel AS WORD _                      ' __in UINT8 resolvedLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNumberSubstitution ( _                     ' VTable offset = 24
     BYVAL textPosition AS DWORD _                      ' __in UINT32 textPosition
   , BYVAL textLength AS DWORD _                        ' __in UINT32 textLength
   , BYVAL numberSubstitution AS IDWriteNumberSubstitution _ '__in IDWriteNumberSubstitution* numberSubstitution
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDWriteTextAnalyzer interface
' IID = b7e6163e-7f46-43b4-84b3-e4e6249c365d
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDWriteTextAnalyzer = GUID$("{b7e6163e-7f46-43b4-84b3-e4e6249c365d}")

INTERFACE IDWriteTextAnalyzer $IID_IDWriteTextAnalyzer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AnalyzeScript ( _                             ' VTable offset = 12
     BYVAL analysisSource AS IDWriteTextAnalysisSource _ ' __in IDWriteTextAnalysisSource* analysisSource
   , BYVAL textPosition AS DWORD _                      ' __in UINT32 textPosition
   , BYVAL textLength AS DWORD _                        ' __in UINT32 textLength
   , BYVAL analysisSink AS IDWriteTextAnalysisSink _    ' __in IDWriteTextAnalysisSink* analysisSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AnalyzeBidi ( _                               ' VTable offset = 16
     BYVAL analysisSource AS IDWriteTextAnalysisSource _ ' __in IDWriteTextAnalysisSource* analysisSource
   , BYVAL textPosition AS DWORD _                      ' __in UINT32 textPosition
   , BYVAL textLength AS DWORD _                        ' __in UINT32 textLength
   , BYVAL analysisSink AS IDWriteTextAnalysisSink _    ' __in IDWriteTextAnalysisSink* analysisSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AnalyzeLineBreakpoints ( _                    ' VTable offset = 20
     BYVAL analysisSource AS IDWriteTextAnalysisSource _ ' __in IDWriteTextAnalysisSource* analysisSource
   , BYVAL textPosition AS DWORD _                      ' __in UINT32 textPosition
   , BYVAL textLength AS DWORD _                        ' __in UINT32 textLength
   , BYVAL analysisSink AS IDWriteTextAnalysisSink _    ' __in IDWriteTextAnalysisSink* analysisSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGlyphs ( _                                 ' VTable offset = 24
     BYREF textString AS WSTRINGZ _                     ' __in WCHAR const* textString
   , BYVAL textLength AS DWORD _                        ' __in UINT32 textLength
   , BYVAL fontFace AS IDWriteFontFace _                ' __in IDWriteFontFace* fontFace
   , BYVAL isSideways AS LONG _                         ' __in BOOL isSideways
   , BYVAL isRightToLeft AS LONG _                      ' __in BOOL isRightToLeft
   , BYREF scriptAnalysis AS DWRITE_SCRIPT_ANALYSIS _   ' __in DWRITE_SCRIPT_ANALYSIS const* scriptAnalysis
   , BYREF localeName AS WSTRINGZ _                     ' __in_opt WCHAR const* localeName
   , BYVAL numberSubstitution AS IDWriteNumberSubstitution _ ' __in IDWriteNumberSubstitution* numberSubstitution
   , BYREF features AS DWRITE_TYPOGRAPHIC_FEATURES _    ' __in DWRITE_TYPOGRAPHIC_FEATURES const** features
   , BYREF featureRangeLengths AS DWORD _               ' __in UINT32 const* featureRangeLengths
   , BYVAL featureRanges AS DWORD _                     ' __in UINT32 featureRanges
   , BYVAL maxGlyphCount AS DWORD _                     ' __in UINT32 maxGlyphCount
   , BYREF clusterMap AS WORD _                         ' __out UINT16* clusterMap
   , BYREF textProps AS DWRITE_SHAPING_TEXT_PROPERTIES _ ' __out DWRITE_SHAPING_TEXT_PROPERTIES* textProps
   , BYREF glyphIndices AS WORD _                       ' __out UINT16* glyphIndices
   , BYREF glyphProps AS DWRITE_SHAPING_GLYPH_PROPERTIES _ ' __out DWRITE_SHAPING_GLYPH_PROPERTIES* glyphProps
   , BYREF actualGlyphCount AS DWORD _                  ' __out UINT32* actualGlyphCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGlyphPlacements ( _                        ' VTable offset = 28
     BYREF textString AS WSTRINGZ _                     ' __in WCHAR const* textString
   , BYREF clusterMap AS WORD _                         ' __in UINT16 const* clusterMap
   , BYREF textProps AS DWRITE_SHAPING_TEXT_PROPERTIES _ ' __in DWRITE_SHAPING_TEXT_PROPERTIES* textProps
   , BYVAL textLength AS DWORD _                        ' __in UINT32 textLength
   , BYREF glyphIndices AS WORD _                       ' __in UINT16 const* glyphIndices
   , BYREF glyphProps AS DWRITE_SHAPING_GLYPH_PROPERTIES _ ' __in DWRITE_SHAPING_GLYPH_PROPERTIES const* glyphProps
   , BYVAL glyphCount AS DWORD _                        ' __in UINT32 glyphCount
   , BYVAL fontFace AS IDWriteFontFace _                ' __in IDWriteFontFace * fontFace
   , BYVAL fontEmSize AS SINGLE _                       ' __in FLOAT fontEmSize
   , BYVAL isSideways AS LONG _                         ' __in BOOL isSideways
   , BYVAL isRightToLeft AS LONG _                      ' __in BOOL isRightToLeft
   , BYREF scriptAnalysis AS DWRITE_SCRIPT_ANALYSIS _   ' __in DWRITE_SCRIPT_ANALYSIS const* scriptAnalysis
   , BYREF localeName AS WSTRINGZ _                     ' __in_opt WCHAR const* localeName
   , BYREF features AS DWRITE_TYPOGRAPHIC_FEATURES _    ' __in DWRITE_TYPOGRAPHIC_FEATURES const** features
   , BYREF featureRangeLengths AS DWORD _               ' __in UINT32 const* featureRangeLengths
   , BYVAL featureRanges AS DWORD _                     ' __in UINT32 featureRanges
   , BYREF glyphAdvances AS SINGLE _                    ' __out FLOAT* glyphAdvances
   , BYREF glyphOffsets AS DWRITE_GLYPH_OFFSET _        ' __out DWRITE_GLYPH_OFFSET* glyphOffsets
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGdiCompatibleGlyphPlacements ( _           ' VTable offset = 32
     BYREF textString AS WSTRINGZ _                     ' __in WCHAR const* textString
   , BYREF clusterMap AS WORD _                         ' __in UINT16 const* clusterMap
   , BYREF textProps AS DWRITE_SHAPING_TEXT_PROPERTIES _ ' __in DWRITE_SHAPING_TEXT_PROPERTIES* textProps
   , BYVAL textLength AS DWORD _                        ' __in UINT32 textLength
   , BYREF glyphIndices AS WORD _                       ' __in UINT16 const* glyphIndices
   , BYREF glyphProps AS DWRITE_SHAPING_GLYPH_PROPERTIES _ ' __in DWRITE_SHAPING_GLYPH_PROPERTIES const* glyphProps
   , BYVAL glyphCount AS DWORD _                        ' __in UINT32 glyphCount
   , BYVAL fontFace AS IDWriteFontFace _                ' __in IDWriteFontFace * fontFace
   , BYVAL fontEmSize AS SINGLE _                       ' __in FLOAT fontEmSize
   , BYVAL pixelsPerDip AS SINGLE _                     ' __in FLOAT pixelsPerDip
   , BYREF transform AS DWRITE_MATRIX _                 ' __in_opt DWRITE_MATRIX const* transform
   , BYVAL useGdiNatural AS LONG _                      ' __in BOOL useGdiNatural
   , BYVAL isSideways AS LONG _                         ' __in BOOL isSideways
   , BYVAL isRightToLeft AS LONG _                      ' __in BOOL isRightToLeft
   , BYREF scriptAnalysis AS DWRITE_SCRIPT_ANALYSIS _   ' __in DWRITE_SCRIPT_ANALYSIS const* scriptAnalysis
   , BYREF localeName AS WSTRINGZ _                     ' __in_opt WCHAR const* localeName
   , BYREF features AS DWRITE_TYPOGRAPHIC_FEATURES _    ' __in DWRITE_TYPOGRAPHIC_FEATURES const** features
   , BYREF featureRangeLengths AS DWORD _               ' __in UINT32 const* featureRangeLengths
   , BYVAL featureRanges AS DWORD _                     ' __in UINT32 featureRanges
   , BYREF glyphAdvances AS SINGLE _                    ' __out FLOAT* glyphAdvances
   , BYREF glyphOffsets AS DWRITE_GLYPH_OFFSET _        ' __out DWRITE_GLYPH_OFFSET* glyphOffsets
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' // Size = 32 bytes
TYPE DWRITE_GLYPH_RUN DWORD
   fontFace      AS DWORD PTR                 ' __notnull IDWriteFontFace* fontFace
   fontEmSize    AS SINGLE                    ' FLOAT
   glyphCount    AS DWORD                     ' UINT32
   glyphIndices  AS WORD PTR                  ' __field_ecount(glyphCount) UINT16 const* glyphIndices
   glyphAdvances AS SINGLE PTR                ' __field_ecount_opt(glyphCount) FLOAT const* glyphAdvances
   glyphOffsets  AS DWRITE_GLYPH_OFFSET PTR   ' __field_ecount_opt(glyphCount) DWRITE_GLYPH_OFFSET const* glyphOffsets
   isSideways    AS LONG                      ' BOOL
   bidiLevel     AS DWORD                     ' UINT32
END TYPE

' // Size = 20 bytes
TYPE DWRITE_GLYPH_RUN_DESCRIPTION DWORD
   localeName   AS WSTRINGZ PTR   ' __nullterminated WCHAR const*
   string       AS WSTRINGZ PTR   ' __field_ecount(stringLength) WCHAR const*
   stringLength AS DWORD          ' UINT32
   clusterMap   AS WORD PTR       ' __field_ecount(stringLength) UINT16 const*
   textPosition AS DWORD          ' UINT32
END TYPE

' // Size = 32 bytes
TYPE DWRITE_UNDERLINE DWORD
   width            AS SINGLE         ' FLOAT
   thickness        AS SINGLE         ' FLOAT
   offset           AS SINGLE         ' FLOAT
   runHeight        AS SINGLE         ' FLOAT
   readingDirection AS LONG           ' DWRITE_READING_DIRECTION
   flowDirection    AS LONG           ' DWRITE_FLOW_DIRECTION
   localeName       AS WSTRINGZ PTR   ' __nullterminated WCHAR const*
   measuringMode    AS LONG           ' DWRITE_MEASURING_MODE
END TYPE

' // Size = 28 bytes
TYPE DWRITE_STRIKETHROUGH DWORD
   width            AS SINGLE         ' FLOAT
   thickness        AS SINGLE         ' FLOAT
   offset           AS SINGLE         ' FLOAT
   readingDirection AS LONG           ' DWRITE_READING_DIRECTION
   flowDirection    AS LONG           ' DWRITE_FLOW_DIRECTION
   localeName       AS WSTRINGZ PTR   ' __nullterminated WCHAR const*
   measuringMode    AS LONG           ' DWRITE_MEASURING_MODE
END TYPE

' // Size = 24 bytes
TYPE DWRITE_LINE_METRICS DWORD
   length                   AS DWORD    ' UINT32
   trailingWhitespaceLength AS DWORD    ' UINT32
   newlineLength            AS DWORD    ' UINT32
   height                   AS SINGLE   ' FLOAT
   baseline                 AS SINGLE   ' FLOAT
   isTrimmed                AS LONG     ' BOOL
END TYPE

' // Size = 8 bytes
TYPE DWRITE_CLUSTER_METRICS WORD
   width            AS SINGLE                ' FLOAT
   length           AS WORD                  ' UINT16
   canWrapLineAfter AS BIT    * 1  IN WORD   ' UINT16
   isWhitespace     AS BIT    * 1
   isNewline        AS BIT    * 1
   isSoftHyphen     AS BIT    * 1
   isRightToLeft    AS BIT    * 1
   padding          AS BIT    * 11
END TYPE

' // Size = 36 bytes
TYPE DWRITE_TEXT_METRICS DWORD
   left                             AS SINGLE   ' FLOAT
   top                              AS SINGLE   ' FLOAT
   width                            AS SINGLE   ' FLOAT
   widthIncludingTrailingWhitespace AS SINGLE   ' FLOAT
   height                           AS SINGLE   ' FLOAT
   layoutWidth                      AS SINGLE   ' FLOAT
   layoutHeight                     AS SINGLE   ' FLOAT
   maxBidiReorderingDepth           AS DWORD    ' UINT32
   lineCount                        AS DWORD    ' UINT32
END TYPE

' // Size = 16 bytes
TYPE DWRITE_INLINE_OBJECT_METRICS DWORD
   width            AS SINGLE   ' FLOAT
   height           AS SINGLE   ' FLOAT
   baseline         AS SINGLE   ' FLOAT
   supportsSideways AS LONG     ' BOOL
END TYPE

' // Size = 16 bytes
TYPE DWRITE_OVERHANG_METRICS DWORD
   left   AS SINGLE   ' FLOAT
   top    AS SINGLE   ' FLOAT
   right  AS SINGLE   ' FLOAT
   bottom AS SINGLE   ' FLOAT
END TYPE

' // Size = 36 bytes
TYPE DWRITE_HIT_TEST_METRICS DWORD
   textPosition AS DWORD    ' UINT32
   length       AS DWORD    ' UINT32
   left         AS SINGLE   ' FLOAT
   top          AS SINGLE   ' FLOAT
   width        AS SINGLE   ' FLOAT
   height       AS SINGLE   ' FLOAT
   bidiLevel    AS DWORD    ' UINT32
   isText       AS LONG     ' BOOL
   isTrimmed    AS LONG     ' BOOL
END TYPE


' ########################################################################################
' IDWriteInlineObject interface
' IID = 8339FDE3-106F-47ab-8373-1C6295EB10B3
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDWriteInlineObject = GUID$("{8339FDE3-106F-47ab-8373-1C6295EB10B3}")

INTERFACE IDWriteInlineObject $IID_IDWriteInlineObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Draw ( _                                      ' VTable offset = 12
     BYVAL clientDrawingContext AS DWORD _              ' __in void* clientDrawingContext
   , BYVAL renderer AS IDWriteTextRenderer _            ' __in IDWriteTextRenderer* renderer
   , BYVAL originX AS SINGLE _                          ' __in FLOAT originX
   , BYVAL originY AS SINGLE _                          ' __in FLOAT originY
   , BYVAL isSideways AS LONG _                         ' __in BOOL isSideways
   , BYVAL isRightToLeft AS LONG _                      ' __in BOOL isRightToLeft
   , BYVAL clientDrawingEffect AS IUnknown _            ' __in IUnknown* clientDrawingEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMetrics ( _                                ' VTable offset = 16
     BYREF metrics AS DWRITE_INLINE_OBJECT_METRICS _    ' __out DWRITE_INLINE_OBJECT_METRICS* metrics
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOverhangMetrics ( _                        ' VTable offset = 20
     BYREF overhangs AS DWRITE_OVERHANG_METRICS _       ' __out DWRITE_OVERHANG_METRICS* overhangs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBreakConditions ( _                        ' VTable offset = 24
     BYREF breakConditionBefore AS LONG _               ' __out DWRITE_BREAK_CONDITION* breakConditionBefore
   , BYREF breakConditionAfter AS LONG _                ' __out DWRITE_BREAK_CONDITION* breakConditionAfter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDWritePixelSnapping interface
' IID = eaf3a2da-ecf4-4d24-b644-b34f6842024b
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDWritePixelSnapping = GUID$("{eaf3a2da-ecf4-4d24-b644-b34f6842024b}")

INTERFACE IDWritePixelSnapping $IID_IDWritePixelSnapping

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsPixelSnappingDisabled ( _                   ' VTable offset = 12
     BYVAL clientDrawingContext AS DWORD _              ' __in void* clientDrawingContext
   , BYREF isDisabled AS LONG _                         ' __out BOOL* isDisabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentTransform ( _                       ' VTable offset = 16
     BYVAL clientDrawingContext AS DWORD _              ' __in void* clientDrawingContext
   , BYREF transform AS DWRITE_MATRIX _                 ' __out DWRITE_MATRIX* transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelsPerDip ( _                           ' VTable offset = 20
     BYVAL clientDrawingContext AS DWORD _              ' __in void* clientDrawingContext
   , BYREF pixelsPerDip AS SINGLE _                     ' __out FLOAT* pixelsPerDip
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDWriteTextRenderer interface
' IID = ef8a8135-5cc6-45fe-8825-c5a0724eb819
' Inherited interface = IDWritePixelSnapping
' ########################################################################################

$IID_IDWriteTextRenderer = GUID$("{ef8a8135-5cc6-45fe-8825-c5a0724eb819}")

INTERFACE IDWriteTextRenderer $IID_IDWriteTextRenderer

   INHERIT IUnknown

   ' =====================================================================================
   ' IDWritePixelSnapping methods
   ' =====================================================================================
   METHOD IsPixelSnappingDisabled ( _                   ' VTable offset = 12
     BYVAL clientDrawingContext AS DWORD _              ' __in void* clientDrawingContext
   , BYREF isDisabled AS LONG _                         ' __out BOOL* isDisabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentTransform ( _                       ' VTable offset = 16
     BYVAL clientDrawingContext AS DWORD _              ' __in void* clientDrawingContext
   , BYREF transform AS DWRITE_MATRIX _                 ' __out DWRITE_MATRIX* transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelsPerDip ( _                           ' VTable offset = 20
     BYVAL clientDrawingContext AS DWORD _              ' __in void* clientDrawingContext
   , BYREF pixelsPerDip AS SINGLE _                     ' __out FLOAT* pixelsPerDip
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDWriteTextRenderer methods
   ' =====================================================================================
   METHOD DrawGlyphRun ( _                              ' VTable offset = 24
     BYVAL clientDrawingContext AS DWORD _              ' __in void* clientDrawingContext
   , BYVAL baselineOriginX AS SINGLE _                  ' __in FLOAT baselineOriginX
   , BYVAL baselineOriginY AS SINGLE _                  ' __in FLOAT baselineOriginY
   , BYVAL measuringMode AS LONG _                      ' __in DWRITE_MEASURING_MODE measuringMode
   , BYREF glyphRun AS DWRITE_GLYPH_RUN _               ' __in DWRITE_GLYPH_RUN const* glyphRun
   , BYREF glyphRunDescription AS DWRITE_GLYPH_RUN_DESCRIPTION _ ' __in DWRITE_GLYPH_RUN_DESCRIPTION const* glyphRunDescription
   , BYVAL clientDrawingEffect AS IUnknown _            ' __in IUnknown* clientDrawingEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DrawUnderline ( _                             ' VTable offset = 28
     BYVAL clientDrawingContext AS DWORD _              ' __in void* clientDrawingContext
   , BYVAL baselineOriginX AS SINGLE _                  ' __in FLOAT baselineOriginX
   , BYVAL baselineOriginY AS SINGLE _                  ' __in FLOAT baselineOriginY
   , BYREF underline AS DWRITE_UNDERLINE _              ' __in DWRITE_UNDERLINE const* underline
   , BYVAL clientDrawingEffect AS IUnknown _            ' __in IUnknown* clientDrawingEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DrawStrikethrough ( _                         ' VTable offset = 32
     BYVAL clientDrawingContext AS DWORD _              ' __in void* clientDrawingContext
   , BYVAL baselineOriginX AS SINGLE _                  ' __in FLOAT baselineOriginX
   , BYVAL baselineOriginY AS SINGLE _                  ' __in FLOAT baselineOriginY
   , BYREF strikethrough AS DWRITE_STRIKETHROUGH _      ' __in DWRITE_STRIKETHROUGH const* strikethrough
   , BYVAL clientDrawingEffect AS IUnknown _            ' __in IUnknown* clientDrawingEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DrawInlineObject ( _                          ' VTable offset = 36
     BYVAL clientDrawingContext AS DWORD _              ' __in void* clientDrawingContext
   , BYVAL originX AS SINGLE _                          ' __in FLOAT originX
   , BYVAL originY AS SINGLE _                          ' __in FLOAT originY
   , BYVAL inlineObject AS IDWriteInlineObject _        ' __in IDWriteInlineObject* inlineObject
   , BYVAL isSideways AS LONG _                         ' __in BOOL isSideways
   , BYVAL isRightToLeft AS LONG _                      ' __in BOOL isRightToLeft
   , BYVAL clientDrawingEffect AS IUnknown _            ' __in IUnknown* clientDrawingEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDWriteTextLayout interface
' IID = 53737037-6d14-410b-9bfe-0b182bb70961
' Inherited interface = IDWriteTextFormat
' ########################################################################################

$IID_IDWriteTextLayout = GUID$("{53737037-6d14-410b-9bfe-0b182bb70961}")

INTERFACE IDWriteTextLayout $IID_IDWriteTextLayout

   INHERIT IUnknown

   ' =====================================================================================
   ' IDWriteTextFormat methods
   ' =====================================================================================
   METHOD SetTextAlignment ( _                          ' VTable offset = 12
     BYVAL textAlignment AS LONG _                      ' __in DWRITE_TEXT_ALIGNMENT textAlignment
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetParagraphAlignment ( _                     ' VTable offset = 16
     BYVAL paragraphAlignment AS LONG _                 ' __in DWRITE_PARAGRAPH_ALIGNMENT paragraphAlignment
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetWordWrapping ( _                           ' VTable offset = 20
     BYVAL wordWrapping AS LONG _                       ' __in DWRITE_WORD_WRAPPING wordWrapping
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetReadingDirection ( _                       ' VTable offset = 24
     BYVAL readingDirection AS LONG _                   ' __in DWRITE_READING_DIRECTION readingDirection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFlowDirection ( _                          ' VTable offset = 28
     BYVAL flowDirection AS LONG _                      ' __in DWRITE_FLOW_DIRECTION flowDirection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIncrementalTabStop ( _                     ' VTable offset = 32
     BYVAL incrementalTabStop AS SINGLE _               ' __in FLOAT incrementalTabStop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTrimming ( _                               ' VTable offset = 36
     BYREF trimmingOptions AS DWRITE_TRIMMING _         ' __in DWRITE_TRIMMING const* trimmingOptions
   , BYVAL trimmingSign AS IDWriteInlineObject _        ' __in IDWriteInlineObject* trimmingSign
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLineSpacing ( _                            ' VTable offset = 40
     BYVAL lineSpacingMethod AS LONG _                  ' __in DWRITE_LINE_SPACING_METHOD lineSpacingMethod
   , BYVAL lineSpacing AS SINGLE _                      ' __in FLOAT lineSpacing
   , BYVAL baseline AS SINGLE _                         ' __in FLOAT baseline
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTextAlignment ( _                          ' VTable offset = 44
   ) AS LONG                                            ' DWRITE_TEXT_ALIGNMENT
   ' =====================================================================================
   METHOD GetParagraphAlignment ( _                     ' VTable offset = 48
   ) AS LONG                                            ' DWRITE_PARAGRAPH_ALIGNMENT
   ' =====================================================================================
   METHOD GetWordWrapping ( _                           ' VTable offset = 52
   ) AS LONG                                            ' DWRITE_WORD_WRAPPING
   ' =====================================================================================
   METHOD GetReadingDirection ( _                       ' VTable offset = 56
   ) AS LONG                                            ' DWRITE_READING_DIRECTION
   ' =====================================================================================
   METHOD GetFlowDirection ( _                          ' VTable offset = 60
   ) AS LONG                                            ' DWRITE_FLOW_DIRECTION
   ' =====================================================================================
   METHOD GetIncrementalTabStop ( _                     ' VTable offset = 64
   ) AS SINGLE                                          ' FLOAT
   ' =====================================================================================
   METHOD GetTrimming ( _                               ' VTable offset = 68
     BYREF trimmingOptions AS LONG _                    ' __out DWRITE_TRIMMING* trimmingOptions
   , BYREF trimmingSign AS IDWriteInlineObject _        ' __out IDWriteInlineObject** trimmingSign
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLineSpacing ( _                            ' VTable offset = 72
     BYREF lineSpacingMethod AS LONG _                  ' __out DWRITE_LINE_SPACING_METHOD* lineSpacingMethod
   , BYREF lineSpacing AS SINGLE _                      ' __out FLOAT* lineSpacing
   , BYREF baseline AS SINGLE _                         ' __out FLOAT* baseline
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFontCollection ( _                         ' VTable offset = 76
     BYREF fontCollection AS IDWriteFontCollection _    ' __out IDWriteFontCollection** fontCollection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFontFamilyNameLength ( _                   ' VTable offset = 80
   ) AS DWORD                                           ' UINT32
   ' =====================================================================================
   METHOD GetFontFamilyName ( _                         ' VTable offset = 84
     BYREF fontFamilyName AS WSTRINGZ _                 ' __out WCHAR* fontFamilyName
   , BYVAL nameSize AS DWORD _                          ' __in UINT32 nameSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFontWeight ( _                             ' VTable offset = 88
   ) AS LONG                                            ' DWRITE_FONT_WEIGHT
   ' =====================================================================================
   METHOD GetFontStyle ( _                              ' VTable offset = 92
   ) AS LONG                                            ' DWRITE_FONT_STYLE
   ' =====================================================================================
   METHOD GetFontStretch ( _                            ' VTable offset = 96
   ) AS LONG                                            ' DWRITE_FONT_STRETCH
   ' =====================================================================================
   METHOD GetFontSize ( _                               ' VTable offset = 100
   ) AS SINGLE                                          ' FLOAT
   ' =====================================================================================
   METHOD GetLocaleNameLength ( _                       ' VTable offset = 104
   ) AS DWORD                                           ' UINT32
   ' =====================================================================================
   METHOD GetLocaleName ( _                             ' VTable offset = 108
     BYREF localeName AS WSTRINGZ _                     ' __out WCHAR* localeName
   , BYVAL nameSize AS DWORD _                          ' __in UINT32 nameSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDWriteTextLayout methods
   ' =====================================================================================
   METHOD SetMaxWidth ( _                               ' VTable offset = 112
     BYVAL maxWidth AS SINGLE _                         ' __in FLOAT maxWidth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMaxHeight ( _                              ' VTable offset = 116
     BYVAL maxHeight AS SINGLE _                        ' __in FLOAT maxHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFontCollection ( _                         ' VTable offset = 120
     BYVAL fontCollection AS IDWriteFontCollection _    ' __in IDWriteFontCollection* fontCollection
   , BYVAL textRange AS DWRITE_TEXT_RANGE _             ' __in DWRITE_TEXT_RANGE textRange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFontFamilyName ( _                         ' VTable offset = 124
     BYREF fontFamilyName AS WSTRINGZ _                 ' __in WCHAR const* fontFamilyName
   , BYVAL textRange AS DWRITE_TEXT_RANGE _             ' __in DWRITE_TEXT_RANGE textRange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFontWeight ( _                             ' VTable offset = 128
     BYVAL fontWeight AS LONG _                         ' __in DWRITE_FONT_WEIGHT fontWeight
   , BYVAL textRange AS DWRITE_TEXT_RANGE _             ' __in DWRITE_TEXT_RANGE textRange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFontStyle ( _                              ' VTable offset = 132
     BYVAL fontStyle AS LONG _                          ' __in DWRITE_FONT_STYLE fontStyle
   , BYVAL textRange AS DWRITE_TEXT_RANGE _             ' __in DWRITE_TEXT_RANGE textRange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFontStretch ( _                            ' VTable offset = 136
     BYVAL fontStretch AS LONG _                        ' __in DWRITE_FONT_STRETCH fontStretch
   , BYVAL textRange AS DWRITE_TEXT_RANGE _             ' __in DWRITE_TEXT_RANGE textRange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFontSize ( _                               ' VTable offset = 140
     BYVAL fontSize AS SINGLE _                         ' __in FLOAT fontSize
   , BYVAL textRange AS DWRITE_TEXT_RANGE _             ' __in DWRITE_TEXT_RANGE textRange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUnderline ( _                              ' VTable offset = 144
     BYVAL hasUnderline AS LONG _                       ' __in BOOL hasUnderline
   , BYVAL textRange AS DWRITE_TEXT_RANGE _             ' __in DWRITE_TEXT_RANGE textRange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStrikethrough ( _                          ' VTable offset = 148
     BYVAL hasStrikethrough AS LONG _                   ' __in BOOL hasStrikethrough
   , BYVAL textRange AS DWRITE_TEXT_RANGE _             ' __in DWRITE_TEXT_RANGE textRange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDrawingEffect ( _                          ' VTable offset = 152
     BYVAL drawingEffect AS IUnknown _                  ' __in IUnknown* drawingEffect
   , BYVAL textRange AS DWRITE_TEXT_RANGE _             ' __in DWRITE_TEXT_RANGE textRange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInlineObject ( _                           ' VTable offset = 156
     BYVAL inlineObject AS IDWriteInlineObject _        ' __in IDWriteInlineObject* inlineObject
   , BYVAL textRange AS DWRITE_TEXT_RANGE _             ' __in DWRITE_TEXT_RANGE textRange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTypography ( _                             ' VTable offset = 160
     BYVAL typography AS IDWriteTypography _            ' __in IDWriteTypography* typography
   , BYVAL textRange AS DWRITE_TEXT_RANGE _             ' __in DWRITE_TEXT_RANGE textRange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLocaleName ( _                             ' VTable offset = 164
     BYREF localeName AS WSTRINGZ _                     ' __in WCHAR const* localeName
   , BYVAL textRange AS DWRITE_TEXT_RANGE _             ' __in DWRITE_TEXT_RANGE textRange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxWidth ( _                               ' VTable offset = 168
   ) AS SINGLE                                          ' FLOAT
   ' =====================================================================================
   METHOD GetMaxHeight ( _                              ' VTable offset = 172
   ) AS SINGLE                                          ' FLOAT
   ' =====================================================================================
   ' In the inherited IDWriteTextFormat interface there is already a method called GetFontCollection.
   ' =====================================================================================
   METHOD GetFontCollection_ ( _                        ' VTable offset = 176
     BYVAL currentPosition AS DWORD _                   ' __in UINT32 currentPosition
   , BYREF fontCollection AS IDWriteFontCollection _    ' __out IDWriteFontCollection** fontCollection
   , OPTIONAL BYREF textRange AS DWRITE_TEXT_RANGE _    ' __out_opt DWRITE_TEXT_RANGE* textRange = NULL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   ' In the inherited IDWriteTextFormat interface there is already a method called GetFontFamilyNameLength
   ' =====================================================================================
   METHOD GetFontFamilyNameLength_ ( _                  ' VTable offset = 180
     BYVAL currentPosition AS DWORD _                   ' __in UINT32 currentPosition
   , BYREF nameLength AS DWORD _                        ' __out UINT32* nameLength
   , OPTIONAL BYREF textRange AS DWRITE_TEXT_RANGE _    ' __out_opt DWRITE_TEXT_RANGE* textRange = NULL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   ' In the inherited IDWriteTextFormat interface there is already a method called GetFontFamilyName
   ' =====================================================================================
   METHOD GetFontFamilyName_ ( _                        ' VTable offset = 184
     BYVAL currentPosition AS DWORD _                   ' __in UINT32 currentPosition
   , BYREF fontFamilyName AS WSTRINGZ _                 ' __out WCHAR* fontFamilyName
   , BYVAL nameSize AS DWORD _                          ' __in UINT32 nameSize
   , OPTIONAL BYREF textRange AS DWRITE_TEXT_RANGE _    ' __out_opt DWRITE_TEXT_RANGE* textRange = NULL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   ' In the inherited IDWriteTextFormat interface there is already a method called GetFontWeight
   ' =====================================================================================
   METHOD GetFontWeight_ ( _                            ' VTable offset = 188
     BYVAL currentPosition AS DWORD _                   ' __in UINT32 currentPosition
   , BYREF fontWeight AS LONG _                         ' __out DWRITE_FONT_WEIGHT* fontWeight
   , OPTIONAL BYREF textRange AS DWRITE_TEXT_RANGE _    ' __out_opt DWRITE_TEXT_RANGE* textRange = NULL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   ' In the inherited IDWriteTextFormat interface there is already a method called GetFontStyle
   ' =====================================================================================
   METHOD GetFontStyle_ ( _                             ' VTable offset = 192
     BYVAL currentPosition AS DWORD _                   ' __in UINT32 currentPosition
   , BYREF fontStyle AS LONG _                          ' __out DWRITE_FONT_STYLE* fontStyle
   , OPTIONAL BYREF textRange AS DWRITE_TEXT_RANGE _    ' __out_opt DWRITE_TEXT_RANGE* textRange = NULL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   ' In the inherited IDWriteTextFormat interface there is already a method called GetFontStretch
   ' =====================================================================================
   METHOD GetFontStretch_ ( _                           ' VTable offset = 196
     BYVAL currentPosition AS DWORD _                   ' __in UINT32 currentPosition
   , BYREF fontStretch AS LONG _                        ' __out DWRITE_FONT_STRETCH* fontStretch
   , OPTIONAL BYREF textRange AS DWRITE_TEXT_RANGE _    ' __out_opt DWRITE_TEXT_RANGE* textRange = NULL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   ' In the inherited IDWriteTextFormat interface there is already a method called GetFontSize
   ' =====================================================================================
   METHOD GetFontSize_ ( _                              ' VTable offset = 200
     BYVAL currentPosition AS DWORD _                   ' __in UINT32 currentPosition
   , BYREF fontSize AS SINGLE _                         ' __out FLOAT* fontSize
   , OPTIONAL BYREF textRange AS DWRITE_TEXT_RANGE _    ' __out_opt DWRITE_TEXT_RANGE* textRange = NULL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUnderline ( _                              ' VTable offset = 204
     BYVAL currentPosition AS DWORD _                   ' __in UINT32 currentPosition
   , BYREF hasUnderline AS LONG _                       ' __out BOOL* hasUnderline
   , OPTIONAL BYREF textRange AS DWRITE_TEXT_RANGE _    ' __out_opt DWRITE_TEXT_RANGE* textRange = NULL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStrikethrough ( _                          ' VTable offset = 208
     BYVAL currentPosition AS DWORD _                   ' __in UINT32 currentPosition
   , BYREF hasStrikethrough AS LONG _                   ' __out BOOL* hasStrikethrough
   , OPTIONAL BYREF textRange AS DWRITE_TEXT_RANGE _    ' __out_opt DWRITE_TEXT_RANGE* textRange = NULL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDrawingEffect ( _                          ' VTable offset = 212
     BYVAL currentPosition AS DWORD _                   ' __in UINT32 currentPosition
   , BYREF drawingEffect AS IUnknown _                  ' __out IUnknown** drawingEffect
   , OPTIONAL BYREF textRange AS DWRITE_TEXT_RANGE _    ' __out_opt DWRITE_TEXT_RANGE* textRange = NULL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInlineObject ( _                           ' VTable offset = 216
     BYVAL currentPosition AS DWORD _                   ' __in UINT32 currentPosition
   , BYREF inlineObject AS IDWriteInlineObject _        ' __out IDWriteInlineObject** inlineObject
   , OPTIONAL BYREF textRange AS DWRITE_TEXT_RANGE _    ' __out_opt DWRITE_TEXT_RANGE* textRange = NULL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTypography ( _                             ' VTable offset = 220
     BYVAL currentPosition AS DWORD _                   ' __in UINT32 currentPosition
   , BYREF typography AS IDWriteTypography _            ' __out IDWriteTypography** typography
   , OPTIONAL BYREF textRange AS DWRITE_TEXT_RANGE _    ' __out_opt DWRITE_TEXT_RANGE* textRange = NULL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   ' In the inherited IDWriteTextFormat interface there is already a method called GetLocaleNameLength
   ' =====================================================================================
   METHOD GetLocaleNameLength_ ( _                      ' VTable offset = 224
     BYVAL currentPosition AS DWORD _                   ' __in UINT32 currentPosition
   , BYREF nameLength AS DWORD _                        ' __out UINT32* nameLength
   , OPTIONAL BYREF textRange AS DWRITE_TEXT_RANGE _    ' __out_opt DWRITE_TEXT_RANGE* textRange = NULL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   ' In the inherited IDWriteTextFormat interface there is already a method called GetLocaleName
   ' =====================================================================================
   METHOD GetLocaleName_ ( _                            ' VTable offset = 228
     BYVAL currentPosition AS DWORD _                   ' __in UINT32 currentPosition
   , BYREF localName AS WSTRINGZ _                      ' __out WCHAR* localeName
   , BYVAL nameSize AS DWORD _                          ' __in UINT32 nameSize
   , OPTIONAL BYREF textRange AS DWRITE_TEXT_RANGE _    ' __out_opt DWRITE_TEXT_RANGE* textRange = NULL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Draw ( _                                      ' VTable offset = 232
     BYVAL clientDrawingContext AS DWORD _              ' __in void* clientDrawingContext
   , BYVAL renderer AS IDWriteTextRenderer _            ' __in IDWriteTextRenderer* renderer
   , BYVAL originX AS SINGLE _                          ' __in FLOAT originX
   , BYVAL originY AS SINGLE _                          ' __in FLOAT originY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLineMetrics ( _                            ' VTable offset = 236
     BYREF lineMetrics AS DWRITE_LINE_METRICS _         ' __out DWRITE_LINE_METRICS* lineMetrics
   , BYVAL maxLineCount AS DWORD _                      ' __in UINT32 maxLineCount
   , BYREF actualLineCount AS DWORD _                   ' __out UINT32* actualLineCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMetrics ( _                                ' VTable offset = 240
     BYREF textMetrics AS DWRITE_TEXT_METRICS _         ' __out DWRITE_TEXT_METRICS* textMetrics
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOverhangMetrics ( _                        ' VTable offset = 244
     BYREF overhangs AS DWRITE_OVERHANG_METRICS _       ' __out DWRITE_OVERHANG_METRICS* overhangs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClusterMetrics ( _                         ' VTable offset = 248
     BYREF clusterMetrics AS DWRITE_CLUSTER_METRICS _   ' __out DWRITE_CLUSTER_METRICS* clusterMetrics
   , BYVAL maxClusterCount AS DWORD _                   ' __in UINT32 maxClusterCount
   , BYREF actualClusterCount AS DWORD _                ' __out UINT32* actualClusterCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DetermineMinWidth ( _                         ' VTable offset = 252
     BYREF minWidth AS SINGLE _                         ' __out FLOAT* minWidth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HitTestPoint ( _                              ' VTable offset = 256
     BYVAL pointX AS SINGLE _                           ' __in FLOAT pointX
   , BYVAL pointY AS SINGLE _                           ' __in FLOAT pointY
   , BYREF isTrailingHit AS LONG _                      ' __out BOOL* isTrailingHit
   , BYREF isInside AS LONG _                           ' __out BOOL* isInside
   , BYREF hitTestMetrics AS DWRITE_HIT_TEST_METRICS _  ' __out DWRITE_HIT_TEST_METRICS* hitTestMetrics
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HitTestTextPosition ( _                       ' VTable offset = 260
     BYVAL textPosition AS DWORD _                      ' __in UINT32 textPosition
   , BYVAL isTrailingHit AS LONG _                      ' __in BOOL isTrailingHit
   , BYREF pointX AS SINGLE _                           ' __out FLOAT* pointX
   , BYREF pointY AS SINGLE _                           ' __out FLOAT* pointY
   , BYREF hitTestMetrics AS DWRITE_HIT_TEST_METRICS _  ' __out DWRITE_HIT_TEST_METRICS* hitTestMetrics
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HitTestTextRange ( _                          ' VTable offset = 264
     BYVAL textPosition AS DWORD _                      ' __in UINT32 textPosition
   , BYVAL textLength AS DWORD _                        ' __in UINT32 textLength
   , BYVAL originX AS SINGLE _                          ' __in FLOAT originX
   , BYVAL originY AS SINGLE _                          ' __in FLOAT originY
   , BYREF hitTestMetrics AS DWRITE_HIT_TEST_METRICS _  ' __out DWRITE_HIT_TEST_METRICS* hitTestMetrics
   , BYVAL maxHitTestMetricsCount AS DWORD _            ' __in UINT32 maxHitTestMetricsCount
   , BYREF actualHitTestMetricsCount AS DWORD _         ' __out UINT32* actualHitTestMetricsCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDWriteBitmapRenderTarget interface
' IID = 5e5a32a3-8dff-4773-9ff6-0696eab77267
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDWriteBitmapRenderTarget = GUID$("{5e5a32a3-8dff-4773-9ff6-0696eab77267}")

INTERFACE IDWriteBitmapRenderTarget $IID_IDWriteBitmapRenderTarget

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DrawGlyphRun ( _                              ' VTable offset = 12
     BYVAL baselineOriginX AS SINGLE _                  ' __in FLOAT baselineOriginX
   , BYVAL baselineOriginY AS SINGLE _                  ' __in FLOAT baselineOriginY
   , BYVAL measuringMode AS LONG _                      ' __in DWRITE_MEASURING_MODE measuringMode
   , BYREF glyphRun AS DWRITE_GLYPH_RUN _               ' __in DWRITE_GLYPH_RUN const* glyphRun
   , BYVAL renderingParams AS IDWriteRenderingParams _  ' __in IDWriteRenderingParams* renderingParams
   , BYVAL textColor AS DWORD _                         ' __in COLORREF textColor
   , OPTIONAL BYREF blackBoxRect AS RECT _              ' __out_opt RECT* blackBoxRect = NULL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMemoryDC ( _                               ' VTable offset = 16
   ) AS DWORD                                           ' HDC
   ' =====================================================================================
   METHOD GetPixelsPerDip ( _                           ' VTable offset = 20
   ) AS SINGLE                                          ' FLOAT
   ' =====================================================================================
   METHOD SetPixelsPerDip ( _                           ' VTable offset = 24
     BYVAL pixelsPerDip AS SINGLE _                     ' __in FLOAT pixelsPerDip
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentTransform ( _                       ' VTable offset = 28
     BYREF transform AS DWRITE_MATRIX _                 ' __out DWRITE_MATRIX* transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCurrentTransform ( _                       ' VTable offset = 32
     OPTIONAL BYREF transform AS DWRITE_MATRIX _        ' __in_opt DWRITE_MATRIX const* transform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 36
     BYREF size AS SIZE _                               ' __out SIZE* size
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Resize ( _                                    ' VTable offset = 40
     BYVAL width AS DWORD _                             ' __in UINT32 width
   , BYVAL height AS DWORD _                            ' __in UINT32 height
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDWriteGdiInterop interface
' IID = 1edd9491-9853-4299-898f-6432983b6f3a
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDWriteGdiInterop = GUID$("{1edd9491-9853-4299-898f-6432983b6f3a}")

INTERFACE IDWriteGdiInterop $IID_IDWriteGdiInterop

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateFontFromLOGFONT ( _                     ' VTable offset = 12
     BYREF logFont AS LOGFONTW _                        ' __in LOGFONTW const* logFont
   , BYREF font AS IDWriteFont _                        ' __out IDWriteFont** font
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertFontToLOGFONT ( _                      ' VTable offset = 16
     BYVAL font AS IDWriteFont _                        ' __in IDWriteFont* font
   , BYREF logFont AS LOGFONTW _                        ' __out LOGFONTW* logFont
   , BYREF isSystemFont AS LONG _                       ' __out BOOL* isSystemFont
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertFontFaceToLOGFONT ( _                  ' VTable offset = 20
     BYVAL font AS IDWriteFontFace _                    ' __in IDWriteFontFace* font
   , BYREF logFont AS LOGFONTW _                        ' __out LOGFONTW* logFont
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateFontFaceFromHdc ( _                     ' VTable offset = 24
     BYVAL hdc AS DWORD _                               ' __in HDC hdc
   , BYREF fontFace AS IDWriteFontFace _                ' __out IDWriteFontFace** fontFace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapRenderTarget ( _                  ' VTable offset = 28
     BYVAL hdc AS DWORD _                               ' __in_opt HDC hdc
   , BYVAL width AS DWORD _                             ' __in UINT32 width
   , BYVAL height AS DWORD _                            ' __in UINT32 height
   , BYREF renderTarget AS IDWriteBitmapRenderTarget _  ' __out IDWriteBitmapRenderTarget** renderTarget
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' enum DWRITE_TEXTURE_TYPE
%DWRITE_TEXTURE_ALIASED_1x1 = 0
%DWRITE_TEXTURE_CLEARTYPE_3x1 = 1

%DWRITE_ALPHA_MAX = 255

' ########################################################################################
' IDWriteGlyphRunAnalysis interface
' IID = 7d97dbf7-e085-42d4-81e3-6a883bded118
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDWriteGlyphRunAnalysis = GUID$("{7d97dbf7-e085-42d4-81e3-6a883bded118}")

INTERFACE IDWriteGlyphRunAnalysis $IID_IDWriteGlyphRunAnalysis

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAlphaTextureBounds ( _                     ' VTable offset = 12
     BYVAL textureType AS LONG _                        ' __in DWRITE_TEXTURE_TYPE textureType
   , BYREF textureBounds AS RECT _                      ' __out RECT* textureBounds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateAlphaTexture ( _                        ' VTable offset = 16
     BYVAL textureType AS LONG _                        ' __in DWRITE_TEXTURE_TYPE textureType
   , BYREF textureBounds AS RECT _                      ' __in RECT const* textureBounds
   , BYREF alphaValues AS BYTE _                        ' __out_bcount(bufferSize) BYTE* alphaValues
   , BYVAL bufferSize AS DWORD _                        ' __in UINT32 bufferSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAlphaBlendParams ( _                       ' VTable offset = 20
     BYVAL renderingParams AS IDWriteRenderingParams _  ' __in IDWriteRenderingParams* renderingParams
   , BYREF blendGamma AS SINGLE _                       ' __out FLOAT* blendGamma
   , BYREF blendEnhancedContrast AS SINGLE _            ' __out FLOAT* blendEnhancedContrast
   , BYREF blendClearTypeLevel AS SINGLE _              ' __out FLOAT* blendClearTypeLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDWriteFactory interface
' IID = b859ee5a-d838-4b5b-a2e8-1adc7d93db48
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDWriteFactory = GUID$("{b859ee5a-d838-4b5b-a2e8-1adc7d93db48}")

INTERFACE IDWriteFactory $IID_IDWriteFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSystemFontCollection ( _                   ' VTable offset = 12
     BYREF fontCollection AS IDWriteFontCollection _    ' __out IDWriteFontCollection** fontCollection
   , BYVAL checkForUpdates AS LONG _                    ' __in BOOL checkForUpdates = FALSE
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateCustomFontCollection ( _                ' VTable offset = 16
     BYVAL collectionLoader AS IDWriteFontCollectionLoader _ ' __in IDWriteFontCollectionLoader* collectionLoader
   , BYREF collectionKey AS DWORD _                     ' __in void const* collectionKey
   , BYVAL collectionKeySize AS DWORD _                 ' __in UINT32 collectionKeySize
   , BYREF fontCollection AS IDWriteFontCollection _    ' __out IDWriteFontCollection** fontCollection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterFontCollectionLoader ( _              ' VTable offset = 20
     BYVAL fontCollectionLoader AS IDWriteFontCollectionLoader _ '__in IDWriteFontCollectionLoader* fontCollectionLoader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterFontCollectionLoader ( _            ' VTable offset = 24
     BYVAL fontCollectionLoader AS IDWriteFontCollectionLoader _ ' __in IDWriteFontCollectionLoader* fontCollectionLoader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateFontFileReference ( _                   ' VTable offset = 28
     BYREF filePath AS WSTRINGZ _                       ' __in WCHAR const* filePath
   , BYREF lastWriteTime AS FILETIME _                  ' __in_opt FILETIME const* lastWriteTime
   , BYREF fontFile AS IDWriteFontFile _                ' __out IDWriteFontFile** fontFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateCustomFontFileReference ( _             ' VTable offset = 32
     BYREF fontFileReferenceKey AS DWORD _              ' __in void const* fontFileReferenceKey
   , BYVAL fontFileReferenceKeySize AS DWORD _          ' __in UINT32 fontFileReferenceKeySize
   , BYVAL fontFileLoader AS IDWriteFontFileLoader _    ' __in IDWriteFontFileLoader* fontFileLoader
   , BYREF fontFile AS IDWriteFontFile _                ' __out IDWriteFontFile** fontFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateFontFace ( _                            ' VTable offset = 36
     BYVAL fontFaceType AS LONG _                       ' __in DWRITE_FONT_FACE_TYPE fontFaceType
   , BYVAL numberOfFiles AS DWORD _                     ' __in UINT32 numberOfFiles
   , BYREF fontFiles AS IDWriteFontFile _               ' __in IDWriteFontFile* const* fontFiles
   , BYVAL faceIndex AS DWORD _                         ' __in UINT32 faceIndex
   , BYVAL fontFaceSimulationFlags AS DWORD _           ' __in DWRITE_FONT_SIMULATIONS fontFaceSimulationFlags
   , BYREF fontFace AS IDWriteFontFace _                ' __out IDWriteFontFace** fontFace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRenderingParams ( _                     ' VTable offset = 40
     BYREF renderingParams AS IDWriteRenderingParams _  ' __out IDWriteRenderingParams** renderingParams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateMonitorRenderingParams ( _              ' VTable offset = 44
     BYVAL monitor AS DWORD _                           ' __in HMONITOR monitor
   , BYREF renderingParams AS IDWriteRenderingParams _  ' __out IDWriteRenderingParams** renderingParams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateCustomRenderingParams ( _               ' VTable offset = 48
     BYVAL gamma AS SINGLE _                            ' __in FLOAT gamma
   , BYVAL enhancedContrast AS SINGLE _                 ' __in FLOAT enhancedContrast
   , BYVAL clearTypeLevel AS SINGLE _                   ' __in FLOAT clearTypeLevel
   , BYVAL pixelGeometry AS LONG _                      ' __in DWRITE_PIXEL_GEOMETRY pixelGeometry
   , BYVAL renderingMode AS LONG _                      ' __in DWRITE_RENDERING_MODE renderingMode
   , BYREF renderingParams AS IDWriteRenderingParams _  ' __out IDWriteRenderingParams** renderingParams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterFontFileLoader ( _                    ' VTable offset = 52
     BYVAL fontFileLoader AS IDWriteFontFileLoader _    ' __in IDWriteFontFileLoader* fontFileLoader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterFontFileLoader ( _                  ' VTable offset = 56
     BYVAL fontFileLoader AS IDWriteFontFileLoader _    ' __in IDWriteFontFileLoader* fontFileLoader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateTextFormat ( _                          ' VTable offset = 60
     BYREF fontFamilyName AS WSTRINGZ _                 ' __in WCHAR const* fontFamilyName
   , BYVAL fontCollection AS IDWriteFontCollection _    ' __in IDWriteFontCollection* fontCollection
   , BYVAL fontWeight AS LONG _                         ' __in DWRITE_FONT_WEIGHT fontWeight
   , BYVAL fontStyle AS LONG _                          ' __in DWRITE_FONT_STYLE fontStyle
   , BYVAL fontStretch AS LONG _                        ' __in DWRITE_FONT_STRETCH fontStretch
   , BYVAL fontSize AS SINGLE _                         ' __in FLOAT fontSize
   , BYREF localeName AS WSTRINGZ _                     ' __in WCHAR const* localeName
   , BYREF textFormat AS IDWriteTextFormat _            ' __out IDWriteTextFormat** textFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateTypography ( _                          ' VTable offset = 64
     BYREF typography AS IDWriteTypography _            ' __out IDWriteTypography** typography
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGdiInterop ( _                             ' VTable offset = 68
     BYREF gdiInterop AS IDWriteGdiInterop _            ' __out IDWriteGdiInterop** gdiInterop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateTextLayout ( _                          ' VTable offset = 72
     BYREF string AS WSTRINGZ _                         ' __in WCHAR const* string
   , BYVAL stringLength AS DWORD _                      ' __in UINT32 stringLength
   , BYVAL textFormat AS IDWriteTextFormat _            ' __in IDWriteTextFormat* textFormat
   , BYVAL maxWidth AS SINGLE _                         ' __in FLOAT maxWidth
   , BYVAL maxHeight AS SINGLE _                        ' __in FLOAT maxHeight
   , BYREF textLayout AS IDWriteTextLayout _            ' __out IDWriteTextLayout** textLayout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateGdiCompatibleTextLayout ( _             ' VTable offset = 76
     BYREF string AS WSTRINGZ _                         ' __in WCHAR const* string
   , BYVAL stringLength AS DWORD _                      ' __in UINT32 stringLength
   , BYVAL textFormat AS IDWriteTextFormat _            ' __in IDWriteTextFormat* textFormat
   , BYVAL layoutWidth AS SINGLE _                      ' __in FLOAT layoutWidth
   , BYVAL layoutHeight AS SINGLE _                     ' __in FLOAT layoutHeight
   , BYVAL pixelsPerDip AS SINGLE _                     ' __in FLOAT pixelsPerDip
   , BYREF transform AS DWRITE_MATRIX _                 ' __in_opt DWRITE_MATRIX const* transform
   , BYVAL useGdiNatural AS LONG _                      ' __in BOOL useGdiNatural
   , BYREF textLayout AS IDWriteTextLayout _            ' __out IDWriteTextLayout** textLayout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateEllipsisTrimmingSign ( _                ' VTable offset = 80
     BYVAL textFormat AS IDWriteTextFormat _            ' __in IDWriteTextFormat* textFormat
   , BYREF trimmingSign AS IDWriteInlineObject _        ' __out IDWriteInlineObject** trimmingSign
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateTextAnalyzer ( _                        ' VTable offset = 84
     BYREF textAnalyzer AS IDWriteTextAnalyzer _        ' __out IDWriteTextAnalyzer** textAnalyzer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateNumberSubstitution ( _                  ' VTable offset = 88
     BYVAL substitutionMethod AS LONG _                 ' __in DWRITE_NUMBER_SUBSTITUTION_METHOD substitutionMethod
   , BYREF localeName AS WSTRINGZ _                     ' __in WCHAR const* localeName
   , BYVAL ignoreUserOverride AS LONG _                 ' __in BOOL ignoreUserOverride
   , BYREF numberSubstitution AS IDWriteNumberSubstitution _ '__out IDWriteNumberSubstitution** numberSubstitution
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateGlyphRunAnalysis ( _                    ' VTable offset = 92
     BYREF glyphRun AS DWRITE_GLYPH_RUN _               ' __in DWRITE_GLYPH_RUN const* glyphRun
   , BYVAL pixelsPerDip AS SINGLE _                     ' __in FLOAT pixelsPerDip
   , BYREF transform AS DWRITE_MATRIX _                 ' __in_opt DWRITE_MATRIX const* transform
   , BYVAL renderingMode AS LONG _                      ' __in DWRITE_RENDERING_MODE renderingMode
   , BYVAL measuringMode AS LONG _                      ' __in DWRITE_MEASURING_MODE measuringMode
   , BYVAL baselineOriginX AS SINGLE _                  ' __in FLOAT baselineOriginX
   , BYVAL baselineOriginY AS SINGLE _                  ' __in FLOAT baselineOriginY
   , BYREF glyphRunAnalysis AS IDWriteGlyphRunAnalysis _ ' __out IDWriteGlyphRunAnalysis** glyphRunAnalysis
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

DECLARE FUNCTION DWriteCreateFactory IMPORT "Dwrite.dll" ALIAS "DWriteCreateFactory" ( _
   BYVAL factoryType AS LONG _                          ' __in DWRITE_FACTORY_TYPE factoryType
 , BYREF iid AS GUID _                                  ' __in REFIID iid
 , BYREF factory AS IUnknown _                          ' __out IUnknown **factory
 ) AS LONG                                              ' HRESULT

'// Macros used to define DirectWrite error codes.
'#define FACILITY_DWRITE 0x898
'#define DWRITE_ERR_BASE 0x5000
'#define MAKE_DWRITE_HR(severity, code) MAKE_HRESULT(severity, FACILITY_DWRITE, (DWRITE_ERR_BASE + code))
'#define MAKE_DWRITE_HR_ERR(code) MAKE_DWRITE_HR(SEVERITY_ERROR, code)

%FACILITY_DWRITE = &H898
%DWRITE_ERR_BASE = &H5000
MACRO MAKE_DWRITE_HR (severity, code) = MAKE_HRESULT(severity, %FACILITY_DWRITE, %DWRITE_ERR_BASE + code)
MACRO MAKE_DWRITE_HR_ERR (code) = MAKE_DWRITE_HR(%SEVERITY_ERROR, code)

'// Indicates an error in an input file such as a font file.
'#define DWRITE_E_FILEFORMAT             MAKE_DWRITE_HR_ERR(0x000)
%DWRITE_E_FILEFORMAT             = &H88985000&

'// Indicates an error originating in DirectWrite code, which is not expected to occur but is safe to recover from.
'#define DWRITE_E_UNEXPECTED             MAKE_DWRITE_HR_ERR(0x001)
%DWRITE_E_UNEXPECTED             = &H88985001&

'// Indicates the specified font does not exist.
'#define DWRITE_E_NOFONT                 MAKE_DWRITE_HR_ERR(0x002)
%DWRITE_E_NOFONT                 = &H88985002&

'// A font file could not be opened because the file, directory, network location, drive, or other storage
'// location does not exist or is unavailable.
'#define DWRITE_E_FILENOTFOUND           MAKE_DWRITE_HR_ERR(0x003)
%DWRITE_E_FILENOTFOUND           = &H88985003&

'// A font file exists but could not be opened due to access denied, sharing violation, or similar error.
'#define DWRITE_E_FILEACCESS             MAKE_DWRITE_HR_ERR(0x004)
%DWRITE_E_FILEACCESS             = &H88985004&

'// A font collection is obsolete due to changes in the system.
'#define DWRITE_E_FONTCOLLECTIONOBSOLETE MAKE_DWRITE_HR_ERR(0x005)
%DWRITE_E_FONTCOLLECTIONOBSOLETE = &H88985005&

'// The given interface is already registered.
'#define DWRITE_E_ALREADYREGISTERED      MAKE_DWRITE_HR_ERR(0x006)
%DWRITE_E_ALREADYREGISTERED      = &H88985006&
