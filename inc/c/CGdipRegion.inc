' ########################################################################################
' Microsoft Windows
' File: CGdipRegion.inc
' Contents: GDI+ region class.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CGDIPREGION_INC = 1

' ########################################################################################
' CGdipRegion Class
' ########################################################################################
CLASS CGdipRegion

   INSTANCE m_hStatus AS LONG
   INSTANCE m_pRegion AS DWORD

   ' =====================================================================================
   ' Cleanup
   ' =====================================================================================
   CLASS METHOD Destroy
      IF m_pRegion THEN GdipDeleteRegion(m_pRegion)
   END METHOD
   ' =====================================================================================

   INTERFACE IGdipRegion : INHERIT IAutomation

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the Pen object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pRegion
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the Pen object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      IF m_pRegion THEN GdipDeleteRegion(m_pRegion)
      m_pRegion = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Region object
   ' =====================================================================================
   METHOD Region () THREADSAFE AS LONG
      IF m_pRegion THEN GdipDeleteRegion(m_pRegion)
      m_hStatus = GdipCreateRegion(m_pRegion)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD RegionRect (BYREF rc AS RectF) THREADSAFE AS LONG
      IF m_pRegion THEN GdipDeleteRegion(m_pRegion)
      m_hStatus = GdipCreateRegionRect(rc, m_pRegion)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD RegionPath (BYVAL pPath AS IGdipGraphicsPath) THREADSAFE AS LONG
      IF m_pRegion THEN GdipDeleteRegion(m_pRegion)
      m_hStatus = GdipCreateRegionPath(pPath.Ptr, m_pRegion)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD RegionRgnData (BYREF regionData AS BYTE, BYVAL nSize AS LONG) THREADSAFE AS LONG
      IF m_pRegion THEN GdipDeleteRegion(m_pRegion)
      m_hStatus = GdipCreateRegionRgnData(regionData, nSize, m_pRegion)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD RegionHrgn (BYVAL hRgn AS DWORD) THREADSAFE AS LONG
      IF m_pRegion THEN GdipDeleteRegion(m_pRegion)
      m_hStatus = GdipCreateRegionHrgn(hRgn, m_pRegion)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a GDI+Region object from a GDI region.
   ' =====================================================================================
   METHOD FromHRGN (BYVAL hRgn AS DWORD) THREADSAFE AS IGdipRegion
      LOCAL pNewRegion AS IGdipRegion
      LOCAL pNewRegionPtr AS DWORD
      m_hStatus = GdipCreateRegionHrgn(hRgn, pNewRegionPtr)
      pNewRegion = CLASS "CGdipRegion"
      pNewRegion.Ptr = pNewRegionPtr
      METHOD = pNewRegion
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new Region object based on this Region object.
   ' =====================================================================================
   METHOD Clone () THREADSAFE AS IGdipRegion
      LOCAL pCloneRegion AS IGdipRegion
      LOCAL pCloneRegionPtr AS DWORD
      m_hStatus = GdipCloneRegion(m_pRegion, pCloneRegionPtr)
      pCloneRegion = CLASS "CGdipRegion"
      pCloneRegion.Ptr = pCloneRegionPtr
      METHOD = pCloneRegion
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this region to an infinite region.
   ' =====================================================================================
   METHOD MakeInfinite () THREADSAFE AS LONG
      m_hStatus = GdipSetInfinite(m_pRegion)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this region to an empty region. In other words, the region occupies no space
   ' on the display device.
   ' =====================================================================================
   METHOD MakeEmpty () THREADSAFE AS LONG
      m_hStatus = GdipSetEmpty(m_pRegion)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this region to the portion of itself that intersects the specified rectangle's interior.
   ' =====================================================================================
   METHOD Intersect (BYREF rc AS RectF) THREADSAFE AS LONG
      m_hStatus = GdipCombineRegionRect(m_pRegion, rc, %CombineModeIntersect)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this region to the portion of itself that intersects the specified path's interior.
   ' =====================================================================================
   METHOD IntersectPath (BYVAL pPath AS IGdipGraphicsPath) THREADSAFE AS LONG
      m_hStatus = GdipCombineRegionPath(m_pRegion, pPath.Ptr, %CombineModeIntersect)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this region to the portion of itself that intersects another region.
   ' =====================================================================================
   METHOD IntersectRegion (BYVAL pRegion AS IGdipRegion) THREADSAFE AS LONG
      m_hStatus = GdipCombineRegionRegion(m_pRegion, pRegion.Ptr, %CombineModeIntersect)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this region to all portions (intersecting and nonintersecting) of itself and
   ' all portions of the specified rectangle's interior.
   ' =====================================================================================
   METHOD Union (BYREF rc AS RectF) THREADSAFE AS LONG
      m_hStatus = GdipCombineRegionRect(m_pRegion, rc, %CombineModeUnion)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this region to all portions (intersecting and nonintersecting) of itself and
   ' all portions of the specified path's interior.
   ' =====================================================================================
   METHOD UnionPath (BYVAL pPath AS IGdipGraphicsPath) THREADSAFE AS LONG
      m_hStatus = GdipCombineRegionPath(m_pRegion, pPath.Ptr, %CombineModeUnion)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this region to all portions (intersecting and nonintersecting) of itself and
   ' all portions of another region.
   ' =====================================================================================
   METHOD UnionRegion (BYVAL pRegion AS IGdipRegion) THREADSAFE AS LONG
      m_hStatus = GdipCombineRegionRegion(m_pRegion, pRegion.Ptr, %CombineModeUnion)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this region to the nonintersecting portions of itself and the specified rectangle's interior.
   ' =====================================================================================
   METHOD Xor (BYREF rc AS RectF) THREADSAFE AS LONG
      m_hStatus = GdipCombineRegionRect(m_pRegion, rc, %CombineModeXor)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this region to the nonintersecting portions of itself and the specified path's interior.
   ' =====================================================================================
   METHOD XorPath (BYVAL pPath AS IGdipGraphicsPath) THREADSAFE AS LONG
      m_hStatus = GdipCombineRegionPath(m_pRegion, pPath.Ptr, %CombineModeXor)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this region to the nonintersecting portions of itself and another region.
   ' =====================================================================================
   METHOD XorRegion (BYVAL pRegion AS IGdipRegion) THREADSAFE AS LONG
      m_hStatus = GdipCombineRegionRegion(m_pRegion, pRegion.Ptr, %CombineModeXor)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this region to the portion of itself that does not intersect the specified rectangle's interior.
   ' =====================================================================================
   METHOD Exclude (BYREF rc AS RectF) THREADSAFE AS LONG
      m_hStatus = GdipCombineRegionRect(m_pRegion, rc, %CombineModeExclude)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this region to the portion of itself that does not intersect the specified path's interior.
   ' =====================================================================================
   METHOD ExcludePath (BYVAL pPath AS IGdipGraphicsPath) THREADSAFE AS LONG
      m_hStatus = GdipCombineRegionPath(m_pRegion, pPath.Ptr, %CombineModeExclude)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this region to the portion of itself that does not intersect another region.
   ' =====================================================================================
   METHOD ExcludeRegion (BYVAL pRegion AS IGdipRegion) THREADSAFE AS LONG
      m_hStatus = GdipCombineRegionRegion(m_pRegion, pRegion.Ptr, %CombineModeExclude)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this region to the portion of itself that does not intersect the specified rectangle's interior.
   ' =====================================================================================
   METHOD Complement (BYREF rc AS RectF) THREADSAFE AS LONG
      m_hStatus = GdipCombineRegionRect(m_pRegion, rc, %CombineModeComplement)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this region to the portion of itself that does not intersect the specified path's interior.
   ' =====================================================================================
   METHOD ComplementPath (BYVAL pPath AS IGdipGraphicsPath) THREADSAFE AS LONG
      m_hStatus = GdipCombineRegionPath(m_pRegion, pPath.Ptr, %CombineModeComplement)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this region to the portion of itself that does not intersect another region.
   ' =====================================================================================
   METHOD ComplementRegion (BYVAL pRegion AS IGdipRegion) THREADSAFE AS LONG
      m_hStatus = GdipCombineRegionRegion(m_pRegion, pRegion.Ptr, %CombineModeComplement)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Offsets this region by specified amounts in the horizontal and vertical directions.
   ' =====================================================================================
   METHOD Translate (BYVAL dx AS SINGLE, BYVAL dy AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipTranslateRegion(m_pRegion, dx, dy)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Transforms this region by multiplying each of its data points by a specified matrix.
   ' =====================================================================================
   METHOD Transform (BYVAL pMatrix AS IGdipMatrix) THREADSAFE AS LONG
      m_hStatus = GdipTransformRegion(m_pRegion, pMatrix.Ptr)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a rectangle that encloses this region.
   ' =====================================================================================
   METHOD GetBounds (BYREF rc AS RectF, BYVAL pGraphics AS IGdipGraphics) THREADSAFE AS LONG
      m_hStatus = GdipGetRegionBounds(m_pRegion, pGraphics.Ptr, rc)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a GDI region from this region.
   ' =====================================================================================
   METHOD GetHRGN (BYVAL pGraphics AS IGdipGraphics) THREADSAFE AS DWORD
      LOCAL hrgn AS DWORD
      m_hStatus = GdipGetRegionHRgn(m_pRegion, pGraphics.Ptr, hrgn)
      METHOD = hrgn
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Determines whether this region is empty.
   ' =====================================================================================
   METHOD IsEmpty (BYVAL pGraphics AS IGdipGraphics) THREADSAFE AS LONG
      LOCAL booln AS LONG
      m_hStatus = GdipIsEmptyRegion(m_pRegion, pGraphics.Ptr, booln)
      METHOD = booln
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Determines whether this region is infinite.
   ' =====================================================================================
   METHOD IsInfinite (BYVAL pGraphics AS IGdipGraphics) THREADSAFE AS LONG
      LOCAL booln AS LONG
      m_hStatus = GdipIsInfiniteRegion(m_pRegion, pGraphics.Ptr, booln)
      METHOD = booln
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Determines whether this region is equal to a specified region.
   ' =====================================================================================
   METHOD Equals (BYVAL pRegion AS IGdipRegion, BYVAL pGraphics AS IGdipGraphics) THREADSAFE AS LONG
      LOCAL booln AS LONG
      m_hStatus = GdipIsEqualRegion(m_pRegion, pRegion.Ptr, pGraphics.Ptr, booln)
      METHOD = booln
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets number of bytes of data that describes this region.
   ' =====================================================================================
   METHOD GetDataSize () THREADSAFE AS DWORD
      LOCAL bufferSize AS DWORD
      m_hStatus = GdipGetRegionDataSize(m_pRegion, bufferSize)
      METHOD = bufferSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets data that describes this region.
   ' =====================================================================================
   METHOD GetData (BYREF buffer AS BYTE, BYVAL bufferSize AS DWORD, OPTIONAL BYREF sizeFilled AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipGetRegionData(m_pRegion, buffer, bufferSize, sizeFilled)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Determines whether a point is inside this region.
   ' =====================================================================================
   METHOD IsVisiblePoint (BYREF pt AS PointF, OPTIONAL BYVAL pGraphics AS IGdipGraphics) THREADSAFE AS LONG
      LOCAL booln AS LONG
      m_hStatus = GdipIsVisibleRegionPoint(m_pRegion, pt.x, pt.y, IIF(ISOBJECT(pGraphics), pGraphics.Ptr, %NULL), booln)
      METHOD = booln
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Determines whether a point is inside this region.
   ' =====================================================================================
   METHOD IsVisiblePointXY (BYVAL x AS SINGLE, BYVAL y AS SINGLE, OPTIONAL BYVAL pGraphics AS IGdipGraphics) THREADSAFE AS LONG
      LOCAL booln AS LONG
      m_hStatus = GdipIsVisibleRegionPoint(m_pRegion, x, y, IIF(ISOBJECT(pGraphics), pGraphics.Ptr, %NULL), booln)
      METHOD = booln
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Determines whether a point is inside this region.
   ' =====================================================================================
   METHOD IsVisibleRect (BYREF rc AS RectF, OPTIONAL BYVAL pGraphics AS IGdipGraphics) THREADSAFE AS LONG
      LOCAL booln AS LONG
      m_hStatus = GdipIsVisibleRegionRect(m_pRegion, rc.x, rc.y, rc.Width, rc.Height, IIF(ISOBJECT(pGraphics), pGraphics.Ptr, %NULL), booln)
      METHOD = booln
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Determines whether a point is inside this region.
   ' =====================================================================================
   METHOD IsVisibleRectXY (BYVAL x AS SINGLE, BYVAL y AS SINGLE, BYVAL nWidth AS SINGLE, BYVAL nHeight AS SINGLE, OPTIONAL BYVAL pGraphics AS IGdipGraphics) THREADSAFE AS LONG
      LOCAL booln AS LONG
      m_hStatus = GdipIsVisibleRegionRect(m_pRegion, x, y, nWidth, nHeight, IIF(ISOBJECT(pGraphics), pGraphics.Ptr, %NULL), booln)
      METHOD = booln
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of rectangles that approximate this region. The region is transformed
   ' by a specified matrix before the rectangles are calculated.
   ' =====================================================================================
   METHOD GetRegionScansCount (BYVAL pMatrix AS IGdipMatrix) THREADSAFE AS DWORD
      LOCAL nCount AS DWORD
      m_hStatus = GdipGetRegionScansCount(m_pRegion, nCount, pMatrix.Ptr)
      METHOD = nCount
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of rectangles that approximate this region. The region is transformed
   ' by a specified matrix before the rectangles are calculated.
   ' =====================================================================================
   METHOD GetRegionScans (BYVAL pMatrix AS IGdipMatrix, BYREF rects AS RectF, BYREF nCount AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipGetRegionScans(m_pRegion, rects, nCount, pMatrix.Ptr)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' ########################################################################################
