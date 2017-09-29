' ########################################################################################
' Microsoft C Runtime
' File: string.inc
' Contents: Function declarations for the string manipulation functions.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%STRING_INC = 1

#INCLUDE ONCE "crtdefs.inc"
#INCLUDE ONCE "memory.inc"

#IF NOT %DEF(%NLSCMP_DEFINED)
%NLSCMP_DEFINED = 1
%NLSCMPERROR   = 2147483647&  ' /* currently == INT_MAX */
#ENDIF

'/* For backwards compatibility */
'#define _WConst_return _CONST_RETURN

'/* Function prototypes */
'#ifndef _CRT_MEMORY_DEFINED
'#define _CRT_MEMORY_DEFINED
'_CRTIMP void *  __cdecl _memccpy( _Out_opt_bytecap_(_MaxCount) void * _Dst, _In_ const void * _Src, _In_ int _Val, _In_ size_t _MaxCount);
'_Check_return_ _CRTIMP _CONST_RETURN void *  __cdecl memchr( _In_opt_bytecount_(_MaxCount) const void * _Buf , _In_ int _Val, _In_ size_t _MaxCount);
'_Check_return_ _CRTIMP int     __cdecl _memicmp(_In_opt_bytecount_(_Size) const void * _Buf1, _In_opt_bytecount_(_Size) const void * _Buf2, _In_ size_t _Size);
'_Check_return_ _CRTIMP int     __cdecl _memicmp_l(_In_opt_bytecount_(_Size) const void * _Buf1, _In_opt_bytecount_(_Size) const void * _Buf2, _In_ size_t _Size, _In_opt_ _locale_t _Locale);
'_Check_return_ int     __cdecl memcmp(_In_opt_bytecount_(_Size) const void * _Buf1, _In_opt_bytecount_(_Size) const void * _Buf2, _In_ size_t _Size);
'_CRT_INSECURE_DEPRECATE_MEMORY(memcpy_s) void *  __cdecl memcpy(_Out_opt_bytecapcount_(_Size) void * _Dst, _In_opt_bytecount_(_Size) const void * _Src, _In_ size_t _Size);
'#if __STDC_WANT_SECURE_LIB__
'_CRTIMP errno_t  __cdecl memcpy_s(_Out_opt_bytecap_post_bytecount_(_DstSize, _MaxCount) void * _Dst, _In_ rsize_t _DstSize, _In_opt_bytecount_(_MaxCount) const void * _Src, _In_ rsize_t _MaxCount);
'#endif
'void *  __cdecl memset(_Out_opt_bytecapcount_(_Size) void * _Dst, _In_ int _Val, _In_ size_t _Size);

'#if     !__STDC__
'/* Non-ANSI names for compatibility */
'_CRT_NONSTDC_DEPRECATE(_memccpy) _CRTIMP void * __cdecl memccpy(_Out_opt_bytecap_(_Size) void * _Dst, _In_opt_bytecount_(_Size) const void * _Src, _In_ int _Val, _In_ size_t _Size);
'_Check_return_ _CRT_NONSTDC_DEPRECATE(_memicmp) _CRTIMP int __cdecl memicmp(_In_opt_bytecount_(_Size) const void * _Buf1, _In_opt_bytecount_(_Size) const void * _Buf2, _In_ size_t _Size);
'#endif  /* __STDC__ */

'#endif

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION strset_ CDECL IMPORT $CRT_DLLNAME ALIAS "_strset" ( _
   BYREF string AS ASCIIZ _                             ' __in char *string
 , BYVAL c AS LONG _                                    ' __in int c
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP_ALTERNATIVE errno_t __cdecl _strset_s(
' _Inout_z_cap_(_DstSize) char * _Dst, _In_ size_t _DstSize, _In_ int _Value);
' ========================================================================================
DECLARE FUNCTION strset_s CDECL IMPORT $CRT_DLLNAME ALIAS "_strset_s" ( _
   BYREF string AS ASCIIZ _                             ' __inout char *string
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' // Added an underscore because it conflicts with the function StrCpy in shlwapi.inc
' ========================================================================================
DECLARE FUNCTION strcpy_ CDECL IMPORT $CRT_DLLNAME ALIAS "strcpy" ( _
   BYREF strDestination AS ASCIIZ _                     ' __in char *strDestination
 , BYREF strSource AS ASCIIZ _                          ' __in const char *strSource
 ) AS DWORD                                             ' char *
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_wat_ _CRTIMP_ALTERNATIVE errno_t __cdecl strcpy_s(
' _Out_z_cap_(_SizeInBytes) char * _Dst, _In_ rsize_t _SizeInBytes, _In_z_ const char * _Src);
' ========================================================================================
DECLARE FUNCTION strcpy_s CDECL IMPORT $CRT_DLLNAME ALIAS "strcpy_s" ( _
   BYREF strDestination AS ASCIIZ _                     ' __out char *strDestination
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , BYREF strSource AS ASCIIZ _                          ' __in const char *strSource
 ) AS DWORD                                             ' char *
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' // Added an underscore because it conflicts with the function StrCat in shlwapi.inc
' ========================================================================================
DECLARE FUNCTION strcat_ CDECL IMPORT $CRT_DLLNAME ALIAS "strcat" ( _
   BYREF strDestination AS ASCIIZ _                     ' __in char *strDestination
 , BYREF strSource AS ASCIIZ _                          ' __in const char *strSource
 ) AS DWORD                                             ' char *
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_wat_ _CRTIMP_ALTERNATIVE errno_t __cdecl strcat_s(
' _Inout_z_cap_(_SizeInBytes) char * _Dst, _In_ rsize_t _SizeInBytes, _In_z_ const char * _Src);
' ========================================================================================
DECLARE FUNCTION strcat_s CDECL IMPORT $CRT_DLLNAME ALIAS "strcat_s" ( _
   BYREF strDestination AS ASCIIZ _                     ' __inout char *strDestination
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , BYREF strSource AS ASCIIZ _                          ' __in const char *strSource
 ) AS DWORD                                             ' char *
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' _Check_return_ int __cdecl strcmp(_In_z_ const char * _Str1, _In_z_ const char * _Str2);
' // Added an underscore because it conflicts with the function StrCmp in shlwapi.inc
' ========================================================================================
DECLARE FUNCTION strcmp_ CDECL IMPORT $CRT_DLLNAME ALIAS "strcmp" ( _
   BYREF string1 AS ASCIIZ _                            ' __in const char *string1
 , BYREF string2 AS ASCIIZ _                            ' __in const char *string2
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ size_t  __cdecl strlen(_In_z_ const char * _Str);
' ========================================================================================
DECLARE FUNCTION strlen CDECL IMPORT $CRT_DLLNAME ALIAS "strlen" ( _
   BYREF string AS ASCIIZ _                             ' __in const char *string
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP size_t  __cdecl strnlen(_In_z_ const char * _Str, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION strnlen CDECL IMPORT $CRT_DLLNAME ALIAS "strnlen" ( _
   BYREF string AS ASCIIZ _                             ' __in const char *str,
 , BYVAL numberOfElements  AS DWORD _                   ' __in size_t numberOfElements
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
'#if __STDC_WANT_SECURE_LIB__ && !defined (__midl)
'_Check_return_ static __inline size_t  __CRTDECL strnlen_s(_In_z_  const char * _Str, _In_ size_t _MaxCount)
'{
'    return (_Str==0) ? 0 : strnlen(_Str, _MaxCount);
'}
'#endif
' ========================================================================================
FUNCTION strnlen_s CDECL ( _
   BYREF string_ AS ASCIIZ _                            ' __in const char *str
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 ) AS DWORD                                             ' size_t

   IF VARPTR(string_) THEN FUNCTION = strnlen(string_, numberOfElements)

END FUNCTION
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP _CRT_INSECURE_DEPRECATE_MEMORY(memmove_s)
' void *  __cdecl memmove(_Out_opt_bytecapcount_(_Size) void * _Dst, _In_opt_bytecount_(_Size) const void * _Src, _In_ size_t _Size);
' ========================================================================================
DECLARE FUNCTION memmove CDECL IMPORT $CRT_DLLNAME ALIAS "memmove" ( _
   BYREF dest AS ANY _                                  ' __out void *dest
 , BYREF src AS ANY _                                   ' __in const void *src
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS DWORD                                             ' void *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' *** From wchar.h ***
' ========================================================================================
FUNCTION wmemmove CDECL ( _
   BYREF dest AS WSTRINGZ _                             ' __out wchar_t *dest
 , BYREF src AS WSTRINGZ _                              ' __in const wchar_t *src
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS DWORD                                             ' void *

   FUNCTION = memmove(dest, src, count * 2)

END FUNCTION
' ========================================================================================

' ========================================================================================
' *** From wchar.h ***
' _CRTIMP errno_t __cdecl memmove_s(_Out_opt_bytecap_post_bytecount_(_DstSize, _MaxCount)
' void * _Dst, _In_ rsize_t _DstSize, _In_opt_bytecount_(_MaxCount) const void * _Src, _In_ rsize_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION memmove_s CDECL IMPORT $CRT_DLLNAME ALIAS "memmove_s" ( _
   BYREF dest AS ANY _                                  ' void *dest
 , BYVAL numberOfElements AS DWORD _                    ' size_t numberOfElements
 , BYREF src AS ANY _                                   ' const void *src
 , BYVAL count AS DWORD _                               ' size_t count
 ) AS DWORD                                             ' void *
' ========================================================================================

' ========================================================================================
' *** From wchar.h ***
' ========================================================================================
FUNCTION wmemmove_s CDECL ( _
   BYREF dest AS WSTRINGZ _                             ' __out wchar_t *dest
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , BYREF src AS WSTRINGZ _                              ' __in const wchar_t *src
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS DWORD                                             ' void *

   FUNCTION = memmove_s(dest, numberOfElements * 2, src, count * 2)

END FUNCTION
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP char *  __cdecl _strdup(_In_opt_z_ const char * _Src);
' ========================================================================================
DECLARE FUNCTION strdup_ CDECL IMPORT $CRT_DLLNAME ALIAS "_strdup" ( _
   BYREF strSource AS ASCIIZ _                          ' __in const char *strSource
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP _CONST_RETURN char *  __cdecl strchr(_In_z_ const char * _Str, _In_ int _Val);
' // Added an underscore because it conflicts with the function StrChr in shlwapi.inc
' ========================================================================================
DECLARE FUNCTION strchr_ CDECL IMPORT $CRT_DLLNAME ALIAS "strchr" ( _
   BYREF string AS ASCIIZ _                             ' __in const char *string
 , BYVAL c AS LONG _                                    ' __in int c
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_NONSTDC_DEPRECATE(_strcmpi) _CRTIMP int __cdecl strcmpi(
' _In_z_ const char * _Str1, _In_z_ const char * _Str2);
' ========================================================================================
DECLARE FUNCTION strcmpi_ CDECL IMPORT $CRT_DLLNAME ALIAS "_strcmpi" ( _
   BYREF string1 AS ASCIIZ _                            ' __in const char *string1
 , BYREF string2 AS ASCIIZ _                            ' __in const char *string2
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_NONSTDC_DEPRECATE(_stricmp) _CRTIMP int __cdecl stricmp(
' _In_z_ const char * _Str1, _In_z_ const char * _Str2);
' ========================================================================================
DECLARE FUNCTION stricmp_ CDECL IMPORT $CRT_DLLNAME ALIAS "_stricmp" ( _
   BYREF string1 AS ASCIIZ _                            ' __in const char *string1
 , BYREF string2 AS ASCIIZ _                            ' __in const char *string2
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _stricmp_l(_In_z_  const char * _Str1,
' _In_z_  const char * _Str2, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION stricmp_l CDECL IMPORT $CRT_DLLNAME ALIAS "_stricmp_l" ( _
   BYREF string1 AS ASCIIZ _                            ' __in const char *string1
 , BYREF string2 AS ASCIIZ _                            ' __in const char *string2
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl strcoll(_In_z_  const char * _Str1, _In_z_  const  char * _Str2);
' ========================================================================================
DECLARE FUNCTION strcoll CDECL IMPORT $CRT_DLLNAME ALIAS "strcoll" ( _
   BYREF string1 AS ASCIIZ _                            ' __in const char *string1
 , BYREF string2 AS ASCIIZ _                            ' __in const char *string2
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int     __cdecl _strcoll_l(_In_z_  const char * _Str1,
' _In_z_  const char * _Str2, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION strcoll_l CDECL IMPORT $CRT_DLLNAME ALIAS "_strcoll_l" ( _
   BYREF string1 AS ASCIIZ _                            ' __in const char *string1
 , BYREF string2 AS ASCIIZ _                            ' __in const char *string2
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int     __cdecl _stricoll(_In_z_  const char * _Str1, _In_z_  const char * _Str2);
' ========================================================================================
DECLARE FUNCTION stricoll_ CDECL IMPORT $CRT_DLLNAME ALIAS "_stricoll" ( _
   BYREF string1 AS ASCIIZ _                            ' __in const char *string1
 , BYREF string2 AS ASCIIZ _                            ' __in const char *string2
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int     __cdecl _stricoll_l(_In_z_  const char * _Str1,
' _In_z_  const char * _Str2, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION stricoll_l CDECL IMPORT $CRT_DLLNAME ALIAS "_stricoll_l" ( _
   BYREF string1 AS ASCIIZ _                            ' __in const char *string1
 , BYREF string2 AS ASCIIZ _                            ' __in const char *string2
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _strncoll  (_In_z_ const char * _Str1,
' _In_z_ const char * _Str2, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION strncoll_ CDECL IMPORT $CRT_DLLNAME ALIAS "_strncoll" ( _
   BYREF string1 AS ASCIIZ _                            ' __in const char *string1
 , BYREF string2 AS ASCIIZ _                            ' __in const char *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int     __cdecl _strncoll_l(_In_z_ const char * _Str1,
' _In_z_ const char * _Str2, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION strncoll_l CDECL IMPORT $CRT_DLLNAME ALIAS "_strncoll_l" ( _
   BYREF string1 AS ASCIIZ _                            ' __in const char *string1
 , BYREF string2 AS ASCIIZ _                            ' __in const char *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _strnicoll (_In_z_ const char * _Str1,
' _In_z_ const char * _Str2, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION strnicoll_ CDECL IMPORT $CRT_DLLNAME ALIAS "_strnicoll" ( _
   BYREF string1 AS ASCIIZ _                            ' __in const char *string1
 , BYREF string2 AS ASCIIZ _                            ' __in const char *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _strnicoll_l(_In_z_ const char * _Str1,
' _In_z_ const char * _Str2, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION strnicoll_l CDECL IMPORT $CRT_DLLNAME ALIAS "_strnicoll_l" ( _
   BYREF string1 AS ASCIIZ _                            ' __in const char *string1
 , BYREF string2 AS ASCIIZ _                            ' __in const char *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP size_t  __cdecl strcspn(_In_z_  const char * _Str, _In_z_  const char * _Control);
' // Added an underscore because it conflicts with the function StrChr in shlwapi.inc
' ========================================================================================
DECLARE FUNCTION strcspn_ CDECL IMPORT $CRT_DLLNAME ALIAS "strcspn" ( _
   BYREF string1 AS ASCIIZ _                            ' __in const char *string1
 , BYREF string2 AS ASCIIZ _                            ' __in const char *string2
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_INSECURE_DEPRECATE(_strerror_s) _CRTIMP char *  __cdecl _strerror(_In_opt_z_ const char * _ErrMsg);
' ========================================================================================
DECLARE FUNCTION strerror_ CDECL IMPORT $CRT_DLLNAME ALIAS "_strerror" ( _
   BYREF strErrMsg AS ASCIIZ _                          ' __in const char *strErrMsg
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _strerror_s(_Out_z_cap_(_SizeInBytes) char * _Buf,
' _In_ size_t _SizeInBytes, _In_opt_z_ const char * _ErrMsg);
' ========================================================================================
DECLARE FUNCTION strerror_s_ CDECL IMPORT $CRT_DLLNAME ALIAS "_strerror_s" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , BYREF strErrMsg AS ASCIIZ _                          ' __in const char *strErrMsg
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_INSECURE_DEPRECATE(strerror_s) _CRTIMP char *  __cdecl strerror(_In_ int);
' ========================================================================================
DECLARE FUNCTION strerror CDECL IMPORT $CRT_DLLNAME ALIAS "strerror" ( _
   BYVAL errnum AS LONG _                               ' int errnum
 ) AS DWORD                                             ' char *
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl strerror_s(_Out_z_cap_(_SizeInBytes) char * _Buf,
' _In_ size_t _SizeInBytes, _In_ int _ErrNum);
' ========================================================================================
DECLARE FUNCTION strerror_s CDECL IMPORT $CRT_DLLNAME ALIAS "strerror_s" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , BYVAL errnum AS LONG _                               ' __in int errnum
 ) AS DWORD                                             ' char *
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' _CRT_NONSTDC_DEPRECATE(_strlwr) _CRTIMP char * __cdecl strlwr(_Inout_z_ char * _Str);
' ========================================================================================
DECLARE FUNCTION strlwr_ CDECL IMPORT $CRT_DLLNAME ALIAS "_strlwr" ( _
   BYREF str AS ASCIIZ _                                ' char *str
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _strlwr_s(_Inout_z_cap_(_Size) char * _Str, _In_ size_t _Size);
' ========================================================================================
DECLARE FUNCTION strlwr_s CDECL IMPORT $CRT_DLLNAME ALIAS "_strlwr_s" ( _
   BYREF str AS ASCIIZ _                                ' __inout char *str
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _strlwr_s_l(_Inout_z_cap_(_Size) char * _Str,
' _In_ size_t _Size, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION strlwr_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_strlwr_s_l" ( _
   BYREF str AS ASCIIZ _                                ' __inout char *str
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' // Added an underscore because it conflicts with the function StrCpy in shlwapi.inc
' ========================================================================================
DECLARE FUNCTION strncat_ CDECL IMPORT $CRT_DLLNAME ALIAS "strncat" ( _
   BYREF strDest AS ASCIIZ _                            ' char *strDest
 , BYREF strSource AS ASCIIZ _                          ' const char *strSource
 , BYVAL count AS DWORD _                               ' size_t count
 ) AS DWORD                                             ' char *
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_wat_ _CRTIMP_ALTERNATIVE errno_t __cdecl strncat_s(_Inout_z_cap_(_SizeInBytes) char * _Dst,
' _In_ rsize_t _SizeInBytes, _In_z_ const char * _Src, _In_ rsize_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION strncat_s CDECL IMPORT $CRT_DLLNAME ALIAS "strncat_s" ( _
   BYREF strDest AS ASCIIZ _                            ' __inout char *strDest
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , BYREF strSource AS ASCIIZ _                          ' __in const char *strSource
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' errno_t
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl strncmp(_In_z_ const char * _Str1,
' _In_z_ const char * _Str2, _In_ size_t _MaxCount);
' ========================================================================================
' // Added an underscore because it conflicts with the function StrCmpN in shlwapi.inc
DECLARE FUNCTION strncmp_ CDECL IMPORT $CRT_DLLNAME ALIAS "strncmp" ( _
   BYREF string1 AS ASCIIZ _                            ' __in const char *string1
 , BYREF string2 AS ASCIIZ _                            ' __in const char *string2
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int     __cdecl _strnicmp(_In_z_ const char * _Str1,
' _In_z_ const char * _Str2, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION strnicmp_ CDECL IMPORT $CRT_DLLNAME ALIAS "_strnicmp" ( _
   BYREF string1 AS ASCIIZ _                            ' __in const char *string1
 , BYREF string2 AS ASCIIZ _                            ' __in const char *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _strnicmp_l(_In_z_ const char * _Str1,
' _In_z_ const char * _Str2, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION strnicmp_l CDECL IMPORT $CRT_DLLNAME ALIAS "_strnicmp_l" ( _
   BYREF string1 AS ASCIIZ _                            ' __in const char *string1
 , BYREF string2 AS ASCIIZ _                            ' __in const char *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' // Added an underscore because it conflicts with the function StrNCpy in shlwapi.inc
' ========================================================================================
DECLARE FUNCTION strncpy_ CDECL IMPORT $CRT_DLLNAME ALIAS "strncpy" ( _
   BYREF strDest AS ASCIIZ _                            ' char *strDest
 , BYREF strSource AS ASCIIZ _                          ' const char *strSource
 , BYVAL count AS DWORD _                               ' size_t count
 ) AS DWORD                                             ' char *
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_wat_ _CRTIMP_ALTERNATIVE errno_t __cdecl strncpy_s(
' _Out_z_cap_(_SizeInBytes) char * _Dst, _In_ rsize_t _SizeInBytes, _In_z_ const char * _Src, _In_ rsize_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION strncpy_s CDECL IMPORT $CRT_DLLNAME ALIAS "strncpy_s" ( _
   BYREF strDest AS ASCIIZ _                            ' __out char *strDest
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , BYREF strSource AS ASCIIZ _                          ' __in const char *strSource
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' errno_t
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' _CRT_NONSTDC_DEPRECATE(_strnset) _CRTIMP char * __cdecl strnset(
' _Inout_z_cap_(_MaxCount) char * _Str, _In_ int _Val, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION strnset_ CDECL IMPORT $CRT_DLLNAME ALIAS "_strnset" ( _
   BYREF string AS ASCIIZ _                             ' char *string
 , BYVAL c AS LONG _                                    ' int c
 , BYVAL count AS DWORD _                               ' size_t count
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP_ALTERNATIVE errno_t __cdecl _strnset_s(
'_Inout_z_cap_(_SizeInBytes) char * _Str, _In_ size_t _SizeInBytes, _In_ int _Val, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION strnset_s CDECL IMPORT $CRT_DLLNAME ALIAS "_strnset_s" ( _
   BYREF string AS ASCIIZ _                             ' __inout char *string
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , BYVAL c AS LONG _                                    ' __in int c
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP _CONST_RETURN char *  __cdecl strpbrk(_In_z_ const char * _Str, _In_z_ const char * _Control);
' // Added an underscore because it conflicts with the function StrPBrk in shlwapi.inc
' ========================================================================================
DECLARE FUNCTION strpbrk_ CDECL IMPORT $CRT_DLLNAME ALIAS "strpbrk" ( _
   BYREF string1 AS ASCIIZ _                            ' __in const char *string1
 , BYREF string2 AS ASCIIZ _                            ' __in const char *string2
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP _CONST_RETURN char *  __cdecl strrchr(_In_z_ const char * _Str, _In_ int _Ch);
' // Added an underscore because it conflicts with the function StrRChr in shlwapi.inc
' ========================================================================================
DECLARE FUNCTION strrchr_ CDECL IMPORT $CRT_DLLNAME ALIAS "strrchr" ( _
   BYREF string AS ASCIIZ _                             ' __in const char *string
 , BYVAL c AS LONG _                                    ' __in int c
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRT_NONSTDC_DEPRECATE(_strrev) _CRTIMP char * __cdecl strrev(_Inout_z_ char * _Str);
' ========================================================================================
DECLARE FUNCTION strrev_ CDECL IMPORT $CRT_DLLNAME ALIAS "_strrev" ( _
   BYREF string AS ASCIIZ _                             ' __inout char *string
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP size_t  __cdecl strspn(_In_z_ const char * _Str, _In_z_ const char * _Control);
' // Added an underscore because it conflicts with the function StrSpn in shlwapi.inc
' ========================================================================================
DECLARE FUNCTION strspn_ CDECL IMPORT $CRT_DLLNAME ALIAS "strspn" ( _
   BYREF string AS ASCIIZ _                             ' __in const char *string
 , BYREF strCharSet AS ASCIIZ _                         ' __in const char *strCharSet
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP _CONST_RETURN char *  __cdecl strstr(_In_z_ const char * _Str,
' _In_z_ const char * _SubStr);
' // Added an underscore because it conflicts with the function StrStr in shlwapi.inc
' ========================================================================================
DECLARE FUNCTION strstr_ CDECL IMPORT $CRT_DLLNAME ALIAS "strstr" ( _
   BYREF string AS ASCIIZ _                             ' __in const char *string
 , BYREF strSearch AS ASCIIZ _                          ' __in const char *strSearch
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_INSECURE_DEPRECATE(strtok_s) _CRTIMP char * __cdecl strtok(
' _Inout_opt_z_ char * _Str, _In_z_ const char * _Delim);
' ========================================================================================
DECLARE FUNCTION strtok CDECL IMPORT $CRT_DLLNAME ALIAS "strtok" ( _
   BYREF strToken AS ASCIIZ _                           ' __in char *strToken
 , BYREF strDelimit AS ASCIIZ _                         ' __in const char *strDelimit
 ) AS DWORD                                             ' char *
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_ _CRTIMP_ALTERNATIVE char *  __cdecl strtok_s(_Inout_opt_z_ char * _Str,
' _In_z_ const char * _Delim, _Inout_ _Deref_prepost_opt_z_ char ** _Context);
' ========================================================================================
DECLARE FUNCTION strtok_s CDECL IMPORT $CRT_DLLNAME ALIAS "strtok_s" ( _
   BYREF strToken AS ASCIIZ _                           ' __inout char *strToken
 , BYREF strDelimit AS ASCIIZ _                         ' __in const char *strDelimit
 , BYREF context AS DWORD _                             ' __inout char **context
 ) AS DWORD                                             ' char *
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION strupr_ CDECL IMPORT $CRT_DLLNAME ALIAS "_strupr" ( _
   BYREF string AS ASCIIZ _                             ' char *string
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _strupr_s(_Inout_z_cap_(_Size) char * _Str, _In_ size_t _Size);
' ========================================================================================
DECLARE FUNCTION strupr_s CDECL IMPORT $CRT_DLLNAME ALIAS "_strupr_s" ( _
   BYREF string AS ASCIIZ _                             ' __inout char *string
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _strupr_s_l(_Inout_z_cap_(_Size) char * _Str,
' _In_ size_t _Size, _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION strupr_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_strupr_s_l" ( _
   BYREF string AS ASCIIZ _                             ' __inout char *string
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP size_t  __cdecl strxfrm (
' _Out_opt_cap_(_MaxCount) _Post_maybez_ char * _Dst, _In_z_ const char * _Src, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION strxfrm CDECL IMPORT "msvcrt.dll" ALIAS "strxfrm" ( _
   BYREF strDest AS ASCIIZ _                            ' __out char *strDest
 , BYREF strSource AS ASCIIZ _                          ' __in const char *strSource
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP size_t  __cdecl strxfrm (
' _Out_opt_cap_(_MaxCount) _Post_maybez_ char * _Dst, _In_z_ const char * _Src, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION strxfrm CDECL IMPORT $CRT_DLLNAME ALIAS "strxfrm" ( _
   BYREF strDest AS ASCIIZ _                            ' __out char *strDest
 , BYREF strSource AS ASCIIZ _                          ' __in const char *strSource
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP size_t  __cdecl _strxfrm_l(_Out_opt_cap_(_MaxCount) _Post_maybez_ char * _Dst,
' _In_z_ const char * _Src, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION strxfrm_l CDECL IMPORT $CRT_DLLNAME ALIAS "_strxfrm_l" ( _
   BYREF strDest AS ASCIIZ _                            ' __out char *strDest
 , BYREF strSource AS ASCIIZ _                          ' __in const char *strSource
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' size_t
' ========================================================================================

'/* wide function prototypes, also declared in wchar.h  */

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP wchar_t * __cdecl _wcsdup(_In_z_ const wchar_t * _Str);
' ========================================================================================
DECLARE FUNCTION wcsdup_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wcsdup" ( _
   BYREF strSource AS WSTRINGZ _                        ' __in const wchar_t *strSource
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION wcscat CDECL IMPORT $CRT_DLLNAME ALIAS "wcscat" ( _
   BYREF strDestination AS WSTRINGZ _                   ' wchar_t *strDestination
 , BYREF strSource AS WSTRINGZ _                           ' const wchar_t *strSource
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_wat_ _CRTIMP_ALTERNATIVE errno_t __cdecl wcscat_s(
' _Inout_z_cap_(_SizeInWords) wchar_t * _Dst, _In_ rsize_t _SizeInWords, _In_z_ const wchar_t * _Src);
' ========================================================================================
DECLARE FUNCTION wcscat_s CDECL IMPORT $CRT_DLLNAME ALIAS "wcscat_s" ( _
   BYREF strDestination AS WSTRINGZ _                   ' __inout wchar_t *strDestination
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , BYREF strSource AS WSTRINGZ _                        ' __in const wchar_t *strSource
 ) AS LONG                                              ' errno_t
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP _CONST_RETURN wchar_t * __cdecl wcschr(
' _In_z_ const wchar_t * _Str, wchar_t _Ch);
' ========================================================================================
DECLARE FUNCTION wcschr CDECL IMPORT $CRT_DLLNAME ALIAS "wcschr" ( _
   BYREF string AS WSTRINGZ _                           ' __in const wchar_t *string
 , BYVAL c AS LONG _                                    ' __in int c
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl wcscmp(_In_z_ const wchar_t * _Str1,
' _In_z_ const wchar_t * _Str2);
' ========================================================================================
DECLARE FUNCTION wcscmp CDECL IMPORT $CRT_DLLNAME ALIAS "wcscmp" ( _
   BYREF string1 AS WSTRINGZ _                          ' __in const wchar_t *string1
 , BYREF string2 AS WSTRINGZ _                          ' __in const wchar_t *string2
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION wcscpy CDECL IMPORT $CRT_DLLNAME ALIAS "wcscpy" ( _
   BYREF strDestination AS WSTRINGZ _                   ' wchar_t *strDestination
 , BYREF strSource AS WSTRINGZ _                        ' const wchar_t *strSource
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_wat_ _CRTIMP_ALTERNATIVE errno_t __cdecl wcscpy_s(
' _Out_z_cap_(_SizeInWords) wchar_t * _Dst, _In_ rsize_t _SizeInWords, _In_z_ const wchar_t * _Src);
' ========================================================================================
DECLARE FUNCTION wcscpy_s CDECL IMPORT $CRT_DLLNAME ALIAS "wcscpy_s" ( _
   BYREF strDestination AS WSTRINGZ _                   ' __out wchar_t *strDestination
 , BYREF strSource AS WSTRINGZ _                        ' __in const wchar_t *strSource
 ) AS LONG                                              ' errno_t
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP size_t __cdecl wcscspn(_In_z_ const wchar_t * _Str,
' _In_z_ const wchar_t * _Control);
' ========================================================================================
DECLARE FUNCTION wcscspn CDECL IMPORT $CRT_DLLNAME ALIAS "wcscspn" ( _
   BYREF string AS WSTRINGZ _                           ' __in const wchar_t *string
 , BYREF strCharSet AS WSTRINGZ _                       ' __in const wchar_t *strCharSet
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION wcslen CDECL IMPORT $CRT_DLLNAME ALIAS "wcslen" ( _
   BYREF string AS WSTRINGZ _                           ' __in const wchar_t *string
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP size_t __cdecl wcsnlen(_In_z_ const wchar_t * _Src, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION wcsnlen CDECL IMPORT $CRT_DLLNAME ALIAS "wcsnlen" ( _
   BYREF string AS WSTRINGZ _                           ' __in const wchar_t *string
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
'#if __STDC_WANT_SECURE_LIB__ && !defined (__midl)
'_Check_return_ static __inline size_t __CRTDECL wcsnlen_s(_In_z_ const wchar_t * _Src, _In_ size_t _MaxCount)
'{
'    return (_Src == NULL) ? 0 : wcsnlen(_Src, _MaxCount);
'}
'#endif
' ========================================================================================
FUNCTION wcsnlen_s CDECL ( _
   BYREF string_ AS WSTRINGZ _                          ' __in const wchar_t *string
 , BYREF numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 ) AS DWORD                                             ' size_t

   IF VARPTR(string_) = 0 THEN FUNCTION = wcsnlen(string_, numberOfElements)

END FUNCTION
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION wcsncat CDECL IMPORT $CRT_DLLNAME ALIAS "wcsncat" ( _
   BYREF strDest AS WSTRINGZ _                          ' wchar_t *strDest
 , BYREF strSource AS WSTRINGZ _                        ' const wchar_t *strSource
 , BYVAL count AS DWORD _                               ' size_t count
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_wat_ _CRTIMP_ALTERNATIVE errno_t __cdecl wcsncat_s(
' _Inout_z_cap_(_SizeInWords) wchar_t * _Dst, _In_ rsize_t _SizeInWords,
' _In_z_ const wchar_t * _Src, _In_ rsize_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION wcsncat_s CDECL IMPORT $CRT_DLLNAME ALIAS "wcsncat_s" ( _
   BYREF strDest AS WSTRINGZ _                          ' __inout wchar_t *strDest
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , BYREF strSource AS WSTRINGZ _                        ' __in const wchar_t *strSource
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl wcsncmp(_In_z_ const wchar_t * _Str1,
' _In_z_ const wchar_t * _Str2, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION wcsncmp CDECL IMPORT $CRT_DLLNAME ALIAS "wcsncmp" ( _
   BYREF string1 AS WSTRINGZ _                          ' __in const wchar_t *string1
 , BYREF string2 AS WSTRINGZ _                          ' __in const wchar_t *string2
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION wcsncpy CDECL IMPORT $CRT_DLLNAME ALIAS "wcsncpy" ( _
   BYREF strDest AS WSTRINGZ _                          ' wchar_t *strDest
 , BYREF strSource AS WSTRINGZ _                        ' const wchar_t *strSource
 , BYVAL count AS DWORD _                               ' size_t count
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_wat_ _CRTIMP_ALTERNATIVE errno_t __cdecl wcsncpy_s(
' _Out_z_cap_(_SizeInWords) wchar_t * _Dst, _In_ rsize_t _SizeInWords,
' _In_z_ const wchar_t * _Src, _In_ rsize_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION wcsncpy_s CDECL IMPORT $CRT_DLLNAME ALIAS "wcsncpy_s" ( _
   BYREF strDest AS WSTRINGZ _                          ' __out wchar_t *strDest
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , BYREF strSource AS WSTRINGZ _                        ' __in const wchar_t *strSource
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' errno_t
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP _CONST_RETURN wchar_t * __cdecl wcspbrk(
' _In_z_ const wchar_t * _Str, _In_z_ const wchar_t * _Control);
' ========================================================================================
DECLARE FUNCTION wcspbrk CDECL IMPORT $CRT_DLLNAME ALIAS "wcspbrk" ( _
   BYREF string1 AS WSTRINGZ _                          ' __in const wchar_t *string1
 , BYREF string2 AS WSTRINGZ _                          ' __in const wchar_t *string2
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP _CONST_RETURN wchar_t * __cdecl wcsrchr(
' _In_z_ const wchar_t * _Str, _In_ wchar_t _Ch);
' ========================================================================================
DECLARE FUNCTION wcsrchr CDECL IMPORT $CRT_DLLNAME ALIAS "wcsrchr" ( _
   BYREF string AS WSTRINGZ _                           ' __in const wchar_t *string
 , BYVAL c AS WORD _                                    ' __in wchar_t c
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP size_t __cdecl wcsspn(_In_z_ const wchar_t * _Str,
' _In_z_ const wchar_t * _Control);
' ========================================================================================
DECLARE FUNCTION wcsspn CDECL IMPORT $CRT_DLLNAME ALIAS "wcsspn" ( _
   BYREF string AS WSTRINGZ _                           ' __in const wchar_t *string
 , BYREF strCharSet AS WSTRINGZ _                       ' __in const wchar_t *strCharSet
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP _CONST_RETURN wchar_t * __cdecl wcsstr(
' _In_z_ const wchar_t * _Str, _In_z_ const wchar_t * _SubStr);
' ========================================================================================
DECLARE FUNCTION wcsstr CDECL IMPORT $CRT_DLLNAME ALIAS "wcsstr" ( _
   BYREF string AS WSTRINGZ _                           ' __in const wchar_t *string
 , BYREF strSearch AS WSTRINGZ _                        ' __in const wchar_t *strSearch
 ) AS DWORD                                             ' wchar_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_INSECURE_DEPRECATE(wcstok_s) _CRTIMP wchar_t * __cdecl wcstok(
' _Inout_opt_z_ wchar_t * _Str, _In_z_ const wchar_t * _Delim);
' ========================================================================================
DECLARE FUNCTION wcstok CDECL IMPORT $CRT_DLLNAME ALIAS "wcstok" ( _
   BYREF strToken AS WSTRINGZ _                         ' __inout wchar_t *strToken
 , BYREF strDelimit AS WSTRINGZ _                       ' __in const wchar_t *strDelimit
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_ _CRTIMP_ALTERNATIVE wchar_t * __cdecl wcstok_s(
' _Inout_opt_z_ wchar_t * _Str, _In_z_ const wchar_t * _Delim, _Inout_ _Deref_prepost_opt_z_ wchar_t ** _Context);
' ========================================================================================
DECLARE FUNCTION wcstok_s CDECL IMPORT $CRT_DLLNAME ALIAS "wcstok_s" ( _
   BYREF strToken AS WSTRINGZ _                         ' __inout wchar_t *strToken
 , BYREF strDelimit AS WSTRINGZ _                       ' __in const wchar_t *strDelimit
 , BYREF context AS DWORD _                             ' __inout wchar_t **context
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================
'#endif

' ========================================================================================
' _Check_return_ _CRT_INSECURE_DEPRECATE(_wcserror_s) _CRTIMP wchar_t * __cdecl _wcserror(_In_ int _ErrNum);
' ========================================================================================
DECLARE FUNCTION wcserror_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wcserror" ( _
   BYVAL errnum AS LONG _                               ' __in int errnum
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _wcserror_s(
' _Out_opt_z_cap_(_SizeInWords) wchar_t * _Buf, _In_ size_t _SizeInWords, _In_ int _ErrNum);
' ========================================================================================
DECLARE FUNCTION wcserror_s CDECL IMPORT $CRT_DLLNAME ALIAS "_wcserror_s" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , BYVAL errnum AS LONG _                               ' __in int errnum
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl __wcserror_s(
' _Out_opt_z_cap_(_SizeInWords) wchar_t * _Buffer, _In_ size_t _SizeInWords, _In_z_ const wchar_t * _ErrMsg);
' ========================================================================================
DECLARE FUNCTION wcserror__s CDECL IMPORT $CRT_DLLNAME ALIAS "__wcserror_s" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , BYREF strErrMsg AS WSTRINGZ _                        ' __in const wchar_t *strErrMsg
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _wcsicmp(_In_z_ const wchar_t * _Str1,
' _In_z_ const wchar_t * _Str2);
' ========================================================================================
DECLARE FUNCTION wcsicmp_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wcsicmp" ( _
   BYREF string1 AS WSTRINGZ _                          ' __in const wchar_t *string1
 , BYREF string2 AS WSTRINGZ _                          ' __in const wchar_t *string2
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _wcsicmp_l(_In_z_ const wchar_t * _Str1,
' _In_z_ const wchar_t * _Str2, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION wcsicmp_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wcsicmp_l" ( _
   BYREF string1 AS WSTRINGZ _                          ' __in const wchar_t *string1
 , BYREF string2 AS WSTRINGZ _                          ' __in const wchar_t *string2
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _wcsnicmp(_In_z_ const wchar_t * _Str1,
' _In_z_ const wchar_t * _Str2, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION wcsnicmp_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wcsnicmp" ( _
   BYREF string1 AS WSTRINGZ _                          ' __in const wchar_t *string1
 , BYREF string2 AS WSTRINGZ _                          ' __in const wchar_t *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _wcsnicmp_l(_In_z_ const wchar_t * _Str1,
' _In_z_ const wchar_t * _Str2, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION wcsnicmp_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wcsnicmp_l" ( _
   BYREF string1 AS WSTRINGZ _                          ' __in const wchar_t *string1
 , BYREF string2 AS WSTRINGZ _                          ' __in const wchar_t *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION wcsnset_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wcsnset" ( _
   BYREF string AS WSTRINGZ _                           ' wchar_t *string
 , BYVAL c AS WORD _                                    ' wchar_t c
 , BYVAL count AS DWORD _                               ' size_t count
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP_ALTERNATIVE errno_t __cdecl _wcsnset_s(
' _Inout_z_cap_(_SizeInWords) wchar_t * _Dst, _In_ size_t _SizeInWords, _In_ wchar_t _Val, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION wcsnset_s CDECL IMPORT $CRT_DLLNAME ALIAS "_wcsnset_s" ( _
   BYREF string AS WSTRINGZ _                           ' inout_ wchar_t *string
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , BYVAL c AS WORD _                                    ' __in wchar_t c
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRTIMP wchar_t * __cdecl _wcsrev(_Inout_z_ wchar_t * _Str);
' ========================================================================================
DECLARE FUNCTION wcsrev_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wcsrev" ( _
   BYREF string AS WSTRINGZ _                           ' __inout wchar_t *string
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
DECLARE FUNCTION wcsset_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wcsset" ( _
   BYREF string AS WSTRINGZ _                           ' wchar_t *string
 , BYVAL c AS WORD _                                    ' wchar_t c
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP_ALTERNATIVE errno_t __cdecl _wcsset_s(
' _Inout_z_cap_(_SizeInWords) wchar_t * _Dst, _In_ size_t _SizeInWords, _In_ wchar_t _Value);
' ========================================================================================
DECLARE FUNCTION wcsset_s CDECL IMPORT $CRT_DLLNAME ALIAS "_wcsset_s" ( _
   BYREF string AS WSTRINGZ _                           ' __inout wchar_t *string
 , BYVAL numberOfElement AS DWORD _                     ' __in size_t numberOfElement
 , BYVAL c AS WORD _                                    ' __in wchar_t c
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION wcslwr_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wcslwr" ( _
   BYREF str AS WSTRINGZ _                              ' wchar_t *str
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _wcslwr_s(
' _Inout_z_cap_(_SizeInWords) wchar_t * _Str, _In_ size_t _SizeInWords);
' ========================================================================================
DECLARE FUNCTION wcslwr_s CDECL IMPORT $CRT_DLLNAME ALIAS "_wcslwr_s" ( _
   BYREF str AS WSTRINGZ _                              ' __inout wchar_t *str
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _wcslwr_s_l(
'_Inout_z_cap_(_SizeInWords) wchar_t * _Str, _In_ size_t _SizeInWords, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION wcslwr_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wcslwr_s_l" ( _
   BYREF str AS WSTRINGZ _                              ' __inout wchar_t *str
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION wcsupr_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wcsupr" ( _
   BYREF string AS WSTRINGZ _                           ' wchar_t *string
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _wcsupr_s(
' _Inout_z_cap_(_Size) wchar_t * _Str, _In_ size_t _Size);
' ========================================================================================
DECLARE FUNCTION wcsupr_s CDECL IMPORT $CRT_DLLNAME ALIAS "_wcsupr_s" ( _
   BYREF string AS WSTRINGZ _                           ' __inout wchar_t *string
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _wcsupr_s_l(
' _Inout_z_cap_(_Size) wchar_t * _Str, _In_ size_t _Size, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION wcsupr_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wcsupr_s_l" ( _
   BYREF string AS WSTRINGZ _                           ' __inout wchar_t *string
 , BYVAL numberOfElements AS locale_t _                 ' __in size_t numberOfElements
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP size_t __cdecl wcsxfrm(_Out_opt_cap_(_MaxCount) _Post_maybez_
'  wchar_t * _Dst, _In_z_ const wchar_t * _Src, In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION wcsxfrm CDECL IMPORT $CRT_DLLNAME ALIAS "wcsxfrm" ( _
   BYREF strDest AS WSTRINGZ _                          ' __out wchar_t *strDest
 , BYREF strSource AS WSTRINGZ _                        ' __in const wchar_t *strSource
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP size_t __cdecl _wcsxfrm_l(_Out_opt_cap_(_MaxCount) _Post_maybez_
'  wchar_t * _Dst, _In_z_ const wchar_t *_Src, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION wcsxfrm_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wcsxfrm_l" ( _
   BYREF strDest AS WSTRINGZ _                          ' __out wchar_t *strDest
 , BYREF strSource AS WSTRINGZ _                        ' __in const wchar_t *strSource
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl wcscoll(_In_z_ const wchar_t * _Str1,
' _In_z_ const wchar_t * _Str2);
' ========================================================================================
DECLARE FUNCTION wcscoll CDECL IMPORT $CRT_DLLNAME ALIAS "wcscoll" ( _
   BYREF string1 AS WSTRINGZ _                          ' __in const wchar_t *string1
 , BYREF string2 AS WSTRINGZ _                          ' __in const wchar_t *string2
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _wcscoll_l(_In_z_ const wchar_t * _Str1,
' _In_z_ const wchar_t * _Str2, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION wcscoll_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wcscoll_l" ( _
   BYREF string1 AS WSTRINGZ _                          ' __in const wchar_t *string1
 , BYREF string2 AS WSTRINGZ _                          ' __in const wchar_t *string2
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _wcsicoll(_In_z_ const wchar_t * _Str1,
' _In_z_ const wchar_t * _Str2);
' ========================================================================================
DECLARE FUNCTION wcsicoll_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wcsicoll" ( _
   BYREF string1 AS WSTRINGZ _                          ' __in const wchar_t *string1
 , BYREF string2 AS WSTRINGZ _                          ' __in const wchar_t *string2
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _wcsicoll_l(_In_z_ const wchar_t * _Str1,
' _In_z_ const wchar_t *_Str2, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION wcsicoll_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wcsicoll_l" ( _
   BYREF string1 AS WSTRINGZ _                          ' __in const wchar_t *string1
 , BYREF string2 AS WSTRINGZ _                          ' __in const wchar_t *string2
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _wcsncoll(_In_z_ const wchar_t * _Str1,
' _In_z_ const wchar_t * _Str2, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION wcsncoll_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wcsncoll" ( _
   BYREF string1 AS WSTRINGZ _                          ' __in const wchar_t *string1
 , BYREF string2 AS WSTRINGZ _                          ' __in const wchar_t *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _wcsncoll_l(_In_z_ const wchar_t * _Str1,
' _In_z_ const wchar_t * _Str2, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION wcsncoll_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wcsncoll_l" ( _
   BYREF string1 AS WSTRINGZ _                          ' __in const wchar_t *string1
 , BYREF string2 AS WSTRINGZ _                          ' __in const wchar_t *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t local
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _wcsnicoll(_In_z_ const wchar_t * _Str1,
' _In_z_ const wchar_t * _Str2, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION wcsnicoll_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wcsnicoll" ( _
   BYREF string1 AS WSTRINGZ _                          ' __in const wchar_t *string1
 , BYREF string2 AS WSTRINGZ _                          ' __in const wchar_t *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _wcsnicoll_l(_In_z_ const wchar_t * _Str1,
' _In_z_ const wchar_t * _Str2, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION wcsnicoll_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wcsnicoll_l" ( _
   BYREF string1 AS WSTRINGZ _                          ' __in const wchar_t *string1
 , BYREF string2 AS WSTRINGZ _                          ' __in const wchar_t *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t local
 ) AS LONG                                              ' int
' ========================================================================================

' ########################################################################################
'                                *** WRAPPER FUNCTIONS ***
' ########################################################################################

' ========================================================================================
' Extracts the contents of a null-terminated ansi string, given its address.
' ========================================================================================
FUNCTION cs2str_ (BYVAL psz AS ASCIIZ PTR) AS STRING
   IF psz THEN FUNCTION = @psz
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts the contents of a null-terminated wide string, given its address, and returns
' it as a PB ansi string.
' ========================================================================================
FUNCTION wcs2str_ (BYVAL pwsz AS WSTRINGZ PTR) AS STRING
   LOCAL nLen AS LONG
   IF pwsz = 0 THEN EXIT FUNCTION
   nLen = wcslen(BYVAL pwsz)
   IF nLen THEN FUNCTION = ACODE$(PEEK$$(pwsz, nLen))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts the contents of a null-terminated wide string, given its address, and returns
' it as a PB wide string.
' ========================================================================================
FUNCTION wcs2bstr_ (BYVAL pwsz AS WSTRINGZ PTR) AS WSTRING
   LOCAL nLen AS LONG
   IF pwsz = 0 THEN EXIT FUNCTION
   nLen = wcslen(BYVAL pwsz)
   IF nLen THEN FUNCTION = PEEK$$(pwsz, nLen)
END FUNCTION
' ========================================================================================
