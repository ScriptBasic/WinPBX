' ########################################################################################
' Microsoft C Runtime
' File: mbctype.inc
' Contents: Functions for MBCS character classification/conversion
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MBCTYPE_INC = 1

#INCLUDE ONCE "crtdefs.inc"
#INCLUDE ONCE "ctype.inc"

'/*
' * MBCS - Multi-Byte Character Set
' */

'/*
' * This declaration allows the user access the _mbctype[] look-up array.
' */
'#if !defined(_M_CEE_PURE)
'/* No data exports in pure code */
'_CRTIMP extern unsigned char _mbctype[];
'_CRTIMP extern unsigned char _mbcasemap[];
'#else
'_Check_return_ _CRTIMP unsigned char * __cdecl __p__mbctype(void);
'_Check_return_ _CRTIMP unsigned char * __cdecl __p__mbcasemap(void);
'#define _mbctype   (__p__mbctype())
'#define _mbcasemap (__p__mbcasemap())
'#endif /* !defined(_M_CEE_PURE) */

'_CRTIMP extern unsigned char _mbctype[];
FUNCTION get_mbctype () AS DWORD
   LOCAL hLib AS DWORD
   LOCAL pmbctype AS WORD PTR
   hLib = LoadLibrary($CRT_DLLNAME)
   IF hLib THEN
      pmbctype = GetProcAddress(hLib, "_mbctype")
      FUNCTION = pmbctype
      FreeLibrary hLib
   END IF
END FUNCTION

'_CRTIMP extern unsigned char _mbcasemap[];
FUNCTION get_mbcasemap () AS DWORD
   LOCAL hLib AS DWORD
   LOCAL pmbcasemap AS WORD PTR
   hLib = LoadLibrary($CRT_DLLNAME)
   IF hLib THEN
      pmbcasemap = GetProcAddress(hLib, "_mbcasemap")
      FUNCTION = pmbcasemap
      FreeLibrary hLib
   END IF
END FUNCTION

'/* bit masks for MBCS character types */

%MS_     = &H01    ' /* MBCS single-byte symbol */
%MP_     = &H02    ' /* MBCS punct */
%M1_     = &H04    ' /* MBCS 1st (lead) byte */
%M2_     = &H08    ' /* MBCS 2nd byte*/

%SBUP_   = &H10    ' /* SBCS upper char */
%SBLOW_  = &H20    ' /* SBCS lower char */

'/* byte types  */

%MBC_SINGLE    = 0       ' /* valid single byte char */
%MBC_LEAD      = 1       ' /* lead byte */
%MBC_TRAIL     = 2       ' /* trailing byte */
%MBC_ILLEGAL   = -1      ' /* illegal byte */

%KANJI_CP      = 932

'/* _setmbcp parameter defines */

%MB_CP_SBCS    = 0
%MB_CP_OEM     = -2
%MB_CP_ANSI    = -3
%MB_CP_LOCALE  = -4

'/* MB control routines */

' ========================================================================================
' *** All versions ***
'_CRTIMP int __cdecl _setmbcp(_In_ int _CodePage);
' ========================================================================================
DECLARE FUNCTION setmbcp_ CDECL IMPORT $CRT_DLLNAME ALIAS "_setmbcp" ( _
   BYVAL codepage AS LONG _                             ' __in int codepage
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
'_CRTIMP int __cdecl _getmbcp(void);
' ========================================================================================
DECLARE FUNCTION getmbcp_ CDECL IMPORT $CRT_DLLNAME ALIAS "_getmbcp" ( _
 ) AS LONG                                              ' int
' ========================================================================================

'/* MBCS character classification function prototypes */


'/* byte routines */

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbbkalnum( _In_ unsigned int _C );
' ========================================================================================
DECLARE FUNCTION ismbbkalnum_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbbkalnum" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbbkalnum_l(_In_ unsigned int _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbbkalnum_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbbkalnum_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbbkana( _In_ unsigned int _C );
' ========================================================================================
DECLARE FUNCTION ismbbkana_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbbkana" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbbkana_l(_In_ unsigned int _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbbkana_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbbkana_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbbkpunct( _In_ unsigned int _C );
' ========================================================================================
DECLARE FUNCTION ismbbkpunct_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbbkpunct" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbbkpunct_l(_In_ unsigned int _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbbkpunct_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbbkpunct_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbbkprint( _In_ unsigned int _C );
' ========================================================================================
DECLARE FUNCTION ismbbkprint_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbbkprint" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbbkprint_l(_In_ unsigned int _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbbkprint_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbbkprint_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbbalpha( _In_ unsigned int _C );
' ========================================================================================
DECLARE FUNCTION ismbbalpha_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbbalpha" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbbalpha_l(_In_ unsigned int _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbbalpha_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbbalpha_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbbpunct( _In_ unsigned int _C );
' ========================================================================================
DECLARE FUNCTION ismbbpunct_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbbpunct" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbbpunct_l(_In_ unsigned int _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbbpunct_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbbpunct_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbbalnum( _In_ unsigned int _C );
' ========================================================================================
DECLARE FUNCTION ismbbalnum_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbbalnum" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbbalnum_l(_In_ unsigned int _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbbalnum_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbbalnum_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbbprint( _In_ unsigned int _C );
' ========================================================================================
DECLARE FUNCTION ismbbprint_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbbprint" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbbprint_l(_In_ unsigned int _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbbprint_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbbprint_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbbgraph( _In_ unsigned int _C );
' ========================================================================================
DECLARE FUNCTION ismbbgraph_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbbgraph" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbbgraph_l(_In_ unsigned int _C, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbbgraph_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbbgraph_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

#IF NOT %DEF(%MBLEADTRAIL_DEFINED)
    %MBLEADTRAIL_DEFINED = 1

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbblead( _In_ unsigned int _C);
' ========================================================================================
DECLARE FUNCTION ismbblead_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbblead" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbblead_l(_In_ unsigned int _C, _In_opt_ _locale_t _Locale );
' ========================================================================================
DECLARE FUNCTION ismbblead_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbblead_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbbtrail( _In_ unsigned int _C);
' ========================================================================================
DECLARE FUNCTION ismbbtrail_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbbtrail" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbbtrail_l(_In_ unsigned int _C, _In_opt_ _locale_t _Locale );
' ========================================================================================
DECLARE FUNCTION ismbbtrail_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbbtrail_l" ( _
   BYVAL c AS DWORD _                                   ' __in unsigned int c
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbslead(_In_bytecount_x_(_Pos - _Str+1) _Pre_z_ const unsigned char * _Str, _In_z_ const unsigned char * _Pos);
' ========================================================================================
DECLARE FUNCTION ismbslead_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbslead" ( _
   BYVAL string AS DWORD _                              ' __in const unsigned char *string
 , BYVAL current AS DWORD _                             ' __in const unsigned char *current
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbslead_l(_In_bytecount_x_(_Pos - _Str+1) _Pre_z_ const unsigned char * _Str, _In_z_ const unsigned char * _Pos, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbslead_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbslead_l" ( _
   BYVAL string AS DWORD _                              ' __in const unsigned char *string
 , BYVAL current AS DWORD _                             ' __in const unsigned char *current
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _ismbstrail(_In_bytecount_x_(_Pos - _Str+1) _Pre_z_ const unsigned char * _Str, _In_z_ const unsigned char * _Pos);
' ========================================================================================
DECLARE FUNCTION ismbstrail_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbstrail" ( _
   BYVAL string AS DWORD _                              ' __in const unsigned char *string
 , BYVAL current AS DWORD _                             ' __in const unsigned char *current
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _ismbstrail_l(_In_bytecount_x_(_Pos - _Str+1) _Pre_z_ const unsigned char * _Str, _In_z_ const unsigned char * _Pos, _In_opt_ _locale_t _Locale);
' ========================================================================================
DECLARE FUNCTION ismbstrail_l CDECL IMPORT $CRT_DLLNAME ALIAS "_ismbstrail_l" ( _
   BYVAL string AS DWORD _                              ' __in const unsigned char *string
 , BYVAL current AS DWORD _                             '__in  const unsigned char *current
 , OPTIONAL BYVAL locale AS locale_t _                  '__in_opt  _locale_t locale
 ) AS LONG                                              ' int
' ========================================================================================

#ENDIF   ' MBLEADTRAIL_DEFINED
