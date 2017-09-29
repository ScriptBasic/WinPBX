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

AfxSetProcessDPiAware

   ' // Create the dialog
   LOCAL hDlg AS DWORD
'   DIALOG NEW PIXELS, 0, "WebBrowser", , , 600, 350, %WS_OVERLAPPEDWINDOW TO hDlg
   DIALOG NEW PIXELS, 0, "WebBrowser", , , 1200, 800, %WS_OVERLAPPEDWINDOW TO hDlg

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' // Add a WebBrowser control
   LOCAL bstrHTML AS WSTRING

   ' // Script to display the picture
   bstrHTML  = "MSHTML:" & $CRLF
   bstrHTML += "<body scroll='auto' style='margin: 0px 0px 0px 0px'>" & $CRLF
'   bstrHTML += "<img src='file://C:\Users\Pepe\FreeBasic64\MyExamples\ImageCtx\VEGA_PAZ_01.jpg' border='0' width='100%'></img>"
'   bstrHTML += "<img src='file://C:\Users\Pepe\FreeBasic64\MyExamples\ImageCtx\VEGA_PAZ_01.jpg' border='0'></img>"
   bstrHTML += "<center>" & $CRLF
   bstrHTML += "<img src='http://www.kenrockwell.com/trips/2016-05-yosemite/RX300658-green-falls.jpg' border='0' width='120%'></img>"
   bstrHTML += "<center>" & $CRLF
   bstrHTML += "</body>"

   ' // Script to display the picture centered
'   bstrHTML  = "MSHTML:" & $CRLF
'   bstrHTML += "<body scroll='auto' style='margin: 0px 0px 0px 0px'>" & $CRLF
'   bstrHTML += "<center>" & $CRLF
'   bstrHTML += "<img src='http://celeb-world.net/d/4134-2/nicolekidman3.jpg' border='0' height='100%'></img>"
'   bstrHTML += "</center>" & $CRLF
'   bstrHTML += "</body>"

   ' // Create the WebBrowser control
   LOCAL nWide, nHigh AS LONG
   DIALOG GET CLIENT hDlg TO nWide, nHigh
   pWindow.AddWebBrowserControl(hDlg, %IDC_WEBBROWSER, bstrHTML, NOTHING, 0, 0, nWide, nHigh)

   ' // Note: Right click with the mouse to activate the options menu

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
