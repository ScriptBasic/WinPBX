# ChoosePrinter

Displays a Print Dialog Box to select a printer.

```
ChoosePrinter (BYVAL hwndOwner AS HWND = NULL) AS BOOLEAN
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
