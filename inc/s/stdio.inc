' ########################################################################################
' Microsoft C Runtime
' File: stdio.inc
' Contents: This file defines the structures, values, macros, and functions used by the
' level 2 I/O ("standard I/O") routines.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%STDIO_INC = 1

#INCLUDE ONCE "crtdefs.inc"

'/* Buffered I/O macros */

'#define BUFSIZ  512
%BUFSIZ = 512

'/*
' * Default number of supported streams. _NFILE is confusing and obsolete, but
' * supported anyway for backwards compatibility.
' */
'#define _NFILE      _NSTREAM_

'#define _NSTREAM_   512
%NSTREAM = 512
%NFILE = %NSTREAM

'/*
' * Number of entries in _iob[] (declared below). Note that _NSTREAM_ must be
' * greater than or equal to _IOB_ENTRIES.
' */
'#define _IOB_ENTRIES 20
%IOB_ENTRIES = 20

'#define EOF     (-1)
%EOF = -1

#IF NOT %DEF(%FILE_DEFINED)
%FILE_DEFINED = 1
' // Size = 32 bytes
TYPE FILE DWORD
   ptr      AS ASCIIZ PTR   ' char *_ptr
   cnt      AS LONG         ' int   _cnt
   base     AS ASCIIZ PTR   ' char *_base
   flag     AS LONG         ' int   _flag
   file     AS LONG         ' int   _file
   charbuf  AS LONG         ' int   _charbuf
   bufsiz   AS LONG         ' int   _bufsiz
   tmpfname AS ASCIIZ PTR   ' char *_tmpfname
END TYPE
MACRO iobuf = FILE
#ENDIF

'/* Seek method constants */

%SEEK_CUR     = 1
%SEEK_END     = 2
%SEEK_SET     = 0

'#define FILENAME_MAX    260
'#define FOPEN_MAX       20
'#define _SYS_OPEN       20
'#define TMP_MAX         32767  /* SHRT_MAX */
'#if __STDC_WANT_SECURE_LIB__
'#define TMP_MAX_S       _TMP_MAX_S
'#define _TMP_MAX_S      2147483647 /* INT_MAX */
'#endif

%FILENAME_MAX = 260
%FOPEN_MAX    = 20
%SYS_OPEN     = 20
%TMP_MAX      = 32767
%TMP_MAX_S    =  2147483647   ' /* INT_MAX */

'/* Declare _iob[] array */

'_CRTIMP extern FILE _iob[];
FUNCTION get_iob () AS DWORD
   LOCAL hLib AS DWORD
   LOCAL piob AS FILE PTR
   hLib = LoadLibrary($CRT_DLLNAME)
   IF hLib THEN
      piob = GetProcAddress(hLib, "_iob")
      FUNCTION = piob
      FreeLibrary hLib
   END IF
END FUNCTION

#IF NOT %DEF(%STDIO_DEFINED)
' ========================================================================================
'_CRTIMP FILE * __cdecl __iob_func(void);
' ========================================================================================
DECLARE FUNCTION get_iob_func__ CDECL IMPORT $CRT_DLLNAME ALIAS "__iob_func" ( _
 ) AS DWORD                                             ' FILE *
' ========================================================================================
#ENDIF  ' /* _STDIO_DEFINED */


'/* Define file position type */

'#if     !__STDC__
'/* At this point we could switch both to long long, but we won't do that till next version to avoid any potential compat issues */
'typedef __int64 fpos_t;
'#define _FPOSOFF(fp) ((long)(fp))
'#else
'typedef long long fpos_t;
'#define _FPOSOFF(fp) ((long)(fp))
'#endif
'#endif  /* _POSIX_ */

'#ifndef _STDSTREAM_DEFINED
'#define stdin  (&__iob_func()[0])
'#define stdout (&__iob_func()[1])
'#define stderr (&__iob_func()[2])
'#define _STDSTREAM_DEFINED
'#endif

%IOREAD         = &H0001&
%IOWRT          = &H0002&

%IOFBF          = &H0000&
%IOLBF          = &H0040&
%IONBF          = &H0004&

%IOMYBUF        = &H0008&
%IOEOF          = &H0010&
%IOERR          = &H0020&
%IOSTRG         = &H0040&
%IORW           = &H0080&

'/* constants used by _set_output_format */
%TWO_DIGIT_EXPONENT = &H1

'/* Function prototypes */

#IF NOT %DEF(%STDIO_DEFINED)
%STDIO_DEFINED = 1

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _filbuf(_Inout_ FILE * _File );
' ========================================================================================
DECLARE FUNCTION filbuf_ CDECL IMPORT $CRT_DLLNAME ALIAS "_filbuf" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl _flsbuf(_In_ int _Ch, _Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION flsbuf_ CDECL IMPORT $CRT_DLLNAME ALIAS "_flsbuf" ( _
   BYVAL c AS LONG _                                    ' __in int c
 , BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP FILE * __cdecl _fsopen(_In_z_ const char * _Filename,
' _In_z_ const char * _Mode, _In_ int _ShFlag);
' ========================================================================================
DECLARE FUNCTION fsopen_ CDECL IMPORT $CRT_DLLNAME ALIAS "_fsopen" ( _
   BYREF filename AS ASCIIZ _                           ' __in const char *filename
 , BYREF mode AS ASCIIZ _                               ' __in const char *mode
 , BYVAL shflag AS LONG _                               ' __in int shflag
 ) AS DWORD                                             ' FILE *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP void __cdecl clearerr(_Inout_ FILE * _File);
' ========================================================================================
DECLARE SUB clearerr CDECL IMPORT $CRT_DLLNAME ALIAS "clearerr" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 )                                                      ' void
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl clearerr_s(_Inout_ FILE * _File );
' ========================================================================================
DECLARE SUB clearerr_s CDECL IMPORT $CRT_DLLNAME ALIAS "clearerr_s" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 )                                                      ' void
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl fclose(_Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION fclose CDECL IMPORT $CRT_DLLNAME ALIAS "fclose" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl _fcloseall(void);
' ========================================================================================
DECLARE SUB fcloseall_ CDECL IMPORT $CRT_DLLNAME ALIAS "_fcloseall" ()
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP FILE * __cdecl _fdopen(_In_ int _FileHandle, _In_z_ const char * _Mode);
' ========================================================================================
DECLARE FUNCTION fdopen_ CDECL IMPORT $CRT_DLLNAME ALIAS "_fdopen" ( _
   BYVAL fd AS LONG _                                   ' __in int fd
 , BYREF mode AS ASCIIZ _                               ' __in const char *mode
 ) AS DWORD                                             ' FILE *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl feof(_In_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION feof CDECL IMPORT $CRT_DLLNAME ALIAS "feof" ( _
   BYVAL stream AS FILE PTR _                           ' __in FILE *stream
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl ferror(_In_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION ferror CDECL IMPORT $CRT_DLLNAME ALIAS "ferror" ( _
   BYVAL stream AS FILE PTR _                           ' __in FILE *stream
 ) AS LONG                                              ' int

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl fflush(_Inout_opt_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION fflush CDECL IMPORT $CRT_DLLNAME ALIAS "fflush" ( _
   BYVAL stream AS FILE PTR _                           ' inout_opt FILE *stream
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl fgetc(_Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION fgetc CDECL IMPORT $CRT_DLLNAME ALIAS "fgetc" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl _fgetchar(void);
' ========================================================================================
DECLARE FUNCTION fgetchar_ CDECL IMPORT $CRT_DLLNAME ALIAS "_fgetchar" ( _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl fgetpos(_Inout_ FILE * _File , _Out_ fpos_t * _Pos);
' ========================================================================================
DECLARE FUNCTION fgetpos CDECL IMPORT $CRT_DLLNAME ALIAS "fgetpos" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF pos AS QUAD _                                  ' __out fpos_t *pos
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP char * __cdecl fgets(_Out_z_cap_(_MaxCount) char * _Buf,
' _In_ int _MaxCount, _Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION fgets CDECL IMPORT $CRT_DLLNAME ALIAS "fgets" ( _
   BYREF string AS ASCIIZ _                             ' __out char *string
 , BYVAL n AS LONG _                                    ' __in int n
 , BYVAL stream AS FILE PTR _                           ' __in FILE *stream
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _fileno(_In_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION fileno_ CDECL IMPORT $CRT_DLLNAME ALIAS "_fileno" ( _
   BYVAL stream AS FILE PTR _                           ' __in FILE *stream
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP char * __cdecl _tempnam(_In_opt_z_ const char * _DirName,
' _In_opt_z_ const char * _FilePrefix);
' ========================================================================================
DECLARE FUNCTION tempnam_ CDECL IMPORT $CRT_DLLNAME ALIAS "_tempnam" ( _
   BYREF dir AS ASCIIZ _                                ' __in_opt const char *dir
 , BYREF prefix AS ASCIIZ _                             ' __in_opt const char *prefix
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl _flushall(void);
' ========================================================================================
DECLARE FUNCTION flushall_ CDECL IMPORT $CRT_DLLNAME ALIAS "_flushall" ( _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_INSECURE_DEPRECATE(fopen_s) _CRTIMP FILE * __cdecl fopen(
' _In_z_ const char * _Filename, _In_z_ const char * _Mode);
' ========================================================================================
DECLARE FUNCTION fopen CDECL IMPORT $CRT_DLLNAME ALIAS "fopen" ( _
   BYREF filename AS ASCIIZ _                           ' __in const char *filename
 , BYREF mode AS ASCIIZ _                               ' __in const char *mode
 ) AS DWORD                                             ' FILE *
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl fopen_s(_Deref_out_opt_ FILE ** _File,
' _In_z_ const char * _Filename, _In_z_ const char * _Mode);
' ========================================================================================
DECLARE FUNCTION fopen_s CDECL IMPORT $CRT_DLLNAME ALIAS "fopen_s" ( _
   BYREF pFile AS DWORD _                               ' __out_opt FILE** pFile
 , BYREF filename AS ASCIIZ _                           ' __in const char *filename
 , BYREF mode AS ASCIIZ _                               ' __in const char *mode
 ) AS LONG                                              ' errno_t
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl fprintf(_Inout_ FILE * _File,
' _In_z_ _Printf_format_string_ const char * _Format, ...);
' ========================================================================================
DECLARE FUNCTION fprintf CDECL IMPORT $CRT_DLLNAME ALIAS "fprintf" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl fprintf_s(_Inout_ FILE * _File,
' _In_z_ _Printf_format_string_ const char * _Format, ...);
' ========================================================================================
DECLARE FUNCTION fprintf_s CDECL IMPORT $CRT_DLLNAME ALIAS "fprintf_s" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl fputc(_In_ int _Ch, _Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION fputc CDECL IMPORT $CRT_DLLNAME ALIAS "fputc" ( _
   BYVAL c AS LONG _                                    ' __in int c
 , BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl _fputchar(_In_ int _Ch);
' ========================================================================================
DECLARE FUNCTION fputchar_ CDECL IMPORT $CRT_DLLNAME ALIAS "_fputchar" ( _
   BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl fputs(_In_z_ const char * _Str, _Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION fputs CDECL IMPORT $CRT_DLLNAME ALIAS "fputs" ( _
   BYREF string AS ASCIIZ _                             ' __in const char *string
 , BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP size_t __cdecl fread(_Out_bytecap_x_(_ElementSize*_Count) void * _DstBuf,
' _In_ size_t _ElementSize, _In_ size_t _Count, _Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION fread CDECL IMPORT $CRT_DLLNAME ALIAS "fread" ( _
   BYREF buffer AS ANY _                                ' __out void *buffer
 , BYVAL size AS DWORD _                                ' __in size_t size
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS DWORD                                             ' size_t
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_opt_ _CRTIMP size_t __cdecl fread_s(_Out_bytecap_x_(_ElementSize*_Count) void * _DstBuf,
' _In_ size_t _DstSize, _In_ size_t _ElementSize, _In_ size_t _Count, _Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION fread_s CDECL IMPORT $CRT_DLLNAME ALIAS "fread_s" ( _
   BYREF buffer AS ANY _                                ' void *buffer
 , BYVAL size AS DWORD _                                ' size_t size
 , BYVAL ElementSize AS DWORD _                         ' size_t _ElementSize
 , BYVAL count AS DWORD _                               ' size_t count
 , BYVAL stream AS FILE PTR _                           ' FILE *stream
 ) AS DWORD                                             ' size_t
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_INSECURE_DEPRECATE(freopen_s) _CRTIMP FILE * __cdecl freopen(
' _In_z_ const char * _Filename, _In_z_ const char * _Mode, _Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION freopen CDECL IMPORT $CRT_DLLNAME ALIAS "freopen" ( _
   BYREF path AS ASCIIZ _                               ' __in const char *path
 , BYREF mode AS ASCIIZ _                               ' __in const char* mode
 , BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS DWORD                                             ' FILE *
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl freopen_s(_Deref_out_opt_ FILE ** _File,
' _In_z_ const char * _Filename, _In_z_ const char * _Mode, _Inout_ FILE * _OldFile);
' ========================================================================================
DECLARE FUNCTION freopen_s CDECL IMPORT $CRT_DLLNAME ALIAS "freopen_s" ( _
   BYREF pFile AS DWORD _                               ' __out FILE** pFile
 , BYREF path AS ASCIIZ _                               ' __in const char *path
 , BYREF mode AS ASCIIZ _                               ' __in const char* mode
 , BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS LONG                                              ' errno_t
' ========================================================================================
'#endif

' ========================================================================================
' _Check_return_ _CRT_INSECURE_DEPRECATE(fscanf_s) _CRTIMP int __cdecl fscanf(
' _Inout_ FILE * _File, _In_z_ _Scanf_format_string_ const char * _Format, ...);
' ========================================================================================
DECLARE FUNCTION fscanf CDECL IMPORT $CRT_DLLNAME ALIAS "fscanf" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_fscanf_s_l) _CRTIMP int __cdecl _fscanf_l(
' _Inout_ FILE * _File, _In_z_ _Scanf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION fscanf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_fscanf_l" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl fscanf_s(_Inout_ FILE * _File, _In_z_ _Scanf_s_format_string_ const char * _Format, ...);
' ========================================================================================
DECLARE FUNCTION fscanf_s CDECL IMPORT $CRT_DLLNAME ALIAS "fscanf_s" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================
'#endif

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _fscanf_s_l(_Inout_ FILE * _File,
' _In_z_ _Scanf_s_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION fscanf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_fscanf_s_l" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl fsetpos(_Inout_ FILE * _File, _In_ const fpos_t * _Pos);
' ========================================================================================
DECLARE FUNCTION fsetpos CDECL IMPORT $CRT_DLLNAME ALIAS "fsetpos" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF pos AS QUAD _                                  ' __in const fpos_t *pos
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl fseek(_Inout_ FILE * _File, _In_ long _Offset, _In_ int _Origin);
' ========================================================================================
DECLARE FUNCTION fseek CDECL IMPORT $CRT_DLLNAME ALIAS "fseek" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYVAL offset AS LONG _                               ' __in long offset
 , BYVAL origin AS LONG _                               ' __in int origin
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP long __cdecl ftell(_Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION ftell CDECL IMPORT $CRT_DLLNAME ALIAS "ftell" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS LONG                                              ' long
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _fseeki64(_Inout_ FILE * _File, _In_ __int64 _Offset, _In_ int _Origin);
' ========================================================================================
DECLARE FUNCTION fseeki64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_fseeki64" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYVAL offset AS QUAD _                               ' __in __int6 offset
 , BYVAL origin AS LONG _                               ' __in int origin
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP __int64 __cdecl _ftelli64(_Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION ftelli64_ CDECL IMPORT $CRT_DLLNAME ALIAS "_ftelli64" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS QUAD                                              ' __int64
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP size_t __cdecl fwrite(_In_count_x_(_Size*_Count) const void * _Str,
' _In_ size_t _Size, _In_ size_t _Count, _Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION fwrite CDECL IMPORT $CRT_DLLNAME ALIAS "fwrite" ( _
   BYREF buffer AS ANY _                                ' __in const void *buffer
 , BYVAL size AS DWORD _                                ' _in size_t size
 , BYVAL count AS DWORD _                               ' _in size_t count
 , BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl getc(_Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION getc CDECL IMPORT $CRT_DLLNAME ALIAS "getc" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl getchar(void);
' ========================================================================================
DECLARE FUNCTION getchar CDECL IMPORT $CRT_DLLNAME ALIAS "getchar" ( _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _getmaxstdio(void);
' ========================================================================================
DECLARE FUNCTION getmaxstdio_ CDECL IMPORT $CRT_DLLNAME ALIAS "_getmaxstdio" ( _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION gets CDECL IMPORT $CRT_DLLNAME ALIAS "gets" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 ) AS DWORD                                             ' char *
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _CRTIMP char * __cdecl gets_s(_Out_z_cap_(_Size) char * _Buf, _In_ rsize_t _Size);
' ========================================================================================
DECLARE FUNCTION gets_s CDECL IMPORT $CRT_DLLNAME ALIAS "gets_s" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL sizeInCharacters AS DWORD _                    ' __in size_t sizeInCharacters
 ) AS DWORD                                             ' char *
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' _Check_return_ int __cdecl _getw(_Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION getw_ CDECL IMPORT $CRT_DLLNAME ALIAS "_getw" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS LONG                                              ' int
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
' _Check_return_opt_ _CRTIMP int __cdecl _pclose(_Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION pclose_ CDECL IMPORT $CRT_DLLNAME ALIAS "_pclose" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP FILE * __cdecl _popen(_In_z_ const char * _Command, _In_z_ const char * _Mode);
' ========================================================================================
DECLARE FUNCTION popen_ CDECL IMPORT $CRT_DLLNAME ALIAS "_popen" ( _
   BYREF command AS ASCIIZ _                            ' __IN const char *command
 , BYREF mode AS ASCIIZ _                               ' __in const char *mode
 ) AS DWORD                                             ' FILE *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl printf(_In_z_ _Printf_format_string_ const char * _Format, ...);
' ========================================================================================
DECLARE FUNCTION printf CDECL IMPORT $CRT_DLLNAME ALIAS "printf" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl printf_s(_In_z_ _Printf_format_string_ const char * _Format, ...);
' ========================================================================================
DECLARE FUNCTION printf_s CDECL IMPORT $CRT_DLLNAME ALIAS "printf_s" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl putc(_In_ int _Ch, _Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION putc CDECL IMPORT $CRT_DLLNAME ALIAS "putc" ( _
   BYVAL c AS LONG _                                    ' __in int c
 , BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl putchar(_In_ int _Ch);
' ========================================================================================
DECLARE FUNCTION putchar CDECL IMPORT $CRT_DLLNAME ALIAS "putchar" ( _
   BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl puts(_In_z_ const char * _Str);
' ========================================================================================
DECLARE FUNCTION puts CDECL IMPORT $CRT_DLLNAME ALIAS "puts" ( _
   BYREF string AS ASCIIZ _                             ' __in const char *string
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
DECLARE FUNCTION putw_ CDECL IMPORT "msvcrt.dll" ALIAS "_putw" ( _
   BYVAL binint AS LONG _                               ' __in int binint
 , BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _putw(_In_ int _Word, _Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION putw_ CDECL IMPORT $CRT_DLLNAME ALIAS "_putw" ( _
   BYVAL binint AS LONG _                               ' __in int binint
 , BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS LONG                                              ' int
' ========================================================================================

#IF NOT %DEF(%CRT_DIRECTORY_DEFINED)
    %CRT_DIRECTORY_DEFINED = 1

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl remove(_In_z_ const char * _Filename);
' ========================================================================================
DECLARE FUNCTION remove CDECL IMPORT $CRT_DLLNAME ALIAS "remove" ( _
   BYREF path AS ASCIIZ _                               ' __in const char *path
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl rename(_In_z_ const char * _OldFilename, _In_z_ const char * _NewFilename);
' ========================================================================================
DECLARE FUNCTION rename CDECL IMPORT $CRT_DLLNAME ALIAS "rename" ( _
   BYREF oldname AS ASCIIZ _                            ' __in const char *oldname
 , BYREF newname AS ASCIIZ _                            ' __in const char *newname
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _unlink(_In_z_ const char * _Filename);
' ========================================================================================
DECLARE FUNCTION unlink_ CDECL IMPORT $CRT_DLLNAME ALIAS " _unlink" (_
   BYREF filename AS ASCIIZ _                           ' __in const char *filename
 ) AS LONG                                              ' int
' ========================================================================================

#ENDIF   ' CRT_DIRECTORY_DEFINED

' ========================================================================================
' *** All versions ***
' _CRTIMP void __cdecl rewind(_Inout_ FILE * _File);
' ========================================================================================
DECLARE SUB rewind CDECL IMPORT $CRT_DLLNAME ALIAS "rewind" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl _rmtmp(void);
' ========================================================================================
DECLARE FUNCTION rmtmp_ CDECL IMPORT $CRT_DLLNAME ALIAS "_rmtmp" ( _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
DECLARE FUNCTION scanf CDECL IMPORT $CRT_DLLNAME ALIAS "scanf" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl scanf_s(_In_z_ _Scanf_s_format_string_ const char * _Format, ...);
' ========================================================================================
DECLARE FUNCTION scanf_s CDECL IMPORT $CRT_DLLNAME ALIAS "scanf_s" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================
'#endif

' ========================================================================================
' _Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _scanf_s_l(
' _In_z_ _Scanf_s_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION scanf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_scanf_s_l" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRT_INSECURE_DEPRECATE(setvbuf) _CRTIMP void __cdecl setbuf(_Inout_ FILE * _File,
' _Inout_opt_cap_c_(BUFSIZ) _Post_count_c_(0) char * _Buffer);
' ========================================================================================
DECLARE SUB setbuf CDECL IMPORT $CRT_DLLNAME ALIAS "setbuf" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF buffer AS ASCIIZ _                             ' __inout char *buffer
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl _setmaxstdio(_In_ int _Max);
' ========================================================================================
DECLARE FUNCTION setmaxstdio_ CDECL IMPORT $CRT_DLLNAME ALIAS "_setmaxstdio" ( _
   BYVAL newmax AS LONG _                               ' __in int newmax
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP unsigned int __cdecl _set_output_format(_In_ unsigned int _Format);
' ========================================================================================
DECLARE FUNCTION set_output_format CDECL IMPORT $CRT_DLLNAME ALIAS "_set_output_format" ( _
   BYVAL newmax AS LONG _                               ' int newmax
 ) AS DWORD                                             ' unsigned int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP unsigned int __cdecl _get_output_format(void);
' ========================================================================================
DECLARE FUNCTION get_output_format CDECL IMPORT $CRT_DLLNAME ALIAS "_get_output_format" ( _
 ) AS DWORD                                             ' unsigned int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl setvbuf(_Inout_ FILE * _File,
' _Inout_opt_z_bytecap_(_Size) char * _Buf, _In_ int _Mode, _In_ size_t _Size);
' ========================================================================================
DECLARE FUNCTION setvbuf CDECL IMPORT $CRT_DLLNAME ALIAS "setvbuf" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF buffer AS ASCIIZ _                             ' __inout char *buffer
 , BYVAL mode AS LONG _                                 ' __in int mode
 , BYVAL size AS DWORD _                                ' __in size_t size
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION snprintf_ CDECL IMPORT $CRT_DLLNAME ALIAS "_snprintf" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _snprintf_s(_Out_z_bytecap_(
' _SizeInBytes) char * _DstBuf, _In_ size_t _SizeInBytes, _In_ size_t _MaxCount,
'  _In_z_ _Printf_format_string_ const char * _Format, ...);
' ========================================================================================
DECLARE FUNCTION snprintf_s CDECL IMPORT $CRT_DLLNAME ALIAS "_snprintf_s" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL sizeOfBuffer AS DWORD _                        ' __in size_t sizeOfBuffer
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION sprintf CDECL IMPORT $CRT_DLLNAME ALIAS "sprintf" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl sprintf_s(_Out_z_bytecap_(
' _SizeInBytes) char * _DstBuf, _In_ size_t _SizeInBytes, _In_z_ _Printf_format_string_ const char * _Format, ...);
' ========================================================================================
DECLARE FUNCTION sprintf_s CDECL IMPORT $CRT_DLLNAME ALIAS "sprintf_s" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL sizeOfBuffer AS DWORD _                        ' __in size_t sizeOfBuffer
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================
'#endif

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _scprintf(_In_z_ _Printf_format_string_ const char * _Format, ...);
' ========================================================================================
DECLARE FUNCTION scprintf_ CDECL IMPORT $CRT_DLLNAME ALIAS "_scprintf" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION sscanf CDECL IMPORT $CRT_DLLNAME ALIAS "sscanf" ( _
   BYREF buffer AS ASCIIZ _                             ' __in const char *buffer
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
'_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl sscanf_s(_In_z_ const char * _Src,
' _In_z_ _Scanf_s_format_string_ const char * _Format, ...);
' ========================================================================================
DECLARE FUNCTION sscanf_s CDECL IMPORT $CRT_DLLNAME ALIAS "sscanf_s" ( _
   BYREF buffer AS ASCIIZ _                             ' __in const char *buffer
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================
'#endif

' ========================================================================================
' _Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _sscanf_s_l(_In_z_ const char * _Src,
' _In_z_ _Scanf_s_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION sscanf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_sscanf_s_l" ( _
   BYREF buffer AS ASCIIZ _                             ' __in const char *buffer
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_snscanf_s) _CRTIMP int __cdecl _snscanf(
' _In_bytecount_(_MaxCount) _Pre_z_ const char * _Src, _In_ size_t _MaxCount,
' _In_z_ _Scanf_format_string_ const char * _Format, ...);
' ========================================================================================
DECLARE FUNCTION snscanf_ CDECL IMPORT $CRT_DLLNAME ALIAS "_snscanf" ( _
   BYREF input AS ASCIIZ _                              ' in_ const char *input
 , BYVAL length AS DWORD _                              ' __in size_t length
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_snscanf_s_l) _CRTIMP int __cdecl _snscanf_l(
' _In_bytecount_(_MaxCount) _Pre_z_ const char * _Src, _In_ size_t _MaxCount,
' _In_z_ _Scanf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION snscanf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_snscanf_l" ( _
   BYREF input AS ASCIIZ _                              ' __in const char *input
 , BYVAL length AS DWORD _                              ' __in size_t length
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _snscanf_s(
' _In_bytecount_(_MaxCount) _Pre_z_ const char * _Src, _In_ size_t _MaxCount,
' _In_z_ _Scanf_s_format_string_ const char * _Format, ...);
' ========================================================================================
DECLARE FUNCTION snscanf_s CDECL IMPORT $CRT_DLLNAME ALIAS "_snscanf_s" ( _
   BYREF input AS ASCIIZ _                              ' __in const char *input
 , BYVAL length AS DWORD _                              ' __in size_t length
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _snscanf_s_l(
' _In_bytecount_(_MaxCount) _Pre_z_ const char * _Src, _In_ size_t _MaxCount,
' _In_z_ _Scanf_s_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION snscanf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_snscanf_s_l" ( _
   BYREF input AS ASCIIZ _                              ' __in const char *input
 , BYVAL length AS locale_t _                           ' __in size_t length
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_INSECURE_DEPRECATE(tmpfile_s) _CRTIMP FILE * __cdecl tmpfile(void);
' ========================================================================================
DECLARE FUNCTION tmpfile CDECL IMPORT $CRT_DLLNAME ALIAS "tmpfile" ( _
 ) AS DWORD                                             ' FILE *
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl tmpfile_s(_Out_opt_ _Deref_post_valid_ FILE ** _File);
' ========================================================================================
DECLARE FUNCTION tmpfile_s CDECL IMPORT $CRT_DLLNAME ALIAS "tmpfile_s" ( _
   BYREF pFilePtr AS DWORD _                            ' __out FILE** pFilePtr
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl tmpnam_s(_Out_z_cap_(_Size) char * _Buf, _In_ rsize_t _Size);
' ========================================================================================
DECLARE FUNCTION tmpnam_s CDECL IMPORT $CRT_DLLNAME ALIAS "tmpnam_s" ( _
   BYREF string AS ASCIIZ _                             ' __out char *string
 , BYVAL sizeInChars AS DWORD _                         ' __in size_t sizeInChars
 ) AS LONG                                              ' errno_t
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION tmpnam CDECL IMPORT $CRT_DLLNAME ALIAS "tmpnam" ( _
   BYREF string AS ASCIIZ _                             ' __in char *string
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl ungetc(_In_ int _Ch, _Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION ungetc CDECL IMPORT $CRT_DLLNAME ALIAS "ungetc" ( _
   BYVAL c AS LONG _                                    ' __in int c
 , BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl vfprintf(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vfprintf CDECL IMPORT $CRT_DLLNAME ALIAS "vfprintf" (_
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl vfprintf_s(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vfprintf_s CDECL IMPORT $CRT_DLLNAME ALIAS "vfprintf_s" (_
   BYVAL stream AS FILE PTR _                           ' FILE *stream
 , BYREF format AS ASCIIZ _                             ' const char *format
 , BYREF argptr AS ANY _                                ' va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl vprintf(_In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vprintf CDECL IMPORT $CRT_DLLNAME ALIAS "vprintf" (_
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl vprintf_s(_In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vprintf_s CDECL IMPORT $CRT_DLLNAME ALIAS "vprintf_s" (_
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================
'#endif

' ========================================================================================
DECLARE FUNCTION vsnprintf_ CDECL IMPORT "msvcrt.dll" ALIAS "_vsnprintf" (_
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
DECLARE FUNCTION vsnprintf_ CDECL IMPORT $CRT_DLLNAME ALIAS "_vsnprintf" (_
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _vsnprintf_s(
' _Out_z_cap_(_SizeInBytes) char * _DstBuf, _In_ size_t _SizeInBytes,
' _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vsnprintf_s CDECL IMPORT $CRT_DLLNAME ALIAS "_vsnprintf_s" (_
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL sizeOfBuffer AS DWORD _                        ' __in size_t sizeOfBuffer
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION vsprintf CDECL IMPORT $CRT_DLLNAME ALIAS "vsprintf" (_
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _CRTIMP_ALTERNATIVE int __cdecl vsprintf_s(_Out_z_cap_(_SizeInBytes) char * _DstBuf, _In_ size_t _SizeInBytes, _In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vsprintf_s CDECL IMPORT $CRT_DLLNAME ALIAS "vsprintf_s" (_
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================
'#endif

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _vscprintf(_In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vscprintf_ CDECL IMPORT $CRT_DLLNAME ALIAS "_vscprintf" (_
   BYREF buffer AS ASCIIZ _                             ' __in char *buffer
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _snprintf_c(_Out_cap_(_MaxCount) char * _DstBuf, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const char * _Format, ...);
' ========================================================================================
DECLARE FUNCTION snprintf_c CDECL IMPORT $CRT_DLLNAME ALIAS "_snprintf_c" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char * buffer
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vsnprintf_c(_Out_cap_(_MaxCount) char *_DstBuf, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vsnprintf_c CDECL IMPORT $CRT_DLLNAME ALIAS "_vsnprintf_c" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char * buffer
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _fprintf_p(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const char * _Format, ...);
' ========================================================================================
DECLARE FUNCTION fprintf_p CDECL IMPORT $CRT_DLLNAME ALIAS "_fprintf_p" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _printf_p(_In_z_ _Printf_format_string_ const char * _Format, ...);
' ========================================================================================
DECLARE FUNCTION printf_p CDECL IMPORT $CRT_DLLNAME ALIAS "_printf_p" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _sprintf_p(_Out_z_cap_(_MaxCount) char * _Dst, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const char * _Format, ...);
' ========================================================================================
DECLARE FUNCTION sprintf_p CDECL IMPORT $CRT_DLLNAME ALIAS "_sprintf_p" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL SizeOfBuffer AS DWORD _                        ' __in size_t sizeOfBuffer
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vfprintf_p(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vfprintf_p CDECL IMPORT $CRT_DLLNAME ALIAS "_vfprintf_p" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vprintf_p(_In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vprintf_p CDECL IMPORT $CRT_DLLNAME ALIAS "_vprintf_p" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vsprintf_p(_Out_z_cap_(_MaxCount) char * _Dst, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vsprintf_p CDECL IMPORT $CRT_DLLNAME ALIAS "_vsprintf_p" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _scprintf_p(_In_z_ _Printf_format_string_ const char * _Format, ...);
' ========================================================================================
DECLARE FUNCTION scprintf_p CDECL IMPORT $CRT_DLLNAME ALIAS "_scprintf_p" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _vscprintf_p(_In_z_ _Printf_format_string_ const char * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vscprintf_p CDECL IMPORT $CRT_DLLNAME ALIAS "_vscprintf_p" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP int __cdecl _set_printf_count_output(_In_ int _Value);
' ========================================================================================
DECLARE FUNCTION set_printf_count_output CDECL IMPORT $CRT_DLLNAME ALIAS "_set_printf_count_output" ( _
   BYVAL enable AS LONG _                               ' __in int enable
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
'_CRTIMP int __cdecl _get_printf_count_output();
' ========================================================================================
DECLARE FUNCTION get_printf_count_output CDECL IMPORT $CRT_DLLNAME ALIAS "_get_printf_count_output" ( _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _printf_l(_In_z_ _Printf_format_string_ const char * _Format,
' _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION printf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_printf_l" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _printf_p_l(_In_z_ _Printf_format_string_ const char * _Format,
' _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION printf_p_l CDECL IMPORT $CRT_DLLNAME ALIAS "_printf_p_l" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _printf_s_l(_In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION printf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_printf_s_l" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt_locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vprintf_l(_In_z_ _Printf_format_string_ const char * _Format,
' _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vprintf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vprintf_l" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vprintf_p_l(_In_z_ _Printf_format_string_ const char * _Format,
' _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vprintf_p_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vprintf_p_l" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL  BYVAL locale AS locale_t _                 ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vprintf_s_l(_In_z_ _Printf_format_string_ const char * _Format,
' _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vprintf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vprintf_s_l" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _fprintf_l(_Inout_ FILE * _File,
' _In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION fprintf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_fprintf_l" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _fprintf_p_l(_Inout_ FILE * _File,
' _In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION fprintf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_fprintf_l" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _fprintf_s_l(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION fprintf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_fprintf_s_l" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL  BYVAL locale AS locale_t _                 ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vfprintf_l(_Inout_ FILE * _File,
' _In_z_ const char * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vfprintf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vfprintf_l" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vfprintf_p_l(_Inout_ FILE * _File,
' _In_z_ const char * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vfprintf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vfprintf_l" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vfprintf_s_l(_Inout_ FILE * _File,
' _In_z_ const char * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vfprintf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vfprintf_s_l" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_sprintf_s_l) _CRTIMP int __cdecl _sprintf_l(
' _Pre_notnull_ _Post_z_ char * _DstBuf, _In_z_ _Printf_format_string_ const char * _Format,
' _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION sprintf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_sprintf_l" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _sprintf_p_l(_Out_z_cap_(_MaxCount) char * _DstBuf,
' _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const char * _Format,
' _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION sprintf_p_l CDECL IMPORT $CRT_DLLNAME ALIAS "_sprintf_p_l" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL sizeOfBuffer AS DWORD _                        ' __in size_t sizeOfBuffer
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _sprintf_s_l(_Out_z_bytecap_(_DstSize) char * _DstBuf,
' _In_ size_t _DstSize, _In_z_ _Printf_format_string_ const char * _Format,
' _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION sprintf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_sprintf_s_l" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL sizeOfBuffer AS DWORD _                        ' __in size_t sizeOfBuffer
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_vsprintf_s_l) _CRTIMP int __cdecl _vsprintf_l(
' _Pre_notnull_ _Post_z_ char * _DstBuf, _In_z_ const char * _Format,
' _In_opt_ _locale_t, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vsprintf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vsprintf_l" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_oppt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vsprintf_p_l(_Out_z_cap_(_MaxCount) char * _DstBuf,
' _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const char* _Format,
' _In_opt_ _locale_t _Locale,  va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vsprintf_p_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vsprintf_p_l" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _vsprintf_s_l(_Out_z_cap_(_DstSize) char * _DstBuf,
' _In_ size_t _DstSize, _In_z_ _Printf_format_string_ const char * _Format,
' _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vsprintf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vsprintf_s_l" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _scprintf_l(
' _In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION scprintf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_scprintf_l" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _scprintf_p_l(
' _In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION scprintf_p_l CDECL IMPORT $CRT_DLLNAME ALIAS "_scprintf_p_l" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vscprintf_l(
' _In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vscprintf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vscprintf_l" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vscprintf_p_l(
' _In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vscprintf_p_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vscprintf_p_l" ( _
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_snprintf_s_l) _CRTIMP int __cdecl _snprintf_l(
' _Out_cap_(_MaxCount) char * _DstBuf, _In_ size_t _MaxCount,
' _In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION snprintf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_snprintf_l" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _snprintf_c_l(
' _Out_cap_(_MaxCount) char * _DstBuf, _In_ size_t _MaxCount,
' _In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION snprintf_c_l CDECL IMPORT $CRT_DLLNAME ALIAS "_snprintf_c_l" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _snprintf_s_l(
' _Out_z_cap_(_DstSize) char * _DstBuf, _In_ size_t _DstSize, _In_ size_t _MaxCount,
'  _In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION snprintf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_snprintf_s_l" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL sizeOfBuffer AS DWORD _                        ' __in size_t sizeOfBuffer
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_vsnprintf_s_l) _CRTIMP int __cdecl _vsnprintf_l(
' _Out_cap_(_MaxCount) char * _DstBuf, _In_ size_t _MaxCount,
' _In_z_ _Printf_format_string_ const char * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vsnprintf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vsnprintf_s_l" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL sizeOfBuffer AS DWORD _                        ' __in size_t sizeOfBuffer
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vsnprintf_c_l(_Out_cap_(_MaxCount) char * _DstBuf,
' _In_ size_t _MaxCount, const char *, _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vsnprintf_c_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vsnprintf_c_l" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vsnprintf_s_l(_Out_z_cap_(_DstSize) char * _DstBuf,
' _In_ size_t _DstSize, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const char* _Format,
' _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vsnprintf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vsnprintf_s_l" ( _
   BYREF buffer AS ASCIIZ _                             ' __out char *buffer
 , BYVAL sizeOfBuffer AS DWORD _                        ' __in size_t sizeOfBuffer
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

#IF NOT %DEF(%WSTDIO_DEFINED)
%WSTDIO_DEFINED = 1

'/* wide function prototypes, also declared in wchar.h  */

#IF NOT %DEF(%WEOF)
%WEOF = &HFFFF??
#ENDIF

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP FILE * __cdecl _wfsopen(_In_z_ const wchar_t * _Filename, _In_z_ const wchar_t * _Mode, _In_ int _ShFlag);
' ========================================================================================
DECLARE FUNCTION wfsopen_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wfsopen" (_
   BYREF filename AS WSTRINGZ _                         ' __in const wchar_t *filename
 , BYREF mode AS WSTRINGZ _                             ' __in const wchar_t *mode
 , BYVAL shflag AS LONG _                               ' __in int shflag
 ) AS DWORD                                             ' FILE *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP wint_t __cdecl fgetwc(_Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION fgetwc CDECL IMPORT $CRT_DLLNAME ALIAS "fgetwc" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS WORD                                              ' wint_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP wint_t __cdecl _fgetwchar(void);
' ========================================================================================
DECLARE FUNCTION fgetwchar_ CDECL IMPORT $CRT_DLLNAME ALIAS "_fgetwchar" ( _
 ) AS WORD                                              ' wint_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP wint_t __cdecl fputwc(_In_ wchar_t _Ch, _Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION fputwc CDECL IMPORT $CRT_DLLNAME ALIAS "fputwc" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 , BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS WORD                                              ' wint_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP wint_t __cdecl _fputwchar(_In_ wchar_t _Ch);
' ========================================================================================
DECLARE FUNCTION fputwchar_ CDECL IMPORT $CRT_DLLNAME ALIAS "_fputwchar" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 ) AS WORD                                              ' wint_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP wint_t __cdecl getwc(_Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION getwc CDECL IMPORT $CRT_DLLNAME ALIAS "getwc" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS WORD                                              ' wint_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP wint_t __cdecl getwchar(void);
' ========================================================================================
DECLARE FUNCTION getwchar CDECL IMPORT $CRT_DLLNAME ALIAS "getwchar" ( _
 ) AS WORD                                              ' wint_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP wint_t __cdecl putwc(_In_ wchar_t _Ch, _Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION putwc CDECL IMPORT $CRT_DLLNAME ALIAS "putwc" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 , BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS WORD                                              ' wint_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP wint_t __cdecl putwchar(_In_ wchar_t _Ch);
' ========================================================================================
DECLARE FUNCTION putwchar CDECL IMPORT $CRT_DLLNAME ALIAS "putwchar" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 ) AS WORD                                              ' wint_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP wint_t __cdecl ungetwc(_In_ wint_t _Ch, _Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION ungetwc CDECL IMPORT $CRT_DLLNAME ALIAS "ungetwc" ( _
   BYVAL c AS WORD _                                    ' __in wint_t c
 , BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS WORD                                              ' wint_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP wchar_t * __cdecl fgetws(_Out_z_cap_(_SizeInWords) wchar_t * _Dst,
' _In_ int _SizeInWords, _Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION fgetws CDECL IMPORT $CRT_DLLNAME ALIAS "fgetws" ( _
   BYREF string AS WSTRINGZ _                           ' __out wchar_t *string
 , BYVAL n AS LONG _                                    ' __in int n
 , BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl fputws(_In_z_ const wchar_t * _Str, _Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION fputws CDECL IMPORT $CRT_DLLNAME ALIAS "fputws" ( _
   BYREF string AS WSTRINGZ _                           ' __in const wchar_t *string
 , BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION getws_ CDECL IMPORT $CRT_DLLNAME ALIAS "_getws" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP wchar_t * __cdecl _getws_s(_Out_z_cap_(_SizeInWords) wchar_t * _Str,
' _In_ size_t _SizeInWords);
' ========================================================================================
DECLARE FUNCTION getws_s CDECL IMPORT $CRT_DLLNAME ALIAS "_getws_s" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL sizeInCharacters AS DWORD _                    ' size_t sizeInCharacters
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl _putws(_In_z_ const wchar_t * _Str);
' ========================================================================================
DECLARE FUNCTION putws_ CDECL IMPORT $CRT_DLLNAME ALIAS "_putws" ( _
   BYREF string AS WSTRINGZ _                           ' __in const wchar_t *string
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl fwprintf(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION fwprintf CDECL IMPORT $CRT_DLLNAME ALIAS "fwprintf" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl fwprintf_s(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION fwprintf_s CDECL IMPORT $CRT_DLLNAME ALIAS "fwprintf_s" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl wprintf(_In_z_ _Printf_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION wprintf CDECL IMPORT $CRT_DLLNAME ALIAS "wprintf" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl wprintf_s(_In_z_ _Printf_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION wprintf_s CDECL IMPORT $CRT_DLLNAME ALIAS "wprintf_s" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================
'#endif

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _scwprintf(_In_z_ _Printf_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION scwprintf CDECL IMPORT $CRT_DLLNAME ALIAS "_scwprintf" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl vfwprintf(_Inout_ FILE * _File,
' _In_z_ _Printf_format_string_ const wchar_t * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vfwprintf CDECL IMPORT $CRT_DLLNAME ALIAS "vfwprintf" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl vfwprintf_s(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const wchar_t * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vfwprintf_s CDECL IMPORT $CRT_DLLNAME ALIAS "vfwprintf_s" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' _Check_return_opt_ _CRTIMP int __cdecl vwprintf(_In_z_ _Printf_format_string_ const wchar_t * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vwprintf CDECL IMPORT $CRT_DLLNAME ALIAS "vwprintf" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl vwprintf_s(_In_z_ _Printf_format_string_ const wchar_t * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vwprintf_s CDECL IMPORT $CRT_DLLNAME ALIAS "vwprintf_s" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION swprintf CDECL IMPORT $CRT_DLLNAME ALIAS "swprintf" ( _
   BYREF buffer AS WSTRINGZ _                           ' wchar_t *buffer
 , BYREF format AS WSTRINGZ _                           ' const wchar_t *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _CRTIMP_ALTERNATIVE int __cdecl swprintf_s(_Out_z_cap_(_SizeInWords) wchar_t * _Dst,
' _In_ size_t _SizeInWords, _In_z_ _Printf_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION swprintf_s CDECL IMPORT $CRT_DLLNAME ALIAS "swprintf_s" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL sizeOfBuffer AS DWORD _                        ' __in size_t sizeOfBuffer
 , BYREF format AS WSTRINGZ _                           ' __in const echar_t *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION vswprintf CDECL IMPORT $CRT_DLLNAME ALIAS "vswprintf" (_
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _CRTIMP_ALTERNATIVE int __cdecl vswprintf_s(_Out_z_cap_(_SizeInWords) wchar_t * _Dst,
' _In_ size_t _SizeInWords, _In_z_ _Printf_format_string_ const wchar_t * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vswprintf_s CDECL IMPORT $CRT_DLLNAME ALIAS "vswprintf_s" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================
'#endif

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _swprintf_c(_Out_z_cap_(_SizeInWords) wchar_t * _DstBuf,
' _In_ size_t _SizeInWords, _In_z_ _Printf_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION swprintf_c CDECL IMPORT $CRT_DLLNAME ALIAS "_swprintf_c" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out const wchar_t *buffer
 , BYVAL SizeInWords AS DWORD _                         ' __in size_t _SizeInWords
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vswprintf_c(_Out_z_cap_(_SizeInWords) wchar_t * _DstBuf, _In_ size_t _SizeInWords, _In_z_ _Printf_format_string_ const wchar_t * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vswprintf_c CDECL IMPORT $CRT_DLLNAME ALIAS "_vswprintf_c" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out const wchar_t *buffer
 , BYVAL SizeInWords AS DWORD _                         ' __in size_t _SizeInWords
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION snwprintf_ CDECL IMPORT $CRT_DLLNAME ALIAS "_snwprintf" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS WSTRINGZ _                           ' __in wchar_t char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _snwprintf_s(_Out_z_cap_(_SizeInWords) wchar_t * _DstBuf, _In_ size_t _SizeInWords, _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION snwprintf_s CDECL IMPORT $CRT_DLLNAME ALIAS "_snwprintf_s" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL SizeOfBuffer AS DWORD _                        ' __in size_t SizeOfBuffer
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS WSTRINGZ _                           ' __in wchar_t char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION vsnwprintf_ CDECL IMPORT $CRT_DLLNAME ALIAS "_vsnwprintf" (_
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _vsnwprintf_s(
' _Out_z_cap_(_SizeInWords) wchar_t * _DstBuf, _In_ size_t _SizeInWords,
' _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const wchar_t * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vsnwprintf_s CDECL IMPORT $CRT_DLLNAME ALIAS "_vsnwprintf_s" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL SizeOfBuffer AS DWORD _                        ' __in size_t SizeOfBuffer
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS WSTRINGZ _                           ' __in wchar_t wchar_t *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION vfwprintf CDECL IMPORT $CRT_DLLNAME ALIAS "vfwprintf" (_
   BYVAL stream AS FILE PTR  _                          ' __inout FILE *stream
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _fwprintf_p(_Inout_ FILE * _File, _In_z_ _Printf_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION fwprintf_p CDECL IMPORT $CRT_DLLNAME ALIAS "_fwprintf_p" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _wprintf_p(_In_z_ _Printf_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION wprintf_p CDECL IMPORT $CRT_DLLNAME ALIAS "_wprintf_p" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vfwprintf_p(_Inout_ FILE * _File,
' _In_z_ _Printf_format_string_ const wchar_t * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vfwprintf_p CDECL IMPORT $CRT_DLLNAME ALIAS "_vfwprintf_p" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vwprintf_p(_In_z_ _Printf_format_string_ const wchar_t * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vwprintf_p CDECL IMPORT $CRT_DLLNAME ALIAS "_vwprintf_p" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _swprintf_p(_Out_z_cap_(_MaxCount) wchar_t * _DstBuf,
' _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION swprintf_p CDECL IMPORT $CRT_DLLNAME ALIAS "_swprintf_p" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL SizeOfBuffer AS DWORD _                        ' __in size_t sizeOfBuffer
 , BYREF format AS WSTRINGZ _                           ' __in const char *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vswprintf_p(_Out_z_cap_(_MaxCount) wchar_t * _DstBuf,
' _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const wchar_t * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vswprintf_p CDECL IMPORT $CRT_DLLNAME ALIAS "_vswprintf_p" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out char *buffer
 , BYVAL sizeInBytes AS DWORD _                         ' __in size_t sizeInBytes
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _scwprintf_p(_In_z_ _Printf_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION scwprintf_p CDECL IMPORT $CRT_DLLNAME ALIAS "_scwprintf_p" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _vscwprintf_p(_In_z_ _Printf_format_string_ const wchar_t * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vscwprintf_p CDECL IMPORT $CRT_DLLNAME ALIAS "_vscwprintf_p" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _wprintf_l(_In_z_ _Printf_format_string_ const wchar_t * _Format,
' _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION wprintf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wprintf_l" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _wprintf_p_l(_In_z_ _Printf_format_string_ const wchar_t * _Format,
' _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION wprintf_p_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wprintf_p_l" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _wprintf_s_l(_In_z_ _Printf_format_string_ const wchar_t * _Format,
' _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION wprintf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wprintf_s_l" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vwprintf_l(_In_z_ _Printf_format_string_ const wchar_t * _Format,
' _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vwprintf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vwprintf_l" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vwprintf_p_l(_In_z_ _Printf_format_string_ const wchar_t * _Format,
' _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vwprintf_p_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vwprintf_p_l" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vwprintf_s_l(
' _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vwprintf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vwprintf_s_l" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _fwprintf_l(_Inout_ FILE * _File,
' _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION fwprintf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_fwprintf_l" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _fwprintf_p_l(_Inout_ FILE * _File,
' _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION fwprintf_p_l CDECL IMPORT $CRT_DLLNAME ALIAS "_fwprintf_p_l" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _fwprintf_s_l(_Inout_ FILE * _File,
' _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION fwprintf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_fwprintf_s_l" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vfwprintf_l(_Inout_ FILE * _File,
' _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vfwprintf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vfwprintf_l" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vfwprintf_p_l(_Inout_ FILE * _File,
' _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vfwprintf_p_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vfwprintf_p_l" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vfwprintf_s_l(_Inout_ FILE * _File,
' _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vfwprintf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vfwprintf_s_l" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _swprintf_c_l(_Out_z_cap_(_MaxCount) wchar_t * _DstBuf,
' _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION swprintf_c_l CDECL IMPORT $CRT_DLLNAME ALIAS "_swprintf_c_l" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _swprintf_p_l(_Out_z_cap_(_MaxCount) wchar_t * _DstBuf,
' _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION swprintf_p_l CDECL IMPORT $CRT_DLLNAME ALIAS "_swprintf_p_l" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _swprintf_s_l(
' _Out_z_cap_(_DstSize) wchar_t * _DstBuf, _In_ size_t _DstSize, _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION swprintf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_swprintf_s_l" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL size AS DWORD _                                ' __in size_t size
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vswprintf_c_l(
' _Out_z_cap_(_MaxCount) wchar_t * _DstBuf, _In_ size_t _MaxCount,
' _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vswprintf_c_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vswprintf_c_l" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _vswprintf_p_l(_Out_z_cap_(_MaxCount) wchar_t * _DstBuf,
' _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vswprintf_p_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vswprintf_p_l" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _vswprintf_s_l(
'_Out_z_cap_(_DstSize) wchar_t * _DstBuf, _In_ size_t _DstSize,
' _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vswprintf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vswprintf_s_l" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL size AS DWORD _                                ' __in size_t size
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _scwprintf_l(_In_z_ _Printf_format_string_ const wchar_t * _Format,
' _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION scwprintf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_scwprintf_l" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _scwprintf_p_l(_In_z_ _Printf_format_string_ const wchar_t * _Format,
' _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION scwprintf_p_l CDECL IMPORT $CRT_DLLNAME ALIAS "_scwprintf_p_l" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _vscwprintf_p_l(_In_z_ _Printf_format_string_ const wchar_t * _Format,
' _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vscwprintf_p_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vscwprintf_p_l" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_snwprintf_s_l) _CRTIMP int __cdecl _snwprintf_l(
' _Out_cap_(_MaxCount) wchar_t * _DstBuf, _In_ size_t _MaxCount,
' _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION snwprintf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_snwprintf_l" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _snwprintf_s_l(
' _Out_z_cap_(_DstSize) wchar_t * _DstBuf, _In_ size_t _DstSize,
' _In_ size_t _MaxCount, _In_z_ _Printf_format_string_ const wchar_t * _Format,
' _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION snwprintf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_snwprintf_s_l" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL size AS DWORD _                                ' __in size_t size
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_vsnwprintf_s_l) _CRTIMP int __cdecl _vsnwprintf_l(
' _Out_cap_(_MaxCount) wchar_t * _DstBuf, _In_ size_t _MaxCount,
' _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vsnwprintf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vsnwprintf_l" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _vsnwprintf_s_l(
' _Out_z_cap_(_DstSize) wchar_t * _DstBuf, _In_ size_t _DstSize, _In_ size_t _MaxCount,
' _In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vsnwprintf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vsnwprintf_s_l" ( _
   BYREF buffer AS WSTRINGZ _                           ' __out wchar_t *buffer
 , BYVAL size AS DWORD _                                ' __in size_t size
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP wchar_t * __cdecl _wtempnam(_In_opt_z_ const wchar_t * _Directory, _In_opt_z_ const wchar_t * _FilePrefix);
' ========================================================================================
DECLARE FUNCTION wtempnam_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wtempnam" ( _
   BYREF dir AS WSTRINGZ _                              ' __in const wchar_t *dir
 , BYREF prefix AS WSTRINGZ _                           ' __in const wchar_t *prefix
 ) AS DWORD                                             ' char *
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _vscwprintf(_In_z_ _Printf_format_string_ const wchar_t * _Format, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vscwprintf CDECL IMPORT $CRT_DLLNAME ALIAS "_vscwprintf" (_
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , BYREF argptr AS ANY _                                ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP int __cdecl _vscwprintf_l(_In_z_ _Printf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, va_list _ArgList);
' ========================================================================================
DECLARE FUNCTION vscwprintf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_vscwprintf_l" (_
   BYREF format AS ASCIIZ _                             ' __in const char *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL BYREF argptr AS ANY _                       ' __in va_list argptr
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_INSECURE_DEPRECATE(fwscanf_s) _CRTIMP int __cdecl fwscanf(
' _Inout_ FILE * _File, _In_z_ _Scanf_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION fwscanf CDECL IMPORT $CRT_DLLNAME ALIAS "fwscanf" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_fwscanf_s_l) _CRTIMP int __cdecl _fwscanf_l(
' _Inout_ FILE * _File, _In_z_ _Scanf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION fwscanf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_fwscanf_s_l" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl fwscanf_s(_Inout_ FILE * _File,
' _In_z_ _Scanf_s_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION fwscanf_s CDECL IMPORT $CRT_DLLNAME ALIAS "fwscanf_s" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================
'#endif

' ========================================================================================
' _Check_return_opt_ _CRTIMP int __cdecl _fwscanf_s_l(_Inout_ FILE * _File,
' _In_z_ _Scanf_s_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION fwscanf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_fwscanf_s_l" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_INSECURE_DEPRECATE(swscanf_s) _CRTIMP int __cdecl swscanf(
' _In_z_ const wchar_t * _Src, _In_z_ _Scanf_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION swscanf CDECL IMPORT $CRT_DLLNAME ALIAS "swscanf" ( _
   BYREF str AS WSTRINGZ _                              ' __in const wchar_t *str
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
'_Check_return_opt_ _CRT_INSECURE_DEPRECATE(_swscanf_s_l) _CRTIMP int __cdecl _swscanf_l(
' _In_z_ const wchar_t * _Src, _In_z_ _Scanf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION swscanf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_swscanf_l" ( _
   BYREF str AS WSTRINGZ _                              ' __in const wchar_t *str
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl swscanf_s(_In_z_ const wchar_t *_Src,
' _In_z_ _Scanf_s_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION swscanf_s CDECL IMPORT $CRT_DLLNAME ALIAS "swscanf_s" ( _
   BYREF str AS WSTRINGZ _                              ' __in const wchar_t *str
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================
'#endif

' ========================================================================================
' _Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _swscanf_s_l(_In_z_ const wchar_t * _Src,
' _In_z_ _Scanf_s_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION swscanf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_swscanf_s_l" ( _
   BYREF str AS WSTRINGZ _                              ' __in const wchar_t *str
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_snwscanf_s) _CRTIMP int __cdecl _snwscanf(
' _In_count_(_MaxCount) _Pre_z_ const wchar_t * _Src, _In_ size_t _MaxCount,
' _In_z_ _Scanf_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION snwscanf CDECL IMPORT $CRT_DLLNAME ALIAS "_snwscanf" ( _
   BYREF str AS WSTRINGZ _                              ' __in const wchar_t *str
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_snwscanf_s_l) _CRTIMP int __cdecl _snwscanf_l(
' _In_count_(_MaxCount) _Pre_z_ const wchar_t * _Src, _In_ size_t _MaxCount,
' _In_z_ _Scanf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION snwscanf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_snwscanf_l" ( _
   BYREF str AS WSTRINGZ _                              ' __in const wchar_t *str
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _snwscanf_s(
' _In_count_(_MaxCount) _Pre_z_ const wchar_t * _Src, _In_ size_t _MaxCount,
' _In_z_ _Scanf_s_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION snwscanf_s CDECL IMPORT $CRT_DLLNAME ALIAS "_snwscanf_s" ( _
   BYREF str AS WSTRINGZ _                              ' __in const wchar_t *str
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _snwscanf_s_l(
' _In_count_(_MaxCount) _Pre_z_ const wchar_t * _Src, _In_ size_t _MaxCount,
' _In_z_ _Scanf_s_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION snwscanf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_snwscanf_s_l" ( _
   BYREF str AS WSTRINGZ _                              ' __in const wchar_t *str
 , BYVAL count AS DWORD _                               ' __in size_t count
 , BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_INSECURE_DEPRECATE(wscanf_s) _CRTIMP int __cdecl wscanf(
' _In_z_ _Scanf_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION wscanf CDECL IMPORT $CRT_DLLNAME ALIAS "wscanf" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYREF ANY _                                 ' __in_opt optional arguments
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_wscanf_s_l) _CRTIMP int __cdecl _wscanf_l(
' _In_z_ _Scanf_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION wscanf_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wscanf_l" ( _
   BYREF format AS WSTRINGZ _                           '__in  const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  '__in_opt  _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
'_Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl wscanf_s(
' _In_z_ _Scanf_s_format_string_ const wchar_t * _Format, ...);
' ========================================================================================
DECLARE FUNCTION wscanf_s CDECL IMPORT $CRT_DLLNAME ALIAS "wscanf_s" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================
'#endif

' ========================================================================================
' _Check_return_opt_ _CRTIMP_ALTERNATIVE int __cdecl _wscanf_s_l(
' _In_z_ _Scanf_s_format_string_ const wchar_t * _Format, _In_opt_ _locale_t _Locale, ...);
' ========================================================================================
DECLARE FUNCTION wscanf_s_l CDECL IMPORT $CRT_DLLNAME ALIAS "_wscanf_s_l" ( _
   BYREF format AS WSTRINGZ _                           ' __in const wchar_t *format
 , OPTIONAL BYVAL locale AS locale_t _                  ' __in_opt _locale_t locale
 , OPTIONAL ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY, ANY _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP FILE * __cdecl _wfdopen(_In_ int _FileHandle , _In_z_ const wchar_t * _Mode);
' ========================================================================================
DECLARE FUNCTION wfdopen_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wfdopen" ( _
   BYVAL fd AS LONG _                                   ' __in int fd
 , BYREF mode AS WSTRINGZ _                             ' __in const wchar_t *mode
 ) AS DWORD                                             ' FILE *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_INSECURE_DEPRECATE(_wfopen_s) _CRTIMP FILE * __cdecl _wfopen(
' _In_z_ const wchar_t * _Filename, _In_z_ const wchar_t * _Mode);
' ========================================================================================
DECLARE FUNCTION wfopen_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wfopen" ( _
   BYREF filename AS WSTRINGZ _                         ' __in const wchar_t *filename
 , BYREF mode AS WSTRINGZ _                             ' __in const wchar_t *mode
 ) AS DWORD                                             ' FILE *
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _wfopen_s(_Deref_out_opt_ FILE ** _File,
' _In_z_ const wchar_t * _Filename, _In_z_ const wchar_t * _Mode);
' ========================================================================================
DECLARE FUNCTION wfopen_s CDECL IMPORT $CRT_DLLNAME ALIAS "_wfopen_s" ( _
   BYREF stream AS DWORD _                              ' __out FILE ** stream
 , BYREF filename AS WSTRINGZ _                         ' __in const wchar_t *filename
 , BYREF mode AS WSTRINGZ _                             ' __in const wchar_t *mode
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRT_INSECURE_DEPRECATE(_wfreopen_s) _CRTIMP FILE * __cdecl _wfreopen(
' _In_z_ const wchar_t * _Filename, _In_z_ const wchar_t * _Mode, _Inout_ FILE * _OldFile);
' ========================================================================================
DECLARE FUNCTION wfreopen_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wfreopen" ( _
   BYREF path AS WSTRINGZ _                             ' __in const wchar_t *path
 , BYREF mode AS WSTRINGZ _                             ' __in const wchar_t* mode
 , BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS DWORD                                             ' FILE *
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _wfreopen_s(_Deref_out_opt_ FILE ** _File,
' _In_z_ const wchar_t * _Filename, _In_z_ const wchar_t * _Mode, _Inout_ FILE * _OldFile);
' ========================================================================================
DECLARE FUNCTION wfreopen_s CDECL IMPORT $CRT_DLLNAME ALIAS "_wfreopen_s" ( _
   BYREF stream AS DWORD _                              ' __out FILE ** stream
 , BYREF path AS WSTRINGZ _                             ' __in const wchar_t *path
 , BYREF mode AS WSTRINGZ _                             ' __in const wchar_t* mode
 , BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
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
' _Check_return_ _CRTIMP FILE * __cdecl _wpopen(_In_z_ const wchar_t *_Command, _In_z_ const wchar_t * _Mode);
' ========================================================================================
DECLARE FUNCTION wpopen_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wpopen" ( _
   BYREF command AS WSTRINGZ _                          ' __in const wchar_t *command
 , BYREF mode AS WSTRINGZ _                             ' __in const wchar_t *mode
 ) AS DWORD                                             ' FILE *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _wremove(_In_z_ const wchar_t * _Filename);
' ========================================================================================
DECLARE FUNCTION wremove_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wremove" ( _
   BYREF path AS WSTRINGZ _                             ' __in const wchar_t *path
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' ========================================================================================
DECLARE FUNCTION wtmpnam_ CDECL IMPORT $CRT_DLLNAME ALIAS "_wtmpnam" ( _
   BYREF string AS WSTRINGZ _                           ' __in wchar_t *string
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' _Check_return_wat_ _CRTIMP errno_t __cdecl _wtmpnam_s(
' _Out_z_cap_(_SizeInWords) wchar_t * _DstBuf, _In_ size_t _SizeInWords);
' ========================================================================================
DECLARE FUNCTION wtmpnam_s CDECL IMPORT $CRT_DLLNAME ALIAS "_wtmpnam_s" ( _
   BYREF string AS WSTRINGZ _                           ' __in wchar_t *string
 , BYVAL SizeInWords AS DWORD _                         ' __in size_t SizeInWords
 ) AS DWORD                                             ' wchar_t *
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP wint_t __cdecl _fgetwc_nolock(_Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION fgetwc_nolock CDECL IMPORT $CRT_DLLNAME ALIAS "_fgetwc_nolock" ( _
   BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS WORD                                              ' wint_t
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP wint_t __cdecl _fputwc_nolock(_In_ wchar_t _Ch, _Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION fputwc_nolock CDECL IMPORT $CRT_DLLNAME ALIAS "_fputwc_nolock" ( _
   BYREF c AS WSTRINGZ _                                ' __in wchar_t c
 , BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS WORD                                              ' wint_t
' ========================================================================================

' ========================================================================================
' _Check_return_opt_ _CRTIMP wint_t __cdecl _ungetwc_nolock(_In_ wint_t _Ch, _Inout_ FILE * _File);
' ========================================================================================
DECLARE FUNCTION ungetwc_nolock CDECL IMPORT $CRT_DLLNAME ALIAS "_ungetwc_nolock" ( _
   BYREF c AS WSTRINGZ _                                ' __in wchar_t c
 , BYVAL stream AS FILE PTR _                           ' __inout FILE *stream
 ) AS WORD                                              ' wint_t
' ========================================================================================

'#define _WSTDIO_DEFINED
#ENDIF   ' /* _WSTDIO_DEFINED */

'#define _STDIO_DEFINED
#ENDIF   ' /* _STDIO_DEFINED */
