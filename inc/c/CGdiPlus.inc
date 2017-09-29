' ########################################################################################
' Microsoft Windows
' File: CGdiPlus.inc
' Contents: GDI+ master class.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CGDIPLUS_INC = 1

#IF NOT %DEF(%COLORMAP_DEFINED)
%COLORMAP_DEFINED = 1
' // Size = 8 bytes
TYPE COLORMAP_STRUCT_0 DWORD   ' As defined in old PB include files
   cmFrom AS DWORD   ' COLORREF from
   cmTo   AS DWORD   ' COLORREF to
END TYPE
' // Size = 8 bytes
TYPE COLORMAP_STRUCT_I DWORD   ' As defined in PB include files
   nfrom AS DWORD   ' COLORREF from
   nto   AS DWORD   ' COLORREF to
END TYPE
' // Size = 8 bytes
TYPE COLORMAP_STRUCT_II DWORD
   from AS DWORD   ' COLORREF from
   to   AS DWORD   ' COLORREF to
END TYPE
' // Size = 8 bytes
TYPE COLORMAP_STRUCT_III DWORD  ' For compatibility with GDI+
   oldColor AS DWORD   ' COLORREF oldColor
   newColor AS DWORD   ' COLORREF newColor
END TYPE
' // To allow to use both nfrom, nto and from, to
' // Size = 8 bytes
UNION COLORMAP DWORD
   COLORMAP_STRUCT_0
   COLORMAP_STRUCT_I
   COLORMAP_STRUCT_II
   COLORMAP_STRUCT_III
END UNION
#ENDIF

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "ddraw.inc"
#INCLUDE ONCE "GdiPlus.inc"
#INCLUDE ONCE "CGdipImage.inc"
#INCLUDE ONCE "CGdipBrush.inc"
#INCLUDE ONCE "CGdipCachedBitmap.inc"
#INCLUDE ONCE "CGdipFont.inc"
#INCLUDE ONCE "CGdipFontCollection.inc"
#INCLUDE ONCE "CGdipFontFamily.inc"
#INCLUDE ONCE "CGdipGraphics.inc"
#INCLUDE ONCE "CGdipImageAttributes.inc"
#INCLUDE ONCE "CGdipLineCaps.inc"
#INCLUDE ONCE "CGdipMatrix.inc"
#INCLUDE ONCE "CGdipPath.inc"
#INCLUDE ONCE "CGdipPen.inc"
#INCLUDE ONCE "CGdipRegion.inc"
#INCLUDE ONCE "CGdipStringFormat.inc"
#INCLUDE ONCE "CGdipEffect.inc"

' ########################################################################################
' CGdiPlus Class
' ########################################################################################
CLASS CGdiPlus

   INSTANCE m_hStatus AS LONG
   INSTANCE m_GdipToken AS DWORD

   ' =====================================================================================
   ' Cleanup
   ' =====================================================================================
   CLASS METHOD Destroy
      IF m_GdipToken THEN GdiplusShutdown(m_GdipToken)
   END METHOD
   ' =====================================================================================

   INTERFACE IGdiPlus : INHERIT IAutomation

   ' =====================================================================================
   ' Initilizes GDI+. Returns a token.
   ' =====================================================================================
   METHOD Init (OPTIONAL BYVAL version AS LONG) THREADSAFE AS DWORD
      IF m_GdipToken = 0 THEN
         LOCAL StartupInput AS GdiplusStartupInput
         IF version < 1 THEN version = 1
         StartupInput.GdiplusVersion = version
         m_hStatus = GdiplusStartup(m_GdipToken, StartupInput, BYVAL %NULL)
      END IF
      METHOD = m_GdipToken
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the last status code.
   ' =====================================================================================
   METHOD GetLastStatus () THREADSAFE AS LONG
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fills a RECTF structure
   ' =====================================================================================
   METHOD RectF (BYVAL x AS SINGLE, BYVAL y AS SINGLE, BYVAL nWidth AS SINGLE, BYVAL nHeight AS SINGLE) THREADSAFE AS RECTF
      LOCAL rc AS RECTF
      rc.x = x : rc.y = y : rc.Width = nWidth : rc.Height = nHeight
      METHOD = rc
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fills a RECT structure
   ' =====================================================================================
   METHOD RectI (BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) THREADSAFE AS RECT
      LOCAL rc AS RECT
      rc.x = x : rc.y = y : rc.Width = nWidth : rc.Height = nHeight
      METHOD = rc
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fills a POINTF structure
   ' =====================================================================================
   METHOD PointF (BYVAL x AS SINGLE, BYVAL y AS SINGLE) THREADSAFE AS POINTF
      LOCAL pt AS POINTF
      pt.x = x : pt.y = y
      METHOD = pt
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Fills a POINT structure
   ' =====================================================================================
   METHOD PointI (BYVAL x AS SINGLE, BYVAL y AS SINGLE) THREADSAFE AS POINT
      LOCAL pt AS POINT
      pt.x = x : pt.y = y
      METHOD = pt
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a color with the supplied alpha, red, green, and blue values.
   ' =====================================================================================
   METHOD Color (OPTIONAL BYVAL a AS BYTE, BYVAL r AS BYTE, BYVAL g AS BYTE, BYVAL b AS BYTE) AS DWORD
      METHOD = GDIP_ARGB(a, r, g, b)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The GetAlpha method gets the alpha component of an ARGB color.
   ' =====================================================================================
   METHOD GetAlpha (BYVAL argbcolor AS DWORD) AS BYTE
      LOCAL clr AS GDIP_BGRA_UNION
      clr.color = argbcolor
      METHOD = clr.alpha
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The GetRed method gets the red component of an ARGB color.
   ' =====================================================================================
   METHOD GetRed (BYVAL argbcolor AS DWORD) AS BYTE
      LOCAL clr AS GDIP_BGRA_UNION
      clr.color = argbcolor
      METHOD = clr.red
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The GetGreen method gets the green component of an ARGB color.
   ' =====================================================================================
   METHOD GetGreen (BYVAL argbcolor AS DWORD) AS BYTE
      LOCAL clr AS GDIP_BGRA_UNION
      clr.color = argbcolor
      METHOD = clr.green
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The GetBlue method gets the blue component of an ARGB color.
   ' =====================================================================================
   METHOD GetBlue (BYVAL argbcolor AS DWORD) AS BYTE
      LOCAL clr AS GDIP_BGRA_UNION
      clr.color = argbcolor
      METHOD = clr.blue
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The SetFromCOLORREF method uses a Windows Graphics Device Interface (GDI)COLORREF value
   ' to set the ARGB value.
   ' =====================================================================================
   METHOD SetFromCOLORREF (BYVAL rgbcolor AS DWORD) AS DWORD
      LOCAL clr AS GDIP_BGRA_UNION
      clr.color = rgbcolor
      METHOD = GDIP_ARGB(255, clr.red, clr.green, clr.blue)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The ToCOLORREF method converts an ARGB value to a Windows Graphics Device Interface
   ' (GDI)COLORREF value.
   ' =====================================================================================
   METHOD ToCOLORREF (BYVAL argbcolor AS DWORD) AS DWORD
      LOCAL clr AS GDIP_BGRA_UNION
      clr.color = argbcolor
      METHOD = RGB(clr.red, clr.green, clr.blue)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new Graphics object.
   ' =====================================================================================
   METHOD Graphics (BYVAL hdc AS DWORD) THREADSAFE AS IGdipGraphics
      LOCAL pGraphics AS IGdipGraphics
      pGraphics = CLASS "CGdipGraphics"
      IF ISNOTHING(pGraphics) THEN EXIT METHOD
      m_hStatus = pGraphics.FromHDC(hdc)
      METHOD = pGraphics
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD GraphicsFromHDC (BYVAL hdc AS DWORD) THREADSAFE AS IGdipGraphics
      LOCAL pGraphics AS IGdipGraphics
      pGraphics = CLASS "CGdipGraphics"
      IF ISNOTHING(pGraphics) THEN EXIT METHOD
      m_hStatus = pGraphics.FromHDC(hdc)
      METHOD = pGraphics
   END METHOD
   ' =====================================================================================
   METHOD GraphicsFromHDC2 (BYVAL hdc AS DWORD, BYVAL hDevice AS DWORD) THREADSAFE AS IGdipGraphics
      LOCAL pGraphics AS IGdipGraphics
      pGraphics = CLASS "CGdipGraphics"
      IF ISNOTHING(pGraphics) THEN EXIT METHOD
      m_hStatus = pGraphics.FromHDC2(hdc, hDevice)
      METHOD = pGraphics
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD GraphicsFromHWND (BYVAL hwnd AS DWORD, OPTIONAL BYVAL icm AS LONG) THREADSAFE AS IGdipGraphics
      LOCAL pGraphics AS IGdipGraphics
      pGraphics = CLASS "CGdipGraphics"
      IF ISNOTHING(pGraphics) THEN EXIT METHOD
      m_hStatus = pGraphics.FromHWND(hwnd, icm)
      METHOD = pGraphics
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD GraphicsFromImage (BYVAL pImage AS IGdipImage) THREADSAFE AS IGdipGraphics
      LOCAL pGraphics AS IGdipGraphics
      pGraphics = CLASS "CGdipGraphics"
      IF ISNOTHING(pGraphics) THEN EXIT METHOD
      m_hStatus = pGraphics.FromImage(pImage)
      METHOD = pGraphics
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new Pen object.
   ' =====================================================================================
   METHOD Pen (BYVAL colour AS DWORD, OPTIONAL BYVAL vWidth AS VARIANT) THREADSAFE AS IGdipPen
      LOCAL pPen AS IGdipPen
      pPen = CLASS "CGdipPen"
      IF ISNOTHING(pPen) THEN EXIT METHOD
      LOCAL nWidth AS SINGLE
      IF ISMISSING(vWidth) THEN nWidth = 1.0! ELSE nWidth = VARIANT#(vWidth)
      m_hStatus = pPen.FromColor(colour, nWidth)
      METHOD = pPen
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD PenFromColor (BYVAL colour AS DWORD, OPTIONAL BYVAL vWidth AS VARIANT) THREADSAFE AS IGdipPen
      LOCAL pPen AS IGdipPen
      pPen = CLASS "CGdipPen"
      IF ISNOTHING(pPen) THEN EXIT METHOD
      LOCAL nWidth AS SINGLE
      IF ISMISSING(vWidth) THEN nWidth = 1.0! ELSE nWidth = VARIANT#(vWidth)
      m_hStatus = pPen.FromColor(colour, nWidth)
      METHOD = pPen
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD PenFromBrush (BYVAL pBrush AS IGdipBrush, OPTIONAL BYVAL vWidth AS VARIANT) THREADSAFE AS IGdipPen
      LOCAL pPen AS IGdipPen
      pPen = CLASS "CGdipPen"
      IF ISNOTHING(pPen) THEN EXIT METHOD
      LOCAL nWidth AS SINGLE
      IF ISMISSING(vWidth) THEN nWidth = 1.0! ELSE nWidth = VARIANT#(vWidth)
      m_hStatus = pPen.FromBrush(pBrush, nWidth)
      METHOD = pPen
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new Image object.
   ' =====================================================================================
   METHOD Image (BYREF wszFileName AS WSTRINGZ, OPTIONAL BYVAL useIcm AS LONG) THREADSAFE AS IGdipImage
      LOCAL pImage AS IGdipImage
      pImage = CLASS "CGdipImage"
      IF ISNOTHING(pImage) THEN EXIT METHOD
      m_hStatus = pImage.ImageFromFile(wszFileName, useIcm)
      METHOD = pImage
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD ImageFromFile (BYREF wszFileName AS WSTRINGZ, OPTIONAL BYVAL useIcm AS LONG) THREADSAFE AS IGdipImage
      LOCAL pImage AS IGdipImage
      pImage = CLASS "CGdipImage"
      IF ISNOTHING(pImage) THEN EXIT METHOD
      m_hStatus = pImage.ImageFromFile(wszFileName, useIcm)
      METHOD = pImage
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD ImageFromStream (BYVAL pStream AS IStream, OPTIONAL BYVAL useIcm AS LONG) THREADSAFE AS IGdipImage
      LOCAL pImage AS IGdipImage
      pImage = CLASS "CGdipImage"
      IF ISNOTHING(pImage) THEN EXIT METHOD
      m_hStatus = pImage.ImageFromStream(pStream, useIcm)
      METHOD = pImage
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new Bitmap object.
   ' =====================================================================================
   METHOD Bitmap (BYREF wszFileName AS WSTRINGZ, OPTIONAL BYVAL useIcm AS LONG) THREADSAFE AS IGdipBitmap
      LOCAL pBitmap AS IGdipBitmap
      pBitmap = CLASS "CGdipImage"
      IF ISNOTHING(pBitmap) THEN EXIT METHOD
      m_hStatus = pBitmap.BitmapFromFile(wszFileName, useIcm)
      METHOD = pBitmap
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD BitmapFromFile (BYREF wszFileName AS WSTRINGZ, OPTIONAL BYVAL useIcm AS LONG) THREADSAFE AS IGdipBitmap
      LOCAL pBitmap AS IGdipBitmap
      pBitmap = CLASS "CGdipImage"
      IF ISNOTHING(pBitmap) THEN EXIT METHOD
      m_hStatus = pBitmap.BitmapFromFile(wszFileName, useIcm)
      METHOD = pBitmap
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD BitmapFromStream (BYVAL pStream AS IStream, OPTIONAL BYVAL useIcm AS LONG) THREADSAFE AS IGdipBitmap
      LOCAL pBitmap AS IGdipBitmap
      pBitmap = CLASS "CGdipImage"
      IF ISNOTHING(pBitmap) THEN EXIT METHOD
      m_hStatus = pBitmap.BitmapFromStream(pStream, useIcm)
      METHOD = pBitmap
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD BitmapFromScan0 (BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, BYVAL stride AS LONG, BYVAL pxFormat AS LONG, OPTIONAL BYREF scan0 AS BYTE) THREADSAFE AS IGdipBitmap
      LOCAL pBitmap AS IGdipBitmap
      pBitmap = CLASS "CGdipImage"
      IF ISNOTHING(pBitmap) THEN EXIT METHOD
      m_hStatus = pBitmap.BitmapFromScan0(nWidth, nHeight, stride, pxFormat, scan0)
      METHOD = pBitmap
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD BitmapFromScan (BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, OPTIONAL BYVAL vPxFormat AS VARIANT) THREADSAFE AS IGdipBitmap
      LOCAL pBitmap AS IGdipBitmap
      pBitmap = CLASS "CGdipImage"
      IF ISNOTHING(pBitmap) THEN EXIT METHOD
      LOCAL pxFormat AS LONG
      IF ISMISSING(vPxFormat) THEN pxFormat = %PixelFormat32bppARGB ELSE pxFormat = VARIANT#(vPxFormat)
      m_hStatus = pBitmap.BitmapFromScan(nWidth, nHeight, pxFormat)
      METHOD = pBitmap
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD BitmapFromGraphics (BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, BYVAL pTarget AS IGdipGraphics) THREADSAFE AS IGdipBitmap
      LOCAL pBitmap AS IGdipBitmap
      pBitmap = CLASS "CGdipImage"
      IF ISNOTHING(pBitmap) THEN EXIT METHOD
      m_hStatus = pBitmap.BitmapFromGraphics(nWidth, nHeight, pTarget)
      METHOD = pBitmap
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD BitmapFromIDirectDrawSurface7 (BYVAL surface AS IDirectDrawSurface7) THREADSAFE AS IGdipBitmap
      LOCAL pBitmap AS IGdipBitmap
      pBitmap = CLASS "CGdipImage"
      IF ISNOTHING(pBitmap) THEN EXIT METHOD
      m_hStatus = pBitmap.BitmapFromIDirectDrawSurface7(surface)
      METHOD = pBitmap
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD BitmapFromBITMAPINFO (BYREF gdiBitmapInfo AS BITMAPINFO, BYVAL gdiBitmapData AS DWORD) THREADSAFE AS IGdipBitmap
      LOCAL pBitmap AS IGdipBitmap
      pBitmap = CLASS "CGdipImage"
      IF ISNOTHING(pBitmap) THEN EXIT METHOD
      m_hStatus = pBitmap.BitmapFromBITMAPINFO(gdiBitmapInfo, gdiBitmapData)
      METHOD = pBitmap
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD BitmapFromHBITMAP (BYVAL hbm AS DWORD, BYVAL hpal AS DWORD) THREADSAFE AS IGdipBitmap
      LOCAL pBitmap AS IGdipBitmap
      pBitmap = CLASS "CGdipImage"
      IF ISNOTHING(pBitmap) THEN EXIT METHOD
      m_hStatus = pBitmap.BitmapFromHBITMAP(hbm, hpal)
      METHOD = pBitmap
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD BitmapFromHICON (BYVAL hicon AS DWORD) THREADSAFE AS IGdipBitmap
      LOCAL pBitmap AS IGdipBitmap
      pBitmap = CLASS "CGdipImage"
      IF ISNOTHING(pBitmap) THEN EXIT METHOD
      m_hStatus = pBitmap.BitmapFromHICON(hicon)
      METHOD = pBitmap
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD BitmapFromResource (BYVAL hInstance AS DWORD, BYREF bitmapName AS WSTRINGZ) THREADSAFE AS IGdipBitmap
      LOCAL pBitmap AS IGdipBitmap
      pBitmap = CLASS "CGdipImage"
      IF ISNOTHING(pBitmap) THEN EXIT METHOD
      m_hStatus = pBitmap.BitmapFromResource(hInstance, bitmapName)
      METHOD = pBitmap
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new SolidBrush object.
   ' =====================================================================================
   METHOD SolidBrush (BYVAL colour AS DWORD) THREADSAFE AS IGdipSolidBrush
      LOCAL pSolidBrush AS IGdipSolidBrush
      pSolidBrush = CLASS "CGdipBrush"
      IF ISNOTHING(pSolidBrush) THEN EXIT METHOD
      m_hStatus = pSolidBrush.SolidBrush(colour)
      METHOD = pSolidBrush
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD SolidBrushARGB (BYVAL a AS BYTE, BYVAL r AS BYTE, BYVAL g AS BYTE, BYVAL b AS BYTE) THREADSAFE AS IGdipSolidBrush
      LOCAL pSolidBrush AS IGdipSolidBrush
      pSolidBrush = CLASS "CGdipBrush"
      IF ISNOTHING(pSolidBrush) THEN EXIT METHOD
      LOCAL colour AS DWORD
      colour = ME.Color(a, r, g, b)
      m_hStatus = pSolidBrush.SolidBrush(colour)
      METHOD = pSolidBrush
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new TextureBrush object.
   ' =====================================================================================
   METHOD TextureBrush (BYVAL pImage AS IGdipImage, OPTIONAL BYVAL wrapMode AS LONG) THREADSAFE AS IGdipTextureBrush
      LOCAL pTextureBrush AS IGdipTextureBrush
      pTextureBrush = CLASS "CGdipBrush"
      IF ISNOTHING(pTextureBrush) THEN EXIT METHOD
      m_hStatus = pTextureBrush.TextureBrush(pImage, wrapMode)
      METHOD = pTextureBrush
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD TextureBrushIA (BYVAL pImage AS IGdipImage, BYREF dstRect AS RectF, OPTIONAL BYVAL pImageAttributes AS IGdipImageAttributes) THREADSAFE AS IGdipTextureBrush
      LOCAL pTextureBrush AS IGdipTextureBrush
      pTextureBrush = CLASS "CGdipBrush"
      IF ISNOTHING(pTextureBrush) THEN EXIT METHOD
      m_hStatus = pTextureBrush.TextureBrushIA(pImage, dstRect, pImageAttributes)
      METHOD = pTextureBrush
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD TextureBrushRect (BYVAL pImage AS IGdipImage, BYVAL wrapMode AS LONG, BYREF dstRect AS RECT) THREADSAFE AS IGdipTextureBrush
      LOCAL pTextureBrush AS IGdipTextureBrush
      pTextureBrush = CLASS "CGdipBrush"
      IF ISNOTHING(pTextureBrush) THEN EXIT METHOD
      m_hStatus = pTextureBrush.TextureBrushRect(pImage, wrapMode, dstRect)
      METHOD = pTextureBrush
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD TextureBrush2 (BYVAL pImage AS IGdipImage, BYVAL wrapMode AS LONG, BYVAL dstX AS SINGLE, BYVAL dstY AS SINGLE, BYVAL dstWidth AS SINGLE, BYVAL dstHeight AS SINGLE) THREADSAFE AS IGdipTextureBrush
      LOCAL pTextureBrush AS IGdipTextureBrush
      pTextureBrush = CLASS "CGdipBrush"
      IF ISNOTHING(pTextureBrush) THEN EXIT METHOD
      m_hStatus = pTextureBrush.TextureBrush2(pImage, wrapMode, dstX, dstY, dstWidth, dstHeight)
      METHOD = pTextureBrush
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new LinearGradientBrush object.
   ' =====================================================================================
   METHOD LinearGradientBrush (BYREF point1 AS PointF, BYREF point2 AS PointF, BYVAL color1 AS DWORD, BYVAL color2 AS DWORD) THREADSAFE AS IGdipLinearGradientBrush
      LOCAL pLinearGradientBrush AS IGdipLinearGradientBrush
      pLinearGradientBrush = CLASS "CGdipBrush"
      IF ISNOTHING(pLinearGradientBrush) THEN EXIT METHOD
      m_hStatus = pLinearGradientBrush.LinearGradientBrush(point1, point2, color1, color2)
      METHOD = pLinearGradientBrush
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD LinearGradientBrushFromRect (BYREF rc AS RectF, BYVAL color1 AS DWORD, BYVAL color2 AS DWORD, BYVAL nMode AS LONG) THREADSAFE AS IGdipLinearGradientBrush
      LOCAL pLinearGradientBrush AS IGdipLinearGradientBrush
      pLinearGradientBrush = CLASS "CGdipBrush"
      IF ISNOTHING(pLinearGradientBrush) THEN EXIT METHOD
      m_hStatus = pLinearGradientBrush.LinearGradientBrushFromRect(rc, color1, color2, nMode)
      METHOD = pLinearGradientBrush
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD LinearBrushFromRectWithAngle (BYREF rc AS RectF, BYVAL color1 AS DWORD, BYVAL color2 AS DWORD, BYVAL angle AS SINGLE, OPTIONAL BYVAL isAngleScalable AS LONG) THREADSAFE AS IGdipLinearGradientBrush
      LOCAL pLinearGradientBrush AS IGdipLinearGradientBrush
      pLinearGradientBrush = CLASS "CGdipBrush"
      IF ISNOTHING(pLinearGradientBrush) THEN EXIT METHOD
      m_hStatus = pLinearGradientBrush.LinearBrushFromRectWithAngle(rc, color1, color2, angle, isAngleScalable)
      METHOD = pLinearGradientBrush
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new PathGradientBrush object.
   ' =====================================================================================
   METHOD PathGradientBrush (BYREF pts AS PointF, BYVAL nCount AS LONG, OPTIONAL BYVAL wrapMode AS LONG) THREADSAFE AS IGdipPathGradientBrush
      LOCAL pPathGradientBrush AS IGdipPathGradientBrush
      pPathGradientBrush = CLASS "CGdipBrush"
      IF ISNOTHING(pPathGradientBrush) THEN EXIT METHOD
      m_hStatus = pPathGradientBrush.PathGradientBrush(pts, nCount, wrapMode)
      METHOD = pPathGradientBrush
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD PathGradientBrushFromPath (BYVAL pPath AS IGdipGraphicsPath) THREADSAFE AS IGdipPathGradientBrush
      LOCAL pPathGradientBrush AS IGdipPathGradientBrush
      pPathGradientBrush = CLASS "CGdipBrush"
      IF ISNOTHING(pPathGradientBrush) THEN EXIT METHOD
      m_hStatus = pPathGradientBrush.PathGradientBrushFromPath(pPath)
      METHOD = pPathGradientBrush
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new HatchBrush object.
   ' =====================================================================================
   METHOD HatchBrush (BYVAL hatchStyle AS LONG, BYVAL foreColor AS DWORD, OPTIONAL BYVAL backColor AS DWORD) THREADSAFE AS IGdipHatchBrush
      LOCAL pHatchBrush AS IGdipHatchBrush
      pHatchBrush = CLASS "CGdipBrush"
      IF ISNOTHING(pHatchBrush) THEN EXIT METHOD
      m_hStatus = pHatchBrush.HatchBrush(hatchStyle, foreColor, backColor)
      METHOD = pHatchBrush
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a cached bitmap object.
   ' =====================================================================================
   METHOD CachedBitmap (BYVAL pBitmap AS IGdipBitmap, BYVAL pGraphics AS IGdipGraphics) THREADSAFE AS IGdipCachedBitmap
      LOCAL pCachedBitmap AS IGdipCachedBitmap
      pCachedBitmap = CLASS "CGdipCachedBitmap"
      IF ISNOTHING(pCachedBitmap) THEN EXIT METHOD
      m_hStatus = pCachedBitmap.CachedBitmap(pBitmap, pGraphics)
      METHOD = pCachedBitmap
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a graphics path object.
   ' =====================================================================================
   METHOD GraphicsPath (OPTIONAL BYVAL fillMode AS LONG) THREADSAFE AS IGdipGraphicsPath
      LOCAL pGraphicsPath AS IGdipGraphicsPath
      pGraphicsPath = CLASS "CGdipGraphicsPath"
      IF ISNOTHING(pGraphicsPath) THEN EXIT METHOD
      m_hStatus = pGraphicsPath.GraphicsPath(fillMode)
      METHOD = pGraphicsPath
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD GraphicsPathPoint (BYREF pts AS POINT, BYREF types AS BYTE, BYVAL nCount AS LONG, BYVAL fillMode AS LONG) THREADSAFE AS IGdipGraphicsPath
      LOCAL pGraphicsPath AS IGdipGraphicsPath
      pGraphicsPath = CLASS "CGdipGraphicsPath"
      IF ISNOTHING(pGraphicsPath) THEN EXIT METHOD
      m_hStatus = pGraphicsPath.GraphicsPathPoint(pts, types, nCount, fillMode)
      METHOD = pGraphicsPath
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new GraphicsPathIterator object and associates it with a GraphicsPath object.
   ' =====================================================================================
   METHOD GraphicsPathIterator (BYVAL pPath AS IGdipGraphicsPath) THREADSAFE AS IGdipGraphicsPathIterator
      LOCAL pGraphicsPathIterator AS IGdipGraphicsPathIterator
      pGraphicsPathIterator = CLASS "CGdipGraphicsPathIterator"
      IF ISNOTHING(pGraphicsPathIterator) THEN EXIT METHOD
      m_hStatus = pGraphicsPathIterator.GraphicsPathIterator(pPath)
      METHOD = pGraphicsPathIterator
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a image attributes object.
   ' =====================================================================================
   METHOD ImageAttributes () THREADSAFE AS IGdipImageAttributes
      LOCAL pImageAttributes AS IGdipImageAttributes
      pImageAttributes = CLASS "CGdipImageAttributes"
      IF ISNOTHING(pImageAttributes) THEN EXIT METHOD
      m_hStatus = pImageAttributes.ImageAttributes
      METHOD = pImageAttributes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a string format object.
   ' =====================================================================================
   METHOD StringFormat (OPTIONAL BYVAL formatFlags AS LONG, BYVAL language AS WORD) THREADSAFE AS IGdipStringFormat
      LOCAL pStringFormat AS IGdipStringFormat
      pStringFormat = CLASS "CGdipStringFormat"
      IF ISNOTHING(pStringFormat) THEN EXIT METHOD
      m_hStatus = pStringFormat.StringFormat(formatFlags, language)
      METHOD = pStringFormat
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD StringFormat2 (BYVAL pFormat AS IGdipStringFormat) THREADSAFE AS IGdipStringFormat
      LOCAL pStringFormat AS IGdipStringFormat
      pStringFormat = CLASS "CGdipStringFormat"
      IF ISNOTHING(pStringFormat) THEN EXIT METHOD
      m_hStatus = pStringFormat.StringFormat2(pFormat)
      METHOD = pStringFormat
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a matrix object.
   ' =====================================================================================
   METHOD Matrix () THREADSAFE AS IGdipMatrix
      LOCAL pMatrix AS IGdipMatrix
      pMatrix = CLASS "CGdipMatrix"
      IF ISNOTHING(pMatrix) THEN EXIT METHOD
      m_hStatus = pMatrix.Matrix
      METHOD = pMatrix
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD Matrix2 (BYVAL m11 AS SINGLE, BYVAL m12 AS SINGLE, BYVAL m21 AS SINGLE, BYVAL m22 AS SINGLE, BYVAL dx AS SINGLE, BYVAL dy AS SINGLE) THREADSAFE AS IGdipMatrix
      LOCAL pMatrix AS IGdipMatrix
      pMatrix = CLASS "CGdipMatrix"
      IF ISNOTHING(pMatrix) THEN EXIT METHOD
      m_hStatus = pMatrix.Matrix2(m11, m12, m21, m22, dx, dy)
      METHOD = pMatrix
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD Matrix3 (BYREF rc AS RectF, BYREF dstplg AS PointF) THREADSAFE AS IGdipMatrix
      LOCAL pMatrix AS IGdipMatrix
      pMatrix = CLASS "CGdipMatrix"
      IF ISNOTHING(pMatrix) THEN EXIT METHOD
      m_hStatus = pMatrix.Matrix3(rc, dstplg)
      METHOD = pMatrix
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD Matrix3I (BYREF rc AS RECT, BYREF dstplg AS POINT) THREADSAFE AS IGdipMatrix
      LOCAL pMatrix AS IGdipMatrix
      pMatrix = CLASS "CGdipMatrix"
      IF ISNOTHING(pMatrix) THEN EXIT METHOD
      m_hStatus = pMatrix.Matrix3I(rc, dstplg)
      METHOD = pMatrix
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new CustomLineCap object.
   ' =====================================================================================
   METHOD CustomLineCap (BYVAL pFillPath AS IGdipGraphicsPath, BYVAL pStrokePath AS IGdipGraphicsPath, OPTIONAL BYVAL baseCap AS LONG, BYVAL baseInset AS SINGLE) THREADSAFE AS IGdipCustomLineCap
      LOCAL pCustomLineCap AS IGdipCustomLineCap
      pCustomLineCap = CLASS "CGdipCustomLineCap"
      IF ISNOTHING(pCustomLineCap) THEN EXIT METHOD
      m_hStatus = pCustomLineCap.CustomLineCap(pFillPath, pStrokePath, baseCap, baseinset)
      METHOD = pCustomLineCap
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD AdjustableArrowCap (BYVAL nHeight AS SINGLE, BYVAL nWidth AS SINGLE, OPTIONAL BYVAL vIsFilled AS VARIANT) THREADSAFE AS IGdipAdjustableArrowCap
      LOCAL pAdjustableArrowCap AS IGdipAdjustableArrowCap
      pAdjustableArrowCap = CLASS "CGdipCustomLineCap"
      IF ISNOTHING(pAdjustableArrowCap) THEN EXIT METHOD
      LOCAL bIsFilled AS LONG
      IF ISMISSING(vIsFilled) THEN bIsFilled = %TRUE ELSE bIsFilled = VARIANT#(vIsFilled)
      m_hStatus = pAdjustableArrowCap.AdjustableArrowCap(nHeight, nWidth, bisFilled)
      METHOD = pAdjustableArrowCap
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new Font object.
   ' Default style is FontStyleRegular. Default unit is UnitPoint.
   ' =====================================================================================
   METHOD Font (BYREF familyName AS WSTRINGZ, BYVAL emSize AS SINGLE, OPTIONAL BYVAL nStyle AS LONG, BYVAL vUnit AS VARIANT) THREADSAFE AS IGdipFont
      LOCAL pFont AS IGdipFont
      pFont = CLASS "CGdipFont"
      IF ISNOTHING(pFont) THEN EXIT METHOD
      LOCAL unit AS LONG
      IF ISMISSING(vUnit) THEN unit = %UnitPoint ELSE unit = VARIANT#(vUnit)
      m_hStatus = pFont.FromFontFamilyName(familyName, emSize, nStyle, unit)
      METHOD = pFont
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD FontFromDC (BYVAL hdc AS DWORD) THREADSAFE AS IGdipFont
      LOCAL pFont AS IGdipFont
      pFont = CLASS "CGdipFont"
      IF ISNOTHING(pFont) THEN EXIT METHOD
      m_hStatus = pFont.FromDC(hdc)
      METHOD = pFont
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD FontFromHFontA (BYVAL hdc AS DWORD, BYVAL hFont AS DWORD) THREADSAFE AS IGdipFont
      LOCAL pFont AS IGdipFont
      pFont = CLASS "CGdipFont"
      IF ISNOTHING(pFont) THEN EXIT METHOD
      m_hStatus = pFont.FromHFontA(hdc, hFont)
      METHOD = pFont
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD FontFromHFontW (BYVAL hdc AS DWORD, BYVAL hFont AS DWORD) THREADSAFE AS IGdipFont
      LOCAL pFont AS IGdipFont
      pFont = CLASS "CGdipFont"
      IF ISNOTHING(pFont) THEN EXIT METHOD
      m_hStatus = pFont.FromHFontW(hdc, hFont)
      METHOD = pFont
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD FontFromLogFontA (BYVAL hdc AS DWORD, BYREF lfA AS LOGFONTA) THREADSAFE AS IGdipFont
      LOCAL pFont AS IGdipFont
      pFont = CLASS "CGdipFont"
      IF ISNOTHING(pFont) THEN EXIT METHOD
      m_hStatus = pFont.FromLogFontA(hdc, lfA)
      METHOD = pFont
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD FontFromLogFontW (BYVAL hdc AS DWORD, BYREF lfW AS LOGFONTW) THREADSAFE AS IGdipFont
      LOCAL pFont AS IGdipFont
      pFont = CLASS "CGdipFont"
      IF ISNOTHING(pFont) THEN EXIT METHOD
      m_hStatus = pFont.FromLogFontW(hdc, lfW)
      METHOD = pFont
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD FontFromFontFamily (BYVAL pFamily AS IGdipFontFamily, BYVAL emSize AS SINGLE, OPTIONAL BYVAL nStyle AS LONG, BYVAL vUnit AS VARIANT) THREADSAFE AS IGdipFont
      LOCAL pFont AS IGdipFont
      pFont = CLASS "CGdipFont"
      IF ISNOTHING(pFont) THEN EXIT METHOD
      LOCAL unit AS LONG
      IF ISMISSING(vUnit) THEN unit = %UnitPoint ELSE unit = VARIANT#(vUnit)
      m_hStatus = pFont.FromFontFamily(pFamily, emSize, nStyle, unit)
      METHOD = pFont
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD FontFromFontFamilyName (BYREF familyName AS WSTRINGZ, BYVAL emSize AS SINGLE, OPTIONAL BYVAL nStyle AS LONG, BYVAL vUnit AS VARIANT, BYVAL pFontCollection AS IGdipFontCollection) THREADSAFE AS IGdipFont
      LOCAL pFont AS IGdipFont
      pFont = CLASS "CGdipFont"
      IF ISNOTHING(pFont) THEN EXIT METHOD
      LOCAL unit AS LONG
      IF ISMISSING(vUnit) THEN unit = %UnitPoint ELSE unit = VARIANT#(vUnit)
      m_hStatus = pFont.FromFontFamilyName(familyName, emSize, nStyle, unit, pFontCollection)
      METHOD = pFont
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new FontFamily object.
   ' =====================================================================================
   METHOD FontFamily (BYREF wszName AS WSTRINGZ, OPTIONAL BYVAL pFontCollection AS IGdipFontCollection) THREADSAFE AS IGdipFontFamily
      LOCAL pFontFamily AS IGdipFontFamily
      pFontFamily = CLASS "CGdipFontFamily"
      IF ISNOTHING(pFontFamily) THEN EXIT METHOD
      m_hStatus = pFontFamily.FromName(wszName, pFontCollection)
      METHOD = pFontFamily
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new FontCollection object.
   ' =====================================================================================
   METHOD PrivateFontCollection () THREADSAFE AS IGdipPrivateFontCollection
      LOCAL pPrivateFontCollection AS IGdipPrivateFontCollection
      pPrivateFontCollection = CLASS "CGdipFontCollection"
      IF ISNOTHING(pPrivateFontCollection) THEN EXIT METHOD
      m_hStatus = pPrivateFontCollection.PrivateFontCollection
      METHOD = pPrivateFontCollection
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD InstalledFontCollection () THREADSAFE AS IGdipInstalledFontCollection
      LOCAL pInstalledFontCollection AS IGdipInstalledFontCollection
      pInstalledFontCollection = CLASS "CGdipFontCollection"
      IF ISNOTHING(pInstalledFontCollection) THEN EXIT METHOD
      m_hStatus = pInstalledFontCollection.InstalledFontCollection
      METHOD = pInstalledFontCollection
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new Metafile object.
   ' =====================================================================================
   METHOD Metafile (BYREF wszFileName AS WSTRINGZ) THREADSAFE AS IGdipMetafile
      LOCAL pMetafile AS IGdipMetafile
      pMetafile = CLASS "CGdipImage"
      IF ISNOTHING(pMetafile) THEN EXIT METHOD
      m_hStatus = pMetafile.MetafileFromFile(wszFileName)
      METHOD = pMetafile
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD MetafileFromWmf (BYVAL hWmf AS DWORD, BYREF wmfPFH AS WmfPlaceableFileHeader, OPTIONAL BYVAL deleteWmf AS LONG) THREADSAFE AS IGdipMetafile
      LOCAL pMetafile AS IGdipMetafile
      pMetafile = CLASS "CGdipImage"
      IF ISNOTHING(pMetafile) THEN EXIT METHOD
      m_hStatus = pMetafile.MetafileFromWmf(hWmf, wmfPFH, deleteWmf)
      METHOD = pMetafile
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD MetafileFromEmf (BYVAL hEmf AS DWORD, OPTIONAL BYVAL deleteEmf AS LONG) THREADSAFE AS IGdipMetafile
      LOCAL pMetafile AS IGdipMetafile
      pMetafile = CLASS "CGdipImage"
      IF ISNOTHING(pMetafile) THEN EXIT METHOD
      m_hStatus = pMetafile.MetafileFromEmf(hEmf, deleteEmf)
      METHOD = pMetafile
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD MetafileFromWmfFile (BYREF wszFileName AS WSTRINGZ, BYREF wmfPFH AS WmfPlaceableFileHeader) THREADSAFE AS IGdipMetafile
      LOCAL pMetafile AS IGdipMetafile
      pMetafile = CLASS "CGdipImage"
      IF ISNOTHING(pMetafile) THEN EXIT METHOD
      m_hStatus = pMetafile.MetafileFromWmfFile(wszFileName, wmfPFH)
      METHOD = pMetafile
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD MetafileFromStream (BYVAL pStream AS IStream) THREADSAFE AS IGdipMetafile
      LOCAL pMetafile AS IGdipMetafile
      pMetafile = CLASS "CGdipImage"
      IF ISNOTHING(pMetafile) THEN EXIT METHOD
      m_hStatus = pMetafile.MetafileFromStream(pStream)
      METHOD = pMetafile
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD RecordMetafile (BYVAL referenceHdc AS DWORD, OPTIONAL BYVAL nType AS LONG, BYREF description AS WSTRINGZ) THREADSAFE AS IGdipMetafile
      LOCAL pMetafile AS IGdipMetafile
      pMetafile = CLASS "CGdipImage"
      IF ISNOTHING(pMetafile) THEN EXIT METHOD
      m_hStatus = pMetafile.RecordMetafile(referenceHdc, nType, description)
      METHOD = pMetafile
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD RecordMetafileRect (BYVAL referenceHdc AS DWORD, BYREF frmRect AS RectF, OPTIONAL BYVAL frameUnit AS LONG, BYVAL nType AS LONG, BYREF description AS WSTRINGZ) THREADSAFE AS IGdipMetafile
      LOCAL pMetafile AS IGdipMetafile
      pMetafile = CLASS "CGdipImage"
      IF ISNOTHING(pMetafile) THEN EXIT METHOD
      m_hStatus = pMetafile.RecordMetafileRect(referenceHdc, frmRect, frameUnit, nType, description)
      METHOD = pMetafile
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD RecordMetafileFileName (BYREF wszFileName AS WSTRINGZ, BYVAL referenceHdc AS DWORD, OPTIONAL BYVAL nType AS LONG, BYREF description AS WSTRINGZ) THREADSAFE AS IGdipMetafile
      LOCAL pMetafile AS IGdipMetafile
      pMetafile = CLASS "CGdipImage"
      IF ISNOTHING(pMetafile) THEN EXIT METHOD
      m_hStatus = pMetafile.RecordMetafileFileName(wszFileName, referenceHdc, nType, description)
      METHOD = pMetafile
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD RecordMetafileFileNameRect (BYREF wszFileName AS WSTRINGZ, BYVAL referenceHdc AS DWORD, BYREF frmRect AS RectF, _
      OPTIONAL BYVAL frameUnit AS LONG, BYVAL nType AS LONG, BYREF description AS WSTRINGZ) THREADSAFE AS IGdipMetafile
      LOCAL pMetafile AS IGdipMetafile
      pMetafile = CLASS "CGdipImage"
      IF ISNOTHING(pMetafile) THEN EXIT METHOD
      m_hStatus = pMetafile.RecordMetafileFileNameRect(wszFileName, referenceHdc, frmRect, frameUnit, nType, description)
      METHOD = pMetafile
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD RecordMetafileStream (BYVAL pStream AS IStream, BYVAL referenceHdc AS DWORD, OPTIONAL BYVAL nType AS LONG, BYREF description AS WSTRINGZ) THREADSAFE AS IGdipMetafile
      LOCAL pMetafile AS IGdipMetafile
      pMetafile = CLASS "CGdipImage"
      IF ISNOTHING(pMetafile) THEN EXIT METHOD
      m_hStatus = pMetafile.RecordMetafileStream(pStream, referenceHdc, nType, description)
      METHOD = pMetafile
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD RecordMetafileStreamRect (BYVAL pStream AS IStream, BYVAL referenceHdc AS DWORD, BYREF frmRect AS RectF, _
      OPTIONAL BYVAL frameUnit AS LONG, BYVAL nType AS LONG, BYREF description AS WSTRINGZ) THREADSAFE AS IGdipMetafile
      LOCAL pMetafile AS IGdipMetafile
      pMetafile = CLASS "CGdipImage"
      IF ISNOTHING(pMetafile) THEN EXIT METHOD
      m_hStatus = pMetafile.RecordMetafileStreamRect(pStream, referenceHdc, frmRect, frameUnit, nType, description)
      METHOD = pMetafile
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a Region object
   ' =====================================================================================
   METHOD Region () THREADSAFE AS IGdipRegion
      LOCAL pRegion AS IGdipRegion
      pRegion = CLASS "CGdipRegion"
      IF ISNOTHING(pRegion) THEN EXIT METHOD
      m_hStatus = pRegion.Region
      METHOD = pRegion
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD RegionRect (BYREF rc AS RectF) THREADSAFE AS IGdipRegion
      LOCAL pRegion AS IGdipRegion
      pRegion = CLASS "CGdipRegion"
      IF ISNOTHING(pRegion) THEN EXIT METHOD
      m_hStatus = pRegion.RegionRect(rc)
      METHOD = pRegion
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD RegionPath (BYVAL pPath AS IGdipGraphicsPath) THREADSAFE AS IGdipRegion
      LOCAL pRegion AS IGdipRegion
      pRegion = CLASS "CGdipRegion"
      IF ISNOTHING(pRegion) THEN EXIT METHOD
      m_hStatus = pRegion.RegionPath(pPath)
      METHOD = pRegion
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD RegionRgnData (BYREF regionData AS BYTE, BYVAL nSize AS LONG) THREADSAFE AS IGdipRegion
      LOCAL pRegion AS IGdipRegion
      pRegion = CLASS "CGdipRegion"
      IF ISNOTHING(pRegion) THEN EXIT METHOD
      m_hStatus = pRegion.RegionRgnData(regionData, nSize)
      METHOD = pRegion
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD RegionHrgn (BYVAL hRgn AS DWORD) THREADSAFE AS IGdipRegion
      LOCAL pRegion AS IGdipRegion
      pRegion = CLASS "CGdipRegion"
      IF ISNOTHING(pRegion) THEN EXIT METHOD
      m_hStatus = pRegion.RegionHrgn(hRgn)
      METHOD = pRegion
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a GDI+ Region object from a GDI region.
   ' =====================================================================================
   METHOD RegionFromHRGN (BYVAL hRgn AS DWORD) THREADSAFE AS IGdipRegion
      LOCAL pNewRegion AS IGdipRegion
      LOCAL pNewRegionPtr AS DWORD
      m_hStatus = GdipCreateRegionHrgn(hRgn, pNewRegionPtr)
      pNewRegion = CLASS "CGdipRegion"
      pNewRegion.Ptr = pNewRegionPtr
      METHOD = pNewRegion
   END METHOD
   ' =====================================================================================

#IF (%GDIPVER >= &H0110)

   ' =====================================================================================
   ' Creates new Effect objects.
   ' =====================================================================================
   METHOD Effect () THREADSAFE AS IGdipEffect
      LOCAL pEffect AS IGdipEffect
      pEffect = CLASS "CGdipEffect"
      IF ISNOTHING(pEffect) THEN EXIT METHOD
      METHOD = pEffect
      m_hStatus = 0
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD Blur () THREADSAFE AS IGdipBlur
      LOCAL pBlur AS IGdipBlur
      pBlur = CLASS "CGdipEffect"
      IF ISNOTHING(pBlur) THEN EXIT METHOD
      m_hStatus = pBlur.Blur
      METHOD = pBlur
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD Sharpen () THREADSAFE AS IGdipSharpen
      LOCAL pSharpen AS IGdipSharpen
      pSharpen = CLASS "CGdipEffect"
      IF ISNOTHING(pSharpen) THEN EXIT METHOD
      m_hStatus = pSharpen.Sharpen
      METHOD = pSharpen
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD RedEyeCorrection () THREADSAFE AS IGdipRedEyeCorrection
      LOCAL pRedEyeCorrection AS IGdipRedEyeCorrection
      pRedEyeCorrection = CLASS "CGdipEffect"
      IF ISNOTHING(pRedEyeCorrection) THEN EXIT METHOD
      m_hStatus = pRedEyeCorrection.RedEyeCorrection
      METHOD = pRedEyeCorrection
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD BrightnessContrast () THREADSAFE AS IGdipBrightnessContrast
      LOCAL pBrightnessContrast AS IGdipBrightnessContrast
      pBrightnessContrast = CLASS "CGdipEffect"
      IF ISNOTHING(pBrightnessContrast) THEN EXIT METHOD
      m_hStatus = pBrightnessContrast.BrightnessContrast
      METHOD = pBrightnessContrast
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD HueSaturationLightness () THREADSAFE AS IGdipHueSaturationLightness
      LOCAL pHueSaturationLightness AS IGdipHueSaturationLightness
      pHueSaturationLightness = CLASS "CGdipEffect"
      IF ISNOTHING(pHueSaturationLightness) THEN EXIT METHOD
      m_hStatus = pHueSaturationLightness.HueSaturationLightness
      METHOD = pHueSaturationLightness
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD Levels () THREADSAFE AS IGdipLevels
      LOCAL pLevels AS IGdipLevels
      pLevels = CLASS "CGdipEffect"
      IF ISNOTHING(pLevels) THEN EXIT METHOD
      m_hStatus = pLevels.Levels
      METHOD = pLevels
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD Tint () THREADSAFE AS IGdipTint
      LOCAL pTint AS IGdipTint
      pTint = CLASS "CGdipEffect"
      IF ISNOTHING(pTint) THEN EXIT METHOD
      m_hStatus = pTint.Tint
      METHOD = pTint
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD ColorBalance () THREADSAFE AS IGdipColorBalance
      LOCAL pColorBalance AS IGdipColorBalance
      pColorBalance = CLASS "CGdipEffect"
      IF ISNOTHING(pColorBalance) THEN EXIT METHOD
      m_hStatus = pColorBalance.ColorBalance
      METHOD = pColorBalance
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD ColorMatrixEffect () THREADSAFE AS IGdipColorMatrixEffect
      LOCAL pColorMatrixEffect AS IGdipColorMatrixEffect
      pColorMatrixEffect = CLASS "CGdipEffect"
      IF ISNOTHING(pColorMatrixEffect) THEN EXIT METHOD
      m_hStatus = pColorMatrixEffect.ColorMatrixEffect
      METHOD = pColorMatrixEffect
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD ColorLUT () THREADSAFE AS IGdipColorLUT
      LOCAL pColorLUT AS IGdipColorLUT
      pColorLUT = CLASS "CGdipEffect"
      IF ISNOTHING(pColorLUT) THEN EXIT METHOD
      m_hStatus = pColorLUT.ColorLUT
      METHOD = pColorLUT
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD ColorCurve () THREADSAFE AS IGdipColorCurve
      LOCAL pColorCurve AS IGdipColorCurve
      pColorCurve = CLASS "CGdipEffect"
      IF ISNOTHING(pColorCurve) THEN EXIT METHOD
      m_hStatus = pColorCurve.ColorCurve
      METHOD = pColorCurve
   END METHOD
   ' =====================================================================================

#ENDIF   ' //(GDIPVER >= 0x0110)

   ' =====================================================================================
   ' Returns the description of a GdiPlus status code.
   ' =====================================================================================
   METHOD StatusString (BYVAL nStatus AS LONG) AS WSTRING

      METHOD = "Unknown"

      SELECT CASE AS LONG nStatus
         CASE %StatusOk                        : METHOD = "Ok"
         CASE %StatusGenericError              : METHOD = "Generic error"
         CASE %StatusInvalidParameter          : METHOD = "Invalid parameter"
         CASE %StatusOutOfMemory               : METHOD = "Out of memory"
         CASE %StatusObjectBusy                : METHOD = "Object busy"
         CASE %StatusInsufficientBuffer        : METHOD = "Insufficient buffer"
         CASE %StatusNotImplemented            : METHOD = "Not implemented"
         CASE %StatusWin32Error                : METHOD = "Win 32 error"
         CASE %StatusWrongState                : METHOD = "Wrong state"
         CASE %StatusAborted                   : METHOD = "Aborted"
         CASE %StatusFileNotFound              : METHOD = "File not found"
         CASE %StatusValueOverflow             : METHOD = "Value overflow"
         CASE %StatusAccessDenied              : METHOD = "Access denied"
         CASE %StatusUnknownImageFormat        : METHOD = "Unknown image format"
         CASE %StatusFontFamilyNotFound        : METHOD = "Font family not found"
         CASE %StatusFontStyleNotFound         : METHOD = "Font style not found"
         CASE %StatusNotTrueTypeFont           : METHOD = "Not TrueType font"
         CASE %StatusUnsupportedGdiplusVersion : METHOD = "Unsupported GdiPlus version"
         CASE %StatusGdiplusNotInitialized     : METHOD = "GdiPlus not initialized"
         CASE %StatusPropertyNotFound          : METHOD = "Property not found"
         CASE %StatusPropertyNotSupported      : METHOD = "Property not supported"
      #IF (%GDIPVER >= &H0110)
         CASE %StatusProfileNotFound           : METHOD = "Profile not found"
      #ENDIF   ' //(%GDIPVER >= &H0110)
      END SELECT

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Shows the specified image in the specified window.
   ' * hWnd = [in] Handle of the window.
   ' * wszFileName = Path of the file.
   ' =====================================================================================
   METHOD ShowImageFromFile (BYVAL hWnd AS DWORD, BYREF wszFileName AS WSTRINGZ) THREADSAFE

      LOCAL hDC AS DWORD
      LOCAL pImage AS DWORD
      LOCAL pGraphics AS DWORD
      LOCAL nWidth AS DWORD
      LOCAL nHeight AS DWORD

      IF IsWindow(hWnd) = 0 THEN m_hStatus = %StatusInvalidParameter : EXIT METHOD
      IF LEN(wszFileName) = 0 THEN m_hStatus = %StatusInvalidParameter : EXIT METHOD
      hDC = GetDC(hWnd)
      m_hStatus = GdipLoadImageFromFile(wszFileName, pImage)
      IF m_hStatus <> %S_OK THEN EXIT METHOD
      IF pImage THEN
         m_hStatus = GdipGetImageWidth(pImage, nWidth)
         m_hStatus = GdipGetImageHeight(pImage, nHeight)
         m_hStatus = GdipCreateFromHDC(hDC, pGraphics)
         IF pGraphics THEN m_hStatus = GdipDrawImageRectI(pGraphics, pImage, 0, 0, nWidth, nHeight)
         m_hStatus = GdipDisposeImage(pImage)
         IF pGraphics THEN m_hStatus = GdipDeleteGraphics(pGraphics)
      END IF
      ReleaseDC hWnd, hDC

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the size of the image.
   ' Parameters:
   ' * wszFileName = [in] Filename path.
   ' * nWidth      = [out] Width, in pixels, of the image.
   ' * nHeight     = [out] Height, in pixels, of the image.
   ' =====================================================================================
   METHOD GetImageSizeFromFile (BYREF wszFileName AS WSTRINGZ, BYREF nWidth AS DWORD, BYREF nHeight AS DWORD) THREADSAFE

      LOCAL pImage AS DWORD

      IF LEN(wszFileName) = 0 THEN m_hStatus = %StatusInvalidParameter : EXIT METHOD
      m_hStatus = GdipLoadImageFromFile(wszFileName, pImage)
      IF m_hStatus <> %StatusOk THEN EXIT METHOD
      IF pImage THEN
         m_hStatus = GdipGetImageWidth(pImage, nWidth)
         m_hStatus = GdipGetImageHeight(pImage, nHeight)
         m_hStatus = GdipDisposeImage(pImage)
      END IF

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Shows the specified image in the specified window at the specified coordinates.
   ' * hWnd = [in] Handle of the window.
   ' * wszFileName = Path of the file.
   ' * x, y = Vertical and horizontal coordinates.
   ' =====================================================================================
   METHOD ShowImageFromFileXY (BYVAL hWnd AS DWORD, BYREF wszFileName AS WSTRINGZ, BYVAL x AS LONG, BYVAL y AS LONG, OPTIONAL BYVAL nWidth AS LONG, OPTIONAL BYVAL nHeight AS LONG) THREADSAFE

      LOCAL hDC AS DWORD
      LOCAL pImage AS DWORD
      LOCAL pGraphics AS DWORD

      IF IsWindow(hWnd) = 0 THEN m_hStatus = %StatusInvalidParameter : EXIT METHOD
      IF LEN(wszFileName) = 0 THEN m_hStatus = %StatusInvalidParameter : EXIT METHOD
      hDC = GetDC(hWnd)
      m_hStatus = GdipLoadImageFromFile(wszFileName, pImage)
      IF m_hStatus <> %S_OK THEN EXIT METHOD
      IF pImage THEN
         IF nWidth = 0 THEN m_hStatus = GdipGetImageWidth(pImage, nWidth)
         IF nHeight = 0 THEN m_hStatus = GdipGetImageHeight(pImage, nHeight)
         m_hStatus = GdipCreateFromHDC(hDC, pGraphics)
         IF pGraphics THEN m_hStatus = GdipDrawImageRectI(pGraphics, pImage, x, y, nWidth, nHeight)
         m_hStatus = GdipDisposeImage(pImage)
         IF pGraphics THEN m_hStatus = GdipDeleteGraphics(pGraphics)
      END IF
      ReleaseDC hWnd, hDC

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Helper method to retrieve the encoder's clsid
   ' * wszMimeType = Mime type.
   ' =====================================================================================
   METHOD GetEncoderClsid (BYREF wszMimeType AS WSTRINGZ) THREADSAFE AS WSTRING

      LOCAL i AS LONG
      LOCAL pImageCodecInfo AS ImageCodecInfo PTR
      LOCAL numEncoders AS DWORD
      LOCAL nSize AS DWORD

      m_hStatus = GdipGetImageEncodersSize(numEncoders, nSize)
      REDIM buffer(nSize - 1) AS BYTE
      pImageCodecInfo = VARPTR(buffer(0))

      m_hStatus = GdipGetImageEncoders(numEncoders, nSize, BYVAL pImageCodecInfo)
      IF m_hStatus = 0 THEN
         FOR i = 1 TO numEncoders
            IF INSTR(UCASE$(@pImageCodecInfo.@MimeType), UCASE$(wszMimeType)) THEN
               METHOD = GUIDTXT$(@pImageCodecInfo.Clsid)
               EXIT FOR
            END IF
            INCR pImageCodecInfo       '// Increments pointer
         NEXT
      END IF

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' With the following wrapper functions you can easily convert pictures from one format to
   ' another, e.g. hStatus = ConvertImageToJpeg("C:\PHOTOS\TEST.BMP", "C:\PHOTOS\TEST.JPG")
   ' =====================================================================================
   METHOD ConvertImage (BYREF wszLoadFileName AS WSTRINGZ, BYREF wszSaveFileName AS WSTRINGZ, BYREF wszMimeType AS WSTRINGZ) THREADSAFE

      LOCAL s AS STRING
      LOCAL clsidEncoder AS GUID
      LOCAL pImage AS DWORD

      IF TRIM$(wszLoadFileName) = "" THEN m_hStatus = %StatusInvalidParameter : EXIT METHOD
      IF TRIM$(wszSaveFileName) = "" THEN m_hStatus = %StatusInvalidParameter : EXIT METHOD

      s = ME.GetEncoderClsid(wszMimeType)
      IF s = "" THEN
         m_hStatus = %StatusInvalidParameter
         EXIT METHOD
      END IF
      clsidEncoder = GUID$(s)

      m_hStatus = GdipLoadImageFromFile(wszLoadFileName, pImage)
      IF m_hStatus THEN EXIT METHOD

      IF pImage THEN
         m_hStatus = GdipSaveImageToFile(pImage, wszSaveFileName, clsidEncoder, BYVAL %NULL)
         IF m_hStatus THEN
            GdipDisposeImage(pImage)
            EXIT METHOD
         END IF
      END IF

      GdipDisposeImage(pImage)

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD ConvertImageToBmp (BYREF wszLoadFileName AS WSTRINGZ, BYREF wszSaveFileName AS WSTRINGZ) THREADSAFE AS LONG
      ME.ConvertImage(wszLoadFileName, wszSaveFileName, "image/bmp")
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD ConvertImageToJpeg (BYREF wszLoadFileName AS WSTRINGZ, BYREF wszSaveFileName AS WSTRINGZ) THREADSAFE AS LONG
      ME.ConvertImage (wszLoadFileName, wszSaveFileName, "image/jpeg")
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD ConvertImageToGif (BYREF wszLoadFileName AS WSTRINGZ, BYREF wszSaveFileName AS WSTRINGZ) THREADSAFE AS LONG
      ME.ConvertImage (wszLoadFileName, wszSaveFileName, "image/gif")
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD ConvertImageToTiff (BYREF wszLoadFileName AS WSTRINGZ, BYREF wszSaveFileName AS WSTRINGZ) THREADSAFE AS LONG
      ME.ConvertImage (wszLoadFileName, wszSaveFileName, "image/tiff")
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD ConvertImageToPng (BYREF wszLoadFileName AS WSTRINGZ, BYREF wszSaveFileName AS WSTRINGZ) THREADSAFE AS LONG
      ME.ConvertImage (wszLoadFileName, wszSaveFileName, "image/png")
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' With the following wrapper functions you can easily save images in the desired format.
   ' =====================================================================================
   METHOD SaveImageToFile (BYVAL pImage AS IGdipImage, BYREF wszFileName AS WSTRINGZ, BYREF wszMimeType AS WSTRINGZ) THREADSAFE

      LOCAL s AS STRING
      LOCAL clsidEncoder AS GUID

      IF ISNOTHING(pImage) THEN m_hStatus = %StatusInvalidParameter : EXIT METHOD
      IF TRIM$(wszFileName) = "" THEN m_hStatus = %StatusInvalidParameter : EXIT METHOD

      s = ME.GetEncoderClsid(wszMimeType)
      IF s = "" THEN
         m_hStatus = %StatusInvalidParameter
         EXIT METHOD
      END IF
      clsidEncoder = GUID$(s)

      m_hStatus = GdipSaveImageToFile(pImage.Ptr, wszFileName, clsidEncoder, BYVAL %NULL)

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD SaveImageToBmp (BYVAL pImage AS IGdipImage, BYREF wszFileName AS WSTRINGZ) THREADSAFE AS LONG
      ME.SaveImageToFile (pImage, wszFileName, "image/bmp")
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD SaveImageToJpeg (BYVAL pImage AS IGdipImage, BYREF wszFileName AS WSTRINGZ) THREADSAFE AS LONG
      ME.SaveImageToFile (pImage, wszFileName, "image/jpeg")
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD SaveImageToGif (BYVAL pImage AS IGdipImage, BYREF wszFileName AS WSTRINGZ) THREADSAFE AS LONG
      ME.SaveImageToFile (pImage, wszFileName, "image/gif")
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD SaveImageToTiff (BYVAL pImage AS IGdipImage, BYREF wszFileName AS WSTRINGZ) THREADSAFE AS LONG
      ME.SaveImageToFile (pImage, wszFileName, "image/tiff")
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   METHOD SaveImageToPng (BYVAL pImage AS IGdipImage, BYREF wszFileName AS WSTRINGZ) THREADSAFE AS LONG
      ME.SaveImageToFile (pImage, wszFileName, "image/png")
      METHOD = m_hStatus
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Loads textures from disk for use with OPENGL.
   ' Parameters:
   ' * wszFileName    = [in]  The file name of the texture.
   ' * TextureWidth   = [out] Width of the texture.
   ' * TextureHeight  = [out] Height of the texture.
   ' * strTextureData = [out] The texture data.
   ' Return Value:
   ' * %E_POINTER = One of the parameters is null.
   ' * ERROR_FILE_NOT_FOUND = File not found.
   ' * ERROR_INVALID_DATA = Bad image size.
   ' * A GdiPlus status value.
   ' =====================================================================================
   METHOD LoadTexture ( _
      BYREF wszFileName AS WSTRINGZ, _
      BYREF TextureWidth AS LONG, _
      BYREF TextureHeight AS LONG, _
      BYREF strTextureData AS STRING _
      ) THREADSAFE AS LONG

      #REGISTER NONE
      REGISTER x AS LONG
      REGISTER y AS LONG

      LOCAL pImage       AS DWORD                 ' // Image handle
      LOCAL pThumb       AS DWORD                 ' // Thumbnail image handle
      LOCAL pixColor     AS GDIP_BGRA_UNION       ' // Union uses to swap colors
      LOCAL pTextureData AS DWORD PTR             ' // Pointer to the texture data

      IF VARPTR(TextureWidth) = %NULL OR VARPTR(TextureHeight) = %NULL OR VARPTR(strTextureData) = %NULL THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = %E_POINTER
         EXIT METHOD
      END IF

      m_hStatus = GdipLoadImageFromFile(wszFileName, pImage)
      IF m_hStatus = %StatusOk THEN
         m_hStatus = GdipGetImageWidth(pImage, TextureWidth)
         m_hStatus = GdipGetImageHeight(pImage, TextureHeight)
         IF TextureWidth <> TextureHeight THEN
            METHOD = %ERROR_INVALID_DATA
            EXIT METHOD
         ELSE
            IF IIF&(TALLY(BIN$(TextureWidth), "1") = 1, 1, 0) = %FALSE THEN
               METHOD = %ERROR_INVALID_DATA
               EXIT METHOD
            END IF
         END IF
         IF m_hStatus = %StatusOk THEN
            m_hStatus = GdipGetImageThumbnail(pImage, TextureWidth, TextureHeight, pThumb, %NULL, %NULL)
            IF m_hStatus = %StatusOk THEN
               m_hStatus = GdipImageRotateFlip(pThumb, 6) ' 6 = %RotateNoneFlipY
               IF m_hStatus = %StatusOk THEN
                  strTextureData = NUL$(TextureWidth * TextureHeight * 4)
                  pTextureData = STRPTR(strTextureData)
                  FOR y = 0 TO TextureWidth - 1
                     FOR x = 0 TO TextureHeight - 1
                        GdipBitmapGetPixel(pThumb, x, y, pixColor.color)
                        SWAP pixColor.red, pixColor.blue
                        @pTextureData = pixColor.color
                        INCR pTextureData
                     NEXT
                  NEXT
               END IF
            END IF
         END IF
      END IF

      IF pImage THEN GdipDisposeImage(pImage)
      IF pThumb THEN GdipDisposeImage(pThumb)

      METHOD = m_hStatus

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Loads textures from a resource file for use with OPENGL.
   ' Parameters:
   ' * hInstance       = [in]  Instance handle.
   ' * wszResourceName = [in]  Name of the resource.
   ' * TextureWidth    = [out] Width of the texture.
   ' * TextureHeight   = [out] Height of the texture.
   ' * strTextureData  = [out] The texture data.
   ' Return Value:
   ' * %E_POINTER = One of the parameters is null.
   ' * %E_ONVALIDARG = One of the parameters is an invalid argument.
   ' * ERROR_FILE_NOT_FOUND = File not found.
   ' * ERROR_INVALID_DATA = Bad image size.
   ' * A GdiPlus status value.
   ' =====================================================================================
   METHOD LoadTextureFromResource ( _
      BYVAL hInstance AS DWORD, _
      BYREF wszResourceName AS WSTRINGZ, _
      BYREF TextureWidth AS LONG, _
      BYREF TextureHeight AS LONG, _
      BYREF strTextureData AS STRING _
      ) THREADSAFE AS LONG

      #REGISTER NONE
      REGISTER x AS LONG
      REGISTER y AS LONG

      LOCAL pImage        AS DWORD                 ' // Image handle
      LOCAL pThumb        AS DWORD                 ' // Thumbnail image handle
      LOCAL pixColor      AS GDIP_BGRA_UNION       ' // Union uses to swap colors
      LOCAL pTextureData  AS DWORD PTR             ' // Pointer to the texture data
      LOCAL hResource     AS DWORD                 ' // Resource handle
      LOCAL pResourceData AS DWORD                 ' // Pointer to the resoruce data
      LOCAL hGlobal       AS DWORD                 ' // Global memory handle
      LOCAL pGlobalBuffer AS DWORD                 ' // Pointer to global memory buffer
      LOCAL pImageStream  AS IStream               ' // IStream interface pointer
      LOCAL imageSize     AS DWORD                 ' // Image size

      IF VARPTR(TextureWidth) = %NULL OR VARPTR(TextureHeight) = %NULL OR VARPTR(strTextureData) = %NULL THEN
         m_hStatus = %StatusInvalidParameter
         METHOD = %E_POINTER
         EXIT METHOD
      END IF

      ' // Find the resource and lock it
      hResource = FindResourceW(hInstance, wszResourceName, BYVAL %RT_RCDATA)
      IF hResource = %NULL THEN METHOD = %E_INVALIDARG : EXIT METHOD
      imageSize = SizeofResource(hInstance, hResource)
      IF imageSize = 0 THEN METHOD = %E_INVALIDARG : EXIT METHOD
      pResourceData = LockResource(LoadResource(hInstance, hResource))
      IF pResourceData = %NULL THEN METHOD = %E_INVALIDARG : EXIT METHOD
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
               m_hStatus = GdipCreateBitmapFromStream(pImageStream, pImage)
               IF m_hStatus = %StatusOk THEN
                  m_hStatus = GdipGetImageWidth(pImage, TextureWidth)
                  m_hStatus = GdipGetImageHeight(pImage, TextureHeight)
                  IF TextureWidth <> TextureHeight THEN
                     METHOD = %ERROR_INVALID_DATA
                  ELSE
                      IF IIF&(TALLY(BIN$(TextureWidth), "1") = 1, 1, 0) = %FALSE THEN METHOD = %ERROR_INVALID_DATA
                  END IF
                  IF m_hStatus = %StatusOk THEN
                     m_hStatus = GdipGetImageThumbnail(pImage, TextureWidth, TextureHeight, pThumb, %NULL, %NULL)
                     IF m_hStatus = %StatusOk THEN
                        m_hStatus = GdipImageRotateFlip(pThumb, 6) ' 6 = %RotateNoneFlipY
                        IF m_hStatus = %StatusOk THEN
                           strTextureData = NUL$(TextureWidth * TextureHeight * 4)
                           pTextureData = STRPTR(strTextureData)
                           FOR y = 0 TO TextureWidth - 1
                              FOR x = 0 TO TextureHeight - 1
                                 GdipBitmapGetPixel(pThumb, x, y, pixColor.color)
                                 SWAP pixColor.red, pixColor.blue
                                 @pTextureData = pixColor.color
                                 INCR pTextureData
                              NEXT
                           NEXT
                        END IF
                     END IF
                  END IF
               END IF
               pImageStream = NOTHING
            END IF
            ' // Unlock the memory
            GlobalUnlock pGlobalBuffer
         END IF
         ' // Free the memory
         GlobalFree hGlobal
      END IF

      IF pImage THEN GdipDisposeImage(pImage)
      IF pThumb THEN GdipDisposeImage(pThumb)

      METHOD = m_hStatus

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Loads an image from a resource using GDI+, converts it to a GDI+ image and returns the handle.
   ' Parameters:
   ' - hInstance  = [in] Handle to the instance that contains the resource.
   ' - bstrImage  = [in] Name of the image in the resource file (.RES). If the image resource uses
   '                an integral identifier, bstrImage should begin with a number symbol (#)
   '                followed by the identifier in an ASCII format, e.g., "#998". Otherwise,
   '                use the text identifier name for the image. Only images embedded as raw data
   '                (type RCDATA) are valid. These must be icons in format .png, .jpg, .gif, .tiff.
   ' Return Value:
   '   If the function succeeds, the return value is the handle of the created GDI+ image.
   '   If the function fails, the return value is NULL.
   ' Note: This function is used to create GDI+ images from raw data resources. This allows to
   ' use images other than bitmaps, such PNGs.
   ' For BITMAP resources, use the GdipCreateBitmapFromResource flat API function.
   ' =====================================================================================
   METHOD CreateBitmapFromRawDataResource (BYVAL hInstance AS DWORD, BYVAL bstrImage AS WSTRING) THREADSAFE AS DWORD

      LOCAL pImage        AS DWORD                 ' // Image handle
      LOCAL hResource     AS DWORD                 ' // Resource handle
      LOCAL pResourceData AS DWORD                 ' // Pointer to the resoruce data
      LOCAL hGlobal       AS DWORD                 ' // Global memory handle
      LOCAL pGlobalBuffer AS DWORD                 ' // Pointer to global memory buffer
      LOCAL pImageStream  AS IStream               ' // IStream interface pointer
      LOCAL imageSize     AS DWORD                 ' // Image size
      LOCAL wID           AS WORD
      LOCAL dwID          AS DWORD

      IF hInstance = 0 THEN
         m_hStatus = %StatusInvalidParameter
         EXIT METHOD
      END IF

      ' // Find the resource and lock it
      IF LEFT$(bstrImage, 1) = "#" THEN
         wID = VAL(MID$(bstrImage, 2))
         dwID = MAK(DWORD, wID, 0)
         hResource = FindResourceW(hInstance, BYVAL dwID, BYVAL %RT_RCDATA)
      ELSE
         hResource = FindResourceW(hInstance, BYCOPY bstrImage, BYVAL %RT_RCDATA)
      END IF
      IF hResource = %NULL THEN m_hStatus = %StatusInvalidParameter : EXIT METHOD
      imageSize = SizeofResource(hInstance, hResource)
      IF imageSize = 0 THEN m_hStatus = %StatusInvalidParameter : EXIT METHOD
      pResourceData = LockResource(LoadResource(hInstance, hResource))
      IF pResourceData = %NULL THEN m_hStatus = %StatusInvalidParameter : EXIT METHOD
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
               m_hStatus = GdipCreateBitmapFromStream(pImageStream, pImage)
               pImageStream = NOTHING
            END IF
            ' // Unlock the memory
            GlobalUnlock pGlobalBuffer
         END IF
         ' // Free the memory
         GlobalFree hGlobal
      END IF

      METHOD = pImage

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Loads an image from a file using GDI+, converts it to an icon and returns the icon handle.
   ' Parameter:
   ' - bstrFileName = [in] Path of the image to load and convert.
   ' Return Value:
   '   If the function succeeds, the return value is the handle of the created icon.
   '   If the function fails, the return value is NULL.
   ' =====================================================================================
   METHOD CreateHICONFromFile (BYVAL bstrFileName AS WSTRING) THREADSAFE AS DWORD

      LOCAL pImage AS DWORD                       ' // Image handle
      LOCAL hIcon AS DWORD                        ' // Icon handle

      m_hStatus = GdipLoadImageFromFile(BYCOPY bstrFileName, pImage)
      IF m_hStatus = %StatusOk THEN
         m_hStatus = GdipCreateHICONFromBitmap(pImage, hIcon)
         GdipDisposeImage pImage
      END IF

      METHOD = hIcon

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Loads an image from a resource using GDI+, converts it to an icon and returns the icon handle.
   ' Parameter:
   ' - hInstance  = [in] Handle to the instance that contains the resource.
   ' - bstrImage  = [in] Name of the image in the resource file (.RES). If the image resource uses
   '                an integral identifier, bstrImage should begin with a number symbol (#)
   '                followed by the identifier in an ASCII format, e.g., "#998". Otherwise,
   '                use the text identifier name for the image. Only images embedded as raw data
   '                (type RCDATA) are valid. These must be icons in format .png, .jpg, .gif, .tiff.
   ' Return Value:
   '   If the function succeeds, the return value is the handle of the created icon.
   '   If the function fails, the return value is NULL.
   ' =====================================================================================
   METHOD CreateHICONFromResource (BYVAL hInstance AS DWORD, BYVAL bstrImage AS WSTRING) THREADSAFE AS DWORD

      LOCAL pImage AS DWORD                        ' // Image handle
      LOCAL hIcon AS DWORD                         ' // Icon handle
      LOCAL hResource     AS DWORD                 ' // Resource handle
      LOCAL pResourceData AS DWORD                 ' // Pointer to the resoruce data
      LOCAL hGlobal       AS DWORD                 ' // Global memory handle
      LOCAL pGlobalBuffer AS DWORD                 ' // Pointer to global memory buffer
      LOCAL pImageStream  AS IStream               ' // IStream interface pointer
      LOCAL imageSize     AS DWORD                 ' // Image size
      LOCAL wID AS WORD
      LOCAL dwID AS DWORD

      IF hInstance = 0 THEN
         m_hStatus = %StatusInvalidParameter
         EXIT METHOD
      END IF

      ' // Find the resource and lock it
      IF LEFT$(bstrImage, 1) = "#" THEN
         wID = VAL(MID$(bstrImage, 2))
         dwID = MAK(DWORD, wID, 0)
         hResource = FindResourceW(hInstance, BYVAL dwID, BYVAL %RT_RCDATA)
      ELSE
         hResource = FindResourceW(hInstance, BYCOPY bstrImage, BYVAL %RT_RCDATA)
      END IF
      IF hResource = %NULL THEN m_hStatus = %StatusInvalidParameter : EXIT METHOD
      imageSize = SizeofResource(hInstance, hResource)
      IF imageSize = 0 THEN m_hStatus = %StatusInvalidParameter : EXIT METHOD
      pResourceData = LockResource(LoadResource(hInstance, hResource))
      IF pResourceData = %NULL THEN m_hStatus = %StatusInvalidParameter : EXIT METHOD
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
               m_hStatus = GdipCreateBitmapFromStream(pImageStream, pImage)
               IF m_hStatus = %StatusOk THEN
                  IF pImage THEN
                     m_hStatus = GdipCreateHICONFromBitmap(pImage, hIcon)
                     GdipDisposeImage pImage
                  END IF
               END IF
               pImageStream = NOTHING
            END IF
            ' // Unlock the memory
            GlobalUnlock pGlobalBuffer
         END IF
         ' // Free the memory
         GlobalFree hGlobal
      END IF

      METHOD = hIcon

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Loads an image from a file using GDI+, converts it to a bitmap and returns the bitmap handle.
   ' Parameters:
   ' - bstrFileName  = [in] Path of the image to load and convert.
   ' - clrBackground = [in] The background color. This parameter is ignored if the bitmap is totally opaque.
   ' Return Value:
   '   If the function succeeds, the return value is the handle of the created bitmap.
   '   If the function fails, the return value is NULL.
   ' =====================================================================================
   METHOD CreateHBITMAPFromFile (BYVAL bstrFileName AS WSTRING, BYVAL clrBackground AS DWORD) THREADSAFE AS DWORD

      LOCAL pImage AS DWORD                       ' // Image handle
      LOCAL hBitmap AS DWORD                      ' // Bitmap handle

      m_hStatus = GdipLoadImageFromFile(BYCOPY bstrFileName, pImage)
      IF m_hStatus = %StatusOk THEN
         m_hStatus = GdipCreateHBITMAPFromBitmap(pImage, hBitmap, clrBackground)
         GdipDisposeImage pImage
      END IF

      METHOD = hBitmap

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Loads an image from a resource using GDI+, converts it to a bitmap and returns the bitmap handle.
   ' Parameters:
   ' - hInstance  = [in] Handle to the instance that contains the resource.
   ' - bstrImage  = [in] Name of the image in the resource file (.RES). If the image resource uses
   '                an integral identifier, bstrImage should begin with a number symbol (#)
   '                followed by the identifier in an ASCII format, e.g., "#998". Otherwise,
   '                use the text identifier name for the image. Only images embedded as raw data
   '                (type RCDATA) are valid. These must be icons in format .png, .jpg, .gif, .tiff.
   ' - clrBackground = [in] The background color. This parameter is ignored if the bitmap is totally opaque.
   ' Return Value:
   '   If the function succeeds, the return value is the handle of the created bitmap.
   '   If the function fails, the return value is NULL.
   '   Call GetLasrError to retrieve the error code.
   ' =====================================================================================
   METHOD CreateHBITMAPFromResource (BYVAL hInstance AS DWORD, BYVAL bstrImage AS WSTRING, BYVAL clrBackground AS DWORD) THREADSAFE AS DWORD

      LOCAL pImage        AS DWORD                 ' // Image handle
      LOCAL hBitmap       AS DWORD                 ' // Bitmap handle
      LOCAL hResource     AS DWORD                 ' // Resource handle
      LOCAL pResourceData AS DWORD                 ' // Pointer to the resoruce data
      LOCAL hGlobal       AS DWORD                 ' // Global memory handle
      LOCAL pGlobalBuffer AS DWORD                 ' // Pointer to global memory buffer
      LOCAL pImageStream  AS IStream               ' // IStream interface pointer
      LOCAL imageSize     AS DWORD                 ' // Image size
      LOCAL wID           AS WORD
      LOCAL dwID          AS DWORD

      IF hInstance = 0 THEN
         m_hStatus = %StatusInvalidParameter
         EXIT METHOD
      END IF

      ' // Find the resource and lock it
      IF LEFT$(bstrImage, 1) = "#" THEN
         wID = VAL(MID$(bstrImage, 2))
         dwID = MAK(DWORD, wID, 0)
         hResource = FindResourceW(hInstance, BYVAL dwID, BYVAL %RT_RCDATA)
      ELSE
         hResource = FindResourceW(hInstance, BYCOPY bstrImage, BYVAL %RT_RCDATA)
      END IF
      IF hResource = %NULL THEN m_hStatus = %StatusInvalidParameter : EXIT METHOD
      imageSize = SizeofResource(hInstance, hResource)
      IF imageSize = 0 THEN m_hStatus = %StatusInvalidParameter : EXIT METHOD
      pResourceData = LockResource(LoadResource(hInstance, hResource))
      IF pResourceData = %NULL THEN m_hStatus = %StatusInvalidParameter : EXIT METHOD
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
               m_hStatus = GdipCreateBitmapFromStream(pImageStream, pImage)
               IF m_hStatus = %StatusOk THEN
                  IF pImage THEN
                     m_hStatus = GdipCreateHBITMAPFromBitmap(pImage, hBitmap, clrBackground)
                     GdipDisposeImage pImage
                  END IF
               END IF
               pImageStream = NOTHING
            END IF
            ' // Unlock the memory
            GlobalUnlock pGlobalBuffer
         END IF
         ' // Free the memory
         GlobalFree hGlobal
      END IF

      METHOD = hBitmap

   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' ########################################################################################

' ########################################################################################
' Creates a new instance of the CGdiPlus class and initializes GDI+.
' ########################################################################################
FUNCTION NewGdiplus (OPTIONAL BYVAL version AS LONG) THREADSAFE AS IGdiPlus
   LOCAL pGdiPlus AS IGdiPlus
   pGdiPlus = CLASS "CGdiPlus"
   IF ISNOTHING(pGdiPlus) THEN EXIT FUNCTION
   pGdiPlus.Init(version)
   FUNCTION = pGdiPlus
END FUNCTION
' ########################################################################################
