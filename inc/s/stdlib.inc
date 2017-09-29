' ########################################################################################
' Microsoft C Runtime
' File: stdlib.inc
' Contents: This include file contains the function declarations for commonly used library
' functions which either don't fit somewhere else, or, cannot be declared in the normal
' place for other reasons.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%STDLIB_INC = 1

#INCLUDE ONCE "crtdefs.inc"
#INCLUDE ONCE "limits.inc"
#INCLUDE ONCE "errno.inc"

'/* Definition of the argument values for the exit() function */

%EXIT_SUCCESS   = 0
%EXIT_FAILURE   = 1

'#ifndef _ONEXIT_T_DEFINED

'#if !defined (_M_CEE_PURE)
'typedef int (__cdecl * _onexit_t)(void);
'#else
'typedef int (__clrcall * _onexit_t)(void);
'typedef _onexit_t _onexit_m_t;
'#endif

'#if defined (_M_CEE_MIXED)
'typedef int (__clrcall * _onexit_m_t)(void);
'#endif

'#if     !__STDC__
'/* Non-ANSI name for compatibility */
'#define onexit_t _onexit_t
'#endif

'#define _ONEXIT_T_DEFINED
'#endif


'/* Data structure definitions for div and ldiv runtimes. */

#IF NOT %DEF(%DIV_T_DEFINED)
%DIV_T_DEFINED = 1
' // Size = 8 bytes
TYPE div_t DWORD
   quot  AS LONG   ' int
   rem_  AS LONG   ' int
END TYPE

' // Size = 8 bytes
TYPE ldiv_t DWORD
   quot  AS LONG   ' long
   rem_  AS LONG   ' long
END TYPE
#ENDIF

'#endif

'/*
' * structs used to fool the compiler into not generating floating point
' * instructions when copying and pushing [long] double values
' */

'#ifndef _CRT_DOUBLE_DEC

'#ifndef _LDSUPPORT

'#pragma pack(4)
'typedef struct {
'    unsigned char ld[10];
'} _LDOUBLE;
'#pragma pack()

'#define _PTR_LD(x) ((unsigned char  *)(&(x)->ld))

'#else

'/* push and pop long, which is #defined as __int64 by a spec2k test */
'#pragma push_macro("long")
'#undef long
'typedef long double _LDOUBLE;
'#pragma pop_macro("long")

'#define _PTR_LD(x) ((unsigned char  *)(x))

'#endif

'typedef struct {
'        double x;
'} _CRT_DOUBLE;

TYPE CRT_DOUBLE
   x AS DOUBLE
END TYPE

'typedef struct {
'    float f;
'} _CRT_FLOAT;

TYPE CRT_FLOAT
  f AS SINGLE
END TYPE

'/* push and pop long, which is #defined as __int64 by a spec2k test */
'#pragma push_macro("long")
'#undef long

'typedef struct {
'        /*
'         * Assume there is a long double type
'         */
'        long double x;
'} _LONGDOUBLE;

TYPE LONGDOUBLE
   x AS EXT
END TYPE

'#pragma pop_macro("long")

'#pragma pack(4)
'typedef struct {
'    unsigned char ld12[12];
'} _LDBL12;
'#pragma pack()

'#define _CRT_DOUBLE_DEC
'#endif

'/* Maximum value that can be returned by the rand function. */

%RAND_MAX = &H7fff&

'/*
' * Maximum number of bytes in multi-byte character in the current locale
' * (also defined in ctype.h).
' */
'#ifndef MB_CUR_MAX
'#ifdef _MT
'#define MB_CUR_MAX ___mb_cur_max_func()
'#else
'#define MB_CUR_MAX __mb_cur_max
'#endif
'#if !defined(_M_CEE_PURE)
'_CRTIMP extern int __mb_cur_max;
'#else
'_CRTIMP int* __cdecl __p___mb_cur_max();
'#define __mb_cur_max (*__p___mb_cur_max())
'#endif /* !defined(_M_CEE_PURE) */
'_CRTIMP int __cdecl ___mb_cur_max_func(void);
'_CRTIMP int __cdecl ___mb_cur_max_l_func(_locale_t);
'#endif  /* MB_CUR_MAX */

#IF NOT %DEF(%MB_CUR_MAX)
    %MB_CUR_MAX = 1

'_CRTIMP extern int __mb_cur_max;
FUNCTION get_mb_cur_max () AS LONG
   LOCAL hLib AS DWORD
   LOCAL pmbcurmax AS LONG PTR
   CALL LoadLibrary($CRT_DLLNAME) TO hLib
   IF hLib THEN
      CALL GetProcAddress(hLib, "__mb_cur_max") TO pmbcurmax
      IF pmbcurmax THEN FUNCTION = @pmbcurmax
      CALL FreeLibrary(hLib)
   END IF
END FUNCTION

'_CRTIMP int __cdecl ___mb_cur_max_func(void);
FUNCTION get_mb_cur_max_func CDECL () AS LONG
   LOCAL hLib AS DWORD
   LOCAL pbcurmax AS LONG
   LOCAL pmbcurmaxfunc AS DWORD
   CALL LoadLibrary($CRT_DLLNAME) TO hLib
   IF hLib THEN
      CALL GetProcAddress(hLib, "___mb_cur_max_func") TO pmbcurmaxfunc
      IF pmbcurmaxfunc THEN
         CALL DWORD pmbcurmaxfunc USING get_mb_cur_max_func() TO pbcurmax
         FUNCTION = pbcurmax
      END IF
      CALL FreeLibrary(hLib)
   END IF
END FUNCTION

#ENDIF   '  /* MB_CUR_MAX */

'/* Minimum and maximum macros */

'#define __max(a,b)  (((a) > (b)) ? (a) : (b))
'#define __min(a,b)  (((a) < (b)) ? (a) : (b))

MACRO max__(a,b) = IIF(a > b, a, b)
MACRO min__(a,b) = IIF(a < b, a, b)

'/*
' * Sizes for buffers used by the _makepath() and _splitpath() functions.
' * note that the sizes include space for 0-terminator
' */

%MAX_PATH   = 260  ' /* max. length of full pathname */
%MAX_DRIVE  = 3    ' /* max. length of drive component */
%MAX_DIR    = 256  ' /* max. length of path component */
%MAX_FNAME  = 256  ' /* max. length of file name component */
%MAX_EXT    = 256  ' /* max. length of extension component */

'/*
' * Argument values for _set_error_mode().
' */

%OUT_TO_DEFAULT = 0
%OUT_TO_STDERR  = 1
%OUT_TO_MSGBOX  = 2
%REPORT_ERRMODE = 3

'/*
' * Argument values for _set_abort_behavior().
' */

%WRITE_ABORT_MSG    = &H1
%CALL_REPORTFAULT   = &H2

'/*
' * Sizes for buffers used by the getenv/putenv family of functions.
' */

%MAX_ENV = 32767

'/* External variable declarations */
'#ifndef _CRT_ERRNO_DEFINED
'#define _CRT_ERRNO_DEFINED
'_CRTIMP extern int * __cdecl _errno(void);
'#define errno   (*_errno())

'errno_t __cdecl _set_errno(__in int _Value);
'errno_t __cdecl _get_errno(__out int * _Value);
'#endif

' errno_t __cdecl _set_errno(_In_ int _Value);
' errno_t __cdecl _get_errno(_Out_ int * _Value);

'_CRTIMP unsigned long * __cdecl __doserrno(void);
'#define _doserrno   (*__doserrno())

'_CRTIMP extern unsigned long _doserrno; /* OS system error value */
FUNCTION doserrno_ () AS LONG
   LOCAL hLib AS DWORD
   LOCAL pdoserrno AS DWORD PTR
   hLib = LoadLibrary("$CRT_DLLNAME")
   IF hLib THEN
      pdoserrno = GetProcAddress(hLib, "_doserrno")
      IF pdoserrno THEN FUNCTION = @pdoserrno
      FreeLibrary hLib
   END IF
END FUNCTION

' ========================================================================================
' _CRTIMP unsigned long * __cdecl __doserrno(void);
' ========================================================================================
DECLARE FUNCTION doserrno__ CDECL IMPORT $CRT_DLLNAME ALIAS "__doserrno" ( _
 ) AS DWORD                                             ' unsigned long *
' ========================================================================================

' ========================================================================================
' errno_t __cdecl _set_doserrno(__in unsigned long _Value);
' ========================================================================================
DECLARE FUNCTION set_doserrno CDECL IMPORT $CRT_DLLNAME ALIAS "_set_doserrno" ( _
   BYVAL Value AS DWORD _                               ' __in unsigned long Value
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' errno_t __cdecl _get_doserrno(__out unsigned long * _Value);
' ========================================================================================
DECLARE FUNCTION get_doserrno CDECL IMPORT $CRT_DLLNAME ALIAS "_get_doserrno" ( _
   BYREF pValue AS DWORD _                              ' __out unsigned long * _Value
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' /* you can't modify this, but it is non-const for backcompat */
' _CRTIMP _CRT_INSECURE_DEPRECATE(strerror) char ** __cdecl __sys_errlist(void);
' #define _sys_errlist (__sys_errlist())
' ========================================================================================
DECLARE FUNCTION sys_errlist__ CDECL IMPORT $CRT_DLLNAME ALIAS "__sys_errlist" ( _
 ) AS DWORD                                             ' char ** [ASCIIZ PTR]
' ========================================================================================

' // Size = 4 bytes
TYPE sys_errlist_struct DWORD
  errors(0) AS ASCIIZ PTR
END TYPE

'_CRTIMP extern char * _sys_errlist[];   /* perror error message table */
' Usage example:
'   DIM rgerrors(0) AS STRING
'   get_sys_errlist(rgerrors())
'   LOCAL i AS LONG
'   FOR i = LBOUND(rgerrors) TO UBOUND(rgerrors)
'      PRINT rgerrors(i)
'   NEXT
FUNCTION get_sys_errlist (BYREF rgerrors() AS STRING) AS LONG
   LOCAL hLib AS DWORD
   LOCAL idx AS LONG
   LOCAL psyserrlist AS sys_errlist_struct PTR
   LOCAL nerrors AS LONG
   nerrors = get_sys_nerr
   FUNCTION = nerrors
   IF nerrors = 0 THEN EXIT FUNCTION
   IF UBOUND(rgerrors) - LBOUND(rgerrors) + 1 <> nerrors THEN
      REDIM rgerrors(nerrors - 1)
   END IF
   hLib = LoadLibrary($CRT_DLLNAME)
   IF hLib THEN
      psyserrlist = GetProcAddress(hLib, "_sys_errlist")
      IF psyserrlist THEN
         FOR idx = 0 TO nerrors - 1
            rgerrors(LBOUND(rgerrors) + idx) = @psyserrlist.@errors(idx)
         NEXT
      END IF
      FreeLibrary hLib
   END IF
END FUNCTION

' ========================================================================================
' _CRTIMP _CRT_INSECURE_DEPRECATE(strerror) int * __cdecl __sys_nerr(void);
' #define _sys_nerr (*__sys_nerr())
' ========================================================================================
DECLARE FUNCTION sys_nerr__ CDECL IMPORT $CRT_DLLNAME ALIAS "__sys_nerr" ( _
 ) AS DWORD                                             ' unsigned long * [LONG PTR]
' ========================================================================================

'_CRTIMP extern int _sys_nerr;           /* # of entries in sys_errlist table */
FUNCTION get_sys_nerr () AS LONG
   LOCAL hLib AS DWORD
   LOCAL psysnerr AS LONG PTR
   hLib = LoadLibrary($CRT_DLLNAME)
   IF hLib THEN
      psysnerr = GetProcAddress(hLib, "_sys_nerr")
      IF psysnerr THEN FUNCTION = @psysnerr
      FreeLibrary hLib
   END IF
END FUNCTION

'_CRTIMP char*** __cdecl __p__environ();
'_CRTIMP wchar_t*** __cdecl __p__wenviron();
'_CRT_INSECURE_DEPRECATE_GLOBALS(_get_pgmptr) _CRTIMP char** __cdecl __p__pgmptr();
'_CRT_INSECURE_DEPRECATE_GLOBALS(_get_wpgmptr) _CRTIMP wchar_t** __cdecl __p__wpgmptr();

'#define _environ   (*__p__environ())
'#define _wenviron  (*__p__wenviron())
'#define _pgmptr    (*__p__pgmptr())
'#define _wpgmptr   (*__p__wpgmptr())

' ========================================================================================
' errno_t __cdecl _get_pgmptr(__deref_out_z char ** _Value);
' ========================================================================================
DECLARE FUNCTION get_pgmptr CDECL IMPORT $CRT_DLLNAME ALIAS "_get_pgmptr" ( _
   BYREF Value AS DWORD _                               ' __out char ** Value [ASCIIZ PTR]
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' errno_t __cdecl _get_wpgmptr(__deref_out_z wchar_t ** _Value);
' ========================================================================================
DECLARE FUNCTION get_wpgmptr CDECL IMPORT $CRT_DLLNAME ALIAS "_get_wpgmptr" ( _
   BYREF Value AS DWORD _                               ' __out wchar_t ** Value [WSTRINGZ PTR]
 ) AS LONG                                              ' errno_t
' ========================================================================================

'_CRTIMP int* __cdecl __p__fmode();
'#define _fmode (*__p__fmode())

'_CRTIMP extern int _fmode;          /* default file translation mode */
FUNCTION getfmode () AS LONG
   LOCAL hLib AS DWORD
   LOCAL pfmode AS LONG PTR
   hLib = LoadLibrary($CRT_DLLNAME)
   IF hLib THEN
      pfmode = GetProcAddress(hLib, "_fmode")
      IF pfmode THEN FUNCTION = @pfmode
      FreeLibrary hLib
   END IF
END FUNCTION

SUB setfmode (BYVAL nmode AS LONG)
   LOCAL hLib AS DWORD
   LOCAL pfmode AS LONG PTR
   hLib = LoadLibrary($CRT_DLLNAME)
   IF hLib THEN
      pfmode = GetProcAddress(hLib, "_fmode")
      IF pfmode THEN @pfmode = nmode
      FreeLibrary hLib
   END IF
END SUB

' ========================================================================================
' _CRTIMP errno_t __cdecl _set_fmode(__in int _Mode);
' ========================================================================================
DECLARE FUNCTION set_fmode CDECL IMPORT $CRT_DLLNAME ALIAS "_set_fmode" ( _
   BYREF Mode AS LONG _                                 ' __in int _Mode
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _get_fmode(__out int * _PMode);
' ========================================================================================
DECLARE FUNCTION get_fmode CDECL IMPORT $CRT_DLLNAME ALIAS "_get_fmode" ( _
   BYREF pMode AS LONG _                                ' __out int * _PMode
 ) AS LONG                                              ' errno_t
' ========================================================================================

'/* Windows major/minor and O.S. version numbers */

'_CRT_INSECURE_DEPRECATE(_get_osplatform) _CRT_OBSOLETE(GetVersionEx)   _CRTIMP unsigned int* __cdecl __p__osplatform();
'_CRT_INSECURE_DEPRECATE(_get_osver) _CRT_OBSOLETE(GetVersionEx)         _CRTIMP unsigned int* __cdecl __p__osver();
'_CRT_INSECURE_DEPRECATE(_get_winver) _CRT_OBSOLETE(GetVersionEx)      _CRTIMP unsigned int* __cdecl __p__winver();
'_CRT_INSECURE_DEPRECATE(_get_winmajor) _CRT_OBSOLETE(GetVersionEx)      _CRTIMP unsigned int* __cdecl __p__winmajor();
'_CRT_INSECURE_DEPRECATE(_get_winminor) _CRT_OBSOLETE(GetVersionEx)      _CRTIMP unsigned int* __cdecl __p__winminor();

'#define _osplatform  (*__p__osplatform())
'#define _osver       (*__p__osver())
'#define _winver      (*__p__winver())
'#define _winmajor    (*__p__winmajor())
'#define _winminor    (*__p__winminor())

'_CRT_OBSOLETE(GetVersionEx) errno_t __cdecl _get_osplatform(__out unsigned int * _Value);
'_CRT_OBSOLETE(GetVersionEx) errno_t __cdecl _get_osver(__out unsigned int * _Value);
'_CRT_OBSOLETE(GetVersionEx) errno_t __cdecl _get_winver(__out unsigned int * _Value);
'_CRT_OBSOLETE(GetVersionEx) errno_t __cdecl _get_winmajor(__out unsigned int * _Value);
'_CRT_OBSOLETE(GetVersionEx) errno_t __cdecl _get_winminor(__out unsigned int * _Value);

'_CRTIMP extern int _fileinfo;       /* open file info mode (for spawn) */
FUNCTION get_fileinfo () AS LONG
   LOCAL hLib AS DWORD
   LOCAL pfileinfo AS LONG PTR
   hLib = LoadLibrary($CRT_DLLNAME)
   IF hLib THEN
      pfileinfo = GetProcAddress(hLib, "_fileinfo")
      IF pfileinfo THEN FUNCTION = @pfileinfo
      FreeLibrary hLib
   END IF
END FUNCTION

'/* Windows major/minor and O.S. version numbers */

'_CRTIMP extern unsigned int _osver;
FUNCTION get_osver () AS DWORD
   LOCAL hLib AS DWORD
   LOCAL posver AS DWORD PTR
   hLib = LoadLibrary($CRT_DLLNAME)
   IF hLib THEN
      posver = GetProcAddress(hLib, "_osver")
      IF posver THEN FUNCTION = @posver
      FreeLibrary hLib
   END IF
END FUNCTION

'_CRTIMP extern unsigned int _winver;
FUNCTION get_winver () AS LONG
   LOCAL hLib AS DWORD
   LOCAL pwinver AS LONG PTR
   hLib = LoadLibrary($CRT_DLLNAME)
   IF hLib THEN
      pwinver = GetProcAddress(hLib, "_winver")
      IF pwinver THEN FUNCTION = @pwinver
      FreeLibrary hLib
   END IF
END FUNCTION

'_CRTIMP extern unsigned int _winmajor;
FUNCTION get_winmajor () AS DWORD
   LOCAL hLib AS DWORD
   LOCAL pwinmajor AS DWORD PTR
   hLib = LoadLibrary($CRT_DLLNAME)
   IF hLib THEN
      pwinmajor = GetProcAddress(hLib, "_winmajor")
      IF pwinmajor THEN FUNCTION = @pwinmajor
      FreeLibrary hLib
   END IF
END FUNCTION

'_CRTIMP extern unsigned int _winminor;
FUNCTION get_winminor () AS DWORD
   LOCAL hLib AS DWORD
   LOCAL pwinminor AS DWORD PTR
   hLib = LoadLibrary($CRT_DLLNAME)
   IF hLib THEN
      pwinminor = GetProcAddress(hLib, "_winminor")
      IF pwinminor THEN FUNCTION = @pwinminor
      FreeLibrary hLib
   END IF
END FUNCTION

'/* function prototypes */

'#ifndef _CRT_TERMINATE_DEFINED
'#define _CRT_TERMINATE_DEFINED
'_CRTIMP __declspec(noreturn) void __cdecl exit(__in int _Code);
'_CRTIMP __declspec(noreturn) void __cdecl _exit(__in int _Code);
'_CRTIMP void __cdecl abort(void);
'#endif

' ========================================================================================
' _CRTIMP unsigned int __cdecl _set_abort_behavior(__in unsigned int _Flags, __in unsigned int _Mask);
' ========================================================================================
DECLARE FUNCTION set_abort_behavior CDECL IMPORT $CRT_DLLNAME ALIAS "_set_abort_behavior" ( _
   BYVAL Flags AS DWORD _                               ' __in unsigned int _Flags
 , BYVAL Mask AS DWORD _                                ' __in unsigned int _Mask
 ) AS LONG                                              ' unsigned int
' ========================================================================================

'#ifndef _CRT_ABS_DEFINED
'#define _CRT_ABS_DEFINED
'int  __cdecl abs(__in int _X);
'long __cdecl labs(__in long _X);
'#endif

'#ifndef _CRT_ATOF_DEFINED
'#define _CRT_ATOF_DEFINED
'_CRTIMP __checkReturn double  __cdecl atof(__in_z const char *_String);
'_CRTIMP __checkReturn double  __cdecl _atof_l(__in_z const char *_String, __in_opt _locale_t _Locale);
'#endif

' ========================================================================================
' *** All versions ***
' _CRTIMP _CRT_JIT_INTRINSIC __checkReturn int    __cdecl atoi(__in_z const char *_Str);
' ========================================================================================
DECLARE FUNCTION atoi CDECL IMPORT $CRT_DLLNAME ALIAS "atoi" ( _
   BYREF str AS ASCIIZ _                                ' __in const char *str
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn int    __cdecl _atoi_l(__in_z const char *_Str, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION atoi_l CDECL IMPORT $CRT_DLLNAME ALIAS "_atoi_l" ( _
   BYREF str AS ASCIIZ _                                ' __in const char *str
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn long   __cdecl atol(__in_z const char *_Str);
' ========================================================================================
DECLARE FUNCTION atol CDECL IMPORT $CRT_DLLNAME ALIAS "atol" ( _
   BYREF str AS ASCIIZ _                                ' __in const char *str
 ) AS LONG                                              ' long
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn long   __cdecl _atol_l(__in_z const char *_Str, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION atol_l CDECL IMPORT $CRT_DLLNAME ALIAS "_atol_l" ( _
   BYREF str AS ASCIIZ _                                ' __in const char *str
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' long
' ========================================================================================

'#ifndef _CRT_ALGO_DEFINED
'#define _CRT_ALGO_DEFINED
'#if __STDC_WANT_SECURE_LIB__
'_CRTIMP __checkReturn void * __cdecl bsearch_s(__in const void * _Key, __in_bcount(_NumOfElements * _SizeOfElements) const void * _Base,
'        __in rsize_t _NumOfElements, __in rsize_t _SizeOfElements,
'        __in int (__cdecl * _PtFuncCompare)(void *, const void *, const void *), void * _Context);
'#endif
'_CRTIMP __checkReturn void * __cdecl bsearch(__in const void * _Key, __in_bcount(_NumOfElements * _SizeOfElements) const void * _Base,
'        __in size_t _NumOfElements, __in size_t _SizeOfElements,
'        __in int (__cdecl * _PtFuncCompare)(const void *, const void *));

'#if __STDC_WANT_SECURE_LIB__
'_CRTIMP void __cdecl qsort_s(__inout_bcount(_NumOfElements* _SizeOfElements) void * _Base,
'        __in rsize_t _NumOfElements, __in rsize_t _SizeOfElements,
'        __in int (__cdecl * _PtFuncCompare)(void *, const void *, const void *), void *_Context);
'#endif
'_CRTIMP void __cdecl qsort(__inout_bcount(_NumOfElements * _SizeOfElements) void * _Base,
'   __in size_t _NumOfElements, __in size_t _SizeOfElements,
'        __in int (__cdecl * _PtFuncCompare)(const void *, const void *));
'#endif

' ========================================================================================
' __checkReturn unsigned short __cdecl _byteswap_ushort(__in unsigned short _Short);
' ========================================================================================
DECLARE FUNCTION byteswap_ushort CDECL IMPORT $CRT_DLLNAME ALIAS "_byteswap_ushort" ( _
   BYVAL val AS WORD _                                  ' __in unsigned short
 ) AS WORD                                              ' unsigned short
' ========================================================================================

' ========================================================================================
' __checkReturn unsigned long  __cdecl _byteswap_ulong (__in unsigned long _Long);
' ========================================================================================
DECLARE FUNCTION byteswap_ulong CDECL IMPORT $CRT_DLLNAME ALIAS "_byteswap_ulong" ( _
   BYVAL val AS WORD _                                  ' __in unsigned long
 ) AS DWORD                                             ' unsigned long
' ========================================================================================

' ========================================================================================
' _Check_return_ unsigned __int64 __cdecl _byteswap_uint64(_In_ unsigned __int64 _Int64);
' ========================================================================================
DECLARE FUNCTION byteswap_uint64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_byteswap_uint64" ( _
   BYVAL val AS QUAD _                                  ' __in unsigned __int64 val
 ) AS QUAD                                              ' unsigned __int64
' ========================================================================================

' _CRTIMP __checkReturn div_t  __cdecl div(__in int _Numerator, __in int _Denominator);
' Note: At the time of writing, PB doesn't support to return an structure as the
' result of a function, so only the quotient will be returned.
'DECLARE FUNCTION div CDECL IMPORT $CRT_DLLNAME ALIAS "div" ( _
'   BYVAL numer AS LONG _                                ' int numer
' , BYVAL denom AS LONG _                                ' int denom
' ) AS DWORD                                             ' div_t

' ========================================================================================
' Inline version of div
' ========================================================================================
SUB div (BYVAL numer AS LONG, BYVAL denom AS LONG, BYREF result AS div_t)
   IF denom = 0 THEN EXIT SUB
   result.quot = numer \ denom
   result.rem_ = numer - (result.quot * denom)
END SUB
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP _CRT_INSECURE_DEPRECATE(_dupenv_s) __checkReturn char * __cdecl getenv(__in_z const char * _VarName);
' ========================================================================================
DECLARE FUNCTION getenv CDECL IMPORT $CRT_DLLNAME ALIAS "getenv" ( _
   BYREF varname AS ASCIIZ _                            ' __in const char *varname
 ) AS DWORD                                             ' char *
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _CRTIMP __checkReturn_opt errno_t __cdecl getenv_s(__out size_t * _ReturnSize, __out_ecount_z(_DstSize) char * _DstBuf, __in rsize_t _DstSize, __in_z const char * _VarName);
' ========================================================================================
DECLARE FUNCTION getenv_s CDECL IMPORT $CRT_DLLNAME ALIAS "getenv_s" ( _
   BYREF pReturnValue AS DWORD _                        ' __out size_t * pReturnValue
 , BYREF buffer AS ASCIIZ _                             ' __out char* buffer
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , BYREF varname AS ASCIIZ _                            ' __in const char *varname
 ) AS LONG                                              ' errno_t
' ========================================================================================
'#endif

' ========================================================================================
' _CRTIMP __checkReturn_opt errno_t __cdecl _dupenv_s(__deref_out_ecount_z_opt(*_PBufferSizeInBytes) char **_PBuffer, __out_opt size_t * _PBufferSizeInBytes, __in_z const char * _VarName);
' ========================================================================================
DECLARE FUNCTION dupenv_s CDECL IMPORT $CRT_DLLNAME ALIAS "_dupenv_s" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char **buffer
 , BYREF sizeInBytes AS DWORD _                         ' __out size_t *sizeInBytes
 , BYREF varname AS ASCIIZ _                            ' __in const char *varname
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn_opt errno_t __cdecl _itoa_s(__in int _Value, __out_ecount_z(_Size) char * _DstBuf, __in size_t _Size, __in int _Radix);
' ========================================================================================
DECLARE FUNCTION itoa_s CDECL IMPORT $CRT_DLLNAME ALIAS "_itoa_s" ( _
   BYVAL value AS LONG _                                ' __in int value
 , BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL sizeInCharacters AS DWORD _                    ' __in size_t sizeInCharacters
 , BYVAL radix AS LONG _                                ' __in int radix
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRT_NONSTDC_DEPRECATE(_itoa) _CRT_INSECURE_DEPRECATE(_itoa_s)
' CRTIMP char * __cdecl itoa(_In_ int _Val, _Pre_notnull_ _Post_z_ char * _DstBuf, _In_ int _Radix);
' ========================================================================================
DECLARE FUNCTION itoa_ CDECL IMPORT $CRT_DLLNAME ALIAS "_itoa" ( _
   BYVAL value AS LONG _                                ' __in int value
 , BYREF str AS ASCIIZ _                                ' __out char *str
 , BYVAL radix AS LONG _                                ' __in int radix
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn_opt errno_t __cdecl _i64toa_s(__in __int64 _Val, __out_ecount_z(_Size) char * _DstBuf, __in size_t _Size, __in int _Radix);
' ========================================================================================
DECLARE FUNCTION i64toa_s CDECL IMPORT $CRT_DLLNAME ALIAS "_i64toa_s" ( _
   BYVAL value AS QUAD _                                ' __in __int64 value
 , BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL sizeInCharacters AS DWORD _                    ' __in size_t sizeInCharacters
 , BYVAL radix AS LONG _                                ' __in int radix
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP _CRT_INSECURE_DEPRECATE(_i64toa_s) char * __cdecl _i64toa(__in __int64 _Val, __out_z char * _DstBuf, __in int _Radix);
' ========================================================================================
DECLARE FUNCTION i64toa_ CDECL IMPORT $CRT_DLLNAME ALIAS "_i64toa" ( _
   BYVAL value AS QUAD _                                '__in  __int64 value
 , BYREF str AS ASCIIZ _                                ' __out char *str
 , BYVAL radix AS LONG _                                ' __in int radix
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn_opt errno_t __cdecl _ui64toa_s(__in unsigned __int64 _Val, __out_ecount_z(_Size) char * _DstBuf, __in size_t _Size, __in int _Radix);
' ========================================================================================
DECLARE FUNCTION ui64toa_s CDECL IMPORT $CRT_DLLNAME ALIAS "_ui64toa_s" ( _
   BYVAL value AS QUAD _                                ' __in unsigned __int64 value
 , BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL sizeInCharacters AS DWORD _                    ' __in size_t sizeInCharacters
 , BYVAL radix AS LONG _                                ' __in int radix
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP _CRT_INSECURE_DEPRECATE(_ui64toa_s) char * __cdecl _ui64toa(__in unsigned __int64 _Val, __out_z char * _DstBuf, __in int _Radix);
' ========================================================================================
DECLARE FUNCTION ui64toa_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ui64toa" ( _
   BYVAL value AS QUAD _                                ' __in unsigned __int64 value
 , BYREF str AS ASCIIZ _                                ' __out char *str
 , BYVAL radix AS LONG _                                ' __in int radix
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP __checkReturn __int64 __cdecl _atoi64(__in_z const char * _String);
' ========================================================================================
DECLARE FUNCTION atoi64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_atoi64" ( _
   BYREF string AS ASCIIZ _                             ' const char *string
 ) AS QUAD                                              ' __int64
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn __int64 __cdecl _atoi64_l(__in_z const char * _String, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION atoi64_l CDECL IMPORT $CRT_DLLNAME ALIAS "_atoi64_l" ( _
   BYREF str AS ASCIIZ _                                ' __in const char *str
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS QUAD                                              ' __int64
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn __int64 __cdecl _strtoi64(__in_z const char * _String, __deref_opt_out_z char ** _EndPtr, __in int _Radix);
' ========================================================================================
DECLARE FUNCTION strtoi64 CDECL IMPORT $CRT_DLLNAME ALIAS "_strtoi64" ( _
   BYREF nptr AS ASCIIZ _                               ' __in const char *nptr
 , BYREF endptr AS STRING _                             ' __out char **endptr
 , BYVAL base AS LONG _                                 ' __in int base
 ) AS QUAD                                              ' __int64
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn __int64 __cdecl _strtoi64_l(__in_z const char * _String, __deref_opt_out_z char ** _EndPtr, __in int _Radix, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION strtoi64_l CDECL IMPORT $CRT_DLLNAME ALIAS "_strtoi64_l" ( _
   BYREF nptr AS ASCIIZ _                               ' __in const char *nptr
 , BYREF endptr AS STRING _                             ' __out char **endptr
 , BYVAL base AS LONG _                                 ' __in int base
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS QUAD                                              ' __int64
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn unsigned __int64 __cdecl _strtoui64(__in_z const char * _String, __deref_opt_out_z char ** _EndPtr, __in int _Radix);
' ========================================================================================
DECLARE FUNCTION strtoui64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_strtoui64" ( _
   BYREF nptr AS ASCIIZ _                               ' __in const char *nptr
 , BYREF endptr AS STRING _                             ' __out char **endptr
 , BYVAL base AS LONG _                                 ' __in int base
 ) AS QUAD                                              ' __int64
' ========================================================================================

' ========================================================================================
'_CRTIMP __checkReturn unsigned __int64 __cdecl _strtoui64_l(__in_z const char * _String, __deref_opt_out_z char ** _EndPtr, __in int  _Radix, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION strtoui64_l CDECL IMPORT $CRT_DLLNAME ALIAS "_strtoui64_l" ( _
   BYREF nptr AS ASCIIZ _                               ' __in const char *nptr
 , BYREF endptr AS STRING _                             ' __out char **endptr
 , BYVAL base AS LONG _                                 ' __in int base
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS QUAD                                              ' __int64
' ========================================================================================

'_CRTIMP __checkReturn ldiv_t __cdecl ldiv(__in long _Numerator, __in long _Denominator);
' Note: At the time of writing, PB doesn't support to return an structure as the
' result of a function, so only the quotient will be returned.
'DECLARE FUNCTION ldiv CDECL IMPORT $CRT_DLLNAME ALIAS "ldiv" ( _
'   BYVAL numer AS LONG _                                ' long numer
' , BYVAL denom AS LONG _                                ' long denom
' ) AS DWORD                                             ' ldiv_t

'#ifdef __cplusplus
'extern "C++"
'{
'    inline ldiv_t  div(__in long _A1, __in long _A2)
'    {
'        return ldiv(_A1, _A2);
'    }
'}
'#endif

' /* The ANSI standard says that |QUOT| <= |NUMER / DENOM|, where
'    NUMER / DENOM is to be computed in infinite precision.  In
'    other words, we should always truncate the quotient towards
'    zero, never -infinity.  Machine division and remainer may
'    work either way when one or both of NUMER or DENOM is
'    negative.  If only one is negative and QUOT has been
'    truncated towards -infinity, REM will have the same sign as
'    DENOM and the opposite sign of NUMER; if both are negative
'    and QUOT has been truncated towards -infinity, REM will be
'    positive (will have the opposite sign of NUMER).  These are
'    considered `wrong'.  If both are NUM and DENOM are positive,
'    RESULT will always be positive.  This all boils down to: if
'    NUMER >= 0, but REM < 0, we got the wrong answer.  In that
'    case, to get the right answer, add 1 to QUOT and subtract
'    DENOM from REM.  */

' ========================================================================================
' Inline version of ldiv
' ========================================================================================
SUB ldiv (BYVAL numer AS LONG, BYVAL denom AS LONG, BYREF result AS div_t)
   IF denom = 0 THEN EXIT SUB
   result.quot = numer \ denom
   result.rem_ = numer MOD denom
   IF numer >= 0 AND result.rem_ < 0 THEN
      result.quot = result.quot + 1
      result.rem_ = result.rem_ - denom
   END IF
END SUB
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn_opt errno_t __cdecl _ltoa_s(__in long _Val, __out_ecount_z(_Size) char * _DstBuf, __in size_t _Size, __in int _Radix);
' ========================================================================================
DECLARE FUNCTION ltoa_s CDECL IMPORT $CRT_DLLNAME ALIAS "_ltoa_s" ( _
   BYVAL value AS LONG _                                ' __in long value
 , BYREF str AS ASCIIZ _                                ' __out char *str
 , BYVAL sizeOfstr AS DWORD _                           ' __in size_t sizeOfstr
 , BYVAL radix AS LONG _                                ' __in int radix
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION ltoa_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ltoa" ( _
   BYVAL value AS LONG _                                ' __in long value
 , BYREF str AS ASCIIZ _                                ' __out char *str
 , BYVAL radix AS LONG _                                ' __in int radix
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP __checkReturn int __cdecl mblen(__in_bcount_z_opt(_MaxCount) const char * _Ch, __in size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION mblen CDECL IMPORT $CRT_DLLNAME ALIAS "mblen" ( _
   BYREF mbstr AS ASCIIZ _                              ' __in const char *mbstr
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn int __cdecl _mblen_l(__in_bcount_z_opt(_MaxCount) const char * _Ch, __in size_t _MaxCount, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mblen_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mblen_l" ( _
   BYREF mbstr AS ASCIIZ _                              ' __in const char *mbstr
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP __checkReturn size_t __cdecl _mbstrlen(__in_z const char * _Str);
' ========================================================================================
DECLARE FUNCTION mbstrlen_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbstrlen" ( _
   BYREF str AS ASCIIZ _                                ' __in const char *str
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn size_t __cdecl _mbstrlen_l(__in_z const char *_Str, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbstrlen_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbstrlen_l" ( _
   BYREF str AS ASCIIZ _                                ' __in const char *str
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn size_t __cdecl _mbstrnlen(__in_z const char *_Str, __in size_t _MaxCount);
' ========================================================================================
DECLARE FUNCTION mbstrnlen_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mbstrnlen" ( _
   BYREF str AS ASCIIZ _                                ' __in const char *str
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn size_t __cdecl _mbstrnlen_l(__in_z const char *_Str, __in size_t _MaxCount, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbstrnlen_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbstrnlen_l" ( _
   BYREF str AS ASCIIZ _                                ' __in const char *str
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP int    __cdecl mbtowc(__out_z wchar_t * _DstCh, __in_bcount_z_opt(_SrcSizeInBytes) const char * _SrcCh, __in size_t _SrcSizeInBytes);
' ========================================================================================
DECLARE FUNCTION mbtowc CDECL IMPORT $CRT_DLLNAME ALIAS "mbtowc" ( _
   BYREF wchar AS WSTRINGZ _                            ' __out wchar_t *wchar
 , BYREF mbchar AS ASCIIZ _                             ' __in const char *mbchar
 , BYVAL size AS DWORD _                                ' __in size_t count
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP int    __cdecl _mbtowc_l(__out_z wchar_t * _DstCh, __in_bcount_z_opt(_SrcSizeInBytes) const char * _SrcCh, __in size_t _SrcSizeInBytes, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbtowc_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbtowc_l" ( _
   BYREF wchar AS WSTRINGZ _                            ' __out wchar_t *wchar
 , BYREF mbchar AS ASCIIZ _                             ' __in const char *mbchar
 , BYVAL size AS DWORD _                                ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION mbstowcs CDECL IMPORT $CRT_DLLNAME ALIAS "mbstowcs" ( _
   BYREF wcstr AS WSTRINGZ _                            ' __out wchar_t *wcstr
 , BYREF mbchar AS ASCIIZ _                             ' __in const char *mbchar
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
DECLARE FUNCTION mbstowcs_l CDECL IMPORT $CRT_DLLNAME ALIAS "mbstowcs_l" ( _
   BYREF wcstr AS WSTRINGZ _                            ' __out wchar_t *wcstr
 , BYREF mbchar AS ASCIIZ _                             ' __in const char *mbchar
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn_opt errno_t __cdecl mbstowcs_s(__out_opt size_t * _PtNumOfCharConverted, __out_ecount_part_opt(_SizeInWords, *_PtNumOfCharConverted) wchar_t * _DstBuf,
' __in size_t _SizeInWords, __in_ecount_z(_MaxCount) const char * _SrcBuf, __in size_t _MaxCount );
' ========================================================================================
DECLARE FUNCTION mbstowcs_s CDECL IMPORT $CRT_DLLNAME ALIAS "mbstowcs_s" ( _
   BYREF pReturnValue AS DWORD _                        ' __out size_t *pReturnValue
 , BYREF wcstr AS WSTRINGZ _                            ' __out wchar_t *wcstr
 , BYVAL sizeInWords AS DWORD _                         ' __in size_t sizeInWords
 , BYREF mbchar AS ASCIIZ _                             ' __in const char *mbchar
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn_opt errno_t __cdecl _mbstowcs_s_l(__out_opt size_t * _PtNumOfCharConverted, __out_ecount_part_opt(_SizeInWords, *_PtNumOfCharConverted) wchar_t * _DstBuf, __in size_t _SizeInWords,
'  __in_ecount_z(_MaxCount) const char * _SrcBuf, __in size_t _MaxCount, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION mbstowcs_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_mbstowcs_s_l" ( _
   BYREF pReturnValue AS DWORD _                        ' __out size_t *pReturnValue
 , BYREF wcstr AS WSTRINGZ _                            ' __out wchar_t *wcstr
 , BYVAL sizeInWords AS DWORD _                         ' __in size_t sizeInWords
 , BYREF mbchar AS ASCIIZ _                             ' __in const char *mbchar
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP __checkReturn int __cdecl rand(void);
' ========================================================================================
DECLARE FUNCTION rand CDECL IMPORT $CRT_DLLNAME ALIAS "rand" ( _
 ) AS LONG                                              ' int
' ========================================================================================

'#if defined(_CRT_RAND_S)
' ========================================================================================
' _CRTIMP errno_t __cdecl rand_s ( __out unsigned int *_RandomValue);
' ========================================================================================
DECLARE FUNCTION rand_s CDECL IMPORT $CRT_DLLNAME ALIAS "rand_s" ( _
   BYREF randomValue AS DWORD _                         ' __out unsigned int* randomValue
 ) AS LONG                                              ' errno_t
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' _CRTIMP __checkReturn_opt int __cdecl _set_error_mode(__in int _Mode);
' ========================================================================================
DECLARE FUNCTION set_error_mode_ CDECL IMPORT $CRT_DLLNAME ALIAS "_set_error_mode" ( _
   BYVAL modeval AS LONG _                              ' __in int modeval
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP void __cdecl srand(__in unsigned int _Seed);
' ========================================================================================
DECLARE SUB srand CDECL IMPORT $CRT_DLLNAME ALIAS "srand" ( _
   BYVAL seed AS DWORD _                                ' __in unsigned int seed
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP __checkReturn double __cdecl strtod(__in_z const char * _Str, __deref_opt_out_z char ** _EndPtr);
' ========================================================================================
' ========================================================================================
' Usage example:
'   LOCAL stopstring AS ASCIIZ PTR
'   LOCAL s AS ASCIIZ * 260
'   LOCAL d AS DOUBLE
'   s = "3.1415926This stopped it"
'   d = strtod(s, stopstring)
'   PRINT d
'   IF stopstring THEN PRINT @stopstring
' ========================================================================================
DECLARE FUNCTION strtod CDECL IMPORT $CRT_DLLNAME ALIAS "strtod" ( _
   BYREF nptr AS ASCIIZ _                               ' __in const char *nptr
 , BYREF endptr AS DWORD _                              ' __out char **endptr
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn double __cdecl _strtod_l(__in_z const char * _Str, __deref_opt_out_z char ** _EndPtr, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION strtod_l CDECL IMPORT $CRT_DLLNAME ALIAS "_strtod_l" ( _
   BYREF nptr AS ASCIIZ _                               ' __in const char *nptr
 , BYREF endptr AS DWORD _                              ' __out char **endptr
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP __checkReturn long __cdecl strtol(__in_z const char * _Str, __deref_opt_out_z char ** _EndPtr, __in int _Radix );
' ========================================================================================
DECLARE FUNCTION strtol CDECL IMPORT $CRT_DLLNAME ALIAS "strtol" ( _
   BYREF nptr AS ASCIIZ _                               ' __in const char *nptr
 , BYREF endptr AS DWORD _                              ' __out char **endptr
 , BYVAL base AS LONG _                                 ' __in int base
 ) AS LONG                                              ' long
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn long __cdecl _strtol_l(__in_z const char *_Str, __deref_opt_out_z char **_EndPtr, __in int _Radix, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION strtol_l CDECL IMPORT $CRT_DLLNAME ALIAS "_strtol_l" ( _
   BYREF nptr AS ASCIIZ _                               ' __in const char *nptr
 , BYREF endptr AS DWORD _                              ' __out char **endptr
 , BYVAL base AS LONG _                                 ' __in int base
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS LONG                                              ' long
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP __checkReturn unsigned long __cdecl strtoul(__in_z const char * _Str, __deref_opt_out_z char ** _EndPtr, __in int _Radix);
' ========================================================================================
DECLARE FUNCTION strtoul CDECL IMPORT $CRT_DLLNAME ALIAS "strtoul" ( _
   BYREF nptr AS ASCIIZ _                               ' __in const char *nptr
 , BYREF endptr AS DWORD _                              ' __out char **endptr
 , BYVAL base AS LONG _                                 ' __in int base
 ) AS DWORD                                             ' unsigned long
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn unsigned long __cdecl _strtoul_l(const char * _Str, __deref_opt_out_z char **_EndPtr, __in int _Radix, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION strtoul_l CDECL IMPORT $CRT_DLLNAME ALIAS "_strtoul_l" ( _
   BYREF nptr AS ASCIIZ _                               ' __in const char *nptr
 , BYREF endptr AS DWORD _                              ' __out char **endptr
 , BYVAL base AS LONG _                                 ' __in int base
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS DWORD                                             ' unsigned long
' ========================================================================================

#IF NOT %DEF(%CRT_SYSTEM_DEFINED)
    %CRT_SYSTEM_DEFINED = 1
' ========================================================================================
' *** All versions ***
' _CRTIMP int __cdecl system(__in_z_opt const char * _Command);
' ========================================================================================
DECLARE FUNCTION system CDECL IMPORT $CRT_DLLNAME ALIAS "system" ( _
   BYREF command AS ASCIIZ _                            ' __in const char *command
 ) AS LONG                                              ' int
' ========================================================================================
#ENDIF   ' CRT_SYSTEM_DEFINED

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION ultoa_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ultoa" ( _
   BYVAL value AS DWORD _                               ' __in unsigned long value
 , BYREF str AS ASCIIZ _                                ' __in char *str
 , BYVAL radix AS LONG _                                ' __in int radix
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn_opt errno_t __cdecl _ultoa_s(__in unsigned long _Val, __out_ecount_z(_Size) char * _DstBuf, __in size_t _Size, __in int _Radix);
' ========================================================================================
DECLARE FUNCTION ultoa_s CDECL IMPORT $CRT_DLLNAME ALIAS "_ultoa_s" ( _
   BYVAL value AS DWORD _                               ' __in unsigned long value
 , BYREF str AS ASCIIZ _                                ' __out char *str
 , BYVAL radix AS LONG _                                ' __in int radix
 , BYVAL sizeOfstr AS DWORD _                           ' __in size_t sizeOfstr
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP _CRT_INSECURE_DEPRECATE(wctomb_s) int __cdecl wctomb(__out_bcount_z_opt(MB_LEN_MAX) char * _MbCh, __in_z wchar_t _WCh);
' ========================================================================================
DECLARE FUNCTION wctomb CDECL IMPORT $CRT_DLLNAME ALIAS "wctomb" ( _
   BYREF mbchar AS ASCIIZ _                             ' __out char *mbchar
 , BYREF wchar AS WSTRINGZ _                            ' __in wchar_t wchar
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP _CRT_INSECURE_DEPRECATE(_wctomb_s_l) int    __cdecl _wctomb_l(__out_z_opt char * _MbCh, __in wchar_t _WCh, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION wctomb_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wctomb_l" ( _
   BYREF mbchar AS ASCIIZ _                             ' __out char *mbchar
 , BYREF wchar AS WSTRINGZ _                            ' __in wchar_t wchar
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _CRTIMP __checkReturn_wat errno_t __cdecl wctomb_s(__out_opt int * _SizeConverted, __out_bcount_part_opt(_SizeInBytes, *_SizeConverted) char * _MbCh, __in rsize_t _SizeInBytes, __in wchar_t _WCh);
' ========================================================================================
DECLARE FUNCTION wctomb_s CDECL IMPORT $CRT_DLLNAME ALIAS "wctomb_s" ( _
   BYREF pRetValue AS LONG _                            ' __out int *pRetValue
 , BYREF mbchar AS ASCIIZ _                             ' __out char *mbchar
 , BYREF wchar AS WSTRINGZ _                            ' __in wchar_t wchar
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 ) AS LONG                                              ' errno_t
' ========================================================================================
'#endif

' ========================================================================================
'_CRTIMP __checkReturn_wat errno_t __cdecl _wctomb_s_l(__out_opt int * _SizeConverted, __out_bcount_z_opt(_SizeInBytes) char * _MbCh, __in size_t _SizeInBytes, __in wchar_t _WCh, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION wctomb_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wctomb_s_l" ( _
   BYREF pRetValue AS LONG _                            ' __out int *pRetValue
 , BYREF mbchar AS ASCIIZ _                             ' __out char *mbchar
 , BYREF wchar AS WSTRINGZ _                            ' __in wchar_t wchar
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION wcstombs CDECL IMPORT $CRT_DLLNAME ALIAS "wcstombs" ( _
   BYREF mbstr AS ASCIIZ _                              ' __out char *mbstr
 , BYREF wcstr AS WSTRINGZ _                            ' __in const wchar_t *wcstr
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn_wat errno_t __cdecl wcstombs_s(__out_opt size_t * _PtNumOfCharConverted, __out_bcount_part_opt(_DstSizeInBytes, *_PtNumOfCharConverted) char * _Dst, __in size_t _DstSizeInBytes,
'   __in_z const wchar_t * _Src, __in size_t _MaxCountInBytes);
' ========================================================================================
DECLARE FUNCTION wcstombs_s CDECL IMPORT $CRT_DLLNAME ALIAS "wcstombs_s" ( _
   BYREF pReturnValue AS DWORD _                        ' __out size_t *pReturnValue
 , BYREF mbstr AS ASCIIZ _                              ' __out char *mbstr
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , BYREF wcstr AS WSTRINGZ _                            ' __in const wchar_t *wcstr
 , BYVAL count AS DWORD _                               ' __in size_t count
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn_wat errno_t __cdecl _wcstombs_s_l(__out_opt size_t * _PtNumOfCharConverted, __out_bcount_part_opt(_DstSizeInBytes, *_PtNumOfCharConverted) char * _Dst, __in size_t _DstSizeInBytes,
'  __in_z const wchar_t * _Src, __in size_t _MaxCountInBytes, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION wcstombs_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wcstombs_s_l" ( _
   BYREF pReturnValue AS DWORD _                        ' __out size_t *pReturnValue
 , BYREF mbstr AS ASCIIZ _                              ' __out char *mbstr
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , BYREF wcstr AS WSTRINGZ _                            ' __in const wchar_t *wcstr
 , BYVAL count AS DWORD _                               ' __in size_t count
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS LONG                                              ' errno_t
' ========================================================================================

#IF NOT %DEF(%WSTDLIB_DEFINED)
    %WSTDLIB_DEFINED = 1

'/* wide function prototypes, also declared in wchar.h  */

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION itow_ CDECL IMPORT $CRT_DLLNAME ALIAS "_itow" ( _
   BYVAL value AS LONG _                                ' __in int value
 , BYREF wstr AS WSTRINGZ _                             '__out  wchar_t *str
 , BYVAL radix AS LONG _                                ' __in int radix
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn_wat errno_t __cdecl _itow_s (__in int _Val, __out_ecount_z(_SizeInWords) wchar_t * _DstBuf, __in size_t _SizeInWords, __in int _Radix);
' ========================================================================================
DECLARE FUNCTION itow_s CDECL IMPORT $CRT_DLLNAME ALIAS "_itow_s" ( _
   BYVAL value AS LONG _                                ' __in int value
 , BYREF wstr AS WSTRINGZ _                             ' __out wchar_t *str
 , BYVAL sizeInCharacters AS DWORD _                    ' __in size_t sizeInCharacters
 , BYVAL radix AS LONG _                                ' __in int radix
 ) AS LONG                                              ' errno_t *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION ltow_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ltow" ( _
   BYVAL value AS LONG _                                ' __in long value
 , BYREF wstr AS WSTRINGZ _                             ' __out wchar_t *str
 , BYVAL radix AS LONG _                                ' __in int radix
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn_wat errno_t __cdecl _ltow_s (__in long _Val, __out_ecount_z(_SizeInWords) wchar_t * _DstBuf, __in size_t _SizeInWords, __in int _Radix);
' ========================================================================================
DECLARE FUNCTION ltow_s CDECL IMPORT $CRT_DLLNAME ALIAS "_ltow_s" ( _
   BYVAL value AS LONG _                                ' __in long value
 , BYREF wstr AS WSTRINGZ _                             ' __out wchar_t *str
 , BYVAL sizeOfstr AS DWORD _                           ' __in size_t sizeOfstr
 , BYVAL radix AS LONG _                                ' __in int radix
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION ultow_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ultow" ( _
   BYVAL value AS DWORD _                               ' __in unsigned long value
 , BYREF wstr AS WSTRINGZ _                             ' __out wchar_t *str
 , BYVAL radix AS LONG _                                ' __in int radix
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn_wat errno_t __cdecl _ultow_s (__in unsigned long _Val, __out_ecount_z(_SizeInWords) wchar_t * _DstBuf, __in size_t _SizeInWords, __in int _Radix);
' ========================================================================================
DECLARE FUNCTION ultow_s CDECL IMPORT $CRT_DLLNAME ALIAS "_ultow_s" ( _
   BYVAL value AS DWORD _                               ' __in unsigned long value
 , BYREF wstr AS WSTRINGZ _                             ' __out wchar_t *str
 , BYVAL sizeOfstr AS DWORD _                           ' __in size_t sizeOfstr
 , BYVAL radix AS LONG _                                ' __in int radix
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP __checkReturn double __cdecl wcstod(__in_z const wchar_t * _Str, __deref_opt_out_z wchar_t ** _EndPtr);
' ========================================================================================
DECLARE FUNCTION wcstod CDECL IMPORT $CRT_DLLNAME ALIAS "wcstod" ( _
   BYREF nptr AS WSTRINGZ _                             ' __in const wchar_t *nptr
 , BYREF endptr AS DWORD _                              ' __out wchar_t **endptr
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn double __cdecl _wcstod_l(__in_z const wchar_t *_Str, __deref_opt_out_z wchar_t ** _EndPtr, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION wcstod_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wcstod_l" ( _
   BYREF nptr AS WSTRINGZ _                             ' __in const wchar_t *nptr
 , BYREF endptr AS DWORD _                              ' __out wchar_t **endptr
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP __checkReturn long   __cdecl wcstol(__in_z const wchar_t *_Str, __deref_opt_out_z wchar_t ** _EndPtr, int _Radix);
' ========================================================================================
DECLARE FUNCTION wcstol CDECL IMPORT $CRT_DLLNAME ALIAS "wcstol" ( _
   BYREF nptr AS WSTRINGZ _                             ' __in const wchar_t *nptr
 , BYREF endptr AS DWORD _                              ' __out wchar_t **endptr
 ) AS LONG                                              ' long
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn long   __cdecl _wcstol_l(__in_z const wchar_t *_Str, __deref_opt_out_z wchar_t **_EndPtr, int _Radix, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION wcstol_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wcstol_l" ( _
   BYREF nptr AS WSTRINGZ _                             ' __in const wchar_t *nptr
 , BYREF endptr AS DWORD _                              ' __out wchar_t **endptr
 , BYVAL base AS LONG _                                 ' __in int base
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS LONG                                              ' long
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP __checkReturn unsigned long __cdecl wcstoul(__in_z const wchar_t *_Str, __deref_opt_out_z wchar_t ** _EndPtr, int _Radix);
' ========================================================================================
DECLARE FUNCTION wcstoul CDECL IMPORT $CRT_DLLNAME ALIAS "wcstoul" ( _
   BYREF nptr AS WSTRINGZ _                             ' __in const wchar_t *nptr
 , BYREF endptr AS DWORD _                              ' __out wchar_t **endptr
 , BYVAL base AS LONG _                                 ' __in int base
 ) AS DWORD                                             ' unsigned long
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn unsigned long __cdecl _wcstoul_l(__in_z const wchar_t *_Str, __deref_opt_out_z wchar_t **_EndPtr, int _Radix, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION wcstoul_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wcstoul_l" ( _
   BYREF nptr AS WSTRINGZ _                             ' __in const wchar_t *nptr
 , BYREF endptr AS DWORD _                              ' __out wchar_t **endptr
 , BYVAL base AS LONG _                                 ' __in int base
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS DWORD                                             ' unsigned long
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP _CRT_INSECURE_DEPRECATE(_wdupenv_s) __checkReturn wchar_t * __cdecl _wgetenv(__in_z const wchar_t * _VarName);
' ========================================================================================
DECLARE FUNCTION wgetenv_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wgetenv" ( _
   BYREF varname AS WSTRINGZ _                          ' __in const wchar_t *varname
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
'_CRTIMP __checkReturn_wat errno_t __cdecl _wgetenv_s(__out size_t * _ReturnSize, __out_ecount_z(_DstSizeInWords) wchar_t * _DstBuf, __in size_t _DstSizeInWords, __in_z const wchar_t * _VarName);
' ========================================================================================
DECLARE FUNCTION wgetenv_s CDECL IMPORT $CRT_DLLNAME ALIAS "_wgetenv_s" ( _
   BYREF pReturnValue AS DWORD _                        ' __out size_t *pReturnValue
 , BYREF buffer AS WSTRINGZ _                           ' __out const wchar_t *buffer
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , BYREF varname AS WSTRINGZ _                          ' __in const wchar_t *varname
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
'_CRTIMP __checkReturn_wat errno_t __cdecl _wdupenv_s(__deref_out_ecount_z_opt(*_BufferSizeInWords) wchar_t **_Buffer, __out_opt size_t *_BufferSizeInWords, __in_z const wchar_t *_VarName);
' ========================================================================================
DECLARE FUNCTION wdupenv_s CDECL IMPORT $CRT_DLLNAME ALIAS "_wdupenv_s" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t **buffer
 , BYREF sizeInBytes AS DWORD _                         ' __out size_t *sizeInBytes
 , BYREF varname AS WSTRINGZ _                          ' __in const wchar_t *varname
 ) AS LONG                                              ' errno_t
' ========================================================================================

#IF NOT %DEF(%CRT_WSYSTEM_DEFINED)
    %CRT_WSYSTEM_DEFINED = 1
' ========================================================================================
' *** All versions ***
' _CRTIMP int __cdecl _wsystem(__in_z_opt const wchar_t * _Command);
' ========================================================================================
DECLARE FUNCTION wsystem_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wsystem" ( _
   BYREF command AS WSTRINGZ _                          ' __in const wchar_t *command
 ) AS LONG                                              ' int
' ========================================================================================
#ENDIF

' ========================================================================================
' _CRTIMP __checkReturn double __cdecl _wtof(__in_z const wchar_t *_Str);
' ========================================================================================
DECLARE FUNCTION wtof CDECL IMPORT $CRT_DLLNAME ALIAS "_wtof" ( _
   BYREF wstr AS WSTRINGZ _                             ' __in const wchar_t *str
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn double __cdecl _wtof_l(__in_z const wchar_t *_Str, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION wtof_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wtof_l" ( _
   BYREF wstr AS WSTRINGZ _                             ' __in const wchar_t *str
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP __checkReturn int __cdecl _wtoi(__in_z const wchar_t *_Str);
' ========================================================================================
DECLARE FUNCTION wtoi_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wtoi" ( _
   BYREF wstr AS WSTRINGZ _                             ' __in const wchar_t *str
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn int __cdecl _wtoi_l(__in_z const wchar_t *_Str, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION wtoi_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wtoi_l" ( _
   BYREF wstr AS WSTRINGZ _                             ' __in const wchar_t *str
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP __checkReturn long __cdecl _wtol(__in_z const wchar_t *_Str);
' ========================================================================================
DECLARE FUNCTION wtol_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wtol" ( _
   BYREF wstr AS WSTRINGZ _                             ' __in const wchar_t *str
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn long __cdecl _wtol_l(__in_z const wchar_t *_Str, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION wtol_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wtol_l" ( _
   BYREF wstr AS WSTRINGZ _                             ' __in const wchar_t *str
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP _CRT_INSECURE_DEPRECATE(_i65tow_s) wchar_t * __cdecl _i64tow(__in __int64 _Val, __out_z wchar_t * _DstBuf, __in int _Radix);
' ========================================================================================
DECLARE FUNCTION i64tow_ CDECL IMPORT $CRT_DLLNAME ALIAS "_i64tow" ( _
   BYVAL value AS QUAD _                                ' __in __int64 value
 , BYREF wstring AS WSTRINGZ _                          ' __out wchar_t *string
 , BYVAL radix AS LONG _                                ' __in int radix
 ) AS DWORD                                             ' wchar_t
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn_wat errno_t __cdecl _i64tow_s(__in __int64 _Val, __out_ecount_z(_SizeInWords) wchar_t * _DstBuf, __in size_t _SizeInWords, __in int _Radix);
' ========================================================================================
DECLARE FUNCTION i64tow_s CDECL IMPORT $CRT_DLLNAME ALIAS "_i64tow_s" ( _
   BYVAL value AS QUAD _                                ' __in __int64 value
 , BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL sizeInCharacters AS DWORD _                    ' __in size_t sizeInCharacters
 , BYVAL radix AS LONG _                                ' __in int radix
 ) AS DWORD                                             ' wchar_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP _CRT_INSECURE_DEPRECATE(_ui64tow_s) wchar_t * __cdecl _ui64tow(__in unsigned __int64 _Val, __out_z wchar_t * _DstBuf, __in int _Radix);
' ========================================================================================
DECLARE FUNCTION ui64tow_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ui64tow" ( _
   BYVAL value AS QUAD _                                ' __in unsigned __int64 value
 , BYREF wstring AS WSTRINGZ _                          ' __out wchar_t *string
 , BYVAL radix AS LONG _                                ' __in int radix
 ) AS DWORD                                             ' wchar_t
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn_wat errno_t __cdecl _ui64tow_s(__in unsigned __int64 _Val, __out_ecount_z(_SizeInWords) wchar_t * _DstBuf, __in size_t _SizeInWords, __in int _Radix);
' ========================================================================================
DECLARE FUNCTION ui64tow_s CDECL IMPORT $CRT_DLLNAME ALIAS "_ui64tow_s" ( _
   BYVAL value AS QUAD _                                ' __in unsigned __int64 value
 , BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL sizeInCharacters AS DWORD _                    ' __in size_t sizeInCharacters
 , BYVAL radix AS LONG _                                ' __in int radix
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP __checkReturn __int64   __cdecl _wtoi64(__in_z const wchar_t *_Str);
' ========================================================================================
DECLARE FUNCTION wtoi64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wtoi64" ( _
   BYREF wstring AS WSTRINGZ _                          ' __in wchar_t *string
 ) AS QUAD                                              ' __int64
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP __checkReturn __int64   __cdecl _wcstoi64(__in_z const wchar_t * _Str, __deref_opt_out_z wchar_t ** _EndPtr, __in int _Radix);
' ========================================================================================
DECLARE FUNCTION wcstoi64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wcstoi64" ( _
   BYREF nptr AS WSTRINGZ _                             ' __in const wchar_t *nptr,
 , BYREF endptr AS DWORD _                              ' __out wchar_t **endptr
 , BYVAL base AS LONG _                                 ' __in int base
 ) AS QUAD                                              ' __int64
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn __int64   __cdecl _wcstoi64_l(__in_z const wchar_t * _Str, __deref_opt_out_z wchar_t ** _EndPtr, __in int _Radix, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION wcstoi64_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wcstoi64_l" ( _
   BYREF nptr AS WSTRINGZ _                             ' __in const wchar_t *nptr,
 , BYREF endptr AS DWORD _                              ' __out wchar_t **endptr
 , BYVAL base AS LONG _                                 ' __in int base
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS QUAD                                              ' __int64
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn unsigned __int64  __cdecl _wcstoui64(__in_z const wchar_t * _Str, __deref_opt_out_z wchar_t ** _EndPtr, __in int _Radix);
' ========================================================================================
DECLARE FUNCTION wcstoui64 CDECL IMPORT $CRT_DLLNAME ALIAS "_wcstoui64" ( _
   BYREF nptr AS WSTRINGZ _                             ' __in const wchar_t *nptr,
 , BYREF endptr AS DWORD _                              ' __out wchar_t **endptr
 , BYVAL base AS LONG _                                 ' __in int base
 ) AS QUAD                                              ' __int64
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn unsigned __int64  __cdecl _wcstoui64_l(__in_z const wchar_t *_Str , __deref_opt_out_z wchar_t ** _EndPtr, __in int _Radix, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION wcstoui64_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wcstoui64_l" ( _
   BYREF nptr AS WSTRINGZ _                             ' __in const wchar_t *nptr,
 , BYREF endptr AS DWORD _                              ' __out wchar_t **endptr
 , BYVAL base AS LONG _                                 ' __in int base
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS QUAD                                              ' __int64
' ========================================================================================

#ENDIF   ' WSTDLIB_DEFINED

' ========================================================================================
' *** All versions ***
' _CRTIMP __checkReturn char * __cdecl _fullpath(__out_ecount_z_opt(_SizeInBytes) char * _FullPath, __in_z const char * _Path, __in size_t _SizeInBytes);
' ========================================================================================
DECLARE FUNCTION fullpath_ CDECL IMPORT $CRT_DLLNAME ALIAS "_fullpath" ( _
   BYREF absPath AS ASCIIZ _                            ' __out char *absPath
 , BYREF relPath AS ASCIIZ _                            ' __in const char *relPath
 , BYVAL maxLength AS DWORD _                           ' __in size_t maxLength
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP _CRT_INSECURE_DEPRECATE(_ecvt_s) __checkReturn char * __cdecl _ecvt(
' __in double _Val, __in int _NumOfDigits, __out int * _PtDec, __out int * _PtSign);
' ========================================================================================
DECLARE FUNCTION ecvt_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ecvt" ( _
   BYVAL value AS DOUBLE _                              ' __in double value
 , BYVAL count AS LONG _                                ' __in int count
 , BYREF dec AS LONG _                                  ' __out int *dec
 , BYREF sign AS LONG _                                 ' __out int *sign
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn_wat errno_t __cdecl _ecvt_s(__out_ecount_z(_Size) char * _DstBuf,
' __in size_t _Size, __in double _Val, __in int _NumOfDights, __out int * _PtDec, __out int * _PtSign);
' ========================================================================================
DECLARE FUNCTION ecvt_s CDECL IMPORT $CRT_DLLNAME ALIAS "_ecvt_s" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char * _Buffer
 , BYVAL SizeInBytes AS DWORD _                         ' __in size_t _SizeInBytes
 , BYVAL value AS DOUBLE _                              ' __in double value
 , BYVAL count AS LONG _                                ' __in int count
 , BYREF dec AS LONG _                                  ' __out int *dec
 , BYREF sign AS LONG _                                 ' __out int *sign
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP _CRT_INSECURE_DEPRECATE(_fcvt_s) __checkReturn char * __cdecl _fcvt(
' __in double _Val, __in int _NumOfDec, __out int * _PtDec, __out int * _PtSign);
' ========================================================================================
DECLARE FUNCTION fcvt_ CDECL IMPORT $CRT_DLLNAME ALIAS "_fcvt" ( _
   BYVAL value AS DOUBLE _                              ' __in double value
 , BYVAL count AS LONG _                                ' __in int count
 , BYREF dec AS LONG _                                  ' __out int *dec
 , BYREF sign AS LONG _                                 ' __out int *sign
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn_wat errno_t __cdecl _fcvt_s(__out_ecount_z(_Size) char * _DstBuf,
' __in size_t _Size, __in double _Val, __in int _NumOfDec, __out int * _PtDec, __out int * _PtSign);
' ========================================================================================
DECLARE FUNCTION fcvt_s CDECL IMPORT $CRT_DLLNAME ALIAS "_fcvt_s" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char * _Buffer
 , BYVAL SizeInBytes AS DWORD _                         ' __in size_t _SizeInBytes
 , BYVAL value AS DOUBLE _                              ' __in double value
 , BYVAL count AS LONG _                                ' __in int count
 , BYREF dec AS LONG _                                  ' __out int *dec
 , BYREF sign AS LONG _                                 ' __out int *sign
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION gcvt_ CDECL IMPORT $CRT_DLLNAME ALIAS "_gcvt" ( _
   BYVAL value AS DOUBLE _                              ' __in double value
 , BYVAL digits AS LONG _                               ' __in int digits
 , BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _gcvt_s(__out_ecount_z(_Size) char * _DstBuf, __in size_t _Size,
' __in double _Val, __in int _NumOfDigits);
' ========================================================================================
DECLARE FUNCTION gcvt_s CDECL IMPORT $CRT_DLLNAME ALIAS "_gcvt_s" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL SizeInBytes AS DWORD _                         ' __in size_t _SizeInBytes
 , BYVAL value AS DOUBLE _                              ' __in double value
 , BYVAL digits AS LONG _                               ' __in int digits
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn int __cdecl _atodbl(__out _CRT_DOUBLE * _Result, __in_z char * _Str);
' ========================================================================================
DECLARE FUNCTION atodbl CDECL IMPORT $CRT_DLLNAME ALIAS "_atodbl" ( _
   BYREF value AS DOUBLE _                              ' __out _CRT_DOUBLE * value
 , BYREF str AS ASCIIZ _                                ' __in char * str
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn int __cdecl _atoldbl(__out _LDOUBLE * _Result, __in_z char * _Str);
' ========================================================================================
DECLARE FUNCTION atoldbl CDECL IMPORT $CRT_DLLNAME ALIAS "_atoldbl" ( _
   BYREF value AS EXT _                                 ' __out _LDOUBLE * value
 , BYREF str AS ASCIIZ _                                ' __in char * str
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn int __cdecl _atoflt(__out _CRT_FLOAT * _Result, __in_z char * _Str);
' ========================================================================================
DECLARE FUNCTION atoflt CDECL IMPORT $CRT_DLLNAME ALIAS "_atoflt" ( _
   BYREF value AS SINGLE _                              ' __out _CRT_FLOAT * value
 , BYREF str AS ASCIIZ _                                ' __in char * str
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn int __cdecl _atodbl_l(__out _CRT_DOUBLE * _Result, __in_z char * _Str, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION atodbl_l CDECL IMPORT $CRT_DLLNAME ALIAS "_atodbl_l" ( _
   BYREF value AS DOUBLE _                              ' __out _CRT_DOUBLE * value
 , BYREF str AS ASCIIZ _                                ' __in char * str
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn int __cdecl _atoldbl_l(__out _LDOUBLE * _Result, __in_z char * _Str, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION atoldbl_l CDECL IMPORT $CRT_DLLNAME ALIAS "_atoldbl_l" ( _
   BYREF value AS EXT _                                 ' __out _LDOUBLE * value
 , BYREF str AS ASCIIZ _                                ' __in char * str
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
'_CRTIMP __checkReturn int __cdecl _atoflt_l(__out _CRT_FLOAT * _Result, __in_z char * _Str, __in_opt _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION atoflt_l CDECL IMPORT $CRT_DLLNAME ALIAS "_atoflt_l" ( _
   BYREF value AS SINGLE _                              '__out _CRT_FLOAT * value
 , BYREF str AS ASCIIZ _                                ' __in char * str
 , OPTIONAL BYVAL locale AS locale_t _                  '__in _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' __checkReturn unsigned long __cdecl _lrotl(__in unsigned long _Val, __in int _Shift);
' ========================================================================================
DECLARE FUNCTION lrotl_ CDECL IMPORT $CRT_DLLNAME ALIAS "_lrotl" ( _
   BYVAL value AS DWORD _                               ' __in unsigned long value
 , BYVAL shift AS LONG _                                ' __in int shift
 ) AS DWORD                                             ' unsigned long
' ========================================================================================

' ========================================================================================
' *** All versions ***
' __checkReturn unsigned long __cdecl _lrotr(__in unsigned long _Val, __in int _Shift);
' ========================================================================================
DECLARE FUNCTION lrotr_ CDECL IMPORT $CRT_DLLNAME ALIAS "_lrotr" ( _
   BYVAL value AS DWORD _                               ' __in unsigned long value
 , BYVAL shift AS LONG _                                ' __in int shift
 ) AS DWORD                                             ' unsigned long
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE SUB makepath_ CDECL IMPORT $CRT_DLLNAME ALIAS "_makepath" ( _
   BYREF path AS ASCIIZ _                               ' __out char *path
 , OPTIONAL BYREF drive AS ASCIIZ _                     ' __in const char *drive
 , OPTIONAL BYREF dir AS ASCIIZ _                       ' __in const char *dir
 , OPTIONAL BYREF fname AS ASCIIZ _                     ' __in const char *fname
 , OPTIONAL BYREF ext AS ASCIIZ _                       ' __in const char *ext
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' _CRTIMP_ALTERNATIVE __checkReturn_wat errno_t __cdecl _makepath_s(
' __out_ecount_z(_Size) char * _PathResult, __in_opt size_t _Size,
' __in_z_opt const char * _Drive, __in_z_opt const char * _Dir,
' __in_z_opt const char * _Filename,  __in_z_opt const char * _Ext);
' ========================================================================================
DECLARE FUNCTION makepath_s CDECL IMPORT $CRT_DLLNAME ALIAS "_makepath_s" ( _
   BYREF path AS ASCIIZ _                               ' __out char *path
 , OPTIONAL BYVAL sizeInCharacters AS DWORD _           ' __in size_t sizeInCharacters
 , OPTIONAL BYREF drive AS ASCIIZ _                     ' __in const char *drive
 , OPTIONAL BYREF dir AS ASCIIZ _                       ' __in const char *dir
 , OPTIONAL BYREF fname AS ASCIIZ _                     ' __in const char *fname
 , OPTIONAL BYREF ext AS ASCIIZ _                       ' __in const char *ext
 ) AS LONG                                              ' errno_t
' ========================================================================================

#IF NOT %DEF(%CRT_PERROR_DEFINED)
    %CRT_PERROR_DEFINED = 1
' // Also defined in stdio.inc
' ========================================================================================
' *** All versions ***
' _CRTIMP void __cdecl perror(_In_opt_z_ const char * _ErrMsg);
' ========================================================================================
DECLARE SUB perror CDECL IMPORT $CRT_DLLNAME ALIAS "perror" ( _
   BYREF szErrMsg AS ASCIIZ _                           ' __in const char * _ErrMsg
 )                                                      ' void
' ========================================================================================
#ENDIF   ' CRT_PERROR_DEFINED

' ========================================================================================
' *** All versions ***
' _CRTIMP __checkReturn int    __cdecl _putenv(__in_z const char * _EnvString);
' ========================================================================================
DECLARE FUNCTION putenv_ CDECL IMPORT $CRT_DLLNAME ALIAS "_putenv" ( _
   BYREF envstring AS ASCIIZ _                          ' __in const char *envstring
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn_wat errno_t __cdecl _putenv_s(__in_z const char * _Name, __in_z const char * _Value);
' ========================================================================================
DECLARE FUNCTION putenv_s CDECL IMPORT $CRT_DLLNAME ALIAS "_putenv_s" ( _
   BYREF name AS ASCIIZ _                               ' __in const char *name
 , BYREF envstring AS ASCIIZ _                          ' __in const char *value
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' __checkReturn unsigned int __cdecl _rotl(__in unsigned int _Val, __in int _Shift);
' ========================================================================================
DECLARE FUNCTION rotl_ CDECL IMPORT $CRT_DLLNAME ALIAS "_rotl" ( _
   BYVAL value AS DWORD _                               ' __in unsigned int value
 , BYVAL shift AS LONG _                                ' __in int shift
 ) AS DWORD                                             ' unsigned int
' ========================================================================================

'#if _INTEGRAL_MAX_BITS >= 64
' ========================================================================================
' checkReturn unsigned __int64 __cdecl _rotl64(__in unsigned __int64 _Val, __in int _Shift);
' ========================================================================================
DECLARE FUNCTION rotl64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_rotl64" ( _
   BYVAL value AS QUAD _                                ' __in unsigned __int64 value
 , BYVAL shift AS LONG _                                ' __in int shift
 ) AS QUAD                                              ' __int64
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' __checkReturn unsigned int __cdecl _rotr(__in unsigned int _Val, __in int _Shift);
' ========================================================================================
DECLARE FUNCTION rotr_ CDECL IMPORT $CRT_DLLNAME ALIAS "_rotr" ( _
   BYVAL value AS DWORD _                               ' __in unsigned int value
 , BYVAL shift AS LONG _                                ' __in int shift
 ) AS DWORD                                             ' unsigned int
' ========================================================================================

' ========================================================================================
' __checkReturn unsigned __int64 __cdecl _rotr64(__in unsigned __int64 _Val, __in int _Shift);
' ========================================================================================
DECLARE FUNCTION rotr64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_rotr64" ( _
   BYVAL value AS QUAD _                                ' __in __int64 value
 , BYVAL shift AS LONG _                                ' __in int shift
 ) AS QUAD                                              ' unsigned __int64
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE SUB searchenv_ CDECL IMPORT $CRT_DLLNAME ALIAS "_searchenv" ( _
   BYREF filename AS ASCIIZ _                           ' __in const char *filename
 , BYREF varname AS ASCIIZ _                            ' __in const char *varname
 , BYREF pathname AS ASCIIZ _                           ' __in char *pathname
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _searchenv_s(__in_z const char * _Filename,
' __in_z const char * _EnvVar, __out_ecount_z(_SizeInBytes) char * _ResultPath, __in size_t _SizeInBytes);
' ========================================================================================
DECLARE FUNCTION searchenv_s CDECL IMPORT $CRT_DLLNAME ALIAS "_searchenv_s" ( _
   BYREF filename AS ASCIIZ _                           ' __in const char *filename
 , BYREF varname AS ASCIIZ _                            ' __in const char *varname
 , BYREF pathname AS ASCIIZ _                           ' __out char *pathname
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRT_INSECURE_DEPRECATE(_splitpath_s) _CRTIMP void   __cdecl _splitpath(__in_z const char * _FullPath, __out_z_opt char * _Drive, __out_z_opt char * _Dir, __out_z_opt char * _Filename, __out_z_opt char * _Ext);
' ========================================================================================
DECLARE SUB splitpath_ CDECL IMPORT $CRT_DLLNAME ALIAS "_splitpath" ( _
   BYREF path AS ASCIIZ _                               ' _in const char *path
 , BYREF drive AS ASCIIZ _                              ' __out char *drive
 , BYREF dir AS ASCIIZ _                                ' __out char *dir
 , BYREF fname AS ASCIIZ _                              ' __out char *fname
 , BYREF ext AS ASCIIZ _                                ' __out char *ext
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' _CRTIMP_ALTERNATIVE __checkReturn_wat errno_t  __cdecl _splitpath_s(__in_z const char * _FullPath,
'      __out_ecount_z_opt(_DriveSize) char * _Drive, __in size_t _DriveSize,
'      __out_ecount_z_opt(_DirSize) char * _Dir, __in size_t _DirSize,
'      __out_ecount_z_opt(_FilenameSize) char * _Filename, __in size_t _FilenameSize,
'      __out_ecount_z_opt(_ExtSize) char * _Ext, __in size_t _ExtSize);
' ========================================================================================
DECLARE FUNCTION splitpath_s CDECL IMPORT $CRT_DLLNAME ALIAS "_splitpath_s" ( _
   BYREF path AS ASCIIZ _                               ' __in const char *path
 , BYREF drive AS ASCIIZ _                              ' __out char *drive
 , BYVAL driveSizeInCharacters AS DWORD _               ' __in size_t driveSizeInCharacters
 , BYREF dir AS ASCIIZ _                                ' __out char *dir
 , BYVAL dirSizeInCharacters AS DWORD _                 ' __in size_t dirSizeInCharacters
 , BYREF fname AS ASCIIZ _                              ' __out char *fname
 , BYVAL nameSizeInCharacters AS DWORD _                ' __in size_t nameSizeInCharacters
 , BYREF ext AS ASCIIZ _                                ' __out char *ext
 , BYVAL extSizeInBytes AS DWORD _                      ' __in size_t extSizeInBytes
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP void   __cdecl _swab(__inout_ecount_full(_SizeInBytes) char * _Buf1, __inout_ecount_full(_SizeInBytes) char * _Buf2, int _SizeInBytes);
' ========================================================================================
DECLARE SUB swab_ CDECL IMPORT $CRT_DLLNAME ALIAS "_swab" ( _
   BYREF src AS ASCIIZ _                                ' __inout char *src
 , BYREF dest AS ASCIIZ _                               ' __inout char *dest
 , BYVAL n AS LONG _                                    ' __in int n
 )                                                      ' void
' ========================================================================================

#IF NOT %DEF(%WSTDLIBP_DEFINED)
    %WSTDLIBP_DEFINED = 1

'/* wide function prototypes, also declared in wchar.h  */

' ========================================================================================
' *** All versions ***
' _CRTIMP __checkReturn wchar_t * __cdecl _wfullpath(__out_ecount_z_opt(_SizeInWords) wchar_t * _FullPath,
' __in_z const wchar_t * _Path, __in size_t _SizeInWords);
' ========================================================================================
DECLARE FUNCTION wfullpath_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wfullpath" ( _
   BYREF absPath AS WSTRINGZ _                          ' __out wchar_t *absPath
 , BYREF relPath AS WSTRINGZ _                          ' __in const wchar_t *relPath
 , BYVAL maxLength AS DWORD _                           ' __in size_t maxLength
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE SUB wmakepath_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wmakepath" ( _
   BYREF path AS WSTRINGZ _                             ' __out wchar_t *path
 , BYREF drive AS WSTRINGZ _                            ' __in_optconst wchar_t *drive
 , BYREF dir AS WSTRINGZ _                              ' __in_optconst wchar_t *dir
 , BYREF fname AS WSTRINGZ _                            ' __in_optconst wchar_t *fname
 , BYREF ext AS WSTRINGZ _                              ' __in_optconst wchar_t *ext
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' _CRTIMP_ALTERNATIVE __checkReturn_wat errno_t __cdecl _wmakepath_s(
' __out_ecount_z(_SizeInWords) wchar_t * _PathResult, __in_opt size_t _SizeInWords,
' __in_z_opt const wchar_t * _Drive, __in_z_opt const wchar_t * _Dir,
' __in_z_opt const wchar_t * _Filename, __in_z_opt const wchar_t * _Ext);
' ========================================================================================
DECLARE FUNCTION wmakepath_s CDECL IMPORT $CRT_DLLNAME ALIAS "_wmakepath_s" ( _
   BYREF path AS WSTRINGZ _                             ' __out wchar_t *path
 , BYVAL sizeInCharacters AS DWORD _                    ' __in size_t sizeInCharacters
 , OPTIONAL BYREF drive AS WSTRINGZ _                   ' __in_opt const wchar_t *drive
 , OPTIONAL BYREF dir AS WSTRINGZ _                     ' __in_opt const wchar_t *dir
 , OPTIONAL BYREF fname AS WSTRINGZ _                   ' __in_opt const wchar_t *fname
 , OPTIONAL BYREF ext AS WSTRINGZ _                     ' __in_opt const wchar_t *ext
 ) AS LONG                                              ' errno_t
' ========================================================================================

#IF NOT %DEF(%CRT_WPERROR_DEFINED)
    %CRT_WPERROR_DEFINED = 1
' // Also declared in stdio.inc
' ========================================================================================
' *** All versions ***
' _CRTIMP void __cdecl _wperror(_In_opt_z_ const wchar_t * _ErrMsg);
' ========================================================================================
DECLARE SUB wperror_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wperror" ( _
   OPTIONAL BYREF string AS WSTRINGZ _                  ' __in_opt  const wchar_t *string
 )                                                      ' void
' ========================================================================================
#ENDIF   ' CRT_WPERROR_DEFINED

' ========================================================================================
' *** All versions ***
' _CRTIMP __checkReturn int    __cdecl _wputenv(__in_z const wchar_t * _EnvString);
' ========================================================================================
DECLARE FUNCTION wputenv_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wputenv" ( _
   BYREF envstring AS WSTRINGZ _                        ' __in const wchar_t *envstring
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP __checkReturn_wat errno_t __cdecl _wputenv_s(__in_z const wchar_t * _Name, __in_z const wchar_t * _Value);
' ========================================================================================
DECLARE FUNCTION wputenv_s CDECL IMPORT $CRT_DLLNAME ALIAS "_wputenv_s" ( _
   BYREF name AS WSTRINGZ _                             ' __in_optconst wchar_t *name
 , BYREF value AS WSTRINGZ _                            ' __in_optconst wchar_t *value
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE SUB wsearchenv_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wsearchenv" ( _
   BYREF filename AS WSTRINGZ _                         ' __in const wchar_t *filename
 , BYREF varname AS WSTRINGZ _                          ' __in const wchar_t *varname
 , BYREF pathname AS WSTRINGZ _                         ' __out wchar_t *pathname
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _wsearchenv_s(__in_z const wchar_t * _Filename, __in_z const wchar_t * _EnvVar, __out_ecount_z(_SizeInWords) wchar_t * _ResultPath, __in size_t _SizeInWords);
' ========================================================================================
DECLARE FUNCTION wsearchenv_s CDECL IMPORT $CRT_DLLNAME ALIAS "_wsearchenv_s" ( _
   BYREF filename AS WSTRINGZ _                         ' __in const wchar_t *filename
 , BYREF varname AS WSTRINGZ _                          ' __in const wchar_t *varname
 , BYREF pathname AS WSTRINGZ _                         ' __out wchar_t *pathname
 , BYVAL sizeInWords AS DWORD _                         ' __in size_t sizeInWords
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRT_INSECURE_DEPRECATE(_wsplitpath_s) _CRTIMP void   __cdecl _wsplitpath(__in_z const wchar_t * _FullPath, __out_z_opt wchar_t * _Drive, __out_z_opt wchar_t * _Dir, __out_z_opt wchar_t * _Filename, __out_z_opt wchar_t * _Ext);
' ========================================================================================
DECLARE SUB wsplitpath_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wsplitpath" ( _
   BYREF path AS WSTRINGZ _                             ' __in const wchar_t *path
 , OPTIONAL BYREF drive AS WSTRINGZ _                   ' __out_opt wchar_t *drive
 , OPTIONAL BYREF dir AS WSTRINGZ _                     ' __out_opt wchar_t *dir
 , OPTIONAL BYREF fname AS WSTRINGZ _                   ' __out_opt wchar_t *fname
 , OPTIONAL BYREF ext AS WSTRINGZ _                     ' __out_opt wchar_t *ext
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' _CRTIMP_ALTERNATIVE errno_t __cdecl _wsplitpath_s(__in_z const wchar_t * _FullPath,
' __out_ecount_z_opt(_DriveSizeInWords) wchar_t * _Drive, __in size_t _DriveSizeInWords,
' __out_ecount_z_opt(_DirSizeInWords) wchar_t * _Dir, __in size_t _DirSizeInWords,
' __out_ecount_z_opt(_FilenameSizeInWords) wchar_t * _Filename, __in size_t _FilenameSizeInWords,
' __out_ecount_z_opt(_ExtSizeInWords) wchar_t * _Ext, __in size_t _ExtSizeInWords);
' ========================================================================================
DECLARE FUNCTION wsplitpath_s CDECL IMPORT $CRT_DLLNAME ALIAS "_wsplitpath_s" ( _
   BYREF path AS WSTRINGZ _                             ' const wchar_t *path
 , OPTIONAL BYREF drive AS WSTRINGZ _                   ' out_opt wchar_t *drive
 , OPTIONAL BYVAL driveSizeInCharacters AS DWORD _      ' __in size_t driveSizeInCharacters
 , OPTIONAL BYREF dir AS WSTRINGZ _                     ' out_opt wchar_t *dir
 , OPTIONAL BYVAL dirSizeInCharacters AS DWORD _        ' __in size_t dirSizeInCharacters
 , OPTIONAL BYREF fname AS WSTRINGZ _                   ' out_opt wchar_t *fname
 , OPTIONAL BYVAL nameSizeInCharacters AS DWORD _       ' __in size_t nameSizeInCharacters
 , OPTIONAL BYREF ext AS WSTRINGZ _                     ' out_opt wchar_t *ext
 , OPTIONAL BYVAL extSizeInCharacters AS DWORD _        ' __in size_t extSizeInCharacters
 ) AS LONG                                              ' errno_t
' ========================================================================================

#ENDIF   ' WSTDLIBP_DEFINED

'/* The Win32 API SetErrorMode, Beep and Sleep should be used instead. */
'_CRT_OBSOLETE(SetErrorMode) _CRTIMP void __cdecl _seterrormode(__in int _Mode);
'_CRT_OBSOLETE(Beep) _CRTIMP void __cdecl _beep(__in unsigned _Frequency, __in unsigned _Duration);
'_CRT_OBSOLETE(Sleep) _CRTIMP void __cdecl _sleep(__in unsigned long _Duration);
