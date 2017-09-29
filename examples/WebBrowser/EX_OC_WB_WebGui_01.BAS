' ########################################################################################
' This example demonstrates how to work interactively with a web page loaded in an instance
' of the WebBrowser Control embedded in a PowerBASIC application.
' ########################################################################################

' SED_PBWIN - Use the PBWIN compiler
#COMPILE EXE
#DIM ALL
#INCLUDE ONCE "OLECON.INC"     ' // Ole Container
#INCLUDE ONCE "EXDISP.INC"     ' // WebBrowser Control
%USEHTMLWRAPPERS = 1           ' // Allow the use of the HTML wrappers
#INCLUDE ONCE "MSHTML.INC"     ' // MSHTML
#INCLUDE ONCE "mshtmhst.inc"   ' // MSTHML Advanced Host Interfaces

%IDC_IEWB = 101

' ========================================================================================
' Main
' ========================================================================================
FUNCTION WINMAIN (BYVAL hInstance AS DWORD, BYVAL hPrevInstance AS DWORD, BYVAL lpszCmdLine AS ASCIIZ PTR, BYVAL nCmdShow AS LONG) AS LONG

   LOCAL hWndMain    AS DWORD
   LOCAL hFont       AS DWORD
   LOCAL wcex        AS WNDCLASSEX
   LOCAL szClassName AS ASCIIZ * 80
   LOCAL rc          AS RECT
   LOCAL szCaption   AS ASCIIZ * 255
   LOCAL nLeft       AS LONG
   LOCAL nTop        AS LONG
   LOCAL nWidth      AS LONG
   LOCAL nHeight     AS LONG

   ' Initilize the COM library using OleInitialize to allow cut and paste
   OleInitialize 0

   ' Required: Initialize the Ole Containewr
   OC_WinInit

   hFont = GetStockObject(%ANSI_VAR_FONT)

   ' Register the window class
   szClassName        = "WebBrowser"
   wcex.cbSize        = SIZEOF(wcex)
   wcex.style         = 0 '%CS_HREDRAW OR %CS_VREDRAW
   wcex.lpfnWndProc   = CODEPTR(WndProc)
   wcex.cbClsExtra    = 0
   wcex.cbWndExtra    = 0
   wcex.hInstance     = hInstance
   wcex.hCursor       = LoadCursor (%NULL, BYVAL %IDC_ARROW)
   wcex.hbrBackground = %COLOR_3DFACE + 1
   wcex.lpszMenuName  = %NULL
   wcex.lpszClassName = VARPTR(szClassName)
   wcex.hIcon         = LoadIcon (%NULL, BYVAL %IDI_APPLICATION) ' Sample, if resource icon: LoadIcon(hInst, "APPICON")
   wcex.hIconSm       = LoadIcon (%NULL, BYVAL %IDI_APPLICATION) ' Remember to set small icon too..
   RegisterClassEx wcex

   ' Window caption
   szCaption = "WebBrowser Example: Web Gui"

   ' Retrieve the size of the working area
   SystemParametersInfo %SPI_GETWORKAREA, 0, BYVAL VARPTR(rc), 0

   ' Calculate the position and size of the window
   nWidth  = (((rc.nRight - rc.nLeft)) + 2) * 0.50   ' 50% of the client screen width
   nHeight = (((rc.nBottom - rc.nTop)) + 2) * 0.60   ' 60% of the client screen height
   nLeft   = ((rc.nRight - rc.nLeft) \ 2) - nWidth \ 2
   nTop    = ((rc.nBottom - rc.nTop) \ 2) - (nHeight \ 2)

   ' Create a window using the registered class
   hWndMain = CreateWindowEx(%WS_EX_CONTROLPARENT, _           ' extended style
                             szClassName, _                    ' window class name
                             szCaption, _                      ' window caption
                             %WS_OVERLAPPEDWINDOW OR _
                             %WS_CLIPCHILDREN, _               ' window style
                             nLeft, _                          ' initial x position
                             nTop, _                           ' initial y position
                             nWidth, _                         ' initial x size
                             nHeight, _                        ' initial y size
                             %NULL, _                          ' parent window handle
                             0, _                              ' window menu handle
                             hInstance, _                      ' program instance handle
                             BYVAL %NULL)                      ' creation parameters

   ' Show the window
   ShowWindow hWndMain, nCmdShow
   UpdateWindow hWndMain

   ' Message handler loop
   LOCAL uMsg AS tagMsg
   WHILE GetMessage(uMsg, %NULL, 0, 0)
      IF ISFALSE OC_ForwardMessage(GetFocus, uMsg) THEN
         IF IsDialogMessage(hWndMain, uMsg) = 0 THEN
            TranslateMessage uMsg
            DispatchMessage uMsg
         END IF
      END IF
   WEND

   ' Uninitialize the COM library
   OleUninitialize

   FUNCTION = uMsg.wParam

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main Window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hWnd AS DWORD, BYVAL wMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL  hr             AS LONG
   LOCAL  hCtl           AS DWORD
   LOCAL  rc             AS RECT
   LOCAL  vUrl           AS VARIANT
   LOCAL  s              AS STRING
   LOCAL  pIWebBrowser2  AS IWebBrowser2
   LOCAL  pHTMLDocument2 AS IHTMLDocument2
   STATIC pWBEvents      AS DWebBrowserEvents2Impl

   SELECT CASE wMsg

      CASE %WM_CREATE
         GetClientRect hWnd, rc
         hCtl = CreateWindowEx(0, $OC_CLASSNAME, "Shell.Explorer", %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP, _
                0, 0, 0, 0, hWnd, %IDC_IEWB, GetModuleHandle(""), BYVAL %NULL)
         ' Get the IDispatch of the control
         pIWebBrowser2 = OC_GetDispatch(GetDlgItem(hWnd, %IDC_IEWB))
         IF ISOBJECT(pIWebBrowser2) THEN
            ' Connect to the events fired by the control
            pWBEvents = CLASS "CDWebBrowserEvents2"
            EVENTS FROM pIWebBrowser2 CALL pWBEvents
            ' Navigate to a blank page
            vUrl = "about:blank"
            pIWebBrowser2.Navigate2(vUrl)
            ' Html form
            s = "<html>" & $CRLF
            s = s & "<head>" & $CRLF
            s = s & "<meta http-equiv=""MSThemeCompatible"" content=""Yes"">" & $CRLF
            s = s & "  <title>WebGui</title>" & $CRLF
            s = s & "" & $CRLF
            s = s & "<style type=""text/css"">" & $CRLF
            s = s & "<!--" & $CRLF
            s = s & "" & $CRLF
            s = s & "#output" & $CRLF
            s = s & "{" & $CRLF
            s = s & "background: #FFFFCC;" & $CRLF
            s = s & "border: thin solid black;" & $CRLF
            s = s & "text-align: center;" & $CRLF
            s = s & "width: 300px;" & $CRLF
            s = s & "}" & $CRLF
            s = s & "-->" & $CRLF
            s = s & "</style>" & $CRLF
            s = s & "" & $CRLF
            s = s & "</head>" & $CRLF
            s = s & "<body>" & $CRLF
            s = s & "<input type =""Button"" id=""Button_1"" name=""Button_1"" value=""Button 1""><br />" & $CRLF
            s = s & "<input type =""Button"" id=""Button_2"" name=""Button_2"" value=""Button 2""><br />" & $CRLF
            s = s & "<input type =""Button"" id=""Button_3"" name=""Button_3"" value=""Button 3""><br />" & $CRLF
            s = s & "<input type =""Button"" id=""Button_4"" name=""Button_4"" value=""Button 4""><br />" & $CRLF
            s = s & "<br />" & $CRLF
            s = s & "<div id=""output"">" & $CRLF
            s = s & "Click a button" & $CRLF
            s = s & "</div>" & $CRLF
            s = s & "<br />" & $CRLF
            s = s & "<br />" & $CRLF
            s = s & "<input type=""Text"" id=""Input_Text"" name=""Input_Text"" value="""" size=40><br />" & $CRLF
            s = s & "<br />" & $CRLF
            s = s & "<input type =""Button"" id=""Button_GetText"" name=""Button_GetText"" value=""Get text""><br />" & $CRLF
            s = s & "</body>" & $CRLF
            s = s & "</html>" & $CRLF
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

      CASE %WM_SIZE
         ' Resizes the control
         IF wParam <> %SIZE_MINIMIZED THEN
            GetClientRect hWnd, rc
            MoveWindow GetDlgItem(hWnd, %IDC_IEWB), 0, 0, rc.nRight - rc.nLeft, rc.nBottom - rc.nTop, %TRUE
         END IF

      CASE %WM_COMMAND
         SELECT CASE LO(WORD, wParam)
            CASE %IDCANCEL
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  SendMessage hWnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT

      CASE %WM_SYSCOMMAND
         ' Capture this message and send a WM_CLOSE message
         IF (wParam AND &HFFF0) = %SC_CLOSE THEN
            SendMessage hWnd, %WM_CLOSE, 0, 0
            EXIT FUNCTION
         END IF

      CASE %WM_DESTROY
         ' Disconnect events and quit
         IF ISOBJECT(pWBEvents) THEN EVENTS END pWBEvents
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hWnd, wMsg, wParam, lParam)

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
         CASE "Button_1", "Button_2", "Button_3", "Button_4"
            IHTMLDocument_setElementInnerHtmlById pHTMLDocument2, "output", "You have clicked " & bstrId
         CASE "Button_GetText"
            bstrValue = IHTMLDocument_getElementValueById(pHTMLDocument2, "Input_Text")
            MSGBOX bstrValue
      END SELECT

   END METHOD
   ' =====================================================================================

END INTERFACE

END CLASS
' ########################################################################################
