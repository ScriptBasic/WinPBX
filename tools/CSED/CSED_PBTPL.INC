' ########################################################################################
' CSED Editor
' File: CSED_PBTPL.INC
' Contents: PowerBASIC templates
' Copyright (c) 2012 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

%IDC_TEMPLATES_LISTBOX = 101

' ========================================================================================
' Get the template description
' ========================================================================================
FUNCTION CSED_GetTemplateDesc (BYVAL hwnd AS DWORD, BYVAL strFileName AS STRING) AS STRING

   LOCAL idx AS LONG
   LOCAL FileNo AS LONG
   LOCAL strText AS STRING
   LOCAL nType AS LONG

   TRY
      FileNo = FREEFILE
      OPEN strFileName FOR INPUT AS FileNo
      WHILE ISFALSE EOF(FileNo)
         LINE INPUT# FileNo, strText
         INCR idx
         IF idx = 1 THEN nType = VAL(strText)
         IF (nType = 1 AND idx = 3) OR (nType = 2 AND idx = 4) THEN
            FUNCTION = strText
            EXIT LOOP
         END IF
      WEND
   CATCH
      CSED_MsgBox hwnd, "Error " & FORMAT$(ERR) & " trying to read " & strFileName, %MB_OK OR %MB_ICONERROR, "Error"
      EXIT TRY
   FINALLY
      CLOSE FileNo
   END TRY

END FUNCTION
' ========================================================================================

' ========================================================================================
' Recursive search of PB templates
' ========================================================================================
SUB CSED_SearchTemplates (BYVAL hwnd AS DWORD)

   LOCAL hSearch  AS DWORD                  ' // Search handle
   LOCAL WFD      AS WIN32_FIND_DATA        ' // FindFirstFile structure
   LOCAL strPath  AS STRING                 ' // Compiler path
#IF %DEF(%UNICODE)
   LOCAL curpath  AS WSTRINGZ * %MAX_PATH   ' // What to search for
#ELSE
   LOCAL curpath  AS ASCIIZ * %MAX_PATH     ' // What to search for
#ENDIF

   pSed.TemplatePaths = ""
   pSed.TemplateDescs = ""
   strPath = EXE.PATH$ & "Templates\"
   curpath = strPath & "\*.pbtpl"              ' // This is what we want to find
   hSearch = FindFirstFile(curPath, WFD)       ' // Get search handle, if success
   IF hSearch <> %INVALID_HANDLE_VALUE THEN
      ' // Loop through directory for files
      DO
         ' // If not directory bit is set...
         IF (WFD.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) <> %FILE_ATTRIBUTE_DIRECTORY THEN
            pSed.TemplatePaths = pSed.TemplatePaths & strPath & WFD.cFileName & ";"
            pSed.TemplateDescs = pSed.TemplateDescs & CSED_GetTemplateDesc(hwnd, strPath & WFD.cFileName) & "|"
         END IF
      LOOP WHILE FindNextFile(hSearch, WFD)
      FindClose(hSearch)
   END IF

END SUB
' ========================================================================================

' ========================================================================================
' Opens a template file in a new window
' ========================================================================================
SUB CSED_OpenTemplateFile (BYVAL hwnd AS DWORD, BYVAL id AS LONG)

   LOCAL FileNo        AS LONG
   LOCAL pSci          AS DWORD
   LOCAL hMdi          AS DWORD
   LOCAL nTab          AS LONG
   LOCAL idx           AS LONG
   LOCAL p             AS LONG
   LOCAL buffer        AS STRING
   LOCAL strFilePath   AS STRING
   LOCAL strText       AS STRING
   LOCAL strExt        AS STRING
   LOCAL bstrFilePath  AS WSTRING
   LOCAL nType         AS LONG
   LOCAL strCompiler   AS STRING
#IF %DEF(%UNICODE)
   LOCAL szFilePath    AS WSTRINGZ * %MAX_PATH
#ELSE
   LOCAL szFilePath    AS ASCIIZ * %MAX_PATH
#ENDIF

   strFilePath = PARSE$(pSed.TemplatePaths, ";", id)

   TRY
      FileNo = FREEFILE
      OPEN strFilePath FOR INPUT AS FileNo
      WHILE ISFALSE EOF(FileNo)
         LINE INPUT# FileNo, strText
         INCR idx
         IF idx = 1 THEN nType = VAL(strText)
         IF nType = 2 AND idx = 2 THEN strCompiler = TRIM$(UCASE$(strText))
         IF (nType = 1 AND idx = 2) OR (nType = 2 AND idx = 3) THEN strExt = strText
         IF (nType = 1 AND idx > 3) OR (nType = 2 AND idx > 4) THEN buffer = buffer & strText & $CRLF
      WEND
   CATCH
      CSED_MsgBox hwnd, "Error " & FORMAT$(ERR) & " trying to read " & strFilePath, %MB_OK OR %MB_ICONERROR, "Error"
      EXIT TRY
   FINALLY
      CLOSE FileNo
   END TRY

   IF strExt = "" THEN strExt = ".BAS"
   IF LEFT$(strExt, 1) <> "." THEN strExt = "." & strExt
   p = INSTR(strExt, " ")
   IF p THEN strExt = LEFT$(strExt, p - 1)

   hMdi = CSED_CreateMdiChild(strFilePath)
   IF ISFALSE hMdi THEN EXIT SUB
   ShowWindow hMdi, %SW_SHOW

   ' // Get a direct pointer for faster access
   pSci = SCI_GetDirectPointer(pSed.hEdit)
   IF ISFALSE pSci THEN EXIT SUB

   ' // Insert the text at the current position
   SCIP_InsertText(pSci, 0, buffer)

   ' // Change the title of the window
   szFilePath = "Untitled" & FORMAT$(pSed.UntitledFilesIdx) & strExt
   SetWindowText hMdi, szFilePath

   ' // Change the tab name
   nTab = TabCtrl_GetCurSel(pSed.hTabMdi)
   TabCtrl_SetText(pSed.hTabMdi, nTab, szFilePath)

   ' // Change the name in the one-based collection
   bstrFilePath = szFilePath
   pSed.TabFilePaths.Replace(nTab + 1, bstrFilePath)

   ' // Change the editor options
   CSED_SetScintillaOptions(pSed.hEdit, strExt)

   ' // Replace the marker with an empty space
   SCIP_FindReplace(pSci, "|", "")

   ' // Set the state of the document as unmodified
   SCIP_SetSavePoint(pSci)

   ' // Change statusbar information
   CSED_ShowLinCol

   ' // Set the compiler
   IF nType = 2 THEN
      IF strCompiler = "PBWIN" THEN
         IF pSed.SelectedCompiler <> 1 THEN
            pSed.SelectedCompiler = 1
            StatusBar_SetText(pSed.hStatusbar, 3, "PBWIN")
         END IF
      ELSEIF strCompiler = "CCWIN" THEN
         IF pSed.SelectedCompiler <> 2 THEN
            pSed.SelectedCompiler = 2
            StatusBar_SetText(pSed.hStatusbar, 3, "PBCC")
         END IF
      END IF
   END IF

END SUB
' ========================================================================================

' ========================================================================================
' Templates popup dialog
' ========================================================================================
SUB CSED_Templates (BYVAL hParent AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG)

   LOCAL i AS LONG        ' // Loop counter

   ' // Create an instance of the class
   LOCAL pTemplates AS IWindow
   pTemplates = CLASS "CWindow"
   IF ISNOTHING(pTemplates) THEN EXIT SUB

   ' // Create the main window
   LOCAL hwnd AS DWORD
'   hwnd = pTemplates.CreateWindow(hParent, "Templates", x + 5, y + 5, 322, 396, _
'          %WS_VISIBLE OR %WS_CAPTION OR %WS_POPUPWINDOW, %WS_EX_TOOLWINDOW OR %WS_EX_WINDOWEDGE, _
'          CODEPTR(CSED_Templates_WindowProc))
   hwnd = pTemplates.CreateWindow(hParent, "Templates", x + 5, y + 5, 422 * pTemplates.rxRatio, 412 * pTemplates.ryRatio, _
          %WS_VISIBLE OR %WS_CAPTION OR %WS_POPUPWINDOW, %WS_EX_WINDOWEDGE, _
          CODEPTR(CSED_Templates_WindowProc), %TRUE)
   ' // Add a listbox
   LOCAL hListBox AS DWORD
   hListBox = pTemplates.AddListbox(hwnd, %IDC_TEMPLATES_LISTBOX, "", 0, 0, 0, 0, _
      %WS_CHILD OR %WS_VISIBLE OR %WS_HSCROLL OR %WS_VSCROLL OR %WS_BORDER OR _
      %WS_TABSTOP OR %LBS_STANDARD OR %LBS_HASSTRINGS OR %LBS_SORT OR %LBS_NOTIFY OR %LBS_NOINTEGRALHEIGHT, %WS_EX_CLIENTEDGE)
   ' // Adjust the height of the control so that the integral height
   ' // is based on the new font rather than the default SYSTEM_FONT
   pTemplates.SetWindowPos hListBox, %NULL, 8, 8, 400, 337, %SWP_NOZORDER
   ListBox_SetHorizontalExtent hListBox, 600 * pTemplates.rxRatio

   ' // Add the buttons
   pTemplates.AddButton(hwnd, %IDOK, "&Ok", 245, 353, 75, 23, %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT OR %BS_DEFPUSHBUTTON, %WS_EX_NOPARENTNOTIFY)
   pTemplates.AddButton(hwnd, %IDCANCEL, "&Cancel", 333, 353, 75, 23, %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT, %WS_EX_NOPARENTNOTIFY)

   ' // Search templates
   CSED_SearchTemplates(hParent)
   ' // Add the names
   LOCAL strName AS STRING   ' // Template name
   LOCAL idx AS LONG         ' // 0 based index of the item
   LOCAL nCount AS LONG      ' // Number of templates
   nCount = PARSECOUNT(pSed.TemplatePaths, ";") - 1
   IF nCount THEN
      FOR i = 1 TO nCount
         strName = PARSE$(pSed.TemplateDescs, "|", i)
         idx = ListBox_AddString(hListBox, BYCOPY strName)
         IF idx <> %LB_ERR AND idx <> %LB_ERRSPACE THEN
            Listbox_SetItemData(hListBox, idx, i)
         END IF
      NEXT
   END IF
   ' // Select the first item
   IF nCount THEN ListBox_SetCurSel(hListBox, 0)
   ' // Set the focus in the list box
   SetFocus hListBox

   ' // Default message pump (you can replace it with your own)
   pTemplates.DoEvents

END SUB
' ========================================================================================

' ========================================================================================
' Templates callback function.
' ========================================================================================
FUNCTION CSED_Templates_WindowProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL hListBox AS DWORD
   LOCAL curSel AS LONG
   LOCAL idx AS LONG

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
                  ' // Let the IDC_TEMPLATES_LISTBOX message to process it
                  SendMessage hwnd, %WM_COMMAND, MAK(DWORD, %IDC_TEMPLATES_LISTBOX, %LBN_DBLCLK), 0
                  EXIT FUNCTION
               END IF

            CASE %IDC_TEMPLATES_LISTBOX
               SELECT CASE HI(WORD, wParam)
                  CASE %LBN_DBLCLK
                     ' // Get the handle of the Listbox
                     hListBox = GetDlgItem(hwnd, %IDC_TEMPLATES_LISTBOX)
                     ' // Get the current selection
                     curSel = ListBox_GetCurSel(hListBox)
                     ' // Get the stored index
                     idx = ListBox_GetItemData(hListBox, curSel)
                     ' // Open the template
                     CSED_OpenTemplateFile(hwnd, idx)
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
