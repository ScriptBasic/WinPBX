' ########################################################################################
' Microsoft Windows
' File: CGdipGraphics.inc
' Contents: GDI+ graphics class.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CGDIPGRAPHICS_INC = 1

' ########################################################################################
' CGdipGraphics Class
' ########################################################################################
CLASS CGdipGraphics

   INSTANCE m_hStatus AS LONG
   INSTANCE m_pGraphics AS DWORD

   ' =====================================================================================
   ' Cleanup
   ' =====================================================================================
   CLASS METHOD Destroy
      IF m_pGraphics THEN GdipDeleteGraphics(m_pGraphics)
   END METHOD
   ' =====================================================================================

   INTERFACE IGdipGraphics : INHERIT IAutomation

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the Graphics object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pGraphics
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the Graphics object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      IF m_pGraphics THEN GdipDeleteGraphics(m_pGraphics)
      m_pGraphics = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Graphics object that is associated with a specified device context.
   ' When you use these constructors to create a Graphics object, make sure that the Graphics
   ' object is deleted or goes out of scope before the device context is released.
   ' =====================================================================================
   METHOD FromHDC (BYVAL hdc AS DWORD) THREADSAFE AS LONG
      IF m_pGraphics THEN GdipDeleteGraphics(m_pGraphics)
      m_hStatus = GdipCreateFromHDC(hdc, m_pGraphics)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD FromHDC2 (BYVAL hdc AS DWORD, BYVAL hDevice AS DWORD) THREADSAFE AS LONG
      IF m_pGraphics THEN GdipDeleteGraphics(m_pGraphics)
      m_hStatus = GdipCreateFromHDC2(hdc, hDevice, m_pGraphics)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Graphics object that is associated with a specified window.
   ' =====================================================================================
   METHOD FromHWND (BYVAL hwnd AS DWORD, OPTIONAL BYVAL icm AS LONG) THREADSAFE AS LONG
      IF m_pGraphics THEN GdipDeleteGraphics(m_pGraphics)
      IF icm THEN
         m_hStatus = GdipCreateFromHWNDICM(hwnd, m_pGraphics)
      ELSE
         m_hStatus = GdipCreateFromHWND(hwnd, m_pGraphics)
      END IF
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Graphics object that is associated with an Image object.
   ' =====================================================================================
   METHOD FromImage (BYVAL pImage AS IGdipImage) THREADSAFE AS LONG
      IF ISNOTHING(pImage) THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      IF m_pGraphics THEN GdipDeleteGraphics(m_pGraphics)
      m_hStatus = GdipGetImageGraphicsContext(pImage.Ptr, m_pGraphics)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Flushes all pending graphics operations.
   ' =====================================================================================
   METHOD Flush (OPTIONAL BYVAL intention AS LONG) THREADSAFE
      GdipFlush(m_pGraphics, intention)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a handle to the device context associated with this Graphics object.
   ' =====================================================================================
   METHOD GetHDC ()  THREADSAFE AS DWORD
      LOCAL hdc AS DWORD
      m_hStatus = GdipGetDC(m_pGraphics, hdc)
      METHOD = hdc
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Releases a device context handle obtained by a previous call to the GetHDC method of
   ' this Graphics object.
   ' =====================================================================================
   METHOD ReleaseHDC (BYVAL hdc AS DWORD) THREADSAFE
      GdipReleaseDC(m_pGraphics, hdc)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the rendering origin of this Graphics object. The rendering origin is used to
   ' set the dither origin for 8-bits-per-pixel and 16-bits-per-pixel dithering and is
   ' also used to set the origin for hatch brushes.
   ' =====================================================================================
   METHOD SetRenderingOrigin (BYVAL x AS LONG, BYVAL y AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetRenderingOrigin(m_pGraphics, x, y)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the rendering origin currently set for this Graphics object. The rendering origin
   ' is used to set the dither origin for 8-bits per pixel and 16-bits per pixel dithering
   ' and is also used to set the origin for hatch brushes.
   ' =====================================================================================
   METHOD GetRenderingOrigin (BYREF x AS LONG, BYREF y AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipGetRenderingOrigin(m_pGraphics, x, y)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the compositing mode of this Graphics object.
   ' =====================================================================================
   METHOD SetCompositingMode (BYVAL compositingMode AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetCompositingMode(m_pGraphics, compositingMode)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the compositing mode currently set for this Graphics object.
   ' =====================================================================================
   METHOD GetCompositingMode () THREADSAFE AS LONG
      LOCAL nMode AS LONG
      m_hStatus = GdipGetCompositingMode(m_pGraphics, nMode)
      METHOD = nMode
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the compositing quality of this Graphics object.
   ' =====================================================================================
   METHOD SetCompositingQuality (BYVAL compositingQuality AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetCompositingQuality(m_pGraphics, compositingQuality)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the compositing mode currently set for this Graphics object.
   ' =====================================================================================
   METHOD GetCompositingQuality () THREADSAFE AS LONG
      LOCAL nQuality AS LONG
      m_hStatus = GdipGetCompositingQuality(m_pGraphics, nQuality)
      METHOD = nQuality
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the text rendering mode of this Graphics object.
   ' =====================================================================================
   METHOD SetTextRenderingHint (BYVAL newMode AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetTextRenderingHint(m_pGraphics, newMode)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the compositing mode currently set for this Graphics object.
   ' =====================================================================================
   METHOD GetTextRenderingHint () THREADSAFE AS LONG
      LOCAL hint AS LONG
      m_hStatus = GdipGetTextRenderingHint(m_pGraphics, hint)
      METHOD = hint
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the text rendering mode of this Graphics object.
   ' =====================================================================================
   METHOD SetTextContrast (BYVAL contrast AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipSetTextContrast(m_pGraphics, contrast)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the contrast value currently set for this Graphics object. The contrast value is
   ' used for antialiasing text.
   ' =====================================================================================
   METHOD GetTextContrast () THREADSAFE AS DWORD
      LOCAL contrast AS DWORD
      m_hStatus = GdipGetTextContrast(m_pGraphics, contrast)
      METHOD = contrast
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the compositing mode currently set for this Graphics object.
   ' =====================================================================================
   METHOD GetInterpolationMode () THREADSAFE AS LONG
      LOCAL nMode AS LONG
      m_hStatus = GdipGetInterpolationMode(m_pGraphics, nMode)
      METHOD = nMode
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the interpolation mode of this Graphics object. The interpolation mode determines
   ' the algorithm that is used when images are scaled or rotated.
   ' =====================================================================================
   METHOD SetInterpolationMode (BYVAL interpolationMode AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetInterpolationMode(m_pGraphics, interpolationMode)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

#IF (%GDIPVER >= &H0110)
   ' =====================================================================================
   ' Not used in Windows GDI+ versions 1.0 and 1.1.
   ' =====================================================================================
   METHOD SetAbort (BYVAL pIAbort AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipGraphicsSetAbort(m_pGraphics, pIAbort)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================
#ENDIF   ' //(GDIPVER >= 0x0110)

   ' =====================================================================================
   ' Determines whether smoothing (antialiasing) is applied to the Graphics object.
   ' =====================================================================================
   METHOD GetSmoothingMode () THREADSAFE AS LONG
      LOCAL smoothingMode AS LONG
      m_hStatus = GdipGetSmoothingMode(m_pGraphics, smoothingMode)
      METHOD = smoothingMode
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the rendering quality of the Graphics object.
   ' =====================================================================================
   METHOD SetSmoothingMode (BYVAL smoothingMode AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetSmoothingMode(m_pGraphics, smoothingMode)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the pixel offset mode currently set for this Graphics object.
   ' =====================================================================================
   METHOD GetPixelOffsetMode () THREADSAFE AS LONG
      LOCAL pixelOffsetMode AS LONG
      m_hStatus = GdipGetPixelOffsetMode(m_pGraphics, pixelOffsetMode)
      METHOD = pixelOffsetMode
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the pixel offset mode of this Graphics object.
   ' =====================================================================================
   METHOD SetPixelOffsetMode (BYVAL pixelOffsetMode AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetPixelOffsetMode(m_pGraphics, pixelOffsetMode)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the transformation matrix of this Graphics object.
   ' =====================================================================================
   METHOD SetTransform (BYVAL pMatrix AS IGdipMatrix) THREADSAFE AS LONG
      m_hStatus = GdipSetWorldTransform(m_pGraphics, pMatrix.Ptr)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the transformation matrix of this Graphics object.
   ' =====================================================================================
   METHOD ResetTransform () THREADSAFE AS LONG
      m_hStatus = GdipResetWorldTransform(m_pGraphics)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this Graphic object's transformation matrix with the product of itself and another matrix.
   ' =====================================================================================
   METHOD MultiplyTransform (BYVAL pMatrix AS IGdipMatrix, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipMultiplyWorldTransform(m_pGraphics, pMatrix.Ptr, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this Graphic object's current transformation matrix with the product of itself
   ' and a translation matrix.
   ' =====================================================================================
   METHOD TranslateTransform (BYVAL dx AS SINGLE, BYVAL dy AS SINGLE, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipTranslateWorldTransform(m_pGraphics, dx, dy, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this Graphic object's current transformation matrix with the product of itself
   ' and a scaling matrix.
   ' =====================================================================================
   METHOD ScaleTransform (BYVAL sx AS SINGLE, BYVAL sy AS SINGLE, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipScaleWorldTransform(m_pGraphics, sx, sy, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Resets the transformation matrix of this Graphic o0bject to the identity matrix. This
   ' means that no transformation takes place.
   ' =====================================================================================
   METHOD RotateTransform (BYVAL angle AS SINGLE, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipRotateWorldTransform(m_pGraphics, angle, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the transformation matrix of this Graphic object.
   ' =====================================================================================
   METHOD GetTransform (BYREF pMatrix AS IGdipMatrix) THREADSAFE AS LONG
      IF ISNOTHING(pMatrix) THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      m_hStatus = GdipGetWorldTransform(m_pGraphics, pMatrix.Ptr)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the unit of measure for this Graphics object. The page unit belongs to the page
   ' transformation, which converts page coordinates to device coordinates.
   ' =====================================================================================
   METHOD SetPageUnit (BYVAL unit AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipSetPageUnit(m_pGraphics, unit)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets scaling factor for the page transformation of this Graphics object. The page
   ' transformation converts page coordinates to device coordinates.
   ' =====================================================================================
   METHOD SetPageScale (BYVAL nScale AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipSetPageScale(m_pGraphics, nScale)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the unit of measure currently set for this Graphics object.
   ' =====================================================================================
   METHOD GetPageUnit () THREADSAFE AS LONG
      LOCAL unit AS LONG
      m_hStatus = GdipGetPageUnit(m_pGraphics, unit)
      METHOD = unit
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets scaling factor currently set for the page transformation of this Graphics object.
   ' The page transformation converts page coordinates to device coordinates.
   ' =====================================================================================
   METHOD GetPageScale () THREADSAFE AS SINGLE
      LOCAL nScale AS SINGLE
      m_hStatus = GdipGetPageScale(m_pGraphics, nScale)
      METHOD = nScale
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the horizontal resolution, in dots per inch, of the display device associated
   ' with this Graphics object.
   ' =====================================================================================
   METHOD GetDpiX () THREADSAFE AS SINGLE
      LOCAL dpi AS SINGLE
      m_hStatus = GdipGetDpiX(m_pGraphics, dpi)
      METHOD = dpi
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the vertical resolution, in dots per inch, of the display device associated
   ' with this Graphics object.
   ' =====================================================================================
   METHOD GetDpiY () THREADSAFE AS SINGLE
      LOCAL dpi AS SINGLE
      m_hStatus = GdipGetDpiY(m_pGraphics, dpi)
      METHOD = dpi
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Converts an array of points from one coordinate space to another. The conversion is
   ' based on the current world and page transformations of this Graphics object.
   ' =====================================================================================
   METHOD TransformPoints (BYVAL destSpace AS LONG, BYVAL srcSpace AS LONG, BYREF pts AS PointF, BYVAL nCount AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipTransformPoints(m_pGraphics, destSpace, srcSpace, pts, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the nearest color to the color that is passed in. This method works on 8-bits per
   ' pixel or lower display devices for which there is an 8-bit color palette.
   ' =====================================================================================
   METHOD GetNearestColor (BYREF colour AS DWORD) THREADSAFE AS LONG
      IF VARPTR(colour) = 0 THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      m_hStatus = GdipGetNearestColor(m_pGraphics, colour)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws a line that connects two points.
   ' =====================================================================================
   METHOD DrawLine (BYVAL pPen AS IGdipPen, BYVAL x1 AS SINGLE, BYVAL y1 AS SINGLE, BYVAL x2 AS SINGLE, BYVAL y2 AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipDrawLine(m_pGraphics, pPen.Ptr, x1, y1, x2, y2)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws a line that connects two points.
   ' =====================================================================================
   METHOD DrawLinePoint (BYVAL pPen AS IGdipPen, BYREF pt1 AS PointF, BYREF pt2 AS PointF) THREADSAFE AS LONG
      m_hStatus = GdipDrawLine(m_pGraphics, pPen.Ptr, pt1.X, pt1.Y, pt2.X, pt2.Y)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws a sequence of connected lines.
   ' =====================================================================================
   METHOD DrawLines (BYVAL pPen AS IGdipPen, BYREF pts AS PointF, BYVAL nCount AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipDrawLines(m_pGraphics, pPen.Ptr, pts, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws an arc. The arc is part of an ellipse.
   ' =====================================================================================
   METHOD DrawArc (BYVAL pPen AS IGdipPen, BYVAL x AS SINGLE, BYVAL y AS SINGLE, BYVAL nWidth AS SINGLE, BYVAL nHeight AS SINGLE, BYVAL startAngle AS SINGLE, BYVAL sweepAngle AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipDrawArc(m_pGraphics, pPen.Ptr, x, y, nWidth, nHeight, startAngle, sweepAngle)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws an arc. The arc is part of an ellipse.
   ' =====================================================================================
   METHOD DrawArcRect (BYVAL pPen AS IGdipPen, BYREF rc AS RectF, BYVAL startAngle AS SINGLE, BYVAL sweepAngle AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipDrawArc(m_pGraphics, pPen.Ptr, rc.x, rc.y, rc.Width, rc.Height, startAngle, sweepAngle)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws a Bézier spline.
   ' =====================================================================================
   METHOD DrawBezier (BYVAL pPen AS IGdipPen, BYVAL x1 AS SINGLE, BYVAL y1 AS SINGLE, _
   BYVAL x2 AS SINGLE, BYVAL y2 AS SINGLE, BYVAL x3 AS SINGLE, BYVAL y3 AS SINGLE, _
   BYVAL x4 AS SINGLE, BYVAL y4 AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipDrawBezier(m_pGraphics, pPen.Ptr, x1, y1, x2, y2, x3, y3, x4, y4)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws a Bézier spline.
   ' =====================================================================================
   METHOD DrawBezierPoint (BYVAL pPen AS IGdipPen, BYREF pt1 AS PointF, BYREF pt2 AS PointF, BYREF pt3 AS PointF, BYREF pt4 AS PointF) THREADSAFE AS LONG
      m_hStatus = GdipDrawBezier(m_pGraphics, pPen.Ptr, pt1.x, pt1.y, pt2.x, pt2.y, pt3.x, pt3.y, pt4.x, pt4.y)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws a Bézier spline.
   ' =====================================================================================
   METHOD DrawBeziers (BYVAL pPen AS IGdipPen, BYREF pts AS PointF, BYVAL nCount AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipDrawBeziers(m_pGraphics, pPen.Ptr, pts, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws a rectangle.
   ' =====================================================================================
   METHOD DrawRectangle (BYVAL pPen AS IGdipPen, BYVAL x AS SINGLE, BYVAL y AS SINGLE, BYVAL nWidth AS SINGLE, BYVAL nHeight AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipDrawRectangleI(m_pGraphics, pPen.Ptr, x, y, nWidth, nHeight)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws a rectangle.
   ' =====================================================================================
   METHOD DrawRectangleRect (BYVAL pPen AS IGdipPen, BYREF rc AS RectF) THREADSAFE AS LONG
      m_hStatus = GdipDrawRectangle(m_pGraphics, pPen.Ptr, rc.x, rc.y, rc.Width, rc.Height)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws a sequence of rectangles.
   ' =====================================================================================
   METHOD DrawRectangles (BYVAL pPen AS IGdipPen, BYREF rects AS RectF, BYVAL nCount AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipDrawRectangles(m_pGraphics, pPen.Ptr, rects, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws an ellipse.
   ' =====================================================================================
   METHOD DrawEllipse (BYVAL pPen AS IGdipPen, BYVAL x AS SINGLE, BYVAL y AS SINGLE, BYVAL nWidth AS SINGLE, BYVAL nHeight AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipDrawEllipse(m_pGraphics, pPen.Ptr, x, y, nWidth, nHeight)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws an ellipse.
   ' =====================================================================================
   METHOD DrawEllipseRect (BYVAL pPen AS IGdipPen, BYREF rc AS RectF) THREADSAFE AS LONG
      m_hStatus = GdipDrawEllipse(m_pGraphics, pPen.Ptr, rc.x, rc.y, rc.Width, rc.Height)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws a pie.
   ' =====================================================================================
   METHOD DrawPie (BYVAL pPen AS IGdipPen, BYVAL x AS SINGLE, BYVAL y AS SINGLE, BYVAL nWidth AS SINGLE, BYVAL nHeight AS SINGLE, BYVAL startAngle AS SINGLE, BYVAL sweepAngle AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipDrawPie(m_pGraphics, pPen.Ptr, x, y, nWidth, nHeight, startAngle, sweepAngle)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws a pie.
   ' =====================================================================================
   METHOD DrawPieRect (BYVAL pPen AS IGdipPen, BYREF rc AS RectF, BYVAL startAngle AS SINGLE, BYVAL sweepAngle AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipDrawPie(m_pGraphics, pPen.Ptr, rc.x, rc.y, rc.Width, rc.Height, startAngle, sweepAngle)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws a polygon.
   ' =====================================================================================
   METHOD DrawPolygon (BYVAL pPen AS IGdipPen, BYREF pts AS PointF, BYVAL nCount AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipDrawPolygon(m_pGraphics, pPen.Ptr, pts, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws a path.
   ' =====================================================================================
   METHOD DrawPath (BYVAL pPen AS IGdipPen, BYVAL pPath AS IGdipGraphicsPath) THREADSAFE AS LONG
      m_hStatus = GdipDrawPath(m_pGraphics, IIF(ISOBJECT(pPen), pPen.Ptr, %NULL), IIF(ISOBJECT(pPath), pPath.Ptr, %NULL))
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws a cardinal spline.
   ' =====================================================================================
   METHOD DrawCurve (BYVAL pPen AS IGdipPen, BYREF pts AS PointF, BYVAL nCount AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipDrawCurve(m_pGraphics, pPen.Ptr, pts, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws a cardinal spline.
   ' =====================================================================================
   METHOD DrawCurve2 (BYVAL pPen AS IGdipPen, BYREF pts AS PointF, BYVAL nCount AS LONG, BYVAL tension AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipDrawCurve2(m_pGraphics, pPen.Ptr, pts, nCount, tension)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws a cardinal spline.
   ' =====================================================================================
   METHOD DrawCurve3 (BYVAL pPen AS IGdipPen, BYREF pts AS PointF, BYVAL nCount AS LONG, BYVAL offset AS LONG, BYVAL numberOfSegments AS LONG, BYVAL tension AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipDrawCurve3(m_pGraphics, pPen.Ptr, pts, nCount, offset, numberOfSegments, tension)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws a a closed cardinal spline.
   ' =====================================================================================
   METHOD DrawClosedCurve (BYVAL pPen AS IGdipPen, BYREF pts AS PointF, BYVAL nCount AS LONG, OPTIONAL BYVAL vTension AS VARIANT) THREADSAFE AS LONG
      IF ISMISSING(vTension) THEN
         m_hStatus = GdipDrawClosedCurve(m_pGraphics, pPen.Ptr, pts, nCount)
      ELSE
         m_hStatus = GdipDrawClosedCurve2(m_pGraphics, pPen.Ptr, pts, nCount, VARIANT#(vTension))
      END IF
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Clears a Graphics object to a specified color.
   ' =====================================================================================
   METHOD Clear (BYVAL colour AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipGraphicsClear(m_pGraphics, colour)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Uses a brush to fill the interior of a rectangle.
   ' =====================================================================================
   METHOD FillRectangle (BYVAL pBrush AS IGdipBrush, BYVAL x AS SINGLE, BYVAL y AS SINGLE, BYVAL nWidth AS SINGLE, BYVAL nHeight AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipFillRectangle(m_pGraphics, pBrush.Ptr, x, y, nWidth, nHeight)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Uses a brush to fill the interior of a rectangle.
   ' =====================================================================================
   METHOD FillRectangleRect (BYVAL pBrush AS IGdipBrush, BYREF rc AS RectF) THREADSAFE AS LONG
      m_hStatus = GdipFillRectangle(m_pGraphics, pBrush.Ptr, rc.x, rc.y, rc.Width, rc.Height)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Uses a brush to fill the interior of a sequence of rectangles.
   ' =====================================================================================
   METHOD FillRectangles (BYVAL pBrush AS IGdipBrush, BYREF rects AS RectF, BYVAL nCount AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipFillRectangles(m_pGraphics, pBrush.Ptr, rects, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================


   ' =====================================================================================
   ' Uses a brush to fill the interior of a sequence of rectangles.
   ' =====================================================================================
   METHOD FillPolygon (BYVAL pBrush AS IGdipBrush, BYREF pts AS PointF, BYVAL nCount AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipFillPolygon(m_pGraphics, pBrush.Ptr, pts, nCount, %FillModeAlternate)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Uses a brush to fill the interior of a sequence of rectangles.
   ' =====================================================================================
   METHOD FillPolygon2 (BYVAL pBrush AS IGdipBrush, BYREF pts AS PointF, BYVAL nCount AS LONG, BYVAL FillMode AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipFillPolygon(m_pGraphics, pBrush.Ptr, pts, nCount, FillMode)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Uses a brush to fill the interior of a polygon.
   ' =====================================================================================
   METHOD FillEllipse (BYVAL pBrush AS IGdipBrush, BYVAL x AS SINGLE, BYVAL y AS SINGLE, BYVAL nWidth AS SINGLE, BYVAL nHeight AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipFillEllipse(m_pGraphics, pBrush.Ptr, x, y, nWidth, nHeight)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Uses a brush to fill the interior of a polygon.
   ' =====================================================================================
   METHOD FillEllipseRect (BYVAL pBrush AS IGdipBrush, BYREF rc AS RectF) THREADSAFE AS LONG
      m_hStatus = GdipFillEllipse(m_pGraphics, pBrush.Ptr, rc.x, rc.y, rc.Width, rc.Height)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Uses a brush to fill the interior of a pie.
   ' =====================================================================================
   METHOD FillPie (BYVAL pBrush AS IGdipBrush, BYVAL x AS SINGLE, BYVAL y AS SINGLE, BYVAL nWidth AS SINGLE, BYVAL nHeight AS SINGLE, BYVAL startAngle AS SINGLE, BYVAL sweepAngle AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipFillPie(m_pGraphics, pBrush.Ptr, x, y, nWidth, nHeight, startAngle, sweepAngle)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Uses a brush to fill the interior of a pie.
   ' =====================================================================================
   METHOD FillPieRect (BYVAL pBrush AS IGdipBrush, BYREF rc AS RectF, BYVAL startAngle AS SINGLE, BYVAL sweepAngle AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipFillPie(m_pGraphics, pBrush.Ptr, rc.x, rc.y, rc.Width, rc.Height, startAngle, sweepAngle)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Uses a brush to fill the interior of a path. If a figure in the path is not closed,
   ' this method treats the nonclosed figure as if it were closed by a straight line that
   ' connects the figure's starting and ending points.
   ' =====================================================================================
   METHOD FillPath (BYVAL pBrush AS IGdipBrush, BYVAL pPath AS IGdipGraphicsPath) THREADSAFE AS LONG
      m_hStatus = GdipFillPath(m_pGraphics, pBrush.Ptr, pPath.Ptr)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a closed cardinal spline from an array of points and uses a brush to fill the
   ' interior of the spline.
   ' =====================================================================================
   METHOD FillClosedCurve (BYVAL pBrush AS IGdipBrush, BYREF pts AS PointF, BYVAL nCount AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipFillClosedCurve(m_pGraphics, pBrush.Ptr, pts, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a closed cardinal spline from an array of points and uses a brush to fill the
   ' interior of the spline.
   ' =====================================================================================
   METHOD FillClosedCurve2 (BYVAL pBrush AS IGdipBrush, BYREF pts AS PointF, BYVAL nCount AS LONG, BYVAL FillMode AS LONG, OPTIONAL BYVAL vTension AS VARIANT) THREADSAFE AS LONG
      LOCAL tension AS SINGLE
      IF ISMISSING(vTension) THEN tension = 0.5! ELSE tension = VARIANT#(tension)
      m_hStatus = GdipFillClosedCurve2(m_pGraphics, pBrush.Ptr, pts, nCount, fillMode, tension)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Uses a brush to fill a specified region.
   ' =====================================================================================
   METHOD FillRegion (BYVAL pBrush AS IGdipBrush, BYVAL pRegion AS IGdipRegion) THREADSAFE AS LONG
      m_hStatus = GdipFillRegion(m_pGraphics, pBrush.Ptr, pRegion.Ptr)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws a string based on a font and an origin for the string.
   ' =====================================================================================
   METHOD DrawString (BYREF wszString AS WSTRINGZ, BYVAL pFont AS IGdipFont, _
   BYVAL x AS LONG, BYVAL y AS LONG, BYVAL pBrush AS IGdipBrush) THREADSAFE AS LONG
      LOCAL rcf AS RectF
      rcf.x = x : rcf.Y = y
      m_hStatus = GdipDrawString(m_pGraphics, wszString, LEN(wszString), _
         IIF(ISOBJECT(pFont), pFont.Ptr, %NULL), rcf, %NULL, _
         IIF(ISOBJECT(pBrush), pBrush.Ptr, %NULL))
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws a string based on a font, a layout rectangle, and a format.
   ' =====================================================================================
   METHOD DrawStringRect (BYREF wszString AS WSTRINGZ, BYVAL pFont AS IGdipFont, _
   BYREF layoutRect AS RectF, BYVAL pStringFormat AS IGdipStringFormat, BYVAL pBrush AS IGdipBrush) THREADSAFE AS LONG
      m_hStatus = GdipDrawString(m_pGraphics, wszString, LEN(wszString), _
         IIF(ISOBJECT(pFont), pFont.Ptr, %NULL), layoutRect, IIF(ISOBJECT(pStringFormat), pStringFormat.Ptr, %NULL), _
         IIF(ISOBJECT(pBrush), pBrush.Ptr, %NULL))
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws a string based on a font and an origin for the string.
   ' =====================================================================================
   METHOD DrawStringPoint (BYREF wszString AS WSTRINGZ, BYVAL pFont AS IGdipFont, _
   BYREF origin AS PointF, BYVAL pBrush AS IGdipBrush) THREADSAFE AS LONG
      LOCAL rcf AS RectF
      rcf.x = origin.X : rcf.Y = origin.Y
      m_hStatus = GdipDrawString(m_pGraphics, wszString, LEN(wszString), _
         IIF(ISOBJECT(pFont), pFont.Ptr, %NULL), rcf, %NULL, _
         IIF(ISOBJECT(pBrush), pBrush.Ptr, %NULL))
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws a string based on a font, a string origin, and a format.
   ' =====================================================================================
   METHOD DrawStringPoint2 (BYREF wszString AS WSTRINGZ, BYVAL pFont AS IGdipFont, _
   BYREF origin AS PointF, BYVAL pStringFormat AS IGdipStringFormat, BYVAL pBrush AS IGdipBrush) THREADSAFE AS LONG
      LOCAL rcf AS RectF
      rcf.x = origin.X : rcf.Y = origin.Y
      m_hStatus = GdipDrawString(m_pGraphics, wszString, LEN(wszString), _
         IIF(ISOBJECT(pFont), pFont.Ptr, %NULL), rcf, IIF(ISOBJECT(pStringFormat), pStringFormat.Ptr, %NULL), _
         IIF(ISOBJECT(pBrush), pBrush.Ptr, %NULL))
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Measures the extent of the string in the specified font, format, and layout rectangle.
   ' =====================================================================================
   METHOD MeasureString (BYREF wszString AS WSTRINGZ, BYVAL pFont AS IGdipFont, _
   BYREF layoutRect AS RECT, BYVAL pStringFormat AS IGdipStringFormat, BYREF boundingBox AS RectF, _
   OPTIONAL BYREF codepointsFitted AS LONG, BYREF linesFilled AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipMeasureString(m_pGraphics, wszString, LEN(wszString), _
         IIF(ISOBJECT(pFont), pFont.Ptr, %NULL), layoutRect, IIF(ISOBJECT(pStringFormat), pStringFormat.Ptr, %NULL), _
         boundingBox, codepointsFitted, linesFilled)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Measures the extent of the string in the specified font, format, and layout rectangle.
   ' =====================================================================================
   METHOD MeasureString2 (BYREF wszString AS WSTRINGZ, BYVAL pFont AS IGdipFont, _
   BYREF layoutRectSize AS SizeF, BYVAL pStringFormat AS IGdipStringFormat, BYREF tSize AS SizeF, _
   OPTIONAL BYREF codepointsFitted AS LONG, BYREF linesFilled AS LONG) THREADSAFE AS LONG
      LOCAL layoutRect, boundingBox AS RectF
      layoutRect.Width = layoutRectSize.Width : layoutRect.Height = layoutRectSize.Height
      boundingBox.Width = tSize.Width : boundingBox.Height = tSize.Height
      m_hStatus = GdipMeasureString(m_pGraphics, wszString, LEN(wszString), _
         IIF(ISOBJECT(pFont), pFont.Ptr, %NULL), layoutRect, IIF(ISOBJECT(pStringFormat), pStringFormat.Ptr, %NULL), _
         boundingBox, codepointsFitted, linesFilled)
      IF m_hStatus = %StatusOk THEN
         tSize.Width = boundingBox.Width
         tSize.Height = boundingBox.Height
      END IF
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Measures the extent of the string in the specified font, format, and layout rectangle.
   ' =====================================================================================
   METHOD MeasureString3 (BYREF wszString AS WSTRINGZ, BYVAL pFont AS IGdipFont, _
   BYREF origin AS PointF, BYVAL pStringFormat AS IGdipStringFormat, BYREF boundingBox AS RectF) THREADSAFE AS LONG
      LOCAL rcf AS RectF
      rcf.X = origin.X : rcf.Y = origin.Y
      m_hStatus = GdipMeasureString(m_pGraphics, wszString, LEN(wszString), _
         IIF(ISOBJECT(pFont), pFont.Ptr, %NULL), rcf, IIF(ISOBJECT(pStringFormat), pStringFormat.Ptr, %NULL), _
         boundingBox, BYVAL %NULL, BYVAL %NULL)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Measures the extent of the string in the specified font and layout rectangle.
   ' =====================================================================================
   METHOD MeasureString4 (BYREF wszString AS WSTRINGZ, BYVAL pFont AS IGdipFont, _
   BYREF layoutRect AS RectF, BYREF boundingBox AS RectF) THREADSAFE AS LONG
      m_hStatus = GdipMeasureString(m_pGraphics, wszString, LEN(wszString), _
         IIF(ISOBJECT(pFont), pFont.Ptr, %NULL), layoutRect, %NULL, _
         boundingBox, BYVAL %NULL, BYVAL %NULL)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Measures the extent of the string in the specified font and layout rectangle.
   ' =====================================================================================
   METHOD MeasureString5 (BYREF wszString AS WSTRINGZ, BYVAL pFont AS IGdipFont, _
   BYREF origin AS PointF, BYREF boundingBox AS RectF) THREADSAFE AS LONG
      LOCAL rcf AS RectF
      rcf.X = origin.X : rcf.Y = origin.Y
      m_hStatus = GdipMeasureString(m_pGraphics, wszString, LEN(wszString), _
         IIF(ISOBJECT(pFont), pFont.Ptr, %NULL), rcf, %NULL, _
         boundingBox, BYVAL %NULL, BYVAL %NULL)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a set of regions each of which bounds a range of character positions within a string.
   ' =====================================================================================
   METHOD MeasureCharacterRanges (BYREF wszString AS WSTRINGZ, BYVAL pFont AS IGdipFont, _
   BYREF layoutRect AS RectF, BYVAL pStringFormat AS IGdipStringFormat, _
   BYVAL regionCount AS LONG, BYREF regions AS IGdipRegion) THREADSAFE AS LONG
      IF VARPTR(regions) = 0 OR regionCount <= 0 THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      LOCAL i AS LONG
      REDIM pRegions(regionCount - 1) AS IGdipRegion AT VARPTR(regions)
      REDIM rgRegions(regionCount - 1) AS DWORD
      FOR i = 0 TO regionCount - 1
         rgRegions(i) = pRegions(i).Ptr
      NEXT
      m_hStatus = GdipMeasureCharacterRanges(m_pGraphics, wszString, LEN(wszString), _
                  IIF(ISOBJECT(pFont), pFont.Ptr, %NULL), layoutRect, _
                  IIF(ISOBJECT(pStringFormat), pStringFormat.Ptr, %NULL), _
                  regionCount, rgRegions(0))
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws characters at the specified positions. The method gives the client complete
   ' control over the appearance of text. The method assumes that the client has already
   ' set up the format and layout to be applied.
   ' =====================================================================================
   METHOD DrawDriverString (BYREF rgText AS WORD, BYVAL length AS LONG, BYVAL pFont AS IGdipFont, _
   BYVAL pBrush AS IGdipBrush, BYREF positions AS PointF, BYVAL flags AS LONG, BYVAL pMatrix AS IGdipMatrix) THREADSAFE AS LONG
      m_hStatus = GdipDrawDriverString(m_pGraphics, rgText, length, IIF(ISOBJECT(pFont), pFont.Ptr, %NULL), _
                  IIF(ISOBJECT(pBrush), pBrush.Ptr, %NULL), positions, flags, IIF(ISOBJECT(pMatrix), pMatrix.Ptr, %NULL))
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Measures the bounding box for the specified characters and their corresponding positions.
   ' =====================================================================================
   METHOD MeasureDriverString (BYREF rgText AS WORD, BYVAL length AS LONG, BYVAL pFont AS IGdipFont, _
   BYREF positions AS PointF, BYVAL flags AS LONG, BYVAL pMatrix AS IGdipMatrix, BYREF boundingBox AS RectF) THREADSAFE AS LONG
      m_hStatus = GdipMeasureDriverString(m_pGraphics, rgText, length, IIF(ISOBJECT(pFont), pFont.Ptr, %NULL), _
                  positions, flags, IIF(ISOBJECT(pMatrix), pMatrix.Ptr, %NULL), boundingBox)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws a cached bitmap on this graphics destination offset by x, y. Note this will fail
   ' with WrongState if the CachedBitmap native format differs from this Graphics.
   ' =====================================================================================
   METHOD DrawCachedBitmap (BYVAL cb AS IGdipCachedBitmap, BYVAL x AS LONG, BYVAL y AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipDrawCachedBitmap(m_pGraphics, cb.Ptr, x, y)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Draws an image.
   ' =====================================================================================
   METHOD DrawImage (BYVAL pImage AS IGdipImage, BYVAL x AS SINGLE, BYVAL y AS SINGLE, OPTIONAL BYVAL nWidth AS SINGLE, BYVAL nHeight AS SINGLE) THREADSAFE AS LONG
      IF nWidth = 0 AND nHeight = 0 THEN
         m_hStatus = GdipDrawImage(m_pGraphics, IIF(ISOBJECT(pImage), pImage.Ptr, %NULL), x, y)
      ELSE
         m_hStatus = GdipDrawImageRect(m_pGraphics, IIF(ISOBJECT(pImage), pImage.Ptr, %NULL), x, y, nWidth, nHeight)
      END IF
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD DrawImagePoint (BYVAL pImage AS IGdipImage, BYREF pt AS PointF) THREADSAFE AS LONG
      m_hStatus = GdipDrawImage(m_pGraphics, IIF(ISOBJECT(pImage), pImage.Ptr, %NULL), pt.x, pt.y)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD DrawImageRect (BYVAL pImage AS IGdipImage, BYVAL x AS SINGLE, BYVAL y AS SINGLE, BYVAL nWidth AS SINGLE, BYVAL nHeight AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipDrawImageRect(m_pGraphics, IIF(ISOBJECT(pImage), pImage.Ptr, %NULL), x, y, nWidth, nHeight)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD DrawImagePoints (BYVAL pImage AS IGdipImage, BYREF destPoints AS PointF, BYVAL nCount AS LONG) THREADSAFE AS LONG
      IF nCount <> 3 AND nCount <> 4 THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      m_hStatus = GdipDrawImagePoints(m_pGraphics, IIF(ISOBJECT(pImage), pImage.Ptr, %NULL), destPoints, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD DrawImagePointRect (BYVAL pImage AS IGdipImage, BYVAL x AS SINGLE, BYVAL y AS SINGLE, _
   BYVAL srcx AS SINGLE, BYVAL srcy AS SINGLE, BYVAL srcwidth AS SINGLE, BYVAL srcheight AS SINGLE, BYVAL srcUnit AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipDrawImagePointRect(m_pGraphics, IIF(ISOBJECT(pImage), pImage.Ptr, %NULL), _
                  x, y, srcx, srcy, srcwidth, srcheight, srcUnit)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD DrawImageRectRect (BYVAL pImage AS IGdipImage, BYREF destRect AS RectF, _
   BYVAL srcx AS SINGLE, BYVAL srcy AS SINGLE, BYVAL srcwidth AS SINGLE, BYVAL srcheight AS SINGLE, _
   BYVAL srcUnit AS LONG, OPTIONAL BYVAL pImageAttributes AS IGdipImageAttributes, BYVAL pCallback AS DWORD, _
   BYVAL pCallbackData AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipDrawImageRectRect(m_pGraphics, IIF(ISOBJECT(pImage), pImage.Ptr, %NULL), _
                  destRect.x, destRect.y, destRect.Width, destRect.Height, srcx, srcy, srcwidth, srcheight, _
                  srcUnit, IIF(ISOBJECT(pImageAttributes), pImageAttributes.Ptr, %NULL), _
                  pCallback, pCallbackData)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD DrawImagePointsRect (BYVAL pImage AS IGdipImage, BYREF destPoints AS PointF, BYVAL nCount AS LONG, _
   BYVAL srcx AS SINGLE, BYVAL srcy AS SINGLE, BYVAL srcwidth AS SINGLE, BYVAL srcheight AS SINGLE, _
   BYVAL srcUnit AS LONG, OPTIONAL BYVAL pImageAttributes AS IGdipImageAttributes, BYVAL pCallback AS DWORD, _
   BYVAL pCallbackData AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipDrawImagePointsRect(m_pGraphics, IIF(ISOBJECT(pImage), pImage.Ptr, %NULL), _
                  destPoints, nCount, srcx, srcy, srcwidth, srcheight, _
                  srcUnit, IIF(ISOBJECT(pImageAttributes), pImageAttributes.Ptr, %NULL), _
                  pCallback, pCallbackData)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

#IF (%GDIPVER >= &H0110)

   ' =====================================================================================
   METHOD DrawImageRectRect2 (BYVAL pImage AS IGdipImage, BYREF destRect AS RectF, _
   BYREF sourceRect AS RectF, BYVAL srcUnit AS LONG, OPTIONAL BYVAL pImageAttributes AS IGdipImageAttributes) THREADSAFE AS LONG
      m_hStatus = GdipDrawImageRectRect(m_pGraphics, IIF(ISOBJECT(pImage), pImage.Ptr, %NULL), _
                  destRect.x, destRect.y, destRect.Width, destRect.Height, sourceRect.x, sourceRect.y, _
                  sourceRect.Width, sourceRect.Height, _
                  srcUnit, IIF(ISOBJECT(pImageAttributes), pImageAttributes.Ptr, %NULL), %NULL, %NULL)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD DrawImageFX (BYVAL pImage AS IGdipImage, BYREF sourceRect AS RectF, BYVAL pMatrix AS IGdipMatrix, _
   BYVAL pEffect AS IGdipEffect, BYVAL pImageAttributes AS IGdipImageAttributes, BYVAL srcUnit AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipDrawImageFX(m_pGraphics, pImage.Ptr, sourceRect, IIF(ISOBJECT(pMatrix), pMatrix.Ptr, %NULL), _
                  IIF(ISOBJECT(pEffect), pEffect.Ptr, %NULL), IIF(ISOBJECT(pImageAttributes), pImageAttributes.Ptr, %NULL), srcUnit)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

#ENDIF   ' //(GDIPVER >= 0x0110)

   ' =====================================================================================
   ' Calls an application-defined callback function for each record in a specified metafile.
   ' You can use this method to display a metafile by calling PlayRecord in the callback function.
   ' =====================================================================================
   METHOD EnumerateMetafileDestPoint (BYVAL pMetafile AS IGdipMetafile, BYREF destPoint AS PointF, _
   OPTIONAL BYVAL pCallback AS DWORD, BYVAL pCallbackData AS DWORD, BYVAL pImageAttributes AS IGdipImageAttributes) AS LONG
      m_hStatus = GdipEnumerateMetafileDestPoint(m_pGraphics, IIF(ISOBJECT(pMetafile), pMetafile.Ptr, %NULL), _
                  destPoint, pCallback, pCallbackData, IIF(ISOBJECT(pImageAttributes), pImageAttributes.Ptr, %NULL))
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD EnumerateMetafileDestRect (BYVAL pMetafile AS IGdipMetafile, BYREF destRect AS RectF, BYVAL pCallback AS DWORD, _
   OPTIONAL BYVAL pCallbackData AS DWORD, BYVAL pImageAttributes AS IGdipImageAttributes) AS LONG
      m_hStatus = GdipEnumerateMetafileDestRect(m_pGraphics, IIF(ISOBJECT(pMetafile), pMetafile.Ptr, %NULL), _
                  destRect, pCallback, pCallbackData, IIF(ISOBJECT(pImageAttributes), pImageAttributes.Ptr, %NULL))
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD EnumerateMetafileDestPoints (BYVAL pMetafile AS IGdipMetafile, BYREF destPoints AS PointF, BYVAL nCount AS LONG, BYVAL pCallback AS DWORD, _
   OPTIONAL BYVAL pCallbackData AS DWORD, BYVAL pImageAttributes AS IGdipImageAttributes) AS LONG
      m_hStatus = GdipEnumerateMetafileDestPoints(m_pGraphics, IIF(ISOBJECT(pMetafile), pMetafile.Ptr, %NULL), _
                  destPoints, nCount, pCallback, pCallbackData, IIF(ISOBJECT(pImageAttributes), pImageAttributes.Ptr, %NULL))
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD EnumerateMetafileSrcRectDestPoint (BYVAL pMetafile AS IGdipMetafile, BYREF destPoint AS PointF, _
   BYREF srcRect AS RectF, BYVAL srcUnit AS LONG, BYVAL pCallback AS DWORD, _
   OPTIONAL BYVAL pCallbackData AS DWORD, BYVAL pImageAttributes AS IGdipImageAttributes) AS LONG
      m_hStatus = GdipEnumerateMetafileSrcRectDestPoint(m_pGraphics, IIF(ISOBJECT(pMetafile), pMetafile.Ptr, %NULL), _
                  destPoint, srcRect, srcUnit, pCallback, pCallbackData, IIF(ISOBJECT(pImageAttributes), pImageAttributes.Ptr, %NULL))
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD EnumerateMetafileSrcRectDestRect (BYVAL pMetafile AS IGdipMetafile, BYREF destRect AS RectF, _
   BYREF srcRect AS RectF, BYVAL srcUnit AS LONG, BYVAL pCallback AS DWORD, _
   OPTIONAL BYVAL pCallbackData AS DWORD, BYVAL pImageAttributes AS IGdipImageAttributes) AS LONG
      m_hStatus = GdipEnumerateMetafileSrcRectDestRect(m_pGraphics, IIF(ISOBJECT(pMetafile), pMetafile.Ptr, %NULL), _
                  destRect, srcRect, srcUnit, pCallback, pCallbackData, IIF(ISOBJECT(pImageAttributes), pImageAttributes.Ptr, %NULL))
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD EnumerateMetafileSrcRectDestPoints (BYVAL pMetafile AS IGdipMetafile, BYREF destPoints AS PointF, _
   BYVAL nCount AS LONG, BYREF srcRect AS RectF, BYVAL srcUnit AS LONG, BYVAL pCallback AS DWORD, _
   OPTIONAL BYVAL pCallbackData AS DWORD, BYVAL pImageAttributes AS IGdipImageAttributes) AS LONG
      m_hStatus = GdipEnumerateMetafileSrcRectDestPoints(m_pGraphics, IIF(ISOBJECT(pMetafile), pMetafile.Ptr, %NULL), _
                  destPoints, nCount, srcRect, srcUnit, pCallback, pCallbackData, IIF(ISOBJECT(pImageAttributes), pImageAttributes.Ptr, %NULL))
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates the clipping region of this Graphics object to a region that is the combination
   ' of itself and the clipping region of another Graphics object.
   ' =====================================================================================
   METHOD SetClip (BYVAL pGraphics AS IGdipGraphics, OPTIONAL BYVAL combineMode AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetClipGraphics(m_pGraphics, pGraphics.Ptr, combineMode)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates the clipping region of this Graphics object to a region that is the
   ' combination of itself and a rectangle.
   ' =====================================================================================
   METHOD SetClipRect (BYREF rc AS RectF, OPTIONAL BYVAL combineMode AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetClipRect(m_pGraphics, rc.x, rc.y, rc.Width, rc.Height, combineMode)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates the clipping region of this Graphics object to a region that is the combination
   ' of itself and the region specified by a graphics path. If a figure in the path is not
   ' closed, this method treats the nonclosed figure as if it were closed by a straight
   ' line that connects the figure's starting and ending points.
   ' =====================================================================================
   METHOD SetClipPath (BYVAL pPath AS IGdipGraphicsPath, OPTIONAL BYVAL combineMode AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetClipPath(m_pGraphics, pPath.Ptr, combineMode)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates the clipping region of this Graphics object to a region that is the
   ' combination of itself and the region specified by a Region object.
   ' =====================================================================================
   METHOD SetClipRegion (BYVAL pRegion AS IGdipRegion, OPTIONAL BYVAL combineMode AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetClipRegion(m_pGraphics, pRegion.Ptr, combineMode)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates the clipping region of this Graphics object to a region that is the combination
   ' of itself and a Windows Graphics Device Interface (GDI) region.
   ' =====================================================================================
   METHOD SetClipHrgn (BYVAL hRgn AS DWORD, OPTIONAL BYVAL combineMode AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetClipRegion(m_pGraphics, hRgn, combineMode)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates the clipping region of this Graphics object to the portion of the specified
   ' rectangle that intersects with the current clipping region of this Graphics object.
   ' =====================================================================================
   METHOD IntersectClipRect (BYREF rc AS RectF) THREADSAFE AS LONG
      m_hStatus = GdipSetClipRect(m_pGraphics, rc.x, rc.y, rc.Width, rc.Height, %CombineModeIntersect)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates the clipping region of this Graphics object to the portion of the specified
   ' region that intersects with the current clipping region of this Graphics object.
   ' =====================================================================================
   METHOD IntersectClipRegion (BYVAL pRegion AS IGdipRegion) THREADSAFE AS LONG
      m_hStatus = GdipSetClipRegion(m_pGraphics, pRegion.Ptr, %CombineModeIntersect)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates the clipping region to the portion of itself that does not intersect the specified rectangle.
   ' =====================================================================================
   METHOD ExcludeClipRect (BYREF rc AS RectF) THREADSAFE AS LONG
      m_hStatus = GdipSetClipRect(m_pGraphics, rc.x, rc.y, rc.Width, rc.Height, %CombineModeExclude)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates the clipping region with the portion of itself that does not overlap the specified region.
   ' =====================================================================================
   METHOD ExcludeClipRegion (BYVAL pRegion AS IGdipRegion) THREADSAFE AS LONG
      m_hStatus = GdipSetClipRegion(m_pGraphics, pRegion.Ptr, %CombineModeExclude)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the clipping region of this Graphics object to an infinite region.
   ' =====================================================================================
   METHOD ResetClip () THREADSAFE AS LONG
      m_hStatus = GdipResetClip(m_pGraphics)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Translates the clipping region of this Graphics object.
   ' =====================================================================================
   METHOD TranslateClip (BYVAL dx AS SINGLE, BYVAL dy AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipTranslateClip(m_pGraphics, dx, dy)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the clipping region of this Graphics object.
   ' =====================================================================================
   METHOD GetClip (BYREF pRegion AS IGdipRegion) THREADSAFE AS LONG
      IF VARPTR(pRegion) = 0 THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      IF ISNOTHING(pRegion) THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      m_hStatus = GdipGetClip(m_pGraphics, pRegion.Ptr)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a rectangle that encloses the clipping region of this Graphics object.
   ' =====================================================================================
   METHOD GetClipBounds (BYREF rc AS RectF) THREADSAFE AS LONG
      m_hStatus = GdipGetClipBounds(m_pGraphics, rc)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Determines whether the clipping region of this Graphics object is empty.
   ' =====================================================================================
   METHOD IsClipEmpty () THREADSAFE AS LONG
      LOCAL booln AS LONG
      m_hStatus = GdipIsClipEmpty(m_pGraphics, booln)
      METHOD = booln
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a rectangle that encloses the visible clipping region of this Graphics object.
   ' The visible clipping region is the intersection of the clipping region of this
   ' Graphics object and the clipping region of the window.
   ' =====================================================================================
   METHOD GetVisibleClipBounds (BYREF rc AS RectF) THREADSAFE AS LONG
      m_hStatus = GdipGetVisibleClipBounds(m_pGraphics, rc)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Determines whether the visible clipping region of this Graphics object is empty. The
   ' visible clipping region is the intersection of the clipping region of this Graphics
   ' object and the clipping region of the window.
   ' =====================================================================================
   METHOD IsVisibleClipEmpty () THREADSAFE AS LONG
      LOCAL booln AS LONG
      m_hStatus = GdipIsVisibleClipEmpty(m_pGraphics, booln)
      METHOD = booln
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Determines whether the specified point is inside the visible clipping region of this
   ' Graphics object. The visible clipping region is the intersection of the clipping
   ' region of this Graphics object and the clipping region of the window.
   ' =====================================================================================
   METHOD IsVisiblePoint (BYREF pt AS PointF) THREADSAFE AS LONG
      LOCAL booln AS LONG
      m_hStatus = GdipIsVisiblePoint(m_pGraphics, pt.x, pt.y, booln)
      METHOD = booln
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Determines whether the specified point is inside the visible clipping region of this
   ' Graphics object. The visible clipping region is the intersection of the clipping
   ' region of this Graphics object and the clipping region of the window.
   ' =====================================================================================
   METHOD IsVisiblePointXY (BYVAL x AS SINGLE, BYVAL y AS SINGLE) THREADSAFE AS LONG
      LOCAL booln AS LONG
      m_hStatus = GdipIsVisiblePoint(m_pGraphics, x, y, booln)
      METHOD = booln
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Determines whether the specified specified rectangle intersects the visible clipping
   ' region of this Graphics object. The visible clipping region is the intersection of
   ' the clipping region of this Graphics object and the clipping region of the window.
   ' =====================================================================================
   METHOD IsVisibleRect (BYREF rc AS RectF) THREADSAFE AS LONG
      LOCAL booln AS LONG
      m_hStatus = GdipIsVisibleRect(m_pGraphics, rc.x, rc.y, rc.Width, rc.Height, booln)
      METHOD = booln
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Determines whether the specified specified rectangle intersects the visible clipping
   ' region of this Graphics object. The visible clipping region is the intersection of
   ' the clipping region of this Graphics object and the clipping region of the window.
   ' =====================================================================================
   METHOD IsVisibleRectXY (BYVAL x AS SINGLE, BYVAL y AS SINGLE, BYVAL nWidth AS SINGLE, BYVAL nHeight AS SINGLE) THREADSAFE AS LONG
      LOCAL booln AS LONG
      m_hStatus = GdipIsVisibleRect(m_pGraphics, x, y, nWidth, nHeight, booln)
      METHOD = booln
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Saves the current state (transformations, clipping region, and quality settings) of
   ' this Graphics object. You can restore the state later by calling the Restore method.
   ' =====================================================================================
   METHOD Save () THREADSAFE AS DWORD
      LOCAL gstate AS DWORD
      m_hStatus = GdipSaveGraphics(m_pGraphics, gstate)
      METHOD = gstate
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the state of this Graphics object to the state stored by a previous call to the
   ' Save method of this Graphics object.
   ' =====================================================================================
   METHOD Restore (BYVAL gstate AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipRestoreGraphics(m_pGraphics, gstate)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Begins a new graphics container.
   ' =====================================================================================
   METHOD BeginContainer () THREADSAFE AS DWORD
      LOCAL dwState AS DWORD
      m_hStatus = GdipBeginContainer2(m_pGraphics, dwState)
      METHOD = dwState
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Begins a new graphics container.
   ' =====================================================================================
   METHOD BeginContainerRect (BYREF dstrect AS RectF, BYREF srcrect AS RectF, BYVAL unit AS LONG) THREADSAFE AS DWORD
      LOCAL dwState AS DWORD
      m_hStatus = GdipBeginContainer(m_pGraphics, dstrect, srcrect, unit, dwState)
      METHOD = dwState
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Closes a graphics container that was previously opened by the BeginContainer method.
   ' =====================================================================================
   METHOD EndContainer (BYVAL dwState AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipEndContainer(m_pGraphics, dwState)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' // Only valid when recording metafiles.

   ' =====================================================================================
   ' Adds a text comment to an existing metafile.
   ' =====================================================================================
   METHOD AddMetafileComment (BYREF rgData AS BYTE, BYVAL sizeData AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipComment(m_pGraphics, sizeData, rgData)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a Windows halftone palette.
   ' =====================================================================================
   METHOD GetHalftonePalette () THREADSAFE AS DWORD
      METHOD = GdipCreateHalftonePalette
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' ########################################################################################
