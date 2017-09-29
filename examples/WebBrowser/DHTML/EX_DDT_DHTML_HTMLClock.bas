' ========================================================================================
' HTML clock
' This example displays the current time immediately, without server interaction. This
' sample requires neither animated nor downloaded images. The document automatically
' re-flows based on content changes. Authors can implement this clock easily and quickly
' with just a few lines of code.
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
   DIALOG NEW PIXELS, 0, "DHTML: HTML Clock", , , 750, 450, %WS_OVERLAPPEDWINDOW TO hDlg

   LOCAL s AS WSTRING
   ' // Prefix with "MSHTML:"
   s  = "MSHTML:" & $CRLF
   s += "<HEAD>" & $CRLF
   s += "<TITLE>MSDN Online Samples:  HTML Clock</TITLE>" & $CRLF
   s += "<META NAME=""FILENAME"" CONTENT=""clock.HTM"">" & $CRLF
   s += "<META HTTP-EQUIV=""MSThemeCompatible"" CONTENT=""Yes"">" & $CRLF
   s += "<STYLE>" & $CRLF
   s += "  A:link { color:#003399; text-decoration:none; }" & $CRLF
   s += "  A:visited { color:#6699CC; text-decoration:none; }" & $CRLF
   s += "  A:hover { text-decoration:underline; }" & $CRLF
   s += "</STYLE>" & $CRLF
   s += "<SCRIPT LANGUAGE=""VBScript"">" & $CRLF
   s += "sub tick()" & $CRLF
   s += "  dim hours, minutes, seconds, ap" & $CRLF
   s += "  dim intHours, intMinutes, intSeconds" & $CRLF
   s += "  dim today" & $CRLF
   s += "  intHours = Hour(Now)" & $CRLF
   s += "  intMinutes = Minute(Now)" & $CRLF
   s += "  intSeconds = Second(Now)" & $CRLF
   s += "  if (intHours = 0) then " & $CRLF
   s += "     hours = ""12:""" & $CRLF
   s += "     ap = ""Midnight""" & $CRLF
   s += "  elseif (intHours < 12) then" & $CRLF
   s += "     hours = intHours & "":""" & $CRLF
   s += "     ap = ""A.M.""" & $CRLF
   s += "  elseif (intHours = 12) then" & $CRLF
   s += "     hours = ""12:""" & $CRLF
   s += "     ap = ""Noon""" & $CRLF
   s += "     else " & $CRLF
   s += "       intHours = intHours - 12" & $CRLF
   s += "       hours = intHours & "":""" & $CRLF
   s += "       ap = ""P.M.""" & $CRLF
   s += "  end if" & $CRLF
   s += "  if (intMinutes < 10) then" & $CRLF
   s += "     minutes = ""0"" & intMinutes & "":""" & $CRLF
   s += "  else " & $CRLF
   s += "     minutes = intMinutes & "":""" & $CRLF
   s += "  end if" & $CRLF
   s += "  if (intSeconds < 10) then" & $CRLF
   s += "     seconds = ""0"" & intSeconds & "" """ & $CRLF
   s += "  else" & $CRLF
   s += "     seconds = intSeconds & "" """ & $CRLF
   s += "  end if" & $CRLF
   s += "  timeString = hours & minutes & seconds & ap" & $CRLF
   s += "  Clock.innerHTML = timeString" & $CRLF
   s += "  window.setTimeout ""tick"", 100" & $CRLF
   s += "end sub" & $CRLF
   s += "sub window_onload" & $CRLF
   s += "  tick" & $CRLF
   s += "end sub" & $CRLF
   s += "</SCRIPT>" & $CRLF
   s += "</HEAD>" & $CRLF
   s += "<BODY SCROLL=""auto"" TOPMARGIN=20 LEFTMARGIN=40 BGCOLOR=""#FFFFFF"" LINK=""#000066"" VLINK=""#666666"" TEXT=""#000000"">" & $CRLF
   s += "<!--TOOLBAR_START-->" & $CRLF
   s += "<!--TOOLBAR_EXEMPT-->" & $CRLF
   s += "<!--TOOLBAR_END-->" & $CRLF
   s += "<H2>HTML Clock</H2>" & $CRLF
   s += "<HR>" & $CRLF
   s += "<P>" & $CRLF
   s += "<P>" & $CRLF
   s += "<DIV id=Clock align=center style=""font-family: Verdana; font-size: 40; color:#0000FF""> </DIV>" & $CRLF
   s += "<P>" & $CRLF
   s += "<FONT FACE=""verdana,arial,helvetica"" SIZE=2>" & $CRLF
   s += "This example displays the current time immediately, without " & $CRLF
   s += "server interaction. This sample requires neither animated nor " & $CRLF
   s += "downloaded images. The document automatically re-flows based on " & $CRLF
   s += "content changes. Authors can implement this clock easily and " & $CRLF
   s += "quickly with just a few lines of code." & $CRLF
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
