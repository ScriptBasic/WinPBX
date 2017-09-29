' ########################################################################################
' Microsoft C Runtime
' File: float.inc
' Contents: This file contains defines for a number of implementation dependent values
' which are commonly used by sophisticated numerical (floating point) programs. [ANSI]
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%FLOAT_INC = 1

#INCLUDE ONCE "crtdefs.inc"

%DBL_DIG              = 15                      ' /* # of decimal digits of precision */
MACRO DBL_EPSILON     = 2.2204460492503131e-016 ' /* smallest such that 1.0+DBL_EPSILON != 1.0 */
%DBL_MANT_DIG         = 53                      ' /* # of bits in mantissa */
MACRO DBL_MAX         = 1.7976931348623158e+308 ' /* max value */
%DBL_MAX_10_EXP       = 308                     ' /* max decimal exponent */
%DBL_MAX_EXP          = 1024                    ' /* max binary exponent */
MACRO DBL_MIN         = 2.2250738585072014e-308 ' /* min positive value */
%DBL_MIN_10_EXP       = -307                    ' /* min decimal exponent */
%DBL_MIN_EXP          = -1021                   ' /* min binary exponent */
%DBL_RADIX            = 2                       ' /* exponent radix */
%DBL_ROUNDS           = 1                       ' /* addition rounding: near */

%FLT_DIG              = 6                       ' /* # of decimal digits of precision */
MACRO FLT_EPSILON     = 1.192092896e-07         ' /* smallest such that 1.0+FLT_EPSILON != 1.0 */
%FLT_GUARD            = 0
%FLT_MANT_DIG         = 24                      ' /* # of bits in mantissa */
MACRO FLT_MAX         = 3.402823466e+38         ' /* max value */
%FLT_MAX_10_EXP       = 38                      ' /* max decimal exponent */
%FLT_MAX_EXP          = 128                     ' /* max binary exponent */
MACRO FLT_MIN         = 1.175494351e-38         ' /* min positive value */
%FLT_MIN_10_EXP       = -37                     ' /* min decimal exponent */
%FLT_MIN_EXP          = -125                    ' /* min binary exponent */
%FLT_NORMALIZE        = 0
%FLT_RADIX            = 2                       ' /* exponent radix */
%FLT_ROUNDS           = 1                       ' /* addition rounding: near */

%LDBL_DIG             = %DBL_DIG                 ' /* # of decimal digits of precision */
MACRO LDBL_EPSILON    = DBL_EPSILON              ' /* smallest such that 1.0+L= %DBL_EPSILON != 1.0 */
%LDBL_MANT_DIG        = %DBL_MANT_DIG            ' /* # of bits in mantissa */
MACRO LDBL_MAX        = DBL_MAX                  ' /* max value */
%LDBL_MAX_10_EXP      = %DBL_MAX_10_EXP          ' /* max decimal exponent */
%LDBL_MAX_EXP         = %DBL_MAX_EXP             ' /* max binary exponent */
MACRO LDBL_MIN        = DBL_MIN                  ' /* min positive value */
%LDBL_MIN_10_EXP      = %DBL_MIN_10_EXP          ' /* min decimal exponent */
%LDBL_MIN_EXP         = %DBL_MIN_EXP             ' /* min binary exponent */
%LDBL_RADIX           = %DBL_RADIX               ' /* exponent radix */
%LDBL_ROUNDS          = %DBL_ROUNDS              ' /* addition rounding: near */

'/* Function prototypes */

'/* Reading or writing the floating point control/status words is not supported in managed code */

' ========================================================================================
' *** All versions ***
' _CRT_MANAGED_FP_DEPRECATE _CRTIMP unsigned int __cdecl _clearfp(void);
' ========================================================================================
DECLARE FUNCTION clearfp_ CDECL IMPORT $CRT_DLLNAME ALIAS "_clearfp" ( _
 ) AS DWORD                                             ' unsigned int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRT_MANAGED_FP_DEPRECATE _CRT_INSECURE_DEPRECATE(_controlfp_s)
' _CRTIMP unsigned int __cdecl _controlfp(_In_ unsigned int _NewValue,_In_ unsigned int _Mask);
' ========================================================================================
DECLARE FUNCTION controlfp_ CDECL IMPORT $CRT_DLLNAME ALIAS "_controlfp" ( _
   BYVAL new AS DWORD _                                 ' __in unsigned int new
 , BYVAL mask AS DWORD _                                ' __in unsigned int mask
 ) AS DWORD                                             ' __in unsigned int
' ========================================================================================

' ========================================================================================
' _CRT_MANAGED_FP_DEPRECATE _CRTIMP void __cdecl _set_controlfp(
'_In_ unsigned int _NewValue, _In_ unsigned int _Mask);
' ========================================================================================
DECLARE SUB set_controlfp CDECL IMPORT $CRT_DLLNAME ALIAS "_set_controlfp" ( _
   BYVAL newControl AS DWORD _                          ' __in unsigned int new
 , BYVAL mask AS DWORD _                                ' __in unsigned int mask
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' _CRT_MANAGED_FP_DEPRECATE _CRTIMP errno_t __cdecl _controlfp_s(
' _Out_opt_ unsigned int *_CurrentState, _In_ unsigned int _NewValue, _In_ unsigned int _Mask);
' ========================================================================================
DECLARE FUNCTION controlfp_s CDECL IMPORT $CRT_DLLNAME ALIAS "_controlfp_s" ( _
   BYVAL currentControl AS DWORD _                      ' __out unsigned int *currentControl
 , BYVAL newControl AS DWORD _                          ' __in unsigned int newControl
 , BYVAL mask AS DWORD _                                ' __in unsigned int mask
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRT_MANAGED_FP_DEPRECATE _CRTIMP unsigned int __cdecl _statusfp(void);
' ========================================================================================
DECLARE FUNCTION statusfp_ CDECL IMPORT $CRT_DLLNAME ALIAS "_statusfp" ( _
 ) AS DWORD                                             ' unsigned int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRT_MANAGED_FP_DEPRECATE _CRTIMP void __cdecl _fpreset(void);
' ========================================================================================
DECLARE SUB fpreset_ CDECL IMPORT $CRT_DLLNAME ALIAS "_fpreset" ()
' ========================================================================================

'/*
' * Abstract User Status Word bit definitions
' */

%SW_INEXACT     = &H00000001???              ' /* inexact (precision) */
%SW_UNDERFLOW   = &H00000002???              ' /* underflow */
%SW_OVERFLOW    = &H00000004???              ' /* overflow */
%SW_ZERODIVIDE  = &H00000008???              ' /* zero divide */
%SW_INVALID     = &H00000010???              ' /* invalid */
%SW_DENORMAL    = &H00080000???              ' /* denormal status bit */


'/*
' * New Control Bit that specifies the ambiguity in control word.
' */

%EM_AMBIGUIOUS  = &H80000000???            ' /* for backwards compatibility old spelling */
%EM_AMBIGUOUS   = &H80000000???

'/*
' * Abstract User Control Word Mask and bit definitions
' */

%MCW_EM         = &H0008001f???              ' /* interrupt Exception Masks */
%EM_INEXACT     = &H00000001???              ' /*   inexact (precision) */
%EM_UNDERFLOW   = &H00000002???              ' /*   underflow */
%EM_OVERFLOW    = &H00000004???              ' /*   overflow */
%EM_ZERODIVIDE  = &H00000008???              ' /*   zero divide */
%EM_INVALID     = &H00000010???              ' /*   invalid */
%EM_DENORMAL    = &H00080000???              ' /* denormal exception mask (_control87 only) */

%MCW_RC         = &H00000300???              ' /* Rounding Control */
%RC_NEAR        = &H00000000???              ' /*   near */
%RC_DOWN        = &H00000100???              ' /*   down */
%RC_UP          = &H00000200???              ' /*   up */
%RC_CHOP        = &H00000300???              ' /*   chop */

'/*
' * i386 specific definitions
' */
%MCW_PC         = &H00030000???              ' /* Precision Control */
%PC_64          = &H00000000???              ' /*    64 bits */
%PC_53          = &H00010000???              ' /*    53 bits */
%PC_24          = &H00020000???              ' /*    24 bits */

%MCW_IC         = &H00040000???              ' /* Infinity Control */
%IC_AFFINE      = &H00040000???              ' /*   affine */
%IC_PROJECTIVE  = &H00000000???              ' /*   projective */

'/*
' * RISC specific definitions
' */

%MCW_DN         = &H03000000???                  ' /* Denormal Control */
%DN_SAVE        = &H00000000???                  ' /*   save denormal results and operands */
%DN_FLUSH       = &H01000000???                  ' /*   flush denormal results and operands to zero */
%DN_FLUSH_OPERANDS_SAVE_RESULTS = &H02000000???  ' /*   flush operands to zero and save results */
%DN_SAVE_OPERANDS_FLUSH_RESULTS = &H03000000???  ' /*   save operands and flush results to zero */

'/* initial Control Word value */

%CW_DEFAULT = %RC_NEAR + %PC_53 + %EM_INVALID + %EM_ZERODIVIDE + %EM_OVERFLOW + %EM_UNDERFLOW + %EM_INEXACT + %EM_DENORMAL

' ========================================================================================
' *** All versions ***
' _CRT_MANAGED_FP_DEPRECATE _CRTIMP unsigned int __cdecl _control87(
' _In_ unsigned int _NewValue,_In_ unsigned int _Mask);
' ========================================================================================
DECLARE FUNCTION control87_ CDECL IMPORT $CRT_DLLNAME ALIAS "_control87" ( _
   BYVAL new AS DWORD _                                 ' __in unsigned int new
 , BYVAL mask AS DWORD _                                ' __in unsigned int mask
 ) AS DWORD                                             ' unsigned int
' ========================================================================================

'/* Global variable holding floating point error code */

'#if     defined(_MT) || defined(_DLL)
'_Check_return_ _CRTIMP extern int * __cdecl __fpecode(void);
'#define _fpecode        (*__fpecode())
'#else   /* ndef _MT && ndef _DLL */
'extern int _fpecode;
'#endif  /* _MT || _DLL */

' *** All versions ***
FUNCTION get_fpecode CDECL () AS LONG
   LOCAL hLib AS DWORD
   LOCAL pfpecode AS LONG PTR
   hLib = LoadLibrary($CRT_DLLNAME)
   IF hLib THEN
      pfpecode = GetProcAddress(hLib, "__fpecode")
      IF pfpecode THEN FUNCTION = @pfpecode
      FreeLibrary hLib
   END IF
END FUNCTION

'/* invalid subconditions (_SW_INVALID also set) */

%SW_UNEMULATED          = &H0040???  ' /* unemulated instruction */
%SW_SQRTNEG             = &H0080???  ' /* square root of a neg number */
%SW_STACKOVERFLOW       = &H0200???  ' /* FP stack overflow */
%SW_STACKUNDERFLOW      = &H0400???  ' /* FP stack underflow */

'/*  Floating point error signals and return codes */

%FPE_INVALID            = &H81&
%FPE_DENORMAL           = &H82&
%FPE_ZERODIVIDE         = &H83&
%FPE_OVERFLOW           = &H84&
%FPE_UNDERFLOW          = &H85&
%FPE_INEXACT            = &H86&

%FPE_UNEMULATED         = &H87&
%FPE_SQRTNEG            = &H88&
%FPE_STACKOVERFLOW      = &H8a&
%FPE_STACKUNDERFLOW     = &H8b&

%FPE_EXPLICITGEN        = &H8c&   ' /* raise( SIGFPE ); */


'/* IEEE recommended functions */

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
' _Check_return_ _CRTIMP double __cdecl _scalb(_In_ double _X, _In_ long _Y);
' ========================================================================================
DECLARE FUNCTION scalb_ CDECL IMPORT $CRT_DLLNAME ALIAS "_scalb" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 , BYVAL exp AS LONG _                                  ' __in long exp
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP double __cdecl _logb(_In_ double _X);
' ========================================================================================
DECLARE FUNCTION logb_ CDECL IMPORT $CRT_DLLNAME ALIAS "_logb" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP double __cdecl _nextafter(_In_ double _X, _In_ double _Y);
' ========================================================================================
DECLARE FUNCTION nextafter_ CDECL IMPORT $CRT_DLLNAME ALIAS "_nextafter" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 , BYVAL y AS DOUBLE _                                  ' __in double y
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _finite(_In_ double _X);
' ========================================================================================
DECLARE FUNCTION finite_ CDECL IMPORT $CRT_DLLNAME ALIAS "_finite" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _isnan(_In_ double _X);
' ========================================================================================
DECLARE FUNCTION isnan_ CDECL IMPORT $CRT_DLLNAME ALIAS "_isnan" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int    __cdecl _fpclass(_In_ double _X);
' ========================================================================================
DECLARE FUNCTION fpclass_ CDECL IMPORT $CRT_DLLNAME ALIAS "_fpclass" ( _
   BYVAL x AS DOUBLE _                                  ' __in double x
 ) AS LONG                                              ' int
' ========================================================================================

%FPCLASS_SNAN   = &H0001&  ' /* signaling NaN */
%FPCLASS_QNAN   = &H0002&  ' /* quiet NaN */
%FPCLASS_NINF   = &H0004&  ' /* negative infinity */
%FPCLASS_NN     = &H0008&  ' /* negative normal */
%FPCLASS_ND     = &H0010&  ' /* negative denormal */
%FPCLASS_NZ     = &H0020&  ' /* -0 */
%FPCLASS_PZ     = &H0040&  ' /* +0 */
%FPCLASS_PD     = &H0080&  ' /* positive denormal */
%FPCLASS_PN     = &H0100&  ' /* positive normal */
%FPCLASS_PINF   = &H0200&  ' /* positive infinity */
