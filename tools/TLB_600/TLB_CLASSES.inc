' ########################################################################################
' TypeLib Browser
' File: TLB_CLASS.INC
' Contents: TypeLib Browser class
' Compiler: PowerBASIC for Windows 10
' Headers: Windows API Headers III
' Copyright (c) 2012-2014 José Roca. All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' TypeLib Browser class
' ########################################################################################
CLASS CTLB COMMON

   INSTANCE m_hwndMain AS DWORD                                 ' // Handle of the main window
   INSTANCE m_hToolBar AS DWORD                                 ' // Handle of the tool bar control
   INSTANCE m_hStatusBar AS DWORD                               ' // Handle of the status bar control
   INSTANCE m_hMenu AS DWORD                                    ' // Handle of the menu of the main window
   INSTANCE m_hMenuFile AS DWORD                                ' // File menu handle
   INSTANCE m_hMenuCode AS DWORD                                ' // Code menu handle
   INSTANCE m_hMenuHelp AS DWORD                                ' // Help menu handle
   INSTANCE m_hTab AS DWORD                                     ' // Tab control handle
   INSTANCE m_pTabTypeLibs AS IWindow                           ' // Tab page typelibs
   INSTANCE m_pTabCode AS IWindow                               ' // Tab page code
   INSTANCE m_pTabOptions AS IWindow                            ' // Tab page options
   INSTANCE m_hListView AS DWORD                                ' // ListView handle
   INSTANCE m_hTreeView AS DWORD                                ' // TreeView handle
   INSTANCE m_hEditPrefix AS DWORD                              ' // Prefix edit controlhandle
   INSTANCE m_hCodeView AS DWORD                                ' // Edit control handle
   INSTANCE m_hCodeViewFont AS DWORD                            ' // Edit control font handle
   INSTANCE m_PrevColSort AS LONG                               ' // Previous column sorted

   INSTANCE m_pToolbarImageListNormal24 AS IAfxImageList        ' // Toolbar normal image list handle
   INSTANCE m_pToolbarImageListDisabled24 AS IAfxImageList      ' // Toolbar disabled image list handle

'   INSTANCE m_pToolbarImageListNormal16 AS IAfxImageList        ' // Toolbar normal image list handle
'   INSTANCE m_pToolbarImageListDisabled16 AS IAfxImageList      ' // Toolbar disabled image list handle
'   INSTANCE m_hTabCtrlImageList AS DWORD                        ' // Tab control image list handle

   INSTANCE m_wszIniFileName AS WSTRINGZ * %MAX_PATH             ' // .ini file name

   ' =====================================================================================
   CLASS METHOD Create()
      ' // Do initialization
      m_wszIniFileName = EXE.PATH$ & $PROGNAME & ".ini"
      ' // Create the image lists for the toolbar
      m_pToolbarImageListNormal24 = TLB_CreateToolbarImageListNormal_24
      m_pToolbarImageListDisabled24 = TLB_CreateToolbarImageListDisabled_24
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   CLASS METHOD Destroy()
      IF m_hCodeViewFont THEN DeleteObject(m_hCodeViewFont)
      ' // Destroy the tab pages
      m_pTabTypeLibs = NOTHING
      m_pTabCode = NOTHING
      m_pTabOptions = NOTHING
      ' // Destroy the toolbars image lists
      m_pToolbarImageListNormal24 = NOTHING
      m_pToolbarImageListDisabled24 = NOTHING
   END METHOD
   ' =====================================================================================

   INTERFACE ITLB : INHERIT IAutomation

   ' =====================================================================================
   ' // Path of the .ini file
   ' =====================================================================================
   PROPERTY GET IniFileName () AS WSTRING : PROPERTY = m_wszIniFileName : END PROPERTY
   PROPERTY SET IniFileName (BYVAL bstrFileName AS WSTRING) : m_wszIniFileName = bstrFileName : END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' // Handles
   ' =====================================================================================
   PROPERTY GET hwndMain () AS DWORD : PROPERTY = m_hwndMain : END PROPERTY
   PROPERTY SET hwndMain (BYVAL hwndMain AS DWORD) : m_hwndMain = hwndMain : END PROPERTY
   PROPERTY GET hToolBar () AS DWORD : PROPERTY = m_hToolBar : END PROPERTY
   PROPERTY SET hToolBar (BYVAL hToolBar AS DWORD) : m_hToolBar = hToolBar : END PROPERTY
   PROPERTY GET hStatusBar () AS DWORD : PROPERTY = m_hStatusBar : END PROPERTY
   PROPERTY SET hStatusBar (BYVAL hStatusBar AS DWORD) : m_hStatusBar = hStatusBar : END PROPERTY
   PROPERTY GET hTab () AS DWORD : PROPERTY = m_hTab : END PROPERTY
   PROPERTY SET hTab (BYVAL hTab AS DWORD) : m_hTab = hTab : END PROPERTY
   PROPERTY GET pTabTypeLibs () AS IWindow : PROPERTY = m_pTabTypeLibs : END PROPERTY
   PROPERTY SET pTabTypeLibs (BYVAL pTabTypeLibs AS IWindow) : m_pTabTypeLibs = pTabTypeLibs : END PROPERTY
   PROPERTY GET pTabCode () AS IWindow : PROPERTY = m_pTabCode : END PROPERTY
   PROPERTY SET pTabCode (BYVAL pTabCode AS IWindow) : m_pTabCode = pTabCode : END PROPERTY
   PROPERTY GET pTabOptions () AS IWindow : PROPERTY = m_pTabOptions : END PROPERTY
   PROPERTY SET pTabOptions (BYVAL pTabOptions AS IWindow) : m_pTabOptions = pTabOptions : END PROPERTY
   PROPERTY GET hListView () AS DWORD : PROPERTY = m_hListView : END PROPERTY
   PROPERTY SET hListView (BYVAL hListView AS DWORD) : m_hListView = hListView : END PROPERTY
   PROPERTY GET hTreeView () AS DWORD : PROPERTY = m_hTreeView : END PROPERTY
   PROPERTY SET hTreeView (BYVAL hTreeView AS DWORD) : m_hTreeView = hTreeView : END PROPERTY
   PROPERTY GET hEditPrefix () AS DWORD : PROPERTY = m_hEditPrefix : END PROPERTY
   PROPERTY SET hEditPrefix (BYVAL hEditPrefix AS DWORD) : m_hEditPrefix = hEditPrefix : END PROPERTY
   PROPERTY GET hCodeView () AS DWORD : PROPERTY = m_hCodeView : END PROPERTY
   PROPERTY SET hCodeView (BYVAL hCodeView AS DWORD) : m_hCodeView = hCodeView : END PROPERTY
   PROPERTY GET hCodeViewFont () AS DWORD : PROPERTY = m_hCodeViewFont : END PROPERTY
   PROPERTY SET hCodeViewFont (BYVAL hCodeViewFont AS DWORD) : m_hCodeViewFont = hCodeViewFont : END PROPERTY
   PROPERTY GET hToolbarImageListNormal24 () AS DWORD : PROPERTY = m_pToolbarImageListNormal24.hImageList : END PROPERTY
   PROPERTY GET hToolbarImageListDisabled24 () AS DWORD : PROPERTY = m_pToolbarImageListDisabled24.hImageList : END PROPERTY
   PROPERTY GET hMenu () AS DWORD : PROPERTY = m_hMenu : END PROPERTY
   PROPERTY SET hMenu (BYVAL hMenu AS DWORD) : m_hMenu = hMenu : END PROPERTY
   PROPERTY GET hMenuFile () AS DWORD : PROPERTY = m_hMenuFile : END PROPERTY
   PROPERTY SET hMenuFile (BYVAL hMenuFile AS DWORD) : m_hMenuFile = hMenuFile : END PROPERTY
   PROPERTY GET hMenuCode () AS DWORD : PROPERTY = m_hMenuCode : END PROPERTY
   PROPERTY SET hMenuCode (BYVAL hMenuCode AS DWORD) : m_hMenuCode = hMenuCode : END PROPERTY
   PROPERTY GET hMenuHelp () AS DWORD : PROPERTY = m_hMenuHelp : END PROPERTY
   PROPERTY SET hMenuHelp (BYVAL hMenuHelp AS DWORD) : m_hMenuHelp = hMenuHelp : END PROPERTY
   PROPERTY GET PrevColSort () AS LONG : PROPERTY = m_PrevColSort : END PROPERTY
   PROPERTY SET PrevColSort (BYVAL nPrevColSort AS LONG) : m_PrevColSort = nPrevColSort : END PROPERTY
   ' =====================================================================================

   ' *** Options *************************************************************************

   ' =====================================================================================
   ' Use method and property get/set statements
   ' =====================================================================================
   PROPERTY GET UsePropGetSet () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_wszIniFileName, "Browser options", "UsePropGetSet")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET UsePropGetSet (BYVAL bUsePropGetSet AS LONG)
      IF bUsePropGetSet THEN bUsePropGetSet = %BST_CHECKED ELSE bUsePropGetSet = %BST_UNCHECKED
      AfxIniFileWrite m_wszIniFileName, "Browser options", "UsePropGetSet", FORMAT$(bUsePropGetSet)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Use method statements only
   ' =====================================================================================
   PROPERTY GET UseMethod () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_wszIniFileName, "Browser options", "UseMethod")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET UseMethod (BYVAL bUseMethod AS LONG)
      IF bUseMethod THEN bUseMethod = %BST_CHECKED ELSE bUseMethod = %BST_UNCHECKED
      AfxIniFileWrite m_wszIniFileName, "Browser options", "UseMethod", FORMAT$(bUseMethod)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Use set instead of put as prefix
   ' =====================================================================================
   PROPERTY GET UseSetPrefix () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_wszIniFileName, "Browser options", "UseSetPrefix")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET UseSetPrefix (BYVAL bUseSetPrefix AS LONG)
      IF bUseSetPrefix THEN bUseSetPrefix = %BST_CHECKED ELSE bUseSetPrefix = %BST_UNCHECKED
      AfxIniFileWrite m_wszIniFileName, "Browser options", "UseSetPrefix", FORMAT$(bUseSetPrefix)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Use parameter names in interface declarations
   ' =====================================================================================
   PROPERTY GET UseParameterNames () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_wszIniFileName, "Browser options", "UseParameterNames")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET UseParameterNames (BYVAL bUseParameterNames AS LONG)
      IF bUseParameterNames THEN bUseParameterNames = %BST_CHECKED ELSE bUseParameterNames = %BST_UNCHECKED
      AfxIniFileWrite m_wszIniFileName, "Browser options", "UseParameterNames", FORMAT$(bUseParameterNames)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Add prefix to parameter names
   ' =====================================================================================
   PROPERTY GET AddParameterNamesPrefix () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_wszIniFileName, "Browser options", "AddParameterNamesPrefix")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET AddParameterNamesPrefix (BYVAL bAddParameterNamesPrefix AS LONG)
      IF bAddParameterNamesPrefix THEN bAddParameterNamesPrefix = %BST_CHECKED ELSE bAddParameterNamesPrefix = %BST_UNCHECKED
      AfxIniFileWrite m_wszIniFileName, "Browser options", "AddParameterNamesPrefix", FORMAT$(bAddParameterNamesPrefix)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Use interface names with external objects
   ' =====================================================================================
   PROPERTY GET UseIntNamesWithExObj () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_wszIniFileName, "Browser options", "UseIntNamesWithExObj")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET UseIntNamesWithExObj (BYVAL bUseIntNamesWithExObj AS LONG)
      IF bUseIntNamesWithExObj THEN bUseIntNamesWithExObj = %BST_CHECKED ELSE bUseIntNamesWithExObj = %BST_UNCHECKED
      AfxIniFileWrite m_wszIniFileName, "Browser options", "UseIntNamesWithExObj", FORMAT$(bUseIntNamesWithExObj)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Use prefix in interface names
   ' =====================================================================================
   PROPERTY GET UsePrefix () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_wszIniFileName, "Browser options", "UsePrefix")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET UsePrefix (BYVAL bUsePrefix AS LONG)
      IF bUsePrefix THEN bUsePrefix = %BST_CHECKED ELSE bUsePrefix = %BST_UNCHECKED
      AfxIniFileWrite m_wszIniFileName, "Browser options", "UsePrefix", FORMAT$(bUsePrefix)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Use enumeration names as prefix in constants
   ' =====================================================================================
   PROPERTY GET UseEnumPrefix () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_wszIniFileName, "Browser options", "UseEnumPrefix")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET UseEnumPrefix (BYVAL bUseEnumPrefix AS LONG)
      IF bUseEnumPrefix THEN bUseEnumPrefix = %BST_CHECKED ELSE bUseEnumPrefix = %BST_UNCHECKED
      AfxIniFileWrite m_wszIniFileName, "Browser options", "UseEnumPrefix", FORMAT$(bUseEnumPrefix)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Use hexadecimal numbers in constants
   ' =====================================================================================
   PROPERTY GET UseHexNumbers () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_wszIniFileName, "Browser options", "UseHexNumbers")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET UseHexNumbers (BYVAL bUseHexNumbers AS LONG)
      IF bUseHexNumbers THEN bUseHexNumbers = %BST_CHECKED ELSE bUseHexNumbers = %BST_UNCHECKED
      AfxIniFileWrite m_wszIniFileName, "Browser options", "UseHexNumbers", FORMAT$(bUseHexNumbers)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Include dispatch only interfaces
   ' =====================================================================================
   PROPERTY GET MixDispInterfaces () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_wszIniFileName, "Browser options", "MixDispInterfaces")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET MixDispInterfaces (BYVAL bMixDispInterfaces AS LONG)
      IF bMixDispInterfaces THEN bMixDispInterfaces = %BST_CHECKED ELSE bMixDispInterfaces = %BST_UNCHECKED
      AfxIniFileWrite m_wszIniFileName, "Browser options", "MixDispInterfaces", FORMAT$(bMixDispInterfaces)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieve license key
   ' =====================================================================================
   PROPERTY GET RetrieveLicenseKey () AS LONG
      LOCAL rs AS STRING
      rs = AfxIniFileRead(m_wszIniFileName, "Browser options", "RetrieveLicenseKey")
      IF LEN(rs) THEN PROPERTY = VAL(rs) ELSE PROPERTY = %BST_UNCHECKED
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET RetrieveLicenseKey (BYVAL bRetrieveLicenseKey AS LONG)
      IF bRetrieveLicenseKey THEN bRetrieveLicenseKey = %BST_CHECKED ELSE bRetrieveLicenseKey = %BST_UNCHECKED
      AfxIniFileWrite m_wszIniFileName, "Browser options", "RetrieveLicenseKey", FORMAT$(bRetrieveLicenseKey)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Last accessed path
   ' =====================================================================================
   PROPERTY GET LastPath () AS WSTRING
      PROPERTY = AfxIniFileRead(m_wszIniFileName, "Browser paths", "LastAccessedFolder")
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET LastPath (BYVAL bstrLastPath AS WSTRING)
      AfxIniFileWrite m_wszIniFileName, "Browser paths", "LastAccessedFolder", bstrLastPath
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Column to sort
   ' =====================================================================================
   PROPERTY GET ColumnToSort () AS LONG
      PROPERTY = VAL(AfxIniFileRead(m_wszIniFileName, "Browser options", "ColumnToSort"))
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET ColumnToSort (BYVAL nCol AS LONG)
      AfxIniFileWrite m_wszIniFileName, "Browser options", "ColumnToSort", FORMAT$(nCol)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Column sort order
   ' =====================================================================================
   PROPERTY GET ColumnSortOrder () AS WSTRING
      PROPERTY = AfxIniFileRead(m_wszIniFileName, "Browser options", "SortOrder")
   END PROPERTY
   ' =====================================================================================
   PROPERTY SET ColumnSortOrder (BYVAL bstrSortOrder AS WSTRING)
      AfxIniFileWrite m_wszIniFileName, "Browser options", "SortOrder", bstrSortOrder
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
      rs = AfxIniFileRead(m_wszIniFileName, "Window placement", "Left")
      IF LEN(rs) THEN WinPla.rcNormalPosition.Left = VAL(rs)
      rs = AfxIniFileRead(m_wszIniFileName, "Window placement", "Right")
      IF LEN(rs) THEN WinPla.rcNormalPosition.Right = VAL(rs)
      IF WinPla.rcNormalPosition.Right = 0 THEN WinPla.rcNormalPosition.Right = 750
      rs = AfxIniFileRead(m_wszIniFileName, "Window placement", "Top")
      IF LEN(rs) THEN WinPla.rcNormalPosition.Top = VAL(rs)
      rs = AfxIniFileRead(m_wszIniFileName, "Window placement", "Bottom")
      IF LEN(rs) THEN WinPla.rcNormalPosition.Bottom = VAL(rs)
      IF WinPla.rcNormalPosition.Bottom = 0 THEN WinPla.rcNormalPosition.Bottom = 450
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
      AfxIniFileWrite m_wszIniFileName, "Window placement", "Left", FORMAT$(WinPla.rcNormalPosition.Left)
      AfxIniFileWrite m_wszIniFileName, "Window placement", "Right", FORMAT$(WinPla.rcNormalPosition.Right)
      AfxIniFileWrite m_wszIniFileName, "Window placement", "Top", FORMAT$(WinPla.rcNormalPosition.Top)
      AfxIniFileWrite m_wszIniFileName, "Window placement", "Bottom", FORMAT$(WinPla.rcNormalPosition.Bottom)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' ListView columns order.
   ' =====================================================================================
   METHOD SaveColumnsOrderArray
      LOCAL r, idx, nCols AS LONG, hListView AS DWORD, rs AS STRING
      hListView = ME.hListView
      nCols = ListView_GetColumnCount(hListView)
      REDIM rgLvOrderArray(nCols - 1) AS LONG
      r = ListView_GetColumnOrderArray(hListView, nCols, rgLvOrderArray(0))
      IF r = 0 THEN EXIT METHOD
      FOR idx = LBOUND(rgLvOrderArray) TO UBOUND(rgLvOrderArray)
         rs += FORMAT$(rgLvOrderArray(idx))
         IF idx < UBOUND(rgLvOrderArray) THEN rs += ","
      NEXT
      AfxIniFileWrite m_wszIniFileName, "Columns order", "ColumnsOrder", rs
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD SetColumnsOrderArray
      LOCAL idx, nCols AS LONG, hListView AS DWORD, rs AS STRING
      hListView = ME.hListView
      nCols = ListView_GetColumnCount(hListView)
      rs = AfxIniFileRead(m_wszIniFileName, "Columns order", "ColumnsOrder")
      IF LEN(rs) THEN
         REDIM rgLvOrderArray(nCols - 1) AS LONG
         FOR idx = LBOUND(rgLvOrderArray) TO UBOUND(rgLvOrderArray)
            rgLvOrderArray(idx) = VAL(PARSE$(rs, idx + 1))
         NEXT
         ListView_SetColumnOrderArray(hListView, nCols, rgLvOrderArray(0))
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' ListView columns width.
   ' =====================================================================================
   METHOD SaveColumnsWidth
      LOCAL idx, nCols AS LONG, hListView AS DWORD, rs AS STRING
      hListView = ME.hListView
      nCols = ListView_GetColumnCount(hListView)
      FOR idx = 0 TO nCols - 1
         rs += FORMAT$(ListView_GetColumnWidth(hListView, idx))
         IF idx < nCols - 1 THEN rs += ","
      NEXT
      AfxIniFileWrite m_wszIniFileName, "Columns width", "ColumnsWidth", rs
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD SetColumnsWidth
      LOCAL idx, nCols, nWidth AS LONG, hListView AS DWORD, rs AS STRING
      hListView = ME.hListView
      nCols = ListView_GetColumnCount(hListView)
      rs = AfxIniFileRead(m_wszIniFileName, "Columns width", "ColumnsWidth")
      IF LEN(rs) THEN
         FOR idx = 0 TO nCols - 1
            nWidth = VAL(PARSE$(rs, idx + 1))
            ListView_SetColumnWidth(hListView, idx, nWidth)
         NEXT
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' ListView selected item
   ' =====================================================================================
   METHOD SaveSelectedItem
      LOCAL hListView AS DWORD, nItem AS LONG
      LOCAL szSelItem AS WSTRINGZ * 260
      hListView = ME.hListView
      nItem = ListView_GetSelectionMark(hListView)
      IF nItem THEN szSelItem = ListView_GetText(ME.hListView, nItem, 0)
      AfxIniFileWrite m_wszIniFileName, "Selected Item", "SelectedItem", szSelItem
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD SetSelectedItem
      LOCAL hListView AS DWORD, nItem AS LONG
      LOCAL szSelItem AS WSTRINGZ * 260
      hListView = ME.hListView
      szSelItem = AfxIniFileRead(m_wszIniFileName, "Selected Item", "SelectedItem")
      nItem = ListView_FindString(hListView, szSelItem)
      IF nItem THEN
         ListView_SetItemState(hListView, nItem, %LVIS_SELECTED OR %LVIS_FOCUSED, %LVIS_SELECTED OR %LVIS_FOCUSED)
         ListView_EnsureVisible(hListView, nItem, %TRUE)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Read options
   ' =====================================================================================
   METHOD ReadOptions
      LOCAL hCtrl AS DWORD
      IF ISNOTHING(m_pTabOptions) THEN EXIT METHOD
      hCtrl = GetDlgItem(m_pTabOptions.hwnd, %IDC_USEMETHOD)
      IF ME.UseMethod = %BST_CHECKED THEN Button_SetCheck(hCtrl, %BST_CHECKED) ELSE Button_SetCheck(hCtrl, %BST_UNCHECKED)
      hCtrl = GetDlgItem(m_pTabOptions.hwnd, %IDC_USEPREFIX)
      IF ME.UsePrefix = %BST_CHECKED THEN Button_SetCheck(hCtrl, %BST_CHECKED) ELSE Button_SetCheck(hCtrl, %BST_UNCHECKED)
      hCtrl = GetDlgItem(m_pTabOptions.hwnd, %IDC_USEENUMPREFIX)
      IF ME.UseEnumPrefix = %BST_CHECKED THEN Button_SetCheck(hCtrl, %BST_CHECKED) ELSE Button_SetCheck(hCtrl, %BST_UNCHECKED)
      hCtrl = GetDlgItem(m_pTabOptions.hwnd, %IDC_USEHEXNUMBERS)
      IF ME.UseHexNumbers = %BST_CHECKED THEN Button_SetCheck(hCtrl, %BST_CHECKED) ELSE Button_SetCheck(hCtrl, %BST_UNCHECKED)
      hCtrl = GetDlgItem(m_pTabOptions.hwnd, %IDC_USEPROPGETSET)
      IF ME.UsePropGetSet = %BST_CHECKED THEN Button_SetCheck(hCtrl, %BST_CHECKED) ELSE Button_SetCheck(hCtrl, %BST_UNCHECKED)
      ' // Set default to m_UsePropGetSet if option not set
      IF ME.UseMethod <> %BST_CHECKED AND ME.UsePropGetSet <> %BST_CHECKED THEN
         Button_SetCheck(hCtrl, %BST_CHECKED)
         ME.UsePropGetSet = %BST_CHECKED
      END IF
      hCtrl = GetDlgItem(m_pTabOptions.hwnd, %IDC_MIXDISPINTERFACES)
      IF ME.MixDispInterfaces = %BST_CHECKED THEN Button_SetCheck(hCtrl, %BST_CHECKED) ELSE Button_SetCheck(hCtrl, %BST_UNCHECKED)
      hCtrl = GetDlgItem(m_pTabOptions.hwnd, %IDC_RETRIEVELICENSEKEY)
      IF ME.RetrieveLicenseKey = %BST_CHECKED THEN Button_SetCheck(hCtrl, %BST_CHECKED) ELSE Button_SetCheck(hCtrl, %BST_UNCHECKED)
      hCtrl = GetDlgItem(m_pTabOptions.hwnd, %IDC_USESETPREFIX)
      IF ME.UseSetPrefix = %BST_CHECKED THEN Button_SetCheck(hCtrl, %BST_CHECKED) ELSE Button_SetCheck(hCtrl, %BST_UNCHECKED)
      hCtrl = GetDlgItem(m_pTabOptions.hwnd, %IDC_USEINTNAMESWITHEXOBJ)
      IF ME.UseIntNamesWithExObj = %BST_CHECKED THEN Button_SetCheck(hCtrl, %BST_CHECKED) ELSE Button_SetCheck(hCtrl, %BST_UNCHECKED)
      hCtrl = GetDlgItem(m_pTabOptions.hwnd, %IDC_USEPRMNAMES)
      IF ME.UseParameterNames = %BST_CHECKED THEN Button_SetCheck(hCtrl, %BST_CHECKED) ELSE Button_SetCheck(hCtrl, %BST_UNCHECKED)
      ' // Set default to m_UseAddParameterNamesPrefix if required
      hCtrl = GetDlgItem(m_pTabOptions.hwnd, %IDC_ADDPRMNAMESPREFIX)
      IF ME.AddParameterNamesPrefix = %BST_CHECKED THEN Button_SetCheck(hCtrl, %BST_CHECKED) ELSE Button_SetCheck(hCtrl, %BST_UNCHECKED)
      ' // List view sorting
      m_PrevColSort = ME.ColumnToSort
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' #######################################################################################

' ########################################################################################
' Load and parse the type library
' ########################################################################################
CLASS CParseTypeLib COMMON

   INSTANCE m_pTypeLib           AS ITypeLib   ' // Reference to the ITypeLib interface

   INSTANCE m_LibName            AS WSTRING    ' // Library name
   INSTANCE m_LibPath            AS WSTRING    ' // Library path
   INSTANCE m_LibHelpString      AS WSTRING    ' // Library help string
   INSTANCE m_LibHelpContext     AS DWORD      ' // Library Help context
   INSTANCE m_LibHelpFile        AS WSTRING    ' // Library help file
   INSTANCE m_LibGuid            AS WSTRING    ' // Library GUID
   INSTANCE m_LibLcid            AS DWORD      ' // Library LCID
   INSTANCE m_LibSysKind         AS LONG       ' // Library SysKind
   INSTANCE m_LibMajorVersion    AS INTEGER    ' // Library major version
   INSTANCE m_LibMinorVersion    AS INTEGER    ' // Library minor version
   INSTANCE m_LibAttr            AS INTEGER    ' // Library attributes
   INSTANCE m_PrefixStr          AS WSTRING    ' // Prefix

   INSTANCE m_hRootNode          AS DWORD      ' // Root node
   INSTANCE m_hDocNode           AS DWORD      ' // Documentation node
   INSTANCE m_hProgIDsNode       AS DWORD      ' // ProgIDs node
   INSTANCE m_hVerIndProgIDsNode AS DWORD      ' // Version independent ProgIDs node
   INSTANCE m_hClsIDsNode        AS DWORD      ' // ClsIDs node
   INSTANCE m_hIIDsNode          AS DWORD      ' // IIDs node
   INSTANCE m_hCoClassesNode     AS DWORD      ' // CoClasses node
   INSTANCE m_hEnumsNode         AS DWORD      ' // Enums node
   INSTANCE m_hRecordsNode       AS DWORD      ' // Records node
   INSTANCE m_hUnionsNode        AS DWORD      ' // Unions node
   INSTANCE m_hTypeDefsNode      AS DWORD      ' // TypeDefs node
   INSTANCE m_hAliasesNode       AS DWORD      ' // Aliases node
   INSTANCE m_hModulesNode       AS DWORD      ' // Modules node
   INSTANCE m_hIntNode           AS DWORD      ' // Interfaces node
   INSTANCE m_hOleAutIntNode     AS DWORD      ' // Ole automation interfaces node
   INSTANCE m_hDualIntNode       AS DWORD      ' // Dual interfaces node
   INSTANCE m_hDispIntNode       AS DWORD      ' // Dispatch interfaces node
   INSTANCE m_hDispblIntNode     AS DWORD      ' // Dispatchable interfaces node
   INSTANCE m_hEventsNode        AS DWORD      ' // Events node

   ' #####################################################################################
   INTERFACE IParseTypeLib : INHERIT IAutomation
   ' #####################################################################################

   ' =====================================================================================
   ' Documentation
   ' =====================================================================================
   PROPERTY GET LibName AS WSTRING       : PROPERTY = m_LibName         : END PROPERTY
   PROPERTY GET LibPath AS WSTRING       : PROPERTY = m_LibPath         : END PROPERTY
   PROPERTY GET LibHelpString AS WSTRING : PROPERTY = m_LibHelpString   : END PROPERTY
   PROPERTY GET LibHelpContext AS DWORD  : PROPERTY = m_LibHelpContext  : END PROPERTY
   PROPERTY GET LibHelpFile AS WSTRING   : PROPERTY = m_LibHelpFile     : END PROPERTY
   PROPERTY GET LibGuid AS WSTRING       : PROPERTY = m_LibGuid         : END PROPERTY
   PROPERTY GET LibLcid AS DWORD         : PROPERTY = m_LibLcid         : END PROPERTY
   PROPERTY GET LibSysKind AS LONG       : PROPERTY = m_LibSysKind      : END PROPERTY
   PROPERTY GET LibMajorVersion AS LONG  : PROPERTY = m_LibMajorVersion : END PROPERTY
   PROPERTY GET LibMinorVersion AS LONG  : PROPERTY = m_LibMinorVersion : END PROPERTY
   PROPERTY GET LibAttr AS LONG          : PROPERTY = m_LibAttr         : END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Handle nodes
   ' =====================================================================================
   PROPERTY GET hRootNode AS DWORD          : PROPERTY = m_hRootNode          : END PROPERTY
   PROPERTY GET hDocNode AS DWORD           : PROPERTY = m_hDocNode           : END PROPERTY
   PROPERTY GET hProgIDsNode AS DWORD       : PROPERTY = m_hProgIDsNode       : END PROPERTY
   PROPERTY GET hVerIndProgIDsNode AS DWORD : PROPERTY = m_hVerIndProgIDsNode : END PROPERTY
   PROPERTY GET hClsIDsNode AS DWORD        : PROPERTY = m_hClsIDsNode        : END PROPERTY
   PROPERTY GET hIIDsNode AS DWORD          : PROPERTY = m_hIIDsNode          : END PROPERTY
   PROPERTY GET hCoClassesNode AS DWORD     : PROPERTY = m_hCoClassesNode     : END PROPERTY
   PROPERTY GET hEnumsNode AS DWORD         : PROPERTY = m_hEnumsNode         : END PROPERTY
   PROPERTY GET hRecordsNode AS DWORD       : PROPERTY = m_hRecordsNode       : END PROPERTY
   PROPERTY GET hUnionsNode AS DWORD        : PROPERTY = m_hUnionsNode        : END PROPERTY
   PROPERTY GET hTypeDefsNode AS DWORD      : PROPERTY = m_hTypeDefsNode      : END PROPERTY
   PROPERTY GET hAliasesNode AS DWORD       : PROPERTY = m_hAliasesNode       : END PROPERTY
   PROPERTY GET hModulesNode AS DWORD       : PROPERTY = m_hModulesNode       : END PROPERTY
   PROPERTY GET hIntNode AS DWORD           : PROPERTY = m_hIntNode           : END PROPERTY
   PROPERTY GET hOleAutIntNode AS DWORD     : PROPERTY = m_hOleAutIntNode     : END PROPERTY
   PROPERTY GET hDualIntNode AS DWORD       : PROPERTY = m_hDualIntNode       : END PROPERTY
   PROPERTY GET hDispIntNode AS DWORD       : PROPERTY = m_hDispIntNode       : END PROPERTY
   PROPERTY GET hDispblIntNode AS DWORD     : PROPERTY = m_hDispblIntNode     : END PROPERTY
   PROPERTY GET hEventsNode AS DWORD        : PROPERTY = m_hEventsNode        : END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Load the type library
   ' =====================================================================================
   METHOD LoadTypeLibEx (BYVAL bstrPath AS WSTRING) AS LONG

      LOCAL hr AS LONG
      LOCAL hTreeView AS DWORD

      hr = LoadTypeLibEx(BYCOPY bstrPath, %REGKIND_NONE, m_pTypeLib)
      IF hr <> %S_OK OR ISFALSE ISOBJECT(m_pTypeLib) THEN
         TLB_MsgBox pTLB.hwndMain, "Error &H" & HEX$(hr, 8) & " loading " & bstrPath, _
            %MB_OK OR %MB_ICONERROR OR %MB_APPLMODAL, "CParseTypeLib.LoadTypeLibEx"
         METHOD = hr
         EXIT METHOD
      END IF
      m_LibPath = bstrPath

      ' // Gets the documentation
      hr = m_pTypeLib.GetDocumentation(-1, m_LibName, m_LibHelpString, m_LibHelpContext, m_LibHelpFile)
      IF hr <> %S_OK THEN
         TLB_MsgBox pTLB.hwndMain, "Error &H" & HEX$(hr, 8) & " retrieving the documentation", _
            %MB_OK OR %MB_ICONERROR OR %MB_APPLMODAL, "CParseTypeLib.LoadTypeLibEx"
         METHOD = hr
         EXIT METHOD
      END IF
      ' // Use the library name as a prefix
      m_PrefixStr = REMOVE$(m_LibName, $SPC)
      m_PrefixStr = REMOVE$(m_PrefixStr, $DQ)
      SetWindowText pTLB.hEditPrefix, BYCOPY m_PrefixStr

      ' // Gets the attributes of the library
      LOCAL pLibAttr AS TLIBATTR PTR
      hr = m_pTypeLib.GetLibAttr(pLibAttr)
      IF hr <> %S_OK OR pLibAttr = %NULL THEN
         TLB_MsgBox pTLB.hwndMain, "Error &H" & HEX$(hr, 8) & " retrieving the attributes", _
            %MB_OK OR %MB_ICONERROR OR %MB_APPLMODAL, "CParseTypeLib.LoadTypeLibEx"
         METHOD = hr
         EXIT METHOD
      END IF
      m_LibGuid = GUIDTXT$(@pLibAttr.guid)
      m_LibLcid = @pLibAttr.lcid
      m_LibSysKind = @pLibAttr.syskind
      m_LibMajorVersion = @pLibAttr.wMajorVerNum
      m_LibMinorVersion = @pLibAttr.wMinorVerNum
      m_LibAttr = @pLibAttr.wLibFlags
      m_pTypeLib.ReleaseTLibAttr(pLibAttr)

      ' // Treeview handle
      hTreeView = pTLB.hTreeView
      ' // Delete all the items in the tree view
      TreeView_DeleteAllItems hTreeView
      ' // Create the nodes
      m_hRootNode = TreeView_AddItem(hTreeView, 0, %TVI_ROOT, 0, 0, m_LibName)
      m_hDocNode = TreeView_AddItem(hTreeView, m_hRootNode, 0, 0, 0, "Documentation")
      m_hProgIDsNode = TreeView_AddItem(hTreeView, m_hRootNode, 0, 0, 0, "ProgIDs (Program identifiers)")
      m_hVerIndProgIDsNode = TreeView_AddItem(hTreeView, m_hRootNode, 0, 0, 0, "Version independent ProgIDs")
      m_hClsIDsNode = TreeView_AddItem(hTreeView, m_hRootNode, 0, 0, 0, "ClsIDs (Class identifiers)")
      m_hIIDsNode = TreeView_AddItem(hTreeView, m_hRootNode, 0, 0, 0, "IIDs (Interface identifiers)")
      m_hCoClassesNode = TreeView_AddItem(hTreeView, m_hRootNode, 0, 0, 0, "CoClasses")
      m_hTypeDefsNode = TreeView_AddItem(hTreeView, m_hRootNode, 0, 0, 0, "Typedefs")
      m_hAliasesNode = TreeView_AddItem(hTreeView, m_hRootNode, 0, 0, 0, "Aliases")
      m_hEnumsNode = TreeView_AddItem(hTreeView, m_hRootNode, 0, 0, 0, "Enumerations")
      m_hRecordsNode = TreeView_AddItem(hTreeView, m_hRootNode, 0, 0, 0, "Structures")
      m_hUnionsNode = TreeView_AddItem(hTreeView, m_hRootNode, 0, 0, 0, "Unions")
      m_hModulesNode = TreeView_AddItem(hTreeView, m_hRootNode, 0, 0, 0, "Modules")
      m_hIntNode = TreeView_AddItem(hTreeView, m_hRootNode, 0, 0, 0, "Interfaces")
      m_hOleAutIntNode = TreeView_AddItem(hTreeView, m_hRootNode, 0, 0, 0, "Ole automation interfaces")
      m_hDualIntNode = TreeView_AddItem(hTreeView, m_hRootNode, 0, 0, 0, "Dual interfaces")
      m_hDispIntNode = TreeView_AddItem(hTreeView, m_hRootNode, 0, 0, 0, "Dispatch interfaces")
      m_hDispblIntNode = TreeView_AddItem(hTreeView, m_hRootNode, 0, 0, 0, "Dispatchable interfaces")
      m_hEventsNode = TreeView_AddItem(hTreeView, m_hRootNode, 0, 0, 0, "Events interfaces")
      ' // Fill the documentation node
      IF m_hDocNode THEN
         IF LEN(m_LibHelpString) THEN TreeView_AddItem hTreeView, m_hDocNode, 0, 0, 0, "Help string = " & m_LibHelpString
         TreeView_AddItem hTreeView, m_hDocNode, 0, 0, 0, "GUID = " & m_LibGuid
         TreeView_AddItem hTreeView, m_hDocNode, 0, 0, 0, "LCID = " & FORMAT$(m_LibLcid)
         TreeView_AddItem hTreeView, m_hDocNode, 0, 0, 0, "Major version = " & FORMAT$(m_LibMajorVersion)
         TreeView_AddItem hTreeView, m_hDocNode, 0, 0, 0, "Minor version = " & FORMAT$(m_LibMinorVersion)
         TreeView_AddItem hTreeView, m_hDocNode, 0, 0, 0, "Path = " & m_LibPath
         IF m_LibHelpContext THEN TreeView_AddItem hTreeView, m_hDocNode, 0, 0, 0, "Help context = " & FORMAT$(m_LibHelpContext)
         IF LEN(m_LibHelpFile) THEN TreeView_AddItem hTreeView, m_hDocNode, 0, 0, 0, "Help file = " & m_LibHelpFile
         TreeView_AddItem hTreeView, m_hDocNode, 0, 0, 0, "Attributes = " & FORMAT$(m_LibAttr) & " [&H" & HEX$(m_LibAttr, 8) & "] " & TLB_LibFlagsToStr(m_LibAttr)
         SELECT CASE AS LONG m_LibSysKind
            CASE %SYS_WIN16 : TreeView_AddItem hTreeView, m_hDocNode, 0, 0, 0, "Target OS = " & FORMAT$(m_LibSysKind) & " (Win16)"
            CASE %SYS_WIN32 : TreeView_AddItem hTreeView, m_hDocNode, 0, 0, 0, "Target OS = " & FORMAT$(m_LibSysKind) & " (Win32)"
            CASE %SYS_MAC   : TreeView_AddItem hTreeView, m_hDocNode, 0, 0, 0, "Target OS = " & FORMAT$(m_LibSysKind) & " (MAC)"
            CASE %SYS_WIN64 : TreeView_AddItem hTreeView, m_hDocNode, 0, 0, 0, "Target OS = " & FORMAT$(m_LibSysKind) & " (Win64)"
         END SELECT
      END IF

      ' // Parse the type infos
      ME.ParseTypeInfos

      ' // Expands the root node
      TreeView_Expand hTreeView, m_hRootNode, %TVE_EXPAND

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves information about constants
   ' =====================================================================================
   METHOD GetConstants (BYVAL pTypeInfo AS ITypeInfo, BYVAL pTypeAttr AS TYPEATTR PTR, BYVAL hTreeView AS DWORD, BYVAL hSubNode AS DWORD)

      LOCAL x AS LONG                           ' // Loop counter
      LOCAL hr AS LONG                          ' // HRESULT
      LOCAL pVarDesc AS VARDESC PTR             ' // Pointer to a VARDESC structure
      LOCAL ptdesc AS TYPEDESC PTR              ' // Pointer to a TYPEDESC structure
      LOCAL bstrName AS WSTRING                 ' // Name
      LOCAL vtPtr AS tagVARIANT PTR             ' // Pointer to a tagVARIANT structure
      LOCAL bstrTypeKind AS WSTRING             ' // Type kind
      LOCAL bstrValue AS WSTRING                ' // Value
      LOCAL bstrLen AS LONG                     ' // Length of the unicode string
      LOCAL wstrLen AS LONG                     ' // Length of the null-terminated unicode string
      LOCAL hSubNode2 AS DWORD                  ' // Sub node handle

      FOR x = 0 TO @pTypeAttr.cVars - 1
         hr = pTypeInfo.GetVarDesc(x, pVarDesc)
         IF hr <> %S_OK OR pVarDesc = %NULL THEN EXIT FOR
         pTypeInfo.GetDocumentation(@pVarDesc.memid, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
         ' // Some components use spaces in the names of enumeration members!
         REPLACE " " WITH "_" IN bstrName
         ' // Pointer to the variant that stores the value of the constant
         vtPtr = @pVarDesc.lpvarvalue
         ' // Gets the value of the constant
         bstrTypeKind = ""
         SELECT CASE @pVarDesc.elemdescVar.tdesc.vt
            CASE %VT_BSTR
               bstrLen = SysStringByteLen(BYVAL @vtPtr.bstrVal)
               IF bstrLen THEN bstrValue = $DQ & ACODE$(PEEK$(@vtPtr.bstrVal, bstrLen)) & $DQ ELSE bstrValue = $DQ & $DQ
               bstrTypeKind = TLB_VarTypeToConstant(@pVarDesc.elemdescVar.tdesc.vt)
            CASE %VT_LPSTR
               ' // Note: bstrVal is used because the correct name, pszVal, isn't defined in the variant structure
               wstrlen = lstrlenW(BYVAL @vtPtr.bstrVal)
               IF wstrlen THEN bstrValue = $DQ & ACODE$(PEEK$(@vtPtr.bstrVal, wstrlen * 2)) & $DQ ELSE bstrValue = $DQ & $DQ
               bstrTypeKind = TLB_VarTypeToConstant(@pVarDesc.elemdescVar.tdesc.vt)
            CASE %VT_LPWSTR
               ' // Note: bstrVal is used because the correct name, pwszVal, isn't defined in the variant structure
               wstrlen = lstrlenW(BYVAL @vtPtr.bstrVal)
               IF wstrlen THEN bstrValue = $DQ & ACODE$(PEEK$(@vtPtr.bstrVal, wstrlen * 2)) & $DQ & "$$" ELSE bstrValue = $DQ & $DQ
               bstrTypeKind = TLB_VarTypeToConstant(@pVarDesc.elemdescVar.tdesc.vt)
            CASE %VT_I1, %VT_UI1
               IF pTLB.UseHexNumbers THEN bstrValue = "&H" & HEX$(@vtPtr.bVal, 8) & "?" ELSE bstrValue = FORMAT$(@vtPtr.bVal)
               bstrTypeKind = TLB_VarTypeToConstant(@pVarDesc.elemdescVar.tdesc.vt)
            CASE %VT_BOOL
               IF pTLB.UseHexNumbers THEN bstrValue = "&H" & HEX$(@vtPtr.boolVal, 8) & "&" ELSE bstrValue = FORMAT$(@vtPtr.boolVal)
               bstrTypeKind = TLB_VarTypeToConstant(@pVarDesc.elemdescVar.tdesc.vt)
            CASE %VT_I2
               IF pTLB.UseHexNumbers THEN bstrValue = "&H" & HEX$(@vtPtr.iVal, 8) & "%" ELSE bstrValue = FORMAT$(@vtPtr.iVal)
               bstrTypeKind = TLB_VarTypeToConstant(@pVarDesc.elemdescVar.tdesc.vt)
            CASE %VT_INT
               IF m_LibSysKind = %SYS_WIN16 THEN
                  IF pTLB.UseHexNumbers THEN bstrValue = "&H" & HEX$(@vtPtr.iVal, 8) & "%" ELSE bstrValue = FORMAT$(@vtPtr.iVal)
               ELSE
                  IF pTLB.UseHexNumbers THEN bstrValue = "&H" & HEX$(@vtPtr.lVal, 8) & "&" ELSE bstrValue = FORMAT$(@vtPtr.lVal)
               END IF
               bstrTypeKind = TLB_VarTypeToConstant(@pVarDesc.elemdescVar.tdesc.vt)
            CASE %VT_I4
               IF pTLB.UseHexNumbers THEN bstrValue = "&H" & HEX$(@vtPtr.lVal, 8) & "&" ELSE bstrValue = FORMAT$(@vtPtr.lVal)
               bstrTypeKind = TLB_VarTypeToConstant(@pVarDesc.elemdescVar.tdesc.vt)
            CASE %VT_UI2
               IF pTLB.UseHexNumbers THEN bstrValue = "&H" & HEX$(@vtPtr.lVal, 8) & "??" ELSE bstrValue = FORMAT$(@vtPtr.lVal)
               bstrTypeKind = TLB_VarTypeToConstant(@pVarDesc.elemdescVar.tdesc.vt)
            CASE %VT_UINT
               IF pTLB.UseHexNumbers THEN bstrValue = "&H" & HEX$(@vtPtr.lVal, 8) & "???" ELSE bstrValue = FORMAT$(@vtPtr.lVal)
               bstrTypeKind = TLB_VarTypeToConstant(@pVarDesc.elemdescVar.tdesc.vt)
            CASE %VT_R4
               bstrValue = FORMAT$(@vtPtr.fltVal, "0.000000E+##")
               bstrTypeKind = TLB_VarTypeToConstant(@pVarDesc.elemdescVar.tdesc.vt)
            CASE %VT_R8
               bstrValue = FORMAT$(@vtPtr.dblVal, "0.000000000000E+##")
               bstrTypeKind = TLB_VarTypeToConstant(@pVarDesc.elemdescVar.tdesc.vt)
            CASE %VT_PTR
               bstrTypeKind = TLB_VarTypeToConstant(@pVarDesc.elemdescVar.tdesc.vt)
               ptdesc = @pVarDesc.elemdescVar.tdesc.lptdesc
               IF ptdesc THEN
                  ' WORD PTR (null terminated unicode string)
                  ' hxds.dll contains a module with these kind of constants.
                  IF @ptdesc.vt = %VT_UI2 THEN
                     wstrlen = lstrlenW(BYVAL @vtPtr.bstrVal)
                     IF wstrlen THEN bstrValue = $DQ & ACODE$(PEEK$(@vtPtr.bstrVal, wstrlen * 2)) & $DQ ELSE bstrValue = $DQ & $DQ
                  END IF
                  bstrTypeKind += " | " & TLB_VarTypeToConstant(@ptdesc.vt)
               END IF
               ' // Other types can be VT_CARRAY and VT_USERDEFINED, but don't have a typelib to test
         END SELECT
         hSubNode2 = TreeView_AddItem(hTreeView, hSubNode, 0, 0, 0, bstrName & " = " & bstrValue)
         TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "TYPE = " & bstrTypeKind)
         TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "VALUE = " & bstrValue)
         TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "ID = " & FORMAT$(@pVarDesc.memid))
         TreeView_Expand hTreeView, hSubNode, %TVE_EXPAND
         pTypeInfo.ReleaseVarDesc(pVarDesc)
         pVarDesc = 0
      NEXT
      IF pVarDesc THEN pTypeInfo.ReleaseVarDesc(pVarDesc)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves information about the members of records and unions, and of datamembers.
   ' =====================================================================================
   METHOD GetMembers (BYVAL pTypeInfo AS ITypeInfo, BYVAL pTypeAttr AS TYPEATTR PTR, BYVAL hTreeView AS DWORD, BYVAL hSubNode AS DWORD, OPTIONAL BYVAL bIsRecord AS LONG)

      LOCAL x AS LONG                           ' // Loop counter
      LOCAL y AS LONG                           ' // Loop counter
      LOCAL hr AS LONG                          ' // HRESULT
      LOCAL pVarDesc AS VARDESC PTR             ' // Pointer to a VARDESC structure
      LOCAL bstrVarName AS WSTRING              ' // Variable name
      LOCAL bstrVarType AS WSTRING              ' // Variable type
      LOCAL bstrTypeKind AS WSTRING             ' // Type kind
      LOCAL bstrPBKeyWord AS WSTRING            ' // PB keyword
      LOCAL bstrPBSyntax AS WSTRING             ' // PB syntax
      LOCAL wIndirectionLevel AS WORD           ' // Indirection level
      LOCAL pRefTypeInfo AS ITypeInfo           ' // Referenced TypeInfo interface
      LOCAL pVarTypeAttr AS TYPEATTR PTR        ' // Type attribute for the member
      LOCAL ptdesc AS TYPEDESC PTR              ' // Pointer to a TYPEDESC structure
      LOCAL padesc AS ARRAYDESC PTR             ' // Pointer to an ARRAYDESC structure
      LOCAL hSubNode2 AS DWORD                  ' // Sub node handle
      LOCAL hSubNode3 AS DWORD                  ' // Sub node handle

      FOR x = 0 TO @pTypeAttr.cVars - 1

         bstrVarType = "" : bstrTypeKind = "" : bstrPBKeyword = ""

         ' // Gets a reference to the VarDesc structure
         hr = pTypeInfo.GetVarDesc(x, pVarDesc)
         IF hr <> %S_OK OR pVarDesc = %NULL THEN EXIT FOR

         ' // Retrieve information
         pTypeInfo.GetDocumentation(@pVarDesc.memid, bstrVarName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
         hSubNode2 = TreeView_AddItem(hTreeView, hSubNode, 0, 0, 0, bstrVarName)
         TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "DispID = " & FORMAT$(@pVarDesc.memid) & " [&H" & HEX$(@pVarDesc.memid, 8) & "]")
         IF @pVarDesc.wVarFlags THEN TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "Attributes = " & FORMAT$(@pVarDesc.wVarFlags) & " [&H" & HEX$(@pVarDesc.wVarFlags, 8) & "]" & TLB_VarFlagsToStr(@pVarDesc.wVarFlags))
         wIndirectionLevel = 0
         IF @pVarDesc.elemdescVar.tdesc.vt = %VT_USERDEFINED THEN
            ' // If it is a user defined type, retrieve its name
            hr = pTypeInfo.GetRefTypeInfo(@pVarDesc.elemdescVar.tdesc.hreftype, pRefTypeInfo)
            IF hr = %S_OK AND ISOBJECT(pRefTypeInfo) THEN
               hr = pRefTypeInfo.GetDocumentation(-1, bstrVarType, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
               hr = pRefTypeInfo.GetTypeAttr(pVarTypeAttr)
               IF hr = %S_OK AND pVarTypeAttr <> %NULL THEN
                  IF @pVarTypeAttr.typekind = %TKIND_ALIAS THEN
                     bstrTypeKind = TLB_TypeKindToStr(@pVarTypeAttr.typekind) & " | " & TLB_VarTypeToConstant(@pVarTypeAttr.tdescalias.vt)
                  ELSE
                     bstrTypeKind = TLB_TypeKindToStr(@pVarTypeAttr.typekind)
                  END IF
                  TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "TypeKind = " & bstrTypeKind)
                  pRefTypeInfo.ReleaseTypeAttr(pVarTypeAttr)
                  pVarTypeAttr = 0
               END IF
               pRefTypeInfo = NOTHING
            END IF
         ELSEIF @pVarDesc.elemdescVar.tdesc.vt = %VT_PTR THEN
            wIndirectionLevel = 1
            ptdesc = @pVarDesc.elemdescVar.tdesc.lptdesc
            DO
               SELECT CASE @ptdesc.vt
                  ' // If it is another pointer, loop again
                  CASE %VT_PTR
                     INCR wIndirectionLevel
                     ptdesc = @ptdesc.lptdesc
                  CASE %VT_USERDEFINED
                     hr = pTypeInfo.GetRefTypeInfo(@ptdesc.hreftype, pRefTypeInfo)
                     IF hr = %S_OK AND ISOBJECT(pRefTypeInfo) THEN
                        hr = pRefTypeInfo.GetDocumentation(-1, bstrVarType, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
                        IF hr = %S_OK THEN
                           pRefTypeInfo.GetTypeAttr(pVarTypeAttr)
                           IF hr = %S_OK AND pVarTypeAttr <> %NULL THEN
                              IF @pVarTypeAttr.typekind = %TKIND_ALIAS THEN
                                 bstrTypeKind = TLB_TypeKindToStr(@pVarTypeAttr.typekind) & " | " & TLB_VarTypeToConstant(@pVarTypeAttr.tdescalias.vt)
                              ELSE
                                 bstrTypeKind = TLB_TypeKindToStr(@pVarTypeAttr.typekind)
                              END IF
                              TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "TypeKind = " & bstrTypeKind)
                              pRefTypeInfo.ReleaseTypeAttr(pVarTypeAttr)
                              pVarTypeAttr = 0
                           END IF
                        END IF
                        pRefTypeInfo = NOTHING
                        EXIT DO
                     END IF
                  CASE ELSE
                     ' // Get the equivalent type
                     bstrVarType = TLB_VarTypeToConstant(@ptdesc.vt)
                     bstrPBKeyword = TLB_VarTypeToKeyword(@ptdesc.vt)
                     EXIT DO
               END SELECT
            LOOP
         ELSE
            ' // Get the equivalent type
            bstrVarType = TLB_VarTypeToConstant(@pVarDesc.elemdescVar.tdesc.vt)
            bstrPBKeyword = TLB_VarTypeToKeyword(@pVarDesc.elemdescVar.tdesc.vt)
         END IF

         IF ISFALSE bIsRecord THEN
            TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "VarType = " & bstrVarType)
         ELSE   ' // Records and unions only
            TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "Indirection level = " & FORMAT$(wIndirectionLevel))
'           ' // Add a prefix to structures that begin with an underscore
'            IF LEFT$(bstrVarType, 1) = "_" THEN
'               IF bstrTypeKind = "TKIND_RECORD" OR bstrTypeKind = "TKIND_UNION" THEN bstrVarType = "tag" & bstrVarType
'            END IF
            ' // END isn't allowed as a member name
            IF UCASE$(bstrVarName) = "END" THEN bstrVarName += "_"
            ' // Use generic data types for enums and interfaces
            IF bstrPBKeyword = "" THEN bstrPBKeyword = bstrVarType
            ' // Add a prefix to structures that begin with an underscore
            IF LEFT$(bstrPBKeyword, 1) = "_" THEN
               IF bstrTypeKind = "TKIND_RECORD" OR bstrTypeKind = "TKIND_UNION" THEN bstrPBKeyword = "tag" & bstrPBKeyword
            END IF
            IF wIndirectionLevel > 0 THEN bstrPBKeyword += " PTR"
            IF bstrTypeKind = "TKIND_ALIAS | VT_PTR" THEN bstrPBKeyword = "DWORD"
            IF bstrTypeKind = "TKIND_ENUM" THEN bstrPBKeyword = "LONG"
            IF bstrTypeKind = "TKIND_UNKNOWN" THEN bstrPBKeyword = "DWORD"    ' IUnknown
            IF bstrTypeKind = "TKIND_DISPATCH" THEN bstrPBKeyword = "DWORD"   ' IDispatch
            IF @pVarDesc.elemdescVar.tdesc.vt = %VT_CARRAY THEN
               padesc = @pVarDesc.elemdescVar.tdesc.lpadesc
               bstrVarType += " | " & TLB_VarTypeToConstant(@padesc.tdescElem.vt)
               IF @padesc.tdescElem.vt = %VT_I1 OR @padesc.tdescElem.vt = %VT_UI1 THEN  ' Byte
                  bstrPBKeyword = "STRING * " & FORMAT$(@padesc.rgbounds(0).cElements)
               ELSEIF @padesc.tdescElem.vt = %VT_UI2 THEN  ' Word (Unicode string)
                  bstrPBKeyword = "WSTRING * " & FORMAT$(@padesc.rgbounds(0).cElements)
               ELSE
                  bstrVarName += " ("
                  FOR y = 0 TO @padesc.cDims - 1
                     bstrVarName += FORMAT$(@padesc.rgbounds(y).lLBound) & " TO "
                     bstrVarName += FORMAT$(@padesc.rgbounds(y).lLBound + @padesc.rgbounds(y).cElements - 1)
                     IF @padesc.cDims > 1 THEN bstrVarName += ", "
                  NEXT
                  bstrVarName += ")"
                  bstrPBKeyword = TLB_VarTypeToKeyword(@padesc.tdescElem.vt)
               END IF
               bstrVarName = REMOVE$(bstrVarName, "0 TO ")
            END IF
            TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "VarType = " & bstrVarType)
            IF @pVarDesc.elemdescVar.tdesc.vt = %VT_CARRAY THEN
               padesc = @pVarDesc.elemdescVar.tdesc.lpadesc
               hSubNode3 = TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "Dimensions = " & FORMAT$(@padesc.cDims))
               FOR y = 0 TO @padesc.cDims - 1
                  TreeView_AddItem(hTreeView, hSubNode3, 0, 0, 0, "Dimension " & FORMAT$(y + 1) & " lower bound = " & FORMAT$(@padesc.rgbounds(y).lLBound))
                  TreeView_AddItem(hTreeView, hSubNode3, 0, 0, 0, "Dimension " & FORMAT$(y + 1) & " elements = " & FORMAT$(@padesc.rgbounds(y).cElements))
               NEXT
               TreeView_Expand hTreeView, hSubNode3, %TVE_EXPAND
            END IF
            ' // PB syntax
            SELECT CASE bstrVarType
               CASE "VT_LPSTR"
                  bstrPBSyntax = bstrVarName & " AS ASCIIZ PTR"
               CASE "VT_LPWSTR"
                  bstrPBSyntax = bstrVarName & " AS WSTRINGZ PTR"
               CASE ELSE
                  bstrPBSyntax = bstrVarName & " AS " & bstrPBKeyword
            END SELECT
            TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "PB syntax = " & bstrPBSyntax)
         END IF

         ' // Expand the nodes
'         TreeView_Expand hTreeView, hSubNode2, %TVE_EXPAND
         TreeView_Expand hTreeView, hSubNode, %TVE_EXPAND
         ' // Release the VARDESC structure
         pTypeInfo.ReleaseVarDesc(pVarDesc)
         pVarDesc = 0

      NEXT

      IF pVarDesc THEN pTypeInfo.ReleaseVarDesc(pVarDesc)

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieve information about the parameters
   ' =====================================================================================
   METHOD GetParameters (BYVAL pTypeInfo AS ITypeInfo, BYVAL pFuncDesc AS FUNCDESC PTR, BYVAL hTreeView AS DWORD, BYVAL hSubNode2 AS DWORD)

      LOCAL y AS LONG                           ' // Loop counter
      LOCAL hr AS LONG                          ' // HRESULT
      LOCAL hParamsNode AS DWORD                ' // Parameters node
      LOCAL hParamNameNode AS DWORD             ' // Parameter name node
      LOCAL cNames AS DWORD                     ' // Number of names returned by ITypeInfo.GetNames
      LOCAL pParam AS ELEMDESC PTR              ' // Pointer to an array of parameters
      LOCAL wFlags AS WORD                      ' // Parameter flags
      LOCAL bstrParamName AS WSTRING            ' // Parameter name
      LOCAL pParamTypeAttr AS TYPEATTR PTR      ' // Referenced TYPEATTR structure
      LOCAL pReturnTypeAttr AS TYPEATTR PTR     ' // Referenced TYPEATTR structure
      LOCAL bstrVarType AS WSTRING              ' // Variable type
      LOCAL bstrTypeKind AS WSTRING             ' // Type kind
      LOCAL bstrPBKeyWord AS WSTRING            ' // PB keyword
      LOCAL bstrPBSyntax AS WSTRING             ' // PB syntax
      LOCAL wIndirectionLevel AS WORD           ' // Indirection level
      LOCAL pRefTypeInfo AS ITypeInfo           ' // Referenced TypeInfo interface
      LOCAL ptdesc AS TYPEDESC PTR              ' // Pointer to a TYPEDESC structure

      hParamsNode = TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "Number of parameters = " & FORMAT$(@pFuncDesc.cParams))
      ' ----------------------------------------------------------------------------------
      ' Gets the name of all the parameters.
      ' The first one is the name of the function.
      ' If the member ID identifies a property that is implemented with property functions,
      ' the property name is returned. For property get functions, the names of the function
      ' and its parameters are always returned.
      ' For property put and put reference functions, the right side of the assignment is
      ' unnamed. If cMaxNames is less than is required to return all of the names of the
      ' parameters of a function, then only the names of the first cMaxNames-1 parameters
      ' are returned. The names of the parameters are returned in the array in the same
      ' order that they appear elsewhere in the interface (for example, the same order in
      ' the parameter array associated with the FUNCDESC enumeration).
      ' ----------------------------------------------------------------------------------
      REDIM rgbstrNames(@pFuncDesc.cParams) AS WSTRING
      hr = pTypeInfo.GetNames(@pFuncDesc.memid, rgbstrNames(0), @pFuncDesc.cParams + 1, cNames)
      IF hr = %S_OK THEN
         ' // Pointer to an ELEMDESC structure
         pParam = @pFuncDesc.lprgelemdescParam
         ' // Retrieves information about the parameters
         FOR y = 0 TO @pFuncDesc.cParams - 1
            bstrVarType = "" : bstrTypeKind = "" : bstrPBKeyword = ""
            ' // Attributes
            wFlags = @pParam[y].paramdesc.wParamFlags
            bstrParamName = rgbstrNames(y + 1)
            IF bstrParamName = "" THEN
               IF y = @pFuncDesc.cParams - 1 THEN
                  bstrParamName = "RHS"
               ELSE
                  bstrParamName = "prm" & FORMAT$(y + 1)
               END IF
            END IF
            hParamNameNode = TreeView_AddItem(hTreeView, hParamsNode, 0, 0, 0, bstrParamName)
            TreeView_AddItem(hTreeView, hParamNameNode, 0, 0, 0, "Attributes = " & FORMAT$(wFlags) & " [&H" & HEX$(wFlags, 8) & "] " & TLB_ParamflagsToStr(wFlags))
            wIndirectionLevel = 0
            IF @pParam[y].tdesc.vt = %VT_USERDEFINED THEN
               ' // If it is a user defined type, retrieve its name
               hr = pTypeInfo.GetRefTypeInfo(@pParam[y].tdesc.hreftype, pRefTypeInfo)
               IF hr = %S_OK AND ISOBJECT(pRefTypeInfo) THEN
                  hr = pRefTypeInfo.GetDocumentation(-1, bstrVarType, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
                  hr = pRefTypeInfo.GetTypeAttr(pParamTypeAttr)
                  IF hr = %S_OK AND pParamTypeAttr <> %NULL THEN
                     IF @pParamTypeAttr.typekind = %TKIND_ALIAS THEN
                        bstrTypeKind = TLB_TypeKindToStr(@pParamTypeAttr.typekind) & " | " & TLB_VarTypeToConstant(@pParamTypeAttr.tdescalias.vt)
                     ELSE
                        bstrTypeKind = TLB_TypeKindToStr(@pParamTypeAttr.typekind)
                     END IF
                     TreeView_AddItem(hTreeView, hParamNameNode, 0, 0, 0, "TypeKind = " & bstrTypeKind)
                     pRefTypeInfo.ReleaseTypeAttr(pParamTypeAttr)
                     pParamTypeAttr = 0
                  END IF
                  pRefTypeInfo = NOTHING
               END IF
            ELSEIF @pParam[y].tdesc.vt = %VT_PTR THEN
               ' // Pointer to a TYPEDESC structure
               ptdesc = @pParam[y].tdesc.lptdesc
               wIndirectionLevel = 1
               DO
                  SELECT CASE @ptdesc.vt
                     ' // If it is a pointer, do it again
                     CASE %VT_PTR
                        INCR wIndirectionLevel
                        ptdesc = @ptdesc.lptdesc
                     CASE %VT_USERDEFINED
                        ' // Retrieve the name of the user defined type
                        hr = pTypeInfo.GetRefTypeInfo(@ptdesc.hreftype, pRefTypeInfo)
                        IF hr = %S_OK AND ISOBJECT(pRefTypeInfo) THEN
                           hr = pRefTypeInfo.GetDocumentation(-1, bstrVarType, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
                           hr = pRefTypeInfo.GetTypeAttr(pParamTypeAttr)
                           IF hr = %S_OK AND pParamTypeAttr <> %NULL THEN
                              IF @pParamTypeAttr.typekind = %TKIND_ALIAS THEN
                                 bstrTypeKind = TLB_TypeKindToStr(@pParamTypeAttr.typekind) & " | " & TLB_VarTypeToConstant(@pParamTypeAttr.tdescalias.vt)
                              ELSE
                                 bstrTypeKind = TLB_TypeKindToStr(@pParamTypeAttr.typekind)
                              END IF
                              TreeView_AddItem(hTreeView, hParamNameNode, 0, 0, 0, "TypeKind = " & bstrTypeKind)
                              pRefTypeInfo.ReleaseTypeAttr(pParamTypeAttr)
                              pParamTypeAttr = 0
                           END IF
                           pRefTypeInfo = NOTHING
                        END IF
                        EXIT DO
                     CASE ELSE
                        ' // Get the equivalent type
                        bstrVarType = TLB_VarTypeToConstant(@ptdesc.vt)
                        bstrPBKeyword = TLB_VarTypeToKeyword(@ptdesc.vt)
                        EXIT DO
                  END SELECT
               LOOP
            ELSE
               ' // Get the equivalent type
               bstrVarType = TLB_VarTypeToConstant(@pParam[y].tdesc.vt)
               bstrPBKeyword = TLB_VarTypeToKeyword(@pParam[y].tdesc.vt)
               ' // Increment indirection level to pointers
               IF bstrTypeKind = "TKIND_INTERFACE" OR bstrTypeKind = "TKIND_DISPATCH" OR bstrTypeKind = "TKIND_COCLASS" THEN INCR wIndirectionLevel
               IF bstrVarType = "VT_SAFEARRAY" THEN INCR wIndirectionLevel
            END IF
            TreeView_AddItem(hTreeView, hParamNameNode, 0, 0, 0, "Indirection level = " & FORMAT$(wIndirectionLevel))
            TreeView_AddItem(hTreeView, hParamNameNode, 0, 0, 0, "VarType = " & bstrVarType)
            ' // Add a prefix to structures that begin with an underscore
            IF LEFT$(bstrVarType, 1) = "_" THEN
               IF bstrTypeKind = "TKIND_RECORD" OR bstrTypeKind = "TKIND_UNION" THEN bstrVarType = "tag" & bstrVarType
            END IF
            ' // Use generic data types for enums and interfaces
            IF bstrPBKeyword = "" THEN bstrPBKeyword = bstrVarType
            IF bstrTypeKind = "TKIND_ALIAS | VT_PTR" THEN bstrPBKeyword = "DWORD"
            IF bstrTypeKind = "TKIND_ENUM" THEN bstrPBKeyword = "LONG"
            IF bstrTypeKind = "TKIND_UNKNOWN" THEN bstrPBKeyword = "IUnknown"
            IF bstrTypeKind = "TKIND_DISPATCH" THEN bstrPBKeyword = "IDispatch"
            ' // Decide if to pass the parameter by value or by reference
            bstrPBSyntax = ""
            SELECT CASE bstrVarType
               CASE "VT_LPSTR"
                  bstrPBSyntax = "BYREF " & bstrParamName & " AS ASCIIZ"
               CASE "VT_LPWSTR"
                  bstrPBSyntax = "BYREF " & bstrParamName & " AS WSTRINGZ"
               CASE "VT_VOID"
                  IF wIndirectionLevel = 2 THEN
                     bstrPBSyntax = "BYREF " & bstrParamName & " AS DWORD"
                  ELSE
                     bstrPBSyntax = "BYVAL " & bstrParamName & " AS DWORD"
                  END IF
               CASE ELSE
                  IF bstrTypeKind = "TKIND_INTERFACE" OR bstrTypeKind = "TKIND_DISPATCH" OR bstrTypeKind = "TKIND_COCLASS" OR _
                     bstrVarType = "IFont" OR bstrVarType = "IFontDisp" OR bstrVarType = "IPicture" OR bstrVarType = "IPictureDisp" THEN
                     IF wIndirectionLevel = 2 THEN
                        bstrPBSyntax = "BYREF " & bstrParamName & " AS " & bstrPBKeyword
                     ELSE
                        bstrPBSyntax = "BYVAL " & bstrParamName & " AS " & bstrPBKeyword
                     END IF
                  ELSE
                     IF wIndirectionLevel = 0 THEN
                        bstrPBSyntax = "BYVAL " & bstrParamName & " AS " & bstrPBKeyword
                     ELSE
                        bstrPBSyntax = "BYREF " & bstrParamName & " AS " & bstrPBKeyword
                     END IF
                  END IF
            END SELECT
            IF (wFlags AND %PARAMFLAG_FOPT) = %PARAMFLAG_FOPT THEN bstrPBSyntax = "OPT " & bstrPBSyntax   ' // Optional parameter
            TreeView_AddItem(hTreeView, hParamNameNode, 0, 0, 0, "PB syntax = " & bstrPBSyntax)
            TreeView_Expand hTreeView, hParamNameNode, %TVE_EXPAND
         NEXT
      END IF

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieve information about the methods, properties and functions.
   ' =====================================================================================
   METHOD GetFunctions (BYVAL pTypeInfo AS ITypeInfo, BYVAL pTypeAttr AS TYPEATTR PTR, BYVAL hTreeView AS DWORD, BYVAL hSubNode AS DWORD, OPTIONAL BYVAL bIsMethod AS LONG, BYVAL pTKind AS DWORD, BYVAL bstrImplInterface AS WSTRING)

      LOCAL x AS LONG                           ' // Loop counter
      LOCAL hr AS LONG                          ' // HRESULT
      LOCAL hSubNode2 AS DWORD                  ' // Sub node handle
      LOCAL pFuncDesc AS FUNCDESC PTR           ' // Pointer to a FUNCDESC structure
      LOCAL bstrName AS WSTRING                 ' // Name
      LOCAL bstrHelpString AS WSTRING           ' // Help string
      LOCAL dwHelpContext AS DWORD              ' // Help context number
      LOCAL bstrDllName AS WSTRING              ' // DLL name
      LOCAL bstrEntryPoint AS WSTRING           ' // Entry point
      LOCAL wOrdinal AS WORD                    ' // Ordinal
      LOCAL pRefTypeInfo AS ITypeInfo           ' // Referenced TypeInfo interface
      LOCAL pReturnTypeAttr AS TYPEATTR PTR     ' // Referenced TYPEATTR structure
      LOCAL ptdesc AS TYPEDESC PTR              ' // Pointer to a TYPEDESC structure

      FOR x = 0 TO @pTypeAttr.cFuncs - 1
         ' // Gets a reference to the FuncDesc structure
         hr = pTypeInfo.GetFuncDesc(x, pFuncDesc)
         IF hr <> %S_OK OR pFuncDesc = %NULL THEN EXIT FOR
         ' // Retrieve the name
         pTypeInfo.GetDocumentation(@pFuncDesc.memid, bstrName, bstrHelpString, dwHelpContext, BYVAL %NULL)
         IF bIsMethod THEN
            ' ------------------------------------------------------------------
            ' Workaround for buggy libraries that can have illegal method names.
            ' For example, TLBINF32.DLL has a property called GetTypeInfo.
            ' ------------------------------------------------------------------
            IF UCASE$(bstrName) = "QUERYINTERFACE" AND @pFuncdesc.oVft > 24 THEN bstrName += "_"
            IF UCASE$(bstrName) = "ADDREF" AND @pFuncdesc.oVft > 24 THEN bstrName += "_"
            IF UCASE$(bstrName) = "RELEASE" AND @pFuncdesc.oVft > 24 THEN bstrName += "_"
            IF UCASE$(bstrName) = "GETTYPEINFOCOUNT" AND @pFuncdesc.oVft > 24 THEN bstrName += "_"
            IF UCASE$(bstrName) = "GETTYPEINFO" AND @pFuncdesc.oVft > 24 THEN bstrName += "_"
            IF UCASE$(bstrName) = "GETIDSOFNAMES" AND @pFuncdesc.oVft > 24 THEN bstrName += "_"
            IF UCASE$(bstrName) = "INVOKE" AND @pFuncdesc.oVft > 24 THEN bstrName += "_"
            ' ------------------------------------------------------------------
'            IF pTKind = %TKIND_DISPATCH THEN
'               IF bstrName = "QueryInterface" OR bstrName = "AddRef" OR bstrName = "Release" OR _
'                  bstrName = "GetTypeInfoCount" OR bstrName = "GetTypeInfo" OR _
'                  bstrName = "GetIDsOfNames" OR bstrName = "Invoke" THEN
'                  ' // Release the FUNCDESC structure
'                  pTypeInfo.ReleaseFuncDesc(pFuncDesc)
'                  pFuncDesc = 0
'                  ' // Iterate the loop
'                  ITERATE FOR
'               END IF
'            END IF
            IF pTKind = %TKIND_INTERFACE THEN
               IF UCASE$(bstrImplInterface) = "IUNKNOWN" AND (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FOLEAUTOMATION) = %TYPEFLAG_FOLEAUTOMATION OR _
                  UCASE$(bstrImplInterface) = "IDISPATCH" AND (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FDUAL) <> %TYPEFLAG_FDUAL THEN
                  IF @pFuncDesc.invkind = %INVOKE_FUNC THEN bstrName = "METHOD " & bstrName
                  IF pTLB.UseMethod THEN
                     IF @pFuncDesc.invkind = %INVOKE_PROPERTYGET THEN bstrName = "METHOD " & bstrName
                     IF @pFuncDesc.invkind = %INVOKE_PROPERTYPUT THEN bstrName = "METHOD " & bstrName
                     IF @pFuncDesc.invkind = %INVOKE_PROPERTYPUTREF THEN bstrName = "METHOD putref_" & bstrName
                  ELSE
                     IF @pFuncDesc.invkind = %INVOKE_PROPERTYGET THEN bstrName = "PROPERTY GET " & bstrName
                     IF @pFuncDesc.invkind = %INVOKE_PROPERTYPUT THEN bstrName = "PROPERTY SET " & bstrName
                     IF @pFuncDesc.invkind = %INVOKE_PROPERTYPUTREF THEN bstrName = "PROPERTY SET putref_" & bstrName
                  END IF
               ELSE
                  IF @pFuncDesc.invkind = %INVOKE_PROPERTYGET THEN bstrName = "get_" & bstrName
                  IF @pFuncDesc.invkind = %INVOKE_PROPERTYPUT THEN
                     IF pTLB.UseSetPrefix THEN bstrName = "set_" & bstrName ELSE bstrName = "put_" & bstrName
                  END IF
                  IF @pFuncDesc.invkind = %INVOKE_PROPERTYPUTREF THEN bstrName = "putref_" & bstrName
                  bstrName = "METHOD " & bstrName
               END IF
            ELSE
               IF @pFuncDesc.invkind = %INVOKE_FUNC THEN bstrName = "METHOD " & bstrName
               IF pTLB.UseMethod THEN
                  IF @pFuncDesc.invkind = %INVOKE_PROPERTYGET THEN bstrName = "METHOD " & bstrName
                  IF @pFuncDesc.invkind = %INVOKE_PROPERTYPUT THEN bstrName = "METHOD " & bstrName
                  IF @pFuncDesc.invkind = %INVOKE_PROPERTYPUTREF THEN bstrName = "METHOD putref_" & bstrName
               ELSE
                  IF @pFuncDesc.invkind = %INVOKE_PROPERTYGET THEN bstrName = "PROPERTY GET " & bstrName
                  IF @pFuncDesc.invkind = %INVOKE_PROPERTYPUT THEN bstrName = "PROPERTY SET " & bstrName
                  IF @pFuncDesc.invkind = %INVOKE_PROPERTYPUTREF THEN bstrName = "PROPERTY SET putref_" & bstrName
               END IF
            END IF
            hSubNode2 = TreeView_AddItem(hTreeView, hSubNode, 0, 0, 0, bstrName)
            TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "VTable offset = " &  FORMAT$(@pFuncdesc.oVft) & " [&H" & HEX$(@pFuncdesc.oVft, 8) & "]")
            TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "DispID = " & FORMAT$(@pFuncDesc.memid) & " [&H" & HEX$(@pFuncDesc.memid, 8) & "]")
            IF LEN(bstrHelpString) THEN TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "Help string = " & bstrHelpString)
            IF dwHelpContext THEN TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "Help context = " & FORMAT$(dwHelpContext))
         ELSE
            IF @pFuncDesc.elemdescFunc.tdesc.vt = %VT_VOID THEN
               hSubNode2 = TreeView_AddItem(hTreeView, hSubNode, 0, 0, 0, "SUB " & bstrName)
            ELSE
               hSubNode2 = TreeView_AddItem(hTreeView, hSubNode, 0, 0, 0, "FUNCTION " & bstrName)
            END IF
            IF LEN(bstrHelpString) THEN TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "Help string = " & bstrHelpString)
            IF dwHelpContext THEN TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "Help context = " & FORMAT$(dwHelpContext))
            TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "DispID = " & FORMAT$(@pFuncDesc.memid) & " [&H" & HEX$(@pFuncDesc.memid, 8) & "]")
            hr = pTypeInfo.GetDllEntry(@pFuncDesc.memid, @pFuncDesc.invkind, bstrDllName, bstrEntryPoint, wOrdinal)
            IF hr = %S_OK THEN
               IF LEN(bstrDllName) THEN TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "DLL name = " & bstrDllName)
               IF LEN(bstrEntryPoint) THEN TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "Entry point = " & bstrEntryPoint)
               IF wOrdinal THEN TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "Ordinal = " & FORMAT$(wOrdinal))
            END IF
         END IF
         ' // Kind of function
         SELECT CASE @pFuncDesc.funckind
            CASE %FUNC_VIRTUAL
               TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "FuncKind = Virtual")
            CASE %FUNC_PUREVIRTUAL
               TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "FuncKind = Pure virtual")
            CASE %FUNC_NONVIRTUAL
               TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "FuncKind = Non virtual")
            CASE %FUNC_STATIC
               TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "FuncKind = Static")
            CASE %FUNC_DISPATCH
               TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "FuncKind = Dispatch")
         END SELECT
         ' // Invoke kind
         SELECT CASE @pFuncDesc.invkind
            CASE %INVOKE_FUNC
               TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "InvokeKind = Function")
            CASE %INVOKE_PROPERTYGET
               TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "InvokeKind = Get property")
            CASE %INVOKE_PROPERTYPUT
               TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "InvokeKind = Put property")
            CASE %INVOKE_PROPERTYPUTREF
               TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "InvokeKind = PutRef property")
         END SELECT
         ' // Calling convention
         SELECT CASE @pFuncDesc.callconv
            CASE %CC_FASTCALL
               TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "Calling convention = FASTCALL")
            CASE %CC_CDECL
               TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "Calling convention = CDECL")
            CASE %CC_MACPASCAL
               TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "Calling convention = MACPASCAL")
            CASE %CC_STDCALL
               TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "Calling convention = STDCALL")
            CASE %CC_FPFASTCALL
               TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "Calling convention = FPFASTCALL")
            CASE %CC_SYSCALL
               TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "Calling convention = SYSCALL")
            CASE %CC_MPWCDECL
               TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "Calling convention = MPWCDECL")
            CASE %CC_MPWPASCAL
               TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "Calling convention = MPWPASCAL")
         END SELECT
         ' // More general information
         IF @pFuncDesc.cParamsOpt THEN TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "Number of optional variant parameters = " & FORMAT$(@pFuncDesc.cParamsOpt))
         IF @pFuncDesc.cScodes THEN TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "Count of permitted return values = " & FORMAT$(@pFuncDesc.cScodes))
         IF @pFuncDesc.wFuncFlags THEN TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "Attributes = " & FORMAT$(@pFuncDesc.wFuncFlags)& " [&H" & HEX$(@pFuncDesc.wFuncFlags, 8) & "]" & TLB_FuncFLagsToStr(@pFuncDesc.wFuncFlags))
         ' // Return type
         IF @pFuncDesc.elemdescFunc.tdesc.vt = %VT_USERDEFINED THEN
            ' // If it is a user defined type, retrieve its name
            hr = pTypeInfo.GetRefTypeInfo(@pFuncDesc.elemdescFunc.tdesc.hreftype, pRefTypeInfo)
            IF hr = %S_OK AND ISOBJECT(pRefTypeInfo) THEN
               hr = pRefTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
               hr = pRefTypeInfo.GetTypeAttr(pReturnTypeAttr)
               IF hr = %S_OK AND pReturnTypeAttr <> %NULL THEN
                  TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "Return type typeKind = " & TLB_TypeKindToStr(@pReturnTypeAttr.typekind))
                  pRefTypeInfo.ReleaseTypeAttr(pReturnTypeAttr)
                  pReturnTypeAttr = 0
               END IF
               pRefTypeInfo = NOTHING
            END IF
         ELSEIF @pFuncDesc.elemdescFunc.tdesc.vt = %VT_PTR THEN
            ' // Pointer to a TYPEDESC structure
            ptdesc = @pFuncDesc.elemdescFunc.tdesc.lptdesc
            DO
               SELECT CASE @ptdesc.vt
                  ' // If it is a pointer, do it again
                  CASE %VT_PTR
                     ptdesc = @ptdesc.lptdesc
                  CASE %VT_USERDEFINED
                     ' // Retrieve the name of the user defined type
                     hr = pTypeInfo.GetRefTypeInfo(@ptdesc.hreftype, pRefTypeInfo)
                     IF hr = %S_OK AND ISOBJECT(pRefTypeInfo) THEN
                        hr = pRefTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
                        hr = pRefTypeInfo.GetTypeAttr(pReturnTypeAttr)
                        IF hr = %S_OK AND pReturnTypeAttr <> %NULL THEN
                           TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "Return type typeKind = " & TLB_TypeKindToStr(@pReturnTypeAttr.typekind))
                           pRefTypeInfo.ReleaseTypeAttr(pReturnTypeAttr)
                           pReturnTypeAttr = 0
                        END IF
                        pRefTypeInfo = NOTHING
                     END IF
                     EXIT DO
                  CASE ELSE
                     ' // Get the equivalent type
                     bstrName = TLB_VarTypeToConstant(@ptdesc.vt)
                     EXIT DO
               END SELECT
            LOOP
         ELSE
            ' // Get the equivalent type
            bstrName = TLB_VarTypeToConstant(@pFuncDesc.elemdescFunc.tdesc.vt)
         END IF
         TreeView_AddItem(hTreeView, hSubNode2, 0, 0, 0, "Return type = " & bstrName)
         ' // Parameters
         IF @pFuncDesc.cParams THEN ME.GetParameters (pTypeInfo, pFuncDesc, hTreeView, hSubNode2)
         ' // Expand the nodes
'                     TreeView_Expand hTreeView, hSubNode2, %TVE_EXPAND
         TreeView_Expand hTreeView, hSubNode, %TVE_EXPAND
'         TreeView_Expand hTreeView, hParamsNode, %TVE_EXPAND
         ' // Release the FUNCDESC structure
         pTypeInfo.ReleaseFuncDesc(pFuncDesc)
         pFuncDesc = 0
      NEXT
      IF pFuncDesc THEN pTypeInfo.ReleaseFuncDesc(pFuncDesc)

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Parses the type infos
   ' =====================================================================================
   METHOD ParseTypeInfos () AS LONG

      LOCAL i AS LONG                           ' // Loop counter
      LOCAL x AS LONG                           ' // Loop counter
      LOCAL hr AS LONG                          ' // HRESULT
      LOCAL hTreeView AS DWORD                  ' // Tree view handle
      LOCAL pTKind AS DWORD                     ' // Type kind
      LOCAL pTypeAttr AS TYPEATTR PTR           ' // Attributes
      ' // Nodes
      LOCAL hNode AS DWORD                      ' // Node handle
      LOCAL hSubNode AS DWORD                   ' // Sub node handle
      LOCAL hSubNode2 AS DWORD                  ' // Sub node handle
      ' // Documentation
      LOCAL bstrName AS WSTRING                 ' // Name
      LOCAL bstrHelpString AS WSTRING           ' // Help string
      LOCAL dwHelpContext AS DWORD              ' // Help context number
      LOCAL bstrOrigName AS WSTRING             ' // Original name
      LOCAL bstrAliasName AS WSTRING            ' // Alias name
      LOCAL bstrAliasName2 AS WSTRING           ' // Alias name (reversed)
      LOCAL bstrTypedefName AS WSTRING          ' // Typedef name
      LOCAL bstrHelpFile AS WSTRING             ' // Help file path
      ' // Type info
      LOCAL TypeInfoCount AS LONG               ' // Number of type infos
      LOCAL bstrProgID AS WSTRING               ' // ProgID
      LOCAL bstrInProcServer AS WSTRING         ' // InProcServer path
      LOCAL cImplTypes AS LONG                  ' // Number of implemented interfaces
      LOCAL lImplTypeFlags AS LONG              ' // Implemented interfaces flags
      LOCAL pRefType  AS DWORD                  ' // Address to a referenced type description
      LOCAL pImplTypeInfo AS ITypeInfo          ' // Reference to the implemented interface TypeInfo
      LOCAL pImplTypeAttr AS TYPEATTR PTR       ' // Attributes of the implemented interface
      LOCAL hImplIntSubNode AS DWORD            ' // Implemented interfaces subnode
      LOCAL pRefTypeInfo AS ITypeInfo           ' // Referenced TypeInfo interface
      LOCAL ptdesc AS TYPEDESC PTR              ' // Pointer to a TYPEDESC structure
      LOCAL bstrImplInterface AS WSTRING        ' // Implemented interface
      LOCAL bstrInheritedInterface AS WSTRING   ' // Inherited interface

      IF ISNOTHING(m_pTypeLib) THEN EXIT METHOD

      ' // Treeview handle
      hTreeView = pTLB.hTreeView

      ' // Retrieves the number of TypeInfos
      TypeInfoCount = m_pTypeLib.GetTypeInfoCount
      IF TypeInfoCount = 0 THEN
         TLB_MsgBox pTLB.hwndMain, "This TypeLib doesn't have type infos", _
            %MB_OK OR %MB_ICONERROR OR %MB_APPLMODAL, "CParseTypeLib.ParseTypeInfos"
         EXIT METHOD
      END IF

      FOR i = 0 TO TypeInfoCount - 1

         ' // Allow for a breath and check the abort flag
'         TLB_DoEvents hWnd
'         IF m_Abort THEN EXIT FOR
         ' // Retrieves the TypeKind
         hr = m_pTypeLib.GetTypeInfoType(i, pTKind)
         IF hr <> %S_OK THEN
            TLB_MsgBox pTLB.hwndMain, "Error &H" & HEX$(hr, 8) & " retrieving the info type", _
               %MB_OK OR %MB_ICONERROR OR %MB_APPLMODAL, "CParseTypeLib.ParseTypeInfos"
            EXIT FOR
         END IF

         ' // Retrieves the ITypeInfo interface
         LOCAL pTypeInfo AS ITypeInfo
         hr = m_pTypeLib.GetTypeInfo(i, pTypeInfo)
         IF hr <> %S_OK OR ISFALSE ISOBJECT(pTypeInfo) THEN
            TLB_MsgBox pTLB.hwndMain, "Error &H" & HEX$(hr, 8) & " retrieving the ITypeInfo interface", _
               %MB_OK OR %MB_ICONERROR OR %MB_APPLMODAL, "CParseTypeLib.ParseTypeInfos"
            EXIT FOR
         END IF

         ' // Gets the address of a pointer to the TYPEATTR structure
         hr = pTypeInfo.GetTypeAttr(pTypeAttr)
         IF hr <> %S_OK OR pTypeAttr = %NULL THEN
            TLB_MsgBox pTLB.hwndMain, "Error &H" & HEX$(hr, 8) & " retrieving the address of the TypeAttr structure", _
               %MB_OK OR %MB_ICONERROR OR %MB_APPLMODAL, "CParseTypeLib.ParseTypeInfos"
            EXIT FOR
         END IF

         ' // Retrieve information
         SELECT CASE pTKind

            ' ----------------------------------------------------------------------------
            ' CoClasses
            ' ----------------------------------------------------------------------------
            CASE %TKIND_COCLASS
               ' // Get the name of the CoClass
               hr = m_pTypeLib.GetDocumentation(i, bstrName, bstrHelpString, dwHelpContext, bstrHelpFile)
               hNode = TreeView_AddItem(hTreeView, m_hCoClassesNode, 0, 0, 0, bstrName)
               ' // ProgIDs node
               ' Some external programs, such McAffee Antivirus, modify the typelibs of
               ' components such Windows Script Host to redirect it to its own server.
               ' This originates duplicate ProgIDs, so we need to search if the ProgID
               ' is already listed to avoid duplicates.
               bstrProgID = TLB_GetProgID(GUIDTXT$(@pTypeAttr.guid))
               IF LEN(bstrProgID) THEN
                  IF TreeView_ItemExists(hTreeView, m_hProgIDsNode, bstrProgID) = 0 THEN
                     TreeView_AddItem hTreeView, m_hProgIDsNode, 0, 0, 0, bstrProgID
                     hSubNode = TreeView_AddItem(hTreeView, hNode, 0, 0, 0, "ProgID")
                     TreeView_AddItem hTreeView, hSubNode, 0, 0, 0, bstrProgID
                     TreeView_Expand hTreeView, hSubNode, %TVE_EXPAND
                  END IF
               END IF
               ' // Version independent ProgIDs node
               ' Note: Search if it already exists because there are components like
               ' MSXML that allow side-by-side installation of several versions that have
               ' different ProgIDs but, of course, the same independent version ProgID.
               bstrProgID = TLB_GetVersionIndependentProgID(GUIDTXT$(@pTypeAttr.guid))
               IF LEN(bstrProgID) THEN
                  IF TreeView_ItemExists(hTreeView, m_hVerIndProgIDsNode, bstrProgID) = 0 THEN
                     TreeView_AddItem hTreeView, m_hVerIndProgIDsNode, 0, 0, 0, bstrProgID
                     hSubNode = TreeView_AddItem(hTreeView, hNode, 0, 0, 0, "Version independent ProgID")
                     TreeView_AddItem hTreeView, hSubNode, 0, 0, 0, bstrProgID
                     TreeView_Expand hTreeView, hSubNode, %TVE_EXPAND
                  END IF
               END IF
               ' // ClsIDs nodes
               TreeView_AddItem hTreeView, m_hClsIDsNode, 0, 0, 0, "$CLSID_" & bstrName & " = GUID$(" & $DQ & GUIDTXT$(@pTypeAttr.guid) & $DQ & ")"
               hSubNode = TreeView_AddItem(hTreeView, hNode, 0, 0, 0, "CLSID")
               TreeView_AddItem hTreeView, hSubNode, 0, 0, 0, GUIDTXT$(@pTypeAttr.guid)
               TreeView_Expand hTreeView, hSubNode, %TVE_EXPAND
               ' // Attributes
               hSubNode = TreeView_AddItem(hTreeView, hNode, 0, 0, 0, "Attributes")
               TreeView_AddItem hTreeView, hSubNode, 0, 0, 0, FORMAT$(@pTypeAttr.wTypeFlags) & " [&H" & HEX$(@pTypeAttr.wTypeFlags, 8) & "]" & TLB_InterfaceFlagsToStr(@pTypeAttr.wTypeFlags)
               TreeView_Expand hTreeView, hSubNode, %TVE_EXPAND
               ' // Help info
               IF LEN(bstrHelpString) THEN
                  hSubNode = TreeView_AddItem(hTreeView, hNode, 0, 0, 0, "Help string")
                  TreeView_AddItem hTreeView, hSubNode, 0, 0, 0, bstrHelpString
                  TreeView_Expand hTreeView, hSubNode, %TVE_EXPAND
               END IF
               IF dwHelpContext THEN
                  hSubNode = TreeView_AddItem(hTreeView, hNode, 0, 0, 0, "Help context")
                  TreeView_AddItem hTreeView, hSubNode, 0, 0, 0, FORMAT$(dwHelpContext) & "[&H" & HEX$(dwHelpContext, 8) & "]"
                  TreeView_Expand hTreeView, hSubNode, %TVE_EXPAND
               END IF
               IF LEN(bstrHelpFile) THEN
                  hSubNode = TreeView_AddItem(hTreeView, hNode, 0, 0, 0, "Help file")
                  TreeView_AddItem hTreeView, hSubNode, 0, 0, 0, bstrHelpFile
                  TreeView_Expand hTreeView, hSubNode, %TVE_EXPAND
               END IF
               ' // InProcServer32
               bstrInProcServer = TLB_ShortPathToLongPath(TLB_GetInprocServer32(GUIDTXT$(@pTypeAttr.guid)))
               IF LEN(bstrInProcServer) THEN
                  hSubNode = TreeView_AddItem(hTreeView, hNode, 0, 0, 0, "InProcServer32")
                  TreeView_AddItem hTreeView, hSubNode, 0, 0, 0, bstrInProcServer
                  TreeView_Expand hTreeView, hSubNode, %TVE_EXPAND
               END IF
               ' // Retrieve the implemented interfaces
               ' Note: Don't release pRefType or it will explode
               cImplTypes = @pTypeAttr.cImplTypes
               IF cImplTypes THEN hImplIntSubNode = TreeView_AddItem(hTreeView, hNode, 0, 0, 0, "Implemented interfaces")
               FOR x = 0 TO cImplTypes - 1
                  lImplTypeFlags = 0
                  hr = pTypeInfo.GetImplTypeFlags(x, lImplTypeFlags)
                  IF hr <> %S_OK THEN EXIT FOR
                  pRefType = 0
                  hr = pTypeInfo.GetRefTypeOfImplType(x, pRefType)
                  IF hr <> %S_OK THEN EXIT FOR
                  hr = pTypeInfo.GetRefTypeInfo(pRefType, pImplTypeInfo)
                  IF hr <> %S_OK OR ISFALSE ISOBJECT(pImplTypeInfo) THEN EXIT FOR
                  hr = pImplTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
                  IF hr <> %S_OK THEN EXIT FOR
                  TreeView_AddItem hTreeView, hImplIntSubNode, 0, 0, 0, bstrName
                  TreeView_Expand hTreeView, hImplIntSubNode, %TVE_EXPAND
                  pImplTypeAttr = 0
                  pImplTypeInfo.GetTypeAttr(pImplTypeAttr)
                  IF lImplTypeFlags = %IMPLTYPEFLAG_FDEFAULT THEN   ' // Default interface
                     hSubNode = TreeView_AddItem(hTreeView, hNode, 0, 0, 0, "Default interface")
                     TreeView_AddItem hTreeView, hSubNode, 0, 0, 0, bstrName
                     TreeView_Expand hTreeView, hSubNode, %TVE_EXPAND
                     hSubNode = TreeView_AddItem(hTreeView, hNode, 0, 0, 0, "Default interface IID")
                     IF pImplTypeAttr THEN TreeView_AddItem hTreeView, hSubNode, 0, 0, 0, GUIDTXT$(@pImplTypeAttr.guid)
                     TreeView_Expand hTreeView, hSubNode, %TVE_EXPAND
                  ELSEIF lImplTypeFlags = %IMPLTYPEFLAG_FSOURCE THEN   ' // Events interface
                     ' // Some components, such Office 12's AccWiz.dll, have deprecated CoClasses that
                     ' // implement the same events interfaces that the new one. We need to check if the
                     ' // interface is hidden to avoid listing them twice.
                     IF (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FHIDDEN) <> %TYPEFLAG_FHIDDEN THEN
                        IF ISFALSE TreeView_ItemExists(hTreeView, m_hEventsNode, bstrName) THEN
                           TreeView_AddItem hTreeView, m_hEventsNode, 0, 0, 0, bstrName
                        END IF
                     END IF
                  ELSEIF lImplTypeFlags = (%IMPLTYPEFLAG_FDEFAULT OR %IMPLTYPEFLAG_FSOURCE) THEN   ' // Default events interface
                     hSubNode = TreeView_AddItem(hTreeView, hNode, 0, 0, 0, "Default events interface")
                     TreeView_AddItem hTreeView, hSubNode, 0, 0, 0, bstrName
                     TreeView_Expand hTreeView, hSubNode, %TVE_EXPAND
                     hSubNode = TreeView_AddItem(hTreeView, hNode, 0, 0, 0, "Default events interface IID")
                     IF pImplTypeAttr THEN TreeView_AddItem hTreeView, hSubNode, 0, 0, 0, GUIDTXT$(@pImplTypeAttr.guid)
                     TreeView_Expand hTreeView, hSubNode, %TVE_EXPAND
                     ' // Some components, such Office 12's AccWiz.dll, have deprecated CoClasses that
                     ' // implement the same events interfaces that the new one. We need to check if the
                     ' // interface is hidden to avoid listing them twice.
                     IF (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FHIDDEN) <> %TYPEFLAG_FHIDDEN THEN
                        IF ISFALSE TreeView_ItemExists(hTreeView, m_hEventsNode, bstrName) THEN
                           TreeView_AddItem hTreeView, m_hEventsNode, 0, 0, 0, bstrName
                        END IF
                     END IF
                  END IF
                  IF pImplTypeAttr THEN
                     pImplTypeInfo.ReleaseTypeAttr(pImplTypeAttr)
                     pImplTypeAttr = 0
                  END IF
               NEXT
               IF pImplTypeAttr THEN
                  pImplTypeInfo.ReleaseTypeAttr(pImplTypeAttr)
                  pImplTypeAttr = 0
               END IF
               pImplTypeInfo = NOTHING
            ' ----------------------------------------------------------------------------

            ' ----------------------------------------------------------------------------
            ' Structures and unions
            ' ----------------------------------------------------------------------------
            CASE %TKIND_RECORD, %TKIND_UNION
               hr = m_pTypeLib.GetDocumentation(i, bstrName, bstrHelpString, dwHelpContext, bstrHelpFile)
               IF hr = %S_OK THEN
                  IF pTKind = %TKIND_RECORD THEN
                     hNode = TreeView_AddItem(hTreeView, m_hRecordsNode, 0, 0, 0, bstrName)
                  ELSE
                     hNode = TreeView_AddItem(hTreeView, m_hUnionsNode, 0, 0, 0, bstrName)
                  END IF
                  IF GUIDTXT$(@pTypeAttr.guid) <> "{00000000-0000-0000-0000-000000000000}" THEN TreeView_AddItem(hTreeView, hNode, 0, 0, 0, "IID: " & GUIDTXT$(@pTypeAttr.guid))
                  IF LEN(bstrHelpString) THEN TreeView_AddItem(hTreeView, hNode, 0, 0, 0, "Documentation string: " & bstrHelpString)
                  IF @pTypeAttr.cVars THEN
                     hSubNode = TreeView_AddItem(hTreeView, hNode, 0, 0, 0, "Number of members: " & FORMAT$(@pTypeAttr.cVars))
                     ME.GetMembers(pTypeInfo, pTypeAttr, hTreeView, hSubNode, %TRUE)
                  END IF
               END IF
            ' ----------------------------------------------------------------------------

            ' ----------------------------------------------------------------------------
            ' Aliases and typedefs
            ' ----------------------------------------------------------------------------
            CASE %TKIND_ALIAS
               bstrOrigName = "" : bstrAliasName = "" : bstrAliasName2 = "" : bstrTypedefName = ""
               hr = m_pTypeLib.GetDocumentation(i, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
               IF hr = %S_OK THEN
                  bstrOrigName = bstrName
                  IF @pTypeAttr.tdescAlias.vt = %VT_USERDEFINED THEN
                     ' // If it is a user defined type, retrieve its name
                     hr = pTypeInfo.GetRefTypeInfo(@pTypeAttr.tdescAlias.hreftype, pRefTypeInfo)
                     IF hr = %S_OK AND ISOBJECT(pRefTypeInfo) THEN
                        hr = pRefTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
                        IF hr = %S_OK THEN
                           bstrAliasName = bstrOrigName & " = " & bstrName
                           bstrAliasName2 = bstrName & " = " & bstrOrigName
                        END IF
                        pRefTypeInfo = NOTHING
                     END IF
                  ELSEIF @pTypeAttr.tdescAlias.vt = %VT_PTR THEN
                     ' // Pointer to a TYPEDESC structure
                     ptdesc = @pTypeAttr.tdescAlias.lptdesc
                     DO
                        SELECT CASE @ptdesc.vt
                           ' // If it is a pointer, do it again
                           CASE %VT_PTR
                              ptdesc = @ptdesc.lptdesc
                           CASE %VT_USERDEFINED
                              ' // Retrieve the name of the user defined type
                              hr = pTypeInfo.GetRefTypeInfo(@ptdesc.hreftype, pRefTypeInfo)
                              IF hr = %S_OK AND ISOBJECT(pRefTypeInfo) THEN
                                 hr = pRefTypeInfo.GetDocumentation(-1, bstrName, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
                                 IF hr = %S_OK THEN
                                    bstrAliasName = bstrOrigName & " = " & bstrName
                                    bstrAliasName2 = bstrName & " = " & bstrOrigName
                                 END IF
                                 pRefTypeInfo = NOTHING
                              END IF
                              EXIT DO
                           CASE ELSE
                              ' // Get the equivalent type
                              bstrTypedefName = bstrName & " = " & TLB_VarTypeToConstant(@ptdesc.vt) & " <" & TLB_VarTypeToKeyword(@pTypeAttr.tdescAlias.vt) & ">"
                              EXIT DO
                        END SELECT
                     LOOP
                  ELSE
                     ' // Get the equivalent type
                     bstrTypedefName = bstrName & " = " & TLB_VarTypeToConstant(@pTypeAttr.tdescAlias.vt) & " <" & TLB_VarTypeToKeyword(@pTypeAttr.tdescAlias.vt) & ">"
                  END IF
                  IF LEN(bstrTypedefName) THEN
                     TreeView_AddItem hTreeView, m_hTypedefsNode, 0, 0, 0, bstrTypedefName
                  ELSE
                     TreeView_AddItem hTreeView, m_hAliasesNode, 0, 0, 0, bstrAliasName
                     TreeView_AddItem hTreeView, m_hAliasesNode, 0, 0, 0, bstrAliasName2
                  END IF
               END IF
            ' ----------------------------------------------------------------------------

            ' ----------------------------------------------------------------------------
            ' Enumerations and modules
            ' ----------------------------------------------------------------------------
            CASE %TKIND_ENUM, %TKIND_MODULE
               hr = m_pTypeLib.GetDocumentation(i, bstrName, bstrHelpString, dwHelpContext, bstrHelpFile)
               IF hr = %S_OK THEN
                  IF pTKind = %TKIND_ENUM THEN
                     hNode = TreeView_AddItem(hTreeView, m_hEnumsNode, 0, 0, 0, bstrName)
                  ELSE
                     hNode = TreeView_AddItem(hTreeView, m_hModulesNode, 0, 0, 0, bstrName)
                  END IF
                  IF GUIDTXT$(@pTypeAttr.guid) <> "{00000000-0000-0000-0000-000000000000}" THEN TreeView_AddItem(hTreeView, hNode, 0, 0, 0, "IID: " & GUIDTXT$(@pTypeAttr.guid))
                  IF LEN(bstrHelpString) THEN TreeView_AddItem(hTreeView, hNode, 0, 0, 0, "Documentation string: " & bstrHelpString)
                  ' /*** Constants ***/
                  IF @pTypeAttr.cVars THEN
                     hSubNode = TreeView_AddItem(hTreeView, hNode, 0, 0, 0, "Number of constants: " & FORMAT$(@pTypeAttr.cVars))
                     ME.GetConstants(pTypeInfo, pTypeAttr, hTreeView, hSubNode)
                  END IF
                  ' /*** Functions ***/
                  IF @pTypeAttr.cFuncs THEN
                     hSubNode = TreeView_AddItem(hTreeView, hNode, 0, 0, 0, "Number of functions " & FORMAT$(@pTypeAttr.cFuncs))
                     ME.GetFunctions(pTypeInfo, pTypeAttr, hTreeView, hSubNode)
                  END IF
               END IF
            ' ----------------------------------------------------------------------------

            ' ----------------------------------------------------------------------------
            ' Dispatch interfaces
            ' ----------------------------------------------------------------------------
            CASE %TKIND_INTERFACE, %TKIND_DISPATCH
               hr = m_pTypeLib.GetDocumentation(i, bstrName, bstrHelpString, BYVAL %NULL, BYVAL %NULL)
               IF hr = %S_OK THEN
                  TreeView_AddItem hTreeView, m_hIIDsNode, 0, 0, 0, "$IID_" & bstrName & " = GUID$(" & $DQ & GUIDTXT$(@pTypeAttr.guid) & $DQ & ")"
                  bstrImplInterface = TLB_GetImplementedInterface(pTypeInfo)
                  IF bstrImplInterface <> "" THEN
                     IF UCASE$(bstrImplInterface) <> "IUNKNOWN" AND UCASE$(bstrImplInterface) <> "IDISPATCH" THEN
                        bstrImplInterface = TLB_GetBaseClass(m_pTypeLib, bstrName)
                     END IF
                  END IF
                  IF pTKind = %TKIND_INTERFACE THEN
                     IF UCASE$(bstrImplInterface) = "IUNKNOWN" AND (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FOLEAUTOMATION) = %TYPEFLAG_FOLEAUTOMATION THEN
                        hSubNode = TreeView_AddItem(hTreeView, m_hOleAutIntNode, 0, 0, 0, bstrName)
                     ELSEIF UCASE$(bstrImplInterface) = "IDISPATCH" AND (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FDUAL) <> %TYPEFLAG_FDUAL THEN
                        hSubNode = TreeView_AddItem(hTreeView, m_hDispblIntNode, 0, 0, 0, bstrName)
                     ELSE
                        hSubNode = TreeView_AddItem(hTreeView, m_hIntNode, 0, 0, 0, bstrName)
                     END IF
                  ELSEIF pTKind = %TKIND_DISPATCH THEN
                     IF (@pTypeAttr.wTypeFlags AND %TYPEFLAG_FDUAL) = %TYPEFLAG_FDUAL THEN
                        hSubNode = TreeView_AddItem(hTreeView, m_hDualIntNode, 0, 0, 0, bstrName)
                     ELSE
                        hSubNode = TreeView_AddItem(hTreeView, m_hDispIntNode, 0, 0, 0, bstrName)
                     END IF
                  END IF
                  IF GUIDTXT$(@pTypeAttr.guid) <> "{00000000-0000-0000-0000-000000000000}" THEN
                     TreeView_AddItem(hTreeView, hSubNode, 0, 0, 0, "IID: " & GUIDTXT$(@pTypeAttr.guid))
                  END IF
                  IF LEN(bstrHelpString) THEN TreeView_AddItem(hTreeView, hSubNode, 0, 0, 0, "Documentation string: " & bstrHelpString)
                  IF @pTypeAttr.wTypeFlags THEN TreeView_AddItem(hTreeView, hSubNode, 0, 0, 0, "Attributes =  " & FORMAT$(@pTypeAttr.wTypeFlags) & " [&H" & HEX$(@pTypeAttr.wTypeFlags, 8) & "]" & TLB_InterfaceFlagsToStr(@pTypeAttr.wTypeFlags))
                  IF LEN(bstrImplInterface) THEN TreeView_AddItem(hTreeView, hSubNode, 0, 0, 0, "Inherited interface = " & bstrImplInterface)
                  ' /*** Datamembers ***/
                  IF @pTypeAttr.cVars THEN
                     hSubNode2 = TreeView_AddItem(hTreeView, hSubNode, 0, 0, 0, "Number of datamembers " & FORMAT$(@pTypeAttr.cVars))
                     ME.GetMembers (pTypeInfo, pTypeAttr, hTreeView, hSubNode2)
                  END IF
                  ' /*** Retrieves the methods and properties ***/
                  IF @pTypeAttr.cFuncs THEN
                     hSubNode2 = TreeView_AddItem(hTreeView, hSubNode, 0, 0, 0, "Number of methods = " & FORMAT$(@pTypeAttr.cFuncs))
                     ME.GetFunctions(pTypeInfo, pTypeAttr, hTreeView, hSubNode2, %TRUE, pTKind, bstrImplInterface)
                  END IF
               END IF
            ' ----------------------------------------------------------------------------

         END SELECT

         IF pTypeAttr THEN
            pTypeInfo.ReleaseTypeAttr(pTypeAttr)
            pTypeAttr = 0
         END IF

      NEXT

      ' // Cleanup
      IF pTypeAttr THEN pTypeInfo.ReleaseTypeAttr(pTypeAttr)
      pTypeInfo = NOTHING

      ' // Sort the items
      TreeView_SortChildren hTreeView, hImplIntSubNode, %FALSE
      TreeView_SortChildren hTreeView, m_hProgIDsNode, %FALSE
      TreeView_SortChildren hTreeView, m_hVerIndProgIDsNode, %FALSE
      TreeView_SortChildren hTreeView, m_hClsIDsNode, %FALSE
      TreeView_SortChildren hTreeView, m_hCoClassesNode, %FALSE
      TreeView_SortChildren hTreeView, m_hEnumsNode, %FALSE
      TreeView_SortChildren hTreeView, m_hModulesNode, %FALSE
      TreeView_SortChildren hTreeView, m_hRecordsNode, %FALSE
      TreeView_SortChildren hTreeView, m_hUnionsNode, %FALSE
      TreeView_SortChildren hTreeView, m_hAliasesNode, %FALSE
      TreeView_SortChildren hTreeView, m_hTypedefsNode, %FALSE
      TreeView_SortChildren hTreeView, m_hIIDsNode, %FALSE
      TreeView_SortChildren hTreeView, m_hIntNode, %FALSE
      TreeView_SortChildren hTreeView, m_hOleAutIntNode, %FALSE
      TreeView_SortChildren hTreeView, m_hDualIntNode, %FALSE
      TreeView_SortChildren hTreeView, m_hDispIntNode, %FALSE
      TreeView_SortChildren hTreeView, m_hDispblIntNode, %FALSE
      TreeView_SortChildren hTreeView, m_hEventsNode, %FALSE

      ' // Remove empty nodes
      IF TreeView_GetChild(hTreeView, m_hProgIDsNode) = %NULL THEN
         TreeView_DeleteItem hTreeView, m_hProgIDsNode
         m_hProgIDsNode = 0
      END IF
      IF TreeView_GetChild(hTreeView, m_hVerIndProgIDsNode) = %NULL THEN
         TreeView_DeleteItem hTreeView, m_hVerIndProgIDsNode
         m_hVerIndProgIDsNode = 0
      END IF
      IF TreeView_GetChild(hTreeView, m_hClsIDsNode) = %NULL THEN
         TreeView_DeleteItem hTreeView, m_hClsIDsNode
         m_hClsIDsNode = 0
      END IF
      IF TreeView_GetChild(hTreeView, m_hCoClassesNode) = %NULL THEN
         TreeView_DeleteItem hTreeView, m_hCoClassesNode
         m_hCoClassesNode = 0
      END IF
      IF TreeView_GetChild(hTreeView, m_hEnumsNode) = %NULL THEN
         TreeView_DeleteItem hTreeView, m_hEnumsNode
         m_hEnumsNode = 0
      END IF
      IF TreeView_GetChild(hTreeView, m_hModulesNode) = %NULL THEN
         TreeView_DeleteItem hTreeView, m_hModulesNode
         m_hModulesNode = 0
      END IF
      IF TreeView_GetChild(hTreeView, m_hRecordsNode) = %NULL THEN
         TreeView_DeleteItem hTreeView, m_hRecordsNode
         m_hRecordsNode = 0
      END IF
      IF TreeView_GetChild(hTreeView, m_hUnionsNode) = %NULL THEN
         TreeView_DeleteItem hTreeView, m_hUnionsNode
         m_hUnionsNode = 0
      END IF
      IF TreeView_GetChild(hTreeView, m_hAliasesNode) = %NULL THEN
         TreeView_DeleteItem hTreeView, m_hAliasesNode
         m_hAliasesNode = 0
      END IF
      IF TreeView_GetChild(hTreeView, m_hTypedefsNode) = %NULL THEN
         TreeView_DeleteItem hTreeView, m_hTypedefsNode
         m_hTypedefsNode = 0
      END IF
      IF TreeView_GetChild(hTreeView, m_hIIDsNode) = %NULL THEN
         TreeView_DeleteItem hTreeView, m_hIIDsNode
         m_hIIDsNode = 0
      END IF
      IF TreeView_GetChild(hTreeView, m_hIntNode) = %NULL THEN
         TreeView_DeleteItem hTreeView, m_hIntNode
         m_hIntNode = 0
      END IF
      IF TreeView_GetChild(hTreeView, m_hOleAutIntNode) = %NULL THEN
         TreeView_DeleteItem hTreeView, m_hOleAutIntNode
         m_hOleAutIntNode = 0
      END IF
      IF TreeView_GetChild(hTreeView, m_hDualIntNode) = %NULL THEN
         TreeView_DeleteItem hTreeView, m_hDualIntNode
         m_hDualIntNode = 0
      END IF
      IF TreeView_GetChild(hTreeView, m_hDispIntNode) = %NULL THEN
         TreeView_DeleteItem hTreeView, m_hDispIntNode
         m_hDispIntNode = 0
      END IF
      IF TreeView_GetChild(hTreeView, m_hDispblIntNode) = %NULL THEN
         TreeView_DeleteItem hTreeView, m_hDispblIntNode
         m_hDispblIntNode = 0
      END IF
      IF TreeView_GetChild(hTreeView, m_hEventsNode) = %NULL THEN
         TreeView_DeleteItem hTreeView, m_hEventsNode
         m_hEventsNode = 0
      END IF

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Code generation
   ' =====================================================================================
   METHOD GenerateCode

'   INSTANCE m_LibName            AS WSTRING    ' // Library name
'   INSTANCE m_LibPath            AS WSTRING    ' // Library path
'   INSTANCE m_LibHelpString      AS WSTRING    ' // Library help string
'   INSTANCE m_LibHelpContext     AS DWORD      ' // Library Help context
'   INSTANCE m_LibHelpFile        AS WSTRING    ' // Library help file
'   INSTANCE m_LibGuid            AS WSTRING    ' // Library GUID
'   INSTANCE m_LibLcid            AS DWORD      ' // Library LCID
'   INSTANCE m_LibSysKind         AS LONG       ' // Library SysKind
'   INSTANCE m_LibMajorVersion    AS INTEGER    ' // Library major version
'   INSTANCE m_LibMinorVersion    AS INTEGER    ' // Library minor version
'   INSTANCE m_LibAttr            AS INTEGER    ' // Library attributes
'   INSTANCE m_PrefixStr          AS WSTRING    ' // Prefix

      ' // Create an instance of the StringBuilderW class
      LOCAL pSb AS IStringBuilderW
      pSb = CLASS "StringBuilderW"
      IF ISNOTHING(pSb) THEN EXIT METHOD

      ' ----------------------------------------------------------------------------------
      ' Documentation header
      ' ----------------------------------------------------------------------------------
      LOCAL wszFmt AS WSTRINGZ * 15     ' // Date format
      LOCAL wszDate AS WSTRINGZ * 256   ' // Formatted date
      wszFmt = "dd MMM yyyy"
      GetDateFormatW %LOCALE_USER_DEFAULT, 0, BYVAL %NULL, wszFmt, wszDate, SIZEOF(wszDate)
      pSb.Add("' ########################################################################################" & $CRLF)
      pSb.Add("' Library name: " & m_LibName & $CRLF)
      IF LEN(m_LibHelpString) THEN pSb.Add("' Documentation string: " & m_LibHelpString & $CRLF)
      pSb.Add("' GUID: " & m_LibGuid & $CRLF)
      pSb.Add("' Version: " & FORMAT$(m_LibMajorVersion) & "." & FORMAT$(m_LibMinorVersion) & ", Locale ID = " & FORMAT$(m_LibLcid) & $CRLF)
      pSb.Add("' Path: " & m_LibPath & $CRLF)
      psb.Add("' Attributes: " & FORMAT$(m_LibAttr) & " [&H" & HEX$(m_LibAttr, 8) & "] " & TLB_LibFlagsToStr(m_LibAttr) & $CRLF)
      IF LEN(m_LibHelpFile) THEN pSb.Add("' Help file: " & m_LibHelpFile & $CRLF)
      'IF LEN(m_strLicKey) THEN psb.Add("' License key: " & m_strLicKey & $cRLF)
      pSb.Add("' Code generated by the " & $TLBCAPTION & " " & $TLBCOPYRIGHT & $CRLF)
      pSb.Add("' Date: " & wszDate & " Time: " & TIME$ & $CRLF)
      pSb.Add("' Options used to generate the code:" & $CRLF)
      IF pTLB.UsePropGetSet THEN pSb.Add("' - Use METHOD and PROPERTY GET/SET statements" & $CRLF)
      IF pTLB.UseMethod THEN pSb.Add("' - Use METHOD statements only" & $CRLF)
      IF pTLB.UseSetPrefix THEN pSb.Add("' - Use SET_ instead of PUT_ as prefix" & $CRLF)
      IF pTLB.UseParameterNames THEN pSb.Add("' - Use parameter names in interface declarations" & $CRLF)
      IF pTLB.AddParameterNamesPrefix THEN pSb.Add("' - Add prefix in parameter names" & $CRLF)
      IF pTLB.UseIntNamesWithExObj THEN pSb.Add("' - Use interface names with external objects" & $CRLF)
      IF pTLB.UsePrefix THEN pSb.Add("' - Use prefix in interface names. Prefix = " & Edit_GetTExt(pTLB.hEditPrefix) & $CRLF)
      IF pTLB.UseEnumPrefix THEN pSb.Add("' - Use enumeration names as prefix in constants" & $CRLF)
      IF pTLB.UseHexNumbers THEN pSb.Add("' - Use hexadecimal numbers in constants" & $CRLF)
      IF pTLB.MixDispInterfaces THEN pSb.Add("' - Include dispatch only interfaces" & $CRLF)
      IF pTLB.RetrieveLicenseKey THEN pSb.Add("' - Retrieve license key" & $CRLF)
      pSb.Add("' ########################################################################################" & $CRLF)
      ' ----------------------------------------------------------------------------------

      ' // Set the text of the edit window
      Edit_SetTextW(pTLB.hCodeView, pSb.String)
      ' // Set the focus in the edit control
      SetFocus(pTLB.hCodeView)
      ' // Hide the typelibs and options pages
      ShowWindow(pTLB.pTabTypeLibs.hwnd, %SW_HIDE)
      ShowWindow(pTLB.pTabOptions.hwnd, %SW_HIDE)
      ' // Show the code page
      ShowWindow(pTLB.pTabCode.hwnd, %SW_SHOW)
      ' // Select the code tab
      TabCtrl_SetCurSel(pTLB.hTab, 1)
      TabCtrl_SetCurFocus(pTLB.hTab, 1)

      ' // Destroy the IStringBuilder class
      pSb = NOTHING

   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' #######################################################################################
