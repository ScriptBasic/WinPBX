#COMPILE EXE
#DIM ALL
%UNICODE = 1

' // Include files for external files
%USEWEBBROWSER = 1            ' // Use the WebBrowser control
#INCLUDE ONCE "CWindow.inc"   ' // CWindow class

' // Identifier
%IDC_WEBBROWSER = 1001

' ########################################################################################
' Main
' ########################################################################################
FUNCTION PBMAIN

   ' // Create the dialog
   LOCAL hDlg AS DWORD
   DIALOG NEW PIXELS, 0, "WebBrowser", , , 600, 350, %WS_OVERLAPPEDWINDOW TO hDlg

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' // Add a WebBrowser control
   LOCAL bstrURL AS WSTRING

   ' // You can pass a URL
   bstrURL = "http://www.powerbasic.com/support/pbforums/index.php"

   ' // Create an instance of the event class
   LOCAL pWBEvents AS DWebBrowserEvents2Impl
   pWBEvents = CLASS "CDWebBrowserEvents2"

   ' // Create the WebBrowser control
   LOCAL nWide, nHigh AS LONG
   DIALOG GET CLIENT hDlg TO nWide, nHigh
   pWindow.AddWebBrowserControl(hDlg, %IDC_WEBBROWSER, bstrURL, pWBEvents, 0, 0, nWide, nHigh)
   CONTROL SET FOCUS hDlg, %IDC_WEBBROWSER

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


' ########################################################################################
' Class CDWebBrowserEvents2
' Interface name = DWebBrowserEvents2
' IID = {34A715A0-6587-11D0-924A-0020AFC7AC4D}
' Web Browser Control events interface
' Attributes = 4112 [&H1010] [Hidden] [Dispatchable]
' ########################################################################################

CLASS CDWebBrowserEvents2 GUID$("{700B73A2-CCFC-4FE0-B9AC-D5853D71B7B9}") AS EVENT

INTERFACE DWebBrowserEvents2Impl GUID$("{34A715A0-6587-11D0-924A-0020AFC7AC4D}") AS EVENT

   INHERIT IDispatch

   ' =====================================================================================
   METHOD StatusTextChange <102> ( _
     BYVAL strText AS STRING _                          ' __in BSTR Text
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD ProgressChange <108> ( _
     BYVAL Progress AS LONG _                           ' __in long Progress
   , BYVAL ProgressMax AS LONG _                        ' __in long ProgressMax
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD CommandStateChange <105> ( _
     BYVAL nCommand AS LONG _                           ' __in long Command
   , BYVAL bEnable AS INTEGER _                         ' __in VARIANT_BOOL Enable
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD DownloadBegin <106>

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD DownloadComplete <104>

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD TitleChange <113> ( _
     BYVAL strText AS STRING _                          ' __in BSTR Text
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD PropertyChange <112> ( _
     BYVAL strProperty AS STRING _                      ' __in BSTR szProperty
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

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
   , BYREF Cancel AS INTEGER _                          ' __in_out VARIANT_BOOL* Cancel
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD NewWindow2 <251> ( _
     BYREF ppDisp AS IDispatch _                        ' __in_out IDispatch** ppDisp
   , BYREF bCancel AS INTEGER _                         ' __in_out VARIANT_BOOL* Cancel
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD NavigateComplete2 <252> ( _
     BYVAL pDisp AS IDispatch _                         ' __in IDispatch* pDisp
   , BYREF vURL AS VARIANT _                            ' __in VARIANT* URL
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD DocumentComplete <259> ( _
     BYVAL pDisp AS IDispatch _                         ' __in IDispatch* pDisp
   , BYREF vURL AS VARIANT _                            ' __in VARIANT* URL
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD OnQuit <253>

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD OnVisible <254> ( _
     BYVAL bVisible AS INTEGER _                        ' __in VARIANT_BOOL Visible
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD OnToolBar <255> ( _
     BYVAL bToolBar AS INTEGER _                        ' __in VARIANT_BOOL ToolBar
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD OnMenuBar <256> ( _
     BYVAL bMenuBar AS INTEGER _                        ' __in VARIANT_BOOL MenuBar
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD OnStatusBar <257> ( _
     BYVAL bStatusBar AS INTEGER _                      ' __in VARIANT_BOOL StatusBar
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD OnFullScreen <258> ( _
     BYVAL bFullScreen AS INTEGER _                     ' __in VARIANT_BOOL FullScreen
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD OnTheaterMode <260> ( _
     BYVAL bTheaterMode AS INTEGER _                    ' __in VARIANT_BOOL TheaterMode
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD WindowSetResizable <262> ( _
     BYVAL bResizable AS INTEGER _                      ' __in VARIANT_BOOL Resizable
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD WindowSetLeft <264> ( _
     BYVAL nLeft AS LONG _                              ' __in long Left
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD WindowSetTop <265> ( _
     BYVAL Top AS LONG _                                ' __in long Top
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD WindowSetWidth <266> ( _
     BYVAL nWidth AS LONG _                             ' __in long Width
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD WindowSetHeight <267> ( _
     BYVAL Height AS LONG _                             ' __in long Height
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD WindowClosing <263> ( _
     BYVAL IsChildWindow AS INTEGER _                   ' __in     VARIANT_BOOL IsChildWindow
   , BYREF bCancel AS INTEGER _                         ' __in_out VARIANT_BOOL* Cancel
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD ClientToHostWindow <268> ( _
     BYREF CX AS LONG _                                 ' __in_out long* CX
   , BYREF CY AS LONG _                                 ' __in_out long* CY
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD SetSecureLockIcon <269> ( _
     BYVAL SecureLockIcon AS LONG _                     ' __in long SecureLockIcon
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD FileDownload <270> ( _
     BYVAL bActiveDocument AS INTEGER _                 ' __in     VARIANT_BOOL ActiveDocument
   , BYREF bCancel AS INTEGER _                         ' __in_out VARIANT_BOOL* Cancel
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD NavigateError <271> ( _
     BYVAL pDisp AS IDispatch _                         ' __in IDispatch* pDisp
   , BYREF vURL AS VARIANT _                            ' __in VARIANT* URL
   , BYREF vFrame AS VARIANT _                          ' __in VARIANT* Frame
   , BYREF vStatusCode AS VARIANT _                     ' __in VARIANT* StatusCode
   , BYREF bCancel AS INTEGER _                         ' __in_out VARIANT_BOOL* Cancel
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD PrintTemplateInstantiation <225> ( _
     BYVAL pDisp AS IDispatch _                         ' __in IDispatch* pDisp
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD PrintTemplateTeardown <226> ( _
     BYVAL pDisp AS IDispatch _                         ' __in pDisp /* VT_DISPATCH <IDispatch> */
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD UpdatePageStatus <227> ( _
     BYVAL pDisp AS IDispatch _                         ' __in IDispatch* pDisp
   , BYREF nPage AS VARIANT _                           ' __in VARIANT* nPage
   , BYREF fDone AS VARIANT _                           ' __in VARIANT* fDone
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD PrivacyImpactedStateChange <272> ( _
     BYVAL bImpacted AS INTEGER _                       ' __in VARIANT_BOOL bImpacted
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD NewWindow3 <273> ( _
     BYREF ppDisp AS IDispatch _                        ' __in_out IDispatch** ppDisp
   , BYREF bCancel AS INTEGER _                         ' __in_out VARIANT_BOOL* Cancel
   , BYVAL dwFlags AS DWORD _                           ' __in unsigned long dwFlags
   , BYVAL bstrUrlContext AS STRING _                   ' __in BSTR bstrUrlContext
   , BYVAL bstrUrl AS STRING _                          ' __in BSTR bstrUrl
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD SetPhishingFilterStatus <282> ( _
     BYVAL PhishingFilterStatus AS LONG _               ' __in long PhishingFilterStatus
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD WindowStateChanged <283> ( _
     BYVAL dwWindowStateFlags AS DWORD _                ' __in unsigned long dwWindowStateFlags
   , BYVAL dwValidFlagsMask AS DWORD _                  ' __in unsigned long dwValidFlagsMask
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

END INTERFACE

END CLASS
