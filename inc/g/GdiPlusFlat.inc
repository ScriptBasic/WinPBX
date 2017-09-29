' ########################################################################################
' Microsoft Windows
' File: GdiPlusFlat.inc
' Contents: GDI+ flat API
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%GDIPLUSFLAT_INC = 1

#INCLUDE ONCE "objidl.inc"

'//----------------------------------------------------------------------------
'// GraphicsPath APIs
'//----------------------------------------------------------------------------

DECLARE FUNCTION GdipCreatePath IMPORT "GDIPLUS.DLL" ALIAS "GdipCreatePath" ( _
   BYVAL brushMode AS LONG _                            ' __in  GpFillMode brushMode
 , BYREF path AS DWORD _                                ' __out GpPath **path
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreatePath2 IMPORT "GDIPLUS.DLL" ALIAS "GdipCreatePath2" ( _
   BYREF points AS GpPointF _                           ' __in  GDIPCONST GpPointF* points
 , BYREF types AS ANY _                                 ' __in  GDIPCONST BYTE* types
 , BYVAL count AS LONG _                                ' __in  INT count
 , BYVAL fillmode AS LONG _                             ' __in  GpFillMode fillmode
 , BYREF path AS DWORD _                                ' __out GpPath **path
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreatePath2I IMPORT "GDIPLUS.DLL" ALIAS "GdipCreatePath2I" ( _
   BYREF points AS GpPoint _                            ' __in  GDIPCONST GpPoint* points
 , BYREF types AS ANY _                                 ' __in  GDIPCONST BYTE* types
 , BYVAL count AS LONG _                                ' __in  INT count
 , BYVAL fillmode AS LONG _                             ' __in  GpFillMode fillmode
 , BYREF path AS DWORD _                                ' __out GpPath **path
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipClonePath IMPORT "GDIPLUS.DLL" ALIAS "GdipClonePath" ( _
   BYVAL path AS DWORD _                                ' __in  GpPath *path
 , BYREF clonePath AS DWORD _                           ' __out GpPath **clonePath
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDeletePath IMPORT "GDIPLUS.DLL" ALIAS "GdipDeletePath" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipResetPath IMPORT "GDIPLUS.DLL" ALIAS "GdipResetPath" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPointCount IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPointCount" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYREF count AS LONG _                                ' __out INT *count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathTypes IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathTypes" ( _
   BYVAL path AS DWORD _                                ' __in  GpPath *path
 , BYREF types AS ANY _                                 ' __out BYTE *types
 , BYVAL count AS LONG _                                ' __in  INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathPoints IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathPoints" ( _
   BYVAL path AS DWORD _                                ' __in  GpPath* path
 , BYREF points AS GpPointF _                           ' __out GpPointF* points
 , BYVAL count AS LONG _                                ' __in  INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathPointsI IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathPointsI" ( _
   BYVAL path AS DWORD _                                ' __in  GpPath* path
 , BYREF points AS GpPoint _                            ' __out GpPoint* points
 , BYVAL count AS LONG _                                ' __in  INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathFillMode IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathFillMode" ( _
   BYVAL path AS DWORD _                                ' __in  GpPath *path
 , BYREF fillmode AS LONG _                             ' __out GpFillMode *fillmode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPathFillMode IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPathFillMode" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYVAL fillMode AS LONG _                             ' __in GpFillMode fillMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathData IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathData" ( _
   BYVAL path AS DWORD _                                ' __in  GpPath *path
 , BYREF pathData AS GpPathData _                       ' __out GpPathData *pathData
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipStartPathFigure IMPORT "GDIPLUS.DLL" ALIAS "GdipStartPathFigure" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipClosePathFigure IMPORT "GDIPLUS.DLL" ALIAS "GdipClosePathFigure" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipClosePathFigures IMPORT "GDIPLUS.DLL" ALIAS "GdipClosePathFigures" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPathMarker IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPathMarker" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipClearPathMarkers IMPORT "GDIPLUS.DLL" ALIAS "GdipClearPathMarkers" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipReversePath IMPORT "GDIPLUS.DLL" ALIAS "GdipReversePath" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathLastPoint IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathLastPoint" ( _
   BYVAL path AS DWORD _                                ' __in  GpPath *path
 , BYREF lastPoint AS GpPointF _                        ' __out GpPointF *lastPoint
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathLine IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathLine" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYVAL x1 AS SINGLE _                                 ' __in REAL x1
 , BYVAL y1 AS SINGLE _                                 ' __in REAL y1
 , BYVAL x2 AS SINGLE _                                 ' __in REAL x2
 , BYVAL y2 AS SINGLE _                                 ' __in REAL y2
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathLine2 IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathLine2" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYREF points AS GpPointF _                           ' __in GpPointF *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathArc IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathArc" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYVAL x AS SINGLE _                                  ' __in REAL x
 , BYVAL y AS SINGLE _                                  ' __in REAL y
 , BYVAL width AS SINGLE _                              ' __in REAL width
 , BYVAL height AS SINGLE _                             ' __in REAL height
 , BYVAL startAngle AS SINGLE _                         ' __in REAL startAngle
 , BYVAL sweepAngle AS SINGLE _                         ' __in REAL sweepAngle
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathBezier IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathBezier" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYVAL x1 AS SINGLE _                                 ' __in REAL x1
 , BYVAL y1 AS SINGLE _                                 ' __in REAL y1
 , BYVAL x2 AS SINGLE _                                 ' __in REAL x2
 , BYVAL y2 AS SINGLE _                                 ' __in REAL y2
 , BYVAL x3 AS SINGLE _                                 ' __in REAL x3
 , BYVAL y3 AS SINGLE _                                 ' __in REAL y3
 , BYVAL x4 AS SINGLE _                                 ' __in REAL x4
 , BYVAL y4 AS SINGLE _                                 ' __in REAL y4
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathBeziers IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathBeziers" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYREF points AS GpPointF _                           ' __in GDIPCONST GpPointF *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathCurve IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathCurve" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYREF points AS GpPointF _                           ' __in GDIPCONST GpPointF *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathCurve2 IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathCurve2" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYREF points AS GpPointF _                           ' __in GDIPCONST GpPointF *points
 , BYVAL count AS LONG _                                ' __in INT count
 , BYVAL tension AS SINGLE _                            ' __in REAL tension
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathCurve3 IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathCurve3" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYREF points AS GpPointF _                           ' __in GDIPCONST GpPointF *points
 , BYVAL count AS LONG _                                ' __in INT count
 , BYVAL offset AS LONG _                               ' __in INT offset
 , BYVAL numberOfSegments AS LONG _                     ' __in INT numberOfSegments
 , BYVAL tension AS SINGLE _                            ' __in REAL tension
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathClosedCurve IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathClosedCurve" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYREF points AS GpPointF _                           ' __in GDIPCONST GpPointF *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathClosedCurve2 IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathClosedCurve2" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYREF points AS GpPointF _                           ' __in GDIPCONST GpPointF *points
 , BYVAL count AS LONG _                                ' __in INT count
 , BYVAL tension AS SINGLE _                            ' __in REAL tension
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathRectangle IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathRectangle" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYVAL x AS SINGLE _                                  ' __in REAL x
 , BYVAL y AS SINGLE _                                  ' __in REAL y
 , BYVAL width AS SINGLE _                              ' __in REAL width
 , BYVAL height AS SINGLE _                             ' __in REAL height
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathRectangles IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathRectangles" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYREF rects AS GpRectF _                             ' __in GDIPCONST GpRectF *rects
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathEllipse IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathEllipse" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYVAL x AS SINGLE _                                  ' __in REAL x
 , BYVAL y AS SINGLE _                                  ' __in REAL y
 , BYVAL width AS SINGLE _                              ' __in REAL width
 , BYVAL height AS SINGLE _                             ' __in REAL height
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathPie IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathPie" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYVAL x AS SINGLE _                                  ' __in REAL x
 , BYVAL y AS SINGLE _                                  ' __in REAL y
 , BYVAL width AS SINGLE _                              ' __in REAL width
 , BYVAL height AS SINGLE _                             ' __in REAL height
 , BYVAL startAngle AS SINGLE _                         ' __in REAL startAngle
 , BYVAL sweepAngle AS SINGLE _                         ' __in REAL sweepAngle
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathPolygon IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathPolygon" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYREF points AS GpPointF _                           ' __in GDIPCONST GpPointF *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathPath IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathPath" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYVAL addingPath AS DWORD _                          ' __in GDIPCONST GpPath *addingPath
 , BYVAL connect AS LONG _                              ' __in BOOL connect
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathString IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathString" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYREF string AS WSTRINGZ _                           ' __in GDIPCONST WCHAR *string
 , BYVAL length AS LONG _                               ' __in INT length
 , BYVAL family AS DWORD _                              ' __in GDIPCONST GpFontFamily *family
 , BYVAL style AS LONG _                                ' __in INT style
 , BYVAL emSize AS SINGLE _                             ' __in REAL emSize
 , BYREF layoutRect AS GpRectF _                        ' __in GDIPCONST GpRectF *layoutRect
 , BYVAL format AS DWORD _                              ' __in GDIPCONST GpStringFormat *format
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathStringI IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathStringI" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYREF string AS WSTRINGZ _                           ' __in GDIPCONST WCHAR *string
 , BYVAL length AS LONG _                               ' __in INT length
 , BYVAL family AS DWORD _                              ' __in GDIPCONST GpFontFamily *family
 , BYVAL style AS LONG _                                ' __in INT style
 , BYVAL emSize AS SINGLE _                             ' __in REAL emSize
 , BYREF layoutRect AS GpRect _                         ' __in GDIPCONST GpRect *layoutRect
 , BYVAL format AS DWORD _                              ' __in GDIPCONST GpStringFormat *format
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathLineI IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathLineI" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYVAL x1 AS LONG _                                   ' __in INT x1
 , BYVAL y1 AS LONG _                                   ' __in INT y1
 , BYVAL x2 AS LONG _                                   ' __in INT x2
 , BYVAL y2 AS LONG _                                   ' __in INT y2
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathLine2I IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathLine2I" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYREF points AS GpPoint _                            ' __in GDIPCONST GpPoint *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathArcI IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathArcI" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYVAL x AS LONG _                                    ' __in INT x
 , BYVAL y AS LONG _                                    ' __in INT y
 , BYVAL width AS LONG _                                ' __in INT width
 , BYVAL height AS LONG _                               ' __in INT height
 , BYVAL startAngle AS SINGLE _                         ' __in REAL startAngle
 , BYVAL sweepAngle AS SINGLE _                         ' __in REAL sweepAngle
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathBezierI IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathBezierI" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYVAL x1 AS LONG _                                   ' __in INT x1
 , BYVAL y1 AS LONG _                                   ' __in INT y1
 , BYVAL x2 AS LONG _                                   ' __in INT x2
 , BYVAL y2 AS LONG _                                   ' __in INT y2
 , BYVAL x3 AS LONG _                                   ' __in INT x3
 , BYVAL y3 AS LONG _                                   ' __in INT y3
 , BYVAL x4 AS LONG _                                   ' __in INT x4
 , BYVAL y4 AS LONG _                                   ' __in INT y4
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathBeziersI IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathBeziersI" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYREF points AS GpPoint _                            ' __in GDIPCONST GpPoint *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathCurveI IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathCurveI" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYREF points AS GpPoint _                            ' __in GDIPCONST GpPoint *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathCurve2I IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathCurve2I" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYREF points AS GpPoint _                            ' __in GDIPCONST GpPoint *points
 , BYVAL count AS LONG _                                ' __in INT count
 , BYVAL tension AS SINGLE _                            ' __in REAL tension
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathCurve3I IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathCurve3I" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYREF points AS GpPoint _                            ' __in GDIPCONST GpPoint *points
 , BYVAL count AS LONG _                                ' __in INT count
 , BYVAL offset AS LONG _                               ' __in INT offset
 , BYVAL numberOfSegments AS LONG _                     ' __in INT numberOfSegments
 , BYVAL tension AS SINGLE _                            ' __in REAL tension
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathClosedCurveI IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathClosedCurveI" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYREF points AS GpPoint _                            ' __in GDIPCONST GpPoint *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathClosedCurve2I IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathClosedCurve2I" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYREF points AS GpPoint _                            ' __in GDIPCONST GpPoint *points
 , BYVAL count AS LONG _                                ' __in INT count
 , BYVAL tension AS SINGLE _                            ' __in REAL tension
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathRectangleI IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathRectangleI" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYVAL x AS LONG _                                    ' __in INT x
 , BYVAL y AS LONG _                                    ' __in INT y
 , BYVAL width AS LONG _                                ' __in INT width
 , BYVAL height AS LONG _                               ' __in INT height
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathRectanglesI IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathRectanglesI" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYREF rects AS GpRect _                              ' __in GDIPCONST GpRect *rects
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathEllipseI IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathEllipseI" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYVAL x AS LONG _                                    ' __in INT x
 , BYVAL y AS LONG _                                    ' __in INT y
 , BYVAL width AS LONG _                                ' __in INT width
 , BYVAL height AS LONG _                               ' __in INT height
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathPieI IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathPieI" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYVAL x AS LONG _                                    ' __in INT x
 , BYVAL y AS LONG _                                    ' __in INT y
 , BYVAL width AS LONG _                                ' __in INT width
 , BYVAL height AS LONG _                               ' __in INT height
 , BYVAL startAngle AS SINGLE _                         ' __in REAL startAngle
 , BYVAL sweepAngle AS SINGLE _                         ' __in REAL sweepAngle
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipAddPathPolygonI IMPORT "GDIPLUS.DLL" ALIAS "GdipAddPathPolygonI" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYREF points AS GpPoint _                            ' __in GDIPCONST GpPoint *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipFlattenPath IMPORT "GDIPLUS.DLL" ALIAS "GdipFlattenPath" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
 , BYVAL flatness AS SINGLE _                           ' __in REAL flatness
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipWindingModeOutline IMPORT "GDIPLUS.DLL" ALIAS "GdipWindingModeOutline" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
 , BYVAL flatness AS SINGLE _                           ' __in REAL flatness
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipWidenPath IMPORT "GDIPLUS.DLL" ALIAS "GdipWidenPath" ( _
   BYVAL nativePath AS LONG _                           ' __in GpPath *nativePath
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
 , BYVAL flatness AS SINGLE _                           ' __in REAL flatness
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipWarpPath IMPORT "GDIPLUS.DLL" ALIAS "GdipWarpPath" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
 , BYREF points AS GpPointF _                           ' __in GDIPCONST GpPointF *points
 , BYVAL count AS LONG _                                ' __in INT count
 , BYVAL srcx AS SINGLE _                               ' __in REAL srcx
 , BYVAL srcy AS SINGLE _                               ' __in REAL srcy
 , BYVAL srcwidth AS SINGLE _                           ' __in REAL srcwidth
 , BYVAL srcheight AS SINGLE _                          ' __in REAL srcheight
 , BYVAL warpMode AS LONG _                             ' __in WarpMode warpMode
 , BYVAL flatness AS SINGLE _                           ' __in REAL flatness
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipTransformPath IMPORT "GDIPLUS.DLL" ALIAS "GdipTransformPath" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathWorldBounds IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathWorldBounds" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYREF bounds AS GpRectF _                            ' __in GpRectF *bounds
 , BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathWorldBoundsI IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathWorldBoundsI" ( _
   BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYREF bounds AS GpRect _                             ' __in GpRect *bounds
 , BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipIsVisiblePathPoint IMPORT "GDIPLUS.DLL" ALIAS "GdipIsVisiblePathPoint" ( _
   BYVAL path AS DWORD _                                ' __in  GpPath *path
 , BYVAL x AS SINGLE _                                  ' __in  REAL x
 , BYVAL y AS SINGLE _                                  ' __in  REAL y
 , BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF result AS LONG _                               ' __out BOOL *result
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipIsVisiblePathPointI IMPORT "GDIPLUS.DLL" ALIAS "GdipIsVisiblePathPointI" ( _
   BYVAL path AS DWORD _                                ' __in  GpPath *path
 , BYVAL x AS LONG _                                    ' __in  INT x
 , BYVAL y AS LONG _                                    ' __in  INT y
 , BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF result AS LONG _                               ' __out BOOL *result
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipIsOutlineVisiblePathPoint IMPORT "GDIPLUS.DLL" ALIAS "GdipIsOutlineVisiblePathPoint" ( _
   BYVAL path AS DWORD _                                ' __in  GpPath *path
 , BYVAL x AS SINGLE _                                  ' __in  REAL x
 , BYVAL y AS SINGLE _                                  ' __in  REAL y
 , BYVAL pen AS DWORD _                                 ' __in  GpPen *pen
 , BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF result AS LONG _                               ' __out BOOL *result
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipIsOutlineVisiblePathPointI IMPORT "GDIPLUS.DLL" ALIAS "GdipIsOutlineVisiblePathPointI" ( _
   BYVAL path AS DWORD _                                ' __in  GpPath *path
 , BYVAL x AS LONG _                                    ' __in  INT x
 , BYVAL y AS LONG _                                    ' __in  INT y
 , BYVAL pen AS DWORD _                                 ' __in  GpPen *pen
 , BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF result AS LONG _                               ' __out BOOL *result
 ) AS LONG                                              ' GpStatus


'//----------------------------------------------------------------------------
'// PathIterator APIs
'//----------------------------------------------------------------------------

DECLARE FUNCTION GdipCreatePathIter IMPORT "GDIPLUS.DLL" ALIAS "GdipCreatePathIter" ( _
   BYREF iterator AS DWORD _                            ' __in  GpPathIterator **iterator
 , BYVAL path AS DWORD _                                ' __in  GpPath *path
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDeletePathIter IMPORT "GDIPLUS.DLL" ALIAS "GdipDeletePathIter" ( _
   BYVAL iterator AS DWORD _                            ' __in  GpPathIterator *iterator
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipPathIterNextSubpath IMPORT "GDIPLUS.DLL" ALIAS "GdipPathIterNextSubpath" ( _
   BYVAL iterator AS DWORD _                            ' __in  GpPathIterator *iterator
 , BYREF resultCount AS LONG _                          ' __out INT *resultCount
 , BYREF startIndex AS LONG _                           ' __out INT *startIndex
 , BYREF endIndex AS LONG _                             ' __out INT *endIndex
 , BYREF isClosed AS LONG _                             ' __out BOOL *isClosed
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipPathIterNextSubpathPath IMPORT "GDIPLUS.DLL" ALIAS "GdipPathIterNextSubpathPath" ( _
   BYVAL iterator AS DWORD _                            ' __in  GpPathIterator *iterator
 , BYREF resultCount AS LONG _                          ' __out INT *resultCount
 , BYREF path AS DWORD _                                ' __out GpPath *path
 , BYREF isClosed AS LONG _                             ' __out BOOL *isClosed
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipPathIterNextPathType IMPORT "GDIPLUS.DLL" ALIAS "GdipPathIterNextPathType" ( _
   BYVAL iterator AS DWORD _                            ' __in  GpPathIterator *iterator
 , BYREF resultCount AS LONG _                          ' __out INT *resultCount
 , BYREF pathType AS ANY _                              ' __out BYTE *pathType
 , BYREF startIndex AS LONG _                           ' __out INT *startIndex
 , BYREF endIndex AS LONG _                             ' __out INT *endIndex
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipPathIterNextMarker IMPORT "GDIPLUS.DLL" ALIAS "GdipPathIterNextMarker" ( _
   BYVAL iterator AS DWORD _                            ' __in  GpPathIterator *iterator
 , BYREF resultCount AS LONG _                          ' __out INT *resultCount
 , BYREF startIndex AS LONG _                           ' __out INT *startIndex
 , BYREF endIndex AS LONG _                             ' __out INT *endIndex
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipPathIterNextMarkerPath IMPORT "GDIPLUS.DLL" ALIAS "GdipPathIterNextMarkerPath" ( _
   BYVAL iterator AS DWORD _                            ' __in  GpPathIterator *iterator
 , BYREF resultCount AS LONG _                          ' __out INT *resultCount
 , BYVAL path AS DWORD _                                ' __in  GpPath *path
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipPathIterGetCount IMPORT "GDIPLUS.DLL" ALIAS "GdipPathIterGetCount" ( _
   BYVAL iterator AS DWORD _                            ' __in  GpPathIterator *iterator
 , BYREF count AS LONG _                                ' __out INT *count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipPathIterGetSubpathCount IMPORT "GDIPLUS.DLL" ALIAS "GdipPathIterGetSubpathCount" ( _
   BYVAL iterator AS DWORD _                            ' __in GpPathIterator *iterator
 , BYREF count AS LONG _                                ' __out INT *count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipPathIterIsValid IMPORT "GDIPLUS.DLL" ALIAS "GdipPathIterIsValid" ( _
   BYVAL iterator AS DWORD _                            ' __in  GpPathIterator *iterator
 , BYREF valid AS LONG _                                ' __out BOOL *valid
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipPathIterHasCurve IMPORT "GDIPLUS.DLL" ALIAS "GdipPathIterHasCurve" ( _
   BYVAL iterator AS DWORD _                            ' __in  GpPathIterator *iterator
 , BYREF hasCurve AS LONG _                             ' __out BOOL *hasCurve
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipPathIterRewind IMPORT "GDIPLUS.DLL" ALIAS "GdipPathIterRewind" ( _
   BYVAL iterator AS DWORD _                            ' __in GpPathIterator *iterator
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipPathIterEnumerate IMPORT "GDIPLUS.DLL" ALIAS "GdipPathIterEnumerate" ( _
   BYVAL iterator AS DWORD _                            ' __in  GpPathIterator *iterator
 , BYREF resultCount AS LONG _                          ' __out INT *resultCount
 , BYREF points AS GpPointF _                           ' __out GpPointF *points
 , BYREF types AS ANY _                                 ' __out BYTE *types
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipPathIterCopyData IMPORT "GDIPLUS.DLL" ALIAS "GdipPathIterCopyData" ( _
   BYVAL iterator AS DWORD _                            ' __in  GpPathIterator *iterator
 , BYREF resultCount AS LONG _                          ' __out INT *resultCount
 , BYREF points AS GpPointF _                           ' __out GpPointF *points
 , BYREF types AS ANY _                                 ' __out BYTE *types
 , BYVAL startIndex AS LONG _                           ' __in  INT startIndex
 , BYVAL endIndex AS LONG _                             ' __in  INT endIndex
 ) AS LONG                                              ' GpStatus

'//----------------------------------------------------------------------------
'// Matrix APIs
'//----------------------------------------------------------------------------

DECLARE FUNCTION GdipCreateMatrix IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateMatrix" ( _
   BYREF matrix AS DWORD _                              ' __in GpMatrix **matrix
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateMatrix2 IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateMatrix2" ( _
   BYVAL m11 AS SINGLE _                                ' __in  REAL m11
 , BYVAL m12 AS SINGLE _                                ' __in  REAL m12
 , BYVAL m21 AS SINGLE _                                ' __in  REAL m21
 , BYVAL m22 AS SINGLE _                                ' __in  REAL m22
 , BYVAL dx AS SINGLE _                                 ' __in  REAL dx
 , BYVAL dy AS SINGLE _                                 ' __in  REAL dy
 , BYREF matrix AS DWORD _                              ' __out GpMatrix **matrix
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateMatrix3 IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateMatrix3" ( _
   BYREF rect AS GpRectF _                              ' __in  GDIPCONST GpRectF *rect
 , BYREF dstplg AS GpPointF _                           ' __in  GDIPCONST GpPointF *dstplg
 , BYREF matrix AS DWORD _                              ' __out GpMatrix **matrix
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateMatrix3I IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateMatrix3I" ( _
   BYREF rect AS GpRect _                               ' __in  GDIPCONST GpRect *rect
 , BYREF dstplg AS GpPoint _                            ' __in  GDIPCONST GpPoint *dstplg
 , BYREF matrix AS DWORD _                              ' __out GpMatrix **matrix
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCloneMatrix IMPORT "GDIPLUS.DLL" ALIAS "GdipCloneMatrix" ( _
   BYVAL matrix AS DWORD _                              ' __in  GpMatrix *matrix
 , BYREF cloneMatrix AS DWORD _                         ' __out GpMatrix **cloneMatrix
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDeleteMatrix IMPORT "GDIPLUS.DLL" ALIAS "GdipDeleteMatrix" ( _
   BYVAL matrix AS DWORD _                              ' __in  GpMatrix *matrix
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetMatrixElements IMPORT "GDIPLUS.DLL" ALIAS "GdipSetMatrixElements" ( _
   BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
 , BYVAL m11 AS SINGLE _                                ' __in REAL m11
 , BYVAL m12 AS SINGLE _                                ' __in REAL m12
 , BYVAL m21 AS SINGLE _                                ' __in REAL m21
 , BYVAL m22 AS SINGLE _                                ' __in REAL m22
 , BYVAL dx AS SINGLE _                                 ' __in REAL dx
 , BYVAL dy AS SINGLE _                                 ' __in REAL dy
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipMultiplyMatrix IMPORT "GDIPLUS.DLL" ALIAS "GdipMultiplyMatrix" ( _
   BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
 , BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix2
 , BYVAL order AS LONG _                                ' __in GpMatrixOrder order
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipTranslateMatrix IMPORT "GDIPLUS.DLL" ALIAS "GdipTranslateMatrix" ( _
   BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
 , BYVAL offsetX AS SINGLE _                            ' __in REAL offsetX
 , BYVAL offsetY AS SINGLE _                            ' __in REAL offsetY
 , BYVAL order AS LONG _                                ' __in GpMatrixOrder order
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipScaleMatrix IMPORT "GDIPLUS.DLL" ALIAS "GdipScaleMatrix" ( _
   BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
 , BYVAL scaleX AS SINGLE _                             ' __in REAL scaleX
 , BYVAL scaleY AS SINGLE _                             ' __in REAL scaleY
 , BYVAL order AS LONG _                                ' __in GpMatrixOrder order
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipRotateMatrix IMPORT "GDIPLUS.DLL" ALIAS "GdipRotateMatrix" ( _
   BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
 , BYVAL angle AS SINGLE _                              ' __in REAL angle
 , BYVAL order AS LONG _                                ' __in GpMatrixOrder order
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipShearMatrix IMPORT "GDIPLUS.DLL" ALIAS "GdipShearMatrix" ( _
   BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
 , BYVAL shearX AS SINGLE _                             ' __in REAL shearX
 , BYVAL shearY AS SINGLE _                             ' __in REAL shearY
 , BYVAL order AS LONG _                                ' __in GpMatrixOrder order
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipInvertMatrix IMPORT "GDIPLUS.DLL" ALIAS "GdipInvertMatrix" ( _
   BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipTransformMatrixPoints IMPORT "GDIPLUS.DLL" ALIAS "GdipTransformMatrixPoints" ( _
   BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
 , BYREF pts AS GpPointF _                              ' __in_out GDIPCONST GpPointF *pts
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipTransformMatrixPointsI IMPORT "GDIPLUS.DLL" ALIAS "GdipTransformMatrixPointsI" ( _
   BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
 , BYREF pts AS GpPoint _                               ' __in_out GDIPCONST GpPoint *pts
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipVectorTransformMatrixPoints IMPORT "GDIPLUS.DLL" ALIAS "GdipVectorTransformMatrixPoints" ( _
   BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
, BYREF pts AS GpPointF _                               ' __in_out GDIPCONST GpPointF *pts
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipVectorTransformMatrixPointsI IMPORT "GDIPLUS.DLL" ALIAS "GdipVectorTransformMatrixPointsI" ( _
   BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
 , BYREF pts AS GpPoint _                               ' __in_out GDIPCONST GpPoint *pts
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetMatrixElements IMPORT "GDIPLUS.DLL" ALIAS "GdipGetMatrixElements" ( _
   BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
 , BYREF matrixOut AS SINGLE _                          ' __out REAL *matrixOut
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipIsMatrixInvertible IMPORT "GDIPLUS.DLL" ALIAS "GdipIsMatrixInvertible" ( _
   BYVAL matrix AS DWORD _                              ' __in  GpMatrix *matrix
 , BYREF result AS LONG _                               ' __out BOOL *result
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipIsMatrixIdentity IMPORT "GDIPLUS.DLL" ALIAS "GdipIsMatrixIdentity" ( _
   BYVAL matrix AS DWORD _                              ' __in  GpMatrix *matrix
 , BYREF result AS LONG _                               ' __out BOOL *result
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipIsMatrixEqual IMPORT "GDIPLUS.DLL" ALIAS "GdipIsMatrixEqual" ( _
   BYVAL matrix AS DWORD _                              ' __in  GpMatrix *matrix
 , BYVAL matrix2 AS DWORD _                             ' __in  GpMatrix *matrix2
 , BYREF result AS LONG _                               ' __out BOOL *result
 ) AS LONG                                              ' GpStatus

'//----------------------------------------------------------------------------
'// Region APIs
'//----------------------------------------------------------------------------

DECLARE FUNCTION GdipCreateRegion IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateRegion" ( _
   BYREF region AS DWORD _                             ' __out GpRegion **region
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateRegionRect IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateRegionRect" ( _
   BYREF rect AS GpRectF _                              ' __in  GDIPCONST GpRectF *rect
 , BYREF region AS DWORD _                              ' __out GpRegion **region
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateRegionRectI IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateRegionRectI" ( _
   BYREF rect AS GpRect _                               ' __in  GDIPCONST GpRect *rect
 , BYREF region AS DWORD _                              ' __out GpRegion **region
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateRegionPath IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateRegionPath" ( _
   BYVAL path AS DWORD _                                ' __in  GpPath *path
 , BYREF region AS DWORD _                              ' __out GpRegion **region
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateRegionRgnData IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateRegionRgnData" ( _
   BYREF regionData AS ANY _                            ' __in  GDIPCONST BYTE *regionData
 , BYVAL size AS LONG _                                 ' __in  INT size
 , BYREF region AS DWORD _                              ' __out GpRegion **region
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateRegionHrgn IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateRegionHrgn" ( _
   BYVAL hRgn AS DWORD _                                ' __in  HRGN hRgn
 , BYREF region AS DWORD _                              ' __out GpRegion **region
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCloneRegion IMPORT "GDIPLUS.DLL" ALIAS "GdipCloneRegion" ( _
   BYVAL region AS DWORD _                              ' __in  GpRegion *region
 , BYREF cloneRegion AS DWORD _                         ' __out GpRegion **cloneRegion
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDeleteRegion IMPORT "GDIPLUS.DLL" ALIAS "GdipDeleteRegion" ( _
   BYVAL region AS DWORD _                              ' __in GpRegion *region
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetInfinite IMPORT "GDIPLUS.DLL" ALIAS "GdipSetInfinite" ( _
   BYVAL region AS DWORD _                              ' __in GpRegion *region
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetEmpty IMPORT "GDIPLUS.DLL" ALIAS "GdipSetEmpty" ( _
   BYVAL region AS DWORD _                              ' __in GpRegion *region
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCombineRegionRect IMPORT "GDIPLUS.DLL" ALIAS "GdipCombineRegionRect" ( _
   BYVAL region AS DWORD _                              ' __in GpRegion *region
 , BYREF rect AS GpRectF _                              ' __in GDIPCONST GpRectF *rect
 , BYVAL combineMode AS LONG _                          ' __in CombineMode combineMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCombineRegionRectI IMPORT "GDIPLUS.DLL" ALIAS "GdipCombineRegionRectI" ( _
   BYVAL region AS DWORD _                              ' __in GpRegion *region
 , BYREF rect AS GpRect _                               ' __in GDIPCONST GpRect *rect
 , BYVAL combineMode AS LONG _                          ' __in CombineMode combineMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCombineRegionPath IMPORT "GDIPLUS.DLL" ALIAS "GdipCombineRegionPath" ( _
   BYVAL region AS DWORD _                              ' __in GpRegion *region
 , BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYVAL combineMode AS LONG _                          ' __in CombineMode combineMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCombineRegionRegion IMPORT "GDIPLUS.DLL" ALIAS "GdipCombineRegionRegion" ( _
   BYVAL region AS DWORD _                              ' __in GpRegion *region
 , BYVAL region2 AS DWORD _                             ' __in GpRegion *region2
 , BYVAL combineMode AS LONG _                          ' __in CombineMode combineMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipTranslateRegion IMPORT "GDIPLUS.DLL" ALIAS "GdipTranslateRegion" ( _
   BYVAL region AS DWORD _                              ' __in GpRegion *region
 , BYVAL dx AS SINGLE _                                 ' __in REAL dx
 , BYVAL dy AS SINGLE _                                 ' __in REAL dy
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipTranslateRegionI IMPORT "GDIPLUS.DLL" ALIAS "GdipTranslateRegionI" ( _
   BYVAL region AS DWORD _                              ' __in GpRegion *region
 , BYVAL dx AS LONG _                                   ' __in INT dx
 , BYVAL dy AS LONG _                                   ' __in INT dy
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipTransformRegion IMPORT "GDIPLUS.DLL" ALIAS "GdipTransformRegion" ( _
   BYVAL region AS DWORD _                              ' __in GpRegion *region
 , BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetRegionBounds IMPORT "GDIPLUS.DLL" ALIAS "GdipGetRegionBounds" ( _
   BYVAL region AS DWORD _                              ' __in  GpRegion *region
 , BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF rect AS GpRectF _                              ' __out GpRectF *rect
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetRegionBoundsI IMPORT "GDIPLUS.DLL" ALIAS "GdipGetRegionBoundsI" ( _
   BYVAL region AS DWORD _                              ' __in  GpRegion *region
 , BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF rect AS GpRect _                               ' __out GpRect rect
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetRegionHRgn IMPORT "GDIPLUS.DLL" ALIAS "GdipGetRegionHRgn" ( _
   BYVAL region AS DWORD _                              ' __in  GpRegion *region
 , BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF hRgn AS DWORD _                                ' __out HRGN *hRgn
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipIsEmptyRegion IMPORT "GDIPLUS.DLL" ALIAS "GdipIsEmptyRegion" ( _
   BYVAL region AS DWORD _                              ' __in  GpRegion *region
 , BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF result AS LONG _                               ' __out BOOL *result
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipIsInfiniteRegion IMPORT "GDIPLUS.DLL" ALIAS "GdipIsInfiniteRegion" ( _
   BYVAL region AS DWORD _                              ' __in  GpRegion *region
 , BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF result AS LONG _                               ' __out BOOL *result
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipIsEqualRegion IMPORT "GDIPLUS.DLL" ALIAS "GdipIsEqualRegion" ( _
   BYVAL region AS DWORD _                              ' __in  GpRegion *region
 , BYVAL region2 AS DWORD _                             ' __in  GpRegion *region2
 , BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF result AS LONG _                               ' __out BOOL *result
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetRegionDataSize IMPORT "GDIPLUS.DLL" ALIAS "GdipGetRegionDataSize" ( _
   BYVAL region AS DWORD _                              ' __in  GpRegion *region
 , BYREF bufferSize AS DWORD _                          ' __out UINT *bufferSize
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetRegionData IMPORT "GDIPLUS.DLL" ALIAS "GdipGetRegionData" ( _
   BYVAL region AS DWORD _                              ' __in  GpRegion *region
 , BYREF buffer AS ANY _                                ' __out BYTE *buffer
 , BYVAL bufferSize AS DWORD _                          ' __in  UINT bufferSize
 , BYREF sizeFilled AS DWORD _                          ' __out UINT *sizeFilled
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipIsVisibleRegionPoint IMPORT "GDIPLUS.DLL" ALIAS "GdipIsVisibleRegionPoint" ( _
   BYVAL region AS DWORD _                              ' __in  GpRegion *region
 , BYVAL x AS SINGLE _                                  ' __in  REAL x
 , BYVAL y AS SINGLE _                                  ' __in  REAL y
 , BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF result AS LONG _                               ' __out BOOL *result
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipIsVisibleRegionPointI IMPORT "GDIPLUS.DLL" ALIAS "GdipIsVisibleRegionPointI" ( _
   BYVAL region AS DWORD _                              ' __in  GpRegion *region
 , BYVAL x AS LONG _                                    ' __in  INT x
 , BYVAL y AS LONG _                                    ' __in  INT y
 , BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF result AS LONG _                               ' __out BOOL *result
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipIsVisibleRegionRect IMPORT "GDIPLUS.DLL" ALIAS "GdipIsVisibleRegionRect" ( _
   BYVAL region AS DWORD _                              ' __in  GpRegion *region
 , BYVAL x AS SINGLE _                                  ' __in  REAL x
 , BYVAL y AS SINGLE _                                  ' __in  REAL y
 , BYVAL width AS SINGLE _                              ' __in  REAL width
 , BYVAL height AS SINGLE _                             ' __in  REAL height
 , BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF result AS LONG _                               ' __out BOOL *result
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipIsVisibleRegionRectI IMPORT "GDIPLUS.DLL" ALIAS "GdipIsVisibleRegionRectI" ( _
   BYVAL region AS DWORD _                              ' __in  GpRegion *region
 , BYVAL x AS LONG _                                    ' __in  INT x
 , BYVAL y AS LONG _                                    ' __in  INT y
 , BYVAL width AS LONG _                                ' __in  INT width
 , BYVAL height AS LONG _                               ' __in  INT height
 , BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF result AS LONG _                               ' __out BOOL *result
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetRegionScansCount IMPORT "GDIPLUS.DLL" ALIAS "GdipGetRegionScansCount" ( _
   BYVAL region AS DWORD _                              ' __in  GpRegion *region
 , BYREF count AS DWORD _                               ' __out UINT *count
 , BYVAL matrix AS DWORD _                              ' __in  GpMatrix *matrix
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetRegionScans IMPORT "GDIPLUS.DLL" ALIAS "GdipGetRegionScans" ( _
   BYVAL region AS DWORD _                              ' __in  GpRegion *region
 , BYREF rects AS GpRectF _                             ' __out GpRectF *rects
 , BYREF count AS DWORD _                               ' __out UINT *count
 , BYVAL matrix AS DWORD _                              ' __in  GpMatrix *matrix
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetRegionScansI IMPORT "GDIPLUS.DLL" ALIAS "GdipGetRegionScansI" ( _
   BYVAL region AS DWORD _                              ' __in  GpRegion *region
 , BYREF rects AS GpRect _                              ' __out GpRect *rects
 , BYREF count AS DWORD _                               ' __out UINT *count
 , BYVAL matrix AS DWORD _                              ' __in  GpMatrix *matrix
 ) AS LONG                                              ' GpStatus

'//----------------------------------------------------------------------------
'// Brush APIs
'//----------------------------------------------------------------------------

DECLARE FUNCTION GdipCloneBrush IMPORT "GDIPLUS.DLL" ALIAS "GdipCloneBrush" ( _
   BYVAL brush AS DWORD _                               ' __in  GpBrush *brush
 , BYREF cloneBrush AS DWORD _                          ' __out GpBrush **cloneBrush
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDeleteBrush IMPORT "GDIPLUS.DLL" ALIAS "GdipDeleteBrush" ( _
   BYVAL brush AS DWORD _                               ' __in  GpBrush *brush
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetBrushType IMPORT "GDIPLUS.DLL" ALIAS "GdipGetBrushType" ( _
   BYVAL brush AS DWORD _                               ' __in  GpBrush *brush
 , BYREF type AS LONG _                                 ' __out GpBrushType *type
 ) AS LONG                                              ' GpStatus

'//----------------------------------------------------------------------------
'// HatchBrush APIs
'//----------------------------------------------------------------------------

DECLARE FUNCTION GdipCreateHatchBrush IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateHatchBrush" ( _
   BYVAL hatchstyle AS LONG _                           ' __in  GpHatchStyle hatchstyle
 , BYVAL forecol AS DWORD _                             ' __in  ARGB forecol
 , BYVAL backcol AS DWORD _                             ' __in  ARGB backcol
 , BYREF brush AS DWORD _                               ' __out GpHatch **brush
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetHatchStyle IMPORT "GDIPLUS.DLL" ALIAS "GdipGetHatchStyle" ( _
   BYVAL brush AS DWORD _                               ' __in  GpHatch *brush
 , BYREF hatchstyle AS LONG _                           ' __out GpHatchStyle hatchstyle
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetHatchForegroundColor IMPORT "GDIPLUS.DLL" ALIAS "GdipGetHatchForegroundColor" ( _
   BYVAL brush AS DWORD _                               ' __in  GpHatch *brush
 , BYREF forecol AS DWORD _                             ' __out ARGB *forecol
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetHatchBackgroundColor IMPORT "GDIPLUS.DLL" ALIAS "GdipGetHatchBackgroundColor" ( _
   BYVAL brush AS DWORD _                               ' __in  GpHatch *brush
 , BYREF backcol AS DWORD _                             ' __out ARGB *backcol
 ) AS LONG                                              ' GpStatus

'//----------------------------------------------------------------------------
'// TextureBrush APIs
'//----------------------------------------------------------------------------

DECLARE FUNCTION GdipCreateTexture IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateTexture" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYVAL wrapmode AS LONG _                             ' __in  GpWrapMode wrapmode
 , BYREF texture AS DWORD _                             ' __out GpTexture **texture
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateTexture2 IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateTexture2" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYVAL wrapmode AS LONG _                             ' __in  GpWrapMode wrapmode
 , BYVAL x AS SINGLE _                                  ' __in  REAL x
 , BYVAL y AS SINGLE _                                  ' __in  REAL y
 , BYVAL width AS SINGLE _                              ' __in  REAL width
 , BYVAL height AS SINGLE _                             ' __in  REAL height
 , BYREF texture AS DWORD _                             ' __out GpTexture **texture
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateTextureIA IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateTextureIA" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYVAL imageAttributes AS DWORD _                     ' __in  GDIPCONST GpImageAttributes *imageAttributes
 , BYVAL x AS SINGLE _                                  ' __in  REAL x
 , BYVAL y AS SINGLE _                                  ' __in  REAL y
 , BYVAL width AS SINGLE _                              ' __in  REAL width
 , BYVAL height AS SINGLE _                             ' __in  REAL height
 , BYREF texture AS DWORD _                             ' __out GpTexture **texture
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateTexture2I IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateTexture2I" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYVAL wrapmode AS LONG _                             ' __in  GpWrapMode wrapmode
 , BYVAL x AS LONG _                                    ' __in  INT x
 , BYVAL y AS LONG _                                    ' __in  INT y
 , BYVAL width AS LONG _                                ' __in  INT width
 , BYVAL height AS LONG _                               ' __in  INT height
 , BYREF texture AS DWORD _                             ' __out GpTexture **texture
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateTextureIAI IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateTextureIAI" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYVAL imageAttributes AS DWORD _                     ' __in  GDIPCONST GpImageAttributes *imageAttributes
 , BYVAL x AS LONG _                                    ' __in  INT x
 , BYVAL y AS LONG _                                    ' __in  INT y
 , BYVAL width AS LONG _                                ' __in  INT width
 , BYVAL height AS LONG _                               ' __in  INT height
 , BYREF texture AS DWORD _                             ' __out GpTexture **texture
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetTextureTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipGetTextureTransform" ( _
   BYVAL brush AS DWORD _                               ' __in  GpTexture *brush
 , BYREF matrix AS DWORD _                              ' __out GpMatrix *matrix
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetTextureTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipSetTextureTransform" ( _
   BYVAL brush AS DWORD _                               ' __in GpTexture *brush
 , BYVAL matrix AS DWORD _                              ' __in GDIPCONST GpMatrix *matrix
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipResetTextureTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipResetTextureTransform" ( _
   BYVAL brush AS DWORD _                               ' __in GpTexture *brush
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipMultiplyTextureTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipMultiplyTextureTransform" ( _
   BYVAL brush AS DWORD _                               ' __in GpTexture *brush
 , BYVAL matrix AS DWORD _                              ' __in GDIPCONST GpMatrix *matrix
 , BYVAL order AS LONG _                                ' __in GpMatrixOrder order
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipTranslateTextureTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipTranslateTextureTransform" ( _
   BYVAL brush AS DWORD _                               ' __in GpTexture *brush
 , BYVAL dx AS SINGLE _                                 ' __in REAL dx
 , BYVAL dy AS SINGLE _                                 ' __in REAL dy
 , BYVAL order AS LONG _                                ' __in GpMatrixOrder order
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipScaleTextureTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipScaleTextureTransform" ( _
   BYVAL brush AS DWORD _                               ' __in GpTexture *brush
 , BYVAL sz AS SINGLE _                                 ' __in REAL sz
 , BYVAL sy AS SINGLE _                                 ' __in REAL sy
 , BYVAL order AS LONG _                                ' __in GpMatrixOrder order
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipRotateTextureTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipRotateTextureTransform" ( _
   BYVAL brush AS DWORD _                               ' __in GpTexture *brush
 , BYVAL angle AS SINGLE _                              ' __in REAL angle
 , BYVAL order AS LONG _                                ' __in GpMatrixOrder order
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetTextureWrapMode IMPORT "GDIPLUS.DLL" ALIAS "GdipSetTextureWrapMode" ( _
   BYVAL brush AS DWORD _                               ' __in GpTexture *brush
 , BYVAL wrapmode AS LONG _                             ' __in GpWrapMode wrapmode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetTextureWrapMode IMPORT "GDIPLUS.DLL" ALIAS "GdipGetTextureWrapMode" ( _
   BYVAL brush AS DWORD _                               ' __in GpTexture *brush
 , BYREF wrapmode AS LONG _                             ' __in GpWrapMode *wrapmode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetTextureImage IMPORT "GDIPLUS.DLL" ALIAS "GdipGetTextureImage" ( _
   BYVAL brush AS DWORD _                               ' __in  GpTexture *brush
 , BYREF image AS DWORD _                               ' __out GpImage **image
 ) AS LONG                                              ' GpStatus

'//----------------------------------------------------------------------------
'// SolidBrush APIs
'//----------------------------------------------------------------------------

DECLARE FUNCTION GdipCreateSolidFill IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateSolidFill" ( _
   BYVAL color AS DWORD _                               ' __in  ARGB color
 , BYREF brush AS DWORD _                               ' __out GpSolidFill **brush
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetSolidFillColor IMPORT "GDIPLUS.DLL" ALIAS "GdipSetSolidFillColor" ( _
   BYVAL brush AS DWORD _                               ' __in GpSolidFill *brush
 , BYVAL color AS DWORD _                               ' __in ARGB color
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetSolidFillColor IMPORT "GDIPLUS.DLL" ALIAS "GdipGetSolidFillColor" ( _
   BYVAL brush AS DWORD _                               ' __in  GpSolidFill *brush
 , BYREF color AS DWORD _                               ' __out ARGB *color
 ) AS LONG                                              ' GpStatus

'//----------------------------------------------------------------------------
'// LineBrush APIs
'//----------------------------------------------------------------------------

DECLARE FUNCTION GdipCreateLineBrush IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateLineBrush" ( _
   BYREF point1 AS GpPointF _                           ' __in  GDIPCONST GpPointF *point1
 , BYREF point2 AS GpPointF _                           ' __in  GDIPCONST GpPointF *point2
 , BYVAL color1 AS DWORD _                              ' __in  ARGB color1
 , BYVAL color2 AS DWORD _                              ' __in  ARGB color2
 , BYVAL wrapmode AS LONG _                             ' __in  GpWrapMode wrapmode
 , BYREF lineGradient AS DWORD _                        ' __out GpLineGradient **lineGradient
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateLineBrushI IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateLineBrushI" ( _
   BYREF GpPoint _                                      ' __in  GDIPCONST GpPoint* point1
 , BYREF GpPoint _                                      ' __in  GDIPCONST GpPoint* point2
 , BYVAL color1 AS DWORD _                              ' __in  ARGB color1
 , BYVAL color2 AS DWORD _                              ' __in  ARGB color2
 , BYVAL wrapmode AS LONG _                             ' __in  GpWrapMode wrapmode
 , BYREF lineGradient AS DWORD _                        ' __out GpLineGradient **lineGradient
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateLineBrushFromRect IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateLineBrushFromRect" ( _
   BYREF rect AS GpRectF _                              ' __in  GDIPCONST GpRectF *rect
 , BYVAL color1 AS DWORD _                              ' __in  ARGB color1
 , BYVAL color2 AS DWORD _                              ' __in  ARGB color2
 , BYVAL mode AS LONG _                                 ' __in  LinearGradientMode mode
 , BYVAL wrapmode AS LONG _                             ' __in  GpWrapMode wrapmode
 , BYREF lineGradient AS DWORD _                        ' __out GpLineGradient **lineGradient
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateLineBrushFromRectI IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateLineBrushFromRectI" ( _
   BYREF rect AS GpRect _                               ' __in  GDIPCONST GpRect *rect
 , BYVAL color1 AS DWORD _                              ' __in  ARGB color1
 , BYVAL color2 AS DWORD _                              ' __in  ARGB color2
 , BYVAL mode AS LONG _                                 ' __in  LinearGradientMode mode
 , BYVAL wrapmode AS LONG _                             ' __in  GpWrapMode wrapmode
 , BYREF lineGradient AS DWORD _                        ' __out GpLineGradient **lineGradient
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateLineBrushFromRectWithAngle IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateLineBrushFromRectWithAngle" ( _
   BYREF rect AS GpRectF _                              ' __in  GDIPCONST GpRectF *rect
 , BYVAL color1 AS DWORD _                              ' __in  ARGB color1
 , BYVAL color2 AS DWORD _                              ' __in  ARGB color2
 , BYVAL angle AS SINGLE _                              ' __in  REAL angle
 , BYVAL isAngleScalable AS LONG _                      ' __in  BOOL isAngleScalable
 , BYVAL wrapmode AS LONG _                             ' __in  GpWrapMode wrapmode
 , BYREF lineGradient AS DWORD _                        ' __out GpLineGradient **lineGradient
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateLineBrushFromRectWithAngleI IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateLineBrushFromRectWithAngleI" ( _
   BYREF rect AS GpRect _                               ' __in  GDIPCONST GpRect *rect
 , BYVAL color1 AS DWORD _                              ' __in  ARGB color1
 , BYVAL color2 AS DWORD _                              ' __in  ARGB color2
 , BYVAL angle AS SINGLE _                              ' __in  REAL angle
 , BYVAL isAngleScalable AS LONG _                      ' __in  BOOL isAngleScalable
 , BYVAL wrapmode AS LONG _                             ' __in  GpWrapMode wrapmode
 , BYREF lineGradient AS DWORD _                        ' __out GpLineGradient **lineGradient
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetLineColors IMPORT "GDIPLUS.DLL" ALIAS "GdipSetLineColors" ( _
   BYVAL brush AS DWORD _                               ' __in  GpLineGradient *brush
 , BYVAL color1 AS DWORD _                              ' __in  ARGB color1
 , BYVAL color2 AS DWORD _                              ' __in  ARGB color2
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetLineColors IMPORT "GDIPLUS.DLL" ALIAS "GdipGetLineColors" ( _
   BYVAL brush AS DWORD _                               ' __in  GpLineGradient *brush
 , BYREF colors AS DWORD _                              ' __out ARGB *colors
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetLineRect IMPORT "GDIPLUS.DLL" ALIAS "GdipGetLineRect" ( _
   BYVAL brush AS DWORD _                               ' __in  GpLineGradient *brush
 , BYREF rect AS GpRectF _                              ' __out GpRectF *rect
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetLineRectI IMPORT "GDIPLUS.DLL" ALIAS "GdipGetLineRectI" ( _
   BYVAL brush AS DWORD _                               ' __in  GpLineGradient *brush
 , BYREF rect AS GpRect _                               ' __out GpRect *rect
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetLineGammaCorrection IMPORT "GDIPLUS.DLL" ALIAS "GdipSetLineGammaCorrection" ( _
   BYVAL brush AS DWORD _                               ' __in  GpLineGradient *brush
 , BYVAL useGammaCorrection AS LONG _                   ' __in  BOOL useGammaCorrection
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetLineGammaCorrection IMPORT "GDIPLUS.DLL" ALIAS "GdipGetLineGammaCorrection" ( _
   BYVAL brush AS DWORD _                               ' __in  GpLineGradient *brush
 , BYREF useGammaCorrection AS LONG _                   ' __out BOOL *useGammaCorrection
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetLineBlendCount IMPORT "GDIPLUS.DLL" ALIAS "GdipGetLineBlendCount" ( _
   BYVAL brush AS DWORD _                               ' __in  GpLineGradient *brush
 , BYREF count AS LONG _                                ' __out INT *count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetLineBlend IMPORT "GDIPLUS.DLL" ALIAS "GdipGetLineBlend" ( _
   BYVAL brush AS DWORD _                               ' __in  GpLineGradient *brush
 , BYREF blend AS SINGLE _                              ' __out REAL *blend
 , BYREF positions AS SINGLE _                          ' __out REAL *positions
 , BYVAL count AS LONG _                                ' __in  INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetLineBlend IMPORT "GDIPLUS.DLL" ALIAS "GdipSetLineBlend" ( _
   BYVAL brush AS DWORD _                               ' __in GpLineGradient *brush
 , BYREF blend AS SINGLE _                              ' __in GDIPCONST REAL *blend
 , BYREF positions AS SINGLE _                          ' __in GDIPCONST REAL *positions
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetLinePresetBlendCount IMPORT "GDIPLUS.DLL" ALIAS "GdipGetLinePresetBlendCount" ( _
   BYVAL brush AS DWORD _                               ' __in  GpLineGradient *brush
 , BYREF count AS LONG _                                ' __out INT *count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetLinePresetBlend IMPORT "GDIPLUS.DLL" ALIAS "GdipGetLinePresetBlend" ( _
   BYVAL brush AS DWORD _                               ' __in  GpLineGradient *brush
 , BYREF blend AS DWORD _                               ' __out ARGB *blend
 , BYREF positions AS SINGLE _                          ' __out REAL *positions
 , BYVAL count AS LONG _                                ' __in  INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetLinePresetBlend IMPORT "GDIPLUS.DLL" ALIAS "GdipSetLinePresetBlend" ( _
   BYVAL brush AS DWORD _                               ' __in  GpLineGradient *brush
 , BYREF blend AS DWORD _                               ' __out GDIPCONST ARGB *blend
 , BYREF positions AS SINGLE _                          ' __out GDIPCONST REAL *positions
 , BYVAL count AS LONG _                                ' __in  INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetLineSigmaBlend IMPORT "GDIPLUS.DLL" ALIAS "GdipSetLineSigmaBlend" ( _
   BYVAL brush AS DWORD _                               ' __in GpLineGradient *brush
 , BYVAL focus AS SINGLE _                              ' __in REAL focus
 , BYVAL scale AS SINGLE _                              ' __in REAL scale
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetLineLinearBlend IMPORT "GDIPLUS.DLL" ALIAS "GdipSetLineLinearBlend" ( _
   BYVAL brush AS DWORD _                               ' __in GpLineGradient *brush
 , BYVAL focus AS SINGLE _                              ' __in REAL focus
 , BYVAL scale AS SINGLE _                              ' __in REAL scale
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetLineWrapMode IMPORT "GDIPLUS.DLL" ALIAS "GdipSetLineWrapMode" ( _
   BYVAL brush AS DWORD _                               ' __in GpLineGradient *brush
 , BYVAL wrapmode AS LONG _                             ' __in GpWrapMode wrapmode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetLineWrapMode IMPORT "GDIPLUS.DLL" ALIAS "GdipGetLineWrapMode" ( _
   BYVAL brush AS DWORD _                               ' __in  GpLineGradient *brush
 , BYREF wrapmode AS LONG _                             ' __out GpWrapMode *wrapmode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetLineTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipGetLineTransform" ( _
   BYVAL brush AS DWORD _                               ' __in  GpLineGradient *brush
 , BYREF matrix AS DWORD _                              ' __out GpMatrix *matrix
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetLineTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipSetLineTransform" ( _
   BYVAL brush AS DWORD _                               ' __in GpLineGradient *brush
 , BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipResetLineTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipResetLineTransform" ( _
   BYVAL brush AS DWORD _                               ' __in GpLineGradient *brush
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipMultiplyLineTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipMultiplyLineTransform" ( _
   BYVAL brush AS DWORD _                               ' __in GpLineGradient *brush
 , BYVAL matrix AS DWORD _                              ' __in GDIPCONST GpMatrix *matrix
 , BYVAL order AS LONG _                                ' __in GpMatrixOrder order
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipTranslateLineTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipTranslateLineTransform" ( _
   BYVAL brush AS DWORD _                               ' __in GpLineGradient *brush
 , BYVAL dx AS SINGLE _                                 ' __in REAL dx
 , BYVAL dy AS SINGLE _                                 ' __in REAL dy
 , BYVAL order AS LONG _                                ' __in GpMatrixOrder order
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipScaleLineTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipScaleLineTransform" ( _
   BYVAL brush AS DWORD _                               ' __in GpLineGradient *brush
 , BYVAL sx AS SINGLE _                                 ' __in REAL sx
 , BYVAL sy AS SINGLE _                                 ' __in REAL sy
 , BYVAL order AS LONG _                                ' __in GpMatrixOrder order
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipRotateLineTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipRotateLineTransform" ( _
   BYVAL brush AS DWORD _                               ' __in GpLineGradient *brush
 , BYVAL angle AS SINGLE _                              ' __in REAL angle
 , BYVAL order AS LONG _                                ' __in GpMatrixOrder order
 ) AS LONG                                              ' GpStatus

'//----------------------------------------------------------------------------
'// PathGradientBrush APIs
'//----------------------------------------------------------------------------

DECLARE FUNCTION GdipCreatePathGradient IMPORT "GDIPLUS.DLL" ALIAS "GdipCreatePathGradient" ( _
   BYREF points AS GpPointF _                           ' __in  GDIPCONST GpPointF *points
 , BYVAL count AS LONG _                                ' __in  INT count
 , BYVAL wrapmode AS LONG _                             ' __in  GpWrapMode wrapmode
 , BYREF polyGradient AS DWORD _                        ' __out GpPathGradient **polyGradient
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreatePathGradientI IMPORT "GDIPLUS.DLL" ALIAS "GdipCreatePathGradientI" ( _
   BYREF points AS GpPoint _                            ' __in  GDIPCONST GpPoint *points
 , BYVAL count AS LONG _                                ' __in  INT count
 , BYVAL wrapmode AS LONG _                             ' __in  GpWrapMode wrapmode
 , BYREF polyGradient AS DWORD _                        ' __out GpPathGradient **polyGradient
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreatePathGradientFromPath IMPORT "GDIPLUS.DLL" ALIAS "GdipCreatePathGradientFromPath" ( _
   BYVAL path AS DWORD _                                ' __in  GpPath *path
 , BYREF polyGradient AS DWORD _                        ' __out GpPathGradient **polyGradient
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathGradientCenterColor IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathGradientCenterColor" ( _
   BYVAL brush AS DWORD _                               ' __in  GpPathGradient *brush
 , BYREF color AS DWORD _                               ' __out ARGB *colors
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPathGradientCenterColor IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPathGradientCenterColor" ( _
   BYVAL brush AS DWORD _                               ' __in  GpPathGradient *brush
 , BYVAL colors AS DWORD _                              ' __in  ARGB colors
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathGradientSurroundColorsWithCount IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathGradientSurroundColorsWithCount" ( _
   BYVAL brush AS DWORD _                               ' __in  GpPathGradient *brush
 , BYREF color AS DWORD _                               ' __out ARGB *color
 , BYREF count AS LONG _                                ' __out INT *count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPathGradientSurroundColorsWithCount IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPathGradientSurroundColorsWithCount" ( _
   BYVAL brush AS DWORD _                               ' __in  GpPathGradient *brush
 , BYREF color AS DWORD _                               ' __out GDIPCONST ARGB *color
 , BYREF count AS LONG _                                ' __out INT *count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathGradientPath IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathGradientPath" ( _
   BYVAL brush AS DWORD _                               ' __in  GpPathGradient *brush
 , BYREF path AS DWORD _                                ' __out GpPath *path
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPathGradientPath IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPathGradientPath" ( _
   BYVAL brush AS DWORD _                               ' __in  GpPathGradient *brush
 , BYVAL path AS DWORD _                                ' __in  GDIPCONST GpPath *path
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathGradientCenterPoint IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathGradientCenterPoint" ( _
   BYVAL brush AS DWORD _                               ' __in  GpPathGradient *brush
 , BYREF points AS GpPointF _                           ' __out GpPointF *points
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathGradientCenterPointI IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathGradientCenterPointI" ( _
   BYVAL brush AS DWORD _                               ' __in  GpPathGradient *brush
 , BYREF points AS GpPoint _                            ' __out GpPoint* points
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPathGradientCenterPoint IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPathGradientCenterPoint" ( _
   BYVAL brush AS DWORD _                               ' __in GpPathGradient *brush
 , BYREF points AS GpPointF _                           ' __in GDIPCONST GpPointF *points
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPathGradientCenterPointI IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPathGradientCenterPointI" ( _
   BYVAL brush AS DWORD _                               ' __in GpPathGradient *brush
 , BYREF points AS GpPoint _                            ' __in GDIPCONST GpPoint *points
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathGradientRect IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathGradientRect" ( _
   BYVAL brush AS DWORD _                               ' __in  GpPathGradient *brush
 , BYREF rect AS GpRectF _                              ' __out GpRectF *rect
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathGradientRectI IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathGradientRectI" ( _
   BYVAL brush AS DWORD _                               ' __in  GpPathGradient *brush
 , BYREF rect AS GpRect _                               ' __out GpRect *rect
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathGradientPointCount IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathGradientPointCount" ( _
   BYVAL brush AS DWORD _                               ' __in  GpPathGradient *brush
 , BYREF count AS LONG _                                ' __out INT *count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathGradientSurroundColorCount IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathGradientSurroundColorCount" ( _
   BYVAL brush AS DWORD _                               ' __in  GpPathGradient *brush
 , BYREF count AS LONG _                                ' __out INT *count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPathGradientGammaCorrection IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPathGradientGammaCorrection" ( _
   BYVAL brush AS DWORD _                               ' __in GpPathGradient *brush
 , BYVAL useGammaCorrection AS LONG _                   ' __in BOOL useGammaCorrection
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathGradientGammaCorrection IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathGradientGammaCorrection" ( _
   BYVAL brush AS DWORD _                               ' __in  GpPathGradient *brush
 , BYREF useGammaCorrection AS LONG _                   ' __out BOOL *useGammaCorrection
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathGradientBlendCount IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathGradientBlendCount" ( _
   BYVAL brush AS DWORD _                               ' __in  GpPathGradient *brush
 , BYREF count AS LONG _                                ' __out INT *count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathGradientBlend IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathGradientBlend" ( _
   BYVAL brush AS DWORD _                               ' __in  GpPathGradient *brush
 , BYREF blend AS SINGLE _                              ' __out REAL *blend
 , BYREF positions AS SINGLE _                          ' __out REAL *positions
 , BYVAL count AS LONG _                                ' __in  INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPathGradientBlend IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPathGradientBlend" ( _
   BYVAL brush AS DWORD _                               ' __in  GpPathGradient *brush
 , BYREF blend AS SINGLE _                              ' __out GDIPCONST REAL *blend
 , BYREF positions AS SINGLE _                          ' __out GDIPCONST REAL *positions
 , BYVAL count AS LONG _                                ' __in  INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathGradientPresetBlendCount IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathGradientPresetBlendCount" ( _
   BYVAL brush AS DWORD _                               ' __in  GpPathGradient *brush
 , BYREF count AS LONG _                                ' __out INT *count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathGradientPresetBlend IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathGradientPresetBlend" ( _
   BYVAL brush AS DWORD _                               ' __in  GpPathGradient *brush
 , BYREF blend AS DWORD _                               ' __out ARGB *blend
 , BYREF positions AS SINGLE _                          ' __out REAL *positions
 , BYVAL count AS LONG _                                ' __in  INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPathGradientPresetBlend IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPathGradientPresetBlend" ( _
   BYVAL brush AS DWORD _                               ' __in  GpPathGradient *brush
 , BYREF blend AS DWORD _                               ' __out GDIPCONST ARGB *blend
 , BYREF positions AS SINGLE _                          ' __out GDIPCONST REAL *positions
 , BYVAL count AS LONG _                                ' __in  INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPathGradientSigmaBlend IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPathGradientSigmaBlend" ( _
   BYVAL brush AS DWORD _                               ' __in GpPathGradient *brush
 , BYVAL focus AS SINGLE _                              ' __in REAL focus
 , BYVAL scale AS SINGLE _                              ' __in REAL scale
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPathGradientLinearBlend IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPathGradientLinearBlend" ( _
   BYVAL brush AS DWORD _                               ' __in GpPathGradient *brush
 , BYVAL focus AS SINGLE _                              ' __in REAL focus
 , BYVAL scale AS SINGLE _                              ' __in REAL scale
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathGradientWrapMode IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathGradientWrapMode" ( _
   BYVAL brush AS DWORD _                               ' __in  GpPathGradient *brush
 , BYREF wrapmode AS LONG _                             ' __out GpWrapMode *wrapmode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPathGradientWrapMode IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPathGradientWrapMode" ( _
   BYVAL brush AS DWORD _                               ' __in GpPathGradient *brush
 , BYVAL wrapmode AS LONG _                             ' __in GpWrapMode wrapmode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathGradientTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathGradientTransform" ( _
   BYVAL brush AS DWORD _                               ' __in  GpPathGradient *brush
 , BYREF matrix AS DWORD _                              ' __out GpMatrix *matrix
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPathGradientTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPathGradientTransform" ( _
   BYVAL brush AS DWORD _                               ' __in GpPathGradient *brush
 , BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipResetPathGradientTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipResetPathGradientTransform" ( _
   BYVAL brush AS DWORD _                               ' __in GpPathGradient *brush
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipMultiplyPathGradientTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipMultiplyPathGradientTransform" ( _
   BYVAL brush AS DWORD _                               ' __in GpPathGradient *brush
 , BYVAL matrix AS DWORD _                              ' __in GDIPCONST GpMatrix *matrix
 , BYVAL order AS LONG _                                ' __in GpMatrixOrder order
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipTranslatePathGradientTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipTranslatePathGradientTransform" ( _
   BYVAL brush AS DWORD _                               ' __in GpPathGradient *brush
 , BYVAL dx AS SINGLE _                                 ' __in REAL dx
 , BYVAL dy AS SINGLE _                                 ' __in REAL dy
 , BYVAL order AS LONG _                                ' __in GpMatrixOrder order
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipScalePathGradientTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipScalePathGradientTransform" ( _
   BYVAL brush AS DWORD _                               ' __in GpPathGradient *brush
 , BYVAL sx AS SINGLE _                                 ' __in REAL sx
 , BYVAL sy AS SINGLE _                                 ' __in REAL sy
 , BYVAL order AS LONG _                                ' __in GpMatrixOrder order
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipRotatePathGradientTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipRotatePathGradientTransform" ( _
   BYVAL brush AS DWORD _                               ' __in GpPathGradient *brush
 , BYVAL angle AS SINGLE _                              ' __in REAL angle
 , BYVAL order AS LONG _                                ' __in GpMatrixOrder order
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPathGradientFocusScales IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPathGradientFocusScales" ( _
   BYVAL brush AS DWORD _                               ' __in  GpPathGradient *brush
 , BYREF xScale AS SINGLE _                             ' __out REAL *xScale
 , BYREF yScale AS SINGLE _                             ' __out REAL *yScale
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPathGradientFocusScales IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPathGradientFocusScales" ( _
   BYVAL brush AS DWORD _                               ' __in GpPathGradient *brush
 , BYVAL xScale AS SINGLE _                             ' __in REAL xScale
 , BYVAL yScale AS SINGLE _                             ' __in REAL yScale
 ) AS LONG                                              ' GpStatus

'//----------------------------------------------------------------------------
'// Pen APIs
'//----------------------------------------------------------------------------

DECLARE FUNCTION GdipCreatePen1 IMPORT "GDIPLUS.DLL" ALIAS "GdipCreatePen1" ( _
   BYVAL color AS DWORD _                               ' __in  ARGB color
 , BYVAL width AS SINGLE _                              ' __in  REAL width
 , BYVAL unit AS LONG _                                 ' __in GpUnit unit
 , BYREF pen AS DWORD _                                 ' __out GpPen **pen
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreatePen2 IMPORT "GDIPLUS.DLL" ALIAS "GdipCreatePen2" ( _
   BYVAL brush AS DWORD _                               ' __in  GpBrush *brush
 , BYVAL width AS SINGLE _                              ' __in  REAL width
 , BYVAL unit AS LONG _                                 ' __in  GpUnit unit
 , BYREF pen AS DWORD _                                 ' __out GpPen **pen
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipClonePen IMPORT "GDIPLUS.DLL" ALIAS "GdipClonePen" ( _
   BYVAL pen AS DWORD _                                 ' __in  GpPen *pen
 , BYREF clonepen AS DWORD _                            ' __out GpPen **clonepen
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDeletePen IMPORT "GDIPLUS.DLL" ALIAS "GdipDeletePen" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPenWidth IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPenWidth" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL width AS SINGLE _                              ' __in REAL width
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPenWidth IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPenWidth" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYREF width AS SINGLE _                              ' __in REAL *width
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPenUnit IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPenUnit" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL unit AS LONG _                                 ' __in GpUnit unit
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPenUnit IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPenUnit" ( _
   BYVAL pen AS DWORD _                                 ' __in  GpPen *pen
 , BYREF unit AS LONG _                                 ' __out GpUnit *unit
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPenLineCap197819 IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPenLineCap197819" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL startCap AS LONG _                             ' __in GpLineCap startCap
 , BYVAL endCap AS LONG _                               ' __in GpLineCap endCap
 , BYVAL dashCap AS LONG _                              ' __in DashCap dashCap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPenStartCap IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPenStartCap" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL startCap AS LONG _                             ' __in GpLineCap startCap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPenEndCap IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPenEndCap" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL endCap AS LONG _                               ' __in GpLineCap endCap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPenDashCap197819 IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPenDashCap197819" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL dashCap AS LONG _                              ' __in GpDashCap dashCap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPenStartCap IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPenStartCap" ( _
   BYVAL pen AS DWORD _                                 ' __in  GpPen *pen
 , BYREF startCap AS LONG _                             ' __out GpLineCap *startCap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPenEndCap IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPenEndCap" ( _
   BYVAL pen AS DWORD _                                 ' __in  GpPen *pen
 , BYREF startCap AS LONG _                             ' __out GpLineCap *startCap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPenDashCap197819 IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPenDashCap197819" ( _
   BYVAL pen AS DWORD _                                 ' __in  GpPen *pen
 , BYREF dashCap AS LONG _                              ' __out DashCap *dashCap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPenLineJoin IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPenLineJoin" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL lineJoin AS LONG _                             ' __in GpLineJoin lineJoin
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPenLineJoin IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPenLineJoin" ( _
   BYVAL pen AS DWORD _                                 ' __in  GpPen *pen
 , BYREF lineJoin AS LONG _                             ' __out GpLineJoin *lineJoin
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPenCustomStartCap IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPenCustomStartCap" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL customCap AS DWORD _                           ' __in GpCustomLineCap *customCap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPenCustomStartCap IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPenCustomStartCap" ( _
   BYVAL pen AS DWORD _                                 ' __in  GpPen *pen
 , BYREF customCap AS DWORD _                           ' __out GpCustomLineCap **customCap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPenCustomEndCap IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPenCustomEndCap" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL customCap AS DWORD _                           ' __in GpCustomLineCap *customCap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPenCustomEndCap IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPenCustomEndCap" ( _
   BYVAL pen AS DWORD _                                 ' __in  GpPen *pen
 , BYREF customCap AS DWORD _                           ' __out GpCustomLineCap **customCap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPenMiterLimit IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPenMiterLimit" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL miterLimit AS SINGLE _                         ' __in REAL miterLimit
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPenMiterLimit IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPenMiterLimit" ( _
   BYVAL pen AS DWORD _                                 ' __in  GpPen *pen
 , BYREF miterLimit aS SINGLE _                         ' __out REAL *miterLimit
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPenMode IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPenMode" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL penMode AS LONG _                              ' __in GpPenAlignment penMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPenMode IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPenMode" ( _
   BYVAL pen AS DWORD _                                 ' __in  GpPen *pen
 , BYREF penMode AS LONG _                              ' __out GpPenAlignment *penMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPenTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPenTransform" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPenTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPenTransform" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYREF matrix AS DWORD _                              ' __in GpMatrix *matrix
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipResetPenTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipResetPenTransform" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipMultiplyPenTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipMultiplyPenTransform" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL matrix AS DWORD _                              ' __in GDIPCONST GpMatrix *matrix
 , BYVAL order AS LONG _                                ' __in GpMatrix order
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipTranslatePenTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipTranslatePenTransform" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL dx AS SINGLE _                                 ' __in REAL dx
 , BYVAL dy AS SINGLE _                                 ' __in REAL dy
 , BYVAL order AS LONG _                                ' __in GpMatrix order
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipScalePenTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipScalePenTransform" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL sx AS SINGLE _                                 ' __in REAL sx
 , BYVAL sy AS SINGLE _                                 ' __in REAL sy
 , BYVAL order AS LONG _                                ' __in GpMatrix order
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipRotatePenTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipRotatePenTransform" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL angle AS SINGLE _                              ' __in REAL angle
 , BYVAL order AS LONG _                                ' __in GpMatrix order
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPenColor IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPenColor" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL argb AS DWORD _                                ' __in ARGB argb
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPenColor IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPenColor" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYREF argb AS DWORD _                                ' __out ARGB *argb
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPenBrushFill IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPenBrushFill" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL brush AS DWORD _                               ' __in GpBrush *brush
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPenBrushFill IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPenBrushFill" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYREF brush AS DWORD _                               ' __out GpBrush **brush
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPenFillType IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPenFillType" ( _
   BYVAL pen AS DWORD _                                 ' __in  GpPen *pen
 , BYREF type AS LONG _                                 ' __out GpPenType *type
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPenDashStyle IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPenDashStyle" ( _
   BYVAL pen AS DWORD _                                 ' __in  GpPen *pen
 , BYREF dashstyle AS LONG _                            ' __out GpDashStyle *dashstyle
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPenDashStyle IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPenDashStyle" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL dashstyle AS LONG _                            ' __in GpDashStyle dashstyle
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPenDashOffset IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPenDashOffset" ( _
   BYVAL pen AS DWORD _                                 ' __in  GpPen *pen
 , BYREF offset AS SINGLE _                             ' __out REAL *offset
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPenDashOffset IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPenDashOffset" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL offset AS SINGLE _                             ' __in REAL offset
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPenDashCount IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPenDashCount" ( _
   BYVAL pen AS DWORD _                                 ' __in  GpPen *pen
 , BYREF count AS LONG _                                ' __out INT *count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPenDashArray IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPenDashArray" ( _
   BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYREF dash AS SINGLE _                               ' __in GDIPCONST REAL *dash
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPenDashArray IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPenDashArray" ( _
   BYVAL pen AS DWORD _                                 ' __in  GpPen *pen
 , BYREF dash AS SINGLE _                               ' __out REAL *dash
 , BYVAL count AS LONG _                                ' __in  INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPenCompoundCount IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPenCompoundCount" ( _
   BYVAL pen AS DWORD _                                 ' __in  GpPen *pen
 , BYREF count AS LONG _                                ' __out INT *count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPenCompoundArray IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPenCompoundArray" ( _
   BYVAL pen AS DWORD _                                 ' __in  GpPen *pen
 , BYREF dash AS SINGLE _                               ' __out GDIPCONST REAL *dash
 , BYVAL count AS LONG _                                ' __in  INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPenCompoundArray IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPenCompoundArray" ( _
   BYVAL pen AS DWORD _                                 ' __in  GpPen *pen
 , BYREF dash AS SINGLE _                               ' __out REAL *dash
 , BYVAL count AS LONG _                                ' __in  INT count
 ) AS LONG                                              ' GpStatus

'//----------------------------------------------------------------------------
'// CustomLineCap APIs
'//----------------------------------------------------------------------------

DECLARE FUNCTION GdipCreateCustomLineCap IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateCustomLineCap" ( _
   BYVAL fillPath AS DWORD _                            ' __in  GpPath *fillPath
 , BYVAL strokePath AS DWORD _                          ' __in  GpPath *strokePath
 , BYVAL baseCap AS LONG _                              ' __in  GpLineCap baseCap
 , BYVAL baseInset AS SINGLE _                          ' __in  REAL baseInset
 , BYREF customCap AS DWORD _                           ' __out GpCustomLineCap **customCap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDeleteCustomLineCap IMPORT "GDIPLUS.DLL" ALIAS "GdipDeleteCustomLineCap" ( _
   BYVAL customCap AS DWORD _                           ' __in GpCustomLineCap *customCap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCloneCustomLineCap IMPORT "GDIPLUS.DLL" ALIAS "GdipCloneCustomLineCap" ( _
   BYVAL customCap AS DWORD _                           ' __in  GpCustomLineCap *customCap
 , BYREF clonedCap AS DWORD _                           ' __out GpCustomLineCap **clonedCap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetCustomLineCapType IMPORT "GDIPLUS.DLL" ALIAS "GdipGetCustomLineCapType" ( _
   BYVAL customCap AS DWORD _                           ' __in  GpCustomLineCap *customCap
 , BYREF capType AS LONG _                              ' __out CustomLineCapType *capType
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetCustomLineCapStrokeCaps IMPORT "GDIPLUS.DLL" ALIAS "GdipSetCustomLineCapStrokeCaps" ( _
   BYVAL customCap AS DWORD _                           ' __in GpCustomLineCap *customCap
 , BYVAL startCap AS LONG _                             ' __in GpLineCap startCap
 , BYVAL endCap AS LONG _                               ' __in GpLineCap endCap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetCustomLineCapStrokeCaps IMPORT "GDIPLUS.DLL" ALIAS "GdipGetCustomLineCapStrokeCaps" ( _
   BYVAL customCap AS DWORD _                           ' __in  GpCustomLineCap *customCap
 , BYREF startCap AS LONG _                             ' __out GpLineCap *startCap
 , BYREF endCap AS LONG _                               ' __out GpLineCap *endCap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetCustomLineCapStrokeJoin IMPORT "GDIPLUS.DLL" ALIAS "GdipSetCustomLineCapStrokeJoin" ( _
   BYVAL customCap AS DWORD _                           ' __in GpCustomLineCap *customCap
 , BYVAL lineJoin AS LONG _                             ' __in GpLineJoin lineJoin
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetCustomLineCapStrokeJoin IMPORT "GDIPLUS.DLL" ALIAS "GdipGetCustomLineCapStrokeJoin" ( _
   BYVAL customCap AS DWORD _                           ' __in  GpCustomLineCap *customCap
 , BYREF lineJoin AS LONG _                             ' __out GpLineJoin *lineJoin
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetCustomLineCapBaseCap IMPORT "GDIPLUS.DLL" ALIAS "GdipSetCustomLineCapBaseCap" ( _
   BYVAL customCap AS DWORD _                           ' __in GpCustomLineCap *customCap
 , BYVAL baseCap AS LONG _                              ' __in GpLineCap baseCap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetCustomLineCapBaseCap IMPORT "GDIPLUS.DLL" ALIAS "GdipGetCustomLineCapBaseCap" ( _
   BYVAL customCap AS DWORD _                           ' __in  GpCustomLineCap *customCap
 , BYREF baseCap AS LONG _                              ' __out GpLineCap *baseCap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetCustomLineCapBaseInset IMPORT "GDIPLUS.DLL" ALIAS "GdipSetCustomLineCapBaseInset" ( _
   BYVAL customCap AS DWORD _                           ' __in GpCustomLineCap *customCap
 , BYVAL inset AS SINGLE _                              ' __in REAL inset
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetCustomLineCapBaseInset IMPORT "GDIPLUS.DLL" ALIAS "GdipGetCustomLineCapBaseInset" ( _
   BYVAL customCap AS DWORD _                           ' __in  GpCustomLineCap *customCap
 , BYREF inset AS SINGLE _                              ' __out REAL *inset
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetCustomLineCapWidthScale IMPORT "GDIPLUS.DLL" ALIAS "GdipSetCustomLineCapWidthScale" ( _
   BYVAL customCap AS DWORD _                           ' __in GpCustomLineCap *customCap
 , BYVAL width AS SINGLE _                              ' __in REAL widthScale
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetCustomLineCapWidthScale IMPORT "GDIPLUS.DLL" ALIAS "GdipGetCustomLineCapWidthScale" ( _
   BYVAL customCap AS DWORD _                           ' __in  GpCustomLineCap *customCap
 , BYREF widthScale AS SINGLE _                         ' __out REAL *widthScale
 ) AS LONG                                              ' GpStatus

'//----------------------------------------------------------------------------
'// AdjustableArrowCap APIs
'//----------------------------------------------------------------------------

DECLARE FUNCTION GdipCreateAdjustableArrowCap IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateAdjustableArrowCap" ( _
   BYVAL height AS SINGLE _                             ' __in  REAL height
 , BYVAL width AS SINGLE _                              ' __in  REAL width
 , BYVAL isFilled AS LONG _                             ' __in  BOOL isFilled
 , BYREF cap AS DWORD _                                 ' __out GpAdjustableArrowCap **cap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetAdjustableArrowCapHeight IMPORT "GDIPLUS.DLL" ALIAS "GdipSetAdjustableArrowCapHeight" ( _
   BYVAL cap AS DWORD _                                 ' __in GpAdjustableArrowCap *cap
 , BYVAL height AS SINGLE _                             ' __in REAL height
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetAdjustableArrowCapHeight IMPORT "GDIPLUS.DLL" ALIAS "GdipGetAdjustableArrowCapHeight" ( _
   BYVAL cap AS DWORD _                                 ' __in  GpAdjustableArrowCap *cap
 , BYREF height AS SINGLE _                             ' __out REAL *height
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetAdjustableArrowCapWidth IMPORT "GDIPLUS.DLL" ALIAS "GdipSetAdjustableArrowCapWidth" ( _
   BYVAL cap AS DWORD _                                 ' __in GpAdjustableArrowCap *cap
 , BYVAL width AS SINGLE _                              ' __in REAL width
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetAdjustableArrowCapWidth IMPORT "GDIPLUS.DLL" ALIAS "GdipGetAdjustableArrowCapWidth" ( _
   BYVAL cap AS DWORD _                                 ' __in  GpAdjustableArrowCap *cap
 , BYREF width AS SINGLE _                              ' __out REAL *width
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetAdjustableArrowCapMiddleInset IMPORT "GDIPLUS.DLL" ALIAS "GdipSetAdjustableArrowCapMiddleInset" ( _
   BYVAL cap AS DWORD _                                 ' __in GpAdjustableArrowCap *cap
 , BYVAL middleInset AS SINGLE _                        ' __in REAL middleInset
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetAdjustableArrowCapMiddleInset IMPORT "GDIPLUS.DLL" ALIAS "GdipGetAdjustableArrowCapMiddleInset" ( _
   BYVAL cap AS DWORD _                                 ' __in  GpAdjustableArrowCap *cap
 , BYREF middleInset AS SINGLE _                        ' __out REAL *middleInset
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetAdjustableArrowCapFillState IMPORT "GDIPLUS.DLL" ALIAS "GdipSetAdjustableArrowCapFillState" ( _
   BYVAL cap AS DWORD _                                 ' __in GpAdjustableArrowCap *cap
 , BYVAL fillState AS LONG _                            ' __in BOOL fillState
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetAdjustableArrowCapFillState IMPORT "GDIPLUS.DLL" ALIAS "GdipGetAdjustableArrowCapFillState" ( _
   BYVAL cap AS DWORD _                                 ' __in  GpAdjustableArrowCap *cap
 , BYREF fillState AS LONG _                            ' __out BOOL *fillState
 ) AS LONG                                              ' GpStatus

'//----------------------------------------------------------------------------
'// Image APIs
'//----------------------------------------------------------------------------

DECLARE FUNCTION GdipLoadImageFromStream IMPORT "GDIPLUS.DLL" ALIAS "GdipLoadImageFromStream" ( _
   BYVAL stream AS IStream _                            ' __in  IStream *stream
 , BYREF image AS DWORD _                               ' __out GpImage **image
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipLoadImageFromFile IMPORT "GDIPLUS.DLL" ALIAS "GdipLoadImageFromFile" ( _
   BYREF filename AS WSTRINGZ _                         ' __in  GDIPCONST WCHAR *filename
 , BYREF image AS DWORD _                               ' __out GpImage **image
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipLoadImageFromStreamICM IMPORT "GDIPLUS.DLL" ALIAS "GdipLoadImageFromStreamICM" ( _
   BYVAL stream AS IStream _                            ' __in  IStream *stream
 , BYREF image AS DWORD _                               ' __out GpImage **image
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipLoadImageFromFileICM IMPORT "GDIPLUS.DLL" ALIAS "GdipLoadImageFromFileICM" ( _
   BYREF filename AS WSTRINGZ _                         ' __in  GDIPCONST WCHAR *filename
 , BYREF image AS DWORD _                               ' __out GpImage **image
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCloneImage IMPORT "GDIPLUS.DLL" ALIAS "GdipCloneImage" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF cloneImage AS DWORD _                          ' __out GpImage **cloneImage
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDisposeImage IMPORT "GDIPLUS.DLL" ALIAS "GdipDisposeImage" ( _
   BYVAL image AS DWORD _                               ' __in GpImage *image
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSaveImageToFile IMPORT "GDIPLUS.DLL" ALIAS "GdipSaveImageToFile" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF filename AS WSTRINGZ _                         ' __in  GDIPCONST WCHAR *filename
 , BYREF clsidEncoder AS GUID _                         ' __in  GDIPCONST CLSID clsidEncoder
 , BYREF encoderParams AS EncoderParameters _           ' __out GDIPCONST EncoderParameters *encoderParams
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSaveImageToStream IMPORT "GDIPLUS.DLL" ALIAS "GdipSaveImageToStream" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYVAL stream AS IStream _                            ' __in  IStream *stream
 , BYREF clsidEncoder AS GUID _                         ' __in  GDIPCONST CLSID *clsidEncoder
 , BYREF encoderParams AS EncoderParameters _           ' __out GDIPCONST EncoderParameters *encoderParams
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSaveAdd IMPORT "GDIPLUS.DLL" ALIAS "GdipSaveAdd" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF encoderParams AS EncoderParameters _           ' __out GDIPCONST EncoderParameters *encoderParams
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSaveAddImage IMPORT "GDIPLUS.DLL" ALIAS "GdipSaveAddImage" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYVAL newImage AS DWORD _                            ' __in  GpImage newImage
 , BYREF encoderParams AS EncoderParameters _           ' __out GDIPCONST EncoderParameters *encoderParams
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetImageGraphicsContext IMPORT "GDIPLUS.DLL" ALIAS "GdipGetImageGraphicsContext" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF graphics AS DWORD _                            ' __out GpGraphics **graphics
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetImageBounds IMPORT "GDIPLUS.DLL" ALIAS "GdipGetImageBounds" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF srcRect AS GpRectF _                           ' __out GpRectF *srcRect
 , BYREF srcUnit AS LONG _                              ' __out GpUnit *srcUnit
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetImageDimension IMPORT "GDIPLUS.DLL" ALIAS "GdipGetImageDimension" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF width AS SINGLE _                              ' __out REAL *width
 , BYREF height AS SINGLE _                             ' __out REAL *height
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetImageType IMPORT "GDIPLUS.DLL" ALIAS "GdipGetImageType" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF type AS LONG _                                 ' __out ImageType *type
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetImageWidth IMPORT "GDIPLUS.DLL" ALIAS "GdipGetImageWidth" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF width AS DWORD _                               ' __out UINT *width
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetImageHeight IMPORT "GDIPLUS.DLL" ALIAS "GdipGetImageHeight" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF height AS DWORD _                              ' __out UINT *height
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetImageHorizontalResolution IMPORT "GDIPLUS.DLL" ALIAS "GdipGetImageHorizontalResolution" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF resolution AS SINGLE _                         ' __out REAL *resolution
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetImageVerticalResolution IMPORT "GDIPLUS.DLL" ALIAS "GdipGetImageVerticalResolution" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF resolution AS SINGLE _                         ' __out REAL *resolution
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetImageFlags IMPORT "GDIPLUS.DLL" ALIAS "GdipGetImageFlags" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF flags AS DWORD _                               ' __out UINT *flags
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetImageRawFormat IMPORT "GDIPLUS.DLL" ALIAS "GdipGetImageRawFormat" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF format AS GUID _                               ' __out GUID *format
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetImagePixelFormat IMPORT "GDIPLUS.DLL" ALIAS "GdipGetImagePixelFormat" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF format AS LONG _                               ' __out PixelFormat *format
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetImageThumbnail IMPORT "GDIPLUS.DLL" ALIAS "GdipGetImageThumbnail" ( _
   BYVAL image AS DWORD _                               ' __in GpImage *image
 , BYVAL thumbWidth AS DWORD _                          ' __in UINT thumbWidth
 , BYVAL thumbHeight AS DWORD _                         ' __in UINT thumbHeight
 , BYREF thumbImage AS DWORD _                          ' __out GpImage **thumbImage
 , BYVAL callback AS DWORD _                            ' __in GetThumbnailImageAbort callback
 , BYVAL callbackData AS DWORD _                        ' __in VOID *callbackData
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetEncoderParameterListSize IMPORT "GDIPLUS.DLL" ALIAS "GdipGetEncoderParameterListSize" ( _
   BYVAL image AS DWORD _                               ' __in GpImage *image
 , BYREF clsidEncoder AS GUID _                         ' __out GDIPCONST CLSID *clsidEncoder
 , BYREF size AS DWORD _                                ' __out UINT *size
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetEncoderParameterList IMPORT "GDIPLUS.DLL" ALIAS "GdipGetEncoderParameterList" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF clsidEncoder AS GUID _                         ' __in  GDIPCONST CLSID *clsidEncoder
 , BYVAL size AS DWORD _                                ' __in  UINT size
 , BYREF buffer AS EncoderParameters _                  ' __out GDIPCONST EncoderParameters *buffer
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipImageGetFrameDimensionsCount IMPORT "GDIPLUS.DLL" ALIAS "GdipImageGetFrameDimensionsCount" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF count AS DWORD _                               ' __out UINT *count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipImageGetFrameDimensionsList IMPORT "GDIPLUS.DLL" ALIAS "GdipImageGetFrameDimensionsList" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF dimensionIDs AS GUID _                         ' __out GUID *dimensionIDs
 , BYVAL count AS DWORD _                               ' __in  UINT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipImageGetFrameCount IMPORT "GDIPLUS.DLL" ALIAS "GdipImageGetFrameCount" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF dimensionID AS GUID _                          ' __in  GDIPCONST GUID *dimensionID
 , BYREF count AS DWORD _                               ' __out UINT *count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipImageSelectActiveFrame IMPORT "GDIPLUS.DLL" ALIAS "GdipImageSelectActiveFrame" ( _
   BYVAL image AS DWORD _                               ' __in GpImage *image
 , BYREF dimensionID AS GUID _                          ' __in GDIPCONST GUID *dimensionID
 , BYVAL frameIndex AS DWORD _                          ' __in UINT frameIndex
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipImageRotateFlip IMPORT "GDIPLUS.DLL" ALIAS "GdipImageRotateFlip" ( _
   BYVAL image AS DWORD _                               ' __in GpImage *image
 , BYVAL rfType AS LONG _                               ' __in RotateFlipType rfType
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetImagePalette IMPORT "GDIPLUS.DLL" ALIAS "GdipGetImagePalette" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF palette AS ColorPalette _                      ' __out ColorPalette *palette
 , BYVAL size AS LONG _                                 ' __in  INT size
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetImagePalette IMPORT "GDIPLUS.DLL" ALIAS "GdipSetImagePalette" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF palette AS ColorPalette _                      ' __out GDIPCONST ColorPalette *palette
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetImagePaletteSize IMPORT "GDIPLUS.DLL" ALIAS "GdipGetImagePaletteSize" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF size AS LONG _                                 ' __out INT *size
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPropertyCount IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPropertyCount" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF numOfProperty AS DWORD _                       ' __out UINT *numOfProperty
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPropertyIdList IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPropertyIdList" ( _
   BYVAL image AS DWORD _                               ' GpImage *image
 , BYVAL numOfProperty AS DWORD _                       ' UINT numOfProperty
 , BYREF list AS DWORD _                                ' PROPID *list
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPropertyItemSize IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPropertyItemSize" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYVAL propId AS DWORD _                              ' __in  PROPID propId
 , BYREF size AS DWORD _                                ' __out UINT *size
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPropertyItem IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPropertyItem" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYVAL propId AS DWORD _                              ' __in  PROPID propId
 , BYVAL propSize AS DWORD _                            ' __in  UINT propSize
 , BYREF buffer AS PropertyItem _                       ' __out PropertyItem *buffer
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPropertySize IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPropertySize" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF totalBufferSize AS DWORD _                     ' __out UINT *totalBufferSize
 , BYREF numProperties AS DWORD _                       ' __out UINT *numProperties
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetAllPropertyItems IMPORT "GDIPLUS.DLL" ALIAS "GdipGetAllPropertyItems" ( _
   BYVAL image AS DWORD _                               ' __in GpImage *image
 , BYVAL totalBufferSize AS DWORD _                     ' __in UINT totalBufferSize
 , BYVAL numProperties AS DWORD _                       ' __in UINT numProperties
 , BYREF allItems AS PropertyItem _                     ' __out PropertyItem *allItems
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipRemovePropertyItem IMPORT "GDIPLUS.DLL" ALIAS "GdipRemovePropertyItem" ( _
   BYVAL image AS DWORD _                               ' __in GpImage *image
 , BYVAL propId AS DWORD _                              ' __in PROPID propId
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPropertyItem IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPropertyItem" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF item AS PropertyItem _                         ' __out PropertyItem *item
 ) AS LONG                                              ' GpStatus

#IF (%GDIPVER >= &H0110)

DECLARE FUNCTION GdipFindFirstImageItem IMPORT "GDIPLUS.DLL" ALIAS "GdipFindFirstImageItem" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF item As ImageItemData _                        ' __out ImageItemData* item
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipFindNextImageItem IMPORT "GDIPLUS.DLL" ALIAS "GdipFindNextImageItem" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF item AS ImageItemData _                        ' __out ImageItemData* item
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetImageItemData IMPORT "GDIPLUS.DLL" ALIAS "GdipGetImageItemData" ( _
   BYVAL image AS DWORD _                               ' __in  GpImage *image
 , BYREF item AS ImageItemData _                        ' __out ImageItemData* item
 ) AS LONG                                              ' GpStatus

#ENDIF   ' //(%GDIPVER >= &H0110)

DECLARE FUNCTION GdipImageForceValidation IMPORT "GDIPLUS.DLL" ALIAS "GdipImageForceValidation" ( _
   BYVAL image AS DWORD _                               ' __in GpImage *image
 ) AS LONG                                              ' GpStatus

'//----------------------------------------------------------------------------
'// Bitmap APIs
'//----------------------------------------------------------------------------

DECLARE FUNCTION GdipCreateBitmapFromStream IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateBitmapFromStream" ( _
   BYVAL stream AS IStream _                            ' __in  IStream *stream
 , BYREF bitmap AS DWORD _                              ' __out GpBitmap **bitmap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateBitmapFromFile IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateBitmapFromFile" ( _
   BYREF filename AS WSTRINGZ _                         ' __in  GDIPCONST WCHAR *filename
 , BYREF bitmap AS DWORD _                              ' __out GpBitmap **bitmap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateBitmapFromStreamICM IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateBitmapFromStreamICM" ( _
   BYVAL stream AS IStream _                            ' __in  IStream *stream
 , BYREF bitmap AS DWORD _                              ' __out GpBitmap **bitmap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateBitmapFromFileICM IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateBitmapFromFileICM" ( _
   BYREF filename AS WSTRINGZ _                         ' __in  GDIPCONST WCHAR *filename
 , BYREF bitmap AS DWORD _                              ' __out GpBitmap **bitmap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateBitmapFromScan0 IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateBitmapFromScan0" ( _
   BYVAL width AS LONG _                                ' __in  INT width
 , BYVAL height AS LONG _                               ' __in  INT height
 , BYVAL stride AS LONG _                               ' __in  INT stride
 , BYVAL PixelFormat AS LONG _                          ' __in  PixelFormat
 , BYREF scan0 AS ANY _                                 ' __in  BYTE *scan0
 , BYREF bitmap AS DWORD _                              ' __out GpBitmap **bitmap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateBitmapFromGraphics IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateBitmapFromGraphics" ( _
   BYVAL width AS LONG _                                ' __in  INT width
 , BYVAL height AS LONG _                               ' __in  INT height
 , BYVAL target AS DWORD _                              ' __in  GpGraphics *target
 , BYREF bitmap AS DWORD _                              ' __out GpBitmap **bitmap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateBitmapFromDirectDrawSurface IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateBitmapFromDirectDrawSurface" ( _
   BYVAL surface AS IUnknown _                          ' __in  IDirectDrawSurface7 *surface
 , BYREF bitmap AS DWORD _                              ' __out GpBitmap **bitmap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateBitmapFromGdiDib IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateBitmapFromGdiDib" ( _
   BYREF gdiBitmapInfo AS BITMAPINFO _                  ' __in  GDIPCONST BITMAPINFO *gdiBitmapInfo
 , BYVAL gdiBitmapData AS DWORD _                       ' __in  VOID *gdiBitmapData
 , BYREF bitmap AS DWORD _                              ' __out GpBitmap **bitmap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateBitmapFromHBITMAP IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateBitmapFromHBITMAP" ( _
   BYVAL hbm AS DWORD _                                 ' __in  HBITMAP hbm
 , BYVAL hpal AS DWORD _                                ' __in  HPALETTE hpal
 , BYREF bitmap AS DWORD _                              ' __out GpBitmap **bitmap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateHBITMAPFromBitmap IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateHBITMAPFromBitmap" ( _
   BYVAL bitmap AS DWORD _                              ' __in  GpBitmap *bitmap
 , BYREF hbmReturn AS DWORD _                           ' __out HBITMAP *hbmReturn
 , BYVAL background AS DWORD _                          ' __in  ARGB background
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateBitmapFromHICON IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateBitmapFromHICON" ( _
   BYVAL hicon AS DWORD _                               ' __in  HICON hicon
 , BYREF bitmap AS DWORD _                              ' __out GpBitmap **bitmap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateHICONFromBitmap IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateHICONFromBitmap" ( _
   BYVAL bitmap AS DWORD _                              ' __in  GpBitmap *bitmap
 , BYREF hbmReturn AS DWORD _                           ' __out HICON* hbmReturn
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateBitmapFromResource IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateBitmapFromResource" ( _
   BYVAL hInstance AS DWORD _                           ' __in  HINSTANCE hInstance
 , BYREF lpBitmapName AS WSTRINGZ _                     ' __in  GDIPCONST WCHAR *lpBitmapName
 , BYREF bitmap AS DWORD _                              ' __out GpBitmap **bitmap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCloneBitmapArea IMPORT "GDIPLUS.DLL" ALIAS "GdipCloneBitmapArea" ( _
   BYVAL x AS SINGLE _                                  ' __in  REAL x
 , BYVAL y AS SINGLE _                                  ' __in  REAL y
 , BYVAL width AS SINGLE _                              ' __in  REAL width
 , BYVAL height AS SINGLE _                             ' __in  REAL height
 , BYVAL format AS LONG _                               ' __in  PixelFormat format
 , BYVAL srcBitmap AS DWORD _                           ' __in  GpBitmap *srcBitmap
 , BYREF dstBitmap AS DWORD _                           ' __out GpBitmap **dstBitmap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCloneBitmapAreaI IMPORT "GDIPLUS.DLL" ALIAS "GdipCloneBitmapAreaI" ( _
   BYVAL x AS LONG _                                    ' __in  INT x
 , BYVAL y AS LONG _                                    ' __in  INT y
 , BYVAL width AS LONG _                                ' __in  INT width
 , BYVAL height AS LONG _                               ' __in  INT height
 , BYVAL format AS LONG _                               ' __in  PixelFormat format
 , BYVAL srcBitmap AS DWORD _                           ' __in  GpBitmap *srcBitmap
 , BYREF dstBitmap AS DWORD _                           ' __out GpBitmap **dstBitmap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipBitmapLockBits IMPORT "GDIPLUS.DLL" ALIAS "GdipBitmapLockBits" ( _
   BYVAL bitmap AS DWORD _                              ' __in  GpBitmap *bitmap
 , BYREF rect AS GpRect _                               ' __in  GDIPCONST GpRect *rect
 , BYVAL flags AS DWORD _                               ' __in  UINT flags
 , BYVAL format AS LONG _                               ' __in  PixelFormat format
 , BYREF lockedBitmapData AS BitmapData _               ' __out BitmapData* lockedBitmapData
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipBitmapUnlockBits IMPORT "GDIPLUS.DLL" ALIAS "GdipBitmapUnlockBits" ( _
   BYVAL bitmap AS DWORD _                              ' __in  GpBitmap *bitmap
 , BYREF lockedBitmapData AS BitmapData _               ' __out BitmapData *lockedBitmapData
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipBitmapGetPixel IMPORT "GDIPLUS.DLL" ALIAS "GdipBitmapGetPixel" ( _
   BYVAL bitmap AS DWORD _                              ' __in  GpBitmap *bitmap
 , BYVAL x AS LONG _                                    ' __in  INT x
 , BYVAL y AS LONG _                                    ' __in  INT y
 , BYREF color AS DWORD _                               ' __out ARGB *color
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipBitmapSetPixel IMPORT "GDIPLUS.DLL" ALIAS "GdipBitmapSetPixel" ( _
   BYVAL bitmap AS DWORD _                              ' __in GpBitmap *bitmap
 , BYVAL x AS LONG _                                    ' __in INT x
 , BYVAL y AS LONG _                                    ' __in INT y
 , BYVAL color AS DWORD _                               ' __in ARGB color
 ) AS LONG                                              ' GpStatus


#IF (%GDIPVER >= &H0110)

DECLARE FUNCTION GdipImageSetAbort IMPORT "GDIPLUS.DLL" ALIAS "GdipImageSetAbort" ( _
   BYVAL pImage AS DWORD _                              ' __in GpImage *pImage
 , BYVAL pIAbort AS DWORD _                             ' __in GdiplusAbort *pIAbort
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGraphicsSetAbort IMPORT "GDIPLUS.DLL" ALIAS "GdipGraphicsSetAbort" ( _
   BYVAL pGraphics AS DWORD _                           ' __in GpGraphics *pGraphics
 , BYVAL pIAbort AS DWORD _                             ' __in GdiplusAbort *pIAbort
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipBitmapConvertFormat IMPORT "GDIPLUS.DLL" ALIAS "GdipBitmapConvertFormat" ( _
   BYVAL pInputBitmap AS DWORD _                        ' __in  GpBitmap *pInputBitmap
 , BYVAL format AS LONG _                               ' __in  PixelFormat format
 , BYVAL dithertype AS LONG _                           ' __in  DitherType dithertype
 , BYVAL palettetype AS LONG _                          ' __in  PaletteType palettetype
 , BYREF palette AS ColorPalette _                      ' __out ColorPalette *palette
 , BYVAL alphaThresholdPercent AS SINGLE _              ' __in  REAL alphaThresholdPercent
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipInitializePalette IMPORT "GDIPLUS.DLL" ALIAS "GdipInitializePalette" ( _
   BYREF palette AS ColorPalette _                      ' __out ColorPalette *palette   // output palette. must be allocated.
 , BYVAL palettetype AS LONG _                          ' __in  PaletteType palettetype     // palette enumeration type.
 , BYVAL optimalColors AS LONG _                        ' __in  INT optimalColors           // how many optimal colors
 , BYVAL useTransparentColor AS LONG _                  ' __in  BOOL useTransparentColor    // add a transparent color to the palette.
 , BYVAL bitmap AS DWORD _                              ' __in  GpBitmap *bitmap            // optional bitmap for median cut.
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipBitmapApplyEffect IMPORT "GDIPLUS.DLL" ALIAS "GdipBitmapApplyEffect" ( _
   BYVAL bitmap AS DWORD _                              ' __in  GpBitmap* bitmap
 , BYVAL effect AS DWORD _                              ' __in  CGpEffect *effect
 , BYREF roi AS RECT _                                  ' __in  RECT *roi
 , BYVAL useAuxData AS LONG _                           ' __in  BOOL useAuxData
 , BYREF auxData AS DWORD _                             ' __out VOID **auxData
 , BYREF auxDataSize AS LONG _                          ' __out INT *auxDataSize
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipBitmapCreateApplyEffect IMPORT "GDIPLUS.DLL" ALIAS "GdipBitmapCreateApplyEffect" ( _
   BYREF inputBitmaps AS DWORD _                        ' __in  GpBitmap **inputBitmaps
 , BYVAL numInputs AS LONG _                            ' __in  INT numInputs
 , BYVAL effect AS DWORD _                              ' __in  CGpEffect *effect
 , BYREF roi AS RECT _                                  ' __in  RECT *roi
 , BYREF outputRect AS RECT _                           ' __out RECT *outputRect
 , BYREF outputBitmap AS DWORD _                        ' __out GpBitmap **outputBitmap
 , BYVAL useAuxData AS LONG _                           ' __in  BOOL useAuxData
 , BYREF auxData AS DWORD _                             ' __out VOID **auxData
 , BYREF auxDataSize AS LONG _                          ' __out INT *auxDataSize
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipBitmapGetHistogram IMPORT "GDIPLUS.DLL" ALIAS "GdipBitmapGetHistogram" ( _
   BYVAL bitmap AS DWORD _                              ' __in  GpBitmap* bitmap
 , BYVAL format AS LONG _                               ' __in  HistogramFormat format
 , BYVAL NumberOfEntries AS DWORD _                     ' __in  UINT NumberOfEntries
 , BYREF channel0 AS DWORD _                            ' __out_bcount(sizeof(UINT)*256) UINT *channel0
 , BYREF channel1 AS DWORD _                            ' __out_bcount(sizeof(UINT)*256) UINT *channel1
 , BYREF channel2 AS DWORD _                            ' __out_bcount(sizeof(UINT)*256) UINT *channel2
 , BYREF channel3 AS DWORD _                            ' __out_bcount(sizeof(UINT)*256) UINT *channel3
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipBitmapGetHistogramSize IMPORT "GDIPLUS.DLL" ALIAS "GdipBitmapGetHistogramSize" ( _
   BYVAL format AS LONG _                               ' __in  HistogramFormat format
 , BYREF NumberOfEntries AS DWORD _                     ' __out UINT *NumberOfEntries
 ) AS LONG                                              ' GpStatus

#ENDIF   ' #IF (%GDIPVER >= &H0110)

DECLARE FUNCTION GdipBitmapSetResolution IMPORT "GDIPLUS.DLL" ALIAS "GdipBitmapSetResolution" ( _
   BYVAL bitmap AS DWORD _                              ' __in GpBitmap *bitmap
 , BYVAL x AS SINGLE _                                  ' __in REAL xdpi
 , BYVAL y AS SINGLE _                                  ' __in REAL ydpi
 ) AS LONG                                              ' GpStatus

'//----------------------------------------------------------------------------
'// ImageAttributes APIs
'//----------------------------------------------------------------------------

DECLARE FUNCTION GdipCreateImageAttributes IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateImageAttributes" ( _
   BYREF imageattr AS DWORD _                           ' __out GpImageAttributes **imageattr
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCloneImageAttributes IMPORT "GDIPLUS.DLL" ALIAS "GdipCloneImageAttributes" ( _
   BYVAL imageattr AS DWORD _                           ' __in  GpImageAttributes *imageattr
 , BYREF cloneImageattr AS DWORD _                      ' __out GpImageAttributes **cloneImageattr
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDisposeImageAttributes IMPORT "GDIPLUS.DLL" ALIAS "GdipDisposeImageAttributes" ( _
   BYVAL imageattr AS LONG _                            ' __in GpImageAttributes *imageattr
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetImageAttributesToIdentity IMPORT "GDIPLUS.DLL" ALIAS "GdipSetImageAttributesToIdentity" ( _
   BYVAL imageattr AS DWORD _                           ' __in GpImageAttributes *imageattr
 , BYVAL type AS LONG _                                 ' __in ColorAdjustType type
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipResetImageAttributes IMPORT "GDIPLUS.DLL" ALIAS "GdipResetImageAttributes" ( _
   BYVAL imageattr AS DWORD _                           ' __in GpImageAttributes *imageattr
 , BYVAL type AS LONG _                                 ' __in ColorAdjustType type
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetImageAttributesColorMatrix IMPORT "GDIPLUS.DLL" ALIAS "GdipSetImageAttributesColorMatrix" ( _
   BYVAL imageattr AS DWORD _                           ' __in GpImageAttributes *imageattr
 , BYVAL type AS LONG _                                 ' __in ColorAdjustType type
 , BYVAL enableFlag AS LONG _                           ' __in BOOL enableFlag
 , BYREF colorMatrix AS ColorMatrix _                   ' __in GDIPCONST ColorMatrix* colorMatrix
 , BYREF grayMatrix AS ColorMatrix _                    ' __in GDIPCONST ColorMatrix* grayMatrix
 , BYVAL flags AS LONG _                                ' __in ColorMatrixFlags flags
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetImageAttributesThreshold IMPORT "GDIPLUS.DLL" ALIAS "GdipSetImageAttributesThreshold" ( _
   BYVAL imageattr AS DWORD _                           ' __in GpImageAttributes *imageattr
 , BYVAL type AS LONG _                                 ' __in ColorAdjustType type
 , BYVAL enableFlag AS LONG _                           ' __in BOOL enableFlag
 , BYVAL threshold AS SINGLE _                          ' __in REAL threshold
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetImageAttributesGamma IMPORT "GDIPLUS.DLL" ALIAS "GdipSetImageAttributesGamma" ( _
   BYVAL imageattr AS DWORD _                           ' __in GpImageAttributes *imageattr
 , BYVAL type AS LONG _                                 ' __in ColorAdjustType type
 , BYVAL enableFlag AS LONG _                           ' __in BOOL enableFlag
 , BYVAL gamma AS SINGLE _                              ' __in REAL gamma
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetImageAttributesNoOp IMPORT "GDIPLUS.DLL" ALIAS "GdipSetImageAttributesNoOp" ( _
   BYVAL imageattr AS DWORD _                           ' __in GpImageAttributes *imageattr
 , BYVAL type AS LONG _                                 ' __in ColorAdjustType type
 , BYVAL enableFlag AS LONG _                           ' __in BOOL enableFlag
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetImageAttributesColorKeys IMPORT "GDIPLUS.DLL" ALIAS "GdipSetImageAttributesColorKeys" ( _
   BYVAL imageattr AS DWORD _                           ' __in GpImageAttributes *imageattr
 , BYVAL type AS LONG _                                 ' __in ColorAdjustType type
 , BYVAL enableFlag AS LONG _                           ' __in BOOL enableFlag
 , BYVAL colorLow AS DWORD _                            ' __in ARGB colorLow
 , BYVAL colorHigh AS DWORD _                           ' __in ARGB colorHigh
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetImageAttributesOutputChannel IMPORT "GDIPLUS.DLL" ALIAS "GdipSetImageAttributesOutputChannel" ( _
   BYVAL imageattr AS DWORD _                           ' __in GpImageAttributes *imageattr
 , BYVAL type AS LONG _                                 ' __in ColorAdjustType type
 , BYVAL enableFlag AS LONG _                           ' __in BOOL  enableFlag
 , BYVAL channelFlags AS LONG _                         ' __in ColorChannelFlags channelFlags
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetImageAttributesOutputChannelColorProfile IMPORT "GDIPLUS.DLL" ALIAS "GdipSetImageAttributesOutputChannelColorProfile" ( _
   BYVAL imageattr AS DWORD _                           ' __in GpImageAttributes *imageattr
 , BYVAL type AS LONG _                                 ' __in ColorAdjustType type
 , BYVAL enableFlag AS LONG _                           ' __in BOOL enableFlag
 , BYREF colorProfileFilename AS WSTRINGZ _             ' __in GDIPCONST WCHAR *colorProfileFilename
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetImageAttributesRemapTable IMPORT "GDIPLUS.DLL" ALIAS "GdipSetImageAttributesRemapTable" ( _
   BYVAL imageattr AS DWORD _                           ' __in GpImageAttributes *imageattr
 , BYVAL type AS LONG _                                 ' __in ColorAdjustType type
 , BYVAL enableFlag AS LONG _                           ' __in BOOL enableFlag
 , BYVAL mapSize AS DWORD _                             ' __in UINT mapSize
 , BYREF map AS GpColorMap _                            ' __in GDIPCONST ColorMap *map
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetImageAttributesWrapMode IMPORT "GDIPLUS.DLL" ALIAS "GdipSetImageAttributesWrapMode" ( _
   BYVAL imageattr AS DWORD _                           ' __in GpImageAttributes *imageattr
 , BYVAL wrap AS LONG _                                 ' __in WrapMode wrap
 , BYVAL argb AS DWORD _                                ' __in ARGB argb
 , BYVAL clamp AS LONG _                                ' __in BOOL clamp
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetImageAttributesICMMode IMPORT "GDIPLUS.DLL" ALIAS "GdipSetImageAttributesICMMode" ( _
   BYVAL imageattr AS DWORD _                           ' __in GpImageAttributes *imageattr
 , BYVAL on AS LONG _                                   ' __in BOOL on
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetImageAttributesAdjustedPalette IMPORT "GDIPLUS.DLL" ALIAS "GdipGetImageAttributesAdjustedPalette" ( _
   BYVAL imageattr AS DWORD _                           ' __in GpImageAttributes *imageattr
 , BYREF colorPalette AS ColorPalette _                 ' __in_out ColorPalette *colorPalette
 , BYVAL colorAdjustType AS LONG _                      ' __in ColorAdjustType colorAdjustType
 ) AS LONG                                              ' GpStatus

'//----------------------------------------------------------------------------
'// Graphics APIs
'//----------------------------------------------------------------------------

DECLARE FUNCTION GdipFlush IMPORT "GDIPLUS.DLL" ALIAS "GdipFlush" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL intention AS LONG _                            ' __in GpFlushIntention intention
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateFromHDC IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateFromHDC" ( _
   BYVAL hdc AS DWORD _                                 ' __in  HDC hdc
 , BYREF graphics AS DWORD _                            ' __out GpGraphics **graphics
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateFromHDC2 IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateFromHDC2" ( _
   BYVAL hdc AS DWORD _                                 ' __in  HDC hdc
 , BYVAL hDevice AS DWORD _                             ' __in  HANDLE hDevice
 , BYREF graphics AS DWORD _                            ' __out GpGraphics **graphics
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateFromHWND IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateFromHWND" ( _
   BYVAL hwnd AS DWORD _                                ' __in  HWND hwnd
 , BYREF graphics AS DWORD _                            ' __out GpGraphics **graphics
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateFromHWNDICM IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateFromHWNDICM" ( _
   BYVAL hwnd AS DWORD _                                ' __in  HWND hwnd
 , BYREF graphics AS DWORD _                            ' __out GpGraphics **graphics
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDeleteGraphics IMPORT "GDIPLUS.DLL" ALIAS "GdipDeleteGraphics" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetDC IMPORT "GDIPLUS.DLL" ALIAS "GdipGetDC" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF DWORD _                                        ' __out HDC *hdc
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipReleaseDC IMPORT "GDIPLUS.DLL" ALIAS "GdipReleaseDC" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetCompositingMode IMPORT "GDIPLUS.DLL" ALIAS "GdipSetCompositingMode" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL compositingMode AS LONG _                      ' __in CompositingMode compositingMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetCompositingMode IMPORT "GDIPLUS.DLL" ALIAS "GdipGetCompositingMode" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF compositingMode AS LONG _                      ' __out CompositingMode *compositingMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetRenderingOrigin IMPORT "GDIPLUS.DLL" ALIAS "GdipSetRenderingOrigin" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL x AS LONG _                                    ' __in INT x
 , BYVAL y AS LONG _                                    ' __in INT y
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetRenderingOrigin IMPORT "GDIPLUS.DLL" ALIAS "GdipGetRenderingOrigin" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYREF x AS LONG _                                    ' __in INT x
 , BYREF y AS LONG _                                    ' __in INT y
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetCompositingQuality IMPORT "GDIPLUS.DLL" ALIAS "GdipSetCompositingQuality" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL compositingQuality AS LONG _                   ' __in GpCompositingQuality compositingQuality
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetCompositingQuality IMPORT "GDIPLUS.DLL" ALIAS "GdipGetCompositingQuality" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF compositingQuality AS LONG _                   ' __out GpCompositingQuality *compositingQuality
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetSmoothingMode IMPORT "GDIPLUS.DLL" ALIAS "GdipSetSmoothingMode" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL smoothingMode AS LONG _                        ' __in GpSmoothingMode smoothingMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetSmoothingMode IMPORT "GDIPLUS.DLL" ALIAS "GdipGetSmoothingMode" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF smoothingMode AS LONG _                        ' __out GpSmoothingMode *smoothingMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPixelOffsetMode IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPixelOffsetMode" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pixelOffsetMode AS LONG _                      ' __in GpPixelOffsetMode pixelOffsetMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPixelOffsetMode IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPixelOffsetMode" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF pixelOffsetMode AS LONG _                      ' __out GpPixelOffsetMode *pixelOffsetMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetTextRenderingHint IMPORT "GDIPLUS.DLL" ALIAS "GdipSetTextRenderingHint" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL mode AS LONG _                                 ' __in GpTextRenderingHint mode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetTextRenderingHint IMPORT "GDIPLUS.DLL" ALIAS "GdipGetTextRenderingHint" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF mode AS LONG _                                 ' __out GpTextRenderingHint *mode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetTextContrast IMPORT "GDIPLUS.DLL" ALIAS "GdipSetTextContrast" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL contrast AS DWORD _                            ' __in UINT contrast
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetTextContrast IMPORT "GDIPLUS.DLL" ALIAS "GdipGetTextContrast" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF contrast AS DWORD _                            ' __out UINT *contrast
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetInterpolationMode IMPORT "GDIPLUS.DLL" ALIAS "GdipSetInterpolationMode" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL interpolationMode AS LONG _                    ' __in GpInterpolationMode interpolationMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetInterpolationMode IMPORT "GDIPLUS.DLL" ALIAS "GdipGetInterpolationMode" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF interpolationMode AS LONG _                    ' __out GpInterpolationMode *interpolationMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetWorldTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipSetWorldTransform" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipResetWorldTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipResetWorldTransform" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipMultiplyWorldTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipMultiplyWorldTransform" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL matrix AS DWORD _                              ' __in GDIPCONST GpMatrix *matrix
 , BYVAL order AS LONG _                                ' __in GpMatrix order
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipTranslateWorldTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipTranslateWorldTransform" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL dx AS SINGLE _                                 ' __in REAL dx
 , BYVAL dy AS SINGLE _                                 ' __in REAL dy
 , BYVAL order AS LONG _                                ' __in GpMatrix order
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipScaleWorldTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipScaleWorldTransform" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL sx AS SINGLE _                                 ' __in REAL sx
 , BYVAL sy AS SINGLE _                                 ' __in REAL sy
 , BYVAL order AS LONG _                                ' __in GpMatrix order
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipRotateWorldTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipRotateWorldTransform" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL angle AS SINGLE _                              ' __in REAL angle
 , BYVAL order AS LONG _                                ' __in GpMatrix order
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetWorldTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipGetWorldTransform" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL matrix AS DWORD _                              ' __in GpMatrix *matrix
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipResetPageTransform IMPORT "GDIPLUS.DLL" ALIAS "GdipResetPageTransform" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPageUnit IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPageUnit" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF unit AS LONG _                                 ' __out GpUnit *unit
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetPageScale IMPORT "GDIPLUS.DLL" ALIAS "GdipGetPageScale" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF scale AS SINGLE _                              ' __out REAL *scale
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPageUnit IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPageUnit" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL unit AS LONG _                                 ' __in GpUnit unit
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetPageScale IMPORT "GDIPLUS.DLL" ALIAS "GdipSetPageScale" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL scale AS SINGLE _                              ' __in REAL scale
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetDpiX IMPORT "GDIPLUS.DLL" ALIAS "GdipGetDpiX" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF dpi AS SINGLE _                                ' __out REAL *dpi
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetDpiY IMPORT "GDIPLUS.DLL" ALIAS "GdipGetDpiY" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF dpi AS SINGLE _                                ' __out REAL *dpi
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipTransformPoints IMPORT "GDIPLUS.DLL" ALIAS "GdipTransformPoints" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL destSpace AS LONG _                            ' __in GpCoordinateSpace destSpace
 , BYVAL srcSpace AS LONG _                             ' __in GpCoordinateSpace srcSpace
 , BYREF points AS GpPointF _                           ' __in_out GpPointF *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipTransformPointsI IMPORT "GDIPLUS.DLL" ALIAS "GdipTransformPointsI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL destSpace AS LONG _                            ' __in GpCoordinateSpace destSpace
 , BYVAL srcSpace AS LONG _                             ' __in GpCoordinateSpace srcSpace
 , BYREF points AS GpPoint _                            ' __in_out GpPoint *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetNearestColor IMPORT "GDIPLUS.DLL" ALIAS "GdipGetNearestColor" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYREF argb AS DWORD _                                ' __out ARGB *argb
 ) AS LONG                                              ' GpStatus

'// Creates the Win9x Halftone Palette (even on NT) with correct Desktop colors
DECLARE FUNCTION GdipCreateHalftonePalette IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateHalftonePalette" ( _
 ) AS DWORD                                             ' HPALETTE

DECLARE FUNCTION GdipDrawLine IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawLine" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL x1 AS SINGLE _                                 ' __in REAL x1
 , BYVAL y1 AS SINGLE _                                 ' __in REAL y1
 , BYVAL x2 AS SINGLE _                                 ' __in REAL x2
 , BYVAL y2 AS SINGLE _                                 ' __in REAL y2
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawLineI IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawLineI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL x1 AS LONG _                                   ' __in INT x1
 , BYVAL y1 AS LONG _                                   ' __in INT y1
 , BYVAL x2 AS LONG _                                   ' __in INT x2
 , BYVAL y2 AS LONG _                                   ' __in INT y2
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawLines IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawLines" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYREF points AS GpPointF _                           ' __in GDIPCONST GpPointF *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawLinesI IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawLinesI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYREF points AS GpPoint _                            ' __in GDIPCONST GpPoint *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawArc IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawArc" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL x AS SINGLE _                                  ' __in REAL x
 , BYVAL y AS SINGLE _                                  ' __in REAL y
 , BYVAL width AS SINGLE _                              ' __in REAL width
 , BYVAL height AS SINGLE _                             ' __in REAL height
 , BYVAL startAngle AS SINGLE _                         ' __in REAL startAngle
 , BYVAL sweepAngle AS SINGLE _                         ' __in REAL sweepAngle
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawArcI IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawArcI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL x AS LONG _                                    ' __in INT x
 , BYVAL y AS LONG _                                    ' __in INT y
 , BYVAL width AS LONG _                                ' __in INT width
 , BYVAL height AS LONG _                               ' __in INT height
 , BYVAL startAngle AS SINGLE _                         ' __in REAL startAngle
 , BYVAL sweepAngle AS SINGLE _                         ' __in REAL sweepAngle
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawBezier IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawBezier" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL x1 AS SINGLE _                                 ' __in REAL x1
 , BYVAL y1 AS SINGLE _                                 ' __in REAL y1
 , BYVAL x2 AS SINGLE _                                 ' __in REAL x2
 , BYVAL y2 AS SINGLE _                                 ' __in REAL y2
 , BYVAL x3 AS SINGLE _                                 ' __in REAL x3
 , BYVAL y3 AS SINGLE _                                 ' __in REAL y3
 , BYVAL x4 AS SINGLE _                                 ' __in REAL x4
 , BYVAL y4 AS SINGLE _                                 ' __in REAL y4
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawBezierI IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawBezierI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL x1 AS LONG _                                   ' __in INT x1
 , BYVAL y1 AS LONG _                                   ' __in INT y1
 , BYVAL x2 AS LONG _                                   ' __in INT x2
 , BYVAL y2 AS LONG _                                   ' __in INT y2
 , BYVAL x3 AS LONG _                                   ' __in INT x3
 , BYVAL y3 AS LONG _                                   ' __in INT y3
 , BYVAL x4 AS LONG _                                   ' __in INT x4
 , BYVAL y4 AS LONG _                                   ' __in INT y4
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawBeziers IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawBeziers" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYREF points AS GpPointF _                           ' __in GDIPCONST GpPointF *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawBeziersI IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawBeziersI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYREF points AS GpPoint _                            ' __in GDIPCONST GpPoint *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawRectangle IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawRectangle" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL x AS SINGLE _                                  ' __in REAL x
 , BYVAL y AS SINGLE _                                  ' __in REAL y
 , BYVAL width AS SINGLE _                              ' __in REAL width
 , BYVAL height AS SINGLE _                             ' __in REAL height
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawRectangleI IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawRectangleI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL x AS LONG _                                    ' __in INT x
 , BYVAL y AS LONG _                                    ' __in INT y
 , BYVAL width AS LONG _                                ' __in INT width
 , BYVAL height AS LONG _                               ' __in INT height
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawRectangles IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawRectangles" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYREF rects AS GpRectF _                             ' __in GDIPCONST GpRectF *rects
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawRectanglesI IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawRectanglesI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYREF rects AS GpRect _                              ' __in GDIPCONST GpRect *rects
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawEllipse IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawEllipse" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL x AS SINGLE _                                  ' __in REAL x
 , BYVAL y AS SINGLE _                                  ' __in REAL y
 , BYVAL width AS SINGLE _                              ' __in REAL width
 , BYVAL height AS SINGLE _                             ' __in REAL height
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawEllipseI IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawEllipseI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL x AS LONG _                                    ' __in INT x
 , BYVAL y AS LONG _                                    ' __in INT y
 , BYVAL width AS LONG _                                ' __in INT width
 , BYVAL height AS LONG _                               ' __in INT height
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawPie IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawPie" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL x AS SINGLE _                                  ' __in REAL x
 , BYVAL y AS SINGLE _                                  ' __in REAL y
 , BYVAL width AS SINGLE _                              ' __in REAL width
 , BYVAL height AS SINGLE _                             ' __in REAL height
 , BYVAL startAngle AS SINGLE _                         ' __in REAL startAngle
 , BYVAL sweepAngle AS SINGLE _                         ' __in REAL sweepAngle
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawPieI IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawPieI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL x AS LONG _                                    ' __in INT x
 , BYVAL y AS LONG _                                    ' __in INT y
 , BYVAL width AS LONG _                                ' __in INT width
 , BYVAL height AS LONG _                               ' __in INT height
 , BYVAL startAngle AS SINGLE _                         ' __in REAL startAngle
 , BYVAL sweepAngle AS SINGLE _                         ' __in REAL sweepAngle
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawPolygon IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawPolygon" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYREF points AS GpPointF _                           ' __in GDIPCONST GpPointF *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawPolygonI IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawPolygonI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYREF points AS GpPoint _                            ' __in GDIPCONST GpPoint *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawPath IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawPath" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYVAL path AS DWORD _                                ' __in GpPath *path
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawCurve IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawCurve" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYREF points AS GpPointF _                           ' __in GDIPCONST GpPointF *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawCurveI IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawCurveI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYREF points AS GpPoint _                            ' __in GDIPCONST GpPoint *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawCurve2 IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawCurve2" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYREF points AS GpPointF _                           ' __in GDIPCONST GpPointF *points
 , BYVAL count AS LONG _                                ' __in INT count
 , BYVAL tension AS SINGLE _                            ' __in REAL tension
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawCurve2I IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawCurve2I" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYREF points AS GpPoint _                            ' __in GDIPCONST GpPoint *points
 , BYVAL count AS LONG _                                ' __in INT count
 , BYVAL tension AS SINGLE _                            ' __in REAL tension
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawCurve3 IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawCurve3" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYREF points AS GpPointF _                           ' __in GDIPCONST GpPointF *points
 , BYVAL count AS LONG _                                ' __in INT count
 , BYVAL offset AS LONG _                               ' __in INT offset
 , BYVAL numberOfSegments AS LONG _                     ' __in INT numberOfSegments
 , BYVAL tension AS SINGLE _                            ' __in REAL tension
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawCurve3I IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawCurve3I" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYREF points AS GpPoint _                            ' __in GDIPCONST GpPoint *points
 , BYVAL count AS LONG _                                ' __in INT count
 , BYVAL offset AS LONG _                               ' __in INT offset
 , BYVAL numberOfSegments AS LONG _                     ' __in INT numberOfSegments
 , BYVAL tension AS SINGLE _                            ' __in REAL tension
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawClosedCurve IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawClosedCurve" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYREF points AS GpPointF _                           ' __in GDIPCONST GpPointF *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawClosedCurveI IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawClosedCurveI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYREF points AS GpPoint _                            ' __in GDIPCONST GpPoint *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawClosedCurve2 IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawClosedCurve2" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYREF points AS GpPointF _                           ' __in GDIPCONST GpPointF *points
 , BYVAL count AS LONG _                                ' __in INT count
 , BYVAL tension AS SINGLE _                            ' __in REAL tension
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawClosedCurve2I IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawClosedCurve2I" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL pen AS DWORD _                                 ' __in GpPen *pen
 , BYREF points AS GpPoint _                            ' __in GDIPCONST GpPoint *points
 , BYVAL count AS LONG _                                ' __in INT count
 , BYVAL tension AS SINGLE _                            ' __in REAL tension
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGraphicsClear IMPORT "GDIPLUS.DLL" ALIAS "GdipGraphicsClear" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL color AS DWORD _                               ' __in ARGB color
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipFillRectangle IMPORT "GDIPLUS.DLL" ALIAS "GdipFillRectangle" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL GpBrush AS DWORD _                             ' __in GpBrush
 , BYVAL x AS SINGLE _                                  ' __in REAL x
 , BYVAL y AS SINGLE _                                  ' __in REAL y
 , BYVAL width AS SINGLE _                              ' __in REAL width
 , BYVAL height AS SINGLE _                             ' __in REAL height
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipFillRectangleI IMPORT "GDIPLUS.DLL" ALIAS "GdipFillRectangleI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL GpBrush AS DWORD _                             ' __in GpBrush
 , BYVAL x AS LONG _                                    ' __in INT x
 , BYVAL y AS LONG _                                    ' __in INT y
 , BYVAL width AS LONG _                                ' __in INT width
 , BYVAL height AS LONG _                               ' __in INT height
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipFillRectangles IMPORT "GDIPLUS.DLL" ALIAS "GdipFillRectangles" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL brush AS DWORD _                               ' __in GpBrush *brush
 , BYREF rects AS GpRectF _                             ' __in GDIPCONST GpRectF *rects
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipFillRectanglesI IMPORT "GDIPLUS.DLL" ALIAS "GdipFillRectanglesI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL brush AS DWORD _                               ' __in GpBrush *brush
 , BYREF rects AS GpRect _                              ' __in GDIPCONST GpRect *rects
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipFillPolygon IMPORT "GDIPLUS.DLL" ALIAS "GdipFillPolygon" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL brush AS DWORD _                               ' __in GpBrush *brush
 , BYREF points AS GpPointF _                           ' __in GDIPCONST GpPointF *points
 , BYVAL count AS LONG _                                ' __in INT count
 , BYVAL fillMode AS LONG _                             ' __in GpFillMode fillMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipFillPolygonI IMPORT "GDIPLUS.DLL" ALIAS "GdipFillPolygonI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL brush AS DWORD _                               ' __in GpBrush *brush
 , BYREF points AS GpPoint _                            ' __in GDIPCONST GpPoint *points
 , BYVAL count AS LONG _                                ' __in INT count
 , BYVAL fillMode AS LONG _                             ' __in GpFillMode fillMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipFillPolygon2 IMPORT "GDIPLUS.DLL" ALIAS "GdipFillPolygon2" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL brush AS DWORD _                               ' __in GpBrush *brush
 , BYREF points AS GpPointF _                           ' __in GDIPCONST GpPointF *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipFillPolygon2I IMPORT "GDIPLUS.DLL" ALIAS "GdipFillPolygon2I" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL brush AS DWORD _                               ' __in GpBrush *brush
 , BYREF points AS GpPoint _                            ' __in GDIPCONST GpPoint *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipFillEllipse IMPORT "GDIPLUS.DLL" ALIAS "GdipFillEllipse" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL brush AS DWORD _                               ' __in GpBrush *brush
 , BYVAL x AS SINGLE _                                  ' __in REAL x
 , BYVAL y AS SINGLE _                                  ' __in REAL y
 , BYVAL width AS SINGLE _                              ' __in REAL width
 , BYVAL height AS SINGLE _                             ' __in REAL height
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipFillEllipseI IMPORT "GDIPLUS.DLL" ALIAS "GdipFillEllipseI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL brush AS DWORD _                               ' __in GpBrush *brush
 , BYVAL x AS LONG _                                    ' __in INT x
 , BYVAL y AS LONG _                                    ' __in INT y
 , BYVAL width AS LONG _                                ' __in INT width
 , BYVAL height AS LONG _                               ' __in INT height
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipFillPie IMPORT "GDIPLUS.DLL" ALIAS "GdipFillPie" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL brush AS DWORD _                               ' __in GpBrush *brush
 , BYVAL x AS SINGLE _                                  ' __in REAL x
 , BYVAL y AS SINGLE _                                  ' __in REAL y
 , BYVAL width AS SINGLE _                              ' __in REAL width
 , BYVAL height AS SINGLE _                             ' __in REAL height
 , BYVAL startAngle AS SINGLE _                         ' __in REAL startAngle
 , BYVAL sweepAngle AS SINGLE _                         ' __in REAL sweepAngle
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipFillPieI IMPORT "GDIPLUS.DLL" ALIAS "GdipFillPieI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL brush AS DWORD _                               ' __in GpBrush *brush
 , BYVAL x AS LONG _                                    ' __in INT x
 , BYVAL y AS LONG _                                    ' __in INT y
 , BYVAL width AS LONG _                                ' __in INT width
 , BYVAL height AS LONG _                               ' __in INT height
 , BYVAL startAngle AS SINGLE _                         ' __in REAL startAngle
 , BYVAL sweepAngle AS SINGLE _                         ' __in REAL sweepAngle
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipFillPath IMPORT "GDIPLUS.DLL" ALIAS "GdipFillPath" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL brush AS DWORD _                               ' __in GpBrush *brush
 , BYVAL path AS DWORD _                                ' __in GpPath *path
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipFillClosedCurve IMPORT "GDIPLUS.DLL" ALIAS "GdipFillClosedCurve" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL brush AS DWORD _                               ' __in GpBrush *brush
 , BYREF points AS GpPointF _                           ' __in GDIPCONST GpPointF *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipFillClosedCurveI IMPORT "GDIPLUS.DLL" ALIAS "GdipFillClosedCurveI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL brush AS DWORD _                               ' __in GpBrush *brush
 , BYREF points AS GpPoint _                            ' __in GDIPCONST GpPoint *points
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipFillClosedCurve2 IMPORT "GDIPLUS.DLL" ALIAS "GdipFillClosedCurve2" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL brush AS DWORD _                               ' __in GpBrush *brush
 , BYREF points AS GpPointF _                           ' __in GDIPCONST GpPointF *points
 , BYVAL count AS LONG _                                ' __in INT count
 , BYVAL tension AS SINGLE _                            ' __in REAL tension
 , BYVAL fillMode AS LONG _                             ' __in GpFillMode fillMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipFillClosedCurve2I IMPORT "GDIPLUS.DLL" ALIAS "GdipFillClosedCurve2I" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL brush AS DWORD _                               ' __in GpBrush *brush
 , BYREF points AS GpPoint _                            ' __in GDIPCONST GpPoint *points
 , BYVAL count AS LONG _                                ' __in INT count
 , BYVAL tension AS SINGLE _                            ' __in REAL tension
 , BYVAL fillMode AS LONG _                             ' __in GpFillMode fillMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipFillRegion IMPORT "GDIPLUS.DLL" ALIAS "GdipFillRegion" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL brush AS DWORD _                               ' __in GpBrush *brush
 , BYVAL region AS DWORD _                              ' __in GpRegion *region
 ) AS LONG                                              ' GpStatus

#IF (%GDIPVER >= &H0110)
DECLARE FUNCTION GdipDrawImageFX IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawImageFX" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL image AS DWORD _                               ' __in GpImage *image
 , BYREF source AS GpRectF _                            ' __in GpRectF *source
 , BYVAL xForm AS DWORD _                               ' __in GpMatrix *xForm
 , BYVAL effect AS DWORD _                              ' __in CGpEffect *effect
 , BYVAL imageAttributes AS DWORD _                     ' __in GpImageAttributes *imageAttributes
 , BYVAL srcUnit AS LONG _                              ' __in GpUnit srcUnit
 ) AS LONG                                              ' GpStatus
#ENDIF   ' //(%GDIPVER >= &H0110)

DECLARE FUNCTION GdipDrawImage IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawImage" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL image AS DWORD _                               ' __in GpImage *image
 , BYVAL x AS SINGLE _                                  ' __in REAL x
 , BYVAL y AS SINGLE _                                  ' __in REAL y
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawImageI IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawImageI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL image AS DWORD _                               ' __in GpImage *image
 , BYVAL x AS LONG _                                    ' __in INT x
 , BYVAL y AS LONG _                                    ' __in INT y
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawImageRect IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawImageRect" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL image AS DWORD _                               ' __in GpImage *image
 , BYVAL x AS SINGLE _                                  ' __in REAL x
 , BYVAL y AS SINGLE _                                  ' __in REAL y
 , BYVAL width AS SINGLE _                              ' __in REAL width
 , BYVAL height AS SINGLE _                             ' __in REAL height
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawImageRectI IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawImageRectI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL image AS DWORD _                               ' __in GpImage *image
 , BYVAL x AS LONG _                                    ' __in INT x
 , BYVAL y AS LONG _                                    ' __in INT y
 , BYVAL width AS LONG _                                ' __in INT width
 , BYVAL height AS LONG _                               ' __in INT height
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawImagePoints IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawImagePoints" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL image AS DWORD _                               ' __in GpImage *image
 , BYREF dstpoints AS GpPointF _                        ' __in GDIPCONST GpPointF *dstpoints
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawImagePointsI IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawImagePointsI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL image AS DWORD _                               ' __in GpImage *image
 , BYREF dstpoints AS GpPoint _                         ' __in GDIPCONST GpPoint *dstpoints
 , BYVAL count AS LONG _                                ' __in INT count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawImagePointRect IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawImagePointRect" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL image AS DWORD _                               ' __in GpImage *image
 , BYVAL x AS SINGLE _                                  ' __in REAL x
 , BYVAL y AS SINGLE _                                  ' __in REAL y
 , BYVAL srcx AS SINGLE _                               ' __in REAL srcx
 , BYVAL srcy AS SINGLE _                               ' __in REAL srcy
 , BYVAL srcwidth AS SINGLE _                           ' __in REAL srcwidth
 , BYVAL srcheight AS SINGLE _                          ' __in REAL srcheight
 , BYVAL srcUnit AS LONG _                              ' __in GpUnit srcUnit
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawImagePointRectI IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawImagePointRectI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL image AS DWORD _                               ' __in GpImage *image
 , BYVAL x AS LONG _                                    ' __in INT x
 , BYVAL y AS LONG _                                    ' __in INT y
 , BYVAL srcx AS LONG _                                 ' __in INT srcx
 , BYVAL srcy AS LONG _                                 ' __in INT srcy
 , BYVAL srcwidth AS LONG _                             ' __in INT srcwidth
 , BYVAL srcheight AS LONG _                            ' __in INT srcheight
 , BYVAL srcUnit AS LONG _                              ' __in GpUnit srcUnit
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawImageRectRect IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawImageRectRect" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL image AS DWORD _                               ' __in GpImage *image
 , BYVAL dstx AS SINGLE _                               ' __in REAL dstx
 , BYVAL dsty AS SINGLE _                               ' __in REAL dsty
 , BYVAL dstwidth AS SINGLE _                           ' __in REAL dstwidth
 , BYVAL dstheight AS SINGLE _                          ' __in REAL dstheight
 , BYVAL srcx AS SINGLE _                               ' __in REAL srcx
 , BYVAL srcy AS SINGLE _                               ' __in REAL srcy
 , BYVAL srcwidth AS SINGLE _                           ' __in REAL srcwidth
 , BYVAL srcheight AS SINGLE _                          ' __in REAL srcheight
 , BYVAL srcUnit AS LONG _                              ' __in GpUnit srcUnit
 , BYVAL imageAttributes AS DWORD _                     ' __in GDIPCONST GpImageAttributes *imageAttributes
 , BYVAL callback AS DWORD _                            ' __in DrawImageAbort callback
 , BYVAL callbackData AS DWORD _                        ' __in VOID * callbackData
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawImageRectRectI IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawImageRectRectI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL image AS DWORD _                               ' __in GpImage *image
 , BYVAL dstx AS LONG _                                 ' __in INT dstx
 , BYVAL dsty AS LONG _                                 ' __in INT dsty
 , BYVAL dstwidth AS LONG _                             ' __in INT dstwidth
 , BYVAL dstheight AS LONG _                            ' __in INT dstheight
 , BYVAL srcx AS LONG _                                 ' __in INT srcx
 , BYVAL srcy AS LONG _                                 ' __in INT srcy
 , BYVAL srcwidth AS LONG _                             ' __in INT srcwidth
 , BYVAL srcheight AS LONG _                            ' __in INT srcheight
 , BYVAL srcUnit AS LONG _                              ' __in GpUnit srcUnit
 , BYVAL imageAttributes AS DWORD _                     ' __in GDIPCONST GpImageAttributes *imageAttributes
 , BYVAL callback AS DWORD _                            ' __in DrawImageAbort callback
 , BYVAL callbackData AS DWORD _                        ' __in VOID * callbackData
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawImagePointsRect IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawImagePointsRect" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL image AS DWORD _                               ' __in GpImage *image
 , BYREF points AS GpPointF _                           ' __in GDIPCONST GpPointF *points
 , BYVAL count AS LONG _                                ' __in INT count
 , BYVAL srcx AS SINGLE _                               ' __in REAL srcx
 , BYVAL srcy AS SINGLE _                               ' __in REAL srcy
 , BYVAL srcwidth AS SINGLE _                           ' __in REAL srcwidth
 , BYVAL srcheight AS SINGLE _                          ' __in REAL srcheight
 , BYVAL srcUnit AS LONG _                              ' __in GpUnit srcUnit
 , BYVAL imageAttributes AS DWORD _                     ' __in GDIPCONST GpImageAttributes *imageAttributes
 , BYVAL callback AS DWORD _                            ' __in DrawImageAbort callback
 , BYVAL callbackData AS DWORD _                        ' __in VOID * callbackData
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawImagePointsRectI IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawImagePointsRectI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL image AS DWORD _                               ' __in GpImage *image
 , BYREF points AS GpPoint _                            ' __in GDIPCONST GpPoint *points
 , BYVAL count AS LONG _                                ' __in INT count
 , BYVAL srcx AS LONG _                                 ' __in INT srcx
 , BYVAL srcy AS LONG _                                 ' __in INT srcy
 , BYVAL srcwidth AS LONG _                             ' __in INT srcwidth
 , BYVAL srcheight AS LONG _                            ' __in INT srcheight
 , BYVAL srcUnit AS LONG _                              ' __in GpUnit srcUnit
 , BYVAL imageAttributes AS DWORD _                     ' __in GDIPCONST GpImageAttributes *imageAttributes
 , BYVAL callback AS DWORD _                            ' __in DrawImageAbort callback
 , BYVAL callbackData AS DWORD _                        ' __in VOID * callbackData
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipEnumerateMetafileDestPoint IMPORT "GDIPLUS.DLL" ALIAS "GdipEnumerateMetafileDestPoint" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL metafile AS DWORD _                            ' __in GDIPCONST GpMetafile *metafile
 , BYREF destPoint AS GpPointF _                        ' __in GDIPCONST GpPointF *destPoint
 , BYVAL callback AS DWORD _                            ' __in EnumerateMetafileProc callback
 , BYVAL callbackData AS DWORD _                        ' __in VOID *callbackData
 , BYVAL imageAttributes AS DWORD _                     ' __in GDIPCONST GpImageAttributes *imageAttributes
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipEnumerateMetafileDestPointI IMPORT "GDIPLUS.DLL" ALIAS "GdipEnumerateMetafileDestPointI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL Dmetafile AS WORD _                            ' __in GDIPCONST GpMetafile * metafile
 , BYREF destPoint AS GpPoint _                         ' __in GDIPCONST GpPoint *destPoint
 , BYVAL destPoint AS DWORD _                           ' __in EnumerateMetafileProc callback
 , BYVAL callbackData AS DWORD _                        ' __in VOID *callbackData
 , BYVAL imageAttributes AS DWORD _                     ' __in GDIPCONST GpImageAttributes *imageAttributes
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipEnumerateMetafileDestRect IMPORT "GDIPLUS.DLL" ALIAS "GdipEnumerateMetafileDestRect" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL metafile AS DWORD _                            ' __in GDIPCONST GpMetafile *metafile
 , BYREF destRect AS GpRectF _                          ' __in GDIPCONST GpRectF *destRect
 , BYVAL callback AS DWORD _                            ' __in EnumerateMetafileProc callback
 , BYVAL callbackData AS DWORD _                        ' __in VOID *callbackData
 , BYVAL imageAttributes AS DWORD _                     ' __in GDIPCONST GpImageAttributes *imageAttributes
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipEnumerateMetafileDestRectI IMPORT "GDIPLUS.DLL" ALIAS "GdipEnumerateMetafileDestRectI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL metafile AS DWORD _                            ' __in GDIPCONST GpMetafile *metafile
 , BYREF destRect AS GpRect _                           ' __in GDIPCONST GpRect *destRect
 , BYVAL callback AS DWORD _                            ' __in EnumerateMetafileProc callback
 , BYVAL callbackData AS DWORD _                        ' __in VOID *callbackData
 , BYVAL imageAttributes AS DWORD _                     ' __in GDIPCONST GpImageAttributes *imageAttributes
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipEnumerateMetafileDestPoints IMPORT "GDIPLUS.DLL" ALIAS "GdipEnumerateMetafileDestPoints" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL metafile AS DWORD _                            ' __in GDIPCONST GpMetafile *metafile
 , BYREF destPoints AS GpPointF _                       ' __in GDIPCONST GpPointF *destPoints
 , BYVAL count AS LONG _                                ' __in INT count
 , BYVAL callback AS DWORD _                            ' __in EnumerateMetafileProc callback
 , BYVAL callbackData AS DWORD _                        ' __in VOID *callbackData
 , BYVAL imageAttributes AS DWORD _                     ' __in GDIPCONST GpImageAttributes *imageAttributes
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipEnumerateMetafileDestPointsI IMPORT "GDIPLUS.DLL" ALIAS "GdipEnumerateMetafileDestPointsI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL metafile AS DWORD _                            ' __in GDIPCONST GpMetafile *metafile
 , BYREF destPoints AS GpPoint _                        ' __in GDIPCONST GpPoint *destPoints
 , BYVAL count AS LONG _                                ' __in INT count
 , BYVAL callback AS DWORD _                            ' __in EnumerateMetafileProc callback
 , BYVAL callbackData AS DWORD _                        ' __in VOID *callbackData
 , BYVAL imageAttributes AS DWORD _                     ' __in GDIPCONST GpImageAttributes *imageAttributes
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipEnumerateMetafileSrcRectDestPoint IMPORT "GDIPLUS.DLL" ALIAS "GdipEnumerateMetafileSrcRectDestPoint" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL metafile AS DWORD _                            ' __in GDIPCONST GpMetafile *metafile
 , BYREF destPoint AS GpPointF _                        ' __in GDIPCONST GpPointF *destPoint
 , BYREF srcRect AS GpRectF _                           ' __in GDIPCONST GpRectF *srcRect
 , BYVAL srcUnit AS LONG _                              ' __in GpUnit srcUnit
 , BYVAL callback AS DWORD _                            ' __in EnumerateMetafileProc callback
 , BYVAL callbackData AS DWORD _                        ' __in VOID * callbackData
 , BYVAL imageAttributes AS DWORD _                     ' __in GDIPCONST GpImageAttributes *imageAttributes
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipEnumerateMetafileSrcRectDestPointI IMPORT "GDIPLUS.DLL" ALIAS "GdipEnumerateMetafileSrcRectDestPointI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL metafile AS DWORD _                            ' __in GDIPCONST GpMetafile *metafile
 , BYREF destPoint AS GpPoint _                         ' __in GDIPCONST GpPoint *destPoint
 , BYREF srcRect AS GpRect _                            ' __in GDIPCONST GpRect *srcRect
 , BYVAL destPoint AS LONG _                            ' __in GpUnit  srcUnit
 , BYVAL callback AS DWORD _                            ' __in EnumerateMetafileProc callback
 , BYVAL callbackData AS DWORD _                        ' __in VOID *callbackData
 , BYVAL imageAttributes AS DWORD _                     ' __in GDIPCONST GpImageAttributes *imageAttributes
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipEnumerateMetafileSrcRectDestRect IMPORT "GDIPLUS.DLL" ALIAS "GdipEnumerateMetafileSrcRectDestRect" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL metafile AS DWORD _                            ' __in GDIPCONST GpMetafile *metafile
 , BYREF destRect AS GpRectF _                          ' __in GDIPCONST GpRectF *destRect
 , BYREF srcRect AS GpRectF _                           ' __in GDIPCONST GpRectF *srcRect
 , BYVAL srcUnit AS LONG _                              ' __in GpUnit srcUnit
 , BYVAL callback AS DWORD _                            ' __in EnumerateMetafileProc callback
 , BYVAL callbackData AS DWORD _                        ' __in VOID *callbackData
 , BYVAL imageAttributes AS DWORD _                     ' __in GDIPCONST GpImageAttributes *imageAttributes
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipEnumerateMetafileSrcRectDestRectI IMPORT "GDIPLUS.DLL" ALIAS "GdipEnumerateMetafileSrcRectDestRectI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL metafile AS DWORD _                            ' __in GDIPCONST GpMetafile *metafile
 , BYREF destRect AS GpRect _                           ' __in GDIPCONST GpRect *destRect
 , BYREF srcRect AS GpRect _                            ' __in GDIPCONST GpRect *srcRect
 , BYVAL srcUnit AS LONG _                              ' __in GpUnit srcUnit
 , BYVAL callback AS DWORD _                            ' __in EnumerateMetafileProc callback
 , BYVAL callbackData AS DWORD _                        ' __in VOID *callbackData
 , BYVAL imageAttributes AS DWORD _                     ' __in GDIPCONST GpImageAttributes *imageAttributes
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipEnumerateMetafileSrcRectDestPoints IMPORT "GDIPLUS.DLL" ALIAS "GdipEnumerateMetafileSrcRectDestPoints" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL metafile AS DWORD _                            ' __in GDIPCONST GpMetafile *metafile
 , BYREF destPoints AS GpPointF _                       ' __in GDIPCONST GpPointF *destPoints
 , BYVAL count AS LONG _                                ' __in INT count
 , BYREF srcRect AS GpRectF _                           ' __in GDIPCONST GpRectF *srcRect
 , BYVAL srcUnit AS LONG _                              ' __in GpUnit srcUnit
 , BYVAL callback AS DWORD _                            ' __in EnumerateMetafileProc callback
 , BYVAL callbackData AS DWORD _                        ' __in VOID *callbackData
 , BYVAL imageAttributes AS DWORD _                     ' __in GDIPCONST GpImageAttributes *imageAttributes
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipEnumerateMetafileSrcRectDestPointsI IMPORT "GDIPLUS.DLL" ALIAS "GdipEnumerateMetafileSrcRectDestPointsI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL metafile AS DWORD _                            ' __in GDIPCONST GpMetafile *metafile
 , BYREF destPoints AS GpPoint _                        ' __in GDIPCONST GpPoint *destPoints
 , BYVAL count AS LONG _                                ' __in INT count
 , BYREF srcRect AS GpRect _                            ' __in GDIPCONST GpRect *srcRect
 , BYVAL srcUnit AS LONG _                              ' __in GpUnit srcUnit
 , BYVAL callback AS DWORD _                            ' __in EnumerateMetafileProc callback
 , BYVAL callbackData AS DWORD _                        ' __in VOID *callbackData
 , BYVAL imageAttributes AS DWORD _                     ' __in GDIPCONST GpImageAttributes *imageAttributes
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipPlayMetafileRecord IMPORT "GDIPLUS.DLL" ALIAS "GdipPlayMetafileRecord" ( _
   BYVAL metafile AS DWORD _                            ' __in GDIPCONST GpMetafile *metafile
 , BYVAL recordType AS LONG _                           ' __in EmfPlusRecordType recordType
 , BYVAL flags AS DWORD _                               ' __in UINT flags
 , BYVAL dataSize AS DWORD _                            ' __in UINT dataSize
 , BYREF data AS ANY _                                  ' __in GDIPCONST BYTE *data
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetClipGraphics IMPORT "GDIPLUS.DLL" ALIAS "GdipSetClipGraphics" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL srcgraphics AS LONG _                          ' __in GpGraphics *srcgraphics
 , BYVAL combineMode AS LONG _                          ' __in CombineMode combineMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetClipRect IMPORT "GDIPLUS.DLL" ALIAS "GdipSetClipRect" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL x AS SINGLE _                                  ' __in REAL x
 , BYVAL y AS SINGLE _                                  ' __in REAL y
 , BYVAL width AS SINGLE _                              ' __in REAL width
 , BYVAL height AS SINGLE _                             ' __in REAL height
 , BYVAL combineMode AS LONG _                          ' __in CombineMode combineMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetClipRectI IMPORT "GDIPLUS.DLL" ALIAS "GdipSetClipRectI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL x AS LONG _                                    ' __in INT x
 , BYVAL y AS LONG _                                    ' __in INT y
 , BYVAL width AS LONG _                                ' __in INT width
 , BYVAL height AS LONG _                               ' __in INT height
 , BYVAL combineMode AS LONG _                          ' __in CombineMode combineMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetClipPath IMPORT "GDIPLUS.DLL" ALIAS "GdipSetClipPath" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL path AS DWORD _                                ' __in GpPath *path
 , BYVAL combineMode AS LONG _                          ' __in CombineMode combineMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetClipRegion IMPORT "GDIPLUS.DLL" ALIAS "GdipSetClipRegion" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL region AS DWORD _                              ' __in GpRegion *region
 , BYVAL combineMode AS LONG _                          ' __in CombineMode combineMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetClipHrgn IMPORT "GDIPLUS.DLL" ALIAS "GdipSetClipHrgn" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL hRgn AS DWORD _                                ' __in HRGN hRgn
 , BYVAL combineMode AS LONG _                          ' __in CombineMode combineMode
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipResetClip IMPORT "GDIPLUS.DLL" ALIAS "GdipResetClip" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipTranslateClip IMPORT "GDIPLUS.DLL" ALIAS "GdipTranslateClip" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL dx AS SINGLE _                                 ' __in REAL dx
 , BYVAL dy AS SINGLE _                                 ' __in REAL dy
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipTranslateClipI IMPORT "GDIPLUS.DLL" ALIAS "GdipTranslateClipI" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL dx AS LONG _                                   ' __in INT dx
 , BYVAL dy AS LONG _                                   ' __in INT dy
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetClip IMPORT "GDIPLUS.DLL" ALIAS "GdipGetClip" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF region AS DWORD _                              ' __out GpRegion *region
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetClipBounds IMPORT "GDIPLUS.DLL" ALIAS "GdipGetClipBounds" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF rect AS GpRectF _                              ' __out GpRectF *rect
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetClipBoundsI IMPORT "GDIPLUS.DLL" ALIAS "GdipGetClipBoundsI" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF rect AS GpRect _                               ' __out GpRect *rect
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipIsClipEmpty IMPORT "GDIPLUS.DLL" ALIAS "GdipIsClipEmpty" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF result AS LONG _                               ' __out BOOL *result
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetVisibleClipBounds IMPORT "GDIPLUS.DLL" ALIAS "GdipGetVisibleClipBounds" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF rect AS GpRectF _                              ' __out GpRectF *rect
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetVisibleClipBoundsI IMPORT "GDIPLUS.DLL" ALIAS "GdipGetVisibleClipBoundsI" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF rect AS GpRect _                               ' __out GpRect *rect
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipIsVisibleClipEmpty IMPORT "GDIPLUS.DLL" ALIAS "GdipIsVisibleClipEmpty" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF result AS LONG _                               ' __out BOOL *result
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipIsVisiblePoint IMPORT "GDIPLUS.DLL" ALIAS "GdipIsVisiblePoint" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYVAL x AS SINGLE _                                  ' __in  REAL x
 , BYVAL y AS SINGLE _                                  ' __in  REAL y
 , BYREF result AS LONG _                               ' __out BOOL *result
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipIsVisiblePointI IMPORT "GDIPLUS.DLL" ALIAS "GdipIsVisiblePointI" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYVAL x AS LONG _                                    ' __in  INT x
 , BYVAL y AS LONG _                                    ' __in  INT y
 , BYREF result AS LONG _                               ' __out BOOL *result
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipIsVisibleRect IMPORT "GDIPLUS.DLL" ALIAS "GdipIsVisibleRect" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYVAL x AS SINGLE _                                  ' __in  REAL x
 , BYVAL y AS SINGLE _                                  ' __in  REAL y
 , BYVAL width AS SINGLE _                              ' __in  REAL width
 , BYVAL height AS SINGLE _                             ' __in  REAL height
 , BYREF result AS LONG _                               ' __out BOOL *result
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipIsVisibleRectI IMPORT "GDIPLUS.DLL" ALIAS "GdipIsVisibleRectI" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYVAL x AS LONG _                                    ' __in  INT x
 , BYVAL y AS LONG _                                    ' __in  INT y
 , BYVAL width AS LONG _                                ' __in  INT width
 , BYVAL height AS LONG _                               ' __in  INT height
 , BYREF result AS LONG _                               ' __out BOOL *result
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSaveGraphics IMPORT "GDIPLUS.DLL" ALIAS "GdipSaveGraphics" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF state AS DWORD _                               ' __out GraphicsState *state
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipRestoreGraphics IMPORT "GDIPLUS.DLL" ALIAS "GdipRestoreGraphics" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL state AS DWORD _                               ' __in GraphicsState state
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipBeginContainer IMPORT "GDIPLUS.DLL" ALIAS "GdipBeginContainer" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF dstrect AS GpRectF _                           ' __in  GDIPCONST GpRectF *dstrect
 , BYREF srcrect AS GpRectF _                           ' __in  GDIPCONST GpRectF *srcrect
 , BYVAL unit AS LONG _                                 ' __in  GpUnit unit
 , BYREF state AS DWORD _                               ' __out GraphicsContainer *state
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipBeginContainerI IMPORT "GDIPLUS.DLL" ALIAS "GdipBeginContainerI" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF dstrect AS GpRect _                            ' __in  GDIPCONST GpRect *dstrect
 , BYREF srcrect AS GpRect _                            ' __in  GDIPCONST GpRect *srcrect
 , BYVAL unit AS LONG _                                 ' __in  GpUnit unit
 , BYREF state AS DWORD _                               ' __out GraphicsContainer *state
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipBeginContainer2 IMPORT "GDIPLUS.DLL" ALIAS "GdipBeginContainer2" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF state AS DWORD _                               ' __out GraphicsContainer *state
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipEndContainer IMPORT "GDIPLUS.DLL" ALIAS "GdipEndContainer" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL state AS DWORD _                               ' __in GraphicsContainer state
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetMetafileHeaderFromWmf IMPORT "GDIPLUS.DLL" ALIAS "GdipGetMetafileHeaderFromWmf" ( _
   BYVAL hWmf AS DWORD _                                ' __in  HMETAFILE hWmf
 , BYREF wmfPlaceableFileHeader AS WmfPlaceableFileHeader _ ' __in GDIPCONST WmfPlaceableFileHeader *wmfPlaceableFileHeader
 , BYREF header AS MetafileHeader _                     ' __out MetafileHeader *header
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetMetafileHeaderFromEmf IMPORT "GDIPLUS.DLL" ALIAS "GdipGetMetafileHeaderFromEmf" ( _
   BYVAL hEmf AS DWORD _                                ' __in  HENHMETAFILE hEmf
 , BYREF header AS MetafileHeader _                     ' __out MetafileHeader *header
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetMetafileHeaderFromFile IMPORT "GDIPLUS.DLL" ALIAS "GdipGetMetafileHeaderFromFile" ( _
   BYREF filename AS WSTRINGZ _                         ' __in  GDIPCONST WCHAR *filename
 , BYREF header AS MetafileHeader _                     ' __out MetafileHeader *header
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetMetafileHeaderFromStream IMPORT "GDIPLUS.DLL" ALIAS "GdipGetMetafileHeaderFromStream" ( _
   BYVAL stream AS IStream _                            ' __in  IStream *stream
 , BYREF header AS MetafileHeader _                     ' __out MetafileHeader *header
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetMetafileHeaderFromMetafile IMPORT "GDIPLUS.DLL" ALIAS "GdipGetMetafileHeaderFromMetafile" ( _
   BYVAL metafile AS DWORD _                            ' __in  GpMetafile *metafile
 , BYREF header AS MetafileHeader _                     ' __out MetafileHeader *header
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetHemfFromMetafile IMPORT "GDIPLUS.DLL" ALIAS "GdipGetHemfFromMetafile" ( _
   BYVAL metafile AS DWORD _                            ' __in  GpMetafile *metafile
 , BYREF hEmf AS DWORD _                                ' __out HENHMETAFILE *hEmf
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateStreamOnFile IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateStreamOnFile" ( _
   BYREF filename AS WSTRINGZ _                         ' __in  GDIPCONST WCHAR *filename
 , BYVAL access AS DWORD _                              ' __in  UINT access
 , BYREF stream AS IStream _                            ' __out IStream *stream
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateMetafileFromWmf IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateMetafileFromWmf" ( _
   BYVAL hWmf AS DWORD _                                ' __in  HMETAFILE hWmf
 , BYVAL deleteWmf AS LONG _                            ' __in  BOOL deleteWmf
 , BYREF wmfPlaceableFileHeader AS WmfPlaceableFileHeader _ ' __in  GDIPCONST WmfPlaceableFileHeader *wmfPlaceableFileHeader
 , BYREF metafile AS DWORD _                            ' __out GpMetafile **metafile
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateMetafileFromEmf IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateMetafileFromEmf" ( _
   BYVAL hEmf AS DWORD _                                ' __in  HENHMETAFILE hEmf
 , BYVAL deleteEmf AS LONG _                            ' __in  BOOL deleteEmf
 , BYREF metafile AS DWORD _                            ' __out GpMetafile **metafile
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateMetafileFromFile IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateMetafileFromFile" ( _
   BYREF filename AS WSTRINGZ _                         ' __in  GDIPCONST WCHAR *filename
 , BYREF metafile AS DWORD _                            ' __out GpMetafile **metafile
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateMetafileFromWmfFile IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateMetafileFromWmfFile" ( _
   BYREF filename AS WSTRINGZ _                         ' __in  GDIPCONST WCHAR *filename
 , BYREF wmfPlaceableFileHeader AS WmfPlaceableFileHeader _ ' __in  GDIPCONST WmfPlaceableFileHeader *wmfPlaceableFileHeader
 , BYREF metafile AS DWORD _                            ' __out GpMetafile **metafile
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateMetafileFromStream IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateMetafileFromStream" ( _
   BYVAL stream AS IStream _                            ' __in  IStream *stream
 , BYREF metafile AS DWORD _                            ' __out GpMetafile **metafile
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipRecordMetafile IMPORT "GDIPLUS.DLL" ALIAS "GdipRecordMetafile" ( _
   BYVAL referenceHdc AS DWORD _                        ' __in  HDC referenceHdc
 , BYVAL type AS LONG _                                 ' __in  EmfType type
 , BYREF frameRect AS GpRectF _                         ' __in  GDIPCONST GpRectF *frameRect
 , BYVAL frameUnit AS LONG _                            ' __in  MetafileFrameUnit frameUnit
 , BYREF description AS WSTRINGZ _                      ' __in  GDIPCONST WCHAR *description
 , BYREF metafile AS DWORD _                            ' __out GpMetafile **metafile
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipRecordMetafileI IMPORT "GDIPLUS.DLL" ALIAS "GdipRecordMetafileI" ( _
   BYVAL referenceHdc AS DWORD _                            ' __in  HDC referenceHdc
 , BYVAL type AS LONG _                                 ' __in  EmfType type
 , BYREF frameRect AS GpRect _                          ' __in  GDIPCONST GpRect *frameRect
 , BYVAL frameUnit AS LONG _                            ' __in  MetafileFrameUnit frameUnit
 , BYREF description AS WSTRINGZ _                      ' __in  GDIPCONST WCHAR *description
 , BYREF metafile AS DWORD _                            ' __out GpMetafile **metafile
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipRecordMetafileFileName IMPORT "GDIPLUS.DLL" ALIAS "GdipRecordMetafileFileName" ( _
   BYREF fileName AS WSTRINGZ _                         ' __in  GDIPCONST WCHAR *fileName
 , BYVAL referenceHdc AS DWORD _                        ' __in  HDC referenceHdc
 , BYVAL type AS LONG _                                 ' __in  EmfType type
 , BYREF frameRect AS GpRectF _                         ' __in  GDIPCONST GpRectF *frameRect
 , BYVAL frameUnit AS LONG _                            ' __in  MetafileFrameUnit frameUnit
 , BYREF description AS WSTRINGZ _                      ' __in  GDIPCONST WCHAR *description
 , BYREF metafile AS DWORD _                            ' __out GpMetafile **metafile
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipRecordMetafileFileNameI IMPORT "GDIPLUS.DLL" ALIAS "GdipRecordMetafileFileNameI" ( _
   BYREF fileName AS WSTRINGZ _                         ' __in  GDIPCONST WCHAR *fileName
 , BYVAL referenceHdc AS DWORD _                        ' __in  HDC referenceHdc
 , BYVAL type AS LONG _                                 ' __in  EmfType type
 , BYREF frameRect AS GpRect _                          ' __in  GDIPCONST GpRect *frameRect
 , BYVAL frameUnit AS LONG _                            ' __in  MetafileFrameUnit frameUnit
 , BYREF description AS WSTRINGZ _                      ' __in  GDIPCONST WCHAR *description
 , BYREF metafile AS DWORD _                            ' __out GpMetafile **metafile
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipRecordMetafileStream IMPORT "GDIPLUS.DLL" ALIAS "GdipRecordMetafileStream" ( _
   BYVAL stream AS IStream _                           ' __in  IStream *stream
 , BYVAL referenceHdc AS DWORD _                        ' __in  HDC referenceHdc
 , BYVAL type AS LONG _                                 ' __in  EmfType type
 , BYREF frameRect AS GpRectF _                         ' __in  GDIPCONST GpRectF *frameRect
 , BYVAL frameUnit AS LONG _                            ' __in  MetafileFrameUnit frameUnit
 , BYREF description AS WSTRINGZ _                      ' __in  GDIPCONST WCHAR *description
 , BYREF metafile AS DWORD _                            ' __out GpMetafile **metafile
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipRecordMetafileStreamI IMPORT "GDIPLUS.DLL" ALIAS "GdipRecordMetafileStreamI" ( _
   BYVAL stream AS IStream _                            ' __in  IStream *stream
 , BYVAL referenceHdc AS DWORD _                        ' __in  HDC referenceHdc
 , BYVAL type AS LONG _                                 ' __in  EmfType type
 , BYREF frameRect AS GpRect _                          ' __in  GDIPCONST GpRect *frameRect
 , BYVAL frameUnit AS LONG _                            ' __in  MetafileFrameUnit frameUnit
 , BYREF description AS WSTRINGZ _                      ' __in  GDIPCONST WCHAR *description
 , BYREF metafile AS DWORD _                            ' __out GpMetafile **metafile
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetMetafileDownLevelRasterizationLimit IMPORT "GDIPLUS.DLL" ALIAS "GdipSetMetafileDownLevelRasterizationLimit" ( _
   BYVAL metafile AS DWORD _                            ' __in GpMetafile *metafile
 , BYVAL metafileRasterizationLimitDpi AS LONG _        ' __in UINT metafileRasterizationLimitDpi
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetMetafileDownLevelRasterizationLimit IMPORT "GDIPLUS.DLL" ALIAS "GdipGetMetafileDownLevelRasterizationLimit" ( _
   BYVAL metafile AS DWORD _                            ' __in  GDIPCONST GpMetafile *metafile
 , BYREF metafileRasterizationLimitDpi AS DWORD _       ' __out UINT *metafileRasterizationLimitDpi
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetImageDecodersSize IMPORT "GDIPLUS.DLL" ALIAS "GdipGetImageDecodersSize" ( _
   BYREF numDecoders AS DWORD _                         ' __in  UINT *numDecoders
 , BYREF size AS DWORD _                                ' __out UINT *size
 ) AS LONG                                              ' Status

DECLARE FUNCTION GdipGetImageDecoders IMPORT "GDIPLUS.DLL" ALIAS "GdipGetImageDecoders" ( _
   BYVAL numDecoders AS DWORD _                         ' __in  UINT numDecoders
 , BYVAL size AS DWORD _                                ' __in  UINT size
 , BYREF decoders AS ANY _                              ' __out ImageCodecInfo *decoders
 ) AS LONG                                              ' Status

DECLARE FUNCTION GdipGetImageEncodersSize IMPORT "GDIPLUS.DLL" ALIAS "GdipGetImageEncodersSize" ( _
   BYREF numEncoders AS DWORD _                         ' __in  UINT *numEncoders
 , BYREF size AS DWORD _                                ' __out UINT *size
 ) AS LONG                                              ' Status

DECLARE FUNCTION GdipGetImageEncoders IMPORT "GDIPLUS.DLL" ALIAS "GdipGetImageEncoders" ( _
   BYVAL numEncoders AS DWORD _                         ' __in  UINT numEncoders
 , BYVAL size AS DWORD _                                ' __in  UINT size
 , BYREF encoders AS ANY _                              ' __out ImageCodecInfo *encoders
 ) AS LONG                                              ' Status

DECLARE FUNCTION GdipComment IMPORT "GDIPLUS.DLL" ALIAS "GdipComment" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYVAL sizeData AS DWORD _                            ' __in  UINT sizeData
 , BYREF data AS ANY _                                  ' __out GDIPCONST BYTE *data
 ) AS LONG                                              ' GpStatus

'//----------------------------------------------------------------------------
'// FontFamily APIs
'//----------------------------------------------------------------------------

DECLARE FUNCTION GdipCreateFontFamilyFromName IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateFontFamilyFromName" ( _
   BYREF name AS WSTRINGZ _                             ' __in  GDIPCONST WCHAR *name
 , BYVAL fontCollection AS DWORD _                      ' __in  GpFontCollection *fontCollection
 , BYREF fontFamily AS DWORD _                          ' __out GpFontFamily **fontFamily
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDeleteFontFamily IMPORT "GDIPLUS.DLL" ALIAS "GdipDeleteFontFamily" ( _
   BYVAL fontFamily AS DWORD _                          ' __in  GpFontFamily *fontFamily
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCloneFontFamily IMPORT "GDIPLUS.DLL" ALIAS "GdipCloneFontFamily" ( _
   BYVAL fontFamily AS DWORD _                          ' __in  GpFontFamily *fontFamily
 , BYREF clonedFontFamily AS DWORD _                    ' __out GpFontFamily **clonedFontFamily
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetGenericFontFamilySansSerif IMPORT "GDIPLUS.DLL" ALIAS "GdipGetGenericFontFamilySansSerif" ( _
   BYREF nativeFamily AS DWORD _                        ' __out GpFontFamily **nativeFamily
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetGenericFontFamilySerif IMPORT "GDIPLUS.DLL" ALIAS "GdipGetGenericFontFamilySerif" ( _
   BYREF nativeFamily AS DWORD _                        ' __out GpFontFamily **nativeFamily
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetGenericFontFamilyMonospace IMPORT "GDIPLUS.DLL" ALIAS "GdipGetGenericFontFamilyMonospace" ( _
   BYREF nativeFamily AS DWORD _                        ' __out GpFontFamily **nativeFamily
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetFamilyName IMPORT "GDIPLUS.DLL" ALIAS "GdipGetFamilyName" ( _
   BYVAL family AS DWORD _                              ' __in GDIPCONST GpFontFamily *family
 , BYREF name AS WSTRINGZ _                             ' __in WCHAR name[LF_FACESIZE]
 , BYVAL language AS WORD _                             ' __in LANGID language
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipIsStyleAvailable IMPORT "GDIPLUS.DLL" ALIAS "GdipIsStyleAvailable" ( _
   BYVAL family AS DWORD _                              ' __in  GDIPCONST GpFontFamily *family
 , BYVAL style AS LONG _                                ' __in  INT style
 , BYREF IsStyleAvailable AS LONG _                     ' __out BOOL IsStyleAvailable
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipFontCollectionEnumerable IMPORT "GDIPLUS.DLL" ALIAS "GdipFontCollectionEnumerable" ( _
   BYVAL fontCollection AS DWORD _                      ' __in  GpFontCollection *fontCollection
 , BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF numFound AS LONG _                             ' __out INT *numFound
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipFontCollectionEnumerate IMPORT "GDIPLUS.DLL" ALIAS "GdipFontCollectionEnumerate" ( _
   BYVAL fontCollection AS DWORD _                      ' __in  GpFontCollection *fontCollection
 , BYVAL numSought AS LONG _                            ' __in  INT numSought
 , BYREF gpfamilies AS DWORD _                          ' __out GpFontFamily *gpfamilies[]
 , BYREF numFound AS LONG _                             ' __out INT *numFound
 , BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetEmHeight IMPORT "GDIPLUS.DLL" ALIAS "GdipGetEmHeight" ( _
   BYVAL family AS DWORD _                              ' __in  GDIPCONST GpFontFamily *family
 , BYVAL style AS LONG _                                ' __in  INT style
 , BYREF EmHeight AS WORD _                             ' __out UINT16 *EmHeight
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetCellAscent IMPORT "GDIPLUS.DLL" ALIAS "GdipGetCellAscent" ( _
   BYVAL family AS DWORD _                              ' __in  GDIPCONST GpFontFamily *family
 , BYVAL style AS LONG _                                ' __in  INT style
 , BYREF CellAscent AS WORD _                           ' __out UINT16 *CellAscent
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetCellDescent IMPORT "GDIPLUS.DLL" ALIAS "GdipGetCellDescent" ( _
   BYVAL family AS DWORD _                              ' __in  GDIPCONST GpFontFamily *family
 , BYVAL style AS LONG _                                ' __in  INT style
 , BYREF CellDescent AS WORD _                          ' __out UINT16 *CellDescent
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetLineSpacing IMPORT "GDIPLUS.DLL" ALIAS "GdipGetLineSpacing" ( _
   BYVAL family AS DWORD _                              ' __in  GDIPCONST GpFontFamily *family
 , BYVAL style AS LONG _                                ' __in  INT style
 , BYREF LineSpacing AS WORD _                          ' __out UINT16 *LineSpacing
 ) AS LONG                                              ' GpStatus


'//----------------------------------------------------------------------------
'// Font APIs
'//----------------------------------------------------------------------------

DECLARE FUNCTION GdipCreateFontFromDC IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateFontFromDC" ( _
   BYVAL hdc AS DWORD _                                 ' __in  HDC hdc
 , BYREF font AS DWORD _                                ' __out GpFont **font
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateFontFromLogfontA IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateFontFromLogfontA" ( _
   BYVAL hdc AS DWORD _                                 ' __in  HDC hdc
 , BYREF logfont AS LOGFONTA _                          ' __in  GDIPCONST LOGFONTA *logfont
 , BYREF font AS DWORD _                                ' __out GpFont **font
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCreateFontFromLogfontW IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateFontFromLogfontW" ( _
   BYVAL hdc AS DWORD _                                 ' __in  HDC hdc
 , BYREF logfont AS LOGFONTW _                          ' __in  GDIPCONST LOGFONTW *logfont
 , BYREF font AS DWORD _                                ' __out GpFont **font
 ) AS LONG                                              ' GpStatus

#IF %DEF(%UNICODE)
MACRO GdipCreateFontFromLogfont = GdipCreateFontFromLogfontW
#ELSE
MACRO GdipCreateFontFromLogfont = GdipCreateFontFromLogfontA
#ENDIF

DECLARE FUNCTION GdipCreateFont IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateFont" ( _
   BYVAL fontFamily AS DWORD _                          ' __in  GDIPCONST GpFontFamily *fontFamily
 , BYVAL emSize AS SINGLE _                             ' __in  REAL emSize
 , BYVAL style AS LONG _                                ' __in  INT style
 , BYVAL unit AS LONG _                                 ' __in  GpUnit unit
 , BYREF font AS DWORD _                                ' __out GpFont **font
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCloneFont IMPORT "GDIPLUS.DLL" ALIAS "GdipCloneFont" ( _
   BYVAL font AS DWORD _                                ' __in  GpFont *font
 , BYREF cloneFont AS DWORD _                           ' __out GpFont **cloneFont
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDeleteFont IMPORT "GDIPLUS.DLL" ALIAS "GdipDeleteFont" ( _
   BYVAL font AS DWORD _                                ' __in  GpFont *font
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetFamily IMPORT "GDIPLUS.DLL" ALIAS "GdipGetFamily" ( _
   BYVAL font AS DWORD _                                ' __in  GpFont *font
 , BYREF family AS DWORD _                              ' __out GpFontFamily **family
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetFontStyle IMPORT "GDIPLUS.DLL" ALIAS "GdipGetFontStyle" ( _
   BYVAL font AS DWORD _                                ' __in  GpFont *font
 , BYREF style AS LONG _                                ' __out INT *style
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetFontSize IMPORT "GDIPLUS.DLL" ALIAS "GdipGetFontSize" ( _
   BYVAL font AS DWORD _                                ' __in  GpFont *font
 , BYREF size AS SINGLE _                               ' __out REAL *size
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetFontUnit IMPORT "GDIPLUS.DLL" ALIAS "GdipGetFontUnit" ( _
   BYVAL font AS DWORD _                                ' __in  GpFont *font
 , BYREF unit AS LONG _                                 ' __out GpUnit *unit
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetFontHeight IMPORT "GDIPLUS.DLL" ALIAS "GdipGetFontHeight" ( _
   BYVAL font AS DWORD _                                ' __in  GDIPCONST GpFont *font
 , BYVAL graphics AS DWORD _                            ' __in  GDIPCONST GpGraphics *graphics
 , BYREF height AS SINGLE _                             ' __out REAL *height
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetFontHeightGivenDPI IMPORT "GDIPLUS.DLL" ALIAS "GdipGetFontHeightGivenDPI" ( _
   BYVAL font AS DWORD _                                ' __in  GDIPCONST GpFont *font
 , BYVAL dpi AS SINGLE _                                ' __in  REAL dpi
 , BYREF height AS SINGLE _                             ' __out REAL *height
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetLogFontA IMPORT "GDIPLUS.DLL" ALIAS "GdipGetLogFontA" ( _
   BYVAL font AS DWORD _                                ' __in  GpFont *font
 , BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF logfontA AS LOGFONTA _                         ' __out LOGFONTA *logfontA
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetLogFontW IMPORT "GDIPLUS.DLL" ALIAS "GdipGetLogFontW" ( _
   BYVAL font AS DWORD _                                ' __in  GpFont *font
 , BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF logfontW AS LOGFONTW _                         ' __out LOGFONTW *logfontW
 ) AS LONG                                              ' GpStatus

#IF %DEF(%UNICODE)
MACRO GdipGetLogFont = GdipGetLogFontW
#ELSE
MACRO GdipGetLogFont = GdipGetLogFontA
#ENDIF

DECLARE FUNCTION GdipNewInstalledFontCollection IMPORT "GDIPLUS.DLL" ALIAS "GdipNewInstalledFontCollection" ( _
   BYREF fontCollection AS DWORD _                      ' __out GpFontCollection **fontCollection
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipNewPrivateFontCollection IMPORT "GDIPLUS.DLL" ALIAS "GdipNewPrivateFontCollection" ( _
   BYREF fontCollection AS DWORD _                      ' __out GpFontCollection **fontCollection
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDeletePrivateFontCollection IMPORT "GDIPLUS.DLL" ALIAS "GdipDeletePrivateFontCollection" ( _
   BYREF fontCollection AS DWORD _                      ' __out GpFontCollection **fontCollection
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetFontCollectionFamilyCount IMPORT "GDIPLUS.DLL" ALIAS "GdipGetFontCollectionFamilyCount" ( _
   BYVAL fontCollection AS DWORD _                      ' __in  GpFontCollection *fontCollection
 , BYREF numFound AS LONG _                             ' __out INT *numFound
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetFontCollectionFamilyList IMPORT "GDIPLUS.DLL" ALIAS "GdipGetFontCollectionFamilyList" ( _
   BYVAL fontCollection AS DWORD _                      ' __in  GpFontCollection *fontCollection
 , BYVAL numSought AS LONG _                            ' __in  INT numSought
 , BYREF gpfamilies AS DWORD _                          ' __out GpFontFamily *gpfamilies[]
 , BYREF numFound AS LONG _                             ' __out INT *numFound
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipPrivateAddFontFile IMPORT "GDIPLUS.DLL" ALIAS "GdipPrivateAddFontFile" ( _
   BYVAL fontCollection AS DWORD _                      ' __in GpFontCollection *fontCollection
 , BYREF filename AS WSTRINGZ _                         ' __in GDIPCONST WCHAR *filename
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipPrivateAddMemoryFont IMPORT "GDIPLUS.DLL" ALIAS "GdipPrivateAddMemoryFont" ( _
   BYVAL fontCollection AS DWORD _                      ' __in GpFontCollection *fontCollection
 , BYVAL memory AS DWORD _                              ' __in GDIPCONST void *memory
 , BYVAL length AS LONG _                               ' __in INT length
 ) AS LONG                                              ' GpStatus

'//----------------------------------------------------------------------------
'// Text APIs
'//----------------------------------------------------------------------------

DECLARE FUNCTION GdipDrawString IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawString" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYREF string AS WSTRINGZ _                           ' __in GDIPCONST WCHAR *string
 , BYVAL length AS LONG _                               ' __in INT length
 , BYVAL font AS DWORD _                                ' __in GDIPCONST GpFont *font
 , BYREF layoutRect AS GpRectF _                        ' __in GDIPCONST GpRectF *layoutRect
 , BYVAL stringFormat AS DWORD _                        ' __in GDIPCONST GpStringFormat *stringFormat
 , BYVAL brush AS DWORD _                               ' __in GpBrush *brush
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipMeasureString IMPORT "GDIPLUS.DLL" ALIAS "GdipMeasureString" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF string AS WSTRINGZ _                           ' __in  GDIPCONST WCHAR *string
 , BYVAL length AS LONG _                               ' __in  INT length
 , BYVAL font AS DWORD _                                ' __in  GDIPCONST GpFont *font
 , BYREF layoutRect AS GpRectF _                        ' __in  GDIPCONST GpRectF *layoutRect
 , BYVAL stringFormat AS DWORD _                        ' __in  GDIPCONST GpStringFormat *stringFormat
 , BYREF boundingBox AS GpRectF _                       ' __in  GpRectF *boundingBox
 , BYREF codepointsFitted AS LONG _                     ' __in  INT *codepointsFitted
 , BYREF linesFilled AS LONG _                          ' __out INT *linesFilled
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipMeasureCharacterRanges IMPORT "GDIPLUS.DLL" ALIAS "GdipMeasureCharacterRanges" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF string AS WSTRINGZ _                           ' __in  GDIPCONST WCHAR *string
 , BYVAL length AS LONG _                               ' __in  INT length
 , BYVAL font AS DWORD _                                ' __in  GDIPCONST GpFont *font
 , BYREF layoutRect AS GpRectF _                        ' __in  GDIPCONST GpRectF *layoutRect
 , BYVAL stringFormat AS DWORD _                        ' __in  GDIPCONST GpStringFormat *stringFormat
 , BYVAL regionCount AS LONG _                          ' __in  INT regionCount
 , BYREF region AS DWORD _                              ' __out GpRegion **regions
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawDriverString IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawDriverString" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYREF text AS WORD _                                 ' __in GDIPCONST WCHAR *text
 , BYVAL length AS LONG _                               ' __in INT length
 , BYVAL length AS DWORD _                              ' __in GDIPCONST GpFont *font
 , BYVAL brush AS DWORD _                               ' __in GDIPCONST GpBrush *brush
 , BYREF positions AS GpPointF _                        ' __in GDIPCONST GpPointF *positions
 , BYVAL flags AS LONG _                                ' __in INT flags
 , BYVAL matrix AS DWORD _                              ' __in GDIPCONST GpMatrix *matrix
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipMeasureDriverString IMPORT "GDIPLUS.DLL" ALIAS "GdipMeasureDriverString" ( _
   BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF text AS WORD _                                 ' __in  GDIPCONST WCHAR *text
 , BYVAL length AS LONG _                               ' __in  INT length
 , BYVAL font AS DWORD _                                ' __in  GDIPCONST GpFont *font
 , BYREF positions AS GpPointF _                        ' __in  GDIPCONST GpPointF *positions
 , BYVAL flags AS LONG _                                ' __in  INT flags
 , BYVAL matrix AS DWORD _                              ' __in  GDIPCONST GpMatrix *matrix
 , BYREF boundingBox AS GpRectF _                       ' __out GpRectF *boundingBox
 ) AS LONG                                              ' GpStatus

'//----------------------------------------------------------------------------
'// String format APIs
'//----------------------------------------------------------------------------

DECLARE FUNCTION GdipCreateStringFormat IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateStringFormat" ( _
   BYVAL formatAttributes AS LONG _                     ' __in  INT formatAttributes
 , BYVAL language AS WORD _                             ' __in  LANGID language
 , BYREF format AS DWORD _                              ' __out GpStringFormat **format
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipStringFormatGetGenericDefault IMPORT "GDIPLUS.DLL" ALIAS "GdipStringFormatGetGenericDefault" ( _
   BYREF format AS DWORD _                              ' __out GpStringFormat **format
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipStringFormatGetGenericTypographic IMPORT "GDIPLUS.DLL" ALIAS "GdipStringFormatGetGenericTypographic" ( _
   BYREF format AS DWORD _                              ' __out GpStringFormat **format
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDeleteStringFormat IMPORT "GDIPLUS.DLL" ALIAS "GdipDeleteStringFormat" ( _
   BYVAL format AS DWORD _                              ' __in GDIPCONST GpStringFormat *format
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipCloneStringFormat IMPORT "GDIPLUS.DLL" ALIAS "GdipCloneStringFormat" ( _
   BYVAL format AS DWORD _                              ' __in  GDIPCONST GpStringFormat *format
 , BYREF newFormat AS DWORD _                           ' __out GpStringFormat **newFormat
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetStringFormatFlags IMPORT "GDIPLUS.DLL" ALIAS "GdipSetStringFormatFlags" ( _
   BYVAL format AS DWORD _                              ' __in GDIPCONST GpStringFormat *format
 , BYVAL flags AS LONG _                                ' __in INT flags
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetStringFormatFlags IMPORT "GDIPLUS.DLL" ALIAS "GdipGetStringFormatFlags" ( _
   BYVAL format AS DWORD _                              ' __in  GDIPCONST GpStringFormat *format
 , BYREF flags AS LONG _                                ' __out INT *flags
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetStringFormatAlign IMPORT "GDIPLUS.DLL" ALIAS "GdipSetStringFormatAlign" ( _
   BYVAL format AS DWORD _                              ' __in GDIPCONST GpStringFormat *format
 , BYVAL align AS LONG _                                ' __in StringAlignment align
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetStringFormatAlign IMPORT "GDIPLUS.DLL" ALIAS "GdipGetStringFormatAlign" ( _
   BYVAL format AS DWORD _                              ' __in  GDIPCONST GpStringFormat *format
 , BYREF align AS LONG _                                ' __out StringAlignment *align
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetStringFormatLineAlign IMPORT "GDIPLUS.DLL" ALIAS "GdipSetStringFormatLineAlign" ( _
   BYVAL format AS DWORD _                              ' __in GDIPCONST GpStringFormat *format
 , BYVAL align AS LONG _                                ' __in StringAlignment align
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetStringFormatLineAlign IMPORT "GDIPLUS.DLL" ALIAS "GdipGetStringFormatLineAlign" ( _
   BYVAL format AS DWORD _                              ' __in  GDIPCONST GpStringFormat *format
 , BYREF align AS LONG _                                ' __out StringAlignment *align
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetStringFormatTrimming IMPORT "GDIPLUS.DLL" ALIAS "GdipSetStringFormatTrimming" ( _
   BYVAL format AS DWORD _                              ' GDIPCONST GpStringFormat *format
 , BYVAL trimming AS LONG _                             ' StringTrimming trimming
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetStringFormatTrimming IMPORT "GDIPLUS.DLL" ALIAS "GdipGetStringFormatTrimming" ( _
   BYVAL format AS DWORD _                              ' __in  GDIPCONST GpStringFormat *format
 , BYREF trimming AS LONG _                             ' __out StringTrimming *trimming
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetStringFormatHotkeyPrefix IMPORT "GDIPLUS.DLL" ALIAS "GdipSetStringFormatHotkeyPrefix" ( _
   BYVAL format AS DWORD _                              ' __in GDIPCONST GpStringFormat *format
 , BYVAL hotkeyPrefix AS LONG _                         ' __in INT hotkeyPrefix
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetStringFormatHotkeyPrefix IMPORT "GDIPLUS.DLL" ALIAS "GdipGetStringFormatHotkeyPrefix" ( _
   BYVAL format AS DWORD _                              ' __in  GDIPCONST GpStringFormat *format
 , BYREF hotkeyPrefix AS LONG _                         ' __out INT *hotkeyPrefix
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetStringFormatTabStops IMPORT "GDIPLUS.DLL" ALIAS "GdipSetStringFormatTabStops" ( _
   BYVAL format AS DWORD _                              ' __in  GDIPCONST GpStringFormat *format
 , BYVAL firstTabOffset AS SINGLE _                     ' __in  REAL firstTabOffset
 , BYVAL count AS LONG _                                ' __in  INT count
 , BYREF tabStops AS SINGLE _                           ' __out GDIPCONST REAL *tabStops
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetStringFormatTabStops IMPORT "GDIPLUS.DLL" ALIAS "GdipGetStringFormatTabStops" ( _
   BYVAL format AS DWORD _                              ' __in  GDIPCONST GpStringFormat *format
 , BYVAL count AS LONG _                                ' __in  INT count
 , BYREF firstTabOffset AS SINGLE _                     ' __out REAL *firstTabOffset
 , BYREF tabStops AS SINGLE _                           ' __out REAL *tabStops
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetStringFormatTabStopCount IMPORT "GDIPLUS.DLL" ALIAS "GdipGetStringFormatTabStopCount" ( _
   BYVAL format AS DWORD _                              ' __in  GDIPCONST GpStringFormat *format
 , BYREF count AS LONG _                                ' __out INT *count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetStringFormatDigitSubstitution IMPORT "GDIPLUS.DLL" ALIAS "GdipSetStringFormatDigitSubstitution" ( _
   BYVAL format AS DWORD _                              ' __in GDIPCONST GpStringFormat *format
 , BYVAL language AS WORD _                             ' __in LANGID language
 , BYVAL substitute AS LONG _                           ' __in StringDigitSubstitute substitute
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetStringFormatDigitSubstitution IMPORT "GDIPLUS.DLL" ALIAS "GdipGetStringFormatDigitSubstitution" ( _
   BYVAL format AS DWORD _                              ' __in  GDIPCONST GpStringFormat *format
 , BYREF language AS WORD _                             ' __out LANGID *language
 , BYREF substitute AS LONG _                           ' __out StringDigitSubstitute *substitute
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipGetStringFormatMeasurableCharacterRangeCount IMPORT "GDIPLUS.DLL" ALIAS "GdipGetStringFormatMeasurableCharacterRangeCount" ( _
   BYVAL format AS DWORD _                              ' __in  GDIPCONST GpStringFormat *format
 , BYREF count AS LONG _                                ' __out INT *count
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipSetStringFormatMeasurableCharacterRanges IMPORT "GDIPLUS.DLL" ALIAS "GdipSetStringFormatMeasurableCharacterRanges" ( _
   BYVAL format AS DWORD _                              ' __in  GDIPCONST GpStringFormat *format
 , BYVAL rangeCount AS LONG _                           ' __in  INT rangeCount
 , BYREF ranges AS CharacterRange _                     ' __out CharacterRange *ranges
 ) AS LONG                                              ' GpStatus

'//----------------------------------------------------------------------------
'// Cached Bitmap APIs
'//----------------------------------------------------------------------------

DECLARE FUNCTION GdipCreateCachedBitmap IMPORT "GDIPLUS.DLL" ALIAS "GdipCreateCachedBitmap" ( _
   BYVAL bitmap AS DWORD _                              ' __in  GpBitmap *bitmap
 , BYVAL graphics AS DWORD _                            ' __in  GpGraphics *graphics
 , BYREF cachedBitmap AS DWORD _                        ' __out GpCachedBitmap **cachedBitmap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDeleteCachedBitmap IMPORT "GDIPLUS.DLL" ALIAS "GdipDeleteCachedBitmap" ( _
   BYVAL cachedBitmap AS DWORD _                        ' __in GpCachedBitmap *cachedBitmap
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipDrawCachedBitmap IMPORT "GDIPLUS.DLL" ALIAS "GdipDrawCachedBitmap" ( _
   BYVAL graphics AS DWORD _                            ' __in GpGraphics *graphics
 , BYVAL cachedBitmap AS DWORD _                        ' __in GpCachedBitmap *cachedBitmap
 , BYVAL x AS LONG _                                    ' __in LONG x
 , BYVAL y AS LONG _                                    ' __in LONG y
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipEmfToWmfBits IMPORT "GDIPLUS.DLL" ALIAS "GdipEmfToWmfBits" ( _
   BYVAL hemf AS DWORD _                                ' __in HENHMETAFILE hemf
 , BYVAL cbData16 AS DWORD _                            ' __in UINT cbData16
 , BYREF pData16 AS ANY _                               ' __in LPBYTE pData16
 , BYVAL iMapMode AS LONG _                             ' __in LONG iMapMode
 , BYVAL eFlags AS LONG _                               ' __in LONG eFlags
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GdipSetImageAttributesCachedBackground IMPORT "GDIPLUS.DLL" ALIAS "GdipSetImageAttributesCachedBackground" ( _
   BYVAL imageattr AS DWORD _                           ' __in GpImageAttributes *imageattr
 , BYVAL enableFlag AS LONG _                           ' __in BOOL enableFlag
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipTestControl IMPORT "GDIPLUS.DLL" ALIAS "GdipTestControl" ( _
   BYVAL control AS DWORD _                             ' __in GpTestControlEnum control
 , BYVAL param AS DWORD _                               ' __in void *param
 ) AS LONG                                              ' GpStatus

'FUNCTION GdiplusNotificationHook ( _
'   BYREF token AS DWORD _                               ' __out ULONG_PTR *token
' ) AS LONG                                              ' GpStatus

'SUB GdiplusNotificationHook ( _
'   BYVAL token AS DWORD _                               ' __in ULONG_PTR token
' )                                                      ' void

#IF (%GDIPVER >= &H0110)

DECLARE FUNCTION GdipConvertToEmfPlus IMPORT "GDIPLUS.DLL" ALIAS "GdipConvertToEmfPlus" ( _
   BYVAL refGraphics AS DWORD _                         ' __in  const GpGraphics* refGraphics
 , BYVAL metafile AS DWORD _                            ' __in  GpMetafile*  metafile
 , BYREF conversionFailureFlag AS LONG _                ' __out INT* conversionFailureFlag
 , BYVAL emfType AS LONG _                              ' __in  EmfType      emfType
 , BYREF description AS WSTRINGZ _                      ' __in  const WCHAR* description
 , BYREF out_metafile AS DWORD _                        ' __out GpMetafile** out_metafile
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipConvertToEmfPlusToFile IMPORT "GDIPLUS.DLL" ALIAS "GdipConvertToEmfPlusToFile" ( _
   BYVAL refGraphics AS DWORD _                         ' __in  const GpGraphics* refGraphics
 , BYVAL metafile AS DWORD _                            ' __in  GpMetafile*  metafile
 , BYREF conversionFailureFlag AS LONG _                ' __out INT* conversionFailureFlag
 , BYREF filename AS WSTRINGZ _                         ' __in  const WCHAR* filename
 , BYVAL emfType AS LONG _                              ' __in  EmfType      emfType
 , BYREF description AS WSTRINGZ _                      ' __in  const WCHAR* description
 , BYREF out_metafile AS DWORD _                        ' __out GpMetafile** out_metafile
 ) AS LONG                                              ' GpStatus

DECLARE FUNCTION GdipConvertToEmfPlusToStream IMPORT "GDIPLUS.DLL" ALIAS "GdipConvertToEmfPlusToStream" ( _
   BYVAL refGraphics AS DWORD _                         ' __in  const GpGraphics* refGraphics
 , BYVAL metafile AS DWORD _                            ' __in  GpMetafile*  metafile
 , BYREF conversionFailureFlag AS LONG _                ' __out INT* conversionFailureFlag
 , BYVAL stream AS IStream _                            ' __in  IStream* stream
 , BYVAL emfType AS LONG _                              ' __in  EmfType      emfType
 , BYREF description AS WSTRINGZ _                      ' __in  const WCHAR* description
 , BYREF out_metafile AS DWORD _                        ' __out GpMetafile** out_metafile
 ) AS LONG                                              ' GpStatus

#ENDIF   ' //(%GDIPVER >= &H0110)
