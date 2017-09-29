' ########################################################################################
' Microsoft C Runtime
' File: io.inc
' Contents: Declarations for low-level file handling and I/O functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IO_INC = 1

#INCLUDE ONCE "crtdefs.inc"

'#ifndef _FSIZE_T_DEFINED
'typedef unsigned long _fsize_t; /* Could be 64 bits for Win32 */
'#define _FSIZE_T_DEFINED
'#endif

#IF NOT %DEF(%FINDDATA_T_DEFINED)
    %FINDDATA_T_DEFINED = 1

' // Size = 280 bytes
TYPE finddata32_t DWORD
   attrib      AS DWORD          ' unsigned
   time_create AS LONG           ' __time32_t /* -1 for FAT file systems */
   time_access AS LONG           ' __time32_t /* -1 for FAT file systems */
   time_write  AS LONG           ' __time32_t
   size        AS DWORD          ' _fsize_t
   name        AS ASCIIZ * 260   ' char
END TYPE

' // Size = 288 bytes
TYPE finddata32i64_t QWORD FILL
   attrib      AS DWORD          ' unsigned
   time_create AS LONG           ' __time32_t /* -1 for FAT file systems */
   time_access AS LONG           ' __time32_t /* -1 for FAT file systems */
   time_write  AS LONG           ' __time32_t
   size        AS QUAD           ' __int64
   name        AS ASCIIZ * 260   ' char
   alignment_  AS DWORD
END TYPE

' // Size = 296 bytes
TYPE finddata64i32_t QWORD FILL
   attrib      AS DWORD          ' unsigned
   time_create AS QUAD           ' __time64_t /* -1 for FAT file systems */
   time_access AS QUAD           ' __time64_t /* -1 for FAT file systems */
   time_write  AS QUAD           ' __time64_t
   size        AS DWORD          ' _fsize_t
   name        AS ASCIIZ * 260   ' char
END TYPE

' // Size = 304 bytes
TYPE finddata64_t QWORD FILL
   attrib      AS DWORD          ' unsigned
   time_create AS QUAD           ' __time64_t /* -1 for FAT file systems */
   time_access AS QUAD           ' __time64_t /* -1 for FAT file systems */
   time_write  AS QUAD           ' __time64_t
   size        AS QUAD           ' __int64
   name        AS ASCIIZ * 260   ' char
   alignment_  AS DWORD
END TYPE

'#ifdef _USE_32BIT_TIME_T
'#define _finddata_t     _finddata32_t
'#define _finddatai64_t  _finddata32i64_t

'#define _findfirst      _findfirst32
'#define _findnext       _findnext32
'#define _findfirsti64   _findfirst32i64
'#define _findnexti64     _findnext32i64

'#else
'#define _finddata_t     _finddata64i32_t
'#define _finddatai64_t  __finddata64_t

'#define _findfirst      _findfirst64i32
'#define _findnext       _findnext64i32
'#define _findfirsti64   _findfirst64
'#define _findnexti64    _findnext64
'#endif

MACRO finddata_t     = finddata32_t
MACRO finddatai64_t  = finddata32i64_t

MACRO findfirst      = findfirst32
MACRO findnext       = findnext32
MACRO findfirsti64   = findfirst32i64
MACRO findnexti64    = findnext32i64

#ENDIF   ' FINDDATA_T_DEFINED

#IF NOT %DEF(%WFINDDATA_T_DEFINED)
    %WFINDDATA_T_DEFINED = 1

' // Size = 540 bytes
TYPE wfinddata32_t DWORD
   attrib      AS DWORD              ' unsigned
   time_create AS LONG               ' __time32_t /* -1 for FAT file systems */
   time_access AS LONG               ' __time32_t /* -1 for FAT file systems */
   time_write  AS LONG               ' __time32_t
   size        AS DWORD              ' _fsize_t
   name        AS WSTRINGZ * 260     ' wchar_t
END TYPE

' // Size = 544 bytes
TYPE wfinddata32i64_t QWORD FILL
   attrib      AS DWORD              ' unsigned
   time_create AS LONG               ' __time32_t /* -1 for FAT file systems */
   time_access AS LONG               ' __time32_t /* -1 for FAT file systems */
   time_write  AS LONG               ' __time32_t
   size        AS QUAD               ' __int64
   name        AS WSTRINGZ * 260     ' wchar_t
END TYPE

' // Size = 560 bytes
TYPE wfinddata64i32_t QWORD FILL
   attrib      AS DWORD              ' unsigned
   time_create AS QUAD               ' __time64_t /* -1 for FAT file systems */
   time_access AS QUAD               ' __time64_t /* -1 for FAT file systems */
   time_write  AS QUAD               ' __time64_t
   size        AS DWORD              ' _fsize_t
   name        AS WSTRINGZ * 260     ' wchar_t
   alignment_  AS DWORD
END TYPE

' // Size = 560 bytes
TYPE wfinddata64_t QWORD FILL
   attrib      AS DWORD              ' unsigned
   time_create AS QUAD               ' __time64_t /* -1 for FAT file systems */
   time_access AS QUAD               ' __time64_t /* -1 for FAT file systems */
   time_write  AS QUAD               ' __time64_t
   size        AS QUAD               ' __int64
   name        AS WSTRINGZ * 260     ' wchar_t
END TYPE

'#ifdef _USE_32BIT_TIME_T
'#define _wfinddata_t    _wfinddata32_t
'#define _wfinddatai64_t _wfinddata32i64_t

'#define _wfindfirst     _wfindfirst32
'#define _wfindnext      _wfindnext32
'#define _wfindfirsti64  _wfindfirst32i64
'#define _wfindnexti64   _wfindnext32i64

'#else
'#define _wfinddata_t    _wfinddata64i32_t
'#define _wfinddatai64_t _wfinddata64_t

'#define _wfindfirst     _wfindfirst64i32
'#define _wfindnext      _wfindnext64i32
'#define _wfindfirsti64  _wfindfirst64
'#define _wfindnexti64   _wfindnext64
'#endif

MACRO wfinddata_t    = wfinddata32_t
MACRO wfinddatai64_t = wfinddata32i64_t

MACRO wfindfirst     = wfindfirst32
MACRO wfindnext      = wfindnext32
MACRO wfindfirsti64  = wfindfirst32i64
MACRO wfindnexti64   = wfindnext32i64

#ENDIF   ' FINDDATA_T_DEFINED

'/* File attribute constants for _findfirst() */

%A_NORMAL       = &H00???    ' /* Normal file - No read/write restrictions */
%A_RDONLY       = &H01???    ' /* Read only file */
%A_HIDDEN       = &H02???    ' /* Hidden file */
%A_SYSTEM       = &H04???    ' /* System file */
%A_SUBDIR       = &H10???    ' /* Subdirectory */
%A_ARCH         = &H20???    ' /* Archive file */

'/* function prototypes */

'#ifndef _SIZE_T_DEFINED
'#ifdef  _WIN64
'typedef unsigned __int64    size_t;
'#else
'typedef _W64 unsigned int   size_t;
'#endif
'#define _SIZE_T_DEFINED
'#endif

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _access(_In_z_ const char * _Filename, _In_ int _AccessMode);
' ========================================================================================
DECLARE FUNCTION access_ CDECL IMPORT $CRT_DLLNAME ALIAS "_access" ( _
   BYREF path AS ASCIIZ _                               ' __in const char *path
 , BYVAL mode AS LONG _                                 ' __in int mode
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _access_s(_In_z_ const char * _Filename, _In_ int _AccessMode);
' ========================================================================================
DECLARE FUNCTION access_s CDECL IMPORT $CRT_DLLNAME ALIAS "_access_s" ( _
   BYREF path AS ASCIIZ _                               ' __in const char *path
 , BYVAL mode AS LONG _                                 ' __in int mode
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _chmod(_In_z_ const char * _Filename, _In_ int _Mode);
' ========================================================================================
DECLARE FUNCTION chmod_ CDECL IMPORT $CRT_DLLNAME ALIAS "_chmod" ( _
   BYREF filename AS ASCIIZ _                           ' __in const char *filename
 , BYVAL pmode AS LONG _                                ' __in int pmode
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _chsize(_In_ int _FileHandle, _In_ long _Size);
' ========================================================================================
DECLARE FUNCTION chsize_ CDECL IMPORT $CRT_DLLNAME ALIAS "_chsize" ( _
   BYVAL fd AS LONG _                                   ' __in int fd
 , BYVAL size AS LONG _                                 ' __in int size
 ) AS LONG                                              ' int

'/* note that the newly added _chsize_s takes a 64 bit value */

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _chsize_s(_In_ int _FileHandle,_In_ __int64 _Size);
' ========================================================================================
DECLARE FUNCTION chsize_s CDECL IMPORT $CRT_DLLNAME ALIAS "_chsize_s" ( _
   BYVAL fd AS LONG _                                   ' __in int fd
 , BYVAL size AS QUAD _                                 ' __in int64 size
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl _close(_In_ int _FileHandle);
' ========================================================================================
DECLARE FUNCTION close_ CDECL IMPORT $CRT_DLLNAME ALIAS "_close" ( _
   BYVAL fd AS LONG _                                   ' __in int fd
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl _commit(_In_ int _FileHandle);
' ========================================================================================
DECLARE FUNCTION commit_ CDECL IMPORT $CRT_DLLNAME ALIAS "_commit" ( _
   BYVAL fd AS LONG _                                   ' __in int fd
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_INSECURE_DEPRECATE(_sopen_s) _CRTIMP int __cdecl _creat(
' _In_z_ const char * _Filename, _In_ int _PermissionMode);
' ========================================================================================
DECLARE FUNCTION creat_ CDECL IMPORT $CRT_DLLNAME ALIAS "_creat" ( _
   BYREF filename AS ASCIIZ _                           ' __in const char *filename
 , BYVAL pmode AS LONG _                                ' __in int pmode
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _dup(_In_ int _FileHandle);
' ========================================================================================
DECLARE FUNCTION dup_ CDECL IMPORT $CRT_DLLNAME ALIAS "_dup" ( _
   BYVAL fd AS LONG _                                   ' __in int fd
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _dup2(_In_ int _FileHandleSrc, _In_ int _FileHandleDst);
' ========================================================================================
DECLARE FUNCTION dup2_ CDECL IMPORT $CRT_DLLNAME ALIAS "_dup2" ( _
   BYVAL fd1 AS LONG _                                  ' __in int fd1
 , BYVAL fd2 AS LONG _                                  ' __in int fd2
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _eof(_In_ int _FileHandle);
' ========================================================================================
DECLARE FUNCTION eof_ CDECL IMPORT $CRT_DLLNAME ALIAS "_eof" ( _
   BYVAL fd AS LONG _                                   ' __in int fd
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP long __cdecl _filelength(_In_ int _FileHandle);
' ========================================================================================
DECLARE FUNCTION filelength_ CDECL IMPORT $CRT_DLLNAME ALIAS "_filelength" ( _
   BYVAL fd AS LONG _                                   ' __in int fd
 ) AS LONG                                              ' long
' ========================================================================================

' ========================================================================================
DECLARE FUNCTION findfirst_ CDECL IMPORT $CRT_DLLNAME ALIAS "_findfirst" ( _
   BYREF filespec AS ASCIIZ _                           ' __in const char *filespec
 , BYREF fileinfo AS finddata_t _                       ' __out struct _finddata_t *fileinfo
 ) AS LONG                                              ' long
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP intptr_t __cdecl _findfirst32(_In_z_ const char * _Filename,
' _Out_ struct _finddata32_t * _FindData);
' ========================================================================================
DECLARE FUNCTION findfirst32_ CDECL IMPORT $CRT_DLLNAME ALIAS "_findfirst32" ( _
   BYREF filespec AS ASCIIZ _                           ' __in const char *filespec
 , BYREF fileinfo AS finddata32_t _                     ' __out struct _finddata32_t *fileinfo
 ) AS LONG                                              ' long
' ========================================================================================

' ========================================================================================
DECLARE FUNCTION findnext_ CDECL IMPORT $CRT_DLLNAME ALIAS "_findnext" ( _
   BYVAL handle AS LONG _                               ' __in long handle
 , BYREF fileinfo AS finddata_t _                       ' __out struct _finddata_t *fileinfo
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _findnext32(_In_ intptr_t _FindHandle, _Out_ struct _finddata32_t * _FindData);
' ========================================================================================
DECLARE FUNCTION findnext32_ CDECL IMPORT $CRT_DLLNAME ALIAS "_findnext32" ( _
   BYVAL handle AS LONG _                               ' __in long handle
 , BYREF fileinfo AS finddata32_t _                     ' __out struct _finddata32_t *fileinfo
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl _findclose(_In_ intptr_t _FindHandle);
' ========================================================================================
DECLARE FUNCTION findclose_ CDECL IMPORT $CRT_DLLNAME ALIAS "_findclose" ( _
   BYVAL handle AS LONG _                               ' __in long handle
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _isatty(_In_ int _FileHandle);
' ========================================================================================
DECLARE FUNCTION isatty_ CDECL IMPORT $CRT_DLLNAME ALIAS "_isatty" ( _
   BYVAL fd AS LONG _                                   ' __in int fd
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP int __cdecl _locking(_In_ int _FileHandle, _In_ int _LockMode, _In_ long _NumOfBytes);
' ========================================================================================
DECLARE FUNCTION locking_ CDECL IMPORT $CRT_DLLNAME ALIAS "_locking" ( _
   BYVAL fd AS LONG _                                   ' __in int fd
 , BYVAL mode AS LONG _                                 ' __in int mode
 , BYVAL nbytes AS LONG _                               ' __in long nbytes
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP long __cdecl _lseek(_In_ int _FileHandle, _In_ long _Offset, _In_ int _Origin);
' ========================================================================================
DECLARE FUNCTION lseek_ CDECL IMPORT $CRT_DLLNAME ALIAS "_lseek" ( _
   BYVAL fd AS LONG _                                   ' __in int fd
 , BYVAL offset AS LONG _                               ' __in long offset
 , BYVAL origin AS LONG _                               ' __in int origin
 ) AS LONG                                              ' long
' ========================================================================================

' ========================================================================================
' *** All versions ***
DECLARE FUNCTION mktemp_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mktemp" ( _
   BYREF template AS ASCIIZ _                           ' __in char *template
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _mktemp_s(_Inout_z_cap_(_Size) char * _TemplateName, _In_ size_t _Size);
' ========================================================================================
DECLARE FUNCTION mktemp_s CDECL IMPORT $CRT_DLLNAME ALIAS "_mktemp_s" ( _
   BYREF template AS ASCIIZ _                           ' __in char *template
 , BYVAL sizeInChars AS DWORD _                         ' __in size_t sizeInChars
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _pipe(_Inout_cap_c_(2) int * _PtHandles, _In_ unsigned int _PipeSize, _In_ int _TextMode);
' ========================================================================================
DECLARE FUNCTION pipe_ CDECL IMPORT $CRT_DLLNAME ALIAS "_pipe" ( _
   BYREF pfds AS LONG _                                 ' __inout int *pfds
 , BYVAL psize AS DWORD _                               ' __in unsigned int psize
 , BYVAL textmode AS LONG _                             ' __in int textmode
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _read(_In_ int _FileHandle,
' _Out_bytecap_(_MaxCharCount) void * _DstBuf, _In_ unsigned int _MaxCharCount);
' ========================================================================================
DECLARE FUNCTION read_ CDECL IMPORT $CRT_DLLNAME ALIAS "_read" ( _
   BYVAL fd AS LONG _                                   ' __in int fd
 , BYREF buffer AS ANY _                                ' __out void *buffer
 , BYVAL count AS DWORD _                               ' __in unsigned int count
 ) AS LONG                                              ' int
' ========================================================================================

#IF NOT %DEF(%CRT_DIRECTORY_DEFINED)
    %CRT_DIRECTORY_DEFINED = 1

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl remove(_In_z_ const char * _Filename);
' ========================================================================================
DECLARE FUNCTION remove CDECL IMPORT $CRT_DLLNAME ALIAS "remove" ( _
   BYREF path AS ASCIIZ _                               ' __in const char *path
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl rename(_In_z_ const char * _OldFilename, _In_z_ const char * _NewFilename);
' ========================================================================================
DECLARE FUNCTION rename CDECL IMPORT $CRT_DLLNAME ALIAS "rename" ( _
   BYREF oldname AS ASCIIZ _                            ' __in const char *oldname
 , BYREF newname AS ASCIIZ _                            ' __in const char *newname
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _unlink(_In_z_ const char * _Filename);
' ========================================================================================
DECLARE FUNCTION unlink_ CDECL IMPORT $CRT_DLLNAME ALIAS " _unlink" (_
   BYREF filename AS ASCIIZ _                           ' __in const char *filename
 ) AS LONG                                              ' int
' ========================================================================================

#ENDIF   ' CRT_DIRECTORY_DEFINED

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _setmode(_In_ int _FileHandle, _In_ int _Mode);
' ========================================================================================
DECLARE FUNCTION setmode_ CDECL IMPORT $CRT_DLLNAME ALIAS "_setmode" ( _
   BYVAL fd AS LONG _                                   ' __in int fd
 , BYVAL mode AS LONG _                                 ' __in int mode
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP long __cdecl _tell(_In_ int _FileHandle);
' ========================================================================================
DECLARE FUNCTION tell_ CDECL IMPORT $CRT_DLLNAME ALIAS "_tell" ( _
   BYVAL fd AS LONG _                                   ' __in int fd
 ) AS LONG                                              ' long
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRT_INSECURE_DEPRECATE(_umask_s) _CRTIMP int __cdecl _umask(_In_ int _Mode);
' ========================================================================================
DECLARE FUNCTION umask_ CDECL IMPORT $CRT_DLLNAME ALIAS "_umask" ( _
   BYVAL pmode AS LONG _                                ' __in int pmode
 ) AS LONG                                              ' long
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _umask_s(_In_ int _NewMode, _Out_ int * _OldMode);
' ========================================================================================
DECLARE FUNCTION umask_s CDECL IMPORT $CRT_DLLNAME ALIAS "_umask_s" ( _
   BYVAL pmode AS LONG _                                ' __in int pmode
 , BYREF pOldMode AS LONG _                             ' __out int * pOldMode
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP int __cdecl _write(_In_ int _FileHandle, _In_bytecount_(_MaxCharCount)
' const void * _Buf, _In_ unsigned int _MaxCharCount);
' ========================================================================================
DECLARE FUNCTION write_ CDECL IMPORT $CRT_DLLNAME ALIAS "_write" ( _
   BYVAL fd AS LONG _                                   ' __in int fd
 , BYREF buffer AS ANY _                                ' __in const void *buffer
 , BYVAL count AS DWORD _                               ' __in unsigned int count
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP __int64 __cdecl _filelengthi64(_In_ int _FileHandle);
' ========================================================================================
DECLARE FUNCTION filelengthi64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_filelengthi64" ( _
   BYVAL fd AS LONG _                                   ' __in int fd
 ) AS QUAD                                              ' __int64
' ========================================================================================

' ========================================================================================
DECLARE FUNCTION findfirsti64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_findfirsti64" ( _
   BYREF filespec AS ASCIIZ _                           ' __in const char *filespec
 , BYREF fileinfo AS finddatai64_t _                    ' __out struct _finddatai64_t *fileinfo
 ) AS LONG                                              ' long
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP intptr_t __cdecl _findfirst32i64(_In_z_ const char * _Filename,
' _Out_ struct _finddata32i64_t * _FindData);
' ========================================================================================
DECLARE FUNCTION findfirst32i64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_findfirst32i64" ( _
   BYREF filespec AS ASCIIZ _                           ' __in const char *filespec
 , BYREF fileinfo AS finddata32i64_t _                  ' __out struct _finddata32i64_t *fileinfo
 ) AS DWORD                                             ' intptr_t
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP intptr_t __cdecl _findfirst64i32(_In_z_ const char * _Filename,
' _Out_ struct _finddata64i32_t * _FindData);
' ========================================================================================
DECLARE FUNCTION findfirst64i32_ CDECL IMPORT $CRT_DLLNAME ALIAS "_findfirst64i32" ( _
   BYREF filespec AS ASCIIZ _                           ' __in const char *filespec
 , BYREF fileinfo AS finddata64i32_t _                  ' __out struct _finddata64i32_t *fileinfo
 ) AS DWORD                                             ' intptr_t
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP intptr_t __cdecl _findfirst64(_In_z_ const char * _Filename,
' _Out_ struct __finddata64_t * _FindData);
' ========================================================================================
DECLARE FUNCTION findfirst64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_findfirst64" ( _
   BYREF filespec AS ASCIIZ _                           ' __in const char *filespec
 , BYREF fileinfo AS finddata64_t _                     ' __out struct _finddata64_t *fileinfo
 ) AS DWORD                                             ' intptr_t
' ========================================================================================

' ========================================================================================
DECLARE FUNCTION findnexti64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_findnexti64" ( _
   BYVAL handle AS LONG _                               ' __in long handle
 , BYREF fileinfo AS finddatai64_t _                    ' __out struct _finddatai64_t *fileinfo
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _findnext32i64(_In_ intptr_t _FindHandle,
' _Out_ struct _finddata32i64_t * _FindData);
' ========================================================================================
DECLARE FUNCTION findnext32i64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_findnext32i64" ( _
   BYREF filespec AS ASCIIZ _                           ' __in const char *filespec
 , BYREF fileinfo AS finddata32i64_t _                  ' __out struct _finddata32i64_t *fileinfo
 ) AS DWORD                                             ' intptr_t
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _findnext64i32(_In_ intptr_t _FindHandle,
' _Out_ struct _finddata64i32_t * _FindData);
' ========================================================================================
DECLARE FUNCTION findnext64i32_ CDECL IMPORT $CRT_DLLNAME ALIAS "_findnext64i32" ( _
   BYREF filespec AS ASCIIZ _                           ' __in const char *filespec
 , BYREF fileinfo AS finddata64i32_t _                  ' __out struct _finddata64i32_t *fileinfo
 ) AS DWORD                                             ' intptr_t
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _findnext64(_In_ intptr_t _FindHandle,
' _Out_ struct __finddata64_t * _FindData);
' ========================================================================================
DECLARE FUNCTION findnext64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_findnext64" ( _
   BYREF filespec AS ASCIIZ _                           ' __in const char *filespec
 , BYREF fileinfo AS finddata64_t _                     ' __out struct __finddata64_t *fileinfo
 ) AS DWORD                                             ' intptr_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP __int64 __cdecl _lseeki64(_In_ int _FileHandle,
' _In_ __int64 _Offset, _In_ int _Origin);
' ========================================================================================
DECLARE FUNCTION lseeki64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_lseeki64" ( _
   BYVAL fd AS LONG _                                   ' __in int fd
 , BYVAL offset AS QUAD _                               ' __in __int64 offset
 , BYVAL origin AS LONG _                               ' __in int origin
 ) AS QUAD                                              ' __int64
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP __int64 __cdecl _telli64(_In_ int _FileHandle);
' ========================================================================================
DECLARE FUNCTION telli64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_telli64" ( _
   BYVAL fd AS LONG _                                   ' __in int fd
 ) AS QUAD                                              ' __int64
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_INSECURE_DEPRECATE(_sopen_s) _CRTIMP int __cdecl _open( _
' _In_z_ const char * _Filename, _In_ int _Openflag, _In_ int _PermissionMode);
' ========================================================================================
DECLARE FUNCTION open_ CDECL IMPORT $CRT_DLLNAME ALIAS "_open" ( _
   BYREF filename AS ASCIIZ _                           ' __in const char *filename
 , BYVAL oflag AS LONG _                                ' __in int oflag
 , OPTIONAL BYVAL pmode AS LONG _                       ' __in pmode
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_INSECURE_DEPRECATE(_sopen_s) _CRTIMP int __cdecl _sopen(
' _In_z_ const char * _Filename, _In_ int _Openflag, _In_ int _ShareFlag, _In_ int _PermissionMode);
' ========================================================================================
DECLARE FUNCTION sopen_ CDECL IMPORT $CRT_DLLNAME ALIAS "_sopen" ( _
   BYREF filename AS ASCIIZ _                           ' __inconst char *filename
 , BYVAL oflag AS LONG _                                ' __inint oflag
 , BYVAL shflag AS LONG _                               ' __inint shflag
 , OPTIONAL BYVAL pmode AS LONG _                       ' __in pmode
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _sopen_s(_Out_ int * _FileHandle,
' _In_z_ const char * _Filename,_In_ int _OpenFlag, _In_ int _ShareFlag, _In_ int _PermissionMode);
' ========================================================================================
DECLARE FUNCTION sopen_s CDECL IMPORT $CRT_DLLNAME ALIAS "_sopen_s" ( _
   BYREF pfh AS LONG _                                  ' __out int* pfh
 , BYREF filename AS ASCIIZ _                           ' __in const char *filename
 , BYVAL oflag AS LONG _                                ' __in int oflag
 , BYVAL shflag AS LONG _                               ' __in int shflag
 , OPTIONAL BYVAL pmode AS LONG _                       ' __in pmode
 ) AS LONG                                              ' errno_t
' ========================================================================================

#IF NOT %DEF(%WIO_DEFINED)
    %WIO_DEFINED = 1

'/* wide function prototypes, also declared in wchar.h  */

' ========================================================================================
' *** All versions ***
'_Check_return_ _CRTIMP int __cdecl _waccess(_In_z_ const wchar_t * _Filename, _In_ int _AccessMode);
' ========================================================================================
DECLARE FUNCTION waccess_ CDECL IMPORT $CRT_DLLNAME ALIAS "_waccess" ( _
   BYREF path AS WSTRINGZ _                             ' __in const wchar_t *path
 , BYVAL mode AS LONG _                                 ' __in int mode
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _waccess_s(_In_z_ const wchar_t * _Filename, _In_ int _AccessMode);
' ========================================================================================
DECLARE FUNCTION waccess_s CDECL IMPORT $CRT_DLLNAME ALIAS "_waccess_s" ( _
   BYREF path AS WSTRINGZ _                             ' __in const wchar_t *path
 , BYVAL mode AS LONG _                                 ' __in int mode
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _wchmod(_In_z_ const wchar_t * _Filename, _In_ int _Mode);
' ========================================================================================
DECLARE FUNCTION wchmod_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wchmod" ( _
   BYREF filename AS WSTRINGZ _                         ' __in const wchar_t *filename
 , BYVAL pmode AS LONG _                                ' __in int pmode
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_INSECURE_DEPRECATE(_wsopen_s) _CRTIMP int __cdecl _wcreat(
' _In_z_ const wchar_t * _Filename, _In_ int _PermissionMode);
' ========================================================================================
DECLARE FUNCTION wcreat_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wcreat" ( _
   BYREF filename AS WSTRINGZ _                         ' __in const wchar_t *filename
 , BYVAL pmode AS LONG _                                ' __in int pmode
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
DECLARE FUNCTION wfindfirst_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wfindfirst" ( _
   BYREF filespec AS WSTRINGZ _                         ' const wchar_t *filespec
 , BYREF fileinfo AS wfinddata_t _                      ' struct _wfinddata_t *fileinfo
 ) AS LONG                                              ' long
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP intptr_t __cdecl _wfindfirst32(_In_z_ const wchar_t * _Filename,
' _Out_ struct _wfinddata32_t * _FindData);
' ========================================================================================
DECLARE FUNCTION wfindfirst32_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wfindfirst32" ( _
   BYREF filespec AS WSTRINGZ _                         ' __in const wchar_t *filespec
 , BYREF fileinfo AS wfinddata32_t _                    ' __out struct _wfinddata32_t *fileinfo
 ) AS LONG                                              ' long
' ========================================================================================

' ========================================================================================
DECLARE FUNCTION wfindnext_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wfindnext" ( _
   BYVAL handle AS LONG _                               ' long handle
 , BYREF fileinfo AS wfinddata_t _                      ' struct _wfinddata_t *fileinfo
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _wfindnext32(_In_ intptr_t _FindHandle, _Out_ struct _wfinddata32_t * _FindData);
' ========================================================================================
DECLARE FUNCTION wfindnext32_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wfindnext32" ( _
   BYVAL handle AS LONG _                               ' __in long handle
 , BYREF fileinfo AS wfinddata32_t _                    ' __out struct _wfinddata32_t *fileinfo
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _wunlink(_In_z_ const wchar_t * _Filename);
' ========================================================================================
DECLARE FUNCTION wunlink_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wunlink" ( _
   BYREF filename AS WSTRINGZ _                         ' __in const wchar_t *filename
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _wrename(_In_z_ const wchar_t * _OldFilename, _In_z_ const wchar_t * _NewFilename);
' ========================================================================================
DECLARE FUNCTION wrename_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wrename" ( _
   BYREF oldname AS WSTRINGZ _                          ' __in const wchar_t *oldname
 , BYREF newname AS WSTRINGZ _                          ' __in const wchar_t *newname
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' wchar_t *_wmktemp(wchar_t *template);
' ========================================================================================
DECLARE FUNCTION wmktemp_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wmktemp" ( _
   BYREF template AS WSTRINGZ _                         ' wchar_t *template
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _wmktemp_s(_Inout_z_cap_(_SizeInWords) wchar_t * _TemplateName, _In_ size_t _SizeInWords);
' ========================================================================================
DECLARE FUNCTION wmktemp_s CDECL IMPORT $CRT_DLLNAME ALIAS "_wmktemp_s" ( _
   BYREF template AS WSTRINGZ _                         ' __in wchar_t *template
 , BYVAL sizeInChars AS DWORD _                         ' __in size_t sizeInChars
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
DECLARE FUNCTION wfindfirsti64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wfindfirsti64" ( _
   BYREF filespec AS ASCIIZ _                           ' const char *filespec
 , BYREF fileinfo AS wfinddatai64_t _                   ' struct _wfinddatai64_t *fileinfo
 ) AS LONG                                              ' long
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP intptr_t __cdecl _wfindfirst32i64(_In_z_ const wchar_t * _Filename,
' _Out_ struct _wfinddata32i64_t * _FindData);
' ========================================================================================
DECLARE FUNCTION wfindfirst32i64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wfindfirst32i64" ( _
   BYREF filespec AS ASCIIZ _                           ' __in const char *filespec
 , BYREF fileinfo AS wfinddata32i64_t _                 ' __out struct _wfinddata32i64_t *fileinfo
 ) AS DWORD                                             ' intptr_t
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP intptr_t __cdecl _wfindfirst64i32(_In_z_ const wchar_t * _Filename,
' _Out_ struct _wfinddata64i32_t * _FindData);
' ========================================================================================
DECLARE FUNCTION wfindfirst64i32_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wfindfirst64i32" ( _
   BYREF filespec AS ASCIIZ _                           ' __in const char *filespec
 , BYREF fileinfo AS wfinddata64i32_t _                 ' __out struct _wfinddata64i32_t *fileinfo
 ) AS DWORD                                             ' intptr_t
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP intptr_t __cdecl _wfindfirst64(_In_z_ const wchar_t * _Filename,
' _Out_ struct _wfinddata64_t * _FindData);
' ========================================================================================
DECLARE FUNCTION wfindfirst64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wfindfirst64" ( _
   BYREF filespec AS ASCIIZ _                           ' __in const char *filespec
 , BYREF fileinfo AS wfinddata64_t _                    ' __out struct _wfinddata64_t *fileinfo
 ) AS DWORD                                             ' intptr_t

' ========================================================================================

' ========================================================================================
DECLARE FUNCTION wfindnexti64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wfindnexti64" ( _
   BYVAL handle AS LONG _                               ' long handle
 , BYREF fileinfo AS wfinddatai64_t _                   ' struct _wfinddatai64_t *fileinfo
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _wfindnext32i64(_In_ intptr_t _FindHandle, _Out_ struct _wfinddata32i64_t * _FindData);
' ========================================================================================
DECLARE FUNCTION wfindnext32i64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wfindnext32i64" ( _
   BYVAL handle AS LONG _                               ' __in long handle
 , BYREF fileinfo AS wfinddatai64_t _                   ' __out struct _wfinddatai64_t *fileinfo
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _wfindnext64i32(_In_ intptr_t _FindHandle, _Out_ struct _wfinddata64i32_t * _FindData);
' ========================================================================================
DECLARE FUNCTION wfindnext64i32_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wfindnext64i32" ( _
   BYVAL handle AS LONG _                               ' __in long handle
 , BYREF fileinfo AS wfinddata64i32_t _                 ' __out struct _wfinddata64i32_t *fileinfo
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _wfindnext64(_In_ intptr_t _FindHandle, _Out_ struct _wfinddata64_t * _FindData);
' ========================================================================================
DECLARE FUNCTION wfindnext64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wfindnext64" ( _
   BYVAL handle AS LONG _                               ' __in long handle
 , BYREF fileinfo AS wfinddata64_t _                    ' __out struct _wfinddata64_t *fileinfo
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' extern "C++" _CRT_INSECURE_DEPRECATE(_wsopen_s) _CRTIMP int __cdecl _wopen(
' _In_z_ const wchar_t * _Filename, _In_ int _OpenFlag, _In_ int _PermissionMode = 0);
' ========================================================================================
DECLARE FUNCTION wopen_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wopen" ( _
   BYREF filename AS WSTRINGZ _                         ' __in const wchar_t *filename
 , BYVAL oflag AS LONG _                                ' __in int oflag
 , OPTIONAL BYVAL pmode AS LONG _                       ' __in pmode
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _wsopen_s(_Out_ int * _FileHandle,
' _In_z_ const wchar_t * _Filename, _In_ int _OpenFlag, _In_ int _ShareFlag, _In_ int _PermissionFlag);
' ========================================================================================
DECLARE FUNCTION wsopen_s CDECL IMPORT $CRT_DLLNAME ALIAS "_wsopen_s" ( _
   BYREF pfh AS LONG _                                  ' __out int* pfh
 , BYREF filename AS WSTRINGZ _                         ' __in const wchar_t *filename
 , BYVAL oflag AS LONG _                                ' __in int oflag
 , BYVAL shflag AS LONG _                               ' __in int shflag
 , OPTIONAL BYVAL pmode AS LONG _                       ' __in pmode
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' extern "C++" _CRT_INSECURE_DEPRECATE(_wsopen_s) _CRTIMP int __cdecl _wsopen(
' _In_z_ const wchar_t * _Filename, _In_ int _OpenFlag, _In_ int _ShareFlag, int _PermissionMode = 0);
' ========================================================================================
DECLARE FUNCTION wsopen_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wsopen" ( _
   BYREF filename AS WSTRINGZ _                         ' __in const wchar_t *filename
 , BYVAL oflag AS LONG _                                ' __in int oflag
 , BYVAL shflag AS LONG _                               ' __in int shflag
 , OPTIONAL BYVAL pmode AS LONG _                       ' __in pmode
 ) AS LONG                                              ' int
' ========================================================================================

#ENDIF   ' WIO_DEFINED

' ========================================================================================
' *** All versions ***
' _CRTIMP intptr_t __cdecl _get_osfhandle(_In_ int _FileHandle);
' ========================================================================================
DECLARE FUNCTION get_osfhandle_ CDECL IMPORT $CRT_DLLNAME ALIAS "_get_osfhandle" ( _
   BYVAL fd AS LONG _                                   ' __in int fd
 ) AS LONG                                              ' long
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP int __cdecl _open_osfhandle(_In_ intptr_t _OSFileHandle, _In_ int _Flags);
' ========================================================================================
DECLARE FUNCTION open_osfhandle_ CDECL IMPORT $CRT_DLLNAME ALIAS "_open_osfhandle" ( _
   BYVAL osfhandle AS LONG _                            ' __in long osfhandle
 , BYVAL flags AS LONG _                                ' __in int flags
 ) AS LONG                                              ' int
' ========================================================================================
