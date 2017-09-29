' ########################################################################################
' Adapted from the following Microsoft Knowledge Base article: http://support.microsoft.com/kb/249232
' Demonstrates how to get the IHTMLDocument2 interface from a HWND. If Microsoft Active
' Accessibility (MSAA) is installed, you can send the WM_HTML_GETOBJECT message to the
' document's window (with the window class "Internet Explorer_Server") and then pass the
' result from SendMessageTimeout to an MSAA function, ObjectFromLresult, to get a fully
' marshaled IHTMLDocument2 pointer.
' ########################################################################################

#COMPILE EXE
#DIM ALL
#INCLUDE "OLEACC.INC"   ' // Accessibility
#INCLUDE "EXDISP.INC"   ' // WebBrowser Control
#INCLUDE "MSHTML.INC"   ' // MSHTML

' ========================================================================================
' Callback for EnumChildWindows
' ========================================================================================
FUNCTION EnumChildProc(BYVAL hwnd AS DWORD, BYVAL lParam AS DWORD PTR) AS LONG
   LOCAL szClassName AS ASCIIZ * %MAX_PATH
   GetClassName (hwnd, szClassName, %MAX_PATH)
   IF szClassName = "Internet Explorer_Server" THEN
      IF lParam <> %NULL THEN @lParam = hWnd
      FUNCTION = %FALSE
   ELSE
      FUNCTION = %TRUE
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN () AS LONG

   LOCAL hr AS LONG                              ' // HRESULT
   LOCAL hWndExplorer AS DWORD                   ' // Internet Explorer handle
   LOCAL hWndChild AS DWORD                      ' // Child window handle
   LOCAL dwMsg AS DWORD                          ' // Message to send
   LOCAL lRes AS DWORD                           ' // Result of the message processing
   LOCAL pIHTMLDocument2 AS IHTMLDocument2       ' // IHTMLDocument2 interface pointer

   ' Find the window handle of a running instance of Internet Explorer
   hWndExplorer = FindWindow("IEFrame", BYVAL %NULL)
   IF ISFALSE hWndExplorer THEN
      ? "Internet Explorer isn't running"
      EXIT FUNCTION
   END IF
   ' Enumerate its child windows
   EnumChildWindows hWndExplorer, CODEPTR(EnumChildProc), VARPTR(hWndChild)
   IF ISFALSE hWndChild THEN EXIT FUNCTION
   ' Register the WM_HTML_GETOBJECT message
   dwMsg = RegisterWindowMessage("WM_HTML_GETOBJECT")
   IF ISFALSE dwMsg THEN EXIT FUNCTION
   ' Send a mensage to get an LRESULT
   SendMessageTimeout hWndChild, dwMsg, 0, 0, %SMTO_ABORTIFHUNG, 1000, lRes
   IF ISFALSE lRes THEN EXIT FUNCTION
   ' Retrieve a reference to the IHTMLDocument2 interface from the LRESULT
   hr = ObjectFromLresult(lRes, $IID_IHTMLDocument2, 0, pIHTMLDocument2)
   IF ISNOTHING(pIHTMLDocument2) THEN EXIT FUNCTION
   ' Change the background color of the document to red
   pIHTMLDocument2.bgColor = "red"
   ' Cleanup
   pIHTMLDocument2 = NOTHING
   ? "Web page background color changed to red"
   #IF %DEF(%PB_CC32)
   WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
