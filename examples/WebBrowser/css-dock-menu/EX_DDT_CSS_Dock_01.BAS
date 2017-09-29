' ########################################################################################
' This example demonstrates how to load a web page an detect which element has been clicked.
' ########################################################################################

' CSED_PBWIN - Use the PBWIN compiler
#COMPILE EXE
#DIM ALL
%UNICODE = 1

' // Include files for external files
%USEWEBBROWSER = 1            ' // Use the WebBrowser control
#INCLUDE ONCE "CWindow.inc"   ' // CWindow class

%IDC_WEBBROWSER = 101

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN () AS LONG

   ' // Create the dialog
   LOCAL hDlg AS DWORD
   DIALOG NEW PIXELS, 0, "Carousel", , , 650, 350, %WS_OVERLAPPEDWINDOW TO hDlg

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' // Add a WebBrowser control
   LOCAL bstrURL AS WSTRING

   ' // You can pass a URL
   bstrURL = EXE.Path$ & "css-dock-top.html"

   ' // Create an instance of the event class
   LOCAL pWBEvents AS DWebBrowserEvents2Impl
   pWBEvents = CLASS "CDWebBrowserEvents2"

   ' // Create the control
   LOCAL nWide, nHigh AS LONG
   DIALOG GET CLIENT hDlg TO nWide, nHigh
   pWindow.AddWebBrowserControl(hDlg, %IDC_WEBBROWSER, bstrURL, pWBEvents, 0, 0, nWide, nHigh)
   CONTROL SET FOCUS hDlg, %IDC_WEBBROWSER

   ' // Display and activate the dialog
   DIALOG SHOW MODAL hDlg, CALL DlgProc

END FUNCTION
' ========================================================================================

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

   ' =====================================================================================
   METHOD DocumentComplete <259> ( _
     BYVAL pDisp AS IDispatch _                         ' __in IDispatch* pDisp
   , BYREF vURL AS VARIANT _                            ' __in VARIANT* URL
   )                                                    ' void

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

      LOCAL pElement AS IHTMLElement             ' // Element that has fired the event
      LOCAL pHTMLDocument2 AS IHTMLDocument2     ' // Document object
      LOCAL bstrId AS WSTRING                    ' // Identifier of the element that has fired the event

      ' // Get a reference to the element that has fired the event
      IF ISOBJECT(pEvtObj) THEN pElement = pEvtObj.srcElement
      IF ISNOTHING(pElement) THEN EXIT METHOD

      ' // Get a reference to the IHTMLDocument2 interface
      pHTMLDocument2 = pElement.document
      IF ISNOTHING(pHTMLDocument2) THEN EXIT METHOD

      ' // Get the identifier of the element that has fired the event
      bstrId = pElement.id

      SELECT CASE bstrId
         CASE "Home", "Contact", "Portfolio", "Music", "Video", "History", "Calendar", "Links", "RSS", "RSS2"
            MSGBOX "You have clicked " & bstrId
      END SELECT

   END METHOD
   ' =====================================================================================

END INTERFACE

END CLASS
' ########################################################################################
