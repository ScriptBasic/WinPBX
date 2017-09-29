' ########################################################################################
' CSED Editor
' File: CSED_TOOLBAR.INC
' Contents: CSED editor toolbars
' Copyright (c) 2012 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ========================================================================================
' Creates the toolbars
' ========================================================================================
FUNCTION CSED_CreateTopToolBar (BYVAL pWindow AS IWindow) AS DWORD

   LOCAL hToolBar AS DWORD
   LOCAL ptbb AS TBBUTTON PTR
   LOCAL idx AS LONG

   ' // Create the ToolBar Window.
   hToolBar = pWindow.AddToolBar(pWindow.hwnd, %IDC_TOOLBAR, "", 0, 0, 0, 0, _
              %WS_CHILD OR %WS_VISIBLE OR %TBSTYLE_TOOLTIPS OR %TBSTYLE_FLAT)

   ' // Set the extended style
   SendMessage hToolbar, %TB_SETEXTENDEDSTYLE, 0, %TBSTYLE_EX_DRAWDDARROWS

   ' // Add buttons to the toolbar
   Toolbar_AddButton hToolBar, 0, %IDM_NEW, 0, %TBSTYLE_DROPDOWN
   Toolbar_AddButton hToolBar, 1, %IDM_OPEN, 0, %TBSTYLE_DROPDOWN
   Toolbar_AddButton hToolBar, 2, %IDM_SAVE
   Toolbar_AddButton hToolBar, 3, %IDM_SAVEAS
   Toolbar_AddButton hToolBar, 4, %IDM_REFRESH
   Toolbar_AddButton hToolBar, 5, %IDM_CLOSEFILE
   Toolbar_AddSeparator hToolBar
   Toolbar_AddButton hToolBar, 6, %IDM_UNDO
   Toolbar_AddButton hToolBar, 7, %IDM_REDO
   Toolbar_AddSeparator hToolBar
   Toolbar_AddButton hToolBar, 8, %IDM_CUT
   Toolbar_AddButton hToolBar, 9, %IDM_COPY
   Toolbar_AddButton hToolBar, 10, %IDM_PASTE
   Toolbar_AddSeparator hToolBar
   Toolbar_AddSeparator hToolBar, 100 * pWindow.rxRatio  ' // Make room for the combobox
   Toolbar_AddSeparator hToolBar
   Toolbar_AddButton hToolBar, 13, %IDM_COMPILE
   Toolbar_AddButton hToolBar, 14, %IDM_COMPILEANDRUN
   Toolbar_AddButton hToolBar, 15, %IDM_EXECUTE
   Toolbar_AddSeparator hToolBar
   Toolbar_AddButton hToolBar, 11, %IDM_FIND, 0, %TBSTYLE_DROPDOWN
   Toolbar_AddButton hToolBar, 12, %IDM_REPLACE
   Toolbar_AddButton hToolBar, 22, %IDM_BOOKMARKOPTIONS, 0, %TBSTYLE_DROPDOWN
   Toolbar_AddSeparator hToolBar
   Toolbar_AddButton hToolBar, 19, %IDM_PRINT
   Toolbar_AddButton hToolBar, 16, %IDM_DOS
   Toolbar_AddButton hToolBar, 17, %IDM_EXIT
   Toolbar_AddButton hToolBar, 20, %IDM_MAIL

   ' // Update the size of the toolbar
   SendMessage hToolbar, %TB_AUTOSIZE, 0, 0

   ' // Create the image lists for the toolbars
   CSED_CreateToolbarImageListNormal(pWindow)
   CSED_CreateToolbarImageListDisabled(pWindow)

   ' // Set the image lists
   ToolBar_SetImageList(hToolbar, pSed.hToolbarImageListNormal)
   ToolBar_SetHotImageList(hToolbar, pSed.hToolbarImageListNormal)

   ' // Creates a combobox and embeds it in the toolbar
   LOCAL hComboBox AS DWORD
   LOCAL dwStyle AS DWORD
   LOCAL rc AS RECT
   LOCAL nTop AS LONG
   ToolBar_GetItemRect(hToolbar, 14, rc)
   dwStyle = %WS_CHILD OR %WS_VISIBLE OR %CBS_DROPDOWNLIST OR %CBS_SORT OR %WS_VSCROLL OR %WS_HSCROLL ' OR %CBS_NOINTEGRALHEIGHT
   nTop = 1
   IF pWindow.IsProcessDPIAware THEN
      IF pWindow.DPI => 120 THEN nTop = 3 ELSE IF pWindow.DPI => 144 THEN nTop = 5
   END IF
   hComboBox = pWindow.AddComboBox(pWindow.hwnd, %IDC_CODEFINDER, "", rc.Left, nTop, rc.Right - rc.Left, 400 * pWindow.ryRatio, dwStyle, 0, 0, %TRUE)
   ComboBox_SetDroppedWidth hComboBox, 410 * pWindow.rxRatio
   pSed.hCodeFinderCB = hComboBox
   SetParent hComboBox, hToolbar
   ComboBox_ResetContent hComboBox
   Combobox_AddStringA hComboBox, "(Code finder)"
   ComboBox_SetItemData hComboBox, 0, 1
   ComboBox_SetCurSel hComboBox, 0

   ' // Store the toolbar handle in the class
   pSed.hToolBar = hToolBar

   ' // Return the handle of the toolbar
   FUNCTION = hToolbar

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates the bottom toolbar
' ========================================================================================
FUNCTION CSED_CreateBottomToolBar (BYVAL pWindow AS IWindow) AS DWORD

   LOCAL hBottomToolBar AS DWORD
   LOCAL ptbb AS TBBUTTON PTR
   LOCAL idx AS LONG

   ' // Create the ToolBar Window.
   hBottomToolBar = pWindow.AddToolBar(pWindow.hwnd, %IDC_BOTTOMTOOLBAR, "", 0, 0, 0, 0, _
              %WS_CHILD OR %WS_VISIBLE OR %CCS_NORESIZE OR %TBSTYLE_TOOLTIPS OR %TBSTYLE_FLAT)

   ' // Set the extended style
   SendMessage hBottomToolBar, %TB_SETEXTENDEDSTYLE, 0, %TBSTYLE_EX_DRAWDDARROWS

   ' // Add buttons to the toolbar
   Toolbar_AddButton hBottomToolBar, 26, %IDM_VIEWOPTIONS, 0, %TBSTYLE_DROPDOWN
   Toolbar_AddButton hBottomToolBar, 27, %IDM_FOLDOPTIONS, 0, %TBSTYLE_DROPDOWN
   Toolbar_AddSeparator hBottomToolBar
   Toolbar_AddButton hBottomToolBar, 24, %IDM_ZOOMIN
   Toolbar_AddButton hBottomToolBar, 25, %IDM_ZOOMOUT
   Toolbar_AddSeparator hBottomToolBar
   Toolbar_AddButton hBottomToolBar, 28, %IDM_PBFORMS, 0, %TBSTYLE_DROPDOWN
   Toolbar_AddButton hBottomToolBar, 29, %IDM_TOGGLECOMPILER
   Toolbar_AddButton hBottomToolBar, 39, %IDM_DEBUGTOOL
   Toolbar_AddButton hBottomToolBar, 44, %IDM_HEADERS, 0, %TBSTYLE_DROPDOWN
   Toolbar_AddSeparator hBottomToolBar
   Toolbar_AddButton hBottomToolBar, 40, %IDM_LYNX
   Toolbar_AddButton hBottomToolBar, 23, %IDM_FINDINFILES
   Toolbar_AddButton hBottomToolBar, 34, %IDM_MSGBOXDESIGNER
   Toolbar_AddSeparator hBottomToolBar
   Toolbar_AddButton hBottomToolBar, 37, %IDM_FILESTAMP
   Toolbar_AddButton hBottomToolBar, 38, %IDM_BACKUPMGR
   Toolbar_AddButton hBottomToolBar, 30, %IDM_CODEKEEPER
   Toolbar_AddButton hBottomToolBar, 35, %IDM_CODETIPSBUILDER
   Toolbar_AddButton hBottomToolBar, 36, %IDM_KBDMACROS
   Toolbar_AddSeparator hBottomToolBar
   Toolbar_AddButton hBottomToolBar, 41, %IDM_VISDES
   Toolbar_AddButton hBottomToolBar, 42, %IDM_ICONED
   Toolbar_AddButton hBottomToolBar, 43, %IDM_IMGED
   Toolbar_AddButton hBottomToolBar, 31, %IDM_TYPELIBBR
   Toolbar_AddSeparator hBottomToolBar
   Toolbar_AddButton hBottomToolBar, 32, %IDM_TOOLS, 0, %TBSTYLE_DROPDOWN
   Toolbar_AddButton hBottomToolBar, 33, %IDM_HELP, 0, %TBSTYLE_DROPDOWN

   ' // Update the size of the toolbar
   SendMessage hBottomToolBar, %TB_AUTOSIZE, 0, 0

   ' // Set the image lists
   ToolBar_SetImageList(hBottomToolbar, pSed.hToolbarImageListNormal)
   ToolBar_SetHotImageList(hBottomToolbar, pSed.hToolbarImageListNormal)

   ' // Store the toolbar handle in the class
   pSed.hBottomToolBar = hBottomToolBar

   ' // Return the handle of the toolbar
   FUNCTION = hBottomToolBar

END FUNCTION
' ========================================================================================

' ========================================================================================
' Create normal image list for toolbar
' ========================================================================================
FUNCTION CSED_CreateToolbarImageListNormal (BYVAL pWindow AS IWindow) AS IAfxImageList

   LOCAL pAfxImageList AS IAfxImageList
   pAfxImageList = CLASS "CAfxImageList"
   IF ISNOTHING(pAfxImageList) THEN EXIT FUNCTION

   LOCAL hInstance AS DWORD
   hInstance = GetModuleHandle("")

   LOCAL cx, cy AS LONG
   cx = 16 : cy = 16
   IF pWindow.IsProcessDPIAware THEN
      IF pWindow.DPI => 120 AND pWindow.DPI < 144 THEN
         cx = 20 : cy = 20
      ELSEIF pWindow.DPI => 144 AND pWindow.DPI < 192 THEN
         cx = 24 : cy = 24
      ELSEIF pWindow.DPI => 192 THEN
         cx = 32 : cy = 32
      END IF
   END IF

   ' // Create the image list
   pAfxImageList.CreateImageList(cx, cy, %ILC_COLOR32 OR %ILC_MASK, 45)

   ' // Give a name to the image list
   pAfxImageList.Name = "Toolbar image list normal"

   ' // Add the bitmaps from the resource file
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_NEW_DOCUMENT_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_OPEN_DOCUMENT_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_SAVE_DOCUMENT_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_SAVE_DOCUMENT_AS_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_REFRESH_DOCUMENT_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_CLOSE_DOCUMENT_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_UNDO_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_REDO_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_CUT_CLIPBOARD_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_COPY_CLIPBOARD_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_PASTE_CLIPBOARD_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_FIND_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_REPLACE_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_COMPILE_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_COMPILE_AND_RUN_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_EXECUTE_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_DOS_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_EXIT_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_PRINT_PREVIEW_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_PRINT_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_MAIL_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_SEARCHOP_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_BOOKMARKS_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_FINDINFILES_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_ZOOMIN_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_ZOOMOUT_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_VIEWOPT_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_FOLDOP_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_POWERBASIC_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_TOGGLECOMPILER_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_CODEKEEPER_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_TLB_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_TOOLS_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_HELP_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_MBD_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_CODETIPS_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_KBDMACROS_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_CLOCK_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_BACKUPMGR_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_DEBUGTOOL_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_LYNX_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_VISDES_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_ICONED_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_IMGED_24_H")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_HEADERS_24_H")

   pSed.pToolbarImageListNormal = pAfxImageList

   FUNCTION = pAfxImageList

END FUNCTION
' ========================================================================================

' ========================================================================================
' Create disabled image list for toolbar
' ========================================================================================
FUNCTION CSED_CreateToolbarImageListDisabled (BYVAL pWindow AS IWindow) AS IAfxImageList

   LOCAL pAfxImageList AS IAfxImageList
   pAfxImageList = CLASS "CAfxImageList"
   IF ISNOTHING(pAfxImageList) THEN EXIT FUNCTION

   LOCAL hInstance AS DWORD
   hInstance = GetModuleHandle("")

   LOCAL cx, cy AS LONG
   cx = 16 : cy = 16
   IF pWindow.IsProcessDPIAware THEN
      IF pWindow.DPI => 120 AND pWindow.DPI < 144 THEN
         cx = 20 : cy = 20
      ELSEIF pWindow.DPI => 144 AND pWindow.DPI < 192 THEN
         cx = 24 : cy = 24
      ELSEIF pWindow.DPI => 192 THEN
         cx = 32 : cy = 32
      END IF
   END IF

   ' // Create the image list
   pAfxImageList.CreateImageList(cx, cy, %ILC_COLOR32 OR %ILC_MASK, 45)

   ' // Give a name to the image list
   pAfxImageList.Name = "Toolbar image list disabled"

   ' // Add the bitmaps from the resource file
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_NEW_DOCUMENT_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_OPEN_DOCUMENT_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_SAVE_DOCUMENT_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_SAVE_DOCUMENT_AS_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_REFRESH_DOCUMENT_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_CLOSE_DOCUMENT_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_UNDO_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_REDO_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_CUT_CLIPBOARD_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_COPY_CLIPBOARD_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_PASTE_CLIPBOARD_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_FIND_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_REPLACE_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_COMPILE_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_COMPILE_AND_RUN_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_EXECUTE_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_DOS_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_EXIT_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_PRINT_PREVIEW_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_PRINT_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_MAIL_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_SEARCHOP_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_BOOKMARKS_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_FINDINFILES_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_ZOOMIN_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_ZOOMOUT_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_VIEWOPT_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_FOLDOP_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_POWERBASIC_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_TOGGLECOMPILER_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_CODEKEEPER_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_TLB_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_TOOLS_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_HELP_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_MBD_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_CODETIPS_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_KBDMACROS_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_CLOCK_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_BACKUPMGR_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_DEBUGTOOL_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_LYNX_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_VISDES_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_ICONED_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_IMGED_24_D")
   pAfxImageList.AddIcon GdiPlusCreateHICONFromResource(hInstance, "IDI_HEADERS_24_D")

   pSed.pToolbarImageListDisabled = pAfxImageList

   FUNCTION = pAfxImageList

END FUNCTION
' ========================================================================================

' ========================================================================================
' Toolbar tooltips
' ========================================================================================
SUB CSED_ToolbarTooltips (BYVAL pttdi AS NMTTDISPINFO PTR)

#IF %DEF(%UNICODE)
   LOCAL szText AS WSTRINGZ * %MAX_PATH
#ELSE
   LOCAL szText AS ASCIIZ * %MAX_PATH
#ENDIF

   SELECT CASE @pttdi.hdr.idFrom
      ' // Top toolbar
      CASE %IDM_NEW                : szText = "New file"
      CASE %IDM_OPEN               : szText = "Open file"
      CASE %IDM_SAVE               : szText = "Save file"
      CASE %IDM_SAVEAS             : szText = "Save file as..."
      CASE %IDM_REFRESH            : szText = "Refresh file"
      CASE %IDM_CLOSEFILE          : szText = "Close file"
      CASE %IDM_CUT                : szText = "Cut"
      CASE %IDM_COPY               : szText = "Copy"
      CASE %IDM_PASTE              : szText = "Paste"
      CASE %IDM_UNDO               : szText = "Undo"
      CASE %IDM_REDO               : szText = "Redo"
      CASE %IDM_FIND               : szText = "Find"
      CASE %IDM_REPLACE            : szText = "Replace"
      CASE %IDM_COMPILE            : szText = "Compile"
      CASE %IDM_COMPILEANDRUN      : szText = "Compile and execute"
      CASE %IDM_EXECUTE            : szText = "Execute without compiling"
      CASE %IDM_PRINT              : szText = "Print"
      CASE %IDM_MAIL               : szText = "Email me"
      CASE %IDM_DOS                : szText = "Command prompt"
      CASE %IDM_EXIT               : szText = "Exit"
      ' // Bottom toolbar
      CASE %IDM_BLOCKOPERATIONS    : szText = "Block operations"
      CASE %IDM_CASECONVERSIONS    : szText = "Case conversions"
      CASE %IDM_EOLCHARCONVERSIONS : szText = "End of line character conversions"
      CASE %IDM_SEARCHOPTIONS      : szText = "Search"
      CASE %IDM_BOOKMARKOPTIONS    : szText = "Bookmarks"
      CASE %IDM_FINDINFILES        : szText = "Find in files"
      CASE %IDM_ZOOMIN             : szText = "Zoom in"
      CASE %IDM_ZOOMOUT            : szText = "Zoom out"
      CASE %IDM_VIEWOPTIONS        : szText = "View options"
      CASE %IDM_FOLDOPTIONS        : szText = "Fold options"
      CASE %IDM_PBFORMS            : szText = "PB Forms"
      CASE %IDM_PBCOMBR            : szText = "PB COM browser"
      CASE %IDM_TOGGLECOMPILER     : szText = "Toggle selected compiler"
      CASE %IDM_SHOWCOMPILERRESULT : szText = "Show compiler result"
      CASE %IDM_CODEKEEPER         : szText = "Code keeper"
      CASE %IDM_VISDES             : szText = "Visual Designer"
      CASE %IDM_ICONED             : szText = "Icon Editor"
      CASE %IDM_IMGED              : szText = "Image Editor"
      CASE %IDM_TYPELIBBR          : szText = "TypeLib Browser"
      CASE %IDM_TOOLS              : szText = "External tools"
      CASE %IDM_HELP               : szText = "Help options"
      CASE %IDM_MSGBOXDESIGNER     : szText = "Message box designer"
      CASE %IDM_CODETIPSBUILDER    : szText = "Code tips builder"
      CASE %IDM_KBDMACROS          : szText = "Keyboard macros"
      CASE %IDM_FILESTAMP          : szText = "File stamp"
      CASE %IDM_BACKUPMGR          : szText = "Backup files manager"
      CASE %IDM_DEBUGTOOL          : szText = "Debugging tool"
      CASE %IDM_LYNX               : szText = "Lynx project explorer"

      CASE %IDM_HEADERS
         IF pSed.SelectedHeaders = 1 THEN szText = "José Roca Headers I"
         IF pSed.SelectedHeaders = 2 THEN szText = "José Roca Headers II"
         IF pSed.SelectedHeaders = 3 THEN szText = "PowerBASIC Headers I"
         IF pSed.SelectedHeaders = 4 THEN szText = "PowerBASIC Headers II"

   END SELECT

   IF LEN(szText) THEN @pttdi.szText = szText

END SUB
' ========================================================================================

' ========================================================================================
' Reset the CodeFinder combobox content
' ========================================================================================
SUB CSED_ResetCodefinder (BYVAL hComboBox AS DWORD)
   LOCAL buffer AS STRING
   buffer = "(Code finder)"
   ComboBox_ResetContent(hComboBox)
   Combobox_AddString(hComboBox, buffer)
   ComboBox_SetItemData(hComboBox, 0, 1)
   ComboBox_SetCurSel(hComboBox, 0)
END SUB
' ========================================================================================

' ========================================================================================
' Find subs, functions, classes, interfaces, methods and peoperties.
' ========================================================================================
SUB CSED_CodeFinder (BYVAL hComboBox AS DWORD, BYVAL hSci AS DWORD)

   LOCAL i            AS LONG     ' // Loop counter
   LOCAL p            AS LONG     ' // Position
   LOCAL pSci         AS DWORD    ' // Scintilla control's direct pointer
   LOCAL nLines       AS LONG     ' // Number of lines
   LOCAL buffer       AS STRING   ' // Buffer
   LOCAL newBuffer    AS STRING   ' // Buffer
   LOCAL strProcName  AS STRING   ' // Sub/Function name
   LOCAL strPrevName  AS STRING   ' // Previous name
   LOCAL strType      AS STRING   ' // Type
   LOCAL strClassName AS STRING   ' // Class name
   LOCAL strIntName   AS STRING   ' // Interface name

   ' // Reset the combobox content
   CSED_ResetCodeFinder(hComboBox)

   ' // Get direct pointer for faster access
   pSci = SCI_GetDirectPointer(hSci)
   IF ISFALSE pSci THEN EXIT SUB

   ' // Number of lines
   nLines = SCIP_GetLineCount(pSci)

   ' // Parse the text
   SetCursor LoadCursor (BYVAL %NULL, BYVAL %IDC_APPSTARTING)
   FOR i = 0 TO nLines - 1
      buffer = SCIP_GetLine(pSci, i)
      buffer = LTRIM$(buffer, ANY CHR$(32, 9))
      strProcName = ""
      strType = ""
      IF LEN(strPrevName) THEN buffer = strPrevName & buffer
      strPrevName = ""
      IF UCASE$(LEFT$(buffer, 9)) = "FUNCTION " AND MID$(LTRIM$(MID$(buffer, 10)), 1, 1) = "_" THEN
         strPrevName = "FUNCTION "
         ITERATE FOR
      ELSEIF UCASE$(LEFT$(buffer, 4)) = "SUB " AND MID$(LTRIM$(MID$(buffer, 5)), 1, 1) = "_" THEN
         strPrevName = "SUB "
         ITERATE FOR
      ELSEIF UCASE$(LEFT$(buffer, 7)) = "METHOD " AND MID$(LTRIM$(MID$(buffer, 8)), 1, 1) = "_" THEN
         strPrevName = "METHOD "
         ITERATE FOR
      ELSEIF UCASE$(LEFT$(buffer, 9)) = "PROPERTY " AND MID$(LTRIM$(MID$(buffer, 10)), 1, 1) = "_" THEN
         strPrevName = "PROPERTY "
         ITERATE FOR
      ELSEIF UCASE$(LEFT$(buffer, 6)) = "CLASS " AND MID$(LTRIM$(MID$(buffer, 7)), 1, 1) = "_" THEN
         strPrevName = "CLASS "
         ITERATE FOR
      ELSEIF UCASE$(LEFT$(buffer, 10)) = "INTERFACE " AND MID$(LTRIM$(MID$(buffer, 11)), 1, 1) = "_" THEN
         strPrevName = "INTERFACE "
         ITERATE FOR
      ELSEIF UCASE$(LEFT$(buffer, 9)) = "FASTPROC "  AND MID$(LTRIM$(MID$(buffer, 10)), 1, 1) = "_" THEN
         strPrevName = "FASTPROC "
         ITERATE FOR
      ELSEIF UCASE$(LEFT$(buffer, 9)) = "CALLBACK " THEN
         buffer = LTRIM$(MID$(buffer, 10), ANY CHR$(32, 9))
         IF UCASE$(LEFT$(buffer, 9)) = "FUNCTION " AND MID$(LTRIM$(MID$(buffer, 10)), 1, 1) = "_" THEN
            strPrevName = "FUNCTION "
            ITERATE FOR
         END IF
      ELSEIF UCASE$(LEFT$(buffer, 7)) = "STATIC " THEN
         buffer = LTRIM$(MID$(buffer, 8), ANY CHR$(32, 9))
         IF UCASE$(LEFT$(buffer, 9)) = "FUNCTION " AND MID$(LTRIM$(MID$(buffer, 10)), 1, 1) = "_" THEN
            strPrevName = "FUNCTION "
            ITERATE FOR
         ELSEIF UCASE$(LEFT$(buffer, 4)) = "SUB " AND MID$(LTRIM$(MID$(buffer, 5)), 1, 1) = "_" THEN
            strPrevName = "SUB "
            ITERATE FOR
         END IF
      ELSEIF UCASE$(LEFT$(buffer, 7)) = "THREAD " THEN
         buffer = LTRIM$(MID$(buffer, 8), ANY CHR$(32, 9))
         IF UCASE$(LEFT$(buffer, 9)) = "FUNCTION " AND MID$(LTRIM$(MID$(buffer, 10)), 1, 1) = "_" THEN
            strPrevName = "FUNCTION "
            ITERATE FOR
         END IF
      END IF
      IF UCASE$(LEFT$(buffer, 9)) = "FUNCTION " AND MID$(LTRIM$(MID$(buffer, 10)), 1, 1) <> "=" THEN
         strType = "function"
         buffer = LTRIM$(MID$(buffer, 10))
         p = INSTR(buffer, "(")
         IF p = 0 THEN p = INSTR(buffer, " ")
         IF p = 0 THEN p = INSTR(buffer, $CR)
         IF p THEN strProcName = LEFT$(buffer, p - 1)
      ELSEIF UCASE$(LEFT$(buffer, 7)) = "METHOD " AND MID$(LTRIM$(MID$(buffer, 8)), 1, 1) <> "=" THEN
         strType = "method"
         buffer = LTRIM$(MID$(buffer, 8))
         p = INSTR(buffer, "(")
         IF p = 0 THEN p = INSTR(buffer, " ")
         IF p = 0 THEN p = INSTR(buffer, $CR)
         IF p THEN strProcName = LEFT$(buffer, p - 1)
      ELSEIF UCASE$(LEFT$(buffer, 9)) = "PROPERTY " AND MID$(LTRIM$(MID$(buffer, 10)), 1, 1) <> "=" THEN
         strType = "property"
         buffer = LTRIM$(MID$(buffer, 10))
         p = INSTR(buffer, "(")
         IF p = 0 THEN p = INSTR(buffer, " ")
         IF p = 0 THEN p = INSTR(buffer, $CR)
         IF p THEN strProcName = LEFT$(buffer, p - 1)
      ELSEIF UCASE$(LEFT$(buffer, 13)) = "CLASS METHOD " THEN
         strType = "method"
         buffer = LTRIM$(MID$(buffer, 14))
         p = INSTR(buffer, "(")
         IF p = 0 THEN p = INSTR(buffer, " ")
         IF p = 0 THEN p = INSTR(buffer, $CR)
         IF p THEN strProcName = LEFT$(buffer, p - 1)
      ELSEIF UCASE$(LEFT$(buffer, 6)) = "CLASS " THEN
         strType = "class"
         buffer = LTRIM$(MID$(buffer, 7))
         p = INSTR(buffer, " ")
         IF p THEN buffer = LEFT$(buffer, p - 1)
         strProcName = buffer
         strClassName = strProcName
      ELSEIF UCASE$(LEFT$(buffer, 9)) = "END CLASS" THEN
         strClassName = ""
      ELSEIF UCASE$(LEFT$(buffer, 10)) = "INTERFACE " THEN
         strType = "interface"
         buffer = LTRIM$(MID$(buffer, 11))
         p = INSTR(buffer, " ")
         IF p THEN buffer = LEFT$(buffer, p - 1)
         strProcName = buffer
         IF p THEN strProcName = LEFT$(buffer, p - 1)
         strIntName = strProcName
      ELSEIF UCASE$(LEFT$(buffer, 13)) = "END INTERFACE" THEN
         strIntName = ""
      ELSEIF UCASE$(LEFT$(buffer, 4)) = "SUB " THEN
         strType = "sub"
         buffer = LTRIM$(MID$(buffer, 5))
         p = INSTR(buffer, "(")
         IF p = 0 THEN p = INSTR(buffer, " ")
         IF p = 0 THEN p = INSTR(buffer, $CR)
         IF p THEN strProcName = LEFT$(buffer, p - 1)
         buffer = LTRIM$(MID$(buffer, p))
         ' // Skip the assembler SUB mnemonic
         IF LEFT$(buffer, 1) = "," OR RIGHT$(strProcName, 1) = "," THEN
            strType = ""
            strProcName = ""
            buffer = ""
         END IF
      ELSEIF UCASE$(LEFT$(buffer, 9)) = "CALLBACK " THEN
         buffer = LTRIM$(MID$(buffer, 10), ANY CHR$(32, 9))
         IF UCASE$(LEFT$(buffer, 9)) = "FUNCTION " THEN
            strType = "callback function"
            buffer = LTRIM$(MID$(buffer, 10))
            p = INSTR(buffer, "(")
            IF p = 0 THEN p = INSTR(buffer, " ")
            IF p = 0 THEN p = INSTR(buffer, $CR)
            IF p THEN strProcName = LEFT$(buffer, p - 1)
         END IF
      ELSEIF UCASE$(LEFT$(buffer, 7)) = "STATIC " THEN
         buffer = LTRIM$(MID$(buffer, 8), ANY CHR$(32, 9))
         IF UCASE$(LEFT$(buffer, 9)) = "FUNCTION " THEN
            strType = "static function"
            buffer = LTRIM$(MID$(buffer, 10))
            p = INSTR(buffer, "(")
            IF p = 0 THEN p = INSTR(buffer, " ")
            IF p = 0 THEN p = INSTR(buffer, $CR)
            IF p THEN strProcName = LEFT$(buffer, p - 1)
         ELSEIF UCASE$(LEFT$(buffer, 4)) = "SUB " THEN
            strType = "static sub"
            buffer = LTRIM$(MID$(buffer, 5))
            p = INSTR(buffer, "(")
            IF p = 0 THEN p = INSTR(buffer, " ")
            IF p = 0 THEN p = INSTR(buffer, $CR)
            IF p THEN strProcName = LEFT$(buffer, p - 1)
         END IF
      ELSEIF UCASE$(LEFT$(buffer, 7)) = "THREAD " THEN
         buffer = LTRIM$(MID$(buffer, 8), ANY CHR$(32, 9))
         IF UCASE$(LEFT$(buffer, 9)) = "FUNCTION " THEN
            strType = "thread function"
            buffer = LTRIM$(MID$(buffer, 10))
            p = INSTR(buffer, "(")
            IF p = 0 THEN p = INSTR(buffer, " ")
            IF p = 0 THEN p = INSTR(buffer, $CR)
            IF p THEN strProcName = LEFT$(buffer, p - 1)
         END IF
      ELSEIF UCASE$(LEFT$(buffer, 6)) = "MACRO " THEN
         newBuffer = LTRIM$(MID$(buffer, 7), ANY CHR$(32, 9))
         IF UCASE$(LEFT$(newBuffer, 9)) = "FUNCTION " THEN
            strType = "macro function"
            newBuffer = LTRIM$(MID$(newBuffer, 10))
            p = INSTR(newBuffer, "(")
            IF p = 0 THEN p = INSTR(newBuffer, "=")
            IF p = 0 THEN p = INSTR(newBuffer, " ")
            IF p = 0 THEN p = INSTR(newBuffer, $CR)
            IF p THEN strProcName = LEFT$(newBuffer, p - 1)
         ELSE
            strType = "macro"
            buffer = LTRIM$(MID$(buffer, 7), ANY CHR$(32, 9))
            p = INSTR(buffer, "(")
            IF p = 0 THEN p = INSTR(buffer, "=")
            IF p = 0 THEN p = INSTR(buffer, " ")
            IF p = 0 THEN p = INSTR(buffer, $CR)
            IF p THEN strProcName = LEFT$(buffer, p - 1)
         END IF
      ELSEIF UCASE$(LEFT$(buffer, 9)) = "FASTPROC " THEN
         strType = "fastproc"
         buffer = LTRIM$(MID$(buffer, 10), ANY CHR$(32, 9))
         p = INSTR(buffer, "(")
         IF p = 0 THEN p = INSTR(buffer, " ")
         IF p = 0 THEN p = INSTR(buffer, $CR)
         IF p THEN strProcName = LEFT$(buffer, p - 1)
      END IF
      strProcName = TRIM$(strProcName)
      strProcName = REMOVE$(strProcName, ANY "!@#$%&")
      p = INSTR(UCASE$(strProcName), "ALIAS")
      IF p THEN strProcName = LEFT$(strProcName, p - 1)
      IF LEN(strProcName) THEN
         IF LEFT$(UCASE$(strProcName), 4) = "GET " THEN
            strProcName = TRIM$(MID$(strProcName, 4)) & " <get " & strType & ">"
         ELSEIF LEFT$(UCASE$(strProcName), 4) = "SET " THEN
            strProcName = TRIM$(MID$(strProcName, 4)) & " <set " & strType & ">"
         ELSE
            strProcName += " <" & strType & ">"
         END IF
         IF strType = "method" OR strType = "property" THEN
            strProcName += " {" & strClassName
            IF ISNOTNULL(strIntName) THEN
               strProcName += "." & strIntName & "}"
            ELSE
               strProcName += "}"
            END IF
         END IF
         p = ComboBox_AddString(hComboBox, BYVAL strProcName)
         ComboBox_SetItemData(hComboBox, p, i)
      END IF
   NEXT
   SetCursor LoadCursor (BYVAL %NULL, BYVAL %IDC_ARROW)

END SUB
' ========================================================================================

' ========================================================================================
' Disable toolbar buttons
' ========================================================================================
SUB CSED_DisableToolbarButtons

   Toolbar_DisableButton(pSed.hToolbar, %IDM_SAVE)
   Toolbar_DisableButton(pSed.hToolbar, %IDM_SAVEAS)
   Toolbar_DisableButton(pSed.hToolbar, %IDM_REFRESH)
   Toolbar_DisableButton(pSed.hToolbar, %IDM_CLOSEFILE)
   Toolbar_DisableButton(pSed.hToolbar, %IDM_UNDO)
   Toolbar_DisableButton(pSed.hToolbar, %IDM_REDO)
   Toolbar_DisableButton(pSed.hToolbar, %IDM_CUT)
   Toolbar_DisableButton(pSed.hToolbar, %IDM_COPY)
   Toolbar_DisableButton(pSed.hToolbar, %IDM_PASTE)
   Toolbar_DisableButton(pSed.hToolbar, %IDM_FIND)
   Toolbar_DisableButton(pSed.hToolbar, %IDM_REPLACE)
   Toolbar_DisableButton(pSed.hToolbar, %IDM_BOOKMARKOPTIONS)
   Toolbar_DisableButton(pSed.hToolbar, %IDM_COMPILE)
   Toolbar_DisableButton(pSed.hToolbar, %IDM_COMPILEANDRUN)
   Toolbar_DisableButton(pSed.hToolbar, %IDM_EXECUTE)
   Toolbar_DisableButton(pSed.hToolbar, %IDM_PRINT)
   Toolbar_DisableButton(pSed.hBottomToolbar, %IDM_VIEWOPTIONS)
   Toolbar_DisableButton(pSed.hBottomToolbar, %IDM_FOLDOPTIONS)
   Toolbar_DisableButton(pSed.hBottomToolbar, %IDM_ZOOMIN)
   Toolbar_DisableButton(pSed.hBottomToolbar, %IDM_ZOOMOUT)

END SUB
' ========================================================================================

' ========================================================================================
' Change toolbar button's state
' ========================================================================================
SUB CSED_ChangeToolbarButtonsState

   ' // Disables toolbar buttons if there is not any file being edited
   IF GetWindow(pSed.hwndClient, %GW_CHILD) = 0 THEN
      CSED_DisableToolbarButtons
      EXIT SUB
   END IF

   ' // Enables or disables toolbar buttons
   Toolbar_EnableButton(pSed.hToolbar, %IDM_SAVEAS)
   Toolbar_EnableButton(pSed.hToolbar, %IDM_REFRESH)
   Toolbar_EnableButton(pSed.hToolbar, %IDM_FIND)
   Toolbar_EnableButton(pSed.hToolbar, %IDM_REPLACE)
   Toolbar_EnableButton(pSed.hToolbar, %IDM_BOOKMARKOPTIONS)
   Toolbar_EnableButton(pSed.hToolbar, %IDM_COMPILE)
   Toolbar_EnableButton(pSed.hToolbar, %IDM_COMPILEANDRUN)
   Toolbar_EnableButton(pSed.hToolbar, %IDM_EXECUTE)
   Toolbar_EnableButton(pSed.hToolbar, %IDM_PRINT)
   Toolbar_EnableButton(pSed.hToolbar, %IDM_CLOSEFILE)
   Toolbar_EnableButton(pSed.hBottomToolbar, %IDM_VIEWOPTIONS)
   Toolbar_EnableButton(pSed.hBottomToolbar, %IDM_FOLDOPTIONS)
   Toolbar_EnableButton(pSed.hBottomToolbar, %IDM_ZOOMIN)
   Toolbar_EnableButton(pSed.hBottomToolbar, %IDM_ZOOMOUT)

   IF SCI_CanPaste(pSed.hEdit) = 0 THEN Toolbar_DisableButton(pSed.hToolbar, %IDM_PASTE) ELSE Toolbar_EnableButton(pSed.hToolbar, %IDM_PASTE)
   IF SCI_GetSelectionStart(pSed.hEdit) = SCI_GetSelectionEnd(pSed.hEdit) THEN
      Toolbar_DisableButton(pSed.hToolbar, %IDM_CUT)
      Toolbar_DisableButton(pSed.hToolbar, %IDM_COPY)
   ELSE
      Toolbar_EnableButton(pSed.hToolbar, %IDM_CUT)
      Toolbar_EnableButton(pSed.hToolbar, %IDM_COPY)
   END IF
   IF SCI_GetModify(pSed.hEdit) = 0 THEN Toolbar_DisableButton(pSed.hToolbar, %IDM_SAVE) ELSE Toolbar_EnableButton(pSed.hToolbar, %IDM_SAVE)
   IF SCI_CanUndo(pSed.hEdit) = 0 THEN Toolbar_DisableButton(pSed.hToolbar, %IDM_UNDO) ELSE Toolbar_EnableButton(pSed.hToolbar, %IDM_UNDO)
   IF SCI_CanRedo(pSed.hEdit) = 0 THEN Toolbar_DisableButton(pSed.hToolbar, %IDM_REDO) ELSE Toolbar_EnableButton(pSed.hToolbar, %IDM_REDO)
   IF SCI_CanPaste(pSed.hEdit) = 0 THEN Toolbar_DisableButton(pSed.hToolbar, %IDM_PASTE) ELSE Toolbar_EnableButton(pSed.hToolbar, %IDM_PASTE)

END SUB
' ========================================================================================
