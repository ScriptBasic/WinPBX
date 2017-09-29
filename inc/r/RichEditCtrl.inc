' ########################################################################################
' Microsoft Windows
' File: RichEditCtrl.inc
' Contents: RichEdit Control Wrapper Functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%RICHEDITCTRL_INC = 1

#INCLUDE ONCE "richedit.inc"

' ========================================================================================
' Enables or disables automatic detection of URLs by a rich edit control.
' ========================================================================================
FUNCTION RichEdit_AutoUrlDetect (BYVAL hRichEdit AS DWORD, BYVAL fUrlDetect AS LONG) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_AUTOURLDETECT, fUrlDetect, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether a rich edit control can paste a specified clipboard format.
' ========================================================================================
FUNCTION RichEdit_CanPaste (BYVAL hRichEdit AS DWORD, BYVAL clipformat AS LONG) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_CANPASTE, clipformat, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether there are any actions in the control redo queue.
' ========================================================================================
FUNCTION RichEdit_CanRedo (BYVAL hRichEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_CANREDO, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether there are any actions in an edit control's undo queue.
' ========================================================================================
FUNCTION RichEdit_CanUndo (BYVAL hRichEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_CANUNDO, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets information about the character closest to a specified point in the client area of
' an edit control.
' ========================================================================================
FUNCTION RichEdit_CharFromPos (BYVAL hRichEdit AS DWORD, BYREF lppl AS POINTL) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_CHARFROMPOS, 0, VARPTR(lppl))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Displays a portion of the contents of a rich edit control, as previously formatted for a
' device using the EM_FORMATRANGE message.
' ========================================================================================
FUNCTION RichEdit_DisplayBand (BYVAL hRichEdit AS DWORD, BYREF lprc AS RECT) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_DISPLAYBAND, 0, VARPTR(lprc))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Resets the undo flag of a rich edit control. The undo flag is set whenever an operation
' within the rich edit control can be undone.
' ========================================================================================
SUB RichEdit_EmptyUndoBuffer (BYVAL hRichEdit AS DWORD)
   SendMessage hRichEdit, %EM_EMPTYUNDOBUFFER, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the starting and ending character positions of the selection in a rich edit control.
' ========================================================================================
SUB RichEdit_ExGetSel (BYVAL hRichEdit AS DWORD, BYREF lpchr AS CHARRANGE)
   SendMessage hRichEdit, %EM_EXGETSEL, 0, VARPTR(lpchr)
END SUB
' ========================================================================================

' ========================================================================================
' Sets an upper limit to the amount of text the user can type or paste into a rich edit control.
' ========================================================================================
SUB RichEdit_ExLimitText (BYVAL hRichEdit AS DWORD, BYVAL dwLimit AS DWORD)
   SendMessage hRichEdit, %EM_EXLIMITTEXT, 0, dwLimit
END SUB
' ========================================================================================

' ========================================================================================
' Determines which line contains the specified character in a rich edit control.
' ========================================================================================
FUNCTION RichEdit_ExLineFromChar (BYVAL hRichEdit AS DWORD, BYVAL iIndex AS LONG) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_EXLINEFROMCHAR, 0, iIndex)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Selects a range of characters and/or Component Object Model (COM) objects in a Microsoft
' Rich Edit control.
' ========================================================================================
FUNCTION RichEdit_ExSetSel (BYVAL hRichEdit AS DWORD, BYREF lpcr AS CHARRANGE) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_EXSETSEL, 0, VARPTR(lpcr))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Finds text within a rich edit control.
' ========================================================================================
FUNCTION RichEdit_FindTextA (BYVAL hRichEdit AS DWORD, BYVAL fOptions AS DWORD, BYREF lpft AS FINDTEXT_A) AS LONG
   FUNCTION = SendMessageA(hRichEdit, %EM_FINDTEXT, fOptions, VARPTR(lpft))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION RichEdit_FindTextW (BYVAL hRichEdit AS DWORD, BYVAL fOptions AS DWORD, BYREF lpft AS FINDTEXT_W) AS LONG
   FUNCTION = SendMessageW(hRichEdit, %EM_FINDTEXTW, fOptions, VARPTR(lpft))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO RichEdit_FindText = RichEdit_FindTextW
#ELSE
   MACRO RichEdit_FindText = RichEdit_FindTextA
#ENDIF

' ========================================================================================
' Finds text within a rich edit control.
' ========================================================================================
FUNCTION RichEdit_FindTextExA (BYVAL hRichEdit AS DWORD, BYVAL fOptions AS DWORD, BYREF lpftex AS FINDTEXTEXA) AS LONG
   FUNCTION = SendMessageA(hRichEdit, %EM_FINDTEXTEX, fOptions, VARPTR(lpftex))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Finds text within a rich edit control. Unicode version of RichEdit_FindTextEx.
' ========================================================================================
FUNCTION RichEdit_FindTextExW (BYVAL hRichEdit AS DWORD, BYVAL fOptions AS DWORD, BYREF lpftexw AS FINDTEXTEXW) AS LONG
   FUNCTION = SendMessageW(hRichEdit, %EM_FINDTEXTEXW, fOptions, VARPTR(lpftexw))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO RichEdit_FindTextEx = RichEdit_FindTextExW
#ELSE
   MACRO RichEdit_FindTextEx = RichEdit_FindTextExA
#ENDIF

' ========================================================================================
' Finds the next word break before or after the specified character position or retrieves
' information about the character at that position.
' ========================================================================================
FUNCTION RichEdit_FindWordBreak (BYVAL hRichEdit AS DWORD, BYVAL fOperation AS DWORD, BYVAL dwStartPos AS DWORD) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_FINDWORDBREAK, fOperation, dwStartPos)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Formats a range of text in a rich edit control for a specific device.
' ========================================================================================
FUNCTION RichEdit_FormatRange (BYVAL hRichEdit AS DWORD, BYVAL fRender AS LONG, BYREF lpfr AS FORMATRANGE) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_FORMATRANGE, fRender, VARPTR(lpfr))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Indicates whether the auto URL detection is turned on in the rich edit control.
' ========================================================================================
FUNCTION RichEdit_GetAutoUrlDetect (BYVAL hRichEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_GETAUTOURLDETECT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Indicates the current state of the bidirectional options in the rich edit control.
' ========================================================================================
SUB RichEdit_GetBidiOptions (BYVAL hRichEdit AS DWORD, BYREF lpbo AS BIDIOPTIONS)
   SendMessage hRichEdit, %EM_GETBIDIOPTIONS, 0, VARPTR(lpbo)
END SUB
' ========================================================================================

' ========================================================================================
' Determines the current character formatting in a rich edit control.
' ========================================================================================
FUNCTION RichEdit_GetCharFormat (BYVAL hRichEdit AS DWORD, BYVAL fOption AS DWORD, BYREF lpcf AS CHARFORMAT) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_GETCHARFORMAT, fOption, VARPTR(lpcf))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the Text Services Framework mode bias values for a Microsoft Rich Edit control.
' ========================================================================================
FUNCTION RichEdit_GetCTFModeBias (BYVAL hRichEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_GETCTFMODEBIAS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines if the Text Services Framework (TSF) keyboard is open or closed.
' ========================================================================================
FUNCTION RichEdit_GetCTFOpenStatus (BYVAL hRichEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_GETCTFOPENSTATUS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current edit style flags.
' ========================================================================================
FUNCTION RichEdit_GetEditStyle (BYVAL hRichEdit AS DWORD) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_GETEDITSTYLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the event mask for a rich edit control. The event mask specifies which
' notification messages the control sends to its parent window.
' ========================================================================================
FUNCTION RichEdit_GetEventMask (BYVAL hRichEdit AS DWORD) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_GETEVENTMASK, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the zero-based index of the uppermost visible line in a multiline rich edit control.
' ========================================================================================
FUNCTION RichEdit_GetFirstVisibleLine (BYVAL hRichEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_GETFIRSTVISIBLELINE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets information about hyphenation for a Microsoft Rich Edit control.
' ========================================================================================
SUB RichEdit_GetHyphenateInfo (BYVAL hRichEdit AS DWORD, BYREF lphi AS HYPHENATEINFO)
   SendMessage hRichEdit, %EM_GETHYPHENATEINFO, VARPTR(lphi), 0
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the Input Method Editor (IME) composition color. This message is available
' only in Asian-language versions of the operating system.
' ========================================================================================
FUNCTION RichEdit_GetIMEColor (BYVAL hRichEdit AS DWORD, BYREF rgCmpclr AS COMPCOLOR) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_GETIMECOLOR, 0, VARPTR(rgCmpclr))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current IME mode for a rich edit control.
' ========================================================================================
FUNCTION RichEdit_GetIMECompMode (BYVAL hRichEdit AS DWORD) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_GETIMECOMPMODE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the Input Method Editor (IME) composition text.
' ========================================================================================
FUNCTION RichEdit_GetIMECompText (BYVAL hRichEdit AS DWORD, BYREF lpict AS IMECOMPTEXT, BYVAL buffer AS DWORD) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_GETIMECOMPTEXT, VARPTR(lpict), buffer)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the Input Method Editor (IME) mode bias for a Microsoft Rich Edit control.
' ========================================================================================
FUNCTION RichEdit_GetIMEModeBias (BYVAL hRichEdit AS DWORD) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_GETIMEMODEBIAS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current Input Method Editor (IME) options. This message is available only
' in Asian-language versions of the operating system.
' ========================================================================================
FUNCTION RichEdit_GetIMEOptions (BYVAL hRichEdit AS DWORD) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_GETIMEOPTIONS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the property and capabilities of the Input Method Editor (IME) associated with the
' current input locale.
' ========================================================================================
FUNCTION RichEdit_GetIMEProperty (BYVAL hRichEdit AS DWORD, BYVAL figp AS DWORD) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_GETIMEPROPERTY, figp, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets a rich edit control's option settings for Input Method Editor (IME) and Asian
' language support.
' ========================================================================================
FUNCTION RichEdit_GetLangOptions (BYVAL hRichEdit AS DWORD) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_GETLANGOPTIONS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current text limit for a rich edit control.
' ========================================================================================
FUNCTION RichEdit_GetLimitText (BYVAL hRichEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_GETLIMITTEXT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Copies a line of text from a rich edit control.
' ========================================================================================
FUNCTION RichEdit_GetLineA (BYVAL hRichEdit AS DWORD, BYVAL which AS DWORD) AS STRING
   LOCAL buffer AS STRING
   LOCAL n AS LONG
   buffer = MKI$(32765) + STRING$(32765, 0)
   n = SendMessageA(hRichEdit, %EM_GETLINE, which, STRPTR(buffer))
   FUNCTION = LEFT$(buffer, n)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION RichEdit_GetLineW (BYVAL hRichEdit AS DWORD, BYVAL which AS DWORD) AS WSTRING
   LOCAL buffer AS WSTRING
   LOCAL n AS LONG
   buffer = MKI$(32765) + STRING$(32765, 0)
   n = SendMessageW(hRichEdit, %EM_GETLINE, which, STRPTR(buffer))
   FUNCTION = LEFT$(buffer, n)
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO RichEdit_GetLine = RichEdit_GetLineW
#ELSE
   MACRO RichEdit_GetLine = RichEdit_GetLineA
#ENDIF

' ========================================================================================
' Gets the number of lines in a multiline rich edit control.
' ========================================================================================
FUNCTION RichEdit_GetLineCount (BYVAL hRichEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_GETLINECOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the state of a rich edit control's modification flag. The flag indicates whether
' the contents of the rich edit control have been modified.
' ========================================================================================
FUNCTION RichEdit_GetModify (BYVAL hRichEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_GETMODIFY, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the state of a rich edit control's modification flag. The flag indicates whether
' the contents of the rich edit control have been modified.
' ========================================================================================
FUNCTION RichEdit_GetOleInterface (BYVAL hRichEdit AS DWORD, BYREF ppObject AS IUnknown) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_GETOLEINTERFACE, 0, VARPTR(ppObject))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves rich edit control options.
' ========================================================================================
FUNCTION RichEdit_GetOptions (BYVAL hRichEdit AS DWORD) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_GETOPTIONS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deprecated. Gets the text layout for a Microsoft Rich Edit control.
' ========================================================================================
FUNCTION RichEdit_GetPageRotate (BYVAL hRichEdit AS DWORD) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_GETPAGEROTATE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the paragraph formatting of the current selection in a rich edit control.
' ========================================================================================
FUNCTION RichEdit_GetParaFormat (BYVAL hRichEdit AS DWORD, BYREF pParaFmt AS PARAFORMAT) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_GETPARAFORMAT, 0, VARPTR(pParaFmt))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the password character that a rich edit control displays when the user enters text.
' ========================================================================================
FUNCTION RichEdit_GetPasswordChar (BYVAL hRichEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_GETPASSWORDCHAR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current punctuation characters for the rich edit control.
' ========================================================================================
FUNCTION RichEdit_GetPunctuation (BYVAL hRichEdit AS DWORD, BYVAL punctp AS DWORD, BYREF lppunct AS PUNCTUATION) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_GETPUNCTUATION, punctp, VARPTR(lppunct))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the formatting rectangle of a rich edit control.
' ========================================================================================
SUB RichEdit_GetRect (BYVAL hRichEdit AS DWORD, BYREF rc AS RECT)
   SendMessage hRichEdit, %EM_GETRECT, 0, VARPTR(rc)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the type of the next action, if any, in the control's redo queue.
' ========================================================================================
FUNCTION RichEdit_GetRedoName (BYVAL hRichEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_GETREDONAME, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Obtains the current scroll position of the edit control.
' ========================================================================================
FUNCTION RichEdit_GetScrollPos (BYVAL hRichEdit AS DWORD, BYREF lppt AS POINT) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_GETSCROLLPOS, 0, VARPTR(lppt))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the starting and ending character positions of the current selection in a rich
' edit control.
' ========================================================================================
'FUNCTION RichEdit_GetSel (BYVAL hRichEdit AS DWORD) AS LONG
'   FUNCTION = SendMessage(hRichEdit, %EM_GETSEL, 0, 0)
'END FUNCTION
' ========================================================================================
FUNCTION RichEdit_GetSel (BYVAL hRichEdit AS DWORD, BYREF dwStartPos AS DWORD, BYREF dwEndPos AS DWORD) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_GETSEL, BYVAL VARPTR(dwStartPos), BYVAL VARPTR(dwEndPos))
END FUNCTION

' ========================================================================================
' Retrieves the currently selected text in a rich edit control.
' Note: From version 4.1 (RichEdit50W class in MSFTEDIT.DLL), Windows XP, EM_GETSELTEXT
' returns the text in unicode.
' ========================================================================================
'FUNCTION RichEdit_GetSelText (BYVAL hRichEdit AS DWORD, BYREF lpsztxt AS ASCIIZ) AS DWORD
'   FUNCTION = SendMessage(hRichEdit, %EM_GETSELTEXT, 0, VARPTR(lpsztxt))
'END FUNCTION
' ========================================================================================
FUNCTION RichEdit_GetSelText (BYVAL hRichEdit AS DWORD) AS WSTRING
   LOCAL dwStartPos, dwEndPos, cbLen AS DWORD, cr AS CHARRANGE, bstrText AS WSTRING
   SendMessage(hRichEdit, %EM_EXGETSEL, 0, BYVAL VARPTR(cr))
   cbLen = ABS(cr.cpMax - cr.cpMin)
   IF cbLen < 1 THEN Exit FUNCTION
   bstrText = SPACE$(cbLen + 1)
   cbLen = SendMessage(hRichEdit, %EM_GETSELTEXT, 0, BYVAL STRPTR(bstrText))
   FUNCTION = LEFT$(bstrText, cbLen)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the text from a rich edit control.
' Note: GetWindowText cannot retrieve the text of a control in another application.
' ========================================================================================
'FUNCTION RichEdit_GetText (BYVAL hRichEdit AS LONG) AS STRING
'   LOCAL nLen AS LONG
'   LOCAL buffer AS STRING
'   nLen = RichEdit_GetTextLength(hRichEdit)
'   Buffer = SPACE$(nLen + 1)
'   GetWindowText hRichEdit, BYVAL STRPTR(Buffer), nLen + 1
'   FUNCTION = LEFT$(Buffer, nLen)
'END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION RichEdit_GetTextA (BYVAL hRichEdit AS LONG) AS STRING
   LOCAL nLen   AS LONG
   LOCAL buffer AS STRING
   nLen = SendMessageA(hRichEdit, %WM_GETTEXTLENGTH, 0, 0)
   Buffer = SPACE$(nLen + 1)
   nLen = SendMessageA(hRichEdit, %WM_GETTEXT, nLen + 1, BYVAL STRPTR(Buffer))
   FUNCTION = LEFT$(Buffer, nLen)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION RichEdit_GetTextW (BYVAL hRichEdit AS LONG) AS WSTRING
   LOCAL nLen   AS LONG
   LOCAL buffer AS WSTRING
   nLen = SendMessageW(hRichEdit, %WM_GETTEXTLENGTH, 0, 0)
   Buffer = SPACE$(nLen + 1)
   nLen = SendMessageW(hRichEdit, %WM_GETTEXT, nLen + 1, BYVAL STRPTR(Buffer))
   FUNCTION = LEFT$(Buffer, nLen)
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO RichEdit_GetText = RichEdit_GetTextW
#ELSE
   MACRO RichEdit_GetText = RichEdit_GetTextA
#ENDIF

' ========================================================================================
' Gets all of the text from the rich edit control in any particular code base you want.
' ========================================================================================
FUNCTION RichEdit_GetTextEx (BYVAL hRichEdit AS DWORD, BYREF lpgtex AS GETTEXTEX, BYVAL buffer AS DWORD) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_GETTEXTEX, VARPTR(lpgtex), buffer)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the length of all text in a rich edit control.
' ========================================================================================
FUNCTION RichEdit_GetTextLength (BYVAL hRichEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hRichEdit, %WM_GETTEXTLENGTH, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Calculates text length in various ways. It is usually called before creating a buffer to
' receive the text from the control.
' ========================================================================================
FUNCTION RichEdit_GetTextLengthEx (BYVAL hRichEdit AS DWORD, BYREF lpgtex AS GETTEXTLENGTHEX) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_GETTEXTLENGTHEX, VARPTR(lpgtex), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current text mode and undo level of a rich edit control.
' ========================================================================================
FUNCTION RichEdit_GetTextMode (BYVAL hRichEdit AS DWORD) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_GETTEXTMODE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a specified range of characters from a rich edit control.
' ========================================================================================
FUNCTION RichEdit_GetTextRange (BYVAL hRichEdit AS DWORD, BYREF lptr AS TEXTRANGE) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_GETTEXTRANGE, 0, VARPTR(lptr))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the position of the scroll box (thumb) in the vertical scroll bar of a multiline
' rich edit control.
' ========================================================================================
FUNCTION RichEdit_GetThumb (BYVAL hRichEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_GETTHUMB, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the current state of the typography options of a rich edit control.
' ========================================================================================
FUNCTION RichEdit_GetTypographyOptions (BYVAL hRichEdit AS DWORD) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_GETTYPOGRAPHYOPTIONS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the type of the next undo action, if any.
' ========================================================================================
FUNCTION RichEdit_GetUndoName (BYVAL hRichEdit AS DWORD) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_GETUNDONAME, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the address of the current Wordwrap function.
' ========================================================================================
FUNCTION RichEdit_GetWordBreakProc (BYVAL hRichEdit AS DWORD) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_GETWORDBREAKPROC, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the address of the currently registered extended word-break procedure.
' ========================================================================================
FUNCTION RichEdit_GetWordBreakProcEx (BYVAL hRichEdit AS DWORD) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_GETWORDBREAKPROCEX, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current word wrap and word-break options for the rich edit control.
' ========================================================================================
FUNCTION RichEdit_GetWordWrapMode (BYVAL hRichEdit AS DWORD) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_GETWORDWRAPMODE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current zoom ratio, which is always between 1/64 and 64.
' ========================================================================================
FUNCTION RichEdit_GetZoom (BYVAL hRichEdit AS DWORD, BYREF zNum AS DWORD, BYREF zDen AS DWORD) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_GETZOOM, VARPTR(zNum), VARPTR(zDen))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Hides or shows the selection in a rich edit control.
' ========================================================================================
SUB RichEdit_HideSelection (BYVAL hRichEdit AS DWORD, BYVAL fHide AS DWORD)
   SendMessage hRichEdit, %EM_HIDESELECTION, fHide, 0
END SUB
' ========================================================================================

' ========================================================================================
' Determines if current input locale is an East Asian locale.
' ========================================================================================
FUNCTION RichEdit_IsIME (BYVAL hRichEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_ISIME, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the text limit of a rich edit control. The text limit is the maximum amount of text,
' in TCHARs, that the user can type into the edit control.
' ========================================================================================
SUB RichEdit_LimitText (BYVAL hRichEdit AS DWORD, BYVAL chMax AS DWORD)
   SendMessage hRichEdit, %EM_LIMITTEXT, chMax, 0
END SUB
' ========================================================================================

' ========================================================================================
' Gets the index of the line that contains the specified character index in a multiline
' rich edit control.
' ========================================================================================
FUNCTION RichEdit_LineFromChar (BYVAL hEdit AS DWORD, BYVAL index AS DWORD) AS LONG
   FUNCTION = SendMessage(hEdit, %EM_LINEFROMCHAR, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the character index of the first character of a specified line in a multiline
' rich edit control.
' ========================================================================================
FUNCTION RichEdit_LineIndex (BYVAL hRichEdit AS DWORD, BYVAL nLine AS LONG) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_LINEINDEX, nLine, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the length, in characters, of a line in a rich edit control.
' ========================================================================================
FUNCTION RichEdit_LineLength (BYVAL hRichEdit AS DWORD, BYVAL index AS DWORD) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_LINELENGTH, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Scrolls the text in a multiline rich edit control.
' ========================================================================================
FUNCTION RichEdit_LineScroll (BYVAL hRichEdit AS DWORD, BYVAL y AS LONG) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_LINESCROLL, 0, y)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Pastes a specific clipboard format in a rich edit control.
' ========================================================================================
SUB RichEdit_PasteSpecial (BYVAL hRichEdit AS DWORD, BYVAL clpfmt AS DWORD, BYREF lprps AS REPASTESPECIAL)
   SendMessage hRichEdit, %EM_PASTESPECIAL, clpfmt, VARPTR(lprps)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the client area coordinates of a specified character in a rich edit control.
' ========================================================================================
FUNCTION RichEdit_PosFromChar (BYVAL hRichEdit AS DWORD, BYREF pt AS POINTL, BYVAL index as DWORD) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_POSFROMCHAR, VARPTR(pt), index)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Invokes the Input Method Editor (IME) reconversion dialog box.
' ========================================================================================
FUNCTION RichEdit_Reconversion (BYVAL hRichEdit AS DWORD) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_RECONVERSION, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Redoes the next action in the control's redo queue.
' ========================================================================================
FUNCTION RichEdit_Redo (BYVAL hRichEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_REDO, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Replaces the current selection in a rich edit control with the specified text.
' ========================================================================================
SUB RichEdit_ReplaceSelA (BYVAL hRichEdit AS DWORD, BYVAL bCanBeUndone AS LONG, BYVAL strText AS STRING)
   SendMessageA hRichEdit, %EM_REPLACESEL, bCanBeUndone, STRPTR(strText)
END SUB
' ========================================================================================
' ========================================================================================
SUB RichEdit_ReplaceSelW (BYVAL hRichEdit AS DWORD, BYVAL bCanBeUndone AS LONG, BYVAL bstrText AS WSTRING)
   SendMessageW hRichEdit, %EM_REPLACESEL, bCanBeUndone, STRPTR(bstrText)
END SUB
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO RichEdit_ReplaceSel = RichEdit_ReplaceSelW
#ELSE
   MACRO RichEdit_ReplaceSel = RichEdit_ReplaceSelA
#ENDIF

' ========================================================================================
' Forces a rich edit control to send an EN_REQUESTRESIZE notification message to its
' parent window.
' ========================================================================================
SUB RichEdit_RequestResize (BYVAL hRichEdit AS DWORD)
   SendMessage hRichEdit, %EM_REQUESTRESIZE, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Scrolls the text vertically in a multiline rich edit control.
' ========================================================================================
FUNCTION RichEdit_Scroll (BYVAL hRichEdit AS DWORD, BYVAL nAction AS LONG) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_SCROLL, nAction, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Scrolls the caret into view in a rich edit control.
' ========================================================================================
SUB RichEdit_ScrollCaret (BYVAL hRichEdit AS DWORD)
   SendMessage hRichEdit, %EM_SCROLLCARET, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Determines the selection type for a rich edit control.
' ========================================================================================
FUNCTION RichEdit_SelectionType (BYVAL hRichEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_SELECTIONTYPE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the current state of the bidirectional options in the rich edit control.
' ========================================================================================
FUNCTION RichEdit_SetBidiOptions (BYVAL hRichEdit AS DWORD, BYREF pOptions AS BIDIOPTIONS) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_SETBIDIOPTIONS, 0, VARPTR(pOptions))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the background color for a rich edit control.
' ========================================================================================
FUNCTION RichEdit_SetBkgndColor (BYVAL hRichEdit AS DWORD, BYVAL pSysColor AS DWORD, BYVAL pBkColor AS DWORD) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_SETBKGNDCOLOR, pSysColor, pBkColor)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets character formatting in a rich edit control.
' ========================================================================================
FUNCTION RichEdit_SetCharFormat (BYVAL hRichEdit AS DWORD, BYVAL chfmt AS DWORD, BYVAL pchfmt AS DWORD) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_SETCHARFORMAT, chfmt, pchfmt)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the Text Services Framework (TSF) mode bias for a Microsoft Rich Edit control.
' ========================================================================================
FUNCTION RichEdit_SetCTFModeBias (BYVAL hRichEdit AS DWORD, BYVAL nModeBias AS LONG) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_SETCTFMODEBIAS, nModeBias, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Opens or closes the Text Services Framework (TSF) keyboard.
' ========================================================================================
FUNCTION RichEdit_SetCTFOpenStatus (BYVAL hRichEdit AS DWORD, BYVAL fTSFkbd AS LONG) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_SETCTFOPENSTATUS, fTSFkbd, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the current edit style flags.
' ========================================================================================
FUNCTION RichEdit_SetEditStyle (BYVAL hRichEdit AS DWORD, BYVAL fStyle AS LONG, BYVAL fMask AS LONG) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_SETEDITSTYLE, fStyle, fMask)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the event mask for a rich edit control.
' ========================================================================================
FUNCTION RichEdit_SetEventMask (BYVAL hRichEdit AS DWORD, BYVAL fMask AS LONG) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_SETEVENTMASK, 0, fMask)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the font size for the selected text.
' ========================================================================================
FUNCTION RichEdit_SetFontSize (BYVAL hRichEdit AS DWORD, BYVAL ptsize AS LONG) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_SETFONTSIZE, ptsize, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the way a Microsoft Rich Edit control does hyphenation.
' ========================================================================================
SUB RichEdit_SetHyphenateInfo (BYVAL hRichEdit AS DWORD, BYREF phinfo AS HYPHENATEINFO)
   SendMessage hRichEdit, %EM_SETHYPHENATEINFO, VARPTR(phinfo), 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the Input Method Editor (IME) composition color.
' ========================================================================================
FUNCTION RichEdit_SetIMEColor (BYVAL hRichEdit AS DWORD, BYREF pcompcolor AS COMPCOLOR) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_SETIMECOLOR, 0, VARPTR(pcompcolor))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the Input Method Editor (IME) mode bias for a Microsoft Rich Edit control.
' ========================================================================================
FUNCTION RichEdit_SetIMEModeBias (BYVAL hRichEdit AS DWORD, BYVAL nModeBias AS LONG) AS LONG
   FUNCTION = SendMessage(hRichEdit,%EM_SETIMEMODEBIAS, nModeBias, nModeBias)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the Input Method Editor (IME) options.
' ========================================================================================
FUNCTION RichEdit_SetIMEOptions (BYVAL hRichEdit AS DWORD, BYVAL fCoop AS LONG, BYVAL fOptions AS LONG) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_SETIMEOPTIONS, fCoop, fOptions)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets options for Input Method Editor (IME) and Asian language support in a rich edit control.
' ========================================================================================
FUNCTION RichEdit_SetLangOptions (BYVAL hRichEdit AS DWORD, BYVAL lgoptions AS LONG) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_SETLANGOPTIONS, 0, lgoptions)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the text limit of a rich edit control. The text limit is the maximum amount of
' text, in TCHARs, that the user can type into the edit control.
' ========================================================================================
SUB RichEdit_SetLimitText (BYVAL hRichEdit AS DWORD, BYVAL chMax AS DWORD)
   SendMessage hRichEdit, %EM_LIMITTEXT, chMax, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the widths of the left and right margins for a rich edit control. The message
' redraws the control to reflect the new margins.
' ========================================================================================
SUB RichEdit_SetMargins (BYVAL hRichEdit AS LONG, BYVAL nMargins AS LONG, BYVAL nWidth AS LONG)
   SendMessage(hRichEdit, %EM_SETMARGINS, nMargins, nWidth)
END SUB
' ========================================================================================

' ========================================================================================
' Sets or clears the modification flag for a rich edit control. The modification flag
' indicates whether the text within the rich edit control has been modified.
' ========================================================================================
SUB RichEdit_SetModify (BYVAL hRichEdit AS LONG, BYVAL fModify AS LONG)
   SendMessage hRichEdit, %EM_SETMODIFY, fModify, 0
END SUB
' ========================================================================================

' ========================================================================================
' Gives a rich edit control an IRichEditOleCallback object that the control uses to get
' OLE-related resources and information from the client.
' ========================================================================================
FUNCTION RichEdit_SetOleCallback (BYVAL hRichEdit AS DWORD, BYVAL pCallback AS DWORD) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_SETOLECALLBACK, 0, pCallback)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the options for a rich edit control.
' ========================================================================================
FUNCTION RichEdit_SetOptions (BYVAL hRichEdit AS DWORD, BYVAL fCoop AS LONG, BYVAL fOptions AS LONG) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_SETOPTIONS, fCoop, fOptions)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deprecated. Sets the text layout for a Microsoft Rich Edit control.
' ========================================================================================
FUNCTION RichEdit_SetPageRotate (BYVAL hRichEdit AS DWORD, BYVAL txtlayout AS LONG) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_SETPAGEROTATE, txtlayout, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deprecated. Sets the text layout for a Microsoft Rich Edit control.
' ========================================================================================
SUB RichEdit_SetPalette (BYVAL hRichEdit AS DWORD, BYVAL newPalette AS DWORD)
   SendMessage hRichEdit, %EM_SETPALETTE, newPalette, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the paragraph formatting for the current selection in a rich edit control.
' ========================================================================================
FUNCTION RichEdit_SetParaFormat (BYVAL hRichEdit AS DWORD, BYREF pfmt AS PARAFORMAT) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_SETPARAFORMAT, 0, VARPTR(pfmt))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets or removes the password character for a rich edit control. When a password
' character is set, that character is displayed in place of the characters typed by the user.
' ========================================================================================
SUB RichEdit_SetPasswordChar (BYVAL hRichEdit AS DWORD, BYVAL dwchar AS DWORD)
   SendMessage hRichEdit, %EM_SETPASSWORDCHAR, dwchar, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the punctuation characters for a rich edit control.
' ========================================================================================
FUNCTION RichEdit_SetPunctuation (BYVAL hRichEdit AS DWORD, BYVAL ptype AS LONG, BYREF ppunct AS PUNCTUATION) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_SETPUNCTUATION, ptype, VARPTR(ppunct))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets or removes the read-only style (ES_READONLY) of a rich edit control.
' ========================================================================================
FUNCTION RichEdit_SetReadOnly (BYVAL hRichEdit AS DWORD, BYVAL fReadOnly AS LONG) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_SETREADONLY, fReadOnly, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the formatting rectangle of a multiline rich edit control.
' ========================================================================================
SUB RichEdit_SetRect (BYVAL hRichEdit AS DWORD, BYVAL fCoord AS LONG, BYREF prect AS RECT)
   SendMessage hRichEdit, %EM_SETRECT, fCoord, VARPTR(prect)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the formatting rectangle of a multiline rich edit control.
' ========================================================================================
SUB RichEdit_SetRectNP (BYVAL hRichEdit AS DWORD, BYVAL fCoord AS LONG, BYREF prect AS RECT)
   SendMessage hRichEdit, %EM_SETRECTNP, fCoord, VARPTR(prect)
END SUB
' ========================================================================================

' ========================================================================================
' Tells the rich edit control to scroll to a particular point.
' ========================================================================================
FUNCTION RichEdit_SetScrollPos (BYVAL hRichEdit AS DWORD, BYREF pt AS POINT) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_SETSCROLLPOS, 0, VARPTR(pt))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Selects a range of characters in a rich edit control.
' ========================================================================================
SUB RichEdit_SetSel (BYVAL hRichEdit AS DWORD, BYVAL nStart AS LONG, BYVAL nEnd AS LONG)
   SendMessage hRichEdit, %EM_SETSEL, nStart, nEnd
END SUB
' ========================================================================================

' ========================================================================================
' Sets the tab stops in a multiline rich edit control.
' ========================================================================================
FUNCTION RichEdit_SetTabStops (BYVAL hRichEdit AS LONG, BYVAL nTabs AS LONG, BYREF rgTabStops AS DWORD) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_SETTABSTOPS, nTabs, VARPTR(rgTabStops))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the target device and line width used for WYSIWYG formatting in a rich edit control.
' ========================================================================================
FUNCTION RichEdit_SetTargetDevice (BYVAL hRichEdit AS DWORD, BYVAL hDC AS DWORD, BYVAL lnwidth AS LONG) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_SETTARGETDEVICE, hDC, lnwidth)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the text of an edit control.
' Note: SetWindowText cannot change the text of a control in another application.
' ========================================================================================
'FUNCTION RichEdit_SetText (BYVAL hRichEdit AS DWORD, BYVAL text AS STRING) AS LONG
'   FUNCTION = SetWindowText(hRichEdit, BYVAL STRPTR(text))
'END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION RichEdit_SetTextA (BYVAL hRichEdit AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hRichEdit, %WM_SETTEXT, 0, STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION RichEdit_SetTextW (BYVAL hRichEdit AS DWORD, BYVAL bstrText AS WSTRING) AS LONG
   FUNCTION = SendMessageW(hRichEdit, %WM_SETTEXT, 0, STRPTR(bstrText))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO RichEdit_SetText = RichEdit_SetTextW
#ELSE
   MACRO RichEdit_SetText = RichEdit_SetTextA
#ENDIF

' ========================================================================================
' Combines the functionality of WM_SETTEXT and EM_REPLACESEL and adds the ability to set
' text using a code page and to use either Rich Text Format (RTF) rich text or plain text.
' ========================================================================================
FUNCTION RichEdit_SetTextExA (BYVAL hRichEdit AS DWORD, BYREF pstex AS SETTEXTEX, BYVAL strText AS STRING) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_SETTEXTEX, VARPTR(pstex), STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION RichEdit_SetTextExW (BYVAL hRichEdit AS DWORD, BYREF pstex AS SETTEXTEX, BYVAL bstrText AS WSTRING) AS DWORD
   FUNCTION = SendMessageW(hRichEdit, %EM_SETTEXTEX, VARPTR(pstex), STRPTR(bstrText))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO RichEdit_SetTextEx = RichEdit_SetTextExW
#ELSE
   MACRO RichEdit_SetTextEx = RichEdit_SetTextExA
#ENDIF

' ========================================================================================
' Sets the text mode or undo level of a rich edit control.
' ========================================================================================
FUNCTION RichEdit_SetTextMode (BYVAL hRichEdit AS DWORD, BYVAL pvalues AS LONG) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_SETTEXTMODE, 0, pvalues)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the text mode or undo level of a rich edit control.
' ========================================================================================
FUNCTION RichEdit_SetTypographyOptions (BYVAL hRichEdit AS DWORD, BYVAL pto AS LONG, BYVAL fMask AS LONG) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_SETTYPOGRAPHYOPTIONS, pto, fMask)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the maximum number of actions that can stored in the undo queue.
' ========================================================================================
FUNCTION RichEdit_SetUndoLimit (BYVAL hRichEdit AS DWORD, BYVAL maxactions AS DWORD) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_SETUNDOLIMIT, maxactions, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Replaces a rich edit control's default Wordwrap function with an application-defined
' Wordwrap function.
' ========================================================================================
SUB RichEdit_SetWordBreakProc (BYVAL hRichEdit AS DWORD, BYVAL pfn AS DWORD)
   SendMessage hRichEdit, %EM_SETWORDBREAKPROC, 0, pfn
END SUB
' ========================================================================================

' ========================================================================================
' Sets the extended word-break procedure.
' ========================================================================================
FUNCTION RichEdit_SetWordBreakProcEx (BYVAL hRichEdit AS DWORD, BYVAL pfn AS DWORD) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_SETWORDBREAKPROCEX, 0, pfn)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the word-wrapping and word-breaking options for the rich edit control.
' ========================================================================================
FUNCTION RichEdit_SetWordWrapMode (BYVAL hRichEdit AS DWORD, BYVAL pvalues AS LONG) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_SETWORDWRAPMODE, pvalues, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the zoom ratio anywhere between 1/64 and 64.
' ========================================================================================
FUNCTION RichEdit_SetZoom (BYVAL hRichEdit AS DWORD, BYVAL zNum AS DWORD, BYVAL zDen AS DWORD) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_SETZOOM, zNum, zDen)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Shows or hides one of the scroll bars in the Text Host window.
' ========================================================================================
SUB RichEdit_ShowScrollBar (BYVAL hRichEdit AS DWORD, BYVAL nScrollBar AS DWORD, BYVAL fShow AS LONG)
   SendMessage hRichEdit, %EM_SHOWSCROLLBAR, nScrollBar, fShow
END SUB
' ========================================================================================

' ========================================================================================
' Stops the control from collecting additional typing actions into the current undo action.
' ========================================================================================
FUNCTION RichEdit_StopGroupTyping (BYVAL hRichEdit AS DWORD) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_STOPGROUPTYPING, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Replaces the contents of a rich edit control with a stream of data provided by an
' application defined–EditStreamCallback callback function.
' ========================================================================================
FUNCTION RichEdit_StreamIn (BYVAL hRichEdit AS DWORD, BYVAL psf AS LONG, BYREF pedst AS EDITSTREAM) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_STREAMIN, psf, VARPTR(pedst))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Causes a rich edit control to pass its contents to an application–defined
' EditStreamCallback callback function.
' ========================================================================================
FUNCTION RichEdit_StreamOut (BYVAL hRichEdit AS DWORD, BYVAL psf AS LONG, BYREF pedst AS EDITSTREAM) AS DWORD
   FUNCTION = SendMessage(hRichEdit, %EM_STREAMOUT, psf, VARPTR(pedst))
END FUNCTION
' ========================================================================================

' ========================================================================================
' This message undoes the last edit control operation in the control's undo queue.
' ========================================================================================
FUNCTION RichEdit_Undo (BYVAL hRichEdit AS DWORD) AS LONG
   FUNCTION = SendMessage(hRichEdit, %EM_UNDO, 0, 0)
END FUNCTION
' ========================================================================================


' ########################################################################################
'                          H E L P E R    F U N C T I O N S
' ########################################################################################

' ========================================================================================
' Loads a RTF file into a Rich Edit control.
' The EM_STREAMIN message replaces the contents of a rich edit control with a stream of
' data provided by an application defined–EditStreamCallback callback function.
' ========================================================================================
FUNCTION RichEdit_LoadRtfFromFileA ( _
   BYVAL hRichEdit AS DWORD _               ' // Handle of the Rich Edit control
 , BYVAL strFileName AS STRING _            ' // Name of the file to load
 ) AS LONG                                  ' // TRUE or FALSE

   LOCAL hFile AS DWORD                     ' // File handle
   LOCAL eds AS EDITSTREAM                  ' // EDITSTREAM structure

   ' // Checks the validity of the parameters
   IF hRichEdit = 0 THEN EXIT FUNCTION
   IF LEN(strFileName) = 0 THEN EXIT FUNCTION

   ' // Opens the file and sends the message
   hFile = CreateFileA(BYCOPY strFileName, %GENERIC_READ, %FILE_SHARE_READ, _
                       BYVAL %NULL, %OPEN_EXISTING, %FILE_FLAG_SEQUENTIAL_SCAN, %NULL)
   IF BITSE(hFile, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
   eds.dwCookie = hFile
   eds.dwError = 0
   eds.pfnCallback = CODEPTR(RichEdit_LoadRtfFromFileCallback)
   IF SendMessageA(hRichEdit, %EM_STREAMIN, %SF_RTF, VARPTR(eds)) AND eds.dwError = 0 THEN
      FUNCTION = %TRUE
   END IF
   CloseHandle hFile

END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION RichEdit_LoadRtfFromFileW ( _
   BYVAL hRichEdit AS DWORD _               ' // Handle of the Rich Edit control
 , BYVAL bstrFileName AS WSTRING _          ' // Name of the file to load
 ) AS LONG                                  ' // TRUE or FALSE

   LOCAL hFile AS DWORD                     ' // File handle
   LOCAL eds AS EDITSTREAM                  ' // EDITSTREAM structure

   ' // Checks the validity of the parameters
   IF hRichEdit = 0 THEN EXIT FUNCTION
   IF LEN(bstrFileName) = 0 THEN EXIT FUNCTION

   ' // Opens the file and sends the message
   hFile = CreateFileW(BYCOPY bstrFileName, %GENERIC_READ, %FILE_SHARE_READ, _
                       BYVAL %NULL, %OPEN_EXISTING, %FILE_FLAG_SEQUENTIAL_SCAN, %NULL)
   IF BITSE(hFile, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
   eds.dwCookie = hFile
   eds.dwError = 0
   eds.pfnCallback = CODEPTR(RichEdit_LoadRtfFromFileCallback)
   IF SendMessageW(hRichEdit, %EM_STREAMIN, %SF_RTF, VARPTR(eds)) AND eds.dwError = 0 THEN
      FUNCTION = %TRUE
   END IF
   CloseHandle hFile

END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO RichEdit_LoadRtfFromFile = RichEdit_LoadRtfFromFileW
#ELSE
   MACRO RichEdit_LoadRtfFromFile = RichEdit_LoadRtfFromFileA
#ENDIF

' ========================================================================================
' The EditStreamCallback function is an application defined callback function used with
' the EM_STREAMIN and EM_STREAMOUT messages. It is used to transfer a stream of data into
' or out of a rich edit control.
' ========================================================================================
FUNCTION RichEdit_LoadRtfFromFileCallback ( _
   BYVAL hFile AS DWORD _                   ' // Value of the dwCookie member of the EDITSTREAM structure.
 , BYVAL lpBuff AS BYTE PTR _               ' // Pointer to a buffer to write to.
 , BYVAL cb AS LONG _                       ' // Number of bytes to write.
 , BYREF pcb AS LONG _                      ' // Number of bytes actually written.
 ) AS DWORD                                 ' // 0 for success, or an error code

   IF ReadFile(hFile, BYVAL lpBuff, cb, pcb, BYVAL %NULL) = 0 THEN
      FUNCTION = GetLastError
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads a RTF resource file into a Rich Edit control.
' The EM_STREAMIN message replaces the contents of a rich edit control with a stream of
' data provided by an application defined–EditStreamCallback callback function.
' ========================================================================================
FUNCTION RichEdit_LoadRtfFromResourceA ( _
   BYVAL hRichEdit AS DWORD _               ' // Handle of the Rich Edit control
 , BYVAL hInstance AS DWORD _               ' // Instance handle
 , BYVAL strResourceName AS STRING _        ' // Name of the resource to load
 ) AS LONG                                  ' // TRUE or FALSE

   LOCAL hResInfo AS DWORD                  ' // Resource handle
   LOCAL pResData AS DWORD                  ' // Pointer to the resource data
   LOCAL buffer AS STRING                   ' // Buffer
   LOCAL eds AS EDITSTREAM                  ' // EDITSTREAM structure

   ' // Checks the validity of the parameters
   IF hRichEdit = 0 THEN EXIT FUNCTION
   IF hInstance = 0 THEN EXIT FUNCTION
   IF LEN(strResourceName) = 0 THEN EXIT FUNCTION

   ' // Loads the resource
   hResInfo = FindResourceA(hInstance, BYCOPY strResourceName, BYVAL %RT_RCDATA)
   IF hResInfo = 0 THEN EXIT FUNCTION

   ' // Loads and locks the resource
   pResData = LockResource(LoadResource(hInstance, hResInfo))
   IF pResData = 0 THEN EXIT FUNCTION
   buffer = PEEK$(pResData, SizeofResource(hInstance, hResInfo))

   ' // Sends the message
   eds.dwCookie = VARPTR(buffer)
   eds.dwError = 0
   eds.pfnCallback = CODEPTR(RichEdit_LoadRtfFromResourceCallback)
   IF SendMessageA(hRichEdit, %EM_STREAMIN, %SF_RTF, VARPTR(eds)) AND eds.dwError = 0 THEN
      FUNCTION = %TRUE
   END IF

END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION RichEdit_LoadRtfFromResourceW ( _
   BYVAL hRichEdit AS DWORD _               ' // Handle of the Rich Edit control
 , BYVAL hInstance AS DWORD _               ' // Instance handle
 , BYVAL bstrResourceName AS WSTRING _      ' // Name of the resource to load
 ) AS LONG                                  ' // TRUE or FALSE

   LOCAL hResInfo AS DWORD                  ' // Resource handle
   LOCAL pResData AS DWORD                  ' // Pointer to the resource data
   LOCAL buffer AS STRING                   ' // Buffer
   LOCAL eds AS EDITSTREAM                  ' // EDITSTREAM structure

   ' // Checks the validity of the parameters
   IF hRichEdit = 0 THEN EXIT FUNCTION
   IF hInstance = 0 THEN EXIT FUNCTION
   IF LEN(bstrResourceName) = 0 THEN EXIT FUNCTION

   ' // Loads the resource
   hResInfo = FindResourceW(hInstance, BYCOPY bstrResourceName, BYVAL %RT_RCDATA)
   IF hResInfo = 0 THEN EXIT FUNCTION

   ' // Loads and locks the resource
   pResData = LockResource(LoadResource(hInstance, hResInfo))
   IF pResData = 0 THEN EXIT FUNCTION
   buffer = PEEK$(pResData, SizeofResource(hInstance, hResInfo))

   ' // Sends the message
   eds.dwCookie = VARPTR(buffer)
   eds.dwError = 0
   eds.pfnCallback = CODEPTR(RichEdit_LoadRtfFromResourceCallback)
   IF SendMessageW(hRichEdit, %EM_STREAMIN, %SF_RTF, VARPTR(eds)) AND eds.dwError = 0 THEN
      FUNCTION = %TRUE
   END IF

END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO RichEdit_LoadRtfFromResource = RichEdit_LoadRtfFromResourceW
#ELSE
   MACRO RichEdit_LoadRtfFromResource = RichEdit_LoadRtfFromResourceA
#ENDIF

' ========================================================================================
' The EditStreamCallback function is an application defined callback function used with
' the EM_STREAMIN and EM_STREAMOUT messages. It is used to transfer a stream of data into
' or out of a rich edit control.
' ========================================================================================
FUNCTION RichEdit_LoadRtfFromResourceCallback ( _
   BYVAL pResBuff AS STRING PTR _           ' // Value of the dwCookie member of the EDITSTREAM structure.
 , BYVAL lpBuff AS BYTE PTR _               ' // Pointer to a buffer to write to.
 , BYVAL cb AS LONG _                       ' // Number of bytes to write.
 , BYREF pcb AS LONG _                      ' // Number of bytes actually written.
 ) AS DWORD                                 ' // 0 for success, or an error code

   LOCAL nBytes AS LONG
   IF LEN(@pResBuff) > cb THEN nBytes = cb ELSE nBytes = LEN(@pResBuff)
   IF nBytes THEN
      POKE$ lpBuff, LEFT$(@pResBuff, nBytes)
      @pResBuff = MID$(@pResBuff, nBytes + 1)
   END IF
   pcb = nBytes

END FUNCTION
' ========================================================================================

' ========================================================================================
' Enumerates font families. Used by the RichEdit_SetFont function.
' ========================================================================================
FUNCTION RichEdit_EnumFontFamProcA ( _
   BYREF lpelf    AS ENUMLOGFONTA, _        ' // Address of ENUMLOGFONT structure
   BYREF lpntm    AS NEWTEXTMETRICA, _      ' // Address of NEWTEXTMETRIC structure
   BYVAL FontType AS LONG, _                ' // Font type
   BYREF lplf     AS LOGFONTA _             ' // Address of LOGFONT struct
   ) AS LONG

   lplf.lfCharSet        = lpelf.elfLogFont.lfCharSet
   lplf.lfPitchAndFamily = lpelf.elfLogFont.lfPitchAndFamily
   lplf.lfFaceName       = lpelf.elfLogFont.lfFaceName

   FUNCTION = %FALSE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the font used by a rich edit control.
' ========================================================================================
FUNCTION RichEdit_SetFontA ( _
   BYVAL hRichEdit AS DWORD, _              ' // Handle to the RichEdit control
   BYREF szFaceName AS ASCIIZ, _            ' // Font name
   BYVAL ptsize AS LONG _                   ' // Font size in points
   ) AS LONG

   LOCAL lResult AS LONG                    ' // Result code
   LOCAL hDC AS DWORD                       ' // Handle of the device context
   LOCAL tlf AS LOGFONTA                    ' // LOGFONT structure
   LOCAL tcf AS CHARFORMATA                 ' // CHARFORMAT structure

   hDC = GetDC(%NULL)
   EnumFontFamiliesA hDC, szFaceName, CODEPTR(RichEdit_EnumFontFamProcA), BYVAL VARPTR(tlf)
   ReleaseDC %NULL, hDC
   tcf.cbSize = SIZEOF(tcf)
   tcf.dwMask = %CFM_BOLD OR %CFM_ITALIC OR %CFM_UNDERLINE OR %CFM_STRIKEOUT OR _
                %CFM_FACE OR %CFM_CHARSET OR %CFM_SIZE
   tcf.yHeight = ptsize * 20   ' // Expects it in 20ths of a point
   tcf.bCharSet = tlf.lfCharSet
   tcf.bPitchAndFamily = tlf.lfPitchAndFamily
   tcf.szFaceName = tlf.lfFaceName
   lResult = SendMessageA(hRichEdit, %EM_SETCHARFORMAT, %SCF_ALL, BYVAL VARPTR(tcf))
   ' // Specify which notifications the control sends to its parent window
   IF lResult <> 0 THEN lResult = SendMessageA(hRichEdit, %EM_SETEVENTMASK, 0, %ENM_CHANGE)
   FUNCTION = lResult

END FUNCTION
' ========================================================================================

' ========================================================================================
' Enumerates font families. Used by the RichEdit_SetFont function.
' ========================================================================================
FUNCTION RichEdit_EnumFontFamProcW ( _
   BYREF lpelf    AS ENUMLOGFONTW, _        ' // Address of ENUMLOGFONT structure
   BYREF lpntm    AS NEWTEXTMETRICW, _      ' // Address of NEWTEXTMETRIC structure
   BYVAL FontType AS LONG, _                ' // Font type
   BYREF lplf     AS LOGFONTW _             ' // Address of LOGFONT struct
   ) AS LONG

   lplf.lfCharSet        = lpelf.elfLogFont.lfCharSet
   lplf.lfPitchAndFamily = lpelf.elfLogFont.lfPitchAndFamily
   lplf.lfFaceName       = lpelf.elfLogFont.lfFaceName

   FUNCTION = %FALSE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets character formatting in a rich edit control.
' ========================================================================================
FUNCTION RichEdit_SetFontW ( _
   BYVAL hRichEdit AS DWORD, _              ' // Handle to the RichEdit control
   BYREF szFaceName AS WSTRINGZ, _          ' // Font name
   BYVAL ptsize AS LONG _                   ' // Font size in points
   ) AS LONG

   LOCAL lResult AS LONG                    ' // Result code
   LOCAL hDC AS DWORD                       ' // Handle of the device context
   LOCAL tlf AS LOGFONTW                    ' // LOGFONT structure
   LOCAL tcf AS CHARFORMATW                 ' // CHARFORMAT structure

   hDC = GetDC(%NULL)
   EnumFontFamiliesW hDC, szFaceName, CODEPTR(RichEdit_EnumFontFamProcW), BYVAL VARPTR(tlf)
   ReleaseDC %NULL, hDC
   tcf.cbSize = SIZEOF(tcf)
   tcf.dwMask = %CFM_BOLD OR %CFM_ITALIC OR %CFM_UNDERLINE OR %CFM_STRIKEOUT OR _
                %CFM_FACE OR %CFM_CHARSET OR %CFM_SIZE
   tcf.yHeight = ptsize * 20   ' // Expects it in 20ths of a point
   tcf.bCharSet = tlf.lfCharSet
   tcf.bPitchAndFamily = tlf.lfPitchAndFamily
   tcf.szFaceName = tlf.lfFaceName
   lResult = SendMessageW(hRichEdit, %EM_SETCHARFORMAT, %SCF_ALL, BYVAL VARPTR(tcf))
   ' // Specify which notifications the control sends to its parent window
   IF lResult <> 0 THEN lResult = SendMessageW(hRichEdit, %EM_SETEVENTMASK, 0, %ENM_CHANGE)
   FUNCTION = lResult

END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO RichEdit_SetFont = RichEdit_SetFontW
#ELSE
   MACRO RichEdit_SetFont = RichEdit_SetFontA
#ENDIF

' ========================================================================================
' RICHEDITCUSTOMDATA structure
' // Size = 12 bytes
' ========================================================================================
TYPE RICHEDITCUSTOMDATA DWORD
   pszText AS ASCIIZ PTR
   nLen    AS LONG
   curPos  AS LONG
END TYPE
' ========================================================================================

' ========================================================================================
' Application defined callback used by the EM_STREAMIN message
' ========================================================================================
FUNCTION RichEdit_SetRtfTextCallback (BYVAL pdwCookie AS RICHEDITCUSTOMDATA PTR, BYVAL pbBuff AS BYTE PTR, BYVAL cb AS LONG, pcb AS DWORD) AS LONG
   pcb = MIN(@pdwCookie.nLen - @pdwCookie.curPos, cb)
   IF pcb > 0 THEN
      MoveMemory BYVAL pbBuff, BYVAL @pdwCookie.pszText + @pdwCookie.curPos, pcb
      @pdwCookie.curPos = @pdwCookie.curPos + pcb
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets a formatted RTF string into a Rich Edit control
' Parameters:
' - hRichEdit = Handle of the Rich Edit control.
' - strText = Text to set.
' - bInsertText (optional) = If specified, the data stream replaces the contents of the
'   current selection. If not specified, the data stream replaces the entire contents of
'   the control.
' ========================================================================================
FUNCTION RichEdit_SetRtfText (BYVAL hRichEdit AS DWORD, BYVAL strText AS STRING, OPTIONAL BYVAL bInsertText AS LONG) AS DWORD

   LOCAL sf   AS DWORD                ' // Data format and replacement options
   LOCAL edts AS EDITSTREAM           ' // EDITSTREAM structure
   LOCAL recd AS RICHEDITCUSTOMDATA   ' // Custom data

   sf = %SF_TEXT
   IF LEFT$(REMOVE$(UCASE$(LEFT$(strText, 10)), ANY "{ " ), 5) = "\RTF1" THEN sf = %SF_RTF

   recd.curPos      = 0
   recd.pszText     = STRPTR(strText)
   recd.nLen        = LEN(strText)

   edts.dwCookie    = VARPTR(recd)
   edts.dwError     = 0
   edts.pfnCallback = CODEPTR(RichEdit_SetRtfTExtCallback)

   IF bInsertText THEN sf = sf OR %SFF_SELECTION
   SendMessage hRichEdit, %EM_STREAMIN, sf, VARPTR(edts)

   FUNCTION = edts.dwError

END FUNCTION
' ========================================================================================

' ========================================================================================
' Application defined callback used by the EM_STREAMOUT message
' ========================================================================================
FUNCTION RichEdit_GetRtfTextCallback (BYVAL pdwCookie AS RICHEDITCUSTOMDATA PTR, BYVAL pbBuff AS BYTE PTR, BYVAL cb AS LONG, pcb AS DWORD) AS LONG

   LOCAL pData AS DWORD

   IF cb < 1 THEN EXIT FUNCTION
   ' // Create a new piece of memory wich must contain all data collected so far.
   pData = HeapAlloc(GetProcessHeap, %HEAP_ZERO_MEMORY, @pdwCookie.curPos + cb + 1)
   ' // Copy from earlier retrieved data into new memory
   IF @pdwCookie.curPos THEN MoveMemory BYVAL pData, BYVAL @pdwCookie.pszText, @pdwCookie.curPos
   ' // Free previous memory
   HeapFree GetProcessHeap, 0, BYVAL @pdwCookie.pszText
   ' // Copy additional piece of data into new memory
   MoveMemory BYVAL pData + @pdwCookie.curPos, BYVAL pbBuff, cb
   @pdwCookie.curPos = @pdwCookie.curPos + cb
   @pdwCookie.pszText = pData
   pcb = cb

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves RTF formatted text from a Rich Edit control
' Parameters:
' - hRichEdit = Handle of the Rich Edit control.
' - nMode (optional) = %SF_RTF (rich edit, default), %SF_TEXT (text)
' Return Value:
'   The retrieved text or a null string.
' ========================================================================================
FUNCTION RichEdit_GetRtfText (BYVAL hWnd AS LONG, OPTIONAL BYVAL nMode AS LONG) AS STRING

   LOCAL edts AS EDITSTREAM           ' // EDITSTREAM structure
   LOCAL recd AS RICHEDITCUSTOMDATA   ' // Custom data

   recd.curPos      = 0
   recd.pszText     = HeapAlloc(GetProcessHeap, %HEAP_ZERO_MEMORY, 1)
   recd.nLen        = LEN(recd.@pszText)

   edts.dwCookie    = VARPTR(recd)
   edts.dwError     = 0
   edts.pfnCallback = CODEPTR(RichEdit_GetRtfTextCallback)

   IF nMode = 0 THEN nMode = %SF_RTF
   SendMessage hWnd, %EM_STREAMOUT, nMode, VARPTR(edts)
   IF recd.curPos > 0 THEN FUNCTION = recd.@pszText
   HeapFree GetProcessHeap, 0, BYVAL recd.pszText

END FUNCTION
' ========================================================================================

' ========================================================================================
' Saves text from a Rich Edit control to a file.
' Parameters:
' - hRichEdit = Handle of the Rich Edit control.
' - strFileName = Path of the file.
' - nMode (optional) = %SF_RTF (rich edit, default), %SF_TEXT (text).
' Return value:
'   The number of bytes saved.
' ========================================================================================
FUNCTION RichEdit_SaveRtfToFile (BYVAL hRichEdit AS DWORD, BYVAL strFileName AS STRING, OPTIONAL BYVAL nMode AS LONG) AS LONG

   DIM fAttr   AS DWORD    ' // File attributes
   DIM FileNum AS LONG     ' // File number
   DIM buffer  AS STRING   ' // String buffer

   ERRCLEAR
   fAttr = GETATTR(strFileName)
   IF ERR = 0 THEN
      IF ISTRUE(fAttr AND %FILE_ATTRIBUTE_DIRECTORY ) THEN EXIT FUNCTION
      KILL strFileName
      IF ERR THEN EXIT FUNCTION
   END IF

   ' // Get the text from the Rich Edit control
   buffer = RichEdit_GetRtfText(hRichEdit, nMode)

   ' // Save it to a file
   FileNum = FREEFILE
   OPEN strFileName FOR BINARY AS #FileNum
   PUT #FileNum, , buffer
   CLOSE #FileNum

   FUNCTION = LEN(buffer)

END FUNCTION
' ========================================================================================
