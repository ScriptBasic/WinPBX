' ########################################################################################
' Microsoft C Runtime
' File: timeb.inc
' Contents: This file define the _ftime() function and the types it uses.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TIMEB_INC = 1

#INCLUDE ONCE "crtdefs.inc"

'/* Structure returned by _ftime system call */

#IF NOT %DEF(%TIMEB_DEFINED)
%TIMEB_DEFINED = 1
' // Size = 12 bytes
TYPE timeb
   time        AS LONG      ' time_t
   millitm     AS WORD      ' unsigned short
   timezone    AS INTEGER   ' short
   dstflag     AS INTEGER   ' short
   alignment__ AS WORD
END TYPE

' // Size = 12 bytes
TYPE timeb32
   time        AS LONG      ' __time32_t
   millitm     AS WORD      ' unsigned short
   timezone    AS INTEGER   ' short
   dstflag     AS INTEGER   ' short
   alignment__ AS WORD
END TYPE

' // Size = 16 bytes
TYPE timeb64 QWORD FILL
   time        AS QUAD      ' __time64_t
   millitm     AS WORD      ' unsigned short
   timezone    AS INTEGER   ' short
   dstflag     AS INTEGER   ' short
   alignment__ AS WORD
END TYPE
#ENDIF

'/* Function prototypes */

' ========================================================================================
DECLARE SUB ftime_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ftime" ( _
   BYREF timeptr AS timeb _                             ' struct _timeb *timeptr
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' _CRT_INSECURE_DEPRECATE(_ftime32_s) _CRTIMP void __cdecl _ftime32(_Out_ struct __timeb32 * _Time);
' ========================================================================================
DECLARE SUB ftime32_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ftime32" ( _
   BYREF timeptr AS timeb32 _                           ' __out struct __timeb32 *timeptr
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _ftime32_s(_Out_ struct __timeb32 * _Time);
' ========================================================================================
DECLARE FUNCTION ftime32_s CDECL IMPORT $CRT_DLLNAME ALIAS "_ftime32_s" ( _
   BYREF timeptr AS timeb32 _                           ' __out struct __timeb32 *timeptr
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRT_INSECURE_DEPRECATE(_ftime64_s) _CRTIMP void __cdecl _ftime64(_Out_ struct __timeb64 * _Time);
' ========================================================================================
DECLARE SUB ftime64 CDECL IMPORT $CRT_DLLNAME ALIAS "_ftime64" ( _
   BYREF timeptr AS timeb64 _                           ' __out struct __timeb64 *timeptr
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _ftime64_s(_Out_ struct __timeb64 * _Time);
' ========================================================================================
DECLARE FUNCTION ftime64_s CDECL IMPORT $CRT_DLLNAME ALIAS "_ftime64_s" ( _
   BYREF timeptr AS timeb64 _                           ' __out struct __timeb64 *timeptr
 ) AS LONG                                              ' errno_t
' ========================================================================================
