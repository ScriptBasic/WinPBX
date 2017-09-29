' ########################################################################################
' Microsoft Windows
' File: AfxWin.inc
' Contents: Windows wrapper functions.
' Copyright (c) 2011 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AFXWIN_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "RegExp.inc"
#INCLUDE ONCE "httprequest.inc"
#INCLUDE ONCE "psapi.inc"
' // Needed if user has defined %WIN32_LEAN_AND_MEAN
#INCLUDE ONCE "winspool.inc"
#INCLUDE ONCE "shellapi.inc"

' ========================================================================================
' Adds a new style to the specified window.
' - hwnd  = Window handle
' - dwStyle = Style to add
' Return value:
'   The previous window style
' ========================================================================================
FUNCTION AfxAddWindowStyle (BYVAL hwnd AS DWORD, BYVAL dwStyle AS DWORD) AS DWORD
   LOCAL dwOldStyle AS DWORD
   dwOldStyle = GetWindowLong(hwnd, %GWL_STYLE)
   SetWindowLong(hwnd, %GWL_STYLE, dwOldStyle OR dwStyle)
   FUNCTION = dwOldStyle
END FUNCTION
' ========================================================================================

' ========================================================================================
' Destroys the specified window.
' ========================================================================================
FUNCTION AfxDestroyWindow (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = DestroyWindow(hwnd)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Disable a window so that it no longer receives any messages or accepts user interaction.
' ========================================================================================
FUNCTION AfxDisableWindow (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = EnableWindow(hwnd, %FALSE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Disables redrawing in the specified window.
' ========================================================================================
FUNCTION AfxDisableWindowRedraw (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_SETREDRAW, %FALSE, 0)
END FUNCTION
' ========================================================================================

' ########################################################################################
' BEGIN Enable/disable application windows
' Code borrowed from the one written by Dominic Mitchell for Phoenix.
' ########################################################################################

' // Structure used to track the enabled state of an application
' // Size = 12 bytes
TYPE AFX_TASKMODAL DWORD
   hWndOwner AS DWORD   ' // Handle of owner of modal window
   fEnable   AS LONG    ' // TRUE = enable, FALSE = disable
   lRefCount AS LONG    ' // Reference count
END TYPE

' ========================================================================================
' Disables/enables all windows in an application when a modal window is created/destroyed.
' This function must be called before the modal is created with the fEnable parameter set
' to FALSE and after the modal window is destroyed with fEnable parameter set to TRUE.
' ========================================================================================
SUB AfxEnableAppWindows ( _
   BYVAL hwndOwner AS DWORD, _   ' // Handle of owner of modal window
   BYVAL fEnable   AS LONG _     ' // TRUE = enable, FALSE = disable
   )

   STATIC ttm AS AFX_TASKMODAL
   ttm.hwndOwner = hwndOwner
   ttm.fEnable   = fEnable

   IF ISTRUE fEnable THEN DECR ttm.lRefCount
   IF ISFALSE ttm.lRefCount THEN
      EnumWindows CODEPTR(AfxAppWindowsEnumProc), VARPTR(ttm)
   END IF
   IF ISFALSE fEnable THEN INCR ttm.lRefCount

END SUB

' ========================================================================================
' Disables/enables all windows in an application when a modal window is created/destroyed.
' ========================================================================================
FUNCTION AfxAppWindowsEnumProc ( _
   BYVAL hwnd   AS DWORD, _   ' // Handle of top-level window
   BYVAL lParam AS LONG _     ' // Address of TASKMODAL structure
   ) AS LONG

   LOCAL hwndOwner   AS DWORD
   LOCAL pttm        AS AFX_TASKMODAL PTR
   LOCAL dwProcessId AS DWORD

   pttm = lParam
   ' // If this window is not the owner of the modal window
   GetWindowThreadProcessId hwnd, BYVAL VARPTR(dwProcessId)
   IF dwProcessId = GetCurrentProcessId() THEN
      IF hwnd <> @pttm.hwndOwner THEN EnableWindow hwnd, @pttm.fEnable
      IF ISFALSE @pttm.fEnable THEN
         SendMessage hwnd, %WM_NCACTIVATE, %FALSE, 0
      END IF
   END IF
   FUNCTION = %TRUE

END FUNCTION

' ########################################################################################
' END Enable/disable application windows
' ########################################################################################

' ========================================================================================
' Enable a window so that it can receive messages when the user interacts with it via
' the mouse or keyboard.
' ========================================================================================
FUNCTION AfxEnableWindow (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = EnableWindow(hwnd, %TRUE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Enables redrawing in the specified window.
' ========================================================================================
FUNCTION AfxEnableWindowRedraw (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_SETREDRAW, %TRUE, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Replacement for the SetForegroundWindow API function.
' ========================================================================================
SUB AfxForceSetForegroundWindow (BYVAL hwnd AS DWORD)
   LOCAL hwndForeground, dwThreadId, dwProcessId, dwCurThreadId AS DWORD
   hwndForeground = GetForegroundWindow
   dwThreadId = GetWindowThreadProcessId(hwndForeground, dwProcessId)
   dwCurThreadId = GetCurrentThreadId
   AttachThreadInput(dwCurThreadId, dwThreadId, %TRUE)
   SetForegroundWindow(hwnd)
   BringWindowToTop(hwnd)
   SetFocus(hwnd)
   AttachThreadInput(dwCurThreadId, dwThreadId, %FALSE)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the window's top-level parent or owner window.
' ========================================================================================
FUNCTION AfxGetTopLevelWindow (BYVAL hwnd AS DWORD) AS DWORD
   LOCAL hWndParent AS DWORD
   LOCAL hWndTmp AS DWORD
   IF IsWindow(hwnd) = 0 THEN EXIT FUNCTION
   hWndTmp = hwnd
   DO
      hWndParent = hWndTmp
      hWndTmp = IIF&(GetWindowLong(hwndParent, %GWL_STYLE) AND %WS_CHILD, GetParent(hwndParent), GetWindow(hWndParent, %GW_OWNER))
      IF hWndTmp = %NULL THEN EXIT DO
   LOOP
   FUNCTION = hWndParent
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the window's top-level parent window.
' ========================================================================================
FUNCTION AfxGetTopLevelParent (BYVAL hwnd AS DWORD) AS DWORD
   LOCAL hWndParent AS DWORD
   LOCAL hWndTmp AS DWORD
   IF IsWindow(hwnd) = 0 THEN EXIT FUNCTION
   hWndParent = hwnd
   DO
      hWndTmp = GetParent(hWndParent)
      IF hWndTmp = %NULL THEN EXIT DO
      hWndParent = hWndTmp
   LOOP
   FUNCTION = hWndParent
END FUNCTION
' ========================================================================================

' ========================================================================================
' Finds the handle of the top-level window or MDI child window that is the ancestor of the
' specified window handle. The reference handle is the handle of any control on the form.
' Code borrowed from a function written by Dominic Mitchell for Phoenix.
' ========================================================================================
FUNCTION AfxGetFormHandle (BYVAL hwnd AS DWORD) AS DWORD
   WHILE (GetWindowLong(hwnd, %GWL_STYLE) AND %WS_CHILD)
      IF (GetWindowLong(hwnd, %GWL_EXSTYLE) AND %WS_EX_MDICHILD) THEN EXIT LOOP
      hwnd = GetParent(hwnd)
   WEND
   FUNCTION = hwnd
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the handle of the control with the specified identifier. The reference handle
' can be the handle of the form or the handle of any other control on the form.
' Returns the handle of the control or NULL.
' Code borrowed from a function written by Dominic Mitchell for Phoenix.
' ========================================================================================
FUNCTION AfxGetControlHandle ( _
   BYVAL hwnd AS DWORD, _                   ' // Reference handle
   BYVAL wCtrlID AS WORD _                  ' // Control identifier
   ) AS DWORD                               ' // Handle of the control

   LOCAL hwndChild AS DWORD
   hwnd = AfxGetFormHandle(hwnd)
   hwndChild = wCtrlID
   EnumChildWindows hwnd, CODEPTR(AfxControlHandle_ChildEnumProc), VARPTR(hwndChild)
   IF hwndChild = wCtrlID THEN
      FUNCTION = %NULL
   ELSE
      FUNCTION = hwndChild
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Enumerates child controls on the specified window.
' Callback function for Window_GetControlHandle.
' ========================================================================================
FUNCTION AfxControlHandle_ChildEnumProc ( _
   BYVAL hwnd   AS DWORD, _                ' // Handle of child window
   BYVAL lParam AS LONG _                  ' // Address of variable with child window handle
   ) AS LONG                               ' // TRUE or FALSE

   LOCAL pdwItem AS DWORD PTR
   pdwItem = lParam
   IF GetDlgCtrlID(hwnd) = LO(WORD, @pdwItem) THEN
      @pdwItem = hwnd
      FUNCTION = %FALSE
      EXIT FUNCTION
   END IF
   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Examines the Z order of the child windows associated with the specified parent window
' and retrieves a handle to the child window at the top of the Z order.
' ========================================================================================
FUNCTION AfxGetFirstChild (BYVAL hwnd AS DWORD) AS DWORD
   FUNCTION = GetTopWindow(hwnd)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a handle that identifies the window of the same type that is highest in the Z order.
' If the specified window is a topmost window, the handle identifies a topmost window. If
' the specified window is a top-level window, the handle identifies a top-level window. If
' the specified window is a child window, the handle identifies a sibling window.
' ========================================================================================
FUNCTION AfxGetFirstSibling (BYVAL hwnd AS DWORD) AS DWORD
   FUNCTION = GetWindow(hwnd, %GW_HWNDFIRST)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a window handle given it's process identifier
' ========================================================================================
FUNCTION AfxGetHwndFromPID (BYVAL PID AS DWORD) AS DWORD

   LOCAL hwnd AS DWORD
   LOCAL dwPID AS DWORD
   LOCAL dwThreadID AS DWORD

   ' // Get the first window handle
   hwnd = FindWindow(BYVAL %NULL, BYVAL %NULL)
   ' // Enumerate all the windows
   DO WHILE hwnd <> 0
      ' // If the parent window is 0, it's a top level window
      IF GetParent(hwnd) = 0 THEN
         ' // Get it's process id
         dwThreadID = GetWindowThreadProcessId(hwnd, dwPID)
         IF dwPID = PID THEN
            ' // We have found it
            FUNCTION = hwnd
            EXIT DO
         END IF
      END IF
      ' // Get the next window handle
      hwnd = GetWindow(hwnd, %GW_HWNDNEXT)
   LOOP

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a handle that identifies the window of the same type that is lowest in the Z order.
' If the specified window is a topmost window, the handle identifies a topmost window. If
' the specified window is a top-level window, the handle identifies a top-level window. If
' the specified window is a child window, the handle identifies a sibling window.
' ========================================================================================
FUNCTION AfxGetLastSibling (BYVAL hwnd AS DWORD) AS DWORD
   FUNCTION = GetWindow(hwnd, %GW_HWNDLAST)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a handle that identifies the window below the specified window in the Z order.
' If the specified window is a topmost window, the handle identifies a topmost window. If
' the specified window is a top-level window, the handle identifies a top-level window. If
' the specified window is a child window, the handle identifies a sibling window.
' ========================================================================================
FUNCTION AfxGetNextSibling (BYVAL hwnd AS DWORD) AS DWORD
   FUNCTION = GetWindow(hwnd, %GW_HWNDNEXT)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a handle that identifies the window above the specified window in the Z order.
' If the specified window is a topmost window, the handle identifies a topmost window. If
' the specified window is a top-level window, the handle identifies a top-level window. If
' the specified window is a child window, the handle identifies a sibling window.
' ========================================================================================
FUNCTION AfxGetPrevSibling (BYVAL hwnd AS DWORD) AS DWORD
   FUNCTION = GetWindow(hwnd, %GW_HWNDPREV)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the handle of the enabled and visible window at the top of the z-order in an
' application.
' Return value: Handle of window at top of z-order or NULL.
' ========================================================================================
FUNCTION AfxGetTopEnabledWindow () AS DWORD
   LOCAL hWndTop AS DWORD
   EnumWindows CODEPTR(EnabledWindowEnumProc), VARPTR(hWndTop)
   FUNCTION = hWndTop
END FUNCTION
' ========================================================================================

' ========================================================================================
' Callback enumeration procedure for finding the window at the top of the z-order.
' ========================================================================================
FUNCTION EnabledWindowEnumProc ( _
   BYVAL hWnd AS DWORD,   _   ' // Handle of top-level window
   BYVAL lParam AS LONG _     ' // Address of variable for window handle
   ) AS LONG

   LOCAL wszClassName AS WSTRINGZ * %MAX_PATH
   LOCAL phWndTop     AS DWORD PTR
   LOCAL dwProcessId  AS DWORD

   IF ISTRUE IsWindowEnabled(hWnd) THEN
      IF ISTRUE IsWindowVisible(hWnd) THEN
        GetClassNameW hWnd, wszClassName, %MAX_PATH
        IF wszClassName <> "tooltips_class32" THEN
          GetWindowThreadProcessId hWnd, BYVAL VARPTR(dwProcessId)
          IF dwProcessId = GetCurrentProcessId() THEN
            phWndTop  = lParam
            @phWndTop = hWnd
            FUNCTION = %FALSE
            EXIT FUNCTION
          END IF
        END IF
      END IF
   END IF

   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the class name of the specified window
' ========================================================================================
FUNCTION AfxGetWindowClassName (BYVAL hwnd AS DWORD) AS WSTRING
   LOCAL wszClassName AS WSTRINGZ * 260
   GetClassNameW hwnd, wszClassName, SIZEOF(wszClassName)
   FUNCTION = wszClassName
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the width and height, in pixels, of the client area of a window.
' ========================================================================================
SUB AfxGetWindowClientSize (BYVAL hwnd AS DWORD, BYREF nWidth AS LONG, BYREF nHeight AS LONG)
   LOCAL rc AS RECT
   GetClientRect hwnd, rc
   nWidth = rc.Right - rc.Left
   nHeight = rc.nBottom - rc.nTop
END SUB
' ========================================================================================

' ========================================================================================
' Gets the height in pixels of the client area of a window.
' ========================================================================================
FUNCTION AfxGetWindowClientHeight (BYVAL hwnd AS DWORD) AS LONG
   LOCAL rc AS RECT
   GetClientRect hwnd, rc
   FUNCTION = rc.Bottom - rc.Top
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the width in pixels of a window.
' ========================================================================================
FUNCTION AfxGetWindowClientWidth (BYVAL hwnd AS DWORD) AS LONG
   LOCAL rc AS RECT
   GetClientRect hwnd, rc
   FUNCTION = rc.Right - rc.Left
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the extended window styles.
' ========================================================================================
FUNCTION AfxGetWindowExStyle (BYVAL hwnd AS DWORD) AS DWORD
   FUNCTION = GetWindowLong(hwnd, %GWL_EXSTYLE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the font with which the window is currently drawing its text.
' ========================================================================================
FUNCTION AfxGetWindowFont (BYVAL hwnd AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwnd, %WM_GETFONT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the width and height in pixels of a window.
' ========================================================================================
SUB AfxGetWindowSize (BYVAL hwnd AS DWORD, BYREF nWidth AS LONG, BYREF nHeight AS LONG)
   LOCAL rc AS RECT
   GetWindowRect hwnd, rc
   nWidth  = rc.Right - rc.Left
   nHeight = rc.Bottom - rc.Top
END SUB
' ========================================================================================

' ========================================================================================
' Gets the height in pixels of a window.
' ========================================================================================
FUNCTION AfxGetWindowHeight (BYVAL hwnd AS DWORD) AS LONG
   LOCAL rc AS RECT
   GetWindowRect hwnd, rc
   FUNCTION = rc.Bottom - rc.Top
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the width in pixels of a window.
' ========================================================================================
FUNCTION AfxGetWindowWidth (BYVAL hwnd AS DWORD) AS LONG
   LOCAL rc AS RECT
   GetWindowRect hwnd, rc
   FUNCTION = rc.Right - rc.Left
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the identifier of the specified control.
' ========================================================================================
FUNCTION AfxGetWindowID (BYVAL hwnd AS DWORD) AS DWORD
   FUNCTION = GetDlgCtrlID(hwnd)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a handle to the application instance.
' ========================================================================================
FUNCTION AfxGetWindowInstance (BYVAL hwnd AS DWORD) AS DWORD
   FUNCTION = GetWindowLong(hwnd, %GWLP_HINSTANCE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the location of the top left corner of the window, in pixels.
' The location is relative to the upper-left corner of the client area in the parent window.
' ========================================================================================
SUB AfxGetWindowLocation (BYVAL hwnd AS DWORD, BYREF nLeft AS LONG, BYREF nTop AS LONG)
   LOCAL rc AS RECT
   ' // Get the dimensions of the window
   GetWindowRect(hwnd, rc)
   ' // Convert the coordinates to be relative to the parent
#IF %DEF(%USEPBDECL)
   MapWindowPoints %HWND_DESKTOP, GetParent(hwnd), BYVAL VARPTR(rc), 2
#ELSE
   MapWindowPoints %HWND_DESKTOP, GetParent(hwnd), rc, 2
#ENDIF
   ' // Return the left and top values
   nLeft = rc.Left
   nTop = rc.Top
END SUB
' ========================================================================================

' ========================================================================================
' Gets the width and height, in pixels, of the desktop.
' ========================================================================================
SUB AfxGetDesktopClientSize (BYREF nWidth AS LONG, BYREF nHeight AS LONG)
   LOCAL rc AS RECT
   GetClientRect GetDesktopWindow, rc
   nWidth = rc.Right - rc.Left
   nHeight = rc.nBottom - rc.nTop
END SUB
' ========================================================================================

' ========================================================================================
' Gets the height in pixels of the desktop.
' ========================================================================================
FUNCTION AfxGetDesktopClientHeight () AS LONG
   LOCAL rc AS RECT
   GetClientRect GetDesktopWindow, rc
   FUNCTION = rc.Bottom - rc.Top
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the width in pixels of the desktop.
' ========================================================================================
FUNCTION AfxGetDesktopClientWidth () AS LONG
   LOCAL rc AS RECT
   GetClientRect GetDesktopWindow, rc
   FUNCTION = rc.Right - rc.Left
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the width and height in pixels of the desktop.
' ========================================================================================
SUB AfxGetDesktopSize (BYREF nWidth AS LONG, BYREF nHeight AS LONG)
   LOCAL rc AS RECT
   GetWindowRect GetDesktopWindow, rc
   nWidth  = rc.Right - rc.Left
   nHeight = rc.Bottom - rc.Top
END SUB
' ========================================================================================

' ========================================================================================
' Gets the height in pixels of the desktop.
' ========================================================================================
FUNCTION AfxGetDesktopHeight () AS LONG
   LOCAL rc AS RECT
   GetWindowRect GetDesktopWindow, rc
   FUNCTION = rc.Bottom - rc.Top
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the width in pixels of the desktop.
' ========================================================================================
FUNCTION AfxGetDesktopWidth () AS LONG
   LOCAL rc AS RECT
   GetWindowRect GetDesktopWindow, rc
   FUNCTION = rc.Right - rc.Left
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the location of the top, left corner of the desktop, in pixels.
' ========================================================================================
SUB AfxGetDesktopLocation (BYREF x AS LONG, BYREF y AS LONG)
   LOCAL rc AS RECT
   GetWindowRect GetDesktopWindow, rc
   x = rc.Top
   y = rc.Left
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the handle of the owner window, if any, of the specified window.
' ========================================================================================
FUNCTION AfxGetWindowOwner (BYVAL hwnd AS DWORD) AS DWORD
   FUNCTION = GetWindow(hwnd, %GW_OWNER)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the window styles.
' ========================================================================================
FUNCTION AfxGetWindowStyle (BYVAL hwnd AS DWORD) AS DWORD
   FUNCTION = GetWindowLong(hwnd, %GWL_STYLE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the text of a window.
' Note: GetWindowText cannot retrieve the text of a control in another application.
' ========================================================================================
FUNCTION AfxGetWindowText (BYVAL hwnd AS LONG) AS WSTRING
   LOCAL nLen   AS LONG
   LOCAL wbuffer AS WSTRING
   nLen = SendMessageW(hwnd, %WM_GETTEXTLENGTH, 0, 0)
   wbuffer = SPACE$(nLen + 1)
   nLen = SendMessageW(hwnd, %WM_GETTEXT, nLen + 1, BYVAL STRPTR(wbuffer))
   FUNCTION = LEFT$(wbuffer, nLen)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the length of the text of a control.
' ========================================================================================
FUNCTION AfxGetWindowTextLength (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_GETTEXTLENGTH, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether a window is maximized.
' ========================================================================================
FUNCTION AfxIsMaximized (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = IsZoomed(hwnd)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether a window is minimized.
' ========================================================================================
FUNCTION AfxIsMinimized (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = IsIconic(hwnd)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Multiplies pixels by the horizontal DPI scaling ratio.
' ========================================================================================
FUNCTION AfxPixelsToDPIX (BYVAL nPixels AS LONG) AS LONG
   LOCAL hDC AS DWORD
   hDC = GetDC(%NULL)
   FUNCTION = CEIL(nPixels * (GetDeviceCaps(hDC, %LOGPIXELSX) / 96))
   ReleaseDC %NULL, hDC
END FUNCTION
' ========================================================================================

' ========================================================================================
' Multiplies pixels by the vertical DPI scaling ratio.
' ========================================================================================
FUNCTION AfxPixelsToDPIY (BYVAL nPixels AS LONG) AS LONG
   LOCAL hDC AS DWORD
   hDC = GetDC(%NULL)
   FUNCTION = CEIL(nPixels * (GetDeviceCaps(hDC, %LOGPIXELSY) / 96))
   ReleaseDC %NULL, hDC
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether the current process is dots per inch (dpi) aware such that it adjusts
' the sizes of UI elements to compensate for the dpi setting.
' ========================================================================================
FUNCTION AfxIsProcessDPIAware () AS LONG
   LOCAL bRes AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD
   hLib = LoadLibrary("user32.dll")
   IF hLib = 0 THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, "IsProcessDPIAware")
   IF pProc THEN CALL DWORD pProc USING AfxIsProcessDPIAware() TO bRes
   FreeLibrary hLib
   FUNCTION = bRes
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether a window is restored, i.e. not minimized and not maximized.
' ========================================================================================
FUNCTION AfxIsRestored (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = ((GetWindowLong(hwnd, %GWL_STYLE) AND (%WS_MINIMIZE OR %WS_MAXIMIZE)) = 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Destroys the specified window.
' ========================================================================================
FUNCTION AfxKillWindow (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = DestroyWindow(hwnd)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Maps a set of points from a coordinate space relative to one window to a coordinate
' space relative to another window.
' ========================================================================================
FUNCTION AfxMapWindowRect(BYVAL hwndFrom AS DWORD, BYVAL hwndTo AS DWORD, BYREF lprc AS RECT) AS LONG
#IF %DEF(%USEPBDECL)
   FUNCTION = MapWindowPoints(hwndFrom, hwndTo, BYVAL VARPTR(lprc), 2)
#ELSE
   FUNCTION = MapWindowPoints(hwndFrom, hwndTo, lprc, 2)
#ENDIF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Redraws the specified window.
' Do not use from within a WM_PAINT message.
' ========================================================================================
SUB AfxRedrawWindow (BYVAL hwnd AS DWORD)
   InvalidateRect hwnd, BYVAL %NULL, %TRUE
   UpdateWindow hwnd
END SUB
' ========================================================================================

' ========================================================================================
' Removes an style from the specified window.
' - hwnd  = Window handle
' - dwStyle = Style to remove
' Return value:
'   The previous window style
' ========================================================================================
FUNCTION AfxRemoveWindowStyle (BYVAL hwnd AS DWORD, BYVAL dwStyle AS DWORD) AS DWORD
   LOCAL dwOldStyle AS DWORD
   dwOldStyle = GetWindowLong(hwnd, %GWL_STYLE)
   SetWindowLong(hwnd, %GWL_STYLE, dwOldStyle AND (NOT dwStyle))
   FUNCTION = dwOldStyle
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the return value of a message processed in the dialog box procedure.
' ========================================================================================
FUNCTION AfxSetDlgMsgResult(BYVAL hwnd AS DWORD, BYVAL msg AS DWORD, BYVAL result AS LONG) AS LONG
   LOCAL bResult AS LONG
   IF msg = %WM_CTLCOLORMSGBOX      OR _
      msg = %WM_CTLCOLOREDIT        OR _
      msg = %WM_CTLCOLORLISTBOX     OR _
      msg = %WM_CTLCOLORBTN         OR _
      msg = %WM_CTLCOLORDLG         OR _
      msg = %WM_CTLCOLORSCROLLBAR   OR _
      msg = %WM_CTLCOLORSTATIC      OR _
      msg = %WM_COMPAREITEM         OR _
      msg = %WM_VKEYTOITEM          OR _
      msg = %WM_CHARTOITEM          OR _
      msg = %WM_QUERYDRAGICON       OR _
      msg = %WM_INITDIALOG          THEN
      bResult = IIF&(SetWindowLong(hwnd, %DWLP_MSGRESULT, result), %TRUE, %FALSE)
   END IF
   FUNCTION = bResult
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the current process as dots per inch (dpi) aware.
' Note SetProcessDPIAware is subject to a possible race condition if a DLL caches dpi
' settings during initialization. For this reason, it is recommended that dpi-aware be set
' through the application (.exe) manifest rather than by calling SetProcessDPIAware.
' ========================================================================================
FUNCTION AfxSetProcessDPIAware () AS LONG
   LOCAL bRes AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD
   hLib = LoadLibrary("user32.dll")
   IF hLib = 0 THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, "SetProcessDPIAware")
   IF pProc THEN CALL DWORD pProc USING AfxSetProcessDPIAware() TO bRes
   FreeLibrary hLib
   FUNCTION = bRes
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the text of a button using UTF8 encoded strings.
' Note: The target window must be an unicode window.
' ========================================================================================
FUNCTION AfxSetUtf8WindowText (BYVAL hwnd AS DWORD, BYVAL strUtf8Text AS STRING) AS LONG
   LOCAL bstrText AS WSTRING
   bstrText = UTF8TOCHR$(strUtf8Text)
   FUNCTION = SendMessageW(hwnd, %WM_SETTEXT, 0, STRPTR(bstrText))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Associates a new small icon with a window. The system displays the small icon in the
' window caption.
' Parameters:
' - hwnd  = Window handle
' - hIcon = Handle to the new small icon.
'   If this parameter is NULL, the icon indicated is removed.
' ========================================================================================
FUNCTION AfxSetWindowBigIcon (BYVAL hwnd AS DWORD, BYVAL hIcon AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwnd, %WM_SETICON, %ICON_BIG, hIcon)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Associates a new small icon with a window. The system displays the small icon in the
' window caption.
' Parameters:
' - hwnd  = Window handle
' - hIcon = Handle to the new small icon.
'   If this parameter is NULL, the icon indicated is removed.
' ========================================================================================
FUNCTION AfxSetWindowSmallIcon (BYVAL hwnd AS DWORD, BYVAL hIcon AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwnd, %WM_SETICON, %ICON_SMALL, hIcon)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Adjust the bounding rectangle of a window based on the desired size of the client area.
' ========================================================================================
SUB AfxSetWindowClientSize (BYVAL hwnd AS DWORD, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG)

   LOCAL rc AS RECT
   LOCAL rcTemp AS RECT
   LOCAL hMenu AS DWORD
   LOCAL dwStyle AS DWORD
   LOCAL cx AS LONG
   LOCAL cy AS LONG

   ' // Convert the client rectangle to a window rectangle.
   ' // The AdjustWindowRectEx function cannot take menu wrapping into account
   ' // because it doesn't know which menu we are using.
   SetRect rc, 0, 0, nWidth, nHeight
   hMenu   = GetMenu(hwnd)
   dwStyle = GetWindowLong(hwnd, %GWL_STYLE)
   AdjustWindowRectEx rc, dwStyle, (hMenu <> %NULL), GetWindowLong(hwnd, %GWL_EXSTYLE)

  ' // If there is a menu, we need to check how much wrapping occurs when we set
  ' // the window to the width specified by AdjustWindowRectEX and an infinite
  ' // amount of height. An infinite height allows us to see every single menu wrap.

   IF ISTRUE hMenu THEN
      rcTemp = rc
      rcTemp.nBottom = &H7FFF   ' // "Infinite" height
      SendMessage hwnd, %WM_NCCALCSIZE, %FALSE, BYVAL VARPTR(rcTemp)
      ' // Adjust our previous calculation to compensate for menu wrapping.
      rc.Bottom = rc.Bottom + rcTemp.Top
   END IF

   ' // The AdjustWindowRectEx function does not take the WS_VSCROLL or WS_HSCROLL
   ' // styles into account. To account for the scroll bars, we need to call the
   ' // GetSystemMetrics function with SM_CXVSCROLL or SM_CYHSCROLL.
   IF (dwStyle AND %WS_HSCROLL) = %WS_HSCROLL THEN
      rc.Bottom = rc.Bottom + GetSystemMetrics(%SM_CYHSCROLL)
   END IF
   IF (dwStyle AND %WS_VSCROLL) = %WS_VSCROLL THEN
      rc.Right = rc.Right + GetSystemMetrics(%SM_CXVSCROLL)
   END IF
   cx = rc.Right - rc.Left
   cy = rc.Bottom - rc.Top
   SetWindowPos(hwnd, %NULL, 0, 0, cx, cy, %SWP_NOZORDER OR %SWP_NOMOVE OR %SWP_NOACTIVATE)

END SUB
' ========================================================================================

' ========================================================================================
' Sets the keyboard focus to the specified window. The window must be attached to the
' calling thread's message queue.
' ========================================================================================
FUNCTION AfxSetWindowFocus (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SetFocus(hwnd)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the font with which the window is currently drawing its text.
' hFont
'   Handle to the font. If this parameter is NULL, the control uses the default system
'   font to draw text.
' fRedraw
'   Specifies whether the control should be redrawn immediately upon setting the font. If
'   this parameter is TRUE, the control redraws itself.
' ========================================================================================
SUB AfxSetWindowFont (BYVAL hwnd AS DWORD, BYVAL hFont AS DWORD, OPTIONAL BYVAL fRedraw AS LONG)
   SendMessage hwnd, %WM_SETFONT, hFont, fRedraw
END SUB
' ========================================================================================

' ========================================================================================
' Associates a new icon with a window. The system displays the large icon in the
' ALT+TAB dialog box and the small icon in the window caption.
' Parameters:
' - hwnd  = Window handle
' - hIcon = Handle to the new large icon.
'   If this parameter is NULL, the icon indicated is removed.
' - nIconType = %ICON_BIG or %ICON_SMALL.
' ========================================================================================
FUNCTION AfxSetWindowIcon (BYVAL hwnd AS DWORD, BYVAL hIcon AS DWORD, BYVAL nIconType AS LONG) AS DWORD
   FUNCTION = SendMessage(hwnd, %WM_SETICON, nIconType, hIcon)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the location of the top left corner of the window, in pixels.
' The location is relative to the upper-left corner of the client area in the parent window.
' ========================================================================================
FUNCTION AfxSetWindowLocation (BYVAL hwnd AS DWORD, BYVAL nLeft AS LONG, BYVAL nTop AS LONG) AS LONG
   FUNCTION = SetWindowPos(hwnd, 0, nLeft, nTop, 0, 0, %SWP_NOSIZE OR %SWP_NOZORDER)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the size in pixels of the specified window.
' ========================================================================================
FUNCTION AfxSetWindowSize (BYVAL hwnd AS DWORD, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS LONG
   FUNCTION = SetWindowPos(hwnd, 0, 0, 0, nWidth, nHeight, %SWP_NOZORDER OR %SWP_NOMOVE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Changes the text of a window.
' Note: SetWindowText cannot change the text of a control in another application.
' ========================================================================================
FUNCTION AfxSetWindowTextA (BYVAL hwnd AS DWORD, BYVAL strText AS STRING) AS LONG
   FUNCTION = SendMessageA(hwnd, %WM_SETTEXT, 0, STRPTR(strText))
END FUNCTION
' ========================================================================================
FUNCTION AfxSetWindowTextW (BYVAL hwnd AS DWORD, BYVAL bstrText AS WSTRING) AS LONG
   FUNCTION = SendMessageW(hwnd, %WM_SETTEXT, 0, STRPTR(bstrText))
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxSetWindowText = AfxSetWindowTextW
#ELSE
   MACRO AfxSetWindowText = AfxSetWindowTextA
#ENDIF

' ========================================================================================
' Change the visible state of a window.
' ========================================================================================
FUNCTION AfxShowWindowState (BYVAL hwnd AS DWORD, BYVAL nShowState AS LONG) AS LONG
   FUNCTION = ShowWindow(hwnd, nShowState)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets a new address for the dialog box procedure.
' ========================================================================================
FUNCTION AfxSubclassDialog(BYVAL hDlg AS DWORD, BYVAL lpfn AS DWORD) AS LONG
   FUNCTION = SetWindowLong(hDlg, %DWLP_DLGPROC, lpfn)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets a new address for the window procedure.
' ========================================================================================
FUNCTION AfxSubclassWindow(BYVAL hwnd AS DWORD, BYVAL lpfn AS DWORD) AS DWORD
   FUNCTION = SetWindowLong(hwnd, %GWLP_WNDPROC, lpfn)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Checks a menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - uItem = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'           identifier. Otherwise, it is a menu item position.
' Return Value: The return value specifies the previous state of the menu item (either
' MF_CHECKED or MF_UNCHECKED). If the menu item does not exist, the return value is -1.
' ========================================================================================
FUNCTION AfxCheckMenuItem (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, OPTIONAL BYVAL fByPosition AS LONG) AS LONG
   LOCAL dwFlags AS DWORD
   IF fByPosition THEN dwFlags = %MF_BYPOSITION ELSE dwFlags = %MF_BYCOMMAND
   dwFlags = dwFlags OR %MF_CHECKED
   FUNCTION = CheckMenuItem(hMenu, uItem, dwFlags)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Unchecks a menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - uItem = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'           identifier. Otherwise, it is a menu item position.
' Return Value: The return value specifies the previous state of the menu item (either
' MF_CHECKED or MF_UNCHECKED). If the menu item does not exist, the return value is -1.
' ========================================================================================
FUNCTION AfxUnCheckMenuItem (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, OPTIONAL BYVAL fByPosition AS LONG) AS LONG
   LOCAL dwFlags AS DWORD
   IF fByPosition THEN dwFlags = %MF_BYPOSITION ELSE dwFlags = %MF_BYCOMMAND
   dwFlags = dwFlags OR %MF_UNCHECKED
   FUNCTION = CheckMenuItem(hMenu, uItem, dwFlags)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Toggles the checked state of a menu item.
' ========================================================================================
FUNCTION ToggleMenuItem (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, OPTIONAL BYVAL fByPosition AS LONG) AS LONG
   LOCAL dwFlags AS DWORD
   IF fByPosition THEN dwFlags = %MF_BYPOSITION ELSE dwFlags = %MF_BYCOMMAND
   IF GetMenuState(hMenu, uItem, dwFlags) AND %MF_CHECKED = %MF_CHECKED THEN
      dwFlags = dwFlags OR %MF_UNCHECKED
   ELSE
      dwFlags = dwFlags OR %MF_CHECKED
   END IF
   FUNCTION = CheckMenuItem(hMenu, uItem, dwFlags)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified menu item is checked; FALSE otherwise.
' ========================================================================================
FUNCTION AfxIsMenuItemChecked (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, OPTIONAL BYVAL fByPosition AS LONG) AS LONG
   LOCAL dwFlags AS DWORD
   IF fByPosition THEN dwFlags = %MF_BYPOSITION ELSE dwFlags = %MF_BYCOMMAND
   IF GetMenuState(hMenu, uItem, dwFlags) AND %MF_CHECKED = %MF_CHECKED THEN FUNCTION = %TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified menu item is enabled; FALSE otherwise.
' ========================================================================================
FUNCTION AfxIsMenuItemEnabled (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, OPTIONAL BYVAL fByPosition AS LONG) AS LONG
   LOCAL dwFlags, dwRes AS DWORD
   IF fByPosition THEN dwFlags = %MF_BYPOSITION ELSE dwFlags = %MF_BYCOMMAND
   dwRes = GetMenuState(hMenu, uItem, dwFlags)
   IF ((dwRes AND %MF_DISABLED) <> %MF_DISABLED) AND ((dwRes AND %MF_GRAYED) <> %MF_GRAYED) THEN FUNCTION = %TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified menu item is disabled; FALSE otherwise.
' ========================================================================================
FUNCTION AfxIsMenuItemDisabled (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, OPTIONAL BYVAL fByPosition AS LONG) AS LONG
   LOCAL dwFlags, dwRes AS DWORD
   IF fByPosition THEN dwFlags = %MF_BYPOSITION ELSE dwFlags = %MF_BYCOMMAND
   dwRes = GetMenuState(hMenu, uItem, dwFlags)
   IF ((dwRes AND %MF_DISABLED) = %MF_DISABLED) THEN FUNCTION = %TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified menu item is grayed; FALSE otherwise.
' ========================================================================================
FUNCTION AfxIsMenuItemGrayed (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, OPTIONAL BYVAL fByPosition AS LONG) AS LONG
   LOCAL dwFlags, dwRes AS DWORD
   IF fByPosition THEN dwFlags = %MF_BYPOSITION ELSE dwFlags = %MF_BYCOMMAND
   dwRes = GetMenuState(hMenu, uItem, dwFlags)
   IF ((dwRes AND %MF_GRAYED) = %MF_GRAYED) THEN FUNCTION = %TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified menu item is highlighted; FALSE otherwise.
' ========================================================================================
FUNCTION AfxIsMenuItemHighlighted (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, OPTIONAL BYVAL fByPosition AS LONG) AS LONG
   LOCAL dwFlags, dwRes AS DWORD
   IF fByPosition THEN dwFlags = %MF_BYPOSITION ELSE dwFlags = %MF_BYCOMMAND
   dwRes = GetMenuState(hMenu, uItem, dwFlags)
   IF ((dwRes AND %MF_HILITE) = %MF_HILITE) THEN FUNCTION = %TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified menu item is a separator; FALSE otherwise.
' ========================================================================================
FUNCTION AfxIsMenuItemSeparator (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, OPTIONAL BYVAL fByPosition AS LONG) AS LONG
   LOCAL dwFlags, dwRes AS DWORD
   IF fByPosition THEN dwFlags = %MF_BYPOSITION ELSE dwFlags = %MF_BYCOMMAND
   dwRes = GetMenuState(hMenu, uItem, dwFlags)
   IF ((dwRes AND %MF_SEPARATOR) = %MF_SEPARATOR) THEN FUNCTION = %TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified menu item is a submenu; FALSE otherwise.
' ========================================================================================
FUNCTION AfxIsMenuItemPopup (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, OPTIONAL BYVAL fByPosition AS LONG) AS LONG
   LOCAL dwFlags, dwRes AS DWORD
   IF fByPosition THEN dwFlags = %MF_BYPOSITION ELSE dwFlags = %MF_BYCOMMAND
   dwRes = GetMenuState(hMenu, uItem, dwFlags)
   IF ((dwRes AND %MF_POPUP) = %MF_POPUP) THEN FUNCTION = %TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified menu item is ownerdraw; FALSE otherwise.
' ========================================================================================
FUNCTION AfxIsMenuItemOwnerDraw (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, OPTIONAL BYVAL fByPosition AS LONG) AS LONG
   LOCAL dwFlags, dwRes AS DWORD
   IF fByPosition THEN dwFlags = %MF_BYPOSITION ELSE dwFlags = %MF_BYCOMMAND
   dwRes = GetMenuState(hMenu, uItem, dwFlags)
   IF ((dwRes AND %MF_OWNERDRAW) = %MF_OWNERDRAW) THEN FUNCTION = %TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the state of the specified menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - uItem = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'           identifier. Otherwise, it is a menu item position.
' Return Value: 0 on failure or one or more of the following values:
' - MFS_CHECKED    The item is checked
'   &H00000008???
' - MFS_DEFAULT    The menu item is the default.
'   &H00001000???
' - MFS_DISABLED   The item is disabled.
'   &H00000003???
' - MFS_ENABLED    The item is enabled.
'   &H00000000???
' - MFS_GRAYED     The item is grayed.
'   &H00000003???
' - MFS_HILITE     The item is highlighted
'   &H00000080???
' - MFS_UNCHECKED  The item is unchecked.
'   &H00000000???
' - MFS_UNHILITE   The item is not highlighed.
'   &H00000000???
' Note: To get extended error information, use the GetLastError function.
' ========================================================================================
FUNCTION AfxGetMenuItemState (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, OPTIONAL BYVAL fByPosition AS LONG) AS DWORD
   LOCAL mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = %MIIM_STATE
   IF GetMenuItemInfoW(hMenu, uItem, fByPosition, mii) = 0 THEN EXIT FUNCTION
   FUNCTION = mii.fState
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the state of the specified menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - uItem = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - fState = The menu item state. It can be one or more of these values:
' - MFS_CHECKED    Checks the menu item.
'   &H00000008???
' - MFS_DEFAULT    Specifies that the menu item is the default.
'   &H00001000???
' - MFS_DISABLED   Disables the menu item and grays it so that it cannot be selected.
'   &H00000003???  This is equivalent to MFS_GRAYED.
' - MFS_ENABLED    Enables the menu item so that it can be selected. This is the default state.
'   &H00000000???
' - MFS_GRAYED     Disables the menu item and grays it so that it cannot be selected.
'   &H00000003???  This is equivalent to MFS_DISABLED.
' - MFS_HILITE     Highlights the menu item.
'   &H00000080???
' - MFS_UNCHECKED  Unchecks the menu item.
'   &H00000000???
' - MFS_UNHILITE   Removes the highlight from the menu item. This is the default state.
'   &H00000000???
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'                 identifier. Otherwise, it is a menu item position.
' Return Value: If the function succeeds, the return value is nonzero. If the function
'   fails, the return value is zero. To get extended error information, use the
'   GetLastError function.
' Note: The application must call the DrawMenuBar function whenever a menu changes,
' whether or not the menu is in a displayed window.
' ========================================================================================
FUNCTION AfxSetMenuItemState (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, BYVAL fState AS DWORD, OPTIONAL BYVAL fByPosition AS LONG) AS LONG
   LOCAL mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = %MIIM_STATE
   mii.fState = fState
   FUNCTION = SetMenuItemInfoW(hMenu, uItem, fByPosition, mii)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Enables the specified menu item.
' ========================================================================================
FUNCTION AfxEnableMenuItem (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, OPTIONAL BYVAL fByPosition AS LONG) AS LONG
   LOCAL mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = %MIIM_STATE
   mii.fState = %MFS_ENABLED
   FUNCTION = SetMenuItemInfoW(hMenu, uItem, fByPosition, mii)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Disables the specified menu item.
' ========================================================================================
FUNCTION AfxDisableMenuItem (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, OPTIONAL BYVAL fByPosition AS LONG) AS LONG
   LOCAL mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = %MIIM_STATE
   mii.fState = %MFS_DISABLED
   FUNCTION = SetMenuItemInfoW(hMenu, uItem, fByPosition, mii)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Grays the specified menu item.
' ========================================================================================
FUNCTION AfxGrayMenuItem (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, OPTIONAL BYVAL fByPosition AS LONG) AS LONG
   LOCAL mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = %MIIM_STATE
   mii.fState = %MFS_GRAYED
   FUNCTION = SetMenuItemInfoW(hMenu, uItem, fByPosition, mii)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Highlights the specified menu item.
' ========================================================================================
FUNCTION AfxHiliteMenuItem (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, OPTIONAL BYVAL fByPosition AS LONG) AS LONG
   LOCAL mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = %MIIM_STATE
   mii.fState = %MFS_HILITE
   FUNCTION = SetMenuItemInfoW(hMenu, uItem, fByPosition, mii)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the text of the specified menu item.
' - hMenu = Handle to the menu that contains the menu item.
' - uItem = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'           identifier. Otherwise, it is a menu item position.
' ========================================================================================
FUNCTION AfxGetMenuItemText (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, OPTIONAL BYVAL fByPosition AS LONG) AS WSTRING

   LOCAL mii AS MENUITEMINFOW
   LOCAL buffer AS WSTRING

   mii.cbSize = SIZEOF(mii)
   mii.fMask = %MIIM_STRING
   mii.dwTypeData = %NULL

   ' // Get the needed size of the buffer
   IF GetMenuItemInfoW(hMenu, uItem, fByPosition, mii) = 0 THEN EXIT FUNCTION
   ' // Make room for the trailing null
   INCR mii.cch
   ' // Allocate the buffer
   buffer = SPACE$(mii.cch)
   ' // Get the menu string
   mii.dwTypeData = STRPTR(buffer)
   IF GetMenuItemInfoW(hMenu, uItem, fByPosition, mii) THEN
      FUNCTION = RTRIM$(buffer, $NUL)
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes the system menu close option and disables the X button.
' ========================================================================================
SUB AfxRemoveCloseMenu (BYVAL hwnd AS DWORD)
   DIM hMenu AS DWORD
   DIM cbItems AS LONG
   ' // Get the system menu handle
   hMenu = GetSystemMenu(hwnd, 0)
   IF hMenu = 0 THEN EXIT SUB
   ' // Get the number of menu items
   cbItems = GetMenuItemCount(hMenu)
   ' // Remove the close menu item
   RemoveMenu(hMenu, cbItems - 1, %MF_REMOVE OR %MF_BYPOSITION)
   ' // Remove the separator line
   RemoveMenu(hMenu, cbItems - 2, %MF_REMOVE OR %MF_BYPOSITION)
   ' // Redraw the menu (this refreshes the caption bar, dimming the X button)
   DrawMenuBar(hwnd)
END SUB
' ========================================================================================

' ========================================================================================
' Right justifies a top level menu item. This is usually used to have the Help menu item
' right-justified on the menu bar.
' - hwnd  = [in] A handle to the menu that contains the menu item.
' - uItem = [in] The zero-based position of the menu item to change.
' Return value:
'   If the function succeeds, the return value is nonzero.
'   If the function fails, the return value is zero.
' ========================================================================================
FUNCTION AfxRightJustifyMenuItem (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD) AS LONG
   LOCAL mii AS MENUITEMINFOW
   LOCAL buffer AS WSTRINGZ * %MAX_PATH + 1
   mii.cbSize = SIZEOF(MENUITEMINFOW)
   mii.dwTypeData = VARPTR(buffer)
   mii.cch = %MAX_PATH
   mii.fType = %MF_STRING
   mii.fState = %MFS_DEFAULT
   mii.fMask = %MIIM_ID OR %MIIM_DATA OR %MIIM_TYPE OR %MIIM_SUBMENU
   IF GetMenuItemInfoW(hMenu, uItem, %TRUE, mii) THEN
      mii.fType = mii.fType OR %MF_HELP
      FUNCTION = SetMenuItemInfoW(hMenu, uItem, %TRUE, mii)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Changes the text of a menu item to bold.
' - hwnd  = [in] A handle to the menu that contains the menu item.
' - uItem = [in] The zero-based position of the menu item to change.
' Return value:
'   If the function succeeds, the return value is nonzero.
'   If the function fails, the return value is zero.
' ========================================================================================
FUNCTION AfxSetMenuItemBold (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD) AS LONG
   LOCAL mii AS MENUITEMINFOW
   LOCAL buffer AS WSTRINGZ * %MAX_PATH + 1
   mii.cbSize = SIZEOF(MENUITEMINFOW)
   mii.dwTypeData = VARPTR(buffer)
   mii.cch = %MAX_PATH
   mii.fType = %MF_STRING
   mii.fMask = %MIIM_ID OR %MIIM_DATA OR %MIIM_TYPE OR %MIIM_SUBMENU OR %MIIM_STATE
   IF GetMenuItemInfoW(hMenu, uItem, %TRUE, mii) THEN
      mii.fState = mii.fState OR &H1000
      FUNCTION = SetMenuItemInfoW(hMenu, uItem, %TRUE, mii)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the text of the specified menu item.
' - hMenu = A handle to the menu that contains the menu item.
' - uItem = The identifier or position of the menu item to get information about.
'           The meaning of this parameter depends on the value of fByPosition.
' - strText = Text to set.
' - fByPosition = The meaning of uItem. If this parameter is FALSE, uItem is a menu item
'           identifier. Otherwise, it is a menu item position.
' ========================================================================================
FUNCTION AfxSetMenuItemText (BYVAL hMenu AS DWORD, BYVAL uItem AS DWORD, BYVAL bstrText AS WSTRING, OPTIONAL BYVAL fByPosition AS LONG) AS LONG
   LOCAL mii AS MENUITEMINFOW
   mii.cbSize = SIZEOF(mii)
   mii.fMask = %MIIM_STRING
   mii.dwTypeData = STRPTR(bstrText)
   FUNCTION = SetMenuItemInfoW(hMenu, uItem, fByPosition, mii)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a string from the specified section in an initialization file.
' ========================================================================================
FUNCTION AfxIniFileRead (BYVAL bstrIniFileName AS WSTRING, BYVAL bstrSectionName AS WSTRING, BYVAL bstrKeyName AS WSTRING, OPTIONAL BYVAL bstrDefault AS WSTRING) AS WSTRING
   LOCAL dwChars AS DWORD
   LOCAL wszReturnedString AS WSTRINGZ * 65535
   dwChars = GetPrivateProfileStringW(BYCOPY bstrSectionName, BYCOPY bstrKeyName, BYCOPY bstrDefault, wszReturnedString, SIZEOF(wszReturnedString), BYCOPY bstrIniFileName)
   FUNCTION = LEFT$(wszReturnedString, dwChars)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION AfxIniFileWrite (BYVAL bstrIniFileName AS WSTRING, BYVAL bstrSectionName AS WSTRING, BYVAL bstrKeyName AS WSTRING, BYVAL bstrValue AS WSTRING) AS LONG
   FUNCTION = WritePrivateProfileStringW(BYCOPY bstrSectionName, BYCOPY bstrKeyName, BYCOPY bstrValue, BYCOPY bstrIniFileName)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes a key from specified section of an initialization file.
' ========================================================================================
FUNCTION AfxIniFileDeleteKey (BYVAL bstrIniFileName AS WSTRING, BYVAL bstrSectionName AS WSTRING, BYVAL bstrKeyName AS WSTRING) AS LONG
   FUNCTION = WritePrivateProfileStringW(BYCOPY bstrSectionName, BYCOPY bstrKeyName, BYVAL %NULL, BYCOPY bstrIniFileName)
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION AfxIniFileDeleteSection (BYVAL bstrIniFileName AS WSTRING, BYVAL bstrSectionName AS WSTRING) AS LONG
   FUNCTION = WritePrivateProfileStringW(BYCOPY bstrSectionName, BYVAL %NULL, BYVAL %NULL, BYCOPY bstrIniFileName)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether the buttons are swapped.
' Returns nonzero if the meanings of the left and right mouse buttons are swapped; otherwise, 0.
' ========================================================================================
FUNCTION AfxAreMouseButtonsSwapped () AS LONG
   IF GetSystemMetrics(%SM_MOUSEPRESENT) THEN
      FUNCTION = GetSystemMetrics(%SM_SWAPBUTTON)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Mouse speed can range from 1 (slowest) to 20 (fastest) and represents how much the
' pointer moves based on the distance the mouse moves. The default value is 10, which
' results in no additional modification to the mouse motion.
' The MouseThreshold (1 and 2) properties can take on values between 0 and 12.
' ========================================================================================
SUB AfxGetMouse (BYREF nSpeed AS LONG, BYREF nThreshold1 AS LONG, BYREF nThreshold2 AS LONG)
   LOCAL r AS LONG
   DIM rgMouseInfo(2) AS LONG
   IF GetSystemMetrics(%SM_MOUSEPRESENT) THEN
      IF SystemParametersInfo(%SPI_GETMOUSE, 0, rgMouseInfo(0), 0) THEN
         nSpeed = rgMouseInfo(2)
         nThreshold1 = rgMouseInfo(0)
         nThreshold2 = rgMouseInfo(1)
      END IF
   END IF
END SUB
' ========================================================================================

' ========================================================================================
' Indicates whether the left mouse button is down.
' ========================================================================================
FUNCTION AfxIsLButtonDown () AS LONG
   FUNCTION = (GetKeyState(%VK_LBUTTON) < 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Indicates whether the middle mouse button is down.
' ========================================================================================
FUNCTION AfxIsMButtonDown() AS LONG
   FUNCTION = (GetKeyState(%VK_MBUTTON) < 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether the horizontal mouse wheel is installed.
' Returns nonzero if a mouse with a horizontal scroll wheel is installed; otherwise 0.
' ========================================================================================
FUNCTION AfxIsMouseHorizontalWheelInstalled () AS LONG
   FUNCTION = GetSystemMetrics(%SM_MOUSEHORIZONTALWHEELPRESENT)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether the mouse is installed.
' Returns nonzero if a mouse is installed; otherwise, 0. This value is rarely zero,
' because of support for virtual mice and because some systems detect the presence
' of the port instead of the presence of a mouse.
' ========================================================================================
FUNCTION AfxIsMouseInstalled () AS LONG
   FUNCTION = GetSystemMetrics(%SM_MOUSEPRESENT)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether the mouse wheel is installed.
' Returns nonzero if a mouse with a vertical scroll wheel is installed; otherwise 0.
' ========================================================================================
FUNCTION AfxIsMouseWheelInstalled () AS LONG
   FUNCTION = GetSystemMetrics(%SM_MOUSEWHEELPRESENT)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Indicates whether the right mouse button is down.
' ========================================================================================
FUNCTION AfxIsRButtonDown() AS LONG
   FUNCTION = (GetKeyState(%VK_RBUTTON) < 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a copy of the region identified by hrgnSrc.
' ========================================================================================
FUNCTION AfxCopyRegion (BYVAL hrgnDst AS DWORD, BYVAL hrgnSrc AS DWORD) AS LONG
   FUNCTION = CombineRgn(hrgnDst, hrgnSrc, 0, %RGN_COPY)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a logical font.
' Examples of Use:
'   hFont = AfxCreateFontA("MS Sans Serif", 8, %FW_NORMAL, %FALSE, %FALSE, %FALSE, %DEFAULT_CHARSET)
'   hFont = AfxCreateFontA("Courier New", 10, %FW_BOLD, %FALSE, %FALSE, %FALSE, %DEFAULT_CHARSET)
'   hFont = AfxCreateFontA("Marlett", 8, %FW_NORMAL, %FALSE, %FALSE, %FALSE, %SYMBOL_CHARSET)
' Note: Any font created with AfxCreateFont must be destroyed with DeleteObject when no
' longer needed to prevent memory leaks.
' ========================================================================================
FUNCTION AfxCreateFontA ( _
   BYVAL strFaceName AS STRING, _    ' __in Typeface name of font
   BYVAL lPointSize  AS LONG, _      ' __in Point size
   BYVAL lWeight     AS LONG, _      ' __in Font weight(bold etc.)
   BYVAL bItalic     AS BYTE, _      ' __in TRUE = italic
   BYVAL bUnderline  AS BYTE, _      ' __in TRUE = underline
   BYVAL bStrikeOut  AS BYTE, _      ' __in TRUE = strikeout
   BYVAL bCharSet    AS BYTE _       ' __in character set
   ) AS DWORD                        ' Handle of font or NULL on failure.

   LOCAL tlf AS LOGFONTA
   LOCAL hDC AS DWORD

   hDC = GetDC(%HWND_DESKTOP)

   tlf.lfHeight         = -MulDiv(lPointSize, GetDeviceCaps(hDC, %LOGPIXELSY), 72) ' logical font height
   tlf.lfWidth          =  0                                                       ' average character width
   tlf.lfEscapement     =  0                                                       ' escapement
   tlf.lfOrientation    =  0                                                       ' orientation angles
   tlf.lfWeight         =  lWeight                                                 ' font weight
   tlf.lfItalic         =  bItalic                                                 ' italic(TRUE/FALSE)
   tlf.lfUnderline      =  bUnderline                                              ' underline(TRUE/FALSE)
   tlf.lfStrikeOut      =  bStrikeOut                                              ' strikeout(TRUE/FALSE)
   tlf.lfCharSet        =  bCharset                                                ' character set
   tlf.lfOutPrecision   =  %OUT_TT_PRECIS                                          ' output precision
   tlf.lfClipPrecision  =  %CLIP_DEFAULT_PRECIS                                    ' clipping precision
   tlf.lfQuality        =  %DEFAULT_QUALITY                                        ' output quality
   tlf.lfPitchAndFamily =  %FF_DONTCARE                                            ' pitch and family
   tlf.lfFaceName       =  strFaceName                                             ' typeface name

   ReleaseDC %HWND_DESKTOP, hDC

   FUNCTION = CreateFontIndirectA(tlf)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a logical font.
' Examples of Use:
'   hFont = AfxCreateFontW("MS Sans Serif", 8, %FW_NORMAL, %FALSE, %FALSE, %FALSE, %DEFAULT_CHARSET)
'   hFont = AfxCreateFontW("Courier New", 10, %FW_BOLD, %FALSE, %FALSE, %FALSE, %DEFAULT_CHARSET)
'   hFont = AfxCreateFontW("Marlett", 8, %FW_NORMAL, %FALSE, %FALSE, %FALSE, %SYMBOL_CHARSET)
' Note: Any font created with API_CreateFont must be destroyed with DeleteObject when no
' longer needed to prevent memory leaks.
' ========================================================================================
FUNCTION AfxCreateFontW ( _
   BYVAL bstrFaceName AS WSTRING, _   ' __in Typeface name of font
   BYVAL lPointSize   AS LONG, _      ' __in Point size
   BYVAL lWeight      AS LONG, _      ' __in Font weight(bold etc.)
   BYVAL bItalic      AS BYTE, _      ' __in TRUE = italic
   BYVAL bUnderline   AS BYTE, _      ' __in TRUE = underline
   BYVAL bStrikeOut   AS BYTE, _      ' __in TRUE = strikeout
   BYVAL bCharSet     AS BYTE _       ' __in character set
   ) AS DWORD                         ' Handle of font or NULL on failure.

   LOCAL tlf AS LOGFONTW
   LOCAL hDC AS DWORD

   hDC = GetDC(%HWND_DESKTOP)

   tlf.lfHeight         = -MulDiv(lPointSize, GetDeviceCaps(hDC, %LOGPIXELSY), 72) ' logical font height
   tlf.lfWidth          =  0                                                       ' average character width
   tlf.lfEscapement     =  0                                                       ' escapement
   tlf.lfOrientation    =  0                                                       ' orientation angles
   tlf.lfWeight         =  lWeight                                                 ' font weight
   tlf.lfItalic         =  bItalic                                                 ' italic(TRUE/FALSE)
   tlf.lfUnderline      =  bUnderline                                              ' underline(TRUE/FALSE)
   tlf.lfStrikeOut      =  bStrikeOut                                              ' strikeout(TRUE/FALSE)
   tlf.lfCharSet        =  bCharset                                                ' character set
   tlf.lfOutPrecision   =  %OUT_TT_PRECIS                                          ' output precision
   tlf.lfClipPrecision  =  %CLIP_DEFAULT_PRECIS                                    ' clipping precision
   tlf.lfQuality        =  %DEFAULT_QUALITY                                        ' output quality
   tlf.lfPitchAndFamily =  %FF_DONTCARE                                            ' pitch and family
   tlf.lfFaceName       =  bstrFaceName                                            ' typeface name

   ReleaseDC %HWND_DESKTOP, hDC

   FUNCTION = CreateFontIndirectW(tlf)

END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxCreateFont = AfxCreateFontW
#ELSE
   MACRO AfxCreateFont = AfxCreateFontA
#ENDIF

' ========================================================================================
' Deletes a logical bitmap, freeing all system resources associated with the object. After
' the object is deleted, the specified handle is no longer valid.
' ========================================================================================
FUNCTION AfxDeleteBitmap (BYVAL hBitmap AS DWORD) AS LONG
   FUNCTION = DeleteObject(hBitmap)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes a logical brush, freeing all system resources associated with the object. After
' the object is deleted, the specified handle is no longer valid.
' ========================================================================================
FUNCTION AfxDeleteBrush (BYVAL hBrush AS DWORD) AS LONG
   FUNCTION = DeleteObject(hBrush)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes a logical font, freeing all system resources associated with the object. After
' the object is deleted, the specified handle is no longer valid.
' ========================================================================================
FUNCTION AfxDeleteFont (BYVAL hFont AS DWORD) AS LONG
   FUNCTION = DeleteObject(hFont)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes a logical palette, freeing all system resources associated with the object. After
' the object is deleted, the specified handle is no longer valid.
' ========================================================================================
FUNCTION AfxDeletePalette (BYVAL hPalette AS DWORD) AS LONG
   FUNCTION = DeleteObject(hPalette)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes a logical pen, freeing all system resources associated with the object. After
' the object is deleted, the specified handle is no longer valid.
' ========================================================================================
FUNCTION AfxDeletePen (BYVAL hPen AS DWORD) AS LONG
   FUNCTION = DeleteObject(hPen)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Deletes a logical region, freeing all system resources associated with the object. After
' the object is deleted, the specified handle is no longer valid.
' ========================================================================================
FUNCTION AfxDeleteRegion (BYVAL hRgn AS DWORD) AS LONG
   FUNCTION = DeleteObject(hRgn)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the width of a bitmap
' ========================================================================================
FUNCTION AfxGetBitmapWidth (BYVAL hBitmap AS DWORD) AS LONG
   LOCAL bm AS BITMAP
   IF hBitmap = 0 THEN EXIT FUNCTION
   IF GetObject(hBitmap, SIZEOF(bm), bm) THEN FUNCTION = bm.bmWidth
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the height of a bitmap
' ========================================================================================
FUNCTION AfxGetBitmapHeight (BYVAL hBitmap AS DWORD) AS LONG
   LOCAL bm AS BITMAP
   IF hBitmap = 0 THEN EXIT FUNCTION
   IF GetObject(hBitmap, SIZEOF(bm), bm) THEN FUNCTION = bm.bmHeight
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the width and height of a bitmap
' ========================================================================================
FUNCTION AfxGetBitmapSize (BYVAL hBitmap AS DWORD, BYREF nWidth AS LONG, BYREF nHeight AS LONG) AS LONG
   LOCAL bm AS BITMAP
   IF hBitmap = 0 THEN EXIT FUNCTION
   IF GetObject(hBitmap, SIZEOF(bm), bm) THEN
      IF VARPTR(nWidth) THEN nWidth = bm.bmWidth
      IF VARPTR(nHeight) THEN nHeight = bm.bmHeight
      FUNCTION = %TRUE
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Captures the desktop window and returns an handle to a bitmap.
' ========================================================================================
FUNCTION AfxCaptureDesktopWindow () AS DWORD
   LOCAL hScreenDC AS DWORD
   hScreenDC = CreateDCW("DISPLAY", "", "", BYVAL %NULL)
   IF hScreenDC = 0 THEN EXIT FUNCTION
   LOCAL cx, cy AS LONG
   cx = GetDeviceCaps(hScreenDC, %HORZRES)
   cy = GetDeviceCaps(hScreenDC, %VERTRES)
   LOCAL hMemDC AS DWORD
   hMemDC = CreateCompatibleDC(hScreenDC)
   IF hMemDC = 0 THEN EXIT FUNCTION
   LOCAL hBitmap AS DWORD
   hBitmap = CreateCompatibleBitmap(hScreenDC, cx, cy)
   IF hBitmap = 0 THEN EXIT FUNCTION
   LOCAL hBmpOld AS DWORD
   hBmpOld = SelectObject(hMemDC, hBitmap)
   ' // Note: CAPTUREBLT flag is required to capture layered windows
   BitBlt(hMemDC, 0, 0, cx, cy, hScreenDC, 0, 0, %SRCCOPY OR %CAPTUREBLT)
   SelectObject(hMemDC, hBmpOld)
   DeleteDC(hMemDC)
   DeleteDC(hScreenDC)
   FUNCTION = hBitmap
END FUNCTION
' ========================================================================================

' ========================================================================================
' Draws a bitmap.
' - hdc
'     A handle to the destination device context.
' - xStart
'     The x-coordinate, in logical units, of the upper-left corner of the destination rectangle.
' - yStart
'     The y-coordinate, in logical units, of the upper-left corner of the destination rectangle.
' - hBitmap
'     Handle of the bitmap to draw.
' ========================================================================================
FUNCTION AfxDrawBitmap (BYVAL hdc AS DWORD, BYVAL xStart AS LONG, BYVAL yStart AS LONG, BYVAL hBitmap AS DWORD) AS LONG
   LOCAL bm AS BITMAP
   LOCAL hMemDC AS DWORD
   IF hdc = 0 OR hBitmap = 0 THEN EXIT FUNCTION
   hMemDC = CreateCompatibleDC(hdc)
   IF hMemDC = 0 THEN EXIT FUNCTION
   SelectObject hMemDC, hBitmap
   IF GetObject(hBitmap, SIZEOF(BITMAP), bm) THEN
      BitBlt hdc, xStart, yStart, bm.bmWidth, bm.bmHeight, hMemDC, 0, 0, %SRCCOPY
      FUNCTION = %TRUE
   END IF
   DeleteDC hMemDC
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the number of pixels per logical inch along the screen width.
' In a system with multiple display monitors, this value is the same for all monitors.
' ========================================================================================
FUNCTION AfxGetLogPixelsX () AS LONG
   LOCAL hDC AS DWORD
   LOCAL LPX AS DWORD
   hDC = GetDC(%HWND_DESKTOP)
   IF hDC = %NULL THEN EXIT FUNCTION
   LPX = GetDeviceCaps(hDC, %LOGPIXELSX)
   ReleaseDC %HWND_DESKTOP, hDC
   FUNCTION = LPX
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the number of pixels per logical inch along the screen height.
' In a system with multiple display monitors, this value is the same for all monitors.
' ========================================================================================
FUNCTION AfxGetLogPixelsY () AS LONG
   LOCAL hDC AS DWORD
   LOCAL LPY AS DWORD
   hDC = GetDC(%HWND_DESKTOP)
   IF hDC = %NULL THEN EXIT FUNCTION
   LPY = GetDeviceCaps(hDC, %LOGPIXELSY)
   ReleaseDC %HWND_DESKTOP, hDC
   FUNCTION = LPY
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the point size of a font given its logical height
' ========================================================================================
FUNCTION AfxGetFontPointSize (BYVAL nHeight AS LONG) AS LONG
   LOCAL hdc AS DWORD
   hdc = CreateDC("DISPLAY", BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
   IF hdc = %NULL THEN EXIT FUNCTION
   LOCAL cyPixelsPerInch AS LONG
   cyPixelsPerInch = GetDeviceCaps(hdc, %LOGPIXELSY)
   DeleteDC hdc
   LOCAL nPointSize AS LONG
   nPointSize = MulDiv(nHeight, 72, cyPixelsPerInch)
   IF nPointSize < 0 THEN nPointSize = -nPointSize
   FUNCTION = nPointSize
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the logical height of a font given its point size
' ========================================================================================
FUNCTION AfxGetFontHeight (BYVAL nPointSize AS LONG) AS LONG
   LOCAL hdc AS DWORD
   hdc = CreateDC("DISPLAY", BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
   IF hdc = %NULL THEN EXIT FUNCTION
   LOCAL cyPixelsPerInch AS LONG
   cyPixelsPerInch = GetDeviceCaps(hdc, %LOGPIXELSY)
   DeleteDC hdc
   LOCAL nHeight AS LONG
   nHeight = -MulDiv(nPointSize, cyPixelsPerInch, 72)
   FUNCTION = nHeight
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a handle to one of the stock brushes.
' ========================================================================================
FUNCTION AfxGetStockBrush(BYVAL nType AS LONG) AS DWORD
   FUNCTION = GetStockObject(nType)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a handle to one of the stock fonts
' ========================================================================================
FUNCTION AfxGetStockFont(BYVAL nType AS LONG) AS DWORD
   FUNCTION = GetStockObject(nType)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a handle to one of the stock pens
' ========================================================================================
FUNCTION AfxGetStockPen(BYVAL nType AS LONG) AS DWORD
   FUNCTION = GetStockObject(nType)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Calls the InflateRect function, passing in the negative value of the specified x- and y-coordinates.
' ========================================================================================
FUNCTION AfxInsetRect (BYREF lprc AS RECT, BYVAL dx AS LONG, BYVAL dy AS LONG) AS LONG
   FUNCTION = InflateRect(lprc, -dx, -dy)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates the intersection of the two combined regions.
' ========================================================================================
FUNCTION AfxIntersectRegion(BYVAL hrgnResult AS DWORD, BYVAL hrgnA AS DWORD, BYVAL hrgnB AS DWORD) AS LONG
   FUNCTION = CombineRgn(hrgnResult, hrgnA, hrgnB, %RGN_AND)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads a .BMP file from a disk file and returns its handle.
' ========================================================================================
FUNCTION AfxLoadBitmapFromFile (BYVAL bstrFileName AS WSTRING) AS DWORD
   FUNCTION = LoadImageW(BYVAL %NULL, BYCOPY bstrFileName, %IMAGE_BITMAP, 0, 0, %LR_LOADFROMFILE OR %LR_DEFAULTSIZE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads a cursor from a disk file and returns its handle.
' ========================================================================================
FUNCTION AfxLoadCursorFromFile (BYVAL bstrFileName AS WSTRING) AS DWORD
   FUNCTION = LoadImageW(BYVAL %NULL, BYCOPY bstrFileName, %IMAGE_CURSOR, 0, 0, %LR_LOADFROMFILE OR %LR_DEFAULTSIZE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads a .ICO file from a disk file and returns his handle.
' ========================================================================================
FUNCTION AfxLoadIconFromFile (BYVAL bstrFileName AS STRING) AS DWORD
   FUNCTION = LoadImageW(BYVAL %NULL, BYCOPY bstrFileName, %IMAGE_ICON, 0, 0, %LR_LOADFROMFILE OR %LR_DEFAULTSIZE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads an icon from a resource.
' - wID       = [in] Identifier of the icon in the resource file.
' - hInstance = [in, opt] Handle to the instance that contains the resource.
' - bShared   = [in, opt] Shares the image handle if the image is loaded multiple times.
' Returns the handle of the icon if successful, or NULL otherwise.
' ========================================================================================
FUNCTION AfxLoadIconFromResource (BYVAL wID AS WORD, OPTIONAL BYVAL hInstance AS DWORD, OPTIONAL BYVAL bShared AS LONG) AS LONG
   LOCAL hImage, dwFlag, dwID AS DWORD
   IF hInstance = 0 THEN hInstance = GetModuleHandle("")
   IF hInstance = 0 THEN EXIT FUNCTION
   dwID = MAK(DWORD, wID, 0)
   IF bShared THEN dwFlag = %LR_SHARED
   hImage = LoadImage(hInstance, BYVAL dwID, %IMAGE_ICON, 0, 0, %LR_DEFAULTCOLOR OR dwFlag)
   FUNCTION = hImage
END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads a bitmap from a resource.
' - wID       = [in] Identifier of the bitmap in the resource file.
' - hInstance = [in, opt] Handle to the instance that contains the resource.
' - bShared   = [in, opt] Shares the bitmap handle if the bitmap is loaded multiple times.
' Returns the handle of the bitmap if successful, or NULL otherwise.
' ========================================================================================
FUNCTION AfxLoadBitmapFromResource (BYVAL wID AS WORD, OPTIONAL BYVAL hInstance AS DWORD, OPTIONAL BYVAL bShared AS LONG) AS LONG
   LOCAL hImage, dwFlag, dwID AS DWORD
   IF hInstance = 0 THEN hInstance = GetModuleHandle("")
   IF hInstance = 0 THEN EXIT FUNCTION
   dwID = MAK(DWORD, wID, 0)
   IF bShared THEN dwFlag = %LR_SHARED
   hImage = LoadImage(hInstance, BYVAL dwID, %IMAGE_BITMAP, 0, 0, %LR_DEFAULTCOLOR OR dwFlag)
   FUNCTION = hImage
END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads a cusor from a resource.
' - wID       = [in] Identifier of the cusor in the resource file.
' - hInstance = [in, opt] Handle to the instance that contains the resource.
' - bShared   = [in, opt] Shares the cusor handle if the cusor is loaded multiple times.
' Returns the handle of the cusor if successful, or NULL otherwise.
' ========================================================================================
FUNCTION AfxLoadCursorFromResource (BYVAL wID AS WORD, OPTIONAL BYVAL hInstance AS DWORD, OPTIONAL BYVAL bShared AS LONG) AS LONG
   LOCAL hImage, dwFlag, dwID AS DWORD
   IF hInstance = 0 THEN hInstance = GetModuleHandle("")
   IF hInstance = 0 THEN EXIT FUNCTION
   dwID = MAK(DWORD, wID, 0)
   IF bShared THEN dwFlag = %LR_SHARED
   hImage = LoadImage(hInstance, BYVAL dwID, %IMAGE_CURSOR, 0, 0, %LR_DEFAULTCOLOR OR dwFlag)
   FUNCTION = hImage
END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads an icon from a resource file.
' - wID       = [in] Name of the icon in the resource file.
' - hInstance = [in, opt] Handle to the instance that contains the resource.
' - bShared   = [in, opt] Shares the icon handle if the icon is loaded multiple times.
' Returns the handle of the icon if successful, or NULL otherwise.
' ========================================================================================
FUNCTION AfxLoadNamedIconFromResource (BYVAL bstrName AS WSTRING, OPTIONAL BYVAL hInstance AS DWORD, OPTIONAL BYVAL bShared AS LONG) AS LONG
   LOCAL hImage, dwFlag AS DWORD
   IF hInstance = 0 THEN hInstance = GetModuleHandle("")
   IF hInstance = 0 THEN EXIT FUNCTION
   IF bShared THEN dwFlag = %LR_SHARED
   hImage = LoadImage(hInstance, BYCOPY bstrName, %IMAGE_ICON, 0, 0, %LR_DEFAULTCOLOR OR dwFlag)
   FUNCTION = hImage
END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads a bitmap from a resource file.
' - wID       = [in] Name of the bitmap in the resource file.
' - hInstance = [in, opt] Handle to the instance that contains the resource.
' - bShared   = [in, opt] Shares the bitmap handle if the bitmap is loaded multiple times.
' Returns the handle of the bitmap if successful, or NULL otherwise.
' ========================================================================================
FUNCTION AfxLoadNamedBitmapFromResource (BYVAL bstrName AS WSTRING, OPTIONAL BYVAL hInstance AS DWORD, OPTIONAL BYVAL bShared AS LONG) AS LONG
   LOCAL hImage, dwFlag AS DWORD
   IF hInstance = 0 THEN hInstance = GetModuleHandle("")
   IF hInstance = 0 THEN EXIT FUNCTION
   IF bShared THEN dwFlag = %LR_SHARED
   hImage = LoadImage(hInstance, BYCOPY bstrName, %IMAGE_BITMAP, 0, 0, %LR_DEFAULTCOLOR OR dwFlag)
   FUNCTION = hImage
END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads a cursor from a resource file.
' - wID       = [in] Name of the bitmap in the resource file.
' - hInstance = [in, opt] Handle to the instance that contains the resource.
' - bShared   = [in, opt] Shares the IMAGE_CURSOR handle if the IMAGE_CURSOR is loaded multiple times.
' Returns the handle of the IMAGE_CURSOR if successful, or NULL otherwise.
' ========================================================================================
FUNCTION AfxLoadNamedCursorFromResource (BYVAL bstrName AS WSTRING, OPTIONAL BYVAL hInstance AS DWORD, OPTIONAL BYVAL bShared AS LONG) AS LONG
   LOCAL hImage, dwFlag AS DWORD
   IF hInstance = 0 THEN hInstance = GetModuleHandle("")
   IF hInstance = 0 THEN EXIT FUNCTION
   IF bShared THEN dwFlag = %LR_SHARED
   hImage = LoadImage(hInstance, BYCOPY bstrName, %IMAGE_CURSOR, 0, 0, %LR_DEFAULTCOLOR OR dwFlag)
   FUNCTION = hImage
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts from HiMetric to Pixels
' Note: Himetric is a scaling unit similar to twips used in computing. It is one
' thousandth of a centimeter and is independent of the screen resolution.
' %HIMETRIC_PER_INCH = 2540   ' 1 inch = 2.54 mm
' ========================================================================================
SUB AfxHiMetricToPixels (BYREF SizeInHiMetric AS SIZEL, BYREF SizeInPix AS SIZEL)
   LOCAL nPixelsPerInchX AS LONG   ' // Pixels per logical inch along width
   LOCAL nPixelsPerInchY AS LONG   ' // Pixels per logical inch along height
   LOCAL hDCSCreen AS DWORD
   hDCScreen = GetDC(%NULL)
   IF hDCScreen = %NULL THEN EXIT SUB
   nPixelsPerInchX = GetDeviceCaps(hDCScreen, %LOGPIXELSX)
   nPixelsPerInchY = GetDeviceCaps(hDCScreen, %LOGPIXELSY)
   ReleaseDC(%NULL, hDCScreen)
   SizeInPix.cx = MulDiv(SizeInHiMetric.cx, nPixelsPerInchX, 2540)
   SizeInPix.cy = MulDiv(SizeInHiMetric.cy, nPixelsPerInchY, 2540)
END SUB
' ========================================================================================

' ========================================================================================
' Converts from Pixel to HiMetric
' Note: Himetric is a scaling unit similar to twips used in computing. It is one
' thousandth of a centimeter and is independent of the screen resolution.
' %HIMETRIC_PER_INCH = 2540   ' 1 inch = 2.54 mm
' ========================================================================================
SUB AfxPixelsToHiMetric (BYREF SizeInPix AS SIZEL, BYREF SizeInHiMetric AS SIZEL)
   LOCAL nPixelsPerInchX AS LONG   ' // Pixels per logical inch along width
   LOCAL nPixelsPerInchY AS LONG   ' // Pixels per logical inch along height
   LOCAL hDCSCreen AS DWORD
   hDCScreen = GetDC(%NULL)
   IF hDCScreen = %NULL THEN EXIT SUB
   nPixelsPerInchX = GetDeviceCaps(hDCScreen, %LOGPIXELSX)
   nPixelsPerInchY = GetDeviceCaps(hDCScreen, %LOGPIXELSY)
   ReleaseDC(%NULL, hDCScreen)
   SizeInHiMetric.cx = MulDiv(SizeInPix.cx, 2540, nPixelsPerInchX)
   SizeInHiMetric.cy = MulDiv(SizeInPix.cy, 2540, nPixelsPerInchY)
END SUB
' ========================================================================================

' ========================================================================================
' Converts pixels to point size (1/72 of an inch). Horizontal resolution.
' ========================================================================================
FUNCTION AfxPixelsToPointsX (BYVAL pix AS LONG) AS LONG
   LOCAL hDC AS DWORD
   LOCAL LPX AS DWORD
   hDC = GetDC(%HWND_DESKTOP)
   IF hDC = %NULL THEN EXIT FUNCTION
   LPX = GetDeviceCaps(hDC, %LOGPIXELSX)
   ReleaseDC %HWND_DESKTOP, hDC
   FUNCTION = pix * 72 / LPX
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts pixels to point size (1/72 of an inch). Vertical resolution.
' ========================================================================================
FUNCTION AfxPixelsToPointsY (BYVAL pix AS LONG) AS LONG
   LOCAL hDC AS DWORD
   LOCAL LPY AS DWORD
   hDC = GetDC(%HWND_DESKTOP)
   IF hDC = %NULL THEN EXIT FUNCTION
   LPY = GetDeviceCaps(hDC, %LOGPIXELSY)
   ReleaseDC %HWND_DESKTOP, hDC
   FUNCTION = pix * 72 / LPY
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a point size (1/72 of an inch) to pixels. Horizontal resolution.
' ========================================================================================
FUNCTION AfxPointsToPixelsX (BYVAL pts AS LONG) AS LONG
   LOCAL hDC AS DWORD
   LOCAL LPX AS DWORD
   hDC = GetDC(%HWND_DESKTOP)
   IF hDC = %NULL THEN EXIT FUNCTION
   LPX = GetDeviceCaps(hDC, %LOGPIXELSX)
   ReleaseDC %HWND_DESKTOP, hDC
   FUNCTION = MulDiv(pts, LPX, 72)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a point size (1/72 of an inch) to pixels. Vertical resolution.
' ========================================================================================
FUNCTION AfxPointsToPixelsY (BYVAL pts AS LONG) AS LONG
   LOCAL hDC AS DWORD
   LOCAL LPY AS DWORD
   hDC = GetDC(%HWND_DESKTOP)
   IF hDC = %NULL THEN EXIT FUNCTION
   LPY = GetDeviceCaps(hDC, %LOGPIXELSY)
   ReleaseDC %HWND_DESKTOP, hDC
   FUNCTION = MulDiv(pts, LPY, 72)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts pixels to twips. Horizontal resolution.
' ========================================================================================
FUNCTION AfxPixelsToTwipsX (BYVAL nPixels AS LONG) AS LONG
   LOCAL hDC AS DWORD
   LOCAL LPX AS DWORD
   hDC = GetDC(%HWND_DESKTOP)
   IF hDC = %NULL THEN EXIT FUNCTION
   LPX = GetDeviceCaps(hDC, %LOGPIXELSX)
   ReleaseDC %HWND_DESKTOP, hDC
   FUNCTION = (nPixels * 1440) / LPX
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts pixels to twips. Vertical resolution.
' ========================================================================================
FUNCTION AfxPixelsToTwipsY (BYVAL nPixels AS LONG) AS LONG
   LOCAL hDC AS DWORD
   LOCAL LPY AS DWORD
   hDC = GetDC(%HWND_DESKTOP)
   IF hDC = %NULL THEN EXIT FUNCTION
   LPY = GetDeviceCaps(hDC, %LOGPIXELSY)
   ReleaseDC %HWND_DESKTOP, hDC
   FUNCTION = (nPixels * 1440) / LPY
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts twips to pixels. Horizontal resolution.
' ========================================================================================
FUNCTION AfxTwipsToPixelsX (BYVAL nTwips AS LONG) AS LONG
   LOCAL hDC AS DWORD
   LOCAL LPX AS DWORD
   hDC = GetDC(%HWND_DESKTOP)
   IF hDC = %NULL THEN EXIT FUNCTION
   LPX = GetDeviceCaps(hDC, %LOGPIXELSX)
   ReleaseDC %HWND_DESKTOP, hDC
   FUNCTION = (nTwips / 1440) * LPX
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts twips to pixels. Vertical resolution.
' ========================================================================================
FUNCTION AfxTwipsToPixelsY (BYVAL nTwips AS LONG) AS LONG
   LOCAL hDC AS DWORD
   LOCAL LPY AS DWORD
   hDC = GetDC(%HWND_DESKTOP)
   IF hDC = %NULL THEN EXIT FUNCTION
   LPY = GetDeviceCaps(hDC, %LOGPIXELSY)
   ReleaseDC %HWND_DESKTOP, hDC
   FUNCTION = (nTwips / 1440) * LPY
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the width of a pixel, in twips. Horizontal resolution.
' Pixel dimensions can vary between systems and may not always be square, so separate
' functions for pixel width and height are required.
' ========================================================================================
FUNCTION AfxTwipsPerPixelX () AS LONG
   LOCAL hDC AS DWORD
   LOCAL LPX AS DWORD
   hDC = GetDC(%HWND_DESKTOP)
   IF hDC = %NULL THEN EXIT FUNCTION
   LPX = GetDeviceCaps(hDC, %LOGPIXELSX)
   ReleaseDC %HWND_DESKTOP, hDC
   FUNCTION = 1440 / LPX
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the width of a pixel, in twips. Vertical resolution.
' Pixel dimensions can vary between systems and may not always be square, so separate
' functions for pixel width and height are required.
' ========================================================================================
FUNCTION AfxTwipsPerPixelY () AS LONG
   LOCAL hDC AS DWORD
   LOCAL LPY AS DWORD
   hDC = GetDC(%HWND_DESKTOP)
   IF hDC = %NULL THEN EXIT FUNCTION
   LPY = GetDeviceCaps(hDC, %LOGPIXELSY)
   ReleaseDC %HWND_DESKTOP, hDC
   FUNCTION = 1440 / LPY
END FUNCTION
' ========================================================================================

' ========================================================================================
' Selects a bitmap into the specified device context (DC). The new object replaces the
' previous object of the same type.
' ========================================================================================
FUNCTION AfxSelectBitmap (BYVAL hdc AS DWORD, BYVAL hBitmap AS DWORD) AS DWORD
   FUNCTION = SelectObject(hdc, hBitmap)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Selects a brush into the specified device context (DC). The new object replaces the
' previous object of the same type.
' ========================================================================================
FUNCTION AfxSelectBrush (BYVAL hdc AS DWORD, BYVAL hBrush AS DWORD) AS DWORD
   FUNCTION = SelectObject(hdc, hBrush)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Selects a font into the specified device context (DC). The new object replaces the
' previous object of the same type.
' ========================================================================================
FUNCTION AfxSelectFont (BYVAL hdc AS DWORD, BYVAL hFont AS DWORD) AS DWORD
   FUNCTION = SelectObject(hdc, hFont)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Selects a pen into the specified device context (DC). The new object replaces the
' previous object of the same type.
' ========================================================================================
FUNCTION AfxSelectPen (BYVAL hdc AS DWORD, BYVAL hPen AS DWORD) AS DWORD
   FUNCTION = SelectObject(hdc, hPen)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Combines the parts of hrgnA that are not part of hrgnB.
' ========================================================================================
FUNCTION AfxSubtractRegion(BYVAL hrgnResult AS DWORD, BYVAL hrgnA AS DWORD, BYVAL hrgnB AS DWORD) AS LONG
   FUNCTION = CombineRgn(hrgnResult, hrgnA, hrgnB, %RGN_DIFF)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Combines the union of two regions.
' ========================================================================================
FUNCTION AfxUnionRegion (BYVAL hrgnResult AS DWORD, BYVAL hrgnA AS DWORD, BYVAL hrgnB AS DWORD) AS LONG
   FUNCTION = CombineRgn(hrgnResult, hrgnA, hrgnB, %RGN_OR)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates the union of two combined regions except for any overlapping areas.
' ========================================================================================
FUNCTION AfxXorRegion (BYVAL hrgnResult AS DWORD, BYVAL hrgnA AS DWORD, BYVAL hrgnB AS DWORD) AS LONG
   FUNCTION = CombineRgn(hrgnResult, hrgnA, hrgnB, %RGN_XOR)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the path of the Windows directory.
' ========================================================================================
FUNCTION AfxGetWinDir () AS WSTRING
   LOCAL wszWinDir AS WSTRINGZ * %MAX_PATH
   GetWindowsDirectoryW wszWinDir, SIZEOF(wszWinDir)
   FUNCTION = wszWinDir
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the name of the user associated with the current thread.
' ========================================================================================
FUNCTION AfxGetUserName () AS WSTRING
   LOCAL buff AS WSTRINGZ * 260
   GetUserNameW(buff, SIZEOF(buff))
   FUNCTION = buff
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the network user name for the current process.
' ========================================================================================
FUNCTION AfxGetNetUserName () AS WSTRING
   LOCAL dwNameLen AS DWORD
   LOCAL wszUserName AS WSTRINGZ * 256
   dwNameLen = SIZEOF(wszUserName)
   WNetGetUserW(BYVAL %NULL, wszUserName, dwNameLen)
   FUNCTION = wszUserName
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the computer name of the current system.
' ========================================================================================
FUNCTION AfxGetComputerName () AS WSTRING
   LOCAL buff AS WSTRINGZ * %MAX_COMPUTERNAME_LENGTH
   GetComputerNameW(buff, SIZEOF(buff))
   FUNCTION = buff
END FUNCTION
' ========================================================================================

#IF %DEF(%RPCDCE_INC)
' ========================================================================================
' Retrieves the MAC address of a machine's Ethernet card.
' This function only supports one NIC card on your PC.
' ========================================================================================
FUNCTION AfxGetMACAddress () AS WSTRING
   LOCAL i AS LONG
   LOCAL rguid AS GUID
   LOCAL bstrMAC AS WSTRING
   UuidCreateSequential(rguid)
   bstrMAC = MID$(GUIDTXT$(rguid), 26, 12)
   bstrMAC = MID$(bstrMAC, 1, 2) & "-" & MID$(bstrMAC, 3, 2) & "-" & MID$(bstrMAC, 5, 2) & "-" & _
             MID$(bstrMAC, 7, 2) & "-" & MID$(bstrMAC, 9, 2) & "-" & MID$(bstrMAC, 11, 2)
   FUNCTION = bstrMAC
END FUNCTION
' ========================================================================================
#ENDIF   ' #IF %DEF(%RPCDCE_INC)

' ========================================================================================
' Returns the path of the program which is currently executing.
' ========================================================================================
FUNCTION AfxGetExePathName () AS WSTRING
   LOCAL buffer AS WSTRINGZ * %MAX_PATH
   LOCAL p AS LONG
   GetModuleFileNameW %NULL, buffer, SIZEOF(buffer)
   p = INSTR(-1, buffer, ANY ":/\")
   FUNCTION = LEFT$(buffer, p)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file name of the program which is currently executing.
' ========================================================================================
FUNCTION AfxGetExeFileName () AS WSTRING
   LOCAL buffer AS WSTRINGZ * %MAX_PATH
   LOCAL p AS LONG
   GetModuleFileNameW %NULL, buffer, SIZEOF(buffer)
   p = INSTR(-1, buffer, ANY ":/\")
   IF p THEN buffer = MID$(buffer, p + 1)
   p = INSTR(-1, buffer, ".")
   IF p THEN buffer = LEFT$(buffer, p - 1)
   FUNCTION = buffer
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file name and extension of the program which is currently executing.
' ========================================================================================
FUNCTION AfxGetExeFileNameX () AS WSTRING
   LOCAL buffer AS WSTRINGZ * %MAX_PATH
   LOCAL p AS LONG
   GetModuleFileNameW %NULL, buffer, SIZEOF(buffer)
   p = INSTR(-1, buffer, ANY ":/\")
   IF p THEN buffer = MID$(buffer, p + 1)
   FUNCTION = buffer
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the extension (with a leading period) of the program which is currently executing.
' ========================================================================================
FUNCTION AfxGetExeFileExt () AS WSTRING
   LOCAL buffer AS WSTRINGZ * %MAX_PATH
   LOCAL p AS LONG
   GetModuleFileNameW %NULL, buffer, SIZEOF(buffer)
   p = INSTR(-1, buffer, ".")
   IF p THEN FUNCTION = MID$(buffer, p) ELSE FUNCTION = buffer
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the full path of the program which is currently executing.
' ========================================================================================
FUNCTION AfxGetExeFullPath () AS WSTRING
   LOCAL buffer AS WSTRINGZ * %MAX_PATH
   LOCAL cb AS LONG
   cb = GetModuleFileNameW(%NULL, buffer, SIZEOF(buffer))
   FUNCTION = LEFT$(buffer, cb)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Parses a path/filename and returns the file name portion. That is the text to the right
' of the last backslash (\) or colon (:), ending just before the last period (.). The file
' extension is excluded.
' ========================================================================================
FUNCTION AfxGetFileName (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL p AS LONG
   p = INSTR(-1, bstrPath, ANY ":/\")
   IF p THEN bstrPath = MID$(bstrPath, p + 1)
   p = INSTR(-1, bstrPath, ".")
   IF p THEN bstrPath = LEFT$(bstrPath, p - 1)
   FUNCTION = bstrPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Parses a path/filename and returns the file name portion. That is the text to the right
' of the last backslash (\) or colon (:), ending just before the last period (.).
' ========================================================================================
FUNCTION AfxGetFileNameX (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL p AS LONG
   p = INSTR(-1, bstrPath, ANY ":/\")
   IF p THEN FUNCTION = MID$(bstrPath, p + 1) ELSE FUNCTION = bstrPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Parses a path/filename and returns the extension portion of the path/file name. That is
' the last period (.) in the string plus the text to the right of it.
' ========================================================================================
FUNCTION AfxGetFileExt (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL p AS LONG
   p = INSTR(-1, bstrPath, ".")
   IF p THEN FUNCTION = MID$(bstrPath, p) ELSE FUNCTION = bstrPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the version of the specified file.
' Returns a DWORD containing the major version in the low part and the minor version in
' the high part.
' ========================================================================================
FUNCTION AfxGetFileVer (BYVAL bstrFileName AS WSTRING) AS DWORD

   LOCAL pvsffi    AS VS_FIXEDFILEINFO PTR
   LOCAL pVerInfo  AS DWORD
   LOCAL dwHandle  AS DWORD
   LOCAL dwVersion AS DWORD
   LOCAL cbLen     AS DWORD
   LOCAL wMajor    AS WORD
   LOCAL wMinor    AS WORD

   cbLen = GetFileVersionInfoSizeW(BYCOPY bstrFileName, dwHandle)
   IF cbLen THEN
      pVerInfo = HeapAlloc(GetProcessHeap, %HEAP_ZERO_MEMORY, cbLen)
      IF pVerInfo THEN
         IF GetFileVersionInfoW(BYCOPY bstrFileName, dwHandle, cbLen, BYVAL pVerInfo) THEN
            IF VerQueryValueW(BYVAL pVerInfo, "\", BYVAL VARPTR(pvsffi), cbLen) THEN
               wMajor = HI(WORD, @pvsffi.dwFileVersionMS)
               wMinor = LO(WORD, @pvsffi.dwFileVersionMS)
               FUNCTION = MAK(DWORD, wMajor, wMinor)
            END IF
         END IF
         HeapFree GetProcessHeap, 0, pVerInfo
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified file exists or FALSE otherwise.
' ========================================================================================
FUNCTION AfxFileExists (BYVAL bstrFileSpec AS WSTRING) AS LONG

   LOCAL fd AS WIN32_FIND_DATAW
   LOCAL hFind AS DWORD

   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      ' // Make sure that is not a directory or a temporary file
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) <> %FILE_ATTRIBUTE_DIRECTORY AND _
         (fd.dwFileAttributes AND %FILE_ATTRIBUTE_TEMPORARY) <> %FILE_ATTRIBUTE_TEMPORARY THEN
         FUNCTION = %TRUE
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified folder exists or FALSE otherwise.
' ========================================================================================
FUNCTION AfxFolderExists (BYVAL bstrFileSpec AS WSTRING) AS LONG

   LOCAL fd AS WIN32_FIND_DATAW
   LOCAL hFind AS DWORD

   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      ' // Make sure that it is a directory
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) = %FILE_ATTRIBUTE_DIRECTORY THEN
         FUNCTION = %TRUE
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current directory for the current process.
' ========================================================================================
FUNCTION AfxGetCurDir () AS WSTRING
   LOCAL wszCurDir AS WSTRINGZ * %MAX_PATH
   GetCurrentDirectoryW(%MAX_PATH, wszCurDir)
   FUNCTION = wszCurDir
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the instance handle of the current application.
' ========================================================================================
FUNCTION AfxGetInstanceHandle () AS DWORD
   FUNCTION = GetModuleHandleW(BYVAL %NULL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts the specified path to its long form.
' ========================================================================================
FUNCTION AfxGetLongPathName (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL wszLongPath AS WSTRINGZ * %MAX_PATH
   GetLongPathNameW(BYCOPY bstrPath, wszLongPath, SIZEOF(wszLongPath))
   FUNCTION = wszLongPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the short path form of the specified path.
' ========================================================================================
FUNCTION AfxGetShortPathName (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL wszShortPath AS WSTRINGZ * %MAX_PATH
   GetShortPathNameW(BYCOPY bstrPath, wszShortPath, SIZEOF(wszShortPath))
   FUNCTION = wszShortPath
END FUNCTION
' ========================================================================================

#IF %DEF(%SHELLAPI_INC)
' ========================================================================================
' Launches the default browser and loads the specified url.
' ========================================================================================
FUNCTION AfxLaunchDefaultBrowser (BYVAL bstrURL AS WSTRING) AS LONG
   IF LEFT$(UCASE$(bstrURL), 7) <> "HTTP://" THEN bstrURL = "http://" & bstrURL
   FUNCTION = ShellExecuteW(0, "open", BYCOPY bstrURL, BYVAL %NULL, BYVAL %NULL, %SW_SHOWNORMAL)
END FUNCTION
' ========================================================================================
#ENDIF   ' #IF %DEF(%SHELLAPI_INC)

' ========================================================================================
' Centers a window on the screen or over another window.
' It also ensures that the placement is done within the work area.
' Parameters:
' - hwnd = Handle of the window.
' - hwndParent = [optional] Handle of the parent window.
' ========================================================================================
SUB AfxCenterWindow (BYVAL hwnd AS DWORD, OPTIONAL BYVAL hwndParent AS DWORD)

   LOCAL rc            AS RECT    ' // Window coordinates
   LOCAL nWidth        AS LONG    ' // Width of the window
   LOCAL nHeight       AS LONG    ' // Height of the window
   LOCAL rcParent      AS RECT    ' // Parent window coordinates
   LOCAL nParentWidth  AS LONG    ' // Width of the parent window
   LOCAL nParentHeight AS LONG    ' // Height of the parent window
   LOCAL rcWorkArea    AS RECT    ' // Work area coordinates
   LOCAL pt            AS POINT   ' // x and y coordinates of centered window

   ' // Get the coordinates of the window
   GetWindowRect hwnd, rc
   ' // Calculate the width and height
   nWidth = rc.Right - rc.Left
   nHeight = rc.Bottom - rc.Top

   ' // Get the coordinates of the work area
   IF SystemParametersInfo(%SPI_GETWORKAREA, SIZEOF(rcWorkArea), rcWorkArea, 0) = 0 THEN
      rcWorkArea.nRight  = GetSystemMetrics(%SM_CXSCREEN)
      rcWorkArea.nBottom = GetSystemMetrics(%SM_CYSCREEN)
   END IF

   ' // Get the coordinates of the parent window
   IF hwndParent THEN
      GetWindowRect hwndParent, rcParent
   ELSE
      rcParent.nLeft   = rcWorkArea.nLeft
      rcParent.nTop    = rcWorkArea.nTop
      rcParent.nRight  = rcWorkArea.nRight
      rcParent.nBottom = rcWorkArea.nBottom
   END IF
   ' // Calculate the width and height of the parent window
   nParentWidth = rcParent.nRight - rcParent.nLeft
   nParentHeight = rcParent.nBottom - rcParent.nTop

   ' // Calculate the new x coordinate and adjust for work area
   pt.x = rcParent.nLeft + ((nParentWidth - nWidth) \ 2)
   IF (pt.x < rcWorkArea.nLeft) THEN
      pt.x = rcWorkArea.nLeft
   ELSEIF ((pt.x + nWidth) > rcWorkArea.nRight) THEN
      pt.x = rcWorkArea.nRight - nWidth
   END IF

   ' // Calculate the new y corodinate and adjust for work area
   pt.y = rcParent.nTop  + ((nParentHeight - nHeight) \ 2)
   IF (pt.y < rcWorkArea.nTop) THEN
      pt.y = rcWorkArea.nTop
   ELSEIF ((pt.y + nHeight) > rcWorkArea.nBottom) THEN
      pt.y = rcWorkArea.nBottom - nHeight
   END IF

   ' // Convert screen coordinates to client area coordinates
   IF (GetWindowLong(hwnd, %GWL_STYLE) AND %WS_CHILD) = %WS_CHILD THEN ScreenToClient(hwndParent, pt)

   ' // Reposition the window retaining its size and Z order
   SetWindowPos(hwnd, %NULL, pt.x, pt.y, 0, 0, %SWP_NOSIZE OR %SWP_NOZORDER)

END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the current desktop DPI values.
' ========================================================================================
SUB AfxGetDesktopDPI (BYREF dpiX AS SINGLE, BYREF dpiY AS SINGLE)
   LOCAL hDC AS DWORD
   hDC = GetDC(%NULL)
   dpiX = GetDeviceCaps(hDC, %LOGPIXELSX)
   dpiY = GetDeviceCaps(hDC, %LOGPIXELSY)
   ReleaseDC %NULL, hDC
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the current desktop DPI scaling ratios.
' ========================================================================================
SUB AfxGetDesktopDPIRatios (BYREF rxRatio AS SINGLE, BYREF ryRatio AS SINGLE)
   LOCAL hDC AS DWORD
   hDC = GetDC(%NULL)
   rxRatio = (GetDeviceCaps(hDC, %LOGPIXELSX) / 96)
   ryRatio = (GetDeviceCaps(hDC, %LOGPIXELSY) / 96)
   ReleaseDC %NULL, hDC
END SUB
' ========================================================================================

' =====================================================================================
' Scales an horizontal coordinate according the DPI (dots per pixel) being used by the application.
' =====================================================================================
FUNCTION AfxScaleX (BYVAL cx AS SINGLE) AS SINGLE
   LOCAL hDC AS DWORD
   hDC = GetDC(%NULL)
   FUNCTION = cx * (GetDeviceCaps(hDC, %LOGPIXELSX) / 96)
   ReleaseDC %NULL, hDC
END FUNCTION
' =====================================================================================

' =====================================================================================
' Scales a vertical coordinate according the DPI (dots per pixel) being used by the application.
' =====================================================================================
FUNCTION AfxScaleY (BYVAL cy AS SINGLE) AS SINGLE
   LOCAL hDC AS DWORD
   hDC = GetDC(%NULL)
   FUNCTION = cy * (GetDeviceCaps(hDC, %LOGPIXELSY) / 96)
   ReleaseDC %NULL, hDC
END FUNCTION
' =====================================================================================

' =====================================================================================
' Unscales an horizontal coordinate according the DPI (dots per pixel) being used by the application.
' =====================================================================================
FUNCTION AfxUnScaleX (BYVAL cx AS SINGLE) AS SINGLE
   LOCAL hDC AS DWORD
   hDC = GetDC(%NULL)
   FUNCTION = cx / (GetDeviceCaps(hDC, %LOGPIXELSX) / 96)
   ReleaseDC %NULL, hDC
END FUNCTION
' =====================================================================================

' =====================================================================================
' Unscales a vertical coordinate according the DPI (dots per pixel) being used by the application.
' =====================================================================================
FUNCTION AfxUnScaleY (BYVAL cy AS SINGLE) AS SINGLE
   LOCAL hDC AS DWORD
   hDC = GetDC(%NULL)
   FUNCTION = cy / (GetDeviceCaps(hDC, %LOGPIXELSY) / 96)
   ReleaseDC %NULL, hDC
END FUNCTION
' =====================================================================================

' ========================================================================================
' Processes pending Windows messages.
' Call this procedure if you are performing a tight FOR/NEXT or DO/LOOP and need to allow
' your dialog to be responsive to user input.
' ========================================================================================
SUB AfxDoEvents (OPTIONAL BYVAL hwnd AS DWORD)
   LOCAL msg AS tagMsg
   IF hwnd = 0 THEN hwnd = GetActiveWindow
   WHILE PeekMessage(msg, %NULL, %NULL, %NULL, %PM_REMOVE)
      IF ISFALSE IsDialogMessage(hwnd, msg) THEN
         TranslateMessage msg
         DispatchMessage msg
      END IF
   WEND
END SUB
' ========================================================================================

' ========================================================================================
' Processes pending Windows messages.
' Call this procedure if you are performing a tight FOR/NEXT or DO/LOOP and need to allow
' your application to be responsive to user input.
' ========================================================================================
SUB AfxPumpMessages
   LOCAL msg AS tagMsg
   WHILE PeekMessage(msg, %NULL, %NULL, %NULL, %PM_REMOVE)
      TranslateMessage msg
      DispatchMessage msg
   WEND
END SUB
' ========================================================================================

' ========================================================================================
' // Control_RunDLL is an undocumented procedure in the Shell32.dll which can be used
' // to launch control panel applications. You’ve to pass the name of the control panel
' // file (.cpl) and the tool represented by it will be launched. For launching some
' // control panel applications, you’ve to provide a valid windows handle (hwnd parameter)
' // and program instance (hinstance parameter).
' // This opens the control panel: AfxControlRunDLL(0, 0, "", %SW_SHOWNORMAL)
' // This opens the applications wizard: AfxControlRunDLL(0, 0, "appwiz.cpl", %SW_SHOWNORMAL)
' void WINAPI Control_RunDLLW(HWND hWnd, HINSTANCE hInst, LPCWSTR cmd, DWORD nCmdShow)
' ========================================================================================
SUB AfxControlRunDLL (BYVAL hwnd AS DWORD, BYVAL hInst AS DWORD, BYREF cmd AS WSTRINGZ, BYVAL nCmdShow AS DWORD)
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD
   hLib = LoadLibraryW("shell32.dll")
   IF hLib = %NULL THEN EXIT SUB
   pProc = GetProcAddress(hLib, "Control_RunDLLW")
   IF pProc THEN CALL DWORD pProc USING AfxControlRunDLL(hwnd, hInst, cmd, nCmdShow)
   FreeLibrary hLib
END SUB
' ========================================================================================

#IF %DEF(%SHELLAPI_INC)
' ========================================================================================
' Opens a folder in Explorer.
' ========================================================================================
FUNCTION AfxOpenFolder (BYVAL bstrFolder AS WSTRING) AS LONG
   FUNCTION = ShellExecuteW(0, "open", BYCOPY bstrFolder, BYVAL %NULL, BYVAL %NULL, %SW_SHOWNORMAL)
END FUNCTION
' ========================================================================================
#ENDIF   ' #IF %DEF(%SHELLAPI_INC)

' ========================================================================================
' Parses a path/filename and returns the path portion. That is the text up to and including
' the last backslash (\) or colon (:).
' ========================================================================================
FUNCTION AfxGetPathName (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL p AS LONG
   p = INSTR(-1, bstrPath, ANY ":\/")
   IF p THEN FUNCTION = LEFT$(bstrPath, p)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a dword to a float
' Note: An alternate way is to use MEMORY COPY:
' MEMORY COPY f, dw, 4
' ========================================================================================
FUNCTION AfxDwordToFloat (BYVAL dw_ AS DWORD) AS SINGLE
   LOCAL pf AS SINGLE PTR
   pf = VARPTR(dw_)
   FUNCTION = @pf
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a float to a dword
' Note: An alternate way is to use MEMORY COPY:
' MEMORY COPY dw, f, 4
' ========================================================================================
FUNCTION AfxFloatToDword (BYVAL f AS SINGLE) AS DWORD
   LOCAL pdw AS DWORD PTR
   pdw = VARPTR(f)
   FUNCTION = @pdw
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a byte array to a string.
' ========================================================================================
FUNCTION AfxByteArrayToString (BYREF rgbyte() AS BYTE) AS STRING
   LOCAL ln AS LONG
   LOCAL s AS STRING
   ln = UBOUND(rgbyte) - LBOUND(rgbyte) + 1
   IF ln = 0 THEN EXIT FUNCTION
   s = SPACE$(ln)
   MEMORY COPY VARPTR(rgbyte(LBOUND(rgbyte))), STRPTR(s), ln
   FUNCTION = s
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a string to a byte array.
' ========================================================================================
SUB AfxStringToByteArray (BYVAL s AS STRING, BYREF rgbyte() AS BYTE)
   LOCAL ln AS LONG
   LOCAL lb AS LONG
   LOCAL ub AS LONG
   ln = LEN(s)
   IF ln = 0 THEN EXIT SUB
   lb = LBOUND(rgbyte)
   IF lb = 0 THEN
      REDIM rgbyte(ln - 1)
   ELSE
      ub = lb + ln - 1
      REDIM rgbyte(lb TO ub)
   END IF
   MEMORY COPY STRPTR(s), VARPTR(rgbyte(LBOUND(rgbyte))), ln
END SUB
' ========================================================================================

' ========================================================================================
' Converts an array of longs to a string.
' ========================================================================================
FUNCTION AfxLongArrayToString (BYREF rglng() AS LONG) AS STRING
   LOCAL ln AS LONG
   LOCAL s AS STRING
   ln = (UBOUND(rglng) - LBOUND(rglng) + 1) * 4
   IF ln = 0 THEN EXIT FUNCTION
   s = SPACE$(ln)
   MEMORY COPY STRPTR(s), VARPTR(rglng(LBOUND(rglng))), ln
   FUNCTION = s
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts an array of dwords to a string.
' ========================================================================================
FUNCTION AfxDwordArrayToString (BYREF rgdw() AS DWORD) AS STRING
   LOCAL ln AS LONG
   LOCAL s AS STRING
   ln = (UBOUND(rgdw) - LBOUND(rgdw) + 1) * 4
   IF ln = 0 THEN EXIT FUNCTION
   s = SPACE$(ln)
   MEMORY COPY STRPTR(s), VARPTR(rgdw(LBOUND(rgdw))), ln
   FUNCTION = s
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts an array of floats to a string.
' ========================================================================================
FUNCTION AfxFloatArrayToString (BYREF rgflt() AS SINGLE) AS STRING
   LOCAL ln AS LONG
   LOCAL s AS STRING
   ln = (UBOUND(rgflt) - LBOUND(rgflt) + 1) * 4
   IF ln = 0 THEN EXIT FUNCTION
   s = SPACE$(ln)
   MEMORY COPY STRPTR(s), VARPTR(rgflt(LBOUND(rgflt))), ln
   FUNCTION = s
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a double to two Dwords
' ========================================================================================
SUB AfxDoubleToDwords (BYVAL d AS DOUBLE, BYREF dwLo AS DWORD, BYREF dwHi AS DWORD)
   DIM dw_(1) AS DWORD
   MEMORY COPY dw_(0), d, 8
   dwLo = dw_(0)
   dwHi = dw_(1)
END SUB
' ========================================================================================

' ========================================================================================
' Extracts the high part of a double
' ========================================================================================
FUNCTION AfxHiDouble (BYVAL d AS DOUBLE) AS DWORD
   DIM dw_(1) AS DWORD
   MEMORY COPY dw_(0), d, 8
   FUNCTION = dw_(1)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts the low part of a double
' ========================================================================================
FUNCTION AfxLoDouble (BYVAL d AS DOUBLE) AS DWORD
   DIM dw_(1) AS DWORD
   MEMORY COPY dw_(0), d, 8
   FUNCTION = dw_(0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retuns -1 if c is a number (0-9), a numeric sign (+-) or a decimal point (.).
' Note: Works both with single characters and strings.
' ========================================================================================
FUNCTION AfxIsNumeric (BYVAL c AS WSTRING) AS LONG
   FUNCTION = (RETAIN$(c, ANY "+-.0123456789") = c) AND c <> ""
END FUNCTION
' ========================================================================================

' ========================================================================================
' Global, multiline in string function with VBScript regular expressions search patterns.
' Parameters:
' - bstrText = The text to be parsed.
' - bstrPattern = The pattern to match.
' - bIgnoreCase = Ignore case.
' Return Value:
' - Returns a list of comma separated "index, length" value pairs. The pairs are separated
'   by a semicolon.
' Usage Example:
'   LOCAL bstrText AS WSTRING
'   LOCAL bstrPattern AS WSTRING
'   LOCAL bstrOut AS WSTRING
'   bstrText = "blah blah a234 blah blah x345 blah blah"
'   bstrPattern = "[A-Z][0-9][0-9][0-9]"
'   bstrOut = AfxRegExpInStr(bstrText, bstrPattern, %TRUE)
' ========================================================================================
FUNCTION AfxRegExpInStr (BYVAL bstrText AS WSTRING, BYVAL bstrPattern AS WSTRING, OPTIONAL BYVAL bIgnoreCase AS LONG) AS WSTRING

   LOCAL i AS LONG
   LOCAL nCount AS LONG
   LOCAL idx AS LONG
   LOCAL nLen AS LONG
   LOCAL pRegExp AS IRegExp2
   LOCAL pMatch AS IMatch
   LOCAL pMatches AS IMatchCollection
   LOCAL pDisp AS IDispatch
   LOCAL bstrOut AS WSTRING

   pRegExp = NEWCOM "VBScript.RegExp"
   IF ISNOTHING(pRegExp) THEN EXIT FUNCTION

   pRegExp.Pattern = bstrPattern
   pRegExp.Global = -1
   pRegExp.IgnoreCase = (bIgnoreCase <> 0)
   pRegExp.Multiline = -1
   pMatches = pRegExp.Execute(bstrText)
   nCount = pMatches.Count
   IF nCount = 0 THEN EXIT FUNCTION
   FOR i = 0 TO nCount - 1
      pDisp = pMatches.Item(i)
      pMatch = pDisp
      idx = pMatch.FirstIndex
      nLen = pMatch.Length
      bstrOut += FORMAT$(idx + 1) & "," & FORMAT$(nLen) & ";"
   NEXT
   FUNCTION = LEFT$(bstrOut, LEN(bstrOut) - 1)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Explores a folder in Explorer.
' ========================================================================================
FUNCTION AfxExploreFolder (BYVAL bstrFolder AS WSTRING) AS LONG
   FUNCTION = ShellExecuteW(0, "explore", BYCOPY bstrFolder, BYVAL %NULL, BYVAL %NULL, %SW_SHOWNORMAL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns a list with the ports that available for printing on a specified server.
' Names are separated with a carriage return and a line feed characters.
' ========================================================================================
FUNCTION AfxEnumPorts () AS WSTRING
   LOCAL i, cbNeeded, cbReturned AS LONG, bstrNames AS WSTRING
   DIM   Ports(0) AS PORT_INFO_1W
   EnumPortsW(BYVAL %NULL, 1, BYVAL %NULL, 0, cbNeeded, cbReturned)
   IF cbNeeded THEN
      REDIM Ports(0 TO cbNeeded \ SIZEOF(PORT_INFO_1))
#IF %DEF(%USEPBDECL)
      EnumPortsW BYVAL %NULL, 1, BYVAL VARPTR(Ports(0)), SIZEOF(Ports(0)) * (UBOUND(Ports) + 1), cbNeeded, cbReturned
#ELSE
      EnumPortsW BYVAL %NULL, 1, Ports(0), SIZEOF(Ports(0)) * (UBOUND(Ports) + 1), cbNeeded, cbReturned
#ENDIF
      FOR i = 0 TO cbReturned - 1
          bstrNames += Ports(i).@pName
          IF i < cbReturned - 1 THEN bstrNames += $CRLF
      NEXT
   END IF
   FUNCTION = bstrNames
END FUNCTION
' ========================================================================================

' ========================================================================================
' Saves the contents of a string buffer in a temporary file.
' ========================================================================================
FUNCTION AfxSaveTempFile (BYVAL bstrBuffer AS WSTRING, OPTIONAL BYVAL bstrPathName AS WSTRING, _
   BYVAL bstrPrefixString AS WSTRING, BYVAL bstrExtension AS WSTRING, BYVAL uUnique AS DWORD) AS WSTRING

   LOCAL wszTmpPath AS WSTRINGZ * %MAX_PATH
   LOCAL wszTmpFileName AS WSTRINGZ * %MAX_PATH
   LOCAL wszPrefixString AS WSTRINGZ * 4
   LOCAL dwRes AS DWORD
   LOCAL fn AS LONG

   IF LEN(bstrPathName) THEN wszTmpPath = bstrPathName
   IF LEN(bstrPrefixString) THEN wszPrefixString = bstrPrefixString ELSE wszPrefixString = "TMP"
   IF LEN(bstrExtension) THEN IF LEFT$(bstrExtension, 1) = "." THEN bstrExtension = MID$(bstrExtension, 2)
   dwRes = GetTempPathW(%MAX_PATH, wszTmpPath)
   IF dwRes > 0 AND dwRes <= %MAX_PATH - 14 THEN
      dwRes = GetTempFileNameW(wszTmpPath, wszPrefixString, uUnique, wszTmpFileName)
      IF dwRes THEN
         IF LEN(bstrExtension) THEN wszTmpFileName = LEFT$(wszTmpFileName, LEN(wszTmpFileName) - 3) & bstrExtension
         fn = FREEFILE
         OPEN wszTmpFileName FOR OUTPUT AS #fn
         PRINT #fn, bstrBuffer
         CLOSE #fn
      END IF
   END IF
   FUNCTION = wszTmpFileName

END FUNCTION
' ========================================================================================


' ========================================================================================
' Fills a rectangle by using the specified color. This function includes the left and top
' borders, but excludes the right and bottom borders of the rectangle.
' ========================================================================================
FUNCTION AfxFillRectangle (BYVAL hdc AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, BYVAL colour AS DWORD) AS LONG
   LOCAL rc AS RECT, hBrush AS DWORD
   SetRect rc, x, y, x + nWidth, y + nHeight
   hBrush = CreateSolidBrush(colour)
   IF hBrush THEN
      FUNCTION = FillRect(hdc, rc, hBrush)
      DeleteObject hBrush
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a DIB section.
' ========================================================================================
FUNCTION AfxCreateDIBSection (BYVAL hDC AS DWORD, BYVAL nWidth AS DWORD, BYVAL nHeight AS DWORD, BYVAL bitCount AS DWORD, OPTIONAL BYREF ppvBits AS DWORD) AS DWORD
   LOCAL bi AS BITMAPINFO
   bi.bmiHeader.biSize = SIZEOF(bi.bmiHeader)
   bi.bmiHeader.biWidth = nWidth
   bi.bmiHeader.biHeight = nHeight
   bi.bmiHeader.biPlanes = 1
   bi.bmiHeader.biBitCount = bitCount
   bi.bmiHeader.biCompression = %BI_RGB
   IF VARPTR(ppvBits) THEN
      FUNCTION = CreateDIBSection(hDC, bi, %DIB_RGB_COLORS, BYVAL VARPTR(ppvBits), %NULL, 0)
   ELSE
      FUNCTION = CreateDIBSection(hDC, bi, %DIB_RGB_COLORS, BYVAL %NULL, %NULL, 0)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Clears the contents of the clipboard.
' Return Value
'   If the function succeeds, the return value is nonzero.
'   If the function fails, the return value is zero.
' ========================================================================================
FUNCTION AfxClearClipboard () AS LONG
   IF ISTRUE OpenClipboard(0) THEN   ' // Opens the clipboard
      FUNCTION = EmptyClipboard      ' // Empties the clipboard
      CloseClipboard                 ' // Closes the clipboard
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves data from the clipboard in the specified format.
' Parameter
'   cfFormat = Clipboard format.
' Return Value
'   If the function succeeds, the return value is the handle to the data.
'   If the function fails, the return value is NULL.
' ========================================================================================
FUNCTION AfxGetClipboardData (BYVAL cfFormat AS DWORD) AS DWORD

   LOCAL hSource AS DWORD
   LOCAL hDest   AS DWORD
   LOCAL hSize   AS DWORD
   LOCAL pSource AS DWORD
   LOCAL pDest   AS DWORD

   IF OpenClipboard(0) THEN                  ' // Opens the clipboard
      hSource = GetClipboardData(cfFormat)   ' // Retrieves data from the clipboard in the specified format
      CloseClipboard                         ' // Closes the clipboard
      IF ISFALSE hSource THEN EXIT FUNCTION  ' // Exits on failure
   END IF

   hSize = GlobalSize(hSource)               ' // Gets the size of the specified global memory object, in bytes
   IF ISFALSE hSize THEN EXIT FUNCTION       ' // Exits on failure

   pSource = GlobalLock(hSource)             ' // Gets a pointer to the source memory object
   IF ISFALSE pSource THEN EXIT FUNCTION     ' // Exits on failure

   hDest = GlobalAlloc(%GHND, hSize)         ' // Allocates the specified number of bytes from the heap
   IF ISFALSE hDest THEN                     ' // Exits on failure
      GlobalUnlock hSource                   ' // Unlocks the source memory object
      EXIT FUNCTION
   END IF

   pDest = GlobalLock(hDest)                 ' // Gets a pointer to the destination memory object
   IF ISFALSE pDest THEN                     ' // Exits on failure
      GlobalUnlock hSource                   ' // Unlocks the source memory object
      GlobalFree hDest                       ' // Frees the allocated memory block
      EXIT FUNCTION
   END IF

   CopyMemory pDest, pSource, hSize          ' // Copies the data from the source to the destination

   GlobalUnlock hSource                      ' // Unlocks the source memory object
   GlobalUnlock hDest                        ' // Unlocks the destination memory object

   FUNCTION = hDest                          ' // Returns the handle to the data

END FUNCTION
' ========================================================================================

' ========================================================================================
' Places a data object into the clipboard.
' Parameters
'   cfFormat = Clipboard format.
'   hData    = Handle to the data in the specified format.
' Return Value
'   If the function succeeds, the return value is the handle to the data.
'   If the function fails, the return value is NULL.
' Remarks
'   The application must not use the hData handle once it has called the AfxSetClipboardData function.
' ========================================================================================
FUNCTION AfxSetClipboardData (BYVAL cfFormat AS DWORD, BYVAL hData AS DWORD) AS DWORD
   IF OpenClipboard(0) THEN                          ' // Opens the clipboard
      EmptyClipboard                                 ' // Empties the clipboard
      FUNCTION = SetClipboardData(cfFormat, hData)   ' // Places the data object in the clipboard
      CloseClipboard                                 ' // Closes the clipboard
    END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns a text string from the clipboard.
' ========================================================================================
FUNCTION AfxGetClipboardTextA() AS STRING

   LOCAL hMem AS DWORD
   LOCAL pMem AS ASCIIZ PTR

   IF ISTRUE IsClipboardFormatAvailable(%CF_TEXT) THEN   ' // If the text format is available...
      IF ISTRUE OpenClipboard(0) THEN                    ' // Opens the clipboard
         hMem = GetClipboardData(%CF_TEXT)               ' // Gets memory object of clipboard text
         IF hMem THEN
            pMem = GlobalLock(hMem)                      ' // Locks it and get a pointer
            IF pMem THEN FUNCTION = @pMem                ' // Assigns the data to our function return value
            GlobalUnlock hMem                            ' // Releases the memory object
         END IF
         CloseClipboard                                  ' // Closes the clipboard
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns a text string from the clipboard.
' ========================================================================================
FUNCTION AfxGetClipboardTextW() AS WSTRING

   LOCAL hMem AS DWORD
   LOCAL pMem AS WSTRINGZ PTR

   IF ISTRUE IsClipboardFormatAvailable(%CF_UNICODETEXT) THEN   ' // If the text format is available...
      IF ISTRUE OpenClipboard(0) THEN                           ' // Opens the clipboard
         hMem = GetClipboardData(%CF_UNICODETEXT)               ' // Gets memory object of clipboard text
         IF hMem THEN
            pMem = GlobalLock(hMem)                             ' // Locks it and get a pointer
            IF pMem THEN FUNCTION = @pMem                       ' // Assigns the data to our function return value
            GlobalUnlock hMem                                   ' // Releases the memory object
         END IF
         CloseClipboard                                         ' // Closes the clipboard
      END IF
   END IF

END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxGetClipboardText = AfxGetClipboardTextW
#ELSE
   MACRO AfxGetClipboardText = AfxGetClipboardTextA
#ENDIF

' ========================================================================================
' Places a text string into the clipboard.
' Parameter
'   strText = Text to place in the clipboard.
' Return Value
'   If the function succeeds, the return value is the handle to the data.
'   If the function fails, the return value is NULL.
' ========================================================================================
FUNCTION AfxSetClipboardTextA (BYVAL strText AS STRING) AS DWORD

   LOCAL pMem AS DWORD
   LOCAL hMem AS DWORD
   LOCAL hData AS DWORD

   IF ISTRUE OpenClipboard(0) THEN                   ' // Opens the clipboard
       EmptyClipboard                                ' // Empties the clipboard
       hMem  = GlobalAlloc(%GMEM_MOVEABLE OR %GMEM_DDESHARE, LEN(strText) + 1)   ' // Allocates a global memory block
       IF hMem THEN
          pMem = GlobalLock(hMem)                    ' // Locks it and gets a pointer to the memory location
          IF pMem THEN POKE$ pMem, strText & $NUL    ' // Copies the text into the allocated memory block
          GlobalUnlock hMem                          ' // Unlocks the memory block
          hData = SetClipboardData(%CF_TEXT, hMem)   ' // Places the text in the clipboard
          IF ISTRUE hData THEN
             FUNCTION = hData                        ' // Returns the handle of the data
          ELSE
             GlobalFree hMem                         ' // Frees the memory block
          END IF
       END IF
       CloseClipboard                                ' // Closes the clipboard
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Places a text string into the clipboard.
' Parameter
'   bstrText = Text to place in the clipboard.
' Return Value
'   If the function succeeds, the return value is the handle to the data.
'   If the function fails, the return value is NULL.
' ========================================================================================
FUNCTION AfxSetClipboardTextW (BYVAL bstrText AS WSTRING) AS DWORD

   LOCAL pMem AS DWORD
   LOCAL hMem AS DWORD
   LOCAL hData AS DWORD

   IF ISTRUE OpenClipboard(0) THEN                           ' // Opens the clipboard
       EmptyClipboard                                        ' // Empties the clipboard
       hMem  = GlobalAlloc(%GMEM_MOVEABLE OR %GMEM_DDESHARE, (LEN(bstrText) + 1) * 2)   ' // Allocates a global memory block
       IF hMem THEN
          pMem = GlobalLock(hMem)                            ' // Locks it and gets a pointer to the memory location
          IF pMem THEN POKE$$ pMem, bstrText & $NUL & $NUL   ' // Copies the text into the allocated memory block
          GlobalUnlock hMem                                  ' // Unlocks the memory block
          hData = SetClipboardData(%CF_UNICODETEXT, hMem)    ' // Places the text in the clipboard
          IF ISTRUE hData THEN
             FUNCTION = hData                                ' // Returns the handle of the data
          ELSE
             GlobalFree hMem                                 ' // Frees the memory block
          END IF
       END IF
       CloseClipboard                                        ' // Closes the clipboard
   END IF

END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxSetClipboardText = AfxSetClipboardTextW
#ELSE
   MACRO AfxSetClipboardText = AfxSetClipboardTextA
#ENDIF

' ========================================================================================
' Returns a string consisting of a specified number of spaces.
' Note: Workaround for XP SP3, that GPFs if nCount is negative.
' ========================================================================================
FUNCTION AfxSpacesA (BYVAL nCount AS LONG) AS STRING
   IF nCount > 0 THEN FUNCTION = SPACE$(nCount)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxSpacesW (BYVAL nCount AS LONG) AS WSTRING
   IF nCount > 0 THEN FUNCTION = SPACE$(nCount)
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxSpaces = AfxSpacesW
#ELSE
   MACRO AfxSpaces = AfxSpacesA
#ENDIF

' ========================================================================================
' Number of adjacent color bits for each pixel.
' ========================================================================================
FUNCTION AfxGetBitsPerPixel () AS LONG
   LOCAL hDC AS DWORD
   hDC = GetDC(%NULL)
   FUNCTION = GetDeviceCaps(hDC, %BITSPIXEL)
   ReleaseDC %NULL, hDC
END FUNCTION
MACRO AfxGetColorDepth = AfxGetBitsPerPixel
' ========================================================================================

' ========================================================================================
' Number of colors the current video driver will support.
' ========================================================================================
FUNCTION AfxGetNumberOfSupportedColors () AS QUAD
   LOCAL hDC AS DWORD
   hDC = GetDC(%NULL)
   FUNCTION = 2 ^ (GetDeviceCaps(hDC, %PLANES) * GetDeviceCaps(hDC, %BITSPIXEL))
   ReleaseDC %NULL, hDC
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sends a WM_SIZE message to the specified window.
' hwnd = Handle of the window.
' nResizeType = Type of resizing requested.
' nWidth = The new width of the client area.
' nHeight = The new height of the client ara.
' ========================================================================================
FUNCTION AfxWindowResize (BYVAL hwnd AS DWORD, BYVAL nResizeType AS DWORD, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_SIZE, nResizeType, MAK(LONG, nWidth, nHeight))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Resizes a window without moving it.
' hwnd = Handle of the window.
' nWidth = The new width of the client area.
' nHeight = The new height of the client ara.
' If the function succeeds, the return value is nonzero.
' If the function fails, the return value is zero. To get extended error information, call GetLastError.
' ========================================================================================
FUNCTION AfxSizeWindow (BYVAL hwnd AS DWORD, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS LONG
   FUNCTION = SetWindowPos(hwnd, %NULL, 0, 0, nWidth, nHeight, %SWP_NOZORDER OR %SWP_NOMOVE OR %SWP_NOACTIVATE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Calculates the size of a menu bar or a drop-down menu.
' - hwnd = Handle of the window that owns the menu.
' - hmenu = handle of the menu.
' - rcmenu = Pointer to a variable of type RECT where to return the retrieved values.
' Return Value:
' If the function succeeds, the return value is 0.
' If the function fails, the return value is  a system error code.
' ========================================================================================
FUNCTION AfxGetMenuRect (BYVAL hwnd AS DWORD, BYVAL hmenu AS DWORD, BYREF rcmenu AS RECT) AS LONG
   LOCAL i AS LONG, nRes AS LONG, rc AS RECT
   FOR i = 1 TO GetMenuItemCount(hmenu)
      nRes = GetMenuItemRect(hwnd, hmenu, i, rc)
      IF nRes = -1 THEN nRes = GetLastError : EXIT FOR
      UnionRect rcmenu, rcmenu, rc
   NEXT
   FUNCTION = nRes
END FUNCTION
' ========================================================================================

' ========================================================================================
' Fills a rectangular area with a solid colour
' - hdc    = Handle of the device context.
' - rc     = A pointer to a RECT structure that specifies the dimensions, in logical
'            coordinates, of a rectangle that is used for opaquing.
' - colour = The new background color.
' ========================================================================================
SUB AfxPaintRectA (BYVAL hdc AS DWORD, BYREF rc AS RECT, BYVAL colour AS DWORD)
   LOCAL oldclr AS DWORD
   oldclr = SetBkColor(hdc, colour)
   ExtTextOutA(hdc, 0, 0, %ETO_OPAQUE, rc, "", 0, BYVAL %NULL)
   SetBkColor(hdc, oldclr)
END SUB
' ========================================================================================
' ========================================================================================
SUB AfxPaintRectW (BYVAL hdc AS DWORD, BYREF rc AS RECT, BYVAL colour AS DWORD)
   LOCAL oldclr AS DWORD
   oldclr = SetBkColor(hdc, colour)
   ExtTextOutW(hdc, 0, 0, %ETO_OPAQUE, rc, "", 0, BYVAL %NULL)
   SetBkColor(hdc, oldclr)
END SUB
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxPaintRect = AfxPaintRectW
#ELSE
   MACRO AfxPaintRect = AfxPaintRectA
#ENDIF

' ========================================================================================
' If you use dual (or even triple/quad) displays then you have undoubtedly encountered the
' following situation: You change the physical order of your displays, or otherwise
' reconfigure the logical ordering using your display software. This sometimes has the
' side-effect of changing your desktop coordinates from zero-based to negative starting
' coordinates (i.e. the top-left coordinate of your desktop changes from 0,0 to -1024,-768).
' This effects many Windows programs which restore their last on-screen position whenever
' they are started. Should the user reorder their display configuration this can sometimes
' result in a Windows program subsequently starting in an off-screen position (i.e. at a
' location that used to be visible) - and is now effectively invisible, preventing the
' user from closing it down or otherwise moving it back on-screen.
' The ForceVisibleDisplay function can be called at program start-time right after the
' main window has been created and positioned 'on-screen'. Should the window be positioned
' in an off-screen position, it is forced back onto the nearest display to its last
' position. The user will be unaware this is happening and won't even realise to thank you
' for keeping their user-interface visible, even though they changed their display
' settings.
' Source: http://www.catch22.net/tuts/tips2
' ========================================================================================
SUB AfxForceVisibleDisplay (BYVAL hwnd AS DWORD)

   ' // Check if the specified window-recrangle is visible on any display
   LOCAL rc AS RECT
   GetWindowRect(hwnd, rc)
   IF MonitorFromRect(rc, %MONITOR_DEFAULTTONULL) <> %NULL THEN EXIT SUB

   LOCAL hMonitor AS DWORD
   LOCAL mi AS MONITORINFO
   mi.cbSize = SIZEOF(mi)
   ' // Find the nearest display to the rectangle
   hMonitor = MonitorFromRect(rc, %MONITOR_DEFAULTTONEAREST)
   GetMonitorInfo(hMonitor, mi)
   ' // Center window rectangle
   rc.left = mi.rcWork.left + ((mi.rcWork.right - mi.rcWork.left) - (rc.right-rc.left)) \ 2
   rc.top = mi.rcWork.top + ((mi.rcWork.bottom - mi.rcWork.top) - (rc.bottom-rc.top)) \ 2
   SetWindowPos(hwnd, 0, rc.left, rc.top, 0, 0, %SWP_NOACTIVATE OR %SWP_NOZORDER OR %SWP_NOSIZE)

END SUB
' ========================================================================================

' ========================================================================================
' Returns TRUE if the application has been started through a shortcut; FALSE if not.
' ========================================================================================
FUNCTION AfxStartedFromShortcut () AS LONG
   LOCAL si AS STARTUPINFO
   GetStartupInfo(si)
   IF (si.dwFlags AND %STARTF_TITLEISLINKNAME) THEN FUNCTION = %TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the name of the shortcut used to start the application.
' ========================================================================================
FUNCTION AfxStartedFromShortcutNameA () AS STRING
   LOCAL si AS STARTUPINFO
   GetStartupInfoA(si)
   IF (si.dwFlags AND %STARTF_TITLEISLINKNAME) THEN FUNCTION = si.@lpTitle
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxStartedFromShortcutNameW () AS WSTRING
   LOCAL si AS STARTUPINFO
   GetStartupInfoW(si)
   IF (si.dwFlags AND %STARTF_TITLEISLINKNAME) THEN FUNCTION = si.@lpTitle
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxStartedFromShortcutName = AfxStartedFromShortcutNameW
#ELSE
   MACRO AfxStartedFromShortcutName = AfxStartedFromShortcutNameA
#ENDIF

' ========================================================================================
' Redraws the non-client area of the specified window.
' If the function succeeds, the return value is nonzero.
' If the function fails, the return value is zero. To get extended error information, call GetLastError.
' ========================================================================================
FUNCTION AfxRedrawNonClientArea (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SetWindowPos(hwnd, 0, 0, 0, 0, 0, %SWP_NOMOVE OR %SWP_NOSIZE OR %SWP_NOZORDER OR %SWP_NOACTIVATE OR %SWP_FRAMECHANGED OR %SWP_DRAWFRAME)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves information about the caption font.
' ========================================================================================
FUNCTION AfxGetCaptionFontA (BYREF lfa AS LOGFONTA) AS LONG
   LOCAL r AS LONG
   LOCAL ncm AS NONCLIENTMETRICSA
   IF VARPTR(lfa) = 0 THEN EXIT FUNCTION
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 344 ELSE ncm.cbSize = 340
   r = SystemParametersInfoA(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0)
   IF r THEN lfa = ncm.lfCaptionFont
   FUNCTION = r
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxGetCaptionFontW (BYREF lfw AS LOGFONTW) AS LONG
   LOCAL r AS LONG
   LOCAL ncm AS NONCLIENTMETRICSW
   IF VARPTR(lfw) = 0 THEN EXIT FUNCTION
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   r = SystemParametersInfoW(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0)
   IF r THEN lfw = ncm.lfCaptionFont
   FUNCTION = r
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxGetCaptionFont = AfxGetCaptionFontW
#ELSE
   MACRO AfxGetCaptionFont = AfxGetCaptionFontA
#ENDIF

' ========================================================================================
' Retrieves the name of the caption font.
' ========================================================================================
FUNCTION AfxGetCaptionFontNameA () AS STRING
   LOCAL ncm AS NONCLIENTMETRICSA
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 344 ELSE ncm.cbSize = 340
   IF SystemParametersInfoA(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) THEN FUNCTION = ncm.lfCaptionFont.lfFaceName
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxGetCaptionFontNameW () AS WSTRING
   LOCAL ncm AS NONCLIENTMETRICSW
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   IF SystemParametersInfoW(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) THEN FUNCTION = ncm.lfCaptionFont.lfFaceName
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxGetCaptionFontName = AfxGetCaptionFontNameW
#ELSE
   MACRO AfxGetCaptionFontName = AfxGetCaptionFontNameA
#ENDIF

' ========================================================================================
' Retrieves the height of the caption font.
' ========================================================================================
FUNCTION AfxGetCaptionFontHeightA () AS LONG
   LOCAL ncm AS NONCLIENTMETRICSA
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 344 ELSE ncm.cbSize = 340
   IF SystemParametersInfoA(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) THEN FUNCTION = ABS(ncm.lfCaptionFont.lfHeight)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxGetCaptionFontHeightW () AS LONG
   LOCAL ncm AS NONCLIENTMETRICSW
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   IF SystemParametersInfoW(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) THEN FUNCTION = ABS(ncm.lfCaptionFont.lfHeight)
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxGetCaptionFontHeight = AfxGetCaptionFontHeightW
#ELSE
   MACRO AfxGetCaptionFontHeight = AfxGetCaptionFontHeightA
#ENDIF

' ========================================================================================
' Retrieves the point size of the caption font.
' ========================================================================================
FUNCTION AfxGetCaptionFontPointSizeA () AS LONG
   LOCAL ncm AS NONCLIENTMETRICSA
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 344 ELSE ncm.cbSize = 340
   IF SystemParametersInfoA(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) = 0 THEN EXIT FUNCTION
   LOCAL hdc AS DWORD
   hdc = CreateDCA("DISPLAY", BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
   IF hdc = %NULL THEN EXIT FUNCTION
   LOCAL cyPixelsPerInch AS LONG
   cyPixelsPerInch = GetDeviceCaps(hdc, %LOGPIXELSY)
   DeleteDC hdc
   LOCAL nPointSize AS LONG
   nPointSize = MulDiv(ncm.lfCaptionFont.lfHeight, 72, cyPixelsPerInch)
   IF nPointSize < 0 THEN nPointSize = -nPointSize
   FUNCTION = nPointSize
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxGetCaptionFontPointSizeW () AS LONG
   LOCAL ncm AS NONCLIENTMETRICSW
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   IF SystemParametersInfoW(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) = 0 THEN EXIT FUNCTION
   LOCAL hdc AS DWORD
   hdc = CreateDCW("DISPLAY", BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
   IF hdc = %NULL THEN EXIT FUNCTION
   LOCAL cyPixelsPerInch AS LONG
   cyPixelsPerInch = GetDeviceCaps(hdc, %LOGPIXELSY)
   DeleteDC hdc
   LOCAL nPointSize AS LONG
   nPointSize = MulDiv(ncm.lfCaptionFont.lfHeight, 72, cyPixelsPerInch)
   IF nPointSize < 0 THEN nPointSize = -nPointSize
   FUNCTION = nPointSize
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxGetCaptionFontPointSize = AfxGetCaptionFontPointSizeW
#ELSE
   MACRO AfxGetCaptionFontPointSize = AfxGetCaptionFontPointSizeA
#ENDIF

' ========================================================================================
' Retrieves information about the small caption font.
' ========================================================================================
FUNCTION AfxGetSmallCaptionFontA (BYREF lfa AS LOGFONTA) AS LONG
   LOCAL r AS LONG
   LOCAL ncm AS NONCLIENTMETRICSA
   IF VARPTR(lfa) = 0 THEN EXIT FUNCTION
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 344 ELSE ncm.cbSize = 340
   r = SystemParametersInfoA(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0)
   IF r THEN lfa = ncm.lfSmCaptionFont
   FUNCTION = r
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxGetSmallCaptionFontW (BYREF lfw AS LOGFONTW) AS LONG
   LOCAL r AS LONG
   LOCAL ncm AS NONCLIENTMETRICSW
   IF VARPTR(lfw) = 0 THEN EXIT FUNCTION
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   r = SystemParametersInfoW(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0)
   IF r THEN lfw = ncm.lfSmCaptionFont
   FUNCTION = r
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxGetSmallCaptionFont = AfxGetSmallCaptionFontW
#ELSE
   MACRO AfxGetSmallCaptionFont = AfxGetSmallCaptionFontA
#ENDIF

' ========================================================================================
' Retrieves the name of the small caption font.
' ========================================================================================
FUNCTION AfxGetSmallCaptionFontNameA () AS STRING
   LOCAL ncm AS NONCLIENTMETRICSA
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 344 ELSE ncm.cbSize = 340
   IF SystemParametersInfoA(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) THEN FUNCTION = ncm.lfSmCaptionFont.lfFaceName
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxGetSmallCaptionFontNameW () AS WSTRING
   LOCAL ncm AS NONCLIENTMETRICSW
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   IF SystemParametersInfoW(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) THEN FUNCTION = ncm.lfSmCaptionFont.lfFaceName
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxGetSmallCaptionFontName = AfxGetSmallCaptionFontNameW
#ELSE
   MACRO AfxGetSmallCaptionFontName = AfxGetSmallCaptionFontNameA
#ENDIF

' ========================================================================================
' Retrieves the height of the small caption font.
' ========================================================================================
FUNCTION AfxGetSmallCaptionFontHeightA () AS LONG
   LOCAL ncm AS NONCLIENTMETRICSA
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 344 ELSE ncm.cbSize = 340
   IF SystemParametersInfoA(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) THEN FUNCTION = ABS(ncm.lfSmCaptionFont.lfHeight)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxGetSmallCaptionFontHeightW () AS LONG
   LOCAL ncm AS NONCLIENTMETRICSW
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   IF SystemParametersInfoW(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) THEN FUNCTION = ABS(ncm.lfSmCaptionFont.lfHeight)
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxGetSmallCaptionFontHeight = AfxGetSmallCaptionFontHeightW
#ELSE
   MACRO AfxGetSmallCaptionFontHeight = AfxGetSmallCaptionFontHeightA
#ENDIF

' ========================================================================================
' Retrieves the point size of the small caption font.
' ========================================================================================
FUNCTION AfxGetSmallCaptionFontPointSizeA () AS LONG
   LOCAL ncm AS NONCLIENTMETRICSA
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 344 ELSE ncm.cbSize = 340
   IF SystemParametersInfoA(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) = 0 THEN EXIT FUNCTION
   LOCAL hdc AS DWORD
   hdc = CreateDCA("DISPLAY", BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
   IF hdc = %NULL THEN EXIT FUNCTION
   LOCAL cyPixelsPerInch AS LONG
   cyPixelsPerInch = GetDeviceCaps(hdc, %LOGPIXELSY)
   DeleteDC hdc
   LOCAL nPointSize AS LONG
   nPointSize = MulDiv(ncm.lfSmCaptionFont.lfHeight, 72, cyPixelsPerInch)
   IF nPointSize < 0 THEN nPointSize = -nPointSize
   FUNCTION = nPointSize
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxGetSmallCaptionFontPointSizeW () AS LONG
   LOCAL ncm AS NONCLIENTMETRICSW
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   IF SystemParametersInfoW(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) = 0 THEN EXIT FUNCTION
   LOCAL hdc AS DWORD
   hdc = CreateDCW("DISPLAY", BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
   IF hdc = %NULL THEN EXIT FUNCTION
   LOCAL cyPixelsPerInch AS LONG
   cyPixelsPerInch = GetDeviceCaps(hdc, %LOGPIXELSY)
   DeleteDC hdc
   LOCAL nPointSize AS LONG
   nPointSize = MulDiv(ncm.lfSmCaptionFont.lfHeight, 72, cyPixelsPerInch)
   IF nPointSize < 0 THEN nPointSize = -nPointSize
   FUNCTION = nPointSize
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxGetSmallCaptionFontPointSize = AfxGetSmallCaptionFontPointSizeW
#ELSE
   MACRO AfxGetSmallCaptionFontPointSize = AfxGetSmallCaptionFontPointSizeA
#ENDIF

' ========================================================================================
' Retrieves information about the font used in menu bars.
' ========================================================================================
FUNCTION AfxGetMenuFontA (BYREF lfa AS LOGFONTA) AS LONG
   LOCAL r AS LONG
   LOCAL ncm AS NONCLIENTMETRICSA
   IF VARPTR(lfa) = 0 THEN EXIT FUNCTION
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 344 ELSE ncm.cbSize = 340
   r = SystemParametersInfoA(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0)
   IF r THEN lfa = ncm.lfMenuFont
   FUNCTION = r
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxGetMenuFontW (BYREF lfw AS LOGFONTW) AS LONG
   LOCAL r AS LONG
   LOCAL ncm AS NONCLIENTMETRICSW
   IF VARPTR(lfw) = 0 THEN EXIT FUNCTION
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   r = SystemParametersInfoW(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0)
   IF r THEN lfw = ncm.lfMenuFont
   FUNCTION = r
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxGetMenuFont = AfxGetMenuFontW
#ELSE
   MACRO AfxGetMenuFont = AfxGetMenuFontA
#ENDIF

' ========================================================================================
' Retrieves the name of the menu font.
' ========================================================================================
FUNCTION AfxGetMenuFontNameA () AS STRING
   LOCAL ncm AS NONCLIENTMETRICSA
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 344 ELSE ncm.cbSize = 340
   IF SystemParametersInfoA(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) THEN FUNCTION = ncm.lfMenuFont.lfFaceName
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxGetMenuFontNameW () AS WSTRING
   LOCAL ncm AS NONCLIENTMETRICSW
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   IF SystemParametersInfoW(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) THEN FUNCTION = ncm.lfMenuFont.lfFaceName
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxGetMenuFontName = AfxGetMenuFontNameW
#ELSE
   MACRO AfxGetMenuFontName = AfxGetMenuFontNameA
#ENDIF

' ========================================================================================
' Retrieves the height of the menu font.
' ========================================================================================
FUNCTION AfxGetMenuFontHeightA () AS LONG
   LOCAL ncm AS NONCLIENTMETRICSA
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 344 ELSE ncm.cbSize = 340
   IF SystemParametersInfoA(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) THEN FUNCTION = ABS(ncm.lfMenuFont.lfHeight)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxGetMenuFontHeightW () AS LONG
   LOCAL ncm AS NONCLIENTMETRICSW
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   IF SystemParametersInfoW(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) THEN FUNCTION = ABS(ncm.lfMenuFont.lfHeight)
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxGetMenuFontHeight = AfxGetMenuFontHeightW
#ELSE
   MACRO AfxGetMenuFontHeight = AfxGetMenuFontHeightA
#ENDIF

' ========================================================================================
' Retrieves the point size of the menu font.
' ========================================================================================
FUNCTION AfxGetMenuFontPointSizeA () AS LONG
   LOCAL ncm AS NONCLIENTMETRICSA
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 344 ELSE ncm.cbSize = 340
   IF SystemParametersInfoA(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) = 0 THEN EXIT FUNCTION
   LOCAL hdc AS DWORD
   hdc = CreateDCA("DISPLAY", BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
   IF hdc = %NULL THEN EXIT FUNCTION
   LOCAL cyPixelsPerInch AS LONG
   cyPixelsPerInch = GetDeviceCaps(hdc, %LOGPIXELSY)
   DeleteDC hdc
   LOCAL nPointSize AS LONG
   nPointSize = MulDiv(ncm.lfMenuFont.lfHeight, 72, cyPixelsPerInch)
   IF nPointSize < 0 THEN nPointSize = -nPointSize
   FUNCTION = nPointSize
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxGetMenuFontPointSizeW () AS LONG
   LOCAL ncm AS NONCLIENTMETRICSW
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   IF SystemParametersInfoW(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) = 0 THEN EXIT FUNCTION
   LOCAL hdc AS DWORD
   hdc = CreateDCW("DISPLAY", BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
   IF hdc = %NULL THEN EXIT FUNCTION
   LOCAL cyPixelsPerInch AS LONG
   cyPixelsPerInch = GetDeviceCaps(hdc, %LOGPIXELSY)
   DeleteDC hdc
   LOCAL nPointSize AS LONG
   nPointSize = MulDiv(ncm.lfMenuFont.lfHeight, 72, cyPixelsPerInch)
   IF nPointSize < 0 THEN nPointSize = -nPointSize
   FUNCTION = nPointSize
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxGetMenuFontPointSize = AfxGetMenuFontPointSizeW
#ELSE
   MACRO AfxGetMenuFontPointSize = AfxGetMenuFontPointSizeA
#ENDIF

' ========================================================================================
' Retrieves information about the font used in status bars and tooltips.
' ========================================================================================
FUNCTION AfxGetStatusFontA (BYREF lfa AS LOGFONTA) AS LONG
   LOCAL r AS LONG
   LOCAL ncm AS NONCLIENTMETRICSA
   IF VARPTR(lfa) = 0 THEN EXIT FUNCTION
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 344 ELSE ncm.cbSize = 340
   r = SystemParametersInfoA(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0)
   IF r THEN lfa = ncm.lfStatusFont
   FUNCTION = r
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxGetStatusFontW (BYREF lfw AS LOGFONTW) AS LONG
   LOCAL r AS LONG
   LOCAL ncm AS NONCLIENTMETRICSW
   IF VARPTR(lfw) = 0 THEN EXIT FUNCTION
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   r = SystemParametersInfoW(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0)
   IF r THEN lfw = ncm.lfStatusFont
   FUNCTION = r
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxGetStatusFont = AfxGetStatusFontW
#ELSE
   MACRO AfxGetStatusFont = AfxGetStatusFontA
#ENDIF

' ========================================================================================
' Retrieves the name of the status font.
' ========================================================================================
FUNCTION AfxGetStatusFontNameA () AS STRING
   LOCAL ncm AS NONCLIENTMETRICSA
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 344 ELSE ncm.cbSize = 340
   IF SystemParametersInfoA(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) THEN FUNCTION = ncm.lfStatusFont.lfFaceName
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxGetStatusFontNameW () AS WSTRING
   LOCAL ncm AS NONCLIENTMETRICSW
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   IF SystemParametersInfoW(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) THEN FUNCTION = ncm.lfStatusFont.lfFaceName
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxGetStatusFontName = AfxGetStatusFontNameW
#ELSE
   MACRO AfxGetStatusFontName = AfxGetStatusFontNameA
#ENDIF

' ========================================================================================
' Retrieves the height of the status font.
' ========================================================================================
FUNCTION AfxGetStatusFontHeightA () AS LONG
   LOCAL ncm AS NONCLIENTMETRICSA
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 344 ELSE ncm.cbSize = 340
   IF SystemParametersInfoA(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) THEN FUNCTION = ABS(ncm.lfStatusFont.lfHeight)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxGetStatusFontHeightW () AS LONG
   LOCAL ncm AS NONCLIENTMETRICSW
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   IF SystemParametersInfoW(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) THEN FUNCTION = ABS(ncm.lfStatusFont.lfHeight)
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxGetStatusFontHeight = AfxGetStatusFontHeightW
#ELSE
   MACRO AfxGetStatusFontHeight = AfxGetStatusFontHeightA
#ENDIF

' ========================================================================================
' Retrieves the point size of the status font.
' ========================================================================================
FUNCTION AfxGetStatusFontPointSizeA () AS LONG
   LOCAL ncm AS NONCLIENTMETRICSA
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 344 ELSE ncm.cbSize = 340
   IF SystemParametersInfoA(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) = 0 THEN EXIT FUNCTION
   LOCAL hdc AS DWORD
   hdc = CreateDCA("DISPLAY", BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
   IF hdc = %NULL THEN EXIT FUNCTION
   LOCAL cyPixelsPerInch AS LONG
   cyPixelsPerInch = GetDeviceCaps(hdc, %LOGPIXELSY)
   DeleteDC hdc
   LOCAL nPointSize AS LONG
   nPointSize = MulDiv(ncm.lfStatusFont.lfHeight, 72, cyPixelsPerInch)
   IF nPointSize < 0 THEN nPointSize = -nPointSize
   FUNCTION = nPointSize
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxGetStatusFontPointSizeW () AS LONG
   LOCAL ncm AS NONCLIENTMETRICSW
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   IF SystemParametersInfoW(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) = 0 THEN EXIT FUNCTION
   LOCAL hdc AS DWORD
   hdc = CreateDCW("DISPLAY", BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
   IF hdc = %NULL THEN EXIT FUNCTION
   LOCAL cyPixelsPerInch AS LONG
   cyPixelsPerInch = GetDeviceCaps(hdc, %LOGPIXELSY)
   DeleteDC hdc
   LOCAL nPointSize AS LONG
   nPointSize = MulDiv(ncm.lfStatusFont.lfHeight, 72, cyPixelsPerInch)
   IF nPointSize < 0 THEN nPointSize = -nPointSize
   FUNCTION = nPointSize
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxGetStatusFontPointSize = AfxGetStatusFontPointSizeW
#ELSE
   MACRO AfxGetStatusFontPointSize = AfxGetStatusFontPointSizeA
#ENDIF

' ========================================================================================
' Retrieves information about the font used in message boxes.
' ========================================================================================
FUNCTION AfxGetMessageFontA (BYREF lfa AS LOGFONTA) AS LONG
   LOCAL r AS LONG
   LOCAL ncm AS NONCLIENTMETRICSA
   IF VARPTR(lfa) = 0 THEN EXIT FUNCTION
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 344 ELSE ncm.cbSize = 340
   r = SystemParametersInfoA(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0)
   IF r THEN lfa = ncm.lfMessageFont
   FUNCTION = r
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxGetMessageFontW (BYREF lfw AS LOGFONTW) AS LONG
   LOCAL r AS LONG
   LOCAL ncm AS NONCLIENTMETRICSW
   IF VARPTR(lfw) = 0 THEN EXIT FUNCTION
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   r = SystemParametersInfoW(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0)
   IF r THEN lfw = ncm.lfMessageFont
   FUNCTION = r
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxGetMessageFont = AfxGetMessageFontW
#ELSE
   MACRO AfxGetMessageFont = AfxGetMessageFontA
#ENDIF

' ========================================================================================
' Retrieves the name of the messages font.
' ========================================================================================
FUNCTION AfxGetMessageFontNameA () AS STRING
   LOCAL ncm AS NONCLIENTMETRICSA
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 344 ELSE ncm.cbSize = 340
   IF SystemParametersInfoA(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) THEN FUNCTION = ncm.lfMessageFont.lfFaceName
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxGetMessageFontNameW () AS WSTRING
   LOCAL ncm AS NONCLIENTMETRICSW
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   IF SystemParametersInfoW(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) THEN FUNCTION = ncm.lfMessageFont.lfFaceName
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxGetMessageFontName = AfxGetMessageFontNameW
#ELSE
   MACRO AfxGetMessageFontName = AfxGetMessageFontNameA
#ENDIF

' ========================================================================================
' Retrieves the height of the messages font.
' ========================================================================================
FUNCTION AfxGetMessageFontHeightA () AS LONG
   LOCAL ncm AS NONCLIENTMETRICSA
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 344 ELSE ncm.cbSize = 340
   IF SystemParametersInfoA(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) THEN FUNCTION = ABS(ncm.lfMessageFont.lfHeight)
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxGetMessageFontHeightW () AS LONG
   LOCAL ncm AS NONCLIENTMETRICSW
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   IF SystemParametersInfoW(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) THEN FUNCTION = ABS(ncm.lfMessageFont.lfHeight)
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxGetMessageFontHeight = AfxGetMessageFontHeightW
#ELSE
   MACRO AfxGetMessageFontHeight = AfxGetMessageFontHeightA
#ENDIF

' ========================================================================================
' Retrieves the point size of the messages font.
' ========================================================================================
FUNCTION AfxGetMessageFontPointSizeA () AS LONG
   LOCAL ncm AS NONCLIENTMETRICSA
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 344 ELSE ncm.cbSize = 340
   IF SystemParametersInfoA(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) = 0 THEN EXIT FUNCTION
   LOCAL hdc AS DWORD
   hdc = CreateDCA("DISPLAY", BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
   IF hdc = %NULL THEN EXIT FUNCTION
   LOCAL cyPixelsPerInch AS LONG
   cyPixelsPerInch = GetDeviceCaps(hdc, %LOGPIXELSY)
   DeleteDC hdc
   LOCAL nPointSize AS LONG
   nPointSize = MulDiv(ncm.lfMessageFont.lfHeight, 72, cyPixelsPerInch)
   IF nPointSize < 0 THEN nPointSize = -nPointSize
   FUNCTION = nPointSize
END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxGetMessageFontPointSizeW () AS LONG
   LOCAL ncm AS NONCLIENTMETRICSW
   IF AfxGetWindowsVersion => 6 THEN ncm.cbSize = 504 ELSE ncm.cbSize = 500
   IF SystemParametersInfoW(%SPI_GETNONCLIENTMETRICS, SIZEOF(ncm), ncm, 0) = 0 THEN EXIT FUNCTION
   LOCAL hdc AS DWORD
   hdc = CreateDCW("DISPLAY", BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
   IF hdc = %NULL THEN EXIT FUNCTION
   LOCAL cyPixelsPerInch AS LONG
   cyPixelsPerInch = GetDeviceCaps(hdc, %LOGPIXELSY)
   DeleteDC hdc
   LOCAL nPointSize AS LONG
   nPointSize = MulDiv(ncm.lfMessageFont.lfHeight, 72, cyPixelsPerInch)
   IF nPointSize < 0 THEN nPointSize = -nPointSize
   FUNCTION = nPointSize
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxGetMessageFontPointSize = AfxGetMessageFontPointSizeW
#ELSE
   MACRO AfxGetMessageFontPointSize = AfxGetMessageFontPointSizeA
#ENDIF

' ========================================================================================
' The SHELL function in PowerBASIC is used to execute an application. Often, it is useful
' to get a Window handle (hWnd) to the application so you can manipulate it using the
' Windows APIs. However, the SHELL function returns an Instance handle (hInstance), which
' is different from a Window handle. This function returns a Window handle based on an
' Instance handle. See: http://support.microsoft.com/kb/242308/en-us
' ========================================================================================
FUNCTION AfxGetWindowHandleFromhInstance (BYVAL hInstance AS DWORD) AS DWORD

   LOCAL hwndTemp AS DWORD
   LOCAL idProc AS DWORD

   ' // Grab the first window handle that Windows finds:
   hwndTemp = FindWindowW("", "")

   ' // Loop until you find a match or there are no more window handles:
   DO
      ' // Check if no parent for this window
      IF GetParent(hwndTemp) = 0 Then
         ' // Get PID for this hwnd
         GetWindowThreadProcessId(hwndTemp, idProc)
         ' // Check for PID match
         IF hInstance = idProc THEN
            ' // Return found handle
            FUNCTION = hwndTemp
            ' // Exit search loop
            EXIT DO
         END IF
      END IF
      ' // Get the next window handle
      hwndTemp = GetWindow(hwndTemp, %GW_HWNDNEXT)
      IF hwndTemp = %NULL THEN EXIT DO
   LOOP

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the path of the executable file given its instance handle.
' ========================================================================================
FUNCTION AfxGetPathFromhInstance (BYVAL hInst AS DWORD) AS WSTRING
   LOCAL hProcess AS DWORD, wszPath AS WSTRINGZ * %MAX_PATH
   IF hInst = 0 THEN EXIT FUNCTION
   hProcess = OpenProcess(%PROCESS_QUERY_INFORMATION OR %PROCESS_VM_READ, %FALSE, hInst)
   IF hProcess = 0 THEN EXIT FUNCTION
   GetModuleFileNameExW(hProcess, %NULL, wszPath, SIZEOF(wszPath))
   CloseHandle(hProcess)
   FUNCTION = wszPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the path of the executable file that created the specified window.
' ========================================================================================
FUNCTION AfxGetPathFromWindowHandle (BYVAL hwnd AS DWORD) AS WSTRING
   LOCAL idProc, hProcess AS DWORD, wszPath AS WSTRINGZ * %MAX_PATH
   GetWindowThreadProcessId(hwnd, idProc)
   IF idProc = 0 THEN EXIT FUNCTION
   hProcess = OpenProcess(%PROCESS_QUERY_INFORMATION OR %PROCESS_VM_READ, %FALSE, idProc)
   IF hProcess = 0 THEN EXIT FUNCTION
   GetModuleFileNameExW(hProcess, %NULL, wszPath, SIZEOF(wszPath))
   CloseHandle(hProcess)
   FUNCTION = wszPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Modifies the point size of the font of a window or control.
' Parameters:
' - hwnd = Handle of the window or control.
' - Percent = The base is 100. To increase the font a 20% pass 120; to reduce it a 20% pass 80%.
' Return Value: 1 = success; 0 = failure.
' ========================================================================================
FUNCTION AfxFontModifyPointSize (BYVAL hwnd AS DWORD, BYVAL Percent AS SINGLE) AS LONG

   LOCAL hCurFont AS DWORD
   LOCAL hNewFont AS DWORD
   LOCAL lf AS LOGFONT
   LOCAL lPointSize AS LONG

   IF hwnd = 0 OR Percent = 0 THEN EXIT FUNCTION

   ' // Get the handle of the font used by the header
   hCurFont = SendMessage(hwnd, %WM_GETFONT, 0, 0)
   IF hCurFont = 0 THEN EXIT FUNCTION

   ' // Get the LOGFONT structure
   IF GetObject(hCurFont, SIZEOF(lf), lf) = 0 THEN EXIT FUNCTION

   ' // Change the point size
   lPointSize = AfxGetFontPointSize(lf.lfHeight)
   lPointSize = lPointSize * (Percent / 100)
   lf.lfHeight = -MulDiv(lPointSize, AfxGetLogPixelsY, 72)

   ' // Create a new font
   hNewFont = CreateFontIndirect(lf)
   IF hNewFont = 0 THEN EXIT FUNCTION

   ' // Select the new font and delete the old one
   DIM hDC AS DWORD
   hDC = GetDC(hwnd)
   DeleteObject(SelectObject(hDC, hNewFont))
   ReleaseDC(hwnd, hDC)
   SendMessage hwnd, %WM_SETFONT, hNewFont, %TRUE

   FUNCTION = 1

END FUNCTION
' ========================================================================================

' ========================================================================================
' Modifies the face name of the font of a window or control.
' Parameters:
' - hwnd = Handle of the window or control.
' - strNewFaceName = The new face name of the font
' Return Value: 1 = success; 0 = failure.
' ========================================================================================
#IF NOT %DEF(%UNICODE)
FUNCTION AfxFontModifyFontFaceName (BYVAL hwnd AS DWORD, BYVAL strNewFaceName AS STRING) AS LONG
#ELSE
FUNCTION AfxFontModifyFontFaceName (BYVAL hwnd AS DWORD, BYVAL strNewFaceName AS WSTRING) AS LONG
#ENDIF

   LOCAL hCurFont AS DWORD
   LOCAL hNewFont AS DWORD
   LOCAL lf AS LOGFONT

   IF hwnd = 0 OR strNewFaceName = "" THEN EXIT FUNCTION

   ' // Get the handle of the font used by the header
   hCurFont = SendMessage(hwnd, %WM_GETFONT, 0, 0)
   IF hCurFont = 0 THEN EXIT FUNCTION

   ' // Get the LOGFONT structure
   IF GetObject(hCurFont, SIZEOF(lf), lf) = 0 THEN EXIT FUNCTION

   ' // Change the face name
   lf.lfFaceName = strNewFaceName

   ' // Create a new font
   hNewFont = CreateFontIndirect(lf)
   IF hNewFont = 0 THEN EXIT FUNCTION

   ' // Select the new font and delete the old one
   DIM hDC AS DWORD
   hDC = GetDC(hwnd)
   DeleteObject(SelectObject(hDC, hNewFont))
   ReleaseDC(hwnd, hDC)
   SendMessage hwnd, %WM_SETFONT, hNewFont, %TRUE

   FUNCTION = 1

END FUNCTION
' ========================================================================================

' ========================================================================================
' Modifies the weight of the font of a window or control.
' Parameters:
' - hwnd = Handle of the window or control.
' - nWeight = The weight of the font in the range 0 through 1000. For example, 400 is normal
'   and 700 is bold. If this value is zero, a default weight is used.
'   The following values are defined for convenience.
'   FW_DONTCARE   0
'   FW_THIN       100
'   FW_EXTRALIGHT 200
'   FW_ULTRALIGHT 200
'   FW_LIGHT      300
'   FW_NORMAL     400
'   FW_REGULAR    400
'   FW_MEDIUM     500
'   FW_SEMIBOLD   600
'   FW_DEMIBOLD   600
'   FW_BOLD       700
'   FW_EXTRABOLD  800
'   FW_ULTRABOLD  800
'   FW_HEAVY      900
'   FW_BLACK      900
' Return Value: 1 = success; 0 = failure.
' ========================================================================================
FUNCTION AfxFontSetWeight (BYVAL hwnd AS DWORD, BYVAL nWeight AS LONG) AS LONG

   LOCAL hCurFont AS DWORD
   LOCAL hNewFont AS DWORD
   LOCAL lf AS LOGFONT

   IF hwnd = 0 THEN EXIT FUNCTION

   ' // Get the handle of the font used by the header
   hCurFont = SendMessage(hwnd, %WM_GETFONT, 0, 0)
   IF hCurFont = 0 THEN EXIT FUNCTION

   ' // Get the LOGFONT structure
   IF GetObject(hCurFont, SIZEOF(lf), lf) = 0 THEN EXIT FUNCTION

   ' // Change the face name
   lf.lfWeight = nWeight

   ' // Create a new font
   hNewFont = CreateFontIndirect(lf)
   IF hNewFont = 0 THEN EXIT FUNCTION

   ' // Select the new font and delete the old one
   DIM hDC AS DWORD
   hDC = GetDC(hwnd)
   DeleteObject(SelectObject(hDC, hNewFont))
   ReleaseDC(hwnd, hDC)
   SendMessage hwnd, %WM_SETFONT, hNewFont, %TRUE

   FUNCTION = 1

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the italic flag.
' Parameters:
' - hwnd = Handle of the window or control.
' - bFlag = %TRUE or %FALSE
' Return Value: 1 = success; 0 = failure.
' ========================================================================================
FUNCTION AfxFontSetItalic (BYVAL hwnd AS DWORD, BYVAL bFlag AS BYTE) AS LONG

   LOCAL hCurFont AS DWORD
   LOCAL hNewFont AS DWORD
   LOCAL lf AS LOGFONT

   IF hwnd = 0 THEN EXIT FUNCTION
   IF bFlag <> 0 THEN bFlag = 1

   ' // Get the handle of the font used by the header
   hCurFont = SendMessage(hwnd, %WM_GETFONT, 0, 0)
   IF hCurFont = 0 THEN EXIT FUNCTION

   ' // Get the LOGFONT structure
   IF GetObject(hCurFont, SIZEOF(lf), lf) = 0 THEN EXIT FUNCTION

   ' // Change the flag
   lf.lfItalic = bFlag

   ' // Create a new font
   hNewFont = CreateFontIndirect(lf)
   IF hNewFont = 0 THEN EXIT FUNCTION

   ' // Select the new font and delete the old one
   DIM hDC AS DWORD
   hDC = GetDC(hwnd)
   DeleteObject(SelectObject(hDC, hNewFont))
   ReleaseDC(hwnd, hDC)
   SendMessage hwnd, %WM_SETFONT, hNewFont, %TRUE

   FUNCTION = 1

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the underline flag.
' Parameters:
' - hwnd = Handle of the window or control.
' - bFlag = %TRUE or %FALSE
' Return Value: 1 = success; 0 = failure.
' ========================================================================================
FUNCTION AfxFontSetUnderline (BYVAL hwnd AS DWORD, BYVAL bFlag AS BYTE) AS LONG

   LOCAL hCurFont AS DWORD
   LOCAL hNewFont AS DWORD
   LOCAL lf AS LOGFONT

   IF hwnd = 0 THEN EXIT FUNCTION
   IF bFlag <> 0 THEN bFlag = 1

   ' // Get the handle of the font used by the header
   hCurFont = SendMessage(hwnd, %WM_GETFONT, 0, 0)
   IF hCurFont = 0 THEN EXIT FUNCTION

   ' // Get the LOGFONT structure
   IF GetObject(hCurFont, SIZEOF(lf), lf) = 0 THEN EXIT FUNCTION

   ' // Change the flag
   lf.lfUnderline = bFlag

   ' // Create a new font
   hNewFont = CreateFontIndirect(lf)
   IF hNewFont = 0 THEN EXIT FUNCTION

   ' // Select the new font and delete the old one
   DIM hDC AS DWORD
   hDC = GetDC(hwnd)
   DeleteObject(SelectObject(hDC, hNewFont))
   ReleaseDC(hwnd, hDC)
   SendMessage hwnd, %WM_SETFONT, hNewFont, %TRUE

   FUNCTION = 1

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the strike out flag.
' Parameters:
' - hwnd = Handle of the window or control.
' - bFlag = %TRUE or %FALSE
' Return Value: 1 = success; 0 = failure.
' ========================================================================================
FUNCTION AfxFontSetStrikeOut (BYVAL hwnd AS DWORD, BYVAL bFlag AS BYTE) AS LONG

   LOCAL hCurFont AS DWORD
   LOCAL hNewFont AS DWORD
   LOCAL lf AS LOGFONT

   IF hwnd = 0 THEN EXIT FUNCTION
   IF bFlag <> 0 THEN bFlag = 1

   ' // Get the handle of the font used by the header
   hCurFont = SendMessage(hwnd, %WM_GETFONT, 0, 0)
   IF hCurFont = 0 THEN EXIT FUNCTION

   ' // Get the LOGFONT structure
   IF GetObject(hCurFont, SIZEOF(lf), lf) = 0 THEN EXIT FUNCTION

   ' // Change the flag
   lf.lfStrikeOut = bFlag

   ' // Create a new font
   hNewFont = CreateFontIndirect(lf)
   IF hNewFont = 0 THEN EXIT FUNCTION

   ' // Select the new font and delete the old one
   DIM hDC AS DWORD
   hDC = GetDC(hwnd)
   DeleteObject(SelectObject(hDC, hNewFont))
   ReleaseDC(hwnd, hDC)
   SendMessage hwnd, %WM_SETFONT, hNewFont, %TRUE

   FUNCTION = 1

END FUNCTION
' ========================================================================================

' ========================================================================================
' Changes the charset.
' Parameters:
' - hwnd = Handle of the window or control.
' - bCharset = The following values are predefined.
'    ANSI_CHARSET
'    BALTIC_CHARSET
'    CHINESEBIG5_CHARSET
'    DEFAULT_CHARSET
'    EASTEUROPE_CHARSET
'    GB2312_CHARSET
'    GREEK_CHARSET
'    HANGUL_CHARSET
'    MAC_CHARSET
'    OEM_CHARSET
'    RUSSIAN_CHARSET
'    SHIFTJIS_CHARSET
'    SYMBOL_CHARSET
'    TURKISH_CHARSET
'    VIETNAMESE_CHARSET

' Korean language edition of Windows:

'    JOHAB_CHARSET

' Middle East language edition of Windows:

'    ARABIC_CHARSET
'    HEBREW_CHARSET

' Thai language edition of Windows:

'    THAI_CHARSET

' The OEM_CHARSET value specifies a character set that is operating-system dependent.

' DEFAULT_CHARSET is set to a value based on the current system locale. For example, when
' the system locale is English (United States), it is set as ANSI_CHARSET.

' Fonts with other character sets may exist in the operating system. If an application uses
' a font with an unknown character set, it should not attempt to translate or interpret
' strings that are rendered with that font.

' This parameter is important in the font mapping process. To ensure consistent results,
' specify a specific character set. If you specify a typeface name in the lfFaceName member,
' make sure that the lfCharSet value matches the character set of the typeface specified in lfFaceName.

' Return Value: 1 = success; 0 = failure.
' ========================================================================================
FUNCTION AfxFontSetCharset (BYVAL hwnd AS DWORD, BYVAL bCharset AS BYTE) AS LONG

   LOCAL hCurFont AS DWORD
   LOCAL hNewFont AS DWORD
   LOCAL lf AS LOGFONT

   IF hwnd = 0 THEN EXIT FUNCTION

   ' // Get the handle of the font used by the header
   hCurFont = SendMessage(hwnd, %WM_GETFONT, 0, 0)
   IF hCurFont = 0 THEN EXIT FUNCTION

   ' // Get the LOGFONT structure
   IF GetObject(hCurFont, SIZEOF(lf), lf) = 0 THEN EXIT FUNCTION

   ' // Change the charset
   lf.lfCharset = bCharset

   ' // Create a new font
   hNewFont = CreateFontIndirect(lf)
   IF hNewFont = 0 THEN EXIT FUNCTION

   ' // Select the new font and delete the old one
   DIM hDC AS DWORD
   hDC = GetDC(hwnd)
   DeleteObject(SelectObject(hDC, hNewFont))
   ReleaseDC(hwnd, hDC)
   SendMessage hwnd, %WM_SETFONT, hNewFont, %TRUE

   FUNCTION = 1

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the token elevation type for the current process.
' Token elevation values describe the relative strength of a given token.
' A full token is a token with all groups and privileges to which the principal
' is authorized.  A limited token is one with some groups or privileges removed.
' Requires Windows Vista or superior.
' ========================================================================================
FUNCTION AfxGetTokenElevationType () AS LONG

   LOCAL hToken AS DWORD
   LOCAL elevationType AS LONG
   LOCAL dwSize AS DWORD

   IF OpenProcessToken(GetCurrentProcess, %TOKEN_QUERY, hToken) = 0 THEN EXIT FUNCTION
#IF %DEF(%USEPBDECL)
   GetTokenInformation(hToken, %TokenElevationType, BYVAL VARPTR(elevationType), 4, dwSize)
#ELSE
   GetTokenInformation(hToken, %TokenElevationType, elevationType, 4, dwSize)
#ENDIF
   CloseHandle(hToken)
   FUNCTION = elevationType

END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts point size to DIP (device independent pixel). DIP is defined as 1/96 of an
' inch and a point is 1/72 of an inch.
' ========================================================================================
FUNCTION AfxPointSizeToDip (BYVAL ptsize AS SINGLE) AS SINGLE
   FUNCTION = (ptsize/72) * 96
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the path of the specified system DLL.
' ========================================================================================
FUNCTION AfxGetDllPath (BYVAL bstrDllName AS WSTRING) AS WSTRING
   LOCAL hLib AS DWORD
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   hLib = LoadLibraryW(BYCOPY bstrDllName)
   IF hLib THEN
      GetModuleFileNameW(hLib, wszPath, SIZEOF(wszPath))
      FreeLibrary hLib
   END IF
   FUNCTION = wszPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the version of the specified system DLL.
' ========================================================================================
FUNCTION AfxGetDllVersion (BYVAL bstrDllName AS WSTRING) AS CURRENCY

   LOCAL pvsffi AS VS_FIXEDFILEINFO PTR
   LOCAL pVerInfo AS DWORD
   LOCAL dwHandle AS DWORD
   LOCAL dwVersion AS DWORD
   LOCAL cbLen AS DWORD
   LOCAL wMajor AS WORD
   LOCAL wMinor AS WORD
   cbLen = GetFileVersionInfoSize(BYCOPY bstrDllName, dwHandle)
   IF cbLen THEN
      pVerInfo = HeapAlloc(GetProcessHeap, %HEAP_ZERO_MEMORY, cbLen)
      IF pVerInfo THEN
         IF GetFileVersionInfo(BYCOPY bstrDllName, dwHandle, cbLen, BYVAL pVerInfo) THEN
            IF VerQueryValue(BYVAL pVerInfo, "\", BYVAL VARPTR(pvsffi), cbLen) THEN
               wMajor = HI(WORD, @pvsffi.dwFileVersionMS)
               wMinor = LO(WORD, @pvsffi.dwFileVersionMS)
            END IF
         END IF
         HeapFree GetProcessHeap, 0, pVerInfo
      END IF
   END IF
   FUNCTION = wMajor + wMinor / 100

END FUNCTION
' ========================================================================================

' ========================================================================================
' Checks if the specified URL exists.
' Parameters:
' - bstrUrl = URL to check.
' - vTimeout = Optional. Number of seconds to wait. The default value is -1 (infinite).
' Return value: TRUE or FALSE
' To retrieve extended error information, call GetLastError. The error code is returned as
' an HRESULT code to allow the use of OBJRESULT$ to get a localized description of it.
' ========================================================================================
FUNCTION AfxUrlExists (BYVAL bstrUrl AS WSTRING, OPTIONAL BYVAL vTimeout AS VARIANT) AS LONG

   LOCAL pWHttp AS IWinHttpRequest
   LOCAL iSucceeded AS INTEGER

   ' // Creates an instance of the HTTP service
   pWHttp = NEWCOM "WinHttp.WinHttpRequest.5.1"
   IF ISNOTHING(pWHttp) THEN
      SetLastError %E_NOINTERFACE
      EXIT FUNCTION
   END IF

   TRY
      ' // Opens an HTTP connection to an HTTP resource
      pWHttp.Open "GET", bstrUrl
      ' // Sends an HTTP request to the HTTP server
      pWHttp.Send
      ' // Wait for response
      iSucceeded = pWHttp.WaitForResponse(vTimeout)
      IF iSucceeded THEN
         ' // If it exists, pWHttp.Status returns a value of 200 and pWHttp.StatusText a value of "OK"
         ' // If it does not exist, pWHttp.Status returns a value of 404 and pWHttp.StatusText a value of "Not Found"
         IF pWHttp.Status = 200 THEN FUNCTION = %TRUE
      ELSE
         SetLastError HRESULT_FROM_WIN32(%ERROR_TIMEOUT)
      END IF
   CATCH
      SetLastError OBJRESULT
   END TRY

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the Internet Explorer version (major.minor).
' ========================================================================================
FUNCTION AfxGetInternetExplorerVersion () AS CURRENCY

   LOCAL hKey     AS DWORD
   LOCAL wszBuff  AS WSTRINGZ * 1024

   IF RegOpenKeyExW(%HKEY_LOCAL_MACHINE, "SOFTWARE\Microsoft\Internet Explorer", 0, _
                    %KEY_QUERY_VALUE, hKey) <> %ERROR_SUCCESS THEN EXIT FUNCTION
   RegQueryValueExW hKey, "Version", 0, 0, wszBuff, SIZEOF(wszBuff)
   RegCloseKey hKey
   FUNCTION = VAL(wszBuff)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Checks if simple MAPI is installed. Returns TRUE or FALSE.
' ========================================================================================
FUNCTION AfxIsSimpleMapiInstalled () AS LONG
   LOCAL dwChars AS DWORD, wszReturn AS WSTRINGZ * 260
   dwChars = GetPrivateProfileStringW("Mail", "MAPI", BYVAL %NULL, wszReturn, SIZEOF(wszReturn), "win.ini")
   IF dwChars THEN FUNCTION = VAL(wszReturn)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Rounds a numeric value to a specified number of decimal places. Uses the "round up at
' five" approach instead of "banker's rounding".
' numDigits n is an  expression specifying the number of decimal places required in the result.
' AfxRound is especially useful in cases where you have a variable in Single, Double, or
' Extended-precision, and you want to put it into a Currency variable or display it, rounded
' to a specific number of decimal places.
' Note: PowerBASIC uses the IIEE standard for rounding. It is implemented by the "banker's
' rounding" principle: if the fractional digit being rounded off is exactly five, with no
' trailing digits, the number is rounded to the nearest even number.
' Unfortunately, in the business world nobody uses banker's rounding, not even the bankers.
' In the EU, the "round up at five" approach is mandatory by law. This makes all the
' functions/statements and numeric types that use banker's rounding useless for business
' applications in the EU.
' ========================================================================================
FUNCTION AfxRound (BYVAL extValue AS EXT, BYVAL numDigits AS LONG) AS EXT
   LOCAL nMult AS LONG
   nMult = 10 ^ numDigits
   FUNCTION = FIX((nMult * extValue + (SGN(extValue)) * .5##)) / nMult
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the largest integral value that is not greater than x.
' Can be used to emulate the C floor function.
' ========================================================================================
MACRO AfxFloor(x) = INT(x)
' ========================================================================================

' ========================================================================================
' Create a copy of the current system palette.
' ========================================================================================
FUNCTION AfxGetSystemPalette () AS DWORD

   LOCAL hDC AS DWORD
   LOCAL hPal AS DWORD
   LOCAL hLogPal AS DWORD
   LOCAL tLogPal AS LOGPALETTE256

   ' // Get a DC for the desktop.
   hDC = GetDC(BYVAL %NULL)

   ' // Check to see if you are a running in a palette-based video mode.
   IF (GetDeviceCaps(hDC, %RASTERCAPS) AND %RC_PALETTE) <> %RC_PALETTE THEN
      ReleaseDC(BYVAL %NULL, hDC)
      EXIT FUNCTION
   END IF

   ' // Initialize the structure
   tLogPal.palVersion = &H300
   tLogPal.palNumEntries = 256

   ' // Copy the current system palette into the logical palette.
   GetSystemPaletteEntries(hDC, 0, 256, tLogPal.palPalEntry(0))

   ' // Create the palette.
   hPal = CreatePalette(BYVAL VARPTR(tLogPal))

   ' // Clean up.
   ReleaseDC(BYVAL %NULL, hDC)

   FUNCTION = hPal

END FUNCTION
' ========================================================================================

' ========================================================================================
' Determine if screen resolution meets minimum requirements in relative pixels.
' ========================================================================================
FUNCTION AfxIsResolutionAtLeast (BYVAL cxMin AS LONG, BYVAL cyMin AS LONG) AS LONG
   LOCAL dpiX, dpiY AS SINGLE
   AfxGetDesktopDPI(dpiX, dpiY)
   LOCAL ScaledScreenWidth AS LONG, ScaledScreenHeight AS LONG
   ScaledScreenWidth = MulDiv(GetSystemMetrics(%SM_CXSCREEN), 96, dpiX)
   ScaledScreenHeight = MulDiv(GetSystemMetrics(%SM_CYSCREEN), 96, dpiY)
   FUNCTION = ((ScaledScreenWidth => cxMin) AND (ScaledScreenHeight => cyMin))
END FUNCTION
' ========================================================================================
