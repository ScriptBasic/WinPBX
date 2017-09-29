' ########################################################################################
' Microsoft Windows
' File: ToolbarCtrl.inc
' Contents: Toolbar Control Wrapper Functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TOOLBARCTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"

' ========================================================================================
' Adds one or more images to the list of button images available for a toolbar.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_AddBitmap (BYVAL hToolBar AS DWORD, BYVAL nButtons AS DWORD, BYREF tabm AS TBADDBITMAP) AS LONG
   FUNCTION = SendMessage (hToolBar, %TB_ADDBITMAP, nButtons, VARPTR(tabm))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Adds one or more buttons to a toolbar.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_AddButtonsA (BYVAL hToolBar AS DWORD, BYVAL uNumButtons AS DWORD, BYREF lpButtons AS TBBUTTON) AS LONG
   FUNCTION = SendMessageA(hToolBar, %TB_ADDBUTTONSA, uNumButtons, VARPTR(lpButtons))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ToolBar_AddButtonsW (BYVAL hToolBar AS DWORD, BYVAL uNumButtons AS DWORD, BYREF lpButtons AS TBBUTTON) AS LONG
   FUNCTION = SendMessageW(hToolBar, %TB_ADDBUTTONSW, uNumButtons, VARPTR(lpButtons))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ToolBar_AddButtons = ToolBar_AddButtonsW
#ELSE
   MACRO ToolBar_AddButtons = ToolBar_AddButtonsA
#ENDIF

' ========================================================================================
' Adds a button to a toolbar.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_AddButtonA (BYVAL hToolBar AS DWORD, BYVAL idxBitmap AS LONG, BYVAL idCommand AS LONG, _
   OPTIONAL BYVAL fsState AS BYTE, BYVAL fsStyle AS BYTE, BYVAL dwData AS DWORD, BYVAL strText AS STRING) AS LONG
   LOCAL tb AS TBBUTTON, idxString AS LONG
   IF fsState = 0 THEN fsState = %TBSTATE_ENABLED
   IF LEN(strText) = 0 THEN idxString = -1 ELSE idxString = STRPTR(strText)
   tb.iBitmap = idxBitmap
   tb.idCommand = idCommand
   tb.fsState = fsState
   tb.fsStyle = fsStyle
   tb.dwData = dwData
   tb.iString = idxString
   FUNCTION = SendMessageA(hToolBar, %TB_ADDBUTTONSA, 1, VARPTR(tb))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ToolBar_AddButtonW (BYVAL hToolBar AS DWORD, BYVAL idxBitmap AS LONG, BYVAL idCommand AS LONG, _
   OPTIONAL BYVAL fsState AS BYTE, BYVAL fsStyle AS BYTE, BYVAL dwData AS DWORD, BYVAL bstrText AS WSTRING) AS LONG
   LOCAL tb AS TBBUTTON, idxString AS LONG
   IF fsState = 0 THEN fsState = %TBSTATE_ENABLED
   IF LEN(bstrText) = 0 THEN idxString = -1 ELSE idxString = STRPTR(bstrText)
   tb.iBitmap = idxBitmap
   tb.idCommand = idCommand
   tb.fsState = fsState
   tb.fsStyle = fsStyle
   tb.dwData = dwData
   tb.iString = idxString
   FUNCTION = SendMessageW(hToolBar, %TB_ADDBUTTONSW, 1, VARPTR(tb))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ToolBar_AddButton = ToolBar_AddButtonW
#ELSE
   MACRO ToolBar_AddButton = ToolBar_AddButtonA
#ENDIF

' ========================================================================================
' Adds a separator to a toolbar.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_AddSeparatorA (BYVAL hToolBar AS DWORD, OPTIONAL BYVAL nWidth AS LONG) AS LONG
   LOCAL tb AS TBBUTTON
   tb.iBitmap = nWidth
   tb.idCommand = 0
   tb.fsState = %TBSTATE_ENABLED
   tb.fsStyle = %TBSTYLE_SEP
   tb.dwData = 0
   tb.iString = -1
   FUNCTION = SendMessageA(hToolBar, %TB_ADDBUTTONSA, 1, VARPTR(tb))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ToolBar_AddSeparatorW (BYVAL hToolBar AS DWORD, OPTIONAL BYVAL nWidth AS LONG) AS LONG
   LOCAL tb AS TBBUTTON
   tb.iBitmap = nWidth
   tb.idCommand = 0
   tb.fsState = %TBSTATE_ENABLED
   tb.fsStyle = %TBSTYLE_SEP
   tb.dwData = 0
   tb.iString = -1
   FUNCTION = SendMessageW(hToolBar, %TB_ADDBUTTONSW, 1, VARPTR(tb))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ToolBar_AddSeparator = ToolBar_AddSeparatorW
#ELSE
   MACRO ToolBar_AddSeparator = ToolBar_AddSeparatorA
#ENDIF

' ========================================================================================
' Adds a new string to the toolbar's string pool.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_AddStringA (BYVAL hToolBar AS DWORD, BYVAL hInst AS DWORD, BYVAL idString AS LONG) AS LONG
   FUNCTION = SendMessageA(hToolBar, %TB_ADDSTRINGA, hInst, IIF&(hInst = %NULL, idString, MAK(LONG, idString, 0)))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ToolBar_AddStringW (BYVAL hToolBar AS DWORD, BYVAL hInst AS DWORD, BYVAL idString AS LONG) AS LONG
   FUNCTION = SendMessageW(hToolBar, %TB_ADDSTRINGW, hInst, IIF&(hInst = %NULL, idString, MAK(LONG, idString, 0)))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ToolBar_AddString = ToolBar_AddStringW
#ELSE
   MACRO ToolBar_AddString = ToolBar_AddStringA
#ENDIF

' ========================================================================================
' Causes a toolbar to be resized.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
SUB ToolBar_AutoSize (BYVAL hToolBar AS DWORD)
   SendMessage hToolBar, %TB_AUTOSIZE, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves a count of the buttons currently in the toolbar.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_ButtonCount (BYVAL hToolBar AS DWORD) AS LONG
   FUNCTION = SendMessage (hToolBar, %TB_BUTTONCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Specifies the size of the TBBUTTON structure.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
SUB ToolBar_ButtonStructSize (BYVAL hToolBar AS DWORD, BYVAL cb AS LONG)
   SendMessage hToolBar, %TB_BUTTONSTRUCTSIZE, cb, 0
END SUB
' ========================================================================================

' ========================================================================================
' Changes the bitmap for a button in a toolbar.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_ChangeBitmap (BYVAL hToolBar AS DWORD, BYVAL idButton AS LONG, BYVAL iBitmap AS WORD) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_CHANGEBITMAP, idButton, MAK(DWORD, iBitmap, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Checks or unchecks a given button in a toolbar.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_CheckButton (BYVAL hToolBar AS DWORD, BYVAL idButton AS LONG, BYVAL fCheck AS INTEGER) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_CHECKBUTTON, idButton, MAK(LONG, fCheck, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the zero-based index for the button associated with the specified command
' identifier.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_CommandToIndex (BYVAL hToolBar AS DWORD, BYVAL idButton AS LONG) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_COMMANDTOINDEX, idButton, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Displays the Customize Toolbar dialog box.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
SUB ToolBar_Customize (BYVAL hToolBar AS DWORD)
   SendMessage hToolBar, %TB_CUSTOMIZE, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Deletes a button from the toolbar.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_DeleteButton (BYVAL hToolBar AS DWORD, BYVAL iButton AS LONG) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_DELETEBUTTON, iButton, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Enables the specified button in a toolbar.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_EnableButton (BYVAL hToolBar AS DWORD, BYVAL idButton AS LONG) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_ENABLEBUTTON, idButton, MAK(LONG, %TRUE, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Disables the specified button in a toolbar.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_DisableButton (BYVAL hToolBar AS DWORD, BYVAL idButton AS LONG) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_ENABLEBUTTON, idButton, MAK(LONG, %FALSE, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the anchor highlight setting for a toolbar.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_GetAnchorHighlight (BYVAL hToolBar AS DWORD) AS LONG
   FUNCTION = SendMessage (hToolBar, %TB_GETANCHORHIGHLIGHT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the index of the bitmap associated with a button in a toolbar.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_GetBitmap (BYVAL hToolBar AS DWORD, BYVAL idButton AS LONG) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_GETBITMAP, idButton, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the flags that describe the type of bitmap to be used.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_GetBitmapFlags (BYVAL hToolBar AS DWORD) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_GETBITMAPFLAGS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves information about the specified button in a toolbar.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_GetButton (BYVAL hToolBar AS DWORD, BYVAL iButton AS LONG, BYREF ptbb AS TBBUTTON) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_GETBUTTON, iButton, VARPTR(ptbb))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current height of toolbar buttons, in pixels.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_GetButtonHeight (BYVAL hToolBar AS DWORD) AS DWORD
   FUNCTION = HI(WORD, SendMessage(hToolBar, %TB_GETBUTTONSIZE, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves extended information for a button in a toolbar.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_GetButtonInfoA (BYVAL hToolBar AS DWORD, BYVAL iID AS LONG, BYREF lptbbi AS TBBUTTONINFOA) AS LONG
   FUNCTION = SendMessageA(hToolBar, %TB_GETBUTTONINFOA, iID, VARPTR(lptbbi))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ToolBar_GetButtonInfoW (BYVAL hToolBar AS DWORD, BYVAL iID AS LONG, BYREF lptbbi AS TBBUTTONINFOW) AS LONG
   FUNCTION = SendMessageW(hToolBar, %TB_GETBUTTONINFOW, iID, VARPTR(lptbbi))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ToolBar_GetButtonInfo = ToolBar_GetButtonInfoW
#ELSE
   MACRO ToolBar_GetButtonInfo = ToolBar_GetButtonInfoA
#ENDIF

' ========================================================================================
' Retrieves the current width and height of toolbar buttons, in pixels.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_GetButtonSize (BYVAL hToolBar AS DWORD) AS DWORD
   FUNCTION = SendMessage(hToolBar, %TB_GETBUTTONSIZE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the display text of a button on a toolbar.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_GetButtonTextA (BYVAL hToolBar AS DWORD, BYVAL idButton AS LONG) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   nLen = SendMessageA(hToolBar, %TB_GETBUTTONTEXTA, idButton, 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen + 1)
   nLen = SendMessageA(hToolBar, %TB_GETBUTTONTEXTA, idButton, STRPTR(buffer))
   IF nLen < 1 THEN EXIT FUNCTION
   FUNCTION = LEFT$(buffer, nLen)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ToolBar_GetButtonTextW (BYVAL hToolBar AS DWORD, BYVAL idButton AS LONG) AS WSTRING
   LOCAL nLen AS LONG
   LOCAL buffer AS WSTRING
   nLen = SendMessageW(hToolBar, %TB_GETBUTTONTEXTW, idButton, 0)
   IF nLen < 1 THEN EXIT FUNCTION
   buffer = SPACE$(nLen + 1)
   nLen = SendMessageW(hToolBar, %TB_GETBUTTONTEXTW, idButton, STRPTR(buffer))
   IF nLen < 1 THEN EXIT FUNCTION
   FUNCTION = LEFT$(buffer, nLen)
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ToolBar_GetButtonText = ToolBar_GetButtonTextW
#ELSE
   MACRO ToolBar_GetButtonText = ToolBar_GetButtonTextA
#ENDIF

' ========================================================================================
' Retrieves the length of the display text of a button on a toolbar.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_GetTextLength (BYVAL hToolBar AS DWORD, BYVAL idButton AS LONG) AS DWORD
   FUNCTION = SendMessage(hToolBar, %TB_GETBUTTONTEXT, idButton, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current width of toolbar buttons, in pixels.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_GetButtonWidth (BYVAL hToolBar AS DWORD) AS DWORD
   FUNCTION = LO(WORD, SendMessage(hToolBar, %TB_GETBUTTONSIZE, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the color scheme information from the toolbar control.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_GetColorScheme (BYVAL hToolBar AS DWORD, BYREF lpcs AS COLORSCHEME) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_GETCOLORSCHEME, 0, VARPTR(lpcs))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the image list that a toolbar control uses to display inactive buttons.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_GetDisabledImageList (BYVAL hToolBar AS DWORD) AS DWORD
   FUNCTION = SendMessage(hToolBar, %TB_GETDISABLEDIMAGELIST, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the extended styles for a toolbar control.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_GetExtendedStyle (BYVAL hToolBar AS DWORD) AS DWORD
   FUNCTION = SendMessage(hToolBar, %TB_GETEXTENDEDSTYLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the horizontal padding for a toolbar control.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_GetHorizontalPadding (BYVAL hToolBar AS DWORD) AS DWORD
   FUNCTION = LO(WORD, SendMessage(hToolBar, %TB_GETPADDING, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the image list that a toolbar control uses to display hot buttons.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_GetHotImageList (BYVAL hToolBar AS DWORD) AS DWORD
   FUNCTION = SendMessage(hToolBar, %TB_GETHOTIMAGELIST, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the index of the hot item in a toolbar.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_GetHotItem (BYVAL hToolBar AS DWORD) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_GETHOTITEM, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the image list that a toolbar control uses to display buttons in their default
' state. A toolbar control uses this image list to display buttons when they are not hot
' or disabled.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_GetImageList (BYVAL hToolBar AS DWORD) AS DWORD
   FUNCTION = SendMessage(hToolBar, %TB_GETIMAGELIST, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current insertion mark for the toolbar.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_GetInsertMark (BYVAL hToolBar AS DWORD, BYREF ptbim AS TBINSERTMARK) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_GETINSERTMARK, 0, VARPTR(ptbim))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the color used to draw the insertion mark for the toolbar.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_GetInsertMarkColor (BYVAL hToolBar AS DWORD) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_GETINSERTMARKCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the bounding rectangle of a button in a toolbar.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_GetItemRect (BYVAL hToolBar AS DWORD, BYVAL iButton AS LONG, BYREF lprc AS RECT) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_GETITEMRECT, iButton, VARPTR(lprc))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the total size of all of the visible buttons and separators in the toolbar.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_GetMaxSize (BYVAL hToolBar AS DWORD, BYREF psize AS SIZE) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_GETMAXSIZE, 0, VARPTR(psize))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the metrics of a toolbar control.
' Note  To use this API, you must provide a manifest specifying Comclt32.dll version 6.0.
' ========================================================================================
SUB ToolBar_GetMetrics (BYVAL hToolBar AS DWORD, BYREF ptbMetrics AS TBMETRICS)
   SendMessage hToolBar, %TB_GETMETRICS, 0, VARPTR(ptbMetrics)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the IDropTarget for a toolbar control.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_GetObject (BYVAL hToolBar AS DWORD, BYREF ppvObject AS IUnknown) AS LONG
   LOCAL IID_IDropTarget AS GUID
   IID_IDropTarget = GUID$("{00000122-0000-0000-C000-000000000046}")
   FUNCTION = SendMessage(hToolBar, %TB_GETOBJECT, VARPTR(IID_IDropTarget), VARPTR(ppvObject))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the padding for a toolbar control.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_GetPadding (BYVAL hToolBar AS DWORD) AS DWORD
   FUNCTION = SendMessage(hToolBar, %TB_GETPADDING, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the bounding rectangle for a specified toolbar button.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_GetRect (BYVAL hToolBar AS DWORD, BYVAL iID AS LONG, BYREF lprc AS RECT) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_GETRECT, iID, VARPTR(lprc))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the number of rows of buttons in a toolbar with the TBSTYLE_WRAPABLE style.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_GetRows (BYVAL hToolBar AS DWORD) AS DWORD
   FUNCTION = SendMessage(hToolBar, %TB_GETROWS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves information about the state of the specified button in a toolbar, such as
' whether it is enabled, pressed, or checked.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_GetState (BYVAL hToolBar AS DWORD, BYVAL idButton AS LONG) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_GETSTATE, idButton, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a string from a toolbar's string pool.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_GetStringA (BYVAL hToolBar AS DWORD, BYVAL iString AS INTEGER, OPTIONAL BYVAL cchMax AS INTEGER) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   IF cchMax < 1 THEN cchMax = 255
   buffer = SPACE$(cchMax + 1)
   nLen = SendMessageA(hToolBar, %TB_GETSTRINGA, MAK(DWORD, cchMax, iString), STRPTR(buffer))
   IF nLen < 1 THEN EXIT FUNCTION
   FUNCTION = LEFT$(buffer, nLen)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ToolBar_GetStringW (BYVAL hToolBar AS DWORD, BYVAL iString AS INTEGER, OPTIONAL BYVAL cchMax AS INTEGER) AS WSTRING
   LOCAL nLen AS LONG
   LOCAL buffer AS WSTRING
   IF cchMax < 1 THEN cchMax = 255
   buffer = SPACE$(cchMax + 1)
   nLen = SendMessageW(hToolBar, %TB_GETSTRINGW, MAK(DWORD, cchMax, iString), STRPTR(buffer))
   IF nLen < 1 THEN EXIT FUNCTION
   FUNCTION = LEFT$(buffer, nLen)
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ToolBar_GetString = ToolBar_GetStringW
#ELSE
   MACRO ToolBar_GetString = ToolBar_GetStringA
#ENDIF

' ========================================================================================
' Retrieves the styles currently in use for a toolbar control.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_GetStyle (BYVAL hToolBar AS DWORD) AS DWORD
   FUNCTION = SendMessage(hToolBar, %TB_GETSTYLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the maximum number of text rows that can be displayed on a toolbar button.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_GetTextRows (BYVAL hToolBar AS DWORD) AS DWORD
   FUNCTION = SendMessage(hToolBar, %TB_GETTEXTROWS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the handle to the ToolTip control, if any, associated with the toolbar.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_GetTooltips (BYVAL hToolBar AS DWORD) AS DWORD
   FUNCTION = SendMessage(hToolBar, %TB_GETTOOLTIPS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the Unicode character format flag for the control.
' Minimum operating systems: Windows NT 4.0, Windows 95
' ========================================================================================
FUNCTION ToolBar_GetUnicodeFormat (BYVAL hToolBar AS DWORD) AS DWORD
   FUNCTION = SendMessage(hToolBar, %TB_GETUNICODEFORMAT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the vertical padding for a toolbar control.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_GetVerticalPadding (BYVAL hToolBar AS DWORD) AS DWORD
   FUNCTION = HI(WORD, SendMessage(hToolBar, %TB_GETPADDING, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Hides or shows the specified button in a toolbar.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_HideButton (BYVAL hToolBar AS DWORD, BYVAL idButton AS LONG, BYVAL fShow AS INTEGER) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_HIDEBUTTON, idButton, MAK(LONG, fShow, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines where a point lies in a toolbar control.
' Minimum operating systems: Windows NT 4.0, Windows 95
' ========================================================================================
FUNCTION ToolBar_HitTest (BYVAL hToolBar AS DWORD, BYREF pptHitTest AS POINT) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_HITTEST, 0, VARPTR(pptHitTest))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets or clears the indeterminate state of the specified button in a toolbar.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_Indeterminate (BYVAL hToolBar AS DWORD, BYVAL idButton AS LONG, BYVAL fIndeterminate AS INTEGER) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_INDETERMINATE, idButton, MAK(LONG, fIndeterminate, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Inserts a button in a toolbar.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_InsButtonA (BYVAL hToolBar AS DWORD, BYVAL iButton AS LONG, BYREF lpButton AS TBBUTTON) AS LONG
   FUNCTION = SendMessageA(hToolBar, %TB_INSERTBUTTONA, iButton, VARPTR(lpButton))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ToolBar_InsButtonW (BYVAL hToolBar AS DWORD, BYVAL iButton AS LONG, BYREF lpButton AS TBBUTTON) AS LONG
   FUNCTION = SendMessageW(hToolBar, %TB_INSERTBUTTONW, iButton, VARPTR(lpButton))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ToolBar_InsButton = ToolBar_InsButtonW
#ELSE
   MACRO ToolBar_InsButton = ToolBar_InsButtonA
#ENDIF

' ========================================================================================
' Inserts a button in a toolbar.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_InsertButtonA (BYVAL hToolBar AS DWORD, BYVAL idxButton AS LONG, BYVAL idxBitmap AS LONG, BYVAL idCommand AS LONG, _
   OPTIONAL BYVAL fsState AS BYTE, BYVAL fsStyle AS BYTE, BYVAL dwData AS DWORD, BYVAL strText AS STRING) AS LONG
   LOCAL tb AS TBBUTTON, idxString AS LONG
   IF fsState = 0 THEN fsState = %TBSTATE_ENABLED
   IF LEN(strText) = 0 THEN idxString = -1 ELSE idxString = STRPTR(strText)
   tb.iBitmap = idxBitmap
   tb.idCommand = idCommand
   tb.fsState = fsState
   tb.fsStyle = fsStyle
   tb.dwData = dwData
   tb.iString = idxString
   FUNCTION = SendMessageA(hToolBar, %TB_INSERTBUTTONA, idxButton, VARPTR(tb))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ToolBar_InsertButtonW (BYVAL hToolBar AS DWORD, BYVAL idxButton AS LONG, BYVAL idxBitmap AS LONG, BYVAL idCommand AS LONG, _
   OPTIONAL BYVAL fsState AS BYTE, BYVAL fsStyle AS BYTE, BYVAL dwData AS DWORD, BYVAL bstrText AS WSTRING) AS LONG
   LOCAL tb AS TBBUTTON, idxString AS LONG
   IF fsState = 0 THEN fsState = %TBSTATE_ENABLED
   IF LEN(bstrText) = 0 THEN idxString = -1 ELSE idxString = STRPTR(bstrText)
   tb.iBitmap = idxBitmap
   tb.idCommand = idCommand
   tb.fsState = fsState
   tb.fsStyle = fsStyle
   tb.dwData = dwData
   tb.iString = idxString
   FUNCTION = SendMessageW(hToolBar, %TB_INSERTBUTTONW, idxButton, VARPTR(tb))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ToolBar_InsertButton = ToolBar_InsertButtonW
#ELSE
   MACRO ToolBar_InsertButton = ToolBar_InsertButtonA
#ENDIF

' ========================================================================================
' Adds a separator to a toolbar.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_InsertSeparatorA (BYVAL hToolBar AS DWORD, BYVAL idxButton AS LONG, OPTIONAL BYVAL nWidth AS LONG) AS LONG
   LOCAL tb AS TBBUTTON
   tb.iBitmap = nWidth
   tb.idCommand = 0
   tb.fsState = %TBSTATE_ENABLED
   tb.fsStyle = %TBSTYLE_SEP
   tb.dwData = 0
   tb.iString = -1
   FUNCTION = SendMessageA(hToolBar, %TB_INSERTBUTTONA, idxButton, VARPTR(tb))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ToolBar_InsertSeparatorW (BYVAL hToolBar AS DWORD, BYVAL idxButton AS LONG, OPTIONAL BYVAL nWidth AS LONG) AS LONG
   LOCAL tb AS TBBUTTON
   tb.iBitmap = nWidth
   tb.idCommand = 0
   tb.fsState = %TBSTATE_ENABLED
   tb.fsStyle = %TBSTYLE_SEP
   tb.dwData = 0
   tb.iString = -1
   FUNCTION = SendMessageA(hToolBar, %TB_INSERTBUTTONW, idxButton, VARPTR(tb))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ToolBar_InsertSeparator = ToolBar_InsertSeparatorW
#ELSE
   MACRO ToolBar_InsertSeparator = ToolBar_InsertSeparatorA
#ENDIF

' ========================================================================================
' Retrieves the insertion mark information for a point in a toolbar.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_InsertMarkHitTest (BYVAL hToolBar AS DWORD, BYREF lppt AS POINT, BYREF lptbim AS TBINSERTMARK) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_INSERTMARKHITTEST, VARPTR(lppt), VARPTR(lptbim))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether the specified button in a toolbar is checked.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_IsButtonChecked (BYVAL hToolBar AS DWORD, BYVAL idButton AS LONG) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_ISBUTTONCHECKED, idButton, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether the specified button in a toolbar is enabled.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_IsButtonEnabled (BYVAL hToolBar AS DWORD, BYVAL idButton AS LONG) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_ISBUTTONENABLED, idButton, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether the specified button in a toolbar is hidden.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_IsButtonHidden (BYVAL hToolBar AS DWORD, BYVAL idButton AS LONG) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_ISBUTTONHIDDEN, idButton, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Checks the highlight state of a toolbar button.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_IsButtonHighlighted (BYVAL hToolBar AS DWORD, BYVAL idButton AS LONG) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_ISBUTTONHIGHLIGHTED, idButton, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether the specified button in a toolbar is indeterminate.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_IsButtonIndeterminate (BYVAL hToolBar AS DWORD, BYVAL idButton AS LONG) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_ISBUTTONINDETERMINATE, idButton, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether the specified button in a toolbar is pressed.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_IsButtonPressed (BYVAL hToolBar AS DWORD, BYVAL idButton AS LONG) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_ISBUTTONPRESSED, idButton, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads system-defined button images into a toolbar control's image list.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_LoadImages (BYVAL hToolBar AS DWORD, BYVAL iBitmapID AS DWORD, BYVAL hinst AS DWORD) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_LOADIMAGES, iBitmapID, hinst)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines the ID of the button that corresponds to the specified accelerator character.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_MapAccelerator (BYVAL hToolBar AS DWORD, BYVAL chAccel AS DWORD, BYREF pIDBtn AS DWORD) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_MAPACCELERATOR, chAccel, VARPTR(pIDBtn))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the highlight state of a given button in a toolbar control.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_MarkButton (BYVAL hToolBar AS DWORD, BYVAL idButton AS LONG, BYVAL fHighlight AS INTEGER) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_MARKBUTTON, idButton, MAK(LONG, fHighlight, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Moves a button from one index to another.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_MoveButton (BYVAL hToolBar AS DWORD, BYVAL uOldPos AS DWORD, BYVAL uNewPos AS DWORD) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_MOVEBUTTON, uOldPos, uNewPos)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Presses or releases the specified button in a toolbar.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_PressButton (BYVAL hToolBar AS DWORD, BYVAL idButton AS LONG, BYVAL fPress AS INTEGER) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_PRESSBUTTON, idButton, MAK(LONG, fPress, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Replaces an existing bitmap with a new bitmap.
' Minimum operating systems Windows NT 4.0, Windows 95
' ========================================================================================
FUNCTION ToolBar_ReplaceBitmap (BYVAL hToolBar AS DWORD, BYREF ptbrb AS TBREPLACEBITMAP) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_REPLACEBITMAP, 0, VARPTR(ptbrb))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Send this message to initiate saving or restoring a toolbar state.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
SUB ToolBar_SaveRestore (BYVAL hToolBar AS DWORD, BYVAL fSave AS LONG, BYREF ptbsp AS TBSAVEPARAMS)
   SendMessage hToolBar, %TB_SAVERESTORE, fSave, VARPTR(ptbsp)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the anchor highlight setting for a toolbar.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_SetAnchorHighlight (BYVAL hToolBar AS DWORD, BYVAL fAnchor AS LONG) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_SETANCHORHIGHLIGHT, fAnchor, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the size of the bitmapped images to be added to a toolbar.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_SetBitmapSize (BYVAL hToolBar AS DWORD, BYVAL dxBitmap AS INTEGER, BYVAL dyBitmap AS INTEGER) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_SETBITMAPSIZE, 0, MAK(LONG, dxBitmap, dyBitmap))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the information for an existing button in a toolbar.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_SetButtonInfoA (BYVAL hToolBar AS DWORD, BYVAL iID AS LONG, BYREF lptbbi AS TBBUTTONINFOA) AS LONG
   FUNCTION = SendMessageA(hToolBar, %TB_SETBUTTONINFOA, iID, VARPTR(lptbbi))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ToolBar_SetButtonInfoW (BYVAL hToolBar AS DWORD, BYVAL iID AS LONG, BYREF lptbbi AS TBBUTTONINFOW) AS LONG
   FUNCTION = SendMessageW(hToolBar, %TB_SETBUTTONINFOW, iID, VARPTR(lptbbi))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ToolBar_SetButtonInfo = ToolBar_SetButtonInfoW
#ELSE
   MACRO ToolBar_SetButtonInfo = ToolBar_SetButtonInfoA
#ENDIF

' ========================================================================================
' Sets the size of the buttons to be added to a toolbar.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_SetButtonSize (BYVAL hToolBar AS DWORD, BYVAL dxButton AS INTEGER, BYVAL dyButton AS INTEGER) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_SETBUTTONSIZE, 0, MAK(LONG, dxButton, dyButton))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the minimum and maximum button widths in the toolbar control.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_SetButtonWidth (BYVAL hToolBar AS DWORD, BYVAL cxMin AS INTEGER, BYVAL cxMax AS INTEGER) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_SETBUTTONWIDTH, 0, MAK(LONG, cxMin, cxMax))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the command identifier of a toolbar button.
' Minimum operating systems Windows NT 3.51, Windows 95
' ========================================================================================
FUNCTION ToolBar_SetCmdId (BYVAL hToolBar AS DWORD, BYVAL index AS INTEGER, BYVAL cmdid AS INTEGER) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_SETCMDID, index, cmdid)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the color scheme information for the toolbar control.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
SUB ToolBar_SetColorScheme (BYVAL hToolBar AS DWORD, BYREF lpcs AS COLORSCHEME)
   SendMessage hToolBar, %TB_SETCOLORSCHEME, 0, VARPTR(lpcs)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the image list that the toolbar control will use to display disabled buttons.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_SetDisabledImageList (BYVAL hToolBar AS DWORD, BYVAL himlNewDisabled AS DWORD) AS DWORD
   FUNCTION = SendMessage(hToolBar, %TB_SETDISABLEDIMAGELIST, 0, himlNewDisabled)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the text drawing flags for the toolbar.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_SetDrawTextFlags (BYVAL hToolBar AS DWORD, BYVAL dwMask AS LONG, BYVAL dwDTFlags AS LONG) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_SETDRAWTEXTFLAGS, dwMask, dwDTFlags)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the extended styles for a toolbar control.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_SetExtendedStyle (BYVAL hToolBar AS DWORD, BYVAL dwExStyle AS DWORD) AS DWORD
   FUNCTION = SendMessage(hToolBar, %TB_SETEXTENDEDSTYLE, 0, dwExStyle)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the image list that the toolbar control will use to display hot buttons.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_SetHotImageList (BYVAL hToolBar AS DWORD, BYVAL himlNewHot AS DWORD) AS DWORD
   FUNCTION = SendMessage(hToolBar, %TB_SETHOTIMAGELIST, 0, himlNewHot)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the hot item in a toolbar.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_SetHotItem (BYVAL hToolBar AS DWORD, BYVAL iHot AS LONG) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_SETHOTITEM, iHot, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the image list that the toolbar will use to display buttons that are in their
' default state.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_SetImageList (BYVAL hToolBar AS DWORD, BYVAL himlNew AS DWORD) AS DWORD
   FUNCTION = SendMessage(hToolBar, %TB_SETIMAGELIST, 0, himlNew)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the indentation for the first button in a toolbar control.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_SetIndent (BYVAL hToolBar AS DWORD, BYVAL iIndent AS LONG) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_SETINDENT, iIndent, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the current insertion mark for the toolbar.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
SUB ToolBar_SetInsertMark (BYVAL hToolBar AS DWORD, BYREF lptbim AS TBINSERTMARK)
   SendMessage hToolBar, %TB_SETINSERTMARK, 0, VARPTR(lptbim)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the color used to draw the insertion mark for the toolbar.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_SetInsertMarkColor (BYVAL hToolBar AS DWORD, BYVAL clrInsertMark AS LONG) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_SETINSERTMARKCOLOR, clrInsertMark, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the distance between the toolbar buttons on a specific toolbar.
' Minimum operating systems Windows Vista
' ========================================================================================
SUB ToolBar_SetListGap (BYVAL hToolBar AS DWORD, BYVAL gap AS DWORD)
   SendMessage hToolBar, %TB_SETLISTGAP, gap, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the maximum number of text rows displayed on a toolbar button.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_SetMaxTextRows (BYVAL hToolBar AS DWORD, BYVAL iMaxRows AS LONG) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_SETMAXTEXTROWS, iMaxRows, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the metrics of a toolbar control.
' Minimum operating systems: Windows XP
' ========================================================================================
SUB ToolBar_SetMetrics (BYVAL hToolBar AS DWORD, BYREF ptbMetrics AS TBMETRICS)
   SendMessage hToolBar, %TB_SETMETRICS, 0, VARPTR(ptbmetrics)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the padding for a toolbar control.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
FUNCTION ToolBar_SetPadding (BYVAL hToolbar AS DWORD, BYVAL cx AS INTEGER, BYVAL cy AS INTEGER) AS DWORD
   FUNCTION = SendMessage(hToolBar, %TB_SETPADDING, 0, MAK(DWORD, cx, cy))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the window to which the toolbar control sends notification messages.
' Minimum operating systems: Windows NT 3.51, Windows 95.
' ========================================================================================
FUNCTION ToolBar_SetParent (BYVAL hToolBar AS DWORD, BYVAL hwndParent AS DWORD) AS DWORD
   FUNCTION = SendMessage(hToolBar, %TB_SETPARENT, hwndParent, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the image list that the toolbar uses to display buttons that are in a pressed state.
' Minimum operating systems: Windows Vista
' ========================================================================================
FUNCTION ToolBar_SetPressedImageList (BYVAL hToolBar AS DWORD, BYVAL iImageID AS DWORD, BYVAL himlNew AS DWORD) AS DWORD
   FUNCTION = SendMessage(hToolBar, %TB_SETPRESSEDIMAGELIST, iImageID, himlNew)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the number of rows of buttons in a toolbar.
' Minimum operating systems: Windows NT 3.51, Windows 95.
' ========================================================================================
SUB ToolBar_SetRows (BYVAL hToolBar AS DWORD, BYVAL cRows AS WORD, BYVAL fLarger AS INTEGER, BYREF lprc AS RECT)
   SendMessage hToolBar, %TB_SETROWS, MAK(DWORD, cRows, fLarger), VARPTR(lprc)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the state for the specified button in a toolbar.
' Minimum operating systems: Windows NT 3.51, Windows 95.
' ========================================================================================
FUNCTION ToolBar_SetState (BYVAL hToolBar AS DWORD, BYVAL idButton AS LONG, BYVAL fState AS INTEGER) AS LONG
   FUNCTION = SendMessage(hToolBar, %TB_SETSTATE, idButton, MAK(LONG, fState, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the style for a toolbar control.
' Minimum operating systems Windows 2000, Windows NT 4.0 with Internet Explorer 4.0,
' Windows 98, Windows 95 with Internet Explorer 4.0
' ========================================================================================
SUB ToolBar_SetStyle (BYVAL hToolBar AS DWORD, BYVAL dwStyle AS DWORD)
   SendMessage hToolBar, %TB_SETSTYLE, 0, dwStyle
END SUB
' ========================================================================================

' ========================================================================================
' Associates a ToolTip control with a toolbar.
' Minimum operating systems: Windows NT 3.51, Windows 95.
' ========================================================================================
SUB ToolBar_SetToolTips (BYVAL hToolBar AS DWORD, BYVAL hwndToolTip AS DWORD)
   SendMessage hToolBar, %TB_SETTOOLTIPS, hwndToolTip, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the Unicode character format flag for the control. This message allows you to
' change the character set used by the control at run time rather than having to re-create
' the control.
' Minimum operating systems: Windows NT 4.0, Windows 95.
' ========================================================================================
FUNCTION ToolBar_SetUnicodeFormat (BYVAL hToolBar AS DWORD, BYVAL fUnicode AS DWORD) AS DWORD
   FUNCTION = SendMessage(hToolBar, %TB_SETUNICODEFORMAT, fUnicode, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the visual style of a toolbar control.
' Note: To use this API, you must provide a manifest specifying Comclt32.dll version 6.0.
' Minimum Operating System: Windows XP.
' ========================================================================================
SUB ToolBar_SetWindowTheme (BYVAL hToolBar AS DWORD, BYREF wszTheme AS WSTRINGZ)
   SendMessage hToolBar, %TB_SETWINDOWTHEME, VARPTR(wszTheme), 0
END SUB
' ========================================================================================

' ========================================================================================
' Makes the toolbar opaque by removing the TBSTYLE_TRANSPARENT style.
' ========================================================================================
SUB ToolBar_MakeOpaque (BYVAL hToolBar AS DWORD)
   SetWindowLong hToolBar, %GWL_STYLE, GetWindowLong(hToolBar, %GWL_STYLE) AND NOT %TBSTYLE_TRANSPARENT
END SUB
' ========================================================================================
