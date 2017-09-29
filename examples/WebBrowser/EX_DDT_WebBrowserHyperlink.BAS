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
   DIALOG NEW PIXELS, 0, "WebBrowser", , , 400, 260, %WS_OVERLAPPEDWINDOW TO hDlg

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' // Add a WebBrowser control
   LOCAL bstrHTML AS WSTRING

   ' // Script to display the hyperlink
   bstrHTML  = "MSHTML:" & $CRLF
   bstrHTML += "<body scroll='no' style='margin: 0px 0px 0px 0px'>" & $CRLF
   bstrHTML += "<a href='http://www.jose.it-berater.org/smfforum/index.php' target='_blank'>" & _
               "<img src='http://www.jose.it-berater.org/webpages_images/h_2.jpg' width='100%' height='100%' alt='Jose Roca Software'></a>"
   bstrHTML += "</body>"

   ' // Create the WebBrowser control
   LOCAL nWide, nHigh AS LONG
   DIALOG GET CLIENT hDlg TO nWide, nHigh
   pWindow.AddWebBrowserControl(hDlg, %IDC_WEBBROWSER, bstrHTML, NOTHING, 45, 45, 311, 170)

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

   END SELECT

END FUNCTION
' ========================================================================================
