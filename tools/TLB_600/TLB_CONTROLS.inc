' ########################################################################################
' TypeLib Browser
' File: TLB_CONTROLS.INC
' Contents: TypeLib Browser controls
' Compiler: PowerBASIC for Windows 10.02+
' Headers: Windows API Headers 2.04+
' Copyright (c) 2011 José Roca. All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

ENUM TLB_CONTROLS_IDS SINGULAR
   IDC_TOOLBAR = 1001
   IDC_STATUSBAR
   IDC_EDITPREFIX
   IDC_TAB
   IDC_LISTVIEW
   IDC_TREEVIEW
   IDC_VIEWCODE
   IDC_USEPROPGETSET
   IDC_USEMETHOD
   IDC_USESETPREFIX
   IDC_USEPRMNAMES
   IDC_ADDPRMNAMESPREFIX
   IDC_USEINTNAMESWITHEXOBJ
   IDC_USEPREFIX
   IDC_USEENUMPREFIX
   IDC_USEHEXNUMBERS
   IDC_MIXDISPINTERFACES
   IDC_RETRIEVELICENSEKEY
END ENUM

' // Menu and toolbar identifiers
ENUM TLB_MENU_IDS SINGULAR
   IDM_FILE = 28000
   IDM_OPEN
   IDM_SAVE
   IDM_RELOAD
   IDM_RESTOREWSIZE
   IDM_EXIT
   ' ---
   IDM_EVENTS
   IDM_CODEGEN
   IDM_EXPAND
   IDM_COLLAPSE
   ' ---
   IDM_HELP
   IDM_ABOUT
END ENUM

' ========================================================================================
' Builds and attaches the menu
' ========================================================================================
FUNCTION TLB_CreateMenu (BYVAL pWindow AS IWindow) AS DWORD

   LOCAL hMenu AS DWORD
   LOCAL hPopUpMenu AS DWORD
   LOCAL hPopUpSubmenu AS DWORD

   hMenu = CreateMenu
   pTLB.hMenu = hMenu
   hPopUpMenu = CreatePopUpMenu
   pTLB.hMenuFile = hPopUpMenu
      AppendMenu hMenu, %MF_POPUP OR %MF_ENABLED, hPopUpMenu, "&File"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_OPEN, "&Open..." & $TAB & "Ctrl+O"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_SAVE, "&Save..." & $TAB & "Ctrl+S"
         AppendMenu hPopUpMenu, %MF_SEPARATOR, 0, ""
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_RESTOREWSIZE, "Restore Main &Window Size"
         AppendMenu hPopUpMenu, %MF_SEPARATOR, 0, ""
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_EXIT, "E&xit" & $TAB & "Alt+F4"
   hPopUpMenu = CreatePopUpMenu
   pTLB.hMenuHelp = hPopUpMenu
      AppendMenu hMenu, %MF_POPUP OR %MF_ENABLED, hPopUpMenu, "&Help"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_HELP, "&Help"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_ABOUT, "&About..."

   ' // Right justify some menus
   AfxRightJustifyMenuItem(hMenu, 1)
   ' // Bold the text of the Help menu
   AfxSetMenuItemBold(hMenu, 1)
   ' // Bold the text of Exit
   AfxSetMenuItemBold(pTLB.hMenuFile, 5)

   ' // Attach the menu to the main window
   SetMenu pWindow.hwnd, hMenu

   FUNCTION = hMenu

END FUNCTION
' ========================================================================================

' ========================================================================================
' Bitmap icons identifiers in the resource file
' Don't change them unless you also change the defines in the .rc file
' ========================================================================================

%IDB_TLB_RELOAD_24     = 101
%IDB_TLB_RELOAD_D_24   = 102
%IDB_TLB_COLLAPSE_24   = 103
%IDB_TLB_COLLAPSE_D_24 = 104
%IDB_TLB_EXPAND_24     = 105
%IDB_TLB_EXPAND_D_24   = 106
%IDB_TLB_CODEGEN_24    = 107
%IDB_TLB_CODEGEN_D_24  = 108
%IDB_TLB_EVENTS_24     = 109
%IDB_TLB_EVENTS_D_24   = 110
%IDB_TLB_SAVE_24       = 111
%IDB_TLB_SAVE_D_24     = 112
%IDB_TLB_HELP_24       = 113
%IDB_TLB_HELP_D_24     = 114
%IDB_TLB_EXIT_24       = 115
%IDB_TLB_EXIT_D_24     = 116

' ========================================================================================
' Creates the toolbar
' ========================================================================================
FUNCTION TLB_CreateToolBar (BYVAL pWindow AS IWindow) AS DWORD

   LOCAL hToolBar AS DWORD

   ' // Create the ToolBar Window.
   hToolBar = pWindow.AddToolBar(pWindow.hwnd, %IDC_TOOLBAR, "", 0, 0, 0, 0, _
              %WS_CHILD OR %WS_VISIBLE OR %TBSTYLE_TOOLTIPS OR %TBSTYLE_FLAT OR %TBSTYLE_LIST, %WS_EX_STATICEDGE)
   ' // Set the extended style
   ToolBar_SetExtendedStyle hToolbar, %TBSTYLE_EX_DRAWDDARROWS

   ' // Set the size of the bitmapped images
   ToolBar_SetBitmapSize(hToolbar, 24, 24)

   ' // Add buttons to the toolbar
   Toolbar_AddButton hToolBar, 0, %IDM_RELOAD,   0, 0, 0, "Reload"
   Toolbar_AddButton hToolBar, 1, %IDM_EXPAND,   0, 0, 0, "Expand"
   Toolbar_AddButton hToolBar, 2, %IDM_COLLAPSE, 0, 0, 0, "Collapse"
   Toolbar_AddButton hToolBar, 3, %IDM_CODEGEN,  0, 0, 0, "Code"
   Toolbar_AddButton hToolBar, 4, %IDM_EVENTS,   0, 0, 0, "Events"
   Toolbar_AddButton hToolBar, 5, %IDM_SAVE,     0, 0, 0, "Save"
   Toolbar_AddButton hToolBar, 6, %IDM_HELP,     0, 0, 0, "Help"
   Toolbar_AddButton hToolBar, 7, %IDM_EXIT,     0, 0, 0, "Exit"

   ' // Update the size of the toolbar
   ToolBar_AutoSize(hToolbar)

   ' // Set the image lists
   ToolBar_SetImageList(hToolbar, pTLB.hToolbarImageListNormal24)
   ToolBar_SetDisabledImageList(hToolbar, pTLB.hToolbarImageListDisabled24)

   ' // Store the toolbar handle in the class
   pTLB.hToolBar = hToolBar

   ' // Return the handle of the toolbar
   FUNCTION = hToolbar

END FUNCTION
' ========================================================================================

' ========================================================================================
' Create normal image list 24 x 24 for toolbar
' ========================================================================================
FUNCTION TLB_CreateToolbarImageListNormal_24 () AS IAfxImageList

   LOCAL pAfxImageList AS IAfxImageList
   pAfxImageList = CLASS "CAfxImageList"
   IF ISNOTHING(pAfxImageList) THEN EXIT FUNCTION

   ' // Create the image list
   pAfxImageList.CreateImageList(24, 24, %ILC_COLOR32 OR %ILC_MASK, 9)

   ' // Give a name to the image list
   pAfxImageList.Name = "Toolbar image list normal 24"

   ' // Add the bitmaps from the resource file
   pAfxImageList.LoadResBitmapMasked(%IDB_TLB_RELOAD_24)
   pAfxImageList.LoadResBitmapMasked(%IDB_TLB_EXPAND_24)
   pAfxImageList.LoadResBitmapMasked(%IDB_TLB_COLLAPSE_24)
   pAfxImageList.LoadResBitmapMasked(%IDB_TLB_CODEGEN_24)
   pAfxImageList.LoadResBitmapMasked(%IDB_TLB_EVENTS_24)
   pAfxImageList.LoadResBitmapMasked(%IDB_TLB_SAVE_24)
   pAfxImageList.LoadResBitmapMasked(%IDB_TLB_HELP_24)
   pAfxImageList.LoadResBitmapMasked(%IDB_TLB_EXIT_24)

   FUNCTION = pAfxImageList

END FUNCTION
' ========================================================================================

' ========================================================================================
' Create disabled image list 24 x 24 for toolbar
' ========================================================================================
FUNCTION TLB_CreateToolbarImageListDisabled_24 () AS IAfxImageList

   LOCAL pAfxImageList AS IAfxImageList
   pAfxImageList = CLASS "CAfxImageList"
   IF ISNOTHING(pAfxImageList) THEN EXIT FUNCTION

   ' // Create the image list
   pAfxImageList.CreateImageList(24, 24, %ILC_COLOR32 OR %ILC_MASK, 8)

   ' // Give a name to the image list
   pAfxImageList.Name = "Toolbar image list disabled 24"

   ' // Add the bitmaps from the resource file
   pAfxImageList.LoadResBitmapMasked(%IDB_TLB_RELOAD_D_24)
   pAfxImageList.LoadResBitmapMasked(%IDB_TLB_EXPAND_D_24)
   pAfxImageList.LoadResBitmapMasked(%IDB_TLB_COLLAPSE_D_24)
   pAfxImageList.LoadResBitmapMasked(%IDB_TLB_CODEGEN_D_24)
   pAfxImageList.LoadResBitmapMasked(%IDB_TLB_EVENTS_D_24)
   pAfxImageList.LoadResBitmapMasked(%IDB_TLB_SAVE_D_24)
   pAfxImageList.LoadResBitmapMasked(%IDB_TLB_HELP_D_24)
   pAfxImageList.LoadResBitmapMasked(%IDB_TLB_EXIT_D_24)

   FUNCTION = pAfxImageList

END FUNCTION
' ========================================================================================

' ========================================================================================
' Toolbar tooltips
' ========================================================================================
SUB TLB_ToolbarTooltips (BYVAL pttdi AS NMTTDISPINFO PTR)

   LOCAL wszText AS WSTRINGZ * %MAX_PATH

   SELECT CASE @pttdi.hdr.idFrom
      CASE %IDM_RELOAD       : wszText = "Reload typelibs"
      CASE %IDM_EXPAND       : wszText = "Expand tree view nodes"
      CASE %IDM_COLLAPSE     : wszText = "Collapse tree view nodes"
      CASE %IDM_CODEGEN      : wszText = "Code generation"
      CASE %IDM_EVENTS       : wszText = "Events code generation"
      CASE %IDM_SAVE         : wszText = "Save generated code"
      CASE %IDM_HELP         : wszText = "Activate the help file"
      CASE %IDM_EXIT         : wszText = "Exit the application"
   END SELECT

   IF LEN(wszText) THEN @pttdi.szText = wszText

END SUB
' ========================================================================================

' ========================================================================================
' Toolbar tooltips
' ========================================================================================
SUB TLB_TabTooltips (BYVAL pttdi AS NMTTDISPINFO PTR)

   LOCAL wszText AS WSTRINGZ * %MAX_PATH

   SELECT CASE @pttdi.hdr.idFrom
      CASE 0 : wszText = "List of registered typelibs"
      CASE 1 : wszText = "Text box with the generated code"
      CASE 2 : wszText = "Custom options"
   END SELECT

   IF LEN(wszText) THEN @pttdi.szText = wszText

END SUB
' ========================================================================================

' ========================================================================================
' Creates the status bar
' ========================================================================================
FUNCTION TLB_CreateStatusBar (BYVAL pWindow AS IWindow) AS DWORD

   LOCAL hStatusBar AS DWORD

   ' // Create the status bar
   hStatusBar = pWindow.AddStatusBar(pWindow.hwnd, %IDC_STATUSBAR, "", 0, 0, 0, 0, _
                %WS_CHILD OR %WS_VISIBLE OR %WS_BORDER OR %CCS_BOTTOM OR %SBARS_SIZEGRIP)
   ' // Store the handle in the class
   pTLB.hStatusBar = hStatusBar

   ' // Set the parts
   pWindow.SetStatusbarPartsBySize(hStatusBar, "80, 35, 160, -1")
   StatusBar_SetText hStatusBar, 0, "0 TypeLibs"
   StatusBar_SetText hStatusBar, 1, "Prefix"

   ' // Update the size of the statusbar
   SendMessage hStatusBar, %WM_SIZE, 0, 0

   ' // Create the edit control for the prefix
   LOCAL hEditPrefix AS DWORD
   hEditPrefix = pWindow.AddTextBox(hStatusBar, %IDC_EDITPREFIX, "", 116, 1, 158, 17)
   pTLB.hEditPrefix = hEditPrefix
   Edit_SetLimitText hEditPrefix, 255

   ' // Return the handle of the status bar
   FUNCTION = hStatusBar

END FUNCTION
' ========================================================================================

' ========================================================================================
' Add a tab control
' ========================================================================================
FUNCTION TLB_CreateTabControl (BYVAL pWindow AS IWindow) AS DWORD

   LOCAL dwExStyle AS DWORD
   LOCAL rc AS RECT

   ' // Calculate the size of the toolbar
   LOCAL ToolBarHeight AS DWORD
   GetWindowRect pTLB.hToolbar, rc
   ToolBarHeight = (rc.Bottom - rc.Top) \ pWindow.ryRatio

   ' // Calculate the size of the status bar
   LOCAL StatusBarHeight AS DWORD
   GetWindowRect pTLB.hStatusBar, rc
   StatusBarHeight = (rc.Bottom - rc.Top) \ pWindow.ryRatio

   LOCAL hTab AS DWORD
   hTab = pWindow.AddTab(pWindow.hwnd, %IDC_TAB, "", 0, ToolBarHeight, pWindow.ClientWidth, _
          pWindow.ClientHeight - ToolBarHeight - StatusBarHeight, %WS_CHILD OR %WS_VISIBLE OR %WS_CLIPCHILDREN OR _
          %WS_CLIPSIBLINGS OR %WS_GROUP OR %WS_TABSTOP OR %TCS_FORCELABELLEFT OR %TCS_TABS OR %TCS_FIXEDWIDTH OR %TCS_TOOLTIPS)
   pTLB.hTab = hTab

   ' // Add the tab pages
   LOCAL pTabTypeLibs, pTabCode, pTabOptions AS IWindow
   IF AfxGetWindowsVersion > 5.00 THEN dwExStyle = %WS_EX_COMPOSITED   ' Avoids flicker - Must be Windows XP or superior
   ' // Don't use WS_EX_COMPOSITED with the dialog that hosts the list view
   pTabTypeLibs = pWindow.InsertTabPage(hTab, 0, "TypeLibs", -1, 0, 0, CODEPTR(TLB_TabTypeLibs_WndProc))
   pTabCode = pWindow.InsertTabPage(hTab, 2, "Code", -1, 0, dwExStyle, CODEPTR(TLB_TabCode_WndProc))
   pTabOptions = pWindow.InsertTabPage(hTab, 3, "Options", -1, 0, dwExStyle, CODEPTR(TLB_TabOptions_WndProc))
   pTabOptions.Brush = %COLOR_WINDOW + 1
   pTLB.pTabTypeLibs = pTabTypeLibs
   pTLB.pTabCode = pTabCode
   pTLB.pTabOptions = pTabOptions

   ' // Display the first tab page
   ShowWindow pTabTypeLibs.hwnd, %SW_SHOW
   ' // Set the focus to the first tab
   TabCtrl_SetCurFocus hTab, 0

   ' // Add a list view to the first page
   LOCAL hListView AS DWORD
   hListView = pTabTypeLibs.AddListView(pTabTypeLibs.hwnd, %IDC_LISTVIEW, "", 0, 0, (pTabTypeLibs.ClientWidth \ 1), pTabTypeLibs.ClientHeight, _
               %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %LVS_REPORT OR %LVS_SINGLESEL OR %LVS_SHOWSELALWAYS OR %LVS_NOSORTHEADER)
   pTLB.hListView = hListView

   ' Set the extended class styles for the control
   ' Note: LVS_EX_GRIDLINES doesn't work properly with XP.
   ' See: http://support.microsoft.com/kb/813791
   IF AfxGetWindowsVersion < 6.00 THEN
      dwExStyle = %LVS_EX_HEADERDRAGDROP OR %LVS_EX_FULLROWSELECT OR %LVS_EX_INFOTIP OR %LVS_EX_DOUBLEBUFFER
   ELSE
      dwExStyle = %LVS_EX_GRIDLINES OR %LVS_EX_HEADERDRAGDROP OR %LVS_EX_FULLROWSELECT OR %LVS_EX_INFOTIP OR %LVS_EX_DOUBLEBUFFER
   END IF
   ListView_SetExtendedListViewStyle(hListView, dwExStyle)

   ' // Remove the buttons style from the header control to give it a flat appearance
   LOCAL hwndHdr AS DWORD
   hwndHdr = ListView_GetHeader(hListView)
   SetWindowLong hwndHdr, %GWL_STYLE, GetWindowLong(hwndHdr, %GWL_STYLE) XOR %HDS_BUTTONS
   SetWindowPos hListView, %NULL, 0, 0, 0, 0, %SWP_NOZORDER OR %SWP_NOMOVE OR %SWP_NOSIZE OR %SWP_DRAWFRAME

   ' // Add the columns
   ListView_AddColumn hListView, 0, "Description", 245 * pWindow.rxRatio, %LVCFMT_LEFT
   ListView_AddColumn hListView, 1, "File Name", 110 * pWindow.rxRatio, %LVCFMT_LEFT
   ListView_AddColumn hListView, 2, "Full Path", 500 * pWindow.rxRatio, %LVCFMT_LEFT
   ListView_AddColumn hListView, 3, "CLSID", 250 * pWindow.rxRatio, %LVCFMT_LEFT

   ' // Add a tree view to the 1st page
   LOCAL hTreeView AS DWORD
   dwExStyle = 0
   IF AfxGetWindowsVersion > 5.00 THEN dwExStyle = %WS_EX_COMPOSITED   ' Avoids flicker - Must be Windows XP or superior
   hTreeView = pTabTypeLibs.AddTreeView(pTabTypeLibs.hwnd, %IDC_TREEVIEW, "", (pTabTypeLibs.ClientWidth \ 2), 0, pTabTypeLibs.ClientWidth \ 2, pTabTypeLibs.ClientHeight, 0, dwExStyle)
   pTLB.hTreeView = hTreeView

   ' // Add a subclassed edit control to the 2nd page
   LOCAL hCodeView AS DWORD
   hCodeView = pTabCode.AddTextBox(pTabCode.hwnd, %IDC_VIEWCODE, "", 0, 0, pTabCode.ClientWidth, pTabCode.ClientHeight, _
      %WS_CHILD OR %WS_VISIBLE OR %WS_HSCROLL OR %WS_VSCROLL OR %WS_BORDER OR %WS_TABSTOP OR %ES_LEFT OR _
      %ES_AUTOHSCROLL OR %ES_AUTOVSCROLL OR %ES_MULTILINE OR %ES_NOHIDESEL OR %ES_WANTRETURN OR %ES_SAVESEL, _
      %WS_EX_CLIENTEDGE, CODEPTR(TLB_Edit_CodeView_WndProc))
   pTLB.hCodeView = hCodeView
   Edit_SetLimitText hCodeView, 31457279
   ' // Create a font for the Code view edit control
   LOCAL hFont AS DWORD
   hFont = pWindow.CreateFont("Lucida Console", 9, %FW_NORMAL, %FALSE, %FALSE, %FALSE, %DEFAULT_CHARSET)
   ' // Set the font
   AfxSetWindowFont hCodeView, hFont
   pTLB.hCodeViewFont = hFont

   ' // Add controls to the options page
   pTabOptions.AddCheckBox(pTabOptions.hwnd, %IDC_USEPROPGETSET, _
                        "Use METHOD and PROPERTY GET/SET statements", 30, 28, 310, 21)
   pTabOptions.AddCheckBox(pTabOptions.hwnd, %IDC_USEMETHOD, _
                        "Use METHOD statements only", 30, 58, 310, 21)
   pTabOptions.AddCheckBox(pTabOptions.hwnd, %IDC_USESETPREFIX, _
                        "Use SET_ instead of PUT_ as prefix", 30, 88, 310, 21)
   pTabOptions.AddCheckBox(pTabOptions.hwnd, %IDC_USEPRMNAMES, _
                        "Use parameter names in interface declarations", 30, 118, 310, 21)
   pTabOptions.AddCheckBox(pTabOptions.hwnd, %IDC_ADDPRMNAMESPREFIX, _
                        "Add prefix to parameter names", 30, 148, 310, 21)
   pTabOptions.AddCheckBox(pTabOptions.hwnd, %IDC_USEINTNAMESWITHEXOBJ, _
                        "Use interface names with external objects", 30, 178, 310, 21)
   pTabOptions.AddCheckBox(pTabOptions.hwnd, %IDC_USEPREFIX, _
                        "Use prefix in interface names", 370, 28, 310, 21)
   pTabOptions.AddCheckBox(pTabOptions.hwnd, %IDC_USEENUMPREFIX, _
                        "Use enumeration names as prefix in constants", 370, 58, 310, 21)
   pTabOptions.AddCheckBox(pTabOptions.hwnd, %IDC_USEHEXNUMBERS, _
                        "Use hexadecimal numbers in constants", 370, 88, 310, 21)
   pTabOptions.AddCheckBox(pTabOptions.hwnd, %IDC_MIXDISPINTERFACES, _
                        "Include dispatch only interfaces", 370, 118, 310, 21)
   pTabOptions.AddCheckBox(pTabOptions.hwnd, %IDC_RETRIEVELICENSEKEY, _
                        "Retrieve license key", 370, 148, 310, 21)

   FUNCTION = hTab

END FUNCTION
' ========================================================================================

' ========================================================================================
' Tab typelibs window procedure
' ========================================================================================
FUNCTION TLB_TabTypeLibs_WndProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL rc AS RECT
   LOCAL pnmhdr AS NMHDR PTR
   LOCAL pnmlvi AS NMLISTVIEW PTR
   LOCAL nItem AS LONG
   LOCAL bstrPath AS WSTRING

   SELECT CASE uMsg

      CASE %WM_SETFOCUS
         StatusBar_SetText(pTLB.hStatusBar, 3, "Double click the wanted item to retrieve information")
         PostMessage pTLB.hwndMain, %WM_USER + 998, pTLB.hListView, 0
         EXIT FUNCTION

      CASE %WM_SIZE
         ' // If the window isn't minimized, resize it
         IF wParam <> %SIZE_MINIMIZED THEN
            IF pTLB.hListView THEN
               GetClientRect hwnd, rc
               MoveWindow pTLB.hListView, rc.Left, rc.Top, (rc.Right \ 2), rc.Bottom - rc.Top, %TRUE
            END IF
            IF pTLB.hTreeView THEN
               MoveWindow pTLB.hTreeView, (rc.Right \ 2), rc.Top, (rc.Right \ 2), rc.Bottom - rc.Top, %TRUE
            END IF
         END IF

      CASE %WM_NOTIFY
         pnmhdr = lParam
         SELECT CASE @pnmhdr.idFrom
            CASE %IDC_LISTVIEW
               SELECT CASE @pnmhdr.code
                  CASE %LVN_COLUMNCLICK
                     pnmlvi = pnmhdr
                     ' // Sort items by the clicked column
                     pTLB.ColumnToSort = @pnmlvi.iSubItem
                     TLB_ListviewSortItems @pnmhdr.hwndFrom
                     EXIT FUNCTION
                  CASE %NM_DBLCLK
                     ' // Retrieve the path of the type library
                     nItem = ListView_GetSelectionMark(@pnmhdr.hwndFrom)
                     bstrPath = ListView_GetText(@pnmhdr.hwndFrom, nItem, 2)
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
                     EXIT FUNCTION
               END SELECT

         END SELECT

      CASE %WM_SYSCOLORCHANGE
         ' // Forward this message to common controls so that they will
         ' // be properly updated when the user changes the color settings.
         SendMessage pTLB.hListView, %WM_SYSCOLORCHANGE, wParam, lParam
         SendMessage pTLB.hTreeView, %WM_SYSCOLORCHANGE, wParam, lParam

   END SELECT

   FUNCTION = DefWindowProc(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Tab code window procedure
' ========================================================================================
FUNCTION TLB_TabCode_WndProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL rc AS RECT

   SELECT CASE uMsg

      CASE %WM_SETFOCUS
         StatusBar_SetText(pTLB.hStatusBar, 3, "Ctrl+A = Select all | Ctrl+C = Copy to clipboard | Ctrl+V = Paste from clipboard")
         PostMessage pTLB.hwndMain, %WM_USER + 998, pTLB.hCodeView, 0
         EXIT FUNCTION

      CASE %WM_SIZE
         ' // If the window isn't minimized, resize it
         IF wParam <> %SIZE_MINIMIZED THEN
            GetClientRect hwnd, rc
            IF pTLB.hCodeView THEN
               MoveWindow pTLB.hCodeView, rc.Left, rc.Top, rc.Right, rc.Bottom - rc.Top, %TRUE
            END IF
            EXIT FUNCTION
         END IF

   END SELECT

   FUNCTION = DefWindowProc(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Tab options window procedure
' ========================================================================================
FUNCTION TLB_TabOptions_WndProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL hBrush AS DWORD
   LOCAL rc AS RECT
   LOCAL tlb AS LOGBRUSH

   SELECT CASE uMsg

      CASE %WM_COMMAND
         SELECT CASE LO(WORD, wParam)
            CASE %IDC_USEMETHOD
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  pTLB.UseMethod = Button_GetCheck(lParam)
                  IF Button_GetCheck(lParam) = %BST_CHECKED THEN
                     pTLB.UsePropGetSet = %BST_UNCHECKED
                     Button_SetCheck(GetDlgItem(hwnd, %IDC_USEPROPGETSET), %BST_UNCHECKED)
                  ELSE
                     pTLB.UsePropGetSet = %BST_CHECKED
                     Button_SetCheck(GetDlgItem(hwnd, %IDC_USEPROPGETSET), %BST_CHECKED)
                  END IF
               END IF
            CASE %IDC_USEPROPGETSET
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  pTLB.UsePropGetSet = Button_GetCheck(lParam)
                  IF Button_GetCheck(lParam) = %BST_CHECKED THEN
                     pTLB.UseMethod = %BST_UNCHECKED
                     Button_SetCheck(GetDlgItem(hwnd, %IDC_USEMETHOD), %BST_UNCHECKED)
                  ELSE
                     pTLB.UseMethod = %BST_CHECKED
                     Button_SetCheck(GetDlgItem(hwnd, %IDC_USEMETHOD), %BST_CHECKED)
                  END IF
               END IF
            CASE %IDC_USEPREFIX
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  pTLB.UsePrefix = Button_GetCheck(lParam)
               END IF
            CASE %IDC_USEENUMPREFIX
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  pTLB.UseEnumPrefix = Button_GetCheck(lParam)
               END IF
            CASE %IDC_USEHEXNUMBERS
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  pTLB.UseHexNumbers = Button_GetCheck(lParam)
               END IF
            CASE %IDC_USESETPREFIX
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  pTLB.UseSetPrefix = Button_GetCheck(lParam)
               END IF
            CASE %IDC_USEPRMNAMES
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  pTLB.UseParameterNames = Button_GetCheck(lParam)
               END IF
            CASE %IDC_ADDPRMNAMESPREFIX
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  pTLB.AddParameterNamesPrefix = Button_GetCheck(lParam)
               END IF
            CASE %IDC_USEINTNAMESWITHEXOBJ
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  pTLB.UseIntNamesWithExObj = Button_GetCheck(lParam)
               END IF
            CASE %IDC_USEPREFIX
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  pTLB.UsePrefix = Button_GetCheck(lParam)
               END IF
            CASE %IDC_USEENUMPREFIX
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  pTLB.UseEnumPrefix = Button_GetCheck(lParam)
               END IF
            CASE %IDC_USEHEXNUMBERS
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  pTLB.UseHexNumbers = Button_GetCheck(lParam)
               END IF
            CASE %IDC_MIXDISPINTERFACES
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  pTLB.MixDispInterfaces = Button_GetCheck(lParam)
               END IF
            CASE %IDC_RETRIEVELICENSEKEY
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  pTLB.RetrieveLicenseKey = Button_GetCheck(lParam)
               END IF
         END SELECT
         EXIT FUNCTION

      CASE %WM_SETFOCUS
         StatusBar_SetText(pTLB.hStatusBar, 3, "Check the wanted options using the mouse or the space bar")
         PostMessage pTLB.hwndMain, %WM_USER + 998, GetDlgItem(hwnd, %IDC_USEPROPGETSET), 0
         EXIT FUNCTION

      CASE %WM_CTLCOLORSTATIC
         SELECT CASE GetDlgCtrlID(lParam)
            CASE %IDC_USEPROPGETSET, %IDC_USEMETHOD, %IDC_USESETPREFIX, %IDC_USEPRMNAMES, _
                 %IDC_ADDPRMNAMESPREFIX, %IDC_USEINTNAMESWITHEXOBJ, %IDC_USEPREFIX, %IDC_USEENUMPREFIX, _
                 %IDC_USEHEXNUMBERS, %IDC_MIXDISPINTERFACES, %IDC_RETRIEVELICENSEKEY
               SetBkColor wParam, GetSysColor(%COLOR_WINDOW)
               ' // Return handle of brush used to paint background
               FUNCTION = GetSysColorBrush(%COLOR_WINDOW)
               EXIT FUNCTION
         END SELECT

   END SELECT

   FUNCTION = DefWindowProc(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Code text box window procedure
' ========================================================================================
FUNCTION TLB_Edit_CodeView_WndProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   ' // REQUIRED: Get the address of the original window procedure
   LOCAL pOldWndProc AS DWORD
   pOldWndProc = GetProp(hwnd, "OLDWNDPROC")

   SELECT CASE uMsg
      CASE %WM_DESTROY
         ' // REQUIRED: Remove control subclassing
         SetWindowLong hwnd, %GWL_WNDPROC, RemoveProp(hwnd, "OLDWNDPROC")
      CASE %WM_KEYDOWN
         ' // If Ctrl+A or Ctrl+E pressed, select all the text
         IF wParam = %VK_A OR wParam = %VK_E THEN
            IF GetAsyncKeyState(%VK_CONTROL) THEN
               PostMessage hwnd, %EM_SETSEL, 0, -1
            END IF
         END IF
         ' // Eat the Escape key to avoid the page being destroyed
         IF wParam = %VK_ESCAPE THEN EXIT FUNCTION
   END SELECT

   FUNCTION = CallWindowProc(pOldWndProc, hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
