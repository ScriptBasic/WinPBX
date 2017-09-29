' ########################################################################################
' Microsoft C Runtime
' File: utime.inc
' Contents: This file defines the structure used by the utime routine to set new file
' access and modification times.  NOTE - MS-DOS does not recognize access time, so this
' field will always be ignored and the modification time field will be used to set the
' new time.
' Copyright (c) 2010 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%UTIME_INC = 1

#INCLUDE ONCE "crtdefs.inc"

'/* define struct used by _utime() function */

#IF NOT %DEF(%UTIMBUF_DEFINED)
%UTIMBUF_DEFINED = 1
' // Size = 8 bytes
TYPE utimbuf DWORD
   actime  AS LONG       ' time_t /* access time */
   modtime AS LONG       ' time_t /* modification time */
END TYPE

' // Size = 8 bytes
TYPE utimbuf32 DWORD
   actime  AS LONG       ' __time32_t /* access time */
   modtime AS LONG       ' __time32_t /* modification time */
END TYPE

' // Size = 8 bytes
TYPE utimbuf64 QWORD
   actime  AS QUAD       ' __time64_t /* access time */
   modtime AS QUAD       ' __time64_t /* modification time */
END TYPE
#ENDIF

'/* Function Prototypes */

' ========================================================================================
DECLARE FUNCTION utime_ CDECL IMPORT $CRT_DLLNAME ALIAS "_utime" ( _
   BYREF filename AS ASCIIZ _                           ' __in const char *filename
 , BYREF times AS utimbuf _                             ' __in_opt struct _utimbuf *times
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP int __cdecl _utime32(_In_z_ const char * _Filename, _In_opt_ struct __utimbuf32 * _Time);
' ========================================================================================
DECLARE FUNCTION utime32_ CDECL IMPORT $CRT_DLLNAME ALIAS "_utime32" ( _
   BYREF filename AS ASCIIZ _                           ' __in const char *filename
 , BYREF times AS utimbuf32 _                           ' __in_opt struct __utimbuf32 *times
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
DECLARE FUNCTION futime_ CDECL IMPORT $CRT_DLLNAME ALIAS "_futime" ( _
   BYVAL fd AS LONG _                                   ' __in int fd
 , BYREF times AS utimbuf _                             ' __in_opt struct _utimbuf *times
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP int __cdecl _futime32(_In_ int _FileDes, _In_opt_ struct __utimbuf32 * _Time);
' ========================================================================================
DECLARE FUNCTION futime32_ CDECL IMPORT $CRT_DLLNAME ALIAS "_futime32" ( _
   BYVAL fd AS LONG _                                   ' __in int fd
 , BYREF times AS utimbuf32 _                           ' __in_opt struct __utimbuf32 *times
 ) AS LONG                                              ' int
' ========================================================================================

'/* Wide Function Prototypes */

' ========================================================================================
DECLARE FUNCTION wutime_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wutime" ( _
   BYREF filename AS WSTRINGZ _                         ' __in const wchar_t *filename
 , BYREF times AS utimbuf _                             ' __in_opt struct _utimbuf *times
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP int __cdecl _wutime32(_In_z_ const wchar_t * _Filename, _In_opt_ struct __utimbuf32 * _Time);
' ========================================================================================
DECLARE FUNCTION wutime32_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wutime32" ( _
   BYREF filename AS WSTRINGZ _                         ' __in const wchar_t *filename
 , BYREF times AS utimbuf32 _                           ' __in_opt struct __utimbuf32 *times
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP int __cdecl _utime64(_In_z_ const char * _Filename, _In_opt_ struct __utimbuf64 * _Time);
' ========================================================================================
DECLARE FUNCTION utime64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_utime64" ( _
   BYREF filename AS ASCIIZ _                           ' __in const char *filename
 , BYREF times AS utimbuf64 _                           ' __in_opt struct __utimbuf64 *times
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP int __cdecl _futime64(_In_ int _FileDes, _In_opt_ struct __utimbuf64 * _Time);
' ========================================================================================
DECLARE FUNCTION futime64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_futime64" ( _
   BYVAL fd AS LONG _                                   ' __in int fd
 , BYREF times AS utimbuf64 _                           ' __in_opt struct __utimbuf64 *times
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP int __cdecl _wutime64(_In_z_ const wchar_t * _Filename, _In_opt_ struct __utimbuf64 * _Time);
' ========================================================================================
DECLARE FUNCTION wutime64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wutime64" ( _
   BYREF filename AS WSTRINGZ _                         ' __in const wchar_t *filename
 , BYREF times AS utimbuf64 _                           ' __in_opt struct __utimbuf64 *times
 ) AS LONG                                              ' int
' ========================================================================================
