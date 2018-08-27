# CImageCtx Class

**CImageCtx** is an image control based on GDI+. The images can be rendered using its actual size or can be resized to fit the width or the height of the window. Resizing is done automatically by the control.

To use the control, include the **CImageCtx.inc** file in your program and use the namespace **Afx**.

Include file: CImageCtx.inc

### Constructor

Registers the class name and creates an instance of the control.

```
CONSTRUCTOR CImageCtx (BYVAL pWindow AS CWindow PTR, BYVAL cID AS INTEGER, _
   BYREF wszTitle AS CONST WSTRING = "", BYVAL x AS LONG = 0, BYVAL y AS LONG = 0, _
   BYVAL nWidth AS LONG = 0, BYVAL nHeight AS LONG = 0, BYVAL dwStyle AS DWORD = 0, _
   BYVAL dwExStyle AS DWORD = 0, BYVAL lpParam AS LONG_PTR = 0)
```
| Parameter  | Description |
| ---------- | ----------- |
| *pWindow* | Pointer to the **CWindow** class of the parent window. |
| *cID* | Control identifier. |
| *wszTitle* | The window caption. If "OPENGL" is used as the caption, support for OpenGL is added to the control. |
| *x* | The x-coordinate of the upper-left corner of the window relative to the upper-left corner of the parent window's client area. |
| *y* | The initial y-coordinate of the upper-left corner of the window relative to the upper-left corner of the parent window's client area. |
| *nWidth* | The width of the control. |
| *nHeight* | The height of the control. |
| *dwStyle* | The style of the window being created. Pass -1 to use the default styles.<br>Default styles: WS_VISIBLE OR WS_CHILD OR WS_TABSTOP. |
| *dwExStyle* | The extended window style of the control being created. Pass -1 to use the default styles. |
| *lpParam* | Pointer to custom data. |

#### Return value

A pointer to the new instance of the class.

#### Usage example:

```
' // Create the main window
DIM pWindow AS CWindow
pWindow.Create(NULL, "CWindow with an image control", @WndProc)
pWindow.SetClientSize(600, 350)
pWindow.Center

' // Add an image control
DIM pImageCtx AS CImageCtx = CImageCtx(@pWindow, IDC_IMAGECTX, "", 0, 0, pWindow.ClientWidth, pWindow.ClientHeight)
' // Load an image from disk
pImageCtx.LoadImageFromFile ExePath & "\image.jpg"
```

### Helper Procedure: AfxCImageCtxPtr

Returns a pointer to the CIMageCtx class given the handle of its associated window.

```
FUNCTION AfxCImageCtxPtr (BYVAL hwnd AS HWND) AS CGraphCtx PTR
FUNCTION AfxCImageCtxPtr (BYVAL hParent AS HWND, BYVAL cID AS LONG) AS CImageCtx PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle of the window associated with the graphic control. Call the **hWindow** method of the **CImageCtx** class to retrieve it. |
| *hParent* | The handle of the parent window of the control. |
| *cID* | The identifier of the control. |

#### Return value

A pointer to the CImageCtx class.
