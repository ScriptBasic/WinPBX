' ########################################################################################
' Microsoft Windows
' File: CGdipBrush.inc
' Contents: GDI+ Brush class.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CGDIPBRUSH_INC = 1

' ########################################################################################
' CGdipBrush Class
' ########################################################################################
CLASS CGdipBrush

   INSTANCE m_hStatus AS LONG
   INSTANCE m_pBrush AS DWORD

   ' =====================================================================================
   ' Cleanup
   ' =====================================================================================
   CLASS METHOD Destroy
      IF m_pBrush THEN GdipDeleteBrush(m_pBrush)
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' IGdipBrush interface.
   ' #####################################################################################
   INTERFACE IGdipBrush : INHERIT IAutomation

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
      PROPERTY = m_pBrush
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the Brush object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      IF m_pBrush THEN GdipDeleteBrush(m_pBrush)
      m_pBrush = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new Brush object based on this Brush object.
   ' =====================================================================================
   METHOD Clone () THREADSAFE AS IGdipBrush
      LOCAL pCloneBrush AS IGdipBrush
      LOCAL pCloneBrushPtr AS DWORD
      m_hStatus = GdipCloneBrush(m_pBrush, pCloneBrushPtr)
      pCloneBrush = CLASS "CGdipBrush"
      IF ISNOTHING(pCloneBrush) THEN EXIT METHOD
      pCloneBrush.Ptr = pCloneBrushPtr
      METHOD = pCloneBrush
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the type of this brush.
   ' =====================================================================================
   METHOD GetType () THREADSAFE AS LONG
      LOCAL brushType AS LONG
      METHOD = -1
      m_hStatus = GdipGetBrushType(m_pBrush, brushType)
      METHOD = brushType
   END METHOD
   ' =====================================================================================

   END INTERFACE

   ' #####################################################################################
   ' IGdipSolidBrush interface.
   ' Inherits from IGdipBrush.
   ' #####################################################################################
   INTERFACE IGdipSolidBrush : INHERIT IAutomation

   ' *** IGdipBrush methods ***

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
      PROPERTY = m_pBrush
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the Brush object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      LOCAL pBrush AS IGdipBrush
      pBrush = ME
      pBrush.Ptr = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new Brush object based on this Brush object.
   ' =====================================================================================
   METHOD Clone () THREADSAFE AS IGdipBrush
      LOCAL pBrush AS IGdipBrush
      pBrush = ME
      METHOD = pBrush.Clone
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the type of this brush.
   ' =====================================================================================
   METHOD GetType () THREADSAFE AS LONG
      LOCAL pBrush AS IGdipBrush
      pBrush = ME
      METHOD = pBrush.GetType
   END METHOD
   ' =====================================================================================

   ' *** IGdipSolidBrush methods ***

   ' =====================================================================================
   ' Creates a solid brush.
   ' =====================================================================================
   METHOD SolidBrush (BYVAL colour AS DWORD) THREADSAFE AS LONG
      IF m_pBrush THEN GdipDeleteBrush(m_pBrush)
      m_hStatus = GdipCreateSolidFill(colour, m_pBrush)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the color of this solid brush.
   ' =====================================================================================
   METHOD GetColor (BYREF colour AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipGetSolidFillColor(m_pBrush, colour)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the color of this solid brush.
   ' =====================================================================================
   METHOD SetColor (BYVAL colour AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipSetSolidFillColor(m_pBrush, colour)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   END INTERFACE

   ' #####################################################################################
   ' IGdipTextureBrush interface.
   ' Inherits from IGdipBrush.
   ' #####################################################################################
   INTERFACE IGdipTextureBrush : INHERIT IAutomation

   ' *** IGdipBrush methods ***

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
      PROPERTY = m_pBrush
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the Brush object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      LOCAL pBrush AS IGdipBrush
      pBrush = ME
      pBrush.Ptr = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new Brush object based on this Brush object.
   ' =====================================================================================
   METHOD Clone () THREADSAFE AS IGdipBrush
      LOCAL pBrush AS IGdipBrush
      pBrush = ME
      METHOD = pBrush.Clone
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the type of this brush.
   ' =====================================================================================
   METHOD GetType () THREADSAFE AS LONG
      LOCAL pBrush AS IGdipBrush
      pBrush = ME
      METHOD = pBrush.GetType
   END METHOD
   ' =====================================================================================

   ' *** IGdipTextureBrush methods ***

   ' =====================================================================================
   ' Creates a TextureBrush object based on an image and a wrap mode. The size of the brush
   ' defaults to the size of the image, so the entire image is used by the brush.
   ' =====================================================================================
   METHOD TextureBrush (BYVAL pImage AS IGdipImage, OPTIONAL BYVAL wrapMode AS LONG) THREADSAFE AS LONG
      IF m_pBrush THEN GdipDeleteBrush(m_pBrush)
      m_hStatus = GdipCreateTexture(pImage.Ptr, wrapmode, m_pBrush)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a TextureBrush object based on an image, a wrap mode, and a defining set of coordinates.
   ' // When creating a texture brush from a metafile image, the dstRect is used to specify
   ' // the size that the metafile image should be rendered at in the device units of the
   ' // destination graphics. It is NOT used to crop the metafile image, so only the width
   ' // and height values matter for metafiles.
   ' =====================================================================================
   METHOD TextureBrushRect (BYVAL pImage AS IGdipImage, BYVAL wrapMode AS LONG, BYREF dstRect AS RectF) THREADSAFE AS LONG
      IF m_pBrush THEN GdipDeleteBrush(m_pBrush)
      m_hStatus = GdipCreateTexture2(pImage.Ptr, wrapmode, dstRect.x, dstRect.y, dstRect.Width, dstRect.Height, m_pBrush)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a TextureBrush object based on an image, a defining set of coordinates, and
   ' a set of image properties.
   ' =====================================================================================
   METHOD TextureBrushIA (BYVAL pImage AS IGdipImage, BYREF dstRect AS RectF, OPTIONAL BYVAL pImageAttributes AS IGdipImageAttributes) THREADSAFE AS LONG
      IF m_pBrush THEN GdipDeleteBrush(m_pBrush)
      m_hStatus = GdipCreateTextureIA(pImage.Ptr, IIF(ISOBJECT(pImageAttributes), pImageAttributes.Ptr, %NULL), _
                  dstRect.x, dstRect.y, dstRect.Width, dstRect.Height, m_pBrush)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a TextureBrush object based on an image, a wrap mode, and a defining set of coordinates.
   ' =====================================================================================
   METHOD TextureBrush2 (BYVAL pImage AS IGdipImage, BYVAL wrapMode AS LONG, BYVAL dstX AS SINGLE, BYVAL dstY AS SINGLE, BYVAL dstWidth AS SINGLE, BYVAL dstHeight AS SINGLE) THREADSAFE AS LONG
      IF m_pBrush THEN GdipDeleteBrush(m_pBrush)
      m_hStatus = GdipCreateTexture2(pImage.Ptr, wrapmode, dstX, dstY, dstWidth, dstHeight, m_pBrush)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the transformation matrix of this texture brush.
   ' =====================================================================================
   METHOD SetTransform (BYVAL pMatrix AS IGdipMatrix) THREADSAFE AS LONG
      m_hStatus = GdipSetTextureTransform(m_pBrush, pMatrix.Ptr)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the transformation matrix of this texture brush.
   ' =====================================================================================
   METHOD GetTransform (BYREF pMatrix AS IGdipMatrix) THREADSAFE AS LONG
      IF ISNOTHING(pMatrix) THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      m_hStatus = GdipGetTextureTransform(m_pBrush, pMatrix.Ptr)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the transformation matrix of this texture brush.
   ' =====================================================================================
   METHOD ResetTransform () THREADSAFE AS LONG
      m_hStatus = GdipResetTextureTransform(m_pBrush)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this brush's transformation matrix with the product of itself and another matrix.
   ' =====================================================================================
   METHOD MultiplyTransform (BYVAL pMatrix AS IGdipMatrix, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipMultiplyTextureTransform(m_pBrush, pMatrix.Ptr, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this brush's current transformation matrix with the product of itself and a
   ' translation matrix.
   ' =====================================================================================
   METHOD TranslateTransform (BYVAL dx AS SINGLE, BYVAL dy AS SINGLE, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipTranslateTextureTransform(m_pBrush, dx, dy, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this texture brush's current transformation matrix with the product of itself
   ' and a scaling matrix.
   ' =====================================================================================
   METHOD ScaleTransform (BYVAL sx AS SINGLE, BYVAL sy AS SINGLE, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipScaleTextureTransform(m_pBrush, sx, sy, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Resets the transformation matrix of this texture brush to the identity matrix. This
   ' means that no transformation takes place.
   ' =====================================================================================
   METHOD RotateTransform (BYVAL angle AS SINGLE, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipRotateTextureTransform(m_pBrush, angle, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the wrap mode of this texture brush.
   ' =====================================================================================
   METHOD SetWrapMode (BYVAL wrapMode AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetTextureWrapMode(m_pBrush, wrapMode)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the wrap mode currently set for this texture brush.
   ' =====================================================================================
   METHOD GetWrapMode () THREADSAFE AS LONG
      LOCAL wrapMode AS LONG
      m_hStatus = GdipGetTextureWrapMode(m_pBrush, wrapMode)
      METHOD = wrapMode
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a pointer to the Image object that is defined by this texture brush.
   ' =====================================================================================
   METHOD GetImage ()  THREADSAFE AS IGdipImage
      LOCAL pImage AS IGdipImage
      pImage = CLASS "CGdipImage"
      IF ISNOTHING(pImage) THEN EXIT METHOD
      LOCAL pImagePtr AS DWORD
      m_hStatus = GdipGetTextureImage(m_pBrush, pImagePtr)
      pImage.Ptr = pImagePtr
      METHOD = pImage
   END METHOD
   ' =====================================================================================

   END INTERFACE

   ' #####################################################################################
   ' IGdipLinearGradientBrush interface.
   ' Inherits from IGdipBrush.
   ' #####################################################################################
   INTERFACE IGdipLinearGradientBrush : INHERIT IAutomation

   ' *** IGdipBrush methods ***

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
      PROPERTY = m_pBrush
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the Brush object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      LOCAL pBrush AS IGdipBrush
      pBrush = ME
      pBrush.Ptr = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new Brush object based on this Brush object.
   ' =====================================================================================
   METHOD Clone () THREADSAFE AS IGdipBrush
      LOCAL pBrush AS IGdipBrush
      pBrush = ME
      METHOD = pBrush.Clone
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the type of this brush.
   ' =====================================================================================
   METHOD GetType () THREADSAFE AS LONG
      LOCAL pBrush AS IGdipBrush
      pBrush = ME
      METHOD = pBrush.GetType
   END METHOD
   ' =====================================================================================

   ' *** IGdipLinearGradientBrush methods ***

   ' =====================================================================================
   ' Creates a LinearGradientBrush object from a set of boundary points and boundary colors.
   ' =====================================================================================
   METHOD LinearGradientBrush (BYREF point1 AS PointF, BYREF point2 AS PointF, BYVAL color1 AS DWORD, BYVAL color2 AS DWORD) THREADSAFE AS LONG
      IF m_pBrush THEN GdipDeleteBrush(m_pBrush)
      m_hStatus = GdipCreateLineBrush(point1, point2, color1, color2, %WrapModeTile, m_pBrush)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a LinearGradientBrush object from a set of boundary points and boundary colors.
   ' =====================================================================================
   METHOD LinearGradientBrushFromRect (BYREF rc AS RectF, BYVAL color1 AS DWORD, BYVAL color2 AS DWORD, BYVAL nMode AS LONG) THREADSAFE AS LONG
      IF m_pBrush THEN GdipDeleteBrush(m_pBrush)
      m_hStatus = GdipCreateLineBrushFromRect(rc, color1, color2, nMode, %WrapModeTile, m_pBrush)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a LinearGradientBrush object from a set of boundary points and boundary colors.
   ' =====================================================================================
   METHOD LinearBrushFromRectWithAngle (BYREF rc AS RectF, BYVAL color1 AS DWORD, BYVAL color2 AS DWORD, BYVAL angle AS SINGLE, OPTIONAL BYVAL isAngleScalable AS LONG) THREADSAFE AS LONG
      IF m_pBrush THEN GdipDeleteBrush(m_pBrush)
      m_hStatus = GdipCreateLineBrushFromRectWithAngle(rc, color1, color2, angle, isAngleScalable, %WrapModeTile, m_pBrush)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the the starting color and ending color of this linear gradient brush.
   ' =====================================================================================
   METHOD SetLinearColors (BYVAL color1 AS DWORD, BYVAL color2 AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipSetLineColors(m_pBrush, color1, color2)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the the starting color and ending color of this linear gradient brush.
   ' =====================================================================================
   METHOD GetLinearColors (BYREF colors AS DWORD) THREADSAFE AS LONG
      IF VARPTR(colors) = 0 THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      m_hStatus = GdipGetLineColors(m_pBrush, colors)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the rectangle that defines the boundaries of the gradient.
   ' =====================================================================================
   METHOD GetRectangle (BYREF rc AS RectF) THREADSAFE AS LONG
      m_hStatus = GdipGetLineRect(m_pBrush, rc)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Specifies whether gamma correction is enabled for this linear gradient brush.
   ' =====================================================================================
   METHOD SetGammaCorrection (BYVAL useGammaCorrection AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetLineGammaCorrection(m_pBrush, useGammaCorrection)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Determines whether gamma correction is enabled for this LinearGradientBrush object.
   ' =====================================================================================
   METHOD GetGammaCorrection () THREADSAFE AS LONG
      LOCAL useGammaCorrection AS LONG
      m_hStatus = GdipGetLineGammaCorrection(m_pBrush, useGammaCorrection)
      METHOD = useGammaCorrection
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of blend factors currently set for this LinearGradientBrush object.
   ' =====================================================================================
   METHOD GetBlendCount () THREADSAFE AS LONG
      LOCAL nCount AS LONG
      m_hStatus = GdipGetLineBlendCount(m_pBrush, nCount)
      METHOD = nCount
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the blend factors and the blend positions of this linear gradient brush to
   ' create a custom blend.
   ' =====================================================================================
   METHOD SetBlend (BYREF blendFactors AS SINGLE, BYREF blendPositions AS SINGLE, BYVAL nCount AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetLineBlend(m_pBrush, blendFactors, blendPositions, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the blend factors and their corresponding blend positions from a LinearGradientBrush object.
   ' =====================================================================================
   METHOD GetBlend (BYREF blendFactors AS SINGLE, BYREF blendPositions AS SINGLE, BYVAL nCount AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipGetLineBlend(m_pBrush, blendFactors, blendPositions, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of preset colors currently specified for this path gradient brush.
   ' =====================================================================================
   METHOD GetInterpolationColorCount () THREADSAFE AS LONG
      LOCAL nCount AS LONG
      m_hStatus = GdipGetLinePresetBlendCount(m_pBrush, nCount)
      METHOD = nCount
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the colors to be interpolated for this linear gradient brush and their
   ' corresponding blend positions.
   ' =====================================================================================
   METHOD SetInterpolationColors (BYREF presetColors AS DWORD, BYREF blendPositions AS SINGLE, BYVAL nCount AS LONG) THREADSAFE AS LONG
      IF VARPTR(presetColors) = 0 OR nCount <= 0 THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      m_hStatus = GdipSetLinePresetBlend(m_pBrush, presetColors, blendPositions, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the colors currently set to be interpolated for this linear gradient brush and
   ' their corresponding blend positions.
   ' =====================================================================================
   METHOD GetInterpolationColors (BYREF presetColors AS DWORD, BYREF blendPositions AS SINGLE, BYVAL nCount AS LONG) THREADSAFE AS LONG
      IF VARPTR(presetColors) = 0 OR nCount <= 0 THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      m_hStatus = GdipGetLinePresetBlend(m_pBrush, presetColors, blendPositions, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the blend shape of this linear gradient brush to create a custom blend based on
   ' a bell-shaped curve. Default scale: 1.0!
   ' =====================================================================================
   METHOD SetBlendBellShape (BYVAL rFocus AS SINGLE, OPTIONAL BYVAL vScale AS VARIANT) THREADSAFE AS LONG
      LOCAL rScale AS SINGLE
      IF ISMISSING(vScale) THEN rScale = 1.0 ELSE rScale = VARIANT#(vScale)
      m_hStatus = GdipSetLineSigmaBlend(m_pBrush, rFocus, rScale)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the blend shape of this linear gradient brush to create a custom blend based on
   ' a triangular shape. Default scale: 1.0!
   ' =====================================================================================
   METHOD SetBlendTriangularShape (BYVAL rFocus AS SINGLE, OPTIONAL BYVAL vScale AS VARIANT) THREADSAFE AS LONG
      LOCAL rScale AS SINGLE
      IF ISMISSING(vScale) THEN rScale = 1.0 ELSE rScale = VARIANT#(vScale)
      m_hStatus = GdipSetLineLinearBlend(m_pBrush, rFocus, rScale)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the transformation matrix of this linear gradient brush.
   ' =====================================================================================
   METHOD SetTransform (BYVAL pMatrix AS IGdipMatrix) THREADSAFE AS LONG
      m_hStatus = GdipSetLineTransform(m_pBrush, pMatrix.Ptr)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the transformation matrix of this linear gradient brush.
   ' =====================================================================================
   METHOD GetTransform (BYREF pMatrix AS IGdipMatrix) THREADSAFE AS LONG
      IF ISNOTHING(pMatrix) THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      m_hStatus = GdipGetLineTransform(m_pBrush, pMatrix.Ptr)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Resets the transformation matrix of this linear gradient brush to the identity matrix.
   ' This means that no transformation takes place.
   ' =====================================================================================
   METHOD ResetTransform () THREADSAFE AS LONG
      m_hStatus = GdipResetLineTransform(m_pBrush)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this brush's transformation matrix with the product of itself and another matrix.
   ' =====================================================================================
   METHOD MultiplyTransform (BYVAL pMatrix AS IGdipMatrix, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipMultiplyLineTransform(m_pBrush, pMatrix.Ptr, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this brush's current transformation matrix with the product of itself and a
   ' translation matrix.
   ' =====================================================================================
   METHOD TranslateTransform (BYVAL dx AS SINGLE, BYVAL dy AS SINGLE, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipTranslateLineTransform(m_pBrush, dx, dy, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this brush's current transformation matrix with the product of itself and a
   ' scaling matrix.
   ' =====================================================================================
   METHOD ScaleTransform (BYVAL sx AS SINGLE, BYVAL sy AS SINGLE, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipScaleLineTransform(m_pBrush, sx, sy, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this brush's current transformation matrix with the product of itself and a
   ' rotation matrix.
   ' =====================================================================================
   METHOD RotateTransform (BYVAL angle AS SINGLE, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipRotateLineTransform(m_pBrush, angle, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the transformation matrix of this linear gradient brush.
   ' =====================================================================================
   METHOD SetWrapMode (BYVAL wrapMode AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetLineWrapMode(m_pBrush, wrapMode)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the transformation matrix of this linear gradient brush.
   ' =====================================================================================
   METHOD GetWrapMode () THREADSAFE AS LONG
      LOCAL wrapMode AS LONG
      m_hStatus = GdipGetLineWrapMode(m_pBrush, wrapMode)
      METHOD = wrapMode
   END METHOD
   ' =====================================================================================

   END INTERFACE

   ' #####################################################################################
   ' IGdipPathGradientBrush interface.
   ' Inherits from IGdipBrush.
   ' #####################################################################################
   INTERFACE IGdipPathGradientBrush : INHERIT IAutomation

   ' *** IGdipBrush methods ***

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
      PROPERTY = m_pBrush
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the Brush object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      LOCAL pBrush AS IGdipBrush
      pBrush = ME
      pBrush.Ptr = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new Brush object based on this Brush object.
   ' =====================================================================================
   METHOD Clone () THREADSAFE AS IGdipBrush
      LOCAL pBrush AS IGdipBrush
      pBrush = ME
      METHOD = pBrush.Clone
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the type of this brush.
   ' =====================================================================================
   METHOD GetType () THREADSAFE AS LONG
      LOCAL pBrush AS IGdipBrush
      pBrush = ME
      METHOD = pBrush.GetType
   END METHOD
   ' =====================================================================================

   ' *** IGdipPathGradientBrush methods ***

   ' =====================================================================================
   ' Creates a PathGradient object.
   ' =====================================================================================
   METHOD PathGradientBrush (BYREF pts AS PointF, BYVAL nCount AS LONG, OPTIONAL BYVAL wrapMode AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipCreatePathGradient(pts, nCount, wrapMode, m_pBrush)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a PathGradient object.
   ' =====================================================================================
   METHOD PathGradientBrushFromPath (BYVAL pPath AS IGdipGraphicsPath) THREADSAFE AS LONG
      m_hStatus = GdipCreatePathGradientFromPath(pPath.Ptr, m_pBrush)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the color of the center point of this path gradient brush.
   ' =====================================================================================
   METHOD GetCenterColor (BYREF colour AS DWORD) THREADSAFE AS LONG
      IF VARPTR(colour) = 0 THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      m_hStatus = GdipGetPathGradientCenterColor(m_pBrush, colour)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the color of the center point of this path gradient brush.
   ' =====================================================================================
   METHOD SetCenterColor (BYVAL colour AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipSetPathGradientCenterColor(m_pBrush, colour)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of points in the array of points that defines this brush's boundary path.
   ' =====================================================================================
   METHOD GetPointCount () THREADSAFE AS LONG
      LOCAL nCount AS LONG
      m_hStatus = GdipGetPathGradientPointCount(m_pBrush, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of colors that have been specified for the boundary path of this path
   ' gradient brush.
   ' =====================================================================================
   METHOD GetSurroundColorCount () THREADSAFE AS LONG
      LOCAL nCount AS LONG
      m_hStatus = GdipGetPathGradientSurroundColorCount(m_pBrush, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the surround colors currently specified for this path gradient brush.
   ' =====================================================================================
   METHOD GetSurroundColors (BYREF colors AS DWORD, BYREF nCount AS LONG) THREADSAFE AS LONG
      IF VARPTR(colors) = 0 THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      LOCAL nCount1 AS LONG
      m_hStatus = GdipGetPathGradientSurroundColorCount(m_pBrush, nCount1)
      IF m_hStatus <> %StatusOK THEN
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      IF nCount < nCount1 OR nCount1 <= 0 THEN
         METHOD = %StatusInsufficientBuffer
         EXIT METHOD
      END IF
      m_hStatus = GdipGetPathGradientSurroundColorsWithCount(m_pBrush, colors, nCount1)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the surround colors currently specified for this path gradient brush.
   ' =====================================================================================
   METHOD SetSurroundColors (BYREF colors AS DWORD, BYREF nCount AS LONG) THREADSAFE AS LONG
      IF VARPTR(colors) = 0 THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      LOCAL nCount1 AS LONG
      nCount1 = ME.GetPointCount
      IF nCount > nCount1 OR nCount1 <= 0 THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      m_hStatus = GdipSetPathGradientSurroundColorsWithCount(m_pBrush, colors, nCount1)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Not implemented in Windows GDI+ version 1.0.
   ' =====================================================================================
   METHOD GetGraphicsPath (BYREF pPath AS IGdipGraphicsPath) THREADSAFE AS LONG
      IF ISNOTHING(pPath) THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      m_hStatus = GdipGetPathGradientPath(m_pBrush, pPath.Ptr)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Not implemented in Windows GDI+ version 1.0.
   ' =====================================================================================
   METHOD SetGraphicsPath (BYVAL pPath AS IGdipGraphicsPath) THREADSAFE AS LONG
      IF ISNOTHING(pPath) THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      m_hStatus = GdipGetPathGradientPath(m_pBrush, pPath.Ptr)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the center point of this path gradient brush.
   ' =====================================================================================
   METHOD GetCenterPoint (BYREF pt AS PointF) THREADSAFE AS LONG
      m_hStatus = GdipGetPathGradientCenterPoint(m_pBrush, pt)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the center point of this path gradient brush.
   ' =====================================================================================
   METHOD SetCenterPoint (BYREF pt AS PointF) THREADSAFE AS LONG
      m_hStatus = GdipSetPathGradientCenterPoint(m_pBrush, pt)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the smallest rectangle that encloses the boundary path of this path gradient brush.
   ' =====================================================================================
   METHOD GetRectangle (BYREF rc AS RectF) THREADSAFE AS LONG
      m_hStatus = GdipGetPathGradientRect(m_pBrush, rc)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Specifies whether gamma correction is enabled for this path gradient brush.
   ' =====================================================================================
   METHOD SetGammaCorrection (BYVAL useGammaCorrection AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetPathGradientGammaCorrection(m_pBrush, useGammaCorrection)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Specifies whether gamma correction is enabled for this path gradient brush.
   ' =====================================================================================
   METHOD GetGammaCorrection () THREADSAFE AS LONG
      LOCAL useGammaCorrection AS LONG
      m_hStatus = GdipGetPathGradientGammaCorrection(m_pBrush, useGammaCorrection)
      METHOD = useGammaCorrection
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of blend factors currently set for this path gradient brush.
   ' =====================================================================================
   METHOD GetBlendCount () THREADSAFE AS LONG
      LOCAL nCount AS LONG
      m_hStatus = GdipGetPathGradientBlendCount(m_pBrush, nCount)
      METHOD = nCount
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the blend factors and the corresponding blend positions currently set for this
   ' path gradient brush.
   ' =====================================================================================
   METHOD GetBlend (BYREF blendFactors AS SINGLE, BYREF blendPositions AS SINGLE, BYVAL nCount AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipGetPathGradientBlend(m_pBrush, blendFactors, blendPositions, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the blend factors and the corresponding blend positions currently set for this
   ' path gradient brush.
   ' =====================================================================================
   METHOD SetBlend (BYREF blendFactors AS SINGLE, BYREF blendPositions AS SINGLE, BYVAL nCount AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetPathGradientBlend(m_pBrush, blendFactors, blendPositions, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of preset colors currently specified for this path gradient brush.
   ' =====================================================================================
   METHOD GetInterpolationColorCount () THREADSAFE AS LONG
      LOCAL nCount AS LONG
      m_hStatus = GdipGetPathGradientPresetBlendCount(m_pBrush, nCount)
      METHOD = nCount
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the preset colors and the blend positions of this path gradient brush.
   ' =====================================================================================
   METHOD SetInterpolationColors (BYREF presetColors AS DWORD, BYREF blendPositions AS SINGLE, BYVAL nCount AS LONG) THREADSAFE AS LONG
      IF VARPTR(presetColors) = 0 OR nCount <= 0 THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      m_hStatus = GdipSetPathGradientPresetBlend(m_pBrush, presetColors, blendPositions, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the number of preset colors currently specified for this path gradient brush.
   ' =====================================================================================
   METHOD GetInterpolationColors (BYREF presetColors AS DWORD, BYREF blendPositions AS SINGLE, BYVAL nCount AS LONG) THREADSAFE AS LONG
      IF VARPTR(presetColors) = 0 OR nCount <= 0 THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      m_hStatus = GdipGetPathGradientPresetBlend(m_pBrush, presetColors, blendPositions, nCount)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the blend shape of this path gradient brush. Default scale: 1.0!
   ' =====================================================================================
   METHOD SetBlendBellShape (BYVAL rFocus AS SINGLE, OPTIONAL BYVAL vScale AS VARIANT) THREADSAFE AS LONG
      LOCAL rScale AS SINGLE
      IF ISMISSING(vScale) THEN rScale = 1.0 ELSE rScale = VARIANT#(vScale)
      m_hStatus = GdipSetPathGradientSigmaBlend(m_pBrush, rFocus, rScale)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the blend shape of this path gradient brush. Default scale: 1.0!
   ' =====================================================================================
   METHOD SetBlendTriangularShape (BYVAL rFocus AS SINGLE, OPTIONAL BYVAL vScale AS VARIANT) THREADSAFE AS LONG
      LOCAL rScale AS SINGLE
      IF ISMISSING(vScale) THEN rScale = 1.0 ELSE rScale = VARIANT#(vScale)
      m_hStatus = GdipSetPathGradientLinearBlend(m_pBrush, rFocus, rScale)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the transformation matrix of this texture brush.
   ' =====================================================================================
   METHOD GetTransform (BYREF pMatrix AS IGdipMatrix) THREADSAFE AS LONG
      IF ISNOTHING(pMatrix) THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      m_hStatus = GdipGetPathGradientTransform(m_pBrush, pMatrix.Ptr)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the transformation matrix of this path gradient brush.
   ' =====================================================================================
   METHOD SetTransform (BYVAL pMatrix AS IGdipMatrix) THREADSAFE AS LONG
      m_hStatus = GdipSetPathGradientTransform(m_pBrush, pMatrix.Ptr)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the transformation matrix of this path gradient brush.
   ' =====================================================================================
   METHOD ResetTransform () THREADSAFE AS LONG
      m_hStatus = GdipResetPathGradientTransform(m_pBrush)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this brush's transformation matrix with the product of itself and another matrix.
   ' =====================================================================================
   METHOD MultiplyTransform (BYVAL pMatrix AS IGdipMatrix, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipMultiplyPathGradientTransform(m_pBrush, pMatrix.Ptr, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this brush's current transformation matrix with the product of itself and a
   ' translation matrix.
   ' =====================================================================================
   METHOD TranslateTransform (BYVAL dx AS SINGLE, BYVAL dy AS SINGLE, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipTranslatePathGradientTransform(m_pBrush, dx, dy, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Updates this brush's current transformation matrix with the product of itself
   ' and a scaling matrix.
   ' =====================================================================================
   METHOD ScaleTransform (BYVAL sx AS SINGLE, BYVAL sy AS SINGLE, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipScalePathGradientTransform(m_pBrush, sx, sy, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Resets the transformation matrix of this brush to the identity matrix. This means
   ' that no transformation takes place.
   ' =====================================================================================
   METHOD RotateTransform (BYVAL angle AS SINGLE, OPTIONAL BYVAL order AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipRotatePathGradientTransform(m_pBrush, angle, order)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the focus scales of this path gradient brush.
   ' =====================================================================================
   METHOD GetFocusScales (BYREF xScale AS SINGLE, BYREF yScale AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipGetPathGradientFocusScales(m_pBrush, xScale, yScale)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the focus scales of this path gradient brush.
   ' =====================================================================================
   METHOD SetFocusScales (BYVAL xScale AS SINGLE, BYVAL yScale AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipSetPathGradientFocusScales(m_pBrush, xScale, yScale)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the wrap mode currently set for this path gradient brush.
   ' =====================================================================================
   METHOD GetWrapMode () THREADSAFE AS LONG
      LOCAL wrapMode AS LONG
      m_hStatus = GdipGetPathGradientWrapMode(m_pBrush, wrapMode)
      METHOD = wrapMode
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the wrap mode of this path gradient brush.
   ' =====================================================================================
   METHOD SetWrapMode (BYVAL wrapMode AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetPathGradientWrapMode(m_pBrush, wrapMode)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   END INTERFACE

   ' #####################################################################################
   ' IGdipHatchBrush interface.
   ' Inherits from IGdipBrush.
   ' #####################################################################################
   INTERFACE IGdipHatchBrush : INHERIT IAutomation

   ' *** IGdipBrush methods ***

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
      PROPERTY = m_pBrush
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the Brush object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      LOCAL pBrush AS IGdipBrush
      pBrush = ME
      pBrush.Ptr = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new Brush object based on this Brush object.
   ' =====================================================================================
   METHOD Clone () THREADSAFE AS IGdipBrush
      LOCAL pBrush AS IGdipBrush
      pBrush = ME
      METHOD = pBrush.Clone
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the type of this brush.
   ' =====================================================================================
   METHOD GetType () THREADSAFE AS LONG
      LOCAL pBrush AS IGdipBrush
      pBrush = ME
      METHOD = pBrush.GetType
   END METHOD
   ' =====================================================================================

   ' *** IGdipHatchBrush methods ***

   ' =====================================================================================
   ' Creates a HatchBrush object based on a hatch style, a foreground color, and a background color.
   ' =====================================================================================
   METHOD HatchBrush (BYVAL hatchStyle AS LONG, BYVAL foreColor AS DWORD, OPTIONAL BYVAL backColor AS DWORD) THREADSAFE AS LONG
      IF backColor = 0 THEN backColor = %ARGB_Black
      m_hStatus = GdipCreateHatchBrush(hatchStyle, foreColor, backColor, m_pBrush)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the hatch style of this hatch brush.
   ' =====================================================================================
   METHOD GetHatchStyle () THREADSAFE AS LONG
      LOCAL hatchStyle AS DWORD
      m_hStatus = GdipGetHatchStyle(m_pBrush, hatchStyle)
      METHOD = hatchStyle
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the foreground color of this hatch brush.
   ' =====================================================================================
   METHOD GetForegroundColor (BYREF colour AS DWORD) THREADSAFE AS LONG
      IF VARPTR(colour) = 0 THEN EXIT METHOD
      m_hStatus = GdipGetHatchForegroundColor(m_pBrush, colour)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the background color of this hatch brush.
   ' =====================================================================================
   METHOD GetBackgroundColor (BYREF colour AS DWORD) THREADSAFE AS LONG
      IF VARPTR(colour) = 0 THEN EXIT METHOD
      m_hStatus = GdipGetHatchBackgroundColor(m_pBrush, colour)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' ########################################################################################
