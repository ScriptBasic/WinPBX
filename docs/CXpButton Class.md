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


