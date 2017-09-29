' ########################################################################################
' Microsoft C Runtime
' File: crtdefs.inc
' Contents: This file has mostly defines used by the entire CRT.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CRTDEFS_INC = 1

#IF NOT %DEF(%CRT_VERSION)
    %CRT_VERSION = 0
#ENDIF

#IF NOT %DEF($CRT_DLLNAME)
    #IF %CRT_VERSION = 0        ' // Use default version
        $CRT_DLLNAME = "msvcrt.dll"
    #ELSEIF %CRT_VERSION = 10   ' // Version 1.0
        $CRT_DLLNAME = "msvcrt10.dll"
    #ELSEIF %CRT_VERSION = 20   ' // Version 2.0
        $CRT_DLLNAME = "msvcrt20.dll"
    #ELSEIF %CRT_VERSION = 30   ' // Version 3.0
        $CRT_DLLNAME = "msvcrt30.dll"
    #ELSEIF %CRT_VERSION = 40   ' // Version 4.0
        $CRT_DLLNAME = "msvcrt40.dll"
    #ELSEIF %CRT_VERSION = 50   ' // Version 5.0
        $CRT_DLLNAME = "msvcrt50.dll"
    #ELSEIF %CRT_VERSION = 60   ' // Version 6.0
        $CRT_DLLNAME = "msvcrt60.dll"
    #ELSEIF %CRT_VERSION = 70   ' // Version 7.0
        $CRT_DLLNAME = "msvcr70.dll"
    #ELSEIF %CRT_VERSION = 71   ' // Version 7.1
        $CRT_DLLNAME = "msvcr71.dll"
    #ELSEIF %CRT_VERSION = 80   ' // Version 8.0
        $CRT_DLLNAME = "msvcr80.dll"
    #ELSEIF %CRT_VERSION = 90   ' // Version 9.0
        $CRT_DLLNAME = "msvcr90.dll"
    #ELSEIF %CRT_VERSION = 100   ' // Version 10.0
        $CRT_DLLNAME = "msvcr100.dll"
    #ENDIF
#ENDIF

#INCLUDE ONCE "windows.inc"

'#ifdef  _WIN64
'typedef unsigned __int64    size_t;
'#else
'typedef _W64 unsigned int   size_t;
'#endif
'#define _SIZE_T_DEFINED
'#endif

'#if __STDC_WANT_SECURE_LIB__
'#ifndef _RSIZE_T_DEFINED
'typedef size_t rsize_t;
'#define _RSIZE_T_DEFINED
'#endif
'#endif

'#ifndef _INTPTR_T_DEFINED
'#ifdef  _WIN64
'typedef __int64             intptr_t;
'#else
'typedef _W64 int            intptr_t;
'#endif
'#define _INTPTR_T_DEFINED
'#endif

'#ifndef _UINTPTR_T_DEFINED
'#ifdef  _WIN64
'typedef unsigned __int64    uintptr_t;
'#else
'typedef _W64 unsigned int   uintptr_t;
'#endif
'#define _UINTPTR_T_DEFINED
'#endif

'#ifndef _PTRDIFF_T_DEFINED
'#ifdef  _WIN64
'typedef __int64             ptrdiff_t;
'#else
'typedef _W64 int            ptrdiff_t;
'#endif
'#define _PTRDIFF_T_DEFINED
'#endif

'#ifndef _WCHAR_T_DEFINED
'typedef unsigned short wchar_t;
'#define _WCHAR_T_DEFINED
'#endif

'#ifndef _WCTYPE_T_DEFINED
'typedef unsigned short wint_t;
'typedef unsigned short wctype_t;
'#define _WCTYPE_T_DEFINED
'#endif

'#ifndef _VA_LIST_DEFINED
'#ifdef _M_CEE_PURE
'typedef System::ArgIterator va_list;
'#else
'typedef char *  va_list;
'#endif
'#define _VA_LIST_DEFINED
'#endif

'#ifdef  _USE_32BIT_TIME_T
'#ifdef  _WIN64
'#error You cannot use 32-bit time_t (_USE_32BIT_TIME_T) with _WIN64
'#undef  _USE_32BIT_TIME_T
'#endif
'#endif

'#ifndef _ERRCODE_DEFINED
'#define _ERRCODE_DEFINED
'/* errcode is deprecated in favor or errno_t, which is part of the standard proposal */
'#if !defined(__midl)
'_CRT_DEPRECATE_TEXT("This name was supported during some Whidbey pre-releases. Instead, use the standard name errno_t." ) typedef int errcode;
'#else
'typedef int errcode;
'#endif

'typedef int errno_t;
'#endif

'#ifndef _TIME32_T_DEFINED
'typedef _W64 long __time32_t;   /* 32-bit time value */
'#define _TIME32_T_DEFINED
'#endif

'#ifndef _TIME64_T_DEFINED
'typedef __int64 __time64_t;     /* 64-bit time value */
'#define _TIME64_T_DEFINED
'#endif

'#ifndef _TIME_T_DEFINED
'#ifdef _USE_32BIT_TIME_T
'typedef __time32_t time_t;      /* time value */
'#else
'typedef __time64_t time_t;      /* time value */
'#endif
'#define _TIME_T_DEFINED         /* avoid multiple def's of time_t */
'#endif

'#define _ARGMAX 100

'struct threadlocaleinfostruct;
'struct threadmbcinfostruct;
'typedef struct threadlocaleinfostruct * pthreadlocinfo;
'typedef struct threadmbcinfostruct * pthreadmbcinfo;
'struct __lc_time_data;

' // Size = 8 bytes
TYPE localeinfo_struct DWORD
   locinfo AS DWORD   ' pthreadlocinfo
   mbcinfo AS DWORD   ' pthreadmbcinfo
END TYPE
MACRO locale_tstruct = localeinfo_struct

UNION locale_t DWORD
   localeinfo_struct
   quadinfo AS QUAD
END UNION

#IF NOT %DEF(%TAGLC_ID_DEFINED)
%TAGLC_ID_DEFINED = 1
' // Size = 6 bytes
TYPE tagLC_ID WORD
   wLanguage AS WORD   ' unsigned short
   wCountry  AS WORD   ' unsigned short
   wCodePage AS WORD   ' unsigned short
END TYPE
MACRO LC_ID = tagLC_ID
#ENDIF   '  /* _TAGLC_ID_DEFINED */

#IF NOT %DEF(%THREADLOCALEINFO)
%THREADLOCALEINFO = 1

TYPE threadlocinfo_inner_struct
   locale    AS ASCIIZ PTR     ' char *
   wlocale   AS WSTRINGZ PTR   ' wchar_t *
   refcount  AS LONG PTR       ' int *
   wrefcount AS LONG PTR       ' int *
END TYPE

TYPE threadlocaleinfostruct
   refcount            AS LONG                         ' int
   lc_codepage         AS DWORD                        ' unsigned int
   lc_collate_cp       AS DWORD                        ' unsigned int
   lc_handle(5)        AS DWORD                        ' unsigned long lc_handle[6] /* LCID */
   lc_id(5)            AS LC_ID                        ' lc_id[6];
   lc_category(5)      AS threadlocinfo_inner_struct   ' lc_category[6]
   lc_clike            AS LONG                         ' int
   mb_cur_max          AS LONG                         ' int
   lconv_intl_refcount AS LONG PTR                     ' int *
   lconv_num_refcount  AS LONG PTR                     ' int *
   lconv_mon_refcount  AS LONG PTR                     ' int *
   lconv               AS DWORD                        ' struct lconv * lconv;
   ctype1_refcount     AS LONG PTR                     ' int *
   ctype1              AS WORD PTR                     ' unsigned short *
   pctype              AS WORD PTR                     ' unsigned short *
   pclmap              AS BYTE PTR                     ' const unsigned char *
   pcumap              AS BYTE PTR                     ' const unsigned char * pcumap
   lc_time_curr        AS DWORD                        ' struct __lc_time_data *
END TYPE

MACRO threadlocinfo = threadlocaleinfostruct
#ENDIF   ' THREADLOCALEINFO

