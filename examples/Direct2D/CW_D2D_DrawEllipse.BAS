' ########################################################################################
' Microsoft Windows
' File: EX_CW_D2D_HWND_DrawEllipse
' Contents: Direct2D example (Window target)
' Compilers: PBWIN 10.02+, PBCC 6.02+
' Headers: Windows API headers 3.1.05+
' Copyright (c) 2012 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################
#COMPILE EXE
#DIM ALL
%UNICODE = 1

' // Include files for external files
#INCLUDE ONCE "CWindow.inc"            ' // CWindow class
#INCLUDE ONCE "d2d1.inc"               ' // Direct2D interfaces

GLOBAL g_pD2D AS ID2D

MACRO D2DCOLORF_(r_,g_,b_,a_) = MKS$(r_) & MKS$(g_) & MKS$(b_) & MKS$(a_)
MACRO D2DPOINT2F_(x_,y_,rx_,ry_) = MKS$(x_) & MKS$(y_) & MKS$(rx_) & MKS$(ry_)
MACRO D2DHWNDRENDERTARGETPROPERTIES_(hw_,w_,h_,op_) = MKDWD$(hw_) & MKDWD$(w_) & MKDWD$(h_) & MKDWD$(op_)

' ========================================================================================
' Class CD2D
' ========================================================================================
CLASS CD2D

   INSTANCE m_pD2DFactory AS ID2D1Factory
   INSTANCE m_pRenderTarget AS ID2D1HwndRenderTarget
   INSTANCE m_pBlueBrush AS ID2D1Brush

   ' =====================================================================================
   ' Constructor
   ' =====================================================================================
   CLASS METHOD Create
      ' // Create the D2D factory
      D2D1CreateFactory2(%D2D1_FACTORY_TYPE_SINGLE_THREADED, m_pD2DFactory)
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   INTERFACE ID2D : INHERIT IAutomation
   ' #####################################################################################

   ' ========================================================================================
   ' This method draws Direct2D content to a window. It will automatically discard
   ' device-specific resources if the D3D device disappears during function invocation,
   ' and will recreate the resources the next time it's invoked.
   ' ========================================================================================
   METHOD RenderScene (BYVAL hwnd AS DWORD)

      LOCAL hr AS LONG

      ' // Create a DC render target.
      IF ISNOTHING(m_pRenderTarget) THEN
         LOCAL rc AS RECT
         GetClientRect(hwnd, rc)

         LOCAL rtp AS D2D1_RENDER_TARGET_PROPERTIES
         rtp.type = %D2D1_RENDER_TARGET_TYPE_DEFAULT
         rtp.pixelFormat.format = %DXGI_FORMAT_B8G8R8A8_UNORM
         rtp.pixelFormat.alphaMode = %D2D1_ALPHA_MODE_IGNORE
         rtp.dpiX = 0 : rtp.dpiY = 0
         rtp.usage = %D2D1_RENDER_TARGET_USAGE_NONE
         rtp.minLevel = %D2D1_FEATURE_LEVEL_DEFAULT

'         LOCAL hrtp AS D2D1_HWND_RENDER_TARGET_PROPERTIES
'         hrtp.hwnd = hwnd
'         hrtp.pixelSize.width = rc.Right - rc.Left
'         hrtp.pixelSize.height = rc.Bottom - rc.Top
'         hrtp.presentOptions = %D2D1_PRESENT_OPTIONS_NONE
         hr = m_pD2DFactory.CreateHwndRenderTarget(rtp, _
              D2DHWNDRENDERTARGETPROPERTIES_(hwnd, rc.Right - rc.Left, rc.Bottom - rc.Top, %D2D1_PRESENT_OPTIONS_NONE), _
              m_pRenderTarget)
         IF SUCCEEDED(hr) THEN
            ' // Create a blue brush.
'            LOCAL clr AS D2D1_COLOR_F
'            clr.r = 0 : clr.g = 0 : clr.b = &HFF : clr.a = 1
'            hr = m_pRenderTarget.CreateSolidColorBrush(clr, BYVAL %NULL, m_pBlueBrush)
            hr = m_pRenderTarget.CreateSolidColorBrush(D2DCOLORF_(0,0,&HFF,1), BYVAL %NULL, m_pBlueBrush)
         END IF
      END IF

      IF SUCCEEDED(hr) THEN
         ' // The BeginDraw method signals the start of drawing.
         m_pRenderTarget.BeginDraw

         ' // The Clear method fills the entire render target with a solid color.
'         LOCAL clearColor AS D2D1_COLOR_F
'         clearColor.r = &HFF : clearColor.g = &HFF : clearColor.b = &HFF : clearColor.a = 0
'         m_pRenderTarget.Clear(clearColor)
         m_pRenderTarget.Clear(D2DCOLORF_(&HFF,&HFF,&HFF,0))

         ' // Draws an ellipse
'         LOCAL tEllipse AS D2D1_ELLIPSE
'         tEllipse.point.x = 150 : tEllipse.point.y = 150 : tEllipse.radiusX = 100 : tEllipse.radiusY = 100
'         m_pRenderTarget.DrawEllipse(tEllipse, m_pBlueBrush, 3)
         m_pRenderTarget.DrawEllipse(D2DPOINT2F_(150,140,100,100), m_pBlueBrush, 3)

         ' // The BeginDraw, ClearRgba, and DrawEllipse methods all have a void return type.
         ' // If an error occurs during the execution of any of these methods, the error
         ' // is signaled through the return value of the EndDraw method.
         ' // The EndDraw method signals the completion of drawing for this frame. All
         ' // drawing operations must be placed between calls to BeginDraw and EndDraw.
         hr = m_pRenderTarget.EndDraw
      END IF

      ' // Direct2D signals a lost device by returning the error code D2DERR_RECREATE_TARGET
      ' // from the EndDraw method. If you receive this error code, you must re-create the
      ' // render target and all device-dependent resources.
      IF hr = %D2DERR_RECREATE_TARGET THEN
         ' // To discard a resource, simply release the interface for that resource.
         m_pRenderTarget = NOTHING
         m_pBlueBrush = NOTHING
      END IF

   END METHOD
   ' ========================================================================================

   END INTERFACE

END CLASS
' ========================================================================================

' ========================================================================================
' Main
' ========================================================================================
FUNCTION WinMain (BYVAL hInstance AS DWORD, BYVAL hPrevInstance AS DWORD, BYVAL lpszCmdLine AS WSTRINGZ PTR, BYVAL nCmdShow AS LONG) AS LONG

   ' // Set process DPI aware
   IF AfxGetWindowsVersion => 6 THEN SetProcessDPIAware

   ' // Create an instance of the CWindow class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' // Create an instance of the CD2D class
   g_pD2D = CLASS "CD2D"
   IF ISNOTHING(g_pD2D) THEN EXIT FUNCTION

   ' // Create the application window.
   pWindow.CreateWindow(%NULL, "Direct2D DrawEllipse", 0, 0, 0, 0, 0, 0, CODEPTR(WindowProc))
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
         g_pD2D.RenderScene(hwnd)
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
