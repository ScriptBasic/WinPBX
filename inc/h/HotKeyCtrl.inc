' ########################################################################################
' Microsoft Windows
' File: HotKeyCtrl.inc
' Contents: Hot Key Control Wrapper Functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%HOTKEYCTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"

' ========================================================================================
' Gets the virtual key code and modifier flags of a hot key from a hot key control.
' ========================================================================================
FUNCTION HotKey_GetHotKey (BYVAL hHotKey AS DWORD) AS LONG
   FUNCTION = SendMessage(hHotKey, %HKM_GETHOTKEY, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the hot key combination for a hot key control.
' ========================================================================================
FUNCTION HotKey_SetHotKey (BYVAL hHotKey AS DWORD, BYVAL vkCode AS DWORD, BYVAL fMods AS DWORD) AS LONG
   FUNCTION = SendMessage(hHotKey, %HKM_SETHOTKEY, MAK(DWORD, vkCode, fMods), 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Defines the invalid combinations and the default modifier combination for a hot key control.
' ========================================================================================
FUNCTION HotKey_SetRules (BYVAL hHotKey AS DWORD, BYVAL fwCombInv AS DWORD, BYVAL fwModInv AS DWORD) AS LONG
   FUNCTION = SendMessage(hHotKey, %HKM_SETRULES, fwCombInv, MAK(LONG, fwModInv, 0))
END FUNCTION
' ========================================================================================
