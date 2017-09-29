' ########################################################################################
' Microsoft Windows
' File: WIMGAPI.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WIMGAPI_INC = 1

#INCLUDE ONCE "windows.inc"

'//
'// Defined Value(s):
'//

'// WIMCreateFile:
'//
%WIM_GENERIC_READ            = %GENERIC_READ
%WIM_GENERIC_WRITE           = %GENERIC_WRITE

%WIM_CREATE_NEW              = %CREATE_NEW
%WIM_CREATE_ALWAYS           = %CREATE_ALWAYS
%WIM_OPEN_EXISTING           = %OPEN_EXISTING
%WIM_OPEN_ALWAYS             = %OPEN_ALWAYS

' enum
%WIM_COMPRESS_NONE = 0
%WIM_COMPRESS_XPRESS = 1
%WIM_COMPRESS_LZX = 2

' enum
%WIM_CREATED_NEW = 0
%WIM_OPENED_EXISTING = 1

'// WIMCreateFile, WIMCaptureImage, WIMApplyImage flags:
'//
%WIM_FLAG_RESERVED           = &H00000001???
%WIM_FLAG_VERIFY             = &H00000002???
%WIM_FLAG_INDEX              = &H00000004???
%WIM_FLAG_NO_APPLY           = &H00000008???
%WIM_FLAG_NO_DIRACL          = &H00000010???
%WIM_FLAG_NO_FILEACL         = &H00000020???
%WIM_FLAG_SHARE_WRITE        = &H00000040???
%WIM_FLAG_FILEINFO           = &H00000080???
%WIM_FLAG_NO_RP_FIX          = &H00000100???   ' // do not fix up reparse point tag
                                               ' // only used in WIMCaptureImage

'// WIMSetReferenceFile
'//
%WIM_REFERENCE_APPEND        = &H00010000???
%WIM_REFERENCE_REPLACE       = &H00020000???

'// WIMExportImage
'//
%WIM_EXPORT_ALLOW_DUPLICATES = &H00000001???
%WIM_EXPORT_ONLY_RESOURCES   = &H00000002???
%WIM_EXPORT_ONLY_METADATA    = &H00000004???

'// WIMRegisterMessageCallback:
'//
%INVALID_CALLBACK_VALUE      = &HFFFFFFFF???

'// WIMCopyFile
'//
%WIM_COPY_FILE_RETRY         = &H01000000???

'// WIMMessageCallback Notifications:
'//
' enum
%WIM_MSG             = %WM_APP            + &H1476
%WIM_MSG_TEXT        = %WIM_MSG           + 1
%WIM_MSG_PROGRESS    = %WIM_MSG_TEXT      + 1
%WIM_MSG_PROCESS     = %WIM_MSG_PROGRESS  + 1
%WIM_MSG_SCANNING    = %WIM_MSG_PROCESS   + 1
%WIM_MSG_SETRANGE    = %WIM_MSG_SCANNING  + 1
%WIM_MSG_SETPOS      = %WIM_MSG_SETRANGE  + 1
%WIM_MSG_STEPIT      = %WIM_MSG_SETPOS    + 1
%WIM_MSG_COMPRESS    = %WIM_MSG_STEPIT    + 1
%WIM_MSG_ERROR       = %WIM_MSG_COMPRESS  + 1
%WIM_MSG_ALIGNMENT   = %WIM_MSG_ERROR     + 1
%WIM_MSG_RETRY       = %WIM_MSG_ALIGNMENT + 1
%WIM_MSG_SPLIT       = %WIM_MSG_RETRY     + 1
%WIM_MSG_FILEINFO    = %WIM_MSG_SPLIT     + 1
%WIM_MSG_INFO        = %WIM_MSG_FILEINFO  + 1
%WIM_MSG_WARNING     = %WIM_MSG_INFO      + 1
%WIM_MSG_CHK_PROCESS = %WIM_MSG_WARNING   + 1

'//
'// WIMMessageCallback Return codes:
'//
%WIM_MSG_SUCCESS     = %ERROR_SUCCESS
%WIM_MSG_DONE        = &HFFFFFFF0???
%WIM_MSG_SKIP_ERROR  = &HFFFFFFFE???
%WIM_MSG_ABORT_IMAGE = &HFFFFFFFF???

'//
'// WIM_INFO dwFlags values:
'//
%WIM_ATTRIBUTE_NORMAL        = &H00000000???
%WIM_ATTRIBUTE_RESOURCE_ONLY = &H00000001???
%WIM_ATTRIBUTE_METADATA_ONLY = &H00000002???
%WIM_ATTRIBUTE_VERIFY_DATA   = &H00000004???
%WIM_ATTRIBUTE_RP_FIX        = &H00000008???
%WIM_ATTRIBUTE_SPANNED       = &H00000010???
%WIM_ATTRIBUTE_READONLY      = &H00000020???

'//
'// The WIM_INFO structure used by WIMGetAttributes:
'//
' // Size = 564 bytes
TYPE WIM_INFO DWORD
   WimPath         AS WSTRINGZ * %MAX_PATH   ' WCHAR[MAX_PATH]
   Guid            AS GUID                   ' GUID
   ImageCount      AS DWORD                  ' DWORD
   CompressionType AS DWORD                  ' DWORD
   PartNumber      AS WORD                   ' USHORT
   TotalParts      AS WORD                   ' USHORT
   BootIndex       AS DWORD                  ' DWORD
   WimAttributes   AS DWORD                  ' DWORD
   WimFlagsAndAttr AS DWORD                  ' DWORD
END TYPE

'//
'// The WIM_MOUNT_LIST structure used for getting the list of mounted images.
'//
' // Size = 1048 bytes
TYPE WIM_MOUNT_LIST DWORD
   WimPath      AS WSTRINGZ * %MAX_PATH   ' WCHAR[MAX_PATH]
   MountPath    AS WSTRINGZ * %MAX_PATH   ' WCHAR[MAX_PATH]
   ImageIndex   AS DWORD                  ' DWORD
   MountedForRW AS LONG                   ' BOOL
END TYPE

'//
'// Exported Function Prototypes:
'//

DECLARE FUNCTION WIMCreateFile IMPORT "wimgapi.dll" ALIAS "WIMCreateFile" ( _
   BYREF lpszWimPath AS WSTRINGZ _                      ' __in LPWSTR  lpszWimPath
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD   dwDesiredAccess
 , BYVAL dwCreationDisposition AS DWORD _               ' __in DWORD   dwCreationDisposition
 , BYVAL dwFlagsAndAttributes AS DWORD _                ' __in DWORD   dwFlagsAndAttributes
 , BYVAL dwCompressionType AS DWORD _                   ' __in DWORD   dwCompressionType
 , OPTIONAL BYREF lpdwCreationResult AS DWORD _         ' __out_opt LPDWORD lpdwCreationResult
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION WIMCloseHandle IMPORT "wimgapi.dll" ALIAS "WIMCloseHandle" ( _
   BYVAL hObject AS DWORD _                             ' __in HANDLE hObject
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WIMSetTemporaryPath IMPORT "wimgapi.dll" ALIAS "WIMSetTemporaryPath" ( _
   BYVAL hWim AS DWORD _                                ' __in HANDLE hWim
 , BYREF lpszPath AS WSTRINGZ _                         ' __in LPWSTR lpszPath
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WIMSetReferenceFile IMPORT "wimgapi.dll" ALIAS "WIMSetReferenceFile" ( _
   BYVAL hWim AS DWORD _                                ' __in HANDLE hWim
 , BYREF lpszPath AS WSTRINGZ _                         ' __in LPWSTR lpszPath
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD  dwFlags
 ) AS LONG                                              ' BOOL


DECLARE FUNCTION WIMSplitFile IMPORT "wimgapi.dll" ALIAS "WIMSplitFile" ( _
   BYVAL hWim AS DWORD _                                ' __in HANDLE hWim
 , BYREF lpszPartPath AS WSTRINGZ _                     ' __in LPWSTR lpszPartPath
 , BYREF pliPartSize AS ANY _                           ' __inout PLARGE_INTEGER pliPartSize
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD  dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WIMExportImage IMPORT "wimgapi.dll" ALIAS "WIMExportImage" ( _
   BYVAL hImage AS DWORD _                              ' __in HANDLE hImage
 , BYVAL hWin AS DWORD _                                ' __in HANDLE hWim
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD  dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WIMDeleteImage IMPORT "wimgapi.dll" ALIAS "WIMDeleteImage" ( _
   BYVAL hWim AS DWORD _                                ' __in HANDLE hWim
 , BYVAL dwImageIndex AS DWORD _                        ' __in DWORD  dwImageIndex
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WIMGetImageCount IMPORT "wimgapi.dll" ALIAS "WIMGetImageCount" ( _
   BYVAL hWim AS DWORD _                                ' __in HANDLE hWim
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION WIMGetAttributes IMPORT "wimgapi.dll" ALIAS "WIMGetAttributes" ( _
   BYVAL hWim AS DWORD _                                ' __in HANDLE hWim
 , BYREF lpWimInfo AS WIM_INFO _                        ' __out LPWIM_INFO lpWimInfo
 , BYVAL cbWimInfo AS DWORD _                           ' __in DWORD cbWimInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WIMSetBootImage IMPORT "wimgapi.dll" ALIAS "WIMSetBootImage" ( _
   BYVAL hWim AS DWORD _                                ' __in HANDLE hWim
 , BYVAL dwImageIndex AS DWORD _                        ' __in DWORD dwImageIndex
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WIMCaptureImage IMPORT "wimgapi.dll" ALIAS "WIMCaptureImage" ( _
   BYVAL hWim AS DWORD _                                ' __in HANDLE hWim
 , BYREF lpszPath AS WSTRINGZ _                         ' __in LPWSTR lpszPath
 , BYVAL dwCaptureFlags AS DWORD _                      ' __in DWORD dwCaptureFlags
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION WIMLoadImage IMPORT "wimgapi.dll" ALIAS "WIMLoadImage" ( _
   BYVAL hWim AS DWORD _                                ' __in HANDLE hWim
 , BYVAL dwImageIndex AS DWORD _                        ' __in DWORD dwImageIndex
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION WIMApplyImage IMPORT "wimgapi.dll" ALIAS "WIMApplyImage" ( _
   BYVAL hImage AS DWORD _                              ' __in HANDLE hImage
 , BYREF lpszPath AS WSTRINGZ _                         ' __in LPWSTR lpszPath
 , BYVAL dwApplyFlags AS DWORD _                        ' __in DWORD dwApplyFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WIMGetImageInformation IMPORT "wimgapi.dll" ALIAS "WIMGetImageInformation" ( _
   BYVAL hImage AS DWORD _                              ' __in HANDLE hImage
 , BYREF lplpvImageInfo AS DWORD _                      ' __out LPVOID *lplpvImageInfo
 , BYREF lpcbImageInfo AS DWORD _                       ' __out LPDWORD lpcbImageInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WIMSetImageInformation IMPORT "wimgapi.dll" ALIAS "WIMSetImageInformation" ( _
   BYVAL hImage AS DWORD _                              ' __in HANDLE hImage
 , BYVAL lplpvImageInfo AS DWORD _                      ' __in LPVOID lplpvImageInfo
 , BYVAL lpcbImageInfo AS DWORD _                       ' __in PDWORD cbImageInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WIMGetMessageCallbackCount IMPORT "wimgapi.dll" ALIAS "WIMGetMessageCallbackCount" ( _
   OPTIONAL BYVAL hWim AS DWORD _                       ' __in_opt HANDLE hWim
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION WIMRegisterMessageCallback IMPORT "wimgapi.dll" ALIAS "WIMRegisterMessageCallback" ( _
   BYVAL hWim AS DWORD _                                ' __in_opt HANDLE hWim
 , BYVAL fpMessageProc AS DWORD _                       ' __in     FARPROC fpMessageProc
 , OPTIONAL BYVAL lpvUserData AS DWORD _                ' __in_opt LPVOID  lpvUserData
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION WIMUnregisterMessageCallback IMPORT "wimgapi.dll" ALIAS "WIMUnregisterMessageCallback" ( _
   BYVAL hImage AS DWORD _                              ' __in HANDLE hWim
 , OPTIONAL BYVAL fpMessageProc AS DWORD _              ' __in_opt FARPROC fpMessageProc
 ) AS LONG                                              ' BOOL

' An application-defined function used with the WIMRegisterMessageCallback or WIMUnregisterMessageCallback functions.
'FUNCTION WIMMessageCallback ( _
'   BYVAL dwMessageId AS DWORD _                         ' __in DWORD  dwMessageId
' , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
' , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
' , BYVAL lpvUserData AS DWORD _                         ' __in LPVOID lpvUserData
' ) AS DWORD                                             ' DWORD

DECLARE FUNCTION WIMCopyFile IMPORT "wimgapi.dll" ALIAS "WIMCopyFile" ( _
   BYREF lpszExistingFileName AS WSTRINGZ _             ' __in     LPWSTR             lpszExistingFileName
 , BYREF lpszNewFileName AS WSTRINGZ _                  ' __in     LPWSTR             lpszNewFileName
 , BYVAL lpProgressRoutine AS DWORD _                   ' __in_opt LPPROGRESS_ROUTINE lpProgressRoutine
 , BYVAL lpvData AS DWORD _                             ' __in_opt LPVOID             lpvData
 , BYVAL pbCancel AS LONG _                             ' __in_opt LPBOOL             pbCancel
 , BYVAL dwCopyFlags AS DWORD _                         ' __in     DWORD              dwCopyFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WIMMountImage IMPORT "wimgapi.dll" ALIAS "WIMMountImage" ( _
   BYREF lpszMountPath AS WSTRINGZ _                    ' __in     LPWSTR lpszMountPath
 , BYREF lpszWimFileName AS WSTRINGZ _                  ' __in     LPWSTR lpszWimFileName
 , BYVAL dwImageIndex AS DWORD _                        ' __in     DWORD  dwImageIndex
 , OPTIONAL BYREF lpszTempPath AS WSTRINGZ _            ' __in_opt LPWSTR lpszTempPath
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WIMUnmountImage IMPORT "wimgapi.dll" ALIAS "WIMUnmountImage" ( _
   BYREF lpszMountPath AS WSTRINGZ _                    ' __in     LPWSTR lpszMountPath
 , BYREF lpszWimFileName AS WSTRINGZ _                  ' __in_opt LPWSTR lpszWimFileName
 , BYVAL dwImageIndex AS DWORD _                        ' __in     DWORD  dwImageIndex
 , BYVAL bCommitChanges AS LONG _                       ' __in     BOOL   bCommitChanges
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WIMGetMountedImages IMPORT "wimgapi.dll" ALIAS "WIMGetMountedImages" ( _
   BYREF lpMountList AS WIM_MOUNT_LIST _                ' __inout LPWIM_MOUNT_LIST lpMountList
 , BYREF lpcbBufferSize AS DWORD _                      ' __inout LPDWORD          lpcbBufferSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WIMInitFileIOCallbacks IMPORT "wimgapi.dll" ALIAS "WIMInitFileIOCallbacks" ( _
   OPTIONAL BYVAL lpCallbacks AS DWORD _                ' __in_opt LPVOID lpCallbacks
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WIMSetFileIOCallbackTemporaryPath IMPORT "wimgapi.dll" ALIAS "WIMSetFileIOCallbackTemporaryPath" ( _
   OPTIONAL BYVAL lpszPath AS DWORD _                   ' __in_opt LPVOID lpszPath
 ) AS LONG                                              ' BOOL

'//
'// File I/O callback prototypes
'//
'typedef VOID * PFILEIOCALLBACK_SESSION;

'typedef
'PFILEIOCALLBACK_SESSION
'(CALLBACK * FileIOCallbackOpenFile)(
'    LPCWSTR lpFileName
'    );

'FUNCTION FileIOCallbackOpenFile ( _
'   BYREF lpFileName AS WSTRINGZ _                       ' LPCWSTR lpFileName
' ) AS DWORD                                             ' PFILEIOCALLBACK_SESSION

'typedef
'BOOL
'(CALLBACK * FileIOCallbackCloseFile)(
'    PFILEIOCALLBACK_SESSION hFile
'    );

'FUNCTION FileIOCallbackCloseFile ( _
'   BYVAL hFile AS DWORD _                               ' PFILEIOCALLBACK_SESSION hFile
' ) AS LONG                                              ' BOOL

'typedef
'BOOL
'(CALLBACK * FileIOCallbackReadFile)(
'    PFILEIOCALLBACK_SESSION hFile,
'    LPVOID lpBuffer,
'    DWORD nNumberOfBytesToRead,
'    LPDWORD lpNumberOfBytesRead,
'    LPOVERLAPPED lpOverlapped
'    );

'FUNCTION FileIOCallbackReadFile ( _
'   BYVAL hFile AS DWORD _                               ' PFILEIOCALLBACK_SESSION hFile
' , BYVAL lpBuffer AS DWORD _                            ' LPVOID lpBuffer
' , BYVAL nNumberOfBytesToRead AS DWORD _                ' DWORD nNumberOfBytesToRead
' , BYREF lpNumberOfBytesRead AS DWORD _                 ' LPDWORD lpNumberOfBytesRead
' , BYREF lpOverlapped AS OVERLAPPED _                   ' LPOVERLAPPED lpOverlapped
' ) AS LONG                                              ' BOOL

'typedef
'BOOL
'(CALLBACK * FileIOCallbackSetFilePointer)(
'    PFILEIOCALLBACK_SESSION hFile,
'    LARGE_INTEGER liDistanceToMove,
'    PLARGE_INTEGER lpNewFilePointer,
'    DWORD dwMoveMethod
'    );

'FUNCTION FileIOCallbackSetFilePointer ( _
'   BYVAL hFile AS DWORD _                               ' PFILEIOCALLBACK_SESSION hFile
' , BYVAL liDistanceToMove AS QUAD _                     ' LARGE_INTEGER liDistanceToMove
' , BYREF lpNewFilePointer AS QUAD _                     ' PLARGE_INTEGER lpNewFilePointer
' , BYVAL dwMoveMethod AS DWORD _                        ' DWORD dwMoveMethod
' ) AS LONG                                              ' BOOL

'typedef
'BOOL
'(CALLBACK * FileIOCallbackGetFileSize)(
'    HANDLE hFile,
'    PLARGE_INTEGER lpFileSize
'    );

'FUNCTION FileIOCallbackGetFileSize ( _
'   BYVAL hFile AS DWORD _                               ' PFILEIOCALLBACK_SESSION hFile
' , BYREF lpFileSize AS QUAD _                           ' PLARGE_INTEGER lpFileSize
' ) AS LONG                                              ' BOOL

' // Size = 20 bytes
TYPE SFileIOCallbackInfo DWORD
   pfnOpenFile       AS DWORD   ' FileIOCallbackOpenFile
   pfnCloseFile      AS DWORD   ' FileIOCallbackCloseFile
   pfnReadFile       AS DWORD   ' FileIOCallbackReadFile
   pfnSetFilePointer AS DWORD   ' FileIOCallbackSetFilePointer
   pfnGetFileSize    AS DWORD   ' FileIOCallbackGetFileSize
END TYPE
