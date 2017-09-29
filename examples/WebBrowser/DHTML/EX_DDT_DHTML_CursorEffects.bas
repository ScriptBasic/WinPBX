' ========================================================================================
' Cursor effects
' This sample shows how easy it is to specify different cursor types for the mouse pointer,
' such as the default arrow, move, or hand cursors.
' Other types of cursors supported include an I-bar for editable text and an hourglass or
' watch to signify a delay.
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
   DIALOG NEW PIXELS, 0, "DHTML: Cursor Effects", , , 750, 450, %WS_OVERLAPPEDWINDOW TO hDlg

   LOCAL s AS WSTRING
   ' // Prefix with "MSHTML:"
   s  = "MSHTML:" & $CRLF
   s += "<HEAD>" & $CRLF
   s += "<TITLE>Cursor Effects</TITLE>" & $CRLF
   s += "<META NAME=""FILENAME"" CONTENT=""cursor.HTM"">" & $CRLF
   s += "<META HTTP-EQUIV=""MSThemeCompatible"" CONTENT=""Yes"">" & $CRLF
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
   s += "<H2>Cursor Effects</H2>" & $CRLF
   s += "<HR>" & $CRLF
   s += "<P>" & $CRLF
   s += "<P>" & $CRLF
   s += "<P>" & $CRLF
   s += "<FONT FACE=""Verdana,Arial,Helvetica"" SIZE=""2"">" & $CRLF
   s += "<STRONG>To run this sample:</STRONG> Move the cursor over ""Change,"" ""the" & $CRLF
   s += "cursor,"" and ""over any element"" to see different cursor types." & $CRLF
   s += "</FONT>" & $CRLF
   s += "<BR>" & $CRLF
   s += "<BR>" & $CRLF
   s += "<DIV id=""Text1""><FONT style=""font-size: 25"" face=""Times"">" & $CRLF
   s += "<P>" & $CRLF
   s += "<FONT FACE=""Verdana,Arial,Helvetica"" SIZE=""3"">" & $CRLF
   s += "<I style=""cursor: hand;"">Change</I>" & $CRLF
   s += "<I style=""cursor: move""> the cursor </I>" & $CRLF
   s += "<I style=""cursor:ne-resize"">over any element</I>" & $CRLF
   s += "</FONT>" & $CRLF
   s += "<BR>" & $CRLF
   s += "</DIV>" & $CRLF
   s += "<P>" & $CRLF
   s += "<FONT FACE=""Verdana,Arial,Helvetica"" SIZE=""2"">" & $CRLF
   s += "This sample shows how easy it is to specify different cursor types for the mouse pointer, such as the default arrow, move, or hand cursors. " & _
          "Other types of cursors supported include an I-bar for editable text and an hourglass or watch to signify a delay. " & $CRLF
   s += "</FONT>" & $CRLF
   s += "<BR>" & $CRLF
   s += "<BR>" & $CRLF
   s += "<HR>" & $CRLF
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
