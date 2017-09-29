' ========================================================================================
' Dynamic Styles
' This sample demonstrates how the style can be changed through interactions with the user.
' This technique makes the Web page more lively and interactive.
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
   DIALOG NEW PIXELS, 0, "DHTML: Dynamic Styles", , , 750, 450, %WS_OVERLAPPEDWINDOW TO hDlg

   LOCAL s AS WSTRING
   ' // Prefix with "MSHTML:"
   s  = "MSHTML:" & $CRLF
   s += "<HEAD>" & $CRLF
   s += "<TITLE>MSDN Online Samples:  Dynamic Styles</TITLE>" & $CRLF
   s += "<META NAME=""FILENAME"" CONTENT=""dynamic.HTM"">" & $CRLF
   s += "<META HTTP-EQUIV=""MSThemeCompatible"" CONTENT=""Yes"">" & $CRLF
   s += "<STYLE>" & $CRLF
   s += "  .bigChange {color:blue; font-weight:bolder; font-size:175%; letter-spacing:4px;  text-transform: uppercase; background:yellow}" & $CRLF
   s += "  .start {color:yellow; background:navy}" & $CRLF
   s += "  A:link { color:#003399; text-decoration:none; }" & $CRLF
   s += "  A:visited { color:#6699CC; text-decoration:none; }" & $CRLF
   s += "  A:hover { text-decoration:underline; }" & $CRLF
   s += "</STYLE>" & $CRLF
   s += "<SCRIPT LANGUAGE=""VBScript"">" & $CRLF
   s += "  sub highlightButton (s)" & $CRLF
   s += "    window.status = ""Running highlight buttons""" & $CRLF
   s += "    if (""INPUT"" = window.event.srcElement.tagName) then" & $CRLF
   s += "      window.event.srcElement.className = s" & $CRLF
   s += "    end if" & $CRLF
   s += "  end sub" & $CRLF
   s += "</SCRIPT>" & $CRLF
   s += "</HEAD>" & $CRLF
   s += "<BODY SCROLL=""auto"" TOPMARGIN=20 LEFTMARGIN=40 BGCOLOR=""#FFFFFF"" LINK=""#000066"" VLINK=""#666666"" TEXT=""#000000"">" & $CRLF
   s += "<!--TOOLBAR_START-->" & $CRLF
   s += "<!--TOOLBAR_EXEMPT-->" & $CRLF
   s += "<!--TOOLBAR_END-->" & $CRLF
   s += "<H2>Dynamic Styles</H2>" & $CRLF
   s += "<HR>" & $CRLF
   s += "<P>" & $CRLF
   s += "<P>" & $CRLF
   s += "<P>" & $CRLF
   s += "<FONT SIZE=4>Move the mouse over ""Make this text bigger"" below.</FONT>" & $CRLF
   s += "<P>" & $CRLF
   s += "<FONT FACE=""verdana,arial,helvetica"" SIZE=2>" & $CRLF
   s += "  Text can change in size and style at any time! " & $CRLF
   s += "  <span onmouseover = 'me.style.fontSize = ""larger""' onmouseout = 'me.style.fontSize =""""' style=""color:red"">Make this text bigger.</span>" & $CRLF
   s += "  Notice how the text automatically reflows." & $CRLF
   s += "</FONT>" & $CRLF
   s += "<P>" & $CRLF
   s += "<FONT FACE=""verdana,arial,helvetica"" SIZE=2>" & $CRLF
   s += "  And one more time-but use the class attribute: " & $CRLF
   s += "  <SPAN onmouseover = 'me.className = ""bigChange""' onmouseout = 'me.className=""start""' class=start>Make this text bigger.</SPAN>" & $CRLF
   s += "  This page demonstrates how the style can be changed through interactions with the user. This technique makes the Web page more lively and interactive." & $CRLF
   s += "</FONT>" & $CRLF
   s += "<P>" & $CRLF
   s += "<P>" & $CRLF
   s += "<P>" & $CRLF
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
