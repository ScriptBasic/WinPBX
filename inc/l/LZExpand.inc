' ########################################################################################
' Microsoft Windows
' File: LZExpand.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LZEXPAND_INC = 1

#INCLUDE ONCE "windows.inc"

'/*
'** Error Return Codes
'*/

%LZERROR_BADINHANDLE    = -1  ' /* invalid input handle */
%LZERROR_BADOUTHANDLE   = -2  ' /* invalid output handle */
%LZERROR_READ           = -3  ' /* corrupt compressed file format */
%LZERROR_WRITE          = -4  ' /* out of space for output file */
%LZERROR_GLOBALLOC      = -5  ' /* insufficient memory for LZFile struct */
%LZERROR_PUBLICLOC      = -5  ' /* insufficient memory for LZFile struct */
%LZERROR_GLOBLOCK       = -6  ' /* bad Global handle */
%LZERROR_BADVALUE       = -7  ' /* input parameter out of range */
%LZERROR_UNKNOWNALG     = -8  ' /* compression algorithm not recognized */


'/*
'** Prototypes
'*/

DECLARE FUNCTION LZStart IMPORT "LZ32.DLL" ALIAS "LZStart" ( _
 ) AS LONG                                              ' INT

DECLARE SUB LZDone IMPORT "LZ32.DLL" ALIAS "LZDone" ( _
 )                                                      ' VOID

DECLARE FUNCTION CopyLZFile IMPORT "LZ32.DLL" ALIAS "CopyLZFile" ( _
   BYVAL hfSource AS LONG _                             ' __in INT hfSource
 , BYVAL hfDest AS LONG _                               ' __in INT hfDest
 ) AS LONG                                              ' LONG

DECLARE FUNCTION LZCopy IMPORT "LZ32.DLL" ALIAS "LZCopy" ( _
   BYVAL hfSource AS LONG _                             ' __in INT hfSource
 , BYVAL hfDest AS LONG _                               ' __in INT hfDest
 ) AS LONG                                              ' LONG

DECLARE FUNCTION LZInit IMPORT "LZ32.DLL" ALIAS "LZInit" ( _
   BYVAL hfSource AS LONG _                             ' __in INT hfSource
 ) AS LONG                                              ' INT

DECLARE FUNCTION GetExpandedNameA IMPORT "LZ32.DLL" ALIAS "GetExpandedNameA" ( _
   BYREF lpszSource AS ASCIIZ _                         ' __in LPSTR lpszSource
 , BYREF lpszBuffer AS ASCIIZ _                         ' __out_ecount(MAX_PATH) LPSTR lpszBuffer
 ) AS LONG                                              ' INT

DECLARE FUNCTION GetExpandedNameW IMPORT "LZ32.DLL" ALIAS "GetExpandedNameW" ( _
   BYREF lpszSource AS WSTRINGZ _                       ' __in LPWSTR lpszSource
 , BYREF lpszBuffer AS WSTRINGZ _                       ' __out_ecount(MAX_PATH) LPWSTR lpszBuffer
 ) AS LONG                                              ' INT

#IF %DEF(%UNICODE)
   MACRO GetExpandedName = GetExpandedNameW
#ELSE
   MACRO GetExpandedName = GetExpandedNameA
#ENDIF

DECLARE FUNCTION LZOpenFileA IMPORT "LZ32.DLL" ALIAS "LZOpenFileA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in LPSTR lpFileName
 , BYREF lpReOpenBuf AS OFSTRUCT _                      ' __inout LPOFSTRUCT lpReOpenBuf
 , BYVAL wStyle AS WORD _                               ' __in WORD wStyle
 ) AS LONG                                              ' INT

DECLARE FUNCTION LZOpenFileW IMPORT "LZ32.DLL" ALIAS "LZOpenFileW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in LPWSTR lpFileName
 , BYREF lpReOpenBuf AS OFSTRUCT _                      ' __inout LPOFSTRUCT lpReOpenBuf
 , BYVAL wStyle AS WORD _                               ' __in WORD wStyle
 ) AS LONG                                              ' INT

#IF %DEF(%UNICODE)
   MACRO LZOpenFile = LZOpenFileW
#ELSE
   MACRO LZOpenFile = LZOpenFileA
#ENDIF

DECLARE FUNCTION LZSeek IMPORT "LZ32.DLL" ALIAS "LZSeek" ( _
   BYVAL hFile AS LONG _                                ' __in INT hFile
 , BYVAL lOffset AS LONG _                              ' __in LONG lOffset
 , BYVAL iOrigin AS LONG _                              ' __in INT iOrigin
 ) AS LONG                                              ' LONG

DECLARE FUNCTION LZRead IMPORT "LZ32.DLL" ALIAS "LZRead" ( _
   BYVAL hFile AS LONG _                                ' __in INT hFile
 , BYREF lpBuffer AS ASCIIZ _                           ' __out_bcount_part(cbRead, return) CHAR* lpBuffer
 , BYVAL cbRead AS LONG _                               ' __in INT cbRead
 ) AS LONG                                              ' INT

DECLARE SUB LZClose IMPORT "LZ32.DLL" ALIAS "LZClose" ( _
   BYVAL hFile AS LONG _                                ' __in INT hFile
 )                                                      ' VOID
