' ########################################################################################
' Microsoft Windows
' File: gb18030.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%GB18030_INC = 1

#INCLUDE ONCE "windows.inc"

'//
'//  Flags for dwFlags in NlsDllCodePageTranslation.
'//
%NLS_CP_CPINFO             = &H10000000???
%NLS_CP_MBTOWC             = &H40000000???
%NLS_CP_WCTOMB             = &H80000000???

'////////////////////////////////////////////////////////////////////////////
'//
'// gb18030.h
'//
'// This is the header for using the c_g18030.dll in the system.
'// This file lists all exported functions in c_g18030.dll.
'// c_g18030.dll is a codpeage conversion DLL for the Chinese GB-18030 codepage
'// (Windows codepage 54936).
'//
'// The best way to use c_g18030.dll is to use the Windows API
'// MultiByteToWideChar() and WideCharToMultiByte(), and pass 54936 as the codepage
'// number.  Internally, MultiByteToWideChar() and WideCharToMultiByte() call function
'// in c_g18030.dll using these exported functions.
'//
'// You can also use this header and load these functions dynamically from c_g18030.dll.
'// However, this is not recommended since MulitByteToWideChar() and WideCharToMultiByte()
'// are much easier to use and these exports may change between windows versions.
'//
'////////////////////////////////////////////////////////////////////////////


'////////////////////////////////////////////////////////////////////////////
'//
'//  NlsDllCodePageTranslation
'//    This routine is the main exported procedure for the functionality in
'//    c_g18030.dll.  It can be used to get code page information or do conversion
'//    depending on the value of dwFlags.
'//
'//    Parameters:
'//      CodePage     The value of the codepage.  The value should be 54936.  Otherwise,
'//                    0 will be returned and GetLastError() will return ERROR_INVALID_PARAMETER.
'//
'//      dwFlags        It can be one of these values
'//          NLS_CP_CPINFO    To return code page information in the buffer pointed by
'//                           lpCPInfo. lpMultiByteStr/cchMultiByte/lpWideCharStr/cchWideChar are not used.
'//
'//          NLS_CP_MBTOWC    Convert GB-18030 bytes to Unicode characters.
'//                           The source GB-18030 characters should be pointed by lpMultiByteStr, and cchMultiByte should
'//                           contains the byte count of the buffer.
'//                           The Unicode result will be stored in the buffer pointed by lpWideCharStr, and cchWideChar
'//                           should contain the character count of the Unicode buffer.
'//                           If lpWideCharStr or cchWideChar are zero, the expected character count of the Unicode result
'//                           will be returned, and no real conversion will be done.
'//                           lpCPInfo is not used in this case.
'//
'//          NLS_CP_WCTOMB    Convert Unicode characters to GB-18030 bytes.
'//                           The source Unicode string should be pointed by lpWideCharStr, and cchWideChar should
'//                           contians the character count of the buffer.
'//                           The GB-18030 result will be stored in the buffer pointed by lpMultiByteStr, and cchMultiByte
'//                           should contain the byte count of the GB-18030 buffer.
'//                           If lpMultiByteStr or cchMultiByte are zero, the byte count of the GB-18030 result
'//                           will be returned, and no real conversion will be done.
'//                           lpCPInfo is not used in this case.
'//
'//                      Additionally one of these values may also be passed by logically oring them together
'//          WC_ERR_INVALID_CHARS
'//                           Returns 0 and GetLastError returns ERROR_NO_UNICODE_TRANSLATION if illegal unicode characters are
'//                           encountered during NLS_CP_WCTOMB, instead of replacing them with ?
'//
'//          MB_ERR_INVALID_CHARS
'//                           Returns 0 and GetLastError returns ERROR_NO_UNICODE_TRANSLATION if illegal gb18030 code points
'//                           are encountered during NLS_CPMBTOWC conversion.  If this flag isn't set they would be replaced
'//                           by ? instead.
'//
'//        lpMultiByteStr    Pointed to a buffer which contains multi-byte GB-18030 characters.  This can be a source buffer
'//                          or target buffer, depending on the value of dwFlags.
'//
'//        cchMulitByte      The byte count of the multi-byte buffer.
'//
'//        lpWideCharStr     Pointed to a buffer which contains Unicode characters.  This can be a source buffer
'//                          or target buffer, depending on the value of dwFlags.
'//
'//        cchWideChar       The character count of the Unicode buffer.
'//
'//        lpCPInfo          A pointer which points to a structure of CPINFO.  CPINFO is defined in Platform SDK.
'//
'//    Returns:
'//        1 if the function succeeds.
'//        0 if the function fails
'//
'////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION NlsDllCodePageTranslation IMPORT "C_g18030.dll" ALIAS "NlsDllCodePageTranslation" ( _
   BYVAL CodePage AS DWORD _                            ' __in DWORD CodePage
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF lpMultiByteStr AS ASCIIZ _                     ' __inout LPSTR lpMultiByteStr
 , BYVAL cchMultiByte AS LONG _                         ' __in int cchMultiByte
 , BYREF lpWideCharStr AS WSTRINGZ _                    ' __inout LPWSTR lpWideCharStr
 , BYVAL cchWideChar AS LONG _                          ' __in int cchWideChar
 , BYREF lpCPInfo AS CPINFO _                           ' __in LPCPINFO lpCPInfo
 ) AS DWORD                                             ' DWORD

'////////////////////////////////////////////////////////////////////////////
'//
'//  BytesToUnicode
'//
'//  Deprecated, only available in Windows XP and Windows Server 2003.
'//
'////////////////////////////////////////////////////////////////////////////

'////////////////////////////////////////////////////////////////////////////
'//
'//  UnicodeToBytes
'//
'//  Deprecated, only available in Windows XP and Windows Server 2003.
'//
'////////////////////////////////////////////////////////////////////////////
