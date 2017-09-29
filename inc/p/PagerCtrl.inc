' ########################################################################################
' Microsoft Windows
' File: PagerCtrl.inc
' Contents: Pager Control Wrapper Functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PAGERCTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"
#INCLUDE ONCE "oleidl.inc"

' ========================================================================================
' Enables or disables mouse forwarding for the pager control. When mouse forwarding is
' enabled, the pager control forwards WM_MOUSEMOVE messages to the contained window.
' ========================================================================================
SUB Pager_ForwardMouse (BYVAL hwndPager AS DWORD, BYVAL bForward AS LONG)
   SendMessage hwndPager, %PGM_FORWARDMOUSE, bForward, 0
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the current background color for the pager control.
' ========================================================================================
FUNCTION Pager_GetBkColor (BYVAL hwndPager AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndPager, %PGM_GETBKCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current border size for the pager control.
' ========================================================================================
FUNCTION Pager_GetBorder (BYVAL hwndPager AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndPager, %PGM_GETBORDER, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current button size for the pager control.
' ========================================================================================
FUNCTION Pager_GetButtonSize (BYVAL hwndPager AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndPager, %PGM_GETBUTTONSIZE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the state of the specified button in a pager control.
' ========================================================================================
FUNCTION Pager_GetButtonState (BYVAL hwndPager AS DWORD, BYVAL iButton AS LONG) AS DWORD
   FUNCTION = SendMessage(hwndPager, %PGM_GETBUTTONSTATE, 0, iButton)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a pager control's IDropTarget interface pointer.
' ========================================================================================
#IF %DEF(%USEPBDECL)
SUB Pager_GetDropTarget (BYVAL hwnd AS DWORD, ppdt AS DWORD)
    SendMessage hwnd, %PGM_GETDROPTARGET, 0, VARPTR(ppdt)
END SUB
#ELSE
SUB Pager_GetDropTarget (BYVAL hwndPager AS DWORD, BYREF ppDropTarget AS IDropTarget)
   SendMessage hwndPager, %PGM_GETDROPTARGET, 0, VARPTR(ppDropTarget)
END SUB
#ENDIF
' ========================================================================================

' ========================================================================================
' Retrieves the current scroll position of the pager control.
' ========================================================================================
FUNCTION Pager_GetPos (BYVAL hwndPager AS DWORD) AS LONG
   FUNCTION = SendMessage(hwndPager, %PGM_GETPOS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Forces the pager control to recalculate the size of the contained window. Using this
' macro will result in a PGN_CALCSIZE notification being sent.
' ========================================================================================
SUB Pager_RecalcSize (BYVAL hwndPager AS DWORD)
   SendMessage hwndPager, %PGM_RECALCSIZE, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the current background color for the pager control.
' ========================================================================================
FUNCTION Pager_SetBkColor (BYVAL hwndPager AS DWORD, BYVAL clrBk AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwndPager, %PGM_SETBKCOLOR, 0, clrBk)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the current border size for the pager control.
' ========================================================================================
FUNCTION Pager_SetBorder (BYVAL hwndPager AS DWORD, BYVAL iBorder AS LONG) AS LONG
   FUNCTION = SendMessage(hwndPager, %PGM_SETBORDER, 0, iBorder)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the current button size for the pager control.
' ========================================================================================
FUNCTION Pager_SetButtonSize (BYVAL hwndPager AS DWORD, BYVAL iButtonSize AS LONG) AS LONG
   FUNCTION = SendMessage(hwndPager, %PGM_SETBUTTONSIZE, 0, iButtonSize)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the contained window for the pager control. This macro will not change the parent
' of the contained window; it only assigns a window handle to the pager control for
' scrolling. In most cases, the contained window will be a child window. If this is the
' case, the contained window should be a child of the pager control.
' ========================================================================================
SUB Pager_SetChild (BYVAL hwndPager AS DWORD, BYVAL hwndChild AS DWORD)
   SendMessage hwndPager, %PGM_SETCHILD, 0, hwndChild
END SUB
' ========================================================================================

' ========================================================================================
' Sets the scroll position for the pager control.
' ========================================================================================
FUNCTION Pager_SetPos (BYVAL hwndPager AS DWORD, BYVAL iPos AS LONG) AS LONG
   FUNCTION = SendMessage(hwndPager, %PGM_SETPOS, 0, iPos)
END FUNCTION
' ========================================================================================
