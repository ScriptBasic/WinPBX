' ========================================================================================
' Demonstrates a mouse-driven animation sequence from a slide show presentation.
' Click the left mouse button repeteadly to animate the hidden elements.
' Adapted from the Microsoft example available at:
' http://samples.msdn.microsoft.com/workshop/samples/author/dhtml/howto/animatingSequenceEX2.htm
' Tutorial: http://msdn.microsoft.com/en-us/library/ms537642(VS.85).aspx
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
   DIALOG NEW PIXELS, 0, "DHTML: Mouse-Driven Animation Sequence", , , 750, 450, %WS_OVERLAPPEDWINDOW TO hDlg

   ' // Add a WebBrowser control
   LOCAL s AS WSTRING
   LOCAL bstrExePath AS STRING

   bstrExePath = EXE.Path$
   REPLACE "\" WITH "/" IN bstrExePath

   ' // Prefix with "MSHTML:"
   s = "MSHTML:<HTML>" & $CRLF
   s += "<HEAD>" & $CRLF
   s += "<TITLE>untitled</TITLE>" & $CRLF
   s += "<META HTTP-EQUIV=""MSThemeCompatible"" CONTENT=""Yes"">" & $CRLF
   s += "<script>" & $CRLF
   s += "   function window.onload()" & $CRLF
   s += "   {" & $CRLF
   s += "      // Define the order of objects in the animation sequence" & $CRLF
   s += "      sequence= new Array (Image1, Image2, Image3, Image4);" & $CRLF
   s += "      numClick= 0;" & $CRLF
   s += "   }" & $CRLF
   s += "   function document.onclick()" & $CRLF
   s += "   {" & $CRLF
   s += "     // when end of animation sequence is reached, go to the next slide" & $CRLF
   s += "     if (numClick < sequence.length)" & $CRLF
   s += "        sequence [numClick].style.visibility = 'visible';" & $CRLF
   s += "     numClick++;" & $CRLF
   s += "   }" & $CRLF
   s += "</script>" & $CRLF
   s += "<STYLE>" & $CRLF
   s += "<!--" & $CRLF
   s += "  H1        {font-size: 16pt; font-weight:bold; font-family: Arial,Helvetica;" & $CRLF
   s += "             margin-top: 5px;" & $CRLF
   s += "             margin-bottom: 5px;" & $CRLF
   s += "             color: gold;" & $CRLF
   s += "             text-align:center }" & $CRLF
   s += "-->" & $CRLF
   s += "</STYLE>" & $CRLF
   s += "<!-- SAMPLE_STYLE_START -->" & $CRLF
   s += "<LINK REL='stylesheet' HREF='" & bstrExePath & "samples.css' TYPE='text/css'>" & $CRLF
   s += "<!-- SAMPLE_STYLE_END -->" & $CRLF
   s += "</HEAD>" & $CRLF
   s += "<BODY SCROLL='auto'>" & $CRLF
   s += "<IMG src='" & bstrExePath & "background.jpg' WIDTH='100%' HEIGHT='140%'" & $CRLF
   s += "     STYLE='position:absolute; top:0; left:0; z-index:-1' border='0' alt='Windows background image'>" & $CRLF
   s += "   s += '<H1>Mouse-Driven Animation Sequence<HR SIZE=1></H1>'" & $CRLF
   s += "<!--Animating Objects on a MouseClick-->" & $CRLF
   s += "<IMG ID='Image1' src='" & bstrExePath & "web-1.gif' WIDTH=500 HEIGHT=428" & $CRLF
   s += "     STYLE='position:absolute; top:120; left:50;" & $CRLF
   s += "     visibility:hidden' border='0' alt='splash screen'>" & $CRLF
   s += "<IMG ID='Image2' src='" & bstrExePath & "web-2.gif' WIDTH=220 HEIGHT=408" & $CRLF
   s += "     STYLE='position:absolute; top:100; left:500;" & $CRLF
   s += "     visibility:hidden' border='0' alt='splash screen'>" & $CRLF
   s += "<IMG ID='Image3' src='" & bstrExePath & "web-3.gif' WIDTH=430 HEIGHT=444" & $CRLF
   s += "     STYLE='position:absolute; top:110; left:130;" & $CRLF
   s += "     visibility:hidden' border='0' alt='splash screen'>" & $CRLF
   s += "<IMG ID='Image4' src='" & bstrExePath & "web-4.gif' WIDTH=570	HEIGHT=318" & $CRLF
   s += "     STYLE='position:absolute; top:240; left:132;" & $CRLF
   s += "     visibility:hidden' border='0' alt='splash screen'>" & $CRLF
   s += "</BODY>" & $CRLF
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
