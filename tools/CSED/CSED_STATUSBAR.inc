' ########################################################################################
' CSED Editor
' File: CSED_STATUSBAR.INC
' Contents: CSED editor status bar
' Copyright (c) 2012 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ========================================================================================
' Creates the status bar
' ========================================================================================
FUNCTION CSED_CreateStatusBar (BYVAL pWindow AS IWindow) AS DWORD

   LOCAL hStatusBar AS DWORD
#IF %DEF(%UNICODE)
   LOCAL szFmt AS WSTRINGZ * 15
   LOCAL szDate AS WSTRINGZ * %MAX_PATH
#ELSE
   LOCAL szFmt AS ASCIIZ * 15
   LOCAL szDate AS ASCIIZ * %MAX_PATH
#ENDIF

   hStatusBar = pWindow.AddStatusBar(pWindow.hwnd, %IDC_STATUSBAR, "", 0, 0, 0, 0, _
                %WS_CHILD OR %WS_VISIBLE OR %WS_BORDER OR %CCS_BOTTOM OR %SBARS_SIZEGRIP)

   ' // Set the parts
'   Statusbar_SetStatusbarPartsBySize(hStatusBar, "86, 90, 230, 60, -1")
   pWindow.SetStatusbarPartsBySize(hStatusBar, "86, 90, 230, 60, -1")
   ' // Show the date
   szFmt = "dd MMM yyyy"
   GetDateFormat(%LOCALE_USER_DEFAULT, 0, BYVAL %NULL, szFmt, szDate, SIZEOF(szDate))
   StatusBar_SetText(hStatusBar, 0, szDate)
   pSed.hStatusBar = hStatusBar
   FUNCTION = hStatusBar

END FUNCTION
' ========================================================================================

' ========================================================================================
' Clear the status bar
' ========================================================================================
SUB CSED_ClearStatusbar
   StatusBar_SetText(pSed.hStatusbar, 1, "")
   StatusBar_SetText(pSed.hStatusbar, 2, "")
'   StatusBar_SetText(pSed.hStatusbar, 3, "")
   IF pSed.SelectedCompiler = 2 THEN StatusBar_SetText(pSed.hStatusbar, 3, "PBCC") ELSE StatusBar_SetText(pSed.hStatusbar, 3, "PBWIN")
   StatusBar_SetText(pSed.hStatusbar, 4, "")
END SUB
' ========================================================================================
