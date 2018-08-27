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

### Methods and Properties

| Name       | Description |
| ---------- | ----------- |
| [Clear](#Clear) | Clears the contents of the controlr. |
| [GetBkColor](#GetBkColor) | Gets the background RGB color used by the **CImageCtx** control. |
| [GetImageAdjustment](#GetImageAdjustment) | Gets the image adjustment setting used by the control. |
| [GetImageHeight](#GetImageHeight) | Gets the height of the image, in pixels, currently loaded in the **CImageCtx** control. |
| [GetImagePtr](#GetImagePtr) | Gets a pointer to the GDI+ GpImage object used by the control to render the loaded image. |
| [GetImageWidth](#GetImageWidth) | Gets the width of the image, in pixels, currently loaded in the control. |
| [GetInterpolationMode](#GetInterpolationMode) | Gets the interpolation mode used by GDI+. |
| [hWindow](#hWindow) | Returns the handle of the control. |
| [LoadBitmapFromResource](#LoadBitmapFromResource) | Loads a bitmap from a resource file into the control. |
| [LoadImageFromFile](#LoadImageFromFile) | Loads an image from disk into the control. |
| [LoadImageFromResource](#LoadImageFromResource) | Loads an image from a resource file into the control. |
| [Redraw](#Redraw) | Redraws the **CImageCtx** control. |
| [SetBkColor](#SetBkColor) | Sets the background RGB color used by the **CImageCtx** control. |
| [SetImageAdjustment](#SetImageAdjustment) | Sets the image adjustment setting used by the control. |
| [SetInterpolationMode](#SetInterpolationMode) | Sets the interpolation mode used by GDI+. |

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
   IF wParam = IDC_IMGCTX THEN
      SELECT CASE phdr->code
         CASE NM_CLICK
            ' Left button clicked
      END SELECT
   END IF
END IF
```

#### Remarks

IDC_IMGCTX is the constant value used as identifier of the control. Change it if needed.

# <a name="NM_DBLCLK"></a>NM_DBLCLK Notification Message

Sent by the control when the user double clicks it with the left mouse button. This notification code is sent in the form of a WM_NOTIFY message.

```
CASE WM_NOTIFY
   DIM phdr AS NMHDR PTR = CAST(NMHDR PTR, lParam)
   IF wParam = IDC_IMGCTX THEN
      SELECT CASE phdr->code
         CASE NM_DBLCLK
            ' Left button double clicked
      END SELECT
   END IF
END IF
```

#### Remarks

IDC_IMGCTX is the constant value used as identifier of the control. Change it if needed.

# <a name="NM_KILLFOCUS"></a>NM_KILLFOCUS Notification Message

Notifies a control's parent window that the control has lost the input focus. This notification code is sent in the form of a WM_NOTIFY message. 

```
CASE WM_NOTIFY
   DIM phdr AS NMHDR PTR = CAST(NMHDR PTR, lParam)
   IF wParam = IDC_IMGCTX THEN
      SELECT CASE phdr->code
         CASE NM_KILLFOCUS
            ' The control has lost focus
      END SELECT
   END IF
END IF
```

#### Remarks

IDC_IMGCTX is the constant value used as identifier of the control. Change it if needed.

# <a name="NM_RCLICK"></a>NM_RCLICK Notification Message

Notifies a control's parent window that the control has lost the input focus. This notification code is sent in the form of a WM_NOTIFY message. 

```
CASE WM_NOTIFY
   DIM phdr AS NMHDR PTR = CAST(NMHDR PTR, lParam)
   IF wParam = IDC_IMGCTX THEN
      SELECT CASE phdr->code
         CASE NM_RCLICK
            ' Right button clicked
      END SELECT
   END IF
END IF
```

#### Remarks

IDC_IMGCTX is the constant value used as identifier of the control. Change it if needed.

# <a name="NM_RDBLCLK"></a>NM_RDBLCLK Notification Message

Sent by the control when the user double clicks it with the right mouse button. This notification code is sent in the form of a WM_NOTIFY message.

```
CASE WM_NOTIFY
   DIM phdr AS NMHDR PTR = CAST(NMHDR PTR, lParam)
   IF wParam = IDC_IMGCTX THEN
      SELECT CASE phdr->code
         CASE NM_RDBLCLK
            ' Right button double clicked
      END SELECT
   END IF
END IF
```

#### Remarks

IDC_IMGCTX is the constant value used as identifier of the control. Change it if needed.

# <a name="NM_SETFOCUS"></a>NM_SETFOCUS Notification Message

Notifies a control's parent window that the control has received the input focus. This notification code is sent in the form of a WM_NOTIFY message. 

```
CASE WM_NOTIFY
   DIM phdr AS NMHDR PTR = CAST(NMHDR PTR, lParam)
   IF wParam = IDC_IMGCTX THEN
      SELECT CASE phdr->code
         CASE NM_SETFOCUS
            ' The control has gained focus
      END SELECT
   END IF
END IF
```

#### Remarks

IDC_IMGCTX is the constant value used as identifier of the control. Change it if needed.

# <a name="Clear"></a>Clear

Clears the contents of the control.

```
SUB Clear
```

# <a name="GetBkColor"></a>GetBkColor

Gets the background RGB color used by the **CImageCtx** control.

```
FUNCTION GetBkColor () AS LONG
```

# <a name="GetImageAdjustment"></a>GetImageAdjustment

Gets the image adjustment setting used by the control.

```
FUNCTION GetImageAdjustment () AS LONG
```

#### Return value

The current adjustment setting, that can be one of the following values:

| Value      | Description |
| ---------- | ----------- |
| **GDIP_IMAGECTX_AUTOSIZE** | Autoadjusts the image to the width or height of the control. |
| **GDIP_IMAGECTX_ACTUALSIZE** | Shows the image with its actual size. |
| **GDIP_IMAGECTX_FITTOWIDTH** | Adjusts the image to the width of the control. |
| **GDIP_IMAGECTX_FITTOHEIGHT** | Adjusts the image to the height of the control. |
| **GDIP_IMAGECTX_STRETCH** | Adjusts the image to the height and width of the control. |

# <a name="GetImageHeight"></a>GetImageHeight

Gets the height of the image, in pixels, currently loaded in the **CImageCtx** control.

```
FUNCTION GetImageHeight () AS LONG
```

# <a name="GetImagePtr"></a>GetImagePtr

Gets a pointer to the GDI+ **GpImage** object used by the control to render the loaded image.

```
FUNCTION GetImagePtr () AS GpImage PTR
```

#### Return value

A copy of the pointer to the **GpImage** object used by the control to render the loaded image.

### Remarks

The returned pointer can be used to call GDI+ Image functions.

Don't dispose the returned pointer. The control keeps a copy of it and calls **GdipDisposeImage** when it is destroyed.

# <a name="GetImageWidth"></a>GetImageWidth

Gets the with of the image, in pixels, currently loaded in the **CImageCtx** control.

```
FUNCTION GetImageWidth () AS LONG
```

# <a name="GetInterpolationMode"></a>GetInterpolationMode

Gets the interpolation mode used by GDI+.

```
FUNCTION GetInterpolationMode () AS LONG
```

#### Return value

The current interpolation mode value.

```
InterpolationModeInvalid = -1
InterpolationModeDefault = 0
InterpolationModeLowQuality = 1
InterpolationModeHighQuality = 2
InterpolationModeBilinear = 3
InterpolationModeBicubic = 4
InterpolationModeNearestNeighbor = 5
InterpolationModeHighQualityBilinear = 6
InterpolationModeHighQualityBicubic = 7
```

# <a name="hWindow"></a>hWindow

Returns the handle of the control.

```
FUNCTION hWindow () AS HWND
```

# <a name="LoadBitmapFromResource"></a>LoadBitmapFromResource

Loads a bitmap from a resource file into the control.

```
FUNCTION LoadBitmapFromResource (BYVAL hInstance AS HINSTANCE, BYREF wszResourceName AS WSTRING) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hInstance* | Handle to the instance of the module whose executable file contains the resource. A value of NULL specifies the module handle associated with the image file that the operating system used to create the current process.  |
| *wszResourceName* | The name of the resource. |

#### Return value

Ok (0) or an error code.

# <a name="LoadImageFromFile"></a>LoadImageFromFile

Loads an image from disk into the control.

```
FUNCTION LoadImageFromFile (BYREF wszFileName AS WSTRING) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFileName* | Fully qualified path and filename of the image file to load. |

#### Return value

Ok (0) or an error code.

# <a name="LoadImageFromResource"></a>LoadImageFromResource

Loads an image from a resource file into the control.
**Note**: In Windows 7, it fails to load .jpg and .tif files. Works with .bmp and .png files.

```
FUNCTION LoadImageFromResource (BYVAL hInstance AS HINSTANCE, BYREF wszResourceName AS WSTRING) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hInstance* | Handle to the instance of the module whose executable file contains the resource. A value of NULL specifies the module handle associated with the image file that the operating system used to create the current process.  |
| *wszResourceName* | The name of the resource. |

#### Return value

Ok (0) or an error code.

# <a name="Redraw"></a>Redraw

Redraws the **CImageCtx** control.

```
SUB Redraw
```

# <a name="SetBkColor"></a>SetBkColor

Sets the background RGB color used by the **CImageCtx** control.

```
FUNCTION SetBkColor (BYVAL clr AS LONG, BYVAL fRedraw AS BOOLEAN = FALSE) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *clr* | The new RGB background color. |
| *fRedraw* | Optional. TRUE to redraw the control to reflect the changes. |

#### Return value

The previous background color.

# <a name="SetImageAdjustment"></a>SetImageAdjustment

Sets the image adjustment setting used by the control.

```
FUNCTION SetImageAdjustment (BYVAL ImageAdjustment AS LONG, BYVAL fRedraw AS BOOLEAN = FALSE) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *ImageAdjustment* | The setting to set. Can be one of the values listed below. |
| *fRedraw* | Optional. TRUE to redraw the control to reflect the changes. |

### Image adjustment constants

| Value      | Description |
| ---------- | ----------- |
| **GDIP_IMAGECTX_AUTOSIZE** | Autoadjusts the image to the width or height of the control. |
| **GDIP_IMAGECTX_ACTUALSIZE** | Shows the image with its actual size. |
| **GDIP_IMAGECTX_FITTOWIDTH** | Adjusts the image to the width of the control. |
| **GDIP_IMAGECTX_FITTOHEIGHT** | Adjusts the image to the height of the control. |
| **GDIP_IMAGECTX_STRETCH*** | Adjusts the image to the height and width of the control. |

#### Return value

The previous setting value.
