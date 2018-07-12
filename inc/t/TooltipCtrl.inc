' ########################################################################################
' Microsoft Windows
' File: TooltipCtrl.inc
' Contents: Tooltip Control Wrapper Functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TOOLTIPCTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"

' ========================================================================================
' Activates or deactivates a ToolTip control.
' ========================================================================================
SUB Tooltip_Activate (BYVAL hTooltip AS DWORD, BYVAL fActivate AS LONG)
   SendMessage hTooltip, %TTM_ACTIVATE, fActivate, 0
END SUB
' ========================================================================================

' ========================================================================================
' Registers a tool with a ToolTip control.
' ========================================================================================
FUNCTION Tooltip_AddTool (BYVAL hTooltip AS DWORD, BYREF lpti AS TOOLINFO) AS LONG
   FUNCTION = SendMessage (hTooltip, %TTM_ADDTOOL, 0, VARPTR(lpti))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Calculates a ToolTip control's text display rectangle from its window rectangle, or the
' ToolTip window rectangle needed to display a specified text display rectangle.
' ========================================================================================
FUNCTION Tooltip_AdjustRect (BYVAL hTooltip AS DWORD, BYVAL fLarger AS LONG, BYREF lprc AS RECT) AS LONG
   FUNCTION = SendMessage (hTooltip, %TTM_ADJUSTRECT, fLarger, VARPTR(lprc))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes a tool from a ToolTip control.
' ========================================================================================
SUB Tooltip_DelTool (BYVAL hTooltip AS DWORD, BYREF lpti AS TOOLINFO)
   SendMessage hTooltip, %TTM_DELTOOL, 0, VARPTR(lpti)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the information that a ToolTip control maintains about the current tool--that
' is, the tool for which the ToolTip is currently displaying text.
' ========================================================================================
FUNCTION Tooltip_EnumTools (BYVAL hTooltip AS DWORD, BYVAL iTool AS DWORD, BYREF lpti AS TOOLINFO) AS LONG
   FUNCTION = SendMessage (hTooltip, %TTM_ENUMTOOLS, iTool, VARPTR(lpti))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the width and height of a ToolTip control.
' ========================================================================================
FUNCTION Tooltip_GetBubbleSize (BYVAL hTooltip AS DWORD, BYREF lpTtm AS TOOLINFO) AS LONG
   FUNCTION = SendMessage (hTooltip, %TTM_GETBUBBLESIZE, 0, VARPTR(lpTtm))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the information for the current tool in a ToolTip control.
' ========================================================================================
FUNCTION Tooltip_GetCurrentTool (BYVAL hTooltip AS DWORD, BYREF lpti AS TOOLINFO) AS LONG
   FUNCTION = SendMessage (hTooltip, %TTM_GETCURRENTTOOL, 0, VARPTR(lpti))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the information for the current tool in a ToolTip control.
' ========================================================================================
FUNCTION Tooltip_GetDelayTime (BYVAL hTooltip AS DWORD, BYVAL dwDuration AS DWORD) AS LONG
   FUNCTION = SendMessage (hTooltip, %TTM_GETDELAYTIME, dwDuration, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the top, left, bottom, and right margins set for a ToolTip window. A margin is
' the distance, in pixels, between the ToolTip window border and the text contained within
' the ToolTip window.
' ========================================================================================
FUNCTION Tooltip_GetMargin (BYVAL hTooltip AS DWORD, BYREF lprc AS RECT) AS LONG
   FUNCTION = SendMessage (hTooltip, %TTM_GETMARGIN, 0, VARPTR(lprc))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the maximum width for a ToolTip window.
' ========================================================================================
FUNCTION Tooltip_GetMaxTipWidth (BYVAL hTooltip AS DWORD) AS LONG
   FUNCTION = SendMessage (hTooltip, %TTM_GETMAXTIPWIDTH, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the information a ToolTip control maintains about a tool.
' ========================================================================================
SUB Tooltip_GetText (BYVAL hTooltip AS DWORD, BYVAL numChars AS DWORD, BYREF lpti AS TOOLINFO)
   SendMessage hTooltip, %TTM_GETTEXT, numChars, VARPTR(lpti)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the background color in a ToolTip window.
' ========================================================================================
FUNCTION Tooltip_GetTipBkColor (BYVAL hTooltip AS DWORD) AS DWORD
   FUNCTION = SendMessage (hTooltip, %TTM_GETTIPBKCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the text color in a ToolTip window.
' ========================================================================================
FUNCTION Tooltip_GetTipTextColor (BYVAL hTooltip AS DWORD) AS DWORD
   FUNCTION = SendMessage (hTooltip, %TTM_GETTIPTEXTCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves information concerning the title of a tooltip control.
' ========================================================================================
SUB Tooltip_GetTitle (BYVAL hTooltip AS DWORD, BYREF pTTGetTitle AS TTGETTITLE)
   SendMessage hTooltip, %TTM_GETTITLE, 0, VARPTR(pTTGetTitle)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves a count of the tools maintained by a ToolTip control.
' ========================================================================================
FUNCTION Tooltip_GetToolCount (BYVAL hTooltip AS DWORD) AS LONG
   FUNCTION = SendMessage (hTooltip, %TTM_GETTOOLCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the information that a ToolTip control maintains about a tool.
' ========================================================================================
FUNCTION Tooltip_GetToolInfo (BYVAL hTooltip AS DWORD, BYREF lpti AS TOOLINFO) AS LONG
   FUNCTION = SendMessage (hTooltip, %TTM_GETTOOLINFO, 0, VARPTR(lpti))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Tests a point to determine whether it is within the bounding rectangle of the specified
' tool and, if it is, retrieves information about the tool.
' ========================================================================================
FUNCTION Tooltip_HitTest (BYVAL hTooltip AS DWORD, BYREF lphti AS TTHITTESTINFO) AS LONG
   FUNCTION = SendMessage (hTooltip, %TTM_HITTEST, 0, VARPTR(lphti))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets a new bounding rectangle for a tool.
' ========================================================================================
SUB Tooltip_NewToolRect (BYVAL hTooltip AS DWORD, BYREF lpti AS TOOLINFO)
   SendMessage hTooltip, %TTM_NEWTOOLRECT, 0, VARPTR(lpti)
END SUB
' ========================================================================================

' ========================================================================================
' Removes a displayed ToolTip window from view.
' ========================================================================================
SUB Tooltip_Pop (BYVAL hTooltip AS DWORD)
   SendMessage hTooltip, %TTM_POP, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Causes the ToolTip to display at the coordinates of the last mouse message.
' ========================================================================================
SUB Tooltip_Popup (BYVAL hTooltip AS DWORD)
   SendMessage hTooltip, %TTM_POPUP, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Passes a mouse message to a ToolTip control for processing.
' ========================================================================================
FUNCTION Tooltip_RelayEvent (BYVAL hTooltip AS DWORD, BYREF lpmsg AS tagMSG) AS LONG
   FUNCTION = SendMessage (hTooltip, %TTM_RELAYEVENT, 0, VARPTR(lpmsg))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the initial, pop-up, and reshow durations for a ToolTip control.
' ========================================================================================
SUB Tooltip_SetDelayTime (BYVAL hTooltip AS DWORD, BYVAL dwDuration AS DWORD, BYVAL iTime AS INTEGER)
   SendMessage hTooltip, %TTM_SETDELAYTIME, dwDuration, MAK(LONG, iTime, 0)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the top, left, bottom, and right margins for a ToolTip window. A margin is the
' distance, in pixels, between the ToolTip window border and the text contained within the
' ToolTip window.
' ========================================================================================
SUB Tooltip_SetMargin (BYVAL hTooltip AS DWORD, BYREF lprc AS RECT)
   SendMessage hTooltip, %TTM_SETMARGIN, 0, VARPTR(lprc)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the maximum width for a ToolTip window.
' ========================================================================================
FUNCTION Tooltip_SetMaxTipWidth (BYVAL hTooltip AS DWORD, BYVAL iWidth AS LONG) AS LONG
   FUNCTION = SendMessage (hTooltip, %TTM_SETMAXTIPWIDTH, 0, iWidth)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the background color in a ToolTip window.
' ========================================================================================
SUB Tooltip_SetTipBkColor (BYVAL hTooltip AS DWORD, BYVAL clr AS DWORD)
   SendMessage hTooltip, %TTM_SETTIPBKCOLOR, clr, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the text color in a ToolTip window.
' ========================================================================================
SUB Tooltip_SetTipTextColor (BYVAL hTooltip AS DWORD, BYVAL clr AS DWORD)
   SendMessage hTooltip, %TTM_SETTIPTEXTCOLOR, clr, 0
END SUB
' ========================================================================================

' ========================================================================================
' Adds a standard icon and title string to a ToolTip.
' ========================================================================================
FUNCTION Tooltip_SetTitleA (BYVAL hTooltip AS DWORD, BYVAL nIcon AS LONG, BYVAL strTitle AS STRING) AS LONG
   FUNCTION = SendMessage(hTooltip, %TTM_SETTITLEA, nIcon, STRPTR(strTitle))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Tooltip_SetTitleW (BYVAL hTooltip AS DWORD, BYVAL nIcon AS LONG, BYVAL bstrTitle AS WSTRING) AS LONG
   FUNCTION = SendMessage(hTooltip, %TTM_SETTITLEW, nIcon, STRPTR(bstrTitle))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Tooltip_SetTitle = Tooltip_SetTitleW
#ELSE
   MACRO Tooltip_SetTitle = Tooltip_SetTitleA
#ENDIF

' ========================================================================================
' Sets the information that a ToolTip control maintains for a tool.
' ========================================================================================
SUB Tooltip_SetToolInfo (BYVAL hTooltip AS DWORD, BYREF lpti AS TOOLINFO)
   SendMessage hTooltip, %TTM_SETTOOLINFO, 0, VARPTR(lpti)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the visual style of a ToolTip control.
' ========================================================================================
SUB Tooltip_SetWindowTheme (BYVAL hTooltip AS DWORD, BYVAL bstrTheme AS WSTRING)
   SendMessage hTooltip, %TTM_SETWINDOWTHEME, 0, STRPTR(bstrTheme)
END SUB
' ========================================================================================

' ========================================================================================
' Activates or deactivates a tracking ToolTip.
' ========================================================================================
SUB Tooltip_TrackActivate (BYVAL hTooltip AS DWORD, BYVAL bActivate AS LONG, BYREF lpti AS TOOLINFO)
   SendMessage hTooltip, %TTM_TRACKACTIVATE, bActivate, VARPTR(lpti)
END SUB
' ========================================================================================

' ========================================================================================
' Activates or deactivates a tracking ToolTip.
' ========================================================================================
SUB Tooltip_TrackPosition (BYVAL hTooltip AS DWORD, BYVAL xPos AS LONG, BYVAL yPos AS LONG)
   SendMessage hTooltip, %TTM_TRACKPOSITION, 0, MAK(LONG, xPos, yPos)
END SUB
' ========================================================================================

' ========================================================================================
' Activates or deactivates a tracking ToolTip.
' ========================================================================================
SUB Tooltip_Update (BYVAL hTooltip AS DWORD)
   SendMessage hTooltip, %TTM_UPDATE, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the ToolTip text for a tool.
' ========================================================================================
SUB Tooltip_UpdateTipText (BYVAL hTooltip AS DWORD, BYREF lpti AS TOOLINFO)
   SendMessage hTooltip, %TTM_UPDATETIPTEXT, 0, VARPTR(lpti)
END SUB
' ========================================================================================

' ========================================================================================
' Allows a subclass procedure to cause a ToolTip to display text for a window other than
' the one beneath the mouse cursor.
' ========================================================================================
FUNCTION Tooltip_WindowFromPoint (BYVAL hTooltip AS DWORD, BYREF lppt AS POINT) AS LONG
   FUNCTION = SendMessage (hTooltip, %TTM_WINDOWFROMPOINT, 0, VARPTR(lppt))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a tooltip for a control.
' Parameters:
' - hwndCtrl = Handle of the control
' - strTooltipText = Tooltip text
' - bBalloon = Ballon tip (TRUE or FALSE)
' - bCentered = Centered (TRUE or FALSE)
' Return Value:
'   The handle of the tooltip control
' ========================================================================================
FUNCTION Tooltip_AddA (BYVAL hwndCtrl AS DWORD, BYVAL strTooltipText AS STRING, _
   OPTIONAL BYVAL bBalloon AS LONG, OPTIONAL BYVAL bCentered AS LONG) AS DWORD

   IF hwndCtrl = 0 THEN EXIT FUNCTION
   LOCAL hwndTT AS DWORD
   LOCAL dwStyle AS DWORD
   dwStyle = %WS_POPUP OR %TTS_ALWAYSTIP
   IF bBalloon THEN dwStyle = dwStyle OR %TTS_BALLOON
   hwndTT = CreateWindowExA(0, "tooltips_class32", "", dwStyle, 0, 0, 0, 0, 0, 0, %NULL, BYVAL %NULL)
   IF hwndTT = %NULL THEN EXIT FUNCTION
   ' // Retrieve the version of CommCtl32.dll
   LOCAL pvsffi AS VS_FIXEDFILEINFO PTR
   LOCAL pVerInfo AS DWORD
   LOCAL dwHandle AS DWORD
   LOCAL dwVersion AS DWORD
   LOCAL cbLen AS DWORD
   LOCAL wMajor AS WORD
   LOCAL wMinor AS WORD
   cbLen = GetFileVersionInfoSizeA("COMCTL32.DLL", dwHandle)
   IF cbLen THEN
      pVerInfo = HeapAlloc(GetProcessHeap, %HEAP_ZERO_MEMORY, cbLen)
      IF pVerInfo THEN
         IF GetFileVersionInfoA("COMCTL32.DLL", dwHandle, cbLen, BYVAL pVerInfo) THEN
            IF VerQueryValueA(BYVAL pVerInfo, "\", BYVAL VARPTR(pvsffi), cbLen) THEN
               wMajor = HI(WORD, @pvsffi.dwFileVersionMS)
               wMinor = LO(WORD, @pvsffi.dwFileVersionMS)
            END IF
         END IF
         HeapFree GetProcessHeap, 0, pVerInfo
      END IF
   END IF
   ' // Register the window with the tooltip control
   LOCAL tti AS TOOLINFOA
   tti.cbSize = SIZEOF(tti)
   ' // The size of the TOOLINFO structure is of 48 bytes in version 6
   ' // of comctl32.dll, and of 44 bytes in lower versions.
   IF wMajor < 6 THEN tti.cbSize = 44
   tti.uFlags = %TTF_IDISHWND OR %TTF_SUBCLASS
   IF bCentered THEN tti.uFlags = tti.uFlags OR %TTF_CENTERTIP
   tti.hwnd = GetParent(hwndCtrl)
   tti.hinst = GetModuleHandleA(BYVAL %NULL)
   ' // The length of the string must not exceed of 80 characters, including the terminating null
'   IF LEN(strTooltipText) > 79 THEN strTooltipText = LEFT$(strTooltipText, 79)
   tti.lpszText = STRPTR(strTooltipText)
   tti.uId = hwndCtrl
   SendMessageA hwndTT, %TTM_ADDTOOLA, 0, VARPTR(tti)
   FUNCTION = hwndTT

END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION Tooltip_AddW (BYVAL hwndCtrl AS DWORD, BYVAL bstrTooltipText AS WSTRING, _
   OPTIONAL BYVAL bBalloon AS LONG, OPTIONAL BYVAL bCentered AS LONG) AS DWORD

   IF hwndCtrl = 0 THEN EXIT FUNCTION
   LOCAL hwndTT AS DWORD
   LOCAL dwStyle AS DWORD
   dwStyle = %WS_POPUP OR %TTS_ALWAYSTIP
   IF bBalloon THEN dwStyle = dwStyle OR %TTS_BALLOON
   hwndTT = CreateWindowExW(0, "tooltips_class32", "", dwStyle, 0, 0, 0, 0, 0, 0, %NULL, BYVAL %NULL)
   IF hwndTT = %NULL THEN EXIT FUNCTION
   ' // Retrieve the version of CommCtl32.dll
   LOCAL pvsffi AS VS_FIXEDFILEINFO PTR
   LOCAL pVerInfo AS DWORD
   LOCAL dwHandle AS DWORD
   LOCAL dwVersion AS DWORD
   LOCAL cbLen AS DWORD
   LOCAL wMajor AS WORD
   LOCAL wMinor AS WORD
   cbLen = GetFileVersionInfoSizeW("COMCTL32.DLL", dwHandle)
   IF cbLen THEN
      pVerInfo = HeapAlloc(GetProcessHeap, %HEAP_ZERO_MEMORY, cbLen)
      IF pVerInfo THEN
         IF GetFileVersionInfoW("COMCTL32.DLL", dwHandle, cbLen, BYVAL pVerInfo) THEN
            IF VerQueryValueW(BYVAL pVerInfo, "\", BYVAL VARPTR(pvsffi), cbLen) THEN
               wMajor = HI(WORD, @pvsffi.dwFileVersionMS)
               wMinor = LO(WORD, @pvsffi.dwFileVersionMS)
            END IF
         END IF
         HeapFree GetProcessHeap, 0, pVerInfo
      END IF
   END IF
   ' // Register the window with the tooltip control
   LOCAL tti AS TOOLINFOW
   tti.cbSize = SIZEOF(tti)
   ' // The size of the TOOLINFO structure is of 48 bytes in version 6
   ' // of comctl32.dll, and of 44 bytes in lower versions.
   IF wMajor < 6 THEN tti.cbSize = 44
   tti.uFlags = %TTF_IDISHWND OR %TTF_SUBCLASS
   IF bCentered THEN tti.uFlags = tti.uFlags OR %TTF_CENTERTIP
   tti.hinst = GetModuleHandleW(BYVAL %NULL)
   tti.hwnd = GetParent(hwndCtrl)
   tti.uId = hwndCtrl
   ' // The length of the string must not exceed of 80 characters, including the terminating null
'   IF LEN(bstrTooltipText) > 79 THEN bstrTooltipText = LEFT$(bstrTooltipText, 79)
   tti.lpszText = STRPTR(bstrTooltipText)
   SendMessageW hwndTT, %TTM_ADDTOOLW, 0, VARPTR(tti)
   FUNCTION = hwndTT

END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Tooltip_Add = Tooltip_AddW
#ELSE
   MACRO Tooltip_Add = Tooltip_AddA
#ENDIF

' ========================================================================================
' Removes a tool from a tooltip control.
' Parameters:
' - hTooltip = Handle of the tooltip control
' - hwndCtrl = Handle of the control
' ========================================================================================
SUB Tooltip_DeleteA (BYVAL hTooltip AS DWORD, BYVAL hwndCtrl AS DWORD)

   IF hTooltip = 0 OR hwndCtrl = 0 THEN EXIT SUB
   ' // Retrieve the version of CommCtl32.dll
   LOCAL pvsffi AS VS_FIXEDFILEINFO PTR
   LOCAL pVerInfo AS DWORD
   LOCAL dwHandle AS DWORD
   LOCAL dwVersion AS DWORD
   LOCAL cbLen AS DWORD
   LOCAL wMajor AS WORD
   LOCAL wMinor AS WORD
   cbLen = GetFileVersionInfoSizeA("COMCTL32.DLL", dwHandle)
   IF cbLen THEN
      pVerInfo = HeapAlloc(GetProcessHeap, %HEAP_ZERO_MEMORY, cbLen)
      IF pVerInfo THEN
         IF GetFileVersionInfoA("COMCTL32.DLL", dwHandle, cbLen, BYVAL pVerInfo) THEN
            IF VerQueryValueA(BYVAL pVerInfo, "\", BYVAL VARPTR(pvsffi), cbLen) THEN
               wMajor = HI(WORD, @pvsffi.dwFileVersionMS)
               wMinor = LO(WORD, @pvsffi.dwFileVersionMS)
            END IF
         END IF
         HeapFree GetProcessHeap, 0, pVerInfo
      END IF
   END IF
   ' // The size of the TOOLINFO structure is of 48 bytes in version 6
   ' // of comctl32.dll, and of 44 bytes in lower versions.
   LOCAL tti AS TOOLINFOA
   tti.cbSize = SIZEOF(tti)
   IF wMajor < 6 THEN tti.cbSize = 44
   tti.hwnd = GetParent(hwndCtrl)
   tti.uId = hwndCtrl
   ' // Remove the tooltip
   SendMessageA(hTooltip, %TTM_DELTOOLA, 0, VARPTR(tti))

END SUB
' ========================================================================================

' ========================================================================================
SUB Tooltip_DeleteW (BYVAL hTooltip AS DWORD, BYVAL hwndCtrl AS DWORD)

   IF hTooltip = 0 OR hwndCtrl = 0 THEN EXIT SUB
   ' // Retrieve the version of CommCtl32.dll
   LOCAL pvsffi AS VS_FIXEDFILEINFO PTR
   LOCAL pVerInfo AS DWORD
   LOCAL dwHandle AS DWORD
   LOCAL dwVersion AS DWORD
   LOCAL cbLen AS DWORD
   LOCAL wMajor AS WORD
   LOCAL wMinor AS WORD
   cbLen = GetFileVersionInfoSizeW("COMCTL32.DLL", dwHandle)
   IF cbLen THEN
      pVerInfo = HeapAlloc(GetProcessHeap, %HEAP_ZERO_MEMORY, cbLen)
      IF pVerInfo THEN
         IF GetFileVersionInfoW("COMCTL32.DLL", dwHandle, cbLen, BYVAL pVerInfo) THEN
            IF VerQueryValueW(BYVAL pVerInfo, "\", BYVAL VARPTR(pvsffi), cbLen) THEN
               wMajor = HI(WORD, @pvsffi.dwFileVersionMS)
               wMinor = LO(WORD, @pvsffi.dwFileVersionMS)
            END IF
         END IF
         HeapFree GetProcessHeap, 0, pVerInfo
      END IF
   END IF
   ' // The size of the TOOLINFO structure is of 48 bytes in version 6
   ' // of comctl32.dll, and of 44 bytes in lower versions.
   LOCAL tti AS TOOLINFOW
   tti.cbSize = SIZEOF(tti)
   IF wMajor < 6 THEN tti.cbSize = 44
   tti.hwnd = GetParent(hwndCtrl)
   tti.uId = hwndCtrl
   ' // Remove the tooltip
   SendMessageW(hTooltip, %TTM_DELTOOLW, 0, VARPTR(tti))

END SUB
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Tooltip_Delete = Tooltip_DeleteW
#ELSE
   MACRO Tooltip_Delete = Tooltip_DeleteA
#ENDIF

' ========================================================================================
' Sets/replaces the text of a tooltip control
' Parameters:
' - hTooltip = Handle of the tooltip control
' - hwndCtrl = Handle of the control
' ========================================================================================
SUB Tooltip_SetTextA (BYVAL hTooltip AS DWORD, BYVAL hwndCtrl AS DWORD, BYVAL strTooltipText AS STRING)

   IF hTooltip = 0 OR hwndCtrl = 0 THEN EXIT SUB
   ' // Retrieve the version of CommCtl32.dll
   LOCAL pvsffi AS VS_FIXEDFILEINFO PTR
   LOCAL pVerInfo AS DWORD
   LOCAL dwHandle AS DWORD
   LOCAL dwVersion AS DWORD
   LOCAL cbLen AS DWORD
   LOCAL wMajor AS WORD
   LOCAL wMinor AS WORD
   cbLen = GetFileVersionInfoSizeA("COMCTL32.DLL", dwHandle)
   IF cbLen THEN
      pVerInfo = HeapAlloc(GetProcessHeap, %HEAP_ZERO_MEMORY, cbLen)
      IF pVerInfo THEN
         IF GetFileVersionInfoA("COMCTL32.DLL", dwHandle, cbLen, BYVAL pVerInfo) THEN
            IF VerQueryValueA(BYVAL pVerInfo, "\", BYVAL VARPTR(pvsffi), cbLen) THEN
               wMajor = HI(WORD, @pvsffi.dwFileVersionMS)
               wMinor = LO(WORD, @pvsffi.dwFileVersionMS)
            END IF
         END IF
         HeapFree GetProcessHeap, 0, pVerInfo
      END IF
   END IF
   ' // The size of the TOOLINFO structure is of 48 bytes in version 6
   ' // of comctl32.dll, and of 44 bytes in lower versions.
   LOCAL tti AS TOOLINFOA
   tti.cbSize = SIZEOF(tti)
   IF wMajor < 6 THEN tti.cbSize = 44
   tti.hwnd = GetParent(hwndCtrl)
   tti.uId = hwndCtrl
   ' // Retrieve the tooltip information
   IF SendMessageA(hTooltip, %TTM_GETTOOLINFOA, 0, VARPTR(tti)) THEN
      ' // The length of the string must not exceed of 80 characters, including the terminating null
      IF LEN(strTooltipText) > 79 THEN strTooltipText = LEFT$(strTooltipText, 79)
      tti.lpszText = STRPTR(strTooltipText)
      SendMessageA hTooltip, %TTM_SETTOOLINFOA, 0, VARPTR(tti)
   END IF

END SUB
' ========================================================================================

' ========================================================================================
SUB Tooltip_SetTextW (BYVAL hTooltip AS DWORD, BYVAL hwndCtrl AS DWORD, BYVAL bstrTooltipText AS WSTRING)

   IF hTooltip = 0 OR hwndCtrl = 0 THEN EXIT SUB
   ' // Retrieve the version of CommCtl32.dll
   LOCAL pvsffi AS VS_FIXEDFILEINFO PTR
   LOCAL pVerInfo AS DWORD
   LOCAL dwHandle AS DWORD
   LOCAL dwVersion AS DWORD
   LOCAL cbLen AS DWORD
   LOCAL wMajor AS WORD
   LOCAL wMinor AS WORD
   cbLen = GetFileVersionInfoSizeW("COMCTL32.DLL", dwHandle)
   IF cbLen THEN
      pVerInfo = HeapAlloc(GetProcessHeap, %HEAP_ZERO_MEMORY, cbLen)
      IF pVerInfo THEN
         IF GetFileVersionInfoW("COMCTL32.DLL", dwHandle, cbLen, BYVAL pVerInfo) THEN
            IF VerQueryValueW(BYVAL pVerInfo, "\", BYVAL VARPTR(pvsffi), cbLen) THEN
               wMajor = HI(WORD, @pvsffi.dwFileVersionMS)
               wMinor = LO(WORD, @pvsffi.dwFileVersionMS)
            END IF
         END IF
         HeapFree GetProcessHeap, 0, pVerInfo
      END IF
   END IF
   ' // The size of the TOOLINFO structure is of 48 bytes in version 6
   ' // of comctl32.dll, and of 44 bytes in lower versions.
   LOCAL tti AS TOOLINFOW
   tti.cbSize = SIZEOF(tti)
   IF wMajor < 6 THEN tti.cbSize = 44
   tti.hwnd = GetParent(hwndCtrl)
   tti.uId = hwndCtrl
   ' // Retrieve the tooltip information
   IF SendMessageW(hTooltip, %TTM_GETTOOLINFOW, 0, VARPTR(tti)) THEN
      ' // The length of the string must not exceed of 80 characters, including the terminating null
      IF LEN(bstrTooltipText) > 79 THEN bstrTooltipText = LEFT$(bstrTooltipText, 79)
      tti.lpszText = STRPTR(bstrTooltipText)
      SendMessageW hTooltip, %TTM_SETTOOLINFOW, 0, VARPTR(tti)
   END IF

END SUB
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Tooltip_SetText = Tooltip_SetTextW
#ELSE
   MACRO Tooltip_SetText = Tooltip_SetTextA
#ENDIF

' ========================================================================================
' Retrieves the handle of the font used by the ToolTip control.
' ========================================================================================
FUNCTION Tooltip_GetFont (BYVAL hTooltip AS DWORD) AS DWORD
   FUNCTION = SendMessage(hTooltip, %WM_GETFONT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the font used by the ToolTip control.
' Parameters:
' - hTooltip  = Handle to the ToolTip control.
' - hFont   = Handle to the font. If this parameter is NULL, the control uses the default system font to draw text.
' - fRedraw = Specifies whether the control should be redrawn immediately upon setting the font.
'             If this parameter is TRUE, the control redraws itself.
' ========================================================================================
SUB Tooltip_SetFont (BYVAL hTooltip AS DWORD, OPTIONAL BYVAL hFont AS DWORD, OPTIONAL BYVAL fRedraw AS LONG)
   SendMessage hTooltip, %WM_SETFONT, hFont, fRedraw
END SUB
' ========================================================================================
