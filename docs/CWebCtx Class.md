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
