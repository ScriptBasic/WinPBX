# GdiPlus

GDI+ is the successor to GDI, the graphics device interface included with earlier versions of Windows. Windows XP or Windows .NET Server supports GDI for compatibility with existing applications, but programmers of new applications should use GDI+ for all their graphics needs because GDI+ optimizes many of the capabilities of GDI and also provides additional features.

A graphics device interface, such as GDI+, allows application programmers to display information on a screen or printer without having to be concerned about the details of a particular display device. The application programmer makes calls to the provided functions and those functions in turn make the appropriate calls to specific device drivers. GDI+ insulates the application from the graphics hardware, and it is this insulation that allows developers to create device-independent applications.

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
