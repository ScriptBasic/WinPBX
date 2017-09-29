' ########################################################################################
' Microsoft Windows
' File: ButtonCtrl.inc
' Contents: Button Control Wrapper Functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%BUTTONCTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"

' ========================================================================================
' Simulates the user clicking a button.
' ========================================================================================
SUB Button_Click (BYVAL hButton AS DWORD)
   SendMessage hButton, %BM_CLICK, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Enables or disables a button.
' ========================================================================================
FUNCTION Button_Enable (BYVAL hButton AS DWORD, BYVAL fEnable AS LONG) AS LONG
   FUNCTION = EnableWindow(hButton, fEnable)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the check state of a radio button or check box.
' ========================================================================================
FUNCTION Button_GetCheck (BYVAL hButton AS DWORD) AS LONG
   FUNCTION = SendMessage(hButton, %BM_GETCHECK, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the size of the button that best fits the text and image, if an image list is present.
' ========================================================================================
FUNCTION Button_GetIdealSize (BYVAL hButton AS DWORD, BYREF psize AS SIZE) AS LONG
   FUNCTION = SendMessage(hButton, %BCM_GETIDEALSIZE, 0, VARPTR(psize))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a handle to the image (icon or bitmap) associated with the button.
' ========================================================================================
FUNCTION Button_GetImage (BYVAL hButton AS DWORD) AS LONG
   FUNCTION = SendMessage(hButton, %BM_GETIMAGE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the BUTTON_IMAGELIST structure that describes the image list that is set for a
' button control.
' ========================================================================================
FUNCTION Button_GetImageList (BYVAL hButton AS DWORD, BYREF pbuttonImagelist AS BUTTON_IMAGELIST) AS LONG
   FUNCTION = SendMessage(hButton, %BCM_GETIMAGELIST, 0, VARPTR(pbuttonImagelist))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the text of the note associated with the Command Link button.
' ========================================================================================
#IF %DEF(%USEPBDECL)
FUNCTION Button_GetNote (BYVAL hwnd AS DWORD, psz AS WSTRINGZ, _
    BYVAL pcc AS LONG) AS LONG
    FUNCTION = SendMessage(hwnd, %BCM_GETNOTE, pcc, VARPTR(psz))
END FUNCTION
#ELSE
FUNCTION Button_GetNote (BYVAL hButton AS DWORD, BYREF psz AS WSTRINGZ, BYREF pcc AS DWORD) AS LONG
   FUNCTION = SendMessage(hButton, %BCM_GETNOTE, VARPTR(pcc), VARPTR(psz))
END FUNCTION
#ENDIF
' ========================================================================================

' ========================================================================================
' Gets the length of the note text that may be displayed in the description for a command link.
' ========================================================================================
FUNCTION Button_GetNoteLength (BYVAL hButton AS DWORD) AS LONG
   FUNCTION = SendMessage(hButton, %BCM_GETNOTELENGTH, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets information for a specified split button control.
' ========================================================================================
FUNCTION Button_GetSplitInfo (BYVAL hButton AS DWORD, BYREF pInfo AS BUTTON_SPLITINFO) AS LONG
   FUNCTION = SendMessage(hButton, %BCM_GETSPLITINFO, 0, VARPTR(pInfo))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines the state of a button or check box.
' ========================================================================================
FUNCTION Button_GetState (BYVAL hButton AS DWORD) AS LONG
   FUNCTION = SendMessage(hButton, %BM_GETSTATE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the text of a button control.
' Note: GetWindowText cannot retrieve the text of a control in another application.
' ========================================================================================
'FUNCTION Button_GetText (BYVAL hButton AS DWORD) AS STRING
'   LOCAL nLen   AS LONG
'   LOCAL buffer AS STRING
'   nLen = GetWindowTextLength(hButton)
'   buffer = SPACE$(nLen + 1)
'   GetWindowText hButton, BYVAL STRPTR(buffer), nLen + 1
'   FUNCTION = LEFT$(buffer, nLen)
'END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Button_GetTextA (BYVAL hButton AS LONG) AS STRING
   LOCAL nLen   AS LONG
   LOCAL buffer AS STRING
   nLen = SendMessageA(hButton, %WM_GETTEXTLENGTH, 0, 0)
   Buffer = SPACE$(nLen + 1)
   nLen = SendMessageA(hButton, %WM_GETTEXT, nLen + 1, BYVAL STRPTR(Buffer))
   FUNCTION = LEFT$(Buffer, nLen)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Button_GetTextW (BYVAL hButton AS LONG) AS WSTRING
   LOCAL nLen   AS LONG
   LOCAL buffer AS WSTRING
   nLen = SendMessageW(hButton, %WM_GETTEXTLENGTH, 0, 0)
   Buffer = SPACE$(nLen + 1)
   nLen = SendMessageW(hButton, %WM_GETTEXT, nLen + 1, BYVAL STRPTR(Buffer))
   FUNCTION = LEFT$(Buffer, nLen)
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Button_GetText = Button_GetTextW
#ELSE
   MACRO Button_GetText = Button_GetTextA
#ENDIF

' ========================================================================================
' Gets the length of the text of a button control.
' ========================================================================================
'FUNCTION Button_GetTextLength (BYVAL hButton AS DWORD) AS LONG
'   FUNCTION = GetWindowTextLength(hButton)
'END FUNCTION
' ========================================================================================
FUNCTION Button_GetTextLength (BYVAL hButton AS DWORD) AS LONG
   FUNCTION = SendMessage(hButton, %WM_GETTEXTLENGTH, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the margins used to draw text in a button control.
' ========================================================================================
FUNCTION Button_GetTextMargin (BYVAL hButton AS DWORD, BYREF pmargin AS RECT) AS LONG
   FUNCTION = SendMessage(hButton, %BCM_GETTEXTMARGIN, 0, VARPTR(pmargin))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the check state of a radio button or check box.
' ========================================================================================
SUB Button_SetCheck (BYVAL hButton AS DWORD, BYVAL checkState AS DWORD)
   SendMessage hButton, %BM_SETCHECK, checkState, 0
END SUB
' ========================================================================================
' ========================================================================================
' Sets the button state to checked.
' ========================================================================================
SUB Button_Check (BYVAL hButton AS DWORD)
   SendMessage hButton, %BM_SETCHECK, %BST_CHECKED, 0
END SUB
' ========================================================================================
' ========================================================================================
' Sets the button state to cleared.
' ========================================================================================
SUB Button_Uncheck (BYVAL hButton AS DWORD)
   SendMessage hButton, %BM_SETCHECK, %BST_UNCHECKED, 0
END SUB
' ========================================================================================
' ========================================================================================
' Sets the button state to grayed, indicating an indeterminate state. Use this value only
' if the button has the BS_3STATE or BS_AUTO3STATE style.
' ========================================================================================
SUB Button_Gray (BYVAL hButton AS DWORD)
   SendMessage hButton, %BM_SETCHECK, %BST_INDETERMINATE, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets a flag on a radio button that controls the generation of BN_CLICKED messages when
' the button receives focus.
' ========================================================================================
SUB Button_SetDontClick (BYVAL hButton AS DWORD, BYVAL bState AS LONG)
   SendMessage hButton, %BM_SETDONTCLICK, bState, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the drop down state for a specified button with style of BS_SPLITBUTTON.
' ========================================================================================
FUNCTION Button_SetDropDownState (BYVAL hButton AS DWORD, BYVAL fDropDown AS DWORD) AS LONG
   FUNCTION = SendMessage(hButton, %BCM_SETDROPDOWNSTATE, fDropDown, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the elevation required state for a specified button or command link to display an
' elevated icon.
' ========================================================================================
FUNCTION Button_SetElevationRequiredState (BYVAL hButton AS DWORD, BYVAL fRequired AS LONG) AS LONG
   FUNCTION = SendMessage(hButton, %BCM_SETSHIELD, 0, fRequired)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Associates a new bitmap with a button.
' ========================================================================================
FUNCTION Button_SetBitmap (BYVAL hButton AS DWORD, BYVAL hBitmap AS DWORD) AS LONG
   FUNCTION = SendMessage(hButton, %BM_SETIMAGE, %IMAGE_BITMAP, hBitmap)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Associates a new icon with a button.
' ========================================================================================
FUNCTION Button_SetIcon (BYVAL hButton AS DWORD, BYVAL hIcon AS DWORD) AS LONG
   FUNCTION = SendMessage(hButton, %BM_SETIMAGE, %IMAGE_ICON, hIcon)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Associate a new image (icon or bitmap) with the button.
' ========================================================================================
FUNCTION Button_SetImage (BYVAL hButton AS DWORD, BYVAL ImageType AS DWORD, BYVAL hImage AS DWORD) AS LONG
   FUNCTION = SendMessage(hButton, %BM_SETIMAGE, ImageType, hImage)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Assigns an image list to a button control.
' ========================================================================================
FUNCTION Button_SetImageList (BYVAL hButton AS DWORD, BYREF pbuttonImagelist AS BUTTON_IMAGELIST) AS LONG
   FUNCTION = SendMessage(hButton, %BCM_SETIMAGELIST, 0, VARPTR(pbuttonImagelist))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Assigns an image list to a button control. Requires Windows XP or superior.
' Parameters:
' - hButon     = The handle of the button.
' - hImageList =
' - nLeft      = The x-coordinate of the upper-left corner of the rectangle for the image.
' - nTop       = The y-coordinate of the upper-left corner of the rectangle for the image.
' - nRight     = The x-coordinate of the lower-right corner of the rectangle for the image.
' - nBottom    = The y-coordinate of the lower-right corner of the rectangle for the image.
' - uAlign     = The alignment to use. This parameter can be one of the following values:
'                BUTTON_IMAGELIST_ALIGN_LEFT   Align the image with the left margin.
'                BUTTON_IMAGELIST_ALIGN_RIGHT  Align the image with the right margin
'                BUTTON_IMAGELIST_ALIGN_TOP    Align the image with the top margin
'                BUTTON_IMAGELIST_ALIGN_BOTTOM Align the image with the bottom margin
'                BUTTON_IMAGELIST_ALIGN_CENTER Center the image.
'                The default value is BUTTON_IMAGELIST_ALIGN_LEFT.
' Return value:  If the function succeeds, it returns TRUE. Otherwise it returns FALSE.
' Note:  To use this application programming interface (API), you must provide a manifest
' specifying Comclt32.dll version 6.0.
' ========================================================================================
FUNCTION Button_SetImageListXY (BYVAL hButton AS DWORD, BYVAL hImageList AS DWORD, BYVAL nLeft AS LONG, BYVAL nTop AS LONG, BYVAL nRight AS LONG, BYVAL nBottom AS LONG, OPTIONAL BYVAL uALign AS DWORD) AS LONG
   LOCAL bi AS BUTTON_IMAGELIST
   bi.himl = hImageList : bi.margin.nLeft = nLeft : bi.margin.nTop = nTop
   bi.margin.nRight = nRight : bi.margin.nBottom = nBottom : bi.uAlign = uAlign
   FUNCTION = SendMessage(hButton, %BCM_SETIMAGELIST, 0, VARPTR(bi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes a bitmap associated with a button.
' ========================================================================================
FUNCTION Button_DeleteBitmap (BYVAL hButton AS DWORD) AS LONG
   FUNCTION = DeleteObject(SendMessage(hButton, %BM_SETIMAGE, %IMAGE_BITMAP, %NULL))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes an icon associated with a button.
' ========================================================================================
FUNCTION Button_DeleteIcon (BYVAL hButton AS DWORD) AS LONG
   FUNCTION = DeleteObject(SendMessage(hButton, %BM_SETIMAGE, %IMAGE_ICON, %NULL))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes an image (icon or bitmap) associated a button.
' ========================================================================================
FUNCTION Button_DeleteImage (BYVAL hButton AS DWORD, BYVAL ImageType AS DWORD) AS LONG
   FUNCTION = DeleteObject(SendMessage(hButton, %BM_SETIMAGE, ImageType, %NULL))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the text of the note associated with a specified Command Link button.
' ========================================================================================
FUNCTION Button_SetNote (BYVAL hButton AS DWORD, BYREF psz AS WSTRINGZ) AS LONG
   FUNCTION = SendMessage(hButton, %BCM_SETNOTE, 0, VARPTR(psz))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets information for a specified split button control.
' ========================================================================================
FUNCTION Button_SetSplitInfo (BYVAL hButton AS DWORD, BYREF pInfo AS BUTTON_SPLITINFO) AS LONG
   FUNCTION = SendMessage(hButton, %BCM_SETSPLITINFO, 0, VARPTR(pInfo))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Changes the highlight state of a button. The highlight state indicates whether the
' button is highlighted as if the user had pushed it.
' ========================================================================================
FUNCTION Button_SetState (BYVAL hButton AS DWORD, BYVAL bState AS LONG) AS LONG
   FUNCTION = SendMessage(hButton, %BM_SETSTATE, ISTRUE(bState) AND 1, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Changes the style of a button.
' ========================================================================================
SUB Button_SetStyle (BYVAL hButton AS DWORD, BYVAL dwStyle AS DWORD, BYVAL fRedraw AS LONG)
   SendMessage hButton, %BM_SETSTYLE, dwStyle, ISTRUE(fRedraw) AND 1
END SUB
' ========================================================================================

' ========================================================================================
' Sets the text of a button.
' Note: SetWindowText cannot change the text of a control in another application.
' ========================================================================================
'SUB Button_SetText (BYVAL hButton AS DWORD, BYVAL strText AS STRING)
'   SetWindowText hButton, BYCOPY strText
'END SUB
' ========================================================================================
FUNCTION Button_SetTextA (BYVAL hButton AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hButton, %WM_SETTEXT, 0, STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Button_SetTextW (BYVAL hButton AS DWORD, BYVAL bstrText AS WSTRING) AS LONG
   FUNCTION = SendMessageW(hButton, %WM_SETTEXT, 0, STRPTR(bstrText))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Button_SetText = Button_SetTextW
#ELSE
   MACRO Button_SetText = Button_SetTextA
#ENDIF

' ========================================================================================
' Sets the text of a button using UTF8 encoded strings.
' ========================================================================================
FUNCTION Button_SetUtf8Text (BYVAL hButton AS DWORD, BYVAL strUtf8Text AS STRING) AS LONG
   LOCAL bstrText AS WSTRING
   bstrText = UTF8TOCHR$(strUtf8Text)
   FUNCTION = SendMessageW(hButton, %WM_SETTEXT, 0, STRPTR(bstrText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the margins for drawing text in a button control.
' ========================================================================================
FUNCTION Button_SetTextMargin (BYVAL hButton AS DWORD, BYREF pmargin AS RECT) AS LONG
   FUNCTION = SendMessage(hButton, %BCM_SETTEXTMARGIN, 0, VARPTR(pmargin))
END FUNCTION
' ========================================================================================
