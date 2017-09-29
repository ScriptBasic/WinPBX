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
   DIALOG NEW PIXELS, 0, "Virtual Earth Map", , , 700, 400, %WS_OVERLAPPEDWINDOW TO hDlg

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' // Build the html script
   LOCAL s AS WSTRING
   LOCAL cx, cy AS DOUBLE
   LOCAL zoom AS LONG
   cx = -6.89186#
   cy = 107.59987#
   zoom = 8

   s  = "<!DOCTYPE html>" & $CRLF
   s += "<html>" & $CRLF
   s += "<head>" & $CRLF
   s += "   <title>Virtual Earth Map</title>" & $CRLF
   s += "   <meta http-equiv='Content-Type' content='text/html; charset=utf-8'>" & $CRLF
   s += "   <script type='text/javascript' src='http://dev.virtualearth.net/mapcontrol/mapcontrol.ashx?v=6'>" & $CRLF
   s += "   </script>" & $CRLF
   s += "   <script type='text/javascript'>" & $CRLF
   s += "      var map = null;" & $CRLF
   s += "      var dyCodeCoord = new VELatLong(" & FORMAT$(cx) & ", " & FORMAT$(cy) & ");" & $CRLF
   s += "      function GetMap()" & $CRLF
   s += "         {" & $CRLF
   s += "            map = new VEMap('myMap');" & $CRLF
   s += "            map.LoadMap(dyCodeCoord," & FORMAT$(zoom) & ");" & $CRLF
   s += "         }" & $CRLF
   s += "   </script>" & $CRLF
   s += "   <style type='text/css'>" & $CRLF
   s += "      .map" & $CRLF
   s += "      {" & $CRLF
   s += "         position: absolute;" & $CRLF
   s += "         top: 0;" & $CRLF
   s += "         left: 0;" & $CRLF
   s += "         width: 100%;" & $CRLF
   s += "         height: 100%;" & $CRLF
   s += "      }" & $CRLF
   s += "   </style>" & $CRLF
   s += "</head>" & $CRLF
   s += "<body scroll='no' style='MARGIN: 0px 0px 0px 0px' onload='GetMap();'>" & $CRLF
   s += "<body>" & $CRLF
   s += "   <div id='myMap' class='map'>" & $CRLF
   s += "   </div>" & $CRLF
   s += "</body>" & $CRLF
   s += "</html>" & $CRLF

   ' // Save the script as a temporary file
   LOCAL bstrTempFileName AS WSTRING
   bstrTempFileName = AfxSaveTempFile(s, "", "TMP", "html", 1)

   ' // Create the WebBrowser control with the embedded map
   LOCAL nWide, nHigh AS LONG
   DIALOG GET CLIENT hDlg TO nWide, nHigh
   pWindow.AddWebBrowserControl(hDlg, %IDC_WEBBROWSER, bstrTempFileName, NOTHING, 0, 0, nWide, nHigh)

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
