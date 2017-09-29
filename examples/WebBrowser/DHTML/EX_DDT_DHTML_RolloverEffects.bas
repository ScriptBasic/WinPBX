' ========================================================================================
' Rollover effects
' In this example, there are seven SPAN elements initially set to use the class Item.
' When the mouse pointer moves over any one of these elements, the element will be changed
' to use the class Highlight.
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

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' // Create the dialog
   LOCAL hDlg AS DWORD
   DIALOG NEW PIXELS, 0, "DHTML: Rollover eEffects", , , 750, 450, %WS_OVERLAPPEDWINDOW TO hDlg

   LOCAL s AS WSTRING
   ' // Prefix with "MSHTL:"
   s  = "MSHTML:" & $CRLF
   s += "<HEAD>" & $CRLF
   s += "<TITLE>MSDN Online Samples:  Rollover Effects</TITLE>" & $CRLF
   s += "<META NAME=""FILENAME"" CONTENT=""rollover.HTM"">" & $CRLF
   s += "<META HTTP-EQUIV=""MSThemeCompatible"" CONTENT=""Yes"">" & $CRLF
   s += "<STYLE>" & $CRLF
   s += ".Item {" & $CRLF
   s += "   cursor: hand;" & $CRLF
   s += "   font-family: verdana;" & $CRLF
   s += "   font-size: 20;" & $CRLF
   s += "   font-style: normal;" & $CRLF
   s += "   background-color: blue;" & $CRLF
   s += "   color: white" & $CRLF
   s += " }" & $CRLF
   s += ".Highlight {" & $CRLF
   s += "   cursor: hand;" & $CRLF
   s += "   font-family: verdana;" & $CRLF
   s += "   font-size: 20;" & $CRLF
   s += "   font-style: italic;" & $CRLF
   s += "   background-color: white;" & $CRLF
   s += "   color: blue" & $CRLF
   s += " }" & $CRLF
   s += "A:link { color:#003399; text-decoration:none; }" & $CRLF
   s += "A:visited { color:#6699CC; text-decoration:none; }" & $CRLF
   s += "A:hover { text-decoration:underline; }" & $CRLF
   s += "</STYLE>" & $CRLF
   s += "</HEAD>" & $CRLF
   s += "<BODY SCROLL=""auto"" TOPMARGIN=20 LEFTMARGIN=40 bgcolor=""#ffffff"" LINK=""#000066"" VLINK=""#666666"" TEXT=""#000000"">" & $CRLF
   s += "<!--TOOLBAR_START-->" & $CRLF
   s += "<!--TOOLBAR_EXEMPT-->" & $CRLF
   s += "<!--TOOLBAR_END-->" & $CRLF
   s += "<H2>Rollover Effects</H2>" & $CRLF
   s += "<HR>" & $CRLF
   s += "<BR>" & $CRLF
   s += "<DIV id=Rollover><P>" & $CRLF
   s += "<FONT FACE=""verdana,arial,helvetica"" SIZE=2>" & $CRLF
   s += "<B>Move the cursor over any of the seven elements to change their style.</B>" & $CRLF
   s += "</FONT>" & $CRLF
   s += "<P>" & $CRLF
   s += "<SPAN class=Item>Milk</SPAN>" & $CRLF
   s += "<SPAN class=Item>Cookies</SPAN>" & $CRLF
   s += "<SPAN class=Item>Eggs</SPAN>" & $CRLF
   s += "<SPAN class=Item>Ham</SPAN>" & $CRLF
   s += "<SPAN class=Item>Cheese</SPAN>" & $CRLF
   s += "<SPAN class=Item>Pasta</SPAN>" & $CRLF
   s += "<SPAN class=Item>Chicken</SPAN></P>" & $CRLF
   s += "</DIV>" & $CRLF
   s += "<BR>" & $CRLF
   s += "<P> " & $CRLF
   s += "<FONT FACE=""verdana,arial,helvetica"" SIZE=2>" & $CRLF
   s += "In this example, there are seven SPAN elements initially set to use the class Item. " & $CRLF
   s += "When the mouse pointer moves over any one of these elements, the element will be changed to use the " & $CRLF
   s += "class Highlight. Innovations in Microsoft® Internet Explorer 4.0 enable the following functionality: " & $CRLF
   s += "<UL>" & $CRLF
   s += "  <LI>Events can now be generated from a SPAN element. " & $CRLF
   s += "  Previously, an HTML author would have had to wrap each SPAN element in an anchor to " & $CRLF
   s += "  get the right events.</LI> " & $CRLF
   s += "  <LI>With event bubbling, events can be captured at the " & $CRLF
   s += "  document level. You do not need to create separate event " & $CRLF
   s += "  handlers for each element that will participate in the effect.</LI>" & $CRLF
   s += "</UL>" & $CRLF
   s += "</FONT>" & $CRLF
   s += "<SCRIPT LANGUAGE=""VBScript"">" & $CRLF
   s += "sub Rollover_onmouseover()" & $CRLF
   s += "  if (window.event.srcElement.className = ""Item"") then" & $CRLF
   s += "     window.event.srcElement.className = ""Highlight""" & $CRLF
   s += "  end if" & $CRLF
   s += "end sub" & $CRLF
   s += "sub Rollover_onmouseout()" & $CRLF
   s += "  if (window.event.srcElement.className = ""Highlight"") then" & $CRLF
   s += "     window.event.srcElement.className = ""Item""" & $CRLF
   s += "  end if" & $CRLF
   s += "end sub" & $CRLF
   s += "</SCRIPT>" & $CRLF
   s += "<P>" & $CRLF
   s += "<P>" & $CRLF
   s += "<P>" & $CRLF
   s += "<HR>" & $CRLF
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
