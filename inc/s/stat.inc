' ########################################################################################
' Microsoft Windows
' File: stat.inc
' Contents: This file defines the structure used by the _stat() and _fstat() routines
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%STAT_INC = 1

'#include <sys/types.h>
'typedef long time_t;
'typedef unsigned short _ino_t;          /* i-node number (not used on DOS) */
'typedef unsigned int _dev_t;            /* device code */
'typedef long _off_t;                    /* file offset value */
'typedef unsigned short wchar_t;

'/* define structure for returning status information */

#IF NOT %DEF(%STAT_DEFINED)
%STAT_DEFINED = 1

' // Size = 36 bytes
TYPE tag_stat DWORD FILL     ' _stat
   st_dev       AS DWORD     ' _dev_t
   st_ino       AS WORD      ' _ino_t
   st_mode      AS WORD      ' unsigned short
   st_nlink     AS INTEGER   ' short
   st_uid       AS INTEGER   ' short
   st_gid       AS INTEGER   ' short
   st_rdev      AS DWORD     ' _dev_t
   st_size      AS LONG      ' _off_t
   st_atime     AS LONG      ' time_t
   st_mtime     AS LONG      ' time_t
   st_ctime     AS LONG      ' time_t
END TYPE

'#IF %INTEGRAL_MAX_BITS >= 64
' // Size = 48 bytes
TYPE tag_stati64 QWORD FILL ' _stati64   - Must be 8 byte aligned
   st_dev      AS DWORD     ' _dev_t
   st_ino      AS WORD      ' _ino_t
   st_mode     AS WORD      ' unsigned short
   st_nlink    AS INTEGER   ' short
   st_uid      AS INTEGER   ' short
   st_gid      AS INTEGER   ' short
   st_rdev     AS DWORD     ' _dev_t
   st_size     AS QUAD      ' __int64
   st_atime    AS LONG      ' time_t
   st_mtime    AS LONG      ' time_t
   st_ctime    AS LONG      ' time_t
   alignment__ AS DWORD
END TYPE
'#ENDIF

#ENDIF


%S_IFMT       = 0170000         ' /* file type mask */
%S_IFDIR      = 0040000         ' /* directory */
%S_IFCHR      = 0020000         ' /* character special */
%S_IFIFO      = 0010000         ' /* pipe */
%S_IFREG      = 0100000         ' /* regular */
%S_IREAD      = 0000400         ' /* read permission, owner */
%S_IWRITE     = 0000200         ' /* write permission, owner */
%S_IEXEC      = 0000100         ' /* execute/search permission, owner */


'/* Function prototypes */

DECLARE FUNCTION fstat_ CDECL IMPORT "msvcrt.dll" ALIAS "_fstat" ( _
   BYVAL fd AS LONG _                                   ' fd
 , BYREF buffer AS tag_stat _                           ' struct _stat *buffer
 ) AS LONG                                              ' int

DECLARE FUNCTION stat_ CDECL IMPORT "msvcrt.dll" ALIAS "_stat" ( _
   BYREF path AS ASCIIZ _                               ' const char *path
 , BYREF buffer AS tag_stat _                           ' struct _stat *buffer
 ) AS LONG                                              ' int

'#if     _INTEGRAL_MAX_BITS >= 64
DECLARE FUNCTION fstati64_ CDECL IMPORT "msvcrt.dll" ALIAS "_fstati64" ( _
   BYVAL fd AS LONG _                                   ' fd
 , BYREF buffer AS tag_stati64 _                        ' struct _tag_stati64 *buffer
 ) AS LONG                                              ' int

DECLARE FUNCTION stati64_ CDECL IMPORT "msvcrt.dll" ALIAS "_stati64" ( _
   BYREF path AS ASCIIZ _                               ' const char *path
 , BYREF buffer AS tag_stati64 _                        ' struct _tag_stati64 *buffer
 ) AS LONG                                              ' int
'#endif

#IF NOT %DEF(%WSTAT_DEFINED)
%WSTAT_DEFINED = 1

'/* wide function prototypes, also declared in wchar.h  */

DECLARE FUNCTION wstat_ CDECL IMPORT "msvcrt.dll" ALIAS "_wstat" ( _
   BYREF path AS WSTRINGZ _                             ' const wchar_t *path
 , BYREF buffer AS tag_stat _                           ' struct _stat *buffer
 ) AS LONG                                              ' int

'#if     _INTEGRAL_MAX_BITS >= 64
DECLARE FUNCTION wstati64 CDECL IMPORT "msvcrt.dll" ALIAS "_wstati64" ( _
   BYREF path AS WSTRINGZ _                             ' const wchar_t *path
 , BYREF buffer AS tag_stati64 _                        ' struct _tag_stati64 *buffer
 ) AS LONG                                              ' int
'#endif

#ENDIF   ' #IF NOT %DEF(%WSTAT_DEFINED)
