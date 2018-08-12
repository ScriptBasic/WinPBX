

# CPrint Class

Allows to attach/choose a printer and get/set its setting values.

### Methods

| Name       | Description |
| ---------- | ----------- |
| [AttachPrinter](#AttachPrinter) | Attaches the specified printer to the class. |
| [ChoosePrinter](#ChoosePrinter) | Displays the printer dialog to select a printer. |
| [PageSetup](#PageSetup) | Displays a Page Setup dialog box that enables the user to specify the attributes of a printed page. |
| [GetPrinterName](#GetPrinterName) | Returns the name of the attached printer. |
| [GetDC](#GetDC) | Returns the handle of the device context of the attached printer. |
| [GetPPIX](#GetPPIX) | Returns the number of pixels per inch of the page (horizontal resolution). |
| [GetPPIY](#GetPPIY) | Returns the number of pixels per inch of the page (vertical resolution). |
| [GetHorizontalUnits](#GetHorizontalUnits) | Returns the width, in world units, of the printable area of the page. |
| [GetVerticalUnits](#GetVerticalUnits) | Returns the height, in world units, of the printable area of the page. |
| [GetHorizontalResolution](#GetHorizontalResolution) | Returns the width, in pixels, of the printable area of the page. |
| [GetVerticalResolution](#GetVerticalResolution) | Returns the height, in pixels, of the printable area of the page. |
| [PixelsToPointsX](#PixelsToPointsX) | Converts pixels to point size (1/72 of an inch) (horizontal resolution). |
| [PixelsToPointsY](#PixelsToPointsY) | Converts pixels to point size (1/72 of an inch) (vertical resolution). |
| [PointsToPixelsX](#PointsToPixelsX) | Converts a point size (1/72 of an inch) to pixels (horizontal resolution). |
| [PointsToPixelsY](#PointsToPixelsY) | Converts a point size (1/72 of an inch) to pixels (vertical resolution). |
| [GetPaperNames](#GetPaperNames) | Returns a list of supported paper names. |
| [PrintBitmap](#PrintBitmap) | Prints a Windows bitmap in the attached printer. |
| [PrintBitmapToFile](#PrintBitmapToFile) | Prints a Windows bitmap in the specified file. |

### Properties

| Name       | Description |
| ---------- | ----------- |
| [Collate](#Collate) | Gets/sets the collate setting value. |
| [ColorMode](#ColorMode) | Switches between color and monochrome on color printers. |
| [Copies](#Copies) | Gets/sets the number of copies to print if the device supports multiple-page copies. |
| [Duplex](#Duplex) | Checks if the printer supports duplex printing. |
| [DuplexMode](#DuplexMode)  | Gets/sets the current duplex mode. |
| [Orientation](#Orientation) | Gets/sets the printer orientation. |
| [PaperSize](#PaperSize) | Gets/sets the printer paper size. |
| Quality                | Gets/sets the printer print quality mode. |
| Scale                  | Gets/sets the factor by which the printed output is to be scaled. |
| Tray                   | Specifies the paper source. |

# <a name="AttachPrinter"></a>AttachPrinter

Creates a device context (DC) for the specified printer and attaches it to the class.

```
FUNCTION AttachPrinter (BYREF wszPrinterName AS WSTRING) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszPrinterName* | The name of the printer to attach (as shown in the Devices and Printers applet of the Control Panel). |

#### Return value

BOOLEAN. True of false.

#### Example

```
DIM pPrint AS CPrint
pPrint.AttachPrinter("OKI DATA CORP B410")
```

# <a name="ChoosePrinter"></a>ChoosePrinter

Displays a Print Dialog Box to select a printer.

```
FUNCTION ChoosePrinter (BYVAL hwndOwner AS HWND = NULL) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwndOwner* | Optional. A handle to the window that owns the dialog box. This member can be any valid window handle, or it can be NULL if the dialog box has no owner. |

#### Return value

BOOLEAN. If the user clicks the OK button, the return value is true. If the user canceled or closed the Print dialog box or an error occurred, the return value is false.

#### Example

```
DIM pPrint AS CPrint
pPrint.ChoosePrinter
```

# <a name="PageSetup"></a>PageSetup

Displays a Page Setup dialog box that enables the user to specify the attributes of a printed page. These attributes include the paper size and source, the page orientation (portrait or landscape), and the width of the page margins.

```
FUNCTION PageSetup (BYVAL hwndOwner AS HWND = NULL) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwndOwner* | Optional. A handle to the window that owns the dialog box. This member can be any valid window handle, or it can be NULL if the dialog box has no owner. |

#### Return value

BOOLEAN. If the user clicks the OK button, the return value is true. If the user canceled or closed the Page Setup dialog box or an error occurred, the return value is false.

#### Example

```
DIM pPrint AS CPrint
pPrint.PageSetup
```

# <a name="GetPrinterName"></a>GetPrinterName

Returns the name of the attached printer.

```
FUNCTION GetPrinterName () AS CWSTR
```

#### Return value

CWSTR. The name of the attached printer. If there is not a printer attached, it returns an empty string.

# <a name="GetDC"></a>GetDC

Returns the name of the attached printer.

```
FUNCTION GetDC () AS HDC
```

#### Return value

HDC. The handle of the device context of the attached printer. If there is not a printer attached, it returns NULL.

# <a name="GetPPIX"></a>GetPPIX

Returns the number of pixels per inch of the specified host printer page (horizontal resolution).

```
FUNCTION GetPPIX () AS LONG
```

#### Return value

LONG. The number of pixels per inch of the specified host printer page. If there is not a printer attached, it returns 0.

# <a name="GetPPIY"></a>GetPPIY

Returns the number of pixels per inch of the specified host printer page (vertical resolution).

```
FUNCTION GetPPIY () AS LONG
```

#### Return value

LONG. The number of pixels per inch of the specified host printer page. If there is not a printer attached, it returns 0.

# <a name="GetHorizontalUnits"></a>GetHorizontalUnits

Returns the width, in world units, of the printable area of the page.

```
FUNCTION GetHorizontalUnits () AS LONG
```

#### Return value

LONG. The width, in world units, of the printable area of the page. If there is not a printer attached, it returns 0.

# <a name="GetVerticalUnits"></a>GetVerticalUnits

Returns the height, in world units, of the printable area of the page.

```
FUNCTION GetVerticalUnits () AS LONG
```

#### Return value

LONG. The height, in world units, of the printable area of the page. If there is not a printer attached, it returns 0.

# <a name="GetHorizontalResolution"></a>GetHorizontalResolution

Returns the width, in pixels, of the printable area of the page.

```
FUNCTION GetHorizontalResolution () AS LONG
```

#### Return value

LONG. The width, in pixels, of the printable area of the page. If there is not a printer attached, it returns 0.

# <a name="GetVerticalResolution"></a>GetVerticalResolution

Returns the height, in pixels, of the printable area of the page.

```
FUNCTION GetVerticalResolution () AS LONG
```

#### Return value

LONG. The height, in pixels, of the printable area of the page. If there is not a printer attached, it returns 0.

# <a name="PixelsToPointsX"></a>PixelsToPointsX

Converts pixels to point size (1/72 of an inch) according to the PPI of the printer (horizontal resolution).

```
FUNCTION PixelsToPointsX (BYVAL pix AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *pix* | The number of pixels to convert. |

#### Return value

LONG. The number of points. If there is not a printer attached, it returns 0.

# <a name="PixelsToPointsY"></a>PixelsToPointsY

Converts pixels to point size (1/72 of an inch) according to the PPI of the printer (vertical resolution).

```
FUNCTION PixelsToPointsY (BYVAL pix AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *pix* | The number of pixels to convert. |

#### Return value

LONG. The number of points. If there is not a printer attached, it returns 0.

# <a name="PointsToPixelsX"></a>PointsToPixelsX

Converts a point size (1/72 of an inch) to pixels according to the PPI of the printer (horizontal resolution).

```
FUNCTION PointsToPixelsX (BYVAL pts AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *pts* | The number of points to convert. |

#### Return value

LONG. The number of pixels. If there is not a printer attached, it returns 0.

# <a name="PointsToPixelsY"></a>PointsToPixelsY

Converts a point size (1/72 of an inch) to pixels according to the PPI of the printer (vertical resolution).

```
FUNCTION PointsToPixelsY (BYVAL pts AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *pts* | The number of points to convert. |

#### Return value

LONG. The number of pixels. If there is not a printer attached, it returns 0.

# <a name="GetPaperNames"></a>GetPaperNames

Returns a list of supported paper names (for example, Letter or Legal).

```
FUNCTION GetPaperNames () AS CWSTR
```

#### Return value

CWSTR. A list of supported paper names on success, or an empty string on failure. The names are separated by a carriage return and a line feed characters.

# <a name="PrintBitmap"></a>PrintBitmap

Prints a Windows bitmap to the attached printer.

```
FUNCTION PrintBitmap ( _
   BYREF wszDocName AS WSTRING, _
   BYVAL hbmp AS HBITMAP, _
   BYVAL bStretch AS BOOLEAN = FALSE, _
   BYVAL nStretchMode AS LONG = InterpolationModeHighQualityBicubic _
) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszDocName* | WSTRING. The document name. |
| *hbmp* | HBITMAP. Handle to the bitmap. |
| *bStretch* | BOOLEAN. Optional. True to strech the image or false. Defaults to False. |
| *nStretchMode* | LONG. Optional. Stretching mode. Defaults to InterpolationModeHighQualityBicubic.<br>Predefined constants:<br>*InterpolationModeLowQuality* = Specifies a low-quality mode.<br>*InterpolationModeHighQuality* = Specifies a high-quality mode.<br>*InterpolationModeBilinear* = Specifies bilinear interpolation. No prefiltering is done. This mode is not suitable for shrinking an image below 50 percent of its original size.<br>*InterpolationModeBicubic* = Specifies bicubic interpolation. No prefiltering is done. This mode is not suitable for shrinking an image below 25 percent of its original size.<br>*InterpolationModeNearestNeighbor* = Specifies nearest-neighbor interpolation.<br>*InterpolationModeHighQualityBilinear* = Specifies high-quality, bilinear interpolation. Prefiltering is performed to ensure high-quality shrinking.<br>*InterpolationModeHighQualityBicubic* = Specifies high-quality, bicubic interpolation. Prefiltering is performed to ensure high-quality shrinking. This mode produces the highest quality transformed images. |

#### Return value

BOOLEAN. Returns TRUE if the bitmap has been printed successfully, or FALSE otherwise.

# <a name="PrintBitmapToFile"></a>PrintBitmapToFile

Prints a Windows bitmap to the specified output file.

```
FUNCTION PrintBitmapToFile ( _
   BYREF wszDocName AS WSTRING, _
   BYREF wszOutputFileName AS WSTRING, _
   BYVAL hbmp AS HBITMAP, _
   BYVAL bStretch AS BOOLEAN = FALSE, _
   BYVAL nStretchMode AS LONG = InterpolationModeHighQualityBicubic _
) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *wszDocName* | WSTRING. The document name. |
| *wszOutputFileName* | WSTRING. The output file name. |
| *hbmp* | HBITMAP. Handle to the bitmap. |
| *bStretch* | BOOLEAN. Optional. True to strech the image or false. Defaults to False. |
| *nStretchMode* | LONG. Optional. Stretching mode. Defaults to InterpolationModeHighQualityBicubic.<br>Predefined constants:<br>*InterpolationModeLowQuality* = Specifies a low-quality mode.<br>*InterpolationModeHighQuality* = Specifies a high-quality mode.<br>*InterpolationModeBilinear* = Specifies bilinear interpolation. No prefiltering is done. This mode is not suitable for shrinking an image below 50 percent of its original size.<br>*InterpolationModeBicubic* = Specifies bicubic interpolation. No prefiltering is done. This mode is not suitable for shrinking an image below 25 percent of its original size.<br>*InterpolationModeNearestNeighbor* = Specifies nearest-neighbor interpolation.<br>*InterpolationModeHighQualityBilinear* = Specifies high-quality, bilinear interpolation. Prefiltering is performed to ensure high-quality shrinking.<br>*InterpolationModeHighQualityBicubic* = Specifies high-quality, bicubic interpolation. Prefiltering is performed to ensure high-quality shrinking. This mode produces the highest quality transformed images. |

#### Return value

BOOLEAN. Returns TRUE if the bitmap has been printed successfully, or FALSE otherwise.

# <a name="Collate"></a>Collate

Gets/sets the printer collating mode.

```
PROPERTY Collate () AS BOOLEAN
PROPERTY Collate (BYVAL nMode AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nMode* | LONG. The collating mode. Possible values: DMCOLLATE_TRUE, DMCOLLATE_FALSE. |

#### Return value

BOOLEAN. If the printer supports collating, the return value is TRUE; otherwise, the return value is FALSE. If TRUE, the pages that are printed should be collated. To collate is to print out the entire document before printing the next copy, as opposed to printing out each page of the document the required number of times.

# <a name="ColorMode"></a>ColorMode

Switches between color and monochrome on color printers. Some color printers have the capability to print using true black instead of a combination of cyan, magenta, and yellow (CMY). This usually creates darker and sharper text for documents. This option is only useful for color printers that support true black printing.

```
PROPERTY ColorMode () AS LONG
PROPERTY ColorMode (BYVAL nMode AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nMode* | LONG. The color mode. Possible values: DMCOLOR_MONOCHROME, DMCOLOR_COLOR. |

#### Return value

LONG. Returns the printer color mode: DMCOLOR_MONOCHROME or DMCOLOR_COLOR.

# <a name="Copies"></a>Copies

Gets/sets the number of copies to print if the device supports multiple-page copies.

```
PROPERTY Copies () AS BOOLEAN
PROPERTY Copies (BYVAL nCopies AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nCopies* | LONG. The number of copies to print if the device supports multiple-page copies. |

#### Return value

LONG. The number of copies

# <a name="Duplex"></a>Duplex

Checks if the printer supports duplex printing.

```
PROPERTY Duplex () AS BOOLEAN
```

#### Return value

BOOLEAN. If the printer supports duplex printing, the return value is TRUE; otherwise, the return value is FALSE.

# <a name="DuplexMode"></a>DuplexMode

Gets/sets the current duplex mode.

```
PROPERTY DuplexMode () AS LONG
PROPERTY DuplexMode (BYVAL nMode AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nMode* | LONG. The duplex mode.<br>*DMDUP_SIMPLEX* = Single sided printing.<br>*DMDUP_VERTICAL* = Page flipped on the vertical edge.<br>*DMDUP_HORIZONTAL* = Page flipped on the horizontal edge. |

#### Return value

LONG. If the printer supports duplex printing, returns the current duplex mode

# <a name="Orientation"></a>Orientation

Gets/sets the printer orientation.

```
PROPERTY Orientation () AS LONG
PROPERTY Orientation (BYVAL nOrientation AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nOrientation* | LONG. The printer orientation.<br>*DMORIENT_PORTRAIT* = Portrait.<br>*DMORIENT_LANDSCAPE* = Landscape. |

#### Return value

LONG. The printer orientation.

# <a name="PaperSize"></a>PaperSize

Gets/sets the printer paper size.

```
PROPERTY PaperSize () AS LONG
PROPERTY PaperSize (BYVAL nSize AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *nSize* | LONG. Specifies the printer paper size.<br>DMPAPER_LETTER = 1; DMPAPER_FIRST = DMPAPER_LETTER; DMPAPER_LETTERSMALL = 2; DMPAPER_TABLOID = 3; DMPAPER_LEDGER = 4; DMPAPER_LEGAL = 5; DMPAPER_STATEMENT = 6; DMPAPER_EXECUTIVE = 7; DMPAPER_A3 = 8; DMPAPER_A4 = 9; DMPAPER_A4SMALL = 10; DMPAPER_A5 = 11; DMPAPER_B4 = 12; DMPAPER_B5 = 13; DMPAPER_FOLIO = 14; DMPAPER_QUARTO = 15; DMPAPER_10X14 = 16; DMPAPER_11X17 = 17; DMPAPER_NOTE = 18; DMPAPER_ENV_9 = 19; DMPAPER_ENV_10 = 20; DMPAPER_ENV_11 = 21; DMPAPER_ENV_12 = 22; DMPAPER_ENV_14 = 23; DMPAPER_CSHEET = 24; DMPAPER_DSHEET = 25; DMPAPER_ESHEET = 26; DMPAPER_ENV_DL = 27; DMPAPER_ENV_C5 = 28; DMPAPER_ENV_C3 = 29; DMPAPER_ENV_C4 = 30; DMPAPER_ENV_C6 = 31; DMPAPER_ENV_C65 = 32; DMPAPER_ENV_B4 = 33; DMPAPER_ENV_B5 = 34; DMPAPER_ENV_B6 = 35; DMPAPER_ENV_ITALY = 36; DMPAPER_ENV_MONARCH = 37; DMPAPER_ENV_PERSONAL = 38; DMPAPER_FANFOLD_US = 39; DMPAPER_FANFOLD_STD_GERMAN = 40; DMPAPER_FANFOLD_LGL_GERMAN = 41; DMPAPER_ISO_B4 = 42; DMPAPER_JAPANESE_POSTCARD = 43; DMPAPER_9X11 = 44; DMPAPER_10X11 = 45; DMPAPER_15X11 = 46; DMPAPER_ENV_INVITE = 47; DMPAPER_RESERVED_48 = 48; DMPAPER_RESERVED_49 = 49; DMPAPER_LETTER_EXTRA = 50; DMPAPER_LEGAL_EXTRA = 51; DMPAPER_TABLOID_EXTRA = 52; DMPAPER_A4_EXTRA = 53; DMPAPER_LETTER_TRANSVERSE = 54; DMPAPER_A4_TRANSVERSE = 55; DMPAPER_LETTER_EXTRA_TRANSVERSE = 56; DMPAPER_A_PLUS = 57; DMPAPER_B_PLUS = 58; DMPAPER_LETTER_PLUS = 59; DMPAPER_A4_PLUS = 60; DMPAPER_A5_TRANSVERSE = 61; DMPAPER_B5_TRANSVERSE = 62; DMPAPER_A3_EXTRA = 63; DMPAPER_A5_EXTRA = 64; DMPAPER_B5_EXTRA = 65; DMPAPER_A2 = 66; DMPAPER_A3_TRANSVERSE = 67; DMPAPER_A3_EXTRA_TRANSVERSE = 68; DMPAPER_DBL_JAPANESE_POSTCARD = 69; DMPAPER_A6 = 70; DMPAPER_JENV_KAKU2 = 71; DMPAPER_JENV_KAKU3 = 72; DMPAPER_JENV_CHOU3 = 73; DMPAPER_JENV_CHOU4 = 74; DMPAPER_LETTER_ROTATED = 75; DMPAPER_A3_ROTATED = 76; DMPAPER_A4_ROTATED = 77; DMPAPER_A5_ROTATED = 78; DMPAPER_B4_JIS_ROTATED = 79; DMPAPER_B5_JIS_ROTATED = 80; DMPAPER_JAPANESE_POSTCARD_ROTATED = 81; DMPAPER_DBL_JAPANESE_POSTCARD_ROTATED = 82; DMPAPER_A6_ROTATED = 83; DMPAPER_JENV_KAKU2_ROTATED = 84; DMPAPER_JENV_KAKU3_ROTATED = 85; DMPAPER_JENV_CHOU3_ROTATED = 86; DMPAPER_JENV_CHOU4_ROTATED = 87; DMPAPER_B6_JIS = 88; DMPAPER_B6_JIS_ROTATED = 89; DMPAPER_12X11 = 90; DMPAPER_JENV_YOU4 = 91; DMPAPER_JENV_YOU4_ROTATED = 92; DMPAPER_P16K = 93; DMPAPER_P32K = 94; DMPAPER_P32KBIG = 95; DMPAPER_PENV_1 = 96; DMPAPER_PENV_2 = 97; DMPAPER_PENV_3 = 98; DMPAPER_PENV_4 = 99; DMPAPER_PENV_5 = 100; DMPAPER_PENV_6 = 101; DMPAPER_PENV_7 = 102; DMPAPER_PENV_8 = 103; DMPAPER_PENV_9 = 104; DMPAPER_PENV_10 = 105; DMPAPER_P16K_ROTATED = 106; DMPAPER_P32K_ROTATED = 107; DMPAPER_P32KBIG_ROTATED = 108; DMPAPER_PENV_1_ROTATED = 109; DMPAPER_PENV_2_ROTATED = 110; DMPAPER_PENV_3_ROTATED = 111; DMPAPER_PENV_4_ROTATED = 112; DMPAPER_PENV_5_ROTATED = 113; DMPAPER_PENV_6_ROTATED = 114; DMPAPER_PENV_7_ROTATED = 115; DMPAPER_PENV_8_ROTATED = 116; DMPAPER_PENV_9_ROTATED = 117; DMPAPER_PENV_10_ROTATED = 118; DMPAPER_LAST = DMPAPER_PENV_10_ROTATED; DMPAPER_USER = 256 |

#### Return value

LONG. The printer paper size.

