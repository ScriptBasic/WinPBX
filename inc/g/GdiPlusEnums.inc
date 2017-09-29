' ########################################################################################
' Microsoft Windows
' File: GdiPlusEnums.inc
' Contents: GDI+ Enumeration Types
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%GDIPLUSENUMS_INC = 1

'//--------------------------------------------------------------------------
'// Default bezier flattening tolerance in device pixels.
'//--------------------------------------------------------------------------

'const float FlatnessDefault = 1.0f/4.0f;
MACRO FlatnessDefault = 0.25!

'//--------------------------------------------------------------------------
'// Graphics and Container State cookies
'//--------------------------------------------------------------------------

'typedef UINT     GraphicsState;
'typedef UINT     GraphicsContainer;

'//--------------------------------------------------------------------------
'// Fill mode constants
'//--------------------------------------------------------------------------

' enum FillMode
%FillModeAlternate = 0
%FillModeWinding   = 1

'//--------------------------------------------------------------------------
'// Quality mode constants
'//--------------------------------------------------------------------------

' enum QualityMode
%QualityModeInvalid   = -1
%QualityModeDefault   = 0
%QualityModeLow       = 1 ' // Best performance
%QualityModeHigh      = 2 ' // Best rendering quality

'//--------------------------------------------------------------------------
'// Alpha Compositing mode constants
'//--------------------------------------------------------------------------

' enum CompositingMode
%CompositingModeSourceOver = 0
%CompositingModeSourceCopy = 1

'//--------------------------------------------------------------------------
'// Alpha Compositing quality constants
'//--------------------------------------------------------------------------

' enum CompositingQuality
%CompositingQualityInvalid          = %QualityModeInvalid
%CompositingQualityDefault          = %QualityModeDefault
%CompositingQualityHighSpeed        = %QualityModeLow
%CompositingQualityHighQuality      = %QualityModeHigh
%CompositingQualityGammaCorrected   = 3
%CompositingQualityAssumeLinear     = 4

'//--------------------------------------------------------------------------
'// Unit constants
'//--------------------------------------------------------------------------

' enum Unit
%UnitWorld      = 0 ' // 0 -- World coordinate (non-physical unit)
%UnitDisplay    = 1 ' // 1 -- Variable -- for PageTransform only
%UnitPixel      = 2 ' // 2 -- Each unit is one device pixel.
%UnitPoint      = 3 ' // 3 -- Each unit is a printer's point, or 1/72 inch.
%UnitInch       = 4 ' // 4 -- Each unit is 1 inch.
%UnitDocument   = 5 ' // 5 -- Each unit is 1/300 inch.
%UnitMillimeter = 6 ' // 6 -- Each unit is 1 millimeter.

'//--------------------------------------------------------------------------
'// MetafileFrameUnit
'//
'// The frameRect for creating a metafile can be specified in any of these
'// units.  There is an extra frame unit value (MetafileFrameUnitGdi) so
'// that units can be supplied in the same units that GDI expects for
'// frame rects -- these units are in .01 (1/100ths) millimeter units
'// as defined by GDI.
'//--------------------------------------------------------------------------

' enum MetafileFrameUnit
%MetafileFrameUnitPixel      = %UnitPixel
%MetafileFrameUnitPoint      = %UnitPoint
%MetafileFrameUnitInch       = %UnitInch
%MetafileFrameUnitDocument   = %UnitDocument
%MetafileFrameUnitMillimeter = %UnitMillimeter
%MetafileFrameUnitGdi        = 7                ' // GDI compatible .01 MM units

'//--------------------------------------------------------------------------
'// Coordinate space identifiers
'//--------------------------------------------------------------------------

' enum CoordinateSpace
%CoordinateSpaceWorld  = 0
%CoordinateSpacePage   = 1
%CoordinateSpaceDevice = 2

'//--------------------------------------------------------------------------
'// Various wrap modes for brushes
'//--------------------------------------------------------------------------

' enum WrapMode
%WrapModeTile         = 0
%WrapModeTileFlipX    = 1
%WrapModeTileFlipY    = 2
%WrapModeTileFlipXY   = 3
%WrapModeClamp        = 4

'//--------------------------------------------------------------------------
'// Various hatch styles
'//--------------------------------------------------------------------------

' enum HatchStyle
%HatchStyleHorizontal                   = 0
%HatchStyleVertical                     = 1
%HatchStyleForwardDiagonal              = 2
%HatchStyleBackwardDiagonal             = 3
%HatchStyleCross                        = 4
%HatchStyleDiagonalCross                = 5
%HatchStyle05Percent                    = 6
%HatchStyle10Percent                    = 7
%HatchStyle20Percent                    = 8
%HatchStyle25Percent                    = 9
%HatchStyle30Percent                    = 10
%HatchStyle40Percent                    = 11
%HatchStyle50Percent                    = 12
%HatchStyle60Percent                    = 13
%HatchStyle70Percent                    = 14
%HatchStyle75Percent                    = 15
%HatchStyle80Percent                    = 16
%HatchStyle90Percent                    = 17
%HatchStyleLightDownwardDiagonal        = 18
%HatchStyleLightUpwardDiagonal          = 19
%HatchStyleDarkDownwardDiagonal         = 20
%HatchStyleDarkUpwardDiagonal           = 21
%HatchStyleWideDownwardDiagonal         = 22
%HatchStyleWideUpwardDiagonal           = 23
%HatchStyleLightVertical                = 24
%HatchStyleLightHorizontal              = 25
%HatchStyleNarrowVertical               = 26
%HatchStyleNarrowHorizontal             = 27
%HatchStyleDarkVertical                 = 28
%HatchStyleDarkHorizontal               = 29
%HatchStyleDashedDownwardDiagonal       = 30
%HatchStyleDashedUpwardDiagonal         = 31
%HatchStyleDashedHorizontal             = 32
%HatchStyleDashedVertical               = 33
%HatchStyleSmallConfetti                = 34
%HatchStyleLargeConfetti                = 35
%HatchStyleZigZag                       = 36
%HatchStyleWave                         = 37
%HatchStyleDiagonalBrick                = 38
%HatchStyleHorizontalBrick              = 39
%HatchStyleWeave                        = 40
%HatchStylePlaid                        = 41
%HatchStyleDivot                        = 42
%HatchStyleDottedGrid                   = 43
%HatchStyleDottedDiamond                = 44
%HatchStyleShingle                      = 45
%HatchStyleTrellis                      = 46
%HatchStyleSphere                       = 47
%HatchStyleSmallGrid                    = 48
%HatchStyleSmallCheckerBoard            = 49
%HatchStyleLargeCheckerBoard            = 50
%HatchStyleOutlinedDiamond              = 51
%HatchStyleSolidDiamond                 = 52

%HatchStyleTotal     = 53
%HatchStyleLargeGrid = %HatchStyleCross

%HatchStyleMin       = %HatchStyleHorizontal
%HatchStyleMax       = %HatchStyleTotal - 1

'//--------------------------------------------------------------------------
'// Dash style constants
'//--------------------------------------------------------------------------

' enum DashStyle
%DashStyleSolid          = 0
%DashStyleDash           = 1
%DashStyleDot            = 2
%DashStyleDashDot        = 3
%DashStyleDashDotDot     = 4
%DashStyleCustom         = 5

'//--------------------------------------------------------------------------
'// Dash cap constants
'//--------------------------------------------------------------------------

' enum DashCap
%DashCapFlat     = 0
%DashCapRound    = 2
%DashCapTriangle = 3

'//--------------------------------------------------------------------------
'// Line cap constants (only the lowest 8 bits are used).
'//--------------------------------------------------------------------------

' enum LineCap
%LineCapFlat          = 0
%LineCapSquare        = 1
%LineCapRound         = 2
%LineCapTriangle      = 3

%LineCapNoAnchor      = &H10   ' corresponds to flat cap
%LineCapSquareAnchor  = &H11   ' corresponds to square cap
%LineCapRoundAnchor   = &H12   ' corresponds to round cap
%LineCapDiamondAnchor = &H13   ' corresponds to triangle cap
%LineCapArrowAnchor   = &H14   ' no correspondence

%LineCapCustom        = &HFF   ' custom cap

%LineCapAnchorMask    = &HF0   ' mask to check for anchor or not.

'//--------------------------------------------------------------------------
'// Custom Line cap type constants
'//--------------------------------------------------------------------------

' enum CustomLineCapType
%CustomLineCapTypeDefault         = 0
%CustomLineCapTypeAdjustableArrow = 1

'//--------------------------------------------------------------------------
'// Line join constants
'//--------------------------------------------------------------------------

' enum LineJoin
%LineJoinMiter        = 0
%LineJoinBevel        = 1
%LineJoinRound        = 2
%LineJoinMiterClipped = 3

'//--------------------------------------------------------------------------
'// Path point types (only the lowest 8 bits are used.)
'//  The lowest 3 bits are interpreted as point type
'//  The higher 5 bits are reserved for flags.
'//--------------------------------------------------------------------------

' enum PathPointType
%PathPointTypeStart           = 0    ' // move
%PathPointTypeLine            = 1    ' // line
%PathPointTypeBezier          = 3    ' // default Bezier (= cubic Bezier)
%PathPointTypePathTypeMask    = &H07 ' // type mask (lowest 3 bits).
%PathPointTypeDashMode        = &H10 ' // currently in dash mode.
%PathPointTypePathMarker      = &H20 ' // a marker for the path.
%PathPointTypeCloseSubpath    = &H80 ' // closed flag

' // Path types used for advanced path.

%PathPointTypeBezier3    = 3         ' // cubic Bezier


'//--------------------------------------------------------------------------
'// WarpMode constants
'//--------------------------------------------------------------------------

' enum WarpMode
%WarpModePerspective     = 0
%WarpModeBilinear        = 1

'//--------------------------------------------------------------------------
'// LineGradient Mode
'//--------------------------------------------------------------------------

' enum LinearGradientMode
%LinearGradientModeHorizontal         = 0
%LinearGradientModeVertical           = 1
%LinearGradientModeForwardDiagonal    = 2
%LinearGradientModeBackwardDiagonal   = 3

'//--------------------------------------------------------------------------
'// Region Comine Modes
'//--------------------------------------------------------------------------

' enum CombineMode
%CombineModeReplace      = 0
%CombineModeIntersect    = 1
%CombineModeUnion        = 2
%CombineModeXor          = 3
%CombineModeExclude      = 4
%CombineModeComplement   = 5 ' (Exclude From)

'//--------------------------------------------------------------------------
'// Image types
'//--------------------------------------------------------------------------

' enum ImageType
%ImageTypeUnknown   = 0
%ImageTypeBitmap    = 1
%ImageTypeMetafile  = 2

'//--------------------------------------------------------------------------
'// Interpolation modes
'//--------------------------------------------------------------------------

' enum InterpolationMode
%InterpolationModeInvalid             = %QualityModeInvalid
%InterpolationModeDefault             = %QualityModeDefault
%InterpolationModeLowQuality          = %QualityModeLow
%InterpolationModeHighQuality         = %QualityModeHigh
%InterpolationModeBilinear            = 3
%InterpolationModeBicubic             = 4
%InterpolationModeNearestNeighbor     = 5
%InterpolationModeHighQualityBilinear = 6
%InterpolationModeHighQualityBicubic  = 7

'//--------------------------------------------------------------------------
'// Pen types
'//--------------------------------------------------------------------------

' enum PenAlignment
%PenAlignmentCenter = 0
%PenAlignmentInset  = 1

'//--------------------------------------------------------------------------
'// Brush types
'//--------------------------------------------------------------------------

' enum BrushType
%BrushTypeSolidColor     = 0
%BrushTypeHatchFill      = 1
%BrushTypeTextureFill    = 2
%BrushTypePathGradient   = 3
%BrushTypeLinearGradient = 4

'//--------------------------------------------------------------------------
'// Pen's Fill types
'//--------------------------------------------------------------------------

' enum PenType
%PenTypeSolidColor     = %BrushTypeSolidColor
%PenTypeHatchFill      = %BrushTypeHatchFill
%PenTypeTextureFill    = %BrushTypeTextureFill
%PenTypePathGradient   = %BrushTypePathGradient
%PenTypeLinearGradient = %BrushTypeLinearGradient
%PenTypeUnknown        = -1

'//--------------------------------------------------------------------------
'// Matrix Order
'//--------------------------------------------------------------------------

' enum MatrixOrder
%MatrixOrderPrepend = 0
%MatrixOrderAppend  = 1

'//--------------------------------------------------------------------------
'// Generic font families
'//--------------------------------------------------------------------------

' enum GenericFontFamily
%GenericFontFamilySerif     = 0
%GenericFontFamilySansSerif = 1
%GenericFontFamilyMonospace = 2

'//--------------------------------------------------------------------------
'// FontStyle: face types and common styles
'//--------------------------------------------------------------------------

' enum FontStyle
%FontStyleRegular    = 0
%FontStyleBold       = 1
%FontStyleItalic     = 2
%FontStyleBoldItalic = 3
%FontStyleUnderline  = 4
%FontStyleStrikeout  = 8

'//---------------------------------------------------------------------------
'// Smoothing Mode
'//---------------------------------------------------------------------------

' enum SmoothingMode
%SmoothingModeInvalid     = %QualityModeInvalid
%SmoothingModeDefault     = %QualityModeDefault
%SmoothingModeHighSpeed   = %QualityModeLow
%SmoothingModeHighQuality = %QualityModeHigh
%SmoothingModeNone        = 3
%SmoothingModeAntiAlias   = 4

'//---------------------------------------------------------------------------
'// Pixel Format Mode
'//---------------------------------------------------------------------------

' enum PixelOffsetMode
%PixelOffsetModeInvalid     = %QualityModeInvalid
%PixelOffsetModeDefault     = %QualityModeDefault
%PixelOffsetModeHighSpeed   = %QualityModeLow
%PixelOffsetModeHighQuality = %QualityModeHigh
%PixelOffsetModeNone        = 3   ' No pixel offset
%PixelOffsetModeHalf        = 4   ' Offset by -0.5 -0.5 for fast anti-alias perf

'//---------------------------------------------------------------------------
'// Text Rendering Hint
'//---------------------------------------------------------------------------

' enum TextRenderingHint
%TextRenderingHintSystemDefault            = 0 ' Glyph with system default rendering hint
%TextRenderingHintSingleBitPerPixelGridFit = 1 ' Glyph bitmap with hinting
%TextRenderingHintSingleBitPerPixel        = 2 ' Glyph bitmap without hinting
%TextRenderingHintAntiAliasGridFit         = 3 ' Glyph anti-alias bitmap with hinting
%TextRenderingHintAntiAlias                = 4 ' Glyph anti-alias bitmap without hinting
%TextRenderingHintClearTypeGridFit         = 5 ' Glyph CT bitmap with hinting

'//---------------------------------------------------------------------------
'// Metafile Types
'//---------------------------------------------------------------------------

' enum MetafileType
%MetafileTypeInvalid      = 0   ' Invalid metafile
%MetafileTypeWmf          = 1   ' Standard WMF
%MetafileTypeWmfPlaceable = 2   ' Placeable WMF
%MetafileTypeEmf          = 3   ' EMF (not EMF+)
%MetafileTypeEmfPlusOnly  = 4   ' EMF+ without dual down-level records
%MetafileTypeEmfPlusDual  = 5   ' EMF+ with dual down-level records

'//---------------------------------------------------------------------------
'// Specifies the type of EMF to record
'//---------------------------------------------------------------------------

' enum EmfType
%EmfTypeEmfOnly     = %MetafileTypeEmf           ' no EMF+  only EMF
%EmfTypeEmfPlusOnly = %MetafileTypeEmfPlusOnly   ' no EMF  only EMF+
%EmfTypeEmfPlusDual = %MetafileTypeEmfPlusDual   ' both EMF+ and EMF

'//---------------------------------------------------------------------------
'// EMF+ Persistent object types
'//---------------------------------------------------------------------------

' enum ObjectType
%ObjectTypeInvalid          = 0
%ObjectTypeBrush            = 1
%ObjectTypePen              = 2
%ObjectTypePath             = 3
%ObjectTypeRegion           = 4
%ObjectTypeImage            = 5
%ObjectTypeFont             = 6
%ObjectTypeStringFormat     = 7
%ObjectTypeImageAttributes  = 8
%ObjectTypeCustomLineCap    = 9
#IF (%GDIPVER >= &H0110)
%ObjectTypeGraphics         = 10
%ObjectTypeMax              = %ObjectTypeGraphics
#ELSE
%ObjectTypeMax              = %ObjectTypeCustomLineCap
#ENDIF   ' //(%GDIPVER >= &H0110)
%ObjectTypeMin              = %ObjectTypeBrush

'inline BOOL
'ObjectTypeIsValid(
'    ObjectType      type
'    )
'{
'    return ((type >= ObjectTypeMin) && (type <= ObjectTypeMax));
'}

FUNCTION ObjectTypeIsValid (BYVAL ntype AS LONG) AS LONG
   FUNCTION = (ntype >= %ObjectTypeMin) AND (ntype <= %ObjectTypeMax)
END FUNCTION

'//---------------------------------------------------------------------------
'// EMF+ Records
'//---------------------------------------------------------------------------

'// We have to change the WMF record numbers so that they don't conflict with
'// the EMF and EMF+ record numbers.

%GDIP_EMFPLUS_RECORD_BASE     = &H00004000???
%GDIP_WMF_RECORD_BASE         = &H00010000???

'#define GDIP_WMF_RECORD_TO_EMFPLUS(n)   ((EmfPlusRecordType)((n) | GDIP_WMF_RECORD_BASE))
'#define GDIP_EMFPLUS_RECORD_TO_WMF(n)   ((n) & (~GDIP_WMF_RECORD_BASE))
'#define GDIP_IS_WMF_RECORDTYPE(n)       (((n) & GDIP_WMF_RECORD_BASE) != 0)

MACRO GDIP_WMF_RECORD_TO_EMFPLUS(n) = (n OR %GDIP_WMF_RECORD_BASE)
MACRO GDIP_EMFPLUS_RECORD_TO_WMF(n) = (n AND (NOT %GDIP_WMF_RECORD_BASE))
MACRO GDIP_IS_WMF_RECORDTYPE(n) = ((n AND %GDIP_WMF_RECORD_BASE) <> 0)

'enum EmfPlusRecordType
'{
'   // Since we have to enumerate GDI records right along with GDI+ records,
'   // We list all the GDI records here so that they can be part of the
'   // same enumeration type which is used in the enumeration callback.

'    WmfRecordTypeSetBkColor              = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETBKCOLOR),
'    WmfRecordTypeSetBkMode               = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETBKMODE),
'    WmfRecordTypeSetMapMode              = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETMAPMODE),
'    WmfRecordTypeSetROP2                 = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETROP2),
'    WmfRecordTypeSetRelAbs               = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETRELABS),
'    WmfRecordTypeSetPolyFillMode         = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETPOLYFILLMODE),
'    WmfRecordTypeSetStretchBltMode       = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETSTRETCHBLTMODE),
'    WmfRecordTypeSetTextCharExtra        = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETTEXTCHAREXTRA),
'    WmfRecordTypeSetTextColor            = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETTEXTCOLOR),
'    WmfRecordTypeSetTextJustification    = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETTEXTJUSTIFICATION),
'    WmfRecordTypeSetWindowOrg            = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETWINDOWORG),
'    WmfRecordTypeSetWindowExt            = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETWINDOWEXT),
'    WmfRecordTypeSetViewportOrg          = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETVIEWPORTORG),
'    WmfRecordTypeSetViewportExt          = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETVIEWPORTEXT),
'    WmfRecordTypeOffsetWindowOrg         = GDIP_WMF_RECORD_TO_EMFPLUS(META_OFFSETWINDOWORG),
'    WmfRecordTypeScaleWindowExt          = GDIP_WMF_RECORD_TO_EMFPLUS(META_SCALEWINDOWEXT),
'    WmfRecordTypeOffsetViewportOrg       = GDIP_WMF_RECORD_TO_EMFPLUS(META_OFFSETVIEWPORTORG),
'    WmfRecordTypeScaleViewportExt        = GDIP_WMF_RECORD_TO_EMFPLUS(META_SCALEVIEWPORTEXT),
'    WmfRecordTypeLineTo                  = GDIP_WMF_RECORD_TO_EMFPLUS(META_LINETO),
'    WmfRecordTypeMoveTo                  = GDIP_WMF_RECORD_TO_EMFPLUS(META_MOVETO),
'    WmfRecordTypeExcludeClipRect         = GDIP_WMF_RECORD_TO_EMFPLUS(META_EXCLUDECLIPRECT),
'    WmfRecordTypeIntersectClipRect       = GDIP_WMF_RECORD_TO_EMFPLUS(META_INTERSECTCLIPRECT),
'    WmfRecordTypeArc                     = GDIP_WMF_RECORD_TO_EMFPLUS(META_ARC),
'    WmfRecordTypeEllipse                 = GDIP_WMF_RECORD_TO_EMFPLUS(META_ELLIPSE),
'    WmfRecordTypeFloodFill               = GDIP_WMF_RECORD_TO_EMFPLUS(META_FLOODFILL),
'    WmfRecordTypePie                     = GDIP_WMF_RECORD_TO_EMFPLUS(META_PIE),
'    WmfRecordTypeRectangle               = GDIP_WMF_RECORD_TO_EMFPLUS(META_RECTANGLE),
'    WmfRecordTypeRoundRect               = GDIP_WMF_RECORD_TO_EMFPLUS(META_ROUNDRECT),
'    WmfRecordTypePatBlt                  = GDIP_WMF_RECORD_TO_EMFPLUS(META_PATBLT),
'    WmfRecordTypeSaveDC                  = GDIP_WMF_RECORD_TO_EMFPLUS(META_SAVEDC),
'    WmfRecordTypeSetPixel                = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETPIXEL),
'    WmfRecordTypeOffsetClipRgn           = GDIP_WMF_RECORD_TO_EMFPLUS(META_OFFSETCLIPRGN),
'    WmfRecordTypeTextOut                 = GDIP_WMF_RECORD_TO_EMFPLUS(META_TEXTOUT),
'    WmfRecordTypeBitBlt                  = GDIP_WMF_RECORD_TO_EMFPLUS(META_BITBLT),
'    WmfRecordTypeStretchBlt              = GDIP_WMF_RECORD_TO_EMFPLUS(META_STRETCHBLT),
'    WmfRecordTypePolygon                 = GDIP_WMF_RECORD_TO_EMFPLUS(META_POLYGON),
'    WmfRecordTypePolyline                = GDIP_WMF_RECORD_TO_EMFPLUS(META_POLYLINE),
'    WmfRecordTypeEscape                  = GDIP_WMF_RECORD_TO_EMFPLUS(META_ESCAPE),
'    WmfRecordTypeRestoreDC               = GDIP_WMF_RECORD_TO_EMFPLUS(META_RESTOREDC),
'    WmfRecordTypeFillRegion              = GDIP_WMF_RECORD_TO_EMFPLUS(META_FILLREGION),
'    WmfRecordTypeFrameRegion             = GDIP_WMF_RECORD_TO_EMFPLUS(META_FRAMEREGION),
'    WmfRecordTypeInvertRegion            = GDIP_WMF_RECORD_TO_EMFPLUS(META_INVERTREGION),
'    WmfRecordTypePaintRegion             = GDIP_WMF_RECORD_TO_EMFPLUS(META_PAINTREGION),
'    WmfRecordTypeSelectClipRegion        = GDIP_WMF_RECORD_TO_EMFPLUS(META_SELECTCLIPREGION),
'    WmfRecordTypeSelectObject            = GDIP_WMF_RECORD_TO_EMFPLUS(META_SELECTOBJECT),
'    WmfRecordTypeSetTextAlign            = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETTEXTALIGN),
'    WmfRecordTypeDrawText                = GDIP_WMF_RECORD_TO_EMFPLUS(0x062F),  // META_DRAWTEXT
'    WmfRecordTypeChord                   = GDIP_WMF_RECORD_TO_EMFPLUS(META_CHORD),
'    WmfRecordTypeSetMapperFlags          = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETMAPPERFLAGS),
'    WmfRecordTypeExtTextOut              = GDIP_WMF_RECORD_TO_EMFPLUS(META_EXTTEXTOUT),
'    WmfRecordTypeSetDIBToDev             = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETDIBTODEV),
'    WmfRecordTypeSelectPalette           = GDIP_WMF_RECORD_TO_EMFPLUS(META_SELECTPALETTE),
'    WmfRecordTypeRealizePalette          = GDIP_WMF_RECORD_TO_EMFPLUS(META_REALIZEPALETTE),
'    WmfRecordTypeAnimatePalette          = GDIP_WMF_RECORD_TO_EMFPLUS(META_ANIMATEPALETTE),
'    WmfRecordTypeSetPalEntries           = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETPALENTRIES),
'    WmfRecordTypePolyPolygon             = GDIP_WMF_RECORD_TO_EMFPLUS(META_POLYPOLYGON),
'    WmfRecordTypeResizePalette           = GDIP_WMF_RECORD_TO_EMFPLUS(META_RESIZEPALETTE),
'    WmfRecordTypeDIBBitBlt               = GDIP_WMF_RECORD_TO_EMFPLUS(META_DIBBITBLT),
'    WmfRecordTypeDIBStretchBlt           = GDIP_WMF_RECORD_TO_EMFPLUS(META_DIBSTRETCHBLT),
'    WmfRecordTypeDIBCreatePatternBrush   = GDIP_WMF_RECORD_TO_EMFPLUS(META_DIBCREATEPATTERNBRUSH),
'    WmfRecordTypeStretchDIB              = GDIP_WMF_RECORD_TO_EMFPLUS(META_STRETCHDIB),
'    WmfRecordTypeExtFloodFill            = GDIP_WMF_RECORD_TO_EMFPLUS(META_EXTFLOODFILL),
'    WmfRecordTypeSetLayout               = GDIP_WMF_RECORD_TO_EMFPLUS(0x0149),  // META_SETLAYOUT
'    WmfRecordTypeResetDC                 = GDIP_WMF_RECORD_TO_EMFPLUS(0x014C),  // META_RESETDC
'    WmfRecordTypeStartDoc                = GDIP_WMF_RECORD_TO_EMFPLUS(0x014D),  // META_STARTDOC
'    WmfRecordTypeStartPage               = GDIP_WMF_RECORD_TO_EMFPLUS(0x004F),  // META_STARTPAGE
'    WmfRecordTypeEndPage                 = GDIP_WMF_RECORD_TO_EMFPLUS(0x0050),  // META_ENDPAGE
'    WmfRecordTypeAbortDoc                = GDIP_WMF_RECORD_TO_EMFPLUS(0x0052),  // META_ABORTDOC
'    WmfRecordTypeEndDoc                  = GDIP_WMF_RECORD_TO_EMFPLUS(0x005E),  // META_ENDDOC
'    WmfRecordTypeDeleteObject            = GDIP_WMF_RECORD_TO_EMFPLUS(META_DELETEOBJECT),
'    WmfRecordTypeCreatePalette           = GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEPALETTE),
'    WmfRecordTypeCreateBrush             = GDIP_WMF_RECORD_TO_EMFPLUS(0x00F8),  // META_CREATEBRUSH
'    WmfRecordTypeCreatePatternBrush      = GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEPATTERNBRUSH),
'    WmfRecordTypeCreatePenIndirect       = GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEPENINDIRECT),
'    WmfRecordTypeCreateFontIndirect      = GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEFONTINDIRECT),
'    WmfRecordTypeCreateBrushIndirect     = GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEBRUSHINDIRECT),
'    WmfRecordTypeCreateBitmapIndirect    = GDIP_WMF_RECORD_TO_EMFPLUS(0x02FD),  // META_CREATEBITMAPINDIRECT
'    WmfRecordTypeCreateBitmap            = GDIP_WMF_RECORD_TO_EMFPLUS(0x06FE),  // META_CREATEBITMAP
'    WmfRecordTypeCreateRegion            = GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEREGION),

'    EmfRecordTypeHeader                  = EMR_HEADER,
'    EmfRecordTypePolyBezier              = EMR_POLYBEZIER,
'    EmfRecordTypePolygon                 = EMR_POLYGON,
'    EmfRecordTypePolyline                = EMR_POLYLINE,
'    EmfRecordTypePolyBezierTo            = EMR_POLYBEZIERTO,
'    EmfRecordTypePolyLineTo              = EMR_POLYLINETO,
'    EmfRecordTypePolyPolyline            = EMR_POLYPOLYLINE,
'    EmfRecordTypePolyPolygon             = EMR_POLYPOLYGON,
'    EmfRecordTypeSetWindowExtEx          = EMR_SETWINDOWEXTEX,
'    EmfRecordTypeSetWindowOrgEx          = EMR_SETWINDOWORGEX,
'    EmfRecordTypeSetViewportExtEx        = EMR_SETVIEWPORTEXTEX,
'    EmfRecordTypeSetViewportOrgEx        = EMR_SETVIEWPORTORGEX,
'    EmfRecordTypeSetBrushOrgEx           = EMR_SETBRUSHORGEX,
'    EmfRecordTypeEOF                     = EMR_EOF,
'    EmfRecordTypeSetPixelV               = EMR_SETPIXELV,
'    EmfRecordTypeSetMapperFlags          = EMR_SETMAPPERFLAGS,
'    EmfRecordTypeSetMapMode              = EMR_SETMAPMODE,
'    EmfRecordTypeSetBkMode               = EMR_SETBKMODE,
'    EmfRecordTypeSetPolyFillMode         = EMR_SETPOLYFILLMODE,
'    EmfRecordTypeSetROP2                 = EMR_SETROP2,
'    EmfRecordTypeSetStretchBltMode       = EMR_SETSTRETCHBLTMODE,
'    EmfRecordTypeSetTextAlign            = EMR_SETTEXTALIGN,
'    EmfRecordTypeSetColorAdjustment      = EMR_SETCOLORADJUSTMENT,
'    EmfRecordTypeSetTextColor            = EMR_SETTEXTCOLOR,
'    EmfRecordTypeSetBkColor              = EMR_SETBKCOLOR,
'    EmfRecordTypeOffsetClipRgn           = EMR_OFFSETCLIPRGN,
'    EmfRecordTypeMoveToEx                = EMR_MOVETOEX,
'    EmfRecordTypeSetMetaRgn              = EMR_SETMETARGN,
'    EmfRecordTypeExcludeClipRect         = EMR_EXCLUDECLIPRECT,
'    EmfRecordTypeIntersectClipRect       = EMR_INTERSECTCLIPRECT,
'    EmfRecordTypeScaleViewportExtEx      = EMR_SCALEVIEWPORTEXTEX,
'    EmfRecordTypeScaleWindowExtEx        = EMR_SCALEWINDOWEXTEX,
'    EmfRecordTypeSaveDC                  = EMR_SAVEDC,
'    EmfRecordTypeRestoreDC               = EMR_RESTOREDC,
'    EmfRecordTypeSetWorldTransform       = EMR_SETWORLDTRANSFORM,
'    EmfRecordTypeModifyWorldTransform    = EMR_MODIFYWORLDTRANSFORM,
'    EmfRecordTypeSelectObject            = EMR_SELECTOBJECT,
'    EmfRecordTypeCreatePen               = EMR_CREATEPEN,
'    EmfRecordTypeCreateBrushIndirect     = EMR_CREATEBRUSHINDIRECT,
'    EmfRecordTypeDeleteObject            = EMR_DELETEOBJECT,
'    EmfRecordTypeAngleArc                = EMR_ANGLEARC,
'    EmfRecordTypeEllipse                 = EMR_ELLIPSE,
'    EmfRecordTypeRectangle               = EMR_RECTANGLE,
'    EmfRecordTypeRoundRect               = EMR_ROUNDRECT,
'    EmfRecordTypeArc                     = EMR_ARC,
'    EmfRecordTypeChord                   = EMR_CHORD,
'    EmfRecordTypePie                     = EMR_PIE,
'    EmfRecordTypeSelectPalette           = EMR_SELECTPALETTE,
'    EmfRecordTypeCreatePalette           = EMR_CREATEPALETTE,
'    EmfRecordTypeSetPaletteEntries       = EMR_SETPALETTEENTRIES,
'    EmfRecordTypeResizePalette           = EMR_RESIZEPALETTE,
'    EmfRecordTypeRealizePalette          = EMR_REALIZEPALETTE,
'    EmfRecordTypeExtFloodFill            = EMR_EXTFLOODFILL,
'    EmfRecordTypeLineTo                  = EMR_LINETO,
'    EmfRecordTypeArcTo                   = EMR_ARCTO,
'    EmfRecordTypePolyDraw                = EMR_POLYDRAW,
'    EmfRecordTypeSetArcDirection         = EMR_SETARCDIRECTION,
'    EmfRecordTypeSetMiterLimit           = EMR_SETMITERLIMIT,
'    EmfRecordTypeBeginPath               = EMR_BEGINPATH,
'    EmfRecordTypeEndPath                 = EMR_ENDPATH,
'    EmfRecordTypeCloseFigure             = EMR_CLOSEFIGURE,
'    EmfRecordTypeFillPath                = EMR_FILLPATH,
'    EmfRecordTypeStrokeAndFillPath       = EMR_STROKEANDFILLPATH,
'    EmfRecordTypeStrokePath              = EMR_STROKEPATH,
'    EmfRecordTypeFlattenPath             = EMR_FLATTENPATH,
'    EmfRecordTypeWidenPath               = EMR_WIDENPATH,
'    EmfRecordTypeSelectClipPath          = EMR_SELECTCLIPPATH,
'    EmfRecordTypeAbortPath               = EMR_ABORTPATH,
'    EmfRecordTypeReserved_069            = 69,  // Not Used
'    EmfRecordTypeGdiComment              = EMR_GDICOMMENT,
'    EmfRecordTypeFillRgn                 = EMR_FILLRGN,
'    EmfRecordTypeFrameRgn                = EMR_FRAMERGN,
'    EmfRecordTypeInvertRgn               = EMR_INVERTRGN,
'    EmfRecordTypePaintRgn                = EMR_PAINTRGN,
'    EmfRecordTypeExtSelectClipRgn        = EMR_EXTSELECTCLIPRGN,
'    EmfRecordTypeBitBlt                  = EMR_BITBLT,
'    EmfRecordTypeStretchBlt              = EMR_STRETCHBLT,
'    EmfRecordTypeMaskBlt                 = EMR_MASKBLT,
'    EmfRecordTypePlgBlt                  = EMR_PLGBLT,
'    EmfRecordTypeSetDIBitsToDevice       = EMR_SETDIBITSTODEVICE,
'    EmfRecordTypeStretchDIBits           = EMR_STRETCHDIBITS,
'    EmfRecordTypeExtCreateFontIndirect   = EMR_EXTCREATEFONTINDIRECTW,
'    EmfRecordTypeExtTextOutA             = EMR_EXTTEXTOUTA,
'    EmfRecordTypeExtTextOutW             = EMR_EXTTEXTOUTW,
'    EmfRecordTypePolyBezier16            = EMR_POLYBEZIER16,
'    EmfRecordTypePolygon16               = EMR_POLYGON16,
'    EmfRecordTypePolyline16              = EMR_POLYLINE16,
'    EmfRecordTypePolyBezierTo16          = EMR_POLYBEZIERTO16,
'    EmfRecordTypePolylineTo16            = EMR_POLYLINETO16,
'    EmfRecordTypePolyPolyline16          = EMR_POLYPOLYLINE16,
'    EmfRecordTypePolyPolygon16           = EMR_POLYPOLYGON16,
'    EmfRecordTypePolyDraw16              = EMR_POLYDRAW16,
'    EmfRecordTypeCreateMonoBrush         = EMR_CREATEMONOBRUSH,
'    EmfRecordTypeCreateDIBPatternBrushPt = EMR_CREATEDIBPATTERNBRUSHPT,
'    EmfRecordTypeExtCreatePen            = EMR_EXTCREATEPEN,
'    EmfRecordTypePolyTextOutA            = EMR_POLYTEXTOUTA,
'    EmfRecordTypePolyTextOutW            = EMR_POLYTEXTOUTW,
'    EmfRecordTypeSetICMMode              = 98,  // EMR_SETICMMODE,
'    EmfRecordTypeCreateColorSpace        = 99,  // EMR_CREATECOLORSPACE,
'    EmfRecordTypeSetColorSpace           = 100, // EMR_SETCOLORSPACE,
'    EmfRecordTypeDeleteColorSpace        = 101, // EMR_DELETECOLORSPACE,
'    EmfRecordTypeGLSRecord               = 102, // EMR_GLSRECORD,
'    EmfRecordTypeGLSBoundedRecord        = 103, // EMR_GLSBOUNDEDRECORD,
'    EmfRecordTypePixelFormat             = 104, // EMR_PIXELFORMAT,
'    EmfRecordTypeDrawEscape              = 105, // EMR_RESERVED_105,
'    EmfRecordTypeExtEscape               = 106, // EMR_RESERVED_106,
'    EmfRecordTypeStartDoc                = 107, // EMR_RESERVED_107,
'    EmfRecordTypeSmallTextOut            = 108, // EMR_RESERVED_108,
'    EmfRecordTypeForceUFIMapping         = 109, // EMR_RESERVED_109,
'    EmfRecordTypeNamedEscape             = 110, // EMR_RESERVED_110,
'    EmfRecordTypeColorCorrectPalette     = 111, // EMR_COLORCORRECTPALETTE,
'    EmfRecordTypeSetICMProfileA          = 112, // EMR_SETICMPROFILEA,
'    EmfRecordTypeSetICMProfileW          = 113, // EMR_SETICMPROFILEW,
'    EmfRecordTypeAlphaBlend              = 114, // EMR_ALPHABLEND,
'    EmfRecordTypeSetLayout               = 115, // EMR_SETLAYOUT,
'    EmfRecordTypeTransparentBlt          = 116, // EMR_TRANSPARENTBLT,
'    EmfRecordTypeReserved_117            = 117, // Not Used
'    EmfRecordTypeGradientFill            = 118, // EMR_GRADIENTFILL,
'    EmfRecordTypeSetLinkedUFIs           = 119, // EMR_RESERVED_119,
'    EmfRecordTypeSetTextJustification    = 120, // EMR_RESERVED_120,
'    EmfRecordTypeColorMatchToTargetW     = 121, // EMR_COLORMATCHTOTARGETW,
'    EmfRecordTypeCreateColorSpaceW       = 122, // EMR_CREATECOLORSPACEW,
'    EmfRecordTypeMax                     = 122,
'    EmfRecordTypeMin                     = 1,

'    // That is the END of the GDI EMF records.

'    // Now we start the list of EMF+ records.  We leave quite
'    // a bit of room here for the addition of any new GDI
'    // records that may be added later.

'    EmfPlusRecordTypeInvalid = GDIP_EMFPLUS_RECORD_BASE,
'    EmfPlusRecordTypeHeader,
'    EmfPlusRecordTypeEndOfFile,

'    EmfPlusRecordTypeComment,

'    EmfPlusRecordTypeGetDC,

'    EmfPlusRecordTypeMultiFormatStart,
'    EmfPlusRecordTypeMultiFormatSection,
'    EmfPlusRecordTypeMultiFormatEnd,

'    // For all persistent objects

'    EmfPlusRecordTypeObject,

'    // Drawing Records

'    EmfPlusRecordTypeClear,
'    EmfPlusRecordTypeFillRects,
'    EmfPlusRecordTypeDrawRects,
'    EmfPlusRecordTypeFillPolygon,
'    EmfPlusRecordTypeDrawLines,
'    EmfPlusRecordTypeFillEllipse,
'    EmfPlusRecordTypeDrawEllipse,
'    EmfPlusRecordTypeFillPie,
'    EmfPlusRecordTypeDrawPie,
'    EmfPlusRecordTypeDrawArc,
'    EmfPlusRecordTypeFillRegion,
'    EmfPlusRecordTypeFillPath,
'    EmfPlusRecordTypeDrawPath,
'    EmfPlusRecordTypeFillClosedCurve,
'    EmfPlusRecordTypeDrawClosedCurve,
'    EmfPlusRecordTypeDrawCurve,
'    EmfPlusRecordTypeDrawBeziers,
'    EmfPlusRecordTypeDrawImage,
'    EmfPlusRecordTypeDrawImagePoints,
'    EmfPlusRecordTypeDrawString,

'    // Graphics State Records

'    EmfPlusRecordTypeSetRenderingOrigin,
'    EmfPlusRecordTypeSetAntiAliasMode,
'    EmfPlusRecordTypeSetTextRenderingHint,
'    EmfPlusRecordTypeSetTextContrast,
'    EmfPlusRecordTypeSetInterpolationMode,
'    EmfPlusRecordTypeSetPixelOffsetMode,
'    EmfPlusRecordTypeSetCompositingMode,
'    EmfPlusRecordTypeSetCompositingQuality,
'    EmfPlusRecordTypeSave,
'    EmfPlusRecordTypeRestore,
'    EmfPlusRecordTypeBeginContainer,
'    EmfPlusRecordTypeBeginContainerNoParams,
'    EmfPlusRecordTypeEndContainer,
'    EmfPlusRecordTypeSetWorldTransform,
'    EmfPlusRecordTypeResetWorldTransform,
'    EmfPlusRecordTypeMultiplyWorldTransform,
'    EmfPlusRecordTypeTranslateWorldTransform,
'    EmfPlusRecordTypeScaleWorldTransform,
'    EmfPlusRecordTypeRotateWorldTransform,
'    EmfPlusRecordTypeSetPageTransform,
'    EmfPlusRecordTypeResetClip,
'    EmfPlusRecordTypeSetClipRect,
'    EmfPlusRecordTypeSetClipPath,
'    EmfPlusRecordTypeSetClipRegion,
'    EmfPlusRecordTypeOffsetClip,

'    EmfPlusRecordTypeDrawDriverString,

'    EmfPlusRecordTotal,

'    EmfPlusRecordTypeMax = EmfPlusRecordTotal-1,
'    EmfPlusRecordTypeMin = EmfPlusRecordTypeHeader,
'};

%WmfRecordTypeSetBkColor                  = 66049
%WmfRecordTypeSetBkMode                   = 65794
%WmfRecordTypeSetMapMode                  = 5795
%WmfRecordTypeSetROP2                     = 65796
%WmfRecordTypeSetRelAbs                   = 65797
%WmfRecordTypeSetPolyFillMode             = 65798
%WmfRecordTypeSetStretchBltMode           = 65799
%WmfRecordTypeSetTextCharExtra            = 65800
%WmfRecordTypeSetTextColor                = 66057
%WmfRecordTypeSetTextJustification        = 66058
%WmfRecordTypeSetWindowOrg                = 66059
%WmfRecordTypeSetWindowExt                = 66060
%WmfRecordTypeSetViewportOrg              = 6061
%WmfRecordTypeSetViewportExt              = 66062
%WmfRecordTypeOffsetWindowOrg             = 66063
%WmfRecordTypeScaleWindowExt              = 6576
%WmfRecordTypeOffsetViewportOrg           = 6065
%WmfRecordTypeScaleViewportExt            = 66578
%WmfRecordTypeLineTo                      = 66067
%WmfRecordTypeMoveTo                      = 6068
%WmfRecordTypeExcludeClipRect             = 66581
%WmfRecordTypeIntersectClipRect           = 66582
%WmfRecordTypeArc                         = 67607
%WmfRecordTypeEllipse                     = 66584
%WmfRecordTypeFloodFill                   = 66585
%WmfRecordTypePie                         = 67610
%WmfRecordTypeRectangle                   = 66587
%WmfRecordTypeRoundRect                   = 67100
%WmfRecordTypePatBlt                      = 67101
%WmfRecordTypeSaveDC                      = 5566
%WmfRecordTypeSetPixel                    = 66591
%WmfRecordTypeOffsetClipRgn               = 66080
%WmfRecordTypeTextOut                     = 66849
%WmfRecordTypeBitBlt                      = 67874
%WmfRecordTypeStretchBlt                  = 68387
%WmfRecordTypePolygon                     = 66340
%WmfRecordTypePolyline                    = 66341
%WmfRecordTypeEscape                      = 67110
%WmfRecordTypeRestoreDC                   = 65831
%WmfRecordTypeFillRegion                  = 66088
%WmfRecordTypeFrameRegion                 = 66601
%WmfRecordTypeInvertRegion                = 65834
%WmfRecordTypePaintRegion                 = 65835
%WmfRecordTypeSelectClipRegion            = 65836
%WmfRecordTypeSelectObject                = 65837
%WmfRecordTypeSetTextAlign                = 65838
%WmfRecordTypeDrawText                    = 67119
%WmfRecordTypeChord                       = 67632
%WmfRecordTypeSetMapperFlags              = 6097
%WmfRecordTypeExtTextOut                  = 68146
%WmfRecordTypeSetDIBToDev                 = 68915
%WmfRecordTypeSelectPalette               = 66100
%WmfRecordTypeRealizePalette              = 65589
%WmfRecordTypeAnimatePalette              = 66614
%WmfRecordTypeSetPalEntries               = 65591
%WmfRecordTypePolyPolygon                 = 66872
%WmfRecordTypeResizePalette               = 65849
%WmfRecordTypeDIBBitBlt                   = 67904
%WmfRecordTypeDIBStretchBlt               = 68417
%WmfRecordTypeDIBCreatePatternBrush       = 65858
%WmfRecordTypeStretchDIB                  = 69443
%WmfRecordTypeExtFloodFill                = 66888
%WmfRecordTypeSetLayout                   = 65865
%WmfRecordTypeResetDC                     = 65868
%WmfRecordTypeStartDoc                    = 65869
%WmfRecordTypeStartPage                   = 65615
%WmfRecordTypeEndPage                     = 65616
%WmfRecordTypeAbortDoc                    = 65618
%WmfRecordTypeEndDoc                      = 65630
%WmfRecordTypeDeleteObject                = 66032
%WmfRecordTypeCreatePalette               = 65783
%WmfRecordTypeCreateBrush                 = 65784
%WmfRecordTypeCreatePatternBrush          = 66041
%WmfRecordTypeCreatePenIndirect           = 66298
%WmfRecordTypeCreateFontIndirect          = 66299
%WmfRecordTypeCreateBrushIndirect         = 66300
%WmfRecordTypeCreateBitmapIndirect        = 66301
%WmfRecordTypeCreateRegion                = 67327

%EmfRecordTypeHeader                      = 1
%EmfRecordTypePolyBezier                  = 2
%EmfRecordTypePolygon                     = 3
%EmfRecordTypePolyline                    = 4
%EmfRecordTypePolyBezierTo                = 5
%EmfRecordTypePolyLineTo                  = 6
%EmfRecordTypePolyPolyline                = 7
%EmfRecordTypePolyPolygon                 = 8
%EmfRecordTypeSetWindowExtEx              = 9
%EmfRecordTypeSetWindowOrgEx              = 10
%EmfRecordTypeSetViewportExtEx            = 11
%EmfRecordTypeSetViewportOrgEx            = 12
%EmfRecordTypeSetBrushOrgEx               = 13
%EmfRecordTypeEOF                         = 14
%EmfRecordTypeSetPixelV                   = 15
%EmfRecordTypeSetMapperFlags              = 16
%EmfRecordTypeSetMapMode                  = 17
%EmfRecordTypeSetBkMode                   = 18
%EmfRecordTypeSetPolyFillMode             = 19
%EmfRecordTypeSetROP2                     = 20
%EmfRecordTypeSetStretchBltMode           = 21
%EmfRecordTypeSetTextAlign                = 22
%EmfRecordTypeSetColorAdjustment          = 23
%EmfRecordTypeSetTextColor                = 24
%EmfRecordTypeSetBkColor                  = 25
%EmfRecordTypeOffsetClipRgn               = 26
%EmfRecordTypeMoveToEx                    = 27
%EmfRecordTypeSetMetaRgn                  = 28
%EmfRecordTypeExcludeClipRect             = 29
%EmfRecordTypeIntersectClipRect           = 30
%EmfRecordTypeScaleViewportExtEx          = 31
%EmfRecordTypeScaleWindowExtEx            = 32
%EmfRecordTypeSaveDC                      = 33
%EmfRecordTypeRestoreDC                   = 34
%EmfRecordTypeSetWorldTransform           = 35
%EmfRecordTypeModifyWorldTransform        = 36
%EmfRecordTypeSelectObject                = 37
%EmfRecordTypeCreatePen                   = 38
%EmfRecordTypeCreateBrushIndirect         = 39
%EmfRecordTypeDeleteObject                = 40
%EmfRecordTypeAngleArc                    = 41
%EmfRecordTypeEllipse                     = 42
%EmfRecordTypeRectangle                   = 43
%EmfRecordTypeRoundRect                   = 44
%EmfRecordTypeArc                         = 45
%EmfRecordTypeChord                       = 46
%EmfRecordTypePie                         = 47
%EmfRecordTypeSelectPalette               = 48
%EmfRecordTypeCreatePalette               = 49
%EmfRecordTypeSetPaletteEntries           = 50
%EmfRecordTypeResizePalette               = 51
%EmfRecordTypeRealizePalette              = 52
%EmfRecordTypeExtFloodFill                = 53
%EmfRecordTypeLineTo                      = 54
%EmfRecordTypeArcTo                       = 55
%EmfRecordTypePolyDraw                    = 56
%EmfRecordTypeSetArcDirection             = 57
%EmfRecordTypeSetMiterLimit               = 58
%EmfRecordTypeBeginPath                   = 59
%EmfRecordTypeEndPath                     = 60
%EmfRecordTypeCloseFigure                 = 61
%EmfRecordTypeFillPath                    = 62
%EmfRecordTypeStrokeAndFillPath           = 63
%EmfRecordTypeStrokePath                  = 64
%EmfRecordTypeFlattenPath                 = 65
%EmfRecordTypeWidenPath                   = 66
%EmfRecordTypeSelectClipPath              = 67
%EmfRecordTypeAbortPath                   = 68
%EmfRecordTypeReserved_069                = 69
%EmfRecordTypeGdiComment                  = 70
%EmfRecordTypeFillRgn                     = 71
%EmfRecordTypeFrameRgn                    = 72
%EmfRecordTypeInvertRgn                   = 73
%EmfRecordTypePaintRgn                    = 74
%EmfRecordTypeExtSelectClipRgn            = 75
%EmfRecordTypeBitBlt                      = 76
%EmfRecordTypeStretchBlt                  = 77
%EmfRecordTypeMaskBlt                     = 78
%EmfRecordTypePlgBlt                      = 79
%EmfRecordTypeSetDIBitsToDevice           = 80
%EmfRecordTypeStretchDIBits               = 81
%EmfRecordTypeExtCreateFontIndirect       = 82
%EmfRecordTypeExtTextOutA                 = 83
%EmfRecordTypeExtTextOutW                 = 84
%EmfRecordTypePolyBezier16                = 85
%EmfRecordTypePolygon16                   = 86
%EmfRecordTypePolyline16                  = 87
%EmfRecordTypePolyBezierTo16              = 88
%EmfRecordTypePolylineTo16                = 89
%EmfRecordTypePolyPolyline16              = 90
%EmfRecordTypePolyPolygon16               = 91
%EmfRecordTypePolyDraw16                  = 92
%EmfRecordTypeCreateMonoBrush             = 93
%EmfRecordTypeCreateDIBPatternBrushPt     = 94
%EmfRecordTypeExtCreatePen                = 95
%EmfRecordTypePolyTextOutA                = 96
%EmfRecordTypePolyTextOutW                = 97
%EmfRecordTypeSetICMMode                  = 98
%EmfRecordTypeCreateColorSpace            = 99
%EmfRecordTypeSetColorSpace               = 100
%EmfRecordTypeDeleteColorSpace            = 101
%EmfRecordTypeGLSRecord                   = 102
%EmfRecordTypeGLSBoundedRecord            = 103
%EmfRecordTypePixelFormat                 = 104
%EmfRecordTypeDrawEscape                  = 105
%EmfRecordTypeExtEscape                   = 106
%EmfRecordTypeStartDoc                    = 107
%EmfRecordTypeSmallTextOut                = 108
%EmfRecordTypeForceUFIMapping             = 109
%EmfRecordTypeNamedEscape                 = 110
%EmfRecordTypeColorCorrectPalette         = 111
%EmfRecordTypeSetICMProfileA              = 112
%EmfRecordTypeSetICMProfileW              = 113
%EmfRecordTypeAlphaBlend                  = 114
%EmfRecordTypeSetLayout                   = 115
%EmfRecordTypeTransparentBlt              = 116
%EmfRecordTypeReserved_117                = 117
%EmfRecordTypeGradientFill                = 118
%EmfRecordTypeSetLinkedUFIs               = 119
%EmfRecordTypeSetTextJustification        = 120
%EmfRecordTypeColorMatchToTargetW         = 121
%EmfRecordTypeCreateColorSpaceW           = 122
%EmfRecordTypeMax                         = 122
%EmfRecordTypeMin                         = 1

%EmfPlusRecordTypeInvalid                 = 16384
%EmfPlusRecordTypeHeader                  = 16385
%EmfPlusRecordTypeEndOfFile               = 16386
%EmfPlusRecordTypeComment                 = 16387
%EmfPlusRecordTypeGetDC                   = 16388
%EmfPlusRecordTypeMultiFormatStart        = 16389
%EmfPlusRecordTypeMultiFormatSection      = 16390
%EmfPlusRecordTypeMultiFormatEnd          = 16391
%EmfPlusRecordTypeObject                  = 16392
%EmfPlusRecordTypeClear                   = 16393
%EmfPlusRecordTypeFillRects               = 16394
%EmfPlusRecordTypeDrawRects               = 16395
%EmfPlusRecordTypeFillPolygon             = 16396
%EmfPlusRecordTypeDrawLines               = 16397
%EmfPlusRecordTypeFillEllipse             = 16398
%EmfPlusRecordTypeDrawEllipse             = 16399
%EmfPlusRecordTypeFillPie                 = 16400
%EmfPlusRecordTypeDrawPie                 = 16401
%EmfPlusRecordTypeDrawArc                 = 16402
%EmfPlusRecordTypeFillRegion              = 16403
%EmfPlusRecordTypeFillPath                = 16404
%EmfPlusRecordTypeDrawPath                = 16405
%EmfPlusRecordTypeFillClosedCurve         = 16406
%EmfPlusRecordTypeDrawClosedCurve         = 16407
%EmfPlusRecordTypeDrawCurve               = 16408
%EmfPlusRecordTypeDrawBeziers             = 16409
%EmfPlusRecordTypeDrawImage               = 16410
%EmfPlusRecordTypeDrawImagePoints         = 16411
%EmfPlusRecordTypeDrawString              = 16412
%EmfPlusRecordTypeSetRenderingOrigin      = 16413
%EmfPlusRecordTypeSetAntiAliasMode        = 16414
%EmfPlusRecordTypeSetTextRenderingHint    = 16415
%EmfPlusRecordTypeSetTextContrast         = 16416
%EmfPlusRecordTypeSetInterpolationMode    = 16417
%EmfPlusRecordTypeSetPixelOffsetMode      = 16418
%EmfPlusRecordTypeSetCompositingMode      = 16419
%EmfPlusRecordTypeSetCompositingQuality   = 16420
%EmfPlusRecordTypeSave                    = 16421
%EmfPlusRecordTypeRestore                 = 16422
%EmfPlusRecordTypeBeginContainer          = 16423
%EmfPlusRecordTypeBeginContainerNoParams  = 16424
%EmfPlusRecordTypeEndContainer            = 16425
%EmfPlusRecordTypeSetWorldTransform       = 16426
%EmfPlusRecordTypeResetWorldTransform     = 16427
%EmfPlusRecordTypeMultiplyWorldTransform  = 16428
%EmfPlusRecordTypeTranslateWorldTransform = 16429
%EmfPlusRecordTypeScaleWorldTransform     = 16430
%EmfPlusRecordTypeRotateWorldTransform    = 16431
%EmfPlusRecordTypeSetPageTransform        = 16432
%EmfPlusRecordTypeResetClip               = 16433
%EmfPlusRecordTypeSetClipRect             = 16434
%EmfPlusRecordTypeSetClipPath             = 16435
%EmfPlusRecordTypeSetClipRegion           = 16436
%EmfPlusRecordTypeOffsetClip              = 16437
%EmfPlusRecordTypeDrawDriverString        = 16438
#IF (%GDIPVER >= &H0110)
%EmfPlusRecordTypeStrokeFillPath          = 16439
%EmfPlusRecordTypeSerializableObject      = 16440
%EmfPlusRecordTypeSetTSGraphics           = 16441
%EmfPlusRecordTypeSetTSClip               = 16442
#ENDIF
'// NOTE: New records *must* be added immediately before this line.

%EmfPlusRecordTotal                       = 16443
%EmfPlusRecordTypeMax                     = %EmfPlusRecordTotal-1
%EmfPlusRecordTypeMin                     = %EmfPlusRecordTypeHeader

'//---------------------------------------------------------------------------
'// StringFormatFlags
'//---------------------------------------------------------------------------

'//---------------------------------------------------------------------------
'// String format flags
'//
'//  DirectionRightToLeft          - For horizontal text, the reading order is
'//                                  right to left. This value is called
'//                                  the base embedding level by the Unicode
'//                                  bidirectional engine.
'//                                  For vertical text, columns are read from
'//                                  right to left.
'//                                  By default, horizontal or vertical text is
'//                                  read from left to right.
'//
'//  DirectionVertical             - Individual lines of text are vertical. In
'//                                  each line, characters progress from top to
'//                                  bottom.
'//                                  By default, lines of text are horizontal,
'//                                  each new line below the previous line.
'//
'//  NoFitBlackBox                 - Allows parts of glyphs to overhang the
'//                                  bounding rectangle.
'//                                  By default glyphs are first aligned
'//                                  inside the margines, then any glyphs which
'//                                  still overhang the bounding box are
'//                                  repositioned to avoid any overhang.
'//                                  For example when an italic
'//                                  lower case letter f in a font such as
'//                                  Garamond is aligned at the far left of a
'//                                  rectangle, the lower part of the f will
'//                                  reach slightly further left than the left
'//                                  edge of the rectangle. Setting this flag
'//                                  will ensure the character aligns visually
'//                                  with the lines above and below, but may
'//                                  cause some pixels outside the formatting
'//                                  rectangle to be clipped or painted.
'//
'//  DisplayFormatControl          - Causes control characters such as the
'//                                  left-to-right mark to be shown in the
'//                                  output with a representative glyph.
'//
'//  NoFontFallback                - Disables fallback to alternate fonts for
'//                                  characters not supported in the requested
'//                                  font. Any missing characters will be
'//                                  be displayed with the fonts missing glyph,
'//                                  usually an open square.
'//
'//  NoWrap                        - Disables wrapping of text between lines
'//                                  when formatting within a rectangle.
'//                                  NoWrap is implied when a point is passed
'//                                  instead of a rectangle, or when the
'//                                  specified rectangle has a zero line length.
'//
'//  NoClip                        - By default text is clipped to the
'//                                  formatting rectangle. Setting NoClip
'//                                  allows overhanging pixels to affect the
'//                                  device outside the formatting rectangle.
'//                                  Pixels at the end of the line may be
'//                                  affected if the glyphs overhang their
'//                                  cells, and either the NoFitBlackBox flag
'//                                  has been set, or the glyph extends to far
'//                                  to be fitted.
'//                                  Pixels above/before the first line or
'//                                  below/after the last line may be affected
'//                                  if the glyphs extend beyond their cell
'//                                  ascent / descent. This can occur rarely
'//                                  with unusual diacritic mark combinations.

'//---------------------------------------------------------------------------

' enum StringFormatFlags
%StringFormatFlagsDirectionRightToLeft        = &H00000001
%StringFormatFlagsDirectionVertical           = &H00000002
%StringFormatFlagsNoFitBlackBox               = &H00000004
%StringFormatFlagsDisplayFormatControl        = &H00000020
%StringFormatFlagsNoFontFallback              = &H00000400
%StringFormatFlagsMeasureTrailingSpaces       = &H00000800
%StringFormatFlagsNoWrap                      = &H00001000
%StringFormatFlagsLineLimit                   = &H00002000

%StringFormatFlagsNoClip                      = &H00004000
%StringFormatFlagsBypassGDI                   = &H80000000

'//---------------------------------------------------------------------------
'// StringTrimming
'//---------------------------------------------------------------------------

' enum StringTrimming {
%StringTrimmingNone              = 0
%StringTrimmingCharacter         = 1
%StringTrimmingWord              = 2
%StringTrimmingEllipsisCharacter = 3
%StringTrimmingEllipsisWord      = 4
%StringTrimmingEllipsisPath      = 5

'//---------------------------------------------------------------------------
'// National language digit substitution
'//---------------------------------------------------------------------------

' enum StringDigitSubstitute
%StringDigitSubstituteUser        = 0   ' As NLS setting
%StringDigitSubstituteNone        = 1
%StringDigitSubstituteNational    = 2
%StringDigitSubstituteTraditional = 3

'//---------------------------------------------------------------------------
'// Hotkey prefix interpretation
'//---------------------------------------------------------------------------

' enum HotkeyPrefix
%HotkeyPrefixNone = 0
%HotkeyPrefixShow = 1
%HotkeyPrefixHide = 2

'//---------------------------------------------------------------------------
'// String alignment flags
'//---------------------------------------------------------------------------

' enum StringAlignment

' // Left edge for left-to-right text,
' // right for right-to-left text,
' // and top for vertical

%StringAlignmentNear   = 0
%StringAlignmentCenter = 1
%StringAlignmentFar    = 2

'//---------------------------------------------------------------------------
'// DriverStringOptions
'//---------------------------------------------------------------------------

' enum DriverStringOptions
%DriverStringOptionsCmapLookup      = 1
%DriverStringOptionsVertical        = 2
%DriverStringOptionsRealizedAdvance = 4
%DriverStringOptionsLimitSubpixel   = 8

'//---------------------------------------------------------------------------
'// Flush Intention flags
'//---------------------------------------------------------------------------

' enum FlushIntention
%FlushIntentionFlush = 0       ' // Flush all batched rendering operations
%FlushIntentionSync  = 1       ' // Flush all batched rendering operations
                               ' // and wait for them to complete

'//---------------------------------------------------------------------------
'// Image encoder parameter related types
'//---------------------------------------------------------------------------

' enum EncoderParameterValueType

%EncoderParameterValueTypeByte          = 1     ' 8-bit unsigned int
%EncoderParameterValueTypeASCII         = 2     ' 8-bit byte containing one 7-bit ASCII
                                                ' code. NULL terminated.
%EncoderParameterValueTypeShort         = 3     ' 16-bit unsigned int
%EncoderParameterValueTypeLong          = 4     ' 32-bit unsigned int
%EncoderParameterValueTypeRational      = 5     ' Two Longs. The first Long is the
                                                ' numerator the second Long expresses the
                                                ' denomintor.
%EncoderParameterValueTypeLongRange     = 6     ' Two longs which specify a range of
                                                ' INT eger values. The first Long specifies
                                                ' the lower end and the second one
                                                ' specifies the higher end. All values
                                                ' are inclusive at both ends
%EncoderParameterValueTypeUndefined     = 7     ' 8-bit byte that can take any value
                                                ' depending on field definition
%EncoderParameterValueTypeRationalRange = 8     ' Two Rationals. The first Rational
                                                ' specifies the lower end and the second
                                                ' specifies the higher end. All values
                                                ' are inclusive at both ends
%EncoderParameterValueTypePointer       = 9     ' Specifies that the parameter is a pointer
                                                ' to a block of custom metadata.

'//---------------------------------------------------------------------------
'// Image encoder value types
'//---------------------------------------------------------------------------

' enum EncoderValue
%EncoderValueColorTypeCMYK             = 0
%EncoderValueColorTypeYCCK             = 1
%EncoderValueCompressionLZW            = 2
%EncoderValueCompressionCCITT3         = 3
%EncoderValueCompressionCCITT4         = 4
%EncoderValueCompressionRle            = 5
%EncoderValueCompressionNone           = 6
%EncoderValueScanMethodInterlaced      = 7
%EncoderValueScanMethodNonInterlaced   = 8
%EncoderValueVersionGif87              = 9
%EncoderValueVersionGif89              = 10
%EncoderValueRenderProgressive         = 11
%EncoderValueRenderNonProgressive      = 12
%EncoderValueTransformRotate90         = 13
%EncoderValueTransformRotate180        = 14
%EncoderValueTransformRotate270        = 15
%EncoderValueTransformFlipHorizontal   = 16
%EncoderValueTransformFlipVertical     = 17
%EncoderValueMultiFrame                = 18
%EncoderValueLastFrame                 = 19
%EncoderValueFlush                     = 20
%EncoderValueFrameDimensionTime        = 21
%EncoderValueFrameDimensionResolution  = 22
%EncoderValueFrameDimensionPage        = 23
#IF (%GDIPVER >= &H0110)
%EncoderValueColorTypeGray             = 24
%EncoderValueColorTypeRGB              = 25
#ENDIF

'//---------------------------------------------------------------------------
'// Conversion of Emf To WMF Bits flags
'//---------------------------------------------------------------------------

'enum EmfToWmfBitsFlags
%EmfToWmfBitsFlagsDefault          = &H00000000???
%EmfToWmfBitsFlagsEmbedEmf         = &H00000001???
%EmfToWmfBitsFlagsIncludePlaceable = &H00000002???
%EmfToWmfBitsFlagsNoXORClip        = &H00000004???

#IF (%GDIPVER >= &H0110)
'//---------------------------------------------------------------------------
'// Conversion of Emf To Emf+ Bits flags
'//---------------------------------------------------------------------------
' enum ConvertToEmfPlusFlags
%ConvertToEmfPlusFlagsDefault       = &H00000000???
%ConvertToEmfPlusFlagsRopUsed       = &H00000001???
%ConvertToEmfPlusFlagsText          = &H00000002???
%ConvertToEmfPlusFlagsInvalidRecord = &H00000004???
#ENDIF

'//---------------------------------------------------------------------------
'// Test Control flags
'//---------------------------------------------------------------------------

' enum GpTestControlEnum
%TestControlForceBilinear  = 0
%TestControlNoICM          = 1
%TestControlGetBuildNumber = 2
