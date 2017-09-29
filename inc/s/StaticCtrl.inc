' ########################################################################################
' Microsoft Windows
' File: StaticCtrl.inc
' Contents: Static Control Wrapper Functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%STATICCTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"

' ========================================================================================
' Enables or disables a static control.
' ========================================================================================
FUNCTION Static_Enable (BYVAL hStatic AS DWORD, BYVAL fEnable AS LONG) AS LONG
   FUNCTION = EnableWindow(hStatic, fEnable)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a handle to the icon associated with a static control that has the SS_ICON style.
' ========================================================================================
FUNCTION Static_GetIcon (BYVAL hStatic AS DWORD) AS DWORD
   FUNCTION = SendMessage(hStatic, %STM_GETICON, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a handle to the image (icon or bitmap) associated with a static control.
' ========================================================================================
FUNCTION Static_GetImage (BYVAL hStatic AS DWORD, BYVAL nType AS LONG) AS DWORD
   FUNCTION = SendMessage (hStatic, %STM_GETIMAGE, nType, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the text of a static control.
' Note: GetWindowText cannot retrieve the text of a control in another application.
' ========================================================================================
'FUNCTION Static_GetText (BYVAL hStatic AS LONG) AS STRING
'   LOCAL nLen   AS LONG
'   LOCAL buffer AS STRING
'   nLen = GetWindowTextLength(hStatic)
'   Buffer = SPACE$(nLen + 1)
'   GetWindowText hStatic, BYVAL STRPTR(Buffer), nLen + 1
'   FUNCTION = LEFT$(Buffer, nLen)
'END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Static_GetTextA (BYVAL hStatic AS LONG) AS STRING
   LOCAL nLen   AS LONG
   LOCAL buffer AS STRING
   nLen = SendMessageA(hStatic, %WM_GETTEXTLENGTH, 0, 0)
   Buffer = SPACE$(nLen + 1)
   nLen = SendMessage(hStatic, %WM_GETTEXT, nLen + 1, BYVAL STRPTR(Buffer))
   FUNCTION = LEFT$(Buffer, nLen)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Static_GetTextW (BYVAL hStatic AS LONG) AS WSTRING
   LOCAL nLen   AS LONG
   LOCAL buffer AS WSTRING
   nLen = SendMessageW(hStatic, %WM_GETTEXTLENGTH, 0, 0)
   Buffer = SPACE$(nLen + 1)
   nLen = SendMessageW(hStatic, %WM_GETTEXT, nLen + 1, BYVAL STRPTR(Buffer))
   FUNCTION = LEFT$(Buffer, nLen)
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Static_GetText = Static_GetTextW
#ELSE
   MACRO Static_GetText = Static_GetTextA
#ENDIF

' ========================================================================================
' Gets the length of the text of a static control.
' ========================================================================================
'FUNCTION Static_GetTextLength (BYVAL hStatic AS DWORD) AS LONG
'   FUNCTION = GetWindowTextLength(hStatic)
'END FUNCTION
' ========================================================================================
FUNCTION Static_GetTextLength (BYVAL hStatic AS DWORD) AS LONG
   FUNCTION = SendMessage(hStatic, %WM_GETTEXTLENGTH, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Associates an icon with an static control.
' ========================================================================================
FUNCTION Static_SetIcon (BYVAL hStatic AS DWORD, BYVAL hIcon AS DWORD) AS DWORD
   FUNCTION = SendMessage (hStatic, %STM_SETICON, hIcon, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes an icon associated with an static control.
' ========================================================================================
FUNCTION Static_DeleteIcon (BYVAL hStatic AS DWORD) AS LONG
   FUNCTION = DeleteObject(SendMessage(hStatic, %STM_SETICON, 0, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Associates a bitmap with an static control.
' ========================================================================================
FUNCTION Static_SetBitmap (BYVAL hStatic AS DWORD, BYVAL hBitmap AS DWORD) AS DWORD
   FUNCTION = SendMessage (hStatic, %STM_SETIMAGE, %IMAGE_BITMAP, hBitmap)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes a bitmap associated with an static control.
' ========================================================================================
FUNCTION Static_DeleteBitmap (BYVAL hStatic AS DWORD) AS LONG
   FUNCTION = DeleteObject(SendMessage(hStatic, %STM_SETIMAGE, %IMAGE_BITMAP, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Associates a cursor with an static control.
' ========================================================================================
FUNCTION Static_SetCursor (BYVAL hStatic AS DWORD, BYVAL hCursor AS DWORD) AS DWORD
   FUNCTION = SendMessage (hStatic, %STM_SETIMAGE, %IMAGE_CURSOR, hCursor)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes a cursor associated with an static control.
' ========================================================================================
FUNCTION Static_DeleteCursor (BYVAL hStatic AS DWORD) AS LONG
   FUNCTION = DeleteObject(SendMessage(hStatic, %STM_SETIMAGE, %IMAGE_CURSOR, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Associates an enhanced metafil with an static control.
' ========================================================================================
FUNCTION Static_SetEnhancedMetafile (BYVAL hStatic AS DWORD, BYVAL hEnhMetafile AS DWORD) AS DWORD
   FUNCTION = SendMessage (hStatic, %STM_SETIMAGE, %IMAGE_ENHMETAFILE, hEnhMetafile)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes a cursor associated with an static control.
' ========================================================================================
FUNCTION Static_DeleteEnhancedMetafile (BYVAL hStatic AS DWORD) AS LONG
   FUNCTION = DeleteObject(SendMessage(hStatic, %STM_SETIMAGE, %IMAGE_ENHMETAFILE, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Associates a new image with a static control.
' ========================================================================================
FUNCTION Static_SetImage (BYVAL hStatic AS DWORD, BYVAL nType AS LONG, BYVAL hImage AS DWORD) AS DWORD
   FUNCTION = SendMessage(hStatic, %STM_SETIMAGE, nType, hImage)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes an image associated with an static control.
' ========================================================================================
FUNCTION Static_DeleteImage (BYVAL hStatic AS DWORD, BYVAL nType AS LONG) AS LONG
   FUNCTION = DeleteObject(SendMessage(hStatic, %STM_SETIMAGE, nType, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the text of a static control.
' Note: SetWindowText cannot change the text of a control in another application.
' ========================================================================================
'FUNCTION Static_SetText (BYVAL hStatic AS DWORD, BYVAL strText AS STRING) AS LONG
'   FUNCTION = SetWindowText(hStatic, BYVAL STRPTR(strText))
'END FUNCTION
' ========================================================================================
FUNCTION Static_SetTextA (BYVAL hStatic AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hStatic, %WM_SETTEXT, 0, STRPTR(strText))
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION Static_SetTextW (BYVAL hStatic AS DWORD, BYVAL bstrText AS WSTRING) AS LONG
   FUNCTION = SendMessageW(hStatic, %WM_SETTEXT, 0, STRPTR(bstrText))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO Static_SetText = Static_SetTextW
#ELSE
   MACRO Static_SetText = Static_SetTextA
#ENDIF

' ========================================================================================
' Sets the text using UTF8 encoded strings.
' ========================================================================================
FUNCTION Static_SetUtf8Text (BYVAL hStatic AS DWORD, BYVAL strUtf8Text AS STRING) AS LONG
   LOCAL bstrText AS WSTRING
   bstrText = UTF8TOCHR$(strUtf8Text)
   FUNCTION = SendMessageW(hStatic, %WM_SETTEXT, 0, STRPTR(bstrText))
END FUNCTION
' ========================================================================================
