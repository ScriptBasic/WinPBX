

# CPrint Class

Allows to attach/choose a printer and get/set its setting values.

### Methods

| Name       | Description |
| ---------- | ----------- |
| [AttachPrinter](./AttachPrinter.md) | Attaches the specified printer to the class. |
| ChoosePrinter           | Displays the printer dialog to select a printer. |
| PageSetup               | Displays a Page Setup dialog box that enables the user to specify the attributes of a printed page. |
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
