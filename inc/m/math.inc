' ########################################################################################
' Microsoft C Runtime
' File: math.inc
' Contents: Definitions and declarations for the C math library.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MATH_INC = 1

#INCLUDE ONCE "crtdefs.inc"

'/* Definition of _exception struct - this struct is passed to the matherr
' * routine when a floating point exception is detected
' */

#IF NOT %DEF(%EXCEPTION_DEFINED)
%EXCEPTION_DEFINED = 1
' // Size = 32 bytes
TYPE tagException DWORD
   type   AS LONG         ' char /* exception type - see below */
   name   AS ASCIIZ PTR   ' char * /* name of function where error occured */
   arg1   AS DOUBLE       ' double /* first argument to function */
   arg2   AS DOUBLE       ' double /* second argument (if any) to function */
   retval AS DOUBLE       ' double /* value to be returned by function */
END TYPE
#ENDIF


'/* Definition of a _complex struct to be used by those who use cabs and
' * want type checking on their argument
' */

#IF NOT %DEF(%COMPLEX_DEFINED)
%COMPLEX_DEFINED = 1
' // Size = 16 bytes
TYPE tagComplex DWORD
   x AS DOUBLE   ' real part
   y AS DOUBLE   ' imaginary part
END TYPE
#ENDIF

'#define _COMPLEX_DEFINED
'#endif


'/* Constant definitions for the exception type passed in the _exception struct
' */

%DOMAIN_    = 1   ' /* argument domain error */
%SING_      = 2   ' /* argument singularity */
%OVERFLOW_  = 3   ' /* overflow range error */
%UNDERFLOW_ = 4   ' /* underflow range error */
%TLOSS_     = 5   ' /* total loss of precision */
%PLOSS_     = 6   ' /* partial loss of precision */

%EDOM       = 33
%ERANGE     = 34

'/* Definitions of _HUGE and HUGE_VAL - respectively the XENIX and ANSI names
' * for a value returned in case of error by a number of the floating point
' * math routines
' */
'#ifndef __assembler /* Protect from assembler */
'#if !defined(_M_CEE_PURE)
'_CRTIMP extern double _HUGE;
'#else
'const double _HUGE = System::Double::PositiveInfinity;
'#endif /* !defined(_M_CEE_PURE) */
'#endif  /* __assembler */

FUNCTION HUGE_VAL () AS DOUBLE
   LOCAL hLib AS DWORD
   LOCAL phuge AS DOUBLE PTR
   hLib = LoadLibrary($CRT_DLLNAME)
   IF hLib THEN
      phuge = GetProcAddress(hLib, "_HUGE")
      IF phuge THEN FUNCTION = @phuge
      FreeLibrary hLib
   END IF
END FUNCTION

'#define HUGE_VAL _HUGE

'/* Function prototypes */

#IF NOT %DEF(%CRT_ABS_DEFINED)
    %CRT_ABS_DEFINED = 1

' ========================================================================================
' *** All versions ***
' int __cdecl abs(_In_ int _X);
' ========================================================================================
DECLARE FUNCTION abs_ CDECL IMPORT $CRT_DLLNAME ALIAS "abs" ( _
   BYVAL n AS LONG _                                    ' __in int n
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' long __cdecl labs(_In_ long _X);
' ========================================================================================
DECLARE FUNCTION labs_ CDECL IMPORT $CRT_DLLNAME ALIAS "labs" ( _
   BYVAL n AS LONG _                                    ' __in long n
 ) AS LONG                                              ' long
' ========================================================================================

#ENDIF   ' CRT_ABS_DEFINED

' ========================================================================================
' *** All versions ***
' double  __cdecl acos(_In_ double _X);
' ========================================================================================
DECLARE FUNCTION acos_ CDECL IMPORT $CRT_DLLNAME ALIAS "acos" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' double  __cdecl asin(_In_ double _X);
' ========================================================================================
DECLARE FUNCTION asin_ CDECL IMPORT $CRT_DLLNAME ALIAS "asin" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' double  __cdecl atan(_In_ double _X);
' ========================================================================================
DECLARE FUNCTION atan_ CDECL IMPORT $CRT_DLLNAME ALIAS "atan" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' double  __cdecl atan2(_In_ double _Y, _In_ double _X);
' ========================================================================================
DECLARE FUNCTION atan2_ CDECL IMPORT $CRT_DLLNAME ALIAS "atan2" ( _
   BYVAL y AS DOUBLE _                                  ' __in double y
 , BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

#IF NOT %DEF(%SIGN_DEFINED)
    %SIGN_DEFINED = 1

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP double __cdecl _copysign (_In_ double _Number, _In_ double _Sign);
' ========================================================================================
DECLARE FUNCTION copysign_ CDECL IMPORT $CRT_DLLNAME ALIAS "_copysign" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 , BYVAL y AS DOUBLE _                                  ' __in double y
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP double __cdecl _chgsign (_In_ double _X);
' ========================================================================================
DECLARE FUNCTION chgsign_ CDECL IMPORT $CRT_DLLNAME ALIAS "_chgsign" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

#ENDIF   ' SIGN_DEFINED

' ========================================================================================
' *** All versions ***
' double  __cdecl cos(_In_ double _X);
' ========================================================================================
DECLARE FUNCTION cos_ CDECL IMPORT $CRT_DLLNAME ALIAS "cos" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' double  __cdecl cosh(_In_ double _X);
' ========================================================================================
DECLARE FUNCTION cosh_ CDECL IMPORT $CRT_DLLNAME ALIAS "cosh" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' double  __cdecl exp(_In_ double _X);
' ========================================================================================
DECLARE FUNCTION exp_ CDECL IMPORT $CRT_DLLNAME ALIAS "exp" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRT_JIT_INTRINSIC double  __cdecl fabs(_In_ double _X);
' ========================================================================================
DECLARE FUNCTION fabs_ CDECL IMPORT $CRT_DLLNAME ALIAS "fabs" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' double  __cdecl fmod(_In_ double _X, _In_ double _Y);
' ========================================================================================
DECLARE FUNCTION fmod_ CDECL IMPORT $CRT_DLLNAME ALIAS "fmod" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 , BYVAL y AS DOUBLE _                                  ' __in double y
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' double  __cdecl log(_In_ double _X);
' ========================================================================================
DECLARE FUNCTION log_ CDECL IMPORT $CRT_DLLNAME ALIAS "log" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' double  __cdecl log10(_In_ double _X);
' ========================================================================================
DECLARE FUNCTION log10_ CDECL IMPORT $CRT_DLLNAME ALIAS "log10" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' double  __cdecl pow(_In_ double _X, _In_ double _Y);
' ========================================================================================
DECLARE FUNCTION pow_ CDECL IMPORT $CRT_DLLNAME ALIAS "pow" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 , BYVAL y AS DOUBLE _                                  ' __in double y
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' double  __cdecl sin(_In_ double _X);
' ========================================================================================
DECLARE FUNCTION sin_ CDECL IMPORT $CRT_DLLNAME ALIAS "sin" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' double  __cdecl sinh(_In_ double _X);
' ========================================================================================
DECLARE FUNCTION sinh_ CDECL IMPORT $CRT_DLLNAME ALIAS "sinh" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' double  __cdecl tan(_In_ double _X);
' ========================================================================================
DECLARE FUNCTION tan_ CDECL IMPORT $CRT_DLLNAME ALIAS "tan" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' double  __cdecl tanh(_In_ double _X);
' ========================================================================================
DECLARE FUNCTION tanh_ CDECL IMPORT $CRT_DLLNAME ALIAS "tanh" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' double  __cdecl sqrt(_In_ double _X);
' ========================================================================================
DECLARE FUNCTION sqrt_ CDECL IMPORT $CRT_DLLNAME ALIAS "sqrt" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

#IF NOT %DEF(%CRT_ATOF_DEFINED)
    %CRT_ATOF_DEFINED = 1

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP double  __cdecl atof(_In_z_ const char *_String);
' ========================================================================================
DECLARE FUNCTION atof_ CDECL IMPORT $CRT_DLLNAME ALIAS "atof" ( _
   BYREF str AS ASCIIZ _                                ' __in const char *str
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP double  __cdecl _atof_l(_In_z_ const char *_String, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION atof_l CDECL IMPORT $CRT_DLLNAME ALIAS "_atof_l" ( _
   BYREF str AS ASCIIZ _                                ' __in const char *str
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt locale _locale_t
 ) AS DOUBLE                                            ' double
' ========================================================================================

#ENDIF   ' CRT_ATOF_DEFINED

' ========================================================================================
' *** All versions ***
' _CRTIMP double  __cdecl _cabs(_In_ struct _complex _Complex_value);
' ========================================================================================
DECLARE FUNCTION cabs_ CDECL IMPORT $CRT_DLLNAME ALIAS "_cabs" ( _
   BYVAL z AS tagComplex _                              ' __in struct _complex z
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP double  __cdecl ceil(_In_ double _X);
' ========================================================================================
DECLARE FUNCTION ceil_ CDECL IMPORT $CRT_DLLNAME ALIAS "ceil" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP double  __cdecl floor(_In_ double _X);
' ========================================================================================
DECLARE FUNCTION floor_ CDECL IMPORT $CRT_DLLNAME ALIAS "floor" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP double  __cdecl frexp(_In_ double _X, _Out_ int * _Y);
' ========================================================================================
DECLARE FUNCTION frexp_ CDECL IMPORT $CRT_DLLNAME ALIAS "frexp" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 , BYREF expptr AS LONG _                               ' __out int *expptr
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP double  __cdecl _hypot(_In_ double _X, _In_ double _Y);
' ========================================================================================
DECLARE FUNCTION hypot_ CDECL IMPORT $CRT_DLLNAME ALIAS "_hypot" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 , BYVAL y AS DOUBLE _                                  ' __in double y
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP double  __cdecl _j0(_In_ double _X );
' ========================================================================================
DECLARE FUNCTION j0_ CDECL IMPORT $CRT_DLLNAME ALIAS "_j0" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP double  __cdecl _j1(_In_ double _X );
' ========================================================================================
DECLARE FUNCTION j1_ CDECL IMPORT $CRT_DLLNAME ALIAS "_j1" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP double  __cdecl _jn(int _X, _In_ double _Y);
' ========================================================================================
DECLARE FUNCTION jn_ CDECL IMPORT $CRT_DLLNAME ALIAS "_jn" ( _
   BYVAL n AS LONG _                                    ' __in int n
 , BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP double  __cdecl ldexp(_In_ double _X, _In_ int _Y);
' ========================================================================================
DECLARE FUNCTION ldexp_ CDECL IMPORT $CRT_DLLNAME ALIAS "ldexp" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 , BYVAL exp AS LONG _                                  ' __in int exp
 ) AS DOUBLE                                            ' double
' ========================================================================================

'#ifndef _CRT_MATHERR_DEFINED
'#define _CRT_MATHERR_DEFINED
'#if defined(MRTDLL) || defined(_M_CEE_PURE)
' int     __CRTDECL _matherr(_Inout_ struct _exception * _Except);
'#else
' int     __cdecl _matherr(_Inout_ struct _exception * _Except);
'#endif
'#endif

' ========================================================================================
' *** All versions ***
' _CRTIMP double  __cdecl modf(_In_ double _X, _Out_ double * _Y);
' ========================================================================================
DECLARE FUNCTION modf_ CDECL IMPORT $CRT_DLLNAME ALIAS "modf" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 , BYREF intptr AS DOUBLE _                             ' __out double *intptr
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP double  __cdecl _y0(_In_ double _X);
' ========================================================================================
DECLARE FUNCTION y0_ CDECL IMPORT $CRT_DLLNAME ALIAS "_y0" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP double  __cdecl _y1(_In_ double _X);
' ========================================================================================
DECLARE FUNCTION y1_ CDECL IMPORT $CRT_DLLNAME ALIAS "_y1" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP double  __cdecl _yn(_In_ int _X, _In_ double _Y);
' ========================================================================================
DECLARE FUNCTION yn_ CDECL IMPORT $CRT_DLLNAME ALIAS "_yn" ( _
   BYVAL n AS  LONG _                                   ' __in int n
 , BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

'#if defined(_USE_MATH_DEFINES) && !defined(_MATH_DEFINES_DEFINED)
'#define _MATH_DEFINES_DEFINED

#IF %DEF(%USE_MATH_DEFINES) AND NOT %DEF(%MATH_DEFINES_DEFINED)
    %MATH_DEFINES_DEFINED = 1

'/* Define _USE_MATH_DEFINES before including math.h to expose these macro
' * definitions for common math constants.  These are placed under an #ifdef
' * since these commonly-defined names are not part of the C/C++ standards.
' */

'/* Definitions of useful mathematical constants
' * M_E        - e
' * M_LOG2E    - log2(e)
' * M_LOG10E   - log10(e)
' * M_LN2      - ln(2)
' * M_LN10     - ln(10)
' * M_PI       - pi
' * M_PI_2     - pi/2
' * M_PI_4     - pi/4
' * M_1_PI     - 1/pi
' * M_2_PI     - 2/pi
' * M_2_SQRTPI - 2/sqrt(pi)
' * M_SQRT2    - sqrt(2)
' * M_SQRT1_2  - 1/sqrt(2)
' */

MACRO M_E        = 2.71828182845904523536
MACRO M_LOG2E    = 1.44269504088896340736
MACRO M_LOG10E   = 0.434294481903251827651
MACRO M_LN2      = 0.693147180559945309417
MACRO M_LN10     = 2.30258509299404568402
MACRO M_PI       = 3.14159265358979323846
MACRO M_PI_2     = 1.57079632679489661923
MACRO M_PI_4     = 0.785398163397448309616
MACRO M_1_PI     = 0.318309886183790671538
MACRO M_2_PI     = 0.636619772367581343076
MACRO M_2_SQRTPI = 1.12837916709551257390
MACRO M_SQRT2    = 1.41421356237309504880
MACRO M_SQRT1_2  = 0.707106781186547524401

#ENDIF   ' /* _USE_MATH_DEFINES */
