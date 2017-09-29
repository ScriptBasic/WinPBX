' ########################################################################################
' CSED Editor
' File: CSED_COMPILE.INC
' Contents: Compilation related procedures
' Copyright (c) 2012 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ========================================================================================
' Save loaded files if needed
' ========================================================================================
SUB CSED_SaveLoadedFiles (BYVAL hwnd AS DWORD)

   LOCAL i          AS LONG      ' // Loop counter
   LOCAL hMdi       AS DWORD     ' // Child window handle
   LOCAL hSci       AS DWORD     ' // Handle of the edit control
   DIM   rghMdi(0)  AS DWORD     ' // Array of MDI child windows
#IF %DEF(%UNICODE)
   LOCAL strPath    AS WSTRING   ' // File path
#ELSE
   LOCAL strPath    AS STRING    ' // File path
#ENDIF

   ' // Get the handles of the MDI child windows
   hMdi = GetWindow(pSed.hwndClient, %GW_CHILD)
   IF hMdi = 0 THEN EXIT SUB
   rghMdi(0) = hMdi
   DO
      hMdi = GetWindow(hMdi, %GW_HWNDNEXT)
      IF hMdi = 0 THEN EXIT DO
      REDIM PRESERVE rghMdi(UBOUND(rghMdi) + 1)
      rghMdi(UBOUND(rghMdi)) = hMdi
   LOOP

   FOR i = LBOUND(rghMdi) TO UBOUND(rghMdi)
      hSci = GetDlgItem(rghMdi(i), %IDC_EDIT)
      IF hSci = 0 THEN ITERATE FOR
      IF SCI_GetModify(hSci) THEN
         strPath = AfxGetWindowText(rghMdi(i))
         ' // A previous saved file has a path in the child window
         ' // Path available?
         IF INSTR(strPath, ANY ":\/") = 0 THEN
            ' // No path - it is a new file - save with prompt, except untitled files
            IF LEFT$(UCASE$(PATHNAME$(NAMEX, strPath)), 8) <> "UNTITLED" THEN
               CSED_SaveFile(hwnd, hSci, %TRUE)
            END IF
         ELSE
            ' // Modified file found: save it
            CSED_SaveFile(hwnd, hSci, %FALSE)
         END IF
      END IF
   NEXT

   ' // Update the toolbars
   CSED_ChangeToolbarButtonsState
'   UpdateWindow pSed.hToolbar
'   UpdateWindow pSed.hBottomToolbar

END SUB
' ========================================================================================

' ========================================================================================
' Compiles a resource file
' ========================================================================================
#IF %DEF(%UNICODE)
SUB CSED_CompileResource (BYVAL hwnd AS DWORD, BYVAL hSci AS DWORD, BYVAL strPath AS WSTRING)
#ELSE
SUB CSED_CompileResource (BYVAL hwnd AS DWORD, BYVAL hSci AS DWORD, BYVAL strPath AS STRING)
#ENDIF

   LOCAL ExitCode     AS LONG                    ' // Exit code
   LOCAL sa           AS SECURITY_ATTRIBUTES     ' // Security attributes
   LOCAL hReadPipe    AS DWORD                   ' // Read pipe handle
   LOCAL hWritePipe   AS DWORD                   ' // Write pipe handle
   LOCAL SI           AS STARTUPINFO             ' // Startup info structure
   LOCAL pi           AS PROCESS_INFORMATION     ' // Process information structure
   LOCAL BytesRead    AS DWORD                   ' // Bytes read
   LOCAL BytesWritten AS DWORD                   ' // Bytes written
   LOCAL chBuf        AS ASCIIZ * 1024           ' // Character buffer
   LOCAL chEOF        AS ASCIIZ * 12             ' // End of file
#IF %DEF(%UNICODE)
   LOCAL szDir        AS WSTRINGZ * %MAX_PATH    ' // Directory
   LOCAL szCmdLine    AS WSTRINGZ * %MAX_PATH    ' // Command line
   LOCAL Result       AS WSTRING                 ' // Result string
   LOCAL strCommand   AS WSTRING                 ' // Command line
#ELSE
   LOCAL szDir        AS ASCIIZ * %MAX_PATH      ' // Directory
   LOCAL szCmdLine    AS ASCIIZ * %MAX_PATH      ' // Command line
   LOCAL Result       AS STRING                  ' // Result string
   LOCAL strCommand   AS STRING                  ' // Command line
#ENDIF

   IF ISNULL(strPath) THEN EXIT SUB
   IF UCASE$(RIGHT$(strPath, 3)) = ".RC" THEN
      strPath = LEFT$(strPath, LEN(strPath) - 3) & ".rc"
   END IF

   IF SCI_GetModify(hSci) THEN
      IF ISFALSE CSED_SaveFile(hwnd, hSci, %FALSE) THEN
         SetFocus hSci
         EXIT SUB
      END IF
      IF ToolBar_IsButtonEnabled(pSed.hToolbar, %IDM_SAVE) THEN
         Toolbar_EnableButton(pSed.hToolbar, %IDM_SAVE)
      END IF
      UpdateWindow pSed.hToolbar
      ' // Reread the caption (the path can be different)
      strPath = AfxGetWindowText(GetParent(hSci))
   END IF

   szDir = UCASE$(PATHNAME$(PATH, strPath))
   IF szDir <> UCASE$(CURDIR$) THEN CHDIR szDir

   IF LEN(pSed.RCPath) THEN
      szCmdLine =  pSed.RCPath & " /R"
   ELSE
      MessageBox(hwnd, "You must set the path of the resource compiler", "", _
                 %MB_OK OR %MB_ICONINFORMATION OR %MB_APPLMODAL)
      EXIT SUB
   END IF

   IF pSed.SelectedHeaders = 1 OR pSed.SelectedHeaders = 0 THEN
      IF LEN(pSed.JRSIncPath1) THEN
         szCmdLine = szCmdLine & " /I " & $DQ & pSed.JRSIncPath1 & $DQ
      ELSE
         MessageBox(hwnd, "You must set the path of the include file", "", _
                    %MB_OK OR %MB_ICONINFORMATION OR %MB_APPLMODAL)
         EXIT SUB
      END IF
   ELSEIF pSed.SelectedHeaders = 2 THEN
      IF LEN(pSed.JRSIncPath2) THEN
         szCmdLine = szCmdLine & " /I " & $DQ & pSed.JRSIncPath2 & $DQ
      ELSE
         MessageBox(hwnd, "You must set the path of the include file", "", _
                    %MB_OK OR %MB_ICONINFORMATION OR %MB_APPLMODAL)
         EXIT SUB
      END IF
   ELSEIF pSed.SelectedHeaders = 3 THEN
      IF LEN(pSed.PBIncPath1) THEN
         szCmdLine = szCmdLine & " /I " & $DQ & pSed.PBIncPath1 & $DQ
      ELSE
         MessageBox(hwnd, "You must set the path of the include file", "", _
                    %MB_OK OR %MB_ICONINFORMATION OR %MB_APPLMODAL)
         EXIT SUB
      END IF
   ELSEIF pSed.SelectedHeaders = 4 THEN
      IF LEN(pSed.PBIncPath2) THEN
         szCmdLine = szCmdLine & " /I " & $DQ & pSed.PBIncPath2 & $DQ
      ELSE
         MessageBox(hwnd, "You must set the path of the include file", "", _
                    %MB_OK OR %MB_ICONINFORMATION OR %MB_APPLMODAL)
         EXIT SUB
      END IF
   END IF

   ' // Update the client area of the control before calling CreateProcess
   UpdateWindow hSci

   sa.nLength = SIZEOF(SECURITY_ATTRIBUTES)
   sa.bInheritHandle = %TRUE

   IF CreatePipe(hReadPipe, hWritePipe, sa, BYVAL 0) = 0 THEN EXIT SUB

   SI.cb          = SIZEOF(STARTUPINFO)
   SI.dwFlags     = %STARTF_USESHOWWINDOW OR %STARTF_USESTDHANDLES
   SI.wShowWindow = %SW_HIDE
   SI.hStdOutput  = hWritePipe
   SI.hStdError   = hWritePipe

   szCmdLine += " " & $DQ & strPath & $DQ

   IF CreateProcess ("", szCmdLine, BYVAL 0&, BYVAL 0&, 1,  %NORMAL_PRIORITY_CLASS, _
        BYVAL 0&, "", si, pi) = 0 THEN EXIT SUB

   WaitForSingleObject PI.hProcess, 15000
   GetExitCodeProcess PI.hProcess, ExitCode
   IF ExitCode = %STILL_ACTIVE THEN TerminateProcess pi.hProcess, 0

   chEOF = "End Of Pipe"
   Result = ""

   DO
      IF WriteFile(hWritePipe, chEOF, LEN(chEOF), BytesWritten, BYVAL 0) = 0 THEN  EXIT DO
      IF BytesWritten <> LEN(chEOF) THEN  EXIT DO
      DO
         IF ReadFile(hReadPipe, chBuf, SIZEOF(chBuf), BytesRead, BYVAL 0) = 0 THEN EXIT DO
         IF BytesRead = 0 THEN EXIT DO
         Result += LEFT$(chBuf, BytesRead)
         IF RIGHT$(Result, LEN(chEOF)) = chEOF THEN
            Result = LEFT$(Result, LEN(Result) - LEN(chEOF))
            EXIT DO
         END IF
      LOOP
      EXIT DO
   LOOP

   CloseHandle hReadPipe
   CloseHandle hWritePipe
   CloseHandle pi.hThread
   CloseHandle pi.hProcess

   UpdateWindow hSci

   IF LEN(Result) THEN
      CSED_MsgBox hwnd, TRIM$(Result, ANY CHR$(32, 0, 13, 10)), %MB_OK OR %MB_ICONINFORMATION
   ELSE
      CSED_MsgBox hwnd, "Resource file compiled", %MB_OK OR %MB_ICONINFORMATION
   END IF

END SUB
' ========================================================================================

' ========================================================================================
' Displays compiler results.
' Returns %TRUE if there have been errors, or %FALSE otherwise.
' ========================================================================================
#IF %DEF(%UNICODE)
FUNCTION CSED_CheckCompilerResults (BYVAL hwnd AS DWORD, BYVAL hSci AS DWORD, BYVAL strPath AS WSTRING, BYVAL strActiveFileName AS WSTRING) AS LONG
#ELSE
FUNCTION CSED_CheckCompilerResults (BYVAL hwnd AS DWORD, BYVAL hSci AS DWORD, BYVAL strPath AS STRING, BYVAL strActiveFileName AS STRING) AS LONG
#ENDIF

   LOCAL i          AS LONG      ' // Loop counter
   LOCAL p1         AS LONG      ' // General purpose variable
   LOCAL p2         AS LONG      ' // General purpose variable
   LOCAL hLogFile   AS LONG      ' // Handle of the log file
   LOCAL hMdi       AS DWORD     ' // Handle of the MDI window
   LOCAL nTab       AS LONG      ' // Tab number
   LOCAL endPos     AS LONG      ' // Ending position
   LOCAL errPos     AS LONG      ' // "Error" string position
   LOCAL nPos       AS LONG      ' // Position
   LOCAL nLin       AS LONG      ' // Number of line
   LOCAL nCol       AS LONG      ' // Number of column
   LOCAL strLogFile AS STRING    ' // Text of the log file
   LOCAL buffer     AS STRING    ' // buffer
   LOCAL strResult  AS STRING    ' // Result to display
   LOCAL strText    AS STRING    ' // General purpose variable
   LOCAL bFound     AS LONG      ' // Boolean

   ' // Read the log file
   strLogFile = UCASE$(strPath)
   REPLACE ".BAS" WITH ".LOG" IN strLogFile
   IF ISFALSE ISFILE(strLogFile) THEN EXIT FUNCTION
   hLogFile = FREEFILE
   OPEN strLogFile FOR BINARY AS hLogFile
   IF ERR THEN
      MessageBox(hwnd, "Error" & STR$(ERR) & " opening the log file", _
         "Log File", %MB_OK OR %MB_ICONERROR OR %MB_APPLMODAL)
   ELSE
      GET$ hLogFile, LOF(hLogFile), buffer
      CLOSE hLogFile
   END IF
   ' // Delete the log file
   IF pSed.DeleteLogFile = %BST_CHECKED THEN KILL strLogFile

   ' // Search for errors
   errPos = INSTR(buffer, $CRLF & "Error ")
   ' // Return %TRUE if there have been errors
   IF errPos THEN FUNCTION = %TRUE

   ' // Display results
   IF ISFALSE errPos THEN
      FOR i = LEN(buffer) TO 1 STEP -1
         IF MID$(buffer, i, 1) <> $CR AND MID$(buffer, i, 1) <> $LF AND MID$(buffer, i, 1) <> " " THEN
            buffer = LEFT$(buffer, i)
            EXIT FOR
         END IF
      NEXT
      ' // Store the result
      pSed.CompilerResults = buffer
      ' // Remove the list of component files
      IF pSed.DisplayResults = %BST_CHECKED THEN
         strResult = buffer
         nPos = INSTR(strResult, "Component Files:")
         IF nPos THEN strResult = LEFT$(strResult, nPos - 1)
         CSED_MsgBox(hwnd, strResult, %MB_OK OR %MB_ICONINFORMATION, "Compiler results")
      END IF
      ' // Restore active child to original
      ' // First look at already loaded files
      hMdi = GetWindow(pSed.hwndClient, %GW_CHILD)
      WHILE hMdi
         strPath = AfxGetWindowText(hMdi)
         ' // If already loaded...
         IF UCASE$(strPath) = UCASE$(strActiveFileName) THEN
            nTab = CSED_GetTabNumberFromPath(strPath)
            IF nTab > -1 THEN
               ' ... activate the tab associated with the window
               TabCtrl_SetCurSel(pSed.hTabMdi, nTab)
               ' ... activate the child MDI window
               MdiActivate(pSed.hwndClient, hMdi)
            END IF
         END IF
         hMdi = GetWindow(hMdi, %GW_HWNDNEXT)
      WEND
      ' // Set the focus on the edit control
      SetFocus hSci
      EXIT FUNCTION
   END IF

   ' // Display the error
   strText = MID$(buffer, errPos)
   p1 = INSTR(strText, "(")
   IF p1 THEN p2 = INSTR(p1 + 1, strText, ")")
   IF p2 THEN strText = MID$(strText, p1 + 1, p2 - 1)
   p1 = INSTR(strText, ":")
   IF p1 THEN
      nLin = VAL(LEFT$(strText, p1 - 1))
      nCol = VAL(MID$(strText, p1 + 1))
   END IF

   ' // Allow for Error 496 Destination File Write Error
   IF nLin <> 0 OR nCol <> 0 THEN
      ' // If it is an untitled file it must be in the active window
      IF (INSTR(strActiveFileName, ANY ":\/") <> 0) AND (LEFT$(UCASE$(PATHNAME$(NAMEX, strActiveFileName)), 8) <> "UNTITLED") THEN
         ' // Search for filename in error line
         p1 = INSTR(buffer, $CRLF & "Error ")
         strText = MID$(buffer, p1)
         strText = PARSE$(strText, "(", 1)       ' // Get left side
         strText = PARSE$(strText, " in ", 2)    ' // Get right side
         IF INSTR(strText, ANY ":\/") = 0 THEN strText = CURDIR$ & "\" & strText
         strText = UCASE$(strText)
         ' // Search for matching window
         hMdi = GetWindow(pSed.hwndClient, %GW_CHILD)
         strPath = AfxGetWindowText(hMdi)
         IF strText <> UCASE$(strPath) THEN
            DO
               hMdi = GetWindow(hMdi, %GW_HWNDNEXT)
               IF hMdi = 0 THEN EXIT DO
               strPath = AfxGetWindowText(hMdi)
               IF strText = UCASE$(strPath) THEN
                  ' // Switch to child handle on match
                  nTab = CSED_GetTabNumberFromPath(strPath)
                  IF nTab > -1 THEN
                     TabCtrl_SetCurSel(pSed.hTabMdi, nTab)
                     MdiActivate(pSed.hwndClient, hMdi)
                     bFound = %TRUE
                  END IF
                  ' // Exit the loop
                  EXIT DO
               END IF
            LOOP
            ' // If not found, load the file in a new window
            IF ISFALSE bFound THEN
               ' // Path available?
               IF INSTR(strText, "\") THEN
                  hMdi = CSED_OpenFile(strText)
               ELSE
                  ' // No path available: Use current path
                  hMdi = CSED_OpenFile(CURDIR$ + "\" + strText)
               END IF
            END IF
         END IF
      END IF
      ' // Get the handle of the edit control
      IF hMdi THEN hSci = GetDlgItem(hMdi, %IDC_EDIT) ELSE hSci = pSed.hEdit
      ' // Set the cursor position in the error line
      IF hSci THEN
         ' // End position = length of the document
         endPos = SCI_GetTextLength(hSci)
         ' // Set pointer the end position of document
         SCI_GotoLine(hSci, endPos)
         ' / Go to Error position
         nPos = SCI_PositionFromLine(hSci, nLin - 1)
         nPos += nCol - 1
         SCI_GotoLine(hSci, SCI_LineFromPosition(hSci, nPos) - (SCI_LinesOnScreen(hSci) \ 2))
         SCI_GotoPos(hSci, nPos)
      END IF
   END IF

   ' // Remove trailing $CR, $LF and spaces
   FOR i = LEN(buffer) TO 1 STEP -1
      IF MID$(buffer, i, 1) <> $CR AND MID$(buffer, i, 1) <> $LF AND MID$(buffer, i, 1) <> " " THEN
         buffer = LEFT$(buffer, i)
         EXIT FOR
      END IF
   NEXT
   ' // Display the error text
   CSED_MsgBox hwnd, buffer, %MB_OK OR %MB_ICONERROR, "Compilation error"

   ' // Set the focus on the edit control
   SetFocus hSci

END FUNCTION
' ========================================================================================

' ========================================================================================
' Compiles the program
' ========================================================================================
SUB CSED_CompileBasFile (BYVAL hwnd AS DWORD, BYVAL hSci AS DWORD, BYVAL cID AS DWORD)

   LOCAL r                 AS LONG                   ' // Result code
   LOCAL p                 AS LONG                   ' // General purpose variable
   LOCAL p2                AS LONG                   ' // General purpose variable
   LOCAL nLin              AS LONG                   ' // Number of line
   LOCAL nLen              AS LONG                   ' // Length
   LOCAL x                 AS LONG                   ' // Starting position of a word
   LOCAL nFile             AS LONG                   ' // File number

#IF %DEF(%UNICODE)
   LOCAL strActiveFileName AS WSTRING                ' // File path
   LOCAL strPath           AS WSTRING                ' // Path
   LOCAL strDir            AS WSTRING                ' // Folder
   LOCAL strCurDir         AS WSTRING                ' // Current directory
   LOCAL szTempPath        AS WSTRINGZ * %MAX_PATH   ' // Path of the temporary folder
#ELSE
   LOCAL strActiveFileName AS STRING                 ' // File path
   LOCAL strPath           AS STRING                 ' // Path
   LOCAL strDir            AS STRING                 ' // Folder
   LOCAL strCurDir         AS STRING                 ' // Current directory
   LOCAL szTempPath        AS ASCIIZ * %MAX_PATH     ' // Path of the temporary folder
#ENDIF
   LOCAL strCommand        AS STRING                 ' // Command line
   LOCAL strExeFile        AS STRING                 ' // Compiled file path
   LOCAL strFileName       AS STRING                 ' // File name
   LOCAL buffer            AS STRING                 ' // General purpose buffer
   LOCAL strText           AS STRING                 ' // General purpose variable
   LOCAL strIncPath        AS STRING                 ' // Include path
   LOCAL strLine           AS STRING                 ' // Line of text

   ' // Save loaded files if needed
   CSED_SaveLoadedFiles(hwnd)

   ' // Store active child name to restore after compiling
   strActiveFileName = AfxGetWindowText(MdiGetActive(pSed.hwndClient))
   IF (INSTR(strActiveFileName, ANY ":\/") = 0) AND (LEFT$(UCASE$(PATHNAME$(NAMEX, strActiveFileName)), 8) = "UNTITLED") THEN
      strPath = strActiveFileName
      strCurDir = CURDIR$
      IF ISFALSE CSED_SaveUntitledFile(hwnd, hSci, strPath) THEN EXIT SUB
   ELSE
      strPath = strActiveFileName
   END IF
   IF LEN(strPath) = 0 THEN EXIT SUB
   IF RIGHT$(UCASE$(strPath), 4) <> ".BAS" THEN
      MessageBox(hwnd, "This is not a .BAS file", "Compile error", %MB_OK OR %MB_ICONERROR OR %MB_APPLMODAL)
      EXIT SUB
   END IF

   ' // Check if the user has defined the compiler in the code
   nLen = SCI_GetTextLength(hSci)
   buffer = SCI_GetText(hSci)
   IF INSTR(buffer, "SED_PBWIN") OR INSTR(buffer, "CSED_PBWIN") THEN
      IF pSed.SelectedCompiler <> 1 THEN
         pSed.SelectedCompiler = 1
         StatusBar_SetText(pSed.hStatusbar, 3, "PBWIN")
      END IF
   ELSEIF INSTR(buffer, "SED_PBCC") OR INSTR(buffer, "CSED_PBCC") THEN
      IF pSed.SelectedCompiler <> 2 THEN
         pSed.SelectedCompiler = 2
         StatusBar_SetText(pSed.hStatusbar, 3, "PBCC")
      END IF
   END IF

   ' // Check if there is an override for the includes path
   strIncPath = ""
   SCI_SetTargetStart(hSci, 0)
   SCI_SetTargetEnd(hSci, SCI_GetTextLength(hSci))
   strText = "$CSED_INCPATH"
   r = SCI_SearchInTarget(hSci, strText)
   WHILE CINT(r) <> -1
      nLin = SCI_LineFromPosition(hSci, r)
      nLen = SCI_LineLength(hSci, nLin)
      strLine = TRIM$(UCASE$(SCI_GetLine(hSci, nLin)))
      IF LEFT$(strLine, 1) = "'" OR LEFT$(UCASE$(strLine), 3) = "REM" THEN
         nLin = SCI_PositionFromLine(hSci, nLin + 1)
         SCI_SetTargetStart(hSci, nLin)
         SCI_SetTargetEnd(hSci, SCI_GetTextLength(hSci))
         r = SCI_SearchInTarget(hSci, strText)
      ELSE
         p = INSTR(strLine, """")
         IF p THEN
            strLine = MID$(strLine, p + 1)
            p = INSTR(2, strLine, """")
            IF p THEN
               strIncPath = LEFT$(strLine, p - 1)
'               IF ISFALSE AfxFolderExists(strIncPath) THEN
'                  MessageBox(hwnd, "The folder """ & strIncPath & """ doesn't exist." & $CRLF & _
'                             "The default folder for include files will be used.", "CSED_CompileBasFile", _
'                             %MB_OK OR %MB_ICONERROR OR %MB_APPLMODAL)
'                  strIncPath = ""
'               END IF
            END IF
         END IF
         r = -1
      END IF
   WEND

   ' // Check if there is an override for the includes path using $SED_INCPATH instead of $CSED_INCPATH
   IF strIncPath = "" THEN
      strIncPath = ""
      SCI_SetTargetStart(hSci, 0)
      SCI_SetTargetEnd(hSci, SCI_GetTextLength(hSci))
      strText = "$SED_INCPATH"
      r = SCI_SearchInTarget(hSci, strText)
      WHILE CINT(r) <> -1
         nLin = SCI_LineFromPosition(hSci, r)
         nLen = SCI_LineLength(hSci, nLin)
         strLine = TRIM$(UCASE$(SCI_GetLine(hSci, nLin)))
         IF LEFT$(strLine, 1) = "'" OR LEFT$(UCASE$(strLine), 3) = "REM" THEN
            nLin = SCI_PositionFromLine(hSci, nLin + 1)
            SCI_SetTargetStart(hSci, nLin)
            SCI_SetTargetEnd(hSci, SCI_GetTextLength(hSci))
            r = SCI_SearchInTarget(hSci, strText)
         ELSE
            p = INSTR(strLine, """")
            IF p THEN
               strLine = MID$(strLine, p + 1)
               p = INSTR(2, strLine, """")
               IF p THEN
                  strIncPath = LEFT$(strLine, p - 1)
                  IF ISFALSE AfxFolderExists(strIncPath) THEN
                     MessageBox(hwnd, "The folder """ & strIncPath & """ doesn't exist." & $CRLF & _
                                "The default folder for include files will be used.", "CSED_CompileBasFile", _
                                %MB_OK OR %MB_ICONERROR OR %MB_APPLMODAL)
                     strIncPath = ""
                  END IF
               END IF
            END IF
            r = -1
         END IF
      WEND
   END IF

   ' // Compile and debug
   IF cID = %IDM_COMPILEANDDEBUG THEN
      CSED_CompileAndDebug(hwnd, strPath)
      EXIT SUB
   END IF

   ' // Refresh the toolbar
   UpdateWindow pSed.hToolbar
   ' // Hour glass mouse
   MOUSEPTR 11

   ' // Change the directory
   strDir = PATHNAME$(PATH, strPath)
   IF strDir <> CURDIR$ THEN CHDIR strDir

   ' // Prepare the command line and compile the program
   IF hSci THEN
      IF LEN(strPath) THEN
         IF pSed.SelectedCompiler = 1 OR pSed.SelectedCompiler = 2 THEN
            strCommand = ""
            IF LEN(strIncPath) THEN
               strCommand = strIncPath
            ELSE
               IF pSed.SelectedHeaders = 1 OR pSed.SelectedHeaders = 0 THEN
                  strCommand = pSed.JRSIncPath1
               ELSEIF pSed.SelectedHeaders = 2 THEN
                  strCommand = pSed.JRSIncPath2
               ELSEIF pSed.SelectedHeaders = 3 THEN
                  strCommand = pSed.PBIncPath1
               ELSEIF pSed.SelectedHeaders = 4 THEN
                  strCommand = pSed.PBIncPath2
               END IF
            END IF
            IF LEN(strCommand) THEN
               ' // Add double quotes to deal with long filenames
               REPLACE ";" WITH $DQ & ";" & $DQ IN strCommand
               strCommand = $DQ & strCommand
               IF RIGHT$(strCommand, 1) <> $DQ THEN strCommand += $DQ
            END IF
            IF LEN(strCommand) THEN
               ' // Search for #COMPILE to see if there is a name for the file
               buffer = ""
               SCI_SetTargetStart(hSci, 0)
               SCI_SetTargetEnd(hSci, SCI_GetTextLength(hSci))
               strText = "#COMPILE "
               r = SCI_SearchInTarget(hSci, strText)
               WHILE CINT(r) <> -1
                  nLin = SCI_LineFromPosition(hSci, r)
                  nLen = SCI_LineLength(hSci, nLin)
                  buffer = SCI_GetLine(hSci, nLin)
                  x = INSTR(UCASE$(buffer),"#COMPILE ")
                  IF INSTR(MID$(buffer, 1, x - 1), "'") <> 0 AND INSTR(MID$(buffer, 1, x - 1), "REM") <> 0 THEN
                     nLin = SCI_PositionFromLine(hSci, nLin + 1)
                     SCI_SetTargetStart(hSci, nLin)
                     SCI_SetTargetEnd(hSci, SCI_GetTextLength(hSci))
                     r = SCI_SearchInTarget(hSci, strText)
                  ELSE
                     buffer = UCASE$(TRIM$(buffer, ANY CHR$(32, 9, 13, 10)))
                     buffer = TRIM$(REMOVE$(buffer, "#COMPILE "))
                     IF LEFT$(buffer, 3) = "EXE" OR LEFT$(buffer, 3) = "CON" THEN
                        IF LEFT$(buffer, 3) = "CON" THEN
                           pSed.SelectedCompiler = 2
                           StatusBar_SetText(pSed.hStatusbar, 3, "PBCC")
                        END IF
                        buffer = TRIM$(MID$(buffer, 4))
                        ' // Some people put comments after #COMPILE EXE!
                        p = INSTR(buffer, "'")
                        IF p THEN
                           buffer = LEFT$(buffer, p - 1)
                           buffer = TRIM$(buffer)
                        END IF
                        strExeFile = REMOVE$(buffer, $DQ)
                        IF LEN(strExeFile) AND RIGHT$(strExeFile, 4) <> ".EXE" THEN
                           strExeFile = PATHNAME$(PATH, strPath) + strExeFile + ".EXE"
                        END IF
                        IF strExeFile = "" THEN strExeFile = UCASE$(strPath)
                        REPLACE ".BAS" WITH ".EXE" IN strExeFile
                     ELSEIF LEFT$(buffer, 3) = "DLL" THEN
                        buffer = TRIM$(MID$(buffer, 4))
                        ' // Some people put comments after #COMPILE DLL!
                        p = INSTR(buffer, "'")
                        IF p THEN
                           buffer = LEFT$(buffer, p - 1)
                           buffer = TRIM$(buffer)
                        END IF
                        strExeFile = REMOVE$(buffer, $DQ)
                        IF LEN(strExeFile) AND RIGHT$(strExeFile, 4) <> ".DLL" THEN
                           strExeFile = PATHNAME$(PATH, strPath) + strExeFile + ".DLL"
                        END IF
                        IF strExeFile = "" THEN strExeFile = UCASE$(strPath)
                        REPLACE ".BAS" WITH ".DLL" IN strExeFile
                        pSed.SelectedCompiler = 1
                        StatusBar_SetText(pSed.hStatusbar, 3, "PBWIN")
                     ELSEIF LEFT$(buffer, 3) = "SLL" THEN
                        buffer = TRIM$(MID$(buffer, 4))
                        ' // Some people put comments after #COMPILE DLL!
                        p = INSTR(buffer, "'")
                        IF p THEN
                           buffer = LEFT$(buffer, p - 1)
                           buffer = TRIM$(buffer)
                        END IF
                        strExeFile = REMOVE$(buffer, $DQ)
                        IF LEN(strExeFile) AND RIGHT$(strExeFile, 4) <> ".SLL" THEN
                           strExeFile = PATHNAME$(PATH, strPath) + strExeFile + ".SLL"
                        END IF
                        IF strExeFile = "" THEN strExeFile = UCASE$(strPath)
                        REPLACE ".BAS" WITH ".SLL" IN strExeFile
                     END IF
                     r = -1
                  END IF
               WEND
               IF pSed.SelectedCompiler = 1 THEN
                  strCommand = pSed.PBWINPath & " /I" & strCommand
               ELSE
                  strCommand = pSed.PBCCPath & " /I" & strCommand
               END IF
               IF strExeFile = "" THEN
                  strExeFile = UCASE$(strPath)
                  REPLACE ".BAS" WITH ".EXE" IN strExeFile
               END IF
               ' // Include the path between quotes to deal with long filenames
               strExeFile = $DQ & strExeFile & $DQ
               ' // If compile or compile and run
               strText = ""
               IF cID <> %IDM_EXECUTE THEN
                  ' // If long file name, include the name between quotes
                  strFileName = PATHNAME$(NAMEX, strPath)
                  IF INSTR(strFileName, " ") THEN strFileName = $DQ & strFileName & $DQ
                  ' // Don't show results - we will show our own messages
                  strCommand += " /Q"
                  ' // Create log file
                  strCommand += " /L " & strFileName
                  ' // Update the client area of the control before shelling
                  UpdateWindow hSci
                  ' // if the command line exceeds 255 characters...
                  IF LEN(strCommand) > 255 THEN
                     ' // ...save it in a temporary file...
                     GetTempPath(%MAX_PATH, szTempPath)
                     nFile = FREEFILE
                     OPEN szTempPath & "PBCMDLINE.TXT" FOR OUTPUT AS #nFile
                     PRINT #nFile, strCommand
                     CLOSE #nFile
                     ' // ...and call the compiler using the /C switch
                     IF pSed.SelectedCompiler = 1 THEN
                        SHELL pSed.PBWINPath & " /C" & szTempPath & "PBCMDLINE.TXT"
                     ELSE
                        SHELL pSed.PBCCPath & " /C" & szTempPath & "PBCMDLINE.TXT"
                     END IF
                  ELSE
                     ' // Call the compiler
                     SHELL strCommand
                  END IF
                  ' // Beep on completion
                  IF pSed.BeepOnCompletion = %BST_CHECKED THEN BEEP
                  ' // Display compiler results
                  r = CSED_CheckCompilerResults(hwnd, hSci, strPath, strActiveFileName)
               END IF
               ' // Run the Exe file
               IF r = 0 OR cID = %IDM_EXECUTE THEN  ' If no errors run the exe or option = execute without compiling
                  IF cID = %IDM_COMPILEANDRUN OR cID = %IDM_EXECUTE THEN
                     strExeFile = REMOVE$(strExeFile, $DQ)  ' Remove quotes
                     IF RIGHT$(strExeFile, 4) <> ".EXE" THEN
                        IF cID = %IDM_EXECUTE THEN
                           MessageBox(hwnd, "Can't run " & RIGHT$(strExeFile, 4) & " files", "", _
                              %MB_OK OR %MB_ICONINFORMATION OR %MB_APPLMODAL)
                        END IF
                     ELSE
                        IF ISFALSE ISFILE(strExeFile) THEN
                           MessageBox(hwnd, "Can't find the file " & strExeFile, "", _
                           %MB_OK OR %MB_ICONINFORMATION OR %MB_APPLMODAL)
                        ELSE
                           strCommand = strExeFile
                           IF LEN(pSed.CommandLine) THEN strCommand = strCommand & " " & pSed.CommandLine
                           r = SHELL(strCommand, 1)
                        END IF
                     END IF
                  END IF
               END IF
            ELSE
               MessageBox(hwnd, "You must set the path of the headers", "", _
                  %MB_OK OR %MB_ICONINFORMATION OR %MB_APPLMODAL)
            END IF
         ELSE
            MessageBox(hwnd, "No default compiler specified", "", _
               %MB_OK OR %MB_ICONINFORMATION OR %MB_APPLMODAL)
         END IF
      ELSE
         IF cID = %IDM_COMPILEANDRUN THEN
            MessageBox(hwnd, "Can't retrieve the path of the file to compile", "", _
               %MB_OK OR %MB_ICONINFORMATION OR %MB_APPLMODAL)
         ELSEIF cID = %IDM_EXECUTE THEN
            MessageBox(hwnd, "Can't retrieve the path of the file to execute", "", _
               %MB_OK OR %MB_ICONINFORMATION OR %MB_APPLMODAL)
         END IF
      END IF
   ELSE
      MessageBox(hwnd, "No file to run", "", _
         %MB_OK OR %MB_ICONINFORMATION OR %MB_APPLMODAL)
   END IF

   ' // Set the focus in the edit control
   SetFocus hSci
   ' // Arrrow mouse
   MOUSEPTR 1
   ' // Restore old directory
   IF LEN(strCurDir) THEN CHDIR strCurDir

END SUB
' ========================================================================================

' ========================================================================================
' Compiler results
' ========================================================================================
#IF %DEF(%UNICODE)
SUB CSED_CompilerResults (BYVAL hParent AS DWORD, BYVAL strResult AS WSTRING)
#ELSE
SUB CSED_CompilerResults (BYVAL hParent AS DWORD, BYVAL strResult AS STRING)
#ENDIF

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT SUB

   ' // Create the main window
   LOCAL hwnd AS DWORD
'   hwnd = pWindow.CreateWindow(hParent, "Compiler Results", 0, 0, 600, 400, _
'          %WS_VISIBLE OR %WS_CAPTION OR %WS_POPUPWINDOW, %WS_EX_TOOLWINDOW OR %WS_EX_WINDOWEDGE, _
'          CODEPTR(CSED_CompilerResult_WindowProc))
   hwnd = pWindow.CreateWindow(hParent, "Compiler Results", 0, 0, 600, 400, _
          %WS_VISIBLE OR %WS_CAPTION OR %WS_POPUPWINDOW, %WS_EX_WINDOWEDGE, _
          CODEPTR(CSED_CompilerResult_WindowProc))
   pWindow.CenterWindow hwnd

   ' // Add a text box
   LOCAL hEdit AS DWORD
   hEdit = pWindow.AddTextBox(hwnd, 101, "", 5, 5, 582, 365, _
           %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %WS_VSCROLL OR %WS_HSCROLL OR %ES_LEFT OR _
           %ES_AUTOVSCROLL OR %ES_MULTILINE OR %ES_WANTRETURN, -1)

   ' // Set the content
   Edit_SetText hEdit, strResult
   ' // Set the focus in the text box
   SetFocus hEdit

   ' // Default message pump (you can replace it with your own)
   pWindow.DoEvents

END SUB
' ========================================================================================

' ========================================================================================
' Compiler result callback function.
' ========================================================================================
FUNCTION CSED_CompilerResult_WindowProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

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
' Launches the PB IDE and sends a compile and debug command.
' Only for PBWIN 10 and PBCC 6.
' ========================================================================================
#IF %DEF(%UNICODE)
SUB CSED_CompileAndDebug (BYVAL hwnd AS DWORD, BYVAL strPath AS WSTRING)
#ELSE
SUB CSED_CompileAndDebug (BYVAL hwnd AS DWORD, BYVAL strPath AS STRING)
#ENDIF

   ' // Save loaded files if needed
   CSED_SaveLoadedFiles(hwnd)

   IF pSed.SelectedCompiler = 2 THEN
      strPath = PATHNAME$(PATH, pSed.PBCCPath) & "CCEDIT.EXE /D " & $DQ & strPath & $DQ
   ELSE
      strPath = PATHNAME$(PATH, pSed.PBWINPath) & "PBEDIT.EXE /D " & $DQ & strPath & $DQ
   END IF

   LOCAL PID AS DWORD
   PID = SHELL(strPath)

END SUB
' ========================================================================================
