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
   DIALOG NEW PIXELS, 0, "Google Map", , , 700, 400, %WS_OVERLAPPEDWINDOW TO hDlg

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' // Build the html script
   LOCAL s AS WSTRING
   LOCAL cx, cy AS DOUBLE
   LOCAL zoom AS LONG
   cx = 39.47#
   cy = 0.28#
   zoom = 7

   s  = "<!DOCTYPE html>" & $CRLF
   s += "<html>" & $CRLF
   s += "<head>" & $CRLF
   s += "<meta name='viewport' content='initial-scale=1.0, user-scalable=no' />" & $CRLF

   s += "      <meta http-equiv='X-UA-Compatible' content='IE=edge'>"   '--> added: used Edge browser
   s += "      <meta http-equiv='MSThemeCompatible' content='Yes'>"     '--> added: allow visual styles

   s += "<style type='text/css'>" & $CRLF
   s += "html { height: 100% }" & $CRLF
   s += "  body { height: 100%; margin: 0px; padding: 0px }" & $CRLF
   s += "  #map_canvas { height: 100% }" & $CRLF

   s += "         .infomsg {display:none;}"                            '--> added: workaround to ignore the message

   s += "</style>" & $CRLF
   s += "<script type='text/javascript'" & $CRLF
   s += "    src='http://maps.google.com/maps/api/js?sensor=false'>" & $CRLF
   s += "</script>" & $CRLF
   s += "<script type='text/javascript'>" & $CRLF
   s += "  function initialize() {" & $CRLF
   s += "    var latlng = new google.maps.LatLng(" & FORMAT$(cx) & "," & FORMAT$(cy) & ");" & $CRLF
   s += "    var myOptions = {" & $CRLF
   s += "      zoom: " & FORMAT$(zoom) & "," & $CRLF
   s += "      center: latlng," & $CRLF
   s += "      mapTypeId: google.maps.MapTypeId.ROADMAP" & $CRLF
   s += "    };" & $CRLF
   s += "    var map = new google.maps.Map(document.getElementById('map_canvas')," & $CRLF
   s += "        myOptions);" & $CRLF
   s += "  }" & $CRLF
   s += "</script>" & $CRLF
   s += "</head>" & $CRLF
   s += "<body scroll='no' onload='initialize()'>" & $CRLF
   s += "  <div id='map_canvas' style='width:100%; height:100%'></div>" & $CRLF
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
