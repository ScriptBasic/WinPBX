' ########################################################################################
' Microsoft Windows
' File: ListViewCtrl.inc
' Contents: ListView Control Wrapper Functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LISTVIEWCTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"

' ========================================================================================
' Calculates the approximate width and height required to display a given number of items.
' ========================================================================================
FUNCTION ListView_ApproximateViewRect (BYVAL hwndLV AS DWORD, BYVAL iWidth AS INTEGER, BYVAL iHeight AS INTEGER, BYVAL iCount AS LONG) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_APPROXIMATEVIEWRECT, iCount, MAK(LONG, iWidth, iHeight))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Arranges items in icon view.
' ========================================================================================
FUNCTION ListView_Arrange (BYVAL hwndLV AS DWORD, BYVAL code AS LONG) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_ARRANGE, code, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Cancels an item text editing operation.
' ========================================================================================
SUB ListView_CancelEditLabel (BYVAL hwndLV AS DWORD)
   SendMessage hwndLV, %LVM_CANCELEDITLABEL, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Creates a drag image list for the specified item.
' ========================================================================================
FUNCTION ListView_CreateDragImage (BYVAL hwndLV AS DWORD, BYVAL i AS LONG, BYREF lpptUpLeft AS POINT) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_CREATEDRAGIMAGE, i, VARPTR(lpptUpLeft))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ListView_CreateDragImageXY (BYVAL hwndLV AS DWORD, BYVAL i AS LONG, BYVAL x AS LONG, BYVAL y AS LONG) AS LONG
   LOCAL tUpLeft AS POINT
   tUpLeft.x = x
   tUpLeft.y = y
   FUNCTION = SendMessage(hwndLV, %LVM_CREATEDRAGIMAGE, i, VARPTR(tUpLeft))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes all items from a list-view control.
' ========================================================================================
FUNCTION ListView_DeleteAllItems (BYVAL hwndLV AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_DELETEALLITEMS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes a column from a list-view control.
' ========================================================================================
FUNCTION ListView_DeleteColumn (BYVAL hwndLV AS DWORD, BYVAL iCol AS LONG) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_DELETECOLUMN, iCol, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes an item from a list-view control.
' ========================================================================================
FUNCTION ListView_DeleteItem (BYVAL hwndLV AS DWORD, BYVAL i AS LONG) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_DELETEITEM, i, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Begins in-place editing of the specified list-view item's text. The message implicitly
' selects and focuses the specified item.
' ========================================================================================
FUNCTION ListView_EditLabel (BYVAL hwndLV AS DWORD, BYVAL i AS LONG) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_EDITLABEL, i, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Enables or disables whether the items in a list-view control display as a group.
' ========================================================================================
FUNCTION ListView_EnableGroupView (BYVAL hwndLV AS DWORD, BYVAL fEnable AS LONG) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_ENABLEGROUPVIEW, fEnable, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Ensures that a list-view item is either entirely or partially visible, scrolling the
' list-view control if necessary.
' ========================================================================================
FUNCTION ListView_EnsureVisible (BYVAL hwndLV AS DWORD, BYVAL i AS LONG, BYVAL fPartialOK AS INTEGER) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_ENSUREVISIBLE, i, MAK(LONG, fPartialOK, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Searches for a list-view item with the specified characteristics.
' ========================================================================================
FUNCTION ListView_FindItem (BYVAL hwndLV AS DWORD, BYVAL iStart AS LONG, plvfi AS LVFINDINFO) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_FINDITEM, iStart, VARPTR(plvfi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Searches for a list-view item with the specified text.
' ========================================================================================
FUNCTION ListView_FindStringA (BYVAL hwndLV AS DWORD, BYVAL strText AS STRING) AS LONG
   LOCAL lvf AS LVFINDINFOA
   lvf.flags = %LVFI_STRING
   lvf.psz = STRPTR(strText)
   FUNCTION = SendMessageA(hwndLV, %LVM_FINDITEMA, -1, VARPTR(lvf))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ListView_FindStringW (BYVAL hwndLV AS DWORD, BYVAL bstrText AS WSTRING) AS LONG
   LOCAL lvf AS LVFINDINFOW
   lvf.flags = %LVFI_STRING
   lvf.psz = STRPTR(bstrText)
   FUNCTION = SendMessageW(hwndLV, %LVM_FINDITEMW, -1, VARPTR(lvf))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ListView_FindString = ListView_FindStringW
#ELSE
   MACRO ListView_FindString = ListView_FindStringA
#ENDIF

' ========================================================================================
' Gets the background color of a list-view control.
' ========================================================================================
FUNCTION ListView_GetBkColor (BYVAL hwndLV AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_GETBKCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the background image in a list-view control.
' ========================================================================================
FUNCTION ListView_GetBkImage (BYVAL hwndLV AS DWORD, BYREF plvbki AS LVBKIMAGE) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETBKIMAGE, 0, VARPTR(plvbki))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the callback mask for a list-view control.
' ========================================================================================
FUNCTION ListView_GetCallbackMask (BYVAL hwndLV AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETCALLBACKMASK, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines if an item in a list-view control is selected. This should be used only for
' list-view controls that have the LVS_EX_CHECKBOXES style.
' ========================================================================================
FUNCTION ListView_GetCheckState (BYVAL hwndLV AS DWORD, BYVAL i AS LONG) AS DWORD
   LOCAL nCheck AS LONG
   nCheck = SendMessage(hwndLV, %LVM_GETITEMSTATE, i, %LVIS_STATEIMAGEMASK)
   FUNCTION = BIT(nCheck, 12) - 1
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the attributes of a list-view control's column.
' ========================================================================================
FUNCTION ListView_GetColumn (BYVAL hwndLV AS DWORD, BYVAL iCol AS LONG, BYREF pcol AS LVCOLUMN) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETCOLUMN, iCol, VARPTR(pcol))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the text of a list-view control's column.
' ========================================================================================
FUNCTION ListView_GetColumnTextA (BYVAL hwndLV AS DWORD, BYVAL iCol AS LONG, OPTIONAL BYVAL cchTextMax AS LONG) AS STRING
   LOCAL strText AS STRING
   IF cchTextMax < 1 THEN cchTextMax = %MAX_PATH + 1
   strText = SPACE$(cchTextMax + 1)
   LOCAL lvc AS LVCOLUMNA
   lvc.mask = %LVCF_TEXT
   lvc.cchTextMax = cchTextMax + 1
   lvc.pszText = STRPTR(strText)
   IF SendMessageA(hwndLV, %LVM_GETCOLUMNA, iCol, VARPTR(lvc)) THEN FUNCTION = strText
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ListView_GetColumnTextW (BYVAL hwndLV AS DWORD, BYVAL iCol AS LONG, OPTIONAL BYVAL cchTextMax AS LONG) AS WSTRING
   LOCAL bstrText AS WSTRING
   IF cchTextMax < 1 THEN cchTextMax = %MAX_PATH + 1
   bstrText = SPACE$(cchTextMax + 1)
   LOCAL lvc AS LVCOLUMNW
   lvc.mask = %LVCF_TEXT
   lvc.cchTextMax = cchTextMax + 1
   lvc.pszText = STRPTR(bstrText)
   IF SendMessageW(hwndLV, %LVM_GETCOLUMNW, iCol, VARPTR(lvc)) THEN FUNCTION = bstrText
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ListView_GetColumnText = ListView_GetColumnTextW
#ELSE
   MACRO ListView_GetColumnText = ListView_GetColumnTextA
#ENDIF

' ========================================================================================
' Gets the current left-to-right order of columns in a list-view control.
' ========================================================================================
#IF %DEF(%USEPBDECL)
FUNCTION ListView_GetColumnOrderArray (BYVAL hwnd AS DWORD, _
    BYVAL iCount AS LONG, BYVAL pii AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_GETCOLUMNORDERARRAY, iCount, pii)
END FUNCTION
#ELSE
FUNCTION ListView_GetColumnOrderArray (BYVAL hwndLV AS DWORD, BYVAL iCount AS LONG, BYREF lpiArray AS LONG) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETCOLUMNORDERARRAY, iCount, VARPTR(lpiArray))
END FUNCTION
#ENDIF
' ========================================================================================

' ========================================================================================
' Gets the width of a column in report or list view.
' ========================================================================================
FUNCTION ListView_GetColumnWidth (BYVAL hwndLV AS DWORD, iCol AS LONG) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETCOLUMNWIDTH, iCol, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Calculates the number of items that can fit vertically in the visible area of a
' list-view control when in list or report view.
' ========================================================================================
FUNCTION ListView_GetCountPerPage (BYVAL hwndLV AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETCOUNTPERPAGE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the handle to the edit control being used to edit a list-view item's text.
' ========================================================================================
FUNCTION ListView_GetEditControl (BYVAL hwndLV AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_GETEDITCONTROL, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the text meant for display when the list-view control appears empty.
' ========================================================================================
FUNCTION ListView_GetEmptyText (BYVAL hwndLV AS DWORD, BYREF pwszText AS WSTRINGZ, BYVAL cchText AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETEMPTYTEXT, cchText, VARPTR(pwszText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the extended styles that are currently in use for a given list-view control.
' ========================================================================================
FUNCTION ListView_GetExtendedListViewStyle (BYVAL hwndLV AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_GETEXTENDEDLISTVIEWSTYLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the group that has the focus.
' ========================================================================================
FUNCTION ListView_GetFocusedGroup (BYVAL hwndLV AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETFOCUSEDGROUP, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets information on the footer of a specified list-view control.
' ========================================================================================
FUNCTION ListView_GetFooterInfo (BYVAL hwndLV AS DWORD, BYREF plvfi AS LVFOOTERINFO) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETFOOTERINFO, 0, VARPTR(plvfi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets information on a footer item for a specified list-view control.
' ========================================================================================
FUNCTION ListView_GetFooterItem (BYVAL hwndLV AS DWORD, BYVAL iItem AS LONG, BYREF pfi AS LVFOOTERITEM) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETFOOTERITEM, iItem, VARPTR(pfi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets information on a footer item for a specified list-view control.
' ========================================================================================
FUNCTION ListView_GetFooterItemRect (BYVAL hwndLV AS DWORD, BYVAL iItem AS LONG, BYREF prc AS RECT) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETFOOTERITEMRECT, iItem, VARPTR(prc))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the coordinates of the footer for a specified list-view control.
' ========================================================================================
FUNCTION ListView_GetFooterRect (BYVAL hwndLV AS DWORD, BYREF prc AS RECT) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETFOOTERRECT, 0, VARPTR(prc))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the number of groups.
' ========================================================================================
FUNCTION ListView_GetGroupCount (BYVAL hwndLV AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETGROUPCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the group header image list that has been set for an existing list-view control.
' ========================================================================================
FUNCTION ListView_GetGroupHeaderImageList (BYVAL hwndLV AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_GETIMAGELIST, %LVSIL_GROUPHEADER, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets group information.
' ========================================================================================
FUNCTION ListView_GetGroupInfo (BYVAL hwndLV AS DWORD, BYVAL iGroupId AS LONG, BYREF pgrp AS LVGROUP) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETGROUPINFO, iGroupId, VARPTR(pgrp))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets information on a specified group.
' ========================================================================================
FUNCTION ListView_GetGroupInfoByIndex (BYVAL hwndLV AS DWORD, BYVAL iIndex AS LONG, BYREF pgrp AS LVGROUP) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETGROUPINFOBYINDEX, iIndex, VARPTR(pgrp))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets information about the display of groups.
' ========================================================================================
SUB ListView_GetGroupMetrics (BYVAL hwndLV AS DWORD, BYREF pGroupMetrics AS LVGROUPMETRICS)
   SendMessage hwndLV, %LVM_GETGROUPMETRICS, 0, VARPTR(pGroupMetrics)
END SUB
' ========================================================================================

' ========================================================================================
' Gets the rectangle for a specified group.
' ========================================================================================
FUNCTION ListView_GetGroupRect (BYVAL hwndLV AS DWORD, BYVAL iGroupId AS LONG, BYVAL nType AS LONG, BYREF prc AS RECT) AS LONG
   prc.nTop = nType
   FUNCTION = SendMessage(hwndLV, %LVM_GETGROUPRECT, iGroupId, VARPTR(prc))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the state for a specified group.
' ========================================================================================
FUNCTION ListView_GetGroupState (BYVAL hwndLV AS DWORD, BYVAL dwGroupId AS DWORD, BYVAL dwMask AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_GETGROUPSTATE, dwGroupId, dwMask)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the handle to the header control used by a list-view control.
' ========================================================================================
FUNCTION ListView_GetHeader (BYVAL hwndLV AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_GETHEADER, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the HCURSOR used when the pointer is over an item while hot tracking is enabled.
' ========================================================================================
FUNCTION ListView_GetHotCursor (BYVAL hwndLV AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_GETHOTCURSOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the index of the hot item.
' ========================================================================================
FUNCTION ListView_GetHotItem (BYVAL hwndLV AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETHOTITEM, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the amount of time that the mouse cursor must hover over an item before it is selected.
' ========================================================================================
FUNCTION ListView_GetHoverTime (BYVAL hwndLV AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_GETHOVERTIME, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the handle to an image list used for drawing list-view items.
' ========================================================================================
FUNCTION ListView_GetImageList (BYVAL hwndLV AS DWORD, BYVAL nImageList AS LONG) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_GETIMAGELIST, nImageList, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the position of the insertion point.
' ========================================================================================
FUNCTION ListView_GetInsertMark (BYVAL hwndLV AS DWORD, plvim AS LVINSERTMARK) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETINSERTMARK, 0, VARPTR(plvim))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the color of the insertion point.
' ========================================================================================
FUNCTION ListView_GetInsertMarkColor (BYVAL hwndLV AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_GETINSERTMARKCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the rectangle that bounds the insertion point.
' ========================================================================================
FUNCTION ListView_GetInsertMarkRect (BYVAL hwndLV AS DWORD, BYREF prc AS RECT) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETINSERTMARKRECT, 0, VARPTR(prc))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the length of the incremental search string of a list-view control.
' ========================================================================================
FUNCTION ListView_GetISearchStringLenA (BYVAL hwndLV AS DWORD) AS LONG
   FUNCTION = SendMessageA(hwndLV, %LVM_GETISEARCHSTRINGA, 0, BYVAL %NULL)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ListView_GetISearchStringLenW (BYVAL hwndLV AS DWORD) AS LONG
   FUNCTION = SendMessageW(hwndLV, %LVM_GETISEARCHSTRINGW, 0, BYVAL %NULL)
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ListView_GetISearchStringLen = ListView_GetISearchStringLenW
#ELSE
   MACRO ListView_GetISearchStringLen = ListView_GetISearchStringLenA
#ENDIF

#IF %DEF(%USEPBDECL)
FUNCTION ListView_GetISearchString (BYVAL hWndLV AS DWORD, lpsz AS ASCIIZ) _
    AS LONG
    FUNCTION = SendMessage(hWndLV, %LVM_GETISEARCHSTRING, 0, VARPTR(lpsz))
END FUNCTION
#ELSE
' ========================================================================================
' Gets the incremental search string of a list-view control.
' ========================================================================================
FUNCTION ListView_GetISearchStringA (BYVAL hwndLV AS DWORD) AS STRING
   LOCAL nLen AS LONG
   LOCAL strSearch AS STRING
   nLen = SendMessageA(hwndLV, %LVM_GETISEARCHSTRINGA, 0, BYVAL %NULL)
   strSearch = SPACE$(nLen + 1)
   nLen = SendMessageA(hwndLV, %LVM_GETISEARCHSTRINGA, 0, BYVAL STRPTR(strSearch))
   FUNCTION = LEFT$(strSearch, nLen)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION ListView_GetISearchStringW (BYVAL hwndLV AS DWORD) AS WSTRING
   LOCAL nLen AS LONG
   LOCAL bstrSearch AS WSTRING
   nLen = SendMessageW(hwndLV, %LVM_GETISEARCHSTRINGW, 0, BYVAL %NULL)
   bstrSearch = SPACE$(nLen + 1)
   nLen = SendMessageW(hwndLV, %LVM_GETISEARCHSTRINGW, 0, BYVAL STRPTR(bstrSearch))
   FUNCTION = LEFT$(bstrSearch, nLen)
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ListView_GetISearchString = ListView_GetISearchStringW
#ELSE
   MACRO ListView_GetISearchString = ListView_GetISearchStringA
#ENDIF
#ENDIF

' ========================================================================================
' Gets some or all of a list-view item's attributes.
' ========================================================================================
FUNCTION ListView_GetItem (BYVAL hwndLV AS DWORD, BYREF pitem AS LVITEM) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETITEM, 0, VARPTR(pitem))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the number of items in a list-view control.
' ========================================================================================
FUNCTION ListView_GetItemCount (BYVAL hwndLV AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETITEMCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the bounding rectangle for all or part of a subitem in the current view of a
' specified list-view control.
' ========================================================================================
FUNCTION ListView_GetItemIndexRect (BYVAL hwndLV AS DWORD, BYREF plvii AS LVITEMINDEX, BYVAL iSubItem AS LONG, BYVAL nCode AS LONG, BYREF prc AS RECT) AS LONG
   prc.nTop = iSubItem : prc.nLeft = nCode
   FUNCTION = SendMessage(hwndLV, %LVM_GETITEMINDEXRECT, VARPTR(plvii), VARPTR(prc))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the position of a list-view item.
' ========================================================================================
FUNCTION ListView_GetItemPosition (BYVAL hwndLV AS DWORD, BYVAL i AS LONG, BYREF ppt AS POINT) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETITEMPOSITION, i, VARPTR(ppt))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the bounding rectangle for all or part of an item in the current view.
' ========================================================================================
FUNCTION ListView_GetItemRect (BYVAL hwndLV AS DWORD, BYVAL i AS LONG, BYREF prc AS RECT, BYVAL code AS LONG) AS LONG
   prc.nLeft = code
   FUNCTION = SendMessage(hwndLV, %LVM_GETITEMRECT, i, VARPTR(prc))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines the spacing between items in a list-view control.
' ========================================================================================
FUNCTION ListView_GetItemSpacing (BYVAL hwndLV AS DWORD, BYVAL fSmall AS LONG) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_GETITEMSPACING, fSmall, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the state of a list-view item.
' ========================================================================================
FUNCTION ListView_GetItemState (BYVAL hwndLV AS DWORD, BYVAL i AS LONG, BYVAL mask AS LONG) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_GETITEMSTATE, i, mask)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the text of a list-view item or subitem.
' ========================================================================================
SUB ListView_GetItemTextA (BYVAL hwndLV AS DWORD, BYVAL i AS LONG, BYVAL iSubItem AS LONG, BYREF pszText AS ASCIIZ, BYVAL cchTextMax AS LONG)
   LOCAL lvi AS LVITEMA
   lvi.iSubItem = iSubItem
   lvi.cchTextMax = cchTextMax
   lvi.pszText = VARPTR(pszText)
   SendMessageA hwndLV, %LVM_GETITEMTEXTA, i, VARPTR(lvi)
END SUB
' ========================================================================================
' ========================================================================================
SUB ListView_GetItemTextW (BYVAL hwndLV AS DWORD, BYVAL i AS LONG, BYVAL iSubItem AS LONG, BYREF pwszText AS WSTRINGZ, BYVAL cchTextMax AS LONG)
   LOCAL lvi AS LVITEMW
   lvi.iSubItem = iSubItem
   lvi.cchTextMax = cchTextMax
   lvi.pszText = VARPTR(pwszText)
   SendMessageW hwndLV, %LVM_GETITEMTEXTW, i, VARPTR(lvi)
END SUB
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ListView_GetItemText = ListView_GetItemTextW
#ELSE
   MACRO ListView_GetItemText = ListView_GetItemTextA
#ENDIF

' ========================================================================================
FUNCTION ListView_GetTextA (BYVAL hwndLV AS DWORD, BYVAL i AS LONG, BYVAL iSubItem AS LONG, OPTIONAL BYVAL cchTextMax AS LONG) AS STRING
   LOCAL strText AS STRING
   LOCAL lvi AS LVITEMA
   LOCAL nLen AS LONG
   IF cchTextMax < 1 THEN cchTextMax = %MAX_PATH + 1
   strText = SPACE$(cchTextMax + 1)
   lvi.iSubItem = iSubItem
   lvi.cchTextMax = cchTextMax + 1
   lvi.pszText = STRPTR(strText)
   nLen = SendMessageA(hwndLV, %LVM_GETITEMTEXTA, i, VARPTR(lvi))
   FUNCTION = LEFT$(strText, nLen)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ListView_GetTextW (BYVAL hwndLV AS DWORD, BYVAL i AS LONG, BYVAL iSubItem AS LONG, OPTIONAL BYVAL cchTextMax AS LONG) AS WSTRING
   LOCAL bstrText AS WSTRING
   LOCAL lvi AS LVITEMW
   LOCAL nLen AS LONG
   IF cchTextMax < 1 THEN cchTextMax = %MAX_PATH + 1
   bstrText = SPACE$(cchTextMax + 1)
   lvi.iSubItem = iSubItem
   lvi.cchTextMax = cchTextMax + 1
   lvi.pszText = STRPTR(bstrText)
   nLen = SendMessageW(hwndLV, %LVM_GETITEMTEXTW, i, VARPTR(lvi))
   FUNCTION = LEFT$(bstrText, nLen)
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ListView_GetText = ListView_GetTextW
#ELSE
   MACRO ListView_GetText = ListView_GetTextA
#ENDIF

' ========================================================================================
' Searches for a list-view item that has the specified properties and bears the specified
' relationship to a specified item.
' ========================================================================================
FUNCTION ListView_GetNextItem (BYVAL hwndLV AS DWORD, BYVAL iStart AS LONG, BYVAL flags AS LONG) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETNEXTITEM, iStart, MAK(LONG, flags, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the item that has the focus, which may or may not be selected.
' ========================================================================================
FUNCTION ListView_GetFocusedItem (BYVAL hwndLV AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETNEXTITEM, -1, %LVNI_ALL OR %LVNI_FOCUSED)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the index of the item in a particular list-view control that has the specified
' properties and relationship to another specific item.
' ========================================================================================
FUNCTION ListView_GetNextItemIndex (BYVAL hwndLV AS DWORD, BYREF plvii AS LVITEMINDEX, BYVAL flags AS LONG) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETNEXTITEMINDEX, VARPTR(plvii), MAK(LONG, flags, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the number of working areas in a list-view control.
' ========================================================================================
FUNCTION ListView_GetNumberOfWorkAreas (BYVAL hwndLV AS DWORD, BYREF pnWorkAreas AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETNUMBEROFWORKAREAS, 0, VARPTR(pnWorkAreas))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current view origin for a list-view control.
' ========================================================================================
FUNCTION ListView_GetOrigin (BYVAL hwndLV AS DWORD, BYREF lpptOrg AS POINT) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETORIGIN, 0, VARPTR(lpptOrg))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the color of the border of a list-view control if the LVS_EX_BORDERSELECT extended
' window style is set.
' ========================================================================================
FUNCTION ListView_GetOutlineColor (BYVAL hwndLV AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_GETOUTLINECOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets an integer that specifies the selected column.
' ========================================================================================
FUNCTION ListView_GetSelectedColumn (BYVAL hwndLV AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_GETSELECTEDCOLUMN, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines the number of selected items in a list-view control.
' ========================================================================================
FUNCTION ListView_GetSelectedCount (BYVAL hwndLV AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_GETSELECTEDCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the selection mark from a list-view control.
' ========================================================================================
FUNCTION ListView_GetSelectionMark (BYVAL hwndLV AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETSELECTIONMARK, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines the width of a specified string using the specified list-view control's
' current font.
' ========================================================================================
#IF %DEF(%USEPBDECL)
FUNCTION ListView_GetStringWidthA (BYVAL hWndLV AS DWORD, psz AS ASCIIZ) AS LONG
    FUNCTION = SendMessage(hWndLV, %LVM_GETSTRINGWIDTHA, 0, VARPTR(psz))
END FUNCTION
#ELSE
FUNCTION ListView_GetStringWidthA (BYVAL hwndLV AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hwndLV, %LVM_GETSTRINGWIDTHA, 0, STRPTR(strText))
END FUNCTION
#ENDIF
' ========================================================================================
' ========================================================================================
#IF %DEF(%USEPBDECL)
FUNCTION ListView_GetStringWidthW (BYVAL hWndLV AS DWORD, psz AS WSTRINGZ) AS LONG
    FUNCTION = SendMessage(hWndLV, %LVM_GETSTRINGWIDTHA, 0, VARPTR(psz))
END FUNCTION
#ELSE
FUNCTION ListView_GetStringWidthW (BYVAL hwndLV AS DWORD, BYVAL bstrText AS WSTRING) AS LONG
   FUNCTION = SendMessageW(hwndLV, %LVM_GETSTRINGWIDTHW, 0, STRPTR(bstrText))
END FUNCTION
#ENDIF
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ListView_GetStringWidth = ListView_GetStringWidthW
#ELSE
   MACRO ListView_GetStringWidth = ListView_GetStringWidthA
#ENDIF

' ========================================================================================
' Gets information about the rectangle that surrounds a subitem in a list-view control.
' This function is intended to be used only on list-view controls that use the LVS_REPORT style.
' ========================================================================================
#IF %DEF(%USEPBDECL)
FUNCTION ListView_GetSubItemRect (BYVAL hwnd AS DWORD, BYVAL iItem AS LONG, _
    BYVAL iSubItem AS LONG, BYVAL nCode AS LONG, BYVAL prc AS RECT PTR) AS LONG
    IF prc THEN
        @prc.nTop = iSubItem
        @prc.nLeft = nCode
    END IF
    FUNCTION = SendMessage(hwnd, %LVM_GETSUBITEMRECT, iItem, prc)
END FUNCTION
#ELSE
FUNCTION ListView_GetSubItemRect (BYVAL hwndLV AS DWORD, BYVAL iItem AS LONG, BYVAL iSubItem AS LONG, BYVAL nCode AS LONG, BYREF prc AS RECT) AS LONG
   IF VARPTR(prc) THEN
      prc.nTop = iSubItem
      prc.nLeft = nCode
   END IF
   FUNCTION = SendMessage(hwndLV, %LVM_GETSUBITEMRECT, iItem, VARPTR(prc))
END FUNCTION
#ENDIF
' ========================================================================================

' ========================================================================================
' Gets the text background color of a list-view control.
' ========================================================================================
FUNCTION ListView_GetTextBkColor (BYVAL hwndLV AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_GETTEXTBKCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the text color of a list-view control.
' ========================================================================================
FUNCTION ListView_GetTextColor (BYVAL hwndLV AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_GETTEXTCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets information about a tile in a list-view control.
' ========================================================================================
SUB ListView_GetTileInfo (BYVAL hwndLV AS DWORD, BYREF pti AS LVTILEINFO)
   SendMessage hwndLV, %LVM_GETTILEINFO, 0, VARPTR(pti)
END SUB
' ========================================================================================

' ========================================================================================
' Gets information about a list-view control in tile view.
' ========================================================================================
SUB ListView_GetTileViewInfo (BYVAL hwndLV AS DWORD, BYREF ptvi AS LVTILEVIEWINFO)
   SendMessage hwndLV, %LVM_GETTILEVIEWINFO, 0, VARPTR(ptvi)
END SUB
' ========================================================================================

' ========================================================================================
' Gets the ToolTip control that the list-view control uses to display ToolTips.
' ========================================================================================
FUNCTION ListView_GetToolTips (BYVAL hwndLV AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_GETTOOLTIPS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the index of the topmost visible item when in list or report view.
' ========================================================================================
FUNCTION ListView_GetTopIndex (BYVAL hwndLV AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETTOPINDEX, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the Unicode character format flag for the control.
' ========================================================================================
FUNCTION ListView_GetUnicodeFormat (BYVAL hwndLV AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETUNICODEFORMAT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current view of a list-view control.
' ========================================================================================
FUNCTION ListView_GetView (BYVAL hwndLV AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_GETVIEW, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the bounding rectangle of all items in the list-view control.
' ========================================================================================
FUNCTION ListView_GetViewRect (BYVAL hwndLV AS DWORD, BYREF prc AS RECT) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETVIEWRECT, 0, VARPTR(prc))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the working areas from a list-view control.
' ========================================================================================
SUB ListView_GetWorkAreas (BYVAL hwndLV AS DWORD, BYVAL nWorkAreas AS LONG, BYREF lprc AS RECT)
   SendMessage hwndLV, %LVM_GETWORKAREAS, nWorkAreas, VARPTR(lprc)
END SUB
' ========================================================================================

' ========================================================================================
' Determines whether the list-view control has a specified group.
' ========================================================================================
FUNCTION ListView_HasGroup (BYVAL hwndLV AS DWORD, BYVAL iGroupId AS LONG) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_HASGROUP, iGroupId, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines which list-view item, if any, is at a specified position.
' ========================================================================================
FUNCTION ListView_HitTest (BYVAL hwndLV AS DWORD, BYREF pinfo AS LVHITTESTINFO) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_HITTEST, 0, VARPTR(pinfo))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines which list-view item, if any, is at a specified position.
' ========================================================================================
FUNCTION ListView_HitTestEx (BYVAL hwndLV AS DWORD, BYREF pinfo AS LVHITTESTINFO) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_HITTEST, -1, VARPTR(pinfo))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Inserts a new column in a list-view control.
' ========================================================================================
FUNCTION ListView_InsertColumn (BYVAL hwndLV AS DWORD, BYVAL iCol AS LONG, pcol AS LVCOLUMN) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_INSERTCOLUMN, iCol, VARPTR(pcol))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Inserts a new column in a list-view control.
' ========================================================================================
FUNCTION ListView_AddColumnA (BYVAL hwndLV AS DWORD, BYVAL iCol AS LONG, BYVAL strText AS STRING, BYVAL nWidth AS LONG, OPTIONAL BYVAL nFormat AS LONG) AS LONG
   LOCAL lvc AS LVCOLUMNA
   lvc.mask = %LVCF_FMT OR %LVCF_WIDTH OR %LVCF_TEXT OR %LVCF_SUBITEM
   lvc.fmt = nFormat
   lvc.pszText = STRPTR(strText)
   lvc.cx = nWidth
   lvc.iSubItem = iCol
   FUNCTION = SendMessageA(hwndLV, %LVM_INSERTCOLUMNA, iCol, VARPTR(lvc))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ListView_AddColumnW (BYVAL hwndLV AS DWORD, BYVAL iCol AS LONG, BYVAL bstrText AS WSTRING, BYVAL nWidth AS LONG, OPTIONAL BYVAL nFormat AS LONG) AS LONG
   LOCAL lvc AS LVCOLUMNW
   lvc.mask = %LVCF_FMT OR %LVCF_WIDTH OR %LVCF_TEXT OR %LVCF_SUBITEM
   lvc.fmt = nFormat
   lvc.pszText = STRPTR(bstrText)
   lvc.cx = nWidth
   lvc.iSubItem = iCol
   FUNCTION = SendMessageW(hwndLV, %LVM_INSERTCOLUMNW, iCol, VARPTR(lvc))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ListView_AddColumn = ListView_AddColumnW
#ELSE
   MACRO ListView_AddColumn = ListView_AddColumnA
#ENDIF

' ========================================================================================
' Inserts a group into a list-view control.
' ========================================================================================
FUNCTION ListView_InsertGroup (BYVAL hwndLV AS DWORD, BYVAL index AS LONG, BYREF pgrp AS LVGROUP) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_INSERTGROUP, index, VARPTR(pgrp))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Inserts a group into an ordered list of groups.
' ========================================================================================
SUB ListView_InsertGroupSorted (BYVAL hwndLV AS DWORD, BYREF structInsert AS LVINSERTGROUPSORTED)
   SendMessage hwndLV, %LVM_INSERTGROUPSORTED, VARPTR(structInsert), 0
END SUB
' ========================================================================================

' ========================================================================================
' Inserts a new item in a list-view control.
' ========================================================================================
FUNCTION ListView_InsertItem (BYVAL hwndLV AS DWORD, BYREF pitem AS LVITEM) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_INSERTITEM, 0, VARPTR(pitem))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Inserts a new item in a list-view control.
' ========================================================================================
FUNCTION ListView_AddItemA (BYVAL hwndLV AS DWORD, BYVAL iItem AS LONG, BYVAL iImage AS LONG, BYVAL strText AS STRING) AS LONG
   LOCAL lvi AS LVITEMA
   lvi.mask = %LVIF_TEXT
   lvi.pszText = STRPTR(strText)
   lvi.iItem = iItem
   lvi.iImage = iImage
   FUNCTION = SendMessageA(hwndLV, %LVM_INSERTITEMA, iItem, VARPTR(lvi))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ListView_AddItemW (BYVAL hwndLV AS DWORD, BYVAL iItem AS LONG, BYVAL iImage AS LONG, BYVAL bstrText AS WSTRING) AS LONG
   LOCAL lvi AS LVITEMW
   lvi.mask = %LVIF_TEXT
   lvi.pszText = STRPTR(bstrText)
   lvi.iItem = iItem
   lvi.iImage = iImage
   FUNCTION = SendMessageW(hwndLV, %LVM_INSERTITEMW, iItem, VARPTR(lvi))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ListView_AddItem = ListView_AddItemW
#ELSE
   MACRO ListView_AddItem = ListView_AddItemA
#ENDIF

' ========================================================================================
' Appends a new item in a list-view control.
' ========================================================================================
FUNCTION ListView_AppendItemA (BYVAL hwndLV AS DWORD, BYVAL iImage AS LONG, BYVAL strText AS STRING) AS LONG
   LOCAL iItem AS LONG
   LOCAL lvi AS LVITEMA
   iItem = SendMessageA(hwndLV, %LVM_GETITEMCOUNT, 0, 0)
   lvi.mask = %LVIF_TEXT
   lvi.pszText = STRPTR(strText)
   lvi.iItem = iItem
   lvi.iImage = iImage
   FUNCTION = SendMessageA(hwndLV, %LVM_INSERTITEMA, iItem, VARPTR(lvi))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ListView_AppendItemW (BYVAL hwndLV AS DWORD, BYVAL iImage AS LONG, BYVAL bstrText AS WSTRING) AS LONG
   LOCAL iItem AS LONG
   LOCAL lvi AS LVITEMW
   iItem = SendMessageW(hwndLV, %LVM_GETITEMCOUNT, 0, 0)
   lvi.mask = %LVIF_TEXT
   lvi.pszText = STRPTR(bstrText)
   lvi.iItem = iItem
   lvi.iImage = iImage
   FUNCTION = SendMessageW(hwndLV, %LVM_INSERTITEMW, iItem, VARPTR(lvi))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ListView_AppendItem = ListView_AppendItemW
#ELSE
   MACRO ListView_AppendItem = ListView_AppendItemA
#ENDIF

' ========================================================================================
' Retrieves the insertion point closest to a specified point.
' ========================================================================================
FUNCTION ListView_InsertMarkHitTest (BYVAL hwndLV AS DWORD, BYREF ppoint AS POINT, BYREF lvim AS LVINSERTMARK) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_INSERTMARKHITTEST, VARPTR(ppoint), VARPTR(lvim))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Checks whether the list-view control has group view enabled.
' ========================================================================================
FUNCTION ListView_IsGroupViewEnabled (BYVAL hwndLV AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_ISGROUPVIEWENABLED, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Indicates whether an item in the list-view control is visible.
' ========================================================================================
FUNCTION ListView_IsItemVisible (BYVAL hwndLV AS DWORD, BYVAL index AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_ISITEMVISIBLE, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Maps the ID of an item to an index.
' ========================================================================================
FUNCTION ListView_MapIDToIndex (BYVAL hwndLV AS DWORD, BYVAL id AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_MAPIDTOINDEX, id, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Maps the index of an item to a unique ID.
' ========================================================================================
FUNCTION ListView_MapIndexToID (BYVAL hwndLV AS DWORD, BYVAL index AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_MAPINDEXTOID, index, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Not implemented.
' ========================================================================================
'FUNCTION ListView_MoveGroup (BYVAL hwnd AS DWORD, BYVAL iGroupId AS LONG, BYVAL toIndex AS LONG) AS LONG
'   FUNCTION = SendMessage(hwndLV, %LVM_MOVEGROUP, iGroupId, toIndex)
'END FUNCTION
' ========================================================================================

' ========================================================================================
' Not implemented.
' ========================================================================================
'FUNCTION ListView_MoveItemToGroup (BYVAL hwndLV AS DWORD, BYVAL idItemFrom AS LONG, BYVAL idGroupTo AS LONG) AS LONG
'   FUNCTION = SendMessage(hwndLV, %LVM_MOVEITEMTOGROUP, idItemFrom, idGroupTo)
'END FUNCTION
' ========================================================================================

' ========================================================================================
' Forces a list-view control to redraw a range of items.
' ========================================================================================
FUNCTION ListView_RedrawItems (BYVAL hwndLV AS DWORD, BYVAL iFirst AS LONG, BYVAL iLast AS LONG) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_REDRAWITEMS, iFirst, iLast)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes all groups from a list-view control.
' ========================================================================================
SUB ListView_RemoveAllGroups (BYVAL hwndLV AS DWORD)
   SendMessage hwndLV, %LVM_REMOVEALLGROUPS, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Removes a group from a list-view control.
' ========================================================================================
FUNCTION ListView_RemoveGroup (BYVAL hwndLV AS DWORD, BYVAL iGroupId AS LONG) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_REMOVEGROUP, iGroupId, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Scrolls the content of a list-view control.
' ========================================================================================
FUNCTION ListView_Scroll (BYVAL hwndLV AS DWORD, BYVAL dx AS LONG, BYVAL dy AS LONG) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SCROLL, dx, dy)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the background color of a list-view control.
' ========================================================================================
FUNCTION ListView_SetBkColor (BYVAL hwndLV AS DWORD, BYVAL clrBk AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SETBKCOLOR, 0, clrBk)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the background image in a list-view control.
' ========================================================================================
FUNCTION ListView_SetBkImage (BYVAL hwndLV AS DWORD, BYREF plvbki AS LVBKIMAGE) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SETBKIMAGE, 0, VARPTR(plvbki))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Changes the callback mask for a list-view control.
' ========================================================================================
FUNCTION ListView_SetCallbackMask (BYVAL hwndLV AS DWORD, BYVAL mask AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SETCALLBACKMASK, mask, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Selects or deselects an item in a list-view control.
' ========================================================================================
SUB ListView_SetCheckState (BYVAL hwndLV AS DWORD, BYVAL iIndex AS LONG, BYVAL fCheck AS LONG)
'   ListView_SetItemState hwndLV, iIndex, INDEXTOSTATEIMAGEMASK(1 - (ISTRUE fCheck)), %LVIS_STATEIMAGEMASK
   ListView_SetItemState hwndLV, iIndex, INDEXTOSTATEIMAGEMASK(IIF&(fCheck, 2, 1)), %LVIS_STATEIMAGEMASK
END SUB
' ========================================================================================

' ========================================================================================
' Sets the attributes of a list-view column.
' ========================================================================================
FUNCTION ListView_SetColumn (BYVAL hwndLV AS DWORD, BYVAL iCol AS LONG, BYREF pcol AS LVCOLUMN) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SETCOLUMN, iCol, VARPTR(pcol))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the left-to-right order of columns in a list-view control.
' ========================================================================================
#IF %DEF(%USEPBDECL)
FUNCTION ListView_SetColumnOrderArray (BYVAL hwnd AS DWORD, _
    BYVAL iCount AS LONG, BYVAL pii AS DWORD) AS LONG
    FUNCTION = SendMessage(hwnd, %LVM_SETCOLUMNORDERARRAY, iCount, pii)
END FUNCTION
#ELSE
FUNCTION ListView_SetColumnOrderArray (BYVAL hwndLV AS DWORD, BYVAL iCount AS LONG, BYREF lpiArray AS LONG) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SETCOLUMNORDERARRAY, iCount, VARPTR(lpiArray))
END FUNCTION
#ENDIF
' ========================================================================================

' ========================================================================================
' Used to change the width of a column in report view or the width of all columns in list-view mode.
' ========================================================================================
FUNCTION ListView_SetColumnWidth (BYVAL hwndLV AS DWORD, BYVAL iCol AS LONG, BYVAL cx AS INTEGER) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SETCOLUMNWIDTH, iCol, MAK(LONG, cx, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets extended styles for list-view controls
' ========================================================================================
SUB ListView_SetExtendedListViewStyle (BYVAL hwndLV AS DWORD, BYVAL dwExStyle AS DWORD)
   SendMessage hwndLV, %LVM_SETEXTENDEDLISTVIEWSTYLE, 0, dwExStyle
END SUB
' ========================================================================================

' ========================================================================================
' Sets extended styles for list-view controls using the style mask.
' ========================================================================================
SUB ListView_SetExtendedListViewStyleEx (BYVAL hwndLV AS DWORD, BYVAL dwExMask AS DWORD, BYVAL dwExStyle AS DWORD)
   SendMessage hwndLV, %LVM_SETEXTENDEDLISTVIEWSTYLE, dwExMask, dwExStyle
END SUB
' ========================================================================================

' ========================================================================================
' Assigns an image list to the group header of a list-view control.
' ========================================================================================
FUNCTION ListView_SetGroupHeaderImageList (BYVAL hwndLV AS DWORD, BYVAL himl AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_SETIMAGELIST, %LVSIL_GROUPHEADER, himl)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets group information.
' ========================================================================================
FUNCTION ListView_SetGroupInfo (BYVAL hwndLV AS DWORD, BYVAL iGroupId AS LONG, BYREF pgrp AS LVGROUP) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SETGROUPINFO, iGroupId, VARPTR(pgrp))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets information about the display of groups.
' ========================================================================================
SUB ListView_SetGroupMetrics (BYVAL hwndLV AS DWORD, BYREF pGroupMetrics AS LVGROUPMETRICS)
   SendMessage hwndLV, %LVM_SETGROUPMETRICS, 0, VARPTR(pGroupMetrics)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the state for a specified group.
' ========================================================================================
FUNCTION ListView_SetGroupState (BYVAL hwndLV AS DWORD, BYVAL dwGroupId AS DWORD, BYVAL dwMask AS DWORD, BYVAL dwState AS DWORD) AS LONG
   LOCAL lvg AS LVGROUP
   lvg.cbSize = SIZEOF(lvg)
   lvg.mask = %LVGF_STATE
   lvg.stateMask = dwMask
   lvg.state = dwState
   FUNCTION = SendMessage(hwndLV, %LVM_SETGROUPINFO, dwGroupId, VARPTR(lvg))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the HCURSOR that the list-view control uses when the pointer is over an item while
' hot tracking is enabled.
' ========================================================================================
FUNCTION ListView_SetHotCursor (BYVAL hwndLV AS DWORD, BYVAL hCursor AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_SETHOTCURSOR, 0, hCursor)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the hot item in a list-view control.
' ========================================================================================
FUNCTION ListView_SetHotItem (BYVAL hwndLV AS DWORD, BYVAL iIndex AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SETHOTITEM, iIndex, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the amount of time that the mouse cursor must hover over an item before it is selected.
' ========================================================================================
FUNCTION ListView_SetHoverTime (BYVAL hwndLV AS DWORD, BYVAL dwHoverTimeMs AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_SETHOVERTIME, 0, dwHoverTimeMs)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the spacing between icons in list-view controls set to the LVS_ICON style.
' ========================================================================================
FUNCTION ListView_SetIconSpacing (BYVAL hwndLV AS DWORD, BYVAL cx AS INTEGER, BYVAL cy AS INTEGER) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_SETICONSPACING, 0, MAK(LONG, cx, cy))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Assigns an image list to a list-view control.
' ========================================================================================
FUNCTION ListView_SetImageList (BYVAL hwndLV AS DWORD, BYVAL himl AS DWORD, BYVAL nImageList AS LONG) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_SETIMAGELIST, nImageList, himl)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets tooltip text.
' ========================================================================================
FUNCTION ListView_SetInfoTip (BYVAL hwndLV AS DWORD, BYREF plvInfoTip AS LVSETINFOTIP) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SETINFOTIP, 0, VARPTR(plvInfoTip))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the insertion point to the defined position.
' ========================================================================================
FUNCTION ListView_SetInsertMark (BYVAL hwndLV AS DWORD, BYREF plvim AS LVINSERTMARK) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SETINSERTMARK, 0, VARPTR(plvim))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the color of the insertion point.
' ========================================================================================
FUNCTION ListView_SetInsertMarkColor (BYVAL hwndLV AS DWORD, BYVAL colr AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_SETINSERTMARKCOLOR, 0, colr)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets some or all of a list-view item's attributes. You can also use ListView_SetItem to
' set the text of a subitem.
' ========================================================================================
FUNCTION ListView_SetItem (BYVAL hwndLV AS DWORD, BYREF pitem AS LVITEM) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SETITEM, 0, VARPTR(pitem))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Causes the list-view control to allocate memory for the specified number of items.
' ========================================================================================
SUB ListView_SetItemCount (BYVAL hwndLV AS DWORD, BYVAL cItems AS DWORD)
   SendMessage hwndLV, %LVM_SETITEMCOUNT, cItems, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the virtual number of items in a virtual list view.
' ========================================================================================
SUB ListView_SetItemCountEx (BYVAL hwndLV AS DWORD, BYVAL cItems AS DWORD, BYVAL dwFlags AS LONG)
   SendMessage hwndLV, %LVM_SETITEMCOUNT, cItems, dwFlags
END SUB
' ========================================================================================

' ========================================================================================
' Sets the state of a specified list-view item.
' ========================================================================================
FUNCTION ListView_SetItemIndexState (BYVAL hwndLV AS DWORD, BYREF plvii AS LVITEMINDEX, BYVAL dwData AS DWORD, BYVAL mask AS DWORD) AS LONG
   LOCAL lvi AS LVITEM
   lvi.stateMask = mask
   lvi.state = dwData
   FUNCTION = SendMessage(hwndLV, %LVM_SETITEMINDEXSTATE, VARPTR(plvii), VARPTR(lvi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Moves an item to a specified position in a list-view control (in icon or small icon view).
' ========================================================================================
FUNCTION ListView_SetItemPosition (BYVAL hwndLV AS DWORD, BYVAL i AS LONG, BYVAL x AS INTEGER, BYVAL y AS INTEGER) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SETITEMPOSITION, i, MAK(LONG, x, y))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Moves an item to a specified position in a list-view control (in icon or small icon view).
' This macro differs from the ListView_SetItemPosition macro in that it uses 32-bit coordinates.
' ========================================================================================
SUB ListView_SetItemPosition32 (BYVAL hwndLV AS DWORD, BYVAL i AS LONG, BYVAL x AS LONG, BYVAL y AS LONG)
   LOCAL ptNewPos AS POINT
   ptNewPos.x = x
   ptNewPos.y = y
   SendMessage  hwndLV, %LVM_SETITEMPOSITION32, i, VARPTR(ptNewPos)
END SUB
' ========================================================================================

' ========================================================================================
' Changes the state of an item in a list-view control.
' ========================================================================================
SUB ListView_SetItemState (BYVAL hwndLV AS DWORD, BYVAL i AS LONG, BYVAL dwState AS DWORD, BYVAL mask AS DWORD)
   LOCAL lvi AS LVITEM
   lvi.stateMask = mask
   lvi.state = dwState
   SendMessage hwndLV, %LVM_SETITEMSTATE, i, VARPTR(lvi)
END SUB
' ========================================================================================

#IF %DEF(%USEPBDECL)
SUB ListView_SetItemText(BYVAL hWndLV AS DWORD, BYVAL i AS LONG, _
    BYVAL iSubItem AS LONG, pszText AS ASCIIZ)
    LOCAL ms_lvi AS LV_ITEM
    ms_lvi.iSubItem = iSubItem
    ms_lvi.pszText = VARPTR(pszText)
    SendMessage hWndLV, %LVM_SETITEMTEXT, i, VARPTR(ms_lvi)
END SUB
#ELSE
' ========================================================================================
' Changes the text of a list-view item or subitem.
' ========================================================================================
SUB ListView_SetItemTextA (BYVAL hwndLV AS DWORD, BYVAL i AS LONG, BYVAL iSubItem AS LONG, BYVAL strText AS STRING)
   LOCAL lvi AS LVITEM
   lvi.iSubItem = iSubItem
   lvi.pszText = STRPTR(strText)
   SendMessage hwndLV, %LVM_SETITEMTEXT, i, VARPTR(lvi)
END SUB
' ========================================================================================
' ========================================================================================
SUB ListView_SetItemTextW (BYVAL hwndLV AS DWORD, BYVAL i AS LONG, BYVAL iSubItem AS LONG, BYVAL bstrText AS WSTRING)
   LOCAL lvi AS LVITEMW
   lvi.iSubItem = iSubItem
   lvi.pszText = STRPTR(bstrText)
   SendMessageW hwndLV, %LVM_SETITEMTEXTW, i, VARPTR(lvi)
END SUB
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ListView_SetItemText = ListView_SetItemTextW
#ELSE
   MACRO ListView_SetItemText = ListView_SetItemTextA
#ENDIF
#ENDIF

' ========================================================================================
SUB ListView_SetTextA (BYVAL hwndLV AS DWORD, BYVAL i AS LONG, BYVAL iSubItem AS LONG, BYVAL strText AS STRING)
   LOCAL lvi AS LVITEMA
   lvi.iSubItem = iSubItem
   lvi.pszText = STRPTR(strText)
   SendMessageA hwndLV, %LVM_SETITEMTEXTA, i, VARPTR(lvi)
END SUB
' ========================================================================================
' ========================================================================================
SUB ListView_SetTextW (BYVAL hwndLV AS DWORD, BYVAL i AS LONG, BYVAL iSubItem AS LONG, BYVAL bstrText AS WSTRING)
   LOCAL lvi AS LVITEMW
   lvi.iSubItem = iSubItem
   lvi.pszText = STRPTR(bstrText)
   SendMessageW hwndLV, %LVM_SETITEMTEXTW, i, VARPTR(lvi)
END SUB
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ListView_SetText = ListView_SetTextW
#ELSE
   MACRO ListView_SetText = ListView_SetTextA
#ENDIF

' ========================================================================================
' Sets the color of the border of a list-view control if the LVS_EX_BORDERSELECT extended
' window style is set.
' ========================================================================================
FUNCTION ListView_SetOutlineColor (BYVAL hwndLV AS DWORD, BYVAL colr AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_SETOUTLINECOLOR, 0, colr)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the index of the selected column.
' ========================================================================================
SUB ListView_SetSelectedColumn (BYVAL hwndLV AS DWORD, BYVAL iCol AS LONG)
   SendMessage hwndLV, %LVM_SETSELECTEDCOLUMN, iCol, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the selection mark in a list-view control.
' ========================================================================================
FUNCTION ListView_SetSelectionMark (BYVAL hwndLV AS DWORD, BYVAL iIndex AS LONG) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SETSELECTIONMARK, 0, iIndex)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the background color of text in a list-view control.
' ========================================================================================
FUNCTION ListView_SetTextBkColor (BYVAL hwndLV AS DWORD, BYVAL clrTextBk AS LONG) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SETTEXTBKCOLOR, 0, clrTextBk)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the text color of a list-view control.
' ========================================================================================
FUNCTION ListView_SetTextColor (BYVAL hwndLV AS DWORD, BYVAL clrText AS LONG) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SETTEXTCOLOR, 0, clrText)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets information for an existing tile of a list-view control.
' ========================================================================================
FUNCTION ListView_SetTileInfo (BYVAL hwndLV AS DWORD, BYREF plvtinfo AS LVTILEINFO) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SETTILEINFO, 0, VARPTR(plvtinfo))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets information that a list-view control uses in tile view.
' ========================================================================================
FUNCTION ListView_SetTileViewInfo (BYVAL hwndLV AS DWORD, BYREF plvtvinfo AS LVTILEVIEWINFO) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SETTILEVIEWINFO, 0, VARPTR(plvtvinfo))
END FUNCTION
' ========================================================================================

' ========================================================================================
' This message is supported only through Microsoft Windows XP.
' It is not defined in the Windows Vista SDK.
' ========================================================================================
FUNCTION ListView_SetTileWidth (BYVAL hwnd AS DWORD, BYVAL cpWidth AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %LVM_SETTILEWIDTH, cpWidth, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the ToolTip control that the list-view control will use to display ToolTips.
' ========================================================================================
FUNCTION ListView_SetToolTips (BYVAL hwndLV AS DWORD, BYVAL hwndToolTip AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndLV, %LVM_SETTOOLTIPS, hwndToolTip, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the Unicode character format flag for the control. This message allows you to
' change the character set used by the control at run time rather than having to re-create
' the control.
' ========================================================================================
FUNCTION ListView_SetUnicodeFormat (BYVAL hwndLV AS DWORD, BYVAL fUnicode AS LONG) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SETUNICODEFORMAT, fUnicode, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the view of a list-view control.
' ========================================================================================
FUNCTION ListView_SetView (BYVAL hwndLV AS DWORD, BYVAL iView AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SETVIEW, iView, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the working areas within a list-view control.
' ========================================================================================
SUB ListView_SetWorkAreas (BYVAL hwndLV AS DWORD, BYVAL nWorkAreas AS LONG, BYREF lprc AS RECT)
   SendMessage hwndLV, %LVM_SETWORKAREAS, nWorkAreas, VARPTR(lprc)
END SUB
' ========================================================================================

' ========================================================================================
' Uses an application-defined comparison function to sort groups by ID within a list-view control.
' ========================================================================================
FUNCTION ListView_SortGroups (BYVAL hwndLV AS DWORD, BYVAL pfnGroupCompare AS DWORD, BYVAL plv AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SORTGROUPS, pfnGroupCompare, plv)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Uses an application-defined comparison function to sort the items of a list-view control.
' The index of each item changes to reflect the new sequence.
' ========================================================================================
FUNCTION ListView_SortItems (BYVAL hwndLV AS DWORD, BYVAL pfnCompare AS DWORD, BYVAL lParamSort AS LONG) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SORTITEMS, lParamSort, pfnCompare)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Uses an application-defined comparison function to sort the items of a list-view control.
' The index of each item changes to reflect the new sequence.
' ========================================================================================
FUNCTION ListView_SortItemsEx (BYVAL hwndLV AS DWORD, BYVAL pfnCompare AS DWORD, BYVAL lParamSort AS LONG) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SORTITEMSEX, lParamSort, pfnCompare)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines which list-view item or subitem is located at a given position.
' ========================================================================================
FUNCTION ListView_SubItemHitTest (BYVAL hwndLV AS DWORD, BYREF plvhti AS LVHITTESTINFO) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SUBITEMHITTEST, 0, VARPTR(plvhti))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines which list-view item or subitem is located at a given position.
' ========================================================================================
FUNCTION ListView_SubItemHitTestEx (BYVAL hwndLV AS DWORD, BYREF plvhti AS LVHITTESTINFO) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SUBITEMHITTEST, -1, VARPTR(plvhti))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Updates a list-view item. If the list-view control has the LVS_AUTOARRANGE style, this
' macro causes the list-view control to be arranged.
' ========================================================================================
FUNCTION ListView_Update (BYVAL hwndLV AS DWORD, BYVAL iItem AS LONG) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_UPDATE, iItem, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the zero-based index of the currently selected item.
' See the following Microsoft article: How To Select a Listview Item Programmatically
' http://support.microsoft.com/kb/131284
' ========================================================================================
FUNCTION ListView_GetSelection (BYVAL hwndLV AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_GETNEXTITEM, -1, %LVNI_SELECTED)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Selects a ListView item.
' Windows does not provide a separate message or function to set the current selection in
' a listview. Instead, it defines item states or LVIS_* values that determine the listview
' item's appearance and functionality. LVIS_FOCUSED and LVIS_SELECTED in particular are
' the states that determine a listview item's selection state.
' Note that the last parameter passed to this macro is a mask specifying which bits are
' about to change. LVIS_FOCUSED and LVIS_SELECTED are defined in commctrl.inc as &H0001
' and &H0002 respectively, so you need to set the last four bits of the mask.
' See the following Microsoft article: How To Select a Listview Item Programmatically
' http://support.microsoft.com/kb/131284
' ========================================================================================
SUB ListView_SelectItem (BYVAL hwndLV AS DWORD, BYVAL iIndex AS LONG)
   ListView_SetItemState(hwndLV, iIndex, %LVIS_FOCUSED OR %LVIS_SELECTED, &H000F)
END SUB
' ========================================================================================

' ========================================================================================
' Selects all items.
' ========================================================================================
SUB ListView_SelectAllItems (BYVAL hwndLV AS DWORD)
   LOCAL lvi AS LVITEM
   lvi.mask = %LVIF_STATE
   lvi.state = -1
   lvi.stateMask = %LVIS_SELECTED
   SendMessage hwndLV, %LVM_SETITEMSTATE, -1, VARPTR(lvi)
END SUB
' ========================================================================================

' ========================================================================================
' Unselects an item in a ListView.
' ========================================================================================
SUB ListView_UnselectItem (BYVAL hwndLV AS DWORD, BYVAL iIndex AS LONG)
   ListView_SetItemState(hwndLV, iIndex, 0, %LVIS_SELECTED)
END SUB
' ========================================================================================

' ========================================================================================
' Unselects all items.
' ========================================================================================
SUB ListView_UnselectAllItems (BYVAL hwndLV AS DWORD)
   ListView_SetItemState(hwndLV, -1, 0, %LVIS_SELECTED OR %LVIS_FOCUSED)
END SUB
' ========================================================================================

' ========================================================================================
' Removes the HDS_BUTTONS style from the header control to give it a flat appearance.
' ========================================================================================
SUB ListView_MakeHeaderFlat (BYVAL hwndLV AS DWORD)
   LOCAL hLvHeader AS DWORD
   hLvHeader = SendMessage(hwndLV, %LVM_GETHEADER, 0, 0)
   IF hLvHeader = 0 THEN EXIT SUB
   SetWindowLong hLvHeader, %GWL_STYLE, GetWindowLong(hLvHeader, %GWL_STYLE) XOR %HDS_BUTTONS
   SetWindowPos GetParent(hwndLV), %NULL, 0, 0, 0, 0, %SWP_NOZORDER OR %SWP_NOMOVE OR %SWP_NOSIZE OR %SWP_DRAWFRAME
END SUB
' ========================================================================================

' ========================================================================================
' Automatically sizes the specified column.
' ========================================================================================
FUNCTION ListView_FitContent (BYVAL hwndLV AS DWORD, BYVAL iCol AS LONG) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SETCOLUMNWIDTH, iCol, %LVSCW_AUTOSIZE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Automatically sizes all the columns of a listview
' ========================================================================================
FUNCTION ListView_AutoSizeColumns (BYVAL hwndLV AS DWORD) AS LONG
   LOCAL i, nCount AS LONG, hLvHeader AS DWORD
   hLvHeader = SendMessage(hwndLV, %LVM_GETHEADER, 0, 0)
   IF hLvHeader = 0 THEN EXIT FUNCTION
   nCount = SendMessage(hLvHeader, %HDM_GETITEMCOUNT, 0, 0)
   FOR i = 0 TO nCount - 1
      FUNCTION = SendMessage(hwndLV, %LVM_SETCOLUMNWIDTH, i, %LVSCW_AUTOSIZE)
   NEXT
END FUNCTION
' ========================================================================================

' ========================================================================================
' Automatically sizes the column to fit the header text. If you use this value with the
' last column, its width is set to fill the remaining width of the list-view control.
' ========================================================================================
FUNCTION ListView_FitHeader (BYVAL hwndLV AS DWORD, BYVAL iCol AS LONG) AS LONG
   FUNCTION = SendMessage(hwndLV, %LVM_SETCOLUMNWIDTH, iCol, %LVSCW_AUTOSIZE_USEHEADER)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Automatically sizes all the columns of the header of a listview
' ========================================================================================
FUNCTION ListView_AutoSizeHeader (BYVAL hwndLV AS DWORD) AS LONG
   LOCAL i, nCount AS LONG, hLvHeader AS DWORD
   hLvHeader = SendMessage(hwndLV, %LVM_GETHEADER, 0, 0)
   IF hLvHeader = 0 THEN EXIT FUNCTION
   nCount = SendMessage(hLvHeader, %HDM_GETITEMCOUNT, 0, 0)
   FOR i = 0 TO nCount - 1
      FUNCTION = SendMessage(hwndLV, %LVM_SETCOLUMNWIDTH, i, %LVSCW_AUTOSIZE_USEHEADER)
   NEXT
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the number of columns of a listview.
' ========================================================================================
FUNCTION ListView_GetColumnCount (BYVAL hwndLV AS DWORD) AS LONG
   LOCAL hLvHeader AS DWORD
   hLvHeader = SendMessage(hwndLV, %LVM_GETHEADER, 0, 0)
   IF hLvHeader = 0 THEN EXIT FUNCTION
   FUNCTION = SendMessage(hLvHeader, %HDM_GETITEMCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the text of the specified column of the header of a listview control.
' ========================================================================================
FUNCTION ListView_GetHeaderTextA (BYVAL hwndLV AS DWORD, BYVAL iCol AS LONG, OPTIONAL BYVAL cchTextMax AS LONG) AS STRING
   LOCAL hLvHeader AS DWORD
   hLvHeader = SendMessageA(hwndLV, %LVM_GETHEADER, 0, 0)
   IF hLvHeader = 0 THEN EXIT FUNCTION
   LOCAL strText AS STRING
   IF cchTextMax < 1 THEN cchTextMax = %MAX_PATH + 1
   strText = SPACE$(cchTextMax + 1)
   LOCAL hdi AS HDITEMA
   hdi.mask = %HDI_TEXT
   hdi.cchTextMax = cchTextMax + 1
   hdi.pszText = STRPTR(strText)
   IF SendMessageA(hLvHeader, %HDM_GETITEMA, iCol, VARPTR(hdi)) THEN FUNCTION = strText
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ListView_GetHeaderTextW (BYVAL hwndLV AS DWORD, BYVAL iCol AS LONG, OPTIONAL BYVAL cchTextMax AS LONG) AS WSTRING
   LOCAL hLvHeader AS DWORD
   hLvHeader = SendMessageW(hwndLV, %LVM_GETHEADER, 0, 0)
   IF hLvHeader = 0 THEN EXIT FUNCTION
   LOCAL bstrText AS WSTRING
   IF cchTextMax < 1 THEN cchTextMax = %MAX_PATH + 1
   bstrText = SPACE$(cchTextMax + 1)
   LOCAL hdi AS HDITEMW
   hdi.mask = %HDI_TEXT
   hdi.cchTextMax = cchTextMax + 1
   hdi.pszText = STRPTR(bstrText)
   IF SendMessageW(hLvHeader, %HDM_GETITEMW, iCol, VARPTR(hdi)) THEN FUNCTION = bstrText
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ListView_GetHeaderText = ListView_GetHeaderTextW
#ELSE
   MACRO ListView_GetHeaderText = ListView_GetHeaderTextA
#ENDIF

' ========================================================================================
' Gets the order of the specified column of the listview's header control.
' ========================================================================================
FUNCTION ListView_GetColumnOrder (BYVAL hwndLV AS DWORD, BYVAL iCol AS LONG) AS LONG
   LOCAL hLvHeader AS DWORD
   hLvHeader = SendMessageW(hwndLV, %LVM_GETHEADER, 0, 0)
   IF hLvHeader = 0 THEN EXIT FUNCTION
   LOCAL hdi AS HDITEM
   hdi.mask = %HDI_ORDER
   IF SendMessage(hLvHeader, %HDM_GETITEM, iCol, VARPTR(hdi)) THEN FUNCTION = hdi.iOrder
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current left-to-right order of items in the header of a listview control.
' ========================================================================================
FUNCTION ListView_GetOrderArray (BYVAL hwndLV AS DWORD, BYVAL iSize AS DWORD, BYREF lpiArray AS LONG) AS LONG
   LOCAL hLvHeader AS DWORD
   hLvHeader = SendMessageW(hwndLV, %LVM_GETHEADER, 0, 0)
   IF hLvHeader = 0 THEN EXIT FUNCTION
   FUNCTION = SendMessage(hLvHeader, %HDM_GETORDERARRAY, iSize, VARPTR(lpiArray))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Changes the font used by the listview header.
' Examples of Use:
'   hFont = ListView_SetHeaderFontA(hListView, "MS Sans Serif", 8, %FW_NORMAL, %FALSE, %FALSE, %FALSE, %DEFAULT_CHARSET)
'   hFont = ListView_SetHeaderFontA(hListView, "Courier New", 10, %FW_BOLD, %FALSE, %FALSE, %FALSE, %DEFAULT_CHARSET)
'   hFont = ListView_SetHeaderFontA(hListView, "Marlett", 8, %FW_NORMAL, %FALSE, %FALSE, %FALSE, %SYMBOL_CHARSET)
' Note: The returned font must be destroyed with DeleteObject when no longer needed to prevent memory leaks.
' ========================================================================================
FUNCTION ListView_SetHeaderFontA ( _
   BYVAL hListView   AS DWORD, _     ' __in Handle to the listview
   BYVAL strFaceName AS STRING, _    ' __in Typeface name of font
   BYVAL lPointSize  AS LONG, _      ' __in Point size
   BYVAL lWeight AS LONG, _          ' __in Font weight(bold etc.)
   BYVAL bItalic     AS BYTE, _      ' __in TRUE = italic
   BYVAL bUnderline  AS BYTE, _      ' __in TRUE = underline
   BYVAL bStrikeOut  AS BYTE, _      ' __in TRUE = strikeout
   BYVAL bCharSet    AS BYTE _       ' __in character set
   ) AS DWORD                        ' Handle of font or NULL on failure.

   LOCAL hLvHeader AS DWORD
   LOCAL hLvHeaderFont AS DWORD
   LOCAL hCurFont AS DWORD
   LOCAL hOldFont AS DWORD
   LOCAL lf AS LOGFONTA
   LOCAL hDC AS DWORD

   ' // Get the handle of the header
   hLvHeader = SendMessageA(hListView, %LVM_GETHEADER, 0, 0)
   IF hLvHeader = 0 THEN EXIT FUNCTION

   ' // Create the font
   hDC = GetDC(%HWND_DESKTOP)
   lf.lfHeight         = -MulDiv(lPointSize, GetDeviceCaps(hDC, %LOGPIXELSY), 72) ' logical font height
   lf.lfWidth          =  0                                                       ' average character width
   lf.lfEscapement     =  0                                                       ' escapement
   lf.lfOrientation    =  0                                                       ' orientation angles
   lf.lfWeight         =  lWeight                                                 ' font weight
   lf.lfItalic         =  bItalic                                                 ' italic(TRUE/FALSE)
   lf.lfUnderline      =  bUnderline                                              ' underline(TRUE/FALSE)
   lf.lfStrikeOut      =  bStrikeOut                                              ' strikeout(TRUE/FALSE)
   lf.lfCharSet        =  bCharset                                                ' character set
   lf.lfOutPrecision   =  %OUT_TT_PRECIS                                          ' output precision
   lf.lfClipPrecision  =  %CLIP_DEFAULT_PRECIS                                    ' clipping precision
   lf.lfQuality        =  %DEFAULT_QUALITY                                        ' output quality
   lf.lfPitchAndFamily =  %FF_DONTCARE                                            ' pitch and family
   lf.lfFaceName       =  strFaceName                                             ' typeface name
   ReleaseDC %HWND_DESKTOP, hDC
   hLvHeaderFont = CreateFontIndirectA(lf)
   IF hLvHeaderFont = 0 THEN EXIT FUNCTION

   ' // Select the font
   hDC = GetDC(hLvHeader)
   hOldFont = SelectObject(hDC, hLvHeaderFont)
   ReleaseDC (hLvHeader, hDC)
   SendMessageA(hLvHeader, %WM_SETFONT, hLvHeaderFont, %TRUE)
   IF hOldFont THEN DeleteObject(hOldFont)
   FUNCTION = hLvHeaderFont

END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ListView_SetHeaderFontW ( _
   BYVAL hListView   AS DWORD, _     ' __in Handle to the listview
   BYVAL strFaceName AS WSTRING, _   ' __in Typeface name of font
   BYVAL lPointSize  AS LONG, _      ' __in Point size
   BYVAL lWeight AS LONG, _          ' __in Font weight(bold etc.)
   BYVAL bItalic     AS BYTE, _      ' __in TRUE = italic
   BYVAL bUnderline  AS BYTE, _      ' __in TRUE = underline
   BYVAL bStrikeOut  AS BYTE, _      ' __in TRUE = strikeout
   BYVAL bCharSet    AS BYTE _       ' __in character set
   ) AS DWORD                        ' Handle of font or NULL on failure.

   LOCAL hLvHeader AS DWORD
   LOCAL hLvHeaderFont AS DWORD
   LOCAL hOldFont AS DWORD
   LOCAL lf AS LOGFONTW
   LOCAL hDC AS DWORD

   ' // Get the handle of the header
   hLvHeader = SendMessageW(hListView, %LVM_GETHEADER, 0, 0)
   IF hLvHeader = 0 THEN EXIT FUNCTION

   ' // Create the font
   hDC = GetDC(%HWND_DESKTOP)
   lf.lfHeight         = -MulDiv(lPointSize, GetDeviceCaps(hDC, %LOGPIXELSY), 72) ' logical font height
   lf.lfWidth          =  0                                                       ' average character width
   lf.lfEscapement     =  0                                                       ' escapement
   lf.lfOrientation    =  0                                                       ' orientation angles
   lf.lfWeight         =  lWeight                                                 ' font weight
   lf.lfItalic         =  bItalic                                                 ' italic(TRUE/FALSE)
   lf.lfUnderline      =  bUnderline                                              ' underline(TRUE/FALSE)
   lf.lfStrikeOut      =  bStrikeOut                                              ' strikeout(TRUE/FALSE)
   lf.lfCharSet        =  bCharset                                                ' character set
   lf.lfOutPrecision   =  %OUT_TT_PRECIS                                          ' output precision
   lf.lfClipPrecision  =  %CLIP_DEFAULT_PRECIS                                    ' clipping precision
   lf.lfQuality        =  %DEFAULT_QUALITY                                        ' output quality
   lf.lfPitchAndFamily =  %FF_DONTCARE                                            ' pitch and family
   lf.lfFaceName       =  strFaceName                                             ' typeface name
   ReleaseDC %HWND_DESKTOP, hDC
   hLvHeaderFont = CreateFontIndirectW(lf)
   IF hLvHeaderFont = 0 THEN EXIT FUNCTION

   ' // Select the font
   hDC = GetDC(hLvHeader)
   hOldFont = SelectObject(hDC, hLvHeaderFont)
   ReleaseDC (hLvHeader, hDC)
   SendMessageW(hLvHeader, %WM_SETFONT, hLvHeaderFont, %TRUE)
   IF hOldFont THEN DeleteObject(hOldFont)
   FUNCTION = hLvHeaderFont

END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ListView_SetHeaderFont = ListView_SetHeaderFontW
#ELSE
   MACRO ListView_SetHeaderFont = ListView_SetHeaderFontA
#ENDIF

' ========================================================================================
' Modifies the font used by the listview header.
' Only the passed values that are not an empty string or zero will be modified.
' Note: The returned font must be destroyed with DeleteObject when no longer needed to prevent memory leaks.
' ========================================================================================
FUNCTION ListView_ModifyHeaderFontA ( _
   BYVAL hListView   AS DWORD, _          ' __in Handle to the listview
   BYVAL strFaceName AS STRING, _         ' __in Typeface name of font
   OPTIONAL BYVAL lPointSize AS LONG, _   ' __in Point size
   BYVAL lWeight     AS LONG, _           ' __in Font weight(bold etc.)
   BYVAL bItalic     AS BYTE, _           ' __in TRUE = italic
   BYVAL bUnderline  AS BYTE, _           ' __in TRUE = underline
   BYVAL bStrikeOut  AS BYTE, _           ' __in TRUE = strikeout
   BYVAL bCharSet    AS BYTE _            ' __in character set
   ) AS DWORD                             ' Handle of font or NULL on failure.

   LOCAL hLvHeader AS DWORD
   LOCAL hLvHeaderFont AS DWORD
   LOCAL hCurFont AS DWORD
   LOCAL hOldFont AS DWORD
   LOCAL lf AS LOGFONTA
   LOCAL hDC AS DWORD

   ' // Get the handle of the header
   hLvHeader = SendMessageA(hListView, %LVM_GETHEADER, 0, 0)
   IF hLvHeader = 0 THEN EXIT FUNCTION

   ' // Get the handle of the font used by the header
   hCurFont = SendMessageA(hLvHeader, %WM_GETFONT, 0, 0)
   IF hCurFont = 0 THEN EXIT FUNCTION
   ' // Get the LOGFONT structure
   IF GetObjectA(hCurFont, SIZEOF(lf), lf) = 0 THEN EXIT FUNCTION

   ' // Change the requested values
   IF lPointSize THEN
      hDC = GetDC(%HWND_DESKTOP)
      lf.lfHeight = -MulDiv(lPointSize, GetDeviceCaps(hDC, %LOGPIXELSY), 72)
      ReleaseDC %HWND_DESKTOP, hDC
   END IF
   IF lWeight THEN lf.lfWeight =  lWeight
   IF bItalic THEN lf.lfItalic =  bItalic
   IF bUnderline THEN lf.lfUnderline =  bUnderline
   IF bStrikeOut THEN lf.lfStrikeOut =  bStrikeOut
   IF bCharset THEN lf.lfCharSet =  bCharset
   IF strFaceName <> "" THEN lf.lfFaceName =  strFaceName

   ' // Create the font
   hLvHeaderFont = CreateFontIndirectA(lf)
   IF hLvHeaderFont = 0 THEN EXIT FUNCTION

   ' // Select the font
   hDC = GetDC(hLvHeader)
   hOldFont = SelectObject(hDC, hLvHeaderFont)
   ReleaseDC (hLvHeader, hDC)
   SendMessageA(hLvHeader, %WM_SETFONT, hLvHeaderFont, %TRUE)
   IF hOldFont THEN DeleteObject(hOldFont)
   FUNCTION = hLvHeaderFont

END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION ListView_ModifyHeaderFontW ( _
   BYVAL hListView   AS DWORD, _          ' __in Handle to the listview
   BYVAL strFaceName AS STRING, _         ' __in Typeface name of font
   OPTIONAL BYVAL lPointSize AS LONG, _   ' __in Point size
   BYVAL lWeight     AS LONG, _           ' __in Font weight(bold etc.)
   BYVAL bItalic     AS BYTE, _           ' __in TRUE = italic
   BYVAL bUnderline  AS BYTE, _           ' __in TRUE = underline
   BYVAL bStrikeOut  AS BYTE, _           ' __in TRUE = strikeout
   BYVAL bCharSet    AS BYTE _            ' __in character set
   ) AS DWORD                             ' Handle of font or NULL on failure.

   LOCAL hLvHeader AS DWORD
   LOCAL hLvHeaderFont AS DWORD
   LOCAL hCurFont AS DWORD
   LOCAL hOldFont AS DWORD
   LOCAL lf AS LOGFONTW
   LOCAL hDC AS DWORD

   ' // Get the handle of the header
   hLvHeader = SendMessageW(hListView, %LVM_GETHEADER, 0, 0)
   IF hLvHeader = 0 THEN EXIT FUNCTION

   ' // Get the handle of the font used by the header
   hCurFont = SendMessageW(hLvHeader, %WM_GETFONT, 0, 0)
   IF hCurFont = 0 THEN EXIT FUNCTION
   ' // Get the LOGFONT structure
   IF GetObjectW(hCurFont, SIZEOF(lf), lf) = 0 THEN EXIT FUNCTION

   ' // Change the requested values
   IF lPointSize THEN
      hDC = GetDC(%HWND_DESKTOP)
      lf.lfHeight = -MulDiv(lPointSize, GetDeviceCaps(hDC, %LOGPIXELSY), 72)
      ReleaseDC %HWND_DESKTOP, hDC
   END IF
   IF lWeight THEN lf.lfWeight =  lWeight
   IF bItalic THEN lf.lfItalic =  bItalic
   IF bUnderline THEN lf.lfUnderline =  bUnderline
   IF bStrikeOut THEN lf.lfStrikeOut =  bStrikeOut
   IF bCharset THEN lf.lfCharSet =  bCharset
   IF strFaceName <> "" THEN lf.lfFaceName =  strFaceName

   ' // Create the font
   hLvHeaderFont = CreateFontIndirectW(lf)
   IF hLvHeaderFont = 0 THEN EXIT FUNCTION

   ' // Select the font
   hDC = GetDC(hLvHeader)
   hOldFont = SelectObject(hDC, hLvHeaderFont)
   ReleaseDC (hLvHeader, hDC)
   SendMessageW(hLvHeader, %WM_SETFONT, hLvHeaderFont, %TRUE)
   IF hOldFont THEN DeleteObject(hOldFont)
   FUNCTION = hLvHeaderFont

END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO ListView_ModifyHeaderFont = ListView_ModifyHeaderFontW
#ELSE
   MACRO ListView_ModifyHeaderFont = ListView_ModifyHeaderFontA
#ENDIF

' ========================================================================================
' Retrieves the font used by the ToolTip control that the list-view control uses to display ToolTips.
' ========================================================================================
FUNCTION LietView_GetTooltipsFont (BYVAL hwndLV AS DWORD) AS DWORD
   LOCAL hwndTooltips AS DWORD
   hwndTooltips = SendMessage(hwndLV, %LVM_GETTOOLTIPS, 0, 0)
   FUNCTION = SendMessage(hwndTooltips, %WM_GETFONT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the font used by the ToolTip control that the list-view control uses to display ToolTips.
' Parameters:
' - hwndLV  = Handle to the ListView control.
' - hFont   = Handle to the font. If this parameter is NULL, the control uses the default system font to draw text.
' - fRedraw = Specifies whether the control should be redrawn immediately upon setting the font.
'             If this parameter is TRUE, the control redraws itself.
' ========================================================================================
SUB ListView_SetTooltipsFont (BYVAL hwndLV AS DWORD, OPTIONAL BYVAL hFont AS DWORD, OPTIONAL BYVAL fRedraw AS LONG)
   LOCAL hwndTooltips AS DWORD
   hwndTooltips = SendMessage(hwndLV, %LVM_GETTOOLTIPS, 0, 0)
   SendMessage hwndTooltips, %WM_SETFONT, hFont, fRedraw
END SUB
' ========================================================================================
