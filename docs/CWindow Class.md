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
| [Keyboard accelerators](#Topic6) |
| [Scrollable windows](#Topic7) |
| [MDI WIndows](#Topic8) |
| [TabPages](#Topic9) |
| [Layout Manager](#Topic10) |

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

# <a name="Topic1"></a>Creating the main window

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
