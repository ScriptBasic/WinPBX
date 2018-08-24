# Windows Procedures

Assorted Windows procedures.

**Include File**: AfxWin.inc.

# Window

| Name       | Description |
| ---------- | ----------- |
| AfxCenterWindow | Centers a window on the screen or over another window. |
| AfxForceSetForegroundWindow | Brings the thread that created the specified window into the foreground and activates the window. |
| AfxGetTopEnabledWindow | Retrieves the handle of the enabled and visible window at the top of the z-order in an application. |
| AfxGetTopLevelParent | Retrieves the window's top-level parent window. |
| AfxGetTopLevelWindow | Retrieves the window's top-level parent or owner window. |
| AfxGetWindowClassName | Retrieves the name of the class to which the specified window belongs. |
| AfxGetWindowClientHeight | Returns the height of the client area of window, in pixels. |
| AfxGetWindowClientRect | Retrieves the coordinates of a window's client area. |
| AfxGetWindowClientWidth | Returns the width of the client area of a window, in pixels. |
| AfxGetWindowHeight | Returns the height of a window, in pixels. |
| AfxGetWindowLocation | Returns the location of the top left corner of the window, in pixels. |
| AfxGetWindowRect | Retrieves the dimensions of the bounding rectangle of the specified window. |
| AfxGetWindowText | Gets the text of a window. |
| AfxGetWindowTextLength | Gets the length of the text of a window. |
| AfxGetWindowWidth | Returns the width of a window, in pixels. |
| AfxGetWorkAreaHeight | Retrieves the height of the work area on the primary display monitor expressed in virtual screen coordinates. |
| AfxGetWorkAreaRect | Retrieves the coordinates of the work area on the primary display monitor expressed in virtual screen coordinates |
| AfxGetWorkAreaWidth | Retrieves the width of the work area on the primary display monitor expressed in virtual screen coordinates. |
| AfxRedrawNonClientArea | Redraws the non-client area of the specified window. |
| AfxRedrawWindow | Redraws the specified window. |
| AfxSetWindowClientSize | Adjusts the bounding rectangle of a window based on the desired size of the client area. |
| AfxSetWindowIcon | Associates a new large icon with a window. |
| AfxSetWindowLocation | Sets the location of the top left corner of the window, in pixels. |
| AfxSetWindowSize | Sets the size of the specified window, in pixels. |
| AfxSetWindowText | Sets the text of a window. |
| AfxShowWindowState | Sets the specified window's show state. |

# Messages

| Name       | Description |
| ---------- | ----------- |
| [AfxDoEvents](#AfxDoEvents) | Processes pending Windows messages. |
| [AfxForwardSizeMessage](#AfxForwardSizeMessage) | Sends a WM_SIZE message to the specified window. |
| [AfxPumpMessages](#AfxPumpMessages) | Processes pending Windows messages. |

# Handles

| Name       | Description |
| ---------- | ----------- |
| AfxGetControlHandle | Returns the handle of the control with the specified identifier. |
| AfxGetFormHandle | Finds the handle of the top-level window or MDI child window that is the ancestor of the specified window handle. |
| AfxGetHwndFromPID | Retrieves a window handle given it's process identifier. |
| AfxGetPathFromWindowHandle | Retrieves the path of the executable file that created the specified window. |

# Window styles

| Name       | Description |
| ---------- | ----------- |
| AfxAddWindowExStyle | Adds a new extended style to the specified window. |
| AfxAddWindowStyle | Adds a new style to the specified window. |
| AfxGetWindowExStyle | Retrieves the extended window styles. |
| AfxGetWindowStyle | Retrieves the window styles. |
| AfxRemoveWindowExStyle | Removes an extended style from the specified window. |
| AfxRemoveWindowStyle | Removes a style from the specified window. |
| AfxSetWindowExStyle | Sets the extended style(s) of the specified window. |
| AfxSetWindowStyle | Sets the style(s) of the specified window. |

# Display

| Name       | Description |
| ---------- | ----------- |
| AfxForceVisibleDisplay | Force visibility of an off-screen window. |
| AfxGetDisplayBitsPerPixel | Returns the color resolution, in bits per pixel, of the display device. |
| AfxGetDisplayFrequency | Returns the frequency, in hertz (cycles per second), of the display device in a particular mode. |
| AfxGetDisplayPixelsHeight | Returns the height, in pixels, of the current display device on the computer on which the calling thread is running. |
| AfxGetDisplayPixelsWidth | Returns the width, in pixels, of the current display device on the computer on which the calling thread is running. |

# Dialogs

| Name       | Description |
| ---------- | ----------- |
| [AfxChooseColorDialog](#AfxChooseColorDialog) | Displays the Windows choose color dialog. |
| [AfxControlRunDLL](#AfxControlRunDLL) | Launches control panel applications. |
| [AfxShowSysInfo](#AfxShowSysInfo) | Displays the Windows Information System dialog. |

# High DPI

| Name       | Description |
| ---------- | ----------- |
| AfxGetDpi | Retrieves the number of pixels per logical inch. |
| AfxGetDpiX | Retrieves the number of pixels per logical inch along the screen width. |
| AfxGetDpiY | Retrieves the number of pixels per logical inch along the screen height. |
| AfxGetMonitorHorizontalScaling | Returns the horizontal scaling of the monitor that the window is currently displayed on. |
| AfxGetMonitorVerticalScaling | Returns the vertical scaling of the monitor that the window is currently displayed on. |
| AfxGetMonitorLogicalHeight | Returns the logical height of the monitor that the window is currently displayed on. |
| AfxGetMonitorLogicalWidth | Returns the logical width of the monitor that the window is currently displayed on. |
| AfxIsDPIResolutionAtLeast | Determines if screen resolution meets minimum requirements in relative pixels. |
| AfxIsProcessDPIAware | Determines whether the current process is dots per inch (dpi) aware. |
| AfxIsResolutionAtLeast | Determines if screen resolution meets minimum requirements. |
| AfxLoadIconMetric | Loads a specified icon resource with a client-specified system metric. |
| AfxLogPixelsX | Retrieves the number of pixels per logical inch along the screen width. |
| AfxLogPixelsY | Retrieves the number of pixels per logical inch along the screen height. |
| AfxScaleRatioX | Retrieves the desktop horizontal scaling ratio. |
| AfxScaleRatioY | Retrieves the desktop vertical scaling ratio. |
| AfxScaleX | Scales an horizontal coordinate according the DPI (dots per pixel) being used by the operating system. |
| AfxScaleY | Scales an vertical coordinate according the DPI (dots per pixel) being used by the operating system. |
| AfxSetProcessDPIAware | Sets the current process as dots per inch (dpi) aware. |
| AfxUnscaleX | Unscales an horizontal coordinate according the DPI (dots per pixel) being used by the operating system. |
| AfxUnscaleY | Unscales a vertical coordinate according the DPI (dots per pixel) being used by the operating system. |
| AfxUseDpiScaling | Returns TRUE if the Windows Platform is NT; FALSE, otherwise. |

# Fonts

| Name       | Description |
| ---------- | ----------- |
| AfxCreateFont | Creates a logical font. |
| AfxGetFontHeight | Returns the logical height of a font given its point size. |
| AfxGetFontPointSize | Returns the point size of a font given its logical height. |
| AfxGetWindowFont | Retrieves the font with which the control is currently drawing its text. |
| AfxGetWindowsFontInfo | Retrieves information about the fonts used by Windows. |
| AfxGetWindowsFontPointSize | Retrieves the point size of the fonts used by Windows. |
| AfxModifyFontFaceName | Modifies the face name of the font of a window or control. |
| AfxModifyFontFaceName | Modifies the height of the font used by a window of control. |
| AfxModifyFontSettings | Modifies settings of the font used by a window of control. |
| AfxSetWindowFont | Sets the font that a control is to use when drawing text. |

# Clipboard

| Name       | Description |
| ---------- | ----------- |
| AfxClearClipboard | Clears the contents of the clipboard. |
| AfxGetClipboardData | Retrieves data from the clipboard in the specified format. |
| AfxGetClipboardText | Returns a text string from the clipboard. |
| AfxSetClipboardData | Places data on the clipboard in a specified clipboard format. |
| AfxSetClipboardText | Places a text string into the clipboard. |

# Bitmap

| Name       | Description |
| ---------- | ----------- |
| AfxCaptureDisplay | Captures the display and returns an handle to a bitmap. |
| AfxGetBitmapHeight | Retrieves the height of the specified bitmap. |
| AfxGetBitmapWidth | Retrieves the width of the specified bitmap. |

# Device Independent Bitmap (DIB)

| Name       | Description |
| ---------- | ----------- |
| AfxCreateDIBSection | Creates a DIB section. |
| AfxDibLoadImage | Loads a DIB in memory and returns a pointer to it. |
| AfxDibSaveImage | Saves a DIB to a file. |

# Metric conversions

| Name       | Description |
| ---------- | ----------- |
| AfxHiMetricToPixelsX | Converts from HiMetric to Pixels (horizontal resolution). |
| AfxHiMetricToPixelsY | Converts from HiMetric to Pixels (vertical resolution). |
| AfxPixelsToHiMetricX | Converts from Pixels to HiMetric (horizontal resolution). |
| AfxPixelsToHiMetricY | Converts from Pixels to HiMetric (vertical resolution). |
| AfxPixelsToPointsX | Converts pixels to points size (1/72 of an inch) (horizontal resolution). |
| AfxPixelsToPointsY | Converts pixels to points size (1/72 of an inch) (vertical resolution). |
| AfxPixelsToTwipsX | Converts pixels to twips (horizontal resolution). |
| AfxPixelsToTwipsY | Converts pixels to twips (vertical resolution). |
| AfxPointSizeToDip | Converts point size to DIP (device independent pixel). |
| AfxPointsToPixelsX | Converts a point size (1/72 of an inch) to pixels (horizontal resolution). |
| AfxPointsToPixelsY | Converts a point size (1/72 of an inch) to pixels (vertical resolution). |
| AfxTwipsPerPixelX | Returns the width of a pixel in twips (horizontal resolution). |
| AfxTwipsPerPixelY | Returns the width of a pixel in twips (vertical resolution). |
| AfxTwipsToPixelsX | Converts twips to pixels (horizontal resolution). |
| AfxTwipsToPixelsY | Converts twips to pixels (vertical resolution). |

# Mail and Internet

| Name       | Description |
| ---------- | ----------- |
| [AfxGetBrowserHandle](#AfxGetBrowserHandle) | Retrieves the handle of the top level window of the web browser. |
| [AfxGetDefaultBrowserName](#AfxGetDefaultBrowserName) | Retrieves the name of the default browser. |
| [AfxGetDefaultBrowserPath](#AfxGetDefaultBrowserPath) | Retrieves the path of the default browser. |
| [AfxGetDefaultMailClientName](#AfxGetDefaultMailClientName) | Retrieves the name of the default client mail application. |
| [AfxGetDefaultMailClientPath](#AfxGetDefaultMailClientPath) | Retrieves the path of the default mail client application. |
| [AfxGetInternetExplorerVersion](#AfxGetInternetExplorerVersion) | Returns the Internet Explorer version installed. |

# Miscellaneous procedures

| Name       | Description |
| ---------- | ----------- |
| [AfxCommand](#AfxCommand) | Returns command line parameters used to call the program. |
| [AfxEnviron](#AfxEnviron) | Retrieves the contents of the specified variable from the environment block of the calling process. |
| [AfxGetComputerName](#AfxGetComputerName) | Retrieves the NetBIOS name of the local computer. |
| [AfxGetMACAddress](#AfxGetMACAddress) | Retrieves the MAC address of a machine's Ethernet card. |
| [AfxGetUserName](#AfxGetUserName) | Retrieves the name of the user associated with the current thread. |
| [AfxGetWinErrMsg](#AfxGetWinErrMsg) | Retrieves the localized description of the specified Windows error code. |
| [AfxMsg](#AfxMsg) | Displays an application modal message box. |
| [AfxSetDlgMsgResult](#AfxSetDlgMsgResult) | Sets the return value of a message processed in the dialog box procedure. |
| [AfxSetEnviron](#AfxSetEnviron) | Sets the contents of the specified environment variable for the current process. |

# Versioning

| Name       | Description |
| ---------- | ----------- |
| [AfxComCtlVersion](#AfxComCtlVersion) | Returns the version of CommCtl32.dll. |
| [AfxIsPlatformNT](#AfxIsPlatformNT) | Returns TRUE if the Windows Platform is NT; FALSE, otherwise. |
| [AfxWindowsBitness](#AfxWindowsBitness) | Returns the bitness of the operating system (32 or 64 bit). |
| [AfxWindowsBuild](#AfxWindowsBuild) | Returns the Windows build number. |
| [AfxWindowsPlatform](#AfxWindowsPlatform) | Returns the Windows platform. |
| [AfxWindowsVersion](#AfxWindowsVersion) | Returns the Windows version. |

# <a name="AfxWindowsVersion"></a>AfxWindowsVersion

Returns the Windows version.

```
FUNCTION AfxWindowsVersion () AS LONG
```

#### Return value

Platform 1:
```
  400 Windows 95
  410 Windows 98
  490 Windows ME
```

Platform 2:

```
  400 Windows NT
  500 Windows 2000
  501 Windows XP
  502 Windows Server 2003
  600 Windows Vista and Windows Server 2008
  601 Windows 7
  602 Windows 8
  603 Windows 8.1
1000 Windows 10
```

**Note**: As Windows 95 and Windows NT return the same version number, we also need to call GetWindowsPlatform to differentiate them.

# <a name="AfxWindowsBuild"></a>AfxWindowsBuild

Returns the Windows build number.

```
FUNCTION AfxWindowsBuild () AS LONG
```

# <a name="AfxWindowsPlatform"></a>AfxWindowsPlatform

Returns the Windows platform.

```
FUNCTION AfxWindowsPlatform () AS LONG
```

#### Return value

| Value      | Description |
| ---------- | ----------- |
| 1 | Windows 95/98/ME |
| 2 | Windows NT/2000/XP/Server/Vista/Windows 7 |

# <a name="AfxWindowsBitness"></a>AfxWindowsBitness

Returns the Windows bitness (32 or 64 bit).

```
FUNCTION AfxWindowsBitness () AS LONG
```

# <a name="AfxIsPlatformNT"></a>AfxIsPlatformNT

Returns TRUE if the Windows Platform is NT; FALSE, otherwise.

```
FUNCTION AfxIsPlatformNT () AS BOOLEAN
```

# <a name="AfxComCtlVersion"></a>AfxComCtlVersion

Returns the version of CommCtl32.dll

```
FUNCTION AfxComCtlVersion () AS LONG
```

#### Return value

The version of CommCtl32.dll multiplied by 100, e.g. 582 for version 5.82.

# <a name="AfxMsg"></a>AfxMsg

Displays an application modal message box. Helper proceudre to display feedback and errors.

```
FUNCTION AfxMsg (BYVAL pwszText AS WSTRING PTR, BYREF wszCaption AS WSTRING = "Message", _
   BYVAL uType AS DWORD = 0) AS LONG
FUNCTION AfxMsg (BYREF cws AS CWSTR, BYREF wszCaption AS WSTRING = "Message", _
   BYVAL uType AS DWORD = 0) AS LONG
FUNCTION AfxMsg (BYREF cbs AS CBSTR, BYREF wszCaption AS WSTRING = "Message", _
   BYVAL uType AS DWORD = 0) AS LONG
FUNCTION AfxMsg (BYREF cv AS CVAR, BYREF wszCaption AS WSTRING = "Message", _
   BYVAL uType AS DWORD = 0) AS LONG
FUNCTION AfxMsg (BYVAL nValue AS DOUBLE, BYREF wszCaption AS WSTRING = "Message", _
   BYVAL uType AS DWORD = 0) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszText* | Pointer to a WSTRING. |
| *cws* | A CWSTR variable. |
| *cws* | A CBSTR variable. |
| *cv* | A CVAR variable. |
| *nValue* | A numeric variable. |
| *wszCaption* | Optional. The message box caption. Default title is "Message". |
| *uType* | Optional. For a list of available types, see the Microsoft documentation for the MessageBoxW function. The MB_APPLMODAL type is always added. |

#### Return value

The version of CommCtl32.dll multiplied by 100, e.g. 582 for version 5.82.

# <a name="AfxGetWinErrMsg"></a>AfxGetWinErrMsg

Retrieves the localized description of the specified Windows error code.

```
FUNCTION AfxGetWinErrMsg (BYVAL dwError AS DWORD) AS CWSTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *dwError* | The Windows error code. |

#### Return value

The localized description of the error code.

# <a name="AfxCommand"></a>AfxCommand

Returns command line parameters used to call the program.

```
FUNCTION AfxCommand (BYVAL nIndex AS LONG = -1) AS CWSTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *nIndex* | Zero-based index for a particular command-line argument. |

#### Return value

Returns the command-line arguments(s).

#### Remarks

**AfxCommand** returns command-line arguments passed to the program upon execution.

If index is less than zero (< 0), a space-separated list of all command-line arguments is returned, otherwise, a single argument is returned. A value of zero (0) returns the name of the executable; and values of one (1) and greater return each command-line argument.

If index is greater than the number of arguments passed to the program, a null string ("") is returned.

# <a name="AfxEnviron"></a>AfxEnviron

Retrieves the contents of the specified variable from the environment block of the calling process.

```
FUNCTION AfxEnviron (BYVAL pwszName AS LPCWSTR) AS CWSTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszName* | The name of the environment variable. |

**Include file**: AfxStr.inc

#### Usage example

```
DIM cws AS CWSTR = AfxEnviron("path")
```

# <a name="AfxSetEnviron"></a>AfxSetEnviron

Sets the contents of the specified environment variable for the current process.

```
FUNCTION AfxSetEnviron (BYVAL pwszName AS LPCWSTR, BYVAL pwszValue AS LPCWSTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszName* | The name of the environment variable. The operating system creates the environment variable if it does not exist and *pwszValue* is not NULL. |
| *pwszValue* | The name of the environment variable. The maximum size of a user-defined environment variable is 32,767 characters. |

**Include file**: AfxStr.inc

#### Return value

If the function succeeds, the return value is TRUE.<br>
If the function fails, the return value is FALSE.<br>
To get extended error information, call **GetLastError**.

#### Usage example

```
AfxSetEnviron("path", "c:")
```

# AfxSetEnviron (Overload)

Sets the contents of the specified environment variable for the current process.<br>
Unicode replacement for Free Basic's **SetEnviron** function.

```
FUNCTION AfxSetEnviron (BYVAL pwszName AS LPCWSTR, BYVAL pwszValue AS LPCWSTR) AS BOOLEAN
FUNCTION AfxSetEnviron (BYREF varexp AS WSTRING) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszName* | The name of the environment variable. The operating system creates the environment variable if it does not exist and *pwszValue* is not NULL. |
| *varexp* | Name and setting of an environment variable in the following (or equivalent) form: varname=varstring (*varname* being the name of the environment variable, and *varstring* being its text value to set).

**Include file**: AfxStr.inc

#### Return value

Returns 0 on success, or -1 on failure.

# <a name="AfxSetDlgMsgResult"></a>AfxSetDlgMsgResult

Sets the return value of a message processed in the dialog box procedure.

```
FUNCTION AfxSetDlgMsgResult (BYVAL hDlg AS HWND, BYVAL msg AS UINT, BYVAL result AS LONG) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hDlg* | A handle to a dialog box. |
| *msg* | The message type. |
| *result* | The return value. |

#### Return value

If the function succeeds, the return value is TRUE. If the function fails, the return value is FALSE.

# <a name="AfxGetComputerName"></a>AfxGetComputerName

Retrieves the NetBIOS name of the local computer. This name is established at system startup, when the system reads it from the registry.

```
FUNCTION AfxGetComputerName () AS CWSTR
```

#### Return value

The NetBIOS name of the local computer.

#### Remarks

The behavior of this function can be affected if the local computer is a node in a cluster. For more information, see **ResUtilGetEnvironmentWithNetName** and **UseNetworkName**.

# <a name="AfxGetUserName"></a>AfxGetUserName

Retrieves the name of the user associated with the current thread.

```
FUNCTION AfxGetUserName () AS CWSTR
```

#### Return value

The name of the current user associated with the current thread.

#### Remarks

If the current thread is impersonating another client, the **AfxGetUserName** function returns the user name of the client that the thread is impersonating.

# <a name="AfxGetMACAddress"></a>AfxGetMACAddress

Retrieves the MAC address of a machine's Ethernet card.

```
FUNCTION AfxGetMACAddress () AS STRING
```

#### Return value

The MAC address in the following format: MM-MM-MM-SS-SS-SS. The leftmost 6 digits, called a "prefix", is associated with the adapter manufacturer. The rightmost digits of a MAC address represent an identification number for the specific device.

#### Remarks

This function only supports one NIC card on your PC.

# <a name="AfxDoEvents"></a>AfxDoEvents

Processes pending Windows messages. Call this procedure if you are performing a tight FOR/NEXT or DO/LOOP and need to allow your application to be responsive to user input.

```
SUB AfxDoEvents (BYVAL hwnd AS HWND = NULL)
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Optional. Handle of the window or dialog. If NULL, the window handle to the active window attached to the calling thread's message queue is used. |

# <a name="AfxPumpMessages"></a>AfxPumpMessages

Processes pending Windows messages. Call this procedure if you are performing a tight FOR/NEXT or DO/LOOP and need to allow your application to be responsive to user input.

```
SUB AfxPumpMessages
```

# <a name="AfxForwardSizeMessage"></a>AfxForwardSizeMessage

Sends a WM_SIZE message to the specified window.

```
FUNCTION AfxForwardSizeMessage (BYVAL hwnd AS HWND, BYVAL nResizeType AS DWORD, _
   BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS LRESULT
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | A handle to a window. |
| *nResizeType* | Type of resizing requested. |
| *nWidth* | The new width of the client area. |
| *nHeight* | The new height of the client ara. |

| Resizing type  | Description |
| -------------- | ----------- |
| SIZE_MAXHIDE | Message is sent to all pop-up windows when some other window is maximized. |
| SIZE_MAXIMIZED | Maximize the window. |
| SIZE_MAXSHOW | Message is sent to all pop-up windows when some other window has been restored to its former size. |
| SIZE_MINIMIZED | Minimize the window. |
| SIZE_RESTORED | The window has been resized, but neither the SIZE_MINIMIZED nor SIZE_MAXIMIZED value applies. |

#### Remark

If an application processes this message, it should return zero.

# <a name="AfxChooseColorDialog"></a>AfxChooseColorDialog

Displays the Windows choose color dialog.

```
FUNCTION AfxChooseColorDialog (BYVAL hwnd AS HWND, BYVAL rgbDefaultColor AS COLORREF = 0, _
   BYVAL lpCustColors AS COLORREF PTR = NULL) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | A handle to the parent window or NULL. |
| *rgbDefaultColor* | The color initially selected when the dialog box is created. If the specified color value is not among the available colors, the system selects the nearest solid color available. If rgbResult is zero, the initially selected color is black. |
| *lpCustColors* | Out. A pointer to an array of 16 values that contain red, green, blue (RGB) values for the custom color boxes in the dialog box. If the user modifies these colors, the system updates the array with the new RGB values. To preserve new custom colors between calls to the **AfxChooseColorDialog** function, you should allocate static memory for the array. To create a COLORREF color value, use the BGR macro. |

#### Return value

The selected color, or -1 if the user has canceled the dialog.

# <a name="AfxControlRunDLL"></a>AfxControlRunDLL

Control_RunDLL is an undocumented procedure in the Shell32.dll which can be used to launch control panel applications. You’ve to pass the name of the control panel file (.cpl) and the tool represented by it will be launched. For launching some control panel applications, you’ve to provide a valid windows handle (hwnd parameter) and program instance (*hInst*) parameter).

```
FUNCTION AfxControlRunDLL (BYVAL hwnd AS HWND, BYVAL hInst AS HINSTANCE, _
   BYVAL cmd AS WSTRING PTR, BYVAL nCmdShow AS LONG) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | Handle to a window. This parameter can be NULL. |
| *hInst* | Instance handle. This parameter can be NULL. |
| *cmd* | The command and parameters. |
| *nCmdShow* | Controls how the window is to be shown, e.g. SW_SHOWNORMAL. |

| nCmdShow value  | Description |
| --------------- | ----------- |
| SW_FORCEMINIMIZE | Minimizes a window, even if the thread that owns the window is not responding. This flag should only be used when minimizing windows from a different thread. |
| SW_HIDE | Hides the window and activates another window. |
| SW_MAXIMIZE | Maximizes the specified window. |
| SW_MINIMIZE | Minimizes the specified window and activates the next top-level window in the Z order. |
| SW_RESTORE | Activates and displays the window. If the window is minimized or maximized, the system restores it to its original size and position. An application should specify this flag when restoring a minimized window. |
| SW_SHOW | Activates the window and displays it in its current size and position. |
| SW_SHOWDEFAULT | Sets the show state based on the SW_ value specified in the STARTUPINFO structure passed to the **CreateProcess** function by the program that started the application. |
| SW_SHOWMAXIMIZED | Activates the window and displays it as a maximized window. |
| SW_SHOWMINIMIZED | Activates the window and displays it as a minimized window. |
| SW_SHOWMINNOACTIVE | Displays the window as a minimized window. This value is similar to SW_SHOWMINIMIZED, except the window is not activated. |
| SW_SHOWNA | Displays the window in its current size and position. This value is similar to SW_SHOW, except that the window is not activated. |
| SW_SHOWNOACTIVATE | Displays a window in its most recent size and position. This value is similar to SW_SHOWNORMAL, except that the window is not activated. |
| SW_SHOWNORMAL | Activates and displays a window. If the window is minimized or maximized, the system restores it to its original size and position. An application should specify this flag when displaying the window for the first time. |

####Usage examples

```
AfxControlRunDLL(0, 0, "", SW_SHOWNORMAL)   ' Opens the control panel
AfxControlRunDLL(0, 0, "appwiz.cpl", SW_SHOWNORMAL)   ' Opens the applications wizard
```

# <a name="AfxShowSysInfo"></a>AfxShowSysInfo

Displays the Windows Information System dialog.

```
FUNCTION AfxShowSysInfo (BYVAL hwnd AS HWND) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | A handle to the parent window or NULL. |

#### Return value

If the function succeeds, the return value is TRUE. If the function fails, the return value is FALSE.

# <a name="AfxGetBrowserHandle"></a>AfxGetBrowserHandle

Retrieves the handle of the top level window of the web browser.

```
FUNCTION AfxGetBrowserHandle (BYVAL pwszClassName AS WSTRING PTR) AS HWND
FUNCTION AfxGetInternetExplorerHandle () AS HWND
FUNCTION AfxGetFireFoxHandle () AS HWND
FUNCTION AfxGetGoogleChromeHandle () AS HWND
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszClassName* | Class name of the browser. |

#### Return value

The handle of the top level window of the browser. If there is not any instance of the browser running, it will return NULL.

#### Examples

```
DIM hwndBrowser AS HWND = AfxGetBrowserHandle("IEFrame")              ' // Internet Explorer
DIM hwndBrowser AS HWND = AfxGetBrowserHandle("MozillaWindowClass")   ' // Firefox
DIM hwndBrowser AS HWND = AfxGetBrowserHandle("Chrome_WidgetWin_1")   ' // Chrome
```

#### Remarks

**AfxGetInternetExplorerHandle**, **AfxGetFireFoxHandle** and **AfxGetGoogleChromeHandle** are wrappers functions that call AfxGetBrowserHandle passing the appropriate class name ("IEFrame", "MozillaWindowClass" and "Chrome_WidgetWin_1").

# <a name="AfxGetDefaultBrowserName"></a>AfxGetDefaultBrowserName

Retrieves the name of the default browser.

```
FUNCTION AfxGetDefaultBrowserName () AS CWSTR
```

#### Return value

The retrieved name or an empty string.

# <a name="AfxGetDefaultBrowserPath"></a>AfxGetDefaultBrowserPath

Retrieves the path of the default browser.

```
FUNCTION AfxGetDefaultBrowserPath () AS CWSTR
```

#### Return value

The retrieved path or an empty string.

# <a name="AfxGetDefaultMailClientName"></a>AfxGetDefaultMailClientName

Retrieves the name of the default client mail application.

```
FUNCTION AfxGetDefaultMailClientName () AS CWSTR
```

#### Return value

The retrieved name or an empty string.

# <a name="AfxGetDefaultMailClientPath"></a>AfxGetDefaultMailClientPath

Retrieves the àth of the default client mail application.

```
FUNCTION AfxGetDefaultMailClientPath () AS CWSTR
```

#### Return value

The retrieved path or an empty string.

# <a name="AfxGetInternetExplorerVersion"></a>AfxGetInternetExplorerVersion

Returns the Internet Explorer version installed.

```
FUNCTION AfxGetInternetExplorerVersion () AS SINGLE
```

#### Return value

The Internet Explorer version (major.minor).
