' ========================================================================================
' Entry Box
' This sample shows how text can be replaced dynamically by user-defined content through
' the innerHTML property. The author need not know in advance what the user will type;
' Dynamic HTML lets users choose how to update this element on the fly.
' This is an adaptation of a Microsoft's MSDN online samples.
' ========================================================================================

#COMPILE EXE
#DIM ALL
%UNICODE = 1

' // Include files for external files
%USEWEBBROWSER = 1            ' // Use the WebBrowser control
#INCLUDE ONCE "CWindow.inc"   ' // CWindow class

' // Identifier
%IDC_WEBBROWSER = 101

' ########################################################################################
' Main
' ########################################################################################
FUNCTION PBMAIN

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' // Create the dialog
   LOCAL hDlg AS DWORD
   DIALOG NEW PIXELS, 0, "DHTML: Entry Box", , , 750, 450, %WS_OVERLAPPEDWINDOW TO hDlg

   LOCAL s AS WSTRING
   ' // Prefix with "MSHTML:"
   s  = "MSHTML:" & $CRLF
   s += "<HEAD>" & $CRLF
   s += "<TITLE>Entry Box</TITLE>" & $CRLF
   s += "<META NAME=""FILENAME"" CONTENT=""input.HTM"">" & $CRLF
   s += "<META http-equiv=""MSThemeCompatible"" CONTENT=""Yes"">" & $CRLF
   s += "<STYLE>" & $CRLF
   s += "  A:link { color:#003399; text-decoration:none; }" & $CRLF
   s += "  A:visited { color:#6699CC; text-decoration:none; }" & $CRLF
   s += "  A:hover { text-decoration:underline; }" & $CRLF
   s += "</STYLE>" & $CRLF
   s += "</HEAD>" & $CRLF
   s += "<BODY SCROLL=""auto"" TOPMARGIN=20 LEFTMARGIN=40 BGCOLOR=""#FFFFFF"" LINK=""#000066"" VLINK=""#666666"" TEXT=""#000000"">" & $CRLF
   s += "<!--TOOLBAR_START-->" & $CRLF
   s += "<!--TOOLBAR_EXEMPT-->" & $CRLF
   s += "<!--TOOLBAR_END-->" & $CRLF
   s += "<H2>Entry Box</H2>" & $CRLF
   s += "<HR>" & $CRLF
   s += "<P>" & $CRLF
   s += "<P>" & $CRLF
   s += "<FONT FACE=""verdana,arial,helvetica"" SIZE=2>" & $CRLF
   s += "<DIV ID=ReplaceMe >What you type in the box below will replace this HTML.</DIV>" & $CRLF
   s += "<BR>" & $CRLF
   s += "<INPUT ID=T1 TYPE=TEXT STYLE=""width: 400""><P><INPUT TYPE=BUTTON VALUE=""Click me to change"" ONCLICK=""ReplaceMe.innerHTML = T1.value"">" & $CRLF
   s += "<UL>" & $CRLF
   s += "	<LI>To " & $CRLF
   s += "	replace page text with your name, type your name and click the button.</LI>" & $CRLF
   s += "	<LI>Notice how Dynamic HTML replaces text " & $CRLF
   s += "	with user-defined content. The page is able " & $CRLF
   s += "	to respond to user input without a server round " & $CRLF
   s += "	trip or reloading the page.</LI>" & $CRLF
   s += "</UL>" & $CRLF
   s += "<P>" & $CRLF
   s += "  This sample shows how text can be replaced dynamically by " & $CRLF
   s += "  user-defined content through the <b>innerHTML</b> property. The author " & $CRLF
   s += "  need not know in advance what the user will type; Dynamic HTML " & $CRLF
   s += "  lets users choose how to update this element on the fly." & $CRLF
   s += "</P>" & $CRLF
   s += "</FONT>" & $CRLF
   s += "<P>" & $CRLF
   s += "<P>" & $CRLF
   s += "<P>" & $CRLF
   s += "<HR>" & $CRLF
   s += "<P>" & $CRLF
   s += "</BODY>" & $CRLF
   s += "</HTML>"

   ' // Create the control
   LOCAL nWide, nHigh AS LONG
   DIALOG GET CLIENT hDlg TO nWide, nHigh
   pWindow.AddWebBrowserControl(hDlg, %IDC_WEBBROWSER, s, NOTHING, 0, 0, nWide, nHigh)

   ' // Display and activate the dialog
   DIALOG SHOW MODAL hDlg, CALL DlgProc

END FUNCTION
' ########################################################################################

' ========================================================================================
' Main Dialog procedure
' ========================================================================================
CALLBACK FUNCTION DlgProc() AS LONG

   SELECT CASE CBMSG

      CASE %WM_COMMAND
         SELECT CASE CB.CTL
            ' ...
            ' ...
         END SELECT

      CASE %WM_SIZE
         IF CB.WPARAM <> %SIZE_MINIMIZED THEN
            ' // Resize the control
            LOCAL nWide, nHigh AS LONG
            DIALOG GET CLIENT CB.HNDL TO nWide, nHigh
            CONTROL SET SIZE CB.HNDL, %IDC_WEBBROWSER, nWide, nHigh
         END IF

   END SELECT

END FUNCTION
' ========================================================================================
