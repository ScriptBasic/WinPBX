# CAxHost Class

**CAxHost** implements an OLE Container using a custom control to host ActiveX controls.

**Include file**: CaxHost.inc.

### Constructors

| Name       | Description |
| ---------- | ----------- |
| [CAXHOST_AMBIENTDISP structure](#CAXHOST_AMBIENTDISP) | Contains information the ambient properties of the CAxHost control. |
| [Constructor(ProgID)](#Constructor1) | Creates an instance of the OLE container using a ProgId. |
| [Constructor(ClsId)](#Constructor2) | Creates an instance of the OLE container using a Clsid. |
| [Constructor(LibName)](#Constructor3) | Creates an instance of the OLE container using an unregistered OCX. |

### Methods

| Name       | Description |
| ---------- | ----------- |
| [Advise](#Advise) | Establishes a connection between a connection point object and the client's sink. |
| [CtrlID](#CtrlID) | Returns the identifier of the container's window. |
| [GuidFromStr](#GuidFromStr) | Converts a string into a 16-byte (128-bit) Globally Unique Identifier (GUID). |
| [GuidText](#GuidText) | Returns a 38-byte human-readable guid string from a 16-byte GUID. |
| [hWindow](#hWindow) | Returns the handle of the hosting window. |
| [OcxDispObj](#OcxDispObj) | Returns a reference to the control's default interface given the handle of the window that hosts it. |
| [OcxDispPtr](#OcxDispPtr) | Returns a reference to the control's default interface given the handle of the window that hosts it. |
| [OleCreateFont](#OleCreateFont) | Creates a standard IFont object. |
| [OleCreateFontDisp](#OleCreateFontDisp) | Creates a standard IFont object. |
| [Unadvise](#Unadvise) | Terminates an advisory connection previously established by the **Advise** method between a connection point object and a client's sink. |

### Helper Procedures

| Name       | Description |
| ---------- | ----------- |
| [AfxCAxHostDispObj](#AfxCAxHostDispObj) | Returns a reference to the control's default interface given the handle of the window that hosts it. |
| [AfxCAxHostDispPtr](#AfxCAxHostDispPtr) | Returns a reference to the control's default interface given the handle of the window that hosts it. |
| [AfxCAxHostPtr](#AfxCAxHostPtr) | Returns a reference to the OLE container class given the handle of its associated window. |
| [AfxCAxHostWindow](#AfxCAxHostWindow) | Returns the OLE container window handle given the handle of the form, or any control in the form, and its control identifier. |
| [AfxCAxHostForwardMessage](#AfxCAxHostForwardMessage) | Forwards the Windows messages to the OLE Container window for processing. |

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

# <a name="Constructor1"></a>Constructor(ProgId)

Creates an instance of the OLE container using a ProgId.

```
CONSTRUCTOR CAxHost (BYVAL pWindow AS CWindow PTR, BYVAL cID AS LONG_PTR, _
   BYREF wszProgID AS WSTRING, BYVAL x AS LONG = 0, BYVAL y AS LONG = 0, _
   BYVAL nWidth AS LONG = 0, BYVAL nHeight AS LONG = 0, _
   BYVAL dwStyle AS DWORD = 0, BYVAL dwExStyle AS DWORD = 0, _
   BYVAL pAmbientDisp AS CAXHOST_AMBIENTDISP PTR = NULL)
```
```
CONSTRUCTOR CAxHost (BYVAL pWindow AS CWindow PTR, BYVAL cID AS INTEGER, _
   BYREF wszProgID AS WSTRING, BYREF wszLicKey AS WSTRING, BYVAL x AS LONG = 0, _
   BYVAL y AS LONG = 0, BYVAL nWidth AS LONG = 0, BYVAL nHeight AS LONG = 0, _
   BYVAL dwStyle AS DWORD = 0, BYVAL dwExStyle AS DWORD = 0, _
   BYVAL pAmbientDisp AS CAXHOST_AMBIENTDISP PTR = NULL)
```

| Parameter  | Description |
| ---------- | ----------- |
| *pWindow* | Pointer to the instance of the **CWindow** class used to create the form. |
| *cID* | The identifier of the control. It must be unique. |
| *wszProgID* | The **ProgID** of the object to create, such "MSCAL.Calendar". |
| *wszLicKey* | The license key of the control, if the control is licensed. |
| *x, y* | The coordinates of the upper-left corner of the window relative to the upper-left corner of the parent window's client area. |
| *nWidth* | The width of the window. |
| *nHeight* | The height of the window. |
| *dwStyle* | The style of the window being created. |
| *dwExStyle* | The extended style of the window being created. |
| *pAmbientDisp* | Pointer to a **CAXHOST_AMBIENTDISP** structure. |


# <a name="Constructor2"></a>Constructor(ClsId)

Creates an instance of the OLE container using a ClsId.

```
CONSTRUCTOR CAxHost (BYVAL pWindow AS CWindow PTR, BYVAL cID AS LONG_PTR, _
   BYREF classID AS CONST CLSID, BYREF riid AS CONST IID, BYVAL x AS LONG = 0, BYVAL y AS LONG = 0, _
   BYVAL nWidth AS LONG = 0, BYVAL nHeight AS LONG = 0, BYVAL dwStyle AS DWORD = 0, _
   BYVAL dwExStyle AS DWORD = 0, BYVAL pAmbientDisp AS CAXHOST_AMBIENTDISP PTR = NULL)
```
```
CONSTRUCTOR CAxHost (BYVAL pWindow AS CWindow PTR, BYVAL cID AS INTEGER, _
   BYREF classID AS CONST CLSID, BYREF riid AS CONST IID, BYREF wszLicKey AS WSTRING, _
   BYVAL x AS LONG = 0, BYVAL y AS LONG = 0, BYVAL nWidth AS LONG = 0, BYVAL nHeight AS LONG = 0, _
   BYVAL dwStyle AS DWORD = 0, BYVAL dwExStyle AS DWORD = 0, _
   BYVAL pAmbientDisp AS CAXHOST_AMBIENTDISP PTR = NULL)
```

| Parameter  | Description |
| ---------- | ----------- |
| *pWindow* | Pointer to the instance of the **CWindow** class used to create the form. |
| *cID* | The identifier of the control. It must be unique. |
| *classID* | The **CLSID** of the object to create, such "{8E27C92B-1264-101C-8A2F-040224009C02}" |
| *riid* | The **IID** of the object to create, such "{8E27C92C-1264-101C-8A2F-040224009C02}". |
| *wszLicKey* | The license key of the control, if the control is licensed. |
| *x, y* | The coordinates of the upper-left corner of the window relative to the upper-left corner of the parent window's client area. |
| *nWidth* | The width of the window. |
| *nHeight* | The height of the window. |
| *dwStyle* | The style of the window being created. |
| *dwExStyle* | The extended style of the window being created. |
| *pAmbientDisp* | Pointer to a **CAXHOST_AMBIENTDISP** structure. |

# <a name="Constructor3"></a>Constructor(LibName)

Creates an instance of the OLE container using an unregistered OCX.

```
CONSTRUCTOR CAxHost (BYVAL pWindow AS CWindow PTR, BYVAL cID AS LONG_PTR, _
   BYREF wszLibName AS WSTRING, BYREF classID AS CONST CLSID, BYREF riid AS CONST IID, _
   BYVAL x AS LONG = 0, BYVAL y AS LONG = 0, BYVAL nWidth AS LONG = 0, _
   BYVAL nHeight AS LONG = 0, BYVAL dwStyle AS DWORD = 0, BYVAL dwExStyle AS DWORD = 0, _
   BYVAL pAmbientDisp AS CAXHOST_AMBIENTDISP = NULL)
```
```
CONSTRUCTOR CAxHost (BYVAL pWindow AS CWindow PTR, BYVAL cID AS INTEGER, _
   BYREF wszLibName AS WSTRING, BYREF classID AS CONST CLSID, BYREF riid AS CONST IID, _
   BYREF wszLicKey AS WSTRING, BYVAL x AS LONG = 0, BYVAL y AS LONG = 0, _
   BYVAL nWidth AS LONG = 0, BYVAL nHeight AS LONG = 0, BYVAL dwStyle AS DWORD = 0, _
   BYVAL dwExStyle AS DWORD = 0, BYVAL pAmbientDisp AS CAXHOST_AMBIENTDISP PTR = NULL)
```

| Parameter  | Description |
| ---------- | ----------- |
| *pWindow* | Pointer to the instance of the **CWindow** class used to create the form. |
| *cID* | The identifier of the control. It must be unique. |
| *wszLibName* | The full qualified path to the OCX file. |
| *classID* | The **CLSID** of the object to create, such "{8E27C92B-1264-101C-8A2F-040224009C02}" |
| *riid* | The **IID** of the object to create, such "{8E27C92C-1264-101C-8A2F-040224009C02}". |
| *wszLicKey* | The license key of the control, if the control is licensed. |
| *x, y* | The coordinates of the upper-left corner of the window relative to the upper-left corner of the parent window's client area. |
| *nWidth* | The width of the window. |
| *nHeight* | The height of the window. |
| *dwStyle* | The style of the window being created. |
| *dwExStyle* | The extended style of the window being created. |
| *pAmbientDisp* | Pointer to a **CAXHOST_AMBIENTDISP** structure. |

```
DIM wszLibName AS WSTRING * 260 = ExePath & "\MSCOMCT2.OCX"
DIM CLSID_MSComCtl2_MonthView AS CLSID = (&h232E456A, &h87C3, &h11D1, {&h8B, &hE3,&h00, &h00, &hF8, &h75, &h4D, &hA1})
DIM IID_MSComCtl2_MonthView AS CLSID = (&h232E4565, &h87C3, &h11D1, {&h8B, &hE3,&h00, &h00, &hF8, &h75, &h4D, &hA1})
DIM RTLKEY_MSCOMCT2 AS WSTRING * 260 = "651A8940-87C5-11d1-8BE3-0000F8754DA1"
DIM pAxHost AS CAxHost PTR = CAxHost(@pWindow, IDC_WEBBROWSER, wszLibName, CLSID_MSComCtl2_MonthView, _
    IID_MSComCtl2_MonthView, RTLKEY_MSCOMCT2, 0, 0, pWindow.ClientWidth, pWindow.ClientHeight)
```

# Advise

Establishes a connection between a connection point object and the client's sink.

```
FUNCTION Advise (BYVAL pEvtObj AS IDispatch PTR, BYVAL riid AS IID PTR) AS HRESULT
FUNCTION Advise (BYVAL pEvtObj AS IDispatch PTR, BYVAL riid AS CONST IID) AS HRESULT
FUNCTION Advise (BYVAL pEvtObj AS IDispatch PTR, BYREF riid AS IID) AS HRESULT
FUNCTION Advise (BYVAL pEvtObj AS IDispatch PTR, BYVAL riid AS IID PTR) AS HRESULT
FUNCTION Advise (BYVAL pEvtObj AS IDispatch PTR, BYREF riid AS CONST IID) AS HRESULT
FUNCTION Advise (BYVAL pEvtObj AS IDispatch PTR, BYREF riid AS IID) AS HRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *pEvtObj* | Pointer to the sink event's class. The client's sink receives outgoing calls from the connection point. |
| *riid* | IID of the events interface of the hosted OCX. |

Return value

S_OK (0) or an error code.
