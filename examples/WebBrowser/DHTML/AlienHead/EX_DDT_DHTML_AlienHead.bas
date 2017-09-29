' ========================================================================================
' Use the mouse to create an alien!
' This is an adaptation of a Microsoft's MSDN online samples.
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

   ' // Create the dialog
   LOCAL hDlg AS DWORD
   DIALOG NEW PIXELS, 0, "WebBrowser", , , 750, 450, %WS_OVERLAPPEDWINDOW TO hDlg

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION
   ' // Add a WebBrowser control
   LOCAL hCtl AS DWORD
   LOCAL s AS WSTRING
   LOCAL bstrExePath AS STRING

   bstrExePath = EXE.Path$
   REPLACE "\" WITH "/" IN bstrExePath

   s  = "MSHTML:" & $CRLF
   s += "<HEAD>" & $CRLF
   s += "<TITLE>MSDN Online Samples:  Alien Head</TITLE>" & $CRLF
   s += "<META NAME=""FILENAME"" CONTENT=""alienhead.HTM"">" & $CRLF
   s += "<META HTTP-EQUIV=""MSThemeCompatible"" CONTENT=""Yes"">" & $CRLF
   s += "<STYLE>" & $CRLF
   s += "  A:link { color:#003399; text-decoration:none; }" & $CRLF
   s += "  A:visited { color:#6699CC; text-decoration:none; }" & $CRLF
   s += "  A:hover { text-decoration:underline; }" & $CRLF
   s += "</STYLE>" & $CRLF
   s += "<SCRIPT LANGUAGE=""VBScript"">" & $CRLF
   s += "      dim curElement" & $CRLF
   s += "      curElement = -1 " & $CRLF
   s += "      sub document_onMouseMove()" & $CRLF
   s += "         dim newleft" & $CRLF
   s += "         dim newTop" & $CRLF
   s += "        newleft = 0" & $CRLF
   s += "        newTop = 0" & $CRLF
   s += "        if ( window.event.button = 1 ) AND (curElement <> -1) then" & $CRLF
   s += "        'if ( window.event.button = 1 ) AND (not (curElement is null)) then" & $CRLF
   s += "        window.defaultStatus = curElement" & $CRLF
   s += "          newleft = window.event.clientX-document.all.OuterDiv.offsetLeft-(curElement.offsetWidth/2)" & $CRLF
   s += "          if (newleft<0) then" & $CRLF
   s += "          newleft=0" & $CRLF
   s += "          end if" & $CRLF
   s += "          curElement.style.pixelLeft = newleft" & $CRLF
   s += "          newtop = window.event.clientY -document.all.OuterDiv.offsetTop-(curElement.offsetHeight/2)" & $CRLF
   s += "          if (newtop<0) then" & $CRLF
   s += "             newtop=0" & $CRLF
   s += "          end if" & $CRLF
   s += "          curElement.style.pixelTop = newtop" & $CRLF
   s += "          window.event.returnValue = false" & $CRLF
   s += "          window.event.cancelBubble = true" & $CRLF
   s += "        end if" & $CRLF
   s += "       end sub" & $CRLF
   s += "      sub document_onDragStart()" & $CRLF
   s += "        ' Don't do default drag operation." & $CRLF
   s += "        if (""IMG"" = window.event.srcElement.tagName) then" & $CRLF
   s += "        window.event.returnValue = false" & $CRLF
   s += "       end if" & $CRLF
   s += "      end sub" & $CRLF
   s += "      sub document_onMouseDown()" & $CRLF
   s += "        if ((window.event.button = 1) AND (window.event.srcElement.tagName = ""IMG"")) then" & $CRLF
   s += "          set curElement = window.event.srcElement" & $CRLF
   s += "          Window.defaultStatus = curElement" & $CRLF
   s += "        end if" & $CRLF
   s += "      end sub" & $CRLF
   s += "      sub document_onMouseUp()" & $CRLF
   s += "        curElement = -1" & $CRLF
   s += "        'curElement = null " & $CRLF
   s += "        Window.defaultStatus = curElement" & $CRLF
   s += "      end sub" & $CRLF
   s += "      sub alienhead_onmousedown() ' Do not allow the alien head to be dragged." & $CRLF
   s += "      window.event.cancelBubble = true " & $CRLF
   s += "     end sub" & $CRLF
   s += "</SCRIPT>" & $CRLF
   s += "</HEAD>" & $CRLF
   s += "<BODY SCROLL=""auto"" TOPMARGIN=20 LEFTMARGIN=""40"" BGCOLOR=""#FFFFFF"" LINK=""#000066"" VLINK=""#666666"" TEXT=""#000000"">" & $CRLF
   s += "<!--TOOLBAR_START-->" & $CRLF
   s += "<!--TOOLBAR_EXEMPT-->" & $CRLF
   s += "<!--TOOLBAR_END-->" & $CRLF
   s += "<H2>Alien Head</H2>" & $CRLF
   s += "<FONT face=verdana,arial,helvetica size=2>" & $CRLF
   s += "<FONT face=""Verdana, Arial, Helvetica"" size=3><B>Use the mouse to create an alien!</B></FONT>" & $CRLF
   s += "<BR>" & $CRLF
   s += "<DIV id=OuterDiv style=""HEIGHT: 350px; POSITION: relative; WIDTH: 100%"">" & $CRLF
   s += "  <IMG height=86 id=alienhead src=""" & bstrExePath & "alienhead.gif"" style=""HEIGHT: 150px; LEFT: 142pt; POSITION: absolute; TOP: 83pt; WIDTH: 230px; Z-INDEX: 2"" width=135 >" & $CRLF
   s += "  <IMG height=51 id=hair1 src=""" & bstrExePath & "hair1.gif"" style=""HEIGHT: 38pt; LEFT: 0pt; POSITION: absolute; TOP: 8pt; WIDTH: 63pt; Z-INDEX: 22"" width=84 >" & $CRLF
   s += "  <IMG height=44 id=hair2 src=""" & bstrExePath & "hair2.gif"" style=""HEIGHT: 33pt; LEFT: 8pt; POSITION: absolute; TOP: 116pt; WIDTH: 56pt; Z-INDEX: 21"" width=74 >" & $CRLF
   s += "  <IMG height=67 id=hair3 src=""" & bstrExePath & "hair3.gif"" style=""HEIGHT: 50pt; LEFT: 0pt; POSITION: absolute; TOP: 58pt; WIDTH: 68pt; Z-INDEX: 20"" width=90 >" & $CRLF
   s += "  <IMG height=60 id=ears1 src=""" & bstrExePath & "ears1.gif"" style=""HEIGHT: 45pt; LEFT: 68.256pt; POSITION: absolute; TOP: 23.976pt; WIDTH: 89pt; Z-INDEX: 19"" width=119 >" & $CRLF
   s += "  <IMG height=64 id=ears2 src=""" & bstrExePath & "ears2.gif"" style=""HEIGHT: 48pt; LEFT: 167.256pt; POSITION: absolute; TOP: 178.488pt; WIDTH: 93pt; Z-INDEX: 18"" width=124 >" & $CRLF
   s += "  <IMG height=58 id=ears3 src=""" & bstrExePath & "ears3.gif"" style=""HEIGHT: 44pt; LEFT: 175.536pt; POSITION: absolute; TOP: 110.232pt; WIDTH: 85pt; Z-INDEX: 17"" width=113 >" & $CRLF
   s += "  <IMG height=46 id=nose1 src=""" & bstrExePath & "nose1.gif"" style=""HEIGHT: 35pt; LEFT: 327pt; POSITION: absolute; TOP: 99pt; WIDTH: 29pt; Z-INDEX: 16"" width=39 >" & $CRLF
   s += "  <IMG height=54 id=nose2 src=""" & bstrExePath & "nose2.gif"" style=""HEIGHT: 41pt; LEFT: 203.256pt; POSITION: absolute; TOP: 112.536pt; WIDTH: 26pt; Z-INDEX: 15"" width=54 >" & $CRLF
   s += "  <IMG height=38 id=nose3 src=""" & bstrExePath & "nose3.gif"" style=""HEIGHT: 29pt; LEFT: 213.768pt; POSITION: absolute; TOP: 67.536pt; WIDTH: 29pt; Z-INDEX: 14"" width=39 >" & $CRLF
   s += "  <IMG height=26 id=mouth1 src=""" & bstrExePath & "mouth1.gif"" style=""HEIGHT: 20pt; LEFT: 368pt; POSITION: absolute; TOP: 107pt; WIDTH: 59pt; Z-INDEX: 13"" width=78 >" & $CRLF
   s += "  <IMG height=30 id=mouth2 src=""" & bstrExePath & "mouth2.gif"" style=""HEIGHT: 23pt; LEFT: 368pt; POSITION: absolute; TOP: 140pt; WIDTH: 50pt; Z-INDEX: 12"" width=66 >" & $CRLF
   s += "  <IMG height=30 id=mouth3 src=""" & bstrExePath & "mouth3.gif"" style=""HEIGHT: 23pt; LEFT: 368pt; POSITION: absolute; TOP: 74pt; WIDTH: 47pt; Z-INDEX: 11"" width=62 >" & $CRLF
   s += "  <IMG height=24 id=eyes1 src=""" & bstrExePath & "eyes1.gif"" style=""HEIGHT: 18pt; LEFT: 200.232pt; POSITION: absolute; TOP: 95.256pt; WIDTH: 47pt; Z-INDEX: 10"" width=62 >" & $CRLF
   s += "  <IMG height=25 id=eyes2 src=""" & bstrExePath & "eyes2.gif"" style=""HEIGHT: 19pt; LEFT: 198.72pt; POSITION: absolute; TOP: 110.232pt; WIDTH: 38pt; Z-INDEX: 9"" width=50 >" & $CRLF
   s += "  <IMG height=24 id=eyes3 src=""" & bstrExePath & "eyes3.gif"" style=""HEIGHT: 18pt; LEFT: 189pt; POSITION: absolute; TOP: 150.768pt; WIDTH: 50pt; Z-INDEX: 8"" width=66 >" & $CRLF
   s += "  <IMG height=28 id=shoe1 src=""" & bstrExePath & "shoes1.gif"" style=""HEIGHT: 21pt; LEFT: 335pt; POSITION: absolute; TOP: 173pt; WIDTH: 71pt; Z-INDEX: 7"" width=94 >" & $CRLF
   s += "  <IMG height=29 id=shoe2 src=""" & bstrExePath & "shoes2.gif"" style=""HEIGHT: 22pt; LEFT: 335pt; POSITION: absolute; TOP: 206pt; WIDTH: 74pt; Z-INDEX: 6"" width=99 >" & $CRLF
   s += "  <IMG height=26 id=shoes3 src=""" & bstrExePath & "shoes3.gif"" style=""HEIGHT: 20pt; LEFT: 335pt; POSITION: absolute; TOP: 231pt; WIDTH: 79pt; Z-INDEX: 5"" width=105 >" & $CRLF
   s += "  <IMG height=42 id=hands1 src=""" & bstrExePath & "hands1.gif"" style=""HEIGHT: 32pt; LEFT: 153.72pt; POSITION: absolute; TOP: 171pt; WIDTH: 119pt; Z-INDEX: 4"" width=159 >" & $CRLF
   s += "  <IMG height=34 id=hands3 src=""" & bstrExePath & "hands3.gif"" style=""HEIGHT: 26pt; LEFT: 158.976pt; POSITION: absolute; TOP: 90.72pt; WIDTH: 141pt; Z-INDEX: 3"" width=188 >" & $CRLF
   s += "</DIV>" & $CRLF
   s += "</BODY>" & $CRLF
   s += "</HTML>"

   ' // Create the control
   LOCAL nWide, nHigh AS LONG
   DIALOG GET CLIENT hDlg TO nWide, nHigh
   hCtl = pWindow.AddWebBrowserControl(hDlg, %IDC_WEBBROWSER, s, NOTHING, 0, 0, nWide, nHigh)

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
