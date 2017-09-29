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
   bstrURL = "http://www.powerbasic.com/support/pbforums/index.php"

   ' // or a path to an Active document file (Excel, Word or PDF)
'   bstrURL = EXE.Path$ & "Test.xls"              ' <-- change me!
'   bstrURL = EXE.Path$ & "JetSQL.doc"            ' <-- change me!
'   bstrURL = EXE.Path$ & "COMCollections.pdf"    ' <-- change me!

   ' // or a fragment of HTML code (remember to always start with "MSHTML:")
'   bstrURL = "MSHTML:<HTML><BODY>This is a line of text</BODY></HTML>"

   ' // or a web page (remember to always start with "MSHTML:")
'   LOCAL s AS WSTRING
'   LOCAL bstrName AS WSTRING

'   S =  "MSHTML:<?xml version=""1.0""?>"
'   s += "<!DOCTYPE HTML PUBLIC ""-//W3C//DTD XHTML 1.0 Transitional//EN"" ""http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"">" & $CRLF
'   s += "<html xmlns=""http://www.w3.org/1999/xhtml"">" & $CRLF
'   s += "<head>" & $CRLF
'   s += "<title>Image Test</title>" & $CRLF
'   s += "</head>" & $CRLF
'   s += "<body scroll=" & $DQ & "auto" & $DQ & " style=" & $DQ & "MARGIN: 0px 0px 0px 0px" & $DQ & " >" & $CRLF
'   bstrName = EXE.Path$ & "Ciutat_de_les_Arts_i_de_les_Ciencies_02.jpg"
'   s += "<img src=" & $DQ & bstrName & $DQ & " alt=" & $DQ & bstrName & $DQ & " title=" & $DQ & bstrName & $DQ & " "
'   s += "/>" & $CRLF
'   s += "</body>" & $CRLF
'   s += "</html>" & $CRLF
'   bstrURL = s

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
