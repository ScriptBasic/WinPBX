' ========================================================================================
' Outline
' This example shows how to build an interactive outline that expands and collapses.
' Click closed folders to open them, and click open folders to close them. The items
' automatically expand and collapse.
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
   DIALOG NEW PIXELS, 0, "DHTML: Outline", , , 750, 450, %WS_OVERLAPPEDWINDOW TO hDlg

   LOCAL s AS WSTRING
   LOCAL bstrExePath AS STRING

   bstrExePath = EXE.Path$
   REPLACE "\" WITH "/" IN bstrExePath

   s  = "MSHTML:<HTML>" & $CRLF
   s += "<HEAD>" & $CRLF
   s += "<TITLE>MSDN Online Samples:  Outline</TITLE>" & $CRLF
   s += "<META NAME=""FILENAME"" CONTENT=""outline_VBS.HTM"">" & $CRLF
   s += "<META HTTP-EQUIV=""MSThemeCompatible"" CONTENT=""Yes"">" & $CRLF
   s += "<STYLE>" & $CRLF
   s += "  A:link { color:#003399; text-decoration:none; }" & $CRLF
   s += "  A:visited { color:#6699CC; text-decoration:none; }" & $CRLF
   s += "  A:hover { text-decoration:underline; }" & $CRLF
   s += "</STYLE>" & $CRLF
   s += "</HEAD>" & $CRLF
   s += "<BODY SCROLL=""auto"" TOPMARGIN=20 LEFTMARGIN=40 BGCOLOR=""#FFFFFF"" LINK=""#000066"" VLINK=""#666666"" TEXT=""#000000"">" & $CRLF
   s += "<!--TOOLBAR_START-->" & $CRLF
   s += "<!--TOOLBAR_EXEMPT-->" & $CRLF
   s += "<!--TOOLBAR_END-->" & $CRLF
   s += "<H2>Outline</H2>" & $CRLF
   s += "<HR>" & $CRLF
   s += "<P>" & $CRLF
   s += "<P>" & $CRLF
   s += "<FONT FACE=""Verdana, Arial, Helvetica"" SIZE=""4""><B>Use the mouse to expand the outline!</B></FONT>" & $CRLF
   s += "<BR><BR>" & $CRLF
   s += "<DIV ID=""Out0"">" & $CRLF
   s += "  <IMG SRC=""" & bstrExePath & "folder.gif"" ID=""Out1"" CLASS=""Outline"" STYLE=""cursor: hand"" WIDTH=""16"" HEIGHT=""16""> Item 1<BR>" & $CRLF
   s += "  <DIV ID=""Out1d"" STYLE=""display:None"">" & $CRLF
   s += "      <IMG SRC=""" & bstrExePath & "folder.gif"" ID=""Out2"" CLASS=""Outline"" STYLE=""cursor: hand"" WIDTH=""16"" HEIGHT=""16""> Item 1.1<BR>" & $CRLF
   s += "    <DIV ID=""Out2d"" STYLE=""display:None"">" & $CRLF
   s += "           <IMG SRC=""" & bstrExePath & "60-60-60.gif"" WIDTH=""20"" HEIGHT=""15""> Item 1.1.1<BR>" & $CRLF
   s += "           <IMG SRC=""" & bstrExePath & "60-60-60.gif"" WIDTH=""20"" HEIGHT=""15""> Item 1.1.2<BR>" & $CRLF
   s += "    </DIV>" & $CRLF
   s += "      <IMG SRC=""" & bstrExePath & "60-60-60.gif"" WIDTH=""20"" HEIGHT=""15""> Item 1.2<BR>" & $CRLF
   s += "  </DIV>" & $CRLF
   s += "  <IMG SRC=""" & bstrExePath & "60-60-60.gif"" WIDTH=""20"" HEIGHT=""15""> Item 2<BR>" & $CRLF
   s += "</DIV>" & $CRLF
   s += "<SCRIPT LANGUAGE=""VBScript"">" & $CRLF
   s += "sub document_onClick " & $CRLF
   s += "  dim targetId, srcElement, targetElement" & $CRLF
   s += "  set srcElement = window.event.srcElement" & $CRLF
   s += "  if (srcElement.className = ""Outline"") then" & $CRLF
   s += "     targetId = srcElement.id & ""d""" & $CRLF
   s += "     set targetElement = document.all(targetId)" & $CRLF
   s += "     if (targetElement.style.display = ""none"") then" & $CRLF
   s += "        targetElement.style.display = """"" & $CRLF
   s += "        srcElement.src = """ & bstrExePath & "ofolder.gif""" & $CRLF
   s += "     else" & $CRLF
   s += "        targetElement.style.display = ""none""" & $CRLF
   s += "        srcElement.src = """ & bstrExePath & "folder.gif""" & $CRLF
   s += "     end if" & $CRLF
   s += "  end if" & $CRLF
   s += "end sub" & $CRLF
   s += "</SCRIPT>" & $CRLF
   s += "<HR>" & $CRLF
   s += "<TABLE CELLPADDING=""0"" CELLSPACING=""0"" BORDER=""0"">" & $CRLF
   s += "  <TR>" & $CRLF
   s += "    <TD ALIGN=""LEFT"" VALIGN=""TOP"" COLSPAN=""2""><FONT FACE=""Verdana, Arial, Helvetica"" SIZE=""2""><B>Description</B></FONT></TD>" & $CRLF
   s += "  </TR>" & $CRLF
   s += "  <TR>" & $CRLF
   s += "    <TD ALIGN=""LEFT"" VALIGN=""TOP"" COLSPAN=""2""><FONT FACE=""Verdana, Arial, Helvetica"" SIZE=""2"">" & _ & $CRLF
          "This example shows how to build an interactive outline that expands and collapses. Click closed folders to open them, and click open folders to close them. The items automatically expand and collapse.</FONT>" & $CRLF
   s += "<P>" & $CRLF
   s += "      <FONT FACE=""Verdana, Arial, Helvetica"" SIZE=""2"">" & $CRLF
   s += "        No matter how many items you would like to include in your outline, or what those items contain, the code to collapse and expand items does not need to change. A simple naming convention allows this consistency. " & _
                   "In the example above, all of the images that are used to control the collapsing and expanding of elements are given the class ""Outline."" The element that will be hidden or shown when its associated image is clicked has " & _
                   "a name consisting of the ID of its associated images, followed by a ""d."" For example, if the Image ID is ""image 1,"" the outline element will have an ID of ""image1d."" When a click occurs, the code checks to see if the " & _
                   "source of the click is an object whose class equals ""Outline."" If so, the code gets the element that has an ID equal to the ID of the clicked image plus ""d."" That element's display status is then toggled." & $CRLF
   s += "      </FONT>" & $CRLF
   s += "</TD>" & $CRLF
   s += "  </TR>" & $CRLF
   s += "  <TR>" & $CRLF
   s += "    <TD ALIGN=""LEFT"" VALIGN=""TOP"" COLSPAN=""2""><P><FONT FACE=""Verdana, Arial, Helvetica"" SIZE=""2""><BR><B>Usage</B></FONT></TD>" & $CRLF
   s += "  </TR>" & $CRLF
   s += "  <TR>" & $CRLF
   s += "    <TD ALIGN=""LEFT"" VALIGN=""TOP"" COLSPAN=""2""><FONT FACE=""Verdana, Arial, Helvetica"" SIZE=""2"">As explained, the code to control the outline need not change based on the contents of the outline. " & _
          "Simply take the script from this page and use the naming convention described previously-you will have instant outlines.</FONT></TD>" & $CRLF
   s += "  </TR>" & $CRLF
   s += "</TABLE>" & $CRLF
   s += "<P>" & $CRLF
   s += "<P>" & $CRLF
   s += "<P>" & $CRLF
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
