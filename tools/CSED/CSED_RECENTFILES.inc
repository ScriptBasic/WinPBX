' ########################################################################################
' CSED Editor
' File: CSED_RECENTFILES.INC
' Contents: PowerBASIC templates
' Copyright (c) 2012 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

%IDC_RECENTFILES_LISTBOX = 101
%IDC_RECENTFILES_REMOVEITEM = 102
%IDC_RECENTFILES_REMOVEALLITEMS = 103
%IDC_RECENTFILES_PURGEITEMS = 104

' ========================================================================================
' Recent files popup dialog
' ========================================================================================
SUB CSED_RecentFiles (BYVAL hParent AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG)

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT SUB

   ' // Create the main window
   LOCAL hwnd AS DWORD
'   hwnd = pWindow.CreateWindow(hParent, "Recent Files", x + 5, y + 5, 522, 396, _
'          %WS_VISIBLE OR %WS_CAPTION OR %WS_POPUPWINDOW, %WS_EX_TOOLWINDOW OR %WS_EX_WINDOWEDGE, _
'          CODEPTR(CSED_RecentFiles_WindowProc))
   hwnd = pWindow.CreateWindow(hParent, "Recent Files", x + 5, y + 5, 522 * pWindow.rxRatio, 412 * pWindow.rxRatio, _
          %WS_VISIBLE OR %WS_CAPTION OR %WS_POPUPWINDOW, %WS_EX_WINDOWEDGE, _
          CODEPTR(CSED_RecentFiles_WindowProc), %TRUE)
   ' // Add a listbox
   LOCAL hListBox AS DWORD
   hListBox = pWindow.AddListbox(hwnd, %IDC_RECENTFILES_LISTBOX, "", 0, 0, 0, 0, _
      %WS_CHILD OR %WS_VISIBLE OR %WS_HSCROLL OR %WS_VSCROLL OR %WS_BORDER OR _
      %WS_TABSTOP OR %LBS_STANDARD OR %LBS_HASSTRINGS OR %LBS_SORT OR %LBS_NOTIFY OR %LBS_NOINTEGRALHEIGHT, %WS_EX_CLIENTEDGE)
   ' // Adjust the height of the control so that the integral height
   ' // is based on the new font rather than the default SYSTEM_FONT
   pWindow.SetWindowPos hListBox, %NULL, 8, 8, 500, 337, %SWP_NOZORDER
   ListBox_SetHorizontalExtent hListBox, 900 * pWindow.rxRatio

   ' // Add the buttons
   pWindow.AddButton(hwnd, %IDC_RECENTFILES_REMOVEITEM, "&Remove", 8, 353, 75, 23, %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT, %WS_EX_NOPARENTNOTIFY)
   pWindow.AddButton(hwnd, %IDC_RECENTFILES_REMOVEALLITEMS, "Remove &All", 96, 353, 75, 23, %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT, %WS_EX_NOPARENTNOTIFY)
   pWindow.AddButton(hwnd, %IDC_RECENTFILES_PURGEITEMS, "&Purge", 184, 353, 75, 23, %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT, %WS_EX_NOPARENTNOTIFY)
   pWindow.AddButton(hwnd, %IDOK, "&Ok", 345, 353, 75, 23, %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT OR %BS_DEFPUSHBUTTON, %WS_EX_NOPARENTNOTIFY)
   pWindow.AddButton(hwnd, %IDCANCEL, "&Cancel", 433, 353, 75, 23, %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT, %WS_EX_NOPARENTNOTIFY)

   LOCAL i      AS LONG   ' // Loop counter
   LOCAL idx    AS LONG   ' // 0 based index of the item
   LOCAL nCount AS LONG   ' // Number of items
#IF %DEF(%UNICODE)
   LOCAL strPath AS WSTRING
#ELSE
   LOCAL strPath AS STRING
#ENDIF
   FOR i = 1 TO 99
      ' // Get the path
      strPath = pSed.GetRecentFile(i)
      IF ISNOTNULL(strPath) THEN
         IF ISFILE(strPath) THEN
            idx = ListBox_InsertString(hListBox, 0, strPath)
            IF idx <> %LB_ERR THEN
               ListBox_SetItemData(hListbox, idx, i)
               nCount += 1
            END IF
         END IF
      END IF
   NEXT
   ' // Select the first item
   IF nCount THEN ListBox_SetCurSel(hListBox, 0)
   ' // Set the focus in the list box
   SetFocus hListBox

   ' // Default message pump (you can replace it with your own)
   pWindow.DoEvents

END SUB
' ========================================================================================

' ========================================================================================
' Recent files callback function.
' ========================================================================================
FUNCTION CSED_RecentFiles_WindowProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL i        AS LONG     ' // Loop counter
   LOCAL r        AS LONG     ' // Result code
   LOCAL idx      AS LONG     ' // Zero-based index of the item
   LOCAL curSel   AS LONG     ' // Current selection
   LOCAL nCount   AS LONG     ' // Number of items
   LOCAL hListBox AS DWORD    ' // List box handle
   LOCAL strPath  AS STRING   ' // Path

   SELECT CASE uMsg

      CASE %WM_CREATE
         ' // Disable the owner of the modal window
         EnableWindow GetWindow(hwnd, %GW_OWNER), %FALSE

      CASE %WM_COMMAND

         SELECT CASE LO(WORD, wParam)

            CASE %IDCANCEL
               ' // Close the dialog
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  SendMessage hwnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF

            CASE %IDOK
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  ' // Let the IDC_RECENTFILES_LISTBOX message to process it
                  SendMessage hwnd, %WM_COMMAND, MAK(DWORD, %IDC_RECENTFILES_LISTBOX, %LBN_DBLCLK), 0
                  EXIT FUNCTION
               END IF

            CASE %IDC_RECENTFILES_REMOVEITEM
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  ' // Get the handle of the Listbox
                  hListBox = GetDlgItem(hwnd, %IDC_RECENTFILES_LISTBOX)
                  ' // Get the current selection
                  curSel = ListBox_GetCurSel(hListBox)
                  ' // Get the index in the recent files collection
                  idx = ListBox_GetItemData(hListBox, curSel)
                  IF idx THEN
                     r = pSed.DeleteRecentFile(idx)
                     ListBox_DeleteString hListBox, curSel
                     ' // Update the recent files menu
                     CSED_RecentFilesMenu
                  END IF
                  EXIT FUNCTION
               END IF

            CASE %IDC_RECENTFILES_REMOVEALLITEMS
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  ' // Get the handle of the Listbox
                  hListBox = GetDlgItem(hwnd, %IDC_RECENTFILES_LISTBOX)
                  ' // Delete the whole section
                  pSed.DeleteAllRecentFiles
                  ' // Update the recent files menu
                  CSED_RecentFilesMenu
                  ' // Close the dialog
                  SendMessage hwnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF

            CASE %IDC_RECENTFILES_PURGEITEMS
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  ' // Get the handle of the Listbox
                  hListBox = GetDlgItem(hwnd, %IDC_RECENTFILES_LISTBOX)
                  ' // Remove no longer existing files
                  pSed.PurgeRecentFiles
                  ' // Remove all the items from the listbox
                  ListBox_ResetContent(hListBox)
                  AfxDisableWindowRedraw hListBox
                  FOR i = 1 TO 99
                     ' // Get the path
                     strPath = pSed.GetRecentFile(i)
                     IF ISNOTNULL(strPath) THEN
                        idx = ListBox_InsertString(hListBox, 0, strPath)
                        IF idx <> %LB_ERR THEN
                           ListBox_SetItemData(hListbox, idx, i)
                           nCount += 1
                        END IF
                     END IF
                  NEXT
                  AfxEnableWindowRedraw hListBox
                  ' // Select the first item
                  IF nCount THEN ListBox_SetCurSel(hListBox, 0)
                  ' // Update the recent files menu
                  CSED_RecentFilesMenu
                  EXIT FUNCTION
               END IF

            CASE %IDC_RECENTFILES_LISTBOX
               SELECT CASE HI(WORD, wParam)
                  CASE %LBN_DBLCLK
                     ' // Get the handle of the Listbox
                     hListBox = GetDlgItem(hwnd, %IDC_RECENTFILES_LISTBOX)
                     ' // Get the current selection
                     curSel = ListBox_GetCurSel(hListBox)
                     strPath = ListBox_GetText(hListBox, curSel)
                     ' // Open the file
                     CSED_OpenFile(strPath)
                     ' // Close the dialog
                     SendMessage hwnd, %WM_CLOSE, 0, 0
                     EXIT FUNCTION
               END SELECT

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

' ========================================================================================
' Add an item to a menu.
' ========================================================================================
SUB CSED_RecentFilesMenu

   LOCAL i AS LONG
   LOCAL nCount AS LONG
   LOCAL idx AS LONG
#IF %DEF(%UNICODE)
   LOCAL strPath AS WSTRING
#ELSE
   LOCAL strPath AS STRING
#ENDIF

   ' // Clear the recent files menu
   FOR i = 0 TO 8
      IF RemoveMenu(pSed.hSubMenuRecentFiles, 0, %MF_BYPOSITION) = 0 THEN EXIT FOR
   NEXT

   ' // Add items
   nCount = 1
   idx = pSed.RecentFilesIdx
   IF idx < 1 THEN EXIT SUB
   DO
      ' // Get the path
      strPath = pSed.GetRecentFile(idx)
      IF ISNOTNULL(strPath) THEN
         IF ISFILE(strPath) THEN
            AppendMenu pSed.hSubMenuRecentFiles, %MF_ENABLED, %IDM_RECENTFILES + nCount, "&" & FORMAT$(nCount) & " " & strPath
            INCR nCount
            IF nCount > 9 THEN EXIT DO
         END IF
      END IF
      DECR idx
      IF idx < 1 THEN EXIT DO
   LOOP

END SUB
' ========================================================================================

' ========================================================================================
' Opens a file from the Recent files menu
' ========================================================================================
FUNCTION CSED_OpenRecentFile (BYVAL wParam AS DWORD) AS STRING

   LOCAL idx AS LONG
#IF %DEF(%UNICODE)
   LOCAL strPath AS WSTRING
'   LOCAL strIndex AS WSTRING
#ELSE
   LOCAL strPath AS STRING
'   LOCAL strIndex AS STRING
#ENDIF

   ' // Get the path from the .ini file
'   idx = LO(WORD, wParam) - %IDM_RECENTFILES
'   strIndex = "File " & FORMAT$(idx)
'   strPath = IniFileRead(pSed.IniFileName, "Recent files", strIndex)

   ' // Get the path from the menu item
   strPath = AfxGetMenuItemText(pSed.hSubMenuRecentFiles, wParam)
   IF ISNULL(strPath) THEN EXIT FUNCTION
   ' // Remove the "&<number> " prefix
   strPath = MID$(strPath, 4)
   IF ISFILE(strPath) THEN
      CSED_OpenFile(strPath)
   ELSE
      MessageBox(pSed.hwndMain, "The file doesn't already exist", _
                 FUNCNAME$, %MB_OK OR %MB_ICONINFORMATION OR %MB_APPLMODAL)
   END IF
   FUNCTION = strPath

END FUNCTION
' ========================================================================================
