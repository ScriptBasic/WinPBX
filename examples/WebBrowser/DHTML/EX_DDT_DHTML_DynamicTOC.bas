' ========================================================================================
' Demonstrates how to create a dynamic table of contents.
' Adapted from the Microsoft example available at:
' http://samples.msdn.microsoft.com/workshop/samples/author/dhtml/howto/creatingTOCEX.htm
' Tutorial: http://msdn.microsoft.com/en-us/library/ms537646(VS.85).aspx
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
   DIALOG NEW PIXELS, 0, "DHTML:  Dynamic Table of Contents", , , 450, 250, %WS_OVERLAPPEDWINDOW TO hDlg

   LOCAL s AS WSTRING
   LOCAL bstrExePath AS STRING

   bstrExePath = EXE.Path$
   REPLACE "\" WITH "/" IN bstrExePath

   ' // Prefix with "MSHTML:"
   s  = "MSHTML:<HTML>" & $CRLF
   s += "<HEAD>" & $CRLF
   s += "<TITLE>Creating a Dynamic TOC sample</TITLE>" & $CRLF
   s += "<META HTTP-EQUIV='MSThemeCompatible' CONTENT='Yes'>" & $CRLF
   s += "<LINK REL='stylesheet' HREF='" & bstrExePath & "samples.css' TYPE='text/css'>" & $CRLF
   s += "<STYLE>" & $CRLF
   s += "BODY                 { font-size:95%; font-family:arial;}" & $CRLF
   s += "UL                   { cursor: hand; }" & $CRLF
   s += "UL LI                { display: none;font: 90%;list-style: square;}" & $CRLF
   s += "UL.showList LI       { display: block; }" & $CRLF
   s += ".defaultStyles UL    { color: black; }" & $CRLF
   s += "UL.defaultStyles LI  { display: none; }" & $CRLF
   s += "</STYLE>" & $CRLF
   s += "</HEAD>" & $CRLF
   s += "<BODY scroll='no' onselectstart='event.returnValue=false;' >" & $CRLF
   s += "<H2>Example: Expanding Table of Contents</H2>" & $CRLF
   s += "<!-- This code takes advantage of event bubbling by cancelling the onselectstart" & $CRLF
   s += "event on the container instead of on each UL. -->" & $CRLF
   s += "<UL onclick=""this.className='showList';""" & $CRLF
   s += "   ondblclick=""this.className='defaultStyles';""" & $CRLF
   s += "   onmouseover=""this.style.color='red';""" & $CRLF
   s += "   onmouseout=""this.style.color='black'"">Part I: DHTML Text Features" & $CRLF
   s += "    <LI><A HREF='about:blank.htm'>Activating Text in Response to User Actions</A>" & $CRLF
   s += "    <LI><A HREF='about:blank.htm'>Showing Text on Demand Using the CSS <B>DISPLAY</B> Attribute</A>" & $CRLF
   s += "    <LI><A HREF='about:blank.htm'>Animating Text by Character and Whole Words</A>" & $CRLF
   s += "</UL>" & $CRLF
   s += "<UL onclick=""this.className='showList';"" " & $CRLF
   s += "   ondblclick=""this.className='defaultStyles';""" & $CRLF
   s += "   onmouseover=""this.style.color='red';""" & $CRLF
   s += "   onmouseout=""this.style.color='black'"">Part II: Filter Effects" & $CRLF
   s += "    <LI><A HREF='about:blank.htm'>Creating Interpage Transitions</A>" & $CRLF
   s += "    <LI><A HREF='about:blank.htm'>Layering Graphical Objects</A>" & $CRLF
   s += "    <LI><A HREF='about:blank.htm'>Using Paths to Create Flying Text</A>" & $CRLF
   s += "    <LI><A HREF='about:blank.htm'>Generating Sliding Text with CSS Positioning</A>" & $CRLF
   s += "</UL>" & $CRLF
   s += "<UL onclick=""this.className='showList';""" & $CRLF
   s += "   ondblclick=""this.className='defaultStyles';""" & $CRLF
   s += "   onmouseover=""this.style.color='red';""" & $CRLF
   s += "   onmouseout=""this.style.color='black'"">Part III: Conclusion" & $CRLF
   s += "    <LI><A HREF='about:blank.htm'>Closing Remarks</A>" & $CRLF
   s += "</UL>" & $CRLF
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
