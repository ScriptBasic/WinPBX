' ========================================================================================
' Demonstrates how to apply a simple transition to an image. Although the sample uses a
' Blinds transition, the technique described applies to the all transitions. The
' applyTransition function should be generic enough to implement any desired transition in
' your own application.
' Adapted from the Microsoft example available at:
' http://msdn.microsoft.com/en-us/library/ms537644%28VS.85%29.aspx
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
   DIALOG NEW PIXELS, 0, "DHTML: Blinds Transition", , , 750, 450, %WS_OVERLAPPEDWINDOW TO hDlg

   ' // Add a WebBrowser control
   LOCAL hCtl AS DWORD
   LOCAL s AS WSTRING
   LOCAL bstrExePath AS STRING

   bstrExePath = EXE.Path$
   REPLACE "\" WITH "/" IN bstrExePath

   ' // Prefix with "MSHTML:"
   s = "MSHTML:<HTML>" & $CRLF
   s += "<HEAD>" & $CRLF
   s += "<TITLE>PDC 97 Cover Page</TITLE>" & $CRLF
   s += "<META HTTP-EQUIV=""MSThemeCompatible"" CONTENT=""Yes"">" & $CRLF
   s += "<SCRIPT>" & $CRLF
   s += "function applyTransition (oImg)" & $CRLF
   s += "{" & $CRLF
   s += "   oImg.filters(0).Apply();" & $CRLF
   s += "   oImg.style.visibility = 'visible';" & $CRLF
   s += "   oImg.filters(0).Play();" & $CRLF
   s += "}" & $CRLF
   s += "</SCRIPT>" & $CRLF
   s += "<!-- SAMPLE_STYLE_START -->" & $CRLF
   s += "<LINK REL='stylesheet' HREF='" & bstrExePath & "samples.css' TYPE='text/css'>" & $CRLF
   s += "<!-- SAMPLE_STYLE_END -->" & $CRLF
   s += "</HEAD>" & $CRLF
   s += "<BODY SCROLL='no' onload='applyTransition(MyImg)'>" & $CRLF
   s += "<IMG ID='MyImg' src='" & bstrExePath & "pdc97.jpg'" & $CRLF
   s += "    STYLE='filter:progid:DXImageTransform.Microsoft.Blinds(direction='down', bands=2);" & $CRLF
   s += "    visibility:hidden' height='100%' width='100%' border='0' alt='PDC logo'>" & $CRLF
   s += "</HTML>" & $CRLF

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
