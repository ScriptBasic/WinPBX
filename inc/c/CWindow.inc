' ########################################################################################
' Class CWindow
' A wrapper class to create a SDK main window and add controls to it.
' (C) 2011 José Roca. Freeware. Use at your own risk.
' Acknowledgements: I want to thank Dominic Mitchell for some code that I have borrowed
' from his examples to implement the MDI support in a clean way.
' Provides default values for window styles and Extended styles passing a value of -1.
' Optional High-DPI support (call the SET DPI property to set the dots per pixel used by the application).
' The window and the controls will be scaled if the user changes the DPI setting.
' Note: To make the application DPI aware with Windows Vista/Windows 7 it's needed a call to
' the API function SetProcessDPIAware or set it through the application manifest.
'   <assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0" xmlns:asmv3="urn:schemas-microsoft-com:asm.v3" >
'    ...
'     <asmv3:application>
'       <asmv3:windowsSettings xmlns="http://schemas.microsoft.com/SMI/2005/WindowsSettings">
'         <dpiAware>true</dpiAware>
'       </asmv3:windowsSettings>
'     </asmv3:application>
'    ...
'   </assembly>
' Easy subclassing of controls. Just pass the address of the callback function, e.g.
'   pWindow.AddButton(hParent, %IDCANCEL, "&Close", 350, 250, 75, 23, -1, -1, CODEPTR(TextBtn_SubclassProc))
' To add OCXs define %USEOLECON = 1 before including CWindow.inc and use the AddCotrol method, e.g.
'   pWindow.AddControl($OC_CLASSNAME, hParent, 100, "MSCAL.Calendar", 100, 100, 200, 200, -1)
' Remarks:
' - Do not subclass ActiveX controls.
' - Don't mess with the cbClsExtra member of the windows class. The class reserves 8 bytes
'   used to store a pointer to the CWindow class and a pointer to the MDI Window client handle.
'   Instead, use the GET/SET UserData properties that allow to get/set 10 long values using
'   an index of 0 to 9 inclusive.
' - The default CWindowProc and CWindowMDIProc callback procedures are just templates.
'   You must use your own instead. The default message pump (CWindow.DoEvents), should be
'   enough for most applications, but you can also use your own instead.
' ########################################################################################

#INCLUDE THIS ONCE
%CWINDOW_INC = 1

#INCLUDE ONCE "windows.inc"    ' // Windows API headers
#INCLUDE ONCE "commctrl.inc"   ' // Common controls
#INCLUDE ONCE "AfxWin.inc"     ' // Windows wrapper functions

' // Use IsDialogMessage in the DoEvents message pump
' // Note: To process arrow keys, characters, enter, insert, backspace or delete keys, set %USEDLGMSG = 0.
' // Or you can leave it as is and process the %WM_GETDLGCODE message:
' // CASE %WM_GETDLGCODE
' //    FUNCTION = %DLGC_WANTALLKEYS
' // If you are only interested in arrow keys and characters...
' // CASE %WM_GETDLGCODE
' //    FUNCTION = %DLGC_WANTARROWS OR %DLGC_WANTCHARS
#IF NOT %DEF(%USEDLGMSG)
    %USEDLGMSG = 1
#ENDIF

' // RichEdit control support
#IF NOT %DEF(%USERICHEDIT)
    %USERICHEDIT = 0
#ENDIF

#IF %USERICHEDIT = 1
    #INCLUDE ONCE "RichEdit.inc"
    #INCLUDE ONCE "RichEditCtrl.inc"
#ENDIF

' // Graphic control support
#IF NOT %DEF(%USEGRAPHCTX)
    %USEGRAPHCTX = 0
#ENDIF

#IF %USEGRAPHCTX = 1
    #INCLUDE ONCE "GraphCtx.inc"
#ENDIF

' // OpenGL Graphic control support
#IF NOT %DEF(%USEGLCTX)
    %USEGLCTX = 0
#ENDIF

#IF %USEGLCTX = 1
    #INCLUDE ONCE "GlCtx.inc"
#ENDIF

' // XPButton support
#IF NOT %DEF(%USEXPBUTTON)
    %USEXPBUTTON = 0
#ENDIF

#IF %USEXPBUTTON = 1
    #INCLUDE ONCE "XPButton.inc"
#ENDIF

' // Graphic control support
#IF NOT %DEF(%USEGDIPIMAGECTX)
    %USEGDIPIMAGECTX = 0
#ENDIF

#IF %USEGDIPIMAGECTX = 1
    #INCLUDE ONCE "GdipImageCtx.inc"
#ENDIF

' // Picture control support
#IF NOT %DEF(%USEPICTURECTX)
    %USEPICTURECTX = 0
#ENDIF

#IF %USEPICTURECTX = 1
    #INCLUDE ONCE "PictureCtx.inc"
#ENDIF

' // Picture control support
#IF NOT %DEF(%USEGDIPANIMCTX)
    %USEGDIPANIMCTX = 0
#ENDIF

#IF %USEGDIPANIMCTX = 1
    #INCLUDE ONCE "GdipAnimCtx.inc"
#ENDIF

' // Group line control support
#IF NOT %DEF(%USEGROUPLINECTX)
    %USEGROUPLINECTX = 0
#ENDIF

#IF %USEGROUPLINECTX = 1
    #INCLUDE ONCE "GroupLineCtx.inc"
#ENDIF

' // FreeIage control support
#IF NOT %DEF(%USEFREEIMAGECTX)
    %USEFREEIMAGECTX = 0
#ENDIF

#IF %USEFREEIMAGECTX = 1
    #INCLUDE ONCE "FreeImageCtx.inc"
#ENDIF

' // MDI support
#IF NOT %DEF(%USEMDI)
    %USEMDI = 0
#ENDIF

#IF %USEMDI = 1
    #INCLUDE ONCE "mdi32.inc"
#ENDIF

' // WebBrowser support
#IF NOT %DEF(%USEWEBBROWSER)
   %USEWEBBROWSER = 0
#ENDIF

#IF %USEWEBBROWSER = 1
   #IF NOT %DEF(%USEOLECON)
       %USEOLECON = 1
   #ENDIF
   #INCLUDE ONCE "exdisp.inc"
   #INCLUDE ONCE "mshtml.inc"
   #INCLUDE ONCE "mshtmhst.inc"   ' // Advanced host interfaces
#ENDIF

' // OCXs support
#IF NOT %DEF(%USEOLECON)
    %USEOLECON = 0
#ENDIF

#IF %USEOLECON = 1
    #INCLUDE ONCE "OLECON.INC"
#ENDIF

' ========================================================================================
' Prototypes for the SetProcessDPIAware and IsProcessDPIAware functions that must be
' called dynamically because they need Windows Vista or Windows 7.
' ========================================================================================
DECLARE FUNCTION CWindow_SetProcessDPIAware () AS LONG
DECLARE FUNCTION CWindow_IsProcessDPIAware () AS LONG
' ========================================================================================

' ========================================================================================
' Registers the window class.
' Parameter:
' - lpfnWndProc = Pointer to the window procedure.
' Return Value:
'   An atom that uniquely identifies the class.
' Remarks:
'   The values of several of the members of this structure can be retrieved with
'   GetClassLong and set with SetClassLong.
' Note: The class uses %CS_HREDRAW OR %CS_VREDRAW as default window styles. Without them,
' the background is not repainted and the controls leave garbage in it when resized. With
' them, windows with many controls cause heavy flicker. To avoid flicker, you can change
' the windows style using e.g. pWindow.ClassStyle = %CS_DBLCLKS and take care yourself of
' repainting.
' ========================================================================================
#IF %DEF(%UNICODE)
FUNCTION CWindow_RegisterClass (BYVAL strClassName AS WSTRING, BYVAL hInstance AS DWORD, BYVAL lpfnWndProc AS DWORD) AS WORD
#ELSE
FUNCTION CWindow_RegisterClass (BYVAL strClassName AS STRING, BYVAL hInstance AS DWORD, BYVAL lpfnWndProc AS DWORD) AS WORD
#ENDIF

   LOCAL  wAtom AS WORD                     ' // Atom
   LOCAL  wcex AS WNDCLASSEX                ' // WNDCLASSEX structure
   STATIC nCount AS LONG                    ' // Counter

   ' // Window class name
#IF %DEF(%UNICODE)
   STATIC szClassName AS WSTRINGZ * 256
#ELSE
   STATIC szClassName AS ASCIIZ * 256
#ENDIF

   IF LEN(strClassName) THEN szClassName = strClassName ELSE szClassName = "PBWindowClass"
   szClassName = szClassName & ":" & FORMAT$(nCount)

   ' // Default handler
   IF lpfnWndProc = %NULL THEN lpfnWndProc = CODEPTR(CWindowProc)

   ' // Fill the WNDCLASSEX structure
   wcex.cbSize        = SIZEOF(wcex)
   wcex.style         = %CS_DBLCLKS OR %CS_HREDRAW OR %CS_VREDRAW
   wcex.lpfnWndProc   = lpfnWndProc
   wcex.cbClsExtra    = 8   ' // Room to save the window and MDI client window handles
   wcex.cbWndExtra    = 4   ' // Extra bytes
   wcex.hInstance     = hInstance
   wcex.hCursor       = LoadCursor(%NULL, BYVAL %IDC_ARROW)
   wcex.hbrBackground = %COLOR_3DFACE + 1
   wcex.lpszMenuName  = %NULL
   wcex.lpszClassName = VARPTR(szClassName)
   wcex.hIcon         = 0
   wcex.hIconSm       = 0

   ' // Register the class
   wAtom = RegisterClassEx(wcex)

   ' // Increment the class counter
   IF wAtom THEN nCount += 1

   ' // Return the atom
   FUNCTION = wAtom

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creation parameters structure
' ========================================================================================
TYPE CWindow_CREATEPARAMS
   pWindow AS DWORD   ' // Reference to an instance the CWindow class
END TYPE
' ========================================================================================

' ========================================================================================
' Registers the MDI window class.
' Parameter:
' - lpfnWndProc = Pointer to the window procedure.
' Return Value:
'   An atom that uniquely identifies the class.
' Remarks:
'   The values of several of the members of this structure can be retrieved with
'   GetClassLong and set with SetClassLong.
' ========================================================================================
#IF %USEMDI = 1

#IF %DEF(%UNICODE)
FUNCTION CWindow_RegisterMDIClass (BYVAL strClassName AS WSTRING, BYVAL hInstance AS DWORD, BYVAL lpfnWndProc AS DWORD) AS WORD
#ELSE
FUNCTION CWindow_RegisterMDIClass (BYVAL strClassName AS STRING, BYVAL hInstance AS DWORD, BYVAL lpfnWndProc AS DWORD) AS WORD
#ENDIF

   STATIC wAtom AS WORD                     ' // Atom
   LOCAL  wcex AS WNDCLASSEX                ' // WNDCLASSEX structure

   ' // Already registered?
   IF wAtom THEN
      FUNCTION = wAtom
      EXIT FUNCTION
   END IF

   ' // MDI window class name
#IF %DEF(%UNICODE)
   LOCAL  szClassName AS WSTRINGZ * 256
#ELSE
   LOCAL  szClassName AS ASCIIZ * 256
#ENDIF
   IF LEN(strClassName) THEN szClassName = strClassName ELSE szClassName = "PBFrameClass"

   ' // Default handler
   IF lpfnWndProc = %NULL THEN lpfnWndProc = CODEPTR(CWindowMDIProc)

   ' // Fill the WNDCLASSEX structure
   wcex.cbSize        = SIZEOF(wcex)
   wcex.style         = %CS_DBLCLKS
   wcex.lpfnWndProc   = lpfnWndProc
   wcex.cbClsExtra    = 0
   wcex.cbWndExtra    = 0
   wcex.hInstance     = hInstance
   wcex.hCursor       = LoadCursor(%NULL, BYVAL %IDC_ARROW)
   wcex.hbrBackground = %COLOR_APPWORKSPACE + 1
   wcex.lpszMenuName  = %NULL
   wcex.lpszClassName = VARPTR(szClassName)
   wcex.hIcon         = 0
   wcex.hIconSm       = 0

   ' // Register the class
   wAtom = RegisterClassEx(wcex)

   ' // Return the atom
   FUNCTION = wAtom

END FUNCTION
#ENDIF
' ========================================================================================

' ========================================================================================
' Retrieves a pointer to the CWindow class and returns a reference counted object variable.
' ========================================================================================
FUNCTION CWindow_GetObjectFromCreateStruct (BYVAL lParam AS DWORD) AS IUnknown

   LOCAL pCreateStruct AS CREATESTRUCT PTR           ' // Initialization parameters
   LOCAL pCreateParams AS CWindow_CREATEPARAMS PTR   ' // Creation parameters
   LOCAL pWindowPtr AS DWORD                         ' // CWindow class pointer
   LOCAL pWindow AS IUnknown                         ' // CWindow class object variable
   LOCAL pv AS DWORD PTR                             ' // Pointer variable

   IF lParam = 0 THEN EXIT FUNCTION
   pCreateStruct = lParam
   IF @pCreateStruct.lpCreateParams THEN
      pCreateParams = @pCreateStruct.lpCreateParams
      pWindowPtr = @pCreateParams.pWindow
      IF pWindowPtr = 0 THEN EXIT FUNCTION
      pv = VARPTR(pWindow)
      @pv = pWindowPtr
      IF ISOBJECT(pWindow) THEN
         pWindow.AddRef
         FUNCTION = pWindow
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' CWindow class
' ========================================================================================
CLASS CWindow

   INSTANCE m_hwnd AS DWORD                    ' // Window handle
   INSTANCE m_hInstance AS DWORD               ' // Instance handle
   INSTANCE m_hFont AS DWORD                   ' // Default font
   INSTANCE m_hAccel AS DWORD                  ' // Accelerator table handle
   INSTANCE m_DPI AS LONG                      ' // Design time DPI
   INSTANCE m_rx AS SINGLE                     ' // Horizontal scaling ratio
   INSTANCE m_ry AS SINGLE                     ' // Vertical scaling ratio
   INSTANCE m_wAtom AS WORD                    ' // Class atom
   INSTANCE m_WBZoom AS LONG                   ' // Optical zoom (WebBrowser control)
   INSTANCE m_DefaultFontSize AS LONG          ' // Default font size
   INSTANCE m_pObjects AS IPowerCollection     ' // Collection of objects
   INSTANCE m_rgUserData() AS LONG             ' // User data
   INSTANCE m_rgAccelEntries() AS ACCELAPI     ' // Accelerators table
   INSTANCE m_TabPagePtr AS DWORD              ' // Tab page object pointer

#IF %DEF(%UNICODE)
   INSTANCE m_szClassName AS WSTRINGZ * 260                  ' // Class name
   INSTANCE m_szMDIClassName AS WSTRINGZ * 260               ' // MDI Class name
   INSTANCE m_szDefaultFontName AS WSTRINGZ * %LF_FACESIZE   ' // Default font name
#ELSE
   INSTANCE m_szClassName AS ASCIIZ * 260                    ' // Class name
   INSTANCE m_szMDIClassName AS ASCIIZ * 260                 ' // MDI Class name
   INSTANCE m_szDefaultFontName AS ASCIIZ * %LF_FACESIZE     ' // Default font name
#ENDIF

#IF %USEMDI = 1
   INSTANCE m_hwndClient AS DWORD              ' // MDI window handle
#ENDIF

#IF %USERICHEDIT = 1
   INSTANCE m_hRichEditLib AS DWORD            ' // Rich edit library
#IF %DEF(%UNICODE)
   INSTANCE m_RichEditClassName AS WSTRING     ' // Rich edit class name
#ELSE
   INSTANCE m_RichEditClassName AS STRING      ' // Rich edit class name
#ENDIF
#ENDIF

   CLASS METHOD Create

      REDIM m_rgUserData(9) AS INSTANCE LONG

      ' // Instance handle
      m_hInstance = GetModuleHandle(BYVAL %NULL)

      ' // Default DPI ratios/value
      m_rx = 1
      m_ry = 1
      m_DPI = 96

'      ' // Scale windows according to the DPI setting.
'      ' // Discarded because Windows checks by default the "Use XP Style DPI Scaling" option
'      ' // for DPIs of 120 (125%) or less and then CWindow does not do scaling.
'      LOCAL pWindow AS IWindow
'      pWindow = ME
'      IF ISOBJECT(pWindow) THEN
'         IF AfxGetUseDpiScaling = 0 THEN
'            pWindow.DPI = 96
'         ELSE
'            pWindow.DPI = -1
'         END IF
'         pWindow = NOTHING
'      END IF

      ' // Scale windows according to the DPI setting
      LOCAL pWindow AS IWindow
      pWindow = ME
      IF ISOBJECT(pWindow) THEN
         pWindow.DPI = -1
         pWindow = NOTHING
      END IF

      ' // Default WebBrowser zoom value
      m_WBZoom = 100

      ' // Default font name
      IF LEN(m_szDefaultFontName) = 0 THEN
         IF AfxGetWindowsVersion => 6 THEN m_szDefaultFontName = "Segoe UI" ELSE m_szDefaultFontName = "Tahoma"
      END IF
      ' // Default font size
      IF m_DefaultFontSize = 0 THEN
         IF AfxGetWindowsVersion => 6 THEN m_DefaultFontSize = 9 ELSE m_DefaultFontSize = 8
      END IF

      ' // Initialize the common controls library
      LOCAL icc AS INIT_COMMON_CONTROLSEX
      icc.dwSize = SIZEOF(icc)
      icc.dwICC  = %ICC_NATIVEFNTCTL_CLASS OR %ICC_COOL_CLASSES OR %ICC_BAR_CLASSES OR _
                   %ICC_TAB_CLASSES OR %ICC_USEREX_CLASSES OR %ICC_WIN95_CLASSES OR _
                   %ICC_STANDARD_CLASSES OR %ICC_ANIMATE_CLASS OR %ICC_DATE_CLASSES OR _
                   %ICC_HOTKEY_CLASS OR %ICC_INTERNET_CLASSES OR %ICC_LISTVIEW_CLASSES OR _
                   %ICC_PAGESCROLLER_CLASS OR %ICC_PROGRESS_CLASS OR %ICC_TREEVIEW_CLASSES OR _
                   %ICC_UPDOWN_CLASS
      InitCommonControlsEx(icc)

      m_pObjects = CLASS "PowerCollection"

      ' // Initialize the graphic controls
#IF %USEGRAPHCTX = 1
      InitGraphCtx
#ENDIF
#IF %USEGLCTX = 1
      InitGlCtx
#ENDIF
#IF %USEXPBUTTON = 1
      ' // Initialize the XPButton control
      InitXPButton
#ENDIF
#IF %USEGDIPIMAGECTX = 1
      ' // Initialize the GDI+ image control
      InitGdipImageCtx
#ENDIF
#IF %USEGDIPANIMCTX = 1
      ' // Initialize the GDI+ animation control
      InitGdipAnimCtx
#ENDIF
#IF %USEGROUPLINECTX = 1
      ' // Initialize the GDI+ animation control
      InitGroupLineCtx
#ENDIF
#IF %USEPICTURECTX = 1
      ' // Initialize the Picture image control
      InitPictureCtx
#ENDIF
#IF %USEFREEIMAGECTX = 1
      ' // Initialize the FreeImage image control
      InitFreeImageCtx
#ENDIF
#IF %USEOLECON = 1
      ' // Initialize the OLE container
      OC_Wininit
#ENDIF
   END METHOD

   CLASS METHOD Destroy
      ' // Deletes the associated tab item and destroys the window
      IF m_TabPagePtr THEN
         LOCAL i, nCount AS LONG, hTab AS DWORD, tci AS TCITEM
         ' // Get the handle of the tab control
         hTab = GetParent(m_hwnd)
         ' // Get the number of items
         nCount = SendMessage(hTab, %TCM_GETITEMCOUNT, 0, 0)
         ' // Ask to return the value of the lParam member
         tci.mask = %TCIF_PARAM
         ' // Get information of the items
         FOR i = 0 TO nCount - 1
            IF SendMessage(hTab, %TCM_GETITEM, i, VARPTR(tci)) THEN
               IF tci.lParam = m_TabPagePtr THEN
                  ' // Delete the tab item
                  SendMessage(hTab, %TCM_DELETEITEM, i, 0)
                  ' // Destroy the window of the tab page
                  DestroyWindow m_hwnd
                  ' // Set the focus in the first tab
                  IF nCount > 1 THEN SendMessage hTab, %TCM_SETCURFOCUS, 0, 0
                  EXIT FOR
               END IF
            END IF
         NEXT
      END IF
      ' // Free resources
      IF m_hFont THEN DeleteObject m_hFont
      IF m_hAccel THEN DestroyAcceleratorTable(m_hAccel)
      IF m_szClassName <> "" THEN UnregisterClass(m_szClassName, m_hInstance)
      IF m_szMDIClassName <> "" THEN UnregisterClass(m_szMDIClassName, m_hInstance)
#IF %USERICHEDIT = 1
      IF m_hRichEditLib THEN FreeLibrary m_hRichEditLib
#ENDIF
      ' // Clears the collection of objects
      IF ISOBJECT(m_pObjects) THEN m_pObjects.Clear
   END METHOD

   INTERFACE IWindow : INHERIT IAutomation

   ' =====================================================================================
   ' Optional. Class name.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   PROPERTY GET ClassName () AS WSTRING
      PROPERTY = m_szClassName
   END PROPERTY
#ELSE
   PROPERTY GET ClassName () AS STRING
      PROPERTY = m_szClassName
   END PROPERTY
#ENDIF
   ' =====================================================================================

   ' =====================================================================================
   ' Optional. Set class name.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   PROPERTY SET ClassName (BYVAL bstrClassName AS WSTRING)
      m_szClassName = bstrClassName
   END PROPERTY
#ELSE
   PROPERTY SET ClassName (BYVAL strClassName AS STRING)
      m_szClassName = strClassName
   END PROPERTY
#ENDIF
   ' =====================================================================================

   ' =====================================================================================
   ' Window creation
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD CreateWindow ( _
      BYVAL hParent AS DWORD, _             ' // Parent window handle
      BYVAL strTitle AS WSTRING, _          ' // Window caption
      BYVAL x AS LONG, _                    ' // Horizontal position
      BYVAL y AS LONG, _                    ' // Vertical position
      BYVAL nWidth AS LONG, _               ' // Window width
      BYVAL nHeight AS LONG, _              ' // Window height
      BYVAL dwStyle AS DWORD, _             ' // Window style
      BYVAL dwExStyle AS DWORD, _           ' // Extended style
      BYVAL lpfnWndProc AS DWORD, _         ' // Address of the callback function
      OPTIONAL BYVAL bNoScale AS LONG _     ' // Boolean - No scale
      ) AS DWORD                            ' // Window handle
#ELSE
   METHOD CreateWindow ( _
      BYVAL hParent AS DWORD, _             ' // Parent window handle
      BYVAL strTitle AS STRING, _           ' // Window caption
      BYVAL x AS LONG, _                    ' // Horizontal position
      BYVAL y AS LONG, _                    ' // Vertical position
      BYVAL nWidth AS LONG, _               ' // Window width
      BYVAL nHeight AS LONG, _              ' // Window height
      BYVAL dwStyle AS DWORD, _             ' // Window style
      BYVAL dwExStyle AS DWORD, _           ' // Extended style
      BYVAL lpfnWndProc AS DWORD, _         ' // Address of the callback function
      OPTIONAL BYVAL bNoScale AS LONG _     ' // Boolean - No scale
      ) AS DWORD                            ' // Window handle
#ENDIF

      ' // Exit if the window has already been created
      IF m_hwnd THEN EXIT METHOD
      ' // Default size values
      IF nWidth = 0 THEN
         nWidth = %CW_USEDEFAULT
         IF x = 0 THEN x = %CW_USEDEFAULT
      END IF
      ' // Register a class
      m_wAtom = CWindow_RegisterClass(m_szClassName, m_hInstance, lpfnWndProc)
      IF m_wAtom = 0 THEN EXIT METHOD
      ' // Create the window
      LOCAL dwClass AS DWORD
      dwClass = MAK(DWORD, m_wAtom, 0)
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_OVERLAPPEDWINDOW OR %WS_CLIPCHILDREN OR %WS_CLIPSIBLINGS
      IF dwExStyle = 0 OR BITS(LONG, dwExStyle) = -1 THEN dwExStyle = %WS_EX_CONTROLPARENT OR %WS_EX_WINDOWEDGE
      LOCAL tCreateParams AS CWindow_CREATEPARAMS
      tCreateParams.pWindow = OBJPTR(ME)
      ' // Create a default font
'      m_hFont = GetStockObject(%DEFAULT_GUI_FONT)
      m_hFont = ME.CreateFont(m_szDefaultFontName, m_DefaultFontSize, %FW_NORMAL, %FALSE, %FALSE, %FALSE, %DEFAULT_CHARSET)
      ' // CW_USEDEFAULT is a special value. Therefore, don't multiply it by the scaling factor.
      IF bNoScale THEN
         m_hwnd = CreateWindowEx(dwExStyle, BYVAL dwClass, BYCOPY strTitle, dwStyle, _
                  IIF&(x = %CW_USEDEFAULT, %CW_USEDEFAULT, x), _
                  IIF&(y = %CW_USEDEFAULT, %CW_USEDEFAULT, y), _
                  IIF&(nWidth = %CW_USEDEFAULT, %CW_USEDEFAULT, nWidth), _
                  IIF&(nHeight = %CW_USEDEFAULT, %CW_USEDEFAULT, nHeight), _
                  hParent, %NULL, m_hInstance, tCreateParams)
      ELSE
         m_hwnd = CreateWindowEx(dwExStyle, BYVAL dwClass, BYCOPY strTitle, dwStyle, _
                  IIF&(x = %CW_USEDEFAULT, %CW_USEDEFAULT, x * m_rx), _
                  IIF&(y = %CW_USEDEFAULT, %CW_USEDEFAULT, y * m_ry), _
                  IIF&(nWidth = %CW_USEDEFAULT, %CW_USEDEFAULT, nWidth * m_rx), _
                  IIF&(nHeight = %CW_USEDEFAULT, %CW_USEDEFAULT, nHeight * m_ry), _
                  hParent, %NULL, m_hInstance, tCreateParams)
      END IF
      IF m_hwnd = %NULL THEN EXIT METHOD
      ' // Store a pointer to the class
      SetClassLong m_hwnd, 0, OBJPTR(ME)
      ' // Retrieve the class name
      GetClassName(m_hwnd, m_szClassName, SIZEOF(m_szClassName))
      ' // Set the font
      SendMessage m_hwnd, %WM_SETFONT, m_hFont, %FALSE
      ' // Return the window handle
      METHOD = m_hwnd
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Resize the window
   ' =====================================================================================
   METHOD Resize
      SendMessage m_hwnd, %WM_SIZE, %SIZE_RESTORED, MAK(LONG, ME.CLientWidth, ME.ClientHeight)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Scales an horizontal coordinate according the DPI setting.
   ' =====================================================================================
   METHOD ScaleX (BYVAL cx AS SINGLE) AS SINGLE
      METHOD = cx * m_rx
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Scales a vertical coordinate according the DPI setting.
   ' =====================================================================================
   METHOD ScaleY (BYVAL cy AS SINGLE) AS SINGLE
      METHOD = cy * m_ry
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Unscales an horizontal coordinate according the DPI setting.
   ' =====================================================================================
   METHOD UnScaleX (BYVAL cx AS SINGLE) AS SINGLE
      METHOD = cx / m_rx
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Unscales a vertical coordinate according the DPI setting.
   ' =====================================================================================
   METHOD UnScaleY (BYVAL cy AS SINGLE) AS SINGLE
      METHOD = cy / m_ry
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves the dimensions of the bounding rectangle of the main window.
   ' =====================================================================================
   METHOD GetWindowRect (BYREF rc AS RECT, OPTIONAL BYVAL bNoScale AS LONG) AS LONG
      LOCAL r AS LONG
      r = GetWindowRect(m_hwnd, rc)
      IF r = 0 THEN EXIT METHOD
      IF bNoScale = 0 THEN
         ' // Divide by m_rx and m_ry to make the result High DPI aware
         rc.Left   /= m_rx
         rc.Right  /= m_rx
         rc.Top    /= m_ry
         rc.Bottom /= m_ry
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves the coordinates of the main window's client area.
   ' =====================================================================================
   METHOD GetClientRect (BYREF rc AS RECT, OPTIONAL BYVAL bNoScale AS LONG) AS LONG
      LOCAL r AS LONG
      r = GetClientRect(m_hwnd, rc)
      IF r = 0 THEN EXIT METHOD
      IF bNoScale = 0 THEN
         ' // Divide by m_rx and m_ry to make the result High DPI aware
         rc.Left   /= m_rx
         rc.Right  /= m_rx
         rc.Top    /= m_ry
         rc.Bottom /= m_ry
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the width of the window
   ' =====================================================================================
   PROPERTY GET Width (OPTIONAL BYVAL bNoScale AS LONG) AS LONG
      LOCAL rc AS RECT
      GetWindowRect m_hwnd, rc
      IF bNoScale THEN
         PROPERTY = (rc.Right - rc.Left)
      ELSE
         ' // Divide by m_rx to make the result High DPI aware
         PROPERTY = (rc.Right - rc.Left) / m_rx
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the height of the window
   ' =====================================================================================
   PROPERTY GET Height (OPTIONAL BYVAL bNoScale AS LONG) AS LONG
      LOCAL rc AS RECT
      GetWindowRect m_hwnd, rc
      IF bNoScale THEN
         PROPERTY = (rc.Bottom - rc.Top)
      ELSE
         ' // Divide by m_rx to make the result High DPI aware
         PROPERTY = (rc.Bottom - rc.Top) / m_ry
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the client width of the window
   ' =====================================================================================
   PROPERTY GET ClientWidth (OPTIONAL BYVAL bNoScale AS LONG) AS LONG
      LOCAL rc AS RECT
      GetClientRect m_hwnd, rc
      IF bNoScale THEN
         PROPERTY = (rc.Right - rc.Left)
      ELSE
         ' // Divide by m_rx to make the result High DPI aware
         PROPERTY = (rc.Right - rc.Left) / m_rx
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the client height of the window
   ' =====================================================================================
   PROPERTY GET ClientHeight (OPTIONAL BYVAL bNoScale AS LONG) AS LONG
      LOCAL rc AS RECT
      GetClientRect m_hwnd, rc
      IF bNoScale THEN
         PROPERTY = (rc.Bottom - rc.Top)
      ELSE
         ' // Divide by m_rx to make the result High DPI aware
         PROPERTY = (rc.Bottom - rc.Top) / m_ry
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves the dimensions of the bounding rectangle of the specified window.
   ' =====================================================================================
   METHOD GetControlWindowRect (BYVAL hwnd AS DWORD, BYREF rc AS RECT, OPTIONAL BYVAL bNoScale AS LONG) AS LONG
      LOCAL r AS LONG
      r = GetWindowRect(hwnd, rc)
      IF r = 0 THEN EXIT METHOD
      IF bNoScale = 0 THEN
         ' // Divide by m_rx and m_ry to make the result High DPI aware
         rc.Left   /= m_rx
         rc.Right  /= m_rx
         rc.Top    /= m_ry
         rc.Bottom /= m_ry
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves the coordinates of a window's client area.
   ' =====================================================================================
   METHOD GetControlClientRect (BYVAL hwnd AS DWORD, BYREF rc AS RECT, OPTIONAL BYVAL bNoScale AS LONG) AS LONG
      LOCAL r AS LONG
      r = GetClientRect(hwnd, rc)
      IF r = 0 THEN EXIT METHOD
      IF bNoScale = 0 THEN
         ' // Divide by m_rx and m_ry to make the result High DPI aware
         rc.Left   /= m_rx
         rc.Right  /= m_rx
         rc.Top    /= m_ry
         rc.Bottom /= m_ry
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the width of the specified window
   ' =====================================================================================
   PROPERTY GET ControlWidth (BYVAL hwnd AS DWORD, OPTIONAL BYVAL bNoScale AS LONG) AS LONG
      LOCAL rc AS RECT
      GetWindowRect hwnd, rc
      IF bNoScale THEN
         PROPERTY = (rc.Right - rc.Left)
      ELSE
         ' // Divide by m_rx to make the result High DPI aware
         PROPERTY = (rc.Right - rc.Left) / m_rx
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the height of the window
   ' =====================================================================================
   PROPERTY GET ControlHeight (BYVAL hwnd AS DWORD, OPTIONAL BYVAL bNoScale AS LONG) AS LONG
      LOCAL rc AS RECT
      GetWindowRect hwnd, rc
      IF bNoScale THEN
         PROPERTY = (rc.Bottom - rc.Top)
      ELSE
         ' // Divide by m_rx to make the result High DPI aware
         PROPERTY = (rc.Bottom - rc.Top) / m_ry
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the client width of the specified window
   ' =====================================================================================
   PROPERTY GET ControlClientWidth (BYVAL hwnd AS DWORD, OPTIONAL BYVAL bNoScale AS LONG) AS LONG
      LOCAL rc AS RECT
      GetClientRect hwnd, rc
      IF bNoScale THEN
         PROPERTY = (rc.Right - rc.Left)
      ELSE
         ' // Divide by m_rx to make the result High DPI aware
         PROPERTY = (rc.Right - rc.Left) / m_rx
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the client height of the window
   ' =====================================================================================
   PROPERTY GET ControlClientHeight (BYVAL hwnd AS DWORD, OPTIONAL BYVAL bNoScale AS LONG) AS LONG
      LOCAL rc AS RECT
      GetClientRect hwnd, rc
      IF bNoScale THEN
         PROPERTY = (rc.Bottom - rc.Top)
      ELSE
         ' // Divide by m_rx to make the result High DPI aware
         PROPERTY = (rc.Bottom - rc.Top) / m_ry
      END IF
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Centers a window on the screen or over another window.
   ' It also ensures that the placement is done within the work area.
   ' Parameters:
   ' - hwnd = Handle of the window.
   ' - hwndParent = [optional] Handle of the parent window.
   ' =====================================================================================
   METHOD CenterWindow (OPTIONAL BYVAL hwnd AS DWORD, OPTIONAL BYVAL hwndParent AS DWORD)

      LOCAL rc            AS RECT    ' Window coordinates
      LOCAL nWidth        AS LONG    ' Width of the window
      LOCAL nHeight       AS LONG    ' Height of the window
      LOCAL rcParent      AS RECT    ' Parent window coordinates
      LOCAL nParentWidth  AS LONG    ' Width of the parent window
      LOCAL nParentHeight AS LONG    ' Height of the parent window
      LOCAL rcWorkArea    AS RECT    ' Work area coordinates
      LOCAL pt            AS POINT   ' x and y coordinates of centered window

      IF hwnd = 0 THEN hwnd = m_hwnd
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

      ' // Calculate the new y coordinate and adjust for work area
      pt.y = rcParent.nTop  + ((nParentHeight - nHeight) \ 2)
      IF (pt.y < rcWorkArea.nTop) THEN
         pt.y = rcWorkArea.nTop
      ELSEIF ((pt.y + nHeight) > rcWorkArea.nBottom) THEN
         pt.y = rcWorkArea.nBottom - nHeight
      END IF

      ' // Convert screen coordinates to client area coordinates
      IF (GetWindowLong(hwnd, %GWL_STYLE) AND %WS_CHILD) = %WS_CHILD THEN ScreenToClient hwndParent, pt

      ' // Reposition the window retaining its size and Z order
      SetWindowPos(hwnd, %NULL, pt.x, pt.y, 0, 0, %SWP_NOSIZE OR %SWP_NOZORDER)

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adjust the bounding rectangle of a window based on the desired size of the client area.
   ' =====================================================================================
   METHOD SetClientSize (BYVAL nWidth AS LONG, BYVAL nHeight AS LONG)

      LOCAL rc AS RECT
      LOCAL rcTemp AS RECT
      LOCAL hMenu AS DWORD
      LOCAL dwStyle AS DWORD
      LOCAL cx AS LONG
      LOCAL cy AS LONG

      ' // Convert the client rectangle to a window rectangle.
      ' // The AdjustWindowRectEx function cannot take menu wrapping into account
      ' // because it doesn't know which menu we are using.
      SetRect rc, 0, 0, nWidth * m_rx, nHeight * m_ry
      hMenu   = GetMenu(m_hwnd)
      dwStyle = GetWindowLong(m_hwnd, %GWL_STYLE)
      AdjustWindowRectEx rc, dwStyle, (hMenu <> %NULL), GetWindowLong(m_hwnd, %GWL_EXSTYLE)

     ' // If there is a menu, we need to check how much wrapping occurs when we set
     ' // the window to the width specified by AdjustWindowRectEX and an infinite
     ' // amount of height. An infinite height allows us to see every single menu wrap.

      IF ISTRUE hMenu THEN
         rcTemp = rc
         rcTemp.nBottom = &H7FFF   ' // "Infinite" height
         SendMessage m_hwnd, %WM_NCCALCSIZE, %FALSE, BYVAL VARPTR(rcTemp)
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
      SetWindowPos(m_hwnd, %NULL, 0, 0, cx, cy, %SWP_NOZORDER OR %SWP_NOMOVE OR %SWP_NOACTIVATE)

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Changes the size, position, and Z order of a child, pop-up, or top-level window.
   ' =====================================================================================
   METHOD SetWindowPos (BYVAL hwnd AS DWORD, BYVAL hwndInsertAfter AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, BYVAL cx AS LONG, BYVAL cy AS LONG, BYVAL uFlags AS DWORD, OPTIONAL BYVAL bNoScale AS LONG) AS LONG
      IF bNoScale THEN
         METHOD = SetWindowPos(hwnd, hwndInsertAfter, x, y, cx, cy, uFlags)
      ELSE
         METHOD = SetWindowPos(hwnd, hwndInsertAfter, x * m_rx, y * m_ry, cx * m_rx, cy * m_ry, uFlags)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Changes the position and dimensions of the specified window.
   ' =====================================================================================
   METHOD MoveWindow (BYVAL hwnd AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, BYVAL bRepaint AS LONG, OPTIONAL BYVAL bNoScale AS LONG) AS LONG
      IF bNoScale THEN
         METHOD = MoveWindow(hwnd, x, y, nWidth, nHeight, bRepaint)
      ELSE
         METHOD = MoveWindow(hwnd, x * m_rx, y * m_ry, nWidth * m_rx, nHeight * m_ry, bRepaint)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Processes window messages
   ' =====================================================================================
   METHOD DoEvents (OPTIONAL BYVAL nCmdShow AS LONG) AS LONG
      LOCAL uMsg AS tagMsg
      IF m_hwnd = %NULL THEN EXIT METHOD
      ' // Show the window and update its client area
      IF nCmdShow = 0 THEN ShowWindow m_hwnd, %SW_SHOW ELSE ShowWindow m_hwnd, nCmdShow
      UpdateWindow m_hwnd
      ' // Message loop
      WHILE GetMessage(uMsg, %NULL, 0, 0)
#IF %USEOLECON = 1
         ' Forwards the message to the OCX
         IF OC_ForwardMessage(GetFocus, uMsg) = 0 THEN
#ENDIF
#IF %USEMDI = 1
            ' Processes accelerator keystrokes for window menu command
            ' of the multiple document interface (MDI) child windows
            IF m_hwndClient = 0 OR TranslateMDISysAccel(m_hwndClient, uMsg) = 0 THEN
#ENDIF
               ' Processes accelerator keys for menu commands
               IF m_hAccel = 0 OR TranslateAccelerator(m_hwnd, m_hAccel, uMsg) = 0 THEN
#IF %USEDLGMSG = 1
                  ' Determines whether a message is intended for the specified
                  ' dialog box and, if it is, processes the message.
                  IF IsDialogMessage(m_hwnd, uMsg) = 0 THEN
                     ' Translates virtual-key messages into character messages.
                     TranslateMessage uMsg
                     ' Dispatches a message to a window procedure.
                     DispatchMessage uMsg
                  END IF
#ELSE
                  ' Translates virtual-key messages into character messages.
                  TranslateMessage uMsg
                  ' Dispatches a message to a window procedure.
                  DispatchMessage uMsg
#ENDIF
               END IF
#IF %USEMDI = 1
            END IF
#ENDIF
#IF %USEOLECON = 1
         END IF
#ENDIF
      WEND
      METHOD = uMsg.wParam
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the instance handle
   ' =====================================================================================
   PROPERTY GET hInstance () AS DWORD
      PROPERTY = m_hInstance
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the instance handle
   ' =====================================================================================
   PROPERTY SET hInstance (BYVAL hInstance AS DWORD)
      IF m_hInstance = %NULL THEN m_hInstance = hInstance
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the window handle
   ' =====================================================================================
   PROPERTY GET hwnd () AS DWORD
      PROPERTY = m_hwnd
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the window handle
   ' =====================================================================================
   PROPERTY SET hwnd (BYVAL hwnd AS DWORD)
      IF m_hwnd = %NULL THEN m_hwnd = hwnd
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the handle of the font used as default.
   ' =====================================================================================
   PROPERTY GET hFont () AS DWORD
      PROPERTY = m_hFont
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the handle of the font used as default.
   ' =====================================================================================
   PROPERTY SET hFont (BYVAL hFont AS DWORD)
      IF m_hFont THEN DeleteObject m_hFont
      m_hFont = hFont
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the name of the default font.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   PROPERTY GET DefaultFontName () AS WSTRING
#ELSE
   PROPERTY GET DefaultFontName () AS STRING
#ENDIF
      PROPERTY = m_szDefaultFontName
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the name of the default font.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   PROPERTY SET DefaultFontName (BYVAL strFontName AS WSTRING)
#ELSE
   PROPERTY SET DefaultFontName (BYVAL strFontName AS STRING)
#ENDIF
      m_szDefaultFontName = strFontName
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the size in points of the default font.
   ' =====================================================================================
   PROPERTY GET DefaultFontSize () AS LONG
      PROPERTY = m_DefaultFontSize
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the size in points of the default font.
   ' =====================================================================================
   PROPERTY SET DefaultFontSize (BYVAL nPointSize AS LONG)
      m_DefaultFontSize = nPointSize
   END PROPERTY
   ' =====================================================================================

   ' ========================================================================================
   ' Creates a High DPI aware logical font.
   ' Usage examples:
   '   hFont = CWindow.CreateFont("MS Sans Serif", 8, %FW_NORMAL, %FALSE, %FALSE, %FALSE, %DEFAULT_CHARSET)
   '   hFont = CWindow.CreateFont("Courier New", 10, %FW_BOLD, %FALSE, %FALSE, %FALSE, %DEFAULT_CHARSET)
   '   hFont = CWindow.CreateFont("Marlett", 8, %FW_NORMAL, %FALSE, %FALSE, %FALSE, %SYMBOL_CHARSET)
   ' Note: Any font created with CWindow.CreateFont must be destroyed with DeleteObject when no
   ' longer needed to prevent memory leaks.
   ' ========================================================================================
#IF %DEF(%UNICODE)
   METHOD CreateFont ( _
      BYVAL bstrFaceName AS WSTRING, _  ' __in Typeface name of font
      BYVAL lPointSize  AS LONG, _      ' __in Point size
      BYVAL lWeight     AS LONG, _      ' __in Font weight(bold etc.)
      BYVAL bItalic     AS BYTE, _      ' __in TRUE = italic
      BYVAL bUnderline  AS BYTE, _      ' __in TRUE = underline
      BYVAL bStrikeOut  AS BYTE, _      ' __in TRUE = strikeout
      BYVAL bCharSet    AS BYTE, _      ' __in character set
      OPTIONAL BYVAL bNoScale AS LONG _ ' __in_opt Boolean - No scale
      ) AS DWORD                        ' Handle of font or NULL on failure.

      LOCAL tlf AS LOGFONTW
      LOCAL hDC AS DWORD

      hDC = GetDC(%HWND_DESKTOP)

      ' // The result must be 1, unless the programmer has set a different DPI with SET DPI
      IF bNoScale = 0 THEN lPointSize = (lPointSize * m_DPI) \ GetDeviceCaps(hDC, %LOGPIXELSY)

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

      METHOD = CreateFontIndirectW(tlf)

   END METHOD
   ' ========================================================================================
#ELSE
   ' ========================================================================================
   METHOD CreateFont ( _
      BYVAL strFaceName AS STRING, _    ' __in Typeface name of font
      BYVAL lPointSize  AS LONG, _      ' __in Point size
      BYVAL lWeight     AS LONG, _      ' __in Font weight(bold etc.)
      BYVAL bItalic     AS BYTE, _      ' __in TRUE = italic
      BYVAL bUnderline  AS BYTE, _      ' __in TRUE = underline
      BYVAL bStrikeOut  AS BYTE, _      ' __in TRUE = strikeout
      BYVAL bCharSet    AS BYTE, _      ' __in character set
      OPTIONAL BYVAL bNoScale AS LONG _ ' __in_opt Boolean - No scale
      ) AS DWORD                        ' Handle of font or NULL on failure.

      LOCAL tlf AS LOGFONTA
      LOCAL hDC AS DWORD

      hDC = GetDC(%HWND_DESKTOP)

      ' // The result must be 1, unless the programmer has set a different DPI with SET DPI
      IF bNoScale = 0 THEN lPointSize = (lPointSize * m_DPI) \ GetDeviceCaps(hDC, %LOGPIXELSY)

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

      METHOD = CreateFontIndirectA(tlf)

   END METHOD
   ' ========================================================================================
#ENDIF

   ' =====================================================================================
   ' Creates a High DPI aware logical font and sets it as the default font.
   ' Usage examples:
   '   CWindow.SetFont("MS Sans Serif", 8, %FW_NORMAL, %FALSE, %FALSE, %FALSE, %DEFAULT_CHARSET)
   '   CWindow.SetFont("Courier New", 10, %FW_BOLD, %FALSE, %FALSE, %FALSE, %DEFAULT_CHARSET)
   '   CWindow.SetFont("Marlett", 8, %FW_NORMAL, %FALSE, %FALSE, %FALSE, %SYMBOL_CHARSET)
   ' Return Value = S_OK or %E_FAIL
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD SetFont ( _
      BYVAL bstrFaceName AS WSTRING, _  ' __in Typeface name of font
      BYVAL lPointSize  AS LONG, _      ' __in Point size
      BYVAL lWeight     AS LONG, _      ' __in Font weight(bold etc.)
      BYVAL bItalic     AS BYTE, _      ' __in TRUE = italic
      BYVAL bUnderline  AS BYTE, _      ' __in TRUE = underline
      BYVAL bStrikeOut  AS BYTE, _      ' __in TRUE = strikeout
      BYVAL bCharSet    AS BYTE, _      ' __in character set
      OPTIONAL BYVAL bNoScale AS LONG _ ' __in_opt Boolean - No scale
      ) AS LONG                         ' HRESULT

      LOCAL hFont AS DWORD
      LOCAL tlf AS LOGFONTW
      LOCAL hDC AS DWORD

      hDC = GetDC(%HWND_DESKTOP)

      IF bNoScale = 0 THEN lPointSize = (lPointSize * m_DPI) \ GetDeviceCaps(hDC, %LOGPIXELSY)

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
      hFont = CreateFontIndirectW(tlf)
      IF hFont THEN
         IF m_hFont THEN DeleteObject m_hFont
         m_hFont = hFont
      ELSE
         METHOD OBJRESULT = %E_FAIL
      END IF

   END METHOD
   ' =====================================================================================
#ELSE
   METHOD SetFont ( _
      BYVAL strFaceName AS STRING, _    ' __in Typeface name of font
      BYVAL lPointSize  AS LONG, _      ' __in Point size
      BYVAL lWeight     AS LONG, _      ' __in Font weight(bold etc.)
      BYVAL bItalic     AS BYTE, _      ' __in TRUE = italic
      BYVAL bUnderline  AS BYTE, _      ' __in TRUE = underline
      BYVAL bStrikeOut  AS BYTE, _      ' __in TRUE = strikeout
      BYVAL bCharSet    AS BYTE, _      ' __in character set
      OPTIONAL BYVAL bNoScale AS LONG _ ' __in_opt Boolean - No scale
      ) AS LONG                         ' HRESULT

      LOCAL hFont AS DWORD
      LOCAL tlf AS LOGFONTA
      LOCAL hDC AS DWORD

      hDC = GetDC(%HWND_DESKTOP)

      IF bNoScale = 0 THEN lPointSize = (lPointSize * m_DPI) \ GetDeviceCaps(hDC, %LOGPIXELSY)

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
      hFont = CreateFontIndirectA(tlf)
      IF hFont THEN
         IF m_hFont THEN DeleteObject m_hFont
         m_hFont = hFont
      ELSE
         METHOD OBJRESULT = %E_FAIL
      END IF

   END METHOD
   ' =====================================================================================
#ENDIF

   ' =====================================================================================
   ' Associates a new large icon with the main window. The system displays the large icon
   ' in the ALT+TAB dialog box.
   ' Parameters:
   ' - hIcon = Handle to the new large icon.
   '   If this parameter is NULL, the icon is removed.
   ' =====================================================================================
   PROPERTY SET BigIcon (BYVAL hIcon AS DWORD)
      SendMessage(m_hwnd, %WM_SETICON, %ICON_BIG, hIcon)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Associates a new small icon with the main window. The system displays the small icon
   ' in the in the window caption.
   ' Parameters:
   ' - hIcon = Handle to the new small icon.
   '   If this parameter is NULL, the icon is removed.
   ' =====================================================================================
   PROPERTY SET SmallIcon (BYVAL hIcon AS DWORD)
      SendMessage(m_hwnd, %WM_SETICON, %ICON_SMALL, hIcon)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves a value from the user data area of a CWindow.
   ' idx = The index number of the user data value to retrieve, in the range 0 to 9 inclusive.
   ' =====================================================================================
   PROPERTY GET UserData (BYVAL idx AS LONG) AS LONG
      IF idx < 0 OR idx > 9 THEN EXIT PROPERTY
      PROPERTY = m_rgUserData(idx)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Set a value in the user data area of a CWindow.
   ' idx = The index number of the user data value to retrieve, in the range 0 to 9 inclusive.
   ' =====================================================================================
   PROPERTY SET UserData (BYVAL idx AS LONG, BYVAL newValue AS LONG)
      IF idx < 0 OR idx > 9 THEN EXIT PROPERTY
      m_rgUserData(idx) = newValue
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the window-class style bits.
   ' =====================================================================================
   PROPERTY GET ClassStyle () AS DWORD
      IF m_hwnd = %NULL THEN EXIT PROPERTY
      PROPERTY = GetClassLong(m_hwnd, %GCL_STYLE)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the window-class style bits.
   ' =====================================================================================
   PROPERTY SET ClassStyle (BYVAL dwStyle AS DWORD)
      IF m_hwnd = %NULL THEN EXIT PROPERTY
      SetClassLong m_hwnd, %GCL_STYLE, dwStyle
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the background brush.
   ' =====================================================================================
   PROPERTY GET Brush () AS DWORD
      IF m_hwnd = %NULL THEN EXIT PROPERTY
      PROPERTY = GetClassLong(m_hwnd, %GCL_HBRBACKGROUND)
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the background brush.
   ' Handle to the class background brush. This member can be a handle to the physical
   ' brush to be used for painting the background, or it can be a color value. A color
   ' value must be one of the standard system colors (the value 1 must be added
   ' to the chosen color), e.g. %COLOR_WINDOW + 1
   ' =====================================================================================
   PROPERTY SET Brush (BYVAL hbrBackground AS DWORD)
      IF m_hwnd = %NULL THEN EXIT PROPERTY
      SetClassLong m_hwnd, %GCL_HBRBACKGROUND, hbrBackground
      InvalidateRect m_hwnd, BYVAL %NULL, %TRUE
      UpdateWindow m_hwnd
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Determines whether the current process is dots per inch (dpi) aware such that it adjusts
   ' the sizes of UI elements to compensate for the dpi setting.
   ' =====================================================================================
   METHOD IsProcessDPIAware () AS LONG
      LOCAL bRes AS LONG
      LOCAL hLib AS DWORD
      LOCAL pProc AS DWORD
      hLib = LoadLibraryW("user32.dll")
      IF hLib = 0 THEN EXIT METHOD
      pProc = GetProcAddress(hLib, "IsProcessDPIAware")
      IF pProc THEN CALL DWORD pProc USING CWindow_IsProcessDPIAware() TO bRes
      FreeLibrary hLib
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the current process as dots per inch (dpi) aware.
   ' Note SetProcessDPIAware is subject to a possible race condition if a DLL caches dpi
   ' settings during initialization. For this reason, it is recommended that dpi-aware be set
   ' through the application (.exe) manifest rather than by calling SetProcessDPIAware.
   ' =====================================================================================
   METHOD SetProcessDPIAware () AS LONG
      LOCAL bRes AS LONG
      LOCAL hLib AS DWORD
      LOCAL pProc AS DWORD
      hLib = LoadLibraryW("user32.dll")
      IF hLib = 0 THEN EXIT METHOD
      pProc = GetProcAddress(hLib, "SetProcessDPIAware")
      IF pProc THEN CALL DWORD pProc USING CWindow_SetProcessDPIAware() TO bRes
      FreeLibrary hLib
      METHOD = bRes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the DPI (dots per pixel) used at design-time.
   ' =====================================================================================
   PROPERTY GET DPI () AS SINGLE
      PROPERTY = m_DPI
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the DPI (dots per pixel) to be used by the application.
   ' Pass -1 to use the value returned by the GetDeviceCaps API function.
   ' Note: Set this value if you want to make your application High-DPI aware.
   ' The main window, controls and fonts will be scaled if the user changes the DPI setting.
   ' =====================================================================================
   PROPERTY SET DPI (BYVAL dpi AS SINGLE)
      LOCAL hDC AS DWORD
      m_DPI = dpi
      ' // Get the screen device context
      hDC = GetDC(%NULL)
      IF m_DPI < 0 THEN
         m_DPI = GetDeviceCaps(hDC, %LOGPIXELSX)
         dpi = m_DPI
      END IF
      ' // Resolution ratio = current resolution / 96
      IF dpi < 0 THEN
         m_rx = (GetDeviceCaps(hDC, %LOGPIXELSX) / 96)
         m_ry = (GetDeviceCaps(hDC, %LOGPIXELSY) / 96)
      ELSE
         m_rx = dpi / 96
         m_ry = dpi / 96
      END IF
      ReleaseDC %NULL, hDC
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the horizontal scaling ratio
   ' =====================================================================================
   PROPERTY GET rxRatio () AS SINGLE
      PROPERTY = m_rx
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the horizontal scaling ratio
   ' =====================================================================================
   PROPERTY SET rxRatio (BYVAL rx AS SINGLE)
      m_rx = rx
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the vertical scaling ratio
   ' =====================================================================================
   PROPERTY GET ryRatio () AS SINGLE
      PROPERTY = m_ry
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the vertical scaling ratio
   ' =====================================================================================
   PROPERTY SET ryRatio (BYVAL ry AS SINGLE)
      m_ry = ry
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a control to the window
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddControl ( _
      BYVAL strClassName AS WSTRING, _      ' // Class name
      BYVAL hParent AS DWORD, _             ' // Parent window handle
      BYVAL cID AS LONG, _                  ' // Control identifier
      BYVAL strTitle AS WSTRING, _          ' // Control caption
      BYVAL x AS LONG, _                    ' // Horizontal position
      BYVAL y AS LONG, _                    ' // Vertical position
      BYVAL nWidth AS LONG, _               ' // Control width
      BYVAL nHeight AS LONG, _              ' // Control height
      BYVAL dwStyle AS DWORD, _             ' // Control style
      OPTIONAL BYVAL dwExStyle AS DWORD, _  ' // Extended style
      OPTIONAL BYVAL lpParam AS DWORD, _    ' // Pointer to custom data
      OPTIONAL BYVAL pWndProc AS DWORD, _   ' // Address of the window callback procedure
      OPTIONAL BYVAL bNoScale AS LONG _     ' // Boolean - No scale
      ) AS DWORD                            ' // Control handle
#ELSE
   METHOD AddControl ( _
      BYVAL strClassName AS STRING, _       ' // Class name
      BYVAL hParent AS DWORD, _             ' // Parent window handle
      BYVAL cID AS LONG, _                  ' // Control identifier
      BYVAL strTitle AS STRING, _           ' // Control caption
      BYVAL x AS LONG, _                    ' // Horizontal position
      BYVAL y AS LONG, _                    ' // Vertical position
      BYVAL nWidth AS LONG, _               ' // Control width
      BYVAL nHeight AS LONG, _              ' // Control height
      BYVAL dwStyle AS DWORD, _             ' // Control style
      OPTIONAL BYVAL dwExStyle AS DWORD, _  ' // Extended style
      OPTIONAL BYVAL lpParam AS DWORD, _    ' // Pointer to custom data
      OPTIONAL BYVAL pWndProc AS DWORD, _   ' // Address of the window callback procedure
      OPTIONAL BYVAL bNoScale AS LONG _     ' // Boolean - No scale
      ) AS DWORD                            ' // Control handle
#ENDIF
      LOCAL hCtl AS DWORD
      IF hParent = 0 THEN hParent = m_hwnd
      IF BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      ' // Create the control
      IF bNoScale THEN
         hCtl = CreateWindowEx(dwExStyle, BYCOPY strClassName, BYCOPY strTitle, _
                dwStyle, x, y, nWidth, nHeight, _
                hParent, cID, m_hInstance, BYVAL lpParam)
      ELSE
         hCtl = CreateWindowEx(dwExStyle, BYCOPY strClassName, BYCOPY strTitle, _
                dwStyle, x * m_rx, y * m_ry, nWidth * m_rx, nHeight * m_ry, _
                hParent, cID, m_hInstance, BYVAL lpParam)
      END IF
      IF hCtl = %NULL THEN EXIT METHOD
      ' // Subclass the control if pWndProc is not null
      IF pWndProc <> %NULL THEN SetProp hCtl, "OLDWNDPROC", SetWindowLong(hCtl, %GWL_WNDPROC, pWndProc)
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a button to the window
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddButton (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddButton (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP OR %BS_PUSHBUTTON OR %BS_CENTER OR %BS_VCENTER
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Shortcut for standard flat button (allows to simply pass %BS_FLAT)
      IF dwStyle = %BS_FLAT THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP OR %BS_PUSHBUTTON OR %BS_CENTER OR %BS_VCENTER OR %BS_FLAT
      IF dwStyle = %BS_DEFPUSHBUTTON THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP OR %BS_CENTER OR %BS_VCENTER OR %BS_DEFPUSHBUTTON
      IF dwStyle = %BS_SPLITBUTTON THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP OR %BS_CENTER OR %BS_VCENTER OR %BS_SPLITBUTTON
      IF dwStyle = %BS_DEFSPLITBUTTON THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP OR %BS_CENTER OR %BS_VCENTER OR %BS_DEFSPLITBUTTON
      IF dwStyle = %BS_OWNERDRAW THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP OR %BS_OWNERDRAW
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("Button", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a frame to the window.
   ' Note: This is not the same that DDT's Frame control, that in fact is a Group Box.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddFrameWindow (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddFrameWindow (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_CLIPSIBLINGS OR %WS_GROUP OR %SS_BLACKFRAME
      IF dwExStyle = 0 OR BITS(LONG, dwExStyle) = -1 THEN dwExStyle = %WS_EX_TRANSPARENT
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("Static", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a text label to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddLabel (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddLabel (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %SS_LEFT OR %WS_GROUP OR %SS_NOTIFY
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("Static", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds an image label to the window.
   ' You must delete the bitmap before the application ends.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddBitmapLabel (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strImage AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddBitmapLabel (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strImage AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_GROUP OR %SS_BITMAP
      IF dwExStyle = 0 OR BITS(LONG, dwExStyle) = -1 THEN dwExStyle = %WS_EX_TRANSPARENT
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("Static", hParent, cID, strImage, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      ' // Loads the image
      LOCAL hImage AS DWORD, wID AS WORD, dwID AS DWORD
      IF LEFT$(strImage, 1) = "#" THEN
         wID = VAL(MID$(strImage, 2))
         dwID = MAK(DWORD, wID, 0)
         hImage = LoadImage(m_hInstance, BYVAL dwID, %IMAGE_BITMAP, 0, 0, %LR_DEFAULTCOLOR)
      ELSE
         hImage = LoadImage(m_hInstance, BYCOPY strImage, %IMAGE_BITMAP, 0, 0, %LR_DEFAULTCOLOR)
      END IF
      IF hImage THEN SendMessage(hCtl, %STM_SETIMAGE, %IMAGE_BITMAP, hImage)
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds an image label to the window
   ' You must delete the icon before the application ends.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddIconLabel (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strImage AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddIconLabel (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strImage AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_GROUP OR %SS_ICON
      IF dwExStyle = 0 OR BITS(LONG, dwExStyle) = -1 THEN dwExStyle = %WS_EX_TRANSPARENT
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("Static", hParent, cID, strImage, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      ' // Loads the image
      LOCAL hImage AS DWORD, wID AS WORD, dwID AS DWORD
      IF LEFT$(strImage, 1) = "#" THEN
         wID = VAL(MID$(strImage, 2))
         dwID = MAK(DWORD, wID, 0)
         hImage = LoadImage(m_hInstance, BYVAL dwID, %IMAGE_ICON, 0, 0, %LR_DEFAULTCOLOR)
      ELSE
         hImage = LoadImage(m_hInstance, BYCOPY strImage, %IMAGE_ICON, 0, 0, %LR_DEFAULTCOLOR)
      END IF
      IF hImage THEN SendMessage(hCtl, %STM_SETIMAGE, %IMAGE_ICON, hImage)
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a custom label to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddCustomLabel (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddCustomLabel (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_GROUP OR %SS_OWNERDRAW
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("Static", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds an horizontal line to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddLine (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddLine (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %SS_ETCHEDFRAME
      IF dwExStyle = 0 OR BITS(LONG, dwExStyle) = -1 THEN dwExStyle = %WS_EX_TRANSPARENT
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("Static", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a text box to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddTextBox (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddTextBox (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP OR %ES_LEFT OR %ES_AUTOHSCROLL
      IF dwExStyle = 0 OR BITS(LONG, dwExStyle) = -1 THEN dwExStyle = %WS_EX_CLIENTEDGE
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("Edit", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a group box to the window.
   ' Note: This is the same that DDT's frame control.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddGroupBox (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddGroupBox (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_CLIPSIBLINGS OR %WS_GROUP OR %BS_GROUPBOX
      IF dwExStyle = 0 OR BITS(LONG, dwExStyle) = -1 THEN dwExStyle = %WS_EX_TRANSPARENT
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("Button", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a bitmap image button to the window.
   ' You must delete the bitmap before the application ends.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddBitmapButton (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strImage AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddBitmapButton (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strImage AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP OR %BS_PUSHBUTTON OR %BS_BITMAP
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("Button", hParent, cID, strImage, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      ' // Loads the image
      LOCAL hImage AS DWORD, wID AS WORD, dwID AS DWORD
      IF LEFT$(strImage, 1) = "#" THEN
         wID = VAL(MID$(strImage, 2))
         dwID = MAK(DWORD, wID, 0)
         hImage = LoadImage(m_hInstance, BYVAL dwID, %IMAGE_BITMAP, 0, 0, %LR_DEFAULTCOLOR)
      ELSE
         hImage = LoadImage(m_hInstance, BYCOPY strImage, %IMAGE_BITMAP, 0, 0, %LR_DEFAULTCOLOR)
      END IF
      IF hImage THEN SendMessage(hCtl, %BM_SETIMAGE, %IMAGE_BITMAP, hImage)
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a icon image button to the window
   ' You must destroy the icon before the application ends.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddIconButton (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strImage AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddIconButton (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strImage AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP OR %BS_PUSHBUTTON OR %BS_ICON
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("Button", hParent, cID, strImage, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      ' // Loads the image
      LOCAL hImage AS DWORD, wID AS WORD, dwID AS DWORD
      IF LEFT$(strImage, 1) = "#" THEN
         wID = VAL(MID$(strImage, 2))
         dwID = MAK(DWORD, wID, 0)
         hImage = LoadImage(m_hInstance, BYVAL dwID, %IMAGE_ICON, 0, 0, %LR_DEFAULTCOLOR)
      ELSE
         hImage = LoadImage(m_hInstance, BYCOPY strImage, %IMAGE_ICON, 0, 0, %LR_DEFAULTCOLOR)
      END IF
      IF hImage THEN SendMessage(hCtl, %BM_SETIMAGE, %IMAGE_ICON, hImage)
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a custom (ownerdraw) button to the window
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddCustomButton (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddCustomButton (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP OR %BS_OWNERDRAW
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("Button", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a check box to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddCheckBox (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddCheckBox (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP OR %BS_AUTOCHECKBOX OR %BS_LEFT OR %BS_VCENTER
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("Button", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a radio button to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddRadioButton (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddRadioButton (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP OR %BS_AUTORADIOBUTTON OR %BS_LEFT OR %BS_VCENTER
      IF dwStyle = %WS_GROUP THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP OR %BS_AUTORADIOBUTTON OR %BS_LEFT OR %BS_VCENTER OR %WS_GROUP
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("Button", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a combo box to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddComboBox (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddComboBox (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_CHILD OR %WS_VISIBLE OR %WS_VSCROLL OR %WS_BORDER OR %WS_TABSTOP OR %CBS_DROPDOWN OR %CBS_HASSTRINGS OR %CBS_SORT
      IF dwExStyle = 0 OR BITS(LONG, dwExStyle) = -1 THEN dwExStyle = %WS_EX_CLIENTEDGE
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("Combobox", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a combo box ex to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddComboBoxEx (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddComboBoxEx (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_BORDER OR %WS_TABSTOP OR %CBS_DROPDOWNLIST
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("ComboboxEx32", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a list box to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddListBox (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddListBox (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_HSCROLL OR %WS_VSCROLL OR %WS_BORDER OR %WS_TABSTOP OR %LBS_STANDARD OR %LBS_HASSTRINGS OR %LBS_SORT OR %LBS_NOTIFY
      IF dwExStyle = 0 OR BITS(LONG, dwExStyle) = -1 THEN dwExStyle = %WS_EX_CLIENTEDGE
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("Listbox", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      ' // Adjust the height of the control so that the integral height
      ' // is based on the new font rather than the default SYSTEM_FONT
      IF bNoScale THEN
         SetWindowPos hCtl, %NULL, x, y, nWidth, nHeight, %SWP_NOZORDER
      ELSE
         SetWindowPos hCtl, %NULL, x * m_rx, y * m_ry, nWidth * m_rx, nHeight * m_ry, %SWP_NOZORDER
      END IF
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds an horizontal scroll bar to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddHScrollBar (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddHScrollBar (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      LOCAL tsi AS SCROLLINFO
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP OR %SBS_HORZ
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("Scrollbar", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      ' // Initialize the scroll bar with default values
      tsi.cbSize = SIZEOF(tsi)
      tsi.fMask  = %SIF_PAGE OR %SIF_POS OR %SIF_RANGE
      tsi.nMin   = 0
      tsi.nMax   = 100
      tsi.nPage  = 0
      tsi.nPos   = 0
      SetScrollInfo hCtl, %SB_CTL, tsi, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a vertical scroll bar to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddVScrollBar (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddVScrollBar (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      LOCAL tsi AS SCROLLINFO
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP OR %SBS_VERT
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("Scrollbar", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      ' // Initialize the scroll bar with default values
      tsi.cbSize = SIZEOF(tsi)
      tsi.fMask  = %SIF_PAGE OR %SIF_POS OR %SIF_RANGE
      tsi.nMin   = 0
      tsi.nMax   = 100
      tsi.nPage  = 0
      tsi.nPos   = 0
      SetScrollInfo hCtl, %SB_CTL, tsi, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a size box to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddSizeBox (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddSizeBox (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %SBS_SIZEGRIP OR %SBS_SIZEBOXBOTTOMRIGHTALIGN
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("Scrollbar", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a track bar to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddTrackBar (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddTrackBar (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP OR %TBS_AUTOTICKS OR %TBS_HORZ OR %TBS_BOTTOM
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("msctls_trackbar32", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      ' // Set the default range values
      SendMessage hCtl, %TBM_SETRANGEMIN, %TRUE, 0
      SendMessage hCtl, %TBM_SETRANGEMAX, %TRUE, 100
      ' // Set the default page size
      SendMessage hCtl, %TBM_SETPAGESIZE, 0, 10
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds an up down control to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddUpDown (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddUpDown (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("msctls_updown32", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      ' // Set the default base
      SendMessage hCtl, %UDM_SETBASE, 10, 0
      ' // Set the default range values
      SendMessage hCtl, %UDM_SETRANGE32, 100, 0
      ' // Set the default initial value
      SendMessage hCtl, %UDM_SETPOS32, 0, 0
      ' // Correct for Windows using a default size for the updown control
      IF bNoScale THEN
         SetWindowPos hCtl, %NULL, x, y, nWidth, nHeight, %SWP_NOZORDER
      ELSE
         SetWindowPos hCtl, %NULL, x * m_rx, y * m_ry, nWidth * m_rx, nHeight * m_ry, %SWP_NOZORDER
      END IF
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a progress bar to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddProgressBar (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddProgressBar (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("msctls_progress32", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      ' // Set the default range
      SendMessage hCtl, %PBM_SETRANGE32, 0, 100
      ' // Set the default initial value
      SendMessage hCtl, %PBM_SETPOS, 0, 0
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a tool bar to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddToolBar (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddToolBar (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_CLIPCHILDREN OR %WS_CLIPSIBLINGS OR %CCS_TOP
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("ToolbarWindow32", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
'      SendMessage hCtl, %TB_AUTOSIZE, 0, 0
      ' // Set the button size
      LOCAL nButtonWidth AS LONG
      LOCAL nButtonHeight AS LONG
'      IF m_DPI < 144 THEN bNoScale = %TRUE
      IF bNoScale THEN
         nButtonWidth = LO(WORD, SendMessage(hCtl, %TB_GETBUTTONSIZE, 0, 0))
         nButtonHeight = HI(WORD, SendMessage(hCtl, %TB_GETBUTTONSIZE, 0, 0))
      ELSE
         nButtonWidth = LO(WORD, SendMessage(hCtl, %TB_GETBUTTONSIZE, 0, 0)) * m_rx
         nButtonHeight = HI(WORD, SendMessage(hCtl, %TB_GETBUTTONSIZE, 0, 0)) * m_ry
      END IF
      SendMessage hCtl, %TB_SETBUTTONSIZE, 0, MAK(LONG, nButtonWidth, nButtonHeight)
      ' // Send this message for backward compatibility
      SendMessage hCtl, %TB_BUTTONSTRUCTSIZE, SIZEOF(TBBUTTON), 0
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds an status bar to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddStatusBar (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddStatusBar (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_CLIPCHILDREN OR %WS_CLIPSIBLINGS OR %CCS_BOTTOM OR %SBARS_SIZEGRIP
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("msctls_statusbar32", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the size of the parts of an status bar.
   ' strSizes = Comma delited string of desired sizes, e.g.:  strSizes = "90,34,42,184"
   ' creates 4 parts of 90, 34, 42 and 184 pixels, and strSizes = "90,34,42,184,-1" creates
   ' 5 parts, the last one extending until the right border of the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD SetStatusbarPartsBySize (BYVAL hStatusBar AS DWORD, BYVAL strSizes AS WSTRING, OPTIONAL BYVAL bNoScale AS LONG) AS LONG
#ELSE
   METHOD SetStatusbarPartsBySize (BYVAL hStatusBar AS DWORD, BYVAL strSizes AS STRING, OPTIONAL BYVAL bNoScale AS LONG) AS LONG
#ENDIF

      LOCAL nParts AS LONG
      LOCAL X AS LONG
      LOCAL Y AS LONG

      nParts = MAX(PARSECOUNT(strSizes),1)
      IF nParts < 2 THEN
         METHOD = SendMessage(hStatusBar, %SB_SIMPLE, (nParts = 1), 0)
         EXIT METHOD
      END IF

      DIM Part(1 TO nParts) AS LOCAL LONG

      FOR X = 1 TO nParts
         Y = VAL(PARSE$(strSizes, ",", X))
         IF X = 1 THEN
            IF bNoScale THEN
               Part(X) = Y
            ELSE
               Part(X) = Y * m_ry
            END IF
         ELSE
            IF Y < 1 THEN
               Part(X) = -1
            ELSE
               IF bNoScale THEN
                  Part(X) = Part(X - 1) + Y
               ELSE
                  Part(X) = Part(X - 1) + (Y * m_ry)
               END IF
            END IF
         END IF
      NEXT

      IF SendMessage(hStatusBar, %SB_SETPARTS, nParts, VARPTR(Part(1))) <> 0 THEN
         METHOD = SendMessage(hStatusBar, %SB_SIMPLE, (nParts = 1), 0)
      END IF

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a tab control to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddTab (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddTab (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_GROUP OR %WS_TABSTOP OR %WS_CLIPCHILDREN OR %WS_CLIPSIBLINGS OR %TCS_TABS OR %TCS_SINGLELINE OR %TCS_RAGGEDRIGHT
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      dwExStyle =  dwExStyle OR %WS_EX_CONTROLPARENT
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("SysTabControl32", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Internal method.
   ' Sets the value of the tab page object pointer for later comparison.
   ' =====================================================================================
   PROPERTY SET TabPagePtr (BYVAL dwPtr AS DWORD)
      m_TabPagePtr = dwPtr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a tab page and creates a generic window that will be associated with the page.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD InsertTabPage (BYVAL hTab AS DWORD, BYVAL nPage AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL nImage AS LONG, OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD) AS IWindow
#ELSE
   METHOD InsertTabPage (BYVAL hTab AS DWORD, BYVAL nPage AS LONG, BYVAL strTitle AS STRING, _
      BYVAL nImage AS LONG, OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD) AS IWindow
#ENDIF

      LOCAL x, y, nWidth, nHeight, cItems AS LONG, hTabPage AS DWORD
      LOCAL rc AS RECT, tci AS TCITEM
      LOCAL pTabPage AS IWindow

      IF ISFALSE IsWindow(hTab) THEN EXIT METHOD
      IF pWndProc = %NULL THEN pWndProc = GetClassLong(m_hwnd, %GCL_WNDPROC)

      IF dwStyle = 0 THEN dwStyle = %WS_CLIPSIBLINGS OR %WS_CLIPCHILDREN
      dwStyle = dwStyle OR %WS_CHILD
      dwExStyle = dwExStyle OR %WS_EX_CONTROLPARENT
      pTabPage = CLASS "CWindow"
      IF ISNOTHING(pTabPage) THEN EXIT METHOD
      pTabPage.ClassStyle = %CS_DBLCLKS
      pTabPage.DPI = m_DPI   ' // Use the same DPI as the main window

      cItems = SendMessage(hTab, %TCM_GETITEMCOUNT, 0, 0)
      IF nPage < 0 OR nPage > cItems THEN nPage = cItems
      tci.mask    = %TCIF_TEXT OR %TCIF_IMAGE OR %TCIF_PARAM
      tci.pszText = STRPTR(strTitle)
      tci.iImage  = nImage
      tci.lParam  = OBJPTR(pTabPage)
      SendMessage hTab, %TCM_INSERTITEM, nPage, VARPTR(tci)
      pTabPage.TabPagePtr = OBJPTR(pTabPage)
      GetWindowRect hTab, rc
      SendMessage hTab, %TCM_ADJUSTRECT, %FALSE, VARPTR(rc)
#IF %DEF(%USEPBDECL)
      MapWindowPoints %NULL, hTab, BYVAL VARPTR(rc), 2
#ELSE
      MapWindowPoints %NULL, hTab, rc, 2
#ENDIF
      x = rc.nLeft
      y = rc.nTop
      nWidth  = MAX(1, rc.nRight - rc.nLeft)
      nHeight = MAX(1, rc.nBottom - rc.nTop)

      hTabPage = pTabPage.CreateWindow(hTab, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, pWndProc, %TRUE)

      METHOD = pTabPage

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds an header control to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddHeader (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddHeader (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %CCS_TOP OR %HDS_HORZ OR %HDS_BUTTONS
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("SysHeader32", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a tree view control to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddTreeView (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddTreeView (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_BORDER OR %WS_TABSTOP OR %TVS_HASBUTTONS OR %TVS_HASLINES OR %TVS_LINESATROOT OR %TVS_SHOWSELALWAYS
      IF dwExStyle = 0 OR BITS(LONG, dwExStyle) = -1 THEN dwExStyle = %WS_EX_CLIENTEDGE
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("SysTreeView32", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a list view control to the window
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddListView (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddListView (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_CLIPCHILDREN OR %WS_TABSTOP OR %LVS_REPORT OR %LVS_SHOWSELALWAYS OR %LVS_SHAREIMAGELISTS OR %LVS_AUTOARRANGE OR %LVS_EDITLABELS OR %LVS_ALIGNTOP
      IF dwExStyle = 0 OR BITS(LONG, dwExStyle) = -1 THEN dwExStyle = %WS_EX_CLIENTEDGE
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("SysListView32", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a rebar control to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddRebar (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddRebar (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_BORDER OR %WS_CLIPCHILDREN OR %WS_CLIPSIBLINGS OR %CCS_NOPARENTALIGN OR %CCS_NODIVIDER OR %RBS_BANDBORDERS
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("ReBarWindow32", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a rebar control with an embedded toolbar to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddToolbarRebar (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL hToolbar AS DWORD, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddToolbarRebar (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL hToolbar AS DWORD, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_BORDER OR %WS_CLIPCHILDREN OR %WS_CLIPSIBLINGS OR %CCS_NODIVIDER OR %RBS_AUTOSIZE
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("ReBarWindow32", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      ' // Make sure the toolbar has the right styles
      SetWindowLong hToolbar, %GWL_STYLE, GetWindowLong(hToolbar, %GWL_STYLE) OR %CCS_NODIVIDER OR %CCS_NORESIZE OR %CCS_NOPARENTALIGN
      ' // The size of the REBARBANDINFO is different in Vista/Windows 7
      LOCAL trbbi AS REBARBANDINFO
      IF AfxGetWindowsVersion => 6.00 AND AfxGetComCtlVersion => 6.00 THEN
         trbbi.cbSize  = %REBARBANDINFO_V6_SIZE
      ELSE
         trbbi.cbSize  = %REBARBANDINFO_V3_SIZE
      END IF
      trbbi.fMask      = %RBBIM_STYLE OR %RBBIM_CHILD OR %RBBIM_CHILDSIZE OR _
                         %RBBIM_SIZE OR %RBBIM_ID OR %RBBIM_IDEALSIZE
      trbbi.fStyle     = %RBBS_CHILDEDGE ' OR %RBBS_GRIPPERALWAYS
      trbbi.hwndChild  = hToolbar
      trbbi.cxMinChild = 0
      trbbi.cyMinChild = HI(WORD, SendMessage(hToolBar, %TB_GETBUTTONSIZE, 0, 0))
      trbbi.cx         = ME.ClientWidth
      trbbi.wID        = 0
      trbbi.cxIdeal    = ME.ClientWidth
      SendMessage (hCtl, %RB_INSERTBAND, -1, VARPTR(trbbi))
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a date time picker control to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddDateTimePicker (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddDateTimePicker (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP OR %DTS_SHORTDATEFORMAT
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("SysDateTimePick32", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      SendMessage hCtl, %DTM_SETMCFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a month calendar control to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddMonthCalendar (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddMonthCalendar (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP
      IF dwExStyle = 0 OR BITS(LONG, dwExStyle) = -1 THEN dwExStyle = %WS_EX_CLIENTEDGE
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("SysMonthCal32", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds an IPAddress control to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddIPAddress (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddIPAddress (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP
      IF dwExStyle = 0 OR BITS(LONG, dwExStyle) = -1 THEN dwExStyle = %WS_EX_CLIENTEDGE
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("SysIPAddress32", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds an hotkey control to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddHotKey (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddHotKey (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP
      IF dwExStyle = 0 OR BITS(LONG, dwExStyle) = -1 THEN dwExStyle = %WS_EX_CLIENTEDGE
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("msctls_hotkey32", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds an animation control to the window
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddAnimation (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddAnimation (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %ACS_TRANSPARENT
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("SysAnimate32", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a SysLink control to the window.
   ' Note: The SysLink control is defined in the ComCtl32.dll version 6 and requires a
   ' manifest or directive that specifies that version 6 of the DLL should be used if it
   ' is available.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddSysLink (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strText AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddSysLink (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strText AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("SysLink", hParent, cID, strText, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds a Pager control to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddPager (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddPager (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("SysPager", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

#IF %USERICHEDIT = 1
   ' =====================================================================================
   ' Adds a rich edit control to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddRichEdit (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddRichEdit (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      ' // Default styles
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP OR %ES_LEFT OR %WS_HSCROLL OR %WS_VSCROLL OR %ES_AUTOHSCROLL OR %ES_AUTOVSCROLL OR %ES_MULTILINE OR %ES_WANTRETURN OR %ES_NOHIDESEL OR %ES_SAVESEL
      IF dwExStyle = 0 OR BITS(LONG, dwExStyle) = -1 THEN dwExStyle = %WS_EX_CLIENTEDGE
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      ' // Make sure the rich edit library is loaded and that the class name is available
      IF m_hRichEditLib = %NULL THEN AfxLoadRichEditLibrary(m_hRichEditLib, m_RichEditClassName)
      IF m_hRichEditLib = %NULL OR m_RichEditClassName = "" THEN EXIT METHOD
      hCtl = ME.AddControl (m_RichEditClassName, hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      ' // Note: To set the font, #INCLUDE "RichEditCtrl.inc" and call the
      ' // RichEdit_SetFont function, e.g. RichEdit_SetFont(hCtl, "MS Shell Dlg, 8)
      ME.SetRichEditFont(hCtl, "Courier New", 9)
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the font of a rich edit control.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD SetRichEditFont (BYVAL hRichEdit AS DWORD, BYREF szFaceName AS WSTRINGZ, BYVAL ptSize AS LONG, OPTIONAL BYVAL bNoScale AS LONG)
#ELSE
   METHOD SetRichEditFont (BYVAL hRichEdit AS DWORD, BYREF szFaceName AS ASCIIZ, BYVAL ptSize AS LONG, OPTIONAL BYVAL bNoScale AS LONG)
#ENDIF
      ' // Calculate the point size
      LOCAL hDC AS DWORD
      hDC = GetDC(%HWND_DESKTOP)
      IF bNoScale = 0 THEN ptSize = (ptSize * m_DPI) \ GetDeviceCaps(hDC, %LOGPIXELSY)
      ReleaseDC %HWND_DESKTOP, hDC
      RichEdit_SetFont(hRichEdit, szFaceName, ptSize)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the Rich Edit class name
   ' =====================================================================================
#IF %DEF(%UNICODE)
   PROPERTY GET RichEditClassName () AS WSTRING
      PROPERTY = m_RichEditClassName
   END PROPERTY
#ELSE
   PROPERTY GET RichEditClassName () AS STRING
      PROPERTY = m_RichEditClassName
   END PROPERTY
#ENDIF
   ' =====================================================================================
#ENDIF

#IF %USEGRAPHCTX = 1
   ' =====================================================================================
   ' Adds an instance of the graphic control.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddGraphCtx (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddGraphCtx (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("GRAPHCTX", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
'      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds an instance of the graphic control (GDI+ aware).
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddGdipGraphCtx (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddGdipGraphCtx (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("GRAPHCTX", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %TRUE, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
'      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================
#ENDIF

#IF %USEGLCTX = 1
   ' =====================================================================================
   ' Adds an instance of the graphic control (GDI, GDI+ and OpenGL aware).
   ' Most Common Cause of SetPixelFormat() Failure
   ' An OpenGL window has its own pixel format. Because of this, only device contexts
   ' retrieved for the client area of an OpenGL window are allowed to draw into the window.
   ' As a result, an OpenGL window should be created with the WS_CLIPCHILDREN and
   ' WS_CLIPSIBLINGS styles. Additionally, the window class attribute should not include
   ' the CS_PARENTDC style.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddGlCtx (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddGlCtx (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD, WS_CLIPCHILDREN and WS_CLIPSIBLINGS styles
      dwStyle = dwStyle OR %WS_CHILD OR %WS_CLIPCHILDREN OR %WS_CLIPSIBLINGS
      hCtl = ME.AddControl ("GLCTX", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %TRUE, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
'      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================
#ENDIF

#IF %USEXPBUTTON = 1
   ' =====================================================================================
   ' Adds an instance of the XPButton control.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddXPButton (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddXPButton (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("XPBUTTON", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================
#ENDIF

#IF %USEGDIPIMAGECTX = 1
   ' =====================================================================================
   ' Adds an instance of the GDI+ image control.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddGdipImageCtx (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddGdipImageCtx (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("GDIPIMAGECTX", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
'      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================
#ENDIF

#IF %USEGDIPANIMCTX = 1
   ' =====================================================================================
   ' Adds an instance of the GDI+ image control
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddGdipAnimCtx (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYREF tDataEx AS GDIPANIMCTXDATAEX, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddGdipAnimCtx (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYREF tDataEx AS GDIPANIMCTXDATAEX, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      LOCAL pDataEx AS DWORD
      IF VARPTR(tDataEx) THEN pDataEx = VARPTR(tDataEx)
      hCtl = ME.AddControl ("GDIPANIMCTX", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, pDataEx, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
'      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================
#ENDIF

#IF %USEGROUPLINECTX = 1
   ' =====================================================================================
   ' Adds an instance of the GDI+ group line control.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddGroupLineCtx (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddGroupLineCtx (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("GROUPLINECTX", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================
#ENDIF

#IF %USEPICTURECTX = 1
   ' =====================================================================================
   ' Adds an instance of the Picture image control.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddPictureCtx (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddPictureCtx (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("PICTURECTX", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
'      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================
#ENDIF

#IF %USEFREEIMAGECTX = 1
   ' =====================================================================================
   ' Adds an instance of the FreeImage image control.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddFreeImageCtx (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS WSTRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ELSE
   METHOD AddFreeImageCtx (BYVAL hParent AS DWORD, BYVAL cID AS LONG, BYVAL strTitle AS STRING, _
      BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
      OPTIONAL BYVAL dwStyle AS DWORD, BYVAL dwExStyle AS DWORD, BYVAL pWndProc AS DWORD, BYVAL bNoScale AS LONG) AS DWORD
#ENDIF
      LOCAL hCtl AS DWORD
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ("FREEIMAGECTX", hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, pWndProc, bNoScale)
      IF hCtl = %NULL THEN EXIT METHOD
'      SendMessage hCtl, %WM_SETFONT, m_hFont, %TRUE
      METHOD = hCtl
   END METHOD
   ' =====================================================================================
#ENDIF

   ' =====================================================================================
   ' Creates a standard tooltip for a window's entire client area.
   ' Parameters:
   ' - hwnd = Handle to the window
   ' - strTooltipText = Tooltip text
   ' - bBalloon = Ballon tip (TRUE or FALSE)
   ' - bCentered = Centered (TRUE or FALSE)
   ' Return Value:
   '   The handle of the tooltip control
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddTooltip (BYVAL hwnd AS DWORD, BYVAL strTooltipText AS WSTRING, _
      OPTIONAL BYVAL bBalloon AS LONG, OPTIONAL BYVAL bCentered AS LONG) AS DWORD
#ELSE
   METHOD AddTooltip (BYVAL hwnd AS DWORD, BYVAL strTooltipText AS STRING, _
      OPTIONAL BYVAL bBalloon AS LONG, OPTIONAL BYVAL bCentered AS LONG) AS DWORD
#ENDIF

      IF hwnd = 0 THEN EXIT METHOD
      LOCAL hwndTT AS DWORD
      LOCAL dwStyle AS DWORD
      dwStyle = %WS_POPUP OR %TTS_NOPREFIX OR %TTS_ALWAYSTIP
      IF bBalloon THEN dwStyle = dwStyle OR %TTS_BALLOON
      hwndTT = CreateWindowEx(%WS_EX_TOPMOST, "tooltips_class32", "", dwStyle, 0, 0, 0, 0, 0, 0, %NULL, BYVAL %NULL)
      IF hwndTT = %NULL THEN EXIT METHOD
      SetWindowPos(hwndTT, %HWND_TOPMOST, 0, 0, 0, 0, %SWP_NOMOVE OR %SWP_NOSIZE OR %SWP_NOACTIVATE)
      ' // Retrieve the version of CommCtl32.dll
      LOCAL pvsffi AS VS_FIXEDFILEINFO PTR
      LOCAL pVerInfo AS DWORD
      LOCAL dwHandle AS DWORD
      LOCAL dwVersion AS DWORD
      LOCAL cbLen AS DWORD
      LOCAL wMajor AS WORD
      LOCAL wMinor AS WORD
      cbLen = GetFileVersionInfoSize("COMCTL32.DLL", dwHandle)
      IF cbLen THEN
         pVerInfo = HeapAlloc(GetProcessHeap, %HEAP_ZERO_MEMORY, cbLen)
         IF pVerInfo THEN
            IF GetFileVersionInfo("COMCTL32.DLL", dwHandle, cbLen, BYVAL pVerInfo) THEN
               IF VerQueryValue(BYVAL pVerInfo, "\", BYVAL VARPTR(pvsffi), cbLen) THEN
                  wMajor = HI(WORD, @pvsffi.dwFileVersionMS)
                  wMinor = LO(WORD, @pvsffi.dwFileVersionMS)
               END IF
            END IF
            HeapFree GetProcessHeap, 0, pVerInfo
         END IF
      END IF
      ' // Register the window with the tooltip control
      LOCAL tti AS TOOLINFO
      tti.cbSize = SIZEOF(tti)
      ' // The size of the TOOLINFO structure is of 48 bytes in version 6
      ' // of comctl32.dll, and of 44 bytes in lower versions.
      IF wMajor < 6 THEN tti.cbSize = 44
      tti.uFlags = %TTF_SUBCLASS
      IF bCentered THEN tti.uFlags = tti.uFlags OR %TTF_CENTERTIP
      tti.hwnd = hwnd
      tti.hinst = GetModuleHandle(BYVAL %NULL)
      GetClientRect(hwnd, tti.rect)
      ' // The length of the string must not exceed of 80 characters, including the terminating null
      IF LEN(strTooltipText) > 79 THEN strTooltipText = LEFT$(strTooltipText, 79)
      tti.lpszText = STRPTR(strTooltipText)
      tti.uId = 0
      SendMessage hwndTT, %TTM_ADDTOOL, 0, VARPTR(tti)
      METHOD = hwndTT

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets/replaces the text of a tooltip control.
   ' Parameters:
   ' - hTooltip = Handle of the tooltip control
   ' - hwnd = Handle of the window
   ' - strTooltipText = Text of the tooltip.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD SetTooltipText (BYVAL hTooltip AS DWORD, BYVAL hwnd AS DWORD, BYVAL strTooltipText AS WSTRING)
#ELSE
   METHOD SetTooltipText (BYVAL hTooltip AS DWORD, BYVAL hwnd AS DWORD, BYVAL strTooltipText AS STRING)
#ENDIF

      IF hTooltip = 0 OR hwnd = 0 THEN EXIT METHOD
      ' // Retrieve the version of CommCtl32.dll
      LOCAL pvsffi AS VS_FIXEDFILEINFO PTR
      LOCAL pVerInfo AS DWORD
      LOCAL dwHandle AS DWORD
      LOCAL dwVersion AS DWORD
      LOCAL cbLen AS DWORD
      LOCAL wMajor AS WORD
      LOCAL wMinor AS WORD
      cbLen = GetFileVersionInfoSize("COMCTL32.DLL", dwHandle)
      IF cbLen THEN
         pVerInfo = HeapAlloc(GetProcessHeap, %HEAP_ZERO_MEMORY, cbLen)
         IF pVerInfo THEN
            IF GetFileVersionInfo("COMCTL32.DLL", dwHandle, cbLen, BYVAL pVerInfo) THEN
               IF VerQueryValue(BYVAL pVerInfo, "\", BYVAL VARPTR(pvsffi), cbLen) THEN
                  wMajor = HI(WORD, @pvsffi.dwFileVersionMS)
                  wMinor = LO(WORD, @pvsffi.dwFileVersionMS)
               END IF
            END IF
            HeapFree GetProcessHeap, 0, pVerInfo
         END IF
      END IF
      ' // The size of the TOOLINFO structure is of 48 bytes in version 6
      ' // of comctl32.dll, and of 44 bytes in lower versions.
      LOCAL tti AS TOOLINFO
      tti.cbSize = SIZEOF(tti)
      IF wMajor < 6 THEN tti.cbSize = 44
      tti.hwnd = hwnd
      tti.uId = 0
      ' // Retrieve the tooltip information
      IF SendMessage(hTooltip, %TTM_GETTOOLINFO, 0, VARPTR(tti)) THEN
         ' // The length of the string must not exceed of 80 characters, including the terminating null
         IF LEN(strTooltipText) > 79 THEN strTooltipText = LEFT$(strTooltipText, 79)
         tti.lpszText = STRPTR(strTooltipText)
         SendMessage hTooltip, %TTM_SETTOOLINFO, 0, VARPTR(tti)
      END IF

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Removes a tool from a tooltip control.
   ' Parameters:
   ' - hTooltip = Handle of the tooltip control
   ' - hwnd = Handle of the window
   ' =====================================================================================
   METHOD DeleteTooltip (BYVAL hTooltip AS DWORD, BYVAL hwnd AS DWORD)

      IF hTooltip = 0 OR hwnd = 0 THEN EXIT METHOD
      ' // Retrieve the version of CommCtl32.dll
      LOCAL pvsffi AS VS_FIXEDFILEINFO PTR
      LOCAL pVerInfo AS DWORD
      LOCAL dwHandle AS DWORD
      LOCAL dwVersion AS DWORD
      LOCAL cbLen AS DWORD
      LOCAL wMajor AS WORD
      LOCAL wMinor AS WORD
      cbLen = GetFileVersionInfoSize("COMCTL32.DLL", dwHandle)
      IF cbLen THEN
         pVerInfo = HeapAlloc(GetProcessHeap, %HEAP_ZERO_MEMORY, cbLen)
         IF pVerInfo THEN
            IF GetFileVersionInfo("COMCTL32.DLL", dwHandle, cbLen, BYVAL pVerInfo) THEN
               IF VerQueryValue(BYVAL pVerInfo, "\", BYVAL VARPTR(pvsffi), cbLen) THEN
                  wMajor = HI(WORD, @pvsffi.dwFileVersionMS)
                  wMinor = LO(WORD, @pvsffi.dwFileVersionMS)
               END IF
            END IF
            HeapFree GetProcessHeap, 0, pVerInfo
         END IF
      END IF
      ' // The size of the TOOLINFO structure is of 48 bytes in version 6
      ' // of comctl32.dll, and of 44 bytes in lower versions.
      LOCAL tti AS TOOLINFO
      tti.cbSize = SIZEOF(tti)
      IF wMajor < 6 THEN tti.cbSize = 44
      tti.hwnd = hwnd
      tti.uId = 0
      ' // Remove the tooltip
      SendMessage(hTooltip, %TTM_DELTOOL, 0, VARPTR(tti))

   END METHOD
   ' =====================================================================================

#IF %USEMDI = 1

   ' =====================================================================================
   ' Optional. MDI Class name.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   PROPERTY GET MDIClassName () AS WSTRING
      PROPERTY = m_szMDIClassName
   END PROPERTY
#ELSE
   PROPERTY GET MDIClassName () AS STRING
      PROPERTY = m_szMDIClassName
   END PROPERTY
#ENDIF
   ' =====================================================================================

   ' =====================================================================================
   ' Optional. Set class name.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   PROPERTY SET MDIClassName (BYVAL bstrMDIClassName AS WSTRING)
      m_szMDIClassName = bstrMDIClassName
   END PROPERTY
#ELSE
   PROPERTY SET MDIClassName (BYVAL strMDIClassName AS STRING)
      m_szMDIClassName = strMDIClassName
   END PROPERTY
#ENDIF
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a MDI window
   ' =====================================================================================
   METHOD CreateMDIWindow ( _
      BYVAL cID AS LONG, _                  ' // Control identifier
      BYVAL x AS LONG, _                    ' // Horizontal position
      BYVAL y AS LONG, _                    ' // Vertical position
      BYVAL nWidth AS LONG, _               ' // Window width
      BYVAL nHeight AS LONG, _              ' // Window height
      BYVAL dwStyle AS DWORD, _             ' // Window style(s)
      BYVAL dwExStyle AS DWORD, _           ' // Extended style
      BYVAL hSubMenu AS DWORD, _            ' // MDI window submenu
      BYVAL lpfnWndProc AS DWORD, _         ' // Address of the callback function
      OPTIONAL BYVAL bNoScale AS LONG _     ' // Boolean - No scale
      ) AS DWORD                            ' // Window handle

      ' // Exit if the main window has not already been created
      IF m_hwnd = %NULL THEN EXIT METHOD
      ' // Default size values
      IF nWidth = 0 THEN
         nWidth = %CW_USEDEFAULT
         IF x = 0 THEN
            x = %CW_USEDEFAULT
         END IF
       END IF
      ' // Exit if the window has already been created
      IF m_hwndClient THEN EXIT METHOD
      ' // Register a class
      LOCAL wMDIAtom AS WORD
      wMDIAtom = CWindow_RegisterMDIClass(m_szMDIClassName, m_hInstance, lpfnWndProc)
      IF wMDIAtom = 0 THEN EXIT METHOD
      ' // Create the window
      LOCAL tccs AS CLIENTCREATESTRUCT
      ' // Note: If you use 1 as the identifier for the first child, the
      ' // identifiers of the windows will conflict with the dialog box
      ' // identifiers, e.g. the first window with %ID_OK, the 2nd with
      ' // IDCANCEL, etc.
      tccs.idFirstChild = 13
      tccs.hWindowMenu  = hSubMenu
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_HSCROLL OR %WS_VSCROLL OR %WS_CLIPCHILDREN OR %WS_CLIPSIBLINGS
      IF dwExStyle = 0 OR BITS(LONG, dwExStyle) = -1 THEN dwExStyle = %WS_EX_CLIENTEDGE
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      IF bNoScale THEN
         m_hwndClient = CreateWindowEx(dwExStyle, "MDICLIENT", "", dwStyle, _
                        x, y, nWidth, nHeight, m_hwnd, cID, m_hInstance, tccs)
      ELSE
         m_hwndClient = CreateWindowEx(dwExStyle, "MDICLIENT", "", dwStyle, _
                        x * m_rx, y * m_ry, nWidth * m_rx, nHeight * m_ry, m_hwnd, cID, m_hInstance, tccs)
      END IF
      IF m_hwndClient = %NULL THEN EXIT METHOD
      ' // Store the handle of the MDI client window
      SetClassLong m_hwnd, 4, m_hwndClient
      ' // Resize the window
      SendMessage m_hwnd, %WM_SIZE, %SIZE_RESTORED, MAK(LONG, ME.CLientWidth, ME.ClientHeight)
      METHOD = m_hwndClient
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the MDI client window handle
   ' =====================================================================================
   PROPERTY GET hwndClient () AS DWORD
      PROPERTY = m_hwndClient
   END PROPERTY
   ' =====================================================================================
#ENDIF

#IF %USEOLECON = 1
   ' =====================================================================================
   ' Adds an OCX to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddOCX ( _
      BYVAL hParent AS DWORD, _             ' // Parent window handle
      BYVAL cID AS LONG, _                  ' // Control identifier
      BYVAL strProgID AS WSTRING, _         ' // ProgID (Program identifier)
      BYVAL strLicKey AS WSTRING, _         ' // License key
      BYVAL x AS LONG, _                    ' // Horizontal position
      BYVAL y AS LONG, _                    ' // Vertical position
      BYVAL nWidth AS LONG, _               ' // Control width
      BYVAL nHeight AS LONG, _              ' // Control height
      OPTIONAL BYVAL dwStyle AS DWORD, _    ' // Control style
      OPTIONAL BYVAL dwExStyle AS DWORD, _  ' // Extended style
      OPTIONAL BYVAL bNoScale AS LONG _     ' // Boolean - No scale
      ) AS DWORD                            ' // Control handle
#ELSE
   METHOD AddOCX ( _
      BYVAL hParent AS DWORD, _             ' // Parent window handle
      BYVAL cID AS LONG, _                  ' // Control identifier
      BYVAL strProgID AS STRING, _          ' // ProgID (Program identifier)
      BYVAL strLicKey AS STRING, _          ' // License key
      BYVAL x AS LONG, _                    ' // Horizontal position
      BYVAL y AS LONG, _                    ' // Vertical position
      BYVAL nWidth AS LONG, _               ' // Control width
      BYVAL nHeight AS LONG, _              ' // Control height
      OPTIONAL BYVAL dwStyle AS DWORD, _    ' // Control style
      OPTIONAL BYVAL dwExStyle AS DWORD, _  ' // Extended style
      OPTIONAL BYVAL bNoScale AS LONG _     ' // Boolean - No scale
      ) AS DWORD                            ' // Control handle
#ENDIF

#IF %DEF(%UNICODE)
      LOCAL strTitle AS WSTRING
#ELSE
      LOCAL strTitle AS STRING
#ENDIF
      LOCAL hCtl AS DWORD
      IF LEN(strProgID) = 0 THEN EXIT METHOD
      strTitle = strProgID
      IF LEN(strLicKey) THEN strTitle += ";RTLKEY:" & strLicKey
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ($OC_CLASSNAME, hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, %NULL, %NULL, bNoScale)
      METHOD = hCtl

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds an unregistered OCX to the window.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddUnregOCX ( _
      BYVAL hParent AS DWORD, _             ' // Parent window handle
      BYVAL cID AS LONG, _                  ' // Control identifier
      BYVAL rclsID AS GUID, _               ' // CLSID (Class identifier)
      BYVAL riid AS GUID, _                 ' // IID (Interface identifier)
      BYVAL strLibName AS WSTRING, _        ' // Fully qualified path of the OCX
      BYVAL strLicKey AS WSTRING, _         ' // License key
      BYVAL x AS LONG, _                    ' // Horizontal position
      BYVAL y AS LONG, _                    ' // Vertical position
      BYVAL nWidth AS LONG, _               ' // Control width
      BYVAL nHeight AS LONG, _              ' // Control height
      OPTIONAL BYVAL dwStyle AS DWORD, _    ' // Control style
      OPTIONAL BYVAL dwExStyle AS DWORD, _  ' // Extended style
      OPTIONAL BYVAL bNoScale AS LONG _     ' // Boolean - No scale
      ) AS DWORD                            ' // Control handle
#ELSE
   METHOD AddUnregOCX ( _
      BYVAL hParent AS DWORD, _             ' // Parent window handle
      BYVAL cID AS LONG, _                  ' // Control identifier
      BYVAL rclsID AS GUID, _               ' // CLSID (Class identifier)
      BYVAL riid AS GUID, _                 ' // IID (Interface identifier)
      BYVAL strLibName AS STRING, _         ' // Fully qualified path of the OCX
      BYVAL strLicKey AS STRING, _          ' // License key
      BYVAL x AS LONG, _                    ' // Horizontal position
      BYVAL y AS LONG, _                    ' // Vertical position
      BYVAL nWidth AS LONG, _               ' // Control width
      BYVAL nHeight AS LONG, _              ' // Control height
      OPTIONAL BYVAL dwStyle AS DWORD, _    ' // Control style
      OPTIONAL BYVAL dwExStyle AS DWORD, _  ' // Extended style
      OPTIONAL BYVAL bNoScale AS LONG _     ' // Boolean - No scale
      ) AS DWORD                            ' // Control handle
#ENDIF

      LOCAL hCtl AS DWORD
      LOCAL cp AS OC_CREATEPARAMS
      cp.clsid = rclsID
      cp.riid = riid
      cp.szLicKey = strLicKey
      cp.szLibName = strLibName
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ($OC_CLASSNAME, hParent, cID, "", x, y, nWidth, nHeight, dwStyle, dwExStyle, VARPTR(cp), %NULL, bNoScale)
      METHOD = hCtl

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Gets the optical zoom factor of the WebBrowser control in the range of 10 to 1000 (percent).
   ' =====================================================================================
   PROPERTY GET WBZoom () AS LONG
      PROPERTY = m_WBZoom
   END PROPERTY
   ' =====================================================================================
   ' =====================================================================================
   ' Sets the optical zoom factor of the WebBrowser control in the range of 10 to 1000 (percent).
   ' =====================================================================================
   PROPERTY SET WBZoom (BYVAL nZoom AS LONG)
      IF nZoom > 9 AND nZoom < 1001 THEN m_WBZoom = nZoom
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Adds an instance of the WebBrowser control.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddWebBrowserControl ( _
      BYVAL hParent AS DWORD, _             ' // Parent window handle
      BYVAL cID AS LONG, _                  ' // Control identifier
      BYVAL strURL AS WSTRING, _            ' // A URL, a path or HTML code
      BYVAL pEvtObj AS IUnknown, _          ' // Events class reference
      BYVAL x AS LONG, _                    ' // Horizontal position
      BYVAL y AS LONG, _                    ' // Vertical position
      BYVAL nWidth AS LONG, _               ' // Control width
      BYVAL nHeight AS LONG, _              ' // Control height
      OPTIONAL BYVAL dwStyle AS DWORD, _    ' // Control style
      OPTIONAL BYVAL dwExStyle AS DWORD, _  ' // Extended style
      OPTIONAL BYVAL lpParam AS DWORD, _    ' // Pointer to custom data
      OPTIONAL BYVAL bNoScale AS LONG _     ' // Boolean - No scale
      ) AS DWORD                            ' // Control handle
#ELSE
   METHOD AddWebBrowserControl ( _
      BYVAL hParent AS DWORD, _             ' // Parent window handle
      BYVAL cID AS LONG, _                  ' // Control identifier
      BYVAL strURL AS STRING, _             ' // A URL, a path or HTML code
      BYVAL pEvtObj AS IUnknown, _          ' // Events class reference
      BYVAL x AS LONG, _                    ' // Horizontal position
      BYVAL y AS LONG, _                    ' // Vertical position
      BYVAL nWidth AS LONG, _               ' // Control width
      BYVAL nHeight AS LONG, _              ' // Control height
      OPTIONAL BYVAL dwStyle AS DWORD, _    ' // Control style
      OPTIONAL BYVAL dwExStyle AS DWORD, _  ' // Extended style
      OPTIONAL BYVAL lpParam AS DWORD, _    ' // Pointer to custom data
      OPTIONAL BYVAL bNoScale AS LONG _     ' // Boolean - No scale
      ) AS DWORD                            ' // Control handle
#ENDIF

      LOCAL hCtl AS DWORD
#IF %DEF(%UNICODE)
      LOCAL strTitle AS WSTRING
#ELSE
      LOCAL strTitle AS STRING
#ENDIF
      strTitle = "Shell.Explorer"
      IF dwStyle = 0 OR BITS(LONG, dwStyle) = -1 THEN dwStyle = %WS_VISIBLE OR %WS_TABSTOP
      IF BITS(LONG, dwExStyle) = -1 THEN dwExStyle = 0
      ' // Make sure that the control has the WS_CHILD style
      dwStyle = dwStyle OR %WS_CHILD
      hCtl = ME.AddControl ($OC_CLASSNAME, hParent, cID, strTitle, x, y, nWidth, nHeight, dwStyle, dwExStyle, lpParam, %NULL, bNoScale)
#IF %USEWEBBROWSER = 1
      LOCAL vURL AS VARIANT
      LOCAL pIWebBrowser2 AS IWebBrowser2
      LOCAL pHTMLDocument2 AS IHTMLDocument2
      LOCAL vaIn AS VARIANT
      LOCAL nZoom AS LONG
      IF LEN(strURL) THEN
         ' // Gets a reference to the IWebBrowser2 interface
         pIWebBrowser2 = OC_GetDispatch(hCtl)
         IF ISOBJECT(pIWebBrowser2) THEN
            IF UCASE$(LEFT$(strURL, 7)) = "MSHTML:" THEN
               ' // Connect events
               IF ISOBJECT(pEvtObj) THEN OC_Advise(hCtl, pEvtObj)
               ' // Blank page
               vUrl = "about:blank"
               pIWebBrowser2.Navigate2(vUrl)
               ' // Zoom if m_WBZoom <> 100 or m_rx <> 1 (High DPI aware)
               IF m_WBZoom <> 100 OR m_rx <> 1 THEN
                  ' // Waits until the page has been loaded
                  DO
                     ' // Processes pending messages
                     AfxPumpMessages
                     ' // Retrieves the ready state
                     IF pIWebBrowser2.ReadyState = %READYSTATE_COMPLETE THEN EXIT DO
                  LOOP
                  ' // Zooms the contents of the page (requires IE 7+)
                  IF AfxGetInternetExplorerVersion => 7 THEN
                     nZoom = m_WBZoom
                     IF nZoom = 0 THEN nZoom = 100
                     vaIn = CLNG(m_rx * nZoom) AS LONG
                     pIWebBrowser2.ExecWB(%OLECMDID_OPTICAL_ZOOM, %OLECMDEXECOPT_DODEFAULT, vaIn)
                  END IF
               END IF
               ' // Gets a reference to the IHTMLDocument2 interface
               pHTMLDocument2 = pIWebBrowser2.Document
               IF ISOBJECT(pHTMLDocument2) THEN
                  strURL = MID$(strURL, 8)
                  IHTMLDocument2_WriteString(pHTMLDocument2, strURL)
                  pHTMLDocument2.close
                  pHTMLDocument2 = NOTHING
               END IF
            ELSE
               ' // Connects events
               IF ISOBJECT(pEvtObj) THEN OC_Advise(hCtl, pEvtObj)
               ' // Navigates to a blank page to fire the DocumentComplete event,
               ' // where resides the code to set the IDocHostUIHandler interface
               vUrl = "about:blank"
               pIWebBrowser2.Navigate2(vUrl)
               ' // Zoom if m_WBZoom <> 100 or m_rx <> 1 (High DPI aware)
               IF m_WBZoom <> 100 OR m_rx <> 1 THEN
                  ' // Waits until the page has been downloaded
                  DO
                     ' // Processes pending messages
                     AfxPumpMessages
                     ' // Retrieves the ready state
                     IF pIWebBrowser2.ReadyState = %READYSTATE_COMPLETE THEN EXIT DO
                  LOOP
                  ' // Zooms the contents of the page (requires IE 7+)
                  IF AfxGetInternetExplorerVersion => 7 THEN
                     nZoom = m_WBZoom
                     IF nZoom = 0 THEN nZoom = 100
                     vaIn = CLNG(m_rx * nZoom) AS LONG
                     pIWebBrowser2.ExecWB(%OLECMDID_OPTICAL_ZOOM, %OLECMDEXECOPT_DODEFAULT, vaIn)
                  END IF
               END IF
               ' // Navigate to the URL
               vURL = strURL
               pIWebBrowser2.Navigate2(vURL)
            END IF
            ' // Releases the interface
            pIWebBrowser2 = NOTHING
         END IF
      ELSE
         ' // Gets a reference to the IWebBrowser2 interface
         pIWebBrowser2 = OC_GetDispatch(hCtl)
         IF ISOBJECT(pIWebBrowser2) THEN
            ' // Connects events
            IF ISOBJECT(pEvtObj) THEN OC_Advise(hCtl, pEvtObj)
            ' // Navigates to a blank page to fire the DocumentComplete event,
            ' // where resides the code to set the IDocHostUIHandler interface
            vUrl = "about:blank"
            pIWebBrowser2.Navigate2(vUrl)
            ' // Zoom if m_WBZoom <> 100 or m_rx <> 1 (High DPI aware)
            IF m_WBZoom <> 100 OR m_rx <> 1 THEN
               ' // Waits until the page has been downloaded
               DO
                  ' // Processes pending messages
                  AfxPumpMessages
                  ' // Retrieves the ready state
                  IF pIWebBrowser2.ReadyState = %READYSTATE_COMPLETE THEN EXIT DO
               LOOP
               ' // Zooms the contents of the page (requires IE 7+)
               IF AfxGetInternetExplorerVersion => 7 THEN
                  nZoom = m_WBZoom
                  IF nZoom = 0 THEN nZoom = 100
                  vaIn = CLNG(m_rx * nZoom) AS LONG
                  pIWebBrowser2.ExecWB(%OLECMDID_OPTICAL_ZOOM, %OLECMDEXECOPT_DODEFAULT, vaIn)
               END IF
            END IF
            ' // Releases the interface
            pIWebBrowser2 = NOTHING
         END IF
      END IF
#ENDIF

      METHOD = hCtl

   END METHOD
   ' =====================================================================================
#ENDIF

#IF %USEWEBBROWSER = 1
   ' =====================================================================================
   ' Adds an instance of the WebBrowser control an embeds a YouTube video.
   ' Note: The strCode parameter is the 11 character code of the video.
   ' For example, given this URL address, "http://www.youtube.com/watch?v=cZ-8jYpa1-o".
   ' the code is "cZ-8jYpa1-o".
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddYouTubeVideo ( _
      BYVAL hParent AS DWORD, _             ' // Parent window handle
      BYVAL cID AS LONG, _                  ' // Control identifier
      BYVAL strCode AS WSTRING, _           ' // The 11 character code of the video
      BYVAL x AS LONG, _                    ' // Horizontal position
      BYVAL y AS LONG, _                    ' // Vertical position
      BYVAL nWidth AS LONG, _               ' // Control width
      BYVAL nHeight AS LONG, _              ' // Control height
      OPTIONAL BYVAL dwStyle AS DWORD, _    ' // Control style
      OPTIONAL BYVAL dwExStyle AS DWORD, _  ' // Extended style
      OPTIONAL BYVAL lpParam AS DWORD, _    ' // Pointer to custom data
      OPTIONAL BYVAL bNoScale AS LONG _     ' // Boolean - No scale
      ) AS DWORD                            ' // Control handle

      LOCAL strUrl AS WSTRING
      LOCAL s AS WSTRING
#ELSE
   METHOD AddYouTubeVideo ( _
      BYVAL hParent AS DWORD, _             ' // Parent window handle
      BYVAL cID AS LONG, _                  ' // Control identifier
      BYVAL strCode AS STRING, _            ' // The 11 character code of the video
      BYVAL x AS LONG, _                    ' // Horizontal position
      BYVAL y AS LONG, _                    ' // Vertical position
      BYVAL nWidth AS LONG, _               ' // Control width
      BYVAL nHeight AS LONG, _              ' // Control height
      OPTIONAL BYVAL dwStyle AS DWORD, _    ' // Control style
      OPTIONAL BYVAL dwExStyle AS DWORD, _  ' // Extended style
      OPTIONAL BYVAL lpParam AS DWORD, _    ' // Pointer to custom data
      OPTIONAL BYVAL bNoScale AS LONG _     ' // Boolean - No scale
      ) AS DWORD                            ' // Control handle

      LOCAL strUrl AS STRING
      LOCAL s AS STRING
#ENDIF

      ' // Build the URL
      strURL = "http://www.youtube.com/v/" & strCode

      ' // Build the web page. Remember to always start it with "MSHTML:".
      s  = "MSHTML:<!DOCTYPE html>" & $CRLF
      s += "<html>" & $CRLF
      s += "<head>" & $CRLF
      s += "<meta http-equiv='MSThemeCompatible' content='Yes'>" & $CRLF
      s += "<title>YouTube video</title>" & $CRLF
      s += "" & $CRLF
      s += "</head>" & $CRLF
      s += "<body scroll='no' style='MARGIN: 0px 0px 0px 0px'>"
      s += "<object width=" & FORMAT$(nWidth) & " height=" & FORMAT$(nHeight) & ">" & _
           "<param name='movie' value=" & strURL & "</param>" & _
           "<embed src=" & strURL & _
           " type='application/x-shockwave-flash' width='100%' height='100%'>" & _
           "</embed></object>"
      s += "" & $CRLF
      s += "</body>" & $CRLF
      s += "" & $CRLF
      s += "</html>" & $CRLF

      LOCAL hCtl AS DWORD
      hCtl = ME.AddWebBrowserControl(hParent, CID, s, NOTHING, x, y, nWidth, nHeight)

   END METHOD
   ' =====================================================================================
#ENDIF

#IF %USEWEBBROWSER = 1
   ' =====================================================================================
   ' Writes one or more HTML expressions to a document in the specified window.
   ' Parameters:
   ' - hwnd : Handle of the window that hosts the WebBrowser control.
   ' - s : Text and HTML tags to write.
   ' OBJRESULT:
   ' - %S_OK if successful, or an error value otherwise.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD WebBrowserWriteString (BYVAL hwnd AS DWORD, BYVAL s AS WSTRING)
#ELSE
   METHOD WebBrowserWriteString (BYVAL hwnd AS DWORD, BYVAL s AS STRING)
#ENDIF
      IF hwnd = 0 THEN METHOD OBJRESULT = %ERROR_INVALID_HANDLE: EXIT METHOD
      LOCAL pIWebBrowser2 AS IWebBrowser2
      pIWebBrowser2 = OC_GetDispatch(hwnd)
      IF ISNOTHING(pIWebBrowser2) THEN METHOD OBJRESULT = %E_FAIL: EXIT METHOD
      ' // Since the IHTMLDocument2::clear method is not supported, this is a
      ' // workaround to clear the current document window and erase all variables.
      LOCAL vUrl AS VARIANT
      vUrl = "about:blank"
      pIWebBrowser2.Navigate2(vUrl)
      ' // Waits until the page has been downloaded
      DO
         ' // Processes pending messages
         AfxPumpMessages
         ' // Retrieves the ready state
         IF pIWebBrowser2.ReadyState = %READYSTATE_COMPLETE THEN EXIT DO
      LOOP
      LOCAL pHTMLDocument2 AS IHTMLDocument2
      pHTMLDocument2 = pIWebBrowser2.Document
      IF ISNOTHING(pIWebBrowser2) THEN METHOD OBJRESULT = %E_FAIL: EXIT METHOD
      IHTMLDocument2_WriteString(pHTMLDocument2, s)
      IF OBJRESULT THEN METHOD OBJRESULT = OBJRESULT
      pHTMLDocument2.close
   END METHOD
   ' =====================================================================================
#ENDIF

#IF %USEWEBBROWSER = 1
   ' =====================================================================================
   ' Writes one or more HTML expressions, followed by a carriage return, to a document in
   ' the specified window.
   ' * Remarks:
   ' - In HTML, the carriage return is ignored unless it occurs within preformatted text.
   ' Parameters:
   ' - hwnd : Handle of the window that hosts the WebBrowser control.
   ' - s : Text and HTML tags to write.
   ' OBJRESULT:
   ' - %S_OK if successful, or an error value otherwise.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD WebBrowserWritelnString (BYVAL hwnd AS DWORD, BYVAL s AS WSTRING)
#ELSE
   METHOD WebBrowserWritelnString (BYVAL hwnd AS DWORD, BYVAL s AS STRING)
#ENDIF
      IF hwnd = 0 THEN METHOD OBJRESULT = %ERROR_INVALID_HANDLE: EXIT METHOD
      LOCAL pIWebBrowser2 AS IWebBrowser2
      pIWebBrowser2 = OC_GetDispatch(hwnd)
      IF ISNOTHING(pIWebBrowser2) THEN METHOD OBJRESULT = %E_FAIL: EXIT METHOD
      ' // Since the IHTMLDocument2::clear method is not supported, this is a
      ' // workaround to clear the current document window and erase all variables.
      LOCAL vUrl AS VARIANT
      vUrl = "about:blank"
      pIWebBrowser2.Navigate2(vUrl)
      ' // Waits until the page has been downloaded
      DO
         ' // Processes pending messages
         AfxPumpMessages
         ' // Retrieves the ready state
         IF pIWebBrowser2.ReadyState = %READYSTATE_COMPLETE THEN EXIT DO
      LOOP
      LOCAL pHTMLDocument2 AS IHTMLDocument2
      pHTMLDocument2 = pIWebBrowser2.Document
      IF ISNOTHING(pIWebBrowser2) THEN METHOD OBJRESULT = %E_FAIL: EXIT METHOD
      IHTMLDocument2_WritelnString(pHTMLDocument2, s)
      IF OBJRESULT THEN METHOD OBJRESULT = OBJRESULT
      pHTMLDocument2.close
   END METHOD
   ' =====================================================================================
#ENDIF

#IF %USEWEBBROWSER = 1
   ' =====================================================================================
   ' Adds an instance of the WebBrowser control an embeds Windows Media Player.
   ' =====================================================================================
#IF %DEF(%UNICODE)
   METHOD AddWindowsMediaPlayer ( _
      BYVAL hParent AS DWORD, _             ' // Parent window handle
      BYVAL cID AS LONG, _                  ' // Control identifier
      BYVAL strPath AS WSTRING, _           ' // The path of the video to play
      BYVAL x AS LONG, _                    ' // Horizontal position
      BYVAL y AS LONG, _                    ' // Vertical position
      BYVAL nWidth AS LONG, _               ' // Control width
      BYVAL nHeight AS LONG, _              ' // Control height
      OPTIONAL BYVAL dwStyle AS DWORD, _    ' // Control style
      OPTIONAL BYVAL dwExStyle AS DWORD, _  ' // Extended style
      OPTIONAL BYVAL lpParam AS DWORD, _    ' // Pointer to custom data
      OPTIONAL BYVAL bNoScale AS LONG _     ' // Boolean - No scale
      ) AS DWORD                            ' // Control handle

      LOCAL s AS WSTRING
#ELSE
   METHOD AddWindowsMediaPlayer ( _
      BYVAL hParent AS DWORD, _             ' // Parent window handle
      BYVAL cID AS LONG, _                  ' // Control identifier
      BYVAL strPath AS STRING, _            ' // The path of the video to play
      BYVAL x AS LONG, _                    ' // Horizontal position
      BYVAL y AS LONG, _                    ' // Vertical position
      BYVAL nWidth AS LONG, _               ' // Control width
      BYVAL nHeight AS LONG, _              ' // Control height
      OPTIONAL BYVAL dwStyle AS DWORD, _    ' // Control style
      OPTIONAL BYVAL dwExStyle AS DWORD, _  ' // Extended style
      OPTIONAL BYVAL lpParam AS DWORD, _    ' // Pointer to custom data
      OPTIONAL BYVAL bNoScale AS LONG _     ' // Boolean - No scale
      ) AS DWORD                            ' // Control handle

     LOCAL s AS STRING
#ENDIF

      ' // If the path has spaces, add double quotes
      IF INSTR(strPath, " ") AND LEFT$(strPath, 1) <> $DQ THEN strPath = $DQ & strPath & $DQ

      ' // Build the web page. Remember to always start it with "MSHTML:".
      s  = "MSHTML:<!DOCTYPE html>" & $CRLF
      s += "<html>" & $CRLF
      s += "<head>" & $CRLF
      s += "<meta http-equiv='MSThemeCompatible' content='Yes'>" & $CRLF
      s += "<title>Windows Media Player</title>" & $CRLF
      s += "" & $CRLF
      s += "</head>" & $CRLF
      s += "<body scroll='no' style='margin: 0px 0px 0px 0px'>"
      s += "<object id='video' classid='clsid:6BF52A52-394A-11d3-B153-00C04F79FAA6' type='application/x-oleobject' width='100%' height='100%'>" & $CRLF
      s += "<param name='URL' value=" & strPath & ">" & $CRLF
      s += "<param name='Enabled' value='true'>" & $CRLF
      s += "<param name='AutoStart' value='true'>" & $CRLF
      s += "<param name='StretchToFit' value='true'>" & $CRLF
      s += "<param name='PlayCount' value='1'>" & $CRLF
      s += "<param name='Volume' value='50'>" & $CRLF
      s += "<param name='Balance' value='0'>" & $CRLF
      s += "<param name='Rate' value='1.0'>" & $CRLF
      s += "<param name='Mute' value='false'>" & $CRLF
      s += "<param name='FullScreen' value='false'>" & $CRLF
      s += "<param name='uiMode' value='full'>" & $CRLF
      s += "</object>" & $CRLF
      s += "" & $CRLF
      s += "</body>" & $CRLF
      s += "" & $CRLF
      s += "</html>" & $CRLF

      LOCAL hCtl AS DWORD
      hCtl = ME.AddWebBrowserControl(hParent, CID, s, NOTHING, x, y, nWidth, nHeight)

   END METHOD
   ' =====================================================================================
#ENDIF

   ' =====================================================================================
   ' Returns the accelerator table handle
   ' =====================================================================================
   PROPERTY GET hAccel () AS DWORD
      PROPERTY = m_hAccel
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the accelerator tabe handle
   ' =====================================================================================
   PROPERTY SET hAccel (BYVAL hAccel AS DWORD)
      IF m_hAccel THEN DestroyAcceleratorTable(m_hAccel)
      IF UBOUND(m_rgAccelEntries) - LBOUND(m_rgAccelEntries) > -1 THEN ERASE m_rgAccelEntries
      m_hAccel = hAccel
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Adds an accelerator to the table.
   ' =====================================================================================
   METHOD AddAccelerator (BYVAL fvirt AS BYTE, BYVAL vKey AS VARIANT, BYVAL cmd AS WORD)
      LOCAL wKey AS WORD
      IF VARIANTVT(vKey) = %VT_BSTR THEN wKey = ASC(VARIANT$$(vKey)) ELSE wKey = VARIANT#(vKey)
      REDIM PRESERVE m_rgAccelEntries(UBOUND(m_rgAccelEntries) + 1) AS INSTANCE ACCELAPI
      m_rgAccelEntries(UBOUND(m_rgAccelEntries)).fvirt = fvirt
      m_rgAccelEntries(UBOUND(m_rgAccelEntries)).key = wKey
      m_rgAccelEntries(UBOUND(m_rgAccelEntries)).cmd = cmd
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates the accelerator table.
   ' =====================================================================================
   METHOD CreateAcceleratorTable () AS DWORD
      IF UBOUND(m_rgAccelEntries) - LBOUND(m_rgAccelEntries) = -1 THEN EXIT METHOD
      IF m_hAccel THEN DestroyAcceleratorTable(m_hAccel)
      m_hAccel = CreateAcceleratorTable(m_rgAccelEntries(0), UBOUND(m_rgAccelEntries) - LBOUND(m_rgAccelEntries) + 1)
      METHOD = m_hAccel
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Destroys the accelerator table.
   ' =====================================================================================
   METHOD DestroyAcceleratorTable
      IF m_hAccel THEN DestroyAcceleratorTable(m_hAccel)
      IF UBOUND(m_rgAccelEntries) - LBOUND(m_rgAccelEntries) > -1 THEN ERASE m_rgAccelEntries
      m_hAccel = 0
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds an object to the collection.
   ' =====================================================================================
   METHOD AddObject (BYVAL bstrKey AS WSTRING, BYVAL vObj AS VARIANT)
      IF ISOBJECT(m_pObjects) THEN m_pObjects.Add(bstrKey, vObj)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Removes an object from the collection.
   ' =====================================================================================
   METHOD RemoveObject (BYVAL bstrKey AS WSTRING)
      IF ISOBJECT(m_pObjects) THEN m_pObjects.Remove(bstrKey)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns an object from the collection.
   ' =====================================================================================
   METHOD GetObject (BYVAL bstrKey AS WSTRING) AS VARIANT
      IF ISOBJECT(m_pObjects) THEN METHOD = m_pObjects.Item(bstrKey)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a reference to the collection.
   ' =====================================================================================
   METHOD GetObjects () AS IPowerCollection
      METHOD = m_pObjects
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' ========================================================================================

' ========================================================================================
' Retrieves a pointer to the CWindow class and returns a reference counted object variable.
' ========================================================================================
FUNCTION CWindow_GetObjectFromWindowHandle (BYVAL hwnd AS DWORD) AS IUnknown

   LOCAL hRootOwner AS DWORD                ' // Root owner window handle
   LOCAL pWindowPtr AS DWORD                ' // CWindow class pointer
   LOCAL pWindow AS IUnknown                ' // CWindow class object variable
   LOCAL pv AS DWORD PTR                    ' // Pointer variable

   IF hwnd = %NULL THEN EXIT FUNCTION
   hRootOwner = GetAncestor(hwnd, %GA_ROOTOWNER)
   IF hRootOwner = %NULL THEN EXIT FUNCTION
   pWindowPtr = GetClassLong(hRootOwner, 0)
   IF pWindowPtr = 0 THEN EXIT FUNCTION
   pv = VARPTR(pWindow)
   @pv = pWindowPtr
   IF ISOBJECT(pWindow) THEN
      pWindow.AddRef
      FUNCTION = pWindow
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the MDI client window handle, if any.
' ========================================================================================
#IF %USEMDI = 1
FUNCTION CWindow_GetMDIClientHandle (BYVAL hwnd AS DWORD) AS DWORD
   IF hwnd = 0 THEN EXIT FUNCTION
   FUNCTION = GetClassLong(hwnd, 4)
END FUNCTION
#ENDIF
' ========================================================================================

' ========================================================================================
' Destroys all MDI child windows.
' ========================================================================================
#IF %USEMDI = 1
FUNCTION CWindow_CloseEnumProc ( _
   BYVAL hwnd   AS DWORD, _                 ' // Handle of enumerated child window
   BYVAL lParam AS LONG _                   ' // Unused
   ) AS LONG

   ' // Skip icon title windows
   IF ISTRUE GetWindow(hwnd, %GW_OWNER) THEN
      FUNCTION = %TRUE
      EXIT FUNCTION
   END IF

   SendMessage GetParent(hwnd), %WM_MDIRESTORE, hwnd, 0
   IF ISFALSE SendMessage(hwnd, %WM_QUERYENDSESSION, 0, 0) THEN
      FUNCTION = %TRUE
      EXIT FUNCTION
   END IF

   SendMessage GetParent(hwnd), %WM_MDIDESTROY, hwnd, 0

   FUNCTION = %TRUE

END FUNCTION
#ENDIF
' ========================================================================================

' ========================================================================================
' Default CWindow callback function.
' ========================================================================================
FUNCTION CWindowProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

#IF %USEMDI = 1
   LOCAL hwndClient AS DWORD    ' // Handle of the MDI client window
   LOCAL hwndActive AS DWORD    ' // Active window
   LOCAL hMdi AS DWORD          ' // MDI child window handle
#ENDIF

#IF %USEMDI = 1
   ' // MDI client window handle
   hwndClient = CWindow_GetMDIClientHandle(hwnd)
#ENDIF

   SELECT CASE uMsg

      CASE %WM_SYSCOMMAND
         ' // Capture this message and send a WM_CLOSE message
         ' // Note: Needed with some OCXs, that otherwise remain in memory
         IF (wParam AND &HFFF0) = %SC_CLOSE THEN
            SendMessage hwnd, %WM_CLOSE, 0, 0
            EXIT FUNCTION
         END IF

      CASE %WM_COMMAND

         SELECT CASE LO(WORD, wParam)
            CASE %IDCANCEL
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  SendMessage hwnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT

#IF %USEMDI = 1
         IF hwndClient THEN
            ' // Pass unprocessed messages to the active MDI child and then to DefFrameProc()
            hwndActive = SendMessage(hwndClient, %WM_MDIGETACTIVE, 0, 0)
            IF IsWindow(hwndActive) THEN SendMessage hwndActive, %WM_COMMAND, wParam, lParam
         END IF
#ENDIF

      CASE %WM_NOTIFY
'         LOCAL ptnmhdr AS NMHDR PTR
'         ptnmhdr = lParam
'         SELECT CASE @ptnmhdr.idFrom
'            ' ...
'            ' ...
'         END SELECT

#IF %USEMDI = 1
         IF hwndClient THEN
            ' // Pass unprocessed messages to the active MDI child and then to DefFrameProc()
            hwndActive = SendMessage(hwndClient, %WM_MDIGETACTIVE, 0, 0)
            IF ISTRUE IsWindow(hwndActive) THEN SendMessage hwndActive, %WM_NOTIFY, wParam, lParam
         END IF
#ENDIF

'      CASE %WM_SIZE
'#IF %USEMDI = 1
'         ' // If the window isn't minimized, resize it (sample code)
'         LOCAL rc AS RECT
'         IF wParam <> %SIZE_MINIMIZED THEN
'            IF hwndClient THEN
'               GetClientRect hwnd, rc
'               MoveWindow hwndClient, rc.Left, rc.Top, rc.Right + 2, rc.Bottom + 2, %TRUE
'            END IF
'         END IF
'#ENDIF
         ' // Note: This message is not passed to DefFrameProc when space
         ' // is being reserved in the client area of the MDI frame
         ' // or controls on the MDI frame are resizeable.
'         EXIT FUNCTION

#IF %USEMDI = 1
      CASE %WM_CLOSE
         IF hwndClient THEN
            ' // Attempt to close all MDI child windows
            EnumChildWindows hwndClient, CODEPTR(CWindow_CloseEnumProc), 0
            ' // If child windows are still open abort closing the application
            IF GetWindow(hwndClient, %GW_CHILD) THEN EXIT FUNCTION
         END IF
#ENDIF

#IF %USEMDI = 1
      CASE %WM_QUERYENDSESSION
         IF hwndClient THEN
            ' // Attempt to close all MDI child windows
            EnumChildWindows hwndClient, CODEPTR(CWindow_CloseEnumProc), 0
            ' // If child windows are still open abort closing the application
            IF GetWindow(hwndClient, %GW_CHILD) THEN EXIT FUNCTION
         END IF
#ENDIF

      CASE %WM_DESTROY
         ' // Close the main window
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

#IF %USEMDI = 1
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
#ELSE
   FUNCTION = DefWindowProc(hwnd, uMsg, wParam, lParam)
#ENDIF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Default CWindow MDI callback function.
' ========================================================================================
#IF %USEMDI = 1
FUNCTION CWindowMDIProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   SELECT CASE uMsg

'      CASE %WM_CREATE
         ' // Retrieve a reference to the CWindow class
'         LOCAL pWindow AS IWindow
'         pWindow = CWindow_GetObjectFromHandle(hwnd)
         ' // Create controls (sample code)
'         LOCAL rc AS RECT
'         pWindow.AddTextBox(hwnd, %IDC_EDIT, "", 0, 0, rc.Right, rc.Bottom, _
'            %WS_CHILD OR %WS_VISIBLE OR %ES_MULTILINE OR %WS_VSCROLL OR %WS_HSCROLL OR %ES_AUTOHSCROLL OR %ES_AUTOVSCROLL OR %ES_NOHIDESEL, 0)
'         EXIT FUNCTION

'      CASE %WM_MDIACTIVATE
'         IF lParam = hwnd THEN
'         END IF
'         EXIT FUNCTION

      CASE %WM_SETFOCUS
         ' // Set the keyboard focus to the first control that is
         ' // visible, not disabled, and has the WS_TABSTOP style
         SetFocus GetNextDlgTabItem(hwnd, %NULL, %FALSE)

'      CASE %WM_SIZE
'         IF wParam <> %SIZE_MINIMIZED THEN
            ' Resize the window and its controls
'         END IF

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
#ENDIF
' ========================================================================================

' ========================================================================================
' Input box dialog
' Parameters:
' - hParent = Handle of the parent window
' - x, y = The location on the screen to display the dialog. If both are 0, the dialog
'   is centered on the screen.
' - strCaption = Caption of the window
' - strPrompt = Prompt string
' - strText = Text to edit
' - nLen = [opt] Maximum length of the string to edit (default = 260 characters)
' - bPassword = [opt] TRUE or FALSE. Default FALSE. Displays all characters as an
'     asterisk (*) as they are typed into the edit control.
'   Note: The maximum length is 2048 characters.
' ========================================================================================
#IF %DEF(%UNICODE)
FUNCTION CWindow_InputBox (BYVAL hParent AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, BYVAL strCaption AS WSTRING, BYVAL strPrompt AS WSTRING, BYVAL strText AS WSTRING, OPTIONAL BYVAL nLen AS LONG, BYVAL bPassword AS LONG) AS WSTRING
#ELSE
FUNCTION CWindow_InputBox (BYVAL hParent AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, BYVAL strCaption AS STRING, BYVAL strPrompt AS STRING, BYVAL strText AS STRING, OPTIONAL BYVAL nLen AS LONG, BYVAL bPassword AS LONG) AS STRING
#ENDIF

   LOCAL hEdit AS DWORD
   LOCAL dwStyle AS DWORD
#IF %DEF(%UNICODE)
   LOCAL szText AS WSTRINGZ * 2049
#ELSE
   LOCAL szText AS ASCIIZ * 2049
#ENDIF

   ' // Create an instance of the class
   LOCAL pInputBox AS IWindow
   pInputBox = CLASS "CWindow"
   IF ISNOTHING(pInputBox) THEN EXIT FUNCTION

   ' // Create the main window
   LOCAL hwnd AS DWORD
   hwnd = pInputBox.CreateWindow(hParent, strCaption, x, y, 276, 142, _
          %WS_VISIBLE OR %WS_CAPTION OR %WS_POPUPWINDOW, %WS_EX_DLGMODALFRAME OR %WS_EX_CONTROLPARENT, _
          CODEPTR(CWindow_InputBox_WindowProc))
   ' // Center the window
   IF x = 0 AND y = 0 THEN
      pInputBox.CenterWindow(hwnd, hParent)
   END IF

   ' // Add a label control
   pInputBox.AddLabel(hwnd, -1, strPrompt, 21, 10, 240, 19, -1, -1)

   ' // Add a TextBox control
   dwStyle = %WS_VISIBLE OR %WS_TABSTOP OR %ES_LEFT OR %ES_AUTOHSCROLL
   IF bPassWord THEN dwStyle = dwStyle OR %ES_PASSWORD
   hEdit = pInputBox.AddTextBox(hwnd, 101, "", 21, 33, 230, 19, dwStyle, -1)

   ' // Add the buttons
   pInputBox.AddButton(hwnd, %IDOK, "&Ok", 21, 72, 75, 22, -1, -1)
   pInputBox.AddButton(hwnd, %IDCANCEL, "&Cancel", 176, 72, 75, 22, -1, -1)

   ' // Set the text
   IF nLen = 0 THEN
      nLen = 260
   ELSE
      IF nLen < 1 OR nLen > 2048 THEN nLen = 2048
   END IF
   SendMessage hEdit, %EM_LIMITTEXT, nLen, 0
   IF LEN(strText) > nLen THEN strText = LEFT$(strText, nLen)
   SendMessage(hEdit, %WM_SETTEXT, 0, STRPTR(strText))
   SendMessage hEdit, %EM_SETSEL, 0, -1

   ' // Set the focus in the edit control
   SetFocus hEdit

   ' // Pointer to the allocated string to return the result
   SendMessage hwnd, %WM_USER + 1, VARPTR(szText), 0

   ' // Default message pump (you can replace it with your own)
   pInputBox.DoEvents

   ' // Enable the parent window
   EnableWindow hParent, %TRUE

   FUNCTION = szText

END FUNCTION
' ========================================================================================

' ========================================================================================
' Input box callback function.
' ========================================================================================
FUNCTION CWindow_InputBox_WindowProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL nLen   AS LONG
#IF %DEF(%UNICODE)
   STATIC pText AS WSTRINGZ PTR
#ELSE
   STATIC pText AS ASCIIZ PTR
#ENDIF

   SELECT CASE uMsg

      CASE %WM_CREATE
         ' // Disable the owner of the modal window
         EnableWindow GetWindow(hwnd, %GW_OWNER), %FALSE

      CASE %WM_USER + 1
         ' // Pointer to allocated string to return the result
         IF wParam THEN
            pText = wParam
            EXIT FUNCTION
         END IF

      CASE %WM_COMMAND

         SELECT CASE LO(WORD, wParam)

            CASE %IDCANCEL
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  SendMessage hwnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF

            CASE %IDOK
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  nLen = SendMessage(GetDlgItem(hwnd, 101), %WM_GETTEXTLENGTH, 0, 0)
                  IF nLen > 2048 THEN nLen = 2048
                  nLen = SendMessage(GetDlgItem(hwnd, 101), %WM_GETTEXT, nLen + 1, pText)
                  SendMessage hwnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF

         END SELECT

      CASE %WM_CLOSE
         ' // The owner window is enabled in WM_CLOSE rather than WM_DESTROY to
         ' // prevent the application from losing the focus. In WM_DESTROY the
         ' // modal window has already been removed from the screen by the system
         ' // and because the remaining windows are disabled, the system gives
         ' // the focus to another application.
         EnableWindow GetWindow(hwnd, %GW_OWNER), %TRUE

      CASE %WM_DESTROY
         ' // Close the main window
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
