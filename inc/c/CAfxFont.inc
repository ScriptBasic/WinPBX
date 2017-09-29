' ########################################################################################
' Microsoft Windows
' File: CAfxFont.inc
' Contents: Font class.
' Copyright (c) 2011 José Roca.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CAFXFONT_INC = 1

#INCLUDE ONCE "windows.inc"

' ########################################################################################
' CAfxFont class.
' ########################################################################################
CLASS CAfxFont

   INSTANCE m_hFont AS DWORD
   INSTANCE m_lWidth AS LONG
   INSTANCE m_lEscapement AS LONG
   INSTANCE m_lOrientation AS LONG
   INSTANCE m_lWeight AS LONG
   INSTANCE m_fItalic AS LONG
   INSTANCE m_fUnderline AS LONG
   INSTANCE m_fStrikeOut AS LONG
   INSTANCE m_lCharset AS LONG
   INSTANCE m_lOutPrecision AS LONG
   INSTANCE m_lClipPrecision AS LONG
   INSTANCE m_lQuality AS LONG
   INSTANCE m_lPitchAndFamily AS LONG
   INSTANCE m_rSize AS SINGLE
   INSTANCE m_fDirty AS LONG

#IF %DEF(%UNICODE)
   INSTANCE m_FontName AS WSTRING
   INSTANCE m_strFaceName AS WSTRING
#ELSE
   INSTANCE m_FontName AS STRING
   INSTANCE m_strFaceName AS STRING
#ENDIF

   ' =====================================================================================
   ' Create method
   ' =====================================================================================
   CLASS METHOD Create
      m_fDirty = -1
      m_FontName = "Default font"
      m_strFaceName = "Tahoma"
      m_lWeight = %FW_NORMAL
      m_lCharset = %DEFAULT_CHARSET
      m_rSize = 8
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Destroy method
   ' =====================================================================================
   CLASS METHOD Destroy
      IF m_hFont THEN DeleteObject(m_hFont)
   END METHOD
   ' =====================================================================================

   ' // Note: I have used IAfxFont instead of IFont because the later is already used by Microsoft.
   INTERFACE IAfxFont : INHERIT IAutomation

   ' =====================================================================================
   ' Creates a font and returns an handle to it.
   ' =====================================================================================
   METHOD CreateFont() AS DWORD
#IF %DEF(%UNICODE)
      LOCAL tlf AS LOGFONTW
#ELSE
      LOCAL tlf AS LOGFONTA
#ENDIF
      LOCAL hDC AS DWORD
      IF m_fDirty THEN
         IF m_hFont THEN
            DeleteObject m_hFont
            m_hFont = %NULL
         END IF
         hDC = GetDC(%NULL)
         tlf.lfHeight         = -MulDiv(m_rSize, GetDeviceCaps(hDC, %LOGPIXELSY), 72)  ' // Logical font height
         tlf.lfWidth          =  m_lWidth                                              ' // Average character width
         tlf.lfEscapement     =  m_lEscapement                                         ' // Escapement
         tlf.lfOrientation    =  m_lOrientation                                        ' // Orientation angles
         tlf.lfWeight         =  m_lWeight                                             ' // Font weight
         tlf.lfItalic         =  m_fItalic                                             ' // Italic(TRUE/FALSE)
         tlf.lfUnderline      =  m_fUnderline                                          ' // Underline(TRUE/FALSE)
         tlf.lfStrikeOut      =  m_fStrikeOut                                          ' // Strikeout(TRUE/FALSE)
         tlf.lfCharSet        =  m_lCharset                                            ' // Character set
         tlf.lfOutPrecision   =  m_lOutPrecision                                       ' // Output precision
         tlf.lfClipPrecision  =  m_lClipPrecision                                      ' // Clipping precision
         tlf.lfQuality        =  m_lQuality                                            ' // Output quality
         tlf.lfPitchAndFamily =  m_lPitchAndFamily                                     ' // Pitch and family
         tlf.lfFaceName       =  m_strFaceName                                         ' // Typeface name
         ReleaseDC %NULL, hDC
#IF %DEF(%UNICODE)
         m_hFont = CreateFontIndirectW(tlf)
#ELSE
         m_hFont = CreateFontIndirectA(tlf)
#ENDIF
         m_fDirty = 0
      END IF
      METHOD = m_hFont
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the handle of the font. If the handle is null or the characteristics have
   ' been changed, it deletes the old font and creates a new one.
   ' =====================================================================================
   PROPERTY GET hFont() AS DWORD
      IF m_fDirty THEN ME.CreateFont
      PROPERTY = m_hFont
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the size of the font.
   ' =====================================================================================
   PROPERTY GET Size() AS SINGLE
      PROPERTY = m_rSize
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the size of the font
   ' =====================================================================================
    PROPERTY SET Size (BYVAL rSize AS SINGLE)
      m_fDirty = -1
      m_rSize = rSize
    END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the width of the font.
   ' =====================================================================================
   PROPERTY GET Width() AS LONG
      PROPERTY = m_lWidth
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the width of the font.
   ' =====================================================================================
   PROPERTY SET Width (BYVAL lWidth AS LONG)
      m_fDirty = -1
      m_lWidth = lWidth
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the escapment of the font.
   ' =====================================================================================
   PROPERTY GET Escapement() AS LONG
      PROPERTY = m_lEscapement
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the escapment of the font.
   ' =====================================================================================
   PROPERTY SET Escapement (BYVAL lEscapement AS LONG)
      m_fDirty = -1
      m_lEscapement = lEscapement
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the orientation of the font.
   ' =====================================================================================
   PROPERTY GET Orientation() AS LONG
      PROPERTY = m_lOrientation
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the orientation of the font.
   ' =====================================================================================
   PROPERTY SET Orientation(BYVAL lOrientation AS LONG)
      m_fDirty = -1
      m_lOrientation = lOrientation
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns -1 if the font is bold, or 0 otherwise.
   ' =====================================================================================
   PROPERTY GET Bold() AS LONG
      PROPERTY = (m_lWeight >= ((%FW_NORMAL + %FW_BOLD) \ 2))
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' True to create the font bold, or 0 otherwise.
   ' =====================================================================================
   PROPERTY SET Bold (BYVAL fBold AS LONG)
      IF m_lWeight <> %FW_BOLD THEN
         m_fDirty = -1
         m_lWeight = %FW_BOLD
      END IF
    END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the weight of the font.
   ' =====================================================================================
   PROPERTY GET Weight() AS LONG
      PROPERTY = m_lWeight
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the weight of the font.
   ' =====================================================================================
   PROPERTY SET Weight (BYVAL lWeight AS LONG)
      IF m_lWeight <> lWeight THEN
        m_fDirty = -1
        m_lWeight = lWeight
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' True if the font is italic, or false otherwise.
   ' =====================================================================================
   PROPERTY GET Italic() AS LONG
      PROPERTY = m_fItalic
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' True if the font is italic, or false otherwise.
   ' =====================================================================================
   PROPERTY SET Italic (BYVAL fItalic AS LONG)
      fItalic = (fItalic <> 0)
      IF m_fItalic <> fItalic THEN
         m_fDirty = -1
         m_fItalic = fItalic
      END IF
    END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' True if the font is underlined, or false otherwise.
   ' =====================================================================================
   PROPERTY GET Underline() AS LONG
      PROPERTY = m_fUnderline
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' True if the font is underlined, or false otherwise.
   ' =====================================================================================
   PROPERTY SET Underline (BYVAL fUnderline AS LONG)
      fUnderline = (fUnderline <> 0)
      IF m_fUnderline <> fUnderline THEN
         m_fDirty = -1
         m_fUnderline = fUnderline
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' True if the font is strike out, or false otherwise.
   ' =====================================================================================
   PROPERTY GET StrikeOut() AS LONG
      PROPERTY = m_fStrikeOut
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' True if the font is strike out, or false otherwise.
   ' =====================================================================================
   PROPERTY SET StrikeOut(BYVAL fStrikeOut AS LONG)
      fStrikeOut = (fStrikeOut <> 0)
      IF m_fStrikeOut <> fStrikeOut THEN
         m_fDirty = -1
         m_fStrikeOut = fStrikeOut
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the character set of the font.
   ' =====================================================================================
   PROPERTY GET CharSet() AS LONG
      PROPERTY = m_lCharSet
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the character set of the font.
   ' =====================================================================================
   PROPERTY SET CharSet (BYVAL lCharSet AS LONG)
      IF m_lCharSet <> lCharSet THEN
         m_fDirty = -1
         m_lCharSet = lCharSet
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the output precision.
   ' =====================================================================================
   PROPERTY GET OutPrecision() AS LONG
      PROPERTY = m_lOutPrecision
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the output precision.
   ' =====================================================================================
   PROPERTY SET OutPrecision (BYVAL lOutPrecision AS LONG)
      IF m_lOutPrecision <> lOutPrecision THEN
         m_fDirty = -1
         m_lOutPrecision = lOutPrecision
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the clipping precision.
   ' =====================================================================================
   PROPERTY GET ClipPrecision() AS LONG
      PROPERTY = m_lClipPrecision
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the clipping precision.
   ' =====================================================================================
   PROPERTY SET ClipPrecision (BYVAL lClipPrecision AS LONG)
      IF m_lClipPrecision <> lClipPrecision THEN
         m_fDirty = -1
         m_lClipPrecision = lClipPrecision
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the output quality.
   ' =====================================================================================
   PROPERTY GET Quality() AS LONG
      PROPERTY = m_lQuality
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the output quality.
   ' =====================================================================================
   PROPERTY SET Quality(BYVAL lQuality AS LONG)
      IF m_lQuality <> lQuality THEN
         m_fDirty = -1
         m_lQuality = lQuality
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the pitch and family of the font.
   ' =====================================================================================
   PROPERTY GET PitchAndFamily() AS LONG
      PROPERTY = m_lPitchAndFamily
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the pitch and family of the font.
   ' =====================================================================================
   PROPERTY SET PitchAndFamily (BYVAL lPitchAndFamily AS LONG)
      IF m_lPitchAndFamily <> lPitchAndFamily THEN
         m_fDirty = -1
         m_lPitchAndFamily = lPitchAndFamily
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the font name
   ' =====================================================================================
#IF %DEF(%UNICODE)
   PROPERTY GET Name () AS WSTRING
#ELSE
   PROPERTY GET Name () AS STRING
#ENDIF
      PROPERTY = m_FontName
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the font name
   ' =====================================================================================
#IF %DEF(%UNICODE)
   PROPERTY SET Name (BYVAL strName AS WSTRING)
#ELSE
   PROPERTY SET Name (BYVAL strName AS STRING)
#ENDIF
      m_FontName = strName
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the font face name
   ' =====================================================================================
#IF %DEF(%UNICODE)
   PROPERTY GET FaceName () AS WSTRING
#ELSE
   PROPERTY GET FaceName () AS STRING
#ENDIF
      PROPERTY = m_strFaceName
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the font face name
   ' =====================================================================================
#IF %DEF(%UNICODE)
   PROPERTY SET FaceName (BYVAL strFaceName AS WSTRING)
#ELSE
   PROPERTY SET FaceName (BYVAL strFaceName AS STRING)
#ENDIF
      m_strFaceName = strFaceName
   END PROPERTY
   ' =====================================================================================

   END INTERFACE
   ' =====================================================================================

END CLASS
' ########################################################################################
