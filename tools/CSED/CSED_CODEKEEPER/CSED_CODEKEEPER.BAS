' ########################################################################################
' CSED Editor
' File: CSED_CODEKEEPER.INC
' Contents: Code keeper database
' Copyright (c) 2011 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#COMPILE EXE
#DIM ALL
%UNICODE = 1

$PROGNAME = "CSED Code Keeper"


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
%IDI_CODEKEEPER32 = 100
%IDI_CODEKEEPER16 = 101
' ========================================================================================

#RESOURCE MANIFEST, 1, "CSED_CODEKEEPER.xml"
#RESOURCE ICON,   100, "32_CODEKEEPER.ico"
#RESOURCE ICON,   101, "16_CODEKEEPER.ico"

' ========================================================================================
' Control identifiers
' ========================================================================================
ENUM CSED_CODEKEEPER_ENUM SINGULAR
   IDC_STATUSBAR = 1001
   IDC_LBITEMS
   IDC_NAME
   IDC_RICHEDIT
   IDB_SAVE
   IDB_NEW
   IDB_DELETE
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
FUNCTION CSED_CreateCodeKeeperDatabase (BYVAL hWnd AS DWORD, BYVAL strDbPath AS STRING) AS LONG

   LOCAL strFileDef AS STRING
   LOCAL strKeys AS STRING
   LOCAL strSegment AS STRING * 25

   strSegment = "CodeKeeper Name"

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
   IF ISFILE(strDbPath) THEN
      IF CSED_MsgBox(hWnd, strDbPath & $CRLF & "File already exist. Overwrite it?", %MB_OK, "Warning!") = %IDYES THEN
         FUNCTION = trm_Create(strDbPath, strFileDef, %TRUE)
      ELSE
         EXIT FUNCTION
      END IF
   ELSE
      FUNCTION = trm_Create(strDbPath, strFileDef, %FALSE)
   END IF

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
' Save the record
' ========================================================================================
FUNCTION SaveCodeRecord (BYVAL hwnd AS DWORD) AS LONG

   LOCAL Result AS LONG
   LOCAL RecordStr AS STRING
   LOCAL strName AS STRING * 60
   LOCAL strText AS STRING
   LOCAL strRichText AS STRING
   LOCAL idx AS LONG

   strText = Edit_GetText(GetDlgItem(hwnd, %IDC_NAME))
   IF ISNULL(strText) THEN
      MessageBox hwnd, "The name must be filled", "CSED_CodeKeeper", %MB_ICONERROR OR %MB_OK OR %MB_APPLMODAL
      SetFocus GetDlgItem(hwnd, %IDC_NAME)
      EXIT FUNCTION
   END IF
   strName = strText
   strRichText = Edit_GetText(GetDlgItem(hwnd, %IDC_RICHEDIT))
   RecordStr = strName & strRichText
   Result = trm_Insert(hCodeFile, BYCOPY RecordStr)
   IF Result = 5 THEN   ' // Duplicate key
'      Result = trm_Delete(hCodeFile)
'      Result = trm_Insert(hCodeFile, BYCOPY RecordStr)
      Result = trm_Update(hCodeFile, BYCOPY RecordStr)
      Statusbar_SetText(GetDlgItem(hwnd, %IDC_STATUSBAR), 0, "Record updated")
      idx = ListBox_FindStringExact(GetDlgItem(hwnd, %IDC_LBITEMS), 0, strText)
      IF idx <> %LB_ERR THEN ListBox_SetCursel(GetDlgItem(hwnd, %IDC_LBITEMS), idx)
   ELSEIF Result = 0 THEN
      idx = ListBox_AddString(GetDlgItem(hwnd, %IDC_LBITEMS), strText)
      ListBox_SetCursel(GetDlgItem(hwnd, %IDC_LBITEMS), idx)
      Statusbar_SetText(GetDlgItem(hwnd, %IDC_STATUSBAR), 0, "Record added")
      RetrieveCodeRecord hwnd
   ELSE
      MessageBox hwnd, "Error" & STR$(Result) & " saving the record", "CSED_CodeKeeper", %MB_ICONERROR OR %MB_OK OR %MB_APPLMODAL
   END IF

   FUNCTION = Result

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
      SetWindowText GetDlgItem(hwnd, %IDC_NAME), BYCOPY strName
      SetWindowText GetDlgItem(hwnd, %IDC_RICHEDIT), MID$(RecordStr, 61)
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Delete the record
' ========================================================================================
FUNCTION DeleteCodeRecord (BYVAL hwnd AS DWORD) AS LONG

   LOCAL RecordStr AS STRING
   LOCAL strName AS STRING
   LOCAL Index AS LONG
   LOCAL Result AS LONG

   IF ISFALSE hCodeFile THEN EXIT FUNCTION
   Index = ListBox_GetCurSel(GetDlgItem(hwnd, %IDC_LBITEMS))
   strName = ListBox_GetText(GetDlgItem(hwnd, %IDC_LBITEMS), Index)
   IF LEN(strName) > 60 THEN strName = LEFT$(strName, 60)
   RecordStr = trm_GetEqualOrGreater(hCodeFile, 1, strName)
   IF UCASE$(TRIM$(LEFT$(RecordStr, 60))) = UCASE$(strName) THEN
      Result = trm_Delete(hCodeFile)
      IF Result = 0 THEN
         Statusbar_SetText(GetDlgItem(hwnd, %IDC_STATUSBAR), 0, "Record deleted")
         ListBox_DeleteString(GetDlgItem(hwnd, %IDC_LBITEMS), Index)
         ListBox_SetCursel(GetDlgItem(hwnd, %IDC_LBITEMS), 0)
         RetrieveCodeRecord(hwnd)
      ELSE
         MessageBox hwnd, "Error" & STR$(Result) & " deleting the record", "CSED_CodeKeeper", %MB_ICONERROR OR %MB_OK OR %MB_APPLMODAL
      END IF
   END IF

END FUNCTION
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
   szMutex = "CSED_CODEKEEPER_MUTEX"
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
   pWindow.BigIcon = LoadIcon(hInstance, BYVAL %IDI_CODEKEEPER32)
   pWindow.SmallIcon = LoadIcon(hInstance, BYVAL %IDI_CODEKEEPER16)

   ' // Load the RichEdit library
   LOCAL hRichEdit AS DWORD
   hRichEdit = LoadLibrary("RICHED32.DLL")
   IF ISFALSE hRichEdit THEN
      MessageBox hwnd, "Unable to load RICHED32.DLL", "Error!", %MB_ICONERROR OR %MB_OK OR %MB_APPLMODAL
      EXIT FUNCTION
   END IF

   ' // Add the controls
   LOCAL hCtl AS DWORD

   pWindow.AddStatusBar(hwnd, %IDC_STATUSBAR, "", 0, 0, 0, 0, %WS_CHILD OR %WS_VISIBLE OR %WS_CLIPCHILDREN OR %WS_CLIPSIBLINGS OR %CCS_BOTTOM)
   ' // Update the size of the statusbar
   SendMessage GetDlgItem(hwnd, %IDC_STATUSBAR), %WM_SIZE, 0, 0

   pWindow.AddLabel(hwnd, -1, "Records", 15, 14, 215, 15, -1, -1)

   pWindow.AddListBox(hwnd, %IDC_LBITEMS, "", 0, 0, 0, 0, %WS_CHILD OR %WS_VISIBLE OR %WS_HSCROLL OR %WS_VSCROLL OR %WS_BORDER OR %WS_TABSTOP OR _
      %LBS_HASSTRINGS OR %LBS_SORT OR %LBS_NOTIFY OR %LBS_NOINTEGRALHEIGHT, -1)
   pWindow.SetWindowPos GetDlgItem(hwnd, %IDC_LBITEMS), %NULL, 15, 30, 215, 350, %SWP_NOZORDER
   ' // Adjust the height of the control so that the integral height
   ' // is based on the new font rather than the default SYSTEM_FONT
   SendMessage GetDlgItem(hwnd, %IDC_LBITEMS), %LB_SETHORIZONTALEXTENT, 600, 0

   pWindow.AddLabel(hwnd, -1, "Name", 240, 14, 440, 15, -1, -1)

   hCtl = pWindow.AddTextBox(hwnd, %IDC_NAME, "", 240, 30, 440, 21, -1, -1)
   ' // Set the text limit
   SendMessage hCtl, %EM_SETLIMITTEXT, 60, 0

   pWindow.AddLabel(hwnd, -1, "Code", 240, 60, 440, 15, -1, -1)
   hRichEdit = pWindow.AddRichEdit(hwnd, %IDC_RICHEDIT, "", 240, 80, 440, 265, -1, -1)

   pWindow.AddButton(hwnd, %IDB_SAVE, "&Save", 294, 355, 65, 26, -1, -1)
   pWindow.AddButton(hwnd, %IDB_NEW, "&New", 374, 355, 65, 26, -1, -1)
   pWindow.AddButton(hwnd, %IDB_DELETE, "&Delete", 454, 355, 65, 26, -1, -1)
   pWindow.AddButton(hwnd, %IDB_COPY, "&Copy", 534, 355, 65, 26, -1, -1)
   pWindow.AddButton(hwnd, %IDB_EXIT, "E&xit", 614, 355, 65, 26, -1, -1)

   LOCAL strDbPath AS STRING
   strDbPath = EXE.Path$ & "CSED_CODEKEEPER.TRM"
   IF ISFALSE ISFILE(strDbPath) THEN
      CSED_CreateCodeKeeperDatabase(hwnd, strDbPath)
   END IF

   hCodeFile = trm_Open(strDbPath, %TRUE)
   IF hCodeFile < 1 THEN
      MessageBox hwnd, "Error opening " & strDbPath, "CSED Code Keeper", %MB_ICONERROR OR %MB_OK OR %MB_APPLMODAL
      IF hRichEdit THEN FreeLibrary hRichEdit
      EXIT FUNCTION
   END IF

   IF ISFALSE FillListBox(hwnd) THEN
      SetFocus GetDlgItem(hwnd, %IDC_NAME)
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

         CASE %IDOK, %IDB_SAVE
            IF HI(WORD, wParam) = %BN_CLICKED THEN
               SaveCodeRecord(hwnd)
               EXIT FUNCTION
            END IF

         CASE %IDB_NEW
            IF HI(WORD, wParam) = %BN_CLICKED THEN
               SetWindowText GetDlgItem(hwnd, %IDC_NAME), ""
               SetWindowText GetDlgItem(hwnd, %IDC_RICHEDIT), ""
               Statusbar_SetText(GetDlgItem(hwnd, %IDC_STATUSBAR), 0, "")
               ListBox_SetCursel GetDlgItem(hwnd, %IDC_LBITEMS), -1
               SetFocus GetDlgItem(hwnd, %IDC_NAME)
               EXIT FUNCTION
            END IF

         CASE %IDB_DELETE
            IF HI(WORD, wParam) = %BN_CLICKED THEN
               DeleteCodeRecord(hwnd)
               Statusbar_SetText(GetDlgItem(hwnd, %IDC_STATUSBAR), 0, "")
               SetFocus GetDlgItem(hwnd, %IDC_LBITEMS)
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
