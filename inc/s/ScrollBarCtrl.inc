' ########################################################################################
' Microsoft Windows
' File: ScrollbarCtrl.inc
' Contents: Scrollbar Control Wrapper Functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SCROLLBARCTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"

' ========================================================================================
' Enables or disables one or both scroll bar arrows.
' ========================================================================================
FUNCTION ScrollBar_Enable (BYVAL hScrollBar AS DWORD, BYVAL wSBflags AS DWORD) AS LONG
   FUNCTION = EnableScrollBar(hScrollBar, %SB_CTL, wSBflags)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current position of the scroll box of a scroll bar control.
' ========================================================================================
FUNCTION ScrollBar_GetPos (BYVAL hScrollBar AS DWORD) AS LONG
   FUNCTION = GetScrollPos(hScrollBar, %SB_CTL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the minimum and maximum position values for the scroll bar control.
' ========================================================================================
FUNCTION ScrollBar_GetRange (BYVAL hScrollBar AS DWORD, BYREF lpposMin AS LONG, BYREF lpposMax AS LONG) AS LONG
   FUNCTION = GetScrollRange(hScrollBar, %SB_CTL, lpposMin, lpposMax)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Positions the scroll box (thumb) and, if requested, redraws the scroll bar to reflect
' the new position of the scroll box.
' ========================================================================================
FUNCTION ScrollBar_SetPos (BYVAL hScrollBar AS DWORD, BYVAL nPos AS LONG, BYVAL fRedraw AS LONG) AS LONG
   FUNCTION = SetScrollPos(hScrollBar, %SB_CTL, nPos, fRedraw)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the minimum and maximum position values for the scroll bar control.
' ========================================================================================
FUNCTION ScrollBar_SetRange (BYVAL hScrollBar AS DWORD, BYVAL posMin AS LONG, BYVAL posMax AS LONG, BYVAL fRedraw AS LONG) AS LONG
   FUNCTION = SetScrollRange(hScrollBar, %SB_CTL, posMin, posMax, fRedraw)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the minimum and maximum position values and redraws the control.
' ========================================================================================
FUNCTION ScrollBar_SetRangeRedraw (BYVAL hScrollBar AS DWORD, BYVAL posMin AS LONG, BYVAL posMax AS LONG) AS LONG
   FUNCTION = SendMessage(hScrollBar, %SBM_SETRANGEREDRAW, posMin, posMax)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Shows or hides a scroll bar control.
' ========================================================================================
FUNCTION ScrollBar_Show (BYVAL hScrollBar AS DWORD, BYVAL fShow AS LONG) AS LONG
   FUNCTION = ShowWindow(hScrollBar, IIF&(fShow > 0, %SW_SHOWNORMAL, %SW_HIDE))
END FUNCTION
' ========================================================================================
