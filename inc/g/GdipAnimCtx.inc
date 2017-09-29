' ########################################################################################
' Microsoft Windows
' File: GdipAnimCtx.inc
' Contents: Renders animated GFIs using GDI+
' Based on code posted by Patrice Terrier in the PowerBASIC Forums.
' Copyright (c) 2011 José Roca. All Rights Reserved.
' Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%GDIPANIMCTX_INC = 1

#INCLUDE ONCE "GDIPLUS.INC"         ' // GDI Plus headers

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
'    IF wParam = %IDC_GDIPANIM THEN
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
' GDIPANIMCTXDATA structure
' ========================================================================================
TYPE GDIPANIMCTXDATA
   m_hMemBmp         AS DWORD   ' // Memory bitmap handle
   m_xMemBmp         AS LONG    ' // x-coord of memory bitmap
   m_yMemBmp         AS LONG    ' // y-coord of memory bitmap
   m_FrameCount      AS LONG    ' // Frame count
   m_ImageWidth      AS DWORD   ' // Width of the image
   m_ImageHeight     AS DWORD   ' // Height of the image
   m_QualityMode     AS LONG    ' // Quality mode
   m_BkColor         AS DWORD   ' // Background color
   m_token           AS DWORD   ' // Token returned by GdiplusStartup
   m_nFrameCount     AS LONG    ' // Number of frames
   m_nFrameAnimation AS LONG    ' // Frame animation
END TYPE
' ========================================================================================

' ========================================================================================
' GDIPANIMCTXDATAEX structure
' ========================================================================================
TYPE GDIPANIMCTXDATAEX
   QualityMode   AS LONG    ' // Quality mode
   BackColor     AS DWORD   ' // Background color
END TYPE
' ========================================================================================

' ========================================================================================
' Registers the window class
' ========================================================================================
FUNCTION InitGdipAnimCtx () AS WORD

   LOCAL  wcex AS WNDCLASSEX               ' // WNDCLASSEX structure
   STATIC wAtom AS WORD                    ' // Atom

   ' // Already initialized
   IF wAtom <> 0 THEN
      FUNCTION = wAtom
      EXIT FUNCTION
   END IF

#IF %DEF(%UNICODE)
   LOCAL szClassName AS WSTRINGZ * 256    ' // Class name
#ELSE
   LOCAL szClassName AS ASCIIZ * 256      ' // Class name
#ENDIF

   szClassName        = "GDIPANIMCTX"
   wcex.cbSize        = SIZEOF(wcex)
   wcex.style         = %CS_HREDRAW OR %CS_VREDRAW   ' OR %CS_GLOBALCLASS
   wcex.lpfnWndProc   = CODEPTR(GdipAnimCtxProc)
   wcex.cbClsExtra    = 0
   wcex.cbWndExtra    = 4 ' For pointer to GDIPANIMCTXDATA structure
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
' Control callback procedure
' ========================================================================================
FUNCTION GdipAnimCtxProc (BYVAL hwnd AS DWORD, BYVAL wMsg AS DWORD, _
                          BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL i                  AS LONG                    ' // Loop counter
   LOCAL hStatus            AS LONG                    ' // Result code
   LOCAL pData              AS GDIPANIMCTXDATA PTR     ' // Pointer to the control data
   LOCAL pDataEx            AS GDIPANIMCTXDATAEX PTR   ' // Extra data
   LOCAL pCreateStruct      AS CREATESTRUCT PTR        ' // Initialization parameters
   LOCAL wszFileName        AS WSTRINGZ * %MAX_PATH    ' // File name
   LOCAL ps                 AS PAINTSTRUCT             ' // PAINTSTRUCT structure
   LOCAL rc                 AS RECT                    ' // Client area of the control
   LOCAL hDc                AS DWORD                   ' // Device context handle
   LOCAL hOldDc             AS DWORD                   ' // Old device context handle
   LOCAL hBrush             AS DWORD                   ' // Handle of the brush
   LOCAL hMemDc             AS DWORD                   ' // Handle of the memory compatible device context
   LOCAL hMemBmp            AS DWORD                   ' // Handle of the memory compatible bitmap
   LOCAL hBmpOld            AS DWORD                   ' // Handle of the old selected bitmap
   LOCAL nXOriginDest       AS LONG                    ' // x-coord of destination upper-left corner
   LOCAL nYOriginDest       AS LONG                    ' // y-coord of destination upper-left corner
   LOCAL nWidthDest         AS LONG                    ' // width of destination rectangle
   LOCAL nHeightDest        AS LONG                    ' // height of destination rectangle
   LOCAL hdcSrc             AS DWORD                   ' // handle to source DC
   LOCAL xLeft              AS LONG                    ' // Left side
   LOCAL yTop               AS LONG                    ' // Top side
   LOCAL xRight             AS LONG                    ' // Right side
   LOCAL yBottom            AS LONG                    ' // Bottom side
   LOCAL StartupInput       AS GdiplusStartupInput     ' // GdiplusStartupInput structure
   LOCAL phdr               AS NMHDR                   ' // NMHDR structure

   ' // Gets a pointer to button data
   IF ISTRUE hwnd AND wMsg <> %WM_CREATE THEN pdata = GetWindowLong(hwnd, 0)

   SELECT CASE wMsg

      CASE %WM_CREATE
         ' // Allocates memory for the control's data
'         pdata = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@pdata))
         pdata = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(GDIPANIMCTXDATA))
         IF pdata THEN
            ' // Stores the pointer in the cbWndExtra member of the window class
            SetWindowLong hwnd, 0, pdata
            ' // Initialize GDI+
            StartupInput.GdiplusVersion = 1
            hStatus = GdiplusStartup(@pData.m_token, StartupInput, BYVAL %NULL)
            IF hStatus <> %StatusOk OR @pData.m_token = 0 THEN
               FUNCTION = -1   ' // Abort the action
               EXIT FUNCTION
            END IF
            ' // Pointer to the initialization parameters structure
            pCreateStruct = lParam
            ' // Pointer to the extra data
            pDataEx = @pCreateStruct.lpCreateParams
            IF pDataEx THEN
               @pData.m_QualityMode = @pDataEx.QualityMode
               @pData.m_BkColor = @pDataEx.BackColor
            END IF
            ' // Gets the filename from the caption
            wszFileName = @pCreateStruct.@lpszName
            IF LEN(wszFilename) <> 0 AND UCASE$(RIGHT$(wszFileName, 4)) = ".GIF" THEN
               GdipAnimCtx_LoadImageFromFile(hwnd, wszFileName)
            END IF
            EXIT FUNCTION
         ELSE
            ' // Aborts the action
            FUNCTION = -1
            EXIT FUNCTION
         END IF

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

      CASE %WM_NCHITTEST
         ' // Forwards the message to the parent window
         FUNCTION = SendMessage(GetParent(hwnd), %WM_NCHITTEST, wParam, lParam)
         EXIT FUNCTION

      CASE %WM_TIMER
         @pData.m_nFrameCount = @pData.m_nFrameCount + 1
         IF @pData.m_nFrameCount > @pData.m_nFrameAnimation THEN @pData.m_nFrameCount = 1
         GetClientRect hwnd, rc
         xLeft = rc.nRight - rc.nLeft
         yTop = rc.nBottom - rc.nTop
         xRight = (xLeft - @pData.m_xMemBmp) \ 2
         yBottom = (yTop - @pData.m_yMemBmp) \ 2
         SetRect rc, xRight, yBottom, xRight + @pData.m_xMemBmp, yBottom + @pData.m_yMemBmp
         InvalidateRect hwnd, rc, %FALSE
         EXIT FUNCTION

      CASE %WM_ERASEBKGND
         ' // Don't erase the background to avoid flicker
         FUNCTION = 1
         EXIT FUNCTION

      CASE %WM_PAINT, %WM_PRINTCLIENT
         ' // Prepares the window for painting
         IF wMsg = %WM_PAINT THEN
            hDc = BeginPaint(hwnd, ps)
         ELSE
            hDc = wParam
         END IF
         ' // Retrieves the coordinates of the window's client area
         GetClientRect hwnd, rc
         xLeft = rc.nRight - rc.nLeft
         yTop = rc.nBottom - rc.nTop
         ' // Creates an off-screen bitmap to avoid flicker
         hMemDc = CreateCompatibleDC(hdc)
         hMemBmp = CreateCompatibleBitmap(hdc, xLeft, yTop)
         hBmpOld = SelectObject(hMemDc, hMemBmp)
         ' // Draw the background
         hBrush = CreateSolidBrush(@pData.m_BkColor)
         hOldDc = SelectObject(hMemDc, hBrush)
         FillRect hMemDc, rc, hBrush
         DeleteObject hBrush
         IF hOldDc THEN  SelectObject hMemDc, hOldDc
         ' // Draw the transparent animated bitmap
         nXOriginDest = (xLeft - @pData.m_xMemBmp) \ 2
         nYOriginDest = (yTop - @pData.m_yMemBmp) \ 2
         nWidthDest = @pData.m_xMemBmp * @pData.m_nFrameCount - @pData.m_xMemBmp
         nHeightDest = @pData.m_yMemBmp
         hdcSrc = CreateCompatibleDC(hDc)
         SelectObject hdcSrc, @pData.m_hMemBmp
         TransparentBlt hMemDc, nXOriginDest, nYOriginDest, @pData.m_xMemBmp, @pData.m_yMemBmp, _
            hdcSrc, nWidthDest, 0, @pData.m_xMemBmp, @pData.m_yMemBmp, GetPixel(hdcSrc, 0, 0)
         DeleteDC hdcSrc
         ' // Draw final result to the target window
         BitBlt hDc, rc.nLeft, rc.nTop, xLeft, yTop, hMemDc, 0, 0, %SRCCOPY
         ' // Free resources
         SelectObject hMemDc, hBmpOld
         DeleteObject hMemBmp
         DeleteDC hMemDc
         ' // Ends the painting of the window
         IF wMsg = %WM_PAINT THEN
            EndPaint hwnd, ps
         END IF
         EXIT FUNCTION

      CASE %WM_ENABLE
         ' // Redraws the control
         InvalidateRect hwnd, BYVAL %NULL, 0
         UpdateWindow hwnd
         EXIT FUNCTION

      CASE %WM_DESTROY
         ' // Kills the timer
         KillTimer hwnd, 1
         ' // Shutdown GDI+
         IF @pData.m_token THEN GdiplusShutdown @pData.m_token
         ' // Destroys the bitmap
         IF @pdata.m_hMemBmp THEN DeleteObject @pdata.m_hMemBmp
         ' // Deallocates the memory used for the button data
         HeapFree(GetProcessHeap(), 0, BYVAL pdata)
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
' Gets the width of the image.
' Parameter:
' * hwnd = Control's window handle
' Return value:
' * The width of the image.
' ========================================================================================
FUNCTION GdipAnimCtx_GetImageWidth (BYVAL hwnd AS DWORD) AS LONG

   LOCAL hStatus AS LONG                   ' // Result code
   LOCAL ImageWidth AS LONG                ' // Image with
   LOCAL pData AS GDIPANIMCTXDATA PTR      ' // Pointer to the control data

   ' // Checks the validity of the parameter
   IF hwnd = %NULL THEN EXIT FUNCTION
   ' // Gets a Pointer to the control data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION
   FUNCTION = @pData.m_ImageWidth

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the height of the image.
' Parameter:
' * hwnd = Control's window handle
' Return value:
' * The height of the image.
' ========================================================================================
FUNCTION GdipAnimCtx_GetImageHeight (BYVAL hwnd AS DWORD) AS LONG

   LOCAL hStatus AS LONG                   ' // Result code
   LOCAL ImageHeight AS LONG               ' // Image with
   LOCAL pData AS GDIPANIMCTXDATA PTR      ' // Pointer to the control data

   ' // Checks the validity of the parameter
   IF hwnd = %NULL THEN EXIT FUNCTION
   ' // Gets a Pointer to the control data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION
   FUNCTION = @pData.m_ImageHeight

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
FUNCTION GdipAnimCtx_SetBkColor (BYVAL hwnd AS DWORD, BYVAL clr AS LONG, OPTIONAL BYVAL fRedraw AS LONG) AS LONG

   LOCAL pData AS GDIPANIMCTXDATA PTR      ' // Pointer to the control data

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
FUNCTION GdipAnimCtx_GetBkColor (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pData AS GDIPANIMCTXDATA PTR      ' // Pointer to the control data

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
' Sets the quality mode.
' Parameters:
' * hwnd = Control's window handle.
' * QualityMode = Quality mode.
' * fRedraw = [optional] TRUE or FALSE (redraws the control to reflect the changes)
' Return value:
' * Returns the previous quality mode.
' ========================================================================================
FUNCTION GdipAnimCtx_SetQualityMode (BYVAL hwnd AS DWORD, BYVAL QualityMode AS LONG, OPTIONAL BYVAL fRedraw AS LONG) AS LONG

   LOCAL pData AS GDIPANIMCTXDATA PTR      ' // Pointer to the control data

   ' // Checks the validity of the parameter
   IF hwnd = %NULL THEN EXIT FUNCTION
   ' // Gets a Pointer to the control data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION
   ' // Returns the old setting
   FUNCTION = @pData.m_QualityMode
   ' // Stores the new color
   @pData.m_QualityMode = QualityMode
   ' // Redraws the control
   IF fRedraw THEN
      InvalidateRect hwnd, BYVAL %NULL, 0
      UpdateWindow hwnd
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the quality mode.
' Parameter:
' * hwnd = Control's window handle
' Return value:
' * The current quality mode.
' ========================================================================================
FUNCTION GdipAnimCtx_GetQualityMode (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pData AS GDIPANIMCTXDATA PTR      ' // Pointer to the control data

   ' // Checks the validity of the parameter
   IF hwnd = %NULL THEN EXIT FUNCTION
   ' // Gets a Pointer to the control data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION
   ' // Returns the current quality mode
   FUNCTION = @pData.m_QualityMode

END FUNCTION
' ========================================================================================

' ========================================================================================
' Helper function for GdipAnimCtx_LoadImageFromFile and GdipAnimCtx_LoadImageFromResource.
' ========================================================================================
FUNCTION GdipAnimCtx_DrawImage (BYVAL hwnd AS DWORD, BYVAL hImage AS DWORD) AS LONG

   LOCAL i         AS LONG                  ' // Loop counter
   LOCAL hr        AS LONG                  ' // Result code
   LOCAL pData     AS GDIPANIMCTXDATA PTR   ' // Pointer to the control data
   LOCAL hDc       AS DWORD                 ' // Device context handle
   LOCAL hOldDc    AS DWORD                 ' // Old device context handle
   LOCAL hMemDc    AS DWORD                 ' // Handle of the memory compatible device context
   LOCAL xWidth    AS LONG                  ' // Width of the memory bitmap
   LOCAL xStep     AS LONG                  ' // Step
   LOCAL hBrush    AS DWORD                 ' // Handle of the brush
   LOCAL rc        AS RECT                  ' // Client area of the control
   LOCAL bufSize   AS DWORD                 ' // Size in bytes of the property item
   LOCAL hGraphics AS DWORD                 ' // Handle of the GDI+ graphics object
   LOCAL uElapse   AS DWORD                 ' // Time-out in milliseconds

   IF hwnd = 0 OR hImage = 0 THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION

   ' // Gets a Pointer to the control data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION
   ' // Gets the width and height
   hr = GdipGetImageWidth(hImage, @pData.m_ImageWidth)
   hr = GdipGetImageHeight(hImage, @pData.m_ImageHeight)
   ' // Gets the frame count
   hr = GdipImageGetFrameCount(hImage, $FrameDimensionTime, @pData.m_FrameCount)
   ' // Creates an information context for the specified device
   hDc = CreateIC("DISPLAY", BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
   ' // Creates a compatible device context
   hMemDc = CreateCompatibleDC(hDc)
   ' // Calculates the dimensions of the memory bitmap
   xWidth = MAX&(@pData.m_ImageWidth, @pData.m_ImageHeight)
   @pData.m_xMemBmp = xWidth * @pData.m_FrameCount
   @pData.m_yMemBmp = xWidth
   ' // Creates a compatible bitmap and selects it
   @pData.m_hMemBmp = CreateCompatibleBitmap(hDc, @pData.m_xMemBmp, @pData.m_yMemBmp)
   SelectObject hMemDc, @pData.m_hMemBmp
   ' // Clears it using a fucsia brush
   hBrush = CreateSolidBrush(&HFF00FF)
   hOldDc = SelectObject(hMemDc, hBrush)
   SetRect rc, 0, 0, @pData.m_xMemBmp, @pData.m_yMemBmp
   FillRect hMemDc, rc, hBrush
   DeleteObject hBrush
   IF hOldDc THEN  SelectObject hMemDc, hOldDc
   ' // Draws all the frames being used
   hr = GdipGetPropertyItemSize(hImage, %PropertyTagFrameDelay, bufSize)
   IF hr = %S_OK THEN
      FOR i = 0 TO @pData.m_FrameCount - 1
         GdipImageSelectActiveFrame(hImage, $FrameDimensionTime, i)
         hr = GdipCreateFromHDC(hMemDc, hGraphics)
         IF hr = %S_OK AND hGraphics <> %NULL THEN
            GdipSetInterpolationMode hGraphics, @pData.m_QualityMode
            GdipDrawImageRectI hGraphics, hImage, xStep + (xWidth - @pData.m_ImageWidth) \ 2, _
               (xWidth  - @pData.m_ImageHeight) \ 2, @pData.m_ImageWidth, @pData.m_ImageHeight
         END IF
         IF hGraphics THEN
            GdipDeleteGraphics hGraphics
            hGraphics = %NULL
         END IF
         xStep = xStep + xWidth
      NEXT
   END IF
   ' // Deletes the memory bitmap and his memory device context
   DeleteDC hMemDc
   DeleteDC hDc
   ' // Kills the timer if it already exists
   KillTimer hwnd, 1
   ' // Sets the timer
   @pData.m_nFrameAnimation = @pData.m_xMemBmp \ @pData.m_yMemBmp
   @pData.m_xMemBmp = @pData.m_yMemBmp
   uElapse = 60
   SELECT CASE @pData.m_nFrameAnimation
      CASE < 4 : uElapse = 300
      CASE < 8 : uElapse = 200
      CASE < 12 : uElapse = 150
   END SELECT
   SetTimer hwnd, 1, uElapse, %NULL
   EXIT FUNCTION

END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads an image from file using GDI+
' Parameters:
' * hwnd = Control's window handle
' * wszFileName = Fully qualified path and filename of the image file to load.
' Return value:
' * %StatusOk or an error code.
' ========================================================================================
FUNCTION GdipAnimCtx_LoadImageFromFile (BYVAL hwnd AS DWORD, BYREF wszFileName AS WSTRINGZ) AS LONG

   LOCAL hr     AS LONG                  ' // Result code
   LOCAL hImage AS DWORD                 ' // Handle of the GIF image
   LOCAL pData  AS GDIPANIMCTXDATA PTR   ' // Pointer to the control data

   IF hwnd = 0 THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION
   IF LEN(wszFilename) = 0 OR UCASE$(RIGHT$(wszFileName, 4)) <> ".GIF" THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION

   ' // Gets a Pointer to the control data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION
   ' // Loads the image
   hr = GdipLoadImageFromFile(wszFileName, hImage)
   IF hr <> %S_OK THEN FUNCTION = hr : EXIT FUNCTION
   ' // Draws the image
   hr = GdipAnimCtx_DrawImage(hwnd, hImage)
   ' // Disposes the image
   GdipDisposeImage(hImage)
   FUNCTION = hr

END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads an image from a resource file using GDI+
' Parameters:
' * hwnd = Control's window handle
' * hInstance = Instance handle
' * wszResourceName = Name of the resource.
' Return value:
' * %StatusOk or an error code.
' ========================================================================================
FUNCTION GdipAnimCtx_LoadImageFromResource (BYVAL hwnd AS DWORD, BYVAL hInstance AS DWORD, BYREF wszResourceName AS WSTRINGZ) AS LONG

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
   LOCAL pData AS GDIPANIMCTXDATA PTR      ' // Pointer to the control data
   LOCAL hImage AS DWORD                   ' // Image handle

   ' // Checks the validity of the parameters
   IF hwnd = %NULL THEN FUNCTION = %E_POINTER : EXIT FUNCTION
   IF LEN(wszResourceName) = 0 THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION

   ' // Gets a Pointer to the control data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN FUNCTION = %E_POINTER : EXIT FUNCTION

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
            hStatus = GdipCreateBitmapFromStream(pImageStream, hImage)
            IF hStatus = %StatusOk THEN
               ' // Draws the image
               hStatus = GdipAnimCtx_DrawImage(hwnd, hImage)
               ' // Disposes the image
               GdipDisposeImage(hImage)
            END IF
            pImageStream = NOTHING
         END IF
         ' // Unlock the memory
         GlobalUnlock pGlobalBuffer
      END IF
      ' // Free the memory
      GlobalFree hGlobal
   END IF

   FUNCTION = hStatus

END FUNCTION
' ========================================================================================
