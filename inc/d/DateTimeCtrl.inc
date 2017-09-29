' ########################################################################################
' Microsoft Windows
' File: DateTimeCtrl.inc
' Contents: DateTime control wrapper functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DATETIMECTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"
#INCLUDE ONCE "AfxWin.inc"

' ========================================================================================
' Closes the date and time picker (DTP) control.
' ========================================================================================
FUNCTION DateTime_CloseMonthCal (BYVAL hdp AS DWORD) AS LONG
   FUNCTION = SendMessage(hdp, %DTM_CLOSEMONTHCAL, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets information for a specified date and time picker (DTP) control.
' ========================================================================================
FUNCTION DateTime_GetDateTimePickerInfo (BYVAL hdp AS DWORD, BYREF pdtpi AS DATETIMEPICKERINFO) AS LONG
   FUNCTION = SendMessage(hdp, %DTM_GETDATETIMEPICKERINFO, 0, VARPTR(pdtpi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the size needed to display the control without clipping.
' ========================================================================================
FUNCTION DateTime_GetIdealSize (BYVAL hdp AS DWORD, BYREF psize AS SIZE) AS LONG
   FUNCTION = SendMessage(hdp, %DTM_GETIDEALSIZE, 0, VARPTR(psize))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the handle to a date and time picker's (DTP) child month calendar control.
' ========================================================================================
FUNCTION DateTime_GetMonthCal (BYVAL hdp AS DWORD) AS DWORD
   FUNCTION = SendMessage(hdp, %DTM_GETMONTHCAL, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the color for a given portion of the month calendar within a date and time
' picker (DTP) control.
' ========================================================================================
FUNCTION DateTime_GetMonthCalColor (BYVAL hdp AS DWORD, BYVAL iColor AS DWORD) AS LONG
   FUNCTION = SendMessage(hdp, %DTM_GETMCCOLOR, iColor, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the font that the date and time picker (DTP) control's child month calendar control
' is currently using.
' ========================================================================================
FUNCTION DateTime_GetMonthCalFont (BYVAL hdp AS DWORD) AS DWORD
   FUNCTION = SendMessage(hdp, %DTM_GETMCFONT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the style of a specified date and time picker (DTP) control.
' ========================================================================================
FUNCTION DateTime_GetMonthCalStyle (BYVAL hdp AS DWORD) AS LONG
   FUNCTION = SendMessage(hdp, %DTM_GETMCSTYLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current minimum and maximum allowable system times for a date and time
' picker (DTP) control.
' ========================================================================================
FUNCTION DateTime_GetRange (BYVAL hdp AS DWORD, BYREF lpSysTimeArray AS SYSTEMTIME) AS DWORD
   FUNCTION = SendMessage(hdp, %DTM_GETRANGE, 0, VARPTR(lpSysTimeArray))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the currently selected time from a date and time picker (DTP) control and
' places it in a specified SYSTEMTIME structure.
' ========================================================================================
FUNCTION DateTime_GetSystemTime (BYVAL hdp AS DWORD, BYREF lpSysTime AS SYSTEMTIME) AS DWORD
   FUNCTION = SendMessage(hdp, %DTM_GETSYSTEMTIME, 0, VARPTR(lpSysTime))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the display of a date and time picker (DTP) control based on a given format string.
' ========================================================================================
FUNCTION DateTime_SetFormatA (BYVAL hdp AS DWORD, BYREF szFormat AS ASCIIZ) AS LONG
   FUNCTION = SendMessageA(hdp, %DTM_SETFORMATA, 0, VARPTR(szFormat))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION DateTime_SetFormatW (BYVAL hdp AS DWORD, BYREF wszFormat AS WSTRINGZ) AS LONG
   FUNCTION = SendMessageW(hdp, %DTM_SETFORMATW, 0, VARPTR(wszFormat))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO DateTime_SetFormat = DateTime_SetFormatW
#ELSE
   MACRO DateTime_SetFormat = DateTime_SetFormatA
#ENDIF

' ========================================================================================
' Sets the color for a given portion of the month calendar within a date and time picker
' (DTP) control.
' ========================================================================================
FUNCTION DateTime_SetMonthCalColor (BYVAL hdp AS DWORD, BYVAL iColor AS DWORD, BYVAL clr AS DWORD) AS DWORD
   FUNCTION = SendMessage(hdp, %DTM_SETMCCOLOR, iColor, clr)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the font to be used by the date and time picker (DTP) control's child month
' calendar control.
' ========================================================================================
SUB DateTime_SetMonthCalFont (BYVAL hdp AS DWORD, BYVAL hFont AS DWORD, BYVAL fRedraw AS LONG)
   SendMessage hdp, %DTM_SETMCFONT, hFont, fRedraw
END SUB
' ========================================================================================

' ========================================================================================
' Sets the style for a specified date and time picker (DTP) control.
' ========================================================================================
FUNCTION DateTime_SetMonthCalStyle (BYVAL hdp AS DWORD, BYVAL dwStyle AS DWORD) AS LONG
   FUNCTION = SendMessage(hdp, %DTM_SETMCSTYLE, 0, dwStyle)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the minimum and maximum allowable system times for a date and time picker (DTP) control.
' ========================================================================================
FUNCTION DateTime_SetRange (BYVAL hdp AS DWORD, BYVAL flags AS DWORD, BYREF lpSysTimeArray AS SYSTEMTIME) AS LONG
   FUNCTION = SendMessage(hdp, %DTM_SETRANGE, flags, VARPTR(lpSysTimeArray))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets a date and time picker (DTP) control to a given date and time.
' ========================================================================================
FUNCTION DateTime_SetSystemTime (BYVAL hdp AS DWORD, BYVAL flag AS DWORD, BYREF lpSysTime AS SYSTEMTIME) AS LONG
   FUNCTION = SendMessage(hdp, %DTM_SETSYSTEMTIME, flag, VARPTR(lpSysTime))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Modifies the point size of the font of the month calendar child control.
' Parameters:
' - hwnd = Handle of the control.
' - Percent = The base is 100. To increase the font a 20% pass 120; to reduce it a 20% pass 80%.
' Return Value: 1 = success; 0 = failure.
' ========================================================================================
FUNCTION DateTimeFont_ModifyPointSize (BYVAL hwnd AS DWORD, BYVAL Percent AS SINGLE) AS LONG

   LOCAL hCurFont AS DWORD
   LOCAL hNewFont AS DWORD
   LOCAL lf AS LOGFONT
   LOCAL lPointSize AS LONG

   IF hwnd = 0 OR Percent = 0 THEN EXIT FUNCTION

   ' // Get the handle of the font used by the header
   hCurFont = SendMessage(hwnd, %DTM_GETMCFONT, 0, 0)
   IF hCurFont = 0 THEN EXIT FUNCTION

   ' // Get the LOGFONT structure
   IF GetObject(hCurFont, SIZEOF(lf), lf) = 0 THEN EXIT FUNCTION

   ' // Change the point size
   lPointSize = AfxGetFontPointSize(lf.lfHeight)
   lPointSize = lPointSize * (Percent / 100)
   lf.lfHeight = -MulDiv(lPointSize, AfxGetLogPixelsY, 72)

   ' // Create a new font
   hNewFont = CreateFontIndirect(lf)
   IF hNewFont = 0 THEN EXIT FUNCTION

   ' // Select the new font and delete the old one
   DeleteObject(SelectObject(hwnd, hNewFont))
   SendMessage hwnd, %DTM_SETMCFONT, hNewFont, %TRUE

   FUNCTION = 1

END FUNCTION
' ========================================================================================

' ========================================================================================
' Modifies the font face name of font of the month calendar child control.
' Parameters:
' - hwnd = Handle of the control.
' - strNewFaceName = The new face name of the font
' Return Value: 1 = success; 0 = failure.
' ========================================================================================
#IF NOT %DEF(%UNICODE)
FUNCTION DateTimeFont_ModifyFontFaceName (BYVAL hwnd AS DWORD, BYVAL strNewFaceName AS STRING) AS LONG
#ELSE
FUNCTION DateTimeFont_ModifyFontFaceName (BYVAL hwnd AS DWORD, BYVAL strNewFaceName AS WSTRING) AS LONG
#ENDIF

   LOCAL hCurFont AS DWORD
   LOCAL hNewFont AS DWORD
   LOCAL lf AS LOGFONT

   IF hwnd = 0 OR strNewFaceName = "" THEN EXIT FUNCTION

   ' // Get the handle of the font used by the header
   hCurFont = SendMessage(hwnd, %DTM_GETMCFONT, 0, 0)
   IF hCurFont = 0 THEN EXIT FUNCTION

   ' // Get the LOGFONT structure
   IF GetObject(hCurFont, SIZEOF(lf), lf) = 0 THEN EXIT FUNCTION

   ' // Change the face name
   lf.lfFaceName = strNewFaceName

   ' // Create a new font
   hNewFont = CreateFontIndirect(lf)
   IF hNewFont = 0 THEN EXIT FUNCTION

   ' // Select the new font and delete the old one
   DeleteObject(SelectObject(hwnd, hNewFont))
   SendMessage hwnd, %DTM_SETMCFONT, hNewFont, %TRUE

   FUNCTION = 1

END FUNCTION
' ========================================================================================

' ========================================================================================
' Modifies the weight of font of the month calendar child control.
' Parameters:
' - hwnd = Handle of the control.
' - nWeight = The weight of the font in the range 0 through 1000. For example, 400 is normal
'   and 700 is bold. If this value is zero, a default weight is used.
'   The following values are defined for convenience.
'   FW_DONTCARE   0
'   FW_THIN       100
'   FW_EXTRALIGHT 200
'   FW_ULTRALIGHT 200
'   FW_LIGHT      300
'   FW_NORMAL     400
'   FW_REGULAR    400
'   FW_MEDIUM     500
'   FW_SEMIBOLD   600
'   FW_DEMIBOLD   600
'   FW_BOLD       700
'   FW_EXTRABOLD  800
'   FW_ULTRABOLD  800
'   FW_HEAVY      900
'   FW_BLACK      900
' Return Value: 1 = success; 0 = failure.
' ========================================================================================
FUNCTION DateTimeFont_SetWeight (BYVAL hwnd AS DWORD, BYVAL nWeight AS LONG) AS LONG

   LOCAL hCurFont AS DWORD
   LOCAL hNewFont AS DWORD
   LOCAL lf AS LOGFONT

   IF hwnd = 0 THEN EXIT FUNCTION

   ' // Get the handle of the font used by the header
   hCurFont = SendMessage(hwnd, %DTM_GETMCFONT, 0, 0)
   IF hCurFont = 0 THEN EXIT FUNCTION

   ' // Get the LOGFONT structure
   IF GetObject(hCurFont, SIZEOF(lf), lf) = 0 THEN EXIT FUNCTION

   ' // Change the face name
   lf.lfWeight = nWeight

   ' // Create a new font
   hNewFont = CreateFontIndirect(lf)
   IF hNewFont = 0 THEN EXIT FUNCTION

   ' // Select the new font and delete the old one
   DeleteObject(SelectObject(hwnd, hNewFont))
   SendMessage hwnd, %DTM_SETMCFONT, hNewFont, %TRUE

   FUNCTION = 1

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the italic flag of font of the month calendar child control.
' Parameters:
' - hwnd = Handle of the window or control.
' - bFlag = %TRUE or %FALSE
' Return Value: 1 = success; 0 = failure.
' ========================================================================================
FUNCTION DateTimeFont_SetItalic (BYVAL hwnd AS DWORD, BYVAL bFlag AS BYTE) AS LONG

   LOCAL hCurFont AS DWORD
   LOCAL hNewFont AS DWORD
   LOCAL lf AS LOGFONT

   IF hwnd = 0 THEN EXIT FUNCTION
   IF bFlag <> 0 THEN bFlag = 1

   ' // Get the handle of the font used by the header
   hCurFont = SendMessage(hwnd, %DTM_GETMCFONT, 0, 0)
   IF hCurFont = 0 THEN EXIT FUNCTION

   ' // Get the LOGFONT structure
   IF GetObject(hCurFont, SIZEOF(lf), lf) = 0 THEN EXIT FUNCTION

   ' // Change the flag
   lf.lfItalic = bFlag

   ' // Create a new font
   hNewFont = CreateFontIndirect(lf)
   IF hNewFont = 0 THEN EXIT FUNCTION

   ' // Select the new font and delete the old one
   DeleteObject(SelectObject(hwnd, hNewFont))
   SendMessage hwnd, %DTM_SETMCFONT, hNewFont, %TRUE

   FUNCTION = 1

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the underline flag of font of the month calendar child control.
' Parameters:
' - hwnd = Handle of the control.
' - bFlag = %TRUE or %FALSE
' Return Value: 1 = success; 0 = failure.
' ========================================================================================
FUNCTION DateTimeFont_SetUnderline (BYVAL hwnd AS DWORD, BYVAL bFlag AS BYTE) AS LONG

   LOCAL hCurFont AS DWORD
   LOCAL hNewFont AS DWORD
   LOCAL lf AS LOGFONT

   IF hwnd = 0 THEN EXIT FUNCTION
   IF bFlag <> 0 THEN bFlag = 1

   ' // Get the handle of the font used by the header
   hCurFont = SendMessage(hwnd, %DTM_GETMCFONT, 0, 0)
   IF hCurFont = 0 THEN EXIT FUNCTION

   ' // Get the LOGFONT structure
   IF GetObject(hCurFont, SIZEOF(lf), lf) = 0 THEN EXIT FUNCTION

   ' // Change the flag
   lf.lfUnderline = bFlag

   ' // Create a new font
   hNewFont = CreateFontIndirect(lf)
   IF hNewFont = 0 THEN EXIT FUNCTION

   ' // Select the new font and delete the old one
   DeleteObject(SelectObject(hwnd, hNewFont))
   SendMessage hwnd, %DTM_SETMCFONT, hNewFont, %TRUE

   FUNCTION = 1

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the strike out flag of font of the month calendar child control.
' Parameters:
' - hwnd = Handle of the control.
' - bFlag = %TRUE or %FALSE
' Return Value: 1 = success; 0 = failure.
' ========================================================================================
FUNCTION DateTimeFont_SetStrikeOut (BYVAL hwnd AS DWORD, BYVAL bFlag AS BYTE) AS LONG

   LOCAL hCurFont AS DWORD
   LOCAL hNewFont AS DWORD
   LOCAL lf AS LOGFONT

   IF hwnd = 0 THEN EXIT FUNCTION
   IF bFlag <> 0 THEN bFlag = 1

   ' // Get the handle of the font used by the header
   hCurFont = SendMessage(hwnd, %DTM_GETMCFONT, 0, 0)
   IF hCurFont = 0 THEN EXIT FUNCTION

   ' // Get the LOGFONT structure
   IF GetObject(hCurFont, SIZEOF(lf), lf) = 0 THEN EXIT FUNCTION

   ' // Change the flag
   lf.lfStrikeOut = bFlag

   ' // Create a new font
   hNewFont = CreateFontIndirect(lf)
   IF hNewFont = 0 THEN EXIT FUNCTION

   ' // Select the new font and delete the old one
   DeleteObject(SelectObject(hwnd, hNewFont))
   SendMessage hwnd, %DTM_SETMCFONT, hNewFont, %TRUE

   FUNCTION = 1

END FUNCTION
' ========================================================================================

' ========================================================================================
' Changes the charset of font of the month calendar child control.
' Parameters:
' - hwnd = Handle of the control.
' - bCharset = The following values are predefined.
'    ANSI_CHARSET
'    BALTIC_CHARSET
'    CHINESEBIG5_CHARSET
'    DEFAULT_CHARSET
'    EASTEUROPE_CHARSET
'    GB2312_CHARSET
'    GREEK_CHARSET
'    HANGUL_CHARSET
'    MAC_CHARSET
'    OEM_CHARSET
'    RUSSIAN_CHARSET
'    SHIFTJIS_CHARSET
'    SYMBOL_CHARSET
'    TURKISH_CHARSET
'    VIETNAMESE_CHARSET

' Korean language edition of Windows:

'    JOHAB_CHARSET

' Middle East language edition of Windows:

'    ARABIC_CHARSET
'    HEBREW_CHARSET

' Thai language edition of Windows:

'    THAI_CHARSET

' The OEM_CHARSET value specifies a character set that is operating-system dependent.

' DEFAULT_CHARSET is set to a value based on the current system locale. For example, when
' the system locale is English (United States), it is set as ANSI_CHARSET.

' Fonts with other character sets may exist in the operating system. If an application uses
' a font with an unknown character set, it should not attempt to translate or interpret
' strings that are rendered with that font.

' This parameter is important in the font mapping process. To ensure consistent results,
' specify a specific character set. If you specify a typeface name in the lfFaceName member,
' make sure that the lfCharSet value matches the character set of the typeface specified in lfFaceName.

' Return Value: 1 = success; 0 = failure.
' ========================================================================================
FUNCTION DateTimeFont_SetCharset (BYVAL hwnd AS DWORD, BYVAL bCharset AS BYTE) AS LONG

   LOCAL hCurFont AS DWORD
   LOCAL hNewFont AS DWORD
   LOCAL lf AS LOGFONT

   IF hwnd = 0 THEN EXIT FUNCTION

   ' // Get the handle of the font used by the header
   hCurFont = SendMessage(hwnd, %DTM_GETMCFONT, 0, 0)
   IF hCurFont = 0 THEN EXIT FUNCTION

   ' // Get the LOGFONT structure
   IF GetObject(hCurFont, SIZEOF(lf), lf) = 0 THEN EXIT FUNCTION

   ' // Change the charset
   lf.lfCharset = bCharset

   ' // Create a new font
   hNewFont = CreateFontIndirect(lf)
   IF hNewFont = 0 THEN EXIT FUNCTION

   ' // Select the new font and delete the old one
   DeleteObject(SelectObject(hwnd, hNewFont))
   SendMessage hwnd, %DTM_SETMCFONT, hNewFont, %TRUE

   FUNCTION = 1

END FUNCTION
' ========================================================================================
