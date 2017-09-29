' ========================================================================================
' The following example causes text to fly from the upper-left corner of the client window
' down to mid-page. As the text stops, a second word appears underneath it.
' Adapted from the Microsoft example available at:
' http://samples.msdn.microsoft.com/workshop/samples/author/dhtml/howto/movingObjectsBySlopeEx.htm
' Tutorial: http://msdn.microsoft.com/en-us/library/ms537655(VS.85).aspx
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
   DIALOG NEW PIXELS, 0, "DHTML: Dynamic Positioning", , , 750, 450, %WS_OVERLAPPEDWINDOW TO hDlg

   LOCAL s AS WSTRING
   LOCAL bstrExePath AS STRING

   bstrExePath = EXE.Path$
   REPLACE "\" WITH "/" IN bstrExePath

   ' // Prefix with "MSHTML:"
   s = "MSHTML:<HTML>" & $CRLF
   s += "<HEAD>" & $CRLF
   s += "<title>Dynamic Positioning</title>" & $CRLF
   s += "<META HTTP-EQUIV='MSThemeCompatible' CONTENT='Yes'>" & $CRLF
   s += "<LINK REL='stylesheet' HREF='" & bstrExePath & "samples.css' TYPE='text/css'>" & $CRLF
   s += "<STYLE>" & $CRLF
   s += ".DiagonalText  { font-family:times; font-size: 36pt; position:absolute;top:0;left:0;}" & $CRLF
   s += ".DisplayText   { font-family:times; font-size: 36pt; position:absolute;top:300;left:330;width:200;color:red;visibility:hidden;}" & $CRLF
   s += "</STYLE>" & $CRLF
   s += "<SCRIPT>" & $CRLF
   s += "<!-------------------Global Variable Declarations----------------------->" & $CRLF
   s += "var i;" & $CRLF
   s += "var iVertical=0;" & $CRLF
   s += "var iHorizontal=0;" & $CRLF
   s += "var iInterval=0;" & $CRLF
   s += "var vTimerID;" & $CRLF
   s += "var vDelayStart;" & $CRLF
   s += "<!---------------------------------------------------------------------->" & $CRLF
   s += "// Included a setTimeout in BODY onload to delay start of text movement." & $CRLF
   s += "function pauseStart()" & $CRLF
   s += "{" & $CRLF
   s += "  vDelayStart=window.setTimeout('setTimer()', 500);" & $CRLF
   s += "}" & $CRLF
   s += "// Set up interval at which the moveDiv function will be called." & $CRLF
   s += "function setTimer()" & $CRLF
   s += "{" & $CRLF
   s += "  vTimerID=window.setInterval('moveDiv()',40);" & $CRLF
   s += "}" & $CRLF
   s += "// This function incrementally repositions divMove. It loops through a set" & $CRLF
   s += "// number of times.!" & $CRLF
   s += "function moveDiv()" & $CRLF
   s += "{" & $CRLF
   s += "  for(i=0;i<10;i++)" & $CRLF
   s += "    {" & $CRLF
   s += "       iHorizontal+= 1;" & $CRLF
   s += "       iVertical=iHorizontal;" & $CRLF
   s += "       divMove.style.top=iVertical;" & $CRLF
   s += "       divMove.style.left=iHorizontal;" & $CRLF
   s += "    }" & $CRLF
   s += "//  iInterval tracks how many times moveDiv has looped and clears the interval" & $CRLF
   s += "//  after a set number of loops." & $CRLF
   s += "  iInterval++;" & $CRLF
   s += "  if(iInterval>25)" & $CRLF
   s += "     {" & $CRLF
   s += "        window.clearInterval(vTimerID);" & $CRLF
   s += "        divToggle.style.visibility='visible';" & $CRLF
   s += "     }" & $CRLF
   s += "}" & $CRLF
   s += "</SCRIPT>" & $CRLF
   s += "</HEAD>" & $CRLF
   s += "<BODY scroll='no' onload='pauseStart()' >" & $CRLF
   s += "<DIV ID='divMove' CLASS='DiagonalText'>" & $CRLF
   s += "   Dynamic" & $CRLF
   s += "</DIV>" & $CRLF
   s += "<DIV ID='divToggle' CLASS='DisplayText'>" & $CRLF
   s += "   Positioning" & $CRLF
   s += "</DIV>" & $CRLF
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
