' ========================================================================================
' Demonstrates a timer-driven animation sequence from a slide show presentation.
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
FUNCTION WinMain (BYVAL hInstance AS DWORD, BYVAL hPrevInstance AS DWORD, BYVAL lpszCmdLine AS WSTRINGZ PTR, BYVAL nCmdShow AS LONG) AS LONG

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' // Create the dialog
   LOCAL hDlg AS DWORD
   DIALOG NEW PIXELS, 0, "DHTML: Timer-Driven Animation Sequence", , , 790, 450, %WS_OVERLAPPEDWINDOW TO hDlg

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
   s += "<HEAD>" & $CRLF
   s += "<SCRIPT>" & $CRLF
   s += "  function ApplyTransition(oImg)" & $CRLF
   s += "  {" & $CRLF
   s += "      oImg.filters.item(0).Apply();" & $CRLF
   s += "      oImg.style.visibility = 'visible';" & $CRLF
   s += "      oImg.filters.item(0).Play();" & $CRLF
   s += "  }" & $CRLF
   s += "  function Animate()" & $CRLF
   s += "  {" & $CRLF
   s += "      // Apply a Transition" & $CRLF
   s += "      ApplyTransition (sequence[currentSequence++]);" & $CRLF
   s += "      // stop when end of animation sequence is reached!" & $CRLF
   s += "      if (currentSequence == sequence.length)" & $CRLF
   s += "         window.clearInterval(iTimerID);" & $CRLF
   s += "  }" & $CRLF
   s += "  function window.onload()" & $CRLF
   s += "  {" & $CRLF
   s += "     // Define the order of objects in the animation sequence" & $CRLF
   s += "     sequence = new Array (CDFWindow, CDF1, CDF2, CDF3, CDF4);" & $CRLF
   s += "     // setup the timer" & $CRLF
   s += "     iTimerID= window.setInterval('Animate()',3000);" & $CRLF
   s += "     // initialize where you are in the sequence" & $CRLF
   s += "     currentSequence=0;" & $CRLF
   s += "  }" & $CRLF
   s += "</SCRIPT>" & $CRLF
   s += "<!-- SAMPLE_STYLE_START -->" & $CRLF
   s += "<LINK REL='stylesheet' HREF='" & bstrExePath & "samples.css' TYPE='text/css'>" & $CRLF
   s += "<!-- SAMPLE_STYLE_END -->" & $CRLF
   s += "</HEAD>" & $CRLF
   s += "<STYLE>" & $CRLF
   s += "<!--" & $CRLF
   s += "  H1        {font-size: 16pt; font-weight:bold; font-family: Arial,Helvetica;" & $CRLF
   s += "             margin-top: 5px;" & $CRLF
   s += "             margin-bottom: 5px;" & $CRLF
   s += "             color: gold;" & $CRLF
   s += "             text-align:center }" & $CRLF
   s += "  H3        {font-size: 14pt; font-weight:bold; font-family: Arial,Helvetica;" & $CRLF
   s += "	     margin-left: 5px;" & $CRLF
   s += "             margin-top: 5px;" & $CRLF
   s += "             color: gold;" & $CRLF
   s += "             text-align:left }" & $CRLF
   s += "  LI.smyellow {font-size: 12pt; font-weight:600; font-family: Arial,Helvetica;" & $CRLF
   s += "               color: gold;" & $CRLF
   s += "               margin-bottom:0.1in;" & $CRLF
   s += "               list-style-type:square" & $CRLF
   s += "              }" & $CRLF
   s += "-->" & $CRLF
   s += "</STYLE>" & $CRLF
   s += "<BODY>" & $CRLF
   s += "<IMG src='" & bstrExePath & "background.jpg' WIDTH='100%' HEIGHT='125%'" & $CRLF
   s += "     STYLE='position:absolute; top:0; left:0; z-index:-50' border='0' alt='Windows background image'>" & $CRLF
   s += "<P>" & $CRLF
   s += "<H1>Timer-Driven Animation Sequence<HR SIZE=1></H1>" & $CRLF
   s += "<!--Animating Objects on a Timer -->" & $CRLF
   s += "<DIV STYLE='position:absolute; top: 110; left:10; width:200'>" & $CRLF
   s += "<H3><U>CDF</U></H3>" & $CRLF
   s += "<UL>" & $CRLF
   s += "   <LI class='smyellow'>An application of the XML standard" & $CRLF
   s += "   <LI class='smyellow'>In cooperation with key industry partners" & $CRLF
   s += "   <LI class='smyellow'>Submission to W3C" & $CRLF
   s += "</UL>" & $CRLF
   s += "<H3><U>XML</U></H3>" & $CRLF
   s += "<UL> " & $CRLF
   s += "   <LI class='smyellow'>eXtensible Markup Language" & $CRLF
   s += "   <LI class='smyellow'>SGML syntax for structured data" & $CRLF
   s += "   <LI class='smyellow'>Industry support: Sun, Netscape, SoftQuad, and others." & $CRLF
   s += "</UL>" & $CRLF
   s += "</DIV>" & $CRLF
   s += "<!-- Semicolons are important between CSS attributes; otherwise, they don't" & $CRLF
   s += "     seem to be recognized correctly -->" & $CRLF
   s += "<IMG ID='CDFWindow' SRC='" & bstrExePath & "cdf.gif' WIDTH=448 HEIGHT=448" & $CRLF
   s += "     STYLE='top:40; left:220; position:absolute;" & $CRLF
   s += "            filter:revealTrans(Duration=1.0, Transition=7); visibility:hidden' border='0' alt='CDF script'>" & $CRLF
   s += "<IMG ID='CDF1' SRC='" & bstrExePath & "cdf-1.gif' WIDTH=335 HEIGHT=118" & $CRLF
   s += "     STYLE='position:absolute; top: 40; left:430;" & $CRLF
   s += "           filter:revealTrans(Duration=1.0, Transition=7); visibility:hidden' border='0' alt='CDF image'>" & $CRLF
   s += "<IMG ID='CDF2' SRC='" & bstrExePath & "cdf-2.gif' WIDTH=413 HEIGHT=147" & $CRLF
   s += "     STYLE='position:absolute; top: 100; left:352;" & $CRLF
   s += "           filter:revealTrans(Duration=1.0, Transition=7); visibility:hidden' border='0' alt='CDF image'>" & $CRLF
   s += "<IMG ID='CDF3' SRC='" & bstrExePath & "cdf-3.gif' WIDTH=400 HEIGHT=103" & $CRLF
   s += "     STYLE='position:absolute; top: 245; left:365;" & $CRLF
   s += "           filter:revealTrans(Duration=1.0, Transition=7); visibility:hidden' border='0' alt='CDF image'>" & $CRLF
   s += "<IMG ID='CDF4' SRC='" & bstrExePath & "cdf-4.gif' WIDTH=170 HEIGHT=132" & $CRLF
   s += "     STYLE='position:absolute; top: 316; left:598;" & $CRLF
   s += "           filter:revealTrans(Duration=1.0, Transition=7); visibility:hidden' border='0' alt='CDF image'>" & $CRLF
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
