' ########################################################################################
' Microsoft Windows
' File: ListBoxCtrl.inc
' Contents: ListBox Control Wrapper Functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LISTBOXCTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"

' ========================================================================================
' Enables or disables a listbox.
' ========================================================================================
FUNCTION ListBox_Enable (BYVAL hListBox AS DWORD, BYVAL fEnable AS LONG) AS LONG
   FUNCTION = EnableWindow(hListBox, fEnable)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Adds the specified filename to a list box that contains a directory listing.
' ========================================================================================
FUNCTION ListBox_AddFileA (BYVAL hListBox AS DWORD, BYVAL strFileName AS STRING) AS LONG
   FUNCTION = SendMessageA(hListBox, %LB_ADDFILE, 0, STRPTR(strFileName))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ListBox_AddFileW (BYVAL hListBox AS DWORD, BYVAL bstrFileName AS WSTRING) AS LONG
   FUNCTION = SendMessageW(hListBox, %LB_ADDFILE, 0, STRPTR(bstrFileName))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ListBox_AddFile = ListBox_AddFileW
#ELSE
   MACRO ListBox_AddFile = ListBox_AddFileA
#ENDIF

' ========================================================================================
' Adds a string to a list box. If the list box does not have the LBS_SORT style, the
' string is added to the end of the list. Otherwise, the string is inserted into the list
' and the list is sorted.
' ========================================================================================
FUNCTION ListBox_AddStringA (BYVAL hListBox AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hListBox, %LB_ADDSTRING, 0, STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ListBox_AddStringW (BYVAL hListBox AS DWORD, BYVAL bstrText AS WSTRING) AS LONG
   FUNCTION = SendMessageW(hListBox, %LB_ADDSTRING, 0, STRPTR(bstrText))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ListBox_AddString = ListBox_AddStringW
#ELSE
   MACRO ListBox_AddString = ListBox_AddStringA
#ENDIF

' ========================================================================================
' Deletes a string in a list box.
' ========================================================================================
FUNCTION ListBox_DeleteString (BYVAL hListBox AS DWORD, BYVAL Index AS LONG) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_DELETESTRING, Index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Adds names to the list displayed by a list box. The message adds the names of
' directories and files that match a specified string and set of file attributes.
' LB_DIR can also add mapped drive letters to the list box.
' ========================================================================================
FUNCTION ListBox_DirA (BYVAL hListBox AS DWORD, BYVAL Attr AS DWORD, BYVAL strFileSpec AS STRING) AS LONG
   FUNCTION = SendMessageA(hListBox, %LB_DIR, Attr, STRPTR(strFileSpec))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ListBox_DirW (BYVAL hListBox AS DWORD, BYVAL Attr AS DWORD, BYVAL bstrFileSpec AS WSTRING) AS LONG
   FUNCTION = SendMessageW(hListBox, %LB_DIR, Attr, STRPTR(bstrFileSpec))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ListBox_Dir = ListBox_DirW
#ELSE
   MACRO ListBox_Dir = ListBox_DirA
#ENDIF

' ========================================================================================
' Finds the first string in a list box that begins with the specified string.
' ========================================================================================
FUNCTION ListBox_FindStringA (BYVAL hListBox AS DWORD, BYVAL indexStart AS LONG, BYVAL searchString AS STRING) AS LONG
   FUNCTION = SendMessageA(hListBox, %LB_FINDSTRING, indexStart, STRPTR(searchString))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ListBox_FindStringW (BYVAL hListBox AS DWORD, BYVAL indexStart AS LONG, BYVAL bsearchString AS WSTRING) AS LONG
   FUNCTION = SendMessageW(hListBox, %LB_FINDSTRING, indexStart, STRPTR(bsearchString))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ListBox_FindString = ListBox_FindStringW
#ELSE
   MACRO ListBox_FindString = ListBox_FindStringA
#ENDIF

' ========================================================================================
' Finds the first list box string that exactly matches the specified string, except that
' the search is not case sensitive.
' ========================================================================================
FUNCTION ListBox_FindStringExactA (BYVAL hListBox AS DWORD, BYVAL indexStart AS LONG, BYVAL searchString AS STRING) AS LONG
   FUNCTION = SendMessageA(hListBox, %LB_FINDSTRINGEXACT, indexStart, STRPTR(searchString))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ListBox_FindStringExactW (BYVAL hListBox AS DWORD, BYVAL indexStart AS LONG, BYVAL bsearchString AS WSTRING) AS LONG
   FUNCTION = SendMessageW(hListBox, %LB_FINDSTRINGEXACT, indexStart, STRPTR(bsearchString))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ListBox_FindStringExact = ListBox_FindStringExactW
#ELSE
   MACRO ListBox_FindStringExact = ListBox_FindStringExactA
#ENDIF

' ========================================================================================
' Gets the index of the anchor item--that is, the item from which a multiple selection
' starts. A multiple selection spans all items from the anchor item to the caret item.
' ========================================================================================
FUNCTION ListBox_GetAnchorIndex (BYVAL hListBox AS DWORD) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_GETANCHORINDEX, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines the index of the item that has the focus rectangle in a multiple-selection
' list box. The item may or may not be selected.
' ========================================================================================
FUNCTION ListBox_GetCaretIndex (BYVAL hListBox AS DWORD) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_GETCARETINDEX, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the number of items in a list box.
' ========================================================================================
FUNCTION ListBox_GetCount (BYVAL hListBox AS DWORD) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_GETCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the index of the currently selected item, if any, in a list box.
' ========================================================================================
FUNCTION ListBox_GetCurSel (BYVAL hListBox AS DWORD) AS LONG
   FUNCTION = SendMessage(hListBox, IIF&((GetWindowLong(hListBox, %GWL_STYLE) AND %LBS_MULTIPLESEL), %LB_GETCARETINDEX, %LB_GETCURSEL), 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the width, in pixels, that a list box can be scrolled horizontally (the scrollable
' width) if the list box has a horizontal scroll bar.
' ========================================================================================
FUNCTION ListBox_GetHorizontalExtent (BYVAL hListBox AS DWORD) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_GETHORIZONTALEXTENT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the number of items per column in a specified list box.
' ========================================================================================
FUNCTION Listbox_GetListboxInfo (BYVAL hListBox AS DWORD) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_GETLISTBOXINFO, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the application-defined value associated with the specified list box item.
' ========================================================================================
FUNCTION ListBox_GetItemData (BYVAL hListBox AS DWORD, BYVAL index AS LONG) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_GETITEMDATA, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the height of items in a list box.
' ========================================================================================
FUNCTION Listbox_GetItemHeight (BYVAL hListBox AS DWORD, BYVAL index AS LONG) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_GETITEMHEIGHT, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the dimensions of the rectangle that bounds a list box item as it is currently
' displayed in the list box.
' ========================================================================================
#IF %DEF(%USEPBDECL)
MACRO ListBox_GetItemRect(hwndCtl, index, lprc)=SendMessage(hwndCtl, %LB_GETITEMRECT, index, lprc)
#ELSE
FUNCTION Listbox_GetItemRect (BYVAL hListBox AS DWORD, BYVAL index AS LONG, BYREF lpRect AS RECT) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_GETITEMRECT, index, VARPTR(lpRect))
END FUNCTION
#ENDIF
' ========================================================================================

' ========================================================================================
' Gets the current locale of the list box. You can use the locale to determine the correct
' sorting order of displayed text (for list boxes with the LBS_SORT style) and of text
' added by the LB_ADDSTRING message.
' ========================================================================================
FUNCTION ListBox_GetLocale (BYVAL hListBox AS DWORD) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_GETLOCALE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the selection state of an item.
' ========================================================================================
FUNCTION ListBox_GetSel (BYVAL hListBox AS DWORD, BYVAL Index AS LONG) AS LONG
   FUNCTION = ISTRUE(SendMessage(hListBox, %LB_GETSEL, Index, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the total number of selected items in a multiple-selection list box.
' ========================================================================================
FUNCTION ListBox_GetSelCount (BYVAL hListBox AS DWORD) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_GETSELCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Fills a buffer with an array of integers that specify the item numbers of selected items
' in a multiple-selection list box.
' ========================================================================================
#IF %DEF(%USEPBDECL)
MACRO ListBox_GetSelItems(hwndCtl, cItems, lpItems)=SendMessage(hwndCtl, %LB_GETSELITEMS, cItems, lpItems)
#ELSE
FUNCTION ListBox_GetSelItems (BYVAL hListBox AS DWORD, BYVAL items AS DWORD, BYREF FirstItem AS LONG) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_GETSELITEMS, items, VARPTR(FirstItem))
END FUNCTION
#ENDIF
' ========================================================================================

' ========================================================================================
' Gets a string from a list box.
' ========================================================================================
FUNCTION ListBox_GetTextA (BYVAL hListBox AS LONG, BYVAL Index AS LONG) AS STRING
   LOCAL nLen AS LONG
   LOCAL buffer AS STRING
   IF Index < 0 THEN Index = ListBox_GetCurSel(hListBox)
   nLen = ListBox_GetTextLen(hListBox, Index)
   Buffer = SPACE$(nLen + 1)
   SendMessageA hListBox, %LB_GETTEXT, Index, STRPTR(Buffer)
   FUNCTION = LEFT$(Buffer, nLen)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ListBox_GetTextW (BYVAL hListBox AS LONG, BYVAL Index AS LONG) AS WSTRING
   LOCAL nLen AS LONG
   LOCAL buffer AS WSTRING
   IF Index < 0 THEN Index = ListBox_GetCurSel(hListBox)
   nLen = ListBox_GetTextLen(hListBox, Index)
   Buffer = SPACE$(nLen + 1)
   SendMessageW hListBox, %LB_GETTEXT, Index, STRPTR(Buffer)
   FUNCTION = LEFT$(Buffer, nLen)
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ListBox_GetText = ListBox_GetTextW
#ELSE
   MACRO ListBox_GetText = ListBox_GetTextA
#ENDIF

' ========================================================================================
' Gets the length of a string in a list box.
' ========================================================================================
FUNCTION Listbox_GetTextLen (BYVAL hListBox AS DWORD, BYVAL index AS LONG) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_GETTEXTLEN, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the index of the first visible item in a list box. Initially the item with index 0
' is at the top of the list box, but if the list box contents have been scrolled another
' item may be at the top.
' ========================================================================================
FUNCTION ListBox_GetTopIndex (BYVAL hListBox AS DWORD) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_GETTOPINDEX, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Allocates memory for storing list box items. This message is used before an application
' adds a large number of items to a list box.
' ========================================================================================
FUNCTION Listbox_InitStorage (BYVAL hListBox AS DWORD, BYVAL nItems AS DWORD, BYVAL nBytes AS DWORD) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_INITSTORAGE, nItems, nBytes)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Inserts a string into a list box. Unlike the LB_ADDSTRING message, the LB_INSERTSTRING
' message does not cause a list with the LBS_SORT style to be sorted.
' ========================================================================================
FUNCTION ListBox_InsertStringA (BYVAL hListBox AS DWORD, BYVAL Index AS LONG, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hListBox, %LB_INSERTSTRING, Index, STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ListBox_InsertStringW (BYVAL hListBox AS DWORD, BYVAL Index AS LONG, BYVAL bstrText AS WSTRING) AS LONG
   FUNCTION = SendMessageW(hListBox, %LB_INSERTSTRING, Index, STRPTR(bstrText))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ListBox_InsertString = ListBox_InsertStringW
#ELSE
   MACRO ListBox_InsertString = ListBox_InsertStringA
#ENDIF

' ========================================================================================
' Gets the zero-based index of the item nearest the specified point in a list box.
' ========================================================================================
FUNCTION Listbox_ItemFromPoint (BYVAL hListBox AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_ITEMFROMPOINT, 0, MAK(LONG, x, y))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes all items from a list box.
' ========================================================================================
SUB ListBox_ResetContent (BYVAL hListBox AS DWORD)
   SendMessage hListBox, %LB_RESETCONTENT, 0, 0
END SUB
' ========================================================================================

#IF %DEF(%USEPBDECL)
MACRO ListBox_SelectString(hwndCtl, indexStart, lpszFind)=SendMessage(hwndCtl, %LB_SELECTSTRING, indexStart, lpszFind)
#ELSE
' ========================================================================================
' Searches a list box for an item that begins with the characters in a specified string.
' If a matching item is found, the item is selected.
' ========================================================================================
FUNCTION ListBox_SelectStringA (BYVAL hListBox AS DWORD, BYVAL Start AS LONG, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hListBox, %LB_SELECTSTRING, Start, STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ListBox_SelectStringW (BYVAL hListBox AS DWORD, BYVAL Start AS LONG, BYVAL bstrText AS WSTRING) AS LONG
   FUNCTION = SendMessageW(hListBox, %LB_SELECTSTRING, Start, STRPTR(bstrText))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ListBox_SelectString = ListBox_SelectStringW
#ELSE
   MACRO ListBox_SelectString = ListBox_SelectStringA
#ENDIF
#ENDIF

' ========================================================================================
' Selects one or more consecutive items in a multiple-selection list box.
' ========================================================================================
FUNCTION Listbox_SelItemRange (BYVAL hListBox AS DWORD, BYVAL fSel AS LONG, BYVAL startIndex AS INTEGER, BYVAL endIndex AS INTEGER) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_SELITEMRANGE, fSel, MAK(LONG, startIndex, endIndex))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Selects one or more consecutive items in a multiple-selection list box.
' ========================================================================================
FUNCTION Listbox_SelItemRangeEx (BYVAL hListBox AS DWORD, BYVAL startIndex AS LONG, BYVAL endIndex AS LONG) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_SELITEMRANGEEX, startIndex, endIndex)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the anchor item--that is, the item from which a multiple selection starts.
' A multiple selection spans all items from the anchor item to the caret item.
' ========================================================================================
FUNCTION ListBox_SetAnchorIndex (BYVAL hListBox AS DWORD, BYVAL index AS LONG) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_SETANCHORINDEX, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the focus rectangle to the item at the specified index in a multiple-selection list
' box. If the item is not visible, it is scrolled into view.
' ========================================================================================
FUNCTION Listbox_SetCaretIndex (BYVAL hListBox AS DWORD, BYVAL index AS LONG) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_SETCARETINDEX, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the width, in pixels, of all columns in a multiple-column list box (created with
' the LBS_MULTICOLUMN style).
' ========================================================================================
FUNCTION Listbox_SetColumnWidth (BYVAL hListBox AS DWORD, BYVAL nWidth AS DWORD) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_SETCOLUMNWIDTH, nWidth, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the count of items in a list box created with the LBS_NODATA style and not created
' with the LBS_HASSTRINGS style.
' ========================================================================================
FUNCTION Listbox_SetCount (BYVAL hListBox AS DWORD, BYVAL nCount AS DWORD) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_SETCOUNT, nCount, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Selects a string and scroll it into view, if necessary. When the new string is selected,
' the list box removes the highlight from the previously selected string.
' ========================================================================================
FUNCTION ListBox_SetCurSel (BYVAL hListBox AS DWORD, BYVAL Index AS LONG) AS LONG
   FUNCTION = SendMessage(hListBox, IIF&((GetWindowLong(hListBox, %GWL_STYLE) AND %LBS_MULTIPLESEL), %LB_SETSEL, %LB_SETCURSEL), Index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' An application sends an LB_SETHORIZONTALEXTENT message to set the width, in pixels, by
' which a list box can be scrolled horizontally (the scrollable width). If the width of
' the list box is smaller than this value, the horizontal scroll bar horizontally scrolls
' items in the list box. If the width of the list box is equal to or greater than this
' value, the horizontal scroll bar is hidden.
' ========================================================================================
SUB ListBox_SetHorizontalExtent (BYVAL hListBox AS DWORD, BYVAL cxExtent AS LONG)
   SendMessage hListBox, %LB_SETHORIZONTALEXTENT, cxExtent, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets a value associated with the specified item in a list box.
' ========================================================================================
FUNCTION Listbox_SetItemData (BYVAL hListBox AS DWORD, BYVAL index AS LONG, BYVAL pData AS LONG) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_SETITEMDATA, index, pData)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the height, in pixels, of items in a list box. If the list box has the
' LBS_OWNERDRAWVARIABLE style, this message sets the height of the item specified by the
' nHeight parameter. Otherwise, this message sets the height of all items in the list box.
' ========================================================================================
FUNCTION Listbox_SetItemHeight (BYVAL hListBox AS DWORD, BYVAL nHeight AS DWORD) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_SETITEMHEIGHT, nHeight, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the current locale of the list box. You can use the locale to determine the correct
' sorting order of displayed text (for list boxes with the LBS_SORT style) and of text
' added by the LB_ADDSTRING message.
' ========================================================================================
FUNCTION ListBox_SetLocale (BYVAL hListBox AS DWORD, BYVAL wLocaleID AS DWORD) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_SETLOCALE, wLocaleID, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Selects a string in a multiple-selection list box.
' ========================================================================================
FUNCTION ListBox_SetSel (BYVAL hListBox AS DWORD, BYVAL fSelect AS LONG, BYVAL index AS LONG) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_SETSEL, fSelect, index)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the tab-stop positions in a list box.
' ========================================================================================
#IF %DEF(%USEPBDECL)
MACRO ListBox_SetTabStops(hwndCtl, cTabs, lpTabs)=SendMessage(hwndCtl, %LB_SETTABSTOPS, cTabs, lpTabs)
#ELSE
SUB ListBox_SetTabStops (BYVAL hListBox AS DWORD, cTabs AS LONG, BYREF lpTabs AS LONG)
   SendMessage hListBox, %LB_SETTABSTOPS, cTabs, VARPTR(lpTabs)
END SUB
#ENDIF
' ========================================================================================

' ========================================================================================
' Ensures that a particular item in a list box is visible.
' ========================================================================================
FUNCTION ListBox_SetTopIndex (BYVAL hListBox AS DWORD, BYVAL index AS LONG) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_SETTOPINDEX, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Replaces a string, and his associated data, into a list box.
' ========================================================================================
FUNCTION ListBox_ReplaceStringA (BYVAL hListBox AS DWORD, BYVAL index AS LONG, BYVAL strNewText AS STRING, BYVAL pNewData AS LONG) AS LONG
   LOCAL lResult AS LONG
   lResult = SendMessageA(hListBox, %LB_DELETESTRING, index, 0)
   IF lResult <> %LB_ERR THEN
      index = SendMessageA(hListBox, %LB_INSERTSTRING, index, STRPTR(strNewText))
      IF index => 0 THEN
         lResult = SendMessageA(hListBox, %LB_SETITEMDATA, index, pNewData)
         IF lResult <> %LB_ERR THEN
            lResult = Listbox_SetCurSel(hListBox, index)
         END IF
      END IF
   END IF
   FUNCTION = lResult
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ListBox_ReplaceStringW (BYVAL hListBox AS DWORD, BYVAL index AS LONG, BYVAL bstrNewText AS WSTRING, BYVAL pNewData AS LONG) AS LONG
   LOCAL lResult AS LONG
   lResult = SendMessageW(hListBox, %LB_DELETESTRING, index, 0)
   IF lResult <> %LB_ERR THEN
      index = SendMessageW(hListBox, %LB_INSERTSTRING, index, STRPTR(bstrNewText))
      IF index => 0 THEN
         lResult = SendMessageW(hListBox, %LB_SETITEMDATA, index, pNewData)
         IF lResult <> %LB_ERR THEN
            lResult = Listbox_SetCurSel(hListBox, index)
         END IF
      END IF
   END IF
   FUNCTION = lResult
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ListBox_ReplaceString = ListBox_ReplaceStringW
#ELSE
   MACRO ListBox_ReplaceString = ListBox_ReplaceStringA
#ENDIF

' ========================================================================================
' Calculates the size, in logical units, of the widest string item.
' ========================================================================================
FUNCTION ListBox_CalcHorizontalExtent (BYVAL hListBox AS DWORD) AS LONG

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

   ' // Get an handle to the device context of the list box
   hDC = GetDC(hListBox)

   ' // Get the number of items
   cItems = ListBox_GetCount(hListBox)
   FOR i = 0 TO cItems - 1
      ' // Get the text of the item
      strText = ListBox_GetText(hListBox, i)
      ' // Computes the width and height of the text
      GetTextExtentPoint32 hDC, BYVAL STRPTR(strText), LEN(strText), tsize
      cxScrollWidth = MAX(cxScrollWidth, tsize.cx)
      INCR iItem
   NEXT

   ' // Release the device context
   ReleaseDC hListBox, hDC
   ' // Return the width of the text
   FUNCTION = cxScrollWidth

END FUNCTION
' ========================================================================================

' ========================================================================================
' Adds item data to the list box.
' ========================================================================================
FUNCTION ListBox_AddItemData (BYVAL hListBox AS DWORD, BYVAL pData AS DWORD) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_ADDSTRING, 0, pData)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Inserts item data to a list box.
' ========================================================================================
FUNCTION ListBox_InsertItemData (BYVAL hListBox AS DWORD, BYVAL index AS LONG, BYVAL pData AS DWORD) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_INSERTSTRING, index, pData)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Finds the first item in a list box that has the specified item data.
' ========================================================================================
FUNCTION ListBox_FindItemData (BYVAL hListBox AS DWORD, BYVAL indexStart AS LONG, BYVAL pData AS DWORD) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_FINDSTRING, indexStart, pData)
END FUNCTION
' ========================================================================================
' ========================================================================================
' Searches a list box for an item that has the specified item data. If a matching item is found, the item is selected.
' ========================================================================================
FUNCTION ListBox_SelectItemData (BYVAL hListBox AS DWORD, BYVAL indexStart AS LONG, BYVAL pData AS DWORD) AS LONG
   FUNCTION = SendMessage(hListBox, %LB_SELECTSTRING, indexStart, pData)
END FUNCTION
' ========================================================================================
