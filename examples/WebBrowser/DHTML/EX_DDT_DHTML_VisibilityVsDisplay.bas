' ========================================================================================
' Visibility versus display
' There are two attributes in CSS to hide and show data: the display and visibility
' attributes. The visibility attribute allows content to be hidden, with the content still
' taking up space in the flow. The display attribute allows the content to be removed from
' the flow, allowing creation of dynamic and interactive content, such as outlines. Both
' attributes are supported by Dynamic HTML in Microsoft® Internet Explorer.
' This example demonstrates the difference between dynamically changing the visibility and
' changing the display of CSS attributes.
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
   DIALOG NEW PIXELS, 0, "DHTML: Visibility Versus Display", , , 750, 450, %WS_OVERLAPPEDWINDOW TO hDlg

   LOCAL s AS WSTRING
   ' // Prefix with "MSHTL:"
   s  = "MSHTML:" & $CRLF
   s += "<HTML>" & $CRLF
   s += "<HEAD>" & $CRLF
   s += "<TITLE>MSDN Online Samples:  Visibility Versus Display</TITLE>" & $CRLF
   s += "<META NAME=""FILENAME"" CONTENT=""visibility.HTM"">" & $CRLF
   s += "<META HTTP-EQUIV=""MSThemeCompatible"" CONTENT=""Yes"">" & $CRLF
   s += "<STYLE>" & $CRLF
   s += "  .bigChange {color:blue; font-weight:bolder; font-size:175%; letter-spacing:4px;  text-transform: uppercase; background:yellow}" & $CRLF
   s += "  .start {color:yellow; background:navy}" & $CRLF
   s += "  A:link { color:#003399; text-decoration:none; }" & $CRLF
   s += "  A:visited { color:#6699CC; text-decoration:none; }" & $CRLF
   s += "  A:hover { text-decoration:underline; }" & $CRLF
   s += "</STYLE>" & $CRLF
   s += "<SCRIPT LANGUAGE=""VBScript"">" & $CRLF
   s += "sub highlightButton(s)" & $CRLF
   s += "  if (""INPUT"" = window.event.srcElement.tagName) then" & $CRLF
   s += "     window.event.srcElement.className = s" & $CRLF
   s += "  end if" & $CRLF
   s += "end sub" & $CRLF
   s += "sub makevisible()" & $CRLF
   s += "  if document.all.v.style.visibility = ""hidden"" then" & $CRLF
   s += "     document.all.v.style.visibility = """"" & $CRLF
   s += "  else" & $CRLF
   s += "     document.all.v.style.visibility = ""hidden""" & $CRLF
   s += "  end if" & $CRLF
   s += "end sub" & $CRLF
   s += "sub makedisplayed()" & $CRLF
   s += "  if document.all.d.style.display = ""none"" then" & $CRLF
   s += "     document.all.d.style.display = """"" & $CRLF
   s += "  else" & $CRLF
   s += "     document.all.d.style.display = ""none""" & $CRLF
   s += "  end if" & $CRLF
   s += "end sub" & $CRLF
   s += "</SCRIPT>" & $CRLF
   s += "</HEAD>" & $CRLF
   s += "<BODY SCROLL=""auto"" TOPMARGIN=20 LEFTMARGIN=40 BGCOLOR=""#FFFFFF"" LINK=""#000066"" VLINK=""#666666"" TEXT=""#000000"">" & $CRLF
   s += "<!--TOOLBAR_START-->" & $CRLF
   s += "<!--TOOLBAR_EXEMPT-->" & $CRLF
   s += "<!--TOOLBAR_END-->" & $CRLF
   s += "<H2>Visibility Versus Display</H2>" & $CRLF
   s += "<HR>" & $CRLF
   s += "<P>" & $CRLF
   s += "<P>" & $CRLF
   s += "<FONT FACE=""verdana,arial,helvetica"" SIZE=2>" & $CRLF
   s += "<B>Click on the blue text below. Notice the difference between visibility and display.</B>" & $CRLF
   s += "<P>" & $CRLF
   s += "  <TABLE><TR><TH>Visibility</TH><TH>Display</TD></TR>" & $CRLF
   s += "  <TBODY VALIGN=TOP>" & $CRLF
   s += "    <TR><TD width=50%><P style=""color:blue"" onclick=""makevisible()"">Click here to see more data:</P>" & $CRLF
   s += "         <P id=v style=""visibility:hidden"">This is <EM>sample data</EM> made visible. The space for this content is already taken up, even though the content is initially invisible.</P>" & $CRLF
   s += "         <P>Here is more information that follows the hidden data.</P>" & $CRLF
   s += "        </TD>" & $CRLF
   s += "        <TD width=50%><P style=""color:blue"" onclick=""makedisplayed()"" title=""A tooltip can even be added to every element using the title attribute!"">Click here to see more data:</P>" & $CRLF
   s += "         <P id=d style=""display:none"">This is <EM>sample data</EM> that is being displayed. The space for this content is not taken up until the content is displayed." & $CRLF
   s += "            Notice how the line following this data automatically moves down.</P>" & $CRLF
   s += "         <P>Here is more information that follows the hidden data.</P><P>" & $CRLF
   s += "        </TD>" & $CRLF
   s += "   </TR>" & $CRLF
   s += "  </TBODY>" & $CRLF
   s += " </TABLE>" & $CRLF
   s += "  <P>There are two attributes in CSS to hide and show data: the <b>display</b> and <b>visibility</b> attributes. The visibility attribute allows content to be hidden, with the content still taking up space in the flow. " & _
               "The display attribute allows the content to be removed from the flow, allowing creation of dynamic and interactive content, such as outlines. Both attributes are supported by Dynamic HTML in Microsoft® Internet Explorer 4 and higher. " & _
               "This example demonstrates the difference between dynamically changing the visibility and changing the display of CSS attributes." & $CRLF
   s += "<P>" & $CRLF
   s += "<HR>" & $CRLF
   s += "<P>" & $CRLF
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
