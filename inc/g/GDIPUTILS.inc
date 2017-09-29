' ########################################################################################
' Microsoft Windows
' File: GDIPUTILS.INC
' Contents: GdiPlus wrapper functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' // NOTE: Routines moved to GDIPLUS.INC

#INCLUDE THIS ONCE
%GDIPUTILS_INC = 1

#INCLUDE ONCE "GdiPlus.inc"
#INCLUDE ONCE "commdlg.inc"

' // Size = 4 bytes
TYPE GDIP_BGRA_STRUCT BYTE
   blue  AS BYTE
   green AS BYTE
   red   AS BYTE
   alpha AS BYTE
END TYPE

' // Size = 4 bytes
UNION GDIP_BGRA_UNION
   color AS DWORD
   GDIP_BGRA_STRUCT
END UNION

' ========================================================================================
' Returns an ARGB color value initialized with the specified values for the alpha, red,
' green, and blue components.
' ========================================================================================
FUNCTION GDIP_ARGB (BYVAL a AS BYTE, BYVAL r AS BYTE, BYVAL g AS BYTE, BYVAL b AS BYTE) AS DWORD
   LOCAL clr AS GDIP_BGRA_UNION
   clr.alpha = a
   clr.red   = r
   clr.green = g
   clr.blue  = b
   FUNCTION  = clr.color
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the alpha value of an ARGB color
' ========================================================================================
FUNCTION GDIP_ARGB_SetAlphaValue (BYVAL dwColor AS DWORD, BYVAL bAlpha AS BYTE) AS DWORD
   LOCAL clr AS GDIP_BGRA_UNION
   clr.color = dwColor
   clr.alpha = bAlpha
   FUNCTION  = clr.color
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the individual color values of an ARGB color
' ========================================================================================
SUB GDIP_ARGB_GetColorValues (BYVAL dwColor AS DWORD, BYREF bAlpha AS BYTE, BYREF bRed AS BYTE, BYREF bGreen AS BYTE, BYREF bBlue AS BYTE)
   LOCAL clr AS GDIP_BGRA_UNION
   clr.color = dwColor
   bAlpha    = clr.alpha
   bRed      = clr.red
   bGreen    = clr.green
   bBlue     = clr.blue
END SUB
' ========================================================================================

' ========================================================================================
' Returns an RGBA color value initialized with the specified values for the alpha, red,
' green, and blue components.
' ========================================================================================
FUNCTION GDIP_RGBA (BYVAL r AS BYTE, BYVAL g AS BYTE, BYVAL b AS BYTE, BYVAL a AS BYTE) AS DWORD
   FUNCTION = GDIP_ARGB(a, r, g, b)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns an XRGB color value initialized with the specified values for the red, green,
' and blue components.
' ========================================================================================
FUNCTION GDIP_XRGB (BYVAL r AS BYTE, BYVAL g AS BYTE, BYVAL b AS BYTE) AS DWORD
   FUNCTION = GDIP_ARGB(&HFF, r, g, b)
END FUNCTION
' ========================================================================================

#IF NOT %DEF(%GPRECTL_DEFINED)
%GPRECTL_DEFINED = 1
' // Size = 16 bytes
TYPE GpRectL DWORD
   x      AS LONG
   y      AS LONG
   Width  AS LONG
   Height AS LONG
END TYPE
#ENDIF

SUB GDIP_SetRectF (BYREF rcf AS RectF, BYVAL x AS SINGLE, BYVAL y AS SINGLE, BYVAL nWidth AS SINGLE, BYVAL nHeight AS SINGLE)
   rcf.x = x : rcf.y = y : rcf.Width = nWidth : rcf.Height = nHeight
END SUB

SUB GDIP_SetRectI (BYREF rc AS RECT, BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG)
   rc.x = x : rc.y = y : rc.Width = nWidth : rc.Height = nHeight
END SUB

SUB GDIP_SetPointF (BYREF pt AS PointF, BYVAL x AS SINGLE, BYVAL y AS SINGLE)
   pt.x = x : pt.y = y
END SUB

SUB GDIP_SetPointI (BYREF pt AS POINT, BYVAL x AS LONG, BYVAL y AS LONG)
   pt.x = x : pt.y = y
END SUB

' ========================================================================================
' Returns the version of GdiPlus.dll
' ========================================================================================
FUNCTION GdiPlusDllVersion () AS CURRENCY

   LOCAL pvsffi AS VS_FIXEDFILEINFO PTR
   LOCAL pVerInfo AS DWORD
   LOCAL dwHandle AS DWORD
   LOCAL dwVersion AS DWORD
   LOCAL cbLen AS DWORD
   LOCAL wMajor AS WORD
   LOCAL wMinor AS WORD
   cbLen = GetFileVersionInfoSize("GDIPLUS.DLL", dwHandle)
   IF cbLen THEN
      pVerInfo = HeapAlloc(GetProcessHeap, %HEAP_ZERO_MEMORY, cbLen)
      IF pVerInfo THEN
         IF GetFileVersionInfo("GDIPLUS.DLL", dwHandle, cbLen, BYVAL pVerInfo) THEN
            IF VerQueryValue(BYVAL pVerInfo, "\", BYVAL VARPTR(pvsffi), cbLen) THEN
               wMajor = HI(WORD, @pvsffi.dwFileVersionMS)
               wMinor = LO(WORD, @pvsffi.dwFileVersionMS)
            END IF
         END IF
         HeapFree GetProcessHeap, 0, pVerInfo
      END IF
   END IF
   FUNCTION = wMajor + wMinor / 100

END FUNCTION
' ========================================================================================

' ========================================================================================
' Initilizes GDI+
' Returns a token. Pass the token to GdiplusShutdown when you have finished using GDI+.
' ========================================================================================
FUNCTION GdiPlusInit (OPTIONAL BYVAL version AS DWORD) AS DWORD

   LOCAL hStatus AS LONG
   LOCAL token AS DWORD
   LOCAL StartupInput AS GdiplusStartupInput

   IF version < 1 THEN version = 1
   StartupInput.GdiplusVersion = version
   hStatus = GdiplusStartup(token, StartupInput, BYVAL %NULL)
   FUNCTION = token

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the description of a GdiPlus status code.
' ========================================================================================
FUNCTION GdiPlusStatusStr (BYVAL nStatus AS LONG) AS WSTRING

   FUNCTION = "Unknown"

   SELECT CASE AS LONG nStatus
      CASE %StatusOk                        : FUNCTION = "Ok"
      CASE %StatusGenericError              : FUNCTION = "Generic error"
      CASE %StatusInvalidParameter          : FUNCTION = "Invalid parameter"
      CASE %StatusOutOfMemory               : FUNCTION = "Out of memory"
      CASE %StatusObjectBusy                : FUNCTION = "Object busy"
      CASE %StatusInsufficientBuffer        : FUNCTION = "Insufficient buffer"
      CASE %StatusNotImplemented            : FUNCTION = "Not implemented"
      CASE %StatusWin32Error                : FUNCTION = "Win 32 error"
      CASE %StatusWrongState                : FUNCTION = "Wrong state"
      CASE %StatusAborted                   : FUNCTION = "Aborted"
      CASE %StatusFileNotFound              : FUNCTION = "File not found"
      CASE %StatusValueOverflow             : FUNCTION = "Value overflow"
      CASE %StatusAccessDenied              : FUNCTION = "Access denied"
      CASE %StatusUnknownImageFormat        : FUNCTION = "Unknown image format"
      CASE %StatusFontFamilyNotFound        : FUNCTION = "Font family not found"
      CASE %StatusFontStyleNotFound         : FUNCTION = "Font style not found"
      CASE %StatusNotTrueTypeFont           : FUNCTION = "Not TrueType font"
      CASE %StatusUnsupportedGdiplusVersion : FUNCTION = "Unsupported GdiPlus version"
      CASE %StatusGdiplusNotInitialized     : FUNCTION = "GdiPlus not initialized"
      CASE %StatusPropertyNotFound          : FUNCTION = "Property not found"
      CASE %StatusPropertyNotSupported      : FUNCTION = "Property not supported"
#IF (%GDIPVER >= &H0110)
      CASE %StatusProfileNotFound           : FUNCTION = "Profile not found"
#ENDIF   ' //(%GDIPVER >= &H0110)
   END SELECT

END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a Font based on a font family, a size, a font style and a unit of measurement
' * wszFamilyName = [in] Name of the font family.
' * emSize = [in] Real number that specifies the em size of the font measured in the units
'   specified in the unit parameter.
' * style = [in] Integer that specifies the style of the typeface. This value must be an
'   element of the FontStyle enumeration or the result of a bitwise OR applied to two or
'   more of these elements. For example, %FontStyleBold OR %FontStyleUnderline OR
'   %FontStyleStrikeout sets the style as a combination of the three styles.
'   The default value is %FontStyleRegular.
' * unit = [in] Element of the Unit enumeration that specifies the unit of measurement for
'   the font size. The default value is %UnitPoint.
' ========================================================================================
FUNCTION GdiPlusCreateFontFromName (BYREF wszFamilyName AS WSTRINGZ, BYVAL emSize AS SINGLE, BYVAL lStyle AS LONG, BYVAL unit AS DWORD, BYREF pFont AS DWORD) AS LONG

   LOCAL hStatus AS LONG
   LOCAL pFontFamily AS DWORD

   hStatus = GdipCreateFontFamilyFromName(wszFamilyName, %NULL, pFontFamily)
   IF hStatus = %StatusOk AND pFontFamily <> %NULL THEN
      hStatus = GdipCreateFont(pFontFamily, emSize, lStyle, unit, pFont)
      GdipDeleteFontFamily(pFontFamily)
   END IF
   FUNCTION = hStatus

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the size of the image.
' Parameters:
' * wszFileName = [in] Filename path.
' * nWidth      = [out] Width, in pixels, of the image.
' * nHeight     = [out] Height, in pixels, of the image.
' Return Values:
'   If the function succeeds, it returns Ok, which is an element of the Status enumeration.
'   If the function fails, it returns one of the other elements of the Status enumeration.
' ========================================================================================
FUNCTION GdiPlusGetImageSizeFromFile (BYREF wszFileName AS WSTRINGZ, BYREF nWidth AS DWORD, BYREF nHeight AS DWORD) AS LONG

   LOCAL hr AS LONG
   LOCAL pImage AS DWORD

   IF LEN(wszFileName) = 0 THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION
   hr = GdipLoadImageFromFile(wszFileName, pImage)
   IF hr <> %StatusOk THEN FUNCTION = hr : EXIT FUNCTION
   IF pImage THEN
      hr = GdipGetImageWidth(pImage, nWidth)
      hr = GdipGetImageHeight(pImage, nHeight)
      hr = GdipDisposeImage(pImage)
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Shows the specified image in the specified window.
' * hWnd = [in] Handle of the window.
' * wszFileName = Path of the file.
' ========================================================================================
FUNCTION GdiPlusShowImageFromFile (BYVAL hWnd AS DWORD, BYREF wszFileName AS WSTRINGZ) AS LONG

   LOCAL hr AS LONG
   LOCAL hDC AS DWORD
   LOCAL pImage AS DWORD
   LOCAL pGraphics AS DWORD
   LOCAL nWidth AS DWORD
   LOCAL nHeight AS DWORD

   IF IsWindow(hWnd) = 0 THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION
   IF LEN(wszFileName) = 0 THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION
   hDC = GetDC(hWnd)
   hr = GdipLoadImageFromFile(wszFileName, pImage)
   IF hr <> %S_OK THEN FUNCTION = hr : EXIT FUNCTION
   IF pImage THEN
      hr = GdipGetImageWidth(pImage, nWidth)
      hr = GdipGetImageHeight(pImage, nHeight)
      hr = GdipCreateFromHDC(hDC, pGraphics)
      IF pGraphics THEN hr = GdipDrawImageRectI(pGraphics, pImage, 0, 0, nWidth, nHeight)
      hr = GdipDisposeImage(pImage)
      IF pGraphics THEN hr = GdipDeleteGraphics(pGraphics)
   END IF
   ReleaseDC hWnd, hDC

END FUNCTION
' ========================================================================================

' ========================================================================================
' Shows the specified image in the specified window at the specified coordinates.
' * hWnd = [in] Handle of the window.
' * wszFileName = Path of the file.
' * x, y = Vertical and horizontal coordinates.
' ========================================================================================
FUNCTION GdiPlusShowImageFromFileXY (BYVAL hWnd AS DWORD, BYREF wszFileName AS WSTRINGZ, BYVAL x AS LONG, BYVAL y AS LONG, OPTIONAL BYVAL nWidth AS LONG, OPTIONAL BYVAL nHeight AS LONG) AS LONG

   LOCAL hr AS LONG
   LOCAL hDC AS DWORD
   LOCAL pImage AS DWORD
   LOCAL pGraphics AS DWORD

   IF IsWindow(hWnd) = 0 THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION
   IF LEN(wszFileName) = 0 THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION
   hDC = GetDC(hWnd)
   hr = GdipLoadImageFromFile(wszFileName, pImage)
   IF hr <> %S_OK THEN FUNCTION = hr : EXIT FUNCTION
   IF pImage THEN
      IF nWidth = 0 THEN hr = GdipGetImageWidth(pImage, nWidth)
      IF nHeight = 0 THEN hr = GdipGetImageHeight(pImage, nHeight)
      hr = GdipCreateFromHDC(hDC, pGraphics)
      IF pGraphics THEN hr = GdipDrawImageRectI(pGraphics, pImage, x, y, nWidth, nHeight)
      hr = GdipDisposeImage(pImage)
      IF pGraphics THEN hr = GdipDeleteGraphics(pGraphics)
   END IF
   ReleaseDC hWnd, hDC

END FUNCTION
' ========================================================================================

' ========================================================================================
' Helper function to retrieve the encoder's clsid
' * wszMimeType = Mime type.
' ========================================================================================
FUNCTION GdiPlusGetEncoderClsid (BYREF wszMimeType AS WSTRINGZ) AS WSTRING

   LOCAL hr AS LONG
   LOCAL i AS LONG
   LOCAL pImageCodecInfo AS ImageCodecInfo PTR
   LOCAL numEncoders AS DWORD
   LOCAL nSize AS DWORD

   hr = GdipGetImageEncodersSize(numEncoders, nSize)
   REDIM buffer(nSize - 1) AS BYTE
   pImageCodecInfo = VARPTR(buffer(0))

   hr = GdipGetImageEncoders(numEncoders, nSize, BYVAL pImageCodecInfo)
   IF hr = 0 THEN
      FOR i = 1 TO numEncoders
         IF INSTR(UCASE$(@pImageCodecInfo.@MimeType), UCASE$(wszMimeType)) THEN
            FUNCTION = GUIDTXT$(@pImageCodecInfo.Clsid)
            EXIT FOR
         END IF
         INCR pImageCodecInfo       '// Increments pointer
      NEXT
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' With the following wrapper functions you can easily convert pictures from one format to
' another, e.g. hStatus = ConvertImageToJpeg("C:\PHOTOS\TEST.BMP", "C:\PHOTOS\TEST.JPG")
' ========================================================================================
FUNCTION GdiPlusConvertImage (BYREF wszLoadFileName AS WSTRINGZ, BYREF wszSaveFileName AS WSTRINGZ, BYREF wszMimeType AS WSTRINGZ) AS LONG

   LOCAL hr AS LONG
   LOCAL s AS STRING
   LOCAL clsidEncoder AS GUID
   LOCAL pImage AS DWORD

   IF TRIM$(wszLoadFileName) = "" THEN FUNCTION = %StatusInvalidParameter : EXIT FUNCTION
   IF TRIM$(wszSaveFileName) = "" THEN FUNCTION = %StatusInvalidParameter : EXIT FUNCTION

   s = GdiPlusGetEncoderClsid(wszMimeType)
   IF s = "" THEN
      FUNCTION = %StatusInvalidParameter
      EXIT FUNCTION
   END IF
   clsidEncoder = GUID$(s)

   hr = GdipLoadImageFromFile(wszLoadFileName, pImage)
   IF hr THEN
      FUNCTION = hr
      EXIT FUNCTION
   END IF

   IF pImage THEN
      hr = GdipSaveImageToFile(pImage, wszSaveFileName, clsidEncoder, BYVAL %NULL)
      IF hr THEN
         GdipDisposeImage(pImage)
         FUNCTION = hr
         EXIT FUNCTION
      END IF
   END IF

   GdipDisposeImage(pImage)

END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION GdiPlusConvertImageToBmp (BYREF wszLoadFileName AS WSTRINGZ, BYREF wszSaveFileName AS WSTRINGZ) AS LONG
   FUNCTION = GdiPlusConvertImage(wszLoadFileName, wszSaveFileName, "image/bmp")
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION GdiPlusConvertImageToJpeg (BYREF wszLoadFileName AS WSTRINGZ, BYREF wszSaveFileName AS WSTRINGZ) AS LONG
   FUNCTION = GdiPlusConvertImage (wszLoadFileName, wszSaveFileName, "image/jpeg")
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION GdiPlusConvertImageToGif (BYREF wszLoadFileName AS WSTRINGZ, BYREF wszSaveFileName AS WSTRINGZ) AS LONG
   FUNCTION = GdiPlusConvertImage (wszLoadFileName, wszSaveFileName, "image/gif")
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION GdiPlusConvertImageToTiff (BYREF wszLoadFileName AS WSTRINGZ, BYREF wszSaveFileName AS WSTRINGZ) AS LONG
   FUNCTION = GdiPlusConvertImage (wszLoadFileName, wszSaveFileName, "image/tiff")
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION GdiPlusConvertImageToPng (BYREF wszLoadFileName AS WSTRINGZ, BYREF wszSaveFileName AS WSTRINGZ) AS LONG
   FUNCTION = GdiPlusConvertImage (wszLoadFileName, wszSaveFileName, "image/png")
END FUNCTION
' ========================================================================================

' ========================================================================================
' With the following wrapper functions you can easily save images in the desired format.
' ========================================================================================
FUNCTION GdiPlusSaveImageToFile (BYVAL pImage AS DWORD, BYREF wszFileName AS WSTRINGZ, BYREF wszMimeType AS WSTRINGZ) AS LONG

   LOCAL hr AS LONG
   LOCAL s AS STRING
   LOCAL clsidEncoder AS GUID

   IF pImage = %NULL THEN FUNCTION = %StatusInvalidParameter : EXIT FUNCTION
   IF TRIM$(wszFileName) = "" THEN FUNCTION = %StatusInvalidParameter : EXIT FUNCTION

   s = GdiPlusGetEncoderClsid(wszMimeType)
   IF s = "" THEN
      FUNCTION = %StatusInvalidParameter
      EXIT FUNCTION
   END IF
   clsidEncoder = GUID$(s)

   hr = GdipSaveImageToFile(pImage, wszFileName, clsidEncoder, BYVAL %NULL)
   FUNCTION = hr

END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION GdiPlusSaveImageToBmp (BYVAL pImage AS DWORD, BYREF wszFileName AS WSTRINGZ) AS LONG
   FUNCTION = GdiPlusSaveImageToFile (pImage, wszFileName, "image/bmp")
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION GdiPlusSaveImageToJpeg (BYVAL pImage AS DWORD, BYREF wszFileName AS WSTRINGZ) AS LONG
   FUNCTION = GdiPlusSaveImageToFile (pImage, wszFileName, "image/jpeg")
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION GdiPlusSaveImageToGif (BYVAL pImage AS DWORD, BYREF wszFileName AS WSTRINGZ) AS LONG
   FUNCTION = GdiPlusSaveImageToFile (pImage, wszFileName, "image/gif")
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION GdiPlusSaveImageToTiff (BYVAL pImage AS DWORD, BYREF wszFileName AS WSTRINGZ) AS LONG
   FUNCTION = GdiPlusSaveImageToFile (pImage, wszFileName, "image/tiff")
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION GdiPlusSaveImageToPng (BYVAL pImage AS DWORD, BYREF wszFileName AS WSTRINGZ) AS LONG
   FUNCTION = GdiPlusSaveImageToFile (pImage, wszFileName, "image/png")
END FUNCTION
' ========================================================================================

' =======================================================================================
' Loads textures from disk for use with OPENGL.
' Parameters:
' * wszFileName    = [in]  The file name of the texture.
' * TextureWidth   = [out] Width of the texture.
' * TextureHeight  = [out] Height of the texture.
' * strTextureData = [out] The texture data.
' * bInitGdiPlus   = [opt] [in] Initialize GDI Plus
' Return Value:
' * %E_POINTER = One of the parameters is null.
' * ERROR_FILE_NOT_FOUND = File not found.
' * ERROR_INVALID_DATA = Bad image size.
' * A GdiPlus status value.
' =======================================================================================
FUNCTION GdiPlusLoadTexture ( _
   BYREF wszFileName AS WSTRINGZ, _
   BYREF TextureWidth AS LONG, _
   BYREF TextureHeight AS LONG, _
   BYREF strTextureData AS STRING, _
   OPTIONAL BYVAL bInitGdiPlus AS LONG _
   ) AS LONG

   #REGISTER NONE
   REGISTER x AS LONG
   REGISTER y AS LONG

   LOCAL hStatus      AS LONG                  ' // GDI+ status code
   LOCAL token        AS DWORD                 ' // Token to shutdown GDI+
   LOCAL StartupInput AS GdiplusStartupInput   ' // Structure to initialize GDI+
   LOCAL pImage       AS DWORD                 ' // Image handle
   LOCAL pThumb       AS DWORD                 ' // Thumbnail image handle
   LOCAL pixColor     AS GDIP_BGRA_UNION       ' // Union used to swap colors
   LOCAL pTextureData AS DWORD PTR             ' // Pointer to the texture data

   IF VARPTR(TextureWidth) = %NULL OR VARPTR(TextureHeight) = %NULL OR VARPTR(strTextureData) = %NULL THEN
      FUNCTION = %E_POINTER
      EXIT FUNCTION
   END IF

   ' // Initialize GDI+
   IF bInitGdiPlus THEN
      StartupInput.GdiplusVersion = 1
      hStatus = GdiplusStartup(token, StartupInput, BYVAL %NULL)
      IF hStatus THEN
         FUNCTION = hStatus
         EXIT FUNCTION
      END IF
   END IF

   hStatus = GdipLoadImageFromFile(wszFileName, pImage)
   IF hStatus = %StatusOk THEN
      hStatus = GdipGetImageWidth(pImage, TextureWidth)
      hStatus = GdipGetImageHeight(pImage, TextureHeight)
      IF TextureWidth <> TextureHeight THEN
         hStatus = %ERROR_INVALID_DATA
      ELSE
          IF IIF&(TALLY(BIN$(TextureWidth), "1") = 1, 1, 0) = %FALSE THEN hStatus = %ERROR_INVALID_DATA
      END IF
      IF hStatus = %StatusOk THEN
         hStatus = GdipGetImageThumbnail(pImage, TextureWidth, TextureHeight, pThumb, %NULL, %NULL)
         IF hStatus = %StatusOk THEN
            hStatus = GdipImageRotateFlip(pThumb, 6) ' 6 = %RotateNoneFlipY
            IF hStatus = %StatusOk THEN
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

   ' // Shutdown GDI+
   IF bInitGdiPlus THEN
      GdiplusShutdown token
   END IF

   FUNCTION = hStatus

END FUNCTION
' =======================================================================================

' =======================================================================================
' Loads textures from a resource file for use with OPENGL.
' Parameters:
' * hInstance       = [in]  Instance handle.
' * wszResourceName = [in]  Name of the resource.
' * TextureWidth    = [out] Width of the texture.
' * TextureHeight   = [out] Height of the texture.
' * strTextureData  = [out] The texture data.
' * bInitGdiPlus    = [opt] [in] Initialize GDI Plus
' Return Value:
' * %E_POINTER = One of the parameters is null.
' * ERROR_FILE_NOT_FOUND = File not found.
' * ERROR_INVALID_DATA = Bad image size.
' * A GdiPlus status value.
' =======================================================================================
FUNCTION GdiPlusLoadTextureFromResource ( _
   BYVAL hInstance AS DWORD, _
   BYREF wszResourceName AS WSTRINGZ, _
   BYREF TextureWidth AS LONG, _
   BYREF TextureHeight AS LONG, _
   BYREF strTextureData AS STRING, _
   OPTIONAL BYVAL bInitGdiPlus AS LONG _
   ) AS LONG

   #REGISTER NONE
   REGISTER x AS LONG
   REGISTER y AS LONG

   LOCAL hStatus       AS LONG                  ' // GDI+ status code
   LOCAL token         AS DWORD                 ' // Token to shutdown GDI+
   LOCAL StartupInput  AS GdiplusStartupInput   ' // Structure to initialize GDI+
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
      FUNCTION = %E_POINTER
      EXIT FUNCTION
   END IF

   ' // Initialize GDI+
   IF bInitGdiPlus THEN
      StartupInput.GdiplusVersion = 1
      hStatus = GdiplusStartup(token, StartupInput, BYVAL %NULL)
      IF hStatus THEN
         FUNCTION = hStatus
         EXIT FUNCTION
      END IF
   END IF

   ' // Find the resource and lock it
   hResource = FindResourceW(hInstance, wszResourceName, BYVAL %RT_RCDATA)
   IF hResource = %NULL THEN hStatus = %E_INVALIDARG : GOTO LExit
   imageSize = SizeofResource(hInstance, hResource)
   IF imageSize = 0 THEN hStatus = %E_INVALIDARG : GOTO LExit
   pResourceData = LockResource(LoadResource(hInstance, hResource))
   IF pResourceData = %NULL THEN hStatus = %E_INVALIDARG : GOTO LExit
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
            hStatus = GdipCreateBitmapFromStream(pImageStream, pImage)
            IF hStatus = %StatusOk THEN
               hStatus = GdipGetImageWidth(pImage, TextureWidth)
               hStatus = GdipGetImageHeight(pImage, TextureHeight)
               IF TextureWidth <> TextureHeight THEN
                  hStatus = %ERROR_INVALID_DATA
               ELSE
                   IF IIF&(TALLY(BIN$(TextureWidth), "1") = 1, 1, 0) = %FALSE THEN hStatus = %ERROR_INVALID_DATA
               END IF
               IF hStatus = %StatusOk THEN
                  hStatus = GdipGetImageThumbnail(pImage, TextureWidth, TextureHeight, pThumb, %NULL, %NULL)
                  IF hStatus = %StatusOk THEN
                     hStatus = GdipImageRotateFlip(pThumb, 6) ' 6 = %RotateNoneFlipY
                     IF hStatus = %StatusOk THEN
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

LExit:

   ' // Shutdown GDI+
   IF bInitGdiPlus THEN
      GdiplusShutdown token
   END IF

   FUNCTION = hStatus

END FUNCTION
' =======================================================================================

' ========================================================================================
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
'   Call GetLastError to retrieve the error code.
' Note: This function is used to create GDI+ images from raw data resources. This allows to
' use images other than bitmaps, such PNGs.
' For BITMAP resources, use the GdipCreateBitmapFromResource flat API function.
' *** Do not use as is. The resource image has to be locked while it is being used. ***
' ========================================================================================
'FUNCTION GdiPlusCreateBitmapFromRawDataResource (BYVAL hInstance AS DWORD, BYVAL bstrImage AS WSTRING) AS DWORD

'   LOCAL hStatus       AS LONG                  ' // Status
'   LOCAL token         AS DWORD                 ' // Token to shutdown GDI+
'   LOCAL StartupInput  AS GdiplusStartupInput   ' // Structure to initialize GDI+
'   LOCAL pImage        AS DWORD                 ' // Image handle
'   LOCAL hResource     AS DWORD                 ' // Resource handle
'   LOCAL pResourceData AS DWORD                 ' // Pointer to the resoruce data
'   LOCAL hGlobal       AS DWORD                 ' // Global memory handle
'   LOCAL pGlobalBuffer AS DWORD                 ' // Pointer to global memory buffer
'   LOCAL pImageStream  AS IStream               ' // IStream interface pointer
'   LOCAL imageSize     AS DWORD                 ' // Image size
'   LOCAL wID           AS WORD
'   LOCAL dwID          AS DWORD

'   IF hInstance = 0 THEN EXIT FUNCTION

'   StartupInput.GdiplusVersion = 1
'   hStatus = GdiplusStartup(token, StartupInput, BYVAL %NULL)
'   IF hStatus <> %S_OK THEN EXIT FUNCTION

'   ' // Find the resource and lock it
'   IF LEFT$(bstrImage, 1) = "#" THEN
'      wID = VAL(MID$(bstrImage, 2))
'      dwID = MAK(DWORD, wID, 0)
'      hResource = FindResourceW(hInstance, BYVAL dwID, BYVAL %RT_RCDATA)
'   ELSE
'      hResource = FindResourceW(hInstance, BYCOPY bstrImage, BYVAL %RT_RCDATA)
'   END IF
'   IF hResource = %NULL THEN SetLastError(%E_INVALIDARG) : GOTO LExit
'   imageSize = SizeofResource(hInstance, hResource)
'   IF imageSize = 0 THEN SetLastError(%E_INVALIDARG) : GOTO LExit
'   pResourceData = LockResource(LoadResource(hInstance, hResource))
'   IF pResourceData = %NULL THEN SetLastError(%E_INVALIDARG) : GOTO LExit
'   ' // Allocate memory to hold the image
'   hGlobal = GlobalAlloc(%GMEM_MOVEABLE, imageSize)
'   IF hGlobal THEN
'      ' // Lock the memory
'      pGlobalBuffer = GlobalLock(hGlobal)
'      IF pGlobalBuffer THEN
'         ' // Copy the image from the resource file to global memory
'         CopyMemory pGlobalBuffer, pResourceData, imageSize
'         ' // Create an stream in global memory
'         IF CreateStreamOnHGlobal(hGlobal, %FALSE, pImageStream) = %S_OK THEN
'            ' // Create a bitmap from the data contained in the stream
'            hStatus = GdipCreateBitmapFromStream(pImageStream, pImage)
'            pImageStream = NOTHING
'         END IF
'         ' // Unlock the memory
'         GlobalUnlock pGlobalBuffer
'      END IF
'      ' // Free the memory
'      GlobalFree hGlobal
'   END IF

'LExit:

'   GdiplusShutdown token

'   FUNCTION = pImage

'END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads an image from a file using GDI+, converts it to an icon and returns the icon handle.
' Parameter:
' - bstrFileName = [in] Path of the image to load and convert.
' Return Value:
'   If the function succeeds, the return value is the handle of the created icon.
'   If the function fails, the return value is NULL.
' ========================================================================================
FUNCTION GdiPlusCreateHICONFromFile (BYVAL bstrFileName AS WSTRING) AS DWORD

   LOCAL hStatus AS LONG                       ' // Status
   LOCAL token AS DWORD                        ' // Token to shutdown GDI+
   LOCAL StartupInput AS GdiplusStartupInput   ' // Structure to initialize GDI+
   LOCAL pImage AS DWORD                       ' // Image handle
   LOCAL hIcon AS DWORD                        ' // Icon handle

   StartupInput.GdiplusVersion = 1
   hStatus = GdiplusStartup(token, StartupInput, BYVAL %NULL)
   IF hStatus <> %StatusOk THEN EXIT FUNCTION

   hStatus = GdipLoadImageFromFile(BYCOPY bstrFileName, pImage)
   IF hStatus = %StatusOk THEN
      hStatus = GdipCreateHICONFromBitmap(pImage, hIcon)
      GdipDisposeImage pImage
   END IF
   GdiplusShutdown token

   FUNCTION = hIcon

END FUNCTION
' ========================================================================================

' ========================================================================================
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
'   Call GetLastError to retrieve the error code.
' ========================================================================================
FUNCTION GdiPlusCreateHICONFromResource (BYVAL hInstance AS DWORD, BYVAL bstrImage AS WSTRING) AS DWORD

   LOCAL hStatus AS LONG                        ' // Status
   LOCAL token AS DWORD                         ' // Token to shutdown GDI+
   LOCAL StartupInput AS GdiplusStartupInput    ' // Structure to initialize GDI+
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

   IF hInstance = 0 THEN EXIT FUNCTION

   StartupInput.GdiplusVersion = 1
   hStatus = GdiplusStartup(token, StartupInput, BYVAL %NULL)
   IF hStatus <> %S_OK THEN EXIT FUNCTION

   ' // Find the resource and lock it
   IF LEFT$(bstrImage, 1) = "#" THEN
      wID = VAL(MID$(bstrImage, 2))
      dwID = MAK(DWORD, wID, 0)
      hResource = FindResourceW(hInstance, BYVAL dwID, BYVAL %RT_RCDATA)
   ELSE
      hResource = FindResourceW(hInstance, BYCOPY bstrImage, BYVAL %RT_RCDATA)
   END IF
   IF hResource = %NULL THEN SetLastError(%E_INVALIDARG) : GOTO LExit
   imageSize = SizeofResource(hInstance, hResource)
   IF imageSize = 0 THEN SetLastError(%E_INVALIDARG) : GOTO LExit
   pResourceData = LockResource(LoadResource(hInstance, hResource))
   IF pResourceData = %NULL THEN SetLastError(%E_INVALIDARG) : GOTO LExit
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
            hStatus = GdipCreateBitmapFromStream(pImageStream, pImage)
            IF hStatus = %StatusOk THEN
               IF pImage THEN
                  hStatus = GdipCreateHICONFromBitmap(pImage, hIcon)
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

LExit:

   GdiplusShutdown token

   FUNCTION = hIcon

END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads an image from a file using GDI+, converts it to a bitmap and returns the bitmap handle.
' Parameters:
' - bstrFileName  = [in] Path of the image to load and convert.
' - clrBackground = [in] The background color. This parameter is ignored if the bitmap is totally opaque.
' Return Value:
'   If the function succeeds, the return value is the handle of the created bitmap.
'   If the function fails, the return value is NULL.
' ========================================================================================
FUNCTION GdiPlusCreateHBITMAPFromFile (BYVAL bstrFileName AS WSTRING, BYVAL clrBackground AS DWORD) AS DWORD

   LOCAL hStatus AS LONG                       ' // Status
   LOCAL token AS DWORD                        ' // Token to shutdown GDI+
   LOCAL StartupInput AS GdiplusStartupInput   ' // Structure to initialize GDI+
   LOCAL pImage AS DWORD                       ' // Image handle
   LOCAL hBitmap AS DWORD                      ' // Bitmap handle

   StartupInput.GdiplusVersion = 1
   hStatus = GdiplusStartup(token, StartupInput, BYVAL %NULL)
   IF hStatus <> %StatusOk THEN EXIT FUNCTION

   hStatus = GdipLoadImageFromFile(BYCOPY bstrFileName, pImage)
   IF hStatus = %StatusOk THEN
      hStatus = GdipCreateHBITMAPFromBitmap(pImage, hBitmap, clrBackground)
      GdipDisposeImage pImage
   END IF
   GdiplusShutdown token

   FUNCTION = hBitmap

END FUNCTION
' ========================================================================================

' ========================================================================================
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
'   Call GetLastError to retrieve the error code.
' ========================================================================================
FUNCTION GdiPlusCreateHBITMAPFromResource (BYVAL hInstance AS DWORD, BYVAL bstrImage AS WSTRING, BYVAL clrBackground AS DWORD) AS DWORD

   LOCAL hStatus       AS LONG                  ' // Status
   LOCAL token         AS DWORD                 ' // Token to shutdown GDI+
   LOCAL StartupInput  AS GdiplusStartupInput   ' // Structure to initialize GDI+
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

   IF hInstance = 0 THEN EXIT FUNCTION

   StartupInput.GdiplusVersion = 1
   hStatus = GdiplusStartup(token, StartupInput, BYVAL %NULL)
   IF hStatus <> %S_OK THEN EXIT FUNCTION

   ' // Find the resource and lock it
   IF LEFT$(bstrImage, 1) = "#" THEN
      wID = VAL(MID$(bstrImage, 2))
      dwID = MAK(DWORD, wID, 0)
      hResource = FindResourceW(hInstance, BYVAL dwID, BYVAL %RT_RCDATA)
   ELSE
      hResource = FindResourceW(hInstance, BYCOPY bstrImage, BYVAL %RT_RCDATA)
   END IF
   IF hResource = %NULL THEN SetLastError(%E_INVALIDARG) : GOTO LExit
   imageSize = SizeofResource(hInstance, hResource)
   IF imageSize = 0 THEN SetLastError(%E_INVALIDARG) : GOTO LExit
   pResourceData = LockResource(LoadResource(hInstance, hResource))
   IF pResourceData = %NULL THEN SetLastError(%E_INVALIDARG) : GOTO LExit
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
            hStatus = GdipCreateBitmapFromStream(pImageStream, pImage)
            IF hStatus = %StatusOk THEN
               IF pImage THEN
                  hStatus = GdipCreateHBITMAPFromBitmap(pImage, hBitmap, clrBackground)
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

LExit:

   GdiplusShutdown token

   FUNCTION = hBitmap

END FUNCTION
' ========================================================================================

' ========================================================================================
' Displays the printer dialog and prints the specified image.
' Parameters:
' - wszFileName = The name of the image file to print.
' - bStretch = %TRUE or %FALSE. Stretch the image to paper size.
' - nStretchMode = Stretching mode. Default value = %InterpolationModeHighQualityBicubic.
'   %InterpolationModeLowQuality = 1
'   %InterpolationModeHighQuality = 2
'   %InterpolationModeBilinear = 3
'   %InterpolationModeBicubic = 4
'   %InterpolationModeNearestNeighbor = 5
'   %InterpolationModeHighQualityBilinear = 6
'   %InterpolationModeHighQualityBicubic = 7
' Return Value: Returns %TRUE if the bitmap has been printed successfully, or %FALSE otherwise.
' ========================================================================================
FUNCTION GdiPlusPrintImageDlg(BYREF wszFileName AS WSTRINGZ, OPTIONAL BYVAL bStretch AS LONG, BYVAL nStretchMode AS LONG) AS LONG

   ' // Display te print dialog
   LOCAL hr AS LONG
   LOCAL ppd AS PRINTDLGAPIW
   ppd.lStructSize = SIZEOF(PRINTDLGAPIW)
   ppd.flags = %PD_RETURNDC OR %PD_ALLPAGES OR %PD_NOPAGENUMS OR %PD_NOSELECTION OR %PD_DISABLEPRINTTOFILE
   hr = PrintDlgW(ppd)
   IF hr <> %PD_RESULT_PRINT THEN EXIT FUNCTION

   ' // Initialize GDI+
   LOCAL token AS DWORD
   LOCAL StartupInput AS GdiplusStartupInput
   StartupInput.GdiplusVersion = 1
   hr = GdiplusStartup(token, StartupInput, BYVAL %NULL)
   IF hr THEN GOTO LExit

   ' // Create a graphics object from the printer DC
   LOCAL hStatus AS LONG
   LOCAL pGraphics AS DWORD
   hStatus = GdipCreateFromHDC(ppd.hDc, pGraphics)
   IF hStatus <> %S_OK OR pGraphics = 0 THEN GOTO LExit
   ' // Create a Bitmap object from a file.
   LOCAL pBitmap AS DWORD
   hStatus = GdipCreateBitmapFromFile(wszFileName, pBitmap)
   IF hStatus <> %S_OK OR pBitmap = 0 THEN GOTO LExit
   ' // Get the width and height of the bitmap
   LOCAL nWidth, nHeight AS DWORD
   GdipGetImageWidth(pBitmap, nWidth)
   GdipGetImageHeight(pBitmap, nHeight)

   ' // Stretching
   LOCAL cx, cy AS SINGLE
   IF bStretch THEN
      IF nStretchMode THEN
         ' // Set the interpolation mode
         IF nStretchMode = 0 THEN nStretchMode = %InterpolationModeHighQualityBicubic
         GdipSetInterpolationMode(pGraphics, nStretchMode)
      END IF
      ' // Get the DPIs of the printer
      LOCAL dpiX, dpiY AS SINGLE
      GdipGetDpiX(pGraphics, dpiX)
      GdipGetDpiY(pGraphics, dpiY)
      ' // Calculate the width and height according to the DPIs of the printer
      cx = GetDeviceCaps(ppd.hDc, %HORZRES) / (dpiX / 100)
      cy = GetDeviceCaps(ppd.hDc, %VERTRES) / (dpiY / 100)
   END IF

   ' // How many frame dimensions does the Image object have?
   LOCAL nCount AS LONG
   hStatus = GdipImageGetFrameDimensionsCount(pBitmap, nCount)
   IF nCount THEN
      DIM dimensionIDs(0) AS GUID
      LOCAL frameCount AS DWORD
      ' // Get the list of frame dimensions from the Image object.
      REDIM dimensionIDs(nCount - 1)
      hStatus = GdipImageGetFrameDimensionsList(pBitmap, dimensionIDs(0), nCount)
      ' // Get the number of frames in the first (and only) frame dimension.
      hStatus = GdipImageGetFrameCount(pBitmap, dimensionIDs(0), frameCount)
      IF frameCount = 0 THEN GOTO LExit
   END IF

   ' // Frame dimension page
   LOCAL pageGuid AS GUID
   pageGuid = $FrameDimensionPage

   ' // Print the bitmap
   LOCAL di AS DOCINFOW
   di.cbSize = SIZEOF(DOCINFOW)
   di.lpszDocName = VARPTR(wszFileName)
   hr = StartDocW(ppd.hDc, di)
   IF hr <= 0 THEN GOTO LExit
   LOCAL i, x AS LONG
   FOR i = 1 TO ppd.nCopies
      FOR x = 0 TO frameCount - 1
         IF StartPage(ppd.hDc) THEN
            ' // Select the frame
            hStatus = GdipImageSelectActiveFrame(pBitmap, pageGuid, x)
            ' // Draw the image
            IF bStretch THEN
               hStatus = GdipDrawImageRect(pGraphics, pBitmap, 0, 0, cx, cy)
            ELSE
               hStatus = GdipDrawImage(pGraphics, pBitmap, 0, 0)
            END IF
            EndPage(ppd.hDc)
         END IF
      NEXT
   NEXT
   EndDoc(ppd.hDc)

LExit:

   ' // Cleanup
   IF ppd.hDc THEN DeleteDC(ppd.hDc)
   IF pBitmap THEN GdipDisposeImage(pBitmap)
   IF pGraphics THEN GdipDeleteGraphics(pGraphics)
   ' // Shutdown GDI+
   IF token THEN GdiplusShutdown token

END FUNCTION
' ========================================================================================

' ========================================================================================
' Prints the specified image using the current default printer and printer settings.
' Parameters:
' - wszFileName = The name of the image file to print.
' - bStretch = %TRUE or %FALSE. Stretch the image to paper size.
' - nStretchMode = Stretching mode. Default value = %InterpolationModeHighQualityBicubic.
'   %InterpolationModeLowQuality = 1
'   %InterpolationModeHighQuality = 2
'   %InterpolationModeBilinear = 3
'   %InterpolationModeBicubic = 4
'   %InterpolationModeNearestNeighbor = 5
'   %InterpolationModeHighQualityBilinear = 6
'   %InterpolationModeHighQualityBicubic = 7
' Return Value: Returns %TRUE if the bitmap has been printed successfully, or %FALSE otherwise.
' ========================================================================================
FUNCTION GdiPlusPrintImage (BYREF wszFileName AS WSTRINGZ, OPTIONAL BYVAL bStretch AS LONG, BYVAL nStretchMode AS LONG) AS LONG

   ' // Get the name of the default printer
   LOCAL wszPrinterName AS WSTRINGZ * %MAX_PATH
   GetProfileStringW("WINDOWS", "DEVICE", "", wszPrinterName, SIZEOF(wszPrinterName))
   wszPrinterName = PARSE$(wszPrinterName, 1)
   IF wszPrinterName = "" THEN EXIT FUNCTION

   ' // Open the printer
   LOCAL hPrinter AS DWORD
   IF OpenPrinterW(wszPrinterName, hPrinter, BYVAL %NULL) = 0 THEN EXIT FUNCTION
   ' // Allocate a buffer of the correct size
   LOCAL dwNeeded AS DWORD
   LOCAL bufferDoc AS STRING
   dwNeeded = DocumentPropertiesW(%NULL, hPrinter, wszPrinterName, BYVAL %NULL, BYVAL %NULL, 0)
   bufferDoc = SPACE$(dwNeeded)
   ' // Retrieve the printer configuration data
   LOCAL nRet AS LONG
   nRet = DocumentPropertiesW(%NULL, hPrinter, wszPrinterName, BYVAL STRPTR(bufferDoc), BYVAL %NULL, %DM_OUT_BUFFER)
   IF nRet <> %IDOK THEN GOTO LExit
   ' // Cast it to a DEVMODEW structure
   LOCAL pDevMode AS DEVMODEW PTR
   pDevMode = STRPTR(bufferDoc)
   ' // Create a device context for the printer
   LOCAL hdc AS DWORD
   hdc = CreateDCW(wszPrinterName, wszPrinterName, BYVAL %NULL, BYVAL pDevMode)
   IF hdc = %NULL THEN GOTO LExit

   ' // Initialize GDI+
   LOCAL hr AS LONG
   LOCAL token AS DWORD
   LOCAL StartupInput AS GdiplusStartupInput
   StartupInput.GdiplusVersion = 1
   hr = GdiplusStartup(token, StartupInput, BYVAL %NULL)
   IF hr THEN GOTO LExit

   ' // Create a graphics object from the printer DC
   LOCAL hStatus AS LONG
   LOCAL pGraphics AS DWORD
   hStatus = GdipCreateFromHDC(hdc, pGraphics)
   IF hStatus <> %S_OK OR pGraphics = 0 THEN GOTO LExit
   ' // Create a Bitmap object from a file.
   LOCAL pBitmap AS DWORD
   hStatus = GdipCreateBitmapFromFile(wszFileName, pBitmap)
   IF hStatus <> %S_OK OR pBitmap = 0 THEN GOTO LExit
   ' // Get the width and height of the bitmap
   LOCAL nWidth, nHeight AS DWORD
   GdipGetImageWidth(pBitmap, nWidth)
   GdipGetImageHeight(pBitmap, nHeight)

   ' // Stretching
   LOCAL cx, cy AS SINGLE
   IF bStretch THEN
      IF nStretchMode THEN
         ' // Set the interpolation mode
         IF nStretchMode = 0 THEN nStretchMode = %InterpolationModeHighQualityBicubic
         GdipSetInterpolationMode(pGraphics, nStretchMode)
      END IF
      ' // Get the DPIs of the printer
      LOCAL dpiX, dpiY AS SINGLE
      GdipGetDpiX(pGraphics, dpiX)
      GdipGetDpiY(pGraphics, dpiY)
      ' // Calculate the width and height according to the DPIs of the printer
      cx = GetDeviceCaps(hdc, %HORZRES) / (dpiX / 100)
      cy = GetDeviceCaps(hdc, %VERTRES) / (dpiY / 100)
   END IF

   ' // How many frame dimensions does the Image object have?
   LOCAL nCount AS LONG
   hStatus = GdipImageGetFrameDimensionsCount(pBitmap, nCount)
   IF nCount THEN
      DIM dimensionIDs(0) AS GUID
      LOCAL frameCount AS DWORD
      ' // Get the list of frame dimensions from the Image object.
      REDIM dimensionIDs(nCount - 1)
      hStatus = GdipImageGetFrameDimensionsList(pBitmap, dimensionIDs(0), nCount)
      ' // Get the number of frames in the first (and only) frame dimension.
      hStatus = GdipImageGetFrameCount(pBitmap, dimensionIDs(0), frameCount)
      IF frameCount = 0 THEN GOTO LExit
   END IF

   ' // Frame dimension page
   LOCAL pageGuid AS GUID
   pageGuid = $FrameDimensionPage

   ' // Print the bitmap
   LOCAL di AS DOCINFOW
   di.cbSize = SIZEOF(DOCINFOW)
   di.lpszDocName = VARPTR(wszFileName)
   hr = StartDocW(hdc, di)
   IF hr <= 0 THEN GOTO LExit
   LOCAL i, x AS LONG
   FOR i = 1 TO @pDevMode.dmCopies
      FOR x = 0 TO frameCount - 1
         IF StartPage(hdc) THEN
            ' // Select the frame
            hStatus = GdipImageSelectActiveFrame(pBitmap, pageGuid, x)
            ' // Draw the image
            IF bStretch THEN
               hStatus = GdipDrawImageRect(pGraphics, pBitmap, 0, 0, cx, cy)
            ELSE
               hStatus = GdipDrawImage(pGraphics, pBitmap, 0, 0)
            END IF
            EndPage(hdc)
         END IF
      NEXT
   NEXT
   EndDoc(hdc)

LExit:

   ' // Finished with the printer
   IF hPrinter THEN ClosePrinter(hPrinter)
   ' // Cleanup
   IF hdc THEN DeleteDC(hdc)
   IF pBitmap THEN GdipDisposeImage(pBitmap)
   IF pGraphics THEN GdipDeleteGraphics(pGraphics)
   ' // Shutdown GDI+
   IF token THEN GdiplusShutdown token

END FUNCTION
' ========================================================================================

' ========================================================================================
' Displays the printer dialog and prints the specified resource image.
' Parameters:
' - hInstance = Handle to the instance that contains the resource.
' - wszImageName = The name in the resource file of the image to print.
' - bStretch = %TRUE or %FALSE. Stretch the image to paper size.
' - nStretchMode = Stretching mode. Default value = %InterpolationModeHighQualityBicubic.
'   %InterpolationModeLowQuality = 1
'   %InterpolationModeHighQuality = 2
'   %InterpolationModeBilinear = 3
'   %InterpolationModeBicubic = 4
'   %InterpolationModeNearestNeighbor = 5
'   %InterpolationModeHighQualityBilinear = 6
'   %InterpolationModeHighQualityBicubic = 7
' Return Value: Returns %TRUE if the bitmap has been printed successfully, or %FALSE otherwise.
' ========================================================================================
FUNCTION GdiPlusPrintResourceImageDlg(BYVAL hInstance AS DWORD, BYREF wszImageName AS WSTRINGZ, OPTIONAL BYVAL bStretch AS LONG, BYVAL nStretchMode AS LONG) AS LONG

   IF hInstance = 0 THEN EXIT FUNCTION

   ' // Display te print dialog
   LOCAL hr AS LONG
   LOCAL ppd AS PRINTDLGAPIW
   ppd.lStructSize = SIZEOF(PRINTDLGAPIW)
   ppd.flags = %PD_RETURNDC OR %PD_ALLPAGES OR %PD_NOPAGENUMS OR %PD_NOSELECTION OR %PD_DISABLEPRINTTOFILE
   hr = PrintDlgW(ppd)
   IF hr <> %PD_RESULT_PRINT THEN EXIT FUNCTION

   ' // Initialize GDI+
   LOCAL token AS DWORD
   LOCAL StartupInput AS GdiplusStartupInput
   StartupInput.GdiplusVersion = 1
   hr = GdiplusStartup(token, StartupInput, BYVAL %NULL)
   IF hr THEN GOTO LExit

   ' // Create a graphics object from the printer DC
   LOCAL hStatus AS LONG
   LOCAL pGraphics AS DWORD
   hStatus = GdipCreateFromHDC(ppd.hDc, pGraphics)
   IF hStatus <> %S_OK OR pGraphics = 0 THEN GOTO LExit

   ' // Create a bitmap from the resource image
   LOCAL hResource     AS DWORD                 ' // Resource handle
   LOCAL pResourceData AS DWORD                 ' // Pointer to the resoruce data
   LOCAL hGlobal       AS DWORD                 ' // Global memory handle
   LOCAL pGlobalBuffer AS DWORD                 ' // Pointer to global memory buffer
   LOCAL pImageStream  AS IStream               ' // IStream interface pointer
   LOCAL pBitmap       AS DWORD                 ' // Bitmap object
   LOCAL imageSize     AS DWORD                 ' // Image size
   LOCAL wID           AS WORD
   LOCAL dwID          AS DWORD
   ' // Find the resource and lock it
   IF LEFT$(wszImageName, 1) = "#" THEN
      wID = VAL(MID$(wszImageName, 2))
      dwID = MAK(DWORD, wID, 0)
      hResource = FindResourceW(hInstance, BYVAL dwID, BYVAL %RT_RCDATA)
   ELSE
      hResource = FindResourceW(hInstance, wszImageName, BYVAL %RT_RCDATA)
   END IF
   IF hResource = %NULL THEN GOTO LExit
   imageSize = SizeofResource(hInstance, hResource)
   IF imageSize = 0 THEN GOTO LExit
   pResourceData = LockResource(LoadResource(hInstance, hResource))
   IF pResourceData = %NULL THEN GOTO LExit
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
            hStatus = GdipCreateBitmapFromStream(pImageStream, pBitmap)
            pImageStream = NOTHING
         END IF
      END IF
   END IF
   IF pBitmap = 0 THEN GOTO LExit

   ' // Get the width and height of the bitmap
   LOCAL nWidth, nHeight AS DWORD
   GdipGetImageWidth(pBitmap, nWidth)
   GdipGetImageHeight(pBitmap, nHeight)

   ' // Stretching
   LOCAL cx, cy AS SINGLE
   IF bStretch THEN
      IF nStretchMode THEN
         ' // Set the interpolation mode
         IF nStretchMode = 0 THEN nStretchMode = %InterpolationModeHighQualityBicubic
         GdipSetInterpolationMode(pGraphics, nStretchMode)
      END IF
      ' // Get the DPIs of the printer
      LOCAL dpiX, dpiY AS SINGLE
      GdipGetDpiX(pGraphics, dpiX)
      GdipGetDpiY(pGraphics, dpiY)
      ' // Calculate the width and height according to the DPIs of the printer
      cx = GetDeviceCaps(ppd.hDc, %HORZRES) / (dpiX / 100)
      cy = GetDeviceCaps(ppd.hDc, %VERTRES) / (dpiY / 100)
   END IF

   ' // How many frame dimensions does the Image object have?
   LOCAL nCount AS LONG
   hStatus = GdipImageGetFrameDimensionsCount(pBitmap, nCount)
   IF nCount THEN
      DIM dimensionIDs(0) AS GUID
      LOCAL frameCount AS DWORD
      ' // Get the list of frame dimensions from the Image object.
      REDIM dimensionIDs(nCount - 1)
      hStatus = GdipImageGetFrameDimensionsList(pBitmap, dimensionIDs(0), nCount)
      ' // Get the number of frames in the first (and only) frame dimension.
      hStatus = GdipImageGetFrameCount(pBitmap, dimensionIDs(0), frameCount)
      IF frameCount = 0 THEN GOTO LExit
   END IF

   ' // Frame dimension page
   LOCAL pageGuid AS GUID
   pageGuid = $FrameDimensionPage

   ' // Print the bitmap
   LOCAL di AS DOCINFOW
   di.cbSize = SIZEOF(DOCINFOW)
   di.lpszDocName = VARPTR(wszImageName)
   hr = StartDocW(ppd.hDc, di)
   IF hr <= 0 THEN GOTO LExit
   LOCAL i, x AS LONG
   FOR i = 1 TO ppd.nCopies
      FOR x = 0 TO frameCount - 1
         IF StartPage(ppd.hDc) THEN
            ' // Select the frame
            hStatus = GdipImageSelectActiveFrame(pBitmap, pageGuid, x)
            ' // Draw the image
            IF bStretch THEN
               hStatus = GdipDrawImageRect(pGraphics, pBitmap, 0, 0, cx, cy)
            ELSE
               hStatus = GdipDrawImage(pGraphics, pBitmap, 0, 0)
            END IF
            EndPage(ppd.hDc)
         END IF
      NEXT
   NEXT
   EndDoc(ppd.hDc)

LExit:

   ' // Cleanup
   IF ppd.hDc THEN DeleteDC(ppd.hDc)
   IF pBitmap THEN GdipDisposeImage(pBitmap)
   IF pGraphics THEN GdipDeleteGraphics(pGraphics)
   ' // Unlock and free the global memory
   IF pGlobalBuffer THEN GlobalUnlock(pGlobalBuffer)
   IF hGlobal THEN GlobalFree(hGlobal)
   ' // Shutdown GDI+
   IF token THEN GdiplusShutdown token

END FUNCTION
' ========================================================================================

' ========================================================================================
' Prints the specified resource image using the current default printer and printer settings.
' Parameters:
' - hInstance = Handle to the instance that contains the resource.
' - wszImageName = The name in the resource file of the image to print.
' - bStretch = %TRUE or %FALSE. Stretch the image to paper size.
' - nStretchMode = Stretching mode. Default value = %InterpolationModeHighQualityBicubic.
'   %InterpolationModeLowQuality = 1
'   %InterpolationModeHighQuality = 2
'   %InterpolationModeBilinear = 3
'   %InterpolationModeBicubic = 4
'   %InterpolationModeNearestNeighbor = 5
'   %InterpolationModeHighQualityBilinear = 6
'   %InterpolationModeHighQualityBicubic = 7
' Return Value: Returns %TRUE if the bitmap has been printed successfully, or %FALSE otherwise.
' ========================================================================================
FUNCTION GdiPlusPrintResourceImage(BYVAL hInstance AS DWORD, BYREF wszImageName AS WSTRINGZ, OPTIONAL BYVAL bStretch AS LONG, BYVAL nStretchMode AS LONG) AS LONG

   ' // Get the name of the default printer
   LOCAL wszPrinterName AS WSTRINGZ * %MAX_PATH
   GetProfileStringW("WINDOWS", "DEVICE", "", wszPrinterName, SIZEOF(wszPrinterName))
   wszPrinterName = PARSE$(wszPrinterName, 1)
   IF wszPrinterName = "" THEN EXIT FUNCTION

   ' // Open the printer
   LOCAL hPrinter AS DWORD
   IF OpenPrinterW(wszPrinterName, hPrinter, BYVAL %NULL) = 0 THEN EXIT FUNCTION
   ' // Allocate a buffer of the correct size
   LOCAL dwNeeded AS DWORD
   LOCAL bufferDoc AS STRING
   dwNeeded = DocumentPropertiesW(%NULL, hPrinter, wszPrinterName, BYVAL %NULL, BYVAL %NULL, 0)
   bufferDoc = SPACE$(dwNeeded)
   ' // Retrieve the printer configuration data
   LOCAL nRet AS LONG
   nRet = DocumentPropertiesW(%NULL, hPrinter, wszPrinterName, BYVAL STRPTR(bufferDoc), BYVAL %NULL, %DM_OUT_BUFFER)
   IF nRet <> %IDOK THEN GOTO LExit
   ' // Cast it to a DEVMODEW structure
   LOCAL pDevMode AS DEVMODEW PTR
   pDevMode = STRPTR(bufferDoc)
   ' // Create a device context for the printer
   LOCAL hdc AS DWORD
   hdc = CreateDCW(wszPrinterName, wszPrinterName, BYVAL %NULL, BYVAL pDevMode)
   IF hdc = %NULL THEN GOTO LExit

   ' // Initialize GDI+
   LOCAL hr AS LONG
   LOCAL token AS DWORD
   LOCAL StartupInput AS GdiplusStartupInput
   StartupInput.GdiplusVersion = 1
   hr = GdiplusStartup(token, StartupInput, BYVAL %NULL)
   IF hr THEN GOTO LExit

   ' // Create a graphics object from the printer DC
   LOCAL hStatus AS LONG
   LOCAL pGraphics AS DWORD
   hStatus = GdipCreateFromHDC(hdc, pGraphics)
   IF hStatus <> %S_OK OR pGraphics = 0 THEN GOTO LExit

   ' // Create a bitmap from the resource image
   LOCAL hResource     AS DWORD                 ' // Resource handle
   LOCAL pResourceData AS DWORD                 ' // Pointer to the resoruce data
   LOCAL hGlobal       AS DWORD                 ' // Global memory handle
   LOCAL pGlobalBuffer AS DWORD                 ' // Pointer to global memory buffer
   LOCAL pImageStream  AS IStream               ' // IStream interface pointer
   LOCAL pBitmap       AS DWORD                 ' // Bitmap object
   LOCAL imageSize     AS DWORD                 ' // Image size
   LOCAL wID           AS WORD
   LOCAL dwID          AS DWORD
   ' // Find the resource and lock it
   IF LEFT$(wszImageName, 1) = "#" THEN
      wID = VAL(MID$(wszImageName, 2))
      dwID = MAK(DWORD, wID, 0)
      hResource = FindResourceW(hInstance, BYVAL dwID, BYVAL %RT_RCDATA)
   ELSE
      hResource = FindResourceW(hInstance, wszImageName, BYVAL %RT_RCDATA)
   END IF
   IF hResource = %NULL THEN GOTO LExit
   imageSize = SizeofResource(hInstance, hResource)
   IF imageSize = 0 THEN GOTO LExit
   pResourceData = LockResource(LoadResource(hInstance, hResource))
   IF pResourceData = %NULL THEN GOTO LExit
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
            hStatus = GdipCreateBitmapFromStream(pImageStream, pBitmap)
            pImageStream = NOTHING
         END IF
      END IF
   END IF
   IF pBitmap = 0 THEN GOTO LExit

   ' // Get the width and height of the bitmap
   LOCAL nWidth, nHeight AS DWORD
   GdipGetImageWidth(pBitmap, nWidth)
   GdipGetImageHeight(pBitmap, nHeight)

   ' // Stretching
   LOCAL cx, cy AS SINGLE
   IF bStretch THEN
      IF nStretchMode THEN
         ' // Set the interpolation mode
         IF nStretchMode = 0 THEN nStretchMode = %InterpolationModeHighQualityBicubic
         GdipSetInterpolationMode(pGraphics, nStretchMode)
      END IF
      ' // Get the DPIs of the printer
      LOCAL dpiX, dpiY AS SINGLE
      GdipGetDpiX(pGraphics, dpiX)
      GdipGetDpiY(pGraphics, dpiY)
      ' // Calculate the width and height according to the DPIs of the printer
      cx = GetDeviceCaps(hdc, %HORZRES) / (dpiX / 100)
      cy = GetDeviceCaps(hdc, %VERTRES) / (dpiY / 100)
   END IF

   ' // How many frame dimensions does the Image object have?
   LOCAL nCount AS LONG
   hStatus = GdipImageGetFrameDimensionsCount(pBitmap, nCount)
   IF nCount THEN
      DIM dimensionIDs(0) AS GUID
      LOCAL frameCount AS DWORD
      ' // Get the list of frame dimensions from the Image object.
      REDIM dimensionIDs(nCount - 1)
      hStatus = GdipImageGetFrameDimensionsList(pBitmap, dimensionIDs(0), nCount)
      ' // Get the number of frames in the first (and only) frame dimension.
      hStatus = GdipImageGetFrameCount(pBitmap, dimensionIDs(0), frameCount)
      IF frameCount = 0 THEN GOTO LExit
   END IF

   ' // Frame dimension page
   LOCAL pageGuid AS GUID
   pageGuid = $FrameDimensionPage

   ' // Print the bitmap
   LOCAL di AS DOCINFOW
   di.cbSize = SIZEOF(DOCINFOW)
   di.lpszDocName = VARPTR(wszImageName)
   hr = StartDocW(hdc, di)
   IF hr <= 0 THEN GOTO LExit
   LOCAL i, x AS LONG
   FOR i = 1 TO @pDevMode.dmCopies
      FOR x = 0 TO frameCount - 1
         IF StartPage(hdc) THEN
            ' // Select the frame
            hStatus = GdipImageSelectActiveFrame(pBitmap, pageGuid, x)
            ' // Draw the image
            IF bStretch THEN
               hStatus = GdipDrawImageRect(pGraphics, pBitmap, 0, 0, cx, cy)
            ELSE
               hStatus = GdipDrawImage(pGraphics, pBitmap, 0, 0)
            END IF
            EndPage(hdc)
         END IF
      NEXT
   NEXT
   EndDoc(hdc)

LExit:

   ' // Finished with the printer
   IF hPrinter THEN ClosePrinter(hPrinter)
   ' // Cleanup
   IF hdc THEN DeleteDC(hdc)
   IF pBitmap THEN GdipDisposeImage(pBitmap)
   IF pGraphics THEN GdipDeleteGraphics(pGraphics)
   ' // Unlock and free the global memory
   IF pGlobalBuffer THEN GlobalUnlock(pGlobalBuffer)
   IF hGlobal THEN GlobalFree(hGlobal)
   ' // Shutdown GDI+
   IF token THEN GdiplusShutdown token

END FUNCTION
' ========================================================================================
