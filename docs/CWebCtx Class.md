# CWebCtx Class

Wrapper class to embed instances of the **WebBrowser** control in our application using an OLE Container (**CAxHost** class) to host it.

It also provides methods to connect and disconnect to the events fired by the **WebBrowser** control, set event handlers (pointers to callback procedures) for both the **DWebBrowser2** and **IDocHostUIHandler2** interfaces, a method to navigate to a URL, and function to get references to the OLE Container class and the **IWebBrowser2** interface.

The file **AfxExDisp.bi** provides declarations to call the methods of the **WebBrowser** interfaces using abstract methods.

The **WebBrowser** events sink class is provided in the file **CWebBrowserEvents.inc**, and the **DocHostUIHandler** events sink class is provided in the file **CDocHostUIHandler2.inc**.

**Include file**: CWebCtx.inc.

### Constructor

| Name       | Description |
| ---------- | ----------- |
| [CAXHOST_AMBIENTDISP structure](#CAXHOST_AMBIENTDISP) | Contains information the ambient properties of the **CAxHost** control. |
| [Constructor](#Constructor) | Creates an instance of the OLE container using a ProgId. |

### Methods

| Name       | Description |
| ---------- | ----------- |
| [Advise](#Advise) | Establishes a connection between a connection point object and the client's sink. |
| [AxHostPtr](#AxHostPtr) | Returns a pointer to the **CAxHost** class. |
| [BrowserPtr](#BrowserPtr) | Returns a direct pointer to the **IWebBrowser2** interface of the hosted **WebBrowser** control. |
| [Busy](#Busy) | Returns a boolean value indicating whether the object is engaged in a navigation or downloading operation. |
| [CtrlID](#CtrlID) | Returns the identifier of the container's window. |
| [Document](#Document) | Retrieves the automation object of the active document, if any. |
| [ExecWB](#ExecWB) | Executes a command on an OLE object and returns the status of the command execution using the **IOleCommandTarget** interface. |
| [Find](#Find) | Activates the find dialog. |
| [GetActiveElementId](#GetActiveElementId) | Retrieves the ID of the active element (the object that has the focus when the parent document has focus). |
| [GetBodyInnerHtml](#GetBodyInnerHtml) | Returns a string that represents the text and html elements between the start and end body tags. |
| [GetBodyInnerText](#GetBodyInnerText) | Returns a string that represents the text between the start and end body tags without any associated HTML. |
| [GoBack](#GoBack) | Navigates backward one item in the history list. |
| [GetElementInnerHtmlById](#GetElementInnerHtmlById) | Retrieves the HTML between the start and end tags of the object. |
| [GetElementValueById](#GetElementValueById) | Retrieves the value attribute of the specified attribute. |
| [GoForward](#GoForward) | Navigates forward one item in the history list. |
| [GoHome](#GoHome) | Navigates to the current home or start page. |
| [GoSearch](#GoSearch) | Navigates to the current search page. |
| [hWindow](#hWindow) | Returns the handle of the OLE Container hosting window. |
| [InternetOptions](#InternetOptions) | Activates the Internet options dialog. |
| [LocationName](#LocationName) | Retrieves the name of the resource that Microsoft Internet Explorer is currently displaying. |
| [LocationURL](#LocationURL) | Retrieves the URL of the resource that Microsoft Internet Explorer is currently displaying. |
| [Navigate](#Navigate) | Returns the handle of the OLE Container hosting window. |
| [PageProperties](#PageProperties) | Activates the properties dialog. |
| [PageSetup](#PageSetup) | Activates the page setup dialog. |
| [PrintPage](#PrintPage) | Activates the print dialog. |
| [PrintPreview](#PrintPreview) | Activates the print preview dialog. |
| [QueryStatusWB](#QueryStatusWB) | Queries the OLE object for the status of commands using the **QueryStatus** method of the **IOleCommandTarget** interface.|
| [ReadyState](#ReadyState) | Retrieves the ready state of the object. |
| [Refresh](#Refresh) | Reloads the file that is currently displayed in the object. |
| [Refresh2](#Refresh2) | Reloads the file that is currently displayed in the object. Unlike Refresh, this method contains a parameter that specifies the refresh level. |
| [RegisterAsBrowser](#RegisterAsBrowser) | Sets or retrieves a value that indicates whether the object is registered as a top-level browser for target name resolution. |
| [RegisterAsDropTarget](#RegisterAsDropTarget) | Sets or retrieves a value that indicates whether the object is registered as a drop target for navigation. |
| [SaveAs](#SaveAs) | Activates the save file dialog. |
| [SetElementFocusById](#SetElementFocusById) | Sets the HTML between the start and end tags of the object. |
| [SetElementInnerHtmlById](#SetElementInnerHtmlById) | Sets the HTML between the start and end tags of the object. |
| [SetElementValueById](#SetElementValueById) | Sets the value attribute of the specified identifier. |
| [SetEventProc](#SetEventProc) | Sets pointers to user implemented callback procedures to receive events of the hosted WebBrowser control. |
| [SetFocus](#SetFocus) | Sets the focus in the hosted document (usually an html page). |
| [SetUIEventProc](#SetUIEventProc) | Sets pointers to user implemented callback procedures to receive events of the **IDocHostUIHandler2** interface. |
| [SetUIHandler](#SetUIHandler) | Sets our implementation of the **IDocHostUIHandler** interface to customize the WebBrowser. |
| [ShowSource](#ShowSource) | Displays the source code of the page in an instance of **NotePad**. |
| [Silent](#Silent) | Sets or gets a value that indicates whether the object can display dialog boxes. |
| [Stop](#Stop) | Cancels any pending navigation or download operation and stops any dynamic page elements, such as background sounds and animations. |
| [Unadvise](#Unadvise) | Releases the events connection. |
| [WaitForPageLoad](#WaitForPageLoad) | Waits until the page had been fully downloaded or te timeout has expired. |
| [WriteHtml](#WriteHtml) | Writes one or more HTML expressions to a document. |

### Helper Procedures

| Name       | Description |
| ---------- | ----------- |
| [AfxGetBrowserPtr](#AfxGetBrowserPtr) | Returns a pointer to the hosted WebBrowser control given the handle of the form, or any control in the form, and the control identifier. |
| [AfxGetActiveElementId](#AfxGetActiveElementId) | Retrieves the ID of the active element (the object that has the focus when the parent document has focus). |
| [AfxGetBodyInnerHtml](#AfxGetBodyInnerHtml) | Returns a string that represents the text and html elements between the start and end body tags. |
| [AfxGetBodyInnerText](#AfxGetBodyInnerText) | Returns a string that represents the text between the start and end body tags without any associated HTML. |
| [AfxGetElementInnerHtmlById](#AfxGetElementInnerHtmlById) | Retrieves the HTML between the start and end tags of the object. |
| [AfxGetElementValueById](#AfxGetElementValueById) | Retrieves the value attribute of the specified attribute. |
| [AfxSetElementFocusById](#AfxSetElementFocusById) | Sets the focus in the specified element. |
| [AfxSetElementInnerHtmlById](#AfxSetElementInnerHtmlById) | Sets the HTML between the start and end tags of the object. |
| [AfxSetElementValueById](#AfxSetElementValueById) | Sets the value attribute of the specified identifier. |
| [AfxWriteHtml](#AfxWriteHtml) | Writes one or more HTML expressions to a document. |

# CWebBrowserEvents Class

The **CWebBrowserEvents** class implements an event sink interface to receive event notifications from the **WebBrowser** control.

The constructor of the **CWebCtx** class creates automatically an instance of this class and establishes a connection with the hosted control calling the **Advise** method.

To set pointers to the callback functions of the events in which you are interested use the SetEventProc of the **CWebCtx** class.

All these callback functions will receive a pointer to the **CwebCtx** class as the first parameter. With this pointer, we can get:

* Access to all the methods of the CWebCtx class.
* The handle of the container window calling pCWbCtx->hWindow.
* A pointer to the hosted WebBrowser control calling pWebCtx->BrowserPtr.
* A pointer to the CAxHost class calling pWebCtx->HostPtr.

| Name       | Description |
| ---------- | ----------- |
| [BeforeNavigate2](#BeforeNavigate2) | Fires before navigation occurs in the given object (on either a window or frameset element). |
| [ClientToHostWindow](#ClientToHostWindow) | Fires to request that the client window size be converted to the host window size. |
| [CommandStateChange](#CommandStateChange) | Fires when the enabled state of a command changes. |
| [DocumentComplete](#DocumentComplete) | Fires when a document has been completely loaded and initialized. |
| [DownloadBegin](#DownloadBegin) | Fires when a navigation operation is beginning. |
| [DownloadComplete](#DownloadComplete) | Fires when a navigation operation finishes, is halted, or fails. |
| [FileDownload](#FileDownload) | Fires to indicate that a file download is about to occur. If a file download dialog is to be displayed, this event is fired prior to the display of the dialog. |
| [HtmlDocumentEventsProc](#HtmlDocumentEventsProc) | Provides access to properties and methods exposed by an object. |
| [NavigateComplete2](#NavigateComplete2) | Fires after a navigation to a link is completed on either a window or frameSet element. |
| [NavigateError](#NavigateError) | Fires when an error occurs during navigation. |
| [NewWindow2](#NewWindow2) | Raised when a new window is to be created. |
| [NewWindow3](#NewWindow3) | Raised when a new window is to be created. Extends **NewWindow2** with additional information about the new window. |
| [OnVisible](#OnVisible) | Fires when the **Visible** property of the object is changed. |
| [PrintTemplateInstantiation](#PrintTemplateInstantiation) | Fires when a print template has been instantiated. |
| [PrintTemplateTeardown](#PrintTemplateTeardown) | Fires when a print template has been destroyed. |
| [PrivacyImpactedStateChange](#PrivacyImpactedStateChange) | Fired when an event occurs that impacts privacy or when a user navigates away from a URL that has impacted privacy. |
| [ProgressChange](#ProgressChange) | Fires when the progress of a download operation is updated on the object. |
| [PropertyChange](#PropertyChange) | Fires when the **PutProperty** method of the object changes the value of a property. |
| [SetSecureLockIcon](#SetSecureLockIcon) | Fires when there is a change in encryption level. |
| [StatusTextChange](#StatusTextChange) | Fires when the status bar text of the object has changed. |
| [TitleChange](#TitleChange) | Fires when the title of a document in the object becomes available or changes. |
| [WindowClosing](#WindowClosing) | Fires when the window of the object is about to be closed by script. |
| [WindowSetHeight](#WindowSetHeight) | Fires when the object changes its height. |
| [WindowSetLeft](#WindowSetLeft) | Fires when the object changes its left position. |
| [WindowSetResizable](#WindowSetResizable) | Fires to indicate whether the host window should allow or disallow resizing of the object. |
| [WindowSetTop](#WindowSetTop) | Fires when the object changes its top position. |
| [WindowSetWidth](#WindowSetWidth) | Fires when the object changes its width. |
| [WindowStateChanged](#WindowStateChanged) | Fires when the progress of a download operation is updated on the object. |


# <a name="CAXHOST_AMBIENTDISP"></a>CAXHOST_AMBIENTDISP Structure

Contains information the ambient properties of the **CAxHost** control.

```
TYPE CAXHOST_AMBIENTDISP
   Font AS IFontDisp PTR
   BackColor AS LONG = &hFFFFFF
   ForeColor AS LONG = 0
   LocaleID AS LONG = LOCALE_USER_DEFAULT
   Silent AS VARIANT_BOOL = -1
   UIDead AS VARIANT_BOOL = 0
   DisplayAsDefault AS VARIANT_BOOL = 0
   SupportMnemonics AS VARIANT_BOOL = -1
   OffLineIfNoConnected AS VARIANT_BOOL = -1
   DlCtFlags AS LONG = 0
END TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **Font** | Pointer to a **IFontDisp** interface. To create the font you can use the **OleCreateFontDisp** method of the CAxHost class or the **AfxOleCreateFontDisp** function. The default font is SegoeUI, 9 points. |
| **BackColor** | Specifies the back color of the container. The default color is white. You can use the FreeBasic BGR macro to set the color. |
| **ForeColor** | Specifies the fore color of the container. The default color is black. You can use the FreeBasic BGR macro to set the color. |
| **LocaleID** | Specifies the ambient locale ID of the container. |
| **Silent** | Indicates the bind operation will be completed silently. No user interface or user notification will occur. |
| **UIDead** | Indicates whether the container wants the control to respond to user-interface actions. If TRUE, the control should not respond. Default value: FALSE. |
| **DisplayAsDefault** | A flag that is TRUE if the container has marked the control in this site to be a default button, and therefore a button control should draw itself with a thicker frame. Default value: FALSE. |
| **SupportMnemonics** | Indicates whether the container supports keyboard mnemonics. Default value: TRUE. |
| **OffLineIfNotConnected** | WebBroser control. The control support offline browsing. |
| **DlCtFlags** | A combination of following flags, using the bitwise OR operator, to indicate your preferences. Most of the flag values have negative effects, that is, they prevent behavior that normally happens. For instance, scripts are normally executed by the WebBrowser Control if you don't customize its behavior. But if you set the DLCTL_NOSCRIPTS flag, no scripts will execute in that instance of the control. However, three flags—DLCTL_DLIMAGES, DLCTL_VIDEOS, and DLCTL_BGSOUNDS—work exactly opposite. If you set flags at all, you must set these three for the WebBrowser Control to behave in its default manner vis-a-vis images, videos and sounds. |

**Flags**

* DLCTL_DLIMAGES, DLCTL_VIDEOS, and DLCTL_BGSOUNDS: Images, videos, and background sounds will be downloaded from the server and displayed or played if these flags are set. They will not be downloaded and displayed if the flags are not set.
* DLCTL_NO_SCRIPTS and DLCTL_NO_JAVA: Scripts and Java applets will not be executed.
* DLCTL_NO_DLACTIVEXCTLS and DLCTL_NO_RUNACTIVEXCTLS : ActiveX controls will not be downloaded or will not be executed.
* DLCTL_DOWNLOADONLY: The page will only be downloaded, not displayed.
* DLCTL_NO_FRAMEDOWNLOAD: The WebBrowser Control will download and parse a frameset, but not the individual frame objects within the frameset.
* DLCTL_RESYNCHRONIZE and DLCTL_PRAGMA_NO_CACHE: These flags cause cache refreshes. With DLCTL_RESYNCHRONIZE, the server will be asked for update status. Cached files will be used if the server indicates that the cached information is up-to-date. With DLCTL_PRAGMA_NO_CACHE, files will be re-downloaded from the server regardless of the update status of the files.
* DLCTL_NO_BEHAVIORS: Behaviors are not downloaded and are disabled in the document.
* DLCTL_NO_METACHARSET_HTML: Character sets specified in meta elements are suppressed.
* DLCTL_URL_ENCODING_DISABLE_UTF8 and DLCTL_URL_ENCODING_ENABLE_UTF8: These flags function similarly to the DOCHOSTUIFLAG_URL_ENCODING_DISABLE_UTF8 and DOCHOSTUIFLAG_URL_ENCODING_ENABLE_UTF8 flags used with IDocHostUIHandler.GetHostInfo. The difference is that the DOCHOSTUIFLAG flags are checked only when the WebBrowser Control is first instantiated. The download flags here for the ambient property change are checked whenever the WebBrowser Control needs to perform a download.
* DLCTL_NO_CLIENTPULL: No client pull operations will be performed.
* DLCTL_SILENT: No user interface will be displayed during downloads.
* DLCTL_FORCEOFFLINE: The WebBrowser Control always operates in offline mode.
* DLCTL_OFFLINEIFNOTCONNECTED and DLCTL_OFFLINE: These flags are the same. The WebBrowser Control will operate in offline mode if not connected to the Internet.

# <a name="Constructor"></a>Constructor

Creates an instance of the **CWebCtx** class.

```
CONSTRUCTOR CWebCtx (BYVAL pWindow AS CWindow PTR, BYVAL cID AS LONG_PTR, BYVAL x AS LONG = 0, _
   BYVAL y AS LONG = 0, BYVAL nWidth AS LONG = 0, BYVAL nHeight AS LONG = 0, BYVAL dwStyle AS DWORD = 0, _
   BYVAL dwExStyle AS DWORD = 0, BYVAL pAmbientFlags AS CAXHOST_AMBIENTDISP PTR = NULL)
```

| Member     | Description |
| ---------- | ----------- |
| *pWindow* | Pointer to the instance of the **CWindow** class used to create the form. |
| *cID* |The identifier of the control. It must be unique. |
| *x* | The x-coordinate of the upper-left corner of the window relative to the upper-left corner of the parent window's client area. |
| *y* | The initial y-coordinate of the upper-left corner of the window relative to the upper-left corner of the parent window's client area. |
| *nWidth* | The width of the window. |
| *nHeight* | The height of the window. |
| *dwStyle* | The style of the window being created. |
| *dwExStyle* | The extended style of the window being created. |
| *pAmbientDisp* | Pointer to a **CAXHOST_AMBIENTDISP** structure. |

#### Example

````
Example

#define UNICODE
#INCLUDE ONCE "Afx/CVAR.inc"
#INCLUDE ONCE "Afx/CAxHost/CWebCtx.inc"
USING Afx

CONST IDC_WEBBROWSER = 1001
CONST IDC_SATUSBAR = 1002

DECLARE FUNCTION WinMain (BYVAL hInstance AS HINSTANCE, _
                          BYVAL hPrevInstance AS HINSTANCE, _
                          BYVAL szCmdLine AS ZSTRING PTR, _
                          BYVAL nCmdShow AS LONG) AS LONG

   END WinMain(GetModuleHandleW(NULL), NULL, COMMAND(), SW_NORMAL)

' // Forward declaration
DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT
DECLARE SUB WebBrowser_StatusTextChangeProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pwszText AS WSTRING PTR)
DECLARE SUB WebBrowser_DocumentCompleteProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pdisp AS IDispatch PTR, BYVAL vUrl AS VARIANT PTR)
DECLARE SUB WebBrowser_BeforeNavigate2Proc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pdisp AS IDispatch PTR, _
    BYVAL vUrl AS VARIANT PTR, BYVAL Flags AS VARIANT PTR, BYVAL TargetFrameName AS VARIANT PTR, _
    BYVAL PostData AS VARIANT PTR, BYVAL Headers AS VARIANT PTR, BYVAL pbCancel AS VARIANT_BOOL PTR)
DECLARE FUNCTION WebBrowser_HtmlDocumentEventsProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL dispId AS LONG, BYVAL pEvtObj AS IHTMLEventObj PTR) AS BOOLEAN
DECLARE FUNCTION DocHostUI_ShowContextMenuProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL dwID AS DWORD, BYVAL ppt AS POINT PTR, BYVAL pcmdtReserved AS IUnknown PTR, BYVAL pdispReserved AS IDispatch PTR) AS HRESULT
DECLARE FUNCTION DocHostUI_GetHostInfo (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pInfo AS DOCHOSTUIINFO PTR) AS HRESULT
DECLARE FUNCTION DocHostUI_TranslateAccelerator (BYVAL pWebCtx AS CWebCtx PTR, BYVAL lpMsg AS LPMSG, BYVAL pguidCmdGroup AS const GUID PTR, BYVAL nCmdID AS DWORD) AS HRESULT

' ========================================================================================
' Main
' ========================================================================================
FUNCTION WinMain (BYVAL hInstance AS HINSTANCE, _
                  BYVAL hPrevInstance AS HINSTANCE, _
                  BYVAL szCmdLine AS ZSTRING PTR, _
                  BYVAL nCmdShow AS LONG) AS LONG

   ' // Set process DPI aware
   ' // The recommended way is to use a manifest file
   AfxSetProcessDPIAware

   ' // Creates the main window
   DIM pWindow AS CWindow
   ' -or- DIM pWindow AS CWindow = "MyClassName" (use the name that you wish)
   DIM hwndMain AS HWND = pWindow.Create(NULL, "Embedded WebBrowser control", @WndProc)
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(750, 450)
   ' // Centers the window
   pWindow.Center

   ' // Add a status bar
   DIM hStatusbar AS HWND = pWindow.AddControl("Statusbar", , IDC_SATUSBAR)

   ' // Add a WebBrowser control
   DIM pwb AS CWebCtx = CWebCtx(@pWindow, IDC_WEBBROWSER, 0, 0, pWindow.ClientWidth, pWindow.ClientHeight)
   ' // Set web browser event callback procedures
   pwb.SetEventProc("StatusTextChange", @WebBrowser_StatusTextChangeProc)
   pwb.SetEventProc("DocumentComplete", @WebBrowser_DocumentCompleteProc)
   pwb.SetEventProc("BeforeNavigate2", @WebBrowser_BeforeNavigate2Proc)
   pwb.SetEventProc("HtmlDocumentEvents", @WebBrowser_HtmlDocumentEventsProc)
   ' // Set DocHostUI event callback procedures
   pwb.SetUIEventProc("ShowContextMenu", @DocHostUI_ShowContextMenuProc)
   pwb.SetUIEventProc("GetHostInfo", @DocHostUI_GetHostInfo)
   pwb.SetUIEventProc("TranslateAccelerator", @DocHostUI_TranslateAccelerator)

   ' // Navigate to a URL
   pwb.Navigate "http://com.it-berater.org/"
   ' // Set the focus in the page (the page must be fully loaded)
   pwb.SetFocus

   ' // Display the window
   ShowWindow(hWndMain, nCmdShow)
   UpdateWindow(hWndMain)

   ' // Dispatch Windows messages
   DIM uMsg AS MSG
   WHILE (GetMessageW(@uMsg, NULL, 0, 0) <> FALSE)
      IF AfxCAxHostForwardMessage(GetFocus, @uMsg) = FALSE THEN
         IF IsDialogMessageW(hWndMain, @uMsg) = 0 THEN
            TranslateMessage(@uMsg)
            DispatchMessageW(@uMsg)
         END IF
      END IF
   WEND
   FUNCTION = uMsg.wParam

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   SELECT CASE uMsg

      CASE WM_COMMAND
         SELECT CASE GET_WM_COMMAND_ID(wParam, lParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF GET_WM_COMMAND_CMD(wParam, lParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT

      CASE WM_SIZE
         ' // Optional resizing code
         IF wParam <> SIZE_MINIMIZED THEN
            ' // Resize the status bar
            DIM hStatusBar AS HWND = GetDlgItem(hwnd, IDC_SATUSBAR)
            SendMessage hStatusBar, uMsg, wParam, lParam
            ' // Calculate the size of the status bar
            DIM StatusBarHeight AS DWORD, rc AS RECT
            GetWindowRect hStatusBar, @rc
            StatusBarHeight = rc.Bottom - rc.Top
            ' // Retrieve a pointer to the CWindow class
            DIM pWindow AS CWindow PTR = AfxCWindowPtr(hwnd)
            ' // Move the position of the control
            IF pWindow THEN pWindow->MoveWindow GetDlgItem(hwnd, IDC_WEBBROWSER), _
               0, 0, pWindow->ClientWidth, pWindow->ClientHeight - StatusBarHeight / pWindow->ryRatio, CTRUE
         END IF

    	CASE WM_DESTROY
         ' // Ends the application by sending a WM_QUIT message
         PostQuitMessage(0)
         EXIT FUNCTION

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefWindowProcW(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Process the WebBrowser StatusTextChange event.
' ========================================================================================
SUB WebBrowser_StatusTextChangeProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pwszText AS WSTRING PTR)
   IF pwszText THEN StatusBar_SetText(GetDlgItem(GetParent(pWebCtx->hWindow), IDC_SATUSBAR), 0, pwszText)
END SUB
' ========================================================================================

' ========================================================================================
' Process the WebBrowser DocumentComplete event.
' ========================================================================================
SUB WebBrowser_DocumentCompleteProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pdisp AS IDispatch PTR, BYVAL vUrl AS VARIANT PTR)
   ' // The vUrl parameter is a VT_BYREF OR VT_BSTR variant
   ' // It can be a VT_BSTR variant or a VT_ARRAY OR VT_UI1 with a pidl
   DIM varUrl AS VARIANT
   VariantCopyInd(@varUrl, vUrl)
   StatusBar_SetText(GetDlgItem(GetParent(pWebCtx->hWindow), IDC_SATUSBAR), 0, "Document complete: " & AfxVarToStr(@varUrl))
   VariantClear(@varUrl)
END SUB
' ========================================================================================

' ========================================================================================
' Process the IDocHostUIHandler ShowContextMenu event.
' ========================================================================================
FUNCTION DocHostUI_ShowContextMenuProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL dwID AS DWORD, BYVAL ppt AS POINT PTR, BYVAL pcmdtReserved AS IUnknown PTR, BYVAL pdispReserved AS IDispatch PTR) AS HRESULT
   ' // This event notifies that the user has clicked the right mouse button to show the
   ' // context menu. We can anulate it returning %S_OK and show our context menu.
   ' // Do not allow to show the context menu
'   AfxMsg "Sorry! Context menu disabled"
'   RETURN S_OK
   ' // Host did not display its UI. MSHTML will display its UI.
   RETURN S_FALSE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Process the IDocHostUIHandler GetHostInfo event.
' ========================================================================================
PRIVATE FUNCTION DocHostUI_GetHostInfo (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pInfo AS DOCHOSTUIINFO PTR) AS HRESULT
   IF pInfo THEN
      pInfo->cbSize = SIZEOF(DOCHOSTUIINFO)
      pInfo->dwFlags = DOCHOSTUIFLAG_NO3DBORDER OR DOCHOSTUIFLAG_THEME OR DOCHOSTUIFLAG_DPI_AWARE
      pInfo->dwDoubleClick = DOCHOSTUIDBLCLK_DEFAULT
      pInfo->pchHostCss = NULL
      pInfo->pchHostNS = NULL
   END IF
   RETURN S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' Process the IDocHostUIHandler TranslateAccelerator event.
' ========================================================================================
PRIVATE FUNCTION DocHostUI_TranslateAccelerator (BYVAL pWebCtx AS CWebCtx PTR, BYVAL lpMsg AS LPMSG, BYVAL pguidCmdGroup AS const GUID PTR, BYVAL nCmdID AS DWORD) AS HRESULT

   IF lpMsg->message = WM_KEYDOWN THEN
      pWebCtx->SetElementInnerHtmlById "output", "ID: " & pWebCtx->GetActiveElementId & " KeyDown - Key: " & WSTR(lpMsg->wParam)
   END IF

   ' // When you use accelerator keys such as TAB, you may need to override the
   ' // default host behavior. The example shows how to do this.
    IF lpMsg->message = WM_KEYDOWN AND lpMsg->wParam = VK_TAB THEN
       RETURN S_FALSE   ' S_OK to disable tab navigation
    END IF
   ' // Return S_FALSE if you don't process the message
   RETURN S_FALSE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Fires before navigation occurs in the given object (on either a window or frameset element).
' ========================================================================================
SUB WebBrowser_BeforeNavigate2Proc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pdisp AS IDispatch PTR, _
    BYVAL vUrl AS VARIANT PTR, BYVAL Flags AS VARIANT PTR, BYVAL TargetFrameName AS VARIANT PTR, _
    BYVAL PostData AS VARIANT PTR, BYVAL Headers AS VARIANT PTR, BYVAL pbCancel AS VARIANT_BOOL PTR)

   OutputDebugStringW AfxVarToStr(vUrl)

   ' // Sample code to redirect navigation to another url
   IF AfxVarToStr(vUrl) = "http://com.it-berater.org/" THEN
      ' // Stop loading the page
      pWebCtx->BrowserPtr->Stop
      ' // Cancel the navigation operation
      *pbCancel = VARIANT_TRUE
      ' // Navigate to another new url
      DIM cvNewUrl AS CVAR = "http://www.planetsquires.com/protect/forum/index.php"
      pWebCtx->BrowserPtr->Navigate2(cvNewUrl)
   END IF

END SUB
' ========================================================================================

' ========================================================================================
' For cancelable document events return TRUE to indicate that Internet Explorer should
' perform its own event processing or FALSE to cancel the event.
' ========================================================================================
PRIVATE FUNCTION WebBrowser_HtmlDocumentEventsProc (BYVAL pWebCtx AS CWebCtx PTR, _
   BYVAL dispid AS LONG, BYVAL pEvtObj AS IHTMLEventObj PTR) AS BOOLEAN

'   SELECT CASE dispid
'
'      CASE DISPID_HTMLELEMENTEVENTS2_ONCLICK   ' // click event
'         ' // Get a reference to the element that has fired the event
'         DIM pElement AS IHTMLElement PTR
'         IF pEvtObj THEN pEvtObj->lpvtbl->get_srcElement(pEvtObj, @pElement)
'         IF pElement = NULL THEN EXIT FUNCTION
'         DIM bstrHtml AS AFX_BSTR   ' // Outer html
'         pElement->lpvtbl->get_outerHtml(pElement, @bstrHtml)
''         DIM bstrId AS AFX_BSTR   ' // identifier
''         pElement->lpvtbl->get_id(pElement, @bstrId)
'         pElement->lpvtbl->Release(pElement)
'         AfxMsg *bstrHtml
'         SysFreeString bstrHtml
'         RETURN TRUE
'
'   END SELECT

   RETURN FALSE

END FUNCTION
' ========================================================================================
````

# <a name="Advise"></a>Advise

Establishes a connection between a connection point object and the client's sink.

```
FUNCTION Advise () AS HRESULT
```

#### Return value

S_OK (0) or an error code.

#### Remarks

You don't have to call this method. The **CWebCtx** constructor calls it.

# <a name="AxHostPtr"></a>AxHostPtr

Returns a pointer to the **CAxHost** class.

```
FUNCTION AxHostPtr () AS CAxHost PTR
```

#### Return value

A pointer to the **CAxHost** class or NULL.

# <a name="BrowserPtr"></a>BrowserPtr

Returns a direct pointer to the **IWebBrowser2** interface of the hosted **WebBrowser** control.

```
FUNCTION BrowserPtr () AS Afx_IWebBrowser2 PTR
```

#### Return value

A pointer to the **IWebBrowser2** interface of the hosted **WebBrowser** control or NULL.

#### Remarks

Since it is a direct pointer, you don't have to release it calling the **Release** method.

# <a name="Busy"></a>Busy

Returns a boolean value indicating whether the object is engaged in a navigation or downloading operation.

```
PROPERTY Busy () AS BOOLEAN
```

#### Return value

A pointer to the **IWebBrowser2** interface of the hosted **WebBrowser** control or NULL.

#### Remarks

It returns TRUE if the control is busy; FALSE otherwise.

# <a name="CtrlID"></a>CtrlID

Returns the identifier of the container's window.

```
FUNCTION CtrlID () AS LONG
```

# <a name="Document"></a>Document

Retrieves the automation object of the active document, if any.

```
PROPERTY Document () AS IHtmlDocument2 PTR
```

### Return value

Returns one of the following values:

| Error code | Description |
| ---------- | ----------- |
| S_OK | The operation was successful. |
| E_FAIL | The operation failed. |
| E_INVALIDARG | One or more parameters are invalid. |
| E_NOINTERFACE | The interface is not supported. |

#### Remarks

When the active document is an HTML page, this property provides access to the contents of the HTML Document Object Model (DOM). Specifically, it returns an **IDispatch** interface pointer to the **HTMLDocument** component object class (coclass). The **HTMLDocument** coclass is functionally equivalent to the Dynamic HTML (DHTML) **document** object used in HTML script. It supports all the properties and methods necessary to access the entire contents of the active HTML document.

FreeBASIC programs can retrieve the Component Object Model (COM) interfaces **IHTMLDocument**, **IHTMLDocument2**, and **IHTMLDocument3** by calling **QueryInterface** on the **IDispatch** received from this property.

When other document types are active, such as a Microsoft Word document, this property returns the default **IDispatch** dispatch interface (dispinterface) pointer for the hosted document object. For Word documents, this would be functionally equivalent to the **Document** object in the Word object model.

# <a name="ExecWB"></a>ExecWB

Executes a command on an OLE object and returns the status of the command execution using the **IOleCommandTarget** interface.

```
FUNCTION ExecWB (BYVAL cmdID AS OLECMDID, BYVAL cmdexecopt AS OLECMDEXECOPT, _
   BYVAL pvaIn AS VARIANT PTR = NULL, BYVAL pvaOut AS VARIANT PTR = NULL) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *cmdID* | **OLECMDID** value that specifies the command to execute. |
| *cmdexecopt* | **OLECMDEXECOPT** value that specifies the command options. |
| *pvaIn* | inter to a **VARIANT** that contains command input arguments. The type of this **VARIANT** depends on the type of the command identifier. This argument can be NULL.  |
| *pvaOut* | In, Out. Pointer to a **VARIANT** that receives and specifies command output. The type of this **VARIANT** depends on the type of the command identifier. This argument can be NULL.  |

#### Return value

Returns S_OK (0) if successful, or an error value otherwise. 

# <a name="Find"></a>Find

Activates the find dialog.

```
FUNCTION Find () AS HRESULT
```

#### Return value

S_OK (0) or an HRESULT code.

# <a name="GetActiveElementId"></a>GetActiveElementId

Retrieves the ID of the active element (the object that has the focus when the parent document has focus).

```
FUNCTION GetActiveElementId () AS CWSTR
```

#### Return value

The ID of the active element, if any. If the element has not an identifier, it returns an empty string.

# <a name="GetBodyInnerHtml"></a>GetBodyInnerHtml

Returns a string that represents the text and html elements between the start and end body tags.

```
FUNCTION GetBodyInnerHtml () AS CWSTR
```

#### Return value

A string containing the html text.

# <a name="GetBodyInnerText"></a>GetBodyInnerText

Returns a string that represents the text between the start and end body tags without any associated HTML.

```
FUNCTION GetBodyInnerText () AS CWSTR
```

#### Return value

A string containing the text.

# <a name="GoBack"></a>GoBack

Navigates backward one item in the history list.

```
FUNCTION GoBack () AS HRESULT
```

#### Return value

Returns S_OK (0) if successful, or an error value otherwise.

#### Remarks

During a browsing session, the WebBrowser control and Microsoft Internet Explorer maintain a history list of all Web sites visited during a session (unless you specify the NAVNOHISTORY flag when using the Navigate method). Use the **CommandStateChange** event to check the enabled state of backward navigation. If the event's CSC_NAVIGATEBACK command is disabled, the beginning of the history list has been reached and the **GoBack** method should not be used.

# <a name="GetElementInnerHtmlById"></a>GetElementInnerHtmlById

Retrieves the HTML between the start and end tags of the object.

```
FUNCTION GetElementInnerHtmlById (BYREF cwsId AS CWSTR) AS CWSTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *cwsId* | The identifier. |

#### Return value

A string containing the HTML text.

#### Remarks

This method performs a case insensitive property search. If two or more attributes have the same name (differing only in uppercase and lowercase letters) this function retrieves values only for the last attribute created with this name, and ignores all other attributes with the same name.

# <a name="GetElementValueById"></a>GetElementValueById

Retrieves the value attribute of the specified attribute.

```
FUNCTION GetElementValueById (BYREF cwsId AS CWSTR) AS VARIANT
```

| Parameter  | Description |
| ---------- | ----------- |
| *cwsId* | The identifier. |

#### Return value

A variant containing the value as defined by the attribute.

#### Remarks

This method performs a case insensitive property search. If two or more attributes have the same name (differing only in uppercase and lowercase letters) this function retrieves values only for the last attribute created with this name, and ignores all other attributes with the same name.

# <a name="GoForward"></a>GoForward

Navigates forward one item in the history list.

```
FUNCTION GoForward () AS HRESULT
```

#### Return value

Returns S_OK (0) if successful, or an error value otherwise.

#### Remarks

During a browsing session, the WebBrowser control and Microsoft Internet Explorer application maintain a history list of all Web sites visited during a session (unless you specify the NAVNOHISTORY flag when using the Navigate method). Use the **CommandStateChange** event to check the enabled state of forward navigation. If the event's CSC_NAVIGATEFORWARD command is disabled, the end of the history list has been reached and the **GoForward** method should not be used.

# <a name="GoHome"></a>GoHome

Navigates to the current home or start page.

```
FUNCTION GoHome () AS HRESULT
```

#### Return value

Returns S_OK (0) if successful, or an error value otherwise.

#### Remarks

The user can indicate the URL to use for the home or start page either from Internet Options in Microsoft Internet Explorer or from Internet Properties in Control Panel.

# <a name="GoSearch"></a>GoSearch

Navigates to the current search page.

```
FUNCTION GoSearch () AS HRESULT
```

#### Return value

Returns S_OK (0) if successful, or an error value otherwise.

#### Remarks

The user can indicate the URL to use for the search page either from Internet Options in Microsoft Internet Explorer or from Internet Properties in Control Panel.

# <a name="hWindow"></a>hWindow

Returns the handle of the OLE Container hosting window.

```
FUNCTION hWindow () AS HWND
```

# <a name="InternetOptions"></a>InternetOptions

Activates the Internet options dialog.

```
FUNCTION InternetOptions () AS HRESULT
```

#### Return value

Returns S_OK (0) if successful, or an error value otherwise.

# <a name="LocationName"></a>LocationName

Retrieves the name of the resource that Microsoft Internet Explorer is currently displaying.

```
PROPERTY LocationName () AS CWSTR
```

#### Return value

The name of the resource that Microsoft Internet Explorer is currently displaying.

#### Remarks

If the resource is an HTML page on the World Wide Web, the name is the title of that page. If the resource is a folder or file on the network or local computer, the name is the full path of the folder or file in Universal Naming Convention (UNC) format.

# <a name="LocationURL"></a>LocationURL

Retrieves the URL of the resource that Microsoft Internet Explorer is currently displaying.

```
PROPERTY LocationURL () AS CWSTR
```

#### Return value

The URL of the resource that Microsoft Internet Explorer is currently displaying.

#### Remarks

If the resource is a folder or file on the network or local computer, the name is the full path of the folder or file in the Universal Naming Convention (UNC) format.

# <a name="Navigate"></a>Navigate

Returns the handle of the OLE Container hosting window.

```
FUNCTION Navigate (BYVAL pwszUrl AS WSTRING PTR, BYVAL Flags AS VARIANT PTR = NULL, _
   BYVAL TargetFrameName AS VARIANT PTR = NULL, BYVAL PostData AS VARIANT PTR = NULL, _
   BYVAL Headers AS VARIANT PTR = NULL) AS HRESULT
```
```
FUNCTION Navigate (BYVAL vUrl AS VARIANT PTR, BYVAL Flags AS VARIANT PTR = NULL, _
   BYVAL TargetFrameName AS VARIANT PTR = NULL, BYVAL PostData AS VARIANT PTR = NULL, _
   BYVAL Headers AS VARIANT PTR = NULL) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszUrl* | A variable or expression that evaluates to the URL of the resource to display or the full path to the file location. |
| *vUrl* | A variable or expression that evaluates to the URL of the resource to display, the full path to the file location, or a PIDL that represents a folder in the Shell namespace. |
| *Flags* | Optional. A constant or value that specifies a combination of the values defined by the **BrowserNavConstants** enumeration. |
| *TargetFrameName* | Optional. Case-sensitive string expression that evaluates to the name of the frame in which to display the resource. The possible values for this parameter are:<br>**\_blank**: Load the link into a new unnamed window.<br>**\_parent**: Load the link into the immediate parent of the document the link is in.<br>**\_self**: Load the link into the same window the link was clicked in.<br>**\_top**: Load the link into the full body of the current window.<br>**WindowName**: A named HTML frame. If no frame or window exists that matches the specified target name, a new window is opened for the specified link. |
| *PostData* | Optional. Data that is sent to the server as part of a HTTP POST transaction. A POST transaction typically is used to send data collected by an HTML form. If this parameter does not specify any POST data, this method issues an HTTP GET transaction. This parameter is ignored if URL is not an HTTP (or HTTPS) URL. |
| *Headers* | Optional. A String that contains additional HTTP headers to send to the server. These headers are added to the default Internet Explorer headers. For example, headers can specify the action required of the server, the type of data being passed to the server, or a status code. This parameter is ignored if the URL is not an HTTP (or HTTPS)  URL. |

### BrowserNavConstants Enumeration

Contains values used by the **Navigate2** method.

| Flag       | Description |
| ---------- | ----------- |
| **navOpenInNewWindow** | Open the resource or file in a new window. |
| **navNoHistory** | Do not add the resource or file to the history list. The new page replaces the current page in the list. |
| **navNoReadFromCache** | Not implemented. |
| **navNoWriteToCache** | Not implemented. |
| **navAllowAutosearch** | If the navigation fails, the autosearch functionality attempts to navigate common root domains (.com, .edu, and so on). If this also fails, the URL is passed to a search engine. |
| **navBrowserBar** | Causes the current Explorer Bar to navigate to the given item, if possible. |
| **navHyperlink** | Microsoft Internet Explorer 6 for Windows XP Service Pack 2 (SP2) and later. If the navigation fails when a hyperlink is being followed, this constant specifies that the resource should then be bound to the moniker using the BINDF_HYPERLINK flag. |
| **navEnforceRestricted** | Internet Explorer 6 for Windows XP SP2 and later. Force the URL into the restricted zone. |
| **navNewWindowsManaged** | Internet Explorer 6 for Windows XP SP2 and later. Use the default Popup Manager to block pop-up windows. |
| **navUntrustedForDownload** | Internet Explorer 6 for Windows XP SP2 and later. Block files that normally trigger a file download dialog box.|
| **navTrustedForActiveX** | Internet Explorer 6 for Windows XP SP2 and later. Prompt for the installation of Microsoft ActiveX controls. |
| **navOpenInNewTab** | Windows Internet Explorer 7. Open the resource or file in a new tab. Allow the destination window to come to the foreground, if necessary. |
| **navOpenInBackgroundTab** | Internet Explorer 7. Open the resource or file in a new background tab; the currently active window and/or tab remains open on top. |
| **navKeepWordWheelText** | Internet Explorer 7. Maintain state for dynamic navigation based on the filter string entered in the search band text box (wordwheel). Restore the wordwheel text when the navigation completes. |
| **navVirtualTab** | Internet Explorer 8. Open the resource as a replacement for the current or target tab. The existing tab is closed while the new tab takes its place in the tab bar and replaces it in the tab group, if any. Browser history is copied forward to the new tab. On Windows Vista, this flag is implied if the navigation would cross integrity levels and **navOpenInNewTab**, **navOpenInBackgroundTab**, or **navOpenInNewWindow** is not specified. |
| **navBlockRedirectsXDomain** | Internet Explorer 8. Block cross-domain redirect requests. The navigation triggers the RedirectXDomainBlocked event if blocked. |
| **navOpenNewForegroundTab** | Internet Explorer 8 and later. Open the resource in a new tab that becomes the foreground tab. |

#### Return value

Returns one of the following values:

| Error code | Description |
| ---------- | ----------- |
| S_OK | The operation was successful. |
| E_FAIL | The operation failed. |
| E_INVALIDARG | One or more parameters are invalid. |
| E_OUTOFMEMORY | Out of memory. |

# <a name="PageProperties"></a>PageProperties

Activates the properties dialog.

```
FUNCTION PageProperties () AS HRESULT
```

#### Return value

S_OK (0) or an HRESULT code.

# <a name="PageSetup"></a>PageSetup

Activates the page setup dialog.

```
FUNCTION PageSetup () AS HRESULT
```

#### Return value

S_OK (0) or an HRESULT code.

# <a name="PrintPage"></a>PrintPage

Activates the print dialog.

```
FUNCTION PrintPage () AS HRESULT
```

#### Return value

S_OK (0) or an HRESULT code.

# <a name="PrintPreview"></a>PrintPreview

Activates the print preview dialog.

```
FUNCTION PrintPreview () AS HRESULT
```

#### Return value

S_OK (0) or an HRESULT code.

# <a name="QueryStatusWB"></a>QueryStatusWB

Queries the OLE object for the status of commands using the **QueryStatus** method of the **IOleCommandTarget** interface.

```
FUNCTION QueryStatusWB (BYVAL cmdID AS OLECMDID) AS OLECMDF
```

| Parameter  | Description |
| ---------- | ----------- |
| *cmdID* | **OLECMDID** value of the command for which the caller needs status information. |

#### Return value

The status of the command.

# <a name="ReadyState"></a>ReadyState

Retrieves the ready state of the object.

```
PROPERTY ReadyState () AS tagREADYSTATE
```

#### Return value

The ready state of the object.

# <a name="Refresh"></a>Refresh

Reloads the file that is currently displayed in the object.

```
FUNCTION Refresh () AS HRESULT
```

#### Return value

Returns S_OK (0) if successful, or E_FAIL otherwise.

#### Remarks

The WebBrowser control and InternetExplorer application store Web pages from recently visited sites in cached memory on the user's hard disk. This saves time when revisiting a site by reloading the page from the local disk rather than downloading it again across the network from the remote HTTP server. You can force the WebBrowser control and WebBrowser application to redownload a page by using the **Refresh** or **Refresh2** methods of the **IWebBrowser2** interface to ensure that you are viewing the most current version of the page. Also, you can disable the cache from being used by specifying the **navNoReadFromCache** and **navNoWriteToCache** flags when calling the **Navigate2** method of the **IWebBrowser2** interface. 

# <a name="Refresh2"></a>Refresh2

Reloads the file that is currently displayed in the object. Unlike **Refresh**, this method contains a parameter that specifies the refresh level.

```
FUNCTION Refresh2 (BYVAL nLevel AS RefreshConstants) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *nLevel* | One of the **RefreshConstants** enumeration values. |

### RefreshConstants enumeration

| Constant   | Description |
| ---------- | ----------- |
| REFRESH_NORMAL (0) | Perform a lightweight refresh that does not include the pragma:nocache header. The pragma:nocache header tells the server not to return a cached copy. This can cause problems with some servers. |
| REFRESH_IFEXPIRED (1) | Only refresh if the page has expired. Do not include the pragma:nocache header. |
| REFRESH_COMPLETELY (3) | Perform a full refresh, including the pragma:nocache header. Using this option is the same as calling the Refresh method. |

#### Return value

Returns S_OK (0) if successful, or E_FAIL otherwise.

#### Remarks

The "pragma:nocache" header tells the server not to return a cached copy. This ensures that the information is as fresh as possible. Browsers typically send this header when the user selects refresh, but the header can cause problems for some servers.

# <a name="RegisterAsBrowser"></a>RegisterAsBrowser

Sets or retrieves a value that indicates whether the object is registered as a top-level browser for target name resolution.

```
PROPERTY RegisterAsBrowser () AS BOOLEAN
PROPERTY RegisterAsBrowser (BYVAL bRegister AS BOOLEAN)
```

| Parameter  | Description |
| ---------- | ----------- |
| *bRegister* | True of False. |

# <a name="RegisterAsDropTarget"></a>RegisterAsDropTarget

Sets or retrieves a value that indicates whether the object is registered as a drop target for navigation.

```
PROPERTY RegisterAsDropTarget () AS BOOLEAN
PROPERTY RegisterAsDropTarget (BYVAL bRegister AS BOOLEAN)
```

| Parameter  | Description |
| ---------- | ----------- |
| *bRegister* | True of False. |

# <a name="SaveAs"></a>SaveAs

Activates the save file dialog.

```
FUNCTION SaveAs () AS HRESULT
```

#### Return value

S_OK (0) or an HRESULT code.

# <a name="SetElementFocusById"></a>SetElementFocusById

Sets the HTML between the start and end tags of the object.

```
FUNCTION SetElementFocusById (BYREF cwsId AS CWSTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *cwsId* | The identifier. |

#### Return value

S_OK (0) or an HRESULT code.

# <a name="SetElementInnerHtmlById"></a>SetElementInnerHtmlById

Sets the HTML between the start and end tags of the object.

```
FUNCTION SetElementInnerHtmlById (BYREF cwsId AS CWSTR, BYREF cwsHtml AS CWSTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *cwsId* | The identifier. |
| *cwsHtml* | The html text to set. |

#### Return value

S_OK (0) or an HRESULT code.

#### Remarks

This method performs a case insensitive property search. If two or more attributes have the same name (differing only in uppercase and lowercase letters) this function sets values only for the last attribute created with this name, and ignores all other attributes with the same name.

# <a name="SetElementValueById"></a>SetElementValueById

Sets the value attribute of the specified identifier.

```
FUNCTION SetElementValueById (BYREF cwsId AS CWSTR, BYVAL vValue AS VARIANT) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *cwsId* | The identifier. |
| *vValue* | Variant that specifies the string, number, or Boolean to assign to the attribute. |

#### Return value

S_OK (0) or an HRESULT code.

#### Remarks

This method performs a case insensitive property search. If two or more attributes have the same name (differing only in uppercase and lowercase letters) this function sets values only for the last attribute created with this name, and ignores all other attributes with the same name.

# <a name="SetEventProc"></a>SetEventProc

Sets pointers to user implemented callback procedures to receive events of the hosted WebBrowser control.

```
FUNCTION SetEventProc (BYVAL pwszEventName AS WSTRING PTR, BYVAL pProc AS ANY PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszEventName* | The name of the event. |
| *pProc* | The address of the callback procedure. |

### Event Names

| Parameter  |
| ---------- |
| StatusTextChange |
| DownloadComplete |
| CommandStateChange |
| DownloadBegin |
| ProgressChange |
| PropertyChange |
| TitleChange |
| PrintTemplateInstantiation |
| PrintTemplateTeardown |
| BeforeNavigate2 |
| NewWindow2 |
| NavigateComplete2 |
| OnVisible |
| OnToolBar |
| OnMenuBar |
| OnStatusBar |
| OnFullScreen |
| DocumentComplete |
| OnTheaterMode |
| WindowSetResizable |
| WindowClosing |
| WindowSetLeft |
| WindowSetTop |
| WindowSetWidth |
| WindowSetHeight |
| ClientToHostWindow |
| SetSecureLockIcon |
| FileDownload |
| NavigateError |
| PrivacyImpactedStateChange |
| NewWindow3 |
| SetPhishingFilterStatus |
| WindowStateChanged |
| HtmlDocumentEvents |

#### Return value

S_OK (0) or an HRESULT code.

### Function callback prototypes

```
SUB BeforeNavigate2Proc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pdisp AS IDispatch PTR, _
    BYVAL vUrl AS VARIANT PTR, BYVAL Flags AS VARIANT PTR, BYVAL TargetFrameName AS VARIANT PTR, _
    BYVAL PostData AS VARIANT PTR, BYVAL Headers AS VARIANT PTR, BYVAL pbCancel AS VARIANT_BOOL PTR)
SUB ClientToHostWindowProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL CX AS LONG PTR, BYVAL CY AS LONG PTR)
SUB CommandStateChangeProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL nCommand AS LONG, BYVAL fEnable AS VARIANT_BOOL)
SUB DocumentCompleteProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pdisp AS IDispatch PTR, BYVAL vUrl AS VARIANT PTR)
SUB DownloadBeginProc (BYVAL pWebCtx AS CWebCtx PTR)
SUB DownloadCompleteProc (BYVAL pWebCtx AS CWebCtx PTR)
SUB FileDownloadProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pbCancel AS VARIANT_BOOL PTR)
SUB NavigateComplete2Proc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pdisp AS IDispatch PTR, BYVAL vUrl AS VARIANT PTR)
SUB NavigateErrorProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pdisp AS IDispatch PTR, _
    BYVAL vUrl AS VARIANT PTR, BYVAL vFrame AS VARIANT PTR, BYVAL StatusCode AS VARIANT PTR, BYVAL pbCancel AS VARIANT_BOOL PTR)
SUB NewWindow3Proc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL ppdispVal AS IDispatch PTR PTR, _
    BYVAL pbCancel AS VARIANT_BOOL PTR, BYVAL dwFlags AS ULONG, BYVAL pwszUrlContext AS WSTRING PTR, BYVAL pwszUrl AS WSTRING PTR)
SUB OnVisibleProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL bVisible AS VARIANT_BOOL)
SUB PrintTemplateInstantiationProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pdisp AS IDispatch PTR)
SUB PrintTemplateTeardownProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pdisp AS IDispatch PTR)
SUB PrivacyImpactedStateChangeProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL bImpacted AS VARIANT_BOOL)
SUB ProgressChangeProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL Progress AS LONG, BYVAL ProgressMax AS LONG)
SUB PropertyChangeProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pwszProperty AS WSTRING PTR)
SUB SetSecureLockIconProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL SecureLockIcon AS LONG)
SUB StatusTextChangeProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pwszText AS WSTRING PTR)
SUB TitleChangeProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pwszText AS WSTRING PTR)
SUB WindowClosingProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL IsChildWindow AS VARIANT_BOOL, BYVAL pbCancel AS VARIANT_BOOL PTR)
SUB WindowSetHeightProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL nHeight AS LONG)
SUB WindowSetLeftProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL nLenft AS LONG)
SUB WindowSetResizableProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL bResizable AS VARIANT_BOOL)
SUB WindowSetTopProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL nTop AS LONG)
SUB WindowSetWidthProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL nWidth AS LONG)
SUB WindowStateChangedProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL dwFlags AS LONG, BYVAL dwValidFlagsMask AS LONG)
FUNCTION HtmlDocumentEventsProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL dispid AS LONG, BYVAL pEvtObj AS IHTMLEventObj) AS BOOLEAN
```
#### Usage example

```
' // Add a WebBrowser control
DIM pwb AS CWebCtx = CWebCtx(@pWindow, IDC_WEBBROWSER, 0, 0, pWindow.ClientWidth, pWindow.ClientHeight)
' // Set web browser event callback procedures
pwb.SetEventProc("StatusTextChange", @WebBrowser_StatusTextChangeProc)
pwb.SetEventProc("DocumentComplete", @WebBrowser_DocumentCompleteProc)
pwb.SetEventProc("BeforeNavigate2", @WebBrowser_BeforeNavigate2Proc)
pwb.SetEventProc("HtmlDocumentEvents", @WebBrowser_HtmlDocumentEventsProc)
' // Set DocHostUI event callback procedures
pwb.SetUIEventProc("ShowContextMenu", @DocHostUI_ShowContextMenuProc)
pwb.SetUIEventProc("GetHostInfo", @DocHostUI_GetHostInfo)
pwb.SetUIEventProc("TranslateAccelerator", @DocHostUI_TranslateAccelerator)

' ========================================================================================
' Process the WebBrowser StatusTextChange event.
' ========================================================================================
SUB WebBrowser_StatusTextChangeProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pwszText AS WSTRING PTR)
   IF pwszText THEN StatusBar_SetText(GetDlgItem(GetParent(pWebCtx->hWindow), IDC_SATUSBAR), 0, pwszText)
END SUB
' ========================================================================================

' ========================================================================================
' Process the WebBrowser DocumentComplete event.
' ========================================================================================
SUB WebBrowser_DocumentCompleteProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pdisp AS IDispatch PTR, BYVAL vUrl AS VARIANT PTR)
   ' // The vUrl parameter is a VT_BYREF OR VT_BSTR variant
   ' // It can be a VT_BSTR variant or a VT_ARRAY OR VT_UI1 with a pidl
   DIM varUrl AS VARIANT
   VariantCopyInd(@varUrl, vUrl)
   StatusBar_SetText(GetDlgItem(GetParent(pWebCtx->hWindow), IDC_SATUSBAR), 0, "Document complete: " & AfxVarToStr(@varUrl))
   VariantClear(@varUrl)
END SUB
' ========================================================================================

' ========================================================================================
' Process the IDocHostUIHandler ShowContextMenu event.
' ========================================================================================
FUNCTION DocHostUI_ShowContextMenuProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL dwID AS DWORD, BYVAL ppt AS POINT PTR, BYVAL pcmdtReserved AS IUnknown PTR, BYVAL pdispReserved AS IDispatch PTR) AS HRESULT
   ' // This event notifies that the user has clicked the right mouse button to show the
   ' // context menu. We can anulate it returning %S_OK and show our context menu.
   ' // Do not allow to show the context menu
'   AfxMsg "Sorry! Context menu disabled"
'   RETURN S_OK
   ' // Host did not display its UI. MSHTML will display its UI.
   RETURN S_FALSE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Process the IDocHostUIHandler GetHostInfo event.
' ========================================================================================
PRIVATE FUNCTION DocHostUI_GetHostInfo (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pInfo AS DOCHOSTUIINFO PTR) AS HRESULT
   IF pInfo THEN
      pInfo->cbSize = SIZEOF(DOCHOSTUIINFO)
      pInfo->dwFlags = DOCHOSTUIFLAG_NO3DBORDER OR DOCHOSTUIFLAG_THEME OR DOCHOSTUIFLAG_DPI_AWARE
      pInfo->dwDoubleClick = DOCHOSTUIDBLCLK_DEFAULT
      pInfo->pchHostCss = NULL
      pInfo->pchHostNS = NULL
   END IF
   RETURN S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' Process the IDocHostUIHandler TranslateAccelerator event.
' ========================================================================================
PRIVATE FUNCTION DocHostUI_TranslateAccelerator (BYVAL pWebCtx AS CWebCtx PTR, BYVAL lpMsg AS LPMSG, BYVAL pguidCmdGroup AS const GUID PTR, BYVAL nCmdID AS DWORD) AS HRESULT

   IF lpMsg->message = WM_KEYDOWN THEN
      pWebCtx->SetElementInnerHtmlById "output", "ID: " & pWebCtx->GetActiveElementId & " KeyDown - Key: " & WSTR(lpMsg->wParam)
   END IF

   ' // When you use accelerator keys such as TAB, you may need to override the
   ' // default host behavior. The example shows how to do this.
    IF lpMsg->message = WM_KEYDOWN AND lpMsg->wParam = VK_TAB THEN
       RETURN S_FALSE   ' S_OK to disable tab navigation
    END IF
   ' // Return S_FALSE if you don't process the message
   RETURN S_FALSE
END FUNCTION
' ========================================================================================
```

# <a name="SetFocus"></a>SetFocus

Sets the focus in the hosted document (usually an html page).

```
FUNCTION SetFocus () AS HRESULT
```

#### Return value

Returns S_OK (0) to indicate that the operation was successful or an error code (E_NOINTERFACE).

# <a name="SetUIEventProc"></a>SetUIEventProc

Sets pointers to user implemented callback procedures to receive events of the **IDocHostUIHandler2** interface.

```
FUNCTION SetUIEventProc (BYVAL pwszEventName AS WSTRING PTR, BYVAL pProc AS ANY PTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszEventName* | The name of the event. |
| *pProc* | The address of the callback procedure. |

| Parameter  |
| ---------- |
| ShowContextMenu |
| GetHostInfo |
| ShowUI |
| HideUI |
| UpdateUI |
| EnableModeless |
| OnDocWindowActivate |
| OnFrameWindowActivate |
| ResizeBorder |
| TranslateAccelerator |
| GetOptionKeyPath |
| GetDropTarget |
| GetExternal |
| TranslateUrl |
| FilterDataObject |
| GetOverrideKeyPath |

### Function callback prototypes

```
FUNCTION EnableModelessProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL fEnable AS WINBOOL) AS HRESULT
FUNCTION FilterDataObjectProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pDO AS IDataObject PTR, BYVAL ppDORet AS IDataObject PTR PTR) AS HRESULT
FUNCTION GetDropTargetProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pDropTarget AS IDropTarget PTR, BYVAL ppDropTarget AS IDropTarget PTR PTR) AS HRESULT
FUNCTION GetExternalProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL ppDispatch AS IDispatch PTR PTR) AS HRESULT
FUNCTION GetHostInfoProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pInfo AS DOCHOSTUIINFO PTR) AS HRESULT
FUNCTION GetOptionKeyPathProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pchKey AS LPOLESTR PTR, BYVAL dw AS DWORD) AS HRESULT
FUNCTION GetOverrideKeyPathProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pchKey AS LPOLESTR PTR, BYVAL dw AS DWORD) AS HRESULT
FUNCTION HideUIProc (BYVAL pWebCtx AS CWebCtx PTR) AS HRESULT
FUNCTION OnDocWindowActivateProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL fActivate AS WINBOOL) AS HRESULT
FUNCTION OnFrameWindowActivateProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL fActivate AS WINBOOL) AS HRESULT
FUNCTION ResizeBorderProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL prcBorder AS LPCRECT, BYVAL pUIWindow AS IOleInPlaceUIWindow PTR, BYVAL frameWindow AS WINBOOL) AS HRESULT
FUNCTION ShowContextMenuProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL dwID AS DWORD, BYVAL ppt AS POINT PTR, BYVAL pcmdtReserved AS IUnknown PTR, BYVAL pdispReserved AS IDispatch PTR) AS HRESULT
FUNCTION ShowUIProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL dwID AS DWORD, BYVAL pActiveObject AS IOleInPlaceActiveObject PTR, BYVAL pCommandTarget AS IOleCommandTarget PTR, BYVAL pFrame AS IOleInPlaceFrame PTR, BYVAL pDoc AS IOleInPlaceUIWindow PTR) AS HRESULT
FUNCTION TranslateAcceleratorProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL lpMsg AS LPMSG, BYVAL pguidCmdGroup AS const GUID PTR, BYVAL nCmdID AS DWORD) AS HRESULT
FUNCTION TranslateUrlProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL dwTranslate AS DWORD, BYVAL pchURLIn AS LPWSTR, BYVAL ppchURLOut AS LPWSTR PTR) AS HRESULT
FUNCTION UpdateUIProc (BYVAL pWebCtx AS CWebCtx PTR) AS HRESULT
```

#### Usage example

```
' // Add a WebBrowser control
DIM pwb AS CWebCtx = CWebCtx(@pWindow, IDC_WEBBROWSER, 0, 0, pWindow.ClientWidth, pWindow.ClientHeight)
' // Set web browser event callback procedures
pwb.SetEventProc("StatusTextChange", @WebBrowser_StatusTextChangeProc)
pwb.SetEventProc("DocumentComplete", @WebBrowser_DocumentCompleteProc)
pwb.SetEventProc("BeforeNavigate2", @WebBrowser_BeforeNavigate2Proc)
pwb.SetEventProc("HtmlDocumentEvents", @WebBrowser_HtmlDocumentEventsProc)
' // Set DocHostUI event callback procedures
pwb.SetUIEventProc("ShowContextMenu", @DocHostUI_ShowContextMenuProc)
pwb.SetUIEventProc("GetHostInfo", @DocHostUI_GetHostInfo)
pwb.SetUIEventProc("TranslateAccelerator", @DocHostUI_TranslateAccelerator)

' ========================================================================================
' Process the WebBrowser StatusTextChange event.
' ========================================================================================
SUB WebBrowser_StatusTextChangeProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pwszText AS WSTRING PTR)
   IF pwszText THEN StatusBar_SetText(GetDlgItem(GetParent(pWebCtx->hWindow), IDC_SATUSBAR), 0, pwszText)
END SUB
' ========================================================================================

' ========================================================================================
' Process the WebBrowser DocumentComplete event.
' ========================================================================================
SUB WebBrowser_DocumentCompleteProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pdisp AS IDispatch PTR, BYVAL vUrl AS VARIANT PTR)
   ' // The vUrl parameter is a VT_BYREF OR VT_BSTR variant
   ' // It can be a VT_BSTR variant or a VT_ARRAY OR VT_UI1 with a pidl
   DIM varUrl AS VARIANT
   VariantCopyInd(@varUrl, vUrl)
   StatusBar_SetText(GetDlgItem(GetParent(pWebCtx->hWindow), IDC_SATUSBAR), 0, "Document complete: " & AfxVarToStr(@varUrl))
   VariantClear(@varUrl)
END SUB
' ========================================================================================

' ========================================================================================
' Process the IDocHostUIHandler ShowContextMenu event.
' ========================================================================================
FUNCTION DocHostUI_ShowContextMenuProc (BYVAL pWebCtx AS CWebCtx PTR, BYVAL dwID AS DWORD, BYVAL ppt AS POINT PTR, BYVAL pcmdtReserved AS IUnknown PTR, BYVAL pdispReserved AS IDispatch PTR) AS HRESULT
   ' // This event notifies that the user has clicked the right mouse button to show the
   ' // context menu. We can anulate it returning %S_OK and show our context menu.
   ' // Do not allow to show the context menu
'   AfxMsg "Sorry! Context menu disabled"
'   RETURN S_OK
   ' // Host did not display its UI. MSHTML will display its UI.
   RETURN S_FALSE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Process the IDocHostUIHandler GetHostInfo event.
' ========================================================================================
PRIVATE FUNCTION DocHostUI_GetHostInfo (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pInfo AS DOCHOSTUIINFO PTR) AS HRESULT
   IF pInfo THEN
      pInfo->cbSize = SIZEOF(DOCHOSTUIINFO)
      pInfo->dwFlags = DOCHOSTUIFLAG_NO3DBORDER OR DOCHOSTUIFLAG_THEME OR DOCHOSTUIFLAG_DPI_AWARE
      pInfo->dwDoubleClick = DOCHOSTUIDBLCLK_DEFAULT
      pInfo->pchHostCss = NULL
      pInfo->pchHostNS = NULL
   END IF
   RETURN S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' Process the IDocHostUIHandler TranslateAccelerator event.
' ========================================================================================
PRIVATE FUNCTION DocHostUI_TranslateAccelerator (BYVAL pWebCtx AS CWebCtx PTR, BYVAL lpMsg AS LPMSG, BYVAL pguidCmdGroup AS const GUID PTR, BYVAL nCmdID AS DWORD) AS HRESULT

   IF lpMsg->message = WM_KEYDOWN THEN
      pWebCtx->SetElementInnerHtmlById "output", "ID: " & pWebCtx->GetActiveElementId & " KeyDown - Key: " & WSTR(lpMsg->wParam)
   END IF

   ' // When you use accelerator keys such as TAB, you may need to override the
   ' // default host behavior. The example shows how to do this.
    IF lpMsg->message = WM_KEYDOWN AND lpMsg->wParam = VK_TAB THEN
       RETURN S_FALSE   ' S_OK to disable tab navigation
    END IF
   ' // Return S_FALSE if you don't process the message
   RETURN S_FALSE
END FUNCTION
' ========================================================================================
```

# <a name="SetUIHandler"></a>SetUIHandler

Sets our implementation of the **IDocHostUIHandler** interface to customize the WebBrowser.

```
FUNCTION SetUIHandler () AS HRESULT
```

#### Remarks

You don't have to call this method. The **CWebCtx** constructor calls it.

# <a name="ShowSource"></a>ShowSource

Displays the source code of the page in an instance of NotePad.

```
FUNCTION ShowSource () AS HRESULT
```

#### Return value

S_OK (0) or an HRESULT code.

# <a name="Silent"></a>Silent

Sets or gets a value that indicates whether the object can display dialog boxes.

```
PROPERTY Silent (BYVAL bSilent AS VARIANT_BOOL)
PROPERTY Silent () AS VARIANT_BOOL
```

| Parameter  | Description |
| ---------- | ----------- |
| *bSilent* | VARIANT_FALSE Dialog boxes and messages can be displayed.<br>VARIANT_TRUE  Dialog boxes are not displayed. |

#### Return value

VARIANT_TRUE or VARIANT_FALSE.

# <a name="Stop"></a>Stop

Cancels any pending navigation or download operation and stops any dynamic page elements, such as background sounds and animations.

```
FUNCTION Stop () AS HRESULT
```

#### Return value

Returns S_OK (0) to indicate that the operation was successful.

# <a name="Unadvise"></a>Unadvise

Releases the events connection.

```
FUNCTION Unadvise () AS HRESULT
```

#### Return value

Returns S_OK (0) or an HRESULT code.

#### Remarks

You don't have to call this method. The **CWebCtx** destructor calls it.

# <a name="WaitForPageLoad"></a>WaitForPageLoad

Waits until the page had been fully downloaded or te timeout has expired.

```
FUNCTION FUNCTION WaitForPageLoad (BYVAL dbTimeout AS DOUBLE = 10) AS tagREADYSTATE
```

| Parameter  | Description |
| ---------- | ----------- |
| *dbTimeout* | Optional. Timeout in seconds. Default value: 10 seconds. |

#### Return value

| Value      | Description |
| ---------- | ----------- |
| READYSTATE_UNINITIALIZED = 0 | Default initialization state. |
| READYSTATE_LOADING = 1 | Object is currently loading its properties. |
| READYSTATE_LOADED = 2 | Object has been initialized. |
| READYSTATE_INTERACTIVE = 3 | Object is interactive, but not all of its data is available. |
| READYSTATE_COMPLETE = 4 | Object has received all of its data. |

# <a name="WriteHtml"></a>WriteHtml

Writes one or more HTML expressions to a document.

```
FUNCTION WriteHtml (BYREF cwsHtml AS CWSTR, BYVAL cr AS BOOLEAN = FALSE) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *cwsHtml* | Text and HTML tags to write. |
| *cr* | Optional. Write the HTML text followed by a carriage return. |

#### Return value

S_OK if successful, or an error value otherwise.

#### Example

```
Example

' ########################################################################################
' Microsoft Windows
' Contents: WebBrowser with an animated GIF
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2017 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#define UNICODE
#INCLUDE ONCE "Afx/CWindow.inc"
#INCLUDE ONCE "Afx/CWebBrowser/CWebBrowser.inc"
USING Afx

CONST IDC_WEBBROWSER = 1001

DECLARE FUNCTION WinMain (BYVAL hInstance AS HINSTANCE, _
                          BYVAL hPrevInstance AS HINSTANCE, _
                          BYVAL szCmdLine AS ZSTRING PTR, _
                          BYVAL nCmdShow AS LONG) AS LONG

   END WinMain(GetModuleHandleW(NULL), NULL, COMMAND(), SW_NORMAL)

DECLARE FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

' ========================================================================================
' Displays an animated gif file
' ========================================================================================
PRIVATE FUNCTION LoadGif (BYREF wszName AS WSTRING, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, BYREF wszAltName AS WSTRING = "") AS STRING

   DIM s AS STRING
   s  = "<!DOCTYPE html>"
   s += "<html>"
   s += "<head>"
   s += "<meta http-equiv='MSThemeCompatible' content='yes'>"
   s += "<title>Animated gif</title>"
   s += "</head>"
   s += "<body scroll='no' style='MARGIN: 0px 0px 0px 0px'>"
   s += "<img src='" & wszName & "' alt=' " & wszAltName & _
         "' style='width:" & STR(nWidth) & "px;height:" & STR(nHeight) & "px;'>"
   s += "</body>"
   s += "</html>"

   FUNCTION = s

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main
' ========================================================================================
FUNCTION WinMain (BYVAL hInstance AS HINSTANCE, _
                  BYVAL hPrevInstance AS HINSTANCE, _
                  BYVAL szCmdLine AS ZSTRING PTR, _
                  BYVAL nCmdShow AS LONG) AS LONG

   ' // Set process DPI aware
   ' // The recommended way is to use a manifest file
   AfxSetProcessDPIAware

   ' // Creates the main window
   DIM pWindow AS CWindow
   ' -or- DIM pWindow AS CWindow = "MyClassName" (use the name that you wish)
   DIM hwndMain AS HWND = pWindow.Create(NULL, "WebBrowser control - Animated gif", @WndProc)
   ' // Change the window style
   pWindow.WindowStyle = WS_OVERLAPPED OR WS_CAPTION OR WS_SYSMENU
   ' // Sizes it by setting the wanted width and height of its client area
   pWindow.SetClientSize(400, 300)
   ' // Centers the window
   pWindow.Center

   ' // Add a WebBrowser control
   DIM pwb AS CWebBrowser = CWebBrowser(@pWindow, IDC_WEBBROWSER, 0, 0, pWindow.ClientWidth, pWindow.ClientHeight)
   ' // Set the IDocHostUIHandler interface
   pwb.SetUIHandler

   ' // Load the gif file --> change the path to your file
   ' // The file can be located anywhere and you can use an url if it is located in the web
   DIM s AS STRING = LoadGif(ExePath & "\Circles-3.gif", _
       pWindow.ClientWidth, pWindow.ClientHeight, "Circles")
   ' // Write the script to the web page
   pwb.WriteHtml(s)

   ' // Displays the window and dispatches the Windows messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   SELECT CASE uMsg

      CASE WM_COMMAND
         SELECT CASE LOWORD(wParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application by sending an WM_CLOSE message
               IF HIWORD(wParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT

    	CASE WM_DESTROY
         ' // Ends the application by sending a WM_QUIT message
         PostQuitMessage(0)
         EXIT FUNCTION

   END SELECT

   ' // Default processing of Windows messages
   FUNCTION = DefWindowProcW(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
```

# <a name="AfxGetBrowserPtr"></a>AfxGetBrowserPtr

Returns a pointer to the hosted WebBrowser control given the handle of the form, or any control in the form, and the control identifier.

```
FUNCTION AfxGetBrowserPtr (BYVAL hwnd AS HWND, BYVAL cID AS WORD) AS Afx_IWebBrowser2 PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle of the window of the form or any of its child controls. |
| *cID* | Identifier of the control, e.g. IDC_WEBBROWSER. |

#### Return value

A pointer to the **IWeBbrowser2** interface or NULL.

# <a name="AfxGetActiveElementId"></a>AfxGetActiveElementId

Retrieves the ID of the active element (the object that has the focus when the parent document has focus).

```
FUNCTION AfxGetActiveElementId (BYVAL pWebBrowser AS Afx_IWebBrowser2 PTR) AS CWSTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *pWebBrowser* | Pointer to the **IWebBrowser2** interface |

#### Return value

The ID of the active element, if any. If the element has not an identifier, it returns an empty string.

# <a name="AfxGetBodyInnerHtml"></a>AfxGetBodyInnerHtml

Returns a string that represents the text and html elements between the start and end body tags.

```
FUNCTION AfxGetBodyInnerHtml (BYVAL pWebBrowser AS Afx_IWebBrowser2 PTR) AS CWSTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *pWebBrowser* | Pointer to the **IWebBrowser2** interface |

#### Return value

A string containing the html text.

# <a name="AfxGetBodyInnerText"></a>AfxGetBodyInnerText

Returns a string that represents the text between the start and end body tags without any associated HTML.

```
FUNCTION AfxGetBodyInnerText (BYVAL pWebBrowser AS Afx_IWebBrowser2 PTR) AS CWSTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *pWebBrowser* | Pointer to the **IWebBrowser2** interface |

#### Return value

A string containing the html text.

# <a name="AfxGetElementInnerHtmlById"></a>AfxGetElementInnerHtmlById

Retrieves the HTML between the start and end tags of the object.

```
FUNCTION AfxGetElementInnerHtmlById (BYVAL pWebBrowser AS Afx_IWebBrowser2 PTR, _
   BYREF cwsId AS CWSTR) AS CWSTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *pWebBrowser* | Pointer to the **IWebBrowser2** interface. |
| *cwsId* | The identifier. |

#### Return value

A string containing the HTML text.

#### Remarks

This method performs a case insensitive property search. If two or more attributes have the same name (differing only in uppercase and lowercase letters) this function retrieves values only for the last attribute created with this name, and ignores all other attributes with the same name.

# <a name="AfxGetElementValueById"></a>AfxGetElementValueById

Retrieves the value attribute of the specified attribute.

```
FUNCTION AfxGetElementValueById (BYVAL pWebBrowser AS Afx_IWebBrowser2 PTR, _
   BYREF cwsId AS CWSTR) AS VARIANT
```

| Parameter  | Description |
| ---------- | ----------- |
| *pWebBrowser* | Pointer to the **IWebBrowser2** interface. |
| *cwsId* | The identifier. |

#### Return value

A variant containing the value as defined by the attribute.

#### Remarks

This method performs a case insensitive property search. If two or more attributes have the same name (differing only in uppercase and lowercase letters) this function retrieves values only for the last attribute created with this name, and ignores all other attributes with the same name.

# <a name="AfxSetElementFocusById"></a>AfxSetElementFocusById

Sets the focus in the specified element.

```
FUNCTION AfxSetElementFocusById (BYVAL pWebBrowser AS Afx_IWebBrowser2 PTR, _
   BYREF cwsId AS CWSTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *pWebBrowser* | Pointer to the **IWebBrowser2** interface. |
| *cwsId* | The identifier. |

#### Return value

S_OK if successful, or an error value otherwise.

#### Remarks

This method performs a case insensitive property search. If two or more attributes have the same name (differing only in uppercase and lowercase letters) this function sets values only for the last attribute created with this name, and ignores all other attributes with the same name.

# <a name="AfxSetElementInnerHtmlById"></a>AfxSetElementInnerHtmlById

Sets the HTML between the start and end tags of the object.

```
FUNCTION AfxSetElementInnerHtmlById (BYVAL pWebBrowser AS Afx_IWebBrowser2 PTR, _
   BYREF cwsId AS CWSTR, BYREF cwsHtml AS CWSTR) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *pWebBrowser* | Pointer to the **IWebBrowser2** interface. |
| *cwsId* | The identifier. |
| *cwsHtml* | The html text to set. |

#### Return value

S_OK if successful, or an error value otherwise.

#### Remarks

This method performs a case insensitive property search. If two or more attributes have the same name (differing only in uppercase and lowercase letters) this function sets values only for the last attribute created with this name, and ignores all other attributes with the same name.

# <a name="AfxSetElementValueById"></a>AfxSetElementValueById

Sets the value attribute of the specified identifier.

```
FUNCTION AfxSetElementValueById (BYVAL pWebBrowser AS Afx_IWebBrowser2 PTR, _
   BYREF cwsId AS CWSTR, BYVAL vValue AS VARIANT) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *pWebBrowser* | Pointer to the **IWebBrowser2** interface. |
| *cwsId* | The identifier. |
| *vValue* | Variant that specifies the string, number, or Boolean to assign to the attribute. |

#### Return value

S_OK if successful, or an error value otherwise.

#### Remarks

This method performs a case insensitive property search. If two or more attributes have the same name (differing only in uppercase and lowercase letters) this function sets values only for the last attribute created with this name, and ignores all other attributes with the same name.

# <a name="AfxWriteHtml"></a>AfxWriteHtml

Writes one or more HTML expressions to a document.

```
FUNCTION AfxWriteHtml (BYVAL pWebBrowser AS Afx_IWebBrowser2 PTR, _
   BYREF cwsHtml AS CWSTR, BYVAL cr AS BOOLEAN = FALSE) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *pWebBrowser* | Pointer to the **IWebBrowser2** interface. |
| *cwsHtml* | Text and HTML tags to write. |
| *cr* | Write the HTML text followed by a carriage return. |

#### Return value

S_OK if successful, or an error value otherwise.

# <a name="BeforeNavigate2"></a>BeforeNavigate2 Event

Fires before navigation occurs in the given object (on either a window or frameset element).

```
SUB BeforeNavigate2 (BYVAL pWebCtx AS CWebCtx PTR, BYVAL pDisp AS IDispatch PTR, _
   BYVAL vUrl AS VARIANT PTR, BYVAL vFlags AS VARIANT PTR, BYVAL vTargetFrameName AS VARIANT PTR, _
   BYVAL vPostData AS VARIANT PTR, BYVAL vHeaders AS VARIANT PTR, BYVAL pbCancel AS VARIANT_BOOL PTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *pWebCtx* | Pointer to the **CWebCtx** class. |
| *pDisp* | Pointer to the **IDispatch** interface for the **WebBrowser** object that represents the window or frame. This interface can be queried for the **IWebBrowser2** interface.  |
| *vUrl* | Pointer to a VARIANT of type VT_BSTR that contains the URL to be navigated to |
| *vFlags* | Pointer to a VARIANT of type VT_I4 that contains the following flag, or zero.<br>**beforeNavigateExternalFrameTarget**: Windows Internet Explorer 7 or later. This navigate was the result of an external window or tab targeting this browser. |
| *vTargetFrameName* | Pointer to a VARIANT of type VT_BSTR that contains the name of the frame in which to display the resource, or NULL if no named frame is targeted for the resource. |
| *vPostData* | Pointer to a VARIANT of type VT_BYREF|VT_VARIANT that contains the data to send to the server if the HTTP POST transaction is being used. |
| *vHeaders* | Pointer to a VARIANT of type VT_BSTR that contains additional HTTP headers to send to the server (HTTPURLs only). The headers can specify things such as the action required of the server, the type of data being passed to the server, or a status code.  |
| *pbCancel* | In, Out. Pointer to a variable of type VARIANT_BOOL that contains the cancel flag. An application can set this parameter to VARIANT_TRUE to cancel the navigation operation, or to VARIANT_FALSE to allow it to proceed.  |

### Remarks

The post data specified by *vPostData* is passed as a SAFEARRAY structure. The variant should be of type VT_BYREF OR VT_VARIANT, which points to a SAFEARRAY. The SAFEARRAY should be of element type VT_UI1, dimension one, and have an element count equal to the number of bytes of post data.

The *vUrl* parameter can be a pointer to an item identifier list (PIDL) in the case of a shell namespace entity for which there is no URL representation.

The *pDisp* parameter specifies the WebBrowser object of the top-level frame corresponding to the navigation. Navigating to a different URL could happen as a result of external automation, internal automation from a script, or the user clicking a link or typing in the address bar. The processing of this navigation can be modified by setting the *pbCancel* parameter to VARIANT_TRUE and either ignoring or reissuing a modified navigation method to the WebBrowser object.

When reissuing a navigation for the WebBrowser object, the **Stop** method must first be executed for *pDisp*. This prevents the display of a web page that declares a cancelled navigation from appearing while the new navigation is being processed.

#### Example

The following example demonstrates how to redirect navigation to another url.

```
SUB WebBrowser_BeforeNavigate2Proc (BYVAL pAxHost AS CAxHost PTR, BYVAL pdisp AS IDispatch PTR, _
    BYVAL vUrl AS VARIANT PTR, BYVAL Flags AS VARIANT PTR, BYVAL TargetFrameName AS VARIANT PTR, _
    BYVAL PostData AS VARIANT PTR, BYVAL Headers AS VARIANT PTR, BYVAL pbCancel AS VARIANT_BOOL PTR)

   ' // Sample code to redirect navigation to another url
   IF AfxVarToStr(vUrl) = "http://com.it-berater.org/" THEN
      ' // Get a reference to the Afx_IWebBrowser2 interface
      DIM pwb AS Afx_IWebBrowser2 PTR = cast(Afx_IWebBrowser2 PTR, cast(ULONG_PTR, pdisp))
      IF pwb THEN
         ' // Stop loading the page
         pwb->Stop
         ' // Cancel the navigation operation
         *pbCancel = VARIANT_TRUE
         DIM vNewUrl AS VARIANT
         vNewUrl.vt = VT_BSTR
         vNewUrl.bstrVal = SysAllocString("http://www.planetsquires.com/protect/forum/index.php")
         pwb->Navigate2(@vNewUrl)
         VariantClear @vNewUrl
      END IF
   END IF

END SUB
' ========================================================================================
```

# <a name="ClientToHostWindow"></a>ClientToHostWindow Event

Fires to request that the client window size be converted to the host window size.

```
SUB ClientToHostWindow (BYVAL pWebCtx AS CWebCtx PTR, BYVAL CX AS LONG PTR, BYVAL CY AS LONG PTR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *pWebCtx* | Pointer to the **CWebCtx** class. |
| *cx* | In, Out. LONG variable that receives the width of the client window and can be set by the host application. |
| *cy* | In, Out. LONG that receives the height of the client window and can be set by the host application. |

#### Remarks

The **ClientToHostWindow** event gives the host application an opportunity to adjust the size of the WebBrowser control window, to account for any user interface items such as a toolbar, menu bar, or address bar.

This event is fired when a new window is opened through scripting, using the open method.

This event is available only to an application that is hosting the WebBrowser control installed by Microsoft Internet Explorer 5.5 and later.
