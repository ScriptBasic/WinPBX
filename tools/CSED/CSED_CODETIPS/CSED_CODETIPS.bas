' ########################################################################################
' CSED Editor
' File: CSED_CODETIPS.INC
' Contents: Codetips builder
' Copyright (c) 2011 José Roca
' All Rights Reserved.
' Scanning routines by Ken Myers. kj_myers@earthlink.net - www.zcureit.com
' Modified by José Roca to suit the needs of his include files.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#COMPILE EXE
#DIM ALL
%UNICODE = 1

' // Include files for external files
#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "CWindow.inc"
#INCLUDE ONCE "trm.inc"
#INCLUDE ONCE "AfxWin.inc"

' // Resource file

' ========================================================================================
' Icon identifiers
' ========================================================================================
%IDI_CODETIPS32 = 100
%IDI_CODETIPS16 = 101
' ========================================================================================

#RESOURCE MANIFEST, 1, "CSED_CODETIPS.xml"
#RESOURCE ICON,   100, "CSED_CODETIPS32.ico"
#RESOURCE ICON,   101, "CSED_CODETIPS16.ico"

$PROGNAME = "Codetips Builder"
$CODETIPSDB = "CSED_CODETIPS.TRM"   ' // Codetips database name

' ========================================================================================
GLOBAL g_AbortCodetips AS LONG
' ========================================================================================

' ========================================================================================
' Codetips structure
' ========================================================================================
TYPE CSED_CODETIPSTYPE
   ProcName AS STRING * 64
   ProcCode AS STRING * 512
END TYPE
' ========================================================================================

' ========================================================================================
'   ** Constants **
' ========================================================================================
ENUM CSED_CODETIPS_ENUM SINGULAR
   IDC_FINDINC = 1001
   IDB_FINDINC
   IDC_LABELINC
   IDB_ABORTINC
   IDB_CODETIPSHELP
   IDB_RESETINC
END ENUM
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
' Creates the Tsunami CodeTip Database.
' The key value is the Function name.
' ========================================================================================
FUNCTION CSED_CreateCodeTipsDatabase (BYVAL hwnd AS DWORD, BYVAL strDbPath AS STRING) AS LONG

   LOCAL strFileDef AS STRING
   LOCAL strKeys AS STRING
   LOCAL strSegment AS STRING * 25

   strSegment = "CodeTip Name"

   strFileDef = MKBYT$(1) & _     ' // Page Size
                MKBYT$(1) & _     ' // Compress Record
                MKBYT$(1)         ' // Number of Key Segments

   strKeys =    strSegment  & _   ' // Description
                MKBYT$(1)   & _   ' // Segment number
                MKWRD$(1)   & _   ' // Segment Offset
                MKBYT$(64)  & _   ' // Segment Size
                MKBYT$(2)         ' // Flags (No duplicates)

   strFileDef += strKeys

   ' // Create Tsunami database file
   IF ISFILE(strDbPath) THEN
      IF CSED_MsgBox(hwnd, strDbPath & $CRLF & "File already exist. Overwrite it?", %MB_YESNO OR %MB_ICONWARNING, "Warning!") = %IDYES THEN
         FUNCTION = trm_Create(strDbPath, strFileDef, %TRUE)
      ELSE
         FUNCTION = -1
         EXIT FUNCTION
      END IF
   ELSE
      FUNCTION = trm_Create(strDbPath, strFileDef, %FALSE)
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Saves a new CodeTip to the Tsunami CodeTip Database.
' ========================================================================================
FUNCTION CSED_AddCodeTip (BYVAL hCodetipsFile AS LONG, BYVAL strCodeTip AS STRING) AS LONG

   LOCAL Result AS LONG, lPosStart AS LONG, lPosEnd AS LONG

   DIM Record      AS STRING * 576
   DIM CodeTips(0) AS CSED_CODETIPSTYPE AT VARPTR(Record)

   IF hCodetipsFile < 1 THEN EXIT FUNCTION
   IF TRIM$(strCodeTip) = "" THEN EXIT FUNCTION

   '----------------------------------------------------------------------------
   ' Add the new CodeTip to the Tsunami CodeTips Database file.
   ' ProcName is used for the Search Key in the Tsunami CodeTips Database.
   '----------------------------------------------------------------------------

   REPLACE $TAB WITH " " IN strCodeTip
   strCodeTip = REMOVE$(strCodeTip, "  ")
   strCodeTip = LTRIM$(strCodeTip)
   lPosStart = INSTR(1, strCodeTip, " ")
   IF lPosStart THEN strCodeTip = LEFT$(strCodeTip, lPosStart) & TRIM$(MID$(strCodeTip, lPosStart))
   lPosEnd   = INSTR(lPosStart + 1, strCodeTip, "(")

   CodeTips(0).ProcName = MID$(strCodeTip, lPosStart+1, (lPosEnd-lPosStart) - 1)
   CodeTips(0).ProcCode = strCodeTip

   Result = trm_Insert(hCodetipsFile, BYCOPY Record)
   ' // Duplicate Key Value so use trm_Update.
   IF Result = 5 THEN
      Result = trm_Update(hCodetipsFile, BYCOPY Record)
   END IF

   FUNCTION = Result

END FUNCTION
' ========================================================================================

' ========================================================================================
' Saves a new CodeTip to the Tsunami CodeTip Database.
' ========================================================================================
FUNCTION CSED_AddConstant (BYVAL hCodetipsFile AS LONG, BYVAL strConstant AS STRING) AS LONG

   LOCAL Result AS LONG

   DIM Record      AS STRING * 576
   DIM CodeTips(0) AS CSED_CODETIPSTYPE AT VARPTR(Record)

   IF hCodetipsFile < 1 THEN EXIT FUNCTION
   IF TRIM$(strConstant) = "" THEN EXIT FUNCTION

   CodeTips(0).ProcName = MID$(strConstant, 2)
   CodeTips(0).ProcCode = ""

   Result = trm_Insert(hCodetipsFile, BYCOPY Record)

   IF Result = 5 THEN        ' // Duplicate Key Value so use trm_Update.
      Result = trm_Update(hCodetipsFile, BYCOPY Record)
   END IF

   FUNCTION = Result

END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION CSED_RemoveNoCase (BYVAL strIn AS STRING, BYVAL strRemove AS STRING) AS STRING

   LOCAL Mask        AS STRING
   LOCAL PosVar      AS LONG
   LOCAL LenVar      AS LONG
   LOCAL StartVar    AS LONG
   LOCAL TheMain     AS STRING
   LOCAL TheWord     AS STRING
   LOCAL NewMain     AS STRING
   LOCAL ReplaceMask AS STRING

   TheMain = strIn
   LET mask = "(" & TRIM$(strRemove) & "+\b)"
   LET ReplaceMask = "\x20"
   StartVar = 1
   PosVar =1

   AfxDoEvents
   WHILE Posvar
      IF g_AbortCodetips THEN EXIT FUNCTION
      REGREPL Mask IN TheMain WITH ReplaceMask AT Startvar TO Posvar, NewMain
      TheMain = NewMain
      REGEXPR Mask IN TheMain AT StartVar TO Posvar, LenVar
      IF PosVar THEN
         TheWord = MID$(TheMain, posvar, Lenvar)
         StartVar = PosVar + Lenvar + 1
      END IF
   WEND

   REPLACE "  " WITH " " IN NewMain

   FUNCTION = NewMain

END FUNCTION
' ========================================================================================

' ========================================================================================
' We have to clean up the lines of code to prep for the regular expressions.
' ========================================================================================
FUNCTION CSED_CleanLine (BYVAL strIn AS STRING, BYVAL lastline AS STRING) AS STRING

   LOCAL tmpLine AS STRING
   LOCAL tmpPreLib AS STRING
   LOCAL tmpPostParen AS STRING
   LOCAL tmpLib AS LONG
   LOCAL tmpParen AS LONG
   LOCAL tend AS LONG
   LOCAL tmpD AS STRING
   LOCAL p AS LONG

   tmpLine = TRIM$(strIn)

   ' // Check if it is a constant
   IF LEFT$(tmpLine, 1) = "%" OR LEFT$(tmpLine, 1) = "$" THEN
      p = INSTR(tmpLine, "=")
      IF p THEN
         tmpLine = MID$(tmpLine, 1, p - 1)
         FUNCTION = RTRIM$(tmpLine)
         EXIT FUNCTION
      END IF
   END IF

   IF tmpLine <> "" THEN
      REPLACE "  " WITH " " IN tmpLine

      IF INSTR(UCASE$(tmpLine), " CDECL ") AND INSTR(UCASE$(tmpLine), " ALIAS ") THEN
         tmpLine = CSED_RemoveNoCase(tmpLine, "\x20cdecl\x20")
         tmpLine = CSED_RemoveNoCase(tmpLine, "declare\x20")
      ELSEIF INSTR(UCASE$(tmpLine), " BDECL ") AND INSTR(UCASE$(tmpLine), " ALIAS ") THEN
         tmpLine = CSED_RemoveNoCase(tmpLine, "\x20bdecl\x20")
         tmpLine = CSED_RemoveNoCase(tmpLine, "declare\x20")
      ELSEIF INSTR(UCASE$(tmpLine), " SDECL ") AND INSTR(UCASE$(tmpLine), " ALIAS ") THEN
         tmpLine = CSED_RemoveNoCase(tmpLine, "\x20sdecl\x20")
         tmpLine = CSED_RemoveNoCase(tmpLine, "declare\x20")
      END IF

      IF INSTR(UCASE$(tmpLine), "CALLBACK FUNCTION ") THEN
         tmpLine = CSED_RemoveNoCase(tmpLine, "callback\x20")
      END IF

      ' // Deal with DECLARE Functions and Subs
      IF INSTR(UCASE$(tmpLine), "DECLARE ") AND INSTR(UCASE$(tmpLine), " LIB ") THEN
         tmpLine = CSED_RemoveNoCase(tmpLine, "declare\x20")
         tmpLine = TRIM$(tmpLine)
         tmpLib = INSTR(UCASE$(tmpLine), " LIB ")
         tmpParen = INSTR(UCASE$(tmpLine), "(")
         tmpPreLib = MID$(tmpLine, 1, tmpLib - 1)
         tmpPreLib = RTRIM$(tmpPreLib)
         tmpPostParen = MID$(tmpLine, tmpParen)
         IF RIGHT$(tmpPreLib, 1) <> " " THEN
            tmpPreLib = tmpPreLib + " "
         END IF
         tmpLine = tmpPreLib & tmpPostParen
      END IF

      IF INSTR(UCASE$(tmpLine), "DECLARE ") AND INSTR(UCASE$(tmpLine), " IMPORT ") THEN
         tmpLine = CSED_RemoveNoCase(tmpLine, "declare\x20")
         tmpLine = TRIM$(tmpLine)
         tmpLib = INSTR(UCASE$(tmpLine), " IMPORT ")
         tmpParen = INSTR(UCASE$(tmpLine), "(")
         tmpPreLib = MID$(tmpLine, 1, tmpLib - 1)
         tmpPreLib = RTRIM$(tmpPreLib)
         tmpPostParen = MID$(tmpLine, tmpParen)
         IF RIGHT$(tmpPreLib, 1) <> " " THEN
            tmpPreLib = tmpPreLib + " "
         END IF
         tmpLine = tmpPreLib & tmpPostParen
      END IF

      ' // Deal with DECLARE Functions and Subs that have only LIB and ALIAS on the same line
      IF INSTR(UCASE$(tmpLine), " LIB ") AND INSTR(UCASE$(tmpLine), " ALIAS ") THEN
         tmpLine = TRIM$(tmpLine)
         tmpLib = INSTR(UCASE$(tmpLine), " LIB ")
         tmpParen = INSTR(UCASE$(tmpLine), "(")
         tmpPreLib = MID$(tmpLine, 1, tmpLib - 1)
         tmpPreLib = RTRIM$(tmpPreLib)
         tmpPostParen = MID$(tmpLine, tmpParen)
         IF RIGHT$(tmpPreLib, 1) <> " " THEN
            tmpPreLib = tmpPreLib + " "
         END IF
         tmpLine = tmpPreLib & tmpPostParen
         IF INSTR(UCASE$(lastLine), "SUB ") THEN
            IF INSTR(UCASE$(tmpLine), "SUB ") <= 0 THEN
               tmpLine = $CRLF & "SUB " & TRIM$(tmpLine)
            END IF
         ELSE
            ' // Default to FUNCTION
            IF INSTR(UCASE$(tmpLine), "FUNCTION ") <= 0 THEN
               tmpLine = $CRLF & "FUNCTION " & TRIM$(tmpLine)
            END IF
         END IF
      END IF

      IF INSTR(UCASE$(tmpLine), " IMPORT ") AND INSTR(UCASE$(tmpLine), " ALIAS ") THEN
         tmpLine = TRIM$(tmpLine)
         tmpLib = INSTR(UCASE$(tmpLine), " IMPORT ")
         tmpParen = INSTR(UCASE$(tmpLine), "(")
         tmpPreLib = MID$(tmpLine, 1, tmpLib - 1)
         tmpPreLib = RTRIM$(tmpPreLib)
         tmpPostParen = MID$(tmpLine, tmpParen)
         IF RIGHT$(tmpPreLib, 1) <> " " THEN
            tmpPreLib = tmpPreLib + " "
         END IF
         tmpLine = tmpPreLib & tmpPostParen
         IF INSTR(UCASE$(lastLine), "SUB ") THEN
            IF INSTR(UCASE$(tmpLine), "SUB ") <= 0 THEN
               tmpLine = $CRLF & "SUB " & TRIM$(tmpLine)
            END IF
         ELSE
            ' // Default to FUNCTION
            IF INSTR(UCASE$(tmpLine), "FUNCTION ") <= 0 THEN
               tmpLine = $CRLF & "FUNCTION " & TRIM$(tmpLine)
            END IF
         END IF
      END IF

      ' // Deal with Simple Alias Functions and Subs
      IF INSTR(UCASE$(tmpLine), " ALIAS ") AND INSTR(UCASE$(tmpLine), " LIB ") <= 0 AND INSTR(tmpLine, CHR$(34)) THEN
         IF INSTR(UCASE$(tmpLine), "FUNCTION ") OR INSTR(UCASE$(tmpLine), "SUB ") THEN
            tend = INSTR(UCASE$(tmpLine), " ALIAS ")
            tmpD = MID$(tmpLine, 1, tend)
            tmpD = TRIM$(tmpD)
            tmpParen = INSTR(UCASE$(tmpLine), "(")
            tmpPostParen = MID$(tmpLine, tmpParen)
            IF RIGHT$(tmpD, 1) <> " " THEN tmpLine = tmpD & " "
            tmpLine = tmpD & tmpPostParen
         END IF
      END IF

      IF INSTR(UCASE$(tmpLine), " ALIAS ") AND INSTR(UCASE$(tmpLine), " IMPORT ") <= 0 AND INSTR(tmpLine, CHR$(34)) THEN
         IF INSTR(UCASE$(tmpLine), "FUNCTION ") OR INSTR(UCASE$(tmpLine), "SUB ") THEN
            tend = INSTR(UCASE$(tmpLine), " ALIAS ")
            tmpD = MID$(tmpLine, 1, tend)
            tmpD = TRIM$(tmpD)
            tmpParen = INSTR(UCASE$(tmpLine), "(")
            tmpPostParen = MID$(tmpLine, tmpParen)
            IF RIGHT$(tmpD, 1) <> " " THEN tmpLine = tmpD & " "
            tmpLine = tmpD & tmpPostParen
         END IF
      END IF

      ' // Convert the older param notation for the reg ex
      REPLACE "%()" WITH "() AS INTEGER" IN tmpLine
      REPLACE "##()" WITH "() AS EXT" IN tmpLine
      REPLACE "!()" WITH "() AS SINGLE" IN tmpLine
      REPLACE "@()" WITH "() AS CUR" IN tmpLine
      REPLACE "#()" WITH "() AS DOUBLE" IN tmpLine
      REPLACE "&()" WITH "() AS LONG" IN tmpLine
      REPLACE "&&()" WITH "() AS QUAD" IN tmpLine
      REPLACE "?()" WITH "() AS BYTE" IN tmpLine
      REPLACE "??()" WITH "() AS WORD" IN tmpLine
      REPLACE "???()" WITH "() AS DWORD" IN tmpLine
      REPLACE "$()" WITH "() AS STRING" IN tmpLine
      REPLACE "%" WITH " AS INTEGER" IN tmpLine
      REPLACE "##" WITH " AS EXT" IN tmpLine
      REPLACE "!" WITH " AS SINGLE" IN tmpLine
      REPLACE "@" WITH " AS CUR" IN tmpLine
      REPLACE "#" WITH " AS DOUBLE" IN tmpLine
      REPLACE "&" WITH " AS LONG" IN tmpLine
      REPLACE "&&" WITH " AS QUAD" IN tmpLine
      REPLACE "?" WITH " AS BYTE" IN tmpLine
      REPLACE "??" WITH " AS WORD" IN tmpLine
      REPLACE "???" WITH " AS DWORD" IN tmpLine
      REPLACE "$" WITH " AS STRING" IN strIn
      ' // Remove comments we don't need them for this
      IF INSTR(tmpLine, "'") THEN
         tmpLine = EXTRACT$(tmpLine, "'")
      END IF

      IF INSTR(tmpLine, "REM") THEN
         tmpLine = EXTRACT$(tmpLine, "REM")
      END IF

      ' // Remove line continuations as well
      tmpLine = TRIM$(tmpLine)
      IF RIGHT$(tmpLine, 1) = "_" THEN
         tmpLine = TRIM$(MID$(tmpLine, 1, LEN(tmpLine) - 1)) & " "
      ELSE
         tmpLine = tmpLine & $CRLF
      END IF

   END IF

   FUNCTION = tmpLine

END FUNCTION
' ========================================================================================

' ========================================================================================
' This function takes the code and breaks it into lines for easy scanning/parsing.
' ========================================================================================
SUB CSED_CodeString (BYVAL hCodetipsFile AS LONG, BYVAL strIn AS STRING)

   LOCAL Mask AS STRING
   LOCAL PosVar AS LONG
   LOCAL LenVar AS LONG
   LOCAL StartVar AS LONG
   LOCAL buf AS STRING
   LOCAL TheWord AS STRING
   LOCAL SaveLast AS STRING

   StartVar = 1
   PosVar   = 1
   Mask = "\n"                       ' \n = newline

   AfxDoEvents
   WHILE PosVar
      IF g_AbortCodetips THEN EXIT SUB
      REGEXPR Mask IN strIn AT StartVar TO PosVar, LenVar
      IF PosVar THEN
         ' // Must remove the newline character
         TheWord = MID$(strIn, StartVar, PosVar - StartVar - 1)
         TheWord = CSED_CleanLine(TheWord, SaveLast)
         IF LEFT$(TheWord, 1) = "%" OR LEFT$(TheWord, 1) = "$" THEN
            ' // If it is a constant save it
            CSED_AddConstant(hCodetipsFile, TheWord)
         ELSE
            ' // Add the line to the buffer
            buf = buf & TheWord
         END IF
         SaveLast = TheWord
         StartVar = PosVar + LenVar
      END IF
   WEND

   StartVar = 1
   PosVar   = 1
   Mask = "^[\x20]*((SUB)|(FUNCTION))[\x20]+([a-z]+)([a-z0-9_\*(\) ,]*$)"

   AfxDoEvents
   WHILE PosVar
      IF g_AbortCodetips THEN EXIT SUB
      REGEXPR Mask IN buf AT StartVar TO PosVar, LenVar
      TheWord = MID$(buf, Posvar, Lenvar)
      ' // Write the codetip to the database
      CSED_AddCodeTip hCodetipsFile, TheWord
      StartVar = PosVar + LenVar + 1
   WEND

END SUB
' ========================================================================================

' ========================================================================================
' This is the main function call
' ========================================================================================
SUB CSED_GenerateTips (BYVAL hwnd AS DWORD, BYVAL hCodetipsFile AS LONG, BYVAL strPath AS STRING)

   LOCAL fileNumber AS LONG
   LOCAL buf AS STRING

   TRY
      fileNumber = FREEFILE
      OPEN strPath FOR BINARY AS fileNumber BASE = 0
      GET$ fileNumber, LOF(fileNumber), buf
      CLOSE fileNumber
      CSED_CodeString(hCodetipsFile, buf)
   CATCH
      CSED_MsgBox(hwnd, "Error " & FORMAT$(ERR) & " opening the file ", %MB_OK, "Error!")
   END TRY

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
   szMutex = "CSED_CODETIPS_MUTEX"
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
      %WS_EX_WINDOWEDGE, CODEPTR(CSED_WindowProc))
   pWindow.SetClientSize 320, 195
   ' // Center the window
   pWindow.CenterWindow hwnd

   ' // Set the icons
   pWindow.BigIcon = LoadIcon(hInstance, BYVAL %IDI_CODETIPS32)
   pWindow.SmallIcon = LoadIcon(hInstance, BYVAL %IDI_CODETIPS16)

   ' // Add the controls
   LOCAL hCtl AS DWORD

   hCtl = pWindow.AddLabel(hwnd, -1, "Include file path", 8, 8, 150, 16, -1)
   hCtl = pWindow.AddTextBox(hwnd, %IDC_FINDINC, "", 8, 24, 270, 22, -1, %WS_EX_CLIENTEDGE)
   hCtl = pWindow.AddButton(hwnd, %IDB_FINDINC, "...", 282, 22, 30, 24, -1)
   hCtl = pWindow.AddButton(hwnd, %IDOK, "&Append", 8, 63, 70, 25, %BS_DEFPUSHBUTTON)
   hCtl = pWindow.AddButton(hwnd, %IDB_ABORTINC, "A&bort", 86, 63, 70, 25, -1)
   hCtl = pWindow.AddButton(hwnd, %IDB_RESETINC, "&Reset", 164, 63, 70, 25, -1)
   hCtl = pWindow.AddButton(hwnd, %IDCANCEL, "E&xit", 242, 63, 70, 25, -1)
   hCtl = pWindow.AddLabel(hwnd, %IDC_LABELINC, "", 8, 104, 307, 80, %WS_CHILD OR %WS_VISIBLE OR %WS_BORDER, %WS_EX_CLIENTEDGE)

   SetFocus GetDlgItem(hwnd, %IDC_FINDINC)

   ' // Default message pump
   pWindow.DoEvents(nCmdShow)

END FUNCTION
' ########################################################################################

' ========================================================================================
' Main window procedure
' ========================================================================================
FUNCTION CSED_WindowProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL  iCount        AS LONG
   LOCAL  iNumFiles     AS LONG
   STATIC hFocus        AS DWORD
   LOCAL  strFilePath   AS STRING
   STATIC strFileList   AS STRING
   LOCAL  strDbPath     AS STRING
   LOCAL  Result        AS LONG
   STATIC strLastDir    AS STRING
   STATIC hCodetipsFile AS DWORD

   SELECT CASE uMsg

      CASE %WM_NCACTIVATE
         ' // Save the handle of the control that has the focus
         IF wParam = 0 THEN hFocus = GetFocus
         ' // Note: Don't use EXIT FUNCTION

      CASE %WM_SETFOCUS
         ' // Post a message to set the focus later, since some
         ' // Windows actions can steal it if we set it here
         IF hFocus THEN
            PostMessage hWnd, %WM_USER + 999, hFocus, 0
            hFocus = 0
         END IF

      CASE %WM_USER + 999
         ' // Set the focus and show the line an column in the status bar
         IF wParam THEN SetFocus wParam
         EXIT FUNCTION

      CASE %WM_CTLCOLORSTATIC
         IF GetDlgCtrlID(lParam) = %IDC_LABELINC THEN
            SetTextColor wParam, &H00FF0000???
            ' // Return handle of brush used to paint background
            FUNCTION = GetSysColorBrush(%COLOR_WINDOW)
            EXIT FUNCTION
         END IF

      CASE %WM_COMMAND

         SELECT CASE LO(WORD, wParam)

            CASE %IDOK
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  g_AbortCodetips = %FALSE
                  strDbPath = EXE.PATH$ & $CODETIPSDB
                  IF ISFALSE ISFILE(strDbPath) THEN
                     Result = CSED_CreateCodeTipsDatabase(hwnd, strDbPath)
                     IF Result THEN
                        CSED_MsgBox(hwnd, strDbPath & $CRLF & "Error " & FORMAT$(Result) & " creating the file", %MB_OK OR %MB_ICONERROR, "Tsunami Error!")
                        EXIT FUNCTION
                     END IF
                  END IF
                  ' // Open the file if it is closed
                  IF hCodetipsFile < 1 OR ISFALSE trm_FileIsOpen(hCodetipsFile) THEN
                     hCodetipsFile = trm_Open(strDbPath, %TRUE)
                     IF hCodetipsFile < 1 THEN
                        CSED_MsgBox(hwnd, strDbPath & $CRLF & "Error " & FORMAT$(hCodetipsFile) & " opening the file", %MB_OK OR %MB_ICONERROR, "Tsunami Error!")
                        EXIT FUNCTION
                     END IF
                  END IF
                  AfxSetWindowText GetDlgItem(hwnd, %IDC_LABELINC), "Please wait!"
                  IF PARSECOUNT(strFileList, CHR$(0)) > 2 THEN
                     ' // Parse out the file list
                     FOR iCount = 2 TO (PARSECOUNT(strFileList, CHR$(0)) - 1)
                        strFilePath = PARSE$(strFileList, CHR$(0), 1) & "\" & PARSE$(strFileList, CHR$(0), iCount)
                        IF ISFALSE ISFILE(strFilePath) THEN
                           CSED_MsgBox(hwnd, strFilePath & $CRLF & "File doesn' exist", %MB_OK OR %MB_ICONERROR, "Error!")
                           EXIT FOR
                        END IF
                        AfxSetWindowText GetDlgItem(hwnd, %IDC_LABELINC), "Please wait while processing the file " & strFilePath
                        ' // Generate the codetips
                        CSED_GenerateTips(hwnd, hCodetipsFile, strFilePath)
                     NEXT
                  END IF
                  AfxSetWindowText GetDlgItem(hwnd, %IDC_LABELINC), "Finished!"
                  ' // Close the file
                  trm_Close hCodetipsFile
                  hCodetipsFile = 0
                  EXIT FUNCTION
               END IF

            CASE %IDCANCEL
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  SendMessage hwnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF

            CASE %IDB_FINDINC
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  AfxSetWindowText GetDlgItem(hwnd, %IDC_LABELINC), ""
                  IF LEN(strLastDir) = 0 THEN strLastDir = CURDIR$
                  DISPLAY OPENFILE hwnd, , , "Choose your incudle file(s)", strLastDir, _
                     CHR$("Includes",0,"*.INC",0,"Basic",0,"*.BAS;*.INC",0,"All Files",0,"*.*",0), _
                     "", "", %OFN_ALLOWMULTISELECT OR %OFN_FILEMUSTEXIST TO strFileList, iNumFiles
                  IF LEN(strFileList) THEN
                     IF PARSECOUNT(strFileList, CHR$(0)) > 2 THEN
                        strLastDir = LEFT$(strFileList, INSTR(strFileList, CHR$(0)) - 1)
                     ELSE
                        ' // Only one file selected
                        strLastDir = PATHNAME$(PATH, strFileList)
                     END IF
                     IF RIGHT$(strLastDir, 1) = "\" THEN strLastDir = LEFT$(strLastDir, LEN(strLastDir) - 1)
                  END IF
                  IF LEN(strFileList) THEN
                     IF PARSECOUNT(strFileList, CHR$(0)) = 2 THEN
                        ' // Only one file selected
                        strFileList = RTRIM$(PATHNAME$(PATH, strFileList),"\") & CHR$(0) & PATHNAME$(NAMEX, strFileList)
                     END IF
                     AfxSetWindowText GetDlgItem(hwnd, %IDC_FINDINC), STR$(PARSECOUNT(strFileList, CHR$(0)) - 2) & " file(s) selected."
                  ELSE
                     AfxSetWindowText GetDlgItem(hwnd, %IDC_FINDINC), "No files selected!"
                  END IF
                  SetFocus GetDlgItem(hwnd, %IDOK)
                  EXIT FUNCTION
               END IF

            CASE %IDB_RESETINC
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                     strDbPath = EXE.PATH$ & $CODETIPSDB
                     IF ISFILE(strDbPath) THEN
                        IF trm_FileIsOpen(hCodetipsFile) THEN
                           CSED_MsgBox(hwnd, "Can't delete the file because it is being used by another application." & $CRLF & "Close all instances of the editor first.", %MB_OK OR %MB_ICONERROR, "Tsunami Error!")
                           EXIT FUNCTION
                        END IF
                     END IF
                     Result = CSED_CreateCodeTipsDatabase(hwnd, strDbPath)
                     IF Result = -1 THEN   ' // Canceled
                        AfxSetWindowText GetDlgItem(hwnd, %IDC_LABELINC), ""
                     ELSEIF Result THEN
                        CSED_MsgBox(hwnd, strDbPath & $CRLF & "Error " & FORMAT$(Result) & " creating the file", %MB_OK OR %MB_ICONERROR, "Tsunami Error!")
                        AfxSetWindowText GetDlgItem(hwnd, %IDC_LABELINC), ""
                     ELSE
                        AfxSetWindowText GetDlgItem(hwnd, %IDC_LABELINC), "Finished!"
                     END IF
                     hCodetipsFile = 0
                  EXIT FUNCTION
               END IF

            CASE %IDB_ABORTINC
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  g_AbortCodetips = %TRUE
                  EXIT FUNCTION
               END IF

         END SELECT

      CASE %WM_DESTROY
         ' // Close the main window
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
