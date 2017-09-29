' ########################################################################################
' Microsoft Windows
' File: AfxPrint.inc
' Contents: Printer wrapper functions.
' Copyright (c) 2011 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AFXPRINT_INC = 1

#INCLUDE ONCE "windows.inc"
' // Needed if user has defined %WIN32_LEAN_AND_MEAN
#INCLUDE ONCE "winspool.inc"
#INCLUDE ONCE "shellapi.inc"

' ========================================================================================
' Returns a list with port names of the available printers, print servers, domains, or print providers.
' Names are separated with a carriage return and a line feed characters.
' ========================================================================================
FUNCTION AfxEnumPrinterPorts () AS WSTRING
   LOCAL i, Level, cbNeeded, cbReturned AS LONG, bstrNames AS WSTRING
   DIM   Pi5(0) AS LOCAL PRINTER_INFO_5W
   Level = 5
   EnumPrintersW %PRINTER_ENUM_LOCAL, BYVAL %NULL, Level, BYVAL %NULL, 0, cbNeeded, cbReturned
   REDIM Pi5(0 TO cbNeeded \ SIZEOF(Pi5(0)))
   EnumPrintersW %PRINTER_ENUM_LOCAL, "", Level, BYVAL VARPTR(Pi5(0)), _
         SIZEOF(Pi5(0)) * (UBOUND(Pi5) + 1), cbNeeded, cbReturned
   FOR i = 0 TO cbReturned - 1
      bstrNames += Pi5(i).@pPortName
      IF i < cbReturned - 1 THEN bstrNames += $CRLF
   NEXT
   FUNCTION = bstrNames
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns a list with the available printers, print servers, domains, or print providers.
' Names are separated with a carriage return and a line feed characters.
' ========================================================================================
FUNCTION AfxEnumPrinters () AS WSTRING
   LOCAL i, Level, cbNeeded, cbReturned AS LONG, bstrNames AS WSTRING
   DIM   Pi5(0) AS LOCAL PRINTER_INFO_5W
   Level = 5
   EnumPrintersW %PRINTER_ENUM_LOCAL, BYVAL %NULL, Level, BYVAL %NULL, 0, cbNeeded, cbReturned
   REDIM Pi5(0 TO cbNeeded \ SIZEOF(Pi5(0)))
   EnumPrintersW %PRINTER_ENUM_LOCAL, "", Level, BYVAL VARPTR(Pi5(0)), _
         SIZEOF(Pi5(0)) * (UBOUND(Pi5) + 1), cbNeeded, cbReturned
   FOR i = 0 TO cbReturned - 1
      bstrNames += Pi5(i).@pPrinterName
      IF i < cbReturned - 1 THEN bstrNames += $CRLF
   NEXT
   FUNCTION = bstrNames
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the name of the default printer.
' ========================================================================================
FUNCTION AfxGetDefaultPrinter () AS WSTRING
   LOCAL buffer AS WSTRINGZ * %MAX_PATH
   GetProfileStringW "WINDOWS", "DEVICE", "", buffer, SIZEOF(buffer)
   FUNCTION = PARSE$(buffer, 1)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the name of the default printer device.
' ========================================================================================
FUNCTION AfxGetDefaultPrinterDevice () AS WSTRING
   LOCAL buffer AS WSTRINGZ * %MAX_PATH
   GetProfileStringW "WINDOWS", "DEVICE", "", buffer, SIZEOF(buffer)
   FUNCTION = PARSE$(buffer, 2)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the name of the default printer driver.
' ========================================================================================
FUNCTION AfxGetDefaultPrinterDriver () AS WSTRING
   LOCAL buffer AS WSTRINGZ * %MAX_PATH
   GetProfileStringW "WINDOWS", "DEVICE", "", buffer, SIZEOF(buffer)
   FUNCTION = PARSE$(buffer, 1)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the name of the default printer port.
' ========================================================================================
FUNCTION AfxGetDefaultPrinterPort () AS WSTRING
   LOCAL buffer AS WSTRINGZ * %MAX_PATH
   GetProfileStringW "WINDOWS", "DEVICE", "", buffer, SIZEOF(buffer)
   FUNCTION = PARSE$(buffer, 3)
END FUNCTION
' ========================================================================================

' ========================================================================================
' If the printer supports collating, the return value is 1; otherwise, the return value is zero.
' ========================================================================================
FUNCTION AfxGetPrinterCollate (BYVAL bstrPrinterName AS WSTRING) AS LONG
   FUNCTION = DeviceCapabilitiesW(BYCOPY bstrPrinterName, BYVAL %NULL, %DC_COLLATE, BYVAL %NULL, BYVAL %NULL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the printer collate status.
' DMCOLLATE_FALSE = Collate is turned off
' DMCOLLATE_TRUE = Collate is turned on
' ========================================================================================
FUNCTION AfxGetPrinterCollateStatus (BYVAL bstrPrinterName AS WSTRING) AS LONG

   LOCAL hPrinter AS DWORD
   LOCAL pDevMode AS DEVMODEW PTR
   LOCAL pi2 AS PRINTER_INFO_2W PTR
   LOCAL bufferDoc AS STRING
   LOCAL dwNeeded AS DWORD
   LOCAL nRet AS LONG

   ' // Start by opening the printer
   IF OpenPrinterW(BYCOPY bstrPrinterName, hPrinter, BYVAL %NULL) = 0 THEN EXIT FUNCTION
   ' // Allocate a buffer of the correct size
   dwNeeded = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL %NULL, BYVAL %NULL, 0)
   bufferDoc = SPACE$(dwNeeded)
   ' // Retrieve the printer configuration data
   nRet = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL STRPTR(bufferDoc), BYVAL %NULL, %DM_OUT_BUFFER)
   IF nRet <> %IDOK THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF
   ' // Cast it to a DEVMODEW structure
   pDevMode = STRPTR(bufferDoc)
   ' // Return the collate status
   IF @pDevMode.dmFields AND %DM_COLLATE THEN
      FUNCTION = @pDevMode.dmCollate
   END IF
   ' // Finished with the printer
   ClosePrinter(hPrinter)

END FUNCTION
' ========================================================================================

' ========================================================================================
' If the printer supports color printing, the return value is 1; otherwise, the return value is zero.
' ========================================================================================
FUNCTION AfxGetPrinterColorMode (BYVAL bstrPrinterName AS WSTRING) AS LONG
   FUNCTION = DeviceCapabilitiesW(BYCOPY bstrPrinterName, BYVAL %NULL, %DC_COLORDEVICE, BYVAL %NULL, BYVAL %NULL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the number of copies printed if the device supports multiple-page copies.
' ========================================================================================
FUNCTION AfxGetPrinterCopies (BYVAL bstrPrinterName AS WSTRING) AS LONG

   LOCAL hPrinter AS DWORD
   LOCAL pDevMode AS DEVMODEW PTR
   LOCAL pi2 AS PRINTER_INFO_2W PTR
   LOCAL bufferDoc AS STRING
   LOCAL dwNeeded AS DWORD
   LOCAL nRet AS LONG

   ' // Start by opening the printer
   IF OpenPrinterW(BYCOPY bstrPrinterName, hPrinter, BYVAL %NULL) = 0 THEN EXIT FUNCTION
   ' // Allocate a buffer of the correct size
   dwNeeded = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL %NULL, BYVAL %NULL, 0)
   bufferDoc = SPACE$(dwNeeded)
   ' // Retrieve the printer configuration data
   nRet = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL STRPTR(bufferDoc), BYVAL %NULL, %DM_OUT_BUFFER)
   IF nRet <> %IDOK THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF
   ' // Cast it to a DEVMODEW structure
   pDevMode = STRPTR(bufferDoc)
   ' // Return the number of copies
   FUNCTION = @pDevMode.dmCopies
   ' // Finished with the printer
   ClosePrinter(hPrinter)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the version number of the printer driver.
' ========================================================================================
FUNCTION AfxGetPrinterDriverVersion (BYVAL bstrPrinterName AS WSTRING) AS LONG
   FUNCTION = DeviceCapabilitiesW(BYCOPY bstrPrinterName, BYVAL %NULL, %DC_DRIVER, BYVAL %NULL, BYVAL %NULL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' If the printer supports duplex printing, the return value is 1; otherwise, the return value is zero.
' ========================================================================================
FUNCTION AfxGetPrinterDuplex (BYVAL bstrPrinterName AS WSTRING) AS LONG
   FUNCTION = DeviceCapabilitiesW(BYCOPY bstrPrinterName, BYVAL %NULL, %DC_DUPLEX, BYVAL %NULL, BYVAL %NULL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the printer name for a given port name.
' ========================================================================================
FUNCTION AfxGetPrinterFromPort (BYVAL bstrPortName AS WSTRING) AS WSTRING
   LOCAL i, Level, cbNeeded, cbReturned AS LONG, bstrNames AS WSTRING
   DIM   Pi5(0) AS LOCAL PRINTER_INFO_5W
   Level = 5
   EnumPrintersW %PRINTER_ENUM_LOCAL, BYVAL %NULL, Level, BYVAL %NULL, 0, cbNeeded, cbReturned
   REDIM Pi5(0 TO cbNeeded \ SIZEOF(Pi5(0)))
   EnumPrintersW %PRINTER_ENUM_LOCAL, "", Level, BYVAL VARPTR(Pi5(0)), _
         SIZEOF(Pi5(0)) * (UBOUND(Pi5) + 1), cbNeeded, cbReturned
   FOR i = 0 TO cbReturned - 1
      IF UCASE$(Pi5(i).@pPortName) = UCASE$(bstrPortName) THEN
         bstrNames += Pi5(i).@pPrinterName & $CRLF
      END IF
   NEXT
   ' // Remove the last $CRLF
   IF LEN(bstrNames) THEN bstrNames = LEFT$(bstrNames, LEN(bstrNames) - 2)
   FUNCTION = bstrNames
END FUNCTION
' ========================================================================================

' ========================================================================================
' Width, in pixels, of the printable area of the page.
' ========================================================================================
FUNCTION AfxGetPrinterHorizontalResolution (BYVAL bstrPrinterName AS WSTRING) AS LONG
   LOCAL hdc AS DWORD
   LOCAL nResult AS LONG
   hdc = CreateICW(BYVAL %NULL, BYCOPY bstrPrinterName, BYVAL %NULL, BYVAL %NULL)
   IF hdc = 0 THEN EXIT FUNCTION
   nResult = GetDeviceCaps(hdc, %HORZRES)
   DeleteDC hdc
   FUNCTION = nResult
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the maximum number of copies the device can print.
' If the function returns -1, this may mean either that the capability is not supported or
' there was a general function failure.
' ========================================================================================
FUNCTION AfxGetPrinterMaxCopies (BYVAL bstrPrinterName AS WSTRING) AS LONG
   FUNCTION = DeviceCapabilitiesW(BYCOPY bstrPrinterName, BYVAL %NULL, %DC_COPIES, BYVAL %NULL, BYVAL %NULL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the maximum paper width in tenths of a millimeter.
' ========================================================================================
FUNCTION AfxGetPrinterMaxPaperHeight (BYVAL bstrPrinterName AS WSTRING) AS LONG
   LOCAL r AS LONG
   r = DeviceCapabilitiesW(BYCOPY bstrPrinterName, BYVAL %NULL, %DC_MAXEXTENT, BYVAL %NULL, BYVAL %NULL)
   IF r = -1 THEN EXIT FUNCTION
   FUNCTION = HI(WORD, r)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the maximum paper width in tenths of a millimeter.
' ========================================================================================
FUNCTION AfxGetPrinterMaxPaperWidth (BYVAL bstrPrinterName AS WSTRING) AS LONG
   LOCAL r AS LONG
   r = DeviceCapabilitiesW(BYCOPY bstrPrinterName, BYVAL %NULL, %DC_MAXEXTENT, BYVAL %NULL, BYVAL %NULL)
   IF r = -1 THEN EXIT FUNCTION
   FUNCTION = LO(WORD, r)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the names of the paper forms that are currently available for use.
' ========================================================================================
FUNCTION AfxGetPrinterMediaReady (BYVAL bstrPrinterName AS WSTRING) AS WSTRING
   LOCAL i, r AS LONG, bstrNames AS WSTRING
   r = DeviceCapabilitiesW(BYCOPY bstrPrinterName, BYVAL %NULL, %DC_MEDIAREADY, BYVAL %NULL, BYVAL %NULL)
   IF r = -1 THEN EXIT FUNCTION
   REDIM wszNames(r - 1) AS WSTRINGZ * 64
   r = DeviceCapabilitiesW(BYCOPY bstrPrinterName, BYVAL %NULL, %DC_MEDIAREADY, wszNames(0), BYVAL %NULL)
   IF r < 1 THEN EXIT FUNCTION
   FOR i = 0 TO r - 1
      bstrNames += wszNames(i)
      IF i < r - 1 THEN bstrNames += $CRLF
   NEXT
   FUNCTION = bstrNames
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the minimum paper width in tenths of a millimeter.
' ========================================================================================
FUNCTION AfxGetPrinterMinPaperHeight (BYVAL bstrPrinterName AS WSTRING) AS LONG
   LOCAL r AS LONG
   r = DeviceCapabilitiesW(BYCOPY bstrPrinterName, BYVAL %NULL, %DC_MINEXTENT, BYVAL %NULL, BYVAL %NULL)
   IF r = -1 THEN EXIT FUNCTION
   FUNCTION = HI(WORD, r)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the minimum paper width in tenths of a millimeter.
' ========================================================================================
FUNCTION AfxGetPrinterMinPaperWidth (BYVAL bstrPrinterName AS WSTRING) AS LONG
   LOCAL r AS LONG
   r = DeviceCapabilitiesW(BYCOPY bstrPrinterName, BYVAL %NULL, %DC_MINEXTENT, BYVAL %NULL, BYVAL %NULL)
   IF r = -1 THEN EXIT FUNCTION
   FUNCTION = LO(WORD, r)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the printer orientation.
' The return value can be one of the following:
' - DMORIENT_PORTRAIT = Portrait
' - DMORIENT_LANDSCAPE = Landscape
' ========================================================================================
FUNCTION AfxGetPrinterOrientation (BYVAL bstrPrinterName AS WSTRING) AS LONG

   LOCAL hPrinter AS DWORD
   LOCAL pDevMode AS DEVMODEW PTR
   LOCAL pi2 AS PRINTER_INFO_2W PTR
   LOCAL bufferDoc AS STRING
   LOCAL dwNeeded AS DWORD
   LOCAL nRet AS LONG

   ' // Start by opening the printer
   IF OpenPrinterW(BYCOPY bstrPrinterName, hPrinter, BYVAL %NULL) = 0 THEN EXIT FUNCTION
   ' // Allocate a buffer of the correct size
   dwNeeded = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL %NULL, BYVAL %NULL, 0)
   bufferDoc = SPACE$(dwNeeded)
   ' // Retrieve the printer configuration data
   nRet = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL STRPTR(bufferDoc), BYVAL %NULL, %DM_OUT_BUFFER)
   IF nRet <> %IDOK THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF
   ' // Cast it to a DEVMODEW structure
   pDevMode = STRPTR(bufferDoc)
   ' // Return the orientation
   FUNCTION = @pDevMode.dmOrientation

   ' // Finished with the printer
   ClosePrinter(hPrinter)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the relationship between portrait and landscape orientations for a device, in
' terms of the number of degrees that portrait orientation is rotated counterclockwise to
' produce landscape orientation. The return value can be one of the following:
'   0  No landscape orientation.
'  90  Portrait is rotated 90 degrees to produce landscape.
' 180  Portrait is rotated 180 degrees to produce landscape.
' 270  Portrait is rotated 270 degrees to produce landscape.
' ========================================================================================
FUNCTION AfxGetPrinterOrientationDegrees (BYVAL bstrPrinterName AS WSTRING) AS LONG
   FUNCTION = DeviceCapabilitiesW(BYCOPY bstrPrinterName, BYVAL %NULL, %DC_ORIENTATION, BYVAL %NULL, BYVAL %NULL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns a list of supported paper names (for example, Letter or Legal).
' The names are separated by a carriage return and a line feed characters.
' ========================================================================================
FUNCTION AfxGetPrinterPaperNames (BYVAL bstrPrinterName AS WSTRING) AS WSTRING
   LOCAL i AS LONG
   LOCAL r AS LONG
   LOCAL bstrNames AS WSTRING
   r = DeviceCapabilitiesW(BYCOPY bstrPrinterName, BYVAL %NULL, %DC_PAPERNAMES, BYVAL %NULL, BYVAL %NULL)
   IF r = -1 THEN EXIT FUNCTION
   REDIM wszNames(r - 1) AS WSTRINGZ * 64
   r = DeviceCapabilitiesW(BYCOPY bstrPrinterName, BYVAL %NULL, %DC_PAPERNAMES, wszNames(0), BYVAL %NULL)
   IF r < 1 THEN EXIT FUNCTION
   FOR i = 0 TO r - 1
      bstrNames += wszNames(i)
      IF i < r - 1 THEN bstrNames += $CRLF
   NEXT
   FUNCTION = bstrNames
END FUNCTION
' ========================================================================================

' ========================================================================================
' Specifies the paper size for which the printer is currently configured.
' ========================================================================================
FUNCTION AfxGetPrinterPaperSize (BYVAL bstrPrinterName AS WSTRING) AS LONG

   LOCAL hPrinter AS DWORD
   LOCAL pDevMode AS DEVMODEW PTR
   LOCAL pi2 AS PRINTER_INFO_2W PTR
   LOCAL bufferDoc AS STRING
   LOCAL dwNeeded AS DWORD
   LOCAL nRet AS LONG

   ' // Start by opening the printer
   IF OpenPrinterW(BYCOPY bstrPrinterName, hPrinter, BYVAL %NULL) = 0 THEN EXIT FUNCTION
   ' // Allocate a buffer of the correct size
   dwNeeded = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL %NULL, BYVAL %NULL, 0)
   bufferDoc = SPACE$(dwNeeded)
   ' // Retrieve the printer configuration data
   nRet = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL STRPTR(bufferDoc), BYVAL %NULL, %DM_OUT_BUFFER)
   IF nRet <> %IDOK THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF
   ' // Cast it to a DEVMODEW structure
   pDevMode = STRPTR(bufferDoc)
   ' // Return the number of copies
   FUNCTION = @pDevMode.dmPaperSize

   ' // Finished with the printer
   ClosePrinter(hPrinter)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns a list of each supported paper sizes, in tenths of a millimeter.
' Each entry if formatted as "<width> x <height>" and separated by a carriage return and a
' line feed characters.
' ========================================================================================
FUNCTION AfxGetPrinterPaperSizes (BYVAL bstrPrinterName AS WSTRING) AS WSTRING
   LOCAL i, r AS LONG, bstrSizes AS WSTRING
   r = DeviceCapabilitiesW(BYCOPY bstrPrinterName, BYVAL %NULL, %DC_PAPERSIZE, BYVAL %NULL, BYVAL %NULL)
   IF r = -1 THEN EXIT FUNCTION
   REDIM pSizes(r - 1) AS POINT
   r = DeviceCapabilitiesW(BYCOPY bstrPrinterName, BYVAL %NULL, %DC_PAPERSIZE, pSizes(0), BYVAL %NULL)
   IF r < 1 THEN EXIT FUNCTION
   FOR i = 0 TO r - 1
      bstrSizes += FORMAT$(pSizes(i).x) & " x " & FORMAT$(pSizes(i).y)
      IF i < r - 1 THEN bstrSizes += $CRLF
   NEXT
   FUNCTION = bstrSizes
END FUNCTION
' ========================================================================================

' ========================================================================================
' The height of the physical page, in device units. For example, a printer set to print at
' 600 dpi on 8.5-by-11-inch paper has a physical height value of 6600 device units. Note
' that the physical page is almost always greater than the printable area of the page,
' and never smaller.
' ========================================================================================
FUNCTION AfxGetPrinterPhysicalHeight (BYVAL bstrPrinterName AS WSTRING) AS LONG
   LOCAL hdc AS DWORD, nResult AS LONG
   hdc = CreateICW(BYVAL %NULL, BYCOPY bstrPrinterName, BYVAL %NULL, BYVAL %NULL)
   IF hdc = 0 THEN EXIT FUNCTION
   nResult = GetDeviceCaps(hdc, %PHYSICALHEIGHT)
   DeleteDC hdc
   FUNCTION = nResult
END FUNCTION
' ========================================================================================

' ========================================================================================
' The distance from the left edge of the physical page to the left edge of the printable area,
' in device units. For example, a printer set to print at 600 dpi on 8.5-by-11-inch paper,
' that cannot print on the leftmost 0.25-inch of paper, has a horizontal physical offset
' of 150 device units.
' ========================================================================================
FUNCTION AfxGetPrinterPhysicalOffsetX (BYVAL bstrPrinterName AS WSTRING) AS LONG
   LOCAL hdc AS DWORD, nResult AS LONG
   hdc = CreateICW(BYVAL %NULL, BYCOPY bstrPrinterName, BYVAL %NULL, BYVAL %NULL)
   IF hdc = 0 THEN EXIT FUNCTION
   nResult = GetDeviceCaps(hdc, %PHYSICALOFFSETX)
   DeleteDC hdc
   FUNCTION = nResult
END FUNCTION
' ========================================================================================

' ========================================================================================
' The distance from the top edge of the physical page to the top edge of the printable
' area, in device units. For example, a printer set to print at 600 dpi on 8.5-by-11-inch
' paper, that cannot print on the topmost 0.5-inch of paper, has a vertical physical
' offset of 300 device units.
' ========================================================================================
FUNCTION AfxGetPrinterPhysicalOffsetY (BYVAL bstrPrinterName AS WSTRING) AS LONG
   LOCAL hdc AS DWORD, nResult AS LONG
   hdc = CreateICW(BYVAL %NULL, BYCOPY bstrPrinterName, BYVAL %NULL, BYVAL %NULL)
   IF hdc = 0 THEN EXIT FUNCTION
   nResult = GetDeviceCaps(hdc, %PHYSICALOFFSETY)
   DeleteDC hdc
   FUNCTION = nResult
END FUNCTION
' ========================================================================================

' ========================================================================================
' The width of the physical page, in device units. For example, a printer set to print at
' 600 dpi on 8.5-x11-inch paper has a physical width value of 5100 device units. Note that
' the physical page is almost always greater than the printable area of the page, and
' never smaller.
' ========================================================================================
FUNCTION AfxGetPrinterPhysicalWidth (BYVAL bstrPrinterName AS WSTRING) AS LONG
   LOCAL hdc AS DWORD, nResult AS LONG
   hdc = CreateICW(BYVAL %NULL, BYCOPY bstrPrinterName, BYVAL %NULL, BYVAL %NULL)
   IF hdc = 0 THEN EXIT FUNCTION
   nResult = GetDeviceCaps(hdc, %PHYSICALWIDTH)
   DeleteDC hdc
   FUNCTION = nResult
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the port name for a given printer name.
' ========================================================================================
FUNCTION AfxGetPrinterPort (BYVAL bstrPrinterName AS WSTRING) AS WSTRING
   LOCAL i, Level, cbNeeded, cbReturned AS LONG
   DIM   Pi5(0) AS LOCAL PRINTER_INFO_5W
   Level = 5
   EnumPrintersW %PRINTER_ENUM_LOCAL, BYVAL %NULL, Level, BYVAL %NULL, 0, cbNeeded, cbReturned
   REDIM Pi5(0 TO cbNeeded \ SIZEOF(Pi5(0)))
   EnumPrintersW %PRINTER_ENUM_LOCAL, "", Level, BYVAL VARPTR(Pi5(0)), _
         SIZEOF(Pi5(0)) * (UBOUND(Pi5) + 1), cbNeeded, cbReturned
   FOR i = 0 TO cbReturned - 1
      IF UCASE$(Pi5(i).@pPrinterName) = UCASE$(bstrPrinterName) THEN
         FUNCTION = Pi5(i).@pPortName
         EXIT FOR
      END IF
   NEXT
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the printer's print rate.
' ========================================================================================
FUNCTION AfxGetPrinterPrintRate (BYVAL bstrPrinterName AS WSTRING) AS LONG
   FUNCTION = DeviceCapabilitiesW(BYCOPY bstrPrinterName, BYVAL %NULL, %DC_PRINTRATE, BYVAL %NULL, BYVAL %NULL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the printer's print rate, in pages per minute.
' ========================================================================================
FUNCTION AfxGetPrinterPrintRatePPM (BYVAL bstrPrinterName AS WSTRING) AS LONG
   FUNCTION = DeviceCapabilitiesW(BYCOPY bstrPrinterName, BYVAL %NULL, %DC_PRINTRATEPPM, BYVAL %NULL, BYVAL %NULL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns one of the following values:
' PRINTRATEUNIT_CPS   Characters per second.
' PRINTRATEUNIT_IPM   Inches per minute.
' PRINTRATEUNIT_LPM   Lines per minute.
' PRINTRATEUNIT_PPM   Pages per minute.
' ========================================================================================
FUNCTION AfxGetPrinterPrintRateUnit (BYVAL bstrPrinterName AS WSTRING) AS LONG
   FUNCTION = DeviceCapabilitiesW(BYCOPY bstrPrinterName, BYVAL %NULL, %DC_PRINTRATEUNIT, BYVAL %NULL, BYVAL %NULL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the printer print quality mode.
' The return value can be one of the following:
' - DMRES_DRAFT  = Draft
' - DMRES_LOW    = Low
' - DMRES_MEDIUM = Medium
' - DMRES_HIGH   = High
' ========================================================================================
FUNCTION AfxGetPrinterQualityMode (BYVAL bstrPrinterName AS WSTRING) AS LONG

   LOCAL hPrinter AS DWORD
   LOCAL pDevMode AS DEVMODEW PTR
   LOCAL pi2 AS PRINTER_INFO_2W PTR
   LOCAL bufferDoc AS STRING
   LOCAL dwNeeded AS DWORD
   LOCAL nRet AS LONG

   ' // Start by opening the printer
   IF OpenPrinterW(BYCOPY bstrPrinterName, hPrinter, BYVAL %NULL) = 0 THEN EXIT FUNCTION
   ' // Allocate a buffer of the correct size
   dwNeeded = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL %NULL, BYVAL %NULL, 0)
   bufferDoc = SPACE$(dwNeeded)
   ' // Retrieve the printer configuration data
   nRet = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL STRPTR(bufferDoc), BYVAL %NULL, %DM_OUT_BUFFER)
   IF nRet <> %IDOK THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF
   ' // Cast it to a DEVMODEW structure
   pDevMode = STRPTR(bufferDoc)
   ' // Return the prnt quality
   FUNCTION = @pDevMode.dmPrintQuality

   ' // Finished with the printer
   ClosePrinter(hPrinter)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Specifies the factor by which the printed output is to be scaled. The apparent page size
' is scaled from the physical page size by a factor of dmScale /100. For example, a
' letter-sized page with a dmScale value of 50 would contain as much data as a page of
' 17- by 22-inches because the output text and graphics would be half their original
' height and width.
' ========================================================================================
FUNCTION AfxGetPrinterScale (BYVAL bstrPrinterName AS WSTRING) AS LONG

   LOCAL hPrinter AS DWORD
   LOCAL pDevMode AS DEVMODEW PTR
   LOCAL pi2 AS PRINTER_INFO_2W PTR
   LOCAL bufferDoc AS STRING
   LOCAL dwNeeded AS DWORD
   LOCAL nRet AS LONG

   ' // Start by opening the printer
   IF OpenPrinterW(BYCOPY bstrPrinterName, hPrinter, BYVAL %NULL) = 0 THEN EXIT FUNCTION
   ' // Allocate a buffer of the correct size
   dwNeeded = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL %NULL, BYVAL %NULL, 0)
   bufferDoc = SPACE$(dwNeeded)
   ' // Retrieve the printer configuration data
   nRet = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL STRPTR(bufferDoc), BYVAL %NULL, %DM_OUT_BUFFER)
   IF nRet <> %IDOK THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF
   ' // Cast it to a DEVMODEW structure
   pDevMode = STRPTR(bufferDoc)
   ' // Return the number of copies
   FUNCTION = @pDevMode.dmScale

   ' // Finished with the printer
   ClosePrinter(hPrinter)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Scaling factor for the x-axis of the printer.
' ========================================================================================
FUNCTION AfxGetPrinterScalingFactorX (BYVAL bstrPrinterName AS WSTRING) AS LONG
   LOCAL hdc AS DWORD
   LOCAL nResult AS LONG
   hdc = CreateICW(BYVAL %NULL, BYCOPY bstrPrinterName, BYVAL %NULL, BYVAL %NULL)
   IF hdc = 0 THEN EXIT FUNCTION
   nResult = GetDeviceCaps(hdc, %SCALINGFACTORX)
   DeleteDC hdc
   FUNCTION = nResult
END FUNCTION
' ========================================================================================

' ========================================================================================
' Scaling factor for the y-axis of the printer.
' ========================================================================================
FUNCTION AfxGetPrinterScalingFactorY (BYVAL bstrPrinterName AS WSTRING) AS LONG
   LOCAL hdc AS DWORD
   LOCAL nResult AS LONG
   hdc = CreateICW(BYVAL %NULL, BYCOPY bstrPrinterName, BYVAL %NULL, BYVAL %NULL)
   IF hdc = 0 THEN EXIT FUNCTION
   nResult = GetDeviceCaps(hdc, %SCALINGFACTORY)
   DeleteDC hdc
   FUNCTION = nResult
END FUNCTION
' ========================================================================================

' ========================================================================================
' Specifies the paper source.
' Returns one of the following values:
' DMBIN_UPPER         = 1
' DMBIN_LOWER         = 2
' DMBIN_MIDDLE        = 3
' DMBIN_MANUAL        = 4
' DMBIN_ENVELOPE      = 5
' DMBIN_ENVMANUAL     = 6
' DMBIN_AUTO          = 7
' DMBIN_TRACTOR       = 8
' DMBIN_SMALLFMT      = 9
' DMBIN_LARGEFMT      = 10
' DMBIN_LARGECAPACITY = 11
' DMBIN_CASSETTE      = 14
' DMBIN_FORMSOURCE    = 15
' ========================================================================================
FUNCTION AfxGetPrinterTray (BYVAL bstrPrinterName AS WSTRING) AS LONG

   LOCAL hPrinter AS DWORD
   LOCAL pDevMode AS DEVMODEW PTR
   LOCAL pi2 AS PRINTER_INFO_2W PTR
   LOCAL bufferDoc AS STRING
   LOCAL dwNeeded AS DWORD
   LOCAL nRet AS LONG

   ' // Start by opening the printer
   IF OpenPrinterW(BYCOPY bstrPrinterName, hPrinter, BYVAL %NULL) = 0 THEN EXIT FUNCTION
   ' // Allocate a buffer of the correct size
   dwNeeded = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL %NULL, BYVAL %NULL, 0)
   bufferDoc = SPACE$(dwNeeded)
   ' // Retrieve the printer configuration data
   nRet = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL STRPTR(bufferDoc), BYVAL %NULL, %DM_OUT_BUFFER)
   IF nRet <> %IDOK THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF
   ' // Cast it to a DEVMODEW structure
   pDevMode = STRPTR(bufferDoc)
   ' // Return the number of copies
   FUNCTION = @pDevMode.dmDefaultSource

   ' // Finished with the printer
   ClosePrinter(hPrinter)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns a list with the names of the printer's paper bins.
' The names are separated by a carriage return and a line feed characters.
' ========================================================================================
FUNCTION AfxGetPrinterTrayNames (BYVAL bstrPrinterName AS WSTRING) AS WSTRING
   LOCAL i, r AS LONG, bstrNames AS WSTRING
   r = DeviceCapabilitiesW(BYCOPY bstrPrinterName, BYVAL %NULL, %DC_BINNAMES, BYVAL %NULL, BYVAL %NULL)
   IF r = -1 THEN EXIT FUNCTION
   REDIM wszNames(r - 1) AS WSTRINGZ * 24
   r = DeviceCapabilitiesW(BYCOPY bstrPrinterName, BYVAL %NULL, %DC_BINNAMES, wszNames(0), BYVAL %NULL)
   IF r < 1 THEN EXIT FUNCTION
   FOR i = 0 TO r - 1
      bstrNames += wszNames(i)
      IF i < r - 1 THEN bstrNames += $CRLF
   NEXT
   FUNCTION = bstrNames
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the abilities of the driver to use TrueType fonts.
' The return value can be one or more of the following:
' DCTT_BITMAP   Device can print TrueType fonts as graphics.
' DCTT_DOWNLOAD Device can download TrueType fonts.
' DCTT_SUBDEV   Device can substitute device fonts for TrueType fonts.
' ========================================================================================
FUNCTION AfxGetPrinterTrueType (BYVAL bstrPrinterName AS WSTRING) AS LONG
   FUNCTION = DeviceCapabilitiesW(BYCOPY bstrPrinterName, BYVAL %NULL, %DC_TRUETYPE, BYVAL %NULL, BYVAL %NULL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Width, in pixels, of the printable area of the page.
' ========================================================================================
FUNCTION AfxGetPrinterVerticalResolution (BYVAL bstrPrinterName AS WSTRING) AS LONG
   LOCAL hdc AS DWORD
   LOCAL nResult AS LONG
   hdc = CreateICW(BYVAL %NULL, BYCOPY bstrPrinterName, BYVAL %NULL, BYVAL %NULL)
   IF hdc = 0 THEN EXIT FUNCTION
   nResult = GetDeviceCaps(hdc, %VERTRES)
   DeleteDC hdc
   FUNCTION = nResult
END FUNCTION
' ========================================================================================

' ========================================================================================
' Opens an instance of Explorer with the Printers and Faxes folder selected.
' ========================================================================================
FUNCTION AfxOpenPrintersFolder () AS LONG
   FUNCTION = ShellExecuteW(0, "open", "explorer.exe", "/e,::{2227A280-3AEA-1069-A2DE-08002B30309D}", BYVAL %NULL, %SW_SHOWNORMAL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Switches between color and monochrome on color printers.
' The following are the possible values:
'   DMCOLOR_COLOR
'   DMCOLOR_MONOCHROME
' ========================================================================================
FUNCTION AfxSetPrinterColorMode (BYVAL bstrPrinterName AS WSTRING, BYVAL nMode AS LONG) AS LONG

   LOCAL hPrinter AS DWORD
   LOCAL pDevMode AS DEVMODEW PTR
   LOCAL pi2 AS PRINTER_INFO_2W PTR
   LOCAL pd AS PRINTER_DEFAULTS
   LOCAL bufferPrn AS STRING
   LOCAL bufferDoc AS STRING
   LOCAL dwNeeded AS DWORD
   LOCAL nRet AS LONG

   ' // Start by opening the printer
   pd.DesiredAccess = %PRINTER_ALL_ACCESS
   IF OpenPrinterW(BYCOPY bstrPrinterName, hPrinter, pd) = 0 THEN EXIT FUNCTION

   ' // The first GetPrinter tells you how big the buffer should be in
   ' // order to hold all of PRINTER_INFO_2. Note that this should fail with
   ' // ERROR_INSUFFICIENT_BUFFER.  If GetPrinter fails for any other reason
   ' // or dwNeeded isn't set for some reason, then there is a problem...
   nRet = GetPrinterW(hPrinter, 2, BYVAL %NULL, 0, dwNeeded)
   IF nRet = 0 AND GetLastError <> %ERROR_INSUFFICIENT_BUFFER THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF
   ' // Allocate enough space for PRINTER_INFO_2...
   bufferPrn = SPACE$(dwNeeded)
   ' // The second GetPrinter fills in all the current settings, so all you
   ' // need to do is modify what you're interested in...
   nRet = GetPrinterW(hPrinter, 2, BYVAL STRPTR(bufferPrn), dwNeeded, dwNeeded)
   IF nRet = 0 THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF

   ' // If GetPrinter didn't fill in the DEVMODE, try to get it by calling
   ' // DocumentProperties...
   pi2 = STRPTR(bufferPrn)
   IF @pi2.pDevMode = %NULL THEN
      ' // Allocate a buffer of the correct size
      dwNeeded = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL %NULL, BYVAL %NULL, 0)
      bufferDoc = SPACE$(dwNeeded)
      ' // Retrieve the printer configuration data
      nRet = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL STRPTR(bufferDoc), BYVAL %NULL, %DM_OUT_BUFFER)
      IF nRet <> %IDOK THEN
         ClosePrinter(hPrinter)
         EXIT FUNCTION
      END IF
      ' // Cast it to a DEVMODEW structure
      pDevMode = STRPTR(bufferDoc)
      @pi2.pDevMode = pDevMode
   END IF

   ' // Specify exactly what we are attempting to change...
   @pi2.@pDevMode.dmColor = nMode

   ' // Do not attempt to set security descriptor...
   @pi2.pSecurityDescriptor = %NULL

   ' // Make sure the driver-dependent part of devmode is updated...
   nRet = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, _
                              BYVAL @pi2.pDevMode, BYVAL @pi2.pDevMode, _
                              %DM_IN_BUFFER OR %DM_OUT_BUFFER)
   IF nRet <> %IDOK THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF

   ' // Update printer information...
   nRet = SetPrinterW(hPrinter, 2, BYVAL pi2, 0)
   IF nRet = 0 THEN
      ' // The driver doesn't support, or it is unable to make the change...
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF

   ' // Finished with the printer
   ClosePrinter(hPrinter)

   IF nRet <> %IDOK THEN EXIT FUNCTION
   FUNCTION  = %TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Selects the number of copies printed if the device supports multiple-page copies.
' ========================================================================================
FUNCTION AfxSetPrinterCopies (BYVAL bstrPrinterName AS WSTRING, BYVAL nCopies AS LONG) AS LONG

   LOCAL hPrinter AS DWORD
   LOCAL pDevMode AS DEVMODEW PTR
   LOCAL pi2 AS PRINTER_INFO_2W PTR
   LOCAL pd AS PRINTER_DEFAULTS
   LOCAL bufferPrn AS STRING
   LOCAL bufferDoc AS STRING
   LOCAL dwNeeded AS DWORD
   LOCAL nRet AS LONG

   ' // Start by opening the printer
   pd.DesiredAccess = %PRINTER_ALL_ACCESS
   IF OpenPrinterW(BYCOPY bstrPrinterName, hPrinter, pd) = 0 THEN EXIT FUNCTION

   ' // The first GetPrinter tells you how big the buffer should be in
   ' // order to hold all of PRINTER_INFO_2. Note that this should fail with
   ' // ERROR_INSUFFICIENT_BUFFER.  If GetPrinter fails for any other reason
   ' // or dwNeeded isn't set for some reason, then there is a problem...
   nRet = GetPrinterW(hPrinter, 2, BYVAL %NULL, 0, dwNeeded)
   IF nRet = 0 AND GetLastError <> %ERROR_INSUFFICIENT_BUFFER THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF
   ' // Allocate enough space for PRINTER_INFO_2...
   bufferPrn = SPACE$(dwNeeded)
   ' // The second GetPrinter fills in all the current settings, so all you
   ' // need to do is modify what you're interested in...
   nRet = GetPrinterW(hPrinter, 2, BYVAL STRPTR(bufferPrn), dwNeeded, dwNeeded)
   IF nRet = 0 THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF

   ' // If GetPrinter didn't fill in the DEVMODE, try to get it by calling
   ' // DocumentProperties...
   pi2 = STRPTR(bufferPrn)
   IF @pi2.pDevMode = %NULL THEN
      ' // Allocate a buffer of the correct size
      dwNeeded = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL %NULL, BYVAL %NULL, 0)
      bufferDoc = SPACE$(dwNeeded)
      ' // Retrieve the printer configuration data
      nRet = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL STRPTR(bufferDoc), BYVAL %NULL, %DM_OUT_BUFFER)
      IF nRet <> %IDOK THEN
         ClosePrinter(hPrinter)
         EXIT FUNCTION
      END IF
      ' // Cast it to a DEVMODEW structure
      pDevMode = STRPTR(bufferDoc)
      @pi2.pDevMode = pDevMode
   END IF

   ' // Specify exactly what we are attempting to change...
   @pi2.@pDevMode.dmCopies = nCopies

   ' // Do not attempt to set security descriptor...
   @pi2.pSecurityDescriptor = %NULL

   ' // Make sure the driver-dependent part of devmode is updated...
   nRet = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, _
                              BYVAL @pi2.pDevMode, BYVAL @pi2.pDevMode, _
                              %DM_IN_BUFFER OR %DM_OUT_BUFFER)
   IF nRet <> %IDOK THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF

   ' // Update printer information...
   nRet = SetPrinterW(hPrinter, 2, BYVAL pi2, 0)
   IF nRet = 0 THEN
      ' // The driver doesn't support, or it is unable to make the change...
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF

   ' // Finished with the printer
   ClosePrinter(hPrinter)

   IF nRet <> %IDOK THEN EXIT FUNCTION
   FUNCTION  = %TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the printer duplex mode
' DMDUP_SIMPLEX = Single sided printing
' DMDUP_VERTICAL = Page flipped on the vertical edge
' DMDUP_HORIZONTAL = Page flipped on the horizontal edge
' ========================================================================================
FUNCTION AfxSetPrinterDuplexMode (BYVAL bstrPrinterName AS WSTRING, BYVAL nDuplexMode AS LONG) AS LONG

   LOCAL hPrinter AS DWORD
   LOCAL pDevMode AS DEVMODEW PTR
   LOCAL pi2 AS PRINTER_INFO_2W PTR
   LOCAL pd AS PRINTER_DEFAULTS
   LOCAL bufferPrn AS STRING
   LOCAL bufferDoc AS STRING
   LOCAL dwNeeded AS DWORD
   LOCAL nRet AS LONG

   IF nDuplexMode <> %DMDUP_SIMPLEX AND nDuplexMode <> %DMDUP_VERTICAL AND nDuplexMode <> %DMDUP_HORIZONTAL  THEN EXIT FUNCTION

   ' // Start by opening the printer
   pd.DesiredAccess = %PRINTER_ALL_ACCESS
   IF OpenPrinterW(BYCOPY bstrPrinterName, hPrinter, pd) = 0 THEN EXIT FUNCTION

   ' // The first GetPrinter tells you how big the buffer should be in
   ' // order to hold all of PRINTER_INFO_2. Note that this should fail with
   ' // ERROR_INSUFFICIENT_BUFFER.  If GetPrinter fails for any other reason
   ' // or dwNeeded isn't set for some reason, then there is a problem...
   nRet = GetPrinterW(hPrinter, 2, BYVAL %NULL, 0, dwNeeded)
   IF nRet = 0 AND GetLastError <> %ERROR_INSUFFICIENT_BUFFER THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF
   ' // Allocate enough space for PRINTER_INFO_2...
   bufferPrn = SPACE$(dwNeeded)
   ' // The second GetPrinter fills in all the current settings, so all you
   ' // need to do is modify what you're interested in...
   nRet = GetPrinterW(hPrinter, 2, BYVAL STRPTR(bufferPrn), dwNeeded, dwNeeded)
   IF nRet = 0 THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF

   ' // If GetPrinter didn't fill in the DEVMODE, try to get it by calling
   ' // DocumentProperties...
   pi2 = STRPTR(bufferPrn)
   IF @pi2.pDevMode = %NULL THEN
      ' // Allocate a buffer of the correct size
      dwNeeded = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL %NULL, BYVAL %NULL, 0)
      bufferDoc = SPACE$(dwNeeded)
      ' // Retrieve the printer configuration data
      nRet = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL STRPTR(bufferDoc), BYVAL %NULL, %DM_OUT_BUFFER)
      IF nRet <> %IDOK THEN
         ClosePrinter(hPrinter)
         EXIT FUNCTION
      END IF
      ' // Cast it to a DEVMODEW structure
      pDevMode = STRPTR(bufferDoc)
      @pi2.pDevMode = pDevMode
   END IF

   ' // Driver is reporting that it doesn't support this change...
   IF (@pi2.@pDevMode.dmFields AND %DM_DUPLEX) = 0 THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF

   ' // Specify exactly what we are attempting to change...
   @pi2.@pDevMode.dmDuplex = nDuplexMode

   ' // Do not attempt to set security descriptor...
   @pi2.pSecurityDescriptor = %NULL

   ' // Make sure the driver-dependent part of devmode is updated...
   nRet = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, _
                              BYVAL @pi2.pDevMode, BYVAL @pi2.pDevMode, _
                              %DM_IN_BUFFER OR %DM_OUT_BUFFER)
   IF nRet <> %IDOK THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF

   ' // Update printer information...
   nRet = SetPrinterW(hPrinter, 2, BYVAL pi2, 0)
   IF nRet = 0 THEN
      ' // The driver doesn't support, or it is unable to make the change...
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF

   ' // Finished with the printer
   ClosePrinter(hPrinter)

   IF nRet <> %IDOK THEN EXIT FUNCTION
   FUNCTION  = %TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the printer orientation.
' DMORIENT_PORTRAIT = Portrait
' DMORIENT_LANDSCAPE = Landscape
' ========================================================================================
FUNCTION AfxSetPrinterOrientation (BYVAL bstrPrinterName AS WSTRING, BYVAL nOrientation AS LONG) AS LONG

   LOCAL hPrinter AS DWORD
   LOCAL pDevMode AS DEVMODEW PTR
   LOCAL pi2 AS PRINTER_INFO_2W PTR
   LOCAL pd AS PRINTER_DEFAULTS
   LOCAL bufferPrn AS STRING
   LOCAL bufferDoc AS STRING
   LOCAL dwNeeded AS DWORD
   LOCAL nRet AS LONG

   IF nOrientation <> %DMORIENT_PORTRAIT AND nOrientation <> %DMORIENT_LANDSCAPE THEN EXIT FUNCTION

   ' // Start by opening the printer
   pd.DesiredAccess = %PRINTER_ALL_ACCESS
   IF OpenPrinterW(BYCOPY bstrPrinterName, hPrinter, pd) = 0 THEN EXIT FUNCTION

   ' // The first GetPrinter tells you how big the buffer should be in
   ' // order to hold all of PRINTER_INFO_2. Note that this should fail with
   ' // ERROR_INSUFFICIENT_BUFFER.  If GetPrinter fails for any other reason
   ' // or dwNeeded isn't set for some reason, then there is a problem...
   nRet = GetPrinterW(hPrinter, 2, BYVAL %NULL, 0, dwNeeded)
   IF nRet = 0 AND GetLastError <> %ERROR_INSUFFICIENT_BUFFER THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF
   ' // Allocate enough space for PRINTER_INFO_2...
   bufferPrn = SPACE$(dwNeeded)
   ' // The second GetPrinter fills in all the current settings, so all you
   ' // need to do is modify what you're interested in...
   nRet = GetPrinterW(hPrinter, 2, BYVAL STRPTR(bufferPrn), dwNeeded, dwNeeded)
   IF nRet = 0 THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF

   ' // If GetPrinter didn't fill in the DEVMODE, try to get it by calling
   ' // DocumentProperties...
   pi2 = STRPTR(bufferPrn)
   IF @pi2.pDevMode = %NULL THEN
      ' // Allocate a buffer of the correct size
      dwNeeded = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL %NULL, BYVAL %NULL, 0)
      bufferDoc = SPACE$(dwNeeded)
      ' // Retrieve the printer configuration data
      nRet = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL STRPTR(bufferDoc), BYVAL %NULL, %DM_OUT_BUFFER)
      IF nRet <> %IDOK THEN
         ClosePrinter(hPrinter)
         EXIT FUNCTION
      END IF
      ' // Cast it to a DEVMODEW structure
      pDevMode = STRPTR(bufferDoc)
      @pi2.pDevMode = pDevMode
   END IF

   ' // Driver is reporting that it doesn't support this change...
   IF (@pi2.@pDevMode.dmFields AND %DM_ORIENTATION) = 0 THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF

   ' // Specify exactly what we are attempting to change...
   @pi2.@pDevMode.dmFields = %DM_ORIENTATION
   @pi2.@pDevMode.dmOrientation = nOrientation

   ' // Do not attempt to set security descriptor...
   @pi2.pSecurityDescriptor = %NULL

   ' // Make sure the driver-dependent part of devmode is updated...
   nRet = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, _
                              BYVAL @pi2.pDevMode, BYVAL @pi2.pDevMode, _
                              %DM_IN_BUFFER OR %DM_OUT_BUFFER)
   IF nRet <> %IDOK THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF

   ' // Update printer information...
   nRet = SetPrinterW(hPrinter, 2, BYVAL pi2, 0)
   IF nRet = 0 THEN
      ' // The driver doesn't support, or it is unable to make the change...
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF

   ' // Finished with the printer
   ClosePrinter(hPrinter)

   IF nRet <> %IDOK THEN EXIT FUNCTION
   FUNCTION  = %TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the printer paper size.
' ========================================================================================
FUNCTION AfxSetPrinterPaperSize (BYVAL bstrPrinterName AS WSTRING, BYVAL nSize AS LONG) AS LONG

   LOCAL hPrinter AS DWORD
   LOCAL pDevMode AS DEVMODEW PTR
   LOCAL pi2 AS PRINTER_INFO_2W PTR
   LOCAL pd AS PRINTER_DEFAULTS
   LOCAL bufferPrn AS STRING
   LOCAL bufferDoc AS STRING
   LOCAL dwNeeded AS DWORD
   LOCAL nRet AS LONG

   ' // Start by opening the printer
   pd.DesiredAccess = %PRINTER_ALL_ACCESS
   IF OpenPrinterW(BYCOPY bstrPrinterName, hPrinter, pd) = 0 THEN EXIT FUNCTION

   ' // The first GetPrinter tells you how big the buffer should be in
   ' // order to hold all of PRINTER_INFO_2. Note that this should fail with
   ' // ERROR_INSUFFICIENT_BUFFER.  If GetPrinter fails for any other reason
   ' // or dwNeeded isn't set for some reason, then there is a problem...
   nRet = GetPrinterW(hPrinter, 2, BYVAL %NULL, 0, dwNeeded)
   IF nRet = 0 AND GetLastError <> %ERROR_INSUFFICIENT_BUFFER THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF
   ' // Allocate enough space for PRINTER_INFO_2...
   bufferPrn = SPACE$(dwNeeded)
   ' // The second GetPrinter fills in all the current settings, so all you
   ' // need to do is modify what you're interested in...
   nRet = GetPrinterW(hPrinter, 2, BYVAL STRPTR(bufferPrn), dwNeeded, dwNeeded)
   IF nRet = 0 THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF

   ' // If GetPrinter didn't fill in the DEVMODE, try to get it by calling
   ' // DocumentProperties...
   pi2 = STRPTR(bufferPrn)
   IF @pi2.pDevMode = %NULL THEN
      ' // Allocate a buffer of the correct size
      dwNeeded = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL %NULL, BYVAL %NULL, 0)
      bufferDoc = SPACE$(dwNeeded)
      ' // Retrieve the printer configuration data
      nRet = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL STRPTR(bufferDoc), BYVAL %NULL, %DM_OUT_BUFFER)
      IF nRet <> %IDOK THEN
         ClosePrinter(hPrinter)
         EXIT FUNCTION
      END IF
      ' // Cast it to a DEVMODEW structure
      pDevMode = STRPTR(bufferDoc)
      @pi2.pDevMode = pDevMode
   END IF

   ' // Specify exactly what we are attempting to change...
   @pi2.@pDevMode.dmPaperSize = nSize

   ' // Do not attempt to set security descriptor...
   @pi2.pSecurityDescriptor = %NULL

   ' // Make sure the driver-dependent part of devmode is updated...
   nRet = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, _
                              BYVAL @pi2.pDevMode, BYVAL @pi2.pDevMode, _
                              %DM_IN_BUFFER OR %DM_OUT_BUFFER)
   IF nRet <> %IDOK THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF

   ' // Update printer information...
   nRet = SetPrinterW(hPrinter, 2, BYVAL pi2, 0)
   IF nRet = 0 THEN
      ' // The driver doesn't support, or it is unable to make the change...
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF

   ' // Finished with the printer
   ClosePrinter(hPrinter)

   IF nRet <> %IDOK THEN EXIT FUNCTION
   FUNCTION  = %TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Specifies the printer resolution.
' ========================================================================================
FUNCTION AfxSetPrinterQuality (BYVAL bstrPrinterName AS WSTRING, BYVAL nMode AS LONG) AS LONG

   LOCAL hPrinter AS DWORD
   LOCAL pDevMode AS DEVMODEW PTR
   LOCAL pi2 AS PRINTER_INFO_2W PTR
   LOCAL pd AS PRINTER_DEFAULTS
   LOCAL bufferPrn AS STRING
   LOCAL bufferDoc AS STRING
   LOCAL dwNeeded AS DWORD
   LOCAL nRet AS LONG

   ' // Start by opening the printer
   pd.DesiredAccess = %PRINTER_ALL_ACCESS
   IF OpenPrinterW(BYCOPY bstrPrinterName, hPrinter, pd) = 0 THEN EXIT FUNCTION

   ' // The first GetPrinter tells you how big the buffer should be in
   ' // order to hold all of PRINTER_INFO_2. Note that this should fail with
   ' // ERROR_INSUFFICIENT_BUFFER.  If GetPrinter fails for any other reason
   ' // or dwNeeded isn't set for some reason, then there is a problem...
   nRet = GetPrinterW(hPrinter, 2, BYVAL %NULL, 0, dwNeeded)
   IF nRet = 0 AND GetLastError <> %ERROR_INSUFFICIENT_BUFFER THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF
   ' // Allocate enough space for PRINTER_INFO_2...
   bufferPrn = SPACE$(dwNeeded)
   ' // The second GetPrinter fills in all the current settings, so all you
   ' // need to do is modify what you're interested in...
   nRet = GetPrinterW(hPrinter, 2, BYVAL STRPTR(bufferPrn), dwNeeded, dwNeeded)
   IF nRet = 0 THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF

   ' // If GetPrinter didn't fill in the DEVMODE, try to get it by calling
   ' // DocumentProperties...
   pi2 = STRPTR(bufferPrn)
   IF @pi2.pDevMode = %NULL THEN
      ' // Allocate a buffer of the correct size
      dwNeeded = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL %NULL, BYVAL %NULL, 0)
      bufferDoc = SPACE$(dwNeeded)
      ' // Retrieve the printer configuration data
      nRet = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL STRPTR(bufferDoc), BYVAL %NULL, %DM_OUT_BUFFER)
      IF nRet <> %IDOK THEN
         ClosePrinter(hPrinter)
         EXIT FUNCTION
      END IF
      ' // Cast it to a DEVMODEW structure
      pDevMode = STRPTR(bufferDoc)
      @pi2.pDevMode = pDevMode
   END IF

   ' // Specify exactly what we are attempting to change...
   @pi2.@pDevMode.dmPrintQuality = nMode

   ' // Do not attempt to set security descriptor...
   @pi2.pSecurityDescriptor = %NULL

   ' // Make sure the driver-dependent part of devmode is updated...
   nRet = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, _
                              BYVAL @pi2.pDevMode, BYVAL @pi2.pDevMode, _
                              %DM_IN_BUFFER OR %DM_OUT_BUFFER)
   IF nRet <> %IDOK THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF

   ' // Update printer information...
   nRet = SetPrinterW(hPrinter, 2, BYVAL pi2, 0)
   IF nRet = 0 THEN
      ' // The driver doesn't support, or it is unable to make the change...
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF

   ' // Finished with the printer
   ClosePrinter(hPrinter)

   IF nRet <> %IDOK THEN EXIT FUNCTION
   FUNCTION  = %TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the paper source. Can be one of the following values, or it can be a device-specific
' value greater than or equal to DMBIN_USER.
' DMBIN_UPPER         = 1
' DMBIN_LOWER         = 2
' DMBIN_MIDDLE        = 3
' DMBIN_MANUAL        = 4
' DMBIN_ENVELOPE      = 5
' DMBIN_ENVMANUAL     = 6
' DMBIN_AUTO          = 7
' DMBIN_TRACTOR       = 8
' DMBIN_SMALLFMT      = 9
' DMBIN_LARGEFMT      = 10
' DMBIN_LARGECAPACITY = 11
' DMBIN_CASSETTE      = 14
' DMBIN_FORMSOURCE    = 15
' ========================================================================================
FUNCTION AfxSetPrinterTray (BYVAL bstrPrinterName AS WSTRING, BYVAL nTray AS LONG) AS LONG

   LOCAL hPrinter AS DWORD
   LOCAL pDevMode AS DEVMODEW PTR
   LOCAL pi2 AS PRINTER_INFO_2W PTR
   LOCAL pd AS PRINTER_DEFAULTS
   LOCAL bufferPrn AS STRING
   LOCAL bufferDoc AS STRING
   LOCAL dwNeeded AS DWORD
   LOCAL nRet AS LONG

   ' // Start by opening the printer
   pd.DesiredAccess = %PRINTER_ALL_ACCESS
   IF OpenPrinterW(BYCOPY bstrPrinterName, hPrinter, pd) = 0 THEN EXIT FUNCTION

   ' // The first GetPrinter tells you how big the buffer should be in
   ' // order to hold all of PRINTER_INFO_2. Note that this should fail with
   ' // ERROR_INSUFFICIENT_BUFFER.  If GetPrinter fails for any other reason
   ' // or dwNeeded isn't set for some reason, then there is a problem...
   nRet = GetPrinterW(hPrinter, 2, BYVAL %NULL, 0, dwNeeded)
   IF nRet = 0 AND GetLastError <> %ERROR_INSUFFICIENT_BUFFER THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF
   ' // Allocate enough space for PRINTER_INFO_2...
   bufferPrn = SPACE$(dwNeeded)
   ' // The second GetPrinter fills in all the current settings, so all you
   ' // need to do is modify what you're interested in...
   nRet = GetPrinterW(hPrinter, 2, BYVAL STRPTR(bufferPrn), dwNeeded, dwNeeded)
   IF nRet = 0 THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF

   ' // If GetPrinter didn't fill in the DEVMODE, try to get it by calling
   ' // DocumentProperties...
   pi2 = STRPTR(bufferPrn)
   IF @pi2.pDevMode = %NULL THEN
      ' // Allocate a buffer of the correct size
      dwNeeded = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL %NULL, BYVAL %NULL, 0)
      bufferDoc = SPACE$(dwNeeded)
      ' // Retrieve the printer configuration data
      nRet = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, BYVAL STRPTR(bufferDoc), BYVAL %NULL, %DM_OUT_BUFFER)
      IF nRet <> %IDOK THEN
         ClosePrinter(hPrinter)
         EXIT FUNCTION
      END IF
      ' // Cast it to a DEVMODEW structure
      pDevMode = STRPTR(bufferDoc)
      @pi2.pDevMode = pDevMode
   END IF

   ' // Specify exactly what we are attempting to change...
   @pi2.@pDevMode.dmDefaultSource = nTray

   ' // Do not attempt to set security descriptor...
   @pi2.pSecurityDescriptor = %NULL

   ' // Make sure the driver-dependent part of devmode is updated...
   nRet = DocumentPropertiesW(%NULL, hPrinter, BYCOPY bstrPrinterName, _
                              BYVAL @pi2.pDevMode, BYVAL @pi2.pDevMode, _
                              %DM_IN_BUFFER OR %DM_OUT_BUFFER)
   IF nRet <> %IDOK THEN
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF

   ' // Update printer information...
   nRet = SetPrinterW(hPrinter, 2, BYVAL pi2, 0)
   IF nRet = 0 THEN
      ' // The driver doesn't support, or it is unable to make the change...
      ClosePrinter(hPrinter)
      EXIT FUNCTION
   END IF

   ' // Finished with the printer
   ClosePrinter(hPrinter)

   IF nRet <> %IDOK THEN EXIT FUNCTION
   FUNCTION  = %TRUE

END FUNCTION
' ========================================================================================
