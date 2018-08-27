# CAxHost Class

**CAxHost** implements an OLE Container using a custom control to host ActiveX controls.

**Include file**: CaxHost.inc.

### Constructors

| Name       | Description |
| ---------- | ----------- |
| [Constructor(ProgID)](#Constructor1) | Creates an instance of OLE container. |
| [Constructor(ClsId)](#Constructor2) | Creates an instance of OLE container. |
| [Constructor(LibName)](#Constructor3) | Creates an instance of OLE container. |

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
