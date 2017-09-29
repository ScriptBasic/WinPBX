' ########################################################################################
' Demonstrates how to get the IWebBrowser2 interface from a HWND. If Microsoft Active
' Accessibility (MSAA) is installed, you can send the WM_HTML_GETOBJECT message to the
' document's window (with the window class "Internet Explorer_Server") and then pass the
' result from SendMessageTimeout to an MSAA function, ObjectFromLresult, to get a fully
' marshaled IHTMLDocument2 pointer. Then you will call the parentWindow property of the
' IHTMLDocument2 interface to retrieve a reference to the IHTMLWindow2 interface and call
' the QueryInterface method to retrieve a reference to the IServiceProvider interface.
' Finally, you will call the QueryService method of the IServiceProvider interface to
' retrieve a reference to the IWebBrowser2 interface.
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
   LOCAL pIWebBrowser2 AS IWebBrowser2           ' // IWebBrowser2 interface pointer
   LOCAL pIHTMLDocument2 AS IHTMLDocument2       ' // IHTMLDocument2 interface pointer
   LOCAL pIHTMLWindow2 AS IHTMLWindow2           ' // IHTMLWindow2 interface pointer
   LOCAL pIServiceProvider AS IServiceProvider   ' // IServiceProvider interface pointer

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
   ' Get a reference to the IHTMLWindow2 interface for the parent window
   pIHTMLWindow2 = pIHTMLDocument2.parentWindow
   IF ISNOTHING(pIHTMLWindow2) THEN EXIT FUNCTION
   ' Retrieve a reference to the IServiceProvider interface
   pIServiceProvider = pIHTMLWindow2
   IF ISNOTHING(pIServiceProvider) THEN EXIT FUNCTION
   ' Retrieve a reference to the IWebBrowser2 interface
   pIServiceProvider.QueryService($IID_IWebBrowserApp, $IID_IWebBrowser2, pIWebBrowser2)
   IF ISNOTHING(pIWebBrowser2) THEN EXIT FUNCTION
   ' ==========================================================================
   ' Now you can call the methods and properties of the IWebBrowser2 interface.
   ' ==========================================================================
   ? "pIWebBrowser2 = " & STR$(OBJPTR(pIWebBrowser2))

   #IF %DEF(%PB_CC32)
   WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================