' ########################################################################################
' Microsoft Windows
' File: shlwapi.inc
' Contents: Interface for the Windows light-weight utility APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SHLWAPI_INC = 1

#IF NOT %DEF(%NOSHLWAPI)

#INCLUDE ONCE "objbase.inc"
#INCLUDE ONCE "shtypes.inc"

'//
'// Users of this header may define any number of these constants to avoid
'// the definitions of each functional group.
'//
'//    NO_SHLWAPI_STRFCNS    String functions
'//    NO_SHLWAPI_PATH       Path functions
'//    NO_SHLWAPI_REG        Registry functions
'//    NO_SHLWAPI_STREAM     Stream functions
'//    NO_SHLWAPI_GDI        GDI helper functions

#IF NOT %DEF (%NO_SHLWAPI_STRFCNS)
'//
'//=============== String Routines ===================================
'//

DECLARE FUNCTION StrChrA IMPORT "SHLWAPI.DLL" ALIAS "StrChrA" ( _
   BYREF lpStart AS ASCIIZ _                            ' __in LPCSTR lpStart
 , BYVAL wMatch AS WORD _                               ' __in WORD wMatch
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION StrChrW IMPORT "SHLWAPI.DLL" ALIAS "StrChrW" ( _
   BYREF lpStart AS WSTRINGZ _                          ' __in LPCWSTR lpStart
 , BYVAL wMatch AS WORD _                               ' __in WCHAR wMatch
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO StrChr = StrChrW
#ELSE
   MACRO StrChr = StrChrA
#ENDIF

DECLARE FUNCTION StrChrIA IMPORT "SHLWAPI.DLL" ALIAS "StrChrIA" ( _
   BYREF lpStart AS ASCIIZ _                            ' __in LPCSTR lpStart
 , BYVAL wMatch AS WORD _                               ' __in WORD wMatch
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION StrChrIW IMPORT "SHLWAPI.DLL" ALIAS "StrChrIW" ( _
   BYREF lpStart AS WSTRINGZ _                          ' __in LPCWSTR lpStart
 , BYVAL wMatch AS WORD _                               ' __in WCHAR wMatch
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO StrChrI = StrChrIW
#ELSE
   MACRO StrChrI = StrChrIA
#ENDIF

DECLARE FUNCTION StrCmpNA IMPORT "SHLWAPI.DLL" ALIAS "StrCmpNA" ( _
   BYREF lpStr1 AS ASCIIZ _                             ' __in LPCSTR lpStr1
 , BYREF lpStr2 AS ASCIIZ _                             ' __in LPCSTR lpStr2
 , BYVAL nChar AS LONG _                                ' __in int nChar
 ) AS LONG                                              ' int

DECLARE FUNCTION StrCmpNW IMPORT "SHLWAPI.DLL" ALIAS "StrCmpNW" ( _
   BYREF lpStr1 AS WSTRINGZ _                           ' __in LPCWSTR lpStr1
 , BYREF lpStr2 AS WSTRINGZ _                           ' __in LPCWSTR lpStr2
 , BYVAL nChar AS LONG _                                ' __in int nChar
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO StrCmpN = StrCmpNW
#ELSE
   MACRO StrCmpN = StrCmpNA
#ENDIF

DECLARE FUNCTION StrCmpNIA IMPORT "SHLWAPI.DLL" ALIAS "StrCmpNIA" ( _
   BYREF lpStr1 AS ASCIIZ _                             ' __in LPCSTR lpStr1
 , BYREF lpStr2 AS ASCIIZ _                             ' __in LPCSTR lpStr2
 , BYVAL nChar As LONG _                                ' __in int nChar
 ) AS LONG                                              ' int

DECLARE FUNCTION StrCmpNIW IMPORT "SHLWAPI.DLL" ALIAS "StrCmpNIW" ( _
   BYREF lpStr1 AS WSTRINGZ _                           ' __in LPCWSTR lpStr1
 , BYREF lpStr2 AS WSTRINGZ _                           ' __in LPCWSTR lpStr2
 , BYVAL nChar AS LONG _                                ' __in int nChar
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO StrCmpNI = StrCmpNIW
#ELSE
   MACRO StrCmpNI = StrCmpNIA
#ENDIF

DECLARE FUNCTION StrCSpnA IMPORT "SHLWAPI.DLL" ALIAS "StrCSpnA" ( _
   BYREF lpStr AS ASCIIZ _                              ' __in LPCSTR lpStr
 , BYREF lpSet AS ASCIIZ _                              ' __in LPCSTR lpSet
 ) AS LONG                                              ' int

DECLARE FUNCTION StrCSpnW IMPORT "SHLWAPI.DLL" ALIAS "StrCSpnW" ( _
   BYREF lpStr AS WSTRINGZ _                            ' __in LPCWSTR lpStr
 , BYREF lpSet AS WSTRINGZ _                            ' __in LPCWSTR lpSet
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO StrCSpn = StrCSpnW
#ELSE
   MACRO StrCSpn = StrCSpnA
#ENDIF

DECLARE FUNCTION StrCSpnIA IMPORT "SHLWAPI.DLL" ALIAS "StrCSpnIA" ( _
   BYREF lpStr AS ASCIIZ _                              ' __in LPCSTR lpStr
 , BYREF lpSet AS ASCIIZ _                              ' __in LPCSTR lpSet
 ) AS LONG                                              ' int

DECLARE FUNCTION StrCSpnIW IMPORT "SHLWAPI.DLL" ALIAS "StrSpnIW" ( _
   BYREF lpStr AS WSTRINGZ _                            ' __in LPCWSTR lpStr
 , BYREF lpSet AS WSTRINGZ _                            ' __in LPCWSTR lpSet
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO StrCSpnI = StrCSpnIW
#ELSE
   MACRO StrCSpnI = StrCSpnIA
#ENDIF

DECLARE FUNCTION StrDupA IMPORT "SHLWAPI.DLL" ALIAS "StrDupA" ( _
   BYREF lpsz AS ASCIIZ _                               ' __in LPCSTR lpsz
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION StrDupW IMPORT "SHLWAPI.DLL" ALIAS "StrDupW" ( _
   BYREF lpsz AS WSTRINGZ _                             ' __in LPCWSTR lpsz
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO StrDup = StrDupW
#ELSE
   MACRO StrDup = StrDupA
#ENDIF

'// StrFormatByteSizeEx takes a ULONGLONG as a byte count and formats a string
'// representing that number of bytes in an appropriately concise manner, where
'// "appropriate manner" is determine by several factors:
'//
'// 1) order - is this most appropriately expressed as KB? MB? GB?
'//    for example: 1039 -> "1.01 KB", 5454608466 -> "5.08 GB", etc
'//
'// 2) number of whole number places shown - if there are more than a few whole
'//    number places to display, decimal places are omitted.
'//    for example: 1024 -> "1.00 KB", 12288 -> "12.0 KB", 125952 -> "123 KB"
'//
'// 3) the caller can specify whether the result should involve rounding to the
'//    nearest displayed digit, or truncation of undisplayed digits. the caller
'//    must specify either rounding or truncation when calling the API.
'//    for example: with rounding,   2147483647 -> "2.00 GB"
'//                 with truncation, 2147483647 -> "1.99 GB"

' enum tagSFBS_FLAGS
%SFBS_FLAGS_ROUND_TO_NEAREST_DISPLAYED_DIGIT     = &H0001&   ' // round to the nearest displayed digit
%SFBS_FLAGS_TRUNCATE_UNDISPLAYED_DECIMAL_DIGITS  = &H0002&   ' // discard undisplayed digits

'typedef int SFBS_FLAGS;

DECLARE FUNCTION StrFormatByteSizeEx IMPORT "SHLWAPI.DLL" ALIAS "StrFormatByteSizeEx" ( _
   BYVAL ull AS QUAD _                                  ' __in ULONGLONG ull
 , BYVAL flags AS DWORD _                               ' __in SFBS_FLAGS flags
 , BYREF pszBuf AS WSTRINGZ _                           ' __out_ecount(cchBuf) LPWSTR pszBuf
 , BYVAL cchBuf AS DWORD _                              ' __in_range(>,0) UINT cchBuf
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StrFormatByteSizeA IMPORT "SHLWAPI.DLL" ALIAS "StrFormatByteSizeA" ( _
   BYVAL dw AS DWORD _                                  ' __in DWORD dw
 , BYREF pszBuf AS ASCIIZ _                             ' __out LPSTR pszBuf
 , BYVAL cchBuf AS DWORD _                              ' __in UINT cchBuf
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION StrFormatByteSizeW IMPORT "SHLWAPI.DLL" ALIAS "StrFormatByteSizeW" ( _
   BYVAL qdw AS QUAD _                                  ' __in LONGLONG qdw
 , BYREF pszBuf AS WSTRINGZ _                           ' __out LPWSTR pszBuf
 , BYVAL cchBuf AS DWORD _                              ' __in UINT cchBuf
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO StrFormatByteSize = StrFormatByteSizeW
#ELSE
   MACRO StrFormatByteSize = StrFormatByteSizeA
#ENDIF

DECLARE FUNCTION StrFormatByteSize64A IMPORT "SHLWAPI.DLL" ALIAS "StrFormatByteSize64A" ( _
   BYVAL qdw AS QUAD _                                  ' __in LONGLONG qdw
 , BYREF pszBuf AS ASCIIZ _                             ' __out LPSTR pszBuf
 , BYVAL uiBufSize AS DWORD _                           ' __in UINT uiBufSize
 ) AS DWORD                                             ' LPSTR

' StrFormatByteSize64 can be used for either ANSI or Unicode characters. However, while StrFormatByteSize64A
' can be called directly, StrFormatByteSize64W is not defined. When StrFormatByteSize64 is called with a
' Unicode value, StrFormatByteSizeW is used.
#IF %DEF(%UNICODE)
   MACRO StrFormatByteSize64 = StrFormatByteSizeW
#ELSE
   MACRO StrFormatByteSize64 = StrFormatByteSize64A
#ENDIF

DECLARE FUNCTION StrFormatKBSizeA IMPORT "SHLWAPI.DLL" ALIAS "StrFormatKBSizeA" ( _
   BYVAL qdw AS QUAD _                                  ' __in LONGLONG qdw
 , BYREF pszBuf AS ASCIIZ _                             ' __out LPSTR pszBuf
 , BYVAL uiBufSize AS DWORD _                           ' __in UINT uiBufSize
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION StrFormatKBSizeW IMPORT "SHLWAPI.DLL" ALIAS "StrFormatKBSizeW" ( _
   BYVAL qdw AS QUAD _                                  ' __in LONGLONG qdw
 , BYREF pszBuf AS WSTRINGZ _                           ' __out LPWSTR pszBuf
 , BYVAL uiBufSize AS DWORD _                           ' __in UINT uiBufSize
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO StrFormatKBSize = StrFormatKBSizeW
#ELSE
   MACRO StrFormatKBSize = StrFormatKBSizeA
#ENDIF

DECLARE FUNCTION StrFromTimeIntervalA IMPORT "SHLWAPI.DLL" ALIAS "StrFromTimeIntervalA" ( _
   BYREF pszOut AS ASCIIZ _                             ' __out LPSTR pszOut
 , BYVAL cchMax AS DWORD _                              ' __in UINT cchMax
 , BYVAL dwTimeMS AS DWORD _                            ' __in DWORD dwTimeMS
 , BYVAL digits AS LONG _                               ' __in int digits
 ) AS LONG                                              ' int

DECLARE FUNCTION StrFromTimeIntervalW IMPORT "SHLWAPI.DLL" ALIAS "StrFromTimeIntervalW" ( _
   BYREF pszOut AS WSTRINGZ _                           ' __out LPWSTR pszOut
 , BYVAL cchMax AS DWORD _                              ' __in UINT cchMax
 , BYVAL dwTimeMS AS DWORD _                            ' __in DWORD dwTimeMS
 , BYVAL digits AS LONG _                               ' __in int digits
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO StrFromTimeInterval = StrFromTimeIntervalW
#ELSE
   MACRO StrFromTimeInterval = StrFromTimeIntervalA
#ENDIF

DECLARE FUNCTION StrIsIntlEqualA IMPORT "SHLWAPI.DLL" ALIAS "StrIsIntlEqualA" ( _
   BYVAL fCaseSens AS LONG _                            ' __in BOOL fCaseSens
 , BYREF lpString1 AS ASCIIZ _                          ' __in LPCSTR lpString1
 , BYREF lpString2 AS ASCIIZ _                          ' __in LPCSTR lpString2
 , BYVAL nChar AS LONG _                                ' __in int nChar
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION StrIsIntlEqualW IMPORT "SHLWAPI.DLL" ALIAS "StrIsIntlEqualW" ( _
   BYVAL fCaseSens AS LONG _                            ' __in BOOL fCaseSens
 , BYREF lpString1 AS WSTRINGZ _                        ' __in LPCWSTR lpString1
 , BYREF lpString2 AS WSTRINGZ _                        ' __in LPCWSTR lpString2
 , BYVAL nChar AS LONG _                                ' __in int nChar
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO StrIsIntlEqual = StrIsIntlEqualW
#ELSE
   MACRO StrIsIntlEqual = StrIsIntlEqualA
#ENDIF

DECLARE FUNCTION StrNCatA IMPORT "SHLWAPI.DLL" ALIAS "StrNCatA" ( _
   BYREF pszFront AS ASCIIZ _                           ' __in LPSTR pszFront
 , BYREF pszBack AS ASCIIZ _                            ' __in LPCSTR pszBack
 , BYVAL cchMax AS LONG _                               ' __in int cchMax
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION StrNCatW IMPORT "SHLWAPI.DLL" ALIAS "StrNCatW" ( _
   BYREF pszFront AS WSTRINGZ _                         ' __in LPWSTR pszFront
 , BYREF pszBack AS WSTRINGZ _                          ' __in LPCWSTR pszBack
 , BYVAL cchMax AS LONG _                               ' __in int cchMax
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO StrNCat = StrNCatW
#ELSE
   MACRO StrNCat = StrNCatA
#ENDIF

DECLARE FUNCTION StrPBrkA IMPORT "SHLWAPI.DLL" ALIAS "StrPBrkA" ( _
   BYREF psz AS ASCIIZ _                                ' __in LPCSTR psz
 , BYREF pszSet AS ASCIIZ _                             ' __in LPCSTR pszSet
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION StrPBrkW IMPORT "SHLWAPI.DLL" ALIAS "StrPBrkW" ( _
   BYREF psz AS WSTRINGZ _                              ' __in LPCWSTR psz
 , BYREF pszSet AS WSTRINGZ _                           ' __in LPCWSTR pszSet
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO StrPBrk = StrPBrkW
#ELSE
   MACRO StrPBrk = StrPBrkA
#ENDIF

DECLARE FUNCTION StrRChrA IMPORT "SHLWAPI.DLL" ALIAS "StrRChrA" ( _
   BYREF lpStart AS ASCIIZ _                            ' __in LPCSTR lpStart
 , BYREF lpEnd AS ASCIIZ _                              ' __in LPCSTR lpEnd
 , BYVAL wMatch AS BYTE _                               ' __in CHAR wMatch
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION StrRChrW IMPORT "SHLWAPI.DLL" ALIAS "StrRChrW" ( _
   BYREF lpStart AS WSTRINGZ _                          ' __in LPCWSTR lpStart
 , BYREF lpEnd AS WSTRINGZ _                            ' __in LPCWSTR lpEnd
 , BYVAL wMatch AS WORD _                               ' __in WCHAR wMatch
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO StrRChr = StrRChrW
#ELSE
   MACRO StrRChr = StrRChrA
#ENDIF

DECLARE FUNCTION StrRChrIA IMPORT "SHLWAPI.DLL" ALIAS "StrRChrIA" ( _
   BYREF lpStart AS ASCIIZ _                            ' __in LPCSTR lpStart
 , BYREF lpEnd AS ASCIIZ _                              ' __in LPCSTR lpEnd
 , BYVAL wMatch AS BYTE _                               ' __in CHAR wMatch
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION StrRChrIW IMPORT "SHLWAPI.DLL" ALIAS "StrRChrIW" ( _
   BYREF lpStart AS WSTRINGZ _                          ' __in LPCWSTR lpStart
 , BYREF lpEnd AS WSTRINGZ _                            ' __in LPCWSTR lpEnd
 , BYVAL wMatch AS WORD _                               ' __in WCHAR wMatch
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO StrRChrI = StrRChrIW
#ELSE
   MACRO StrRChrI = StrRChrIA
#ENDIF

DECLARE FUNCTION StrRStrIA IMPORT "SHLWAPI.DLL" ALIAS "StrRStrIA" ( _
   BYREF pszSource AS ASCIIZ _                          ' __in LPCSTR pszSource
 , BYREF pszLast AS ASCIIZ _                            ' __in LPCSTR pszLast
 , BYREF pszSrch AS ASCIIZ _                            ' __in LPCSTR pszSrch
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION StrRStrIW IMPORT "SHLWAPI.DLL" ALIAS "StrRStrIW" ( _
   BYREF pszSource AS WSTRINGZ _                        ' __in LPCWSTR pszSource
 , BYREF pszLast AS WSTRINGZ _                          ' __in LPCWSTR pszLast
 , BYREF pszSrch AS WSTRINGZ _                          ' __in LPCWSTR pszSrch
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO StrRStrI = StrRStrIW
#ELSE
   MACRO StrRStrI = StrRStrIA
#ENDIF

DECLARE FUNCTION StrSpnA IMPORT "SHLWAPI.DLL" ALIAS "StrSpnA" ( _
   BYREF psz AS ASCIIZ _                                ' __in LPCSTR psz
 , BYREF pszSet AS ASCIIZ _                             ' __in LPCSTR pszSet
 ) AS LONG                                              ' int

DECLARE FUNCTION StrSpnW IMPORT "SHLWAPI.DLL" ALIAS "StrSpnW" ( _
   BYREF psz AS WSTRINGZ _                              ' __in LPCWSTR psz
 , BYREF pszSet AS WSTRINGZ _                           ' __in LPCWSTR pszSet
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO StrSpn = StrSpnW
#ELSE
   MACRO StrSpn = StrSpnA
#ENDIF

DECLARE FUNCTION StrStrA IMPORT "SHLWAPI.DLL" ALIAS "StrStrA" ( _
   BYREF lpFirst AS ASCIIZ _                            ' __in LPCSTR lpFirst
 , BYREF lpSrch AS ASCIIZ _                             ' __in LPCSTR lpSrch
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION StrStrW IMPORT "SHLWAPI.DLL" ALIAS "StrStrW" ( _
   BYREF lpFirst AS WSTRINGZ _                          ' __in LPCWSTR lpFirst
 , BYREF lpSrch AS WSTRINGZ _                           ' __in LPCWSTR lpSrch
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO StrStr = StrStrW
#ELSE
   MACRO StrStr = StrStrA
#ENDIF

DECLARE FUNCTION StrStrIA IMPORT "SHLWAPI.DLL" ALIAS "StrStrIA" ( _
   BYREF lpFirst AS ASCIIZ _                            ' __in LPCSTR lpFirst
 , BYREF lpSrch AS ASCIIZ _                             ' __in LPCSTR lpSrch
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION StrStrIW IMPORT "SHLWAPI.DLL" ALIAS "StrStrIW" ( _
   BYREF lpFirst AS WSTRINGZ _                          ' __in LPCWSTR lpFirst
 , BYREF lpSrch AS WSTRINGZ _                           ' __in LPCWSTR lpSrch
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO StrStrI = StrStrIW
#ELSE
   MACRO StrStrI = StrStrIA
#ENDIF

DECLARE FUNCTION StrToIntA IMPORT "SHLWAPI.DLL" ALIAS "StrToIntA" ( _
   BYREF lpSrc AS ASCIIZ _                              ' __in LPCSTR lpSrc
 ) AS LONG                                              ' int

DECLARE FUNCTION StrToIntW IMPORT "SHLWAPI.DLL" ALIAS "StrToIntW" ( _
   BYREF lpSrc AS WSTRINGZ _                            ' __in LPCWSTR lpSrc
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO StrToInt = StrToIntW
#ELSE
   MACRO StrToInt = StrToIntA
#ENDIF

DECLARE FUNCTION StrToIntExA IMPORT "SHLWAPI.DLL" ALIAS "StrToIntExA" ( _
   BYREF pszString AS ASCIIZ _                          ' __in LPCSTR pszString
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF piRet AS LONG _                                ' __out int *piRet
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION StrToIntExW IMPORT "SHLWAPI.DLL" ALIAS "StrToIntExW" ( _
   BYREF pszString AS WSTRINGZ _                        ' __in LPCWSTR pszString
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF piRet AS LONG _                                ' __out int *piRet
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO StrToIntEx = StrToIntExW
#ELSE
   MACRO StrToIntEx = StrToIntExA
#ENDIF

'#if (_WIN32_IE >= _WIN32_IE_IE60)
DECLARE FUNCTION StrToInt64ExA IMPORT "SHLWAPI.DLL" ALIAS "StrToInt64ExA" ( _
   BYREF pszString AS ASCIIZ _                          ' __in LPCSTR pszString
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pllRet AS QUAD _                               ' __out LONGLONG *pllRet
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION StrToInt64ExW IMPORT "SHLWAPI.DLL" ALIAS "StrToInt64ExW" ( _
   BYREF pszString AS WSTRINGZ _                        ' __in LPCWSTR pszString
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pllRet AS QUAD _                               ' __out LONGLONG *pllRet
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO StrToInt64Ex = StrToInt64ExW
#ELSE
   MACRO StrToInt64Ex = StrToInt64ExA
#ENDIF
'#endif // _WIN32_IE_IE60

DECLARE FUNCTION StrTrimA IMPORT "SHLWAPI.DLL" ALIAS "StrTrimA" ( _
   BYREF pszSource AS ASCIIZ _                          ' __inout LPSTR pszSource
 , BYREF pszTrimChars AS ASCIIZ _                       ' __in LPCSTR pszTrimChars
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION StrTrimW IMPORT "SHLWAPI.DLL" ALIAS "StrTrimW" ( _
   BYREF pszSource AS WSTRINGZ _                        ' __inout LPWSTR pszSource
 , BYREF pszTrimChars AS WSTRINGZ _                     ' __in LPCWSTR pszTrimChars
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO StrTrim = StrTrimW
#ELSE
   MACRO StrTrim = StrTrimA
#ENDIF

DECLARE FUNCTION StrCatA IMPORT "KERNEL32.DLL" ALIAS "lstrcatA" ( _
   BYREF psz1 AS ASCIIZ _                               ' __inout LPSTR psz1
 , BYREF psz2 AS ASCIIZ _                               ' __in LPSTR psz2
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION StrCatW IMPORT "SHLWAPI.DLL" ALIAS "StrCatW" ( _
   BYREF psz1 AS WSTRINGZ _                             ' __inout LPWSTR psz1
 , BYREF psz2 AS WSTRINGZ _                             ' __in LPWSTR psz2
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO StrCat = StrCatW
#ELSE
   MACRO StrCat = StrCatA
#ENDIF

DECLARE FUNCTION StrCmpA IMPORT "KERNEL32.DLL" ALIAS "lstrcmpA" ( _
   BYREF psz1 AS ASCIIZ _                               ' __in LPCSTR psz1
 , BYREF psz2 AS ASCIIZ _                               ' __in LPCSTR psz2
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION StrCmpW IMPORT "SHLWAPI.DLL" ALIAS "StrCmpW" ( _
   BYREF lpStr1 AS WSTRINGZ _                           ' __in LPCWSTR lpStr1
 , BYREF lpStr2 AS WSTRINGZ _                           ' __in LPCWSTR lpStr2
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO StrCmp = StrCmpW
#ELSE
   MACRO StrCmp = StrCmpA
#ENDIF

MACRO StrCmpIA = lstrcmpiA

DECLARE FUNCTION StrCmpIW IMPORT "SHLWAPI.DLL" ALIAS "StrCmpIW" ( _
   BYREF lpStr1 AS WSTRINGZ _                           ' __in LPCWSTR lpStr1
 , BYREF lpStr2 AS WSTRINGZ _                           ' __in LPCWSTR lpStr2
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO StrCmpI = StrCmpIW
#ELSE
   MACRO StrCmpI = StrCmpIA
#ENDIF

MACRO StrCpyA = lstrcpyA

DECLARE FUNCTION StrCpyW IMPORT "SHLWAPI.DLL" ALIAS "StrCpyW" ( _
   BYREF lpStr1 AS WSTRINGZ _                           ' __out LPWSTR lpStr1
 , BYREF lpStr1 AS WSTRINGZ _                           ' __in LPCWSTR lpStr1
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO StrCpy = StrCpyW
#ELSE
   MACRO StrCpy = StrCpyA
#ENDIF

MACRO StrCpyNA = lstrcpynA

DECLARE FUNCTION StrCpyNW IMPORT "SHLWAPI.DLL" ALIAS "StrCpyNW" ( _
   BYREF psz1 AS WSTRINGZ _                             ' __in LPWSTR psz1
 , BYREF psz2 AS WSTRINGZ _                             ' __in LPCWSTR psz2
 , BYVAL cchMax AS LONG _                               ' __in int cchMax
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO StrCpyN = StrCpyNW
#ELSE
   MACRO StrCpyN = StrCpyNA
#ENDIF

DECLARE FUNCTION StrCatBuffW IMPORT "SHLWAPI.DLL" ALIAS "StrCatBuffW" ( _
   BYREF pszDestination AS WSTRINGZ _                   ' __inout LPWSTR pszDestination
 , BYREF pszSource AS WSTRINGZ _                        ' __in LPCWSTR pszSource
 , BYVAL cchDestBuffSize AS LONG _                      ' __in int cchDestBuffSize
 ) AS DWORD                                             ' LPWSTR

DECLARE FUNCTION StrCatBuffA IMPORT "SHLWAPI.DLL" ALIAS "StrCatBuffA" ( _
   BYREF pszDestination AS ASCIIZ _                     ' __inout LPSTR pszDestination
 , BYREF pszSource AS ASCIIZ _                          ' __in LPCSTR pszSource
 , BYVAL cchDestBuffSize AS LONG _                      ' __in int cchDestBuffSize
 ) AS DWORD                                             ' LPSTR

#IF %DEF(%UNICODE)
   MACRO StrCatBuff = StrCatBuffW
#ELSE
   MACRO StrCatBuff = StrCatBuffA
#ENDIF

DECLARE FUNCTION ChrCmpIA IMPORT "SHLWAPI.DLL" ALIAS "ChrCmpIA" ( _
   BYVAL w1 AS BYTE _                                   ' __in CHAR w1
 , BYVAL w2 AS BYTE _                                   ' __in CHAR w2
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ChrCmpIW IMPORT "SHLWAPI.DLL" ALIAS "ChrCmpIW" ( _
   BYVAL w1 AS WORD _                                   ' __in WCHAR w1
 , BYVAL w2 AS WORD _                                   ' __in WCHAR w2
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ChrCmpI = ChrCmpIW
#ELSE
   MACRO ChrCmpI = ChrCmpIA
#ENDIF

DECLARE FUNCTION wvnsprintfA CDECL IMPORT "SHLWAPI.DLL" ALIAS "wvnsprintfA" ( _
   BYREF lpOut AS ASCIIZ _                              ' __out LPSTR lpOut
 , BYVAL cchLimitIn AS LONG _                           ' __in int cchLimitIn
 , BYREF pszFmt AS ASCIIZ _                             ' __in LPCWSTR pszFmt
 , BYREF arglist AS ANY _                               ' __in va_list arglist
 ) AS LONG                                              ' int

DECLARE FUNCTION wvnsprintfW CDECL IMPORT "SHLWAPI.DLL" ALIAS "wvnsprintfW" ( _
   BYREF lpOut AS WSTRINGZ _                            ' __out LPWSTR lpOut
 , BYVAL cchLimitIn AS LONG _                           ' __in int cchLimitIn
 , BYREF pszFmt AS WSTRINGZ _                           ' __in LPCWSTR pszFmt
 , BYREF arglist AS ANY _                               ' __in va_list arglist
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO wvnsprintf = wvnsprintfW
#ELSE
   MACRO wvnsprintf = wvnsprintfA
#ENDIF

DECLARE FUNCTION wnsprintfA CDECL IMPORT "SHLWAPI.DLL" ALIAS "wnsprintfA" ( _
   BYREF lpOut AS ASCIIZ _                              ' __out LPSTR lpOut
 , BYVAL cchLimitIn AS LONG _                           ' __in int cchLimitIn
 , BYREF pszFmt AS ASCIIZ _                             ' __in LPCSTR pszFmt
 , OPTIONAL BYREF ANY _                                 ' optional parameters
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 ) AS LONG                                              ' int

DECLARE FUNCTION wnsprintfW CDECL IMPORT "SHLWAPI.DLL" ALIAS "wnsprintfW" ( _
   BYREF lpOut AS WSTRINGZ _                               ' __out LPWSTR lpOut
 , BYVAL cchLimitIn AS LONG _                           ' __in int cchLimitIn
 , BYREF pszFmt AS ASCIIZ _                             ' __in LPCSTR pszFmt
 , OPTIONAL BYREF ANY _                                 ' optional parameters
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO wnsprintf = wnsprintfW
#ELSE
   MACRO wnsprintf = wnsprintfA
#ENDIF

'#define StrIntlEqNA( s1, s2, nChar) StrIsIntlEqualA( TRUE, s1, s2, nChar)
'MACRO StrIntlEqNA(s1, s2, nChar) = StrIsIntlEqualA(%TRUE, s1, s2, nChar)

' // To avoid macro conflicts.
FUNCTION StrIntlEqNA ( _
   BYREF lpString1 AS ASCIIZ _                          ' __in LPCSTR lpString1
 , BYREF lpString2 AS ASCIIZ _                          ' __in LPCSTR lpString2
 , BYVAL nChar AS LONG _                                ' __in int nChar
 ) AS LONG                                              ' BOOL

   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD
   LOCAL bRes AS LONG

   hLib = LoadLibrary("shlwapi.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress (hLib, "StrIsIntlEqualA")
   IF pProc THEN CALL DWORD pProc USING StrIsIntlEqualA(%TRUE, lpString1, lpString2, nChar) TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION

'#define StrIntlEqNW( s1, s2, nChar) StrIsIntlEqualW( TRUE, s1, s2, nChar)
'MACRO StrIntlEqNW(s1, s2, nChar) = StrIsIntlEqualW(%TRUE, s1, s2, nChar)

' // To avoid macro conflicts.
FUNCTION StrIntlEqNW ( _
   BYREF lpString1 AS WSTRINGZ _                        ' __in LPCWSTR lpString1
 , BYREF lpString2 AS WSTRINGZ _                        ' __in LPCWSTR lpString2
 , BYVAL nChar AS LONG _                                ' __in int nChar
 ) AS LONG                                              ' BOOL

   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD
   LOCAL bRes AS LONG

   hLib = LoadLibrary("shlwapi.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress (hLib, "StrIsIntlEqualW")
   IF pProc THEN CALL DWORD pProc USING StrIsIntlEqualW(%TRUE, lpString1, lpString2, nChar) TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION

#IF %DEF(%UNICODE)
   MACRO StrIntlEqN = StrIntlEqNW
#ELSE
   MACRO StrIntlEqN = StrIntlEqNA
#ENDIF

'#define StrIntlEqNIA(s1, s2, nChar) StrIsIntlEqualA(FALSE, s1, s2, nChar)
'MACRO StrIntlEqNIA(s1, s2, nChar) = StrIsIntlEqualA(%FALSE, s1, s2, nChar)

' // To avoid macro conflicts.
FUNCTION StrIntlEqNIA ( _
   BYREF lpString1 AS ASCIIZ _                          ' __in LPCSTR lpString1
 , BYREF lpString2 AS ASCIIZ _                          ' __in LPCSTR lpString2
 , BYVAL nChar AS LONG _                                ' __in int nChar
 ) AS LONG                                              ' BOOL

   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD
   LOCAL bRes AS LONG

   hLib = LoadLibrary("shlwapi.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress (hLib, "StrIsIntlEqualA")
   IF pProc THEN CALL DWORD pProc USING StrIsIntlEqualA(%FALSE, lpString1, lpString2, nChar) TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION

'#define StrIntlEqNIW(s1, s2, nChar) StrIsIntlEqualW(FALSE, s1, s2, nChar)
'MACRO StrIntlEqNIW(s1, s2, nChar) = StrIsIntlEqualW(%FALSE, s1, s2, nChar)

' // To avoid macro conflicts.
FUNCTION StrIntlEqNIW ( _
   BYREF lpString1 AS WSTRINGZ _                        ' __in LPCWSTR lpString1
 , BYREF lpString2 AS WSTRINGZ _                        ' __in LPCWSTR lpString2
 , BYVAL nChar AS LONG _                                ' __in int nChar
 ) AS LONG                                              ' BOOL

   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD
   LOCAL bRes AS LONG

   hLib = LoadLibrary("shlwapi.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress (hLib, "StrIsIntlEqualW")
   IF pProc THEN CALL DWORD pProc USING StrIsIntlEqualW(%FALSE, lpString1, lpString2, nChar) TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION

#IF %DEF(%UNICODE)
   MACRO StrIntlEqNI = StrIntlEqNIW
#ELSE
   MACRO StrIntlEqNI = StrIntlEqNIA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION StrRetToStrA LIB "ShlWApi.dll" ALIAS "StrRetToStrA" _
    (BYVAL pstr AS STRRET PTR, pidl AS ITEMIDLIST, ppsz AS ANY) AS LONG
#ELSE
DECLARE FUNCTION StrRetToStrA IMPORT "SHLWAPI.DLL" ALIAS "StrRetToStrA" ( _
   BYREF pstr AS STRRET _                               ' __inout LPSTRRET pstr
 , BYVAL pidl AS ITEMIDLIST PTR _                       ' __in_opt LPCITEMIDLIST pidl
 , BYREF ppszName AS DWORD _                            ' __out LPSTR *ppszName
 ) AS LONG                                              ' HRESULT
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION StrRetToStrW LIB "ShlWApi.dll" ALIAS "StrRetToStrW" _
    (BYVAL pstr AS STRRET PTR, pidl AS ITEMIDLIST, ppsz AS ANY) AS LONG
#ELSE
DECLARE FUNCTION StrRetToStrW IMPORT "SHLWAPI.DLL" ALIAS "StrRetToStrW" ( _
   BYREF pstr AS STRRET _                               ' __inout LPSTRRET pstr
 , BYVAL pidl AS ITEMIDLIST PTR _                       ' __in_opt LPCITEMIDLIST pidl
 , BYREF ppszName AS DWORD _                            ' __out LPWSTR *ppszName
 ) AS LONG                                              ' HRESULT
#ENDIF

#IF %DEF(%UNICODE)
   MACRO StrRetToStr = StrRetToStrW
#ELSE
   MACRO StrRetToStr = StrRetToStrA
#ENDIF

DECLARE FUNCTION StrRetToBufA IMPORT "SHLWAPI.DLL" ALIAS "StrRetToBufA" ( _
   BYREF pstr AS STRRET _                               ' __inout LPSTRRET pstr
 , BYVAL pidl AS ITEMIDLIST PTR _                       ' __in_opt LPCITEMIDLIST pidl
 , BYREF pszBuf AS ASCIIZ _                             ' __out LPSTR pszBuf
 , BYVAL cchBuf AS DWORD _                              ' __in UINT cchBuf
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION StrRetToBufW IMPORT "SHLWAPI.DLL" ALIAS "StrRetToBufW" ( _
   BYREF pstr AS STRRET _                               ' __inout LPSTRRET pstr
 , BYVAL pidl AS ITEMIDLIST PTR _                       ' __in_opt LPCITEMIDLIST pidl
 , BYREF pszBuf AS WSTRINGZ _                           ' __out LPWSTR pszBuf
 , BYVAL cchBuf AS DWORD _                              ' __in UINT cchBuf
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO StrRetToBuf = StrRetToBufW
#ELSE
   MACRO StrRetToBuf = StrRetToBufA
#ENDIF

'// helper to duplicate a string using the task allocator

DECLARE FUNCTION SHStrDupA IMPORT "SHLWAPI.DLL" ALIAS "SHStrDupA" ( _
   BYREF pszSource AS ASCIIZ _                          ' __in LPCSTR pszSource
 , BYREF ppwszTarget AS DWORD _                         ' __out WCHAR **ppwszTarget
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHStrDupW IMPORT "SHLWAPI.DLL" ALIAS "SHStrDupW" ( _
   BYREF pszSource AS WSTRINGZ _                        ' __in LPCWSTR pszSource
 , BYREF ppwszTarget AS DWORD _                         ' __out WCHAR **ppwszTarget
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO SHStrDup = SHStrDupW
#ELSE
   MACRO SHStrDup = SHStrDupA
#ENDIF

DECLARE FUNCTION StrCmpLogicalW IMPORT "SHLWAPI.DLL" ALIAS "StrCmpLogicalW" ( _
   BYREF lpStr1 AS WSTRINGZ _                           ' __in LPCWSTR lpStr1
 , BYREF lpStr2 AS WSTRINGZ _                           ' __in LPCWSTR lpStr2
 ) AS LONG                                              ' int

MACRO StrCmpLogical = StrCmpLogicalW

DECLARE FUNCTION StrCatChainW IMPORT "SHLWAPI.DLL" ALIAS "StrCatChainW" ( _
   BYREF pszDst AS WSTRINGZ _                           ' __inout LPWSTR pszDst
 , BYVAL cchDst AS DWORD _                              ' __in DWORD cchDst
 , BYVAL ichAt AS DWORD _                               ' __in DWORD ichAt
 , BYREF pszSrc AS WSTRINGZ _                           ' __in LPCWSTR pszSrc
 ) AS DWORD                                             ' DWORD

MACRO StrCatChain = StrCatChainW

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION StrRetToBSTR LIB "ShlWApi.dll" ALIAS "StrRetToBSTR" _
    (BYVAL pstr AS STRRET PTR, pidl AS ITEMIDLIST, pbstr AS ANY) AS LONG
#ELSE
DECLARE FUNCTION StrRetToBSTR IMPORT "SHLWAPI.DLL" ALIAS "StrRetToBSTR" ( _
   BYREF pstr AS STRRET _                               ' __inout STRRET *pstr
 , BYVAL pidl AS ITEMIDLIST PTR _                       ' __in_opt LPCITEMIDLIST pidl
 , BYREF pbstr AS WSTRING _                             ' __out BSTR *pbstr
 ) AS LONG                                              ' HRESULT
#ENDIF

DECLARE FUNCTION SHLoadIndirectString IMPORT "SHLWAPI.DLL" ALIAS "SHLoadIndirectString" ( _
   BYREF pszSource AS WSTRINGZ _                        ' __in LPCWSTR pszSource
 , BYREF pszOutBuf AS WSTRINGZ _                        ' __out LPWSTR pszOutBuf
 , BYVAL cchOutBuf AS DWORD _                           ' __in UINT cchOutBuf
 , BYREF ppvReserved AS ANY _                           ' __out void **ppvReserved
 ) AS LONG                                              ' HRESULT

'#if (_WIN32_IE >= _WIN32_IE_IE60SP2)
DECLARE FUNCTION IsCharSpaceA IMPORT "SHLWAPI.DLL" ALIAS "IsCharSpaceA" ( _
   BYVAL wch AS BYTE _                                  ' __in CHAR wch
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsCharSpaceW IMPORT "SHLWAPI.DLL" ALIAS "IsCharSpaceW" ( _
   BYVAL wch AS WORD _                                  ' __in WCHAR wch
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO IsCharSpace = IsCharSpaceW
#ELSE
   MACRO IsCharSpace = IsCharSpaceA
#ENDIF

DECLARE FUNCTION StrCmpCA IMPORT "SHLWAPI.DLL" ALIAS "StrCmpCA" ( _
   BYREF lpStr1 AS ASCIIZ _                             ' __in LPCSTR lpStr1
 , BYREF lpStr2 AS ASCIIZ _                             ' __in LPCSTR lpStr2
 ) AS LONG                                              ' int

DECLARE FUNCTION StrCmpCW IMPORT "SHLWAPI.DLL" ALIAS "StrCmpCW" ( _
   BYREF lpStr1 AS WSTRINGZ _                           ' __in LPWCSTR lpStr1
 , BYREF lpStr2 AS WSTRINGZ _                           ' __in LPCWSTR lpStr2
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO StrCmpC = StrCmpCW
#ELSE
   MACRO StrCmpC = StrCmpCA
#ENDIF

DECLARE FUNCTION StrCmpICA IMPORT "SHLWAPI.DLL" ALIAS "StrCmpICA" ( _
   BYREF lpStr1 AS ASCIIZ _                             ' __in LPCSTR lpStr1
 , BYREF lpStr2 AS ASCIIZ _                             ' __in LPCSTR lpStr2
 ) AS LONG                                              ' int

DECLARE FUNCTION StrCmpICW IMPORT "SHLWAPI.DLL" ALIAS "StrCmpICW" ( _
   BYREF lpStr1 AS WSTRINGZ _                           ' __in LPCWSTR lpStr1
 , BYREF lpStr2 AS WSTRINGZ _                           ' __in LPWCSTR lpStr2
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO StrCmpIC = StrCmpICW
#ELSE
   MACRO StrCmpIC = StrCmpICA
#ENDIF
'#endif // _WIN32_IE_IE60SP2

'#if (_WIN32_IE >= _WIN32_IE_IE50)

'// StrCmp*C* - Compare strings using C runtime collation rules.
DECLARE FUNCTION StrCmpNCA IMPORT "SHLWAPI.DLL" ALIAS "StrCmpNCA" ( _
   BYREF lpStr1 AS ASCIIZ _                             ' __in LPCSTR lpStr1
 , BYREF lpStr2 AS ASCIIZ _                             ' __in LPCSTR lpStr2
 , BYVAL nChar AS LONG _                                ' __in int nChar
 ) AS LONG                                              ' int

'// StrCmp*C* - Compare strings using C runtime collation rules.
DECLARE FUNCTION StrCmpNCW IMPORT "SHLWAPI.DLL" ALIAS "StrCmpNCW" ( _
   BYREF lpStr1 AS WSTRINGZ _                           ' __in LPCWSTR lpStr1
 , BYREF lpStr2 AS WSTRINGZ _                           ' __in LPCWSTR lpStr2
 , BYVAL nChar AS LONG _                                ' __in int nChar
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO StrCmpNC = StrCmpNCW
#ELSE
   MACRO StrCmpNC = StrCmpNCA
#ENDIF

DECLARE FUNCTION StrCmpNICA IMPORT "SHLWAPI.DLL" ALIAS "StrCmpNICA" ( _
   BYREF lpStr1 AS ASCIIZ _                             ' __in LPCSTR lpStr1
 , BYREF lpStr2 AS ASCIIZ _                             ' __in LPCSTR lpStr2
 , BYVAL nChar AS LONG _                                ' __in int nChar
 ) AS LONG                                              ' int

DECLARE FUNCTION StrCmpNICW IMPORT "SHLWAPI.DLL" ALIAS "StrCmpNICW" ( _
   BYREF lpStr1 AS WSTRINGZ _                           ' __in LPCWSTR lpStr1
 , BYREF lpStr2 AS WSTRINGZ _                           ' __in LPCWSTR lpStr2
 , BYVAL nChar AS LONG _                                ' __in int nChar
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO StrCmpNIC = StrCmpNICW
#ELSE
   MACRO StrCmpNIC = StrCmpNICA
#ENDIF

'#endif  // _WIN32_IE_IE50

'// Backward compatible to NT's non-standard naming (strictly
'// for comctl32)
'//

DECLARE FUNCTION IntlStrEqWorkerA IMPORT "SHLWAPI.DLL" ALIAS "IntlStrEqWorkerA" ( _
   BYVAL fCaseSens AS LONG _                            ' __in BOOL fCaseSens
 , BYREF pszStr1 AS ASCIIZ _                            ' __in LPCSTR pszStr1
 , BYREF pszStr2 AS ASCIIZ _                            ' __in LPCSTR pszStr2
 , BYVAL nChar AS LONG _                                ' __in int nChar
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IntlStrEqWorkerW IMPORT "SHLWAPI.DLL" ALIAS "IntlStrEqWorkerW" ( _
   BYVAL fCaseSens AS LONG _                            ' __in BOOL fCaseSens
 , BYREF pszStr1 AS WSTRINGZ _                          ' __in LPCWSTR pszStr1
 , BYREF pszStr2 AS WSTRINGZ _                          ' __in LPCWSTR pszStr2
 , BYVAL nChar AS LONG _                                ' __in int nChar
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO IntlStrEqWorker = IntlStrEqWorkerW
#ELSE
   MACRO IntlStrEqWorker = IntlStrEqWorkerA
#ENDIF

'#define IntlStrEqNA( s1, s2, nChar) IntlStrEqWorkerA( TRUE, s1, s2, nChar)
'MACRO IntlStrEqNA(s1, s2, nChar) = IntlStrEqWorkerA(%TRUE, s1, s2, nChar)

' // To avoid macro conflicts.
FUNCTION IntlStrEqNA ( _
   BYREF pszStr1 AS ASCIIZ _                            ' __in LPCSTR pszStr1
 , BYREF pszStr2 AS ASCIIZ _                            ' __in LPCSTR pszStr2
 , BYVAL nChar AS LONG _                                ' __in int nChar
 ) AS LONG                                              ' BOOL

   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD
   LOCAL bRes AS LONG

   hLib = LoadLibrary("shlwapi.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress (hLib, "IntlStrEqWorkerA")
   IF pProc THEN CALL DWORD pProc USING IntlStrEqWorkerA(%TRUE, pszStr1, pszStr2, nChar) TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION

'#define IntlStrEqNW( s1, s2, nChar) IntlStrEqWorkerW( TRUE, s1, s2, nChar)
'MACRO IntlStrEqNW(s1, s2, nChar) = IntlStrEqWorkerW(%TRUE, s1, s2, nChar)

' // To avoid macro conflicts.
FUNCTION IntlStrEqNW ( _
   BYREF pszStr1 AS WSTRINGZ _                          ' __in LPCWSTR pszStr1
 , BYREF pszStr2 AS WSTRINGZ _                          ' __in LPCWSTR pszStr2
 , BYVAL nChar AS LONG _                                ' __in int nChar
 ) AS LONG                                              ' BOOL

   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD
   LOCAL bRes AS LONG

   hLib = LoadLibrary("shlwapi.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress (hLib, "IntlStrEqWorkerW")
   IF pProc THEN CALL DWORD pProc USING IntlStrEqWorkerW(%TRUE, pszStr1, pszStr2, nChar) TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION

'#define IntlStrEqNIA(s1, s2, nChar) IntlStrEqWorkerA(FALSE, s1, s2, nChar)
'MACRO IntlStrEqNIA(s1, s2, nChar) = IntlStrEqWorkerA(%FALSE, s1, s2, nChar)

' // To avoid macro conflicts.
FUNCTION IntlStrEqNIA ( _
   BYREF pszStr1 AS ASCIIZ _                            ' __in LPCSTR pszStr1
 , BYREF pszStr2 AS ASCIIZ _                            ' __in LPCSTR pszStr2
 , BYVAL nChar AS LONG _                                ' __in int nChar
 ) AS LONG                                              ' BOOL

   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD
   LOCAL bRes AS LONG

   hLib = LoadLibrary("shlwapi.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress (hLib, "IntlStrEqWorkerA")
   IF pProc THEN CALL DWORD pProc USING IntlStrEqWorkerA(%FALSE, pszStr1, pszStr2, nChar) TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION

'#define IntlStrEqNIW(s1, s2, nChar) IntlStrEqWorkerW(FALSE, s1, s2, nChar)
'MACRO IntlStrEqNIW(s1, s2, nChar) = IntlStrEqWorkerW(%FALSE, s1, s2, nChar)

' // To avoid macro conflicts.
FUNCTION IntlStrEqNIW ( _
   BYREF pszStr1 AS WSTRINGZ _                          ' __in LPCWSTR pszStr1
 , BYREF pszStr2 AS WSTRINGZ _                          ' __in LPCWSTR pszStr2
 , BYVAL nChar AS LONG _                                ' __in int nChar
 ) AS LONG                                              ' BOOL

   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD
   LOCAL bRes AS LONG

   hLib = LoadLibrary("shlwapi.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress (hLib, "IntlStrEqWorkerW")
   IF pProc THEN CALL DWORD pProc USING IntlStrEqWorkerW(%FALSE, pszStr1, pszStr2, nChar) TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION

#IF %DEF(%UNICODE)
   MACRO IntlStrEqN  = IntlStrEqNW
   MACRO IntlStrEqNI = IntlStrEqNIW
#ELSE
   MACRO IntlStrEqN  = IntlStrEqNA
   MACRO IntlStrEqNI = IntlStrEqNIA
#ENDIF

$SZ_CONTENTTYPE_HTMLA      = "text/html"
$SZ_CONTENTTYPE_CDFA       = "application/x-cdf"

$$SZ_CONTENTTYPE_HTMLW     = "text/html"$$
$$SZ_CONTENTTYPE_CDFW      = "application/x-cdf"$$

#IF %DEF(%UNICODE)
   MACRO SZ_CONTENTTYPE_HTML = $$SZ_CONTENTTYPE_HTMLW
   MACRO SZ_CONTENTTYPE_CDF  = $$SZ_CONTENTTYPE_CDFW
#ELSE
   MACRO SZ_CONTENTTYPE_HTML = $SZ_CONTENTTYPE_HTMLA
   MACRO SZ_CONTENTTYPE_CDF  = $SZ_CONTENTTYPE_CDFA
#ENDIF

'#define PathIsHTMLFileA(pszPath)     PathIsContentTypeA(pszPath, SZ_CONTENTTYPE_HTMLA)
'MACRO PathIsHTMLFileA(pszPath) = PathIsContentTypeA(pszPath, $SZ_CONTENTTYPE_HTMLA)

' // To avoid macro conflicts.
FUNCTION PathIsHTMLFileA ( _
   BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 ) AS LONG                                              ' BOOL

   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD
   LOCAL bRes AS LONG

   hLib = LoadLibrary("shlwapi.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress (hLib, "PathIsContentTypeA")
   IF pProc THEN CALL DWORD pProc USING PathIsContentTypeA(pszPath, $SZ_CONTENTTYPE_HTMLA) TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION

'#define PathIsHTMLFileW(pszPath)     PathIsContentTypeW(pszPath, SZ_CONTENTTYPE_HTMLW)
'MACRO PathIsHTMLFileW(pszPath) = PathIsContentTypeW(pszPath, $$SZ_CONTENTTYPE_HTMLW)

' // To avoid macro conflicts.
FUNCTION PathIsHTMLFileW ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 ) AS LONG                                              ' BOOL

   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD
   LOCAL bRes AS LONG

   hLib = LoadLibrary("shlwapi.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress (hLib, "PathIsContentTypeW")
   IF pProc THEN CALL DWORD pProc USING PathIsContentTypeW(pszPath, $$SZ_CONTENTTYPE_HTMLW) TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION

#IF %DEF(%UNICODE)
   MACRO PathIsHTMLFile  = PathIsHTMLFileW
#ELSE
   MACRO PathIsHTMLFile  = PathIsHTMLFileA
#ENDIF

'// Flags for StrToIntEx
%STIF_DEFAULT     = &H00000000???
%STIF_SUPPORT_HEX = &H00000001???


'#define StrCatA                 lstrcatA
'#define StrCmpA                 lstrcmpA
'#define StrCmpIA                lstrcmpiA
'#define StrCpyA                 lstrcpyA
'#define StrCpyNA                lstrcpynA

'#define StrToLong               StrToInt
'#define StrNCmp                 StrCmpN
'#define StrNCmpI                StrCmpNI
'#define StrNCpy                 StrCpyN
'#define StrCatN                 StrNCat

MACRO StrToLong  = StrToInt
MACRO StrNCmp    = StrCmpN
MACRO StrNCmpI   = StrCmpNI
MACRO StrNCpy    = StrCpyN
MACRO StrCatN    = StrNCat

#ENDIF   ' //  NO_SHLWAPI_STRFCNS

#IF NOT %DEF(%NO_SHLWAPI_PATH)

'//
'//=============== Path Routines ===================================
'//

DECLARE FUNCTION PathAddBackslashA IMPORT "SHLWAPI.DLL" ALIAS "PathAddBackslashA" ( _
   BYREF lpszPath AS ASCIIZ _                           ' __inout LPSTR lpszPath
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION PathAddBackslashW IMPORT "SHLWAPI.DLL" ALIAS "PathAddBackslashW" ( _
   BYREF lpszPath AS WSTRINGZ _                         ' __inout LPWSTR lpszPath
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO PathAddBackslash = PathAddBackslashW
#ELSE
   MACRO PathAddBackslash = PathAddBackslashA
#ENDIF

DECLARE FUNCTION PathAddExtensionA IMPORT "SHLWAPI.DLL" ALIAS "PathAddExtensionA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __inout LPSTR pszPath
 , OPTIONAL BYREF pszExtension AS ASCIIZ _              ' __in_opt LPCSTR pszExtension
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathAddExtensionW IMPORT "SHLWAPI.DLL" ALIAS "PathAddExtensionW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __inout LPWSTR pszPath
 , OPTIONAL BYREF pszExtension AS WSTRINGZ _            ' __in_opt LPWCSTR pszExtension
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathAddExtension = PathAddExtensionW
#ELSE
   MACRO PathAddExtension = PathAddExtensionA
#ENDIF

DECLARE FUNCTION PathAppendA IMPORT "SHLWAPI.DLL" ALIAS "PathAppendA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __inout LPSTR pszPath
 , BYREF pszMore AS ASCIIZ _                            ' __in LPCSTR pszMore
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathAppendW IMPORT "SHLWAPI.DLL" ALIAS "PathAppendW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __inout LPWSTR pszPath
 , BYREF pszMore AS WSTRINGZ _                          ' __in LPCWSTR pszMore
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathAppend = PathAppendW
#ELSE
   MACRO PathAppend = PathAppendA
#ENDIF

DECLARE FUNCTION PathBuildRootA IMPORT "SHLWAPI.DLL" ALIAS "PathBuildRootA" ( _
   BYREF szRoot AS ASCIIZ _                             ' __out LPSTR szRoot
 , BYVAL iDrive AS LONG _                               ' __in int iDrive
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION PathBuildRootW IMPORT "SHLWAPI.DLL" ALIAS "PathBuildRootW" ( _
   BYREF szRoot AS WSTRINGZ _                           ' __out LPWSTR szRoot
 , BYVAL iDrive AS LONG _                               ' __in int iDrive
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO PathBuildRoot = PathBuildRootW
#ELSE
   MACRO PathBuildRoot = PathBuildRootA
#ENDIF

DECLARE FUNCTION PathCanonicalizeA IMPORT "SHLWAPI.DLL" ALIAS "PathCanonicalizeA" ( _
   BYREF lpszDst AS ASCIIZ _                            ' __out LPSTR lpszDst
 , BYREF lpszSrc AS ASCIIZ _                            ' __in LPCSTR lpszSrc
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathCanonicalizeW IMPORT "SHLWAPI.DLL" ALIAS "PathCanonicalizeW" ( _
   BYREF lpszDst AS WSTRINGZ _                          ' __out LPWSTR lpszDst
 , BYREF lpszSrc AS WSTRINGZ _                          ' __in LPCWSTR lpszSrc
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathCanonicalize = PathCanonicalizeW
#ELSE
   MACRO PathCanonicalize = PathCanonicalizeA
#ENDIF

DECLARE FUNCTION PathCombineA IMPORT "SHLWAPI.DLL" ALIAS "PathCombineA" ( _
   BYREF lpszDest AS ASCIIZ _                           ' __out LPSTR lpszDest
 , BYREF lpszDir AS ASCIIZ _                            ' __in LPCSTR lpszDir
 , BYREF lpszFile AS ASCIIZ _                           ' __in LPCSTR lpszFile
 ) AS LONG                                              ' LPSTR

DECLARE FUNCTION PathCombineW IMPORT "SHLWAPI.DLL" ALIAS "PathCombineW" ( _
   BYREF lpszDest AS WSTRINGZ _                         ' __out LPWSTR lpszDest
 , BYREF lpszDir AS WSTRINGZ _                          ' __in LPCWSTR lpszDir
 , BYREF lpszFile AS WSTRINGZ _                         ' __in LPCWSTR lpszFile
 ) AS LONG                                              ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO PathCombine = PathCombineW
#ELSE
   MACRO PathCombine = PathCombineA
#ENDIF

DECLARE FUNCTION PathCompactPathA IMPORT "SHLWAPI.DLL" ALIAS "PathCompactPathA" ( _
   BYVAL hDC AS DWORD _                                 ' __in_opt HDC hDC
 , BYREF lpszPath AS ASCIIZ _                           ' __inout LPSTR lpszPath
 , BYVAL dx AS DWORD _                                  ' __in UINT dx
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathCompactPathW IMPORT "SHLWAPI.DLL" ALIAS "PathCompactPathW" ( _
   BYVAL hDC AS DWORD _                                 ' __in_opt HDC hDC
 , BYREF lpszPath AS WSTRINGZ _                         ' __inout LPWSTR lpszPath
 , BYVAL dx AS DWORD _                                  ' __in UINT dx
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathCompactPath = PathCompactPathW
#ELSE
   MACRO PathCompactPath = PathCompactPathA
#ENDIF

DECLARE FUNCTION PathCompactPathExA IMPORT "SHLWAPI.DLL" ALIAS "PathCompactPathExA" ( _
   BYREF pszOut AS ASCIIZ _                             ' __out LPSTR pszOut
 , BYREF pszSrc AS ASCIIZ _                             ' __in LPCSTR pszSrc
 , BYVAL cchMax AS DWORD _                              ' __in UINT cchMax
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathCompactPathExW IMPORT "SHLWAPI.DLL" ALIAS "PathCompactPathExW" ( _
   BYREF pszOut AS WSTRINGZ _                           ' __out LPWSTR pszOut
 , BYREF pszSrc AS WSTRINGZ _                           ' __in LPCWSTR pszSrc
 , BYVAL cchMax AS DWORD _                              ' __in UINT cchMax
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathCompactPathEx = PathCompactPathExW
#ELSE
   MACRO PathCompactPathEx = PathCompactPathExA
#ENDIF

DECLARE FUNCTION PathCommonPrefixA IMPORT "SHLWAPI.DLL" ALIAS "PathCommonPrefixA" ( _
   BYREF pszFile1 AS ASCIIZ _                           ' __in LPCSTR pszFile1
 , BYREF pszFile2 AS ASCIIZ _                           ' __in LPCSTR pszFile2
 , BYREF pszPath AS ASCIIZ _                            ' __out LPCSTR pszPath
 ) AS LONG                                              ' int

DECLARE FUNCTION PathCommonPrefixW IMPORT "SHLWAPI.DLL" ALIAS "PathCommonPrefixW" ( _
   BYREF pszFile1 AS WSTRINGZ _                         ' __in LPCWSTR pszFile1
 , BYREF pszFile2 AS WSTRINGZ _                         ' __in LPCWSTR pszFile2
 , BYREF pszPath AS WSTRINGZ _                          ' __out LPCWSTR pszPath
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO PathCommonPrefix = PathCommonPrefixW
#ELSE
   MACRO PathCommonPrefix = PathCommonPrefixA
#ENDIF

DECLARE FUNCTION PathFileExistsA IMPORT "SHLWAPI.DLL" ALIAS "PathFileExistsA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathFileExistsW IMPORT "SHLWAPI.DLL" ALIAS "PathFileExistsW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathFileExists = PathFileExistsW
#ELSE
   MACRO PathFileExists = PathFileExistsA
#ENDIF

DECLARE FUNCTION PathFindExtensionA IMPORT "SHLWAPI.DLL" ALIAS "PathFindExtensionA" ( _
   BYREF pPath AS ASCIIZ _                              ' __in LPCSTR pPath
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION PathFindExtensionW IMPORT "SHLWAPI.DLL" ALIAS "PathFindExtensionW" ( _
   BYREF pPath AS WSTRINGZ _                            ' __in LPCWSTR pPath
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO PathFindExtension = PathFindExtensionW
#ELSE
   MACRO PathFindExtension = PathFindExtensionA
#ENDIF

DECLARE FUNCTION PathFindFileNameA IMPORT "SHLWAPI.DLL" ALIAS "PathFindFileNameA" ( _
   BYREF pPath AS ASCIIZ _                              ' __in LPCSTR pPath
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION PathFindFileNameW IMPORT "SHLWAPI.DLL" ALIAS "PathFindFileNameW" ( _
   BYREF pPath AS WSTRINGZ _                            ' __in LPCWSTR pPath
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO PathFindFileName = PathFindFileNameW
#ELSE
   MACRO PathFindFileName = PathFindFileNameA
#ENDIF

DECLARE FUNCTION PathFindNextComponentA IMPORT "SHLWAPI.DLL" ALIAS "PathFindNextComponentA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION PathFindNextComponentW IMPORT "SHLWAPI.DLL" ALIAS "PathFindNextComponentW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO PathFindNextComponent = PathFindNextComponentW
#ELSE
   MACRO PathFindNextComponent = PathFindNextComponentA
#ENDIF

DECLARE FUNCTION PathFindOnPathA IMPORT "SHLWAPI.DLL" ALIAS "PathFindOnPathA" ( _
   BYREF pszFile AS ASCIIZ _                            ' __inout LPSTR pszFile
 , BYREF ppszOtherDirs AS ASCIIZ _                      ' __in_opt LPCSTR *ppszOtherDirs
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathFindOnPathW IMPORT "SHLWAPI.DLL" ALIAS "PathFindOnPathW" ( _
   BYREF pszFile AS WSTRINGZ _                          ' __inout LPWSTR pszFile
 , BYREF ppszOtherDirs AS WSTRINGZ _                    ' __in_opt LPCWSTR *ppszOtherDirs
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathFindOnPath = PathFindOnPathW
#ELSE
   MACRO PathFindOnPath = PathFindOnPathA
#ENDIF

DECLARE FUNCTION PathFindSuffixArrayA IMPORT "SHLWAPI.DLL" ALIAS "PathFindSuffixArrayA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 , BYREF apszSuffix AS ASCIIZ _                         ' __in LPCSTR *apszSuffix [array]
 , BYVAL iArraySize AS LONG _                           ' __in int iArraySize
 ) AS DWORD                                             ' LPCSTR

DECLARE FUNCTION PathFindSuffixArrayW IMPORT "SHLWAPI.DLL" ALIAS "PathFindSuffixArrayW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 , BYREF apszSuffix AS WSTRINGZ _                       ' __in LPCWSTR *apszSuffix [array]
 , BYVAL iArraySize AS LONG _                           ' __in int iArraySize
 ) AS DWORD                                             ' LPCWSTR

#IF %DEF(%UNICODE)
   MACRO PathFindSuffixArray = PathFindSuffixArrayW
#ELSE
   MACRO PathFindSuffixArray = PathFindSuffixArrayA
#ENDIF

DECLARE FUNCTION PathGetArgsA IMPORT "SHLWAPI.DLL" ALIAS "PathGetArgsA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION PathGetArgsW IMPORT "SHLWAPI.DLL" ALIAS "PathGetArgsW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO PathGetArgs = PathGetArgsW
#ELSE
   MACRO PathGetArgs = PathGetArgsA
#ENDIF

DECLARE FUNCTION PathIsLFNFileSpecA IMPORT "SHLWAPI.DLL" ALIAS "PathIsLFNFileSpecA" ( _
   BYREF pszName AS ASCIIZ _                            ' __in LPCSTR pszName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathIsLFNFileSpecW IMPORT "SHLWAPI.DLL" ALIAS "PathIsLFNFileSpecW" ( _
   BYREF pszName AS WSTRINGZ _                          ' __in LPCWSTR pszName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathIsLFNFileSpec = PathIsLFNFileSpecW
#ELSE
   MACRO PathIsLFNFileSpec = PathIsLFNFileSpecA
#ENDIF

DECLARE FUNCTION PathGetCharTypeA IMPORT "SHLWAPI.DLL" ALIAS "PathGetCharTypeA" ( _
   BYVAL ch AS BYTE _                                   ' __in UCHAR ch
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION PathGetCharTypeW IMPORT "SHLWAPI.DLL" ALIAS "PathGetCharTypeW" ( _
   BYVAL ch AS WORD _                                   ' __in WUCHAR ch
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO PathGetCharType = PathGetCharTypeW
#ELSE
   MACRO PathGetCharType = PathGetCharTypeA
#ENDIF

'// Return flags for PathGetCharType
%GCT_INVALID   = &H0000
%GCT_LFNCHAR   = &H0001
%GCT_SHORTCHAR = &H0002
%GCT_WILD      = &H0004
%GCT_SEPARATOR = &H0008

DECLARE FUNCTION PathGetDriveNumberA IMPORT "SHLWAPI.DLL" ALIAS "PathGetDriveNumberA" ( _
   BYREF lpsz AS ASCIIZ _                               ' __in LPCSTR lpsz
 ) AS LONG                                              ' int

DECLARE FUNCTION PathGetDriveNumberW IMPORT "SHLWAPI.DLL" ALIAS "PathGetDriveNumberW" ( _
   BYREF lpsz AS WSTRINGZ _                             ' __in LPCWSTR lpsz
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO PathGetDriveNumber = PathGetDriveNumberW
#ELSE
   MACRO PathGetDriveNumber = PathGetDriveNumberA
#ENDIF

DECLARE FUNCTION PathIsDirectoryA IMPORT "SHLWAPI.DLL" ALIAS "PathIsDirectoryA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathIsDirectoryW IMPORT "SHLWAPI.DLL" ALIAS "PathIsDirectoryW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathIsDirectory = PathIsDirectoryW
#ELSE
   MACRO PathIsDirectory = PathIsDirectoryA
#ENDIF

DECLARE FUNCTION PathIsDirectoryEmptyA IMPORT "SHLWAPI.DLL" ALIAS "PathIsDirectoryEmptyA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathIsDirectoryEmptyW IMPORT "SHLWAPI.DLL" ALIAS "PathIsDirectoryEmptyW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathIsDirectoryEmpty = PathIsDirectoryEmptyW
#ELSE
   MACRO PathIsDirectoryEmpty = PathIsDirectoryEmptyA
#ENDIF

DECLARE FUNCTION PathIsFileSpecA IMPORT "SHLWAPI.DLL" ALIAS "PathIsFileSpecA" ( _
   BYREF lpszPath AS ASCIIZ _                           ' __in LPCSTR lpszPath
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathIsFileSpecW IMPORT "SHLWAPI.DLL" ALIAS "PathIsFileSpecW" ( _
   BYREF lpszPath AS WSTRINGZ _                         ' __in LPCWSTR lpszPath
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathIsFileSpec = PathIsFileSpecW
#ELSE
   MACRO PathIsFileSpec = PathIsFileSpecA
#ENDIF

DECLARE FUNCTION PathIsPrefixA IMPORT "SHLWAPI.DLL" ALIAS "PathIsPrefixA" ( _
   BYREF pszPrefix AS ASCIIZ _                          ' __in LPCSTR pszPrefix
 , BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathIsPrefixW IMPORT "SHLWAPI.DLL" ALIAS "PathIsPrefixW" ( _
   BYREF pszPrefix AS WSTRINGZ _                        ' __in LPCWSTR pszPrefix
 , BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPrefix
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathIsPrefix = PathIsPrefixW
#ELSE
   MACRO PathIsPrefix = PathIsPrefixA
#ENDIF

DECLARE FUNCTION PathIsRelativeA IMPORT "SHLWAPI.DLL" ALIAS "PathIsRelativeA" ( _
   BYREF lpszPath AS ASCIIZ _                           ' __in LPCSTR lpszPath
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathIsRelativeW IMPORT "SHLWAPI.DLL" ALIAS "PathIsRelativeW" ( _
   BYREF lpszPath AS WSTRINGZ _                         ' __in LPCWSTR lpszPath
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathIsRelative = PathIsRelativeW
#ELSE
   MACRO PathIsRelative = PathIsRelativeA
#ENDIF

DECLARE FUNCTION PathIsRootA IMPORT "SHLWAPI.DLL" ALIAS "PathIsRootA" ( _
   BYREF pPath AS ASCIIZ _                              ' __in LPCSTR pPath
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathIsRootW IMPORT "SHLWAPI.DLL" ALIAS "PathIsRootW" ( _
   BYREF pPath AS WSTRINGZ _                            ' __in LPCWSTR pPath
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathIsRoot = PathIsRootW
#ELSE
   MACRO PathIsRoot = PathIsRootA
#ENDIF

DECLARE FUNCTION PathIsSameRootA IMPORT "SHLWAPI.DLL" ALIAS "PathIsSameRootA" ( _
   BYREF pszPath1 AS ASCIIZ _                           ' __in LPCSTR pszPath1
 , BYREF pszPath2 AS ASCIIZ _                           ' __in LPCSTR pszPath2
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathIsSameRootW IMPORT "SHLWAPI.DLL" ALIAS "PathIsSameRootW" ( _
   BYREF pszPath1 AS WSTRINGZ _                         ' __in LPCSTR pszPath1
 , BYREF pszPath2 AS WSTRINGZ _                         ' __in LPCSTR pszPath2
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathIsSameRoot = PathIsSameRootW
#ELSE
   MACRO PathIsSameRoot = PathIsSameRootA
#ENDIF

DECLARE FUNCTION PathIsUNCA IMPORT "SHLWAPI.DLL" ALIAS "PathIsUNCA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathIsUNCW IMPORT "SHLWAPI.DLL" ALIAS "PathIsUNCW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathIsUNC = PathIsUNCW
#ELSE
   MACRO PathIsUNC = PathIsUNCA
#ENDIF

DECLARE FUNCTION PathIsNetworkPathA IMPORT "SHLWAPI.DLL" ALIAS "PathIsNetworkPathA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathIsNetworkPathW IMPORT "SHLWAPI.DLL" ALIAS "PathIsNetworkPathW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathIsNetworkPath = PathIsNetworkPathW
#ELSE
   MACRO PathIsNetworkPath = PathIsNetworkPathA
#ENDIF

DECLARE FUNCTION PathIsUNCServerA IMPORT "SHLWAPI.DLL" ALIAS "PathIsUNCServerA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathIsUNCServerW IMPORT "SHLWAPI.DLL" ALIAS "PathIsUNCServerW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathIsUNCServer = PathIsUNCServerW
#ELSE
   MACRO PathIsUNCServer = PathIsUNCServerA
#ENDIF

DECLARE FUNCTION PathIsUNCServerShareA IMPORT "SHLWAPI.DLL" ALIAS "PathIsUNCServerShareA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathIsUNCServerShareW IMPORT "SHLWAPI.DLL" ALIAS "PathIsUNCServerShareW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathIsUNCServerShare = PathIsUNCServerShareW
#ELSE
   MACRO PathIsUNCServerShare = PathIsUNCServerShareA
#ENDIF

DECLARE FUNCTION PathIsContentTypeA IMPORT "SHLWAPI.DLL" ALIAS "PathIsContentTypeA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 , BYREF pszContentType AS ASCIIZ _                     ' __in LPCSTR pszContentType
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathIsContentTypeW IMPORT "SHLWAPI.DLL" ALIAS "PathIsContentTypeW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 , BYREF pszContentType AS WSTRINGZ _                   ' __in LPCWSTR pszContentType
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathIsContentType = PathIsContentTypeW
#ELSE
   MACRO PathIsContentType = PathIsContentTypeA
#ENDIF

DECLARE FUNCTION PathIsURLA IMPORT "SHLWAPI.DLL" ALIAS "PathIsURLA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathIsURLW IMPORT "SHLWAPI.DLL" ALIAS "PathIsURLW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathIsURL = PathIsURLW
#ELSE
   MACRO PathIsURL = PathIsURLA
#ENDIF

DECLARE FUNCTION PathMakePrettyA IMPORT "SHLWAPI.DLL" ALIAS "PathMakePrettyA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __inout LPCSTR pszPath
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathMakePrettyW IMPORT "SHLWAPI.DLL" ALIAS "PathMakePrettyW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __inout LPCWSTR pszPath
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathMakePretty = PathMakePrettyW
#ELSE
   MACRO PathMakePretty = PathMakePrettyA
#ENDIF

DECLARE FUNCTION PathMatchSpecA IMPORT "SHLWAPI.DLL" ALIAS "PathMatchSpecA" ( _
   BYREF pszFileParam AS ASCIIZ _                       ' __in LPCSTR pszFileParam
 , BYREF pszSpec AS ASCIIZ _                            ' __in LPCSTR pszSpec
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathMatchSpecW IMPORT "SHLWAPI.DLL" ALIAS "PathMatchSpecW" ( _
   BYREF pszFileParam AS WSTRINGZ _                     ' __in LPCWSTR pszFileParam
 , BYREF pszSpec AS WSTRINGZ _                          ' __in LPCWSTR pszSpec
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathMatchSpec = PathMatchSpecW
#ELSE
   MACRO PathMatchSpec = PathMatchSpecA
#ENDIF

'#if (_WIN32_IE >= _WIN32_IE_IE70)
'// Flags for PathMatchSpecEx
%PMSF_NORMAL            = &H00000000???
%PMSF_MULTIPLE          = &H00000001???
%PMSF_DONT_STRIP_SPACES = &H00010000???   ' // modifies either of the above

DECLARE FUNCTION PathMatchSpecExA IMPORT "SHLWAPI.DLL" ALIAS "PathMatchSpecExA" ( _
   BYREF pszFile AS ASCIIZ _                            ' __in LPCSTR pszFile
 , BYREF pszSpec AS ASCIIZ _                            ' __in LPCSTR pszSpec
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathMatchSpecExW IMPORT "SHLWAPI.DLL" ALIAS "PathMatchSpecExW" ( _
   BYREF pszFile AS WSTRINGZ _                          ' __in LPCWSTR pszFile
 , BYREF pszSpec AS WSTRINGZ _                          ' __in LPCWSTR pszSpec
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathMatchSpecEx = PathMatchSpecExW
#ELSE
   MACRO PathMatchSpecEx = PathMatchSpecExA
#ENDIF
'#endif // _WIN32_IE_IE70

DECLARE FUNCTION PathParseIconLocationA IMPORT "SHLWAPI.DLL" ALIAS "PathParseIconLocationA" ( _
   BYREF pszIconFile AS ASCIIZ _                        ' __inout LPSTR pszIconFile
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathParseIconLocationW IMPORT "SHLWAPI.DLL" ALIAS "PathParseIconLocationW" ( _
   BYREF pszIconFile AS WSTRINGZ _                      ' __inout LPWSTR pszIconFile
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathParseIconLocation = PathParseIconLocationW
#ELSE
   MACRO PathParseIconLocation = PathParseIconLocationA
#ENDIF

DECLARE SUB PathQuoteSpacesA IMPORT "SHLWAPI.DLL" ALIAS "PathQuoteSpacesA" ( _
   BYREF lpsz AS ASCIIZ _                               ' __inout LPSTR lpsz
   )                                                    ' void

DECLARE SUB PathQuoteSpacesW IMPORT "SHLWAPI.DLL" ALIAS "PathQuoteSpacesW" ( _
   BYREF lpsz AS WSTRINGZ _                             ' __inout LPWSTR lpsz
   )                                                    ' void

#IF %DEF(%UNICODE)
   MACRO PathQuoteSpaces = PathQuoteSpacesW
#ELSE
   MACRO PathQuoteSpaces = PathQuoteSpacesA
#ENDIF

DECLARE FUNCTION PathRelativePathToA IMPORT "SHLWAPI.DLL" ALIAS "PathRelativePathToA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __out LPSTR pszPath
 , BYREF pszFrom AS ASCIIZ _                            ' __in LPCSTR pszFrom
 , BYVAL dwAttrFrom AS DWORD _                          ' __in DWORD dwAttrFrom
 , BYREF pszTo AS ASCIIZ _                              ' __in LPCSTR pszTo
 , BYVAL dwAttrTo AS DWORD _                            ' __in DWORD dwAttrTo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathRelativePathToW IMPORT "SHLWAPI.DLL" ALIAS "PathRelativePathToW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __out LPWSTR pszPath
 , BYREF pszFrom AS WSTRINGZ _                          ' __in LPCWSTR pszFrom
 , BYVAL dwAttrFrom AS DWORD _                          ' __in DWORD dwAttrFrom
 , BYREF pszTo AS WSTRINGZ _                            ' __in LPWCSTR pszTo
 , BYVAL dwAttrTo AS DWORD _                            ' __in DWORD dwAttrTo
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathRelativePathTo = PathRelativePathToW
#ELSE
   MACRO PathRelativePathTo = PathRelativePathToA
#ENDIF

DECLARE SUB PathRemoveArgsA IMPORT "SHLWAPI.DLL" ALIAS "PathRemoveArgsA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __inout LPSTR pszPath
   )                                                    ' void

DECLARE SUB PathRemoveArgsW IMPORT "SHLWAPI.DLL" ALIAS "PathRemoveArgsW" ( _
   BYREF pszPath AS WSTRINGZ _                             ' __inout LPWSTR pszPath
   )                                                    ' void

#IF %DEF(%UNICODE)
   MACRO PathRemoveArgs = PathRemoveArgsW
#ELSE
   MACRO PathRemoveArgs = PathRemoveArgsA
#ENDIF

DECLARE FUNCTION PathRemoveBackslashA IMPORT "SHLWAPI.DLL" ALIAS "PathRemoveBackslashA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __inout LPSTR pszPath
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION PathRemoveBackslashW IMPORT "SHLWAPI.DLL" ALIAS "PathRemoveBackslashW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __inout LPWSTR pszPath
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO PathRemoveBackslash = PathRemoveBackslashW
#ELSE
   MACRO PathRemoveBackslash = PathRemoveBackslashA
#ENDIF

DECLARE SUB PathRemoveBlanksA IMPORT "SHLWAPI.DLL" ALIAS "PathRemoveBlanksA" ( _
   BYREF lpszString AS ASCIIZ _                         ' __inout LPSTR lpszString
   )                                                    ' void

DECLARE SUB PathRemoveBlanksW IMPORT "SHLWAPI.DLL" ALIAS "PathRemoveBlanksW" ( _
   BYREF lpszString AS WSTRINGZ _                       ' __inout LPWSTR lpszString
   )                                                    ' void

#IF %DEF(%UNICODE)
   MACRO PathRemoveBlanks = PathRemoveBlanksW
#ELSE
   MACRO PathRemoveBlanks = PathRemoveBlanksA
#ENDIF

DECLARE SUB PathRemoveExtensionA IMPORT "SHLWAPI.DLL" ALIAS "PathRemoveExtensionA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __inout LPSTR pszPath
   )                                                    ' void

DECLARE SUB PathRemoveExtensionW IMPORT "SHLWAPI.DLL" ALIAS "PathRemoveExtensionW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __inout LPWSTR pszPath
   )                                                    ' void

#IF %DEF(%UNICODE)
   MACRO PathRemoveExtension = PathRemoveExtensionW
#ELSE
   MACRO PathRemoveExtension = PathRemoveExtensionA
#ENDIF

DECLARE FUNCTION PathRemoveFileSpecA IMPORT "SHLWAPI.DLL" ALIAS "PathRemoveFileSpecA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __inout LPSTR pszPath
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathRemoveFileSpecW IMPORT "SHLWAPI.DLL" ALIAS "PathRemoveFileSpecW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __inout LPWSTR pszPath
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathRemoveFileSpec = PathRemoveFileSpecW
#ELSE
   MACRO PathRemoveFileSpec = PathRemoveFileSpecA
#ENDIF

DECLARE FUNCTION PathRenameExtensionA IMPORT "SHLWAPI.DLL" ALIAS "PathRenameExtensionA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __in LPSTR pszPath
 , BYREF pszExt AS ASCIIZ _                             ' __in LPCSTR pszExt
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathRenameExtensionW IMPORT "SHLWAPI.DLL" ALIAS "PathRenameExtensionW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPWSTR pszPath
 , BYREF pszExt AS WSTRINGZ _                           ' __in LPCWSTR pszExt
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathRenameExtension = PathRenameExtensionW
#ELSE
   MACRO PathRenameExtension = PathRenameExtensionA
#ENDIF

DECLARE FUNCTION PathSearchAndQualifyA IMPORT "SHLWAPI.DLL" ALIAS "PathSearchAndQualifyA" ( _
   BYREF pcszPath AS ASCIIZ _                           ' __in LPCSTR pcszPath
 , BYREF pszFullyQualifiedPath AS ASCIIZ _              ' __out LPSTR pszFullyQualifiedPath
 , BYVAL cchFullyQualifyedPath AS DWORD _               ' __in UINT cchFullyQualifyedPath
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathSearchAndQualifyW IMPORT "SHLWAPI.DLL" ALIAS "PathSearchAndQualifyW" ( _
   BYREF pcszPath AS WSTRINGZ _                         ' __in LPCWSTR pcszPath
 , BYREF pszFullyQualifiedPath AS WSTRINGZ _            ' __out LPWSTR pszFullyQualifiedPath
 , BYVAL cchFullyQualifyedPath AS DWORD _               ' __in UINT cchFullyQualifyedPath
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathSearchAndQualify = PathSearchAndQualifyW
#ELSE
   MACRO PathSearchAndQualify = PathSearchAndQualifyA
#ENDIF

DECLARE SUB PathSetDlgItemPathA IMPORT "SHLWAPI.DLL" ALIAS "PathSetDlgItemPathA" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYVAL id AS LONG _                                   ' __in int id
 , BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
   )                                                    ' void

DECLARE SUB PathSetDlgItemPathW IMPORT "SHLWAPI.DLL" ALIAS "PathSetDlgItemPath" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYVAL id AS LONG _                                   ' __in int id
 , BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
   )                                                    ' void

#IF %DEF(%UNICODE)
   MACRO PathSetDlgItemPath = PathSetDlgItemPathW
#ELSE
   MACRO PathSetDlgItemPath = PathSetDlgItemPathA
#ENDIF

DECLARE FUNCTION PathSkipRootA IMPORT "SHLWAPI.DLL" ALIAS "PathSkipRootA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __inout LPCSTR pszPath
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION PathSkipRootW IMPORT "SHLWAPI.DLL" ALIAS "PathSkipRootW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __inout LPCWSTR pszPath
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO PathSkipRoot = PathSkipRootW
#ELSE
   MACRO PathSkipRoot = PathSkipRootA
#ENDIF

DECLARE SUB PathStripPathA IMPORT "SHLWAPI.DLL" ALIAS "PathStripPathA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __inout LPCSTR pszPath
   )                                                    ' void

DECLARE SUB PathStripPathW IMPORT "SHLWAPI.DLL" ALIAS "PathStripPathW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __inout LPCWSTR pszPath
   )                                                    ' void

#IF %DEF(%UNICODE)
   MACRO PathStripPath = PathStripPathW
#ELSE
   MACRO PathStripPath = PathStripPathA
#ENDIF

DECLARE FUNCTION PathStripToRootA IMPORT "SHLWAPI.DLL" ALIAS "PathStripToRootA" ( _
   BYREF szRoot AS ASCIIZ _                             ' __inout LPSTR szRoot
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathStripToRootW IMPORT "SHLWAPI.DLL" ALIAS "PathStripToRootW" ( _
   BYREF szRoot AS WSTRINGZ _                           ' __inout LPWSTR szRoot
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathStripToRoot = PathStripToRootW
#ELSE
   MACRO PathStripToRoot = PathStripToRootA
#ENDIF

DECLARE SUB PathUnquoteSpacesA IMPORT "SHLWAPI.DLL" ALIAS "PathUnquoteSpacesA" ( _
   BYREF lpsz AS ASCIIZ _                               ' __inout LPSTR lpsz
   )                                                    ' void

DECLARE SUB PathUnquoteSpacesW IMPORT "SHLWAPI.DLL" ALIAS "PathUnquoteSpacesW" ( _
   BYREF lpsz AS WSTRINGZ _                             ' __inout LPWSTR lpsz
   )                                                    ' void

#IF %DEF(%UNICODE)
   MACRO PathUnquoteSpaces = PathUnquoteSpacesW
#ELSE
   MACRO PathUnquoteSpaces = PathUnquoteSpacesA
#ENDIF

DECLARE FUNCTION PathMakeSystemFolderA IMPORT "SHLWAPI.DLL" ALIAS "PathMakeSystemFolderA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathMakeSystemFolderW IMPORT "SHLWAPI.DLL" ALIAS "PathMakeSystemFolderW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathMakeSystemFolder = PathMakeSystemFolderW
#ELSE
   MACRO PathMakeSystemFolder = PathMakeSystemFolderA
#ENDIF

DECLARE FUNCTION PathUnmakeSystemFolderA IMPORT "SHLWAPI.DLL" ALIAS "PathUnmakeSystemFolderA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __in LPSTR pszPath
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathUnmakeSystemFolderW IMPORT "SHLWAPI.DLL" ALIAS "PathUnmakeSystemFolderW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPWSTR pszPath
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathUnmakeSystemFolder = PathUnmakeSystemFolderW
#ELSE
   MACRO PathUnmakeSystemFolder = PathUnmakeSystemFolderA
#ENDIF

DECLARE FUNCTION PathIsSystemFolderA IMPORT "SHLWAPI.DLL" ALIAS "PathIsSystemFolderA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 , BYVAL dwAttrb AS DWORD _                             ' __in DWORD dwAttrb
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathIsSystemFolderW IMPORT "SHLWAPI.DLL" ALIAS "PathIsSystemFolderW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 , BYVAL dwAttrb AS DWORD _                             ' __in DWORD dwAttrb
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathIsSystemFolder = PathIsSystemFolderW
#ELSE
   MACRO PathIsSystemFolder = PathIsSystemFolderA
#ENDIF

DECLARE SUB PathUndecorateA IMPORT "SHLWAPI.DLL" ALIAS "PathUndecorateA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
   )                                                    ' void

DECLARE SUB PathundecorateW IMPORT "SHLWAPI.DLL" ALIAS "PathUndecorateW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
   )                                                    ' void

#IF %DEF(%UNICODE)
   MACRO PathUndecorate = PathundecorateW
#ELSE
   MACRO PathUndecorate = PathundecorateA
#ENDIF

DECLARE FUNCTION PathUnExpandEnvStringsA IMPORT "SHLWAPI.DLL" ALIAS "PathUnExpandEnvStringsA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 , BYREF pszBuf AS ASCIIZ _                             ' __out LPSTR pszBuf
 , BYVAL cchBuf AS DWORD _                              ' __in UINT cchBuf
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathUnExpandEnvStringsW IMPORT "SHLWAPI.DLL" ALIAS "PathUnExpandEnvStringsW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 , BYREF pszBuf AS WSTRINGZ _                           ' __out LPWSTR pszBuf
 , BYVAL cchBuf AS DWORD _                              ' __in UINT cchBuf
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathUnExpandEnvStrings = PathUnExpandEnvStringsW
#ELSE
   MACRO PathUnExpandEnvStrings = PathUnExpandEnvStringsA
#ENDIF

' URL_SCHEME enum
%URL_SCHEME_INVALID       = -1
%URL_SCHEME_UNKNOWN       = 0
%URL_SCHEME_FTP           = 1
%URL_SCHEME_HTTP          = 2
%URL_SCHEME_GOPHER        = 3
%URL_SCHEME_MAILTO        = 4
%URL_SCHEME_NEWS          = 5
%URL_SCHEME_NNTP          = 6
%URL_SCHEME_TELNET        = 7
%URL_SCHEME_WAIS          = 8
%URL_SCHEME_FILE          = 9
%URL_SCHEME_MK            = 10
%URL_SCHEME_HTTPS         = 11
%URL_SCHEME_SHELL         = 12
%URL_SCHEME_SNEWS         = 13
%URL_SCHEME_LOCAL         = 14
%URL_SCHEME_JAVASCRIPT    = 15
%URL_SCHEME_VBSCRIPT      = 16
%URL_SCHEME_ABOUT         = 17
%URL_SCHEME_RES           = 18
'#if (_WIN32_IE >= _WIN32_IE_IE60)
%URL_SCHEME_MSSHELLROOTED = 19
%URL_SCHEME_MSSHELLIDLIST = 20
%URL_SCHEME_MSHELP        = 21
'#endif // _WIN32_IE_IE60
'#if (_WIN32_IE >= _WIN32_IE_IE70)
%URL_SCHEME_MSSHELLDEVICE = 22
%URL_SCHEME_WILDCARD      = 23
'#endif // _WIN32_IE_IE70
%URL_SCHEME_SEARCH_MS     = 24
'#if (NTDDI_VERSION >= NTDDI_VISTASP1)
%URL_SCHEME_SEARCH        = 25
'#endif
'#if (NTDDI_VERSION >= NTDDI_WIN7)
%URL_SCHEME_KNOWNFOLDER   = 26
'#endif
%URL_SCHEME_MAXVALUE      = 27

' URL_PART enum
%URL_PART_NONE     = 0
%URL_PART_SCHEME   = 1
%URL_PART_HOSTNAME = 2
%URL_PART_USERNAME = 3
%URL_PART_PASSWORD = 4
%URL_PART_PORT     = 5
%URL_PART_QUERY    = 6

' URLIS enum
%URLIS_URL       = 0
%URLIS_OPAQUE    = 1
%URLIS_NOHISTORY = 2
%URLIS_FILEURL   = 3
%URLIS_APPLIABLE = 4
%URLIS_DIRECTORY = 5
%URLIS_HASQUERY  = 6

%URL_UNESCAPE                    = &H10000000???
%URL_ESCAPE_UNSAFE               = &H20000000???
%URL_PLUGGABLE_PROTOCOL          = &H40000000???
%URL_WININET_COMPATIBILITY       = &H80000000???
%URL_DONT_ESCAPE_EXTRA_INFO      = &H02000000???
%URL_DONT_UNESCAPE_EXTRA_INFO    = %URL_DONT_ESCAPE_EXTRA_INFO
%URL_BROWSER_MODE                = %URL_DONT_ESCAPE_EXTRA_INFO
%URL_ESCAPE_SPACES_ONLY          = &H04000000???
%URL_DONT_SIMPLIFY               = &H08000000???
%URL_NO_META                     = %URL_DONT_SIMPLIFY
%URL_UNESCAPE_INPLACE            = &H00100000???
%URL_CONVERT_IF_DOSPATH          = &H00200000???
%URL_UNESCAPE_HIGH_ANSI_ONLY     = &H00400000???
%URL_INTERNAL_PATH               = &H00800000???  ' / Will escape #'s in paths
%URL_FILE_USE_PATHURL            = &H00010000???
'#if (_WIN32_IE >= _WIN32_IE_IE60SP2)
%URL_DONT_UNESCAPE               = &H00020000???  ' / Do not unescape the path/url at all
'#endif // _WIN32_IE_IE60SP2
'#if (NTDDI_VERSION >= NTDDI_WIN7)
%URL_ESCAPE_AS_UTF8              = &H00040000???  ' // Percent-encode all non-ASCII characters as their UTF-8 equivalents.
'#endif // (NTDDI_VERSION >= NTDDI_WIN7)
%URL_ESCAPE_PERCENT              = &H00001000???
%URL_ESCAPE_SEGMENT_ONLY         = &H00002000???  ' / Treat the entire URL param as one URL segment.

%URL_PARTFLAG_KEEPSCHEME         = &H00000001???

%URL_APPLY_DEFAULT               = &H00000001???
%URL_APPLY_GUESSSCHEME           = &H00000002???
%URL_APPLY_GUESSFILE             = &H00000004???
%URL_APPLY_FORCEAPPLY            = &H00000008???


DECLARE FUNCTION UrlCompareA IMPORT "SHLWAPI.DLL" ALIAS "UrlCompareA" ( _
   BYREF pszURL1 AS ASCIIZ _                            ' __in LPCSTR pszURL1
 , BYREF pszURL2 AS ASCIIZ _                            ' __in LPCSTR pszURL2
 , BYVAL fIgnoreSlash AS DWORD _                        ' __in BOOL fIgnoreSlash
 ) AS LONG                                              ' int

DECLARE FUNCTION UrlCompareW IMPORT "SHLWAPI.DLL" ALIAS "UrlCompareW" ( _
   BYREF pszURL1 AS WSTRINGZ _                          ' __in LPCWSTR pszURL1
 , BYREF pszURL2 AS WSTRINGZ _                          ' __in LPCWSTR pszURL2
 , BYVAL fIgnoreSlash AS DWORD _                        ' __in BOOL fIgnoreSlash
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO UrlCompare = UrlCompareW
#ELSE
   MACRO UrlCompare = UrlCompareA
#ENDIF

DECLARE FUNCTION UrlCombineA IMPORT "SHLWAPI.DLL" ALIAS "UrlCombineA" ( _
   BYREF pszBase AS ASCIIZ _                            ' __in LPCSTR pszBase
 , BYREF pszRelative AS ASCIIZ _                        ' __in LPCSTR pszRelative
 , BYREF pszCombined AS ASCIIZ _                        ' __out LPSTR pszCombined
 , BYREF pcchCombined AS DWORD _                        ' __inout LPDWORD pcchCombined
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UrlCombineW IMPORT "SHLWAPI.DLL" ALIAS "UrlCombineW" ( _
   BYREF pszBase AS WSTRINGZ _                          ' __in LPCWSTR pszBase
 , BYREF pszRelative AS WSTRINGZ _                      ' __in LPCWSTR pszRelative
 , BYREF pszCombined AS WSTRINGZ _                      ' __out LPWSTR pszCombined
 , BYREF pcchCombined AS DWORD _                        ' __inout LPDWORD pcchCombined
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO UrlCombine = UrlCombineW
#ELSE
   MACRO UrlCombine = UrlCombineA
#ENDIF

DECLARE FUNCTION UrlCanonicalizeA IMPORT "SHLWAPI.DLL" ALIAS "UrlCanonicalizeA" ( _
   BYREF pszUrl AS ASCIIZ _                             ' __in LPCSTR pszUrl
 , BYREF pszCanonicalized AS ASCIIZ _                   ' __out LPSTR pszCanonicalized
 , BYREF pcchCanonicalized AS DWORD _                   ' __inout LPDWORD pcchCanonicalized
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UrlCanonicalizeW IMPORT "SHLWAPI.DLL" ALIAS "UrlCanonicalizeW" ( _
   BYREF pszUrl AS WSTRINGZ _                           ' __in LPCWSTR pszUrl
 , BYREF pszCanonicalized AS WSTRINGZ _                 ' __out LPWSTR pszCanonicalized
 , BYREF pcchCanonicalized AS DWORD _                   ' __inout LPDWORD pcchCanonicalized
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO UrlCanonicalize = UrlCanonicalizeW
#ELSE
   MACRO UrlCanonicalize = UrlCanonicalizeA
#ENDIF

DECLARE FUNCTION UrlIsOpaqueA IMPORT "SHLWAPI.DLL" ALIAS "UrlIsOpaqueA" ( _
   BYREF pszURL AS ASCIIZ _                             ' __in LPCSTR pszURL
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION UrlIsOpaqueW IMPORT "SHLWAPI.DLL" ALIAS "UrlIsOpaqueW" ( _
   BYREF pszURL AS WSTRINGZ _                           ' __in LPCWSTR pszURL
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO UrlIsOpaque = UrlIsOpaqueW
#ELSE
   MACRO UrlIsOpaque = UrlIsOpaqueA
#ENDIF

DECLARE FUNCTION UrlIsNoHistoryA IMPORT "SHLWAPI.DLL" ALIAS "UrlIsNoHistoryA" ( _
   BYREF pszURL AS ASCIIZ _                             ' __in LPCSTR pszURL
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION UrlIsNoHistoryW IMPORT "SHLWAPI.DLL" ALIAS "UrlIsNoHistoryW" ( _
   BYREF pszURL AS WSTRINGZ _                           ' __in LPCWSTR pszURL
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO UrlIsNoHistory = UrlIsNoHistoryW
#ELSE
   MACRO UrlIsNoHistory = UrlIsNoHistoryA
#ENDIF

'#define                 UrlIsFileUrlA(pszURL) UrlIsA(pszURL, URLIS_FILEURL)
'#define                 UrlIsFileUrlW(pszURL) UrlIsW(pszURL, URLIS_FILEURL)

DECLARE FUNCTION UrlIsA IMPORT "SHLWAPI.DLL" ALIAS "UrlIsA" ( _
   BYREF pszUrl AS ASCIIZ _                             ' __in LPCSTR pszUrl
 , BYVAL UrlIs AS DWORD _                               ' __in URLIS UrlIs
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION UrlIsW IMPORT "SHLWAPI.DLL" ALIAS "UrlIsW" ( _
   BYREF pszUrl AS WSTRINGZ _                           ' __in LPCWSTR pszUrl
 , BYVAL UrlIs AS DWORD _                               ' __in URLIS UrlIs
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO UrlIs = UrlIsW
#ELSE
   MACRO UrlIs = UrlIsA
#ENDIF

'MACRO UrlIsFileUrlA(pszURL) = UrlIsA(pszURL, %URLIS_FILEURL)

' // To avoid macro conflicts.
FUNCTION UrlIsFileUrlA ( _
   BYREF pszURL AS ASCIIZ _                             ' __in LPCSTR pszURL
 ) AS LONG                                              ' BOOL

   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD
   LOCAL bRes AS LONG

   hLib = LoadLibrary("shlwapi.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress (hLib, "UrlIsA")
   IF pProc THEN CALL DWORD pProc USING UrlIsA(pszURL, %URLIS_FILEURL) TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION

'MACRO UrlIsFileUrlW(pszURL) = UrlIsW(pszURL, %URLIS_FILEURL)

' // To avoid macro conflicts.
FUNCTION UrlIsFileUrlW ( _
   BYREF pszURL AS WSTRINGZ _                           ' __in LPCWSTR pszURL
 ) AS LONG                                              ' BOOL

   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD
   LOCAL bRes AS LONG

   hLib = LoadLibrary("shlwapi.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress (hLib, "UrlIsW")
   IF pProc THEN CALL DWORD pProc USING UrlIsW(pszURL, %URLIS_FILEURL) TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION

#IF %DEF(%UNICODE)
   MACRO UrlIsFileUrl = UrlIsFileUrlW
#ELSE
   MACRO UrlIsFileUrl = UrlIsFileUrlA
#ENDIF

DECLARE FUNCTION UrlGetLocationA IMPORT "SHLWAPI.DLL" ALIAS "UrlGetLocationA" ( _
   BYREF pszURL AS ASCIIZ _                             ' __in LPCSTR pszURL
 ) AS DWORD                                             ' LPCSTR

DECLARE FUNCTION UrlGetLocationW IMPORT "SHLWAPI.DLL" ALIAS "UrlGetLocationW" ( _
   BYREF pszURL AS WSTRINGZ _                           ' __in LPCWSTR pszURL
 ) AS DWORD                                             ' LPCWSTR

#IF %DEF(%UNICODE)
   MACRO UrlGetLocation = UrlGetLocationW
#ELSE
   MACRO UrlGetLocation = UrlGetLocationA
#ENDIF

DECLARE FUNCTION UrlUnescapeA IMPORT "SHLWAPI.DLL" ALIAS "UrlUnescapeA" ( _
   BYREF pszURL AS ASCIIZ _                             ' __in LPSTR pszURL
 , BYREF pszUnescaped AS ASCIIZ _                       ' __out LPSTR pszUnescaped
 , BYREF pcchUnescaped AS DWORD _                       ' __inout LPDWORD pcchUnescaped
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UrlUnescapeW IMPORT "SHLWAPI.DLL" ALIAS "UrlUnescapeW" ( _
   BYREF pszURL AS WSTRINGZ _                           ' __in LPWSTR pszURL
 , BYREF pszUnescaped AS WSTRINGZ _                     ' __out LPWSTR pszUnescaped
 , BYREF pcchUnescaped AS DWORD _                       ' __inout LPDWORD pcchUnescaped
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO UrlUnescape = UrlUnescapeW
#ELSE
   MACRO UrlUnescape = UrlUnescapeA
#ENDIF

DECLARE FUNCTION UrlEscapeA IMPORT "SHLWAPI.DLL" ALIAS "UrlEscapeA" ( _
   BYREF pszURL AS ASCIIZ _                             ' __in LPCSTR pszURL
 , BYREF pszEscaped AS ASCIIZ _                         ' __out LPSTR pszEscaped
 , BYREF pcchEscaped AS DWORD _                         ' __inout LPDWORD pcchEscaped
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UrlEscapeW IMPORT "SHLWAPI.DLL" ALIAS "UrlEscapeW" ( _
   BYREF pszURL AS WSTRINGZ _                           ' __in LPCWSTR pszURL
 , BYREF pszEscaped AS WSTRINGZ _                       ' __out LPWSTR pszEscaped
 , BYREF pcchEscaped AS DWORD _                         ' __inout LPDWORD pcchEscaped
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO UrlEscape = UrlEscapeW
#ELSE
   MACRO UrlEscape = UrlEscapeA
#ENDIF

DECLARE FUNCTION UrlCreateFromPathA IMPORT "SHLWAPI.DLL" ALIAS "UrlCreateFromPathA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 , BYREF pszUrl AS ASCIIZ _                             ' __out LPSTR pszUrl
 , BYREF pcchUrl AS DWORD _                             ' __out LPDWORD pcchUrl
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UrlCreateFromPathW IMPORT "SHLWAPI.DLL" ALIAS "UrlCreateFromPathW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 , BYREF pszUrl AS WSTRINGZ _                           ' __out LPWSTR pszUrl
 , BYREF pcchUrl AS DWORD _                             ' __out LPDWORD pcchUrl
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO UrlCreateFromPath = UrlCreateFromPathW
#ELSE
   MACRO UrlCreateFromPath = UrlCreateFromPathA
#ENDIF

DECLARE FUNCTION PathCreateFromUrlA IMPORT "SHLWAPI.DLL" ALIAS "PathCreateFromUrlA" ( _
   BYREF pszUrl AS ASCIIZ _                             ' __in LPCSTR pszUrl
 , BYREF pszPath AS ASCIIZ _                            ' __out LPSTR pszPath
 , BYREF pcchPath AS DWORD _                            ' __inout LPDWORD pcchPath
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PathCreateFromUrlW IMPORT "SHLWAPI.DLL" ALIAS "PathCreateFromUrlW" ( _
   BYREF pszUrl AS WSTRINGZ _                           ' __in LPCWSTR pszUrl
 , BYREF pszPath AS WSTRINGZ _                          ' __out LPWSTR pszPath
 , BYREF pcchPath AS DWORD _                            ' __inout LPDWORD pcchPath
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO PathCreateFromUrl = PathCreateFromUrlW
#ELSE
   MACRO PathCreateFromUrl = PathCreateFromUrlA
#ENDIF

'#if (_WIN32_IE >= _WIN32_IE_IE70)
DECLARE FUNCTION PathCreateFromUrlAlloc IMPORT "SHLWAPI.DLL" ALIAS "PathCreateFromUrlAlloc" ( _
   BYREF pszIn AS WSTRINGZ _                            ' __in LPCWSTR pszIn
 , BYREF ppszOut AS DWORD _                             ' __out LPWSTR *ppszOut
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT
'#endif // _WIN32_IE_IE70

DECLARE FUNCTION UrlHashA IMPORT "SHLWAPI.DLL" ALIAS "UrlHashA" ( _
   BYREF pszURL AS ASCIIZ _                             ' __in LPCSTR pszURL
 , BYREF pbHash AS ANY _                                ' __out LPBYTE pbHash
 , BYVAL cbHash AS DWORD _                              ' __in DWORD cbHash
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UrlHashW IMPORT "SHLWAPI.DLL" ALIAS "UrlHashW" ( _
   BYREF pszURL AS WSTRINGZ _                           ' __in LPCWSTR pszURL
 , BYREF pbHash AS ANY _                                ' __out LPBYTE pbHash
 , BYVAL cbHash AS DWORD _                              ' __in DWORD cbHash
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO UrlHash = UrlHashW
#ELSE
   MACRO UrlHash = UrlHashA
#ENDIF

DECLARE FUNCTION UrlGetPartW IMPORT "SHLWAPI.DLL" ALIAS "UrlGetPArtW" ( _
   BYREF pszIn AS WSTRINGZ _                            ' __in LPCWSTR pszIn
 , BYREF pszOut AS WSTRINGZ _                           ' __out LPWSTR pszOut
 , BYREF pcchOut AS DWORD _                             ' __inout LPDWORD pcchOut
 , BYVAL dwPart AS DWORD _                              ' __in DWORD dwPart
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UrlGetPartA IMPORT "SHLWAPI.DLL" ALIAS "UrlGetPartA" ( _
   BYREF pszIn AS ASCIIZ _                              ' __in LPCSTR pszIn
 , BYREF pszOut AS ASCIIZ _                             ' __out LPSTR pszOut
 , BYREF pcchOut AS DWORD _                             ' __inout LPDWORD pcchOut
 , BYVAL dwPart AS DWORD _                              ' __in DWORD dwPart
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO UrlGetPart = UrlGetPartW
#ELSE
   MACRO UrlGetPart = UrlGetPartA
#ENDIF

DECLARE FUNCTION UrlApplySchemeA IMPORT "SHLWAPI.DLL" ALIAS "UrlApplySchemeA" ( _
   BYREF pszIn AS ASCIIZ _                              ' __in LPCSTR pszIn
 , BYREF pszOut AS ASCIIZ _                             ' __out LPSTR pszOut
 , BYREF pcchOut AS DWORD _                             ' __inout LPDWORD pcchOut
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UrlApplySchemeW IMPORT "SHLWAPI.DLL" ALIAS "UrlApplySchemeW" ( _
   BYREF pszIn AS WSTRINGZ _                            ' __in LPCWSTR pszIn
 , BYREF pszOut AS WSTRINGZ _                           ' __out LPWSTR pszOut
 , BYREF pcchOut AS DWORD _                             ' __inout LPDWORD pcchOut
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlag
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO UrlApplyScheme = UrlApplySchemeW
#ELSE
   MACRO UrlApplyScheme = UrlApplySchemeA
#ENDIF

DECLARE FUNCTION HashData IMPORT "SHLWAPI.DLL" ALIAS "HadhData" ( _
   BYVAL pbData AS BYTE PTR _                           ' __in LPBYTE pbData
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 , BYREF pbHash AS ANY _                                ' __out LPBYTE pbHash
 , BYVAL cbHash AS DWORD _                              ' __in DWORD cbHash
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UrlFixupW IMPORT "SHLWAPI.DLL" ALIAS "UrlFixupW" ( _
   BYREF pszIn AS WSTRINGZ _                               ' __in LPCWSTR pszIn
 , BYREF pszOut AS WSTRINGZ _                              ' __out LPWSTR pszOut
 , BYVAL cchOut AS DWORD _                              ' __in DWORD cchOut
 ) AS LONG                                              ' HRESULT

MACRO UrlFixup = UrlFixupW

'#define UrlEscapeSpaces(pszUrl, pszEscaped, pcchEscaped)        UrlCanonicalize(pszUrl, pszEscaped, pcchEscaped, URL_ESCAPE_SPACES_ONLY |URL_DONT_ESCAPE_EXTRA_INFO )
'MACRO UrlEscapeSpacesA(pszUrl, pszEscaped, pcchEscaped) = UrlCanonicalizeA(pszUrl, pszEscaped, pcchEscaped, %URL_ESCAPE_SPACES_ONLY OR %URL_DONT_ESCAPE_EXTRA_INFO)

' // To avoid macro conflicts and to avoid failing if UrlCanonicalizeA does not exist
' // in the version of SHLWAPI.DLL used.
FUNCTION UrlEscapeSpacesA ( _
   BYREF pszUrl AS ASCIIZ _                             ' __in  LPCSTR pszUrl
 , BYREF pszEscaped AS ASCIIZ _                         ' __out LPSTR pszCanonicalized
 , BYREF pcchEscaped AS DWORD _                         ' __out LPDWORD pcchCanonicalized
 ) AS LONG                                              ' HRESULT

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("shlwapi.dll")
   IF hLib = %NULL THEN
      hr = GetLastError
   ELSE
      pProc = GetProcAddress(hLib, "UrlCanonicalizeA")
      IF pProc = %NULL THEN
         hr = GetLastError
      ELSE
         CALL DWORD pProc USING UrlCanonicalizeA(pszUrl, pszEscaped, pcchEscaped, %URL_ESCAPE_SPACES_ONLY OR %URL_DONT_ESCAPE_EXTRA_INFO) TO hr
      END IF
      FreeLibrary hLib
   END IF
   FUNCTION = hr

END FUNCTION

'MACRO UrlEscapeSpacesW(pszUrl, pszEscaped, pcchEscaped) = UrlCanonicalizeW(pszUrl, pszEscaped, pcchEscaped, %URL_ESCAPE_SPACES_ONLY OR %URL_DONT_ESCAPE_EXTRA_INFO)

' // To avoid macro conflicts and to avoid failing if UrlCanonicalizeA does not exist
' // in the version of SHLWAPI.DLL used.
FUNCTION UrlEscapeSpacesW ( _
   BYREF pszUrl AS WSTRINGZ _                           ' __in  LPWCSTR pszUrl
 , BYREF pszEscaped AS WSTRINGZ _                       ' __out LPWSTR pszCanonicalized
 , BYREF pcchEscaped AS DWORD _                         ' __out LPDWORD pcchCanonicalized
 ) AS LONG                                              ' HRESULT

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("shlwapi.dll")
   IF hLib = %NULL THEN
      hr = GetLastError
   ELSE
      pProc = GetProcAddress(hLib, "UrlCanonicalizeW")
      IF pProc = %NULL THEN
         hr = GetLastError
      ELSE
         CALL DWORD pProc USING UrlCanonicalizeW(pszUrl, pszEscaped, pcchEscaped, %URL_ESCAPE_SPACES_ONLY OR %URL_DONT_ESCAPE_EXTRA_INFO) TO hr
      END IF
      FreeLibrary hLib
   END IF
   FUNCTION = hr

END FUNCTION

#IF %DEF(%UNICODE)
   MACRO UrlEscapeSpaces = UrlEscapeSpacesW
#ELSE
   MACRO UrlEscapeSpaces = UrlEscapeSpacesA
#ENDIF


'#define UrlUnescapeInPlace(pszUrl, dwFlags)                     UrlUnescape(pszUrl, NULL, NULL, dwFlags | URL_UNESCAPE_INPLACE)
'MACRO UrlUnescapeInPlaceA(pszUrl, dwFlags) = UrlUnescapeA(pszUrl, BYVAL %NULL, BYVAL %NULL, dwFlags OR %URL_UNESCAPE_INPLACE)

' // To avoid macro conflicts and to avoid failing if UrlUnescapeA does not exist
' // in the version of SHLWAPI.DLL used.
FUNCTION UrlUnescapeInPlaceA ( _
   BYREF pszUrl AS ASCIIZ _                             ' __inout LPCSTR pszUrl
 , BYVAL dwFlags AS DWORD _                             ' __in    DWORD dwFlags
 ) AS LONG                                              ' HRESULT

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("shlwapi.dll")
   IF hLib = %NULL THEN
      hr = GetLastError
   ELSE
      pProc = GetProcAddress(hLib, "UrlUnescapeA")
      IF pProc = %NULL THEN
         hr = GetLastError
      ELSE
         CALL DWORD pProc USING UrlUnescapeA(pszUrl, BYVAL %NULL, BYVAL %NULL, dwFlags OR %URL_UNESCAPE_INPLACE) TO hr
      END IF
      FreeLibrary hLib
   END IF
   FUNCTION = hr

END FUNCTION

'MACRO UrlUnescapeInPlaceW(pszUrl, dwFlags) = UrlUnescapeW(pszUrl, BYVAL %NULL, BYVAL %NULL, dwFlags OR %URL_UNESCAPE_INPLACE)

' // To avoid macro conflicts and to avoid failing if UrlUnescapeA does not exist
' // in the version of SHLWAPI.DLL used.
FUNCTION UrlUnescapeInPlaceW ( _
   BYREF pszUrl AS WSTRINGZ _                           ' __inout LPCWSTR pszUrl
 , BYVAL dwFlags AS DWORD _                             ' __in    DWORD dwFlags
 ) AS LONG                                              ' HRESULT

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("shlwapi.dll")
   IF hLib = %NULL THEN
      hr = GetLastError
   ELSE
      pProc = GetProcAddress(hLib, "UrlUnescapeW")
      IF pProc = %NULL THEN
         hr = GetLastError
      ELSE
         CALL DWORD pProc USING UrlUnescapeW(pszUrl, BYVAL %NULL, BYVAL %NULL, dwFlags OR %URL_UNESCAPE_INPLACE) TO hr
      END IF
      FreeLibrary hLib
   END IF
   FUNCTION = hr

END FUNCTION

#IF %DEF(%UNICODE)
   MACRO UrlUnescapeInPlace = UrlUnescapeInPlaceW
#ELSE
   MACRO UrlUnescapeInPlace = UrlUnescapeInPlaceA
#ENDIF


'#if (_WIN32_IE >= _WIN32_IE_IE50)
'#IF (%WIN32_IE >= %WIN32_IE_IE50)

' // Size = 24 bytes
TYPE PARSEDURLA DWORD
   cbSize      AS DWORD        ' DWORD
   ' // Pointers into the buffer that was provided to ParseURL
   pszProtocol AS ASCIIZ PTR   ' LPCSTR
   cchProtocol AS DWORD        ' UINT
   pszSuffix   AS ASCIIZ PTR   ' LPCSTR
   cchSuffix   AS DWORD        ' UINT
   nScheme     AS DWORD        ' UINT // One of URL_SCHEME_*
END TYPE

' // Size = 24 bytes
TYPE PARSEDURLW DWORD
   cbSize      AS DWORD          ' DWORD
   ' // Pointers into the buffer that was provided to ParseURL
   pszProtocol AS WSTRINGZ PTR   ' LPCWSTR
   cchProtocol AS DWORD          ' UINT
   pszSuffix   AS WSTRINGZ PTR   ' LPCWSTR
   cchSuffix   AS DWORD          ' UINT
   nScheme     AS DWORD          ' UINT // One of URL_SCHEME_*
END TYPE

#IF %DEF(%UNICODE)
   MACRO PARSEDURL = PARSEDURLW
#ELSE
   MACRO PARSEDURL = PARSEDURLA
#ENDIF

DECLARE FUNCTION ParseURLA IMPORT "SHLWAPI.DLL" ALIAS "ParseURLA" ( _
   BYREF pcszURL AS ASCIIZ _                            ' __in LPCSTR pcszURL
 , BYREF ppu AS PARSEDURLA _                            ' __inout PARSEDURLA * ppu
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ParseURLW IMPORT "SHLWAPI.DLL" ALIAS "ParseURLW" ( _
   BYREF pcszURL AS WSTRINGZ _                          ' __in LPCWSTR pcszURL
 , BYREF ppu AS PARSEDURLW _                            ' __inout PARSEDURLW * ppu
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO ParseURL = ParseURLW
#ELSE
   MACRO ParseURL = ParseURLA
#ENDIF

'#ENDIF   ' // _WIN32_IE_IE50
'#endif  // _WIN32_IE_IE50

#ENDIF   ' //  NO_SHLWAPI_PATH


#IF NOT %DEF(%NO_SHLWAPI_REG)
'//
'//=============== Registry Routines ===================================
'//


'// SHDeleteEmptyKey mimics RegDeleteKey as it behaves on NT.
'// SHDeleteKey mimics RegDeleteKey as it behaves on Win95.

DECLARE FUNCTION SHDeleteEmptyKeyA IMPORT "SHLWAPI.DLL" ALIAS "SHDeleteEmptyKeyA" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pszSubKey AS ASCIIZ _                          ' __in LPCSTR pszSubKey
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION SHDeleteEmptyKeyW IMPORT "SHLWAPI.DLL" ALIAS "SHDeleteEmptyKeyW" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pszSubKey AS WSTRINGZ _                        ' __in LPCWSTR pszSubKey
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO SHDeleteEmptyKey = SHDeleteEmptyKeyW
#ELSE
   MACRO SHDeleteEmptyKey = SHDeleteEmptyKeyA
#ENDIF

DECLARE FUNCTION SHDeleteKeyA IMPORT "SHLWAPI.DLL" ALIAS "SHDeleteKeyA" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pszSubKey AS ASCIIZ _                          ' __in LPCSTR pszSubKey
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION SHDeleteKeyW IMPORT "SHLWAPI.DLL" ALIAS "SHDeleteKeyW" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pszSubKey AS WSTRINGZ _                        ' __in LPCWSTR pszSubKey
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO SHDeleteKey = SHDeleteKeyW
#ELSE
   MACRO SHDeleteKey = SHDeleteKeyA
#ENDIF

DECLARE FUNCTION SHRegDuplicateKey IMPORT "SHLWAPI.DLL" ALIAS "SHRegDuplicateKey" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 ) AS DWORD                                             ' HKEY


'// These functions open the key, get/set/delete the value, then close
'// the key.

DECLARE FUNCTION SHDeleteValueA IMPORT "SHLWAPI.DLL" ALIAS "SHDeleteValueA" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pszSubKey AS ASCIIZ _                          ' __in LPCSTR pszSubKey
 , BYREF pszValue AS ASCIIZ _                           ' __in LPCSTR pszValue
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION SHDeleteValueW IMPORT "SHLWAPI.DLL" ALIAS "SHDeleteValueW" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pszSubKey AS WSTRINGZ _                        ' __in LPCWSTR pszSubKey
 , BYREF pszValue AS WSTRINGZ _                         ' __in LPCWSTR pszValue
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO SHDeleteValue = SHDeleteValueW
#ELSE
   MACRO SHDeleteValue = SHDeleteValueA
#ENDIF

DECLARE FUNCTION SHGetValueA IMPORT "SHLWAPI.DLL" ALIAS "SHGetValueA" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pszSubKey AS ASCIIZ _                          ' __in LPCSTR pszSubKey
 , BYREF pszValue AS ASCIIZ _                           ' __in LPCSTR pszValue
 , BYREF pdwType AS DWORD _                             ' __in LPDWORD pdwType
 , BYREF pvData AS ANY _                                ' __out LPVOID pvData
 , BYREF pcbData AS DWORD _                             ' __inout LPDWORD pcbData
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION SHGetValueW IMPORT "SHLWAPI.DLL" ALIAS "SHGetValueW" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pszSubKey AS WSTRINGZ _                        ' __in LPCWSTR pszSubKey
 , BYREF pszValue AS WSTRINGZ _                         ' __in LPCWSTR pszValue
 , BYREF pdwType AS DWORD _                             ' __in LPDWORD pdwType
 , BYREF pvData AS ANY _                                ' __out LPVOID pvData
 , BYREF pcbData AS DWORD _                             ' __inout LPDWORD pcbData
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO SHGetValue = SHGetValueW
#ELSE
   MACRO SHGetValue = SHGetValueA
#ENDIF

DECLARE FUNCTION SHSetValueA IMPORT "SHLWAPI.DLL" ALIAS "SHSetValueA" ( _
   BYVAL hkey AS DWORD _                               ' __in HKEY hkey
 , BYREF pszSubKey AS ASCIIZ _                          ' __in LPCSTR pszSubKey
 , BYREF pszValue AS ASCIIZ _                           ' __in LPCSTR pszValue
 , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
 , BYREF pvData AS ANY _                                ' __in LPCVOID pvData
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION SHSetValueW IMPORT "SHLWAPI.DLL" ALIAS "SHSetValueW" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pszSubKey AS WSTRINGZ _                        ' __in LPCWSTR pszSubKey
 , BYREF pszValue AS WSTRINGZ _                         ' __in LPCWSTR pszValue
 , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
 , BYREF pvData AS ANY _                                ' __in LPCVOID pvData
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO SHSetValue = SHSetValueW
#ELSE
   MACRO SHSetValue = SHSetValueA
#ENDIF

'#if (_WIN32_IE >= 0x0602)
'//
'// SRRF - Shell Registry Routine Flags (for SHRegGetValue)
'//

'typedef int SRRF;   ' // Prevously defined as DWORD

%SRRF_RT_REG_NONE        = &H00000001&  ' // restrict type to REG_NONE      (other data types will not return ERROR_SUCCESS)
%SRRF_RT_REG_SZ          = &H00000002&  ' // restrict type to REG_SZ        (other data types will not return ERROR_SUCCESS)
%SRRF_RT_REG_EXPAND_SZ   = &H00000004&  ' // restrict type to REG_EXPAND_SZ (other data types will not return ERROR_SUCCESS)
%SRRF_RT_REG_BINARY      = &H00000008&  ' // restrict type to REG_BINARY    (other data types will not return ERROR_SUCCESS)
%SRRF_RT_REG_DWORD       = &H00000010&  ' // restrict type to REG_DWORD     (other data types will not return ERROR_SUCCESS)
%SRRF_RT_REG_MULTI_SZ    = &H00000020&  ' // restrict type to REG_MULTI_SZ  (other data types will not return ERROR_SUCCESS)
%SRRF_RT_REG_QWORD       = &H00000040&  ' // restrict type to REG_QWORD     (other data types will not return ERROR_SUCCESS)

%SRRF_RT_DWORD           = (%SRRF_RT_REG_BINARY OR %SRRF_RT_REG_DWORD) ' // restrict type to *32-bit* SRRF_RT_REG_BINARY or SRRF_RT_REG_DWORD (other data types will not return ERROR_SUCCESS)
%SRRF_RT_QWORD           = (%SRRF_RT_REG_BINARY OR %SRRF_RT_REG_QWORD) ' // restrict type to *64-bit* SRRF_RT_REG_BINARY or SRRF_RT_REG_DWORD (other data types will not return ERROR_SUCCESS)
%SRRF_RT_ANY             = &H0000ffff&                                  ' // no type restriction

%SRRF_RM_ANY             = &H00000000&  ' // no mode restriction (default is to allow any mode)
%SRRF_RM_NORMAL          = &H00010000&  ' // restrict system startup mode to "normal boot"               (other startup modes will not return ERROR_SUCCESS)
%SRRF_RM_SAFE            = &H00020000&  ' // restrict system startup mode to "safe mode"                 (other startup modes will not return ERROR_SUCCESS)
%SRRF_RM_SAFENETWORK     = &H00040000&  ' // restrict system startup mode to "safe mode with networking" (other startup modes will not return ERROR_SUCCESS)

%SRRF_NOEXPAND           = &H10000000&  ' // do not automatically expand environment strings if value is of type REG_EXPAND_SZ
%SRRF_ZEROONFAILURE      = &H20000000&  ' // if pvData is not NULL, set content to all zeros on failure
%SRRF_NOVIRT             = &H40000000&  ' // if the requested key is virtualized, then fail with ERROR_FILE_NOT_FOUND

'// Function:
'//
'//  SHRegGetValue()
'//
'// Purpose:
'//
'//  Gets a registry value.  SHRegGetValue() provides the following benefits:
'//
'//  - data type checking
'//  - boot mode checking
'//  - auto-expansion of REG_EXPAND_SZ data
'//  - guaranteed NULL termination of REG_SZ, REG_EXPAND_SZ, REG_MULTI_SZ data
'//
'// Parameters:
'//
'//  hkey        - handle to a currently open key.
'//
'//  pszSubKey   - pointer to a null-terminated string specifying the relative
'//                path from hkey to one of its subkeys from which the data is
'//                to be retrieved.  this will be opened with KEY_READ sam.
'//
'//                Note1: pszSubKey can be NULL or "".  In either of these two
'//                       cases, the data is retrieved from the hkey itself.
'//                Note2: *** PERF ***
'//                       If pszSubKey is not NULL or "", the subkey will be
'//                       automatically be opened and closed by this routine
'//                       in order to obtain the data.  If you are retrieving
'//                       multiple values from the same subkey, it is better
'//                       for perf to open the subkey via RegOpenKeyEx() prior
'//                       to calling this method, and using this opened key as
'//                       hkey with pszSubKey set to NULL.
'//
'//  pszValue    - pointer to a null-terminated string specifying the name of
'//                the value to query for data
'//
'//                Note1: pszValue can be NULL or "".  In either of these two
'//                       cases, the data is retrieved from the unnamed or
'//                       default value.
'//
'//  dwFlags     - bitwise or of SRRF_ flags, which cannot be 0:  at least one
'//                type restriction must be specified (SRRF_RT_...), or if any
'//                type is desired then SRRF_RT_ANY can be specified
'//
'//                Note1: SRRF_RT_ANY will allow any data type to be returned.
'//                Note2: The following two type restrictions have special
'//                       handling semantics:
'//
'//                         SRRF_RT_DWORD == SRRF_RT_REG_BINARY | SRRF_RT_REG_DWORD
'//                         SRRF_RT_QWORD == SRRF_RT_REG_BINARY | SRRF_RT_REG_QWORD
'//
'//                       If either of these are specified, with no other type
'//                       restrictions, then in the prior case the restriction
'//                       will limit "valid" returned data to either REG_DWORD
'//                       or 32-bit REG_BINARY data, and in the latter case
'//                       the restriction will limit "valid" returned data to
'//                       either REG_QWORD or 64-bit REG_BINARY.
'//
'//  pdwType     - pointer to a dword which receives a code indicating the
'//                type of data stored in the specified value
'//
'//                Note1: pdwType can be NULL if no type information is wanted
'//                Note2: If pdwType is not NULL, and the SRRF_NOEXPAND flag
'//                       has not been set, data types of REG_EXPAND_SZ will
'//                       be returned as REG_SZ since they are automatically
'//                       expanded in this method.
'//
'//  pvData      - pointer to a buffer that receives the value's data
'//
'//                Note1: pvData can be NULL if the data is not required.
'//                       pvData is usually NULL if doing either a simple
'//                       existence test, or if interested in the size only.
'//                Note2: *** PERF ***
'//                       Reference 'perf' note for pcbData.
'//
'//  pcbData     - when pvData is NULL:
'//                  optional pointer to a dword that receives a size in bytes
'//                  which would be sufficient to hold the registry data (note
'//                  this size is not guaranteed to be exact, merely sufficient)
'//                when pvData is not NULL:
'//                  required pointer to a dword that specifies the size in
'//                  bytes of the buffer pointed to by the pvData parameter
'//                  and receives a size in bytes of:
'//                  a) the number of bytes read into pvData on ERROR_SUCCESS
'//                     (note this size is guaranteed to be exact)
'//                  b) the number of bytes which would be sufficient to hold
'//                     the registry data on ERROR_MORE_DATA -- pvData was of
'//                     insufficient size (note this size is not guaranteed to
'//                     be exact, merely sufficient)
'//
'//                Note1: pcbData can be NULL only if pvData is NULL.
'//                Note2: *** PERF ***
'//                       The potential for an 'extra' call to the registry to
'//                       read (or re-read) in the data exists when the data
'//                       type is REG_EXPAND_SZ and the SRRF_NOEXPAND flag has
'//                       not been set.  The following conditions will result
'//                       in this 'extra' read operation:
'//                       i)  when pvData is NULL and pcbData is not NULL
'//                           we must read in the data from the registry
'//                           anyway in order to obtain the string and perform
'//                           an expand on it to obtain and return the total
'//                           required size in pcbData
'//                       ii) when pvData is not NULL but is of insufficient
'//                           size we must re-read in the data from the
'//                           registry in order to obtain the entire string
'//                           and perform an expand on it to obtain and return
'//                           the total required size in pcbData
'//
'// Remarks:
'//
'//  The key identified by hkey must have been opened with KEY_QUERY_VALUE
'//  access.  If pszSubKey is not NULL or "", it must be able to be opened
'//  with KEY_QUERY_VALUE access in the current calling context.
'//
'//  If the data type is REG_SZ, REG_EXPAND_SZ or REG_MULTI_SZ then any
'//  returned data is guaranteed to take into account proper null termination.
'//  For example:  if pcbData is not NULL, its returned size will include the
'//  bytes for a null terminator  if pvData is not NULL, its returned data
'//  will be properly null terminated.
'//
'//  If the data type is REG_EXPAND_SZ, then unless the SRRF_NOEXPAND flag
'//  is set the data will be automatically expanded prior to being returned.
'//  For example:  if pdwType is not NULL, its returned type will be changed
'//  to REG_SZ,  if pcbData is not NULL, its returned size will include the
'//  bytes for a properly expanded string.  if pvData is not NULL, its
'//  returned data will be the expanded version of the string.
'//
'//  Reference MSDN documentation for RegQueryValueEx() for more information
'//  of the behaviour when pdwType, pvData, and/or pcbData are equal to NULL.
'//
'// Return Values:
'//
'//  If the function succeeds, the return value is ERROR_SUCCESS and all out
'//  parameters requested (pdwType, pvData, pcbData) are valid.
'//
'//  If the function fails due to insufficient space in a provided non-NULL
'//  pvData, the return value is ERROR_MORE_DATA and only pdwType and pcbData
'//  can contain valid data.  The content of pvData in this case is undefined.
'//
'// Examples:
'//
'//  1) read REG_SZ (or REG_EXPAND_SZ as REG_SZ) "string" data from the (default) value of an open hkey
'//
'//      TCHAR szData[128]
'//      DWORD cbData = sizeof(pszData)
'//      if (ERROR_SUCCESS == SHRegGetValue(hkey, NULL, NULL, SRRF_RT_REG_SZ, NULL, szData, &cbData))
'//      {
'//          // use sz (successful read)
'//      }
'//
'//  2) read REG_SZ (or REG_EXPAND_SZ as REG_SZ) "string" data of unknown size from the "MyValue" value of an open hkey
'//
'//      DWORD cbData
'//      if (ERROR_SUCCESS == SHRegGetValue(hkey, NULL, TEXT("MyValue"), SRRF_RT_REG_SZ, NULL, NULL, &cbData))
'//      {
'//          TCHAR *pszData = new TCHAR[cbData/sizeof(TCHAR)]
'//          if (pszData)
'//          {
'//              if (ERROR_SUCCESS == SHRegGetValue(hkey, NULL, TEXT("MyValue"), SRRF_RT_REG_SZ, NULL, pszData, &cbData))
'//              {
'//                  // use pszData (successful read)
'//              }
'//              delete[] pszData
'//          }
'//      }
'//
'//  3) read "dword" data from the "MyValue" value of the "MySubKey" subkey of an open hkey
'//
'//      DWORD dwData
'//      DWORD cbData = sizeof(dwData)
'//      if (ERROR_SUCCESS == SHRegGetValue(hkey, TEXT("MySubKey"), TEXT("MyValue"), SRRF_RT_REG_DWORD, NULL, &dwData, &cbData))
'//      {
'//          // use dwData (successful read)
'//      }
'//
'//  4) read "dword" data from the "MyValue" value of the "MySubKey" subkey of an open hkey (32-bit binary data also ok)
'//
'//      DWORD dwData
'//      DWORD cbData = sizeof(dwData)
'//      if (ERROR_SUCCESS == SHRegGetValue(hkey, TEXT("MySubKey"), TEXT("MyValue"), SRRF_RT_DWORD, NULL, &dwData, &cbData))
'//      {
'//          // use dwData (successful read)
'//      }
'//
'//  5) determine existence of "MyValue" value of an open hkey
'//
'//      BOOL bExists = ERROR_SUCCESS == SHRegGetValue(hkey, NULL, TEXT("MyValue"), SRRF_RT_ANY, NULL, NULL, NULL)

DECLARE FUNCTION SHRegGetValueA IMPORT "SHLWAPI.DLL" ALIAS "SHRegGetValueA" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pszSubKey AS ASCIIZ _                          ' __in LPCSTR pszSubKey
 , BYREF pszValue AS ASCIIZ _                           ' __in LPCSTR pszValue
 , BYVAL srrfFlags AS LONG _                            ' __in SRRF srrfFlags
 , BYREF pdwType AS DWORD _                             ' __out LPDWORD pdwType
 , BYREF pvData AS ANY _                                ' __out LPVOID pvData
 , BYREF pcbData AS DWORD _                             ' __out LPDWORD pcbData
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION SHRegGetValueW IMPORT "SHLWAPI.DLL" ALIAS "SHRegGetValueW" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pszSubKey AS WSTRINGZ _                        ' __in LPCWSTR pszSubKey
 , BYREF pszValue AS WSTRINGZ _                         ' __in LPCWSTR pszValue
 , BYVAL srrfFlags AS LONG _                            ' __in SRRF srrfFlags
 , BYREF pdwType AS DWORD _                             ' __out LPDWORD pdwType
 , BYREF pvData AS ANY _                                ' __out LPVOID pvData
 , BYREF pcbData AS DWORD _                             ' __out LPDWORD pcbData
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO SHRegGetValue = SHRegGetValueW
#ELSE
   MACRO SHRegGetValue = SHRegGetValueA
#ENDIF

' Not currently supported. Use RegSetValue in its place.
'DECLARE FUNCTION SHRegSetValue IMPORT "SHLWAPI.DLL" ALIAS "SHRegSetValue" ( _
'   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
' , BYREF pszSubKey AS WSTRINGZ _                        ' __in_opt LPCWSTR pszSubKey
' , BYREF pszValue AS WSTRINGZ _                         ' __in_opt LPCWSTR pszValue
' , BYVAL srrfFlags AS LONG _                            ' __in SRRF srrfFlags
' , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
' , BYREF pvData AS ANY _                                ' __in LPCVOID pvData
' , BYVAL cbData AS DWORD _                              ' __in_opt DWORD cbData
' ) AS LONG                                              ' LSTATUS

' Not currently supported.
'DECLARE FUNCTION SHRegGetValueFromHKCUHKLM IMPORT "SHLWAPI.DLL" ALIAS "SHRegGetValueFromHKCUHKLM" ( _
'   BYREF pwszKey AS WSTRINGZ _                          ' __in PCWSTR pwszKey
' , BYREF pwszValue AS WSTRINGZ _                        ' __in_opt PCWSTR pwszValue
' , BYVAL srrfFlags AS LONG _                            ' __in SRRF srrfFlags
' , BYREF pdwType AS DWORD _                             ' __out_opt DWORD* pdwType
' , BYREF pvData AS ANY _                                ' __out void* pvData
' , BYREF pcbData AS DWORD _                             ' __inout_opt DWORD * pcbData
' ) AS LONG                                              ' LSTATUS

' Not currently supported.
'DECLARE FUNCTION SHRegGetBoolValueFromHKCUHKLM IMPORT "SHLWAPI.DLL" ALIAS "SHRegGetBoolValueFromHKCUHKLM" ( _
'   BYREF pwszKey AS WSTRINGZ _                          ' __in PCWSTR pwszKey
' , BYREF pwszValue AS WSTRINGZ _                        ' __in_opt PCWSTR pwszValue
' , BYVAL fDefault AS LONG _                             ' __in BOOL fDefault
' ) AS LONG                                              ' LSTATUS

'#endif // (_WIN32_IE >= 0x0602)

'// These functions behave just like RegQueryValueEx(), except if the data
'// type is REG_SZ, REG_EXPAND_SZ or REG_MULTI_SZ then the string is
'// guaranteed to be properly null terminated.
'//
'// Additionally, if the data type is REG_EXPAND_SZ these functions will
'// go ahead and expand out the string, and "massage" the returned *pdwType
'// to be REG_SZ.

DECLARE FUNCTION SHQueryValueExA IMPORT "SHLWAPI.DLL" ALIAS "SHQueryValueExA" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pszValue AS ASCIIZ _                           ' __in LPCSTR pszValue
 , BYREF pdwReserved AS DWORD _                         ' __in LPDWORD pdwReserved
 , BYREF pdwType AS DWORD _                             ' __out LPDWORD pdwType
 , BYREF pvData AS ANY _                                ' __out LPVOID pvData
 , BYREF pcbData AS DWORD _                             ' __out LPDWORD pcbData
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION SHQueryValueExW IMPORT "SHLWAPI.DLL" ALIAS "SHQueryValueExW" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pszValue AS WSTRINGZ _                         ' __in LPCWSTR pszValue
 , BYREF pdwReserved AS DWORD _                         ' __in LPDWORD pdwReserved
 , BYREF pdwType AS DWORD _                             ' __out LPDWORD pdwType
 , BYREF pvData AS ANY _                                ' __out LPVOID pvData
 , BYREF pcbData AS DWORD _                             ' __out LPDWORD pcbData
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO SHQueryValueEx = SHQueryValueExW
#ELSE
   MACRO SHQueryValueEx = SHQueryValueExA
#ENDIF

'// Enumeration functions support.

DECLARE FUNCTION SHEnumKeyExA IMPORT "SHLWAPI.DLL" ALIAS "SHEnumKeyExA" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF pszName AS ASCIIZ _                            ' __out LPSTR pszName
 , BYREF pcchName AS DWORD _                            ' __out LPDWORD pcchName
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION SHEnumKeyExW IMPORT "SHLWAPI.DLL" ALIAS "SHEnumKeyExW" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF pszName AS WSTRINGZ _                          ' __out LPWSTR pszName
 , BYREF pcchName AS DWORD _                            ' __out LPDWORD pcchName
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO SHEnumKeyEx = SHEnumKeyExW
#ELSE
   MACRO SHEnumKeyEx = SHEnumKeyExA
#ENDIF

DECLARE FUNCTION SHEnumValueA IMPORT "SHLWAPI.DLL" ALIAS "SHEnumValueA" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF pszValueName AS ASCIIZ _                       ' __out LPSTR pszValueName
 , BYREF pcchValueName AS DWORD _                       ' __inout LPDWORD pcchValueName
 , BYREF pdwType AS DWORD _                             ' __out LPDWORD pdwType
 , BYREF pvData AS ANY _                                ' __out LPVOID pvData
 , BYREF pcbData AS DWORD _                             ' __inout LPDWORD pcbData
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION SHEnumValueW IMPORT "SHLWAPI.DLL" ALIAS "SHEnumValueW" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF pszValueName AS WSTRINGZ _                     ' __out LPWSTR pszValueName
 , BYREF pcchValueName AS DWORD _                       ' __inout LPDWORD pcchValueName
 , BYREF pdwType AS DWORD _                             ' __out LPDWORD pdwType
 , BYREF pvData AS ANY _                                ' __out LPVOID pvData
 , BYREF pcbData AS DWORD _                             ' __inout LPDWORD pcbData
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO SHEnumValue = SHEnumValueW
#ELSE
   MACRO SHEnumValue = SHEnumValueA
#ENDIF

DECLARE FUNCTION SHQueryInfoKeyA IMPORT "SHLWAPI.DLL" ALIAS "SHQueryInfoKeyA" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pcSubKeys AS DWORD _                           ' __out LPDWORD pcSubKeys
 , BYREF pcchMaxSubKeyLen AS DWORD _                    ' __out LPDWORD pcchMaxSubKeyLen
 , BYREF pcValues AS DWORD _                            ' __out LPDWORD pcValues
 , BYREF pcchMaxValueNameLen AS DWORD _                 ' __out LPDWORD pcchMaxValueNameLen
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION SHQueryInfoKeyW IMPORT "SHLWAPI.DLL" ALIAS "SHQueryInfoKeyWA" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pcSubKeys AS DWORD _                           ' __out LPDWORD pcSubKeys
 , BYREF pcchMaxSubKeyLen AS DWORD _                    ' __out LPDWORD pcchMaxSubKeyLen
 , BYREF pcValues AS DWORD _                            ' __out LPDWORD pcValues
 , BYREF pcchMaxValueNameLen AS DWORD _                 ' __out LPDWORD pcchMaxValueNameLen
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO SHQueryInfoKey = SHQueryInfoKeyW
#ELSE
   MACRO SHQueryInfoKey = SHQueryInfoKeyA
#ENDIF

'// recursive key copy
DECLARE FUNCTION SHCopyKeyA IMPORT "SHLWAPI.DLL" ALIAS "SHCopyKeyA" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkeySrc
 , BYREF szSrcSubKey AS ASCIIZ _                        ' __in LPCSTR szSrcSubKey
 , BYVAL hkeyDest AS DWORD _                            ' __in HKEY hkeyDest
 , BYVAL fReserved AS DWORD _                           ' __in DWORD fReserved
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION SHCopyKeyW IMPORT "SHLWAPI.DLL" ALIAS "SHCopyKeyW" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkeySrc
 , BYREF szSrcSubKey AS WSTRINGZ _                      ' __in LPCWSTR szSrcSubKey
 , BYVAL hkeyDest AS DWORD _                            ' __in HKEY hkeyDest
 , BYVAL fReserved AS DWORD _                           ' __in DWORD fReserved
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO SHCopyKey = SHCopyKeyW
#ELSE
   MACRO SHCopyKey = SHCopyKeyA
#ENDIF

'// Getting and setting file system paths with environment variables

DECLARE FUNCTION SHRegGetPathA IMPORT "SHLWAPI.DLL" ALIAS "SHRegGetPathA" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pszSubKey AS ASCIIZ _                          ' __in LPCSTR pszSubKey
 , BYREF pszValue AS ASCIIZ _                           ' __in LPCSTR pszValue
 , BYREF pszPath AS ASCIIZ _                            ' __out LPSTR pszPath
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION SHRegGetPathW IMPORT "SHLWAPI.DLL" ALIAS "SHRegGetPathW" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pszSubKey AS WSTRINGZ _                        ' __in LPCWSTR pszSubKey
 , BYREF pszValue AS WSTRINGZ _                         ' __in LPCWSTR pszValue
 , BYREF pszPath AS WSTRINGZ _                          ' __out LPWSTR pszPath
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO SHRegGetPath = SHRegGetPathW
#ELSE
   MACRO SHRegGetPath = SHRegGetPathA
#ENDIF

DECLARE FUNCTION SHRegSetPathA IMPORT "SHLWAPI.DLL" ALIAS "SHRegSetPathA" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pszSubKey AS ASCIIZ _                          ' __in LPCSTR pszSubKey
 , BYREF pszValue AS ASCIIZ _                           ' __in LPCSTR pszValue
 , BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION SHRegSetPathW IMPORT "SHLWAPI.DLL" ALIAS "SHRegSetPathW" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pszSubKey AS WSTRINGZ _                        ' __in LPCWSTR pszSubKey
 , BYREF pszValue AS WSTRINGZ _                         ' __in LPCWSTR pszValue
 , BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO SHRegSetPath = SHRegSetPathW
#ELSE
   MACRO SHRegSetPath = SHRegSetPathA
#ENDIF

'//////////////////////////////////////////////
'// User Specific Registry Access Functions
'//////////////////////////////////////////////

' SHREGDEL_FLAGS enum
%SHREGDEL_DEFAULT        = &H00000000   ' // Delete's HKCU, or HKLM if HKCU is not found.
%SHREGDEL_HKCU           = &H00000001   ' // Delete HKCU only
%SHREGDEL_HKLM           = &H00000010   ' // Delete HKLM only.
%SHREGDEL_BOTH           = &H00000011   ' // Delete both HKCU and HKLM.

' SHREGENUM_FLAGS enum
%SHREGENUM_DEFAULT       = &H00000000   ' // Enumerates HKCU or HKLM if not found.
%SHREGENUM_HKCU          = &H00000001   ' // Enumerates HKCU only
%SHREGENUM_HKLM          = &H00000010   ' // Enumerates HKLM only.
%SHREGENUM_BOTH          = &H00000011   ' // Enumerates both HKCU and HKLM without duplicates.
                                        ' // This option is NYI.

%SHREGSET_HKCU           = &H00000001       ' // Write to HKCU if empty.
%SHREGSET_FORCE_HKCU     = &H00000002       ' // Write to HKCU.
%SHREGSET_HKLM           = &H00000004       ' // Write to HKLM if empty.
%SHREGSET_FORCE_HKLM     = &H00000008       ' // Write to HKLM.
%SHREGSET_DEFAULT        = (%SHREGSET_FORCE_HKCU OR %SHREGSET_HKLM)          ' // Default is SHREGSET_FORCE_HKCU | SHREGSET_HKLM.

'typedef HANDLE HUSKEY;  // HUSKEY is a Handle to a User Specific KEY.
'typedef HUSKEY *PHUSKEY;

DECLARE FUNCTION SHRegCreateUSKeyA IMPORT "SHLWAPI.DLL" ALIAS "SHRegCreateUSKeyA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 , BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 , BYVAL hRelativeUSKey AS DWORD _                      ' __in HUSKEY hRelativeUSKey
 , BYREF phNewUSKey AS DWORD _                          ' __out PHUSKEY phNewUSKey
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION SHRegCreateUSKeyW IMPORT "SHLWAPI.DLL" ALIAS "SHRegCreateUSKeyW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 , BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 , BYVAL hRelativeUSKey AS DWORD _                      ' __in HUSKEY hRelativeUSKey
 , BYREF phNewUSKey AS DWORD _                          ' __out PHUSKEY phNewUSKey
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO SHRegCreateUSKey = SHRegCreateUSKeyW
#ELSE
   MACRO SHRegCreateUSKey = SHRegCreateUSKeyA
#ENDIF

DECLARE FUNCTION SHRegOpenUSKeyA IMPORT "SHLWAPI.DLL" ALIAS "SHRegOpenUSKeyA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 , BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 , BYVAL hRelativeUSKey AS DWORD _                      ' __in HUSKEY hRelativeUSKey
 , BYREF phNewUSKey AS DWORD _                          ' __out PHUSKEY phNewUSKey
 , BYVAL fIgnoreHKCU AS LONG _                          ' __in BOOL fIgnoreHKCU
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION SHRegOpenUSKeyW IMPORT "SHLWAPI.DLL" ALIAS "SHRegOpenUSKeyW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 , BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 , BYVAL hRelativeUSKey AS DWORD _                      ' __in HUSKEY hRelativeUSKey
 , BYREF phNewUSKey AS DWORD _                          ' __out PHUSKEY phNewUSKey
 , BYVAL fIgnoreHKCU AS LONG _                          ' __in BOOL fIgnoreHKCU
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO SHRegOpenUSKey = SHRegOpenUSKeyW
#ELSE
   MACRO SHRegOpenUSKey = SHRegOpenUSKeyA
#ENDIF

DECLARE FUNCTION SHRegQueryUSValueA IMPORT "SHLWAPI.DLL" ALIAS "SHRegQueryUSValueA" ( _
   BYVAL hUSKey AS DWORD _                              ' __in HUSKEY hUSKey
 , BYREF pszValue AS ASCIIZ _                           ' __in LPCSTR pszValue
 , BYREF pdwType AS DWORD _                             ' __out LPDWORD pdwType
 , BYREF pvData AS ANY _                                ' __out LPVOID pvData
 , BYREF pcbData AS DWORD _                             ' __inout LPDWORD pcbData
 , BYVAL fIgnoreHKCU AS LONG _                          ' __in BOOL fIgnoreHKCU
 , BYREF pvDefaultData AS ANY _                         ' __in LPVOID pvDefaultData
 , BYVAL dwDefaultDataSize AS DWORD _                   ' __in DWORD dwDefaultDataSize
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION SHRegQueryUSValueW IMPORT "SHLWAPI.DLL" ALIAS "SHRegQueryUSValueW" ( _
   BYVAL hUSKey AS DWORD _                              ' __in HUSKEY hUSKey
 , BYREF pszValue AS WSTRINGZ _                         ' __in LPCWSTR pszValue
 , BYREF pdwType AS DWORD _                             ' __out LPDWORD pdwType
 , BYREF pvData AS ANY _                                ' __out LPVOID pvData
 , BYREF pcbData AS DWORD _                             ' __inout LPDWORD pcbData
 , BYVAL fIgnoreHKCU AS LONG _                          ' __in BOOL fIgnoreHKCU
 , BYREF pvDefaultData AS ANY _                         ' __in LPVOID pvDefaultData
 , BYVAL dwDefaultDataSize AS DWORD _                   ' __in DWORD dwDefaultDataSize
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO SHRegQueryUSValue = SHRegQueryUSValueW
#ELSE
   MACRO SHRegQueryUSValue = SHRegQueryUSValueA
#ENDIF

DECLARE FUNCTION SHRegWriteUSValueA IMPORT "SHLWAPI.DLL" ALIAS "SHRegWriteUSValueA" ( _
   BYVAL hUSKey AS DWORD _                              ' __in HUSKEY hUSKey
 , BYREF pszValue AS ASCIIZ _                           ' __in LPCSTR pszValue
 , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
 , BYREF pvData AS ANY _                                ' __in LPVOID pvData
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION SHRegWriteUSValueW IMPORT "SHLWAPI.DLL" ALIAS "SHRegWriteUSValueW" ( _
   BYVAL hUSKey AS DWORD _                              ' __in HUSKEY hUSKey
 , BYREF pszValue AS WSTRINGZ _                         ' __in LPCWSTR pszValue
 , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
 , BYREF pvData AS ANY _                                ' __in LPVOID pvData
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO SHRegWriteUSValue = SHRegWriteUSValueW
#ELSE
   MACRO SHRegWriteUSValue = SHRegWriteUSValueA
#ENDIF

DECLARE FUNCTION SHRegDeleteUSValueA IMPORT "SHLWAPI.DLL" ALIAS "SHRegDeleteUSValueA" ( _
   BYVAL hUSKey AS DWORD _                              ' __in HUSKEY hUSKey
 , BYREF pszValue AS ASCIIZ _                           ' __in LPCSTR pszValue
 , BYVAL delRegFlags AS LONG _                          ' __in SHREGDEL_FLAGS delRegFlags
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION SHRegDeleteUSValueW IMPORT "SHLWAPI.DLL" ALIAS "SHRegDeleteUSValueW" ( _
   BYVAL hUSKey AS DWORD _                              ' __in HUSKEY hUSKey
 , BYREF pszValue AS WSTRINGZ _                         ' __in LPCWSTR pszValue
 , BYVAL delRegFlags AS LONG _                          ' __in SHREGDEL_FLAGS delRegFlags
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO SHRegDeleteUSValue = SHRegDeleteUSValueW
#ELSE
   MACRO SHRegDeleteUSValue = SHRegDeleteUSValueA
#ENDIF

DECLARE FUNCTION SHRegDeleteEmptyUSKeyA IMPORT "SHLWAPI.DLL" ALIAS "SHRegDeleteEmptyUSKeyA" ( _
   BYVAL hUSKey AS DWORD _                              ' __in HUSKEY hUSKey
 , BYREF pszValue AS ASCIIZ _                           ' __in LPCSTR pszValue
 , BYVAL delRegFlags AS LONG _                          ' __in SHREGDEL_FLAGS delRegFlags
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION SHRegDeleteEmptyUSKeyW IMPORT "SHLWAPI.DLL" ALIAS "SHRegDeleteEmptyUSKeyW" ( _
   BYVAL hUSKey AS DWORD _                              ' __in HUSKEY hUSKey
 , BYREF pszValue AS WSTRINGZ _                         ' __in LPCWSTR pszValue
 , BYVAL delRegFlags AS LONG _                          ' __in SHREGDEL_FLAGS delRegFlags
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO SHRegDeleteEmptyUSKey = SHRegDeleteEmptyUSKeyW
#ELSE
   MACRO SHRegDeleteEmptyUSKey = SHRegDeleteEmptyUSKeyA
#ENDIF

DECLARE FUNCTION SHRegEnumUSKeyA IMPORT "SHLWAPI.DLL" ALIAS "SHRegEnumUSKeyA" ( _
   BYVAL hUSKey AS DWORD _                              ' __in HUSKEY hUSKey
 , BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF pszName AS ASCIIZ _                            ' __out LPSTR pszName
 , BYREF pcchName AS DWORD _                            ' __inout LPDWORD pcchName
 , BYVAL enumRegFlags AS LONG _                         ' __in SHREGENUM_FLAGS enumRegFlags
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION SHRegEnumUSKeyW IMPORT "SHLWAPI.DLL" ALIAS "SHRegEnumUSKeyW" ( _
   BYVAL hUSKey AS DWORD _                              ' __in HUSKEY hUSKey
 , BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF pszName AS WSTRINGZ _                          ' __out LPWSTR pszName
 , BYREF pcchName AS DWORD _                            ' __inout LPDWORD pcchNam
 , BYVAL enumRegFlags AS LONG _                         ' __in SHREGENUM_FLAGS enumRegFlags
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO SHRegEnumUSKey = SHRegEnumUSKeyW
#ELSE
   MACRO SHRegEnumUSKey = SHRegEnumUSKeyA
#ENDIF

DECLARE FUNCTION SHRegEnumUSValueA IMPORT "SHLWAPI.DLL" ALIAS "SHRegEnumUSValueA" ( _
   BYVAL hUSKey AS DWORD _                              ' __in HUSKEY hUSKey
 , BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF pszValueName AS ASCIIZ _                       ' __in LPSTR pszValueName
 , BYREF pcchValueNameLen AS DWORD _                    ' __out LPDWORD pcchValueNameLen
 , BYREF pdwType AS DWORD _                             ' __out LPDWORD pdwType
 , BYREF pvData AS ANY _                                ' __out LPVOID pvData
 , BYREF pcbData AS DWORD _                             ' __inout LPDWORD pcbData
 , BYVAL enumRegFlags AS LONG _                         ' __in SHREGENUM_FLAGS enumRegFlags
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION SHRegEnumUSValueW IMPORT "SHLWAPI.DLL" ALIAS "SHRegEnumUSValueW" ( _
   BYVAL hUSKey AS DWORD _                              ' __in HUSKEY hUSKey
 , BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF pszValueName AS WSTRINGZ _                     ' __in LPWSTR pszValueName
 , BYREF pcchValueNameLen AS DWORD _                    ' __out LPDWORD pcchValueNameLen
 , BYREF pdwType AS DWORD _                             ' __out LPDWORD pdwType
 , BYREF pvData AS ANY _                                ' __out LPVOID pvData
 , BYREF pcbData AS DWORD _                             ' __inout LPDWORD pcbData
 , BYVAL enumRegFlags AS LONG _                         ' __in SHREGENUM_FLAGS enumRegFlags
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO SHRegEnumUSValue = SHRegEnumUSValueW
#ELSE
   MACRO SHRegEnumUSValue = SHRegEnumUSValueA
#ENDIF

DECLARE FUNCTION SHRegQueryInfoUSKeyA IMPORT "SHLWAPI.DLL" ALIAS "SHRegQueryInfoUSKeyA" ( _
   BYVAL hUSKey AS DWORD _                              ' __in HUSKEY hUSKey
 , BYREF pcSubKeys AS DWORD _                           ' __out LPDWORD pcSubKeys
 , BYREF pcchMaxSubKeyLen AS DWORD _                    ' __out LPDWORD pcchMaxSubKeyLen
 , BYREF pcValues AS DWORD _                            ' __out LPDWORD pcValues
 , BYREF pcchMaxValueNameLen AS DWORD _                 ' __out LPDWORD pcchMaxValueNameLen
 , BYVAL enumRegFlags AS LONG _                         ' __in SHREGENUM_FLAGS enumRegFlags
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION SHRegQueryInfoUSKeyW IMPORT "SHLWAPI.DLL" ALIAS "SHRegQueryInfoUSKeyW" ( _
   BYVAL hUSKey AS DWORD _                              ' __in HUSKEY hUSKey
 , BYREF pcSubKeys AS DWORD _                           ' __out LPDWORD pcSubKeys
 , BYREF pcchMaxSubKeyLen AS DWORD _                    ' __out LPDWORD pcchMaxSubKeyLen
 , BYREF pcValues AS DWORD _                            ' __out LPDWORD pcValues
 , BYREF pcchMaxValueNameLen AS DWORD _                 ' __out LPDWORD pcchMaxValueNameLen
 , BYVAL enumRegFlags AS LONG _                         ' __in SHREGENUM_FLAGS enumRegFlags
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO SHRegQueryInfoUSKey = SHRegQueryInfoUSKeyW
#ELSE
   MACRO SHRegQueryInfoUSKey = SHRegQueryInfoUSKeyA
#ENDIF

DECLARE FUNCTION SHRegCloseUSKey IMPORT "SHLWAPI.DLL" ALIAS "SHRegCloseUSKey" ( _
   BYVAL hUSKey AS DWORD _                              ' __in HUSKEY hUSKey
 ) AS LONG                                              ' LSTATUS

'// These calls are equal to an SHRegOpenUSKey, SHRegQueryUSValue, and then a SHRegCloseUSKey.
DECLARE FUNCTION SHRegGetUSValueA IMPORT "SHLWAPI.DLL" ALIAS "SHRegGetUSValueA" ( _
   BYREF pszSubKey AS ASCIIZ _                          ' __in LPCSTR pszSubKey
 , BYREF pszValue AS ASCIIZ _                           ' __in LPCSTR pszValue
 , BYREF pdwType AS DWORD _                             ' __out LPDWORD pdwType
 , BYREF pvData AS ANY _                                ' __out LPVOID pvData
 , BYREF pcbData AS DWORD _                             ' __inout LPDWORD pcbData
 , BYVAL fIgnoreHKCU AS LONG _                          ' __in BOOL fIgnoreHKCU
 , BYREF pvDefaultData AS ANY _                         ' __out LPVOID pvDefaultData
 , BYVAL dwDefaultDataSize AS DWORD _                   ' __in DWORD dwDefaultDataSize
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION SHRegGetUSValueW IMPORT "SHLWAPI.DLL" ALIAS "SHRegGetUSValueW" ( _
   BYREF pszSubKey AS WSTRINGZ _                        ' __in LPCWSTR pszSubKey
 , BYREF pszValue AS WSTRINGZ _                         ' __in LPCWSTR pszValue
 , BYREF pdwType AS DWORD _                             ' __out LPDWORD pdwType
 , BYREF pvData AS ANY _                                ' __out LPVOID pvData
 , BYREF pcbData AS DWORD _                             ' __inout LPDWORD pcbData
 , BYVAL fIgnoreHKCU AS LONG _                          ' __in BOOL fIgnoreHKCU
 , BYREF pvDefaultData AS ANY _                         ' __out LPVOID pvDefaultData
 , BYVAL dwDefaultDataSize AS DWORD _                   ' __in DWORD dwDefaultDataSize
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO SHRegGetUSValue = SHRegGetUSValueW
#ELSE
   MACRO SHRegGetUSValue = SHRegGetUSValueA
#ENDIF

DECLARE FUNCTION SHRegSetUSValueA IMPORT "SHLWAPI.DLL" ALIAS "SHRegSetUSValueA" ( _
   BYREF pszSubKey AS ASCIIZ _                          ' __in LPCSTR pszSubKey
 , BYREF pszValue AS ASCIIZ _                           ' __in LPCSTR pszValue
 , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
 , BYREF pvData AS ANY _                                ' __in LPVOID pvData
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' LSTATUS

DECLARE FUNCTION SHRegSetUSValueW IMPORT "SHLWAPI.DLL" ALIAS "SHRegSetUSValueW" ( _
   BYREF pszSubKey AS WSTRINGZ _                        ' __in LPCWSTR pszSubKey
 , BYREF pszValue AS WSTRINGZ _                         ' __in LPCWSTR pszValue
 , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
 , BYREF pvData AS ANY _                                ' __in LPVOID pvData
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' LSTATUS

#IF %DEF(%UNICODE)
   MACRO SHRegSetUSValue = SHRegSetUSValueW
#ELSE
   MACRO SHRegSetUSValue = SHRegSetUSValueA
#ENDIF

' NOTE: Implemented as Unicode version only.
DECLARE FUNCTION SHRegGetIntW IMPORT "SHLWAPI.DLL" ALIAS "SHRegGetIntW" ( _
   BYVAL hk AS DWORD _                                  ' __in HKEY hk
 , BYREF szKey AS WSTRINGZ _                            ' __in LPCWSTR szKey
 , BYVAL nDefault AS LONG _                             ' __in int nDefault
 ) AS LONG                                              ' int

MACRO SHRegGetInt = SHRegGetIntW

DECLARE FUNCTION SHRegGetBoolUSValueA IMPORT "SHLWAPI.DLL" ALIAS "SHRegGetBoolUSValueA" ( _
   BYREF pszSubKey AS ASCIIZ _                          ' __in LPCSTR pszSubKey
 , BYREF pszValue AS ASCIIZ _                           ' __in LPCSTR pszValue
 , BYVAL fIgnoreHKCU AS LONG _                          ' __in BOOL fIgnoreHKCU
 , BYVAL fDefault AS LONG _                             ' __in BOOL fDefault
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SHRegGetBoolUSValueW IMPORT "SHLWAPI.DLL" ALIAS "SHRegGetBoolUSValueW" ( _
   BYREF pszSubKey AS WSTRINGZ _                        ' __in LPCWSTR pszSubKey
 , BYREF pszValue AS WSTRINGZ _                         ' __in LPCWSTR pszValue
 , BYVAL fIgnoreHKCU AS LONG _                          ' __in BOOL fIgnoreHKCU
 , BYVAL fDefault AS LONG _                             ' __in BOOL fDefault
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SHRegGetBoolUSValue = SHRegGetBoolUSValueW
#ELSE
   MACRO SHRegGetBoolUSValue = SHRegGetBoolUSValueA
#ENDIF

'//
'//  Association APIs
'//
'//  these APIs are to assist in accessing the data in HKCR
'//  getting the Command strings and exe paths
'//  for different verbs and extensions are simplified this way
'//

%ASSOCF_INIT_NOREMAPCLSID    = &H00000001???   ' //  do not remap clsids to progids
%ASSOCF_INIT_BYEXENAME       = &H00000002???   ' //  executable is being passed in
%ASSOCF_OPEN_BYEXENAME       = &H00000002???   ' //  executable is being passed in
%ASSOCF_INIT_DEFAULTTOSTAR   = &H00000004???   ' //  treat "*" as the BaseClass
%ASSOCF_INIT_DEFAULTTOFOLDER = &H00000008???   ' //  treat "Folder" as the BaseClass
%ASSOCF_NOUSERSETTINGS       = &H00000010???   ' //  dont use HKCU
%ASSOCF_NOTRUNCATE           = &H00000020???   ' //  dont truncate the return string
%ASSOCF_VERIFY               = &H00000040???   ' //  verify data is accurate (DISK HITS)
%ASSOCF_REMAPRUNDLL          = &H00000080???   ' //  actually gets info about rundlls target if applicable
%ASSOCF_NOFIXUPS             = &H00000100???   ' //  attempt to fix errors if found
%ASSOCF_IGNOREBASECLASS      = &H00000200???   ' //  dont recurse into the baseclass
%ASSOCF_INIT_IGNOREUNKNOWN   = &H00000400???   ' //  dont use the "Unknown" progid, instead fail

'typedef DWORD ASSOCF;

' ASSOCSTR enum
%ASSOCSTR_COMMAND         = 1    ' //  shell\verb\command string
%ASSOCSTR_EXECUTABLE      = 2    ' //  the executable part of command string
%ASSOCSTR_FRIENDLYDOCNAME = 3    ' //  friendly name of the document type
%ASSOCSTR_FRIENDLYAPPNAME = 4    ' //  friendly name of executable
%ASSOCSTR_NOOPEN          = 5    ' //  noopen value
%ASSOCSTR_SHELLNEWVALUE   = 6    ' //  query values under the shellnew key
%ASSOCSTR_DDECOMMAND      = 7    ' //  template for DDE commands
%ASSOCSTR_DDEIFEXEC       = 8    ' //  DDECOMMAND to use if just create a process
%ASSOCSTR_DDEAPPLICATION  = 9    ' //  Application name in DDE broadcast
%ASSOCSTR_DDETOPIC        = 10   ' //  Topic Name in DDE broadcast
%ASSOCSTR_INFOTIP         = 11   ' //  info tip for an item, or list of properties to create info tip from
'#if (_WIN32_IE >= _WIN32_IE_IE60)
%ASSOCSTR_QUICKTIP        = 12   ' //  same as ASSOCSTR_INFOTIP, except, this list contains only quickly retrievable properties
%ASSOCSTR_TILEINFO        = 13   ' //  similar to ASSOCSTR_INFOTIP - lists important properties for tileview
%ASSOCSTR_CONTENTTYPE     = 14   ' //  MIME Content type
%ASSOCSTR_DEFAULTICON     = 15   ' //  Default icon source
%ASSOCSTR_SHELLEXTENSION  = 16   ' //  Guid string pointing to the Shellex\Shellextensionhandler value.
'#endif // _WIN32_IE_IE60
'#if (_WIN32_IE >= _WIN32_IE_IE80)
%ASSOCSTR_DROPTARGET      = 17   ' //  The CLSID of DropTarget
%ASSOCSTR_DELEGATEEXECUTE = 18   ' //  The CLSID of DelegateExecute
'#endif // _WIN32_IE_IE80
%ASSOCSTR_MAX             = 19   ' //  last item in enum...

' ASSOCKEY enum
%ASSOCKEY_SHELLEXECCLASS = 1   ' //  the key that should be passed to ShellExec(hkeyClass)
%ASSOCKEY_APP            = 2   ' //  the "Application" key for the association
%ASSOCKEY_CLASS          = 3   ' //  the progid or class key
%ASSOCKEY_BASECLASS      = 4   ' //  the BaseClass key
%ASSOCKEY_MAX            = 4   ' //  last item in enum...

' ASSOCDATA enum
%ASSOCDATA_MSIDESCRIPTOR     = 1   ' //  Component Descriptor to pass to MSI APIs
%ASSOCDATA_NOACTIVATEHANDLER = 2   ' //  restrict attempts to activate window
%ASSOCDATA_QUERYCLASSSTORE   = 3   ' //  should check with the NT Class Store
%ASSOCDATA_HASPERUSERASSOC   = 4   ' //  defaults to user specified association
'#if (_WIN32_IE >= _WIN32_IE_IE60)
%ASSOCDATA_EDITFLAGS         = 5   ' //  Edit flags.
%ASSOCDATA_VALUE             = 6   ' //  use pszExtra as the Value name
'#endif // _WIN32_IE_IE60
%ASSOCDATA_MAX               = 6

' ASSOCENUM enum
%ASSOCENUM_NONE = 0

' ########################################################################################
' IQueryAssociations interface
' IID = C46CA590-3C3F-11D2-BEE6-0000F805CA57
' Inherited interface = IUnknown
' Minimum operating systems: Windows 2000, Windows NT 4.0 with Internet Explorer 5,
' Windows 98, Windows 95 with Internet Explorer 5
' ########################################################################################

$IID_IQueryAssociations = GUID$("{C46CA590-3C3F-11D2-BEE6-0000F805CA57}")

INTERFACE IQueryAssociations $IID_IQueryAssociations

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Init ( _                                      ' VTable offset = 12
     BYVAL flags AS DWORD _                             ' __in ASSOCF flags
   , BYREF pszAssoc AS WSTRINGZ _                       ' __in LPCWSTR pszAssoc
   , BYVAL hkProgid AS DWORD _                          ' __in HKEY hkProgid
   , BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
 ) AS LONG                                              ' HRESULT
   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 16
     BYVAL flags AS DWORD _                             ' __in ASSOCF flags
   , BYVAL str AS DWORD _                               ' __in ASSOCSTR str
   , BYREF pszExtra AS WSTRINGZ _                       ' __in LPCWSTR pszExtra
   , BYREF pszOut AS WSTRINGZ _                         ' __out LPWSTR pszOut
   , BYREF pcchOut AS DWORD _                           ' __inout DWORD *pcchOut
 ) AS LONG                                              ' HRESULT
   ' =====================================================================================
   METHOD GetKey ( _                                    ' VTable offset = 20
     BYVAL flags AS DWORD _                             ' __in ASSOCF flags
   , BYVAL key AS DWORD _                               ' __in ASSOCKEY key
   , BYREF pszExtra AS WSTRINGZ _                       ' __in LPCWSTR pszExtra
   , BYREF phkeyOut AS DWORD _                          ' __out HKEY *phkeyOut
 ) AS LONG                                              ' HRESULT
   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 24
     BYVAL flags AS DWORD _                             ' __in ASSOCF flags
   , BYVAL data AS DWORD _                              ' __in ASSOCDATA data
   , BYREF pszExtra AS WSTRINGZ _                       ' __in LPCWSTR pszExtra
   , BYREF pvOut AS DWORD _                             ' __out LPVOID pvOut
   , BYREF pcbOut AS DWORD _                            ' __out DWORD *pcbOut
 ) AS LONG                                              ' HRESULT
   ' =====================================================================================
   METHOD GetEnum ( _                                   ' VTable offset = 28
     BYVAL flags AS DWORD _                             ' __in ASSOCF flags
   , BYVAL assocenum AS DWORD _                         ' __in ASSOCENUM assocenum
   , BYREF pszExtra AS WSTRINGZ _                       ' __in LPCWSTR pszExtra
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvOut AS IUnknown _                         ' __out LPVOID *ppvOut
 ) AS LONG                                              ' HRESULT
   ' =====================================================================================

END INTERFACE

DECLARE FUNCTION AssocCreate IMPORT "SHLWAPI.DLL" ALIAS "AssocCreate" ( _
   BYREF clsid AS GUID _                                ' __in CLSID clsid
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF pqa AS ANY _                                   ' __out LPVOID *pqa
 ) AS LONG                                              ' HRESULT

'//  wrappers for the interface

DECLARE FUNCTION AssocQueryStringA IMPORT "SHLWAPI.DLL" ALIAS "AssocQueryStringA" ( _
   BYVAL flags AS LONG _                                ' __in ASSOCF flags
 , BYVAL str AS LONG _                                  ' __in ASSOCSTR str
 , BYREF pszAssoc AS ASCIIZ _                           ' __in LPCSTR pszAssoc
 , BYREF pszExtra AS ASCIIZ _                           ' __in LPCSTR pszExtra
 , BYREF pszOut AS ASCIIZ _                             ' __out LPSTR pszOut
 , BYREF pcchOut AS DWORD _                             ' __inout DWORD *pcchOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION AssocQueryStringW IMPORT "SHLWAPI.DLL" ALIAS "AssocQueryStringW" ( _
   BYVAL flags AS LONG _                                ' __in ASSOCF flags
 , BYVAL str AS LONG _                                  ' __in ASSOCSTR str
 , BYREF pszAssoc AS WSTRINGZ _                         ' __in LPCWSTR pszAssoc
 , BYREF pszExtra AS WSTRINGZ _                         ' __in LPCWSTR pszExtra
 , BYREF pszOut AS WSTRINGZ _                           ' __out LPWSTR pszOut
 , BYREF pcchOut AS DWORD _                             ' __inout DWORD *pcchOut
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO AssocQueryString = AssocQueryStringW
#ELSE
   MACRO AssocQueryString = AssocQueryStringA
#ENDIF

DECLARE FUNCTION AssocQueryStringByKeyA IMPORT "SHLWAPI.DLL" ALIAS "AssocQueryStringByKeyA" ( _
   BYVAL flags AS LONG _                                ' __in ASSOCF flags
 , BYVAL str AS LONG _                                  ' __in ASSOCSTR str
 , BYVAL hkAssoc AS DWORD _                             ' __in HKEY hkAssoc
 , BYREF pszExtra AS ASCIIZ _                           ' __in LPCSTR pszExtra
 , BYREF pszOut AS ASCIIZ _                             ' __out LPSTR pszOut
 , BYREF pcchOut AS DWORD _                             ' __inout DWORD *pcchOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION AssocQueryStringByKeyW IMPORT "SHLWAPI.DLL" ALIAS "AssocQueryStringByKeyW" ( _
   BYVAL flags AS LONG _                                ' __in ASSOCF flags
 , BYVAL str AS LONG _                                  ' __in ASSOCSTR str
 , BYVAL hkAssoc AS DWORD _                             ' __in HKEY hkAssoc
 , BYREF pszExtra AS WSTRINGZ _                         ' __in LPCWSTR pszExtra
 , BYREF pszOut AS WSTRINGZ _                           ' __out LPWSTR pszOut
 , BYREF pcchOut AS DWORD _                             ' __inout DWORD *pcchOut
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO AssocQueryStringByKey = AssocQueryStringByKeyW
#ELSE
   MACRO AssocQueryStringByKey = AssocQueryStringByKeyA
#ENDIF

DECLARE FUNCTION AssocQueryKeyA IMPORT "SHLWAPI.DLL" ALIAS "AssocQueryKeyA" ( _
   BYVAL flags AS LONG _                                ' __in ASSOCF flags
 , BYVAL key AS LONG _                                  ' __in ASSOCKEY key
 , BYREF pszAssoc AS ASCIIZ _                           ' __in LPCSTR pszAssoc
 , BYREF pszExtra AS ASCIIZ _                           ' __in LPCSTR pszExtra
 , BYREF phkeyOut AS DWORD _                            ' __out HKEY *phkeyOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION AssocQueryKeyW IMPORT "SHLWAPI.DLL" ALIAS "AssocQueryKeyW" ( _
   BYVAL flags AS LONG _                                ' __in ASSOCF flags
 , BYVAL key AS LONG _                                  ' __in ASSOCKEY key
 , BYREF pszAssoc AS WSTRINGZ _                         ' __in LPCWSTR pszAssoc
 , BYREF pszExtra AS WSTRINGZ _                         ' __in LPCWSTR pszExtra
 , BYREF phkeyOut AS DWORD _                            ' __out HKEY *phkeyOut
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO AssocQueryKey = AssocQueryKeyW
#ELSE
   MACRO AssocQueryKey = AssocQueryKeyA
#ENDIF

'#if (_WIN32_IE >= 0x0601)
'#IF (%WIN32_IE >= &H0601)
'//  AssocIsDangerous() checks a file type to determine whether it is "Dangerous"
'//      this maps to the IE download dialog's forcing a prompt to open or save.
'//      dangerous file types should be handled more carefully than other file types.
'//
'//  Parameter:  pszAssoc - type to check.  may be an extension or progid.  (".exe" or "exefile" would both be valid)
'//
'//  Returns: TRUE if the file type is dangerous.
'//
'//  NOTES:
'//
'//      this API first checks a hardcoded list of known dangerous types.
'//      then it checks the editflags for the file type looking for the FTA_AlwaysUnsafe bit.
'//      then it checks Safer policies.
'//
'LWSTDAPI_(BOOL) AssocIsDangerous(LPCWSTR pszAssoc);
DECLARE FUNCTION AssocIsDangerous IMPORT "SHLWAPI.DLL" ALIAS "AssocIsDangerous" ( _
   BYREF pszAssoc AS WSTRINGZ _                         ' __in LPCWSTR pszAssoc
 ) AS LONG                                              ' BOOL
'#ENDIF  ' // %WIN32_IE >= &H0601
'#endif // (_WIN32_IE >= 0x0601)

'#if (_WIN32_IE >= _WIN32_IE_IE60SP2)
'#IF (%WIN32_IE >= %WIN32_IE_IE60SP2)
DECLARE FUNCTION AssocGetPerceivedType IMPORT "SHLWAPI.DLL" ALIAS "AssocGetPerceivedType" ( _
   BYREF pszExt AS WSTRINGZ _                              ' __in LPCWSTR pszExt
 , BYREF ptype AS DWORD _                               ' __out PERCEIVED *ptype
 , BYREF pflag AS DWORD _                               ' __out PERCEIVEDFLAG *pflag
 , BYREF ppszType AS DWORD _                            ' __out LPWSTR *ppszType
 ) AS LONG                                              ' HRESULT
'#ENDIF
'#endif


#ENDIF   ' //  NO_SHLWAPI_REG



#IF NOT %DEF(%NO_SHLWAPI_STREAM)
'//
'//=============== Stream Routines ===================================
'//

DECLARE FUNCTION SHOpenRegStreamA IMPORT "SHLWAPI.DLL" ALIAS "SHOpenRegStreamA" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pszSubKey AS ASCIIZ _                          ' __in_opt LPCSTR pszSubKey
 , BYREF pszValue AS ASCIIZ _                           ' __in_opt LPCSTR pszValue
 , BYVAL grfMode AS DWORD _                             ' __in DWORD grfMode
 ) AS IStream                                           ' IStream *

DECLARE FUNCTION SHOpenRegStreamW IMPORT "SHLWAPI.DLL" ALIAS "SHOpenRegStreamW" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pszSubKey AS WSTRINGZ _                        ' __in_opt LPCWSTR pszSubKey
 , BYREF pszValue AS WSTRINGZ _                         ' __inopt LPCWSTR pszValue
 , BYVAL grfMode AS DWORD _                             ' __in DWORD grfMode
 ) AS IStream                                           ' IStream *

#IF %DEF(%UNICODE)
   MACRO SHOpenRegStream = SHOpenRegStreamW
#ELSE
   MACRO SHOpenRegStream = SHOpenRegStreamA
#ENDIF

DECLARE FUNCTION SHOpenRegStream2A IMPORT "SHLWAPI.DLL" ALIAS "SHOpenRegStream2A" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pszSubKey AS ASCIIZ _                          ' __in_opt LPCSTR pszSubKey
 , BYREF pszValue AS ASCIIZ _                           ' __in_opt LPCSTR pszValue
 , BYVAL grfMode AS DWORD _                             ' __in DWORD grfMode
 ) AS IStream                                           ' IStream *

DECLARE FUNCTION SHOpenRegStream2W IMPORT "SHLWAPI.DLL" ALIAS "SHOpenRegStream2W" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pszSubKey AS WSTRINGZ _                        ' __in_opt LPCWSTR pszSubKey
 , BYREF pszValue AS WSTRINGZ _                         ' __in_opt LPCWSTR pszValue
 , BYVAL grfMode AS DWORD _                             ' __in DWORD grfMode
 ) AS IStream                                           ' IStream *

#IF %DEF(%UNICODE)
   MACRO SHOpenRegStream2 = SHOpenRegStream2W
#ELSE
   MACRO SHOpenRegStream2 = SHOpenRegStream2A
#ENDIF

DECLARE FUNCTION SHCreateStreamOnFileA IMPORT "SHLWAPI.DLL" ALIAS "SHCreateStreamOnFileA" ( _
   BYREF pszFile AS ASCIIZ _                            ' __in LPCSTR pszFile
 , BYVAL grfMode AS DWORD _                             ' __in DWORD grfMode
 , BYREF ppstm AS IStream _                             ' __out IStream **ppstm
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHCreateStreamOnFileW IMPORT "SHLWAPI.DLL" ALIAS "SHCreateStreamOnFileW" ( _
   BYREF pszFile AS WSTRINGZ _                          ' __in LPCWSTR pszFile
 , BYVAL grfMode AS DWORD _                             ' __in DWORD grfMode
 , BYREF ppstm AS IStream _                             ' __out IStream **ppstm
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO SHCreateStreamOnFile = SHCreateStreamOnFileW
#ELSE
   MACRO SHCreateStreamOnFile = SHCreateStreamOnFileA
#ENDIF

'#if (_WIN32_IE >= 0x0600)
'#IF (%WIN32_IE >= &H0600)

DECLARE FUNCTION SHCreateStreamOnFileEx IMPORT "SHLWAPI.DLL" ALIAS "SHCreateStreamOnFileEx" ( _
   BYREF pszFile AS WSTRINGZ _                          ' __in LPCWSTR pszFile
 , BYVAL grfMode AS DWORD _                             ' __in DWORD grfMode
 , BYVAL dwAttributes AS DWORD _                        ' __in DWORD dwAttributes
 , BYVAL fCreate AS LONG _                              ' __in BOOL fCreate
 , BYVAL pstmTemplate AS IStream _                      ' __in IStream *pstmTemplate
 , BYREF ppstm AS IStream _                             ' __out IStream **ppstm
 ) AS LONG                                              ' HRESULT

'#ENDIF ' // (%WIN32_IE >= &H0600)
'#endif // (_WIN32_IE >= 0x0600)

'#if (_WIN32_IE >= _WIN32_IE_IE501)
'#IF (%WIN32_IE >= %WIN32_IE_IE501)
DECLARE FUNCTION SHCreateMemStream IMPORT "SHLWAPI.DLL" ALIAS "SHCreateMemStream" ( _
   BYVAL pInit AS BYTE PTR _                            ' __in const BYTE *pInit
 , BYVAL cbInit AS DWORD _                              ' __in UINT cbInit
 ) AS IStream                                           ' IStream *
'#ENDIF ' // (%WIN32_IE >= %WIN32_IE_IE501)
'#endif // (_WIN32_IE >= _WIN32_IE_IE501)

#ENDIF    ' // NO_SHLWAPI_STREAM


'#IF NOT %DEF(%NO_SHLWAPI_MLUI)
'//
'//=============== Multi Language UI Routines ===================================
'//

' *** Removed in Windows 7 SDK ***

'#if (_WIN32_IE >= _WIN32_IE_IE501)

'DECLARE FUNCTION MLLoadLibrary IMPORT "SHLWAPI.DLL" ALIAS "MLLoadLibraryA" ( _
'   BYREF lpLibFileName AS ASCIIZ _                      ' __in LPCSTR lpLibFileName
' , BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
' , BYVAL dwCrossCodePage AS DWORD _                     ' __in DWORD dwCrossCodePage
' ) AS DWORD                                             ' HINSTANCE

'DECLARE FUNCTION MLLoadLibraryW IMPORT "SHLWAPI.DLL" ALIAS "MLLoadLibraryW" ( _
'   BYREF lpLibFileName AS WSTRINGZ _                    ' __in LPWCSTR lpLibFileName
' , BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
' , BYVAL dwCrossCodePage AS DWORD _                     ' __in DWORD dwCrossCodePage
' ) AS DWORD                                             ' HINSTANCE

'DECLARE FUNCTION MLFreeLibrary IMPORT "SHLWAPI.DLL" ALIAS "MLFreeLibrary" ( _
'   BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
' ) AS LONG                                              ' BOOL

'%ML_NO_CROSSCODEPAGE    = 0
'%ML_CROSSCODEPAGE_NT    = 1
'%ML_CROSSCODEPAGE       = 2
'%ML_SHELL_LANGUAGE      = 4
'%ML_CROSSCODEPAGE_MASK  = 7

'#endif // (_WIN32_IE >= _WIN32_IE_IE501)


'#ENDIF ' // NO_SHLWAPI_MLUI


#IF NOT %DEF(%NO_SHLWAPI_HTTP)
'//
'//=============== HTTP helper Routines ===================================
'//


'#if (_WIN32_IE >= 0x0603)
DECLARE FUNCTION GetAcceptLanguagesA IMPORT "SHLWAPI.DLL" ALIAS "GetAcceptLanguagesA" ( _
   BYREF psz AS ASCIIZ _                                ' __out LPSTR psz
 , BYREF pcch AS DWORD _                                ' __inout DWORD *pcch
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION GetAcceptLanguagesW IMPORT "SHLWAPI.DLL" ALIAS "GetAcceptLanguagesW" ( _
   BYREF psz AS WSTRINGZ _                              ' __out LPWSTR psz
 , BYREF pcch AS DWORD _                                ' __inout DWORD *pcch
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO GetAcceptLanguages = GetAcceptLanguagesW
#ELSE
   MACRO GetAcceptLanguages = GetAcceptLanguagesA
#ENDIF
'#endif  // (_WIN32_IE >= 0x0603)

#ENDIF   ' // NO_SHLWAPI_HTTP


'#if (_WIN32_IE < _WIN32_IE_IE70) && !defined(NO_SHLWAPI_STOPWATCH)

%SPMODE_SHELL      = &H00000001???
%SPMODE_DEBUGOUT   = &H00000002???
%SPMODE_TEST       = &H00000004???
%SPMODE_BROWSER    = &H00000008???
%SPMODE_FLUSH      = &H00000010???
%SPMODE_EVENT      = &H00000020???
%SPMODE_MSVM       = &H00000040???
%SPMODE_FORMATTEXT = &H00000080???
%SPMODE_PROFILE    = &H00000100???
%SPMODE_DEBUGBREAK = &H00000200???
%SPMODE_MSGTRACE   = &H00000400???
%SPMODE_PERFTAGS   = &H00000800???
%SPMODE_MEMWATCH   = &H00001000???
%SPMODE_DBMON      = &H00002000???
%SPMODE_MULTISTOP  = &H00004000???
#IF NOT %DEF(%NO_ETW_TRACING)
%SPMODE_EVENTTRACE = &H00008000???   '  // Event Tracing for Windows Enabled
#ENDIF

DECLARE FUNCTION StopWatchMode IMPORT "SHLWAPI.DLL" ALIAS "StopWatchMode" ( _
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION StopWatchFlush IMPORT "SHLWAPI.DLL" ALIAS "StopWatchFlush" ( _
 ) AS DWORD                                             ' DWORD

'#endif // (_WIN32_IE < _WIN32_IE_IE70) && !defined(NO_SHLWAPI_STOPWATCH)

'#if (_WIN32_IE >= _WIN32_IE_IE501)

DECLARE SUB IUnknown_Set IMPORT "SHLWAPI.DLL" ALIAS "IUnknown_Set" ( _
   BYREF ppunk AS IUnknown _                            ' __inout IUnknown ** ppunk
 , BYVAL punk AS IUnknown _                             ' __in_opt IUnknown * punk
 )                                                      ' void

DECLARE SUB IUnknown_AtomicRelease IMPORT "SHLWAPI.DLL" ALIAS "IUnknown_AtomicRelease" ( _
   BYREF ppunk AS IUnknown _                            ' __inout_opt void ** ppunk
 )                                                      ' void

DECLARE FUNCTION IUnknown_GetWindow IMPORT "SHLWAPI.DLL" ALIAS "IUnknown_GetWindow" ( _
   BYVAL punk AS IUnknown _                             ' __in_opt IUnknown* punk
 , BYREF phwnd AS DWORD _                               ' __out HWND* phwnd
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION IUnknown_SetSite IMPORT "SHLWAPI.DLL" ALIAS "IUnknown_SetSite" ( _
   BYVAL punk AS IUnknown _                             ' __in IUnknown* punk
 , BYVAL punkSite AS IUnknown _                         ' __in_opt IUnknown *punkSite
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION IUnknown_GetSite IMPORT "SHLWAPI.DLL" ALIAS "IUnknown_GetSite" ( _
   BYVAL punk AS IUnknown _                             ' __in IUnknown* punk
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

' For those versions of Windows that do not include IUnknown_QueryService in Shlwapi.h,
' this function must be called directly from Shlwapi.dll using ordinal 176.
DECLARE FUNCTION IUnknown_QueryService IMPORT "SHLWAPI.DLL" ALIAS "IUnknown_QueryService" ( _
   BYVAL punk AS IUnknown _                             ' __in IUnknown* punk
 , BYREF guidService AS GUID _                          ' __in REFGUID guidService
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppvOut AS IUnknown _                           ' __out void ** ppvOut
 ) AS LONG                                              ' HRESULT

'#endif // (_WIN32_IE >= _WIN32_IE_IE501)

'#if (_WIN32_IE >= _WIN32_IE_IE501)

DECLARE FUNCTION IStream_Read IMPORT "SHLWAPI.DLL" ALIAS "IStream_Read" ( _
   BYVAL pstm AS IStream _                              ' __in IStream *pstm
 , BYREF pv AS ANY _                                    ' __out void *pv
 , BYVAL cb AS DWORD _                                  ' __in ULONG cb
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION IStream_Write IMPORT "SHLWAPI.DLL" ALIAS "IStream_Write" ( _
   BYVAL pstm AS IStream _                              ' __in IStream *pstm
 , BYREF pv AS ANY _                                    ' __in void *pv
 , BYVAL cb AS DWORD _                                  ' __in ULONG cb
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION IStream_Reset IMPORT "SHLWAPI.DLL" ALIAS "IStream_Reset" ( _
   BYVAL pstm AS IStream _                              ' __in IStream *pstm
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION IStream_Size IMPORT "SHLWAPI.DLL" ALIAS "IStream_Size" ( _
   BYVAL pstm AS IStream _                              ' __in IStream *pstm
 , BYREF pui AS QUAD _                                  ' __out ULARGE_INTEGER *pui
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ConnectToConnectionPoint IMPORT "SHLWAPI.DLL" ALIAS "ConnectToConnectionPoint" ( _
   BYVAL punk AS IUnknown _                             ' __in_opt IUnknown* punk
 , BYREF riidEvent AS GUID _                            ' __in REFIID riidEvent
 , BYVAL fConnect AS LONG _                             ' __in BOOL fConnect
 , BYVAL punkTarget AS IUnknown _                       ' __in IUnknown* punkTarget
 , BYREF pdwCookie AS DWORD _                           ' __out DWORD* pdwCookie
 , BYREF ppcpOut AS IConnectionPoint _                  ' __out_opt IConnectionPoint** ppcpOut
 ) AS LONG                                              ' HRESULT

'#endif // (_WIN32_IE >= _WIN32_IE_IE501)

'#if (_WIN32_IE >= _WIN32_IE_IE60)

DECLARE FUNCTION IStream_ReadPidl IMPORT "SHLWAPI.DLL" ALIAS "IStream_ReadPidl" ( _
   BYVAL pstm AS IStream _                              ' __in IStream *pstm
 , BYREF ppidlOut AS ANY _                              ' __out PIDLIST_RELATIVE *ppidlOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION IStream_WritePidl IMPORT "SHLWAPI.DLL" ALIAS "IStream_WritePidl" ( _
   BYVAL pstm AS IStream _                              ' __in IStream *pstm
 , BYVAL pidlWrite AS DWORD _                           ' __in PCUIDLIST_RELATIVE pidlWrite
 ) AS LONG                                              ' HRESULT

'#endif // (_WIN32_IE >= _WIN32_IE_IE60)

'#if (_WIN32_IE >= _WIN32_IE_IE70)

DECLARE FUNCTION IStream_ReadStr IMPORT "SHLWAPI.DLL" ALIAS "IStream_ReadStr" ( _
   BYVAL pstm AS IStream _                              ' __in IStream *pstm
 , BYREF ppsz AS DWORD _                                ' __out PWSTR *ppsz
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION IStream_WriteStr IMPORT "SHLWAPI.DLL" ALIAS "IStream_WriteStr" ( _
   BYVAL pstm AS IStream _                              ' __in IStream *pstm
 , BYREF psz AS WSTRINGZ _                              ' __in PCWSTR psz
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION IStream_Copy IMPORT "SHLWAPI.DLL" ALIAS "IStream_Copy" ( _
   BYVAL pstm AS IStream _                              ' __in IStream *pstmFrom
 , BYVAL pstmTo AS IStream _                            ' __in IStream *pstmTo
 , BYVAL cb AS DWORD _                                  ' __in DWORD cb
 ) AS LONG                                              ' HRESULT

'#endif // (_WIN32_IE >= _WIN32_IE_IE70)

'#if (_WIN32_IE >= 0x0600)
%SHGVSPB_PERUSER             = &H00000001??? ' // must have one of PERUSER or ALLUSERS
%SHGVSPB_ALLUSERS            = &H00000002???
%SHGVSPB_PERFOLDER           = &H00000004??? ' // must have one of PERFOLDER ALLFOLDERS or INHERIT
%SHGVSPB_ALLFOLDERS          = &H00000008???
%SHGVSPB_INHERIT             = &H00000010???
%SHGVSPB_ROAM                = &H00000020??? ' // modifies the above
%SHGVSPB_NOAUTODEFAULTS      = &H80000000??? ' // turns off read delegation to more general property bags

%SHGVSPB_FOLDER              = (%SHGVSPB_PERUSER OR %SHGVSPB_PERFOLDER)
%SHGVSPB_FOLDERNODEFAULTS    = (%SHGVSPB_PERUSER OR %SHGVSPB_PERFOLDER OR %SHGVSPB_NOAUTODEFAULTS)
%SHGVSPB_USERDEFAULTS        = (%SHGVSPB_PERUSER OR %SHGVSPB_ALLFOLDERS)
%SHGVSPB_GLOBALDEFAULTS      = (%SHGVSPB_ALLUSERS OR %SHGVSPB_ALLFOLDERS)

DECLARE FUNCTION SHGetViewStatePropertyBag IMPORT "SHLWAPI.DLL" ALIAS "SHGetViewStatePropertyBag" ( _
   BYVAL pidl AS ITEMIDLIST PTR _                       ' __in LPCITEMIDLIST pidl
 , BYREF pszBagName AS WSTRINGZ _                       ' __in LPCWSTR pszBagName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS ANY _                                   ' __out void **ppv
 ) AS LONG                                              ' HRESULT
'#endif  // (_WIN32_IE >= 0x0600)

'// SHFormatDateTime flags
'//  (FDTF_SHORTDATE and FDTF_LONGDATE are mutually exclusive, as is
'//   FDTF_SHORTIME and FDTF_LONGTIME.)
'//
%FDTF_SHORTTIME          = &H00000001???      ' // eg, "7:48 PM"
%FDTF_SHORTDATE          = &H00000002???      ' // eg, "3/29/98"
%FDTF_DEFAULT            = %FDTF_SHORTDATE OR %FDTF_SHORTTIME  ' // eg, "3/29/98 7:48 PM"
%FDTF_LONGDATE           = &H00000004???      ' // eg, "Monday, March 29, 1998"
%FDTF_LONGTIME           = &H00000008???      ' // eg. "7:48:33 PM"
%FDTF_RELATIVE           = &H00000010???      ' // uses "Yesterday", etc. if possible
%FDTF_LTRDATE            = &H00000100???      ' // Left To Right reading order
%FDTF_RTLDATE            = &H00000200???      ' // Right To Left reading order
%FDTF_NOAUTOREADINGORDER = &H00000400???      ' // Don't detect reading order automatically. Useful if you will be converting to Ansi and don't want Unicode reading order characters

DECLARE FUNCTION SHFormatDateTimeA IMPORT "SHLWAPI.DLL" ALIAS "SHFormatDateTimeA" ( _
   BYREF pft AS FILETIME _                              ' __in const FILETIME UNALIGNED * pft
 , BYREF pdwFlags AS DWORD _                            ' __inout_opt DWORD * pdwFlags
 , BYREF pszBuf AS ASCIIZ _                             ' __out LPSTR pszBuf
 , BYVAL cchBuf AS DWORD _                              ' __in UINT cchBuf
 ) AS LONG                                              ' int

DECLARE FUNCTION SHFormatDateTimeW IMPORT "SHLWAPI.DLL" ALIAS "SHFormatDateTimeW" ( _
   BYREF pft AS FILETIME _                              ' __in const FILETIME UNALIGNED * pft
 , BYREF pdwFlags AS DWORD _                            ' __inout_opt DWORD * pdwFlags
 , BYREF pszBuf AS WSTRINGZ _                           ' __out LPWSTR pszBuf
 , BYVAL cchBuf AS DWORD _                              ' __in UINT cchBuf
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO SHFormatDateTime = SHFormatDateTimeW
#ELSE
   MACRO SHFormatDateTime = SHFormatDateTimeA
#ENDIF

'#if (_WIN32_IE >= _WIN32_IE_IE501)

DECLARE FUNCTION SHAnsiToUnicode IMPORT "SHLWAPI.DLL" ALIAS "SHAnsiToUnicode" ( _
   BYREF pszSrc AS ASCIIZ _                             ' __in LPCSTR pszSrc
 , BYREF pwszDst AS WSTRINGZ _                          ' __out LPWSTR pwszDst
 , BYVAL cwchBuf AS LONG _                              ' __in int cwchBuf
 ) AS LONG                                              ' int

DECLARE FUNCTION SHAnsiToAnsi IMPORT "SHLWAPI.DLL" ALIAS "SHAnsiToAnsi" ( _
   BYREF pszSrc AS ASCIIZ _                             ' __in LPCSTR pszSrc
 , BYREF pszDst AS ASCIIZ _                             ' __out LPSTR pszDst
 , BYVAL cchBuf AS LONG _                               ' __in int cchBuf
 ) AS LONG                                              ' int

DECLARE FUNCTION SHUnicodeToAnsi IMPORT "SHLWAPI.DLL" ALIAS "SHUnicodeToAnsi" ( _
   BYREF pwszSrc AS WSTRINGZ _                          ' __in LPCWSTR pwszSrc
 , BYREF pszDst AS ASCIIZ _                             ' __out LPSTR pszDst
 , BYVAL cchBuf AS LONG _                               ' __in int cchBuf
 ) AS LONG                                              ' int

DECLARE FUNCTION SHUnicodeToUnicode IMPORT "SHLWAPI.DLL" ALIAS "SHUnicodeToUnicode" ( _
   BYREF pwszSrc AS WSTRINGZ _                          ' __in LPCWSTR pwszSrc
 , BYREF pwszDst AS WSTRINGZ _                          ' __out LPWSTR pwszDst
 , BYVAL cwchBuf AS LONG _                              ' __in int cwchBuf
 ) AS LONG                                              ' int

'// The return value from all SH<Type>To<Type> is the size of szDest including the terminater.
'#ifdef UNICODE
'#define SHTCharToUnicode(wzSrc, wzDest, cchSize)                SHUnicodeToUnicode(wzSrc, wzDest, cchSize)
'#define SHTCharToAnsi(wzSrc, szDest, cchSize)                   SHUnicodeToAnsi(wzSrc, szDest, cchSize)
'#define SHUnicodeToTChar(wzSrc, wzDest, cchSize)                SHUnicodeToUnicode(wzSrc, wzDest, cchSize)
'#define SHAnsiToTChar(szSrc, wzDest, cchSize)                   SHAnsiToUnicode(szSrc, wzDest, cchSize)
'#else // UNICODE
'#define SHTCharToUnicode(szSrc, wzDest, cchSize)                SHAnsiToUnicode(szSrc, wzDest, cchSize)
'#define SHTCharToAnsi(szSrc, szDest, cchSize)                   SHAnsiToAnsi(szSrc, szDest, cchSize)
'#define SHUnicodeToTChar(wzSrc, szDest, cchSize)                SHUnicodeToAnsi(wzSrc, szDest, cchSize)
'#define SHAnsiToTChar(szSrc, szDest, cchSize)                   SHAnsiToAnsi(szSrc, szDest, cchSize)
'#endif // UNICODE

'#if (_WIN32_IE >= _WIN32_IE_IE501)

DECLARE FUNCTION SHMessageBoxCheckA IMPORT "SHLWAPI.DLL" ALIAS "SHMessageBoxCheckA" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pszText AS ASCIIZ _                            ' __in LPCSTR pszText
 , BYREF pszCaption AS ASCIIZ _                         ' __in LPCSTR pszCaption
 , BYVAL uType AS DWORD _                               ' __in UINT uType
 , BYVAL iDefault AS LONG _                             ' __in int iDefault
 , BYREF pszRegVal AS ASCIIZ _                          ' __in LPCSTR pszRegVal
 ) AS LONG                                              ' int

DECLARE FUNCTION SHMessageBoxCheckW IMPORT "SHLWAPI.DLL" ALIAS "SHMessageBoxCheckW" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pszText AS WSTRINGZ _                          ' __in LPCWSTR pszText
 , BYREF pszCaption AS WSTRINGZ _                       ' __in LPCWSTR pszCaption
 , BYVAL uType AS DWORD _                               ' __in UINT uType
 , BYVAL iDefault AS LONG _                             ' __in int iDefault
 , BYVAL pszRegVal AS DWORD _                           ' __in LPCWSTR pszRegVal
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO SHMessageBoxCheck = SHMessageBoxCheckW
#ELSE
   MACRO SHMessageBoxCheck = SHMessageBoxCheckA
#ENDIF

'#endif // (_WIN32_IE >= _WIN32_IE_IE501)

'#if (_WIN32_IE >= _WIN32_IE_IE501)

'// Prevents hang do to hung window on broadcast
DECLARE FUNCTION SHSendMessageBroadcastA IMPORT "SHLWAPI.DLL" ALIAS "SHSendMessageBroadcastA" ( _
   BYVAL uMsg AS DWORD _                                ' __in UINT uMsg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' LRESULT

'// Prevents hang do to hung window on broadcast
DECLARE FUNCTION SHSendMessageBroadcastW IMPORT "SHLWAPI.DLL" ALIAS "SHSendMessageBroadcastW" ( _
   BYVAL uMsg AS DWORD _                                ' __in UINT uMsg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' LRESULT

#IF %DEF(%UNICODE)
   MACRO SHSendMessageBroadcast = SHSendMessageBroadcastW
#ELSE
   MACRO SHSendMessageBroadcast = SHSendMessageBroadcastA
#ENDIF

DECLARE FUNCTION SHStripMneumonicA IMPORT "SHLWAPI.DLL" ALIAS "SHStripMneumonicA" ( _
   BYREF pszMenu AS ASCIIZ _                            ' __inout LPSTR pszMenu
 ) AS BYTE                                              ' CHAR

DECLARE FUNCTION SHStripMneumonicW IMPORT "SHLWAPI.DLL" ALIAS "SHStripMneumonicW" ( _
   BYREF pszMenu AS WSTRINGZ _                          ' __inout LPWSTR pszMenu
 ) AS WORD                                              ' WCHAR

#IF %DEF(%UNICODE)
   MACRO SHStripMneumonic = SHStripMneumonicW
#ELSE
   MACRO SHStripMneumonic = SHStripMneumonicA
#ENDIF

#IF NOT %DEF(%NO_SHLWAPI_ISOS)

'// Returns TRUE/FALSE depending on question
%OS_WINDOWS                 = 0           ' // Windows 9x vs. NT
%OS_NT                      = 1           ' // Windows 9x vs. NT
%OS_WIN95ORGREATER          = 2           ' // Win95 or greater
%OS_NT4ORGREATER            = 3           ' // NT4 or greater
%OS_WIN98ORGREATER          = 5           ' // Win98 or greater
%OS_WIN98_GOLD              = 6           ' // Win98 Gold (Version 4.10 build 1998)
%OS_WIN2000ORGREATER        = 7           ' // Some derivative of Win2000

'// NOTE: these flags check explicitly for (dwMajorVersion == 5)
%OS_WIN2000PRO              = 8           ' // Windows 2000 Professional (Workstation)
%OS_WIN2000SERVER           = 9           ' // Windows 2000 Server
%OS_WIN2000ADVSERVER        = 10          ' // Windows 2000 Advanced Server
%OS_WIN2000DATACENTER       = 11          ' // Windows 2000 Data Center Server
%OS_WIN2000TERMINAL         = 12          ' // Windows 2000 Terminal Server in "Application Server" mode (now simply called "Terminal Server")

%OS_EMBEDDED                = 13          ' // Embedded Windows Edition
%OS_TERMINALCLIENT          = 14          ' // Windows Terminal Client (eg user is comming in via tsclient)
%OS_TERMINALREMOTEADMIN     = 15          ' // Terminal Server in "Remote Administration" mode
%OS_WIN95_GOLD              = 16          ' // Windows 95 Gold (Version 4.0 Build 1995)
%OS_MEORGREATER             = 17          ' // Windows Millennium (Version 5.0)
%OS_XPORGREATER             = 18          ' // Windows XP or greater
%OS_HOME                    = 19          ' // Home Edition (eg NOT Professional, Server, Advanced Server, or Datacenter)
%OS_PROFESSIONAL            = 20          ' // Professional     (aka Workstation; eg NOT Server, Advanced Server, or Datacenter)
%OS_DATACENTER              = 21          ' // Datacenter       (eg NOT Server, Advanced Server, Professional, or Personal)
%OS_ADVSERVER               = 22          ' // Advanced Server  (eg NOT Datacenter, Server, Professional, or Personal)
%OS_SERVER                  = 23          ' // Server           (eg NOT Datacenter, Advanced Server, Professional, or Personal)
%OS_TERMINALSERVER          = 24          ' // Terminal Server - server running in what used to be called "Application Server" mode (now simply called "Terminal Server")
%OS_PERSONALTERMINALSERVER  = 25          ' // Personal Terminal Server - per/pro machine running in single user TS mode
%OS_FASTUSERSWITCHING       = 26          ' // Fast User Switching
%OS_WELCOMELOGONUI          = 27          ' // New friendly logon UI
%OS_DOMAINMEMBER            = 28          ' // Is this machine a member of a domain (eg NOT a workgroup)
%OS_ANYSERVER               = 29          ' // is this machine any type of server? (eg datacenter or advanced server or server)?
%OS_WOW6432                 = 30          ' // Is this process a 32-bit process running on an 64-bit platform?
%OS_WEBSERVER               = 31          ' // Web Edition Server
%OS_SMALLBUSINESSSERVER     = 32          ' // SBS Server
%OS_TABLETPC                = 33          ' // Are we running on a TabletPC?
%OS_SERVERADMINUI           = 34          ' // Should defaults lean towards those preferred by server administrators?
%OS_MEDIACENTER             = 35          ' // eHome Freestyle Project
%OS_APPLIANCE               = 36          ' // Windows .NET Appliance Server

DECLARE FUNCTION IsOS IMPORT "SHLWAPI.DLL" ALIAS "IsOS" ( _
   BYVAL dwOS AS DWORD _                                ' __in DWORD dwOS
 ) AS LONG                                              ' BOOL

#ENDIF   ' // NO_SHLWAPI_ISOS

'#endif // (_WIN32_IE >= _WIN32_IE_IE501)

' enum SHGLOBALCOUNTER
%GLOBALCOUNTER_SEARCHMANAGER = 0
%GLOBALCOUNTER_SEARCHOPTIONS = 1
%GLOBALCOUNTER_FOLDERSETTINGSCHANGE = 2
%GLOBALCOUNTER_RATINGS = 3
%GLOBALCOUNTER_APPROVEDSITES = 4
%GLOBALCOUNTER_RESTRICTIONS = 5
%GLOBALCOUNTER_SHELLSETTINGSCHANGED = 6
%GLOBALCOUNTER_SYSTEMPIDLCHANGE = 7
%GLOBALCOUNTER_OVERLAYMANAGER = 8
%GLOBALCOUNTER_QUERYASSOCIATIONS = 9
%GLOBALCOUNTER_IESESSIONS = 10
%GLOBALCOUNTER_IEONLY_SESSIONS = 11
%GLOBALCOUNTER_APPLICATION_DESTINATIONS = 12
'__UNUSED_RECYCLE_WAS_%GLOBALCOUNTER_CSCSYNCINPROGRESS = 13
%GLOBALCOUNTER_BITBUCKETNUMDELETERS = 14
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_SHARES = 15
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_A = 16
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_B = 17
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_C = 18
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_D = 19
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_E = 20
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_F = 21
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_G = 22
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_H = 23
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_I = 24
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_J = 25
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_K = 26
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_L = 27
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_M = 28
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_N = 29
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_O = 30
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_P = 31
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Q = 32
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_R = 33
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_S = 34
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_T = 35
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_U = 36
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_V = 37
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_W = 38
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_X = 39
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Y = 40
%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Z = 41
'__UNUSED_RECYCLE_WAS_%GLOBALCOUNTER_RECYCLEDIRTYCOUNT_SERVERDRIVE = 42
'__UNUSED_RECYCLE_WAS_%GLOBALCOUNTER_RECYCLEGLOBALDIRTYCOUNT = 43
%GLOBALCOUNTER_RECYCLEBINENUM = 44
%GLOBALCOUNTER_RECYCLEBINCORRUPTED = 45
%GLOBALCOUNTER_RATINGS_STATECOUNTER = 46
%GLOBALCOUNTER_PRIVATE_PROFILE_CACHE = 47
%GLOBALCOUNTER_INTERNETTOOLBAR_LAYOUT = 48
%GLOBALCOUNTER_FOLDERDEFINITION_CACHE = 49
%GLOBALCOUNTER_COMMONPLACES_LIST_CACHE = 50
%GLOBALCOUNTER_PRIVATE_PROFILE_CACHE_MACHINEWIDE = 51
%GLOBALCOUNTER_ASSOCCHANGED = 52   ' // throttles reading of the registry value "GlobalAssocChangedCounter" from HKLM\Software\Microsoft\Windows\CurrentVersion\Explorer
%GLOBALCOUNTER_MAXIMUMVALUE = 53   ' // should always be last value

DECLARE FUNCTION SHGlobalCounterGetValue IMPORT "SHELL32.DLL" ALIAS "SHGlobalCounterGetValue" ( _
   BYVAL id AS LONG _                                   ' const SHGLOBALCOUNTER id
 ) AS LONG                                              ' long

DECLARE FUNCTION SHGlobalCounterIncrement IMPORT "SHELL32.DLL" ALIAS "SHGlobalCounterIncrement" ( _
   BYVAL id AS LONG _                                   ' const SHGLOBALCOUNTER id
 ) AS LONG                                              ' long

DECLARE FUNCTION SHGlobalCounterDecrement IMPORT "SHELL32.DLL" ALIAS "SHGlobalCounterDecrement" ( _
   BYVAL id AS LONG _                                   ' const SHGLOBALCOUNTER id
 ) AS LONG                                              ' long

'// Shared memory apis

'#if (_WIN32_IE >= 0x0603)
DECLARE FUNCTION SHAllocShared IMPORT "SHELL32.DLL" ALIAS "SHAllocShared" ( _
   BYVAL pvData AS DWORD _                              ' __in LPCVOID pvData
 , BYVAL dwSize AS DWORD _                              ' __in DWORD dwSize
 , BYVAL dwDestinationProcessId AS DWORD _              ' __in DWORD dwDestinationProcessId
 ) AS DWORD                                             ' HANDLE

'FUNCTION SHAllocShared ( _
'   BYVAL pvData AS DWORD _                       ' __in LPCVOID pvData
' , BYVAL dwSize AS DWORD _                       ' __in DWORD dwSize
' , BYVAL dwDestinationProcessId AS DWORD _       ' __in DWORD dwDestinationProcessId
'   ) AS DWORD                                    ' HANDLE

'   LOCAL DWRESULT AS DWORD
'   LOCAL hLib  AS DWORD
'   LOCAL pAddr AS DWORD

'   hLib = LoadLibrary("SHELL32.DLL")
'   IF hLib THEN
'      pAddr = GetProcAddress(hLib, BYVAL MAK(DWORD, 520, 0))
'      IF pAddr THEN CALL DWORD pAddr USING SHAllocShared(pvData, dwSize, dwDestinationProcessId) TO DWRESULT
'      FreeLibrary hLib
'   END IF
'   FUNCTION = DWRESULT

'END FUNCTION

DECLARE FUNCTION SHFreeShared IMPORT "SHELL32.DLL" ALIAS "SHFreeShared" ( _
   BYVAL hData AS DWORD _                               ' __in HANDLE hData
 , BYVAL dwSourceProcId AS DWORD _                      ' __in DWORD dwSourceProcId
 ) AS LONG                                              ' BOOL

'FUNCTION SHFreeShared ( _
'   BYVAL hData AS DWORD _                        ' HANDLE hData
' , BYVAL dwSourceProcId AS DWORD _               ' DWORD dwSourceProcId
'   ) AS LONG                                     ' BOOL

'   LOCAL LRESULT AS LONG
'   LOCAL hLib  AS DWORD
'   LOCAL pAddr AS DWORD

'   hLib = LoadLibrary("SHELL32.DLL")
'   IF hLib THEN
'      pAddr = GetProcAddress(hLib, BYVAL MAK(DWORD, 523, 0))
'      IF pAddr THEN CALL DWORD pAddr USING SHFreeShared(hData, dwSourceProcId) TO LRESULT
'      FreeLibrary hLib
'   END IF
'   FUNCTION = LRESULT

'END FUNCTION

DECLARE FUNCTION SHLockShared IMPORT "SHELL32.DLL" ALIAS "SHLockShared" ( _
   BYVAL hData AS DWORD _                               ' __in HANDLE * hData
 , BYVAL dwOtherProcId AS DWORD _                       ' __in DWORD dwOtherProcId
 ) AS DWORD                                             ' LPVOID

'FUNCTION SHLockShared ( _
'   BYVAL hData AS DWORD _                        ' __in HANDLE * hData
' , BYVAL dwOtherProcId AS DWORD _                ' __in DWORD dwOtherProcId
'   ) AS DWORD                                    ' LPVOID

'   LOCAL DWRESULT AS DWORD
'   LOCAL hLib  AS DWORD
'   LOCAL pAddr AS DWORD

'   hLib = LoadLibrary("SHELL32.DLL")
'   IF hLib THEN
'      pAddr = GetProcAddress(hLib, BYVAL MAK(DWORD, 521, 0))
'      IF pAddr THEN CALL DWORD pAddr USING SHLockShared(hData, dwOtherProcId) AS DWRESULT
'      FreeLibrary hLib
'   END IF
'   FUNCTION = DWRESULT

'END FUNCTION

DECLARE FUNCTION SHUnlockShared IMPORT "SHELL32.DLL" ALIAS "SHUnlockShared" ( _
   BYVAL lpvData AS DWORD _                             ' __in LPVOID lpvData
 ) AS LONG                                              ' BOOL

'FUNCTION SHUnlockShared ( _
'   BYVAL lpvData AS DWORD _                      ' __in LPVOID lpvData
'   ) AS LONG                                     ' BOOL

'   LOCAL LRESULT AS LONG
'   LOCAL hLib  AS DWORD
'   LOCAL pAddr AS DWORD

'   hLib = LoadLibrary("SHELL32.DLL")
'   IF hLib THEN
'      pAddr = GetProcAddress(hLib, BYVAL MAK(DWORD, 522, 0))
'      IF pAddr THEN CALL DWORD pAddr USING SHUnlockShared(lpvData) TO LRESULT
'      FreeLibrary hLib
'   END IF
'   FUNCTION = LRESULT

'END FUNCTION

'#endif // _WIN32_IE >= 0x0603

'#if (_WIN32_IE >= _WIN32_IE_IE501)

DECLARE FUNCTION WhichPlatform IMPORT "SHELL32.DLL" ALIAS "WhichPlatform" ( _
 ) AS DWORD                                             ' UINT

'// Return values of WhichPlatform
%PLATFORM_UNKNOWN     = 0
%PLATFORM_IE3         = 1     ' // obsolete: use PLATFORM_BROWSERONLY
%PLATFORM_BROWSERONLY = 1     ' // browser-only (no new shell)
%PLATFORM_INTEGRATED  = 2     ' // integrated shell

'//***   QueryInterface helpers
'// NOTES
'//  ATL has a fancier version of this.  if we need to extend ours, we
'//  should probably just switch to ATL's rather than reinvent.
'// EXAMPLE
'//  Cfoo::QI(REFIID riid, void **ppv)
'//  {
'//      // (the IID_xxx comments make grep'ing work!)
'//      static const QITAB qit = {
'//          QITABENT(Cfoo, Iiface1),    // IID_Iiface1
'//          ...
'//          QITABENT(Cfoo, IifaceN),    // IID_IifaceN
'//          { 0 },                      // n.b. don't forget the 0
'//      };
'//
'//      // n.b. make sure you don't cast 'this'
'//      hr = QISearch(this, qit, riid, ppv);
'//      if (FAILED(hr))
'//          hr = SUPER::QI(riid, ppv);
'//      // custom code could be added here for FAILED() case
'//      return hr;
'//  }
'//
'//  If you have an interface that is implemented multiple times,
'//  the compiler will claim an ambiguous cast, so you need to give
'//  some help.  For example, if your class is defined as
'//
'//  class CClass : public IPersistStream, public IPersistFile
'//
'//  then you need to say
'//
'//      QITABENTMULTI(CClass, IPersist, IPersistStream)
'//      QITABENT(CClass, IPersistStream)
'//      QITABENT(CClass, IPersistFile)
'//
'//  The MULTI is needed for IPersist because the compiler doesn't
'//  know whether you wanted the IPersist from IPersistStream
'//  or the IPersist from IPersistFile.  Unless you have played weird
'//  compiler tricks, they are the same implementation, so you can
'//  just pick either one, doesn't matter.
'//
'//  Common mistake: You do not need to use MULTI if the base interface
'//  can be unambiguously determined.  E.g.,
'//
'//  class CSimple : public IContextMenu3
'//
'//      QITABENT(CClass, IContextMenu)      // do not need MULTI
'//      QITABENT(CClass, IContextMenu2)     // do not need MULTI
'//      QITABENT(CClass, IContextMenu3)
'//
'//  Do not create an entry for IUnknown; the first entry in the
'//  table will be used for IUnknown.
'//

' // Size = 8 bytes
TYPE QITAB DWORD
   piid     AS GUID PTR   ' const IID *
   dwOffset AS LONG       ' int
END TYPE

'#ifdef __cplusplus

'#define QITABENTMULTI(Cthis, Ifoo, Iimpl) \
'    { &__uuidof(Ifoo), OFFSETOFCLASS(Iimpl, Cthis) }

'#else

'#define QITABENTMULTI(Cthis, Ifoo, Iimpl) \
'    { (IID*) &IID_##Ifoo, OFFSETOFCLASS(Iimpl, Cthis) }

'#endif  // __cplusplus

'#define QITABENTMULTI2(Cthis, Ifoo, Iimpl) \
'    { (IID*) &Ifoo, OFFSETOFCLASS(Iimpl, Cthis) }

'#define QITABENT(Cthis, Ifoo) QITABENTMULTI(Cthis, Ifoo, Ifoo)

DECLARE FUNCTION QISearch IMPORT "SHELL32.DLL" ALIAS "QISearch" ( _
   BYVAL that AS IUnknown _                             ' __inout void* that
 , BYREF pqit AS QITAB _                                ' __in LPCQITAB pqit
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

'#endif // (_WIN32_IE >= _WIN32_IE_IE501)

'#ifndef STATIC_CAST
'//***   STATIC_CAST -- 'portable' static_cast<>
'// NOTES
'//  do *not* use SAFE_CAST (see comment in OFFSETOFCLASS)
'#define STATIC_CAST(typ)   static_cast<typ>
'#ifndef _X86_
'    // assume only intel compiler (>=vc5) supports static_cast for now
'    // we could key off of _MSC_VER >= 1100 but i'm not sure that will work
'    //
'    // a straight cast will give the correct result but no error checking,
'    // so we'll have to catch errors on intel.
'    #undef  STATIC_CAST
'    #define STATIC_CAST(typ)   (typ)
'#endif
'#endif

'#ifndef OFFSETOFCLASS
'//***   OFFSETOFCLASS -- (stolen from ATL)
'// we use STATIC_CAST not SAFE_CAST because the compiler gets confused
'// (it doesn't constant-fold the ,-op in SAFE_CAST so we end up generating
'// code for the table!)

'#define OFFSETOFCLASS(base, derived) \
'    ((DWORD)(DWORD_PTR)(STATIC_CAST(base*)((derived*)8))-8)
'#endif


'// Types for SHIsLowMemoryMachine
%ILMM_IE4   = 0      ' // 1997-era machine

DECLARE FUNCTION SHIsLowMemoryMachine IMPORT "SHELL32.DLL" ALIAS "SHIsLowMemoryMachine" ( _
   BYVAL dwType AS DWORD _                              ' DWORD dwType
 ) AS LONG                                              ' BOOL

'// Menu Helpers
DECLARE FUNCTION GetMenuPosFromID IMPORT "SHELL32.DLL" ALIAS "GetMenuPosFromID" ( _
   BYVAL hmenu AS DWORD _                               ' __in HMENU hmenu
 , BYVAL id AS DWORD _                                  ' __in UINT id
 ) AS LONG                                              ' int

DECLARE FUNCTION SHGetInverseCMAP IMPORT "SHELL32.DLL" ALIAS "SHGetInverseCMAP" ( _
   BYREF pbMap AS BYTE _                                ' __out BYTE *pbMap
 , BYVAL cbMap AS DWORD _                               ' __in ULONG cbMap
 ) AS LONG                                              ' HRESULT

'#if (_WIN32_IE >= 0x0500)

'// SHAutoComplete
'//      hwndEdit - HWND of editbox, ComboBox or ComboBoxEx.
'//      dwFlags - Flags to indicate what to AutoAppend or AutoSuggest for the editbox.
'//
'// WARNING:
'//    Caller needs to have called CoInitialize() or OleInitialize()
'//    and cannot call CoUninit/OleUninit until after
'//    WM_DESTROY on hwndEdit.
'//
'//  dwFlags values:
%SHACF_DEFAULT                   = &H00000000???  ' // Currently (SHACF_FILESYSTEM | SHACF_URLALL)
%SHACF_FILESYSTEM                = &H00000001???  ' // This includes the File System as well as the rest of the shell (Desktop\My Computer\Control Panel\)
%SHACF_URLHISTORY                = &H00000002???  ' // URLs in the User's History
%SHACF_URLMRU                    = &H00000004???  ' // URLs in the User's Recently Used list.
%SHACF_USETAB                    = &H00000008???  ' // Use the tab to move thru the autocomplete possibilities instead of to the next dialog/window control.
%SHACF_FILESYS_ONLY              = &H00000010???  ' // This includes the File System
%SHACF_URLALL                    = (%SHACF_URLHISTORY OR %SHACF_URLMRU)
'#if (_WIN32_IE >= 0x0600)
%SHACF_FILESYS_DIRS              = &H00000020???  ' // Same as SHACF_FILESYS_ONLY except it only includes directories, UNC servers, and UNC server shares.
'#endif ' // (_WIN32_IE >= = &H0600)
'#if (_WIN32_IE >= _WIN32_IE_IE70)
%SHACF_VIRTUAL_NAMESPACE         = &H00000040???  ' // Also include the virtual namespace
'#endif ' // _WIN32_IE_IE70
%SHACF_AUTOSUGGEST_FORCE_ON      = &H10000000???  ' // Ignore the registry default and force the feature on.
%SHACF_AUTOSUGGEST_FORCE_OFF     = &H20000000???  ' // Ignore the registry default and force the feature off.
%SHACF_AUTOAPPEND_FORCE_ON       = &H40000000???  ' // Ignore the registry default and force the feature on. (Also know as AutoComplete)
%SHACF_AUTOAPPEND_FORCE_OFF      = &H80000000???  ' // Ignore the registry default and force the feature off. (Also know as AutoComplete)

DECLARE FUNCTION SHAutoComplete IMPORT "SHLWAPI.DLL" ALIAS "SHAutoComplete" ( _
   BYVAL hwndEdit AS DWORD _                            ' __in HWND hwndEdit
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

'#if (_WIN32_IE >= _WIN32_IE_IE60SP2)
DECLARE FUNCTION SHCreateThreadRef IMPORT "SHLWAPI.DLL" ALIAS "SHCreateThreadRef" ( _
   BYREF pcRef AS LONG _                                ' __inout LONG *pcRef
 , BYREF ppunk AS IUnknown _                            ' __out IUnknown **ppunk
 ) AS LONG                                              ' HRESULT
'#endif // _WIN32_IE_IE60SP2

DECLARE FUNCTION SHSetThreadRef IMPORT "SHLWAPI.DLL" ALIAS "SHSetThreadRef" ( _
   BYVAL punk AS IUnknown _                             ' __in IUnknown *punk
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHGetThreadRef IMPORT "SHLWAPI.DLL" ALIAS "SHGetThreadRef" ( _
   BYREF ppunk AS IUnknown _                            ' __out IUnknown **ppunk
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHSkipJunction IMPORT "SHLWAPI.DLL" ALIAS "SHSkipJunction" ( _
   BYVAL pbc AS DWORD _                                 ' __in IBindCtx *pbc
 , BYREF pclsid AS GUID _                               ' __in const CLSID *pclsid
 ) AS LONG                                              ' BOOL

'#endif // (_WIN32_IE >= 0x0500)

%CTF_INSIST          = &H00000001???      ' // SHCreateThread() dwFlags - call pfnThreadProc synchronously if CreateThread() fails
%CTF_THREAD_REF      = &H00000002???      ' // hold a reference to the creating thread
%CTF_PROCESS_REF     = &H00000004???      ' // hold a reference to the creating process
%CTF_COINIT_STA      = &H00000008???      ' // init COM for the created thread
%CTF_COINIT          = %CTF_COINIT_STA    ' // init COM as STA for the created thread
'#if (_WIN32_IE >= _WIN32_IE_IE60)
%CTF_FREELIBANDEXIT  = &H00000010???      ' // hold a ref to the DLL and call FreeLibraryAndExitThread() when done
%CTF_REF_COUNTED     = &H00000020???      ' // thread supports ref counting via SHGetThreadRef() or CTF_THREAD_REF so that child threads can keep this thread alive
%CTF_WAIT_ALLOWCOM   = &H00000040???      ' // while waiting for pfnCallback, allow COM marshaling to the blocked calling thread
'#endif // _WIN32_IE_IE60
'#if (_WIN32_IE >= _WIN32_IE_IE70)
%CTF_UNUSED          = &H00000080???
%CTF_INHERITWOW64    = &H00000100???      ' // new thread should inherit the wow64 disable state for the file system redirector
'#endif // _WIN32_IE_IE70
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%CTF_WAIT_NO_REENTRANCY = &H00000200???   ' // don't allow re-entrancy when waiting for the sync proc, this won't work with marshalled objects or SendMessages() from the sync proc
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)
'#if (NTDDI_VERSION >= NTDDI_WIN7)
%CTF_KEYBOARD_LOCALE    = &H00000400???   ' // carry the keyboard locale from creating to created thread
%CTF_OLEINITIALIZE      = &H00000800???   ' // init OLE on the created thread (this will also init COM as STA)
%CTF_COINIT_MTA         = &H00001000???   ' // init COM as MTA for the created thread
%CTF_NOADDREFLIB        = &H00002000???   ' // this flag is the opposite of CTF_FREELIBANDEXIT that is now implicit as of Vista
                                          ' // this avoids the LoadLibrary/FreeLibraryAndExitThread calls that result in contention for the loader lock
                                          ' // only use this when the thread being created has some other means to ensure that the code
                                          ' // of the thread proc will remain loaded. This should not be used in the context of COM objects as those
                                          ' // need to ensure that the DLL stays loaded as COM will unload DLLs

'#endif // (NTDDI_VERSION >= NTDDI_WIN7)
'typedef DWORD SHCT_FLAGS;   // SHCreateThread flags values

DECLARE FUNCTION SHCreateThread IMPORT "SHLWAPI.DLL" ALIAS "SHCreateThread" ( _
   BYVAL pfnThreadProc AS DWORD _                       ' __in LPTHREAD_START_ROUTINE pfnThreadProc
 , BYVAL pData AS DWORD _                               ' __in VOID *pData
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pfnCallback AS DWORD _                         ' __in LPTHREAD_START_ROUTINE pfnCallback
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SHCreateThreadWithHandle IMPORT "SHLWAPI.DLL" ALIAS "SHCreateThreadWithHandle" ( _
   BYVAL pfnThreadProc AS DWORD _                       ' __in LPTHREAD_START_ROUTINE pfnThreadProc
 , BYVAL pData AS DWORD _                               ' __in_opt VOID *pData
 , BYVAL flags AS DWORD _                               ' __in SHCT_FLAGS flags
 , BYVAL pfnCallback AS DWORD _                         ' __in_opt LPTHREAD_START_ROUTINE pfnCallback
 , BYREF pHandle AS DWORD _                             ' __out_opt HANDLE *pHandle
 ) AS LONG                                              ' BOOL

'#if (_WIN32_IE >= _WIN32_IE_IE60)
DECLARE FUNCTION SHReleaseThreadRef IMPORT "SHLWAPI.DLL" ALIAS "SHReleaseThreadRef" ( _
 ) AS LONG                                              ' HRESULT
'#endif // _WIN32_IE_IE60

#IF NOT %DEF(%NO_SHLWAPI_GDI)
'//
'//====== GDI helper functions  ================================================
'//

DECLARE FUNCTION SHCreateShellPalette IMPORT "SHLWAPI.DLL" ALIAS "SHCreateShellPalette" ( _
   BYVAL HDC AS DWORD _                                 ' __in HDC
 ) AS DWORD                                             ' HPALETTE

'#if (_WIN32_IE >= 0x0500)

DECLARE SUB ColorRGBToHLS IMPORT "SHLWAPI.DLL" ALIAS "ColorRGBToHLS" ( _
   BYVAL clrRGB AS DWORD _                              ' __in COLORREF clrRGB
 , BYREF pwHue AS WORD _                                ' __out WORD *pwHue
 , BYREF pwLuminance AS WORD _                          ' __out WORD *pwLuminance
 , BYREF pwSaturation AS WORD _                         ' __out WORD *pwSaturation
 )                                                      ' void

DECLARE FUNCTION ColorHLSToRGB IMPORT "SHLWAPI.DLL" ALIAS "ColorHLSToRGB" ( _
   BYVAL wHue AS WORD _                                 ' __in WORD wHue
 , BYVAL wLuminance AS WORD _                           ' __in WORD wLuminance
 , BYVAL wSaturation AS WORD _                          ' __in WORD wSaturation
 ) AS DWORD                                             ' COLORREF

DECLARE FUNCTION ColorAdjustLuma IMPORT "SHLWAPI.DLL" ALIAS "ColorAdjustLuma" ( _
   BYVAL clrRGB AS DWORD _                              ' __in COLORREF clrRGB
 , BYVAL n AS LONG _                                    ' __in int n
 , BYVAL fScale AS LONG _                               ' __in BOOL fScale
 ) AS DWORD                                             ' COLORREF

'#endif  // _WIN32_IE >= 0x0500

#ENDIF   ' // NO_SHLWAPI_GDI


'//
'//====== DllGetVersion  =======================================================
'//

' // Size = 20 bytes
TYPE DLLVERSIONINFO DWORD
   cbsize         AS DWORD
   dwMajorVersion AS DWORD   ' // Major version
   dwMinorVersion AS DWORD   ' // Minor version
   dwBuildNumber  AS DWORD   ' // Build number
   dwPlatformID   AS DWORD   ' // DLLVER_PLATFORM_*
END TYPE

'// Platform IDs for DLLVERSIONINFO
%DLLVER_PLATFORM_WINDOWS = &H00000001??? ' Windows 95
%DLLVER_PLATFORM_NT      = &H00000002??? ' Windows NT

'#if (_WIN32_IE >= 0x0501)

'typedef struct _DLLVERSIONINFO2
'{
'    DLLVERSIONINFO info1;
'    DWORD dwFlags;                          // No flags currently defined
'    ULONGLONG ullVersion;                   // Encoded as:
'                                            // Major 0xFFFF 0000 0000 0000
'                                            // Minor 0x0000 FFFF 0000 0000
'                                            // Build 0x0000 0000 FFFF 0000
'                                            // QFE   0x0000 0000 0000 FFFF
'} DLLVERSIONINFO2;

' // Size = 32 bytes
TYPE DLLVERSIONINFO2 DWORD   ' Must be 8 byte aligned
   info1      AS DLLVERSIONINFO
   dwFlags    AS DWORD
   uilVersion AS QUAD                      ' // Encoded as:
                                           ' // Major 0xFFFF 0000 0000 0000
                                           ' // Minor 0x0000 FFFF 0000 0000
                                           ' // Build 0x0000 0000 FFFF 0000
                                           ' // QFE   0x0000 0000 0000 FFFF
END TYPE

%DLLVER_MAJOR_MASK                    = &HFFFF000000000000&&
%DLLVER_MINOR_MASK                    = &H0000FFFF00000000&&
%DLLVER_BUILD_MASK                    = &H00000000FFFF0000&&
%DLLVER_QFE_MASK                      = &H000000000000FFFF&&

'#define MAKEDLLVERULL(major, minor, build, qfe) \
'        (((ULONGLONG)(major) << 48) |        \
'         ((ULONGLONG)(minor) << 32) |        \
'         ((ULONGLONG)(build) << 16) |        \
'         ((ULONGLONG)(  qfe) <<  0))

FUNCTION MAKEDLLVERULL (BYVAL major AS QUAD, BYVAL minor AS QUAD, BYVAL build AS QUAD, BYVAL qfe AS QUAD) AS QUAD
   SHIFT LEFT major, 48
   SHIFT LEFT minor, 32
   SHIFT LEFT build, 16
   SHIFT LEFT qfe, 0
   FUNCTION = major OR minor OR build OR qfe
END FUNCTION

'//
'// The caller should always GetProcAddress("DllGetVersion"), not
'// implicitly link to it.
'//

FUNCTION DllGetVersion (BYREF pdvi AS DLLVERSIONINFO) AS LONG

   LOCAL hLib  AS DWORD
   LOCAL pAddr AS DWORD
   LOCAL hr    AS LONG

   hr = 1
   pdvi.cbSize = SIZEOF(DLLVERSIONINFO)
   hLib = LoadLibrary("SHLWAPI.DLL")
   IF hLib THEN
      pAddr = GetProcAddress(hLib, "DllGetVersion")
      IF pAddr THEN CALL DWORD pAddr USING DllGetVersion(pdvi) TO hr
      FreeLibrary hLib
   END IF
   FUNCTION = hr

END FUNCTION

'typedef HRESULT (CALLBACK* DLLGETVERSIONPROC)(DLLVERSIONINFO *);

'// DllInstall (to be implemented by self-installing DLLs)
DECLARE FUNCTION DllInstall IMPORT "SHLWAPI.DLL" ALIAS "DllInstall" ( _
   BYVAL bInstall AS LONG _                             ' __in BOOL bInstall
 , BYREF pszCmdLine AS WSTRINGZ _                       ' __in LPCWSTR pszCmdLine
 ) AS LONG                                              ' HRESULT

'#if (_WIN32_IE >= 0x0602)
'// Function to see if Internet Explorer Enhanced Security Configuration is active for the current user
DECLARE FUNCTION IsInternetESCEnabled IMPORT "SHLWAPI.DLL" ALIAS "IsInternetESCEnabled" ( _
  ) AS LONG                                             ' BOOL
'#endif // (_WIN32_IE >= 0x0602)

' ========================================================================================
' Converts image file format between GIF/BMP/JPG/PNG.
' Undocumented function. Exported only by ordinal.
' typedef HRESULT (WINAPI*PSHCGF) (IN LPCWSTR pSrcFileName, IN LPCWSTR pDestFileName, IN DWORD dwFlags);
' ========================================================================================
FUNCTION SHConvertGraphicsFile( _
   BYREF wszSrcFileName AS WSTRINGZ, _                  ' Source file name
   BYREF wszDestFileName AS WSTRINGZ, _                 ' Destination file name
   BYVAL dwFlags AS DWORD _                             ' Overwrite file (TRUE/FALSE)
   ) AS LONG                                            ' HRESULT

   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD
   LOCAL hr AS LONG

   hLib = LoadLibrary("shlwapi.dll")
   IF hLib = %NULL THEN
      hr = GetLastError
   ELSE
      pProc = GetProcAddress (hLib, BYVAL MAK(LONG, 488, 0))
      IF pProc = %NULL THEN
         hr = GetLastError
      ELSE
         CALL DWORD pProc USING SHConvertGraphicsFile(wszSrcFileName, wszDestFileName, dwFlags) TO hr
      END IF
      FreeLibrary hLib
   END IF
   FUNCTION = hr

END FUNCTION
' ========================================================================================

#ENDIF   ' #IF NOT %DEF(%NOSHLWAPI)
