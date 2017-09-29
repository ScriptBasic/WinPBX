' ########################################################################################
' Microsoft Windows
' File: TreeviewCtrl.inc
' Contents: TreeView Control Wrapper Functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TREEVIEWCTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"

' ========================================================================================
' Creates a dragging bitmap for the specified item in a tree-view control. The macro also
' creates an image list for the bitmap and adds the bitmap to the image list.
' ========================================================================================
FUNCTION TreeView_CreateDragImage (BYVAL hwndTV AS DWORD, BYVAL hitem AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndTV, %TVM_CREATEDRAGIMAGE, 0, hitem)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes all items from a tree-view control.
' ========================================================================================
FUNCTION TreeView_DeleteAllItems (BYVAL hwndTV AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTV, %TVM_DELETEITEM, 0, %TVI_ROOT)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes an item and all its children from a tree-view control.
' ========================================================================================
FUNCTION TreeView_DeleteItem (BYVAL hwndTV AS DWORD, BYVAL hitem AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTV, %TVM_DELETEITEM, 0, hitem)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Begins in-place editing of the specified item's text, replacing the text of the item
' with a single-line edit control containing the text.
' ========================================================================================
FUNCTION TreeView_EditLabel (BYVAL hwndTV AS DWORD, BYVAL hitem AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndTV, %TVM_EDITLABEL, 0, hitem)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Ends the editing of a tree-view item's label.
' ========================================================================================
FUNCTION TreeView_EndEditLabelNow (BYVAL hwndTV AS DWORD, BYVAL fCancel AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTV, %TVM_ENDEDITLABELNOW, fCancel, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Ensures that a tree-view item is visible, expanding the parent item or scrolling the
' tree-view control, if necessary.
' ========================================================================================
FUNCTION TreeView_EnsureVisible (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTV, %TVM_ENSUREVISIBLE, 0, hItem)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Expands or collapses the list of child items associated with the specified parent item, if any.
' ========================================================================================
FUNCTION TreeView_Expand (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD, BYVAL flag AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTV, %TVM_EXPAND, flag, hItem)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current background color of the control.
' ========================================================================================
FUNCTION TreeView_GetBkColor (BYVAL hwndTV AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTV, %TVM_GETBKCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns -1 if the bold attribute is set; 0 otherwise.
' ========================================================================================
FUNCTION TreeView_GetBold (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD) AS LONG
   FUNCTION = ((TreeView_GetItemState(hwndTV, hItem, %TVIS_BOLD) AND %TVIS_BOLD) = %TVIS_BOLD)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the check state of the specified item.
' ========================================================================================
FUNCTION TreeView_GetCheckState (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD) AS LONG
   LOCAL nState AS LONG
   nState = SendMessage(hwndTV, %TVM_GETITEMSTATE, hItem, %TVIS_STATEIMAGEMASK)
   SHIFT RIGHT nState, 12
   nState -=1
   FUNCTION = nState
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns -1 if the item is checked, or 0 otherwise.
' ========================================================================================
FUNCTION TreeView_IsItemChecked (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD) AS LONG
   LOCAL nState AS LONG
   nState = SendMessage(hwndTV, %TVM_GETITEMSTATE, hItem, %TVIS_STATEIMAGEMASK)
   SHIFT RIGHT nState, 12
   nState -=1
   FUNCTION = (nState = 1)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the first child item of the specified tree-view item.
' ========================================================================================
FUNCTION TreeView_GetChild (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD) AS DWORD
   FUNCTION = TreeView_GetNextItem(hwndTV, hItem, %TVGN_CHILD)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a count of the items in a tree-view control.
' ========================================================================================
FUNCTION TreeView_GetCount (BYVAL hwndTV AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTV, %TVM_GETCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the tree-view item that is the target of a drag-and-drop operation.
' ========================================================================================
FUNCTION TreeView_GetDropHilight (BYVAL hwndTV AS DWORD) AS DWORD
   FUNCTION = TreeView_GetNextItem(hwndTV, %NULL, %TVGN_DROPHILITE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the handle to the edit control being used to edit a tree-view item's text.
' ========================================================================================
FUNCTION TreeView_GetEditControl (BYVAL hwndTV AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndTV, %TVM_GETEDITCONTROL, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the extended style for a specified tree-view control.
' ========================================================================================
FUNCTION TreeView_GetExtendedStyle (BYVAL hwndTV AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndTV, %TVM_GETEXTENDEDSTYLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the first visible item in a tree-view control window.
' ========================================================================================
FUNCTION TreeView_GetFirstVisible (BYVAL hwndTV AS DWORD) AS DWORD
   FUNCTION = TreeView_GetNextItem(hwndTV, %NULL, %TVGN_FIRSTVISIBLE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the handle to the normal or state image list associated with a tree-view control.
' ========================================================================================
FUNCTION TreeView_GetImageList (BYVAL hwndTV AS DWORD, BYVAL iImage AS LONG) AS DWORD
   FUNCTION = SendMessage(hwndTV, %TVM_GETIMAGELIST, iImage, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the amount, in pixels, that child items are indented relative to their parent items.
' ========================================================================================
FUNCTION TreeView_GetIndent (BYVAL hwndTV AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndTV, %TVM_GETINDENT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the color used to draw the insertion mark for the tree view.
' ========================================================================================
FUNCTION TreeView_GetInsertMarkColor (BYVAL hwndTV AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndTV, %TVM_GETINSERTMARKCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the incremental search string for a tree-view control.
' ========================================================================================
'FUNCTION TreeView_GetISearchString (BYVAL hwndTV AS DWORD, lpsz AS ASCIIZ) AS LONG
'   FUNCTION = SendMessage(hwndTV, %TVM_GETISEARCHSTRING, 0, VARPTR(lpsz))
'END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the length of the incremental search string of a list-view control.
' ========================================================================================
FUNCTION TreeView_GetISearchStringLen (BYVAL hwndTV AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTV, %TVM_GETISEARCHSTRING, 0, BYVAL %NULL)
END FUNCTION
' ========================================================================================

#IF %DEF(%USEPBDECL)
FUNCTION TreeView_GetISearchStringA (BYVAL hwndTV AS DWORD, lpsz AS ASCIIZ) AS LONG
    FUNCTION = SendMessage(hwndTV, %TVM_GETISEARCHSTRINGA, 0, VARPTR(lpsz))
END FUNCTION

FUNCTION TreeView_GetISearchStringW (BYVAL hwndTV AS DWORD, lpsz AS WSTRINGZ) AS LONG
    FUNCTION = SendMessage(hwndTV, %TVM_GETISEARCHSTRINGW, 0, VARPTR(lpsz))
END FUNCTION
#ELSE
' ========================================================================================
' Gets the incremental search string of a list-view control.
' ========================================================================================
FUNCTION TreeView_GetISearchStringA (BYVAL hwndTV AS DWORD) AS STRING
   LOCAL nLen AS LONG
   LOCAL strSearch AS STRING
   nLen = SendMessageA(hwndTV, %TVM_GETISEARCHSTRINGA, 0, BYVAL %NULL)
   strSearch = SPACE$(nLen + 1)
   nLen = SendMessageA(hwndTV, %TVM_GETISEARCHSTRINGA, 0, BYVAL STRPTR(strSearch))
   FUNCTION = LEFT$(strSearch, nLen)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION TreeView_GetISearchStringW (BYVAL hwndLV AS DWORD) AS WSTRING
   LOCAL nLen AS LONG
   LOCAL bstrSearch AS WSTRING
   nLen = SendMessageW(hwndLV, %TVM_GETISEARCHSTRINGW, 0, BYVAL %NULL)
   bstrSearch = SPACE$(nLen + 1)
   nLen = SendMessageW(hwndLV, %TVM_GETISEARCHSTRINGW, 0, BYVAL STRPTR(bstrSearch))
   FUNCTION = LEFT$(bstrSearch, nLen)
END FUNCTION
' ========================================================================================
#ENDIF

#IF %DEF(%UNICODE)
   MACRO TreeView_GetISearchString = TreeView_GetISearchStringW
#ELSE
   MACRO TreeView_GetISearchString = TreeView_GetISearchStringA
#ENDIF

' ========================================================================================
' Retrieves some or all of a tree-view item's attributes.
' ========================================================================================
FUNCTION TreeView_GetItemA (BYVAL hwndTV AS DWORD, BYREF pitem AS TVITEMA) AS LONG
   FUNCTION = SendMessageA(hwndTV, %TVM_GETITEMA, 0, VARPTR(pitem))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION TreeView_GetItemW (BYVAL hwndTV AS DWORD, BYREF pitem AS TVITEMW) AS LONG
   FUNCTION = SendMessageW(hwndTV, %TVM_GETITEMW, 0, VARPTR(pitem))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO TreeView_GetItem = TreeView_GetItemW
#ELSE
   MACRO TreeView_GetItem = TreeView_GetItemA
#ENDIF

' ========================================================================================
' Retrieves some or all of a tree-view item's attributes.
' ========================================================================================
FUNCTION TreeView_GetItemExA (BYVAL hwndTV AS DWORD, BYREF pitem AS TVITEMEXA) AS LONG
   FUNCTION = SendMessageA(hwndTV, %TVM_GETITEMA, 0, VARPTR(pitem))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION TreeView_GetItemExW (BYVAL hwndTV AS DWORD, BYREF pitem AS TVITEMEXW) AS LONG
   FUNCTION = SendMessageW(hwndTV, %TVM_GETITEMW, 0, VARPTR(pitem))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO TreeView_GetItemEx = TreeView_GetItemExW
#ELSE
   MACRO TreeView_GetItemEx = TreeView_GetItemExA
#ENDIF

' ========================================================================================
' Retrieves the current height of the tree-view items.
' ========================================================================================
FUNCTION TreeView_GetItemHeight (BYVAL hwndTV AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTV, %TVM_GETITEMHEIGHT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the largest possible bounding rectangle that constitutes the "hit zone" for a
' specified part of an item.
' ========================================================================================
FUNCTION TreeView_GetItemPartRect (BYVAL hwnd AS DWORD, BYVAL hitem AS DWORD, BYREF prc AS RECT, BYVAL partid AS LONG) AS LONG
   LOCAL info AS TVGETITEMPARTRECTINFO
   info.hti = hitem
   info.prc = VARPTR(prc)
   info.partID = partid
   FUNCTION = SendMessage(hwnd, %TVM_GETITEMPARTRECT, 0, VARPTR(info))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the bounding rectangle for a tree-view item and indicates whether the item is visible.
' ========================================================================================
FUNCTION TreeView_GetItemRect (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD, BYREF prc AS RECT, BYVAL fItemRect AS LONG) AS LONG
   prc.nLeft = hItem
   FUNCTION = SendMessage(hwndTV, %TVM_GETITEMRECT, fItemRect, VARPTR(prc))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves some or all of a tree-view item's state attributes.
' ========================================================================================
FUNCTION TreeView_GetItemState (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD, BYVAL stateMask AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndTV, %TVM_GETITEMSTATE, hItem, stateMask)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the text of the specified item.
' ========================================================================================
FUNCTION TreeView_GetItemTextA (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD, OPTIONAL BYVAL cchTextMax AS LONG) AS STRING
   LOCAL tvi AS TVITEMA
   LOCAL strText AS STRING
   LOCAL p AS LONG
   IF cchtextmax < 1 THEN cchtextmax = %MAX_PATH + 1
   strText = NUL$(cchtextmax + 1)
   tvi.hitem = hItem
   tvi.mask = %TVIF_TEXT
   tvi.psztext = STRPTR(strText)
   tvi.cchtextmax = cchtextmax + 1
   IF ISFALSE SendMessageA(hwndTV, %TVM_GETITEMA, 0, VARPTR(tvi)) THEN EXIT FUNCTION
   p = INSTR(strText, CHR$(0))
   IF p THEN strText = LEFT$(strText, p - 1)
   FUNCTION = strText
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION TreeView_GetItemTextW (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD, OPTIONAL BYVAL cchTextMax AS LONG) AS WSTRING
   LOCAL tvi AS TVITEMW
   LOCAL bstrText AS WSTRING
   LOCAL p AS LONG
   IF cchtextmax < 1 THEN cchtextmax = %MAX_PATH + 1
   bstrText = NUL$(cchtextmax + 1)
   tvi.hitem = hItem
   tvi.mask = %TVIF_TEXT
   tvi.psztext = STRPTR(bstrText)
   tvi.cchtextmax = cchtextmax + 1
   IF ISFALSE SendMessageW(hwndTV, %TVM_GETITEMW, 0, VARPTR(tvi)) THEN EXIT FUNCTION
   p = INSTR(bstrText, CHR$$(0))
   IF p THEN bstrText = LEFT$(bstrText, p - 1)
   FUNCTION = bstrText
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO TreeView_GetItemText = TreeView_GetItemTextW
#ELSE
   MACRO TreeView_GetItemText = TreeView_GetItemTextA
#ENDIF

' ========================================================================================
' Retrieves some or all of a tree-view item's state attributes.
' ========================================================================================
FUNCTION TreeView_GetLastVisible (BYVAL hwndTV AS DWORD) AS DWORD
   FUNCTION = TreeView_GetNextItem(hwndTV, %NULL, %TVGN_LASTVISIBLE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current line color.
' ========================================================================================
FUNCTION TreeView_GetLineColor (BYVAL hwndTV AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndTV, %TVM_GETLINECOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the tree-view item that bears the specified relationship to a specified item.
' ========================================================================================
FUNCTION TreeView_GetNextItem (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD, BYVAL flag AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndTV, %TVM_GETNEXTITEM, flag, hItem)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the tree-view item that bears the TVGN_NEXTSELECTED relationship to a specified tree item.
' ========================================================================================
FUNCTION TreeView_GetNextSelected (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD) AS DWORD
   FUNCTION = TreeView_GetNextItem(hwndTV, hItem, %TVGN_NEXTSELECTED)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the next sibling item of a specified item in a tree-view control.
' ========================================================================================
FUNCTION TreeView_GetNextSibling (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD) AS DWORD
   FUNCTION = TreeView_GetNextItem(hwndTV, hItem, %TVGN_NEXT)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the next visible item that follows a specified item in a tree-view control.
' ========================================================================================
FUNCTION TreeView_GetNextVisible (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD) AS DWORD
   FUNCTION = TreeView_GetNextItem(hwndTV, hItem, %TVGN_NEXTVISIBLE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the parent item of the specified tree-view item.
' ========================================================================================
FUNCTION TreeView_GetParent (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD) AS DWORD
   FUNCTION = TreeView_GetNextItem(hwndTV, hItem, %TVGN_PARENT)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the previous sibling item of a specified item in a tree-view control.
' ========================================================================================
FUNCTION TreeView_GetPrevSibling (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD) AS DWORD
   FUNCTION = TreeView_GetNextItem(hwndTV, hItem, %TVGN_PREVIOUS)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the first visible item that precedes a specified item in a tree-view control.
' ========================================================================================
FUNCTION TreeView_GetPrevVisible (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD) AS DWORD
   FUNCTION = TreeView_GetNextItem(hwndTV, hItem, %TVGN_PREVIOUSVISIBLE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the topmost or very first item of the tree-view control.
' ========================================================================================
FUNCTION TreeView_GetRoot (BYVAL hwndTV AS DWORD) AS DWORD
   FUNCTION = TreeView_GetNextItem(hwndTV, %NULL, %TVGN_ROOT)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the maximum scroll time for the tree-view control.
' ========================================================================================
FUNCTION TreeView_GetScrollTime (BYVAL hwndTV AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndTV, %TVM_GETSCROLLTIME, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Not implemented
' ========================================================================================
'FUNCTION TreeView_GetSelectedCount (BYVAL hwndTV AS DWORD) AS DWORD
'   FUNCTION = SendMessage(hwndTV, %TVM_GETSELECTEDCOUNT, 0, 0)
'END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the currently selected item in a tree-view control.
' ========================================================================================
FUNCTION TreeView_GetSelection (BYVAL hwndTV AS DWORD) AS DWORD
   FUNCTION = TreeView_GetNextItem(hwndTV, %NULL, %TVGN_CARET)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current text color of the control.
' ========================================================================================
FUNCTION TreeView_GetTextColor (BYVAL hwndTV AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTV, %TVM_GETTEXTCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the handle to the child ToolTip control used by a tree-view control.
' ========================================================================================
FUNCTION TreeView_GetToolTips (BYVAL hwndTV AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndTV, %TVM_GETTOOLTIPS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the Unicode character format flag for the control.
' ========================================================================================
FUNCTION TreeView_GetUnicodeFormat (BYVAL hwndTV AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTV, %TVM_GETUNICODEFORMAT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Obtains the number of items that can be fully visible in the client window of a
' tree-view control.
' ========================================================================================
FUNCTION TreeView_GetVisibleCount (BYVAL hwndTV AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndTV, %TVM_GETVISIBLECOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines the location of the specified point relative to the client area of a
' tree-view control.
' ========================================================================================
FUNCTION TreeView_HitTest (BYVAL hwndTV AS DWORD, BYREF lpht AS TVHITTESTINFO) AS DWORD
   FUNCTION = SendMessage(hwndTV, %TVM_HITTEST, 0, VARPTR(lpht))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Inserts a new item in a tree-view control.
' ========================================================================================
FUNCTION TreeView_AddItemA (BYVAL hwndTV AS DWORD, BYVAL hParent AS DWORD, BYVAL hInsertAfter AS DWORD, BYVAL iImage AS LONG, BYVAL iSelectedImage AS LONG, BYVAL strText AS STRING) AS DWORD
   LOCAL tvinsert AS TVINSERTSTRUCTA
   tvinsert.hParent             = hParent
   tvinsert.hInsertAfter        = hInsertAfter
   tvinsert.Item.iImage         = iImage
   tvinsert.Item.iSelectedImage = iSelectedImage
   tvinsert.Item.mask           = %TVIF_TEXT OR %TVIF_IMAGE OR %TVIF_SELECTEDIMAGE
   tvinsert.Item.pszText        = STRPTR(strText)
   tvinsert.Item.cchTextMax     = LEN(strText)
   FUNCTION = SendMessageA(hwndTV, %TVM_INSERTITEMA, 0, VARPTR(tvinsert))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION TreeView_AddItemW (BYVAL hwndTV AS DWORD, BYVAL hParent AS DWORD, BYVAL hInsertAfter AS DWORD, BYVAL iImage AS LONG, BYVAL iSelectedImage AS LONG, BYVAL bstrText AS WSTRING) AS DWORD
   LOCAL tvinsert AS TVINSERTSTRUCTW
   tvinsert.hParent             = hParent
   tvinsert.hInsertAfter        = hInsertAfter
   tvinsert.Item.iImage         = iImage
   tvinsert.Item.iSelectedImage = iSelectedImage
   tvinsert.Item.mask           = %TVIF_TEXT OR %TVIF_IMAGE OR %TVIF_SELECTEDIMAGE
   tvinsert.Item.pszText        = STRPTR(bstrText)
   tvinsert.Item.cchTextMax     = LEN(bstrText)
   FUNCTION = SendMessageW(hwndTV, %TVM_INSERTITEMW, 0, VARPTR(tvinsert))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO TreeView_AddItem = TreeView_AddItemW
#ELSE
   MACRO TreeView_AddItem = TreeView_AddItemA
#ENDIF

' ========================================================================================
' Inserts a new item in a tree-view control.
' ========================================================================================
FUNCTION TreeView_InsertItemA (BYVAL hwndTV AS DWORD, BYREF lpis AS TVINSERTSTRUCTA) AS DWORD
   FUNCTION = SendMessageA(hwndTV, %TVM_INSERTITEMA, 0, VARPTR(lpis))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION TreeView_InsertItemW (BYVAL hwndTV AS DWORD, BYREF lpis AS TVINSERTSTRUCTW) AS DWORD
   FUNCTION = SendMessageW(hwndTV, %TVM_INSERTITEMW, 0, VARPTR(lpis))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO TreeView_InsertItem = TreeView_InsertItemW
#ELSE
   MACRO TreeView_InsertItem = TreeView_InsertItemA
#ENDIF

' ========================================================================================
' Maps an accessibility ID to an HTREEITEM.
' ========================================================================================
FUNCTION TreeView_MapAccIDToHTREEITEM (BYVAL hwndTV AS DWORD, BYVAL id AS LONG) AS DWORD
   FUNCTION = SendMessage(hwndTV, %TVM_MAPACCIDTOHTREEITEM, id, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Maps an HTREEITEM to an accessibility ID.
' ========================================================================================
FUNCTION TreeView_MapHTREEITEMToAccID (BYVAL hwndTV AS DWORD, BYVAL htreeitem AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndTV, %TVM_MAPHTREEITEMTOACCID, htreeitem, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Selects the specified tree-view item, scrolls the item into view, or redraws the item in
' the style used to indicate the target of a drag-and-drop operation.
' ========================================================================================
FUNCTION TreeView_Select (BYVAL hwndTV AS DWORD, BYVAL hitem AS DWORD, BYVAL flag AS LONG) AS LONG
   FUNCTION = SendMessage(hwndTV, %TVM_SELECTITEM, flag, hItem)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Redraws a specified tree-view control item in the style used to indicate the target of a
' drag-and-drop operation.
' ========================================================================================
FUNCTION TreeView_SelectDropTarget (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD) AS LONG
   FUNCTION = TreeView_Select(hwndTV, hItem, %TVGN_DROPHILITE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Selects the specified tree-view item.
' ========================================================================================
FUNCTION TreeView_SelectItem (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD) AS LONG
   FUNCTION = TreeView_Select(hwndTV, hItem, %TVGN_CARET)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Scrolls the tree-view control vertically to ensure that the specified item is visible.
' ========================================================================================
FUNCTION TreeView_SelectSetFirstVisible (BYVAL hwndTV AS DWORD, BYVAL hitem AS DWORD) AS LONG
   FUNCTION = TreeView_Select(hwndTV, hitem, %TVGN_FIRSTVISIBLE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets information used to determine auto-scroll characteristics.
' ========================================================================================
FUNCTION TreeView_SetAutoScrollInfo (BYVAL hwndTV AS DWORD, BYVAL uPixPerSec AS DWORD, BYVAL uUpdateTime AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTV, %TVM_SETAUTOSCROLLINFO, uPixPerSec, uUpdateTime)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the background color of the control.
' ========================================================================================
FUNCTION TreeView_SetBkColor (BYVAL hwndTV AS DWORD, BYVAL clr AS LONG) AS LONG
   FUNCTION = SendMessage(hwndTV, %TVM_SETBKCOLOR, 0, clr)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets/unsets the bold attribute of the specified item.
' ========================================================================================
SUB TreeView_SetBold (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD, BYVAL fBold AS LONG)
   TreeView_SetItemState(hwndTV, hItem, IIF&(fBold = 0, 0, %TVIS_BOLD), %TVIS_BOLD)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the item's state image to "checked" or "unchecked."
' ========================================================================================
SUB TreeView_SetCheckState (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD, BYVAL fCheck AS LONG)
   LOCAL ix AS LONG
   ix = IIF&(ISTRUE fCheck, IndexToStateImageMask(2), IndexToStateImageMask(1))
   TreeView_SetItemState hwndTV, hItem, ix, %TVIS_STATEIMAGEMASK
END SUB
' ========================================================================================

' ========================================================================================
' Sets the extended style for a specified TreeView control.
' ========================================================================================
FUNCTION TreeView_SetExtendedStyle (BYVAL hwndTV AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL mask AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTV, %TVM_SETEXTENDEDSTYLE, mask, dwExStyle)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the normal or state image list for a tree-view control and redraws the control
' using the new images.
' ========================================================================================
FUNCTION TreeView_SetImageList (BYVAL hwndTV AS DWORD, BYVAL himl AS DWORD, BYVAL iImage AS LONG) AS DWORD
   FUNCTION = SendMessage(hwndTV, %TVM_SETIMAGELIST, iImage, himl)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the width of indentation for a tree-view control and redraws the control to reflect
' the new width.
' ========================================================================================
FUNCTION TreeView_SetIndent (BYVAL hwndTV AS DWORD, BYVAL indent AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTV, %TVM_SETINDENT, indent, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the insertion mark in a tree-view control.
' ========================================================================================
FUNCTION TreeView_SetInsertMark (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD, BYVAL fAfter AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTV, %TVM_SETINSERTMARK, fAfter, hItem)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the color used to draw the insertion mark for the tree view.
' ========================================================================================
FUNCTION TreeView_SetInsertMarkColor (BYVAL hwndTV AS DWORD, BYVAL clr AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndTV, %TVM_SETINSERTMARKCOLOR, 0, clr)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets some or all of a tree-view item's attributes.
' ========================================================================================
FUNCTION TreeView_SetItemA (BYVAL hwndTV AS DWORD, BYREF pitem AS TVITEMA) AS LONG
   FUNCTION = SendMessageA(hwndTV, %TVM_SETITEMA, 0, VARPTR(pitem))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION TreeView_SetItemW (BYVAL hwndTV AS DWORD, BYREF pitem AS TVITEMW) AS LONG
   FUNCTION = SendMessageW(hwndTV, %TVM_SETITEMW, 0, VARPTR(pitem))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO TreeView_SetItem = TreeView_SetItemW
#ELSE
   MACRO TreeView_SetItem = TreeView_SetItemA
#ENDIF

' ========================================================================================
' Sets some or all of a tree-view item's attributes.
' ========================================================================================
FUNCTION TreeView_SetItemExA (BYVAL hwndTV AS DWORD, BYREF pitem AS TVITEMEXA) AS LONG
   FUNCTION = SendMessageA(hwndTV, %TVM_SETITEMA, 0, VARPTR(pitem))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION TreeView_SetItemExW (BYVAL hwndTV AS DWORD, BYREF pitem AS TVITEMEXW) AS LONG
   FUNCTION = SendMessageW(hwndTV, %TVM_SETITEMW, 0, VARPTR(pitem))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO TreeView_SetItemEx = TreeView_SetItemExW
#ELSE
   MACRO TreeView_SetItemEx = TreeView_SetItemExA
#ENDIF

' ========================================================================================
' Sets the height of the tree-view items.
' ========================================================================================
FUNCTION TreeView_SetItemHeight (BYVAL hwndTV AS DWORD, BYVAL cyItem AS INTEGER) AS LONG
   FUNCTION = SendMessage(hwndTV, %TVM_SETITEMHEIGHT, cyItem, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets a tree-view item's state attributes.
' ========================================================================================
SUB TreeView_SetItemStateA (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD, BYVAL nState AS DWORD, BYVAL statemask AS DWORD)
   LOCAL tvi AS TVITEMA
   tvi.mask  = %TVIF_STATE
   tvi.hItem = hItem
   tvi.stateMask = statemask
   tvi.state = nState
   SendMessageA hwndTV, %TVM_SETITEMA, 0, VARPTR(tvi)
END SUB
' ========================================================================================
' ========================================================================================
SUB TreeView_SetItemStateW (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD, BYVAL nState AS DWORD, BYVAL statemask AS DWORD)
   LOCAL tvi AS TVITEMW
   tvi.mask  = %TVIF_STATE
   tvi.hItem = hItem
   tvi.stateMask = statemask
   tvi.state = nState
   SendMessageW hwndTV, %TVM_SETITEMW, 0, VARPTR(tvi)
END SUB
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO TreeView_SetItemState = TreeView_SetItemStateW
#ELSE
   MACRO TreeView_SetItemState = TreeView_SetItemStateA
#ENDIF

' ========================================================================================
' Sets the text of the specified item.
' ========================================================================================
FUNCTION TreeView_SetItemTextA (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD, BYREF szText AS ASCIIZ) AS LONG
   LOCAL tvi AS TVITEMA
   tvi.hitem = hItem
   tvi.mask = %TVIF_TEXT
   tvi.psztext = VARPTR(szText)
   tvi.cchtextmax = LEN(szText)
   FUNCTION = SendMessageA(hwndTV, %TVM_SETITEMA, 0, VARPTR(tvi))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION TreeView_SetItemTextW (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD, BYREF wszText AS WSTRINGZ) AS LONG
   LOCAL tvi AS TVITEMW
   tvi.hitem = hItem
   tvi.mask = %TVIF_TEXT
   tvi.psztext = VARPTR(wszText)
   tvi.cchtextmax = LEN(wszText)
   FUNCTION = SendMessageW(hwndTV, %TVM_SETITEMW, 0, VARPTR(tvi))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO TreeView_SetItemText = TreeView_SetItemTextW
#ELSE
   MACRO TreeView_SetItemText = TreeView_SetItemTextA
#ENDIF

' ========================================================================================
' Sets the text of the specified item.
' ========================================================================================
FUNCTION TreeView_SetTextA (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD, BYVAL strText AS STRING) AS LONG
   LOCAL tvi AS TVITEMA
   tvi.hitem = hItem
   tvi.mask = %TVIF_TEXT
   tvi.psztext = STRPTR(strText)
   tvi.cchtextmax = LEN(strText)
   FUNCTION = SendMessageA(hwndTV, %TVM_SETITEMA, 0, VARPTR(tvi))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION TreeView_SetTextW (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD, BYVAL bstrText AS WSTRING) AS LONG
   LOCAL tvi AS TVITEMW
   tvi.hitem = hItem
   tvi.mask = %TVIF_TEXT
   tvi.psztext = STRPTR(bstrText)
   tvi.cchtextmax = LEN(bstrText)
   FUNCTION = SendMessageW(hwndTV, %TVM_SETITEMW, 0, VARPTR(tvi))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO TreeView_SetText = TreeView_SetTextW
#ELSE
   MACRO TreeView_SetText = TreeView_SetTextA
#ENDIF

' ========================================================================================
' Sets the current line color.
' ========================================================================================
FUNCTION TreeView_SetLineColor (BYVAL hwndTV AS DWORD, BYVAL clrLine AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndTV, %TVM_SETLINECOLOR, 0, clrLine)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the maximum scroll time for the tree-view control.
' ========================================================================================
FUNCTION TreeView_SetScrollTime (BYVAL hwndTV AS DWORD, BYVAL uMaxScrollTime AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndTV, %TVM_SETSCROLLTIME, uMaxScrollTime, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the text color of the control.
' ========================================================================================
FUNCTION TreeView_SetTextColor (BYVAL hwndTV AS DWORD, BYVAL clrText AS LONG) AS LONG
   FUNCTION = SendMessage(hwndTV, %TVM_SETTEXTCOLOR, 0, clrText)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets a tree-view control's child ToolTip control.
' ========================================================================================
FUNCTION TreeView_SetToolTips (BYVAL hwndTV AS DWORD, BYVAL hwndTT AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndTV, %TVM_SETTOOLTIPS, hwndTT, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the Unicode character format flag for the control.
' ========================================================================================
FUNCTION TreeView_SetUnicodeFormat (BYVAL hwndTV AS DWORD, BYVAL fUnicode AS LONG) AS LONG
   FUNCTION = SendMessage(hwndTV, %TVM_SETUNICODEFORMAT, fUnicode, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Shows the infotip for a specified item in a tree-view control.
' ========================================================================================
FUNCTION TreeView_ShowInfoTip (BYVAL hwndTV AS DWORD, BYVAL hitem AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndTV, %TVM_SHOWINFOTIP, 0, hitem)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sorts the child items of the specified parent item in a tree-view control.
' ========================================================================================
FUNCTION TreeView_SortChildren (BYVAL hwndTV AS DWORD, BYVAL hitem AS DWORD, BYVAL fRecurse AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTV, %TVM_SORTCHILDREN, fRecurse, hitem)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sorts tree-view items using an application-defined callback function that compares the items.
' ========================================================================================
FUNCTION TreeView_SortChildrenCB (BYVAL hwndTV AS DWORD, psort AS TVSORTCB, fRecurse AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTV, %TVM_SORTCHILDRENCB, fRecurse, VARPTR(psort))
END FUNCTION
' ========================================================================================

' ========================================================================================

' ========================================================================================
' Searches for an exact string in a tree view node. Search is case sensitive.
' Returns TRUE or FALSE.
' ========================================================================================
FUNCTION TreeView_ItemExistsA (BYVAL hTreeView AS DWORD, BYVAL hNode AS DWORD, BYVAL strText AS STRING) AS LONG
   LOCAL hItem AS DWORD
   hItem = TreeView_GetChild(hTreeView, hNode)
   DO
      IF hItem = %NULL THEN EXIT FUNCTION
      IF TreeView_GetItemTextA(hTreeView, hItem) = strText THEN
         FUNCTION = %TRUE
         EXIT DO
      END IF
      hItem = TreeView_GetNextSibling(hTreeView, hItem)
   LOOP
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION TreeView_ItemExistsW (BYVAL hTreeView AS DWORD, BYVAL hNode AS DWORD, BYVAL bstrText AS WSTRING) AS LONG
   LOCAL hItem AS DWORD
   hItem = TreeView_GetChild(hTreeView, hNode)
   DO
      IF hItem = %NULL THEN EXIT FUNCTION
      IF TreeView_GetItemTextW(hTreeView, hItem) = bstrText THEN
         FUNCTION = %TRUE
         EXIT DO
      END IF
      hItem = TreeView_GetNextSibling(hTreeView, hItem)
   LOOP
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO TreeView_ItemExists = TreeView_ItemExistsW
#ELSE
   MACRO TreeView_ItemExists = TreeView_ItemExistsA
#ENDIF

' ========================================================================================
' Expands the list of child items, if any, associated with the specified parent node.
' ========================================================================================
SUB TreeView_ExpandChildItems (BYVAL hwndTV AS DWORD, BYVAL hNode AS DWORD)

   LOCAL hChildNode AS DWORD

   DO WHILE hNode
      ' // Expand the node
      TreeView_Expand(hwndTV, hNode, %TVM_EXPAND)
      ' // Get the first child node
      hChildNode = TreeView_GetChild(hwndTV, hNode)
      IF hChildNode THEN TreeView_ExpandChildItems(hwndTV, hChildNode)
      hNode = %NULL
   LOOP

END SUB
' ========================================================================================

' ========================================================================================
' Expands the list of sibling items, if any, associated with the specified parent node.
' ========================================================================================
SUB TreeView_ExpandSiblings (BYVAL hwndTV AS DWORD, BYVAL hNode AS DWORD)

   LOCAL hChildNode AS DWORD

   DO WHILE hNode
      ' // Expand the node
      TreeView_Expand(hwndTV, hNode, %TVM_EXPAND)
      ' // Get the next sibling item
      hNode = TreeView_GetNextSibling(hwndTV, hNode)
   LOOP

END SUB
' ========================================================================================

' ========================================================================================
' Expands the list of child items, if any, associated with the specified parent node and
' the sibling nodes below it.
' ========================================================================================
SUB TreeView_ExpandAllChildItems (BYVAL hwndTV AS DWORD, BYVAL hNode AS DWORD)

   LOCAL hChildNode AS DWORD

   DO WHILE hNode
      ' // Expand the node
      TreeView_Expand(hwndTV, hNode, %TVM_EXPAND)
      ' // Get the first child node
      hChildNode = TreeView_GetChild(hwndTV, hNode)
      IF hChildNode THEN TreeView_ExpandAllChildItems(hwndTV, hChildNode)
      ' // Get the next sibling item
      hNode = TreeView_GetNextSibling(hwndTV, hNode)
   LOOP

END SUB
' ========================================================================================

' ========================================================================================
' Expands all the list of items.
' Note: This is a very slow process if the control has many items.
' ========================================================================================
SUB TreeView_ExpandAllItems (BYVAL hwndTV AS DWORD)
   LOCAL hNode AS DWORD
   hNode = TreeView_GetRoot(hwndTV)
   IF hNode THEN TreeView_ExpandAllChildItems(hwndTV, hNode)
END SUB
' ========================================================================================

' ========================================================================================
' Collapses the list of child items, if any, associated with the specified parent node.
' ========================================================================================
SUB TreeView_CollapseChildItems (BYVAL hwndTV AS DWORD, BYVAL hNode AS DWORD)

   LOCAL hChildNode AS DWORD

   DO WHILE hNode
      ' // Collapse the node
      TreeView_Expand(hwndTV, hNode, %TVE_COLLAPSE)
      ' // Get the first child node
      hChildNode = TreeView_GetChild(hwndTV, hNode)
      IF hChildNode THEN TreeView_CollapseChildItems(hwndTV, hChildNode)
      hNode = %NULL
   LOOP

END SUB
' ========================================================================================

' ========================================================================================
' Collapses the list of sibling items, if any, associated with the specified parent node.
' ========================================================================================
SUB TreeView_CollapseSiblings (BYVAL hwndTV AS DWORD, BYVAL hNode AS DWORD)

   LOCAL hChildNode AS DWORD

   DO WHILE hNode
      ' // Collapse the node
      TreeView_Expand(hwndTV, hNode, %TVE_COLLAPSE)
      ' // Get the next sibling item
      hNode = TreeView_GetNextSibling(hwndTV, hNode)
   LOOP

END SUB
' ========================================================================================

' ========================================================================================
' Collapses the list of child items, if any, associated with the specified parent node and
' the sibling nodes below it.
' ========================================================================================
SUB TreeView_CollapseAllChildItems (BYVAL hwndTV AS DWORD, BYVAL hNode AS DWORD)

   LOCAL hChildNode AS DWORD

   DO WHILE hNode
      ' // Collapse the node
      TreeView_Expand(hwndTV, hNode, %TVE_COLLAPSE)
      ' // Get the first child node
      hChildNode = TreeView_GetChild(hwndTV, hNode)
      IF hChildNode THEN TreeView_CollapseAllChildItems(hwndTV, hChildNode)
      ' // Get the next sibling item
      hNode = TreeView_GetNextSibling(hwndTV, hNode)
   LOOP

END SUB
' ========================================================================================

' ========================================================================================
' Collapses all the list of items.
' ========================================================================================
SUB TreeView_CollapseAllItems (BYVAL hwndTV AS DWORD)
   LOCAL hNode AS DWORD
   hNode = TreeView_GetRoot(hwndTV)
   IF hNode THEN TreeView_CollapseAllChildItems(hwndTV, hNode)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the text of the parent item of the specified tree-view item.
' ========================================================================================
FUNCTION TreeView_GetParentTextA (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD, OPTIONAL BYVAL cchTextMax AS LONG) AS STRING
   LOCAL hNode AS DWORD
   hNode = TreeView_GetNextItem(hwndTV, hItem, %TVGN_PARENT)
   IF hNode THEN FUNCTION = TreeView_GetItemTextA(hwndTV, hNode, cchTextMax)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION TreeView_GetParentTextW (BYVAL hwndTV AS DWORD, BYVAL hItem AS DWORD, OPTIONAL BYVAL cchTextMax AS LONG) AS WSTRING
   LOCAL hNode AS DWORD
   hNode = TreeView_GetNextItem(hwndTV, hItem, %TVGN_PARENT)
   IF hNode THEN FUNCTION = TreeView_GetItemTextW(hwndTV, hNode, cchTextMax)
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO TreeView_GetParentText = TreeView_GetParentTextW
#ELSE
   MACRO TreeView_GetParentText = TreeView_GetParentTextA
#ENDIF
