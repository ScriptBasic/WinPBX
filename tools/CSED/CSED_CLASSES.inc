' ########################################################################################
' CSED Editor
' File: CSED_CLASS.INC
' Contents: CSED editor class
' Copyright (c) 2012 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' CSED editor class
' ########################################################################################
CLASS CSED

   INSTANCE m_hwndMain AS DWORD                         ' // Handle of the main window
   INSTANCE m_hwndClient AS DWORD                       ' // Handle of the MDI client window
   INSTANCE m_hToolBar AS DWORD                         ' // Handle of the tool bar control
   INSTANCE m_hBottomToolBar AS DWORD                   ' // Handle of the bottom tool bar control
   INSTANCE m_hStatusBar AS DWORD                       ' // Handle of the status bar control
   INSTANCE m_hCodeFinderCB AS DWORD                    ' // Code finder combobox
   INSTANCE m_hTabMdi AS DWORD                          ' // Handle of the tab control for MDI windows
   INSTANCE m_pToolbarImageListNormal AS IAfxImageList        ' // Toolbar normal image list handle
   INSTANCE m_pToolbarImageListDisabled AS IAfxImageList      ' // Toolbar disabled image list handle
   INSTANCE m_hTabCtrlImageList AS DWORD                ' // Tab control image list handle
   INSTANCE m_hMenu AS DWORD                            ' // Handle of the menu of the main window
   INSTANCE m_hMenuFile AS DWORD                        ' // File menu handle
   INSTANCE m_hMenuEdit AS DWORD                        ' // Edit menu handle
   INSTANCE m_hMenuSearch AS DWORD                      ' // Search menu handle
   INSTANCE m_hMenuRun AS DWORD                         ' // Run menu handle
   INSTANCE m_hMenuView AS DWORD                        ' // View menu handle
   INSTANCE m_hMenuWindow AS DWORD                      ' // Window menu handle
   INSTANCE m_hMenuOptions AS DWORD                     ' // Options menu handle
   INSTANCE m_hMenuTools AS DWORD                       ' // Tools menu handle
   INSTANCE m_hMenuHelp AS DWORD                        ' // Help menu handle
   INSTANCE m_hMenuSites AS DWORD                       ' // Sites menu handle
   INSTANCE m_hMenuGuides AS DWORD                      ' // Guides menu handle
   INSTANCE m_hSubMenuRecentFiles AS DWORD              ' // Block operations submenu handle
   INSTANCE m_hSubMenuBlockOperations AS DWORD          ' // Block operations submenu handle
   INSTANCE m_hSubMenuCaseConversions AS DWORD          ' // Case conversions submenu handle
   INSTANCE m_hSubMenuEndOfLineConversions AS DWORD     ' // End of line conversions submenu handle
   INSTANCE m_bUnicodeEnabled AS LONG                   ' // Unicode (UTF-8 encoding)
   INSTANCE m_cUntitledFilesIdx AS DWORD                ' // Untitled files index
   INSTANCE m_PBKeywords AS STRING                      ' // PB keywords
   INSTANCE m_strCompilerResults AS STRING              ' // Compiler result
   INSTANCE m_strTemplatePaths AS STRING                ' // Templates paths
   INSTANCE m_strTemplateDescs AS STRING                ' // Templates descriptions
   INSTANCE m_pTabFilePaths AS ILinkListCollection      ' // Paths of the files loaded in the editor
   INSTANCE m_pFindReplace AS IFindReplace              ' // Find and replace dialog
   INSTANCE m_pVsHelp AS IVsHelp                        ' // Visual Studio help (dexplore.exe)
   INSTANCE m_MenuGuidesCount AS LONG                   ' // Number of reference guides in the menu
   INSTANCE m_MenuToolsCount AS LONG                     ' // Number of tools in the menu
#IF %DEF(%UNICODE)
   INSTANCE m_szIniFileName AS WSTRINGZ * %MAX_PATH     ' // .ini file name
#ELSE
   INSTANCE m_szIniFileName AS ASCIIZ * %MAX_PATH       ' // .ini file name
#ENDIF

   ' =====================================================================================
   CLASS METHOD Create()
      ' // Do initialization
      m_szIniFileName = EXE.PATH$ & $PROGNAME & ".ini"
      m_pTabFilePaths = CLASS "LinkListCollection"
      m_pFindReplace = CLASS "CFindReplace"
      ' // Create the image list for the tabs
      LOCAL hIcon AS DWORD
      m_hTabCtrlImageList = ImageList_Create(16, 16, %ILC_MASK OR %ILC_COLOR32, 1, 0)
      hIcon = LoadIcon(GetModuleHandle(BYVAL %NULL), BYVAL %IDI_TABCLOSEICO)
      ImageList_AddIcon(m_hTabCtrlImageList, hIcon)
      DestroyIcon hIcon
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   CLASS METHOD Destroy()
      ' // Do cleanup
      m_pTabFilePaths = NOTHING
      m_pFindReplace = NOTHING
      m_pVsHelp = NOTHING
      ' // Destroy the toolbars image lists
      m_pToolbarImageListNormal = NOTHING
      m_pToolbarImageListDisabled = NOTHING
      ' // Destroy the tab control image lists
      IF m_hTabCtrlImageList THEN ImageList_Destroy m_hTabCtrlImageList
   END METHOD
   ' =====================================================================================

   INTERFACE ISED : INHERIT IAutomation

   ' =====================================================================================
   ' // Path of the .ini file
   ' =====================================================================================
#IF %DEF(%UNICODE)
   PROPERTY GET IniFileName () AS WSTRING : PROPERTY = m_szIniFileName : END PROPERTY
   PROPERTY SET IniFileName (BYVAL strFileName AS WSTRING) : m_szIniFileName = strFileName : END PROPERTY
#ELSE
   PROPERTY GET IniFileName () AS STRING : PROPERTY = m_szIniFileName : END PROPERTY
   PROPERTY SET IniFileName (BYVAL strFileName AS STRING) : m_szIniFileName = strFileName : END PROPERTY
#ENDIF
   ' =====================================================================================


   ' =====================================================================================
   ' Get the handle of the active Scintilla edit control
   ' =====================================================================================
   PROPERTY GET hEdit () AS DWORD
      PROPERTY = GetDlgItem(MdiGetActive(m_hwndClient), %IDC_EDIT)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Get the untitled files counter
   ' =====================================================================================
   PROPERTY GET UntitledFilesIdx () AS DWORD
      m_cUntitledFilesIdx += 1
      PROPERTY = m_cUntitledFilesIdx
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a reference to the tab paths collection
   ' =====================================================================================
   PROPERTY GET TabFilePaths () AS ILinkListCollection : PROPERTY = m_pTabFilePaths : END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a reference to the CFindReplace class
   ' // Note: FindReplace can't be used as the name of the method because it conflicts
   ' // with the FindReplace macro.
   ' =====================================================================================
   PROPERTY GET FindReplaceObj () AS IFindReplace : PROPERTY = m_pFindReplace : END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a reference to the tab Visual Studio help (dexplore.exe)
   ' =====================================================================================
   PROPERTY GET VsHelpObj () AS IVsHelp : PROPERTY = m_pVsHelp : END PROPERTY
   PROPERTY SET VsHelpObj (BYVAL pVsHelp AS IVsHelp) : m_pVsHelp = pVsHelp : END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' PB Keywords
   ' =====================================================================================
   PROPERTY GET PBKeywords () AS STRING : PROPERTY = m_PBKeywords : END PROPERTY
   PROPERTY SET PBKeywords (BYVAL strKeywords AS STRING) : m_PBKeywords = strKeywords : END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Compiler result
   ' =====================================================================================
   PROPERTY GET CompilerResults () AS STRING : PROPERTY = m_strCompilerResults : END PROPERTY
   PROPERTY SET CompilerResults (BYVAL strCompileResults AS STRING) : m_strCompilerResults = strCompileResults : END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Template names and descriptions
   ' =====================================================================================
   PROPERTY GET TemplatePaths () AS STRING : PROPERTY = m_strTemplatePaths : END PROPERTY
   PROPERTY SET TemplatePaths (BYVAL strTemplatePath AS STRING) : m_strTemplatePaths = strTemplatePath : END PROPERTY
   PROPERTY GET TemplateDescs () AS STRING : PROPERTY = m_strTemplateDescs : END PROPERTY
   PROPERTY SET TemplateDescs (BYVAL strTemplateDesc AS STRING) : m_strTemplateDescs = strTemplateDesc : END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' // Handles
   ' =====================================================================================
   PROPERTY GET hwndMain () AS DWORD : PROPERTY = m_hwndMain : END PROPERTY
   PROPERTY SET hwndMain (BYVAL hwndMain AS DWORD) : m_hwndMain = hwndMain : END PROPERTY
   PROPERTY GET hwndClient () AS DWORD : PROPERTY = m_hwndClient : END PROPERTY
   PROPERTY SET hwndClient (BYVAL hwndClient AS DWORD) : m_hwndClient = hwndClient : END PROPERTY
   PROPERTY GET hToolBar () AS DWORD : PROPERTY = m_hToolBar : END PROPERTY
   PROPERTY SET hToolBar (BYVAL hToolBar AS DWORD) : m_hToolBar = hToolBar : END PROPERTY
   PROPERTY GET hBottomToolBar () AS DWORD : PROPERTY = m_hBottomToolBar : END PROPERTY
   PROPERTY SET hBottomToolBar (BYVAL hBottomToolBar AS DWORD) : m_hBottomToolBar = hBottomToolBar : END PROPERTY
   PROPERTY GET hCodeFinderCB () AS DWORD : PROPERTY = m_hCodeFinderCB : END PROPERTY
   PROPERTY SET hCodeFinderCB (BYVAL hCodeFinderCB AS DWORD) : m_hCodeFinderCB = hCodeFinderCB : END PROPERTY
   PROPERTY GET hStatusBar () AS DWORD : PROPERTY = m_hStatusBar : END PROPERTY
   PROPERTY SET hStatusBar (BYVAL hStatusBar AS DWORD) : m_hStatusBar = hStatusBar : END PROPERTY
   PROPERTY GET hTabMdi () AS DWORD : PROPERTY = m_hTabMdi : END PROPERTY
   PROPERTY SET hTabMdi (BYVAL hTabMdi AS DWORD) : m_hTabMdi = hTabMdi : END PROPERTY
   PROPERTY GET hToolbarImageListNormal () AS DWORD : PROPERTY = m_pToolbarImageListNormal.hImageList : END PROPERTY
   PROPERTY GET hToolbarImageListDisabled () AS DWORD : PROPERTY = m_pToolbarImageListDisabled.hImageList : END PROPERTY
   PROPERTY SET pToolbarImageListNormal (BYVAL pToolbarImageListNormal AS IAfxImageList) : m_pToolbarImageListNormal = pToolbarImageListNormal : END PROPERTY
   PROPERTY SET pToolbarImageListDisabled (BYVAL pToolbarImageListDisabled AS IAfxImageList) : m_pToolbarImageListDisabled = pToolbarImageListDisabled : END PROPERTY
   PROPERTY GET hTabCtrlImageList () AS DWORD : PROPERTY = m_hTabCtrlImageList : END PROPERTY
   PROPERTY SET hTabCtrlImageList (BYVAL hTabCtrlImageList AS DWORD) : m_hTabCtrlImageList = m_hTabCtrlImageList : END PROPERTY
   PROPERTY GET hMenu () AS DWORD : PROPERTY = m_hMenu : END PROPERTY
   PROPERTY SET hMenu (BYVAL hMenu AS DWORD) : m_hMenu = hMenu : END PROPERTY
   PROPERTY GET hMenuFile () AS DWORD : PROPERTY = m_hMenuFile : END PROPERTY
   PROPERTY SET hMenuFile (BYVAL hMenuFile AS DWORD) : m_hMenuFile = hMenuFile : END PROPERTY
   PROPERTY GET hMenuEdit () AS DWORD : PROPERTY = m_hMenuEdit : END PROPERTY
   PROPERTY SET hMenuEdit (BYVAL hMenuEdit AS DWORD) : m_hMenuEdit = hMenuEdit : END PROPERTY
   PROPERTY GET hMenuSearch () AS DWORD : PROPERTY = m_hMenuSearch : END PROPERTY
   PROPERTY SET hMenuSearch (BYVAL hMenuSearch AS DWORD) : m_hMenuSearch = hMenuSearch : END PROPERTY
   PROPERTY GET hMenuRun () AS DWORD : PROPERTY = m_hMenuRun : END PROPERTY
   PROPERTY SET hMenuRun (BYVAL hMenuRun AS DWORD) : m_hMenuRun = hMenuRun : END PROPERTY
   PROPERTY GET hMenuView () AS DWORD : PROPERTY = m_hMenuView : END PROPERTY
   PROPERTY SET hMenuView (BYVAL hMenuView AS DWORD) : m_hMenuView = hMenuView : END PROPERTY
   PROPERTY GET hMenuWindow () AS DWORD : PROPERTY = m_hMenuWindow : END PROPERTY
   PROPERTY SET hMenuWindow (BYVAL hMenuWindow AS DWORD) : m_hMenuWindow = hMenuWindow : END PROPERTY
   PROPERTY GET hMenuOptions () AS DWORD : PROPERTY = m_hMenuOptions : END PROPERTY
   PROPERTY SET hMenuOptions (BYVAL hMenuOptions AS DWORD) : m_hMenuOptions = hMenuOptions : END PROPERTY
   PROPERTY GET hMenuHelp () AS DWORD : PROPERTY = m_hMenuHelp : END PROPERTY
   PROPERTY SET hMenuHelp (BYVAL hMenuHelp AS DWORD) : m_hMenuHelp = hMenuHelp : END PROPERTY
   PROPERTY GET hMenuSites () AS DWORD : PROPERTY = m_hMenuSites : END PROPERTY
   PROPERTY SET hMenuSites (BYVAL hMenuSites AS DWORD) : m_hMenuSites = hMenuSites : END PROPERTY
   PROPERTY GET hMenuGuides () AS DWORD : PROPERTY = m_hMenuGuides : END PROPERTY
   PROPERTY SET hMenuGuides (BYVAL hMenuGuides AS DWORD) : m_hMenuGuides = hMenuGuides : END PROPERTY
   PROPERTY GET MenuGuidesCount () AS LONG : PROPERTY = m_MenuGuidesCount : END PROPERTY
   PROPERTY SET MenuGuidesCount (BYVAL MenuGuidesCount AS LONG) : m_MenuGuidesCount = MenuGuidesCount : END PROPERTY
   PROPERTY GET hMenuTools () AS DWORD : PROPERTY = m_hMenuTools : END PROPERTY
   PROPERTY SET hMenuTools (BYVAL hMenuTools AS DWORD) : m_hMenuTools = hMenuTools : END PROPERTY
   PROPERTY GET MenuToolsCount () AS LONG : PROPERTY = m_MenuToolsCount : END PROPERTY
   PROPERTY SET MenuToolsCount (BYVAL MenuToolsCount AS LONG) : m_MenuToolsCount = MenuToolsCount : END PROPERTY
   PROPERTY GET hSubMenuRecentFiles () AS DWORD : PROPERTY = m_hSubMenuRecentFiles : END PROPERTY
   PROPERTY SET hSubMenuRecentFiles (BYVAL hSubMenuRecentFiles AS DWORD) : m_hSubMenuRecentFiles = hSubMenuRecentFiles : END PROPERTY
   PROPERTY GET hSubMenuBlockOperations () AS DWORD : PROPERTY = m_hSubMenuBlockOperations : END PROPERTY
   PROPERTY SET hSubMenuBlockOperations (BYVAL hSubMenuBlockOperations AS DWORD) : m_hSubMenuBlockOperations = hSubMenuBlockOperations : END PROPERTY
   PROPERTY GET hSubMenuCaseConversions () AS DWORD : PROPERTY = m_hSubMenuCaseConversions : END PROPERTY
   PROPERTY SET hSubMenuCaseConversions (BYVAL hSubMenuCaseConversions AS DWORD) : m_hSubMenuCaseConversions = hSubMenuCaseConversions : END PROPERTY
   PROPERTY GET hSubMenuEndOfLineConversions () AS DWORD : PROPERTY = m_hSubMenuEndOfLineConversions : END PROPERTY
   PROPERTY SET hSubMenuEndOfLineConversions (BYVAL hSubMenuEndOfLineConversions AS DWORD) : m_hSubMenuEndOfLineConversions = hSubMenuEndOfLineConversions : END PROPERTY
   ' =====================================================================================

   ' *** Editor options ******************************************************************

   ' =====================================================================================
   ' Use tabs
   ' =====================================================================================
   PROPERTY GET UseTabs () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "UseTabs")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED : ME.UseTabs = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET UseTabs (BYVAL bUseTabs AS LONG)
      IF bUseTabs THEN bUseTabs = %BST_CHECKED ELSE bUseTabs = %BST_UNCHECKED
      AfxIniFileWrite m_szIniFileName, "Editor options", "UseTabs", FORMAT$(bUseTabs)
      IF bUseTabs THEN CheckMenuItem m_hMenu, %IDM_USETABS, %MF_CHECKED ELSE CheckMenuItem m_hMenu, %IDM_USETABS, %MF_UNCHECKED
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Tab size
   ' =====================================================================================
   PROPERTY GET TabSize () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "TabSize")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = 3 : ME.TabSize = 3
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET TabSize (BYVAL nTabSize AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "TabSize", FORMAT$(nTabSize)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Auto indentation
   ' =====================================================================================
   PROPERTY GET AutoIndent () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "AutoIndent")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_CHECKED : ME.AutoIndent = %BST_CHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET AutoIndent (BYVAL bAutoIndent AS LONG)
      IF bAutoIndent THEN bAutoIndent = %BST_CHECKED
      AfxIniFileWrite m_szIniFileName, "Editor options", "AutoIndent", FORMAT$(bAutoIndent)
      IF bAutoIndent THEN CheckMenuItem m_hMenu, %IDM_AUTOINDENT, %MF_CHECKED ELSE CheckMenuItem m_hMenu, %IDM_AUTOINDENT, %MF_UNCHECKED
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Indentation size
   ' =====================================================================================
   PROPERTY GET IndentSize () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "IndentSize")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = 3 : ME.TabSize = 3
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET IndentSize (BYVAL nIndentSize AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "IndentSize", FORMAT$(nIndentSize)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Show line numbers
   ' =====================================================================================
   PROPERTY GET LineNumbers () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "LineNumbers")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED : ME.LineNumbers = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET LineNumbers (BYVAL bLineNumbers AS LONG)
      IF bLineNumbers THEN bLineNumbers = %BST_CHECKED
      AfxIniFileWrite m_szIniFileName, "Editor options", "LineNumbers", FORMAT$(bLineNumbers)
      IF bLineNumbers THEN CheckMenuItem m_hMenu, %IDM_SHOWLINENUM, %MF_CHECKED ELSE CheckMenuItem m_hMenu, %IDM_SHOWLINENUM, %MF_UNCHECKED
      IF bLineNumbers = %BST_CHECKED THEN SCI_SetMarginWidthN(ME.hEdit, 0, ME.LineNumbersWidth) ELSE SCI_SetMarginWidthN(ME.hEdit, 0, 0)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Size of the strip to display line numbers
   ' =====================================================================================
   PROPERTY GET LineNumbersWidth () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "LineNumbersWidth")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = 50 : ME.LineNumbersWidth = 50
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET LineNumbersWidth (BYVAL nLineNumbersWidth AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "LineNumbersWidth", FORMAT$(nLineNumbersWidth)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Margin
   ' =====================================================================================
   PROPERTY GET Margin () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "Margin")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_CHECKED : ME.Margin = %BST_CHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET Margin (BYVAL bMargin AS LONG)
      IF bMargin THEN bMargin = %BST_CHECKED
      AfxIniFileWrite m_szIniFileName, "Editor options", "Margin", FORMAT$(bMargin)
      IF bMargin THEN CheckMenuItem m_hMenu, %IDM_SHOWMARGIN, %MF_CHECKED ELSE CheckMenuItem m_hMenu, %IDM_SHOWMARGIN, %MF_UNCHECKED
      IF bMargin = %BST_CHECKED THEN SCI_SetMarginWidthN(ME.hEdit, 2, ME.MarginWidth) ELSE SCI_SetMarginWidthN(ME.hEdit, 2, 0)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Size of the strip to display line numbers
   ' =====================================================================================
   PROPERTY GET MarginWidth () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "MarginWidth")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = 20 : ME.MarginWidth = 20
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET MarginWidth (BYVAL nMarginWidth AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "MarginWidth", FORMAT$(nMarginWidth)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Edge column
   ' =====================================================================================
   PROPERTY GET EdgeColumn () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "EdgeColumn")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_CHECKED : ME.EdgeColumn = %BST_CHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET EdgeColumn (BYVAL bEdgeColumn AS LONG)
      IF bEdgeColumn THEN bEdgeColumn = %BST_CHECKED
      AfxIniFileWrite m_szIniFileName, "Editor options", "EdgeColumn", FORMAT$(bEdgeColumn)
      IF bEdgeColumn THEN CheckMenuItem m_hMenu, %IDM_SHOWEDGE, %MF_CHECKED ELSE CheckMenuItem m_hMenu, %IDM_SHOWEDGE, %MF_UNCHECKED
      IF bEdgeColumn = %BST_CHECKED THEN SCI_SetEdgeColumn(ME.hEdit, ME.EdgeWidth) ELSE SCI_SetEdgeColumn(ME.hEdit, 0)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Column at which the edge must be displayed
   ' =====================================================================================
   PROPERTY GET EdgeWidth () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "EdgeWidth")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = 255 : ME.EdgeWidth = 255
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET EdgeWidth (BYVAL nEdgeWidth AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "EdgeWidth", FORMAT$(nEdgeWidth)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Indentation guides
   ' =====================================================================================
   PROPERTY GET IndentGuides () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "IndentGuides")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_CHECKED : ME.IndentGuides = %BST_CHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET IndentGuides (BYVAL bIndentGuides AS LONG)
      IF bIndentGuides THEN bIndentGuides = %BST_CHECKED
      AfxIniFileWrite m_szIniFileName, "Editor options", "IndentGuides", FORMAT$(bIndentGuides)
      IF bIndentGuides THEN CheckMenuItem m_hMenu, %IDM_SHOWINDENT, %MF_CHECKED ELSE CheckMenuItem m_hMenu, %IDM_SHOWINDENT, %MF_UNCHECKED
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Magnification
   ' =====================================================================================
   PROPERTY GET Magnification () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Editor options", "Magnification"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET Magnification (BYVAL bMagnification AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "Magnification", FORMAT$(bMagnification)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' White space
   ' =====================================================================================
   PROPERTY GET WhiteSpace () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "WhiteSpace")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED : ME.WhiteSpace = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET WhiteSpace (BYVAL bWhiteSpace AS LONG)
      IF bWhiteSpace THEN bWhiteSpace = %BST_CHECKED
      AfxIniFileWrite m_szIniFileName, "Editor options", "WhiteSpace", FORMAT$(bWhiteSpace)
      IF bWhiteSpace THEN CheckMenuItem m_hMenu, %IDM_SHOWSPACES, %MF_CHECKED ELSE CheckMenuItem m_hMenu, %IDM_SHOWSPACES, %MF_UNCHECKED
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' End of line
   ' =====================================================================================
   PROPERTY GET EndOfLine () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "EndOfLine")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED : ME.EndOfLine = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET EndOfLine (BYVAL bEndOfLine AS LONG)
      IF bEndOfLine THEN bEndOfLine = %BST_CHECKED
      AfxIniFileWrite m_szIniFileName, "Editor options", "EndOfLine", FORMAT$(bEndOfLine)
      IF bEndOfLine THEN CheckMenuItem m_hMenu, %IDM_SHOWEOL, %MF_CHECKED ELSE CheckMenuItem m_hMenu, %IDM_SHOWEOL, %MF_UNCHECKED
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Syntax highlighting
   ' =====================================================================================
   PROPERTY GET SyntaxHighlighting () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "SyntaxHighlighting")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_CHECKED : ME.SyntaxHighlighting = %BST_CHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET SyntaxHighlighting (BYVAL bSyntaxHighlighting AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "SyntaxHighlighting", FORMAT$(bSyntaxHighlighting)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Codetips
   ' =====================================================================================
   PROPERTY GET CodeTips () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Editor options", "CodeTips"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET CodeTips (BYVAL bCodeTips AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "CodeTips", FORMAT$(bCodeTips)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Maximize main window
   ' =====================================================================================
   PROPERTY GET MaximizeMainWindow () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Editor options", "MaximizeMainWindow"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET MaximizeMainWindow (BYVAL bMaximizeMainWindow AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "MaximizeMainWindow", FORMAT$(bMaximizeMainWindow)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Maximize edit windows
   ' =====================================================================================
   PROPERTY GET MaximizeEditWindows () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "MaximizeEditWindows")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_CHECKED : ME.MaximizeEditWindows = %BST_CHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET MaximizeEditWindows (BYVAL bMaximizeEditWindows AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "MaximizeEditWindows", FORMAT$(bMaximizeEditWindows)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Ask before exiting the editor
   ' =====================================================================================
   PROPERTY GET AskBeforeExit () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "AskBeforeExit")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_CHECKED : ME.AskBeforeExit = %BST_CHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET AskBeforeExit (BYVAL bAskBeforeExit AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "AskBeforeExit", FORMAT$(bAskBeforeExit)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Allow mutiple instances of the editor
   ' =====================================================================================
   PROPERTY GET AllowMultipleInstances () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "AllowMultipleInstances")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED : ME.AllowMultipleInstances = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET AllowMultipleInstances (BYVAL bAllowMultipleInstances AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "AllowMultipleInstances", FORMAT$(bAllowMultipleInstances)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Default case
   ' =====================================================================================
   PROPERTY GET DefaultCase () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "DefaultCase")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED : ME.DefaultCase = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET DefaultCase (BYVAL bDefaultCase AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "DefaultCase", FORMAT$(bDefaultCase)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Keyword case
   ' =====================================================================================
   PROPERTY GET KeywordCase () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "KeywordCase")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED : ME.KeywordCase = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET KeywordCase (BYVAL bKeywordCase AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "KeywordCase", FORMAT$(bKeywordCase)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Autocomplete constructs
   ' =====================================================================================
   PROPERTY GET ConstructAutocompletion () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "ConstructAutocompletion")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED : ME.ConstructAutocompletion = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET ConstructAutocompletion (BYVAL bConstructAutocompletion AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "ConstructAutocompletion", FORMAT$(bConstructAutocompletion)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Autocomplete types
   ' =====================================================================================
   PROPERTY GET AutocompleteTypes () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "AutocompleteTypes")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED : ME.AutocompleteTypes = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET AutocompleteTypes (BYVAL bAutocompleteTypes AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "AutocompleteTypes", FORMAT$(bAutocompleteTypes)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Trim trailing blanks
   ' =====================================================================================
   PROPERTY GET TrimTrailingBlanks () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "TrimTrailingBlanks")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED : ME.TrimTrailingBlanks = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET TrimTrailingBlanks (BYVAL bTrimTrailingBlanks AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "TrimTrailingBlanks", FORMAT$(bTrimTrailingBlanks)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Show procedure name
   ' =====================================================================================
   PROPERTY GET ShowProcedureName () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "ShowProcedureName")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED : ME.ShowProcedureName = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET ShowProcedureName (BYVAL bShowProcedureName AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "ShowProcedureName", FORMAT$(bShowProcedureName)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Show caret line
   ' =====================================================================================
   PROPERTY GET ShowCaretLine () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "ShowCaretLine")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_CHECKED : ME.ShowCaretLine = %BST_CHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET ShowCaretLine (BYVAL bShowCaretLine AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "ShowCaretLine", FORMAT$(bShowCaretLine)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Start in the last folder used
   ' =====================================================================================
   PROPERTY GET StartInLastFolder () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "StartInLastFolder")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_CHECKED : ME.StartInLastFolder = %BST_CHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET StartInLastFolder (BYVAL bStartInLastFolder AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "StartInLastFolder", FORMAT$(bStartInLastFolder)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Last folder path used
   ' =====================================================================================
   PROPERTY GET LastFolder () AS STRING
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "LastFolder")
      IF LEN(rs) THEN PROPERTY = rs ELSE PROPERTY = CURDIR$ : ME.LastFolder = CURDIR$
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET LastFolder (BYVAL strLastFolder AS STRING)
      AfxIniFileWrite m_szIniFileName, "Editor options", "LastFolder", BYCOPY strLastFolder
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Reload files at start up
   ' =====================================================================================
   PROPERTY GET ReloadFilesAtStartup () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "ReloadFilesAtStartup")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED : ME.ReloadFilesAtStartup = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET ReloadFilesAtStartup (BYVAL bReloadFilesAtStartup AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "ReloadFilesAtStartup", FORMAT$(bReloadFilesAtStartup)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Back up editor files
   ' =====================================================================================
   PROPERTY GET BackupEditorFiles () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "BackupEditorFiles")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_CHECKED : ME.BackupEditorFiles = %BST_CHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET BackupEditorFiles (BYVAL bBackupEditorFiles AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "BackupEditorFiles", FORMAT$(bBackupEditorFiles)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Use MSDN help
   ' =====================================================================================
   PROPERTY GET UseMSDNHelp () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "UseMSDNHelp")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED : ME.UseMSDNHelp = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET UseMSDNHelp (BYVAL bUseMSDNHelp AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "UseMSDNHelp", FORMAT$(bUseMSDNHelp)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Save bookmarks
   ' =====================================================================================
   PROPERTY GET SaveBookmarksToFile () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "SaveBookmarksToFile")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED : ME.SaveBookmarksToFile = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET SaveBookmarksToFile (BYVAL bSave AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "SaveBookmarksToFile", FORMAT$(bSave)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Save/Restore window placement
   ' =====================================================================================
   PROPERTY GET WindowPlacement () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "WindowPlacement")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED : ME.WindowPlacement = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET WindowPlacement (BYVAL bEnable AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "WindowPlacement", FORMAT$(bEnable)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Convert end of lines when pasting
   ' =====================================================================================
   PROPERTY GET PasteConvertEndings () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "PasteConvertEndings")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_CHECKED : ME.PasteConvertEndings = %BST_CHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET PasteConvertEndings (BYVAL bConvert AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "PasteConvertEndings", FORMAT$(bConvert)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Multiple selection
   ' =====================================================================================
   PROPERTY GET MultipleSelection () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "MultipleSelection")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED : ME.MultipleSelection = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET MultipleSelection (BYVAL bMulSel AS LONG)
      IF bMulSel THEN bMulSel = %BST_CHECKED
      AfxIniFileWrite m_szIniFileName, "Editor options", "MultipleSelection", FORMAT$(bMulSel)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Unicode (UTF-8 encoding)
   ' =====================================================================================
   PROPERTY GET UnicodeEnabled () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Editor options", "UnicodeEnabled")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED : ME.UnicodeEnabled = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET UnicodeEnabled (BYVAL bUnicodeEnabled AS LONG)
      IF bUnicodeEnabled THEN bUnicodeEnabled = %BST_CHECKED
      AfxIniFileWrite m_szIniFileName, "Editor options", "UnicodeEnabled", FORMAT$(bUnicodeEnabled)
   END PROPERTY
   ' =====================================================================================

   ' *** Compiler options ****************************************************************

   ' =====================================================================================
   ' Selected compiler
   ' =====================================================================================
   PROPERTY GET SelectedCompiler () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Compiler options", "SelectedCompiler")
      IF VAL(rs) = 0 THEN rs = "1" : ME.SelectedCompiler = 1
      PROPERTY = VAL(rs)
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET SelectedCompiler (BYVAL nSelectedCompiler AS LONG)
      AfxIniFileWrite m_szIniFileName, "Compiler options", "SelectedCompiler", FORMAT$(nSelectedCompiler)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Default headers
   ' =====================================================================================
   PROPERTY GET SelectedHeaders () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Compiler options", "SelectedHeaders")
      IF VAL(rs) = 0 THEN rs = "1" : ME.SelectedHeaders = 1
      PROPERTY = VAL(rs)
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET SelectedHeaders (BYVAL nSelectedHeaders AS LONG)
      AfxIniFileWrite m_szIniFileName, "Compiler options", "SelectedHeaders", FORMAT$(nSelectedHeaders)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Display results
   ' =====================================================================================
   PROPERTY GET DisplayResults () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Compiler options", "DisplayResults"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET DisplayResults (BYVAL bDisplayResults AS LONG)
      AfxIniFileWrite m_szIniFileName, "Compiler options", "DisplayResults", FORMAT$(bDisplayResults)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Delete log file
   ' =====================================================================================
   PROPERTY GET DeleteLogFile () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Compiler options", "DeleteLogFile"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET DeleteLogFile (BYVAL bDeleteLogFile AS LONG)
      AfxIniFileWrite m_szIniFileName, "Compiler options", "DeleteLogFile", FORMAT$(bDeleteLogFile)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Beep on completion
   ' =====================================================================================
   PROPERTY GET BeepOnCompletion () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Compiler options", "BeepOnCompletion"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET BeepOnCompletion (BYVAL bBeepOnCompletion AS LONG)
      AfxIniFileWrite m_szIniFileName, "Compiler options", "BeepOnCompletion", FORMAT$(bBeepOnCompletion)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Add date/time to backup files
   ' =====================================================================================
   PROPERTY GET AddDateTimeToBackupFiles () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Editor options", "AddDateTimeToBackupFiles"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET AddDateTimeToBackupFiles (BYVAL bAddDateTime AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "AddDateTimeToBackupFiles", FORMAT$(bAddDateTime)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Save backup files to database
   ' =====================================================================================
   PROPERTY GET SaveBackupFilesToDatabase () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Editor options", "SaveBackupFilesToDatabase"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET SaveBackupFilesToDatabase (BYVAL bSave AS LONG)
      AfxIniFileWrite m_szIniFileName, "Editor options", "SaveBackupFilesToDatabase", FORMAT$(bSave)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Find in files tool path
   ' =====================================================================================
   PROPERTY GET FindInFilesToolPath () AS STRING
      PROPERTY = AfxIniFileRead(m_szIniFileName, "Editor options", "FindInFilesToolPath")
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET FindInFilesToolPath (BYVAL strPath AS STRING)
      AfxIniFileWrite m_szIniFileName, "Editor options", "FindInFilesToolPath", BYCOPY strPath
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' PBWIN compiler path
   ' =====================================================================================
   PROPERTY GET PBWINPath () AS STRING
      PROPERTY = AfxIniFileRead(m_szIniFileName, "Compiler options", "PBWINPath")
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET PBWINPath (BYVAL strPBWINPath AS STRING)
      AfxIniFileWrite m_szIniFileName, "Compiler options", "PBWINPath", BYCOPY strPBWINPath
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' PBCC compiler path
   ' =====================================================================================
   PROPERTY GET PBCCPath () AS STRING
      PROPERTY = AfxIniFileRead(m_szIniFileName, "Compiler options", "PBCCPath")
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET PBCCPath (BYVAL strPBCCPath AS STRING)
      AfxIniFileWrite m_szIniFileName, "Compiler options", "PBCCPath", BYCOPY strPBCCPath
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Resource compiler path
   ' =====================================================================================
   PROPERTY GET RCPath () AS STRING
      PROPERTY = AfxIniFileRead(m_szIniFileName, "Compiler options", "RCPath")
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET RCPath (BYVAL strRCPath AS STRING)
      AfxIniFileWrite m_szIniFileName, "Compiler options", "RCPath", BYCOPY strRCPath
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' PBForms compiler path
   ' =====================================================================================
   PROPERTY GET PBFormsPath () AS STRING
      PROPERTY = AfxIniFileRead(m_szIniFileName, "Compiler options", "PBFormsPath")
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET PBFormsPath (BYVAL strPBFormsPath AS STRING)
      AfxIniFileWrite m_szIniFileName, "Compiler options", "PBFormsPath", BYCOPY strPBFormsPath
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' PB COM Browser path
   ' =====================================================================================
   PROPERTY GET PBCOMBrowserPath () AS STRING
      PROPERTY = AfxIniFileRead(m_szIniFileName, "Compiler options", "PBCOMBrowserPath")
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET PBCOMBrowserPath (BYVAL strPBCOMBrowserPath AS STRING)
      AfxIniFileWrite m_szIniFileName, "Compiler options", "PBCOMBrowserPath", BYCOPY strPBCOMBrowserPath
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' TypeLib Browser path
   ' =====================================================================================
   PROPERTY GET TypeLibBrowserPath () AS STRING
      PROPERTY = AfxIniFileRead(m_szIniFileName, "Compiler options", "TypeLibBrowserPath")
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET TypeLibBrowserPath (BYVAL strTypeLibBrowserPath AS STRING)
      AfxIniFileWrite m_szIniFileName, "Compiler options", "TypeLibBrowserPath", BYCOPY strTypeLibBrowserPath
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' PB headers path
   ' =====================================================================================
   PROPERTY GET PBIncPath1 () AS STRING
      PROPERTY = AfxIniFileRead(m_szIniFileName, "Compiler options", "PBIncPath1")
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET PBIncPath1 (BYVAL strPBIncPath AS STRING)
      AfxIniFileWrite m_szIniFileName, "Compiler options", "PBIncPath1", BYCOPY strPBIncPath
   END PROPERTY
   ' =====================================================================================
   PROPERTY GET PBIncPath2 () AS STRING
      PROPERTY = AfxIniFileRead(m_szIniFileName, "Compiler options", "PBIncPath2")
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET PBIncPath2 (BYVAL strPBIncPath AS STRING)
      AfxIniFileWrite m_szIniFileName, "Compiler options", "PBIncPath2", BYCOPY strPBIncPath
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' José Roca headers path
   ' =====================================================================================
   PROPERTY GET JRSIncPath1 () AS STRING
      PROPERTY = AfxIniFileRead(m_szIniFileName, "Compiler options", "JRSIncPath1")
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET JRSIncPath1 (BYVAL strJRSIncPath AS STRING)
      AfxIniFileWrite m_szIniFileName, "Compiler options", "JRSIncPath1", BYCOPY strJRSIncPath
   END PROPERTY
   ' =====================================================================================
   PROPERTY GET JRSIncPath2 () AS STRING
      PROPERTY = AfxIniFileRead(m_szIniFileName, "Compiler options", "JRSIncPath2")
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET JRSIncPath2 (BYVAL strJRSIncPath AS STRING)
      AfxIniFileWrite m_szIniFileName, "Compiler options", "JRSIncPath2", BYCOPY strJRSIncPath
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Debugging tool
   ' =====================================================================================
   PROPERTY GET DebugToolPath () AS STRING
      PROPERTY = AfxIniFileRead(m_szIniFileName, "Compiler options", "DebugToolPath")
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET DebugToolPath (BYVAL strDebugToolPath AS STRING)
      AfxIniFileWrite m_szIniFileName, "Compiler options", "DebugToolPath", BYCOPY strDebugToolPath
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' PowerBASIC Library Manager
   ' =====================================================================================
   PROPERTY GET PowerLibPath () AS STRING
      PROPERTY = AfxIniFileRead(m_szIniFileName, "Compiler options", "PowerLibPath")
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET PowerLibPath (BYVAL strPowerLibPath AS STRING)
      AfxIniFileWrite m_szIniFileName, "Compiler options", "PowerLibPath", BYCOPY strPowerLibPath
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Visual designer
   ' =====================================================================================
   PROPERTY GET VisualDesignerPath () AS STRING
      PROPERTY = AfxIniFileRead(m_szIniFileName, "Compiler options", "VisualDesignerPath")
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET VisualDesignerPath (BYVAL strVisualDesignerPath AS STRING)
      AfxIniFileWrite m_szIniFileName, "Compiler options", "VisualDesignerPath", BYCOPY strVisualDesignerPath
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Icon editor path
   ' =====================================================================================
   PROPERTY GET IconEditorPath () AS STRING
      PROPERTY = AfxIniFileRead(m_szIniFileName, "Compiler options", "IconEditorPath")
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET IconEditorPath (BYVAL strIconEditorPath AS STRING)
      AfxIniFileWrite m_szIniFileName, "Compiler options", "IconEditorPath", BYCOPY strIconEditorPath
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Image editor path
   ' =====================================================================================
   PROPERTY GET ImageEditorPath () AS STRING
      PROPERTY = AfxIniFileRead(m_szIniFileName, "Compiler options", "ImageEditorPath")
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET ImageEditorPath (BYVAL strImageEditorPath AS STRING)
      AfxIniFileWrite m_szIniFileName, "Compiler options", "ImageEditorPath", BYCOPY strImageEditorPath
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' PBWIN Help file path
   ' =====================================================================================
   PROPERTY GET PBWinHelpPath () AS STRING
      PROPERTY = AfxIniFileRead(m_szIniFileName, "Compiler options", "PBWinHelpPath")
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET PBWinHelpPath (BYVAL strPBWinHelpPath AS STRING)
      AfxIniFileWrite m_szIniFileName, "Compiler options", "PBWinHelpPath", BYCOPY strPBWinHelpPath
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' PBCC Help file path
   ' =====================================================================================
   PROPERTY GET PBCCHelpPath () AS STRING
      PROPERTY = AfxIniFileRead(m_szIniFileName, "Compiler options", "PBCCHelpPath")
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET PBCCHelpPath (BYVAL strPBCCHelpPath AS STRING)
      AfxIniFileWrite m_szIniFileName, "Compiler options", "PBCCHelpPath", BYCOPY strPBCCHelpPath
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Platform SDK Help path
   ' =====================================================================================
   PROPERTY GET SDKHelpPath () AS STRING
      PROPERTY = AfxIniFileRead(m_szIniFileName, "Compiler options", "SDKHelpPath")
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET SDKHelpPath (BYVAL strSDKHelpPath AS STRING)
      AfxIniFileWrite m_szIniFileName, "Compiler options", "SDKHelpPath", BYCOPY strSDKHelpPath
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Command line arguments
   ' =====================================================================================
   PROPERTY GET CommandLine () AS STRING
      PROPERTY = AfxIniFileRead(m_szIniFileName, "Compiler options", "CommandLine")
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET CommandLine (BYVAL strCommandLine AS STRING)
      AfxIniFileWrite m_szIniFileName, "Compiler options", "CommandLine", BYCOPY strCommandLine
   END PROPERTY
   ' =====================================================================================

   ' *** Folding options *****************************************************************

   ' =====================================================================================
   ' Folding level
   ' =====================================================================================
   PROPERTY GET FoldLevel () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Fold options", "FoldLevel")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = 1 : ME.FoldLevel = 1
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET FoldLevel (BYVAL nFoldLevel AS LONG)
      AfxIniFileWrite m_szIniFileName, "Fold options", "FoldLevel", FORMAT$(nFoldLevel)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Folding symbol
   ' =====================================================================================
   PROPERTY GET FoldSymbol () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Fold options", "FoldSymbol")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = 3 : ME.FoldSymbol = 3
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET FoldSymbol (BYVAL nFoldSymbol AS LONG)
      AfxIniFileWrite m_szIniFileName, "Fold options", "FoldSymbol", FORMAT$(nFoldSymbol)
   END PROPERTY
   ' =====================================================================================

   ' *** Colors and fonts options ********************************************************

   ' =====================================================================================
   ' Default foreground color
   ' =====================================================================================
   PROPERTY GET DefaultForeColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "DefaultForeColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BLACK : ME.DefaultForeColor = %BLACK
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET DefaultForeColor (BYVAL nDefaultForeColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "DefaultForeColor", FORMAT$(nDefaultForeColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Default background color
   ' =====================================================================================
   PROPERTY GET DefaultBackColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "DefaultBackColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %WHITE : ME.DefaultBackColor = %WHITE
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET DefaultBackColor (BYVAL nDefaultBackColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "DefaultBackColor", FORMAT$(nDefaultBackColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Default font name
   ' =====================================================================================
   PROPERTY GET DefaultFontName () AS STRING
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "DefaultFontName")
      IF LEN(rs) THEN PROPERTY = rs ELSE PROPERTY = "Courier New" : ME.DefaultFontName = "Courier New"
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET DefaultFontName (BYVAL strDefaultFontName AS STRING)
      AfxIniFileWrite m_szIniFileName, "Color options", "DefaultFontName", BYCOPY strDefaultFontName
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Default character set
   ' =====================================================================================
   PROPERTY GET DefaultFontCharset () AS STRING
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "DefaultFontCharset")
      IF LEN(rs) THEN PROPERTY = rs ELSE PROPERTY = "Default" : ME.DefaultFontCharset = "Default"
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET DefaultFontCharset (BYVAL strDefaultFontCharset AS STRING)
      AfxIniFileWrite m_szIniFileName, "Color options", "DefaultFontCharset", BYCOPY strDefaultFontCharset
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Default font size
   ' =====================================================================================
   PROPERTY GET DefaultFontSize () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "DefaultFontSize")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = 10 : ME.DefaultFontSize = 10
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET DefaultFontSize (BYVAL nDefaultFontSize AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "DefaultFontSize", FORMAT$(nDefaultFontSize)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Default font bold
   ' =====================================================================================
   PROPERTY GET DefaultFontBold () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "DefaultFontBold"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET DefaultFontBold (BYVAL bDefaultFontBold AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "DefaultFontBold", FORMAT$(bDefaultFontBold)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Default font italic
   ' =====================================================================================
   PROPERTY GET DefaultFontItalic () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "DefaultFontItalic"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET DefaultFontItalic (BYVAL bDefaultFontItalic AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "DefaultFontItalic", FORMAT$(bDefaultFontItalic)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Default font underline
   ' =====================================================================================
   PROPERTY GET DefaultFontUnderline () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "DefaultFontUnderline"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET DefaultFontUnderline (BYVAL bDefaultFontUnderline AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "DefaultFontUnderline", FORMAT$(bDefaultFontUnderline)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Comment foreground color
   ' =====================================================================================
   PROPERTY GET CommentForeColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "CommentForeColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = RGB(0, 128, 0) : ME.CommentForeColor = RGB(0, 128, 0)
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET CommentForeColor (BYVAL nCommentForeColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "CommentForeColor", FORMAT$(nCommentForeColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Comment background color
   ' =====================================================================================
   PROPERTY GET CommentBackColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "CommentBackColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %WHITE : ME.CommentBackColor = %WHITE
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET CommentBackColor (BYVAL nCommentBackColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "CommentBackColor", FORMAT$(nCommentBackColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Comment font name
   ' =====================================================================================
   PROPERTY GET CommentFontName () AS STRING
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "CommentFontName")
      IF LEN(rs) THEN PROPERTY = rs ELSE PROPERTY = "Courier New" : ME.CommentFontName = "Courier New"
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET CommentFontName (BYVAL strCommentFontName AS STRING)
      AfxIniFileWrite m_szIniFileName, "Color options", "CommentFontName", BYCOPY strCommentFontName
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Comment character set
   ' =====================================================================================
   PROPERTY GET CommentFontCharset () AS STRING
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "CommentFontCharset")
      IF LEN(rs) THEN PROPERTY = rs ELSE PROPERTY = "Default" : ME.CommentFontCharset = "Default"
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET CommentFontCharset (BYVAL strCommentFontCharset AS STRING)
      AfxIniFileWrite m_szIniFileName, "Color options", "CommentFontCharset", BYCOPY strCommentFontCharset
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Comment font size
   ' =====================================================================================
   PROPERTY GET CommentFontSize () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "CommentFontSize")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = 8 : ME.CommentFontSize = 8
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET CommentFontSize (BYVAL nCommentFontSize AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "CommentFontSize", FORMAT$(nCommentFontSize)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Comment font bold
   ' =====================================================================================
   PROPERTY GET CommentFontBold () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "CommentFontBold"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET CommentFontBold (BYVAL bCommentFontBold AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "CommentFontBold", FORMAT$(bCommentFontBold)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Comment font italic
   ' =====================================================================================
   PROPERTY GET CommentFontItalic () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "CommentFontItalic"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET CommentFontItalic (BYVAL bCommentFontItalic AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "CommentFontItalic", FORMAT$(bCommentFontItalic)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Comment font underline
   ' =====================================================================================
   PROPERTY GET CommentFontUnderline () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "CommentFontUnderline"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET CommentFontUnderline (BYVAL bCommentFontUnderline AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "CommentFontUnderline", FORMAT$(bCommentFontUnderline)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Constant foreground color
   ' =====================================================================================
   PROPERTY GET ConstantForeColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "ConstantForeColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = RGB(230, 50, 0) : ME.ConstantForeColor = RGB(230, 50, 0)
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET ConstantForeColor (BYVAL nConstantForeColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "ConstantForeColor", FORMAT$(nConstantForeColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Constant background color
   ' =====================================================================================
   PROPERTY GET ConstantBackColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "ConstantBackColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %WHITE : ME.ConstantBackColor = %WHITE
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET ConstantBackColor (BYVAL nConstantBackColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "ConstantBackColor", FORMAT$(nConstantBackColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Constant font name
   ' =====================================================================================
   PROPERTY GET ConstantFontName () AS STRING
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "ConstantFontName")
      IF LEN(rs) THEN PROPERTY = rs ELSE PROPERTY = "Courier New" : ME.ConstantFontName = "Courier New"
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET ConstantFontName (BYVAL strConstantFontName AS STRING)
      AfxIniFileWrite m_szIniFileName, "Color options", "ConstantFontName", BYCOPY strConstantFontName
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Constant character set
   ' =====================================================================================
   PROPERTY GET ConstantFontCharset () AS STRING
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "ConstantFontCharset")
      IF LEN(rs) THEN PROPERTY = rs ELSE PROPERTY = "Default" : ME.ConstantFontCharset = "Default"
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET ConstantFontCharset (BYVAL strConstantFontCharset AS STRING)
      AfxIniFileWrite m_szIniFileName, "Color options", "ConstantFontCharset", BYCOPY strConstantFontCharset
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Constant font size
   ' =====================================================================================
   PROPERTY GET ConstantFontSize () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "ConstantFontSize")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = 8 : ME.ConstantFontSize = 8
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET ConstantFontSize (BYVAL nConstantFontSize AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "ConstantFontSize", FORMAT$(nConstantFontSize)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Constant font bold
   ' =====================================================================================
   PROPERTY GET ConstantFontBold () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "ConstantFontBold"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET ConstantFontBold (BYVAL bConstantFontBold AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "ConstantFontBold", FORMAT$(bConstantFontBold)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Constant font italic
   ' =====================================================================================
   PROPERTY GET ConstantFontItalic () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "ConstantFontItalic"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET ConstantFontItalic (BYVAL bConstantFontItalic AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "ConstantFontItalic", FORMAT$(bConstantFontItalic)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Constant font underline
   ' =====================================================================================
   PROPERTY GET ConstantFontUnderline () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "ConstantFontUnderline"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET ConstantFontUnderline (BYVAL bConstantFontUnderline AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "ConstantFontUnderline", FORMAT$(bConstantFontUnderline)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Identifier foreground color
   ' =====================================================================================
   PROPERTY GET IdentifierForeColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "IdentifierForeColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BLACK : ME.IdentifierForeColor = %BLACK
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET IdentifierForeColor (BYVAL nIdentifierForeColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "IdentifierForeColor", FORMAT$(nIdentifierForeColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Identifier background color
   ' =====================================================================================
   PROPERTY GET IdentifierBackColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "IdentifierBackColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %WHITE : ME.IdentifierBackColor = %WHITE
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET IdentifierBackColor (BYVAL nIdentifierBackColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "IdentifierBackColor", FORMAT$(nIdentifierBackColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Identifier font name
   ' =====================================================================================
   PROPERTY GET IdentifierFontName () AS STRING
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "IdentifierFontName")
      IF LEN(rs) THEN PROPERTY = rs ELSE PROPERTY = "Courier New" : ME.IdentifierFontName = "Courier New"
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET IdentifierFontName (BYVAL strIdentifierFontName AS STRING)
      AfxIniFileWrite m_szIniFileName, "Color options", "IdentifierFontName", BYCOPY strIdentifierFontName
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Identifier character set
   ' =====================================================================================
   PROPERTY GET IdentifierFontCharset () AS STRING
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "IdentifierFontCharset")
      IF LEN(rs) THEN PROPERTY = rs ELSE PROPERTY = "Default" : ME.IdentifierFontCharset = "Default"
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET IdentifierFontCharset (BYVAL strIdentifierFontCharset AS STRING)
      AfxIniFileWrite m_szIniFileName, "Color options", "IdentifierFontCharset", BYCOPY strIdentifierFontCharset
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Identifier font size
   ' =====================================================================================
   PROPERTY GET IdentifierFontSize () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "IdentifierFontSize")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = 8 : ME.IdentifierFontSize = 8
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET IdentifierFontSize (BYVAL nIdentifierFontSize AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "IdentifierFontSize", FORMAT$(nIdentifierFontSize)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Identifier font bold
   ' =====================================================================================
   PROPERTY GET IdentifierFontBold () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "IdentifierFontBold"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET IdentifierFontBold (BYVAL bIdentifierFontBold AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "IdentifierFontBold", FORMAT$(bIdentifierFontBold)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Identifier font italic
   ' =====================================================================================
   PROPERTY GET IdentifierFontItalic () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "IdentifierFontItalic"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET IdentifierFontItalic (BYVAL bIdentifierFontItalic AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "IdentifierFontItalic", FORMAT$(bIdentifierFontItalic)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Identifier font underline
   ' =====================================================================================
   PROPERTY GET IdentifierFontUnderline () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "IdentifierFontUnderline"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET IdentifierFontUnderline (BYVAL bIdentifierFontUnderline AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "IdentifierFontUnderline", FORMAT$(bIdentifierFontUnderline)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Keyword foreground color
   ' =====================================================================================
   PROPERTY GET KeywordForeColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "KeywordForeColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = RGB(0, 0, 255) : ME.KeywordForeColor = RGB(0, 0, 255)
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET KeywordForeColor (BYVAL nKeywordForeColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "KeywordForeColor", FORMAT$(nKeywordForeColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Keyword background color
   ' =====================================================================================
   PROPERTY GET KeywordBackColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "KeywordBackColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %WHITE : ME.KeywordBackColor = %WHITE
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET KeywordBackColor (BYVAL nKeywordBackColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "KeywordBackColor", FORMAT$(nKeywordBackColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Keyword font name
   ' =====================================================================================
   PROPERTY GET KeywordFontName () AS STRING
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "KeywordFontName")
      IF LEN(rs) THEN PROPERTY = rs ELSE PROPERTY = "Courier New" : ME.KeywordFontName = "Courier New"
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET KeywordFontName (BYVAL strKeywordFontName AS STRING)
      AfxIniFileWrite m_szIniFileName, "Color options", "KeywordFontName", BYCOPY strKeywordFontName
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Keyword character set
   ' =====================================================================================
   PROPERTY GET KeywordFontCharset () AS STRING
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "KeywordFontCharset")
      IF LEN(rs) THEN PROPERTY = rs ELSE PROPERTY = "Default" : ME.KeywordFontCharset = "Default"
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET KeywordFontCharset (BYVAL strKeywordFontCharset AS STRING)
      AfxIniFileWrite m_szIniFileName, "Color options", "KeywordFontCharset", BYCOPY strKeywordFontCharset
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Keyword font size
   ' =====================================================================================
   PROPERTY GET KeywordFontSize () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "KeywordFontSize")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = 8 : ME.KeywordFontSize = 8
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET KeywordFontSize (BYVAL nKeywordFontSize AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "KeywordFontSize", FORMAT$(nKeywordFontSize)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Keyword font bold
   ' =====================================================================================
   PROPERTY GET KeywordFontBold () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "KeywordFontBold"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET KeywordFontBold (BYVAL bKeywordFontBold AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "KeywordFontBold", FORMAT$(bKeywordFontBold)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Keyword font italic
   ' =====================================================================================
   PROPERTY GET KeywordFontItalic () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "KeywordFontItalic"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET KeywordFontItalic (BYVAL bKeywordFontItalic AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "KeywordFontItalic", FORMAT$(bKeywordFontItalic)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Keyword font underline
   ' =====================================================================================
   PROPERTY GET KeywordFontUnderline () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "KeywordFontUnderline"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET KeywordFontUnderline (BYVAL bKeywordFontUnderline AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "KeywordFontUnderline", FORMAT$(bKeywordFontUnderline)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Number foreground color
   ' =====================================================================================
   PROPERTY GET NumberForeColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "NumberForeColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = RGB(192, 100, 0) : ME.NumberForeColor = RGB(192, 100, 0)
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET NumberForeColor (BYVAL nNumberForeColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "NumberForeColor", FORMAT$(nNumberForeColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Number background color
   ' =====================================================================================
   PROPERTY GET NumberBackColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "NumberBackColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %WHITE : ME.NumberBackColor = %WHITE
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET NumberBackColor (BYVAL nNumberBackColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "NumberBackColor", FORMAT$(nNumberBackColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Number font name
   ' =====================================================================================
   PROPERTY GET NumberFontName () AS STRING
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "NumberFontName")
      IF LEN(rs) THEN PROPERTY = rs ELSE PROPERTY = "Courier New" : ME.NumberFontName = "Courier New"
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET NumberFontName (BYVAL strNumberFontName AS STRING)
      AfxIniFileWrite m_szIniFileName, "Color options", "NumberFontName", BYCOPY strNumberFontName
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Number character set
   ' =====================================================================================
   PROPERTY GET NumberFontCharset () AS STRING
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "NumberFontCharset")
      IF LEN(rs) THEN PROPERTY = rs ELSE PROPERTY = "Default" : ME.NumberFontCharset = "Default"
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET NumberFontCharset (BYVAL strNumberFontCharset AS STRING)
      AfxIniFileWrite m_szIniFileName, "Color options", "NumberFontCharset", BYCOPY strNumberFontCharset
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Number font size
   ' =====================================================================================
   PROPERTY GET NumberFontSize () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "NumberFontSize")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = 8 : ME.NumberFontSize = 8
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET NumberFontSize (BYVAL nNumberFontSize AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "NumberFontSize", FORMAT$(nNumberFontSize)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Number font bold
   ' =====================================================================================
   PROPERTY GET NumberFontBold () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "NumberFontBold"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET NumberFontBold (BYVAL bNumberFontBold AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "NumberFontBold", FORMAT$(bNumberFontBold)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Number font italic
   ' =====================================================================================
   PROPERTY GET NumberFontItalic () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "NumberFontItalic"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET NumberFontItalic (BYVAL bNumberFontItalic AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "NumberFontItalic", FORMAT$(bNumberFontItalic)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Number font underline
   ' =====================================================================================
   PROPERTY GET NumberFontUnderline () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "NumberFontUnderline"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET NumberFontUnderline (BYVAL bNumberFontUnderline AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "NumberFontUnderline", FORMAT$(bNumberFontUnderline)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Line number foreground color
   ' =====================================================================================
   PROPERTY GET LineNumberForeColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "LineNumberForeColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BLACK : ME.LineNumberForeColor = %BLACK
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET LineNumberForeColor (BYVAL nLineNumberForeColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "LineNumberForeColor", FORMAT$(nLineNumberForeColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Line number background color
   ' =====================================================================================
   PROPERTY GET LineNumberBackColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "LineNumberBackColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %LTGRAY : ME.LineNumberBackColor = %LTGRAY
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET LineNumberBackColor (BYVAL nLineNumberBackColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "LineNumberBackColor", FORMAT$(nLineNumberBackColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Line number font name
   ' =====================================================================================
   PROPERTY GET LineNumberFontName () AS STRING
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "LineNumberFontName")
      IF LEN(rs) THEN PROPERTY = rs ELSE PROPERTY = "Courier New" : ME.LineNumberFontName = "Courier New"
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET LineNumberFontName (BYVAL strLineNumberFontName AS STRING)
      AfxIniFileWrite m_szIniFileName, "Color options", "LineNumberFontName", BYCOPY strLineNumberFontName
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Line number character set
   ' =====================================================================================
   PROPERTY GET LineNumberFontCharset () AS STRING
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "LineNumberFontCharset")
      IF LEN(rs) THEN PROPERTY = rs ELSE PROPERTY = "Default" : ME.LineNumberFontCharset = "Default"
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET LineNumberFontCharset (BYVAL strLineNumberFontCharset AS STRING)
      AfxIniFileWrite m_szIniFileName, "Color options", "LineNumberFontCharset", BYCOPY strLineNumberFontCharset
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Line number font size
   ' =====================================================================================
   PROPERTY GET LineNumberFontSize () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "LineNumberFontSize")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = 8 : ME.LineNumberFontSize = 8
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET LineNumberFontSize (BYVAL nLineNumberFontSize AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "LineNumberFontSize", FORMAT$(nLineNumberFontSize)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Line number font bold
   ' =====================================================================================
   PROPERTY GET LineNumberFontBold () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "LineNumberFontBold"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET LineNumberFontBold (BYVAL bLineNumberFontBold AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "LineNumberFontBold", FORMAT$(bLineNumberFontBold)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Line number font italic
   ' =====================================================================================
   PROPERTY GET LineNumberFontItalic () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "LineNumberFontItalic"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET LineNumberFontItalic (BYVAL bLineNumberFontItalic AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "LineNumberFontItalic", FORMAT$(bLineNumberFontItalic)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Line number font underline
   ' =====================================================================================
   PROPERTY GET LineNumberFontUnderline () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "LineNumberFontUnderline"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET LineNumberFontUnderline (BYVAL bLineNumberFontUnderline AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "LineNumberFontUnderline", FORMAT$(bLineNumberFontUnderline)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Operator foreground color
   ' =====================================================================================
   PROPERTY GET OperatorForeColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "OperatorForeColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = RGB(0, 128, 128) : ME.OperatorForeColor = RGB(0, 128, 128)
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET OperatorForeColor (BYVAL nOperatorForeColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "OperatorForeColor", FORMAT$(nOperatorForeColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Operator background color
   ' =====================================================================================
   PROPERTY GET OperatorBackColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "OperatorBackColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %WHITE : ME.OperatorBackColor = %WHITE
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET OperatorBackColor (BYVAL nOperatorBackColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "OperatorBackColor", FORMAT$(nOperatorBackColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Operator font name
   ' =====================================================================================
   PROPERTY GET OperatorFontName () AS STRING
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "OperatorFontName")
      IF LEN(rs) THEN PROPERTY = rs ELSE PROPERTY = "Courier New" : ME.OperatorFontName = "Courier New"
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET OperatorFontName (BYVAL strOperatorFontName AS STRING)
      AfxIniFileWrite m_szIniFileName, "Color options", "OperatorFontName", BYCOPY strOperatorFontName
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Operator character set
   ' =====================================================================================
   PROPERTY GET OperatorFontCharset () AS STRING
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "OperatorFontCharset")
      IF LEN(rs) THEN PROPERTY = rs ELSE PROPERTY = "Default" : ME.OperatorFontCharset = "Default"
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET OperatorFontCharset (BYVAL strOperatorFontCharset AS STRING)
      AfxIniFileWrite m_szIniFileName, "Color options", "OperatorFontCharset", BYCOPY strOperatorFontCharset
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Operator font size
   ' =====================================================================================
   PROPERTY GET OperatorFontSize () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "OperatorFontSize")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = 8 : ME.OperatorFontSize = 8
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET OperatorFontSize (BYVAL nOperatorFontSize AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "OperatorFontSize", FORMAT$(nOperatorFontSize)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Operator font bold
   ' =====================================================================================
   PROPERTY GET OperatorFontBold () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "OperatorFontBold"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET OperatorFontBold (BYVAL bOperatorFontBold AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "OperatorFontBold", FORMAT$(bOperatorFontBold)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Operator font italic
   ' =====================================================================================
   PROPERTY GET OperatorFontItalic () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "OperatorFontItalic"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET OperatorFontItalic (BYVAL bOperatorFontItalic AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "OperatorFontItalic", FORMAT$(bOperatorFontItalic)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Operator font underline
   ' =====================================================================================
   PROPERTY GET OperatorFontUnderline () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "OperatorFontUnderline"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET OperatorFontUnderline (BYVAL bOperatorFontUnderline AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "OperatorFontUnderline", FORMAT$(bOperatorFontUnderline)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Preprocessor foreground color
   ' =====================================================================================
   PROPERTY GET PreprocessorForeColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "PreprocessorForeColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = RGB(255, 0, 0) : ME.PreprocessorForeColor = RGB(255, 0, 0)
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET PreprocessorForeColor (BYVAL nPreprocessorForeColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "PreprocessorForeColor", FORMAT$(nPreprocessorForeColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Preprocessor background color
   ' =====================================================================================
   PROPERTY GET PreprocessorBackColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "PreprocessorBackColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %WHITE : ME.PreprocessorBackColor = %WHITE
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET PreprocessorBackColor (BYVAL nPreprocessorBackColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "PreprocessorBackColor", FORMAT$(nPreprocessorBackColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Preprocessor font name
   ' =====================================================================================
   PROPERTY GET PreprocessorFontName () AS STRING
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "PreprocessorFontName")
      IF LEN(rs) THEN PROPERTY = rs ELSE PROPERTY = "Courier New" : ME.PreprocessorFontName = "Courier New"
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET PreprocessorFontName (BYVAL strPreprocessorFontName AS STRING)
      AfxIniFileWrite m_szIniFileName, "Color options", "PreprocessorFontName", BYCOPY strPreprocessorFontName
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Preprocessor character set
   ' =====================================================================================
   PROPERTY GET PreprocessorFontCharset () AS STRING
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "PreprocessorFontCharset")
      IF LEN(rs) THEN PROPERTY = rs ELSE PROPERTY = "Default" : ME.PreprocessorFontCharset = "Default"
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET PreprocessorFontCharset (BYVAL strPreprocessorFontCharset AS STRING)
      AfxIniFileWrite m_szIniFileName, "Color options", "PreprocessorFontCharset", BYCOPY strPreprocessorFontCharset
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Preprocessor font size
   ' =====================================================================================
   PROPERTY GET PreprocessorFontSize () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "PreprocessorFontSize")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = 8 : ME.PreprocessorFontSize = 8
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET PreprocessorFontSize (BYVAL nPreprocessorFontSize AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "PreprocessorFontSize", FORMAT$(nPreprocessorFontSize)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Preprocessor font bold
   ' =====================================================================================
   PROPERTY GET PreprocessorFontBold () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "PreprocessorFontBold"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET PreprocessorFontBold (BYVAL bPreprocessorFontBold AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "PreprocessorFontBold", FORMAT$(bPreprocessorFontBold)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Preprocessor font italic
   ' =====================================================================================
   PROPERTY GET PreprocessorFontItalic () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "PreprocessorFontItalic"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET PreprocessorFontItalic (BYVAL bPreprocessorFontItalic AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "PreprocessorFontItalic", FORMAT$(bPreprocessorFontItalic)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Preprocessor font underline
   ' =====================================================================================
   PROPERTY GET PreprocessorFontUnderline () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "PreprocessorFontUnderline"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET PreprocessorFontUnderline (BYVAL bPreprocessorFontUnderline AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "PreprocessorFontUnderline", FORMAT$(bPreprocessorFontUnderline)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' String foreground color
   ' =====================================================================================
   PROPERTY GET StringForeColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "StringForeColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = RGB(255, 0, 255) : ME.StringForeColor = RGB(255, 0, 255)
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET StringForeColor (BYVAL nStringForeColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "StringForeColor", FORMAT$(nStringForeColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' String background color
   ' =====================================================================================
   PROPERTY GET StringBackColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "StringBackColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %WHITE : ME.StringBackColor = %WHITE
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET StringBackColor (BYVAL nStringBackColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "StringBackColor", FORMAT$(nStringBackColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' String font name
   ' =====================================================================================
   PROPERTY GET StringFontName () AS STRING
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "StringFontName")
      IF LEN(rs) THEN PROPERTY = rs ELSE PROPERTY = "Courier New" : ME.StringFontName = "Courier New"
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET StringFontName (BYVAL strStringFontName AS STRING)
      AfxIniFileWrite m_szIniFileName, "Color options", "StringFontName", BYCOPY strStringFontName
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' String character set
   ' =====================================================================================
   PROPERTY GET StringFontCharset () AS STRING
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "StringFontCharset")
      IF LEN(rs) THEN PROPERTY = rs ELSE PROPERTY = "Default" : ME.StringFontCharset = "Default"
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET StringFontCharset (BYVAL strStringFontCharset AS STRING)
      AfxIniFileWrite m_szIniFileName, "Color options", "StringFontCharset", BYCOPY strStringFontCharset
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' String font size
   ' =====================================================================================
   PROPERTY GET StringFontSize () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "StringFontSize")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = 8 : ME.StringFontSize = 8
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET StringFontSize (BYVAL nStringFontSize AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "StringFontSize", FORMAT$(nStringFontSize)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' String font bold
   ' =====================================================================================
   PROPERTY GET StringFontBold () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "StringFontBold"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET StringFontBold (BYVAL bStringFontBold AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "StringFontBold", FORMAT$(bStringFontBold)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' String font italic
   ' =====================================================================================
   PROPERTY GET StringFontItalic () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "StringFontItalic"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET StringFontItalic (BYVAL bStringFontItalic AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "StringFontItalic", FORMAT$(bStringFontItalic)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' String font underline
   ' =====================================================================================
   PROPERTY GET StringFontUnderline () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_szIniFileName, "Color options", "StringFontUnderline"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET StringFontUnderline (BYVAL bStringFontUnderline AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "StringFontUnderline", FORMAT$(bStringFontUnderline)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Caret foreground color
   ' =====================================================================================
   PROPERTY GET CaretForeColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "CaretForeColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BLACK : ME.CaretForeColor = %BLACK
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET CaretForeColor (BYVAL nCaretForeColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "CaretForeColor", FORMAT$(nCaretForeColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Edge foreground color
   ' =====================================================================================
   PROPERTY GET EdgeForeColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "EdgeForeColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BLACK : ME.EdgeForeColor = %BLACK
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET EdgeForeColor (BYVAL nEdgeForeColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "EdgeForeColor", FORMAT$(nEdgeForeColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Edge background color
   ' =====================================================================================
   PROPERTY GET EdgeBackColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "EdgeBackColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %WHITE : ME.EdgeBackColor = %WHITE
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET EdgeBackColor (BYVAL nEdgeBackColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "EdgeBackColor", FORMAT$(nEdgeBackColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Fold foreground color
   ' =====================================================================================
   PROPERTY GET FoldForeColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "FoldForeColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %RED : ME.FoldForeColor = %RED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET FoldForeColor (BYVAL nFoldForeColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "FoldForeColor", FORMAT$(nFoldForeColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Fold background color
   ' =====================================================================================
   PROPERTY GET FoldBackColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "FoldBackColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %WHITE : ME.FoldBackColor = %WHITE
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET FoldBackColor (BYVAL nFoldBackColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "FoldBackColor", FORMAT$(nFoldBackColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Folder open foreground color
   ' =====================================================================================
   PROPERTY GET FoldOpenForeColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "FoldOpenForeColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %RED : ME.FoldOpenForeColor = %RED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET FoldOpenForeColor (BYVAL nFoldOpenForeColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "FoldOpenForeColor", FORMAT$(nFoldOpenForeColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Folder open background color
   ' =====================================================================================
   PROPERTY GET FoldOpenBackColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "FoldOpenBackColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %WHITE : ME.FoldOpenBackColor = %WHITE
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET FoldOpenBackColor (BYVAL nFoldOpenBackColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "FoldOpenBackColor", FORMAT$(nFoldOpenBackColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Folder margin foreground color
   ' =====================================================================================
   PROPERTY GET FoldMarginForeColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "FoldMarginForeColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = RGB(200,0,200) : ME.FoldMarginForeColor = RGB(200,0,200)
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET FoldMarginForeColor (BYVAL nFoldMarginForeColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "FoldMarginForeColor", FORMAT$(nFoldMarginForeColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Folder margin background color
   ' =====================================================================================
   PROPERTY GET FoldMarginBackColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "FoldMarginBackColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = RGB(200,0,200) : ME.FoldMarginBackColor = RGB(200,0,200)
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET FoldMarginBackColor (BYVAL nFoldMarginBackColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "FoldMarginBackColor", FORMAT$(nFoldMarginBackColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Indent guide foreground color
   ' =====================================================================================
   PROPERTY GET IndentGuideForeColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "IndentGuideForeColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BLACK : ME.IndentGuideForeColor = %BLACK
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET IndentGuideForeColor (BYVAL nIndentGuideForeColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "IndentGuideForeColor", FORMAT$(nIndentGuideForeColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Indent guide background color
   ' =====================================================================================
   PROPERTY GET IndentGuideBackColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "IndentGuideBackColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %WHITE : ME.IndentGuideBackColor = %WHITE
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET IndentGuideBackColor (BYVAL nIndentGuideBackColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "IndentGuideBackColor", FORMAT$(nIndentGuideBackColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Selection foreground color
   ' =====================================================================================
   PROPERTY GET SelectionForeColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "SelectionForeColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BLACK : ME.SelectionForeColor = %BLACK
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET SelectionForeColor (BYVAL nSelectionForeColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "SelectionForeColor", FORMAT$(nSelectionForeColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Selection background color
   ' =====================================================================================
   PROPERTY GET SelectionBackColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "SelectionBackColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %LTGRAY : ME.SelectionBackColor = %LTGRAY
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET SelectionBackColor (BYVAL nSelectionBackColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "SelectionBackColor", FORMAT$(nSelectionBackColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' White space foreground color
   ' =====================================================================================
   PROPERTY GET WhitespaceForeColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "WhitespaceForeColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BLACK : ME.WhitespaceForeColor = %BLACK
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET WhitespaceForeColor (BYVAL nWhitespaceForeColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "WhitespaceForeColor", FORMAT$(nWhitespaceForeColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' White space background color
   ' =====================================================================================
   PROPERTY GET WhitespaceBackColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "WhitespaceBackColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %WHITE : ME.WhitespaceBackColor = %WHITE
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET WhitespaceBackColor (BYVAL nWhitespaceBackColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "WhitespaceBackColor", FORMAT$(nWhitespaceBackColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Codetip foreground color
   ' =====================================================================================
   PROPERTY GET CodetipForeColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "CodetipForeColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BLACK : ME.CodetipForeColor = %BLACK
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET CodetipForeColor (BYVAL nCodetipForeColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "CodetipForeColor", FORMAT$(nCodetipForeColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Codetip background color
   ' =====================================================================================
   PROPERTY GET CodetipBackColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "CodetipBackColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = &HDDFFFF : ME.CodetipBackColor = &HDDFFFF
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET CodetipBackColor (BYVAL nCodetipBackColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "CodetipBackColor", FORMAT$(nCodetipBackColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Caret line background color
   ' =====================================================================================
   PROPERTY GET CaretLineBackColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "CaretLineBackColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %YELLOW : ME.CaretLineBackColor = %YELLOW
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET CaretLineBackColor (BYVAL nCaretLineBackColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "CaretLineBackColor", FORMAT$(nCaretLineBackColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Use always the default background color
   ' =====================================================================================
   PROPERTY GET UseAlwaysDefaultBackColor () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "UseAlwaysDefaultBackColor")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_CHECKED : ME.UseAlwaysDefaultBackColor = %BST_CHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET UseAlwaysDefaultBackColor (BYVAL bUseAlwaysDefaultBackColor AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "UseAlwaysDefaultBackColor", FORMAT$(bUseAlwaysDefaultBackColor)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Use always the default font
   ' =====================================================================================
   PROPERTY GET UseAlwaysDefaultFont () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "UseAlwaysDefaultFont")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_CHECKED : ME.UseAlwaysDefaultFont = %BST_CHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET UseAlwaysDefaultFont (BYVAL bUseAlwaysDefaultFont AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "UseAlwaysDefaultFont", FORMAT$(bUseAlwaysDefaultFont)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Use always the default font size
   ' =====================================================================================
   PROPERTY GET UseAlwaysDefaultFontSize () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Color options", "UseAlwaysDefaultFontSize")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_CHECKED : ME.UseAlwaysDefaultFontSize = %BST_CHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET UseAlwaysDefaultFontSize (BYVAL bUseAlwaysDefaultFontSize AS LONG)
      AfxIniFileWrite m_szIniFileName, "Color options", "UseAlwaysDefaultFontSize", FORMAT$(bUseAlwaysDefaultFontSize)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Window placement
   ' =====================================================================================
   METHOD SetWindowPlacement (BYVAL hwnd AS DWORD)
      ' // Get the current window placement
      LOCAL WinPla AS WINDOWPLACEMENT
      WinPla.Length = SIZEOF(WinPla)
      GetWindowPlacement(hwnd, WinPla)
      ' // Read the values saved in the .ini file
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Window placement", "Left")
      IF LEN(rs) THEN WinPla.rcNormalPosition.Left = VAL(rs)
      rs = AfxIniFileRead(m_szIniFileName, "Window placement", "Right")
      IF LEN(rs) THEN WinPla.rcNormalPosition.Right = VAL(rs)
      IF WinPla.rcNormalPosition.Right = 0 THEN WinPla.rcNormalPosition.Right = 800
      rs = AfxIniFileRead(m_szIniFileName, "Window placement", "Top")
      IF LEN(rs) THEN WinPla.rcNormalPosition.Top = VAL(rs)
      rs = AfxIniFileRead(m_szIniFileName, "Window placement", "Bottom")
      IF LEN(rs) THEN WinPla.rcNormalPosition.Bottom = VAL(rs)
      IF WinPla.rcNormalPosition.Bottom = 0 THEN WinPla.rcNormalPosition.Bottom = 570
      SetWindowPlacement hwnd, WinPla
      ' // Desktop's real size
      LOCAL rcDeskTop AS RECT
      SystemParametersInfo %SPI_GETWORKAREA, 0, rcDesktop, 0
      ' // Make sure dialog is not horizontally oversized
      IF WinPla.rcNormalPosition.Right - WinPla.rcNormalPosition.Left > rcDesktop.Right THEN
         WinPla.rcNormalPosition.Left = 0
         WinPla.rcNormalPosition.Right = rcDesktop.Right
      END IF
      ' // Make sure dialog is not vertically oversized
      IF WinPla.rcNormalPosition.Bottom - WinPla.rcNormalPosition.Top > rcDesktop.Bottom THEN
         WinPla.rcNormalPosition.Top = 0
         WinPla.rcNormalPosition.Bottom = rcDesktop.Bottom
      END IF
      ' // Make sure left side of dialog is visible
      IF WinPla.rcNormalPosition.Left < 0 THEN
         WinPla.rcNormalPosition.Right = WinPla.rcNormalPosition.Right - WinPla.rcNormalPosition.Left
         WinPla.rcNormalPosition.Left = 0
      END IF
      ' // Make sure right side of dialog is visible
      IF WinPla.rcNormalPosition.Right > rcDesktop.Right THEN
         WinPla.rcNormalPosition.Left = WinPla.rcNormalPosition.Left - (WinPla.rcNormalPosition.Right - rcDesktop.Right)
         WinPla.rcNormalPosition.Right = rcDesktop.Right
      END IF
      ' // Make sure top side of dialog is visible
      IF WinPla.rcNormalPosition.Top < 0 THEN
         WinPla.rcNormalPosition.Bottom = WinPla.rcNormalPosition.Bottom - WinPla.rcNormalPosition.Top
         WinPla.rcNormalPosition.Top = 0
      END IF
      ' // Make sure bottom side of dialog is visible
      IF WinPla.rcNormalPosition.Bottom > rcDesktop.Bottom THEN
         WinPla.rcNormalPosition.Top = WinPla.rcNormalPosition.Top - (WinPla.rcNormalPosition.Bottom - rcDesktop.Bottom)
         WinPla.rcNormalPosition.Bottom = rcDesktop.Bottom
      END IF
      ' // Adjust the working area
      LOCAL rc AS RECT
      SystemParametersInfo %SPI_GETWORKAREA, 0, rc, 0
      IF WinPla.rcNormalPosition.Left = rc.Left AND WinPla.rcNormalPosition.Right = rc.Right THEN WinPla.rcNormalPosition.Right = WinPla.rcNormalPosition.Right
      IF WinPla.rcNormalPosition.Top = rc.Top AND WinPla.rcNormalPosition.Bottom = rc.Bottom THEN WinPla.rcNormalPosition.Bottom = WinPla.rcNormalPosition.Bottom
      ' // Place the window
      SetWindowPlacement hwnd, WinPla
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD SaveWindowPlacement (BYVAL hwnd AS DWORD)
      ' // Get the current window placement
      LOCAL WinPla AS WINDOWPLACEMENT
      WinPla.Length = SIZEOF(WinPla)
      GetWindowPlacement(hwnd, WinPla)
      ' // Save the values in the .ini file
      AfxIniFileWrite m_szIniFileName, "Window placement", "Left", FORMAT$(WinPla.rcNormalPosition.Left)
      AfxIniFileWrite m_szIniFileName, "Window placement", "Right", FORMAT$(WinPla.rcNormalPosition.Right)
      AfxIniFileWrite m_szIniFileName, "Window placement", "Top", FORMAT$(WinPla.rcNormalPosition.Top)
      AfxIniFileWrite m_szIniFileName, "Window placement", "Bottom", FORMAT$(WinPla.rcNormalPosition.Bottom)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Bookmarks
   ' =====================================================================================
   METHOD SetBookmarks (BYVAL strPath AS STRING)
      LOCAL strExt AS STRING
      LOCAL strBookmarks AS STRING
      LOCAL i AS LONG
      LOCAL nLine AS LONG
      ' // Change the extension
      strExt = UCASE$(PATHNAME$(EXTN, strPath))
      IF LCASE$(strExt) = ".csbmk" THEN EXIT METHOD
      strPath + = ".csbmk"
      strBookmarks = AfxIniFileRead(strPath, "Bookmarks", "Bookmarks")
      IF ISNULL(strBookmarks) THEN EXIT METHOD
      FOR i = 1 TO PARSECOUNT(strBookmarks, "|")
         nLine = VAL(PARSE$(strBookmarks, "|", i))
         SCI_MarkerAdd(pSed.hEdit, nLine, 0)
      NEXT
      ' // Set the caret position after scrolling the text to make
      ' // the target line to appear in the middle of the screen
      LOCAL caretPos AS LONG
      LOCAL endPos AS LONG
      LOCAL LinesOnScreen AS LONG
      LOCAL LineToGo AS LONG
      ' // Get the saved caret position
      caretPos = VAL(AfxIniFileRead(strPath, "Caret position", "CaretPos"))
      ' // Get the length of the text
      endPos = SCI_GetTextLEngth(pSed.hEdit)
      ' // Goto to the end of the text
      SCI_GotoPos(pSed.hEdit, endPos)
      ' // Number of lines of the screen
      LinesOnScreen = SCI_LinesOnScreen(pSed.hEdit)
      ' // Line to go
      LineToGo = SCI_LineFromPosition(pSed.hEdit, caretPos)
      LineToGo -= LinesOnScreen \ 2
      ' // Go to the line
      SCI_GotoLine(pSed.hEdit, LineToGo)
      ' // set the caret position
      SCI_GotoPos(pSed.hEdit, caretPos)
   END METHOD
   ' =====================================================================================
   METHOD SaveBookmarks (BYVAL hSci AS DWORD, BYVAL strPath AS STRING)
      LOCAL caretPos AS LONG
      LOCAL strExt AS STRING
      LOCAL strBookmarks AS STRING
      LOCAL fMark AS LONG
      LOCAL nLine AS LONG
      ' // Exit if there are no bookmarks
      IF hSci = 0 THEN EXIT METHOD
      BIT SET fMark, 0
      IF SCI_MarkerNext(hSci, 0, fMark) = -1 THEN EXIT METHOD
      strExt = UCASE$(PATHNAME$(EXTN, strPath))
      IF LCASE$(strExt) = ".csbmk" THEN EXIT METHOD
      strPath + = ".csbmk"
      caretPos = SCI_GetCurrentPos(hSci)
      AfxIniFileWrite strPath, "Caret position", "CaretPos", FORMAT$(caretPos)
      ' // Retrieve the bookmark positions
      BIT SET fMark, 0
      nLine = SCI_MarkerNext(hSci, 0, fMark)
      DO WHILE nLine <> -1
         strBookmarks += "|" & FORMAT$(nLine)
         fMark = 0
         BIT SET fMark, 0
         nLine = SCI_MarkerNext(hSci, nLine + 1, fMark)
      LOOP
      ' // Remove the first "|"
      strBookmarks = MID$(strBookmarks, 2)
      ' // Write the list of bookmarks to file
      AfxIniFileWrite strPath, "Bookmarks", "Bookmarks", strBookmarks
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Recent files
   ' =====================================================================================
   PROPERTY GET RecentFilesIdx () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Recent files", "Index")
      IF LEN(rs) THEN PROPERTY = VAL(rs)
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   PROPERTY SET RecentFilesIdx (BYVAL idx AS LONG)
      AfxIniFileWrite m_szIniFileName, "Recent files", "Index", FORMAT$(idx)
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   METHOD GetRecentFile (BYVAL idx AS LONG) AS STRING
      LOCAL strIndex AS STRING
      strIndex = "File " & FORMAT$(idx)
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_szIniFileName, "Recent files", strIndex)
      IF LEN(rs) THEN METHOD = rs
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD ResetRecentFiles
      LOCAL idx AS LONG
      LOCAL strIndex AS STRING
      LOCAL strPath AS STRING
      REDIM strPaths(0) AS LOCAL STRING
      FOR idx = 1 TO 99
         strPath = ME.GetRecentFile(idx)
         IF ISNOTNULL(strPath) THEN
            REDIM PRESERVE strPaths(UBOUND(strPaths) + 1) AS LOCAL STRING
            strPaths(UBOUND(strPaths)) = strPath
         END IF
      NEXT
      AfxIniFileDeleteSection(m_szIniFileName, "Recent files")
      FOR idx = 1 TO UBOUND(strPaths)
         strIndex = "File " & FORMAT$(idx)
         strPath = strPaths(idx)
         AfxIniFileWrite m_szIniFileName, "Recent files", strIndex, BYCOPY strPath
      NEXT
      AfxIniFileWrite m_szIniFileName, "Recent files", "Index", FORMAT$(UBOUND(strPaths))
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD PurgeRecentFiles
      LOCAL idx AS LONG
      LOCAL strIndex AS STRING
      LOCAL strPath AS STRING
      REDIM strPaths(0) AS LOCAL STRING
      FOR idx = 1 TO 99
         strPath = ME.GetRecentFile(idx)
         IF ISNOTNULL(strPath) THEN
            IF ISFILE(strPath) THEN
               REDIM PRESERVE strPaths(UBOUND(strPaths) + 1) AS LOCAL STRING
               strPaths(UBOUND(strPaths)) = strPath
            END IF
         END IF
      NEXT
      AfxIniFileDeleteSection(m_szIniFileName, "Recent files")
      FOR idx = 1 TO UBOUND(strPaths)
         strIndex = "File " & FORMAT$(idx)
         strPath = strPaths(idx)
         AfxIniFileWrite m_szIniFileName, "Recent files", strIndex, BYCOPY strPath
      NEXT
      AfxIniFileWrite m_szIniFileName, "Recent files", "Index", FORMAT$(UBOUND(strPaths))
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD SetRecentFile (BYVAL strPath AS STRING)
      LOCAL idx AS LONG
      LOCAL strIndex AS STRING
      IF INSTR(strPath, ANY ":\/") = 0 THEN   ' // Path not available
         IF LEFT$(UCASE$(PATHNAME$(NAMEX, strPath)), 8) = "UNTITLED" THEN EXIT METHOD
      END IF
      ' // Check if it already exists
      FOR idx = 1 TO 99
         IF UCASE$(ME.GetRecentFile(idx)) = UCASE$(strPath) THEN
            ME.DeleteRecentFile(idx)
            ME.ResetRecentFiles
         END IF
      NEXT
      idx = ME.RecentFilesIdx
      IF idx => 99 THEN
         ME.DeleteRecentFile(1)
         ME.ResetRecentFiles
         idx = ME.RecentFilesIdx
      END IF
      idx +=1
      ME.RecentFilesIdx = idx
      strIndex = "File " & FORMAT$(idx)
      AfxIniFileWrite m_szIniFileName, "Recent files", strIndex, BYCOPY strPath
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD DeleteRecentFile (BYVAL idx AS LONG) AS LONG
      LOCAL strIndex AS STRING
      strIndex = "File " & FORMAT$(idx)
      METHOD = AfxIniFileDeleteKey(m_szIniFileName, "Recent files", strIndex)
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD DeleteAllRecentFiles () AS LONG
      METHOD = AfxIniFileDeleteSection(m_szIniFileName, "Recent files")
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Save the path of the loaded files
   ' =====================================================================================
   METHOD SaveFileSet
      LOCAL idx AS LONG
      LOCAL strIndex AS STRING
      LOCAL vPath AS VARIANT
      LOCAL strPath AS STRING
      LOCAL strCurPath AS STRING
      LOCAL caretPos AS LONG
      LOCAL hwndActive AS DWORD
      LOCAL strLine AS STRING
      LOCAL pTabFilePaths AS ILinkListCollection
      ' // Delete the section
      AfxIniFileDeleteSection(m_szIniFileName, "File set")
      ' // Get the path of the active window
      hwndActive = MdiGetActive(pSed.hwndClient)
      strCurPath = AfxGetWindowText(hwndActive)
      ' // Add the paths of the files
      pSed.TabFilePaths.First
      idx = 1
      DO
   '      vPath = pSed.TabFilePaths.Next
         pTabFilePaths = pSed.TabFilePaths
         vPath = pTabFilePaths.Next
         IF OBJRESULT = %S_FALSE THEN EXIT DO
         strPath = VARIANT$$(vPath)
         ' // Activate the window
         CSED_TabMdiActivateWindow(strPath)
         hwndActive = MdiGetActive(pSed.hwndClient)
         caretPos = SCI_GetCurrentPos(pSed.hEdit)
         IF (INSTR(strPath, ANY ":\/") <> 0) THEN
            strLine = FORMAT$(caretPos, "000000") & "|" & strPath
            strIndex = "File " & FORMAT$(idx)
            AfxIniFileWrite m_szIniFileName, "File set", strIndex, strLine
         END IF
         INCR idx
      LOOP
      strIndex = "Active File"
      AfxIniFileWrite m_szIniFileName, "File set", strIndex, strCurPath
   END METHOD
'   ' =====================================================================================

   ' =====================================================================================
   ' Note: This one allows to save the caret position.
   ' =====================================================================================
'   METHOD SaveFileSet
'      LOCAL i AS LONG
'      LOCAL idx AS LONG
'      LOCAL nCount AS LONG
'      LOCAL strIndex AS STRING
'      LOCAL strPath AS STRING
'      LOCAL hwndActive AS DWORD
'      LOCAL hMdi AS DWORD
'      LOCAL caretPos AS LONG
'      LOCAL strLine AS STRING
'      LOCAL vPath AS VARIANT
'      ' // Delete the section
'      IniFileDeleteSection(m_szIniFileName, "File set")
'      ' // Get the number of child MDI windows
'      nCount = 0
'      hMdi = GetWindow(pSed.hwndClient, %GW_CHILD)
'      DO WHILE hMdi <> 0
'         hMdi = GetWindow(hMdi, %GW_HWNDNEXT)
'         INCR nCount
'      LOOP
'      IF nCount = 0 THEN EXIT METHOD
'      ' // Add the paths of the files
'      hwndActive = MdiGetActive(pSed.hwndClient)
'      idx = 1
'      FOR i = 1 TO nCount
'         hwndActive = MdiGetActive(pSed.hwndClient)
'         strPath = Window_GetText(hwndActive)
'         caretPos = SCI_GetCurrentPos(pSed.hEdit)
'         IF (INSTR(strPath, ANY ":\/") <> 0) THEN
'            strLine = FORMAT$(caretPos, "000000") & "|" & strPath
'            strIndex = "File " & FORMAT$(idx)
'            AfxIniFileWrite m_szIniFileName, "File set", strIndex, strLine
'            INCR idx
'         END IF
'         MdiNext(pSed.hwndClient, hwndActive, 0)
'      NEXT
'   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Load the saved file set
   ' =====================================================================================
   METHOD LoadFileSet
      LOCAL idx AS LONG
      LOCAL strIndex AS STRING
      LOCAL strPath AS STRING
      LOCAL caretPos AS LONG
      idx = 1
      DO
         strIndex = "File " & FORMAT$(idx)
         strPath = AfxIniFileRead(m_szIniFileName, "File set", strIndex)
         IF ISNULL(strPath) THEN EXIT DO
         caretPos = VAL(LEFT$(strPath, 6))
         strPath = MID$(strPath, 8)
         IF ISFILE(strPath) THEN
            CSED_OpenFile(strPath)
            SCI_GotoPos(pSed.hEdit, caretPos)
         END IF
         INCR idx
      LOOP
      ' // Get the path of the file that was active when saved
      strIndex = "Active File"
      strPath = AfxIniFileRead(m_szIniFileName, "File set", strIndex)
      ' // Activate the window
      CSED_TabMdiActivateWindow strPath
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' #######################################################################################

' #######################################################################################
' Class CFindReplace
' Wrapper class on top of the FindReplace Windows dialog.
' Finds and or replaces selected text.
' #######################################################################################
CLASS CFindReplace

   ' // Static data
   INSTANCE m_hFind      AS DWORD            ' // FindReplace dialog handle
   INSTANCE m_fr         AS FINDREPLACE      ' // FINDREPLACE structure
   INSTANCE m_dwFindMsg  AS DWORD            ' // Registered message handle
   INSTANCE m_startPos   AS LONG             ' // Starting position
   INSTANCE m_endPos     AS LONG             ' // Ending position
   INSTANCE m_curPos     AS LONG             ' // Current position
   INSTANCE m_findFlags  AS LONG             ' // Find flags
   INSTANCE m_UpDown     AS LONG             ' // Search direction
#IF %DEF(%UNICODE)
   INSTANCE m_szFindText AS WSTRINGZ * 256   ' // Text to search
   INSTANCE m_szReplText AS WSTRINGZ * 256   ' // Replace text
   INSTANCE m_szLastFind AS WSTRINGZ * 256   ' // Last word found
#ELSE
   INSTANCE m_szFindText AS ASCIIZ * 256     ' // Text to search
   INSTANCE m_szReplText AS ASCIIZ * 256     ' // Replace text
   INSTANCE m_szLastFind AS ASCIIZ * 256     ' // Last word found
#ENDIF

   INTERFACE IFindReplace : INHERIT IAutomation

   ' =====================================================================================
   ' Returns the handle of the FindReplace Windows dialog
   ' =====================================================================================
   PROPERTY GET hFind () AS DWORD
      PROPERTY = m_hFind
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the FINDREPLACE flags.
   ' =====================================================================================
   PROPERTY GET Flags () AS DWORD
      PROPERTY = m_fr.Flags
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Find or replace dialog
   ' wParam has the identifier in the low word
   ' // Note: FindReplace can't be used as the name of the method because it conflicts
   ' // with the FindReplace macro.
   ' =====================================================================================
   METHOD FindOrReplace (BYVAL hwnd AS DWORD, BYVAL wParam AS DWORD) AS DWORD

      LOCAL buffer AS STRING     ' // buffer

      IF pSed.hEdit = 0 THEN EXIT METHOD
      IF m_fr.lCustData = 0 THEN
         ' // Fills the search box with the selected word.
         ' // If there are carriage returns or/and line feeds, this mean that
         ' // there is a block selected, instead of a word, so avoid it.
         m_startPos = SCI_GetSelectionStart(pSed.hEdit)
         m_endPos = SCI_GetSelectionEnd(pSed.hEdit)
         buffer = SCI_GetSelText(pSed.hEdit)
         IF LEN(buffer) THEN
            IF INSTR(buffer, CHR$(13, 10)) = 0 THEN
               m_szFindText = buffer
               m_szLastFind = buffer
            END IF
         ELSE
            m_szFindText = m_szLastFind
         END IF
         ' // Register a Windows message to communicate with the dialog
         ' // Sends messages identified by m_dwFindMsg.
         m_dwFindMsg = RegisterWindowMessage("CommDlg_FindReplace")
         m_fr.lStructSize      = SIZEOF(m_fr)
         m_fr.hwndOwner        = hwnd
         m_fr.hInstance        = %NULL
         m_fr.Flags            = %FR_DOWN
         m_fr.lpstrFindWhat    = VARPTR(m_szFindText)
         m_fr.lpstrReplaceWith = VARPTR(m_szReplText)
         m_fr.wFindWhatLen     = SIZEOF(m_szFindText)
         m_fr.wReplaceWithLen  = SIZEOF(m_szReplText)
         m_fr.lCustData        = LO(WORD, wParam)
         m_fr.lpfnHook         = %NULL
         m_fr.lpTemplateName   = %NULL
         IF LO(WORD, wParam) = %IDM_FIND THEN
            m_hFind = FindText(m_fr)
         ELSE
            m_hFind = ReplaceText(m_fr)
         END IF
      ELSE
         IF LO(WORD, wParam) = %IDM_FIND THEN
            MessageBox(BYVAL hwnd, "Cancel your previous dialog", _
               "Find", %MB_OK OR %MB_ICONINFORMATION OR %MB_APPLMODAL)
         ELSE
            MessageBox(BYVAL hwnd, "Cancel your previous dialog", _
               "Replace", %MB_OK OR %MB_ICONINFORMATION OR %MB_APPLMODAL)
         END IF
      END IF
      METHOD = m_dwFindMsg

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Find next
   ' =====================================================================================
   METHOD FindNext (BYVAL hwnd AS DWORD)
      LOCAL buffer AS STRING     ' // buffer
      m_startPos = SCI_GetSelectionStart(pSed.hEdit)
      m_endPos = SCI_GetSelectionEnd(pSed.hEdit)
      buffer = SCI_GetSelText(pSed.hEdit)
      IF LEN(buffer) THEN
         IF INSTR(buffer, CHR$(13, 10)) = 0 THEN
            m_szFindText = buffer
            m_szLastFind = buffer
         END IF
      END IF
      m_UpDown = %FR_DOWN
      SendMessage hwnd, %WM_COMMAND, %IDM_FINDUPORDOWN, 0
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Find backwards
   ' =====================================================================================
   METHOD FindBackwards (BYVAL hwnd AS DWORD)
      LOCAL buffer AS STRING     ' // buffer
      m_startPos = SCI_GetSelectionStart(pSed.hEdit)
      m_endPos = SCI_GetSelectionEnd(pSed.hEdit)
      buffer = SCI_GetSelText(pSed.hEdit)
      IF LEN(buffer) THEN
         IF INSTR(buffer, CHR$(13, 10)) = 0 THEN
            m_szFindText = buffer
            m_szLastFind = buffer
         END IF
      END IF
      m_UpDown = 0
      ME.FindUpOrDown(hwnd)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Find forward or backwards
   ' =====================================================================================
   METHOD FindUpOrDown (BYVAL hwnd AS DWORD)

      LOCAL r AS LONG

      IF LEN(m_szFindText) THEN
         ' // Begin to search from the current position
         m_curPos = SCI_GetCurrentPos(pSed.hEdit)
         IF m_startPos <> m_curPos THEN
            IF m_UpDown = %FR_DOWN THEN
               m_startPos = m_curPos
            ELSE
               IF m_curPos < m_startPos THEN m_startPos = m_curPos
               IF m_startPos = 0 THEN m_startPos = m_curPos
            END IF
         END IF
      SearchAgain:                                                                                                   'UPDATED by WLB
         ' // For backward searches the end position must be less than the start position
         m_endPos = SCI_GetTextLength(pSed.hEdit)
         IF m_UpDown <> %FR_DOWN THEN
            m_endPos = 0    ' // Search backwards
            SCI_SetTargetStart(pSed.hEdit, m_startPos - 1)
         ELSE
            IF m_startPos = 0 THEN
               SCI_SetTargetStart(pSed.hEdit, m_startPos)
            ELSE
               SCI_SetTargetStart(pSed.hEdit, m_startPos + 1)
            END IF
         END IF
         ' // Set the end position and the find flags
         SCI_SetTargetEnd(pSed.hEdit, m_endPos)
         SCI_SetSearchFlags(pSed.hEdit, m_findFlags)
         ' // Search for the text to find
         r = SCI_SearchInTarget(pSed.hEdit, m_szFindText)
         IF CINT(r) = -1 THEN
            IF m_UpDown = %FR_DOWN THEN
               IF MessageBox(hwnd, "No more matches found. Continue searching from the top?", " Find Next", _
                  %MB_OK Or %MB_ICONINFORMATION Or %MB_APPLMODAL Or %MB_YESNOCANCEL Or %MB_DEFBUTTON2) = %IDYES THEN
                  m_startPos = 1
                  GOTO SearchAgain
               END IF
            ELSEIF m_UpDown = 0 THEN
               IF MessageBox(hwnd, "No more matches found. Continue searching from the bottom?", " Find Next", _
                  %MB_OK Or %MB_ICONINFORMATION Or %MB_APPLMODAL Or %MB_YESNOCANCEL OR %MB_DEFBUTTON2) = %IDYES THEN
                  m_startPos = SCI_GetTextLength(pSed.hEdit)
                  GOTO SearchAgain
               END IF
            END IF
         ELSE
            ' // Position the caret and select the text
            SCI_SetCurrentPos pSed.hEdit, r
            SCI_GotoPos pSed.hEdit, r
            SCI_SetSelectionStart pSed.hEdit, r
            SCI_SetSelectionEnd pSed.hEdit, r + LEN(m_szFindText)
            ' // Increase the position
            m_startPos = r
         END IF
      END IF

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Find and/or replace the selected text
   ' =====================================================================================
   METHOD FindReplaceText (BYVAL hwnd AS DWORD)

      LOCAL r AS LONG
      LOCAL x AS LONG
      LOCAL y AS LONG
      LOCAL numItems AS LONG
      LOCAL bInSelection AS LONG
      LOCAL startSelPos AS LONG
      LOCAL endSelPos AS LONG
      LOCAL buffer AS STRING

      LOCAL szFindTextUTF8 AS ASCIIZ * 512
      LOCAL szReplaceTextUTF8 AS ASCIIZ * 512
      STATIC PrevFlag AS LONG

      IF (m_fr.flags AND %FR_DIALOGTERM) = %FR_DIALOGTERM THEN
         IF m_szLastFind <> m_szFindText THEN m_szLastFind = m_szFindText
         m_fr.lCustData = 0   ' // Finished
      ELSE
         IF (m_fr.flags AND %FR_FINDNEXT) = %FR_FINDNEXT THEN
            ' // Find next
            ' // Get the options checked in the dialog box
            m_findFlags = 0
            IF (m_fr.Flags AND %FR_MATCHCASE) = %FR_MATCHCASE THEN m_findFlags = m_findFlags OR %SCFIND_MATCHCASE
            IF (m_fr.Flags AND %FR_WHOLEWORD) = %FR_WHOLEWORD THEN m_findFlags = m_findFlags OR %SCFIND_WHOLEWORD
            ' // If FR_DOWN = FALSE we must seach backwards
            m_UpDown = 0
            IF (m_fr.Flags AND %FR_DOWN) = %FR_DOWN THEN m_UpDown = %FR_DOWN
            ' // Begin to search from the current position
            m_curPos = SCI_GetCurrentPos(pSed.hEdit)
            IF m_startPos <> m_curPos THEN
               IF m_UpDown = %FR_DOWN THEN
                  m_startPos = m_curPos
               ELSE
                  IF m_curPos < m_startPos THEN m_startPos = m_curPos
                  IF m_startPos = 0 THEN m_startPos = m_curPos
               END IF
            END IF
            ' // For backward searches the end position must be less than the start position
            m_endPos = SCI_GetTextLength(pSed.hEdit)
            IF m_UpDown <> %FR_DOWN THEN
               m_endPos = 0    ' // Search backwards
               SCI_SetTargetStart(pSed.hEdit, m_startPos - 1)
            ELSE
               IF m_startPos = 0 THEN
                  SCI_SetTargetStart(pSed.hEdit, m_startPos)
               ELSE
                  SCI_SetTargetStart(pSed.hEdit, m_startPos + 1)
               END IF
            END IF
            ' // Set the end position and the find flags
            SCI_SetTargetEnd(pSed.hEdit, m_endPos)
            SCI_SetSearchFlags(pSed.hEdit, m_findFlags)
            ' // Search for the text to find
            IF pSed.UnicodeEnabled THEN
               szFindTextUTF8 = ChrToUtf8$(m_szFindText)
               r = SCI_SearchInTarget(pSed.hEdit, szFindTextUTF8)
            ELSE
               r = SCI_SearchInTarget(pSed.hEdit, m_szFindText)
            END IF
            IF CINT(r) = -1 THEN
               IF PrevFlag = %FR_REPLACE THEN
                  PrevFlag = 0
               ELSE
                  MessageBox(BYVAL m_hFind, "Match not found", "Find", _
                     %MB_OK OR %MB_ICONINFORMATION OR %MB_APPLMODAL)
               END IF
            ELSE
               ' // Position the caret and select the text
               SCI_SetCurrentPos(pSed.hEdit, r)
               SCI_GotoPos(pSed.hEdit, r)
               SCI_SetSelectionStart(pSed.hEdit, r)
               IF pSed.UnicodeEnabled THEN
                  SCI_SetSelectionEnd(pSed.hEdit, r + LEN(szFindTextUTF8))
               ELSE
                  SCI_SetSelectionEnd(pSed.hEdit, r + LEN(m_szFindText))
               END IF
               ' // Increase the position
               m_startPos = r
            END IF
         ELSEIF (m_fr.flags AND %FR_REPLACE) = %FR_REPLACE THEN
            m_findFlags = 0
            ' // Get the options checked in the dialog box
            IF (m_fr.Flags AND %FR_MATCHCASE) = %FR_MATCHCASE THEN m_findFlags = m_findFlags OR %SCFIND_MATCHCASE
            IF (m_fr.Flags AND %FR_WHOLEWORD) = %FR_WHOLEWORD THEN m_findFlags = m_findFlags OR %SCFIND_WHOLEWORD
            ' // Begin to search from the current position
            m_startPos = SCI_GetCurrentPos(pSed.hEdit)
            ' // End position = length of the document
            m_endPos = SCI_GetTextLength(pSed.hEdit)
            ' // See if there is text selected
            x = SCI_GetSelectionStart(pSed.hEdit)
            y = SCI_GetSelectionEnd(pSed.hEdit)
            IF y > x THEN m_startPos = x
            ' // Set the start position
            SCI_SetTargetStart(pSed.hEdit, m_startPos)
            ' // Set the end position
            SCI_SetTargetEnd(pSed.hEdit, m_endPos)
            ' // Set the search flags
            SCI_SetSearchFlags(pSed.hEdit, m_findFlags)
            ' // Search the text to replace
            IF pSed.UnicodeEnabled THEN
               szFindTextUTF8 = ChrToUtf8$(m_szFindText)
               r = SCI_SearchInTarget(pSed.hEdit, szFindTextUTF8)
            ELSE
               r = SCI_SearchInTarget(pSed.hEdit, m_szFindText)
            END IF
            IF CINT(r) = -1 THEN
               MessageBox(BYVAL m_hFind, "Match not found", "Replace", _
                  %MB_OK OR %MB_ICONINFORMATION OR %MB_APPLMODAL)
            ELSE
               ' // Position the caret and select the text
               SCI_SetCurrentPos(pSed.hEdit, r)
               SCI_GotoPos(pSed.hEdit, r)
               SCI_SetSelectionStart(pSed.hEdit, r)
               IF pSed.UnicodeEnabled THEN
                  SCI_SetSelectionEnd(pSed.hEdit, r + LEN(szFindTextUTF8))
               ELSE
                  SCI_SetSelectionEnd(pSed.hEdit, r + LEN(m_szFindText))
               END IF
               ' // Replace the selection
               IF pSed.UnicodeEnabled THEN
                  szReplaceTextUTF8 = ChrToUtf8$(m_szReplText)
                  SCI_ReplaceSel(pSed.hEdit, szReplaceTextUTF8)
               ELSE
                  SCI_ReplaceSel(pSed.hEdit, m_szReplText)
               END IF
               ' // Increase the position
               m_startPos = r
            END IF
            ' // Send a message to search for the next occurrence
            PrevFlag = %FR_REPLACE
            m_fr.Flags = m_fr.Flags OR %FR_FINDNEXT
            SendMessage hwnd, m_dwFindMsg, 0, 0
         ELSEIF (m_fr.flags AND %FR_REPLACEALL) = %FR_REPLACEALL THEN
            ' // If there is not block selection, unselect text to allow for
            ' // Replace all in the whole document
            m_startPos = SCI_GetSelectionStart(pSed.hEdit)
            m_endPos = SCI_GetSelectionEnd(pSed.hEdit)
            IF m_endPos > m_startPos THEN
               buffer = SPACE$(m_endPos - m_startPos + 1)
               buffer = SCI_GetSelText(pSed.hEdit)
               IF LEN(buffer) THEN
                  IF INSTR(buffer, CHR$(13, 10)) = 0 THEN
                     m_curPos = SCI_GetCurrentPos(pSed.hEdit)
                     SCI_SetSelectionStart(pSed.hEdit, m_curPos)
                     SCI_SetSelectionEnd(pSed.hEdit, m_curPos)
                  END IF
               END IF
            END IF
            ' // Replace all
            m_findFlags = 0
            IF (m_fr.Flags AND %FR_MATCHCASE) = %FR_MATCHCASE THEN m_findFlags = m_findFlags OR %SCFIND_MATCHCASE
            IF (m_fr.Flags AND %FR_WHOLEWORD) = %FR_WHOLEWORD THEN m_findFlags = m_findFlags OR %SCFIND_WHOLEWORD
            ' // Begin to search from the begining
            m_endPos = SCI_GetTextLength(pSed.hEdit)
            ' // Reset counter and starting position
            numItems = 0
            m_startPos = 0
            bInSelection = 0
            ' // If startSelPos and endSelPos are the same there is not selection,
            ' // otherwise made the changes only in the selected text
            startSelPos = SCI_GetSelectionStart(pSed.hEdit)
            endSelPos = SCI_GetSelectionEnd(pSed.hEdit)
            IF endSelPos > startSelPos THEN
               m_startPos = startSelPos
               m_endPos = endSelPos
               bInSelection = %TRUE
            END IF
            DO
               ' // Set the find flags and the starting and ending positions
               SCI_SetSearchFlags(pSed.hEdit, m_findFlags)
               SCI_SetTargetStart(pSed.hEdit, m_startPos)
               SCI_SetTargetEnd(pSed.hEdit, m_endPos)
               ' // Search for the text to replace
               IF pSed.UnicodeEnabled THEN
                  szFindTextUTF8 = ChrToUtf8$(m_szFindText)
                  r = SCI_SearchInTarget(pSed.hEdit, szFindTextUTF8)
               ELSE
                  r = SCI_SearchInTarget(pSed.hEdit, m_szFindText)
               END IF
               ' // Store the position
               m_curPos = r
               ' // If hr = -1 there are no more text to replace
               IF CINT(r) = -1 THEN
                  MessageBox(BYVAL m_hFind, FORMAT$(numItems) & " replacements", "Replace all", _
                     %MB_OK OR %MB_ICONINFORMATION OR %MB_APPLMODAL)
                  EXIT DO
               ELSE
                  IF pSed.UnicodeEnabled THEN
                     szReplaceTextUTF8 = ChrToUtf8$(m_szReplText)
                     ' // Replace the text
                     SCI_ReplaceTarget(pSed.hEdit, szReplaceTextUTF8)
                  ELSE
                     SCI_ReplaceTarget(pSed.hEdit, m_szReplText)
                  END IF
                  ' // Increase the counter
                  INCR numItems
               END IF
               ' // Calculate the new start position
               IF pSed.UnicodeEnabled THEN
                  m_startPos = m_curPos + LEN(szReplaceTextUTF8)
               ELSE
                  m_startPos = m_curPos + LEN(m_szReplText)
               END IF
               ' // Calculate the new end position (the length of the text may have changed)
               IF bInSelection THEN
                  m_endPos = SCI_GetSelectionEnd(pSed.hEdit)
               ELSE
                  m_endPos = SCI_GetTextLength(pSed.hEdit)
               END IF
               IF m_endPos <= m_startPos THEN
                  MessageBox(BYVAL m_hFind, FORMAT$(numItems) & " replacements", "Replace all", _
                     %MB_OK OR %MB_ICONINFORMATION OR %MB_APPLMODAL)
                  EXIT DO
               END IF
            LOOP
         END IF
      END IF

   END METHOD

   END INTERFACE

END CLASS
' #######################################################################################
