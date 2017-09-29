' ########################################################################################
' CSED Editor
' File: CSED.BAS
' Contents: CSED editor main source file
' Copyright (c) 2011 José Roca
' All Rights Reserved.
' Compiler: PowerBASIC for Windows 10.01+
' Headers: Windows API Headers 2.02+
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#COMPILE EXE
#DIM ALL
%UNICODE = 1

' // Globals
GLOBAL pSed AS ISED   ' // Reference to the ISED interface

' // Constants
$PROGNAME      = "CSED"
$CSEDVERSION   = "1.03"
$CSEDCAPTION   = "CSED 1.03"
$CSEDCOPYRIGHT = "© 2011 by José Roca"
$MAILADDRESS   = "JRoca@com.it-berater.org"
$CODETIPSDB    = "CSED_CODETIPS.TRM"    ' // Codetips database name
$BACKUPSDB     = "CSED_BACKUPMGR.TRM"   ' // Backups database name

' // Icon identifiers
%IDI_PROGRAMICO  = 100
%IDI_EDITICO     = 101
%IDI_TABCLOSEICO = 102

' // Resource file
#RESOURCE RES, ".\Resources\CSED.RES"  ' // Editor resource file

' // Include files
%USEMDI = 1                            ' // Use MDI
%USEWEBBROWSER = 1                     ' // Use WebBrowser control

' ========================================================================================
' CSED tools record structure
' ========================================================================================
TYPE CSED_TOOLSTYPE
   strName   AS STRING * 64
   strPath   AS STRING * 256
   strParams AS STRING * 1023
   strMenu   AS STRING * 1
END TYPE
' ========================================================================================

' // Include files for external files
#INCLUDE ONCE "CWindow.inc"            ' // CWindow class
#INCLUDE ONCE "AfxWin.inc"             ' // Application Framework Extensions Library
#INCLUDE ONCE "AfxDlg.inc"             ' // Common dialogs
#INCLUDE ONCE "CommCtrl.inc"           ' // Common controls
#INCLUDE ONCE "ShlObj.inc"             ' // Windows shell
#INCLUDE ONCE "HtmlHelp.inc"           ' // HTML Help
#INCLUDE ONCE "vshelp.inc"             ' // DExplorer interfaces
#INCLUDE ONCE "Scintilla.inc"          ' // Scintilla edit control
#INCLUDE ONCE "TRM.inc"                ' // Tsunami Record Manager
#INCLUDE ONCE "AfxShell.inc"           ' // Shell wrapper functions

' // Include files for internal files
#INCLUDE ONCE "CSED_ENUMS.inc"         ' // Enumerations
#INCLUDE ONCE "CSED_CLASSES.inc"       ' // CSED and CFindReplace classes
#INCLUDE ONCE "CSED_TOOLBARS.inc"      ' // Toolbars
#INCLUDE ONCE "CSED_STATUSBAR.inc"     ' // Statusbar
#INCLUDE ONCE "CSED_TABCTRL.inc"       ' // Tab control
#INCLUDE ONCE "CSED_FILE.inc"          ' // File procedures
#INCLUDE ONCE "CSED_COMPILE.inc"       ' // Compilation related procedures
#INCLUDE ONCE "CSED_GOTOPROC.inc"      ' // Go to beginning/end procedure
#INCLUDE ONCE "CSED_SCI.inc"           ' // Scintilla related functions
#INCLUDE ONCE "CSED_HELP.inc"          ' // Context menu help
#INCLUDE ONCE "CSED_MENU.inc"          ' // Menu

' // Dialogs
#INCLUDE ONCE "CSED_GOTOLINE.inc"      ' // Go to line dialog
#INCLUDE ONCE "CSED_PRINT.inc"         ' // Printing
#INCLUDE ONCE "CSED_PBTPL.inc"         ' // Templates
#INCLUDE ONCE "CSED_RECENTFILES.inc"   ' // Recent files
#INCLUDE ONCE "CSED_EDOPT.inc"         ' // Editor options dialog
#INCLUDE ONCE "CSED_FOLDOPT.inc"       ' // Fold options dialog
#INCLUDE ONCE "CSED_CMPOPT.INC"        ' // Compiler options dialog
#INCLUDE ONCE "CSED_COLOROPT.inc"      ' // Colors and fonts dialog

' // Include files for wrapper functions
#INCLUDE ONCE "SciCtrl.inc"            ' // Scintilla edit control wrappers
#INCLUDE ONCE "ToolbarCtrl.inc"        ' // Toolbar control wrapper functions
#INCLUDE ONCE "StatusbarCtrl.inc"      ' // Status bar wrapper functions
#INCLUDE ONCE "TabCtrl.inc"            ' // Tab control wrapper functions
#INCLUDE ONCE "ComboBoxCtrl.inc"       ' // Combo box wrapper functions
#INCLUDE ONCE "ListBoxCtrl.inc"        ' // List box wrapper functions
#INCLUDE ONCE "EditCtrl.inc"           ' // Edit control wrapper functions
#INCLUDE ONCE "TreeViewCtrl.inc"       ' // TreeView control wrapper functions
#INCLUDE ONCE "CAfxImageList.inc"      ' // Image List class
#INCLUDE ONCE "GdipUtils.inc"          ' // GdiPlus wrapper functions

' ########################################################################################
' Main
' ########################################################################################
FUNCTION WinMain (BYVAL hInstance AS DWORD, BYVAL hPrevInstance AS DWORD, BYVAL lpszCmdLine AS WSTRINGZ PTR, BYVAL nCmdShow AS LONG) AS LONG

   ' // Create an instance of the CSED class
   pSed = CLASS "CSED"
   IF ISNOTHING(pSed) THEN EXIT FUNCTION

'   IF ISFALSE pSed.AllowMultipleInstances THEN
'      ' // Mutex to avoid multiple instances running
'      LOCAL hWindow AS DWORD
'      LOCAL hMutex AS DWORD
'#IF %DEF(%UNICODE)
'      LOCAL szMutex AS WSTRINGZ * 260
'#ELSE
'      LOCAL szMutex AS ASCIIZ * 260
'#ENDIF
'      szMutex = "CSED_MUTEX"
'      hMutex  = CreateMutex(BYVAL %NULL, %FALSE, szMutex)
'      IF ISTRUE hMutex THEN
'         IF GetLastError = %ERROR_ALREADY_EXISTS THEN
'            CloseHandle hMutex
'            ' // We can't use FindWindow because the caption of a MDI main window
'            ' // may include the path of the MDI active child windows, and we
'            ' // can't use the class name because all the CWindow main windows
'            ' // share the same class name.
'            EnumWindows(CODEPTR(CSED_EnumWindowsProc), VARPTR(hWindow))
'            IF hWindow THEN
'               SetForegroundWindow hWindow
'               CSED_ProcessCommandLine(hWindow)
'               FUNCTION = -1
'               EXIT FUNCTION
'            END IF
'         END IF
'      END IF
'   END IF

   IF ISFALSE pSed.AllowMultipleInstances THEN
      ' // We can't use FindWindow because the caption of a MDI main window
      ' // may include the path of the MDI active child windows, and we
      ' // can't use the class name because all the CWindow main windows
      ' // share the same class name.
      LOCAL hWindow AS DWORD
      EnumWindows(CODEPTR(CSED_EnumWindowsProc), VARPTR(hWindow))
      IF hWindow THEN
         SetForegroundWindow hWindow
         CSED_ProcessCommandLine(hWindow)
         FUNCTION = -1
         EXIT FUNCTION
      END IF
   END IF

   ' // Load Scintilla
   LOCAL hSciLib AS DWORD
   hSciLib = LoadLibrary(EXE.PATH$ & "SciLexer.dll")
   IF hSciLib = %NULL THEN EXIT FUNCTION

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' // Create the main window
   LOCAL hwndMain AS DWORD
   LOCAL rc AS RECT
      ' Retrieve the size of the working area
   SystemParametersInfo %SPI_GETWORKAREA, 0, rc, 0
   ' // Create the window
   hwndMain = pWindow.CreateWindow(%NULL, $CSEDCAPTION, _
              0, 0, rc.Right - rc.Left, rc.Bottom - rc.Top, -1, -1, CODEPTR(CSED_WindowProc), %TRUE)
   pSed.hwndMain = hwndMain
   ' // Change the class style to avoid the flicker caused by redrawing
   pWindow.ClassStyle = %CS_DBLCLKS
   ' // Center the window
   pWindow.CenterWindow hwndMain
   ' // Set the icons
   pWindow.BigIcon = LoadIcon(hInstance, BYVAL %IDI_PROGRAMICO)
   pWindow.SmallIcon = LoadIcon(hInstance, BYVAL %IDI_PROGRAMICO)

   ' // Create the toolbars
   CSED_CreateTopToolBar(pWindow)
   CSED_CreateBottomToolBar(pWindow)

   ' // Create the status bar
   CSED_CreateStatusBar(pWindow)
   CSED_ClearStatusBar

   ' // Create the menu
   CSED_CreateMenu(pWindow)
   ' // Get the recent files list
   CSED_RecentFilesMenu

   ' // Create the tab control for the MDI windows
   pSed.hTabMdi = CSED_CreateTabMdiCtrl(pWindow)

   ' // Create the MDI client window
   LOCAL hWindowMenu AS DWORD
   hWindowMenu = GetSubMenu(pSed.hMenu, 5)
   LOCAL hwndClient AS DWORD
   hwndClient = pWindow.CreateMDIWindow(101, 0, 0, 0, 0, -1, -1, hWindowMenu, CODEPTR(CSED_MDIWindowProc))
   pSed.hwndClient = hwndClient

   ' // Initialize PB keywords
   CSED_LoadPBKeywords(hwndMain)

   ' // Create the accelerator table
   LOCAL hAccel AS DWORD
   hAccel = CSED_CreateAcceleratorTable(pWindow)

   ' // Disable unusable toolbar buttons and menu items
   CSED_ChangeToolbarButtonsState
   CSED_ChangeMenuItemsState
   CSED_CheckMenuOptions(pSed.hMenu)

   ' // Enable drag and drop files
   DragAcceptFiles hwndMain, %TRUE

   ' // Read saved window's state and placement
   IF pSed.WindowPlacement THEN pSed.SetWindowPlacement(hwndMain)
   ' // Maximized state
   IF ISTRUE pSed.MaximizeMainWindow THEN ShowWindow hwndMain, %SW_MAXIMIZE

   ' // Show the main window
   ShowWindow hwndMain, nCmdShow
   UpdateWindow hwndMain

   ' // Load previous file set
   IF pSed.ReloadFilesAtStartup AND LEN(COMMAND$) = 0 THEN
      psed.LoadFileSet
   END IF

   ' // Start in last used folder
   IF pSed.StartInLastFolder AND LEN(pSed.LastFolder) THEN CHDIR pSed.LastFolder

   ' // If the command line isn't empty post a message to process it later
   IF LEN(COMMAND$) THEN PostMessage hwndMain, %WM_USER + 1000, 0, 0

   IF pSed.hEdit THEN SetFocus pSed.hEdit

   ' // Processes window messages
   LOCAL uMsg AS tagMsg
   WHILE GetMessage(uMsg, %NULL, 0, 0)
#IF %USEOLECON = 1
   ' Forwards the message to the OCX
   IF OC_ForwardMessage(GetFocus, uMsg) = 0 THEN
#ENDIF
#IF %USEMDI = 1
         ' // Processes accelerator keystrokes for window menu command
         ' // of the multiple document interface (MDI) child windows
         IF hwndClient = 0 OR TranslateMDISysAccel(hwndClient, uMsg) = 0 THEN
#ENDIF
            ' // Processes accelerator keys for menu commands
            IF pWindow.hAccel = 0 OR TranslateAccelerator(hwndMain, hAccel, uMsg) = 0 THEN
               ' // Needed to process Find and Find/Replace dialog messages
               IF pSed.FindReplaceObj.hFind = 0 OR ISFALSE IsDialogMessage(pSed.FindReplaceObj.hFind, uMsg) THEN
                  ' // Determines whether a message is intended for the specified
                  ' // dialog box and, if it is, processes the message.
                  IF IsDialogMessage(hwndMain, uMsg) = 0 THEN
                     ' // Translates virtual-key messages into character messages.
                     TranslateMessage uMsg
                     ' // Dispatches a message to a window procedure.
                     DispatchMessage uMsg
                  END IF
               END IF
            END IF
#IF %USEMDI = 1
         END IF
#ENDIF
#IF %USEOLECON = 1
      END IF
#ENDIF
   WEND
   FUNCTION = uMsg.wParam

   ' // Unload Scintilla
   IF hSciLib THEN FreeLibrary(hSciLib)

   pSed = NOTHING

END FUNCTION
' ########################################################################################

' ========================================================================================
' Callback function to enumerate the top-level windows
' ========================================================================================
FUNCTION CSED_EnumWindowsProc (BYVAL hwnd AS DWORD, BYVAL lParam AS DWORD PTR) AS LONG
   IF AfxGetWindowClassName(hwnd) = "PBWindowClass:0" AND _
      LEFT$(AfxGetWindowText(hwnd), LEN($CSEDCAPTION)) = $CSEDCAPTION THEN
      IF lParam <> %NULL THEN @lParam = hwnd
      FUNCTION = %FALSE
   ELSE
      FUNCTION = %TRUE
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the command line and processes it
' ========================================================================================
SUB CSED_ProcessCommandLine (BYVAL hwnd AS DWORD)

   LOCAL strFileName   AS STRING           ' // File name
   LOCAL strLineNumber AS STRING           ' // Line number
   LOCAL DataToSend    AS COPYDATASTRUCT   ' // Data to send structure

   IF ISFALSE hwnd THEN EXIT SUB

   IF IsIconic(hwnd) <> 0 OR IsZoomed(hwnd) <> 0 THEN ShowWindow hwnd, %SW_RESTORE
   SetForegroundWindow hwnd

   IF TRIM$(COMMAND$) = "" THEN EXIT SUB

   strLineNumber = RIGHT$(COMMAND$, LEN(COMMAND$) - INSTR(-1, COMMAND$, " "))
   IF LEN(TRIM$(strLineNumber, ANY "0123456789")) THEN
      strFileName = TRIM$(COMMAND$, ANY $DQ + $SPC)
   ELSE
      strFileName = TRIM$(LEFT$(COMMAND$, LEN(COMMAND$) - LEN(strLineNumber)), ANY $DQ + $SPC)
   END IF

   IF TRIM$(strFilename) = "" THEN EXIT SUB

'   IF strFileName <> "" AND PATHNAME$(PATH, strFileName) = "" THEN
'      CSED_MsgBox hwnd, "Missing path in file " & strFileName, %MB_OK OR %MB_ICONERROR, "Error"
'      EXIT SUB
'   END IF

   IF strFileName <> "" AND PATHNAME$(PATH, strFileName) = "" THEN strFileName = CURDIR$ & "\" & strFileName

   IF ISFALSE AfxFileExists(strFileName) THEN
      CSED_MsgBox hwnd, "Can't find the file " & strFileName, %MB_OK OR %MB_ICONERROR, "Error"
      EXIT SUB
   END IF

   DataToSend.lpData  = STRPTR(strFileName)
   DataToSend.cbdata  = LEN(strFileName) + 1
   DataToSend.dwData  = VAL(strLineNumber) - 1

   SendMessage hwnd, %WM_COPYDATA, LEN(DataToSend), VARPTR(DataToSend)
   IF pSed.hEdit THEN SCI_GotoLine(pSed.hEdit, VAL(strLineNumber) - 1)

END SUB
' ========================================================================================

' ========================================================================================
' Default CWindow callback function.
' ========================================================================================
FUNCTION CSED_WindowProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL r               AS LONG                   ' // Result code
   LOCAL hwndClient      AS DWORD                  ' // Handle of the MDI client window
   LOCAL hwndActive      AS DWORD                  ' // Active window
   LOCAL pnmhdr          AS NMHDR PTR              ' // Information about a notification message
   LOCAL hMdi            AS DWORD                  ' // MDI child window handle
   LOCAL hToolBar        AS DWORD                  ' // Toolbar handle
   LOCAL hBottomToolBar  AS DWORD                  ' // Toolbar handle
   LOCAL ptbn            AS TBNOTIFY PTR           ' // For toolbar notification messages
   LOCAL hTabMdi         AS DWORD                  ' // Tab control handle
   LOCAL hStatusBar      AS DWORD                  ' // Statusbar handle
   LOCAL rc              AS RECT                   ' // RECT structure
   LOCAL nTab            AS DWORD                  ' // Tab number
   LOCAL PID             AS DWORD                  ' // Process identifier
   LOCAL hCalc           AS DWORD                  ' // Calculator handle
   LOCAL curPos          AS LONG                   ' // Current position
   LOCAL endPos          AS LONG                   ' // Ending position
   LOCAL curSel          AS LONG                   ' // Current selection
   LOCAL pttdi           AS NMTTDISPINFO PTR       ' // Tooltip notification message information
   LOCAL strText         AS STRING                 ' // General purpose variable
   LOCAL strPath         AS STRING                 ' // File path
   LOCAL strFilePath     AS STRING                 ' // File path
   LOCAL vPath           AS VARIANT                ' // File path
   LOCAL pInfo           AS TCHITTESTINFO          ' // Information about a hit test
   LOCAL pt              AS POINT                  ' // Screen coordinates
   LOCAL tProc           AS CSED_PROCSTRUCT        ' // Proc structure
   LOCAL hTrackPopUpMenu AS DWORD                  ' // Track pop up menu handle
   LOCAL pWindow         AS IWindow                ' // Reference to the IWindow interface
   LOCAL pQueue          AS IQueueCollection       ' // Reference to the Queue collection
   LOCAL pTabFilePaths   AS ILinkListCollection    ' // File paths linked list
#IF %DEF(%UNICODE)
   LOCAL szTooltipText   AS WSTRINGZ * %MAX_PATH   ' // Tooltip text (uicode)
#ELSE
   LOCAL szTooltipText   AS ASCIIZ * %MAX_PATH     ' // Tooltip text
#ENDIF

   STATIC hFocus         AS DWORD                  ' // Handle of the control that has the focus
   STATIC dwFindMsg      AS DWORD                  ' // Registered message handle

   ' // Copy data (for Lynx support)
   LOCAL pDataToGet      AS COPYDATASTRUCT PTR     ' // Pointer to a CopyData structure
   LOCAL pszBuffer       AS ASCIIZ PTR             ' // Pointer to the buffer

   ' // Guides menu
   LOCAL hToolsFile     AS LONG                    ' // Tools file handle
   LOCAL RecordStr      AS STRING                  ' // Record string
   LOCAL tTools         AS CSED_TOOLSTYPE          ' // Tools structure

   ' // MDI client window handle
   hwndClient = CWindow_GetMDIClientHandle(hwnd)

   SELECT CASE uMsg

      CASE %WM_NCACTIVATE
         ' // Save the handle of the control that has the focus
         IF wParam = 0 THEN hFocus = GetFocus
         ' // Note: Don't use EXIT FUNCTION

      CASE %WM_SETFOCUS
         ' // Post a message to set the focus later, since some
         ' // Windows actions can steal it if we set it here
         IF hFocus THEN
            PostMessage hWnd, %WM_USER + 999, hFocus, 0
            hFocus = 0
         END IF

      CASE %WM_USER + 999
         ' // Set the focus and show the line an column in the status bar
         IF wParam THEN SetFocus wParam
         CSED_ShowLinCol   ' // Show line and column
         EXIT FUNCTION

      CASE %WM_USER + 1000
         ' // Process the command line
         CSED_ProcessCommandLine hwnd
         EXIT FUNCTION

      ' // This custom message is posted when the dropdown
      ' // list of the codefinder combobox is closed
      CASE %WM_USER + 1001
         ' // Reset the contents of the codefinder
         CSED_ResetCodefinder(pSed.hCodeFinderCB)
         ' // Return the focus to the edit control
         SetFocus pSed.hEdit
         EXIT FUNCTION

      CASE %WM_SYSCOMMAND
         ' // Capture this message and send a WM_CLOSE message
         IF (wParam AND &HFFF0) = %SC_CLOSE THEN
            SendMessage hwnd, %WM_CLOSE, 0, 0
            EXIT FUNCTION
         END IF

      CASE %WM_SYSCOLORCHANGE
         ' // Menu font size may have changed, so destroy old menu and create a
         ' // new one to use new font's measurements
         IF pSed.hMenu = 0 THEN pSed.hMenu = GetMenu(hwnd)
         IF pSed.hMenu THEN
            pWindow = CWindow_GetObjectFromWindowHandle(hwnd)
            IF ISOBJECT(pWindow) THEN
               DestroyMenu pSed.hMenu
               pSed.hMenu = CSED_CreateMenu(pWindow)
               pWindow = NOTHING
            END IF
         END IF
         ' // Forward this message to common controls so that they will
         ' // be properly updated if the user changes the color settings.
         SendMessage pSed.hToolbar, %WM_SYSCOLORCHANGE, wParam, lParam
         SendMessage pSed.hStatusbar, %WM_SYSCOLORCHANGE, wParam, lParam

      CASE %WM_DROPFILES
         ' // Retrieve the dropped file names
         pQueue = CSED_GetDroppedFiles(wParam)
         ' Open a new edit window for each of them
         IF ISOBJECT(pQueue) THEN
            IF pQueue.Count THEN
               DO
                  vPath = pQueue.Dequeue
                  IF OBJRESULT THEN EXIT DO
                  IF VARIANTVT(vPath) <> %VT_EMPTY THEN CSED_OpenFile(VARIANT$$(vPath))
               LOOP
            END IF
         END IF
         EXIT FUNCTION

      CASE %WM_COPYDATA
         ' // For Lynx support
         pDataToGet = lParam
         pszBuffer = @pDataToGet.lpData
         CSED_OpenFile TRIM$(@pszBuffer)
         SCI_GotoLine(pSed.hEdit, SCI_GetTextLength(pSed.hEdit))
         SCI_GotoLine(pSed.hEdit, @pDataToGet.dwData)

      CASE %WM_COMMAND

         SELECT CASE LO(WORD, wParam)

            CASE %IDCANCEL
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  SendMessage hwnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF

            ' *** FILE_MENU_BEGIN ***
            ' // New file
            CASE %IDM_NEW
               IF pSed.hEdit THEN UpdateWindow(pSed.hEdit)
               hMdi = CSED_CreateMdiChild("Untitled" & FORMAT$(pSed.UntitledFilesIdx) & ".bas")
               CSED_ResetCodeFinder(pSed.hCodeFinderCB)
               ShowWindow hMdi, %SW_SHOW
               EXIT FUNCTION

             ' // Insert file
            CASE %IDM_INSERTFILE
               IF pSed.hEdit THEN UpdateWindow(pSed.hEdit)
               CSED_InsertFile hwnd
               EXIT FUNCTION

            ' // Open file
            CASE %IDM_OPEN
               CSED_OpenFileDialog(hwnd)
               CSED_ChangeToolbarButtonsState
               CSED_ChangeMenuItemsState
               EXIT FUNCTION

            ' // Open recent file
            CASE %IDM_RECENTFILE1 TO %IDM_RECENTFILE9
               CSED_OpenRecentFile wParam
               EXIT FUNCTION

            ' // Save
            CASE %IDM_SAVE
               IF pSed.hEdit THEN UpdateWindow(pSed.hEdit)
               CSED_SaveFile hwnd, pSed.hEdit, %FALSE
               CSED_ChangeToolbarButtonsState
               CSED_ChangeMenuItemsState
               EXIT FUNCTION

            ' // Save as
            CASE %IDM_SAVEAS
               IF pSed.hEdit THEN UpdateWindow(pSed.hEdit)
               CSED_SaveFile hwnd, pSed.hEdit, %TRUE
               CSED_ChangeToolbarButtonsState
               CSED_ChangeMenuItemsState
               EXIT FUNCTION

            ' // Save all files
            CASE %IDM_SAVEALL
               IF pSed.hEdit THEN UpdateWindow(pSed.hEdit)
               CSED_SaveLoadedFiles hwnd
               CSED_ChangeMenuItemsState
               EXIT FUNCTION

            ' // Close file
            CASE %IDM_CLOSEFILE, %IDM_CLOSEWINDOW
               IF pSed.hEdit THEN UpdateWindow(pSed.hEdit)
               ' // Get the path of the file from the window caption
               strPath = AfxGetWindowText(MdiGetActive(pSed.hwndClient))
               ' // See if the document has been modified
               IF SCI_GetModify(pSed.hEdit) THEN
                  BEEP
                  r = CSED_MsgBox(hwnd, "Save current changes? " & PATHNAME$(NAMEX, strPath), _
                           %MB_YESNOCANCEL OR %MB_ICONQUESTION)
                  IF r = %IDCANCEL THEN EXIT FUNCTION
                  IF r = %IDYES THEN
                     r = CSED_SaveFile(hwnd, pSed.hEdit, %FALSE)
                     IF r = 0 THEN EXIT FUNCTION
                  END IF
               END IF
               ' // Close the active window
               IF hwndClient THEN
                  hwndActive = MdiGetActive(hwndClient)
                  IF SendMessage(hwndActive, %WM_QUERYENDSESSION, 0, 0) THEN
                     MdiDestroy(hwndClient, hwndActive)
                  END IF
               END IF
               CSED_ChangeToolbarButtonsState
               CSED_ChangeMenuItemsState
               ' // Enable open just in case it has been disabled
               EnableMenuItem pSed.hMenuFile, %IDM_OPEN, %MF_ENABLED
               Toolbar_EnableButton(pSed.hToolbar, %IDM_OPEN)
               ' // If there are not child windows open, clear the status bar
               IF GetWindow(hwndClient, %GW_CHILD) = 0 THEN CSED_ClearStatusBar
               EXIT FUNCTION

            ' // Close all
            CASE %IDM_CLOSEALL, %IDM_CLOSEWINDOWS
               ' // Close all the MDI child windows
               IF hwndClient THEN
                  EnumChildWindows hwndClient, CODEPTR(CSED_CloseEnumProc), 0
               END IF
               CSED_ChangeToolbarButtonsState
               CSED_ChangeMenuItemsState
               ' // Enable open just in case it has been disabled
               EnableMenuItem pSed.hMenuFile, %IDM_OPEN, %MF_ENABLED
               Toolbar_EnableButton(pSed.hToolbar, %IDM_OPEN)
               ' // If there are not child windows open, clear the status bar
               IF GetWindow(hwndClient, %GW_CHILD) = 0 THEN CSED_ClearStatusBar
               EXIT FUNCTION

            ' // DOS prompt
            CASE %IDM_DOS
               PID = SHELL(ENVIRON$("COMSPEC"))
               EXIT FUNCTION

            ' // Refresh document
            CASE %IDM_REFRESH
               IF pSed.hEdit THEN UpdateWindow(pSed.hEdit)
               strPath = AfxGetWindowText(MdiGetActive(pSed.hwndClient))
               IF LEFT$(UCASE$(PATHNAME$(NAMEX, strPath)), 8) <> "UNTITLED" THEN
                  CSED_OpenFile strPath
               END IF
               EXIT FUNCTION

            ' *** FILE_MENU_END ***

            ' *** EDIT_MENU_BEGIN ***
            ' // Undo
            CASE %IDM_UNDO
               SCI_Undo(pSed.hEdit)
               CSED_ChangeToolbarButtonsState
               CSED_ChangeMenuItemsState
               EXIT FUNCTION

            ' // Redo
            CASE %IDM_REDO
               SCI_Redo(pSed.hEdit)
               CSED_ChangeToolbarButtonsState
               CSED_ChangeMenuItemsState
               EXIT FUNCTION

            ' // Clear
            CASE %IDM_CLEAR
               SCI_Clear(pSed.hEdit)
               EXIT FUNCTION

            ' // Clear all
            CASE %IDM_CLEARALL
               SCI_ClearAll(pSed.hEdit)
               EXIT FUNCTION

            ' // Cut
            CASE %IDM_CUT
               SCI_Cut(pSed.hEdit)
               EXIT FUNCTION

            ' // Copy
            CASE %IDM_COPY
               SCI_Copy(pSed.hEdit)
               EXIT FUNCTION

            ' // Paste
            CASE %IDM_PASTE
               SCI_Paste(pSed.hEdit)
               CSED_ChangeToolbarButtonsState
               CSED_ChangeMenuItemsState
               EXIT FUNCTION

            ' // Delete line
            CASE %IDM_LINEDELETE
               SCI_LineDelete(pSed.hEdit)
               EXIT FUNCTION

            ' // Select all
            CASE %IDM_SELECTALL
               SCI_SelectAll(pSed.hEdit)
               EXIT FUNCTION

            ' // Indent block
            CASE %IDM_BLOCKINDENT
               SCI_Tab(pSed.hEdit)
               EXIT FUNCTION

            ' // Unindent block
            CASE %IDM_BLOCKUNINDENT
               SCI_BackTab(pSed.hEdit)
               EXIT FUNCTION

            ' // Comment line or blobk
            CASE %IDM_COMMENT, %IDK_COMMENT
               SCI_BlockComment(pSed.hEdit)
               EXIT FUNCTION

            ' // Uncomment line or blobk
            CASE %IDM_UNCOMMENT, %IDK_UNCOMMENT
               SCI_BlockUncomment(pSed.hEdit)
               EXIT FUNCTION

            ' // Convert selected text to upper case
            CASE %IDM_SELTOUPPERCASE
               SCI_ChangeSelectionToUpperCase(pSed.hEdit)
               EXIT FUNCTION

            ' // Convert selected text to lower case
            CASE %IDM_SELTOLOWERCASE
               SCI_ChangeSelectionToLowerCase(pSed.hEdit)
               EXIT FUNCTION

            ' Convert selected text to mixed case
            CASE %IDM_SELTOMIXEDCASE
               SCI_ChangeSelectionToMixedCase(pSed.hEdit)
               EXIT FUNCTION

            ' // Change end of line to <cr> <lf>
            CASE %IDM_CVEOLTOCRLF
               SCI_ConvertEOLs(pSed.hEdit, %SC_EOL_CRLF)
               EXIT FUNCTION

            ' // Change end of line to <cr>
            CASE %IDM_CVEOLTOCR
               SCI_ConvertEOLs(pSed.hEdit, %SC_EOL_CR)
               EXIT FUNCTION

            ' // Change end of line to <lf>
            CASE %IDM_CVEOLTOLF
               SCI_ConvertEOLs(pSed.hEdit, %SC_EOL_LF)
               EXIT FUNCTION

            ' // Goto to the specified line
            CASE %IDM_GOTOLINE
               CSED_GotoLineDialog hwnd
               EXIT FUNCTION

            ' // Replace tabs with spaces
            CASE %IDM_REPLTABSWITHSPC
               SCI_ReplaceTabsWithSpaces(pSed.hEdit)
               EXIT FUNCTION

            ' // Format selected text
            CASE %IDM_FORMATREGION
               SCI_FormatRegion(pSed.hEdit)
               EXIT FUNCTION

            ' // Tabulate selected text
            CASE %IDM_TABULATEREGION
               SCI_TabulateRegion(pSed.hEdit)
               EXIT FUNCTION

            ' // Goto to the beginning of the first procedure
            CASE %IDM_GOTOBEGINPROC
               curPos = CSED_GotoBeginProc
               EXIT FUNCTION

            ' // Goto to the end of the last procedure
            CASE %IDM_GOTOENDPROC
               curPos = CSED_GotoEndProc
               EXIT FUNCTION

            ' // Goto to the beginning of the procedure
            CASE %IDM_GOTOBEGINTHISPROC
               curPos = CSED_GotoBeginThisProc
               EXIT FUNCTION

            ' // Goto to the end of the procedure
            CASE %IDM_GOTOENDTHISPROC
               curPos = CSED_GotoEndThisProc
               EXIT FUNCTION

            ' // Generate a new guid and insert it at the cursor location
            CASE %IDM_INSERTGUID
               strText = "GUID$(" & $DQ & GUIDTXT$(GUID$) & $DQ & ")"
               SCI_InsertText(pSed.hEdit, -1, strText)
               EXIT FUNCTION

            ' // Change directory to current file path
            CASE %IDM_CHDIR
               strPath = AfxGetWindowText(MdiGetActive(pSed.hwndClient))
               strPath = PATHNAME$(PATH, strPath)
               IF RIGHT$(strPath, 1) = "\" THEN strPath = LEFT$(strPath, LEN(strPath) - 1)
               IF LEN(strPath) THEN CHDIR strPath
               EXIT FUNCTION

            ' // Keyboard macros
            CASE %IDM_ALT0 TO %IDM_ALT9, %IDM_CTRL0 TO %IDM_CTRL9
               CSED_InsertMacroText LO(WORD, hwnd), wParam
               EXIT FUNCTION
            ' *** EDIT_MENU_END ***

            ' *** SEARCH_MENU_BEGIN ***
            ' // Toggle the current bookmark
            CASE %IDM_TOGGLEBOOKMARK
               SCI_ToggleBookmark(pSed.hEdit)
               ' // Comment and uncomment the line just to make
               ' // the file dirty and force saving.
               SCI_BlockComment(pSed.hEdit)
               SCI_BlockUncomment(pSed.hEdit)
               EXIT FUNCTION

            ' // Goto next bookmark
            CASE %IDM_NEXTBOOKMARK
               SCI_NextBookmark(pSed.hEdit)
               EXIT FUNCTION

            ' // Goto previous bookmark
            CASE %IDM_PREVIOUSBOOKMARK
               SCI_PrevBookmark(pSed.hEdit)
               EXIT FUNCTION

            ' // Delete bookmarks
            CASE %IDM_DELETEBOOKMARKS
               SCI_DeleteBookmark(pSed.hEdit)
               EXIT FUNCTION

            ' // Code finder combobox
            CASE %IDM_CODEFINDER
               SendMessage pSed.hCodeFinderCB, %CB_SHOWDROPDOWN, %TRUE, 0
               SetFocus pSed.hCodeFinderCB
'               ComboBox_SetCurSel pSed.hCodeFinderCB, 0
               EXIT FUNCTION

            ' // Launch Explorer
            CASE %IDM_EXPLORER
               ShellExecute %HWND_DESKTOP, "explore", BYCOPY CURDIR$, BYVAL 0, BYVAL 0, %SW_SHOWNORMAL
               EXIT FUNCTION

            ' // Launch Windows Find
            CASE %IDM_WINDOWSFIND
               ShellExecute %HWND_DESKTOP, "find", BYCOPY CURDIR$, BYVAL 0, BYVAL 0, %SW_SHOWNORMAL
               EXIT FUNCTION
            ' *** SEARCH_MENU_END ***

            ' *** VIEW_MENU_BEGIN ***

            ' // Toggle current fold point
            CASE %IDM_TOGGLE
               SCI_ToggleCurFold(pSed.hEdit, SCI_GetCurrentLineNumber(pSed.hEdit))
               EXIT FUNCTION

            ' // Toggle all current fold point from current to below
            CASE %IDM_TOGGLEALL
               SCI_ToggleFoldsOnwards(pSed.hEdit, SCI_GetCurrentLineNumber(pSed.hEdit))
               EXIT FUNCTION

            ' // Fold all the fold points
            CASE %IDM_FOLDALL
               SCI_FoldAll(pSed.hEdit)
               EXIT FUNCTION

            ' // Unfold all the fold points
            CASE %IDM_UNFOLDALL
               SCI_UnfoldAll(pSed.hEdit)
               EXIT FUNCTION

            ' // Toggle the Use Tabs option
            CASE %IDM_USETABS
               IF pSed.hEdit THEN
                  IF pSed.UseTabs THEN
                     pSed.UseTabs = %FALSE
                     SCI_SetUseTabs(pSed.hEdit, %FALSE)
                  ELSE
                     pSed.UseTabs = %TRUE
                     SCI_SetUseTabs(pSed.hEdit, %TRUE)
                  END IF
               END IF
               EXIT FUNCTION

            ' // Toggle the Autoindent option
            CASE %IDM_AUTOINDENT
               IF pSed.hEdit THEN
                  IF pSed.AutoIndent THEN
                     pSed.AutoIndent = %FALSE
                  ELSE
                     pSed.AutoIndent = %TRUE
                  END IF
               END IF
               EXIT FUNCTION

            ' // Toggle the End of Line option
            CASE %IDM_SHOWEOL
               IF pSed.hEdit THEN
                  IF pSed.EndOfLine THEN
                     pSed.EndOfLine = %FALSE
                     SCI_SetViewEOL(pSed.hEdit, %FALSE)
                  ELSE
                     pSed.EndOfLine = %TRUE
                     SCI_SetViewEOL(pSed.hEdit, %TRUE)
                  END IF
               END IF
               EXIT FUNCTION

            ' // Toggle the Line Numbers option
            CASE %IDM_SHOWLINENUM
               IF pSed.hEdit THEN
                  IF pSed.LineNumbers THEN
                     pSed.LineNumbers = %FALSE
                     SCI_SetMarginWidthN(pSed.hEdit, 0, 0)
                  ELSE
                     pSed.LineNumbers = %TRUE
                     IF SCI_GetMarginWidthN(pSed.hEdit, 0) = 0 THEN
                        IF pSed.LineNumbersWidth = 0 THEN pSed.LineNumbersWidth = 50
                        SCI_SetMarginWidthN(pSed.hEdit, 0, pSed.LineNumbersWidth)
                     END IF
                  END IF
               END IF
               EXIT FUNCTION

            ' // Toggle the Margin option
            CASE %IDM_SHOWMARGIN
               IF pSed.hEdit THEN
                  IF pSed.Margin THEN
                     pSed.Margin = %FALSE
                     SCI_SetMarginWidthN(pSed.hEdit, 2, 0)
                  ELSE
                     pSed.Margin = %TRUE
                     IF SCI_GetMarginWidthN(pSed.hEdit, 2) = 0 THEN
                        IF pSed.MarginWidth = 0 THEN pSed.MarginWidth = 20
                        SCI_SetMarginWidthN(pSed.hEdit, 2, pSed.MarginWidth)
                     END IF
                  END IF
               END IF
               EXIT FUNCTION

            ' // Toggle the Use Tabs option
            CASE %IDM_SHOWINDENT
               IF pSed.hEdit THEN
                  IF pSed.IndentGuides THEN
                     pSed.IndentGuides = %FALSE
                     SCI_SetIndentationGuides(pSed.hEdit, %SC_IV_NONE)
                  ELSE
                     pSed.IndentGuides = %TRUE
                     SCI_SetIndentationGuides(pSed.hEdit, %SC_IV_REAL)
                  END IF
               END IF
               EXIT FUNCTION

            ' // Toggle the End of Line option
            CASE %IDM_SHOWEOL
               IF pSed.hEdit THEN
                  IF pSed.EndOfLine THEN
                     pSed.EndOfLine = %FALSE
                     SCI_SetViewEOL(pSed.hEdit, %FALSE)
                  ELSE
                     pSed.EndOfLine = %TRUE
                     SCI_SetViewEOL(pSed.hEdit, %TRUE)
                  END IF
               END IF
               EXIT FUNCTION

            ' // Toggle the WhiteSpace option
            CASE %IDM_SHOWSPACES
               IF pSed.hEdit THEN
                  IF pSed.WhiteSpace THEN
                     pSed.WhiteSpace = %FALSE
                     SCI_SetViews(pSed.hEdit, %SCWS_INVISIBLE)
                  ELSE
                     pSed.WhiteSpace = %TRUE
                     SCI_SetViews(pSed.hEdit, %SCWS_VISIBLEALWAYS)
                  END IF
               END IF
               EXIT FUNCTION

            ' // Toggle the Edge option
            CASE %IDM_SHOWEDGE
               IF pSed.hEdit THEN
                  IF pSed.EdgeColumn THEN
                     pSed.EdgeColumn = %FALSE
                     SCI_SetEdgeMode(pSed.hEdit, %EDGE_NONE)
                  ELSE
                     pSed.EdgeColumn = %TRUE
                     SCI_SetEdgeMode(pSed.hEdit, %EDGE_LINE)
                  END IF
               END IF
               EXIT FUNCTION

            ' // Zoom in
            CASE %IDM_ZOOMIN
               SCI_ZoomIn(pSed.hEdit)
               EXIT FUNCTION

            ' // Zoom out
            CASE %IDM_ZOOMOUT
               SCI_ZoomOut(pSed.hEdit)
               EXIT FUNCTION

            ' // File properties
            CASE %IDM_FILEPROPERTIES
               IF hwndClient THEN AfxShowFileProperties(hwnd, AfxGetWindowText(MdiGetActive(hwndClient)))
               EXIT FUNCTION

            ' // System information
            CASE %IDM_SYSINFO
               AfxShowSysInfo(hwnd, %TRUE)
               EXIT FUNCTION
            ' *** VIEW_MENU_END ***

            ' *** WINDOW_MENU_BEGIN ***
            ' // Cascade windows
            CASE %IDM_CASCADE
               MdiCascade(hwndClient)
               EXIT FUNCTION

            ' // Tile horizontal
            CASE %IDM_TILEH
               MdiTileHorizontal(hwndClient)
               EXIT FUNCTION

            ' // Tile vertical
            CASE %IDM_TILEV
               MdiTileVertical(hwndClient)
               EXIT FUNCTION

            ' // Arrange icons
            CASE %IDM_ARRANGE
               MdiIconArrange(hwndClient)
               EXIT FUNCTION

            ' // Restore the size of the main window
            CASE %IDM_RESTOREWSIZE
               SystemParametersInfo %SPI_GETWORKAREA, 0, rc, 0
               MoveWindow hwnd, 0, 0, rc.Right - rc.Left, rc.Bottom - rc.Top, %TRUE
               AfxCenterWindow hwnd
               EXIT FUNCTION

            ' // Swicth window
            CASE %IDM_SWITCHWINDOW
               hwndActive = MdiGetActive(pSed.hwndClient)
               MdiNext(pSed.hwndClient, hwndActive, 0)
               strPath = AfxGetWindowText(MdiGetActive(pSed.hwndClient))
               nTab = CSED_GetTabNumberFromPath(strPath)
               IF nTab > -1 THEN TabCtrl_SetCursel(pSed.hTabMdi, nTab)
               EXIT FUNCTION
            ' *** WINDOW_MENU_END ***

            ' *** TOOLS_MENU_END ***
            ' // Tools dialog
            CASE %IDM_TOOLS
               IF ISFILE(EXE.PATH$ & "CSED_TOOLS\CSED_TOOLS.EXE") THEN PID = SHELL(EXE.Path$ & "CSED_TOOLS\CSED_TOOLS.EXE", 1)
               EXIT FUNCTION

            ' // Code keeper
            CASE %IDM_CODEKEEPER
               IF ISFILE(EXE.PATH$ & "CSED_CODEKEEPER\CSED_CODEKEEPER.EXE") THEN PID = SHELL(EXE.Path$ & "CSED_CODEKEEPER\CSED_CODEKEEPER.EXE", 1)
               EXIT FUNCTION

            ' // Keyboard macros
            CASE %IDM_KBDMACROS
               IF ISFILE(EXE.PATH$ & "CSED_KBDMACROS\CSED_KBDMACROS.EXE") THEN PID = SHELL(EXE.Path$ & "CSED_KBDMACROS\CSED_KBDMACROS.EXE", 1)
               EXIT FUNCTION

            ' // Code tips builder
            CASE %IDM_CODETIPSBUILDER
               IF ISFILE(EXE.PATH$ & "CSED_CODETIPS\CSED_CODETIPS.EXE") THEN PID = SHELL(EXE.Path$ & "CSED_CODETIPS\CSED_CODETIPS.EXE", 1)
               EXIT FUNCTION

            ' // Launch PBForms
            CASE %IDM_PBFORMS
               strPath = pSed.PBFormsPath
               IF LEN(strPath) THEN
                  IF pSed.hEdit THEN UpdateWindow pSed.hEdit
                  CSED_SaveFile hwnd, pSed.hEdit, %FALSE
                  strFilePath = AfxGetWindowText(MdiGetActive(pSed.hwndClient))
                  IF LEN(strPath) THEN r = SHELL(strPath & " " & strFilePath, 1)
               END IF
               EXIT FUNCTION

            ' // Launch the PB COM browser
            CASE %IDM_PBCOMBR
               strPath = pSed.PBCOMBrowserPath
               IF LEN(strPath) THEN r = SHELL(strPath, 1)
               EXIT FUNCTION

            ' // Launch the PB Library Manager
            CASE %IDM_POWERLIB
               strPath = pSed.PowerLibPath
               IF LEN(strPath) THEN r = SHELL(strPath, 1)
               EXIT FUNCTION

            ' // Launch the TypeLib Browser
            CASE %IDM_TYPELIBBR
               strPath = pSed.TypeLibBrowserPath
               IF LEN(strPath) THEN r = SHELL(strPath, 1)
               EXIT FUNCTION

            ' // Debugging tool
            CASE %IDM_DEBUGTOOL
               strPath = pSed.DebugToolPath
               IF LEN(strPath) THEN r = SHELL(strPath, 1)
               EXIT FUNCTION

            ' // Find in files
            CASE %IDM_FINDINFILES
               strPath = pSed.FindInFilesToolPath
               IF LEN(strPath) THEN r = SHELL(strPath, 1)
               EXIT FUNCTION

            ' // Launch the Windows calculator
            CASE %IDM_CALCULATOR
               hCalc = FindWindow("SciCalc", BYVAL %NULL)
               IF hCalc <> %NULL THEN
                  IF IsIconic(hCalc) <> 0 OR IsZoomed(hCalc) <> 0 THEN
                     ShowWindow hCalc, %SW_RESTORE
                  END IF
                  SetForegroundWindow hCalc
               ELSE
                  r = SHELL("CALC.EXE")
               END IF
               EXIT FUNCTION

            ' // Character map
            CASE %IDM_CHARMAP
               r = SHELL("CharMap.exe")
               EXIT FUNCTION

            ' // Notepad
            CASE %IDM_NOTEPAD
               r = SHELL("Notepad.exe")
               EXIT FUNCTION

            ' // Microsoft Paint
            CASE %IDM_MSPAINT
               r = SHELL("mspaint.exe")
               EXIT FUNCTION

            ' // Lynx
            CASE %IDM_LYNX
               IF ISFILE(EXE.PATH$ & "CSED_LYNX\Lynx.exe") THEN PID = SHELL(EXE.Path$ & "CSED_LYNX\Lynx.exe", 1)
               EXIT FUNCTION

            ' // Message box designer
            CASE %IDM_MSGBOXDESIGNER
               IF ISFILE(EXE.PATH$ & "MessageBoxDesigner\MessageBoxDesigner.exe") THEN PID = SHELL(EXE.Path$ & "MessageBoxDesigner\MessageBoxDesigner.exe", 1)
               EXIT FUNCTION

            ' // Backup files manager
            CASE %IDM_BACKUPMGR
               IF ISFILE(EXE.PATH$ & "CSED_BACKUPMGR\CSED_BACKUPMGR.exe") THEN PID = SHELL(EXE.Path$ & "CSED_BACKUPMGR\CSED_BACKUPMGR.exe", 1)
               EXIT FUNCTION

            ' // File stamp
            CASE %IDM_FILESTAMP
               IF ISFILE(EXE.PATH$ & "FileStamp\fStamp.exe") THEN PID = SHELL(EXE.Path$ & "FileStamp\fStamp.exe", 1)
               EXIT FUNCTION

            ' // Visual designer
            CASE %IDM_VISDES
               strPath = pSed.VisualDesignerPath
               IF LEN(strPath) THEN r = SHELL(strPath, 1)
               EXIT FUNCTION

            ' // Icon editor
            CASE %IDM_ICONED
               strPath = pSed.IconEditorPath
               IF LEN(strPath) THEN r = SHELL(strPath, 1)
               EXIT FUNCTION

            ' // Image editor
            CASE %IDM_IMGED
               strPath = pSed.ImageEditorPath
               IF LEN(strPath) THEN r = SHELL(strPath, 1)
               EXIT FUNCTION

            ' // Selected headers
            CASE %IDM_JRSINC1
               pSed.SelectedHeaders = 1
               EXIT FUNCTION
            CASE %IDM_JRSINC2
               pSed.SelectedHeaders = 2
               EXIT FUNCTION
            CASE %IDM_PBINC1
               pSed.SelectedHeaders = 3
               EXIT FUNCTION
            CASE %IDM_PBINC2
               pSed.SelectedHeaders = 4
               EXIT FUNCTION

            ' *** TOOLS_MENU_END ***

            ' // Autocompletion listbox
            CASE %IDM_AUTOCOMPLETE
               CSED_AutoComplete(hwnd)
               EXIT FUNCTION

            ' // Toggle the Show Procedure Name option
            CASE %IDM_SHOWPROCNAME
               IF pSed.ShowProcedureName = %BST_CHECKED THEN
                  CheckMenuItem pSed.hMenu, %IDM_SHOWPROCNAME, %MF_UNCHECKED
                  pSed.ShowProcedureName = %BST_UNCHECKED
                  StatusBar_SetText(pSed.hStatusbar, 4, "")
               ELSE
                  CheckMenuItem pSed.hMenu, %IDM_SHOWPROCNAME, %MF_CHECKED
                  pSed.ShowProcedureName = %BST_CHECKED
                  CSED_WithinProc(tProc)
                  StatusBar_SetText(pSed.hStatusbar, 4, tProc.ProcName)
               END IF
               EXIT FUNCTION

            ' // Toggle compiler selection
            CASE %IDM_TOGGLECOMPILER
               IF pSed.SelectedCompiler = 2 THEN
                  pSed.SelectedCompiler = 1
                  StatusBar_SetText(pSed.hStatusbar, 3, "PBWIN")
               ELSE
                  pSed.SelectedCompiler = 2
                  StatusBar_SetText(pSed.hStatusbar, 3, "PBCC")
               END IF
               EXIT FUNCTION

            ' // Convert to HTML
            CASE %IDM_HTMLCODE
               IF pSed.hEdit THEN UpdateWindow pSed.hEdit
               CSED_CvBasToHtml(%TRUE)
               EXIT FUNCTION

            ' // HTML Print preview
            CASE %IDM_PRINT
               IF pSed.hEdit THEN UpdateWindow pSed.hEdit
               strText = CSED_CvBasToHtml(%FALSE, %TRUE)
               IF LEN(strText) THEN CSED_WB_PrintPreview(hwnd, strText)
               EXIT FUNCTION

            ' // Editor options
            CASE %IDM_EDITOROPT
               CSED_EditorOptionsDialog hwnd
               EXIT FUNCTION

            ' // Compiler options
            CASE %IDM_COMPILEROPT
               CSED_CompilerOptionsDialog hwnd
               EXIT FUNCTION

            ' // Fold options
            CASE %IDM_FOLDOPT
               CSED_FoldOptionsDialog hwnd
               EXIT FUNCTION

            ' // Fold options
            CASE %IDM_COLORSOPT
               CSED_ColorOptionsDialog hwnd
               EXIT FUNCTION

            ' // Register file extensions
            CASE %IDM_REGFILEEXT
               CSED_RegisterFileExtensions hwnd
               EXIT FUNCTION

            ' // Email us
            CASE %IDM_MAIL
               strText = "mailto:" & $MAILADDRESS & "?"
               ShellExecute BYVAL %NULL, "open", BYCOPY strText, BYVAL %NULL, BYVAL %NULL, %SW_SHOWNORMAL
               EXIT FUNCTION

            ' // Exit
            CASE %IDM_EXIT
               SendMessage hwnd, %WM_CLOSE, 0, 0
               EXIT FUNCTION

            ' *** HELP_MENU_BEGIN ***
            ' // About box
            CASE %IDM_ABOUT
               CSED_AboutBox hwnd
               EXIT FUNCTION

            ' // Context help
            CASE %IDM_HELP
               CSED_SearchContextHelp hwnd
               EXIT FUNCTION

            ' // CSED help
            CASE %IDM_CSEDHELP
               strPath = EXE.Path$ & "CSED.CHM"
               IF ISFILE(strPath) THEN HtmlHelp 0, BYCOPY strPath, 0, 0
               EXIT FUNCTION

            ' // PBWIN help
            CASE %IDM_PBWINHELP
               strPath = pSed.PBWinHelpPath
               IF LEN(strPath) THEN
                  IF RIGHT$(UCASE$(strPath), 4) = ".HLP" THEN
                     WinHelp hwnd, BYCOPY strPath, %HELP_FINDER, 0
                  ELSEIF RIGHT$(UCASE$(strPath), 4) = ".CHM" THEN
                     HtmlHelp 0, BYCOPY strPath, 0, 0
                  END IF
               END IF
               EXIT FUNCTION

            ' // PBCC help
            CASE %IDM_PBCCHELP
               strPath = pSed.PBCCHelpPath
               IF LEN(strPath) THEN
                  IF RIGHT$(UCASE$(strPath), 4) = ".HLP" THEN
                     WinHelp hwnd, BYCOPY strPath, %HELP_FINDER, 0
                  ELSEIF RIGHT$(UCASE$(strPath), 4) = ".CHM" THEN
                     HtmlHelp 0, BYCOPY strPath, 0, 0
                  END IF
               END IF
               EXIT FUNCTION

            ' // Help contents
            CASE %IDM_HELPCONTENTS
               IF pSed.SelectedCompiler = 1 THEN
                  strPath = pSed.PBWinHelpPath
               ELSE
                  strPath = pSed.PBCCHelpPath
               END IF
               IF LEN(strPath) THEN
                  IF RIGHT$(UCASE$(strPath), 4) = ".HLP" THEN
                     WinHelp hwnd, BYCOPY strPath, %HELP_CONTENTS, 0
                  ELSEIF RIGHT$(UCASE$(strPath), 4) = ".CHM" THEN
                     HtmlHelp 0, BYCOPY strPath, %HH_DISPLAY_TOC, 0
                  END IF
               END IF
               EXIT FUNCTION

            ' // Help index
            CASE %IDM_HELPINDEX
               IF pSed.SelectedCompiler = 1 THEN
                  strPath = pSed.PBWinHelpPath
               ELSE
                  strPath = pSed.PBCCHelpPath
               END IF
               IF LEN(strPath) THEN
                  IF RIGHT$(UCASE$(strPath), 4) = ".HLP" THEN
                     WinHelp hwnd, BYCOPY strPath, %HELP_INDEX, 0
                  ELSEIF RIGHT$(UCASE$(strPath), 4) = ".CHM" THEN
                     HtmlHelp 0, BYCOPY strPath, %HH_DISPLAY_INDEX, 0
                  END IF
               END IF
               EXIT FUNCTION

            ' // Help search
            CASE %IDM_HELPSEARCH
               IF pSed.SelectedCompiler = 1 THEN
                  strPath = pSed.PBWinHelpPath
               ELSE
                  strPath = pSed.PBCCHelpPath
               END IF
               IF LEN(strPath) THEN
                  IF RIGHT$(UCASE$(strPath), 4) = ".HLP" THEN
                     WinHelp hwnd, BYCOPY strPath, %HELP_FINDER, 0
                  ELSEIF RIGHT$(UCASE$(strPath), 4) = ".CHM" THEN
                     LOCAL q AS HH_FTS_QUERY
                     q.cbStruct = SIZEOF(q)
                     HtmlHelp 0, BYCOPY strPath, %HH_DISPLAY_SEARCH, VARPTR(q)
                  END IF
               END IF
               EXIT FUNCTION

            ' // Guides
            CASE %IDM_GUIDESMENUHEADER + 1 TO %IDM_GUIDESMENUHEADER + pSed.MenuGuidesCount
               strText = AfxGetMenuItemText(pSed.hMenuGuides, LO(WORD, wParam))
               ' // Retrieve the path of the help file
               hToolsFile = trm_Open(EXE.Path$ & "CSED_TOOLS\CSED_TOOLS.TRM", %TRUE)
               IF hToolsFile THEN
                  RecordStr = trm_GetEqual(hToolsFile, 1, BYCOPY strText)
                  LSET tTools = RecordStr
                  strPath = TRIM$(tTools.strPath)
                  IF LEN(strPath) THEN
                     IF UCASE$(RIGHT$(TRIM$(tTools.strPath), 4)) = ".CHM" THEN
                        HtmlHelp( 0, BYCOPY strPath, 0, 0)
                     ELSEIF UCASE$(RIGHT$(TRIM$(tTools.strPath), 4)) = ".PDF" THEN
                        ShellExecute(%NULL, "open", BYCOPY TRIM$(tTools.strPath), BYCOPY TRIM$(tTools.strParams), "", %SW_SHOWNORMAL)
                     END IF
                  END IF
                  ' // Close the file
                  trm_Close hToolsFile
               END IF
               EXIT FUNCTION

            ' // Tools
            CASE %IDM_TOOLSMENUHEADER + 1 TO %IDM_TOOLSMENUHEADER + pSed.MenuToolsCount
               strText = AfxGetMenuItemText(pSed.hMenuTools, LO(WORD, wParam))
               ' // Retrieve the path of the help file
               hToolsFile = trm_Open(EXE.Path$ & "CSED_TOOLS\CSED_TOOLS.TRM", %TRUE)
               IF hToolsFile THEN
                  RecordStr = trm_GetEqual(hToolsFile, 1, BYCOPY strText)
                  LSET tTools = RecordStr
                  strPath = TRIM$(tTools.strPath)
                  IF LEN(strPath) THEN
                     IF UCASE$(RIGHT$(TRIM$(tTools.strPath), 4)) <> ".CHM" THEN
                        PID = SHELL(strPath & " " & TRIM$(tTools.strParams), 1)
                     END IF
                  END IF
                  ' // Close the file
                  trm_Close hToolsFile
               END IF
               EXIT FUNCTION

            ' // José Roca Software site
            CASE %IDM_JRSSITE
               ShellExecute %HWND_DESKTOP, "open", "http://www.jose.it-berater.org/index.html", BYVAL 0, BYVAL 0, %SW_SHOWNORMAL
               EXIT FUNCTION

            ' // José Roca Software forum
            CASE %IDM_JRSFORUM
               ShellExecute %HWND_DESKTOP, "open", "http://www.jose.it-berater.org/smfforum/index.php", BYVAL 0, BYVAL 0, %SW_SHOWNORMAL
               EXIT FUNCTION

            ' // PowewrBASIC site
            CASE %IDM_PBSITE
               ShellExecute %HWND_DESKTOP, "open", "http://www.powerbasic.com", BYVAL 0, BYVAL 0, %SW_SHOWNORMAL
               EXIT FUNCTION

            ' // MSDN site
            CASE %IDM_MSDNSITE
               ShellExecute %HWND_DESKTOP, "open", "http://msdn.microsoft.com", BYVAL 0, BYVAL 0, %SW_SHOWNORMAL
               EXIT FUNCTION

            ' // Google
            CASE %IDM_GOOGLE
               ShellExecute %HWND_DESKTOP, "open", "http://www.google.com", BYVAL 0, BYVAL 0, %SW_SHOWNORMAL
               EXIT FUNCTION

            ' // Google code search
            CASE %IDM_GOOGLECODESEARCH
               ShellExecute %HWND_DESKTOP, "open", "http://www.google.com/codesearch", BYVAL 0, BYVAL 0, %SW_SHOWNORMAL
               EXIT FUNCTION

            ' // Resource compiler help
            CASE %IDM_RCHELP
               ShellExecute %HWND_DESKTOP, "open", "http://msdn.microsoft.com/en-us/library/aa381042%28VS.85%29.aspx", BYVAL 0, BYVAL 0, %SW_SHOWNORMAL
               EXIT FUNCTION

            ' // Platform SDK Help
            CASE %IDM_PLATFORMSDKHELP
               CSED_MSDNHELP hwnd
               EXIT FUNCTION

            ' *** HELP_MENU_END ***
            ' // Compile and Compile and execute options
            CASE %IDM_COMPILE, %IDM_COMPILEANDRUN, %IDM_COMPILEANDDEBUG, %IDM_EXECUTE
               ' // Get the path of the active window
               strPath = AfxGetWindowText(MdiGetActive(pSed.hwndClient))
               ' // If it is a resource file...
               IF INSTR(UCASE$(strPath), ".RC") THEN
                  CSED_CompileResource(hwnd, pSed.hEdit, strPath)
                  EXIT FUNCTION
               END IF
               IF LO(WORD, wParam) <> %IDM_EXECUTE THEN CSED_SaveLoadedFiles(hwnd)
               CSED_CompileBasFile hwnd, pSed.hEdit, LO(WORD, wParam)
               EXIT FUNCTION

            ' // Run File Dialog
            CASE %IDM_RUNFILEDLG
               AfxRunFileDialog hwnd, %NULL, "", "", "", %NULL
               EXIT FUNCTION

            ' // Compiler results
            CASE %IDM_COMPILERRESULTS
               IF LEN(pSed.CompilerResults) THEN CSED_CompilerResults hwnd, pSed.CompilerResults
               EXIT FUNCTION

            ' // Command line argumtnts
            CASE %IDM_COMMANDLINE
               pSed.CommandLine = CWindow_InputBox(hwnd, 0, 0, "Command Line", "Enter command line arguments:", pSed.CommandLine, 256)
               EXIT FUNCTION

            ' // Code finder combobox
            CASE %IDC_CODEFINDER
               SELECT CASE HI(WORD, wParam)
                  CASE %CBN_DROPDOWN
                     ' // Search the function and procedure names in a separate procedure.
                     ' // This procedure fills the combobox and stores the lines in the
                     ' // 32-bit values associated with each of them.
                     CSED_CodeFinder(pSed.hCodeFinderCB, pSed.hEdit)
                  CASE %CBN_SELCHANGE
                     ' // Retrieve the line of the wanted function or procedure
                     ' // stored in the 32-bit value associated with the specified item.
                     curSel = ComboBox_GetCurSel(pSed.hCodeFinderCB)
                     IF curSel THEN
                        ' // End position = length of the document
                        endPos = SCI_GetTextLength(pSed.hEdit)
                        ' // Set to end position of document
                        SCI_GotoLine(pSed.hEdit, endPos)
                        ' // Set function or procedure to top of editor
                        curSel = ComboBox_GetItemData(pSed.hCodeFinderCB, curSel)
                        SCI_GotoLine(pSed.hEdit, curSel)
                     END IF
                  CASE %CBN_CLOSEUP
                     ' // Post a message to reset the contents
                     PostMessage hwnd, %WM_USER + 1001, 0, 0
               END SELECT
               EXIT FUNCTION

            ' // Load selected file
            CASE %IDM_GOTOSELFILE
               ' // Forward the message to the MDI window procedure
               SendMessage MdiGetActive(pSed.hwndClient), %WM_COMMAND, %IDM_GOTOSELFILE, 0
               EXIT FUNCTION

            ' // Find and Find and replace
            CASE %IDM_FIND, %IDM_REPLACE
               dwFindMsg = pSed.FindReplaceObj.FindOrReplace(hwnd, wParam)
               EXIT FUNCTION

            ' // Find next
            CASE %IDM_FINDNEXT
               pSed.FindReplaceObj.FindNext(hwnd)
               EXIT FUNCTION

            ' // Find backwards
            CASE %IDM_FINDBACKWARDS
               pSed.FindReplaceObj.FindBackwards(hwnd)
               EXIT FUNCTION

            ' // Common method to find backwards for forward
            CASE %IDM_FINDUPORDOWN
               pSed.FindReplaceObj.FindUpOrDown(hwnd)
               EXIT FUNCTION

         END SELECT

         ' // Pass unprocessed messages to the active MDI child and then to DefFrameProc()
         hwndActive = SendMessage(hwndClient, %WM_MDIGETACTIVE, 0, 0)
         IF IsWindow(hwndActive) THEN SendMessage hwndActive, %WM_COMMAND, wParam, lParam

      ' // Message sent by the Find/FindReplace dialog
      CASE dwFindMsg
         pSed.FindReplaceObj.FindReplaceText(hwnd)
         EXIT FUNCTION

      ' // Processes notification messages
      CASE %WM_NOTIFY
         pnmhdr = lParam
         SELECT CASE @pnmhdr.idFrom
            CASE %IDC_TABMDI
               SELECT CASE @pnmhdr.code
                  CASE %NM_CLICK
                     ' // Get the position of the hit
                     GetCursorPos pInfo.pt
                     ScreentoClient pSed.hTabMdi, pInfo.pt
                     nTab = TabCtrl_HitTest(pSed.hTabMdi, pInfo)
                     ' // If the icon has been clicked...
                     IF pInfo.flags = %TCHT_ONITEMICON THEN
                        ' // ...send message to close the window
                        SendMessage hwnd, %WM_COMMAND, MAK(DWORD, %IDM_CLOSEWINDOW, 0), 0
                     END IF
                  CASE %NM_RCLICK
                     ' // Get the tab number
                     GetCursorPos pInfo.pt
                     ScreentoClient pSed.hTabMdi, pInfo.pt
                     nTab = TabCtrl_HitTest(pSed.hTabMdi, pInfo)
                     ' // Select the tab
                     TabCtrl_SetCurSel(pSed.hTabMdi, nTab)
                     ' // Get the path of the file loaded in the associated edit control
                     pTabFilePaths = pSed.TabFilePaths
                     vPath = pTabFilePaths.Item(nTab + 1)
                     ' // Activate it
                     CSED_TabMdiActivateWindow(VARIANT$$(vPath))
                     ' // Create a popup menu
                     hTrackPopUpMenu = CreatePopUpMenu
                     AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_CLOSEFILE, "&Close" & $TAB & "Ctrl+F4"
                     GetCursorPos pt
                     TrackPopupMenu(hTrackPopUpMenu, 0, pt.x, pt.y, 0, hwnd, BYVAL %NULL)
                     DestroyMenu hTrackPopUpMenu
               END SELECT
            CASE %IDC_TOOLBAR
               ptbn = lParam
               IF @ptbn.hdr.code = %TBN_DROPDOWN THEN
                  SELECT CASE @ptbn.iItem
                     ' // Dropdown new file menu
                     CASE %IDM_NEW
                        Toolbar_GetRect(@ptbn.hdr.hwndFrom, @ptbn.iItem, rc)
                        MapWindowPoints(@ptbn.hdr.hwndFrom, %HWND_DESKTOP, rc, 2)
                        CSED_Templates(hwnd, rc.Left, rc.Bottom)
                     ' // Dropdown open file menu
                     CASE %IDM_OPEN
                        Toolbar_GetRect(@ptbn.hdr.hwndFrom, @ptbn.iItem, rc)
                        MapWindowPoints(@ptbn.hdr.hwndFrom, %HWND_DESKTOP, rc, 2)
                        CSED_RecentFiles(hwnd, rc.Left, rc.Bottom)
                     ' // Dropdown search options menu
                     CASE %IDM_FIND
                        Toolbar_GetRect(@ptbn.hdr.hwndFrom, @ptbn.iItem, rc)
                        MapWindowPoints(@ptbn.hdr.hwndFrom, %HWND_DESKTOP, rc, 2)
                        hTrackPopUpMenu = CreatePopUpMenu
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_FIND, "&Find..." + $TAB + "Ctrl+F"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_FINDNEXT, "Find &Next" + $TAB + "F3"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_FINDBACKWARDS, "Find &Backwards" + $TAB + "Shift+F3"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_REPLACE, "Find and R&eplace..." + $TAB + "Ctrl+R"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_GOTOLINE, "&Go to Line..." + $TAB + "Ctrl+G"
                        TrackPopupMenu(hTrackPopUpMenu, 0, rc.Left, rc.Bottom, 0, hwnd, BYVAL %NULL)
                        DestroyMenu hTrackPopUpMenu
                     ' // Dropdown bookmark options menu
                     CASE %IDM_BOOKMARKOPTIONS
                        Toolbar_GetRect(@ptbn.hdr.hwndFrom, @ptbn.iItem, rc)
                        MapWindowPoints(@ptbn.hdr.hwndFrom, %HWND_DESKTOP, rc, 2)
                        hTrackPopUpMenu = CreatePopUpMenu
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_TOGGLEBOOKMARK, "Toggle Bookmark" + $TAB + "Ctrl+F2"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_NEXTBOOKMARK, "Next Bookmark" + $TAB + "F2"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_PREVIOUSBOOKMARK, "Previous Bookmark" + $TAB + "Shift+F2"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_DELETEBOOKMARKS,"Delete Bookmarks" + $TAB + "Ctrl+Shift+F2"
                        TrackPopupMenu(hTrackPopUpMenu, 0, rc.Left, rc.Bottom, 0, hwnd, BYVAL %NULL)
                        DestroyMenu hTrackPopUpMenu
                  END SELECT
               END IF
            CASE %IDC_BOTTOMTOOLBAR
               ptbn = lParam
               IF @ptbn.hdr.code = %TBN_DROPDOWN THEN
                  SELECT CASE @ptbn.iItem
                     ' // Dropdown block operations menu
                     CASE %IDM_BLOCKOPERATIONS
                        Toolbar_GetRect(@ptbn.hdr.hwndFrom, @ptbn.iItem, rc)
                        MapWindowPoints(@ptbn.hdr.hwndFrom, %HWND_DESKTOP, rc, 2)
                        hTrackPopUpMenu = CreatePopUpMenu
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_BLOCKINDENT, "Block &Indent" + $TAB + "Tab"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_BLOCKUNINDENT, "Block &Unindent" + $TAB + "Shift+Tab"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_COMMENT, "&Block Comment" + $TAB + "Ctrl+Q"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_UNCOMMENT, "Bloc&k Uncomment" + $TAB + "Ctrl+Shift+Q"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_FORMATREGION, "&Format Text" + $TAB + "Ctrl+B"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_TABULATEREGION, "&Tabulate Text" + $TAB + "Ctrl+Shift+B"
                        TrackPopupMenu(hTrackPopUpMenu, 0, rc.Left, rc.Bottom, 0, hwnd, BYVAL %NULL)
                        DestroyMenu hTrackPopUpMenu
                     ' // Dropdown case conversions menu
                     CASE %IDM_CASECONVERSIONS
                        Toolbar_GetRect(@ptbn.hdr.hwndFrom, @ptbn.iItem, rc)
                        MapWindowPoints(@ptbn.hdr.hwndFrom, %HWND_DESKTOP, rc, 2)
                        hTrackPopUpMenu = CreatePopUpMenu
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_SELTOUPPERCASE, "Selection to &Upper Case" + $TAB + "Ctrl+Alt+U"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_SELTOLOWERCASE, "Selection to &Lower Case" + $TAB + "Ctrl+Alt+L"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_SELTOMIXEDCASE, "Selection to &Mixed Case" + $TAB + "Ctrl+Alt+M"
                        TrackPopupMenu(hTrackPopUpMenu, 0, rc.Left, rc.Bottom, 0, hwnd, BYVAL %NULL)
                        DestroyMenu hTrackPopUpMenu
                     ' // Dropdown end of line conversions menu
                     CASE %IDM_EOLCHARCONVERSIONS
                        Toolbar_GetRect(@ptbn.hdr.hwndFrom, @ptbn.iItem, rc)
                        MapWindowPoints(@ptbn.hdr.hwndFrom, %HWND_DESKTOP, rc, 2)
                        hTrackPopUpMenu = CreatePopUpMenu
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_CVEOLTOCRLF, "Convert End of Line Characters to $CRLF"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_CVEOLTOCR, "Convert End of Line Characters to $CRLF"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_CVEOLTOLF, "Convert End of Line Characters to $LF"
                        TrackPopupMenu(hTrackPopUpMenu, 0, rc.Left, rc.Bottom, 0, hwnd, BYVAL %NULL)
                        DestroyMenu hTrackPopUpMenu
                     ' // Dropdown view options menu
                     CASE %IDM_VIEWOPTIONS
                        Toolbar_GetRect(@ptbn.hdr.hwndFrom, @ptbn.iItem, rc)
                        MapWindowPoints(@ptbn.hdr.hwndFrom, %HWND_DESKTOP, rc, 2)
                        hTrackPopUpMenu = CreatePopUpMenu
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_USETABS, "Use &Tabs" + $TAB + "Ctrl+Shift+T"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_AUTOINDENT, "&Auto Indentation" + $TAB + "Ctrl+Shift+A"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_SHOWLINENUM, "&Line Numbers" + $TAB + "Ctrl+Shift+L"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_SHOWMARGIN, "&Margin" + $TAB + "Ctrl+Shift+M"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_SHOWINDENT, "&Indentation Guides" + $TAB + "Ctrl+Shift+I"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_SHOWSPACES, "&Whitespace" + $TAB + "Ctrl+Shift+W"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_SHOWEOL, "&End of Line" + $TAB + "Ctrl+Shift+D"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_SHOWEDGE, "Ed&ge" + $TAB + "Ctrl+Shift+G"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_SHOWPROCNAME, "&Show Procedure Name" + $TAB + "Ctrl+Shift+S"
                        CSED_CheckMenuOptions(hTrackPopUpMenu)
                        TrackPopupMenu(hTrackPopUpMenu, 0, rc.Left, rc.Bottom, 0, hwnd, BYVAL %NULL)
                        DestroyMenu hTrackPopUpMenu
                     ' // Dropdown fold options menu
                     CASE %IDM_FOLDOPTIONS
                        Toolbar_GetRect(@ptbn.hdr.hwndFrom, @ptbn.iItem, rc)
                        MapWindowPoints(@ptbn.hdr.hwndFrom, %HWND_DESKTOP, rc, 2)
                        hTrackPopUpMenu = CreatePopUpMenu
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_TOGGLE, "Toggle &Current Fold Point" + $TAB + "F8"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_TOGGLEALL, "Toggle Current and All &Below" + $TAB + "Ctrl+F8"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_FOLDALL, "&Fold All" + $TAB + "Alt+F8"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_UNFOLDALL, "&Unfold All" + $TAB + "Shift+F8"
                        TrackPopupMenu(hTrackPopUpMenu, 0, rc.Left, rc.Bottom, 0, hwnd, BYVAL %NULL)
                        DestroyMenu hTrackPopUpMenu
                     ' // Dropdown PB tools menu
                     CASE %IDM_PBFORMS
                        Toolbar_GetRect(@ptbn.hdr.hwndFrom, @ptbn.iItem, rc)
                        MapWindowPoints(@ptbn.hdr.hwndFrom, %HWND_DESKTOP, rc, 2)
                        hTrackPopUpMenu = CreatePopUpMenu
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_PBFORMS, "PowerBASIC &Forms" + $TAB + "F7"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_PBCOMBR, "PowerBASIC &COM Browser"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_POWERLIB, "PowerBASIC &Library Manager"
                        IF LEN(pSed.CompilerResults) THEN
                           AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_COMPILERRESULTS, "Compiler &Results"
                        ELSE
                           AppendMenu hTrackPopUpMenu, %MF_GRAYED, %IDM_COMPILERRESULTS, "Compiler &Results"
                        END IF
                        TrackPopupMenu(hTrackPopUpMenu, 0, rc.Left, rc.Bottom, 0, hwnd, BYVAL %NULL)
                        DestroyMenu hTrackPopUpMenu
                     ' // Dropdown headers menu
                     CASE %IDM_HEADERS
                        Toolbar_GetRect(@ptbn.hdr.hwndFrom, @ptbn.iItem, rc)
                        MapWindowPoints(@ptbn.hdr.hwndFrom, %HWND_DESKTOP, rc, 2)
                        hTrackPopUpMenu = CreatePopUpMenu
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_JRSINC1, "José Roca Headers I"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_JRSINC2, "José Roca Headers II"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_PBINC1, "PowerBASIC Headers I"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_PBINC2, "PowerBASIC Headers II"
                        CheckMenuItem hTrackPopUpMenu, %IDM_JRSINC1, IIF&(pSed.SelectedHeaders = 1, %MF_CHECKED, %MF_UNCHECKED)
                        CheckMenuItem hTrackPopUpMenu, %IDM_JRSINC2, IIF&(pSed.SelectedHeaders = 2, %MF_CHECKED, %MF_UNCHECKED)
                        CheckMenuItem hTrackPopUpMenu, %IDM_PBINC1, IIF&(pSed.SelectedHeaders = 3, %MF_CHECKED, %MF_UNCHECKED)
                        CheckMenuItem hTrackPopUpMenu, %IDM_PBINC2, IIF&(pSed.SelectedHeaders = 4, %MF_CHECKED, %MF_UNCHECKED)
                        TrackPopupMenu(hTrackPopUpMenu, 0, rc.Left, rc.Bottom, 0, hwnd, BYVAL %NULL)
                        DestroyMenu hTrackPopUpMenu
                     ' // Dropdown tools menu
                     CASE %IDM_TOOLS
                        Toolbar_GetRect(@ptbn.hdr.hwndFrom, @ptbn.iItem, rc)
                        MapWindowPoints(@ptbn.hdr.hwndFrom, %HWND_DESKTOP, rc, 2)
                        hTrackPopUpMenu = CreatePopUpMenu
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_TOOLS, "&Tools Manager" + $TAB + "F11"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_CALCULATOR, "&Calculator" + $TAB + "Ctrl+Shift+U"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_CHARMAP, "Character &Map" + $TAB + "Ctrl+Shift+K"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_NOTEPAD, "&Notepad" + $TAB + "Ctrl+Shift+N"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_MSPAINT, "&Paint" + $TAB + "Ctrl+Shift+P"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_RUNFILEDLG, "&Run File Dialog..." & $TAB & "Ctrl+Shift+R"
                        TrackPopupMenu(hTrackPopUpMenu, 0, rc.Left, rc.Bottom, 0, hwnd, BYVAL %NULL)
                        DestroyMenu hTrackPopUpMenu
                     ' // Dropdown help menu
                     CASE %IDM_HELP
                        Toolbar_GetRect(@ptbn.hdr.hwndFrom, @ptbn.iItem, rc)
                        MapWindowPoints(@ptbn.hdr.hwndFrom, %HWND_DESKTOP, rc, 2)
                        hTrackPopUpMenu = CreatePopUpMenu
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_HELP, "&Help Context" + $TAB + "F1"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_HELPCONTENTS, "Help Contents" + $TAB + "Ctrl+Alt+F1"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_HELPINDEX, "Help Index" + $TAB + "Ctrl+Alt+F2"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_HELPSEARCH, "Help Search" + $TAB + "Ctrl+Alt+F3"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, 0, ""
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, 0, ""
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_PBWINHELP, "PBWin Help"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_PBCCHELP, "PBCC Help"
                        AppendMenu hTrackPopUpMenu, %MF_ENABLED, %IDM_RCHELP, "Resource Compiler Help"
                        TrackPopupMenu(hTrackPopUpMenu, 0, rc.Left, rc.Bottom, 0, hwnd, BYVAL %NULL)
                        DestroyMenu hTrackPopUpMenu
                  END SELECT
               END IF
         END SELECT
         SELECT CASE @pnmhdr.code
            ' // Toolbar tooltips
            CASE %TTN_GETDISPINFO
               pttdi = lParam
               @pttdi.hinst = GetModuleHandle(BYVAL %NULL)
               SELECT CASE @pttdi.hdr.hwndFrom
                  CASE ToolBar_GetTooltips(pSed.hToolbar), ToolBar_GetTooltips(pSed.hBottomToolbar)
                     CSED_ToolbarTooltips(pttdi)
                     EXIT FUNCTION
                  CASE TabCtrl_GetTooltips(pSed.hTabMdi)
'                     vPath = pSed.TabFilePaths.Item(@pttdi.hdr.idFrom + 1)
                     pTabFilePaths = pSed.TabFilePaths
                     vPath = pTabFilePaths.Item(@pttdi.hdr.idFrom + 1)
                     szTooltipText = VARIANT$$(vPath)
                     @pttdi.lpszText = VARPTR(szTooltipText)
                     EXIT FUNCTION
               END SELECT
            ' // Tab control selection changed
            CASE %TCN_SELCHANGE
               IF @pnmhdr.idFrom = %IDC_TABMDI THEN
                  ' // Identify the selected tab
                  nTab = TabCtrl_GetCurSel(pSed.hTabMdi)
                  ' // Activate the associated edit control
                  IF pSed.TabFilePaths.Count => nTab + 1 THEN
'                     vPath = pSed.TabFilePaths.Item(nTab + 1)
                     pTabFilePaths = pSed.TabFilePaths
                     vPath = pTabFilePaths.Item(nTab + 1)
                     CSED_TabMdiActivateWindow(VARIANT$$(vPath))
                  END IF
               END IF
         END SELECT

         ' // Pass unprocessed messages to the active MDI child and then to DefFrameProc()
         hwndActive = MdiGetActive(hwndClient)
         IF IsWindow(hwndActive) THEN SendMessage hwndActive, %WM_NOTIFY, wParam, lParam

      CASE %WM_GETMINMAXINFO
         ' // Set the pointer to the address of the MINMAXINFO structure
         LOCAL ptmmi AS MINMAXINFO PTR
         ptmmi = lParam
         ' // Set the minimum and maximum sizes that can be
         ' // produced by dragging the borders of the window
         pWindow = CWindow_GetObjectFromWindowHandle(hwnd)
         IF ISOBJECT(pWindow) THEN
            @ptmmi.ptMinTrackSize.x = 525 * pWindow.rxRatio
            @ptmmi.ptMinTrackSize.y = 125 * pWindow.ryRatio
            pWindow = NOTHING
         ELSE
            @ptmmi.ptMinTrackSize.x = 525
            @ptmmi.ptMinTrackSize.y = 125
         END IF
         EXIT FUNCTION

      CASE %WM_SIZE
         ' // If the window isn't minimized, resize it
         IF wParam <> %SIZE_MINIMIZED THEN
            ' // Resize the toolbar
            hToolBar = GetDlgItem(hwnd, %IDC_TOOLBAR)
            SendMessage hToolBar, uMsg, wParam, lParam
            ' // Calculate the size of the toolbar
            LOCAL ToolBarHeight AS DWORD
            GetWindowRect hToolbar, rc
            ToolBarHeight = rc.Bottom - rc.Top
            ' // Calculate the size of the bottom toolbar
            hBottomToolBar = GetDlgItem(hwnd, %IDC_BOTTOMTOOLBAR)
            LOCAL BottomToolBarHeight AS DWORD
            BottomToolBarHeight = ToolbarHeight
            ' // Resize the status bar
            hStatusBar = GetDlgItem(hwnd, %IDC_STATUSBAR)
            SendMessage hStatusbar, %WM_SIZE, wParam, lParam
'            InvalidateRect hStatusbar, BYVAL %NULL, %TRUE
            ' // Calculate the size of the status bar
            LOCAL StatusBarHeight AS DWORD
            GetWindowRect hStatusBar, rc
            StatusBarHeight = rc.Bottom - rc.Top
            ' // Resize the tab control for MDI windows
            LOCAL TabMdiHeight AS DWORD
            hTabMdi = GetDlgItem(hwnd, %IDC_TABMDI)
            GetWindowRect hTabMdi, rc
            TabMdiHeight = rc.Bottom - rc.Top
            GetClientRect hwnd, rc
            MoveWindow hTabMdi, rc.Left, rc.Top + ToolBarHeight, rc.Right + 2, TabMdiHeight, %TRUE
            MoveWindow hBottomToolBar, rc.Left, rc.Bottom - StatusBarHeight - BottomToolBarHeight, rc.Right + 2, BottomToolBarHeight, %TRUE
            ' // Resize the MDI client window
            IF hwndClient THEN
               ' // Retrieve the coordinates of the window's client area
               GetClientRect hwnd, rc
               MoveWindow hwndClient, rc.Left, rc.Top + ToolBarHeight + TabMdiHeight, rc.Right + 2, rc.Bottom - ToolBarHeight - TabMdiHeight - StatusBarHeight - BottomToolbarHeight, %TRUE
            END IF
            ' // Redraw the Scintilla edit control
            IF pSed.hEdit THEN RedrawWindow pSed.hEdit, BYVAL %NULL, %NULL, %RDW_ERASE OR %RDW_FRAME OR %RDW_INVALIDATE
         END IF
         ' // Note: This message is not passed to DefFrameProc when space
         ' // is being reserved in the client area of the MDI frame
         ' // or controls on the MDI frame are resizeable.
         EXIT FUNCTION

      CASE %WM_CLOSE
         IF pSed.AskBeforeExit THEN
            r = CSED_MsgBox(hwnd, "Are you sure you want to exit?", _
                  %MB_YESNO OR %MB_ICONWARNING, "Exit CSED")
            IF r = %IDNO THEN EXIT FUNCTION
         END IF
         ' // Save paths of loaded files
         pSed.SaveFileSet
         ' // Attempt to close all MDI child windows
         EnumChildWindows hwndClient, CODEPTR(CSED_CloseEnumProc), 0
         ' // If child windows are still open abort closing the application
         IF GetWindow(hwndClient, %GW_CHILD) THEN EXIT FUNCTION

      CASE %WM_QUERYENDSESSION
         ' // Attempt to close all MDI child windows
         EnumChildWindows hwndClient, CODEPTR(CSED_CloseEnumProc), 0
         ' // If child windows are still open abort closing the application
         IF GetWindow(hwndClient, %GW_CHILD) THEN EXIT FUNCTION

      CASE %WM_DESTROY
         ' // Disable drag and drop files
         DragAcceptFiles hwnd, %FALSE
         ' // Save the window placement
         IF pSed.WindowPlacement THEN pSed.SaveWindowPlacement(hwnd)
         ' // Save last folder
         pSed.LastFolder = CURDIR$
         ' // Close the main window
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   IF hwndClient THEN
   ' // The DefFrameProc function provides default processing for any window
   ' // messages that the window procedure of a multiple-document interface (MDI)
   ' // frame window does not process. All window messages that are not explicitly
   ' // processed by the window procedure must be passed to the DefFrameProc
   ' // function, not the DefWindowProc function.
      FUNCTION = DefFrameProc(hwnd, hwndClient, uMsg, wParam, lParam)
   ELSE
   ' // The DefWindowProc function calls the default window procedure to provide
   ' // default processing for any window messages that an application does not process.
   ' // This function ensures that every message is processed. DefWindowProc
   ' // is called with the same parameters received by the window procedure.
      FUNCTION = DefWindowProc(hwnd, uMsg, wParam, lParam)
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Default CWindow MDI callback function.
' ========================================================================================
FUNCTION CSED_MDIWindowProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL hEdit      AS DWORD             ' // Handle of the edit control
   LOCAL fTime      AS DWORD             ' // File time
   LOCAL fSavedTime AS DWORD             ' // Saved file time
   LOCAL nTab       AS LONG              ' // Tab index
   LOCAL pWindow    AS IWindow           ' // Reference to the IWindow interface
   LOCAL rc         AS RECT              ' // Client coordinates
   LOCAL strPath    AS STRING            ' // File path
   LOCAL pt         AS POINT             ' // POINT structure
   LOCAL cp         AS LONG              ' // Cursor position
   LOCAL selStart   AS LONG              ' // Selection start
   LOCAL selEnd     AS LONG              ' // Selection end
   LOCAL hPopupMenu AS DWORD             ' // Popup menu handle
   LOCAL x          AS LONG              ' // Word starting position
   LOCAL y          AS LONG              ' // Word ending position
   LOCAL buffer     AS STRING            ' // General purpose buffer
   LOCAL tProc      AS CSED_PROCSTRUCT   ' // PROC structure

   SELECT CASE uMsg

      CASE %WM_CREATE
         ' // Retrieve a reference to the CWindow class from the MDI child window handle
         pWindow = CWindow_GetObjectFromWindowHandle(hwnd)
         ' // Create and edit control control
         IF ISOBJECT(pWindow) THEN
            GetClientRect hwnd, rc
            hEdit = pWindow.AddControl("Scintilla", hwnd, %IDC_EDIT, "", 0, 0, 0, 0, _
                    %WS_CHILD OR %WS_VISIBLE OR %ES_MULTILINE OR %WS_VSCROLL OR %WS_HSCROLL OR _
                    %ES_AUTOHSCROLL OR %ES_AUTOVSCROLL OR %ES_NOHIDESEL, 0)
            pWindow = NOTHING
            EXIT FUNCTION
         END IF

      CASE %WM_MDIACTIVATE
         IF lParam = hWnd THEN
            ' // Show the procedure name in the statusbar
            CSED_ResetCodefinder(pSed.hCodeFinderCB)
            IF pSed.ShowProcedureName THEN
               CSED_WithinProc(tProc)
               StatusBar_SetText(pSed.hStatusbar, 4, tProc.ProcName)
            END IF
            EXIT FUNCTION
         END IF

      CASE %WM_SETFOCUS
         ' // Post a message to restore the focus later
         ' // (some actions can steal the focus if we set it now)
         PostMessage hwnd, %WM_USER + 999, pSed.hEdit, 0
         EXIT FUNCTION

      CASE %WM_USER + 999
         ' // Get the path from the window caption
         strPath = AfxGetWindowText(hwnd)
         IF LEFT$(UCASE$(strPath), 8) <> "UNTITLED" THEN
            ' // Get the time the file was last written
            fTime = CSED_GetFileTime(strPath)
            ' // Get the stored time
            fSavedTime = GetProp(hwnd, "FTIME")
            ' // If they are different ask for reloading else store the new time
            IF fSavedTime <> fTime THEN
               IF CSED_MsgBox(hwnd, strPath & $CRLF & _
                  "File was changed by another application. Reload it?  ", _
                  %MB_YESNO OR %MB_ICONQUESTION, "File modified externally") = %IDYES THEN
                  CSED_OpenFile strPath
               ELSE
                  SetProp hwnd, "FTIME", fTime
               END IF
            END IF
         END IF
         ' // Set the focus
         IF wParam THEN SetFocus wParam
         ' // Show line and column
         CSED_ShowLinCol
         ' // Activate the associated tab
         nTab = CSED_GetTabNumberFromPath(strPath)
         IF nTab > -1 THEN TabCtrl_SetCursel(pSed.hTabMdi, nTab)
         EXIT FUNCTION

      CASE %WM_COMMAND
         SELECT CASE LO(WORD, wParam)
            CASE %IDM_UNDO           : SendMessage pSed.hwndMain, %WM_COMMAND, %IDM_UNDO, 0
            CASE %IDM_REDO           : SendMessage pSed.hwndMain, %WM_COMMAND, %IDM_REDO, 0
            CASE %IDM_CLEAR          : SendMessage pSed.hwndMain, %WM_COMMAND, %IDM_CLEAR, 0
            CASE %IDM_CLEARALL       : SendMessage pSed.hwndMain, %WM_COMMAND, %IDM_CLEARALL, 0
            CASE %IDM_CUT            : SendMessage pSed.hwndMain, %WM_COMMAND, %IDM_CUT, 0
            CASE %IDM_COPY           : SendMessage pSed.hwndMain, %WM_COMMAND, %IDM_COPY, 0
            CASE %IDM_PASTE          : SendMessage pSed.hwndMain, %WM_COMMAND, %IDM_PASTE, 0
            CASE %IDM_SELECTALL      : SendMessage pSed.hwndMain, %WM_COMMAND, %IDM_SELECTALL, 0
            CASE %IDM_LINEDELETE     : SendMessage pSed.hwndMain, %WM_COMMAND, %IDM_LINEDELETE, 0
            CASE %IDM_BLOCKINDENT    : SendMessage pSed.hwndMain, %WM_COMMAND, %IDM_BLOCKINDENT, 0
            CASE %IDM_BLOCKUNINDENT  : SendMessage pSed.hwndMain, %WM_COMMAND, %IDM_BLOCKUNINDENT, 0
            CASE %IDM_COMMENT        : SendMessage pSed.hwndMain, %WM_COMMAND, %IDM_COMMENT, 0
            CASE %IDM_UNCOMMENT      : SendMessage pSed.hwndMain, %WM_COMMAND, %IDM_UNCOMMENT, 0
            CASE %IDM_FORMATREGION   : SendMessage pSed.hwndMain, %WM_COMMAND, %IDM_FORMATREGION, 0
            CASE %IDM_TABULATEREGION : SendMessage pSed.hwndMain, %WM_COMMAND, %IDM_TABULATEREGION, 0
            CASE %IDM_SELTOUPPERCASE : SendMessage pSed.hwndMain, %WM_COMMAND, %IDM_SELTOUPPERCASE, 0
            CASE %IDM_SELTOLOWERCASE : SendMessage pSed.hwndMain, %WM_COMMAND, %IDM_SELTOLOWERCASE, 0
            CASE %IDM_SELTOMIXEDCASE : SendMessage pSed.hwndMain, %WM_COMMAND, %IDM_SELTOMIXEDCASE, 0
            CASE %IDM_TOGGLEBOOKMARK : SendMessage pSed.hwndMain, %WM_COMMAND, %IDM_TOGGLEBOOKMARK, 0
            CASE %IDM_INSERTGUID     : SendMessage pSed.hwndMain, %WM_COMMAND, %IDM_INSERTGUID, 0
            CASE %IDM_HELP           : SendMessage pSed.hwndMain, %WM_COMMAND, %IDM_HELP, 0

            CASE %IDM_GOTOSELFILE
               ' // Retrieve the name of the file under the caret
               ' // Needed to get Alt+F7 to work
               ' // Note: Does not work if the path contains spaces.
               buffer = SCI_GetWord(pSed.hEdit)
               CSED_LoadSelectedFile(hwnd, buffer)
         END SELECT
         EXIT FUNCTION

      CASE %WM_CONTEXTMENU
         ' // Change the focus and the caret position if there is not selected text
         SetFocus wParam
         pt.x = LO(WORD, lParam)
         pt.y = HI(WORD, lParam)
         ScreenToClient wParam, pt
         cp = SCI_PositionFromPoint(wParam, pt.x, pt.y)
         selStart = SCI_GetSelectionStart(wParam)
         selEnd = SCI_GetSelectionEnd(wParam)
         IF selStart = selEnd THEN SCI_SetSel(wParam, cp, cp)
         ' // Retrieve the word under the cursor
         buffer = SCI_GetWord(pSed.hEdit)
         ' // Build the menu
         hPopupMenu = CSED_CreateContextMenu(buffer)
         GetCursorPos pt
         TrackPopupMenu hPopupMenu, 0, pt.x, pt.y, 0, hwnd, BYVAL %NULL
         DestroyMenu hPopupMenu
         UpdateWindow pSed.hEdit

      CASE %WM_NOTIFY
         ' // Process Scintilla control notification messages
         SELECT CASE LO(WORD, wParam)
         CASE %IDC_EDIT
            Sci_OnNotify hwnd, wParam, lParam
            EXIT FUNCTION
         END SELECT

      CASE %WM_SIZE
         IF wParam <> %SIZE_MINIMIZED THEN
            ' // Resize the window and/or its controls
            hEdit = GetDlgItem(hwnd, %IDC_EDIT)
            MoveWindow hEdit, 0, 0, LO(WORD, lParam), HI(WORD, lParam), %FALSE
         END IF

         ' Don't exit. Let DefMDIChildProc to process the message for
         ' properly resizing of the MDI child window.

      CASE %WM_DESTROY
         ' // Do cleanunp if needed, such removing properties attached
         ' // to the MDI child window.
         ' Remove the FTIME property
         RemoveProp(hwnd, "FTIME")
         ' // Remove the associated tab
         CSED_TabMdiRemoveTab(AfxGetWindowText(hwnd))
         ' // Clear the code finder combo box
         CSED_ResetCodefinder(pSed.hCodeFinderCB)
         EXIT FUNCTION

   END SELECT

   ' // The DefMDIChildProc function provides default processing for any window
   ' // message that the window procedure of a multiple-document interface (MDI)
   ' // child window does not process. A window message not processed by the window
   ' // procedure must be passed to the DefMDIChildProc function, not to the
   ' // DefWindowProc function.
   FUNCTION = DefMDIChildProc(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a new MDI child window
' ========================================================================================
FUNCTION CSED_CreateMdiChild (BYVAL strPath AS STRING) AS DWORD

   LOCAL hMdi AS DWORD
   LOCAL nTab AS LONG
   LOCAL bstrPath AS WSTRING

   ' // Disable redrawing
   AfxDisableWindowRedraw pSed.hwndClient

   hMdi = CreateMdiChild("PBFrameClass", pSed.hwndClient, BYCOPY strPath, IIF&(pSed.MaximizeEditWindows = %BST_CHECKED, %WS_MAXIMIZE, 0))
   IF hMdi THEN
      ' // Set the icon
      AfxSetWindowSmallIcon(hMdi, LoadIcon(GetModuleHandle(BYVAL %NULL), BYVAL 101))
      ' // Add new tab
      ' // --------------------------------------------
      ' // Workaround: The Add method of the linked list
      ' // collection needs an Unicode string
      bStrPath = strPath
      pSed.TabFilePaths.Add(bstrPath)
      ' // --------------------------------------------
      nTab = TabCtrl_AddTab(pSed.hTabMdi, 0, PATHNAME$(NAMEX, strPath))
      ' // Set it as the current selection on the tab control
      TabCtrl_SetCurSel(pSed.hTabMdi, nTab)
      ' // Note: In some OSes, such XP SP3 and Windows 7, files that begin with a number,
      ' // such 0.BAS are displayed in the tab wrongly, e.g. as BAS.0.
      ' // Apparently, it's a bug of the tab control.
      ' // As a workaround, call TabCtrl_SetText after adding and selecting the tab.
      TabCtrl_SetText(pSed.hTabMdi, nTab, PATHNAME$(NAMEX, strPath))
      ' // Set the Scintilla options
      CSED_SetScintillaOptions(pSed.hEdit, PATHNAME$(EXTN, strPath))
   END IF
   FUNCTION = hMdi

   ' // Enable redrawing
   AfxEnableWindowRedraw pSed.hwndClient
   ' // Redraw the window
   RedrawWindow pSed.hwndClient, BYVAL %NULL, %NULL, %RDW_ERASE OR %RDW_FRAME OR %RDW_INVALIDATE OR %RDW_ALLCHILDREN
   ' // Redraw the Scintilla edit control
   IF pSed.hEdit THEN RedrawWindow pSed.hEdit, BYVAL %NULL, %NULL, %RDW_ERASE OR %RDW_FRAME OR %RDW_INVALIDATE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Destroys all MDI child windows.
' ========================================================================================
FUNCTION CSED_CloseEnumProc ( _
   BYVAL hwnd AS DWORD, _                   ' // Handle of enumerated child window
   BYVAL lParam AS LONG _                   ' // Unused
   ) AS LONG

   ' // Skip icon title windows
   IF ISTRUE GetWindow(hwnd, %GW_OWNER) THEN
      FUNCTION = %TRUE
      EXIT FUNCTION
   END IF

'   SendMessage GetParent(hwnd), %WM_MDIRESTORE, hwnd, 0
   IF ISFALSE SendMessage(hwnd, %WM_QUERYENDSESSION, 0, 0) THEN
      FUNCTION = %TRUE
      EXIT FUNCTION
   END IF

   ' // Get the path of the file from the window caption
   LOCAL r AS LONG
   LOCAL strPath AS STRING
   strPath = AfxGetWindowText(hwnd)

   ' // See if the document has been modified
   IF SCI_GetModify(pSed.hEdit) THEN
      BEEP
      r = CSED_MsgBox(hwnd, "Save current changes? " & PATHNAME$(NAMEX, strPath), _
            %MB_YESNOCANCEL OR %MB_ICONQUESTION)
      IF r = %IDCANCEL THEN
         FUNCTION = %FALSE
         EXIT FUNCTION
      ELSE
         IF r = %IDYES THEN CSED_SaveFile hwnd, pSed.hEdit, %FALSE
      END IF
   END IF

   ' // Destroy the MDI child window
   MdiDestroy GetParent(hwnd), hwnd

   FUNCTION = %TRUE

END FUNCTION
' =======================================================================================