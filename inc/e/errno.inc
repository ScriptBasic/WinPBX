' ########################################################################################
' Microsoft C Runtime
' File: errno.inc
' Contents: System-wide error numbers (set by system calls)
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ERRNO_INC = 1

#INCLUDE ONCE "crtdefs.inc"

'/* declare reference to errno */

'#ifndef _CRT_ERRNO_DEFINED
'#define _CRT_ERRNO_DEFINED
'_CRTIMP extern int * __cdecl _errno(void);
'#define errno   (*_errno())

#IF NOT %DEF(%CRT_ERRNO_DEFINED)
    %CRT_ERRNO_DEFINED = 1

' ========================================================================================
FUNCTION geterrno CDECL () AS LONG
   LOCAL hLib AS DWORD
   LOCAL perrno AS LONG PTR
   hLib = LoadLibrary($CRT_DLLNAME)
   IF hLib THEN
      perrno = GetProcAddress(hLib, "_errno")
      IF perrno THEN FUNCTION = @perrno
      FreeLibrary hLib
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
FUNCTION seterrno CDECL (BYVAL value AS LONG) AS LONG
   LOCAL hLib AS DWORD
   LOCAL perrno AS LONG PTR
   hLib = LoadLibrary($CRT_DLLNAME)
   IF hLib THEN
      perrno = GetProcAddress(hLib, "_errno")
      IF perrno THEN @perrno = Value
      FUNCTION = @perrno
      FreeLibrary hLib
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' errno_t __cdecl _set_errno(_In_ int _Value);
' ========================================================================================
DECLARE FUNCTION set_errno CDECL IMPORT $CRT_DLLNAME ALIAS "_set_errno" ( _
   BYVAL value AS LONG _                                ' int value
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' errno_t __cdecl _get_errno(_Out_ int * _Value);
' ========================================================================================
DECLARE FUNCTION get_errno CDECL IMPORT $CRT_DLLNAME ALIAS "_get_errno" ( _
   BYREF value AS LONG _                                ' int * pValue
 ) AS LONG                                              ' errno_t
' ========================================================================================

#ENDIF   ' CRT_ERRNO_DEFINED

'/* Error Codes */

%EPERM         = 1
%ENOENT        = 2
%ESRCH         = 3
%EINTR         = 4
%EIO           = 5
%ENXIO         = 6
%E2BIG         = 7
%ENOEXEC       = 8
%EBADF         = 9
%ECHILD        = 10
%EAGAIN        = 11
%ENOMEM        = 12
%EACCES        = 13
%EFAULT        = 14
%EBUSY         = 16
%EEXIST        = 17
%EXDEV         = 18
%ENODEV        = 19
%ENOTDIR       = 20
%EISDIR        = 21
%EINVAL        = 22
%ENFILE        = 23
%EMFILE        = 24
%ENOTTY        = 25
%EFBIG         = 27
%ENOSPC        = 28
%ESPIPE        = 29
%EROFS         = 30
%EMLINK        = 31
%EPIPE         = 32
%EDOM          = 33
%ERANGE        = 34
%EDEADLK       = 36
%ENAMETOOLONG  = 38
%ENOLCK        = 39
%ENOSYS        = 40
%ENOTEMPTY     = 41

'/* Error codes used in the Secure CRT functions */

'#ifndef RC_INVOKED
'#if !defined(_SECURECRT_ERRCODE_VALUES_DEFINED)
'#define _SECURECRT_ERRCODE_VALUES_DEFINED
%EINVAL        = 22
%ERANGE        = 34
%EILSEQ        = 42
%STRUNCATE     = 80
'#endif
'#endif

'/*
' * Support EDEADLOCK for compatibiity with older MS-C versions.
' */
%EDEADLOCK     = %EDEADLK
