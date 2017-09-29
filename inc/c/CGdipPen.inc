' ########################################################################################
' Microsoft Windows
' File: CGdipPen.inc
' Contents: GDI+ graphics class.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CGDIPEN_INC = 1

' ########################################################################################
' CGdipPen Class
' ########################################################################################
CLASS CGdipPen

   INSTANCE m_hStatus AS LONG
   INSTANCE m_pPen AS DWORD

   ' =====================================================================================
   ' Cleanup
   ' =====================================================================================
   CLASS METHOD Destroy
      IF m_pPen THEN GdipDeletePen(m_pPen)
   END METHOD
   ' =====================================================================================

   INTERFACE IGdipPen : INHERIT IAutomation

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
      PROPERTY = m_pPen
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the Pen object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      IF m_pPen THEN GdipDeletePen(m_pPen)
      m_pPen = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Pen object that uses a specified color and width.
   ' =====================================================================================
   METHOD FromColor (BYVAL colour AS DWORD, OPTIONAL BYVAL vWidth AS VARIANT) THREADSAFE AS LONG
      LOCAL nWidth AS SINGLE
      IF ISMISSING(vWidth) THEN nWidth = 1.0! ELSE nWidth = VARIANT#(vWidth)
      m_hStatus = GdipCreatePen1(colour, nWidth, %UnitWorld, m_pPen)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Pen object that uses the attributes of a brush and a real number to set the
   ' width of this Pen object.
   ' =====================================================================================
   METHOD FromBrush (BYVAL pBrush AS IGdipBrush, OPTIONAL BYVAL vWidth AS VARIANT) THREADSAFE AS LONG
      IF ISNOTHING(pBrush) THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      LOCAL nWidth AS SINGLE
      IF ISMISSING(vWidth) THEN nWidth = 1.0! ELSE nWidth = VARIANT#(vWidth)
      m_hStatus = GdipCreatePen2(pBrush.Ptr, nWidth, %UnitWorld, m_pPen)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new Pen object based on this Pen object.
   ' =====================================================================================
   METHOD Clone () THREADSAFE AS IGdipPen
      LOCAL pClonePen AS IGdipPen
      LOCAL pClonePenPtr AS DWORD
      m_hStatus = GdipClonePen(m_pPen, pClonePenPtr)
      pClonePen = CLASS "CGdipPen"
      pClonePen.Ptr = pClonePenPtr
      METHOD = pClonePen
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the width for this Pen object.
   ' =====================================================================================
   METHOD SetWidth (BYVAL nWidth AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipSetPenWidth(m_pPen, nWidth)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the width currently set for this Pen object.
   ' =====================================================================================
   METHOD GetWidth () THREADSAFE AS SINGLE
      LOCAL nWidth AS SINGLE
      m_hStatus = GdipGetPenWidth(m_pPen, nWidth)
      METHOD = nWidth
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the cap styles for the start, end, and dashes in a line drawn with this pen.
   ' =====================================================================================
   METHOD SetLineCap (BYVAL startCap AS LONG, BYVAL endCap AS LONG, BYVAL dashCap AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetPenLineCap197819(m_pPen, startCap, endCap, dashCap)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the start cap for this Pen object.
   ' =====================================================================================
   METHOD SetStartCap (BYVAL startCap AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetPenStartCap(m_pPen, startCap)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the end cap for this Pen object.
   ' =====================================================================================
   METHOD SetEndCap (BYVAL endCap AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetPenEndCap(m_pPen, endCap)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the dash cap style for this Pen object.
   ' =====================================================================================
   METHOD SetDashCap (BYVAL dashCap AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetPenDashCap197819(m_pPen, dashCap)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the start cap currently set for this Pen object.
   ' =====================================================================================
   METHOD GetStartCap () THREADSAFE AS LONG
      LOCAL startCap AS LONG
      m_hStatus = GdipGetPenStartCap(m_pPen, startCap)
      METHOD = startCap
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the end cap currently set for this Pen object.
   ' =====================================================================================
   METHOD GetEndCap () THREADSAFE AS LONG
      LOCAL endCap AS LONG
      m_hStatus = GdipGetPenEndCap(m_pPen, endCap)
      METHOD = endCap
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the dash cap style currently set for this Pen object.
   ' =====================================================================================
   METHOD GetDashCap () THREADSAFE AS LONG
      LOCAL dashCap AS LONG
      m_hStatus = GdipGetPenDashCap197819(m_pPen, dashCap)
      METHOD = dashCap
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the the line join for this Pen object.
   ' =====================================================================================
   METHOD SetLineJoin (BYVAL lineJoin AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetPenLineJoin(m_pPen, lineJoin)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the line join for this Pen object.
   ' =====================================================================================
   METHOD GetLineJoin () THREADSAFE AS LONG
      LOCAL lineJoin AS LONG
      m_hStatus = GdipGetPenLineJoin(m_pPen, lineJoin)
      METHOD = lineJoin
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the custom start cap currently set for this Pen object.
   ' =====================================================================================
   METHOD GetCustomStartCap (BYREF customCap AS IGdipCustomLineCap) THREADSAFE AS LONG
      IF ISNOTHING(customCap) THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      LOCAL pCustomLineCapPtr AS DWORD
      m_hStatus = GdipGetPenCustomStartCap(m_pPen, pCustomLineCapPtr)
      customCap.Ptr = pCustomLineCapPtr
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the custom start cap for this Pen object.
   ' =====================================================================================
   METHOD SetCustomStartCap (BYVAL pCustomLineCap AS IGdipCustomLineCap) THREADSAFE AS LONG
      m_hStatus = GdipSetPenCustomStartCap(m_pPen, pCustomLineCap.Ptr)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the custom end cap currently set for this Pen object.
   ' =====================================================================================
   METHOD GetCustomEndCap (BYREF customCap AS IGdipCustomLineCap) THREADSAFE AS LONG
      IF ISNOTHING(customCap) THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      LOCAL pCustomLineCapPtr AS DWORD
      m_hStatus = GdipGetPenCustomEndCap(m_pPen, pCustomLineCapPtr)
      customCap.Ptr = pCustomLineCapPtr
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the custom end cap for this Pen object.
   ' =====================================================================================
   METHOD SetCustomEndCap (BYVAL pCustomLineCap AS IGdipCustomLineCap) THREADSAFE AS LONG
      IF ISNOTHING(pCustomLineCap) THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      m_hStatus = GdipSetPenCustomEndCap(m_pPen, pCustomLineCap.Ptr)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the miter limit of this Pen object.
   ' =====================================================================================
   METHOD SetMiterLimit (BYVAL miterLimit AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipSetPenMiterLimit(m_pPen, miterLimit)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the miter length currently set for this Pen object.
   ' =====================================================================================
   METHOD GetMiterLimit () THREADSAFE AS SINGLE
      LOCAL miterLimit AS SINGLE
      m_hStatus = GdipGetPenMiterLimit(m_pPen, miterLimit)
      METHOD = miterLimit
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the alignment for this Pen object relative to the line.
   ' =====================================================================================
   METHOD SetAlignment (BYVAL penAlignment AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetPenMode(m_pPen, penAlignment)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the alignment for this Pen object relative to the line.
   ' =====================================================================================
   METHOD GetAlignment () THREADSAFE AS DWORD
      LOCAL penAlignment AS LONG
      m_hStatus = GdipGetPenMode(m_pPen, penAlignment)
      METHOD = penAlignment
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the world transformation of this Pen object.
   ' =====================================================================================
   METHOD SetTransform (BYVAL pMatrix AS IGdipMatrix) THREADSAFE AS LONG
      m_hStatus = GdipSetPenTransform(m_pPen, pMatrix.Ptr)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the world transformation of this Pen object.
   ' =====================================================================================
   METHOD GetTransform (BYREF pMatrix AS IGdipMatrix) THREADSAFE AS LONG
      IF ISNOTHING(pMatrix) THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      m_hStatus = GdipGetPenTransform(m_pPen, pMatrix.Ptr)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the world transformation matrix of this Pen object to the identity matrix.
   ' =====================================================================================
   METHOD ResetTransform () THREADSAFE AS LONG
      m_hStatus = GdipResetPenTransform(m_pPen)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates the world transformation matrix of this Pen object with the product of itself
   ' and another matrix. Default value for order is MatrixOrderPrepend (0).
   ' =====================================================================================
   METHOD MultiplyTransform (BYVAL pMatrix AS IGdipMatrix, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipMultiplyPenTransform(m_pPen, pMatrix.Ptr, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Translates the local geometric transformation of this Pen object by the specified dimensions.
   ' This method prepends the translation to the transformation.
   ' Default value for order is MatrixOrderPrepend (0).
   ' =====================================================================================
   METHOD TranslateTransform (BYVAL dx AS SINGLE, BYVAL dy AS SINGLE, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipTranslatePenTransform(m_pPen, dx, dy, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the Pen object's world transformation matrix equal to the product of itself and
   ' a scaling matrix. Default value for order is MatrixOrderPrepend (0).
   ' =====================================================================================
   METHOD ScaleTransform (BYVAL sx AS SINGLE, BYVAL sy AS SINGLE, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipScalePenTransform(m_pPen, sx, sy, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates the world transformation matrix of this Pen object with the product of itself
   ' and a rotation matrix. Default value for order is MatrixOrderPrepend (0).
   ' =====================================================================================
   METHOD RotateTransform (BYVAL angle AS SINGLE, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipRotatePenTransform(m_pPen, angle, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the type currently set for this Pen object.
   ' =====================================================================================
   METHOD GetPenType () THREADSAFE AS LONG
      LOCAL penType AS LONG
      m_hStatus = GdipGetPenFillType(m_pPen, penType)
      METHOD = penType
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the color for this Pen object.
   ' =====================================================================================
   METHOD SetColor (BYVAL colour AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipSetPenColor(m_pPen, colour)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the color for this Pen object.
   ' =====================================================================================
   METHOD SetBrush (BYVAL pBrush AS IGdipBrush) THREADSAFE AS LONG
      m_hStatus = GdipSetPenBrushFill(m_pPen, pBrush.Ptr)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the color currently set for this Pen object.
   ' =====================================================================================
   METHOD GetColor (BYREF argb AS DWORD) THREADSAFE AS LONG
      IF ME.GetPenType <> %PenTypeSolidColor THEN
         m_hStatus = %StatusWrongState
         EXIT METHOD
      END IF
      m_hStatus = GdipGetPenColor(m_pPen, argb)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the Brush object that is currently set for this Pen object.
   ' =====================================================================================
   METHOD GetBrush () THREADSAFE AS IGdipBrush
      LOCAL pBrush AS IGdipBrush
      LOCAL pBrushPtr AS DWORD
      pBrush = CLASS "CGdipBrush"
      IF ISNOTHING(pBrush) THEN EXIT METHOD
      m_hStatus = GdipGetPenBrushFill(m_pPen, pBrushPtr)
      pBrush.Ptr = pBrushPtr
      METHOD = pBrush
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the dash style currently set for this Pen object.
   ' =====================================================================================
   METHOD GetDashStyle () THREADSAFE AS LONG
      LOCAL dashStyle AS LONG
      m_hStatus = GdipGetPenDashStyle(m_pPen, dashStyle)
      METHOD = dashStyle
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the dash style for this Pen object.
   ' =====================================================================================
   METHOD SetDashStyle (BYVAL dashStyle AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetPenDashStyle(m_pPen, dashStyle)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the distance from the start of the line to the start of the first space in a
   ' dashed line.
   ' =====================================================================================
   METHOD GetDashOffset () THREADSAFE AS SINGLE
      LOCAL dashOffset AS SINGLE
      m_hStatus = GdipGetPenDashOffset(m_pPen, dashOffset)
      METHOD = dashOffset
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets an array of custom dashes and spaces for this Pen object.
   ' =====================================================================================
   METHOD SetDashOffset (BYVAL dashOffset AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipSetPenDashOffset(m_pPen, dashOffset)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets an array of custom dashes and spaces for this Pen object.
   ' =====================================================================================
   METHOD SetDashPattern (BYREF dashArray AS SINGLE, BYVAL nCount AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetPenDashArray(m_pPen, dashArray, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of elements in a dash pattern array.
   ' =====================================================================================
   METHOD GetDashPatternCount () THREADSAFE AS LONG
      LOCAL nCount AS LONG
      m_hStatus = GdipGetPenDashCount(m_pPen, nCount)
      METHOD = nCount
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets an array of custom dashes and spaces currently set for this Pen object.
   ' =====================================================================================
   METHOD GetDashPattern (BYREF dashArray AS SINGLE, BYVAL nCount AS LONG) THREADSAFE AS LONG
      IF VARPTR(dashArray) = 0 OR nCount <= 0 THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      m_hStatus = GdipGetPenDashArray(m_pPen, dashArray, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the compound array for this Pen object.
   ' =====================================================================================
   METHOD SetCompoundArray (BYREF compoundArray AS SINGLE, BYVAL nCount AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetPenCompoundArray(m_pPen, compoundArray, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of elements in a dash pattern array.
   ' =====================================================================================
   METHOD GetCompoundArrayCount () THREADSAFE AS LONG
      LOCAL nCount AS LONG
      m_hStatus = GdipGetPenCompoundCount(m_pPen, nCount)
      METHOD = nCount
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets an array of custom dashes and spaces currently set for this Pen object.
   ' =====================================================================================
   METHOD GetCompoundArray (BYREF compoundArray AS SINGLE, BYVAL nCount AS LONG) THREADSAFE AS LONG
      IF VARPTR(compoundArray) = 0 OR nCount <= 0 THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      m_hStatus = GdipGetPenCompoundArray(m_pPen, compoundArray, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
