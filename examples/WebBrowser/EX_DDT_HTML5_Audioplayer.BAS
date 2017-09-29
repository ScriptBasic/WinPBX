' ########################################################################################
' Microsoft Windows
' File: EX_DDT_HTML5_AudioPlayer.bas
' Contents: Template - CWindow with HTML5 Audio Player
' Compilers: PBWIN 10+, PBCC 6+
' Headers: Windows API headers 3.0+
' Copyright (c) 2012 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################
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
FUNCTION PBMAIN () AS LONG

   ' // Create the dialog
   LOCAL hDlg AS DWORD
   DIALOG NEW PIXELS, 0, "HTML5 Audio Player", , , 500, 200, %WS_OVERLAPPEDWINDOW TO hDlg

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' // Build the html page
   LOCAL s AS WSTRING

   s = "<!doctype html>" & $CRLF
   s += "<head>" & $CRLF
   s += "   <title>Audio Element Sample</title>" & $CRLF
   s += "   <meta http-equiv='X-UA-Compatible' content='IE=9' />" & $CRLF
   s += "</head>" & $CRLF
   s += "<body>" & $CRLF
   s += "    <h1>Audio Element Sample</h1>" & $CRLF
   s += "    <!-- Display the audio player with control buttons. -->" & $CRLF
   s += "    <!-- Remember to change the path of the url of the audio file. -->" & $CRLF
   s += "    <audio src='" & EXE.PATH$ & "Kalimba.mp3' controls autoplay loop>" & $CRLF
   s += "        HTML5 audio not supported" & $CRLF
   s += "    </audio>" & $CRLF
   s += "</body>" & $CRLF
   s += "</html>" & $CRLF

   ' // Save the script as a temporary file
   LOCAL bstrTempFileName AS WSTRING
   bstrTempFileName = AfxSaveTempFile(s, "", "TMP", "html", 1)

   ' // Create the WebBrowser control
   LOCAL nWide, nHigh AS LONG
   DIALOG GET CLIENT hDlg TO nWide, nHigh
   pWindow.AddWebBrowserControl(hDlg, %IDC_WEBBROWSER, bstrTempFileName, NOTHING, 0, 0, nWide, nHigh)

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
