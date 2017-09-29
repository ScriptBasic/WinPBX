' ########################################################################################
' CSED Editor
' File: CSED_KBDMACROS.INC
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

$PROGNAME = "CSED Keyboard Macros"

' // Include files for external files
%USERICHEDIT = 1
#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "CWindow.inc"
#INCLUDE ONCE "CommCtrl.inc"
#INCLUDE ONCE "ListBoxCtrl.inc"
#INCLUDE ONCE "EditCtrl.inc"
#INCLUDE ONCE "StatusbarCtrl.inc"
#INCLUDE ONCE "CommDlg.inc"
#INCLUDE ONCE "trm.inc"

' // Resource file

' ========================================================================================
' Icon identifiers
' ========================================================================================
%IDI_KBDMACROS32 = 100
%IDI_KBDMACROS16 = 101
' ========================================================================================

#RESOURCE MANIFEST, 1, "CSED_KBDMACROS.xml"
#RESOURCE ICON,   100, "32_MACROS.ico"
#RESOURCE ICON,   101, "16_MACROS.ico"

' ========================================================================================
' Control identifiers
' ========================================================================================
ENUM CSED_KBDMACROS_ENUM SINGULAR
   IDC_STATUSBAR = 1001
   IDC_LBITEMS
   IDC_DESC
   IDC_RICHEDIT
   IDB_EXIT
   IDB_SAVE
   IDB_EXECUTE
   IDB_DELETE
   IDB_CLEAR
END ENUM
' ========================================================================================

' ========================================================================================
' Global handle
' ========================================================================================
GLOBAL hMacrosFile AS LONG
' ========================================================================================

' ========================================================================================
' Creates the Macros database
' ========================================================================================
FUNCTION CreateMacrosDatabase (BYVAL hwnd AS DWORD, BYVAL strDbPath AS STRING) AS LONG

   LOCAL strFileDef AS STRING
   LOCAL strKeys AS STRING
   LOCAL strSegment AS STRING * 25

   strSegment = "Macro Key"

   strFileDef = MKBYT$(1) & _     ' // Page Size
                MKBYT$(1) & _     ' // Compress Record
                MKBYT$(1)         ' // Number of Key Segments

   strKeys =    strSegment  & _   ' // Description
                MKBYT$(1)   & _   ' // Segment number
                MKWRD$(1)   & _   ' // Segment Offset
                MKBYT$(15)  & _   ' // Segment Size
                MKBYT$(2)         ' // Flags (No duplicates)

   strFileDef += strKeys

   FUNCTION = trm_Create(strDbPath, strFileDef, %FALSE)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Save the record
' ========================================================================================
FUNCTION SaveMacrosRecord (BYVAL hwnd AS DWORD) AS LONG

   LOCAL Result AS LONG
   LOCAL RecordStr AS STRING
   LOCAL strText AS STRING
   LOCAL strMacroKey AS STRING * 15
   LOCAL strMacroDesc AS STRING * 60
   LOCAL Index AS LONG

   ' // Get the selected name in the listbox
   Index = Listbox_GetCurSel(GetDlgItem(hwnd, %IDC_LBITEMS))
   strMacroKey = ListBox_GetText(GetDlgItem(hwnd, %IDC_LBITEMS), Index)
   IF ISNULL(strMacroKey) THEN
      MessageBox hwnd, "You must select a key", "CSED Macros", %MB_ICONERROR OR %MB_OK OR %MB_APPLMODAL
      EXIT FUNCTION
   END IF

   ' // Get the description of the macro
   strMacroDesc = Edit_GetText(GetDlgItem(hwnd, %IDC_DESC))
   ' // Read the content of the richedit box
   strText = Edit_GetText(GetDlgItem(hwnd, %IDC_RICHEDIT))

   ' // Fill the record setring
   RecordStr = strMacroKey & strMacroDesc & strText

   ' // Save/Update the record
   Result = trm_Insert(hMacrosFile, RecordStr)
   IF Result = 5 THEN        ' // Duplicate key value so use trm_Update.
      Result = trm_Update(hMacrosFile, RecordStr)
      Statusbar_SetText(GetDlgItem(hwnd, %IDC_STATUSBAR), 0, "Record updated")
   ELSEIF Result = 0 THEN
      Statusbar_SetText(GetDlgItem(hwnd, %IDC_STATUSBAR), 0, "Record added")
   END IF
   IF Result THEN
      MessageBox hwnd, "Error" & STR$(Result) & " saving the record", "CSED Macros", %MB_ICONERROR OR %MB_OK OR %MB_APPLMODAL
   END IF

   FUNCTION = Result

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieve the record
' ========================================================================================
FUNCTION RetrieveMacrosRecord (BYVAL hwnd AS DWORD) AS LONG

   LOCAL RecordStr AS STRING
   LOCAL strMacroKey AS STRING
   LOCAL Index AS LONG
   LOCAL strMacroDesc AS STRING

   Statusbar_SetText(GetDlgItem(hwnd, %IDC_STATUSBAR), 0, "")
   IF ISFALSE hMacrosFile THEN EXIT FUNCTION
   Index = Listbox_GetCurSel(GetDlgItem(hwnd, %IDC_LBITEMS))
   strMacroKey = ListBox_GetText(GetDlgItem(hwnd, %IDC_LBITEMS), Index)
   IF LEN(strMacroKey) > 15 THEN strMacroKey = LEFT$(strMacroKey, 15)
   RecordStr = trm_GetEqualOrGreater(hMacrosFile, 1, strMacroKey)
   IF UCASE$(TRIM$(LEFT$(RecordStr, 15))) = UCASE$(strMacroKey) THEN
      strMacroDesc = TRIM$(MID$(RecordStr, 16, 60))
      SetWindowText GetDlgItem(hwnd, %IDC_DESC), BYCOPY strMacroDesc
      SetWindowText GetDlgItem(hwnd, %IDC_RICHEDIT), MID$(RecordStr, 76)
   ELSE
      SetWindowText GetDlgItem(hwnd, %IDC_DESC), ""
      SetWindowText GetDlgItem(hwnd, %IDC_RICHEDIT), ""
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Delete the record
' ========================================================================================
FUNCTION DeleteMacrosRecord (BYVAL hwnd AS DWORD) AS LONG

   LOCAL RecordStr AS STRING
   LOCAL strMacroKey AS STRING
   LOCAL Index AS LONG
   LOCAL Result AS LONG

   IF ISFALSE hMacrosFile THEN EXIT FUNCTION
   Index = Listbox_GetCurSel(GetDlgItem(hwnd, %IDC_LBITEMS))
   strMacroKey = ListBox_GetText(GetDlgItem(hwnd, %IDC_LBITEMS), Index)
   IF LEN(strMacroKey) > 15 THEN strMacroKey = LEFT$(strMacroKey, 15)
   RecordStr = trm_GetEqualOrGreater(hMacrosFile, 1, strMacroKey)
   IF UCASE$(TRIM$(LEFT$(RecordStr, 15))) = UCASE$(strMacroKey) THEN
      Result = trm_Delete(hMacrosFile)
      IF Result = 0 THEN
         SetWindowText GetDlgItem(hwnd, %IDC_DESC), ""
         SetWindowText GetDlgItem(hwnd, %IDC_RICHEDIT), ""
         Statusbar_SetText(GetDlgItem(hwnd, %IDC_STATUSBAR), 0, "Record deleted")
      ELSE
         MessageBox hwnd, "Error" & STR$(Result) & " deleting the record", "CSED_Macros", %MB_ICONERROR OR %MB_OK OR %MB_APPLMODAL
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
   szMutex = "CSED_KBDMACROS_MUTEX"
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
   pWindow.SetClientSize 680, 410
   ' // Center the window
   pWindow.CenterWindow hwnd

   ' // Set the icons
   pWindow.BigIcon = LoadIcon(hInstance, BYVAL %IDI_KBDMACROS32)
   pWindow.SmallIcon = LoadIcon(hInstance, BYVAL %IDI_KBDMACROS16)

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

   pWindow.AddLabel(hwnd, -1, "Key", 15, 14, 80, 15, -1, -1)
   pWindow.AddListBox(hwnd, %IDC_LBITEMS, "", 15, 30, 80, 306, %WS_CHILD OR %WS_VISIBLE OR %WS_HSCROLL OR %WS_VSCROLL OR _
      %WS_BORDER OR %WS_TABSTOP OR %LBS_STANDARD OR %LBS_HASSTRINGS OR %LBS_SORT OR %LBS_NOTIFY OR %LBS_NOINTEGRALHEIGHT, -1)
   pWindow.AddLabel(hwnd, -1, "Description", 110, 14, 358, 15, -1, -1)

   hCtl = pWindow.AddTextBox(hwnd, %IDC_DESC, "", 110, 30, 556, 21, -1, -1)
   ' // Set the text limit
   SendMessage hCtl, %EM_SETLIMITTEXT, 60, 0

   pWindow.AddLabel(hwnd, -1, "Code", 110, 60, 358, 15, -1, -1)
   hRichEdit = pWindow.AddRichEdit(hwnd, %IDC_RICHEDIT, "", 110, 80, 556, 256, -1, -1)

   pWindow.AddButton(hwnd, %IDB_SAVE, "&Save", 362, 348, 65, 26, -1, -1)
   pWindow.AddButton(hwnd, %IDB_CLEAR, "&Clear", 442, 348, 65, 26, -1, -1)
   pWindow.AddButton(hwnd, %IDB_DELETE, "&Delete", 522, 348, 65, 26, -1, -1)
   pWindow.AddButton(hwnd, %IDB_EXIT, "E&xit", 602, 348, 65, 26, -1, -1)

   LOCAL strDbPath AS STRING
   strDbPath = EXE.Path$ & "CSED_KBDMACROS.TRM"
   IF ISFALSE ISFILE(strDbPath) THEN
      CreateMacrosDatabase(hwnd, strDbPath)
   END IF
   hMacrosFile = trm_Open(strDbPath, %TRUE)
   IF hMacrosFile < 1 THEN
      MessageBox hwnd, "Error opening " & strDbPath, "CSED Macros", %MB_ICONERROR OR %MB_OK OR %MB_APPLMODAL
      IF hRichEdit THEN FreeLibrary hRichEdit
      EXIT FUNCTION
   END IF

   ' // Fill the listbox
   LOCAL i AS LONG
   FOR i = 0 TO 9
      Listbox_AddString GetDlgItem(hwnd, %IDC_LBITEMS), "Alt" & FORMAT$(i)
      Listbox_AddString GetDlgItem(hwnd, %IDC_LBITEMS), "Ctrl" & FORMAT$(i)
   NEXT
   ListBox_SetCursel GetDlgItem(hwnd, %IDC_LBITEMS), 0
   RetrieveMacrosRecord hwnd
   SetFocus GetDlgItem(hwnd, %IDC_LBITEMS)

   ' // Default message pump
   pWindow.DoEvents(nCmdShow)

   ' // Close the Tsunami database file
   IF hMacrosFile THEN trm_Close(hMacrosFile)
   ' // F4ree the Rich Edit library
   IF hRichEdit THEN FreeLibrary hRichEdit

END FUNCTION
' ########################################################################################

' ========================================================================================
' Processes messages for the main window.
' ========================================================================================
FUNCTION WndProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   STATIC hFocus    AS DWORD

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
                  RetrieveMacrosRecord hwnd
                  EXIT FUNCTION
            END SELECT

         CASE %IDB_SAVE
            IF HI(WORD, wParam) = %BN_CLICKED THEN
               SaveMacrosRecord(hwnd)
               SetFocus GetDlgItem(hwnd, %IDC_LBITEMS)
               EXIT FUNCTION
            END IF

         CASE %IDOK
            IF HI(WORD, wParam) = %BN_CLICKED THEN
               IF GetFocus = GetDlgItem(hwnd, %IDC_DESC) THEN
                  SetFocus GetDlgItem(hwnd, %IDC_RICHEDIT)
               END IF
               EXIT FUNCTION
            END IF

         CASE %IDB_CLEAR
            IF HI(WORD, wParam) = %BN_CLICKED THEN
               SetWindowText GetDlgItem(hwnd, %IDC_RICHEDIT), ""
               Statusbar_SetText(GetDlgItem(hwnd, %IDC_STATUSBAR), 0, "")
               SetFocus GetDlgItem(hwnd, %IDC_RICHEDIT)
               EXIT FUNCTION
            END IF

         CASE %IDB_DELETE
            IF HI(WORD, wParam) = %BN_CLICKED THEN
               IF MessageBox(hwnd, "Are you sure you want to delete this macro?", "Delete Macro", %MB_YESNO OR %MB_APPLMODAL) = %IDYES THEN
                  DeleteMacrosRecord(hwnd)
                  SetWindowText GetDlgItem(hwnd, %IDC_DESC), ""
                  Statusbar_SetText(GetDlgItem(hwnd, %IDC_STATUSBAR), 0, "")
                  SetFocus GetDlgItem(hwnd, %IDC_LBITEMS)
               END IF
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

