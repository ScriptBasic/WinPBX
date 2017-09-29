' ########################################################################################
' TypeLib Browser
' File: TLB_600.BAS
' Contents: TypeLib Browser
' Compiler: PowerBASIC for Windows 10
' Headers: Windows API Headers III
' Copyright (c) 2012-2014 José Roca. All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#COMPILE EXE
#DIM ALL
%UNICODE = 1

GLOBAL pTLB AS ITLB
GLOBAL pParseTypeLib AS IParseTypeLib

' // Constants
$PROGNAME     = "TLB_600"
$TLBVERSION   = "6.01"
$TLBCAPTION   = "TypeLib Browser 6.01"
$TLBCOPYRIGHT = "© 2012-2014 by José Roca"
$MAILADDRESS  = "JRoca@com.it-berater.org"

' // Icon identifiers
ENUM TLB_ICON_IDS SINGULAR
   IDI_TLB_LOGO_32 = 100
   IDI_TLB_LOGO_16 = 101
END ENUM

' // Resource file
#RESOURCE RES, ".\Resources\TLB_600.RES"  ' // Resource file

' // Include files for external files
#INCLUDE ONCE "CWindow.inc"            ' // CWindow class
#INCLUDE ONCE "RichEdit.inc"           ' // RichEdit include file
#INCLUDE ONCE "ToolBarCtrl.inc"        ' // Toolbar wrappers
#INCLUDE ONCE "StatusBarCtrl.inc"      ' // Status bar wrappers
#INCLUDE ONCE "TabCtrl.inc"            ' // Tab control wrappers
#INCLUDE ONCE "ListViewCtrl.inc"       ' // List view control wrappers
#INCLUDE ONCE "EditCtrl.inc"           ' // Edit control wrappers
#INCLUDE ONCE "ButtonCtrl.inc"         ' // Button control wrappers
#INCLUDE ONCE "TreeViewCtrl.inc"       ' // Tree view control wrappers
#INCLUDE ONCE "CAfxImageList.inc"      ' // Image list class
#INCLUDE ONCE "CAfxFileDialog.inc"     ' // Open File Dialog class

#INCLUDE ONCE "TLB_PROCS.inc"          ' // Procedures
#INCLUDE ONCE "TLB_CONTROLS.inc"       ' // Controls
#INCLUDE ONCE "TLB_CLASSES.inc"        ' // Classes
#INCLUDE ONCE "TLB_ENUMTLBS.inc"       ' // Enumerates type libraries

' ========================================================================================
' Main
' ========================================================================================
FUNCTION WinMain (BYVAL hInstance AS DWORD, BYVAL hPrevInstance AS DWORD, BYVAL lpszCmdLine AS WSTRINGZ PTR, BYVAL nCmdShow AS LONG) AS LONG

   ' // Create an instance of the CTLB class
   pTLB = CLASS "CTLB"
   IF ISNOTHING(pTLB) THEN EXIT FUNCTION

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' Retrieve the size of the working area
   LOCAL rc AS RECT
   SystemParametersInfo %SPI_GETWORKAREA, 0, rc, 0
   ' // Create the main window
   LOCAL hwndMain AS DWORD
   hwndMain = pWindow.CreateWindow(%NULL, $TLBCAPTION & " " & $TLBCOPYRIGHT, 0, 0, rc.Right - rc.Left, rc.Bottom - rc.Top, 0, 0, CODEPTR(WindowProc), %TRUE)
   pTLB.hwndMain = hwndMain
   ' // Set the icons
   pWindow.BigIcon = LoadIcon(hInstance, BYVAL %IDI_TLB_LOGO_32)
   pWindow.SmallIcon = LoadIcon(hInstance, BYVAL %IDI_TLB_LOGO_32)
   ' // Change the class style to avoid flicker
   pWindow.ClassStyle = %CS_DBLCLKS
   ' // Center the window
   pWindow.CenterWindow

   ' // Create the menu
   TLB_CreateMenu(pWindow)
   ' // Create the toolbar
   TLB_CreateToolBar(pWindow)
   ' // Create the status bar
   TLB_CreateStatusBar(pWindow)
   ' // Create the tab control
   TLB_CreateTabControl(pWindow)
   ' // Read the options
   pTLB.ReadOptions

   ' // Set the ListView columns order
   pTLB.SetColumnsOrderArray
   ' // Set the ListView columns width
   pTLB.SetColumnsWidth

   ' // Read saved window's state and placement
   pTLB.SetWindowPlacement(hwndMain)

   ' // Post a message to enumerate the type libraries
   PostMessage pWindow.hwnd, %WM_USER + 999, 0, 0

   ' // Default message pump (you can replace it with your own)
   pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main callback function.
' ========================================================================================
FUNCTION WindowProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL pnmhdr AS NMHDR PTR         ' // For notification messages
   LOCAL pttdi AS NMTTDISPINFO PTR   ' // For tooltip messages
   LOCAL tbn AS TBNOTIFY PTR         ' // For toolbar notification messages
   LOCAL hStatusBar AS DWORD         ' // Status bar handle
   LOCAL hMenu AS DWORD              ' // Menu handle
   LOCAL hSubMenu AS DWORD           ' // Submenu handle
   LOCAL rc AS RECT
   LOCAL wszText AS WSTRINGZ * 260

   STATIC hInstance AS DWORD         ' // Instance handle
   STATIC lpc AS CREATESTRUCT PTR    ' // Pointer to the creation parameters
   STATIC pWindow AS IWindow         ' // Reference to the IWindow interface

   ' // Process window mesages
   SELECT CASE uMsg

      CASE %WM_CREATE
         ' // Pointer to the creation parameters
         lpc = lParam
         ' // Instance handle
         hInstance = @lpc.hInstance
         ' // Get a reference to the IWindow interface from the CREATESTRUCT structure
         pWindow = CWindow_GetObjectFromCreateStruct(lParam)
         EXIT FUNCTION

      CASE %WM_COMMAND

         SELECT CASE LO(WORD, wParam)

'            CASE %IDCANCEL
'               ' // If the Escape key has been pressed...
'               IF HI(WORD, wParam) = %BN_CLICKED THEN
'                  ' // ... close the application by sending a WM_CLOSE message
'                  SendMessage hwnd, %WM_CLOSE, 0, 0
'                  EXIT FUNCTION
'               END IF

            ' // Display the about box
            CASE %IDM_ABOUT
               TLB_MsgBox hwnd, "TypeLib Browser version " & $TLBVERSION & $CRLF & _
                  "Object browser and code generator for PowerBASIC™" & $CRLF & _
                  "Copyright " & $TLBCOPYRIGHT & $CRLF & "All rights reserved", _
                  %MB_OK, "About TypeLib Browser"
               EXIT FUNCTION

            ' // Open a typelib loaded from disk
            CASE %IDM_OPEN
               TLB_LoadTypeLibFromFile(hwnd)
               EXIT FUNCTION

            ' // Expand all the nodes of the treeview
            CASE %IDM_EXPAND
               #IF %DEF(%PB_WIN32)
               MOUSEPTR 11   ' // Hourglass cursor
               #ENDIF
               ' // Disables redraw to minimize flicker
               AfxDisableWindowRedraw(pTLB.hTreeView)
               TreeView_ExpandAllItems pTLB.hTreeView
               TreeView_SelectSetFirstVisible pTLB.hTreeView, TreeView_GetSelection(pTLB.hTreeView)
               ' // Enables redraw and repaints the control
               AfxEnableWindowRedraw(pTLB.hTreeView)
               AfxRedrawWindow(pTLB.hTreeView)
               #IF %DEF(%PB_WIN32)
               MOUSEPTR 1    ' // Arrow cursor
               #ENDIF
               EXIT FUNCTION

            ' // Collapse all the nodes of the treeview
            CASE %IDM_COLLAPSE
               #IF %DEF(%PB_WIN32)
               MOUSEPTR 11   ' // Hourglass cursor
               #ENDIF
               TreeView_CollapseAllChildItems pTLB.hTreeView, TreeView_GetChild(pTLB.hTreeView, TreeView_GetRoot(pTLB.hTreeView))
               #IF %DEF(%PB_WIN32)
               MOUSEPTR 1    ' // Arrow cursor
               #ENDIF
               EXIT FUNCTION

            ' // Restore the size of the main window
            CASE %IDM_RESTOREWSIZE
               SystemParametersInfo %SPI_GETWORKAREA, 0, rc, 0
               MoveWindow hwnd, 0, 0, rc.Right - rc.Left, rc.Bottom - rc.Top, %TRUE
               AfxCenterWindow hwnd
               EXIT FUNCTION

            ' // End the application
            CASE %IDM_EXIT
               SendMessage hwnd, %WM_CLOSE, 0, 0
               EXIT FUNCTION

            CASE %IDM_RELOAD
               ' // Save the selected item
               pTLB.SaveSelectedItem
               ' // Post a message to enumerate the type libraries
               PostMessage hwnd, %WM_USER + 999, 0, 0
               ' // Restore the selected item
               pTLB.SetSelectedItem
               EXIT FUNCTION

            ' // Code generation
            CASE %IDM_CODEGEN
               #IF %DEF(%PB_WIN32)
               MOUSEPTR 11   ' // Hourglass cursor
               #ENDIF
               IF ISOBJECT(pParseTypeLib) THEN pParseTypeLib.GenerateCode
               #IF %DEF(%PB_WIN32)
               MOUSEPTR 1    ' // Arrow cursor
               #ENDIF
               EXIT FUNCTION

         END SELECT

      ' // Processes notification messages
      CASE %WM_NOTIFY

         LOCAL nPage AS DWORD         ' // Page number
         LOCAL pTabPage AS IWindow    ' // Tab page object reference
         LOCAL tci AS TCITEM          ' // TCITEM structure

         pnmhdr = lParam
         SELECT CASE @pnmhdr.idFrom
            CASE %IDC_TAB
               SELECT CASE @pnmhdr.code
                  CASE %TCN_SELCHANGE
                     ' // Show the selected page
                     nPage = TabCtrl_GetCurSel(@pnmhdr.hwndFrom)
                     tci.mask = %TCIF_PARAM
                     TabCtrl_GetItem(@pnmhdr.hwndFrom, nPage, tci)
                     IF tci.lParam THEN
                        pTabPage = Ptr2Obj(tci.lParam)
                        IF ISOBJECT(pTabPage) THEN
                           ShowWindow pTabPage.hwnd, %SW_SHOW
                           SetFocus pTabPage.hwnd
                           pTabPage = NOTHING
                        END IF
                     END IF
                  CASE %TCN_SELCHANGING
                     ' // Hide the current page
                     nPage = TabCtrl_GetCurSel(@pnmhdr.hwndFrom)
                     tci.mask = %TCIF_PARAM
                     TabCtrl_GetItem(@pnmhdr.hwndFrom, nPage, tci)
                     IF tci.lParam THEN
                        pTabPage = Ptr2Obj(tci.lParam)
                        IF ISOBJECT(pTabPage) THEN
                           ShowWindow pTabPage.hwnd, %SW_HIDE
                           pTabPage = NOTHING
                        END IF
                     END IF
               END SELECT
         END SELECT

         SELECT CASE @pnmhdr.code
            ' // Toolbar tooltips
            CASE %TTN_GETDISPINFO
               pttdi = lParam
               @pttdi.hinst = GetModuleHandle(BYVAL %NULL)
               SELECT CASE @pttdi.hdr.hwndFrom
                  CASE ToolBar_GetTooltips(pTLB.hToolbar)
                     TLB_ToolbarTooltips(pttdi)
                     EXIT FUNCTION
                  CASE TabCtrl_GetToolTips(pTLB.hTab)
                     TLB_TabTooltips(pttdi)
                     EXIT FUNCTION
               END SELECT
         END SELECT

      CASE %WM_GETMINMAXINFO
         ' // Set the pointer to the address of the MINMAXINFO structure
         LOCAL pmmi AS MINMAXINFO PTR   ' // Pointer to the maximized and tracking info
         pmmi = lParam
         ' // A bug in the operating system causes the WM_GETMINMAXINFO message to be sent
         ' // before the WM_NCCREATE and WM_CREATE messages.  A nonzero font handle indicates
         ' // that the window has processed these messages and is fully initialized.
         IF ISOBJECT(pWindow) THEN
            IF pWindow.hFont THEN
               ' Set the minimum and maximum sizes that can be produced by dragging the borders of the window
               @pmmi.ptMinTrackSize.x = 450 * pWindow.rxRatio
               @pmmi.ptMinTrackSize.y = 140 * pWindow.ryRatio
               EXIT FUNCTION
            END IF
         END IF

      CASE %WM_SIZE
         ' // If the window isn't minimized, resize it
         IF wParam <> %SIZE_MINIMIZED THEN
            ' // Resize the toolbar
            LOCAL hToolbar AS DWORD
            hToolBar = GetDlgItem(hwnd, %IDC_TOOLBAR)
            IF hToolBar THEN
               SendMessage hToolBar, uMsg, wParam, lParam
               ' // Calculate the size of the toolbar
               LOCAL ToolBarHeight AS DWORD
               pWindow.GetControlWindowRect(hToolBar, rc)
               ToolBarHeight = (rc.Bottom - rc.Top)
            END IF
            ' // Resize the status bar
            hStatusBar = GetDlgItem(hwnd, %IDC_STATUSBAR)
            IF hStatusBar THEN
               SendMessage hStatusBar, uMsg, wParam, lParam
               ' // Redraw it
'               InvalidateRect hStatusBar, BYVAL %NULL, %TRUE
               ' // Calculate the size of the status bar
               LOCAL StatusBarHeight AS DWORD
               pWindow.GetControlWindowRect(hStatusBar, rc)
               StatusBarHeight = (rc.Bottom - rc.Top)
            END IF
            ' // Resize the tab control
            LOCAL hTab AS DWORD
            hTab = GetDlgItem(hwnd, %IDC_TAB)
            IF hTab THEN
               pWindow.MoveWindow hTab, 0, ToolBarHeight, pWindow.ClientWidth, pWindow.ClientHeight - ToolBarHeight - StatusBarHeight, %TRUE
               ' // Resize the tab pages
               GetWindowRect hTab, rc
               TabCtrl_AdjustRect(hTab, %FALSE, rc)
               MapWindowPoints %NULL, hTab, rc, 2
               LOCAL pTabTypeLibs AS IWindow
               pTabTypeLibs = pTLB.pTabTypeLibs
               IF ISOBJECT(pTabTypeLibs) THEN
                  MoveWindow pTabTypeLibs.hwnd, rc.Left, rc.Top, rc.Right - GetSystemMetrics(%SM_CYDLGFRAME), rc.Bottom - rc.Top, %TRUE
                  pTabTypeLibs = NOTHING
               END IF
               LOCAL pTabCode AS IWindow
               pTabCode = pTLB.pTabCode
               IF ISOBJECT(pTabCode) THEN
                  MoveWindow pTabCode.hwnd, rc.Left, rc.Top, rc.Right - GetSystemMetrics(%SM_CYDLGFRAME), rc.Bottom - rc.Top, %TRUE
                  pTabCode = NOTHING
               END IF
               LOCAL pTabOptions AS IWindow
               pTabOptions = pTLB.pTabOptions
               IF ISOBJECT(pTabOptions) THEN
                  MoveWindow pTabOptions.hwnd, rc.Left, rc.Top, rc.Right - GetSystemMetrics(%SM_CYDLGFRAME), rc.Bottom - rc.Top, %TRUE
                  pTabOptions = NOTHING
               END IF
            END IF
         END IF

      CASE %WM_USER + 998
         ' // Sets the focus in the control specified by wParam
         SetFocus wParam
         EXIT FUNCTION

      CASE %WM_USER + 999
         ' // Disables redraw to minimize flicker
         AfxDisableWindowRedraw(pTLB.hListView)
         ' // Delete all items
         ListView_DeleteAllItems(pTLB.hListView)
         ' // Enumerate the type libraries
         TLB_RegEnumTypeLibs pTLB.hListView
         ' // Enables redraw and repaints the control
         AfxEnableWindowRedraw(pTLB.hListView)
         ' // Sort the items
         IF pTLB.ColumnSortOrder = "DESCEND" THEN pTLB.ColumnSortOrder = "ASCEND" ELSE pTLB.ColumnSortOrder = "DESCEND"
         TLB_ListviewSortItems(pTLB.hListView)
         ' // Display info in the status bar
         wszText = FORMAT$(ListView_GetItemCount(pTLB.hListView)) & " TypeLibs"
         StatusBar_SetText pTLB.hStatusBar, 0, wszText
         wszText = "Double click the wanted item to retrieve information"
         StatusBar_SetText pTLB.hStatusBar, 3, wszText
         ' // Set the focus in the list view
         SetFocus pTLB.hListView
         ' // Restore ListView selected item
         pTLB.SetSelectedItem
         EXIT FUNCTION

      CASE %WM_SYSCOLORCHANGE
         ' // Forward this message to common controls so that they will
         ' // be properly updated when the user changes the color settings.
         SendMessage pTLB.hToolbar, %WM_SYSCOLORCHANGE, wParam, lParam
         SendMessage pTLB.hStatusBar, %WM_SYSCOLORCHANGE, wParam, lParam
         SendMessage pTLB.hTab, %WM_SYSCOLORCHANGE, wParam, lParam
         SendMessage pTLB.pTabTypeLibs.hwnd, %WM_SYSCOLORCHANGE, wParam, lParam
         SendMessage pTLB.pTabCode.hwnd, %WM_SYSCOLORCHANGE, wParam, lParam
         SendMessage pTLB.pTabOptions.hwnd, %WM_SYSCOLORCHANGE, wParam, lParam

      CASE %WM_DESTROY
         ' // Save ListView selected item
         pTLB.SaveSelectedItem
         ' // Save ListView columns order
         pTLB.SaveColumnsOrderArray
         ' // Save ListView columns width
         pTLB.SaveColumnsWidth
         ' // Save the window placement
         pTLB.SaveWindowPlacement(hwnd)
         ' // End the application
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   ' // Pass unprocessed messages to Windows
   FUNCTION = DefWindowProc(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Open file dialog (class).
' ========================================================================================
SUB TLB_LoadTypeLibFromFile (BYVAL hwnd AS DWORD)

   STATIC bstrSelectedPath AS WSTRING
   LOCAL pofd AS IAfxFileDialog
   pofd = CLASS "CAfxFileDialog"
   IF ISNOTHING(pofd) THEN EXIT SUB

   pofd.DefaultFolder = IIF$(LEN(bstrSelectedPath) > 0, bstrSelectedPath, CURDIR$)
   pofd.FileName = "*.TLB;*.OLB;*.EXE;*.DLL;*.OCX"
   pofd.DefaultExtension = "BAS"
   pofd.Filter = CHR$("Type/Object Files (*.TLB;*.OLB)", 0, "*.TLB", 0, "*.OLB", 0) & _
                 CHR$("Object Modules (*.EXE;*.DLL;*.OCX)", 0, "*.EXE", 0, "*.DLL", 0,  "*.OCX", 0) & _
                 CHR$("All Files (*.*)", 0, "*.*", 0)
   pofd.Options = %OFN_EXPLORER OR %OFN_FILEMUSTEXIST
   IF pofd.ShowOpenDialog THEN
      LOCAL pFiles AS IPowerCollection
      LOCAL vFile AS VARIANT
      pFiles = pofd.Files
      bstrSelectedPath = pofd.SelectedPath
      vFile = pFiles.Item("1")
      IF VARIANT$$(vFile) <> "" THEN
         LOCAL bstrPath AS WSTRING
         bstrPath = bstrSelectedPath & VARIANT$$(vFile)
         ' // Load and parse the type library
         pParseTypeLib = NOTHING
         pParseTypeLib = CLASS "CParseTypeLib"
         IF ISOBJECT(pParseTypeLib) THEN
            #IF %DEF(%PB_WIN32)
            MOUSEPTR 11   ' // Hourglass cursor
            #ENDIF
            IF pParseTypeLib.LoadTypeLibEx(bstrPath) = %S_OK THEN SetFocus pTLB.hTreeView
            #IF %DEF(%PB_WIN32)
            MOUSEPTR 1    ' // Arrow cursor
            #ENDIF
         END IF
      END IF
   END IF

END SUB
' ========================================================================================
