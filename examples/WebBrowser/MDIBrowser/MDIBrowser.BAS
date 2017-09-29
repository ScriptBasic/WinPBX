' ########################################################################################
' Microsoft Windows
' File: MDIBrowser.bas
' Contents: MDI web browser demo.
' Compilers: PBWIN 10.02+, PBCC 6.02+
' Headers: Windows API headers III
' Copyright (c) 2011-2012 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS"  WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#COMPILE EXE
#DIM ALL

' // Equates for conditional compilation
%UNICODE = 1                   ' // Use Unicode
%USEMDI = 1                    ' // Use MDI
%USEWEBBROWSER = 1             ' // Use WebBrowser control

' // Include files for external files
#INCLUDE ONCE "CWindow.inc"         ' // CWindow class
#INCLUDE ONCE "ShObjIdl.inc"        ' // Shell objects
#INCLUDE ONCE "CAfxImageList.inc"   ' // CImageList class
#INCLUDE ONCE "ToolbarCtrl.inc"     ' // Toolbar wrappers
#INCLUDE ONCE "RebarCtrl.inc"       ' // Rebar wrappers
#INCLUDE ONCE "StatusbarCtrl.inc"   ' // Statusbar wrappers

' // Resource file
#RESOURCE RES, ".\Resources\MDIBrowser.res"

' // Image list - icon identifiers
ENUM ICON_IDS SINGULAR
   IDI_INTERNET32 = 100
   IDI_INTERNET
   IDI_BACK
   IDI_FORWARD
   IDI_NEW
   IDI_FIND
   IDI_PRINTPREV
   IDI_PAGESETUP
   IDI_PRINT
   IDI_PROPERTIES
   IDI_SAVE
   IDI_REFRESH
   IDI_STOP
   IDI_ZOOMIN
   IDI_ZOOMOUT
   IDI_EXIT
END ENUM

' // Control identifiers
ENUM CONTROL_IDS SINGULAR
   IDC_STATUSBAR = 1001
   IDC_REBAR
   IDC_IEWB
   IDC_TOOLBAR
   IDC_EDITURL
   IDC_GOBTN
   IDC_TABMDI
END ENUM

' // Menu identifiers
ENUM MENU_IDS SINGULAR
   IDM_NEW = 3001   ' // New file
   IDM_SAVEAS       ' // Save file as...
   IDM_EXIT         ' // Exit
   IDM_TILEH        ' // Tile hosizontal
   IDM_TILEV        ' // Tile vertical
   IDM_CASCADE      ' // Cascade
   IDM_ARRANGE      ' // Arrange icons
   IDM_CLOSE        ' // Close
   IDM_CLOSEALL     ' // Close all
END ENUM

' // Command identifiers
ENUM COMMAND_IDS SINGULAR
   ID_GOBACK = 28000
   ID_FORWARD
   ID_NEW
   ID_FIND
   ID_PRINTPREVIEW
   ID_PRINT
   ID_PROPERTIES
   ID_FILE_SAVE
   ID_PAGESETUP
   ID_REFRESH
   ID_STOP
   ID_ZOOMIN
   ID_ZOOMOUT
   ID_EXIT
   ID_CASCADE
   ID_TILEH
   ID_TILEV
   ID_ARRANGE
END ENUM

' ========================================================================================
' Main
' ========================================================================================
FUNCTION WinMain (BYVAL hInstance AS DWORD, BYVAL hPrevInstance AS DWORD, BYVAL lpszCmdLine AS WSTRINGZ PTR, BYVAL nCmdShow AS LONG) AS LONG

   ' // Set process DPI aware
   AfxSetProcessDPIAware

   ' // To allow cut and paste
   OleInitialize

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' // Web Browser zoom
'   IF pWindow.IsProcessDPIAware THEN pWindow.WBZoom = 100 * pWindow.rxRatio

   ' // Retrieve the size of the working area
   LOCAL rc AS RECT
   SystemParametersInfo %SPI_GETWORKAREA, 0, rc, 0

   ' // Create the window
   pWindow.CreateWindow(%NULL, "MDI Browser", 0, 0, rc.Right - rc.Left, rc.Bottom - rc.Top, 0, 0, CODEPTR(WindowProc), %TRUE)
   ' // Change the class style of the window to avoid flicker
   pWindow.ClassStyle = %CS_DBLCLKS
   ' // Set the icons
   pWindow.BigIcon = AfxLoadIconFromResource(100, hInstance)
   pWindow.SmallIcon = AfxLoadIconFromResource(101, hInstance)
   ' // Center the window
   pWindow.CenterWindow
   ' Web Browser optical zoom
'   IF pWindow.IsProcessDPIAware THEN pWindow.WBZoom = 100 * pWindow.rxRatio

   ' // Create the menu
   LOCAL hMenu AS DWORD
   hMenu = BuildMenu
   SetMenu pWindow.hwnd, hMenu

   ' // Create the rebar control
   LOCAL hRebar AS DWORD
   hRebar = CreateRebar(pWindow)

   ' // Add a status bar
   pWindow.AddStatusBar(pWindow.hwnd, %IDC_STATUSBAR, "", 0, 0, 0, 0)

   ' // Create a MDI client child window
   LOCAL hwndClient AS DWORD
   LOCAL hwindowMenu AS DWORD
   hwindowMenu = GetSubMenu(hMenu, 1)
   hwndClient = pWindow.CreateMDIWindow(101, 0, 0, 0, 0, 0, 0, hwindowMenu, CODEPTR(MDIWindowProc))

   ' // If you want to start the browser with a page loaded, you can use:
'   LOCAL hUrlTextbox AS DWORD
'   hUrlTextbox = GetDlgItem(GetDlgItem(pWindow.hwnd, %IDC_REBAR), %IDC_EDITURL)
'   SetWindowText hUrlTextbox, "http://www.powerbasic.com/support/pbforums/"  ' <-- change me
'   PostMessage pWindow.hwnd, %WM_COMMAND, %IDC_GOBTN, MAK(DWORD, %BN_CLICKED, %IDC_GOBTN)

   ' // Default message pump (you can replace it with your own)
   pWindow.DoEvents(nCmdShow)

   ' // Uninitialize the COM library
   OleUninitialize

END FUNCTION
' ========================================================================================

' ========================================================================================
' Default CWindow callback function.
' ========================================================================================
FUNCTION WindowProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL  hwndActive    AS DWORD              ' // Active window
   LOCAL  ptnmhdr       AS NMHDR PTR          ' // Information about a notification message
   LOCAL  ptttdi        AS NMTTDISPINFO PTR   ' // Tooltip notification message information
   LOCAL  hMdi          AS DWORD              ' // MDI child window handle
   LOCAL  hCtrl         AS DWORD              ' // Control handle
   LOCAL  rc            AS RECT               ' // RECT structure
   LOCAL  pIWebBrowser2 AS IWebBrowser2       ' // Instance of the WebBrowser control
   LOCAL  nZoom         AS LONG               ' // Zoom
   LOCAL  vZoom         AS VARIANT            ' // Zoom
   LOCAL  wszItem       AS WSTRINGZ * 260     ' // Tooltip item
   LOCAL  vUrl          AS VARIANT            ' // URL
   LOCAL  wszUrl        AS WSTRINGZ * %L_MAX_URL_LENGTH

   STATIC hwndClient    AS DWORD              ' // Handle of the MDI client window
   STATIC hInstance     AS DWORD              ' // Instance handle
   STATIC lpc           AS CREATESTRUCT PTR   ' // Pointer to the creation parameters
   STATIC pWindow       AS IWindow            ' // Reference to the IWindow interface

   ' // MDI client window handle
   IF hwndClient = 0 THEN hwndClient = CWindow_GetMDIClientHandle(hwnd)

   SELECT CASE uMsg

      CASE %WM_CREATE
         ' // Pointer to the creation parameters
         lpc = lParam
         ' // Instance handle
         hInstance = @lpc.hInstance
         ' // Get a reference to the IWindow interface from the CREATESTRUCT structure
         pWindow = CWindow_GetObjectFromCreateStruct(lParam)
         EXIT FUNCTION

      CASE %WM_ACTIVATE
         STATIC hwndSaveFocus AS DWORD
         IF LO(WORD, wParam) = %WA_INACTIVE THEN
            ' // Save the control with the keyboard focus
            hwndSaveFocus = GetFocus()
         ELSEIF hwndSaveFocus THEN
            ' // Set the keyboard focus to the control with
            ' // the focus when the window was deactivated
            SetFocus(hwndSaveFocus)
            hwndSaveFocus = 0
         END IF
         EXIT FUNCTION

      CASE %WM_SYSCOMMAND
         ' // Capture this message and send a WM_CLOSE message
         IF (wParam AND &HFFF0) = %SC_CLOSE THEN
            SendMessage hwnd, %WM_CLOSE, 0, 0
            EXIT FUNCTION
         END IF

      CASE %WM_COMMAND

         SELECT CASE LO(WORD, wParam)

            CASE %IDOK
               ' // If we are in the URL edit control, load the web page
               hCtrl = GetDlgItem(GetDlgItem(hwnd, %IDC_REBAR), %IDC_EDITURL)
               IF GetFocus = hCtrl THEN
                  PostMessage hwnd, %WM_COMMAND, %IDC_GOBTN, MAK(DWORD, %BN_CLICKED, %IDC_GOBTN)
                  EXIT FUNCTION
               END IF

            CASE %IDCANCEL
               ' // Close the application by sending a WM_CLOSE message
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  SendMessage hwnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF

            ' // Tile horizontally
            CASE %IDM_TILEH
               IF hwndClient THEN MdiTileHorizontal(hwndClient)
               EXIT FUNCTION

            ' // Tile vertically
            CASE %IDM_TILEV
               IF hwndClient THEN MdiTileVertical(hwndClient)
               EXIT FUNCTION

            ' // Cascade windows
            CASE %IDM_CASCADE
               IF hwndClient THEN MdiCascade(hwndClient)
               EXIT FUNCTION

            ' // Arrange icons
            CASE %IDM_ARRANGE
               IF hwndClient THEN MdiIconArrange(hwndClient)
               EXIT FUNCTION

            CASE %IDM_CLOSE
               ' // Close the active window
               IF hwndClient THEN
                  hwndActive = MdiGetActive(hwndClient)
                  IF SendMessage(hwndActive, %WM_QUERYENDSESSION, 0, 0) THEN MdiDestroy(hwndClient, hwndActive)
               END IF
               EXIT FUNCTION

            CASE %IDM_CLOSEALL
               ' // Close all the MDI child windows
               IF hwndClient THEN
                  EnumChildWindows hwndClient, CODEPTR(CWindow_CloseEnumProc), 0
               END IF
               EXIT FUNCTION

            ' // Exit the application
            CASE %ID_EXIT, %IDM_EXIT
               SendMessage hwnd, %WM_CLOSE, 0, 0
               EXIT FUNCTION

            CASE %ID_NEW, %IDM_NEW
               ' // Create a MDI child window
               hMdi = CreateMdiChild("PBFrameClass", hwndClient, "", 0)
'               hMdi = CreateMdiChild("PBFrameClass", hwndClient, "", %WS_MAXIMIZE)
               IF hMdi THEN
                  ' // Get the handle of the window that hosts the webbrowser
                  hCtrl = GetDlgItem(hMdi, %IDC_IEWB)
                  IF hCtrl THEN
                     ' // Get a reference to the WebBrowser control
                     pIWebBrowser2 = OC_GetDispatch(hCtrl)
                     IF ISOBJECT(pIWebBrowser2) THEN
                        ' // Navigate to a blank page
                        vUrl = "about:blank"
                        pIWebBrowser2.Navigate2 vUrl
                        ' // Release the object reference
                        pIWebBrowser2 = NOTHING
                     END IF
                  END IF
               END IF
               EXIT FUNCTION

            CASE %IDC_GOBTN
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  ' // Get the Url
                  hCtrl = GetDlgItem(GetDlgItem(hwnd, %IDC_REBAR), %IDC_EDITURL)
                  wszUrl = AfxGetWindowText(hCtrl)
                  IF wszUrl = "" THEN EXIT FUNCTION
                  vUrl = wszUrl
                  ' // Get the active window
                  hCtrl = GetDlgItem(MdiGetActive(hWndClient), %IDC_IEWB)
                  IF hCtrl = 0 THEN
                     ' // Create a MDI child window
                     IF hwndClient THEN
                        hMdi = CreateMdiChild("PBFrameClass", hwndClient, "", 0)
'                        hMdi = CreateMdiChild("PBFrameClass", hwndClient, "", %WS_MAXIMIZE)
                        SetWindowText hMdi, wszUrl
                        hCtrl = GetDlgItem(hMdi, %IDC_IEWB)
                     END IF
                  END IF
                  ' // Get a reference to the WebBrowser control
                  pIWebBrowser2 = OC_GetDispatch(hCtrl)
                  IF ISOBJECT(pIWebBrowser2) THEN
                     ' // Nevigate to the URL
                     pIWebBrowser2.Navigate2 vUrl
                     ' // Release the object reference
                     pIWebBrowser2 = NOTHING
                  END IF
                  EXIT FUNCTION
               END IF

            CASE %ID_GOBACK
               ' // Navigate to the previous page, if any
               hCtrl = GetDlgItem(MdiGetActive(hWndClient), %IDC_IEWB)
               IF hCtrl THEN
                  pIWebBrowser2 = OC_GetDispatch(hCtrl)
                  IF ISOBJECT(pIWebBrowser2) THEN
                     pIWebBrowser2.GoBack
                     pIWebBrowser2 = NOTHING
                  END IF
               END IF
               EXIT FUNCTION

            CASE %ID_FORWARD
               ' // Navigate to the next page, if any
               hCtrl = GetDlgItem(MdiGetActive(hWndClient), %IDC_IEWB)
               IF hCtrl THEN
                  pIWebBrowser2 = OC_GetDispatch(hCtrl)
                  IF ISOBJECT(pIWebBrowser2) THEN
                     pIWebBrowser2.GoForward
                     pIWebBrowser2 = NOTHING
                  END IF
               END IF
               EXIT FUNCTION

            CASE %ID_FIND
              ' // Warning: This code uses an undocumented command-group GUID that is
              ' // subject to change in the future. Currently it works in all versions of
              ' // Internet Explorer up to 9. See http://support.microsoft.com/?kbid=311288
               hCtrl = GetDlgItem(MdiGetActive(hWndClient), %IDC_IEWB)
               IF hCtrl THEN
                  pIWebBrowser2 = OC_GetDispatch(hCtrl)
                  IF ISOBJECT(pIWebBrowser2) THEN
                     LOCAL CGID_WebBrowser AS GUID
                     LOCAL pDisp AS IDispatch
                     LOCAL pCmdTarget AS IOleCommandTarget
                     LOCAL vIn AS VARIANT
                     LOCAL vOut AS VARIANT
                     CGID_WebBrowser = GUID$("{ED016940-BD5B-11CF-BA4E-00C04FD70816}")
                     pDisp = pIWebBrowser2.Document
                     IF ISOBJECT(pDisp) THEN
                        pCmdTarget = pDisp
                        IF ISOBJECT(pCmdTarget) THEN pCmdTarget.Exec(CGID_WebBrowser, 1, 0, vIn, vOut)
                     END IF
                     pIWebBrowser2 = NOTHING
                  END IF
               END IF
               EXIT FUNCTION

            CASE %ID_PRINTPREVIEW
               ' // Activate the print preview dialog
               hCtrl = GetDlgItem(MdiGetActive(hWndClient), %IDC_IEWB)
               IF hCtrl THEN
                  pIWebBrowser2 = OC_GetDispatch(hCtrl)
                  IF ISOBJECT(pIWebBrowser2) THEN
                     pIWebBrowser2.ExecWB %OLECMDID_PRINTPREVIEW, %OLECMDEXECOPT_PROMPTUSER
                     pIWebBrowser2 = NOTHING
                  END IF
               END IF
               EXIT FUNCTION

            CASE %ID_PAGESETUP
               ' // Activate the page setup dialog
               hCtrl = GetDlgItem(MdiGetActive(hWndClient), %IDC_IEWB)
               IF hCtrl THEN
                  pIWebBrowser2 = OC_GetDispatch(hCtrl)
                  IF ISOBJECT(pIWebBrowser2) THEN
                     pIWebBrowser2.ExecWB %OLECMDID_PAGESETUP, %OLECMDEXECOPT_PROMPTUSER
                     pIWebBrowser2 = NOTHING
                  END IF
               END IF
               EXIT FUNCTION

            CASE %ID_PRINT
               ' // Activate the print dialog
               hCtrl = GetDlgItem(MdiGetActive(hWndClient), %IDC_IEWB)
               IF hCtrl THEN
                  pIWebBrowser2 = OC_GetDispatch(hCtrl)
                  IF ISOBJECT(pIWebBrowser2) THEN
                     pIWebBrowser2.ExecWB %OLECMDID_PRINT, %OLECMDEXECOPT_PROMPTUSER
                     pIWebBrowser2 = NOTHING
                  END IF
               END IF
               EXIT FUNCTION

            CASE %ID_PROPERTIES
               ' // Activate the properties dialog
               hCtrl = GetDlgItem(MdiGetActive(hWndClient), %IDC_IEWB)
               IF hCtrl THEN
                  pIWebBrowser2 = OC_GetDispatch(hCtrl)
                  IF ISOBJECT(pIWebBrowser2) THEN
                     pIWebBrowser2.ExecWB %OLECMDID_PROPERTIES, %OLECMDEXECOPT_PROMPTUSER
                     pIWebBrowser2 = NOTHING
                  END IF
               END IF
               EXIT FUNCTION

            CASE %ID_FILE_SAVE, %IDM_SAVEAS
               ' // Activate the save file dialog
               hCtrl = GetDlgItem(MdiGetActive(hWndClient), %IDC_IEWB)
               IF hCtrl THEN
                  pIWebBrowser2 = OC_GetDispatch(hCtrl)
                  IF ISOBJECT(pIWebBrowser2) THEN
                     pIWebBrowser2.ExecWB %OLECMDID_SAVEAS, %OLECMDEXECOPT_PROMPTUSER
                     pIWebBrowser2 = NOTHING
                  END IF
               END IF
               EXIT FUNCTION

            CASE %ID_REFRESH
               ' // Reload the web page
               hCtrl = GetDlgItem(MdiGetActive(hWndClient), %IDC_IEWB)
               IF hCtrl THEN
                  pIWebBrowser2 = OC_GetDispatch(hCtrl)
                  IF ISOBJECT(pIWebBrowser2) THEN
                     pIWebBrowser2.ExecWB %OLECMDID_REFRESH, %OLECMDEXECOPT_DONTPROMPTUSER
                     pIWebBrowser2 = NOTHING
                  END IF
               END IF
               EXIT FUNCTION

            CASE %ID_STOP
               ' // Stop the loading of the page
               hCtrl = GetDlgItem(MdiGetActive(hWndClient), %IDC_IEWB)
               IF hCtrl THEN
                  pIWebBrowser2 = OC_GetDispatch(hCtrl)
                  IF ISOBJECT(pIWebBrowser2) THEN
                     pIWebBrowser2.ExecWB %OLECMDID_STOP, %OLECMDEXECOPT_DONTPROMPTUSER
                     pIWebBrowser2 = NOTHING
                  END IF
               END IF
               EXIT FUNCTION

            CASE %ID_ZOOMIN
               ' // Increases the zoom factor, in the range of 10 to 1000 (percent).
               hCtrl = GetDlgItem(MdiGetActive(hWndClient), %IDC_IEWB)
               IF hCtrl THEN
                  pIWebBrowser2 = OC_GetDispatch(hCtrl)
                  IF ISOBJECT(pIWebBrowser2) THEN
                     ' // Call the ExecWB method to get the current zoom factor
                     pIWebBrowser2.ExecWB %OLECMDID_OPTICAL_ZOOM, %OLECMDEXECOPT_DONTPROMPTUSER, BYVAL %NULL, vZoom
                     nZoom = VARIANT#(vZoom)
                     IF nZoom < 990 THEN nZoom +=10
                     ' // Call the ExecWB method to set the new zoom factor
                     vZoom = nZoom AS LONG   ' The 'AS LONG' part is important!
                     pIWebBrowser2.ExecWB %OLECMDID_OPTICAL_ZOOM, %OLECMDEXECOPT_DONTPROMPTUSER, vZoom
                     pIWebBrowser2 = NOTHING
                  END IF
               END IF
               EXIT FUNCTION

            CASE %ID_ZOOMOUT
               ' // Decreases the zoom factor, in the range of 10 to 1000 (percent).
               hCtrl = GetDlgItem(MdiGetActive(hWndClient), %IDC_IEWB)
               IF hCtrl THEN
                  pIWebBrowser2 = OC_GetDispatch(hCtrl)
                  IF ISOBJECT(pIWebBrowser2) THEN
                     ' // Call the ExecWB method to get the current font zoom scale
                     pIWebBrowser2.ExecWB %OLECMDID_OPTICAL_ZOOM, %OLECMDEXECOPT_DONTPROMPTUSER, BYVAL %NULL, vZoom
                     nZoom = VARIANT#(vZoom)
                     IF nZoom > 20 THEN nZoom -=10
                     ' // Call the ExecWB method to set the new font zoom scale
                     vZoom = nZoom AS LONG   ' The 'AS LONG' part is important!
                     pIWebBrowser2.ExecWB %OLECMDID_OPTICAL_ZOOM, %OLECMDEXECOPT_DONTPROMPTUSER, vZoom
                     pIWebBrowser2 = NOTHING
                  END IF
               END IF
               EXIT FUNCTION

            CASE %IDC_EDITURL
               SELECT CASE HI(WORD, wParam)
                  CASE %EN_SETFOCUS
                     ' // Select all the text of the edit box
                     PostMessage lParam, %EM_SETSEL, 0, -1
                     EXIT FUNCTION
               END SELECT

         END SELECT

         ' // Pass unprocessed messages to the active MDI child and then to DefFrameProc()
         hwndActive = MdiGetActive(hwndClient)
         IF IsWindow(hwndActive) THEN SendMessage hwndActive, %WM_COMMAND, wParam, lParam

      CASE %WM_NOTIFY
         ptnmhdr = lParam
         SELECT CASE @ptnmhdr.code
            ' // The height of the rebar has changed
            CASE %RBN_HEIGHTCHANGE
               ' // Get the coordinates of the client area
               GetClientRect hwnd, rc
               ' // Send a WM_SIZE message to resize the controls
               SendMessage hwnd, %WM_SIZE, %SIZE_RESTORED, MAK(LONG, rc.Right - rc.Left, rc.Bottom - rc.Top)
            ' // Toolbar tooltips
            CASE %TTN_GETDISPINFO
               ptttdi = lParam
               @ptttdi.hinst = %NULL
               SELECT CASE @ptttdi.hdr.hwndFrom
                  hCtrl = GetDlgItem(GetDlgItem(hWnd, %IDC_REBAR), %IDC_TOOLBAR)
                  CASE SendMessage(hCtrl, %TB_GETTOOLTIPS, 0, 0)
                     SELECT CASE @ptttdi.hdr.idFrom
                        CASE %ID_GOBACK
                           wszItem = "Go Back"
                           @ptttdi.lpszText = VARPTR(wszItem)
                           EXIT FUNCTION
                        CASE %ID_FORWARD
                           wszItem = "Go Forward"
                           @ptttdi.lpszText = VARPTR(wszItem)
                           EXIT FUNCTION
                        CASE %ID_NEW
                           wszItem = "New Window"
                           @ptttdi.lpszText = VARPTR(wszItem)
                           EXIT FUNCTION
                        CASE %ID_FIND
                           wszItem = "Find"
                           @ptttdi.lpszText = VARPTR(wszItem)
                           EXIT FUNCTION
                        CASE %ID_PRINTPREVIEW
                           wszItem = "Print Preview"
                           @ptttdi.lpszText = VARPTR(wszItem)
                           EXIT FUNCTION
                        CASE %ID_PAGESETUP
                           wszItem = "Page Setup"
                           @ptttdi.lpszText = VARPTR(wszItem)
                           EXIT FUNCTION
                        CASE %ID_PRINT
                           wszItem = "Print"
                           @ptttdi.lpszText = VARPTR(wszItem)
                           EXIT FUNCTION
                        CASE %ID_PROPERTIES
                           wszItem = "Properties"
                           @ptttdi.lpszText = VARPTR(wszItem)
                           EXIT FUNCTION
                        CASE %ID_FILE_SAVE
                           wszItem = "Save As"
                           @ptttdi.lpszText = VARPTR(wszItem)
                           EXIT FUNCTION
                        CASE %ID_REFRESH
                           wszItem = "Refresh"
                           @ptttdi.lpszText = VARPTR(wszItem)
                           EXIT FUNCTION
                        CASE %ID_STOP
                           wszItem = "Stop"
                           @ptttdi.lpszText = VARPTR(wszItem)
                           EXIT FUNCTION
                        CASE %ID_ZOOMIN
                           wszItem = "Zoom in"
                           @ptttdi.lpszText = VARPTR(wszItem)
                           EXIT FUNCTION
                        CASE %ID_ZOOMOUT
                           wszItem = "Zoom out"
                           @ptttdi.lpszText = VARPTR(wszItem)
                           EXIT FUNCTION
                        CASE %ID_EXIT
                           wszItem = "Exit"
                           @ptttdi.lpszText = VARPTR(wszItem)
                           EXIT FUNCTION
                     END SELECT
               END SELECT
         END SELECT

         ' // Pass unprocessed messages to the active MDI child and then to DefFrameProc()
         hwndActive = MdiGetActive(hwndClient)
         IF ISTRUE IsWindow(hwndActive) THEN SendMessage hwndActive, %WM_NOTIFY, wParam, lParam

      CASE %WM_SIZE
         ' // If the window isn't minimized, resize it
         IF wParam <> %SIZE_MINIMIZED THEN
            ' // Resize the status bar
            AfxWindowResize GetDlgItem(hwnd, %IDC_STATUSBAR), wParam, pWindow.ClientWidth, pWindow.ClientHeight
            ' // Autosize the rebar
            SendMessage GetDlgItem(hwnd, %IDC_REBAR), %WM_SIZE, wParam, lParam
            IF hwndClient THEN
               ' // Calculate the height of the rebar
               LOCAL rbh AS LONG
               rbh = pWindow.ControlHeight(GetDlgItem(hwnd, %IDC_REBAR))
               ' // Calculate the height of the status bar
               LOCAL sbh AS LONG
               sbh = pWindow.ControlHeight(GetDlgItem(hwnd, %IDC_STATUSBAR))
               ' // Resize the MDI client window
               pWindow.MoveWindow hwndClient, 0, rbh, pWindow.ClientWidth, pWindow.ClientHeight - rbh - sbh, %TRUE
            END IF
         END IF
         ' // Note: This message is not passed to DefFrameProc when space
         ' // is being reserved in the client area of the MDI frame
         ' // or controls on the MDI frame are resizeable.
         EXIT FUNCTION

      CASE %WM_CLOSE

         ' // Attempt to close all MDI child windows
         EnumChildWindows hwndClient, CODEPTR(CWindow_CloseEnumProc), 0
         ' // If child windows are still open abort closing the application
         IF GetWindow(hwndClient, %GW_CHILD) THEN EXIT FUNCTION

      CASE %WM_QUERYENDSESSION

         ' // Attempt to close all MDI child windows
         EnumChildWindows hwndClient, CODEPTR(CWindow_CloseEnumProc), 0
         ' // If child windows are still open abort closing the application
         IF GetWindow(hwndClient, %GW_CHILD) THEN EXIT FUNCTION

      CASE %WM_DESTROY
         ' // End the application
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   IF hwndClient THEN
   ' // The DefFrameProc function provides default processing for any window
   ' // messages that the window procedure of a multiple-document interface (MDI)
   ' // frame window does not process. All window messages that are not explicitly
   ' // processed by the window procedure must be passed to the DefFrameProc
   ' // function, not the DefWindowProc function.
      FUNCTION = DefFrameProc(hwnd, hwndClient, uMsg, wParam, lParam)
   ELSE
   ' // The DefWindowProc function calls the default window procedure to provide
   ' // default processing for any window messages that an application does not process.
   ' // This function ensures that every message is processed. DefWindowProc
   ' // is called with the same parameters received by the window procedure.
      FUNCTION = DefWindowProc(hwnd, uMsg, wParam, lParam)
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Default CWindow MDI callback function.
' ========================================================================================
FUNCTION MDIWindowProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL hWB           AS DWORD                    ' // Handle to the window that hosts the WebBrowser control
   LOCAL pIWebBrowser2 AS IWebBrowser2             ' // WebBrowser control reference
   LOCAL pWBEvents     AS DWebBrowserEvents2Impl   ' // Event class reference
   LOCAL rc            AS RECT                     ' // RECT structure

   SELECT CASE uMsg

      CASE %WM_CREATE
         ' // Retrieve a reference to the CWindow class from the MDI child window handle
         LOCAL pWindow AS IWindow
         pWindow = CWindow_GetObjectFromWindowHandle(hwnd)
         ' // Create and edit control control
         IF ISOBJECT(pWindow) THEN
            ' // Get the client coordinates of the window
            GetClientRect hwnd, rc
            ' // Add an instance of the WebBrowser control
            hWB = pWindow.AddWebBrowserControl(hwnd, %IDC_IEWB, "", NOTHING, 0, 0, rc.nRight, rc.nBottom)
            ' // Get the IDispatch of the control
            pIWebBrowser2 = OC_GetDispatch(hWB)
            IF ISOBJECT(pIWebBrowser2) THEN
               ' // Create an instance of the event class
               pWBEvents = CLASS "CDWebBrowserEvents2"
               IF ISOBJECT(pWBEvents) THEN
                  ' // Connect to the events fired by the control
                  OC_Advise(hWb, pWBEvents)
                  ' // Set the handle of the main window
                  pWBEvents.SethwndMain(pWindow.hwnd)
                  ' // Set the handle of the MDI client window
                  pWBEvents.SethwndClient(pWindow.hwndClient)
               END IF
               ' // Release the object reference
               pIWebBrowser2 = NOTHING
               EXIT FUNCTION
            END IF
         END IF

      CASE %WM_SETFOCUS
         ' // Set the keyboard focus to the first control that is
         ' // visible, not disabled, and has the WS_TABSTOP style
         SetFocus GetNextDlgTabItem(hwnd, %NULL, %FALSE)
         ' // Retrieve a reference to the CWindow class from the MDI child window handle
         pWindow = CWindow_GetObjectFromWindowHandle(hwnd)
         ' // Show the caption of the active MDI child window in the URL edit box
         AfxSetWindowText(GetDlgItem(GetDlgItem(pWindow.hwnd, %IDC_REBAR), %IDC_EDITURL), _
            AfxGetWindowText(MdiGetActive(pWindow.hwndClient)))

      CASE %WM_SIZE
         IF wParam <> %SIZE_MINIMIZED THEN
            ' // Resize the window and/or its controls
            MoveWindow GetDlgItem(hwnd, %IDC_IEWB), 0, 0, LO(WORD, lParam), HI(WORD, lParam), %TRUE
         END IF

         ' // Don't exit. Let DefMDIChildProc to process the message for
         ' // properly resizing of the MDI child window.

'      CASE %WM_DESTROY
'         ' // Do cleanunp if needed, such removing properties attached
'         ' // to the MDI child window.
'         EXIT FUNCTION

   END SELECT

   ' // The DefMDIChildProc function provides default processing for any window
   ' // message that the window procedure of a multiple-document interface (MDI)
   ' // child window does not process. A window message not processed by the window
   ' // procedure must be passed to the DefMDIChildProc function, not to the
   ' // DefWindowProc function.
   FUNCTION = DefMDIChildProc(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Create the toolbar control image list
' ========================================================================================
FUNCTION CreateToolbarImageList () AS IAfxImageList

   LOCAL cx, cy AS LONG

   LOCAL pAfxImageList AS IAfxImageList
   pAfxImageList = CLASS "CAfxImageList"
   IF ISNOTHING(pAfxImageList) THEN EXIT FUNCTION

   ' // Desired icon size width and height
   cx = GetSystemMetrics(%SM_CXSMICON)
   cy = GetSystemMetrics(%SM_CYSMICON)

   ' // Create the image list
   pAfxImageList.CreateImageList(cx, cy, %ILC_COLOR32 OR %ILC_MASK, 14)

   ' // Give a name to the image list
   pAfxImageList.Name = "Toolbar image list"

   ' // Add the icons from the resource file
   pAfxImageList.LoadResIcon(%IDI_BACK, cx, cy)
   pAfxImageList.LoadResIcon(%IDI_FORWARD, cx, cy)
   pAfxImageList.LoadResIcon(%IDI_NEW, cx, cy)
   pAfxImageList.LoadResIcon(%IDI_FIND, cx, cy)
   pAfxImageList.LoadResIcon(%IDI_PRINTPREV, cx, cy)
   pAfxImageList.LoadResIcon(%IDI_PAGESETUP, cx, cy)
   pAfxImageList.LoadResIcon(%IDI_PRINT, cx, cy)
   pAfxImageList.LoadResIcon(%IDI_PROPERTIES, cx, cy)
   pAfxImageList.LoadResIcon(%IDI_SAVE, cx, cy)
   pAfxImageList.LoadResIcon(%IDI_REFRESH, cx, cy)
   pAfxImageList.LoadResIcon(%IDI_STOP, cx, cy)
   pAfxImageList.LoadResIcon(%IDI_ZOOMIN, cx, cy)
   pAfxImageList.LoadResIcon(%IDI_ZOOMOUT, cx, cy)
   pAfxImageList.LoadResIcon(%IDI_EXIT, cx, cy)

   FUNCTION = pAfxImageList

END FUNCTION
' ========================================================================================

' ========================================================================================
' Create the toolbar control
' ========================================================================================
FUNCTION CreateToolbar (BYVAL pWindow AS IWindow) AS DWORD

   LOCAL hToolbar   AS DWORD          ' // Toolbar handle
   LOCAL pImageList AS IAfxImageList  ' // Toolbar control image list handle

   ' // Create the toolbar control
   hToolbar = pWindow.AddToolbar(pWindow.hwnd, %IDC_TOOLBAR, "", 0, 0, 0, 0, _
              %WS_CHILD OR %WS_VISIBLE OR %TBSTYLE_TOOLTIPS OR %TBSTYLE_FLAT OR _
              %CCS_NODIVIDER OR %CCS_NORESIZE OR %CCS_NOPARENTALIGN, 0, 0, %FALSE)

   ' // Create the image list for the toolbar control
   pImageList = CreateToolbarImageList
   ' // Register it in the collection of objects
   pWindow.AddObject(pImageList.Name, pImageList)
   ' // Set the imagelist
   ToolBar_SetImageList(hToolbar, pImageList.hImageList)

   ' // Add buttons to the toolbar
   Toolbar_AddButton hToolBar,  0, %ID_GOBACK
   Toolbar_AddButton hToolBar,  1, %ID_FORWARD
   Toolbar_AddButton hToolBar,  2, %ID_NEW
   Toolbar_AddButton hToolBar,  3, %ID_FIND
   Toolbar_AddButton hToolBar,  4, %ID_PRINTPREVIEW
   Toolbar_AddButton hToolBar,  5, %ID_PAGESETUP
   Toolbar_AddButton hToolBar,  6, %ID_PRINT
   Toolbar_AddButton hToolBar,  7, %ID_PROPERTIES
   Toolbar_AddButton hToolBar,  8, %ID_FILE_SAVE
   Toolbar_AddButton hToolBar,  9, %ID_REFRESH
   Toolbar_AddButton hToolBar, 10, %ID_STOP
   Toolbar_AddButton hToolBar, 11, %ID_ZOOMIN
   Toolbar_AddButton hToolBar, 12, %ID_ZOOMOUT
   Toolbar_AddButton hToolBar, 13, %ID_EXIT

   ' // Update the size of the toolbar
   ToolBar_AutoSize(hToolbar)

   ' // Return the handle of the toolbar
   FUNCTION = hToolbar

END FUNCTION
' ========================================================================================

' ========================================================================================
' Create the rebar control
' ========================================================================================
FUNCTION CreateRebar (BYVAL pWindow AS IWindow) AS DWORD

   LOCAL hRebar     AS DWORD           ' // Handle of the rebar control
   LOCAL hToolbar   AS DWORD           ' // Handle of the toolbar control
   LOCAL hEditURL   AS DWORD           ' // Handle of the edit URL control
   LOCAL hGoButton  AS DWORD           ' // Handle of the Go button
   LOCAL trbbi      AS REBARBANDINFO   ' // Specifies or receives the attributes of a rebar band
   LOCAL wszItem    AS WSTRINGZ * 260  ' // Item text

   ' // Create the rebar
   hRebar = pWindow.AddRebar(pWindow.hwnd, %IDC_REBAR, "", 0, 0, 0, 0, _
            %WS_VISIBLE OR %WS_BORDER OR %WS_CLIPCHILDREN OR %WS_CLIPSIBLINGS OR %CCS_NODIVIDER OR %RBS_AUTOSIZE)

   ' // Create the toolbar
   hToolbar = CreateToolbar(pWindow)

   ' // Add the band containing the Toolbar1 toolbar control to the rebar
   ' // The size of the REBARBANDINFO is different in Vista/Windows 7
   IF AfxGetWindowsVersion => 6.00 AND AfxGetComCtlVersion => 6.00 THEN
      trbbi.cbSize  = %REBARBANDINFO_V6_SIZE
   ELSE
      trbbi.cbSize  = %REBARBANDINFO_V3_SIZE
   END IF
   trbbi.fMask      = %RBBIM_STYLE OR %RBBIM_CHILD OR %RBBIM_CHILDSIZE OR _
                      %RBBIM_SIZE OR %RBBIM_ID OR %RBBIM_IDEALSIZE
   trbbi.fStyle     = %RBBS_CHILDEDGE
   trbbi.hwndChild  = hToolbar
   trbbi.cxMinChild = 320 * pWindow.rxRatio
   trbbi.cyMinChild = HI(WORD, SendMessage(hToolBar, %TB_GETBUTTONSIZE, 0, 0))
   trbbi.cx         = 320 * pWindow.rxRatio
   trbbi.wID        = 0
   trbbi.cxIdeal    = 320 * pWindow.rxRatio
   Rebar_InsertBand(hRebar, -1, trbbi)

   ' // Create the EditUrl edit control
   hEditURL = pWindow.AddTextBox(pWindow.hwnd, %IDC_EDITURL, "", 151, 0, 0, 0)
   SetWindowText hEditURL, "http://www.jose.it-berater.org/index.html"

   ' // Add the band containing the EditUrl edit control to the rebar
   wszItem          = "URL"
   trbbi.fMask      = %RBBIM_STYLE OR %RBBIM_TEXT OR %RBBIM_CHILD OR _
                      %RBBIM_CHILDSIZE OR %RBBIM_SIZE OR %RBBIM_ID OR _
                      %RBBIM_IDEALSIZE
   trbbi.fStyle     = %RBBS_CHILDEDGE
   trbbi.lpText     = VARPTR(wszItem)
   trbbi.hwndChild  = hEditURL
   trbbi.cxMinChild = 450 * pWindow.rxRatio
   trbbi.cyMinChild = 22 * pWindow.ryRatio
   trbbi.cx         = 450 * pWindow.rxRatio
   trbbi.wID        = 0
   trbbi.cxIdeal    = 450 * pWindow.rxRatio
   Rebar_InsertBand(hRebar, -1, trbbi)

   ' // Create the "Go" button
   hGoButton = pWindow.AddButton(pWindow.hwnd, %IDC_GOBTN, "Go", 0, 0, 0, 0)

   ' // Add the band containing the GoBtn button to the rebar
   trbbi.fMask      = %RBBIM_STYLE OR %RBBIM_CHILD OR %RBBIM_CHILDSIZE OR _
                      %RBBIM_SIZE OR %RBBIM_ID OR %RBBIM_IDEALSIZE
   trbbi.fStyle     = %RBBS_FIXEDSIZE OR %RBBS_CHILDEDGE
   trbbi.hwndChild  = hGoButton
   trbbi.cxMinChild = 34 * pWindow.rxRatio
   trbbi.cyMinChild = 24 * pWindow.ryRatio
   trbbi.cx         = 34 * pWindow.rxRatio
   trbbi.wID        = 0
   trbbi.cxIdeal    = 34 * pWindow.rxRatio
   Rebar_InsertBand(hRebar, -1, trbbi)

   ' // Return the handle of the rebar control
   FUNCTION = hRebar

END FUNCTION
' ========================================================================================

' ========================================================================================
' Build the menu
' ========================================================================================
FUNCTION BuildMenu () AS DWORD

   LOCAL hMenu AS DWORD
   LOCAL hPopUpMenu AS DWORD

   hMenu = CreateMenu
   hPopUpMenu = CreatePopUpMenu
      AppendMenu hMenu, %MF_POPUP OR %MF_ENABLED, hPopUpMenu, "&File"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_NEW, "&New" & $TAB & "Ctrl+N"
         AppendMenu hPopUpMenu, %MF_SEPARATOR, 0, ""
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_SAVEAS, "Save &As..."
         AppendMenu hPopUpMenu, %MF_SEPARATOR, 0, ""
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_EXIT, "E&xit" & $TAB & "Alt+F4"
   hPopUpMenu = CreatePopUpMenu
      AppendMenu hMenu, %MF_POPUP OR %MF_ENABLED, hPopUpMenu, "&Window"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_TILEH, "&Tile Horizontal"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_TILEV, "Tile &Vertical"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_CASCADE, "Ca&scade"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_ARRANGE, "&Arrange &Icons"
         AppendMenu hPopUpMenu, %MF_SEPARATOR, 0, ""
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_CLOSE, "&Close" & $TAB & "Ctrl+F4"
         AppendMenu hPopUpMenu, %MF_ENABLED, %IDM_CLOSEALL, "Close &All"

   FUNCTION = hMenu

END FUNCTION
' ========================================================================================

' ========================================================================================
' Class CDWebBrowserEvents2
' Interface name = DWebBrowserEvents2
' IID = {34A715A0-6587-11D0-924A-0020AFC7AC4D}
' Web Browser Control events interface
' Attributes = 4112 [&H1010] [Hidden] [Dispatchable]
' ========================================================================================
CLASS CDWebBrowserEvents2 GUID$("{700B73A2-CCFC-4FE0-B9AC-D5853D71B7B9}") AS EVENT

   INSTANCE m_hwndMain AS DWORD     ' // Main window handle
   INSTANCE m_hwndClient AS DWORD   ' // MDI client window handle
   INSTANCE bQualifiedUrl AS LONG   ' // Indicates that the qualified url has already been set in the URL edit textbox
   INSTANCE bNewWindow3 AS LONG     ' // Indicates that the NewWindow3 event as been processed

INTERFACE DWebBrowserEvents2Impl GUID$("{34A715A0-6587-11D0-924A-0020AFC7AC4D}") AS EVENT

   INHERIT IDispatch

   ' =====================================================================================
   METHOD StatusTextChange <102> ( _
     BYVAL bstrText AS WSTRING _                        ' __in BSTR Text
   )                                                    ' void

      ' // Retrieves the handle of the status bar
      LOCAL hStatusBar AS DWORD
      hStatusBar = GetDlgItem(m_hwndMain, %IDC_STATUSBAR)
      IF ISFALSE hStatusBar THEN EXIT METHOD
      ' // Shows the changed statusbar text
      StatusBar_SetText(hStatusBar, 0, bstrText)

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD ProgressChange <108> ( _
     BYVAL Progress AS LONG _                           ' __in long Progress
   , BYVAL ProgressMax AS LONG _                        ' __in long ProgressMax
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD CommandStateChange <105> ( _
     BYVAL nCommand AS LONG _                           ' __in long Command
   , BYVAL bEnable AS INTEGER _                         ' __in VARIANT_BOOL Enable
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD DownloadBegin <106>

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD DownloadComplete <104>

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD TitleChange <113> ( _
     BYVAL bstrText AS WSTRING _                        ' __in BSTR Text
   )                                                    ' void

      ' // Changes the caption of the active MDI child window
      SetWindowText MdiGetActive(m_hwndClient), BYCOPY bstrText

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD PropertyChange <112> ( _
     BYVAL bstrProperty AS WSTRING _                    ' __in BSTR szProperty
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD BeforeNavigate2 <250> ( _
     BYVAL pDisp AS IDispatch _                         ' __in IDispatch* pDisp
   , BYREF vURL AS VARIANT _                            ' __in VARIANT* URL
   , BYREF vFlags AS VARIANT _                          ' __in VARIANT* Flags
   , BYREF vTargetFrameName AS VARIANT _                ' __in VARIANT* TargetFrameName
   , BYREF vPostData AS VARIANT _                       ' __in VARIANT* PostData
   , BYREF vHeaders AS VARIANT _                        ' __in VARIANT* Headers
   , BYREF bCancel AS INTEGER _                         ' __in_out VARIANT_BOOL* Cancel
   )                                                    ' void

   IF bQualifiedUrl = %FALSE THEN
      ' // Retrieve the handle of the rebar control
      LOCAL hCtrl AS DWORD
      hCtrl = GetDlgItem(m_hwndMain, %IDC_REBAR)
      ' // Retrieve the handle of the edit control
      hCtrl = GetDlgItem(hCtrl, %IDC_EDITURL)
      ' // Show the canonicalized and qualified URL
      SetWindowText hCtrl, VARIANT$$(vURL)
      bQualifiedUrl = %TRUE
   END IF

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD NewWindow2 <251> ( _
     BYREF ppDisp AS IDispatch _                        ' __in_out IDispatch** ppDisp
   , BYREF bCancel AS INTEGER _                         ' __in-out VARIANT_BOOL* Cancel
   )                                                    ' void

      ' // Cancel new window creation if the NewWindow3 event has been processed.
      IF bNewWindow3 THEN
         bCancel = %VARIANT_TRUE
         bNewWindow3 = %FALSE
         EXIT METHOD
      END IF

      ' // Create the new window in a new MDI child window
      LOCAL hMdi AS DWORD
      LOCAL hWB AS DWORD
      LOCAL pIWebBrowser2 AS IWebBrowser2

      ' // Create an MDI child
      hMdi = CreateMdiChild("PBFrameClass", m_hwndClient, "", 0)
'      hMdi = CreateMdiChild("PBFrameClass", m_hwndClient, "", %WS_MAXIMIZE)
      ' // Get the handle of the control
      hWB = GetDlgItem(hMdi, %IDC_IEWB)
      ' // Get the IDispatch of the control
      pIWebBrowser2 = OC_GetDispatch(hWB)
      IF ISOBJECT(pIWebBrowser2) THEN
         ' // Register the browser
         pIWebBrowser2.RegisterAsBrowser = %VARIANT_TRUE
         ppDisp = pIWebBrowser2
         ' // Release the object reference
         pIWebBrowser2 = NOTHING
      END IF

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD NavigateComplete2 <252> ( _
     BYVAL pDisp AS IDispatch _                         ' __in IDispatch* pDisp
   , BYREF vURL AS VARIANT _                            ' __in VARIANT* URL
   )                                                    ' void

      ' // Retrieve the handle of the status bar
      LOCAL hStatusBar AS DWORD
      hStatusBar = GetDlgItem(m_hwndMain, %IDC_STATUSBAR)
      IF ISFALSE hStatusBar THEN EXIT METHOD
      ' // Retrieve the handle of the rebar control
      LOCAL hCtrl AS DWORD
      hCtrl = GetDlgItem(m_hwndMain, %IDC_REBAR)
      ' // Show the changed statusbar text
      LOCAL bstrURL AS WSTRING
      bstrURL = VARIANT$$(vURL)
      StatusBar_SetText(hStatusBar, 0, bstrURL)

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD DocumentComplete <259> ( _
     BYVAL pDisp AS IDispatch _                         ' __in IDispatch* pDisp
   , BYREF vURL AS VARIANT _                            ' __in VARIANT* URL
   )                                                    ' void

      bQualifiedUrl = %FALSE

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD OnQuit <253>

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD OnVisible <254> ( _
     BYVAL bVisible AS INTEGER _                        ' __in VARIANT_BOOL Visible
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD OnToolBar <255> ( _
     BYVAL bToolBar AS INTEGER _                        ' __in VARIANT_BOOL ToolBar
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD OnMenuBar <256> ( _
     BYVAL bMenuBar AS INTEGER _                        ' __in VARIANT_BOOL MenuBar
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD OnStatusBar <257> ( _
     BYVAL bStatusBar AS INTEGER _                      ' __in VARIANT_BOOL StatusBar
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD OnFullScreen <258> ( _
     BYVAL bFullScreen AS INTEGER _                     ' __in VARIANT_BOOL FullScreen
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD OnTheaterMode <260> ( _
     BYVAL bTheaterMode AS INTEGER _                    ' __in VARIANT_BOOL TheaterMode
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD WindowSetResizable <262> ( _
     BYVAL bResizable AS INTEGER _                      ' __in VARIANT_BOOL Resizable
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD WindowSetLeft <264> ( _
     BYVAL nLeft AS LONG _                              ' __in long Left
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD WindowSetTop <265> ( _
     BYVAL Top AS LONG _                                ' __in long Top
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD WindowSetWidth <266> ( _
     BYVAL nWidth AS LONG _                             ' __in long Width
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD WindowSetHeight <267> ( _
     BYVAL Height AS LONG _                             ' __in long Height
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD WindowClosing <263> ( _
     BYVAL bIsChildWindow AS INTEGER _                  ' __in     VARIANT_BOOL IsChildWindow
   , BYREF bCancel AS INTEGER _                         ' __in_out VARIANT_BOOL* Cancel
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD ClientToHostWindow <268> ( _
     BYREF CX AS LONG _                                 ' __in_out long* CX
   , BYREF CY AS LONG _                                 ' __in_out long* CY
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD SetSecureLockIcon <269> ( _
     BYVAL SecureLockIcon AS LONG _                     ' _in long SecureLockIcon
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD FileDownload <270> ( _
     BYVAL bActiveDocument AS INTEGER _                 ' __in     VARIANT_BOOL ActiveDocument
   , BYREF bCancel AS INTEGER _                         ' __in_out VARIANT_BOOL* Cancel
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD NavigateError <271> ( _
     BYVAL pDisp AS IDispatch _                         ' __in IDispatch* pDisp
   , BYREF vURL AS VARIANT _                            ' __in VARIANT* URL
   , BYREF vFrame AS VARIANT _                          ' __in VARIANT* Frame
   , BYREF vStatusCode AS VARIANT _                     ' __in VARIANT* StatusCode
   , BYREF bCancel AS INTEGER _                         ' __in_out VARIANT_BOOL* Cancel
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD PrintTemplateInstantiation <225> ( _
     BYVAL pDisp AS IDispatch _                         ' __in IDispatch* pDisp
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD PrintTemplateTeardown <226> ( _
     BYVAL pDisp AS IDispatch _                         ' __in IDispatch* pDisp
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD UpdatePageStatus <227> ( _
     BYVAL pDisp AS IDispatch _                         ' __in IDispatch* pDisp
   , BYREF nPage AS VARIANT _                           ' __in VARIANT* nPage
   , BYREF fDone AS VARIANT _                           ' __in VARIANT* fDone
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD PrivacyImpactedStateChange <272> ( _
     BYVAL bImpacted AS INTEGER _                       ' __in VARIANT_BOOL bImpacted
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD NewWindow3 <273> ( _
     BYREF ppDisp AS IDispatch _                        ' __in_out IDispatch** ppDisp
   , BYREF bCancel AS INTEGER _                         ' __in_out VARIANT_BOOL* Cancel
   , BYVAL dwFlags AS DWORD _                           ' __in unsigned long dwFlags
   , BYVAL bstrUrlContext AS WSTRING _                  ' __in BSTR bstrUrlContext
   , BYVAL bstrUrl AS WSTRING _                         ' __in BSTR bstrUrl
   )                                                    ' void

      LOCAL hr AS LONG                      ' // Long result
      LOCAL hMdi AS DWORD                   ' // Handle to the MDI child window
      LOCAL hWB AS DWORD                    ' // Handle to the window that hosts the WebBrowser control
      LOCAL pIWebBrowser2 AS IWebBrowser2   ' // WebBrowser object reference

      ' // The combination of the %NWMF_FIRST_USERINITED and %NWMF_USERINITED flags
      ' // indicates that is the first query that results of a user-initiated action
      ' // (a mouse click or key press). Otherwise, it must be a popup.
      IF (dwFlags AND %NWMF_FIRST_USERINITED) = %NWMF_FIRST_USERINITED AND _
         (dwFlags AND %NWMF_USERINITED) = %NWMF_USERINITED THEN
         ' // Flag that indicates that this event has been processed.
         bNewWindow3 = %TRUE
         ' // Create an MDI child
         hMdi = CreateMdiChild("PBFrameClass", m_hwndClient, "", 0)
'         hMdi = CreateMdiChild("PBFrameClass", m_hwndClient, "", %WS_MAXIMIZE)
         ' // Get the handle of the control
         hWB = GetDlgItem(hMdi, %IDC_IEWB)
         ' // Get the IDispatch of the control
         pIWebBrowser2 = OC_GetDispatch(hWB)
         IF ISOBJECT(pIWebBrowser2) THEN
            ' // Register the browser
            pIWebBrowser2.RegisterAsBrowser = %VARIANT_TRUE
            ppDisp = pIWebBrowser2
            ' // Release the object reference
            pIWebBrowser2 = NOTHING
         END IF
      ELSE
         ' // Popup blocker.
         ' // Bug: IE6 gives "?ttp://" instead of "http://"
         IF LEFT$(bstrUrl, 1) <> "h" THEN MID$(bstrUrl, 1, 1) = "h"
         hr = MessageBox(m_hwndClient, "Do you want to activate the popup window?" & $CRLF & bstrUrl, _
              "Popup blocked", %MB_YESNOCANCEL OR %MB_ICONQUESTION OR %MB_APPLMODAL)
         IF hr = %IDYES THEN
            ' // Allow the creation of a new window in the NewWindow2 event
            bNewWindow3 = %FALSE
            bCancel = %VARIANT_FALSE
         ELSE
            bCancel = %VARIANT_TRUE
         END IF
      END IF

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD SetPhishingFilterStatus <282> ( _
     BYVAL PhishingFilterStatus AS LONG _               ' __in long PhishingFilterStatus
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD WindowStateChanged <283> ( _
     BYVAL dwWindowStateFlags AS DWORD _                ' __in unsigned long dwWindowStateFlags
   , BYVAL dwValidFlagsMask AS DWORD _                  ' __in unsigned long dwValidFlagsMask
   )                                                    ' void

     ' *** Insert your code here ***

   END METHOD
   ' =====================================================================================

   ' =========================== *** PRIVATE METHODS *** =================================

   ' =====================================================================================
   ' Sets the main window handle
   ' =====================================================================================
   METHOD SethwndMain <998> (BYVAL hwndMain AS DWORD)
      m_hwndMain = hwndMain
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the MDI client window handle
   ' =====================================================================================
   METHOD SethwndClient <999> (BYVAL hwndClient AS DWORD)
      m_hwndClient = hwndClient
   END METHOD
   ' =====================================================================================

END INTERFACE

END CLASS
' ========================================================================================
