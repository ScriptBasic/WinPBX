' ########################################################################################
' Microsoft Windows
' File: CGdipFont.inc
' Contents: GDI+ Font class.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CGDIPFONT_INC = 1

' ########################################################################################
' CGdipFont Class
' ########################################################################################
CLASS CGdipFont

   INSTANCE m_hStatus AS LONG
   INSTANCE m_pFont AS DWORD

   ' =====================================================================================
   ' Cleanup
   ' =====================================================================================
   CLASS METHOD Destroy
      IF m_pFont THEN GdipDeleteFont(m_pFont)
   END METHOD
   ' =====================================================================================

   INTERFACE IGdipFont : INHERIT IAutomation

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
      PROPERTY = m_pFont
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the Graphics object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      IF m_pFont THEN GdipDeleteFont(m_pFont)
      m_pFont = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Font object based on the GDI font object that is currently selected into a
   ' specified device context. This constructor is provided for compatibility with GDI.
   ' =====================================================================================
   METHOD FromDC (BYVAL hdc AS DWORD) THREADSAFE AS LONG
      m_hStatus = GdipCreateFontFromDC(hdc, m_pFont)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Font object indirectly from a Windows Graphics Device Interface (GDI)
   ' logical font by using a handle to a GDI LOGFONT structure.
   ' =====================================================================================
   METHOD FromhFontA (BYVAL hdc AS DWORD, BYVAL hFont AS DWORD) THREADSAFE AS LONG
      LOCAL lfA AS LOGFONTA
      IF hFont THEN
         IF GetObjectA(hFont, SIZEOF(LOGFONTA), lfA) THEN
            m_hStatus = GdipCreateFontFromLogfontA(hdc, lfA, m_pFont)
         ELSE
            m_hStatus = GdipCreateFontFromDC(hdc, m_pFont)
         END IF
      ELSE
         m_hStatus = GdipCreateFontFromDC(hdc, m_pFont)
      END IF
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Font object indirectly from a Windows Graphics Device Interface (GDI)
   ' logical font by using a handle to a GDI LOGFONT structure.
   ' =====================================================================================
   METHOD FromhFontW (BYVAL hdc AS DWORD, BYVAL hFont AS DWORD) THREADSAFE AS LONG
      LOCAL lfW AS LOGFONTW
      IF hFont THEN
         IF GetObjectW(hFont, SIZEOF(LOGFONTW), lfW) THEN
            m_hStatus = GdipCreateFontFromLogfontW(hdc, lfW, m_pFont)
         ELSE
            m_hStatus = GdipCreateFontFromDC(hdc, m_pFont)
         END IF
      ELSE
         m_hStatus = GdipCreateFontFromDC(hdc, m_pFont)
      END IF
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Font object directly from a Windows Graphics Device Interface (GDI) logical
   ' font. The GDI logical font is a LOGFONTA structure, which is the one-byte character
   ' version of a logical font. This constructor is provided for compatibility with GDI.
   ' =====================================================================================
   METHOD FromLogFontA (BYVAL hdc AS DWORD, BYREF lfA AS LOGFONTA) THREADSAFE AS LONG
      IF VARPTR(lfA) THEN
         m_hStatus = GdipCreateFontFromLogfontA(hdc, lfA, m_pFont)
      ELSE
         m_hStatus = GdipCreateFontFromDC(hdc, m_pFont)
      END IF
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Font object directly from a Windows Graphics Device Interface (GDI) logical
   ' font. The GDI logical font is a LOGFONTW structure, which is the one-byte character
   ' version of a logical font. This constructor is provided for compatibility with GDI.
   ' =====================================================================================
   METHOD FromLogFontW (BYVAL hdc AS DWORD, BYREF lfW AS LOGFONTW) THREADSAFE AS LONG
      IF VARPTR(lfW) THEN
         m_hStatus = GdipCreateFontFromLogfontW(hdc, lfW, m_pFont)
      ELSE
         m_hStatus = GdipCreateFontFromDC(hdc, m_pFont)
      END IF
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Font object based on a FontFamily object, a size, a font style, and a unit of measurement.
   ' =====================================================================================
   METHOD FromFontFamily (BYVAL pFamily AS IGdipFontFamily, BYVAL emSize AS SINGLE, OPTIONAL BYVAL nStyle AS LONG, BYVAL unit AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipCreateFont(IIF(ISOBJECT(pFamily), pFamily.Ptr, %NULL), emSize, nStyle, unit, m_pFont)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Font object based on a font family, a size, a font style, a unit of
   ' measurement, and a FontCollection object.
   ' =====================================================================================
   METHOD FromFontFamilyName (BYREF familyName AS WSTRINGZ, BYVAL emSize AS SINGLE, OPTIONAL BYVAL nStyle AS LONG, BYVAL unit AS LONG, BYVAL pFontCollection AS IGdipFontCollection) THREADSAFE AS LONG
      LOCAL pFamily AS IGdipFontFamily
      pFamily = CLASS "CGdipFontFamily"
      IF ISNOTHING(pFamily) THEN EXIT METHOD
      m_hStatus = pFamily.FromName(familyName, pFontCollection)
      IF m_hStatus = %StatusOK THEN
         ME.FromFontFamily(pFamily, emSize, nStyle, unit)
      ELSE
         pFamily = pFamily.GenericSansSerif
         IF ISOBJECT(pFamily) THEN
            m_hStatus = ME.FromFontFamily(pFamily, emSize, nStyle, unit)
         END IF
      END IF
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The GetLogFontA method uses a LOGFONTA structure to get the attributes of this Font object.
   ' =====================================================================================
   METHOD GetLogFontA (BYVAL pGraphics AS IGdipGraphics, BYREF lfA AS LOGFONTA) THREADSAFE AS LONG
      m_hStatus = GdipGetLogFontA(m_pFont, IIF(ISOBJECT(pGraphics), pGraphics.Ptr, %NULL), lfA)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The GetLogFontW method uses a LOGFONTW structure to get the attributes of this Font object.
   ' =====================================================================================
   METHOD GetLogFontW (BYVAL pGraphics AS IGdipGraphics, BYREF lfW AS LOGFONTW) THREADSAFE AS LONG
      m_hStatus = GdipGetLogFontW(m_pFont, IIF(ISOBJECT(pGraphics), pGraphics.Ptr, %NULL), lfW)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new Font object based on this Font object.
   ' =====================================================================================
   METHOD Clone () THREADSAFE AS IGdipFont
      LOCAL pCloneFont AS IGdipFont
      LOCAL pCloneFontPtr AS DWORD
      m_hStatus = GdipCloneFont(m_pFont, pCloneFontPtr)
      pCloneFont = CLASS "CGdipFont"
      IF ISNOTHING(pCloneFont) THEN EXIT METHOD
      pCloneFont.Ptr = pCloneFontPtr
      METHOD = pCloneFont
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The IsAvailable method determines whether this Font object was created successfully.
   ' =====================================================================================
   METHOD IsAvailable () THREADSAFE AS LONG
      METHOD = m_pFont <> 0
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The GetFamily method gets the font family on which this font is based.
   ' =====================================================================================
   METHOD GetFamily (BYREF pFamily AS IGdipFontFamily) THREADSAFE AS LONG
      IF ISNOTHING(pFamily) THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = m_hStatus
         EXIT METHOD
      END IF
      LOCAL pFamilyPtr AS DWORD
      m_hStatus = GdipGetFamily(m_pFont, pFamilyPtr)
      pFamily.Ptr = pFamilyPtr
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The GetStyle method gets the style of this font's typeface.
   ' =====================================================================================
   METHOD GetStyle () THREADSAFE AS LONG
      LOCAL nStyle AS LONG
      m_hStatus = GdipGetFontStyle(m_pFont, nStyle)
      METHOD = nStyle
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The GetSize method returns the font size (commonly called the em size) of this
   ' Font object. The size is in the units of this Font object.
   ' =====================================================================================
   METHOD GetSize () THREADSAFE AS SINGLE
      LOCAL nSize AS SINGLE
      m_hStatus = GdipGetFontSize(m_pFont, nSize)
      METHOD = nSize
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The GetUnit method returns the unit of measure of this Font object.
   ' =====================================================================================
   METHOD GetUnit () THREADSAFE AS LONG
      LOCAL unit AS LONG
      m_hStatus = GdipGetFontUnit(m_pFont, unit)
      METHOD = unit
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the line spacing of this font in the current unit of a specified Graphics object.
   ' The line spacing is the vertical distance between the base lines of two consecutive
   ' lines of text. Thus, the line spacing includes the blank space between lines along
   ' with the height of the character itself.
   ' =====================================================================================
   METHOD GetHeight (BYVAL pGraphics AS IGdipGraphics) THREADSAFE AS SINGLE
      LOCAL nHeight AS SINGLE
      m_hStatus = GdipGetFontHeight(m_pFont, IIF(ISOBJECT(pGraphics), pGraphics.Ptr, %NULL), nHeight)
      METHOD = nHeight
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the line spacing, in pixels, of this font. The line spacing is the vertical
   ' distance between the base lines of two consecutive lines of text. Thus, the line
   ' spacing includes the blank space between lines along with the height of the character
   ' itself.
   ' =====================================================================================
   METHOD GetHeightGivenDPI (BYVAL dpi AS SINGLE) THREADSAFE AS SINGLE
      LOCAL nHeight AS SINGLE
      m_hStatus = GdipGetFontHeightGivenDPI(m_pFont, dpi, nHeight)
      METHOD = nHeight
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' ########################################################################################
