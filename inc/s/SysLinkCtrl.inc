' ########################################################################################
' Microsoft Windows
' File: SysLinkCtrl.inc
' Contents: SysLink Control Wrapper Functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SYSLINKCTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"

' ========================================================================================
' Retrieves the preferred height of a link for the control's current width.
' ========================================================================================
FUNCTION SysLink_GetIdealHeight (BYVAL hLM AS DWORD) AS LONG
   FUNCTION = SendMessage(hLM, %LM_GETIDEALHEIGHT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the states and attributes of an item.
' ========================================================================================
FUNCTION Syslink_GetItem (BYVAL hLM AS DWORD, BYREF lpItem AS LITEM) AS LONG
   FUNCTION = SendMessage(hLM, %LM_GETITEM, 0, VARPTR(lpItem))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines if the user clicked the specified link.
' ========================================================================================
FUNCTION SysLink_HitTest (BYVAL hLM AS DWORD, BYREF lphti AS LHITTESTINFO) AS LONG
   FUNCTION = SendMessage(hLM, %LM_HITTEST, 0, VARPTR(lphti))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the states and attributes of an item.
' ========================================================================================
FUNCTION SysLink_SetItem (BYVAL hLM AS DWORD, BYREF lpItem AS LITEM) AS LONG
   FUNCTION = SendMessage(hLM, %LM_SETITEM, 0, VARPTR(lpItem))
END FUNCTION
' ========================================================================================
