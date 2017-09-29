' ########################################################################################
' Microsoft Windows
' File: MDI32.inc
' Contents: Multiple Document Interface (MDI) Encapsulation for PowerBASIC
' Copyright (c) 2011 José Roca
' Portions Copyright (c) PowerBASIC, Inc.
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MDI32_INC = 1

#INCLUDE ONCE "windows.inc"

' ========================================================================================
' Retrieves the handle to the active MDI child window.
' ========================================================================================
FUNCTION MdiGetActive (BYVAL hClient AS DWORD) AS DWORD
   FUNCTION = SendMessage(hClient, %WM_MDIGETACTIVE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the handle to the active MDI child window.
' lpMaximized = The maximized state. If this parameter is not NULL, it is a pointer to a
' value that indicates the maximized state of the MDI child window. If the value is TRUE,
' the window is maximized; a value of FALSE indicates that it is not. If this parameter is
' NULL, the parameter is ignored.
' ========================================================================================
FUNCTION MdiGetActiveMax (BYVAL hClient AS DWORD, BYREF lpMaximized AS DWORD) AS DWORD
   FUNCTION = SendMessage(hClient, %WM_MDIGETACTIVE, 0, BYVAL VARPTR(lpMaximized))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Arranges all the child windows in a cascade format.
' ========================================================================================
FUNCTION MdiCascade (BYVAL hClient AS DWORD, OPTIONAL BYVAL dwFlags AS DWORD) AS LONG
   FUNCTION = SendMessage(hClient, %WM_MDICASCADE, dwFlags, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Arranges all of the MDI child windows in a tile format.
' ========================================================================================
FUNCTION MdiTile (BYVAL hClient AS DWORD, BYVAL dwFlags AS DWORD) AS LONG
   FUNCTION = SendMessage(hClient, %WM_MDITILE, dwFlags, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Arranges all of the MDI child windows in a tile horizontal format.
' ========================================================================================
FUNCTION MdiTileHorizontal (BYVAL hClient AS DWORD) AS LONG
   FUNCTION = SendMessage(hClient, %WM_MDITILE, %MDITILE_HORIZONTAL, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Arranges all of its MDI child windows in a tile vertical format.
' ========================================================================================
FUNCTION MdiTileVertical (BYVAL hClient AS DWORD) AS LONG
   FUNCTION = SendMessage(hClient, %WM_MDITILE, %MDITILE_VERTICAL, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Arranges all minimized MDI child windows. It does not affect child windows that are not minimized.
' ========================================================================================
SUB MdiIconArrange (BYVAL hClient AS DWORD)
   SendMessage hClient, %WM_MDIICONARRANGE, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Activates a different MDI child window.
' ========================================================================================
FUNCTION MdiActivate (BYVAL hClient AS DWORD, BYVAL hWnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hClient, %WM_MDIACTIVATE, hWnd, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Closes a MDI child window.
' ========================================================================================
SUB MdiDestroy (BYVAL hClient AS DWORD, BYVAL hWnd AS DWORD)
   SendMessage(hClient, %WM_MDIDESTROY, hWnd, 0)
END SUB
' ========================================================================================

' ========================================================================================
' Maximizes an MDI child window. The system resizes the child window to make its client
' area fill the client window. The system places the child window's window menu icon in
' the rightmost position of the frame window's menu bar, and places the child window's
' restore icon in the leftmost position. The system also appends the title bar text of
' the child window to that of the frame window.
' ========================================================================================
SUB MdiMaximize (BYVAL hClient AS DWORD, BYVAL hWnd AS DWORD)
   SendMessage(hClient, %WM_MDIMAXIMIZE, hWnd, 0)
END SUB
' ========================================================================================

' ========================================================================================
' Activates the next or previous child window.
' Note: The optional fNext parameter is for compatibility with the powerBASIC include
' files, that has not a separate previous function.
' ========================================================================================
SUB MdiNext (BYVAL hClient AS DWORD, BYVAL hWnd AS DWORD, OPTIONAL BYVAL fNext AS LONG)
   SendMessage(hClient, %WM_MDINEXT, hWnd, fNext)
END SUB
' ========================================================================================

' ========================================================================================
' Activates the previous child window.
' ========================================================================================
SUB MdiPrevious (BYVAL hClient AS DWORD, BYVAL hWnd AS DWORD)
   SendMessage(hClient, %WM_MDINEXT, hWnd, %TRUE)
END SUB
' ========================================================================================

' ========================================================================================
' Restores an MDI child window from maximized or minimized size.
' ========================================================================================
SUB MdiRestore (BYVAL hClient AS DWORD, BYVAL hWnd AS DWORD)
   SendMessage(hClient, %WM_MDIRESTORE, hWnd, 0)
END SUB
' ========================================================================================

' ========================================================================================
' The CreateMdiChild function is a PowerBASIC addition, rather than something
' found in the Windows API headers.
' ========================================================================================
#IF %DEF(%UNICODE)
FUNCTION CreateMdiChildW (BYVAL strWndClass AS WSTRING, BYVAL hClient AS DWORD, _
   BYVAL strTitle AS WSTRING, BYVAL dwStyle AS DWORD) AS DWORD
#ELSE
FUNCTION CreateMdiChildA (BYVAL strWndClass AS STRING, BYVAL hClient AS DWORD, _
   BYVAL strTitle AS STRING, BYVAL dwStyle AS DWORD) AS DWORD
#ENDIF

   LOCAL mdi AS MDICREATESTRUCT
   LOCAL dwResult AS DWORD

   IF IsZoomed(MdiGetActive(hClient)) THEN
      dwStyle = dwStyle OR %WS_MAXIMIZE
   END IF

   IF LO(BYTE, GetVersion) < 4 THEN
      mdi.szClass = STRPTR(strWndClass)
      mdi.szTitle = STRPTR(strTitle)
      mdi.hOwner  = GetWindowLong(hClient, %GWL_HINSTANCE)
      mdi.x       = %CW_USEDEFAULT
      mdi.y       = %CW_USEDEFAULT
      mdi.cx      = %CW_USEDEFAULT
      mdi.cy      = %CW_USEDEFAULT
      mdi.Style   = dwStyle
      dwResult = SendMessage(hClient, %WM_MDICREATE, 0, VARPTR(mdi))
   ELSE
      dwResult = CreateWindowEx(%WS_EX_MDICHILD OR %WS_EX_CLIENTEDGE, _
                                BYCOPY strWndClass, _
                                BYCOPY strTitle, _
                                dwStyle, _
                                %CW_USEDEFAULT, _
                                %CW_USEDEFAULT, _
                                %CW_USEDEFAULT, _
                                %CW_USEDEFAULT, _
                                hClient, _
                                %NULL, _
                                GetWindowLong(hClient, %GWL_HINSTANCE), _
                                BYVAL %NULL)
   END IF

   FUNCTION = dwResult

END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO CreateMdiChild = CreateMdiChildW
#ELSE
   MACRO CreateMdiChild = CreateMdiChildA
#ENDIF
