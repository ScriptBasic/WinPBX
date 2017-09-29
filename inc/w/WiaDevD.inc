' ########################################################################################
' Microsoft Windows
' File: WiaDevD.inc
' Contents: Device Dialog and UI extensibility declarations
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WIADEVD_INC = 1

#INCLUDE ONCE "wia.inc"

'#include <pshpack8.h>


'#if (_WIN32_WINNT >= 0x0600) // Windows Vista and later
#IF %WINVER >= &H0600

' // Size = 36 bytes
TYPE DEVICEDIALOGDATA2 DWORD
   cbSize         AS DWORD       ' DWORD // Size of the structure in bytes
   pIWiaItemRoot  AS DWORD PTR   ' IWiaItem2 * // Valid root item
   dwFlags        AS DWORD       ' DWORD // Flags
   hwndParent     AS DWORD       ' HWND // Parent window
   bstrFolderName AS DWORD       ' BSTR // Folder name where the files are transferred
   bstrFilename   AS DWORD       ' BSTR // template file name.
   lNumFiles      AS LONG        ' LONG // Number of items in ppbstrFilePaths array.  Filled on return.
   pbstrFilePaths AS DWORD       ' BSTR * // file names created after successful transfers.
   pWiaItem       AS DWORD PTR   ' IWiaItem2 * // IWiaItem2 interface pointer.  This is the IWiaItem2 used for transfer.
END TYPE


' ########################################################################################
' Interface name = IWiaUIExtension2
' IID = {305600D7-5088-46D7-9A15-B77B09CDBA7A}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IWiaUIExtension2 = GUID$("{305600D7-5088-46D7-9A15-B77B09CDBA7A}")

INTERFACE IWiaUIExtension2 $IID_IWiaUIExtension2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DeviceDialog ( _                              ' VTable offset = 12
     BYREF pDeviceDialogData AS DEVICEDIALOGDATA2 _     ' __in PDEVICEDIALOGDATA2 pDeviceDialogData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceIcon ( _                             ' VTable offset = 16
     BYVAL bstrDeviceId AS WSTRING _                    ' __in BSTR bstrDeviceId
   , BYREF phIcon AS DWORD _                            ' __out HICON *phIcon
   , BYVAL nSize AS DWORD _                             ' __in ULONG nSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF ' //#if (_WIN32_WINNT >= 0x0600)


' // Size = 28 bytes
TYPE DEVICEDIALOGDATA DWORD
   cbSize        AS DWORD       ' DWORD      // Size of the structure in bytes
   hwndParent    AS DWORD       ' HWND       // Parent window
   pIWiaItemRoot AS DWORD PTR   ' IWiaItem * // Valid root item
   dwFlags       AS DWORD       ' DWORD      // Flags
   lIntent       AS LONG        ' LONG       // Intent flags
   lItemCount    AS LONG        ' LONG       // Number of items in ppWiaItems array.  Filled on return.
   ppWiaItems    AS DWORD       ' IWiaItem   // Array of IWiaItem interface pointers.  Array must
                                '            // be allocated using LocalAlloc, all interface pointers must be AddRef'ed
END TYPE

'HRESULT WINAPI DeviceDialog( PDEVICEDIALOGDATA pDeviceDialogData );

'// IWiaUIExtension provides a means to replace a device's image acquisition dialog
'// and to provide custom icons and logo bitmaps to appear on the standard dialog

' ########################################################################################
' Interface name = IWiaUIExtension
' IID = {D52920AA-DB88-41F0-946C-E00DC0A19CFA}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IWiaUIExtension = GUID$("{DA319113-50EE-4C80-B460-57D005D44A2C}")

INTERFACE IWiaUIExtension $IID_IWiaUIExtension

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DeviceDialog ( _                              ' VTable offset = 12
     BYREF pDeviceDialogData AS DEVICEDIALOGDATA _      ' __in PDEVICEDIALOGDATA pDeviceDialogData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceIcon ( _                             ' VTable offset = 16
     BYVAL bstrDeviceId AS WSTRING _                    ' __in BSTR bstrDeviceId
   , BYREF phIcon AS DWORD _                            ' __out HICON *phIcon
   , BYVAL nSize AS DWORD _                             ' __in ULONG nSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceBitmapLogo ( _                       ' VTable offset = 20
     BYVAL bstrDeviceId AS WSTRING _                    ' __in BSTR bstrDeviceId
   , BYREF phBitmap AS DWORD _                          ' __out HBITMAP *phBitmap
   , BYVAL nMaxWidth AS DWORD _                         ' __in ULONG nMaxWidth
   , BYVAL nMaxHeight AS DWORD _                        ' __in ULONG nMaxHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

'typedef HRESULT (WINAPI *DeviceDialogFunction)(PDEVICEDIALOGDATA);

'#define SHELLEX_WIAUIEXTENSION_NAME TEXT("WiaDialogExtensionHandlers")
$$SHELLEX_WIAUIEXTENSION_NAME = "WiaDialogExtensionHandlers"$$

'// Define clipboard format names for retrieving data from an IDataObject
'#define CFSTR_WIAITEMNAMES TEXT("WIAItemNames")
'#define CFSTR_WIAITEMPTR   TEXT("WIAItemPointer")

$$CFSTR_WIAITEMNAMES = "WIAItemNames"$$
$$CFSTR_WIAITEMPTR   = "WIAItemPointer"$$

'#include <poppack.h>

