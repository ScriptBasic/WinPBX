# CAxHost Class

**CAxHost** implements an OLE Container using a custom control to host ActiveX controls.

**Include file**: CaxHost.inc.

### Constructors

| Name       | Description |
| ---------- | ----------- |
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

