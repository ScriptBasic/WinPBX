' ########################################################################################
' Microsoft Windows
' File: CGdipStringFormat.inc
' Contents: GDI+ StringFormat class.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CGDIPSTRINGFORMAT_INC = 1

' ########################################################################################
' CGdipStringFormat Class
' ########################################################################################
CLASS CGdipStringFormat

   INSTANCE m_hStatus AS LONG
   INSTANCE m_pStringFormat AS DWORD

   ' =====================================================================================
   ' Cleanup
   ' =====================================================================================
   CLASS METHOD Destroy
      IF m_pStringFormat THEN GdipDeleteStringFormat(m_pStringFormat)
   END METHOD
   ' =====================================================================================

   INTERFACE IGdipStringFormat : INHERIT IAutomation

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
      PROPERTY = m_pStringFormat
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a pointer to the Graphics object.
   ' =====================================================================================
   PROPERTY SET Ptr (BYVAL pPtr AS DWORD) THREADSAFE
      IF m_pStringFormat THEN GdipDeleteStringFormat(m_pStringFormat)
      m_pStringFormat = pPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a StringFormat object based on string format flags and a language.
   ' =====================================================================================
   METHOD StringFormat (OPTIONAL BYVAL formatFlags AS LONG, BYVAL language AS WORD) THREADSAFE AS LONG
      m_hStatus = GdipCreateStringFormat(formatFlags, language, m_pStringFormat)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a StringFormat from another StringFormat object.
   ' =====================================================================================
   METHOD StringFormat2 (BYVAL pFormat AS IGdipStringFormat) THREADSAFE AS LONG
      IF m_pStringFormat THEN GdipDeleteStringFormat(m_pStringFormat)
      m_hStatus = GdipCloneStringFormat(pFormat.Ptr, m_pStringFormat)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new StringFormat object based on this StringFormat object.
   ' =====================================================================================
   METHOD Clone () THREADSAFE AS IGdipStringFormat
      LOCAL pCloneStringFormat AS IGdipStringFormat
      LOCAL pCloneStringFormatPtr AS DWORD
      m_hStatus = GdipCloneStringFormat(m_pStringFormat, pCloneStringFormatPtr)
      pCloneStringFormat = CLASS "CGdipStringFormat"
      IF ISNOTHING(pCloneStringFormat) THEN EXIT METHOD
      pCloneStringFormat.Ptr = pCloneStringFormatPtr
      METHOD = pCloneStringFormat
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the format flags for this StringFormat object. The format flags determine most
   ' of the characteristics of a StringFormat object.
   ' =====================================================================================
   METHOD SetFormatFlags (BYVAL flags AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetStringFormatFlags(m_pStringFormat, flags)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the format flags for this StringFormat object. The format flags determine most
   ' of the characteristics of a StringFormat object.
   ' =====================================================================================
   METHOD GetFormatFlags () THREADSAFE AS LONG
      LOCAL flags AS LONG
      m_hStatus = GdipGetStringFormatFlags(m_pStringFormat, flags)
      METHOD = flags
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the character alignment of this StringFormat object in relation to the origin of
   ' the layout rectangle. A layout rectangle is used to position the displayed string.
   ' =====================================================================================
   METHOD SetAlignment (BYVAL nAlign AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetStringFormatAlign(m_pStringFormat, nAlign)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the format flags for this StringFormat object. The format flags determine most
   ' of the characteristics of a StringFormat object.
   ' =====================================================================================
   METHOD GetAlignment () THREADSAFE AS LONG
      LOCAL alignment AS LONG
      m_hStatus = GdipGetStringFormatFlags(m_pStringFormat, alignment)
      METHOD = alignment
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the line alignment of this StringFormat object in relation to the origin of the
   ' layout rectangle. The line alignment setting specifies how to align the string vertically
   ' in the layout rectangle. The layout rectangle is used to position the displayed string.
   ' =====================================================================================
   METHOD SetLineAlignment (BYVAL nAlign AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetStringFormatLineAlign(m_pStringFormat, nAlign)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the line alignment of this StringFormat object in relation to the origin of the
   ' layout rectangle. The line alignment setting specifies how to align the string vertically
   ' in the layout rectangle. The layout rectangle is used to position the displayed string.
   ' =====================================================================================
   METHOD GetLineAlignment () THREADSAFE AS LONG
      LOCAL alignment AS LONG
      m_hStatus = GdipGetStringFormatLineAlign(m_pStringFormat, alignment)
      METHOD = alignment
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the type of processing that is performed on a string when the hot key prefix, an
   ' ampersand (&), is encountered. The ampersand is called the hot key prefix and can be
   ' used to designate certain keys as hot keys.
   ' =====================================================================================
   METHOD SetHotkeyPrefix (BYVAL hotkeyPrefix AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetStringFormatHotkeyPrefix(m_pStringFormat, hotkeyPrefix)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the type of processing that is performed on a string when the hot key prefix, an
   ' ampersand (&), is encountered. The ampersand is called the hot key prefix and can be
   ' used to designate certain keys as hot keys.
   ' =====================================================================================
   METHOD GetHotkeyPrefix () THREADSAFE AS LONG
      LOCAL hotkeyPrefix AS LONG
      m_hStatus = GdipGetStringFormatHotkeyPrefix(m_pStringFormat, hotkeyPrefix)
      METHOD = hotkeyPrefix
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the offsets for tab stops in this StringFormat object.
   ' =====================================================================================
   METHOD SetTabStops (BYVAL firstTabOffset AS SINGLE, BYVAL nCount AS LONG, BYREF tabStops AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipSetStringFormatTabStops(m_pStringFormat, firstTabOffset, nCount, tabStops)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the number of tab-stop offsets in this StringFormat object.
   ' =====================================================================================
   METHOD GetTabStopCount () THREADSAFE AS LONG
      LOCAL nCount AS LONG
      m_hStatus = GdipGetStringFormatTabStopCount(m_pStringFormat, nCount)
      METHOD = nCount
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets offsets of the tab stops in this StringFormat object.
   ' =====================================================================================
   METHOD GetTabStops (BYVAL nCount AS LONG, BYREF firstTabOffset AS SINGLE, BYREF tabStops AS SINGLE) THREADSAFE AS LONG
      m_hStatus = GdipGetStringFormatTabStops(m_pStringFormat, nCount, firstTabOffset, tabStops)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the digit substitution method and the language that corresponds to the digit substitutes.
   ' =====================================================================================
   METHOD SetDigitSubstitution (BYVAL language AS WORD, BYVAL substitute AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetStringFormatDigitSubstitution(m_pStringFormat, language, substitute)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the digit substitution method and the language that corresponds to the digit substitutes.
   ' =====================================================================================
   METHOD GetDigitSubstitutionLanguage () THREADSAFE AS WORD
      LOCAL language AS WORD
      m_hStatus = GdipGetStringFormatDigitSubstitution(m_pStringFormat, language, BYVAL %NULL)
      METHOD = language
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets an element of the StringDigitSubstitute enumeration that indicates the digit
   ' substitution method that is used by this StringFormat object.
   ' =====================================================================================
   METHOD GetDigitSubstitutionMethod () THREADSAFE AS LONG
      LOCAL substitute AS LONG
      m_hStatus = GdipGetStringFormatDigitSubstitution(m_pStringFormat, BYVAL %NULL, substitute)
      METHOD = substitute
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the trimming style for this StringFormat object. The trimming style determines
   ' how to trim a string so that it fits into the layout rectangle.
   ' =====================================================================================
   METHOD SetTrimming (BYVAL trimming AS LONG) THREADSAFE AS LONG
      m_hStatus = GdipSetStringFormatTrimming(m_pStringFormat, trimming)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets an element of the StringDigitSubstitute enumeration that indicates the digit
   ' substitution method that is used by this StringFormat object.
   ' =====================================================================================
   METHOD GetTrimming () THREADSAFE AS LONG
      LOCAL trimming AS LONG
      m_hStatus = GdipGetStringFormatTrimming(m_pStringFormat, trimming)
      METHOD = trimming
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets a series of character ranges for this StringFormat object that, when in a string,
   ' can be measured by the MeasureCharacterRanges method.
   ' =====================================================================================
   METHOD SetMeasurableCharacterRanges (BYVAL rangeCount AS LONG, BYREF ranges AS CharacterRange) THREADSAFE AS LONG
      m_hStatus = GdipSetStringFormatMeasurableCharacterRanges(m_pStringFormat, rangeCount, ranges)
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a series of character ranges for this StringFormat object that, when in a string,
   ' can be measured by the MeasureCharacterRanges method.
   ' =====================================================================================
   METHOD GetMeasurableCharacterRangeCount () THREADSAFE AS LONG
      LOCAL nCount AS LONG
      m_hStatus = GdipGetStringFormatMeasurableCharacterRangeCount(m_pStringFormat, nCount)
      METHOD = nCount
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a generic, default StringFormat object.
   ' =====================================================================================
   METHOD GenericDefault () THREADSAFE AS IGdipStringFormat
      LOCAL pStringFormat AS IGdipStringFormat
      LOCAL pStringFormatPtr AS DWORD
      m_hStatus = GdipStringFormatGetGenericDefault(pStringFormatPtr)
      pStringFormat = CLASS "CGdipStringFormat"
      IF ISNOTHING(pStringFormat) THEN EXIT METHOD
      pStringFormat.Ptr = pStringFormatPtr
      METHOD = pStringFormat
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a generic, typographic StringFormat object.
   ' =====================================================================================
   METHOD GenericTypographic () THREADSAFE AS IGdipStringFormat
      LOCAL pStringFormat AS IGdipStringFormat
      LOCAL pStringFormatPtr AS DWORD
      m_hStatus = GdipStringFormatGetGenericTypographic(pStringFormatPtr)
      pStringFormat = CLASS "CGdipStringFormat"
      IF ISNOTHING(pStringFormat) THEN EXIT METHOD
      pStringFormat.Ptr = pStringFormatPtr
      METHOD = pStringFormat
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' ########################################################################################
