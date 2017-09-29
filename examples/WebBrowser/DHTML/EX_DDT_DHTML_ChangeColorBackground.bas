' ========================================================================================
' Change color background
' Demonstrates how to change the color background.
' Mouse over the squares and the background color will change.
' Adapted from the following example: http://www.w3schools.com/dhtml/tryit.asp?filename=trydhtml_css_bgcolor
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
   DIALOG NEW PIXELS, 0, "DHTML: Change Color Background", , , 600, 350, %WS_OVERLAPPEDWINDOW TO hDlg

   LOCAL s AS WSTRING
   ' // Prefix with "MSHTML:"
   s  = "MSHTML:<HTML>" & $CRLF
   s += "<head>" & $CRLF
   s += "<TITLE>Change color background</TITLE>" & $CRLF
   s += "<META HTTP-EQUIV='MSThemeCompatible' CONTENT='Yes'>" & $CRLF
   s += "<script type='text/javascript'>" & $CRLF
   s += "function bgChange(bg)" & $CRLF
   s += "{" & $CRLF
   s += "document.body.style.background=bg;" & $CRLF
   s += "}" & $CRLF
   s += "</script>" & $CRLF
   s += "</head>" & $CRLF
   s += "<body scroll='no'>" & $CRLF
   s += "<h2>Mouse over the squares and the background color will change!</h2>" & $CRLF
   s += "<table width='300' height='100'>" & $CRLF
   s += "<tr>" & $CRLF
   s += "  <td onmouseover=""bgChange('red')""" & $CRLF
   s += "      onmouseout=""bgChange('transparent')""" & $CRLF
   s += "      bgcolor='red'>" & $CRLF
   s += "  </td>" & $CRLF
   s += "  <td onmouseover=""bgChange('blue')""" & $CRLF
   s += "      onmouseout=""bgChange('transparent')"""
   s += "      bgcolor='blue'>" & $CRLF
   s += "  </td>" & $CRLF
   s += "  <td onmouseover=""bgChange('green')""" & $CRLF
   s += "      onmouseout=""bgChange('transparent')""" & $CRLF
   s += "      bgcolor='green'>" & $CRLF
   s += "  </td>" & $CRLF
   s += "</tr>" & $CRLF
   s += "</table>" & $CRLF
   s += "</body>" & $CRLF
   s += "</html>"

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
