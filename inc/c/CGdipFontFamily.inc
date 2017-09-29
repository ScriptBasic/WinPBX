' ########################################################################################
' Microsoft Windows
' File: CGdipFontFamily.inc
' Contents: GDI+ Font Family class.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CGDIPFONTFAMILY_INC = 1

' ########################################################################################
' CGdipFontFamily Class
' ########################################################################################
CLASS CGdipFontFamily

   INSTANCE m_hStatus AS LONG
   INSTANCE m_pFontFamily AS DWORD

   ' =====================================================================================
   ' Cleanup
   ' =====================================================================================
   CLASS METHOD Destroy
      IF m_pFontFamily THEN GdipDeleteFontFamily(m_pFontFamily)
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   INTERFACE IGdipFontFamily : INHERIT IAutomation
   ' #####################################################################################

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
      PROPERTY = m_pFontFamily
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the Graphics object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      IF m_pFontFamily THEN GdipDeleteFontFamily(m_pFontFamily)
      m_pFontFamily = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a FontFamily object based on a specified font collection.
   ' =====================================================================================
   METHOD FromName (BYREF wszName AS WSTRINGZ, OPTIONAL BYVAL pFontCollection AS IGdipFontCollection) THREADSAFE AS LONG
      m_hStatus = GdipCreateFontFamilyFromName(wszName, IIF(ISOBJECT(pFontCollection), pFontCollection.Ptr, %NULL), m_pFontFamily)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a FontFamily object that specifies a generic sans serif typeface.
   ' =====================================================================================
   METHOD GenericSansSerif () THREADSAFE AS IGdipFontFamily
      LOCAL pFontFamily AS IGdipFontFamily
      LOCAL pFontFamilyPtr AS DWORD
      m_hStatus = GdipGetGenericFontFamilySansSerif(pFontFamilyPtr)
      pFontFamily = CLASS "CGdipFontFamily"
      IF ISNOTHING(pFontFamily) THEN EXIT METHOD
      pFontFamily.Ptr = pFontFamilyPtr
      METHOD = pFontFamily
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a FontFamily object that specifies a generic serif typeface.
   ' =====================================================================================
   METHOD GenericSerif () THREADSAFE AS IGdipFontFamily
      LOCAL pFontFamily AS IGdipFontFamily
      LOCAL pFontFamilyPtr AS DWORD
      m_hStatus = GdipGetGenericFontFamilySerif(pFontFamilyPtr)
      pFontFamily = CLASS "CGdipFontFamily"
      IF ISNOTHING(pFontFamily) THEN EXIT METHOD
      pFontFamily.Ptr = pFontFamilyPtr
      METHOD = pFontFamily
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a FontFamily object that specifies a generic monospace typeface.
   ' =====================================================================================
   METHOD GenericMonospace () THREADSAFE AS IGdipFontFamily
      LOCAL pFontFamily AS IGdipFontFamily
      LOCAL pFontFamilyPtr AS DWORD
      m_hStatus = GdipGetGenericFontFamilyMonospace(pFontFamilyPtr)
      pFontFamily = CLASS "CGdipFontFamily"
      IF ISNOTHING(pFontFamily) THEN EXIT METHOD
      pFontFamily.Ptr = pFontFamilyPtr
      METHOD = pFontFamily
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new FontFamily object based on this FontFamily object.
   ' =====================================================================================
   METHOD Clone () THREADSAFE AS IGdipFontFamily
      LOCAL pCloneFontFamily AS IGdipFontFamily
      LOCAL pCloneFontFamilyPtr AS DWORD
      m_hStatus = GdipCloneFontFamily(m_pFontFamily, pCloneFontFamilyPtr)
      pCloneFontFamily = CLASS "CGdipFontFamily"
      IF ISNOTHING(pCloneFontFamily) THEN EXIT METHOD
      pCloneFontFamily.Ptr = pCloneFontFamilyPtr
      METHOD = pCloneFontFamily
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the name of this font family.
   ' =====================================================================================
   METHOD GetFamilyName (BYREF wszName AS WSTRINGZ * %LF_FACESIZE, OPTIONAL BYVAL language AS WORD) THREADSAFE AS LONG
      m_hStatus = GdipGetFamilyName(m_pFontFamily, wszName, language)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Determines whether the specified style is available for this font family.
   ' =====================================================================================
   METHOD IsAvailable (BYVAL nStyle AS LONG) THREADSAFE AS LONG
      LOCAL StyleAvailable AS LONG
      m_hStatus = GdipIsStyleAvailable(m_pFontFamily, nStyle, StyleAvailable)
      METHOD = StyleAvailable
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size (commonly called em size or em height), in design units, of this font family.
   ' =====================================================================================
   METHOD GetEmHeight (BYVAL nStyle AS LONG) THREADSAFE AS WORD
      LOCAL EmHeight AS WORD
      m_hStatus = GdipGetEmHeight(m_pFontFamily, nStyle, EmHeight)
      METHOD = EmHeight
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the cell ascent, in design units, of this font family for the specified style
   ' or style combination.
   ' =====================================================================================
   METHOD GetCellAscent (BYVAL nStyle AS LONG) THREADSAFE AS WORD
      LOCAL CellAscent AS WORD
      m_hStatus = GdipGetCellAscent(m_pFontFamily, nStyle, CellAscent)
      METHOD = CellAscent
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the cell descent, in design units, of this font family for the specified style
   ' or style combination.
   ' =====================================================================================
   METHOD GetCellDescent (BYVAL nStyle AS LONG) THREADSAFE AS WORD
      LOCAL CellDescent AS WORD
      m_hStatus = GdipGetCellDescent(m_pFontFamily, nStyle, CellDescent)
      METHOD = CellDescent
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the line spacing, in design units, of this font family for the specified style
   ' or style combination. The line spacing is the vertical distance between the base
   ' lines of two consecutive lines of text.
   ' =====================================================================================
   METHOD GetLineSpacing (BYVAL nStyle AS LONG) THREADSAFE AS WORD
      LOCAL LineSpacing AS WORD
      m_hStatus = GdipGetLineSpacing(m_pFontFamily, nStyle, LineSpacing)
      METHOD = LineSpacing
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' ########################################################################################
