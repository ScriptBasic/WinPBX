#COMPILE EXE
#DIM ALL
%UNICODE = 1

' // Include files for external files
%USEOLECON = 1                ' // Use the OLE container
#INCLUDE ONCE "CWindow.inc"   ' // CWindow class
#INCLUDE ONCE "MSHTML.INC"    ' // MSHTML

' // Identifier
%IDC_WEBBROWSER = 101

' ########################################################################################
' Main
' ########################################################################################
FUNCTION WinMain (BYVAL hInstance AS DWORD, BYVAL hPrevInstance AS DWORD, BYVAL lpszCmdLine AS WSTRINGZ PTR, BYVAL nCmdShow AS LONG) AS LONG

   ' // Set process DPI aware
   AfxSetProcessDPIAware

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' // Create the main window
   DIM hwndMain AS DWORD
   hwndMain = pWindow.CreateWindow(%NULL, "Web GUI", 0, 0, 0, 0, %WS_POPUPWINDOW OR %WS_CAPTION, 0, CODEPTR(WindowProc))
   ' // Set the client size
   pWindow.SetClientSize 400, 200
   ' // Center the window
   pWindow.CenterWindow

   DIM s AS WSTRING
   s +="<!DOCTYPE html>" & $CRLF
   s +="    <html>" & $CRLF
   s += "<meta http-equiv='MSThemeCompatible' content='Yes'>" & $CRLF
   s +="    <body scroll='auto'>" & $CRLF
   s +="    <script>"& $CRLF
   s +="      function random() {"& $CRLF
   s +="      var x = Math.random()*10;"& $CRLF
   s +="      x=parseInt(x+0.5);"& $CRLF
   s +="      document.getElementById('test').value = x;"& $CRLF
   s +="     }"& $CRLF
   s +="    </script>"& $CRLF
   s +="    <input type='button' id='random button' name='button' value='random nr' onClick='random()'>"& $CRLF
   s +="    <input type='text'   id='test'          name='result' value=''>"& $CRLF
   s +="    </body>"& $CRLF
   s +="    </html>"& $CRLF

   ' // Add a WebBrowser control
   DIM hCtl AS DWORD
   hCtl = pWindow.AddControl($OC_CLASSNAME, hwndMain, %IDC_WEBBROWSER, "Shell.Explorer", _
          0, 0, pWindow.ClientWidth, pWindow.ClientHeight, -1)

   LOCAL pIWebBrowser2  AS IWebBrowser2
   LOCAL pHTMLDocument2 AS IHTMLDocument2
   LOCAL pWBEvents      AS DWebBrowserEvents2Impl

   ' // Get the IDispatch of the control
   pIWebBrowser2 = OC_GetDispatch(hCtl)
   IF ISOBJECT(pIWebBrowser2) THEN
      ' Connect to the events fired by the control
      pWBEvents = CLASS "CDWebBrowserEvents2"
      EVENTS FROM pIWebBrowser2 CALL pWBEvents
      ' Navigate to a blank page
      DIM vUrl AS VARIANT
      vUrl = "about:blank"
      pIWebBrowser2.Navigate2(vUrl)
      ' Get a reference to the IHTMLDocument2 interface
      pHTMLDocument2 = pIWebBrowser2.Document
      IF ISOBJECT(pHTMLDocument2) THEN
         IHTMLDocument2_WriteString(pHTMLDocument2, s)
         pHTMLDocument2.close
         pHTMLDocument2 = NOTHING
      END IF
      ' Release the interface
      pIWebBrowser2 = NOTHING
   END IF
   SetFocus hCtl

   ' // Default message pump (you can replace it with your own)
   FUNCTION = pWindow.DoEvents(nCmdShow)

   ' // Disconnect events and quit
   IF ISOBJECT(pWBEvents) THEN EVENTS END pWBEvents

END FUNCTION
' ########################################################################################

' ========================================================================================
' Main callback function.
' ========================================================================================
FUNCTION WindowProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   STATIC pWindow AS IWindow        ' // Reference to the IWindow interface

   SELECT CASE uMsg

      CASE %WM_SYSCOMMAND
         ' // Capture this message and send a WM_CLOSE message
         ' // Note: Needed with some OCXs, that otherwise remain in memory
         IF (wParam AND &HFFF0) = %SC_CLOSE THEN
            SendMessage hwnd, %WM_CLOSE, 0, 0
            EXIT FUNCTION
         END IF

      CASE %WM_COMMAND
         SELECT CASE LO(WORD, wParam)
            CASE %IDCANCEL
               ' // If the Escape key has been pressed...
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  ' // ... close the application by sending a WM_CLOSE message
                  SendMessage hwnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT

      CASE %WM_DESTROY
         ' // End the application
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   ' // Pass unprocessed messages to Windows
   FUNCTION = DefWindowProc(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ########################################################################################
' Class CDWebBrowserEvents2
' Interface name = DWebBrowserEvents2
' IID = {34A715A0-6587-11D0-924A-0020AFC7AC4D}
' Web Browser Control events interface
' Attributes = 4112 [&H1010] [Hidden] [Dispatchable]
' ########################################################################################

CLASS CDWebBrowserEvents2 GUID$("{700B73A2-CCFC-4FE0-B9AC-D5853D71B7B9}") AS EVENT

   INSTANCE pIWebBrowser2 AS IWebBrowser2
   INSTANCE pHTMLDocumentEvents2 AS HTMLDocumentEvents2Impl
INSTANCE url AS WSTRING

   ' =====================================================================================
   CLASS METHOD Destroy
      ' Disconnect events
      IF ISOBJECT(pHTMLDocumentEvents2) THEN EVENTS END pHTMLDocumentEvents2
   END METHOD
   ' =====================================================================================

' ========================================================================================
' Implementation of the interface
' ========================================================================================
INTERFACE DWebBrowserEvents2Impl GUID$("{34A715A0-6587-11D0-924A-0020AFC7AC4D}") AS EVENT

  INHERIT IDispatch

   ' =====================================================================================
   ' Note  It would be more appropriate to use the DocumentComplete event, but this
   ' event isn't fired. See: BUG: DocumentComplete Does Not Fire When WebBrowser Is Not Visible
   ' http://support.microsoft.com/kb/q259935/
   ' =====================================================================================
   METHOD DownloadComplete <104>

      ' Get a reference to the IHTMLDocument2 interface
      LOCAL pHTMLDocument2 AS IHTMLDocument2
      pHTMLDocument2 = pIWebBrowser2.Document
      IF ISNOTHING(pHTMLDocument2) THEN EXIT METHOD
      ' Connect to the events fired by the page
      pHTMLDocumentEvents2 = CLASS "CHTMLDocumentEvents2"
      IF ISNOTHING(pHTMLDocumentEvents2) THEN EXIT METHOD
      EVENTS FROM pHTMLDocument2 CALL pHTMLDocumentEvents2
    MSGBOX "END OF METHOD 'DOWNLOAD COMPLETE'" & url

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD BeforeNavigate2 <250> ( _
     BYVAL pDisp AS IDispatch _                         ' __in IDispatch* pDisp
   , BYREF vURL AS VARIANT _                            ' __in VARIANT* URL
   , BYREF vFlags AS VARIANT _                          ' __in VARIANT* Flags
   , BYREF vTargetFrameName AS VARIANT _                ' __in VARIANT* TargetFrameName
   , BYREF vPostData AS VARIANT _                       ' __in VARIANT* PostData
   , BYREF vHeaders AS VARIANT _                        ' __in VARIANT* Headers
   , BYREF bCancel AS INTEGER _                         ' __in_out VARIANT_BOOL* Cancel
   )                                                    ' void

      ' Get a reference to the WebBrowser control
      IF ISNOTHING(pIWebBrowser2) THEN pIWebBrowser2 = pDisp
      IF ISNOTHING(pIWebBrowser2) THEN EXIT METHOD
      ' If there was a previous loaded page, disconnect from the events
      IF ISOBJECT(pHTMLDocumentEvents2) THEN
         EVENTS END pHTMLDocumentEvents2
         pHTMLDocumentEvents2 = NOTHING
      END IF
url = VARIANT$(vUrl)
      MSGBOX "END OF METHOD 'BEFORE NAVIGATE' " & url

   END METHOD
   ' =====================================================================================

END INTERFACE

END CLASS
' ########################################################################################

' ########################################################################################
' Class CHTMLDocumentEvents2
' Interface name = HTMLDocumentEvents2
' IID = {3050F613-98B5-11CF-BB82-00AA00BDCE0B}
' Attributes = 4112 [&H1010] [Hidden] [Dispatchable]
' ########################################################################################

CLASS CHTMLDocumentEvents2 GUID$("{1FFB0071-8BCC-4BBD-BC29-A662FAE87C82}") AS EVENT

INTERFACE HTMLDocumentEvents2Impl GUID$("{3050F613-98B5-11CF-BB82-00AA00BDCE0B}") AS EVENT

  INHERIT IDispatch

   ' =====================================================================================
   METHOD onclick <-600> ( _
     BYVAL pEvtObj AS IHTMLEventObj _                   ' __in IHTMLEventObj* pEvtObj
   )                                                    ' void

      LOCAL pElement AS IHTMLElement           ' // Element that has fired the event
      LOCAL pHTMLDocument2 AS IHTMLDocument2   ' // Document object
      LOCAL bstrId AS WSTRING                  ' // Identifier of the element that has fired the event
      LOCAL bstrValue AS WSTRING               ' // Value of the property

      ' // Get a reference to the element that has fired the event
      IF ISOBJECT(pEvtObj) THEN pElement = pEvtObj.srcElement
      IF ISNOTHING(pElement) THEN EXIT METHOD

      ' // Get a reference to the IHTMLDocument2 interface
      pHTMLDocument2 = pElement.document
      IF ISNOTHING(pHTMLDocument2) THEN EXIT METHOD

      ' // Get the identifier of the element that has fired the event
      bstrId = pElement.id

      SELECT CASE bstrId
         CASE "random button"
            bstrValue = IHTMLDocument_getElementValueById(pHTMLDocument2, "test")
            MSGBOX "Clicked on button Webbrowser. Value=" & bstrValue
      END SELECT

   END METHOD
   ' =====================================================================================

END INTERFACE

END CLASS
' ########################################################################################
