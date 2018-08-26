# CWindow Class

**CWindow** is a powerful class to easily create Graphical User Interfaces for Windows applications.

#### Main features

* Easy creation of Graphical User Interfaces.
* 100% compatible with the Windows API.
* Optional default values for window styles and extended styles.
* High DPI and Unicode support for windows and controls.
* Support for alpha blended icons and images.
* Easy subclassing of child controls.
* Easy management of tab controls and tab pages
* MDI (Multiple Document Interface) support

#### Remarks

The default **CWindow_WindowProc** and **CWindowMDIProc** callback procedures have just the needed code to work; you must use your own instead.

The default message pump (**CWindow.DoEvents**), should be enough for most applications, but you can replace it with your own.

**Include file**: CWindow.inc.

# Constructor

Registers the class name and initializes the common controls library.

```
CONSTRUCTOR CWindow (BYREF wszClassName AS CONST WSTRING = "")
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszClassName* | Optional. The name of the class name to register. If omitted, the class will use "FBWindowClass:" and a number as the class name. |

#### Usage examples

```
DIM pWindow AS CWindow
```
```
DIM pWindow AS CWindow = "MyClassName"
```

### Tutorial

| Topic      |
| ---------- |
| [Creating the main window](#Topic1) |
| [Getting a pointer to the CWindow class](#Topic2) |
| [Adding controls](#Topic3) |
| [Popup windows](#Topic4) |
| [Using PNG icons in toolbars](#Topic5) |
| [Visual style menus](#Topic6) |
| [Keyboard accelerators](#Topic7) |
| [Scrollable windows](#Topic8) |
| [TabPages](#Topic9) |
| [Layout Manager](#Topic10) |
| [MDI WIndows](#Topic11) |

### Methods and Properties

| Name       | Description |
| ---------- | ----------- |
| [AccelHandle](#AccelHandle) | Gets/sets the accelerator table handle. |
| [AddAccelerator](#AddAccelerator) | Adds an accelerator key to the table. |
| [AddControl](#AddControl) | Adds a control to the window. |
| [BigIcon](#BigIcon) | Associates a new large icon with the main window. |
| [Brush](#Brush) | Gets/sets the background brush. |
| [Center](#Center) | Centers a window on the screen or over another window. |
| [ClassStyle](#ClassStyle) | Gets/sets the style of the class. |
| [ClientHeight](#ClientHeight) | Returns the unscaled client height of the main window. |
| [ClientWidth](#ClientWidth) | Returns the unscaled client width of the window. |
| [ControlClientHeight](#ControlClientHeight) | Returns the unscaled client height of the specified window. |
| [ControlClientWidth](#ControlClientWidth) | Returns the unscaled client width of the specified window. |
| [ControlHandle](#ControlHandle) | Retrieves a handle to the child control specified by its identifier. |
| [ControlHeight](#ControlHeight) | Returns the unscaled height of the specified window. |
| [ControlWidth](#ControlWidth) | Returns the unscaled width of the specified window. |
| [Create](#Create) | Creates a new window. |
| [CreateAcceleratorTable](#CreateAcceleratorTable) | Creates the accelerator table. |
| [CreateFont](#CreateFont) | Creates a DPI aware logical font. |
| [CreateMDIWindow](#CreateMDIWindow) | Creates a new MDI window. |
| [DefaultFontSize](#DefaultFontSize) | Gets/sets the point size of the default font. |
| [DestroyAcceleratorTable](#DestroyAcceleratorTable) | Destroys the accelerator table. |
| [DoEvents](#DoEvents) | Processes windows messages. |
| [DPI](#DPI) | Gets/sets the DPI (dots per inch) to be used by the application. |
| [Font](#Font) | Gets/sets the font used as default. |
| [GetClientRect](#GetClientRect) | Retrieves the unscaled coordinates of the main window client area. |
| [GetControlClientRect](#GetControlClientRect) | Retrieves the unscaled coordinates of a window's client area. |
| [GetControlWindowRect](#GetControlWindowRect) | Retrieves the unscaled dimensions of the bounding rectangle of the specified window. |
| [GetWindowRect](#GetWindowRect) | Retrieves the unscaled dimensions of the bounding rectangle of the main window. |
| [GetWorkArea](#GetWorkArea) | Retrieves the unscaled size of the work area on the primary display monitor. |
| [Height](#Height) | Returns the unscaled height of the main window. |
| [hWindow](#hWindow) | Gets/sets the main window handle. |
| [hwndClient](#hwndClient) | Gets the MDI client window handle. |
| [InstanceHandle](#InstanceHandle) | Gets/sets the instance handle. |
| [MDICLassName](#MDICLassName) | Sets the class name of the MDI frame window. |
| [MoveWindow](#MoveWindow) | Changes the position and dimensions of the specified window. |
| [Resize](#Resize) | Resizes the window sending a WM_SIZE message with the  SIZE_RESTORED value. |
| [rxRatio](#rxRatio) | Returns the horizontal scaling ratio. |
| [ryRatio](#ryRatio) | Returns the vertical scaling ratio. |
| [ScaleX](#ScaleX) | Scales an horizontal coordinate according the DPI setting. |
| [ScaleY](#ScaleY) | Scales a vertical coordinate according the DPI setting. |
| [ScrollWindowPtr](#ScrollWindowPtr) | Gets/sets a pointer to the scroll window class. |
| [SetClientSize](#SetClientSize) | Adjusts the bounding rectangle of the window based on the desired size of the client area. |
| [SetFont](#SetFont) | Creates a DPI aware logical font and sets it as the default font. |
| [SetWindowPos](#SetWindowPos) | Changes the size, position, and Z order of a child, pop-up, or top-level window. |
| [SmallIcon](#SmallIcon) | Associates a new small icon with the main window. |
| [UnScaleX](#UnScaleX) | Unscales an horizontal coordinate according the DPI setting. |
| [UnScaleY](#UnScaleY) | Unscales a vertical coordinate according the DPI setting. |
| [UserData](#UserData) | Gets/sets a value in the user data area of the window. |
| [Width](#Width) | Returns the unscaled width of the main window. |
| [WindowExStyle](#WindowExStyle) | Gets/sets the window extended styles. |
| [WindowStyle](#WindowStyle) | Gets/sets the window styles. |

### Procedures

| Name       | Description |
| ---------- | ----------- |
| [AfxCWindowPtr](#AfxCWindowPtr) | Returns a pointer to the CWindow class given the handle of the main window or the CREATESTRUCT structure associated with it. |
| [AfxCWindowOwnerPtr](#AfxCWindowOwnerPtr) | Returns a pointer to the CWindow class given the handle of the window created with it or the handle of any of it's children windows or controls. |
| [AfxScrollWindowPtr](#AfxScrollWindowPtr) | Returns a pointer to the CScrollWindow class given the handle of the window attached to it. |

### Dialog

| Name       | Description |
| ---------- | ----------- |
| [AfxInputBox](#AfxInputBox) | Input box dialog. |

# CLayout Class

This class allows to anchor child windows to a parent window. When the parent window is resized, it manages the location and size of the anchored child windows according to the new dimensions of the parent.

| Name       | Description |
| ---------- | ----------- |
| [Constructor](#Constructor_Layout) | Creates an instance of the CLayout class. |
| [AnchorControl](#AnchorControl) | Anchors a window or control to its parent window. |
| [AdjustControls](#AdjustControls) | Adjusts the size and location of the child controls to the dimensions of its parent window. |

# CTabPage Class

Creates a generic window used as a tab page of a tab control.

### Methods

| Name       | Description |
| ---------- | ----------- |
| [hTabPage](#hTabPage) | Returns the window handle of the tab page. |
| [InsertPage](#InsertPage) | Adds a tab page and creates a generic window that will be associated with the page. |

### Procedures

| Name       | Description |
| ---------- | ----------- |
| [AfxCTabPagePtr](#AfxCTabPagePtr) | Returns a pointer to the **CTabPage** class given the handle of the tab control to which the tab page is associated and the zero-based tab index. |
| [AfxDestroyTabPage](#AfxDestroyTabPage) | Detroys a tab page. |
| [AfxDestroyAllTabPages](#AfxDestroyAllTabPages) | Detroys all the tab pages. |
| [AfxResizeTabPages](#AfxResizeTabPages) | Resizes all the tab pages associated with a tab control. |
| [AfxScrollTabPagePtr](#AfxScrollTabPagePtr) | Returns a pointer to the CScrollWindow class given the handle of the tab control to which the tab page is associated and the zero-based tab index. |

### <a name="Topic1"></a>Creating the main window

To use **CWindow** you must first include "CWindow.inc" and allow all symbols of its namespace to be accessed adding **USING Afx**.

```
#INCLUDE ONCE "CWindow.inc"
USING Afx
```

The first step is to create an instance of the class:

```
DIM pWindow AS CWindow
```

The **CWindow** constructor registers a class for the window with the name "FBWindowClass:xxx", where xxx is a counter number. Alternatively, you can force the use of your own class name by specifying it, e.g.

```
DIM pWindow AS CWindow = "MyClassName"
```

The constructor also checks if the application is DPI aware and calculates de scaling ratios and the default font name and point size ("Tahoma", 8 pt, for Windows XP and below; "Segoe UI", 9 pt, for Windows Vista and above").

You can override it by setting your own DPI and/or font before creating the window, e.g.

```
DIM pWindow AS CWindow
pWindow. DPI = 96
pWindow.SetFont("Times New Roman", 10, FW_NORMAL, , , , DEFAULT_CHARSET)
```

By default, **CWindow** uses a standard COLOR_3DFACE + 1 brush. You can override it calling the **Brush** property:

```
DIM pWindow AS CWindow
pWindow.Brush = GetStockObject(WHITE_BRUSH)
```

This makes the background of the window white.

The window class uses CS_HREDRAW OR CS_VREDRAW as default window styles. Without them, the background is not repainted and the controls leave garbage in it when resized. With them, windows with many controls cause heavy flicker. To avoid flicker, you can change the windows style using e.g. pWindow.ClassStyle = CS_DBLCLKS and take care yourself of repainting.

The next step is to create the window.

The **Create** method has many parameters, all of which are optional:

```
hParent     = Parent window handle
wszTitle    = Window caption
lpfnWndProc = Address of the callback function
x           = Horizontal position
y           = Vertical position
nWidth      = Window width
nHeight     = Window height
dwStyle     = Window style
dwExStyle   = Extended style
```

The most verbose way to call it is:

```
DIM hwndMain AS HWND = pWindow.Create(NULL, "CWindow Test", @WndProc, 0, 0, 525, 395, _
   WS_OVERLAPPEDWINDOW OR WS_CLIPCHILDREN OR WS_CLIPSIBLINGS, WS_EX_CONTROLPARENT OR WS_EX_WINDOWEDGE)
```

But just using

```
pWindow.Create
```

a working window is created and sized using CW_USEDEFAULT.

Unless the window has to use all the available desktop space, it may be preferible to use the **SetClientSize** method to size the window because Windows UI elements such the caption and borders have different sizes depending of the Windows version and/or the styles used. Therefore, to make sure that you have enough room for your controls, sizing the window according the client size seems more adequate.

We may need to process Windows messages, so we need to provide a callback function, e.g.

```
' ========================================================================================
' Window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hWnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   SELECT CASE uMsg

      CASE WM_COMMAND
         SELECT CASE LOWORD(wParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application sending an WM_CLOSE message
               IF HIWORD(wParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT

    	CASE WM_DESTROY
         PostQuitMessage(0)
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProcW(hWnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
```

and we have to pass the address of that callback function:

```
pWindow.Create(NULL, "CWindow Test", @WndProc)
pWindow.SetClientSize(500, 320)   ' The size may vary
```

Optionally, we can automatically center the window in the destop calling the **Center** method, e.g.

```
pWindow.Create(NULL, "CWindow Test", @WndProc)
pWindow.SetClientSize(500, 320)   ' The size may vary
pWindow.Center
```

To process Windows messages we need a message pump. **CWindow** provides a default one calling the **DoEvents** method:

```
FUNCTION = pWindow.DoEvents(nCmdShow)
```

This default message pump displays the window and processes the messages. It can be used with most applications, but, in case of need, you can replace it with your own, e.g.

```
' // Displays the window
DIM hwndMain AS HWND = pWindow.hWindow
ShowWindow(hwndMain, nCmdShow)
UpdateWindow(hwndMain)

' // Processes Windows messages
DIM uMsg AS MSG
WHILE (GetMessageW(@uMsg, NULL, 0, 0) <> FALSE)
   IF IsDialogMessageW(hWndMain, @uMsg) = 0 THEN
      TranslateMessage(@uMsg)
      DispatchMessageW(@uMsg)
   END IF
WEND
FUNCTION = uMsg.wParam
```
Each instance of the **CWindow** class has an user data area consisting in an array of 99 LONG_PTR values that you can use to store information that you find useful.

These values are set and retrieved using the **UserData** property and an index from 0 to 99.

### <a name="Topic2"></a>Getting a pointer to the CWindow class

At any time, you can get a pointer to the **CWindow** class by using:

```
DIM pWindow AS CWindow PTR = CAST(CWindow PTR, GetWindowLongPtrW(hwnd, 0))
- or -
DIM pWindow AS CWindow PTR = AfxCWindowPtr(hwnd)
```
where *hwnd* is the handle of its associated window handle.

If the handle of the main window its not available, the function **AfxCWindowOwnerPtr** allows the use of the handle of any of it's child controls.

An special case is the WM_CREATE message.

At the time in which this message is processed in the window callback, **CWindow** has not yet been able to store the pointer in the extra bytes of the window class.

To solve this problem, the **Create** method passes the pointer to the class in the *lParam* parameter when calling the API function **CreateWindowEx** to create the window.

This pointer can be retrieved in WM_CREATE using:

```
CASE WM_CREATE
   DIM pCreateStruct AS CREATESTRUCT PTR = CAST(CREATESTRUCT PTR, lParam)
   DIM pWindow AS CWindow PTR = CAST(CWindow PTR, pCreateStruct->lpCreateParams)
- or -
CASE WM_CREATE
   DIM pWindow AS CWindow PTR = AfxCWindowPtr(lParam)
```

### <a name="Topic3"></a>Adding controls

To add controls to the window you can use the **AddControl** method. Alternatively, you can use the API function **CreateWindowEx**, but then you will have to do scaling by yourself.

Besides the registered class names for the controls, in many cases you can use easier to remember aliases. For example. you can use "STATUSBAR" instead of "MSCTLS_STATUSBAR32".

The **AddControl** method also provides default styles for all the Windows controls. Therefore, you can save typing unless you need to use different styles.

For example, to add a button you can use

```
pWindow.AddControl("Button", pWindow.hWindow, IDCANCEL, "&Close", 350, 250, 75, 23)
```

instead of

```
pWindow.AddControl("Button", pWindow.hWindow, IDCANCEL, "&Close", 350, 250, 75, 23, _
   WS_CHILD OR WS_VISIBLE OR WS_TABSTOP OR BS_PUSHBUTTON OR BS_CENTER OR BS_VCENTER
```

For a list of predefined class names and styles, see the **AddControl** method.

If the application is DPI aware, controls created with the **AddControl** method are scaled according to the DPI setting.

**AddControl** also provides two ways for easily subclassing a control.

For the first way, used before Windows XP, you need to pass the address of the subclassed procedure, e.g.

```
pWindow.AddControl("Button", pWindow.hWindow, IDC_BUTTON, "Click me", 350, 250, 75, 23, , , , CAST(WNDPROC, @Button_SubclassProc))
```

and use a callback like this one:

```
' ========================================================================================
' Processes messages for the subclassed Button window.
' ========================================================================================
FUNCTION Button_SubclassProc ( _
   BYVAL hwnd   AS HWND, _                 ' // Control window handle
   BYVAL uMsg   AS UINT, _                 ' // Type of message
   BYVAL wParam AS WPARAM, _               ' // First message parameter
   BYVAL lParam AS LPARAM _                ' // Second message parameter
   ) AS LRESULT

   SELECT CASE uMsg

      CASE WM_GETDLGCODE
         ' // All keyboard input
         FUNCTION = DLGC_WANTALLKEYS
         EXIT FUNCTION

      CASE WM_LBUTTONDOWN
         MessageBoxW(GetParent(hwnd), "Click", "FreeBasic", MB_OK)
         EXIT FUNCTION

      CASE WM_KEYDOWN
         SELECT CASE LOWORD(wParam)
            CASE VK_ESCAPE
               SendMessageW(GetParent(hwnd), WM_CLOSE, 0, 0)
               EXIT FUNCTION
         END SELECT

      CASE WM_DESTROY
         ' // REQUIRED: Remove control subclassing
         SetWindowLongPtrW hwnd, GWLP_WNDPROC, CAST(LONG_PTR, RemovePropW(hwnd, "OLDWNDPROC"))

   END SELECT

   FUNCTION = CallWindowProcW(GetPropW(hwnd, "OLDWNDPROC"), hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
```

The second way uses the API function **SetWindowSubclass**. Besides passing the address of the callback procedure, it allows to pass the identifier of the control and a pointer to the **CWindow** class.

```
pWindow.AddControl("Button", pWindow.hWindow, IDC_BUTTON, "Click me", 350, 250, 75, 23, , , , _
   CAST(WNDPROC, @Button_SubclassProc), IDC_BUTTON, CAST(DWORD_PTR, @pWindow))
```

The main advantage of this method is that we can use the same callback for all the subclassed controls and easily identify which one is firing the messages and also have a pointer to his parent **CWindow class** if we need to use it. **SetWindowSubclass** also eliminates the disadvantages of the old subclassing approach explained in this thread: [Subclassing Controls](https://docs.microsoft.com/en-us/windows/desktop/controls/subclassing-overview).

Example of a callback function for controls subclassed with this method:

```
' ========================================================================================
' Processes messages for the subclassed Button window.
' ========================================================================================
FUNCTION Button_SubclassProc ( _
   BYVAL hwnd   AS HWND, _                 ' // Control window handle
   BYVAL uMsg   AS UINT, _                 ' // Type of message
   BYVAL wParam AS WPARAM, _               ' // First message parameter
   BYVAL lParam AS LPARAM, _               ' // Second message parameter
   BYVAL uIdSubclass AS UINT_PTR, _        ' // The subclass ID
   BYVAL dwRefData AS DWORD_PTR _          ' // Pointer to reference data
   ) AS LRESULT

   SELECT CASE uMsg

      CASE WM_GETDLGCODE
         ' // All keyboard input
         FUNCTION = DLGC_WANTALLKEYS
         EXIT FUNCTION

      CASE WM_LBUTTONDOWN
         MessageBoxW(GetParent(hwnd), "Click", "FreeBasic", MB_OK)
         EXIT FUNCTION

      CASE WM_KEYDOWN
         SELECT CASE LOWORD(wParam)
            CASE VK_ESCAPE
               SendMessageW(GetParent(hwnd), WM_CLOSE, 0, 0)
               EXIT FUNCTION
         END SELECT

      CASE WM_DESTROY
         ' // REQUIRED: Remove control subclassing
         RemoveWindowSubclass hwnd, @Button_SubclassProc, uIdSubclass

   END SELECT

   FUNCTION = DefSubclassProc(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
```

Both of these methods are optional. Therefore, you can use your own way to subclass controls.

**Warning**: You cannot use the subclassing helper functions to subclass a window across threads.

### <a name="Topic4"></a>Popup windows

To create a popup window you simply create a new instance of the **CWindow** class and, in the **Create** method, you make it child of the main window and use the WS_POPUPWINDOW style.

```
DIM pWindow AS CWindow
pWindow.Create(hParent, "Popup window", @PopupWndProc, , , , , _
   WS_VISIBLE OR WS_CAPTION OR WS_POPUPWINDOW OR WS_THICKFRAME, WS_EX_WINDOWEDGE)
```

The window created this way is modeless. To make it modal, we need to disable the parent window:

```
CASE WM_CREATE
   EnableWindow GetParent(hwnd), FALSE
```

When the popup dialog is closed, we need to enable the parent window:

```
CASE WM_CLOSE
   ' // Enables parent window keeping parent's zorder
   EnableWindow GetParent(hwnd), CTRUE
```

#### Example

```
' ########################################################################################
' Microsoft Windows
' File: CW_PopupWindow.fbtpl
' Contents: CWindow with a modal popup window
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2016 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE ONCE "windows.bi"
#INCLUDE ONCE "Afx/CWindow.inc"
USING Afx

CONST IDC_POPUP = 1001

DECLARE FUNCTION WinMain (BYVAL hInstance AS HINSTANCE, _
                          BYVAL hPrevInstance AS HINSTANCE, _
                          BYVAL szCmdLine AS ZSTRING PTR, _
                          BYVAL nCmdShow AS LONG) AS LONG

   END WinMain(GetModuleHandleW(NULL), NULL, COMMAND(), SW_NORMAL)

DECLARE FUNCTION WndProc (BYVAL hWnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT
DECLARE FUNCTION PopupWindow (BYVAL hParent AS HWND) AS LONG
DECLARE FUNCTION PopupWndProc (BYVAL hWnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

' ========================================================================================
' Main
' ========================================================================================
FUNCTION WinMain (BYVAL hInstance AS HINSTANCE, _
                  BYVAL hPrevInstance AS HINSTANCE, _
                  BYVAL szCmdLine AS ZSTRING PTR, _
                  BYVAL nCmdShow AS LONG) AS LONG

   ' // Set process DPI aware
   AfxSetProcessDPIAware

   DIM pWindow AS CWindow
   pWindow.Create(NULL, "CWindow with a popup window", @WndProc)
   pWindow.SetClientSize(500, 320)
   pWindow.Center

   ' // Add a button without position or size (it will be resized in the WM_SIZE message).
   pWindow.AddControl("Button", pWindow.hWindow, IDC_POPUP, "&Popup", 350, 250, 75, 23)

   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hWnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   DIM hDC AS HDC
   DIM pPaint AS PAINTSTRUCT
   DIM rc AS RECT
   DIM pWindow AS CWindow PTR

   SELECT CASE uMsg

      CASE WM_CREATE
         EXIT FUNCTION

      CASE WM_COMMAND
         ' // If ESC key pressed, close the application sending an WM_CLOSE message
         SELECT CASE LOWORD(wParam)
            CASE IDCANCEL
               IF HIWORD(wParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
            CASE IDC_POPUP
               IF HIWORD(wParam) = BN_CLICKED THEN
                  PopupWindow(hwnd)
                  EXIT FUNCTION
               END IF
         END SELECT

      CASE WM_SIZE
         IF wParam <> SIZE_MINIMIZED THEN
            ' // Resize the buttons
            pWindow = CAST(CWindow PTR, GetWindowLongPtrW(hwnd, 0))
            pWindow->MoveWindow GetDlgItem(hwnd, IDCANCEL), pWindow->ClientWidth - 120, pWindow->ClientHeight - 50, 75, 23, CTRUE
         END IF

    	CASE WM_DESTROY
         PostQuitMessage(0)
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProcW(hWnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Popup window procedure
' ========================================================================================
FUNCTION PopupWindow (BYVAL hParent AS HWND) AS LONG

   DIM pWindow AS CWindow
   pWindow.Create(hParent, "Popup window", @PopupWndProc, , , , , _
      WS_VISIBLE OR WS_CAPTION OR WS_POPUPWINDOW OR WS_THICKFRAME, WS_EX_WINDOWEDGE)
   pWindow.Brush = GetStockObject(WHITE_BRUSH)
   pWindow.SetClientSize(300, 200)
   pWindow.Center(pWindow.hWindow, hParent)
   ' / Process Windows messages
   FUNCTION = pWindow.DoEvents

END FUNCTION
' ========================================================================================

' ========================================================================================
' Popup window procedure
' ========================================================================================
FUNCTION PopupWndProc (BYVAL hWnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   DIM hOldFont AS HFONT
   STATIC hNewFont AS HFONT

   SELECT CASE uMsg

      CASE WM_CREATE
         ' // Get a pointer to the CWindow class from the CREATESTRUCT structure
         DIM pCreateStruct AS CREATESTRUCT PTR = CAST(CREATESTRUCT PTR, lParam)
         DIM pWindow AS CWindow PTR = CAST(CWindow PTR, pCreateStruct->lpCreateParams)
         ' // Create a new font scaled according the DPI ratio
         IF pWindow->DPI <> 96 THEN hNewFont = pWindow->CreateFont("Tahoma", 9)
         ' Disable parent window to make popup window modal
         EnableWindow GetParent(hwnd), FALSE
         EXIT FUNCTION

      CASE WM_COMMAND
         SELECT CASE LOWORD(wParam)
            ' // If ESC key pressed, close the application sending an WM_CLOSE message
            CASE IDCANCEL
               IF HIWORD(wParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT

      CASE WM_PAINT
    		DIM rc AS RECT, ps AS PAINTSTRUCT, hDC AS HANDLE
         hDC = BeginPaint(hWnd, @ps)
         IF hNewFont THEN hOldFont = CAST(HFONT, SelectObject(hDC, CAST(HGDIOBJ, hNewFont)))
         GetClientRect(hWnd, @rc)
         DrawTextW(hDC, "Hello, World!", -1, @rc, DT_SINGLELINE or DT_CENTER or DT_VCENTER)
         IF hNewFont THEN SelectObject(hDC, CAST(HGDIOBJ, CAST(HFONT, hOldFont)))
         EndPaint(hWnd, @ps)
         EXIT FUNCTION

      CASE WM_CLOSE
         ' // Enables parent window keeping parent's zorder
         EnableWindow GetParent(hwnd), CTRUE
         ' // Don't exit; let DefWindowProcW perform the default action

    	CASE WM_DESTROY
         ' // Destroy the new font
         IF hNewFont THEN DeleteObject(CAST(HGDIOBJ, hNewFont))
         ' // End the application by sending an WM_QUIT message
         PostQuitMessage(0)
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProcW(hWnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
```

### <a name="Topic5"></a>Using PNG icons in toolbars

**AfxGdiplus.inc** provides functions that allow to use alphablended PNG icons in toolbars.

**AfxGdipIconFromFile** loads the images from disk and **AfxGdipIconFromRes** from a resource file embedded in the application.

We need to create an image list for the toolbar of the appropriate size. To calculate the size, I'm using the following formula: 16 * pWindow.DPI \ 96. Where 16 is the size of a normal icon (for toolbars it may be preferible to use 20 to make them a bit bigger), pWindow.DPI the DPI being used by the computer and 96 the DPI used by applications that are not DPI aware.

```
' // Create an image list for the toolbar
DIM hImageList AS HIMAGELIST
DIM cx AS LONG = 16 * pWindow.DPI \ 96
hImageList = ImageList_Create(cx, cx, ILC_COLOR32 OR ILC_MASK, 4, 0)
IF hImageList THEN
   AfxGdipAddIconFromRes(hImageList, hInst, "IDI_ARROW_LEFT_32")
   AfxGdipAddIconFromRes(hImageList, hInst, "IDI_ARROW_RIGHT_48")
   AfxGdipAddIconFromRes(hImageList, hInst, "IDI_HOME_48")
   AfxGdipAddIconFromRes(hImageList, hInst, "IDI_SAVE_48")
END IF
SendMessageW hToolBar, TB_SETIMAGELIST, 0, CAST(LPARAM, hImageList)
```

We are using 48 bit icons in this example, that usually resize well to adapt to different DPI settings. This way, we can use only a set of icons instead of several sets of icons of different sizes. However, for best quality, it is advisable to use the appropriate icon size.

**AfxGdipIconFromFile** and **AfxGdipIconFromRes** also provide two optional parameters, *dimPercent* and *bGrayScale*. With *dimPercent* you can indicate a percentage of dimming, and *bGrayScale* is a boolean value (TRUE or FALSE) that tells these functions to convert the icon colors to shades of gray. This allows to create an image list for disabled items with the same icon set. The following code creates a disabled image using the same color PNG icons, but dimming them a 60% and converting them to gray:

```
' // Create a disabled image list for the toolbar
DIM hDisabledImageList AS HIMAGELIST
DIM cx AS LONG = 16 * pWindow.DPI \ 96
hDisabledImageList = ImageList_Create(cx, cx, ILC_COLOR32 OR ILC_MASK, 4, 0)
IF hDisabledImageList THEN
   AfxGdipAddIconFromRes(hDisabledImageList, hInst, "IDI_ARROW_LEFT_32", 60, TRUE))
   AfxGdipAddIconFromRes(hDisabledImageList, hInst, "IDI_ARROW_RIGHT_48", 60, TRUE))
   AfxGdipAddIconFromRes(hDisabledImageList, hInst, "IDI_HOME_48", 60, TRUE))
   AfxGdipAddIconFromRes(hDisabledImageList, hInst, "IDI_SAVE_48", 60, TRUE))
END IF
SendMessageW hToolBar, TB_SETDISABLEDIMAGELIST, 0, CAST(LPARAM, hDisabledImageList)
```

**Resource file**:

```
//=============================================================================
// Manifest
//=============================================================================

1 24 "WThemes.xml"

//=============================================================================
// Toolbar icons
//=============================================================================

// Toolbar, normal
IDI_ARROW_LEFT_48       RCDATA "arrow_left_48.png"
IDI_ARROW_RIGHT_48      RCDATA "arrow_right_48.png"
IDI_HOME_48             RCDATA "home_48.png"
IDI_SAVE_48             RCDATA "save_48.png"

Manifest:

<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
   <assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0" xmlns:asmv3="urn:schemas-microsoft-com:asm.v3">

      <assemblyIdentity version="1.0.0.0"
         processorArchitecture="*"
         name="ApplicationName"
         type="win32"/>
      <description>Optional description of your application</description>

      <asmv3:application>
         <asmv3:windowsSettings xmlns="http://schemas.microsoft.com/SMI/2005/WindowsSettings">
            <dpiAware>true</dpiAware>
         </asmv3:windowsSettings>
      </asmv3:application>

      <!-- Compatibility section -->
      <compatibility xmlns="urn:schemas-microsoft-com:compatibility.v1">
         <application>
            <!--The ID below indicates application support for Windows Vista -->
            <supportedOS Id="{e2011457-1546-43c5-a5fe-008deee3d3f0}"/>
            <!--The ID below indicates application support for Windows 7 -->
            <supportedOS Id="{35138b9a-5d96-4fbd-8e2d-a2440225f93a}"/>
            <!--This Id value indicates the application supports Windows 8 functionality-->
            <supportedOS Id="{4a2f28e3-53b9-4441-ba9c-d69d4a4a6e38}"/>
            <!--This Id value indicates the application supports Windows 8.1 functionality-->
            <supportedOS Id="{1f676c76-80e1-4239-95bb-83d0f6d0da78}"/>
         </application>
       </compatibility>

      <!-- Trustinfo section -->
      <trustInfo xmlns="urn:schemas-microsoft-com:asm.v2">
         <security>
            <requestedPrivileges>
               <requestedExecutionLevel
                  level="asInvoker"
                  uiAccess="false"/>
               </requestedPrivileges>
         </security>
      </trustInfo>

      <dependency>
         <dependentAssembly>
            <assemblyIdentity
               type="win32"
               name="Microsoft.Windows.Common-Controls"
               version="6.0.0.0"
               processorArchitecture="*"
               publicKeyToken="6595b64144ccf1df"
               language="*" />
         </dependentAssembly>
      </dependency>

   </assembly>
```

#### Example

```
' ########################################################################################
' Microsoft Windows
' Contents: CWindow with a toolbar
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2016 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#define unicode
#INCLUDE ONCE "windows.bi"
#INCLUDE ONCE "Afx/CWindow.inc"
#INCLUDE ONCE "Afx/AfxCtl.inc"
#INCLUDE ONCE "Afx/AfxGdiplus.inc"
USING Afx

DECLARE FUNCTION WinMain (BYVAL hInstance AS HINSTANCE, _
                          BYVAL hPrevInstance AS HINSTANCE, _
                          BYVAL szCmdLine AS ZSTRING PTR, _
                          BYVAL nCmdShow AS LONG) AS LONG

   END WinMain(GetModuleHandleW(NULL), NULL, COMMAND(), SW_NORMAL)

CONST IDC_TOOLBAR = 1001
enum
   IDM_LEFTARROW = 28000
   IDM_RIGHTARROW
   IDM_HOME
   IDM_SAVEFILE
end enum

' ========================================================================================
' Window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hwnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   DIM pWindow AS CWindow PTR

   SELECT CASE uMsg

      CASE WM_CREATE
         EXIT FUNCTION

      CASE WM_COMMAND
         SELECT CASE LOWORD(wParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application sending an WM_CLOSE message
               IF HIWORD(wParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
'            CASE IDM_CUT   ' etc.
'               MessageBoxW hwnd, "You have clicked the Cut button", "Toolbar", MB_OK
'               EXIT FUNCTION
         END SELECT

      CASE WM_SIZE
         IF wParam <> SIZE_MINIMIZED THEN
            ' // Update the size and position of the Toolbar control
            SendMessageW GetDlgItem(hWnd, IDC_TOOLBAR), TB_AUTOSIZE, 0, 0
            ' // Resize the buttons
            pWindow = CAST(CWindow PTR, GetWindowLongPtrW(hwnd, 0))
            pWindow->MoveWindow GetDlgItem(hwnd, IDCANCEL), pWindow->ClientWidth - 95, pWindow->ClientHeight - 35, 75, 23, CTRUE
         END IF

    	CASE WM_DESTROY
         ' // Destroy the image list
         ImageList_Destroy CAST(HIMAGELIST, SendMessageW(GetDlgItem(hwnd, IDC_TOOLBAR), TB_SETIMAGELIST, 0, 0))
         PostQuitMessage(0)
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProcW(hWnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main
' ========================================================================================
FUNCTION WinMain (BYVAL hInstance AS HINSTANCE, _
                  BYVAL hPrevInstance AS HINSTANCE, _
                  BYVAL szCmdLine AS ZSTRING PTR, _
                  BYVAL nCmdShow AS LONG) AS LONG

   ' // Set process DPI aware
'   AfxSetProcessDPIAware

   DIM pWindow AS CWindow
   pWindow.Create(NULL, "CWindow with a toolbar", @WndProc)
   ' // Disable background erasing
   pWindow.ClassStyle = CS_DBLCLKS
   ' // Set the client size
   pWindow.SetClientSize(600, 300)
   ' // Center the window
   pWindow.Center

   ' // Add a button
   pWindow.AddControl("Button", pWindow.hWindow, IDCANCEL, "&Close")

   ' // Add a tooolbar
   DIM hToolBar AS HWND = pWindow.AddControl("Toolbar", pWindow.hWindow, IDC_TOOLBAR)
   ' // Module instance handle
   DIM hInst AS HINSTANCE = GetModuleHandle(NULL)
   ' // Create an image list for the toolbar
   DIM hImageList AS HIMAGELIST
   DIM cx AS LONG = 16 * pWindow.DPI \ 96
   hImageList = ImageList_Create(cx, cx, ILC_COLOR32 OR ILC_MASK, 4, 0)
   IF hImageList THEN
      ImageList_ReplaceIcon(hImageList, -1, AfxGdipIconFromRes(hInst, "IDI_ARROW_LEFT_48"))
      ImageList_ReplaceIcon(hImageList, -1, AfxGdipIconFromRes(hInst, "IDI_ARROW_RIGHT_48"))
      ImageList_ReplaceIcon(hImageList, -1, AfxGdipIconFromRes(hInst, "IDI_HOME_48"))
      ImageList_ReplaceIcon(hImageList, -1, AfxGdipIconFromRes(hInst, "IDI_SAVE_48"))
   END IF
   SendMessageW hToolBar, TB_SETIMAGELIST, 0, CAST(LPARAM, hImageList)

   ' // Add buttons to the toolbar
   Toolbar_AddButton hToolBar, 0, IDM_LEFTARROW
   Toolbar_AddButton hToolBar, 1, IDM_RIGHTARROW
   Toolbar_AddButton hToolBar, 2, IDM_HOME
   Toolbar_AddButton hToolBar, 3, IDM_SAVEFILE

   ' // Size the toolbar
   SendMessageW hToolBar, TB_AUTOSIZE, 0, 0

   ' // Process event messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================
```

### <a name="Topic6"></a>Visual style menus

Windows Vista and posterior Windows versions provide menus that are part of the visual schema. These menus are rendered using visual styles, which can be added to existing applications. Adding code for new features to existing code must be done carefully to avoid breaking existing application behavior. Certain situations can cause visual styling to be disabled in an application. These situations include:

* Customizing menus using owner-draw menu items (MFT_OWNERDRAW)
* Using menu breaks (MFT_MENUBREAK or MFT_MENUBARBREAK)
* Using HBMMENU_CALLBACK to defer bitmap rendering
* Using a destroyed menu handle

These situations prevent visual style menus from being rendered. Owner-draw menus can be used in Windows Vista and posterior Windows versions, but the menus will not be visually styled. Windows Vista and posterior Windows versions provide alpha-blended bitmaps, which enables menu items to be shown without using owner-draw menu items.

**Requirements**:

* The bitmap is a 32bpp DIB section.
* The DIB section has BI_RGB compression.
* The bitmap contains pre-multiplied alpha pixels.
* The bitmap is stored in hbmpChecked, hbmpUnchecked, or hbmpItem fields.

**Note**: MFT_BITMAP items do not support PARGB32 bitmaps.

The **AfxAddIconToMenuItem** function included in **AfxMenu.inc** allows to use alphablended icons in visually styled menus.

```
DIM hSubMenu AS HMENU = GetSubMenu(hMenu, 1)
DIM hIcon AS HICON
hIcon = LoadImageW(NULL, "MyIcon.ico", IMAGE_ICON, 32, 32, LR_LOADFROMFILE)
IF hIcon THEN AfxAddIconToMenuItem(hSubMenu, 0, TRUE, hIcon)
```

PNG icons can be used by converting them first to an icon with **AfxGdipImageFromFile**:

```
hIcon = AfxGdipImageFromFileEx("MyIcon.png")
IF hIcon THEN AfxAddIconToMenuItem(hSubMenu, 0, TRUE, hIcon)
```

But, in general, we are more interested in loading the icons from a resource file embedded in the application. We can achieve it using the **AfxGdipIconFromRes** function.

```
DIM hSubMenu AS HMENU = GetSubMenu(hMenu, 0)
AfxAddIconToMenuItem(hSubMenu, 0, TRUE, AfxGdipIconFromRes(hInst, "IDI_ARROW_LEFT_48"))
```

The following code uses the same resource file that the one for the "Using PNG icons in toolbars example" to demonstrate that we can use just one set of icons for both toolbars and menus.

```
' ########################################################################################
' Microsoft Windows
' Contents: CWindow with a menu
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2016 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#define _WIN32_WINNT &h0602
#INCLUDE ONCE "windows.bi"
#INCLUDE ONCE "win/uxtheme.bi"
#INCLUDE ONCE "Afx/CWindow.inc"
#INCLUDE ONCE "Afx/AfxGdiplus.inc"
#INCLUDE ONCE "Afx/AfxMenu.inc"
using Afx

' // Menu identifiers
#define IDM_UNDO     1001   ' Undo
#define IDM_REDO     1002   ' Redo
#define IDM_HOME     1003   ' Home
#define IDM_SAVE     1004   ' Save file
#define IDM_EXIT     1005   ' Exit

DECLARE FUNCTION WinMain (BYVAL hInstance AS HINSTANCE, _
                          BYVAL hPrevInstance AS HINSTANCE, _
                          BYVAL szCmdLine AS ZSTRING PTR, _
                          BYVAL nCmdShow AS LONG) AS LONG

   END WinMain(GetModuleHandleW(NULL), NULL, COMMAND(), SW_NORMAL)

' ========================================================================================
' Build the menu
' ========================================================================================
FUNCTION BuildMenu () AS HMENU

   DIM hMenu AS HMENU
   DIM hPopUpMenu AS HMENU

   hMenu = CreateMenu
   hPopUpMenu = CreatePopUpMenu
      AppendMenuW hMenu, MF_POPUP OR MF_ENABLED, CAST(UINT_PTR, hPopUpMenu), "&File"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_UNDO, "&Undo" & CHR(9) & "Ctrl+U"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_REDO, "&Redo" & CHR(9) & "Ctrl+R"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_HOME, "&Home" & CHR(9) & "Ctrl+H"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_SAVE, "&Save" & CHR(9) & "Ctrl+S"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_EXIT, "E&xit" & CHR(9) & "Alt+F4"
   FUNCTION = hMenu

END FUNCTION
' ========================================================================================

' ========================================================================================
' Window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hWnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   SELECT CASE uMsg

      CASE WM_CREATE
         EXIT FUNCTION

      CASE WM_COMMAND
         SELECT CASE LOWORD(wParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application sending an WM_CLOSE message
               IF HIWORD(wParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
            CASE IDM_UNDO
               MessageBox hwnd, "Undo option clicked", "Menu", MB_OK
               EXIT FUNCTION
            CASE IDM_REDO
               MessageBox hwnd, "Redo option clicked", "Menu", MB_OK
               EXIT FUNCTION
            CASE IDM_HOME
               MessageBox hwnd, "Home option clicked", "Menu", MB_OK
               EXIT FUNCTION
            CASE IDM_SAVE
               MessageBox hwnd, "Save option clicked", "Menu", MB_OK
               EXIT FUNCTION
         END SELECT

    	CASE WM_DESTROY
         PostQuitMessage(0)
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProcW(hWnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main
' ========================================================================================
FUNCTION WinMain (BYVAL hInstance AS HINSTANCE, _
                  BYVAL hPrevInstance AS HINSTANCE, _
                  BYVAL szCmdLine AS ZSTRING PTR, _
                  BYVAL nCmdShow AS LONG) AS LONG

   ' // Set process DPI aware
   AfxSetProcessDPIAware

   DIM pWindow AS CWindow
   pWindow.Create(NULL, "CWindow with a menu", @WndProc)
   pWindow.SetClientSize(400, 250)
   pWindow.Center

   ' // Add a button
   pWindow.AddControl("Button", pWindow.hWindow, IDCANCEL, "&Close", 280, 180, 75, 23)

   ' // Module instance handle
   DIM hInst AS HINSTANCE = GetModuleHandle(NULL)

   ' // Create the menu
   DIM hMenu AS HMENU = BuildMenu
   SetMenu pWindow.hWindow, hMenu

   ' // Add icons to the items of the File menu
   DIM hSubMenu AS HMENU = GetSubMenu(hMenu, 0)
   AfxAddIconToMenuItem(hSubMenu, 0, TRUE, AfxGdipIconFromRes(hInst, "IDI_ARROW_LEFT_48"))
   AfxAddIconToMenuItem(hSubMenu, 1, TRUE, AfxGdipIconFromRes(hInst, "IDI_ARROW_RIGHT_48"))
   AfxAddIconToMenuItem(hSubMenu, 2, TRUE, AfxGdipIconFromRes(hInst, "IDI_HOME_48"))
   AfxAddIconToMenuItem(hSubMenu, 3, TRUE, AfxGdipIconFromRes(hInst, "IDI_SAVE_48"))

   ' // Process Windows messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================
```

### <a name="Topic7"></a>Keyboard Accelerators

Accelerators are closely related to menus — both provide the user with access to an application's command set. Typically, users rely on an application's menus to learn the command set and then switch over to using accelerators as they become more proficient with the application. Accelerators provide faster, more direct access to commands than menus do. At a minimum, an application should provide accelerators for the more commonly used commands. Although accelerators typically generate commands that exist as menu items, they can also generate commands that have no equivalent menu items. 

Creating an accelerator table with **CWindow** is very simple. You only need to build the table with calls to the **AddAccelerator** method and then call the **CreateAcceleratorTable** method. The accelerator table will be destroyed automatically when the window is destroyed or the applications ends. If you need to change the accelerator table, you can first destroy it calling the **DestroyAcceleratorTable** method, build a new table with **AddAccelerator** and then call **CreateAcceleratorTable**.

```
' // Create a keyboard accelerator table
pWindow.AddAccelerator FVIRTKEY OR FCONTROL, "U", IDM_UNDO ' // Ctrl+U - Undo
pWindow.AddAccelerator FVIRTKEY OR FCONTROL, "R", IDM_REDO ' // Ctrl+R - Redo
pWindow.AddAccelerator FVIRTKEY OR FCONTROL, "H", IDM_HOME ' // Ctrl+H - Home
pWindow.AddAccelerator FVIRTKEY OR FCONTROL, "S", IDM_SAVE ' // Ctrl+S - Save
pWindow.CreateAcceleratorTable
```

#### Example

The following example creates a menu and an accelerator table.

```
' ########################################################################################
' Microsoft Windows
' Contents: CWindow with a menu
' Compiler: FreeBasic 32 & 64 bit
' Copyright (c) 2016 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE ONCE "windows.bi"
#INCLUDE ONCE "Afx/CWindow.inc"
#INCLUDE ONCE "Afx/AfxMenu.inc"
using Afx

' // Menu identifiers
#define IDM_UNDO     1001   ' Undo
#define IDM_REDO     1002   ' Redo
#define IDM_HOME     1003   ' Home
#define IDM_SAVE     1004   ' Save file
#define IDM_EXIT     1005   ' Exit

DECLARE FUNCTION WinMain (BYVAL hInstance AS HINSTANCE, _
                          BYVAL hPrevInstance AS HINSTANCE, _
                          BYVAL szCmdLine AS ZSTRING PTR, _
                          BYVAL nCmdShow AS LONG) AS LONG

   END WinMain(GetModuleHandleW(NULL), NULL, COMMAND(), SW_NORMAL)

' ========================================================================================
' Build the menu
' ========================================================================================
FUNCTION BuildMenu () AS HMENU

   DIM hMenu AS HMENU
   DIM hPopUpMenu AS HMENU

   hMenu = CreateMenu
   hPopUpMenu = CreatePopUpMenu
      AppendMenuW hMenu, MF_POPUP OR MF_ENABLED, CAST(UINT_PTR, hPopUpMenu), "&File"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_UNDO, "&Undo" & CHR(9) & "Ctrl+U"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_REDO, "&Redo" & CHR(9) & "Ctrl+R"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_HOME, "&Home" & CHR(9) & "Ctrl+H"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_SAVE, "&Save" & CHR(9) & "Ctrl+S"
         AppendMenuW hPopUpMenu, MF_ENABLED, IDM_EXIT, "E&xit" & CHR(9) & "Alt+F4"
   FUNCTION = hMenu

END FUNCTION
' ========================================================================================

' ========================================================================================
' Window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hWnd AS HWND, BYVAL uMsg AS UINT, BYVAL wParam AS WPARAM, BYVAL lParam AS LPARAM) AS LRESULT

   SELECT CASE uMsg

      CASE WM_CREATE
         EXIT FUNCTION

      CASE WM_COMMAND
         SELECT CASE LOWORD(wParam)
            CASE IDCANCEL
               ' // If ESC key pressed, close the application sending an WM_CLOSE message
               IF HIWORD(wParam) = BN_CLICKED THEN
                  SendMessageW hwnd, WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
            CASE IDM_UNDO
               MessageBox hwnd, "Undo option clicked", "Menu", MB_OK
               EXIT FUNCTION
            CASE IDM_REDO
               MessageBox hwnd, "Redo option clicked", "Menu", MB_OK
               EXIT FUNCTION
            CASE IDM_HOME
               MessageBox hwnd, "Home option clicked", "Menu", MB_OK
               EXIT FUNCTION
            CASE IDM_SAVE
               MessageBox hwnd, "Save option clicked", "Menu", MB_OK
               EXIT FUNCTION
         END SELECT

    	CASE WM_DESTROY
         PostQuitMessage(0)
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProcW(hWnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main
' ========================================================================================
FUNCTION WinMain (BYVAL hInstance AS HINSTANCE, _
                  BYVAL hPrevInstance AS HINSTANCE, _
                  BYVAL szCmdLine AS ZSTRING PTR, _
                  BYVAL nCmdShow AS LONG) AS LONG

   ' // Set process DPI aware
   AfxSetProcessDPIAware

   DIM pWindow AS CWindow
   pWindow.Create(NULL, "CWindow with a menu", @WndProc)
   pWindow.SetClientSize(400, 250)
   pWindow.Center

   ' // Add a button
   DIM hButton AS HWND = pWindow.AddControl("Button", pWindow.hWindow, IDCANCEL, "&Close", 280, 180, 75, 23)
   SetFocus hButton

   ' // Module instance handle
   DIM hInst AS HINSTANCE = GetModuleHandle(NULL)

   ' // Create the menu
   DIM hMenu AS HMENU = BuildMenu
   SetMenu pWindow.hWindow, hMenu

   ' // Create a keyboard accelerator table
   pWindow.AddAccelerator FVIRTKEY OR FCONTROL, "U", IDM_UNDO ' // Ctrl+U - Undo
   pWindow.AddAccelerator FVIRTKEY OR FCONTROL, "R", IDM_REDO ' // Ctrl+R - Redo
   pWindow.AddAccelerator FVIRTKEY OR FCONTROL, "H", IDM_HOME ' // Ctrl+H - Home
   pWindow.AddAccelerator FVIRTKEY OR FCONTROL, "S", IDM_SAVE ' // Ctrl+S - Save
   pWindow.CreateAcceleratorTable

   ' // Process Windows messages
   FUNCTION = pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================
```
