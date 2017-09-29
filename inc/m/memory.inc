' ########################################################################################
' Microsoft C Runtima
' File: memory.inc
' Contents: Dunction declarations for the buffer (memory) manipulation routines.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MEMORY_INC = 1

#INCLUDE ONCE "crtdefs.inc"

'/* For backwards compatibility */
'#define _WConst_return _CONST_RETURN

'/* Function prototypes */

#IF NOT %DEF(%CRT_MEMORY_DEFINED)
    %CRT_MEMORY_DEFINED = 1

' ========================================================================================
' *** All versions ***
' _CRTIMP void *  __cdecl _memccpy( _Out_opt_bytecap_(_MaxCount) void * _Dst,
' _In_ const void * _Src, _In_ int _Val, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION memccpy_ CDECL IMPORT $CRT_DLLNAME ALIAS "_memccpy" ( _
   BYREF dest AS ANY _                                  ' __out void *dest
 , BYREF src AS ANY _                                   ' __in const void *src
 , BYVAL c AS LONG _                                    ' __in int  c
 , BYVAL count AS DWORD _                               ' __in unsigned int count
 ) AS DWORD                                             ' void *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP _CONST_RETURN void *  __cdecl memchr(
' _In_opt_bytecount_(_MaxCount) const void * _Buf , _In_ int _Val, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION memchr CDECL IMPORT $CRT_DLLNAME ALIAS "memchr" ( _
   BYREF buf AS ANY _                                   ' __in const void *buf
 , BYVAL c AS LONG _                                    ' __in int  c
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS DWORD                                             ' void *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int     __cdecl _memicmp(_In_opt_bytecount_(_Size) const void * _Buf1,
' _In_opt_bytecount_(_Size) const void * _Buf2, _In_ size_t _Size);
' ========================================================================================
DECLARE FUNCTION memicmp_ CDECL IMPORT $CRT_DLLNAME ALIAS "_memicmp" ( _
   BYREF buf1 AS ANY _                                  ' __in const void *buf1
 , BYREF buf2 AS ANY _                                  ' __in const void *buf2
 , BYVAL count AS DWORD _                               ' __in unsigned int count
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int     __cdecl _memicmp_l(_In_opt_bytecount_(_Size) const void * _Buf1,
' _In_opt_bytecount_(_Size) const void * _Buf2, _In_ size_t _Size, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION memicmp_l CDECL IMPORT $CRT_DLLNAME ALIAS "_memicmp_l" ( _
   BYREF buf1 AS ANY _                                  ' __in const void *buf1
 , BYREF buf2 AS ANY _                                  ' __in const void *buf2
 , BYVAL count AS DWORD _                               ' __in unsigned int count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ int __cdecl memcmp(_In_opt_bytecount_(_Size) const void * _Buf1,
' _In_opt_bytecount_(_Size) const void * _Buf2, _In_ size_t _Size);
' ========================================================================================
DECLARE FUNCTION memcmp CDECL IMPORT $CRT_DLLNAME ALIAS "memcmp" ( _
   BYREF buf1 AS ANY _                                  ' __in const void *buf1
 , BYREF buf2 AS ANY _                                  ' __in const void *buf2
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRT_INSECURE_DEPRECATE_MEMORY(memcpy_s) void * __cdecl memcpy(
' _Out_opt_bytecapcount_(_Size) void * _Dst, _In_opt_bytecount_(_Size) const void * _Src, _In_ size_t _Size);
' ========================================================================================
DECLARE FUNCTION memcpy CDECL IMPORT $CRT_DLLNAME ALIAS "memcpy" ( _
   BYREF dest AS ANY _                                  ' __out void *dest
 , BYREF src AS ANY _                                   ' __in const void *src
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS DWORD                                             ' void *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
FUNCTION wmemcpy CDECL ( _
   BYREF dest AS WSTRINGZ _                             ' __out wchar_t *dest
 , BYREF src AS WSTRINGZ _                              ' __in const wchar_t *src
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' errno_t

   FUNCTION = memcpy(dest, src, count * 2)

END FUNCTION
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _CRTIMP errno_t  __cdecl memcpy_s(_Out_opt_bytecap_post_bytecount_(_DstSize,
' _MaxCount) void * _Dst, _In_ rsize_t _DstSize, _In_opt_bytecount_(_MaxCount) const void * _Src,
' _In_ rsize_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION memcpy_s CDECL IMPORT $CRT_DLLNAME ALIAS "memcpy_s" ( _
   BYREF dest AS ANY _                                  ' __out void *dest
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , BYREF src AS ANY _                                   ' __in const void *src
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' errno_t
' ========================================================================================
'#endif

' ========================================================================================
FUNCTION wmemcpy_s CDECL ( _
   BYREF dest AS WSTRINGZ _                             ' __out wchar_t *dest
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , BYREF src AS WSTRINGZ _                              ' __in const wchar_t *src
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' errno_t

   FUNCTION = memcpy_s(dest, numberOfElements * 2, src, count * 2)

END FUNCTION
' ========================================================================================

' ========================================================================================
' *** All versions ***
' void *  __cdecl memset(_Out_opt_bytecapcount_(_Size) void * _Dst, _In_ int _Val, _In_ size_t _Size);
' ========================================================================================
DECLARE FUNCTION memset CDECL IMPORT $CRT_DLLNAME ALIAS "memset" ( _
   BYREF dest AS ANY _                                  ' __out void *dest
 , BYVAL c AS LONG _                                    ' __in int c
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS DWORD                                             ' void *
' ========================================================================================

#ENDIF   ' CRT_MEMORY_DEFINED
