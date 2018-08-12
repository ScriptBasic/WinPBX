

# CPrint Class

Allows to attach/choose a printer and get/set its setting values.

### Methods

| Name       | Description |
| ---------- | ----------- |
| [AttachPrinter](#AttachPrinter) | Attaches the specified printer to the class. |
| [ChoosePrinter](#ChoosePrinter) | Displays the printer dialog to select a printer. |
| [PageSetup](#PageSetup) | Displays a Page Setup dialog box that enables the user to specify the attributes of a printed page. |
| GetPrinterName          | Returns the name of the attached printer. |
| GetDC                   | Returns the handle of the device context of the attached printer. |
| GetPPIX                 | Returns the number of pixels per inch of the page (horizontal resolution). |
| GetPPIY                 | Returns the number of pixels per inch of the page (vertical resolution). |
| GetHorizontalUnits      | Returns the width, in world units, of the printable area of the page. |
| GetVerticalUnits        | Returns the height, in world units, of the printable area of the page. |
| GetHorizontalResolution | Returns the width, in pixels, of the printable area of the page. |
| GetVerticalResolution   | Returns the height, in pixels, of the printable area of the page. |
| PixelsToPointsX         | Converts pixels to point size (1/72 of an inch) (horizontal resolution). |
| PixelsToPointsY         | Converts pixels to point size (1/72 of an inch) (vertical resolution). |
| PointsToPixelsX         | Converts a point size (1/72 of an inch) to pixels (horizontal resolution). |
| PointsToPixelsY         | Converts a point size (1/72 of an inch) to pixels (vertical resolution). |
| GetDocumentProperties   | Retrieves printer initialization information. |
| SetPrinterInfo          | Sets printer data. |
| GetPaperNames           | Returns a list of supported paper names. |
| PrintBitmap             | Prints a Windows bitmap in the attached printer. |
| PrintBitmapToFile       | Prints a Windows bitmap in the specified file. |

### Properties

| Name       | Description |
| ---------- | ----------- |
| Collate                | Gets/sets the collate setting value. |
| ColorMode              | Switches between color and monochrome on color printers. |
| Copies                 | Gets/sets the number of copies to print if the device supports multiple-page copies. |
| Duplex                 | Checks if the printer supports duplex printing. |
| DuplexMode             | Gets/sets the current duplex mode. |
| Orientation            | Gets/sets the printer orientation. |
| PaperSize              | Gets/sets the printer paper size. |
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
