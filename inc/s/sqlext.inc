' ########################################################################################
' Microsoft Windows
' File: sqlext.inc
' Contents: This is the include for applications using the Microsoft SQL Extensions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SQLEXT_INC = 1

#INCLUDE ONCE "sql.inc"

' Moved from below
%SQL_LIKE_ONLY       = 1
%SQL_ALL_EXCEPT_LIKE = 2

'/* generally useful constants */
%SQL_SPEC_MAJOR  = 3        '/* Major version of specification  */
%SQL_SPEC_MINOR  = 80       '/* Minor version of specification  */
$SQL_SPEC_STRING = "03.80"  '/* String constant for version */

%SQL_SQLSTATE_SIZE  = 5   '/* size of SQLSTATE */
%SQL_MAX_DSN_LENGTH = 32  '/* maximum data source name size */

%SQL_MAX_OPTION_STRING_LENGTH = 256

'/* return code SQL_NO_DATA_FOUND is the same as SQL_NO_DATA */
#IF %ODBCVER < &H0300
%SQL_NO_DATA_FOUND = 100
#ELSE
%SQL_NO_DATA_FOUND = %SQL_NO_DATA
#ENDIF

'/* an end handle type */
#IF %ODBCVER >= &H0300
%SQL_HANDLE_SENV = 5
#ENDIF   '  /* ODBCVER >= &H0300 */

'/* env attribute */
#IF %ODBCVER >= &H0300
%SQL_ATTR_ODBC_VERSION       = 200
%SQL_ATTR_CONNECTION_POOLING = 201
%SQL_ATTR_CP_MATCH           = 202
#ENDIF   '  /* ODBCVER >= &H0300 */

#IF %ODBCVER >= &H0300
'/* values for SQL_ATTR_CONNECTION_POOLING */
%SQL_CP_OFF            = 0???
%SQL_CP_ONE_PER_DRIVER = 1???
%SQL_CP_ONE_PER_HENV   = 2???
%SQL_CP_DEFAULT        = %SQL_CP_OFF

'/* values for SQL_ATTR_CP_MATCH */
%SQL_CP_STRICT_MATCH  = 0???
%SQL_CP_RELAXED_MATCH = 1???
%SQL_CP_MATCH_DEFAULT = %SQL_CP_STRICT_MATCH

'/* values for SQL_ATTR_ODBC_VERSION */
%SQL_OV_ODBC2 = 2???
%SQL_OV_ODBC3 = 3???
#ENDIF   '  /* ODBCVER >= &H0300 */

#IF %ODBCVER >= &H0380
'// new values for SQL_ATTR_ODBC_VERSION
'// From ODBC 3.8 onwards, we should use <major version> * 100 + <minor version>
%SQL_OV_ODBC3_80 = 380???
#ENDIF   ' /* ODBCVER >= 0x0380

'/* connection attributes */
%SQL_ACCESS_MODE       = 101
%SQL_AUTOCOMMIT        = 102
%SQL_LOGIN_TIMEOUT     = 103
%SQL_OPT_TRACE         = 104
%SQL_OPT_TRACEFILE     = 105
%SQL_TRANSLATE_DLL     = 106
%SQL_TRANSLATE_OPTION  = 107
%SQL_TXN_ISOLATION     = 108
%SQL_CURRENT_QUALIFIER = 109
%SQL_ODBC_CURSORS      = 110
%SQL_QUIET_MODE        = 111
%SQL_PACKET_SIZE       = 112

'/* connection attributes with new names */
#IF %ODBCVER >= &H0300
%SQL_ATTR_ACCESS_MODE         = %SQL_ACCESS_MODE
%SQL_ATTR_AUTOCOMMIT          = %SQL_AUTOCOMMIT
%SQL_ATTR_CONNECTION_TIMEOUT  = 113
%SQL_ATTR_CURRENT_CATALOG     = %SQL_CURRENT_QUALIFIER
%SQL_ATTR_DISCONNECT_BEHAVIOR = 114
%SQL_ATTR_ENLIST_IN_DTC       = 1207
%SQL_ATTR_ENLIST_IN_XA        = 1208
%SQL_ATTR_LOGIN_TIMEOUT       = %SQL_LOGIN_TIMEOUT
%SQL_ATTR_ODBC_CURSORS        = %SQL_ODBC_CURSORS
%SQL_ATTR_PACKET_SIZE         = %SQL_PACKET_SIZE
%SQL_ATTR_QUIET_MODE          = %SQL_QUIET_MODE
%SQL_ATTR_TRACE               = %SQL_OPT_TRACE
%SQL_ATTR_TRACEFILE           = %SQL_OPT_TRACEFILE
%SQL_ATTR_TRANSLATE_LIB       = %SQL_TRANSLATE_DLL
%SQL_ATTR_TRANSLATE_OPTION    = %SQL_TRANSLATE_OPTION
%SQL_ATTR_TXN_ISOLATION       = %SQL_TXN_ISOLATION
#ENDIF   '  /* ODBCVER >= &H0300 */

%SQL_ATTR_CONNECTION_DEAD     = 1209  'ODBC 3.5 /* GetConnectAttr only */

#IF %ODBCVER >= &H0351
'/*   ODBC Driver Manager sets this connection attribute to a unicode driver
'   (which supports SQLConnectW) when the application is an ANSI application
'   (which calls SQLConnect, SQLDriverConnect, or SQLBrowseConnect).
'   This is SetConnectAttr only and application does not set this attribute
'   This attribute was introduced because some unicode driver's some APIs may
'   need to behave differently on ANSI or Unicode applications. A unicode
'   driver, which  has same behavior for both ANSI or Unicode applications,
'   should return SQL_ERROR when the driver manager sets this connection
'   attribute. When a unicode driver returns SQL_SUCCESS on this attribute,
'   the driver manager treates ANSI and Unicode connections differently in
'   connection pooling.
'*/
%SQL_ATTR_ANSI_APP = 115
#ENDIF   '  /* ODBCVER >= &H0351 */

#IF %ODBCVER >= &H0380
%SQL_ATTR_RESET_CONNECTION = 116
%SQL_ATTR_ASYNC_DBC_FUNCTIONS_ENABLE = 117
#ENDIF

'/* SQL_CONNECT_OPT_DRVR_START is not meaningful for 3.0 driver */
#IF %ODBCVER >= &H0300
%SQL_CONNECT_OPT_DRVR_START = 1000
#ENDIF   '  /* ODBCVER >= &H0300 */

#IF %ODBCVER < &H0300
%SQL_CONN_OPT_MAX = %SQL_PACKET_SIZE
%SQL_CONN_OPT_MIN = %SQL_ACCESS_MODE
#ENDIF   ' /* ODBCVER < &H0300 */

'/* SQL_ACCESS_MODE options */
%SQL_MODE_READ_WRITE = 0???
%SQL_MODE_READ_ONLY  = 1???
%SQL_MODE_DEFAULT    = %SQL_MODE_READ_WRITE

'/* SQL_AUTOCOMMIT options */
%SQL_AUTOCOMMIT_OFF     = 0???
%SQL_AUTOCOMMIT_ON      = 1???
%SQL_AUTOCOMMIT_DEFAULT = %SQL_AUTOCOMMIT_ON

'/* SQL_LOGIN_TIMEOUT options */
%SQL_LOGIN_TIMEOUT_DEFAULT = 15???

'/* SQL_OPT_TRACE options */
%SQL_OPT_TRACE_OFF     = 0???
%SQL_OPT_TRACE_ON      = 1???
%SQL_OPT_TRACE_DEFAULT = %SQL_OPT_TRACE_OFF
$SQL_OPT_TRACE_FILE_DEFAULT = "\SQL.LOG"

'/* SQL_ODBC_CURSORS options */
%SQL_CUR_USE_IF_NEEDED = 0???
%SQL_CUR_USE_ODBC      = 1???
%SQL_CUR_USE_DRIVER    = 2???
%SQL_CUR_DEFAULT       = %SQL_CUR_USE_DRIVER

#IF %ODBCVER >= &H0300
'/* values for SQL_ATTR_DISCONNECT_BEHAVIOR */
%SQL_DB_RETURN_TO_POOL = 0???
%SQL_DB_DISCONNECT     = 1???
%SQL_DB_DEFAULT        = %SQL_DB_RETURN_TO_POOL

'/* values for SQL_ATTR_ENLIST_IN_DTC */
%SQL_DTC_DONE = 0&
#ENDIF   ' /* ODBCVER >= 0x0300 */

'/* values for SQL_ATTR_CONNECTION_DEAD */
%SQL_CD_FALSE                 = 0&  'ODBC 3.5 /* GetConnectAttr only */
%SQL_CD_TRUE                  = 1&  'ODBC 3.5 /* GetConnectAttr only */

'/* values for SQL_ATTR_ANSI_APP */
#IF %ODBCVER >= &H0351
%SQL_AA_TRUE              = 1&  ' /* the application is an ANSI app */
%SQL_AA_FALSE             = 0&  ' /* the application is a Unicode app */
#ENDIF

'/* values for SQL_ATTR_RESET_CONNECTION */
#IF %ODBCVER >= &H0380
%SQL_RESET_CONNECTION_YES = 1???
#ENDIF   ' // ODBCVER >= 0x0380

'/* values for SQL_ATTR_ASYNC_DBC_FUNCTIONS_ENABLE */
#IF %ODBCVER >= &H0380
%SQL_ASYNC_DBC_ENABLE_ON      = 1???
%SQL_ASYNC_DBC_ENABLE_OFF     = 0???
%SQL_ASYNC_DBC_ENABLE_DEFAULT = %SQL_ASYNC_DBC_ENABLE_OFF
#ENDIF   ' // ODBCVER >= 0x0380

'/* statement attributes */
%SQL_QUERY_TIMEOUT   = 0
%SQL_MAX_ROWS        = 1
%SQL_NOSCAN          = 2
%SQL_MAX_LENGTH      = 3
%SQL_ASYNC_ENABLE    = 4   '/* same as SQL_ATTR_ASYNC_ENABLE */
%SQL_BIND_TYPE       = 5
%SQL_CURSOR_TYPE     = 6
%SQL_CONCURRENCY     = 7
%SQL_KEYSET_SIZE     = 8
%SQL_ROWSET_SIZE     = 9
%SQL_SIMULATE_CURSOR = 10
%SQL_RETRIEVE_DATA   = 11
%SQL_USE_BOOKMARKS   = 12
%SQL_GET_BOOKMARK    = 13      '/*      GetStmtOption Only */
%SQL_ROW_NUMBER      = 14      '/*      GetStmtOption Only */

'/* statement attributes for ODBC 3.0 */
#IF %ODBCVER >= &H0300
%SQL_ATTR_ASYNC_ENABLE          = 4
%SQL_ATTR_CONCURRENCY           = %SQL_CONCURRENCY
%SQL_ATTR_CURSOR_TYPE           = %SQL_CURSOR_TYPE
%SQL_ATTR_ENABLE_AUTO_IPD       = 15
%SQL_ATTR_FETCH_BOOKMARK_PTR    = 16
%SQL_ATTR_KEYSET_SIZE           = %SQL_KEYSET_SIZE
%SQL_ATTR_MAX_LENGTH            = %SQL_MAX_LENGTH
%SQL_ATTR_MAX_ROWS              = %SQL_MAX_ROWS
%SQL_ATTR_NOSCAN                = %SQL_NOSCAN
%SQL_ATTR_PARAM_BIND_OFFSET_PTR = 17
%SQL_ATTR_PARAM_BIND_TYPE       = 18
%SQL_ATTR_PARAM_OPERATION_PTR   = 19
%SQL_ATTR_PARAM_STATUS_PTR      = 20
%SQL_ATTR_PARAMS_PROCESSED_PTR  = 21
%SQL_ATTR_PARAMSET_SIZE         = 22
%SQL_ATTR_QUERY_TIMEOUT         = %SQL_QUERY_TIMEOUT
%SQL_ATTR_RETRIEVE_DATA         = %SQL_RETRIEVE_DATA
%SQL_ATTR_ROW_BIND_OFFSET_PTR   = 23
%SQL_ATTR_ROW_BIND_TYPE         = %SQL_BIND_TYPE
%SQL_ATTR_ROW_NUMBER            = %SQL_ROW_NUMBER        'GetStmtAttr*/
%SQL_ATTR_ROW_OPERATION_PTR     = 24
%SQL_ATTR_ROW_STATUS_PTR        = 25
%SQL_ATTR_ROWS_FETCHED_PTR      = 26
%SQL_ATTR_ROW_ARRAY_SIZE        = 27
%SQL_ATTR_SIMULATE_CURSOR       = %SQL_SIMULATE_CURSOR
%SQL_ATTR_USE_BOOKMARKS         = %SQL_USE_BOOKMARKS
#ENDIF   ' /* ODBCVER >= &H0300 */

#IF %ODBCVER < &H0300
%SQL_STMT_OPT_MAX = %SQL_ROW_NUMBER
%SQL_STMT_OPT_MIN = %SQL_QUERY_TIMEOUT
#ENDIF   ' /* ODBCVER < &H0300 */

'/* New defines for SEARCHABLE column in SQLGetTypeInfo */

#IF %ODBCVER >= &H0300
%SQL_COL_PRED_CHAR  = %SQL_LIKE_ONLY
%SQL_COL_PRED_BASIC = %SQL_ALL_EXCEPT_LIKE
#ENDIF   ' /* ODBCVER >= &H0300 */

'/* whether an attribute is a pointer or not */
#IF %ODBCVER >= &H0300
%SQL_IS_POINTER   = -4
%SQL_IS_UINTEGER  = -5
%SQL_IS_INTEGER   = -6
%SQL_IS_USMALLINT = -7
%SQL_IS_SMALLINT  = -8
#ENDIF   ' /* ODBCVER >= &H0300 */

'/* the value of SQL_ATTR_PARAM_BIND_TYPE */
#IF %ODBCVER >= &H0300
%SQL_PARAM_BIND_BY_COLUMN    = 0???
%SQL_PARAM_BIND_TYPE_DEFAULT = %SQL_PARAM_BIND_BY_COLUMN
#ENDIF   ' /* ODBCVER >= &H0300 */

'/* SQL_QUERY_TIMEOUT options */
%SQL_QUERY_TIMEOUT_DEFAULT = 0???

'/* SQL_MAX_ROWS options */
%SQL_MAX_ROWS_DEFAULT = 0???

'/* SQL_NOSCAN options */
%SQL_NOSCAN_OFF     = 0???              '      1.0 FALSE */
%SQL_NOSCAN_ON      = 1???              '      1.0 TRUE */
%SQL_NOSCAN_DEFAULT = %SQL_NOSCAN_OFF

'/* SQL_MAX_LENGTH options */
%SQL_MAX_LENGTH_DEFAULT = 0???

'/* values for SQL_ATTR_ASYNC_ENABLE */
%SQL_ASYNC_ENABLE_OFF     = 0???
%SQL_ASYNC_ENABLE_ON      = 1???
%SQL_ASYNC_ENABLE_DEFAULT = %SQL_ASYNC_ENABLE_OFF

'/* SQL_BIND_TYPE options */
%SQL_BIND_BY_COLUMN    = 0???
%SQL_BIND_TYPE_DEFAULT = %SQL_BIND_BY_COLUMN   ' Default value */

'/* SQL_CONCURRENCY options */
%SQL_CONCUR_READ_ONLY = 1
%SQL_CONCUR_LOCK      = 2
%SQL_CONCUR_ROWVER    = 3
%SQL_CONCUR_VALUES    = 4
%SQL_CONCUR_DEFAULT   = %SQL_CONCUR_READ_ONLY   ' Default value */

'/* SQL_CURSOR_TYPE options */
%SQL_CURSOR_FORWARD_ONLY  = 0???
%SQL_CURSOR_KEYSET_DRIVEN = 1???
%SQL_CURSOR_DYNAMIC       = 2???
%SQL_CURSOR_STATIC        = 3???
%SQL_CURSOR_TYPE_DEFAULT  = %SQL_CURSOR_FORWARD_ONLY   ' Default value */

'/* SQL_ROWSET_SIZE options */
%SQL_ROWSET_SIZE_DEFAULT = 1???

'/* SQL_KEYSET_SIZE options */
%SQL_KEYSET_SIZE_DEFAULT = 0???

'/* SQL_SIMULATE_CURSOR options */
%SQL_SC_NON_UNIQUE = 0???
%SQL_SC_TRY_UNIQUE = 1???
%SQL_SC_UNIQUE     = 2???

'/* SQL_RETRIEVE_DATA options */
%SQL_RD_OFF     = 0???
%SQL_RD_ON      = 1???
%SQL_RD_DEFAULT = %SQL_RD_ON

'/* SQL_USE_BOOKMARKS options */
%SQL_UB_OFF     = 0???
%SQL_UB_ON      = 01???
%SQL_UB_DEFAULT = %SQL_UB_OFF

'/* New values for SQL_USE_BOOKMARKS attribute */
#IF %ODBCVER >= &H0300
%SQL_UB_FIXED    = %SQL_UB_ON
%SQL_UB_VARIABLE = 2???
#ENDIF   ' /* ODBCVER >= &H0300 */

'/* defines for diagnostics fields */
#IF %ODBCVER >= &H0300
%SQL_DIAG_CURSOR_ROW_COUNT = -1249
%SQL_DIAG_ROW_NUMBER       = -1248
%SQL_DIAG_COLUMN_NUMBER    = -1247
#ENDIF   ' /* ODBCVER >= &H0300 */

'/* SQL extended datatypes */
%SQL_DATE          = 9
#IF %ODBCVER >= &H0300
%SQL_INTERVAL      = 10
#ENDIF   ' /* ODBCVER >= 0x0300 */
%SQL_TIME          = 10
%SQL_TIMESTAMP     = 11
%SQL_LONGVARCHAR   = -1
%SQL_BINARY        = -2
%SQL_VARBINARY     = -3
%SQL_LONGVARBINARY = -4
%SQL_BIGINT        = -5
%SQL_TINYINT       = -6
%SQL_BIT           = -7
#IF %ODBCVER >= &H0350
%SQL_GUID          = -11
#ENDIF   ' /* ODBCVER >= &H0350 */

#IF %ODBCVER >= &H0300
'/* interval code */
%SQL_CODE_YEAR                 = 1
%SQL_CODE_MONTH                = 2
%SQL_CODE_DAY                  = 3
%SQL_CODE_HOUR                 = 4
%SQL_CODE_MINUTE               = 5
%SQL_CODE_SECOND               = 6
%SQL_CODE_YEAR_TO_MONTH        = 7
%SQL_CODE_DAY_TO_HOUR          = 8
%SQL_CODE_DAY_TO_MINUTE        = 9
%SQL_CODE_DAY_TO_SECOND        = 10
%SQL_CODE_HOUR_TO_MINUTE       = 11
%SQL_CODE_HOUR_TO_SECOND       = 12
%SQL_CODE_MINUTE_TO_SECOND     = 13

%SQL_INTERVAL_YEAR             = (100 + %SQL_CODE_YEAR)
%SQL_INTERVAL_MONTH            = (100 + %SQL_CODE_MONTH)
%SQL_INTERVAL_DAY              = (100 + %SQL_CODE_DAY)
%SQL_INTERVAL_HOUR             = (100 + %SQL_CODE_HOUR)
%SQL_INTERVAL_MINUTE           = (100 + %SQL_CODE_MINUTE)
%SQL_INTERVAL_SECOND           = (100 + %SQL_CODE_SECOND)
%SQL_INTERVAL_YEAR_TO_MONTH    = (100 + %SQL_CODE_YEAR_TO_MONTH)
%SQL_INTERVAL_DAY_TO_HOUR      = (100 + %SQL_CODE_DAY_TO_HOUR)
%SQL_INTERVAL_DAY_TO_MINUTE    = (100 + %SQL_CODE_DAY_TO_MINUTE)
%SQL_INTERVAL_DAY_TO_SECOND    = (100 + %SQL_CODE_DAY_TO_SECOND)
%SQL_INTERVAL_HOUR_TO_MINUTE   = (100 + %SQL_CODE_HOUR_TO_MINUTE)
%SQL_INTERVAL_HOUR_TO_SECOND   = (100 + %SQL_CODE_HOUR_TO_SECOND)
%SQL_INTERVAL_MINUTE_TO_SECOND = (100 + %SQL_CODE_MINUTE_TO_SECOND)

#ELSE

%SQL_INTERVAL_YEAR                       = -80
%SQL_INTERVAL_MONTH                      = -81
%SQL_INTERVAL_YEAR_TO_MONTH              = -82
%SQL_INTERVAL_DAY                        = -83
%SQL_INTERVAL_HOUR                       = -84
%SQL_INTERVAL_MINUTE                     = -85
%SQL_INTERVAL_SECOND                     = -86
%SQL_INTERVAL_DAY_TO_HOUR                = -87
%SQL_INTERVAL_DAY_TO_MINUTE              = -88
%SQL_INTERVAL_DAY_TO_SECOND              = -89
%SQL_INTERVAL_HOUR_TO_MINUTE             = -90
%SQL_INTERVAL_HOUR_TO_SECOND             = -91
%SQL_INTERVAL_MINUTE_TO_SECOND           = -92
#ENDIF   ' /* ODBCVER >= 0x0300 */


#IF %ODBCVER <= &H0300
%SQL_UNICODE                   = -95
%SQL_UNICODE_VARCHAR           = -96
%SQL_UNICODE_LONGVARCHAR       = -97
%SQL_UNICODE_CHAR              = %SQL_UNICODE
#ELSE
'/* The previous definitions for SQL_UNICODE_ are historical and obsolete */

%SQL_UNICODE             = -8   ' SQL_WCHAR
%SQL_UNICODE_VARCHAR     = -9   ' SQL_WVARCHAR
%SQL_UNICODE_LONGVARCHAR = -10  ' SQL_WLONGVARCHAR
%SQL_UNICODE_CHAR        = -8   ' SQL_WCHAR
#ENDIF

#IF %ODBCVER < &H0300
%SQL_TYPE_DRIVER_START = %SQL_INTERVAL_YEAR
%SQL_TYPE_DRIVER_END   = %SQL_UNICODE_LONGVARCHAR
#ENDIF   ' /* ODBCVER < 0x0300 */

'/* C datatype to SQL datatype mapping      SQL types
%SQL_C_CHAR    = %SQL_CHAR             ' CHAR, VARCHAR, DECIMAL, NUMERIC */
%SQL_C_LONG    = %SQL_INTEGER          ' INTEGER                      */
%SQL_C_SHORT   = %SQL_SMALLINT         ' SMALLINT                     */
%SQL_C_FLOAT   = %SQL_REAL             ' REAL                         */
%SQL_C_DOUBLE  = %SQL_DOUBLE           ' FLOAT, DOUBLE                */
#IF %ODBCVER >= &H0300
%SQL_C_NUMERIC = %SQL_NUMERIC
#ENDIF   ' /* ODBCVER >= &H0300 */
%SQL_C_DEFAULT = 99

%SQL_SIGNED_OFFSET   = -20
%SQL_UNSIGNED_OFFSET = -22

'/* C datatype to SQL datatype mapping */
%SQL_C_DATE                      = %SQL_DATE
%SQL_C_TIME                      = %SQL_TIME
%SQL_C_TIMESTAMP                 = %SQL_TIMESTAMP
#IF %ODBCVER >= &H0300
%SQL_C_TYPE_DATE                 = %SQL_TYPE_DATE
%SQL_C_TYPE_TIME                 = %SQL_TYPE_TIME
%SQL_C_TYPE_TIMESTAMP            = %SQL_TYPE_TIMESTAMP
%SQL_C_INTERVAL_YEAR             = %SQL_INTERVAL_YEAR
%SQL_C_INTERVAL_MONTH            = %SQL_INTERVAL_MONTH
%SQL_C_INTERVAL_DAY              = %SQL_INTERVAL_DAY
%SQL_C_INTERVAL_HOUR             = %SQL_INTERVAL_HOUR
%SQL_C_INTERVAL_MINUTE           = %SQL_INTERVAL_MINUTE
%SQL_C_INTERVAL_SECOND           = %SQL_INTERVAL_SECOND
%SQL_C_INTERVAL_YEAR_TO_MONTH    = %SQL_INTERVAL_YEAR_TO_MONTH
%SQL_C_INTERVAL_DAY_TO_HOUR      = %SQL_INTERVAL_DAY_TO_HOUR
%SQL_C_INTERVAL_DAY_TO_MINUTE    = %SQL_INTERVAL_DAY_TO_MINUTE
%SQL_C_INTERVAL_DAY_TO_SECOND    = %SQL_INTERVAL_DAY_TO_SECOND
%SQL_C_INTERVAL_HOUR_TO_MINUTE   = %SQL_INTERVAL_HOUR_TO_MINUTE
%SQL_C_INTERVAL_HOUR_TO_SECOND   = %SQL_INTERVAL_HOUR_TO_SECOND
%SQL_C_INTERVAL_MINUTE_TO_SECOND = %SQL_INTERVAL_MINUTE_TO_SECOND
#ENDIF   ' /* ODBCVER >= 0x0300 */
%SQL_C_BINARY                    = %SQL_BINARY
%SQL_C_BIT                       = %SQL_BIT
#IF %ODBCVER >= &H0300
%SQL_C_SBIGINT                   = (%SQL_BIGINT+%SQL_SIGNED_OFFSET)     ' SIGNED BIGINT */
%SQL_C_UBIGINT                   = (%SQL_BIGINT+%SQL_UNSIGNED_OFFSET)   ' UNSIGNED BIGINT */
#ENDIF   ' /* ODBCVER >= &H0300 */
%SQL_C_TINYINT                   = %SQL_TINYINT
%SQL_C_SLONG                     = (%SQL_C_LONG+%SQL_SIGNED_OFFSET)     ' SIGNED INTEGER  */
%SQL_C_SSHORT                    = (%SQL_C_SHORT+%SQL_SIGNED_OFFSET)    ' SIGNED SMALLINT */
%SQL_C_STINYINT                  = (%SQL_TINYINT+%SQL_SIGNED_OFFSET)    ' SIGNED TINYINT  */
%SQL_C_ULONG                     = (%SQL_C_LONG+%SQL_UNSIGNED_OFFSET)   ' UNSIGNED INTEGER*/
%SQL_C_USHORT                    = (%SQL_C_SHORT+%SQL_UNSIGNED_OFFSET)  ' UNSIGNED SMALLINT*/
%SQL_C_UTINYINT                  = (%SQL_TINYINT+%SQL_UNSIGNED_OFFSET)  ' UNSIGNED TINYINT*/

'#ifdef _WIN64
'#define SQL_C_BOOKMARK   SQL_C_UBIGINT                     /* BOOKMARK        */
'#else
%SQL_C_BOOKMARK                  = %SQL_C_ULONG                         ' BOOKMARK        */
'#endif

#IF %ODBCVER >= &H0350
'#define SQL_C_GUID   SQL_GUID
#ENDIF   ' /* ODBCVER >= &H0350 */

%SQL_TYPE_NULL                   = 0
#IF %ODBCVER < &H0300
%SQL_TYPE_MIN                    = %SQL_BIT
%SQL_TYPE_MAX                    = %SQL_VARCHAR
#ENDIF

'// base value of driver-specific C-Type (max is 0x7fff)
'// define driver-specific C-Type, named as SQL_DRIVER_C_TYPE_BASE,
'// SQL_DRIVER_C_TYPE_BASE+1, SQL_DRIVER_C_TYPE_BASE+2, etc.
#IF %ODBCVER >= &H0380
%SQL_DRIVER_C_TYPE_BASE      = &H4000??
#ENDIF

'// base value of driver-specific fields/attributes (max are 0x7fff [16-bit] or 0x00007fff [32-bit])
'// define driver-specific SQL-Type, named as SQL_DRIVER_SQL_TYPE_BASE,
'// SQL_DRIVER_SQL_TYPE_BASE+1, SQL_DRIVER_SQL_TYPE_BASE+2, etc.
'//
'// Please note that there is no runtime change in this version of DM.
'// However, we suggest that driver manufacturers adhere to this range
'// as future versions of the DM may enforce these constraints
#IF %ODBCVER >= &H0380
%SQL_DRIVER_SQL_TYPE_BASE    = &H4000??
%SQL_DRIVER_DESC_FIELD_BASE  = &H4000??
%SQL_DRIVER_DIAG_FIELD_BASE  = &H4000??
%SQL_DRIVER_INFO_TYPE_BASE   = &H4000??
%SQL_DRIVER_CONN_ATTR_BASE   = &H00004000???   ' // 32-bit
%SQL_DRIVER_STMT_ATTR_BASE   = &H00004000???   ' // 32-bit
#ENDIF

#IF %ODBCVER >= &H0300
%SQL_C_VARBOOKMARK               = %SQL_C_BINARY
#ENDIF   ' /* ODBCVER >= &H0300 */

'/* define for SQL_DIAG_ROW_NUMBER and SQL_DIAG_COLUMN_NUMBER */
#IF %ODBCVER >= &H0300
%SQL_NO_ROW_NUMBER         = -1
%SQL_NO_COLUMN_NUMBER      = -1
%SQL_ROW_NUMBER_UNKNOWN    = -2
%SQL_COLUMN_NUMBER_UNKNOWN = -2
#ENDIF

'/* SQLBindParameter extensions */
%SQL_DEFAULT_PARAM           = -5
%SQL_IGNORE                  = -6
#IF %ODBCVER >= &H0300
%SQL_COLUMN_IGNORE           = %SQL_IGNORE
#ENDIF   ' /* ODBCVER >= &H0300 */
%SQL_LEN_DATA_AT_EXEC_OFFSET = (-100)
'#define SQL_LEN_DATA_AT_EXEC(length) (-(length)+SQL_LEN_DATA_AT_EXEC_OFFSET)
MACRO SQL_LEN_DATA_AT_EXEC(length) = (-(length)+%SQL_LEN_DATA_AT_EXEC_OFFSET)

'/* binary length for driver specific attributes */
%SQL_LEN_BINARY_ATTR_OFFSET = (-100)
'#define SQL_LEN_BINARY_ATTR(length)    (-(length)+SQL_LEN_BINARY_ATTR_OFFSET)
MACRO SQL_LEN_BINARY_ATTR(length) = (-(length)+%SQL_LEN_BINARY_ATTR_OFFSET)

'/* SQLColAttributes defines */
%SQL_COLUMN_COUNT          = 0
%SQL_COLUMN_NAME           = 1
%SQL_COLUMN_TYPE           = 2
%SQL_COLUMN_LENGTH         = 3
%SQL_COLUMN_PRECISION      = 4
%SQL_COLUMN_SCALE          = 5
%SQL_COLUMN_DISPLAY_SIZE   = 6
%SQL_COLUMN_NULLABLE       = 7
%SQL_COLUMN_UNSIGNED       = 8
%SQL_COLUMN_MONEY          = 9
%SQL_COLUMN_UPDATABLE      = 10
%SQL_COLUMN_AUTO_INCREMENT = 11
%SQL_COLUMN_CASE_SENSITIVE = 12
%SQL_COLUMN_SEARCHABLE     = 13
%SQL_COLUMN_TYPE_NAME      = 14
%SQL_COLUMN_TABLE_NAME     = 15
%SQL_COLUMN_OWNER_NAME     = 16
%SQL_COLUMN_QUALIFIER_NAME = 17
%SQL_COLUMN_LABEL          = 18
%SQL_COLATT_OPT_MAX        = %SQL_COLUMN_LABEL
#IF %ODBCVER < &H0300
%SQL_COLUMN_DRIVER_START   = 1000
#ENDIF   ' /* ODBCVER < &H0300 */

%SQL_COLATT_OPT_MIN = %SQL_COLUMN_COUNT

'/* extended descriptor field */
#IF %ODBCVER >= &H0300
%SQL_DESC_ARRAY_SIZE                  = 20
%SQL_DESC_ARRAY_STATUS_PTR            = 21
%SQL_DESC_AUTO_UNIQUE_VALUE           = %SQL_COLUMN_AUTO_INCREMENT
%SQL_DESC_BASE_COLUMN_NAME            = 22
%SQL_DESC_BASE_TABLE_NAME             = 23
%SQL_DESC_BIND_OFFSET_PTR             = 24
%SQL_DESC_BIND_TYPE                   = 25
%SQL_DESC_CASE_SENSITIVE              = %SQL_COLUMN_CASE_SENSITIVE
%SQL_DESC_CATALOG_NAME                = %SQL_COLUMN_QUALIFIER_NAME
%SQL_DESC_CONCISE_TYPE                = %SQL_COLUMN_TYPE
%SQL_DESC_DATETIME_INTERVAL_PRECISION = 26
%SQL_DESC_DISPLAY_SIZE                = %SQL_COLUMN_DISPLAY_SIZE
%SQL_DESC_FIXED_PREC_SCALE            = %SQL_COLUMN_MONEY
%SQL_DESC_LABEL                       = %SQL_COLUMN_LABEL
%SQL_DESC_LITERAL_PREFIX              = 27
%SQL_DESC_LITERAL_SUFFIX              = 28
%SQL_DESC_LOCAL_TYPE_NAME             = 29
%SQL_DESC_MAXIMUM_SCALE               = 30
%SQL_DESC_MINIMUM_SCALE               = 31
%SQL_DESC_NUM_PREC_RADIX              = 32
%SQL_DESC_PARAMETER_TYPE              = 33
%SQL_DESC_ROWS_PROCESSED_PTR          = 34
#IF %ODBCVER >= &H0350
%SQL_DESC_ROWVER                      = 35
#ENDIF   ' /* ODBCVER >= &H0350 */
%SQL_DESC_SCHEMA_NAME                 = %SQL_COLUMN_OWNER_NAME
%SQL_DESC_SEARCHABLE                  = %SQL_COLUMN_SEARCHABLE
%SQL_DESC_TYPE_NAME                   = %SQL_COLUMN_TYPE_NAME
%SQL_DESC_TABLE_NAME                  = %SQL_COLUMN_TABLE_NAME
%SQL_DESC_UNSIGNED                    = %SQL_COLUMN_UNSIGNED
%SQL_DESC_UPDATABLE                   = %SQL_COLUMN_UPDATABLE
#ENDIF   ' /* ODBCVER >= 0x0300 */

'/* SQLColAttributes subdefines for SQL_COLUMN_UPDATABLE */
%SQL_ATTR_READONLY          = 0
%SQL_ATTR_WRITE             = 1
%SQL_ATTR_READWRITE_UNKNOWN = 2

''/* SQLColAttributes subdefines for SQL_COLUMN_SEARCHABLE */
'/* These are also used by SQLGetInfo                     */
%SQL_UNSEARCHABLE    = 0
'%SQL_LIKE_ONLY       = 1   ' moved above
'%SQL_ALL_EXCEPT_LIKE = 2   ' moved above
%SQL_SEARCHABLE      = 3
%SQL_PRED_SEARCHABLE = %SQL_SEARCHABLE

'/* Special return values for SQLGetData */
%SQL_NO_TOTAL = -4

'/********************************************/
'/* SQLGetFunctions: additional values for   */
'/* fFunction to represent functions that    */
'/* are not in the X/Open spec.            */
'/********************************************/

#IF %ODBCVER >= &H0300
%SQL_API_SQLALLOCHANDLESTD   = 73
%SQL_API_SQLBULKOPERATIONS   = 24
#ENDIF   ' /* ODBCVER >= &H0300 */
%SQL_API_SQLBINDPARAMETER    = 72
%SQL_API_SQLBROWSECONNECT    = 55
%SQL_API_SQLCOLATTRIBUTES    = 6
%SQL_API_SQLCOLUMNPRIVILEGES = 56
%SQL_API_SQLDESCRIBEPARAM    = 58
%SQL_API_SQLDRIVERCONNECT    = 41
%SQL_API_SQLDRIVERS          = 71
%SQL_API_SQLEXTENDEDFETCH    = 59
%SQL_API_SQLFOREIGNKEYS      = 60
%SQL_API_SQLMORERESULTS      = 61
%SQL_API_SQLNATIVESQL        = 62
%SQL_API_SQLNUMPARAMS        = 63
%SQL_API_SQLPARAMOPTIONS     = 64
%SQL_API_SQLPRIMARYKEYS      = 65
%SQL_API_SQLPROCEDURECOLUMNS = 66
%SQL_API_SQLPROCEDURES       = 67
%SQL_API_SQLSETPOS           = 68
%SQL_API_SQLSETSCROLLOPTIONS = 69
%SQL_API_SQLTABLEPRIVILEGES  = 70

'/*-------------------------------------------*/
'/* SQL_EXT_API_LAST is not useful with ODBC  */
'/* version 3.0 because some of the values    */
'/* from X/Open are in the 10000 range.       */
'/*-------------------------------------------*/

#IF %ODBCVER < &H0300
%SQL_EXT_API_LAST   = %SQL_API_SQLBINDPARAMETER
%SQL_NUM_FUNCTIONS  = 23
%SQL_EXT_API_START  = 40
%SQL_NUM_EXTENSIONS = %SQL_EXT_API_LAST - %SQL_EXT_API_START + 1
#ENDIF

'/*--------------------------------------------*/
'/* SQL_API_ALL_FUNCTIONS returns an array     */
'/* of 'booleans' representing whether a       */
'/* function is implemented by the driver.     */
'/*                                            */
'/* CAUTION: Only functions defined in ODBC    */
'/* version 2.0 and earlier are returned, the  */
'/* new high-range function numbers defined by */
'/* X/Open break this scheme.   See the new    */
'/* method -- SQL_API_ODBC3_ALL_FUNCTIONS      */
'/*--------------------------------------------*/

%SQL_API_ALL_FUNCTIONS = 0       ' See CAUTION above */

'/*----------------------------------------------*/
'/* 2.X drivers export a dummy function with     */
'/* ordinal number SQL_API_LOADBYORDINAL to speed*/
'/* loading under the windows operating system.  */
'/*                   */
'/* CAUTION: Loading by ordinal is not supported */
'/* for 3.0 and above drivers.         */
'/*----------------------------------------------*/

%SQL_API_LOADBYORDINAL = 199     ' See CAUTION above */

'/*----------------------------------------------*/
'/* SQL_API_ODBC3_ALL_FUNCTIONS                  */
'/* This returns a bitmap, which allows us to    */
'/* handle the higher-valued function numbers.   */
'/* Use  SQL_FUNC_EXISTS(bitmap,function_number) */
'/* to determine if the function exists.         */
'/*----------------------------------------------*/


#IF %ODBCVER >= &H0300
%SQL_API_ODBC3_ALL_FUNCTIONS      = 999
%SQL_API_ODBC3_ALL_FUNCTIONS_SIZE = 250     ' array of 250 words */

'#define SQL_FUNC_EXISTS(pfExists, uwAPI) \
'            ((*(((UWORD*) (pfExists)) + ((uwAPI) >> 4)) \
'               & (1 << ((uwAPI) & 0x000F)) \
'              ) ? SQL_TRUE : SQL_FALSE \
'            )
#ENDIF   ' /* ODBCVER >= 0x0300 */


'/************************************************/
'/* Extended definitions for SQLGetInfo         */
'/************************************************/

'/*---------------------------------*/
'/* Values in ODBC 2.0 that are not */
'/* in the X/Open spec              */
'/*---------------------------------*/

%SQL_INFO_FIRST                 = 0
%SQL_ACTIVE_CONNECTIONS         = 0     ' MAX_DRIVER_CONNECTIONS */
%SQL_ACTIVE_STATEMENTS          = 1     ' MAX_CONCURRENT_ACTIVITIES */
%SQL_DRIVER_HDBC                = 3
%SQL_DRIVER_HENV                = 4
%SQL_DRIVER_HSTMT               = 5
%SQL_DRIVER_NAME                = 6
%SQL_DRIVER_VER                 = 7
%SQL_ODBC_API_CONFORMANCE       = 9
%SQL_ODBC_VER                   = 10
%SQL_ROW_UPDATES                = 11
%SQL_ODBC_SAG_CLI_CONFORMANCE   = 12
%SQL_ODBC_SQL_CONFORMANCE       = 15
%SQL_PROCEDURES                 = 21
%SQL_CONCAT_NULL_BEHAVIOR       = 22
%SQL_CURSOR_ROLLBACK_BEHAVIOR   = 24
%SQL_EXPRESSIONS_IN_ORDERBY     = 27
%SQL_MAX_OWNER_NAME_LEN         = 32    ' MAX_SCHEMA_NAME_LEN */
%SQL_MAX_PROCEDURE_NAME_LEN     = 33
%SQL_MAX_QUALIFIER_NAME_LEN     = 34    ' MAX_CATALOG_NAME_LEN */
%SQL_MULT_RESULT_SETS           = 36
%SQL_MULTIPLE_ACTIVE_TXN        = 37
%SQL_OUTER_JOINS                = 38
%SQL_OWNER_TERM                 = 39
%SQL_PROCEDURE_TERM             = 40
%SQL_QUALIFIER_NAME_SEPARATOR   = 41
%SQL_QUALIFIER_TERM             = 42
%SQL_SCROLL_OPTIONS             = 44
%SQL_TABLE_TERM                 = 45
%SQL_CONVERT_FUNCTIONS          = 48
%SQL_NUMERIC_FUNCTIONS          = 49
%SQL_STRING_FUNCTIONS           = 50
%SQL_SYSTEM_FUNCTIONS           = 51
%SQL_TIMEDATE_FUNCTIONS         = 52
%SQL_CONVERT_BIGINT             = 53
%SQL_CONVERT_BINARY             = 54
%SQL_CONVERT_BIT                = 55
%SQL_CONVERT_CHAR               = 56
%SQL_CONVERT_DATE               = 57
%SQL_CONVERT_DECIMAL            = 58
%SQL_CONVERT_DOUBLE             = 59
%SQL_CONVERT_FLOAT              = 60
%SQL_CONVERT_INTEGER            = 61
%SQL_CONVERT_LONGVARCHAR        = 62
%SQL_CONVERT_NUMERIC            = 63
%SQL_CONVERT_REAL               = 64
%SQL_CONVERT_SMALLINT           = 65
%SQL_CONVERT_TIME               = 66
%SQL_CONVERT_TIMESTAMP          = 67
%SQL_CONVERT_TINYINT            = 68
%SQL_CONVERT_VARBINARY          = 69
%SQL_CONVERT_VARCHAR            = 70
%SQL_CONVERT_LONGVARBINARY      = 71
%SQL_ODBC_SQL_OPT_IEF           = 73    ' SQL_INTEGRITY */
%SQL_CORRELATION_NAME           = 74
%SQL_NON_NULLABLE_COLUMNS       = 75
%SQL_DRIVER_HLIB                = 76
%SQL_DRIVER_ODBC_VER            = 77
%SQL_LOCK_TYPES                 = 78
%SQL_POS_OPERATIONS             = 79
%SQL_POSITIONED_STATEMENTS      = 80
%SQL_BOOKMARK_PERSISTENCE       = 82
%SQL_STATIC_SENSITIVITY         = 83
%SQL_FILE_USAGE                 = 84
%SQL_COLUMN_ALIAS               = 87
%SQL_GROUP_BY                   = 88
%SQL_KEYWORDS                   = 89
%SQL_OWNER_USAGE                = 91
%SQL_QUALIFIER_USAGE            = 92
%SQL_QUOTED_IDENTIFIER_CASE     = 93
%SQL_SUBQUERIES                 = 95
%SQL_UNION                      = 96
%SQL_MAX_ROW_SIZE_INCLUDES_LONG = 103
%SQL_MAX_CHAR_LITERAL_LEN       = 108
%SQL_TIMEDATE_ADD_INTERVALS     = 109
%SQL_TIMEDATE_DIFF_INTERVALS    = 110
%SQL_NEED_LONG_DATA_LEN         = 111
%SQL_MAX_BINARY_LITERAL_LEN     = 112
%SQL_LIKE_ESCAPE_CLAUSE         = 113
%SQL_QUALIFIER_LOCATION         = 114

'#if (ODBCVER >= 0x0201 && ODBCVER < 0x0300)
#IF %ODBCVER >= &H201
#IF %ODBCVER < &H300
%SQL_OJ_CAPABILITIES         = 65003  ' /* Temp value until ODBC 3.0 */
#ENDIF   ' /* ODBCVER >= 0x0201 && ODBCVER < 0x0300 */

'/*----------------------------------------------*/
'/* SQL_INFO_LAST and SQL_INFO_DRIVER_START are  */
'/* not useful anymore, because  X/Open has      */
'/* values in the 10000 range.   You           */
'/* must contact X/Open directly to get a range   */
'/* of numbers for driver-specific values.       */
'/*----------------------------------------------*/

#IF %ODBCVER < &H0300
%SQL_INFO_LAST                 = %SQL_QUALIFIER_LOCATION
%SQL_INFO_DRIVER_START         = 1000
#ENDIF   ' /* ODBCVER < &H0300 */

'/*-----------------------------------------------*/
'/* ODBC 3.0 SQLGetInfo values that are not part  */
'/* of the X/Open standard at this time.   X/Open */
'/* standard values are in sql.h.             */
'/*-----------------------------------------------*/

#IF %ODBCVER >= &H0300
%SQL_ACTIVE_ENVIRONMENTS               = 116
%SQL_ALTER_DOMAIN                      = 117

%SQL_SQL_CONFORMANCE                   = 118
%SQL_DATETIME_LITERALS                 = 119

%SQL_ASYNC_MODE                        = 10021    ' new X/Open spec */
%SQL_BATCH_ROW_COUNT                   = 120
%SQL_BATCH_SUPPORT                     = 121
%SQL_CATALOG_LOCATION                  = %SQL_QUALIFIER_LOCATION
%SQL_CATALOG_NAME_SEPARATOR            = %SQL_QUALIFIER_NAME_SEPARATOR
%SQL_CATALOG_TERM                      = %SQL_QUALIFIER_TERM
%SQL_CATALOG_USAGE                     = %SQL_QUALIFIER_USAGE
%SQL_CONVERT_WCHAR                     = 122
%SQL_CONVERT_INTERVAL_DAY_TIME         = 123
%SQL_CONVERT_INTERVAL_YEAR_MONTH       = 124
%SQL_CONVERT_WLONGVARCHAR              = 125
%SQL_CONVERT_WVARCHAR                  = 126
%SQL_CREATE_ASSERTION                  = 127
%SQL_CREATE_CHARACTER_SET              = 128
%SQL_CREATE_COLLATION                  = 129
%SQL_CREATE_DOMAIN                     = 130
%SQL_CREATE_SCHEMA                     = 131
%SQL_CREATE_TABLE                      = 132
%SQL_CREATE_TRANSLATION                = 133
%SQL_CREATE_VIEW                       = 134
%SQL_DRIVER_HDESC                      = 135
%SQL_DROP_ASSERTION                    = 136
%SQL_DROP_CHARACTER_SET                = 137
%SQL_DROP_COLLATION                    = 138
%SQL_DROP_DOMAIN                       = 139
%SQL_DROP_SCHEMA                       = 140
%SQL_DROP_TABLE                        = 141
%SQL_DROP_TRANSLATION                  = 142
%SQL_DROP_VIEW                         = 143
%SQL_DYNAMIC_CURSOR_ATTRIBUTES1        = 144
%SQL_DYNAMIC_CURSOR_ATTRIBUTES2        = 145
%SQL_FORWARD_ONLY_CURSOR_ATTRIBUTES1   = 146
%SQL_FORWARD_ONLY_CURSOR_ATTRIBUTES2   = 147
%SQL_INDEX_KEYWORDS                    = 148
%SQL_INFO_SCHEMA_VIEWS                 = 149
%SQL_KEYSET_CURSOR_ATTRIBUTES1         = 150
%SQL_KEYSET_CURSOR_ATTRIBUTES2         = 151
%SQL_MAX_ASYNC_CONCURRENT_STATEMENTS   = 10022  ' new X/Open spec */
%SQL_ODBC_INTERFACE_CONFORMANCE        = 152
%SQL_PARAM_ARRAY_ROW_COUNTS            = 153
%SQL_PARAM_ARRAY_SELECTS               = 154
%SQL_SCHEMA_TERM                       = %SQL_OWNER_TERM
%SQL_SCHEMA_USAGE                      = %SQL_OWNER_USAGE
%SQL_SQL92_DATETIME_FUNCTIONS          = 155
%SQL_SQL92_FOREIGN_KEY_DELETE_RULE     = 156
%SQL_SQL92_FOREIGN_KEY_UPDATE_RULE     = 157
%SQL_SQL92_GRANT                       = 158
%SQL_SQL92_NUMERIC_VALUE_FUNCTIONS     = 159
%SQL_SQL92_PREDICATES                  = 160
%SQL_SQL92_RELATIONAL_JOIN_OPERATORS   = 161
%SQL_SQL92_REVOKE                      = 162
%SQL_SQL92_ROW_VALUE_CONSTRUCTOR       = 163
%SQL_SQL92_STRING_FUNCTIONS            = 164
%SQL_SQL92_VALUE_EXPRESSIONS           = 165
%SQL_STANDARD_CLI_CONFORMANCE          = 166
%SQL_STATIC_CURSOR_ATTRIBUTES1         = 167
%SQL_STATIC_CURSOR_ATTRIBUTES2         = 168

%SQL_AGGREGATE_FUNCTIONS               = 169
%SQL_DDL_INDEX                         = 170
%SQL_DM_VER                            = 171
%SQL_INSERT_STATEMENT                  = 172
%SQL_CONVERT_GUID                      = 173
%SQL_UNION_STATEMENT                   = %SQL_UNION
#ENDIF   ' /* ODBCVER >= &H0300 */

#IF %ODBCVER >= &H0380
'// Info Types
%SQL_ASYNC_DBC_FUNCTIONS               = 10023
#ENDIF   ' // ODBCVER >= 0x0380

%SQL_DTC_TRANSITION_COST               = 1750

'/* SQL_ALTER_TABLE bitmasks */
#IF %ODBCVER >= &H0300
'/* the following 5 bitmasks are defined in sql.h
'#define SQL_AT_ADD_COLUMN                      0x00000001L
'#define SQL_AT_DROP_COLUMN                     0x00000002L
'#define SQL_AT_ADD_CONSTRAINT                  0x00000008L
'/
%SQL_AT_ADD_COLUMN_SINGLE              = &H00000020&
%SQL_AT_ADD_COLUMN_DEFAULT             = &H00000040&
%SQL_AT_ADD_COLUMN_COLLATION           = &H00000080&
%SQL_AT_SET_COLUMN_DEFAULT             = &H00000100&
%SQL_AT_DROP_COLUMN_DEFAULT            = &H00000200&
%SQL_AT_DROP_COLUMN_CASCADE            = &H00000400&
%SQL_AT_DROP_COLUMN_RESTRICT           = &H00000800&
%SQL_AT_ADD_TABLE_CONSTRAINT           = &H00001000&
%SQL_AT_DROP_TABLE_CONSTRAINT_CASCADE  = &H00002000&
%SQL_AT_DROP_TABLE_CONSTRAINT_RESTRICT = &H00004000&
%SQL_AT_CONSTRAINT_NAME_DEFINITION     = &H00008000&
%SQL_AT_CONSTRAINT_INITIALLY_DEFERRED  = &H00010000&
%SQL_AT_CONSTRAINT_INITIALLY_IMMEDIATE = &H00020000&
%SQL_AT_CONSTRAINT_DEFERRABLE          = &H00040000&
%SQL_AT_CONSTRAINT_NON_DEFERRABLE      = &H00080000&
#ENDIF   ' /* ODBCVER >= &H0300 */

'/* SQL_CONVERT_*  return value bitmasks */

%SQL_CVT_CHAR                = &H00000001&
%SQL_CVT_NUMERIC             = &H00000002&
%SQL_CVT_DECIMAL             = &H00000004&
%SQL_CVT_INTEGER             = &H00000008&
%SQL_CVT_SMALLINT            = &H00000010&
%SQL_CVT_FLOAT               = &H00000020&
%SQL_CVT_REAL                = &H00000040&
%SQL_CVT_DOUBLE              = &H00000080&
%SQL_CVT_VARCHAR             = &H00000100&
%SQL_CVT_LONGVARCHAR         = &H00000200&
%SQL_CVT_BINARY              = &H00000400&
%SQL_CVT_VARBINARY           = &H00000800&
%SQL_CVT_BIT                 = &H00001000&
%SQL_CVT_TINYINT             = &H00002000&
%SQL_CVT_BIGINT              = &H00004000&
%SQL_CVT_DATE                = &H00008000&
%SQL_CVT_TIME                = &H00010000&
%SQL_CVT_TIMESTAMP           = &H00020000&
%SQL_CVT_LONGVARBINARY       = &H00040000&
%SQL_CVT_INTERVAL_YEAR_MONTH = &H00080000&
%SQL_CVT_INTERVAL_DAY_TIME   = &H00100000&
%SQL_CVT_WCHAR               = &H00200000&
%SQL_CVT_WLONGVARCHAR        = &H00400000&
%SQL_CVT_WVARCHAR            = &H00800000&
%SQL_CVT_GUID                = &H01000000&
#IF %ODBCVER >= &H0300
%SQL_CVT_INTERVAL_YEAR_MONTH = &H00080000&
%SQL_CVT_INTERVAL_DAY_TIME   = &H00100000&
%SQL_CVT_WCHAR               = &H00200000&
%SQL_CVT_WLONGVARCHAR        = &H00400000&
%SQL_CVT_WVARCHAR            = &H00800000&
%SQL_CVT_GUID                = &H01000000&
#ENDIF   ' /* ODBCVER >= &H0300 */


'/* SQL_CONVERT_FUNCTIONS functions */
%SQL_FN_CVT_CONVERT = &H00000001&
#IF %ODBCVER >= &H0300
%SQL_FN_CVT_CAST    = &H00000002&
#ENDIF   ' /* ODBCVER >= &H0300 */


'/* SQL_STRING_FUNCTIONS functions */

%SQL_FN_STR_CONCAT           = &H00000001&
%SQL_FN_STR_INSERT           = &H00000002&
%SQL_FN_STR_LEFT             = &H00000004&
%SQL_FN_STR_LTRIM            = &H00000008&
%SQL_FN_STR_LENGTH           = &H00000010&
%SQL_FN_STR_LOCATE           = &H00000020&
%SQL_FN_STR_LCASE            = &H00000040&
%SQL_FN_STR_REPEAT           = &H00000080&
%SQL_FN_STR_REPLACE          = &H00000100&
%SQL_FN_STR_RIGHT            = &H00000200&
%SQL_FN_STR_RTRIM            = &H00000400&
%SQL_FN_STR_SUBSTRING        = &H00000800&
%SQL_FN_STR_UCASE            = &H00001000&
%SQL_FN_STR_ASCII            = &H00002000&
%SQL_FN_STR_CHAR             = &H00004000&
%SQL_FN_STR_DIFFERENCE       = &H00008000&
%SQL_FN_STR_LOCATE_2         = &H00010000&
%SQL_FN_STR_SOUNDEX          = &H00020000&
%SQL_FN_STR_SPACE            = &H00040000&
#IF %ODBCVER >= &H0300
%SQL_FN_STR_BIT_LENGTH       = &H00080000&
%SQL_FN_STR_CHAR_LENGTH      = &H00100000&
%SQL_FN_STR_CHARACTER_LENGTH = &H00200000&
%SQL_FN_STR_OCTET_LENGTH     = &H00400000&
%SQL_FN_STR_POSITION         = &H00800000&
#ENDIF   ' /* ODBCVER >= &H0300 */

'/* SQL_SQL92_STRING_FUNCTIONS */
%SQL_SSF_CONVERT       = &H00000001&
%SQL_SSF_LOWER         = &H00000002&
%SQL_SSF_UPPER         = &H00000004&
%SQL_SSF_SUBSTRING     = &H00000008&
%SQL_SSF_TRANSLATE     = &H00000010&
%SQL_SSF_TRIM_BOTH     = &H00000020&
%SQL_SSF_TRIM_LEADING  = &H00000040&
%SQL_SSF_TRIM_TRAILING = &H00000080&
#ENDIF   ' /* ODBCVER >= &H0300 */

'/* SQL_NUMERIC_FUNCTIONS functions */

%SQL_FN_NUM_ABS      = &H00000001&
%SQL_FN_NUM_ACOS     = &H00000002&
%SQL_FN_NUM_ASIN     = &H00000004&
%SQL_FN_NUM_ATAN     = &H00000008&
%SQL_FN_NUM_ATAN2    = &H00000010&
%SQL_FN_NUM_CEILING  = &H00000020&
%SQL_FN_NUM_COS      = &H00000040&
%SQL_FN_NUM_COT      = &H00000080&
%SQL_FN_NUM_EXP      = &H00000100&
%SQL_FN_NUM_FLOOR    = &H00000200&
%SQL_FN_NUM_LOG      = &H00000400&
%SQL_FN_NUM_MOD      = &H00000800&
%SQL_FN_NUM_SIGN     = &H00001000&
%SQL_FN_NUM_SIN      = &H00002000&
%SQL_FN_NUM_SQRT     = &H00004000&
%SQL_FN_NUM_TAN      = &H00008000&
%SQL_FN_NUM_PI       = &H00010000&
%SQL_FN_NUM_RAND     = &H00020000&
%SQL_FN_NUM_DEGREES  = &H00040000&
%SQL_FN_NUM_LOG10    = &H00080000&
%SQL_FN_NUM_POWER    = &H00100000&
%SQL_FN_NUM_RADIANS  = &H00200000&
%SQL_FN_NUM_ROUND    = &H00400000&
%SQL_FN_NUM_TRUNCATE = &H00800000&

'/* SQL_SQL92_NUMERIC_VALUE_FUNCTIONS */
#IF %ODBCVER >= &H0300
%SQL_SNVF_BIT_LENGTH       = &H00000001&
%SQL_SNVF_CHAR_LENGTH      = &H00000002&
%SQL_SNVF_CHARACTER_LENGTH = &H00000004&
%SQL_SNVF_EXTRACT          = &H00000008&
%SQL_SNVF_OCTET_LENGTH     = &H00000010&
%SQL_SNVF_POSITION         = &H00000020&
#ENDIF   ' /* ODBCVER >= &H0300 */

'/* SQL_TIMEDATE_FUNCTIONS functions */

%SQL_FN_TD_NOW               = &H00000001&
%SQL_FN_TD_CURDATE           = &H00000002&
%SQL_FN_TD_DAYOFMONTH        = &H00000004&
%SQL_FN_TD_DAYOFWEEK         = &H00000008&
%SQL_FN_TD_DAYOFYEAR         = &H00000010&
%SQL_FN_TD_MONTH             = &H00000020&
%SQL_FN_TD_QUARTER           = &H00000040&
%SQL_FN_TD_WEEK              = &H00000080&
%SQL_FN_TD_YEAR              = &H00000100&
%SQL_FN_TD_CURTIME           = &H00000200&
%SQL_FN_TD_HOUR              = &H00000400&
%SQL_FN_TD_MINUTE            = &H00000800&
%SQL_FN_TD_SECOND            = &H00001000&
%SQL_FN_TD_TIMESTAMPADD      = &H00002000&
%SQL_FN_TD_TIMESTAMPDIFF     = &H00004000&
%SQL_FN_TD_DAYNAME           = &H00008000&
%SQL_FN_TD_MONTHNAME         = &H00010000&
#IF %ODBCVER >= &H0300
%SQL_FN_TD_CURRENT_DATE      = &H00020000&
%SQL_FN_TD_CURRENT_TIME      = &H00040000&
%SQL_FN_TD_CURRENT_TIMESTAMP = &H00080000&
%SQL_FN_TD_EXTRACT           = &H00100000&
#ENDIF   ' /* ODBCVER >= &H0300 */

'/* SQL_SQL92_DATETIME_FUNCTIONS */
#IF %ODBCVER >= &H0300
%SQL_SDF_CURRENT_DATE      = &H00000001&
%SQL_SDF_CURRENT_TIME      = &H00000002&
%SQL_SDF_CURRENT_TIMESTAMP = &H00000004&
#ENDIF   ' /* ODBCVER >= &H0300 */

'/* SQL_SYSTEM_FUNCTIONS functions */

%SQL_FN_SYS_USERNAME = &H00000001&
%SQL_FN_SYS_DBNAME   = &H00000002&
%SQL_FN_SYS_IFNULL   = &H00000004&

'/* SQL_TIMEDATE_ADD_INTERVALS and SQL_TIMEDATE_DIFF_INTERVALS functions */

%SQL_FN_TSI_FRAC_SECOND = &H00000001&
%SQL_FN_TSI_SECOND      = &H00000002&
%SQL_FN_TSI_MINUTE      = &H00000004&
%SQL_FN_TSI_HOUR        = &H00000008&
%SQL_FN_TSI_DAY         = &H00000010&
%SQL_FN_TSI_WEEK        = &H00000020&
%SQL_FN_TSI_MONTH       = &H00000040&
%SQL_FN_TSI_QUARTER     = &H00000080&
%SQL_FN_TSI_YEAR        = &H00000100&

'/* bitmasks for SQL_DYNAMIC_CURSOR_ATTRIBUTES1,
' * SQL_FORWARD_ONLY_CURSOR_ATTRIBUTES1,
' * SQL_KEYSET_CURSOR_ATTRIBUTES1, and SQL_STATIC_CURSOR_ATTRIBUTES1
' */
#IF %ODBCVER >= &H0300
'/* supported SQLFetchScroll FetchOrientation's */
%SQL_CA1_NEXT     = &H00000001&
%SQL_CA1_ABSOLUTE = &H00000002&
%SQL_CA1_RELATIVE = &H00000004&
%SQL_CA1_BOOKMARK = &H00000008&

'/* supported SQLSetPos LockType's */
%SQL_CA1_LOCK_NO_CHANGE = &H00000040&
%SQL_CA1_LOCK_EXCLUSIVE = &H00000080&
%SQL_CA1_LOCK_UNLOCK    = &H00000100&

'/* supported SQLSetPos Operations */
%SQL_CA1_POS_POSITION = &H00000200&
%SQL_CA1_POS_UPDATE   = &H00000400&
%SQL_CA1_POS_DELETE   = &H00000800&
%SQL_CA1_POS_REFRESH  = &H00001000&

'/* positioned updates and deletes */
%SQL_CA1_POSITIONED_UPDATE = &H00002000&
%SQL_CA1_POSITIONED_DELETE = &H00004000&
%SQL_CA1_SELECT_FOR_UPDATE = &H00008000&

'/* supported SQLBulkOperations operations */
%SQL_CA1_BULK_ADD                = &H00010000&
%SQL_CA1_BULK_UPDATE_BY_BOOKMARK = &H00020000&
%SQL_CA1_BULK_DELETE_BY_BOOKMARK = &H00040000&
%SQL_CA1_BULK_FETCH_BY_BOOKMARK  = &H00080000&
#ENDIF   ' /* ODBCVER >= 0x0300 */

'/* bitmasks for SQL_DYNAMIC_CURSOR_ATTRIBUTES2,
' * SQL_FORWARD_ONLY_CURSOR_ATTRIBUTES2,
' * SQL_KEYSET_CURSOR_ATTRIBUTES2, and SQL_STATIC_CURSOR_ATTRIBUTES2
' */
#IF %ODBCVER >= &H0300
'/* supported values for SQL_ATTR_SCROLL_CONCURRENCY */
%SQL_CA2_READ_ONLY_CONCURRENCY  = &H00000001&
%SQL_CA2_LOCK_CONCURRENCY       = &H00000002&
%SQL_CA2_OPT_ROWVER_CONCURRENCY = &H00000004&
%SQL_CA2_OPT_VALUES_CONCURRENCY = &H00000008&

'/* sensitivity of the cursor to its own inserts, deletes, and updates */
%SQL_CA2_SENSITIVITY_ADDITIONS = &H00000010&
%SQL_CA2_SENSITIVITY_DELETIONS = &H00000020&
%SQL_CA2_SENSITIVITY_UPDATES   = &H00000040&

'/* semantics of SQL_ATTR_MAX_ROWS */
%SQL_CA2_MAX_ROWS_SELECT      = &H00000080&
%SQL_CA2_MAX_ROWS_INSERT      = &H00000100&
%SQL_CA2_MAX_ROWS_DELETE      = &H00000200&
%SQL_CA2_MAX_ROWS_UPDATE      = &H00000400&
%SQL_CA2_MAX_ROWS_CATALOG     = &H00000800&
%SQL_CA2_MAX_ROWS_AFFECTS_ALL = %SQL_CA2_MAX_ROWS_SELECT OR _
                                %SQL_CA2_MAX_ROWS_INSERT OR _
                                %SQL_CA2_MAX_ROWS_DELETE OR _
                                %SQL_CA2_MAX_ROWS_UPDATE OR _
                                %SQL_CA2_MAX_ROWS_CATALOG

'/* semantics of SQL_DIAG_CURSOR_ROW_COUNT */
%SQL_CA2_CRC_EXACT       = &H00001000&
%SQL_CA2_CRC_APPROXIMATE = &H00002000&

'/* the kinds of positioned statements that can be simulated */
%SQL_CA2_SIMULATE_NON_UNIQUE = &H00004000&
%SQL_CA2_SIMULATE_TRY_UNIQUE = &H00008000&
%SQL_CA2_SIMULATE_UNIQUE     = &H00010000&
#ENDIF   ' /* ODBCVER >= 0x0300 */

'/* SQL_ODBC_API_CONFORMANCE values */

%SQL_OAC_NONE   = &H0000
%SQL_OAC_LEVEL1 = &H0001
%SQL_OAC_LEVEL2 = &H0002

'/* SQL_ODBC_SAG_CLI_CONFORMANCE values */

%SQL_OSCC_NOT_COMPLIANT = &H0000
%SQL_OSCC_COMPLIANT     = &H0001

'/* SQL_ODBC_SQL_CONFORMANCE values */

%SQL_OSC_MINIMUM  = &H0000
%SQL_OSC_CORE     = &H0001
%SQL_OSC_EXTENDED = &H0002


'/* SQL_CONCAT_NULL_BEHAVIOR values */

%SQL_CB_NULL     = &H0000
%SQL_CB_NON_NULL = &H0001

'/* SQL_SCROLL_OPTIONS masks */

%SQL_SO_FORWARD_ONLY  = &H00000001&
%SQL_SO_KEYSET_DRIVEN = &H00000002&
%SQL_SO_DYNAMIC       = &H00000004&
%SQL_SO_MIXED         = &H00000008&
%SQL_SO_STATIC        = &H00000010&

'/* SQL_FETCH_DIRECTION masks */

'/* SQL_FETCH_RESUME is no longer supported
'%SQL_FD_FETCH_RESUME   = &H00000040&
'*/
%SQL_FD_FETCH_BOOKMARK = &H00000080&

'/* SQL_TXN_ISOLATION_OPTION masks */
'/* SQL_TXN_VERSIONING is no longer supported
'%SQL_TXN_VERSIONING    = &H00000010&
'*/

'/* SQL_CORRELATION_NAME values */

%SQL_CN_NONE      = &H0000
%SQL_CN_DIFFERENT = &H0001
%SQL_CN_ANY       = &H0002

'/* SQL_NON_NULLABLE_COLUMNS values */

%SQL_NNC_NULL     = &H0000
%SQL_NNC_NON_NULL = &H0001

'/* SQL_NULL_COLLATION values */

%SQL_NC_START = &H0002
%SQL_NC_END   = &H0004

'/* SQL_FILE_USAGE values */

%SQL_FILE_NOT_SUPPORTED = &H0000
%SQL_FILE_TABLE         = &H0001
%SQL_FILE_QUALIFIER     = &H0002
%SQL_FILE_CATALOG       = %SQL_FILE_QUALIFIER   ' ODBC 3.0


'/* SQL_GETDATA_EXTENSIONS values */

%SQL_GD_BLOCK = &H00000004&
%SQL_GD_BOUND = &H00000008&
#IF %ODBCVER >= &H0380
%SQL_GD_OUTPUT_PARAMS = &H00000010&
#ENDIF

'/* SQL_POSITIONED_STATEMENTS masks */

%SQL_PS_POSITIONED_DELETE = &H00000001&
%SQL_PS_POSITIONED_UPDATE = &H00000002&
%SQL_PS_SELECT_FOR_UPDATE = &H00000004&

'/* SQL_GROUP_BY values */

%SQL_GB_NOT_SUPPORTED            = &H0000
%SQL_GB_GROUP_BY_EQUALS_SELECT   = &H0001
%SQL_GB_GROUP_BY_CONTAINS_SELECT = &H0002
%SQL_GB_NO_RELATION              = &H0003
#IF %ODBCVER >= &H0300
%SQL_GB_COLLATE                  = &H0004
#ENDIF   ' /* ODBCVER >= 0x0300 */

'/* SQL_OWNER_USAGE masks */

%SQL_OU_DML_STATEMENTS       = &H00000001&
%SQL_OU_PROCEDURE_INVOCATION = &H00000002&
%SQL_OU_TABLE_DEFINITION     = &H00000004&
%SQL_OU_INDEX_DEFINITION     = &H00000008&
%SQL_OU_PRIVILEGE_DEFINITION = &H00000010&

'/* SQL_SCHEMA_USAGE masks */
#IF %ODBCVER >= &H0300
%SQL_SU_DML_STATEMENTS       = %SQL_OU_DML_STATEMENTS
%SQL_SU_PROCEDURE_INVOCATION = %SQL_OU_PROCEDURE_INVOCATION
%SQL_SU_TABLE_DEFINITION     = %SQL_OU_TABLE_DEFINITION
%SQL_SU_INDEX_DEFINITION     = %SQL_OU_INDEX_DEFINITION
%SQL_SU_PRIVILEGE_DEFINITION = %SQL_OU_PRIVILEGE_DEFINITION
#ENDIF   ' /* ODBCVER >= &H0300 */

'/* SQL_QUALIFIER_USAGE masks */

%SQL_QU_DML_STATEMENTS       = &H00000001&
%SQL_QU_PROCEDURE_INVOCATION = &H00000002&
%SQL_QU_TABLE_DEFINITION     = &H00000004&
%SQL_QU_INDEX_DEFINITION     = &H00000008&
%SQL_QU_PRIVILEGE_DEFINITION = &H00000010&

#IF %ODBCVER >= &H0300
'/* SQL_CATALOG_USAGE masks */
%SQL_CU_DML_STATEMENTS       = %SQL_QU_DML_STATEMENTS
%SQL_CU_PROCEDURE_INVOCATION = %SQL_QU_PROCEDURE_INVOCATION
%SQL_CU_TABLE_DEFINITION     = %SQL_QU_TABLE_DEFINITION
%SQL_CU_INDEX_DEFINITION     = %SQL_QU_INDEX_DEFINITION
%SQL_CU_PRIVILEGE_DEFINITION = %SQL_QU_PRIVILEGE_DEFINITION
#ENDIF   ' /* ODBCVER >= &H0300 */

'/* SQL_SUBQUERIES masks */

%SQL_SQ_COMPARISON            = &H00000001&
%SQL_SQ_EXISTS                = &H00000002&
%SQL_SQ_IN                    = &H00000004&
%SQL_SQ_QUANTIFIED            = &H00000008&
%SQL_SQ_CORRELATED_SUBQUERIES = &H00000010&

'/* SQL_UNION masks */

%SQL_U_UNION     = &H00000001&
%SQL_U_UNION_ALL = &H00000002&

'/* SQL_BOOKMARK_PERSISTENCE values */

%SQL_BP_CLOSE       = &H00000001&
%SQL_BP_DELETE      = &H00000002&
%SQL_BP_DROP        = &H00000004&
%SQL_BP_TRANSACTION = &H00000008&
%SQL_BP_UPDATE      = &H00000010&
%SQL_BP_OTHER_HSTMT = &H00000020&
%SQL_BP_SCROLL      = &H00000040&

'/* SQL_STATIC_SENSITIVITY values */

%SQL_SS_ADDITIONS = &H00000001&
%SQL_SS_DELETIONS = &H00000002&
%SQL_SS_UPDATES   = &H00000004&

'/* SQL_VIEW values */
%SQL_CV_CREATE_VIEW  = &H00000001&
%SQL_CV_CHECK_OPTION = &H00000002&
%SQL_CV_CASCADED     = &H00000004&
%SQL_CV_LOCAL        = &H00000008&

'/* SQL_LOCK_TYPES masks */

%SQL_LCK_NO_CHANGE = &H00000001&
%SQL_LCK_EXCLUSIVE = &H00000002&
%SQL_LCK_UNLOCK    = &H00000004&

'/* SQL_POS_OPERATIONS masks */

%SQL_POS_POSITION = &H00000001&
%SQL_POS_REFRESH  = &H00000002&
%SQL_POS_UPDATE   = &H00000004&
%SQL_POS_DELETE   = &H00000008&
%SQL_POS_ADD      = &H00000010&

'/* SQL_QUALIFIER_LOCATION values */

%SQL_QL_START = &H0001
%SQL_QL_END   = &H0002

'/* Here start return values for ODBC 3.0 SQLGetInfo */

#IF %ODBCVER >= &H0300
'/* SQL_AGGREGATE_FUNCTIONS bitmasks */
%SQL_AF_AVG      = &H00000001&
%SQL_AF_COUNT    = &H00000002&
%SQL_AF_MAX      = &H00000004&
%SQL_AF_MIN      = &H00000008&
%SQL_AF_SUM      = &H00000010&
%SQL_AF_DISTINCT = &H00000020&
%SQL_AF_ALL      = &H00000040&

'/* SQL_SQL_CONFORMANCE bit masks */
%SQL_SC_SQL92_ENTRY            = &H00000001&
%SQL_SC_FIPS127_2_TRANSITIONAL = &H00000002&
%SQL_SC_SQL92_INTERMEDIATE     = &H00000004&
%SQL_SC_SQL92_FULL             = &H00000008&

'/* SQL_DATETIME_LITERALS masks */
%SQL_DL_SQL92_DATE                      = &H00000001&
%SQL_DL_SQL92_TIME                      = &H00000002&
%SQL_DL_SQL92_TIMESTAMP                 = &H00000004&
%SQL_DL_SQL92_INTERVAL_YEAR             = &H00000008&
%SQL_DL_SQL92_INTERVAL_MONTH            = &H00000010&
%SQL_DL_SQL92_INTERVAL_DAY              = &H00000020&
%SQL_DL_SQL92_INTERVAL_HOUR             = &H00000040&
%SQL_DL_SQL92_INTERVAL_MINUTE           = &H00000080&
%SQL_DL_SQL92_INTERVAL_SECOND           = &H00000100&
%SQL_DL_SQL92_INTERVAL_YEAR_TO_MONTH    = &H00000200&
%SQL_DL_SQL92_INTERVAL_DAY_TO_HOUR      = &H00000400&
%SQL_DL_SQL92_INTERVAL_DAY_TO_MINUTE    = &H00000800&
%SQL_DL_SQL92_INTERVAL_DAY_TO_SECOND    = &H00001000&
%SQL_DL_SQL92_INTERVAL_HOUR_TO_MINUTE   = &H00002000&
%SQL_DL_SQL92_INTERVAL_HOUR_TO_SECOND   = &H00004000&
%SQL_DL_SQL92_INTERVAL_MINUTE_TO_SECOND = &H00008000&

'/* SQL_CATALOG_LOCATION values */
%SQL_CL_START = %SQL_QL_START
%SQL_CL_END   = %SQL_QL_END

'/* values for SQL_BATCH_ROW_COUNT */
%SQL_BRC_PROCEDURES = &H0000001
%SQL_BRC_EXPLICIT   = &H0000002
%SQL_BRC_ROLLED_UP  = &H0000004

'/* bitmasks for SQL_BATCH_SUPPORT */
%SQL_BS_SELECT_EXPLICIT    = &H00000001&
%SQL_BS_ROW_COUNT_EXPLICIT = &H00000002&
%SQL_BS_SELECT_PROC        = &H00000004&
%SQL_BS_ROW_COUNT_PROC     = &H00000008&

'/* Values for SQL_PARAM_ARRAY_ROW_COUNTS getinfo */
%SQL_PARC_BATCH    = 1
%SQL_PARC_NO_BATCH = 2

'/* values for SQL_PARAM_ARRAY_SELECTS */
%SQL_PAS_BATCH     = 1
%SQL_PAS_NO_BATCH  = 2
%SQL_PAS_NO_SELECT = 3

'/* Bitmasks for SQL_INDEX_KEYWORDS */
%SQL_IK_NONE = &H00000000&
%SQL_IK_ASC  = &H00000001&
%SQL_IK_DESC = &H00000002&
%SQL_IK_ALL  = %SQL_IK_ASC OR %SQL_IK_DESC

'/* Bitmasks for SQL_INFO_SCHEMA_VIEWS */

%SQL_ISV_ASSERTIONS              = &H00000001&
%SQL_ISV_CHARACTER_SETS          = &H00000002&
%SQL_ISV_CHECK_CONSTRAINTS       = &H00000004&
%SQL_ISV_COLLATIONS              = &H00000008&
%SQL_ISV_COLUMN_DOMAIN_USAGE     = &H00000010&
%SQL_ISV_COLUMN_PRIVILEGES       = &H00000020&
%SQL_ISV_COLUMNS                 = &H00000040&
%SQL_ISV_CONSTRAINT_COLUMN_USAGE = &H00000080&
%SQL_ISV_CONSTRAINT_TABLE_USAGE  = &H00000100&
%SQL_ISV_DOMAIN_CONSTRAINTS      = &H00000200&
%SQL_ISV_DOMAINS                 = &H00000400&
%SQL_ISV_KEY_COLUMN_USAGE        = &H00000800&
%SQL_ISV_REFERENTIAL_CONSTRAINTS = &H00001000&
%SQL_ISV_SCHEMATA                = &H00002000&
%SQL_ISV_SQL_LANGUAGES           = &H00004000&
%SQL_ISV_TABLE_CONSTRAINTS       = &H00008000&
%SQL_ISV_TABLE_PRIVILEGES        = &H00010000&
%SQL_ISV_TABLES                  = &H00020000&
%SQL_ISV_TRANSLATIONS            = &H00040000&
%SQL_ISV_USAGE_PRIVILEGES        = &H00080000&
%SQL_ISV_VIEW_COLUMN_USAGE       = &H00100000&
%SQL_ISV_VIEW_TABLE_USAGE        = &H00200000&
%SQL_ISV_VIEWS                   = &H00400000&

'/* Bitmasks for SQL_ASYNC_MODE */

%SQL_AM_NONE         = 0
%SQL_AM_CONNECTION   = 1
%SQL_AM_STATEMENT    = 2

'/* Bitmasks for SQL_ALTER_DOMAIN */
%SQL_AD_CONSTRAINT_NAME_DEFINITION         = &H00000001&
%SQL_AD_ADD_DOMAIN_CONSTRAINT              = &H00000002&
%SQL_AD_DROP_DOMAIN_CONSTRAINT             = &H00000004&
%SQL_AD_ADD_DOMAIN_DEFAULT                 = &H00000008&
%SQL_AD_DROP_DOMAIN_DEFAULT                = &H00000010&
%SQL_AD_ADD_CONSTRAINT_INITIALLY_DEFERRED  = &H00000020&
%SQL_AD_ADD_CONSTRAINT_INITIALLY_IMMEDIATE = &H00000040&
%SQL_AD_ADD_CONSTRAINT_DEFERRABLE          = &H00000080&
%SQL_AD_ADD_CONSTRAINT_NON_DEFERRABLE      = &H00000100&


'/* SQL_CREATE_SCHEMA bitmasks */
%SQL_CS_CREATE_SCHEMA         = &H00000001&
%SQL_CS_AUTHORIZATION         = &H00000002&
%SQL_CS_DEFAULT_CHARACTER_SET = &H00000004&

'/* SQL_CREATE_TRANSLATION bitmasks */
%SQL_CTR_CREATE_TRANSLATION = &H00000001&

'/* SQL_CREATE_ASSERTION bitmasks */
%SQL_CA_CREATE_ASSERTION               = &H00000001&
%SQL_CA_CONSTRAINT_INITIALLY_DEFERRED  = &H00000010&
%SQL_CA_CONSTRAINT_INITIALLY_IMMEDIATE = &H00000020&
%SQL_CA_CONSTRAINT_DEFERRABLE          = &H00000040&
%SQL_CA_CONSTRAINT_NON_DEFERRABLE      = &H00000080&

'/* SQL_CREATE_CHARACTER_SET bitmasks */
%SQL_CCS_CREATE_CHARACTER_SET = &H00000001&
%SQL_CCS_COLLATE_CLAUSE       = &H00000002&
%SQL_CCS_LIMITED_COLLATION    = &H00000004&

'/* SQL_CREATE_COLLATION bitmasks */
%SQL_CCOL_CREATE_COLLATION = &H00000001&

'/* SQL_CREATE_DOMAIN bitmasks */
%SQL_CDO_CREATE_DOMAIN                  = &H00000001&
%SQL_CDO_DEFAULT                        = &H00000002&
%SQL_CDO_CONSTRAINT                     = &H00000004&
%SQL_CDO_COLLATION                      = &H00000008&
%SQL_CDO_CONSTRAINT_NAME_DEFINITION     = &H00000010&
%SQL_CDO_CONSTRAINT_INITIALLY_DEFERRED  = &H00000020&
%SQL_CDO_CONSTRAINT_INITIALLY_IMMEDIATE = &H00000040&
%SQL_CDO_CONSTRAINT_DEFERRABLE          = &H00000080&
%SQL_CDO_CONSTRAINT_NON_DEFERRABLE      = &H00000100&

'/* SQL_CREATE_TABLE bitmasks */
%SQL_CT_CREATE_TABLE                   = &H00000001&
%SQL_CT_COMMIT_PRESERVE                = &H00000002&
%SQL_CT_COMMIT_DELETE                  = &H00000004&
%SQL_CT_GLOBAL_TEMPORARY               = &H00000008&
%SQL_CT_LOCAL_TEMPORARY                = &H00000010&
%SQL_CT_CONSTRAINT_INITIALLY_DEFERRED  = &H00000020&
%SQL_CT_CONSTRAINT_INITIALLY_IMMEDIATE = &H00000040&
%SQL_CT_CONSTRAINT_DEFERRABLE          = &H00000080&
%SQL_CT_CONSTRAINT_NON_DEFERRABLE      = &H00000100&
%SQL_CT_COLUMN_CONSTRAINT              = &H00000200&
%SQL_CT_COLUMN_DEFAULT                 = &H00000400&
%SQL_CT_COLUMN_COLLATION               = &H00000800&
%SQL_CT_TABLE_CONSTRAINT               = &H00001000&
%SQL_CT_CONSTRAINT_NAME_DEFINITION     = &H00002000&

'/* SQL_DDL_INDEX bitmasks */
%SQL_DI_CREATE_INDEX = &H00000001&
%SQL_DI_DROP_INDEX   = &H00000002&

'/* SQL_DROP_COLLATION bitmasks */
%SQL_DC_DROP_COLLATION = &H00000001&

'/* SQL_DROP_DOMAIN bitmasks */
%SQL_DD_DROP_DOMAIN = &H00000001&
%SQL_DD_RESTRICT    = &H00000002&
%SQL_DD_CASCADE     = &H00000004&

'/* SQL_DROP_SCHEMA bitmasks */
%SQL_DS_DROP_SCHEMA = &H00000001&
%SQL_DS_RESTRICT    = &H00000002&
%SQL_DS_CASCADE     = &H00000004&

'/* SQL_DROP_CHARACTER_SET bitmasks */
%SQL_DCS_DROP_CHARACTER_SET = &H00000001&

'/* SQL_DROP_ASSERTION bitmasks */
%SQL_DA_DROP_ASSERTION = &H00000001&

'/* SQL_DROP_TABLE bitmasks */
%SQL_DT_DROP_TABLE = &H00000001&
%SQL_DT_RESTRICT   = &H00000002&
%SQL_DT_CASCADE    = &H00000004&

'/* SQL_DROP_TRANSLATION bitmasks */
%SQL_DTR_DROP_TRANSLATION = &H00000001&

'/* SQL_DROP_VIEW bitmasks */
%SQL_DV_DROP_VIEW = &H00000001&
%SQL_DV_RESTRICT  = &H00000002&
%SQL_DV_CASCADE   = &H00000004&

'/* SQL_INSERT_STATEMENT bitmasks */
%SQL_IS_INSERT_LITERALS = &H00000001&
%SQL_IS_INSERT_SEARCHED = &H00000002&
%SQL_IS_SELECT_INTO     = &H00000004&

'/* SQL_ODBC_INTERFACE_CONFORMANCE values */
%SQL_OIC_CORE   = 1???
%SQL_OIC_LEVEL1 = 2???
%SQL_OIC_LEVEL2 = 3???

'/* SQL_SQL92_FOREIGN_KEY_DELETE_RULE bitmasks */
%SQL_SFKD_CASCADE     = &H00000001&
%SQL_SFKD_NO_ACTION   = &H00000002&
%SQL_SFKD_SET_DEFAULT = &H00000004&
%SQL_SFKD_SET_NULL    = &H00000008&

'/* SQL_SQL92_FOREIGN_KEY_UPDATE_RULE bitmasks */
%SQL_SFKU_CASCADE     = &H00000001&
%SQL_SFKU_NO_ACTION   = &H00000002&
%SQL_SFKU_SET_DEFAULT = &H00000004&
%SQL_SFKU_SET_NULL    = &H00000008&

'/* SQL_SQL92_GRANT   bitmasks */
%SQL_SG_USAGE_ON_DOMAIN        = &H00000001&
%SQL_SG_USAGE_ON_CHARACTER_SET = &H00000002&
%SQL_SG_USAGE_ON_COLLATION     = &H00000004&
%SQL_SG_USAGE_ON_TRANSLATION   = &H00000008&
%SQL_SG_WITH_GRANT_OPTION      = &H00000010&
%SQL_SG_DELETE_TABLE           = &H00000020&
%SQL_SG_INSERT_TABLE           = &H00000040&
%SQL_SG_INSERT_COLUMN          = &H00000080&
%SQL_SG_REFERENCES_TABLE       = &H00000100&
%SQL_SG_REFERENCES_COLUMN      = &H00000200&
%SQL_SG_SELECT_TABLE           = &H00000400&
%SQL_SG_UPDATE_TABLE           = &H00000800&
%SQL_SG_UPDATE_COLUMN          = &H00001000&

'/* SQL_SQL92_PREDICATES bitmasks */
%SQL_SP_EXISTS                = &H00000001&
%SQL_SP_ISNOTNULL             = &H00000002&
%SQL_SP_ISNULL                = &H00000004&
%SQL_SP_MATCH_FULL            = &H00000008&
%SQL_SP_MATCH_PARTIAL         = &H00000010&
%SQL_SP_MATCH_UNIQUE_FULL     = &H00000020&
%SQL_SP_MATCH_UNIQUE_PARTIAL  = &H00000040&
%SQL_SP_OVERLAPS              = &H00000080&
%SQL_SP_UNIQUE                = &H00000100&
%SQL_SP_LIKE                  = &H00000200&
%SQL_SP_IN                    = &H00000400&
%SQL_SP_BETWEEN               = &H00000800&
%SQL_SP_COMPARISON            = &H00001000&
%SQL_SP_QUANTIFIED_COMPARISON = &H00002000&

'/* SQL_SQL92_RELATIONAL_JOIN_OPERATORS bitmasks */
%SQL_SRJO_CORRESPONDING_CLAUSE = &H00000001&
%SQL_SRJO_CROSS_JOIN           = &H00000002&
%SQL_SRJO_EXCEPT_JOIN          = &H00000004&
%SQL_SRJO_FULL_OUTER_JOIN      = &H00000008&
%SQL_SRJO_INNER_JOIN           = &H00000010&
%SQL_SRJO_INTERSECT_JOIN       = &H00000020&
%SQL_SRJO_LEFT_OUTER_JOIN      = &H00000040&
%SQL_SRJO_NATURAL_JOIN         = &H00000080&
%SQL_SRJO_RIGHT_OUTER_JOIN     = &H00000100&
%SQL_SRJO_UNION_JOIN           = &H00000200&

'/* SQL_SQL92_REVOKE bitmasks */
%SQL_SR_USAGE_ON_DOMAIN        = &H00000001&
%SQL_SR_USAGE_ON_CHARACTER_SET = &H00000002&
%SQL_SR_USAGE_ON_COLLATION     = &H00000004&
%SQL_SR_USAGE_ON_TRANSLATION   = &H00000008&
%SQL_SR_GRANT_OPTION_FOR       = &H00000010&
%SQL_SR_CASCADE                = &H00000020&
%SQL_SR_RESTRICT               = &H00000040&
%SQL_SR_DELETE_TABLE           = &H00000080&
%SQL_SR_INSERT_TABLE           = &H00000100&
%SQL_SR_INSERT_COLUMN          = &H00000200&
%SQL_SR_REFERENCES_TABLE       = &H00000400&
%SQL_SR_REFERENCES_COLUMN      = &H00000800&
%SQL_SR_SELECT_TABLE           = &H00001000&
%SQL_SR_UPDATE_TABLE           = &H00002000&
%SQL_SR_UPDATE_COLUMN          = &H00004000&

'/* SQL_SQL92_ROW_VALUE_CONSTRUCTOR bitmasks */
%SQL_SRVC_VALUE_EXPRESSION = &H00000001&
%SQL_SRVC_NULL             = &H00000002&
%SQL_SRVC_DEFAULT          = &H00000004&
%SQL_SRVC_ROW_SUBQUERY     = &H00000008&

'/* SQL_SQL92_VALUE_EXPRESSIONS bitmasks */
%SQL_SVE_CASE     = &H00000001&
%SQL_SVE_CAST     = &H00000002&
%SQL_SVE_COALESCE = &H00000004&
%SQL_SVE_NULLIF   = &H00000008&

'/* SQL_STANDARD_CLI_CONFORMANCE bitmasks */
%SQL_SCC_XOPEN_CLI_VERSION1 = &H00000001&
%SQL_SCC_ISO92_CLI          = &H00000002&

'/* SQL_UNION_STATEMENT bitmasks */
%SQL_US_UNION     = %SQL_U_UNION
%SQL_US_UNION_ALL = %SQL_U_UNION_ALL

#ENDIF   ' /* ODBCVER >= 0x0300 */

'/* SQL_DTC_TRANSITION_COST bitmasks */
%SQL_DTC_ENLIST_EXPENSIVE   = &H00000001&
%SQL_DTC_UNENLIST_EXPENSIVE = &H00000002&

#IF %ODBCVER >= &H0380
'// possible values for SQL_ASYNC_DBC_FUNCTIONS
%SQL_ASYNC_DBC_NOT_CAPABLE = &H00000000&
%SQL_ASYNC_DBC_CAPABLE     = &H00000001&
#ENDIF   ' // ODBCVER >= 0x0380

'/* additional SQLDataSources fetch directions */
#IF %ODBCVER >= &H0300
%SQL_FETCH_FIRST_USER   = 31
%SQL_FETCH_FIRST_SYSTEM = 32
#ENDIF   ' /* ODBCVER >= 0x0300 */


'/* Defines for SQLSetPos */
%SQL_ENTIRE_ROWSET = 0

'/* Operations in SQLSetPos */
%SQL_POSITION = 0   '      1.0 FALSE */
%SQL_REFRESH  = 1   '      1.0 TRUE */
%SQL_UPDATE   = 2
%SQL_DELETE   = 3

'/* Operations in SQLBulkOperations */
%SQL_ADD                     = 4
%SQL_SETPOS_MAX_OPTION_VALUE = %SQL_ADD
#IF %ODBCVER >= &H0300
%SQL_UPDATE_BY_BOOKMARK      = 5
%SQL_DELETE_BY_BOOKMARK      = 6
%SQL_FETCH_BY_BOOKMARK       = 7
#ENDIF   ' /*  ODBCVER >= &H0300 */

'/* Lock options in SQLSetPos */
%SQL_LOCK_NO_CHANGE = 0   '      1.0 FALSE */
%SQL_LOCK_EXCLUSIVE = 1   '      1.0 TRUE */
%SQL_LOCK_UNLOCK    = 2

%SQL_SETPOS_MAX_LOCK_VALUE = %SQL_LOCK_UNLOCK

'/* Column types and scopes in SQLSpecialColumns.  */
%SQL_BEST_ROWID = 1
%SQL_ROWVER     = 2

'/* Defines for SQLSpecialColumns (returned in the result set)
'   SQL_PC_UNKNOWN and SQL_PC_PSEUDO are defined in sql.h */
%SQL_PC_NOT_PSEUDO = 1

'/* Defines for SQLStatistics */
%SQL_QUICK  = 0
%SQL_ENSURE = 1

'/* Defines for SQLStatistics (returned in the result set)
'   SQL_INDEX_CLUSTERED, SQL_INDEX_HASHED, and SQL_INDEX_OTHER are
'   defined in sql.h */
%SQL_TABLE_STAT = 0


'/* Defines for SQLTables */
#IF %ODBCVER >= &H0300
$SQL_ALL_CATALOGS               = "%"
$SQL_ALL_SCHEMAS                = "%"
$SQL_ALL_TABLE_TYPES            = "%"
#ENDIF   ' /* ODBCVER >= 0x0300 */

'/* Options for SQLDriverConnect */
%SQL_DRIVER_NOPROMPT          = 0
%SQL_DRIVER_COMPLETE          = 1
%SQL_DRIVER_PROMPT            = 2
%SQL_DRIVER_COMPLETE_REQUIRED = 3

DECLARE FUNCTION SQLDriverConnect IMPORT "ODBC32.DLL" ALIAS "SQLDriverConnect" ( _
   BYVAL hdbc AS DWORD _                                ' SQLHDBC       hdbc
 , BYVAL hwnd AS DWORD _                                ' SQLHWND       hwnd
 , BYREF szConnStrIn AS ASCIIZ _                        ' SQLCHAR      *szConnStrIn
 , BYVAL cbConnStrIn AS INTEGER _                       ' SQLSMALLINT   cbConnStrIn
 , BYREF szConnStrOut AS ASCIIZ _                       ' SQLCHAR      *szConnStrOut
 , BYVAL cbConnStrOutMax AS INTEGER _                   ' SQLSMALLINT   cbConnStrOutMax
 , BYREF pcbConnStrOut AS INTEGER _                     ' SQLSMALLINT  *pcbConnStrOut
 , BYVAL fDriverCompletion AS WORD _                    ' SQLUSMALLINT  fDriverCompletion
 ) AS INTEGER                                           ' SQLRETURN

'/* Level 2 Functions                             */

'/* SQLExtendedFetch "fFetchType" values */
%SQL_FETCH_BOOKMARK = 8

'/* SQLExtendedFetch "rgfRowStatus" element values */
%SQL_ROW_SUCCESS           = 0
%SQL_ROW_DELETED           = 1
%SQL_ROW_UPDATED           = 2
%SQL_ROW_NOROW             = 3
%SQL_ROW_ADDED             = 4
%SQL_ROW_ERROR             = 5
#IF %ODBCVER >= &H0300
%SQL_ROW_SUCCESS_WITH_INFO = 6
%SQL_ROW_PROCEED           = 0
%SQL_ROW_IGNORE            = 1
#ENDIF

'/* value for SQL_DESC_ARRAY_STATUS_PTR */
#IF %ODBCVER >= &H0300
%SQL_PARAM_SUCCESS           = 0
%SQL_PARAM_SUCCESS_WITH_INFO = 6
%SQL_PARAM_ERROR             = 5
%SQL_PARAM_UNUSED            = 7
%SQL_PARAM_DIAG_UNAVAILABLE  = 1

%SQL_PARAM_PROCEED           = 0
%SQL_PARAM_IGNORE            = 1
#ENDIF   ' /* ODBCVER >= 0x0300 */

'/* Defines for SQLForeignKeys (UPDATE_RULE and DELETE_RULE) */
%SQL_CASCADE             = 0
%SQL_RESTRICT            = 1
%SQL_SET_NULL            = 2
#IF %ODBCVER >= &H0250
%SQL_NO_ACTION           = 3
%SQL_SET_DEFAULT         = 4
#ENDIF   ' /* ODBCVER >= &H0250 */

#IF %ODBCVER >= &H0300
'/* Note that the following are in a different column of SQLForeignKeys than */
'/* the previous #defines.   These are for DEFERRABILITY.                    */

%SQL_INITIALLY_DEFERRED  = 5
%SQL_INITIALLY_IMMEDIATE = 6
%SQL_NOT_DEFERRABLE      = 7

#ENDIF   ' /* ODBCVER >= 0x0300 */

'/* Defines for SQLBindParameter and
'                           SQLProcedureColumns (returned in the result set) */
%SQL_PARAM_TYPE_UNKNOWN          = 0
%SQL_PARAM_INPUT                 = 1
%SQL_PARAM_INPUT_OUTPUT          = 2
%SQL_RESULT_COL                  = 3
%SQL_PARAM_OUTPUT                = 4
%SQL_RETURN_VALUE                = 5
#IF %ODBCVER >= &H0380
%SQL_PARAM_INPUT_OUTPUT_STREAM   = 8
%SQL_PARAM_OUTPUT_STREAM         = 16
#ENDIF

'/* Defines for SQLProcedures (returned in the result set) */
%SQL_PT_UNKNOWN   = 0
%SQL_PT_PROCEDURE = 1
%SQL_PT_FUNCTION  = 2

'/* Defines used by Driver Manager when mapping SQLSetParam to SQLBindParameter
'*/
%SQL_PARAM_TYPE_DEFAULT = %SQL_PARAM_INPUT_OUTPUT
%SQL_SETPARAM_VALUE_MAX = (-1&)

'/*      This define is too large for RC */
'#define SQL_ODBC_KEYWORDS \
'"ABSOLUTE,ACTION,ADA,ADD,ALL,ALLOCATE,ALTER,AND,ANY,ARE,AS,"\
'"ASC,ASSERTION,AT,AUTHORIZATION,AVG,"\
'"BEGIN,BETWEEN,BIT,BIT_LENGTH,BOTH,BY,CASCADE,CASCADED,CASE,CAST,CATALOG,"\
'"CHAR,CHAR_LENGTH,CHARACTER,CHARACTER_LENGTH,CHECK,CLOSE,COALESCE,"\
'"COLLATE,COLLATION,COLUMN,COMMIT,CONNECT,CONNECTION,CONSTRAINT,"\
'"CONSTRAINTS,CONTINUE,CONVERT,CORRESPONDING,COUNT,CREATE,CROSS,CURRENT,"\
'"CURRENT_DATE,CURRENT_TIME,CURRENT_TIMESTAMP,CURRENT_USER,CURSOR,"\
'"DATE,DAY,DEALLOCATE,DEC,DECIMAL,DECLARE,DEFAULT,DEFERRABLE,"\
'"DEFERRED,DELETE,DESC,DESCRIBE,DESCRIPTOR,DIAGNOSTICS,DISCONNECT,"\
'"DISTINCT,DOMAIN,DOUBLE,DROP,"\
'"ELSE,END,END-EXEC,ESCAPE,EXCEPT,EXCEPTION,EXEC,EXECUTE,"\
'"EXISTS,EXTERNAL,EXTRACT,"\
'"FALSE,FETCH,FIRST,FLOAT,FOR,FOREIGN,FORTRAN,FOUND,FROM,FULL,"\
'"GET,GLOBAL,GO,GOTO,GRANT,GROUP,HAVING,HOUR,"\
'"IDENTITY,IMMEDIATE,IN,INCLUDE,INDEX,INDICATOR,INITIALLY,INNER,"\
'"INPUT,INSENSITIVE,INSERT,INT,INTEGER,INTERSECT,INTERVAL,INTO,IS,ISOLATION,"\
'"JOIN,KEY,LANGUAGE,LAST,LEADING,LEFT,LEVEL,LIKE,LOCAL,LOWER,"\
'"MATCH,MAX,MIN,MINUTE,MODULE,MONTH,"\
'"NAMES,NATIONAL,NATURAL,NCHAR,NEXT,NO,NONE,NOT,NULL,NULLIF,NUMERIC,"\
'"OCTET_LENGTH,OF,ON,ONLY,OPEN,OPTION,OR,ORDER,OUTER,OUTPUT,OVERLAPS,"\
'"PAD,PARTIAL,PASCAL,PLI,POSITION,PRECISION,PREPARE,PRESERVE,"\
'"PRIMARY,PRIOR,PRIVILEGES,PROCEDURE,PUBLIC,"\
'"READ,REAL,REFERENCES,RELATIVE,RESTRICT,REVOKE,RIGHT,ROLLBACK,ROWS"\
'"SCHEMA,SCROLL,SECOND,SECTION,SELECT,SESSION,SESSION_USER,SET,SIZE,"\
'"SMALLINT,SOME,SPACE,SQL,SQLCA,SQLCODE,SQLERROR,SQLSTATE,SQLWARNING,"\
'"SUBSTRING,SUM,SYSTEM_USER,"\
'"TABLE,TEMPORARY,THEN,TIME,TIMESTAMP,TIMEZONE_HOUR,TIMEZONE_MINUTE,"\
'"TO,TRAILING,TRANSACTION,TRANSLATE,TRANSLATION,TRIM,TRUE,"\
'"UNION,UNIQUE,UNKNOWN,UPDATE,UPPER,USAGE,USER,USING,"\
'"VALUE,VALUES,VARCHAR,VARYING,VIEW,WHEN,WHENEVER,WHERE,WITH,WORK,WRITE,"\
'"YEAR,ZONE"

DECLARE FUNCTION SQLBrowseConnect IMPORT "ODBC32.DLL" ALIAS "SQLBrowseConnect" ( _
   BYVAL hdbc AS DWORD _                                ' SQLHDBC       hdbc
 , BYREF szConnStrIn AS ASCIIZ _                        ' SQLCHAR      *szConnStrIn
 , BYVAL cbConnStrIn AS INTEGER _                       ' SQLSMALLINT   cbConnStrIn
 , BYREF szConnStrOut AS ASCIIZ _                       ' SQLCHAR      *szConnStrOut
 , BYVAL cbConnStrOutMax AS INTEGER _                   ' SQLSMALLINT   cbConnStrOutMax
 , BYREF pcbConnStrOut AS INTEGER _                     ' SQLSMALLINT  *pcbConnStrOut
 ) AS INTEGER                                           ' SQLRETURN


#IF %ODBCVER >= &H0300
DECLARE FUNCTION SQLBulkOperations IMPORT "ODBC32.DLL" ALIAS "SQLBulkOperations" ( _
   BYVAL StatementHandle AS DWORD _                     ' SQLHSTMT    StatementHandle
 , BYVAL Operation AS INTEGER _                         ' SQLSMALLINT Operation
 ) AS INTEGER                                           ' SQLRETURN
#ENDIF   ' /* ODBCVER >= &H0300 */

DECLARE FUNCTION SQLColAttributes IMPORT "ODBC32.DLL" ALIAS "SQLColAttributes" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT      hstmt
 , BYVAL icol AS WORD _                                 ' SQLUSMALLINT  icol
 , BYVAL fDescType AS WORD _                            ' SQLUSMALLINT  fDescType
 , BYREF rgbDesc AS ANY _                               ' SQLPOINTER    rgbDesc
 , BYVAL cbDescMax AS INTEGER _                         ' SQLSMALLINT   cbDescMax
 , BYREF pcbDesc AS INTEGER _                           ' SQLSMALLINT  *pcbDesc
 , BYREF pfDesc AS LONG _                               ' SQLLEN       *pfDesc
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLColumnPrivileges IMPORT "ODBC32.DLL" ALIAS "SQLColumnPrivileges" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT     hstmt
 , BYREF szCatalogName AS ASCIIZ _                      ' SQLCHAR     *szCatalogName
 , BYVAL cbCatalogName AS INTEGER _                     ' SQLSMALLINT  cbCatalogName
 , BYREF szSchemaName AS ASCIIZ _                       ' SQLCHAR     *szSchemaName
 , BYVAL cbSchemaName AS INTEGER _                      ' SQLSMALLINT  cbSchemaName
 , BYREF szTableName AS ASCIIZ _                        ' SQLCHAR     *szTableName
 , BYVAL cbTableName AS INTEGER _                       ' SQLSMALLINT  cbTableName
 , BYREF szColumnName AS ASCIIZ _                       ' SQLCHAR     *szColumnName
 , BYVAL cbColumnName AS INTEGER _                      ' SQLSMALLINT  cbColumnName
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLDescribeParam IMPORT "ODBC32.DLL" ALIAS "SQLDescribeParam" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT      hstmt
 , BYVAL ipar AS WORD _                                 ' SQLUSMALLINT  ipar
 , BYREF pfSqlType AS INTEGER _                         ' SQLSMALLINT  *pfSqlType
 , BYREF pcbParamDef AS DWORD _                         ' SQLULEN      *pcbParamDef
 , BYREF pibScale AS INTEGER _                          ' SQLSMALLINT  *pibScale
 , BYREF pfNullable AS INTEGER _                        ' SQLSMALLINT  *pfNullable
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLExtendedFetch IMPORT "ODBC32.DLL" ALIAS "SQLExtendedFetch" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT      hstmt
 , BYVAL fFetchType AS WORD _                           ' SQLUSMALLINT  fFetchType
 , BYVAL irow AS LONG _                                 ' SQLLEN        irow
 , BYREF pcrow AS DWORD _                               ' SQLULEN      *pcrow
 , BYREF rgfRowStatus AS WORD _                         ' SQLUSMALLINT *rgfRowStatus
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLForeignKeys IMPORT "ODBC32.DLL" ALIAS "SQLForeignKeys" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT     hstmt
 , BYREF szPkCatalogName AS ASCIIZ _                    ' SQLCHAR     *szPkCatalogName
 , BYVAL cbPkCatalogName AS INTEGER _                   ' SQLSMALLINT  cbPkCatalogName
 , BYREF szPkSchemaName AS ASCIIZ _                     ' SQLCHAR     *szPkSchemaName
 , BYVAL cbPkSchemaName AS INTEGER _                    ' SQLSMALLINT  cbPkSchemaName
 , BYREF szPkTableName AS ASCIIZ _                      ' SQLCHAR     *szPkTableName
 , BYVAL cbPkTableName AS INTEGER _                     ' SQLSMALLINT  cbPkTableName
 , BYREF szFkCatalogName AS ASCIIZ _                    ' SQLCHAR     *szFkCatalogName
 , BYVAL cbFkCatalogName AS INTEGER _                   ' SQLSMALLINT  cbFkCatalogName
 , BYREF szFkSchemaName AS ASCIIZ _                     ' SQLCHAR     *szFkSchemaName
 , BYVAL cbFkSchemaName AS INTEGER _                    ' SQLSMALLINT  cbFkSchemaName
 , BYREF szFkTableName AS ASCIIZ _                      ' SQLCHAR     *szFkTableName
 , BYVAL cbFkTableName AS INTEGER _                     ' SQLSMALLINT  cbFkTableName
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLMoreResults IMPORT "ODBC32.DLL" ALIAS "SQLMoreResults" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT  hstmt
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLNativeSql IMPORT "ODBC32.DLL" ALIAS "SQLNativeSql" ( _
   BYVAL hdbc AS DWORD _                                ' SQLHDBC     hdbc
 , BYREF szSqlStrIn AS ASCIIZ _                         ' SQLCHAR    *szSqlStrIn
 , BYVAL cbSqlStrIn AS LONG _                           ' SQLINTEGER  cbSqlStrIn
 , BYREF szSqlStr AS ASCIIZ _                           ' SQLCHAR    *szSqlStr
 , BYVAL cbSqlStrMax AS LONG _                          ' SQLINTEGER  cbSqlStrMax
 , BYREF pcbSqlStr AS LONG _                            ' SQLINTEGER *pcbSqlStr
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLNumParams IMPORT "ODBC32.DLL" ALIAS "SQLNumParams" ( _
   BYVAL hstmt AS DWORD  _                              ' SQLHSTMT     hstmt
 , BYREF pcpar AS INTEGER _                             ' SQLSMALLINT *pcpar
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLParamOptions IMPORT "ODBC32.DLL" ALIAS "SQLParamOptions" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT   hstmt
 , BYVAL crow AS DWORD _                                ' SQLULEN    crow
 , BYREF pirow AS DWORD _                               ' SQLULEN   *pirow
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLPrimaryKeys IMPORT "ODBC32.DLL" ALIAS "SQLPrimaryKeys" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT     hstmt
 , BYREF szCatalogName AS ASCIIZ _                      ' SQLCHAR     *szCatalogName
 , BYVAL cbCatalogName AS INTEGER _                     ' SQLSMALLINT  cbCatalogName
 , BYREF szSchemaName AS ASCIIZ _                       ' SQLCHAR     *szSchemaName
 , BYVAL cbSchemaName AS INTEGER _                      ' SQLSMALLINT  cbSchemaName
 , BYREF szTableName AS ASCIIZ _                        ' SQLCHAR     *szTableName
 , BYVAL cbTableName AS INTEGER _                       ' SQLSMALLINT  cbTableName
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLProcedureColumns IMPORT "ODBC32.DLL" ALIAS "SQLProcedureColumns" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT     hstmt
 , BYREF szCatalogName AS ASCIIZ _                      ' SQLCHAR     *szCatalogName
 , BYVAL cbCatalogName AS INTEGER _                     ' SQLSMALLINT  cbCatalogName
 , BYREF szSchemaName AS ASCIIZ _                       ' SQLCHAR     *szSchemaName
 , BYVAL cbSchemaName AS INTEGER _                      ' SQLSMALLINT  cbSchemaName
 , BYREF szProcName AS ASCIIZ _                         ' SQLCHAR     *szProcName
 , BYVAL cbProcName AS INTEGER _                        ' SQLSMALLINT  cbProcName
 , BYREF szColumnName AS ASCIIZ _                       ' SQLCHAR     *szColumnName
 , BYVAL cbColumnName AS INTEGER _                      ' SQLSMALLINT  cbColumnName
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLProcedures IMPORT "ODBC32.DLL" ALIAS "SQLProcedures" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT     hstmt
 , BYREF szCatalogName AS ASCIIZ _                      ' SQLCHAR     *szCatalogName
 , BYVAL cbCatalogName AS INTEGER _                     ' SQLSMALLINT  cbCatalogName
 , BYREF szSchemaName AS ASCIIZ _                       ' SQLCHAR     *szSchemaName
 , BYVAL cbSchemaName AS INTEGER _                      ' SQLSMALLINT  cbSchemaName
 , BYREF szProcName AS ASCIIZ _                         ' SQLCHAR     *szProcName
 , BYVAL cbProcName AS INTEGER _                        ' SQLSMALLINT  cbProcName
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLSetPos IMPORT "ODBC32.DLL" ALIAS "SQLSetPos" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT           hstmt
 , BYVAL irow AS WORD _                                 ' SQLSETPOSIROW      irow
 , BYVAL fOption AS WORD _                              ' SQLUSMALLINT       fOption
 , BYVAL fLock AS WORD _                                ' SQLUSMALLINT       fLock
 ) AS INTEGER                                           ' SQLRETURN

'/* Macros for SQLSetPos */
'#define SQL_POSITION_TO(hstmt,irow) SQLSetPos(hstmt,irow,SQL_POSITION,SQL_LOCK_NO_CHANGE)
'#define SQL_LOCK_RECORD(hstmt,irow,fLock) SQLSetPos(hstmt,irow,SQL_POSITION,fLock)
'#define SQL_REFRESH_RECORD(hstmt,irow,fLock) SQLSetPos(hstmt,irow,SQL_REFRESH,fLock)
'#define SQL_UPDATE_RECORD(hstmt,irow) SQLSetPos(hstmt,irow,SQL_UPDATE,SQL_LOCK_NO_CHANGE)
'#define SQL_DELETE_RECORD(hstmt,irow) SQLSetPos(hstmt,irow,SQL_DELETE,SQL_LOCK_NO_CHANGE)
'#define SQL_ADD_RECORD(hstmt,irow) SQLSetPos(hstmt,irow,SQL_ADD,SQL_LOCK_NO_CHANGE)

MACRO SQL_POSITION_TO(hstmt,irow) = SQLSetPos(hstmt,irow,%SQL_POSITION,%SQL_LOCK_NO_CHANGE)
MACRO SQL_LOCK_RECORD(hstmt,irow,fLock) = SQLSetPos(hstmt,irow,%SQL_POSITION,fLock)
MACRO SQL_REFRESH_RECORD(hstmt,irow,fLock) = SQLSetPos(hstmt,irow,%SQL_REFRESH,fLock)
MACRO SQL_UPDATE_RECORD(hstmt,irow) = SQLSetPos(hstmt,irow,%SQL_UPDATE,%SQL_LOCK_NO_CHANGE)
MACRO SQL_DELETE_RECORD(hstmt,irow) = SQLSetPos(hstmt,irow,%SQL_DELETE,%SQL_LOCK_NO_CHANGE)
MACRO SQL_ADD_RECORD(hstmt,irow) = SQLSetPos(hstmt,irow,%SQL_ADD,%SQL_LOCK_NO_CHANGE)

DECLARE FUNCTION SQLTablePrivileges IMPORT "ODBC32.DLL" ALIAS "SQLTablePrivileges" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT     hstmt
 , BYREF szCatalogName AS ASCIIZ _                      ' SQLCHAR     *szCatalogName
 , BYVAL cbCatalogName AS INTEGER _                     ' SQLSMALLINT  cbCatalogName
 , BYREF szSchemaName AS ASCIIZ _                       ' SQLCHAR     *szSchemaName
 , BYVAL cbSchemaName AS INTEGER _                      ' SQLSMALLINT  cbSchemaName
 , BYREF szTableName AS ASCIIZ _                        ' SQLCHAR     *szTableName
 , BYVAL cbTableName AS INTEGER _                       ' SQLSMALLINT  cbTableName
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLDrivers IMPORT "ODBC32.DLL" ALIAS "SQLDrivers" ( _
   BYVAL henv AS DWORD _                                ' SQLHENV       henv
 , BYVAL fDirection AS WORD _                           ' SQLUSMALLINT  fDirection
 , BYREF szDriverDesc AS ASCIIZ _                       ' SQLCHAR      *szDriverDesc
 , BYVAL cbDriverDescMax AS INTEGER _                   ' SQLSMALLINT   cbDriverDescMax
 , BYREF pcbDriverDesc AS INTEGER _                     ' SQLSMALLINT  *pcbDriverDesc
 , BYREF szDriverAttributes AS ASCIIZ _                 ' SQLCHAR      *szDriverAttributes
 , BYVAL cbDrvrAttrMax AS INTEGER _                     ' SQLSMALLINT   cbDrvrAttrMax
 , BYREF pcbDrvrAttr AS INTEGER _                       ' SQLSMALLINT  *pcbDrvrAttr
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLBindParameter IMPORT "ODBC32.DLL" ALIAS "SQLBindParameter" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT      hstmt
 , BYVAL ipar AS WORD _                                 ' SQLUSMALLINT  ipar
 , BYVAL fParamType AS INTEGER _                        ' SQLSMALLINT   fParamType
 , BYVAL fCType AS INTEGER _                            ' SQLSMALLINT   fCType
 , BYVAL fSqlType AS INTEGER _                          ' SQLSMALLINT   fSqlType
 , BYVAL cbColDef AS DWORD _                            ' SQLULEN       cbColDef
 , BYVAL ibScale AS INTEGER _                           ' SQLSMALLINT   ibScale
 , BYREF rgbValue AS ANY _                              ' SQLPOINTER    rgbValue
 , BYVAL cbValueMax AS LONG _                           ' SQLLEN        cbValueMax
 , BYREF pcbValue AS LONG _                             ' SQLLEN       *pcbValue
 ) AS INTEGER                                           ' SQLRETURN


'/*---------------------------------------------------------*/
'/* SQLAllocHandleStd is implemented to make SQLAllocHandle */
'/* compatible with X/Open standard.    an application should */
'/* not call SQLAllocHandleStd directly                  */
'/*---------------------------------------------------------*/
'#IF %DEF(%ODBC_STD)
'#define SQLAllocHandle  SQLAllocHandleStd
'#define SQLAllocEnv(phenv)  SQLAllocHandleStd(SQL_HANDLE_ENV, SQL_NULL_HANDLE, phenv)

'/* Internal type subcodes */
'#define SQL_YEAR                   SQL_CODE_YEAR
'#define SQL_MONTH                  SQL_CODE_MONTH
'#define SQL_DAY                    SQL_CODE_DAY
'#define SQL_HOUR                   SQL_CODE_HOUR
'#define SQL_MINUTE                 SQL_CODE_MINUTE
'#define SQL_SECOND                 SQL_CODE_SECOND
'#define SQL_YEAR_TO_MONTH          SQL_CODE_YEAR_TO_MONTH
'#define SQL_DAY_TO_HOUR            SQL_CODE_DAY_TO_HOUR
'#define SQL_DAY_TO_MINUTE          SQL_CODE_DAY_TO_MINUTE
'#define SQL_DAY_TO_SECOND          SQL_CODE_DAY_TO_SECOND
'#define SQL_HOUR_TO_MINUTE         SQL_CODE_HOUR_TO_MINUTE
'#define SQL_HOUR_TO_SECOND         SQL_CODE_HOUR_TO_SECOND
'#define SQL_MINUTE_TO_SECOND       SQL_CODE_MINUTE_TO_SECOND
'#ENDIF   ' /* ODBC_STD */

#IF %ODBCVER >= &H0300
'SQLRETURN SQL_API SQLAllocHandleStd(
'   SQLSMALLINT    fHandleType,
'   SQLHANDLE      hInput,
'   SQLHANDLE     *phOutput);

DECLARE FUNCTION SQLAllocHandleStd IMPORT "ODBC32.DLL" ALIAS "SQLAllocHandleStd" ( _
   BYVAL fHandleType AS WORD _                          ' SQLSMALLINT  fHandleType
 , BYVAL hInput AS DWORD _                              ' SQLHANDLE    hInput
 , BYREF phOutput AS DWORD _                            ' SQLHANDLE   *phOutput
 ) AS INTEGER                                           ' SQLRETURN
#ENDIF

'/*      Deprecated defines from prior versions of ODBC */
%SQL_DATABASE_NAME               = 16   ' /* Use SQLGetConnectOption/SQL_CURRENT_QUALIFIER */
%SQL_FD_FETCH_PREV               = %SQL_FD_FETCH_PRIOR
%SQL_FETCH_PREV                  = %SQL_FETCH_PRIOR
%SQL_CONCUR_TIMESTAMP            = %SQL_CONCUR_ROWVER
%SQL_SCCO_OPT_TIMESTAMP          = %SQL_SCCO_OPT_ROWVER
%SQL_CC_DELETE                   = %SQL_CB_DELETE
%SQL_CR_DELETE                   = %SQL_CB_DELETE
%SQL_CC_CLOSE                    = %SQL_CB_CLOSE
%SQL_CR_CLOSE                    = %SQL_CB_CLOSE
%SQL_CC_PRESERVE                 = %SQL_CB_PRESERVE
%SQL_CR_PRESERVE                 = %SQL_CB_PRESERVE
'/* SQL_FETCH_RESUME is not supported by 2.0+ drivers
%SQL_FETCH_RESUME                = 7
'*/
%SQL_SCROLL_FORWARD_ONLY         = 0&    ' /*-SQL_CURSOR_FORWARD_ONLY */
%SQL_SCROLL_KEYSET_DRIVEN        = -1&   ' /*-SQL_CURSOR_KEYSET_DRIVEN */
%SQL_SCROLL_DYNAMIC              = -2&   ' /*-SQL_CURSOR_DYNAMIC */
%SQL_SCROLL_STATIC               = -3&   ' /*-SQL_CURSOR_STATIC */

'/*      Deprecated functions from prior versions of ODBC */

DECLARE FUNCTION SQLSetScrollOptions IMPORT "ODBC32.DLL" ALIAS "SQLSetScrollOptions" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT     hstmt
 , BYVAL fConcurrency AS WORD _                         ' SQLUSMALLINT fConcurrency
 , BYVAL crowKeyset AS LONG _                           ' SQLLEN       crowKeyset
 , BYVAL crowRowset AS WORD _                           ' SQLUSMALLINT crowRowset
 ) AS INTEGER                                           ' SQLRETURN

'/* Tracing section */

%TRACE_VERSION = 1000     ' /* Version of trace API */

DECLARE FUNCTION TraceOpenLogFile IMPORT "odbctrac.dll" ALIAS "TraceOpenLogFile" ( _
   BYVAL DWORD _                                        ' LPWSTR
 , BYVAL DWORD _                                        ' LPWSTR
 , BYVAL DWORD _                                        ' DWORD
 ) AS LONG                                              ' RETCODE

'RETCODE   SQL_API TraceCloseLogFile();         // Request to close a trace log

DECLARE FUNCTION TraceCloseLogFile IMPORT "odbctrac.dll" ALIAS "TraceCloseLogFile" ( _
 ) AS LONG                                              ' RETCODE

DECLARE SUB TraceReturn IMPORT "odbctrac.dll" ALIAS "TraceReturn" ( _
   BYVAL LONG _                                         ' RETCODE
 , BYVAL LONG _                                         ' RETCODE
 )                                                      ' VOID

DECLARE FUNCTION TraceVersion IMPORT "odbctrac.dll" ALIAS "TraceVersion" ( _
 ) AS DWORD                                             ' DWORD

'/* Functions for Visual Studio Analyzer*/
'/* to turn on/off tracing or VS events, call TraceVSControl by setting or clearing the following bits  */
%TRACE_ON          = &H00000001&
%TRACE_VS_EVENT_ON = &H00000002&

DECLARE FUNCTION TraceVSControl IMPORT "odbctrac.dll" ALIAS "TraceVSControl" ( _
   BYVAL DWORD _                                        ' DWORD
 ) AS LONG                                              ' RETCODE

'/* Functions for setting the connection pooling failure detection code */
'/* The "TryWait" value is the time (in seconds) that the DM will wait  */
'/* between detecting that a connection is dead (using                  */
'/* SQL_ATTR_CONNECTION_DEAD) and retrying the connection.  During that */
'/* interval, connection requests will get "The server appears to be    */
'/* dead" error returns.                                                */


DECLARE FUNCTION ODBCSetTryWaitValue IMPORT "odbc32.dll" ALIAS "ODBCSetTryWaitValue" ( _
   BYVAL dwValue AS DWORD _                             ' DWORD dwValue
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ODBCGetTryWaitValue IMPORT "odbc32.dll" ALIAS "ODBCGetTryWaitValue" ( _
 ) AS DWORD                                             ' DWORD

'/* the flags in ODBC_VS_ARGS */
%ODBC_VS_FLAG_UNICODE_ARG = &H00000001&   ' /* the argument is unicode */
%ODBC_VS_FLAG_UNICODE_COR = &H00000002&   ' /* the correlation is unicode */
%ODBC_VS_FLAG_RETCODE     = &H00000004&   ' /* RetCode field is set */
%ODBC_VS_FLAG_STOP        = &H00000008&   ' /* Stop firing visual studio analyzer events */

' // Size = 4 bytes
UNION ODBC_VS_ARGS_UNION_1
   wszArg AS WSTRINGZ PTR   ' WCHAR   *
   szArg  AS ASCIIZ PTR     ' CHAR   *
END UNION

' // Size = 4 bytes
UNION ODBC_VS_ARGS_UNION_2
   wszCorrelation AS WSTRINGZ PTR   ' WCHAR   *
   szCorrelation  AS ASCIIZ PTR     ' CHAR   *
END UNION

' // Size = 20 bytes
TYPE ODBC_VS_ARGS DWORD
   pguidEvent AS GUID PTR   ' const GUID  /* the GUID for event */
   dwFlags    AS DWORD      ' DWORD  /* flags for the call */
   ODBC_VS_ARGS_UNION_1
   ODBC_VS_ARGS_UNION_2
   RetCode    AS LONG       ' RETCODE
END TYPE

DECLARE SUB FireVSDebugEvent IMPORT "odbctrac.dll" ALIAS "FireVSDebugEvent" ( _
   BYREF ODBC_VS_ARGS _                                 ' PODBC_VS_ARGS
 )                                                      ' VOID
