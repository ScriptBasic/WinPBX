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
   DIALOG NEW PIXELS, 0, "WebBrowser", , , 600, 350, %WS_OVERLAPPEDWINDOW TO hDlg

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' // Add a WebBrowser control
   LOCAL bstrURL AS WSTRING

   ' // You can pass a URL
   bstrURL = "https://forum.powerbasic.com/"

   ' // Create the WebBrowser control
   LOCAL nWide, nHigh AS LONG
   DIALOG GET CLIENT hDlg TO nWide, nHigh
   pWindow.AddWebBrowserControl(hDlg, %IDC_WEBBROWSER, bstrURL, NOTHING, 0, 0, nWide, nHigh)

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
            CASE %IDCANCEL

LOCAL pIWebBrowser2 AS IWebBrowser2
LOCAL pIHTMLDocument2 AS IHTMLDocument2
pIWebBrowser2 = OC_GetDispatch(GetDlgItem(CB.HNDL, %IDC_WEBBROWSER))
IF ISOBJECT(pIWebBrowser2) THEN
   pIHTMLDocument2 = pIWebBrowser2.Document
   IF ISTRUE ISOBJECT(pIHTMLDocument2) THEN
      IHTMLDocument_setElementValueById(pIHTMLDocument2, "vB_Editor_001_textarea", "Jose's approach works!")
   END IF
END IF

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
