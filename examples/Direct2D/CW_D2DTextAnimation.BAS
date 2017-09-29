' ########################################################################################
' Microsoft Windows
' File: CW_D2DTextAnimation.bas
' Compilers: PBWIN 10.02+, PBCC 6.02+
' Headers: Windows API headers 2.03+
' This sample demonstrates how to animate text using the Direct2D API. As with any other
' API, there are multiple ways though which this can be accomplished. Each rendering
' method offers certain performance and quality measures.
' It is an adaptation of the C++ program available at:
' http://archive.msdn.microsoft.com/d2dtextanimation/Release/ProjectReleases.aspx?ReleaseId=2631
' and a previous translation to PowerBASIC by Patrice Terrier, 07-26-2010.
' Portions (c) Microsoft Corporation.
' Copyright (c) 2012 José Roca. Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

'// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
'// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
'// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
'// PARTICULAR PURPOSE.
'//
'// Copyright (c) Microsoft Corporation. All rights reserved

#COMPILE EXE
#DIM ALL
#INCLUDE ONCE "CWindow.inc"
#INCLUDE ONCE "d2d1.inc"
#INCLUDE ONCE "d2d1Helper.inc"
#INCLUDE ONCE "Math.inc"

ENUM AnimationStyleEnum
   None = 0
   Translation
   Rotation
   Scaling
END ENUM

ENUM TextRenderingMethodEnum
   Default = 0
   Outline
   UseA8Target
   NumValues
END ENUM

GLOBAL g_pID2D1Helper AS ID2D1Helper
GLOBAL g_pD2DFactory AS ID2D1Factory
GLOBAL g_pTextFormat AS IDWriteTextFormat
GLOBAL g_pDWriteFactory AS IDWriteFactory
GLOBAL g_pRenderTarget AS ID2D1hwndRenderTarget
GLOBAL g_pBlackBrush AS ID2D1SolidColorBrush
GLOBAL g_pOpacityRT AS ID2D1BitmapRenderTarget
GLOBAL g_pTextLayout AS IDWriteTextLayout
GLOBAL g_overhangOffset AS D2D1_POINT_2F
GLOBAL g_startTime, g_animationStyle, g_renderingMethod  AS DWORD

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

   ' // Create an instance of the CD2D1Helper class
   g_pID2D1Helper = CLASS "CD2D1Helper"
   IF ISNOTHING(g_pID2D1Helper) THEN EXIT FUNCTION

   IF ISFALSE CreateDeviceIndependentResources THEN EXIT FUNCTION

   ' // Initialize global data
   g_startTime       = 0
   g_animationStyle  = %AnimationStyleENum.Translation OR %AnimationStyleEnum.Rotation OR %AnimationStyleEnum.Scaling
   g_renderingMethod = %TextRenderingMethodEnum.Default

   ' // Create the application window.
   pWindow.CreateWindow(%NULL, "Direct2D Demo App", 0, 0, 0, 0, 0, 0, CODEPTR(WindowProc))
   ' // Set the client size
   pWindow.SetClientSize 600, 450
   ' // Center the window
   pWindow.CenterWindow

   ' // Default message pump (you can replace it with your own)
   pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' This function is used to create resources which are not bound to any device. Their
' lifetime effectively extends for the duration of the app. These resources include the D2D,
' DWrite factories; and a DWrite Text Format object (used for identifying particular font
' characteristics) and a D2D geometry.
' ========================================================================================
FUNCTION CreateDeviceIndependentResources () AS LONG

   LOCAL hr AS LONG, stringLength AS DWORD
   LOCAL msc_fontName, msc_localName, sc_helloWorld AS WSTRINGZ * 260
   LOCAL msc_fontSize AS SINGLE

   msc_fontName  = "Gabriola"
   msc_localName = ""
   sc_helloWorld = "The quick brown fox jumped over the lazy dog!"
   msc_fontSize  = 50
   stringLength  = LEN(sc_helloWorld)

   '//create D2D factory
   hr = D2D1CreateFactory2(%D2D1_FACTORY_TYPE_SINGLE_THREADED, g_pD2DFactory)
   IF FAILED(hr) THEN EXIT FUNCTION

   ' // Create DWrite factory
   hr = DWriteCreateFactory(%DWRITE_FACTORY_TYPE_ISOLATED, $IID_IDWriteFactory, g_pDWriteFactory)
   IF FAILED(hr) THEN EXIT FUNCTION

   ' // Create DWrite text format object
   hr = g_pDWriteFactory.CreateTextFormat(msc_fontName, NOTHING, %DWRITE_FONT_WEIGHT_NORMAL, _
        %DWRITE_FONT_STYLE_NORMAL, %DWRITE_FONT_STRETCH_NORMAL, msc_fontSize, _
        msc_localName, g_pTextFormat)
   IF FAILED(hr) THEN EXIT FUNCTION

   ' // Center the text horizontally
   g_pTextFormat.SetTextAlignment(%DWRITE_TEXT_ALIGNMENT_CENTER)

   hr = g_pDWriteFactory.CreateTextLayout(sc_helloWorld, stringLength, g_pTextFormat, _
      300, 1000, g_pTextLayout)
   IF FAILED(hr) THEN EXIT FUNCTION

   ' // We use typographic features here to show how to account for the
   ' // overhangs that these features will produce. See the code in
   ' // ResetAnimation that calls GetOverhangMetrics(). Note that there are
   ' // fonts that can produce overhangs even without the use of typographic
   ' // features- this is just one example.
   LOCAL pTypography AS IDWriteTypography
   hr = g_pDWriteFactory.CreateTypography(pTypography)
   IF FAILED(hr) THEN EXIT FUNCTION

   LOCAL fontFeature AS DWRITE_FONT_FEATURE
   fontFeature.nameTag = %DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_7
   fontFeature.parameter = 1
   hr = pTypography.AddFontFeature(fontFeature)
   IF FAILED(hr) THEN EXIT FUNCTION

   LOCAL textRange AS DWRITE_TEXT_RANGE
   textRange.startPosition = 0
   textRange.length = stringLength
   hr = g_pTextLayout.SetTypography(pTypography, textRange)
   IF FAILED(hr) THEN EXIT FUNCTION

   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' This function creates resources which are bound to a particular D3D device. It's all
' centralized here, in case the resources need to be recreated in case of D3D device loss
' (eg. display change, remoting, removal of video card, etc).
' ========================================================================================
FUNCTION CreateDeviceResources(BYVAL hwnd AS LONG) AS LONG

   LOCAL hr AS LONG

   IF ISNOTHING(g_pRenderTarget) THEN
      LOCAL rc AS RECT
      GetClientRect(hwnd, rc)
      '// Create a D2D render target
      '//
      '// Note: we only use D2D1_PRESENT_OPTIONS_IMMEDIATELY so that we can
      '// easily measure the framerate. Most apps should not use this
      '// flag.
      hr = g_pD2DFactory.CreatehwndRenderTarget( _
           g_pID2D1Helper.RenderTargetProperties, _
           g_pID2D1Helper.hwndRenderTargetProperties(hwnd, _
           g_pID2D1Helper.SizeU(rc.Right - rc.Left, rc.Bottom - rc.Top), _
           %D2D1_PRESENT_OPTIONS_IMMEDIATELY), _
           g_pRenderTarget)
      IF SUCCEEDED(hr) THEN
         ' // Nothing in this sample requires antialiasing so we set the antialias
         ' // mode to aliased up front.
         g_pRenderTarget.SetAntialiasMode(%D2D1_ANTIALIAS_MODE_ALIASED)

         ' // Create a black brush
         LOCAL brushProperties AS D2D1_BRUSH_PROPERTIES
         brushProperties.opacity = 1.0
         brushProperties.transform =  g_pID2D1Helper.IdentityMatrix()
         hr = g_pRenderTarget.CreateSolidColorBrush( _
              g_pID2D1Helper.ColorF_2(%D2D1_Black, 1.0), _
              brushProperties, _
              g_pBlackBrush)
      END IF
      IF SUCCEEDED(hr) THEN hr = ResetAnimation(%TRUE)
   END IF

   FUNCTION = hr

END FUNCTION
' ========================================================================================

' ========================================================================================
' Discard device-specific resources which need to be recreated when a D3D device is lost
' ========================================================================================
SUB DiscardDeviceResources
    g_pRenderTarget = NOTHING
    g_pBlackBrush   = NOTHING
    g_pOpacityRT    = NOTHING
END SUB
' ========================================================================================

' ========================================================================================
' Responds to input from the user.
' ========================================================================================
FUNCTION OnChar (BYVAL Charkey AS LONG) AS LONG

   LOCAL hr, bResetAnimation, bResetClock AS LONG

   bResetAnimation = -1
   bResetClock = -1

    SELECT CASE Charkey

      CASE %VK_T
         IF (g_animationStyle AND %AnimationStyleEnum.Translation) THEN
            g_animationStyle = g_animationStyle AND (NOT %AnimationStyleEnum.Translation)
         ELSE
            g_animationStyle = g_animationStyle OR %AnimationStyleEnum.Translation
         END IF

      CASE %VK_R
         IF (g_animationStyle AND %AnimationStyleEnum.Rotation) THEN
            g_animationStyle = g_animationStyle AND (NOT %AnimationStyleEnum.Rotation)
         ELSE
            g_animationStyle = g_animationStyle OR %AnimationStyleEnum.Rotation
         END IF

      CASE %VK_S
         IF (g_animationStyle AND %AnimationStyleEnum.Scaling) THEN
            g_animationStyle = g_animationStyle AND (NOT %AnimationStyleEnum.Scaling)
         ELSE
            g_animationStyle = g_animationStyle OR %AnimationStyleEnum.Scaling
         END IF

      CASE %VK_1, %VK_2, %VK_3
         g_renderingMethod = CharKey - 49
         bResetClock = 0

      CASE ELSE
         bResetAnimation = 0
         bResetClock = 0

   END SELECT

   IF bResetAnimation THEN hr = ResetAnimation(bResetClock)

   FUNCTION = hr

END FUNCTION
' ========================================================================================

' ========================================================================================
' This procedure updates the window title bar with info about the current animation style
' and rendering method. It also outputs the framerate.
' ========================================================================================
SUB UpdateWindowText (BYVAL hwnd AS LONG)

   LOCAL sTitle, sT, sR, sS, sMethod, sFps AS STRING
   STATIC sWasTitle AS STRING
   STATIC dwFrames, dwCurrentTime, dwLastUpdateTime, dwElapsedTime AS DWORD

   dwFrames += 1
   dwCurrentTime = timeGetTime()
   dwElapsedTime = dwCurrentTime - dwLastUpdateTime
   IF dwElapsedTime > 999 THEN

      IF dwLastUpdateTime THEN sFps = "," + STR$( dwFrames * 1000 \ dwElapsedTime) + " fps"
      dwFrames = 0: dwLastUpdateTime = dwCurrentTime

'    STATIC sc_lastTimeStatusShown AS QUAD
'
'    '//
'    '// Update the window status no more than 10 times a second. Without this
'    '// check, the performance bottleneck could potentially be the time it takes
'    '// for Windows to update the title.
'    '//
'    IF  g_times.GetCount() > 0 AND g_times.GetLast() > sc_lastTimeStatusShown + 1000000 THEN
'        '// Determine the frame rate by computing the difference in clock time
'        '// between this frame and the frame we rendered 10 frames ago.
'        sc_lastTimeStatusShown = g_times.GetLast()
'
'        LOCAL qfrequency AS QUAD
'        QueryPerformanceFrequency(qfrequency)
'
'        IF (g_times.GetCount() > 0) THEN
'            sFps = "," + STR$((g_times.GetCount()-1) * frequency.QuadPart /
'                    static_cast<float>((g_times.GetLast() - g_times.GetFirst()))) + " fps"
'        END IF

      SELECT CASE LONG g_renderingMethod
         CASE %TextRenderingMethodEnum.Default
            sMethod = "Default"
         CASE %TextRenderingMethodEnum.Outline
            sMethod = "Outline"
         CASE %TextRenderingMethodEnum.UseA8Target
            sMethod = "UseA8Target"
      END SELECT

      sTitle = "AnimationStyle: "
      IF (g_animationStyle AND %AnimationStyleEnum.Translation) THEN sT = "+t" ELSE sT = "-t"
      IF (g_animationStyle AND %AnimationStyleEnum.Rotation) THEN sR = "+r" ELSE sR = "-r"
      IF (g_animationStyle AND %AnimationStyleEnum.Scaling) THEN sS = "+s" ELSE sS = "-s"
      sTitle = BUILD$(sTitle, sT, sR, sS, ", Method: ", sMethod, sFps, $NUL)

      IF sTitle <> sWasTitle THEN
         SetWindowText(hwnd, BYVAL STRPTR(sTitle))
         sWasTitle = sTitle
      END IF

   END IF

END SUB
' ========================================================================================

' ========================================================================================
' This function does the necessary work to change the current animation style.
' ========================================================================================
FUNCTION ResetAnimation(BYVAL resetClock AS LONG) AS LONG

   LOCAL hr AS LONG

   IF resetClock THEN g_startTime = GetTickCount()

   ' // Release the opacity mask. We will regenerate it if the current animation style demands it.
   g_pOpacityRT = NOTHING

   IF g_renderingMethod = %TextRenderingMethodEnum.Outline THEN

      ' // Set the rendering mode to OUTLINE mode. To do this we first create
      ' // a default params object and then make a copy with the given modification.

      LOCAL pDefaultParams AS IDWriteRenderingParams
      hr = g_pDWriteFactory.CreateRenderingParams(pDefaultParams)

      IF SUCCEEDED(hr) THEN
         LOCAL pRenderingParams AS IDWriteRenderingParams
         hr = g_pDWriteFactory.CreateCustomRenderingParams( _
              pDefaultParams.GetGamma(), _
              pDefaultParams.GetEnhancedContrast(), _
              pDefaultParams.GetClearTypeLevel(), _
              pDefaultParams.GetPixelGeometry(), _
              %DWRITE_RENDERING_MODE_OUTLINE, _
              pRenderingParams)
         IF SUCCEEDED(hr) THEN
            g_pRenderTarget.SetTextRenderingParams(pRenderingParams)
            pRenderingParams = NOTHING
         END IF
         pDefaultParams = NOTHING
      END IF
   ELSE
      '// Reset the rendering mode to default.
      g_pRenderTarget.SetTextRenderingParams(NOTHING)
   END IF

   IF SUCCEEDED(hr) AND g_renderingMethod = %TextRenderingMethodEnum.UseA8Target THEN

      ' // Create a compatible A8 Target to store the text as an opacity mask.
      ' //
      ' // Note: To reduce sampling error in the scale animation, it might be
      ' //       preferable to create multiple masks for the text at different
      ' //       resolutions.

      LOCAL dpiX, dpiY AS SINGLE
      g_pRenderTarget.GetDpi(dpiX, dpiY)

      ' // It is important to obtain the overhang metrics here in case the text
      ' // extends beyond the layout max-width and max-height.
      LOCAL overhangMetrics AS DWRITE_OVERHANG_METRICS
      g_pTextLayout.GetOverhangMetrics(overhangMetrics)

      ' // Because the overhang metrics can be off slightly given that these
      ' // metrics do not account for antialiasing, we add an extra pixel for
      ' // padding.
      LOCAL padding AS D2D1_SIZE_F
      padding = g_pID2D1Helper.SizeF(96.0 / dpiX, 96.0 / dpiY)
      g_overhangOffset = g_pID2D1Helper.Point2F(CEIL(overhangMetrics.left + padding.width), CEIL(overhangMetrics.top + padding.height))

      '// The true width of the text is the max width + the overhang
      '// metrics + padding in each direction.
      LOCAL maskSize AS D2D1_SIZE_F
      maskSize = g_pID2D1Helper.SizeF( _
                 overhangMetrics.right + padding.width + g_overhangOffset.x + g_pTextLayout.GetMaxWidth, _
                 overhangMetrics.bottom + padding.height + g_overhangOffset.y + g_pTextLayout.GetMaxHeight)

      ' // Round up to the nearest pixel
      LOCAL maskPixelSize AS D2D1_SIZE_U
      maskPixelSize = g_pID2D1Helper.SizeU(CEIL(maskSize.width * dpiX / 96.0), CEIL(maskSize.height * dpiY / 96.0))

      ' // Create the compatible render target using desiredPixelSize to avoid
      ' // blurriness issues caused by a fractional-pixel desiredSize.
      LOCAL alphaOnlyFormat AS D2D1_PIXEL_FORMAT
      alphaOnlyFormat = g_pID2D1Helper.PixelFormat(%DXGI_FORMAT_A8_UNORM, %D2D1_ALPHA_MODE_PREMULTIPLIED)
      hr = g_pRenderTarget.CreateCompatibleRenderTarget( _
           BYVAL %NULL, maskPixelSize, alphaOnlyFormat, %D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_NONE, g_pOpacityRT)

      IF SUCCEEDED(hr) THEN
         ' // Draw the text to the opacity mask. Note that we can use pixel
         ' // snapping now given that subpixel translation can now happen during
         ' // the FillOpacityMask method.
         g_pOpacityRT.BeginDraw
         g_pOpacityRT.Clear(g_pID2D1Helper.ColorF_2(%D2D1_Black, 0.0))
         g_pOpacityRT.DrawTextLayout(g_overhangOffset, g_pTextLayout, g_pBlackBrush, %D2D1_DRAW_TEXT_OPTIONS_NO_SNAP)
         hr = g_pOpacityRT.EndDraw
      END IF

   END IF

   FUNCTION = hr

END FUNCTION
' ========================================================================================

' ========================================================================================
' Calculates the transform based on the current time
' ========================================================================================
SUB CalculateTransform(pTransform AS D2D1_MATRIX_3X2_F)

   ' // Calculate a 't' value that will linearly interpolate from 0 to 1 and back every 20 seconds
   LOCAL currentTime AS DWORD
   currentTime = GetTickCount()
   IF g_startTime = 0 THEN g_startTime = currentTime
   LOCAL t AS SINGLE
   t = 2 * (( currentTime - g_startTime) MOD 20000) / 20000.0
   IF t > 1.0 THEN t = 2 - t

   ' // Calculate animation parameters
   LOCAL rotation, translationOffset, scaleMultiplier AS SINGLE
   rotation = 0
   translationOffset = 0
   scaleMultiplier = 1.0
   IF (g_animationStyle AND %AnimationStyleEnum.Translation) THEN
      ' // range from -100 to 100
      translationOffset = (t - 0.5) * 200
   END IF

   IF (g_animationStyle AND %AnimationStyleEnum.Rotation) THEN
      '// range from 0 to 360
      rotation = t * 360.0
   END IF

   IF (g_animationStyle AND %AnimationStyleEnum.Scaling) THEN
      '// range from 1/4 to 2x the normal size
      scaleMultiplier = t * 1.75 + 0.25
   END IF

   LOCAL renderTargetSize AS D2D1_SIZE_F
   renderTargetSize = g_pRenderTarget.GetSize()

   LOCAL center AS D2D1_POINT_2F

   ' // *pTransform =
   ' //      D2D1::Matrix3x2F::Rotation(rotation)
   ' //    * D2D1::Matrix3x2F::Scale(scaleMultiplier, scaleMultiplier)
   ' //    * D2D1::Matrix3x2F::Translation(translationOffset + size.width / 2.0f, translationOffset + size.height / 2.0f);
   pTransform = g_pID2D1Helper.MultiplyMatrices(g_pID2D1Helper.MatrixRotation(rotation, center), _
                g_pID2D1Helper.MatrixScale(scaleMultiplier, scaleMultiplier))
   pTransform = g_pID2D1Helper.MultiplyMatrices(pTransform, _
                g_pID2D1Helper.MatrixTranslation(translationOffset + renderTargetSize.width / 2.0, translationOffset + renderTargetSize.height / 2.0))

END SUB
' ========================================================================================

' ========================================================================================
' Note that this function will not render anything if the window is occluded (e.g. when
' the screen is locked). Also, this function will automatically discard device-specific
' resources if the D3D device disappears during function invocation, and will recreate the
' resources the next time it's invoked.
' ========================================================================================
FUNCTION OnRender(BYVAL hwnd AS LONG) AS LONG

   LOCAL hr AS LONG

   '// We use a ring buffer to store the clock time for the last 10 frames.
   '// This lets us eliminate a lot of noise when computing framerate.

   hr = CreateDeviceResources(hwnd)

   IF SUCCEEDED(hr) THEN
      IF (g_pRenderTarget.CheckWindowState() AND %D2D1_WINDOW_STATE_OCCLUDED) = 0 THEN
         LOCAL transform AS D2D1_MATRIX_3X2_F
         CalculateTransform(transform)
         g_pRenderTarget.BeginDraw
         g_pRenderTarget.Clear(g_pID2D1Helper.ColorF_2(%D2D1_White, 1.0))
         g_pRenderTarget.SetTransform(transform)
         LOCAL textMetrics AS DWRITE_TEXT_METRICS
         g_pTextLayout.GetMetrics(textMetrics)
         IF (g_renderingMethod = %TextRenderingMethodEnum.UseA8Target) THEN
            ' // Offset the destination rect such that the text will be centered
            ' // on the render target. Given that we have offset the text in the
            ' // A8 target by the overhang offset, we must factor that into the
            ' // destination rect now.
            LOCAL opacityRTSize AS D2D1_SIZE_F
            opacityRTSize = g_pOpacityRT.GetSize()
            LOCAL offset AS D2D1_POINT_2F
            offset = g_pID2D1Helper.Point2F( _
                     -textMetrics.width / 2.0 - g_overhangOffset.x, _
                     -textMetrics.height / 2.0 - g_overhangOffset.y _
                     )

            ' // Round the offset to the nearest pixel. Note that the rounding
            ' // done here is unecessary, but it causes the text to be less blurry.
            LOCAL dpiX, dpiY AS SINGLE
            g_pRenderTarget.GetDpi(dpiX, dpiY)
            LOCAL roundedOffset AS D2D1_POINT_2F
            roundedOffset = g_pID2D1Helper.Point2F( _
               floor_(offset.x * dpiX / 96.0 + 0.5) * 96.0 / dpiX, _
               floor_(offset.y * dpiY / 96.0 + 0.5) * 96.0 / dpiY _
               )

            LOCAL destinationRect AS D2D1_RECT_F
            destinationRect = g_pID2D1Helper.RectF( _
                              roundedOffset.x, _
                              roundedOffset.y, _
                              roundedOffset.x + opacityRTSize.width, _
                              roundedOffset.y + opacityRTSize.height _
                              )

            LOCAL pBitmap AS ID2D1Bitmap
            g_pOpacityRT.GetBitmap(pBitmap)

            pBitmap.GetDpi(dpiX, dpiY)

            ' // The antialias mode must be set to D2D1_ANTIALIAS_MODE_ALIASED
            ' // for this method to succeed. We've set this mode already though
            ' // so no need to do it again.
            g_pRenderTarget.FillOpacityMask(pBitmap, g_pBlackBrush, _
                %D2D1_OPACITY_MASK_CONTENT_TEXT_NATURAL, destinationRect)
               pBitmap = NOTHING
         ELSE
            LOCAL origin AS D2D1_POINT_2F
            origin = g_pID2D1Helper.Point2F(-textMetrics.width / 2.0, -textMetrics.height / 2.0)
            ' // Disable pixel snapping to get a smoother animation.
            g_pRenderTarget.DrawTextLayout(origin, g_pTextLayout, _
                   g_pBlackBrush, %D2D1_DRAW_TEXT_OPTIONS_NO_SNAP)
         END IF

         hr = g_pRenderTarget.EndDraw()

         IF hr = %D2DERR_RECREATE_TARGET THEN
            hr = %S_OK
            DiscardDeviceResources()
         END IF
         ' // To animate as quickly as possible, we request another WM_PAINT
         ' // immediately.
         InvalidateRect(hwnd, BYVAL %NULL, %FALSE)

      END IF

   END IF

   UpdateWindowText(hwnd)

   FUNCTION = hr

END FUNCTION
' ========================================================================================

' ========================================================================================
' If the application receives a WM_SIZE message, this method resize the render target appropriately.
' ========================================================================================
SUB OnResize(BYVAL nWidth AS LONG, BYVAL nHeight AS LONG)
   IF ISOBJECT(g_pRenderTarget) THEN
      LOCAL su AS D2D1_SIZE_U
      su.width = nWidth
      su.height = nHeight
      ' // Note: This method can fail, but it's okay to ignore the
      ' // error here -- it will be repeated on the next call to EndDraw.
      g_pRenderTarget.Resize(su)
   END IF
END SUB
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

      CASE %WM_SIZE
         OnResize(LO(INTEGER, lParam), HI(INTEGER, lParam))

       CASE %WM_KEYDOWN
         OnChar(wParam)
         EXIT FUNCTION

       CASE %WM_PAINT
         LOCAL ps AS PAINTSTRUCT
         BeginPaint(hwnd, ps)
         OnRender(hwnd)
         EndPaint(hwnd, ps)
         EXIT FUNCTION

       CASE %WM_DESTROY
         ' // End the application
         PostQuitMessage(0)
         EXIT FUNCTION

   END SELECT

   ' // Pass unprocessed messages to Windows
   FUNCTION = DefWindowProc(hwnd, uMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
