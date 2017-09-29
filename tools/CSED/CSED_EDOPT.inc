' ########################################################################################
' CSED Editor
' File: CSED_EDOPT.INC
' Contents: Editor options dialog
' Copyright (c) 2012 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ========================================================================================
' Editor Options popup dialog
' ========================================================================================
SUB CSED_EditorOptionsDialog (BYVAL hParent AS DWORD)

   ' // Create an instance of the class
   LOCAL pEdOpt AS IWindow
   pEdOpt = CLASS "CWindow"
   IF ISNOTHING(pEdOpt) THEN EXIT SUB

   ' // Create the main window
   LOCAL hwnd AS DWORD
'   hwnd = pEdOpt.CreateWindow(hParent, "Editor Options", 0, 0, 760, 485, _
'          %WS_VISIBLE OR %WS_CAPTION OR %WS_POPUPWINDOW, %WS_EX_TOOLWINDOW OR %WS_EX_WINDOWEDGE, _
'          CODEPTR(CSED_EdOpt_WindowProc))
   hwnd = pEdOpt.CreateWindow(hParent, "Editor Options", 0, 0, 0, 0, _
          %WS_VISIBLE OR %WS_CAPTION OR %WS_POPUPWINDOW, %WS_EX_WINDOWEDGE, _
          CODEPTR(CSED_EdOpt_WindowProc))
   pEdOpt.SetClientSize 750, 460
   pEdOpt.CenterWindow(hwnd, hParent)

   ' // Add the controls
   LOCAL i AS LONG
   LOCAL hCtl AS DWORD

   hCtl = pEdOpt.AddGroupBox(hwnd, -1, "Edit preferences", 15, 10, 464, 394, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_USETABS, "Use tabs", 33, 33, 210, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_AUTOINDENT, "Auto indentation", 33, 57, 210, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_LINENUMBERS, "Line numbers", 33, 81, 210, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_MARGIN, "Margin", 33, 104, 210, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_EDGECOLUMN, "Edge column", 33, 128, 210, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_INDENTGUIDES, "Indentation guides", 33, 152, 210, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_WHITESPACE, "Whitespace", 33, 176, 210, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_ENDOFLINE, "End of line", 33, 198, 210, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_SYNTAXHIGH, "Color syntax highlighting", 33, 220, 210, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_CODETIPS, "Code tips", 33, 242, 210, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_AUTOCONSTRUCT, "Autocomplete constructs", 33, 264, 210, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_TRIMTRAILBLANKS, "Trim trailing blanks", 33, 286, 210, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_SHOWCARETLINE, "Show caret line", 33, 308, 210, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_PASTECVTEOLS, "Convert endings when pasting", 33, 331, 210, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_MULTIPLESELECTION, "Multiple selection", 33, 353, 210, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_SHOWPROCNAME, "Show procedure name", 33, 374, 210, 16, -1)

   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_MAXMAINWINDOW, "Maximize main window", 252, 33, 210, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_MAXEDITWINDOWS, "Maximize edit windows", 252, 57, 210, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_ASKBEFOREEXIT, "Ask before exiting the editor", 252, 81, 210, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_RELOADFILESATSTARTUP, "Reload previous file set at start", 252, 104, 210, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_BACKUPEDITORFILES, "Backup editor files", 252, 128, 210, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_ADDDATETIME, "Add date/time to backup files", 252, 152, 220, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_SAVEBACKUPFILESTODATABASE, "Save backup files to database", 252, 176, 220, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_STARTINLASTFOLDER, "Start in last folder", 252, 198, 210, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_ALLOWMULTINST, "Allow multiple instances", 252, 220, 210, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_UTF8UNICODE, "Enable unicode (UTF-8 encoding)", 252, 242, 210, 16, -1)

   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_SAVEBOOKMARKS, "Save/Restore bookmarks", 252, 331, 210, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_SAVEWINPLA, "Save/Restore window placement", 252, 353, 210, 16, -1)
   hCtl = pEdOpt.AddCheckBox(hwnd, %IDCO_USEMSDNHELP, "Use Platform SDK help", 252, 374, 210, 16, -1)

   hCtl = pEdOpt.AddGroupBox(hwnd, -1, "Default case", 490, 10, 248, 100, -1)
   hCtl = pEdOpt.AddRadioButton(hwnd, %IDCO_DEFAULT_MIXEDCASE, "Original case", 500, 35, 150, 16, %WS_GROUP)
   hCtl = pEdOpt.AddRadioButton(hwnd, %IDCO_DEFAULT_UPPERCASE, "Upper case", 500, 59, 150, 16, -1)
   hCtl = pEdOpt.AddRadioButton(hwnd, %IDCO_DEFAULT_LOWERCASE, "Lower case", 500, 83, 150, 16, -1)

   hCtl = pEdOpt.AddGroupBox(hwnd, -1, "Keyword case", 490, 115, 248, 100, -1)
   hCtl = pEdOpt.AddRadioButton(hwnd, %IDCO_KEYWORD_MIXEDCASE, "Original case", 500, 140, 150, 16, %WS_GROUP)
   hCtl = pEdOpt.AddRadioButton(hwnd, %IDCO_KEYWORD_UPPERCASE, "Upper case", 500, 165, 150, 16, -1)
   hCtl = pEdOpt.AddRadioButton(hwnd, %IDCO_KEYWORD_LOWERCASE, "Lower case", 500, 190, 150, 16, -1)

   hCtl = pEdOpt.AddGroupBox(hwnd, -1, "", 490, 220, 248, 184, -1)
   hCtl = pEdOpt.AddLabel(hwnd, -1, "Tab size", 500, 240, 100, 16, -1)
   hCtl = pEdOpt.AddComboBox(hwnd, %IDCO_CBTABSIZE, "ComboBox", 655, 238, 42, 160, -1)
   FOR i = 0 TO 8
      Combobox_AddString hCtl, FORMAT$(i)
   NEXT
   hCtl = pEdOpt.AddLabel(hwnd, -1, "Indent size", 500, 265, 100, 16, -1)
   hCtl = pEdOpt.AddComboBox(hwnd, %IDCO_CBINDENTSIZE, "ComboBox", 655, 263, 42, 160, -1)
   FOR i = 0 TO 8
      Combobox_AddString hCtl, FORMAT$(i)
   NEXT
   hCtl = pEdOpt.AddLabel(hwnd, -1, "Line numbers width", 500, 290, 100, 16, -1)
   hCtl = pEdOpt.AddTextBox(hwnd, %IDCO_LINENUMBERSWIDTH, "", 655, 288, 42, 21, %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %ES_RIGHT OR %ES_NUMBER OR %ES_AUTOHSCROLL, -1)
   SendMessage hCtl, %EM_LIMITTEXT, 3, 0
   hCtl = pEdOpt.AddLabel(hwnd, -1, "Margin width", 500, 315, 100, 16, -1)
   hCtl = pEdOpt.AddTextBox(hwnd, %IDCO_MARGINWIDTH, "", 655, 313, 42, 21, %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %ES_RIGHT OR %ES_NUMBER OR %ES_AUTOHSCROLL, -1)
   SendMessage hCtl, %EM_LIMITTEXT, 2, 0
   hCtl = pEdOpt.AddLabel(hwnd, -1, "Edge column", 500, 339, 100, 16, -1)
   hCtl = pEdOpt.AddTextBox(hwnd, %IDCO_EDGEWIDTH, "", 655, 338, 42, 21, %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %ES_RIGHT OR %ES_NUMBER OR %ES_AUTOHSCROLL, -1)
   SendMessage hCtl, %EM_LIMITTEXT, 3, 0
   hCtl = pEdOpt.AddLabel(hwnd, -1, "Magnification", 500, 364, 150, 16, -1)
   hCtl = pEdOpt.AddTextBox(hwnd, %IDCO_BUDDY, "", 530, 364, 25, 20, %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %ES_RIGHT OR %ES_NUMBER OR %ES_AUTOHSCROLL, -1)
   SendMessage hCtl, %EM_LIMITTEXT, 2, 0
   SetDlgItemInt hwnd, %IDCO_BUDDY, 0, %FALSE
   hCtl = pEdOpt.AddUpDown(hwnd, %IDCO_MAGNIFICATION, "", 669, 364, 10, 20, %WS_CHILD OR %WS_VISIBLE OR %WS_BORDER OR %UDS_WRAP OR %UDS_ARROWKEYS OR %UDS_ALIGNRIGHT OR %UDS_SETBUDDYINT)
   ' // Set the base
   SendMessage hCtl, %UDM_SETBASE, 1, 0
   ' // Set the range
   SendMessage hCtl, %UDM_SETRANGE, 0, MAK(LONG, 20, -10)
   ' // Set the initial value
   SendMessage hCtl, %UDM_SETPOS, 0, 0
   ' // Set the buddy control
   SendMessage hCtl, %UDM_SETBUDDY, GetDlgItem(hwnd, %IDCO_BUDDY), 0
   ' // Correct for Windows using a default size for the updown control
   pEdOpt.SetWindowPos hCtl, %NULL, 679, 364, 18, 20, %SWP_NOZORDER
   ' // Correction for the auto-resizing of the buddy control
'   SetWindowPos GetDlgItem(hwnd, %IDCO_BUDDY), %NULL, 654 * pEdOpt.rxRatio, 364 * pEdOpt.ryRatio, 25, 20, %SWP_NOZORDER
   pEdopt.SetWindowPos GetDlgItem(hwnd, %IDCO_BUDDY), %NULL, 654, 364, 25, 20, %SWP_NOZORDER

   hCtl = pEdOpt.AddGroupBox(hwnd, -1, "Find in Files Tool Path", 15, 408, 464, 45, -1)
   hCtl = pEdOpt.AddTextBox(hwnd, %IDCO_FINDINFILESTOOLPATH, "", 22, 426, 418, 21, -1, %WS_EX_CLIENTEDGE)
   hCtl = pEdOpt.AddButton(hwnd, %IDBO_FINDINFILESTOOLPATH, "...", 445, 426, 28, 21, %BS_FLAT)

   hCtl = pEdOpt.AddButton(hwnd, %IDOK, "&Ok", 490, 420, 75, 24, %BS_DEFPUSHBUTTON)
   hCtl = pEdOpt.AddButton(hwnd, %IDCANCEL, "&Cancel", 575, 420, 78, 24, -1)
   hCtl = pEdOpt.AddButton(hwnd, %IDBO_EDITOR_HELP, "&Help", 664, 420, 75, 24, -1)

   ' // Set the options
   CheckDlgButton hwnd, %IDCO_USETABS, pSed.UseTabs
   ComboBox_SetCurSel(GetDlgItem(hwnd, %IDCO_CBTABSIZE), pSed.TabSize)
   CheckDlgButton hwnd, %IDCO_AUTOINDENT, pSed.AutoIndent
   ComboBox_SetCurSel(GetDlgItem(hwnd, %IDCO_CBINDENTSIZE), pSed.IndentSize)
   CheckDlgButton hwnd, %IDCO_LINENUMBERS, pSed.LineNumbers
   SetWindowText GetDlgItem(hwnd, %IDCO_LINENUMBERSWIDTH), FORMAT$(pSed.LineNumbersWidth)
   CheckDlgButton hwnd, %IDCO_MARGIN, pSed.Margin
   SetWindowText GetDlgItem(hwnd, %IDCO_MARGINWIDTH), FORMAT$(pSed.MarginWidth)
   CheckDlgButton hwnd, %IDCO_EDGECOLUMN, pSed.EdgeColumn
   SetWindowText GetDlgItem(hwnd, %IDCO_EDGEWIDTH), FORMAT$(pSed.EdgeWidth)
   CheckDlgButton hwnd, %IDCO_INDENTGUIDES, pSed.IndentGuides
   CheckDlgButton hwnd, %IDCO_WHITESPACE, pSed.WhiteSpace
   CheckDlgButton hwnd, %IDCO_ENDOFLINE, pSed.EndOfLine
   SetWindowText GetDlgItem(hwnd, %IDCO_BUDDY), FORMAT$(pSed.Magnification)
   CheckDlgButton hwnd, %IDCO_SYNTAXHIGH, pSed.SyntaxHighlighting
   CheckDlgButton hwnd, %IDCO_CODETIPS, pSed.CodeTips
   CheckDlgButton hwnd, %IDCO_MAXMAINWINDOW, pSed.MaximizeMainWindow
   CheckDlgButton hwnd, %IDCO_MAXEDITWINDOWS, pSed.MaximizeEditWindows
   CheckDlgButton hwnd, %IDCO_ASKBEFOREEXIT, pSed.AskBeforeExit
   CheckDlgButton hwnd, %IDCO_ALLOWMULTINST, pSed.AllowMultipleInstances
   CheckDlgButton hwnd, %IDCO_AUTOCONSTRUCT, pSed.ConstructAutocompletion
   CheckDlgButton hwnd, %IDCO_TRIMTRAILBLANKS, pSed.TrimTrailingBlanks
   CheckDlgButton hwnd, %IDCO_SHOWPROCNAME, pSed.ShowProcedureName
   CheckDlgButton hwnd, %IDCO_SHOWCARETLINE, pSed.ShowCaretLine
   CheckDlgButton hwnd, %IDCO_STARTINLASTFOLDER, pSed.StartInLastFolder
   CheckDlgButton hwnd, %IDCO_RELOADFILESATSTARTUP, pSed.ReloadFilesAtStartup
   CheckDlgButton hwnd, %IDCO_BACKUPEDITORFILES, pSed.BackupEditorFiles
   CheckDlgButton hwnd, %IDCO_ADDDATETIME, pSed.AddDateTimeToBackupFiles
   CheckDlgButton hwnd, %IDCO_SAVEBACKUPFILESTODATABASE, pSed.SaveBackupFilesToDatabase
   CheckDlgButton hwnd, %IDCO_SAVEBOOKMARKS, pSed.SaveBookmarksToFile
   CheckDlgButton hwnd, %IDCO_SAVEWINPLA, pSed.WindowPlacement
   CheckDlgButton hwnd, %IDCO_USEMSDNHELP, pSed.UseMSDNHelp
   CheckDlgButton hwnd, %IDCO_PASTECVTEOLS, pSed.PasteConvertEndings
   CheckDlgButton hwnd, %IDCO_MULTIPLESELECTION, pSed.MultipleSelection
   CheckDlgButton hwnd, %IDCO_UTF8UNICODE, pSed.UnicodeEnabled
   Edit_SetText GetDlgItem(hwnd, %IDCO_FINDINFILESTOOLPATH), pSed.FindInFilesToolPath

   SELECT CASE pSed.DefaultCase
      CASE 1
         CheckDlgButton hwnd, %IDCO_DEFAULT_UPPERCASE, %BST_CHECKED
      CASE 2
         CheckDlgButton hwnd, %IDCO_DEFAULT_LOWERCASE, %BST_CHECKED
      CASE ELSE
         CheckDlgButton hwnd, %IDCO_DEFAULT_MIXEDCASE, %BST_CHECKED
   END SELECT

   SELECT CASE pSed.KeywordCase
      CASE 1
         CheckDlgButton hwnd, %IDCO_KEYWORD_UPPERCASE, %BST_CHECKED
      CASE 2
         CheckDlgButton hwnd, %IDCO_KEYWORD_LOWERCASE, %BST_CHECKED
      CASE ELSE
         CheckDlgButton hwnd, %IDCO_KEYWORD_MIXEDCASE, %BST_CHECKED
   END SELECT

   ' // Default message pump (you can replace it with your own)
   pEdOpt.DoEvents

END SUB
' ========================================================================================

' ========================================================================================
' Editor options callback function.
' ========================================================================================
FUNCTION CSED_EdOpt_WindowProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL tProc  AS CSED_PROCSTRUCT
#IF %DEF(%UNICODE)
   LOCAL szText AS WSTRINGZ * 255                ' // General purpose variable
   LOCAL szPath AS WSTRINGZ * %MAX_PATH          ' // File path
#ELSE
   LOCAL szText AS ASCIIZ * 255                  ' // General purpose variable
   LOCAL szPath AS ASCIIZ * %MAX_PATH            ' // File path
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
                  pSed.UseTabs = IsDlgButtonChecked(hwnd, %IDCO_USETABS)
                  pSed.TabSize = VAL(ComboBox_GetLbText(GetDlgItem(hwnd, %IDCO_CBTABSIZE), -1))
                  pSed.AutoIndent = IsDlgButtonChecked(hwnd, %IDCO_AUTOINDENT)
                  pSed.IndentSize = VAL(ComboBox_GetLbText(GetDlgItem(hwnd, %IDCO_CBINDENTSIZE), -1))
                  pSed.LineNumbers = IsDlgButtonChecked(hwnd, %IDCO_LINENUMBERS)
                  pSed.LineNumbersWidth = VAL(AfxGetWindowText(GetDlgItem(hwnd, %IDCO_LINENUMBERSWIDTH)))
                  pSed.Margin = IsDlgButtonChecked(hwnd, %IDCO_MARGIN)
                  pSed.MarginWidth = VAL(AfxGetWindowText(GetDlgItem(hwnd, %IDCO_MARGINWIDTH)))
                  pSed.EdgeColumn = IsDlgButtonChecked(hwnd, %IDCO_EDGECOLUMN)
                  pSed.EdgeWidth = VAL(AfxGetWindowText(GetDlgItem(hwnd, %IDCO_EDGEWIDTH)))
                  pSed.IndentGuides = IsDlgButtonChecked(hwnd, %IDCO_INDENTGUIDES)
                  pSed.WhiteSpace = IsDlgButtonChecked(hwnd, %IDCO_WHITESPACE)
                  pSed.EndOfLine = IsDlgButtonChecked(hwnd, %IDCO_ENDOFLINE)
                  IF IsDlgButtonChecked(hwnd, %IDCO_DEFAULT_UPPERCASE) = %BST_CHECKED THEN
                     pSed.DefaultCase = 1
                  ELSEIF IsDlgButtonChecked(hwnd, %IDCO_DEFAULT_LOWERCASE) = %BST_CHECKED THEN
                     pSed.DefaultCase = 2
                  ELSE
                     pSed.DefaultCase = 0
                  END IF
                  IF IsDlgButtonChecked(hwnd, %IDCO_KEYWORD_UPPERCASE) = %BST_CHECKED THEN
                     pSed.KeywordCase = 1
                  ELSEIF IsDlgButtonChecked(hwnd, %IDCO_KEYWORD_LOWERCASE) = %BST_CHECKED THEN
                     pSed.KeywordCase = 2
                  ELSE
                     pSed.KeywordCase = 0
                  END IF
                  pSed.Magnification = VAL(AfxGetWindowText(GetDlgItem(hwnd, %IDCO_BUDDY)))
                  SCI_SetZoom pSed.hEdit, pSed.Magnification
                  pSed.SyntaxHighlighting = IsDlgButtonChecked(hwnd, %IDCO_SYNTAXHIGH)
                  pSed.CodeTips = IsDlgButtonChecked(hwnd, %IDCO_CODETIPS)
                  pSed.MaximizeMainWindow = IsDlgButtonChecked(hwnd, %IDCO_MAXMAINWINDOW)
                  pSed.MaximizeEditWindows = IsDlgButtonChecked(hwnd, %IDCO_MAXEDITWINDOWS)
                  pSed.AskBeforeExit = IsDlgButtonChecked(hwnd, %IDCO_ASKBEFOREEXIT)
                  pSed.AllowMultipleInstances = IsDlgButtonChecked(hwnd, %IDCO_ALLOWMULTINST)
                  pSed.ConstructAutocompletion = IsDlgButtonChecked(hwnd, %IDCO_AUTOCONSTRUCT)
                  pSed.TrimTrailingBlanks = IsDlgButtonChecked(hwnd, %IDCO_TRIMTRAILBLANKS)
                  pSed.PasteConvertEndings = IsDlgButtonChecked(hwnd, %IDCO_PASTECVTEOLS)
                  pSed.MultipleSelection = IsDlgButtonChecked(hwnd, %IDCO_MULTIPLESELECTION)
                  pSed.ShowProcedureName = IsDlgButtonChecked(hwnd, %IDCO_SHOWPROCNAME)
                  pSed.UnicodeEnabled = IsDlgButtonChecked(hwnd, %IDCO_UTF8UNICODE)
                  ' // Show the procedure name in the statusbar
                  CSED_ResetCodefinder(pSed.hCodeFinderCB)
                  IF pSed.ShowProcedureName THEN
                     CSED_WithinProc(tProc)
                     StatusBar_SetText pSed.hStatusbar, 4, tProc.ProcName
                  ELSE
                     StatusBar_SetText pSed.hStatusbar, 4, ""
                  END IF
                  pSed.ShowCaretLine = IsDlgButtonChecked(hwnd, %IDCO_SHOWCARETLINE)
                  pSed.StartInLastFolder = IsDlgButtonChecked(hwnd, %IDCO_STARTINLASTFOLDER)
                  pSed.ReloadFilesAtStartup = IsDlgButtonChecked(hwnd, %IDCO_RELOADFILESATSTARTUP)
                  pSed.BackupEditorFiles = IsDlgButtonChecked(hwnd, %IDCO_BACKUPEDITORFILES)
                  pSed.AddDateTimeToBackupFiles = IsDlgButtonChecked(hwnd, %IDCO_ADDDATETIME)
                  pSed.SaveBackupFilesToDatabase = IsDlgButtonChecked(hwnd, %IDCO_SAVEBACKUPFILESTODATABASE)
                  pSed.SaveBookmarksToFile = IsDlgButtonChecked(hwnd, %IDCO_SAVEBOOKMARKS)
                  pSed.WindowPlacement = IsDlgButtonChecked(hwnd, %IDCO_SAVEWINPLA)
                  pSed.UseMSDNHelp = IsDlgButtonChecked(hwnd, %IDCO_USEMSDNHELP)
                  pSed.FindInFilesToolPath = Edit_GetText(GetDlgItem(hwnd, %IDCO_FINDINFILESTOOLPATH))
                  ' // Check menu options
                  CSED_CheckMenuOptions(pSed.hMenu)
                  ' // Retrieve the name again and set the control options
                  szPath = AfxGetWindowText(GetParent(pSed.hEdit))
                  IF LEN(szPath) THEN
                     CSED_SetScintillaOptions(pSed.hEdit, PATHNAME$(EXTN, szPath))
                  END IF
                  SendMessage hwnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF

            CASE %IDBO_FINDINFILESTOOLPATH
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  szPath = CSED_SearchForExePath(hwnd)
                  IF LEN(szPath) THEN SetWindowText GetDlgItem(hwnd, %IDCO_FINDINFILESTOOLPATH), szPath
                  SetFocus GetDlgItem(hwnd, %IDCO_FINDINFILESTOOLPATH)
                  EXIT FUNCTION
               END IF

            CASE %IDBO_EDITOR_HELP
               szPath = EXE.Path$ & "CSED.CHM"
               szText = "Editor Options"
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
