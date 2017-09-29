' ########################################################################################
' CSED Editor
' File: CSED_PRINT.INC
' Contents: HTML print/print preview dialog
' Copyright (c) 2012 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

%IDC_WB_CONTROL = 101
%IDC_WB_PRINT   = 102
%IDC_WB_PREVIEW = 103

' ========================================================================================
' Print using the Print Preview of the WebBrowser control
' ========================================================================================
SUB CSED_WB_PrintPreview (BYVAL hParent AS DWORD, BYVAL strText AS STRING)

   ' // Create an instance of the class
   LOCAL pPrint AS IWindow
   pPrint = CLASS "CWindow"
   IF ISNOTHING(pPrint) THEN EXIT SUB

   ' // Create the main window
   LOCAL hwnd AS DWORD
'   hwnd = pPrint.CreateWindow(hParent, "Print Preview", 0, 0, 700, 450, _
'          %WS_VISIBLE OR %WS_CAPTION OR %WS_POPUPWINDOW, %WS_EX_TOOLWINDOW OR %WS_EX_WINDOWEDGE, _
'          CODEPTR(CSED_WB_PrintPreview_WindowProc))
   hwnd = pPrint.CreateWindow(hParent, "Print Preview", 0, 0, 0, 0, _
          %WS_VISIBLE OR %WS_CAPTION OR %WS_POPUPWINDOW, %WS_EX_WINDOWEDGE, _
          CODEPTR(CSED_WB_PrintPreview_WindowProc))
   pPrint.SetClientSize 700, 440
   pPrint.CenterWindow(hwnd, hParent)

   ' // Add the WebBrowser control
   LOCAL hCtl AS DWORD
   strText = "MSHTML:" & strText
   hCtl = pPrint.AddWebBrowserControl(hwnd, %IDC_WB_CONTROL, strText, NOTHING, 0, 0, pPrint.ClientWidth, pPrint.ClientHeight - 40, -1)

   ' // Add the buttons
   pPrint.AddButton(hwnd, %IDC_WB_PRINT, "&Print", pPrint.ClientWidth - 280, pPrint.ClientHeight - 30, 75, 23, -1)
   pPrint.AddButton(hwnd, %IDC_WB_PREVIEW, "Pre&view", pPrint.ClientWidth - 185, pPrint.ClientHeight - 30, 75, 23, -1)
   pPrint.AddButton(hwnd, %IDCANCEL, "&Close", pPrint.ClientWidth - 90, pPrint.ClientHeight - 30, 75, 23, -1)

   ' // Default message pump (you can replace it with your own)
   pPrint.DoEvents

END SUB
' ========================================================================================

' ========================================================================================
' Editor options callback function.
' ========================================================================================
FUNCTION CSED_WB_PrintPreview_WindowProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL pIWebBrowser2 AS IWebBrowser2           ' // IWebBrowser2 interface reference
#IF %DEF(%UNICODE)
   LOCAL szText AS WSTRINGZ * 255                ' // General purpose variable
   LOCAL szPath AS WSTRINGZ * %MAX_PATH          ' // File path
#ELSE
   LOCAL szText AS ASCIIZ * 255                  ' // General purpose variable
   LOCAL szPath AS ASCIIZ * %MAX_PATH            ' // File path
#ENDIF

   SELECT CASE uMsg

      CASE %WM_CREATE
         ' // Disable the owner of the modal window
         EnableWindow GetWindow(hwnd, %GW_OWNER), %FALSE

      CASE %WM_COMMAND

         SELECT CASE LO(WORD, wParam)

            CASE %IDCANCEL
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  SendMessage hwnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF

            CASE %IDC_WB_PRINT
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  ' // Gets a reference to the IWebBrowser2 interface
                  pIWebBrowser2 = OC_GetDispatch(GetDlgItem(hwnd, %IDC_WB_CONTROL))
                  IF ISOBJECT(pIWebBrowser2) THEN
                     pIWebBrowser2.ExecWB %OLECMDID_PRINT, %OLECMDEXECOPT_PROMPTUSER
                     ' // Releases the interface
                     pIWebBrowser2 = NOTHING
                  END IF
               END IF
               EXIT FUNCTION

            CASE %IDC_WB_PREVIEW
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  ' // Gets a reference to the IWebBrowser2 interface
                  pIWebBrowser2 = OC_GetDispatch(GetDlgItem(hwnd, %IDC_WB_CONTROL))
                  IF ISOBJECT(pIWebBrowser2) THEN
                     pIWebBrowser2.ExecWB %OLECMDID_PRINTPREVIEW, %OLECMDEXECOPT_PROMPTUSER
                     ' // Releases the interface
                     pIWebBrowser2 = NOTHING
                  END IF
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
' BAS to colored HTML converter
' Based on Börje Hagsten's WebCoder utility.
' ========================================================================================
FUNCTION CSED_CvBasToHtml (BYVAL bShow AS LONG, OPTIONAL BYVAL bSelectedText AS LONG) AS STRING

   LOCAL i             AS LONG       ' // Loop counter
   LOCAL stopPos       AS LONG       ' // Stop position
   LOCAL Result        AS LONG       ' // Word position
   LOCAL wFlag         AS LONG       ' // Word flag
   LOCAL remFlag       AS LONG       ' // REM flag
   LOCAL dqFlag        AS LONG       ' // Double quotes flag
   LOCAL isRem         AS LONG       ' // Boolean flag
   LOCAL blueStr       AS STRING     ' // HTML blue color
   LOCAL greenStr      AS STRING     ' // HTML green color
   LOCAL redStr        AS STRING     ' // HTML red color
   LOCAL pinkStr       AS STRING     ' // HTML pink color
   LOCAL PBFstr        AS STRING     ' // PBForms color
   LOCAL beginBlock    AS STRING     ' // HTML begin block
   LOCAL endBlock      AS STRING     ' // HTML end block
   LOCAL htmlHeader    AS STRING     ' // HTML header
   LOCAL htmlFooter    AS STRING     ' // HTML footer
   LOCAL txt           AS STRING     ' // Input buffer
   LOCAL lCaseBuf      AS STRING     ' // Lowercase input buffer
   LOCAL outBuf        AS STRING     ' // Output buffer
   LOCAL pLet          AS BYTE PTR   ' // Pointer to input string
   LOCAL pLet2         AS BYTE PTR   ' // Pointer to output string
   LOCAL tmpWord       AS STRING     ' // Intermediate result
   LOCAL hMdi          AS DWORD      ' // MDI window handle
   LOCAL pSci          AS DWORD      ' // Scintilla direct pointer
   LOCAL bIsNotEmpty   AS LONG       ' // Flag: Line is not empty
   LOCAL PrevChar      AS LONG       ' // Previous character
   LOCAL strPBKeywords AS STRING     ' // PB keywords
   LOCAL TabSize       AS LONG       ' // Tab size
   LOCAL defFontSize   AS STRING     ' // Default font size in points
   LOCAL defFontName   AS STRING     ' // Default font name

   IF pSed.hEdit = 0 THEN EXIT FUNCTION
   ' // PB keywords
   strPBKeywords = pSed.PBKeywords
   ' // Get direct pointer for faster access
   pSci = SCI_GetDirectPointer(pSed.hEdit)
   IF pSci = 0 THEN EXIT FUNCTION
   ' // Get the text
   IF bSelectedText THEN txt = SCIP_GetSelText(pSci)
   IF txt = "" THEN txt = SCIP_GetText(pSci)
   IF txt = "" THEN EXIT FUNCTION
   ' // Replace tabs with spaces, if needed
   IF INSTR(txt, $TAB) THEN
      TabSize = SCIP_GetTabWidth(pSci)
      IF TabSize < 1 THEN EXIT FUNCTION
      REDIM rgTxt(1 TO PARSECOUNT(txt, $CRLF)) AS STRING
      PARSE txt, rgTxt(), $CRLF
      IF UBOUND(rgTxt) = -1 THEN EXIT FUNCTION
      FOR i = LBOUND(rgTxt) TO UBOUND(rgTxt)
         IF INSTR(rgTxt(i), $TAB) THEN
            rgTxt(i) = TAB$(rgTxt(i), TabSize)
         END IF
      NEXT
      txt = JOIN$(rgTxt(), $CRLF)
   END IF
   ' // Default font size
   defFontSize = FORMAT$(pSed.DefaultFontSize)
   ' // Default font name
   defFontName = pSed.DefaultFontName

   ' // Show hour glass mouse cursor
   SetCursor LoadCursor(BYVAL %NULL, BYVAL %IDC_APPSTARTING)

   htmlHeader   = "<?xml version=""1.0""?>" & $CRLF
   htmlHeader + = "<!DOCTYPE html PUBLIC ""-//W3C//DTD XHTML 1.1//EN"" ""http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd"">" & $CRLF
   htmlHeader + = "<html xmlns=""http://www.w3.org/1999/xhtml"">" & $CRLF
   htmlHeader + = "<head>" & $CRLF
   htmlHeader + = "   <title>" & AfxGetWindowText(MdiGetActive(pSed.hwndClient)) & "</title>" & $CRLF
   htmlHeader + = "   <meta name=""generator"" content=""CSED"" />" & $CRLF
   htmlHeader + = "   <meta http-equiv=""Content-Type"" content=""text/html; charset=ISO-8859-1"" />" & $CRLF
   htmlHeader + = "   <meta http-equiv=""Content-Style-Type"" content=""text/css"" />" & $CRLF
   htmlHeader + = "<style type=""text/css"">" & $CRLF
   htmlHeader + = "/* Text Styles */" & $CRLF
   htmlHeader + = "body, table /* Normal */" & $CRLF
   htmlHeader + = "{" & $CRLF
   htmlHeader + = "   font-size: " & defFontSize & "pt;" & $CRLF
   htmlHeader + = "   font-family: '" & defFontName & "';" & $CRLF
   htmlHeader + = "   font-style: normal;" & $CRLF
'   htmlHeader + = "   font-weight: normal;" & $CRLF
   htmlHeader + = "   font-weight: " &  IIF$(pSed.DefaultFontBold, "bold;", "normal;") & $CRLF
   htmlHeader + = "   color: #000000;" & $CRLF
   htmlHeader + = "   text-decoration: none;" & $CRLF
   htmlHeader + = "}" & $CRLF
   htmlHeader + = "/* Paragraph styles */" & $CRLF
   htmlHeader + = "p /* Normal */" & $CRLF
   htmlHeader + = "{" & $CRLF
   htmlHeader + = "   text-align: left;" & $CRLF
   htmlHeader + = "   text-indent: 0px;" & $CRLF
   htmlHeader + = "   padding: 0px 0px 0px 0px;" & $CRLF
   htmlHeader + = "   margin: 0px 0px 0px 0px;" & $CRLF
   htmlHeader + = "}" & $CRLF
   htmlHeader + = "</style>" & $CRLF
   htmlHeader + = "</head>" & $CRLF
   htmlHeader + = "<body style=""margin: 0px 0px 0px 0px;"">" & $CRLF
   htmlHeader + = "<table width=""100%"" border=""0"" cellspacing=""0"" cellpadding=""5""><tr valign=""top""><td align=""left"">" & $CRLF
   htmlHeader + = "<p>"

   htmlFooter + = "</p>" & $CRLF
   htmlFooter + = "</td>" & $CRLF
   htmlFooter + = "</tr>" & $CRLF
   htmlFooter + = "</table>" & $CRLF
   htmlFooter + = "</body>" & $CRLF
   htmlFooter + = "</html>" & $CRLF

   beginBlock = "<span style=""font-size: " & defFontSize & "pt; font-family: '" & defFontName & "';"">"
   blueStr    = "<span style=""font-size: " & defFontSize & "pt; font-family: '" & defFontName & "'; color: #0000FF;"">"
   greenStr   = "<span style=""font-size: " & defFontSize & "pt; font-family: '" & defFontName & "'; color: #008000;"">"
   pinkStr    = "<span style=""font-size: " & defFontSize & "pt; font-family: '" & defFontName & "'; color: #FF00EE;"">"
   redStr     = "<span style=""font-size: " & defFontSize & "pt; font-family: '" & defFontName & "'; color: #FF0000;"">"
   PBFStr     = "<span style=""font-size: " & defFontSize & "pt; font-family: '" & defFontName & "'; color: #C06400;"">"
   endBlock   = "</span>"

   LOCAL blockLen AS LONG
   blockLen = LEN(blueStr)
   LOCAL endBlockLen AS LONG
   endBlockLen = LEN(endBlock)
   LOCAL beginBlockLen AS LONG
   beginBlockLen = LEN(beginBlock)
   LOCAL bStartBlock AS LONG

   REPLACE "&" WITH "&amp;" IN txt
   REPLACE "<" WITH "&lt;" IN txt

   txt += " "                                           ' // Add a space to ensure last word will be checked if nothing follows it
   OutBuf = STRING$(MAX&(1000000, 10 * LEN(txt) ), 0)   ' // 10 times bigger mem for result should be enough
   lCaseBuf = LCASE$(txt)                               ' // Use lowercase string for compare
   pLet = STRPTR(txt)                                   ' // Pointer to global string (input)
   pLet2 = STRPTR(OutBuf)                               ' // Pointer to output buffer

   FOR i = 1 TO LEN(txt)

      IF @pLet <> 13 AND @pLet <> 10 THEN bIsNotEmpty = %TRUE

      SELECT CASE @pLet

         ' // The characters we need to include in a word
         CASE 65 TO 90, 97 TO 122, 35 TO 38, 48 TO 57, 63, 95
            IF wFlag = 0 AND remFlag = 0 AND dqFlag = 0 THEN
               wFlag = 1
               stopPos = i
            END IF

         CASE 34   ' Double quote -> "
            IF dqFlag = 0 AND remFlag = 0 THEN   ' // If start of string literal...
               IF bStartBlock = 1 THEN
                  POKE$ pLet2, endBlock
                  pLet2 = pLet2 + endBlockLen
                  bStartBlock = 0
               END IF
               POKE$ pLet2, pinkStr              ' //   poke HTML code into output string
               pLet2 = pLet2 + blockLen          ' //   and move pointer forward
               dqFlag = 1                        ' // Set double quote flag
               wFlag = 0                         ' // Since we aee now inside DQ, wordflag is off
            ELSEIF dqFlag = 1 THEN               ' // Should be end of DQ block
               @pLet2 = @pLet                    ' // Set value in output string
               INCR pLet2                        ' // Move one character ahead
               POKE$ pLet2, endBlock             ' // Poke HTML end block string into output
               pLet2 = pLet2 + endBlockLen       ' //   and move pointer forward
               dqFlag = 3                        ' // End of DQ: set DQ flag
            END IF

         CASE 59   ' ASM comment character -> ;
            IF remFlag = 0 AND dqFlag = 2 THEN
               POKE$ pLet2, endBlock             ' // Poke HTML end block string into output
               pLet2 = pLet2 + endBlockLen       ' //   and move pointer forward
               POKE$ pLet2, greenStr
               pLet2 = pLet2 + blockLen
               remFlag = 1
               wFlag = 0
            END IF

         CASE 39   ' Comment character -> '
            IF remFlag = 0 AND dqFlag <> 1 THEN
               IF dqFlag = 2 THEN
                  POKE$ pLet2, endBlock          ' // poke HTML end block string into output
                  pLet2 = pLet2 + endBlockLen    ' //   and move pointer forward
               END IF
               POKE$ pLet2, greenStr
               pLet2 = pLet2 + blockLen
               remFlag = 1
               wFlag = 0
               isRem = 1
            END IF

         CASE 33   ' ASM character -> !
            IF remFlag = 0 AND dqFlag = 0 THEN
               IF bStartBlock = 1 THEN
                  POKE$ pLet2, endBlock
                  pLet2 = pLet2 + endBlockLen
                  bStartBlock = 0
               END IF
               POKE$ pLet2, redStr
               pLet2 = pLet2 + blockLen
               dqFlag = 2
               wFlag = 0
            END IF

         CASE ELSE   ' Word is ready

            IF @pLet = 13 THEN                   ' // If CRLF - end of line
               IF remFlag OR dqFlag THEN         ' // In REM or ASM
                  POKE$ pLet2, endBlock
                  pLet2 = pLet2 + endBlockLen
                  ' // Reset flags
                  remFlag = 0
                  wFlag = 0
                  dqFlag = 0
                  isRem = 0
               END IF
            END IF

            IF @pLet = 10 THEN                   ' // If Line Feed
               IF bStartBlock = 1 THEN
                  POKE$ pLet2, endBlock
                  pLet2 = pLet2 + endBlockLen
                  bStartBlock = 0
               END IF
               POKE$ pLet2, "</p>" & $CRLF & "<p>" & beginBlock
               pLet2 = pLet2 + 9 + beginBlockLen
               bStartBlock = 1
            END IF

            IF wFlag = 1 THEN                                   ' // If we have a word
               tmpWord = MID$(lCaseBuf, stopPos, i - stopPos)  ' // Get word
               tmpWord = LCASE$(tmpWord)
               Result = INSTR(strPBKeyWords, " " & tmpWord & " ")
               tmpWord = UCASE$(tmpWord)                        ' // Convert to uppercase
               IF tmpWord = "REM" THEN                          ' // extra for REM keyword
                  pLet2 = pLet2 - 3                             ' // Set position to start of word
                  IF bStartBlock = 1 THEN
                     POKE$ pLet2, endBlock
                     pLet2 = pLet2 + endBlockLen
                     bStartBlock = 0
                  END IF
                  POKE$ pLet2, greenStr
                  pLet2 = pLet2 + blockLen
                  POKE$ pLet2, tmpWord
                  pLet2 = pLet2 + 3
                  remFlag = 1
                  isRem = 1
               ELSEIF tmpWord = "#PBFORMS" THEN                 ' // Extra for directives
                  pLet2 = pLet2 - 8                             ' // Set position to start of word
                  IF bStartBlock = 1 THEN
                     POKE$ pLet2, endBlock
                     pLet2 = pLet2 + endBlockLen
                     bStartBlock = 0
                  END IF
                  POKE$ pLet2, PBFstr
                  pLet2 = pLet2 + blockLen
                  POKE$ pLet2, tmpWord
                  pLet2 = pLet2 + 8
                  remFlag = 1
               ELSEIF tmpWord = "ASM" THEN                      ' // Extra for ASM keyword
                  pLet2 = pLet2 - 3                             ' // Set position to start of word
                  IF bStartBlock = 1 THEN
                     POKE$ pLet2, endBlock
                     pLet2 = pLet2 + endBlockLen
                     bStartBlock = 0
                  END IF
                  POKE$ pLet2, RedStr
                  pLet2 = pLet2 + blockLen
                  POKE$ pLet2, tmpWord
                  pLet2 = pLet2 + 3
                  dqFlag = 2
               ELSE
                  IF Result THEN                    ' // If match was found, it's a PB keyword
                     pLet2 = pLet2 - LEN(tmpWord)   ' // Set position to start of word
                     IF bStartBlock = 1 THEN
                        POKE$ pLet2, endBlock
                        pLet2 = pLet2 + endBlockLen
                        bStartBlock = 0
                     END IF
                     IF LEFT$(tmpWord, 1) = "#" OR UCASE$(tmpWord) = "%DEF" THEN
                        POKE$ pLet2, redStr         ' //   and poke HTML string for red color into output string
                     ELSE
                        POKE$ pLet2, blueStr        ' //   and poke HTML string for blue color into output string
                     END IF
                     pLet2 = pLet2 + blockLen       ' // Move pointer ahead
                     POKE$ pLet2, tmpWord           ' // Poke the word into output string
                     pLet2 = pLet2 + LEN(tmpWord)   ' // Move pointer ahead
                     POKE$ pLet2, endBlock          ' //   and finally poke HTML end block string into output-
                     pLet2 = pLet2 + endBlockLen    ' // Move pointer ahead
                     Result = 0                     ' //   and reset result
                  END IF
               END IF
               wFlag = 0                            ' // Reset word flag
            END IF
      END SELECT

      IF dqFlag <> 3 THEN       ' // If not handled matching double-quote...
         IF @pLet <> 13 AND @pLet <> 10 THEN
            IF @pLet = 32 AND PrevChar = 32 THEN
               POKE$ pLet2, "&nbsp;"
               pLet2 = pLet2 + 6      ' //   and increase pos in output
            ELSE
               @pLet2 = @pLet         ' //   copy original character to output
               INCR pLet2             ' //   and increase pos in output
            END IF
         END IF
      ELSE
         dqFlag = 0             ' // else reset DQ flag
      END IF
      IF @pLet = 32 AND PrevChar = 32 THEN
         PrevChar = 0
      ELSE
         PrevChar = @pLet          ' // Previous character
      END IF
      INCR pLet                 ' // Move ahead to next character
   NEXT

   ' // Close last open block
   IF bStartBlock = 1 THEN
      POKE$ pLet2, endBlock
      bStartBlock = 0
   END IF

   ' // Blank lines
   REPLACE "<p><span style=""font-size: " & defFontSize & "pt; font-family: '" & defFontName & "';""></span></p>" WITH "<p><span style=""font-size: " & defFontSize & "pt; font-family: '" & defFontName & "';"">&nbsp;</span></p>" IN OutBuf
   ' // Unneeded code
   REPLACE "<span style=""font-size: 10pt; font-family: '" & defFontName & "';""></span>" WITH "" IN OutBuf
   ' // Hack for last empty line
'   REPLACE "<span style=""font-size: 10pt; font-family: '" & defFontName & "';""></span>" WITH "" IN OutBuf
   ' // Trim trailing blanks
   OutBuf = RTRIM$(OutBuf, ANY CHR$(32, 0))
   ' // Add the header and footer
   OutBuf = htmlHeader + OutBuf + htmlFooter
   SetCursor LoadCursor(BYVAL %NULL, BYVAL %IDC_ARROW)        ' // Show standard mouse

   ' // Display the text in a new MDI window
   IF bShow THEN
      ' // Create a new MDI window
      hMdi = CSED_CreateMdiChild("Untitled" & FORMAT$(pSed.UntitledFilesIdx) & ".html")
      IF ISFALSE hMdi THEN EXIT FUNCTION
      ShowWindow hMdi, %SW_SHOW
      ' // Get a direct pointer for faster access
      pSci = SCI_GetDirectPointer(pSed.hEdit)
      IF ISFALSE pSci THEN EXIT FUNCTION
      ' // Set the text
      SCIP_SetText(pSci, OutBuf)
      ' // Change statusbar information
      CSED_ShowLinCol
   END IF

   FUNCTION = OutBuf

END FUNCTION
' ========================================================================================
