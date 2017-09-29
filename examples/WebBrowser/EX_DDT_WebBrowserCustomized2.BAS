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
   ' Fires when the status bar text of the object has changed.
   ' =====================================================================================
   METHOD StatusTextChange <102> ( _
     BYVAL strText AS STRING _                          ' __in BSTR Text
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fires when the progress of a download operation is updated on the object.
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
   ' Fires when the enabled state of a command changes.
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
   ' Fires when a navigation operation begins.
   ' =====================================================================================
   METHOD DownloadBegin <106>

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fires when a navigation operation finishes, is halted, or fails.
   ' =====================================================================================
   METHOD DownloadComplete <104>

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fires when the title of a document in the object becomes available or changes.
   ' =====================================================================================
   METHOD TitleChange <113> ( _
     BYVAL strText AS STRING _                          ' __in BSTR Text
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fires when the IWebBrowser2::PutProperty method of the object changes the value of a property.
   ' =====================================================================================
   METHOD PropertyChange <112> ( _
     BYVAL strProperty AS STRING _                      ' __in BSTR szProperty
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fires before navigation occurs in the given object (on either a window element or a frameset element).
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
   ' Fires when a new window is to be created.
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
   ' Fires after a navigation to a link is completed on a window element or a frameSet element.
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
   ' Fires when a document is completely loaded and initialized.
   ' =====================================================================================
   METHOD DocumentComplete <259> ( _
     BYVAL pDisp AS IDispatch _                         ' __in IDispatch* pDisp
   , BYREF vURL AS VARIANT _                            ' __in VARIANT* URL
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

      ' // After the MSHTML document has been loaded we retrieve a reference to its
      ' // ICustomDoc interface and give him a pointer to our IDocHostUIHandler interface
      ' // to allow for customization.

      LOCAL pIWebBrowser2 AS IWebBrowser2
      LOCAL pIHTMLDocument2 AS IHTMLDocument2
      LOCAL pICustomDoc AS ICustomDoc
      LOCAL pDocHostUIHandler AS IDocHostUIHandler2Impl

      pIWebBrowser2 = pDisp
      IF ISNOTHING(pIWebBrowser2) THEN EXIT METHOD

      ' // Get a reference to the active document
      pIHTMLDocument2 = pIWebBrowser2.Document
      IF ISNOTHING(pIHTMLDocument2) THEN EXIT METHOD

      ' // Get a reference to the CustomDoc interface
      pICustomDoc = pIHTMLDocument2
      IF ISNOTHING(pICustomDoc) THEN EXIT METHOD

      ' // Set our IDocHostUIHandler interface for MSHTML
      ' // MSHTML will release its previous IDocHostUIHandler interface
      ' // (if one is present) and call pDocHostUIHandler's AddRef method.
      pDocHostUIHandler = CLASS "CDocHostUIHandler2"
      IF ISOBJECT(pDocHostUIHandler) THEN
         pICustomDoc.SetUIHandler(pDocHostUIHandler)
      END IF

      ' Release the interfaces
      pDocHostUIHandler = NOTHING
      pICustomDoc = NOTHING
      pIWebBrowser2 = NOTHING

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fires before the Internet Explorer application quits.
   ' =====================================================================================
   METHOD OnQuit <253>

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fires when the IWebBrowser2::Visible property of the object is changed.
   ' =====================================================================================
   METHOD OnVisible <254> ( _
     BYVAL bVisible AS INTEGER _                        ' __in VARIANT_BOOL Visible
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fires when the IWebBrowser2::ToolBar property is changed.
   ' =====================================================================================
   METHOD OnToolBar <255> ( _
     BYVAL bToolBar AS INTEGER _                        ' __in VARIANT_BOOL ToolBar
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fires when the IWebBrowser2::MenuBar property is changed.
   ' =====================================================================================
   METHOD OnMenuBar <256> ( _
     BYVAL bMenuBar AS INTEGER _                        ' __in VARIANT_BOOL MenuBar
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fires when the IWebBrowser2::StatusBar property is changed.
   ' =====================================================================================
   METHOD OnStatusBar <257> ( _
     BYVAL bStatusBar AS INTEGER _                      ' __in VARIANT_BOOL StatusBar
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fires when the IWebBrowser2::FullScreen property is changed.
   ' =====================================================================================
   METHOD OnFullScreen <258> ( _
     BYVAL bFullScreen AS INTEGER _                     ' __in VARIANT_BOOL FullScreen
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fires when the IWebBrowser2::TheaterMode property is changed.
   ' =====================================================================================
   METHOD OnTheaterMode <260> ( _
     BYVAL bTheaterMode AS INTEGER _                    ' __in VARIANT_BOOL TheaterMode
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fires to indicate whether the host window should allow resizing of the object.
   ' =====================================================================================
   METHOD WindowSetResizable <262> ( _
     BYVAL bResizable AS INTEGER _                      ' __in VARIANT_BOOL Resizable
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fires when the object changes its left position.
   ' =====================================================================================
   METHOD WindowSetLeft <264> ( _
     BYVAL nLeft AS LONG _                              ' __in long Left
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fires when the object changes its top position.
   ' =====================================================================================
   METHOD WindowSetTop <265> ( _
     BYVAL Top AS LONG _                                ' __in long Top
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fires when the object changes its width.
   ' =====================================================================================
   METHOD WindowSetWidth <266> ( _
     BYVAL nWidth AS LONG _                             ' __in long Width
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fires when the object changes its height.
   ' =====================================================================================
   METHOD WindowSetHeight <267> ( _
     BYVAL Height AS LONG _                             ' __in long Height
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fires when the window of the object is about to be closed by script.
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
   ' Fires to request that the client window size is converted to the host window size.
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
   ' Fires when there is a change in encryption level.
   ' =====================================================================================
   METHOD SetSecureLockIcon <269> ( _
     BYVAL SecureLockIcon AS LONG _                     ' __in long SecureLockIcon
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fires to indicate that a file download is about to occur. If a file download dialog
   ' box can be displayed, this event fires prior to the appearance of the dialog box.
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
   ' Fires when an error occurs during navigation.
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
   ' Fires when a print template is instantiated.
   ' =====================================================================================
   METHOD PrintTemplateInstantiation <225> ( _
     BYVAL pDisp AS IDispatch _                         ' __in IDispatch* pDisp
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fires when a print template is destroyed.
   ' =====================================================================================
   METHOD PrintTemplateTeardown <226> ( _
     BYVAL pDisp AS IDispatch _                         ' __in pDisp /* VT_DISPATCH <IDispatch> */
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Not implemented.
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
   ' Fired when an event occurs that impacts privacy, or when a user navigates away from a
   ' URL that has impacted privacy.
   ' =====================================================================================
   METHOD PrivacyImpactedStateChange <272> ( _
     BYVAL bImpacted AS INTEGER _                       ' __in VARIANT_BOOL bImpacted
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Raised when a new window is to be created. Extends DWebBrowserEvents2::NewWindow2
   ' with additional information about the new window.
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
   ' Fires to indicate the progress and status of Microsoft Phishing Filter analysis of
   ' the current webpage.
   ' =====================================================================================
   METHOD SetPhishingFilterStatus <282> ( _
     BYVAL PhishingFilterStatus AS LONG _               ' __in long PhishingFilterStatus
   )                                                    ' void

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fires when the visibility state of a content window, such as the browser window or a tab, changes.
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
' ========================================================================================

' ########################################################################################
' Class CDocHostUIHandler2
' Implementation of the IDocHostUIHandler2 interface
' ########################################################################################

' ========================================================================================
' Class CDocHostUIHandler2
' ========================================================================================
$IID_CDocHostUIHandler2 = GUID$("{DFD6CC82-CC58-4227-AC23-A4B36E7A45B1}")

CLASS CDocHostUIHandler2 $IID_CDocHostUIHandler2 AS COMMON   ' // Use AS COMMON to avoid removal of methods

INTERFACE IDocHostUIHandler2Impl $IID_IDocHostUIHandler2

   INHERIT IUnknown

   ' =====================================================================================
   ' Enables MSHTML to display a shortcut menu.
   ' =====================================================================================
   METHOD ShowContextMenu ( _                           ' VTable offset = 12
     BYVAL dwID AS DWORD _                              ' /* [in] */ DWORD dwID
   , BYREF ppt AS POINT _                               ' /* [in] */ POINT *ppt
   , BYVAL pcmdtReserved AS IUnknown _                  ' /* [in] */ IUnknown *pcmdtReserved
   , BYVAL pdispReserved AS IDispatch _                 ' /* [in] */ IDispatch *pdispReserved
   ) AS LONG                                            ' HRESULT

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

      ' // This event notifies that the user has clicked the right mouse button to show the
      ' // context menu. We can anulate it returning %S_OK and show our context menu.

      ' // Do not allow to show the context menu
      MSGBOX "Sorry! Context menu disabled"
      METHOD = %S_OK

      ' // Host did not display its UI. MSHTML will display its UI.
'      METHOD = %S_FALSE

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the UI capabilities of the application that is hosting MSHTML.
   ' DOCHOSTUIFLAG_DIALOG
   '     MSHTML does not enable selection of the text in the form.
   ' DOCHOSTUIFLAG_DISABLE_HELP_MENU
   '     MSHTML does not add the Help menu item to the container's menu.
   ' DOCHOSTUIFLAG_NO3DBORDER
   '     MSHTML does not use 3-D borders on any frames or framesets. To turn the border off
   '     on only the outer frameset use DOCHOSTUIFLAG_NO3DOUTERBORDER
   ' DOCHOSTUIFLAG_SCROLL_NO
   '     MSHTML does not have scroll bars.
   ' DOCHOSTUIFLAG_DISABLE_SCRIPT_INACTIVE
   '     MSHTML does not execute any script until fully activated. This flag is used to
   '     postpone script execution until the host is active and, therefore, ready for script
   '     to be executed.
   ' DOCHOSTUIFLAG_OPENNEWWIN
   '     MSHTML opens a site in a new window when a link is clicked rather than browse to
   '     the new site using the same browser window.
   ' DOCHOSTUIFLAG_DISABLE_OFFSCREEN
   '     Not implemented.
   ' DOCHOSTUIFLAG_FLAT_SCROLLBAR
   '     MSHTML uses flat scroll bars for any UI it displays.
   ' DOCHOSTUIFLAG_DIV_BLOCKDEFAULT
   '     MSHTML inserts the div tag if a return is entered in edit mode. Without this flag,
   '     MSHTML will use the p tag.
   ' DOCHOSTUIFLAG_ACTIVATE_CLIENTHIT_ONLY
   '     MSHTML only becomes UI active if the mouse is clicked in the client area of the
   '     window. It does not become UI active if the mouse is clicked on a non-client area,
   '     such as a scroll bar.
   ' DOCHOSTUIFLAG_OVERRIDEBEHAVIORFACTORY
   '     MSHTML consults the host before retrieving a behavior from the URL specified on
   '     the page. If the host does not support the behavior, MSHTML does not proceed to
   '     query other hosts or instantiate the behavior itself, even for behaviors developed
   '     in script (HTML Components (HTCs)).
   ' DOCHOSTUIFLAG_CODEPAGELINKEDFONTS
   '     Microsoft Internet Explorer 5 and later. Provides font selection compatibility
   '     for Microsoft Outlook Express. If the flag is enabled, the displayed characters
   '     are inspected to determine whether the current font supports the code page. If
   '     disabled, the current font is used, even if it does not contain a glyph for the
   '     character. This flag assumes that the user is using Internet Explorer 5 and
   '     Outlook Express 4.0.
   ' DOCHOSTUIFLAG_URL_ENCODING_DISABLE_UTF8
   '     Internet Explorer 5 and later. Controls how nonnative URLs are transmitted over
   '     the Internet. Nonnative refers to characters outside the multibyte encoding of
   '     the URL. If this flag is set, the URL is not submitted to the server in UTF-8 encoding.
   ' DOCHOSTUIFLAG_URL_ENCODING_ENABLE_UTF8
   '     Internet Explorer 5 and later. Controls how nonnative URLs are transmitted over
   '     the Internet. Nonnative refers to characters outside the multibyte encoding of
   '     the URL. If this flag is set, the URL is submitted to the server in UTF-8 encoding.
   ' DOCHOSTUIFLAG_ENABLE_FORMS_AUTOCOMPLETE
   '     Internet Explorer 5 and later. Enables the AutoComplete feature for forms in the
   '     hosted browser. The Intelliforms feature is only turned on if the user has
   '     previously enabled it. If the user has turned the AutoComplete feature off for
   '     forms, it is off whether this flag is specified or not.
   ' DOCHOSTUIFLAG_ENABLE_INPLACE_NAVIGATION
   '     Internet Explorer 5 and later. Enables the host to specify that navigation should
   '     happen in place. This means that applications hosting MSHTML directly can specify
   '     that navigation happen in the application's window. For instance, if this flag is
   '     set, you can click a link in HTML mail and navigate in the mail instead of opening
   '     a new Windows Internet Explorer window.
   ' DOCHOSTUIFLAG_IME_ENABLE_RECONVERSION
   '     Internet Explorer 5 and later. During initialization, the host can set this flag
   '     to enable Input Method Editor (IME) reconversion, allowing computer users to employ
   '     IME reconversion while browsing Web pages. An input method editor is a program that
   '     allows users to enter complex characters and symbols, such as Japanese Kanji
   '     characters, using a standard keyboard. For more information, see the International
   '     Features reference in the Base Services section of the Windows Software Development
   '     Kit (SDK).
   ' DOCHOSTUIFLAG_THEME
   '     Internet Explorer 6 and later. Specifies that the hosted browser should use themes
   '     for pages it displays.
   ' DOCHOSTUIFLAG_NOTHEME
   '     Internet Explorer 6 and later. Specifies that the hosted browser should not use
   '     themes for pages it displays.
   ' DOCHOSTUIFLAG_NOPICS
   '     Internet Explorer 6 and later. Disables PICS ratings for the hosted browser.
   ' DOCHOSTUIFLAG_NO3DOUTERBORDER
   '     Internet Explorer 6 and later. Turns off any 3-D border on the outermost frame or
   '     frameset only. To turn borders off on all frame sets, use DOCHOSTUIFLAG_NO3DBORDER
   ' DOCHOSTUIFLAG_DISABLE_EDIT_NS_FIXUP
   '     Internet Explorer 6 and later. Disables the automatic correction of namespaces when
   '     editing HTML elements.
   ' DOCHOSTUIFLAG_LOCAL_MACHINE_ACCESS_CHECK
   '     Internet Explorer 6 and later. Prevents Web sites in the Internet zone from accessing
   '     files in the Local Machine zone.
   ' DOCHOSTUIFLAG_DISABLE_UNTRUSTEDPROTOCOL
   '     Internet Explorer 6 and later. Turns off untrusted protocols. Untrusted protocols
   '     include ms-its, ms-itss, its, and mk:@msitstore.
   ' DOCHOSTUIFLAG_HOST_NAVIGATES
   '     Internet Explorer 7. Indicates that navigation is delegated to the host; otherwise,
   '     MSHTML will perform navigation. This flag is used primarily for non-HTML document types.
   ' DOCHOSTUIFLAG_ENABLE_REDIRECT_NOTIFICATION
   '     Internet Explorer 7. Causes MSHTML to fire an additional DWebBrowserEvents2::BeforeNavigate2
   '     event when redirect navigations occur. Applications hosting the WebBrowser Control
   '     can choose to cancel or continue the redirect by returning an appropriate value in
   '     the Cancel parameter of the event.
   ' DOCHOSTUIFLAG_USE_WINDOWLESS_SELECTCONTROL
   '     Internet Explorer 7. Causes MSHTML to use the Document Object Model (DOM) to create
   '     native "windowless" select controls that can be visually layered under other elements.
   ' DOCHOSTUIFLAG_USE_WINDOWED_SELECTCONTROL
   '     Internet Explorer 7. Causes MSHTML to create standard Microsoft Win32 "windowed"
   '     select and drop-down controls.
   ' DOCHOSTUIFLAG_ENABLE_ACTIVEX_INACTIVATE_MODE
   '     Internet Explorer 6 for Windows XP Service Pack 2 (SP2) and later. Requires user
   '     activation for Microsoft ActiveX controls and Java Applets embedded within a web page.
   '     This flag enables interactive control blocking, which provisionally disallows direct
   '     interaction with ActiveX controls loaded by the APPLET, EMBED, or OBJECT elements.
   '     When a control is inactive, it does not respond to user input; however, it can perform
   '     operations that do not involve interaction.
   ' DOCHOSTUIFLAG_DPI_AWARE
   '     Internet Explorer 8. Causes layout engine to calculate document pixels as 96 dots
   '     per inch (dpi). Normally, a document pixel is the same size as a screen pixel. This
   '     flag is equivalent to setting the FEATURE_96DPI_PIXEL feature control key on a
   '     per-host basis.
   ' Remarks
   '     The DOCHOSTUIFLAG_BROWSER flag, a supplementary defined constant (not technically
   '     a part of this enumeration), combines the values of DOCHOSTUIFLAG_DISABLE_HELP_MENU
   '     and DOCHOSTUIFLAG_DISABLE_SCRIPT_INACTIVE.
   ' =====================================================================================
   METHOD GetHostInfo ( _                               ' VTable offset = 16
     BYREF pInfo AS DOCHOSTUIINFO _                     ' /* [out][in] */ DOCHOSTUIINFO *pInfo
   ) AS LONG                                            ' HRESULT

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

      IF VARPTR(pInfo) THEN
         pInfo.cbSize = SIZEOF(DOCHOSTUIINFO)
'         pInfo.dwFlags = %DOCHOSTUIFLAG_NO3DBORDER OR %DOCHOSTUIFLAG_THEME
         pInfo.dwDoubleClick = %DOCHOSTUIDBLCLK_DEFAULT
         pInfo.pchHostCss = %NULL
         pInfo.pchHostNS = %NULL
      END IF
      METHOD = %S_OK

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Enables the host to replace MSHTML menus and toolbars.
   ' =====================================================================================
   METHOD ShowUI ( _                                    ' VTable offset = 20
     BYVAL dwID AS DWORD _                              ' /* [in] */ DWORD dwID
   , BYVAL pActiveObject AS IOleInPlaceActiveObject _   ' /* [in] */ IOleInPlaceActiveObject *pActiveObject
   , BYVAL pCommandTarget AS IOleCommandTarget _        ' /* [in] */ IOleCommandTarget *pCommandTarget
   , BYVAL pFrame AS IOleInPlaceFrame _                 ' /* [in] */ IOleInPlaceFrame *pFrame
   , BYVAL pDoc AS IOleInPlaceUIWindow _                ' /* [in] */ IOleInPlaceUIWindow *pDoc
   ) AS LONG                                            ' HRESULT

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Enables the host to remove its menus and toolbars.
   ' =====================================================================================
   METHOD HideUI ( _                                    ' VTable offset = 24
   ) AS LONG                                            ' HRESULT

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Notifies the host that the command state has changed.
   ' =====================================================================================
   METHOD UpdateUI ( _                                  ' VTable offset = 28
   ) AS LONG                                            ' HRESULT

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Called by the MSHTML implementation of IOleInPlaceActiveObject::EnableModeless.
   ' Also called when MSHTML displays a modal UI.
   ' =====================================================================================
   METHOD EnableModeless ( _                            ' VTable offset = 32
     BYVAL fEnable AS LONG _                            ' /* [in] */ BOOL fEnable
   ) AS LONG                                            ' HRESULT

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Called by the MSHTML implementation of IOleInPlaceActiveObject::OnDocWindowActivate.
   ' =====================================================================================
   METHOD OnDocWindowActivate ( _                       ' VTable offset = 36
     BYVAL fActivate AS LONG _                          ' /* [in] */ BOOL fActivate
   )

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Called by the MSHTML implementation of IOleInPlaceActiveObject::OnFrameWindowActivate.
   ' =====================================================================================
   METHOD OnFrameWindowActivate ( _                     ' VTable offset = 40
     BYVAL fActivate AS LONG _                          ' /* [in] */ BOOL fActivate
   ) AS LONG                                            ' HRESULT

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Called by the MSHTML implementation of IOleInPlaceActiveObject::ResizeBorder.
   ' =====================================================================================
   METHOD ResizeBorder ( _                              ' VTable offset = 44
     BYREF prcBorder AS RECT _                          ' /* [in] */ LPCRECT prcBorder
   , BYVAL pUIWindow AS IOleInPlaceUIWindow _           ' /* [in] */ IOleInPlaceUIWindow *pUIWindow
   , BYVAL fRameWindow AS LONG _                        ' /* [in] */ BOOL fRameWindow
   ) AS LONG                                            ' HRESULT

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Called by MSHTML when IOleInPlaceActiveObject::TranslateAccelerator or
   ' IOleControlSite::TranslateAccelerator is called.
   ' =====================================================================================
   METHOD TranslateAccelerator ( _                      ' VTable offset = 48
     BYREF lpMsg AS tagMSG _                            ' /* [in] */ LPMSG lpMsg
   , BYREF pguidCmdGroup AS GUID _                      ' /* [in] */ const GUID *pguidCmdGroup
   , BYVAL nCmdID AS DWORD _                            ' /* [in] */ DWORD nCmdID
   ) AS LONG                                            ' HRESULT

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

      ' // When you use accelerator keys such as TAB, you may need to override the
      ' // default host behavior. The example shows how to do this.
'      IF lpMsg.message = %WM_KEYDOWN AND lpMsg.wParam = %VK_TAB THEN
'         METHOD = %S_FALSE
'      END IF

      ' // Return S_FALSE if you don't process the message
      METHOD = %S_FALSE

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a registry subkey path that overrides the default Windows Internet Explorer
   ' registry settings.
   ' =====================================================================================
   METHOD GetOptionKeyPath ( _                          ' VTable offset = 52
     BYREF pchKey AS DWORD _                            ' /* [out] */ LPOLESTR *pchKey
   , BYVAL dw_ AS DWORD _                               ' /* [in] */ DWORD dw
   ) AS LONG                                            ' HRESULT

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

      pchKey = %NULL

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Enables the host to supply an alternative IDropTarget interface.
   ' =====================================================================================
   METHOD GetDropTarget ( _                             ' VTable offset = 56
     BYVAL pDropTarget AS IDropTarget _                 ' /* [in] */ IDropTarget *pDropTarget
   , BYREF ppDropTarget AS IDropTarget  _               ' /* [out] */ IDropTarget **ppDropTarget
   ) AS LONG                                            ' HRESULT

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

      ppDropTarget = NOTHING
      METHOD = %E_NOTIMPL

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the host's IDispatch interface.
   ' =====================================================================================
   METHOD GetExternal ( _                             ' VTable offset = 60
     BYREF ppDispatch AS IDispatch  _                 ' /* [out] */ IDispatch **ppDispatch
     ) AS LONG                                        ' HRESULT

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

      ppDispatch = NOTHING
      METHOD = %S_FALSE

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Enables the host to modify the URL to be loaded.
   ' =====================================================================================
   METHOD TranslateUrl ( _                              ' VTable offset = 64
     BYVAL dwTranslate AS DWORD  _                      ' /* [in] */ DWORD dwTranslate
   , BYREF pchURLIn AS WSTRINGZ _                       ' /* [in] */ OLECHAR *pchURLIn
   , BYREF ppchURLOut AS WSTRINGZ _                     ' /* [out] */ OLECHAR **ppchURLOut
   ) AS LONG                                            ' HRESULT

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

      ppchURLOut = ""
      METHOD = %S_FALSE

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Enables the host to replace the MSHTML data object.
   ' =====================================================================================
   METHOD FilterDataObject ( _                          ' VTable offset = 68
     BYVAL pDO AS IDataObject  _                        ' /* [in] */ IDataObject *pDO
   , BYREF ppDORet AS IDataObject _                     ' /* [out] */ IDataObject **ppDORet
   ) AS LONG                                            ' HRESULT

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

      ppDORet = NOTHING
      METHOD = %S_FALSE

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets a registry subkey path that modifies Windows Internet Explorer user preferences.
   ' =====================================================================================
   METHOD GetOverrideKeyPath ( _                        ' VTable offset = 72
     BYREF pchKey AS DWORD _                            ' /* [out] */ LPOLESTR *pchKey
   , BYVAL dw_ AS DWORD _                               ' /* [in] */ DWORD dw
   ) AS LONG                                            ' HRESULT

     ' *** Insert your code here ***
     OutputDebugString FUNCNAME$

      pchKey = %NULL

   END METHOD
   ' =====================================================================================

END INTERFACE     ' IDocHostUIHandler2Impl

END CLASS         ' CDocHostUIHandler2
' ========================================================================================
