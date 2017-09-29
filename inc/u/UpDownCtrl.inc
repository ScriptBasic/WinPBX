' ########################################################################################
' Microsoft Windows
' File: UpDownCtrl.inc
' Contents: Trackbar Control Wrapper Functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%UPDOWNCTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"

' ========================================================================================
' Retrieves acceleration information for an up-down control.
' ========================================================================================
FUNCTION UpDown_GetAccel (BYVAL hUDM AS DWORD, BYVAL cAccels AS DWORD, BYREF paAccels AS UDACCEL) AS LONG
   FUNCTION = SendMessage(hUDM, %UDM_GETACCEL, cAccels, VARPTR(paAccels))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current radix base (that is, either base 10 or 16) for an up-down control.
' ========================================================================================
FUNCTION UpDown_GetBase (BYVAL hUDM AS DWORD) AS LONG
   FUNCTION = SendMessage(hUDM, %UDM_GETBASE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the handle to the current buddy window.
' ========================================================================================
FUNCTION UpDown_GetBuddy (BYVAL hUDM AS DWORD) AS DWORD
   FUNCTION = SendMessage(hUDM, %UDM_GETBUDDY, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current position of an up-down control with 16-bit precision.
' ========================================================================================
FUNCTION UpDown_GetPos (BYVAL hUDM AS DWORD) AS LONG
   FUNCTION = SendMessage(hUDM, %UDM_GETPOS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the 32-bit position of an up-down control.
' ========================================================================================
FUNCTION UpDown_GetPos32 (BYVAL hUDM AS DWORD, BYREF pfError AS LONG) AS LONG
   FUNCTION = SendMessage(hUDM, %UDM_GETPOS32, 0, pfError)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the 32-bit position of an up-down control.
' ========================================================================================
FUNCTION UpDown_GetRange (BYVAL hUDM AS DWORD) AS LONG
   FUNCTION = SendMessage(hUDM, %UDM_GETRANGE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the 32-bit position of an up-down control.
' ========================================================================================
SUB UpDown_GetRange32 (BYVAL hUDM AS DWORD, BYREF pLow AS WORD, BYREF pHigh AS WORD)
   SendMessage hUDM, %UDM_GETRANGE32, VARPTR(pLow), VARPTR(pHigh)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the Unicode character format flag for the control.
' ========================================================================================
FUNCTION UpDown_GetUnicodeFormat (BYVAL hUDM AS DWORD) AS LONG
   FUNCTION = SendMessage(hUDM, %UDM_GETUNICODEFORMAT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the acceleration for an up-down control.
' ========================================================================================
FUNCTION UpDown_SetAccel (BYVAL hUDM AS DWORD, BYVAL cAccels AS DWORD, BYREF paAccels AS UDACCEL) AS LONG
   FUNCTION = SendMessage(hUDM, %UDM_SETACCEL, cAccels, VARPTR(paAccels))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the acceleration for an up-down control.
' ========================================================================================
FUNCTION UpDown_SetBase (BYVAL hUDM AS DWORD, BYVAL nBase AS LONG) AS LONG
   FUNCTION = SendMessage(hUDM, %UDM_SETBASE, nBase, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the buddy window for an up-down control.
' ========================================================================================
FUNCTION UpDown_SetBuddy (BYVAL hUDM AS DWORD, BYVAL hwndBuddy AS DWORD) AS DWORD
   FUNCTION = SendMessage(hUDM, %UDM_SETBUDDY, hwndBuddy, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the current position for an up-down control with 16-bit precision.
' ========================================================================================
FUNCTION UpDown_SetPos (BYVAL hUDM AS DWORD, BYVAL nPos AS INTEGER) AS LONG
   FUNCTION = SendMessage(hUDM, %UDM_SETPOS, 0, MAK(LONG, nPos, 0))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the current position for an up-down control with 32-bit precision.
' ========================================================================================
FUNCTION UpDown_SetPos32 (BYVAL hUDM AS DWORD, BYVAL nPos AS LONG) AS LONG
   FUNCTION = SendMessage(hUDM, %UDM_SETPOS32, 0, nPos)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the minimum and maximum positions (range) for an up-down control.
' ========================================================================================
SUB UpDown_SetRange (BYVAL hUDM AS DWORD, BYVAL nUpper AS INTEGER, BYVAL nLower AS INTEGER)
   SendMessage hUDM, %UDM_SETRANGE, 0, MAK(LONG, nUpper, nLower)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the minimum and maximum positions (range) for an up-down control.
' ========================================================================================
SUB UpDown_SetRange32 (BYVAL hUDM AS DWORD, BYVAL iLow AS LONG, BYVAL iHigh AS LONG)
   SendMessage hUDM, %UDM_SETRANGE32, iLow, iHigh
END SUB
' ========================================================================================

' ========================================================================================
' Sets the Unicode character format flag for the control.
' ========================================================================================
FUNCTION UpDown_SetUnicodeFormat (BYVAL hUDM AS DWORD, BYVAL fUnicode AS LONG) AS LONG
   FUNCTION = SendMessage(hUDM, %UDM_SETUNICODEFORMAT, fUnicode, 0)
END FUNCTION
' ========================================================================================
