' ########################################################################################
' Microsoft Windows
' File: CGdipPath.inc
' Contents: GDI+ image class.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CGDIPPATH_INC = 1

' ########################################################################################
' CGdipGraphicsPath Class
' ########################################################################################
CLASS CGdipGraphicsPath

   INSTANCE m_hStatus AS LONG
   INSTANCE m_pGraphicsPath AS DWORD

   ' =====================================================================================
   ' Cleanup
   ' =====================================================================================
   CLASS METHOD Destroy
      IF m_pGraphicsPath THEN GdipDeletePath(m_pGraphicsPath)
   END METHOD
   ' =====================================================================================

   INTERFACE IGdipGraphicsPath : INHERIT IAutomation

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the Image object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pGraphicsPath
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the Image object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      IF m_pGraphicsPath THEN GdipDeletePath(m_pGraphicsPath)
      m_pGraphicsPath = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a GraphicsPath object and initializes the fill mode. This is the default constructor.
   ' Default value for fillMode: FillModeAlternate(0).
   ' =====================================================================================
   METHOD GraphicsPath (OPTIONAL BYVAL fillMode AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipCreatePath(fillMode, m_pGraphicsPath)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a GraphicsPath object based on an array of points, an array of types, and a fill mode.
   ' Default value for filolMode: FillModeAlternate(0).
   ' =====================================================================================
   METHOD GraphicsPathPoint (BYREF pts AS PointF, BYREF types AS BYTE, BYVAL nCount AS LONG, BYVAL fillMode AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipCreatePath2(pts, types, nCount, fillmode, m_pGraphicsPath)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new Path object based on this Path object.
   ' =====================================================================================
   METHOD Clone () THREADSAFE AS IGdipGraphicsPath
      LOCAL pGraphicsPath AS IGdipGraphicsPath
      LOCAL pGraphicsPathPtr AS DWORD
      m_hStatus = GdipClonePath(m_pGraphicsPath, pGraphicsPathPtr)
      pGraphicsPath = CLASS "CGdipGraphicsPath"
      pGraphicsPath.Ptr = pGraphicsPathPtr
      METHOD = pGraphicsPath
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Empties the path and sets the fill mode to FillModeAlternate.
   ' =====================================================================================
   METHOD Reset () THREADSAFE AS LONG
      m_hStatus = GdipResetPath(m_pGraphicsPath)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the fill mode of this path.
   ' =====================================================================================
   METHOD GetFillMode () THREADSAFE AS LONG
      LOCAL fillmode AS LONG
      fillmode = %FillModeAlternate
      m_hStatus = GdipGetPathFillMode(m_pGraphicsPath, fillmode)
      METHOD = fillmode
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the fill mode of this path.
   ' =====================================================================================
   METHOD SetFillMode (BYVAL fillmode AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetPathFillMode(m_pGraphicsPath, fillmode)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets an array of points and an array of point types from this path. Together, these
   ' two arrays define the lines, curves, figures, and markers of this path.
   ' =====================================================================================
   METHOD GetPathData (BYREF PathData_ AS GpPathData) THREADSAFE AS LONG
      m_hStatus = GdipGetPathData(m_pGraphicsPath, PathData_)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Starts a new figure without closing the current figure. Subsequent points added to
   ' this path are added to the new figure.
   ' =====================================================================================
   METHOD StartFigure () THREADSAFE AS LONG
      m_hStatus = GdipStartPathFigure(m_pGraphicsPath)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Closes the current figure of this path.
   ' =====================================================================================
   METHOD CloseFigure () THREADSAFE AS LONG
      m_hStatus = GdipClosePathFigure(m_pGraphicsPath)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Closes all open figures in this path.
   ' =====================================================================================
   METHOD CloseAllFigures () THREADSAFE AS LONG
      m_hStatus = GdipClosePathFigures(m_pGraphicsPath)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Designates the last point in this path as a marker point.
   ' =====================================================================================
   METHOD SetMarker () THREADSAFE AS LONG
      m_hStatus = GdipSetPathMarker(m_pGraphicsPath)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Clears the markers from this path.
   ' =====================================================================================
   METHOD ClearMarkers () THREADSAFE AS LONG
      m_hStatus = GdipClearPathMarkers(m_pGraphicsPath)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Reverses the order of the points that define this path's lines and curves.
   ' =====================================================================================
   METHOD Reverse () THREADSAFE AS LONG
      m_hStatus = GdipReversePath(m_pGraphicsPath)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the ending point of the last figure in this path.
   ' =====================================================================================
   METHOD GetLastPoint (BYREF lastPoint AS POINTF) THREADSAFE AS LONG
      m_hStatus = GdipGetPathLastPoint(m_pGraphicsPath, lastPoint)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a line to the current figure of this path.
   ' =====================================================================================
   METHOD AddLine (BYVAL x1 AS SINGLE, BYVAL y1 AS SINGLE, BYVAL x2 AS SINGLE, BYVAL y2 AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipAddPathLine(m_pGraphicsPath, x1, y1, x2, y1)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a sequence of connected lines to the current figure of this path.
   ' =====================================================================================
   METHOD AddLines (BYREF pts AS PointF, BYVAL count_ AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipAddPathLine2(m_pGraphicsPath, pts, count_)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds an elliptical arc to the current figure of this path.
   ' =====================================================================================
   METHOD AddArc (BYVAL x AS SINGLE, BYVAL y AS SINGLE, BYVAL width_ AS SINGLE, _
      BYVAL height_ AS SINGLE, BYVAL startAngle AS SINGLE, BYVAL sweepAngle AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipAddPathArc(m_pGraphicsPath, x, y, width_, height_, startAngle, sweepAngle)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds an elliptical arc to the current figure of this path.
   ' =====================================================================================
   METHOD AddArcRect (BYREF rc AS RectF, BYVAL BYVAL startAngle AS SINGLE, BYVAL sweepAngle AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipAddPathArcI(m_pGraphicsPath, rc.x, rc.y, rc.width, rc.height, startAngle, sweepAngle)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a Bézier spline to the current figure of this path.
   ' =====================================================================================
   METHOD AddBezier (BYVAL x1 AS SINGLE, BYVAL y1 AS SINGLE, BYVAL x2 AS SINGLE, BYVAL y2 AS SINGLE, _
      BYVAL x3 AS SINGLE, BYVAL y3 AS SINGLE, BYVAL x4 AS SINGLE, BYVAL y4 AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipAddPathBezier(m_pGraphicsPath, x1, y1, x2, y2, x3, y3, x4, y4)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a sequence of connected Bézier splines to the current figure of this path.
   ' =====================================================================================
   METHOD AddBeziers (BYREF pts AS PointF, BYVAL count_ AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipAddPathBeziers(m_pGraphicsPath, pts, count_)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a cardinal spline to the current figure of this path.
   ' =====================================================================================
   METHOD AddCurve (BYREF pts AS PointF, BYVAL count_ AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipAddPathCurve(m_pGraphicsPath, pts, count_)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a cardinal spline to the current figure of this path.
   ' =====================================================================================
   METHOD AddCurve2 (BYREF pts AS PointF, BYVAL count_ AS LONG, BYVAL tension AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipAddPathCurve2(m_pGraphicsPath, pts, count_, tension)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a cardinal spline to the current figure of this path.
   ' =====================================================================================
   METHOD AddCurve3 (BYREF pts AS PointF, BYVAL count_ AS LONG, BYVAL offset AS LONG, _
      BYVAL numberOfSegments AS LONG, BYVAL tension AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipAddPathCurve3(m_pGraphicsPath, pts, count_, offset, numberOfSegments, tension)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a closed cardinal spline to this path.
   ' =====================================================================================
   METHOD AddClosedCurve (BYREF pts AS PointF, BYVAL count_ AS LONG, OPTIONAL BYVAL vTension AS VARIANT) THREADSAFE AS LONG
      IF ISMISSING(vTension) THEN
         m_hStatus = GdipAddPathClosedCurve(m_pGraphicsPath, pts, count_)
      ELSE
         m_hStatus = GdipAddPathClosedCurve2(m_pGraphicsPath, pts, count_, VARIANT#(vTension))
      END IF
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a rectangle to this path.
   ' =====================================================================================
   METHOD AddRectangle (BYVAL x AS SINGLE, BYVAL y AS SINGLE, BYVAL width_ AS SINGLE, BYVAL height_ AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipAddPathRectangle(m_pGraphicsPath, x, y, width_, height_)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a sequence of rectangles to this path.
   ' =====================================================================================
   METHOD AddRectangles (BYREF rects AS GpRectF, BYVAL count_ AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipAddPathRectangles(m_pGraphicsPath, rects, count_)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds an ellipse to this path.
   ' =====================================================================================
   METHOD AddEllipse (BYVAL x AS SINGLE, BYVAL y AS SINGLE, BYVAL width_ AS SINGLE, BYVAL height_ AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipAddPathEllipse(m_pGraphicsPath, x, y, width_, height_)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a pie to this path. An arc is a portion of an ellipse, and a pie is a portion of
   ' the area enclosed by an ellipse. A pie is bounded by an arc and two lines (edges) that
   ' go from the center of the ellipse to the endpoints of the arc.
   ' =====================================================================================
   METHOD AddPie (BYVAL x AS SINGLE, BYVAL y AS SINGLE, BYVAL width_ AS SINGLE, BYVAL height_ AS SINGLE, _
      BYVAL startAngle AS SINGLE, BYVAL sweepAngle AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipAddPathPie(m_pGraphicsPath, x, y, width_, height_, startAngle, sweepAngle)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a polygon to this path.
   ' =====================================================================================
   METHOD AddPolygon (BYREF pts AS PointF, BYVAL count_ AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipAddPathPolygon(m_pGraphicsPath, pts, count_)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a path to this path.
   ' =====================================================================================
   METHOD AddPath (BYVAL pAddingPath AS IGdipGraphicsPath, BYVAL connect_ AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipAddPathPath(m_pGraphicsPath, pAddingPath.Ptr, connect_)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds the outlines of a string to this path.
   ' =====================================================================================
   METHOD AddString (BYREF string_ AS WSTRINGZ, BYVAL pFamily AS IGdipFontFamily, BYVAL style_ AS LONG, _
   BYVAL emSize AS SINGLE, BYREF layoutRect AS RectF, BYVAL pFormat AS IGdipStringFormat) THREADSAFE AS LONG
      m_hStatus = GdipAddPathString(m_pGraphicsPath, string_, LEN(string_), _
         IIF(ISOBJECT(pFamily), pFamily.Ptr, %NULL), style_, emSize, layoutRect, _
         IIF(ISOBJECT(pFormat), pFormat.Ptr, %NULL))
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds the outlines of a string to this path.
   ' =====================================================================================
   METHOD AddStringRect (BYREF string_ AS WSTRINGZ, BYVAL pFamily AS IGdipFontFamily, BYVAL style_ AS LONG, _
   BYVAL emSize AS SINGLE, BYREF layoutRect AS RectF, BYVAL pFormat AS IGdipStringFormat) THREADSAFE AS LONG
      m_hStatus = GdipAddPathString(m_pGraphicsPath, string_, LEN(string_), _
         IIF(ISOBJECT(pFamily), pFamily.Ptr, %NULL), style_, emSize, layoutRect, _
         IIF(ISOBJECT(pFormat), pFormat.Ptr, %NULL))
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds the outlines of a string to this path.
   ' =====================================================================================
   METHOD AddStringPoint (BYREF string_ AS WSTRINGZ, BYVAL pFamily AS IGdipFontFamily, BYVAL style_ AS LONG, _
   BYVAL emSize AS SINGLE, BYREF origin AS PointF, BYVAL pFormat AS IGdipStringFormat) THREADSAFE AS LONG
      LOCAL layoutRect AS RectF
      layoutRect.x = origin.X : layoutRect.y = origin.Y
      m_hStatus = GdipAddPathString(m_pGraphicsPath, string_, LEN(string_), _
         IIF(ISOBJECT(pFamily), pFamily.Ptr, %NULL), style_, emSize, layoutRect, _
         IIF(ISOBJECT(pFormat), pFormat.Ptr, %NULL))
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds the outlines of a string to this path.
   ' =====================================================================================
   METHOD AddStringXY (BYREF string_ AS WSTRINGZ, BYVAL pFamily AS IGdipFontFamily, BYVAL style_ AS LONG, _
   BYVAL emSize AS SINGLE, BYVAL x AS LONG, BYVAL y AS LONG, BYVAL pFormat AS IGdipStringFormat) THREADSAFE AS LONG
      LOCAL layoutRect AS RectF
      layoutRect.x = x : layoutRect.y = y
      m_hStatus = GdipAddPathString(m_pGraphicsPath, string_, LEN(string_), _
         IIF(ISOBJECT(pFamily), pFamily.Ptr, %NULL), style_, emSize, layoutRect, _
         IIF(ISOBJECT(pFormat), pFormat.Ptr, %NULL))
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Multiplies each of this path's data points by a specified matrix.
   ' =====================================================================================
   METHOD TransForm (BYVAL pMatrix AS IGdipMatrix) THREADSAFE AS LONG
      m_hStatus = GdipTransformPath(m_pGraphicsPath, pMatrix.Ptr)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a bounding rectangle for this path
   ' =====================================================================================
   METHOD GetBounds (BYREF bounds AS RectF, OPTIONAL BYVAL pMatrix AS IGdipMatrix, BYVAL pPen AS IGdipPen) THREADSAFE AS LONG
      m_hStatus = GdipGetPathWorldBounds(m_pGraphicsPath, bounds, IIF(ISOBJECT(pMatrix), pMatrix.Ptr, %NULL), IIF(ISOBJECT(pPen), pPen.Ptr, %NULL))
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Applies a transformation to this path and converts each curve in the path to a
   ' sequence of connected lines.
   ' =====================================================================================
   METHOD Flatten (OPTIONAL BYVAL pMatrix AS IGdipMatrix, BYVAL vFlatness AS VARIANT) THREADSAFE AS LONG
      LOCAL flatness AS SINGLE
      IF ISMISSING(vFlatness) THEN flatness = 0.25! ELSE flatness = VARIANT#(vFlatness)
      m_hStatus = GdipFlattenPath(m_pGraphicsPath, IIF(ISOBJECT(pMatrix), pMatrix.Ptr, %NULL), flatness)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Replaces this path with curves that enclose the area that is filled when this path is
   ' drawn by a specified pen. The GraphicsPath::Widen method also flattens the path.
   ' =====================================================================================
   METHOD Widen (BYVAL pPen AS IGdipPen, OPTIONAL BYVAL pMatrix AS IGdipMatrix, BYVAL vFlatness AS VARIANT) THREADSAFE AS LONG
      LOCAL flatness AS SINGLE
      IF ISMISSING(vflatness) THEN flatness = 0.25! ELSE flatness = VARIANT#(vFlatness)
      m_hStatus = GdipWidenPath(m_pGraphicsPath, IIF(ISOBJECT(pPen), pPen.Ptr, %NULL), IIF(ISOBJECT(pMatrix), pMatrix.Ptr, %NULL), flatness)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Transforms and flattens this path, and then converts this path's data points so that
   ' they represent only the outline of the path.
   ' =====================================================================================
   METHOD Outline (OPTIONAL BYVAL pMatrix AS IGdipMatrix, BYVAL vFlatness AS VARIANT) THREADSAFE AS LONG
      LOCAL flatness AS SINGLE
      IF ISMISSING(vFlatness) THEN flatness = 0.25! ELSE flatness = VARIANT#(vFlatness)
      m_hStatus = GdipWindingModeOutline(m_pGraphicsPath, IIF(ISOBJECT(pMatrix), pMatrix.Ptr, %NULL), flatness)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Applies a warp transformation to this path. Warp also flattens (converts to a sequence
   ' of straight lines) the path. Default warpMode value: WarpModePerspective (0).
   ' =====================================================================================
   METHOD Warp (BYREF destPoints AS PointF, BYVAL count_ AS LONG, BYREF srcRect AS RectF, _
      OPTIONAL BYVAL pMatrix AS IGdipMatrix, BYVAL warpMode AS LONG, BYVAL vFlatness AS VARIANT) THREADSAFE AS LONG
      LOCAL flatness AS SINGLE
      IF ISMISSING(vflatness) THEN flatness = 0.25! ELSE flatness = VARIANT#(vFlatness)
      m_hStatus = GdipWarpPath(m_pGraphicsPath, IIF(ISOBJECT(pMatrix), pMatrix.Ptr, %NULL), destPoints, count_, _
                  srcRect.x, srcRect.y, srcRect.width, srcRect.height, warpMode, flatness)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of points in this path's array of data points. This is the same as
   ' the number of types in the path's array of point types.
   ' =====================================================================================
   METHOD GetPointCount () THREADSAFE AS LONG
      LOCAL count_ AS LONG
      m_hStatus = GdipGetPointCount(m_pGraphicsPath, count_)
      METHOD = count_
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets this path's array of point types.
   ' =====================================================================================
   METHOD GetPathTypes (BYREF types AS BYTE, BYVAL count_ AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipGetPathTypes(m_pGraphicsPath, types, count_)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets this path's array of points. The array contains the endpoints and control points
   ' of the lines and Bézier splines that are used to draw the path.
   ' =====================================================================================
   METHOD GetPathPoints (BYREF pts AS PointF, BYVAL count_ AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipGetPathPoints(m_pGraphicsPath, pts, count_)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Determines whether a specified point lies in the area that is filled when this path
   ' is filled by a specified Graphics object.
   ' =====================================================================================
   METHOD IsVisible (BYVAL x AS SINGLE, BYVAL y AS SINGLE, OPTIONAL BYVAL graphics AS IGdipGraphics) THREADSAFE AS LONG
      LOCAL result AS LONG
      m_hStatus = GdipIsVisiblePathPoint(m_pGraphicsPath, x, y, IIF(ISOBJECT(graphics), graphics.Ptr, %NULL), result)
      METHOD = result
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Determines whether a specified point touches the outline of this path when the path
   ' is drawn by a specified Graphics object and a specified pen.
   ' =====================================================================================
   METHOD IsOutlineVisible (BYVAL x AS SINGLE, BYVAL y AS SINGLE, BYVAL pPen AS DWORD, OPTIONAL BYVAL graphics AS IGdipGraphics) THREADSAFE AS LONG
      LOCAL result AS LONG
      m_hStatus = GdipIsOutlineVisiblePathPoint(m_pGraphicsPath, x, y, pPen, IIF(ISOBJECT(graphics), graphics.Ptr, %NULL), result)
      METHOD = result
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' ########################################################################################

' ########################################################################################
' CGdipGraphicsPathIterator Class
' ########################################################################################
CLASS CGdipGraphicsPathIterator

   INSTANCE m_hStatus AS LONG
   INSTANCE m_pGraphicsPathIretator AS DWORD
   INSTANCE m_dpiX AS SINGLE
   INSTANCE m_dpiY AS SINGLE
   INSTANCE m_rx AS SINGLE
   INSTANCE m_ry AS SINGLE

   ' =====================================================================================
   ' Create method
   ' =====================================================================================
   CLASS METHOD Create
      ' // Get the DPI ratios
      LOCAL hDC AS DWORD
      hDC = GetDC(%NULL)
      m_dpiX = GetDeviceCaps(hDC, %LOGPIXELSX)
      m_dpiY = GetDeviceCaps(hDC, %LOGPIXELSY)
      m_rx = (GetDeviceCaps(hDC, %LOGPIXELSX) / 96)
      m_ry = (GetDeviceCaps(hDC, %LOGPIXELSY) / 96)
      ReleaseDC %NULL, hDC
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Cleanup
   ' =====================================================================================
   CLASS METHOD Destroy
      IF m_pGraphicsPathIretator THEN GdipDeletePathIter(m_pGraphicsPathIretator)
   END METHOD
   ' =====================================================================================

   INTERFACE IGdipGraphicsPathIterator : INHERIT IAutomation

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the Image object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pGraphicsPathIretator
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the Image object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      IF m_pGraphicsPathIretator THEN GdipDeletePathIter(m_pGraphicsPathIretator)
      m_pGraphicsPathIretator = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new GraphicsPathIterator object and associates it with a GraphicsPath object.
   ' =====================================================================================
   METHOD GraphicsPathIterator (BYVAL pPath AS IGdipGraphicsPath) THREADSAFE AS LONG
      IF m_pGraphicsPathIretator THEN GdipDeletePathIter(m_pGraphicsPathIretator)
      m_hStatus = GdipCreatePathIter(m_pGraphicsPathIretator, pPath.Ptr)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the starting index and the ending index of the next subpath (figure) in this
   ' iterator's associated path.
   ' =====================================================================================
   METHOD NextSubpath (BYREF startIndex AS LONG, BYREF endIndex AS LONG, BYREF isClosed AS LONG) THREADSAFE AS LONG
      LOCAL resultCount AS LONG
      m_hStatus = GdipPathIterNextSubpath(m_pGraphicsPathIretator, resultCount, startIndex, endIndex, isClosed)
      METHOD = resultCount
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the the next figure (subpath) from this iterator's associated path.
   ' =====================================================================================
   METHOD NextSubpathPath (BYREF pPath AS IGdipGraphicsPath, BYREF isClosed AS LONG) THREADSAFE AS LONG
      IF ISNOTHING(pPath) THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      LOCAL resultCount AS LONG
      LOCAL pGraphicsPathPtr AS DWORD
      pGraphicsPathPtr = pPath.Ptr
      m_hStatus = GdipPathIterNextSubpathPath(m_pGraphicsPathIretator, resultCount, pGraphicsPathPtr, isClosed)
      pPath.Ptr = pGraphicsPathPtr
      METHOD = resultCount
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the starting index and the ending index of the next group of data points that
   ' all have the same type.
   ' =====================================================================================
   METHOD NextPathType (BYREF pathType AS BYTE, BYREF startIndex AS LONG, BYREF endIndex AS LONG) THREADSAFE AS LONG
      LOCAL resultCount AS LONG
      m_hStatus = GdipPathIterNextPathType(m_pGraphicsPathIretator, resultCount, pathType, startIndex, endIndex)
      METHOD = resultCount
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the starting index and the ending index of the next marker-delimited section in
   ' this iterator's associated path.
   ' =====================================================================================
   METHOD NextMarker (BYREF startIndex AS LONG, BYREF endIndex AS LONG) THREADSAFE AS LONG
      LOCAL resultCount AS LONG
      m_hStatus = GdipPathIterNextMarker(m_pGraphicsPathIretator, resultCount, startIndex, endIndex)
      METHOD = resultCount
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the next marker-delimited section of this iterator's associated path.
   ' =====================================================================================
   METHOD NextMarkerPath (BYREF pPath AS IGdipGraphicsPath) THREADSAFE AS LONG
      LOCAL resultCount AS LONG
      LOCAL pGraphicsPathPtr AS DWORD
      IF ISNOTHING(pPath) THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      m_hStatus = GdipPathIterNextMarkerPath(m_pGraphicsPathIretator, resultCount, pGraphicsPathPtr)
      pPath.Ptr = pGraphicsPathPtr
      METHOD = resultCount
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the number of data points in the path.
   ' =====================================================================================
   METHOD GetCount () THREADSAFE AS LONG
      LOCAL resultCount AS LONG
      m_hStatus = GdipPathIterGetCount(m_pGraphicsPathIretator, resultCount)
      METHOD = resultCount
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the number of subpaths (also called figures) in the path.
   ' =====================================================================================
   METHOD GetSubpathCount () THREADSAFE AS LONG
      LOCAL resultCount AS LONG
      m_hStatus = GdipPathIterGetSubpathCount(m_pGraphicsPathIretator, resultCount)
      METHOD = resultCount
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the number of subpaths (also called figures) in the path.
   ' =====================================================================================
   METHOD HasCurve () THREADSAFE AS LONG
      LOCAL hasCurve AS LONG
      m_hStatus = GdipPathIterHasCurve(m_pGraphicsPathIretator, hasCurve)
      METHOD = hasCurve
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Rewinds this iterator to the beginning of its associated path.
   ' =====================================================================================
   METHOD Rewind () THREADSAFE AS LONG
      m_hStatus = GdipPathIterRewind(m_pGraphicsPathIretator)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Copies the path's data points to a PointF array and copies the path's point types to a BYTE array.
   ' =====================================================================================
   METHOD Enumerate (BYREF pts AS PointF, BYREF types AS BYTE, BYVAL nCount AS LONG) THREADSAFE AS LONG
      LOCAL resultCount AS LONG
      m_hStatus = GdipPathIterEnumerate(m_pGraphicsPathIretator, resultCount, pts, types, nCount)
      METHOD = resultCount
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Copies a subset of the path's data points to a PointF array and copies a subset of
   ' the path's point types to a BYTE array.
   ' =====================================================================================
   METHOD CopyData (BYREF pts AS PointF, BYREF types AS BYTE, BYVAL startIndex AS LONG, BYVAL endIndex AS LONG) THREADSAFE AS LONG
      LOCAL resultCount AS LONG
      m_hStatus = GdipPathIterCopyData(m_pGraphicsPathIretator, resultCount, pts, types, startIndex, endIndex)
      METHOD = resultCount
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' ########################################################################################
