# AttachPrinter

Creates a device context (DC) for the specified printer and attaches it to the class.

```
AttachPrinter (BYREF wszPrinterName AS WSTRING) AS BOOLEAN
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
