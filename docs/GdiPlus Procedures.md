# GdiPlus Procedures

Assorted GDI+ helper procedures.

**Include File**: AfxGdiPlus.inc.

| Name       | Description |
| ---------- | ----------- |
| [AfxGdipAddIconFromFile](#AfxGdipAddIconFromFile) | Loads an image from a file, converts it to an icon and adds it to specified image list. |
| [AfxGdipAddIconFromRes](#AfxGdipAddIconFromRes) | Loads an image from a resource file, converts it to an icon and adds it to specified image list. |
| [AfxGdipBitmapFromBuffer](#AfxGdipBitmapFromBuffer) | Converts an image stored in a buffer into a bitmap and returns the handle. |
| [AfxGdipBitmapFromFile](#AfxGdipBitmapFromFile) | Loads an image from a file, converts it to a bitmap and returns the handle. |
| [AfxGdipBitmapFromRes](#AfxGdipBitmapFromRes) | Loads an image from a resource, converts it to a bitmap and returns the handle. |
| [AfxGdipDllVersion](#AfxGdipDllVersion) | Returns the version of Gdiplus.dll, e.g. 601 for version 6.01. |
| [AfxGdipGetEncoderClsid](#AfxGdipGetEncoderClsid) | Retrieves the encoder's clsid. |
| [AfxGdipGetImageSizeFromFile](#AfxGdipGetImageSizeFromFile) | Returns the size of the image. |
| [AfxGdipIconFromBuffer](#AfxGdipIconFromBuffer) | Converts an image stored in a buffer into an icon and returns the handle. |
| [AfxGdipIconFromFile](#AfxGdipIconFromFile) | Loads an image from a file, converts it to an icon and returns the handle. |
| [AfxGdipIconFromRes](#AfxGdipIconFromRes) | Loads an image from a resource, converts it to an icon and returns the handle. |
| [AfxGdipImageFromBuffer](#AfxGdipImageFromBuffer) | Converts an image stored in a buffer into an icon or bitmap and returns the handle. |
| [AfxGdipImageFromFile](#AfxGdipImageFromFile) | Loads an image from a file, converts it to an icon or bitmap and returns the handle. |
| [AfxGdipImageFromFile2](#AfxGdipImageFromFile2) | Loads an image from a file using GDI+, converts it to an icon or bitmap and returns the handle. |
| [AfxGdipImageFromRes](#AfxGdipImageFromRes) | Loads an image from a resource, converts it to an icon or bitmap and returns the handle. |
| [AfxGdipInit](#AfxGdipInit) | Initializes GDI+. |
| [AfxGdipLoadTexture](#AfxGdipLoadTexture) | Loads an image from disk or a resource an converts it to a texture for use with OpenGL. |
| [AfxGdipPrintHBITMAP](#AfxGdipPrintHBITMAP) | Prints a Windows bitmap in the default printer. |
| [AfxGdipSaveHBITMAPToFile](#AfxGdipSaveHBITMAPToFile) | Saves a Windows bitmap to file. |
| [AfxGdipSaveImageToFile](#AfxGdipSaveImageToFile) | Saves a GDI+ image to file. |
| [AfxGdipShutdown](#AfxGdipShutdown) | Cleans up resources used by Windows GDI+. Each call to **GdiplusStartup** should be paired with a call to **GdiplusShutdown**. |
| [GDIP_ARGB](#GDIP_ARGB) | Returns an ARGB color value initialized with the specified values for the alpha, red, green, and blue components. |
| [GDIP_BGRA](#GDIP_BGRA) | Returns a BGRA color value initialized with the specified values for the blue, green, red and alpha components. |
| [GDIP_COLOR](#GDIP_COLOR) | Returns an ARGB color value initialized with the specified values for the alpha, red, green, and blue components. |
| [GDIP_GetAlpha](#GDIP_GetAlpha) | Returns the alpha component of an ARGB color value. |
| [GDIP_GetBlue](#GDIP_GetBlue) | Returns the blue component of an ARGB color value. |
| [GDIP_GetGreen](#GDIP_GetGreen) | Returns the green component of an ARGB color value. |
| [GDIP_GetRed](#GDIP_GetRed) | Returns the red component of an ARGB color value. |
| [GDIP_POINT](#GDIP_POINT) | Returns a GpPoint color value initialized with the specified values for the x and y coordinates. |
| [GDIP_POINTF](#GDIP_POINTF) | Returns a GpPointF color value initialized with the specified values for the x and y coordinates. |
| [GDIP_RGBA](#GDIP_RGBA) | Returns a RGBA color value initialized with the specified values for the red, green, blue and alpha components. |
| [GDIP_RECT](#GDIP_RECT) | Returns a GpRect structure initialized with the specified values for the x, y, width, and height components. |
| [GDIP_RECTF](#GDIP_RECTF) | Returns a GpRectF structrure initialized with the specified values for the x, y, width, and height components. |
| [GDIP_XRGB](#GDIP_XRGB) | Returns a XRGB color value initialized with the specified values for the red, green, and blue components. |
