' ########################################################################################
' Microsoft Windows
' File: CW_D2DSkeleton.pbtpl
' Contents: Template - Direct2D skeleton
' Compilers: PBWIN 10.02+, PBCC 6.02+
' Headers: Windows API headers 2.03+
' Copyright (c) 2011 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################
#COMPILE EXE
#DIM ALL
%UNICODE = 1

' // Include files for external files
#INCLUDE ONCE "CWindow.inc"            ' // CWindow class
#INCLUDE ONCE "d2d1Helper.inc"         ' // Helper class

GLOBAL g_pD2DFactory AS ID2D1Factory   ' // ID2D1Factory interface
GLOBAL g_pD2DHelper AS ID2D1Helper     ' // ID2D1Helper interface

' ========================================================================================
' Main
' ========================================================================================
FUNCTION WinMain (BYVAL hInstance AS DWORD, BYVAL hPrevInstance AS DWORD, BYVAL lpszCmdLine AS WSTRINGZ PTR, BYVAL nCmdShow AS LONG) AS LONG

   ' // Set process DPI aware
'   IF AfxGetWindowsVersion => 6 THEN SetProcessDPIAware

   ' // Create an instance of the CWindow class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' // Create D2D factory
   D2D1CreateFactory2(%D2D1_FACTORY_TYPE_SINGLE_THREADED, g_pD2DFactory)
   IF ISNOTHING(g_pD2DFactory) THEN EXIT FUNCTION

   ' // Create an instance of the CD2D1Helper class
   g_pD2DHelper = CLASS "CD2D1Helper"
   IF ISNOTHING(g_pD2DHelper) THEN EXIT FUNCTION

   ' // Create the application window.
   pWindow.CreateWindow(%NULL, "Direct2D Demo App", 0, 0, 0, 0, 0, 0, CODEPTR(WindowProc))
   ' // Set the client size
   pWindow.SetClientSize 300, 300
   ' // Center the window
   pWindow.CenterWindow

   ' // Default message pump (you can replace it with your own)
   pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main callback function.
' ========================================================================================
FUNCTION WindowProc (BYVAL hwnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   ' // Process window mesages
   SELECT CASE uMsg

      CASE %WM_COMMAND
         SELECT CASE LO(WORD, wParam)
            CASE %IDCANCEL
               ' // If the Escape key has been pressed...
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  ' // ... close the application by sending a WM_CLOSE message
                  SendMessage hwnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT

      ' // Because the render target is a window (as opposed to a bitmap or other
      ' // offscreen surface), drawing is done in response to WM_PAINT messages.
      CASE %WM_PAINT
         ' // Render the scene
         LOCAL ps AS PAINTSTRUCT
         BeginPaint hwnd, ps
         RenderScene hwnd, ps
         EndPaint hwnd, ps
         EXIT FUNCTION

      ' // Don't erase the background to avoid flicker
      CASE %WM_ERASEBKGND
         FUNCTION = 1
         EXIT FUNCTION

      CASE %WM_DESTROY
         ' // End the application
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   ' // Pass unprocessed messages to Windows
   FUNCTION = DefWindowProc(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' This function draws Direct2D content to a GDI HDC.
' This function will automatically discard device-specific resources if the D3D device
' disappears during function invocation, and will recreate the resources the next time
' it's invoked.
' ========================================================================================
FUNCTION RenderScene (BYVAL hwnd AS DWORD, BYREF ps AS PAINTSTRUCT) AS LONG

   LOCAL hr AS LONG
   STATIC pRenderTarget AS ID2D1DCRenderTarget
   STATIC pBlackBrush AS ID2D1SolidColorBrush

   ' // Create a DC render target.
   IF ISNOTHING(pRenderTarget) THEN
      LOCAL props AS D2D1_RENDER_TARGET_PROPERTIES
      props = g_pD2DHelper.RenderTargetProperties(%D2D1_RENDER_TARGET_TYPE_DEFAULT, _
              g_pD2DHelper.PixelFormat(%DXGI_FORMAT_B8G8R8A8_UNORM, %D2D1_ALPHA_MODE_IGNORE), _
              0, 0, %D2D1_RENDER_TARGET_USAGE_NONE, %D2D1_FEATURE_LEVEL_DEFAULT)
      hr = g_pD2DFactory.CreateDCRenderTarget(props, pRenderTarget)
      IF SUCCEEDED(hr) THEN
         ' // Create a black brush.
         hr = pRenderTarget.CreateSolidColorBrush(g_pD2DHelper.ColorF_3(%D2D1_Black), BYVAL %NULL, pBlackBrush)
      END IF
   END IF

   IF SUCCEEDED(hr) THEN
      ' // Get the dimensions of the client drawing area.
      LOCAL rc AS RECT
      GetClientRect(hwnd, rc)
      ' // Bind the DC to the DC render target.
      hr = pRenderTarget.BindDC(ps.hdc, rc)
      ' // The ID2D1RenderTarget::BeginDraw method signals the start of drawing.
      pRenderTarget.BeginDraw
      ' // The ID2D1RenderTarget::Clear method fills the entire render target with a
      ' // solid color. The color is given as a D2D1_COLOR_F structure.
      pRenderTarget.Clear(g_pD2DHelper.ColorF_3(%D2D1_White))
      ' // Sample code: Draws an ellipse (replace it with your drawing operations)
      pRenderTarget.DrawEllipse(g_pD2DHelper.Ellipse(g_pD2DHelper.Point2F(150.0!, 150.0!), 100.0!, 100.0!), pBlackBrush, 3.0!)
      ' // If High DPI aware, scale the ellipse
      ' // Get the DPI scaling ratios
'      LOCAL rx, ry AS SINGLE
'      AfxGetDesktopDPIRatios(rx, ry)
'      pRenderTarget.DrawEllipse(g_pD2DHelper.Ellipse(g_pD2DHelper.Point2F(150.0! * rx, 150.0! * ry), 100.0! * rx, 100.0! * ry), pBlackBrush, 3.0! * rx)


      ' // The BeginDraw, Clear, and DrawEllipse methods all have a void return type.
      ' // If an error occurs during the execution of any of these methods, the error
      ' // is signaled through the return value of the EndDraw method.
      ' // The ID2D1RenderTarget::EndDraw method signals the completion of drawing for
      ' // this frame. All drawing operations must be placed between calls to BeginDraw
      ' // and EndDraw.
      hr = pRenderTarget.EndDraw
   END IF

   ' // Direct2D signals a lost device by returning the error code D2DERR_RECREATE_TARGET
   ' // from the EndDraw method. If you receive this error code, you must re-create the
   ' // render target and all device-dependent resources.
   IF hr = %D2DERR_RECREATE_TARGET THEN
      ' // To discard a resource, simply release the interface for that resource.
      pRenderTarget = NOTHING
      pBlackBrush = NOTHING
      hr = %S_OK
   END IF

   FUNCTION = hr

END FUNCTION
' ========================================================================================
