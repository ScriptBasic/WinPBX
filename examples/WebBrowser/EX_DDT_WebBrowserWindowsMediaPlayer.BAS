#COMPILE EXE
#DIM ALL
%UNICODE = 1

' // Include files for external files
%USEWEBBROWSER = 1            ' // Use the WebBrowser control
#INCLUDE ONCE "CWindow.inc"   ' // CWindow class

' // Identifier
%IDC_WEBBROWSER = 1001

' ########################################################################################
' Main
' ########################################################################################
FUNCTION PBMAIN

   ' // Create the dialog
   LOCAL hDlg AS DWORD
   DIALOG NEW PIXELS, 0, "Windows Media Player", , , 450, 400, %WS_OVERLAPPEDWINDOW TO hDlg

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' // Add a WebBrowser control and display a video
   LOCAL s AS WSTRING
   LOCAL bstrURL AS WSTRING

   bstrURL = "MyVideo.wmv"   ' --> change me

   ' // Build the web page. Remember to always start it with "MSHTML:".
   s  = "MSHTML:<!DOCTYPE html>" & $CRLF
   s += "<html>" & $CRLF
   s += "<head>" & $CRLF
   s += "<meta http-equiv='MSThemeCompatible' content='Yes'>" & $CRLF
   s += "<title>Windows Media Player</title>" & $CRLF
   s += "" & $CRLF
   s += "</head>" & $CRLF
   s += "<body scroll='no' style='margin: 0px 0px 0px 0px'>"
   s += "<object id='video' classid='clsid:6BF52A52-394A-11d3-B153-00C04F79FAA6' type='application/x-oleobject' width='100%' height='100%'>" & $CRLF
   s += "<param name='URL' value=" & bstrURL & ">" & $CRLF
   s += "<param name='Enabled' value='true'>" & $CRLF
   s += "<param name='AutoStart' value='true'>" & $CRLF
   s += "<param name='StretchToFit' value='true'>" & $CRLF
   s += "<param name='PlayCount' value='1'>" & $CRLF
   s += "<param name='Volume' value='50'>" & $CRLF
   s += "<param name='Balance'value='0'>" & $CRLF
   s += "<param name='Rate' value='1.0'>" & $CRLF
   s += "<param name='Mute' value='false'>" & $CRLF
   s += "<param name='FullScreen' value='false'>" & $CRLF
   s += "<param name='uiMode' value='full'>" & $CRLF
   s += "</object>" & $CRLF
   s += "" & $CRLF
   s += "</body>" & $CRLF
   s += "" & $CRLF
   s += "</html>" & $CRLF

   ' // Create the WebBrowser control with the embedded video
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
