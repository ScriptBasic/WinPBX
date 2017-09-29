' ########################################################################################
' CSED Editor
' File: CSED_CMPOPT.INC
' Contents: Compiler options dialog
' Copyright (c) 2012 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ========================================================================================
' Compiler Options popup dialog
' ========================================================================================
SUB CSED_CompilerOptionsDialog (BYVAL hParent AS DWORD)

   ' // Create an instance of the class
   LOCAL pCmpOpt AS IWindow
   pCmpOpt = CLASS "CWindow"
   IF ISNOTHING(pCmpOpt) THEN EXIT SUB

   ' // Create the main window
   LOCAL hwnd AS DWORD
'   hwnd = pCmpOpt.CreateWindow(hParent, "Compiler Options and Paths", 0, 0, 700, 539, _
'          %WS_VISIBLE OR %WS_CAPTION OR %WS_POPUPWINDOW, %WS_EX_TOOLWINDOW OR %WS_EX_WINDOWEDGE, _
'          CODEPTR(CSED_EdCmp_WindowProc))
   hwnd = pCmpOpt.CreateWindow(hParent, "Compiler Options and Paths", 0, 0, 0, 0, _
          %WS_VISIBLE OR %WS_CAPTION OR %WS_POPUPWINDOW, %WS_EX_WINDOWEDGE, _
          CODEPTR(CSED_EdCmp_WindowProc))
   pCmpOpt.SetClientSize 786, 480
   pCmpOpt.CenterWindow(hwnd, hParent)

   ' // Add controls
   LOCAL hCtl AS DWORD

   ' // Add the controls

   hCtl = pCmpOpt.AddGroupBox(hwnd, -1, "Paths", 10, 8, 566, 460, -1)
   hCtl = pCmpOpt.AddLabel(hwnd, -1, "PowerBASIC for Windows", 20, 33, 150, 16, -1)
   hCtl = pCmpOpt.AddTextBox(hwnd, %IDCO_PBWINPATH, "", 178, 31, 350, 21, -1, %WS_EX_CLIENTEDGE)
   hCtl = pCmpOpt.AddButton(hwnd, %IDBO_PBWINPATH, "...", 538, 31, 28, 21, %BS_FLAT)

   hCtl = pCmpOpt.AddLabel(hwnd, -1, "PowerBASIC Console", 20, 57, 150, 16, -1)
   hCtl = pCmpOpt.AddTextBox(hwnd, %IDCO_PBCCPATH, "", 178, 55, 350, 21, -1, %WS_EX_CLIENTEDGE)
   hCtl = pCmpOpt.AddButton(hwnd, %IDBO_PBCCPATH, "...", 538, 55, 28, 21, %BS_FLAT)

   hCtl = pCmpOpt.AddLabel(hwnd, -1, "Resource Compiler", 20, 81, 150, 16, -1)
   hCtl = pCmpOpt.AddTextBox(hwnd, %IDCO_RCPATH, "", 178, 79, 350, 21, -1, %WS_EX_CLIENTEDGE)
   hCtl = pCmpOpt.AddButton(hwnd, %IDBO_RCPATH, "...", 538, 79, 28, 21, %BS_FLAT)

   hCtl = pCmpOpt.AddLabel(hwnd, -1, "PowerBASIC Forms", 20, 105, 150, 16, -1)
   hCtl = pCmpOpt.AddTextBox(hwnd, %IDCO_PBFORMSPATH, "", 178, 103, 350, 21, -1, %WS_EX_CLIENTEDGE)
   hCtl = pCmpOpt.AddButton(hwnd, %IDBO_PBFORMSPATH, "...", 538, 103, 28, 21, %BS_FLAT)

   hCtl = pCmpOpt.AddLabel(hwnd, -1, "PowerBASIC COM Browser", 20, 129, 150, 16, -1)
   hCtl = pCmpOpt.AddTextBox(hwnd, %IDCO_PBCOMBROWSERPATH, "", 178, 127, 350, 21, -1, %WS_EX_CLIENTEDGE)
   hCtl = pCmpOpt.AddButton(hwnd, %IDBO_PBCOMBROWSERPATH, "...", 538, 127, 28, 21, %BS_FLAT)

   hCtl = pCmpOpt.AddLabel(hwnd, -1, "PowerBASIC Library Manager", 20, 153, 150, 16, -1)
   hCtl = pCmpOpt.AddTextBox(hwnd, %IDCO_POWERLIBPATH, "", 178, 151, 350, 21, -1, %WS_EX_CLIENTEDGE)
   hCtl = pCmpOpt.AddButton(hwnd, %IDBO_POWERLIBPATH, "...", 538, 151, 28, 21, %BS_FLAT)

   hCtl = pCmpOpt.AddLabel(hwnd, -1, "PowerBASIC Include Files I", 20, 177, 150, 16, -1)
   hCtl = pCmpOpt.AddTextBox(hwnd, %IDCO_PBINCPATH1, "", 178, 175, 350, 21, -1, %WS_EX_CLIENTEDGE)
   hCtl = pCmpOpt.AddButton(hwnd, %IDBO_PBINCPATH1, "...", 538, 175, 28, 21, %BS_FLAT)

   hCtl = pCmpOpt.AddLabel(hwnd, -1, "PowerBASIC Include Files II", 20, 201, 150, 16, -1)
   hCtl = pCmpOpt.AddTextBox(hwnd, %IDCO_PBINCPATH2, "", 178, 199, 350, 21, -1, %WS_EX_CLIENTEDGE)
   hCtl = pCmpOpt.AddButton(hwnd, %IDBO_PBINCPATH2, "...", 538, 199, 28, 21, %BS_FLAT)

   hCtl = pCmpOpt.AddLabel(hwnd, -1, "José Roca Include Files I", 20, 225, 150, 16, -1)
   hCtl = pCmpOpt.AddTextBox(hwnd, %IDCO_JRSINCPATH1, "", 178, 223, 350, 21, -1, %WS_EX_CLIENTEDGE)
   hCtl = pCmpOpt.AddButton(hwnd, %IDBO_JRSINCPATH1, "...", 538, 223, 28, 21, %BS_FLAT)

   hCtl = pCmpOpt.AddLabel(hwnd, -1, "José Roca Include Files II", 20, 249, 150, 16, -1)
   hCtl = pCmpOpt.AddTextBox(hwnd, %IDCO_JRSINCPATH2, "", 178, 247, 350, 21, -1, %WS_EX_CLIENTEDGE)
   hCtl = pCmpOpt.AddButton(hwnd, %IDBO_JRSINCPATH2, "...", 538, 247, 28, 21, %BS_FLAT)

   hCtl = pCmpOpt.AddLabel(hwnd, -1, "José Roca TypeLib Browser", 20, 273, 150, 16, -1)
   hCtl = pCmpOpt.AddTextBox(hwnd, %IDCO_TYPELIBBROWSERPATH, "", 178, 271, 350, 21, -1, %WS_EX_CLIENTEDGE)
   hCtl = pCmpOpt.AddButton(hwnd, %IDBO_TYPELIBBROWSERPATH, "...", 538, 271, 28, 21, %BS_FLAT)

   hCtl = pCmpOpt.AddLabel(hwnd, -1, "Visual Designer", 20, 297, 150, 16, -1)
   hCtl = pCmpOpt.AddTextBox(hwnd, %IDCO_VISDESPATH, "", 178, 295, 350, 21, -1, %WS_EX_CLIENTEDGE)
   hCtl = pCmpOpt.AddButton(hwnd, %IDBO_VISDESPATH, "...", 538, 295, 28, 21, %BS_FLAT)

   hCtl = pCmpOpt.AddLabel(hwnd, -1, "Icon Editor", 20, 321, 150, 16, -1)
   hCtl = pCmpOpt.AddTextBox(hwnd, %IDCO_ICONEDITORPATH, "", 178, 319, 350, 21, -1, %WS_EX_CLIENTEDGE)
   hCtl = pCmpOpt.AddButton(hwnd, %IDBO_ICONEDITORPATH, "...", 538, 319, 28, 21, %BS_FLAT)

   hCtl = pCmpOpt.AddLabel(hwnd, -1, "Image Editor", 20, 345, 150, 16, -1)
   hCtl = pCmpOpt.AddTextBox(hwnd, %IDCO_IMAGEEDITORPATH, "", 178, 343, 350, 21, -1, %WS_EX_CLIENTEDGE)
   hCtl = pCmpOpt.AddButton(hwnd, %IDBO_IMAGEEDITORPATH, "...", 538, 343, 28, 21, %BS_FLAT)

   hCtl = pCmpOpt.AddLabel(hwnd, -1, "PBWIN Help", 20, 369, 150, 16, -1)
   hCtl = pCmpOpt.AddTextBox(hwnd, %IDCO_PBWINHELPPATH, "", 178, 367, 350, 21, -1, %WS_EX_CLIENTEDGE)
   hCtl = pCmpOpt.AddButton(hwnd, %IDBO_PBWINHELPPATH, "...", 538, 367, 28, 21, %BS_FLAT)

   hCtl = pCmpOpt.AddLabel(hwnd, -1, "PBCC Help", 20, 393, 150, 16, -1)
   hCtl = pCmpOpt.AddTextBox(hwnd, %IDCO_PBCCHELPPATH, "", 178, 391, 350, 21, -1, %WS_EX_CLIENTEDGE)
   hCtl = pCmpOpt.AddButton(hwnd, %IDBO_PBCCHELPPATH, "...", 538, 391, 28, 21, %BS_FLAT)

   hCtl = pCmpOpt.AddLabel(hwnd, -1, "Platform SDK Help", 20, 417, 150, 16, -1)
   hCtl = pCmpOpt.AddTextBox(hwnd, %IDCO_SDKHELPPATH, "", 178, 415, 350, 21, -1, %WS_EX_CLIENTEDGE)
   hCtl = pCmpOpt.AddButton(hwnd, %IDBO_SDKHELPPATH, "...", 538, 415, 28, 21, %BS_FLAT)

   hCtl = pCmpOpt.AddLabel(hwnd, -1, "Debugging Tool", 20, 441, 150, 16, -1)
   hCtl = pCmpOpt.AddTextBox(hwnd, %IDCO_DEBUGTOOLPATH, "", 178, 439, 350, 21, -1, %WS_EX_CLIENTEDGE)
   hCtl = pCmpOpt.AddButton(hwnd, %IDBO_DEBUGTOOLPATH, "...", 538, 439, 28, 21, %BS_FLAT)

   hCtl = pCmpOpt.AddGroupBox(hwnd, -1, "Selected Compiler", 586, 8, 190, 74, -1)
   hCtl = pCmpOpt.AddRadioButton(hwnd, %IDCO_PBWIN, "PBWIN", 605, 33, 150, 16, -1)
   hCtl = pCmpOpt.AddRadioButton(hwnd, %IDCO_PBCC, "PBCC", 605, 57, 150, 16, -1)

   hCtl = pCmpOpt.AddGroupBox(hwnd, -1, "Compiler Results", 586, 88, 190, 94, -1)
   hCtl = pCmpOpt.AddCheckBox(hwnd, %IDCO_DISPRES, "Display results", 605, 107, 140, 16, -1)
   hCtl = pCmpOpt.AddCheckBox(hwnd, %IDCO_DELLOG, "Delete log file", 605, 131, 140, 16, -1)
   hCtl = pCmpOpt.AddCheckBox(hwnd, %IDCO_BEEPONEND, "Beep on completion", 605, 155, 150, 16, -1)

   hCtl = pCmpOpt.AddGroupBox(hwnd, -1, "Selected Windows API Headers", 586, 188, 190, 118, -1)
   hCtl = pCmpOpt.AddRadioButton(hwnd, %IDCO_JRSINC1, "José Roca Headers I", 605, 207, 150, 16, -1)
   hCtl = pCmpOpt.AddRadioButton(hwnd, %IDCO_JRSINC2, "José Roca Headers II", 605, 231, 150, 16, -1)
   hCtl = pCmpOpt.AddRadioButton(hwnd, %IDCO_PBINC1, "PowerBASIC Headers I", 605, 255, 150, 16, -1)
   hCtl = pCmpOpt.AddRadioButton(hwnd, %IDCO_PBINC2, "PowerBASIC Headers II", 605, 279, 150, 16, -1)

'   hCtl = pCmpOpt.AddButton(hwnd, %IDOK, "&Ok", 433, 481, 78, 24, %BS_DEFPUSHBUTTON)
   hCtl = pCmpOpt.AddButton(hwnd, %IDOK, "&Ok", 586, 440, 58, 24, %BS_DEFPUSHBUTTON)
   hCtl = pCmpOpt.AddButton(hwnd, %IDCANCEL, "&Cancel", 652, 440, 58, 24, -1)
   hCtl = pCmpOpt.AddButton(hwnd, %IDBO_COMPILEROPT_HELP, "&Help", 717, 440, 58, 24, -1)

   ' // Set the options
   IF pSed.SelectedCompiler = 1 OR pSed.SelectedCompiler = 0 THEN
      CheckDlgButton hwnd, %IDCO_PBWIN, %BST_CHECKED
      Statusbar_SetText pSed.hStatusbar,3, "PBWIN"
   ELSEIF pSed.SelectedCompiler = 2 THEN
      CheckDlgButton hwnd, %IDCO_PBCC, %BST_CHECKED
      Statusbar_SetText pSed.hStatusbar,3, "PBCC"
   END IF
   IF pSed.SelectedHeaders = 1 OR pSed.SelectedHeaders = 0 THEN
      CheckDlgButton hwnd, %IDCO_JRSINC1, %BST_CHECKED
   ELSEIF pSed.SelectedHeaders = 2 THEN
      CheckDlgButton hwnd, %IDCO_JRSINC2, %BST_CHECKED
   ELSEIF pSed.SelectedHeaders = 3 THEN
      CheckDlgButton hwnd, %IDCO_PBINC1, %BST_CHECKED
   ELSEIF pSed.SelectedHeaders = 4 THEN
      CheckDlgButton hwnd, %IDCO_PBINC2, %BST_CHECKED
   END IF
   CheckDlgButton hwnd, %IDCO_DISPRES, pSed.DisplayResults
   CheckDlgButton hwnd, %IDCO_DELLOG, pSed.DeleteLogFile
   CheckDlgButton hwnd, %IDCO_BEEPONEND, pSed.BeepOnCompletion
   Edit_SetText GetDlgItem(hwnd, %IDCO_PBWINPATH), pSed.PBWINPath
   Edit_SetText GetDlgItem(hwnd, %IDCO_PBCCPATH), pSed.PBCCPath
   Edit_SetText GetDlgItem(hwnd, %IDCO_RCPATH), pSed.RCPath
   Edit_SetText GetDlgItem(hwnd, %IDCO_PBFORMSPATH), pSed.PBFormsPath
   Edit_SetText GetDlgItem(hwnd, %IDCO_PBCOMBROWSERPATH), pSed.PBCOMBrowserPath
   Edit_SetText GetDlgItem(hwnd, %IDCO_TYPELIBBROWSERPATH), pSed.TypelibBrowserPath
   Edit_SetText GetDlgItem(hwnd, %IDCO_JRSINCPATH1), pSed.JRSIncPath1
   Edit_SetText GetDlgItem(hwnd, %IDCO_JRSINCPATH2), pSed.JRSIncPath2
   Edit_SetText GetDlgItem(hwnd, %IDCO_PBINCPATH1), pSed.PBIncPath1
   Edit_SetText GetDlgItem(hwnd, %IDCO_PBINCPATH2), pSed.PBIncPath2
   Edit_SetText GetDlgItem(hwnd, %IDCO_VISDESPATH), pSed.VisualDesignerPath
   Edit_SetText GetDlgItem(hwnd, %IDCO_ICONEDITORPATH), pSed.IconEditorPath
   Edit_SetText GetDlgItem(hwnd, %IDCO_IMAGEEDITORPATH), pSed.ImageEditorPath
   Edit_SetText GetDlgItem(hwnd, %IDCO_PBWINHELPPATH), pSed.PBWinHelpPath
   Edit_SetText GetDlgItem(hwnd, %IDCO_PBCCHELPPATH), pSed.PBCCHelpPath
   Edit_SetText GetDlgItem(hwnd, %IDCO_SDKHELPPATH), pSed.SDKHelpPath
   Edit_SetText GetDlgItem(hwnd, %IDCO_DEBUGTOOLPATH), pSed.DebugToolPath
   Edit_SetText GetDlgItem(hwnd, %IDCO_POWERLIBPATH), pSed.PowerLibPath

   ' // Default message pump (you can replace it with your own)
   pCmpOpt.DoEvents

END SUB
' ========================================================================================

' ========================================================================================
' Editor options callback function.
' ========================================================================================
FUNCTION CSED_EdCmp_WindowProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

#IF %DEF(%UNICODE)
   LOCAL szText AS WSTRINGZ * 255                ' // General purpose variable
   LOCAL szPath AS WSTRINGZ * %MAX_PATH          ' // File path
   STATIC strDir AS WSTRING                      ' // Last used directory path
#ELSE
   LOCAL szText AS ASCIIZ * 255                  ' // General purpose variable
   LOCAL szPath AS ASCIIZ * %MAX_PATH            ' // File path
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
                  IF IsDlgButtonChecked(hwnd, %IDCO_PBWIN) = %BST_CHECKED THEN
                     pSed.SelectedCompiler = 1
                  ELSEIF IsDlgButtonChecked(hwnd, %IDCO_PBCC) = %BST_CHECKED THEN
                     pSed.SelectedCompiler = 2
                  ELSE
                     pSed.SelectedCompiler = 0
                  END IF
                  IF IsDlgButtonChecked(hwnd, %IDCO_JRSINC1) = %BST_CHECKED THEN
                     pSed.SelectedHeaders = 1
                  ELSEIF IsDlgButtonChecked(hwnd, %IDCO_JRSINC2) = %BST_CHECKED THEN
                     pSed.SelectedHeaders = 2
                  ELSEIF IsDlgButtonChecked(hwnd, %IDCO_PBINC1) = %BST_CHECKED THEN
                     pSed.SelectedHeaders = 3
                  ELSEIF IsDlgButtonChecked(hwnd, %IDCO_PBINC2) = %BST_CHECKED THEN
                     pSed.SelectedHeaders = 4
                  ELSE
                     pSed.SelectedHeaders = 0
                  END IF
                  pSed.DisplayResults = IsDlgButtonChecked(hwnd, %IDCO_DISPRES)
                  pSed.DeleteLogFile = IsDlgButtonChecked(hwnd, %IDCO_DELLOG)
                  pSed.BeepOnCompletion = IsDlgButtonChecked(hwnd, %IDCO_BEEPONEND)
                  pSed.PBWINPath = Edit_GetText(GetDlgItem(hwnd, %IDCO_PBWINPATH))
                  pSed.PBCCPath = Edit_GetText(GetDlgItem(hwnd, %IDCO_PBCCPATH))
                  pSed.RCPath = Edit_GetText(GetDlgItem(hwnd, %IDCO_RCPATH))
                  pSed.PBFormsPath = Edit_GetText(GetDlgItem(hwnd, %IDCO_PBFORMSPATH))
                  pSed.PBCOMBrowserPath = Edit_GetText(GetDlgItem(hwnd, %IDCO_PBCOMBROWSERPATH))
                  pSed.TypeLibBrowserPath = Edit_GetText(GetDlgItem(hwnd, %IDCO_TYPELIBBROWSERPATH))
                  pSed.JRSIncPath1 = Edit_GetText(GetDlgItem(hwnd, %IDCO_JRSINCPATH1))
                  pSed.JRSIncPath2 = Edit_GetText(GetDlgItem(hwnd, %IDCO_JRSINCPATH2))
                  pSed.PBIncPath1 = Edit_GetText(GetDlgItem(hwnd, %IDCO_PBINCPATH1))
                  pSed.PBIncPath2 = Edit_GetText(GetDlgItem(hwnd, %IDCO_PBINCPATH2))
                  pSed.VisualDesignerPath = Edit_GetText(GetDlgItem(hwnd, %IDCO_VISDESPATH))
                  pSed.IconEditorPath = Edit_GetText(GetDlgItem(hwnd, %IDCO_ICONEDITORPATH))
                  pSed.ImageEditorPath = Edit_GetText(GetDlgItem(hwnd, %IDCO_IMAGEEDITORPATH))
                  pSed.PBWinHelpPath = Edit_GetText(GetDlgItem(hwnd, %IDCO_PBWINHELPPATH))
                  pSed.PBCCHelpPath = Edit_GetText(GetDlgItem(hwnd, %IDCO_PBCCHELPPATH))
                  pSed.SDKHelpPath = Edit_GetText(GetDlgItem(hwnd, %IDCO_SDKHELPPATH))
                  pSed.DebugToolPath = Edit_GetText(GetDlgItem(hwnd, %IDCO_DEBUGTOOLPATH))
                  pSed.PowerLibPath = Edit_GetText(GetDlgItem(hwnd, %IDCO_POWERLIBPATH))
                  ' // Check menu options
                  CSED_CheckMenuOptions(pSed.hMenu)
                  SendMessage hwnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF

            CASE %IDBO_PBWINPATH
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  szPath = CSED_SearchForExePath(hwnd)
                  IF LEN(szPath) THEN SetWindowText GetDlgItem(hwnd, %IDCO_PBWINPATH), szPath
                  SetFocus GetDlgItem(hwnd, %IDCO_PBWINPATH)
                  EXIT FUNCTION
               END IF

            CASE %IDBO_PBCCPATH
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  szPath = CSED_SearchForExePath(hwnd)
                  IF LEN(szPath) THEN SetWindowText GetDlgItem(hwnd, %IDCO_PBCCPATH), szPath
                  SetFocus GetDlgItem(hwnd, %IDCO_PBCCPATH)
                  EXIT FUNCTION
               END IF

            CASE %IDBO_RCPATH
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  szPath = CSED_SearchForExePath(hwnd)
                  IF LEN(szPath) THEN SetWindowText GetDlgItem(hwnd, %IDCO_RCPATH), szPath
                  SetFocus GetDlgItem(hwnd, %IDCO_RCPATH)
                  EXIT FUNCTION
               END IF

            CASE %IDBO_PBFORMSPATH
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  szPath = CSED_SearchForExePath(hwnd)
                  IF LEN(szPath) THEN SetWindowText GetDlgItem(hwnd, %IDCO_PBFORMSPATH), szPath
                  SetFocus GetDlgItem(hwnd, %IDCO_PBFORMSPATH)
                  EXIT FUNCTION
               END IF

            CASE %IDBO_PBCOMBROWSERPATH
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  szPath = CSED_SearchForExePath(hwnd)
                  IF LEN(szPath) THEN SetWindowText GetDlgItem(hwnd, %IDCO_PBCOMBROWSERPATH), szPath
                  SetFocus GetDlgItem(hwnd, %IDCO_PBCOMBROWSERPATH)
                  EXIT FUNCTION
               END IF

            CASE %IDBO_TYPELIBBROWSERPATH
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  szPath = CSED_SearchForExePath(hwnd)
                  IF LEN(szPath) THEN SetWindowText GetDlgItem(hwnd, %IDCO_TYPELIBBROWSERPATH), szPath
                  SetFocus GetDlgItem(hwnd, %IDCO_TYPELIBBROWSERPATH)
                  EXIT FUNCTION
               END IF

            CASE %IDBO_JRSINCPATH1
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  IF ISNULL(strDir) THEN strDir = CURDIR$
                  strDir = AfxBrowseForFolder(hwnd, "Choose a folder", strDir)
                  IF LEN(strDir) THEN
                     GetWindowText GetDlgItem(hwnd, %IDCO_JRSINCPATH1), szPath, SIZEOF(szPath)
                     IF LEN(szPath) THEN
                        szPath = szPath & ";" & strDir
                     ELSE
                        szPath = strDir
                     END IF
                     SetWindowText GetDlgItem(hwnd, %IDCO_JRSINCPATH1), szPath
                  END IF
                  EXIT FUNCTION
               END IF

            CASE %IDBO_JRSINCPATH2
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  IF ISNULL(strDir) THEN strDir = CURDIR$
                  strDir = AfxBrowseForFolder(hwnd, "Choose a folder", strDir)
                  IF LEN(strDir) THEN
                     GetWindowText GetDlgItem(hwnd, %IDCO_JRSINCPATH2), szPath, SIZEOF(szPath)
                     IF LEN(szPath) THEN
                        szPath = szPath & ";" & strDir
                     ELSE
                        szPath = strDir
                     END IF
                     SetWindowText GetDlgItem(hwnd, %IDCO_JRSINCPATH2), szPath
                  END IF
                  EXIT FUNCTION
               END IF

            CASE %IDBO_PBINCPATH1
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  IF ISNULL(strDir) THEN strDir = CURDIR$
                  strDir = AfxBrowseForFolder(hwnd, "Choose a folder", strDir)
                  IF LEN(strDir) THEN
                     GetWindowText GetDlgItem(hwnd, %IDCO_PBINCPATH1), szPath, SIZEOF(szPath)
                     IF LEN(szPath) THEN
                        szPath = szPath & ";" & strDir
                     ELSE
                        szPath = strDir
                     END IF
                     SetWindowText GetDlgItem(hwnd, %IDCO_PBINCPATH1), szPath
                  END IF
                  EXIT FUNCTION
               END IF

            CASE %IDBO_PBINCPATH2
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  IF ISNULL(strDir) THEN strDir = CURDIR$
                  strDir = AfxBrowseForFolder(hwnd, "Choose a folder", strDir)
                  IF LEN(strDir) THEN
                     GetWindowText GetDlgItem(hwnd, %IDCO_PBINCPATH2), szPath, SIZEOF(szPath)
                     IF LEN(szPath) THEN
                        szPath = szPath & ";" & strDir
                     ELSE
                        szPath = strDir
                     END IF
                     SetWindowText GetDlgItem(hwnd, %IDCO_PBINCPATH2), szPath
                  END IF
                  EXIT FUNCTION
               END IF

            CASE %IDBO_VISDESPATH
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  szPath = CSED_SearchForExePath(hwnd)
                  IF LEN(szPath) THEN SetWindowText GetDlgItem(hwnd, %IDCO_VISDESPATH), szPath
                  SetFocus GetDlgItem(hwnd, %IDCO_VISDESPATH)
                  EXIT FUNCTION
               END IF

            CASE %IDBO_ICONEDITORPATH
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  szPath = CSED_SearchForExePath(hwnd)
                  IF LEN(szPath) THEN SetWindowText GetDlgItem(hwnd, %IDCO_ICONEDITORPATH), szPath
                  SetFocus GetDlgItem(hwnd, %IDCO_ICONEDITORPATH)
                  EXIT FUNCTION
               END IF

            CASE %IDBO_IMAGEEDITORPATH
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  szPath = CSED_SearchForExePath(hwnd)
                  IF LEN(szPath) THEN SetWindowText GetDlgItem(hwnd, %IDCO_IMAGEEDITORPATH), szPath
                  SetFocus GetDlgItem(hwnd, %IDCO_IMAGEEDITORPATH)
                  EXIT FUNCTION
               END IF

            CASE %IDBO_DEBUGTOOLPATH
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  szPath = CSED_SearchForExePath(hwnd)
                  IF LEN(szPath) THEN SetWindowText GetDlgItem(hwnd, %IDCO_DEBUGTOOLPATH), szPath
                  SetFocus GetDlgItem(hwnd, %IDCO_DEBUGTOOLPATH)
                  EXIT FUNCTION
               END IF

            CASE %IDBO_POWERLIBPATH
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  szPath = CSED_SearchForExePath(hwnd)
                  IF LEN(szPath) THEN SetWindowText GetDlgItem(hwnd, %IDCO_POWERLIBPATH), szPath
                  SetFocus GetDlgItem(hwnd, %IDCO_POWERLIBPATH)
                  EXIT FUNCTION
               END IF

            CASE %IDBO_PBWINHELPPATH
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  szPath = CSED_SearchForHelpFilePath(hwnd)
                  IF LEN(szPath) THEN SetWindowText GetDlgItem(hwnd, %IDCO_PBWINHELPPATH), szPath
                  SetFocus GetDlgItem(hwnd, %IDCO_PBWINHELPPATH)
                  EXIT FUNCTION
               END IF

            CASE %IDBO_PBCCHELPPATH
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  szPath = CSED_SearchForHelpFilePath(hwnd)
                  IF LEN(szPath) THEN SetWindowText GetDlgItem(hwnd, %IDCO_PBCCHELPPATH), szPath
                  SetFocus GetDlgItem(hwnd, %IDCO_PBCCHELPPATH)
                  EXIT FUNCTION
               END IF

            CASE %IDBO_SDKHELPPATH
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  szPath = CSED_SearchForHelpFilePath(hwnd)
                  IF LEN(szPath) THEN SetWindowText GetDlgItem(hwnd, %IDCO_SDKHELPPATH), szPath
                  SetFocus GetDlgItem(hwnd, %IDCO_SDKHELPPATH)
                  EXIT FUNCTION
               END IF

            CASE %IDBO_COMPILEROPT_HELP
               szPath = EXE.Path$ & "CSED.CHM"
               szText = "Compiler Options"
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
