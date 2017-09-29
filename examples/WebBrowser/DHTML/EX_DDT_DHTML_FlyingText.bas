' ========================================================================================
' This example demonstrates two ways to implement flying text: through the marquee element
' and through Cascading Style Sheets (CSS) positioning.
' Adapted from the Microsoft example available at:
' http://samples.msdn.microsoft.com/workshop/samples/author/dhtml/howto/flyingtextex.htm
' Tutorial: http://msdn.microsoft.com/en-us/library/ms537649(VS.85).aspx
' ========================================================================================

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
   DIALOG NEW PIXELS, 0, "DHTML: Flying Text", , , 750, 450, %WS_OVERLAPPEDWINDOW TO hDlg

   LOCAL s AS WSTRING
   LOCAL bstrExePath AS STRING

   bstrExePath = EXE.Path$
   REPLACE "\" WITH "/" IN bstrExePath

   ' // Prefix with "MSHTML:"
   s  = "MSHTML:" & $CRLF
   s += "<HEAD>" & $CRLF
   s += "<TITLE>Flying Text</TITLE>" & $CRLF
   s += "<META HTTP-EQUIV=""MSThemeCompatible"" CONTENT=""Yes"">" & $CRLF
   s += "<SCRIPT>" & $CRLF
   s += "  function FlyFromRight (oImg,stopX)" & $CRLF
   s += "  {" & $CRLF
   s += "     oImg.style.pixelLeft -= 10;" & $CRLF
   s += "     if (oImg.style.pixelLeft <= stopX) " & $CRLF
   s += "       oImg.style.pixelLeft = stopX;" & $CRLF
   s += "     else" & $CRLF
   s += "     {" & $CRLF
   s += "       copyImg = oImg;" & $CRLF
   s += "       copyX   = stopX;" & $CRLF
   s += "       window.setTimeout (""FlyFromRight (copyImg,copyX);"",10);" & $CRLF
   s += "     }" & $CRLF
   s += "  }" & $CRLF
   s += "  function FlyFromLeft (oImg,stopX)" & $CRLF
   s += "  {" & $CRLF
   s += "     oImg.style.pixelLeft += 10;" & $CRLF
   s += "     if (oImg.style.pixelLeft >= stopX)" & $CRLF
   s += "       oImg.style.pixelLeft = stopX;" & $CRLF
   s += "     else" & $CRLF
   s += "     {" & $CRLF
   s += "       copyImg = oImg;" & $CRLF
   s += "       copyX   = stopX;" & $CRLF
   s += "       window.setTimeout (""FlyFromLeft (copyImg,copyX);"",10);" & $CRLF
   s += "     }" & $CRLF
   s += "  }" & $CRLF
   s += "  function FlyFromTop (oDiv,stopY)" & $CRLF
   s += "  {" & $CRLF
   s += "     oDiv.style.pixelTop += 10;" & $CRLF
   s += "     if (oDiv.style.pixelTop >= stopY)" & $CRLF
   s += "       oDiv.style.pixelTop = stopY;" & $CRLF
   s += "     else" & $CRLF
   s += "     {" & $CRLF
   s += "        copyDiv = oDiv;" & $CRLF
   s += "        copyY   = stopY;" & $CRLF
   s += "        window.setTimeout (""FlyFromTop (copyDiv,copyY);"", 10);" & $CRLF
   s += "     }" & $CRLF
   s += "  }" & $CRLF
   s += "  function FlyFromBottom (oDiv,stopY)" & $CRLF
   s += "  {" & $CRLF
   s += "     oDiv.style.pixelTop -= 10;" & $CRLF
   s += "     if (oDiv.style.pixelTop <= stopY)" & $CRLF
   s += "       oDiv.style.pixelTop = stopY;" & $CRLF
   s += "     else" & $CRLF
   s += "     {" & $CRLF
   s += "        copyDiv = oDiv;" & $CRLF
   s += "        copyY   = stopY;" & $CRLF
   s += "        window.setTimeout (""FlyFromBottom (copyDiv,copyY);"", 10);" & $CRLF
   s += "     }" & $CRLF
   s += "  }" & $CRLF
   s += "  function flyIn()" & $CRLF
   s += "  {" & $CRLF
   s += "        i = currentSequence;" & $CRLF
   s += "        switch (i)" & $CRLF
   s += "        {" & $CRLF
   s += "           // Fly From Top" & $CRLF
   s += "           case 0: sequence[i].style.pixelTop = document.body.offsetTop" & $CRLF
   s += "                                              - sequence[i].offsetTop" & $CRLF
   s += "                                              - sequence[i].offsetHeight;" & $CRLF
   s += "                   sequence[i].style.visibility= 'visible';" & $CRLF
   s += "                   window.setTimeout (""FlyFromTop (sequence[i],0);"",10);" & $CRLF
   s += "                   break;" & $CRLF
   s += "           // Fly from Right" & $CRLF
   s += "           case 1:  sequence[i].style.pixelLeft = document.body.offsetWidth" & $CRLF
   s += "                                                - sequence[i].offsetLeft;" & $CRLF
   s += "                    sequence[i].style.visibility= 'visible';" & $CRLF
   s += "                    window.setTimeout (""FlyFromRight (sequence[i],0);"",10);" & $CRLF
   s += "                    break;" & $CRLF
   s += "           default: break;" & $CRLF
   s += "           // Fly from Bottom" & $CRLF
   s += "           case 2: sequence [i].style.pixelTop = document.body.offsetHeight" & $CRLF
   s += "                                               - sequence[i].offsetTop;" & $CRLF
   s += "                    sequence[i].style.visibility= 'visible';" & $CRLF
   s += "                    window.setTimeout (""FlyFromBottom (sequence[i],0);"",10);" & $CRLF
   s += "        }" & $CRLF
   s += "       // prepare for the next sequence" & $CRLF
   s += "currentSequence++;" & $CRLF
   s += "      // stop when end of animation sequence is reached!" & $CRLF
   s += "      if (currentSequence == sequence.length)" & $CRLF
   s += "         window.clearInterval(iTimerID);" & $CRLF
   s += "  }" & $CRLF
   s += "  function init()" & $CRLF
   s += "  {" & $CRLF
   s += "     // Define the order of objects in the animation sequence" & $CRLF
   s += "     sequence = new Array (Text1, Text2, Text3);" & $CRLF
   s += "     // setup the timer" & $CRLF
   s += "     iTimerID= window.setInterval(""flyIn()"",1500);" & $CRLF
   s += "     // initialize where you are in the sequence" & $CRLF
   s += "     currentSequence=0;" & $CRLF
   s += "  }" & $CRLF
   s += "</script>" & $CRLF
   s += "<!-- SAMPLE_STYLE_START -->" & $CRLF
   s += "<LINK REL='stylesheet' HREF='" & bstrExePath & "samples.css' TYPE='text/css'>" & $CRLF
   s += "<!-- SAMPLE_STYLE_END -->" & $CRLF
   s += "</HEAD>" & $CRLF
   s += "<STYLE>" & $CRLF
   s += "<!--" & $CRLF
   s += "  H1        {font-size: 20pt; font-weight:bold; font-family: Arial,Helvetica;" & $CRLF
   s += "             margin-top: 20px;" & $CRLF
   s += "             margin-bottom: 10px;" & $CRLF
   s += "             color: gold;" & $CRLF
   s += "             text-align:center }" & $CRLF
   s += "  LI.yellow {font-size: 16pt; font-weight:600; font-family: Arial,Helvetica;" & $CRLF
   s += "             color: gold;" & $CRLF
   s += "             margin-top:.2in; margin-bottom: 0.2in;" & $CRLF
   s += "             margin-left:0.5in; margin-right:0.5in;" & $CRLF
   s += "             }" & $CRLF
   s += "  LI.white  {font-size: 14pt; font-weight:600; font-family: Arial,Helvetica;" & $CRLF
   s += "             color: white;" & $CRLF
   s += "             margin-top: 0.1in;" & $CRLF
   s += "             margin-left: 0.5in; margin-right: 0.5in;" & $CRLF
   s += "            }" & $CRLF
   s += "-->" & $CRLF
   s += "</STYLE>" & $CRLF
   s += "<BODY scroll='no' onload='init();' BGCOLOR=BLACK LEFTMARGIN=0 TOPMARGIN=0 BOTTOMMARGIN=0 RIGHTMARGIN=0>" & $CRLF
   s += "<DIV CLASS='body'>" & $CRLF
   s += "<IMG src='"  & bstrExePath & "background.jpg' WIDTH=100% HEIGHT=100%" & $CRLF
   s += "     STYLE='position:absolute; top:0; left:0; z-index:-1' border='0' alt='Windows background image'>" & $CRLF
   s += "<P>" & $CRLF
   s += "<H1>Flying Text<HR SIZE=1></H1>" & $CRLF
   s += "<UL>" & $CRLF
   s += "<div ID='Text1' style='position:relative; visibility: hidden'>" & $CRLF
   s += "<LI class='yellow'>Use Dynamic HTML to differentiate your content and create compelling Web sites" & $CRLF
   s += "</div>" & $CRLF
   s += "<div ID='Text2' style='position:relative; visibility:hidden'>" & $CRLF
   s += "<LI class='yellow'>Use the Document Object Model (DOM) to create interactive documents" & $CRLF
   s += "</div>" & $CRLF
   s += "   <div ID='Text3' style='position:relative; visibility:hidden'>" & $CRLF
   s += "   <UL>" & $CRLF
   s += "     <LI class='white'>Interact with the user through the event model" & $CRLF
   s += "     <LI class='white'>Interactively change the appearance of the document with Dynamic Styles and Dynamic Content" & $CRLF
   s += "     <LI class='white'>Take precise control over your layout with CSS-positioning" & $CRLF
   s += "   </UL>" & $CRLF
   s += "   </div>" & $CRLF
   s += "</UL>" & $CRLF
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
