' ########################################################################################
' Microsoft C Runtime
' File: direct.inc
' Contents: Functions related to directory handling and creation.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DIRECT_INC = 1

#INCLUDE ONCE "crtdefs.inc"

'/* _getdiskfree structure for _getdiskfree() */
#IF NOT %DEF(%DISKFREE_T_DEFINED)
%DISKFREE_T_DEFINED = 1
' // Size = 16 bytes
TYPE diskfree_t
   total_clusters      AS DWORD   ' unsigned
   avail_clusters      AS DWORD   ' unsigned
   sectors_per_cluster AS DWORD   ' unsigned
   bytes_per_sector    AS DWORD   ' unsigned
END TYPE
#ENDIF

'/* function prototypes */

' ========================================================================================
' *** All versions ***
' _Check_return_ _Ret_opt_z_ _CRTIMP char * __cdecl _getcwd(
' _Out_opt_cap_(_SizeInBytes) char * _DstBuf, _In_ int _SizeInBytes);
' ========================================================================================
DECLARE FUNCTION getcwd_ CDECL IMPORT $CRT_DLLNAME ALIAS "_getcwd" ( _
   BYREF dirname AS ASCIIZ _                            ' __out const char *dirname
 , BYVAL maxlen AS LONG _                               ' __in int maxlen
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _Ret_opt_z_ _CRTIMP char * __cdecl _getdcwd(_In_ int _Drive,
' _Out_opt_cap_(_SizeInBytes) char * _DstBuf, _In_ int _SizeInBytes);
' ========================================================================================
DECLARE FUNCTION getdcwd_ CDECL IMPORT $CRT_DLLNAME ALIAS "_getdcwd" ( _
   BYVAL drive AS LONG _                                ' __in int drive
 , BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL maxlen AS LONG _                               ' __in int maxlen
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' _Check_return_ _Ret_opt_z_ char * __cdecl _getdcwd_nolock(_In_ int _Drive,
' _Out_opt_cap_(_SizeInBytes) char * _DstBuf, _In_ int _SizeInBytes);
' ========================================================================================
DECLARE FUNCTION getdcwd_nolock CDECL IMPORT $CRT_DLLNAME ALIAS "_getdcwd_nolock" ( _
   BYVAL drive AS LONG _                                ' __in int drive
 , BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL maxlen AS LONG _                               ' __in int maxlen
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _chdir(_In_z_ const char * _Path);
' ========================================================================================
DECLARE FUNCTION chdir_ CDECL IMPORT $CRT_DLLNAME ALIAS "_chdir" ( _
   BYREF dirname AS ASCIIZ _                            ' __in const char *dirname
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _mkdir(_In_z_ const char * _Path);
' ========================================================================================
DECLARE FUNCTION mkdir_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mkdir" ( _
   BYREF dirname AS ASCIIZ _                            ' __in const char *dirname
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _rmdir(_In_z_ const char * _Path);
' ========================================================================================
DECLARE FUNCTION rmdir_ CDECL IMPORT $CRT_DLLNAME ALIAS "_rmdir" ( _
   BYREF dirname AS ASCIIZ _                            ' __in const char *dirname
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _chdrive(_In_ int _Drive);
' ========================================================================================
DECLARE FUNCTION chdrive_ CDECL IMPORT $CRT_DLLNAME ALIAS "_chdrive" ( _
   BYVAL drive AS LONG _                                ' __in int drive
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _getdrive(void);
' ========================================================================================
DECLARE FUNCTION getdrive_ CDECL IMPORT $CRT_DLLNAME ALIAS "_getdrive" ( _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP unsigned long __cdecl _getdrives(void);
' ========================================================================================
DECLARE FUNCTION getdrives_ CDECL IMPORT $CRT_DLLNAME ALIAS "_getdrives" ( _
 ) AS DWORD                                             ' unsigned long
' ========================================================================================

#IF NOT %DEF(%GETDISKFREE_DEFINED)
%GETDISKFREE_DEFINED = 1
' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP unsigned __cdecl _getdiskfree(_In_ unsigned _Drive,
' _Out_ struct _diskfree_t * _DiskFree);
' ========================================================================================
DECLARE FUNCTION getdiskfree_ CDECL IMPORT $CRT_DLLNAME ALIAS "_getdiskfree" ( _
   BYVAL drive AS DWORD _                               ' __in unsigned drive
 , BYREF driveinfo AS diskfree_t _                      ' __out struct _diskfree_t *driveinfo
 ) AS DWORD                                             ' unsigned
' ========================================================================================
#ENDIF


#IF NOT %DEF(%WDIRECT_DEFINED)
    %WDIRECT_DEFINED = 1

'/* wide function prototypes, also declared in wchar.h  */

' ========================================================================================
' *** All versions ***
' _Check_return_ _Ret_opt_z_ _CRTIMP wchar_t * __cdecl _wgetcwd(
' _Out_opt_cap_(_SizeInWords) wchar_t * _DstBuf, _In_ int _SizeInWords);
' ========================================================================================
DECLARE FUNCTION wgetcwd_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wgetcwd" ( _
   BYREF dirname AS WSTRINGZ _                          ' __out const wchar_t *dirname
 , BYVAL maxlen AS LONG _                               ' __in int maxlen
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _Ret_opt_z_ _CRTIMP wchar_t * __cdecl _wgetdcwd(
' _In_ int _Drive, _Out_opt_cap_(_SizeInWords) wchar_t * _DstBuf, _In_ int _SizeInWords);
' ========================================================================================
DECLARE FUNCTION wgetdcwd_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wgetdcwd" ( _
   BYVAL drive AS LONG _                                ' __in int drive
 , BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL maxlen AS LONG _                               ' __in int maxlen
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' _Check_return_ _Ret_opt_z_ wchar_t * __cdecl _wgetdcwd_nolock(_In_ int _Drive,
' _Out_opt_cap_(_SizeInWords) wchar_t * _DstBuf, _In_ int _SizeInWords);
' ========================================================================================
DECLARE FUNCTION wgetdcwd_nolock CDECL IMPORT $CRT_DLLNAME ALIAS "_wgetdcwd_nolock" ( _
   BYVAL drive AS LONG _                                ' __in int drive
 , BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL maxlen AS LONG _                               ' __in int maxlen
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' *** All versions ***
'_Check_return_ _CRTIMP int __cdecl _wchdir(_In_z_ const wchar_t * _Path);
' ========================================================================================
DECLARE FUNCTION wchdir_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wchdir" ( _
   BYREF dirname AS WSTRINGZ _                          ' __in const wchar_t *dirname
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _wmkdir(_In_z_ const wchar_t * _Path);
' ========================================================================================
DECLARE FUNCTION wmkdir_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wmkdir" ( _
   BYREF dirname AS WSTRINGZ _                          ' __in const wchar_t *dirname
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _wrmdir(_In_z_ const wchar_t * _Path);
' ========================================================================================
DECLARE FUNCTION wrmdir_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wrmdir" ( _
   BYREF dirname AS WSTRINGZ _                          ' __in const wchar_t *dirname
 ) AS LONG                                              ' int
' ========================================================================================

#ENDIF   ' _WDIRECT_DEFINED
