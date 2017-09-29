' ########################################################################################
' CSED Editor
' File: CSED_GOTOLINE.INC
' Contents: Go to line dialog
' Copyright (c) 2012 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ========================================================================================
' Go to line popup dialog
' ========================================================================================
SUB CSED_GotoLineDialog (BYVAL hParent AS LONG)

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT SUB

   ' // Create the main window
   LOCAL hwnd AS DWORD
'   hwnd = pWindow.CreateWindow(hParent, "Go to line", 0, 0, 0, 0, _
'          %WS_VISIBLE OR %WS_CAPTION OR %WS_POPUPWINDOW, %WS_EX_TOOLWINDOW OR %WS_EX_WINDOWEDGE, _
'          CODEPTR(CSED_GotoLine_WindowProc))
   hwnd = pWindow.CreateWindow(hParent, "Go to line", 0, 0, 0, 0, _
          %WS_VISIBLE OR %WS_CAPTION OR %WS_POPUPWINDOW, %WS_EX_WINDOWEDGE, _
          CODEPTR(CSED_GotoLine_WindowProc))
   pWindow.SetClientSize 254, 97
   pWindow.CenterWindow(hwnd, hParent)

   ' // Retrieve the position and number of lines
   LOCAL curPos AS LONG
   LOCAL nLine  AS LONG
   LOCAL nLines AS LONG

   curPos = SCI_GetCurrentPos(pSed.hEdit)
   nLine = SCI_LineFromPosition(pSed.hEdit, curPos) + 1
   nLines = SCI_GetLineCount(pSed.hEdit)

   ' // Add the controls
   LOCAL hCtl AS DWORD

   hCtl = pWindow.AddGroupBox(hwnd, -1, "", 15, 8, 135, 74, -1)
   hCtl = pWindow.AddLabel(hwnd, -1, "Last line:", 18, 20, 68, 13, %WS_CHILD OR %WS_VISIBLE OR %SS_RIGHT)
   hCtl = pWindow.AddLabel(hwnd, -1, "", 90, 20, 48, 13, %WS_CHILD OR %WS_VISIBLE OR %SS_RIGHT)
   SetWindowText hCtl, FORMAT$(nLines)
   hCtl = pWindow.AddLabel(hwnd, -1, "Current line:", 18, 37, 68, 13, %WS_CHILD OR %WS_VISIBLE OR %SS_RIGHT)
   hCtl = pWindow.AddLabel(hwnd, -1, "", 90, 37, 48, 13, %WS_CHILD OR %WS_VISIBLE OR %SS_RIGHT)
   SetWindowText hCtl, FORMAT$(nLine)
   hCtl = pWindow.AddLabel(hwnd, -1, "&Go to line:", 18, 57, 68, 13, %WS_CHILD OR %WS_VISIBLE OR %SS_RIGHT)
   hCtl = pWindow.AddTextBox(hwnd, 100, "", 90, 55, 51, 20, %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %ES_NUMBER OR %ES_AUTOHSCROLL, %WS_EX_CLIENTEDGE)
   Edit_LimitText(hCtl, LEN(FORMAT$(nLines)))
   SetFocus hCtl
   hCtl = pWindow.AddButton(hwnd, %IDOK, "&Ok", 165, 13, 75, 23, %BS_DEFPUSHBUTTON)
   AfxDisableWindow hCtl
   hCtl = pWindow.AddButton(hwnd, %IDCANCEL, "&Cancel", 165, 41, 75, 23, -1)

   ' // Default message pump
   pWindow.DoEvents

END SUB
' ========================================================================================

' ========================================================================================
' Go to line window procedure
' ========================================================================================
FUNCTION CSED_GotoLine_WindowProc (BYVAL hwnd AS DWORD, BYVAL wMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL szBuffer AS ASCIIZ * 255
   LOCAL nLine    AS LONG

   SELECT CASE wMsg
      CASE %WM_CREATE   ' Entrance
         EnableWindow GetParent(hwnd), %FALSE   ' To make popup dialog modal

      CASE %WM_COMMAND
         SELECT CASE LO(WORD, wParam)
            CASE %IDCANCEL
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  SendMessage hwnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
            CASE %IDOK
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  szBuffer = AfxGetWindowText(GetDlgItem(hwnd, 100))
                  nLine = VAL(szBuffer) - 1
                  SCI_GotoLine(pSed.hEdit, nLine)
                  SendMessage hwnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
            CASE 100   ' // Go to line edit control
               IF HI(WORD, wParam) = %EN_CHANGE THEN
                  szBuffer = AfxGetWindowText(GetDlgItem(hwnd, 100))
                  IF LEN(szBuffer) THEN
                     IF VAL(szBuffer) > SCI_GetLineCount(pSed.hEdit) THEN
                        EnableWindow GetDlgItem(hwnd, %IDOK), %FALSE
                     ELSE
                        EnableWindow GetDlgItem(hwnd, %IDOK), %TRUE
                     END IF
                  ELSE
                     EnableWindow GetDlgItem(hwnd, %IDOK), %FALSE
                  END IF
               END IF
         END SELECT

      CASE %WM_CLOSE
         ' // Maintains parent's zorder
         EnableWindow GetParent(hwnd), %TRUE

      CASE %WM_DESTROY
         ' // Close the main window
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hwnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
