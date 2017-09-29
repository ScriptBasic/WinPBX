' ########################################################################################
' Microsoft C Runtime
' File: limits.inc
' Contents: defines for a number of implementation dependent values which are commonly
' used in C programs. [ANSI]
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LIMITS_INC = 1

#INCLUDE ONCE "crtdefs.inc"

%CHAR_BIT     = 8           ' /* number of bits in a char */
%SCHAR_MIN    = -128%       ' /* minimum signed char value */
%SCHAR_MAX    = 127?        ' /* maximum signed char value */
%UCHAR_MAX    = &Hff?       ' /* maximum unsigned char value */

#IF NOT %DEF(%CHAR_UNSIGNED)
%CHAR_MIN     = %SCHAR_MIN  ' /* mimimum char value */
%CHAR_MAX     = %SCHAR_MAX  ' /* maximum char value */
#ELSE
%CHAR_MIN     = 0
%CHAR_MAX     = %UCHAR_MAX
#ENDIF   ' /* _CHAR_UNSIGNED */

%MB_LEN_MAX   = 5                   ' /* max. # bytes in multibyte char */
%SHRT_MIN     = -32768%             ' /* minimum (signed) short value */
%SHRT_MAX     = 32767%              ' /* maximum (signed) short value */
%USHRT_MAX    = &Hffff??            ' /* maximum unsigned short value */
%INT_MIN      = -2147483647& - 1    ' /* minimum (signed) int value */
%INT_MAX      = 2147483647&         ' /* maximum (signed) int value */
%UINT_MAX     = &Hffffffff???       ' /* maximum unsigned int value */
%LONG_MIN     = -2147483647& - 1    ' /* minimum (signed) long value */
%LONG_MAX     = 2147483647&         ' /* maximum (signed) long value */
%ULONG_MAX    = &Hffffffff???       ' /* maximum unsigned long value */
%LLONG_MAX    = 9223372036854775807&&   ' /* maximum signed long long int value */
%LLONG_MIN    = -9223372036854775807&& - 1   '  /* minimum signed long long int value */
'#define ULLONG_MAX    0xffffffffffffffffui64       /* maximum unsigned long long int value */

'#ifndef SIZE_MAX
'#ifdef _WIN64
'#define SIZE_MAX _UI64_MAX
'#else
'#define SIZE_MAX UINT_MAX
%SIZE_MAX = %UINT_MAX
'#endif
'#endif

'#if __STDC_WANT_SECURE_LIB__
'/* While waiting to the C standard committee to finalize the decision on RSIZE_MAX and rsize_t,
' * we define RSIZE_MAX as SIZE_MAX
' */
'#ifndef RSIZE_MAX
'#define RSIZE_MAX SIZE_MAX
%RSIZE_MAX = %SIZE_MAX
'#endif
'#endif
