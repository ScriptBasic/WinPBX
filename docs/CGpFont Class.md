# CGpFont Class

The **CGpFont** class allows the creation of **Font** objects. The Font object encapsulates the characteristics, such as family, height, size, and style (or combination of styles), of a specific font. A **Font** object is used when drawing strings.

**Inherits from**: CGpBase.
**Imclude file**: CGpFont.inc.

| Name       | Description |
| ---------- | ----------- |
| [Constructors](#ConstructorsImage) | Creates a Font object. |
| [Clone](#Clone) | Copies the contents of the existing Font object into a new Font object. |
| [GetFamily](#GetFamily) | Gets the font family on which this font is based. |
| [GetHeight](#GetHeight) | Gets the line spacing of this font in the current unit of a specified Graphics object. |
| [GetLogFontA](#GetLogFontA) | Uses a LOGFONTA structure to get the attributes of this Font object. |
| [GetLogFontW](#GetLogFontW) | Uses a LOGFONTW structure to get the attributes of this Font object. |
| [GetSize](#GetSize) | Returns the font size (commonly called the em size) of this Font object. |
| [GetStyle](#GetStyle) | Returns the font size (commonly called the em size) of this Font object. |
| [GetUnit](#GetUnit) | Returns the unit of measure of this Font object. |
| [IsAvailable](#IsAvailable) | Determines whether this Font object was created successfully. |
