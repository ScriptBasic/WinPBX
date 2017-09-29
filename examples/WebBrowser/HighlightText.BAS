#COMPILE EXE
#DIM ALL
%UNICODE = 1

' // Include files for external files
%USEWEBBROWSER = 1             ' // Use the WebBrowser control
#INCLUDE ONCE "CWindow.inc"    ' // CWindow class

' // Identifier
%IDC_WEBBROWSER = 101

' ########################################################################################
' Main
' ########################################################################################
FUNCTION WinMain (BYVAL hInstance AS DWORD, BYVAL hPrevInstance AS DWORD, BYVAL lpszCmdLine AS WSTRINGZ PTR, BYVAL nCmdShow AS LONG) AS LONG

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' // Create the main window
   pWindow.CreateWindow(%NULL, "AddWebBrowser Template", 0, 0, 0, 0, 0, 0, CODEPTR(WindowProc))
   ' // Set the client siz
   pWindow.SetClientSize 600, 350
   ' // Center the window
   pWindow.CenterWindow

   ' // Add a WebBrowser control
   LOCAL hCtl AS DWORD
   LOCAL bstrURL AS WSTRING

   ' // Create an instance of the event class
   LOCAL pWBEvents AS DWebBrowserEvents2Impl
   pWBEvents = CLASS "CDWebBrowserEvents2"

   ' // Create the control and navigate to the specified page
   bstrURL = "http://www.powerbasic.com/support/pbforums/index.php"
   hCtl = pWindow.AddWebBrowserControl(pWindow.hwnd, %IDC_WEBBROWSER, bstrURL, pWBEvents, 0, 0, pWindow.ClientWidth, pWindow.ClientHeight)
   SetFocus hCtl

   ' // Default message pump (you can replace it with your own)
   pWindow.DoEvents(nCmdShow)

END FUNCTION
' ########################################################################################

' ========================================================================================
' Main callback function.
' ========================================================================================
FUNCTION WindowProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   STATIC hInstance AS DWORD        ' // Instance handle
   STATIC lpc AS CREATESTRUCT PTR   ' // Pointer to the creation parameters
   STATIC pWindow AS IWindow        ' // Reference to the IWindow interface

   SELECT CASE uMsg

      CASE %WM_CREATE
         ' // Pointer to the creation parameters
         lpc = lParam
         ' // Instance handle
         hInstance = @lpc.hInstance
         ' // Get a reference to the IWindow interface from the CREATESTRUCT structure
         pWindow = CWindow_GetObjectFromCreateStruct(lParam)
         EXIT FUNCTION

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

      CASE %WM_SIZE
         IF wParam <> %SIZE_MINIMIZED THEN
            ' // Resize the control
            pWindow.MoveWindow GetDlgItem(hwnd, %IDC_WEBBROWSER), 0, 0, pWindow.ClientWidth, pWindow.ClientHeight, %TRUE
         END IF

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
' Web Browser Control events interface
' ########################################################################################
CLASS CDWebBrowserEvents2 AS EVENT

INTERFACE DWebBrowserEvents2Impl $IID_DWebBrowserEvents2 AS EVENT

   INHERIT IDispatch

   ' =====================================================================================
   ' Fires when a document is completely loaded and initialized.
   ' =====================================================================================
   METHOD DocumentComplete <259> ( _
     BYVAL pDisp AS IDispatch _                         ' __in IDispatch* pDisp
   , BYREF vURL AS VARIANT _                            ' __in VARIANT* URL
   )                                                    ' void


      IF VARIANT$(vURL) = "about:blank" THEN EXIT METHOD

OutputDebugString FUNCNAME$ & VARIANT$(vURL)

      LOCAL pIWebBrowser2 AS IWebBrowser2
      LOCAL pIHTMLDocument2 AS IHTMLDocument2

      ' // Get a reference to the IWebBrowser2 interface
      pIWebBrowser2 = pDisp
      IF ISNOTHING(pIWebBrowser2) THEN EXIT METHOD

      ' // Get a reference to the active document
      pIHTMLDocument2 = pIWebBrowser2.Document
      IF ISNOTHING(pIHTMLDocument2) THEN EXIT METHOD

      ' // Get a reference to the selection object
      LOCAL pIHTMLSelectionObject AS IHTMLSelectionObject
      pIHTMLSelectionObject = pIHTMLDocument2.selection
      IF ISNOTHING(pIHTMLSelectionObject) THEN EXIT METHOD

      ' // Get a reference to the Text Range object
      LOCAL pDispatch AS IDispatch
      LOCAL pIHTMLTxtRange AS IHTMLTxtRange
      pDispatch = pIHTMLSelectionObject.createRange
      pIHTMLTxtRange = pDispatch
      IF ISNOTHING(pIHTMLTxtRange) THEN EXIT METHOD

      ' // Get an empty selection, so we start from the beginning
      pIHTMLSelectionObject.empty

      LOCAL iRes AS INTEGER
      ' // Find and select the first occurence of the wanted text to highlight
      iRes = pIHTMLTxtRange.findText("PowerBASIC", &H7FFFFFFF???, %FINDTEXT_WHOLEWORD)
      IF iRes THEN pIHTMLTxtRange.select
      ' // Find the next occurrences
      DO
         IF iRes = 0 THEN EXIT DO
         ' // Collapse the current selection so we start from the end of the previous range
         pIHTMLTxtRange.collapse(%VARIANT_FALSE)
         iRes = pIHTMLTxtRange.findText("PowerBASIC", &H7FFFFFFF???, %FINDTEXT_WHOLEWORD)
         IF iRes THEN pIHTMLTxtRange.execCommand("BackColor", %VARIANT_TRUE, "Yellow")
      LOOP

   END METHOD
   ' =====================================================================================

END INTERFACE

END CLASS
' ========================================================================================
