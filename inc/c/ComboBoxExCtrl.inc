' ########################################################################################
' Microsoft Windows
' File: ComboBoxExCtrl.inc
' Contents: ComboBoxEx Control Wrapper Functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%COMBOBOXEXCTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"

' ========================================================================================
' Removes an item from a ComboBoxEx control.
' ========================================================================================
FUNCTION ComboBoxEx_DeleteItem (BYVAL hComboboxEx AS DWORD, BYVAL iIndex AS DWORD) AS LONG
   FUNCTION = SendMessage (hComboboxEx, %CBEM_DELETEITEM, iIndex, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the handle to the child combo box control.
' ========================================================================================
FUNCTION ComboBoxEx_GetComboControl (BYVAL hComboBoxEx AS DWORD) AS DWORD
   FUNCTION = SendMessage (hComboBoxEx, %CBEM_GETCOMBOCONTROL, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the handle to the edit control portion of a ComboBoxEx control. A ComboBoxEx
' control uses an edit box when it is set to the CBS_DROPDOWN style.
' ========================================================================================
FUNCTION ComboBoxEx_GetEditControl (BYVAL hComboBoxEx AS DWORD) AS DWORD
   FUNCTION = SendMessage (hComboBoxEx, %CBEM_GETEDITCONTROL, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the extended styles that are in use for a ComboBoxEx control.
' ========================================================================================
FUNCTION ComboBoxEx_GetExtendedStyle (BYVAL hComboBoxEx AS DWORD) AS DWORD
   FUNCTION = SendMessage (hComboBoxEx, %CBEM_GETEXTENDEDSTYLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the handle to an image list assigned to a ComboBoxEx control.
' ========================================================================================
FUNCTION ComboBoxEx_GetImageList (BYVAL hComboBoxEx AS DWORD) AS DWORD
   FUNCTION = SendMessage (hComboBoxEx, %CBEM_GETIMAGELIST, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves item information for a given ComboBoxEx item.
' ========================================================================================
FUNCTION ComboBoxEx_GetItem (BYVAL hComboBoxEx AS DWORD, BYREF pCBItem AS COMBOBOXEXITEM) AS LONG
   FUNCTION = SendMessage (hComboBoxEx, %CBEM_GETITEM, 0, VARPTR(pCBItem))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the UNICODE character format flag for the control.
' ========================================================================================
FUNCTION ComboBoxEx_GetUnicodeFormat (BYVAL hComboBoxEx AS DWORD) AS LONG
   FUNCTION = SendMessage (hComboBoxEx, %CBEM_GETUNICODEFORMAT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether or not the user has changed the text of a ComboBoxEx edit control.
' ========================================================================================
FUNCTION ComboBoxEx_HasEditChanged (BYVAL hComboBoxEx AS DWORD) AS LONG
   FUNCTION = SendMessage (hComboBoxEx, %CBEM_HASEDITCHANGED, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Inserts a new item in a ComboBoxEx control.
' ========================================================================================
FUNCTION ComboBoxEx_InsertItem (BYVAL hComboBoxEx AS DWORD, BYREF lpCBItem AS COMBOBOXEXITEM) AS LONG
   FUNCTION = SendMessage(hComboBoxEx, %CBEM_INSERTITEM, 0, VARPTR(lpCBItem))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets extended styles within a ComboBoxEx control.
' ========================================================================================
FUNCTION ComboBoxEx_SetExtendedStyle (BYVAL hComboBoxEx AS DWORD, BYVAL dwMask AS DWORD, BYVAL dwExStyle AS DWORD) AS DWORD
   FUNCTION = SendMessage (hComboBoxEx, %CBEM_SETEXTENDEDSTYLE, dwMask, dwExStyle)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets an image list for a ComboBoxEx control.
' ========================================================================================
FUNCTION ComboBoxEx_SetImageList (BYVAL hComboBoxEx AS DWORD, BYVAL himl AS DWORD) AS DWORD
   FUNCTION = SendMessage (hComboBoxEx, %CBEM_SETIMAGELIST, 0, himl)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the attributes for an item in a ComboBoxEx control.
' ========================================================================================
FUNCTION ComboBoxEx_SetItem (BYVAL hComboBoxEx AS DWORD, BYREF lpCBItem AS COMBOBOXEXITEM) AS LONG
   FUNCTION = SendMessage (hComboBoxEx, %CBEM_SETITEM, 0, VARPTR(lpCBItem))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the UNICODE character format flag for the control. This message enables you to
' change the character set used by the control at run time rather than having to re-create
' the control.
' ========================================================================================
FUNCTION ComboBoxEx_SetUnicodeFormat (BYVAL hComboBoxEx AS DWORD, BYVAL fUnicode AS DWORD) AS LONG
   FUNCTION = SendMessage (hComboBoxEx, %CBEM_SETUNICODEFORMAT, fUnicode, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the visual style of a ComboboxEx control.
' ========================================================================================
SUB ComboBoxEx_SetWindowTheme (BYVAL hComboBoxEx AS DWORD, BYREF wszStyle AS WSTRINGZ)
   SendMessage hComboBoxEx, %CBEM_SETWINDOWTHEME, 0, VARPTR(wszStyle)
END SUB
' ========================================================================================
