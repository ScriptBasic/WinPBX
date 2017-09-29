' ========================================================================================
' Resize graphic
' This sample lets users replace a small graphic with a larger graphic. Text surrounding
' the graphic re-flows automatically.
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
   DIALOG NEW PIXELS, 0, "DHTML: Ressize Graphic", , , 750, 450, %WS_OVERLAPPEDWINDOW TO hDlg

   LOCAL s AS WSTRING
   LOCAL bstrExePath AS STRING

   bstrExePath = EXE.Path$
   REPLACE "\" WITH "/" IN bstrExePath

   ' // Prefix with "MSHTL:"
   s  = "MSHTML:<HTML>" & $CRLF
   s += "<HEAD>" & $CRLF
   s += "<TITLE>Resize Graphic</TITLE>" & $CRLF
   s += "<META HTTP-EQUIV='MSThemeCompatible' CONTENT='Yes'>" & $CRLF
   s += "<STYLE>" & $CRLF
   s += "  A:link { color:#003399; text-decoration:none; }" & $CRLF
   s += "  A:visited { color:#6699CC; text-decoration:none; }" & $CRLF
   s += "  A:hover { text-decoration:underline; }" & $CRLF
   s += "</STYLE>" & $CRLF
   s += "</HEAD>" & $CRLF
   s += "<BODY SCROLL=""auto"" TOPMARGIN=""20"" LEFTMARGIN=""40"" bgcolor=""#FFFFFF"" LINK=""#000066"" VLINK=""#666666"" TEXT=""#000000"">" & $CRLF
   s += "<!--TOOLBAR_START-->" & $CRLF
   s += "<!--TOOLBAR_EXEMPT-->" & $CRLF
   s += "<!--TOOLBAR_END-->" & $CRLF
   s += "<H2>Resize Graphic</H2>" & $CRLF
   s += "<HR>" & $CRLF
   s += "<P>" & $CRLF
   s += "<P>" & $CRLF
   s += "<P>" & $CRLF
   s += "<FONT FACE=""verdana,arial,helvetica"" SIZE=2><b>To run this sample, move the mouse pointer over the graphic.</b></FONT>" & $CRLF
   s += "<P>" & $CRLF
   s += "<FONT FACE=""verdana,arial,helvetica"" SIZE=2>" & $CRLF
   s += "The final releases of Microsoft® Internet Explorer 4 and 5 include Dynamic HTML, the next generation of HTML that moves beyond static" & $CRLF
   s += "<A href onmouseover=""img2.src = '" & bstrExePath & "ie_lg.gif';"" onmouseout=""img2.src = '" & bstrExePath & "ie_sm.gif';"">" & $CRLF
   s += "<IMG border=""0"" name=""img2"" src=""" & bstrExePath & "ie_sm.gif"" align=""left"" hspace=""0""></A>" & $CRLF
   s += "text and graphic images to interactive Web pages and live business applications." & $CRLF
   s += "In addition to making Web page design easier and more precise," & $CRLF
   s += "Dynamic HTML enriches the Web experience by allowing users to" & $CRLF
   s += "interact with multimedia content. A key criterion of an interactive Web page is that page elements " & $CRLF
   s += "readjust automatically if a graphic is resized, as this sample demonstrates." & $CRLF
   s += "</FONT>" & $CRLF
   s += "<P>" & $CRLF
   s += "<FONT FACE=""verdana,arial,helvetica"" SIZE=2>" & $CRLF
   s += "This sample lets users replace a small graphic with a larger " & $CRLF
   s += "graphic. Text surrounding the graphic re-flows automatically." & $CRLF
   s += "</FONT>" & $CRLF
   s += "<P>" & $CRLF
   s += "<P>" & $CRLF
   s += "<P>" & $CRLF
   s += "<HR>" & $CRLF
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
