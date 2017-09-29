' ########################################################################################
' Microsoft Windows
' File: iepmapi.inc
' Contents: Defines the IE Protected Mode APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IEPMAPI_INC = 1

#INCLUDE ONCE "windows.inc"

'// Remap old API names to new ones.
'#define IEGetWriteableHKCU      IEGetWriteableLowHKCU


'// IE Launch Option Flags

' enum IELAUNCHOPTION_FLAGS
%IELAUNCHOPTION_SCRIPTDEBUG = &H00000001???

'//+-------------------------------------------------------------------------
'//
'// Structure:   IELAUNCHURLINFO
'//
'// Members:
'//              cbSize - Size of the structure, in bytes.
'//              dwCreationFlags - Process Creation flags used by CreateProcess
'//                                and CreateProcessAsUser functions.
'//
'//--------------------------------------------------------------------------

' // Size = 12 bytes
TYPE IELAUNCHURLINFO
   cbSize              AS DWORD   ' DWORD
   dwCreationFlags     AS DWORD   ' DWORD
   dwLaunchOptionFlags AS DWORD   ' DWORD
END TYPE

'//+-------------------------------------------------------------------------
'//
'//  Method:     IESaveFile
'//
'//  Synopsis:   Saves the file to the location selected by the user in a
'//              previous call to IEShowSaveFileDialog
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION IESaveFile IMPORT "ieframe.dll" ALIAS "IESaveFile" ( _
   BYVAL hState AS DWORD _                              ' __in HANDLE  hState
 , BYREF lpwstrSourceFile AS WSTRINGZ _                 ' __in LPCWSTR lpwstrSourceFile
 ) AS LONG                                              ' HRESULT


'//+-------------------------------------------------------------------------
'//
'//  Method:     IECancelSaveFile
'//
'//  Synopsis:   Cancels the save operation and releases the resources
'//              allocated for the previous call to IEShowSaveFileDialog
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION IECancelSaveFile IMPORT "ieframe.dll" ALIAS "IECancelSaveFile" ( _
   BYVAL hState AS DWORD _                              ' __in HANDLE hState
 ) AS LONG                                              ' HRESULT


'//+-------------------------------------------------------------------------
'//
'//  Method:     IEShowSaveFileDialog
'//
'//  Synopsis:   Shows the standard SaveFile dialog from a higher integrity
'//              user context
'//
'//  Remarks:    When no longer needed, call CoTaskMemFree to release
'//              lppwstrDestinationFilePath
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION IEShowSaveFileDialog IMPORT "ieframe.dll" ALIAS "IEShowSaveFileDialog" ( _
   BYVAL hwnd AS DWORD _                                ' __in        HWND     hwnd
 , BYREF lpwstrInitialFileName AS WSTRINGZ _            ' __in        LPCWSTR  lpwstrInitialFileName
 , BYREF lpwstrInitialDir AS WSTRINGZ _                 ' __in_opt    LPCWSTR  lpwstrInitialDir
 , BYREF lpwstrFilter AS WSTRINGZ _                     ' __in_opt    LPCWSTR  lpwstrFilter
 , BYREF lpwstrDefExt AS WSTRINGZ _                     ' __in_opt    LPCWSTR  lpwstrDefExt
 , BYVAL dwFilterIndex AS DWORD _                       ' __in        DWORD    dwFilterIndex
 , BYVAL dwFlags AS DWORD _                             ' __in        DWORD    dwFlags
 , BYREF lppwstrDestinationFilePath AS WSTRINGZ _       ' __deref_out LPWSTR   *lppwstrDestinationFilePath
 , BYREF phState AS DWORD _                             ' __out       HANDLE   *phState
 ) AS LONG                                              ' HRESULT


'//+-------------------------------------------------------------------------
'//
'//  Method:     IEGetWriteableLowHKCU
'//
'//  Synopsis:   Returns a handle to a write accessible location under
'//              HKEY_CURRENT_USER for MIC Low process
'//
'//  Remarks:    When no longer needed, call RegCloseKey function to close
'//              the HKEY
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION IEGetWriteableLowHKCU IMPORT "ieframe.dll" ALIAS "IEGetWriteableLowHKCU" ( _
   BYREF pHKey AS DWORD _                               ' __out HKEY    *pHKey
 ) AS LONG                                              ' HRESULT

'//+-------------------------------------------------------------------------
'//
'//  Method:     IEGetWriteableFolderPath
'//
'//  Synopsis:   Returns the current location of the specified folder.
'//              In protected mode, the path points to a location where
'//              the user has write permissions
'//
'//  Remarks:    When no longer needed, call CoTaskMemFree to release the
'//              lppwstrPath
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION IEGetWriteableFolderPath IMPORT "ieframe.dll" ALIAS "IEGetWriteableFolderPath" ( _
   BYREF clsidFolderID AS GUID _                        ' __in        REFGUID clsidFolderID
 , BYREF lppwstrPath AS WSTRINGZ _                      ' __deref_out LPWSTR   *lppwstrPath
 ) AS LONG                                              ' HRESULT

'//+-------------------------------------------------------------------------
'//
'//  Method:     IEIsProtectedModeProcess
'//
'//  Synopsis:   Determines if Internet Explorer is running in protected mode
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION IEIsProtectedModeProcess IMPORT "ieframe.dll" ALIAS "IEIsProtectedModeProcess" ( _
   BYREF pbResult AS LONG _                             ' __out BOOL     *pbResult
 ) AS LONG                                              ' HRESULT

'//+-------------------------------------------------------------------------
'//
'//  Method:     IEIsProtectedModeURL
'//
'//  Synopsis:   Determines if the URL runs in Protected Mode or not
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION IEIsProtectedModeURL IMPORT "ieframe.dll" ALIAS "IEIsProtectedModeURL" ( _
   BYREF lpwstrUrl AS WSTRINGZ _                        ' __in LPCWSTR lpwstrUrl
 ) AS LONG                                              ' HRESULT

'//+-------------------------------------------------------------------------
'//
'//  Method:     IELaunchURL
'//
'//  Synopsis:   Launches the appropriate IE to handle the navigation to
'//              the URL
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION IELaunchURL IMPORT "ieframe.dll" ALIAS "IELaunchURL" ( _
   BYREF lpwstrUrl AS WSTRINGZ _                        ' __in        LPCWSTR lpwstrUrl
 , BYREF lpProcInfo AS PROCESS_INFORMATION _            ' __inout     PROCESS_INFORMATION *lpProcInfo
 , BYREF lpInfo AS ANY _                                ' __in_opt    VOID *lpInfo
 ) AS LONG                                              ' HRESULT

'//+-------------------------------------------------------------------------
'//
'//  Method:     IERefreshElevationPolicy
'//
'//  Synopsis:   Causes the next elevation policy look up to refresh from
'//              the registry
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION IERefreshElevationPolicy IMPORT "ieframe.dll" ALIAS "IERefreshElevationPolicy" ( _
 ) AS LONG                                              ' HRESULT

'//+-------------------------------------------------------------------------
'//
'//  Method:     IEGetProtectedModeCookie
'//
'//  Synopsis:   Retrieves the cookie data from the Protected Mode Cookie store
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION IEGetProtectedModeCookie IMPORT "ieframe.dll" ALIAS "IEGetProtectedModeCookie" ( _
   BYREF lpszURL AS WSTRINGZ _                          ' __in LPCWSTR lpszURL
 , BYREF lpszCookieName AS WSTRINGZ _                   ' __in LPCWSTR lpszCookieName
 , BYREF lpszCookieData AS WSTRINGZ _                   ' __inout LPWSTR lpszCookieData
 , BYREF pcchCookieData AS DWORD _                      ' __inout DWORD *pcchCookieData
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

'//+-------------------------------------------------------------------------
'//
'//  Method:     IESetProtectedModeCookie
'//
'//  Synopsis:   Set the cookie data in the Protected Mode Cookie store
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION IESetProtectedModeCookie IMPORT "ieframe.dll" ALIAS "IESetProtectedModeCookie" ( _
   BYREF lpszURL AS WSTRINGZ _                          ' __in LPCWSTR lpszURL
 , BYREF lpszCookieName AS WSTRINGZ _                   ' __in LPCWSTR lpszCookieName
 , BYREF lpszCookieData AS WSTRINGZ _                   ' __in LPCWSTR lpszCookieData
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

'//+-------------------------------------------------------------------------
'//
'//  Method:     IERegisterWritableRegistryKey
'//
'//  Synopsis:   Register a subkey path during installation so that
'//              low process can write into this location during run time.
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION IERegisterWritableRegistryKey IMPORT "ieframe.dll" ALIAS "IERegisterWritableRegistryKey" ( _
   BYVAL guid AS GUID _                                 ' __in GUID guid
 , BYREF lpSubkey AS WSTRINGZ _                         ' __in LPCWSTR lpSubkey
 , BYVAL fSubkeyAllowed AS LONG _                       ' __in BOOL fSubkeyAllowed
 ) AS LONG                                              ' HRESULT

'//+-------------------------------------------------------------------------
'//
'//  Method:     IERegisterWritableRegistryValue
'//
'//  Synopsis:   Register a value in a subkey path during installation so that
'//              low process can write into this location during run time.
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION IERegisterWritableRegistryValue IMPORT "ieframe.dll" ALIAS "IERegisterWritableRegistryValue" ( _
   BYVAL guid AS GUID _                                 ' __in GUID guid
 , BYREF lpPath AS WSTRINGZ _                           ' __in LPCWSTR lpPath
 , BYREF lpValueName AS WSTRINGZ _                      ' __in LPCWSTR lpValueName
 , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
 , BYVAL lpData AS BYTE PTR _                           ' __in_opt const BYTE* lpData
 , BYVAL cbMaxData AS DWORD _                           ' __in DWORD cbMaxData
 ) AS LONG                                              ' HRESULT

'//+-------------------------------------------------------------------------
'//
'//  Method:     IEUnregisterWritableRegistryKey
'//
'//  Synopsis:   Unregister a registry path during uninstallation so that
'//              low process can not write into this location
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION IEUnregisterWritableRegistry IMPORT "ieframe.dll" ALIAS "IEUnregisterWritableRegistry" ( _
   BYVAL guid AS GUID _                                 ' __in GUID guid
 ) AS LONG                                              ' HRESULT

'//+-------------------------------------------------------------------------
'//
'//  Method:     IERegCreateKeyEx
'//
'//  Synopsis:   Call Broker to do RegCreateKeyEx on pre-registered locations
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION IERegCreateKeyEx IMPORT "ieframe.dll" ALIAS "IERegCreateKeyEx" ( _
   BYREF lpSubKey AS WSTRINGZ _                         ' __in      LPCWSTR lpSubKey
 , BYVAL Reserved AS DWORD _                            ' __in      DWORD Reserved
 , BYREF lpClass AS WSTRINGZ _                          ' __in_opt  LPWSTR lpClass
 , BYVAL dwOptions AS DWORD _                           ' __in      DWORD dwOptions
 , BYVAL samDesired AS DWORD _                          ' __in      REGSAM samDesired
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in_opt  LPSECURITY_ATTRIBUTES lpSecurityAttributes
 , BYREF phkResult AS DWORD _                           ' __out     PHKEY phkResult
 , BYREF lpdwDisposition AS DWORD _                     ' __out     LPDWORD lpdwDisposition
 ) AS LONG                                              ' HRESULT

'//+-------------------------------------------------------------------------
'//
'//  Method:     IERegSetValueEx
'//
'//  Synopsis:   Call Broker to do RegSetValueEx on pre-registered location
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION IERegSetValueEx IMPORT "ieframe.dll" ALIAS "IERegSetValueEx" ( _
   BYVAL lpSubKey AS DWORD _                            ' __in LPCWSTR lpSubKey
 , BYREF lpValueName AS WSTRINGZ _                      ' __in LPCWSTR lpValueName
 , BYVAL Reserved AS DWORD _                            ' __in DWORD Reserved
 , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
 , BYVAL lpData AS BYTE PTR _                           ' __in const BYTE* lpData
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 ) AS LONG                                              ' HRESULT

'//+-------------------------------------------------------------------------
'//
'//  Method:     IECreateFile
'//
'//  Synopsis:   wrapper to CreateFile
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION IECreateFile IMPORT "ieframe.dll" ALIAS "IECreateFile" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL dwShareMode AS DWORD _                         ' __in DWORD dwShareMode
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in LPSECURITY_ATTRIBUTES lpSecurityAttributes
 , BYVAL dwCreationDisposition AS DWORD _               ' __in DWORD dwCreationDisposition
 , BYVAL dwFlagsAndAttributes AS DWORD _                ' __in DWORD dwFlagsAndAttributes
 , BYVAL hTemplateFile AS DWORD _                       ' __in_opt HANDLE hTemplateFile
 ) AS DWORD                                             ' HANDLE

'//+-------------------------------------------------------------------------
'//
'//  Method:     IEDeleteFile
'//
'//  Synopsis:   wrapper to DeleteFile
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION IEDeleteFile IMPORT "ieframe.dll" ALIAS "IEDeleteFile" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//
'//  Method:     IERemoveDirectory
'//
'//  Synopsis:   wrapper to RemoveDirectory
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION IERemoveDirectory IMPORT "ieframe.dll" ALIAS "IERemoveDirectory" ( _
   BYREF lpPathName AS WSTRINGZ _                       ' __in LPCWSTR lpPathName
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//
'//  Method:     IEMoveFileEx
'//
'//  Synopsis:   wrapper to MoveFileEx
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION IEMoveFileEx IMPORT "ieframe.dll" ALIAS "IEMoveFileEx" ( _
   BYREF lpExistingFileName AS WSTRINGZ _               ' __in LPCWSTR lpExistingFileName
 , BYREF lpNewFileName AS WSTRINGZ _                    ' __in LPCWSTR lpNewFileName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//
'//  Method:     IECreateDirectory
'//
'//  Synopsis:   wrapper to CreateDirectory
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION IECreateDirectory IMPORT "ieframe.dll" ALIAS "IECreateDirectory" ( _
   BYREF lpPathName AS WSTRINGZ _                       ' __in LPCWSTR lpPathName
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in LPSECURITY_ATTRIBUTES lpSecurityAttributes
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//
'//  Method:     IEGetFileAttributesEx
'//
'//  Synopsis:   wrapper to GetFileAttributesEx
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION IEGetFileAttributesEx IMPORT "ieframe.dll" ALIAS "IEGetFileAttributesEx" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 , BYVAL fInfoLevelId AS LONG _                         ' __in GET_FILEEX_INFO_LEVELS fInfoLevelId
 , BYREF lpFileInformation AS ANY _                     ' __in LPVOID lpFileInformation
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//
'//  Method:     IEFindFirstFile
'//
'//  Synopsis:   wrapper to FindFirstFile
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION IEFindFirstFile IMPORT "ieframe.dll" ALIAS "IEFindFirstFile" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 , BYREF lpFindFileData AS WIN32_FIND_DATAW _           ' __in LPWIN32_FIND_DATA lpFindFileData
 ) AS DWORD                                             ' HANDLE
