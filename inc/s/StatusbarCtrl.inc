' ########################################################################################
' Microsoft Windows
' File: StatusbarCtrl.inc
' Contents: Statusbar Control Wrapper Functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%STATUSBARCTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"

' ========================================================================================
' Retrieves the current widths of the horizontal, and vertical borders of a status window,
' and the width of the border between rectangles.
' ========================================================================================
FUNCTION StatusBar_GetBorders (BYVAL hStatusBar AS DWORD, BYREF aBorders AS LONG) AS LONG
   FUNCTION = SendMessage (hStatusBar, %SB_GETBORDERS, 0, VARPTR(aBorders))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the icon for a part in a status bar.
' ========================================================================================
FUNCTION StatusBar_GetIcon (BYVAL hStatusBar AS DWORD, BYVAL nPart AS DWORD) AS DWORD
  FUNCTION = SendMessage (hStatusBar, %SB_GETICON, nPart, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a count of the parts in a status window. The message also retrieves the
' coordinate of the right edge of the specified number of parts.
' ========================================================================================
FUNCTION StatusBar_GetParts (BYVAL hStatusBar AS DWORD, BYVAL nParts AS DWORD, BYREF aRightCoord AS LONG) AS LONG
   FUNCTION = SendMessage (hStatusBar, %SB_GETPARTS, nParts, VARPTR(aRightCoord))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a count of the parts in a status window.
' ========================================================================================
FUNCTION StatusBar_GetPartsCount (BYVAL hStatusBar AS DWORD) AS DWORD
   FUNCTION = SendMessage (hStatusBar, %SB_GETPARTS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the bounding rectangle of a part in a status window.
' ========================================================================================
FUNCTION StatusBar_GetRect (BYVAL hStatusBar AS DWORD, BYVAL nPart AS DWORD, BYREF lprc AS RECT) AS LONG
   FUNCTION = SendMessage (hStatusBar, %SB_GETRECT, nPart, VARPTR(lprc))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the text from the specified part of a status window.
' ========================================================================================
FUNCTION StatusBar_GetTextA (BYVAL hStatusBar AS DWORD, BYVAL nPart AS DWORD) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   LOCAL dwResult AS DWORD
   dwResult = SendMessageA(hStatusBar, %SB_GETTEXTLENGTH, nPart, 0)
   nLen = LO(WORD, dwResult)
   buffer = SPACE$(nLen + 1)
   SendMessageA hStatusBar, %SB_GETTEXTA, nPart, STRPTR(buffer)
   FUNCTION = LEFT$(buffer, nLen)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION StatusBar_GetTextW (BYVAL hStatusBar AS DWORD, BYVAL nPart AS DWORD) AS WSTRING
   LOCAL nLen AS LONG
   LOCAL buffer AS WSTRING
   LOCAL dwResult AS DWORD
   dwResult = SendMessageW(hStatusBar, %SB_GETTEXTLENGTH, nPart, 0)
   nLen = LO(WORD, dwResult)
   buffer = SPACE$(nLen + 1)
   SendMessageW hStatusBar, %SB_GETTEXTW, nPart, STRPTR(buffer)
   FUNCTION = LEFT$(buffer, nLen)
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO StatusBar_GetText = StatusBar_GetTextW
#ELSE
   MACRO StatusBar_GetText = StatusBar_GetTextA
#ENDIF

' ========================================================================================
' Retrieves the type of operation used to draw the text.
' ========================================================================================
FUNCTION StatusBar_GetTextDrawingMode (BYVAL hStatusBar AS DWORD, BYVAL nPart AS DWORD) AS LONG
   LOCAL dwResult AS DWORD
   dwResult = SendMessage (hStatusBar, %SB_GETTEXTLENGTH, nPart, 0)
   FUNCTION = HI(WORD, dwResult)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the length, in characters, of the text from the specified part of a status window.
' ========================================================================================
FUNCTION StatusBar_GetTextLength (BYVAL hStatusBar AS DWORD, BYVAL nPart AS DWORD) AS LONG
   LOCAL dwResult AS DWORD
   dwResult = SendMessage (hStatusBar, %SB_GETTEXTLENGTH, nPart, 0)
   FUNCTION = LO(WORD, dwResult)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the tooltip text for a part in a status bar. The status bar must have been
' created with the SBT_TOOLTIPS style to enable tooltips.
' ========================================================================================
FUNCTION StatusBar_GetTipTextA (BYVAL hStatusBar AS DWORD, BYVAL nPart AS WORD) AS STRING
   LOCAL szBuffer AS ASCIIZ * 65535
   SendMessageA hStatusBar, %SB_GETTIPTEXTA, MAK(DWORD, nPart, SIZEOF(szBuffer)), VARPTR(szBuffer)
   FUNCTION = szBuffer
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION StatusBar_GetTipTextW (BYVAL hStatusBar AS DWORD, BYVAL nPart AS WORD) AS WSTRING
   LOCAL wszBuffer AS WSTRINGZ * 65535
   SendMessageW hStatusBar, %SB_GETTIPTEXTW, MAK(DWORD, nPart, SIZEOF(wszBuffer)), VARPTR(wszBuffer)
   FUNCTION = wszBuffer
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO StatusBar_GetTipText = StatusBar_GetTipTextW
#ELSE
   MACRO StatusBar_GetTipText = StatusBar_GetTipTextA
#ENDIF

' ========================================================================================
' Retrieves the Unicode character format flag for the control.
' ========================================================================================
FUNCTION StatusBar_GetUnicodeFormat (BYVAL hStatusBar AS DWORD) AS LONG
   FUNCTION = SendMessage (hStatusBar, %SB_GETUNICODEFORMAT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Checks a status bar control to determine if it is in simple mode.
' ========================================================================================
FUNCTION StatusBar_IsSimple (BYVAL hStatusBar AS DWORD) AS LONG
   FUNCTION = SendMessage (hStatusBar, %SB_ISSIMPLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the background color in a status bar.
' ========================================================================================
FUNCTION StatusBar_SetBkColor (BYVAL hStatusBar AS DWORD, BYVAL clrBk AS DWORD) AS DWORD
   FUNCTION = SendMessage (hStatusBar, %SB_SETBKCOLOR, 0, clrBk)
END FUNCTION
' ========================================================================================

' ========================================================================================
'  Sets the font that the status bar is to use when drawing text.
' ========================================================================================
SUB StatusBar_SetFont (BYVAL hStatusBar AS DWORD, BYVAL hFont AS DWORD, OPTIONAL BYVAL fRedraw AS LONG)
   SendMessage hStatusBar, %WM_SETFONT, hFont, fRedraw
END SUB
' ========================================================================================

' ========================================================================================
' Sets the icon for a part in a status bar.
' ========================================================================================
FUNCTION StatusBar_SetIcon (BYVAL hStatusBar AS DWORD, BYVAL nPart AS LONG, BYVAL hIcon AS DWORD) AS LONG
   FUNCTION = SendMessage (hStatusBar, %SB_SETICON, nPart, hIcon)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the minimum length, in pixels, of a status window's drawing area.
' ========================================================================================
SUB StatusBar_SetMinHeight (BYVAL hStatusBar AS DWORD, BYVAL minHeight AS DWORD)
   SendMessage hStatusBar, %SB_SETMINHEIGHT, minHeight, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the text in the specified part of an ownerdraw status window.
' The message invalidates the portion of the window that has changed, causing it to
' display the new text when the window next receives the WM_PAINT message.
'
' To show the text of the status bar with the foreground and background colors that you
' like, you only need to set the text with StatusBar_SetOwnerDrawText,
' e.g. StatusBar_SetOwnerDrawText hStatus, 1, "Part 1", add in your main dialog callback:
'
' *** SDK ***
' CASE %WM_DRAWITEM
'    ' Ownerdraw statusbar
'    IF wParam = %ID_STATUSBAR THEN
'       Statusbar_DrawItem lParam
'    END IF
'    FUNCTION = 1
'
' *** DDT ***
' CASE %WM_DRAWITEM
'    ' Ownerdraw statusbar
'    IF CBWPARAM = %ID_STATUSBAR THEN
'       Statusbar_DrawItem CBLPARAM
'    END IF
'    FUNCTION = 1
'
' and include in your program a SUB like the listed below:

' SUB Statusbar_DrawItem (BYVAL lParam AS LONG)
'
'    LOCAL lpdis AS DRAWITEMSTRUCT PTR
'    LOCAL zp AS ASCIIZ PTR
'    LOCAL hBrush AS DWORD
'    LOCAL clrFg AS DWORD
'    LOCAL clrBk AS DWORD
'
'    lpdis = lParam
'
'    DECR @lpdis.rcItem.nRight
'    DECR @lpdis.rcItem.nBottom
'
'    clrBk = %BLUE
'    clrFg = %WHITE
'
'    SELECT CASE @lpdis.itemID
'       CASE 1 : clrBk = %YELLOW : clrFg = %RED
'       CASE 2 : clrBk = %RED : clrFg = %YELLOW
'       CASE 3 : clrBk = RGB(0,160,0) : clrFg = %WHITE
'    END SELECT
'
'    hBrush = CreateSolidBrush(clrBk)
'    FillRect @lpdis.hDC, @lpdis.rcItem, hBrush
'    SetBkColor @lpdis.hDC, clrBk
'    SetTextColor @lpdis.hDC, clrFg
'    DeleteObject hBrush
'
'    zp = @lpdis.itemData
'    DrawText @lpdis.hDC, @zp, LEN(@zp), @lpdis.rcItem, %DT_SINGLELINE OR %DT_VCENTER
'
'END SUB
' ========================================================================================
FUNCTION StatusBar_SetOwnerdrawTextA (BYVAL hStatusBar AS DWORD, BYVAL nPart AS DWORD, BYVAL strText AS STRING, OPTIONAL BYVAL uType AS DWORD) AS LONG
   DIM strTxt(0) AS STRING
   LOCAL nCount AS DWORD
   IF nCount = 0 THEN
      nCount = StatusBar_GetPartsCount(hStatusBar)
      REDIM strTxt(nCount)
   END IF
   IF nPart > nCount THEN EXIT FUNCTION
   strTxt(nPart) = strText
   FUNCTION = SendMessageA(hStatusBar, %SB_SETTEXTA, nPart OR %SBT_OWNERDRAW OR uType, STRPTR(strTxt(nPart)))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION StatusBar_SetOwnerdrawTextW (BYVAL hStatusBar AS DWORD, BYVAL nPart AS DWORD, BYVAL bstrText AS WSTRING, OPTIONAL BYVAL uType AS DWORD) AS LONG
   DIM bstrTxt(0) AS WSTRING
   LOCAL nCount AS DWORD
   IF nCount = 0 THEN
      nCount = StatusBar_GetPartsCount(hStatusBar)
      REDIM bstrTxt(nCount)
   END IF
   IF nPart > nCount THEN EXIT FUNCTION
   bstrTxt(nPart) = bstrText
   FUNCTION = SendMessageW(hStatusBar, %SB_SETTEXTW, nPart OR %SBT_OWNERDRAW OR uType, STRPTR(bstrTxt(nPart)))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO StatusBar_SetOwnerdrawText = StatusBar_SetOwnerdrawTextW
#ELSE
   MACRO StatusBar_SetOwnerdrawText = StatusBar_SetOwnerdrawTextA
#ENDIF

' ========================================================================================
' Sets the number of parts in a status window and the coordinate of the right edge of each part.
' ========================================================================================
FUNCTION StatusBar_SetParts (BYVAL hStatusBar AS DWORD, BYVAL dwParts AS DWORD, BYREF aWidths AS LONG) AS LONG
   FUNCTION = SendMessage (hStatusBar, %SB_SETPARTS, dwParts, VARPTR(aWidths))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets n parts of an existing status bar.
' strSizes = Comma delited string of desired sizes. e.g.:  strSizes = "90,34,42,184"
' creates 4 parts of 90, 34, 42 and 184 pixels, and strSizes = "90,34,42,184,-1" creates
' 5 parts, the last one extending until the right border of the window.
' ========================================================================================
FUNCTION StatusBar_SetPartsBySizeW (BYVAL hStatusBar AS DWORD, BYVAL bstrSizes AS WSTRING) AS LONG

   LOCAL nParts AS LONG
   LOCAL X AS LONG
   LOCAL Y AS LONG

   nParts = MAX(PARSECOUNT(bstrSizes),1)
   IF nParts < 2 THEN
      FUNCTION = SendMessageW(hStatusBar, %SB_SIMPLE, (nParts = 1), 0)
      EXIT FUNCTION
   END IF

   DIM Part(1 TO nParts) AS LOCAL LONG

   FOR X = 1 TO nParts
      Y = VAL(PARSE$(bstrSizes, ",", X))
      IF X = 1 THEN
         Part(X) = Y
      ELSE
         IF Y < 1 THEN
            Part(X) = -1
         ELSE
            Part(X) = Part(X - 1) + Y
         END IF
      END IF
   NEXT

   IF SendMessageW(hStatusBar, %SB_SETPARTS, nParts, VARPTR(Part(1))) <> 0 THEN
      FUNCTION = SendMessageW(hStatusBar, %SB_SIMPLE, (nParts = 1), 0)
   END IF

END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION StatusBar_SetPartsBySizeA (BYVAL hStatusBar AS DWORD, BYVAL strSizes AS STRING) AS LONG

   LOCAL nParts AS LONG
   LOCAL X AS LONG
   LOCAL Y AS LONG

   nParts = MAX(PARSECOUNT(strSizes),1)
   IF nParts < 2 THEN
      FUNCTION = SendMessageA(hStatusBar, %SB_SIMPLE, (nParts = 1), 0)
      EXIT FUNCTION
   END IF

   DIM Part(1 TO nParts) AS LOCAL LONG

   FOR X = 1 TO nParts
      Y = VAL(PARSE$(strSizes, ",", X))
      IF X = 1 THEN
         Part(X) = Y
      ELSE
         IF Y < 1 THEN
            Part(X) = -1
         ELSE
            Part(X) = Part(X - 1) + Y
         END IF
      END IF
   NEXT

   IF SendMessageA(hStatusBar, %SB_SETPARTS, nParts, VARPTR(Part(1))) <> 0 THEN
      FUNCTION = SendMessageA(hStatusBar, %SB_SIMPLE, (nParts = 1), 0)
   END IF

END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO StatusBar_SetPartsBySize = StatusBar_SetPartsBySizeW
#ELSE
   MACRO StatusBar_SetPartsBySize = StatusBar_SetPartsBySizeA
#ENDIF

' ========================================================================================
' Sets the text in the specified part of a status window.
' ========================================================================================
FUNCTION StatusBar_SetTextA (BYVAL hStatusBar AS DWORD, BYVAL nPart AS LONG, BYVAL strText AS STRING, OPTIONAL BYVAL uType AS DWORD) AS LONG
   FUNCTION = SendMessageA(hStatusBar, %SB_SETTEXTA, nPart OR uType, STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION StatusBar_SetTextW (BYVAL hStatusBar AS DWORD, BYVAL nPart AS LONG, BYVAL bstrText AS WSTRING, OPTIONAL BYVAL uType AS DWORD) AS LONG
   FUNCTION = SendMessageW(hStatusBar, %SB_SETTEXTW, nPart OR uType, STRPTR(bstrText))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO StatusBar_SetText = StatusBar_SetTextW
#ELSE
   MACRO StatusBar_SetText = StatusBar_SetTextA
#ENDIF

' ========================================================================================
' Sets the tooltip text for a part in a status bar.
' ========================================================================================
SUB StatusBar_SetTipTextA (BYVAL hStatusBar AS DWORD, BYVAL nPart AS LONG, BYVAL strTipText AS STRING)
   SendMessage hStatusBar, %SB_SETTIPTEXTA, nPart, STRPTR(strTipText)
END SUB
' ========================================================================================
' ========================================================================================
SUB StatusBar_SetTipTextW (BYVAL hStatusBar AS DWORD, BYVAL nPart AS LONG, BYVAL bstrTipText AS WSTRING)
   SendMessage hStatusBar, %SB_SETTIPTEXTW, nPart, STRPTR(bstrTipText)
END SUB
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO StatusBar_SetTipText = StatusBar_SetTipTextW
#ELSE
   MACRO StatusBar_SetTipText = StatusBar_SetTipTextA
#ENDIF

' ========================================================================================
' Sets the Unicode character format flag for the control. This message allows you to
' change the character set used by the control at run time rather than having to re-create
' the control.
' ========================================================================================
FUNCTION StatusBar_SetUnicodeFormat (BYVAL hStatusBar AS DWORD, BYVAL fUnicode AS LONG) AS LONG
   FUNCTION = SendMessage (hStatusBar, %SB_SETUNICODEFORMAT, fUnicode, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Specifies whether a status window displays simple text or displays all window parts set
' by a previous SB_SETPARTS message.
' ========================================================================================
SUB StatusBar_Simple (BYVAL hStatusBar AS DWORD, BYVAL fSimple AS LONG)
   SendMessage (hStatusBar, %SB_SIMPLE, fSimple, 0)
END SUB
' ========================================================================================

' ========================================================================================
' Returns the height of the status bar.
' ========================================================================================
FUNCTION StatusBar_GetHeight (BYVAL hStatusBar AS DWORD) AS LONG
   LOCAL rc AS RECT
   GetWindowRect(hStatusbar, rc)
   FUNCTION = rc.Bottom - rc.Top
END FUNCTION
' ========================================================================================
