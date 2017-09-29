' ########################################################################################
' Microsoft Windows
' File: GdipImageCtx.inc
' Contents: A GDI+ image control
' Copyright (c) 2011 José Roca. All Rights Reserved.
' Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%GDIPIMAGECTX_INC = 1

#INCLUDE ONCE "GdiPlus.inc"

%GDIP_IMAGECTX_AUTOSIZE    = 0   ' // Autoadjusts the image to the width or height of the control
%GDIP_IMAGECTX_ACTUALSIZE  = 1   ' // Shows the image with its actual size
%GDIP_IMAGECTX_FITTOWIDTH  = 2   ' // Adjusts the image to the width of the control
%GDIP_IMAGECTX_FITTOHEIGHT = 3   ' // Adjusts the image to the height of the control
%GDIP_IMAGECTX_STRETCH     = 4   ' // Adjusts the image to the height and width of the control

' // Notification messages
'%NM_CLICK           = %NM_FIRST - 2
'%NM_DBLCLK          = %NM_FIRST - 3
'%NM_RCLICK          = %NM_FIRST - 5
'%NM_RDBLCLK         = %NM_FIRST - 6
'%NM_SETFOCUS        = %NM_FIRST - 7
'%NM_KILLFOCUS       = %NM_FIRST - 8

' // Process them in the main window callback as follows:
'
' CASE %WM_NOTIFY
'    LOCAL phdr AS NMHDR PTR
'    phdr = lParam
'    IF wParam = %IDC_GRCTX THEN
'       SELECT CASE @phdr.code
'          CASE %NM_CLICK
'             ' Left button clicked
'          CASE %NM_RCLICK
'             ' Right button clicked
'          CASE %NM_SETFOCUS
'             ' The control has gained focus
'          CASE %NM_KILLFOCUS
'             ' The control has lost focus
'       END SELECT
'    END IF

' ========================================================================================
' GDIP_IMAGECTXDATA structure
' ========================================================================================
TYPE GDIP_IMAGECTXDATA
   m_pImage    AS DWORD     ' // Image object pointer
   m_token     AS DWORD     ' // Token returned by GdiplusStartup
   m_BkColor   AS LONG      ' // RGB background color
   m_Fit       AS LONG      ' // Fit to width/height
END TYPE
' ========================================================================================

' ========================================================================================
' Registers the window class
' ========================================================================================
FUNCTION InitGdipImageCtx () AS WORD

   LOCAL  wcex AS WNDCLASSEX               ' // WNDCLASSEX structure
   STATIC wAtom AS WORD                    ' // Atom

   ' Already initialized
   IF wAtom <> 0 THEN
      FUNCTION = wAtom
      EXIT FUNCTION
   END IF

#IF %DEF(%UNICODE)
   LOCAL szClassName AS WSTRINGZ * 256    ' // Class name
#ELSE
   LOCAL szClassName AS ASCIIZ * 256      ' // Class name
#ENDIF

   szClassName        = "GDIPIMAGECTX"
   wcex.cbSize        = SIZEOF(wcex)
   wcex.style         = %CS_HREDRAW OR %CS_VREDRAW ' OR %CS_GLOBALCLASS
   wcex.lpfnWndProc   = CODEPTR(GdipImageCtxProc)
   wcex.cbClsExtra    = 0
   wcex.cbWndExtra    = 4 ' For pointer to GDIP_IMAGECTXDATA structure
   wcex.hInstance     = GetModuleHandle(BYVAL %NULL)
   wcex.hIcon         = %NULL
   wcex.hCursor       = LoadCursor(%NULL, BYVAL %IDC_ARROW)
   wcex.hbrBackground = GetStockObject(%WHITE_BRUSH)
   wcex.lpszMenuName  = %NULL
   wcex.lpszClassName = VARPTR(szClassName)
   wcex.hIconSm       = %NULL

   wAtom = RegisterClassEx(wcex)
   FUNCTION = wAtom

END FUNCTION
' ========================================================================================

' ========================================================================================
' Draws the image
' Returns %StatusOk or an error code.
' ========================================================================================
FUNCTION GdipImageCtx_DrawImage (BYVAL hwnd AS DWORD, BYVAL hDc AS DWORD, BYVAL pImage AS DWORD) AS LONG

   LOCAL hStatus AS LONG                   ' // Result code
   LOCAL pGraphics AS DWORD                ' // Graphics object pointer
   LOCAL hBgBrush AS DWORD                 ' // Background brush
   LOCAL ImageWidth AS LONG                ' // Image width
   LOCAL ImageHeight AS LONG               ' // Image heigth
   LOCAL p AS LONG                         ' // Percent
   LOCAL w AS LONG                         ' // Width
   LOCAL h AS LONG                         ' // Height
   LOCAL cx AS LONG                        ' // x-coordinate for center fill
   LOCAL cy AS LONG                        ' // y-coordinate for center fill
   LOCAL nFit AS LONG                      ' // Fit
   LOCAL rc AS RECT                        ' // client area
   LOCAL rcFill AS RECT                    ' // Fill area
   LOCAL pData AS GDIP_IMAGECTXDATA PTR    ' // Pointer to the control data

   ' // Checks the validity of the parameter
   IF hwnd = %NULL THEN EXIT FUNCTION
   ' // Gets a Pointer to the control data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION

   ' // Check parameters validity
   IF hWnd = %NULL OR hDc = %NULL OR pImage = %NULL THEN
      FUNCTION = %E_POINTER
      EXIT FUNCTION
   END IF

   ' // Retrieves the coordinates of the window's client area
   GetClientRect hwnd, rc

   ' // Retrieves the width and height of the image
   hStatus = GdipGetImageWidth(pImage, ImageWidth)
   hStatus = GdipGetImageHeight(pImage, ImageHeight)

   ' // Creates a Graphics object
   hStatus = GdipCreateFromHDC(hdc, pGraphics)

   ' // Draws the image
   IF pGraphics THEN
      nFit = @pData.m_Fit
      IF nFit = %GDIP_IMAGECTX_AUTOSIZE THEN
         IF ImageWidth / (rc.nRight - rc.nLeft) > ImageHeight / (rc.nBottom - rc.nTop) THEN
            nFit = %GDIP_IMAGECTX_FITTOWIDTH
         ELSE
            nFit = %GDIP_IMAGECTX_FITTOHEIGHT
         END IF
      END IF
      IF nFit = %GDIP_IMAGECTX_ACTUALSIZE THEN
         ' // If the width of the image is smaller than the width of the control
         ' // calculate the position for a centered image
         w = ImageWidth
         h = ImageHeight
         IF w < (rc.nRight - rc.nLeft) THEN
            cx = ((rc.nRight - rc.nLeft) - w) / 2
         END IF
         IF h < (rc.nBottom - rc.nTop) THEN
            cy = ((rc.nBottom - rc.nTop) - h) / 2
         END IF
         ' // Draw the image
         hStatus = GdipDrawImageRectI(pGraphics, @pData.m_pImage, cx, cy, ImageWidth, ImageHeight)
         ' // Creates a brush and fills the client area of the window not covered by the image
         hBgBrush = CreateSolidBrush(@pData.m_BkColor)
         GetClientRect hwnd, rcFill
         rcFill.nLeft = 0
         rcFill.nRight = cx
         FillRect hDc, rcFill, hBgBrush
         GetClientRect hwnd, rcFill
         rcFill.nLeft = cx + w
         FillRect hDc, rcFill, hBgBrush
         GetClientRect hwnd, rcFill
         rcFill.nLeft = cx
         rcFill.nRight = cx + w
         rcFill.nBottom = cy
         FillRect hDc, rcFill, hBgBrush
         GetClientRect hwnd, rcFill
         rcFill.nLeft = cx
         rcFill.nRight = cx + w
         rcFill.nTop = cy + h
         FillRect hDc, rcFill, hBgBrush
         ' // Deletes the brush
         DeleteObject hBgBrush
      ELSEIF nFit = %GDIP_IMAGECTX_STRETCH THEN
        ' Stretch or shrunk to fill the controls client area
         w = rc.nRight - rc.nLeft
         h = rc.nBottom - rc.nTop
         hStatus = GdipDrawImageRectI(pGraphics, @pData.m_pImage, 0, 0, w, h)
      ELSEIF nFit = %GDIP_IMAGECTX_FITTOWIDTH THEN
         ' // Calculate the percent of reduction or ampliation
         ' // and adjust the image height
         p = ((rc.nRight - rc.nLeft) * 100) / ImageWidth
         w = rc.nRight - rc.nLeft
         h = ImageHeight * p / 100
         ' // If the height of the image is smaller than the height of the control
         ' // calculate the position for a centered image
         IF h < (rc.nBottom - rc.nTop) THEN
            cy = ((rc.nBottom - rc.nTop) - h) / 2
         END IF
         hStatus = GdipDrawImageRectI(pGraphics, @pData.m_pImage, 0, cy, w, h)
         ' // Creates a brush and fills the client area of the window not covered by the image
         hBgBrush = CreateSolidBrush(@pData.m_BkColor)
         GetClientRect hwnd, rcFill
         rcFill.nBottom = cy
         FillRect hDC, rcFill, hBgBrush
         GetClientRect hwnd, rcFill
         rcFill.nTop = cy + h
         FillRect hDC, rcFill, hBgBrush
         ' // Deletes the brush
         DeleteObject hBgBrush
      ELSE
         ' // Calculate the percent of reduction or ampliation
         ' // and adjust the image width
         IF ImageHeight <> rc.nBottom - rc.nTop THEN
            p = ((rc.nBottom - rc.nTop) * 100) /  ImageHeight
            h = rc.nBottom - rc.nTop
            w = ImageWidth * p / 100
         ELSE
            h = ImageHeight
            w = ImageWidth
         END IF
         ' // If the width of the image is smaller than the width of the control
         ' // calculate the position for a centered image
         IF w < (rc.nRight - rc.nLeft) THEN
            cx = ((rc.nRight - rc.nLeft) - w) / 2
         END IF
         ' // Draws the image
         hStatus = GdipDrawImageRectI(pGraphics, @pData.m_pImage, cx, 0, w, h)
         ' // Creates a brush and fills the client area of the window not covered by the image
         hBgBrush = CreateSolidBrush(@pData.m_BkColor)
         GetClientRect hwnd, rcFill
         rcFill.nLeft = 0
         rcFill.nRight = cx
         FillRect hDC, rcFill, hBgBrush
         GetClientRect hwnd, rcFill
         rcFill.nLeft = cx + w
         FillRect hDC, rcFill, hBgBrush
         ' // Deletes the brush
         DeleteObject hBgBrush
      END IF
      ' // Deletes the Graphics object
      GdipDeleteGraphics(pGraphics)
   ELSE
      ' // Creates a brush and fills the client area of the window
      hBgBrush = CreateSolidBrush(@pData.m_BkColor)
      GetClientRect hwnd, rcFill
      FillRect hDC, rcFill, hBgBrush
      ' // Deletes the brush
      DeleteObject hBgBrush
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Control callback procedure
' ========================================================================================
FUNCTION GdipImageCtxProc (BYVAL hwnd AS DWORD, BYVAL wMsg AS DWORD, _
                           BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL hStatus AS LONG                       ' // Result code
   LOCAL hDc AS DWORD                          ' // Device context handle
   LOCAL phdr AS NMHDR                         ' // NMHDR structure
   LOCAL pData AS GDIP_IMAGECTXDATA PTR        ' // Pointer to the control data
   LOCAL ps AS PAINTSTRUCT                     ' // PAINTSTRUCT structure
   LOCAL StartupInput AS GdiplusStartupInput   ' // GdiplusStartupInput structure

   ' // Gets a pointer to control data
   IF hwnd <> %NULL AND wMsg <> %WM_CREATE THEN pData = GetWindowLong(hwnd, 0)

   SELECT CASE wMsg

      CASE %WM_CREATE
         ' // Allocates memory for the control's data
'         pData = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@pData))
         pData = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(GDIP_IMAGECTXDATA))
         IF pData THEN
            ' // Stores the pointer in the cbWndExtra member of the window class
            SetWindowLong hwnd, 0, pData
            ' // Initialize GDI+
            StartupInput.GdiplusVersion = 1
            hStatus = GdiplusStartup(@pData.m_token, StartupInput, BYVAL %NULL)
            IF hStatus <> %StatusOk OR @pData.m_token = 0 THEN
               FUNCTION = -1   ' // Abort the action
               EXIT FUNCTION
            END IF
         ELSE
            FUNCTION = -1   ' // Abort the action
         END IF
         EXIT FUNCTION

      CASE %WM_DESTROY
         ' // Destroy the Image object
         IF @pData.m_pImage THEN GdipDisposeImage(@pData.m_pImage)
         ' // Shutdown GDI+
         IF @pData.m_token THEN GdiplusShutdown @pData.m_token
         ' // Deallocates the memory used for the control data
         IF pData THEN CALL HeapFree(GetProcessHeap(), 0, BYVAL pData)
         EXIT FUNCTION

      CASE %WM_ERASEBKGND
         ' // Don't erase the background to avoid flicker
         FUNCTION = 1
         EXIT FUNCTION

      CASE %WM_PRINTCLIENT
         ' // Draws the image in the provided device context
         hDc = wParam
         GdipImageCtx_DrawImage(hwnd, hdc, @pData.m_pImage)
         EXIT FUNCTION

      CASE %WM_PAINT
         ' // Prepares the window for painting
         hDc = BeginPaint(hwnd, ps)
         ' // Draws the image
         GdipImageCtx_DrawImage(hwnd, hdc, @pData.m_pImage)
         ' // Ends the painting of the window
         EndPaint hwnd, ps
         EXIT FUNCTION

      CASE %WM_COMMAND, %WM_NOTIFY
         ' // Forwards the message to the parent window
         SendMessage GetParent(hwnd), wMsg, wParam, lParam

      CASE %WM_GETDLGCODE
        ' // Ensures that the control will process all the keystrokes by itself
        FUNCTION = %DLGC_WANTALLKEYS
        EXIT FUNCTION

      CASE %WM_KEYDOWN
         SELECT CASE (wParam)
            ' // Must handle tab key by ourselves, since we have taken full control
            CASE %VK_TAB
               IF HI(WORD, GetKeyState(%VK_SHIFT)) = 0 THEN
                  SetFocus GetNextDlgTabItem(GetParent(hwnd), hwnd, 0)
               ELSE
                  SetFocus GetNextDlgTabItem(GetParent(hwnd), hwnd, -1)
               END IF
         END SELECT

      CASE %WM_LBUTTONDOWN
         ' // Forwards the message to the parent window
         phdr.hwndFrom = hwnd
         phdr.idFrom = GetDlgCtrlId(hwnd)
         phdr.code = %NM_CLICK
         SendMessage GetParent(hwnd), %WM_NOTIFY, GetDlgCtrlId(hwnd), VARPTR(phdr)
         EXIT FUNCTION

      CASE %WM_RBUTTONDOWN
         ' // Forwards the message to the parent window
         phdr.hwndFrom = hwnd
         phdr.idFrom = GetDlgCtrlId(hwnd)
         phdr.code = %NM_RCLICK
         SendMessage GetParent(hwnd), %WM_NOTIFY, GetDlgCtrlId(hwnd), VARPTR(phdr)
         EXIT FUNCTION

      CASE %WM_LBUTTONDBLCLK
         ' // Forwards the message to the parent window
         phdr.hwndFrom = hwnd
         phdr.idFrom = GetDlgCtrlId(hwnd)
         phdr.code = %NM_DBLCLK
         SendMessage GetParent(hwnd), %WM_NOTIFY, GetDlgCtrlId(hwnd), VARPTR(phdr)
         EXIT FUNCTION

      CASE %WM_RBUTTONDBLCLK
         ' // Forwards the message to the parent window
         phdr.hwndFrom = hwnd
         phdr.idFrom = GetDlgCtrlId(hwnd)
         phdr.code = %NM_RDBLCLK
         SendMessage GetParent(hwnd), %WM_NOTIFY, GetDlgCtrlId(hwnd), VARPTR(phdr)
         EXIT FUNCTION

      CASE %WM_SETFOCUS
         ' // Forwards the message to the parent window
         phdr.hwndFrom = hwnd
         phdr.idFrom = GetDlgCtrlId(hwnd)
         phdr.code = %NM_SETFOCUS
         SendMessage GetParent(hwnd), %WM_NOTIFY, GetDlgCtrlId(hwnd), VARPTR(phdr)
         EXIT FUNCTION

      CASE %WM_KILLFOCUS
         ' // Forwards the message to the parent window
         phdr.hwndFrom = hwnd
         phdr.idFrom = GetDlgCtrlId(hwnd)
         phdr.code = %NM_KILLFOCUS
         SendMessage GetParent(hwnd), %WM_NOTIFY, GetDlgCtrlId(hwnd), VARPTR(phdr)
         EXIT FUNCTION

      CASE %WM_ENABLE
         ' // Redraws the control
         InvalidateRect hwnd, BYVAL %NULL, 0
         UpdateWindow hwnd
         EXIT FUNCTION

   END SELECT

   ' // Default processing for other messages.
   FUNCTION = DefWindowProc(hwnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================


' ########################################################################################
' ###########################  FUNCTIONS AND PROCEDURES ##################################
' ########################################################################################

' ========================================================================================
' Loads an image from file using GDI+
' Parameters:
' * hwnd = Control's window handle
' * wszFileName = Fully qualified path and filename of the image file to load.
' Return value:
' * %StatusOk or an error code.
' ========================================================================================
FUNCTION GdipImageCtx_LoadImageFromFile (BYVAL hwnd AS DWORD, BYREF wszFileName AS WSTRINGZ) AS LONG

   LOCAL hStatus AS LONG                   ' // Result code
   LOCAL hDc AS DWORD                      ' // Device context handle
   LOCAL hBgBrush AS DWORD                 ' // Background brush
   LOCAL rc AS RECT                        ' // Image bounds
   LOCAL rcFill AS RECT                    ' // Fill area
   LOCAL pData AS GDIP_IMAGECTXDATA PTR    ' // Pointer to the control data

   ' // Checks the validity of the parameters
   IF hwnd = %NULL THEN FUNCTION = %E_POINTER : EXIT FUNCTION
   IF LEN(wszFileName) = 0 THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION

   ' // Gets a Pointer to the control data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN FUNCTION = %E_POINTER : EXIT FUNCTION

   ' // Dispose a previous instance of the Image object, if any
   IF @pData.m_pImage THEN
      GdipDisposeImage(@pData.m_pImage)
      @pData.m_pImage = 0
   END IF

   ' // Loads the image
   hStatus = GdipLoadImageFromFile(wszFileName, @pData.m_pImage)

   ' // Erases the window's client area
   hBgBrush = CreateSolidBrush(@pData.m_BkColor)
   IF hBgBrush THEN
      hDc = GetDc(hwnd)
      IF hDc THEN
         GetClientRect hwnd, rcFill
         FillRect hDc, rcFill, hBgBrush
         DeleteDc hDc
      END IF
      DeleteObject hBgBrush
   END IF

   ' // Redraws the control
   InvalidateRect hwnd, BYVAL %NULL, 0
   UpdateWindow hwnd

   FUNCTION = hStatus

END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads a bitmap from a resource file using GDI+
' Parameters:
' * hwnd = Control's window handle
' * hInstance = Instance handle
' * wszResourceName = Name of the resource.
' Return value:
' * %StatusOk or an error code.
' Note: In Windows 7, it fails to load .jpg and .tif files. Works with .bmp and .png files.
' ========================================================================================
FUNCTION GdipImageCtx_LoadBitmapFromResource (BYVAL hwnd AS DWORD, BYVAL hInstance AS DWORD, BYREF wszResourceName AS WSTRINGZ) AS LONG

   LOCAL hStatus AS LONG                   ' // Result code
   LOCAL hDc AS DWORD                      ' // Device context handle
   LOCAL hBgBrush AS DWORD                 ' // Background brush
   LOCAL imageSize AS DWORD                ' // Image size
   LOCAL rc AS RECT                        ' // Image bounds
   LOCAL rcFill AS RECT                    ' // Fill area
   LOCAL pData AS GDIP_IMAGECTXDATA PTR    ' // Pointer to the control data

   ' // Checks the validity of the parameters
   IF hwnd = %NULL THEN FUNCTION = %E_POINTER : EXIT FUNCTION
   IF LEN(wszResourceName) = 0 THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION

   ' // Gets a Pointer to the control data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN FUNCTION = %E_POINTER : EXIT FUNCTION

   ' // Dispose a previous instance of the Image object, if any
   IF @pData.m_pImage THEN
      GdipDisposeImage(@pData.m_pImage)
      @pData.m_pImage = 0
   END IF

   hStatus = GdipCreateBitmapFromResource(hInstance, wszResourceName, @pData.m_pImage)

   ' // Erases the window's client area
   hBgBrush = CreateSolidBrush(@pData.m_BkColor)
   IF hBgBrush THEN
      hDc = GetDc(hwnd)
      IF hDc THEN
         GetClientRect hwnd, rcFill
         FillRect hDc, rcFill, hBgBrush
         DeleteDc hDc
      END IF
      DeleteObject hBgBrush
   END IF

   ' // Redraws the control
   InvalidateRect hwnd, BYVAL %NULL, 0
   UpdateWindow hwnd

   FUNCTION = hStatus

END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads an image from a resource file using GDI+
' Parameters:
' * hwnd = Control's window handle
' * hInstance = Instance handle
' * wszResourceName = Name of the resource image.
' Return value:
' * %StatusOk or an error code.
' ========================================================================================
FUNCTION GdipImageCtx_LoadImageFromResource (BYVAL hwnd AS DWORD, BYVAL hInstance AS DWORD, BYREF wszResourceName AS WSTRINGZ) AS LONG

   LOCAL hStatus AS LONG                   ' // Result code
   LOCAL hDc AS DWORD                      ' // Device context handle
   LOCAL pGraphics AS DWORD                ' // Graphocs object pointer
   LOCAL hResource AS DWORD                ' // Resource handle
   LOCAL pResourceData AS DWORD            ' // Pointer to the resoruce data
   LOCAL hGlobal AS DWORD                  ' // Global memory handle
   LOCAL pGlobalBuffer AS DWORD            ' // Pointer to global memory buffer
   LOCAL pImageStream AS IStream           ' // IStream interface pointer
   LOCAL hBgBrush AS DWORD                 ' // Background brush
   LOCAL imageSize AS DWORD                ' // Image size
   LOCAL rc AS RECT                        ' // Image bounds
   LOCAL rcFill AS RECT                    ' // Fill area
   LOCAL pData AS GDIP_IMAGECTXDATA PTR    ' // Pointer to the control data

   ' // Checks the validity of the parameters
   IF hwnd = %NULL THEN FUNCTION = %E_POINTER : EXIT FUNCTION
   IF LEN(wszResourceName) = 0 THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION

   ' // Gets a Pointer to the control data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN FUNCTION = %E_POINTER : EXIT FUNCTION

   ' // Dispose a previous instance of the Image object, if any
   IF @pData.m_pImage THEN
      GdipDisposeImage(@pData.m_pImage)
      @pData.m_pImage = 0
   END IF

   ' // Find the resource and lock it
   hResource = FindResourceW(hInstance, wszResourceName, BYVAL %RT_RCDATA)
   IF hResource = %NULL THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION
   imageSize = SizeofResource(hInstance, hResource)
   IF imageSize = 0 THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION
   pResourceData = LockResource(LoadResource(hInstance, hResource))
   IF pResourceData = %NULL THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION
   ' // Allocate memory to hold the image
   hGlobal = GlobalAlloc(%GMEM_MOVEABLE, imageSize)
   IF hGlobal THEN
      ' // Lock the memory
      pGlobalBuffer = GlobalLock(hGlobal)
      IF pGlobalBuffer THEN
         ' // Copy the image from the resource file to global memory
         CopyMemory pGlobalBuffer, pResourceData, imageSize
         ' // Create an stream in global memory
         IF CreateStreamOnHGlobal(hGlobal, %FALSE, pImageStream) = %S_OK THEN
            ' // Create a bitmap from the data contained in the stream
            hStatus = GdipCreateBitmapFromStream(pImageStream, @pData.m_pImage)
            IF hStatus = %StatusOk THEN
               ' // Gets the device context handle
               hDc = GetDc(hwnd)
               ' // Creates a graphics object from it
               IF hDc THEN hStatus = GdipCreateFromHDC(hDc, pGraphics)
               ' // Draws the image (required to keep it in memory, since we are
               ' // going to unlock and free the resource)
               IF pGraphics THEN hStatus = GdipDrawImageI(pGraphics, @pData.m_pImage, 0, 0)
               ' // Deletes the graphics object
               IF pGraphics THEN GdipDeleteGraphics(pGraphics)
               ' // Releases the device context handle
               IF hDc THEN DeleteDc hDc
            END IF
            pImageStream = NOTHING
         END IF
         ' // Unlock the memory
         GlobalUnlock pGlobalBuffer
      END IF
      ' // Free the memory
      GlobalFree hGlobal
   END IF

   ' // Erases the window's client area
   hBgBrush = CreateSolidBrush(@pData.m_BkColor)
   IF hBgBrush THEN
      hDc = GetDc(hwnd)
      IF hDc THEN
         GetClientRect hwnd, rcFill
         FillRect hDc, rcFill, hBgBrush
         DeleteDc hDc
      END IF
      DeleteObject hBgBrush
   END IF

   ' // Redraws the control
   InvalidateRect hwnd, BYVAL %NULL, 0
   UpdateWindow hwnd

   FUNCTION = hStatus

END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads an image from a stream using GDI+
' Parameters:
' * hwnd = Control's window handle
' * wszFileName = Fully qualified path of the compound file that stores the stream.
' * wszStreamName = Name of the stream that stores the image.
' Return value:
' * %StatusOk or an error code.
' ========================================================================================
FUNCTION GdipImageCtx_LoadImageFromStream (BYVAL hwnd AS DWORD, BYREF wszFileName AS WSTRINGZ, BYREF wszStreamName AS WSTRINGZ) AS LONG

   LOCAL hr AS LONG                        ' // HRESULT
   LOCAL hStatus AS LONG                   ' // Result code
   LOCAL hDc AS DWORD                      ' // Device context handle
   LOCAL pGraphics AS DWORD                ' // Graphocs object pointer
   LOCAL hBgBrush AS DWORD                 ' // Background brush
   LOCAL imageSize AS SIZE                 ' // Image size
   LOCAL rc AS RECT                        ' // Image bounds
   LOCAL rcFill AS RECT                    ' // Fill area
   LOCAL pData AS GDIP_IMAGECTXDATA PTR    ' // Pointer to the control data
   LOCAL pIStorage AS IStorage             ' // IStorage interface pointer
   LOCAL pIStream AS IStream               ' // IStream interface pointer

   ' // Checks the validity of the parameters
   IF hwnd = %NULL THEN FUNCTION = %E_POINTER : EXIT FUNCTION
   IF LEN(wszFileName) = 0 THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION
   IF LEN(wszStreamName) = 0 THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION

   ' // Gets a Pointer to the control data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN FUNCTION = %E_POINTER : EXIT FUNCTION

   ' // Dispose a previous instance of the Image object, if any
   IF @pData.m_pImage THEN
      GdipDisposeImage(@pData.m_pImage)
      @pData.m_pImage = 0
   END IF

   ' // Open the compound file and get a pointer to its IStorage interface.
   hr = StgOpenStorage(wszFileName, NOTHING, %STGM_READ OR %STGM_SHARE_EXCLUSIVE, 0, %NULL, pIStorage)
   IF FAILED(hr) THEN
      FUNCTION = hr
      EXIT FUNCTION
   END IF

   ' // Get a pointer to the stream strStreamName in the compound file.
   hr = pIStorage.OpenStream(wszStreamName, 0, %STGM_READ OR %STGM_SHARE_EXCLUSIVE, 0, pIStream)
   IF FAILED(hr) THEN
      FUNCTION = hr
      EXIT FUNCTION
   END IF

   ' // Create a new Image object based on the stream.
   hStatus = GdipLoadImageFromStream(pIStream, @pData.m_pImage)
   IF hStatus <> %StatusOk THEN
      FUNCTION = hStatus
      EXIT FUNCTION
   END IF

   ' // Gets the device context handle
   hDc = GetDc(hwnd)
   ' // Creates a graphics object from it
   IF hDc THEN hStatus = GdipCreateFromHDC(hDc, pGraphics)
   ' // Draws the image (required to keep it in memory, since we are
   ' // going to unlock and free the resource)
   IF pGraphics THEN hStatus = GdipDrawImageI(pGraphics, @pData.m_pImage, 0, 0)
   ' // Deletes the graphics object
   IF pGraphics THEN GdipDeleteGraphics(pGraphics)

   ' // Erases the window's client area
   hBgBrush = CreateSolidBrush(@pData.m_BkColor)
   IF hBgBrush THEN
      hDc = GetDc(hwnd)
      IF hDc THEN
         GetClientRect hwnd, rcFill
         FillRect hDc, rcFill, hBgBrush
         DeleteDc hDc
      END IF
      DeleteObject hBgBrush
   END IF

   ' // Redraws the control
   InvalidateRect hwnd, BYVAL %NULL, 0
   UpdateWindow hwnd

   FUNCTION = %StatusOk

END FUNCTION
' ========================================================================================

' ========================================================================================
' Redraws the control.
' Parameters:
' * hwnd = Control's window handle
' Return value:
' * No return value.
' ========================================================================================
SUB GdipImageCtx_Redraw (BYVAL hwnd AS DWORD)
   IF hwnd = %NULL THEN EXIT SUB
   InvalidateRect hwnd, BYVAL %NULL, 0
   UpdateWindow hwnd
END SUB
' ========================================================================================

' ========================================================================================
' Sets the image adjustment.
' Parameters:
' * hwnd = Control's window handle
' * ImageAdjustment =
'     %GDIP_IMAGECTX_AUTOSIZE = 0
'        Autoadjusts the image to the width or height of the control
'     %GDIP_IMAGECTX_ACTUALSIZE = 1
'        Shows the image with its actual size
'     %GDIP_IMAGECTX_FITTOWIDTH = 2
'        Adjusts the image to the width of the control
'     %GDIP_IMAGECTX_FITTOHEIGHT = 3
'        Adjusts the image to the height of the control
' * fRedraw = [optional] TRUE or FALSE (redraws the control to reflect the changes)
' Return value:
' * Returns the previous setting.
' ========================================================================================
FUNCTION GdipImageCtx_SetImageAdjustment (BYVAL hwnd AS DWORD, BYVAL ImageAdjustment AS LONG, OPTIONAL BYVAL fRedraw AS LONG) AS LONG

   LOCAL pData AS GDIP_IMAGECTXDATA PTR    ' // Pointer to the control data

   ' // Checks the validity of the parameter
   IF hwnd = %NULL THEN EXIT FUNCTION
   ' // Gets a Pointer to the control data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION
   ' // Returns the old setting
   FUNCTION = @pData.m_Fit
   ' // Store the new setting
   @pData.m_Fit = ImageAdjustment
   ' // Redraws the control
   IF fRedraw THEN
      InvalidateRect hwnd, BYVAL %NULL, 0
      UpdateWindow hwnd
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the image adjustment setting.
' Parameter:
' * hwnd = Control's window handle
' Return value:
' * The current adjustment setting.
' ========================================================================================
FUNCTION GdipImageCtx_GetImageAdjustment (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pData AS GDIP_IMAGECTXDATA PTR    ' // Pointer to the control data

   ' // Checks the validity of the parameter
   IF hwnd = %NULL THEN EXIT FUNCTION
   ' // Gets a Pointer to the control data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION
   ' // Returns the setting value
   FUNCTION = @pData.m_Fit

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the width of the image.
' Parameter:
' * hwnd = Control's window handle
' Return value:
' * The width of the image.
' ========================================================================================
FUNCTION GdipImageCtx_GetImageWidth (BYVAL hwnd AS DWORD) AS LONG

   LOCAL hStatus AS LONG                   ' // Result code
   LOCAL ImageWidth AS LONG                ' // Image with
   LOCAL pData AS GDIP_IMAGECTXDATA PTR    ' // Pointer to the control data

   ' // Checks the validity of the parameter
   IF hwnd = %NULL THEN EXIT FUNCTION
   ' // Gets a Pointer to the control data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION
   IF @pData.m_pImage THEN
      hStatus = GdipGetImageWidth(@pData.m_pImage, ImageWidth)
      IF hStatus = %Statusok THEN FUNCTION = ImageWidth
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the height of the image.
' Parameter:
' * hwnd = Control's window handle
' Return value:
' * The height of the image.
' ========================================================================================
FUNCTION GdipImageCtx_GetImageHeight (BYVAL hwnd AS DWORD) AS LONG

   LOCAL hStatus AS LONG                   ' // Result code
   LOCAL ImageHeight AS LONG               ' // Image with
   LOCAL pData AS GDIP_IMAGECTXDATA PTR    ' // Pointer to the control data

   ' // Checks the validity of the parameter
   IF hwnd = %NULL THEN EXIT FUNCTION
   ' // Gets a Pointer to the control data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION
   IF @pData.m_pImage THEN
      hStatus = GdipGetImageHeight(@pData.m_pImage, ImageHeight)
      IF hStatus = %Statusok THEN FUNCTION = ImageHeight
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the background color of the control.
' Parameters:
' * hwnd = Control's window handle
' * clr = RGB color.
' * fRedraw = [optional] TRUE or FALSE (redraws the control to reflect the changes)
' Return value:
' * Returns the previous background color.
' ========================================================================================
FUNCTION GdipImageCtx_SetBkColor (BYVAL hwnd AS DWORD, BYVAL clr AS LONG, OPTIONAL BYVAL fRedraw AS LONG) AS LONG

   LOCAL pData AS GDIP_IMAGECTXDATA PTR    ' // Pointer to the control data

   ' // Checks the validity of the parameter
   IF hwnd = %NULL THEN EXIT FUNCTION
   ' // Gets a Pointer to the control data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION
   ' // Returns the old setting
   FUNCTION = @pData.m_BkColor
   ' // Stores the new color
   @pData.m_BkColor = clr
   ' // Redraws the control
   IF fRedraw THEN
      InvalidateRect hwnd, BYVAL %NULL, 0
      UpdateWindow hwnd
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the background color of the control's window.
' Parameter:
' * hwnd = Control's window handle
' Return value:
' * The current background color.
' ========================================================================================
FUNCTION GdipImageCtx_GetBkColor (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pData AS GDIP_IMAGECTXDATA PTR    ' // Pointer to the control data

   ' // Checks the validity of the parameter
   IF hwnd = %NULL THEN EXIT FUNCTION
   ' // Gets a Pointer to the control data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION
   ' // Returns the current background color
   FUNCTION = @pData.m_BkColor

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the Image object pointer.
' Parameter:
' * hwnd = Control's window handle
' Return value:
' * The Image object pointer.
' NOTE: Don't dispose the returned pointer. The control keeps a copy of it and calls
' GdipDisposeImage when it is destroyed.
' ========================================================================================
FUNCTION GdipImageCtx_GetImagePtr (BYVAL hwnd AS DWORD) AS DWORD

   LOCAL pData AS GDIP_IMAGECTXDATA PTR    ' // Pointer to the control data

   ' // Checks the validity of the parameter
   IF hwnd = %NULL THEN EXIT FUNCTION
   ' // Gets a Pointer to the control data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION
   ' // Returns the Graphics object pointer
   FUNCTION = @pData.m_pImage

END FUNCTION
' ========================================================================================

' ========================================================================================
' Clears the contents of the control
' Parameters:
' * hwnd = Control's window handle
' Return value:
' * If the function succeeds, the return value is TRUE.
'   If the function fails, the return value is FALSE.
' ========================================================================================
FUNCTION GdipImageCtx_Clear (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pdata AS GDIP_IMAGECTXDATA PTR    ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF ISFALSE hwnd THEN EXIT FUNCTION
   ' // Gets a Pointer to the control data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN EXIT FUNCTION

   ' // Dispose a the Image object, if any
   IF @pData.m_pImage THEN
      GdipDisposeImage(@pData.m_pImage)
      @pData.m_pImage = 0
   END IF

   ' // Erase the contents of the window
   LOCAL hBgBrush AS DWORD
   LOCAL rcFill AS RECT
   LOCAL hDc AS DWORD
   hBgBrush = CreateSolidBrush(@pdata.m_BkColor)
   GetClientRect hwnd, rcFill
   hDc = GetDc(hwnd)
   FillRect hDc, rcFill, hBgBrush
   ReleaseDC hwnd, hDc
   DeleteObject hBgBrush

   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================
