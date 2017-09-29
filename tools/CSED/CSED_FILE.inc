' ########################################################################################
' CSED Editor
' File: CSED_FILE.INC
' Contents: File related functions and procedures
' Copyright (c) 2012 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ========================================================================================
' Retrieves the date and time that a file was last modified.
' ========================================================================================
#IF %DEF(%UNICODE)
FUNCTION CSED_GetFileTime (BYVAL strFileSpec AS WSTRING) AS DWORD
#ELSE
FUNCTION CSED_GetFileTime (BYVAL strFileSpec AS STRING) AS DWORD
#ENDIF

   LOCAL fd      AS WIN32_FIND_DATA
   LOCAL ft      AS SYSTEMTIME
   LOCAL hFile   AS DWORD
   LOCAL strTime AS STRING

   hFile = FindFirstFile(BYCOPY strFileSpec, fd)
   IF hFile = %INVALID_HANDLE_VALUE THEN EXIT FUNCTION
   FindClose hFile

   ' // Convert the file time into a compatible system time
   FileTimeToSystemTime fd.ftLastWriteTime, ft
   strTime = FORMAT$(ft.wHour) & FORMAT$(ft.wMinute) & FORMAT$(ft.wSecond)
   FUNCTION = VAL(strTime)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Search for compiler paths
' ========================================================================================
#IF %DEF(%UNICODE)
FUNCTION CSED_SearchForExePath (BYVAL hwnd AS DWORD) AS WSTRING
#ELSE
FUNCTION CSED_SearchForExePath (BYVAL hwnd AS DWORD) AS STRING
#ENDIF

   LOCAL dwStyle       AS DWORD
#IF %DEF(%UNICODE)
   LOCAL strFileSpec   AS WSTRING
   LOCAL strFilter     AS WSTRING
   LOCAL strInitialDir AS WSTRING
#ELSE
   LOCAL strFileSpec   AS STRING
   LOCAL strFilter     AS STRING
   LOCAL strInitialDir AS STRING
#ENDIF

   strInitialDir = CURDIR$
   strFilter = "EXE files (*.EXE)|*.EXE|"
   strFilter += "All Files (*.*)|*.*"
   strFileSpec = "*.EXE"
   dwStyle = %OFN_EXPLORER OR %OFN_FILEMUSTEXIST OR %OFN_HIDEREADONLY
   IF ISTRUE AfxOpenFileDialog(hwnd, "", strFileSpec, strInitialDir, strFilter, "EXE", dwStyle) THEN FUNCTION = strFileSpec

END FUNCTION
' ========================================================================================

' ========================================================================================
' Search for help paths
' ========================================================================================
#IF %DEF(%UNICODE)
FUNCTION CSED_SearchForHelpFilePath (BYVAL hwnd AS DWORD) AS WSTRING
#ELSE
FUNCTION CSED_SearchForHelpFilePath (BYVAL hwnd AS DWORD) AS STRING
#ENDIF

   LOCAL dwStyle       AS DWORD
#IF %DEF(%UNICODE)
   LOCAL strFileSpec   AS WSTRING
   LOCAL strFilter     AS WSTRING
   LOCAL strInitialDir AS WSTRING
#ELSE
   LOCAL strFileSpec   AS STRING
   LOCAL strFilter     AS STRING
   LOCAL strInitialDir AS STRING
#ENDIF

   strInitialDir = CURDIR$
   strFilter = "Help files (*.HLP;*:CHM)|*.HLP|*.CHM|"
   strFilter += "All Files (*.*)|*.*"
   strFileSpec = "*.HLP;*.CHM"
   dwStyle = %OFN_EXPLORER OR %OFN_FILEMUSTEXIST OR %OFN_HIDEREADONLY
   IF ISTRUE AfxOpenFileDialog(hwnd, "", strFileSpec, strInitialDir, strFilter, "CHM", dwStyle) THEN FUNCTION = strFileSpec

END FUNCTION
' ========================================================================================

' ========================================================================================
' Search for include files
' ========================================================================================
#IF %DEF(%UNICODE)
FUNCTION CSED_SearchForIncFilesPath (BYVAL hwnd AS DWORD) AS WSTRING
#ELSE
FUNCTION CSED_SearchForIncFilesPath (BYVAL hwnd AS DWORD) AS STRING
#ENDIF

   LOCAL dwStyle       AS DWORD
#IF %DEF(%UNICODE)
   LOCAL strFileSpec   AS WSTRING
   LOCAL strFilter     AS WSTRING
   LOCAL strInitialDir AS WSTRING
#ELSE
   LOCAL strFileSpec   AS STRING
   LOCAL strFilter     AS STRING
   LOCAL strInitialDir AS STRING
#ENDIF

   strInitialDir = CURDIR$
   strFilter = "INC files (*.INC)|*.INC|"
   strFilter += "BAS files (*.BAS)|*.BAS|"
   strFileSpec = "*.HLP;*.CHM"
   dwStyle = %OFN_EXPLORER OR %OFN_FILEMUSTEXIST OR %OFN_HIDEREADONLY
   IF ISTRUE AfxOpenFileDialog(hwnd, "", strFileSpec, strInitialDir, strFilter, "INC", dwStyle) THEN FUNCTION = strFileSpec

END FUNCTION
' ========================================================================================

' ========================================================================================
' Open selected files in MDI windows
' ========================================================================================
FUNCTION CSED_OpenFileDialog (BYVAL hwnd AS DWORD) AS DWORD

   LOCAL i               AS LONG
   LOCAL nCount          AS LONG
   LOCAL hMdi            AS DWORD
   LOCAL dwStyle         AS DWORD
#IF %DEF(%UNICODE)
   LOCAL strInitialDir   AS WSTRING
   LOCAL strFileSpec     AS WSTRING
   LOCAL strDefExtension AS WSTRING
   LOCAL strFilter       AS WSTRING
   LOCAL strPath         AS WSTRING
   LOCAL strFile         AS WSTRING
#ELSE
   LOCAL strInitialDir   AS STRING
   LOCAL strFileSpec     AS STRING
   LOCAL strDefExtension AS STRING
   LOCAL strFilter       AS STRING
   LOCAL strPath         AS STRING
   LOCAL strFile         AS STRING
#ENDIF

   strInitialDir = CURDIR$
   strFileSpec = "*.BAS;*.INC"
   strDefExtension = "BAS"
   strFilter  = "PB Code Files (*.BAS)|*.BAS|"
   strFilter += "PB Include Files (*.INC)|*.INC|"
   strFilter += "PB Template Files (*.PBTPL)|*.PBTPL|"
   strFilter += "Resource Files (*.RC;*.RC2;.DLG)|*.RC;*.RC2;*.DLG|"
   strFilter += "Text Files (*.TXT)|*.TXT|"
   strFilter += "XML Files (*.XML;*.XSL;*.XSD)|*.XML;*.XSL;*.XSD|"
   strFilter += "HTML Files (*.HTML;*.HTM;*.SHTML)|*.HTML;*.HTM;*.SHTML|"
   strFilter += "C/CPP Files (*.C;*.CC;*.CPP;*.CXX;*.H;*.HH;*.HPP;*.HXX)|*.C;*.CC;*.CPP;*.CXX;*.H;*.HH;*.HPP;*.HXX|"
   strFilter += "Java Files (*.JAVA;*.JAD)|*.JAVA;*.JAD|"
   strFilter += "Java Script Files (*.JS)|*.JS|"
   strFilter += "IDL Files (*.IDL;*.ODL)|*.IDL;*.ODL|"
   strFilter += "All Files (*.*)|*.*"
   dwStyle = %OFN_EXPLORER OR %OFN_FILEMUSTEXIST OR %OFN_ALLOWMULTISELECT

   IF AfxOpenFileDialog(hwnd, "", strFileSpec, strInitialDir, strFilter, strDefExtension, dwStyle) THEN
      strFileSpec = RTRIM$(strFileSpec, CHR$(0))
      nCount = PARSECOUNT(strFileSpec, CHR$(0))
      IF nCount = 1 THEN
         hMdi = CSED_OpenFile(strFileSpec)
         ' // If the user has checked the open read-only box don't allow editing
         IF (dwStyle AND %OFN_READONLY) = %OFN_READONLY THEN
            SCI_SetReadOnly(pSed.hEdit, %TRUE)
         END IF
      ELSE
         strPath = PARSE$(strFileSpec, CHR$(0), 1)
         IF RIGHT$(strPath, 1) <> "\" THEN strPath = strPath & "\"
         FOR i = 2 TO nCount
            strFile = PARSE$(strFileSpec, CHR$(0), i)
            IF LEN(strFile) THEN
               hMdi = CSED_OpenFile(strPath & strFile)
               ' // If the user has checked the open read-only box don't allow editing
               ' // Note: Doesn't work with multiselection: the flag is cleared.
'               IF (dwStyle AND %OFN_READONLY) = %OFN_READONLY THEN
'                  IF hMdi THEN SCI_SetReadOnly(pSed.hEdit, %TRUE)
'               END IF
            END IF
         NEXT
      END IF
   END IF

   FUNCTION = hMdi

END FUNCTION
' ========================================================================================

' ========================================================================================
' Open file function
' ========================================================================================
#IF %DEF(%UNICODE)
FUNCTION CSED_OpenFile (BYVAL strFileName AS WSTRING) AS DWORD
#ELSE
FUNCTION CSED_OpenFile (BYVAL strFileName AS STRING) AS DWORD
#ENDIF

   LOCAL hMdi      AS DWORD     ' // Handle of the MDI window
   LOCAL nFile     AS LONG      ' // File handle
   LOCAL fModify   AS LONG      ' // Modify flag - indicates if the file has been mdified and needs saving
   LOCAL fTime     AS DWORD     ' // File time
   LOCAL bValidExt AS LONG      ' // Valid extension
   LOCAL nTab      AS LONG      ' // Tab index
   LOCAL p         AS LONG      ' // Position
   LOCAL r         AS LONG      ' // Result code
   LOCAL buffer    AS STRING    ' // Buffer (ansi)
#IF %DEF(%UNICODE)
   LOCAL strExt    AS WSTRING   ' // File extension
   LOCAL strPath   AS WSTRING   ' // Path and name of the file
#ELSE
   LOCAL strExt    AS STRING    ' // File extension
   LOCAL strPath   AS STRING    ' // Path and name of the file
#ENDIF

   IF LEN(strFileName) = 0 THEN EXIT FUNCTION
   p = INSTR(-1, strFileName, ".")
   IF p THEN strExt = MID$(strFileName, p)
   IF strExt = ".BAS" OR strExt = ".INC" OR strExt = ".RC" THEN bValidExt = %TRUE
   TRY
      nFile = FREEFILE
      OPEN strFileName FOR BINARY AS nFile
      GET$ nFile, LOF(nFile), buffer   ' // Use GET$ because the file is ansi
   CATCH
      MessageBox(0, "Error" & STR$(ERR) & " loading the file " & strFileName, _
         FUNCNAME$, %MB_OK OR %MB_ICONERROR OR %MB_TASKMODAL)
      EXIT FUNCTION
   FINALLY
      CLOSE nFile
   END TRY

   ' // Check the first two bytes to see if the text contains the Unicode byte-order mark (BOM) &HFEFF.
   LOCAL bIsUnicode AS LONG
   bIsUnicode = IsTextUnicode(STRPTR(buffer), 2, %IS_TEXT_UNICODE_SIGNATURE)
   IF bIsUnicode THEN buffer = ACODE$(MID$(buffer, 3))

   ' // Trim trailing spaces and tabs
   IF pSed.TrimTrailingBlanks THEN
      DO
         p = LEN(buffer)
         REPLACE " " & $CR WITH $CR IN buffer
         REPLACE $TAB & $CR WITH $CR IN buffer
      LOOP UNTIL p = LEN(buffer)
   END IF

   ' // Get the file time
   fTime = CSED_GetFileTime(strFileName)

   ' // First look at already opened files
   hMdi = GetWindow(pSed.hwndClient, %GW_CHILD)
   WHILE hMdi
      strPath = AfxGetWindowText(hMdi)
      ' // If already opened...
      IF UCASE$(strPath) = UCASE$(strFileName) THEN
         ' // Activate the MDI child window
         MdiActivate(pSed.hwndClient, hMdi)
         ' // Select the tab associated with the path
         nTab = CSED_GetTabNumberFromPath(strPath)
         IF nTab THEN TabCtrl_SetCurSel(pSed.hTabMdi, nTab)
         fModify = SCI_GetModify(pSed.hEdit)
         IF fModify THEN
            BEEP
            r = CSED_Msgbox(pSed.hEdit, "Warning! The modifications will be lost." & $CRLF & _
               "Do you want to reload the file anyway?", %MB_YESNO OR %MB_ICONWARNING, "Reload file")
         END IF
         IF fModify AND r = %IDYES OR fModify = %FALSE THEN
            ' // Fill the control with the contents of the file
            SCI_SetText(pSed.hEdit, buffer)
            ' // Empty the undo buffer (it also sets the state of the document as unmodified)
            SCI_EmptyUndoBuffer(pSed.hEdit)
            ' // Store the time in the properties list of the window
            SetProp MdiGetActive(pSed.hwndClient), "FTIME", fTime
         END IF
         ' // Load and set the bookmarks
         IF pSed.SaveBookmarksToFile THEN pSed.SetBookmarks(strFileName)
         ' // Update the MRU list and exit
         pSed.SetRecentFile(strFileName)
         CSED_RecentFilesMenu
         EXIT FUNCTION
      END IF
      hMdi = GetWindow(hMdi, %GW_HWNDNEXT)
   WEND

   ' // Create a new MDI child window
   hMdi = CSED_CreateMdiChild(strFileName)
   IF hMdi THEN
      ' // Fill the control with the contents of the file
      SCI_SetText(pSed.hEdit, buffer)
      ' // Empty the undo buffer (it also sets the state of the document as unmodified)
      SCI_EmptyUndoBuffer(pSed.hEdit)
      ' // Store the time in the properties list of the window
      SetProp MdiGetActive(pSed.hwndClient), "FTIME", fTime
      ' // Load and set the bookmarks
      IF pSed.SaveBookmarksToFile THEN pSed.SetBookmarks(strFileName)
      ' // Update the MRU list
      pSed.SetRecentFile(strFileName)
      CSED_RecentFilesMenu
   END IF

   FUNCTION = hMdi

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
' Save the record
' ========================================================================================
FUNCTION CSED_SaveBackupCodeRecord (BYVAL hwnd AS DWORD, BYVAL hBackupFile AS DWORD, BYVAL strName AS STRING, BYVAL strText AS STRING) AS LONG

   LOCAL Result AS LONG
   LOCAL RecordName AS STRING * 60
   LOCAL RecordStr AS STRING

   RecordName = strName
   RecordStr = RecordName & strText
   ' // Insert the record
   Result = trm_Insert(hBackupFile, BYCOPY RecordStr)
   ' // Duplicate key value: use trm_Update
   IF Result = 5 THEN
      ' // Establish current logical position
      trm_GetEqual(hBackupFile, 1, BYCOPY RecordName)
      Result = trm_Result(hBackupFile)
      IF Result = 0 THEN Result = trm_Update(hBackupFile, BYCOPY RecordStr)
   END IF
   FUNCTION = Result

END FUNCTION
' ========================================================================================

' ========================================================================================
' Save file procedure
' ========================================================================================
#IF %DEF(%UNICODE)
FUNCTION CSED_SaveFile (BYVAL hwnd AS DWORD, BYVAL hSci AS DWORD, BYVAL bAsk AS LONG) AS LONG
#ELSE
FUNCTION CSED_SaveFile (BYVAL hwnd AS DWORD, BYVAL hSci AS DWORD, BYVAL bAsk AS LONG) AS LONG
#ENDIF

   LOCAL Result         AS LONG      ' // Result code
   LOCAL dwStyle        AS DWORD     ' // Window styles
   LOCAL nFile          AS DWORD     ' // File number
   LOCAL buffer         AS STRING    ' // Ansi string buffer
   LOCAL bufLen         AS LONG      ' // Buffer length
   LOCAL fTime          AS DWORD     ' // File time
   LOCAL nTab           AS LONG      ' // Tab number
   LOCAL hMdi           AS DWORD     ' // MDI child window
   LOCAL hBackupFile    AS DWORD     ' // Backup file

#IF %DEF(%UNICODE)
   LOCAL strInitialDir  AS WSTRING   ' // Initial directory
   LOCAL strPath        AS WSTRING   ' // File path
   LOCAL strExt         AS WSTRING   ' // File extension
   LOCAL strOldExt      AS WSTRING   ' // Old file extension
   LOCAL bakExt         AS WSTRING   ' // Backup file extension
   LOCAL strDefExt      AS WSTRING   ' // DEfault file extension
   LOCAL strFilter      AS WSTRING   ' // Filter
   LOCAL strBakFileName AS WSTRING   ' // Backup file name
#ELSE
   LOCAL strInitialDir  AS STRING    ' // Initial directory
   LOCAL strPath        AS STRING    ' // File path
   LOCAL strExt         AS STRING    ' // File extension
   LOCAL strOldExt      AS STRING    ' // Old file extension
   LOCAL bakExt         AS STRING    ' // Backup file extension
   LOCAL strDefExt      AS STRING    ' // DEfault file extension
   LOCAL strFilter      AS STRING    ' // Filter
   LOCAL strBakFileName AS STRING    ' // Backup file name
#ENDIF
   LOCAL bstrPath       AS WSTRING   ' // Path in unicode
   LOCAL strDbPath      AS STRING    ' // Database path (ansi)
   LOCAL strRecordName  AS STRING    ' // Record Name

   strPath = AfxGetWindowText(GetParent(hSci))
   IF ISNULL(strPath) THEN EXIT FUNCTION
   ' // If not path, it's a new document
   IF INSTR(strPath, ANY ":\/") = 0 THEN
      strInitialDir = CURDIR$
      IF RIGHT$(strInitialDir, 1) <> "\" THEN strInitialDir = strInitialDir + "\"
      IF LEFT$(UCASE$(strPath), 8) = "UNTITLED" AND INSTR(strPath, ".") = 0 THEN strPath += ".BAS"
      ' // We need the dialog for new docs
      bAsk = %TRUE
   ELSE
      strInitialDir = PATHNAME$(PATH, strPath)
      strPath = PATHNAME$(NAMEX, strPath)
   END IF
   strDefExt = "BAS"

   ' // Build the filter based on the file extension
   strExt = UCASE$(PATHNAME$(EXTN, strPath))
   strOldExt = strExt
   SELECT CASE strExt
      CASE ".BAS"
         strFilter += "PB Code Files (*.BAS)|*.BAS|"
         strFilter += "PB Include Files (*.INC)|*.INC|"
         strDefExt = "BAS"
      CASE ".INC"
         strFilter += "PB Include Files (*.INC)|*.INC|"
         strFilter += "PB Code Files (*.BAS)|*.BAS|"
         strDefExt = "INC"
      CASE ".PBTPL"
         strFilter += "PB Template Files (*.PBTPL)|*.PBTPL|"
         strDefExt = "PBTPL"
      CASE ".RC", ".RC2", ".DLG"
         strFilter += "Resource Files (*.RC;*.RC2;.DLG)|*.RC;*.RC2;*.DLG|"
         strDefExt = "RC"
      CASE ".TXT"
         strFilter += "Text Files (*.TXT)|*.TXT|"
         strDefExt = "TXT"
      CASE ".XML", ".XSL", ".XSD"
         strFilter += "XML Files (*.XML;*.XSL;*.XSD)|*.XML;*.XSL;*.XSD|"
         strDefExt = "XML"
      CASE ".HTML", ".HTM", ".SHTML"
         strFilter += "HTML Files (*.HTML;*.HTM;*.SHTML)|*.HTML;*.HTM;*.SHTML|"
         strDefExt = "HTML"
      CASE ".C", ".CC", ".CPP", ".CXX", ".H", ".HH", ".HPP", ".HXX"
         strFilter += "C/CPP Files (*.C;*.CC;*.CPP;*.CXX;*.H;*.HH;*.HPP;*.HXX)|*.C;*.CC;*.CPP;*.CXX;*.H;*.HH;*.HPP;*.HXX|"
         strDefExt = "C"
      CASE ".JAVA", ".JAD"
         strFilter += "Java Files (*.JAVA;*.JAD)|*.JAVA;*.JAD|"
         strDefExt = "JAVA"
      CASE ".JS"
         strFilter += "Java Script Files (*.JS)|*.JS|"
         strDefExt = "JS"
      CASE ".IDL", ".ODL"
         strFilter += "IDL Files (*.IDL;*.ODL)|*.IDL;*.ODL|"
         strDefExt = "IDL"
   END SELECT
   strFilter += "All Files (*.*)|*.*"

   ' // Launch the Save File Dialog
   IF bAsk THEN
      dwStyle = %OFN_EXPLORER OR %OFN_FILEMUSTEXIST OR %OFN_HIDEREADONLY OR %OFN_OVERWRITEPROMPT
      IF ISFALSE(AfxSaveFileDialog(pSed.hwndMain, "", strPath, strInitialDir, strFilter, strDefExt, dwStyle)) THEN EXIT FUNCTION
   ELSE
      strPath = strInitialDir & strPath
   END IF

   ' // Backup the file
   IF pSed.BackupEditorFiles THEN
      strExt = UCASE$(PATHNAME$(EXTN, strPath))
      IF strExt <> ".BAK" THEN
         strBakFileName = strPath
         strBakFileName += ".bak"
         bakExt = strExt & ".bak"
         IF pSed.AddDateTimeToBackupFiles THEN
            LOCAL d, t, dt AS STRING
            d = DATE$
            d = RIGHT$(d, 4) & LEFT$(d, 2) & MID$(d, 4, 2)
            t = TIME$
            t = REMOVE$(t, ":")
            dt = d & "_" & t
          strBakFileName = LEFT$(strBakFilename, LEN(strBakFilename) - LEN(bakExt)) & "_" & dt & bakExt
         END IF
         IF ISFALSE pSed.SaveBackupFilesToDatabase THEN
            IF ISFILE(strPath) THEN FILECOPY strPath, strBakFileName
         END IF
      END IF
   END IF

   ' // Save the file
   TRY
      nFile = FREEFILE
      OPEN strPath FOR BINARY AS nFile
      ' // Get the text to save
      buffer = SCI_GetText(hSci)
      ' // Remove trailing spaces and tabs
      IF pSed.TrimTrailingBlanks THEN
         DO
            bufLen = LEN(buffer)
            REPLACE " " & $CR WITH $CR IN buffer
            REPLACE $TAB & $CR WITH $CR IN buffer
         LOOP UNTIL bufLen = LEN(buffer)
      END IF
      PUT$ nFile, buffer
      SETEOF nFile
   CATCH
      CSED_MsgBox(hwnd, "Error" & STR$(ERR) & " saving the file " & strPath, _
         %MB_OK OR %MB_ICONERROR, "Save File")
      EXIT FUNCTION
   FINALLY
      CLOSE nFile
   END TRY

   ' // Tell to Scintilla that the current state of the document is unmodified
   SCI_SetSavePoint(hSci)

   ' // Save backup file in the database
   IF pSed.BackupEditorFiles AND pSed.SaveBackupFilesToDatabase THEN
      strDbPath = EXE.PATH$ & "CSED_BACKUPMGR\" & $BACKUPSDB
      IF ISFALSE ISFILE(strDbPath) THEN
         hBackupFile = CSED_CreateBackupMgrDatabase(hwnd, strDbPath)
      END IF
      IF hBackupFile < 1 OR ISFALSE trm_FileIsOpen(hBackupFile) THEN
         hBackupFile = trm_Open(strDbPath, %TRUE)
         IF hBackupFile < 1 THEN
            CSED_MsgBox(hwnd, "Error opening the file backups database", _
               %MB_OK OR %MB_ICONERROR, "Tsunami Error")
         ELSE
            strRecordName = PATHNAME$(NAME, strBakFileName)
            Result = CSED_SaveBackupCodeRecord(hwnd, hBackupFile, strRecordName, buffer)
            IF Result THEN
               CSED_MsgBox(hwnd, "Error " & FORMAT$(Result) & " saving the file backup record", _
                  %MB_OK OR %MB_ICONERROR, "Tsunami Error")
            END IF
            trm_Close hBackupFile
         END IF
      END IF
   END IF

   ' // Save the bookmarks
   IF pSed.SaveBookmarksToFile AND _
      LCASE$(strExt) <> ".csbkm" AND _
      LCASE$(strExt) <> ".bak" THEN
      pSed.SaveBookmarks(hSci, strPath)
   END IF

   ' // Update reopen file list (MRU menu)
   pSed.SetRecentFile(strPath)
   CSED_RecentFilesMenu

   ' // Set Scintilla options if the user has changed the file extension
   IF UCASE$(PATHNAME$(EXTN, strPath)) <> strOldExt THEN
      strExt = UCASE$(PATHNAME$(EXTN, strPath))
      CSED_SetScintillaOptions hSci, strExt
   END IF

   ' // Get the handle of the MDI child window
   hMdi = GetParent(hSci)

   IF bAsk THEN
      ' // Get the current tab
      nTab = TabCtrl_GetCurSel(pSed.hTabMdi)
      ' // Update the collection of full paths
      ' // --------------------------------------------
      ' // Workaround: The Add method of the linked list
      ' // collection needs an Unicode string
      bStrPath = strPath
      pSed.TabFilePaths.Replace(nTab + 1, bstrPath)
      ' // --------------------------------------------
      ' // Update the window caption and the tab name
      IF hMdi THEN AfxSetWindowText hMdi, strPath
      TabCtrl_SetText(pSed.hTabMdi, nTab, PATHNAME$(NAMEX, strPath))
   END IF

   ' // Retrieve the file time and store it in the properties list of the window
   fTime = CSED_GetFileTime(strPath)
   IF hMdi THEN SetProp hMdi, "FTIME", fTime

   FUNCTION = -1

END FUNCTION
' ========================================================================================

' ========================================================================================
' Save untitled file in Windows temporary folder
' ========================================================================================
#IF %DEF(%UNICODE)
FUNCTION CSED_SaveUntitledFile (BYVAL hwnd AS DWORD, BYVAL hSci AS DWORD, BYVAL strPath AS WSTRING) AS LONG
#ELSE
FUNCTION CSED_SaveUntitledFile (BYVAL hwnd AS DWORD, BYVAL hSci AS DWORD, BYVAL strPath AS STRING) AS LONG
#ENDIF

   LOCAL nLen   AS LONG                 ' // Text lenght
   LOCAL nFile  AS LONG                 ' // File number
   LOCAL buffer AS STRING               ' // Buffer
#IF %DEF(%UNICODE)
   LOCAL szTempPath AS WSTRINGZ * %MAX_PATH   ' // Temporary file path
#ELSE
   LOCAL szTempPath AS ASCIIZ * %MAX_PATH     ' // Temporary file path
#ENDIF

   IF ISNULL(strPath) THEN EXIT FUNCTION
   GetTempPath(%MAX_PATH, szTempPath)
   CHDIR szTempPath
   strPath = szTempPath & strPath
   nFile = FREEFILE
   OPEN strPath FOR BINARY AS nFile
   IF ERR THEN
      CSED_MsgBox(hwnd, "Error" & STR$(ERR) & " saving the file", _
         %MB_OK OR %MB_ICONERROR OR %MB_APPLMODAL, "Save untitled file")
      EXIT FUNCTION
   END IF
   nLen = SCI_GetTextLength(hSci)
   buffer = SCI_GetText(hSci)
   PUT$ nFile, LEFT$(buffer, LEN(buffer))
   SETEOF nFile
   CLOSE nFile
   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Insert file procedure
' ========================================================================================
SUB CSED_InsertFile (BYVAL hwnd AS DWORD)

#IF %DEF(%UNICODE)
   LOCAL strPath        AS WSTRING   ' // File path
   LOCAL strInitialDir  AS WSTRING   ' // Initial directory
   LOCAL strFilter      AS WSTRING   ' // Filter
#ELSE
   LOCAL strPath        AS STRING    ' // File path
   LOCAL strInitialDir  AS STRING    ' // Initial directory
   LOCAL strFilter      AS STRING    ' // Filter
#ENDIF
   LOCAL dwStyle        AS DWORD     ' // Window styles
   LOCAL nFile          AS LONG      ' // File number
   LOCAL buffer         AS STRING    ' // Buffer

   IF ISFALSE pSed.hEdit THEN EXIT SUB

   strInitialDir = CURDIR$
   strFilter = "PB Code Files (*.BAS)|*.BAS|"
   strFilter += "PB Include Files (*.INC)|*.INC|"
   strFilter += "PB Include Files (*.INC)|*.INC|"
   strFilter += "PB Code Files (*.BAS)|*.BAS|"
   strFilter += "All Files (*.*)|*.*"
   strPath = "*.BAS;*.INC"

   ' // Launch the Open File Dialog
   dwStyle = %OFN_EXPLORER OR %OFN_FILEMUSTEXIST OR %OFN_HIDEREADONLY OR %OFN_LONGNAMES
   IF ISFALSE(AfxOpenFileDialog(pSed.hwndMain, "", strPath, strInitialDir, strFilter, "BAS", dwStyle)) THEN EXIT SUB

   ' // Open the file and read it
   TRY
      nFile = FREEFILE
      OPEN strPath FOR BINARY AS nFile
      GET$ nFile, LOF(nFile), Buffer
   CATCH
      CSED_MsgBox(hwnd, "Error" & STR$(ERR) & " inserting the file " & strPath, _
         %MB_OK OR %MB_ICONERROR, "Insert File")
      EXIT SUB
   FINALLY
      CLOSE nFile
   END TRY

   ' // Insert the text at the current position
   SCI_InsertText(pSed.hEdit, -1, buffer)
   ' // Change statusbar information
   CSED_ShowLinCol

END SUB
' ========================================================================================

' ========================================================================================
' GetDroppedFiles - Retrieves the paths of the dropped files
' ========================================================================================
FUNCTION CSED_GetDroppedFiles (BYVAL hDrop AS DWORD) AS IQueueCollection

   LOCAL i      AS LONG                   ' // Loop counter
   LOCAL nCount AS LONG                   ' // Number of dropped filed
   LOCAL nLen   AS LONG                   ' // Length of the path + filename
   LOCAL pQueue AS IQueueCollection       ' // Reference to the Queue collection
#IF %DEF(%UNICODE)
   LOCAL szPath AS WSTRINGZ * %MAX_PATH   ' // Filename and path
#ELSE
   LOCAL szPath AS ASCIIZ * %MAX_PATH     ' // Filename and path
#ENDIF

   ' // Get the number of dropped files
   nCount = DragQueryFile(hDrop, &HFFFFFFFF???, BYVAL %NULL, 0)
   IF nCount = 0 THEN EXIT FUNCTION

   ' // Create an instance of the Queue collection
   pQueue = CLASS "QueueCollection"
   IF ISNOTHING(pQueue) THEN EXIT FUNCTION

   FOR i = 0 TO nCount - 1
      ' // Retrieve the path and length
      nLen = DragQueryFile(hDrop, i, szPath, %MAX_PATH)
      IF nLen THEN
         szPath = TRIM$(LEFT$(szPath, nLen))
         ' // Make sure it's a file, not a folder
         IF LEN(szPath) AND (GETATTR(szPath) AND 16) = 0 THEN
            pQueue.Enqueue BYCOPY szPath
         END IF
      END IF
   NEXT

   DragFinish hDrop
   FUNCTION = pQueue

END FUNCTION
' ========================================================================================

' ========================================================================================
' Load selected file
' ========================================================================================
SUB CSED_LoadSelectedFile (BYVAL hwnd AS DWORD, BYVAL strFileName AS STRING)

   LOCAL i          AS LONG              ' // Loop counter
   LOCAL RetVal     AS LONG              ' // Return value
   LOCAL hFile      AS DWORD             ' // File handle
   LOCAL strPath    AS STRING            ' // File path
   LOCAL strIncPath AS STRING            ' // Include files path
   LOCAL WFD        AS WIN32_FIND_DATA   ' // Find file structure

   IF INSTR(strFileName, ANY ":\/") THEN
      hFile = FindFirstFile(BYCOPY strFileName, WFD)
      IF hFile = %INVALID_HANDLE_VALUE THEN
         CSED_MsgBox(0, strFileName & " not found", %MB_OK, "File not found")
         EXIT SUB
      END IF
      strPath = strFileName
   ELSE
      ' // File has not path; add the path of the source file
      strPath = AfxGetWindowText(hwnd)
      strPath = PATHNAME$(PATH, strPath)
      strPath += strFileName
      hFile = FindFirstFile(BYCOPY strPath, WFD)
      IF hFile = %INVALID_HANDLE_VALUE THEN
         ' // Search the file in the include folders
         IF pSed.SelectedHeaders = 1 OR pSed.SelectedHeaders = 0 THEN
            strIncPath = pSed.JRSIncPath1
         ELSEIF pSed.SelectedHeaders = 2 THEN
            strIncPath = pSed.JRSIncPath2
         ELSEIF pSed.SelectedHeaders = 3 THEN
            strIncPath = pSed.PBIncPath1
         ELSEIF pSed.SelectedHeaders = 4 THEN
            strIncPath = pSed.PBIncPath2
         END IF
         RetVal = PARSECOUNT(strIncPath , ";")
         FOR i = 1 TO RetVal
            strPath = PARSE$(strIncPath , ";" , i) & "\" & strFileName
            hFile = FindFirstFile(BYCOPY strPath, WFD)
            IF hFile <> %INVALID_HANDLE_VALUE THEN EXIT FOR
         NEXT
         IF hFile = %INVALID_HANDLE_VALUE THEN
            CSED_MsgBox(0, strPath & " not found", %MB_OK, "File not found")
            EXIT SUB
         END IF
      END IF
   END IF
   ' // Close the search handle
   FindClose hFile
   ' // Open the file
   CSED_OpenFile strPath

END SUB
' ========================================================================================

' ========================================================================================
' Inserts the text of the macro at the caret position
' ========================================================================================
SUB CSED_InsertMacroText (BYVAL hwnd AS DWORD, BYVAL wParam AS DWORD)

   LOCAL hFile     AS LONG
   LOCAL strDbPath AS STRING
   LOCAL RecordStr AS STRING
   LOCAL strKey    AS STRING
   LOCAL wKey      AS WORD

   wKey = wParam
   SELECT CASE wKey
      CASE 3700 TO 3709
         strKey = "Alt" & FORMAT$(wKey - 3700)
      CASE 3710 TO 3719
         strKey = "Ctrl" & FORMAT$(wKey - 3710)
   END SELECT

   strDbPath = EXE.Path$ & "CSED_KBDMACROS\CSED_KBDMACROS.TRM"
   IF ISFALSE ISFILE(strDbPath) THEN
      CSED_MsgBox(hwnd, "Can't find the file " & strDbPath, %MB_OK OR %MB_ICONERROR, "CSED Macros")
      EXIT SUB
   END IF

   hFile = trm_Open(strDbPath, %TRUE)
   IF hFile < 1 THEN
      CSED_MsgBox(hwnd, "Error opening  " & strDbPath, %MB_OK OR %MB_ICONERROR, "CSED Macros")
      EXIT SUB
   END IF

   RecordStr = trm_GetEqualOrGreater(hFile, 1, BYCOPY strKey)
   IF UCASE$(strKey) = TRIM$(UCASE$(LEFT$(RecordStr, 15))) THEN
      RecordStr = MID$(RecordStr, 76)
      SCI_InsertText(pSed.hEdit, -1, RecordStr)
   END IF

   trm_Close(hFile)

END SUB
' ========================================================================================

' ========================================================================================
' Registers file extensions
' ========================================================================================
SUB CSED_RegisterFileExtensions (BYVAL hwnd AS DWORD)

   LOCAL r          AS LONG
   LOCAL KeyHandle  AS DWORD
#IF %DEF(%UNICODE)
   LOCAL KeyName    AS WSTRINGZ * 256
   LOCAL KeyValue   AS WSTRINGZ * 256
#ELSE
   LOCAL KeyName    AS ASCIIZ * 256
   LOCAL KeyValue   AS ASCIIZ * 256
#ENDIF

   r = CSED_MsgBox(hwnd, "This will associate the .BAS, .INC and .RC file extensions with the editor." & $CRLF & _
                         "You must have started the editor as administrator to succeed.", %MB_OKCANCEL, "Register File Extensions")
   IF r = %IDCANCEL THEN EXIT SUB

   KeyName = ".BAS"
   KeyValue = "CSED Editor"
   r = RegCreateKey(%HKEY_CLASSES_ROOT, KeyName, KeyHandle)
   IF r <> %ERROR_SUCCESS THEN MSGBOX AfxWinErrMsg(r) : EXIT SUB
   r = RegSetValue(KeyHandle, "", %REG_SZ, KeyValue, 0)
   RegCloseKey KeyHandle
   IF r <> %ERROR_SUCCESS THEN MSGBOX AfxWinErrMsg(r) : EXIT SUB

   KeyName = ".INC"
   KeyValue = "CSED Editor"
   r = RegCreateKey(%HKEY_CLASSES_ROOT, KeyName, KeyHandle)
   IF r <> %ERROR_SUCCESS THEN MSGBOX AfxWinErrMsg(r) : EXIT SUB
   r = RegSetValue(KeyHandle, "", %REG_SZ, KeyValue, 0)
   RegCloseKey KeyHandle
   IF r <> %ERROR_SUCCESS THEN MSGBOX AfxWinErrMsg(r) : EXIT SUB

   KeyName = ".RC"
   KeyValue = "CSED Editor"
   r = RegCreateKey(%HKEY_CLASSES_ROOT, KeyName, KeyHandle)
   IF r <> %ERROR_SUCCESS THEN MSGBOX AfxWinErrMsg(r) : EXIT SUB
   r = RegSetValue(KeyHandle, "", %REG_SZ, KeyValue, 0)
   RegCloseKey KeyHandle
   IF r <> %ERROR_SUCCESS THEN MSGBOX AfxWinErrMsg(r) : EXIT SUB

   KeyName = "CSED Editor"
   KeyValue = "CSED File Extensions"
   r = RegCreateKey(%HKEY_CLASSES_ROOT, KeyName, KeyHandle)
   IF r <> %ERROR_SUCCESS THEN MSGBOX AfxWinErrMsg(r) : EXIT SUB
   r = RegSetValue(KeyHandle, "", %REG_SZ, KeyValue, 0)
   RegCloseKey KeyHandle
   IF r <> %ERROR_SUCCESS THEN MSGBOX AfxWinErrMsg(r) : EXIT SUB

   KeyName = "CSED Editor"
   KeyValue = EXE.PATH$ & "\Resources\CSED.ICO"
   r = RegCreateKey(%HKEY_CLASSES_ROOT, KeyName, KeyHandle)
   IF r <> %ERROR_SUCCESS THEN MSGBOX AfxWinErrMsg(r) : EXIT SUB
   r = RegSetValue(KeyHandle, "ICON", %REG_SZ, KeyValue, %MAX_PATH)
   RegCloseKey KeyHandle
   IF r <> %ERROR_SUCCESS THEN MSGBOX AfxWinErrMsg(r) : EXIT SUB

   KeyName = "CSED Editor"
   KeyValue = EXE.FULL$ & " %1"
   r = RegCreateKey(%HKEY_CLASSES_ROOT, KeyName, KeyHandle)
   IF r <> %ERROR_SUCCESS THEN MSGBOX AfxWinErrMsg(r) : EXIT SUB
   r = RegSetValue(KeyHandle, "shell\open\command", %REG_SZ, KeyValue, %MAX_PATH)
   RegCloseKey KeyHandle
   IF r <> %ERROR_SUCCESS THEN MSGBOX AfxWinErrMsg(r) : EXIT SUB

   CSED_MsgBox hwnd, ".BAS, .INC and .RC file extensions" & $CRLF & "have been registered with Windows", %MB_OK, "Register File Extensions"

END SUB
' ========================================================================================
