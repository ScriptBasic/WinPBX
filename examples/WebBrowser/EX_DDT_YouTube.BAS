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
   DIALOG NEW PIXELS, 0, "YouTube", , , 450, 400, %WS_OVERLAPPEDWINDOW TO hDlg

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' // Build the html script
   LOCAL s AS WSTRING

   ' // Build the web page. Remember to always start it with "MSHTML:".
   s  = "MSHTML:<!DOCTYPE html>" & $CRLF
   s += "<html>" & $CRLF
   s += "<head>" & $CRLF
   s += "<meta http-equiv='MSThemeCompatible' content='Yes'>" & $CRLF
   s += "<title>YouTube video</title>" & $CRLF
   s += "" & $CRLF
   s += "</head>" & $CRLF
   s += "<body scroll='no' style='MARGIN: 0px 0px 0px 0px'>"
   s += "<object width='100%' height='100%'>" & _
        "<param name='movie' value='http://www.youtube.com/v/t6Lp4w8wyy0&hl=es&fs=1'></param>" & _
        "<param name='wmode' value='transparent'>" & _
        "</param><embed src='http://www.youtube.com/v/t6Lp4w8wyy0&hl=es&fs=1'" & _
        " type='application/x-shockwave-flash' wmode='transparent' width='100%' height='100%'>" & _
        "</embed></object>"
   s += "" & $CRLF
   s += "</body>" & $CRLF
   s += "" & $CRLF
   s += "</html>" & $CRLF

   ' // Create the WebBrowser control with the embedded YouTube video
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
