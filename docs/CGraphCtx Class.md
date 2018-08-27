# CGraphCtx Class

**CGraphCtx** is a graphic control for pictures, text and graphics. You can use both GDI and GDI+ to draw graphics and text and to load and manipulate images. Optionally, you can add support for OpenGL by passing "OPENGL" in the caption.

This control features persistence and uses a virtual buffer (set initially equal to the size of the control when it is created) to allow to display images bigger than the size of the control. Scrollbars are automatically added when the size of the virtual buffer is bigger than the size of the control and removed when unneeded. It also features keyboard navigation and sends command messages to the parent window or dialog when the return or Escape keys are pressed, and notification messages for mouse clicks.

To use the control, include the CGraphCtx.inc file in your program and use the namespace **Afx**.

**Include file**: CGraphCtx.inc

### Constructor

Registers the class name and creates an instance of the control.

```
CONSTRUCTOR CGraphCtx (BYVAL pWindow AS CWindow PTR, BYVAL cID AS LONG_PTR, _
   BYREF wszTitle AS WSTRING = "", BYVAL x AS LONG = 0, BYVAL y AS LONG = 0, _
   BYVAL nWidth AS LONG = 0, BYVAL nHeight AS LONG = 0, BYVAL dwStyle AS DWORD = 0, _
   BYVAL dwExStyle AS DWORD = 0, BYVAL lpParam AS LONG_PTR = 0)
```

| Parameter  | Description |
| ---------- | ----------- |
| *pWindow* | Pointer to the CWindow class of the parent window. |
| *cID* | Control identifier. |
| *wszTitle* | The window caption. If "OPENGL" is used as the caption, support for OpenGL is added to the control. |
| *x* | The x-coordinate of the upper-left corner of the window relative to the upper-left corner of the parent window's client area. |
| *y* | The initial y-coordinate of the upper-left corner of the window relative to the upper-left corner of the parent window's client area. |
| *nWidth* | The width of the control. |
| *nHeight* | The height of the control. |
| *dwStyle* | The style of the window being created. Pass -1 to use the default styles. |
| *dwExStyle* | The extended window style of the control being created. Pass -1 to use the default styles. |
| *lpParam* | Pointer to custom data. |

### Helper Procedure: AfxCGraphPtr

Returns a pointer to the CGraphCtx class given the handle of its associated window.

```
FUNCTION AfxCGraphPtr (BYVAL hwnd AS HWND) AS CGraphCtx PTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle of the window associated with the graphic control. Call the **hWindow** method of the **CGraphCtx** class to retrieve it. |

### Methods and Properties

| Name       | Description |
| ---------- | ----------- |
| [Clear](#Clear) | Clears the graphic control with the specified RGB color. |
| [CreateBitmapFromFile](#CreateBitmapFromFile) | Loads and displays the specified image in the Graphic Control. It also allows to convert the image to gray scale and/or dim the image. |
| [DrawBitmap](#DrawBitmap) | Draws a bitmap in the Graphic Control. |
| [GetBits](#GetBits) | Returns the location of the DIB bit values. |
| [GethBmp](#GethBmp) | Returns the handle of the compatible bitmap. |
| [GethRC](#GethRC) | If OpenGL is enabled, it returns the handle of the rendering context of the control. |
| [GetMemDC](#GetMemDC) | Handle to  the memory device context of the control. |
| [GetVirtualBufferHeight](#GetVirtualBufferHeight) | Returns the height of the virtual buffer. |
| [GetVirtualBufferWidth](#GetVirtualBufferWidth) | Returns the width of the virtual buffer. |
| [hWindow](#hWindow) | Returns the handle of the control. |
| [LoadImageFromFile](#LoadImageFromFile) | Loads and displays the specified image in the Graphic Control. |
| [LoadImageFromRes](#LoadImageFromRes) | Loads the specified image from a resource file in the Graphic Control. It also allows to convert the image to gray scale and/or dim the image. |
| [MakeCurrent](#MakeCurrent) | Redirects OpenGL calls are directed to the correct rendering context. |
| [PrintImage](#PrintImage) | Prints the image in the default printer. |
| [Resizable](#Resizable) | Gets/sets the value of the Resizable property. |
| [SaveImage](#SaveImage) | Saves the image to a file. |
| [SetVirtualBufferSize](#SetVirtualBufferSize) | Sets the size of the virtual buffer. |
| [Stretchable](#Stretchable) | Gets/sets the value of the Stretchable property. |
| [StretchMode](#StretchMode) | Gets/sets the value of the StretchMode property. |

### Notification Messages

| Name       | Description |
| ---------- | ----------- |
| [NM_CLICK](#NM_CLICK) | Sent by the control when the user clicks it with the left mouse button. |
| [NM_DBLCLK](#NM_DBLCLK) | Sent by the control when the user double clicks it with the left mouse button. |
| [NM_KILLFOCUS](#NM_KILLFOCUS) | Notifies a control's parent window that the control has lost the input focus. |
| [NM_RCLICK](#NM_RCLICK) | Sent by the control when the user clicks it with the right mouse button. |
| [NM_RDBLCLK](#NM_RDBLCLK) | Sent by the control when the user double clicks it with the right mouse button. |
| [NM_SETFOCUS](#NM_SETFOCUS) | Notifies a control's parent window that the control has received the input focus. |

# <a name="NM_CLICK"></a>NM_CLICK Notification Message

Sent by the control when the user clicks it with the left mouse button. This notification code is sent in the form of a WM_NOTIFY message.

```
CASE WM_NOTIFY
   DIM phdr AS NMHDR PTR = CAST(NMHDR PTR, lParam)
   IF wParam = IDC_GRCTX THEN
      SELECT CASE phdr->code
         CASE NM_CLICK
            ' Left button clicked
      END SELECT
   END IF
END IF
```

#### Remarks

IDC_GRCTX is the constant value used as identifier of the control. Change it if needed.

# <a name="NM_DBLCLK"></a>NM_DBLCLK Notification Message

Sent by the control when the user double clicks it with the left mouse button. This notification code is sent in the form of a WM_NOTIFY message.

```
CASE WM_NOTIFY
   DIM phdr AS NMHDR PTR = CAST(NMHDR PTR, lParam)
   IF wParam = IDC_GRCTX THEN
      SELECT CASE phdr->code
         CASE NM_DBLCLK
            ' Left button double clicked
      END SELECT
   END IF
END IF
```

#### Remarks

IDC_GRCTX is the constant value used as identifier of the control. Change it if needed.

# <a name="NM_KILLFOCUS"></a>NM_KILLFOCUS Notification Message

Notifies a control's parent window that the control has lost the input focus. This notification code is sent in the form of a WM_NOTIFY message. 

```
CASE WM_NOTIFY
   DIM phdr AS NMHDR PTR = CAST(NMHDR PTR, lParam)
   IF wParam = IDC_GRCTX THEN
      SELECT CASE phdr->code
         CASE NM_KILLFOCUS
            ' The control has lost focus
      END SELECT
   END IF
END IF
```

#### Remarks

IDC_GRCTX is the constant value used as identifier of the control. Change it if needed.

# <a name="NM_RCLICK"></a>NM_RCLICK Notification Message

Notifies a control's parent window that the control has lost the input focus. This notification code is sent in the form of a WM_NOTIFY message. 

```
CASE WM_NOTIFY
   DIM phdr AS NMHDR PTR = CAST(NMHDR PTR, lParam)
   IF wParam = IDC_GRCTX THEN
      SELECT CASE phdr->code
         CASE NM_RCLICK
            ' Right button clicked
      END SELECT
   END IF
END IF
```

#### Remarks

IDC_GRCTX is the constant value used as identifier of the control. Change it if needed.

# <a name="NM_RDBLCLK"></a>NM_RDBLCLK Notification Message

Sent by the control when the user double clicks it with the right mouse button. This notification code is sent in the form of a WM_NOTIFY message.

```
CASE WM_NOTIFY
   DIM phdr AS NMHDR PTR = CAST(NMHDR PTR, lParam)
   IF wParam = IDC_GRCTX THEN
      SELECT CASE phdr->code
         CASE NM_RDBLCLK
            ' Right button double clicked
      END SELECT
   END IF
END IF
```

#### Remarks

IDC_GRCTX is the constant value used as identifier of the control. Change it if needed.

# <a name="NM_SETFOCUS"></a>NM_SETFOCUS Notification Message

Notifies a control's parent window that the control has received the input focus. This notification code is sent in the form of a WM_NOTIFY message. 

```
CASE WM_NOTIFY
   DIM phdr AS NMHDR PTR = CAST(NMHDR PTR, lParam)
   IF wParam = IDC_GRCTX THEN
      SELECT CASE phdr->code
         CASE NM_SETFOCUS
            ' The control has gained focus
      END SELECT
   END IF
END IF
```

#### Remarks

IDC_GRCTX is the constant value used as identifier of the control. Change it if needed.
