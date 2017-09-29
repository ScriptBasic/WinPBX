' ########################################################################################
' Microsoft Windows
' File: sqltypes.inc
' Contents: This file defines the types used in ODBC
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SQLTYPES_INC = 1

'/* if ODBCVER is not defined, assume version 3.80 */
#IF NOT %DEF(%ODBCVER)
%ODBCVER = &H0380
#ENDIF   ' /* ODBCVER */

'/* API declaration data types */
'typedef unsigned char   SQLCHAR;
'#if (ODBCVER >= 0x0300)
'typedef signed char     SQLSCHAR;
'typedef unsigned char   SQLDATE;
'typedef unsigned char   SQLDECIMAL;
'typedef double          SQLDOUBLE;
'typedef double          SQLFLOAT;
'#endif
'typedef long            SQLINTEGER;
'typedef unsigned long   SQLUINTEGER;

'#ifdef _WIN64
'typedef INT64           SQLLEN;
'typedef UINT64          SQLULEN;
'typedef UINT64          SQLSETPOSIROW;
'#else
'#define SQLLEN          SQLINTEGER
'#define SQLULEN         SQLUINTEGER
'#define SQLSETPOSIROW   SQLUSMALLINT
'#endif

'//For Backward compatibility
'#ifdef WIN32
'typedef SQLULEN         SQLROWCOUNT;
'typedef SQLULEN         SQLROWSETSIZE;
'typedef SQLULEN         SQLTRANSID;
'typedef SQLLEN          SQLROWOFFSET;
'#endif

'#if (ODBCVER >= 0x0300)
'typedef unsigned char   SQLNUMERIC;
'#endif
'typedef void *          SQLPOINTER;
'#if (ODBCVER >= 0x0300)
'typedef float           SQLREAL;
'#endif
'typedef short           SQLSMALLINT;
'typedef unsigned short  SQLUSMALLINT;
'#if (ODBCVER >= 0x0300)
'typedef unsigned char   SQLTIME;
'typedef unsigned char   SQLTIMESTAMP;
'typedef unsigned char   SQLVARCHAR;
'#endif

'/* function return type */
'typedef SQLSMALLINT     SQLRETURN;

'/* generic data structures */
'#if (ODBCVER >= 0x0300)
'#if defined(WIN32) || defined(_WIN64)
'typedef void*               SQLHANDLE;
'#else
'typedef SQLINTEGER              SQLHANDLE;
'#endif   /* defined(WIN32) || defined(_WIN64) */
'typedef SQLHANDLE               SQLHENV;
'typedef SQLHANDLE               SQLHDBC;
'typedef SQLHANDLE               SQLHSTMT;
'typedef SQLHANDLE               SQLHDESC;
'#else //ODBCVER < 0x0300
'#if defined(WIN32) || defined(_WIN64)
'typedef void*               SQLHENV;
'typedef void*               SQLHDBC;
'typedef void*               SQLHSTMT;
'#else
'typedef SQLINTEGER              SQLHENV;
'typedef SQLINTEGER              SQLHDBC;
'typedef SQLINTEGER              SQLHSTMT;
'#endif  /* defined(WIN32) || defined(_WIN64) */
'#endif /* ODBCVER >= 0x0300 */

'/* SQL portable types for C */
'typedef unsigned char           UCHAR;
'typedef signed char             SCHAR;
'typedef SCHAR                   SQLSCHAR;
'typedef long int                SDWORD;
'typedef short int               SWORD;
'typedef unsigned long int       UDWORD;
'typedef unsigned short int      UWORD;
'#ifndef _WIN64
'typedef UDWORD                  SQLUINTEGER;
'#endif

'typedef signed long             SLONG;
'typedef signed short            SSHORT;
'typedef unsigned long           ULONG;
'typedef unsigned short          USHORT;
'typedef double                  SDOUBLE;
'typedef double                  LDOUBLE;
'typedef float                   SFLOAT;

'typedef void*                    PTR;

'typedef void*                    HENV;
'typedef void*                    HDBC;
'typedef void*                    HSTMT;

'typedef signed short            RETCODE;

'#if defined(WIN32) || defined(OS2)
'typedef HWND                    SQLHWND;
'#elif defined (UNIX)
'typedef Widget                  SQLHWND;
'#else
'/* placehold for future O/S GUI window handle definition */
'typedef SQLPOINTER              SQLHWND;
'#endif

'#ifndef   __SQLDATE
'#define   __SQLDATE
'/* transfer types for DATE, TIME, TIMESTAMP */
' // Size = 6 bytes
TYPE tagDATE_STRUCT WORD
   year  AS INTEGER   ' SQLSMALLINT
   month AS WORD      ' SQLUSMALLINT
   day   AS WORD      ' SQLUSMALLINT
END TYPE

MACRO DATE_STRUCT = tagDATE_STRUCT
MACRO SQL_DATE_STRUCT = tagDATE_STRUCT

'#if (ODBCVER >= 0x0300)
'typedef DATE_STRUCT   SQL_DATE_STRUCT;
'#endif  /* ODBCVER >= 0x0300 */

' // Size = 6 bytes
TYPE tagTIME_STRUCT WORD
   hour   AS WORD   ' SQLUSMALLINT
   minute AS WORD   ' SQLUSMALLINT
   second AS WORD   ' SQLUSMALLINT
END TYPE

MACRO TIME_STRUCT = tagTIME_STRUCT
MACRO SQL_TIME_STRUCT = tagTIME_STRUCT

'#if (ODBCVER >= 0x0300)
'typedef TIME_STRUCT   SQL_TIME_STRUCT;
'#endif /* ODBCVER >= 0x0300 */

' // Size = 16 bytes
TYPE tagTIMESTAMP_STRUCT WORD
   year     AS INTEGER   ' SQLSMALLINT
   month    AS WORD      ' SQLUSMALLINT
   day      AS WORD      ' SQLUSMALLINT
   hour     AS WORD      ' SQLUSMALLINT
   minute   AS WORD      ' SQLUSMALLINT
   second   AS WORD      ' SQLUSMALLINT
   fraction AS DWORD     ' SQLUINTEGER
END TYPE

MACRO TIMESTAMP_STRUCT = tagTIMESTAMP_STRUCT
MACRO SQL_TIMESTAMP_STRUCT = tagTIMESTAMP_STRUCT

'#if (ODBCVER >= 0x0300)
'typedef TIMESTAMP_STRUCT   SQL_TIMESTAMP_STRUCT;
'#endif  /* ODBCVER >= 0x0300 */


'/*
' * enumerations for DATETIME_INTERVAL_SUBCODE values for interval data types
' * these values are from SQL-92
' */

'#if (ODBCVER >= 0x0300)
' enum SQLINTERVAL
%SQL_IS_YEAR             = 1
%SQL_IS_MONTH            = 2
%SQL_IS_DAY              = 3
%SQL_IS_HOUR             = 4
%SQL_IS_MINUTE           = 5
%SQL_IS_SECOND           = 6
%SQL_IS_YEAR_TO_MONTH    = 7
%SQL_IS_DAY_TO_HOUR      = 8
%SQL_IS_DAY_TO_MINUTE    = 9
%SQL_IS_DAY_TO_SECOND    = 10
%SQL_IS_HOUR_TO_MINUTE   = 11
%SQL_IS_HOUR_TO_SECOND   = 12
%SQL_IS_MINUTE_TO_SECOND = 13

'#endif  /* ODBCVER >= 0x0300 */

'#if (ODBCVER >= 0x0300)
' // Size = 8 bytes
TYPE tagSQL_YEAR_MONTH DWORD
   year  AS DWORD   ' SQLUINTEGER
   month AS DWORD   ' SQLUINTEGER
END TYPE

MACRO SQL_YEAR_MONTH_STRUCT = tagSQL_YEAR_MONTH

' // Size = 20 bytes
TYPE tagSQL_DAY_SECOND DWORD
   day      AS DWORD   ' SQLUINTEGER
   hour     AS DWORD   ' SQLUINTEGER
   minute   AS DWORD   ' SQLUINTEGER
   second   AS DWORD   ' SQLUINTEGER
   fraction AS DWORD   ' SQLUINTEGER
END TYPE

MACRO SQL_DAY_SECOND_STRUCT = tagSQL_DAY_SECOND

' // Size = 20 bytes
UNION tagSQL_INTERVAL_UNION DWORD
   year_month AS SQL_YEAR_MONTH_STRUCT
   day_second AS SQL_DAY_SECOND_STRUCT
END UNION

MACRO SQL_INTERVAL_UNION = tagSQL_INTERVAL_UNION

' // Size = 28 bytes
TYPE tagSQL_INTERVAL_STRUCT DWORD
   Interval_type AS LONG                    ' SQLINTERVAL
   interval_sign AS INTEGER                 ' SQLSMALLINT
   intval        AS tagSQL_INTERVAL_UNION
END TYPE

MACRO SQL_INTERVAL_STRUCT = tagSQL_INTERVAL_STRUCT

'#endif  /* ODBCVER >= 0x0300 */

'#endif   /* __SQLDATE   */

'/* the ODBC C types for SQL_C_SBIGINT and SQL_C_UBIGINT */
'#if (ODBCVER >= 0x0300)
'#if (_MSC_VER >= 900)
'#define ODBCINT64   __int64
'#endif

'/* If using other compilers, define ODBCINT64 to the
'   approriate 64 bit integer type */
'#ifdef ODBCINT64
'typedef ODBCINT64   SQLBIGINT;
'typedef unsigned ODBCINT64   SQLUBIGINT;
'#endif
'#endif  /* ODBCVER >= 0x0300 */

'/* internal representation of numeric data type */
#IF %ODBCVER >= &H0300
%SQL_MAX_NUMERIC_LEN    = 16
' // Size = 19 bytes
TYPE tagSQL_NUMERIC_STRUCT BYTE
   precision AS BYTE                             ' SQLCHAR
   scale     AS BYTE                             ' SQLSCHAR
   sign      AS BYTE                             ' SQLSCHAR
   val       AS STRING * %SQL_MAX_NUMERIC_LEN    ' SQLCHAR[SQL_MAX_NUMERIC_LEN]
END TYPE
MACRO SQL_NUMERIC_STRUCT = tagSQL_NUMERIC_STRUCT
#ENDIF   ' /* ODBCVER >= 0x0300 */

'#if (ODBCVER >= 0x0350)
'#ifdef GUID_DEFINED
'typedef GUID   SQLGUID;
'#else
'/* size is 16 */
' // Size = 16 bytes
TYPE tagSQLGUID WORD
  Data1 AS DWORD        ' DWORD
  Data2 AS WORD         ' WORD
  Data3 AS WORD         ' WORD
  Data4 AS STRING * 8   ' BYTE[4]
END TYPE
MACRO SQLGUID = tagSQLGUID
'#endif  /* GUID_DEFINED */
'#endif  /* ODBCVER >= 0x0350 */

'typedef SQLULEN         BOOKMARK;

'#ifdef _WCHAR_T_DEFINED
'typedef wchar_t SQLWCHAR;
'#else
'typedef unsigned short SQLWCHAR;
'#endif

'#ifdef UNICODE
'typedef SQLWCHAR        SQLTCHAR;
'#else
'typedef SQLCHAR         SQLTCHAR;
'#endif  /* UNICODE */
