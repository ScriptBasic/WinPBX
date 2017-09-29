' ########################################################################################
' Microsoft Windows
' File: TabCtrl.inc
' Contents: Tab Control Wrapper Functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TABCTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"

' ========================================================================================
' Adds a new tab in a Tab control.
' iImage = 0-based index of the image in the image list or -1 for no image
' ========================================================================================
FUNCTION TabCtrl_AddTabA (BYVAL hTab AS DWORD, BYVAL iImage AS LONG, BYVAL strText AS STRING) AS LONG
   LOCAL ttc_item AS TCITEMA
   LOCAL nTabIndex AS DWORD
   ttc_item.mask = %TCIF_TEXT OR %TCIF_IMAGE OR %TCIF_RTLREADING OR %TCIF_PARAM OR %TCIF_STATE OR %TCIS_BUTTONPRESSED OR %TCIS_HIGHLIGHTED
   ttc_item.pszText = STRPTR(strText)
   ttc_item.cchTextMax = LEN(strText)
   ttc_item.iImage = iImage
   ttc_item.lParam = 0
   nTabIndex = SendMessageA(hTab, %TCM_GETITEMCOUNT, 0, 0)
   FUNCTION = SendMessageA(hTab, %TCM_INSERTITEMA, nTabIndex, VARPTR(ttc_item))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION TabCtrl_AddTabW (BYVAL hTab AS DWORD, BYVAL iImage AS LONG, BYVAL bstrText AS WSTRING) AS LONG
   LOCAL ttc_item AS TCITEMW
   LOCAL nTabIndex AS DWORD
   ttc_item.mask = %TCIF_TEXT OR %TCIF_IMAGE OR %TCIF_RTLREADING OR %TCIF_PARAM OR %TCIF_STATE OR %TCIS_BUTTONPRESSED OR %TCIS_HIGHLIGHTED
   ttc_item.pszText = STRPTR(bstrText)
   ttc_item.cchTextMax = LEN(bstrText)
   ttc_item.iImage = iImage
   ttc_item.lParam = 0
   nTabIndex = SendMessageW(hTab, %TCM_GETITEMCOUNT, 0, 0)
   FUNCTION = SendMessageW(hTab, %TCM_INSERTITEMW, nTabIndex, VARPTR(ttc_item))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO TabCtrl_AddTab = TabCtrl_AddTabW
#ELSE
   MACRO TabCtrl_AddTab = TabCtrl_AddTabA
#ENDIF

' ========================================================================================
' Calculates a tab control's display area given a window rectangle, or calculates the
' window rectangle that would correspond to a specified display area.
' ========================================================================================
SUB TabCtrl_AdjustRect (BYVAL hwndTab AS DWORD, BYVAL fLarger AS DWORD, BYREF prc AS RECT)
   SendMessage hwndTab, %TCM_ADJUSTRECT, fLarger, VARPTR(prc)
END SUB
' ========================================================================================

' ========================================================================================
' Removes all items from a tab control.
' ========================================================================================
FUNCTION TabCtrl_DeleteAllItems (BYVAL hwndTab AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTab, %TCM_DELETEALLITEMS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes an item from a tab control.
' ========================================================================================
FUNCTION TabCtrl_DeleteItem (BYVAL hwndTab AS DWORD, BYVAL iItem AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTab, %TCM_DELETEITEM, iItem, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Resets items in a tab control, clearing any that were set to the TCIS_BUTTONPRESSED state.
' ========================================================================================
SUB TabCtrl_DeselectAll (BYVAL hwndTab AS DWORD, BYVAL fExcludeFocus AS DWORD)
   SendMessage hwndTab, %TCM_DESELECTALL, fExcludeFocus, 0
END SUB
' ========================================================================================

' ========================================================================================
' Returns the index of the item that has the focus in a tab control.
' ========================================================================================
FUNCTION TabCtrl_GetCurFocus (BYVAL hwndTab AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTab, %TCM_GETCURFOCUS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines the currently selected tab in a tab control.
' ========================================================================================
FUNCTION TabCtrl_GetCurSel (BYVAL hwndTab AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTab, %TCM_GETCURSEL, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the extended styles that are currently in use for the tab control.
' ========================================================================================
FUNCTION TabCtrl_GetExtendedStyle (BYVAL hwndTab AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndTab, %TCM_GETEXTENDEDSTYLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the 0-based index in the tab control's image list.
' Returns the index of the image or -1 if not found.
' ========================================================================================
FUNCTION TabCtrl_GetImageIndexA (BYVAL hwndTab AS DWORD, BYVAL iItem AS DWORD) AS LONG
   LOCAL ttc_item AS TCITEMA
   ttc_item.mask = %TCIF_IMAGE
   IF SendMessageA(hwndTab, %TCM_GETITEMA, iItem, VARPTR(ttc_item)) THEN
      FUNCTION = ttc_item.iImage
   ELSE
      FUNCTION = -1
   END IF
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION TabCtrl_GetImageIndexW (BYVAL hwndTab AS DWORD, BYVAL iItem AS DWORD) AS LONG
   LOCAL ttc_item AS TCITEMW
   ttc_item.mask = %TCIF_IMAGE
   IF SendMessageW(hwndTab, %TCM_GETITEMW, iItem, VARPTR(ttc_item)) THEN
      FUNCTION = ttc_item.iImage
   ELSE
      FUNCTION = -1
   END IF
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO TabCtrl_GetImageIndex = TabCtrl_GetImageIndexW
#ELSE
   MACRO TabCtrl_GetImageIndex = TabCtrl_GetImageIndexA
#ENDIF

' ========================================================================================
' Retrieves the image list associated with a tab control.
' ========================================================================================
FUNCTION TabCtrl_GetImageList (BYVAL hWndTab AS DWORD) AS DWORD
   FUNCTION = SendMessage(hWndTab, %TCM_GETIMAGELIST, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves information about a tab in a tab control.
' ========================================================================================
FUNCTION TabCtrl_GetItemA (BYVAL hwndTab AS DWORD, BYVAL iItem AS DWORD, BYREF pItem AS TCITEMA) AS LONG
   FUNCTION = SendMessageA(hwndTab, %TCM_GETITEMA, iItem, VARPTR(pItem))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION TabCtrl_GetItemW (BYVAL hwndTab AS DWORD, BYVAL iItem AS DWORD, BYREF pItem AS TCITEMW) AS LONG
   FUNCTION = SendMessageW(hwndTab, %TCM_GETITEMW, iItem, VARPTR(pItem))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO TabCtrl_GetItem = TabCtrl_GetItemW
#ELSE
   MACRO TabCtrl_GetItem = TabCtrl_GetItemA
#ENDIF

' ========================================================================================
' Retrieves the number of tabs in the tab control.
' ========================================================================================
FUNCTION TabCtrl_GetItemCount (BYVAL hwndTab AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTab, %TCM_GETITEMCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the bounding rectangle for a tab in a tab control.
' ========================================================================================
FUNCTION TabCtrl_GetItemRect (BYVAL hwndTab AS DWORD, BYVAL iItem AS DWORD, BYREF prc AS RECT) AS LONG
   FUNCTION = SendMessage(hwndTab, %TCM_GETITEMRECT, iItem, VARPTR(prc))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the number of tabs in the tab control.
' ========================================================================================
FUNCTION TabCtrl_GetRowCount (BYVAL hwndTab AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTab, %TCM_GETROWCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the name of a tab in a Tab control.
' ========================================================================================
FUNCTION TabCtrl_GetTextA (BYVAL hwndTab AS DWORD, BYVAL nTabIndex AS DWORD) AS STRING
   LOCAL ttc_item AS TCITEMA
   LOCAL szText AS ASCIIZ * 256
   ttc_item.mask = %TCIF_TEXT
   ttc_item.pszText = VARPTR(szText)
   ttc_item.cchTextMax = SIZEOF(szText)
   SendMessageA hwndTab, %TCM_GETITEMA, nTabIndex, VARPTR(ttc_item)
   FUNCTION = szText
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION TabCtrl_GetTextW (BYVAL hwndTab AS DWORD, BYVAL nTabIndex AS DWORD) AS WSTRING
   LOCAL ttc_item AS TCITEMW
   LOCAL wszText AS WSTRINGZ * 256
   ttc_item.mask = %TCIF_TEXT
   ttc_item.pszText = VARPTR(wszText)
   ttc_item.cchTextMax = SIZEOF(wszText)
   SendMessageW hwndTab, %TCM_GETITEMW, nTabIndex, VARPTR(ttc_item)
   FUNCTION = wszText
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO TabCtrl_GetText = TabCtrl_GetTextW
#ELSE
   MACRO TabCtrl_GetText = TabCtrl_GetTextA
#ENDIF

' ========================================================================================
' Retrieves the handle to the ToolTip control associated with a tab control.
' ========================================================================================
FUNCTION TabCtrl_GetToolTips (BYVAL hwndTab AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndTab, %TCM_GETTOOLTIPS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the UNICODE character format flag for the control.
' ========================================================================================
FUNCTION TabCtrl_GetUnicodeFormat (BYVAL hwndTab AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTab, %TCM_GETUNICODEFORMAT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the highlight state of a tab item.
' ========================================================================================
FUNCTION TabCtrl_HighlightItem (BYVAL hwndTab AS DWORD, BYVAL idItem AS DWORD, BYVAL fHighlight AS WORD) AS LONG
   FUNCTION = SendMessage(hwndTab, %TCM_HIGHLIGHTITEM, idItem, MAK(LONG, fHighlight, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines which tab, if any, is at a specified screen position.
' ========================================================================================
FUNCTION TabCtrl_HitTest (BYVAL hwndTab AS DWORD, BYREF pinfo AS TC_HITTESTINFO) AS LONG
   FUNCTION = SendMessage(hwndTab, %TCM_HITTEST, 0, VARPTR(pinfo))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Inserts a new tab in a tab control.
' ========================================================================================
FUNCTION TabCtrl_InsertItemA (BYVAL hwndTab AS DWORD, BYVAL iItem AS DWORD, BYREF pItem AS TCITEMA) AS LONG
   FUNCTION = SendMessageA(hwndTab, %TCM_INSERTITEMA, iItem, VARPTR(pItem))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION TabCtrl_InsertItemW (BYVAL hwndTab AS DWORD, BYVAL iItem AS DWORD, BYREF pItem AS TCITEMW) AS LONG
   FUNCTION = SendMessageW(hwndTab, %TCM_INSERTITEMW, iItem, VARPTR(pItem))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO TabCtrl_InsertItem = TabCtrl_InsertItemW
#ELSE
   MACRO TabCtrl_InsertItem = TabCtrl_InsertItemA
#ENDIF

' ========================================================================================
' Inserts a new tab in a tab control.
' nTabInxex = 0-based index of the tab
' iImage = 0-based index of the image in the image list or -1 for no image
' ========================================================================================
FUNCTION TabCtrl_InsertTabA (BYVAL hwndTab AS DWORD, BYVAL nTabIndex AS DWORD, BYVAL iImage AS LONG, BYVAL strText AS STRING) AS LONG
   LOCAL ttc_item AS TCITEMA
   ttc_item.mask = %TCIF_TEXT OR %TCIF_IMAGE OR %TCIF_RTLREADING OR %TCIF_PARAM OR %TCIF_STATE OR %TCIS_BUTTONPRESSED OR %TCIS_HIGHLIGHTED
   ttc_item.pszText = STRPTR(strText)
   ttc_item.cchTextMax = LEN(strText)
   ttc_item.iImage = iImage
   ttc_item.lParam = 0
   FUNCTION = SendMessageA(hwndTab, %TCM_INSERTITEMA, nTabIndex, VARPTR(ttc_item))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION TabCtrl_InsertTabW (BYVAL hwndTab AS DWORD, BYVAL nTabIndex AS DWORD, BYVAL iImage AS LONG, BYVAL bstrText AS WSTRING) AS LONG
   LOCAL ttc_item AS TCITEMW
   ttc_item.mask = %TCIF_TEXT OR %TCIF_IMAGE OR %TCIF_RTLREADING OR %TCIF_PARAM OR %TCIF_STATE OR %TCIS_BUTTONPRESSED OR %TCIS_HIGHLIGHTED
   ttc_item.pszText = STRPTR(bstrText)
   ttc_item.cchTextMax = LEN(bstrText)
   ttc_item.iImage = iImage
   ttc_item.lParam = 0
   FUNCTION = SendMessageW(hwndTab, %TCM_INSERTITEMW, nTabIndex, VARPTR(ttc_item))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO TabCtrl_InsertTab = TabCtrl_InsertTabW
#ELSE
   MACRO TabCtrl_InsertTab = TabCtrl_InsertTabA
#ENDIF

' ========================================================================================
' Removes an image from a tab control's image list.
' ========================================================================================
SUB TabCtrl_RemoveImage (BYVAL hwndTab AS DWORD, BYVAL iImage AS DWORD)
   SendMessage hwndTab, %TCM_REMOVEIMAGE, iImage, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the focus to a specified tab in a tab control.
' ========================================================================================
SUB TabCtrl_SetCurFocus (BYVAL hwndTab AS DWORD, BYVAL iItem AS DWORD)
   SendMessage hwndTab, %TCM_SETCURFOCUS, iItem, 0
END SUB
' ========================================================================================

' ========================================================================================
' Selects a tab in a tab control.
' ========================================================================================
FUNCTION TabCtrl_SetCurSel (BYVAL hwndTab AS DWORD, BYVAL iItem AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTab, %TCM_SETCURSEL, iItem, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the extended styles that the tab control will use.
' ========================================================================================
FUNCTION TabCtrl_SetExtendedStyle (BYVAL hwndTab AS DWORD, BYVAL dwExStyle AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndTab, %TCM_SETEXTENDEDSTYLE, 0, dwExStyle)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Assigns an image list to a tab control.
' ========================================================================================
FUNCTION TabCtrl_SetImageList (BYVAL hwndTab AS DWORD, BYVAL himl AS DWORD) AS DWORD
    FUNCTION = SendMessage(hwndTab, %TCM_SETIMAGELIST, 0, himl)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the 0-based index in the tab control's image list.
' Returns TRUE if successful, or FALSE otherwise.
' ========================================================================================
FUNCTION TabCtrl_SetImageIndexA (BYVAL hwndTab AS DWORD, BYVAL iItem AS DWORD, BYVAL iImage AS LONG) AS LONG
   LOCAL ttc_item AS TCITEMA
   ttc_item.mask = %TCIF_IMAGE
   ttc_item.iImage = iImage
   FUNCTION = SendMessageA(hwndTab, %TCM_SETITEMA, iItem, VARPTR(ttc_item))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION TabCtrl_SetImageIndexW (BYVAL hwndTab AS DWORD, BYVAL iItem AS DWORD, BYVAL iImage AS LONG) AS LONG
   LOCAL ttc_item AS TCITEMW
   ttc_item.mask = %TCIF_IMAGE
   ttc_item.iImage = iImage
   FUNCTION = SendMessageW(hwndTab, %TCM_SETITEMW, iItem, VARPTR(ttc_item))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO TabCtrl_SetImageIndex = TabCtrl_SetImageIndexW
#ELSE
   MACRO TabCtrl_SetImageIndex = TabCtrl_SetImageIndexA
#ENDIF

' ========================================================================================
' Sets some or all of a tab's attributes.
' ========================================================================================
FUNCTION TabCtrl_SetItemA (BYVAL hwndTab AS DWORD, BYVAL iItem AS DWORD, BYREF pItem AS TCITEMA) AS LONG
   FUNCTION = SendMessageA(hwndTab, %TCM_SETITEMA, iItem, VARPTR(pItem))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION TabCtrl_SetItemW (BYVAL hwndTab AS DWORD, BYVAL iItem AS DWORD, BYREF pItem AS TCITEMW) AS LONG
   FUNCTION = SendMessageW(hwndTab, %TCM_SETITEMW, iItem, VARPTR(pItem))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO TabCtrl_SetItem = TabCtrl_SetItemW
#ELSE
   MACRO TabCtrl_SetItem = TabCtrl_SetItemA
#ENDIF

' ========================================================================================
' Sets the number of bytes per tab reserved for application-defined data in a tab control.
' ========================================================================================
FUNCTION TabCtrl_SetItemExtra (BYVAL hwndTab AS DWORD, BYVAL cb AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndTab, %TCM_SETITEMEXTRA, cb, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the width and height of tabs in a fixed-width or owner-drawn tab control.
' ========================================================================================
FUNCTION TabCtrl_SetItemSize (BYVAL hwndTab AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG) AS DWORD
   FUNCTION = SendMessage(hwndTab, %TCM_SETITEMSIZE, 0, MAK(LONG, x, y))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the width and height of tabs in a fixed-width or owner-drawn tab control.
' ========================================================================================
FUNCTION TabCtrl_SetMinTabWidth (BYVAL hwndTab AS DWORD, BYVAL cx AS LONG) AS LONG
   FUNCTION = SendMessage(hwndTab, %TCM_SETMINTABWIDTH, 0, cx)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the amount of space (padding) around each tab's icon and label in a tab control.
' ========================================================================================
SUB TabCtrl_SetPadding (BYVAL hwndTab AS DWORD, BYVAL cx AS INTEGER, BYVAL cy AS INTEGER)
   SendMessage hwndTab, %TCM_SETPADDING, 0, MAK(LONG, cx, cy)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the name of a tab in a Tab control.
' ========================================================================================
FUNCTION TabCtrl_SetTextA (BYVAL hwndTab AS DWORD, BYVAL nTabIndex AS DWORD, BYVAL strText AS STRING) AS LONG
   LOCAL ttc_item AS TCITEMA
   ttc_item.mask = %TCIF_TEXT
   ttc_item.pszText = STRPTR(strText)
   ttc_item.cchTextMax = LEN(strText)
   FUNCTION = SendMessageA(hwndTab, %TCM_SETITEMA, nTabIndex, VARPTR(ttc_item))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION TabCtrl_SetTextW (BYVAL hwndTab AS DWORD, BYVAL nTabIndex AS DWORD, BYVAL bstrText AS WSTRING) AS LONG
   LOCAL ttc_item AS TCITEMW
   ttc_item.mask = %TCIF_TEXT
   ttc_item.pszText = STRPTR(bstrText)
   ttc_item.cchTextMax = LEN(bstrText)
   FUNCTION = SendMessageW(hwndTab, %TCM_SETITEMW, nTabIndex, VARPTR(ttc_item))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO TabCtrl_SetText = TabCtrl_SetTextW
#ELSE
   MACRO TabCtrl_SetText = TabCtrl_SetTextA
#ENDIF

' ========================================================================================
' Assigns a ToolTip control to a tab control. You can use this macro or send the
' TCM_SETTOOLTIPS message explicitly.
' ========================================================================================
SUB TabCtrl_SetToolTips (BYVAL hwndTab AS DWORD, BYVAL hwndTT AS DWORD)
   SendMessage hwndTab, %TCM_SETTOOLTIPS, hwndTT, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the Unicode character format flag for the control. This message allows you to
' change the character set used by the control at run time rather than having to re-create
' the control.
' ========================================================================================
FUNCTION TabCtrl_SetUnicodeFormat (BYVAL hwndTab AS DWORD, BYVAL fUnicode AS LONG) AS LONG
   FUNCTION = SendMessage(hwndTab, %TCM_SETUNICODEFORMAT, fUnicode, 0)
END FUNCTION
' ========================================================================================
