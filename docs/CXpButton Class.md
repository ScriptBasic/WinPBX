# CXpButton Class

Theme aware push button that can also act as a toggle button and display an icon or bitmap.

* Draws a themed button in Windows XP or superior, using the functions available in UxTheme.dll, or a button with classic appearance in other versions of Windows, using GDI functions. 
* Allows up to three images per button (for normal, hot and disabled states). If you want a button with a centered image and no text, use the XPBI_CENTERCENTER flag in the SetImagePos procedure.
* Can be used as a toggle button setting this flag with the SetToggle procedure.
* Images and fonts are owned and destroyed by the control.
* If theming is diabled, you can use you own colors for the different elements of the button: Background, foreground, text, etc.

### Constructor

Registers the class name and creates an instance of the control.

```
CONSTRUCTOR CXpButton (BYVAL pWindow AS CWindow PTR, BYVAL cID AS LONG_PTR, _
   BYREF wszTitle AS WSTRING = "", BYVAL x AS LONG = 0, BYVAL y AS LONG = 0, _
   BYVAL nWidth AS LONG = 0, BYVAL nHeight AS LONG = 0, BYVAL dwStyle AS DWORD = 0, _
   BYVAL dwExStyle AS DWORD = 0, BYVAL lpParam AS LONG_PTR = 0)
```

| Parameter  | Description |
| ---------- | ----------- |
| *pWindow* | Pointer to the *CWindow* class of the parent window. |
| *cID* | Control identifier. |
| *wszTitle* | Optional. The button caption. |
| *x* | Optional. The x-coordinate of the upper-left corner of the button relative to the upper-left corner of the parent window's client area. |
| *y* | Optional. The initial y-coordinate of the upper-left corner of the button relative to the upper-left corner of the parent window's client area. |
| *nWidth* | Optional. The width of the button. |
| *nHeight* | Optional. The height of the button. |
| *dwStyle* | Optional. The style of the button being created.<>Default styles: WS_VISIBLE OR WS_TABSTOP OR BS_PUSHBUTTON OR BS_CENTER OR BS_VCENTER. |
| *dwExStyle* | Optional. The extended window style of the button being created. |
| *lpParam* | Optional. Pointer to custom data. |

#### Return value

A pointer to the new instance of the class.

### Methods

| Parameter  | Description |
| ---------- | ----------- |
| [DisableTheming](#DisableTheming) | Disables theming. |
| [EnableTheming](#EnableTheming) | Enables theming. |
| [GetImage](#GetImage) | Returns the handle of the image. |
| [hWindow](#hWindow) | Returns the handle of the button. |
| [IsThemed](#IsThemed) | Returns CTRUE if themes are enabled or FALSE otherwise. |
| [Redraw](#Redraw) | Redraws the button. |
| [SetBitmap](#SetBitmap) | Sets the bitmap for the button. |
| [SetBitmapFromFile](#SetBitmapFromFile) | Loads an bitmap from file and sets it as the image of tbe button. |
| [SetIcon](#SetIcon) | Sets the icon for the button. |
| [SetIconFromFile](#SetIconFromFile) | Loads an icon from file and sets it as the image of tbe button. |
| [SetImage](#SetImage) | Sets the image for the button. |
| [SetImageFromFile](#SetImageFromFile) | Loads an image from file and sets it as the image of the button. |
| [SetImageFromRes](#SetImageFromRes) | Loads an image from a resource file and sets it as the image of the button. |

### Properties

| Parameter  | Description |
| ---------- | ----------- |
| [BkBrush](#BkBrush) | Returns the background color brush. |
| [ButtonBkColor](#ButtonBkColor) | Gets/sets the background color of button. |
| [ButtonBkColorDown](#ButtonBkColorDown) | Gets/sets the background color of button when it is down (pressed or toggled). |
| [ButtonBkColorHot](#ButtonBkColorHot) | Gets/sets the background color of button when it is hot (the mouse is over it). |
| [ButtonState](#ButtonState) | Returns the button state. |
| [Cursor](#Cursor) | Gets/sets the cursor for the button. |
| [DisabledImageHandle](#DisabledImageHandle) | Returns the handle of the disabled image. |
| [Font](#Font) | Gets/sets the handle of the font used by the button. |
| [HotImageHandle](#HotImageHandle) | Returns the handle of the hot image. |
| [ImageHeight](#ImageHeight) | Gets/sets the heigth of the image. |
| [ImageMargin](#ImageMargin) | Gets/sets the image margin. |
| [ImagePos](#ImagePos) | Gets/sets the image position. |
| [ImageType](#ImageType) | Returns the image type |
| [ImageWidth](#ImageWidth) | Gets/sets the width of the image. |
| [NormalImageHandle](#NormalImageHandle) | Returns the handle of the normal image. |
| [TextBkColor](#TextBkColor) | Gets/sets the text background color of the button. |
| [TextBkColorDown](#TextBkColorDown) | Gets/sets the text background color of the button when it is down (pressed). |
| [TextForeColor](#TextForeColor) | Gets/sets the text foreground color of the button. |
| [TextForeColorDown](#TextForeColorDown) | Gets/sets the text foreground color of the button when it is down (pressed). |
| [TextFormat](#TextFormat) | Gets/sets the method of formatting the text. |
| [TextMargin](#TextMargin) | Gets/sets the margin of the text of the button. |
| [Toggle](#Toggle) | Gets/sets button to toggle state (CTRUE) or to pushbutton state (FALSE). |
| [ToggleState](#ToggleState) | Gets/sets the toggle state: pushed (CTRUE) or unpushed (FALSE). |

# <a name="DisableTheming"></a>DisableTheming

Disables theming.

```
SUB DisableTheming
```

# <a name="EnableTheming"></a>EnableTheming

Enables theming.

```
SUB EnableTheming
```

# <a name="GetImage"></a>GetImage

Returns the handle of the image.

```
FUNCTION GetImage (BYVAL ImageState AS LONG) AS HANDLE
```

| Parameter  | Description |
| ---------- | ----------- |
| *ImageState* | One of the following values:<br>XPBI_NORMAL = 1, XPBI_HOT = 2, XPBI_DISABLED = 3 |

#### Return value

Returns the handle of the requested image.

# <a name="hWindow"></a>hWindow

Returns the handle of the button.

```
FUNCTION hWindow () AS HWND
```

# <a name="IsThemed"></a>IsThemed

Returns CTRUE if themes are enabled or FALSE otherwise.

```
FUNCTION IsThemed () AS LONG
```

# <a name="Redraw"></a>Redraw

Redraws the button.

```
SUB Redraw
```

# <a name="SetBitmap"></a>SetBitmap

Sets the bitmap for the button.

```
SUB SetBitmap (BYVAL hBitmap AS HBITMAP, _
   BYVAL ImageState AS LONG, BYVAL fRedraw AS LONG = FALSE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hBitmap* | Handle to the bitmap. |
| *ImageState* | One of the following values:<br>XPBI_NORMAL = 1, XPBI_HOT = 2, XPBI_DISABLED = 3 |
| *fRedraw* | Optional. CTRUE or FALSE (redraws the button to reflect the changes). |

# <a name="SetBitmapFromFile"></a>SetBitmapFromFile

Loads a bitmap from file and sets it as the image of tbe button.

```
SUB SetBitmapFromFile (BYVAL pwszPath AS WSTRING PTR, _
   BYVAL ImageState AS LONG, BYVAL fRedraw AS LONG = FALSE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszPath* | Full path of the bitmap's file. |
| *ImageState* | One of the following values:<br>XPBI_NORMAL = 1, XPBI_HOT = 2, XPBI_DISABLED = 3 |
| *fRedraw* | Optional. CTRUE or FALSE (redraws the button to reflect the changes). |

# <a name="SetIcon"></a>SetIcon

Sets the icon for the button.

```
SUB SetIcon (BYVAL hIcon AS HICON, _
   BYVAL ImageState AS LONG, BYVAL fRedraw AS LONG = FALSE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hIcon* | Handle to the icon. |
| *ImageState* | One of the following values:<br>XPBI_NORMAL = 1, XPBI_HOT = 2, XPBI_DISABLED = 3 |
| *fRedraw* | Optional. CTRUE or FALSE (redraws the button to reflect the changes). |

# <a name="SetIconFromFile"></a>SetIconFromFile

Loads an icon from file and sets it as the image of tbe button.

```
SUB SetIconFromFile (BYVAL pwszPath AS WSTRING PTR, _
   BYVAL ImageState AS LONG, BYVAL fRedraw AS LONG = FALSE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszPath* | Full path of the icon's file. |
| *ImageState* | One of the following values:<br>XPBI_NORMAL = 1, XPBI_HOT = 2, XPBI_DISABLED = 3 |
| *fRedraw* | Optional. CTRUE or FALSE (redraws the button to reflect the changes). |

# <a name="SetImage"></a>SetImage

Sets the image for the button.

```
SUB SetImage (BYVAL hImage AS HANDLE, BYVAL ImageType AS LONG, _
   BYVAL ImageState AS LONG, BYVAL fRedraw AS LONG = FALSE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hImage* | Handle to the image. |
| *ImageType* | IMAGE_ICON or IMAGE_BITMAP. |
| *ImageState* | One of the following values:<br>XPBI_NORMAL = 1, XPBI_HOT = 2, XPBI_DISABLED = 3 |
| *fRedraw* | Optional. CTRUE or FALSE (redraws the button to reflect the changes). |

# <a name="SetImageFromFile"></a>SetImageFromFile

Loads an image from file and sets it as the image of the button.

```
SUB SetImageFromFile (BYREF wszPath AS WSTRING, BYVAL ImageState AS LONG, _
   BYVAL dimPercent AS LONG = 0, BYVAL bGrayScale AS LONG = FALSE, _
   BYVAL fRedraw AS LONG = FALSE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszPath* | Full path of the image's file. |
| *ImageState* | One of the following values:<br>XPBI_NORMAL = 1, XPBI_HOT = 2, XPBI_DISABLED = 3 |
| *dimPercent* | Percent of dimming (1-99) |
| *bGrayScale* | CTRUE or FALSE. Convert to gray scale. |
| *fRedraw* | Optional. CTRUE or FALSE (redraws the button to reflect the changes). |

# <a name="SetImageFromRes"></a>SetImageFromRes

Loads an image from file and sets it as the image of the button.

```
SUB SetImageFromRes (BYVAL hInstance AS HINSTANCE, BYREF wszImageName AS WSTRING, _
   BYVAL ImageState AS LONG, BYVAL dimPercent AS LONG = 0, _
   BYVAL bGrayScale AS LONG = FALSE, BYVAL fRedraw AS LONG = FALSE)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hInstance* | A handle to the module whose portable executable file or an accompanying MUI file contains the resource. If this parameter is NULL, the function searches the module used to create the current process. |
| *wszImageName* | Name of the image in the resource file (.RES). If the image resource uses an integral identifier, wszImage should begin with a number symbol (#) followed by the identifier in an ASCII format, e.g., "#998". Otherwise, use the text identifier name for the image. Only images embedded as raw data (type RCDATA) are valid. These must be icons in format .png, .jpg, .gif, .tiff. |
| *ImageState* | One of the following values:<br>XPBI_NORMAL = 1, XPBI_HOT = 2, XPBI_DISABLED = 3 |
| *dimPercent* | Percent of dimming (1-99) |
| *bGrayScale* | CTRUE or FALSE. Convert to gray scale. |
| *fRedraw* | Optional. CTRUE or FALSE (redraws the button to reflect the changes). |

# <a name="BkBrush"></a>BkBrush

Returns the background color brush.

```
PROPERTY BkBrush () AS HBRUSH
```

# <a name="ButtonBkColor"></a>ButtonBkColor

Gets/sets the background color of button.

```
PROPERTY ButtonBkColor () AS COLORREF
PROPERTY ButtonBkColor (BYVAL bkColor AS COLORREF)
```

| Parameter  | Description |
| ---------- | ----------- |
| *bkColor* | A COLORREF color value. Use the FreeBasic BGR function. |

#### Return value

The background color of the button as a COLORREF value.

#### Remarks

Only available if the button is not themed. Call **DisableTheming** to disable theming.

# <a name="ButtonBkColorDown"></a>ButtonBkColorDown

Gets/sets the background color of button when it is down (pressed or toggled).

```
PROPERTY ButtonBkColorDown () AS COLORREF
PROPERTY ButtonBkColorDown (BYVAL bkColorDown AS COLORREF)
```

| Parameter  | Description |
| ---------- | ----------- |
| *bkColorDown* | A COLORREF color value. Use the FreeBasic BGR function. |

#### Return value

The background color of button when it is down (pressed or toggled).

#### Remarks

Only available if the button is not themed. Call **DisableTheming** to disable theming.

# <a name="ButtonBkColorHot"></a>ButtonBkColorHot

Gets/sets the background color of button when it is hot (the mouse is over it).

```
PROPERTY ButtonBkColorHot () AS COLORREF
PROPERTY ButtonBkColorHot (BYVAL bkColorHot AS COLORREF)
```

| Parameter  | Description |
| ---------- | ----------- |
| *bkColorHot* | A COLORREF color value. Use the FreeBasic BGR function. |

#### Return value

The background color of button when it is hot (the mouse is over it).

#### Remarks

Only available if the button is not themed. Call **DisableTheming** to disable theming.

# <a name="ButtonState"></a>ButtonState

Returns the button state.

```
PROPERTY ButtonState () AS LONG
```

#### Return value

The button state: Pushed (BST_PUSHED) or unpushed.

# <a name="Cursor"></a>Cursor

Gets/sets the cursor for the button.

```
PROPERTY Cursor () AS HCURSOR
PROPERTY Cursor (BYVAL hCursor AS HCURSOR)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hCursor* | Handle to the cursor. |

#### Return value

The cursor handle.

