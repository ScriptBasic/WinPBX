' ########################################################################################
' Microsoft Windows
' File: CGdipMatrix.inc
' Contents: GDI+ matrix class.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CGDIPMATRIX_INC = 1

' ########################################################################################
' CGdipMatrix Class
' ########################################################################################
CLASS CGdipMatrix

   INSTANCE m_hStatus AS LONG
   INSTANCE m_pMatrix AS DWORD

   ' =====================================================================================
   ' Cleanup
   ' =====================================================================================
   CLASS METHOD Destroy
      IF m_pMatrix THEN GdipDeleteMatrix(m_pMatrix)
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' IGdipMatrix interface.
   ' #####################################################################################
   INTERFACE IGdipMatrix : INHERIT IAutomation

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a pointer to the Brush object.
   ' =====================================================================================
   PROPERTY GET Ptr () THREADSAFE AS DWORD
      PROPERTY = m_pMatrix
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the Brush object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      IF m_pMatrix THEN GdipDeleteMatrix(m_pMatrix)
      m_pMatrix = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new Matrix object based on this Matrix object.
   ' =====================================================================================
   METHOD Clone () THREADSAFE AS IGdipMatrix
      LOCAL pCloneMatrix AS IGdipMatrix
      LOCAL pCloneMatrixPtr AS DWORD
      m_hStatus = GdipCloneMatrix(m_pMatrix, pCloneMatrixPtr)
      pCloneMatrix = CLASS "CGdipMatrix"
      pCloneMatrix.Ptr = pCloneMatrixPtr
      METHOD = pCloneMatrix
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates and initializes a Matrix object that represents the identity matrix.
   ' =====================================================================================
   METHOD Matrix () THREADSAFE AS LONG
      IF m_pMatrix THEN GdipDeleteMatrix(m_pMatrix)
      m_hStatus = GdipCreateMatrix(m_pMatrix)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates and initializes a Matrix object based on six numbers that define an affine transformation.
   ' =====================================================================================
   METHOD Matrix2 (BYVAL m11 AS SINGLE, BYVAL m12 AS SINGLE, BYVAL m21 AS SINGLE, BYVAL m22 AS SINGLE, BYVAL dx AS SINGLE, BYVAL dy AS SINGLE) THREADSAFE AS LONG
      IF m_pMatrix THEN GdipDeleteMatrix(m_pMatrix)
      m_hStatus = GdipCreateMatrix2(m11, m12, m21, m22, dx, dy, m_pMatrix)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Matrix object based on a rectangle and a point.
   ' =====================================================================================
   METHOD Matrix3 (BYREF rc AS RectF, BYREF dstplg AS PointF) THREADSAFE AS LONG
      IF m_pMatrix THEN GdipDeleteMatrix(m_pMatrix)
      m_hStatus = GdipCreateMatrix3(rc, dstplg, m_pMatrix)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Matrix object based on a rectangle and a point.
   ' =====================================================================================
   METHOD Matrix3I (BYREF rc AS RECT, BYREF dstplg AS POINT) THREADSAFE AS LONG
      IF m_pMatrix THEN GdipDeleteMatrix(m_pMatrix)
      m_hStatus = GdipCreateMatrix3I(rc, dstplg, m_pMatrix)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the elements of this matrix. The elements are placed in an array in the order
   ' m11, m12, m21, m22, m31, m32, where mij denotes the element in row i, column j.
   ' =====================================================================================
   METHOD GetElements (BYREF m AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipGetMatrixElements(m_pMatrix, m)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the elements of this matrix. The elements are placed in an array in the order
   ' m11, m12, m21, m22, m31, m32, where mij denotes the element in row i, column j.
   ' =====================================================================================
   METHOD SetElements (BYVAL m11 AS SINGLE, BYVAL m12 AS SINGLE, BYVAL m21 AS SINGLE, BYVAL m22 AS SINGLE, BYVAL dx AS SINGLE, BYVAL dy AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipSetMatrixElements(m_pMatrix, m11, m12, m21, m22, dx, dy)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the horizontal translation value of this matrix, which is the element in row 3, column 1.
   ' =====================================================================================
   METHOD OffsetX () THREADSAFE AS SINGLE
      DIM elements(0 TO 5) AS SINGLE
      IF ME.GetElements(elements(0)) = %StatusOK THEN
         METHOD = elements(4)
      ELSE
         METHOD = 0
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the vertical translation value of this matrix, which is the element in row 3, column 1.
   ' =====================================================================================
   METHOD OffsetY () THREADSAFE AS SINGLE
      DIM elements(0 TO 5) AS SINGLE
      IF ME.GetElements(elements(0)) = %StatusOK THEN
         METHOD = elements(5)
      ELSE
         METHOD = 0.0!
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this matrix with the elements of the identity matrix.
   ' =====================================================================================
   METHOD Reset () THREADSAFE AS LONG
      m_hStatus = GdipSetMatrixElements(m_pMatrix, 1.0!, 0.0!, 0.0!, 1.0!, 0.0!, 0.0!)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this matrix with the product of itself and another matrix.
   ' =====================================================================================
   METHOD Multiply (BYVAL pMatrix AS IGdipMatrix, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipMultiplyMatrix(m_pMatrix, pMatrix.Ptr, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this matrix with the product of itself and a translation matrix.
   ' =====================================================================================
   METHOD Translate (BYVAL offsetX AS SINGLE, BYVAL offsetY AS SINGLE, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipTranslateMatrix(m_pMatrix, offsetX, offsetY, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this matrix with the product of itself and a scaling matrix.
   ' =====================================================================================
   METHOD Scale (BYVAL scaleX AS SINGLE, BYVAL scaleY AS SINGLE, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipScaleMatrix(m_pMatrix, scaleX, scaleY, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this matrix with the product of itself and a rotation matrix.
   ' =====================================================================================
   METHOD Rotate (BYVAL angle AS SINGLE, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipRotateMatrix(m_pMatrix, angle, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this matrix with the product of itself and a matrix that represents rotation
   ' about a specified point.
   ' =====================================================================================
   METHOD RotateAt (BYVAL angle AS SINGLE, BYREF center AS PointF, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      IF order = %MatrixOrderPrepend THEN
         m_hStatus = GdipTranslateMatrix(m_pMatrix, center.X, center.Y, order)
         m_hStatus = GdipRotateMatrix(m_pMatrix, angle, order)
         m_hStatus = GdipTranslateMatrix(m_pMatrix, -center.X, -center.Y, order)
      ELSE
         m_hStatus = GdipTranslateMatrix(m_pMatrix, -center.X, -center.Y, order)
         m_hStatus = GdipRotateMatrix(m_pMatrix, angle, order)
         m_hStatus = GdipTranslateMatrix(m_pMatrix, center.X, center.Y, order)
      END IF
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this matrix with the product of itself and a shearing matrix.
   ' =====================================================================================
   METHOD Shear (BYVAL shearX AS SINGLE, BYVAL shearY AS SINGLE, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipShearMatrix(m_pMatrix, shearX, shearY, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' If the matrix is invertible, this function replaces its elements  with the elements of its inverse.
   ' =====================================================================================
   METHOD Invert () THREADSAFE AS LONG
      m_hStatus = GdipInvertMatrix(m_pMatrix)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Multiplies each point in an array by this matrix. Each point is treated as a row matrix.
   ' The multiplication is performed with the row matrix on the left and this matrix on the right.
   ' =====================================================================================
   METHOD TransformPoints (BYREF pts AS PointF, OPTIONAL BYVAL nCount AS LONG) THREADSAFE AS LONG
      IF nCount = 0 THEN nCount = 1
      m_hStatus = GdipTransformMatrixPoints(m_pMatrix, pts, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Multiplies each vector in an array by this matrix. The translation elements of this
   ' matrix (third row) are ignored. Each vector is treated as a row matrix. The multiplication
   ' is performed with the row matrix on the left and this matrix on the right.
   ' =====================================================================================
   METHOD TransformVectors (BYREF pts AS PointF, OPTIONAL BYVAL nCount AS LONG) THREADSAFE AS LONG
      IF nCount = 0 THEN nCount = 1
      m_hStatus = GdipVectorTransformMatrixPoints(m_pMatrix, pts, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Determines whether this matrix is invertible.
   ' =====================================================================================
   METHOD IsInvertible () THREADSAFE AS LONG
      LOCAL result AS LONG
      m_hStatus = GdipIsMatrixInvertible(m_pMatrix, result)
      METHOD = result
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Determines whether this matrix is the identity matrix.
   ' =====================================================================================
   METHOD IsIdentity () THREADSAFE AS LONG
      LOCAL result AS LONG
      m_hStatus = GdipIsMatrixIdentity(m_pMatrix, result)
      METHOD = result
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Determines whether the elements of this matrix are equal to the elements of another matrix.
   ' =====================================================================================
   METHOD Equals (BYVAL pMatrix AS IGdipMatrix) THREADSAFE AS LONG
      LOCAL result AS LONG
      m_hStatus = GdipIsMatrixEqual(m_pMatrix, pMatrix.Ptr, result)
      METHOD = result
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
