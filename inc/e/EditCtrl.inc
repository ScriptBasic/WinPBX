' ########################################################################################
' Microsoft Windows
' File: EditCtrl.inc
' Contents: Edit Control wrapper functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%EDITCTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"

' ========================================================================================
' Determines whether there are any actions in an edit control's undo queue. You can send
' this message to either an edit control or a rich edit control.
' ========================================================================================
FUNCTION Edit_CanUndo (BYVAL hEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_CANUNDO, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets information about the character closest to a specified point in the client area of
' an edit control. You can send this message to either an edit control or a rich edit control.
' ========================================================================================
FUNCTION Edit_CharFromPos (BYVAL hEdit AS DWORD, BYVAL x AS INTEGER, BYVAL y AS INTEGER) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_CHARFROMPOS, 0, MAK(LONG, x, y))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes (clears) the current selection, if any, from the edit control.
' ========================================================================================
SUB Edit_Clear (BYVAL hEdit AS DWORD)
   SendMessage hEdit, %WM_CLEAR, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Copies the current selection to the clipboard in CF_TEXT format.
' ========================================================================================
SUB Edit_Copy (BYVAL hEdit AS DWORD)
   SendMessage hEdit, %WM_COPY, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Deletes (cuts) the current selection, if any, in the edit control and copy the deleted
' text to the clipboard in CF_TEXT format.
' ========================================================================================
SUB Edit_Cut (BYVAL hEdit AS DWORD)
   SendMessage hEdit, %WM_CUT, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Resets the undo flag of an edit control. The undo flag is set whenever an operation
' within the edit control can be undone.
' ========================================================================================
SUB Edit_EmptyUndoBuffer (BYVAL hEdit AS DWORD)
   SendMessage hEdit, %EM_EMPTYUNDOBUFFER, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Enables or disables an edit control.
' ========================================================================================
FUNCTION Edit_Enable (BYVAL hEdit AS DWORD, BYVAL fEnable AS LONG) AS LONG
   FUNCTION = EnableWindow(hEdit, fEnable)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets a flag that determines whether a multiline edit control includes soft line-break
' characters. A soft line break consists of two carriage returns and a line feed and is
' inserted at the end of a line that is broken because of wordwrapping.
' ========================================================================================
FUNCTION Edit_FmtLines (BYVAL hEdit AS LONG, BYVAL AddEolFlag AS LONG) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_FMTLINES, ISTRUE(AddEolFlag) AND 1, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the text that is displayed as the textual cue, or tip, in an edit control.
' ========================================================================================
FUNCTION Edit_GetCueBannerText (BYVAL hEdit AS DWORD, BYREF lpwText AS WSTRINGZ, BYVAL cchText AS LONG) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_GETCUEBANNER, VARPTR(lpwText), cchText)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the zero-based index of the uppermost visible line in a multiline edit control.
' ========================================================================================
FUNCTION Edit_GetFirstVisibleLine (BYVAL hEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_GETFIRSTVISIBLELINE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets a handle of the memory currently allocated for a multiline edit control's text.
' ========================================================================================
FUNCTION Edit_GetHandle (BYVAL hEdit AS DWORD) AS DWORD
   FUNCTION = SendMessage(hEdit, %EM_GETHANDLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Not implemented.
' ========================================================================================
'FUNCTION Edit_GetHilite (BYVAL hEdit AS DWORD) AS LONG
'   FUNCTION = SendMessage(hEdit, %EM_GETHILITE, 0, 0)
'END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a set of status flags that indicate how the edit control interacts with the
' Input Method Editor (IME).
' ========================================================================================
FUNCTION Edit_GetIMEStatus (BYVAL hEdit AS DWORD, BYVAL nStatusType AS LONG) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_GETIMESTATUS, nStatusType, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current text limit for an edit control.
' ========================================================================================
FUNCTION Edit_GetLimitText (BYVAL hEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_GETLIMITTEXT, 0, 0)
END FUNCTION
' ========================================================================================

#IF %DEF(%USEPBDECL)
MACRO FUNCTION Edit_GetLine(hwndCtl, nline, lpch, cchMax)
    POKE LONG, lpch, cchMax
END MACRO=SendMessage(hwndCtl, %EM_GETLINE, nline, lpch)
#ELSE
' ========================================================================================
' Copies a line of text from an edit control.
' ========================================================================================
FUNCTION Edit_GetLineA (BYVAL hEdit AS DWORD, BYVAL which AS DWORD) AS STRING
   LOCAL buffer AS STRING
   LOCAL n AS LONG
   buffer = MKI$(32765) + STRING$(32765, 0)
   n = SendMessageA(hEdit, %EM_GETLINE, which, STRPTR(buffer))
   FUNCTION = LEFT$(buffer, n)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Edit_GetLineW (BYVAL hEdit AS DWORD, BYVAL which AS DWORD) AS WSTRING
   LOCAL buffer AS WSTRING
   LOCAL n AS LONG
   buffer = MKI$(32765) + STRING$$(32765, 0)
   n = SendMessageW(hEdit, %EM_GETLINE, which, STRPTR(buffer))
   FUNCTION = LEFT$(buffer, n)
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Edit_GetLine = Edit_GetLineW
#ELSE
   MACRO Edit_GetLine = Edit_GetLineA
#ENDIF
#ENDIF

' ========================================================================================
' Gets the number of lines in a multiline edit control.
' ========================================================================================
FUNCTION Edit_GetLineCount (BYVAL hEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_GETLINECOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the widths of the left and right margins for an edit control.
' ========================================================================================
FUNCTION Edit_GetMargins (BYVAL hEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_GETMARGINS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the width of the left margin for an edit control.
' ========================================================================================
FUNCTION Edit_GetLeftMargin (BYVAL hEdit AS DWORD) AS LONG
   FUNCTION = LO(WORD, SendMessage(hEdit, %EM_GETMARGINS, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the width of the right margin for an edit control.
' ========================================================================================
FUNCTION Edit_GetRightMargin (BYVAL hEdit AS DWORD) AS LONG
   FUNCTION = HI(WORD, SendMessage(hEdit, %EM_GETMARGINS, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the state of an edit control's modification flag. The flag indicates whether the
' contents of the edit control have been modified.
' ========================================================================================
FUNCTION Edit_GetModify (BYVAL hEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_GETMODIFY, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the password character that an edit control displays when the user enters text.
' ========================================================================================
FUNCTION Edit_GetPasswordChar (BYVAL hEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_GETPASSWORDCHAR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the formatting rectangle of an edit control. The formatting rectangle is the
' limiting rectangle into which the control draws the text. The limiting rectangle is
' independent of the size of the edit-control window.
' ========================================================================================
#IF %DEF(%USEPBDECL)
MACRO Edit_GetRect(hwndCtl, lprc)
    SendMessage hwndCtl, %EM_GETRECT, 0, lprc
END MACRO
#ELSE
SUB Edit_GetRect (BYVAL hEdit AS DWORD, BYREF rc AS RECT)
   SendMessage hEdit, %EM_GETRECT, 0, VARPTR(rc)
END SUB
#ENDIF
' ========================================================================================

' ========================================================================================
' Gets the starting and ending character positions of the current selection in an edit control.
' ========================================================================================
FUNCTION Edit_GetSel (BYVAL hEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_GETSEL, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the starting character position of the current selection in an edit control.
' ========================================================================================
FUNCTION Edit_GetSelStart (BYVAL hEdit AS DWORD) AS LONG
   FUNCTION = LO(WORD, SendMessage(hEdit, %EM_GETSEL, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the ending character position of the current selection in an edit control.
' ========================================================================================
FUNCTION Edit_GetSelEnd (BYVAL hEdit AS DWORD) AS LONG
   FUNCTION = HI(WORD, SendMessage(hEdit, %EM_GETSEL, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the text from an edit control.
' Note: GetWindowText cannot retrieve the text of a control in another application.
' ========================================================================================
'FUNCTION Edit_GetText (BYVAL hEdit AS LONG) AS STRING
'   LOCAL nLen   AS LONG
'   LOCAL buffer AS STRING
'   nLen = GetWindowTextLength(hEdit)
'   Buffer = SPACE$(nLen + 1)
'   GetWindowText hEdit, BYVAL STRPTR(Buffer), nLen + 1
'   FUNCTION = LEFT$(Buffer, nLen)
'END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Edit_GetTextA (BYVAL hEdit AS LONG) AS STRING
   LOCAL nLen   AS LONG
   LOCAL buffer AS STRING
   nLen = SendMessageA(hEdit, %WM_GETTEXTLENGTH, 0, 0)
   Buffer = SPACE$(nLen + 1)
   nLen = SendMessageA(hEdit, %WM_GETTEXT, nLen + 1, BYVAL STRPTR(Buffer))
   FUNCTION = LEFT$(Buffer, nLen)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Edit_GetTextW (BYVAL hEdit AS LONG) AS WSTRING
   LOCAL nLen   AS LONG
   LOCAL buffer AS WSTRING
   nLen = SendMessageW(hEdit, %WM_GETTEXTLENGTH, 0, 0)
   Buffer = SPACE$(nLen + 1)
   nLen = SendMessageW(hEdit, %WM_GETTEXT, nLen + 1, BYVAL STRPTR(Buffer))
   FUNCTION = LEFT$(Buffer, nLen)
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Edit_GetText = Edit_GetTextW
#ELSE
   MACRO Edit_GetText = Edit_GetTextA
#ENDIF

' ========================================================================================
' Retrieves the length of all text in an edit control.
' ========================================================================================
FUNCTION Edit_GetTextLength (BYVAL hEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hEdit, %WM_GETTEXTLENGTH, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the position of the scroll box (thumb) in the vertical scroll bar of a multiline
' edit control.
' ========================================================================================
FUNCTION Edit_GetThumb (BYVAL hEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_GETTHUMB, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the address of the current Wordwrap function.
' ========================================================================================
FUNCTION Edit_GetWordBreakProc (BYVAL hEdit AS DWORD) AS DWORD
   FUNCTION = SendMessage(hEdit, %EM_GETWORDBREAKPROC, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Hides any balloon tip associated with an edit control.
' ========================================================================================
FUNCTION Edit_HideBalloonTip (BYVAL hEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_HIDEBALLOONTIP, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the text limit of an edit control. The text limit is the maximum amount of text, in
' bytes, that the user can type into the edit control.
' ========================================================================================
SUB Edit_LimitText (BYVAL hEdit AS DWORD, BYVAL chMax AS DWORD)
   SendMessage hEdit, %EM_LIMITTEXT, chMax, 0
END SUB
' ========================================================================================

' ========================================================================================
' Gets the index of the line that contains the specified character index in a multiline
' edit control. A character index is the zero-based index of the character from the
' beginning of the edit control.
' ========================================================================================
FUNCTION Edit_LineFromChar (BYVAL hEdit AS DWORD, BYVAL index AS DWORD) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_LINEFROMCHAR, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the character index of the first character of a specified line in a multiline edit
' control. A character index is the zero-based index of the character from the beginning
' of the edit control.
' ========================================================================================
FUNCTION Edit_LineIndex (BYVAL hEdit AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_LINEINDEX, nLine, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the length, in characters, of a line in an edit control.
' ========================================================================================
FUNCTION Edit_LineLength (BYVAL hEdit AS DWORD, BYVAL index AS DWORD) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_LINELENGTH, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Scrolls the text in a multiline edit control.
' ========================================================================================
FUNCTION Edit_LineScroll (BYVAL hEdit AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_LINESCROLL, x, y)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Copies the current content of the clipboard to the edit control at the current caret
' position. Data is inserted only if the clipboard contains data in CF_TEXT format.
' ========================================================================================
SUB Edit_Paste (BYVAL hEdit AS DWORD)
   SendMessage hEdit, %WM_PASTE, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the client area coordinates of a specified character in an edit control.
' ========================================================================================
FUNCTION Edit_PosFromChar (BYVAL hEdit AS DWORD, BYVAL index AS DWORD) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_POSFROMCHAR, index, 0)
END FUNCTION
' ========================================================================================

#IF %DEF(%USEPBDECL)
MACRO Edit_ReplaceSel(hwndCtl, lpszReplace)
    SendMessage hwndCtl, %EM_REPLACESEL, 0, lpszReplace
END MACRO
#ELSE
' ========================================================================================
' Replaces the current selection in an edit control with the specified text.
' ========================================================================================
SUB Edit_ReplaceSelA (BYVAL hEdit AS DWORD, BYVAL bCanBeUndone AS LONG, BYVAL strText AS STRING)
   SendMessageA hEdit, %EM_REPLACESEL, bCanBeUndone, STRPTR(strText)
END SUB
' ========================================================================================
' ========================================================================================
SUB Edit_ReplaceSelW (BYVAL hEdit AS DWORD, BYVAL bCanBeUndone AS LONG, BYVAL bstrText AS WSTRING)
   SendMessageW hEdit, %EM_REPLACESEL, bCanBeUndone, STRPTR(bstrText)
END SUB
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Edit_ReplaceSel = Edit_ReplaceSelW
#ELSE
   MACRO Edit_ReplaceSel = Edit_ReplaceSelA
#ENDIF
#ENDIF

' ========================================================================================
' Scrolls the text vertically in a multiline edit control.
' ========================================================================================
FUNCTION Edit_Scroll (BYVAL hEdit AS DWORD, BYVAL nAction AS LONG) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_SCROLL, nAction, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Scrolls the text vertically in a multiline edit control.
' ========================================================================================
SUB Edit_ScrollCaret (BYVAL hEdit AS DWORD)
   SendMessage hEdit, %EM_SCROLLCARET, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the textual cue, or tip, that is displayed by the edit control to prompt the user
' for information.
' ========================================================================================
#IF %DEF(%USEPBDECL)
FUNCTION Edit_SetCueBannerText (BYVAL hwnd AS DWORD, lpcwText AS WSTRINGZ) AS LONG
    FUNCTION = SendMessage(hwnd, %EM_SETCUEBANNER, 0, VARPTR(lpcwText))
END FUNCTION
#ELSE
FUNCTION Edit_SetCueBannerText (BYVAL hEdit AS DWORD, BYVAL bstrText AS WSTRING) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_SETCUEBANNER, 0, STRPTR(bstrText))
END FUNCTION
#ENDIF
' ========================================================================================

' ========================================================================================
' Sets the text that is displayed as the textual cue, or tip, for an edit control.
' ========================================================================================
#IF %DEF(%USEPBDECL)
FUNCTION Edit_SetCueBannerTextFocused (BYVAL hwnd AS DWORD, _
    lpcwText AS WSTRINGZ, BYVAL fDrawFocused AS LONG) AS LONG
    FUNCTION = SendMessage(hwnd, %EM_SETCUEBANNER, fDrawFocused, VARPTR(lpcwText))
END FUNCTION
#ELSE
FUNCTION Edit_SetCueBannerTextFocused (BYVAL hEdit AS DWORD, BYVAL bstrText AS WSTRING, BYVAL fDrawFocused AS LONG) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_SETCUEBANNER, fDrawFocused, STRPTR(bstrText))
END FUNCTION
#ENDIF
' ========================================================================================

' ========================================================================================
' Sets the handle of the memory that will be used by a multiline edit control.
' ========================================================================================
SUB Edit_SetHandle (BYVAL hEdit AS DWORD, BYVAL hLocal AS DWORD)
   SendMessage hEdit, %EM_SETHANDLE, hLocal, 0
END SUB
' ========================================================================================

' ========================================================================================
' Not implemented.
' ========================================================================================
'FUNCTION Edit_SetHilite (BYVAL hEdit AS DWORD, BYVAL ichStart AS LONG, BYVAL ichEnd AS LONG) AS LONG
'   FUNCTION = SendMessage(hEdit, %EM_SETHILITE, ichStart, ichEnd)
'END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the status flags that determine how an edit control interacts with the Input Method
' Editor (IME).
' ========================================================================================
FUNCTION Edit_SetIMEStatus (BYVAL hEdit AS LONG, BYVAL nStatusType AS LONG, BYVAL flags AS LONG) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_SETIMESTATUS, nStatusType, flags)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the text limit of an edit control. The text limit is the maximum amount of text, in
' TCHARs, that the user can type into the edit control.
' ========================================================================================
SUB Edit_SetLimitText (BYVAL hEdit AS DWORD, BYVAL chMax AS DWORD)
   SendMessage hEdit, %EM_LIMITTEXT, chMax, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the widths of the left and right margins for an edit control. The message redraws
' the control to reflect the new margins.
' ========================================================================================
SUB Edit_SetMargins (BYVAL hEdit AS LONG, BYVAL nMargins AS LONG, BYVAL nWidth AS LONG)
   SendMessage hEdit, %EM_SETMARGINS, nMargins, nWidth
END SUB
' ========================================================================================

' ========================================================================================
' Sets the width of the left margin for an edit control. The message redraws the control
' to reflect the new margin.
' ========================================================================================
SUB Edit_SetLeftMargin (BYVAL hEdit AS LONG, BYVAL nWidth AS WORD)
   SendMessage hEdit, %EM_SETMARGINS, %EC_LEFTMARGIN, MAK(LONG, nWidth, 0)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the width of the right margin for an edit control. The message redraws the control
' to reflect the new margin.
' ========================================================================================
SUB Edit_SetRightMargin (BYVAL hEdit AS LONG, BYVAL nWidth AS WORD)
   SendMessage hEdit, %EM_SETMARGINS, %EC_RIGHTMARGIN, MAK(LONG, 0, nWidth)
END SUB
' ========================================================================================

' ========================================================================================
' Sets or clears the modification flag for an edit control. The modification flag
' indicates whether the text within the edit control has been modified.
' ========================================================================================
SUB Edit_SetModify (BYVAL hEdit AS LONG, BYVAL fModify AS LONG)
   SendMessage hEdit, %EM_SETMODIFY, fModify, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets or removes the password character for an edit control. When a password character is
' set, that character is displayed in place of the characters typed by the user.
' ========================================================================================
SUB Edit_SetPasswordChar (BYVAL hEdit AS DWORD, BYVAL dwchar AS DWORD)
   SendMessage hEdit, %EM_SETPASSWORDCHAR, dwchar, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets or removes the read-only style (ES_READONLY) of an edit control.
' ========================================================================================
FUNCTION Edit_SetReadOnly (BYVAL hEdit AS DWORD, BYVAL fReadOnly AS LONG) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_SETREADONLY, fReadOnly, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the formatting rectangle of a multiline edit control. The formatting rectangle is
' the limiting rectangle into which the control draws the text. The limiting rectangle is
' independent of the size of the edit control window. This message is processed only by
' multiline edit controls.
' ========================================================================================
#IF %DEF(%USEPBDECL)
MACRO Edit_SetRect(hwndCtl, lprc)
    SendMessage hwndCtl, %EM_SETRECT, 0, lprc
END MACRO
#ELSE
SUB Edit_SetRect (BYVAL hEdit AS DWORD, BYREF prect AS RECT)
   SendMessage hEdit, %EM_SETRECT, 0, VARPTR(prect)
END SUB
#ENDIF
' ========================================================================================

' ========================================================================================
' Sets the formatting rectangle of a multiline edit control. The EM_SETRECTNP message is
' identical to the EM_SETRECT message, except that EM_SETRECTNP does not redraw the edit
' control window. The formatting rectangle is the limiting rectangle into which the
' control draws the text. The limiting rectangle is independent of the size of the edit
' control window. This message is processed only by multiline edit controls.
' ========================================================================================
SUB Edit_SetRectNP (BYVAL hEdit AS DWORD, BYREF prect AS RECT)
   SendMessage hEdit, %EM_SETRECTNP, 0, VARPTR(prect)
END SUB
' ========================================================================================
' ========================================================================================
#IF %DEF(%USEPBDECL)
MACRO Edit_SetRectNoPaint(hwndCtl, lprc)
    SendMessage hwndCtl, %EM_SETRECTNP, 0, lprc
END MACRO
#ELSE
SUB Edit_SetRectNoPaint (BYVAL hEdit AS DWORD, BYREF prect AS RECT)
   SendMessage hEdit, %EM_SETRECTNP, 0, VARPTR(prect)
END SUB
#ENDIF
' ========================================================================================

' ========================================================================================
' Selects a range of characters in an edit control.
' ========================================================================================
SUB Edit_SetSel (BYVAL hEdit AS DWORD, BYVAL nStart AS LONG, BYVAL nEnd AS LONG)
   SendMessage hEdit, %EM_SETSEL, nStart, nEnd
END SUB
' ========================================================================================

' ========================================================================================
' Sets the tab stops in a multiline edit control. When text is copied to the control, any
' tab character in the text causes space to be generated up to the next tab stop. This
' message is processed only by multiline edit controls.
' ========================================================================================
#IF %DEF(%USEPBDECL)
MACRO Edit_SetTabStops(hwndCtl, cTabs, lpTabs)
    SendMessage hwndCtl, %EM_SETTABSTOPS, cTabs, lpTabs
END MACRO
#ELSE
FUNCTION Edit_SetTabStops (BYVAL hEdit AS LONG, BYVAL cTabs AS LONG, BYREF rgTabStops AS DWORD) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_SETTABSTOPS, cTabs, VARPTR(rgTabStops))
END FUNCTION
#ENDIF
' ========================================================================================

' ========================================================================================
' Sets the text of an edit control.
' Note: SetWindowText cannot change the text of a control in another application.
' ========================================================================================
'FUNCTION Edit_SetText (BYVAL hEdit AS DWORD, BYVAL strText AS STRING) AS LONG
'   FUNCTION = SetWindowText(hEdit, BYCOPY strText)
'END FUNCTION
' ========================================================================================
FUNCTION Edit_SetTextA (BYVAL hEdit AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hEdit, %WM_SETTEXT, 0, STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Edit_SetTextW (BYVAL hEdit AS DWORD, BYVAL bstrText AS WSTRING) AS LONG
   FUNCTION = SendMessageW(hEdit, %WM_SETTEXT, 0, STRPTR(bstrText))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Edit_SetText = Edit_SetTextW
#ELSE
   MACRO Edit_SetText = Edit_SetTextA
#ENDIF

' ========================================================================================
' Sets the text using UTF8 encoded strings.
' ========================================================================================
FUNCTION Edit_SetUtf8Text (BYVAL hEdit AS DWORD, BYVAL strUtf8Text AS STRING) AS LONG
   LOCAL bstrText AS WSTRING
   bstrText = UTF8TOCHR$(strUtf8Text)
   FUNCTION = SendMessageW(hEdit, %WM_SETTEXT, 0, STRPTR(bstrText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Replaces an edit control's default Wordwrap function with an application-defined
' Wordwrap function.
' ========================================================================================
SUB Edit_SetWordBreakProc (BYVAL hEdit AS DWORD, BYVAL pfn AS DWORD)
   SendMessage hEdit, %EM_SETWORDBREAKPROC, 0, pfn
END SUB
' ========================================================================================

' ========================================================================================
' Displays a balloon tip associated with an edit control.
' ========================================================================================
FUNCTION Edit_ShowBalloonTip (BYVAL hEdit AS DWORD, BYREF peditballoontip AS EDITBALLOONTIP) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_SHOWBALLOONTIP, 0, VARPTR(peditballoontip))
END FUNCTION
' ========================================================================================

' ========================================================================================
' This message undoes the last edit control operation in the control's undo queue.
' ========================================================================================
FUNCTION Edit_Undo (BYVAL hEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_UNDO, 0, 0)
END FUNCTION
' ========================================================================================
