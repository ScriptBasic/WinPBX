' ########################################################################################
' Microsoft Windows
' File: CGdipImageAttributes.inc
' Contents: GDI+ image attributes class.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CGDIPIMAGEATTRIBUTES_INC = 1

' ########################################################################################
' CGdipImageAttributes Class
' ########################################################################################
CLASS CGdipImageAttributes

   INSTANCE m_hStatus AS LONG
   INSTANCE m_pImgAttr AS DWORD

   ' =====================================================================================
   ' Cleanup
   ' =====================================================================================
   CLASS METHOD Destroy
      IF m_pImgAttr THEN GdipDisposeImageAttributes(m_pImgAttr)
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' IGdipImageAttributes interface.
   ' #####################################################################################
   INTERFACE IGdipImageAttributes : INHERIT IAutomation

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
      PROPERTY = m_pImgAttr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the Brush object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      IF m_pImgAttr THEN GdipDisposeImageAttributes(m_pImgAttr)
      m_pImgAttr = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Creates an image attributes object
   ' =====================================================================================
   METHOD ImageAttributes () THREADSAFE AS LONG
      IF m_pImgAttr THEN GdipDisposeImageAttributes(m_pImgAttr)
      m_hStatus = GdipCreateImageAttributes(m_pImgAttr)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new ImageAttributes object based on this ImageAttributes object.
   ' =====================================================================================
   METHOD Clone () THREADSAFE AS IGdipImageAttributes
      LOCAL pCloneImgAttr AS IGdipImageAttributes
      LOCAL pCloneImgAttrPtr AS DWORD
      m_hStatus = GdipCloneImageAttributes(m_pImgAttr, pCloneImgAttrPtr)
      pCloneImgAttr = CLASS "CGdipImageAttributes"
      pCloneImgAttr.Ptr = pCloneImgAttrPtr
      METHOD = pCloneImgAttr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the color-adjustment matrix of a specified category to identity matrix.
   ' =====================================================================================
   METHOD SetToIdentity (OPTIONAL BYVAL nType AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetImageAttributesToIdentity(m_pImgAttr, nType)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Clears all color- and grayscale-adjustment settings for a specified category.
   ' =====================================================================================
   METHOD Reset (OPTIONAL BYVAL nType AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipResetImageAttributes(m_pImgAttr, nType)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the color-adjustment matrix for a specified category.
   ' =====================================================================================
   METHOD SetColorMatrix (BYREF ClrMatrix AS colorMatrix, OPTIONAL BYVAL nMode AS LONG, BYVAL nType AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetImageAttributesColorMatrix(m_pImgAttr, nType, %TRUE, ClrMatrix, BYVAL %NULL, nMode)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Clears the color-adjustment matrix for a specified category.
   ' =====================================================================================
   METHOD ClearColorMatrix (OPTIONAL BYVAL nType AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetImageAttributesColorMatrix(m_pImgAttr, nType, %FALSE, BYVAL %NULL, BYVAL %NULL, %ColorMatrixFlagsDefault)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the color-adjustment matrix and the grayscale-adjustment matrix for a specified category.
   ' =====================================================================================
   METHOD SetColorMatrices (BYVAL clrMatrix AS ColorMatrix, BYVAL grayMatrix AS ColorMatrix, OPTIONAL BYVAL nMode AS LONG, BYVAL nType AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetImageAttributesColorMatrix(m_pImgAttr, nType, %TRUE, clrMatrix, grayMatrix, nMode)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Clears the color-adjustment matrix and the grayscale-adjustment matrix for a specified category.
   ' =====================================================================================
   METHOD ClearColorMatrices (OPTIONAL BYVAL nType AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetImageAttributesColorMatrix(m_pImgAttr, nType, %FALSE, BYVAL %NULL, BYVAL %NULL, %ColorMatrixFlagsDefault)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the threshold (transparency range) for a specified category.
   ' =====================================================================================
   METHOD SetThreshold (BYVAL threshold AS SINGLE, OPTIONAL BYVAL nType AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetImageAttributesThreshold(m_pImgAttr, nType, %TRUE, threshold)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Clears the threshold value for a specified category.
   ' =====================================================================================
   METHOD ClearThreshold (OPTIONAL BYVAL nType AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetImageAttributesThreshold(m_pImgAttr, nType, %FALSE, 0.0!)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the gamma value for a specified category.
   ' =====================================================================================
   METHOD SetGamma (BYVAL gamma AS SINGLE, OPTIONAL BYVAL nType AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetImageAttributesGamma(m_pImgAttr, nType, %TRUE, gamma)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Disables gamma correction for a specified category.
   ' =====================================================================================
   METHOD ClearGamma (OPTIONAL BYVAL nType AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetImageAttributesGamma(m_pImgAttr, nType, %FALSE, 0.0!)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Turns off color adjustment for a specified category. You can call ClearNoOp to reinstate
   ' the color-adjustment settings that were in place before the call to SetNoOp.
   ' =====================================================================================
   METHOD SetNoOp (OPTIONAL BYVAL nType AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetImageAttributesNoOp(m_pImgAttr, nType, %TRUE)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Clears the NoOp setting for a specified category.
   ' =====================================================================================
   METHOD ClearNoOp (OPTIONAL BYVAL nType AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetImageAttributesNoOp(m_pImgAttr, nType, %FALSE)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the color key (transparency range) for a specified category.
   ' =====================================================================================
   METHOD SetColorKey (BYVAL colorLow AS DWORD, BYVAL colorHigh AS DWORD, OPTIONAL BYVAL nType AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetImageAttributesColorKeys(m_pImgAttr, nType, %TRUE, colorLow, colorHigh)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Clears the color key (transparency range) for a specified category.
   ' =====================================================================================
   METHOD ClearColorKey (OPTIONAL BYVAL nType AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetImageAttributesColorKeys(m_pImgAttr, nType, %FALSE, %NULL, %NULL)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the CMYK output channel for a specified category.
   ' =====================================================================================
   METHOD SetOutputChannel (BYVAL channelFlags AS LONG, OPTIONAL BYVAL nType AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetImageAttributesOutputChannel(m_pImgAttr, nType, %TRUE, channelFlags)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Clears the cyan-magenta-yellow-black (CMYK) output channel setting for a specified category.
   ' =====================================================================================
   METHOD ClearOutputChannel (OPTIONAL BYVAL nType AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetImageAttributesOutputChannel(m_pImgAttr, nType, %FALSE, %ColorChannelFlagsLast)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the output channel color-profile file for a specified category.
   ' =====================================================================================
   METHOD SetOutputChannelColorProfile (BYREF colorProfileFilename AS WSTRINGZ, OPTIONAL BYVAL nType AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetImageAttributesOutputChannelColorProfile(m_pImgAttr, nType, %TRUE, colorProfileFilename)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Clears the output channel color profile setting for a specified category.
   ' =====================================================================================
   METHOD ClearOutputChannelColorProfile (OPTIONAL BYVAL nType AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetImageAttributesOutputChannelColorProfile(m_pImgAttr, nType, %FALSE, BYVAL %NULL)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the color-remap table for a specified category.
   ' =====================================================================================
   METHOD SetRemapTable (BYVAL mapSize AS DWORD, BYREF map AS GDIP_COLORMAP, OPTIONAL BYVAL nType AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetImageAttributesRemapTable(m_pImgAttr, nType, %TRUE, mapSize, map)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Clears the color-remap table for a specified category.
   ' =====================================================================================
   METHOD ClearRemapTable (OPTIONAL BYVAL nType AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetImageAttributesRemapTable(m_pImgAttr, nType, %FALSE, 0, BYVAL %NULL)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the color remap table for the brush category.
   ' =====================================================================================
   METHOD SetBrushRemapTable (BYVAL mapSize AS DWORD, BYREF map AS ColorMap) THREADSAFE AS LONG
      m_hStatus = ME.SetRemapTable(mapSize, map, %ColorAdjustTypeBrush)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Clears the brush color-remap table of this ImageAttributes object.
   ' =====================================================================================
   METHOD ClearBrushRemapTable () THREADSAFE AS LONG
      m_hStatus = ME.ClearRemapTable(%ColorAdjustTypeBrush)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the wrap mode of this ImageAttributes object.
   ' =====================================================================================
   METHOD SetWrapMode (BYVAL nWrap AS LONG, OPTIONAL BYVAL colour AS DWORD, BYVAL clamp AS LONG) THREADSAFE AS LONG
      IF colour = 0 THEN colour = %ARGB_Black
      m_hStatus = GdipSetImageAttributesWrapMode(m_pImgAttr, nWrap, colour, clamp)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adjusts the colors in a palette according to the adjustment settings of a specified category.
   ' =====================================================================================
   METHOD GetAdjustedPalette (BYREF clrPalette AS ColorPalette, BYVAL colorAdjustType AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipGetImageAttributesAdjustedPalette(m_pImgAttr, clrPalette, colorAdjustType)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
