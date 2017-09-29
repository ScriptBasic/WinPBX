' ########################################################################################
' CSED Editor
' File: CSED_HELP.INC
' Contents: Help procedures
' Copyright (c) 2012 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ========================================================================================
' Search for context help
' ========================================================================================
SUB CSED_SearchContextHelp (BYVAL hwnd AS DWORD)

   LOCAL r             AS LONG                   ' // Result code
   LOCAL x             AS LONG                   ' // Starting position of a word
   LOCAL y             AS LONG                   ' // Ending position of a word
   LOCAL curPos        AS LONG                   ' // Current position
   LOCAL p             AS LONG                   ' // General purpose variable
   LOCAL hlk           AS HH_AKLINK              ' // HTML Help
   LOCAL strPBKeywords AS STRING                 ' // PB Keywords
#IF %DEF(%UNICODE)
   LOCAL szPath        AS WSTRINGZ * %MAX_PATH   ' // Path
   LOCAL buffer        AS WSTRING                ' // General purpose buffer
#ELSE
   LOCAL szPath        AS ASCIIZ * %MAX_PATH     ' // Path
   LOCAL buffer        AS STRING                 ' // General purpose buffer
#ENDIF

   ' // Retrieve the word under the caret and activate the compiler's help file
   ' // if it is a Power Basic keyword or the Windows 32 help file is it is not.
   strPBKeywords = pSed.PBKeywords
   ' // Retrieve the current position
   curPos = SCI_GetCurrentPos(pSed.hEdit)
   ' // Retrieve the starting position of the word
   x = SCI_WordStartPosition(pSed.hEdit, curPos, %TRUE)
   ' // Retrieve the ending position of the word
   y = SCI_WordEndPosition(pSed.hEdit, curPos, %TRUE)
   IF y > x THEN
      ' // Prepare the buffer
      buffer = SPACE$(y - x + 1)
      ' // Read also the characters before and after the word
      IF x > 0 THEN x = x - 1
      buffer = buffer + " "
      y = y + 1
      buffer = buffer + " "
      ' // Text range
      buffer = SCI_GetTextRange(pSed.hEdit, x, y)
      ' // Remove the $NUL
      p = INSTR(buffer, CHR$(0))
      IF p THEN  buffer = LEFT$(buffer, p - 1)
      ' // We need to preserve $ and # for PowerBasic keywords
      IF RIGHT$(buffer, 1) <> "$" THEN buffer = LEFT$(buffer, LEN(buffer) - 1)
      IF x > 0 THEN
         IF LEFT$(buffer, 1) <> "%" AND LEFT$(buffer, 1) <> "#" THEN buffer = MID$(buffer, 2)
      END IF
      ' // If it begins with % and it is not a PB keyword, then remove it to call Win32Help
      IF LEFT$(buffer, 1) = "%" AND INSTR(strPBKeywords, " " & LCASE$(MID$(buffer, 2)) & " ") = 0 THEN buffer = MID$(buffer, 2)
      IF LEFT$(buffer, 1) = "#" AND INSTR(strPBKeywords, " " & LCASE$(MID$(buffer, 2)) & " ") = 0 THEN buffer = MID$(buffer, 2)
      buffer = TRIM$(buffer)
      IF LEN(buffer) THEN
         IF INSTR(strPBKeywords, " " & LCASE$(buffer) & " ") THEN
            ' // If it is a Power Basic keyword, get the Default compiler and
            ' // call the appropiate help file, else call the Win32 help file
            szPath = ""
            IF pSed.SelectedCompiler = 1 THEN
               szPath = pSed.PBWinHelpPath
            ELSE
               szPath = pSed.PBCCHelpPath
            END IF
            IF LEN(szPath) THEN
               IF RIGHT$(UCASE$(szPath), 4) = ".HLP" THEN
                  WinHelp hwnd, szPath, %HELP_KEY, BYVAL STRPTR(buffer)
               ELSEIF RIGHT$(UCASE$(szPath), 4) = ".CHM" THEN
                  hlk.cbStruct     = SIZEOF(hlk)
                  hlk.pszKeywords  = STRPTR(buffer)
                  hlk.fIndexOnFail = %TRUE
'                  HtmlHelp hwnd, szPath, %HH_DISPLAY_TOPIC, %NULL
'                  HtmlHelp hwnd, szPath, %HH_KEYWORD_LOOKUP, VARPTR(hlk)
                  ' // Use it modeless, because if we pass a parent windows to make
                  ' // it modal, it hangs in some Windows versions, such Windows 7
                  HtmlHelp 0, szPath, %HH_DISPLAY_TOPIC, %NULL
                  HtmlHelp 0, szPath, %HH_KEYWORD_LOOKUP, VARPTR(hlk)
               END IF
            END IF
         ELSE
            ' // Get the path of the file
            szPath = AfxGetWindowText(MdiGetActive(pSed.hwndClient))
            IF pSed.UseMSDNHelp = %BST_CHECKED THEN CSED_MSDNHELP hwnd, buffer
         END IF
      END IF
   ELSE
      buffer = ""
      szPath = ""
      IF pSed.SelectedCompiler = 1 THEN
         szPath = pSed.PBWinHelpPath
      ELSE
         szPath = pSed.PBCCHelpPath
      END IF
      IF LEN(szPath) THEN r = ShellExecute(hwnd, "open", szPath, "", "", %SW_SHOWNORMAL)
   END IF

END SUB
' ========================================================================================

' ========================================================================================
' Displays the MSDN help
' Collection example: "ms-help://MS.PSDKSVR2003R2.1033"
' Full path example (you need to retrieve it in the properties of the "Platform SDK Documentation" shortcut):
' "C:\Program Files\Common Files\Microsoft Shared\help\dexplore.exe /helpcol ms-help://MS.PSDKSVR2003R2.1033"
' ========================================================================================
#IF %DEF(%UNICODE)
SUB CSED_MSDNHELP (BYVAL hwnd AS DWORD, OPTIONAL BYVAL buffer AS WSTRING)
#ELSE
SUB CSED_MSDNHELP (BYVAL hwnd AS DWORD, OPTIONAL BYVAL buffer AS STRING)
#ENDIF

   LOCAL p AS LONG
#IF %DEF(%UNICODE)
   LOCAL szPath AS WSTRINGZ * %MAX_PATH
   LOCAL szCaption AS WSTRINGZ * %MAX_PATH
#ELSE
   LOCAL szPath AS ASCIIZ * %MAX_PATH
   LOCAL szCaption AS ASCIIZ * %MAX_PATH
#ENDIF
   LOCAL bstrCollection AS WSTRING

   ' // Retrieve the name of the collection, if any
   szPath = pSed.SDKHelpPath
   IF LEN(szPath) THEN
      p = INSTR(LCASE$(szPath), "ms-help://")
      IF p THEN
         bstrCollection = MID$(szPath, p)
         p = INSTR(11, bstrCollection, "/")
         IF p THEN bstrCollection = LEFT$(bstrCollection, p - 1)
      END IF
   END IF

   LOCAL pVsHelpObj AS IVsHelp
   pVsHelpObj = pSed.VsHelpObj
   IF ISNOTHING(pVsHelpObj) THEN pVsHelpObj = ANYCOM "DExplore.AppObj"
   pSed.VsHelpObj = pVsHelpObj
   IF ISNOTHING(pVsHelpObj) THEN
      CSED_MsgBox hwnd, "Document Explorer is not installed", %MB_OK OR %MB_ICONERROR, "Error"
      EXIT SUB
   END IF

   TRY
      IF LEN(bstrCollection) THEN pVsHelpObj.SetCollection(bstrCollection, "")
      IF LEN(buffer) THEN
         pVsHelpObj.DisplayTopicFromKeyword buffer
      ELSE
         pVsHelpObj.Search
'         pVsHelpObj.Index
'         pVsHelpObj.Contents
      END IF
   CATCH
      CSED_MsgBox hwnd, "Error &H" & HEX$(OBJRESULT, 8) & " displaying the Platform SDK Help", %MB_OK OR %MB_ICONERROR, "Error"
   END TRY

   ' // Put the window in the foreground
   LOCAL hwndExplorer AS DWORD
   hwndExplorer = FindWindow("wndclass_desked_gsk", "")
   IF hwndExplorer THEN
'      szCaption = Window_GetText(hwndExplorer)
'      IF LEFT$(szCaption, 22) = "Microsoft Platform SDK" THEN
         IF IsIconic(hwndExplorer) OR IsZoomed(hwndExplorer) <> 0 THEN
            ShowWindow hwndExplorer, %SW_RESTORE
         END IF
         SetForegroundWindow hwndExplorer
'      END IF
   END IF

END SUB
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
' About box
' ========================================================================================
SUB CSED_AboutBox (BYVAL hwnd AS DWORD)

   LOCAL strCaption AS STRING
   LOCAL strMessage AS STRING

   strCaption = "About " & $PROGNAME & " " & $CSEDVERSION
   strMessage = $PROGNAME & " " & $CSEDVERSION & $CRLF & _
                "MDI code editor for PowerBASIC" & $CRLF & _
                "Editing component: Scintilla" & $CRLF & _
                $CSEDCOPYRIGHT & $CRLF & _
                $MAILADDRESS

   CSED_MsgBox hwnd, strMessage, %MB_OK OR %MB_ICONINFORMATION, strCaption

END SUB
' ========================================================================================
