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
