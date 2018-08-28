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

# <a name="AfxGdipAddIconFromFile"></a>AfxGdipAddIconFromFile

Loads an image from a file, converts it to an icon and adds it to specified image list.

```
FUNCTION AfxGdipAddIconFromFile (BYVAL hIml AS HIMAGELIST, BYREF wszFileName AS WSTRING, _
   BYVAL dimPercent AS LONG = 0, BYVAL bGrayScale AS LONG = FALSE) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hIml* | Handle to the image list. |
| *wszFileName* | Path of the image to load and convert. |
| *dimPercent* | Optional. Percent of dimming (1-99). |
| *bGrayScale* | Optional. TRUE or FALSE. Convert to gray scale. |

#### Return value

Returns the index of the image if successful, or -1 otherwise.

# <a name="AfxGdipAddIconFromRes"></a>AfxGdipAddIconFromRes

Loads an image from a resource file, converts it to an icon and adds it to specified image list.

```
FUNCTION AfxGdipAddIconFromRes (BYVAL hIml AS HIMAGELIST, BYVAL hInstance AS HINSTANCE, _
   BYREF wszFileName AS WSTRING, BYVAL dimPercent AS LONG = 0, BYVAL bGrayScale AS LONG = FALSE) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *hIml* | Handle to the image list. |
| *hInstance* | A handle to the module whose portable executable file or an accompanying MUI file contains the resource. If this parameter is NULL, the function searches the module used to create the current process. |
| *wszFileName* | Path of the image to load and convert. |
| *dimPercent* | Optional. Percent of dimming (1-99). |
| *bGrayScale* | Optional. TRUE or FALSE. Convert to gray scale. |

#### Return value

Returns the index of the image if successful, or -1 otherwise.

# <a name="AfxGdipBitmapFromBuffer"></a>AfxGdipBitmapFromBuffer

Converts an image stored in a buffer into a bitmap and returns the handle.

```
FUNCTION AfxGdipBitmapFromBuffer (BYVAL pBuffer AS ANY PTR, BYVAL bufferSize AS SIZE_T_, _
   BYVAL dimPercent AS LONG = 0, BYVAL bGrayScale AS LONG = FALSE, BYVAL clrBkg AS ARGB = 0) AS HANDLE
```

| Parameter  | Description |
| ---------- | ----------- |
| *pBuffer* | Pointer to the buffer. |
| *bufferSize* | Size of the buffer |
| *dimPercent* | Optional. Percent of dimming (1-99). |
| *bGrayScale* | Optional. TRUE or FALSE. Convert to gray scale. |
| *clrBkg* | Optional. The background color. This parameter is ignored if the image is totally opaque. |

#### Return value

If the function succeeds, the return value is the handle of the created icon or bitmap.

If the function fails, the return value is NULL.

# <a name="AfxGdipBitmapFromFile"></a>AfxGdipBitmapFromFile

Loads an image from a file, converts it to a bitmap and returns the handle.

```
FUNCTION AfxGdipBitmapFromFile (BYREF wszFileName AS WSTRING, BYVAL dimPercent AS LONG = 0, _
   BYVAL bGrayScale AS LONG = FALSE, BYVAL clrBkg AS ARGB = 0) AS HANDLE
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFileName* | Path of the image to load and convert. |
| *dimPercent* | Optional. Percent of dimming (1-99). |
| *bGrayScale* | Optional. TRUE or FALSE. Convert to gray scale. |
| *clrBkg* | Optional. The background color. This parameter is ignored if the image is totally opaque. |

#### Return value

If the function succeeds, the return value is the handle of the created bitmap.

If the function fails, the return value is NULL.

# <a name="AfxGdipBitmapFromRes"></a>AfxGdipBitmapFromRes

Loads an image from a resource, converts it to a bitmap and returns the handle.

```
FUNCTION AfxGdipBitmapFromRes (BYVAL hInstance AS HINSTANCE, BYREF wszImageName AS WSTRING, _
   BYVAL dimPercent AS LONG = 0, BYVAL bGrayScale AS LONG = FALSE, BYVAL clrBkg AS ARGB = 0) AS HANDLE
```

| Parameter  | Description |
| ---------- | ----------- |
| *hInstance* | A handle to the module whose portable executable file or an accompanying MUI file contains the resource. If this parameter is NULL, the function searches the module used to create the current process. |
| *wszFileName* | Name of the image in the resource file (.RES). If the image resource uses an integral identifier, wszImage should begin with a number symbol (#) followed by the identifier in an ASCII format, e.g., "#998". Otherwise, use the text identifier name for the image. Only images embedded as raw data (type RCDATA) are valid. These must be icons in format .png, .jpg, .gif, .tiff. |
| *dimPercent* | Optional. Percent of dimming (1-99). |
| *bGrayScale* | Optional. TRUE or FALSE. Convert to gray scale. |
| *clrBkg* | Optional. The background color. This parameter is ignored if the image is totally opaque. |

#### Return value

If the function succeeds, the return value is the handle of the created bitmap.

If the function fails, the return value is NULL.

# <a name="AfxGdipDllVersion"></a>AfxGdipDllVersion

Returns the version of Gdiplus.dll, e.g. 601 for version 6.01.

```
FUNCTION AfxGdipDllVersion () AS LONG
```

# <a name="AfxGdipGetEncoderClsid"></a>AfxGdipGetEncoderClsid

Retrieves the encoder's clsid.

```
FUNCTION AfxGdipGetEncoderClsid (BYREF wszMimeType AS WSTRING) AS GUID
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszMimeType* | The mime type. |

# <a name="AfxGdipGetImageSizeFromFile"></a>AfxGdipGetImageSizeFromFile

Returns the size of the image.

```
FUNCTION AfxGdipGetImageSizeFromFile (BYREF wszFileName AS WSTRING, BYVAL nWidth AS DWORD PTR, _
   BYVAL nHeight AS DWORD PTR) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFileName* | The filename path. |
| *nWidth* | Pointer to a DWORD variable that will receive the width, in pixels, of the image. |
| *nHeight* | Pointer to a DWORD variable that will receive the height, in pixels, of the image. |

#### Return value

If the function succeeds, it returns Ok, which is an element of the Status enumeration.

If the function fails, it returns one of the other elements of the Status enumeration.

# <a name="AfxGdipIconFromBuffer"></a>AfxGdipIconFromBuffer

Converts an image stored in a buffer into an icon and returns the handle.

```
FUNCTION AfxGdipIconFromBuffer (BYVAL pBuffer AS ANY PTR, BYVAL bufferSize AS SIZE_T_, _
   BYVAL dimPercent AS LONG = 0, BYVAL bGrayScale AS LONG = FALSE) AS HANDLE
```

| Parameter  | Description |
| ---------- | ----------- |
| *pBuffer* | Pointer to the buffer. |
| *bufferSize* | Size of the buffer |
| *dimPercent* | Optional. Percent of dimming (1-99). |
| *bGrayScale* | Optional. TRUE or FALSE. Convert to gray scale. |

#### Return value

If the function succeeds, the return value is the handle of the created icon.

If the function fails, the return value is NULL.

# <a name="AfxGdipIconFromFile"></a>AfxGdipIconFromFile

Loads an image from a file, converts it to an icon and returns the handle.

```
FUNCTION AfxGdipIconFromFile (BYREF wszFileName AS WSTRING, BYVAL dimPercent AS LONG = 0, _
   BYVAL bGrayScale AS LONG = FALSE) AS HANDLE
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszFileName* | Path of the image to load and convert. |
| *dimPercent* | Optional. Percent of dimming (1-99). |
| *bGrayScale* | Optional. TRUE or FALSE. Convert to gray scale. |

#### Return value

If the function succeeds, the return value is the handle of the created icon.

If the function fails, the return value is NULL.
