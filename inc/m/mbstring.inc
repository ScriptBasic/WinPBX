' ########################################################################################
' Microsoft C Runtime
' File: mbstring.inc
' Contents: Declarations for the MBCS string manipulation functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MBSTRING_INC = 1

#INCLUDE ONCE "crtdefs.inc"

#IF NOT %DEF(%FILE_DEFINED)
%FILE_DEFINED = 1
' // Size = 32 bytes
TYPE FILE DWORD
   ptr      AS ASCIIZ PTR   ' char *_ptr
   cnt      AS LONG         ' int   _cnt
   base     AS ASCIIZ PTR   ' char *_base
   flag     AS LONG         ' int   _flag
   file     AS LONG         ' int   _file
   charbuf  AS LONG         ' int   _charbuf
   bufsiz   AS LONG         ' int   _bufsiz
   tmpfname AS ASCIIZ PTR   ' char *_tmpfname
END TYPE
MACRO iobuf = FILE
#ENDIF

#IF NOT %DEF(%MBSTRING_DEFINED)
    %MBSTRING_DEFINED = 1

'/* function prototypes */

' Not exported
' _Check_return_ _CRTIMP unsigned char * __cdecl _mbsdup(_In_z_ const unsigned char * _Str);

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP unsigned int __cdecl _mbbtombc(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION mbbtombc_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbbtombc" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS DWORD                                             ' unsigned int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP unsigned int __cdecl _mbbtombc_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbbtombc_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbbtombc_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' unsigned int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _mbbtype(_In_ unsigned char _Ch, _In_ int _CType);
' ========================================================================================
DECLARE FUNCTION mbbtype_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbbtype" ( _
   BYVAL c AS BYTE _                                    ' __in unsigned char c
 , BYVAL type AS LONG _                                 ' __in int type
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _mbbtype_l(_In_ unsigned char _Ch, _In_ int _CType, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbbtype_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbbtype_l" ( _
   BYVAL c AS BYTE _                                    ' __in unsigned char c
 , BYVAL type AS LONG _                                 ' __in int type
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP unsigned int __cdecl _mbctombb(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION mbctombb_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbctombb" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS DWORD                                             ' unsigned int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP unsigned int __cdecl _mbctombb_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbctombb_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbctombb_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' unsigned int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP int __cdecl _mbsbtype(_In_bytecount_(_Pos) _Pre_z_ const unsigned char * _Str, _In_ size_t _Pos);
' ========================================================================================
DECLARE FUNCTION mbsbtype_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsbtype" ( _
   BYVAL mbstr AS DWORD _                               ' __in const unsigned char *mbstr
 , BYVAL count AS LONG _                                ' __in size_t count
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP int __cdecl _mbsbtype_l(_In_bytecount_(_Pos) _Pre_z_ const unsigned char * _Str, _In_ size_t _Pos, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsbtype_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsbtype_l" ( _
   BYVAL mbstr AS DWORD _                               ' __in const unsigned char *mbstr
 , BYVAL count AS LONG _                                ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
DECLARE FUNCTION mbscat_ CDECL IMPORT "msvcrt.dll" ALIAS "_mbscat" ( _
   BYVAL strDestination AS DWORD _                      ' unsigned char *strDestination
 , BYVAL strSource AS DWORD _                           ' const unsigned char *strSource
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' _CRTIMP_ALTERNATIVE errno_t __cdecl _mbscat_s(_Inout_z_bytecap_(_SizeInBytes) unsigned char * _Dst, _In_ size_t _SizeInBytes, _In_z_ const unsigned char * _Src);
' ========================================================================================
DECLARE FUNCTION mbscat_s CDECL IMPORT $CRT_DLLNAME ALIAS "_mbscat_s" ( _
   BYVAL strDestination AS DWORD _                      ' __in unsigned char *strDestination
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , BYVAL strSource AS DWORD _                           ' __in const unsigned char *strSource
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _mbscat_s_l(_Inout_z_bytecap_(_DstSizeInBytes) unsigned char * _Dst, _In_ size_t _DstSizeInBytes, _In_z_ const unsigned char * _Src, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbscat_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbscat_s_l" ( _
   BYVAL strDestination AS DWORD _                      ' __in unsigned char *strDestination
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , BYVAL strSource AS DWORD _                           ' __in const unsigned char *strSource
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP  _CONST_RETURN unsigned char * __cdecl _mbschr(_In_z_ const unsigned char * _Str, _In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION mbschr_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbschr" ( _
   BYVAL str AS DWORD _                                 ' __in const unsigned char *str
 , BYVAL c AS LONG _                                    ' __in unsigned int c
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP  _CONST_RETURN unsigned char * __cdecl _mbschr_l(_In_z_ const unsigned char * _Str, _In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbschr_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbschr_l" ( _
   BYVAL str AS DWORD _                                 ' __in const unsigned char *str
 , BYVAL c AS LONG _                                    ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _mbscmp(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char * _Str2);
' ========================================================================================
DECLARE FUNCTION mbscmp_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbscmp" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _mbscmp_l(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char * _Str2, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbscmp_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbscmp_l" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _mbscoll(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char * _Str2);
' ========================================================================================
DECLARE FUNCTION mbscoll_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbscoll" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _mbscoll_l(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char * _Str2, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbscoll_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbscoll_l" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP_ALTERNATIVE errno_t __cdecl _mbscpy_s(_Out_z_cap_(_SizeInBytes) unsigned char * _Dst, _In_ size_t _SizeInBytes, _In_z_ const unsigned char * _Src);
' ========================================================================================
DECLARE FUNCTION mbscpy_s CDECL IMPORT $CRT_DLLNAME ALIAS "_mbscpy_s" ( _
   BYVAL strDestination AS DWORD _                      ' __in const unsigned char *strDestination
 , numberOfElements AS DWORD _                          ' __in size_t numberOfElements
 , BYVAL strSource AS DWORD _                           ' __in const unsigned char *strSource
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _mbscpy_s_l(_Out_z_bytecap_(_DstSizeInBytes) unsigned char * _Dst, _In_ size_t _DstSizeInBytes, _In_z_ const unsigned char * _Src, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbscpy_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbscpy_s_l" ( _
   BYVAL strDestination AS DWORD _                      ' __in const unsigned char *strDestination
 , numberOfElements AS DWORD _                          ' __in size_t numberOfElements
 , BYVAL strSource AS DWORD _                           ' __in const unsigned char *strSource
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP size_t __cdecl _mbscspn(_In_z_ const unsigned char * _Str, _In_z_ const unsigned char * _Control);
' ========================================================================================
DECLARE FUNCTION mbscspn_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbscspn" ( _
   BYVAL str AS DWORD _                                 ' __in const unsigned char *str
 , BYVAL strCharSet AS DWORD _                          ' __in const unsigned char *strCharSet
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP size_t __cdecl _mbscspn_l(_In_z_ const unsigned char * _Str, _In_z_ const unsigned char * _Control, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbscspn_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbscspn_l" ( _
   BYVAL str AS DWORD _                                 ' __in const unsigned char *str
 , BYVAL strCharSet AS DWORD _                          ' __in const unsigned char *strCharSet
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP unsigned char * __cdecl _mbsdec(_In_count_x_(_Pos-_Start +1) _Pre_z_ const unsigned char * _Start, _In_z_ const unsigned char * _Pos);
' ========================================================================================
DECLARE FUNCTION mbsdec_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsdec" ( _
   BYVAL start AS DWORD _                               ' __in const unsigned char *start
 , BYVAL current AS DWORD _                             ' __in const unsigned char *current
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP unsigned char * __cdecl _mbsdec_l(_In_count_x_(_Pos-_Start+1) _Pre_z_ const unsigned char * _Start, _In_z_ const unsigned char * _Pos, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsdec_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsdec_l" ( _
   BYVAL start AS DWORD _                               ' __in const unsigned char *start
 , BYVAL current AS DWORD _                             ' __in const unsigned char *current
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _mbsicmp(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char * _Str2);
' ========================================================================================
DECLARE FUNCTION mbsicmp_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsicmp" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _mbsicmp_l(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char * _Str2, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsicmp_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsicmp_l" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _mbsicoll(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char * _Str2);
' ========================================================================================
DECLARE FUNCTION mbsicoll_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsicoll" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _mbsicoll_l(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char * _Str2, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsicoll_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsicoll_l" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP unsigned char * __cdecl _mbsinc(_In_z_ const unsigned char * _Ptr);
' ========================================================================================
DECLARE FUNCTION mbsinc_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsinc" ( _
   BYVAL current AS DWORD _                             ' __in const unsigned char *current
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP unsigned char * __cdecl _mbsinc_l(_In_z_ const unsigned char * _Ptr, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsinc_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsinc_l" ( _
   BYVAL current AS DWORD _                             ' __in const unsigned char *current
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP size_t __cdecl _mbslen(_In_z_ const unsigned char * _Str);
' ========================================================================================
DECLARE FUNCTION mbslen_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbslen" ( _
   BYVAL str AS DWORD _                                 ' __in const unsigned char *str
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP size_t __cdecl _mbslen_l(_In_z_ const unsigned char * _Str, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbslen_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbslen_l" ( _
   BYVAL str AS DWORD _                                 ' __in const unsigned char *str
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP size_t __cdecl _mbsnlen(_In_z_ const unsigned char * _Str, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION mbsnlen_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnlen" ( _
   BYVAL str AS DWORD _                                 ' __in const unsigned char *str
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP size_t __cdecl _mbsnlen_l(_In_z_ const unsigned char * _Str, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsnlen_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnlen_l" ( _
   BYVAL str AS DWORD _                                 ' __in const unsigned char *str
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION mbslwr_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbslwr" ( _
   BYVAL str AS DWORD _                                 ' const unsigned char *str
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _mbslwr_s(_Inout_opt_z_bytecap_(_SizeInBytes) unsigned char *_Str, _In_ size_t _SizeInBytes);
' ========================================================================================
DECLARE FUNCTION mbslwr_s CDECL IMPORT $CRT_DLLNAME ALIAS "_mbslwr_s" ( _
   BYVAL str AS DWORD _                                 ' __inout const unsigned char *str
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _mbslwr_s_l(_Inout_opt_z_bytecap_(_SizeInBytes) unsigned char *_Str, _In_ size_t _SizeInBytes, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbslwr_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbslwr_s_l" ( _
   BYVAL str AS DWORD _                                 ' __inout const unsigned char *str
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION mbsnbcat_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnbcat" ( _
   BYVAL dest AS DWORD _                                ' unsigned char dest
 , BYVAL src AS DWORD _                                 ' const unsigned char *src
 , BYVAL count AS DWORD _                               ' size_t count
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' _CRTIMP_ALTERNATIVE errno_t __cdecl _mbsnbcat_s(_Inout_z_bytecap_(_SizeInBytes) unsigned char * _Dst, _In_ size_t _SizeInBytes, _In_z_ const unsigned char * _Src, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION mbsnbcat_s CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnbcat_s" ( _
   BYVAL dest AS DWORD _                                ' __inout unsigned char dest
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , BYVAL src AS DWORD _                                 ' __in const unsigned char *src
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _mbsnbcat_s_l(_Inout_z_bytecap_(_DstSizeInBytes) unsigned char * _Dst, _In_ size_t _DstSizeInBytes, _In_z_ const unsigned char * _Src, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsnbcat_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnbcat_s_l" ( _
   BYVAL dest AS DWORD _                                ' __inout unsigned char dest
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , BYVAL src AS DWORD _                                 ' __in const unsigned char *src
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _mbsnbcmp(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char * _Str2, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION mbsnbcmp_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnbcmp" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _mbsnbcmp_l(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char * _Str2, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsnbcmp_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnbcmp_l" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _mbsnbcoll(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char * _Str2, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION mbsnbcoll_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnbcoll" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _mbsnbcoll_l(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char * _Str2, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsnbcoll_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnbcoll_l" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP size_t __cdecl _mbsnbcnt(_In_bytecount_(_MaxCount) _Pre_z_ const unsigned char * _Str, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION mbsnbcnt_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnbcnt" ( _
   BYVAL string AS DWORD _                              ' __in const unsigned char *string
 , BYVAL number AS DWORD _                              ' __in size_t number
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP size_t __cdecl _mbsnbcnt_l(_In_bytecount_(_MaxCount) _Pre_z_ const unsigned char * _Str, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsnbcnt_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnbcnt_l" ( _
   BYVAL string AS DWORD _                              ' __in const unsigned char *string
 , BYVAL number AS DWORD _                              ' __in size_t number
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION mbsnbcpy_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnbcpy" ( _
   BYVAL strDest AS DWORD _                             ' unsigned char * strDest
 , BYVAL strSource AS DWORD _                           ' const unsigned char * strSource
 , BYVAL count AS DWORD _                               ' size_t count
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' _CRTIMP_ALTERNATIVE errno_t __cdecl _mbsnbcpy_s(_Out_z_cap_(_SizeInBytes) unsigned char * _Dst, _In_ size_t _SizeInBytes, _In_z_ const unsigned char * _Src, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION mbsnbcpy_s CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnbcpy_s" ( _
   BYVAL strDest AS DWORD _                             ' __out unsigned char * strDest
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , BYVAL strSource AS DWORD _                           ' __in const unsigned char * strSource
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _mbsnbcpy_s_l(_Out_z_bytecap_(_DstSizeInBytes) unsigned char * _Dst, _In_ size_t _DstSizeInBytes, _In_z_ const unsigned char * _Src, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsnbcpy_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnbcpy_s_l" ( _
   BYVAL strDest AS DWORD _                             ' __out unsigned char * strDest
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , BYVAL strSource AS DWORD _                           ' __in const unsigned char * strSource
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _mbsnbicmp(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char * _Str2, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION mbsnbicmp_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnbicmp" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _mbsnbicmp_l(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char * _Str2, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsnbicmp_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnbicmp_l" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _mbsnbicoll(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char * _Str2, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION mbsnbicoll_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnbicoll" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _mbsnbicoll_l(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char * _Str2, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsnbicoll_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnbicoll_l" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION mbsnbset_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnbset" ( _
   BYVAL str AS DWORD _                                 ' unsigned char *str
 , BYVAL c AS DWORD _                                   ' unsigned int c
 , BYVAL count AS DWORD _                               ' size_t count
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' _CRTIMP_ALTERNATIVE errno_t __cdecl _mbsnbset_s(_Inout_z_bytecap_(_SizeInBytes) unsigned char * _Dst, _In_ size_t _SizeInBytes, _In_ unsigned int _Ch, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION mbsnbset_s CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnbset_s" ( _
   BYVAL str AS DWORD _                                 ' __inout unsigned char *str
 , BYVAL size AS DWORD _                                ' __in size_t size
 , BYVAL c AS DWORD _                                   ' __in unsigned int c
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _mbsnbset_s_l(_Inout_z_bytecap_(_DstSizeInBytes) unsigned char * _Dst, _In_ size_t _DstSizeInBytes, _In_ unsigned int _Ch, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsnbset_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnbset_s_l" ( _
   BYVAL str AS DWORD _                                 ' __inout unsigned char *str
 , BYVAL size AS DWORD _                                ' __in size_t size
 , BYVAL c AS DWORD _                                   ' __in unsigned int c
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION mbsncat_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsncat" ( _
   BYVAL strDest AS DWORD _                             ' unsigned char *strDest
 , BYVAL strSource AS DWORD _                           ' const unsigned char *strSource
 , BYVAL count AS DWORD _                               ' size_t count
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' _CRTIMP_ALTERNATIVE errno_t __cdecl _mbsncat_s(_Inout_z_bytecap_(_SizeInBytes) unsigned char * _Dst, _In_ size_t _SizeInBytes, _In_z_ const unsigned char * _Src, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION mbsncat_s CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsncat_s" ( _
   BYVAL strDest AS DWORD _                             ' __inout unsigned char *strDest
 , BYVAL bufferSizeInBytes AS DWORD _                   ' __in size_t bufferSizeInBytes
 , BYVAL strSource AS DWORD _                           ' __in const unsigned char *strSource
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _mbsncat_s_l(_Inout_z_bytecap_(_DstSizeInBytes) unsigned char * _Dst, _In_ size_t _DstSizeInBytes, _In_z_ const unsigned char * _Src, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsncat_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsncat_s_l" ( _
   BYVAL strDest AS DWORD _                             ' __inout unsigned char *strDest
 , BYVAL bufferSizeInBytes AS DWORD _                   ' __in size_t bufferSizeInBytes
 , BYVAL strSource AS DWORD _                           ' __in const unsigned char *strSource
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP size_t __cdecl _mbsnccnt(_In_bytecount_(_MaxCount) _Pre_z_ const unsigned char * _Str, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION mbsnccnt_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnccnt" ( _
   BYVAL string AS DWORD _                              ' __in const unsigned char *string
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP size_t __cdecl _mbsnccnt_l(_In_bytecount_(_MaxCount) _Pre_z_ const unsigned char * _Str, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsnccnt_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnccnt_l" ( _
   BYVAL string AS DWORD _                              ' __in const unsigned char *string
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _mbsncmp(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char * _Str2, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION mbsncmp_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsncmp" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _mbsncmp_l(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char * _Str2, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsncmp_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsncmp_l" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _mbsncoll(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char * _Str2, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION mbsncoll_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsncoll" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _mbsncoll_l(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char * _Str2, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsncoll_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsncoll_l" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION mbsncpy_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsncpy" ( _
   BYVAL strDest AS DWORD _                             ' unsigned char *strDest
 , BYVAL strSource AS DWORD _                           ' const unsigned char *strSource
 , BYVAL count AS DWORD _                               ' size_t count
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' _CRTIMP_ALTERNATIVE errno_t __cdecl _mbsncpy_s(_Out_z_bytecap_(_SizeInBytes) unsigned char * _Dst, _In_ size_t _SizeInBytes, _In_z_ const unsigned char * _Src, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION mbsncpy_s CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsncpy_s" ( _
   BYVAL strDest AS DWORD _                             ' __out unsigned char *strDest
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , BYVAL strSource AS DWORD _                           ' __in const unsigned char *strSource
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _mbsncpy_s_l(_Out_z_bytecap_(_DstSizeInBytes) unsigned char * _Dst, _In_ size_t _DstSizeInBytes, _In_z_ const unsigned char * _Src, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsncpy_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsncpy_s_l" ( _
   BYVAL strDest AS DWORD _                             ' __out unsigned char *strDest
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , BYVAL strSource AS DWORD _                           ' __in const unsigned char *strSource
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP unsigned int __cdecl _mbsnextc (_In_z_ const unsigned char * _Str);
' ========================================================================================
DECLARE FUNCTION mbsnextc_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnextc" ( _
   BYVAL string AS DWORD _                              ' __in const unsigned char *string
 ) AS DWORD                                             ' unsigned int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP unsigned int __cdecl _mbsnextc_l(_In_z_ const unsigned char * _Str, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsnextc_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnextc_l" ( _
   BYVAL string AS DWORD _                              ' __in const unsigned char *string
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' unsigned int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _mbsnicmp(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char * _Str2, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION mbsnicmp_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnicmp" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _mbsnicmp_l(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char * _Str2, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsnicmp_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnicmp_l" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _mbsnicoll(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char * _Str2, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION mbsnicoll_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnicoll" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _mbsnicoll_l(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char * _Str2, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsnicoll_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnicoll_l" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP unsigned char * __cdecl _mbsninc(_In_bytecount_(_Count) _Pre_z_ const unsigned char * _Str, _In_ size_t _Count);
' ========================================================================================
DECLARE FUNCTION mbsninc_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsninc" ( _
   BYVAL string AS DWORD _                              ' __in const unsigned char *string
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP unsigned char * __cdecl _mbsninc_l(_In_bytecount_(_Count) _Pre_z_ const unsigned char * _Str, _In_ size_t _Count, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsninc_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsninc_l" ( _
   BYVAL string AS DWORD _                              ' __in const unsigned char *string
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION mbsnset_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnset" ( _
   BYVAL string AS DWORD _                              ' const unsigned char *string
 , BYVAL c AS DWORD _                                   ' unsigned int c
 , BYVAL count AS DWORD _                               ' size_t count
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' _CRTIMP_ALTERNATIVE errno_t __cdecl _mbsnset_s(_Inout_z_bytecap_(_SizeInBytes) unsigned char * _Dst, _In_ size_t _SizeInBytes, _In_ unsigned int _Val, _In_ size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION mbsnset_s CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnset_s" ( _
   BYVAL string AS DWORD _                              ' __inout const unsigned char *string
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , BYVAL c AS DWORD _                                   ' __in unsigned int c
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _mbsnset_s_l(_Inout_z_bytecap_(_DstSizeInBytes) unsigned char * _Dst, _In_ size_t _DstSizeInBytes, _In_ unsigned int _Val, _In_ size_t _MaxCount, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsnset_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsnset_s_l" ( _
   BYVAL string AS DWORD _                              ' __inout const unsigned char *string
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , BYVAL c AS DWORD _                                   ' __in unsigned int c
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP  _CONST_RETURN unsigned char * __cdecl _mbspbrk(_In_z_ const unsigned char * _Str, _In_z_ const unsigned char * _Control);
' ========================================================================================
DECLARE FUNCTION mbspbrk_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbspbrk" ( _
   BYVAL str AS DWORD _                                 ' __in const unsigned char *str
 , BYVAL strCharSet AS DWORD _                          ' __in const unsigned char *strCharSet
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP  _CONST_RETURN unsigned char * __cdecl _mbspbrk_l(_In_z_ const unsigned char * _Str, _In_z_ const unsigned char * _Control, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbspbrk_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbspbrk_l" ( _
   BYVAL str AS DWORD _                                 ' __in const unsigned char *str
 , BYVAL strCharSet AS DWORD _                          ' __in const unsigned char *strCharSet
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP  _CONST_RETURN unsigned char * __cdecl _mbsrchr(_In_z_ const unsigned char * _Str, _In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION mbsrchr_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsrchr" ( _
   BYVAL str AS DWORD _                                 ' __in const unsigned char *str
 , BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP  _CONST_RETURN unsigned char * __cdecl _mbsrchr_l(_In_z_ const unsigned char *_Str, _In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsrchr_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsrchr_l" ( _
   BYVAL str AS DWORD _                                 ' __in const unsigned char *str
 , BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP unsigned char * __cdecl _mbsrev(_Inout_z_ unsigned char * _Str);
' ========================================================================================
DECLARE FUNCTION mbsrev_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsrev" ( _
   BYVAL str AS DWORD _                                 ' __inout const unsigned char *str
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' _CRTIMP unsigned char * __cdecl _mbsrev_l(_Inout_z_ unsigned char *_Str, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsrev_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsrev_l" ( _
   BYVAL str AS DWORD _                                 ' __inout const unsigned char *str
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION mbsset_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsset" ( _
   BYVAL string AS DWORD _                              ' unsigned char *string
 , BYVAL c AS DWORD _                                   ' unsigned int c
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' _CRTIMP_ALTERNATIVE errno_t __cdecl _mbsset_s(_Inout_z_bytecap_(_SizeInBytes) unsigned char * _Dst, _In_ size_t _SizeInBytes, _In_ unsigned int _Val);
' ========================================================================================
DECLARE FUNCTION mbsset_s CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsset_s" ( _
   BYVAL string AS DWORD _                              ' __inout unsigned char *string
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _mbsset_s_l(_Inout_z_bytecap_(_DstSizeInBytes) unsigned char * _Dst, _In_ size_t _DstSizeInBytes, _In_ unsigned int _Val, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsset_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsset_s_l" ( _
   BYVAL string AS DWORD _                              ' __inout unsigned char *string
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP size_t __cdecl _mbsspn(_In_z_ const unsigned char *_Str, _In_z_ const unsigned char * _Control);
' ========================================================================================
DECLARE FUNCTION mbsspn_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsspn" ( _
   BYVAL string AS DWORD _                              ' __in unsigned char *string
 , BYVAL strCharSet AS DWORD _                          ' __in const unsigned char *strCharSet
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP size_t __cdecl _mbsspn_l(_In_z_ const unsigned char * _Str, _In_z_ const unsigned char * _Control, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsspn_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsspn_l" ( _
   BYVAL string AS DWORD _                              ' __in unsigned char *string
 , BYVAL strCharSet AS DWORD _                          ' __in const unsigned char *strCharSet
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP unsigned char * __cdecl _mbsspnp(_In_z_ const unsigned char * _Str1, _In_z_ const unsigned char *_Str2);
' ========================================================================================
DECLARE FUNCTION mbsspnp_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsspnp" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP unsigned char * __cdecl _mbsspnp_l(_In_z_ const unsigned char *_Str1, _In_z_ const unsigned char *_Str2, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsspnp_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsspnp_l" ( _
   BYVAL string1 AS DWORD _                             ' __in const unsigned char *string1
 , BYVAL string2 AS DWORD _                             ' __in const unsigned char *string2
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP  _CONST_RETURN unsigned char * __cdecl _mbsstr(_In_z_ const unsigned char * _Str, _In_z_ const unsigned char * _Substr);
' ========================================================================================
DECLARE FUNCTION mbsstr_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsstr" ( _
   BYVAL str AS DWORD _                                 ' __in const unsigned char *str
 , BYVAL strSearch AS DWORD _                           ' __in const unsigned char *strSearch
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP  _CONST_RETURN unsigned char * __cdecl _mbsstr_l(_In_z_ const unsigned char * _Str, _In_z_ const unsigned char * _Substr, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsstr_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsstr_l" ( _
   BYVAL str AS DWORD _                                 ' __in const unsigned char *str
 , BYVAL strSearch AS DWORD _                           ' __in const unsigned char *strSearch
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP _CRT_INSECURE_DEPRECATE(_mbstok_s) unsigned char * __cdecl _mbstok(_Inout_opt_z_ unsigned char * _Str, _In_z_ const unsigned char * _Delim);
' ========================================================================================
DECLARE FUNCTION mbstok_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbstok" ( _
   BYVAL strToken AS DWORD _                            ' unsigned char *strToken
 , BYVAL strDelimit AS DWORD _                          ' const unsigned char *strDelimit
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP_ALTERNATIVE unsigned char * __cdecl _mbstok_s(_Inout_opt_z_ unsigned char *_Str, _In_z_ const unsigned char * _Delim, _Inout_ _Deref_prepost_opt_z_ unsigned char ** _Context);
' ========================================================================================
DECLARE FUNCTION mbstok_s CDECL IMPORT $CRT_DLLNAME ALIAS "_mbstok_s" ( _
   BYVAL strToken AS DWORD _                            ' __inout unsigned char *strToken
 , BYVAL strDelimit AS DWORD _                          ' __in const unsigned char *strDelimit
 , BYREF context AS DWORD _                             ' __in char **context
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP _CRT_INSECURE_DEPRECATE(_mbstok_s_l)
' unsigned char * __cdecl _mbstok_l(_Inout_opt_z_ unsigned char *_Str,
' _In_z_ const unsigned char * _Delim, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbstok_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbstok_l" ( _
   BYVAL strToken AS DWORD _                            ' __inout unsigned char *strToken
 , BYVAL strDelimit AS DWORD _                          ' __in const unsigned char *strDelimit
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP unsigned char * __cdecl _mbstok_s_l(_Inout_opt_z_ unsigned char * _Str, _In_z_ const unsigned char * _Delim, _Inout_ _Deref_prepost_opt_z_ unsigned char ** _Context, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbstok_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbstok_s_l" ( _
   BYVAL strToken AS DWORD _                            ' __inout unsigned char *strToken
 , BYVAL strDelimit AS DWORD _                          ' __in const unsigned char *strDelimit
 , BYREF context AS DWORD _                             ' __in char **context
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION mbsupr_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsupr" ( _
   BYVAL str AS DWORD _                                 ' unsigned char *str
 ) AS DWORD                                             ' unsigned char *
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _mbsupr_s(_Inout_z_bytecap_(_SizeInBytes) unsigned char *_Str, _In_ size_t _SizeInBytes);
' ========================================================================================
DECLARE FUNCTION mbsupr_s CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsupr_s" ( _
   BYVAL str AS DWORD _                                 ' __inout unsigned char *str
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _mbsupr_s_l(_Inout_z_bytecap_(_SizeInBytes) unsigned char *_Str, _In_ size_t _SizeInBytes, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbsupr_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbsupr_s_l" ( _
   BYVAL str AS DWORD _                                 ' __inout unsigned char *str
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
' _Check_return_ _CRTIMP size_t __cdecl _mbclen(_In_z_ const unsigned char *_Str);
' ========================================================================================
DECLARE FUNCTION mbclen_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbclen" ( _
   BYVAL mbstr AS DWORD _                               ' __in const unsigned char *mbstr
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP size_t __cdecl _mbclen_l(_In_z_ const unsigned char * _Str, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbclen_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbclen_l" ( _
   BYVAL mbstr AS DWORD _                               ' __in const unsigned char *mbstr
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP _CRT_INSECURE_DEPRECATE(_mbccpy_s) void __cdecl _mbccpy(_Out_bytecap_c_(2) unsigned char * _Dst, _In_z_ const unsigned char * _Src);
' ========================================================================================
DECLARE SUB mbccpy_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbccpy" ( _
   BYVAL dest AS DWORD _                                ' unsigned char *dest
 , BYVAL src AS DWORD _                                 ' const unsigned char *src
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' _CRTIMP_ALTERNATIVE errno_t __cdecl _mbccpy_s(_Out_z_bytecap_(_SizeInBytes) unsigned char * _Dst, _In_ size_t _SizeInBytes, _Out_opt_ int * _PCopied, _In_z_ const unsigned char * _Src);
' ========================================================================================
DECLARE FUNCTION mbccpy_s CDECL IMPORT $CRT_DLLNAME ALIAS "_mbccpy_s" ( _
   BYVAL dest AS DWORD _                                ' __out unsigned char *dest
 , BYVAL buffSizeInBytes AS DWORD _                     ' __in size_t buffSizeInBytes
 , BYREF pCopied AS LONG _                              ' __in int * pCopied
 , BYVAL src AS DWORD _                                 ' __in const unsigned char *src
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRTIMP _CRT_INSECURE_DEPRECATE(_mbccpy_s_l) void __cdecl _mbccpy_l(
' _Out_bytecap_c_(2) unsigned char *_Dst, _In_z_ const unsigned char *_Src, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbccpy_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbccpy_s_l" ( _
   BYVAL dest AS DWORD _                                ' __out unsigned char *dest
 , BYVAL buffSizeInBytes AS DWORD _                     ' __in size_t buffSizeInBytes
 , BYREF pCopied AS LONG _                              ' __in int * pCopied
 , BYVAL src AS DWORD _                                 ' __in const unsigned char *src
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _mbccpy_s_l(_Out_bytecap_(_DstSizeInBytes) unsigned char * _Dst, _In_ size_t _DstSizeInBytes, _Out_opt_ int * _PCopied, _In_z_ const unsigned char * _Src, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbccpy_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbccpy_s_l" ( _
   BYVAL dest AS DWORD _                                ' __out unsigned char *dest
 , BYVAL buffSizeInBytes AS DWORD _                     ' __in size_t buffSizeInBytes
 , BYREF pCopied AS LONG _                              ' __in int * pCopied
 , BYVAL src AS DWORD _                                 ' __in const unsigned char *src
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' errno_t
' ========================================================================================

'#define _mbccmp(_cpc1, _cpc2) _mbsncmp((_cpc1),(_cpc2),1)
MACRO mbccmp_ (cpc1, cpc2) = mbsncmp(cpc1, cpc2, 1)

'/* character routines */

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbcalnum(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION ismbcalnum_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbcalnum" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbcalnum_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbcalnum_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbcalnum_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbcalpha(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION ismbcalpha_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbcalpha" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbcalpha_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbcalpha_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbcalpha_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbcdigit(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION ismbcdigit_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbcdigit" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbcdigit_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbcdigit_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbcdigit_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbcgraph(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION ismbcgraph_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbcgraph" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbcgraph_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbcgraph_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbcgraph_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbclegal(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION ismbclegal_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbclegal" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbclegal_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbclegal_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbclegal_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbclower(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION ismbclower_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbclower" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbclower_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbclower_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbclower_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbcprint(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION ismbcprint_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbcprint" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbcprint_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbcprint_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbcprint_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbcpunct(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION ismbcpunct_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbcpunct" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbcpunct_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbcpunct_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbcpunct_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbcspace(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION ismbcspace_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbcspace" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbcspace_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbcspace_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbcspace_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbcupper(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION ismbcupper_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbcupper" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbcupper_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbcupper_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbcupper_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP unsigned int __cdecl _mbctolower(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION mbctolower_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbctolower" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS DWORD                                             ' unsigned int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP unsigned int __cdecl _mbctolower_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbctolower_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbctolower_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' unsigned int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP unsigned int __cdecl _mbctoupper(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION mbctoupper_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbctoupper" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS DWORD                                             ' unsigned int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP unsigned int __cdecl _mbctoupper_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbctoupper_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbctoupper_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' unsigned int
' ========================================================================================

#ENDIF   ' MBSTRING_DEFINED

#IF NOT %DEF(%MBLEADTRAIL_DEFINED)
    %MBLEADTRAIL_DEFINED = 1

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbblead(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION ismbblead CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbblead" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbblead_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbblead_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbblead_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbbtrail(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION ismbbtrail_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbbtrail" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbbtrail_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbbtrail_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbbtrail_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbslead(_In_count_x_(_Pos - _Str+1) _Pre_z_ const unsigned char * _Str, _In_z_ const unsigned char * _Pos);
' ========================================================================================
DECLARE FUNCTION ismbslead_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbslead" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbslead_l(_In_count_x_(_Pos - _Str+1) _Pre_z_ const unsigned char * _Str, _In_z_ const unsigned char * _Pos, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbslead_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbslead_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbstrail(_In_count_x_(_Pos - _Str+1) _Pre_z_ const unsigned char * _Str, _In_z_ const unsigned char * _Pos);
' ========================================================================================
DECLARE FUNCTION ismbstrail_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbstrail" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbstrail_l(_In_count_x_(_Pos - _Str+1) _Pre_z_ const unsigned char * _Str, _In_z_ const unsigned char * _Pos, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbstrail_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbstrail_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

#ENDIF   ' MBLEADTRAIL_DEFINED

'/*  Kanji specific prototypes.  */

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbchira(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION ismbchira_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbchira" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbchira_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbchira_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbchira_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbckata(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION ismbckata_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbckata" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbckata_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbckata_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbckata_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbcsymbol(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION ismbcsymbol_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbcsymbol" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbcsymbol_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbcsymbol_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbcsymbol_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbcl0(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION ismbcl0_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbcl0" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbcl0_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbcl0_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbcl0_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbcl1(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION ismbcl1_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbcl1" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbcl1_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbcl1_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbcl1_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbcl2(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION ismbcl2_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbcl2" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbcl2_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbcl2_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbcl2_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP unsigned int __cdecl _mbcjistojms(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION mbcjistojms_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbcjistojms" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS DWORD                                             ' unsigned int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP unsigned int __cdecl _mbcjistojms_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbcjistojms_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbcjistojms_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' unsigned int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP unsigned int __cdecl _mbcjmstojis(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION mbcjmstojis_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbcjmstojis" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS DWORD                                             ' unsigned int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP unsigned int __cdecl _mbcjmstojis_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbcjmstojis_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbcjmstojis_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' unsigned int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP unsigned int __cdecl _mbctohira(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION mbctohira_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbctohira" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS DWORD                                             ' unsigned int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP unsigned int __cdecl _mbctohira_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbctohira_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbctohira_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' unsigned int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP unsigned int __cdecl _mbctokata(_In_ unsigned int _Ch);
' ========================================================================================
DECLARE FUNCTION mbctokata_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbctokata" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS DWORD                                             ' unsigned int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP unsigned int __cdecl _mbctokata_l(_In_ unsigned int _Ch, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbctokata_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbctokata_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' unsigned int
' ========================================================================================
