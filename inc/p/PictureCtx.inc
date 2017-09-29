' ########################################################################################
' Microsoft Windows
' File: PictureCtx.inc
' Contents: An image control based on the IPicture interface.
' Copyright (c) 2011 José Roca. All Rights Reserved.
' Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PICTURECTX_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "olectl.inc"
#INCLUDE ONCE "ole2utils.inc"

%PICTURECTX_AUTOSIZE    = 0   ' // Autoadjusts the image to the width or height of the control
%PICTURECTX_ACTUALSIZE  = 1   ' // Shows the image with its actual size
%PICTURECTX_FITTOWIDTH  = 2   ' // Adjusts the image to the width of the control
%PICTURECTX_FITTOHEIGHT = 3   ' // Adjusts the image to the height of the control
%PICTURECTX_STRETCH     = 4   ' // Adjusts the image to the height and width of the control

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
'    IF wParam = %IDC_PICCTX THEN
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
' PICTURECTXDATA structure
' ========================================================================================
TYPE PICTURECTXDATA
   m_pPicture AS DWORD   ' // IPicture interface pointer
   m_BkColor  AS LONG    ' // RGB background color
   m_Fit      AS LONG    ' // Fit to width/height
END TYPE
' ========================================================================================

' ========================================================================================
' Registers the window class
' ========================================================================================
FUNCTION InitPictureCtx () AS WORD

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

   szClassName        = "PICTURECTX"
   wcex.cbSize        = SIZEOF(wcex)
   wcex.style         = %CS_HREDRAW OR %CS_VREDRAW
   wcex.lpfnWndProc   = CODEPTR(PictureCtxProc)
   wcex.cbClsExtra    = 0
   wcex.cbWndExtra    = 4 ' For pointer to PICTURECTXDATA structure
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
FUNCTION PictureCtxProc (BYVAL hwnd AS DWORD, BYVAL wMsg AS DWORD, _
                         BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL phdr AS NMHDR                     ' // NMHDR structure
   LOCAL pdata AS PICTURECTXDATA PTR       ' // Pointer to the control data
   LOCAL hr AS LONG                        ' // Result code
   LOCAL hDc AS DWORD                      ' // Device context handle
   LOCAL ps AS PAINTSTRUCT                 ' // PAINTSTRUCT structure
   LOCAL rc AS RECT                        ' // client area
   LOCAL rcFill AS RECT                    ' // Fill area
   LOCAL hBgBrush AS DWORD                 ' // Background brush
   LOCAL p AS LONG                         ' // Percent
   LOCAL w AS LONG                         ' // Width
   LOCAL h AS LONG                         ' // Height
   LOCAL cx AS LONG                        ' // x-coordinate for center fill
   LOCAL cy AS LONG                        ' // y-coordinate for center fill
   LOCAL nFit AS LONG                      ' // Fit
   LOCAL pIPicture AS IPicture             ' // IPicture interface reference

   LOCAL hmWidth AS LONG
   LOCAL hmHeight AS LONG
   LOCAL nWidth AS LONG
   LOCAL nHeight AS LONG

   ' // Gets a pointer to button data
   IF ISTRUE hwnd AND wMsg <> %WM_CREATE THEN pdata = GetWindowLong(hwnd, 0)

   SELECT CASE wMsg

      CASE %WM_CREATE
         ' // Allocates memory for the control's data
'         pdata = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@pdata))
         pdata = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(PICTURECTXDATA))
         IF ISTRUE pdata THEN
            ' // Stores the pointer in the cbWndExtra member of the window class
            SetWindowLong hwnd, 0, pdata
            EXIT FUNCTION
         ELSE
            ' // Aborts the action
            FUNCTION = -1
            EXIT FUNCTION
         END IF

      CASE %WM_DESTROY
         ' // Release the IPicture object
         IF @pdata.m_pPicture THEN IUnknown_Release @pdata.m_pPicture
         ' // Deallocates the memory used for the button data
         IF pdata THEN CALL HeapFree(GetProcessHeap(), 0, BYVAL pdata)
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
         ' // Draws the picture
         IF @pdata.m_pPicture THEN
            pIPicture = Ptr2Obj(@pdata.m_pPicture)
               IF ISOBJECT(pIPicture) THEN
               hr = pIPicture.get_Width(hmWidth)
               hr = pIPicture.get_Height(hmHeight)
               nWidth  = MulDiv(hmWidth,  GetDeviceCaps (hDc, %LOGPIXELSX), 2540) ' 1 inch = 2.54 mm
               nHeight = MulDiv(hmHeight, GetDeviceCaps (hDc, %LOGPIXELSY), 2540)
               nFit = @pdata.m_Fit
               w = nWidth
               h = nHeight
               IF nFit = %PICTURECTX_AUTOSIZE THEN
                  IF w / (rc.nRight - rc.nLeft) > h / (rc.nBottom - rc.nTop) THEN
                     nFit = %PICTURECTX_FITTOWIDTH
                  ELSE
                     nFit = %PICTURECTX_FITTOHEIGHT
                  END IF
               END IF
               IF nFit = %PICTURECTX_ACTUALSIZE THEN
                  ' // If the width of the image is smaller than the width of the control
                  ' // calculate the position for a centered image
                  IF nWidth < (rc.nRight - rc.nLeft) THEN
                     cx = ((rc.nRight - rc.nLeft) - nWidth) / 2
                  END IF
                  IF nHeight < (rc.nBottom - rc.nTop) THEN
                     cy = ((rc.nBottom - rc.nTop) - nHeight) / 2
                  END IF
                  ' // Draws the picture
                  hr = pIPicture.Render(hDc, cx, cy, _
                       nWidth, nHeight, 0, hmHeight, hmWidth, -hmHeight, rc)
                  ' // Creates a brush and fills the client area of the window not covered by the image
                  hBgBrush = CreateSolidBrush(@pdata.m_BkColor)
                  GetClientRect hwnd, rcFill
                  rcFill.nLeft = 0
                  rcFill.nRight = cx
                  FillRect hDc, rcFill, hBgBrush
                  GetClientRect hwnd, rcFill
                  rcFill.nLeft = cx + nWidth
                  FillRect hDc, rcFill, hBgBrush
                  GetClientRect hwnd, rcFill
                  rcFill.nLeft = cx
                  rcFill.nRight = cx + nWidth
                  rcFill.nBottom = cy
                  FillRect hDc, rcFill, hBgBrush
                  GetClientRect hwnd, rcFill
                  rcFill.nLeft = cx
                  rcFill.nRight = cx + nWidth
                  rcFill.nTop = cy + nHeight
                  FillRect hDc, rcFill, hBgBrush
                  ' // Deletes the brush
                  DeleteObject hBgBrush
               ELSEIF nFit = %PICTURECTX_FITTOWIDTH THEN
                  ' // Calculate the percent of reduction or ampliation
                  ' // and adjust the image height
                  p = ((rc.nRight - rc.nLeft) * 100) / nWidth
                  w = rc.nRight - rc.nLeft
                  h = nHeight * p / 100
                  ' // If the height of the image is smaller than the height of the control
                  ' // calculate the position for a centered image
                  IF h < (rc.nBottom - rc.nTop) THEN
                     cx = ((rc.nBottom - rc.nTop) - h) / 2
                  END IF
                  ' // Draws the picture
                  hr = pIPicture.Render(hDc, 0, cx, w, h, _
                       0, hmHeight, hmWidth, -hmHeight, rc)
                  ' // Creates a brush and fills the client area of the window not covered by the image
                  hBgBrush = CreateSolidBrush(@pdata.m_BkColor)
                  GetClientRect hwnd, rcFill
                  rcFill.nBottom = cx
                  FillRect hDc, rcFill, hBgBrush
                  GetClientRect hwnd, rcFill
                  rcFill.nTop = cx + h
                  FillRect hDc, rcFill, hBgBrush
                  ' // Deletes the brush
                  DeleteObject hBgBrush
               ELSEIF nFit = %PICTURECTX_STRETCH THEN
                  ' Stretch or shrunk to fill the controls client area
                  w = rc.nRight - rc.nLeft
                  h = rc.nBottom - rc.nTop
                  ' // Draws the picture
                  hr = pIPicture.Render(hDc, 0, 0, w, h, _
                       0, hmHeight, hmWidth, -hmHeight, rc)
               ELSE
                  ' // Calculate the percent of reduction or ampliation
                  ' // and adjust the image width
                  IF nHeight <> rc.nBottom - rc.nTop THEN
                     p = ((rc.nBottom - rc.nTop) * 100) / nHeight
                     h = rc.nBottom - rc.nTop
                     w = nWidth * p / 100
                  ELSE
                     h = nHeight
                     w = nWidth
                  END IF
                  ' // If the width of the image is greater than the width of the control
                  ' // calculate the position for a centered image
                  IF w < (rc.nRight - rc.nLeft) THEN
                     cx = ((rc.nRight - rc.nLeft) - w) / 2
                  END IF
                  ' // Draws the image
                  hr = pIPicture.Render(hDc, cx, 0, _
                       w, h, 0, hmHeight, hmWidth, -hmHeight, rc)
                  ' // Creates a brush and fills the client area of the window not covered by the image
                  hBgBrush = CreateSolidBrush(@pdata.m_BkColor)
                  GetClientRect hwnd, rcFill
                  rcFill.nLeft = 0
                  rcFill.nRight = cx
                  FillRect hDc, rcFill, hBgBrush
                  GetClientRect hwnd, rcFill
                  rcFill.nLeft = cx + w
                  FillRect hDc, rcFill, hBgBrush
                  ' // Deletes the brush
                  DeleteObject hBgBrush
               END IF
            ELSE
               ' // Creates a brush and fills the client area of the window
               hBgBrush = CreateSolidBrush(@pdata.m_BkColor)
               GetClientRect hwnd, rcFill
               FillRect hDc, rcFill, hBgBrush
               ' // Deletes the brush
               DeleteObject hBgBrush
            END IF
            pIPicture = NOTHING
         END IF
         ' // Ends the painting of the window
         IF wMsg = %WM_PAINT THEN
            EndPaint hwnd, ps
         END IF
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

   ' Default processing for other messages.
   FUNCTION = DefWindowProc(hwnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================


' ########################################################################################
' ###########################  FUNCTIONS AND PROCEDURES ##################################
' ########################################################################################

' ========================================================================================
' Creates an IPicture object from the contents of a buffer.
' Parameters:
' * pBuff = Pointer to the buffer.
' * nSize = Size of the buffer.
' Return value:
' * The address of a pointer to the IPicture object.
' ========================================================================================
FUNCTION PictureCtx_LoadFromBuffer (BYVAL pBuff AS BYTE PTR, BYVAL nSize AS LONG) AS DWORD

   LOCAL hr AS LONG
   LOCAL hGlobal AS DWORD
   LOCAL pd AS DWORD
   LOCAL pIStream AS IStream
   LOCAL pIPicture AS DWORD

   ' // Checks parameters for validity
   IF pBuff = %NULL OR nSize < 1 THEN EXIT FUNCTION
   ' // Allocates nsize bytes from the heap
   hGlobal = GlobalAlloc(%GMEM_MOVEABLE, nSize)
   ' // Locks the global memory object and returns a pointer
   ' // to the first byte of the object's memory block
   pd = GlobalLock(hGlobal)
   ' // Copy the buffer in the stream
   MoveMemory BYVAL pd, BYVAL pBuff, nSize
   ' // Unlocks the memory
   GlobalUnlock hGlobal
   ' // Creates a stream object stored in global memory
   IF CreateStreamOnHGlobal(hGlobal, %TRUE, pIStream) = %S_OK THEN
      ' // Creates a new picture object and initializes it from the contents of a stream
      hr = OleLoadPicture(pIStream, nSize, %FALSE, $IID_IPicture, pIPicture)
      ' // Release the stream
      pIStream = NOTHING
   END IF

   ' // Returns the interface pointer
   FUNCTION = pIPicture

END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads a picture from a file and creates an IPicture object.
' Parameter:
' * wszFileName = Path and name of the image file
' Return value:
' * %S_OK or an error code.
' ========================================================================================
FUNCTION PictureCtx_LoadImageFromFile (BYVAL hwnd AS DWORD, BYREF wszFileName AS WSTRINGZ) AS LONG

   LOCAL pdata AS PICTURECTXDATA PTR         ' // Pointer to the control data
   LOCAL hFile AS LONG                       ' // File number
   LOCAL strPicture AS STRING                ' // String buffer
   LOCAL pIPicture AS IPicture               ' // IPicture

   ' // Checks the validity of the parameters
   IF ISFALSE hwnd THEN FUNCTION = %E_POINTER : EXIT FUNCTION
   IF LEN(wszFileName) = 0 THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION

   ' // Gets a Pointer to the control data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN FUNCTION = %E_POINTER : EXIT FUNCTION

   ' // Opens the file and creates the IPicture object
   TRY
      hFile = FREEFILE
      OPEN wszFileName FOR BINARY AS #hFile
      GET$ #hFile, LOF(hFile), strPicture
      ' // Release the previous IPicture object, if any
      IF @pdata.m_pPicture THEN
         IUnknown_Release @pdata.m_pPicture
         @pdata.m_pPicture = %NULL
      END IF
      @pdata.m_pPicture = PictureCtx_LoadFromBuffer(STRPTR(strPicture), LEN(strPicture))
      InvalidateRect hwnd, BYVAL %NULL, 0
      UpdateWindow hwnd
   CATCH
      FUNCTION = ERR
      MessageBox(BYVAL hwnd, "Error" & STR$(ERR) & " loading the file   ", "Error", _
                 %MB_OK OR %MB_ICONERROR OR %MB_APPLMODAL)
   FINALLY
      CLOSE #hFile
   END TRY

END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads a picture from a resource and creates an IPicture object.
' Parameters:
' * hInstance = A handle to the module whose executable file contains the resource.
' * wszResourceName = Resource name.
' Return value:
' * %S_OK or an error code.
' ========================================================================================
FUNCTION PictureCtx_LoadImageFromResource (BYVAL hwnd AS DWORD, BYVAL hInstance AS DWORD, BYREF wszResourceName AS WSTRINGZ) AS LONG

   LOCAL pdata AS PICTURECTXDATA PTR         ' // Pointer to the control data
   LOCAL hResInfo AS DWORD                   ' // Resource handle
   LOCAL imageSize AS DWORD                  ' // Size of the image
   LOCAL pResData AS DWORD                   ' // Pointer to the resource data

   ' // Checks the validity of the parameters
   IF ISFALSE hwnd THEN FUNCTION = %E_POINTER : EXIT FUNCTION
   IF LEN(wszResourceName) = 0 THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION

   ' // Gets a Pointer to the control data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN FUNCTION = %E_POINTER : EXIT FUNCTION

   ' // Loads the resource and creates the IPicture object
   hResInfo = FindResourceW(hInstance, wszResourceName, BYVAL %RT_RCDATA)
   IF hResInfo = 0 THEN EXIT FUNCTION

   ' // Retrieve the image size
   imageSize = SizeOfResource(hInstance, hResInfo)
   IF imageSize = 0 THEN FUNCTION = %E_UNEXPECTED : EXIT FUNCTION

   ' // Load and lock the resource
   pResData = LockResource(LoadResource(hInstance, hResInfo))
   IF pResData = 0 THEN FUNCTION = %E_POINTER : EXIT FUNCTION

   ' // Release the previous IPicture object, if any
   IF @pdata.m_pPicture THEN
      IUnknown_Release @pdata.m_pPicture
      @pdata.m_pPicture = %NULL
   END IF

   ' // Create the IPicture from the resource data
   @pdata.m_pPicture = PictureCtx_LoadFromBuffer(pResData, imageSize)

   ' // Redraw the control
   InvalidateRect hwnd, BYVAL %NULL, 0
   UpdateWindow hwnd

END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads a picture from a string buffer and creates an IPicture object.
' Parameters:
' * hwnd = Control's window handle
' * strPicture = String containing the image data
' Return value:
' * %S_OK or an error code.
' ========================================================================================
FUNCTION PictureCtx_LoadImageFromStringBuffer (BYVAL hwnd AS DWORD, BYVAL strPicture AS STRING) AS LONG

   LOCAL pdata AS PICTURECTXDATA PTR         ' // Pointer to the control data
   LOCAL hFile AS LONG                       ' // File number

   ' // Checks the validity of the parameters
   IF ISFALSE hwnd THEN FUNCTION = %E_POINTER : EXIT FUNCTION
   IF LEN(strPicture) = 0 THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION

   ' // Gets a Pointer to the control data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN FUNCTION = %E_POINTER : EXIT FUNCTION

   ' // Release the previous IPicture object, if any
   IF @pdata.m_pPicture THEN
      IUnknown_Release @pdata.m_pPicture
      @pdata.m_pPicture = %NULL
   END IF

   ' // Creates the IPicture object
   @pdata.m_pPicture = PictureCtx_LoadFromBuffer(STRPTR(strPicture), LEN(strPicture))
   InvalidateRect hwnd, BYVAL %NULL, 0
   UpdateWindow hwnd
   FUNCTION = %S_OK

END FUNCTION
' ========================================================================================

' ========================================================================================
' Redraws the control.
' Parameters:
' * hwnd = Control's window handle
' Return value:
' * No return value.
' ========================================================================================
SUB PictureCtx_Redraw (BYVAL hwnd AS DWORD)
   IF ISFALSE hwnd THEN EXIT SUB
   InvalidateRect hwnd, BYVAL %NULL, 0
   UpdateWindow hwnd
END SUB
' ========================================================================================

' ========================================================================================
' Sets the image adjustment.
' Parameters:
' * hwnd = Control's window handle
' * ImageAdjustment =
'     %PictureCtx_AUTOSIZE = 0
'        Autoadjusts the image to the width or height of the control
'     %PictureCtx_ACTUALSIZE = 1
'        Shows the image with its actual size
'     %PictureCtx_FITTOWIDTH = 2
'        Adjusts the image to the width of the control
'     %PictureCtx_FITTOHEIGHT = 3
'        Adjusts the image to the height of the control
' * fRedraw = [optional] TRUE or FALSE (redraws the control to reflect the changes)
' Return value:
' * Returns the previous setting.
' ========================================================================================
FUNCTION PictureCtx_SetImageAdjustment (BYVAL hwnd AS DWORD, BYVAL ImageAdjustment AS LONG, OPTIONAL fRedraw AS LONG) AS LONG

   LOCAL pdata AS PICTURECTXDATA PTR    ' // Pointer to the control data

   ' // Checks the validity of the parameter
   IF ISFALSE hwnd THEN EXIT FUNCTION
   ' // Gets a Pointer to the control data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN EXIT FUNCTION
   ' // Returns the old setting
   FUNCTION = @pdata.m_Fit
   ' // Store the new setting
   @pdata.m_Fit = ImageAdjustment
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
FUNCTION PictureCtx_GetImageAdjustment (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pdata AS PICTURECTXDATA PTR    ' // Pointer to the control data

   ' // Checks the validity of the parameter
   IF ISFALSE hwnd THEN EXIT FUNCTION
   ' // Gets a Pointer to the control data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN EXIT FUNCTION
   ' // Returns the setting value
   FUNCTION = @pdata.m_Fit

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
FUNCTION PictureCtx_SetBkColor (BYVAL hwnd AS DWORD, BYVAL clr AS LONG, OPTIONAL BYVAL fRedraw AS LONG) AS LONG

   LOCAL pdata AS PICTURECTXDATA PTR    ' // Pointer to the control data

   ' // Checks the validity of the parameter
   IF ISFALSE hwnd THEN EXIT FUNCTION
   ' // Gets a Pointer to the control data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN EXIT FUNCTION
   ' // Returns the old setting
   FUNCTION = @pdata.m_BkColor
   ' // Stores the new color
   @pdata.m_BkColor = clr
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
FUNCTION PictureCtx_GetBkColor (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pdata AS PICTURECTXDATA PTR    ' // Pointer to the control data

   ' // Checks the validity of the parameter
   IF ISFALSE hwnd THEN EXIT FUNCTION
   ' // Gets a Pointer to the control data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN EXIT FUNCTION
   ' // Returns the current background color
   FUNCTION = @pdata.m_BkColor

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the IPicture interface pointer.
' Parameter:
' * hwnd = Control's window handle
' Return value:
' * The interface object reference.
' ========================================================================================
FUNCTION PictureCtx_GetDirectInterfacePointer (BYVAL hwnd AS DWORD) AS IPicture

   LOCAL pdata AS PICTURECTXDATA PTR    ' // Pointer to the control data

   ' // Checks the validity of the parameter
   IF ISFALSE hwnd THEN EXIT FUNCTION
   ' // Gets a Pointer to the control data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN EXIT FUNCTION
   ' // Returns the interface pointer
   FUNCTION = Ptr2Obj(@pdata.m_pPicture)

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
FUNCTION PictureCtx_Clear (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pdata AS PICTURECTXDATA PTR    ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF ISFALSE hwnd THEN EXIT FUNCTION
   ' // Gets a Pointer to the control data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN EXIT FUNCTION

   ' // Releases the IPicture object, if any
   IF @pdata.m_pPicture THEN
      IUnknown_Release @pdata.m_pPicture
      @pdata.m_pPicture = %NULL
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
