# CGpGraphics Class

The **CGpGraphics** class provides methods for drawing lines, curves, figures, images, and text. A **Graphics** object stores attributes of the display device and attributes of the items to be drawn.

**Inherits from**: CGpBase.
**Imclude file**: CGpGraphics.inc.

| Name       | Description |
| ---------- | ----------- |
| [Constructors](#ConstructorsGraphics) | Creates a Graphics object. |
| [AddMetafileComment](#AddMetafileComment) | Adds a text comment to an existing metafile. |
| [BeginContainer](#BeginContainer) | Begins a new graphics container. |
| [Clear](#Clear) | Clears a Graphics object to a specified color. |
| [DrawArc](#DrawArc) | Draws an arc. The arc is part of an ellipse. |
| [DrawBezier](#DrawBezier) | Draws a Bézier spline. |
| [DrawBeziers](#DrawBeziers) | Draws a sequence of connected Bézier splines. |
| [DrawCachedBitmap](#DrawCachedBitmap) | Draws the image stored in a CachedBitmap object. |
| [DrawClosedCurve](#DrawClosedCurve) | Draws a closed cardinal spline. |
| [DrawCurve](#DrawCurve) | Draws a cardinal spline. |
| [DrawDriverString](#DrawDriverString) | Draws characters at the specified positions. |
| [DrawEllipse](#DrawEllipse) | Draws an ellipse. |
| [DrawImage](#DrawImage) | Draws an image. |
| [DrawImageFX](#DrawImageFX) | Draws a portion of an image after applying a specified effect. |
| [DrawLine](#DrawLine) | Draws a line that connects two points. |
| [DrawLines](#DrawLines) | Draws a sequence of connected lines. |
| [DrawPath](#DrawPath) | Draws a sequence of lines and curves defined by a GraphicsPath object. |
| [DrawPie](#DrawPie) | Draws a pie. |
| [DrawPolygon](#DrawPolygon) | Draws a polygon. |
| [DrawRectangle](#DrawRectangle) | Draws a rectangle. |
| [DrawRectangles](#DrawRectangles) | Draws a sequence of rectangles. |
| [DrawString](#DrawString) | Draws a string based on a font and an origin for the string. |
| [EndContainer](#EndContainer) | Closes a graphics container that was previously opened by the BeginContainer method. |
| [EnumerateMetafile](#EnumerateMetafile) | Calls an application-defined callback function for each record in a specified metafile. |
| [ExcludeClip](#ExcludeClip) | Updates the clipping region to the portion of itself that does not intersect the specified rectangle. |
| [FillClosedCurve](#FillClosedCurve) | Creates a closed cardinal spline from an array of points and uses a brush to fill the interior of the spline. |
| [FillEllipse](#FillEllipse) | Uses a brush to fill the interior of an ellipse that is specified by coordinates and dimensions. |
| [FillPath](#FillPath) | Uses a brush to fill the interior of a path. |
| [FillPie](#FillPie) | Uses a brush to fill the interior of a pie. |
| [FillPolygon](#FillPolygon) | Uses a brush to fill the interior of a polygon. |
| [FillRectangle](#FillRectangle) | Uses a brush to fill the interior of a rectangle. |
| [FillRectangles](#FillRectangles) | Uses a brush to fill the interior of a sequence of rectangles. |
| [FillRegion](#FillRegion) | Uses a brush to fill a specified region. |
| [Flush](#Flush) | Flushes all pending graphics operations. |
| [FromHDC](#FromHDC) | Creates a Graphics object that is associated with a specified device context. |
| [FromHWND](#FromHWND) | Creates a Graphics object that is associated with a specified window. |
| [FromImage](#FromImage) | Creates a Graphics object that is associated with a specified device context. |
| [GetClip](#GetClip) | Gets the clipping region of this Graphics object. |
| [GetClipBounds](#GetClipBounds) | Gets a rectangle that encloses the clipping region of this Graphics object. |
| [GetCompositingMode](#GetCompositingMode) | Gets the compositing mode currently set for this Graphics object. |
| [GetCompositingQuality](#GetCompositingQuality) | Gets the compositing quality currently set for this Graphics object. |
| [GetDpiX](#GetDpiX) | Gets the horizontal resolution, in dots per inch, of the display device associated with this Graphics object. |
| [GetDpiY](#GetDpiY) | Gets the vertical resolution, in dots per inch, of the display device associated with this Graphics object. |
| [GetHalftonePalette](#GetHalftonePalette) | Gets a Windows halftone palette. |
| [GetHDC](#GetHDC) | Gets a handle to the device context associated with this Graphics object. |
| [GetInterpolationMode](#GetInterpolationMode) | Gets the interpolation mode currently set for this Graphics object. |
| [GetNearestColor](#GetNearestColor) | Gets the nearest color to the color that is passed in. |
| [GetPageScale](#GetPageScale) | Gets the scaling factor currently set for the page transformation of this Graphics object. |
| [GetPageUnit](#GetPageUnit) | Gets the unit of measure currently set for this Graphics object. |
| [GetPixelOffsetMode](#GetPixelOffsetMode) | Gets the pixel offset mode currently set for this Graphics object. |
| [GetRenderingOrigin](#GetRenderingOrigin) | Gets the rendering origin currently set for this Graphics object. |
| [GetSmoothingMode](#GetSmoothingMode) | Determines whether smoothing (antialiasing) is applied to the Graphics object. |
| [GetTextContrast](#GetTextContrast) | Gets the contrast value currently set for this Graphics object. |
| [GetTextRenderingHint](#GetTextRenderingHint) | Returns the text rendering mode currently set for this Graphics object. |
| [GetTransform](#GetTransform) | Gets the world transformation matrix of this Graphics object. |
| [GetVisibleClipBounds](#GetVisibleClipBounds) | Gets a rectangle that encloses the visible clipping region of this Graphics object. |
| [IntersectClip](#IntersectClip) | Updates the clipping region of this Graphics object to the portion of the specified rectangle that intersects with the current clipping region of this Graphics object. |
| [IsClipEmpty](#IsClipEmpty) | Determines whether the clipping region of this Graphics object is empty. |
| [IsVisible](#IsVisible) | Determines whether the specified point is inside the visible clipping region of this Graphics object. |
| [IsVisibleClipEmpty](#IsVisibleClipEmpty) | Determines whether the visible clipping region of this Graphics object is empty. |
| [MeasureCharacterRanges](#MeasureCharacterRanges) | Gets a set of regions each of which bounds a range of character positions within a string. |
| [MeasureDriverString](#MeasureDriverString) | Measures the bounding box for the specified characters and their corresponding positions. |
| [MeasureString](#MeasureString) | Measures the extent of the string in the specified font, format, and layout rectangle. |
| [MultiplyTransform](#MultiplyTransform) | Updates this Graphics object's world transformation matrix with the product of itself and another matrix. |
| [ReleaseHDC](#ReleaseHDC) | Releases a device context handle obtained by a previous call to the GetHDC method of this Graphics object. |
| [ResetClip](#ResetClip) | Sets the clipping region of this Graphics object to an infinite region. |
| [ResetTransform](#ResetTransform) | Sets the world transformation matrix of this Graphics object to the identity matrix. |
| [Restore](#Restore) | Sets the state of this Graphics object to the state stored by a previous call to the Save method of this Graphics object. |
| [RotateTransform](#RotateTransform) | Updates the world transformation matrix of this Graphics object with the product of itself and a rotation matrix. |
| [Save](#Save) | Saves the current state (transformations, clipping region, and quality settings) of this Graphics object. |
| [ScaleTransform](#ScaleTransform) | Updates this Graphics object's world transformation matrix with the product of itself and a scaling matrix. |
| [SetClip](#SetClip) | Updates the clipping region of this Graphics object to a region that is the combination of itself and the clipping region of another Graphics object. |
| [SetCompositingMode](#SetCompositingMode) | Sets the compositing mode of this Graphics object. |
| [SetCompositingQuality](#SetCompositingQuality) | Sets the compositing quality of this Graphics object. |
| [SetInterpolationMode](#SetInterpolationMode) | Sets the interpolation mode of this Graphics object. |
| [SetPageScale](#SetPageScale) | Sets the scaling factor for the page transformation of this Graphics object. |
| [SetPageUnit](#SetPageUnit) | Sets the unit of measure for this Graphics object. |
| [SetPixelOffsetMode](#SetPixelOffsetMode) | Sets the pixel offset mode of this Graphics object. |
| [SetRenderingOrigin](#SetRenderingOrigin) | Sets the rendering origin of this Graphics object. |
| [SetSmoothingMode](#SetSmoothingMode) | Sets the rendering quality of the Graphics object. |
| [SetTextContrast](#SetTextContrast) | Sets the contrast value of this Graphics object. The contrast value is used for antialiasing text. |
| [SetTextRenderingHint](#SetTextRenderingHint) | Sets the text rendering mode of this Graphics object. |
| [SetTransform](#SetTransform) | Sets the world transformation of this Graphics object. |
| [TransformPoints](#TransformPoints) | Converts an array of points from one coordinate space to another. |
| [TranslateClip](#TranslateClip) | Translates the clipping region of this Graphics object. |
| [TranslateTransform](#TranslateTransform) | Updates this Graphics object's world transformation matrix with the product of itself and a translation matrix. |
