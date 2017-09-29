' ########################################################################################
' Microsoft C Runtime
' File: ctype.inc
' Contents: Defines macros for character classification/conversion.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CTYPE_INC = 1

#INCLUDE ONCE "crtdefs.inc"

#IF NOT %DEF(%WEOF)
%WEOF = &HFFFF??
#ENDIF

'/* set bit masks for the possible character types */

%UPPER_          = &H1&    ' /* upper case letter */
%LOWER_          = &H2&    ' /* lower case letter */
%DIGIT_          = &H4&    ' /* digit[0-9] */
%SPACE_          = &H8&    ' /* tab, carriage return, newline, */
                           ' /* vertical tab or form feed */
%PUNCT_          = &H10&   ' /* punctuation character */
%CONTROL_        = &H20&   ' /* control character */
%BLANK_          = &H40&   ' /* space char */
%HEX_            = &H80&   ' /* hexadecimal digit */

%LEADBYTE_       = &H8000&                         ' /* multibyte leadbyte */
%ALPHA_          = &H0100& OR %UPPER_ OR %LOWER_   ' /* alphabetic character */


'/* character classification function prototypes */

#IF NOT %DEF(%CTYPE_DEFINED)
    %CTYPE_DEFINED = 1

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _isctype(_In_ int _C, _In_ int _Type);
' ========================================================================================
DECLARE FUNCTION isctype_ CDECL IMPORT $CRT_DLLNAME ALIAS "_isctype" (_
   BYVAL c AS LONG _                                    ' __in int c
 , BYVAL desc AS LONG _                                 ' __in int desc
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _isctype_l(_In_ int _C, _In_ int _Type, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION isctype_l CDECL IMPORT $CRT_DLLNAME ALIAS "_isctype_l" (_
   BYVAL c AS LONG _                                    ' __in int c
 , BYVAL desc AS LONG _                                 ' __in int desc
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_JIT_INTRINSIC _CRTIMP int __cdecl isalpha(_In_ int _C);
' ========================================================================================
DECLARE FUNCTION isalpha CDECL IMPORT $CRT_DLLNAME ALIAS "isalpha" ( _
   BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _isalpha_l(_In_ int _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION isalpha_l CDECL IMPORT $CRT_DLLNAME ALIAS "_isalpha_l" ( _
   BYVAL c AS LONG _                                    ' __in int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_JIT_INTRINSIC _CRTIMP int __cdecl isupper(_In_ int _C);
' ========================================================================================
DECLARE FUNCTION isupper CDECL IMPORT $CRT_DLLNAME ALIAS "isupper" ( _
   BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _isupper_l(_In_ int _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION isupper_l CDECL IMPORT $CRT_DLLNAME ALIAS "_isupper_l" ( _
   BYVAL c AS LONG _                                    ' __in int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_JIT_INTRINSIC _CRTIMP int __cdecl islower(_In_ int _C);
' ========================================================================================
DECLARE FUNCTION islower CDECL IMPORT $CRT_DLLNAME ALIAS "islower" ( _
   BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _islower_l(_In_ int _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION islower_l CDECL IMPORT $CRT_DLLNAME ALIAS "_islower_l" ( _
   BYVAL c AS LONG _                                    ' __in int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_JIT_INTRINSIC _CRTIMP int __cdecl isdigit(_In_ int _C);
' ========================================================================================
DECLARE FUNCTION isdigit CDECL IMPORT $CRT_DLLNAME ALIAS "isdigit" ( _
   BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _isdigit_l(_In_ int _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION isdigit_l CDECL IMPORT $CRT_DLLNAME ALIAS "_isdigit_l" ( _
   BYVAL c AS LONG _                                    ' __in int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl isxdigit(_In_ int _C);
' ========================================================================================
DECLARE FUNCTION isxdigit CDECL IMPORT $CRT_DLLNAME ALIAS "isxdigit" ( _
   BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _isxdigit_l(_In_ int _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION isxdigit_l CDECL IMPORT $CRT_DLLNAME ALIAS "_isxdigit_l" ( _
   BYVAL c AS LONG _                                    ' __in int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_JIT_INTRINSIC _CRTIMP int __cdecl isspace(_In_ int _C);
' ========================================================================================
DECLARE FUNCTION isspace CDECL IMPORT $CRT_DLLNAME ALIAS "isspace" ( _
   BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _isspace_l(_In_ int _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION isspace_l CDECL IMPORT $CRT_DLLNAME ALIAS "_isspace_l" ( _
   BYVAL c AS LONG _                                    ' __in int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl ispunct(_In_ int _C);
' ========================================================================================
DECLARE FUNCTION ispunct CDECL IMPORT $CRT_DLLNAME ALIAS "ispunct" ( _
   BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ispunct_l(_In_ int _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ispunct_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ispunct_l" ( _
   BYVAL c AS LONG _                                    ' __in int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_JIT_INTRINSIC _CRTIMP int __cdecl isalnum(_In_ int _C);
' ========================================================================================
DECLARE FUNCTION isalnum CDECL IMPORT $CRT_DLLNAME ALIAS "isalnum" ( _
   BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _isalnum_l(_In_ int _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION isalnum_l CDECL IMPORT $CRT_DLLNAME ALIAS "_isalnum_l" ( _
   BYVAL c AS LONG _                                    ' __in int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl isprint(_In_ int _C);
' ========================================================================================
DECLARE FUNCTION isprint CDECL IMPORT $CRT_DLLNAME ALIAS "isprint" ( _
   BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _isprint_l(_In_ int _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION isprint_l CDECL IMPORT $CRT_DLLNAME ALIAS "_isprint_l" ( _
   BYVAL c AS LONG _                                    ' __in int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl isgraph(_In_ int _C);
' ========================================================================================
DECLARE FUNCTION isgraph CDECL IMPORT $CRT_DLLNAME ALIAS "isgraph" ( _
   BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _isgraph_l(_In_ int _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION isgraph_l CDECL IMPORT $CRT_DLLNAME ALIAS "_isgraph_l" ( _
   BYVAL c AS LONG _                                    ' __in int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl iscntrl(_In_ int _C);
' ========================================================================================
DECLARE FUNCTION iscntrl CDECL IMPORT $CRT_DLLNAME ALIAS "iscntrl" ( _
   BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _iscntrl_l(_In_ int _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION iscntrl_l CDECL IMPORT $CRT_DLLNAME ALIAS "_iscntrl_l" ( _
   BYVAL c AS LONG _                                    ' __in int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_JIT_INTRINSIC _CRTIMP int __cdecl toupper(_In_ int _C);
' ========================================================================================
DECLARE FUNCTION toupper CDECL IMPORT $CRT_DLLNAME ALIAS "toupper" ( _
   BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_JIT_INTRINSIC _CRTIMP int __cdecl tolower(_In_ int _C);
' ========================================================================================
DECLARE FUNCTION tolower CDECL IMPORT $CRT_DLLNAME ALIAS "tolower" ( _
   BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_JIT_INTRINSIC _CRTIMP int __cdecl _tolower(_In_ int _C);
' ========================================================================================
DECLARE FUNCTION tolower_ CDECL IMPORT $CRT_DLLNAME ALIAS "_tolower" ( _
   BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _tolower_l(_In_ int _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION tolower_l CDECL IMPORT $CRT_DLLNAME ALIAS "_tolower_l" ( _
   BYVAL c AS LONG _                                    ' __in int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_JIT_INTRINSIC _CRTIMP int __cdecl _toupper(_In_ int _C);
' ========================================================================================
DECLARE FUNCTION toupper_ CDECL IMPORT $CRT_DLLNAME ALIAS "_toupper" ( _
   BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _toupper_l(_In_ int _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION toupper_l CDECL IMPORT $CRT_DLLNAME ALIAS "_toupper_l" ( _
   BYVAL c AS LONG _                                    ' __in int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl __isascii(_In_ int _C);
' ========================================================================================
DECLARE FUNCTION isascii__ CDECL IMPORT $CRT_DLLNAME ALIAS "__isascii" ( _
   BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl __toascii(_In_ int _C);
' ========================================================================================
DECLARE FUNCTION toascii__ CDECL IMPORT $CRT_DLLNAME ALIAS "__toascii" ( _
   BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl __iscsymf(_In_ int _C);
' ========================================================================================
DECLARE FUNCTION iscsymf__ CDECL IMPORT $CRT_DLLNAME ALIAS "__iscsymf" ( _
   BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl __iscsym(_In_ int _C);
' ========================================================================================
DECLARE FUNCTION iscsym__ CDECL IMPORT $CRT_DLLNAME ALIAS "__iscsym" ( _
   BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' int
' ========================================================================================

#ENDIF   ' _CTYPE_DEFINED

#IF NOT %DEF(%WCTYPE_DEFINED)
    %WCTYPE_DEFINED = 1

'/* wide function prototypes, also declared in wchar.h  */

'/* character classification function prototypes */

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl iswalpha(_In_ wint_t _C);
' ========================================================================================
DECLARE FUNCTION iswalpha CDECL IMPORT $CRT_DLLNAME ALIAS "iswalpha" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _iswalpha_l(_In_ wint_t _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION iswalpha_l CDECL IMPORT $CRT_DLLNAME ALIAS "_iswalpha_l" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl iswupper(_In_ wint_t _C);
' ========================================================================================
DECLARE FUNCTION iswupper CDECL IMPORT $CRT_DLLNAME ALIAS "iswupper" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _iswupper_l(_In_ wint_t _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION iswupper_l CDECL IMPORT $CRT_DLLNAME ALIAS "_iswupper_l" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl iswlower(_In_ wint_t _C);
' ========================================================================================
DECLARE FUNCTION iswlower CDECL IMPORT $CRT_DLLNAME ALIAS "iswlower" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _iswlower_l(_In_ wint_t _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION iswlower_l CDECL IMPORT $CRT_DLLNAME ALIAS "_iswlower_l" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl iswdigit(_In_ wint_t _C);
' ========================================================================================
DECLARE FUNCTION iswdigit CDECL IMPORT $CRT_DLLNAME ALIAS "iswdigit" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _iswdigit_l(_In_ wint_t _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION iswdigit_l CDECL IMPORT $CRT_DLLNAME ALIAS "_iswdigit_l" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl iswxdigit(_In_ wint_t _C);
' ========================================================================================
DECLARE FUNCTION iswxdigit CDECL IMPORT $CRT_DLLNAME ALIAS "iswxdigit" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _iswxdigit_l(_In_ wint_t _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION iswxdigit_l CDECL IMPORT $CRT_DLLNAME ALIAS "_iswxdigit_l" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl iswspace(_In_ wint_t _C);
' ========================================================================================
DECLARE FUNCTION iswspace CDECL IMPORT $CRT_DLLNAME ALIAS "iswspace" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _iswspace_l(_In_ wint_t _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION iswspace_l CDECL IMPORT $CRT_DLLNAME ALIAS "_iswspace_l" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl iswpunct(_In_ wint_t _C);
' ========================================================================================
DECLARE FUNCTION iswpunct CDECL IMPORT $CRT_DLLNAME ALIAS "iswpunct" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _iswpunct_l(_In_ wint_t _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION iswpunct_l CDECL IMPORT $CRT_DLLNAME ALIAS "_iswpunct_l" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl iswalnum(_In_ wint_t _C);
' ========================================================================================
DECLARE FUNCTION iswalnum CDECL IMPORT $CRT_DLLNAME ALIAS "iswalnum" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _iswalnum_l(_In_ wint_t _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION iswalnum_l CDECL IMPORT $CRT_DLLNAME ALIAS "_iswalnum_l" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl iswprint(_In_ wint_t _C);
' ========================================================================================
DECLARE FUNCTION iswprint CDECL IMPORT $CRT_DLLNAME ALIAS "iswprint" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _iswprint_l(_In_ wint_t _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION iswprint_l CDECL IMPORT $CRT_DLLNAME ALIAS "_iswprint_l" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl iswgraph(_In_ wint_t _C);
' ========================================================================================
DECLARE FUNCTION iswgraph CDECL IMPORT $CRT_DLLNAME ALIAS "iswgraph" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _iswgraph_l(_In_ wint_t _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION iswgraph_l CDECL IMPORT $CRT_DLLNAME ALIAS "_iswgraph_l" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl iswcntrl(_In_ wint_t _C);
' ========================================================================================
DECLARE FUNCTION iswcntrl CDECL IMPORT $CRT_DLLNAME ALIAS "iswcntrl" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _iswcntrl_l(_In_ wint_t _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION iswcntrl_l CDECL IMPORT $CRT_DLLNAME ALIAS "_iswcntrl_l" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl iswascii(_In_ wint_t _C);
' ========================================================================================
DECLARE FUNCTION iswascii CDECL IMPORT $CRT_DLLNAME ALIAS "iswascii" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl isleadbyte(_In_ int _C);
' ========================================================================================
DECLARE FUNCTION isleadbyte CDECL IMPORT $CRT_DLLNAME ALIAS "isleadbyte" ( _
   BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _isleadbyte_l(_In_ int _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION isleadbyte_l CDECL IMPORT $CRT_DLLNAME ALIAS "_isleadbyte_l" ( _
   BYVAL c AS LONG _                                    ' __in int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP wint_t __cdecl towupper(_In_ wint_t _C);
' ========================================================================================
DECLARE FUNCTION towupper CDECL IMPORT $CRT_DLLNAME ALIAS "towupper" ( _
   BYVAL c AS WORD _                                    ' __in wchar_t c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP wint_t __cdecl _towupper_l(_In_ wint_t _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION towupper_l CDECL IMPORT $CRT_DLLNAME ALIAS "_towupper_l" ( _
   BYVAL c AS WORD _                                    ' __in wchar_t c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP wint_t __cdecl towlower(_In_ wint_t _C);
' ========================================================================================
DECLARE FUNCTION towlower CDECL IMPORT $CRT_DLLNAME ALIAS "towlower" ( _
   BYVAL c AS WORD _                                    ' __in wchar_t c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP wint_t __cdecl _towlower_l(_In_ wint_t _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION towlower_l CDECL IMPORT $CRT_DLLNAME ALIAS "_towlower_l" ( _
   BYVAL c AS WORD _                                    ' __in wchar_t c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
'_Check_return_ _CRTIMP int __cdecl iswctype(_In_ wint_t _C, _In_ wctype_t _Type);
' ========================================================================================
DECLARE FUNCTION iswctype CDECL IMPORT $CRT_DLLNAME ALIAS "iswctype" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 , BYVAL desc AS WORD _                                 ' __in wctype_t desc
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
'_Check_return_ _CRTIMP int __cdecl _iswctype_l(_In_ wint_t _C, _In_ wctype_t _Type, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION iswctype_l CDECL IMPORT $CRT_DLLNAME ALIAS "_iswctype_l" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 , BYVAL desc AS WORD _                                 ' __in wctype_t desc
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl __iswcsymf(_In_ wint_t _C);
' ========================================================================================
DECLARE FUNCTION iswcsymf__ CDECL IMPORT $CRT_DLLNAME ALIAS "__iswcsymf" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _iswcsymf_l(_In_ wint_t _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION iswcsymf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_iswcsymf_l" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl __iswcsym(_In_ wint_t _C);
' ========================================================================================
DECLARE FUNCTION iswcsym__ CDECL IMPORT $CRT_DLLNAME ALIAS "__iswcsym" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _iswcsym_l(_In_ wint_t _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION iswcsym_l CDECL IMPORT $CRT_DLLNAME ALIAS "_iswcsym_l" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRT_OBSOLETE(iswctype) _CRTIMP int __cdecl is_wctype(_In_ wint_t _C, _In_ wctype_t _Type);
' ========================================================================================
DECLARE FUNCTION is_wctype CDECL IMPORT $CRT_DLLNAME ALIAS "is_wctype" ( _
   BYVAL c AS WORD _                                    ' wint_t c
 ) AS LONG                                              ' int
' ========================================================================================

#ENDIF   ' _WCTYPE_DEFINED

'/* the character classification macro definitions */

'#ifndef _CTYPE_DISABLE_MACROS

'/*
' * Maximum number of bytes in multi-byte character in the current locale
' * (also defined in stdlib.h).
' */
'#ifndef MB_CUR_MAX

'#if defined(_CRT_DISABLE_PERFCRIT_LOCKS) && !defined(_DLL)
'#define MB_CUR_MAX __mb_cur_max
'#else
'#define MB_CUR_MAX ___mb_cur_max_func()
'#endif
'#if !defined(_M_CEE_PURE)
'/* No data exports in pure code */
'_CRTIMP extern int __mb_cur_max;
'#else
'#define __mb_cur_max (___mb_cur_max_func())
'#endif /* !defined(_M_CEE_PURE) */
'_CRTIMP int __cdecl ___mb_cur_max_func(void);
'_CRTIMP int __cdecl ___mb_cur_max_l_func(_locale_t);
'#endif  /* MB_CUR_MAX */

#IF NOT %DEF(%MB_CUR_MAX)
    %MB_CUR_MAX = 1

' ========================================================================================
' *** All versions ***
' ========================================================================================
FUNCTION mb_cur_max__ CDECL () AS LONG
   LOCAL hLib AS DWORD
   LOCAL pmbcurmax AS LONG PTR
   CALL LoadLibrary($CRT_DLLNAME) TO hLib
   IF hLib THEN
      pmbcurmax = GetProcAddress(hLib, "__mb_cur_max")
      IF pmbcurmax THEN FUNCTION = @pmbcurmax
      CALL FreeLibrary(hLib)
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
FUNCTION get_mb_cur_max_func CDECL () AS LONG
   LOCAL hLib AS DWORD
   LOCAL pbcurmax AS LONG
   LOCAL pmbcurmaxfunc AS DWORD
   CALL LoadLibrary($CRT_DLLNAME) TO hLib
   IF hLib THEN
      pmbcurmaxfunc = GetProcAddress(hLib, "___mb_cur_max_func")
      IF pmbcurmaxfunc THEN
         CALL DWORD pmbcurmaxfunc USING get_mb_cur_max_func() TO pbcurmax
         FUNCTION = pbcurmax
      END IF
      CALL FreeLibrary(hLib)
   END IF
END FUNCTION

#ENDIF   '  /* MB_CUR_MAX */

' ========================================================================================
' _CRTIMP int __cdecl ___mb_cur_max_func(void);
' ========================================================================================
DECLARE FUNCTION mb_cur_max_func___ CDECL IMPORT $CRT_DLLNAME ALIAS "___mb_cur_max_func" ( _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP int __cdecl ___mb_cur_max_l_func(_locale_t);
' ========================================================================================
DECLARE FUNCTION mb_cur_max_l_func___ CDECL IMPORT $CRT_DLLNAME ALIAS "___mb_cur_max_l_func" ( _
   BYVAL locale AS locale_t _                           ' _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================
