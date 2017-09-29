' ########################################################################################
' Microsoft Windows
' File: MSChart.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MSChart20Lib
' Version: 2.0, Locale ID = 0
' Documentation string: Microsoft Chart Control 6.0 (SP4) (OLEDB)
' Path: C:\WINDOWS\system32\mschrt20.ocx
' Library GUID: {65E121D4-0C60-11D2-A9FC-0000F8754DA1}
' Help file: C:\WINDOWS\HELP\MSCHRT98.chm
' License key: 8E147C69-BD50-11d1-B137-0000F8753F5D
' ########################################################################################

#INCLUDE THIS ONCE
%MSCHART_INC = 1

#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "msdatsrc.inc"

$RTLKEY_MSChart = "8E147C69-BD50-11d1-B137-0000F8753F5D"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

$PROGID_MSChart = "MSChart20Lib.MSChart.2"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_MSChartAxis = GUID$("{E9E07526-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartAxisGrid = GUID$("{E9E0751C-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartAxisScale = GUID$("{E9E07522-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartAxisTitle = GUID$("{E9E07516-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartBackdrop = GUID$("{E9E074E3-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartBrush = GUID$("{E9E074DB-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartCategoryScale = GUID$("{E9E07518-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartCoor = GUID$("{E9E074CA-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartDataGrid = GUID$("{E9E074EB-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartDataPoint = GUID$("{E9E0750F-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartDataPointLabel = GUID$("{E9E0750D-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartDataPoints = GUID$("{E9E07510-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartFill = GUID$("{E9E074DF-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartFootnote = GUID$("{E9E074E7-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartFrame = GUID$("{E9E074E1-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartIntersection = GUID$("{E9E0751E-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartLabel = GUID$("{E9E07509-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartLabels = GUID$("{E9E0750B-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartLCoor = GUID$("{E9E074CC-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartLegend = GUID$("{E9E074E9-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartLight = GUID$("{E9E074F1-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartLightSource = GUID$("{E9E074ED-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartLightSources = GUID$("{E9E074EF-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartLocation = GUID$("{E9E074D7-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartMarker = GUID$("{E9E074D4-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartMSChart = GUID$("{3A2B370C-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartPen = GUID$("{E9E074D2-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartPlot = GUID$("{E9E07528-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartPlotBase = GUID$("{E9E074F5-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartRect = GUID$("{E9E074CE-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartSeries = GUID$("{E9E07512-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartSeriesCollection = GUID$("{E9E07514-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartSeriesMarker = GUID$("{E9E07505-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartSeriesPosition = GUID$("{E9E07503-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartShadow = GUID$("{E9E074DD-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartStatLine = GUID$("{E9E07507-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartTextLayout = GUID$("{E9E07529-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartTick = GUID$("{E9E07520-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartTitle = GUID$("{E9E074E5-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartValueScale = GUID$("{E9E07524-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartView3d = GUID$("{E9E074F3-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartVtColor = GUID$("{E9E074D0-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartVtFont = GUID$("{E9E074D9-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartWall = GUID$("{E9E074FD-BA0A-11D1-B137-0000F8753F5D}")
$CLSID_MSChartWeighting = GUID$("{E9E074FB-BA0A-11D1-B137-0000F8753F5D}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_MSChartIVcAxis = GUID$("{E9E07525-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcAxisGrid = GUID$("{E9E0751B-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcAxisScale = GUID$("{E9E07521-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcAxisTitle = GUID$("{E9E07515-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcBackdrop = GUID$("{E9E074E2-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcBrush = GUID$("{E9E074DA-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcCategoryScale = GUID$("{E9E07517-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcColor = GUID$("{E9E074CF-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcCoor = GUID$("{E9E074C9-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcDataGrid = GUID$("{E9E074EA-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcDataPoint = GUID$("{E9E0750E-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcDataPointLabel = GUID$("{E9E0750C-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcDataPoints = GUID$("{E9E0752A-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcFill = GUID$("{E9E074DE-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcFont = GUID$("{E9E074D8-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcFootnote = GUID$("{E9E074E6-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcFrame = GUID$("{E9E074E0-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcIntersection = GUID$("{E9E0751D-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcLabel = GUID$("{E9E07508-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcLabels = GUID$("{E9E0750A-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcLCoor = GUID$("{E9E074CB-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcLegend = GUID$("{E9E074E8-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcLight = GUID$("{E9E074F0-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcLightSource = GUID$("{E9E074EC-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcLightSources = GUID$("{E9E074EE-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcLocation = GUID$("{E9E074D6-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcMarker = GUID$("{E9E074D3-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcPen = GUID$("{E9E074D1-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcPlot = GUID$("{E9E07527-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcPlotBase = GUID$("{E9E074F4-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcRect = GUID$("{E9E074CD-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcSeries = GUID$("{E9E07511-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcSeriesCollection = GUID$("{E9E07513-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcSeriesMarker = GUID$("{E9E07504-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcSeriesPosition = GUID$("{E9E07502-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcShadow = GUID$("{E9E074DC-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcStatLine = GUID$("{E9E07506-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcTextLayout = GUID$("{E9E074D5-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcTick = GUID$("{E9E0751F-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcTitle = GUID$("{E9E074E4-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcValueScale = GUID$("{E9E07523-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcView3d = GUID$("{E9E074F2-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcWall = GUID$("{E9E074FC-BA0A-11D1-B137-0000F8753F5D}")
$IID_MSChartIVcWeighting = GUID$("{E9E074FA-BA0A-11D1-B137-0000F8753F5D}")
$IID__MSChartDMSChart = GUID$("{3A2B370A-BA0A-11D1-B137-0000F8753F5D}")
$IID__MSChartDMSChartEvents = GUID$("{3A2B370B-BA0A-11D1-B137-0000F8753F5D}")

' ========================================================================================
' ErrorConstants enum
' IID: {ECB6C9A0-309B-11CF-93D5-0020AF99504A}
' The list of error codes
' ========================================================================================

%VtOk                                                   = 0            ' &H0
%VtFail                                                 = 1000         ' &H3E8
%VtErrorDeletingUsedObject                              = 1001         ' &H3E9
%VtErrorDeletingDeletedObject                           = 1002         ' &H3EA
%VtErrorCorruptData                                     = 1003         ' &H3EB
%VtErrorNotImplemented                                  = 1004         ' &H3EC
%VtErrorNoMemory                                        = 1100         ' &H44C
%VtErrorInvalidArgument                                 = 1101         ' &H44D
%VtErrorNotFound                                        = 1102         ' &H44E
%VtErrorTooSmall                                        = 1103         ' &H44F
%VtErrorInvalidRequest                                  = 1104         ' &H450
%VtErrorStreamIo                                        = 1105         ' &H451
%VtErrorUserIo                                          = 1106         ' &H452
%VtErrorCorruptArchive                                  = 1107         ' &H453
%VtErrorArchiveVersion                                  = 1108         ' &H454
%VtErrorArchiveTypeMismatch                             = 1109         ' &H455
%VtErrorArchivePointerMismatch                          = 1110         ' &H456
%VtErrorCannotOpenFile                                  = 1111         ' &H457
%VtErrorUnableToLoadString                              = 1112         ' &H458
%VtErrorBufferTooSmall                                  = 1113         ' &H459
%VtErrorCopyingObject                                   = 1114         ' &H45A
%VtErrorDuplicateObject                                 = 1115         ' &H45B
%VtErrorActionCanceled                                  = 1116         ' &H45C
%VtErrorInvalidIndex                                    = 1117         ' &H45D
%VtErrorInvalidTypeConversion                           = 1118         ' &H45E
%VtErrorInvalidObject                                   = 1119         ' &H45F
%VtErrorCreateWindow                                    = 1120         ' &H460
%VtErrorOSVersion                                       = 1121         ' &H461
%VtErrorLoadPicture                                     = 1122         ' &H462
%VtErrorInvalidSyntax                                   = 1200         ' &H4B0
%VtErrorIdentifierTooBig                                = 1201         ' &H4B1
%VtErrorUnrecongizedFunction                            = 1202         ' &H4B2
%VtErrorUnrecongizedSymbol                              = 1203         ' &H4B3
%VtErrorUnexpectedEOS                                   = 1204         ' &H4B4
%VtErrorDuplicateSymbol                                 = 1205         ' &H4B5
%VtErrorDisplay                                         = 1500         ' &H5DC
%VtErrorInvalidFontName                                 = 1501         ' &H5DD
%VtErrorInvalidFont                                     = 1502         ' &H5DE
%VtErrorNoDisplayResources                              = 1503         ' &H5DF
%VtErrorDefaultFontSubstituted                          = 1504         ' &H5E0
%VtChError                                              = 2000         ' &H7D0
%VtChErrorInvalidHandle                                 = 2001         ' &H7D1
%VtChErrorNoData                                        = 2002         ' &H7D2
%VtChErrorInvalidSeriesNumber                           = 2003         ' &H7D3
%VtChErrorInvalidAxis                                   = 2004         ' &H7D4
%VtChErrorRestrictedVersion                             = 2005         ' &H7D5
%InvalidPropertyValue                                   = 380          ' &H17C
%GetNotSupported                                        = 394          ' &H18A
%SetNotSupported                                        = 383          ' &H17F
%InvalidProcedureCall                                   = 5            ' &H5
%InvalidObjectUse                                       = 425          ' &H1A9
%WrongClipboardFormat                                   = 461          ' &H1CD
%DataObjectLocked                                       = 672          ' &H2A0
%ExpectedAnArgument                                     = 673          ' &H2A1
%RecursiveOleDrag                                       = 674          ' &H2A2
%FormatNotByteArray                                     = 675          ' &H2A3
%DataNotSetForFormat                                    = 676          ' &H2A4

' ========================================================================================
' OLEDropConstants enum
' IID: {D8898461-742F-11CF-8AEA-00AA00C00905}
' Constants for the OLEDropMode property (but not the DragMode or OLEDragMode properties).
' ========================================================================================

%chOLEDropNone                                          = 0            ' &H0
%chOLEDropManual                                        = 1            ' &H1
%chOLEDropAutomatic                                     = 2            ' &H2

' ========================================================================================
' OLEDragConstants enum
' IID: {D8898460-742F-11CF-8AEA-00AA00C00905}
' Constants for the OLEDragMode property (but not the DragMode or OLEDropMode properties).
' ========================================================================================

%chOLEDragManual                                        = 0            ' &H0
%chOLEDragAutomatic                                     = 1            ' &H1

' ========================================================================================
' VtHorizontalAlignment enum
' IID: {E76E7294-BD49-11D1-B137-0000F8753F5D}
' Horizontal Alignment Constants
' ========================================================================================

%VtHorizontalAlignmentLeft                              = 0            ' &H0
%VtHorizontalAlignmentRight                             = 1            ' &H1
%VtHorizontalAlignmentCenter                            = 2            ' &H2
%VtHorizontalAlignmentFill                              = 3            ' &H3
%VtHorizontalAlignmentFlush                             = 4            ' &H4

' ========================================================================================
' VtVerticalAlignment enum
' IID: {E76E7295-BD49-11D1-B137-0000F8753F5D}
' Vertical Alignment Constants
' ========================================================================================

%VtVerticalAlignmentTop                                 = 0            ' &H0
%VtVerticalAlignmentBottom                              = 1            ' &H1
%VtVerticalAlignmentCenter                              = 2            ' &H2

' ========================================================================================
' VtOrientation enum
' IID: {E76E7296-BD49-11D1-B137-0000F8753F5D}
' Orientation Constants
' ========================================================================================

%VtOrientationHorizontal                                = 0            ' &H0
%VtOrientationVertical                                  = 1            ' &H1
%VtOrientationUp                                        = 2            ' &H2
%VtOrientationDown                                      = 3            ' &H3

' ========================================================================================
' VtSortType enum
' IID: {E76E7297-BD49-11D1-B137-0000F8753F5D}
' Sort Type Constants
' ========================================================================================

%VtSortTypeNone                                         = 0            ' &H0
%VtSortTypeAscending                                    = 1            ' &H1
%VtSortTypeDescending                                   = 2            ' &H2

' ========================================================================================
' VtAngleUnits enum
' IID: {E76E7298-BD49-11D1-B137-0000F8753F5D}
' Angle Units Constants
' ========================================================================================

%VtAngleUnitsDegrees                                    = 0            ' &H0
%VtAngleUnitsRadians                                    = 1            ' &H1
%VtAngleUnitsGrads                                      = 2            ' &H2

' ========================================================================================
' VtPrintScaleType enum
' IID: {E76E7299-BD49-11D1-B137-0000F8753F5D}
' Print Scale Type Constants
' ========================================================================================

%VtPrintScaleTypeActual                                 = 0            ' &H0
%VtPrintScaleTypeFitted                                 = 1            ' &H1
%VtPrintScaleTypeStretched                              = 2            ' &H2

' ========================================================================================
' VtPrintOrientation enum
' IID: {E76E729A-BD49-11D1-B137-0000F8753F5D}
' Print Orientation Type Constants
' ========================================================================================

%VtPrintOrientationPortrait                             = 0            ' &H0
%VtPrintOrientationLandscape                            = 1            ' &H1

' ========================================================================================
' VtFontStyle enum
' IID: {B8CC5B97-BD29-11D1-B137-0000F8753F5D}
' The list of VtFont styles
' ========================================================================================

%VtFontStyleBold                                        = 1            ' &H1
%VtFontStyleItalic                                      = 2            ' &H2
%VtFontStyleOutline                                     = 4            ' &H4

' ========================================================================================
' VtFontEffect enum
' IID: {B8CC5B98-BD29-11D1-B137-0000F8753F5D}
' The list of VtFont effects
' ========================================================================================

%VtFontEffectStrikeThrough                              = 256          ' &H100
%VtFontEffectUnderline                                  = 512          ' &H200

' ========================================================================================
' VtBrushStyle enum
' IID: {B8CC5B99-BD29-11D1-B137-0000F8753F5D}
' Brush Styles
' ========================================================================================

%VtBrushStyleNull                                       = 0            ' &H0
%VtBrushStyleSolid                                      = 1            ' &H1
%VtBrushStylePattern                                    = 2            ' &H2
%VtBrushStyleHatched                                    = 3            ' &H3

' ========================================================================================
' VtBrushPatterns enum
' IID: {B8CC5B9A-BD29-11D1-B137-0000F8753F5D}
' Brush Patterns
' ========================================================================================

%VtBrushPattern94Percent                                = 0            ' &H0
%VtBrushPattern88Percent                                = 1            ' &H1
%VtBrushPattern75Percent                                = 2            ' &H2
%VtBrushPattern50Percent                                = 3            ' &H3
%VtBrushPattern25Percent                                = 4            ' &H4
%VtBrushPatternBoldHorizontal                           = 5            ' &H5
%VtBrushPatternBoldVertical                             = 6            ' &H6
%VtBrushPatternBoldDownDiagonal                         = 7            ' &H7
%VtBrushPatternBoldUpDiagonal                           = 8            ' &H8
%VtBrushPatternChecks                                   = 9            ' &H9
%VtBrushPatternWeave                                    = 10           ' &HA
%VtBrushPatternHorizontal                               = 11           ' &HB
%VtBrushPatternVertical                                 = 12           ' &HC
%VtBrushPatternDownDiagonal                             = 13           ' &HD
%VtBrushPatternUpDiagonal                               = 14           ' &HE
%VtBrushPatternGrid                                     = 15           ' &HF
%VtBrushPatternTrellis                                  = 16           ' &H10
%VtBrushPatternInvertedTrellis                          = 17           ' &H11
%VtBrushPatternCount                                    = 18           ' &H12

' ========================================================================================
' VtBrushHatches enum
' IID: {B8CC5B9B-BD29-11D1-B137-0000F8753F5D}
' Brush Hatches
' ========================================================================================

%VtBrushHatchHorizontal                                 = 0            ' &H0
%VtBrushHatchVertical                                   = 1            ' &H1
%VtBrushHatchDownDiagonal                               = 2            ' &H2
%VtBrushHatchUpDiagonal                                 = 3            ' &H3
%VtBrushHatchCross                                      = 4            ' &H4
%VtBrushHatchDiagonalCross                              = 5            ' &H5
%VtBrushHatchCount                                      = 6            ' &H6

' ========================================================================================
' VtShadowStyle enum
' IID: {B8CC5B9C-BD29-11D1-B137-0000F8753F5D}
' Shadow Styles
' ========================================================================================

%VtShadowStyleNull                                      = 0            ' &H0
%VtShadowStyleDrop                                      = 1            ' &H1

' ========================================================================================
' VtPenStyle enum
' IID: {B8CC5B9D-BD29-11D1-B137-0000F8753F5D}
' Pen Styles
' ========================================================================================

%VtPenStyleNull                                         = 0            ' &H0
%VtPenStyleSolid                                        = 1            ' &H1
%VtPenStyleDashed                                       = 2            ' &H2
%VtPenStyleDotted                                       = 3            ' &H3
%VtPenStyleDashDot                                      = 4            ' &H4
%VtPenStyleDashDotDot                                   = 5            ' &H5
%VtPenStyleDitted                                       = 6            ' &H6
%VtPenStyleDashDit                                      = 7            ' &H7
%VtPenStyleDashDitDit                                   = 8            ' &H8
%VtPenStyleNative                                       = 9            ' &H9

' ========================================================================================
' VtPenJoin enum
' IID: {B8CC5B9E-BD29-11D1-B137-0000F8753F5D}
' Pen Join types
' ========================================================================================

%VtPenJoinMiter                                         = 0            ' &H0
%VtPenJoinRound                                         = 1            ' &H1
%VtPenJoinBevel                                         = 2            ' &H2

' ========================================================================================
' VtPenCap enum
' IID: {B8CC5B9F-BD29-11D1-B137-0000F8753F5D}
' Pen Cap types
' ========================================================================================

%VtPenCapButt                                           = 0            ' &H0
%VtPenCapRound                                          = 1            ' &H1
%VtPenCapSquare                                         = 2            ' &H2

' ========================================================================================
' VtFrameStyle enum
' IID: {B8CC5BA0-BD29-11D1-B137-0000F8753F5D}
' Frame Styles
' ========================================================================================

%VtFrameStyleNull                                       = 0            ' &H0
%VtFrameStyleSingleLine                                 = 1            ' &H1
%VtFrameStyleDoubleLine                                 = 2            ' &H2
%VtFrameStyleThickInner                                 = 3            ' &H3
%VtFrameStyleThickOuter                                 = 4            ' &H4

' ========================================================================================
' VtPictureType enum
' IID: {B8CC5BA1-BD29-11D1-B137-0000F8753F5D}
' Picture Types
' ========================================================================================

%VtPictureTypeNull                                      = 0            ' &H0
%VtPictureTypeBitmap                                    = 1            ' &H1
%VtPictureTypeVector                                    = 2            ' &H2
%VtPictureTypeBMP                                       = 3            ' &H3
%VtPictureTypeWMF                                       = 4            ' &H4

' ========================================================================================
' VtPictureOption enum
' IID: {B8CC5BA2-BD29-11D1-B137-0000F8753F5D}
' Picture Options (WMF only)
' ========================================================================================

%VtPictureOptionNoSizeHeader                            = 1            ' &H1
%VtPictureOptionTextAsCurves                            = 2            ' &H2

' ========================================================================================
' VtPictureMapType enum
' IID: {B8CC5BA3-BD29-11D1-B137-0000F8753F5D}
' Picture Map Types
' ========================================================================================

%VtPictureMapTypeActual                                 = 0            ' &H0
%VtPictureMapTypeFitted                                 = 1            ' &H1
%VtPictureMapTypeStretched                              = 2            ' &H2
%VtPictureMapTypeTiled                                  = 3            ' &H3
%VtPictureMapTypeCropFitted                             = 4            ' &H4
%VtPictureMapTypeHorizontalTile                         = 5            ' &H5
%VtPictureMapTypeVerticalTile                           = 6            ' &H6

' ========================================================================================
' VtGradientStyle enum
' IID: {B8CC5BA4-BD29-11D1-B137-0000F8753F5D}
' Gradient Styles
' ========================================================================================

%VtGradientStyleHorizontal                              = 0            ' &H0
%VtGradientStyleVertical                                = 1            ' &H1
%VtGradientStyleRectangle                               = 2            ' &H2
%VtGradientStyleOval                                    = 3            ' &H3

' ========================================================================================
' VtFillStyle enum
' IID: {B8CC5BA5-BD29-11D1-B137-0000F8753F5D}
' Fill Style Constants
' ========================================================================================

%VtFillStyleNull                                        = 0            ' &H0
%VtFillStyleBrush                                       = 1            ' &H1
%VtFillStyleGradient                                    = 2            ' &H2

' ========================================================================================
' VtMarkerStyle enum
' IID: {B8CC5BA6-BD29-11D1-B137-0000F8753F5D}
' Marker Style Constants
' ========================================================================================

%VtMarkerStyleDash                                      = 0            ' &H0
%VtMarkerStylePlus                                      = 1            ' &H1
%VtMarkerStyleX                                         = 2            ' &H2
%VtMarkerStyleStar                                      = 3            ' &H3
%VtMarkerStyleCircle                                    = 4            ' &H4
%VtMarkerStyleSquare                                    = 5            ' &H5
%VtMarkerStyleDiamond                                   = 6            ' &H6
%VtMarkerStyleUpTriangle                                = 7            ' &H7
%VtMarkerStyleDownTriangle                              = 8            ' &H8
%VtMarkerStyleFilledCircle                              = 9            ' &H9
%VtMarkerStyleFilledSquare                              = 10           ' &HA
%VtMarkerStyleFilledDiamond                             = 11           ' &HB
%VtMarkerStyleFilledUpTriangle                          = 12           ' &HC
%VtMarkerStyleFilledDownTriangle                        = 13           ' &HD
%VtMarkerStyle3dBall                                    = 14           ' &HE
%VtMarkerStyleNull                                      = 15           ' &HF
%VtMarkerStyleCount                                     = 16           ' &H10

' ========================================================================================
' VtProjectionType enum
' IID: {B8CC5BA7-BD29-11D1-B137-0000F8753F5D}
' Projection Type Constants
' ========================================================================================

%VtProjectionTypePerspective                            = 0            ' &H0
%VtProjectionTypeOblique                                = 1            ' &H1
%VtProjectionTypeOrthogonal                             = 2            ' &H2
%VtProjectionTypeFrontal                                = 3            ' &H3
%VtProjectionTypeOverhead                               = 4            ' &H4

' ========================================================================================
' VtSmoothingType enum
' IID: {B8CC5BA8-BD29-11D1-B137-0000F8753F5D}
' Smoothing Type Constants
' ========================================================================================

%VtSmoothingTypeNone                                    = 0            ' &H0
%VtSmoothingTypeQuadraticBSpline                        = 1            ' &H1
%VtSmoothingTypeCubicBSpline                            = 2            ' &H2

' ========================================================================================
' VtDcType enum
' IID: {B8CC5BA9-BD29-11D1-B137-0000F8753F5D}
' Device Context Type Constants
' ========================================================================================

%VtDcTypeNull                                           = 0            ' &H0
%VtDcTypeDisplay                                        = 1            ' &H1
%VtDcTypePrinter                                        = 2            ' &H2
%VtDcTypeMetafile                                       = 3            ' &H3

' ========================================================================================
' VtTextOutputType enum
' IID: {B8CC5BAA-BD29-11D1-B137-0000F8753F5D}
' 2D Text output Type Constants
' ========================================================================================

%VtTextOutputTypeHardware                               = 0            ' &H0
%VtTextOutputTypePolygon                                = 1            ' &H1

' ========================================================================================
' VtTextLengthType enum
' IID: {B8CC5BAB-BD29-11D1-B137-0000F8753F5D}
' Text Length Type Constants
' ========================================================================================

%VtTextLengthTypeVirtual                                = 0            ' &H0
%VtTextLengthTypeDevice                                 = 1            ' &H1

' ========================================================================================
' VtChChartType enum
' IID: {C091D289-BD43-11D1-B137-0000F8753F5D}
' The list of Chart types
' ========================================================================================

%VtChChartType3dBar                                     = 0            ' &H0
%VtChChartType2dBar                                     = 1            ' &H1
%VtChChartType3dLine                                    = 2            ' &H2
%VtChChartType2dLine                                    = 3            ' &H3
%VtChChartType3dArea                                    = 4            ' &H4
%VtChChartType2dArea                                    = 5            ' &H5
%VtChChartType3dStep                                    = 6            ' &H6
%VtChChartType2dStep                                    = 7            ' &H7
%VtChChartType3dCombination                             = 8            ' &H8
%VtChChartType2dCombination                             = 9            ' &H9
%VtChChartType3dHorizontalBar                           = 10           ' &HA
%VtChChartType2dHorizontalBar                           = 11           ' &HB
%VtChChartType3dClusteredBar                            = 12           ' &HC
%VtChChartType3dPie                                     = 13           ' &HD
%VtChChartType2dPie                                     = 14           ' &HE
%VtChChartType3dDoughnut                                = 15           ' &HF
%VtChChartType2dXY                                      = 16           ' &H10
%VtChChartType2dPolar                                   = 17           ' &H11
%VtChChartType2dRadar                                   = 18           ' &H12
%VtChChartType2dBubble                                  = 19           ' &H13
%VtChChartType2dHiLo                                    = 20           ' &H14
%VtChChartType2dGantt                                   = 21           ' &H15
%VtChChartType3dGantt                                   = 22           ' &H16
%VtChChartType3dSurface                                 = 23           ' &H17
%VtChChartType2dContour                                 = 24           ' &H18
%VtChChartType3dScatter                                 = 25           ' &H19
%VtChChartType3dXYZ                                     = 26           ' &H1A
%VtChChartTypeCount                                     = 27           ' &H1B

' ========================================================================================
' VtChSeriesType enum
' IID: {C091D28A-BD43-11D1-B137-0000F8753F5D}
' The list of Series types
' ========================================================================================

%VtChSeriesTypeVaries                                   = -2           ' &HFFFFFFFE
%VtChSeriesTypeDefault                                  = -1           ' &HFFFFFFFF
%VtChSeriesType3dBar                                    = 0            ' &H0
%VtChSeriesType2dBar                                    = 1            ' &H1
%VtChSeriesType3dHorizontalBar                          = 2            ' &H2
%VtChSeriesType2dHorizontalBar                          = 3            ' &H3
%VtChSeriesType3dClusteredBar                           = 4            ' &H4
%VtChSeriesType3dLine                                   = 5            ' &H5
%VtChSeriesType2dLine                                   = 6            ' &H6
%VtChSeriesType3dArea                                   = 7            ' &H7
%VtChSeriesType2dArea                                   = 8            ' &H8
%VtChSeriesType3dStep                                   = 9            ' &H9
%VtChSeriesType2dStep                                   = 10           ' &HA
%VtChSeriesType2dXY                                     = 11           ' &HB
%VtChSeriesType2dPolar                                  = 12           ' &HC
%VtChSeriesType2dRadarLine                              = 13           ' &HD
%VtChSeriesType2dRadarArea                              = 14           ' &HE
%VtChSeriesType2dBubble                                 = 15           ' &HF
%VtChSeriesType2dHiLo                                   = 16           ' &H10
%VtChSeriesType2dHLC                                    = 17           ' &H11
%VtChSeriesType2dHLCRight                               = 18           ' &H12
%VtChSeriesType2dOHLC                                   = 19           ' &H13
%VtChSeriesType2dOHLCBar                                = 20           ' &H14
%VtChSeriesType2dGantt                                  = 21           ' &H15
%VtChSeriesType3dGantt                                  = 22           ' &H16
%VtChSeriesType3dPie                                    = 23           ' &H17
%VtChSeriesType2dPie                                    = 24           ' &H18
%VtChSeriesType3dDoughnut                               = 25           ' &H19
%VtChSeriesType2dDates                                  = 26           ' &H1A
%VtChSeriesType3dBarHiLo                                = 27           ' &H1B
%VtChSeriesType2dBarHiLo                                = 28           ' &H1C
%VtChSeriesType3dHorizontalBarHiLo                      = 29           ' &H1D
%VtChSeriesType2dHorizontalBarHiLo                      = 30           ' &H1E
%VtChSeriesType3dClusteredBarHiLo                       = 31           ' &H1F
%VtChSeriesType3dSurface                                = 32           ' &H20
%VtChSeriesType2dContour                                = 33           ' &H21
%VtChSeriesType3dXYZ                                    = 34           ' &H22
%VtChSeriesTypeCount                                    = 35           ' &H23

' ========================================================================================
' VtChPartType enum
' IID: {C091D28B-BD43-11D1-B137-0000F8753F5D}
' Chart Part Type Constants
' ========================================================================================

%VtChPartTypeChart                                      = 0            ' &H0
%VtChPartTypeTitle                                      = 1            ' &H1
%VtChPartTypeFootnote                                   = 2            ' &H2
%VtChPartTypeLegend                                     = 3            ' &H3
%VtChPartTypePlot                                       = 4            ' &H4
%VtChPartTypeSeries                                     = 5            ' &H5
%VtChPartTypeSeriesLabel                                = 6            ' &H6
%VtChPartTypePoint                                      = 7            ' &H7
%VtChPartTypePointLabel                                 = 8            ' &H8
%VtChPartTypeAxis                                       = 9            ' &H9
%VtChPartTypeAxisLabel                                  = 10           ' &HA
%VtChPartTypeAxisTitle                                  = 11           ' &HB
%VtChPartTypeSeriesName                                 = 12           ' &HC
%VtChPartTypePointName                                  = 13           ' &HD
%VtChPartTypeCount                                      = 14           ' &HE

' ========================================================================================
' VtChLocationType enum
' IID: {C091D28C-BD43-11D1-B137-0000F8753F5D}
' Chart Element Location Type Constants
' ========================================================================================

%VtChLocationTypeTopLeft                                = 0            ' &H0
%VtChLocationTypeTop                                    = 1            ' &H1
%VtChLocationTypeTopRight                               = 2            ' &H2
%VtChLocationTypeLeft                                   = 3            ' &H3
%VtChLocationTypeRight                                  = 4            ' &H4
%VtChLocationTypeBottomLeft                             = 5            ' &H5
%VtChLocationTypeBottom                                 = 6            ' &H6
%VtChLocationTypeBottomRight                            = 7            ' &H7
%VtChLocationTypeCustom                                 = 8            ' &H8

' ========================================================================================
' VtChLabelComponent enum
' IID: {C091D28D-BD43-11D1-B137-0000F8753F5D}
' The list of datapoint label component types
' ========================================================================================

%VtChLabelComponentValue                                = 1            ' &H1
%VtChLabelComponentPercent                              = 2            ' &H2
%VtChLabelComponentSeriesName                           = 4            ' &H4
%VtChLabelComponentPointName                            = 8            ' &H8

' ========================================================================================
' VtChLabelLineStyle enum
' IID: {C091D28E-BD43-11D1-B137-0000F8753F5D}
' The list of series/datapoint label line styles
' ========================================================================================

%VtChLabelLineStyleNone                                 = 0            ' &H0
%VtChLabelLineStyleStraight                             = 1            ' &H1
%VtChLabelLineStyleBent                                 = 2            ' &H2

' ========================================================================================
' VtChLabelLocationType enum
' IID: {C091D28F-BD43-11D1-B137-0000F8753F5D}
' The list of series/datapoint label locations
' ========================================================================================

%VtChLabelLocationTypeNone                              = 0            ' &H0
%VtChLabelLocationTypeAbovePoint                        = 1            ' &H1
%VtChLabelLocationTypeBelowPoint                        = 2            ' &H2
%VtChLabelLocationTypeCenter                            = 3            ' &H3
%VtChLabelLocationTypeBase                              = 4            ' &H4
%VtChLabelLocationTypeInside                            = 5            ' &H5
%VtChLabelLocationTypeOutside                           = 6            ' &H6
%VtChLabelLocationTypeLeft                              = 7            ' &H7
%VtChLabelLocationTypeRight                             = 8            ' &H8

' ========================================================================================
' VtChSubPlotLabelLocationType enum
' IID: {C091D290-BD43-11D1-B137-0000F8753F5D}
' Sub Plot Label Location Type Constants
' ========================================================================================

%VtChSubPlotLabelLocationTypeNone                       = 0            ' &H0
%VtChSubPlotLabelLocationTypeAbove                      = 1            ' &H1
%VtChSubPlotLabelLocationTypeBelow                      = 2            ' &H2
%VtChSubPlotLabelLocationTypeCenter                     = 3            ' &H3

' ========================================================================================
' VtChPieWeightBasis enum
' IID: {C091D291-BD43-11D1-B137-0000F8753F5D}
' Pie Weight Basis Constants
' ========================================================================================

%VtChPieWeightBasisNone                                 = 0            ' &H0
%VtChPieWeightBasisTotal                                = 1            ' &H1
%VtChPieWeightBasisSeries                               = 2            ' &H2

' ========================================================================================
' VtChPieWeightStyle enum
' IID: {C091D292-BD43-11D1-B137-0000F8753F5D}
' Pie Weight Style Constants
' ========================================================================================

%VtChPieWeightStyleArea                                 = 0            ' &H0
%VtChPieWeightStyleDiameter                             = 1            ' &H1

' ========================================================================================
' VtChAxisId enum
' IID: {C091D293-BD43-11D1-B137-0000F8753F5D}
' Axis Id Constants
' ========================================================================================

%VtChAxisIdX                                            = 0            ' &H0
%VtChAxisIdY                                            = 1            ' &H1
%VtChAxisIdY2                                           = 2            ' &H2
%VtChAxisIdZ                                            = 3            ' &H3
%VtChAxisIdNone                                         = 4            ' &H4

' ========================================================================================
' VtChDateIntervalType enum
' IID: {C091D294-BD43-11D1-B137-0000F8753F5D}
' Date Interval Constants
' ========================================================================================

%VtChDateIntervalTypeNone                               = 0            ' &H0
%VtChDateIntervalTypeDaily                              = 1            ' &H1
%VtChDateIntervalTypeWeekly                             = 2            ' &H2
%VtChDateIntervalTypeSemimonthly                        = 3            ' &H3
%VtChDateIntervalTypeMonthly                            = 4            ' &H4
%VtChDateIntervalTypeYearly                             = 5            ' &H5

' ========================================================================================
' VtChScaleType enum
' IID: {C091D295-BD43-11D1-B137-0000F8753F5D}
' Scale Type Constants
' ========================================================================================

%VtChScaleTypeLinear                                    = 0            ' &H0
%VtChScaleTypeLogarithmic                               = 1            ' &H1
%VtChScaleTypePercent                                   = 2            ' &H2

' ========================================================================================
' VtChPercentAxisBasis enum
' IID: {C091D296-BD43-11D1-B137-0000F8753F5D}
' Percent Axis Basis Constants
' ========================================================================================

%VtChPercentAxisBasisMaxChart                           = 0            ' &H0
%VtChPercentAxisBasisMaxRow                             = 1            ' &H1
%VtChPercentAxisBasisMaxColumn                          = 2            ' &H2
%VtChPercentAxisBasisSumChart                           = 3            ' &H3
%VtChPercentAxisBasisSumRow                             = 4            ' &H4
%VtChPercentAxisBasisSumColumn                          = 5            ' &H5

' ========================================================================================
' VtChAxisTickStyle enum
' IID: {C091D297-BD43-11D1-B137-0000F8753F5D}
' Axis Tick Style Constants
' ========================================================================================

%VtChAxisTickStyleNone                                  = 0            ' &H0
%VtChAxisTickStyleCenter                                = 1            ' &H1
%VtChAxisTickStyleInside                                = 2            ' &H2
%VtChAxisTickStyleOutside                               = 3            ' &H3

' ========================================================================================
' VtChStats enum
' IID: {C091D298-BD43-11D1-B137-0000F8753F5D}
' Stat Type Constants
' ========================================================================================

%VtChStatsMinimum                                       = 1            ' &H1
%VtChStatsMaximum                                       = 2            ' &H2
%VtChStatsMean                                          = 4            ' &H4
%VtChStatsStddev                                        = 8            ' &H8
%VtChStatsRegression                                    = 16           ' &H10

' ========================================================================================
' VtChUpdateFlags enum
' IID: {C091D299-BD43-11D1-B137-0000F8753F5D}
' Update Flag Constants
' ========================================================================================

%VtChNoDisplay                                          = 0            ' &H0
%VtChDisplayPlot                                        = 1            ' &H1
%VtChLayoutPlot                                         = 2            ' &H2
%VtChDisplayLegend                                      = 4            ' &H4
%VtChLayoutLegend                                       = 8            ' &H8
%VtChLayoutSeries                                       = 16           ' &H10
%VtChPositionSection                                    = 32           ' &H20

' ========================================================================================
' VtChMouseFlag enum
' IID: {C091D2A2-BD43-11D1-B137-0000F8753F5D}
' Mouse Flag Constants
' ========================================================================================

%VtChMouseFlagShiftKeyDown                              = 4            ' &H4
%VtChMouseFlagControlKeyDown                            = 8            ' &H8

' ========================================================================================
' VtChSsLinkMode enum
' IID: {C091D29A-BD43-11D1-B137-0000F8753F5D}
' The list of Formula One spreadsheet link modes
' ========================================================================================

%VtChSsLinkModeOff                                      = 0            ' &H0
%VtChSsLinkModeOn                                       = 1            ' &H1
%VtChSsLinkModeAutoParse                                = 2            ' &H2

' ========================================================================================
' VtChDrawMode enum
' IID: {C091D29B-BD43-11D1-B137-0000F8753F5D}
' The list of Draw modes
' ========================================================================================

%VtChDrawModeDraw                                       = 0            ' &H0
%VtChDrawModeBlit                                       = 1            ' &H1

' ========================================================================================
' VtChContourColorType enum
' IID: {C091D29C-BD43-11D1-B137-0000F8753F5D}
' Contour VtColor Type Constants
' ========================================================================================

%VtChContourColorTypeAutomatic                          = 0            ' &H0
%VtChContourColorTypeGradient                           = 1            ' &H1
%VtChContourColorTypeManual                             = 2            ' &H2

' ========================================================================================
' VtChContourDisplayType enum
' IID: {C091D29D-BD43-11D1-B137-0000F8753F5D}
' Contour Display Type Constants
' ========================================================================================

%VtChContourDisplayTypeCBands                           = 0            ' &H0
%VtChContourDisplayTypeCLines                           = 1            ' &H1

' ========================================================================================
' VtChSurfaceBaseType enum
' IID: {C091D29E-BD43-11D1-B137-0000F8753F5D}
' Surface Base Type Constants
' ========================================================================================

%VtChSurfaceBaseTypePedestal                            = 0            ' &H0
%VtChSurfaceBaseTypeStandard                            = 1            ' &H1
%VtChSurfaceBaseTypeStandardWithCBands                  = 2            ' &H2
%VtChSurfaceBaseTypeStandardWithCLines                  = 3            ' &H3

' ========================================================================================
' VtChSurfaceDisplayType enum
' IID: {C091D29F-BD43-11D1-B137-0000F8753F5D}
' Surface Display Type Constants
' ========================================================================================

%VtChSurfaceDisplayTypeNone                             = 0            ' &H0
%VtChSurfaceDisplayTypeCBands                           = 1            ' &H1
%VtChSurfaceDisplayTypeCLines                           = 2            ' &H2
%VtChSurfaceDisplayTypeSolid                            = 3            ' &H3
%VtChSurfaceDisplayTypeSolidWithCLines                  = 4            ' &H4

' ========================================================================================
' VtChSurfaceProjectionType enum
' IID: {C091D2A0-BD43-11D1-B137-0000F8753F5D}
' Surface Projection Type Constants
' ========================================================================================

%VtChSurfaceProjectionTypeNone                          = 0            ' &H0
%VtChSurfaceProjectionTypeCBands                        = 1            ' &H1
%VtChSurfaceProjectionTypeCLines                        = 2            ' &H2

' ========================================================================================
' VtChSurfaceWireframeType enum
' IID: {C091D2A1-BD43-11D1-B137-0000F8753F5D}
' Surface Wireframe Type Constants
' ========================================================================================

%VtChSurfaceWireframeTypeNone                           = 0            ' &H0
%VtChSurfaceWireframeTypeMajor                          = 1            ' &H1
%VtChSurfaceWireframeTypeMajorAndMinor                  = 2            ' &H2

' ========================================================================================
' VtBorderStyle enum
' IID: {3A2B3708-BA0A-11D1-B137-0000F8753F5D}
' Border Style Constants
' ========================================================================================

%VtBorderStyleNone                                      = 0            ' &H0
%VtBorderStyleFixedSingle                               = 1            ' &H1

' ========================================================================================
' VtMousePointer enum
' IID: {3A2B3709-BA0A-11D1-B137-0000F8753F5D}
' Mouse Pointer Constants
' ========================================================================================

%VtMousePointerDefault                                  = 0            ' &H0
%VtMousePointerArrow                                    = 1            ' &H1
%VtMousePointerCross                                    = 2            ' &H2
%VtMousePointerIbeam                                    = 3            ' &H3
%VtMousePointerIcon                                     = 4            ' &H4
%VtMousePointerSize                                     = 5            ' &H5
%VtMousePointerSizeNESW                                 = 6            ' &H6
%VtMousePointerSizeNS                                   = 7            ' &H7
%VtMousePointerSizeNWSE                                 = 8            ' &H8
%VtMousePointerSizeWE                                   = 9            ' &H9
%VtMousePointerUpArrow                                  = 10           ' &HA
%VtMousePointerHourGlass                                = 11           ' &HB
%VtMousePointerNoDrop                                   = 12           ' &HC
%VtMousePointerArrowHourGlass                           = 13           ' &HD
%VtMousePointerArrowQuestion                            = 14           ' &HE
%VtMousePointerSizeAll                                  = 15           ' &HF

' ########################################################################################
' Interface name = IVcCoor
' IID = {E9E074C9-BA0A-11D1-B137-0000F8753F5D}
' Coor object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcCoor_INTERFACE_DEFINED)
    %MSChartIVcCoor_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcCoor $IID_MSChartIVcCoor

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET X <1> ( _                               ' VTable offset = 28
   ) AS SINGLE                                          ' __retval_out float* X
   ' =====================================================================================
   PROPERTY SET X <1> ( _                               ' VTable offset = 32
     BYVAL X AS SINGLE _                                ' __in float X
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Y <2> ( _                               ' VTable offset = 36
   ) AS SINGLE                                          ' __retval_out float* Y
   ' =====================================================================================
   PROPERTY SET Y <2> ( _                               ' VTable offset = 40
     BYVAL y AS SINGLE _                                ' __in float Y
   )                                                    ' void
   ' =====================================================================================
   METHOD Set <3> ( _                                   ' VTable offset = 44
     BYVAL X AS SINGLE _                                ' __in float X
   , BYVAL Y AS SINGLE _                                ' __in float Y
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcCoor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcLCoor
' IID = {E9E074CB-BA0A-11D1-B137-0000F8753F5D}
' LCoor object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcLCoor_INTERFACE_DEFINED)
    %MSChartIVcLCoor_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcLCoor $IID_MSChartIVcLCoor

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET X <1> ( _                               ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long* X
   ' =====================================================================================
   PROPERTY SET X <1> ( _                               ' VTable offset = 32
     BYVAL X AS LONG _                                  ' __in long X
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Y <2> ( _                               ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long* Y
   ' =====================================================================================
   PROPERTY SET Y <2> ( _                               ' VTable offset = 40
     BYVAL y AS LONG _                                  ' __in long Y
   )                                                    ' void
   ' =====================================================================================
   METHOD Set <3> ( _                                   ' VTable offset = 44
     BYVAL X AS LONG _                                  ' __in long X
   , BYVAL Y AS LONG _                                  ' __in long Y
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcLCoor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcRect
' IID = {E9E074CD-BA0A-11D1-B137-0000F8753F5D}
' Rect object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcRect_INTERFACE_DEFINED)
    %MSChartIVcRect_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcRect $IID_MSChartIVcRect

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Min <1> ( _                             ' VTable offset = 28
   ) AS MSChartIVcCoor                                  ' __retval_out IVcCoor** Min
   ' =====================================================================================
   PROPERTY GET Max <2> ( _                             ' VTable offset = 32
   ) AS MSChartIVcCoor                                  ' __retval_out IVcCoor** Max
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcRect_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcColor
' IID = {E9E074CF-BA0A-11D1-B137-0000F8753F5D}
' VtColor object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcColor_INTERFACE_DEFINED)
    %MSChartIVcColor_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcColor $IID_MSChartIVcColor

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Red <1> ( _                             ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short* Red
   ' =====================================================================================
   PROPERTY SET Red <1> ( _                             ' VTable offset = 32
     BYVAL Red AS INTEGER _                             ' __in short Red
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Green <2> ( _                           ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out short* Green
   ' =====================================================================================
   PROPERTY SET Green <2> ( _                           ' VTable offset = 40
     BYVAL Green AS INTEGER _                           ' __in short Green
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Blue <3> ( _                            ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out short* Blue
   ' =====================================================================================
   PROPERTY SET Blue <3> ( _                            ' VTable offset = 48
     BYVAL Blue AS INTEGER _                            ' __in short Blue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Automatic <4> ( _                       ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Automatic
   ' =====================================================================================
   PROPERTY SET Automatic <4> ( _                       ' VTable offset = 56
     BYVAL Automatic AS INTEGER _                       ' __in VARIANT_BOOL Automatic
   )                                                    ' void
   ' =====================================================================================
   METHOD Set <5> ( _                                   ' VTable offset = 60
     BYVAL Red AS INTEGER _                             ' __in short Red
   , BYVAL Green AS INTEGER _                           ' __in short Green
   , BYVAL Blue AS INTEGER _                            ' __in short Blue
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcColor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcPen
' IID = {E9E074D1-BA0A-11D1-B137-0000F8753F5D}
' Pen object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcPen_INTERFACE_DEFINED)
    %MSChartIVcPen_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcPen $IID_MSChartIVcPen

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Style <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out VtPenStyle* Style
   ' =====================================================================================
   PROPERTY SET Style <1> ( _                           ' VTable offset = 32
     BYVAL LONG _                                       ' __in VtPenStyle Style
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Join <2> ( _                            ' VTable offset = 36
   ) AS LONG                                            ' __retval_out VtPenJoin* Join
   ' =====================================================================================
   PROPERTY SET Join <2> ( _                            ' VTable offset = 40
     BYVAL Join AS LONG _                               ' __in VtPenJoin Join
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Cap <3> ( _                             ' VTable offset = 44
   ) AS LONG                                            ' __retval_out VtPenCap* Cap
   ' =====================================================================================
   PROPERTY SET Cap <3> ( _                             ' VTable offset = 48
     BYVAL Cap AS LONG _                                ' __in VtPenCap Cap
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VtColor <4> ( _                         ' VTable offset = 52
   ) AS MSChartIVcColor                                 ' __retval_out IVcColor** VtColor
   ' =====================================================================================
   PROPERTY GET Width <5> ( _                           ' VTable offset = 56
   ) AS SINGLE                                          ' __retval_out float* Width
   ' =====================================================================================
   PROPERTY SET Width <5> ( _                           ' VTable offset = 60
     BYVAL Width AS SINGLE _                            ' __in float Width
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Limit <6> ( _                           ' VTable offset = 64
   ) AS SINGLE                                          ' __retval_out float* Limit
   ' =====================================================================================
   PROPERTY SET Limit <6> ( _                           ' VTable offset = 68
     BYVAL Limit AS SINGLE _                            ' __in float Limit
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcPen_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcMarker
' IID = {E9E074D3-BA0A-11D1-B137-0000F8753F5D}
' Marker object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcMarker_INTERFACE_DEFINED)
    %MSChartIVcMarker_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcMarker $IID_MSChartIVcMarker

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Visible <1> ( _                         ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Visible
   ' =====================================================================================
   PROPERTY SET Visible <1> ( _                         ' VTable offset = 32
     BYVAL Visible AS INTEGER _                         ' __in VARIANT_BOOL Visible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Style <2> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out VtMarkerStyle* Style
   ' =====================================================================================
   PROPERTY SET Style <2> ( _                           ' VTable offset = 40
     BYVAL Style AS LONG _                              ' __in VtMarkerStyle Style
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Pen <3> ( _                             ' VTable offset = 44
   ) AS MSChartIVcPen                                   ' __retval_out IVcPen** Pen
   ' =====================================================================================
   PROPERTY GET Size <4> ( _                            ' VTable offset = 48
   ) AS SINGLE                                          ' __retval_out float* Size
   ' =====================================================================================
   PROPERTY SET Size <4> ( _                            ' VTable offset = 52
     BYVAL Size AS SINGLE _                             ' __in float Size
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FillColor <5> ( _                       ' VTable offset = 56
   ) AS MSChartIVcColor                                 ' __retval_out IVcColor** FillColor
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcMarker_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcTextLayout
' IID = {E9E074D5-BA0A-11D1-B137-0000F8753F5D}
' TextLayout object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcTextLayout_INTERFACE_DEFINED)
    %MSChartIVcTextLayout_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcTextLayout $IID_MSChartIVcTextLayout

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET HorzAlignment <1> ( _                   ' VTable offset = 28
   ) AS LONG                                            ' __retval_out VtHorizontalAlignment* HorzAlignment
   ' =====================================================================================
   PROPERTY SET HorzAlignment <1> ( _                   ' VTable offset = 32
     BYVAL HorzAlignment AS LONG _                      ' __in VtHorizontalAlignment HorzAlignment
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VertAlignment <2> ( _                   ' VTable offset = 36
   ) AS LONG                                            ' __retval_out VtVerticalAlignment* VertAlignment
   ' =====================================================================================
   PROPERTY SET VertAlignment <2> ( _                   ' VTable offset = 40
     BYVAL VertAlignment AS LONG _                      ' __in VtVerticalAlignment VertAlignment
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Orientation <3> ( _                     ' VTable offset = 44
   ) AS LONG                                            ' __retval_out VtOrientation* Orientation
   ' =====================================================================================
   PROPERTY SET Orientation <3> ( _                     ' VTable offset = 48
     BYVAL Orientation AS LONG _                        ' __in VtOrientation Orientation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WordWrap <4> ( _                        ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* WordWrap
   ' =====================================================================================
   PROPERTY SET WordWrap <4> ( _                        ' VTable offset = 56
     BYVAL WordWrap AS INTEGER _                        ' __in VARIANT_BOOL WordWrap
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcTextLayout_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcLocation
' IID = {E9E074D6-BA0A-11D1-B137-0000F8753F5D}
' Location object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcLocation_INTERFACE_DEFINED)
    %MSChartIVcLocation_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcLocation $IID_MSChartIVcLocation

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Rect <1> ( _                            ' VTable offset = 28
   ) AS MSChartIVcRect                                  ' __retval_out IVcRect** Rect
   ' =====================================================================================
   PROPERTY GET Visible <2> ( _                         ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Visible
   ' =====================================================================================
   PROPERTY SET Visible <2> ( _                         ' VTable offset = 36
     BYVAL Visible AS INTEGER _                         ' __in VARIANT_BOOL Visible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LocationType <3> ( _                    ' VTable offset = 40
   ) AS LONG                                            ' __retval_out VtChLocationType* LocationType
   ' =====================================================================================
   PROPERTY SET LocationType <3> ( _                    ' VTable offset = 44
     BYVAL LocationType AS LONG _                       ' __in VtChLocationType LocationType
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcLocation_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcFont
' IID = {E9E074D8-BA0A-11D1-B137-0000F8753F5D}
' VtFont object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcFont_INTERFACE_DEFINED)
    %MSChartIVcFont_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcFont $IID_MSChartIVcFont

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* Name
   ' =====================================================================================
   PROPERTY SET Name <1> ( _                            ' VTable offset = 32
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Size <2> ( _                            ' VTable offset = 36
   ) AS SINGLE                                          ' __retval_out float* Size
   ' =====================================================================================
   PROPERTY SET Size <2> ( _                            ' VTable offset = 40
     BYVAL Size AS SINGLE _                             ' __in float Size
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Style <3> ( _                           ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out short* Style
   ' =====================================================================================
   PROPERTY SET Style <3> ( _                           ' VTable offset = 48
     BYVAL Style AS INTEGER _                           ' __in short Style
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Effect <4> ( _                          ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out short* Effect
   ' =====================================================================================
   PROPERTY SET Effect <4> ( _                          ' VTable offset = 56
     BYVAL Effect AS INTEGER _                          ' __in short Effect
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VtColor <5> ( _                         ' VTable offset = 60
   ) AS MSChartIVcColor                                 ' __retval_out IVcColor** VtColor
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcFont_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcBrush
' IID = {E9E074DA-BA0A-11D1-B137-0000F8753F5D}
' Brush object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcBrush_INTERFACE_DEFINED)
    %MSChartIVcBrush_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcBrush $IID_MSChartIVcBrush

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Style <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out VtBrushStyle* Style
   ' =====================================================================================
   PROPERTY SET Style <1> ( _                           ' VTable offset = 32
     BYVAL Style AS LONG _                              ' __in VtBrushStyle Style
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FillColor <2> ( _                       ' VTable offset = 36
   ) AS MSChartIVcColor                                 ' __retval_out IVcColor** FillColor
   ' =====================================================================================
   PROPERTY GET PatternColor <3> ( _                    ' VTable offset = 40
   ) AS MSChartIVcColor                                 ' __retval_out IVcColor** PatternColor
   ' =====================================================================================
   PROPERTY GET Index <4> ( _                           ' VTable offset = 44
   ) AS LONG                                            ' __retval_out VtBrushPatterns* Index
   ' =====================================================================================
   PROPERTY SET Index <4> ( _                           ' VTable offset = 48
     BYVAL Index AS LONG _                              ' __in VtBrushPatterns Index
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcBrush_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcShadow
' IID = {E9E074DC-BA0A-11D1-B137-0000F8753F5D}
' Shadow object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcShadow_INTERFACE_DEFINED)
    %MSChartIVcShadow_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcShadow $IID_MSChartIVcShadow

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Style <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out VtShadowStyle* Style
   ' =====================================================================================
   PROPERTY SET Style <1> ( _                           ' VTable offset = 32
     BYVAL Style AS LONG _                              ' __in VtShadowStyle Style
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Brush <2> ( _                           ' VTable offset = 36
   ) AS MSChartIVcBrush                                 ' __retval_out IVcBrush** Brush
   ' =====================================================================================
   PROPERTY GET Offset <3> ( _                          ' VTable offset = 40
   ) AS MSChartIVcCoor                                  ' __retval_out IVcCoor** Offset
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcShadow_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcFill
' IID = {E9E074DE-BA0A-11D1-B137-0000F8753F5D}
' Fill object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcFill_INTERFACE_DEFINED)
    %MSChartIVcFill_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcFill $IID_MSChartIVcFill

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Style <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out VtFillStyle* Style
   ' =====================================================================================
   PROPERTY SET Style <1> ( _                           ' VTable offset = 32
     BYVAL Style AS LONG _                              ' __in VtFillStyle Style
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Brush <2> ( _                           ' VTable offset = 36
   ) AS MSChartIVcBrush                                 ' __retval_out IVcBrush** Brush
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcFill_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcFrame
' IID = {E9E074E0-BA0A-11D1-B137-0000F8753F5D}
' Frame object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcFrame_INTERFACE_DEFINED)
    %MSChartIVcFrame_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcFrame $IID_MSChartIVcFrame

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Style <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out VtFrameStyle* Style
   ' =====================================================================================
   PROPERTY SET Style <1> ( _                           ' VTable offset = 32
     BYVAL Style AS LONG _                              ' __in VtFrameStyle Style
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FrameColor <2> ( _                      ' VTable offset = 36
   ) AS MSChartIVcColor                                 ' __retval_out IVcColor** FrameColor
   ' =====================================================================================
   PROPERTY GET SpaceColor <3> ( _                      ' VTable offset = 40
   ) AS MSChartIVcColor                                 ' __retval_out IVcColor** SpaceColor
   ' =====================================================================================
   PROPERTY GET Width <4> ( _                           ' VTable offset = 44
   ) AS SINGLE                                          ' __retval_out float* Width
   ' =====================================================================================
   PROPERTY SET Width <4> ( _                           ' VTable offset = 48
     BYVAL Width AS SINGLE _                            ' __in float Width
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcFrame_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcBackdrop
' IID = {E9E074E2-BA0A-11D1-B137-0000F8753F5D}
' Backdrop object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcBackdrop_INTERFACE_DEFINED)
    %MSChartIVcBackdrop_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcBackdrop $IID_MSChartIVcBackdrop

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Shadow <1> ( _                          ' VTable offset = 28
   ) AS MSChartIVcShadow                                ' __retval_out IVcShadow** Shadow
   ' =====================================================================================
   PROPERTY GET Frame <2> ( _                           ' VTable offset = 32
   ) AS MSChartIVcFrame                                 ' __retval_out IVcFrame** Frame
   ' =====================================================================================
   PROPERTY GET Fill <3> ( _                            ' VTable offset = 36
   ) AS MSChartIVcFill                                  ' __retval_out IVcFill** Fill
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcBackdrop_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcTitle
' IID = {E9E074E4-BA0A-11D1-B137-0000F8753F5D}
' Title object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcTitle_INTERFACE_DEFINED)
    %MSChartIVcTitle_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcTitle $IID_MSChartIVcTitle

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Text_ <0> ( _                           ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* _Text
   ' =====================================================================================
   PROPERTY SET Text_ <0> ( _                           ' VTable offset = 32
     BYVAL Text AS WSTRING _                            ' __in BSTR _Text
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TextLayout <1> ( _                      ' VTable offset = 36
   ) AS MSChartIVcTextLayout                            ' __retval_out IVcTextLayout** TextLayout
   ' =====================================================================================
   PROPERTY GET Text <2> ( _                            ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* Text
   ' =====================================================================================
   PROPERTY SET Text <2> ( _                            ' VTable offset = 44
     BYVAL Text AS WSTRING _                            ' __in BSTR Text
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Location <3> ( _                        ' VTable offset = 48
   ) AS MSChartIVcLocation                              ' __retval_out IVcLocation** Location
   ' =====================================================================================
   PROPERTY GET Backdrop <4> ( _                        ' VTable offset = 52
   ) AS MSChartIVcBackdrop                              ' __retval_out IVcBackdrop** Backdrop
   ' =====================================================================================
   PROPERTY GET VtFont <5> ( _                          ' VTable offset = 56
   ) AS MSChartIVcFont                                  ' __retval_out IVcFont** VtFont
   ' =====================================================================================
   PROPERTY GET TextLength <6> ( _                      ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out short* TextLength
   ' =====================================================================================
   PROPERTY SET putref_Font <8> ( _                     ' VTable offset = 64
     BYVAL Font AS IFontDisp _                          ' __in IFontDisp* Font
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font <8> ( _                            ' VTable offset = 68
   ) AS IFontDisp                                       ' __retval_out IFontDisp** Font
   ' =====================================================================================
   METHOD Select <7> ( _                                ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcTitle_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcFootnote
' IID = {E9E074E6-BA0A-11D1-B137-0000F8753F5D}
' Footnote object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcFootnote_INTERFACE_DEFINED)
    %MSChartIVcFootnote_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcFootnote $IID_MSChartIVcFootnote

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Text_ <0> ( _                           ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* _Text
   ' =====================================================================================
   PROPERTY SET Text_ <0> ( _                           ' VTable offset = 32
     BYVAL Text AS WSTRING _                            ' __in BSTR _Text
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TextLayout <1> ( _                      ' VTable offset = 36
   ) AS MSChartIVcTextLayout                            ' __retval_out IVcTextLayout** TextLayout
   ' =====================================================================================
   PROPERTY GET Location <2> ( _                        ' VTable offset = 40
   ) AS MSChartIVcLocation                              ' __retval_out IVcLocation** Location
   ' =====================================================================================
   PROPERTY GET Backdrop <3> ( _                        ' VTable offset = 44
   ) AS MSChartIVcBackdrop                              ' __retval_out IVcBackdrop** Backdrop
   ' =====================================================================================
   PROPERTY GET VtFont <4> ( _                          ' VTable offset = 48
   ) AS MSChartIVcFont                                  ' __retval_out IVcFont** VtFont
   ' =====================================================================================
   PROPERTY GET Text <5> ( _                            ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* Text
   ' =====================================================================================
   PROPERTY SET Text <5> ( _                            ' VTable offset = 56
     BYVAL Text AS WSTRING _                            ' __in BSTR Text
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TextLength <6> ( _                      ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out short* TextLength
   ' =====================================================================================
   PROPERTY SET putref_Font <8> ( _                     ' VTable offset = 64
     BYVAL Font AS IFontDisp _                          ' __in IFontDisp* Font
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font <8> ( _                            ' VTable offset = 68
   ) AS IFontDisp                                       ' __retval_out IFontDisp** Font
   ' =====================================================================================
   METHOD Select <7> ( _                                ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcFootnote_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcLegend
' IID = {E9E074E8-BA0A-11D1-B137-0000F8753F5D}
' Legend object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcLegend_INTERFACE_DEFINED)
    %MSChartIVcLegend_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcLegend $IID_MSChartIVcLegend

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Location <1> ( _                        ' VTable offset = 28
   ) AS MSChartIVcLocation                              ' __retval_out IVcLocation** Location
   ' =====================================================================================
   PROPERTY GET Backdrop <2> ( _                        ' VTable offset = 32
   ) AS MSChartIVcBackdrop                              ' __retval_out IVcBackdrop** Backdrop
   ' =====================================================================================
   PROPERTY GET VtFont <3> ( _                          ' VTable offset = 36
   ) AS MSChartIVcFont                                  ' __retval_out IVcFont** VtFont
   ' =====================================================================================
   PROPERTY GET TextLayout <4> ( _                      ' VTable offset = 40
   ) AS MSChartIVcTextLayout                            ' __retval_out IVcTextLayout** TextLayout
   ' =====================================================================================
   PROPERTY SET putref_Font <8> ( _                     ' VTable offset = 44
     BYVAL Font AS IFontDisp _                          ' __in IFontDisp* Font
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font <8> ( _                            ' VTable offset = 48
   ) AS IFontDisp                                       ' __retval_out IFontDisp** Font
   ' =====================================================================================
   METHOD Select <5> ( _                                ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcLegend_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcDataGrid
' IID = {E9E074EA-BA0A-11D1-B137-0000F8753F5D}
' DataGrid object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcDataGrid_INTERFACE_DEFINED)
    %MSChartIVcDataGrid_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcDataGrid $IID_MSChartIVcDataGrid

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ColumnCount <1> ( _                     ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short* ColumnCount
   ' =====================================================================================
   PROPERTY SET ColumnCount <1> ( _                     ' VTable offset = 32
     BYVAL ColumnCount AS INTEGER _                     ' __in short ColumnCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ColumnLabelCount <2> ( _                ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out short* ColumnLabelCount
   ' =====================================================================================
   PROPERTY SET ColumnLabelCount <2> ( _                ' VTable offset = 40
     BYVAL ColumnLabelCount AS INTEGER _                ' __in short ColumnLabelCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RowLabelCount <3> ( _                   ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out short* RowLabelCount
   ' =====================================================================================
   PROPERTY SET RowLabelCount <3> ( _                   ' VTable offset = 48
     BYVAL RowLabelCount AS INTEGER _                   ' __in short RowLabelCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RowCount <4> ( _                        ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out short* RowCount
   ' =====================================================================================
   PROPERTY SET RowCount <4> ( _                        ' VTable offset = 56
     BYVAL RowCount AS INTEGER _                        ' __in short RowCount
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteColumns <5> ( _                         ' VTable offset = 60
     BYVAL Column AS INTEGER _                          ' __in short Column
   , BYVAL Count AS INTEGER _                           ' __in short Count
   )                                                    ' void
   ' =====================================================================================
   METHOD InsertColumns <6> ( _                         ' VTable offset = 64
     BYVAL Column AS INTEGER _                          ' __in short Column
   , BYVAL Count AS INTEGER _                           ' __in short Count
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteColumnLabels <7> ( _                    ' VTable offset = 68
     BYVAL LabelIndex AS INTEGER _                      ' __in short LabelIndex
   , BYVAL Count AS INTEGER _                           ' __in short Count
   )                                                    ' void
   ' =====================================================================================
   METHOD InsertColumnLabels <8> ( _                    ' VTable offset = 72
     BYVAL LabelIndex AS INTEGER _                      ' __in short LabelIndex
   , BYVAL Count AS INTEGER _                           ' __in short Count
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteRows <9> ( _                            ' VTable offset = 76
     BYVAL Row AS INTEGER _                             ' __in short Row
   , BYVAL Count AS INTEGER _                           ' __in short Count
   )                                                    ' void
   ' =====================================================================================
   METHOD InsertRows <10> ( _                           ' VTable offset = 80
     BYVAL Row AS INTEGER _                             ' __in short Row
   , BYVAL Count AS INTEGER _                           ' __in short Count
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteRowLabels <11> ( _                      ' VTable offset = 84
     BYVAL LabelIndex AS INTEGER _                      ' __in short LabelIndex
   , BYVAL Count AS INTEGER _                           ' __in short Count
   )                                                    ' void
   ' =====================================================================================
   METHOD InsertRowLabels <12> ( _                      ' VTable offset = 88
     BYVAL LabelIndex AS INTEGER _                      ' __in short LabelIndex
   , BYVAL Count AS INTEGER _                           ' __in short Count
   )                                                    ' void
   ' =====================================================================================
   METHOD RandomDataFill <13> ( _                       ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD SetSize <14> ( _                              ' VTable offset = 96
     BYVAL RowLabelCount AS INTEGER _                   ' __in short RowLabelCount
   , BYVAL ColumnLabelCount AS INTEGER _                ' __in short ColumnLabelCount
   , BYVAL DataRowCount AS INTEGER _                    ' __in short DataRowCount
   , BYVAL DataColumnCount AS INTEGER _                 ' __in short DataColumnCount
   )                                                    ' void
   ' =====================================================================================
   METHOD InitializeLabels <15> ( _                     ' VTable offset = 100
   )                                                    ' void
   ' =====================================================================================
   METHOD RandomFillColumns <16> ( _                    ' VTable offset = 104
     BYVAL Column AS INTEGER _                          ' __in short Column
   , BYVAL Count AS INTEGER _                           ' __in short Count
   )                                                    ' void
   ' =====================================================================================
   METHOD RandomFillRows <17> ( _                       ' VTable offset = 108
     BYVAL Row AS INTEGER _                             ' __in short Row
   , BYVAL Count AS INTEGER _                           ' __in short Count
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveData <18> ( _                             ' VTable offset = 112
     BYVAL Top AS INTEGER _                             ' __in short Top
   , BYVAL Left AS INTEGER _                            ' __in short Left
   , BYVAL Bottom AS INTEGER _                          ' __in short Bottom
   , BYVAL Right AS INTEGER _                           ' __in short Right
   , BYVAL OverOffset AS INTEGER _                      ' __in short OverOffset
   , BYVAL DownOffset AS INTEGER _                      ' __in short DownOffset
   )                                                    ' void
   ' =====================================================================================
   METHOD GetData <19> ( _                              ' VTable offset = 116
     BYVAL Row AS INTEGER _                             ' __in short Row
   , BYVAL Column AS INTEGER _                          ' __in short Column
   , BYREF DataPoint AS DOUBLE _                        ' __out double* DataPoint
   , BYREF nullFlag AS INTEGER _                        ' __out short* nullFlag
   )                                                    ' void
   ' =====================================================================================
   METHOD SetData <20> ( _                              ' VTable offset = 120
     BYVAL Row AS INTEGER _                             ' __in short Row
   , BYVAL Column AS INTEGER _                          ' __in short Column
   , BYVAL DataPoint AS DOUBLE _                        ' __in double DataPoint
   , BYVAL nullFlag AS INTEGER _                        ' __in short nullFlag
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ColumnLabel <21> ( _                    ' VTable offset = 124
     BYVAL Column AS INTEGER _                          ' __in short Column
   , BYVAL LabelIndex AS INTEGER _                      ' __in short LabelIndex
   ) AS WSTRING                                         ' __retval_out BSTR* ColumnLabel
   ' =====================================================================================
   PROPERTY SET ColumnLabel <21> ( _                    ' VTable offset = 128
     BYVAL Column AS INTEGER _                          ' __in short Column
   , BYVAL LabelIndex AS INTEGER _                      ' __in short LabelIndex
   , BYVAL ColumnLabel AS WSTRING _                     ' __in BSTR ColumnLabel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CompositeColumnLabel <22> ( _           ' VTable offset = 132
     BYVAL Column AS INTEGER _                          ' __in short Column
   ) AS WSTRING                                         ' __retval_out BSTR* CompositeColumnLabel
   ' =====================================================================================
   PROPERTY GET CompositeRowLabel <23> ( _              ' VTable offset = 136
     BYVAL Row AS INTEGER _                             ' __in short Row
   ) AS WSTRING                                         ' __retval_out BSTR* CompositeRowLabel
   ' =====================================================================================
   PROPERTY GET RowLabel <24> ( _                       ' VTable offset = 140
     BYVAL Row AS INTEGER _                             ' __in short Row
   , BYVAL LabelIndex AS INTEGER _                      ' __in short LabelIndex
   ) AS WSTRING                                         ' __retval_out BSTR* RowLabel
   ' =====================================================================================
   PROPERTY SET RowLabel <24> ( _                       ' VTable offset = 144
     BYVAL Row AS INTEGER _                             ' __in short Row
   , BYVAL LabelIndex AS INTEGER _                      ' __in short LabelIndex
   , BYVAL RowLabel AS WSTRING _                        ' __in BSTR RowLabel
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcDataGrid_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcLightSource
' IID = {E9E074EC-BA0A-11D1-B137-0000F8753F5D}
' LightSource object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcLightSource_INTERFACE_DEFINED)
    %MSChartIVcLightSource_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcLightSource $IID_MSChartIVcLightSource

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Intensity_ <0> ( _                      ' VTable offset = 28
   ) AS SINGLE                                          ' __retval_out float* _Intensity
   ' =====================================================================================
   PROPERTY SET Intensity_ <0> ( _                      ' VTable offset = 32
     BYVAL Intensity AS SINGLE _                        ' __in float _Intensity
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Intensity <1> ( _                       ' VTable offset = 36
   ) AS SINGLE                                          ' __retval_out float* Intensity
   ' =====================================================================================
   PROPERTY SET Intensity <1> ( _                       ' VTable offset = 40
     BYVAL Intensity AS SINGLE _                        ' __in float Intensity
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET X <2> ( _                               ' VTable offset = 44
   ) AS SINGLE                                          ' __retval_out float* X
   ' =====================================================================================
   PROPERTY SET X <2> ( _                               ' VTable offset = 48
     BYVAL X AS SINGLE _                                ' __in float X
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Y <3> ( _                               ' VTable offset = 52
   ) AS SINGLE                                          ' __retval_out float* Y
   ' =====================================================================================
   PROPERTY SET Y <3> ( _                               ' VTable offset = 56
     BYVAL Y AS SINGLE _                                ' __in float Y
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Z <4> ( _                               ' VTable offset = 60
   ) AS SINGLE                                          ' __retval_out float* Z
   ' =====================================================================================
   PROPERTY SET Z <4> ( _                               ' VTable offset = 64
     BYVAL Z AS SINGLE _                                ' __in float Z
   )                                                    ' void
   ' =====================================================================================
   METHOD Set <5> ( _                                   ' VTable offset = 68
     BYVAL X AS SINGLE _                                ' __in float X
   , BYVAL Y AS SINGLE _                                ' __in float Y
   , BYVAL Z AS SINGLE _                                ' __in float Z
   , BYVAL Intensity AS SINGLE _                        ' __in float Intensity
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcLightSource_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcLightSources
' IID = {E9E074EE-BA0A-11D1-B137-0000F8753F5D}
' LightSources Collection
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcLightSources_INTERFACE_DEFINED)
    %MSChartIVcLightSources_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcLightSources $IID_MSChartIVcLightSources

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown** ppEnum
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out float* Count
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 36
     BYVAL X AS SINGLE _                                ' __in float X
   , BYVAL Y AS SINGLE _                                ' __in float Y
   , BYVAL Z AS SINGLE _                                ' __in float Z
   , BYVAL Intensity AS SINGLE _                        ' __in float Intensity
   ) AS MSChartIVcLightSource                           ' __retval_out IVcLightSource** Item
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 40
     BYVAL Index AS INTEGER _                           ' __in short Index
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 44
     BYVAL Index AS INTEGER _                           ' __in short Index
   ) AS MSChartIVcLightSource                           ' __retval_out IVcLightSource** Item
   ' =====================================================================================
   PROPERTY GET Item_ <4> ( _                           ' VTable offset = 48
     BYVAL Index AS INTEGER _                           ' __in short Index
   ) AS MSChartIVcLightSource                           ' __retval_out IVcLightSource** Item
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcLightSources_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcLight
' IID = {E9E074F0-BA0A-11D1-B137-0000F8753F5D}
' Light object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcLight_INTERFACE_DEFINED)
    %MSChartIVcLight_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcLight $IID_MSChartIVcLight

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET AmbientIntensity <1> ( _                ' VTable offset = 28
   ) AS SINGLE                                          ' __retval_out float* AmbientIntensity
   ' =====================================================================================
   PROPERTY SET AmbientIntensity <1> ( _                ' VTable offset = 32
     BYVAL AmbientIntensity AS SINGLE _                 ' __in float AmbientIntensity
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EdgeIntensity <2> ( _                   ' VTable offset = 36
   ) AS SINGLE                                          ' __retval_out float* EdgeIntensity
   ' =====================================================================================
   PROPERTY SET EdgeIntensity <2> ( _                   ' VTable offset = 40
     BYVAL EdgeIntensity AS SINGLE _                    ' __in float EdgeIntensity
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EdgeVisible <3> ( _                     ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* EdgeVisible
   ' =====================================================================================
   PROPERTY SET EdgeVisible <3> ( _                     ' VTable offset = 48
     BYVAL EdgeVisible AS INTEGER _                     ' __in VARIANT_BOOL EdgeVisible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LightSources <4> ( _                    ' VTable offset = 52
   ) AS MSChartIVcLightSources                          ' __retval_out IVcLightSources** LightSources
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcLight_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcView3d
' IID = {E9E074F2-BA0A-11D1-B137-0000F8753F5D}
' View3d object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcView3d_INTERFACE_DEFINED)
    %MSChartIVcView3d_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcView3d $IID_MSChartIVcView3d

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Rotation <1> ( _                        ' VTable offset = 28
   ) AS SINGLE                                          ' __retval_out float* Rotation
   ' =====================================================================================
   PROPERTY SET Rotation <1> ( _                        ' VTable offset = 32
     BYVAL Rotation AS SINGLE _                         ' __in float Rotation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Elevation <2> ( _                       ' VTable offset = 36
   ) AS SINGLE                                          ' __retval_out float* Elevation
   ' =====================================================================================
   PROPERTY SET Elevation <2> ( _                       ' VTable offset = 40
     BYVAL Elevation AS SINGLE _                        ' __in float Elevation
   )                                                    ' void
   ' =====================================================================================
   METHOD Set <4> ( _                                   ' VTable offset = 44
     BYVAL Rotation AS SINGLE _                         ' __in float Rotation
   , BYVAL Elevation AS SINGLE _                        ' __in float Elevation
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcView3d_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcPlotBase
' IID = {E9E074F4-BA0A-11D1-B137-0000F8753F5D}
' PlotBase object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcPlotBase_INTERFACE_DEFINED)
    %MSChartIVcPlotBase_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcPlotBase $IID_MSChartIVcPlotBase

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET BaseHeight <1> ( _                      ' VTable offset = 28
   ) AS SINGLE                                          ' __retval_out float* BaseHeight
   ' =====================================================================================
   PROPERTY SET BaseHeight <1> ( _                      ' VTable offset = 32
     BYVAL BaseHeight AS SINGLE _                       ' __in float BaseHeight
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Brush <2> ( _                           ' VTable offset = 36
   ) AS MSChartIVcBrush                                 ' __retval_out IVcBrush** Brush
   ' =====================================================================================
   PROPERTY GET Pen <3> ( _                             ' VTable offset = 40
   ) AS MSChartIVcPen                                   ' __retval_out IVcPen** Pen
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcPlotBase_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcWeighting
' IID = {E9E074FA-BA0A-11D1-B137-0000F8753F5D}
' Weighting object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcWeighting_INTERFACE_DEFINED)
    %MSChartIVcWeighting_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcWeighting $IID_MSChartIVcWeighting

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Basis <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out VtChPieWeightBasis* Basis
   ' =====================================================================================
   PROPERTY SET Basis <1> ( _                           ' VTable offset = 32
     BYVAL Basis AS LONG _                              ' __in VtChPieWeightBasis Basis
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Style <2> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out VtChPieWeightStyle* Style
   ' =====================================================================================
   PROPERTY SET Style <2> ( _                           ' VTable offset = 40
     BYVAL Style AS LONG _                              ' __in VtChPieWeightStyle Style
   )                                                    ' void
   ' =====================================================================================
   METHOD Set <3> ( _                                   ' VTable offset = 44
     BYVAL Basis AS LONG _                              ' __in VtChPieWeightBasis Basis
   , BYVAL Style AS LONG _                              ' __in VtChPieWeightStyle Style
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcWeighting_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcWall
' IID = {E9E074FC-BA0A-11D1-B137-0000F8753F5D}
' Wall object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcWall_INTERFACE_DEFINED)
    %MSChartIVcWall_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcWall $IID_MSChartIVcWall

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Width <1> ( _                           ' VTable offset = 28
   ) AS SINGLE                                          ' __retval_out float* Width
   ' =====================================================================================
   PROPERTY SET Width <1> ( _                           ' VTable offset = 32
     BYVAL Width AS SINGLE _                            ' __in float Width
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Brush <2> ( _                           ' VTable offset = 36
   ) AS MSChartIVcBrush                                 ' __retval_out IVcBrush** Brush
   ' =====================================================================================
   PROPERTY GET Pen <3> ( _                             ' VTable offset = 40
   ) AS MSChartIVcPen                                   ' __retval_out IVcPen** Pen
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcWall_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcSeriesPosition
' IID = {E9E07502-BA0A-11D1-B137-0000F8753F5D}
' SeriesPosition object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcSeriesPosition_INTERFACE_DEFINED)
    %MSChartIVcSeriesPosition_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcSeriesPosition $IID_MSChartIVcSeriesPosition

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Excluded <1> ( _                        ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Excluded
   ' =====================================================================================
   PROPERTY SET Excluded <1> ( _                        ' VTable offset = 32
     BYVAL Excluded AS INTEGER _                        ' __in VARIANT_BOOL Excluded
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Hidden <2> ( _                          ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Hidden
   ' =====================================================================================
   PROPERTY SET Hidden <2> ( _                          ' VTable offset = 40
     BYVAL Hidden AS INTEGER _                          ' __in VARIANT_BOOL Hidden
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Order <3> ( _                           ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out short* Order
   ' =====================================================================================
   PROPERTY SET Order <3> ( _                           ' VTable offset = 48
     BYVAL Order AS INTEGER _                           ' __in short Order
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StackOrder <4> ( _                      ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out short* StackOrder
   ' =====================================================================================
   PROPERTY SET StackOrder <4> ( _                      ' VTable offset = 56
     BYVAL StackOrder AS INTEGER _                      ' __in short StackOrder
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcSeriesPosition_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcSeriesMarker
' IID = {E9E07504-BA0A-11D1-B137-0000F8753F5D}
' SeriesMarker object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcSeriesMarker_INTERFACE_DEFINED)
    %MSChartIVcSeriesMarker_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcSeriesMarker $IID_MSChartIVcSeriesMarker

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Auto <1> ( _                            ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Automatic
   ' =====================================================================================
   PROPERTY SET Auto <1> ( _                            ' VTable offset = 32
     BYVAL Automatic AS INTEGER _                       ' __in VARIANT_BOOL Automatic
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Show <2> ( _                            ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Show
   ' =====================================================================================
   PROPERTY SET Show <2> ( _                            ' VTable offset = 40
     BYVAL Show AS INTEGER _                            ' __in VARIANT_BOOL Show
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcSeriesMarker_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcStatLine
' IID = {E9E07506-BA0A-11D1-B137-0000F8753F5D}
' StatLine object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcStatLine_INTERFACE_DEFINED)
    %MSChartIVcStatLine_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcStatLine $IID_MSChartIVcStatLine

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Flag <1> ( _                            ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out short* Flag
   ' =====================================================================================
   PROPERTY SET Flag <1> ( _                            ' VTable offset = 32
     BYVAL Flag AS INTEGER _                            ' __in short Flag
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VtColor <2> ( _                         ' VTable offset = 36
   ) AS MSChartIVcColor                                 ' __retval_out IVcColor** VtColor
   ' =====================================================================================
   PROPERTY GET Width <3> ( _                           ' VTable offset = 40
   ) AS SINGLE                                          ' __retval_out float* Width
   ' =====================================================================================
   PROPERTY SET Width <3> ( _                           ' VTable offset = 44
     BYVAL Width AS SINGLE _                            ' __in float Width
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Style <4> ( _                           ' VTable offset = 48
     BYVAL type AS LONG _                               ' __in VtChStats type
   ) AS LONG                                            ' __retval_out VtPenStyle* Style
   ' =====================================================================================
   PROPERTY SET Style <4> ( _                           ' VTable offset = 52
     BYVAL type AS LONG _                               ' __in VtChStats type
   , BYVAL Style AS LONG _                              ' __in VtPenStyle Style
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcStatLine_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcLabel
' IID = {E9E07508-BA0A-11D1-B137-0000F8753F5D}
' Label object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcLabel_INTERFACE_DEFINED)
    %MSChartIVcLabel_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcLabel $IID_MSChartIVcLabel

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Backdrop <1> ( _                        ' VTable offset = 28
   ) AS MSChartIVcBackdrop                              ' __retval_out IVcBackdrop** Backdrop
   ' =====================================================================================
   PROPERTY GET Format <2> ( _                          ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* Format
   ' =====================================================================================
   PROPERTY SET Format <2> ( _                          ' VTable offset = 36
     BYVAL Format AS WSTRING _                          ' __in BSTR Format
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VtFont <3> ( _                          ' VTable offset = 40
   ) AS MSChartIVcFont                                  ' __retval_out IVcFont** VtFont
   ' =====================================================================================
   PROPERTY GET Auto <4> ( _                            ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Automatic
   ' =====================================================================================
   PROPERTY SET Auto <4> ( _                            ' VTable offset = 48
     BYVAL Automatic AS INTEGER _                       ' __in VARIANT_BOOL Automatic
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Standing <5> ( _                        ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Standing
   ' =====================================================================================
   PROPERTY SET Standing <5> ( _                        ' VTable offset = 56
     BYVAL Standing AS INTEGER _                        ' __in VARIANT_BOOL Standing
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TextLayout <6> ( _                      ' VTable offset = 60
   ) AS MSChartIVcTextLayout                            ' __retval_out IVcTextLayout** TextLayout
   ' =====================================================================================
   PROPERTY GET FormatLength <7> ( _                    ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out short* FormatLength
   ' =====================================================================================
   PROPERTY SET putref_Font <8> ( _                     ' VTable offset = 68
     BYVAL Font AS IFontDisp _                          ' __in IFontDisp *Font
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font <8> ( _                            ' VTable offset = 72
   ) AS IFontDisp                                       ' __retval_out IFontDisp** Font
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcLabel_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcLabels
' IID = {E9E0750A-BA0A-11D1-B137-0000F8753F5D}
' Labels Collection
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcLabels_INTERFACE_DEFINED)
    %MSChartIVcLabels_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcLabels $IID_MSChartIVcLabels

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown** ppEnum
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* Count
   ' =====================================================================================
   PROPERTY GET Item_ <2> ( _                           ' VTable offset = 36
     BYVAL LabelIndex AS INTEGER _                      ' __in short LabelIndex
   ) AS MSChartIVcLabel                                 ' __retval_out IVcLabel** _Item
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 40
     BYVAL LabelIndex AS INTEGER _                      ' __in short LabelIndex
   ) AS MSChartIVcLabel                                 ' __retval_out IVcLabel** Item
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcLabels_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcDataPointLabel
' IID = {E9E0750C-BA0A-11D1-B137-0000F8753F5D}
' DataPointLabel object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcDataPointLabel_INTERFACE_DEFINED)
    %MSChartIVcDataPointLabel_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcDataPointLabel $IID_MSChartIVcDataPointLabel

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Text_ <0> ( _                           ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *_Text
   ' =====================================================================================
   PROPERTY SET Text_ <0> ( _                           ' VTable offset = 32
     BYVAL Text AS WSTRING _                            ' __in BSTR _Text
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Text <1> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* Text
   ' =====================================================================================
   PROPERTY SET Text <1> ( _                            ' VTable offset = 40
     BYVAL Text AS WSTRING _                            ' __in BSTR Text
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Backdrop <2> ( _                        ' VTable offset = 44
   ) AS MSChartIVcBackdrop                              ' __retval_out IVcBackdrop** Backdrop
   ' =====================================================================================
   PROPERTY GET VtFont <3> ( _                          ' VTable offset = 48
   ) AS MSChartIVcFont                                  ' __retval_out IVcFont** VtFont
   ' =====================================================================================
   PROPERTY GET Offset <4> ( _                          ' VTable offset = 52
   ) AS MSChartIVcLCoor                                 ' __retval_out IVcLCoor** Offset
   ' =====================================================================================
   PROPERTY GET TextLayout <5> ( _                      ' VTable offset = 56
   ) AS MSChartIVcTextLayout                            ' __retval_out IVcTextLayout** TextLayout
   ' =====================================================================================
   PROPERTY GET LocationType <6> ( _                    ' VTable offset = 60
   ) AS LONG                                            ' __retval_out VtChLabelLocationType* LocationType
   ' =====================================================================================
   PROPERTY SET LocationType <6> ( _                    ' VTable offset = 64
     BYVAL LocationType AS LONG _                       ' __in VtChLabelLocationType LocationType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Custom <7> ( _                          ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Custom
   ' =====================================================================================
   PROPERTY SET Custom <7> ( _                          ' VTable offset = 72
     BYVAL Custom AS INTEGER _                          ' __in VARIANT_BOOL Custom
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Component <8> ( _                       ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out short* Component
   ' =====================================================================================
   PROPERTY SET Component <8> ( _                       ' VTable offset = 80
     BYVAL Component AS INTEGER _                       ' __in short Component
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LineStyle <9> ( _                       ' VTable offset = 84
   ) AS LONG                                            ' __retval_out VtChLabelLineStyle* LineStyle
   ' =====================================================================================
   PROPERTY SET LineStyle <9> ( _                       ' VTable offset = 88
     BYVAL LineStyle AS LONG _                          ' __in VtChLabelLineStyle LineStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ValueFormat <10> ( _                    ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR* ValueFormat
   ' =====================================================================================
   PROPERTY SET ValueFormat <10> ( _                    ' VTable offset = 96
     BYVAL ValueFormat AS WSTRING _                     ' __in BSTR ValueFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PercentFormat <11> ( _                  ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR* PercentFormat
   ' =====================================================================================
   PROPERTY SET PercentFormat <11> ( _                  ' VTable offset = 104
     BYVAL PercentFormat AS WSTRING _                   ' __in BSTR PercentFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TextLength <12> ( _                     ' VTable offset = 108
   ) AS INTEGER                                         ' __retval_out short* TextLength
   ' =====================================================================================
   PROPERTY SET putref_Font <15> ( _                    ' VTable offset = 112
     BYVAL Font AS IFontDisp _                          ' __in IFontDisp* Font
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font <15> ( _                           ' VTable offset = 116
   ) AS IFontDisp                                       ' __retval_out IFontDisp** Font
   ' =====================================================================================
   METHOD ResetCustomLabel <13> ( _                     ' VTable offset = 120
   )                                                    ' void
   ' =====================================================================================
   METHOD Select <14> ( _                               ' VTable offset = 124
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcDataPointLabel_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcDataPoint
' IID = {E9E0750E-BA0A-11D1-B137-0000F8753F5D}
' DataPoint object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcDataPoint_INTERFACE_DEFINED)
    %MSChartIVcDataPoint_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcDataPoint $IID_MSChartIVcDataPoint

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DataPointLabel <1> ( _                  ' VTable offset = 28
   ) AS MSChartIVcDataPointLabel                        ' __retval_out IVcDataPointLabel** DataPointLabel
   ' =====================================================================================
   PROPERTY GET Brush <2> ( _                           ' VTable offset = 32
   ) AS MSChartIVcBrush                                 ' __retval_out IVcBrush** Brush
   ' =====================================================================================
   PROPERTY GET EdgePen <3> ( _                         ' VTable offset = 36
   ) AS MSChartIVcPen                                   ' __retval_out IVcPen** EdgePen
   ' =====================================================================================
   PROPERTY GET Marker <4> ( _                          ' VTable offset = 40
   ) AS MSChartIVcMarker                                ' __retval_out IVcMarker** Marker
   ' =====================================================================================
   PROPERTY GET Offset <5> ( _                          ' VTable offset = 44
   ) AS SINGLE                                          ' __retval_out float* Offset
   ' =====================================================================================
   PROPERTY SET Offset <5> ( _                          ' VTable offset = 48
     BYVAL Offset AS SINGLE _                           ' __in float Offset
   )                                                    ' void
   ' =====================================================================================
   METHOD ResetCustom <7> ( _                           ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD Select <8> ( _                                ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcDataPoint_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcDataPoints
' IID = {E9E0752A-BA0A-11D1-B137-0000F8753F5D}
' DataPoints Collection
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcDataPoints_INTERFACE_DEFINED)
    %MSChartIVcDataPoints_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcDataPoints $IID_MSChartIVcDataPoints

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown** ppEnum
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* Count
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 36
     BYVAL Index AS INTEGER _                           ' __in short Index
   ) AS MSChartIVcDataPoint                             ' __retval_out IVcDataPoint** Item
   ' =====================================================================================
   PROPERTY GET Item_ <2> ( _                           ' VTable offset = 40
     BYVAL Index AS INTEGER _                           ' __in short Index
   ) AS MSChartIVcDataPoint                             ' __retval_out IVcDataPoint** Item
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcDataPoints_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcSeries
' IID = {E9E07511-BA0A-11D1-B137-0000F8753F5D}
' Series object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcSeries_INTERFACE_DEFINED)
    %MSChartIVcSeries_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcSeries $IID_MSChartIVcSeries

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET LegendText_ <0> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *_LegendText
   ' =====================================================================================
   PROPERTY SET LegendText_ <0> ( _                     ' VTable offset = 32
     BYVAL LegendText AS WSTRING _                      ' __in BSTR _LegendText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SecondaryAxis <1> ( _                   ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* SecondaryAxis
   ' =====================================================================================
   PROPERTY SET SecondaryAxis <1> ( _                   ' VTable offset = 40
     BYVAL SecondaryAxis AS INTEGER _                   ' __in VARIANT_BOOL SecondaryAxis
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SeriesType <4> ( _                      ' VTable offset = 44
   ) AS LONG                                            ' __retval_out VtChSeriesType* SeriesType
   ' =====================================================================================
   PROPERTY SET SeriesType <4> ( _                      ' VTable offset = 48
     BYVAL SeriesType AS LONG _                         ' __in VtChSeriesType SeriesType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GuideLinePen <5> ( _                    ' VTable offset = 52
   ) AS MSChartIVcPen                                   ' __retval_out IVcPen** GuideLinePen
   ' =====================================================================================
   PROPERTY GET ShowLine <6> ( _                        ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* ShowLine
   ' =====================================================================================
   PROPERTY SET ShowLine <6> ( _                        ' VTable offset = 60
     BYVAL ShowLine AS INTEGER _                        ' __in VARIANT_BOOL ShowLine
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Pen <7> ( _                             ' VTable offset = 64
   ) AS MSChartIVcPen                                   ' __retval_out IVcPen** Pen
   ' =====================================================================================
   PROPERTY GET Position <10> ( _                       ' VTable offset = 68
   ) AS MSChartIVcSeriesPosition                        ' __retval_out IVcSeriesPosition** Position
   ' =====================================================================================
   PROPERTY GET SeriesMarker <11> ( _                   ' VTable offset = 72
   ) AS MSChartIVcSeriesMarker                          ' __retval_out IVcSeriesMarker** SeriesMarker
   ' =====================================================================================
   PROPERTY GET StatLine <13> ( _                       ' VTable offset = 76
   ) AS MSChartIVcStatLine                              ' __retval_out IVcStatLine** StatLine
   ' =====================================================================================
   PROPERTY GET DataPoints <14> ( _                     ' VTable offset = 80
   ) AS MSChartIVcDataPoints                            ' __retval_out IVcDataPoints** DataPoints
   ' =====================================================================================
   PROPERTY GET LegendText <15> ( _                     ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR* LegendText
   ' =====================================================================================
   PROPERTY SET LegendText <15> ( _                     ' VTable offset = 88
     BYVAL LegendText AS WSTRING _                      ' __in BSTR LegendText
   )                                                    ' void
   ' =====================================================================================
   METHOD Select <16> ( _                               ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowGuideLine <17> ( _                  ' VTable offset = 96
     BYVAL axisID AS LONG _                             ' __in VtChAxisId axisID
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* ShowGuideLine
   ' =====================================================================================
   PROPERTY SET ShowGuideLine <17> ( _                  ' VTable offset = 100
     BYVAL axisID AS LONG _                             ' __in VtChAxisId axisID
   , BYVAL ShowGuideLine AS INTEGER _                   ' __in VARIANT_BOOL ShowGuideLine
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TypeByChartType <18> ( _                ' VTable offset = 104
     BYVAL chartType AS LONG _                          ' __in VtChChartType chartType
   ) AS LONG                                            ' __retval_out VtChSeriesType* SeriesType
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcSeries_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcSeriesCollection
' IID = {E9E07513-BA0A-11D1-B137-0000F8753F5D}
' SeriesCollection Collection
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcSeriesCollection_INTERFACE_DEFINED)
    %MSChartIVcSeriesCollection_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcSeriesCollection $IID_MSChartIVcSeriesCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown** ppEnum
   ' =====================================================================================
   METHOD Count <1> ( _                                 ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* Count
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 36
     BYVAL Index AS INTEGER _                           ' __in short Index
   ) AS MSChartIVcSeries                                ' __retval_out IVcSeries** Item
   ' =====================================================================================
   PROPERTY GET Item_ <2> ( _                           ' VTable offset = 40
     BYVAL Index AS INTEGER _                           ' __in short Index
   ) AS MSChartIVcSeries                                ' __retval_out IVcSeries** _Item
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcSeriesCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcAxisTitle
' IID = {E9E07515-BA0A-11D1-B137-0000F8753F5D}
' AxisTitle object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcAxisTitle_INTERFACE_DEFINED)
    %MSChartIVcAxisTitle_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcAxisTitle $IID_MSChartIVcAxisTitle

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Text_ <0> ( _                           ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* Text
   ' =====================================================================================
   PROPERTY SET Text_ <0> ( _                           ' VTable offset = 32
     BYVAL Text AS WSTRING _                            ' __in BSTR Text
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Text <1> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* Text
   ' =====================================================================================
   PROPERTY SET Text <1> ( _                            ' VTable offset = 40
     BYVAL Text AS WSTRING _                            ' __in BSTR Text
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Backdrop <2> ( _                        ' VTable offset = 44
   ) AS MSChartIVcBackdrop                              ' __retval_out IVcBackdrop** Backdrop
   ' =====================================================================================
   PROPERTY GET VtFont <3> ( _                          ' VTable offset = 48
   ) AS MSChartIVcFont                                  ' __retval_out IVcFont** VtFont
   ' =====================================================================================
   PROPERTY GET Visible <4> ( _                         ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Visible
   ' =====================================================================================
   PROPERTY SET Visible <4> ( _                         ' VTable offset = 56
     BYVAL Visible AS INTEGER _                         ' __in VARIANT_BOOL Visible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TextLayout <5> ( _                      ' VTable offset = 60
   ) AS MSChartIVcTextLayout                            ' __retval_out IVcTextLayout** TextLayout
   ' =====================================================================================
   PROPERTY GET TextLength <6> ( _                      ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out short* TextLength
   ' =====================================================================================
   PROPERTY SET putref_Font <7> ( _                     ' VTable offset = 68
     BYVAL Font AS IFontDisp _                          ' __in IFontDisp* Font
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font <7> ( _                            ' VTable offset = 72
   ) AS IFontDisp                                       ' __retval_out IFontDisp** Font
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcAxisTitle_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcCategoryScale
' IID = {E9E07517-BA0A-11D1-B137-0000F8753F5D}
' CategoryScale object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcCategoryScale_INTERFACE_DEFINED)
    %MSChartIVcCategoryScale_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcCategoryScale $IID_MSChartIVcCategoryScale

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Auto <1> ( _                            ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Automatic
   ' =====================================================================================
   PROPERTY SET Auto <1> ( _                            ' VTable offset = 32
     BYVAL Automatic AS INTEGER _                       ' __in VARIANT_BOOL Automatic
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DivisionsPerLabel <2> ( _               ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out short* DivisionsPerLabel
   ' =====================================================================================
   PROPERTY SET DivisionsPerLabel <2> ( _               ' VTable offset = 40
     BYVAL DivisionsPerLabel AS INTEGER _               ' __in short DivisionsPerLabel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DivisionsPerTick <3> ( _                ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out short* DivisionsPerTick
   ' =====================================================================================
   PROPERTY SET DivisionsPerTick <3> ( _                ' VTable offset = 48
     BYVAL DivisionsPerTick AS INTEGER _                ' __in short DivisionsPerTick
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LabelTick <4> ( _                       ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* LabelTick
   ' =====================================================================================
   PROPERTY SET LabelTick <4> ( _                       ' VTable offset = 56
     BYVAL LabelTick AS INTEGER _                       ' __in VARIANT_BOOL LabelTick
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcCategoryScale_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcAxisGrid
' IID = {E9E0751B-BA0A-11D1-B137-0000F8753F5D}
' AxisGrid object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcAxisGrid_INTERFACE_DEFINED)
    %MSChartIVcAxisGrid_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcAxisGrid $IID_MSChartIVcAxisGrid

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET MinorPen <1> ( _                        ' VTable offset = 28
   ) AS MSChartIVcPen                                   ' __retval_out VARIANT_BOOL** MinorPen
   ' =====================================================================================
   PROPERTY GET MajorPen <2> ( _                        ' VTable offset = 32
   ) AS MSChartIVcPen                                   ' __retval_out IVcPen** MajorPen
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcAxisGrid_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcIntersection
' IID = {E9E0751D-BA0A-11D1-B137-0000F8753F5D}
' Intersection object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcIntersection_INTERFACE_DEFINED)
    %MSChartIVcIntersection_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcIntersection $IID_MSChartIVcIntersection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Auto <1> ( _                            ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Automatic
   ' =====================================================================================
   PROPERTY SET Auto <1> ( _                            ' VTable offset = 32
     BYVAL Automatic AS INTEGER _                       ' __in VARIANT_BOOL Automatic
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Point <2> ( _                           ' VTable offset = 36
   ) AS DOUBLE                                          ' __retval_out double* Point
   ' =====================================================================================
   PROPERTY SET Point <2> ( _                           ' VTable offset = 40
     BYVAL Point AS DOUBLE _                            ' __in double Point
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET axisID <3> ( _                          ' VTable offset = 44
   ) AS LONG                                            ' __retval_out VtChAxisId* axisID
   ' =====================================================================================
   PROPERTY GET Index <4> ( _                           ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out short* Index
   ' =====================================================================================
   PROPERTY GET LabelsInsidePlot <5> ( _                ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* LabelsInsidePlot
   ' =====================================================================================
   PROPERTY SET LabelsInsidePlot <5> ( _                ' VTable offset = 56
     BYVAL LabelsInsidePlot AS INTEGER _                ' __in VARIANT_BOOL LabelsInsidePlot
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcIntersection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcTick
' IID = {E9E0751F-BA0A-11D1-B137-0000F8753F5D}
' Tick object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcTick_INTERFACE_DEFINED)
    %MSChartIVcTick_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcTick $IID_MSChartIVcTick

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Length <1> ( _                          ' VTable offset = 28
   ) AS SINGLE                                          ' __retval_out float* Length
   ' =====================================================================================
   PROPERTY SET Length <1> ( _                          ' VTable offset = 32
     BYVAL Length AS SINGLE _                           ' __in float Length
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Style <2> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out VtChAxisTickStyle* Style
   ' =====================================================================================
   PROPERTY SET Style <2> ( _                           ' VTable offset = 40
     BYVAL Style AS LONG _                              ' __in VtChAxisTickStyle Style
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcTick_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcAxisScale
' IID = {E9E07521-BA0A-11D1-B137-0000F8753F5D}
' AxisScale object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcAxisScale_INTERFACE_DEFINED)
    %MSChartIVcAxisScale_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcAxisScale $IID_MSChartIVcAxisScale

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Hide <1> ( _                            ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Hide
   ' =====================================================================================
   PROPERTY SET Hide <1> ( _                            ' VTable offset = 32
     BYVAL Hide AS INTEGER _                            ' __in VARIANT_BOOL Hide
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET type <2> ( _                            ' VTable offset = 36
   ) AS LONG                                            ' __retval_out VtChScaleType* type
   ' =====================================================================================
   PROPERTY SET type <2> ( _                            ' VTable offset = 40
     BYVAL type AS LONG _                               ' __in VtChScaleType type
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LogBase <3> ( _                         ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out short* LogBase
   ' =====================================================================================
   PROPERTY SET LogBase <3> ( _                         ' VTable offset = 48
     BYVAL LogBase AS INTEGER _                         ' __in short LogBase
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PercentBasis <4> ( _                    ' VTable offset = 52
   ) AS LONG                                            ' __retval_out VtChPercentAxisBasis* PercentBasis
   ' =====================================================================================
   PROPERTY SET PercentBasis <4> ( _                    ' VTable offset = 56
     BYVAL PercentBasis AS LONG _                       ' __in VtChPercentAxisBasis PercentBasis
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcAxisScale_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcValueScale
' IID = {E9E07523-BA0A-11D1-B137-0000F8753F5D}
' ValueScale object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcValueScale_INTERFACE_DEFINED)
    %MSChartIVcValueScale_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcValueScale $IID_MSChartIVcValueScale

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Auto <1> ( _                            ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Automatic
   ' =====================================================================================
   PROPERTY SET Auto <1> ( _                            ' VTable offset = 32
     BYVAL Automatic AS INTEGER _                       ' __in VARIANT_BOOL Automatic
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Minimum <2> ( _                         ' VTable offset = 36
   ) AS DOUBLE                                          ' __retval_out double* Minimum
   ' =====================================================================================
   PROPERTY SET Minimum <2> ( _                         ' VTable offset = 40
     BYVAL Minimum AS DOUBLE _                          ' __in double Minimum
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Maximum <3> ( _                         ' VTable offset = 44
   ) AS DOUBLE                                          ' __retval_out double* Maximum
   ' =====================================================================================
   PROPERTY SET Maximum <3> ( _                         ' VTable offset = 48
     BYVAL Maximum AS DOUBLE _                          ' __in double Maximum
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MajorDivision <4> ( _                   ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out short* MajorDivision
   ' =====================================================================================
   PROPERTY SET MajorDivision <4> ( _                   ' VTable offset = 56
     BYVAL MajorDivision AS INTEGER _                   ' __in short MajorDivision
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MinorDivision <5> ( _                   ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out short* MinorDivision
   ' =====================================================================================
   PROPERTY SET MinorDivision <5> ( _                   ' VTable offset = 64
     BYVAL MinorDivision AS INTEGER _                   ' __in short MinorDivision
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcValueScale_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcAxis
' IID = {E9E07525-BA0A-11D1-B137-0000F8753F5D}
' Axis(axisId, 1) object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcAxis_INTERFACE_DEFINED)
    %MSChartIVcAxis_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcAxis $IID_MSChartIVcAxis

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Pen <1> ( _                             ' VTable offset = 28
   ) AS MSChartIVcPen                                   ' __retval_out IVcPen** Pen
   ' =====================================================================================
   PROPERTY GET LabelLevelCount <2> ( _                 ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out short* LabelLevelCount
   ' =====================================================================================
   PROPERTY GET CategoryScale <3> ( _                   ' VTable offset = 36
   ) AS MSChartIVcCategoryScale                         ' __retval_out IVcCategoryScale** CategoryScale
   ' =====================================================================================
   PROPERTY GET AxisGrid <5> ( _                        ' VTable offset = 40
   ) AS MSChartIVcAxisGrid                              ' __retval_out IVcAxisGrid** AxisGrid
   ' =====================================================================================
   PROPERTY GET Intersection <6> ( _                    ' VTable offset = 44
   ) AS MSChartIVcIntersection                          ' __retval_out IVcIntersection** Intersection
   ' =====================================================================================
   PROPERTY GET Tick <7> ( _                            ' VTable offset = 48
   ) AS MSChartIVcTick                                  ' __retval_out IVcTick** Tick
   ' =====================================================================================
   PROPERTY GET AxisScale <8> ( _                       ' VTable offset = 52
   ) AS MSChartIVcAxisScale                             ' __retval_out IVcAxisScale** AxisScale
   ' =====================================================================================
   PROPERTY GET ValueScale <9> ( _                      ' VTable offset = 56
   ) AS MSChartIVcValueScale                            ' __retval_out IVcValueScale** ValueScale
   ' =====================================================================================
   PROPERTY GET AxisTitle <10> ( _                      ' VTable offset = 60
   ) AS MSChartIVcAxisTitle                             ' __retval_out IVcAxisTitle** AxisTitle
   ' =====================================================================================
   PROPERTY GET Labels <11> ( _                         ' VTable offset = 64
   ) AS MSChartIVcLabels                                ' __retval_out IVcLabels** Labels
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcAxis_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVcPlot
' IID = {E9E07527-BA0A-11D1-B137-0000F8753F5D}
' Plot object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartIVcPlot_INTERFACE_DEFINED)
    %MSChartIVcPlot_INTERFACE_DEFINED = 1

INTERFACE MSChartIVcPlot $IID_MSChartIVcPlot

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET AngleUnit <1> ( _                       ' VTable offset = 28
   ) AS LONG                                            ' __retval_out VtAngleUnits* AngleUnit
   ' =====================================================================================
   PROPERTY SET AngleUnit <1> ( _                       ' VTable offset = 32
     BYVAL AngleUnit AS LONG _                          ' __in VtAngleUnits AngleUnit
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Clockwise <2> ( _                       ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Clockwise
   ' =====================================================================================
   PROPERTY SET Clockwise <2> ( _                       ' VTable offset = 40
     BYVAL Clockwise AS INTEGER _                       ' __in VARIANT_BOOL Clockwise
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Sort <3> ( _                            ' VTable offset = 44
   ) AS LONG                                            ' __retval_out VtSortType* Sort
   ' =====================================================================================
   PROPERTY SET Sort <3> ( _                            ' VTable offset = 48
     BYVAL Sort AS LONG _                               ' __in VtSortType Sort
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Backdrop <5> ( _                        ' VTable offset = 52
   ) AS MSChartIVcBackdrop                              ' __retval_out IVcBackdrop** Backdrop
   ' =====================================================================================
   PROPERTY GET StartingAngle <8> ( _                   ' VTable offset = 56
   ) AS SINGLE                                          ' __retval_out float* StartingAngle
   ' =====================================================================================
   PROPERTY SET StartingAngle <8> ( _                   ' VTable offset = 60
     BYVAL StartingAngle AS SINGLE _                    ' __in float StartingAngle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubPlotLabelPosition <9> ( _            ' VTable offset = 64
   ) AS LONG                                            ' __retval_out VtChSubPlotLabelLocationType* SubPlotLabelPosition
   ' =====================================================================================
   PROPERTY SET SubPlotLabelPosition <9> ( _            ' VTable offset = 68
     BYVAL SubPlotLabelPosition AS LONG _               ' __in VtChSubPlotLabelLocationType SubPlotLabelPosition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BarGap <10> ( _                         ' VTable offset = 72
   ) AS SINGLE                                          ' __retval_out float* BarGap
   ' =====================================================================================
   PROPERTY SET BarGap <10> ( _                         ' VTable offset = 76
     BYVAL BarGap AS SINGLE _                           ' __in float BarGap
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET xGap <11> ( _                           ' VTable offset = 80
   ) AS SINGLE                                          ' __retval_out float* xGap
   ' =====================================================================================
   PROPERTY SET xGap <11> ( _                           ' VTable offset = 84
     BYVAL xGap AS SINGLE _                             ' __in float xGap
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoLayout <12> ( _                     ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* AutoLayout
   ' =====================================================================================
   PROPERTY SET AutoLayout <12> ( _                     ' VTable offset = 92
     BYVAL AutoLayout AS INTEGER _                      ' __in VARIANT_BOOL AutoLayout
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WidthToHeightRatio <13> ( _             ' VTable offset = 96
   ) AS SINGLE                                          ' __retval_out float* WidthToHeightRatio
   ' =====================================================================================
   PROPERTY SET WidthToHeightRatio <13> ( _             ' VTable offset = 100
     BYVAL WidthToHeightRatio AS SINGLE _               ' __in float WidthToHeightRatio
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DepthToHeightRatio <14> ( _             ' VTable offset = 104
   ) AS SINGLE                                          ' __retval_out float* DepthToHeightRatio
   ' =====================================================================================
   PROPERTY SET DepthToHeightRatio <14> ( _             ' VTable offset = 108
     BYVAL DepthToHeightRatio AS SINGLE _               ' __in float DepthToHeightRatio
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LocationRect <15> ( _                   ' VTable offset = 112
   ) AS MSChartIVcRect                                  ' __retval_out IVcRect** LocationRect
   ' =====================================================================================
   PROPERTY GET Projection <16> ( _                     ' VTable offset = 116
   ) AS LONG                                            ' __retval_out VtProjectionType* Projection
   ' =====================================================================================
   PROPERTY SET Projection <16> ( _                     ' VTable offset = 120
     BYVAL Projection AS LONG _                         ' __in VtProjectionType Projection
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET zGap <17> ( _                           ' VTable offset = 124
   ) AS SINGLE                                          ' __retval_out float* zGap
   ' =====================================================================================
   PROPERTY SET zGap <17> ( _                           ' VTable offset = 128
     BYVAL zGap AS SINGLE _                             ' __in float zGap
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET View3d <18> ( _                         ' VTable offset = 132
   ) AS MSChartIVcView3d                                ' __retval_out IVcView3d** View3d
   ' =====================================================================================
   PROPERTY GET PlotBase <19> ( _                       ' VTable offset = 136
   ) AS MSChartIVcPlotBase                              ' __retval_out IVcPlotBase** PlotBase
   ' =====================================================================================
   PROPERTY GET Weighting <22> ( _                      ' VTable offset = 140
   ) AS MSChartIVcWeighting                             ' __retval_out IVcWeighting** Weighting
   ' =====================================================================================
   PROPERTY GET Wall <23> ( _                           ' VTable offset = 144
   ) AS MSChartIVcWall                                  ' __retval_out IVcWall** Wall
   ' =====================================================================================
   PROPERTY GET SeriesCollection <25> ( _               ' VTable offset = 148
   ) AS MSChartIVcSeriesCollection                      ' __retval_out IVcSeriesCollection** SeriesCollection
   ' =====================================================================================
   PROPERTY GET DataSeriesInRow <26> ( _                ' VTable offset = 152
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* DataSeriesInRow
   ' =====================================================================================
   PROPERTY SET DataSeriesInRow <26> ( _                ' VTable offset = 156
     BYVAL DataSeriesInRow AS INTEGER _                 ' __in VARIANT_BOOL DataSeriesInRow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Light <27> ( _                          ' VTable offset = 160
   ) AS MSChartIVcLight                                 ' __retval_out IVcLight** Light
   ' =====================================================================================
   PROPERTY GET DefaultPercentBasis <29> ( _            ' VTable offset = 164
   ) AS LONG                                            ' __retval_out VtChPercentAxisBasis* DefaultPercentBasis
   ' =====================================================================================
   PROPERTY GET UniformAxis <30> ( _                    ' VTable offset = 168
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* UniformAxis
   ' =====================================================================================
   PROPERTY SET UniformAxis <30> ( _                    ' VTable offset = 172
     BYVAL UniformAxis AS INTEGER _                     ' __in VARIANT_BOOL UniformAxis
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Axis <31> ( _                           ' VTable offset = 176
     BYVAL axisID AS LONG _                             ' __in VtChAxisId axisID
   , OPTIONAL BYVAL Index AS VARIANT _                  ' __opt_in VARIANT Index
   ) AS MSChartIVcAxis                                  ' __retval_out IVcAxis** Axis
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartIVcPlot_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _DMSChart
' IID = {3A2B370A-BA0A-11D1-B137-0000F8753F5D}
' Chart object
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%MSChartDMSChart_INTERFACE_DEFINED)
    %MSChartDMSChart_INTERFACE_DEFINED = 1

INTERFACE MSChartDMSChart $IID__MSChartDMSChart

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET AutoIncrement <1> ( _                   ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *AutoIncrement
   ' =====================================================================================
   PROPERTY SET AutoIncrement <1> ( _                   ' VTable offset = 32
     BYVAL AutoIncrement AS INTEGER _                   ' __in VARIANT_BOOL AutoIncrement
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RandomFill <2> ( _                      ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* RandomFill
   ' =====================================================================================
   PROPERTY SET RandomFill <2> ( _                      ' VTable offset = 40
     BYVAL RandomFill AS INTEGER _                      ' __in VARIANT_BOOL RandomFill
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET chartType <3> ( _                       ' VTable offset = 44
   ) AS LONG                                            ' __retval_out VtChChartType* chartType
   ' =====================================================================================
   PROPERTY SET chartType <3> ( _                       ' VTable offset = 48
     BYVAL chartType AS LONG _                          ' __in VtChChartType chartType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Column <4> ( _                          ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out short* Column
   ' =====================================================================================
   PROPERTY SET Column <4> ( _                          ' VTable offset = 56
     BYVAL Column AS INTEGER _                          ' __in short Column
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ColumnCount <5> ( _                     ' VTable offset = 60
   ) AS INTEGER                                         ' __retval_out short* ColumnCount
   ' =====================================================================================
   PROPERTY SET ColumnCount <5> ( _                     ' VTable offset = 64
     BYVAL ColumnCount AS INTEGER _                     ' __in short ColumnCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ColumnLabel <6> ( _                     ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR* ColumnLabel
   ' =====================================================================================
   PROPERTY SET ColumnLabel <6> ( _                     ' VTable offset = 72
     BYVAL ColumnLabel AS WSTRING _                     ' __in BSTR ColumnLabel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ColumnLabelCount <7> ( _                ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out short* ColumnLabelCount
   ' =====================================================================================
   PROPERTY SET ColumnLabelCount <7> ( _                ' VTable offset = 80
     BYVAL ColumnLabelCount AS INTEGER _                ' __in short ColumnLabelCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ColumnLabelIndex <8> ( _                ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out short* ColumnLabelIndex
   ' =====================================================================================
   PROPERTY SET ColumnLabelIndex <8> ( _                ' VTable offset = 88
     BYVAL ColumnLabelIndex AS INTEGER _                ' __in short ColumnLabelIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Data <9> ( _                            ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR* Data
   ' =====================================================================================
   PROPERTY SET Data <9> ( _                            ' VTable offset = 96
     BYVAL Data AS WSTRING _                            ' __in BSTR Data
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FootnoteText <10> ( _                   ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR* FootnoteText
   ' =====================================================================================
   PROPERTY SET FootnoteText <10> ( _                   ' VTable offset = 104
     BYVAL FootnoteText AS WSTRING _                    ' __in BSTR FootnoteText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Repaint <11> ( _                        ' VTable offset = 108
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Repaint
   ' =====================================================================================
   PROPERTY SET Repaint <11> ( _                        ' VTable offset = 112
     BYVAL Repaint AS INTEGER _                         ' __in VARIANT_BOOL Repaint
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Row <12> ( _                            ' VTable offset = 116
   ) AS INTEGER                                         ' __retval_out short* Row
   ' =====================================================================================
   PROPERTY SET Row <12> ( _                            ' VTable offset = 120
     BYVAL Row AS INTEGER _                             ' __in short Row
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RowCount <13> ( _                       ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out short* RowCount
   ' =====================================================================================
   PROPERTY SET RowCount <13> ( _                       ' VTable offset = 128
     BYVAL RowCount AS INTEGER _                        ' __in short RowCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RowLabel <14> ( _                       ' VTable offset = 132
   ) AS WSTRING                                         ' __retval_out BSTR* RowLabel
   ' =====================================================================================
   PROPERTY SET RowLabel <14> ( _                       ' VTable offset = 136
     BYVAL RowLabel AS WSTRING _                        ' __in BSTR RowLabel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RowLabelCount <15> ( _                  ' VTable offset = 140
   ) AS INTEGER                                         ' __retval_out short* RowLabelCount
   ' =====================================================================================
   PROPERTY SET RowLabelCount <15> ( _                  ' VTable offset = 144
     BYVAL RowLabelCount AS INTEGER _                   ' __in short RowLabelCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RowLabelIndex <16> ( _                  ' VTable offset = 148
   ) AS INTEGER                                         ' __retval_out short* RowLabelIndex
   ' =====================================================================================
   PROPERTY SET RowLabelIndex <16> ( _                  ' VTable offset = 152
     BYVAL RowLabelIndex AS INTEGER _                   ' __in short RowLabelIndex
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SeriesColumn <17> ( _                   ' VTable offset = 156
   ) AS INTEGER                                         ' __retval_out short* SeriesColumn
   ' =====================================================================================
   PROPERTY SET SeriesColumn <17> ( _                   ' VTable offset = 160
     BYVAL SeriesColumn AS INTEGER _                    ' __in short SeriesColumn
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SeriesType <18> ( _                     ' VTable offset = 164
   ) AS LONG                                            ' __retval_out VtChSeriesType* SeriesType
   ' =====================================================================================
   PROPERTY SET SeriesType <18> ( _                     ' VTable offset = 168
     BYVAL SeriesType AS LONG _                         ' __in VtChSeriesType SeriesType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ShowLegend <19> ( _                     ' VTable offset = 172
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* ShowLegend
   ' =====================================================================================
   PROPERTY SET ShowLegend <19> ( _                     ' VTable offset = 176
     BYVAL ShowLegend AS INTEGER _                      ' __in VARIANT_BOOL ShowLegend
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DrawMode <23> ( _                       ' VTable offset = 180
   ) AS LONG                                            ' __retval_out VtChDrawMode* DrawMode
   ' =====================================================================================
   PROPERTY SET DrawMode <23> ( _                       ' VTable offset = 184
     BYVAL DrawMode AS LONG _                           ' __in VtChDrawMode DrawMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BorderStyle <-504> ( _                  ' VTable offset = 188
   ) AS LONG                                            ' __retval_out VtBorderStyle* BorderStyle
   ' =====================================================================================
   PROPERTY SET BorderStyle <-504> ( _                  ' VTable offset = 192
     BYVAL BorderStyle AS LONG _                        ' __in VtBorderStyle BorderStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Enabled <-514> ( _                      ' VTable offset = 196
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Enabled
   ' =====================================================================================
   PROPERTY SET Enabled <-514> ( _                      ' VTable offset = 200
     BYVAL Enabled AS INTEGER _                         ' __in VARIANT_BOOL Enabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET hWnd <-515> ( _                         ' VTable offset = 204
   ) AS LONG                                            ' __retval_out long* hWnd
   ' =====================================================================================
   PROPERTY GET Title <26> ( _                          ' VTable offset = 208
   ) AS MSChartIVcTitle                                 ' __retval_out IVcTitle** Title
   ' =====================================================================================
   PROPERTY GET Footnote <27> ( _                       ' VTable offset = 212
   ) AS MSChartIVcFootnote                              ' __retval_out IVcFootnote** Footnote
   ' =====================================================================================
   PROPERTY GET TitleText <28> ( _                      ' VTable offset = 216
   ) AS WSTRING                                         ' __retval_out BSTR* TitleText
   ' =====================================================================================
   PROPERTY SET TitleText <28> ( _                      ' VTable offset = 220
     BYVAL TitleText AS WSTRING _                       ' __in BSTR TitleText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Stacking <29> ( _                       ' VTable offset = 224
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Stacking
   ' =====================================================================================
   PROPERTY SET Stacking <29> ( _                       ' VTable offset = 228
     BYVAL Stacking AS INTEGER _                        ' __in VARIANT_BOOL Stacking
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TextLengthType <30> ( _                 ' VTable offset = 232
   ) AS LONG                                            ' __retval_out VtTextLengthType* TextLengthType
   ' =====================================================================================
   PROPERTY SET TextLengthType <30> ( _                 ' VTable offset = 236
     BYVAL TextLengthType AS LONG _                     ' __in VtTextLengthType TextLengthType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowSelections <32> ( _                ' VTable offset = 240
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* AllowSelections
   ' =====================================================================================
   PROPERTY SET AllowSelections <32> ( _                ' VTable offset = 244
     BYVAL AllowSelections AS INTEGER _                 ' __in VARIANT_BOOL AllowSelections
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowSeriesSelection <33> ( _           ' VTable offset = 248
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* AllowSeriesSelection
   ' =====================================================================================
   PROPERTY SET AllowSeriesSelection <33> ( _           ' VTable offset = 252
     BYVAL AllowSeriesSelection AS INTEGER _            ' __in VARIANT_BOOL AllowSeriesSelection
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowDynamicRotation <34> ( _           ' VTable offset = 256
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* AllowDynamicRotation
   ' =====================================================================================
   PROPERTY SET AllowDynamicRotation <34> ( _           ' VTable offset = 260
     BYVAL AllowDynamicRotation AS INTEGER _            ' __in VARIANT_BOOL AllowDynamicRotation
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ActiveSeriesCount <35> ( _              ' VTable offset = 264
   ) AS INTEGER                                         ' __retval_out short* ActiveSeriesCount
   ' =====================================================================================
   PROPERTY GET Backdrop <36> ( _                       ' VTable offset = 268
   ) AS MSChartIVcBackdrop                              ' __retval_out IVcBackdrop** Backdrop
   ' =====================================================================================
   PROPERTY GET Legend <38> ( _                         ' VTable offset = 272
   ) AS MSChartIVcLegend                                ' __retval_out IVcLegend** Legend
   ' =====================================================================================
   PROPERTY GET DataGrid <39> ( _                       ' VTable offset = 276
   ) AS MSChartIVcDataGrid                              ' __retval_out IVcDataGrid** DataGrid
   ' =====================================================================================
   PROPERTY GET Plot <40> ( _                           ' VTable offset = 280
   ) AS MSChartIVcPlot                                  ' __retval_out IVcPlot** Plot
   ' =====================================================================================
   PROPERTY GET AllowDithering <43> ( _                 ' VTable offset = 284
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* AllowDithering
   ' =====================================================================================
   PROPERTY SET AllowDithering <43> ( _                 ' VTable offset = 288
     BYVAL AllowDithering AS INTEGER _                  ' __in VARIANT_BOOL AllowDithering
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DoSetCursor <45> ( _                    ' VTable offset = 292
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* DoSetCursor
   ' =====================================================================================
   PROPERTY SET DoSetCursor <45> ( _                    ' VTable offset = 296
     BYVAL DoSetCursor AS INTEGER _                     ' __in VARIANT_BOOL DoSetCursor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Chart3d <47> ( _                        ' VTable offset = 300
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* Chart3d
   ' =====================================================================================
   PROPERTY GET ChartData <0> ( _                       ' VTable offset = 304
   ) AS VARIANT                                         ' __retval_out VARIANT* Array
   ' =====================================================================================
   PROPERTY SET ChartData <0> ( _                       ' VTable offset = 308
     BYVAL Array AS VARIANT _                           ' __in VARIANT Array
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Chart <72> ( _                          ' VTable offset = 312
   ) AS LONG                                            ' __retval_out long* pChart
   ' =====================================================================================
   PROPERTY GET MousePointer <74> ( _                   ' VTable offset = 316
   ) AS LONG                                            ' __retval_out VtMousePointer* MousePointer
   ' =====================================================================================
   PROPERTY SET MousePointer <74> ( _                   ' VTable offset = 320
     BYVAL MousePointer AS LONG _                       ' __in VtMousePointer MousePointer
   )                                                    ' void
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 324
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <-550> ( _                            ' VTable offset = 328
   )                                                    ' void
   ' =====================================================================================
   METHOD EditPaste <49> ( _                            ' VTable offset = 332
   )                                                    ' void
   ' =====================================================================================
   METHOD EditCopy <50> ( _                             ' VTable offset = 336
   )                                                    ' void
   ' =====================================================================================
   METHOD Layout <52> ( _                               ' VTable offset = 340
   )                                                    ' void
   ' =====================================================================================
   METHOD ToDefaults <53> ( _                           ' VTable offset = 344
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectPart <56> ( _                           ' VTable offset = 348
     BYVAL part AS INTEGER _                            ' __in short part
   , BYVAL index1 AS INTEGER _                          ' __in short index1
   , BYVAL index2 AS INTEGER _                          ' __in short index2
   , BYVAL index3 AS INTEGER _                          ' __in short index3
   , BYVAL index4 AS INTEGER _                          ' __in short index4
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSelectedPart <57> ( _                      ' VTable offset = 352
     BYREF part AS INTEGER _                            ' __out short *part
   , BYREF index1 AS INTEGER _                          ' __out short *index1
   , BYREF index2 AS INTEGER _                          ' __out short *index2
   , BYREF index3 AS INTEGER _                          ' __out short *index3
   , BYREF index4 AS INTEGER _                          ' __out short *index4
   )                                                    ' void
   ' =====================================================================================
   METHOD TwipsToChartPart <59> ( _                     ' VTable offset = 356
     BYVAL xVal AS LONG _                               ' __in long xVal
   , BYVAL yVal AS LONG _                               ' __in long yVal
   , BYREF part AS INTEGER _                            ' __out short *part
   , BYREF index1 AS INTEGER _                          ' __out short *index1
   , BYREF index2 AS INTEGER _                          ' __out short *index2
   , BYREF index3 AS INTEGER _                          ' __out short *index3
   , BYREF index4 AS INTEGER _                          ' __out short *index4
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDragMode <1550> ( _                  ' VTable offset = 360
   ) AS LONG                                            ' __retval_out OLEDragConstants* psOLEDragMode
   ' =====================================================================================
   PROPERTY SET OLEDragMode <1550> ( _                  ' VTable offset = 364
     BYVAL psOLEDragMode AS LONG _                      ' __in OLEDragConstants psOLEDragMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OLEDropMode <1551> ( _                  ' VTable offset = 368
   ) AS LONG                                            ' __retval_out OLEDropConstants* psOLEDropMode
   ' =====================================================================================
   PROPERTY SET OLEDropMode <1551> ( _                  ' VTable offset = 372
     BYVAL psOLEDropMode AS LONG _                      ' __in OLEDropConstants psOLEDropMode
   )                                                    ' void
   ' =====================================================================================
   METHOD OLEDrag <1552> ( _                            ' VTable offset = 376
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataSource <71> ( _                     ' VTable offset = 380
   ) AS DataSource                                      ' __retval_out DataSource** ppDataSource
   ' =====================================================================================
   PROPERTY SET putref_DataSource <71> ( _              ' VTable offset = 384
     BYVAL ppDataSource AS DataSource _                 ' __in DataSource* ppDataSource
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataMember <75> ( _                     ' VTable offset = 388
   ) AS WSTRING                                         ' __retval_out DataMember* pbstrDataMember
   ' =====================================================================================
   PROPERTY SET DataMember <75> ( _                     ' VTable offset = 392
     BYVAL pbstrDataMember AS WSTRING _                 ' __in DataMember pbstrDataMember
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MSChartDMSChart_INTERFACE_DEFINED__ */


' ########################################################################################
' Class CDMSChartEvents
' Interface name = _DMSChartEvents
' IID = {3A2B370B-BA0A-11D1-B137-0000F8753F5D}
' Event interface for MSChart Control 6.0 (SP4) (OLEDB)
' Attributes = 4112 [&H1010] [Hidden] [Dispatchable]
' ########################################################################################

'CLASS CDMSChartEvents GUID$("{07C396D5-6C70-49D0-BCC0-856085C772E2}") AS EVENT

'INTERFACE DMSChartEventsImpl GUID$("{3A2B370B-BA0A-11D1-B137-0000F8753F5D}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD OLEStartDrag <1550> ( _
'     BYREF pData AS IDispatch _                         ' __in_out DataObject** Data
'   , BYREF AllowedEffects AS LONG _                     ' __in_out long* AllowedEffects
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEGiveFeedback <1551> ( _
'     BYREF Effect AS LONG _                             ' __in_out *Effect VT_I4 <Long>
'   , BYREF DefaultCursors AS INTEGER _                  ' __in_out *DefaultCursors VT_BOOL <Integer>
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLESetData <1552> ( _
'     BYREF pData AS IDispatch _                         ' __in_out DataObject** Data
'   , BYREF DataFormat AS INTEGER _                      ' __in_out short* DataFormat
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLECompleteDrag <1553> ( _
'     BYREF Effect AS LONG _                             ' __in_out long* Effect
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEDragOver <1554> ( _
'     BYREF pData AS IDispatch _                         ' __in_out DataObject** Data
'   , BYREF Effect AS LONG _                             ' __in_out long* Effect
'   , BYREF iButton AS INTEGER _                         ' __in_out short* Button
'   , BYREF iShift AS INTEGER _                          ' __in_out short* Shift
'   , BYREF X AS SINGLE _                                ' __in_out float* X
'   , BYREF Y AS SINGLE _                                ' __in_out float* Y
'   , BYREF iState AS INTEGER _                          ' __in_out short* State
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD OLEDragDrop <1555> ( _
'     BYREF pData AS IDispatch _                         ' __in_out DataObject** Data
'   , BYREF Effect AS LONG _                             ' __in_out long* Effect
'   , BYREF iButton AS INTEGER _                         ' __in_out short* Button
'   , BYREF iShift AS INTEGER _                          ' __in_out short* Shift
'   , BYREF X AS SINGLE _                                ' __in_out float* X
'   , BYREF Y AS SINGLE _                                ' __in_out float* Y
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD ChartSelected <1> ( _
'     BYREF MouseFlags AS INTEGER _                      ' __in  short* MouseFlags
'   , BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD TitleSelected <2> ( _
'     BYREF MouseFlags AS INTEGER _                      ' __in  short* MouseFlags
'   , BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD FootnoteSelected <3> ( _
'     BYREF MouseFlags AS INTEGER _                      ' __in  short* MouseFlags
'   , BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD LegendSelected <4> ( _
'     BYREF MouseFlags AS INTEGER _                      ' __in  short* MouseFlags
'   , BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PlotSelected <5> ( _
'     BYREF MouseFlags AS INTEGER _                      ' __in  short* MouseFlags
'   , BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD AxisSelected <6> ( _
'     BYREF axisID AS INTEGER _                          ' __in  short* axisID
'   , BYREF AxisIndex AS INTEGER _                       ' __in  short* AxisIndex
'   , BYREF MouseFlags AS INTEGER _                      ' __in  short* MouseFlags
'   , BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD AxisLabelSelected <7> ( _
'     BYREF axisID AS INTEGER _                          ' __in  short* axisID
'   , BYREF AxisIndex AS INTEGER _                       ' __in  short* AxisIndex
'   , BYREF labelSetIndex AS INTEGER _                   ' __in  short* labelSetIndex
'   , BYREF LabelIndex AS INTEGER _                      ' __in  short* LabelIndex
'   , BYREF MouseFlags AS INTEGER _                      ' __in  short* MouseFlags
'   , BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD AxisTitleSelected <8> ( _
'     BYREF axisID AS INTEGER _                          ' __in  short* axisID
'   , BYREF AxisIndex AS INTEGER _                       ' __in  short* AxisIndex
'   , BYREF MouseFlags AS INTEGER _                      ' __in  short* MouseFlags
'   , BYREF Cancel AS INTEGER _                          ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PointSelected <9> ( _
'     BYREF Series AS INTEGER _                          ' __in  short* Series
'   , BYREF DataPoint AS INTEGER _                       ' __in  short* DataPoint
'   , BYREF MouseFlags AS INTEGER _                      ' __in  short* MouseFlags
'   , BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PointLabelSelected <10> ( _
'     BYREF Series AS INTEGER _                          ' __in  short* Series
'   , BYREF DataPoint AS INTEGER _                       ' __in  short* DataPoint
'   , BYREF MouseFlags AS INTEGER _                      ' __in  short* MouseFlags
'   , BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD SeriesSelected <11> ( _
'     BYREF Series AS INTEGER _                          ' __in  short* Series
'   , BYREF MouseFlags AS INTEGER _                      ' __in  short* MouseFlags
'   , BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD ChartActivated <13> ( _
'     BYREF MouseFlags AS INTEGER _                      ' __in  short* MouseFlags
'   , BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD TitleActivated <14> ( _
'     BYREF MouseFlags AS INTEGER _                      ' __in  short* MouseFlags
'   , BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD FootnoteActivated <15> ( _
'     BYREF MouseFlags AS INTEGER _                      ' __in  short* MouseFlags
'   , BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD LegendActivated <16> ( _
'     BYREF MouseFlags AS INTEGER _                      ' __in  short* MouseFlags
'   , BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PlotActivated <17> ( _
'     BYREF MouseFlags AS INTEGER _                      ' __in  short* MouseFlags
'   , BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD AxisActivated <18> ( _
'     BYREF axisID AS INTEGER _                          ' __in  short* axisID
'   , BYREF AxisIndex AS INTEGER _                       ' __in  short* AxisIndex
'   , BYREF MouseFlags AS INTEGER _                      ' __in  short* MouseFlags
'   , BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD AxisLabelActivated <19> ( _
'     BYREF axisID AS INTEGER _                          ' __in  short* axisID
'   , BYREF AxisIndex AS INTEGER _                       ' __in  short* AxisIndex
'   , BYREF labelSetIndex AS INTEGER _                   ' __in  short* labelSetIndex
'   , BYREF LabelIndex AS INTEGER _                      ' __in  short* LabelIndex
'   , BYREF MouseFlags AS INTEGER _                      ' __in  short* MouseFlags
'   , BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD AxisTitleActivated <20> ( _
'     BYREF axisID AS INTEGER _                          ' __in  short* axisID
'   , BYREF AxisIndex AS INTEGER _                       ' __in  short* AxisIndex
'   , BYREF MouseFlags AS INTEGER _                      ' __in  short* MouseFlags
'   , BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PointActivated <21> ( _
'     BYREF Series AS INTEGER _                          ' __in  short* Series
'   , BYREF DataPoint AS INTEGER _                       ' __in  short* DataPoint
'   , BYREF MouseFlags AS INTEGER _                      ' __in  short* MouseFlags
'   , BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PointLabelActivated <22> ( _
'     BYREF Series AS INTEGER _                          ' __in  short* Series
'   , BYREF DataPoint AS INTEGER _                       ' __in  short* DataPoint
'   , BYREF MouseFlags AS INTEGER _                      ' __in  short* MouseFlags
'   , BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD SeriesActivated <23> ( _
'     BYREF Series AS INTEGER _                          ' __in  short* Series
'   , BYREF MouseFlags AS INTEGER _                      ' __in  short* MouseFlags
'   , BYREF iCancel AS INTEGER _                         ' __out short* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD AxisUpdated <26> ( _
'     BYREF axisID AS INTEGER _                          ' __in short* axisID
'   , BYREF AxisIndex AS INTEGER _                       ' __in short* AxisIndex
'   , BYREF updateFlags AS INTEGER _                     ' __in short* updateFlags
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD AxisLabelUpdated <27> ( _
'     BYREF axisID AS INTEGER _                          ' __in short* axisID
'   , BYREF AxisIndex AS INTEGER _                       ' __in short* AxisIndex
'   , BYREF labelSetIndex AS INTEGER _                   ' __in short* labelSetIndex
'   , BYREF LabelIndex AS INTEGER _                      ' __in short* LabelIndex
'   , BYREF updateFlags AS INTEGER _                     ' __in short* updateFlags
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD AxisTitleUpdated <28> ( _
'     BYREF axisID AS INTEGER _                          ' __in short* axisID
'   , BYREF AxisIndex AS INTEGER _                       ' __in short* AxisIndex
'   , BYREF updateFlags AS INTEGER _                     ' __in short* updateFlags
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD ChartUpdated <29> ( _
'     BYREF updateFlags AS INTEGER _                     ' __in short* updateFlags
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD FootnoteUpdated <30> ( _
'     BYREF updateFlags AS INTEGER _                     ' __in short* updateFlags
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD LegendUpdated <31> ( _
'     BYREF updateFlags AS INTEGER _                     ' __in short* updateFlags
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PlotUpdated <32> ( _
'     BYREF updateFlags AS INTEGER _                     ' __in short* updateFlags
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PointUpdated <33> ( _
'     BYREF Series AS INTEGER _                          ' __in short* Series
'   , BYREF DataPoint AS INTEGER _                       ' __in short* DataPoint
'   , BYREF updateFlags AS INTEGER _                     ' __in short* updateFlags
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PointLabelUpdated <34> ( _
'     BYREF Series AS INTEGER _                          ' __in short* Series
'   , BYREF DataPoint AS INTEGER _                       ' __in short* DataPoint
'   , BYREF updateFlags AS INTEGER _                     ' __in short* updateFlags
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD SeriesUpdated <35> ( _
'     BYREF Series AS INTEGER _                          ' __in short* Series
'   , BYREF updateFlags AS INTEGER _                     ' __in short* updateFlags
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD TitleUpdated <37> ( _
'     BYREF updateFlags AS INTEGER _                     ' __in short* updateFlags
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DataUpdated <38> ( _
'     BYREF Row AS INTEGER _                             ' __in short* Row
'   , BYREF iColumn AS INTEGER _                         ' __in short* Column
'   , BYREF labelRow AS INTEGER _                        ' __in short* labelRow
'   , BYREF labelColumn AS INTEGER _                     ' __in short* labelColumn
'   , BYREF labelSetIndex AS INTEGER _                   ' __in short* labelSetIndex
'   , BYREF updateFlags AS INTEGER _                     ' __in short* updateFlags
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DonePainting <39>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD Click <-600>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DblClick <-601>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyDown <-602> ( _
'     BYREF KeyCode AS INTEGER _                         ' __in short *KeyCode
'   , BYVAL iShift AS INTEGER _                          ' __in short Shift
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyPress <-603> ( _
'     BYREF KeyAscii AS INTEGER _                        ' __in short* KeyAscii
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD KeyUp <-604> ( _
'     BYREF KeyCode AS INTEGER _                         ' __in short *KeyCode
'   , BYVAL iShift AS INTEGER _                          ' __in short Shift
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseDown <-605> ( _
'     BYVAL iButton AS INTEGER _                         ' __in short Button
'   , BYVAL iShift AS INTEGER _                          ' __in short Shift
'   , BYVAL X AS LONG _                                  ' __in X OLE_XPOS_PIXELS
'   , BYVAL Y AS LONG _                                  ' __in Y OLE_YPOS_PIXELS
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseMove <-606> ( _
'     BYVAL iButton AS INTEGER _                         ' __in short Button
'   , BYVAL iShift AS INTEGER _                          ' __in short Shift
'   , BYVAL X AS LONG _                                  ' __in X OLE_XPOS_PIXELS
'   , BYVAL Y AS LONG _                                  ' __in Y OLE_YPOS_PIXELS
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD MouseUp <-607> ( _
'     BYVAL iButton AS INTEGER _                         ' __in short Button
'   , BYVAL iShift AS INTEGER _                          ' __in short Shift
'   , BYVAL X AS LONG _                                  ' __in X OLE_XPOS_PIXELS
'   , BYVAL Y AS LONG _                                  ' __in Y OLE_YPOS_PIXELS
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS
