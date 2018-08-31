# GdiPlus

GDI+ is the successor to GDI, the graphics device interface included with earlier versions of Windows. Windows XP or Windows .NET Server supports GDI for compatibility with existing applications, but programmers of new applications should use GDI+ for all their graphics needs because GDI+ optimizes many of the capabilities of GDI and also provides additional features.

A graphics device interface, such as GDI+, allows application programmers to display information on a screen or printer without having to be concerned about the details of a particular display device. The application programmer makes calls to the provided functions and those functions in turn make the appropriate calls to specific device drivers. GDI+ insulates the application from the graphics hardware, and it is this insulation that allows developers to create device-independent applications.

**Include file**: CGdiPlus.inc.

# CGpBase class

Initializes the GDI+ library and keeps a reference count of it. The destructor shutdowns the library. All the other GDI+ classes inherit frrom CGpBase.

### GetLastStatus method

Returns a value that indicates the nature of this object's most recent method failure.

```
FUNCTION GetLastStatus () AS GpStatus
```

#### Return value

Returns an element of the **Status** enumeration.

If no methods invoked on this object have failed since the previous call to GetLastStatus, then GetLastStatus returns **Ok** (0). If at least one method has failed since the previous call to GetLastStatus, then GetLastStatus returns a value that indicates the nature of the most recent failure.

For a detailed list of status codes see the **Status** enumeration.

# Structures

| Name       | Description |
| ---------- | ----------- |
| [BitmapData](#BitmapData) | Stores attributes of a bitmap. |
| [CharacterRange](#CharacterRange) | Specifies a range of character positions within a string. |
| [ColorMap](#ColorMap) | Contains two COLORREF values. |
| [ColorMatrix](#ColorMatrix) | Contains a 5x5 matrix of real numbers. |
| [ColorPalette](#ColorPalette) | Defines an array of colors that make up a color palette. |
| [EncoderParameter](#EncoderParameter) | Holds a parameter that can be passed to an image encoder. |
| [EncoderParameters](#EncoderParameters) | Holds array of **EncoderParameter** structures. |
| [ENHMETAHEADER3](#ENHMETAHEADER3) | Contains enhanced-metafile data. |
| [GdiplusStartupInput](#GdiplusStartupInput) | Holds a block of arguments that are required by the GdiplusStartup function. |
| [GdiplusStartupOutput](#GdiplusStartupOutput) | Uses the **GdiplusStartupOutput** structure to return (in its output parameter) a pointer to a hook function and a pointer to an unhook function. |
| [GpPathData](#GpPathData) | Used to get or set the data points (and their types) of a path. |
| [GpPoint](#GpPoint) | Defines the x- and y-coordinates of a point. |
| [GpPointF](#GpPointF) | Defines the x- and y-coordinates of a point. |
| [GpRect](#GpRect) | Defines the upper-left corner, width, and height of a rectangle. |
| [GpRectF](#GpRectF) | Defines the upper-left corner, width, and height of a rectangle. |
| [GpSize](#GpSize) | Encapsulates a Width and Height dimension in a 2-D coordinate system. |
| [GpSizeF](#GpSizeF) | Encapsulates a Width and Height dimension in a 2-D coordinate system. |
| [ImageCodecInfo](#ImageCodecInfo) | Stores information about an image codec. |
| [LOGFONTA](#LOGFONTA) | Defines the attributes of a font. |
| [LOGFONTW](#LOGFONTW) | Defines the attributes of a font. |
| [MetafileHeader](#MetafileHeader) | Stores properties of an associated metafile. |
| [PropertyItem](#PropertyItem) | Holds one piece of image metadata. |
| [PWMFRect16](#PWMFRect16) | Defines a rectangle that bounds a placeable metafile. |
| [WmfPlaceableFileHeader](#WmfPlaceableFileHeader) | Defines the fields of a placeable metafile header. |

# Enumerations

| Name       | Description |
| ---------- | ----------- |
| [BrushType](#BrushType) | Indicates the type of brush. |
| [Color](#Color) | Predefined ARGB colors. |
| [ColorAdjustType](#ColorAdjustType) | Specifies which GDI+ objects use color-adjustment information. |
| [ColorChannelFlags](#ColorChannelFlags) | Specifies individual channels in the CMYK (cyan, magenta, yellow, black) color space. |
| [ColorMatrixFlags](#ColorMatrixFlags) | Specifies the types of images and colors that will be affected by the color and grayscale adjustment settings. |
| [ColorMode](#ColorMode) | ColorModeARGB32 = 0, ColorModeARGB64 = 1. |
| [CombineMode](#CombineMode) | Specifies how a new region is combined with an existing region. |
| [CompositingMode](#CompositingMode) | Specifies how rendered colors are combined with background colors. |
| [CompositingQuality](#CompositingQuality) | Specifies whether gamma correction is applied when colors are blended with background colors. |
| [CoordinateSpace](#CoordinateSpace) | Specifies coordinate spaces. |
| [CustomLineCapType](#CustomLineCapType) | CustomLineCapTypeDefault = 0, CustomLineCapTypeAdjustableArrow = 1. |
| [DashCap](#DashCap) | Specifies the type of graphic shape to use on both ends of each dash in a dashed line. |
| [DashStyle](#DashStyle) | Specifies the line style of a line drawn with a Microsoft Windows GDI+ pen. |
| [DriverStringOptions](#DriverStringOptions) | Sècifies the spacing, orientation, and quality of the rendering for driver strings. |
| [EmfPlusRecordType](#EmfPlusRecordType) | Identifies metafile record types used in Microsoft Windows Metafile Format (WMF), Enhanced Metafile (EMF), and EMF+ files. |
| [EmfToWmfBitsFlags](#EmfToWmfBitsFlags) | Specifies options for the **GdipEmfToWmfBits** method, which converts an Enhanced Metafile (EMF) metafile to a Microsoft Windows Metafile Format (WMF) metafile. |
| [EmfType](#EmfType) | Specifies the nature of the records that are placed in an Enhanced Metafile (EMF) file. |
| [EncoderParameterValueType](#EncoderParameterValueType) | Specifies data types for image codec (encoder/decoder) parameters. |
| [EncoderValue](#EncoderValue) | Specifies values that can be passed as arguments to image encoders. |
| [FillMode](#FillMode) | Specifies how to fill areas that are formed when a path or curve intersects itself. |
| [FlushIntention](#FlushIntention) | Specifies when to flush the queue of graphics operations. |
| [FontStyle](#FontStyle) | Specifies the style of the typeface of a font. Styles can be combined. |
| [GenericFontFamily](#GenericFontFamily) | GenericFontFamilySerif = 0, GenericFontFamilySansSerif = 1, GenericFontFamilyMonospace = 2. |
| [HatchStyle](#HatchStyle) | Specifies the hatch pattern used by a brush of type **HatchBrush**. |
| [HistogramFormat](#HistogramFormat) | Specifies the number and type of histograms that represent the color channels of a bitmap. |
| [HotkeyPrefix](#HotkeyPrefix) | Specifies how to display hot keys. |
| [ImageFlags](#ImageFlags) | Specifies the attributes of the pixel data contained in an image. |
| [ImageLockMode](#ImageLockMode) | Specifies flags that are passed to the flags parameter of the **GdipBitmapLockBits** function. |
| [ImageType](#ImageType) | Indicates whether an image is a bitmap or a metafile. |
| [InterpolationMode](#InterpolationMode) | Specifies the algorithm that is used when images are scaled or rotated. |
| [ItemDataPosition](#ItemDataPosition) | Specifies the location of custom metadata in an image file. |
| [LinearGradientMode](#LinearGradientMode) | Specifies the direction in which the change of color occurs for a linear gradient brush. |
| [LineCap](#LineCap) | Specifies the type of graphic shape to use on the end of a line drawn with a Microsoft Windows GDI+ pen. |
| [LineJoin](#LineJoin) | Specifies how to join two lines that are drawn by the same pen and whose ends meet. |
| [MatrixOrder](#MatrixOrder) | Specifies the order of multiplication when a new matrix is multiplied by an existing matrix. |
| [MetafileFrameUnit](#MetafileFrameUnit) | Specifies the unit of measure for a metafile frame rectangle. |
| [MetafileType](#MetafileType) | Specifies types of metafiles. |
| [ObjectType](#ObjectType) | Indicates the object type value of an EMF+ record. |
| [PaletteFlags](#PaletteFlags) | Indicates attributes of the color data in a palette. |
| [PaletteType](#PaletteType) | Identify several standard color palette formats. |
| [PathPointType](#PathPointType) | Indicates point types and flags for the data points in a path. |
| [PenAlignment](#PenAlignment) | Specifies the alignment of a pen relative to the stroke that is being drawn. |
| [PenType](#PenType) | Indicates the type of pattern, texture, or gradient that a pen draws. |
| [PixelOffsetMode](#PixelOffsetMode) | Specifies the pixel offset mode. |
| [QualityMode](#QualityMode) | Specifies the quality mode. |
| [RotateFlipType](#RotateFlipType) | Specifies the direction of an image's rotation and the axis used to flip the image. |
| [SmoothingMode](#SmoothingMode) | Specifies the type of smoothing (antialiasing) that is applied to lines and curves. |
| [Status](#Status) | Indicates the result of a Microsoft Windows GDI+ function call. |
| [StringAlignment](#StringAlignment) | Specifies how a string is aligned in reference to the bounding rectangle. |
| [StringDigitSubstitute](#StringDigitSubstitute) | Specifies how to substitute digits in a string according to a user's locale or language. |
| [StringFormatFlags](#StringFormatFlags) | Specifies text layout information (such as orientation and clipping) and display manipulations (such as ellipsis insertion, digit substitution, and representation of characters that are not supported by a font). |
| [StringTrimming](#StringTrimming) | Specifies how to trim characters from a string so that the string fits into a layout rectangle. |
| [TestControl](#TestControl) | TestControlForceBilinear = 0, TestControlNoICM = 1, TestControlGetBuildNumber = 2. |
| [TextRenderingHint](#TextRenderingHint) | Specifies the process used to render text. |
| [Unit](#Unit) | Specifies the unit of measure for a given data type. |
| [WarpMode](#WarpMode) | Specifies warp modes that can be used to transform images. |
| [WrapMode](#WrapMode) | Specifies how repeated copies of an image are used to tile an area. |

# Constants

| Name       | Description |
| ---------- | ----------- |
| [Image Encoder Constants](#Constants1) | GUIDs that specify the various parameter categories of the **EncodeParameter** objects. |
| [Image File Format Constants](#Constants2) | GUIDs that specify the that identify the file formats of an image. |
| [Image Frame Dimension Constants](#Constants3) | GUIDs that identify the page and time dimensions. |
| [Image Pixel Format Constants](#Constants4) | Pixel formats used in bitmaps. |
| [Image Property Tag Type Constants](#Constants5) | Specifies the data type of the values stored in the value data member of a **PropertyItem** structure. |
| [Image Property Tag Constants](#Constants6) | Property items supported by Microsoft Windows GDI+. |

# <a name="BitmapData"></a>BitmapData Structure

A **BitmapData** structure stores attributes of a bitmap. Used by the **GdipBitmapLockBits** and **GdipBitmapUnlockBits** functions.

```
TYPE BitmapData
   Width AS UINT
   Height AS UINT
   Stride AS INT_
   PixelFormat AS PixelFormat
   Scan0 AS ANY PTR
   Reserved AS UINT_PTR
END TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **Width** | Number of pixels in one scan line of the bitmap. |
| **Height** | Number of scan lines in the bitmap. |
| **Stride** | Offset, in bytes, between consecutive scan lines of the bitmap. If the stride is positive, the bitmap is top-down. If the stride is negative, the bitmap is bottom-up. |
| **PixelFormat** | Integer that specifies the pixel format of the bitmap. |
| **Scan0** | Pointer to the first (index 0) scan line of the bitmap. |
| **Reserved** | Reserved for future use. |

# <a name="CharacterRange"></a>CharacterRange Structure

A **CharacterRange** structure specifies a range of character positions within a string.

```
TYPE CharacterRange
   First AS INT_
   Length AS INT_
END TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **First** | Specifies the first position of this range. |
| **Length** | Specifies the number of positions in this range. |

#### Remarks

A character range is a range of character positions within a string of text. The area of the display that is occupied by a group of characters that are specified by the character range is the bounding region. A character range is set by **GdipSetStringFormatMeasurableCharacterRanges**. The number of ranges that are currently set can be determined by calling **GdipGetStringFormatMeasurableCharacterRangeCount**. This number is also the number of regions expected to be obtained by the **GdipMeasureCharacterRanges** function.

# <a name="ColorMap"></a>ColorMap Structure

The **ColorMap** structure contains two COLORREF values. Several of the **ImageAttributes** functions adjust image colors by using a color remap table, which is an array of **ColorMap** structures.

```
TYPE ColorMap
   oldColor AS Color
   newColor AS Color
END TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **oldColor** | The original color. |
| **newColor** | The new color. |

#### Remarks

Because the FreeBasic 32-bit headers don't define the GDI+ **ColorMap** structure ad use the GDI **ColorMap** one, that has different member names, there is a conflict. To solve it, I have defined an union that can be used to replace **ColorMap** in both 32 and 64-bit.

```
UNION GDIP_COLORMAP
   ' // For compatibility with GDI+
   TYPE
      oldColor AS COLORREF
      newColor AS COLORREF
   END TYPE
   ' // For compatibility with GDI
   TYPE
      from AS COLORREF
      to AS COLORREF
   END TYPE
END UNION
```

# <a name="ColorMatrix"></a>ColorMatrix Structure

The **ColorMap** structure contains two COLORREF values. Several of the **ImageAttributes** functions adjust image colors by using a color remap table, which is an array of **ColorMap** structures.

```
TYPE ColorMatrix
   m(0 to 5-1, 0 to 5-1) AS REAL
END TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **m** | 55 array of real numbers. |

#### Remarks

A 55 color matrix is a homogeneous matrix for a 4-space transformation. The element in the fifth row and fifth column of a 55 homogeneous matrix must be 1, and all of the other elements in the fifth column must be 0. Color matrices are used to transform color vectors. The first four components of a color vector hold the red, green, blue, and alpha components (in that order) of a color. The fifth component of a color vector is always 1.

# <a name="ColorPalette"></a>ColorPalette Structure

The **ColorPalette** structure defines an array of colors that make up a color palette. The colors are 32-bit ARGB colors.

```
TYPE ColorPalette
   Flags AS UINT
   Count AS UINT
   Entries(0) AS ARGB
END TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **Flags** | Combination of flags from the **PaletteFlags** enumeration. |
| **Count** | Number of elements in the Entries array. |
| **Entries** | Array of ARGB colors.  |

# <a name="EncoderParameter"></a>EncoderParameter Structure

An **EncoderParameter** structure holds a parameter that can be passed to an image encoder. An **EncoderParameter** structure can also be used to receive a list of possible values supported by a particular parameter of a particular image encoder.

```
TYPE EncoderParameter
   Guid AS GUID
   NumberOfValues AS ULONG
   Type AS ULONG
   Value AS ANY PTR
END TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **Guid** | Identifies the parameter category. GUIDs that represent various parameter categories (**EncoderCompression**, **EncoderColorDepth**, and the like) are defined in Gdiplusimaging.inc. |
| **NumberOfValues** | Number of values in the array pointed to by the **Value** data member. |
| **Type** | Identifies the data type of the parameter. The **EncoderParameterValueType** enumeration in Gdiplusenums.inc defines several possible value types. |
| **Value** | Pointer to an array of values. Each value has the type specified by the **Type** data member. |

# <a name="EncoderParameters"></a>EncoderParameters Structure

An **EncoderParameters** structure is an array of **EncoderParameter** structures along with a data member that specifies the number of **EncoderParameter** structures in the array.

```
TYPE EncoderParameters
   Count AS UINT
   Parameter(0) AS EncoderParameter
END TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **Count** | Number of **EncoderParameter** structures in the array. |
| **Parameter ()** | Array of **EncoderParameter** structures. |

#### Remarks

When you create an **EncoderParameters** structure, you must allocate enough memory to hold all of the **EncoderParameter** structures that will eventually be placed in the array.

# <a name="ENHMETAHEADER3"></a>ENHMETAHEADER3 Structure

The **ENHMETAHEADER3** structure contains enhanced-metafile data including the dimensions of the metafile image, the number of records in the metafile, and the resolution of the device on which the metafile was created.

```
TYPE ENHMETAHEADER3
   itype AS DWORD
   nSize AS DWORD
   rclBounds AS RECTL
   rclFrame AS RECTL
   dSignature AS DWORD
   nVersion AS DWORD
   nBytes AS DWORD
   nRecords AS DWORD
   nHandles AS WORD
   sReserved AS WORD
   nDescription AS DWORD
   offDescription AS DWORD
   nPalEntries AS DWORD
   szlDevice AS SIZEL
   szlMillimeters AS SIZEL
END TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **iType** | Record type. Value is always EMR_HEADER. |
| **nSize** | Structure size, in bytes. This may be greater than the value returned by SIZEOF (ENHMETAHEADER3). |
| **rclBounds** | Bounding rectangle, in device units, for the image stored in the metafile. |
| **rclFrame** | Rectangle, in 0.01 millimeter units, that surrounds the image stored in the metafile. |
| **dSignature** | Must be ENHMETA_SIGNATURE. |
| **nVersion** | Version number of the metafile format. The current version is &H10000. |
| **nBytes** | Size, in bytes, of the metafile. |
| **nRecords** | Number of records in the metafile. |
| **nHandles** | Number of handles in the metafile handle table. Handle index zero is reserved. |
| **sReserved** | Reserved. Must be zero. |
| **nDescription** | Number of characters in the string that contains the description of the metafile's contents. This member is 0 if the metafile does not have a description string. |
| **offDescription** | Offset from the beginning of the ENHMETAHEADER3 structure to the string that contains the description of the metafile's contents. This member is 0 if the metafile does not have a description string. |
| **nPalEntries** | Number of entries in the metafile palette. |
| **szlDevice** | Resolution, in pixels, of the reference device. |
| **szlMillimeters** | Resolution, in millimeters, of the reference device. |

# <a name="GdiplusStartupInput"></a>GdiplusStartupInput Structure

The **GdiplusStartupInput** structure holds a block of arguments that are required by the **GdiplusStartup** function.

```
TYPE GdiplusStartupInput
   GdiplusVersion AS UINT32
   DebugEventCallback AS DebugEventProc
   SuppressBackgroundThread AS BOOL
   SuppressExternalCodecs AS BOOL
END TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **GdiplusVersion** | Specifies the version of Microsoft Windows GDI+. Must be 1. |
| **DebugEventCallback** | Pointer to a callback function that GDI+ can call, on debug builds, for assertions and warnings. The default value is NULL. |
| **SuppressBackgroundThread** | Boolean value that specifies whether to suppress the GDI+ background thread. If you set this member to TRUE, GdiplusStartup returns (in its output parameter) a pointer to a hook function and a pointer to an unhook function. You must call those functions appropriately to replace the background thread. If you do not want to be responsible for calling the hook and unhook functions, set this member to FALSE. The default value is FALSE. |
| **SuppressExternalCodecs** | Boolean value that specifies whether you want GDI+ to suppress external image codecs. GDI+ version 1.0 does not support external image codecs, so this parameter is ignored. |

#### Remarks

The **GdiplusStartupInput** structure provides a constructor that sets the **GdiplusVersion** member to 1 and allows you to specify values for the other three members. All of the constructor parameters are optional, so you can declare a variable of type GdiplusStartupInput without passing any arguments to the constructor, and all of the members will be initialized with appropriate default values.

If you set the **SuppressBackgroundThread** member of the **GdiplusStartupinput** parameter to TRUE, you must call the hook and unhook functions returned in the output parameter. Call those functions before and after the application's main message loop; that is, a message loop that is active for the lifetime of GDI+. Call the hook function before the loop starts, and call the unhook function after the loop ends.

# <a name="GdiplusStartupOutput"></a>GdiplusStartupOutput Structure

The **GdiplusStartup** function uses the **GdiplusStartupOutput** structure to return (in its output parameter) a pointer to a hook function and a pointer to an unhook function. If you set the **SuppressBackgroundThread** member of the input parameter to TRUE, then you are responsible for calling those functions to replace the Microsoft Windows GDI+ background thread.

Call the hook and unhook functions before and after the application's main message loop; that is, a message loop that is active for the lifetime of GDI+. Call the hook function before the loop starts, and call the unhook function after the loop ends. The token parameter of the hook function receives an identifier that you should later pass to the unhook function. If you do not pass the proper identifier (the one returned by the hook function) to the unhook function, there will be resource leaks that won't be cleaned up until the process exits.

If you do not want to be responsible for calling the hook and unhook functions, set the **SuppressBackgroundThread** member of the input parameter (passed to **GdiplusStartup**) to FALSE.

```
TYPE GdiplusStartupOutput
   NotificationHook AS NotificationHookProc
   NotificationUnhook AS NotificationUnhookProc
END TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **NotificationHook** | Receives a pointer to a hook function. |
| **NotificationUnhook** | Receives a pointer to an unhook function. |

# <a name="GpPathData"></a>GpPathData Structure

The **GpPathData** structure is used by the **GdipGetPathData** function. It has an array of points and an array of types. Each element in the array of types is a byte that specifies the point type and a set of flags for the corresponding element in the array of points. You can use a **GpathData** structure to get or set the data points (and their types) of a path.

```
TYPE GpPathData
   Count AS INT_
   Points AS GpPointF PTR
   Types AS BYTE PTR
END TYPE
```
-also-
```
type GpPathData as any
```

| Member     | Description |
| ---------- | ----------- |
| **NotificationHook** | Receives a pointer to a hook function. |
| **NotificationUnhook** | Receives a pointer to an unhook function. |

#### Remarks

Because of another mess in the FreeBASIC Gdi+ headers, this structure can't be used with 32 and 64-bit at the same time. Therefore, I have declared a replacement in AfxGdiPlus.inc.

```
TYPE GDIP_PATHDATA
   Count AS LONG
   Points AS GpPointF PTR
   Types AS UBYTE PTR
END TYPE
```

# <a name="GpPoint"></a>GpPoint Structure

Defines the x- and y-coordinates of a point.

```
TYPE GpPoint
   x AS INT_
   y AS INT_
END TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **x** | Specifies the x-coordinate of a point. |
| **y** | Specifies the y-coordinate of a point. |

# <a name="GpPointF"></a>GpPointF Structure

Defines the x- and y-coordinates of a point.

```
TYPE GpPoint
   x AS FLOAT
   y AS FLOAT
END TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **x** | Specifies the x-coordinate of a point. |
| **y** | Specifies the y-coordinate of a point. |

# <a name="GpRect"></a>GpRect Structure

Defines the upper-left corner, width, and height of a rectangle.

```
TYPE GpRect
   x AS INT_
   y AS INT_
   width AS INT_
   height AS INT_
END TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **x** | Specifies the x-coordinate of the upper-left corner of a rectangle. |
| **y** | Specifies the y-coordinate of the upper-left corner of a rectangle. |
| **width** | Specifies the width of a rectangle. |
| **height** | Specifies the heigth of a rectangle. |

# <a name="GpRectF"></a>GpRectF Structure

Defines the upper-left corner, width, and height of a rectangle.

```
TYPE GpRect
   x AS REAL
   y AS REAL
   width AS REAL
   height AS REAL
END TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **x** | Specifies the x-coordinate of the upper-left corner of a rectangle. |
| **y** | Specifies the y-coordinate of the upper-left corner of a rectangle. |
| **width** | Specifies the width of a rectangle. |
| **height** | Specifies the heigth of a rectangle. |

# <a name="GpSize"></a>GpSize Structure

Encapsulates a Width and Height dimension in a 2-D coordinate system.

```
TYPE GpSize
   Width AS INT_
   Height AS INT_
END TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **Width** | Vertical measurement. |
| **Height** | Horizontal measurement. |

# <a name="GpSizeF"></a>GpSizeF Structure

Encapsulates a Width and Height dimension in a 2-D coordinate system.

```
TYPE GpSizeF
   Width AS REAL
   Height AS REAL
END TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **Width** | Vertical measurement. |
| **Height** | Horizontal measurement. |

# <a name="ImageCodecInfo"></a>ImageCodecInfo Structure

An **ImageCodecInfo** structure stores information about an image codec (encoder/decoder). GDI+ provides several built-in image codecs. You can obtain information about those codecs by calling the **GetImageEncoders** function and the **GetImageDecoders** function. Each of those functions returns an array of **ImageCodecInfo** structures, one for each available encoder or decoder.

```
TYPE ImageCodecInfo
   Clsid AS CLSID
   FormatID AS GUID
   CodecName AS WCHAR PTR
   DllName AS WCHAR PTR
   FormatDescription AS WCHAR PTR
   FilenameExtension AS WCHAR PTR
   MimeType AS WCHAR PTR
   Flags AS DWORD
   Version AS DWORD
   SigCount AS DWORD
   SigSize AS DWORD
   SigPattern AS UBYTE PTR
   SigMask AS UBYTE PTR
END TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **Clsid** | Codec identifier. |
| **FormatID** | File format identifier. GUIDs that identify various file formats (**ImageFormatBMP**, **ImageFormatEMF**, and the like) are defined in Gdiplusimaging.inc. |
| **CodecName** | Pointer to a null-terminated wide string that contains the codec name. |
| **DllName** | Pointer to a null-terminated wide string that contains the path name of the DLL in which the codec resides. If the codec is not in a DLL, this pointer is NULL. |
| **FormatDescription** | Pointer to a null-terminated wide string that contains the name of the file format used by the codec. |
| **FilenameExtension** | Pointer to a null-terminated wide string that contains all file-name extensions associated with the codec. The extensions are separated by semicolons. |
| **MimeType** | Pointer to a null-terminated wide string that contains the mime type of the codec. |
| **Flags** | Combination of flags from the **ImageCodecFlags** enumeration. |
| **Version** | Integer that indicates the version of the codec. |
| **SigCount** | Integer that indicates the number of signatures used by the file format associated with the codec. |
| **SigSize** | Integer that indicates the number of bytes in each signature. |
| **SigPattern** | Pointer to an array of bytes that contains the pattern for each signature. |
| **SigMask** | Pointer to an array of bytes that contains the mask for each signature. |

# <a name="LOGFONTA"></a>LOGFONTA Structure

Defines the attributes of a font.

```
TYPE LOGFONTA
   lfHeight AS LONG
   lfWidth AS LONG
   lfEscapement AS LONG
   lfOrientation AS LONG
   lfWeight AS LONG
   lfItalic AS UBYTE
   lfUnderline AS UBYTE
   lfStrikeOut AS UBYTE
   lfCharSet AS UBYTE
   lfOutPrecision AS UBYTE
   lfClipPrecision AS UBYTE
   lfQuality AS UBYTE
   lfPitchAndFamily AS UBYTE
   lfFaceName AS ZSTRING * 32   ' LF_FACESIZE
END TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **lfHeight** | Value of type LONG that specifies the height, in logical units, of the font's character cell or character. |
| **lfWidth** | Value of type LONG that specifies the width, in logical units, of characters in the font.  |
| **lfEscapement** | Value of type LONG that contains the angle, in tenths of degrees, between the escapement vector and the x-axis of the device. The escapement vector is parallel to the base line of a row of text. |
| **lfOrientation** | Value of type LONG that specifies the angle, in tenths of degrees, between each character's base line and the x-axis of the device. |
| **lfWeight** | Value of type LONG that specifies the weight of the font in the range from 0 through 1000. |
| **lfItalic** | Value of type BYTE that specifies an italic font if set to TRUE. |
| **lfUnderline** | Value of type BYTE that specifies an underlined font if set to TRUE. |
| **lfStrikeOut** | Value of type BYTE that specifies a strikeout font if set to TRUE. |
| **lfCharSet** | Value of type BYTE that specifies the character set. |
| **lfOutPrecision** | Value of type BYTE that specifies the output precision. The output precision defines how closely the output must match the requested font's height, width, character orientation, escapement, pitch, and font type. |
| **lfClipPrecision** | Value of type BYTE that specifies the clipping precision. The clipping precision defines how to clip characters that are partially outside the clipping region. |
| **lfQuality** | Value of type BYTE that specifies the output quality. The output quality defines how carefully the Microsoft Windows Graphics Device Interface (GDI) must attempt to match the logical-font attributes to those of an actual physical font. |
| **lfPitchAndFamily** | Value of type BYTE that specifies the pitch and family of the font. |
| **lfFaceName** | Array of characters that contains a null-terminated string that specifies the typeface name of the font. The length of the string must not exceed 32 characters, including the NULL terminator. |

# <a name="LOGFONTW"></a>LOGFONTW Structure

Defines the attributes of a font.

```
TYPE LOGFONTW
   lfHeight AS LONG
   lfWidth AS LONG
   lfEscapement AS LONG
   lfOrientation AS LONG
   lfWeight AS LONG
   lfItalic AS UBYTE
   lfUnderline AS UBYTE
   lfStrikeOut AS UBYTE
   lfCharSet AS UBYTE
   lfOutPrecision AS UBYTE
   lfClipPrecision AS UBYTE
   lfQuality AS UBYTE
   lfPitchAndFamily AS UBYTE
   lfFaceName AS WSTRING * 32   ' LF_FACESIZE
END TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **lfHeight** | Value of type LONG that specifies the height, in logical units, of the font's character cell or character. |
| **lfWidth** | Value of type LONG that specifies the width, in logical units, of characters in the font.  |
| **lfEscapement** | Value of type LONG that contains the angle, in tenths of degrees, between the escapement vector and the x-axis of the device. The escapement vector is parallel to the base line of a row of text. |
| **lfOrientation** | Value of type LONG that specifies the angle, in tenths of degrees, between each character's base line and the x-axis of the device. |
| **lfWeight** | Value of type LONG that specifies the weight of the font in the range from 0 through 1000. |
| **lfItalic** | Value of type BYTE that specifies an italic font if set to TRUE. |
| **lfUnderline** | Value of type BYTE that specifies an underlined font if set to TRUE. |
| **lfStrikeOut** | Value of type BYTE that specifies a strikeout font if set to TRUE. |
| **lfCharSet** | Value of type BYTE that specifies the character set. |
| **lfOutPrecision** | Value of type BYTE that specifies the output precision. The output precision defines how closely the output must match the requested font's height, width, character orientation, escapement, pitch, and font type. |
| **lfClipPrecision** | Value of type BYTE that specifies the clipping precision. The clipping precision defines how to clip characters that are partially outside the clipping region. |
| **lfQuality** | Value of type BYTE that specifies the output quality. The output quality defines how carefully the Microsoft Windows Graphics Device Interface (GDI) must attempt to match the logical-font attributes to those of an actual physical font. |
| **lfPitchAndFamily** | Value of type BYTE that specifies the pitch and family of the font. |
| **lfFaceName** | Array of wide characters that contains a null-terminated string that specifies the typeface name of the font. The length of the string must not exceed 32 characters, including the NULL terminator. |

# <a name="MetafileHeader"></a>MetafileHeader Structure

A **MetafileHeader** structure stores properties of an associated metafile.

```
UNION MetafileHeader_UNION
   WmfHeader AS METAHEADER
   EmfHeader AS ENHMETAHEADER3
END UNION

TYPE MetafileHeader
   Type_ AS MetafileType     ' // The type of the associated metafile
   Size AS UINT              ' // Size of the metafile (in bytes)
   Version AS UINT           ' // EMF+, EMF, or WMF version
   EmfPlusFlags AS UINT
   DpiX AS REAL
   DpiY AS REAL
   X AS INT_                 ' // Bounds in device units
   Y AS INT_
   Width AS INT_
   Height AS INT_
   union
      WmfHeader as METAHEADER
      EmfHeader as ENHMETAHEADER3
   end union
   EmfPlusHeaderSize AS INT_ ' // size of the EMF+ header in file
   LogicalDpiX AS INT_       ' // Logical Dpi of reference Hdc
   LogicalDpiY AS INT_       ' // usually valid only for EMF+
END TYPE
```

#### Remarks

Metafiles provide a device-independent and application-independent way to share pictures. They contain records that describe a sequence of graphics application programming interfaces (APIs) to invoke in a particular order with their associated graphics data. Metafiles can be recorded by an application and later played back by that application or by another one to reproduce a particular picture. They can also be used to send content to a print spooler. Enhanced metafiles support the ability to provide both Microsoft Windows GDI+ and Windows Graphics Device Interface (GDI) descriptions of the same picture so that both GDI+ and down-level GDI applications can render it.

# <a name="PropertyItem"></a>PropertyItem Structure

A **PropertyItem** structure holds one piece of image metadata.

```
TYPE PropertyItem
   id AS PROPID
   length AS ULONG
   wtype AS WORD
   value AS ANY PTR
END TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **id** | Integer that identifies the kind of metadata stored in this PropertyItem object. Constants that identify various kinds of metadata (**PropertyTagEquipMake**, P**ropertyTagEquipModel**, and the like) are defined in Gdiplusimaging.inc. The **PROPID** data type is defined in Wtypes.inc. |
| **length** | Size, in bytes, of the value array. |
| **wtype** | Integer that identifies the data type of the values in the value array. Constants that identify various data types (**PropertyTagTypeByte**, **PropertyTagTypeASCII**, and the like) are defined in Gdiplusimaging.inc. |
| **value** | Pointer to an array of values. Each value in the array has the data type specified by the type data member. |

# <a name="PWMFRect16"></a>PWMFRect16 Structure

The **PWMFRect16** structure defines a rectangle that bounds a placeable metafile. The rectangle defines the size and position of the metafile.

```
TYPE PWMFRect16
   Left AS INT16
   Top AS INT16
   Right AS INT16
   Bottom AS INT16
END TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **Left** | Left coordinate of the rectangle that bounds the metafile. |
| **Top** | Top coordinate of the rectangle that bounds the metafile. |
| **Right** | Right coordinate of the rectangle that bounds the metafile. |
| **Bottom** | Bottom coordinate of the rectangle that bounds the metafile. |

# <a name="WmfPlaceableFileHeader"></a>WmfPlaceableFileHeader Structure

The **WmfPlaceableFileHeader** structure defines the fields of a placeable metafile header. Placeable metafiles were created as a way of specifying how a metafile is mapped and scaled on a display device.

```
TYPE WmfPlaceableFileHeader
   Key AS UINT32
   Hmf AS INT16
   BoundingBox AS PWMFRect16
   Inch AS INT16
   Reserved AS UINT32
   Checksum AS INT16
END TYPE
```

| Member     | Description |
| ---------- | ----------- |
| **Key** | Identification value that indicates the presence of a placeable metafile header. This value is always &h9AC6CDD7. |
| **Hmf** | Handle to the metafile in memory. When written to disk, this field is not used and will always contains the value 0. |
| **BoundingBox** | Destination rectangle, measured in twips, for displaying the metafile. |
| **Inch** | Number of twips per inch used to represent the image.<br>Normally, there are 1440 twips per inch; however, this number can be changed to scale the image.<br>* A value of 720 specifies that the image is twice its normal size.<br>* A value of 360 specifies that the image is four times its normal size.<br>* A value of 2880 specifies that the image is half its normal size. |
| **Reserved** | Not used and is always set to 0. |
| **Checksum** | Checksum for the previous 10 WORDs in the header. This value can be used to determine whether the metafile has become corrupted. |

#### Remarks

Although placeable metafiles are quite common, they are not directly supported by the Microsoft Windows application programming interface (API). To display a placeable metafile using the Windows API, you must first strip the placeable metafile header from the file. This is typically performed by copying the metafile to a temporary file starting at file offset 22 (0x16). This is because each placeable metafile begins with a 22-byte header that is followed by a standard metafile. 

# <a name="BrushType"></a>BrushType Enumeration

The **BrushType** enumeration indicates the type of brush. There are five types of brushes.

```
BrushTypeSolidColor = 0
BrushTypeHatchFill = 1
BrushTypeTextureFill = 2
BrushTypePathGradient = 3
BrushTypeLinearGradient = 4
```

| Constant   | Meaning     |
| ---------- | ----------- |
| **BrushTypeSolidColor** | Indicates a brush of type SolidBrush. A solid brush paints a single, constant color that can be opaque or transparent. |
| **BrushTypeHatchFill** | Indicates a brush of type **HatchBrush**. A hatch brush paints a background and paints, over that background, a pattern of lines, dots, dashes, squares, crosshatch, or some variation of these. The hatch brush consists of two colors: one for the background and one for the pattern over the background. The color of the background is called the background color, and the color of the pattern is called the foreground color.  |
| **BrushTypeTextureFill** | Indicates a brush of type **TextureBrush**. A texture brush paints an image. The image or texture is either a portion of a specified image or a scaled version of a specified image. The type of image (metafile or nonmetafile) determines whether the texture is a portion of the image or a scaled version of the image. |
| **BrushTypePathGradient** | Indicates a brush of type **PathGradientBrush**. A path gradient brush paints a color gradient in which the color changes from a center point outward to a boundary that is defined by a closed curve or path. The color gradient has one color at the center point and one or multiple colors at the boundary. |
| **BrushTypeLinearGradient** | Indicates a brush of type **LinearGradientBrush**. A linear gradient brush paints a color gradient in which the color changes evenly from the starting boundary line of the linear gradient brush to the ending boundary line of the linear gradient brush. The boundary lines of a linear gradient brush are two parallel straight lines. The color gradient is perpendicular to the boundary lines of the linear gradient brush, changing gradually across the stroke from the starting boundary line to the ending boundary line. The color gradient has one color at the starting boundary line and another color at the ending boundary line.  |

# <a name="Color"></a>Color Enumeration

```
AliceBlue = &hFFF0F8FF
AntiqueWhite = &hFFFAEBD7
Aqua = &hFF00FFFF
Aquamarine = &hFF7FFFD4
Azure = &hFFF0FFFF
Beige = &hFFF5F5DC
Bisque = &hFFFFE4C4
Black = &hFF000000
BlanchedAlmond = &hFFFFEBCD
Blue = &hFF0000FF
BlueViolet = &hFF8A2BE2
Brown = &hFFA52A2A
BurlyWood = &hFFDEB887
CadetBlue = &hFF5F9EA0
Chartreuse = &hFF7FFF00
Chocolate = &hFFD2691E
Coral = &hFFFF7F50
CornflowerBlue = &hFF6495ED
Cornsilk = &hFFFFF8DC
Crimson = &hFFDC143C
Cyan = &hFF00FFFF
DarkBlue = &hFF00008B
DarkCyan = &hFF008B8B
DarkGoldenrod = &hFFB8860B
DarkGray = &hFFA9A9A9
DarkGreen = &hFF006400
DarkKhaki = &hFFBDB76B
DarkMagenta = &hFF8B008B
DarkOliveGreen = &hFF556B2F
DarkOrange = &hFFFF8C00
DarkOrchid = &hFF9932CC
DarkRed = &hFF8B0000
DarkSalmon = &hFFE9967A
DarkSeaGreen = &hFF8FBC8B
DarkSlateBlue = &hFF483D8B
DarkSlateGray = &hFF2F4F4F
DarkTurquoise = &hFF00CED1
DarkViolet = &hFF9400D3
DeepPink = &hFFFF1493
DeepSkyBlue = &hFF00BFFF
DimGray = &hFF696969
DodgerBlue = &hFF1E90FF
Firebrick = &hFFB22222
FloralWhite = &hFFFFFAF0
ForestGreen = &hFF228B22
Fuchsia = &hFFFF00FF
Gainsboro = &hFFDCDCDC
GhostWhite = &hFFF8F8FF
Gold = &hFFFFD700
Goldenrod = &hFFDAA520
Gray = &hFF808080
Green = &hFF008000
GreenYellow = &hFFADFF2F
Honeydew = &hFFF0FFF0
HotPink = &hFFFF69B4
IndianRed = &hFFCD5C5C
Indigo = &hFF4B0082
Ivory = &hFFFFFFF0
Khaki = &hFFF0E68C
Lavender = &hFFE6E6FA
LavenderBlush = &hFFFFF0F5
LawnGreen = &hFF7CFC00
LemonChiffon = &hFFFFFACD
LightBlue = &hFFADD8E6
LightCoral = &hFFF08080
LightCyan = &hFFE0FFFF
LightGoldenrodYellow = &hFFFAFAD2
LightGray = &hFFD3D3D3
LightGreen = &hFF90EE90
LightPink = &hFFFFB6C1
LightSalmon = &hFFFFA07A
LightSeaGreen = &hFF20B2AA
LightSkyBlue = &hFF87CEFA
LightSlateGray = &hFF778899
LightSteelBlue = &hFFB0C4DE
LightYellow = &hFFFFFFE0
Lime = &hFF00FF00
LimeGreen = &hFF32CD32
Linen = &hFFFAF0E6
Magenta = &hFFFF00FF
Maroon = &hFF800000
MediumAquamarine = &hFF66CDAA
MediumBlue = &hFF0000CD
MediumOrchid = &hFFBA55D3
MediumPurple = &hFF9370DB
MediumSeaGreen = &hFF3CB371
MediumSlateBlue = &hFF7B68EE
MediumSpringGreen = &hFF00FA9A
MediumTurquoise = &hFF48D1CC
MediumVioletRed = &hFFC71585
MidnightBlue = &hFF191970
MintCream = &hFFF5FFFA
MistyRose = &hFFFFE4E1
Moccasin = &hFFFFE4B5
NavajoWhite = &hFFFFDEAD
Navy = &hFF000080
OldLace = &hFFFDF5E6
Olive = &hFF808000
OliveDrab = &hFF6B8E23
Orange = &hFFFFA500
OrangeRed = &hFFFF4500
Orchid = &hFFDA70D6
PaleGoldenrod = &hFFEEE8AA
PaleGreen = &hFF98FB98
PaleTurquoise = &hFFAFEEEE
PaleVioletRed = &hFFDB7093
PapayaWhip = &hFFFFEFD5
PeachPuff = &hFFFFDAB9
Peru = &hFFCD853F
Pink = &hFFFFC0CB
Plum = &hFFDDA0DD
PowderBlue = &hFFB0E0E6
Purple = &hFF800080
Red = &hFFFF0000
RosyBrown = &hFFBC8F8F
RoyalBlue = &hFF4169E1
SaddleBrown = &hFF8B4513
Salmon = &hFFFA8072
SandyBrown = &hFFF4A460
SeaGreen = &hFF2E8B57
SeaShell = &hFFFFF5EE
Sienna = &hFFA0522D
Silver = &hFFC0C0C0
SkyBlue = &hFF87CEEB
SlateBlue = &hFF6A5ACD
SlateGray = &hFF708090
Snow = &hFFFFFAFA
SpringGreen = &hFF00FF7F
SteelBlue = &hFF4682B4
Tan = &hFFD2B48C
Teal = &hFF008080
Thistle = &hFFD8BFD8
Tomato = &hFFFF6347
Transparent = &hFFFFFF
Turquoise = &hFF40E0D0
Violet = &hFFEE82EE
Wheat = &hFFF5DEB3
White = &hFFFFFFFF
WhiteSmoke = &hFFF5F5F5
Yellow = &hFFFFFF00
YellowGreen = &hFF9ACD32
```
```
AlphaShift = 24
RedShift = 16
GreenShift = 8
BlueShift = 0
```
```
AlphaMask = &hFF000000
RedMask = &h00FF0000
GreenMask = &h0000FF00
BlueMask = &hh000000FF
```

# <a name="ColorAdjustType"></a>ColorAdjustType Enumeration

The **ColorAdjustType** enumeration specifies which GDI+ objects use color-adjustment information. You can adjust the colors in a rendered image using the **ImageAttributes functions**. There are five adjustment categories: default, bitmap, brush, pen, and text.

```
ColorAdjustTypeDefault = 0
ColorAdjustTypeBitmap  = 1
ColorAdjustTypeBrush   = 2
ColorAdjustTypePen     = 3
ColorAdjustTypeText    = 4
ColorAdjustTypeCount   = 5
ColorAdjustTypeAny     = 6
```

| Constant   | Meaning     |
| ---------- | ----------- |
| ColorAdjustTypeDefault | Specifies that color or grayscale adjustment applies to all categories that do not have adjustment settings of their own. |
| ColorAdjustTypeBitmap | Specifies that color or grayscale adjustment applies to bitmapped images. |
| ColorAdjustTypeBrush | Specifies that color or grayscale adjustment applies to brush operations in metafiles. |
| ColorAdjustTypePen | Specifies that color or grayscale adjustment applies to pen operations in metafiles. |
| ColorAdjustTypeText | Specifies that color or grayscale adjustment applies to text drawn in metafiles. |
| ColorAdjustTypeCount | Used internally to record the number of color adjustment types. |
| ColorAdjustTypeAny | Reserved. |

# <a name="ColorChannelFlags"></a>ColorChannelFlags Enumeration

The **ColorChannelFlags** enumeration specifies individual channels in the CMYK (cyan, magenta, yellow, black) color space. This enumeration is used by the GdipSetImageAttributesOutputChannel function.

```
ColorChannelFlagsC    = 0
ColorChannelFlagsM    = 1
ColorChannelFlagsY    = 2
ColorChannelFlagsK    = 3
ColorChannelFlagsLast = 4
```

| Constant   | Meaning     |
| ---------- | ----------- |
| ColorChannelFlagsC | Specifies the cyan color channel. |
| ColorChannelFlagsM | Specifies the magenta color channel. |
| ColorChannelFlagsY | Specifies the yellow color channel. |
| ColorChannelFlagsK | Specifies the black color channel. |

# <a name="ColorMatrixFlags"></a>ColorMatrixFlags Enumeration

The **ColorMatrixFlags** enumeration specifies the types of images and colors that will be affected by the color and grayscale adjustment settings. It is used by the GdipSetImageAttributesColorMatrix function.

```
ColorMatrixFlagsDefault = 0
ColorMatrixFlagsSkipGrays = 1
ColorMatrixFlagsAltGray = 2
```

| Constant   | Meaning     |
| ---------- | ----------- |
| ColorMatrixFlagsDefault | Specifies that all color values (including grays) are adjusted by the same color-adjustment matrix. |
| ColorMatrixFlagsSkipGrays | Specifies that colors are adjusted but gray shades are not adjusted. A gray shade is any color that has the same value for its red, green, and blue components. |
| ColorMatrixFlagsAltGray | Specifies that colors are adjusted by one matrix and gray shades are adjusted by another matrix. |

# <a name="ColorMode"></a>ColorMode Enumeration

```
ColorModeARGB32 = 0
ColorModeARGB64 = 1
```

# <a name="CombineMode"></a>CombineMode Enumeration

The **CombineMode** enumeration specifies how a new region is combined with an existing region.

```
CombineModeReplace      = 0
CombineModeIntersect    = 1
CombineModeUnion        = 2
CombineModeXor          = 3
CombineModeExclude      = 4
CombineModeComplement   = 5
```

| Constant   | Meaning     |
| ---------- | ----------- |
| CombineModeReplace | Specifies that the existing region is replaced by the new region. |
| CombineModeIntersect | Specifies that the existing region is replaced by the intersection of itself and the new region. |
| CombineModeUnion | Specifies that the existing region is replaced by the union of itself and the new region. |
| CombineModeXor | Specifies that the existing region is replaced by the result of performing an XOR on the two regions. A point is in the XOR of two regions if it is in one region or the other but not in both regions. |
| CombineModeExclude | Specifies that the existing region is replaced by the portion of itself that is outside of the new region. |
| CombineModeComplement | Specifies that the existing region is replaced by the portion of the new region that is outside of the existing region. |

