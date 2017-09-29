' ########################################################################################
' Microsoft Windows
' File: sql.inc
' Contents: This is the the main include for ODBC Core functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SQL_INC = 1

#INCLUDE ONCE "windows.inc"

'/*
'* ODBCVER  Default to ODBC version number (0x0380).   To exclude
'*          definitions introduced in version 3.8 (or above)
'*          #define ODBCVER 0x0351 before #including <sql.h>
'*/
#IF NOT %DEF(%ODBCVER)
%ODBCVER = &H0380
#ENDIF

#INCLUDE ONCE "sqltypes.inc"

'/* special length/indicator values */
%SQL_NULL_DATA    = -1
%SQL_DATA_AT_EXEC = -2


'/* return values from functions */
%SQL_SUCCESS              = 0
%SQL_SUCCESS_WITH_INFO    = 1
#IF %ODBCVER >= &H0300
%SQL_NO_DATA              = 100
#ENDIF
#IF %ODBCVER >= &H0380
%SQL_PARAM_DATA_AVAILABLE = 101
#ENDIF
%SQL_ERROR                = -1
%SQL_INVALID_HANDLE       = -2

%SQL_STILL_EXECUTING      = 2
%SQL_NEED_DATA            = 99

'/* test for SQL_SUCCESS or SQL_SUCCESS_WITH_INFO */
'#define SQL_SUCCEEDED(rc) (((rc)&(~1))==0)
MACRO SQL_SUCCEEDED (rc) = -BITS(INTEGER, (rc = 0) OR (rc = 1))

'/* flags for null-terminated string */
%SQL_NTS  = -3
%SQL_NTSL = -3&

'/* maximum message length */
%SQL_MAX_MESSAGE_LENGTH = 512

'/* date/time length constants */
#IF %ODBCVER >= &H0300
%SQL_DATE_LEN      = 10
%SQL_TIME_LEN      = 8  '/* add P+1 if precision is nonzero */
%SQL_TIMESTAMP_LEN = 19  '/* add P+1 if precision is nonzero */
#ENDIF

'/* handle type identifiers */
#IF %ODBCVER >= &H0300
%SQL_HANDLE_ENV  = 1
%SQL_HANDLE_DBC  = 2
%SQL_HANDLE_STMT = 3
%SQL_HANDLE_DESC = 4
#ENDIF

'/* environment attribute */
#IF %ODBCVER >= &H0300
%SQL_ATTR_OUTPUT_NTS = 10001
#ENDIF

'/* connection attributes */
#IF %ODBCVER >= &H0300
%SQL_ATTR_AUTO_IPD    = 10001
%SQL_ATTR_METADATA_ID = 10014
#ENDIF   ' /* ODBCVER >= 0x0300 */

'/* statement attributes */
#IF %ODBCVER >= &H0300
%SQL_ATTR_APP_ROW_DESC       = 10010
%SQL_ATTR_APP_PARAM_DESC     = 10011
%SQL_ATTR_IMP_ROW_DESC       = 10012
%SQL_ATTR_IMP_PARAM_DESC     = 10013
%SQL_ATTR_CURSOR_SCROLLABLE  = -1
%SQL_ATTR_CURSOR_SENSITIVITY = -2
#ENDIF

'/* SQL_ATTR_CURSOR_SCROLLABLE values */
#IF %ODBCVER >= &H0300
%SQL_NONSCROLLABLE = 0
%SQL_SCROLLABLE    = 1
#ENDIF   ' /* ODBCVER >= 0x0300 */

'/* identifiers of fields in the SQL descriptor */
#IF %ODBCVER >= &H0300
%SQL_DESC_COUNT                  = 1001
%SQL_DESC_TYPE                   = 1002
%SQL_DESC_LENGTH                 = 1003
%SQL_DESC_OCTET_LENGTH_PTR       = 1004
%SQL_DESC_PRECISION              = 1005
%SQL_DESC_SCALE                  = 1006
%SQL_DESC_DATETIME_INTERVAL_CODE = 1007
%SQL_DESC_NULLABLE               = 1008
%SQL_DESC_INDICATOR_PTR          = 1009
%SQL_DESC_DATA_PTR               = 1010
%SQL_DESC_NAME                   = 1011
%SQL_DESC_UNNAMED                = 1012
%SQL_DESC_OCTET_LENGTH           = 1013
%SQL_DESC_ALLOC_TYPE             = 1099
#ENDIF

'/* identifiers of fields in the diagnostics area */
#IF %ODBCVER >= &H0300
%SQL_DIAG_RETURNCODE            = 1
%SQL_DIAG_NUMBER                = 2
%SQL_DIAG_ROW_COUNT             = 3
%SQL_DIAG_SQLSTATE              = 4
%SQL_DIAG_NATIVE                = 5
%SQL_DIAG_MESSAGE_TEXT          = 6
%SQL_DIAG_DYNAMIC_FUNCTION      = 7
%SQL_DIAG_CLASS_ORIGIN          = 8
%SQL_DIAG_SUBCLASS_ORIGIN       = 9
%SQL_DIAG_CONNECTION_NAME       = 10
%SQL_DIAG_SERVER_NAME           = 11
%SQL_DIAG_DYNAMIC_FUNCTION_CODE = 12
#ENDIF

'/* dynamic function codes */
#IF %ODBCVER >= &H0300
%SQL_DIAG_ALTER_DOMAIN          = 3
%SQL_DIAG_ALTER_TABLE           = 4
%SQL_DIAG_CALL                  = 7
%SQL_DIAG_CREATE_ASSERTION      = 6
%SQL_DIAG_CREATE_CHARACTER_SET  = 8
%SQL_DIAG_CREATE_COLLATION      = 10
%SQL_DIAG_CREATE_DOMAIN         = 23
%SQL_DIAG_CREATE_INDEX          = -1
%SQL_DIAG_CREATE_SCHEMA         = 64
%SQL_DIAG_CREATE_TABLE          = 77
%SQL_DIAG_CREATE_TRANSLATION    = 79
%SQL_DIAG_CREATE_VIEW           = 84
%SQL_DIAG_DELETE_WHERE          = 19
%SQL_DIAG_DROP_ASSERTION        = 24
%SQL_DIAG_DROP_CHARACTER_SET    = 25
%SQL_DIAG_DROP_COLLATION        = 26
%SQL_DIAG_DROP_DOMAIN           = 27
%SQL_DIAG_DROP_INDEX            = -2
%SQL_DIAG_DROP_SCHEMA           = 31
%SQL_DIAG_DROP_TABLE            = 32
%SQL_DIAG_DROP_TRANSLATION      = 33
%SQL_DIAG_DROP_VIEW             = 36
%SQL_DIAG_DYNAMIC_DELETE_CURSOR = 38
%SQL_DIAG_DYNAMIC_UPDATE_CURSOR = 81
%SQL_DIAG_GRANT                 = 48
%SQL_DIAG_INSERT                = 50
%SQL_DIAG_REVOKE                = 59
%SQL_DIAG_SELECT_CURSOR         = 85
%SQL_DIAG_UNKNOWN_STATEMENT     = 0
%SQL_DIAG_UPDATE_WHERE          = 82
#ENDIF   ' /* ODBCVER >= 0x0300 */

'/* SQL data type codes */
%SQL_UNKNOWN_TYPE = 0
%SQL_CHAR         = 1
%SQL_NUMERIC      = 2
%SQL_DECIMAL      = 3
%SQL_INTEGER      = 4
%SQL_SMALLINT     = 5
%SQL_FLOAT        = 6
%SQL_REAL         = 7
%SQL_DOUBLE       = 8
#IF %ODBCVER >= &H0300
%SQL_DATETIME     = 9
#ENDIF
%SQL_VARCHAR      = 12

'/* One-parameter shortcuts for date/time data types */
#IF %ODBCVER >= &H0300
%SQL_TYPE_DATE      = 91
%SQL_TYPE_TIME      = 92
%SQL_TYPE_TIMESTAMP = 93
#ENDIF

'/* Statement attribute values for cursor sensitivity */
#IF %ODBCVER >= &H0300
%SQL_UNSPECIFIED = 0
%SQL_INSENSITIVE = 1
%SQL_SENSITIVE   = 2
#ENDIF

'/* GetTypeInfo() request for all data types */
%SQL_ALL_TYPES = 0

'/* Default conversion code for SQLBindCol(), SQLBindParam() and SQLGetData() */
#IF %ODBCVER >= &H0300
%SQL_DEFAULT = 99
#ENDIF

'/* SQLSQLLEN GetData() code indicating that the application row descriptor
' * specifies the data type
' */
#IF %ODBCVER >= &H0300
%SQL_ARD_TYPE = -99
#ENDIF

#IF %ODBCVER >= &H0380
%SQL_APD_TYPE = -100
#ENDIF

'/* SQL date/time type subcodes */
#IF %ODBCVER >= &H0300
%SQL_CODE_DATE      = 1
%SQL_CODE_TIME      = 2
%SQL_CODE_TIMESTAMP = 3
#ENDIF

'/* CLI option values */
#IF %ODBCVER >= &H0300
%SQL_FALSE = 0
%SQL_TRUE  = 1
#ENDIF

'/* values of NULLABLE field in descriptor */
%SQL_NO_NULLS = 0
%SQL_NULLABLE = 1

'/* Value returned by SQLGetTypeInfo() to denote that it is
' * not known whether or not a data type supports null values.
' */
%SQL_NULLABLE_UNKNOWN = 2

'/* Values returned by SQLGetTypeInfo() to show WHERE clause
' * supported
' */
#IF %ODBCVER >= &H0300
%SQL_PRED_NONE  = 0
%SQL_PRED_CHAR  = 1
%SQL_PRED_BASIC = 2
#ENDIF

'/* values of UNNAMED field in descriptor */
#IF %ODBCVER >= &H0300
%SQL_NAMED   = 0
%SQL_UNNAMED = 1
#ENDIF

'/* values of ALLOC_TYPE field in descriptor */
#IF %ODBCVER >= &H0300
%SQL_DESC_ALLOC_AUTO = 1
%SQL_DESC_ALLOC_USER = 2
#ENDIF

'/* FreeStmt() options */
%SQL_CLOSE        = 0
%SQL_DROP         = 1
%SQL_UNBIND       = 2
%SQL_RESET_PARAMS = 3

'/* Codes used for FetchOrientation in SQLFetchScroll(),
'   and in SQLDataSources()
'*/
%SQL_FETCH_NEXT  = 1
%SQL_FETCH_FIRST = 2

'/* Other codes used for FetchOrientation in SQLFetchScroll() */
%SQL_FETCH_LAST     = 3
%SQL_FETCH_PRIOR    = 4
%SQL_FETCH_ABSOLUTE = 5
%SQL_FETCH_RELATIVE = 6

'/* SQLEndTran() options */
%SQL_COMMIT   = 0
%SQL_ROLLBACK = 1

'/* null handles returned by SQLAllocHandle() */
%SQL_NULL_HENV  = 0
%SQL_NULL_HDBC  = 0
%SQL_NULL_HSTMT = 0
#IF %ODBCVER >= &H0300
%SQL_NULL_HDESC = 0
#ENDIF

'/* null handle used in place of parent handle when allocating HENV */
#IF %ODBCVER >= &H0300
%SQL_NULL_HANDLE = 0&
#ENDIF

'/* Values that may appear in the result set of SQLSpecialColumns() */
%SQL_SCOPE_CURROW      = 0
%SQL_SCOPE_TRANSACTION = 1
%SQL_SCOPE_SESSION     = 2

%SQL_PC_UNKNOWN        = 0
#IF %ODBCVER >= &H0300
%SQL_PC_NON_PSEUDO     = 1
#ENDIF
%SQL_PC_PSEUDO         = 2

'/* Reserved value for the IdentifierType argument of SQLSpecialColumns() */
#IF %ODBCVER >= &H0300
%SQL_ROW_IDENTIFIER = 1
#ENDIF

'/* Reserved values for UNIQUE argument of SQLStatistics() */
%SQL_INDEX_UNIQUE = 0
%SQL_INDEX_ALL    = 1

'/* Values that may appear in the result set of SQLStatistics() */
%SQL_INDEX_CLUSTERED = 1
%SQL_INDEX_HASHED    = 2
%SQL_INDEX_OTHER     = 3

'/* SQLGetFunctions() values to identify ODBC APIs */
%SQL_API_SQLALLOCCONNECT     = 1
%SQL_API_SQLALLOCENV         = 2
#IF %ODBCVER >= &H0300
%SQL_API_SQLALLOCHANDLE      = 1001
#ENDIF
%SQL_API_SQLALLOCSTMT        = 3
%SQL_API_SQLBINDCOL          = 4
#IF %ODBCVER >= &H0300
%SQL_API_SQLBINDPARAM        = 1002
#ENDIF
%SQL_API_SQLCANCEL           = 5
#IF %ODBCVER >= &H0300
%SQL_API_SQLCLOSECURSOR      = 1003
%SQL_API_SQLCOLATTRIBUTE     = 6
#ENDIF
%SQL_API_SQLCOLUMNS          = 40
%SQL_API_SQLCONNECT          = 7
#IF %ODBCVER >= &H0300
%SQL_API_SQLCOPYDESC         = 1004
#ENDIF
%SQL_API_SQLDATASOURCES      = 57
%SQL_API_SQLDESCRIBECOL      = 8
%SQL_API_SQLDISCONNECT       = 9
#IF %ODBCVER >= &H0300
%SQL_API_SQLENDTRAN          = 1005
#ENDIF
%SQL_API_SQLERROR            = 10
%SQL_API_SQLEXECDIRECT       = 11
%SQL_API_SQLEXECUTE          = 12
%SQL_API_SQLFETCH            = 13
#IF %ODBCVER >= &H0300
%SQL_API_SQLFETCHSCROLL      = 1021
#ENDIF
%SQL_API_SQLFREECONNECT      = 14
%SQL_API_SQLFREEENV          = 15
#IF %ODBCVER >= &H0300
%SQL_API_SQLFREEHANDLE       = 1006
#ENDIF
%SQL_API_SQLFREESTMT         = 16
#IF %ODBCVER >= &H0300
%SQL_API_SQLGETCONNECTATTR   = 1007
#ENDIF
%SQL_API_SQLGETCONNECTOPTION = 42
%SQL_API_SQLGETCURSORNAME    = 17
%SQL_API_SQLGETDATA          = 43
#IF %ODBCVER >= &H0300
%SQL_API_SQLGETDESCFIELD     = 1008
%SQL_API_SQLGETDESCREC       = 1009
%SQL_API_SQLGETDIAGFIELD     = 1010
%SQL_API_SQLGETDIAGREC       = 1011
%SQL_API_SQLGETENVATTR       = 1012
#ENDIF
%SQL_API_SQLGETFUNCTIONS     = 44
%SQL_API_SQLGETINFO          = 45
#IF %ODBCVER >= &H0300
%SQL_API_SQLGETSTMTATTR      = 1014
#ENDIF
%SQL_API_SQLGETSTMTOPTION    = 46
%SQL_API_SQLGETTYPEINFO      = 47
%SQL_API_SQLNUMRESULTCOLS    = 18
%SQL_API_SQLPARAMDATA        = 48
%SQL_API_SQLPREPARE          = 19
%SQL_API_SQLPUTDATA          = 49
%SQL_API_SQLROWCOUNT         = 20
#IF %ODBCVER >= &H0300
%SQL_API_SQLSETCONNECTATTR   = 1016
#ENDIF
%SQL_API_SQLSETCONNECTOPTION = 50
%SQL_API_SQLSETCURSORNAME    = 21
#IF %ODBCVER >= &H0300
%SQL_API_SQLSETDESCFIELD     = 1017
%SQL_API_SQLSETDESCREC       = 1018
%SQL_API_SQLSETENVATTR       = 1019
#ENDIF
%SQL_API_SQLSETPARAM         = 22
#IF %ODBCVER >= &H0300
%SQL_API_SQLSETSTMTATTR      = 1020
#ENDIF
%SQL_API_SQLSETSTMTOPTION    = 51
%SQL_API_SQLSPECIALCOLUMNS   = 52
%SQL_API_SQLSTATISTICS       = 53
%SQL_API_SQLTABLES           = 54
%SQL_API_SQLTRANSACT         = 23

#IF %ODBCVER >= &H0380
%SQL_API_SQLCANCELHANDLE     = 1022
#ENDIF

'/* Information requested by SQLGetInfo() */
#IF %ODBCVER >= &H0300
%SQL_MAX_DRIVER_CONNECTIONS        = 0
%SQL_MAXIMUM_DRIVER_CONNECTIONS    = %SQL_MAX_DRIVER_CONNECTIONS
%SQL_MAX_CONCURRENT_ACTIVITIES     = 1
%SQL_MAXIMUM_CONCURRENT_ACTIVITIES = %SQL_MAX_CONCURRENT_ACTIVITIES
#ENDIF
%SQL_DATA_SOURCE_NAME              = 2
%SQL_FETCH_DIRECTION               = 8
%SQL_SERVER_NAME                   = 13
%SQL_SEARCH_PATTERN_ESCAPE         = 14
%SQL_DBMS_NAME                     = 17
%SQL_DBMS_VER                      = 18
%SQL_ACCESSIBLE_TABLES             = 19
%SQL_ACCESSIBLE_PROCEDURES         = 20
%SQL_CURSOR_COMMIT_BEHAVIOR        = 23
%SQL_DATA_SOURCE_READ_ONLY         = 25
%SQL_DEFAULT_TXN_ISOLATION         = 26
%SQL_IDENTIFIER_CASE               = 28
%SQL_IDENTIFIER_QUOTE_CHAR         = 29
%SQL_MAX_COLUMN_NAME_LEN           = 30
%SQL_MAXIMUM_COLUMN_NAME_LENGTH    = %SQL_MAX_COLUMN_NAME_LEN
%SQL_MAX_CURSOR_NAME_LEN           = 31
%SQL_MAXIMUM_CURSOR_NAME_LENGTH    = %SQL_MAX_CURSOR_NAME_LEN
%SQL_MAX_SCHEMA_NAME_LEN           = 32
%SQL_MAXIMUM_SCHEMA_NAME_LENGTH    = %SQL_MAX_SCHEMA_NAME_LEN
%SQL_MAX_CATALOG_NAME_LEN          = 34
%SQL_MAXIMUM_CATALOG_NAME_LENGTH   = %SQL_MAX_CATALOG_NAME_LEN
%SQL_MAX_TABLE_NAME_LEN            = 35
%SQL_SCROLL_CONCURRENCY            = 43
%SQL_TXN_CAPABLE                   = 46
%SQL_TRANSACTION_CAPABLE           = %SQL_TXN_CAPABLE
%SQL_USER_NAME                     = 47
%SQL_TXN_ISOLATION_OPTION          = 72
%SQL_TRANSACTION_ISOLATION_OPTION  = %SQL_TXN_ISOLATION_OPTION
%SQL_INTEGRITY                     = 73
%SQL_GETDATA_EXTENSIONS            = 81
%SQL_NULL_COLLATION                = 85
%SQL_ALTER_TABLE                   = 86
%SQL_ORDER_BY_COLUMNS_IN_SELECT    = 90
%SQL_SPECIAL_CHARACTERS            = 94
%SQL_MAX_COLUMNS_IN_GROUP_BY       = 97
%SQL_MAXIMUM_COLUMNS_IN_GROUP_BY   = %SQL_MAX_COLUMNS_IN_GROUP_BY
%SQL_MAX_COLUMNS_IN_INDEX          = 98
%SQL_MAXIMUM_COLUMNS_IN_INDEX      = %SQL_MAX_COLUMNS_IN_INDEX
%SQL_MAX_COLUMNS_IN_ORDER_BY       = 99
%SQL_MAXIMUM_COLUMNS_IN_ORDER_BY   = %SQL_MAX_COLUMNS_IN_ORDER_BY
%SQL_MAX_COLUMNS_IN_SELECT         = 100
%SQL_MAXIMUM_COLUMNS_IN_SELECT     = %SQL_MAX_COLUMNS_IN_SELECT
%SQL_MAX_COLUMNS_IN_TABLE          = 101
%SQL_MAX_INDEX_SIZE                = 102
%SQL_MAXIMUM_INDEX_SIZE            = %SQL_MAX_INDEX_SIZE
%SQL_MAX_ROW_SIZE                  = 104
%SQL_MAXIMUM_ROW_SIZE              = %SQL_MAX_ROW_SIZE
%SQL_MAX_STATEMENT_LEN             = 105
%SQL_MAXIMUM_STATEMENT_LENGTH      = %SQL_MAX_STATEMENT_LEN
%SQL_MAX_TABLES_IN_SELECT          = 106
%SQL_MAXIMUM_TABLES_IN_SELECT      = %SQL_MAX_TABLES_IN_SELECT
%SQL_MAX_USER_NAME_LEN             = 107
%SQL_MAXIMUM_USER_NAME_LENGTH      = %SQL_MAX_USER_NAME_LEN
#IF %ODBCVER >= &H0300
%SQL_OJ_CAPABILITIES               = 115
%SQL_OUTER_JOIN_CAPABILITIES       = %SQL_OJ_CAPABILITIES
#ENDIF   ' /* ODBCVER >= 0x0300 */

#IF %ODBCVER >= &H0300
%SQL_XOPEN_CLI_YEAR                = 10000
%SQL_CURSOR_SENSITIVITY            = 10001
%SQL_DESCRIBE_PARAMETER            = 10002
%SQL_CATALOG_NAME                  = 10003
%SQL_COLLATION_SEQ                 = 10004
%SQL_MAX_IDENTIFIER_LEN            = 10005
%SQL_MAXIMUM_IDENTIFIER_LENGTH     = %SQL_MAX_IDENTIFIER_LEN
#ENDIF   ' /* ODBCVER >= 0x0300 */

'/* SQL_ALTER_TABLE bitmasks */
#IF %ODBCVER >= &H0200
%SQL_AT_ADD_COLUMN     = &H00000001&
%SQL_AT_DROP_COLUMN    = &H00000002&
#ENDIF   ' /* ODBCVER >= 0x0200 */

#IF %ODBCVER >= &H0300
%SQL_AT_ADD_CONSTRAINT = &H00000008&

'/* The following bitmasks are ODBC extensions and defined in sqlext.h
' #define SQL_AT_COLUMN_SINGLE                  0x00000020L
' #define SQL_AT_ADD_COLUMN_DEFAULT             0x00000040L
' #define SQL_AT_ADD_COLUMN_COLLATION           0x00000080L
' #define SQL_AT_SET_COLUMN_DEFAULT             0x00000100L
' #define SQL_AT_DROP_COLUMN_DEFAULT            0x00000200L
' #define SQL_AT_DROP_COLUMN_CASCADE            0x00000400L
' #define SQL_AT_DROP_COLUMN_RESTRICT           0x00000800L
' #define SQL_AT_ADD_TABLE_CONSTRAINT           0x00001000L
' #define SQL_AT_DROP_TABLE_CONSTRAINT_CASCADE  0x00002000L
' #define SQL_AT_DROP_TABLE_CONSTRAINT_RESTRICT 0x00004000L
' #define SQL_AT_CONSTRAINT_NAME_DEFINITION     0x00008000L
' #define SQL_AT_CONSTRAINT_INITIALLY_DEFERRED  0x00010000L
' #define SQL_AT_CONSTRAINT_INITIALLY_IMMEDIATE 0x00020000L
' #define SQL_AT_CONSTRAINT_DEFERRABLE          0x00040000L
' #define SQL_AT_CONSTRAINT_NON_DEFERRABLE      0x00080000L
'/
#ENDIF   ' /* ODBCVER >= 0x0300 */


'/* SQL_ASYNC_MODE values */
#IF %ODBCVER >= &H0300
%SQL_AM_NONE       = 0
%SQL_AM_CONNECTION = 1
%SQL_AM_STATEMENT  = 2
#ENDIF

'/* SQL_CURSOR_COMMIT_BEHAVIOR values */
%SQL_CB_DELETE   = 0
%SQL_CB_CLOSE    = 1
%SQL_CB_PRESERVE = 2

'/* SQL_FETCH_DIRECTION bitmasks */
%SQL_FD_FETCH_NEXT     = &H00000001&
%SQL_FD_FETCH_FIRST    = &H00000002&
%SQL_FD_FETCH_LAST     = &H00000004&
%SQL_FD_FETCH_PRIOR    = &H00000008&
%SQL_FD_FETCH_ABSOLUTE = &H00000010&
%SQL_FD_FETCH_RELATIVE = &H00000020&

'/* SQL_GETDATA_EXTENSIONS bitmasks */
%SQL_GD_ANY_COLUMN = &H00000001&
%SQL_GD_ANY_ORDER  = &H00000002&

'/* SQL_IDENTIFIER_CASE values */
%SQL_IC_UPPER     = 1
%SQL_IC_LOWER     = 2
%SQL_IC_SENSITIVE = 3
%SQL_IC_MIXED     = 4

'/* SQL_OJ_CAPABILITIES bitmasks */
'/* NB: this means 'outer join', not what  you may be thinking */

#IF %ODBCVER >= &H0201
%SQL_OJ_LEFT               = &H00000001&
%SQL_OJ_RIGHT              = &H00000002&
%SQL_OJ_FULL               = &H00000004&
%SQL_OJ_NESTED             = &H00000008&
%SQL_OJ_NOT_ORDERED        = &H00000010&
%SQL_OJ_INNER              = &H00000020&
%SQL_OJ_ALL_COMPARISON_OPS = &H00000040&
#ENDIF

'/* SQL_SCROLL_CONCURRENCY bitmasks */
%SQL_SCCO_READ_ONLY  = &H00000001&
%SQL_SCCO_LOCK       = &H00000002&
%SQL_SCCO_OPT_ROWVER = &H00000004&
%SQL_SCCO_OPT_VALUES = &H00000008&

'/* SQL_TXN_CAPABLE values */
%SQL_TC_NONE       = 0
%SQL_TC_DML        = 1
%SQL_TC_ALL        = 2
%SQL_TC_DDL_COMMIT = 3
%SQL_TC_DDL_IGNORE = 4

'/* SQL_TXN_ISOLATION_OPTION bitmasks */
%SQL_TXN_READ_UNCOMMITTED         = &H00000001&
%SQL_TRANSACTION_READ_UNCOMMITTED = %SQL_TXN_READ_UNCOMMITTED
%SQL_TXN_READ_COMMITTED           = &H00000002&
%SQL_TRANSACTION_READ_COMMITTED   = %SQL_TXN_READ_COMMITTED
%SQL_TXN_REPEATABLE_READ          = &H00000004&
%SQL_TRANSACTION_REPEATABLE_READ  = %SQL_TXN_REPEATABLE_READ
%SQL_TXN_SERIALIZABLE             = &H00000008&
%SQL_TRANSACTION_SERIALIZABLE     = %SQL_TXN_SERIALIZABLE

'/* SQL_NULL_COLLATION values */
%SQL_NC_HIGH = 0
%SQL_NC_LOW  = 1

' In ODBC 3.x, the ODBC 2.x function SQLAllocConnect has been replaced by SQLAllocHandle.
DECLARE FUNCTION SQLAllocConnect IMPORT "ODBC32.DLL" ALIAS "SQLAllocConnect" ( _
   BYVAL EnvironmentHandle AS DWORD _                   ' __in  SQLHENV    EnvironmentHandle
 , BYREF ConnectionHandle AS DWORD _                    ' __out SQLHDBC   *ConnectionHandle
 ) AS INTEGER                                           ' SQLRETURN

' In ODBC 3.x, the ODBC 2.x function SQLAllocEnv has been replaced by SQLAllocHandle.
DECLARE FUNCTION SQLAllocEnv IMPORT "ODBC32.DLL" ALIAS "SQLAllocEnv" ( _
   BYREF EnvironmentHandle AS DWORD _                   ' __in SQLHENV   *EnvironmentHandle
 ) AS INTEGER                                           ' SQLRETURN

#IF %ODBCVER >= &H0300
DECLARE FUNCTION SQLAllocHandle IMPORT "ODBC32.DLL" ALIAS "SQLAllocHandle" ( _
   BYVAL HandleType AS INTEGER _                        ' __in  SQLSMALLINT HandleType
 , BYVAL InputHandle AS DWORD _                         ' __in  SQLHANDLE   InputHandle
 , BYREF OutputHandle AS DWORD _                        ' __out SQLHANDLE  *OutputHandle
 ) AS INTEGER                                           ' SQLRETURN
#ENDIF

DECLARE FUNCTION SQLAllocStmt IMPORT "ODBC32.DLL" ALIAS "SQLAllocStmt" ( _
   BYVAL ConnectionHandle AS DWORD _                    ' __in  SQLHDBC    ConnectionHandle
 , BYREF StatementHandle AS DWORD _                     ' __out SQLHSTMT  *StatementHandle
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLBindCol IMPORT "ODBC32.DLL" ALIAS "SQLBindCol" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in SQLHSTMT        StatementHandle
 , BYVAL ColumnNumber AS INTEGER _                      ' __in SQLUSMALLINT    ColumnNumber
 , BYVAL TargetType AS INTEGER _                        ' __in SQLSMALLINT     TargetType
 , BYREF TargetValue AS ANY _                           ' __in_out SQLPOINTER  TargetValue
 , BYVAL BufferLength AS LONG _                         ' __in SQLLEN          BufferLength
 , BYREF StrLen_or_Ind AS LONG _                        ' __in_outSQLLEN      *StrLen_or_Ind
 ) AS INTEGER                                           ' SQLRETURN

#IF %ODBCVER >= &H0300
DECLARE FUNCTION SQLBindParam IMPORT "ODBC32.DLL" ALIAS "SQLBindParam" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in SQLHSTMT     StatementHandle
 , BYVAL ParameterNumber AS INTEGER _                   ' __in SQLUSMALLINT ParameterNumber
 , BYVAL ValueType AS INTEGER _                         ' __in SQLSMALLINT  ValueType
 , BYVAL ParameterType AS INTEGER _                     ' __in SQLSMALLINT  ParameterType
 , BYVAL LengthPrecision AS DWORD _                     ' __in SQLULEN      LengthPrecision
 , BYVAL ParameterScale AS INTEGER _                    ' __in SQLSMALLINT  ParameterScale
 , BYREF ParameterValue AS ANY _                        ' __in SQLPOINTER   ParameterValue
 , BYREF StrLen_or_Ind AS LONG _                        ' __in SQLLEN      *StrLen_or_Ind
 ) AS INTEGER                                           ' SQLRETURN
#ENDIF

DECLARE FUNCTION SQLCancel IMPORT "ODBC32.DLL" ALIAS "SQLCancel" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in SQLHSTMT   StatementHandle
 ) AS INTEGER                                           ' SQLRETURN

#IF %ODBCVER >= &H0380
DECLARE FUNCTION SQLCancelHandle IMPORT "ODBC32.DLL" ALIAS "SQLCancelHandle" ( _
   BYVAL HandleType AS INTEGER _                        ' __in SQLSMALLINT HandleType
 , BYVAL InputHandle AS DWORD _                         ' __in SQLHANDLE   InputHandle
 ) AS INTEGER                                           ' SQLRETURN
#ENDIF   '  // ODBCVER >= 0x0380

#IF %ODBCVER >= &H0300
DECLARE FUNCTION SQLCloseCursor IMPORT "ODBC32.DLL" ALIAS "SQLCloseCursor" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in SQLHSTMT   StatementHandle
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLColAttribute IMPORT "ODBC32.DLL" ALIAS "SQLColAttribute" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in  SQLHSTMT     StatementHandle
 , BYVAL ColumnNumber AS WORD _                         ' __in  SQLUSMALLINT ColumnNumber
 , BYVAL FieldIdentifier AS WORD _                      ' __in  SQLUSMALLINT FieldIdentifier
 , BYREF CharacterAttribute AS ANY _                    ' __out SQLPOINTER   CharacterAttribute
 , BYVAL BufferLength AS INTEGER _                      ' __in  SQLSMALLINT  BufferLength
 , BYREF StringLength AS INTEGER _                      ' __out SQLSMALLINT *StringLength
 , BYREF NumericAttribute AS ANY _                      ' __out SQLPOINTER   NumericAttribute
 ) AS INTEGER                                           ' SQLRETURN
#ENDIF

DECLARE FUNCTION SQLColumns IMPORT "ODBC32.DLL" ALIAS "SQLColumns" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in SQLHSTMT     StatementHandle
 , BYREF CatalogName AS ASCIIZ _                        ' __in SQLCHAR     *CatalogName
 , BYVAL NameLength1 AS INTEGER _                       ' __in SQLSMALLINT  NameLength1
 , BYREF SchemaName AS ASCIIZ _                         ' __in SQLCHAR     *SchemaName
 , BYVAL NameLength2 AS INTEGER _                       ' __in SQLSMALLINT  NameLength2
 , BYREF TableName AS ASCIIZ _                          ' __in SQLCHAR     *TableName
 , BYVAL NameLength3 AS INTEGER _                       ' __in SQLSMALLINT  NameLength3
 , BYREF ColumnName AS ASCIIZ _                         ' __in SQLCHAR     *ColumnName
 , BYVAL NameLength4 AS INTEGER _                       ' __in SQLSMALLINT  NameLength4
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLConnect IMPORT "ODBC32.DLL" ALIAS "SQLConnect" ( _
   BYVAL ConnectionHandle AS DWORD _                    ' __in SQLHDBC      ConnectionHandle
 , BYREF ServerName AS ASCIIZ _                         ' __in SQLCHAR     *ServerName
 , BYVAL NameLength1 AS INTEGER _                       ' __in SQLSMALLINT  NameLength1
 , BYREF UserName AS ASCIIZ _                           ' __in SQLCHAR     *UserName
 , BYVAL NameLength2 AS INTEGER _                       ' __in SQLSMALLINT  NameLength2
 , BYREF Authentication AS ASCIIZ _                     ' __in SQLCHAR     *Authentication
 , BYVAL NameLength3 AS INTEGER _                       ' __in SQLSMALLINT  NameLength3
 ) AS INTEGER                                           ' SQLRETURN

#IF %ODBCVER >= &H0300
DECLARE FUNCTION SQLCopyDesc IMPORT "ODBC32.DLL" ALIAS "SQLCopyDesc" ( _
   BYVAL SourceDescHandle AS DWORD  _                   ' __in SQLHDESC   SourceDescHandle
 , BYVAL TargetDescHandle AS DWORD _                    ' __in SQLHDESC   TargetDescHandle
 ) AS INTEGER                                           ' SQLRETURN
#ENDIF

DECLARE FUNCTION SQLDataSources IMPORT "ODBC32.DLL" ALIAS "SQLDataSources" ( _
   BYVAL EnvironmentHandle AS DWORD _                   ' __in  SQLHENV       EnvironmentHandle
 , BYVAL Direction AS WORD _                            ' __in  SQLUSMALLINT  Direction
 , BYREF ServerName AS ASCIIZ _                         ' __out SQLCHAR      *ServerName
 , BYVAL BufferLength1 AS INTEGER _                     ' __in  SQLSMALLINT   BufferLength1
 , BYREF NameLength1 AS INTEGER _                       ' __out SQLSMALLINT  *NameLength1
 , BYREF Description AS ASCIIZ _                        ' __out SQLCHAR      *Description
 , BYVAL BufferLength2 AS INTEGER _                     ' __in  SQLSMALLINT   BufferLength2
 , BYREF NameLength2 AS INTEGER _                       ' __out SQLSMALLINT  *NameLength2
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLDescribeCol IMPORT "ODBC32.DLL" ALIAS "SQLDescribeCol" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in  SQLHSTMT      StatementHandle
 , BYVAL ColumnNumber AS WORD _                         ' __in  SQLUSMALLINT  ColumnNumber
 , BYREF ColumnName AS ASCIIZ _                         ' __out SQLCHAR      *ColumnName
 , BYVAL BufferLength AS INTEGER _                      ' __in  SQLSMALLINT   BufferLength
 , BYREF NameLength AS INTEGER _                        ' __out SQLSMALLINT  *NameLength
 , BYREF DataType AS INTEGER _                          ' __out SQLSMALLINT  *DataType
 , BYREF ColumnSize AS DWORD _                          ' __out SQLULEN      *ColumnSize
 , BYREF DecimalDigits AS INTEGER _                     ' __out SQLSMALLINT  *DecimalDigits
 , BYREF Nullable AS INTEGER _                          ' __out SQLSMALLINT  *Nullable
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLDisconnect IMPORT "ODBC32.DLL" ALIAS "SQLDisconnect" ( _
   BYVAL ConnectionHandle AS DWORD _                    ' __in SQLHDBC    ConnectionHandle
 ) AS INTEGER                                           ' SQLRETURN

#IF %ODBCVER >= &H0300
DECLARE FUNCTION SQLEndTran IMPORT "ODBC32.DLL" ALIAS "SQLEndTran" ( _
   BYVAL HandleType AS INTEGER _                        ' __in SQLSMALLINT HandleType
 , BYVAL Handle AS DWORD _                              ' __in SQLHANDLE   Handle
 , BYVAL CompletionType AS INTEGER _                    ' __in SQLSMALLINT CompletionType
 ) AS INTEGER                                           ' SQLRETURN
#ENDIF

DECLARE FUNCTION SQLError IMPORT "ODBC32.DLL" ALIAS "SQLError" ( _
   BYVAL EnvironmentHandle AS DWORD _                   ' __in  SQLHENV      EnvironmentHandle
 , BYVAL ConnectionHandle AS DWORD _                    ' __in  SQLHDBC      ConnectionHandle
 , BYVAL StatementHandle AS DWORD _                     ' __in  SQLHSTMT     StatementHandle
 , BYREF Sqlstate AS ASCIIZ _                           ' __out SQLCHAR     *Sqlstate
 , BYREF NativeError AS LONG _                          ' __out SQLINTEGER  *NativeError
 , BYREF MessageText AS ASCIIZ _                        ' __out SQLCHAR     *MessageText
 , BYVAL BufferLength AS INTEGER _                      ' __in  SQLSMALLINT  BufferLength
 , BYREF TextLength AS INTEGER _                        ' __out SQLSMALLINT *TextLength
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLExecDirect IMPORT "ODBC32.DLL" ALIAS "SQLExecDirect" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in SQLHSTMT    StatementHandle
 , BYREF StatementText AS ASCIIZ _                      ' __in SQLCHAR    *StatementText
 , BYVAL TextLength AS LONG _                           ' __in SQLINTEGER  TextLength
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLExecute IMPORT "ODBC32.DLL" ALIAS "SQLExecute" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in SQLHSTMT   StatementHandle
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLFetch IMPORT "ODBC32.DLL" ALIAS "SQLFetch" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in SQLHSTMT   StatementHandle
 ) AS INTEGER                                           ' SQLRETURN

#IF %ODBCVER >= &H0300
DECLARE FUNCTION SQLFetchScroll IMPORT "ODBC32.DLL" ALIAS "SQLFetchScroll" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in SQLHSTMT    StatementHandle
 , BYVAL FetchOrientation AS INTEGER _                  ' __in SQLSMALLINT FetchOrientation
 , BYVAL FetchOffset AS LONG _                          ' __in SQLLEN      FetchOffset
 ) AS INTEGER                                           ' SQLRETURN
#ENDIF

DECLARE FUNCTION SQLFreeConnect IMPORT "ODBC32.DLL" ALIAS "SQLFreeConnect" ( _
   BYVAL ConnectionHandle AS DWORD _                    ' __in SQLHDBC    ConnectionHandle
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLFreeEnv IMPORT "ODBC32.DLL" ALIAS "SQLFreeEnv" ( _
   BYVAL EnvironmentHandle AS DWORD _                   ' __in SQLHENV    EnvironmentHandle
 ) AS INTEGER                                           ' SQLRETURN

#IF %ODBCVER >= &H0300
DECLARE FUNCTION SQLFreeHandle IMPORT "ODBC32.DLL" ALIAS "SQLFreeHandle" ( _
   BYVAL HandleType AS INTEGER _                        ' __in SQLSMALLINT HandleType
 , BYVAL Handle AS DWORD _                              ' __in SQLHANDLE   Handle
 ) AS INTEGER                                           ' SQLRETURN
#ENDIF

DECLARE FUNCTION SQLFreeStmt IMPORT "ODBC32.DLL" ALIAS "SQLFreeStmt" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in SQLHSTMT     StatementHandle
 , BYVAL Option AS WORD _                               ' __in SQLUSMALLINT Option
 ) AS INTEGER                                           ' SQLRETURN

#IF %ODBCVER >= &H0300
DECLARE FUNCTION SQLGetConnectAttr IMPORT "ODBC32.DLL" ALIAS "SQLGetConnectAttr" ( _
   BYVAL ConnectionHandle AS DWORD _                    ' __in  SQLHDBC     ConnectionHandle
 , BYVAL Attribute AS LONG _                            ' __in  SQLINTEGER  Attribute
 , BYREF Value AS ANY _                                 ' __out SQLPOINTER  Value
 , BYVAL BufferLength AS LONG _                         ' __in  SQLINTEGER  BufferLength
 , BYREF StringLength AS LONG _                         ' __out SQLINTEGER *StringLength
 ) AS INTEGER                                           ' SQLRETURN
#ENDIF

DECLARE FUNCTION SQLGetConnectOption IMPORT "ODBC32.DLL" ALIAS "SQLGetConnectOption" ( _
   BYVAL ConnectionHandle AS DWORD _                    ' __in  SQLHDBC      ConnectionHandle
 , BYVAL Option AS WORD _                               ' __in  SQLUSMALLINT Option
 , BYREF Value AS ANY _                                 ' __out SQLPOINTER   Value
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLGetCursorName IMPORT "ODBC32.DLL" ALIAS "SQLGetCursorName" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in  SQLHSTMT     StatementHandle
 , BYREF CursorName AS ASCIIZ _                         ' __out SQLCHAR     *CursorName
 , BYVAL BufferLength AS INTEGER _                      ' __in  SQLSMALLINT  BufferLength
 , BYREF NameLength AS INTEGER _                        ' __out SQLSMALLINT *NameLength
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLGetData IMPORT "ODBC32.DLL" ALIAS "SQLGetData" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in  SQLHSTMT      StatementHandle
 , BYVAL ColumnNumber AS WORD _                         ' __in  SQLUSMALLINT  ColumnNumber
 , BYVAL TargetType AS INTEGER _                        ' __in  SQLSMALLINT   TargetType
 , BYREF TargetValue AS ANY _                           ' __out SQLPOINTER    TargetValue
 , BYVAL BufferLength AS LONG _                         ' __in  SQLLEN        BufferLength
 , BYREF StrLen_or_Ind AS LONG _                        ' __out SQLLEN       *StrLen_or_Ind
 ) AS INTEGER                                           ' SQLRETURN

#IF %ODBCVER >= &H0300
DECLARE FUNCTION SQLGetDescField IMPORT "ODBC32.DLL" ALIAS "SQLGetDescField" ( _
   BYVAL DescriptorHandle AS DWORD _                    ' __in  SQLHDESC     DescriptorHandle
 , BYVAL RecNumber AS INTEGER _                         ' __in  SQLSMALLINT  RecNumber
 , BYVAL FieldIdentifier AS INTEGER _                   ' __in  SQLSMALLINT  FieldIdentifier
 , BYREF Value AS ANY _                                 ' __out SQLPOINTER   Value
 , BYVAL BufferLength AS LONG _                         ' __in  SQLINTEGER   BufferLength
 , BYREF StringLength AS LONG _                         ' __out SQLINTEGER  *StringLength
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLGetDescRec IMPORT "ODBC32.DLL" ALIAS "SQLGetDescRec" ( _
   BYVAL DescriptorHandle AS DWORD _                    ' __in  SQLHDESC     DescriptorHandle
 , BYVAL RecNumber AS INTEGER _                         ' __in  SQLSMALLINT  RecNumber
 , BYREF Name AS ASCIIZ _                               ' __out SQLCHAR     *Name
 , BYVAL BufferLength AS INTEGER _                      ' __in  SQLSMALLINT  BufferLength
 , BYREF StringLength AS INTEGER _                      ' __out SQLSMALLINT *StringLength
 , BYREF Type AS INTEGER _                              ' __out SQLSMALLINT *Type
 , BYREF SubType AS INTEGER _                           ' __out SQLSMALLINT *SubType
 , BYREF Length AS LONG _                               ' __out SQLLEN      *Length
 , BYREF Precision AS INTEGER _                         ' __out SQLSMALLINT *Precision
 , BYREF Scale AS INTEGER _                             ' __out SQLSMALLINT *Scale
 , BYREF Nullable AS INTEGER _                          ' __out SQLSMALLINT *Nullable
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLGetDiagField IMPORT "ODBC32.DLL" ALIAS "SQLGetDiagField" ( _
   BYVAL HandleType AS INTEGER _                        ' __in  SQLSMALLINT  HandleType
 , BYVAL Handle AS DWORD _                              ' __in  SQLHANDLE    Handle
 , BYVAL RecNumber AS INTEGER _                         ' __in  SQLSMALLINT  RecNumber
 , BYVAL DiagIdentifier AS INTEGER _                    ' __in  SQLSMALLINT  DiagIdentifier
 , BYREF DiagInfo AS ANY _                              ' __out SQLPOINTER   DiagInfo
 , BYVAL BufferLength AS INTEGER _                      ' __in  SQLSMALLINT  BufferLength
 , BYREF StringLength AS INTEGER _                      ' __out SQLSMALLINT *StringLength
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLGetDiagRec IMPORT "ODBC32.DLL" ALIAS "SQLGetDiagRec" ( _
   BYVAL HandleType AS INTEGER _                        ' __in  SQLSMALLINT  HandleType
 , BYVAL Handle AS DWORD _                              ' __in  SQLHANDLE    Handle
 , BYVAL RecNumber AS INTEGER _                         ' __in  SQLSMALLINT  RecNumber
 , BYREF Sqlstate AS ASCIIZ _                           ' __out SQLCHAR     *Sqlstate
 , BYREF NativeError AS LONG _                          ' __out SQLINTEGER  *NativeError
 , BYREF MessageText AS ASCIIZ _                        ' __out SQLCHAR     *MessageText
 , BYVAL BufferLength AS INTEGER _                      ' __out SQLSMALLINT  BufferLength
 , BYREF TextLength AS INTEGER _                        ' __out SQLSMALLINT *TextLength
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLGetEnvAttr IMPORT "ODBC32.DLL" ALIAS "SQLGetEnvAttr" ( _
   BYVAL EnvironmentHandle AS DWORD _                   ' __in  SQLHENV     EnvironmentHandle
 , BYVAL Attribute AS LONG _                            ' __in  SQLINTEGER  Attribute
 , BYREF Value AS ANY _                                 ' __out SQLPOINTER  Value
 , BYVAL BufferLength AS LONG _                         ' __in  SQLINTEGER  BufferLength
 , BYREF StringLength AS LONG _                         ' __out SQLINTEGER *StringLength
 ) AS INTEGER                                           ' SQLRETURN
#ENDIF   ' /* ODBCVER >= 0x0300 */

DECLARE FUNCTION SQLGetFunctions IMPORT "ODBC32.DLL" ALIAS "SQLGetFunctions" ( _
   BYVAL ConnectionHandle AS DWORD _                    ' __in  SQLHDBC       ConnectionHandle
 , BYVAL FunctionId AS WORD _                           ' __in  SQLUSMALLINT  FunctionId
 , BYREF Supported AS WORD _                            ' __out SQLUSMALLINT *Supported
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLGetInfo IMPORT "ODBC32.DLL" ALIAS "SQLGetInfo" ( _
   BYVAL ConnectionHandle AS DWORD _                    ' __in  SQLHDBC      ConnectionHandle
 , BYVAL InfoType AS WORD _                             ' __in  SQLUSMALLINT InfoType
 , BYREF InfoValue AS ANY _                             ' __out SQLPOINTER   InfoValue
 , BYVAL BufferLength AS INTEGER _                      ' __in  SQLSMALLINT  BufferLength
 , BYREF StringLength AS INTEGER _                      ' __out SQLSMALLINT *StringLength
 ) AS INTEGER                                           ' SQLRETURN

#IF %ODBCVER >= &H0300
DECLARE FUNCTION SQLGetStmtAttr IMPORT "ODBC32.DLL" ALIAS "SQLGetStmtAttr" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in  SQLHSTMT    StatementHandle
 , BYVAL Attribute AS LONG _                            ' __in  SQLINTEGER  Attribute
 , BYREF Value AS ANY _                                 ' __out SQLPOINTER  Value
 , BYVAL BufferLength AS LONG _                         ' __in  SQLINTEGER  BufferLength
 , BYREF StringLength AS LONG _                         ' __out SQLINTEGER *StringLength
 ) AS INTEGER                                           ' SQLRETURN
#ENDIF   ' /* ODBCVER >= 0x0300 */

DECLARE FUNCTION SQLGetStmtOption IMPORT "ODBC32.DLL" ALIAS "SQLGetStmtOption" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in  SQLHSTMT     StatementHandle
 , BYVAL Option AS WORD _                               ' __in  SQLUSMALLINT Option
 , BYREF Value AS ANY _                                 ' __out SQLPOINTER   Value
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLGetTypeInfo IMPORT "ODBC32.DLL" ALIAS "SQLGetTypeInfo" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in SQLHSTMT    StatementHandle
 , BYVAL DataType AS INTEGER _                          ' __in SQLSMALLINT DataType
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLNumResultCols IMPORT "ODBC32.DLL" ALIAS "SQLNumResultCols" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in  SQLHSTMT     StatementHandle
 , BYREF ColumnCount AS INTEGER _                       ' __out SQLSMALLINT *ColumnCount
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLParamData IMPORT "ODBC32.DLL" ALIAS "SQLParamData" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in  SQLHSTMT    StatementHandle
 , BYREF Value AS ANY _                                 ' __out SQLPOINTER *Value
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLPrepare IMPORT "ODBC32.DLL" ALIAS "SQLPrepare" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in SQLHSTMT    StatementHandle
 , BYREF StatementText AS ASCIIZ _                      ' __in SQLCHAR    *StatementText
 , BYVAL TextLength AS LONG _                           ' __in SQLINTEGER  TextLength
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLPutData IMPORT "ODBC32.DLL" ALIAS "SQLPutData" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in SQLHSTMT   StatementHandle
 , BYREF Data As ANY _                                  ' __in SQLPOINTER Data
 , BYVAL StrLen_or_Ind AS LONG _                        ' __in SQLLEN     StrLen_or_Ind
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLRowCount IMPORT "ODBC32.DLL" ALIAS "SQLRowCount" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in  SQLHSTMT StatementHandle
 , BYREF RowCount AS LONG _                             ' __out SQLLEN  *RowCount
 ) AS INTEGER                                           ' SQLRETURN

#IF %ODBCVER >= &H0300
DECLARE FUNCTION SQLSetConnectAttr IMPORT "ODBC32.DLL" ALIAS "SQLSetConnectAttr" ( _
   BYVAL ConnectionHandle AS DWORD _                    ' __in SQLHDBC    ConnectionHandle
 , BYVAL Attribute AS LONG _                            ' __in SQLINTEGER Attribute
 , BYREF Value AS ANY _                                 ' __in SQLPOINTER Value
 , BYVAL StringLength AS LONG _                         ' __in SQLINTEGER StringLength
 ) AS INTEGER                                           ' SQLRETURN
#ENDIF   ' /* ODBCVER >= 0x0300 */

DECLARE FUNCTION SQLSetConnectOption IMPORT "ODBC32.DLL" ALIAS "SQLSetConnectOption" ( _
   BYVAL ConnectionHandle AS DWORD _                    ' __in SQLHDBC      ConnectionHandle
 , BYVAL Option AS WORD _                               ' __in SQLUSMALLINT Option
 , BYVAL Value AS DWORD _                               ' __in SQLULEN      Value
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLSetCursorName IMPORT "ODBC32.DLL" ALIAS "SQLSetCursorName" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in SQLHSTMT     StatementHandle
 , BYREF CursorName AS ASCIIZ _                         ' __in SQLCHAR     *CursorName
 , BYVAL NameLength AS INTEGER _                        ' __in SQLSMALLINT  NameLength
 ) AS INTEGER                                           ' SQLRETURN

#IF %ODBCVER >= &H0300
DECLARE FUNCTION SQLSetDescField IMPORT "ODBC32.DLL" ALIAS "SQLSetDescField" ( _
   BYVAL DescriptorHandle AS DWORD _                    ' __in SQLHDESC    DescriptorHandle
 , BYVAL RecNumber AS INTEGER _                         ' __in SQLSMALLINT RecNumber
 , BYVAL FieldIdentifier AS INTEGER _                   ' __in SQLSMALLINT FieldIdentifier
 , BYREF Value AS ANY _                                 ' __in SQLPOINTER  Value
 , BYVAL BufferLength AS LONG _                         ' __in SQLINTEGER  BufferLength
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLSetDescRec IMPORT "ODBC32.DLL" ALIAS "SQLSetDescRec" ( _
   BYVAL DescriptorHandle AS DWORD _                    ' __in     SQLHDESC     DescriptorHandle
 , BYVAL RecNumber AS INTEGER _                         ' __in     SQLSMALLINT  RecNumber
 , BYVAL Type AS INTEGER _                              ' __in     SQLSMALLINT  Type
 , BYVAL SubType AS INTEGER _                           ' __in     SQLSMALLINT  SubType
 , BYVAL Length AS LONG _                               ' __in     SQLLEN       Length
 , BYVAL Precision AS INTEGER _                         ' __in     SQLSMALLINT  Precision
 , BYVAL Scale AS INTEGER _                             ' __in     SQLSMALLINT  Scale
 , BYREF Data AS ANY _                                  ' __in_out SQLPOINTER   Data
 , BYREF StringLength AS LONG _                         ' __in_out SQLLEN      *StringLength
 , BYREF Indicator AS LONG _                            ' __in_out SQLLEN      *Indicator
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLSetEnvAttr IMPORT "ODBC32.DLL" ALIAS "SQLSetEnvAttr" ( _
   BYVAL EnvironmentHandle AS DWORD _                   ' __in SQLHENV    EnvironmentHandle
 , BYVAL Attribute AS LONG _                            ' __in SQLINTEGER Attribute
 , BYREF Value AS ANY _                                 ' __in SQLPOINTER Value
 , BYVAL StringLength AS LONG _                         ' __in SQLINTEGER StringLength
 ) AS INTEGER                                           ' SQLRETURN
#ENDIF   ' /* ODBCVER >= 0x0300 */

DECLARE FUNCTION SQLSetParam IMPORT "ODBC32.DLL" ALIAS "SQLSetParam" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in SQLHSTMT      StatementHandle
 , BYVAL ParameterNumber AS WORD _                      ' __in SQLUSMALLINT  ParameterNumber
 , BYVAL ValueType AS INTEGER _                         ' __in SQLSMALLINT   ValueType
 , BYVAL ParameterType AS INTEGER _                     ' __in SQLSMALLINT   ParameterType
 , BYVAL LengthPrecision AS DWORD _                     ' __in SQLULEN       LengthPrecision
 , BYVAL ParameterScale AS INTEGER _                    ' __in SQLSMALLINT   ParameterScale
 , BYREF ParameterValue AS ANY _                        ' __in SQLPOINTER    ParameterValue
 , BYREF StrLen_or_Ind AS LONG _                        ' __in SQLLEN       *StrLen_or_Ind
 ) AS INTEGER                                           ' SQLRETURN


#IF %ODBCVER >= &H0300
DECLARE FUNCTION SQLSetStmtAttr IMPORT "ODBC32.DLL" ALIAS "SQLSetStmtAttr" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in SQLHSTMT   StatementHandle
 , BYVAL Attribute AS LONG _                            ' __in SQLINTEGER Attribute
 , BYREF Value AS ANY _                                 ' __in SQLPOINTER Value
 , BYVAL StringLength AS LONG _                         ' __in SQLINTEGER StringLength
 ) AS INTEGER                                           ' SQLRETURN
#ENDIF

DECLARE FUNCTION SQLSetStmtOption IMPORT "ODBC32.DLL" ALIAS "SQLSetStmtOption" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in SQLHSTMT     StatementHandle
 , BYVAL Option As WORD _                               ' __in SQLUSMALLINT Option
 , BYVAL Value AS DWORD _                               ' __in SQLULEN      Value
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLSpecialColumns IMPORT "ODBC32.DLL" ALIAS "SQLSpecialColumns" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in SQLHSTMT      StatementHandle
 , BYVAL IdentifierType AS WORD _                       ' __in SQLUSMALLINT  IdentifierType
 , BYREF CatalogName AS ASCIIZ _                        ' __in SQLCHAR      *CatalogName
 , BYVAL NameLength1 AS INTEGER _                       ' __in SQLSMALLINT   NameLength1
 , BYREF SchemaName AS ASCIIZ _                         ' __in SQLCHAR      *SchemaName
 , BYVAL NameLength2 AS INTEGER _                       ' __in SQLSMALLINT   NameLength2
 , BYREF TableName AS ASCIIZ _                          ' __in SQLCHAR      *TableName
 , BYVAL NameLength3 AS INTEGER _                       ' __in SQLSMALLINT   NameLength3
 , BYVAL Scope AS WORD _                                ' __in SQLUSMALLINT  Scope
 , BYVAL Nullable AS WORD _                             ' __in SQLUSMALLINT  Nullable
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLStatistics IMPORT "ODBC32.DLL" ALIAS "SQLStatistics" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in SQLHSTMT      StatementHandle
 , BYREF CatalogName AS ASCIIZ _                        ' __in SQLCHAR      *CatalogName
 , BYVAL NameLength1 AS INTEGER _                       ' __in SQLSMALLINT   NameLength1
 , BYREF SchemaName AS ASCIIZ _                         ' __in SQLCHAR      *SchemaName
 , BYVAL NameLength2 AS INTEGER _                       ' __in SQLSMALLINT   NameLength2
 , BYREF TableName AS ASCIIZ _                          ' __in SQLCHAR      *TableName
 , BYVAL NameLength3 AS INTEGER _                       ' __in SQLSMALLINT   NameLength3
 , BYVAL Unique AS WORD _                               ' __in SQLUSMALLINT  Unique
 , BYVAL Reserved AS WORD _                             ' __in SQLUSMALLINT  Reserved
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLTables IMPORT "ODBC32.DLL" ALIAS "SQLTables" ( _
   BYVAL StatementHandle AS DWORD _                     ' __in SQLHSTMT     StatementHandle
 , BYREF CatalogName AS ASCIIZ _                        ' __in SQLCHAR     *CatalogName
 , BYVAL NameLength1 AS INTEGER _                       ' __in SQLSMALLINT  NameLength1
 , BYREF SchemaName AS ASCIIZ _                         ' __in SQLCHAR     *SchemaName
 , BYVAL NameLength2 AS INTEGER _                       ' __in SQLSMALLINT  NameLength2
 , BYREF TableName AS ASCIIZ _                          ' __in SQLCHAR     *TableName
 , BYVAL NameLength3 AS INTEGER _                       ' __in SQLSMALLINT  NameLength3
 , BYREF TableType AS ASCIIZ _                          ' __in SQLCHAR     *TableType
 , BYVAL NameLength4 AS INTEGER _                       ' __in SQLSMALLINT  NameLength4
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLTransact IMPORT "ODBC32.DLL" ALIAS "SQLTransact" ( _
   BYVAL EnvironmentHandle AS DWORD _                   ' __in SQLHENV      EnvironmentHandle
 , BYVAL ConnectionHandle AS DWORD _                    ' __in SQLHDBC      ConnectionHandle
 , BYVAL CompletionType AS WORD _                       ' __in SQLUSMALLINT CompletionType
 ) AS INTEGER                                           ' SQLRETURN
