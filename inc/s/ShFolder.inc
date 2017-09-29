' ########################################################################################
' Microsoft Windows
' File: ShFolder.inc
' Contents: Functions to get shell special folders
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

'// shfolder.dll supports these on all platforms including Win95, Win98, NT4 and IE4 shell

'// all CSIDL values referred to here are supported natively by shfolder.dll, that is they
'// will work on all platforms.

#INCLUDE THIS ONCE
%SHFOLDER_INC = 1

'// deprecate in Windows 2000 or later
'#if (NTDDI_VERSION >= NTDDI_WIN2K)
'#error shfolder.h/shfolder.lib provide platform independence with versions prior to Windows 2000. Use shlobj.h/shell32.lib if targetting Windows 2000 or higher.
'#endif

'#include <SpecStrings.h>

#IF NOT %DEF(%SHLOBJ_INC)

#IF NOT %DEF(%CSIDL_PERSONAL)
%CSIDL_PERSONAL                = &H0005& ' My Documents
#ENDIF

#IF NOT %DEF(%CSIDL_MYMUSIC)
%CSIDL_MYMUSIC                 = &H000d& ' "My Music" folder
#ENDIF

#IF NOT %DEF(%CSIDL_APPDATA)
%CSIDL_APPDATA                 = &H001A& ' <user name>\Application Data
#ENDIF

#IF NOT %DEF(%CSIDL_LOCAL_APPDATA)

%CSIDL_LOCAL_APPDATA           = &H001c& ' <user name>\Local Settings\Application Data (non roaming)
%CSIDL_INTERNET_CACHE          = &H0020&
%CSIDL_COOKIES                 = &H0021&
%CSIDL_HISTORY                 = &H0022&
%CSIDL_COMMON_APPDATA          = &H0023& ' All Users\Application Data
%CSIDL_WINDOWS                 = &H0024& ' GetWindowsDirectory()
%CSIDL_SYSTEM                  = &H0025& ' GetSystemDirectory()
%CSIDL_PROGRAM_FILES           = &H0026& ' C:\Program Files
%CSIDL_MYPICTURES              = &H0027& ' C:\Program Files\My Pictures
%CSIDL_PROGRAM_FILES_COMMON    = &H002b& ' C:\Program Files\Common
%CSIDL_COMMON_DOCUMENTS        = &H002e& ' All Users\Documents
%CSIDL_RESOURCES               = &H0038& ' Resource Direcotry
%CSIDL_RESOURCES_LOCALIZED     = &H0039& ' %windir%\Resources\<LangID>, for theme and other windows specific resources.

%CSIDL_FLAG_CREATE             = &H8000& ' // new for Win2K, or this in to force creation of folder

%CSIDL_COMMON_ADMINTOOLS       = &H002f& ' All Users\Start Menu\Programs\Administrative Tools
%CSIDL_ADMINTOOLS              = &H0030& ' <user name>\Start Menu\Programs\Administrative Tools

#ENDIF   ' // CSIDL_LOCAL_APPDATA


DECLARE FUNCTION SHGetFolderPathA IMPORT "SHELL32.DLL" ALIAS "SHGetFolderPathA" ( _
   BYVAL hwndOwner AS DWORD _                           ' __in HWND hwndOwner
 , BYVAL nFolder AS LONG _                              ' __in int nFolder
 , BYVAL hToken AS DWORD _                              ' __in HANDLE hToken
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pszPath AS ASCIIZ _                            ' __out LPSTR pszPath
 ) AS LONG                                              ' HRESULT

' // Deprecated. As of Windows Vista, this function is merely a wrapper for SHGetKnownFolderPath.
DECLARE FUNCTION SHGetFolderPathW IMPORT "SHELL32.DLL" ALIAS "SHGetFolderPathW" ( _
   BYVAL hwndOwner AS DWORD _                           ' __in HWND hwndOwner
 , BYVAL nFolder AS LONG _                              ' __in int nFolder
 , BYVAL hToken AS DWORD _                              ' __in HANDLE hToken
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pszPath AS WSTRINGZ _                          ' __out LPWSTR pszPath
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO SHGetFolderPath = SHGetFolderPathW
#ELSE
   MACRO SHGetFolderPath = SHGetFolderPathA
#ENDIF

'// protos so callers can GetProcAddress() from shfolder.dll

'typedef HRESULT (__stdcall * PFNSHGETFOLDERPATHA)(HWND, int, HANDLE, DWORD, LPSTR);  // "SHGetFolderPathA"
'typedef HRESULT (__stdcall * PFNSHGETFOLDERPATHW)(HWND, int, HANDLE, DWORD, LPWSTR); // "SHGetFolderPathW"

#ENDIF   ' #IF NOT %DEF(%SHLOBJ_INC)
