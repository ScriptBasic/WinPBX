# Window Procedures

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
| AfxDoEvents | Processes pending Windows messages. |
| AfxForwardSizeMessage | Sends a WM_SIZE message to the specified window. |
| AfxPumpMessages | Processes pending Windows messages. |

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
| AfxChooseColorDialog | Displays the Windows choose color dialog. |
| AfxControlRunDLL | Launches control panel applications. |
| AfxShowSysInfo | Displays the Windows Information System dialog. |

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
| AfxGetBrowserHandle | Retrieves the handle of the top level window of the web browser. |
| AfxGetDefaultBrowserName | Retrieves the name of the default browser. |
| AfxGetDefaultBrowserPath | Retrieves the path of the default browser. |
| AfxGetDefaultMailClientName | Retrieves the name of the default client mail application. |
| AfxGetDefaultMailClientPath | Retrieves the path of the default mail client application. |
| AfxGetInternetExplorerVersion | Returns the Internet Explorer version installed. |

# Miscellaous procedures

| Name       | Description |
| ---------- | ----------- |
| AfxCommand | Returns command line parameters used to call the program. |
| AfxEnviron | etrieves the contents of the specified variable from the environment block of the calling process. |
| AfxGetComputerName | Retrieves the NetBIOS name of the local computer. |
| AfxGetMACAddress | Retrieves the MAC address of a machine's Ethernet card. |
| AfxGetUserName | Retrieves the name of the user associated with the current thread. |
| AfxGetWinErrMsg | Retrieves the localized description of the specified Windows error code. |
| AfxMsg | Displays an application modal message box. |
| AfxSetDlgMsgResult | Sets the return value of a message processed in the dialog box procedure. |
| AfxSetEnviron | Sets the contents of the specified environment variable for the current process. |

# Versioning

| Name       | Description |
| ---------- | ----------- |
| AfxComCtlVersion | Returns the version of CommCtl32.dll. |
| AfxIsPlatformNT | Returns TRUE if the Windows Platform is NT; FALSE, otherwise. |
| AfxWindowsBuild | Returns the Windows build number. |
| AfxWindowsPlatform | Returns the Windows platform. |
| AfxWindowsVersion | Returns the Windows version. |

#### Include file

AfxWin.inc
