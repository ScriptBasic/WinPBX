' ########################################################################################
' Microsoft Windows
' File: ComboBoxCtrl.inc
' Contents: Combo Box control wrapper functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%COMBOBOXCTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"

' ========================================================================================
' Enables or disables a combobox
' ========================================================================================
FUNCTION ComboBox_Enable (BYVAL hComboBox AS DWORD, BYVAL fEnable AS LONG) AS LONG
   FUNCTION = EnableWindow(hComboBox, fEnable)
END FUNCTION
MACRO Combo_Enable = ComboBox_Enable
' ========================================================================================

' ========================================================================================
' Adds a string to the list box of a combo box. If the combo box does not have the
' CBS_SORT style, the string is added to the end of the list.
' ========================================================================================
FUNCTION Combobox_AddStringA (BYVAL hComboBox AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hComboBox, %CB_ADDSTRING, 0, STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Combobox_AddStringW (BYVAL hComboBox AS DWORD, BYVAL bstrText AS WSTRING) AS LONG
   FUNCTION = SendMessageW(hComboBox, %CB_ADDSTRING, 0, STRPTR(bstrText))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Combobox_AddString = Combobox_AddStringW
   MACRO Combo_AddString = Combobox_AddStringW
#ELSE
   MACRO Combobox_AddString = Combobox_AddStringA
   MACRO Combo_AddString = Combobox_AddStringA
#ENDIF

' ========================================================================================
' Deletes a string in the list box of a combo box.
' ========================================================================================
FUNCTION ComboBox_DeleteString (BYVAL hComboBox AS DWORD, BYVAL Index AS DWORD) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_DELETESTRING, Index, 0)
END FUNCTION
MACRO Combo_DeleteString = ComboBox_DeleteString
' ========================================================================================

' ========================================================================================
' Adds names to the list displayed by the combo box. The message adds the names of
' directories and files that match a specified string and set of file attributes.
' CB_DIR can also add mapped drive letters to the list.
' ========================================================================================
FUNCTION ComboBox_DirA (BYVAL hComboBox AS DWORD, BYVAL Attr AS DWORD, BYVAL strFileSpec AS STRING) AS LONG
   FUNCTION = SendMessageA(hComboBox, %CB_DIR, Attr, STRPTR(strFileSpec))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ComboBox_DirW (BYVAL hComboBox AS DWORD, BYVAL Attr AS DWORD, BYVAL bstrFileSpec AS WSTRING) AS LONG
   FUNCTION = SendMessageW(hComboBox, %CB_DIR, Attr, STRPTR(bstrFileSpec))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ComboBox_Dir = ComboBox_DirW
   MACRO Combo_Dir = ComboBox_DirW
#ELSE
   MACRO ComboBox_Dir = ComboBox_DirA
   MACRO Combo_Dir = ComboBox_DirA
#ENDIF

' ========================================================================================
' Searches the list box of a combo box for an item beginning with the characters in a
' specified string.
' ========================================================================================
FUNCTION ComboBox_FindStringA (BYVAL hComboBox AS DWORD, BYVAL Start AS LONG, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hComboBox, %CB_FINDSTRING, Start, STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ComboBox_FindStringW (BYVAL hComboBox AS DWORD, BYVAL Start AS LONG, BYVAL bstrText AS WSTRING) AS LONG
   FUNCTION = SendMessageW(hComboBox, %CB_FINDSTRING, Start, STRPTR(bstrText))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ComboBox_FindString = ComboBox_FindStringW
   MACRO Combo_FindString = ComboBox_FindStringW
#ELSE
   MACRO ComboBox_FindString = ComboBox_FindStringA
   MACRO Combo_FindString = ComboBox_FindStringA
#ENDIF

' ========================================================================================
' Finds the first list box string in a combo box that matches the string specified in the
' start parameter.
' ========================================================================================
FUNCTION ComboBox_FindStringExactA (BYVAL hComboBox AS DWORD, BYVAL Start AS LONG, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hComboBox, %CB_FINDSTRINGEXACT, Start, STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ComboBox_FindStringExactW (BYVAL hComboBox AS DWORD, BYVAL Start AS LONG, BYVAL bstrText AS WSTRING) AS LONG
   FUNCTION = SendMessageW(hComboBox, %CB_FINDSTRINGEXACT, Start, STRPTR(bstrText))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ComboBox_FindStringExact = ComboBox_FindStringExactW
   MACRO Combo_FindStringExact = ComboBox_FindStringExactW
#ELSE
   MACRO ComboBox_FindStringExact = ComboBox_FindStringExactA
   MACRO Combo_FindStringExact = ComboBox_FindStringExactA
#ENDIF

' ========================================================================================
' Retrieves information about the specified combo box.
' ========================================================================================
FUNCTION ComboBox_GetComboBoxInfo (BYVAL hComboBox AS DWORD, BYREF pcbi AS COMBOBOXINFO) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_GETCOMBOBOXINFO, 0, VARPTR(pcbi))
END FUNCTION
MACRO Combo_GetComboBoxInfo = ComboBox_GetComboBoxInfo
' ========================================================================================

' ========================================================================================
' Retrieves the handle to the edit box of the combobox
' ========================================================================================
FUNCTION ComboBox_GetEditBoxHandle (BYVAL hComboBox AS DWORD) AS DWORD
   LOCAL tci AS COMBOBOXINFO
   tci.cbSize = SIZEOF(COMBOBOXINFO)
   IF SendMessage(hComboBox, %CB_GETCOMBOBOXINFO, 0, VARPTR(tci)) = 0 THEN EXIT FUNCTION
   FUNCTION = tci.hwndItem
END FUNCTION
MACRO Combo_GetEditBoxHandle = ComboBox_GetEditBoxHandle
' ========================================================================================

' ========================================================================================
' Retrieves the handle to the drop down of the combobox
' ========================================================================================
FUNCTION ComboBox_GetListBoxHandle (BYVAL hComboBox AS DWORD) AS DWORD
   LOCAL tci AS COMBOBOXINFO
   tci.cbSize = SIZEOF(COMBOBOXINFO)
   IF SendMessage(hComboBox, %CB_GETCOMBOBOXINFO, 0, VARPTR(tci)) = 0 THEN EXIT FUNCTION
   FUNCTION = tci.hwndList
END FUNCTION
MACRO Combo_GetListBoxHandle = ComboBox_GetListBoxHandle
' ========================================================================================

' ========================================================================================
' Retrieves the number of items in the list box of a combo box.
' ========================================================================================
FUNCTION ComboBox_GetCount (BYVAL hComboBox AS DWORD) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_GETCOUNT, 0, 0)
END FUNCTION
MACRO Combo_GetCount = ComboBox_GetCount
' ========================================================================================

' ========================================================================================
' Gets the cue banner text displayed in the edit control of a combo box.
' ========================================================================================
FUNCTION ComboBox_GetCueBannerText (BYVAL hComboBox AS DWORD, BYREF lpcwText AS WSTRINGZ, BYVAL cchText AS DWORD) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_GETCUEBANNER, VARPTR(lpcwText), cchText)
END FUNCTION
MACRO Combo_GetCueBannerText = ComboBox_GetCueBannerText
' ========================================================================================

' ========================================================================================
' Retrieves the index of the currently selected item, if any, in the list box of a combo box.
' ========================================================================================
FUNCTION ComboBox_GetCurSel (BYVAL hComboBox AS DWORD) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_GETCURSEL, 0, 0)
END FUNCTION
MACRO Combo_GetCurSel = ComboBox_GetCurSel
' ========================================================================================

' ========================================================================================
' Retrieves the screen coordinates of a combo box in its dropped-down state
' ========================================================================================
#IF %DEF(%USEPBDECL)
MACRO ComboBox_GetDroppedControlRect(hwndCtl, lprc)=SendMessage(hwndCtl, %CB_GETDROPPEDCONTROLRECT, 0, lprc)
#ELSE
FUNCTION ComboBox_GetDroppedControlRect (BYVAL hComboBox AS DWORD, BYREF prect AS RECT) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_GETDROPPEDCONTROLRECT,  0, VARPTR(prect))
END FUNCTION
#ENDIF
MACRO Combo_GetDroppedControlRect = ComboBox_GetDroppedControlRect
' ========================================================================================

' ========================================================================================
' Determines whether the list box of a combo box is dropped down.
' ========================================================================================
FUNCTION ComboBox_GetDroppedState (BYVAL hComboBox AS DWORD) AS LONG
   FUNCTION = ISTRUE(SendMessage(hComboBox, %CB_GETDROPPEDSTATE, 0, 0))
END FUNCTION
MACRO Combo_GetDroppedState = ComboBox_GetDroppedState
' ========================================================================================

' ========================================================================================
' Retrieves the minimum allowable width, in pixels, of the list box of a combo box with
' the CBS_DROPDOWN or CBS_DROPDOWNLIST style.
' ========================================================================================
FUNCTION ComboBox_GetDroppedWidth (BYVAL hComboBox AS DWORD) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_GETDROPPEDWIDTH, 0, 0)
END FUNCTION
MACRO Combo_GetDroppedWidth = ComboBox_GetDroppedWidth
' ========================================================================================

' ========================================================================================
' Gets the starting and ending character positions of the current selection in the edit
' control of a combo box.
' ========================================================================================
SUB ComboBox_GetEditSel (BYVAL hComboBox AS DWORD, BYREF lpStart AS LONG, BYREF lpEnd AS LONG)
   SendMessage hComboBox, %CB_GETEDITSEL, VARPTR(lpStart), VARPTR(lpEnd)
END SUB
MACRO Combo_GetEditSel = ComboBox_GetEditSel
' ========================================================================================

' ========================================================================================
' Determines whether a combo box has the default user interface or the extended user interface.
' ========================================================================================
FUNCTION ComboBox_GetExtendedUI (BYVAL hComboBox AS DWORD) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_GETEXTENDEDUI, 0, 0)
END FUNCTION
MACRO Combo_GetExtendedUI = ComboBox_GetExtendedUI
' ========================================================================================

' ========================================================================================
' Retrieves from a combo box the width, in pixels, by which the list box can be scrolled
' horizontally (the scrollable width). This is applicable only if the list box has a
' horizontal scroll bar.
' ========================================================================================
FUNCTION ComboBox_GetHorizontalExtent (BYVAL hComboBox AS DWORD) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_GETHORIZONTALEXTENT, 0, 0)
END FUNCTION
MACRO Combo_GetHorizontalExtent = ComboBox_GetHorizontalExtent
' ========================================================================================

' ========================================================================================
' Retrieves the application-supplied value associated with the specified item in the combo box.
' ========================================================================================
FUNCTION ComboBox_GetItemData (BYVAL hComboBox AS DWORD, BYVAL index AS LONG) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_GETITEMDATA, IIF&((index < 0), ComboBox_GetCurSel(hComboBox), index), 0)
END FUNCTION
MACRO Combo_GetItemData = ComboBox_GetItemData
' ========================================================================================

' ========================================================================================
' Retrieves the height of list items in a combo box.
' ========================================================================================
FUNCTION ComboBox_GetItemHeight (BYVAL hComboBox AS DWORD) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_GETITEMHEIGHT, 0, 0)
END FUNCTION
MACRO Combo_GetItemHeight = ComboBox_GetItemHeight
' ========================================================================================

' ========================================================================================
' Gets a string from the list of a combo box.
' ========================================================================================
FUNCTION ComboBox_GetLbTextA (BYVAL hComboBox AS DWORD, BYVAL Index AS LONG) AS STRING
   LOCAL strText AS STRING
   LOCAL nLen AS LONG
   IF Index < 0 THEN Index = ComboBox_GetCurSel(hComboBox)
   nLen = Combobox_GetLbTextLen(hComboBox, Index)
   strText = SPACE$(nLen + 1)
   SendMessageA hComboBox, %CB_GETLBTEXT, Index, STRPTR(strText)
   FUNCTION = LEFT$(strText, nLen)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ComboBox_GetLbTextW (BYVAL hComboBox AS DWORD, BYVAL Index AS LONG) AS WSTRING
   LOCAL bstrText AS WSTRING
   LOCAL nLen AS LONG
   IF Index < 0 THEN Index = ComboBox_GetCurSel(hComboBox)
   nLen = Combobox_GetLbTextLen(hComboBox, Index)
   bstrText = SPACE$(nLen + 1)
   SendMessageW hComboBox, %CB_GETLBTEXT, Index, STRPTR(bstrText)
   FUNCTION = LEFT$(bstrText, nLen)
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ComboBox_GetLbText = ComboBox_GetLbTextW
   MACRO Combo_GetLbText = ComboBox_GetLbTextW
#ELSE
   MACRO ComboBox_GetLbText = ComboBox_GetLbTextA
   MACRO Combo_GetLbText = ComboBox_GetLbTextA
#ENDIF

' ========================================================================================
' Retrieve the length, in characters, of a string in the list of a combo box.
' ========================================================================================
FUNCTION ComboBox_GetLbTextLen (BYVAL hComboBox AS DWORD, BYVAL index AS LONG) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_GETLBTEXTLEN, Index, 0)
END FUNCTION
MACRO Combo_GetLbTextLen = ComboBox_GetLbTextLen
' ========================================================================================

' ========================================================================================
' Retrieves the current locale of the combo box. The locale is used to determine the
' correct sorting order of displayed text for combo boxes with the CBS_SORT style and text
' added by using the CB_ADDSTRING message.
' ========================================================================================
FUNCTION ComboBox_GetLocale (BYVAL hComboBox AS DWORD) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_GETLOCALE, 0, 0)
END FUNCTION
MACRO Combo_GetLocale = ComboBox_GetLocale
' ========================================================================================

' ========================================================================================
' Gets the minimum number of visible items in the drop-down list of a combo box.
' ========================================================================================
FUNCTION ComboBox_GetMinVisible (BYVAL hComboBox AS DWORD) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_GETMINVISIBLE, 0, 0)
END FUNCTION
MACRO Combo_GetMinVisible = ComboBox_GetMinVisible
' ========================================================================================

' ========================================================================================
' Retrieves the zero-based index of the first visible item in the list box portion of a
' combo box. Initially, the item with index 0 is at the top of the list box, but if the
' list box contents have been scrolled, another item may be at the top.
' ========================================================================================
FUNCTION ComboBox_GetTopIndex (BYVAL hComboBox AS DWORD) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_GETTOPINDEX, 0, 0)
END FUNCTION
MACRO Combo_GetTopIndex = ComboBox_GetTopIndex
' ========================================================================================

' ========================================================================================
' Allocates memory for storing list box items. An application sends the CB_INITSTORAGE
' message before adding a large number of items to the list box portion of a combo box.
' ========================================================================================
FUNCTION ComboBox_InitStorage (BYVAL hComboBox AS DWORD, BYVAL items AS LONG, BYVAL cb AS LONG) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_INITSTORAGE, items, cb)
END FUNCTION
MACRO Combo_InitStorage = ComboBox_InitStorage
' ========================================================================================

' ========================================================================================
' Inserts a string into the list box of a combo box. Unlike the CB_ADDSTRING message, the
' CB_INSERTSTRING message does not cause a list with the CBS_SORT style to be sorted.
' ========================================================================================
FUNCTION ComboBox_InsertStringA (BYVAL hComboBox AS DWORD, BYVAL Index AS LONG, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hComboBox, %CB_INSERTSTRING, Index, STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ComboBox_InsertStringW (BYVAL hComboBox AS DWORD, BYVAL Index AS LONG, BYVAL bstrText AS WSTRING) AS LONG
   FUNCTION = SendMessageW(hComboBox, %CB_INSERTSTRING, Index, STRPTR(bstrText))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ComboBox_InsertString = ComboBox_InsertStringW
   MACRO Combo_InsertString = ComboBox_InsertStringW
#ELSE
   MACRO ComboBox_InsertString = ComboBox_InsertStringA
   MACRO Combo_InsertString = ComboBox_InsertStringA
#ENDIF

' ========================================================================================
' Limits the length of the text the user may type into the edit control of a combo box.
' ========================================================================================
SUB ComboBox_LimitText (BYVAL hComboBox AS DWORD, BYVAL chLimit AS DWORD)
   SendMessage hComboBox, %CB_LIMITTEXT, chLimit, 0
END SUB
MACRO Combo_LimitText = ComboBox_LimitText
' ========================================================================================

' ========================================================================================
' Removes all items from the list box and edit control of a combo box.
' ========================================================================================
SUB ComboBox_ResetContent (BYVAL hComboBox AS DWORD)
   SendMessage hComboBox, %CB_RESETCONTENT, 0, 0
END SUB
MACRO Combo_ResetContent = ComboBox_ResetContent
' ========================================================================================

' ========================================================================================
' Searches the list of a combo box for an item that begins with the characters in a
' specified string. If a matching item is found, it is selected and copied to the edit control.
' ========================================================================================
FUNCTION ComboBox_SelectStringA (BYVAL hComboBox AS DWORD, BYVAL Index AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hComboBox, %CB_SELECTSTRING, Index, STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ComboBox_SelectStringW (BYVAL hComboBox AS DWORD, BYVAL Index AS DWORD, BYVAL bstrText AS WSTRING) AS LONG
   FUNCTION = SendMessageW(hComboBox, %CB_SELECTSTRING, Index, STRPTR(bstrText))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ComboBox_SelectString = ComboBox_SelectStringW
   MACRO Combo_SelectString = ComboBox_SelectStringW
#ELSE
   MACRO ComboBox_SelectString = ComboBox_SelectStringA
   MACRO Combo_SelectString = ComboBox_SelectStringA
#ENDIF

' ========================================================================================
' Gets the cue banner text displayed in the edit control of a combo box.
' ========================================================================================
FUNCTION ComboBox_SetCueBannerText (BYVAL hComboBox AS DWORD, BYREF wszText AS WSTRINGZ) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_SETCUEBANNER, 0, VARPTR(wszText))
END FUNCTION
MACRO Combo_SetCueBannerText = ComboBox_SetCueBannerText
' ========================================================================================

' ========================================================================================
' Selects a string in the list of a combo box. If necessary, the list scrolls the string
' into view. The text in the edit control of the combo box changes to reflect the new
' selection, and any previous selection in the list is removed.
' ========================================================================================
FUNCTION ComboBox_SetCurSel (BYVAL hComboBox AS DWORD, BYVAL Index AS DWORD) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_SETCURSEL, Index, 0)
END FUNCTION
MACRO Combo_SetCurSel = ComboBox_SetCurSel
' ========================================================================================

' ========================================================================================
' Sets the maximum allowable width, in pixels, of the list box of a combo box with the
' CBS_DROPDOWN or CBS_DROPDOWNLIST style.
' ========================================================================================
FUNCTION ComboBox_SetDroppedWidth (BYVAL hComboBox AS DWORD, BYVAL nWidth AS LONG) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_SETDROPPEDWIDTH, nWidth, 0)
END FUNCTION
MACRO Combo_SetDroppedWidth = ComboBox_SetDroppedWidth
' ========================================================================================

' ========================================================================================
' Selects characters in the edit control of a combo box.
' ========================================================================================
FUNCTION ComboBox_SetEditSel (BYVAL hComboBox AS DWORD, BYVAL nStart AS INTEGER, BYVAL nEnd AS INTEGER) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_SETEDITSEL, 0, MAK(LONG, nStart, nEnd))
END FUNCTION
MACRO Combo_SetEditSel = ComboBox_SetEditSel
' ========================================================================================

' ========================================================================================
' Selects either the default user interface or the extended user interface for a combo box
' that has the CBS_DROPDOWN or CBS_DROPDOWNLIST style.
' ========================================================================================
FUNCTION ComboBox_SetExtendedUI (BYVAL hComboBox AS DWORD, BYVAL fBool AS LONG) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_SETEXTENDEDUI, fBool, 0)
END FUNCTION
MACRO Combo_SetExtendedUI = ComboBox_SetExtendedUI
' ========================================================================================

' ========================================================================================
' Sets the width, in pixels, by which a list box can be scrolled horizontally (the
' scrollable width). If the width of the list box is smaller than this value, the
' horizontal scroll bar horizontally scrolls items in the list box. If the width of the
' list box is equal to or greater than this value, the horizontal scroll bar is hidden or,
' if the combo box has the CBS_DISABLENOSCROLL style, disabled.
' ========================================================================================
SUB ComboBox_SetHorizontalExtent (BYVAL hComboBox AS DWORD, BYVAL nWidth AS LONG)
   SendMessage hComboBox, %CB_SETHORIZONTALEXTENT, nWidth, 0
END SUB
MACRO Combo_SetHorizontalExtent = ComboBox_SetHorizontalExtent
' ========================================================================================

' ========================================================================================
' Sets the value associated with the specified item in a combo box.
' ========================================================================================
FUNCTION ComboBox_SetItemData (BYVAL hComboBox AS DWORD, BYVAL index AS DWORD, BYVAL nData AS LONG) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_SETITEMDATA, index, nData)
END FUNCTION
MACRO Combo_SetItemData = ComboBox_SetItemData
' ========================================================================================

' ========================================================================================
' Sets the height of list items or the selection field in a combo box.
' ========================================================================================
FUNCTION ComboBox_SetItemHeight (BYVAL hComboBox AS DWORD, BYVAL index AS LONG, BYVAL nHeight AS LONG) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_SETITEMHEIGHT, index, nHeight)
END FUNCTION
MACRO Combo_SetItemHeight = ComboBox_SetItemHeight
' ========================================================================================

' ========================================================================================
' Sets the current locale of the combo box. If the combo box has the CBS_SORT style and
' strings are added using CB_ADDSTRING, the locale of a combo box affects how list items
' are sorted.
' ========================================================================================
FUNCTION ComboBox_SetLocale (BYVAL hComboBox AS DWORD, BYVAL lcid AS LONG) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_SETLOCALE, lcid, 0)
END FUNCTION
MACRO Combo_SetLocale = ComboBox_SetLocale
' ========================================================================================

' ========================================================================================
' Sets the minimum number of visible items in the drop-down list of a combo box.
' ========================================================================================
FUNCTION ComboBox_SetMinVisible (BYVAL hComboBox AS DWORD, BYVAL iMinVisible AS LONG) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_SETMINVISIBLE, iMinVisible, 0)
END FUNCTION
MACRO Combo_SetMinVisible = ComboBox_SetMinVisible
' ========================================================================================

' ========================================================================================
' Ensures that a particular item is visible in the list box of a combo box. The system
' scrolls the list box contents so that either the specified it.
' ========================================================================================
FUNCTION ComboBox_SetTopIndex (BYVAL hComboBox AS DWORD, BYVAL index AS DWORD) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_SETTOPINDEX, index, 0)
END FUNCTION
MACRO Combo_SetTopIndex = ComboBox_SetTopIndex
' ========================================================================================

' ========================================================================================
' Shows or hides the list box of a combo box that has the CBS_DROPDOWN or CBS_DROPDOWNLIST style.
' ========================================================================================
SUB ComboBox_ShowDropDown (BYVAL hComboBox AS DWORD, BYVAL nShow AS LONG)
   SendMessage hComboBox, %CB_SHOWDROPDOWN, ISTRUE(nShow) AND 1, 0
END SUB
MACRO Combo_ShowDropDown = ComboBox_ShowDropDown
' ========================================================================================

' ========================================================================================
' Calculates the size, in logical units, of the widest string item.
' ========================================================================================
FUNCTION ComboBox_CalcHorizontalExtent (BYVAL hComboBox AS DWORD) AS LONG

   LOCAL i             AS LONG
   LOCAL cItems        AS LONG
   LOCAL hDC           AS DWORD
   LOCAL iItem         AS LONG
   LOCAL tsize         AS SIZE
   LOCAL cxScrollWidth AS LONG
#IF %DEF(%UNICODE)
   LOCAL strText       AS WSTRING
#ELSE
   LOCAL strText       AS STRING
#ENDIF

   ' // Get an handle to the device context of the control
   hDC = GetDC(hComboBox)

   ' // Get the number of items
   cItems = ComboBox_GetCount(hComboBox)
   FOR i = 0 TO cItems - 1
      ' // Get the text of the item
      strText = ComboBox_GetLbText(hComboBox, i)
      ' // Computes the width and height of the text
      GetTextExtentPoint32 hDC, BYVAL STRPTR(strText), LEN(strText), tsize
      cxScrollWidth = MAX(cxScrollWidth, tsize.cx)
      INCR iItem
   NEXT

   ' // Release the device context
   ReleaseDC hComboBox, hDC
   ' // Return the width of the text
   FUNCTION = cxScrollWidth

END FUNCTION
' ========================================================================================

' ========================================================================================
' Adds item data to the combo box.
' ========================================================================================
FUNCTION ComboBox_AddItemData (BYVAL hComboBox AS DWORD, BYVAL pData AS DWORD) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_ADDSTRING, 0, pData)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Inserts item data to a combo box.
' ========================================================================================
FUNCTION ComboBox_InsertItemData (BYVAL hComboBox AS DWORD, BYVAL index AS LONG, BYVAL pData AS DWORD) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_INSERTSTRING, index, pData)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Finds the first item in a combo box that has the specified item data.
' ========================================================================================
FUNCTION ComboBox_FindItemData (BYVAL hComboBox AS DWORD, BYVAL indexStart AS LONG, BYVAL pData AS DWORD) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_FINDSTRING, indexStart, pData)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Searches a combo box for an item that has the specified item data. If a matching item is found, the item is selected.
' ========================================================================================
FUNCTION ComboBox_SelectItemData (BYVAL hComboBox AS DWORD, BYVAL indexStart AS LONG, BYVAL pData AS DWORD) AS LONG
   FUNCTION = SendMessage(hComboBox, %CB_SELECTSTRING, indexStart, pData)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the text from a combo box control.
' ========================================================================================
MACRO ComboBox_GetText(hwndCtl, lpch, cchMax) = GetWindowText(hwndCtl, lpch, cchMax)
' ========================================================================================

' ========================================================================================
' Gets the number of characters in the text of a combo box.
' ========================================================================================
MACRO ComboBox_GetTextLength(hwndCtl) = GetWindowTextLength(hwndCtl)
' ========================================================================================

' ========================================================================================
' Sets the text of a combo box.
' ========================================================================================
MACRO ComboBox_SetText(hwndCtl, lpsz) = SetWindowText(hwndCtl, lpsz)
' ========================================================================================
