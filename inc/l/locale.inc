' ########################################################################################
' Microsoft C Runtime
' File: locale.inc
' Contents: This file defines the structures, values, macros, and functions used by the
' localization routines.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LOCALE_INC = 1

#INCLUDE ONCE "crtdefs.inc"

'/* Locale categories */

%LC_ALL         = 0
%LC_COLLATE     = 1
%LC_CTYPE       = 2
%LC_MONETARY    = 3
%LC_NUMERIC     = 4
%LC_TIME        = 5

%LC_MIN         = %LC_ALL
%LC_MAX         = %LC_TIME

'/* Locale convention structure */

#IF NOT %DEF(%LCONV_DEFINED)
%LCONV_DEFINED = 1
' // Size = 48 bytes
TYPE lconv BYTE
   decimal_point     AS ASCIIZ PTR   ' char*
   thousands_sep     AS ASCIIZ PTR   ' char*
   grouping          AS ASCIIZ PTR   ' char*
   int_curr_symbol   AS ASCIIZ PTR   ' char*
   currency_symbol   AS ASCIIZ PTR   ' char*
   mon_decimal_point AS ASCIIZ PTR   ' char*
   mon_thousands_sep AS ASCIIZ PTR   ' char*
   mon_grouping      AS ASCIIZ PTR   ' char*
   positive_sign     AS ASCIIZ PTR   ' char*
   negative_sign     AS ASCIIZ PTR   ' char*
   int_frac_digits   AS BYTE         ' char
   frac_digits       AS BYTE         ' char
   p_cs_precedes     AS BYTE         ' char
   p_sep_by_space    AS BYTE         ' char
   n_cs_precedes     AS BYTE         ' char
   n_sep_by_space    AS BYTE         ' char
   p_sign_posn       AS BYTE         ' char
   n_sign_posn       AS BYTE         ' char
END TYPE
#ENDIF

'/* ANSI: char lconv members default is CHAR_MAX which is compile time
'   dependent. Defining and using _charmax here causes CRT startup code
'   to initialize lconv members properly */

'#ifdef  _CHAR_UNSIGNED
'extern int _charmax;
'extern __inline int __dummy(void) { return _charmax; }
'#endif

'/* function prototypes */

#IF NOT %DEF(%CONFIG_LOCALE_SWT)
%CONFIG_LOCALE_SWT = 1
%ENABLE_PER_THREAD_LOCALE           = &H1
%DISABLE_PER_THREAD_LOCALE          = &H2
%ENABLE_PER_THREAD_LOCALE_GLOBAL    = &H10
%DISABLE_PER_THREAD_LOCALE_GLOBAL   = &H20
%ENABLE_PER_THREAD_LOCALE_NEW       = &H100
%DISABLE_PER_THREAD_LOCALE_NEW      = &H200
#ENDIF

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _configthreadlocale(_In_ int _Flag);
' ========================================================================================
DECLARE FUNCTION configthreadlocale_ CDECL IMPORT $CRT_DLLNAME ALIAS "_configthreadlocale" ( _
   BYVAL fkag AS LONG _                                 ' __in int flag
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP char * __cdecl setlocale(_In_ int _Category, _In_opt_z_ const char * _Locale);
' ========================================================================================
DECLARE FUNCTION setlocale CDECL IMPORT $CRT_DLLNAME ALIAS "setlocale" ( _
   BYVAL category AS LONG _                             ' __in int category
 , OPTIONAL BYREF locale AS ASCIIZ _                    ' __in_opt const char *locale
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP struct lconv * __cdecl localeconv(void);
' ========================================================================================
DECLARE FUNCTION localeconv CDECL IMPORT $CRT_DLLNAME ALIAS "localeconv" ( _
 ) AS DWORD                                             ' lconv *
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP _locale_t __cdecl _get_current_locale(void);
' ========================================================================================
DECLARE FUNCTION get_current_locale CDECL IMPORT $CRT_DLLNAME ALIAS "_get_current_locale" ( _
 ) AS QUAD                                              ' _locale_t
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP _locale_t __cdecl _create_locale(_In_ int _Category,
' _In_z_ const char * _Locale);
' ========================================================================================
DECLARE FUNCTION create_locale CDECL IMPORT $CRT_DLLNAME ALIAS "_create_locale" ( _
   BYVAL category AS LONG _                             ' __in int category
 , BYREF locale AS ASCIIZ _                             ' __in const char *locale
 ) AS QUAD                                              ' _locale_t
' ========================================================================================

' ========================================================================================
' _CRTIMP void __cdecl _free_locale(_In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE SUB free_locale CDECL IMPORT $CRT_DLLNAME ALIAS "_free_locale" ( _
   BYVAL locale AS locale_t _                           ' __in _locale_t locale
 )                                                      ' void
' ========================================================================================

'/* use _get_current_locale, _create_locale and _free_locale, instead of these functions with double leading underscore */
'_Check_return_ _CRT_OBSOLETE(_get_current_locale) _CRTIMP _locale_t __cdecl __get_current_locale(void);
'_Check_return_ _CRT_OBSOLETE(_create_locale) _CRTIMP _locale_t __cdecl __create_locale(_In_ int _Category, _In_z_ const char * _Locale);
'_CRT_OBSOLETE(_free_locale) _CRTIMP void __cdecl __free_locale(_In_opt_ _locale_t _Locale);

'/* wide function prototypes, also declared in wchar.h  */

#IF NOT %DEF(%WLOCALE_DEFINED)
    %WLOCALE_DEFINED = 1

' ========================================================================================
' *** All versions ***
DECLARE FUNCTION wsetlocale_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wsetlocale" ( _
   BYVAL category AS LONG _                             ' __in int category
 , BYREF locale AS WSTRINGZ _                           ' __in const wchar_t *locale
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

#ENDIF   ' WLOCALE_DEFINED
