' ########################################################################################
' Microsoft Windows
' File: AfxDlg.inc
' Contents: Include file for the dialogs library.
' Copyright (c) 2011 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AFXDLG_INC = 1

#INCLUDE ONCE "commdlg.inc"
#INCLUDE ONCE "AfxWin.inc"

' ========================================================================================
' Open File Dialog
' It allows both the use of "|" as a separator (for compatibility with legacy code) and
' of nulls, used by PB's DISPLAY OPEN FILE statement.
' bstrFilter = "BASIC|*.BAS;*.INC;*.BI|"
' bstrFilter = CHR$("BASIC", 0, "*.BAS;*.INC;*.BI", 0)
' The minimum buffer is %MAX_PATH and the maximum buffer is unlimited.
' Can not be used with Windows versions below Windows 2000.
' ========================================================================================
FUNCTION AfxOpenFileDialogA ( _
   BYVAL hwndOwner AS DWORD _                    ' // Parent window
 , BYVAL strTitle AS STRING _                    ' // Caption
 , BYREF strFile AS STRING _                     ' // Filename
 , BYVAL strInitialDir AS STRING _               ' // Start directory
 , BYVAL strFilter AS STRING _                   ' // Filename filter
 , BYVAL strDefExt AS STRING _                   ' // Default extension
 , BYREF dwFlags AS DWORD _                      ' // Flags
 , OPTIONAL BYVAL dwBufLen AS DWORD _            ' // Buffer length
 ) AS LONG

   LOCAL ix AS LONG
   LOCAL ofn AS OPENFILENAMEA

   ' // Filter is a sequence of ASCIIZ strings with a final (extra) $NUL terminator
   REPLACE "|" WITH $NUL IN strFilter
   strFilter += $NUL

   ' // If the initial directory has not been specified, assume the current directory
   IF LEN(strInitialDir) = 0 THEN strInitialDir = CURDIR$

   ' // The filename must be null terminated
   ix = INSTR(strFile, $NUL)
   IF ix THEN strFile = LEFT$(strFile, ix) ELSE strFile = strFile & $NUL

   ' // The size of the buffer must be at least %MAX_PATH bytes
   IF dwBufLen = 0 THEN dwBufLen = 32768   ' // 32 Kb buffer (enough for at least 126 files)
   IF dwBufLen < 260 THEN dwBufLen = 260
   IF LEN(strFile) < dwBufLen THEN strFile += SPACE$(dwBufLen - LEN(strFile))

   ' // Fill the members of the structure
   IF AfxGetWindowsVersion < 5 THEN
      ofn.lStructSize   = 76
   ELSE
      ofn.lStructSize   = SIZEOF(ofn)
   END IF
   ofn.hwndOwner        = hwndOwner
   ofn.lpstrFilter      = STRPTR(strFilter)
   ofn.nFilterIndex     = 1
   ofn.lpstrFile        = STRPTR(strFile)
   ofn.nMaxFile         = LEN(strFile)
   ofn.lpstrInitialDir  = STRPTR(strInitialDir)
   IF LEN(strTitle) THEN
      ofn.lpstrTitle    = STRPTR(strTitle)
   END IF
   ofn.Flags            = dwFlags
   IF LEN(strDefExt) THEN
      ofn.lpstrDefExt   = STRPTR(strDefExt)
   END IF

   FUNCTION = GetOpenFilenameA(ofn)

   ix = INSTR(strFile, $NUL & $NUL)
   IF ix THEN
      strFile = LEFT$(strFile, ix - 1)
   ELSE
      ix = INSTR(strFile, $NUL)
      IF ix THEN
         strFile = LEFT$(strFile, ix - 1)
      ELSE
         strFile = ""
      END IF
   END IF

   dwFlags = ofn.Flags

END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxOpenFileDialogW ( _
   BYVAL hwndOwner AS DWORD _                    ' // Parent window
 , BYVAL bstrTitle AS WSTRING _                  ' // Caption
 , BYREF bstrFile AS WSTRING _                   ' // Filename
 , BYVAL bstrInitialDir AS WSTRING _             ' // Start directory
 , BYVAL bstrFilter AS WSTRING _                 ' // Filename filter
 , BYVAL bstrDefExt AS WSTRING _                 ' // Default extension
 , BYREF dwFlags AS DWORD _                      ' // Flags
 , OPTIONAL BYVAL dwBufLen AS DWORD _            ' // Buffer length
 ) AS LONG

   LOCAL ix AS LONG
   LOCAL ofn AS OPENFILENAMEW

   ' // Filter is a sequence of ASCIIZ strings with a final (extra) $NUL terminator
   REPLACE "|" WITH $NUL IN bstrFilter
   bstrFilter += $$NUL

   ' // If the initial directory has not been specified, assume the current directory
   IF LEN(bstrInitialDir) = 0 THEN bstrInitialDir = CURDIR$

   ' // The filename must be null terminated
   ix = INSTR(bstrFile, $NUL)
   IF ix THEN bstrFile = LEFT$(bstrFile, ix) ELSE bstrFile = bstrFile & $NUL

   ' // The size of the buffer must be at least %MAX_PATH bytes
   IF dwBufLen = 0 THEN dwBufLen = 32768   ' // 32 Kb buffer (enough for at least 126 files)
   IF dwBufLen < 260 THEN dwBufLen = 260
   IF LEN(bstrFile) < dwBufLen THEN bstrFile += SPACE$(dwBufLen - LEN(bstrFile))

   ' // Fill the members of the structure
   IF AfxGetWindowsVersion < 5 THEN
      ofn.lStructSize   = 76
   ELSE
      ofn.lStructSize   = SIZEOF(ofn)
   END IF
   ofn.hwndOwner        = hwndOwner
   ofn.lpstrFilter      = STRPTR(bstrFilter)
   ofn.nFilterIndex     = 1
   ofn.lpstrFile        = STRPTR(bstrFile)
   ofn.nMaxFile         = LEN(bstrFile)
   ofn.lpstrInitialDir  = STRPTR(bstrInitialDir)
   IF LEN(bstrTitle) THEN
      ofn.lpstrTitle    = STRPTR(bstrTitle)
   END IF
   ofn.Flags            = dwFlags
   IF LEN(bstrDefExt) THEN
      ofn.lpstrDefExt   = STRPTR(bstrDefExt)
   END IF

   FUNCTION = GetOpenFilenameW(ofn)
   ix = INSTR(bstrFile, $NUL & $NUL)
   IF ix THEN
      bstrFile = LEFT$(bstrFile, ix - 1)
   ELSE
      ix = INSTR(bstrFile, $NUL)
      IF ix THEN
         bstrFile = LEFT$(bstrFile, ix - 1)
      ELSE
         bstrFile = ""
      END IF
   END IF

   dwFlags = ofn.Flags

END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxOpenFileDialog = AfxOpenFileDialogW
   MACRO OpenFileDialog = AfxOpenFileDialogW
#ELSE
   MACRO AfxOpenFileDialog = AfxOpenFileDialogA
   MACRO OpenFileDialog = AfxOpenFileDialogA
#ENDIF

' ========================================================================================
' Save File Dialog
' ========================================================================================
FUNCTION AfxSaveFileDialogA ( _
   BYVAL hwndOwner AS DWORD _                    ' // Parent window
 , BYVAL strTitle AS STRING _                    ' // Caption
 , BYREF strFile AS STRING _                     ' // Filename
 , BYVAL strInitialDir AS STRING _               ' // Start directory
 , BYVAL strFilter AS STRING _                   ' // Filename filter
 , BYVAL strDefExt AS STRING _                   ' // Default extension
 , BYREF dwFlags AS DWORD _                      ' // Flags
 ) AS LONG

   LOCAL ix AS LONG
   LOCAL ofn AS OPENFILENAMEA

   ' // Filter is a sequence of ASCIIZ strings with a final (extra) $NUL terminator
   REPLACE "|" WITH $NUL IN strFilter
   strFilter += $NUL

   ' // If the initial directory has not been specified, assume the current directory
   IF LEN(strInitialDir) = 0 THEN strInitialDir = CURDIR$

   IF LEN(strFile) > %MAX_PATH THEN
      strFile = LEFT$(strFile, %MAX_PATH)
   END IF
   ix = INSTR(strFile, $NUL)
   IF ix THEN
      strFile = LEFT$(strFile, ix) & SPACE$(%MAX_PATH - ix)
   ELSE
      strFile = strFile & $NUL & SPACE$(%MAX_PATH - LEN(strFile))
   END IF

   IF AfxGetWindowsVersion < 5 THEN
      ofn.lStructSize   = 76
   ELSE
      ofn.lStructSize   = SIZEOF(ofn)
   END IF
   ofn.hwndOwner       = hwndOwner
   ofn.lpstrFilter     = STRPTR(strFilter)
   ofn.nFilterIndex    = 1
   ofn.lpstrFile       = STRPTR(strFile)
   ofn.nMaxFile        = LEN(strFile)
   ofn.lpstrInitialDir = STRPTR(strInitialDir)
   IF LEN(strTitle) THEN
      ofn.lpstrTitle   = STRPTR(strTitle)
   END IF
   ofn.Flags           = dwFlags
   IF LEN(strDefExt) THEN
      ofn.lpstrDefExt  = STRPTR(strDefExt)
   END IF

   FUNCTION = GetSaveFilenameA(ofn)

   ix = INSTR(strFile, $NUL)
   IF ix THEN
      strFile = LEFT$(strFile, ix - 1)
   ELSE
      strFile = ""
   END IF

   dwFlags = ofn.Flags

END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxSaveFileDialogW ( _
   BYVAL hwndOwner AS DWORD _                    ' // Parent window
 , BYVAL bstrTitle AS WSTRING _                  ' // Caption
 , BYREF bstrFile AS WSTRING _                   ' // Filename
 , BYVAL bstrInitialDir AS WSTRING _             ' // Start directory
 , BYVAL bstrFilter AS WSTRING _                 ' // Filename filter
 , BYVAL bstrDefExt AS WSTRING _                 ' // Default extension
 , BYREF dwFlags AS DWORD _                      ' // Flags
 ) AS LONG

   LOCAL ix AS LONG
   LOCAL ofn AS OPENFILENAMEW

   ' // Filter is a sequence of ASCIIZ strings with a final (extra) $NUL terminator
   REPLACE "|" WITH $NUL IN bstrFilter
   bstrFilter += $$NUL

   ' // If the initial directory has not been specified, assume the current directory
   IF LEN(bstrInitialDir) = 0 THEN bstrInitialDir = CURDIR$

   IF LEN(bstrFile) > %MAX_PATH THEN
      bstrFile = LEFT$(bstrFile, %MAX_PATH)
   END IF
   ix = INSTR(bstrFile, $NUL)
   IF ix THEN
      bstrFile = LEFT$(bstrFile, ix) & SPACE$(%MAX_PATH - ix)
   ELSE
      bstrFile = bstrFile & $NUL & SPACE$(%MAX_PATH - LEN(bstrFile))
   END IF

   IF AfxGetWindowsVersion < 5 THEN
      ofn.lStructSize   = 76
   ELSE
      ofn.lStructSize   = SIZEOF(ofn)
   END IF
   ofn.hwndOwner       = hwndOwner
   ofn.lpstrFilter     = STRPTR(bstrFilter)
   ofn.nFilterIndex    = 1
   ofn.lpstrFile       = STRPTR(bstrFile)
   ofn.nMaxFile        = LEN(bstrFile)
   ofn.lpstrInitialDir = STRPTR(bstrInitialDir)
   IF LEN(bstrTitle) THEN
      ofn.lpstrTitle   = STRPTR(bstrTitle)
   END IF
   ofn.Flags           = dwFlags
   IF LEN(bstrDefExt) THEN
      ofn.lpstrDefExt  = STRPTR(bstrDefExt)
   END IF

   FUNCTION = GetSaveFilenameW(ofn)

   ix = INSTR(bstrFile, $NUL)
   IF ix THEN
      bstrFile = LEFT$(bstrFile, ix - 1)
   ELSE
      bstrFile = ""
   END IF

   dwFlags = ofn.Flags

END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxSaveFileDialog = AfxSaveFileDialogW
   MACRO SaveFileDialog = AfxSaveFileDialogW
#ELSE
   MACRO AfxSaveFileDialog = AfxSaveFileDialogA
   MACRO SaveFileDialog = AfxSaveFileDialogA
#ENDIF

' ========================================================================================
' Printer dialog
' ========================================================================================
FUNCTION AfxPrinterDialog ( _
   BYVAL hwndOwner AS DWORD _                    ' // Parent window
 , BYREF flags AS DWORD _                        ' // Dialog flags
 , BYREF hDC AS DWORD _                          ' // device context of the printer
 , BYREF nCopies AS WORD _                       ' // Number of copies
 , BYREF nFromPage AS WORD _                     ' // From page number
 , BYREF nToPage AS WORD _                       ' // To page number
 , BYVAL nMinPage AS WORD _                      ' // Minimum page number
 , BYVAL nMaxPage AS WORD _                      ' // Maximum page number
 ) AS LONG

   LOCAL pd AS PRINTDLGAPIW

   pd.lStructSize = SIZEOF(pd)
   pd.hwndOwner   = hwndOwner
   pd.flags       = flags OR %PD_SHOWHELP
   pd.nCopies     = nCopies
   pd.nFromPage   = MAX(nFromPage, nMinPage)
   pd.nToPage     = MAX(MIN(nToPage, nMaxPage), nMaxPage)
   pd.nMinPage    = nMinPage
   pd.nMaxPage    = nMaxPage

   IF PrintDlgW(pd) THEN
      hDC            = pd.hDC
      nCopies        = pd.nCopies
      nFromPage      = pd.nFromPage
      nToPage        = pd.nToPage
      flags          = pd.flags
      IF pd.hDevMode THEN GlobalFree(pd.hDevMode)
      IF pd.hDevNames THEN GlobalFree(pd.hDevNames)
      FUNCTION = %TRUE
   END IF

END FUNCTION
' ========================================================================================

' // To support the old name
MACRO PrinterDialog = AfxPrinterDialog

' ========================================================================================
' Printer setup dialog
' ========================================================================================
FUNCTION AfxPrinterSetup (BYVAL hwndOwner AS DWORD) AS LONG

   LOCAL pd AS PRINTDLGAPIW

   pd.lStructSize = SIZEOF(pd)
   pd.hwndOwner   = hwndOwner
   pd.Flags       = %PD_SHOWHELP OR %PD_PRINTSETUP

   IF PrintDlgW(pd) THEN
      IF pd.hDevMode THEN GlobalFree(pd.hDevMode)
      IF pd.hDevNames THEN GlobalFree(pd.hDevNames)
      FUNCTION = %TRUE
   END IF

END FUNCTION
' ========================================================================================

' // To support the old name
MACRO PrinterSetup = AfxPrinterSetup

' ========================================================================================
' Helper procedure to activate the run file dialog.
' * hwndOwner identifies the window that owns the dialog box.
' * hIcon is the handle of the icon that will be displayed in the dialog. If it is NULL,
'   the default icon will be used.
' * lpstrDirectory points to a string that specifies the working directory.
' * lpstrTitle points to a string to be placed in the title bar of the dialog box. If it
'   is NULL, the default title is used.
' * lpstrDescription points to a string that is displayed in the dialog, briefly informing
'   the user what to do. If it is NULL, the default description is used.
' * uFlags is a set of bit flags that specify other properties of the dialog.
'     - RFF_NOBROWSE       &H01    Removes the browse button.
'     - RFF_NODEFAULT      &H02    No default item selected.
'     - RFF_CALCDIRECTORY  &H04    Calculates the working directory from the file name.
'     - RFF_NOLABEL        &H08    Removes the edit box label.
'     - RFF_NOSEPARATEMEM  &H20    Removes the Separate Memory Space check box (Windows NT only).
' A nice feature of this dialog is that it allows you to control which applications the
' user may run. When the user selects the OK button, your parent window is sent a
' notification with details of the program that is about to be started. The notification is
' in the form of a WM_NOTIFY message with the notification code set to RFN_VALIDATE (-510)
' and the lParam pointing to an NM_RUNFILEDLG structure.
' Note: The three string parameters, lpstrDirectory, lpstrTitle and lpstrDescription must
' be ansi in Win95/98 and unicode in NT Platforms.
' ========================================================================================
SUB AfxRunFileDialog ( _
   BYVAL hwndOwner AS DWORD _                    ' HWND hwndOwner
 , BYVAL hIcon AS DWORD _                        ' HICON hIcon
 , BYREF lpstrDirectory AS WSTRINGZ _            ' LPWSTR lpstrDirectory
 , BYREF lpstrTitle AS WSTRINGZ _                ' LPWSTR lpstrTitle
 , BYREF lpstrDescription AS WSTRINGZ _          ' LPWSTR lpstrDescription
 , BYVAL uFlags AS DWORD _                       ' UINT uFlags
   )                                             ' void

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pRunDlg AS DWORD

   ' // Load the shell library
   hLib = LoadLibrary("SHELL32.DLL")
   IF hLib = %NULL THEN EXIT SUB

   ' // Get the address of the RunFileDlg (ordinal 61)
   pRunDlg = GetProcAddress(hLib, BYVAL MAK(LONG, 61, 0))
   IF ISTRUE pRunDlg THEN
      ' // Call the Run File dialog
      CALL DWORD pRunDlg USING AfxRunFileDialog(hwndOwner, hIcon, lpstrDirectory, lpstrTitle, lpstrDescription, uFlags)
   END IF

   ' // Free the library
   FreeLibrary hLib

END SUB
' ========================================================================================

' ========================================================================================
' Show MSInfo32 - First look in Registry for path, then SHELL..
' ========================================================================================
FUNCTION AfxShowSysInfo (BYVAL hwnd AS DWORD, OPTIONAL BYVAL bDisplayError AS LONG) AS LONG

   LOCAL PID      AS DWORD
   LOCAL hKey     AS DWORD
   LOCAL wszBuff  AS WSTRINGZ * 1024
   LOCAL bstrPath AS WSTRING

   IF RegOpenKeyExW(%HKEY_LOCAL_MACHINE, "SOFTWARE\Microsoft\Shared Tools\MSInfo", 0, _
                    %KEY_QUERY_VALUE, hKey) = %ERROR_SUCCESS THEN
      IF hKey THEN
         RegQueryValueExW hKey, "Path", 0, 0, wszBuff, SIZEOF(wszBuff)
         RegCloseKey hKey
         bstrPath = EXTRACT$(wszBuff, CHR$(0))
      END IF
   END IF

   IF LEN(bstrPath) THEN
      PID = SHELL(bstrPath)
      IF PID = 0 THEN
         FUNCTION = ERR
         IF bDisplayError THEN MessageBox hwnd, "Error " & FORMAT$(ERR), "Error", %MB_ICONERROR
      END IF
   ELSE
      FUNCTION = 53   ' // File not found
      IF bDisplayError THEN MessageBox hwnd, "Can't find MSInfo32.exe", "Error", %MB_ICONERROR
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Displays the printer dialog and prints the specified bitmap stretched to the paper size.
' Note: It is advisable to use GdiPlusPrintImageDlg, that allows to print all kind of
' images supported by GDI+.
' Parameters:
' wszFileName = The name of the bitmap file to print.
' nStetchMode = The stretching mode:
' - BLACKONWHITE: Performs a Boolean AND operation using the color values for the eliminated
' and existing pixels. If the bitmap is a monochrome bitmap, this mode preserves black pixels
' at the expense of white pixels.
' - COLORONCOLOR: Deletes the pixels. This mode deletes all eliminated lines of pixels
' without trying to preserve their information.
' - HALFTONE: Maps pixels from the source rectangle into blocks of pixels in the destination
' rectangle. The average color over the destination block of pixels approximates the color
' of the source pixels.
' - WHITEONBLACK: Performs a boolean OR operation using the color values for the eliminated
' and existing pixels. If the bitmap is a monochrome bitmap, this mode preserves white
' pixels at the expense of black pixels.
' Return Value: Returns %TRUE if the bitmap has been printed successfully, or %FALSE otherwise.
' ========================================================================================
FUNCTION AfxPrintBitmapDlg (BYREF wszFileName AS WSTRINGZ, OPTIONAL BYVAL nStretchMode AS LONG) AS LONG

   ' // Display te print dialog
   LOCAL hr AS LONG
   LOCAL ppd AS PRINTDLGAPIW
   ppd.lStructSize = SIZEOF(PRINTDLGAPIW)
   ppd.flags = %PD_RETURNDC OR %PD_ALLPAGES OR %PD_NOPAGENUMS OR %PD_NOSELECTION
   hr = PrintDlgW(ppd)
   IF hr <> %PD_RESULT_PRINT THEN EXIT FUNCTION

   ' // Load the bitmap
   LOCAL hBitmap AS DWORD
   hBitmap = LoadImageW(%NULL, wszFileName, %IMAGE_BITMAP, 0, 0, %LR_LOADFROMFILE OR %LR_CREATEDIBSECTION OR %LR_DEFAULTSIZE)
   IF hBitmap = 0 THEN GOTO LExit
   ' // Get the dimensions of the bitmap
   LOCAL bm AS BITMAP
   IF GetObjectW(hBitmap, SIZEOF(bm), bm) = 0 THEN GOTO LExit

   ' // Create a compatible DC
   LOCAL hMemDc AS DWORD
   hMemDc = CreateCompatibleDC(ppd.hDc)
   IF hMemDc = 0 THEN GOTO LExit

   ' // Select the bitmap in the compatible memory DC
   LOCAL hOldBitmap AS DWORD
   hOldBitmap = SelectObject(hMemDc, hBitmap)
   ' //Set the map mode of the memory DC
   SetMapMode(hMemDc, GetMapMode(ppd.hDc))
   ' // Set the stretching mode of the printer DC
   IF nStretchMode = 0 THEN nStretchMode = %HALFTONE
   SetStretchBltMode(ppd.hDc, nStretchMode)
   IF nStretchMode = %HALFTONE THEN SetBrushOrgEx(ppd.hDc, 0, 0, BYVAL %NULL)

   ' // Print the bitmap
   LOCAL di AS DOCINFOW
   di.cbSize = SIZEOF(DOCINFOW)
   di.lpszDocName = VARPTR(wszFileName)
   hr = StartDocW(ppd.hDc, di)
   IF hr <= 0 THEN GOTO LExit
   LOCAL i AS LONG
   FOR i = 1 TO ppd.nCopies
      IF StartPage(ppd.hDc) THEN
         StretchBlt(ppd.hDc, 0, 0, GetDeviceCaps(ppd.hDc, %HORZRES), GetDeviceCaps(ppd.hDc, %VERTRES), _
            hMemDc, 0, 0, bm.bmWidth, bm.bmHeight, %SRCCOPY)
         IF EndPage(ppd.hDc) > 0 THEN
            EndDoc(ppd.hDc)
            FUNCTION = %TRUE
         ELSE
            AbortDoc(ppd.hDc)
         END IF
      END IF
   NEXT

LExit:

   ' // Cleanup
   IF ppd.hDc THEN DeleteDC ppd.hDc
   IF ISTRUE hOldBitmap AND ISTRUE hMemDc THEN SelectObject(hMemDc, hOldBitmap)
   IF hMemDc THEN DeleteDC hMemDc

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the handle of the printer device context.
' ========================================================================================
FUNCTION AfxGetPrinterDC () AS DWORD
   LOCAL pdlg AS tagPRINTDLGEXW
   pdlg.lStructSize = SIZEOF(tagPRINTDLGEXW)
   pdlg.Flags = %PD_RETURNDEFAULT OR %PD_RETURNDC
   PrintDlgExW(pdlg)
   FUNCTION = pdlg.hDC
END FUNCTION
' ========================================================================================

' ========================================================================================
' Captures the entire contents of a window (including the nonclient area) and prints it to
' the default printer. To do this, the code creates an intermediate surface, copies the
' contents of the specified window to the intermediate surface, and then stretches the
' intermediate surface to fill the entire display area in the printer DC.
' Only the form that currently has focus can be printed by using this method.
' ========================================================================================
FUNCTION AfxPrintWindow (BYVAL hwnd AS DWORD) AS LONG

   LOCAL hbm AS DWORD
   LOCAL hdcPrinter AS DWORD
   LOCAL hdcMemory AS DWORD
   LOCAL hdcWindow AS DWORD
   LOCAL nWidth AS LONG
   LOCAL nHeight AS LONG
   LOCAL di AS DOCINFOW
   LOCAL rc AS RECT
   LOCAL ds AS DIBSECTION
   LOCAL hPal AS DWORD

   ' // Do you have a valid window?
   IF IsWindow(hwnd) = 0 THEN EXIT FUNCTION

   ' // Get a HDC for the default printer.
   hdcPrinter = AfxGetPrinterDC
   IF hdcPrinter = 0 THEN EXIT FUNCTION

   ' // Get the HDC for the entire window.
   hdcWindow = GetWindowDC(hwnd)

   ' // Get the rectangle bounding the window.
   GetWindowRect(hwnd, rc)

   ' // Adjust coordinates to client area.
   OffsetRect(rc, -rc.left, -rc.top)

   ' // Get the resolution of the printer device.
   nWidth  = GetDeviceCaps(hdcPrinter, %HORZRES)
   nHeight = GetDeviceCaps(hdcPrinter, %VERTRES)

   ' // Create the intermediate drawing surface at window resolution.
   hbm = AfxCreateDIBSection(hdcWindow, rc.right, rc.bottom, GetDeviceCaps(hdcWindow, %BITSPIXEL))
   IF hbm = 0 THEN
      DeleteDC(hdcPrinter)
      ReleaseDC(hwnd, hdcWindow)
      EXIT FUNCTION
   END IF

   ' // Prepare the surface for drawing.
   hdcMemory = CreateCompatibleDC(hdcWindow)
   SelectObject(hdcMemory, hbm)

   ' // Copy the window contents to the memory surface.
   BitBlt(hdcMemory, 0, 0, rc.right, rc.bottom, hdcWindow, 0, 0, %SRCCOPY)

   ' // Prepare the DOCINFO.
   LOCAL wszDocName AS WSTRINGZ * 260
   wszDocName = "Window Contents"
   di.cbSize = SIZEOF(di)
   di.lpszDocName = VARPTR(wszDocName)

   ' // Initialize the print job.
   IF StartDocW(hdcPrinter, di) > 0 THEN
      ' // Prepare to send a page.
      IF StartPage(hdcPrinter) > 0 THEN
         ' // Retrieve the information describing the surface.
         GetObjectW(hbm, SIZEOF(DIBSECTION), ds)
         ' // Print the contents of the surface.
         StretchDIBits(hdcPrinter, 0, 0, nWidth, nHeight, 0, 0, rc.right, rc.bottom, _
            BYVAL ds.dsBm.bmBits, BYVAL VARPTR(ds.dsBmih), %DIB_RGB_COLORS, %SRCCOPY)
         ' // Let the driver know the page is done.
         EndPage(hdcPrinter)
      END IF
      ' // Let the driver know the document is done.
      EndDoc(hdcPrinter)
   END IF

   ' // Clean up the objects you created.
   DeleteDC(hdcPrinter)
   DeleteDC(hdcMemory)
   ReleaseDC(hwnd, hdcWindow)
   DeleteObject(hbm)

   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================
