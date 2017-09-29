' ========================================================================================
' This example uses the table container to demonstrate color cycling effects for text.
' The code provided in this task transfers to any object you might want to use.
' Adapted from the Microsoft example available at:
' http://samples.msdn.microsoft.com/workshop/samples/author/dhtml/howto/CyclingTextColorEX.htm
' Tutorial: http://msdn.microsoft.com/en-us/library/ms537648(VS.85).aspx
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
   DIALOG NEW PIXELS, 0, "DHTML: Cycling Text Color", , , 450, 250, %WS_OVERLAPPEDWINDOW TO hDlg

   LOCAL s AS WSTRING
   ' // Prefix with "MSHTML:"
   s = "MSHTML:<HTML>" & $CRLF
   s += "<HEAD>" & $CRLF
   s += "<title>How to Change Text Color Character by Character Sample</title>" & $CRLF
   s += "<META HTTP-EQUIV=""MSThemeCompatible"" CONTENT=""Yes"">" & $CRLF
   s += "<style type='text/css'>" & $CRLF
   s += "body {" & $CRLF
   s += "   background-color: black;" & $CRLF
   s += "   color: orange;" & $CRLF
   s += "}" & $CRLF
   s += "table {" & $CRLF
   s += "   font-family: 'Comic Sans MS';" & $CRLF
   s += "   font-size: 30pt;" & $CRLF
   s += "   color: black;" & $CRLF
   s += "}" & $CRLF
   s += "#celSlide {" & $CRLF
   s += "   letter-spacing: 10px;" & $CRLF
   s += "   color: aqua;" & $CRLF
   s += "}" & $CRLF
   s += "</style>" & $CRLF
   s += "<script type='text/javascript'><!--" & $CRLF
   s += "// --- Global Variable Declarations" & $CRLF
   s += "var sColor1 = 'white';" & $CRLF
   s += "var sColor2 = 'gray';" & $CRLF
   s += "var iColorLoop = 0;" & $CRLF
   s += "var iCurrentCELL = 0;" & $CRLF
   s += "var bAscending = true;" & $CRLF
   s += "var output = null;" & $CRLF
   s += "var startTime = new Date();" & $CRLF
   s += "function startCycle()" & $CRLF
   s += "{" & $CRLF
   s += "   output = document.getElementById('output');" & $CRLF
   s += "   setInterval(cycleColors,100);" & $CRLF
   s += "}" & $CRLF
   s += "function cycleColors()" & $CRLF
   s += "{" & $CRLF
   s += "   var triggerTime = new Date();" & $CRLF
   s += "   output.innerHTML = Math.round(triggerTime - startTime);" & $CRLF
   s += "   startTime = triggerTime;" & $CRLF
   s += "   var celColorChange = document.getElementById('celColorChange').cells;" & $CRLF
   s += "   if (bAscending)" & $CRLF
   s += "   {" & $CRLF
   s += "      celColorChange[iCurrentCELL++].style.color = sColor2;" & $CRLF
   s += "      if (iCurrentCELL == celColorChange.length)" & $CRLF
   s += "      {" & $CRLF
   s += "         bAscending = false;" & $CRLF
   s += "         iCurrentCELL = celColorChange.length;" & $CRLF
   s += "      }" & $CRLF
   s += "   }" & $CRLF
   s += "   else" & $CRLF
   s += "   {" & $CRLF
   s += "      celColorChange[--iCurrentCELL].style.color = sColor1;" & $CRLF
   s += "      if (iCurrentCELL == 0)" & $CRLF
   s += "      {" & $CRLF
   s += "         bAscending = true;" & $CRLF
   s += "         changeColors();" & $CRLF
   s += "      }" & $CRLF
   s += "   }" & $CRLF
   s += "}" & $CRLF
   s += "function changeColors()" & $CRLF
   s += "{" & $CRLF
   s += "   switch (iColorLoop++)" & $CRLF
   s += "   {" & $CRLF
   s += "   case 0:" & $CRLF
   s += "      sColor1='yellow';" & $CRLF
   s += "      sColor2='orange';" & $CRLF
   s += "      break;" & $CRLF
   s += "   case 1:" & $CRLF
   s += "      sColor1='hotpink';" & $CRLF
   s += "      sColor2='purple';" & $CRLF
   s += "      break;" & $CRLF
   s += "   case 2:" & $CRLF
   s += "      sColor1='aqua';" & $CRLF
   s += "      sColor2='blue';" & $CRLF
   s += "      break;" & $CRLF
   s += "   case 3:" & $CRLF
   s += "      sColor1='lightgreen';" & $CRLF
   s += "      sColor2='green';" & $CRLF
   s += "   }" & $CRLF
   s += "   if (iColorLoop > 3)" & $CRLF
   s += "      iColorLoop = 0;" & $CRLF
   s += "}" & $CRLF
   s += "--></script>" & $CRLF
   s += "</head>" & $CRLF
   s += "<body scroll='no' onload='startCycle()'>" & $CRLF
   s += "<div class='body'>" & $CRLF
   s += "   <table>" & $CRLF
   s += "      <tr id='celColorChange'>" & $CRLF
   s += "         <td>Dynamic</td>" & $CRLF
   s += "         <td>H</td>" & $CRLF
   s += "         <td>T</td>" & $CRLF
   s += "         <td>M</td>" & $CRLF
   s += "         <td>L</td>" & $CRLF
   s += "      </tr>" & $CRLF
   s += "      <tr>" & $CRLF
   s += "         <td id='celSlide'>" & $CRLF
   s += "         <marquee behavior='slide' direction='left' loop='1' width='170'> rocks!" & $CRLF
   s += "         </marquee> </td>" & $CRLF
   s += "      </tr>" & $CRLF
   s += "   </table>" & $CRLF
   s += "   <div style='font-size:x-small;' id='output'> </div>" & $CRLF
   s += "</body>" & $CRLF
   s += "</html>" & $CRLF

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
