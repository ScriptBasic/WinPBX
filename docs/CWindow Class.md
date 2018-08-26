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
| [Creating the main window](Topic1) |
| [Getting a pointer to the CWindow class](Topic2) |
| [Adding controls](Topic3) |
| [Popup windows](Topic4) |
| [Using PNG icons in toolbars](Topic5) |
| [Keyboard accelerators](Topic7) |
| [Scrollable windows](Topic8) |
| [TabPages](Topic9) |
| [Layout Manager](Topic10) |


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
