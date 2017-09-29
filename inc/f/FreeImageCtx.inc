' ########################################################################################
' Microsoft Windows
' File: FreeImageCtx.inc
' Contents: An image control based on FreeImage.
' Copyright (c) 2011 José Roca. All Rights Reserved.
' Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%FREEIMAGECTX_INC = 1

#INCLUDE ONCE "FreeImage.inc"

%FREEIMAGECTX_AUTOSIZE    = 0   ' // Autoadjusts the image to the width or height of the control
%FREEIMAGECTX_ACTUALSIZE  = 1   ' // Shows the image with its actual size
%FREEIMAGECTX_FITTOWIDTH  = 2   ' // Adjusts the image to the width of the control
%FREEIMAGECTX_FITTOHEIGHT = 3   ' // Adjusts the image to the height of the control
%FREEIMAGECTX_STRETCH     = 4   ' // Adjusts the image to the height and width of the control

' ========================================================================================
' FREEIMAGECTXDATA structure
' ========================================================================================
TYPE FREEIMAGECTXDATA
   m_pDib        AS DWORD   ' // Device independent bitmap pointer
   m_BkColor     AS LONG    ' // RGB background color
   m_StretchMode AS LONG    ' // Stretching mode
   m_Fit         AS LONG    ' // Fit to width/height
END TYPE
' ========================================================================================

' ========================================================================================
' Registers the window class
' ========================================================================================
FUNCTION InitFreeImageCtx () AS WORD

   LOCAL  wcex AS WNDCLASSEX               ' // WNDCLASSEX structure
   STATIC wAtom AS WORD                    ' // Atom

   ' // Already initialized
   IF wAtom <> 0 THEN
      FUNCTION = wAtom
      EXIT FUNCTION
   END IF

#IF %DEF(%UNICODE)
   LOCAL szClassName AS WSTRINGZ * 256
#ELSE
   LOCAL szClassName AS ASCIIZ * 256
#ENDIF

   szClassName        = "FREEIMAGECTX"
   wcex.cbSize        = SIZEOF(wcex)
   wcex.style         = %CS_HREDRAW OR %CS_VREDRAW   ' OR %CS_GLOBALCLASS
   wcex.lpfnWndProc   = CODEPTR(FreeImageCtxProc)
   wcex.cbClsExtra    = 0
   wcex.cbWndExtra    = 4 ' For pointer to FREEIMAGECTXDATA structure
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
FUNCTION FreeImageCtx_DrawImage (BYVAL hwnd AS DWORD, BYVAL hDc AS DWORD) AS LONG

   LOCAL hStatus AS LONG                   ' // Result code
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
   LOCAL pData AS FREEIMAGECTXDATA PTR     ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF hwnd = %NULL THEN EXIT FUNCTION
   ' // Gets a pointer to the control's data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION

   ' // Check parameters validity
   IF hWnd = %NULL OR hDc = %NULL OR @pData.m_pDib = %NULL THEN
      FUNCTION = %E_POINTER
      EXIT FUNCTION
   END IF

   ' // Retrieves the coordinates of the window's client area
   GetClientRect hwnd, rc

   ' // Retrieves the width and height of the image
   ImageWidth = FreeImage_GetWidth(@pData.m_pDib)
   ImageHeight = FreeImage_GetHeight(@pData.m_pDib)

   ' // Sets teh stretching mode
   SetStretchBltMode(hDC, @pData.m_StretchMode)

   ' // Draws the image
   nFit = @pData.m_Fit
   IF nFit = %FREEIMAGECTX_AUTOSIZE THEN
      IF ImageWidth / (rc.nRight - rc.nLeft) > ImageHeight / (rc.nBottom - rc.nTop) THEN
         nFit = %FREEIMAGECTX_FITTOWIDTH
      ELSE
         nFit = %FREEIMAGECTX_FITTOHEIGHT
      END IF
   END IF
   IF nFit = %FREEIMAGECTX_ACTUALSIZE THEN
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
      ' // Draws the image
      StretchDibits(hDC, cx, cy, ImageWidth, ImageHeight, _
         0, 0, ImageWidth, ImageHeight, _
         BYVAL FreeImage_GetBits(@pData.m_pDib), _
         BYVAL FreeImage_GetInfo(@pData.m_pDib), _
         %DIB_RGB_COLORS, %SRCCOPY)
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
   ELSEIF nFit = %FREEIMAGECTX_STRETCH THEN
     ' Stretch or shrunk to fill the controls client area
      w = rc.nRight - rc.nLeft
      h = rc.nBottom - rc.nTop
      StretchDibits(hDC, 0, 0, w, h, _
         0, 0, ImageWidth, ImageHeight, _
         BYVAL FreeImage_GetBits(@pData.m_pDib), _
         BYVAL FreeImage_GetInfo(@pData.m_pDib), _
         %DIB_RGB_COLORS, %SRCCOPY)
   ELSEIF nFit = %FREEIMAGECTX_FITTOWIDTH THEN
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
      StretchDibits(hDC, 0, cy, w, h, _
         0, 0, ImageWidth, ImageHeight, _
         BYVAL FreeImage_GetBits(@pData.m_pDib), _
         BYVAL FreeImage_GetInfo(@pData.m_pDib), _
         %DIB_RGB_COLORS, %SRCCOPY)
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
      StretchDibits(hDC, cx, 0, w, h, _
         0, 0, ImageWidth, ImageHeight, _
         BYVAL FreeImage_GetBits(@pData.m_pDib), _
         BYVAL FreeImage_GetInfo(@pData.m_pDib), _
         %DIB_RGB_COLORS, %SRCCOPY)
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

END FUNCTION
' ========================================================================================

' ========================================================================================
' Control callback procedure
' ========================================================================================
FUNCTION FreeImageCtxProc (BYVAL hwnd AS DWORD, BYVAL wMsg AS DWORD, _
                           BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL hStatus AS LONG                       ' // Result code
   LOCAL hDc AS DWORD                          ' // Device context handle
   LOCAL phdr AS NMHDR                         ' // NMHDR structure
   LOCAL pData AS FREEIMAGECTXDATA PTR        ' // Pointer to the control's data
   LOCAL ps AS PAINTSTRUCT                     ' // PAINTSTRUCT structure

   ' // Gets a pointer to button data
   IF hwnd <> %NULL AND wMsg <> %WM_CREATE THEN pData = GetWindowLong(hwnd, 0)

   SELECT CASE wMsg

      CASE %WM_CREATE
         ' // Allocates memory for the control's data
'         pData = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@pData))
         pData = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(FREEIMAGECTXDATA))
         IF pData THEN
            ' // Stores the pointer in the cbWndExtra member of the window class
            SetWindowLong hwnd, 0, pData
            ' // Default stretching mode
            @pData.m_StretchMode = %HALFTONE
         ELSE
            FUNCTION = -1   ' // Abort the action
         END IF
         EXIT FUNCTION

      CASE %WM_DESTROY
         ' // Unload the image
         IF @pData.m_pDib THEN FreeImage_Unload(@pData.m_pDib)
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
         FreeImageCtx_DrawImage(hwnd, hdc)
         EXIT FUNCTION

      CASE %WM_PAINT
         ' // Prepares the window for painting
         hDc = BeginPaint(hwnd, ps)
         ' // Draws the image
         FreeImageCtx_DrawImage(hwnd, hdc)
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
' Loads an image from file.
' Parameters:
' * hwnd = Control's window handle
' * strFileName = Fully qualified path and filename of the image file to load.
' Return value:
' * TRUE or FALSE.
' ========================================================================================
FUNCTION FreeImageCtx_LoadImageFromFile (BYVAL hwnd AS DWORD, BYVAL strFileName AS STRING) AS LONG

   LOCAL hDc AS DWORD                      ' // Device context handle
   LOCAL hBgBrush AS DWORD                 ' // Background brush
   LOCAL rc AS RECT                        ' // Image bounds
   LOCAL rcFill AS RECT                    ' // Fill area
   LOCAL pData AS FREEIMAGECTXDATA PTR     ' // Pointer to the control's data
   LOCAL nType AS LONG                     ' // File format

   ' // Checks the validity of the parameters
   IF hwnd = %NULL THEN EXIT FUNCTION
   IF LEN(strFileName) = 0 THEN EXIT FUNCTION

   ' // Gets a Pointer to the control's data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION

   ' // Unload the previous image, if any
   IF @pData.m_pDib THEN
      FreeImage_Unload(@pData.m_pDib)
      @pData.m_pDib = 0
   END IF

   ' // Loads the image
   nType = FreeImage_GetFileType(BYCOPY strFileName, 0)
   IF nType = %FIF_UNKNOWN THEN nType = FreeImage_GetFIFFromFilename(BYCOPY strFileName)
   IF nType = %FIF_UNKNOWN THEN EXIT FUNCTION
   IF FreeImage_FIFSupportsReading(nType) THEN
      @pData.m_pDib = FreeImage_Load(nType, BYCOPY strFileName, 0)
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

   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads an image from a resource file.
' Parameters:
' * hwnd = Control's window handle
' * hInstance = Instance handle
' * strResourceName = Name of the resource.
' Return value:
' * TRUE or FALSE
' ========================================================================================
FUNCTION FreeImageCtx_LoadImageFromResource (BYVAL hwnd AS DWORD, BYVAL hInstance AS DWORD, BYVAL strResourceName AS STRING) AS LONG

   LOCAL hDc AS DWORD                      ' // Device context handle
   LOCAL hStream AS DWORD                  ' // Handle to a memory stream
   LOCAL hResource AS DWORD                ' // Resource handle
   LOCAL pResourceData AS DWORD            ' // Pointer to the resoruce data
   LOCAL hBgBrush AS DWORD                 ' // Background brush
   LOCAL imageSize AS DWORD                ' // Image size
   LOCAL nType AS LONG                     ' // File format
   LOCAL rc AS RECT                        ' // Image bounds
   LOCAL rcFill AS RECT                    ' // Fill area
   LOCAL pData AS FREEIMAGECTXDATA PTR     ' // Pointer to the control's data

   ' // Checks the validity of the parameters
   IF hwnd = %NULL THEN EXIT FUNCTION
   IF LEN(strResourceName) = 0 THEN EXIT FUNCTION

   ' // Gets a Pointer to the control's data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION

   ' // Unload the previous image, if any
   IF @pData.m_pDib THEN
      FreeImage_Unload(@pData.m_pDib)
      @pData.m_pDib = 0
   END IF

   ' // Finds the resource and locks it
   hResource = FindResource(hInstance, BYCOPY strResourceName, BYVAL %RT_RCDATA)
   IF hResource = %NULL THEN EXIT FUNCTION
   imageSize = SizeofResource(hInstance, hResource)
   IF imageSize = 0 THEN EXIT FUNCTION
   pResourceData = LockResource(LoadResource(hInstance, hResource))
   IF pResourceData = %NULL THEN EXIT FUNCTION
   ' // Opens the memory stream
   hStream = FreeImage_OpenMemory(BYVAL pResourceData, imageSize)
   IF hStream = %NULL THEN EXIT FUNCTION
   ' // Loads the image
   nType = FreeImage_GetFileTypeFromMemory(hStream, 0)
   IF nType <> %FIF_UNKNOWN THEN
      @pData.m_pDib = FreeImage_LoadFromMemory(nType, hStream, 0)
   END IF
   ' // Closes the memory stream
   FreeImage_CloseMemory hStream

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

   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Redraws the control.
' Parameters:
' * hwnd = Control's window handle
' Return value:
' * No return value.
' ========================================================================================
SUB FreeImageCtx_Redraw (BYVAL hwnd AS DWORD)
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
'     %FREEIMAGECTX_AUTOSIZE = 0
'        Autoadjusts the image to the width or height of the control
'     %FREEIMAGECTX_ACTUALSIZE = 1
'        Shows the image with its actual size
'     %FREEIMAGECTX_FITTOWIDTH = 2
'        Adjusts the image to the width of the control
'     %FREEIMAGECTX_FITTOHEIGHT = 3
'        Adjusts the image to the height of the control
' * fRedraw = [optional] TRUE or FALSE (redraws the control to reflect the changes)
' Return value:
' * Returns the previous setting.
' ========================================================================================
FUNCTION FreeImageCtx_SetImageAdjustment (BYVAL hwnd AS DWORD, BYVAL ImageAdjustment AS LONG, OPTIONAL BYVAL fRedraw AS LONG) AS LONG

   LOCAL pData AS FREEIMAGECTXDATA PTR    ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF hwnd = %NULL THEN EXIT FUNCTION
   ' // Gets a pointer to the control's data
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
FUNCTION FreeImageCtx_GetImageAdjustment (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pData AS FREEIMAGECTXDATA PTR    ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF hwnd = %NULL THEN EXIT FUNCTION
   ' // Gets a pointer to the control's data
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
FUNCTION FreeImageCtx_GetImageWidth (BYVAL hwnd AS DWORD) AS LONG

   LOCAL hStatus AS LONG                   ' // Result code
   LOCAL ImageWidth AS LONG                ' // Image with
   LOCAL pData AS FREEIMAGECTXDATA PTR     ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF hwnd = %NULL THEN EXIT FUNCTION
   ' // Gets a pointer to the control's data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION
   IF @pData.m_pDib THEN
      FUNCTION = FreeImage_GetWidth(@pData.m_pDib)
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
FUNCTION FreeImageCtx_GetImageHeight (BYVAL hwnd AS DWORD) AS LONG

   LOCAL hStatus AS LONG                   ' // Result code
   LOCAL ImageWidth AS LONG                ' // Image with
   LOCAL pData AS FREEIMAGECTXDATA PTR     ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF hwnd = %NULL THEN EXIT FUNCTION
   ' // Gets a pointer to the control's data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION
   IF @pData.m_pDib THEN
      FUNCTION = FreeImage_GetHeight(@pData.m_pDib)
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
FUNCTION FreeImageCtx_SetBkColor (BYVAL hwnd AS DWORD, BYVAL clr AS LONG, OPTIONAL BYVAL fRedraw AS LONG) AS LONG

   LOCAL pData AS FREEIMAGECTXDATA PTR    ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF hwnd = %NULL THEN EXIT FUNCTION
   ' // Gets a pointer to the control's data
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
FUNCTION FreeImageCtx_GetBkColor (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pData AS FREEIMAGECTXDATA PTR    ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF hwnd = %NULL THEN EXIT FUNCTION
   ' // Gets a pointer to the control's data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION
   ' // Returns the current background color
   FUNCTION = @pData.m_BkColor

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the stretching mode.
' Parameters:
' * hwnd = Control's window handle
' * newMode = The stretching mode
'     %BLACKONWHITE      = 1&
'     %WHITEONBLACK      = 2&
'     %COLORONCOLOR      = 3&
'     %HALFTONE          = 4&
'     %MAXSTRETCHBLTMODE = 4&
' * fRedraw = [optional] TRUE or FALSE (redraws the control to reflect the changes)
' Return value:
' * Returns the previous stretching mode.
' ========================================================================================
FUNCTION FreeImageCtx_SetStretchMode (BYVAL hwnd AS DWORD, BYVAL newMode AS LONG, OPTIONAL BYVAL fRedraw AS LONG) AS LONG

   LOCAL pData AS FREEIMAGECTXDATA PTR    ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF hwnd = %NULL THEN EXIT FUNCTION
   ' // Gets a pointer to the control's data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION
   ' // Returns the old setting
   FUNCTION = @pData.m_StretchMode
   ' // Stores the new color
   @pData.m_StretchMode = newMode
   ' // Redraws the control
   IF fRedraw THEN
      InvalidateRect hwnd, BYVAL %NULL, 0
      UpdateWindow hwnd
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the DIB handle.
' Parameter:
' * hwnd = Control's window handle
' Return value:
' * The DIB handle
' NOTE: Don't unload the image using the returned pointer. The control keeps a copy of it
' and calls FreeImage_Unload when it is destroyed.
' ========================================================================================
FUNCTION FreeImageCtx_GetDIB (BYVAL hwnd AS DWORD) AS DWORD

   LOCAL pData AS FREEIMAGECTXDATA PTR    ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF hwnd = %NULL THEN EXIT FUNCTION
   ' // Gets a pointer to the control's data
   pData = GetWindowLong(hwnd, 0)
   IF pData = %NULL THEN EXIT FUNCTION
   ' // Returns the Graphics object pointer
   FUNCTION = @pData.m_pDib

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
FUNCTION FreeImageCtx_Clear (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pdata AS FREEIMAGECTXDATA PTR    ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF ISFALSE hwnd THEN EXIT FUNCTION
   ' // Gets a Pointer to the control data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN EXIT FUNCTION

   ' // Unload the image, if any
   IF @pData.m_pDib THEN
      FreeImage_Unload(@pData.m_pDib)
      @pData.m_pDib = 0
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
