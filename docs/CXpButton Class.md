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
| [Toggle](#Toggle) | Gets/sets button to toggle state (CTRUE) or to pushbutton state (FALSE). |
| [ToggleState](#ToggleState) | Gets/sets the toggle state: pushed (CTRUE) or unpushed (FALSE). |
