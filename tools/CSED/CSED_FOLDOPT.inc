' ########################################################################################
' CSED Editor
' File: CSED_FOLDOPT.INC
' Contents: Fold options dialog
' Copyright (c) 2012 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ========================================================================================
' Fold Options popup dialog
' ========================================================================================
SUB CSED_FoldOptionsDialog (BYVAL hParent AS DWORD)

   ' // Create an instance of the class
   LOCAL pFoldOpt AS IWindow
   pFoldOpt = CLASS "CWindow"
   IF ISNOTHING(pFoldOpt) THEN EXIT SUB

   ' // Create the main window
   LOCAL hwnd AS DWORD
'   hwnd = pFoldOpt.CreateWindow(hParent, "Fold Options", 0, 0, 398, 210, _
'          %WS_VISIBLE OR %WS_CAPTION OR %WS_POPUPWINDOW, %WS_EX_TOOLWINDOW OR %WS_EX_WINDOWEDGE, _
'          CODEPTR(CSED_FoldOpt_WindowProc))
   hwnd = pFoldOpt.CreateWindow(hParent, "Fold Options", 0, 0, 0, 0, _
          %WS_VISIBLE OR %WS_CAPTION OR %WS_POPUPWINDOW, %WS_EX_WINDOWEDGE, _
          CODEPTR(CSED_FoldOpt_WindowProc))
   pFoldOpt.SetClientSize 392, 185
   pFoldOpt.CenterWindow(hwnd, hParent)

   ' // Add the controls
   LOCAL hCtl AS DWORD

   hCtl = pFoldOpt.AddGroupBox(hwnd, -1, "Fold Level", 10, 7, 180, 133, -1)
   hCtl = pFoldOpt.AddRadioButton(hwnd, %IDC_FOLDLEVELNONE, "None", 20, 30, 150, 20, -1)
   hCtl = pFoldOpt.AddRadioButton(hwnd, %IDC_FOLDLEVELKEYWORD, "Keyword level", 20, 55, 150, 20, -1)

   hCtl = pFoldOpt.AddGroupBox(hwnd, -1, "Fold Symbol", 202, 7, 180, 133, -1)
   hCtl = pFoldOpt.AddRadioButton(hwnd, %IDC_FOLDSYMBOLARROW, "Arrow", 212, 30, 150, 20, -1)
   hCtl = pFoldOpt.AddRadioButton(hwnd, %IDC_FOLDSYMBOLPLUSMINUS, "Plus/Minus", 212, 55, 150, 20, -1)
   hCtl = pFoldOpt.AddRadioButton(hwnd, %IDC_FOLDSYMBOLCIRCLE, "Circle", 212, 80, 150, 20, -1)
   hCtl = pFoldOpt.AddRadioButton(hwnd, %IDC_FOLDSYMBOLBOXTREE, "Box tree", 212, 105, 150, 20, -1)

   hCtl = pFoldOpt.AddButton(hwnd, %IDOK, "&Ok", 133, 150, 75, 24, %BS_DEFPUSHBUTTON)
   hCtl = pFoldOpt.AddButton(hwnd, %IDCANCEL, "&Cancel", 220, 150, 75, 24, -1)
   hCtl = pFoldOpt.AddButton(hwnd, %IDBO_FOLDING_HELP, "&Help", 307, 150, 75, 24, -1)

   IF pSed.FoldLevel = 0 THEN
      CheckDlgButton hwnd, %IDC_FOLDLEVELNONE, %BST_CHECKED
   ELSEIF pSed.FoldLevel = 1 THEN
      CheckDlgButton hwnd, %IDC_FOLDLEVELKEYWORD, %BST_CHECKED
   ELSEIF pSed.FoldLevel = 2 THEN
      CheckDlgButton hwnd, %IDC_FOLDLEVELSUB, %BST_CHECKED
   END IF

   IF pSed.FoldSymbol = 1 THEN
      CheckDlgButton hwnd, %IDC_FOLDSYMBOLARROW, %BST_CHECKED
   ELSEIF pSed.FoldSymbol = 2 THEN
      CheckDlgButton hwnd, %IDC_FOLDSYMBOLPLUSMINUS, %BST_CHECKED
   ELSEIF pSed.FoldSymbol = 3 THEN
      CheckDlgButton hwnd, %IDC_FOLDSYMBOLCIRCLE, %BST_CHECKED
   ELSEIF pSed.FoldSymbol = 4 THEN
      CheckDlgButton hwnd, %IDC_FOLDSYMBOLBOXTREE, %BST_CHECKED
   END IF

   ' // Default message pump
   pFoldOpt.DoEvents

END SUB
' ========================================================================================

' ========================================================================================
' Editor options callback function.
' ========================================================================================
FUNCTION CSED_FoldOpt_WindowProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
   LOCAL szText  AS WSTRINGZ * 255               ' // General purpose variable
   LOCAL szPath  AS WSTRINGZ * %MAX_PATH         ' // File path
   STATIC strDir AS WSTRING                      ' // Last used directory path
#ELSE
   LOCAL szText  AS ASCIIZ * 255                 ' // General purpose variable
   LOCAL szPath  AS ASCIIZ * %MAX_PATH           ' // File path
   STATIC strDir AS STRING                       ' // Last used directory path
#ENDIF

   SELECT CASE uMsg

      CASE %WM_CREATE
         ' // Disable the owner of the modal window
         EnableWindow GetWindow(hwnd, %GW_OWNER), %FALSE

      CASE %WM_COMMAND

         SELECT CASE LO(WORD, wParam)

            CASE %IDCANCEL
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  SendMessage hwnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF

            CASE %IDOK
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  IF IsDlgButtonChecked(hwnd, %IDC_FOLDLEVELNONE) THEN
                     pSed.FOLDLevel = 0
                  ELSEIF IsDlgButtonChecked(hwnd, %IDC_FOLDLEVELKEYWORD) THEN
                     pSed.FoldLevel = 1
                  ELSEIF IsDlgButtonChecked(hwnd, %IDC_FOLDLEVELSUB) THEN
                     pSed.FoldLevel = 2
                  END IF
                  IF IsDlgButtonChecked(hwnd, %IDC_FOLDSYMBOLARROW) THEN
                     pSed.FoldSymbol = 1
                  ELSEIF IsDlgButtonChecked(hwnd, %IDC_FOLDSYMBOLPLUSMINUS) THEN
                     pSed.FoldSymbol = 2
                  ELSEIF IsDlgButtonChecked(hwnd, %IDC_FOLDSYMBOLCIRCLE) THEN
                     pSed.FoldSymbol = 3
                  ELSEIF IsDlgButtonChecked(hwnd, %IDC_FOLDSYMBOLBOXTREE) THEN
                     pSed.FoldSymbol = 4
                  END IF
                  ' // Force repainting
                  SCI_Colourise(pSed.hEdit, 0, -1)
                  ' // Close the dialog
                  SendMessage hwnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF

            CASE %IDBO_FOLDING_HELP
               szPath = EXE.Path$ & "CSED.CHM"
               szText = "Folding Options"
               IF ISFILE(szPath) THEN
                  LOCAL hlk AS HH_AKLINK
                  hlk.cbStruct     = SIZEOF(hlk)
                  hlk.pszKeywords  = VARPTR(szText)
                  hlk.fIndexOnFail = %TRUE
                  HtmlHelp hWnd, szPath, %HH_DISPLAY_TOPIC, %NULL
                  HtmlHelp hWnd, szPath, %HH_KEYWORD_LOOKUP, VARPTR(hlk)
               END IF

         END SELECT

      CASE %WM_CLOSE
         ' // The owner window is enabled in WM_CLOSE rather than WM_DESTROY to
         ' // prevent the application from losing the focus. In WM_DESTROY the
         ' // modal window has already been removed from the screen by the system.
         ' // Because the remaining windows are disabled, the system gives the
         ' // focus to another application.
         EnableWindow GetWindow(hwnd, %GW_OWNER), %TRUE

      CASE %WM_DESTROY
         ' // Close the main window
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
