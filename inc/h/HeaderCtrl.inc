' ########################################################################################
' Microsoft Windows
' File: HeaderCtrl.inc
' Contents: Header Control Wrapper Functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%HEADERCTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"

' ========================================================================================
' Clears all of the filters for a given header control.
' ========================================================================================
FUNCTION Header_ClearAllFilters (BYVAL hwndHD AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndHD, %HDM_CLEARFILTER, -1, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Clears the filter for a given header control.
' ========================================================================================
FUNCTION Header_ClearFilter (BYVAL hwndHD AS DWORD, BYVAL i AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndHD, %HDM_CLEARFILTER, i, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a transparent version of an item image within an existing header control.
' ========================================================================================
FUNCTION Header_CreateDragImage (BYVAL hwndHD AS DWORD, BYVAL i AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndHD, %HDM_CREATEDRAGIMAGE, i, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes an item from a header control.
' ========================================================================================
FUNCTION Header_DeleteItem (BYVAL hwndHD AS DWORD, BYVAL i AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndHD, %HDM_DELETEITEM, i, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Moves the input focus to the edit box when a filter button has the focus.
' ========================================================================================
FUNCTION Header_EditFilter (BYVAL hwndHD AS DWORD, BYVAL i AS DWORD, BYVAL fDiscardChanges AS INTEGER) AS LONG
   FUNCTION = SendMessage(hwndHD, %HDM_EDITFILTER, i, MAK(LONG, fDiscardChanges, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the width of the margin (in pixels) of a bitmap in an existing header control.
' ========================================================================================
FUNCTION Header_GetBitmapMargin (BYVAL hwndHD AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndHD, %HDM_GETBITMAPMARGIN, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the item in a header control that has the focus.
' ========================================================================================
FUNCTION Header_GetFocusedItem (BYVAL hwndHD AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndHD, %HDM_GETFOCUSEDITEM, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the handle to the image list that has been set for an existing header control.
' ========================================================================================
FUNCTION Header_GetImageList (BYVAL hwndHD AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndHD, %HDM_GETIMAGELIST, %HDSIL_NORMAL, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets information about an item in a header control.
' ========================================================================================
FUNCTION Header_GetItemA (BYVAL hwndHD AS DWORD, BYVAL iItem AS DWORD, BYREF phdi AS HDITEMA) AS LONG
   FUNCTION = SendMessageA(hwndHD, %HDM_GETITEMA, iItem, VARPTR(phdi))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Header_GetItemW (BYVAL hwndHD AS DWORD, BYVAL iItem AS DWORD, BYREF phdi AS HDITEMW) AS LONG
   FUNCTION = SendMessageW(hwndHD, %HDM_GETITEMW, iItem, VARPTR(phdi))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Header_GetItem = Header_GetItemW
#ELSE
   MACRO Header_GetItem = Header_GetItemA
#ENDIF

' ========================================================================================
' Gets a count of the items in a header control.
' ========================================================================================
FUNCTION Header_GetItemCount (BYVAL hwndHD AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndHD, %HDM_GETITEMCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the coordinates of the drop-down button for a specfied item in a header control.
' The header control must be of type HDF_SPLITBUTTON.
' ========================================================================================
FUNCTION Header_GetItemDropDownRect (BYVAL hwndHD AS DWORD, BYVAL iItem AS LONG, BYREF lprc AS RECT) AS LONG
   FUNCTION = SendMessage(hwndHD, %HDM_GETITEMDROPDOWNRECT, iItem, VARPTR(lprc))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the bounding rectangle for a given item in a header control.
' ========================================================================================
FUNCTION Header_GetItemRect (BYVAL hwndHD AS DWORD, BYVAL iItem AS LONG, BYREF lprc AS RECT) AS DWORD
   FUNCTION = SendMessage(hwndHD, %HDM_GETITEMRECT, iItem, VARPTR(lprc))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current left-to-right order of items in a header control.
' ========================================================================================
#IF %DEF(%USEPBDECL)
FUNCTION Header_GetOrderArray (BYVAL hwnd AS DWORD, BYVAL iCount AS DWORD, _
    BYVAL lpi AS LONG) AS LONG
    FUNCTION = SendMessage(hwnd, %HDM_GETORDERARRAY, iCount, lpi)
END FUNCTION
#ELSE
FUNCTION Header_GetOrderArray (BYVAL hwndHD AS DWORD, BYVAL iSize AS DWORD, BYREF lpiArray AS LONG) AS LONG
   FUNCTION = SendMessage(hwndHD, %HDM_GETORDERARRAY, iSize, VARPTR(lpiArray))
END FUNCTION
#ENDIF
' ========================================================================================

' ========================================================================================
' Gets the coordinates of the drop-down overflow area for a specified header control.
' The header control must be of type HDF_SPLITBUTTON.
' ========================================================================================
FUNCTION Header_GetOverflowRect (BYVAL hwndHD AS DWORD, BYREF lprc AS RECT) AS LONG
   FUNCTION = SendMessage(hwndHD, %HDM_GETOVERFLOWRECT, 0, VARPTR(lprc))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the handle to the image list that has been set for an existing header control state.
' ========================================================================================
FUNCTION Header_GetStateImageList (BYVAL hwndHD AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndHD, %HDM_GETIMAGELIST, %HDSIL_STATE, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the Unicode character format flag for the control.
' ========================================================================================
FUNCTION Header_GetUnicodeFormat (BYVAL hwndHD AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndHD, %HDM_GETUNICODEFORMAT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Tests a point to determine which header item, if any, is at the specified point.
' ========================================================================================
FUNCTION Header_HitTest (BYVAL hwndHD AS DWORD, BYREF phdhti AS HDHITTESTINFO) AS LONG
   FUNCTION = SendMessage(hwndHD, %HDM_HITTEST, 0, VARPTR(phdhti))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Inserts a new item into a header control.
' ========================================================================================
#IF %DEF(%USEPBDECL)
FUNCTION Header_InsertItem (BYVAL hWndHD AS DWORD, BYVAL i AS DWORD, _
    BYVAL phdi AS DWORD) AS LONG
    FUNCTION = SendMessage(hWndHD, %HDM_INSERTITEM, i, phdi)
END FUNCTION
#ELSE
FUNCTION Header_InsertItem (BYVAL hwndHD AS DWORD, BYVAL i AS DWORD, BYREF phdi AS HDITEM) AS LONG
   FUNCTION = SendMessage(hwndHD, %HDM_INSERTITEM, i, VARPTR(phdi))
END FUNCTION
#ENDIF
' ========================================================================================

' ========================================================================================
' Retrieves the correct size and position of a header control within the parent window.
' ========================================================================================
FUNCTION Header_Layout (BYVAL hwndHD AS DWORD, BYREF playout AS HDLAYOUT) AS LONG
   FUNCTION = SendMessage(hwndHD, %HDM_LAYOUT, 0, VARPTR(playout))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves an index value for an item based on its order in the header control.
' ========================================================================================
FUNCTION Header_OrderToIndex (BYVAL hwndHD AS DWORD, BYVAL i AS LONG) AS DWORD
   FUNCTION = SendMessage(hwndHD, %HDM_ORDERTOINDEX, i, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the width of the margin for a bitmap in an existing header control.
' ========================================================================================
FUNCTION Header_SetBitmapMargin (BYVAL hwndHD AS DWORD, BYVAL iWidth AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndHD, %HDM_SETBITMAPMARGIN, iWidth, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the timeout interval between the time a change takes place in the filter
' attributes and the posting of an HDN_FILTERCHANGE notification.
' ========================================================================================
FUNCTION Header_SetFilterChangeTimeout (BYVAL hwndHD AS DWORD, BYVAL i AS LONG) AS LONG
   FUNCTION = SendMessage(hwndHD, %HDM_SETFILTERCHANGETIMEOUT, 0, i)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the focus to a specified item in a header control.
' ========================================================================================
FUNCTION Header_SetFocusedItem (BYVAL hwndHD AS DWORD, BYVAL iItem AS LONG) AS LONG
   FUNCTION = SendMessage(hwndHD, %HDM_SETFOCUSEDITEM, 0, iItem)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Changes the color of a divider between header items to indicate the destination of an
' external drag-and-drop operation.
' ========================================================================================
FUNCTION Header_SetHotDivider (BYVAL hwndHD AS DWORD, BYVAL fPos AS DWORD, BYVAL dwInputValue AS LONG) AS LONG
   FUNCTION = SendMessage(hwndHD, %HDM_SETHOTDIVIDER, fPos, dwInputValue)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Assigns an image list to an existing header control.
' ========================================================================================
FUNCTION Header_SetImageList (BYVAL hwndHD AS DWORD, BYVAL himl AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndHD, %HDM_SETIMAGELIST, 0, himl)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the attributes of the specified item in a header control.
' ========================================================================================
FUNCTION Header_SetItemA (BYVAL hwndHD AS DWORD, BYVAL i AS DWORD, BYREF phdi AS HDITEMA) AS LONG
   FUNCTION = SendMessageA(hwndHD, %HDM_SETITEMA, i, VARPTR(phdi))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Header_SetItemW (BYVAL hwndHD AS DWORD, BYVAL i AS DWORD, BYREF phdi AS HDITEMW) AS LONG
   FUNCTION = SendMessageW(hwndHD, %HDM_SETITEMW, i, VARPTR(phdi))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Header_SetItem = Header_SetItemW
#ELSE
   MACRO Header_SetItem = Header_SetItemA
#ENDIF

' ========================================================================================
' Sets the left-to-right order of header items.
' ========================================================================================
#IF %DEF(%USEPBDECL)
FUNCTION Header_SetOrderArray (BYVAL hwnd AS DWORD, BYVAL iCount AS DWORD, _
    BYVAL lpi AS LONG) AS LONG
    FUNCTION = SendMessage(hwnd, %HDM_SETORDERARRAY, iCount, lpi)
END FUNCTION
#ELSE
FUNCTION Header_SetOrderArray (BYVAL hwndHD AS DWORD, BYVAL iSize AS DWORD, BYREF lpiArray AS LONG) AS LONG
   FUNCTION = SendMessage(hwndHD, %HDM_SETORDERARRAY, iSize, VARPTR(lpiArray))
END FUNCTION
#ENDIF
' ========================================================================================

' ========================================================================================
' Assigns an image list to an existing header control.
' ========================================================================================
FUNCTION Header_SetStateImageList (BYVAL hwndHD AS DWORD, BYVAL himl AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndHD, %HDM_SETIMAGELIST, %HDSIL_STATE, himl)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the UNICODE character format flag for the control. This message allows you to
' change the character set used by the control at run time rather than having to re-create the control.
' ========================================================================================
FUNCTION Header_SetUnicodeFormat (BYVAL hwndHD AS DWORD, BYVAL fUnicode AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndHD, %HDM_SETUNICODEFORMAT, fUnicode, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the text of the specified column.
' Returns TRUE or FALSE.
' ========================================================================================
FUNCTION Header_GetItemTextA (BYVAL hwndHD AS DWORD, BYVAL iItem AS LONG, BYREF pszText AS ASCIIZ, BYVAL cchTextMax AS LONG) AS LONG
   LOCAL hdi AS HDITEMA
   hdi.mask = %HDI_TEXT
   hdi.cchTextMax = cchTextMax
   hdi.pszText = VARPTR(pszText)
   FUNCTION = SendMessageA(hwndHD, %HDM_GETITEMA, iItem, VARPTR(hdi))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Header_GetItemTextW (BYVAL hwndHD AS DWORD, BYVAL iItem AS LONG, BYREF pszText AS WSTRINGZ, BYVAL cchTextMax AS LONG) AS LONG
   LOCAL hdi AS HDITEMW
   hdi.mask = %HDI_TEXT
   hdi.cchTextMax = cchTextMax
   hdi.pszText = VARPTR(pszText)
   FUNCTION = SendMessageW(hwndHD, %HDM_GETITEMW, iItem, VARPTR(hdi))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Header_GetItemText = Header_GetItemTextW
#ELSE
   MACRO Header_GetItemText = Header_GetItemTextA
#ENDIF

' ========================================================================================
' Gets the text of the specified column.
' ========================================================================================
FUNCTION Header_GetTextA (BYVAL hwndHD AS DWORD, BYVAL iCol AS LONG, OPTIONAL BYVAL cchTextMax AS LONG) AS STRING
   LOCAL strText AS STRING
   IF cchTextMax < 1 THEN cchTextMax = %MAX_PATH + 1
   strText = SPACE$(cchTextMax + 1)
   LOCAL hdi AS HDITEMA
   hdi.mask = %HDI_TEXT
   hdi.cchTextMax = cchTextMax + 1
   hdi.pszText = STRPTR(strText)
   IF SendMessageA(hwndHD, %HDM_GETITEMA, iCol, VARPTR(hdi)) THEN FUNCTION = strText
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Header_GetTextW (BYVAL hwndHD AS DWORD, BYVAL iCol AS LONG, OPTIONAL BYVAL cchTextMax AS LONG) AS WSTRING
   LOCAL bstrText AS WSTRING
   IF cchTextMax < 1 THEN cchTextMax = %MAX_PATH + 1
   bstrText = SPACE$(cchTextMax + 1)
   LOCAL hdi AS HDITEMW
   hdi.mask = %HDI_TEXT
   hdi.cchTextMax = cchTextMax + 1
   hdi.pszText = STRPTR(bstrText)
   IF SendMessageW(hwndHD, %HDM_GETITEMW, iCol, VARPTR(hdi)) THEN FUNCTION = bstrText
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Header_GetText = Header_GetTextW
#ELSE
   MACRO Header_GetText = Header_GetTextA
#ENDIF

' ========================================================================================
' Sets the text of the specified item.
' Returns TRUE or FALSE.
' ========================================================================================
FUNCTION Header_SetItemTextA (BYVAL hwndHD AS DWORD, BYVAL iItem AS LONG, BYREF pszText AS ASCIIZ) AS LONG
   LOCAL hdi AS HDITEMA
   hdi.mask = %HDI_TEXT
   hdi.cchTextMax = LEN(pszText)
   hdi.pszText = VARPTR(pszText)
   FUNCTION = SendMessageA(hwndHD, %HDM_SETITEMA, iItem, VARPTR(hdi))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Header_SetItemTextW (BYVAL hwndHD AS DWORD, BYVAL iItem AS LONG, BYREF pszText AS WSTRINGZ) AS LONG
   LOCAL hdi AS HDITEMW
   hdi.mask = %HDI_TEXT
   hdi.cchTextMax = LEN(pszText)
   hdi.pszText = VARPTR(pszText)
   FUNCTION = SendMessageW(hwndHD, %HDM_SETITEMW, iItem, VARPTR(hdi))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Header_SetItemText = Header_SetItemTextW
#ELSE
   MACRO Header_SetItemText = Header_SetItemTextA
#ENDIF

' ========================================================================================
' Sets the text of the specified item.
' Returns TRUE or FALSE.
' ========================================================================================
FUNCTION Header_SetTextA (BYVAL hwndHD AS DWORD, BYVAL iItem AS LONG, BYVAL strText AS STRING) AS LONG
   LOCAL hdi AS HDITEMA
   hdi.mask = %HDI_TEXT
   hdi.cchTextMax = LEN(strText)
   hdi.pszText = STRPTR(strText)
   FUNCTION = SendMessageA(hwndHD, %HDM_SETITEMA, iItem, VARPTR(hdi))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Header_SetTextW (BYVAL hwndHD AS DWORD, BYVAL iItem AS LONG, BYVAL bstrText AS WSTRING) AS LONG
   LOCAL hdi AS HDITEMW
   hdi.mask = %HDI_TEXT
   hdi.cchTextMax = LEN(bstrText)
   hdi.pszText = STRPTR(bstrText)
   FUNCTION = SendMessageW(hwndHD, %HDM_SETITEMW, iItem, VARPTR(hdi))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Header_SetText = Header_SetTextW
#ELSE
   MACRO Header_SetText = Header_SetTextA
#ENDIF

' ========================================================================================
' Gets the width of the specified item of a header control.
' ========================================================================================
FUNCTION Header_GetItemWidthA (BYVAL hwndHD AS DWORD, BYVAL iItem AS LONG) AS LONG
   LOCAL hdi AS HDITEMA
   hdi.mask = %HDI_WIDTH
   IF SendMessageA(hwndHD, %HDM_GETITEMA, iItem, VARPTR(hdi)) THEN FUNCTION = hdi.cxy
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Header_GetItemWidthW (BYVAL hwndHD AS DWORD, BYVAL iItem AS LONG) AS LONG
   LOCAL hdi AS HDITEMW
   hdi.mask = %HDI_WIDTH
   IF SendMessageW(hwndHD, %HDM_GETITEMW, iItem, VARPTR(hdi)) THEN FUNCTION = hdi.cxy
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Header_GetItemWidth = Header_GetItemWidthW
#ELSE
   MACRO Header_GetItemWidth = Header_GetItemWidthA
#ENDIF

' ========================================================================================
' Sets the width of the specified item of a header control.
' ========================================================================================
FUNCTION Header_SetItemWidthA (BYVAL hwndHD AS DWORD, BYVAL iItem AS LONG, BYVAL nWidth AS LONG) AS LONG
   LOCAL hdi AS HDITEMA
   hdi.mask = %HDI_WIDTH
   hdi.cxy = nWidth
   FUNCTION = SendMessageA(hwndHD, %HDM_SETITEMA, iItem, VARPTR(hdi))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Header_SetItemWidthW (BYVAL hwndHD AS DWORD, BYVAL iItem AS LONG, BYVAL nWidth AS LONG) AS LONG
   LOCAL hdi AS HDITEMW
   hdi.mask = %HDI_WIDTH
   hdi.cxy = nWidth
   FUNCTION = SendMessageW(hwndHD, %HDM_SETITEMW, iItem, VARPTR(hdi))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Header_SetItemWidth = Header_SetItemWidthW
#ELSE
   MACRO Header_SetItemWidth = Header_SetItemWidthA
#ENDIF

' ========================================================================================
' Gets the order of the specified item of a header control.
' ========================================================================================
FUNCTION Header_GetItemOrderA (BYVAL hwndHD AS DWORD, BYVAL iItem AS LONG) AS LONG
   LOCAL hdi AS HDITEMA
   hdi.mask = %HDI_ORDER
   IF SendMessageA(hwndHD, %HDM_GETITEMA, iItem, VARPTR(hdi)) THEN FUNCTION = hdi.iOrder
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Header_GetItemOrderW (BYVAL hwndHD AS DWORD, BYVAL iItem AS LONG) AS LONG
   LOCAL hdi AS HDITEMW
   hdi.mask = %HDI_ORDER
   IF SendMessageW(hwndHD, %HDM_GETITEMW, iItem, VARPTR(hdi)) THEN FUNCTION = hdi.iOrder
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Header_GetItemOrder = Header_GetItemOrderW
#ELSE
   MACRO Header_GetItemOrder = Header_GetItemOrderA
#ENDIF

' ========================================================================================
' Sets the order of the specified item of a header control.
' ========================================================================================
FUNCTION Header_SetItemOrderA (BYVAL hwndHD AS DWORD, BYVAL iItem AS LONG, BYVAL iOrder AS LONG) AS LONG
   LOCAL hdi AS HDITEMA
   hdi.mask = %HDI_ORDER
   hdi.iOrder = iOrder
   FUNCTION = SendMessageA(hwndHD, %HDM_SETITEMA, iItem, VARPTR(hdi))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Header_SetItemOrderW (BYVAL hwndHD AS DWORD, BYVAL iItem AS LONG, BYVAL iOrder AS LONG) AS LONG
   LOCAL hdi AS HDITEMW
   hdi.mask = %HDI_ORDER
   hdi.iOrder = iOrder
   FUNCTION = SendMessageW(hwndHD, %HDM_SETITEMW, iItem, VARPTR(hdi))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Header_SetItemOrder = Header_SetItemOrderW
#ELSE
   MACRO Header_SetItemOrder = Header_SetItemOrderA
#ENDIF

' ========================================================================================
' Change the font used by the listview header.
' Examples of Use:
'   hFont = Header_SetFontA(hListView, "MS Sans Serif", 8, %FW_NORMAL, %FALSE, %FALSE, %FALSE, %DEFAULT_CHARSET)
'   hFont = Header_SetFontA(hListView, "Courier New", 10, %FW_BOLD, %FALSE, %FALSE, %FALSE, %DEFAULT_CHARSET)
'   hFont = Header_SetFontA(hListView, "Marlett", 8, %FW_NORMAL, %FALSE, %FALSE, %FALSE, %SYMBOL_CHARSET)
' Note: The returned font must be destroyed with DeleteObject when no longer needed to prevent memory leaks.
' ========================================================================================
FUNCTION Header_SetFontA ( _
   BYVAL hwndHD      AS DWORD, _     ' __in Handle to the header control
   BYVAL strFaceName AS STRING, _    ' __in Typeface name of font
   BYVAL lPointSize  AS LONG, _      ' __in Point size
   BYVAL lWeight     AS LONG, _      ' __in Font weight(bold etc.)
   BYVAL bItalic     AS BYTE, _      ' __in TRUE = italic
   BYVAL bUnderline  AS BYTE, _      ' __in TRUE = underline
   BYVAL bStrikeOut  AS BYTE, _      ' __in TRUE = strikeout
   BYVAL bCharSet    AS BYTE _       ' __in character set
   ) AS DWORD                        ' Handle of font or NULL on failure.

   LOCAL hLvHeaderFont AS DWORD
   LOCAL hCurFont AS DWORD
   LOCAL hOldFont AS DWORD
   LOCAL lf AS LOGFONTA
   LOCAL hDC AS DWORD

   IF hwndHD = 0 THEN EXIT FUNCTION

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
   hOldFont = SelectObject(hwndHD, hLvHeaderFont)
   SendMessageA(hwndHD, %WM_SETFONT, hLvHeaderFont, %TRUE)
   IF hOldFont THEN DeleteObject(hOldFont)
   FUNCTION = hLvHeaderFont

END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Header_SetFontW ( _
   BYVAL hwndHD      AS DWORD, _     ' __in Handle to the header control
   BYVAL strFaceName AS WSTRING, _   ' __in Typeface name of font
   BYVAL lPointSize  AS LONG, _      ' __in Point size
   BYVAL lWeight     AS LONG, _      ' __in Font weight(bold etc.)
   BYVAL bItalic     AS BYTE, _      ' __in TRUE = italic
   BYVAL bUnderline  AS BYTE, _      ' __in TRUE = underline
   BYVAL bStrikeOut  AS BYTE, _      ' __in TRUE = strikeout
   BYVAL bCharSet    AS BYTE _       ' __in character set
   ) AS DWORD                        ' Handle of font or NULL on failure.

   LOCAL hLvHeaderFont AS DWORD
   LOCAL hOldFont AS DWORD
   LOCAL lf AS LOGFONTW
   LOCAL hDC AS DWORD

   IF hwndHD = 0 THEN EXIT FUNCTION

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
   hOldFont = SelectObject(hwndHD, hLvHeaderFont)
   SendMessageW(hwndHD, %WM_SETFONT, hLvHeaderFont, %TRUE)
   IF hOldFont THEN DeleteObject(hOldFont)
   FUNCTION = hLvHeaderFont

END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Header_SetFont = Header_SetFontW
#ELSE
   MACRO Header_SetFont = Header_SetFontA
#ENDIF

' ========================================================================================
' Modifies the font used by the listview header.
' Only the passed values that are not an empty string or zero will be modified.
' Note: The returned font must be destroyed with DeleteObject when no longer needed to prevent memory leaks.
' ========================================================================================
FUNCTION Header_ModifyFontA ( _
   BYVAL hwndHD      AS DWORD, _     ' __in Handle to the header control
   BYVAL strFaceName AS STRING, _         ' __in Typeface name of font
   OPTIONAL BYVAL lPointSize AS LONG, _   ' __in Point size
   BYVAL lWeight     AS LONG, _           ' __in Font weight(bold etc.)
   BYVAL bItalic     AS BYTE, _           ' __in TRUE = italic
   BYVAL bUnderline  AS BYTE, _           ' __in TRUE = underline
   BYVAL bStrikeOut  AS BYTE, _           ' __in TRUE = strikeout
   BYVAL bCharSet    AS BYTE _            ' __in character set
   ) AS DWORD                             ' Handle of font or NULL on failure.

   LOCAL hLvHeaderFont AS DWORD
   LOCAL hCurFont AS DWORD
   LOCAL hOldFont AS DWORD
   LOCAL lf AS LOGFONTA
   LOCAL hDC AS DWORD

   IF hwndHD = 0 THEN EXIT FUNCTION

   ' // Get the handle of the font used by the header
   hCurFont = SendMessageA(hwndHD, %WM_GETFONT, 0, 0)
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
   IF strFaceName <> "" THEN lf.lfFaceName = strFaceName

   ' // Create the font
   hLvHeaderFont = CreateFontIndirectA(lf)
   IF hLvHeaderFont = 0 THEN EXIT FUNCTION

   ' // Select the font
   hOldFont = SelectObject(hwndHD, hLvHeaderFont)
   SendMessageA(hwndHD, %WM_SETFONT, hLvHeaderFont, %TRUE)
   IF hOldFont THEN DeleteObject(hOldFont)
   FUNCTION = hLvHeaderFont

END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Header_ModifyFontW ( _
   BYVAL hwndHD      AS DWORD, _     ' __in Handle to the header control
   BYVAL strFaceName AS STRING, _         ' __in Typeface name of font
   OPTIONAL BYVAL lPointSize AS LONG, _   ' __in Point size
   BYVAL lWeight     AS LONG, _           ' __in Font weight(bold etc.)
   BYVAL bItalic     AS BYTE, _           ' __in TRUE = italic
   BYVAL bUnderline  AS BYTE, _           ' __in TRUE = underline
   BYVAL bStrikeOut  AS BYTE, _           ' __in TRUE = strikeout
   BYVAL bCharSet    AS BYTE _            ' __in character set
   ) AS DWORD                             ' Handle of font or NULL on failure.

   LOCAL hLvHeaderFont AS DWORD
   LOCAL hCurFont AS DWORD
   LOCAL hOldFont AS DWORD
   LOCAL lf AS LOGFONTW
   LOCAL hDC AS DWORD

   IF hwndHD = 0 THEN EXIT FUNCTION

   ' // Get the handle of the font used by the header
   hCurFont = SendMessageW(hwndHD, %WM_GETFONT, 0, 0)
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
   hOldFont = SelectObject(hwndHD, hLvHeaderFont)
   SendMessageW(hwndHD, %WM_SETFONT, hLvHeaderFont, %TRUE)
   IF hOldFont THEN DeleteObject(hOldFont)
   FUNCTION = hLvHeaderFont

END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Header_ModifyFont = Header_ModifyFontW
#ELSE
   MACRO Header_ModifyFont = Header_ModifyFontA
#ENDIF
