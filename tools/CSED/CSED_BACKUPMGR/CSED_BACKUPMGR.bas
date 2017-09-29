' ########################################################################################
' CSED Editor
' File: CSED_BACKUPMGR.INC
' Contents: Backup files manager
' Copyright (c) 2011 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#COMPILE EXE
#DIM ALL
%UNICODE = 1

$PROGNAME = "CSED Backup Files Manager"

' // Include files for external files
%USERICHEDIT = 1
#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "CWindow.inc"
#INCLUDE ONCE "commctrl.inc"
#INCLUDE ONCE "ListBoxCtrl.inc"
#INCLUDE ONCE "EditCtrl.inc"
#INCLUDE ONCE "RichEditCtrl.inc"
#INCLUDE ONCE "StatusbarCtrl.inc"
#INCLUDE ONCE "commdlg.inc"
#INCLUDE ONCE "trm.inc"

' // Resource file

' ========================================================================================
' Icon identifiers
' ========================================================================================
%IDI_BACKUPMGR32 = 100
%IDI_BACKUPMGR16 = 101
' ========================================================================================

#RESOURCE MANIFEST, 1, "CSED_BACKUPMGR.xml"
#RESOURCE ICON,   100, "32_BACKUPMGR.ico"
#RESOURCE ICON,   101, "16_BACKUPMGR.ico"

' ========================================================================================
' Control identifiers
' ========================================================================================
ENUM CSED_BACKUPMGR_ENUM SINGULAR
   IDC_STATUSBAR = 1001
   IDC_LBITEMS
   IDC_RICHEDIT
   IDB_EXPORT
   IDB_DELETE
   IDB_DELETEALL
   IDB_COPY
   IDB_EXIT
END ENUM
' ========================================================================================

' ========================================================================================
' Global handle
' ========================================================================================
GLOBAL hCodeFile AS LONG
' ========================================================================================

' ========================================================================================
' CSED_MsgBox
' ========================================================================================
#IF %DEF(%UNICODE)
FUNCTION CSED_MsgBox (BYVAL hwnd AS DWORD, BYVAL strMessage AS WSTRING, OPTIONAL BYVAL dwStyle AS DWORD, BYVAL strCaption AS WSTRING) AS LONG
#ELSE
FUNCTION CSED_MsgBox (BYVAL hwnd AS DWORD, BYVAL strMessage AS STRING, OPTIONAL BYVAL dwStyle AS DWORD, BYVAL strCaption AS STRING) AS LONG
#ENDIF

   IF LEN(strCaption) = 0 THEN strCaption = "CSED Editor"
   IF dwStyle = 0 THEN dwStyle = %MB_OK
   FUNCTION = MessageBox(hwnd, BYCOPY strMessage, BYCOPY strCaption, dwStyle)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates the code database
' ========================================================================================
FUNCTION CSED_CreateBackupMgrDatabase (BYVAL hWnd AS DWORD, BYVAL strDbPath AS STRING) AS LONG

   LOCAL strFileDef AS STRING
   LOCAL strKeys AS STRING
   LOCAL strSegment AS STRING * 25

   strSegment = "Backup File Name"

   strFileDef = MKBYT$(1) & _     ' // Page Size
                MKBYT$(1) & _     ' // Compress Record
                MKBYT$(1)         ' // Number of Key Segments

   strKeys =    strSegment  & _   ' // Description
                MKBYT$(1)   & _   ' // Segment number
                MKWRD$(1)   & _   ' // Segment Offset
                MKBYT$(60)  & _   ' // Segment Size
                MKBYT$(2)         ' // Flags (No duplicates)

   strFileDef += strKeys

   ' // Create Tsunami database file
'   IF ISFILE(strDbPath) THEN
'      IF CSED_MsgBox(hWnd, strDbPath & $CRLF & "File already exist. Overwrite it?", %MB_OK, "Warning!") = %IDYES THEN
'         FUNCTION = trm_Create(strDbPath, strFileDef, %TRUE)
'      ELSE
'         EXIT FUNCTION
'      END IF
'   ELSE
'      FUNCTION = trm_Create(strDbPath, strFileDef, %FALSE)
'   END IF

   LOCAL hCodeFile AS DWORD
   trm_Create(strDbPath, strFileDef, %TRUE)
   trm_Close(hCodeFile)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Fill the listbox
' ========================================================================================
FUNCTION FillListBox (BYVAL hwnd AS DWORD) AS LONG

   LOCAL RecordStr AS STRING
   LOCAL nCount AS LONG

   RecordStr = trm_GetFirst(hCodeFile, 1)
   WHILE LEN(RecordStr)
      INCR nCount
      AfxDoEvents hwnd
      ListBox_AddString GetDlgItem(hwnd, %IDC_LBITEMS), TRIM$(LEFT$(RecordStr, 60))
      RecordStr = trm_GetNext(hCodeFile)
   WEND

   FUNCTION = nCount

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieve the record
' ========================================================================================
FUNCTION RetrieveCodeRecord (BYVAL hwnd AS DWORD) AS LONG

   LOCAL RecordStr AS STRING
   LOCAL strName AS STRING
   LOCAL Index AS LONG

   IF ISFALSE hCodeFile THEN EXIT FUNCTION
   Index = ListBox_GetCurSel(GetDlgItem(hwnd, %IDC_LBITEMS))
   IF Index = %LB_ERR THEN EXIT FUNCTION
   strName = ListBox_GetText(GetDlgItem(hwnd, %IDC_LBITEMS), Index)
   IF LEN(strName) > 60 THEN strName = LEFT$(strName, 60)
   RecordStr = trm_GetEqualOrGreater(hCodeFile, 1, strName)
   IF UCASE$(TRIM$(LEFT$(RecordStr, 60))) = UCASE$(strName) THEN
      RichEdit_SetText GetDlgItem(hwnd, %IDC_RICHEDIT), MID$(RecordStr, 61)
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Delete the record
' ========================================================================================
FUNCTION DeleteCodeRecord (BYVAL hwnd AS DWORD) AS LONG

   LOCAL i AS LONG
   LOCAL hListBox AS DWORD
   LOCAL nCount AS LONG
   LOCAL Result AS LONG
   LOCAL RecordStr AS STRING
   LOCAL strName AS STRING
   DIM   rgItems(0) AS LOCAL LONG

   IF ISFALSE hCodeFile THEN EXIT FUNCTION
   hListBox = GetDlgItem(hwnd, %IDC_LBITEMS)
   IF ISFALSE hListBox THEN EXIT FUNCTION
   nCount = ListBox_GetSelCount(hListBox)
   IF nCount = 0 THEN EXIT FUNCTION
   REDIM rgItems(nCount - 1)
   IF ListBox_GetSelItems(hListbox, nCount, rgItems(0)) = %LB_ERR THEN EXIT FUNCTION
   FOR i = 0 TO nCount - 1
      strName = ListBox_GetText(hListBox, rgItems(i))
      IF LEN(strName) > 60 THEN strName = LEFT$(strName, 60)
      RecordStr = trm_GetEqualOrGreater(hCodeFile, 1, strName)
      IF UCASE$(TRIM$(LEFT$(RecordStr, 60))) = UCASE$(strName) THEN
         Result = trm_Delete(hCodeFile)
         IF Result = 0 THEN
            Statusbar_SetText(GetDlgItem(hwnd, %IDC_STATUSBAR), 0, "Record " & strName & " deleted")
         ELSE
            MessageBox hwnd, "Error" & STR$(Result) & " deleting the record " & strName, FUNCNAME$, %MB_ICONERROR OR %MB_OK OR %MB_APPLMODAL
         END IF
      END IF
   NEXT
   ListBox_ResetContent(hListBox)
   FillListBox(hwnd)
   ListBox_SetCursel(hListBox, 0)
   RetrieveCodeRecord(hwnd)
   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Export backup file
' ========================================================================================
#IF %DEF(%UNICODE)
FUNCTION CSED_ExportFile (BYVAL hwnd AS DWORD, BYVAL strName AS WSTRING, BYVAL strText AS WSTRING) AS LONG
#ELSE
FUNCTION CSED_ExportFile (BYVAL hwnd AS DWORD, BYVAL strName AS STRING, BYVAL strText AS STRING) AS LONG
#ENDIF

   LOCAL nLen           AS LONG      ' // Text lenght
   LOCAL dwStyle        AS DWORD     ' // Window styles
   LOCAL nFile          AS LONG      ' // File number
   LOCAL buffer         AS STRING    ' // Buffer
#IF %DEF(%UNICODE)
   LOCAL strInitialDir  AS WSTRING   ' // Initial directory
   LOCAL strPath        AS WSTRING   ' // File path
   LOCAL strExt         AS WSTRING   ' // File extension
   LOCAL strFilter      AS WSTRING   ' // Filter
   LOCAL strDefExt      AS WSTRING   ' // Default extension
#ELSE
   LOCAL strInitialDir  AS STRING    ' // Initial directory
   LOCAL strPath        AS STRING    ' // File path
   LOCAL strExt         AS STRING    ' // File extension
   LOCAL strFilter      AS STRING    ' // Filter
   LOCAL strDefExt      AS STRING    ' // Default extension
#ENDIF

   IF ISNULL(strName) THEN EXIT FUNCTION
   IF ISNULL(strText) THEN EXIT FUNCTION
   strExt = PATHNAME$(EXTN, strPath)
   strPath = CURDIR$ & "\" & strName
   strInitialDir = CURDIR$
   IF RIGHT$(strInitialDir, 1) <> "\" THEN strInitialDir = strInitialDir + "\"

   ' // Build the filter based on the file extension
   strExt = UCASE$(PATHNAME$(EXTN, strPath))
   SELECT CASE strExt
      CASE ".BAS"
         strFilter += "PB Code Files (*.BAS)|*.BAS|"
         strFilter += "PB Include Files (*.INC)|*.INC|"
      CASE ".INC"
         strFilter += "PB Include Files (*.INC)|*.INC|"
         strFilter += "PB Code Files (*.BAS)|*.BAS|"
      CASE ".PBTPL"
         strFilter += "PB Template Files (*.PBTPL)|*.PBTPL|"
      CASE ".RC", ".RC2", ".DLG"
         strFilter += "Resource Files (*.RC;*.RC2;.DLG)|*.RC;*.RC2;*.DLG|"
      CASE ".TXT"
         strFilter += "Text Files (*.TXT)|*.TXT|"
      CASE ".XML", ".XSL", ".XSD"
         strFilter += "XML Files (*.XML;*.XSL;*.XSD)|*.XML;*.XSL;*.XSD|"
      CASE ".HTML", ".HTM", ".SHTML"
         strFilter += "HTML Files (*.HTML;*.HTM;*.SHTML)|*.HTML;*.HTM;*.SHTML|"
      CASE ".C", ".CC", ".CPP", ".CXX", ".H", ".HH", ".HPP", ".HXX"
         strFilter += "C/CPP Files (*.C;*.CC;*.CPP;*.CXX;*.H;*.HH;*.HPP;*.HXX)|*.C;*.CC;*.CPP;*.CXX;*.H;*.HH;*.HPP;*.HXX|"
      CASE ".JAVA", ".JAD"
         strFilter += "Java Files (*.JAVA;*.JAD)|*.JAVA;*.JAD|"
      CASE ".JS"
         strFilter += "Java Script Files (*.JS)|*.JS|"
      CASE ".IDL", ".ODL"
         strFilter += "IDL Files (*.IDL;*.ODL)|*.IDL;*.ODL|"
   END SELECT
   strFilter += "All Files (*.*)|*.*"
   strDefExt = MID$(strExt, 2)

   dwStyle = %OFN_EXPLORER OR %OFN_FILEMUSTEXIST OR %OFN_HIDEREADONLY OR %OFN_OVERWRITEPROMPT
   IF ISFALSE(SaveFileDialog(hwnd, "", strPath, strInitialDir, strFilter, strDefExt, dwStyle)) THEN EXIT FUNCTION

   ' // Save the file
   TRY
      nFile = FREEFILE
      OPEN strPath FOR BINARY AS nFile
      PUT$ nFile, strText
      SETEOF nFile
   CATCH
      CSED_MsgBox(hwnd, "Error" & STR$(ERR) & " saving the file " & strPath, _
         %MB_OK OR %MB_ICONERROR, "Save File")
      EXIT FUNCTION
   FINALLY
      CLOSE nFile
   END TRY

   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Export the record
' ========================================================================================
SUB ExportCodeRecord (BYVAL hwnd AS DWORD)

   LOCAL Index AS LONG
   LOCAL RecordStr AS STRING
   LOCAL strName AS STRING
   LOCAL strText AS STRING

   IF ISFALSE hCodeFile THEN EXIT SUB
   Index = ListBox_GetCurSel(GetDlgItem(hwnd, %IDC_LBITEMS))
   IF Index = %LB_ERR THEN EXIT SUB
   strName = ListBox_GetText(GetDlgItem(hwnd, %IDC_LBITEMS), Index)
   IF LEN(strName) > 60 THEN strName = LEFT$(strName, 60)
   RecordStr = trm_GetEqualOrGreater(hCodeFile, 1, strName)
   IF UCASE$(TRIM$(LEFT$(RecordStr, 60))) = UCASE$(strName) THEN
      strText = RichEdit_GetText(GetDlgItem(hwnd, %IDC_RICHEDIT))
      CSED_ExportFile hwnd, strName, strText
   END IF

END SUB
' ========================================================================================

' ########################################################################################
' Main
' ########################################################################################
FUNCTION WinMain (BYVAL hInstance AS DWORD, BYVAL hPrevInstance AS DWORD, BYVAL lpszCmdLine AS ASCIIZ PTR, BYVAL nCmdShow AS LONG) AS LONG

   ' // Mutex to avoid multiple instances running
   LOCAL hWindow AS DWORD
   LOCAL hMutex AS DWORD
#IF %DEF(%UNICODE)
   LOCAL szMutex AS WSTRINGZ * 260
#ELSE
   LOCAL szMutex AS ASCIIZ * 260
#ENDIF
   szMutex = "CSED_BACKUPMGR_MUTEX"
   hMutex  = CreateMutex(BYVAL %NULL, %FALSE, szMutex)
   IF ISTRUE hMutex THEN
      IF GetLastError = %ERROR_ALREADY_EXISTS THEN
         CloseHandle hMutex
         hWindow = FindWindow(BYVAL %NULL, $PROGNAME)
         IF hWindow THEN SetForegroundWindow hWindow
         FUNCTION = -1
         EXIT FUNCTION
      END IF
   END IF

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' // Create the main window
   LOCAL hwnd AS DWORD
   hwnd = pWindow.CreateWindow(%NULL, $PROGNAME, 0, 0, 0, 0, _
      %WS_OVERLAPPED OR %WS_VISIBLE OR %WS_MINIMIZEBOX OR %WS_SYSMENU, _
      %WS_EX_WINDOWEDGE, CODEPTR(WndProc))
   pWindow.SetClientSize 692, 420
   ' // Center the window
   pWindow.CenterWindow hwnd

   ' // Set the icons
   pWindow.BigIcon = LoadIcon(hInstance, BYVAL %IDI_BACKUPMGR32)
   pWindow.SmallIcon = LoadIcon(hInstance, BYVAL %IDI_BACKUPMGR16)

   ' // Load the RichEdit library
   LOCAL hRichEdit AS DWORD
   hRichEdit = LoadLibrary("RICHED32.DLL")
   IF ISFALSE hRichEdit THEN
      MessageBox hwnd, "Unable to load RICHED32.DLL", "Error!", %MB_ICONERROR OR %MB_OK OR %MB_APPLMODAL
      EXIT FUNCTION
   END IF

   ' // Add the controls
   pWindow.AddStatusBar(hwnd, %IDC_STATUSBAR, "", 0, 0, 0, 0, %WS_CHILD OR %WS_VISIBLE OR %WS_CLIPCHILDREN OR %WS_CLIPSIBLINGS OR %CCS_BOTTOM)

   ' // Update the size of the statusbar
   SendMessage GetDlgItem(hwnd, %IDC_STATUSBAR), %WM_SIZE, 0, 0

   pWindow.AddLabel(hwnd, -1, "Records", 15, 14, 215, 15, -1, -1)

   pWindow.AddListBox(hwnd, %IDC_LBITEMS, "", 0, 0, 0, 0, %WS_CHILD OR %WS_VISIBLE OR %WS_HSCROLL OR %WS_VSCROLL OR %WS_BORDER OR %WS_TABSTOP OR _
      %LBS_EXTENDEDSEL OR %LBS_HASSTRINGS OR %LBS_SORT OR %LBS_NOTIFY OR %LBS_NOINTEGRALHEIGHT, -1)
   pWindow.SetWindowPos GetDlgItem(hwnd, %IDC_LBITEMS), %NULL, 15, 30, 215, 350, %SWP_NOZORDER
   ' // Adjust the height of the control so that the integral height
   ' // is based on the new font rather than the default SYSTEM_FONT
   SendMessage GetDlgItem(hwnd, %IDC_LBITEMS), %LB_SETHORIZONTALEXTENT, 600, 0

   pWindow.AddLabel(hwnd, -1, "Code", 240, 14, 440, 15, -1, -1)
   hRichEdit = pWindow.AddRichEdit(hwnd, %IDC_RICHEDIT, "", 240, 30, 440, 311, -1, -1)

   pWindow.AddButton(hwnd, %IDB_EXPORT, "&Export", 294, 355, 65, 26, -1, -1)
   pWindow.AddButton(hwnd, %IDB_DELETE, "&Delete", 374, 355, 65, 26, -1, -1)
   pWindow.AddButton(hwnd, %IDB_DELETEALL, "Delete &All", 454, 355, 65, 26, -1, -1)
   pWindow.AddButton(hwnd, %IDB_COPY, "&Copy", 534, 355, 65, 26, -1, -1)
   pWindow.AddButton(hwnd, %IDB_EXIT, "E&xit", 614, 355, 65, 26, -1, -1)

   LOCAL strDbPath AS STRING
   strDbPath = EXE.Path$ & "CSED_BACKUPMGR.TRM"
   IF ISFALSE ISFILE(strDbPath) THEN
      CSED_CreateBackupMgrDatabase(hwnd, strDbPath)
   END IF

   hCodeFile = trm_Open(strDbPath, %TRUE)
   IF hCodeFile < 1 THEN
      MessageBox hwnd, "Error opening " & strDbPath, "CSED Backup Files Manager", %MB_ICONERROR OR %MB_OK OR %MB_APPLMODAL
      IF hRichEdit THEN FreeLibrary hRichEdit
      EXIT FUNCTION
   END IF

   IF ISFALSE FillListBox(hwnd) THEN
      SetFocus GetDlgItem(hwnd, %IDC_LBITEMS)
   ELSE
      SetFocus GetDlgItem(hwnd, %IDC_LBITEMS)
      ListBox_SetCursel GetDlgItem(hwnd, %IDC_LBITEMS), 0
      RetrieveCodeRecord hwnd
   END IF

   ' // Default message pump
   pWindow.DoEvents(nCmdShow)

   ' // Close the Tsunami database file
   IF hCodeFile THEN trm_Close(hCodeFile)
   ' // Free the Rich Edit library
   IF hRichEdit THEN FreeLibrary hRichEdit

END FUNCTION
' ########################################################################################

' ========================================================================================
' Processes messages for the main window.
' ========================================================================================
FUNCTION WndProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL  Result  AS LONG     ' // Result code
   LOCAL  strText AS STRING
   STATIC hFocus  AS DWORD

   SELECT CASE uMsg

      CASE %WM_ACTIVATEAPP
         IF ISFALSE wParam THEN hFocus = GetFocus

      CASE %WM_SETFOCUS
         IF hFocus THEN
            PostMessage hwnd, %WM_USER + 999, hFocus, 0
            hFocus = 0
         ELSE
            ' // Set the keyboard focus to the first control that is
            ' // visible, not disabled, and has the WS_TABSTOP style
            SetFocus GetNextDlgTabItem(hwnd, %NULL, %FALSE)
         END IF

      CASE %WM_USER + 999
         IF ISTRUE wParam THEN SetFocus wParam

      CASE %WM_SIZE
         IF wParam <> %SIZE_MINIMIZED THEN
            ' // Update the size and position of aligned controls
            SendMessage GetDlgItem(hwnd, %IDC_STATUSBAR), %WM_SIZE, wParam, lParam
         END IF

      CASE %WM_SYSCOLORCHANGE
         ' // Forward this message to common controls so that they will
         ' // be properly updated when the user changes the color settings.
         SendMessage GetDlgItem(hwnd, %IDC_STATUSBAR), %WM_SYSCOLORCHANGE, wParam, lParam

      CASE %WM_COMMAND

       SELECT CASE LOWRD(wParam)

         CASE %IDCANCEL
            IF HI(WORD, wParam) = %BN_CLICKED THEN
               SendMessage hwnd, %WM_CLOSE, 0, 0
               EXIT FUNCTION
            END IF

         CASE %IDC_LBITEMS
            SELECT CASE HI(WORD, wParam)
               CASE %LBN_SELCHANGE
                  RetrieveCodeRecord hwnd
                  EXIT FUNCTION
            END SELECT

         CASE %IDB_EXPORT
            IF HI(WORD, wParam) = %BN_CLICKED THEN
               ExportCodeRecord(hwnd)
               EXIT FUNCTION
            END IF

         CASE %IDB_DELETE
            IF HI(WORD, wParam) = %BN_CLICKED THEN
               DeleteCodeRecord(hwnd)
               Statusbar_SetText(GetDlgItem(hwnd, %IDC_STATUSBAR), 0, "")
               SetFocus GetDlgItem(hwnd, %IDC_LBITEMS)
               EXIT FUNCTION
            END IF

         CASE %IDB_DELETEALL
            IF HI(WORD, wParam) = %BN_CLICKED THEN
               IF CSED_MsgBox(hwnd, "Are you sure you want to delete all the records?", _
                  %MB_YESNO OR %MB_ICONWARNING, "CSED Backup Manager") = %IDYES THEN
                  CSED_CreateBackupMgrDatabase(hwnd, EXE.Path$ & "CSED_BACKUPMGR.TRM")
                  ListBox_ResetContent GetDlgItem(hwnd, %IDC_LBITEMS)
                  RichEdit_SetText GetDlgItem(hwnd, %IDC_RICHEDIT), ""
               END IF
               EXIT FUNCTION
            END IF

         CASE %IDB_COPY
            IF HI(WORD, wParam) = %BN_CLICKED THEN
               strText = RichEdit_GetText(GetDlgItem(hwnd, %IDC_RICHEDIT))
               CLIPBOARD RESET
               CLIPBOARD SET TEXT strText, Result
               IF Result THEN Statusbar_SetText(GetDlgItem(hwnd, %IDC_STATUSBAR), 0, "Text copied to the clipboard")
               EXIT FUNCTION
            END IF

         CASE %IDB_EXIT
            IF HI(WORD, wParam) = %BN_CLICKED THEN
               SendMessage hwnd, %WM_CLOSE, 0, 0
               EXIT FUNCTION
            END IF

       END SELECT

      CASE %WM_DESTROY
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================