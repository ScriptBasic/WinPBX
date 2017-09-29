' ########################################################################################
' Microsoft Windows
' File: AfxGfx.inc
' Contents: Graphic wrapper functions.
' Copyright (c) 2011 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AFXGFX_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "objbase.inc"

' ========================================================================================
' Loads a DIB in memory and returns a pointer to it.
' - bstrFileName
'     Path of the bitmap file.
' Reutn Value:
'   A pointer to the bitmap file header.
'   Release it with CoTaskMemFree when no longer needed.
' ========================================================================================
FUNCTION AfxDibLoadImage (BYVAL bstrFileName AS WSTRING) AS DWORD

   LOCAL bSuccess AS LONG
   LOCAL dwFileSize AS DWORD
   LOCAL dwHighSize AS DWORD
   LOCAL dwBytesRead AS DWORD
   LOCAL hFile AS DWORD
   LOCAL pbmfh AS BITMAPFILEHEADER PTR

   hFile = CreateFileW(BYCOPY bstrFileName, %GENERIC_READ, %FILE_SHARE_READ, _
           BYVAL %NULL, %OPEN_EXISTING, %FILE_FLAG_SEQUENTIAL_SCAN, %NULL)
   IF BITSE(hFile, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION

   dwFileSize = GetFileSize(hFile, dwHighSize)
   IF dwHighSize THEN
      CloseHandle hFile
      EXIT FUNCTION
   END IF

   ' // Read the contents of the file. Notice that pmfh has been cast as
   ' // BITMAPFILEHEADER PTR to be able to read the header.
   pbmfh = CoTaskMemAlloc(dwFileSize)
   bSuccess = ReadFile(hFile, BYVAL pbmfh, dwFileSize, dwBytesRead, BYVAL %NULL)
   ' // Check for "BM" (&H4D42, i.e. &H42 = "B", &H4D = "M", they are in reverse order)
   IF ISFALSE bSuccess OR dwBytesRead <> dwFileSize OR @pbmfh.bfType <> &H4D42 THEN
      CoTaskMemFree BYVAL pbmfh
      CloseHandle hFile
      EXIT FUNCTION
   END IF

   ' // Close the file handle and return a pointer to the data read
   CloseHandle hFile
   FUNCTION = pbmfh

END FUNCTION
' ========================================================================================

' ========================================================================================
' Saves a DIB to a file.
' - bstrFileName
'     Path of the file.
' - pbmfh
'     Pointer to the bitmap file header.
' Return Value
'   TRUE if the DIB has been saved successfully; FALSE otherwise.
' ========================================================================================
FUNCTION AfxDibSaveImage (BYVAL bstrFileName AS WSTRING, BYVAL pbmfh AS BITMAPFILEHEADER PTR) AS LONG

   LOCAL bSuccess AS LONG
   LOCAL dwBytesWritten AS DWORD
   LOCAL hFile  AS DWORD

   IF pbmfh = %NULL THEN EXIT FUNCTION

   hFile = CreateFileW(BYCOPY bstrFileName, %GENERIC_WRITE, 0, BYVAL %NULL, _
                      %CREATE_ALWAYS, %FILE_ATTRIBUTE_NORMAL, %NULL)

   IF BITSE(hFile, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION

   bSuccess = WriteFile(hFile, BYVAL pbmfh, BYVAL @pbmfh.bfSize, dwBytesWritten, BYVAL %NULL)
   CloseHandle hFile

   IF ISFALSE bSuccess OR dwBytesWritten <> @pbmfh.bfSize THEN
      DeleteFile BYCOPY bstrFileName
      EXIT FUNCTION
   END IF

   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================
