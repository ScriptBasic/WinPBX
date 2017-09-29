' ========================================================================================
' Animated Buttons
' This example demonstrates how style can be changed through interactions with the user.
' This technique makes the Web page more lively and interactive.
' Dynamic HTML supports the CSS standard on built-in controls. When combined with the
' object model, it allows the controls to change in appearance and size as a result of
' interaction with the user.
' The "Click me" button demonstrates that even buttons can resize to accommodate changed
' button content, causing the document to automatically reflow around them.
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
FUNCTION WinMain (BYVAL hInstance AS DWORD, BYVAL hPrevInstance AS DWORD, BYVAL lpszCmdLine AS WSTRINGZ PTR, BYVAL nCmdShow AS LONG) AS LONG

   ' // Allow copy selected text
   OleInitialize

   ' // Create the dialog
   LOCAL hDlg AS DWORD
   DIALOG NEW PIXELS, 0, "Animated buttons", , , 750, 450, %WS_OVERLAPPEDWINDOW TO hDlg

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' // Add a WebBrowser control
   LOCAL s AS WSTRING

   s  = "MSHTML:" & $CRLF
   s += "<HEAD>" & $CRLF
   s += "<TITLE>MSDN Online Samples:  Animated Buttons</TITLE>" & $CRLF
   s += "<META NAME=""FILENAME"" CONTENT=""animated.HTM"">" & $CRLF
   s += "<META HTTP-EQUIV=""MSThemeCompatible"" CONTENT=""Yes"">" & $CRLF
   s += "<STYLE>" & $CRLF
   s += ".bigChange {color:blue; font-weight:bolder; font-size:175%; letter-spacing:4px;  text-transform: uppercase; background:yellow}" & $CRLF
   s += ".start {color:yellow; background:navy}" & $CRLF
   s += "A:link { color:#003399; text-decoration:none; }" & $CRLF
   s += "A:visited { color:#6699CC; text-decoration:none; }" & $CRLF
   s += "A:hover { text-decoration:underline; }" & $CRLF
   s += "</STYLE>" & $CRLF
   s += "<SCRIPT LANGUAGE=""VBScript"">" & $CRLF
   s += "sub highlightButton(s)" & $CRLF
   s += "   if (""INPUT"" = window.event.srcElement.tagName) then" & $CRLF
   s += "      window.event.srcElement.className = s" & $CRLF
   s += "   end if" & $CRLF
   s += "end sub" & $CRLF
   s += "</SCRIPT>" & $CRLF
   s += "</HEAD>" & $CRLF
   s += "<BODY SCROLL=""auto"" TOPMARGIN=20 LEFTMARGIN=40 BGCOLOR=""#ffffff"" LINK=""#000066"" VLINK=""#666666"" TEXT=""#000000"">" & $CRLF
   s += "<!--TOOLBAR_START-->" & $CRLF
   s += "<!--TOOLBAR_EXEMPT-->" & $CRLF
   s += "<!--TOOLBAR_END-->" & $CRLF
   s += "<H2>Animated Buttons</H2>" & $CRLF
   s += "<HR>" & $CRLF
   s += "<P>" & $CRLF
   s += "<P>" & $CRLF
   s += "<FORM NAME=highlight onmouseover='highlightButton(""start"")' onmouseout='highlightButton("""")'>" & $CRLF
   s += "   <input type=""button"" value=""Button 1"">" & $CRLF
   s += "   <input type=""button"" onmouseup='me.style.fontStyle=""""' value=""Click me"" onclick ='me.value=""You clicked the button!""' onmousedown='me.style.fontStyle=""italic""'>" & $CRLF
   s += "   <input type=""button"" value=""Button 3"">" & $CRLF
   s += "</FORM>" & $CRLF
   s += "<FONT FACE=""verdana,arial,helvetica"" SIZE=2>" & $CRLF
   s += "This page demonstrates how style can be changed through interactions with the user." & $CRLF
   s += "This technique makes the Web page more lively and interactive." & $CRLF
   s += "</FONT>" & $CRLF
   s += "<P>" & $CRLF
   s += "<P>" & $CRLF
   s += "<FONT FACE=""verdana,arial,helvetica"" SIZE=2>" & $CRLF
   s += "Dynamic HTML supports the CSS standard on built-in controls. When combined with the object model, it allows the controls to change in appearance and size as a result of interaction with the user." & $CRLF
   s += "</FONT>" & $CRLF
   s += "<P>" & $CRLF
   s += "<FONT FACE=""verdana,arial,helvetica"" SIZE=2>" & $CRLF
   s += "The ""Click me"" button demonstrates that even buttons can resize to accommodate changed button content, causing the document to automatically reflow around them." & $CRLF
   s += "</FONT>" & $CRLF
   s += "<P>" & $CRLF
   s += "<P>" & $CRLF
   s += "<P>" & $CRLF
   s += "<HR>" & $CRLF
   s += "</BODY>" & $CRLF
   s += "</HTML>" & $CRLF

   ' // Create the control
   LOCAL nWide, nHigh AS LONG
   DIALOG GET CLIENT hDlg TO nWide, nHigh
   pWindow.AddWebBrowserControl(hDlg, %IDC_WEBBROWSER, s, NOTHING, 0, 0, nWide, nHigh)

   ' // Display and activate the dialog
   DIALOG SHOW MODAL hDlg, CALL DlgProc

   ' // Uninitialize the COM library
   OleUninitialize

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
