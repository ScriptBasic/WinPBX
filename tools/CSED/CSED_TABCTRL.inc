' ########################################################################################
' CSED Editor
' File: CSED_TABCTRL.INC
' Contents: CSED editor tab control
' Copyright (c) 2012 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ========================================================================================
' Create the tab control for the MDI windows
' ========================================================================================
FUNCTION CSED_CreateTabMdiCtrl (BYVAL pWindow AS IWindow) AS DWORD

   LOCAL hwndTab    AS DWORD
   LOCAL dwStyle    AS DWORD
   LOCAL ToolHeight AS LONG
   LOCAL rc         AS RECT
   LOCAL rctb       AS RECT

   ' // Retrieve the height of the toolbar
   GetWindowRect pSed.hToolbar, rctb
   ToolHeight = rctb.nBottom - rctb.nTop

   ' // Retrieve the coordinates of the window's client area
   GetClientRect pWindow.hwnd, rc

   ' // Create the tab control
'   dwStyle = %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %TCS_SINGLELINE OR %TCS_RIGHTJUSTIFY OR %TCS_FOCUSNEVER OR %TCS_TOOLTIPS OR %TCS_BUTTONS OR %TCS_FLATBUTTONS
   dwStyle = %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %TCS_SINGLELINE OR %TCS_RIGHTJUSTIFY OR %TCS_TABS OR %TCS_FOCUSNEVER OR %TCS_TOOLTIPS
   hwndTab = pWindow.AddTab(pWindow.hwnd, %IDC_TABMDI, "", _
             rc.nLeft, rc.nTop + ToolHeight, rc.nRight, 22, _
             dwStyle, %WS_EX_STATICEDGE)

   ' // Set the image list
   TabCtrl_SetImageList(hwndTab, pSed.hTabCtrlImageList)

   FUNCTION = hwndTab

END FUNCTION
' ========================================================================================

' ========================================================================================
' Redraw all the tabs removing them and inserting them again.
' Workaround for a problem with the Tab control not redrawing properly when there are many
' tabs and you delete one tab, causing the deletion to scroll the tabs.
' ========================================================================================
SUB CSED_TabMdiRedrawTabs

   LOCAL vPath AS VARIANT
   LOCAL pTabFilePaths AS ILinkListCollection

   ' // Delete all the tabs
   TabCtrl_DeleteAllItems pSed.hTabMdi
   ' // Add them again
   pSed.TabFilePaths.First
   DO
'      vPath = pSed.TabFilePaths.Next
      pTabFilePaths = pSed.TabFilePaths
      vPath = pTabFilePaths.Next
      IF OBJRESULT = %S_FALSE THEN EXIT DO
      TabCtrl_AddTab(pSed.hTabMdi, 0, BYCOPY PATHNAME$(NAMEX, VARIANT$$(vPath)))
      ' // Note: In some OSes, such XP SP3 and Windows 7, files that begin with a number,
      ' // such 0.BAS are displayed in the tab wrongly, e.g. as BAS.0.
      ' // Apparently, it's a bug of the tab control.
      ' // As a workaround, call TabCtrl_SetText after adding and selecting the tab.
      TabCtrl_SetText(pSed.hTabMdi, TabCtrl_GetItemCount(pSed.hTabMdi) - 1, BYCOPY PATHNAME$(NAMEX, VARIANT$$(vPath)))
   LOOP

END SUB
' ========================================================================================

' ========================================================================================
' Retrieve the tab number associated with a path.
' Return value: The zero-based number of the tab, or -1 if not found.
' ========================================================================================
#IF %DEF(%UNICODE)
FUNCTION CSED_GetTabNumberFromPath (BYVAL strFilePath AS WSTRING) AS LONG
#ELSE
FUNCTION CSED_GetTabNumberFromPath (BYVAL strFilePath AS STRING) AS LONG
#ENDIF

   LOCAL idx AS LONG
   LOCAL vPath AS VARIANT
   LOCAL pTabFilePaths AS ILinkListCollection

   IF pSed.TabFilePaths.Count = 0 THEN
      FUNCTION = -1
      EXIT FUNCTION
   END IF
   pSed.TabFilePaths.First
   DO
'      vPath = pSed.TabFilePaths.Next
      pTabFilePaths = pSed.TabFilePaths
      vPath = pTabFilePaths.Next
      IF OBJRESULT = %S_FALSE THEN EXIT DO
      IF VARIANT$$(vPath) = strFilePath THEN
         FUNCTION = idx
         EXIT DO
      END IF
      INCR idx
   LOOP

END FUNCTION
' ========================================================================================

' ========================================================================================
' Activates a window given the path of the file loaded in it
' ========================================================================================
#IF %DEF(%UNICODE)
SUB CSED_TabMdiActivateWindow (BYVAL strFilePath AS WSTRING)
#ELSE
SUB CSED_TabMdiActivateWindow (BYVAL strFilePath AS STRING)
#ENDIF

   LOCAL hMdi AS DWORD
   LOCAL nTab AS LONG
   LOCAL vPath AS VARIANT

   IF ISNULL(strFilePath) THEN EXIT SUB
   ' // Get the path from the caption of the MDI child window
   vPath = AfxGetWindowText(MdiGetActive(pSed.hwndClient))
   ' // If it's the same, it's already activated
   IF VARIANT$$(vPath) = strFilePath THEN EXIT SUB

   ' // Disable redrawing
   AfxDisableWindowRedraw pSed.hwndClient

   ' // Get the first MDI child window handle
   hMdi = GetWindow(pSed.hwndClient, %GW_CHILD)
   ' // Cycle thru all the open windows
   WHILE hMdi
      ' // Get the path from the collection
      vPath = AfxGetWindowText(hMdi)
      IF VARIANT$$(vPath) = strFilePath THEN
         nTab = CSED_GetTabNumberFromPath(VARIANT$$(vPath))
         IF nTab > -1 THEN
            ' // Select the tab associated with the window
            TabCtrl_SetCurSel(pSed.hTabMdi, nTab)
            ' // Activate the MDI child window
            IF IsIconic(hMdi) THEN
               MdiRestore(pSed.hwndClient, hMdi)
            ELSE
               MdiActivate(pSed.hwndClient, hMdi)
            END IF
            EXIT LOOP
         END IF
      END IF
      ' // Get the handle of the next MDI child window
      hMdi = GetWindow(hMdi, %GW_HWNDNEXT)
   WEND

   ' // Enable redrawing
   AfxEnableWindowRedraw pSed.hwndClient
   ' // Redraw the window
'   RedrawWindow pSed.hwndClient, BYVAL %NULL, %NULL, %RDW_ERASE OR %RDW_FRAME OR %RDW_INVALIDATE OR %RDW_ALLCHILDREN
   ' // Redraw the Scintilla edit control
   IF pSed.hEdit THEN RedrawWindow pSed.hEdit, BYVAL %NULL, %NULL, %RDW_ERASE OR %RDW_FRAME OR %RDW_INVALIDATE

END SUB
' ========================================================================================

' ========================================================================================
' Remove the tab associated with a path
' ========================================================================================
#IF %DEF(%UNICODE)
SUB CSED_TabMdiRemoveTab (BYVAL strFilePath AS WSTRING)
#ELSE
SUB CSED_TabMdiRemoveTab (BYVAL strFilePath AS STRING)
#ENDIF

   LOCAL nTab AS LONG
   LOCAL nCount AS LONG
   LOCAL idx AS LONG

   ' // Get the tab bumber associated with the path
   nTab = CSED_GetTabNumberFromPath(strFilePath)
   IF nTab = - 1 THEN EXIT SUB
   ' // Delete the tab
   TabCtrl_DeleteItem(pSed.hTabMdi, nTab)
   ' // Index in the one-based collection
   idx = nTab + 1
   ' // Remove the path from the collection
   pSed.TabFilePaths.Remove(idx)
   nCount = pSed.TabFilePaths.Count
   IF nCount = 0 THEN EXIT SUB
   ' // Redraw all the tabs
   CSED_TabMdiRedrawTabs
   IF idx > nCount THEN idx = nCount

END SUB
' ========================================================================================