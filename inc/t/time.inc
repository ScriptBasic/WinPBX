' ########################################################################################
' Microsoft C Runtime
' File: time.inc
' Contents: This file has declarations of time routines and defines the structure
' returned by the localtime and gmtime routines and used by asctime.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TIME_INC = 1

#INCLUDE ONCE "crtdefs.inc"

'#ifndef _WCHAR_T_DEFINED
'typedef unsigned short wchar_t;
'#define _WCHAR_T_DEFINED
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

'#ifndef _CLOCK_T_DEFINED
'typedef long clock_t;
'#define _CLOCK_T_DEFINED
'#endif

'#ifndef _SIZE_T_DEFINED
'#ifdef  _WIN64
'typedef unsigned __int64    size_t;
'#else
'typedef _W64 unsigned int   size_t;
'#endif
'#define _SIZE_T_DEFINED
'#endif

#IF NOT %DEF(%TM_DEFINED)
%TM_DEFINED = 1
' // Size = 36 bytes
TYPE tm DWORD
   tm_sec   AS LONG   ' int /* seconds after the minute - [0,59] */
   tm_min   AS LONG   ' int /* minutes after the hour - [0,59] */
   tm_hour  AS LONG   ' int /* hours since midnight - [0,23] */
   tm_mday  AS LONG   ' int /* day of the month - [1,31] */
   tm_mon   AS LONG   ' int /* months since January - [0,11] */
   tm_year  AS LONG   ' int /* years since 1900 */
   tm_wday  AS LONG   ' int /* days since Sunday - [0,6] */
   tm_yday  AS LONG   ' int /* days since January 1 - [0,365] */
   tm_isdst AS LONG   ' int /* daylight savings time flag */
END TYPE
MACRO tm_type = tm   ' // For compatibility with the PB declares
#ENDIF

'/* Clock ticks macro - ANSI version */

%CLOCKS_PER_SEC = 1000

'/* non-zero if daylight savings time is used */
'_CRTIMP extern int _daylight;

FUNCTION getdaylight CDECL () AS LONG
   LOCAL hLib AS DWORD
   LOCAL phours AS LONG PTR
   hLib = LoadLibrary($CRT_DLLNAME)
   IF hLib THEN
      phours = GetProcAddress(hLib, "_daylight")
      IF phours THEN FUNCTION = @phours
      FreeLibrary hLib
   END IF
END FUNCTION

'/* offset for Daylight Saving Time */
'_CRTIMP extern long _dstbias;

FUNCTION getdstbias CDECL () AS LONG
   LOCAL hLib AS DWORD
   LOCAL pseconds AS LONG PTR
   hLib = LoadLibrary($CRT_DLLNAME)
   IF hLib THEN
      pseconds = GetProcAddress(hLib, "_dstbias")
      IF pseconds THEN FUNCTION = @pseconds
      FreeLibrary hLib
   END IF
END FUNCTION

'/* difference in seconds between GMT and local time */
'_CRTIMP extern long _timezone;

FUNCTION gettimezone CDECL () AS LONG
   LOCAL hLib AS DWORD
   LOCAL pseconds AS LONG PTR
   hLib = LoadLibrary($CRT_DLLNAME)
   IF hLib THEN
      pseconds = GetProcAddress(hLib, "_timezone")
      IF pseconds THEN FUNCTION = @pseconds
      FreeLibrary hLib
   END IF
END FUNCTION

'/* standard/daylight savings time zone names */
'_CRTIMP extern char * _tzname[2];

FUNCTION gettzname CDECL (BYVAL index AS LONG) AS STRING
   LOCAL hLib AS DWORD
   LOCAL ptzname AS ASCIIZ PTR
   IF index <> 0 AND index <> 1 THEN EXIT FUNCTION
   hLib = LoadLibrary($CRT_DLLNAME)
   IF hLib THEN
      ptzname = GetProcAddress(hLib, "_tzname")
      IF ptzname THEN
         ptzname = ptzname + (index * 4)   ' Calculate offset in the list
         FUNCTION = @@ptzname
      END IF
      FreeLibrary hLib
   END IF
END FUNCTION

' ========================================================================================
' _CRTIMP errno_t __cdecl _get_daylight(_Out_ int * _Daylight);
' ========================================================================================
DECLARE FUNCTION get_daylight CDECL IMPORT $CRT_DLLNAME ALIAS "_get_daylight" ( _
   BYREF hours AS LONG _                                ' __out int * hours
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _get_dstbias(_Out_ long * _Daylight_savings_bias);
' ========================================================================================
DECLARE FUNCTION get_dstbias CDECL IMPORT $CRT_DLLNAME ALIAS "_get_dstbias" ( _
   BYREF seconds AS LONG _                              ' __out int * seconds
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _get_timezone(_Out_ long * _Timezone);
' ========================================================================================
DECLARE FUNCTION get_timezone CDECL IMPORT $CRT_DLLNAME ALIAS "_get_timezone" ( _
   BYREF seconds AS LONG _                              ' __out int * seconds
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _get_tzname(_Out_ size_t *_ReturnValue,
' _Out_z_cap_(_SizeInBytes) char *_Buffer, _In_ size_t _SizeInBytes, _In_ int _Index);
' ========================================================================================
DECLARE FUNCTION get_tzname CDECL IMPORT $CRT_DLLNAME ALIAS "_get_tzname" ( _
   BYREF pReturnValue AS DWORD _                        ' __out size_t* pReturnValue
 , BYREF timeZoneName AS ASCIIZ _                       ' __out char* timeZoneName
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , BYVAL index AS LONG _                                ' __in int index
 ) AS LONG                                              ' errno_t
' ========================================================================================

'/* Function prototypes */

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_INSECURE_DEPRECATE(asctime_s) _CRTIMP char * __cdecl asctime(_In_ const struct tm * _Tm);
' ========================================================================================
DECLARE FUNCTION asctime CDECL IMPORT $CRT_DLLNAME ALIAS "asctime" ( _
   BYREF timeptr AS tm _                                ' __in const struct tm *timeptr
 ) AS DWORD                                             ' char *
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl asctime_s(_Out_cap_(_SizeInBytes) _Post_count_c_(26) char *_Buf,
' _In_ size_t _SizeInBytes, _In_ const struct tm * _Tm);
' ========================================================================================
DECLARE FUNCTION asctime_s CDECL IMPORT $CRT_DLLNAME ALIAS "asctime_s" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char* buffer
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , BYREF timeptr AS tm _                                ' __in const struct tm *timeptr
 ) AS LONG                                              ' errno_t
' ========================================================================================
'#endif

' ========================================================================================
DECLARE FUNCTION ctime CDECL IMPORT $CRT_DLLNAME ALIAS "ctime" ( _
   BYREF timer AS LONG _                                ' const time_t *timer
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRT_INSECURE_DEPRECATE(_ctime32_s) _CRTIMP char * __cdecl _ctime32(_In_ const __time32_t * _Time);
' ========================================================================================
DECLARE FUNCTION ctime32_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ctime32" ( _
   BYREF timer AS LONG _                                ' __in const _time32_t *timer
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _ctime32_s(_Out_cap_(_SizeInBytes) _Post_count_c_(26) char *_Buf,
' _In_ size_t _SizeInBytes, _In_ const __time32_t *_Time);
' ========================================================================================
DECLARE FUNCTION ctime32_s CDECL IMPORT $CRT_DLLNAME ALIAS "_ctime32_s" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char* buffer
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , BYVAL BYREF AS LONG _                                ' __in const _time32_t *timer
 ) AS DWORD                                             ' errno_t
' ========================================================================================
' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP clock_t __cdecl clock(void);
' ========================================================================================
DECLARE FUNCTION clock CDECL IMPORT $CRT_DLLNAME ALIAS "clock" ( _
 ) AS LONG                                              ' clock_t
' ========================================================================================

' ========================================================================================
DECLARE FUNCTION difftime CDECL IMPORT $CRT_DLLNAME ALIAS "difftime" ( _
   BYVAL timer1 AS LONG _                               ' time_t timer1
 , BYVAL timer0 AS LONG _                               ' time_t timer0
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' _CRTIMP double __cdecl _difftime32(_In_ __time32_t _Time1, _In_ __time32_t _Time2);
' ========================================================================================
DECLARE FUNCTION difftime32_ CDECL IMPORT $CRT_DLLNAME ALIAS "_difftime32" ( _
   BYVAL timer1 AS LONG _                               ' __in _time32_t timer1
 , BYVAL timer0 AS LONG _                               ' __in _time32_t timer0
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
DECLARE FUNCTION gmtime CDECL IMPORT $CRT_DLLNAME ALIAS "gmtime" ( _
   BYREF timer AS LONG _                                ' const time_t *timer
 ) AS DWORD                                             ' tm *
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRT_INSECURE_DEPRECATE(_gmtime32_s) _CRTIMP struct tm * __cdecl _gmtime32(_In_ const __time32_t * _Time);
' ========================================================================================
DECLARE FUNCTION gmtime32_ CDECL IMPORT $CRT_DLLNAME ALIAS "_gmtime32" ( _
   BYREF timer AS LONG _                                ' __in const _time32_t *timer
 ) AS DWORD                                             ' tm *
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _gmtime32_s(_In_ struct tm *_Tm, _In_ const __time32_t * _Time);
' ========================================================================================
DECLARE FUNCTION gmtime32_s CDECL IMPORT $CRT_DLLNAME ALIAS "_gmtime32_s" ( _
   BYREF timeptr AS tm _                                ' __in struct tm* timeptr
 , BYREF timer AS LONG _                                ' __in const __time32_t* time
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
DECLARE FUNCTION localtime CDECL LIB "msvcrt.dll" ALIAS "localtime" ( _
   BYREF timer AS LONG _                                ' const time_t *timer
 ) AS DWORD                                             ' tm *
' ========================================================================================

' ========================================================================================
' _CRT_INSECURE_DEPRECATE(_localtime32_s) _CRTIMP struct tm * __cdecl _localtime32(_In_ const __time32_t * _Time);
' ========================================================================================
DECLARE FUNCTION localtime32 CDECL IMPORT $CRT_DLLNAME ALIAS "_localtime32" ( _
   BYREF timer AS LONG _                                ' __in const _time32_t *timer
 ) AS DWORD                                             ' tm *
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _localtime32_s(_Out_ struct tm *_Tm, _In_ const __time32_t * _Time);
' ========================================================================================
DECLARE FUNCTION localtime32_s CDECL IMPORT $CRT_DLLNAME ALIAS "_localtime32_s" ( _
   BYREF timeptr AS tm _                                ' __out struct tm* timeptr
 , BYREF timer AS DWORD _                               ' __in const __time32_t* time
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP size_t __cdecl strftime(_Out_z_cap_(_SizeInBytes) char * _Buf,
' _In_ size_t _SizeInBytes, _In_z_ _Printf_format_string_ const char * _Format,
' _In_ const struct tm * _Tm);
' ========================================================================================
DECLARE FUNCTION strftime CDECL IMPORT $CRT_DLLNAME ALIAS "strftime" ( _
   BYREF strDest AS ASCIIZ _                            ' __out char *strDest
 , BYVAL maxsize AS DWORD _                             ' __in size_t maxsize
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , BYREF timeptr AS tm _                                ' __in const struct tm *timeptr
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' _CRTIMP size_t __cdecl _strftime_l(_Pre_notnull_ _Post_z_ char *_Buf,
' _In_ size_t _Max_size, _In_z_ _Printf_format_string_ const char * _Format,
' _In_ const struct tm *_Tm, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION strftime_l CDECL IMPORT $CRT_DLLNAME ALIAS "_strftime_l" ( _
   BYREF strDest AS ASCIIZ _                            ' __out char *strDest
 , BYVAL maxsize AS DWORD _                             ' __in size_t maxsize
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , BYREF timeptr AS tm _                                ' __in const struct tm *timeptr
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP char * __cdecl _strdate(char *);
' ========================================================================================
DECLARE FUNCTION strdate_ CDECL IMPORT $CRT_DLLNAME ALIAS "_strdate" ( _
   BYREF datestr AS ASCIIZ _                            ' __in char *datestr
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _strdate_s(_Out_cap_(_SizeInBytes) _Post_count_c_(9) char *_Buf, _In_ size_t _SizeInBytes);
' ========================================================================================
DECLARE FUNCTION strdate_s CDECL IMPORT $CRT_DLLNAME ALIAS "_strdate_s" ( _
   BYREF datestr AS ASCIIZ _                            ' __out char *datestr
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION strtime_ CDECL IMPORT $CRT_DLLNAME ALIAS "_strtime" ( _
   BYREF timestr AS ASCIIZ _                            ' __in char *timestr
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _strtime_s(_Out_cap_(_SizeInBytes) _Post_count_c_(9) char *_Buf , _In_ size_t _SizeInBytes);
' ========================================================================================
DECLARE FUNCTION strtime_s CDECL IMPORT $CRT_DLLNAME ALIAS "_strtime_s" ( _
   BYREF timestr AS ASCIIZ _                            ' __out char *timestr
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
DECLARE FUNCTION time CDECL IMPORT $CRT_DLLNAME ALIAS "time" ( _
   BYREF timer AS LONG _                                ' time_t *timer
 ) AS LONG                                              ' time_t
' ========================================================================================

' ========================================================================================
' _CRTIMP __time32_t __cdecl _time32(_Out_opt_ __time32_t * _Time);
' ========================================================================================
DECLARE FUNCTION time32_ CDECL IMPORT $CRT_DLLNAME ALIAS "_time32" ( _
   BYREF timer AS LONG _                                ' __out _time32_t *timer
 ) AS LONG                                              ' _time32_t
' ========================================================================================

' ========================================================================================
DECLARE FUNCTION mktime CDECL IMPORT $CRT_DLLNAME ALIAS "mktime" ( _
   BYREF timeptr AS tm _                                ' struct tm *timeptr
 ) AS LONG                                              ' time_t
' ========================================================================================

' ========================================================================================
' _CRTIMP __time32_t __cdecl _mktime32(_Inout_ struct tm * _Tm);
' ========================================================================================
DECLARE FUNCTION mktime32_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mktime32" ( _
   BYREF timeptr AS tm _                                ' __out struct tm *timeptr
 ) AS LONG                                              ' _time32_t
' ========================================================================================

' ========================================================================================
' _CRTIMP __time32_t __cdecl _mkgmtime32(_Inout_ struct tm * _Tm);
' ========================================================================================
DECLARE FUNCTION mkgmtime32_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mkgmtime32" ( _
   BYREF timeptr AS tm _                                ' __out struct tm *timeptr
 ) AS LONG                                              ' _time32_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP void __cdecl _tzset(void);
' ========================================================================================
DECLARE SUB tzset_ CDECL IMPORT $CRT_DLLNAME ALIAS "_tzset" ()
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP double __cdecl _difftime64(_In_ __time64_t _Time1, _In_ __time64_t _Time2);
' ========================================================================================
DECLARE FUNCTION difftime64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_difftime64" ( _
   BYVAL timer1 AS QUAD _                               ' __in __time64_t timer1
 , BYVAL timer0 AS QUAD _                               ' __in __time64_t timer0
 ) AS DOUBLE                                            ' double
' ========================================================================================

' ========================================================================================
' _CRT_INSECURE_DEPRECATE(_ctime64_s) _CRTIMP char * __cdecl _ctime64(_In_ const __time64_t * _Time);
' ========================================================================================
DECLARE FUNCTION ctime64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ctime64" ( _
   BYREF timer AS QUAD _                                ' __in const __time64_t *timer
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _ctime64_s(_Out_z_cap_(_SizeInBytes) char *_Buf, _In_ size_t _SizeInBytes, _In_ const __time64_t * _Time);
' ========================================================================================
DECLARE FUNCTION ctime64_s CDECL IMPORT $CRT_DLLNAME ALIAS "_ctime64_s" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char* buffer
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , BYREF timer AS QUAD _                                ' __in const __time64_t *timer
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRT_INSECURE_DEPRECATE(_gmtime64_s) _CRTIMP struct tm * __cdecl _gmtime64(_In_ const __time64_t * _Time);
' ========================================================================================
DECLARE FUNCTION gmtime64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_gmtime64" ( _
   BYREF timer AS QUAD _                                ' __in const __time64_t *timer
 ) AS DWORD                                             ' tm *
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _gmtime64_s(_Out_ struct tm *_Tm, _In_ const __time64_t *_Time);
' ========================================================================================
DECLARE FUNCTION gmtime64_s CDECL IMPORT $CRT_DLLNAME ALIAS "_gmtime64_s" ( _
   BYREF timeptr AS tm _                                ' __out struct tm* _tm
 , BYREF timer AS QUAD _                                ' __in const __time64_t *timer
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRT_INSECURE_DEPRECATE(_localtime64_s) _CRTIMP struct tm * __cdecl _localtime64(_In_ const __time64_t * _Time);
' ========================================================================================
DECLARE FUNCTION localtime64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_localtime64" ( _
   BYREF timer AS QUAD _                                ' __in const __time64_t *timer
 ) AS DWORD                                             ' tm *
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _localtime64_s(_Out_ struct tm *_Tm, _In_ const __time64_t *_Time);
' ========================================================================================
DECLARE FUNCTION localtime64_s CDECL IMPORT $CRT_DLLNAME ALIAS "_localtime64_s" ( _
   BYREF timeptr AS tm _                                ' __out struct tm* _tm
 , BYREF timer AS QUAD _                                ' __in const __time64_t *timer
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRTIMP __time64_t __cdecl _mktime64(_Inout_ struct tm * _Tm);
' ========================================================================================
DECLARE FUNCTION mktime64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mktime64" ( _
   BYREF timeptr AS tm _                                ' __out struct tm *timeptr
 ) AS QUAD                                              ' __time64_t
' ========================================================================================

' ========================================================================================
' _CRTIMP __time64_t __cdecl _mkgmtime64(_Inout_ struct tm * _Tm);
' ========================================================================================
DECLARE FUNCTION mkgmtime64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_mkgmtime64" ( _
   BYREF timeptr AS tm _                                ' __out struct tm *timeptr
 ) AS QUAD                                              ' __time64_t
' ========================================================================================

' ========================================================================================
' _CRTIMP __time64_t __cdecl _time64(_Out_opt_ __time64_t * _Time);
' ========================================================================================
DECLARE FUNCTION time64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_time64" ( _
   BYREF timer AS QUAD _                                ' __in __time64_t *timer
 ) AS QUAD                                              ' __time64_t
' ========================================================================================

'/* The Win32 API GetLocalTime and SetLocalTime should be used instead. */
'_CRT_OBSOLETE(GetLocalTime) unsigned __cdecl _getsystime(_Out_ struct tm * _Tm);
'_CRT_OBSOLETE(SetLocalTime) unsigned __cdecl _setsystime(_In_ struct tm * _Tm, unsigned _MilliSec);

#IF NOT %DEF(%WTIME_DEFINED)
%WTIME_DEFINED = 1

'/* wide function prototypes, also declared in wchar.h */

' ========================================================================================
' *** All versions ***
' _CRT_INSECURE_DEPRECATE(_wasctime_s) _CRTIMP wchar_t * __cdecl _wasctime(_In_ const struct tm * _Tm);
' ========================================================================================
DECLARE FUNCTION wasctime_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wasctime" ( _
   BYREF timeptr AS tm _                                ' __out const struct tm *timeptr
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _wasctime_s(_Out_cap_(_SizeInWords) _Post_count_c_(26) wchar_t *_Buf, _In_ size_t _SizeInWords, _In_ const struct tm * _Tm);
' ========================================================================================
DECLARE FUNCTION wasctime_s CDECL IMPORT $CRT_DLLNAME ALIAS "_wasctime_s" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t* buffer
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , BYREF timeptr AS tm _                                ' __in const struct tm *timeptr
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
DECLARE FUNCTION wctime_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wctime" ( _
   BYREF timer AS LONG _                                ' const time_t *timer
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' _CRT_INSECURE_DEPRECATE(_wctime32_s) _CRTIMP wchar_t * __cdecl _wctime32(_In_ const __time32_t *_Time);
' ========================================================================================
DECLARE FUNCTION wctime32_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wctime32" ( _
   BYREF timer AS LONG _                                ' __in const time_t *timer
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _wctime32_s(_Out_cap_(_SizeInWords) _Post_count_c_(26) wchar_t* _Buf, _In_ size_t _SizeInWords, _In_ const __time32_t * _Time);
' ========================================================================================
DECLARE FUNCTION wctime32_s CDECL IMPORT $CRT_DLLNAME ALIAS "_wctime32_s" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t* buffer
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , BYREF timer AS LONG _                                ' __in const _time32_t *timer
 ) AS DWORD                                             ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP size_t __cdecl wcsftime(_Out_z_cap_(_SizeInWords) wchar_t * _Buf,
' _In_ size_t _SizeInWords, _In_z_ _Printf_format_string_ const wchar_t * _Format,  _In_ const struct tm * _Tm);
' ========================================================================================
DECLARE FUNCTION wcsftime CDECL IMPORT $CRT_DLLNAME ALIAS "wcsftime" ( _
   BYREF strDest AS WSTRINGZ _                          ' __out wchar_t *strDest
 , BYVAL maxsize AS DWORD _                             ' __in size_t maxsize
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , BYREF timeptr AS tm _                                ' __in const struct tm *timeptr
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' _CRTIMP size_t __cdecl _wcsftime_l(_Out_z_cap_(_SizeInWords) wchar_t * _Buf,
' _In_ size_t _SizeInWords, _In_z_ _Printf_format_string_ const wchar_t *_Format,
' _In_ const struct tm *_Tm, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION wcsftime_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wcsftime_l" ( _
   BYREF strDest AS WSTRINGZ _                          ' __out wchar_t *strDest
 , BYVAL maxsize AS DWORD _                             ' __in size_t maxsize
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , BYREF timeptr AS tm _                                ' __in const struct tm *timeptr
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t lccale
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION wstrdate_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wstrdate" ( _
   BYREF datestr AS WSTRINGZ _                          ' __out wchar_t *datestr
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _wstrdate_s(_Out_cap_(_SizeInWords) _Post_count_c_(9) wchar_t * _Buf, _In_ size_t _SizeInWords);
' ========================================================================================
DECLARE FUNCTION wstrdate_s CDECL IMPORT $CRT_DLLNAME ALIAS "_wstrdate_s" ( _
   BYREF datestr AS WSTRINGZ _                          ' __out wchar_t *datestr
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION wstrtime_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wstrtime" ( _
   BYREF timestr AS WSTRINGZ _                          ' __out wchar_t *timestr
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _wstrtime_s(_Out_cap_(_SizeInWords) _Post_count_c_(9) wchar_t * _Buf, _In_ size_t _SizeInWords);
' ========================================================================================
DECLARE FUNCTION wstrtime_s CDECL IMPORT $CRT_DLLNAME ALIAS "_wstrtime_s" ( _
   BYREF timestr AS WSTRINGZ _                          ' __out wchar_t *timestr
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRT_INSECURE_DEPRECATE(_wctime64_s) _CRTIMP wchar_t * __cdecl _wctime64(_In_ const __time64_t * _Time);
' ========================================================================================
DECLARE FUNCTION wctime64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wctime64" ( _
   BYREF timer AS QUAD _                                ' __in const __time64_t *time
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _wctime64_s(_Out_cap_(_SizeInWords) _Post_count_c_(26) wchar_t* _Buf, _In_ size_t _SizeInWords, _In_ const __time64_t *_Time);
' ========================================================================================
DECLARE FUNCTION wctime64_s CDECL IMPORT $CRT_DLLNAME ALIAS "_wctime64_s" ( _
   BYREF timestr AS WSTRINGZ _                          ' __out wchar_t *timestr
 , BYVAL numberOfElements AS DWORD _                    ' __in size_t numberOfElements
 , BYREF timer AS QUAD _                                ' __in const __time64_t *time
 ) AS LONG                                              ' errno_t
' ========================================================================================

#ENDIF   ' WTIME_DEFINED
