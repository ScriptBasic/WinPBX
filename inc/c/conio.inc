' ########################################################################################
' Microsoft C Runtime
' File: conio.inc
' Contents: Console and port I/O declarations
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CONIO_INC = 1

#INCLUDE ONCE "crtdefs.inc"

'/* Function prototypes */

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION cgets_ CDECL IMPORT $CRT_DLLNAME ALIAS "_cgets" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _cgets_s(_Out_z_cap_(_Size)
' char * _Buffer, size_t _Size, _Out_ size_t * _SizeRead);
' ========================================================================================
DECLARE FUNCTION cgets_s CDECL IMPORT $CRT_DLLNAME ALIAS "_cgets_s" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , BYREF pSizeRead AS DWORD _                           ' __out size_t *pSizeRead
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl _cprintf(_In_z_ _Printf_format_string_ const char * _Format, ...);
' ========================================================================================
DECLARE FUNCTION cprintf_ CDECL IMPORT $CRT_DLLNAME ALIAS "_cprintf" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _cprintf_s(_In_z_ _Printf_format_string_ const char * _Format, ...);
' ========================================================================================
DECLARE FUNCTION cprintf_s CDECL IMPORT $CRT_DLLNAME ALIAS "_cprintf_s" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl _cputs(_In_z_ const char * _Str);
' ========================================================================================
DECLARE FUNCTION cputs_ CDECL IMPORT $CRT_DLLNAME ALIAS "_cputs" ( _
   BYREF str AS ASCIIZ _                                ' __in const char *str
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_cscanf_s) _CRTIMP int __cdecl _cscanf(
' _In_z_ _Scanf_format_string_ const char * _Format, ...);
' ========================================================================================
DECLARE FUNCTION cscanf_ CDECL IMPORT $CRT_DLLNAME ALIAS "_cscanf" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_cscanf_s_l) _CRTIMP int __cdecl _cscanf_l(
' _In_z_ _Scanf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION cscanf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_cscanf_s_l" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _cscanf_s(_In_z_ _Scanf_format_string_ const char * _Format, ...);
' ========================================================================================
DECLARE FUNCTION cscanf_s CDECL IMPORT $CRT_DLLNAME ALIAS "_cscanf_s" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _cscanf_s_l(_In_z_ _Scanf_format_string_ const char * _Format,
' _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION cscanf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_cscanf_s_l" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _getch(void);
' ========================================================================================
DECLARE FUNCTION getch_ CDECL IMPORT $CRT_DLLNAME ALIAS "_getch" ( _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _getche(void);
' ========================================================================================
DECLARE FUNCTION getche_ CDECL IMPORT $CRT_DLLNAME ALIAS "_getche" ( _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vcprintf(_In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vcprintf_ CDECL IMPORT $CRT_DLLNAME ALIAS "_vcprintf" ( _
   BYREF format AS ASCIIZ _                             ' __in const char* format
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vcprintf_s(_In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vcprintf_s CDECL IMPORT $CRT_DLLNAME ALIAS "_vcprintf_s" ( _
   BYREF format AS ASCIIZ _                             ' __in const char* format
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _cprintf_p(_In_z_ _Printf_format_string_ const char * _Format, ...);
' ========================================================================================
DECLARE FUNCTION cprintf_p CDECL IMPORT $CRT_DLLNAME ALIAS "_cprintf_p" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vcprintf_p(_In_z_ const char * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vcprintf_p CDECL IMPORT $CRT_DLLNAME ALIAS "_vcprintf_p" ( _
   BYREF format AS ASCIIZ _                             ' __in const char* format
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _cprintf_l(_In_z_ _Printf_format_string_ const char * _Format,
'  _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION cprintf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_cprintf_l" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _cprintf_s_l(_In_z_ _Printf_format_string_ const char * _Format,
'  _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION cprintf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_cprintf_s_l" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vcprintf_l(_In_z_ _Printf_format_string_ const char * _Format,
'  _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vcprintf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vcprintf_l" ( _
   BYREF format AS ASCIIZ _                             ' __in const char* format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vcprintf_s_l(_In_z_ _Printf_format_string_ const char * _Format,
' _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vcprintf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vcprintf_s_l" ( _
   BYREF format AS ASCIIZ _                             ' __in const char* format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _cprintf_p_l(_In_z_ _Printf_format_string_ const char * _Format,
' _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION cprintf_p_l CDECL IMPORT $CRT_DLLNAME ALIAS "_cprintf_p_l" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vcprintf_p_l(_In_z_ _Printf_format_string_ const char * _Format,
' _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vcprintf_p_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vcprintf_p_l" ( _
   BYREF format AS ASCIIZ _                             ' __in const char* format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP int __cdecl _kbhit(void);
' ========================================================================================
DECLARE FUNCTION kbhit_ CDECL IMPORT $CRT_DLLNAME ALIAS "_kbhit" ( _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP int __cdecl _putch(_In_ int _Ch);
' ========================================================================================
DECLARE FUNCTION putch_ CDECL IMPORT $CRT_DLLNAME ALIAS "_putch" ( _
   BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP int __cdecl _ungetch(_In_ int _Ch);
' ========================================================================================
DECLARE FUNCTION ungetch_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ungetch" ( _
   BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _getch_nolock(void);
' ========================================================================================
DECLARE FUNCTION getch_nolock CDECL IMPORT $CRT_DLLNAME ALIAS "_getch_nolock" ( _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _getche_nolock(void);
' ========================================================================================
DECLARE FUNCTION getche_nolock CDECL IMPORT $CRT_DLLNAME ALIAS "_getche_nolock" ( _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP int __cdecl _putch_nolock(_In_ int _Ch);
' ========================================================================================
DECLARE FUNCTION putch_nolock CDECL IMPORT $CRT_DLLNAME ALIAS "_putch_nolock" ( _
   BYVAL c AS LONG _                                    ' int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP int __cdecl _ungetch_nolock(_In_ int _Ch);
' ========================================================================================
DECLARE FUNCTION ungetch_nolock CDECL IMPORT $CRT_DLLNAME ALIAS "_ungetch_nolock" ( _
   BYVAL c AS LONG _                                    ' int c
 ) AS LONG                                              ' int
' ========================================================================================

#IF NOT %DEF(%WCONIO_DEFINED)
    %WCONIO_DEFINED = 1

'/* wide function prototypes, also declared in wchar.h */

#IF NOT %DEF(%WEOF)
%WEOF = &HFFFF??
#ENDIF

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _cgetws_s(_Out_cap_post_count_(
' _SizeInWords, *_SizeRead) wchar_t * _Buffer, size_t _SizeInWords, _Out_ size_t * _SizeRead);
' ========================================================================================
DECLARE FUNCTION cgetws_s CDECL IMPORT $CRT_DLLNAME ALIAS "_cgetws_s" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL sizeInWords AS DWORD _                         ' __in size_t sizeInWords
 , BYREF pSizeRead AS DWORD _                           ' __out size_t *pSizeRead
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
DECLARE FUNCTION cgetws_ CDECL IMPORT $CRT_DLLNAME ALIAS "_cgetws" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 ) AS DWORD                                             ' wchar_t
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP wint_t __cdecl _getwch(void);
' ========================================================================================
DECLARE FUNCTION getwch_ CDECL IMPORT $CRT_DLLNAME ALIAS "_getwch" ( _
 ) AS WORD                                              ' wint_t
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP wint_t __cdecl _getwche(void);
' ========================================================================================
DECLARE FUNCTION getwche_ CDECL IMPORT $CRT_DLLNAME ALIAS "_getwche" ( _
 ) AS WORD                                              ' wint_t
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
' ========================================================================================
DECLARE FUNCTION putwch_ CDECL IMPORT $CRT_DLLNAME ALIAS "_putwch" ( _
   BYVAL c AS WORD _                                    ' __in wchar_t c
 ) AS WORD                                              ' wint_t
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
' ========================================================================================
DECLARE FUNCTION ungetwch_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ungetwch" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 ) AS WORD                                              ' wint_t
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _cputws(_In_z_ const wchar_t * _String);
' ========================================================================================
DECLARE FUNCTION cputws_ CDECL IMPORT $CRT_DLLNAME ALIAS "_cputws" ( _
   BYREF str AS WSTRINGZ _                              ' __in const wchar_t *str
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _cwprintf(_In_z_ _Printf_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION cwprintf CDECL IMPORT $CRT_DLLNAME ALIAS "_cwprintf" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _cwprintf_s(_In_z_ _Printf_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION cwprintf_s CDECL IMPORT $CRT_DLLNAME ALIAS "_cwprintf_s" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_cwscanf_s) _CRTIMP int __cdecl _cwscanf(
' _In_z_ _Scanf_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION cwscanf_s CDECL IMPORT $CRT_DLLNAME ALIAS "_cwscanf_s" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_cwscanf_s_l) _CRTIMP int __cdecl _cwscanf_l(
' _In_z_ _Scanf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION cwscanf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_cwscanf_s_l" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _cwscanf_s(_In_z_ _Scanf_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION cwscanf_s CDECL IMPORT $CRT_DLLNAME ALIAS "_cwscanf_s" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _cwscanf_s_l(_In_z_ _Scanf_format_string_ const wchar_t * _Format,
' _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION cwscanf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_cwscanf_s_l" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vcwprintf(_In_z_ _Printf_format_string_ const wchar_t *_Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vcwprintf_ CDECL IMPORT $CRT_DLLNAME ALIAS "_vcwprintf" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vcwprintf_s(_In_z_ _Printf_format_string_ const wchar_t *_Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vcwprintf_s CDECL IMPORT $CRT_DLLNAME ALIAS "_vcwprintf_s" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _cwprintf_p(_In_z_ _Printf_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION cwprintf_p CDECL IMPORT $CRT_DLLNAME ALIAS "_cwprintf_p" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vcwprintf_p(_In_z_ _Printf_format_string_ const wchar_t*  _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vcwprintf_p CDECL IMPORT $CRT_DLLNAME ALIAS "_vcwprintf_p" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP int __cdecl _cwprintf_l(_In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION cwprintf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_cwprintf_l" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP int __cdecl _cwprintf_s_l(_In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION cwprintf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_cwprintf_s_l" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP int __cdecl _vcwprintf_l(_In_z_ _Printf_format_string_ const wchar_t *_Format,
' _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vcwprintf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vcwprintf_l" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP int __cdecl _vcwprintf_s_l(_In_z_ _Printf_format_string_ const wchar_t * _Format,
' _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vcwprintf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vcwprintf_s_l" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP int __cdecl _cwprintf_p_l(_In_z_ _Printf_format_string_ const wchar_t * _Format,
' _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION cwprintf_p_l CDECL IMPORT $CRT_DLLNAME ALIAS "_cwprintf_p_l" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP int __cdecl _vcwprintf_p_l(_In_z_ _Printf_format_string_ const wchar_t * _Format,
' _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vcwprintf_p_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vcwprintf_p_l" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP wint_t __cdecl _putwch_nolock(wchar_t _WCh);
' ========================================================================================
DECLARE FUNCTION putwch_nolock CDECL IMPORT $CRT_DLLNAME ALIAS "_putwch_nolock" ( _
   BYVAL c AS WORD _                                    ' __in wchar_t c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP wint_t __cdecl _getwch_nolock(void);
' ========================================================================================
DECLARE FUNCTION getwch_nolock CDECL IMPORT $CRT_DLLNAME ALIAS "_getwch_nolock" ( _
 ) AS WORD                                              ' wint_t
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP wint_t __cdecl _getwche_nolock(void);
' ========================================================================================
DECLARE FUNCTION getwche_nolock CDECL IMPORT $CRT_DLLNAME ALIAS "_getwche_nolock" ( _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
' ========================================================================================
DECLARE FUNCTION ungetwch_nolock CDECL IMPORT $CRT_DLLNAME ALIAS "_ungetwch_nolock" ( _
   BYVAL c AS WORD _                                    ' __in wchar_t c
 ) AS LONG                                              ' int
' ========================================================================================

#ENDIF   ' WCONIO_DEFINED
