' ########################################################################################
' Microsoft Windows
' File: IPAddressCtrl.inc
' Contents: IP Address edit control Wrapper Functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IPADDRESSCTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"

' ========================================================================================
' Clears the contents of the IP address control.
' ========================================================================================
SUB IPAddress_ClearAddress (BYVAL hIPM AS DWORD)
   SendMessage hIPM, %IPM_CLEARADDRESS, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Gets the address values for all four fields in the IP address control.
' ========================================================================================
FUNCTION IPAddress_GetAddress (BYVAL hIPM AS DWORD, BYREF pdwAddr AS DWORD) AS LONG
   FUNCTION = SendMessage(hIPM, %IPM_GETADDRESS, 0, VARPTR(pdwAddr))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines if all fields in the IP address control are blank.
' ========================================================================================
SUB IPAddress_IsBlank (BYVAL hIPM AS DWORD)
   SendMessage hIPM, %IPM_ISBLANK, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the address values for all four fields in the IP address control.
' ========================================================================================
SUB IPAddress_SetAddress (BYVAL hIPM AS DWORD, BYVAL dwAddr AS DWORD)
   SendMessage hIPM, %IPM_SETADDRESS, 0, dwAddr
END SUB
' ========================================================================================

' ========================================================================================
' Sets the keyboard focus to the specified field in the IP address control.
' All of the text in that field will be selected.
' ========================================================================================
SUB IPAddress_SetFocus (BYVAL hIPM AS DWORD, BYVAL nField AS LONG)
   SendMessage hIPM, %IPM_SETFOCUS, nField, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the valid range for the specified field in the IP address control.
' ========================================================================================
SUB IPAddress_SetRange (BYVAL hIPM AS DWORD, BYVAL nField AS LONG, BYVAL loRange AS BYTE, BYVAL hiRange AS BYTE)
   LOCAL dwRange AS DWORD
   dwRange = hiRange
   SHIFT LEFT dwRange, 8
   dwRange = dwRange OR loRange
   SendMessage hIPM, %IPM_SETRANGE, nField, dwRange
END SUB
' ========================================================================================
