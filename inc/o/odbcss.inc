' ########################################################################################
' Microsoft Windows
' File: odbcss.inc
' Contents: This is the application include file for the SQL Server driver specific defines.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ODBCSS_INC = 1

#INCLUDE ONCE "sqlext.inc"

'//   Useful defines
%SQL_MAX_SQLSERVERNAME  = 128     ' // max SQL Server identifier length

'//   SQLSetConnectOption/SQLSetStmtOption driver specific defines.
'//   Microsoft has 1200 thru 1249 reserved for Microsoft SQL Server driver usage.

'//   Connection Options
%SQL_COPT_SS_BASE                = 1200
%SQL_COPT_SS_REMOTE_PWD          = %SQL_COPT_SS_BASE+1  ' // dbrpwset SQLSetConnectOption only
%SQL_COPT_SS_USE_PROC_FOR_PREP   = %SQL_COPT_SS_BASE+2  ' // Use create proc for SQLPrepare
%SQL_COPT_SS_INTEGRATED_SECURITY = %SQL_COPT_SS_BASE+3  ' // Force integrated security on login
%SQL_COPT_SS_PRESERVE_CURSORS    = %SQL_COPT_SS_BASE+4  ' // Preserve server cursors after SQLTransact
%SQL_COPT_SS_USER_DATA           = %SQL_COPT_SS_BASE+5  ' // dbgetuserdata/dbsetuserdata
%SQL_COPT_SS_ENLIST_IN_DTC       = %SQL_ATTR_ENLIST_IN_DTC  ' // Enlist in a DTC transaction
%SQL_COPT_SS_ENLIST_IN_XA        = %SQL_ATTR_ENLIST_IN_XA   ' // Enlist in a XA transaction
'//SQL_ATTR_CONNECTION_DEAD 1209 (It will return current connection status, it will not go to server
%SQL_COPT_SS_FALLBACK_CONNECT    = %SQL_COPT_SS_BASE+10  ' // Enables FallBack connections
%SQL_COPT_SS_PERF_DATA           = %SQL_COPT_SS_BASE+11  ' // Used to access SQL Server ODBC driver performance data
%SQL_COPT_SS_PERF_DATA_LOG       = %SQL_COPT_SS_BASE+12  ' // Used to set the logfile name for the Performance data
%SQL_COPT_SS_PERF_QUERY_INTERVAL = %SQL_COPT_SS_BASE+13  ' // Used to set the query logging threshold in milliseconds.
%SQL_COPT_SS_PERF_QUERY_LOG      = %SQL_COPT_SS_BASE+14  ' // Used to set the logfile name for saving queryies.
%SQL_COPT_SS_PERF_QUERY          = %SQL_COPT_SS_BASE+15  ' // Used to start and stop query logging.
%SQL_COPT_SS_PERF_DATA_LOG_NOW   = %SQL_COPT_SS_BASE+16  ' // Used to make a statistics log entry to disk.
%SQL_COPT_SS_QUOTED_IDENT        = %SQL_COPT_SS_BASE+17  ' // Enable/Disable Quoted Identifiers
%SQL_COPT_SS_ANSI_NPW            = %SQL_COPT_SS_BASE+18  ' // Enable/Disable ANSI NULL, Padding and Warnings
%SQL_COPT_SS_BCP                 = %SQL_COPT_SS_BASE+19  ' // Allow BCP usage on connection
%SQL_COPT_SS_TRANSLATE           = %SQL_COPT_SS_BASE+20  ' // Perform code page translation
%SQL_COPT_SS_ATTACHDBFILENAME    = %SQL_COPT_SS_BASE+21  ' // File name to be attached as a database
%SQL_COPT_SS_CONCAT_NULL         = %SQL_COPT_SS_BASE+22  ' // Enable/Disable CONCAT_NULL_YIELDS_NULL
%SQL_COPT_SS_ENCRYPT             = %SQL_COPT_SS_BASE+23  ' // Allow strong encryption for data

'%SQL_COPT_SS_MAX_USED            = %SQL_COPT_SS_ENCRYPT

'//   Statement Options
%SQL_SOPT_SS_BASE                = 1225
%SQL_SOPT_SS_TEXTPTR_LOGGING     = %SQL_SOPT_SS_BASE+0  ' // Text pointer logging
%SQL_SOPT_SS_CURRENT_COMMAND     = %SQL_SOPT_SS_BASE+1  ' // dbcurcmd SQLGetStmtOption only
%SQL_SOPT_SS_HIDDEN_COLUMNS      = %SQL_SOPT_SS_BASE+2  ' // Expose FOR BROWSE hidden columns
%SQL_SOPT_SS_NOBROWSETABLE       = %SQL_SOPT_SS_BASE+3  ' // Set NOBROWSETABLE option
%SQL_SOPT_SS_REGIONALIZE         = %SQL_SOPT_SS_BASE+4  ' // Regionalize output character conversions
%SQL_SOPT_SS_CURSOR_OPTIONS      = %SQL_SOPT_SS_BASE+5  ' // Server cursor options
%SQL_SOPT_SS_NOCOUNT_STATUS      = %SQL_SOPT_SS_BASE+6  ' // Real vs. Not Real row count indicator
%SQL_SOPT_SS_DEFER_PREPARE       = %SQL_SOPT_SS_BASE+7  ' // Defer prepare until necessary

'%SQL_SOPT_SS_MAX_USED            = %SQL_SOPT_SS_DEFER_PREPARE

%SQL_COPT_SS_BASE_EX             = 1240
%SQL_COPT_SS_BROWSE_CONNECT      = %SQL_COPT_SS_BASE_EX+1  ' // Browse connect mode of operation
%SQL_COPT_SS_BROWSE_SERVER       = %SQL_COPT_SS_BASE_EX+2  ' // Single Server browse request.
%SQL_COPT_SS_WARN_ON_CP_ERROR    = %SQL_COPT_SS_BASE_EX+3  ' // Issues warning when data from the server
                                                           ' // had a loss during code page conversion.

%SQL_COPT_SS_CONNECTION_DEAD     = %SQL_COPT_SS_BASE_EX+4  ' // dbdead SQLGetConnectOption only
                                                           ' // It will try to ping the server.
                                                           ' // Expensive connection check

%SQL_COPT_SS_BROWSE_CACHE_DATA   = %SQL_COPT_SS_BASE_EX+5  ' //Determines if we should cache browse info
                                                           ' //Used when returned buffer is greater then ODBC limit (32K

%SQL_COPT_SS_RESET_CONNECTION    = %SQL_COPT_SS_BASE_EX+6  ' //When this option is set, we will perform connection reset
                                                           ' //on next packet


'%SQL_COPT_SS_EX_MAX_USED         = %SQL_COPT_SS_RESET_CONNECTION

'//   Defines for use with SQL_COPT_SS_USE_PROC_FOR_PREP
%SQL_UP_OFF     = 0&          ' //   Procedures won't be used for prepare
%SQL_UP_ON      = 1&          ' //   Procedures will be used for prepare
%SQL_UP_ON_DROP = 2&          ' //   Temp procedures will be explicitly dropped
%SQL_UP_DEFAULT = %SQL_UP_ON

'//   Defines for use with SQL_COPT_SS_INTEGRATED_SECURITY - Pre-Connect Option only
%SQL_IS_OFF     = 0&          ' //   Integrated security isn't used
%SQL_IS_ON      = 1&          ' //   Integrated security is used
%SQL_IS_DEFAULT = %SQL_IS_OFF

'//   Defines for use with SQL_COPT_SS_PRESERVE_CURSORS
%SQL_PC_OFF     = 0&          ' //   Cursors are closed on SQLTransact
%SQL_PC_ON      = 1&          ' //   Cursors remain open on SQLTransact
%SQL_PC_DEFAULT = %SQL_PC_OFF

'//   Defines for use with SQL_COPT_SS_USER_DATA
%SQL_UD_NOTSET  = %NULL       ' //   No user data pointer set

'//   Defines for use with SQL_COPT_SS_TRANSLATE
%SQL_XL_OFF     = 0&          ' //   Code page translation is not performed
%SQL_XL_ON      = 1&          ' //   Code page translation is performed
%SQL_XL_DEFAULT = %SQL_XL_ON

'//   Defines for use with SQL_COPT_SS_FALLBACK_CONNECT - Pre-Connect Option only
%SQL_FB_OFF     = 0&          ' //   FallBack connections are disabled
%SQL_FB_ON      = 1&          ' //   FallBack connections are enabled
%SQL_FB_DEFAULT = %SQL_FB_OFF

'//   Defines for use with SQL_COPT_SS_BCP - Pre-Connect Option only
%SQL_BCP_OFF     = 0&         ' //   BCP is not allowed on connection
%SQL_BCP_ON      = 1&         ' //   BCP is allowed on connection
%SQL_BCP_DEFAULT = %SQL_BCP_OFF

'//   Defines for use with SQL_COPT_SS_QUOTED_IDENT
%SQL_QI_OFF     = 0&          ' //   Quoted identifiers are enable
%SQL_QI_ON      = 1&          ' //   Quoted identifiers are disabled
%SQL_QI_DEFAULT = %SQL_QI_ON

'//   Defines for use with SQL_COPT_SS_ANSI_NPW - Pre-Connect Option only
%SQL_AD_OFF     = 0&          ' //   ANSI NULLs, Padding and Warnings are enabled
%SQL_AD_ON      = 1&          ' //   ANSI NULLs, Padding and Warnings are disabled
%SQL_AD_DEFAULT = %SQL_AD_ON

'//   Defines for use with SQL_COPT_SS_CONCAT_NULL - Pre-Connect Option only
%SQL_CN_OFF     = 0&          ' //  CONCAT_NULL_YIELDS_NULL is off
%SQL_CN_ON      = 1&          ' //  CONCAT_NULL_YIELDS_NULL is on
%SQL_CN_DEFAULT = %SQL_CN_ON

'//   Defines for use with SQL_SOPT_SS_TEXTPTR_LOGGING
%SQL_TL_OFF     = 0&          ' //   No logging on text pointer ops
%SQL_TL_ON      = 1&          ' //   Logging occurs on text pointer ops
%SQL_TL_DEFAULT = %SQL_TL_ON

'//   Defines for use with SQL_SOPT_SS_HIDDEN_COLUMNS
%SQL_HC_OFF     = 0&          ' //  FOR BROWSE columns are hidden
%SQL_HC_ON      = 1&          ' //  FOR BROWSE columns are exposed
%SQL_HC_DEFAULT = %SQL_HC_OFF

'//   Defines for use with SQL_SOPT_SS_NOBROWSETABLE
%SQL_NB_OFF     = 0&          ' //   NO_BROWSETABLE is off
%SQL_NB_ON      = 1&          ' //   NO_BROWSETABLE is on
%SQL_NB_DEFAULT = %SQL_NB_OFF

'//   Defines for use with SQL_SOPT_SS_REGIONALIZE
%SQL_RE_OFF     = 0&          ' //   No regionalization occurs on output character conversions
%SQL_RE_ON      = 1&          ' //   Regionalization occurs on output character conversions
%SQL_RE_DEFAULT = %SQL_RE_OFF

'//   Defines for use with SQL_SOPT_SS_CURSOR_OPTIONS
%SQL_CO_OFF         = 0&        ' //   Clear all cursor options
%SQL_CO_FFO         = 1&        ' //   Fast-forward cursor will be used
%SQL_CO_AF          = 2&        ' //   Autofetch on cursor open
%SQL_CO_FFO_AF      = %SQL_CO_FFO OR %SQL_CO_AF  ' //   Fast-forward cursor with autofetch
%SQL_CO_FIREHOSE_AF = 4&        ' //  Auto fetch on fire-hose cursors
%SQL_CO_DEFAULT     = %SQL_CO_OFF

'//SQL_SOPT_SS_NOCOUNT_STATUS
%SQL_NC_OFF     = 0&
%SQL_NC_ON      = 1&

'//SQL_SOPT_SS_DEFER_PREPARE
%SQL_DP_OFF     = 0&
%SQL_DP_ON      = 1&

'//SQL_COPT_SS_ENCRYPT
%SQL_EN_OFF     = 0&
%SQL_EN_ON      = 1&

'//SQL_COPT_SS_BROWSE_CONNECT
%SQL_MORE_INFO_NO  = 0&
%SQL_MORE_INFO_YES = 1&

'//SQL_COPT_SS_BROWSE_CACHE_DATA
%SQL_CACHE_DATA_NO  = 0&
%SQL_CACHE_DATA_YES = 1&

'//SQL_COPT_SS_RESET_CONNECTION
%SQL_RESET_YES = 1&

'//SQL_COPT_SS_WARN_ON_CP_ERROR
%SQL_WARN_NO  = 0&
%SQL_WARN_YES = 1&

'//   Defines returned by SQL_ATTR_CURSOR_TYPE/SQL_CURSOR_TYPE
%SQL_CURSOR_FAST_FORWARD_ONLY = 8  ' //   Only returned by SQLGetStmtAttr/Option


'//   SQLColAttributes driver specific defines.
'//   SQLSet/GetDescField driver specific defines.
'//   Microsoft has 1200 thru 1249 reserved for Microsoft SQL Server driver usage.

%SQL_CA_SS_BASE                  = 1200
%SQL_CA_SS_COLUMN_SSTYPE         = %SQL_CA_SS_BASE+0   ' // dbcoltype/dbalttype
%SQL_CA_SS_COLUMN_UTYPE          = %SQL_CA_SS_BASE+1   ' // dbcolutype/dbaltutype
%SQL_CA_SS_NUM_ORDERS            = %SQL_CA_SS_BASE+2   ' // dbnumorders
%SQL_CA_SS_COLUMN_ORDER          = %SQL_CA_SS_BASE+3   ' // dbordercol
%SQL_CA_SS_COLUMN_VARYLEN        = %SQL_CA_SS_BASE+4   ' // dbvarylen
%SQL_CA_SS_NUM_COMPUTES          = %SQL_CA_SS_BASE+5   ' // dbnumcompute
%SQL_CA_SS_COMPUTE_ID            = %SQL_CA_SS_BASE+6   ' // dbnextrow status return
%SQL_CA_SS_COMPUTE_BYLIST        = %SQL_CA_SS_BASE+7   ' // dbbylist
%SQL_CA_SS_COLUMN_ID             = %SQL_CA_SS_BASE+8   ' // dbaltcolid
%SQL_CA_SS_COLUMN_OP             = %SQL_CA_SS_BASE+9   ' // dbaltop
%SQL_CA_SS_COLUMN_SIZE           = %SQL_CA_SS_BASE+10  ' // dbcollen
%SQL_CA_SS_COLUMN_HIDDEN         = %SQL_CA_SS_BASE+11  ' // Column is hidden (FOR BROWSE
%SQL_CA_SS_COLUMN_KEY            = %SQL_CA_SS_BASE+12  ' // Column is key column (FOR BROWSE
' //%SQL_DESC_BASE_COLUMN_NAME_OLD = %SQL_CA_SS_BASE+13  ' // This is defined at another location.
%SQL_CA_SS_COLUMN_COLLATION      = %SQL_CA_SS_BASE+14  ' // Column collation (only for chars
%SQL_CA_SS_VARIANT_TYPE          = %SQL_CA_SS_BASE+15
%SQL_CA_SS_VARIANT_SQL_TYPE      = %SQL_CA_SS_BASE+16
%SQL_CA_SS_VARIANT_SERVER_TYPE   = %SQL_CA_SS_BASE+17
'%SQL_CA_SS_MAX_USED              = %SQL_CA_SS_BASE+18


'//   SQL Server Data Type Tokens.
'//   New types for 6.0 and later servers
'/* SQL Server Data Type Tokens. */
%SQLTEXT         = &H23
%SQLVARBINARY    = &H25
%SQLINTN         = &H26
%SQLVARCHAR      = &H27
%SQLBINARY       = &H2d
%SQLIMAGE        = &H22
%SQLCHARACTER    = &H2f
%SQLINT1         = &H30
%SQLBIT          = &H32
%SQLINT2         = &H34
%SQLINT4         = &H38
%SQLMONEY        = &H3c
%SQLDATETIME     = &H3d
%SQLFLT8         = &H3e
%SQLFLTN         = &H6d
%SQLMONEYN       = &H6e
%SQLDATETIMN     = &H6f
%SQLFLT4         = &H3b
%SQLMONEY4       = &H7a
%SQLDATETIM4     = &H3a
'//   New types for 6.0 and later servers
%SQLDECIMAL      = &H6a
%SQLNUMERIC      = &H6c
'//   New types for 7.0 and later servers
%SQLUNIQUEID     = &H24
%SQLBIGCHAR      = &Haf
%SQLBIGVARCHAR   = &Ha7
%SQLBIGBINARY    = &Had
%SQLBIGVARBINARY = &Ha5
%SQLBITN         = &H68
%SQLNCHAR        = &Hef
%SQLNVARCHAR     = &He7
%SQLNTEXT        = &H63
'// New for 7.x
%SQLINT8         = &H7f
%SQLVARIANT      = &H62

'//   User Data Type definitions.
'//   Returned by SQLColAttributes/SQL_CA_SS_COLUMN_UTYPE.
%SQLudtBINARY           = 3
%SQLudtBIT              = 16
%SQLudtBITN             = 0
%SQLudtCHAR             = 1
%SQLudtDATETIM4         = 22
%SQLudtDATETIME         = 12
%SQLudtDATETIMN         = 15
%SQLudtDECML            = 24
%SQLudtDECMLN           = 26
%SQLudtFLT4             = 23
%SQLudtFLT8             = 8
%SQLudtFLTN             = 14
%SQLudtIMAGE            = 20
%SQLudtINT1             = 5
%SQLudtINT2             = 6
%SQLudtINT4             = 7
%SQLudtINTN             = 13
%SQLudtMONEY            = 11
%SQLudtMONEY4           = 21
%SQLudtMONEYN           = 17
%SQLudtNUM              = 10
%SQLudtNUMN             = 25
%SQLudtSYSNAME          = 18
%SQLudtTEXT             = 19
%SQLudtTIMESTAMP        = 80
%SQLudtUNIQUEIDENTIFIER = 0
%SQLudtVARBINARY        = 4
%SQLudtVARCHAR          = 2
%MIN_USER_DATATYPE      = 256

'//   Aggregate operator types.
'//   Returned by SQLColAttributes/SQL_CA_SS_COLUMN_OP.
%SQLAOPSTDEV  = &H30   ' // Standard deviation
%SQLAOPSTDEVP = &H31   ' // Standard deviation population
%SQLAOPVAR    = &H32   ' // Variance
%SQLAOPVARP   = &H33   ' // Variance population
%SQLAOPCNT    = &H4b   ' // Count
%SQLAOPSUM    = &H4d   ' // Sum
%SQLAOPAVG    = &H4f   ' // Average
%SQLAOPMIN    = &H51   ' // Min
%SQLAOPMAX    = &H52   ' // Max
%SQLAOPANY    = &H53   ' // Any
%SQLAOPNOOP   = &H56   ' // None


'//   SQLGetInfo driver specific defines.
'//   Microsoft has 1151 thru 1200 reserved for Microsoft SQL Server driver usage.

%SQL_INFO_SS_FIRST        = 1199
%SQL_INFO_SS_NETLIB_NAMEW = %SQL_INFO_SS_FIRST+0  ' //  dbprocinfo
%SQL_INFO_SS_NETLIB_NAMEA = %SQL_INFO_SS_FIRST+1  ' //  dbprocinfo
%SQL_INFO_SS_MAX_USED     = %SQL_INFO_SS_NETLIB_NAMEA
'#ifdef UNICODE
'%SQL_INFO_SS_NETLIB_NAME      = %SQL_INFO_SS_NETLIB_NAMEW
'#else
'%SQL_INFO_SS_NETLIB_NAME      = %SQL_INFO_SS_NETLIB_NAMEA
'#endif
%SQL_INFO_SS_NETLIB_NAME      = %SQL_INFO_SS_NETLIB_NAMEA


'//   Driver specific SQL type defines.
'//   Microsoft has -150 thru -199 reserved for Microsoft SQL Server driver usage.
%SQL_SS_VARIANT   = -150


'//   SQLGetDiagField driver specific defines.
'//   Microsoft has -1150 thru -1199 reserved for Microsoft SQL Server driver usage.

%SQL_DIAG_SS_BASE      =-1150
%SQL_DIAG_SS_MSGSTATE  = %SQL_DIAG_SS_BASE
%SQL_DIAG_SS_SEVERITY  = %SQL_DIAG_SS_BASE-1
%SQL_DIAG_SS_SRVNAME   = %SQL_DIAG_SS_BASE-2
%SQL_DIAG_SS_PROCNAME  = %SQL_DIAG_SS_BASE-3
%SQL_DIAG_SS_LINE      = %SQL_DIAG_SS_BASE-4


'//   SQLGetDiagField/SQL_DIAG_DYNAMIC_FUNCTION_CODE driver specific defines.
'//   Microsoft has -200 thru -299 reserved for Microsoft SQL Server driver usage.

%SQL_DIAG_DFC_SS_BASE                = -200
%SQL_DIAG_DFC_SS_ALTER_DATABASE      = %SQL_DIAG_DFC_SS_BASE - 0
%SQL_DIAG_DFC_SS_CHECKPOINT          = %SQL_DIAG_DFC_SS_BASE - 1
%SQL_DIAG_DFC_SS_CONDITION           = %SQL_DIAG_DFC_SS_BASE - 2
%SQL_DIAG_DFC_SS_CREATE_DATABASE     = %SQL_DIAG_DFC_SS_BASE - 3
%SQL_DIAG_DFC_SS_CREATE_DEFAULT      = %SQL_DIAG_DFC_SS_BASE - 4
%SQL_DIAG_DFC_SS_CREATE_PROCEDURE    = %SQL_DIAG_DFC_SS_BASE - 5
%SQL_DIAG_DFC_SS_CREATE_RULE         = %SQL_DIAG_DFC_SS_BASE - 6
%SQL_DIAG_DFC_SS_CREATE_TRIGGER      = %SQL_DIAG_DFC_SS_BASE - 7
%SQL_DIAG_DFC_SS_CURSOR_DECLARE      = %SQL_DIAG_DFC_SS_BASE - 8
%SQL_DIAG_DFC_SS_CURSOR_OPEN         = %SQL_DIAG_DFC_SS_BASE - 9
%SQL_DIAG_DFC_SS_CURSOR_FETCH        = %SQL_DIAG_DFC_SS_BASE - 10
%SQL_DIAG_DFC_SS_CURSOR_CLOSE        = %SQL_DIAG_DFC_SS_BASE - 11
%SQL_DIAG_DFC_SS_DEALLOCATE_CURSOR   = %SQL_DIAG_DFC_SS_BASE - 12
%SQL_DIAG_DFC_SS_DBCC                = %SQL_DIAG_DFC_SS_BASE - 13
%SQL_DIAG_DFC_SS_DISK                = %SQL_DIAG_DFC_SS_BASE - 14
%SQL_DIAG_DFC_SS_DROP_DATABASE       = %SQL_DIAG_DFC_SS_BASE - 15
%SQL_DIAG_DFC_SS_DROP_DEFAULT        = %SQL_DIAG_DFC_SS_BASE - 16
%SQL_DIAG_DFC_SS_DROP_PROCEDURE      = %SQL_DIAG_DFC_SS_BASE - 17
%SQL_DIAG_DFC_SS_DROP_RULE           = %SQL_DIAG_DFC_SS_BASE - 18
%SQL_DIAG_DFC_SS_DROP_TRIGGER        = %SQL_DIAG_DFC_SS_BASE - 19
%SQL_DIAG_DFC_SS_DUMP_DATABASE       = %SQL_DIAG_DFC_SS_BASE - 20
%SQL_DIAG_DFC_SS_DUMP_TABLE          = %SQL_DIAG_DFC_SS_BASE - 21
%SQL_DIAG_DFC_SS_DUMP_TRANSACTION    = %SQL_DIAG_DFC_SS_BASE - 22
%SQL_DIAG_DFC_SS_GOTO                = %SQL_DIAG_DFC_SS_BASE - 23
%SQL_DIAG_DFC_SS_INSERT_BULK         = %SQL_DIAG_DFC_SS_BASE - 24
%SQL_DIAG_DFC_SS_KILL                = %SQL_DIAG_DFC_SS_BASE - 25
%SQL_DIAG_DFC_SS_LOAD_DATABASE       = %SQL_DIAG_DFC_SS_BASE - 26
%SQL_DIAG_DFC_SS_LOAD_HEADERONLY     = %SQL_DIAG_DFC_SS_BASE - 27
%SQL_DIAG_DFC_SS_LOAD_TABLE          = %SQL_DIAG_DFC_SS_BASE - 28
%SQL_DIAG_DFC_SS_LOAD_TRANSACTION    = %SQL_DIAG_DFC_SS_BASE - 29
%SQL_DIAG_DFC_SS_PRINT               = %SQL_DIAG_DFC_SS_BASE - 30
%SQL_DIAG_DFC_SS_RAISERROR           = %SQL_DIAG_DFC_SS_BASE - 31
%SQL_DIAG_DFC_SS_READTEXT            = %SQL_DIAG_DFC_SS_BASE - 32
%SQL_DIAG_DFC_SS_RECONFIGURE         = %SQL_DIAG_DFC_SS_BASE - 33
%SQL_DIAG_DFC_SS_RETURN              = %SQL_DIAG_DFC_SS_BASE - 34
%SQL_DIAG_DFC_SS_SELECT_INTO         = %SQL_DIAG_DFC_SS_BASE - 35
%SQL_DIAG_DFC_SS_SET                 = %SQL_DIAG_DFC_SS_BASE - 36
%SQL_DIAG_DFC_SS_SET_IDENTITY_INSERT = %SQL_DIAG_DFC_SS_BASE - 37
%SQL_DIAG_DFC_SS_SET_ROW_COUNT       = %SQL_DIAG_DFC_SS_BASE - 38
%SQL_DIAG_DFC_SS_SET_STATISTICS      = %SQL_DIAG_DFC_SS_BASE - 39
%SQL_DIAG_DFC_SS_SET_TEXTSIZE        = %SQL_DIAG_DFC_SS_BASE - 40
%SQL_DIAG_DFC_SS_SETUSER             = %SQL_DIAG_DFC_SS_BASE - 41
%SQL_DIAG_DFC_SS_SHUTDOWN            = %SQL_DIAG_DFC_SS_BASE - 42
%SQL_DIAG_DFC_SS_TRANS_BEGIN         = %SQL_DIAG_DFC_SS_BASE - 43
%SQL_DIAG_DFC_SS_TRANS_COMMIT        = %SQL_DIAG_DFC_SS_BASE - 44
%SQL_DIAG_DFC_SS_TRANS_PREPARE       = %SQL_DIAG_DFC_SS_BASE - 45
%SQL_DIAG_DFC_SS_TRANS_ROLLBACK      = %SQL_DIAG_DFC_SS_BASE - 46
%SQL_DIAG_DFC_SS_TRANS_SAVE          = %SQL_DIAG_DFC_SS_BASE - 47
%SQL_DIAG_DFC_SS_TRUNCATE_TABLE      = %SQL_DIAG_DFC_SS_BASE - 48
%SQL_DIAG_DFC_SS_UPDATE_STATISTICS   = %SQL_DIAG_DFC_SS_BASE - 49
%SQL_DIAG_DFC_SS_UPDATETEXT          = %SQL_DIAG_DFC_SS_BASE - 50
%SQL_DIAG_DFC_SS_USE                 = %SQL_DIAG_DFC_SS_BASE - 51
%SQL_DIAG_DFC_SS_WAITFOR             = %SQL_DIAG_DFC_SS_BASE - 52
%SQL_DIAG_DFC_SS_WRITETEXT           = %SQL_DIAG_DFC_SS_BASE - 53
%SQL_DIAG_DFC_SS_DENY                = %SQL_DIAG_DFC_SS_BASE - 54
%SQL_DIAG_DFC_SS_SET_XCTLVL          = %SQL_DIAG_DFC_SS_BASE - 55

'//   Severity codes for SQL_DIAG_SS_SEVERITY
%EX_ANY          = 0
%EX_INFO         = 10
%EX_MAXISEVERITY = %EX_INFO
%EX_MISSING      = 11
%EX_TYPE         = 12
%EX_DEADLOCK     = 13
%EX_PERMIT       = 14
%EX_SYNTAX       = 15
%EX_USER         = 16
%EX_RESOURCE     = 17
%EX_INTOK        = 18
%MAXUSEVERITY    = %EX_INTOK
%EX_LIMIT        = 19
%EX_CMDFATAL     = 20
%MINFATALERR     = %EX_CMDFATAL
%EX_DBFATAL      = 21
%EX_TABCORRUPT   = 22
%EX_DBCORRUPT    = 23
%EX_HARDWARE     = 24
%EX_CONTROL      = 25

'//   Internal server datatypes - used when binding to SQL_C_BINARY
#IF NOT %DEF(%MAXNUMERICLEN)  ' // Resolve ODS/DBLib conflicts
'// DB-Library datatypes
%DBMAXCHAR       = 8000+1   ' // Max length of DBVARBINARY and DBVARCHAR, etc. +1 for zero byte
%MAXNAME         = %SQL_MAX_SQLSERVERNAME+1  ' // Max server identifier length including zero byte

'#ifdef UNICODE
'typedef wchar_t         DBCHAR;
'#else
'typedef char            DBCHAR;
'#endif
'typedef unsigned char   DBBINARY;
'typedef unsigned char   DBTINYINT;
'typedef short           DBSMALLINT;
'typedef unsigned short  DBUSMALLINT;
'typedef double          DBFLT8;
'typedef unsigned char   DBBIT;
'typedef unsigned char   DBBOOL;
'typedef float           DBFLT4;

'typedef DBFLT4 DBREAL;
'typedef UINT   DBUBOOL;

' // Size = 8004 bytes
TYPE DBVARYCHARA WORD
   len AS WORD                    ' DBSMALLINT
   str AS STRING * %DBMAXCHAR     ' DBCHAR
END TYPE

' // Size = 16005 bytes
TYPE DBVARYCHARW WORD
   len AS WORD                    ' DBSMALLINT
   str AS WSTRINGZ * %DBMAXCHAR   ' DBCHAR
END TYPE

#IF %DEF(%UNICODE)
   MACRO DBVARYCHAR = DBVARYCHARW
#ELSE
   MACRO DBVARYCHAR = DBVARYCHARA
#ENDIF

' // Size = 8004 bytes
TYPE DBVARYBIN WORD
   len                   AS WORD   ' DBSMALLINT
   array(%DBMAXCHAR - 1) AS BYTE   ' BYTE
END TYPE

' // Size = 8 bytes
TYPE DBMONEY DWORD
   mnyhigh AS LONG    ' LONG  // Money value *10,000 (High 32 bits/signed)
   mnylow  AS DWORD   ' ULONG // Money value *10,000 (Low 32 bits/unsigned)
END TYPE

' // Size = 8 bytes
TYPE DBDATETIME DWORD
                     '       // Internal representation of DATETIME data type
   dtdays AS LONG    ' LONG  // No of days since Jan-1-1900 (maybe negative)
   dttime AS DWORD   ' ULONG // No. of 300 hundredths of a second since midnight
END TYPE

' // Size = 4 bytes
TYPE DBDATETIM4 WORD
                     '        // Internal representation of SMALLDATETIME data type
   numdays AS WORD   ' USHORT // No of days since Jan-1-1900
   nummins AS WORD   ' USHORT // No. of minutes since midnight
END TYPE

'typedef LONG DBMONEY4;   // Internal representation of SMALLMONEY data type
'                         // Money value *10,000

'#define DBNUM_PREC_TYPE BYTE
'#define DBNUM_SCALE_TYPE BYTE
'#define DBNUM_VAL_TYPE BYTE

#IF %ODBCVER < &H0300
%MAXNUMERICLEN = 16

' // Size = 19 bytes
TYPE DBNUMERIC BYTE
                                   '  // Internal representation of NUMERIC data type
   precision AS BYTE               ' DBNUM_PREC_TYPE   // Precision
   scale     AS BYTE               ' DBNUM_SCALE_TYPE  // Scale
   sign      AS BYTE               ' BYTE              // Sign (1 if positive, 0 if negative)
'   val(%MAXNUMERICLEN-1) AS BYTE   ' DBNUM_VAL_TYPE    // Value
   val       AS STRING * %MAXNUMERICLEN
END TYPE

'typedef DBNUMERIC DBDECIMAL;// Internal representation of DECIMAL data type
' // Size = 19 bytes
TYPE DBDECIMAL BYTE
                                   '  // Internal representation of NUMERIC data type
   precision AS BYTE               ' DBNUM_PREC_TYPE   // Precision
   scale     AS BYTE               ' DBNUM_SCALE_TYPE  // Scale
   sign      AS BYTE               ' BYTE              // Sign (1 if positive, 0 if negative)
'   val(%MAXNUMERICLEN-1) AS BYTE   ' DBNUM_VAL_TYPE    // Value
   val       AS STRING * %MAXNUMERICLEN
END TYPE

#ELSE   ' //   Use ODBC 3.0 definitions since same as DBLib

%MAXNUMERICLEN = %SQL_MAX_NUMERIC_LEN

'typedef SQL_NUMERIC_STRUCT DBNUMERIC;
'typedef SQL_NUMERIC_STRUCT DBDECIMAL;

' // Size = 19 bytes
TYPE DBNUMERIC BYTE
   precision AS BYTE
   scale     AS BYTE
   sign      AS BYTE
   val       AS STRING * %SQL_MAX_NUMERIC_LEN
END TYPE

' // Size = 19 bytes
TYPE DBDECIMAL BYTE
   precision AS BYTE
   scale     AS BYTE
   sign      AS BYTE
   val       AS STRING * %SQL_MAX_NUMERIC_LEN
END TYPE

#ENDIF

#ENDIF   ' //   MAXNUMERICLEN

'#ifndef INT
'typedef int INT;
'typedef long            DBINT;
'#ifndef _LPCBYTE_DEFINED
'#define _LPCBYTE_DEFINED
'typedef const LPBYTE   LPCBYTE;
'#endif
'typedef DBINT *         LPDBINT;
'#endif

'/*****************************************************************
' This struct is a global used for
' gathering statistical data on the driver.
' Access to this structure is controlled via the
' pStatCrit;
'******************************************************************/

' // Size = 160 bytes
TYPE SQLPERF   ' Must be 8 byte aligned

   ' // Application Profile Statistics
   TimerResolution        AS DWORD
   SQLidu                 AS DWORD
   SQLiduRows             AS DWORD
   SQLSelects             AS DWORD
   SQLSelectRows          AS DWORD
   Transactions           AS DWORD
   SQLPrepares            AS DWORD
   ExecDirects            AS DWORD
   SQLExecutes            AS DWORD
   CursorOpens            AS DWORD
   CursorSize             AS DWORD
   CursorUsed             AS DWORD
   PercentCursorUsed      AS DOUBLE   ' LDOUBLE
   AvgFetchTime           AS DOUBLE   ' LDOUBLE
   AvgCursorSize          AS DOUBLE   ' LDOUBLE
   AvgCursorUsed          AS DOUBLE   ' LDOUBLE
   SQLFetchTime           AS DWORD
   SQLFetchCount          AS DWORD
   CurrentStmtCount       AS DWORD
   MaxOpenStmt            AS DWORD
   SumOpenStmt            AS DWORD

   ' // Connection Statistics
   CurrentConnectionCount AS DWORD
   MaxConnectionsOpened   AS DWORD
   SumConnectionsOpened   AS DWORD
   SumConnectiontime      AS DWORD
   alignment1__           AS DWORD   ' // o keep 8 byte alignment
   AvgTimeOpened          AS DOUBLE   ' LDOUBLE

   ' // Network Statistics
   ServerRndTrips         AS DWORD
   BuffersSent            AS DWORD
   BuffersRec             AS DWORD
   BytesSent              AS DWORD
   BytesRec               AS DWORD

   ' // Time Statistics
   msExecutionTime        AS DWORD
   msNetWorkServerTime    AS DWORD
   alignment2__           AS DWORD   ' // o keep 8 byte alignment

END TYPE

'// The following are options for SQL_COPT_SS_PERF_DATA and SQL_COPT_SS_PERF_QUERY
%SQL_PERF_START = 1        ' // Starts the driver sampling performance data.
%SQL_PERF_STOP  = 2        ' // Stops the counters from sampling performance data.

'// The following are defines for SQL_COPT_SS_PERF_DATA_LOG
'#define SQL_SS_DL_DEFAULT   TEXT("STATS.LOG")
$$SQL_SS_DL_DEFAULT   = "STATS.LOG"$$

'// The following are defines for SQL_COPT_SS_PERF_QUERY_LOG
'#define SQL_SS_QL_DEFAULT   TEXT("QUERY.LOG")
$$SQL_SS_QL_DEFAULT   = "QUERY.LOG"$$

'// The following are defines for SQL_COPT_SS_PERF_QUERY_INTERVAL
%SQL_SS_QI_DEFAULT   = 30000   ' // 30,000 milliseconds

'//   ODBC BCP prototypes and defines

'//   Return codes
%SUCCEED         = 1
%FAIL            = 0
%SUCCEED_ABORT   = 2
%SUCCEED_ASYNC   = 3

'//   Transfer directions
%DB_IN           = 1    ' // Transfer from client to server
%DB_OUT          = 2    ' // Transfer from server to client

'//   bcp_control option
%BCPMAXERRS      = 1    ' // Sets max errors allowed
%BCPFIRST        = 2    ' // Sets first row to be copied out
%BCPLAST         = 3    ' // Sets number of rows to be copied out
%BCPBATCH        = 4    ' // Sets input batch size
%BCPKEEPNULLS    = 5    ' // Sets to insert NULLs for empty input values
%BCPABORT        = 6    ' // Sets to have bcpexec return SUCCEED_ABORT
%BCPODBC         = 7    ' // Sets ODBC canonical character output
%BCPKEEPIDENTITY = 8    ' // Sets IDENTITY_INSERT on
%BCP6xFILEFMT    = 9    ' // DEPRECATED: Sets 6x file format on
%BCPHINTSA       = 10   ' // Sets server BCP hints (ANSI string)
%BCPHINTSW       = 11   ' // Sets server BCP hints (UNICODE string)
%BCPFILECP       = 12   ' // Sets clients code page for the file
%BCPUNICODEFILE  = 13   ' // Sets that the file contains unicode header
%BCPTEXTFILE     = 14   ' // Sets BCP mode to expect a text file and to detect Unicode or ANSI automatically
%BCPFILEFMT      = 15   ' // Sets file format version

#IF %DEF(%UNICODE)
   %BCPHINTS = %BCPHINTSW
#ELSE
   %BCPHINTS = %BCPHINTSA
#ENDIF

'//   BCPFILECP values
'//   Any valid code page that is installed on the client can be passed plus:
%BCPFILECP_ACP   = 0    ' // Data in file is in Windows code page
%BCPFILECP_OEMCP = 1    ' // Data in file is in OEM code page (default)
%BCPFILECP_RAW   = -1   ' // Data in file is in Server code page (no conversion)

'//   bcp_collen definition
%SQL_VARLEN_DATA = -10  ' //   Use default length for column

'// BCP functions

DECLARE FUNCTION bcp_batch IMPORT "Odbcbcp.dll" ALIAS "bcp_batch" ( _
   BYVAL hdbc AS DWORD _                                ' __in HDBC hdbc
 ) AS LONG                                              ' DBINT

DECLARE FUNCTION bcp_bind IMPORT "Odbcbcp.dll" ALIAS "bcp_bind" ( _
   BYVAL hdbc AS DWORD _                                ' __in HDBC hdbc
 , BYVAL pData AS BYTE PTR _                            ' __in LPCBYTE pData
 , BYVAL cbIndicator AS LONG _                          ' __in INT cbIndicator
 , BYVAL cbData AS LONG _                               ' __in DBINT cbData
 , BYVAL pTerm AS BYTE PTR _                            ' __in LPCBYTE pTerm
 , BYVAL cbTerm AS LONG _                               ' __in INT cbTerm
 , BYVAL eDataType AS LONG _                            ' __in INT eDataType
 , BYVAL idxServerCol AS LONG _                         ' __in INT idxServerCol
 ) AS LONG                                              ' RETCODE

DECLARE FUNCTION bcp_colfmt IMPORT "Odbcbcp.dll" ALIAS "bcp_colfmt" ( _
   BYVAL hdbc AS DWORD _                                ' __in HDBC hdbc
 , BYVAL idxUserDataCol AS LONG _                       ' __in INT idxUserDataCol
 , BYVAL eUserDataType AS BYTE _                        ' __in BYTE eUserDataType
 , BYVAL cbIndicator AS LONG _                          ' __in INT cbIndicator
 , BYVAL cbUserData AS LONG _                           ' __in DBINT cbUserData
 , BYVAL pUserDataTerm AS BYTE PTR _                    ' __in LPCBYTE pUserDataTerm
 , BYVAL cbUserDataTerm AS LONG _                       ' __in INT cbUserDataTerm
 , BYVAL idxServerCol AS LONG _                         ' __in INT idxServerCol
 ) AS LONG                                              ' RETCODE

DECLARE FUNCTION bcp_collen IMPORT "Odbcbcp.dll" ALIAS "bcp_collen" ( _
   BYVAL hdbc AS DWORD _                                ' __in HDBC hdbc
 , BYVAL cbData AS LONG _                               ' __in DBINT cbData
 , BYVAL idxServerCol AS LONG _                         ' __in INT idxServerCol
 ) AS LONG                                              ' RETCODE

DECLARE FUNCTION bcp_colptr IMPORT "Odbcbcp.dll" ALIAS "bcp_colptr" ( _
   BYVAL hdbc AS DWORD _                                ' __in HDBC hdbc
 , BYVAL pData AS BYTE PTR _                            ' __in LPCBYTE pData
 , BYVAL idxServerCol AS LONG _                         ' __in INT idxServerCol
 ) AS LONG                                              ' RETCODE

DECLARE FUNCTION bcp_columns IMPORT "Odbcbcp.dll" ALIAS "bcp_columns" ( _
   BYVAL hdbc AS DWORD _                                ' __in HDBC hdbc
 , BYVAL nColumns AS LONG _                             ' __in INT nColumns
 ) AS LONG                                              ' RETCODE

DECLARE FUNCTION bcp_control IMPORT "Odbcbcp.dll" ALIAS "bcp_control" ( _
   BYVAL hdbc AS DWORD _                                ' __in HDBC hdbc
 , BYVAL eOption AS LONG _                              ' __in INT eOption
 , BYVAL iValue AS DWORD _                              ' __in void* iValue
 ) AS LONG                                              ' RETCODE

DECLARE FUNCTION bcp_done IMPORT "Odbcbcp.dll" ALIAS "bcp_done" ( _
   BYVAL hdbc AS DWORD _                                ' __in HDBC hdbc
 ) AS LONG                                              ' DBINT

DECLARE FUNCTION bcp_exec IMPORT "Odbcbcp.dll" ALIAS "bcp_exec" ( _
   BYVAL hdbc AS DWORD _                                ' __in  HDBC hdbc
 , BYREF pnRowsProcessed AS LONG _                      ' __out LPDBINT pnRowsProcessed
 ) AS LONG                                              ' RETCODE

DECLARE FUNCTION bcp_getcolfmt IMPORT "Odbcbcp.dll" ALIAS "bcp_getcolfmt" ( _
   BYVAL hdbc AS DWORD _                                ' __in  HDBC hdbc
 , BYVAL field AS LONG _                                ' __in  INT field
 , BYVAL property AS LONG _                             ' __in  INT property
 , BYREF pValue AS ANY _                                ' __in_out void* pValue
 , BYVAL cbvalue AS LONG _                              ' __in  INT cbvalue
 , BYREF pcbLen AS LONG _                               ' __out INT* pcbLen
 ) AS LONG                                              ' RETCODE

DECLARE FUNCTION bcp_initA IMPORT "Odbcbcp.dll" ALIAS "bcp_initA" ( _
   BYVAL hdbc AS DWORD _                                ' __in HDBC hdbc
 , BYREF szTable AS ASCIIZ _                            ' __in LPCSTR szTable
 , BYREF szDataFile AS ASCIIZ _                         ' __in LPCSTR szDataFile
 , BYREF szErrorFile AS ASCIIZ _                        ' __in LPCSTR szErrorFile
 , BYVAL eDirection AS LONG _                           ' __in INT eDirection
 ) AS LONG                                              ' RETCODE

DECLARE FUNCTION bcp_initW IMPORT "Odbcbcp.dll" ALIAS "bcp_initW" ( _
   BYREF hdbc AS DWORD _                                ' __in HDBC hdbc
 , BYREF szTable AS WSTRINGZ _                          ' __in LPCWSTR szTable
 , BYREF szDataFile AS WSTRINGZ _                       ' __in LPCWSTR szDataFile
 , BYREF szErrorFile AS WSTRINGZ _                      ' __in LPCWSTR szErrorFile
 , BYVAL eDirection AS LONG _                           ' __in INT eDirection
 ) AS LONG                                              ' RETCODE

#IF %DEF(%UNICODE)
   MACRO bcp_init = bcp_initW
#ELSE
   MACRO bcp_init = bcp_initA
#ENDIF

DECLARE FUNCTION bcp_moretext IMPORT "Odbcbcp.dll" ALIAS "bcp_moretext" ( _
   BYVAL hdbc AS DWORD _                                ' __in HDBC hdbc
 , BYVAL cbData AS LONG _                               ' __in DBINT cbData
 , BYVAL pData AS BYTE PTR _                            ' __in LPCBYTE pData
 ) AS LONG                                              ' RETCODE

DECLARE FUNCTION bcp_readfmtA IMPORT "Odbcbcp.dll" ALIAS "bcp_readfmtA" ( _
   BYVAL hdbc AS DWORD _                                ' __in HDBC hdbc
 , BYREF szFormatFile AS ASCIIZ _                       ' __in LPCSTR szFormatFile
 ) AS LONG                                              ' RETCODE

DECLARE FUNCTION bcp_readfmtW IMPORT "Odbcbcp.dll" ALIAS "bcp_readfmtW" ( _
   BYVAL hdbc AS DWORD _                                ' __in HDBC hdbc
 , BYREF szFormatFile AS WSTRINGZ  _                    ' __in LPCWSTR szFormatFile
 ) AS LONG                                              ' RETCODE

#IF %DEF(%UNICODE)
   MACRO bcp_readfmt = bcp_readfmtW
#ELSE
   MACRO bcp_readfmt = bcp_readfmtA
#ENDIF

DECLARE FUNCTION bcp_sendrow IMPORT "Odbcbcp.dll" ALIAS "bcp_sendrow" ( _
   BYVAL hdbc AS DWORD _                                ' __in HDBC hdbc
 ) AS LONG                                              ' RETCODE

DECLARE FUNCTION bcp_setcolfmt IMPORT "Odbcbcp.dll" ALIAS "bcp_setcolfmt" ( _
   BYVAL hdbc AS DWORD _                                ' __in HDBC hdbc
 , BYVAL field AS LONG _                                ' __in INT field
 , BYVAL property AS LONG _                             ' __in INT property
 , BYREF pValue AS ANY _                                ' __in void * pValue
 , BYVAL cbValue AS LONG _                              ' __in INT cbValue
 ) AS LONG                                              ' RETCODE

DECLARE FUNCTION bcp_writefmtA IMPORT "Odbcbcp.dll" ALIAS "bcp_writefmtA" ( _
   BYVAL hdbc AS DWORD _                                ' __in HDBC hdbc
 , BYREF szFormatFile AS ASCIIZ _                       ' __in LPCSTR szFormatFile
 ) AS LONG                                              ' RETCODE

DECLARE FUNCTION bcp_writefmtW IMPORT "Odbcbcp.dll" ALIAS "bcp_writefmtW" ( _
   BYVAL hdbc AS DWORD _                                ' __in HDBC hdbc
 , BYREF szFormatFile AS WSTRINGZ _                     ' __in LPCWSTR szFormatFile
 ) AS LONG                                              ' RETCODE

#IF %DEF(%UNICODE)
   MACRO bcp_writefmt = bcp_writefmtW
#ELSE
   MACRO bcp_writefmt = bcp_writefmtA
#ENDIF

DECLARE FUNCTION dbprtypeA IMPORT "Odbcbcp.dll" ALIAS "dbprtypeA" ( _
   BYVAL token AS LONG _                                ' __in INT token
 ) AS DWORD                                             ' CHAR *

DECLARE FUNCTION dbprtypeW IMPORT "Odbcbcp.dll" ALIAS "dbprtypeW" ( _
   BYVAL token AS LONG _                                ' __in INT token
 ) AS DWORD                                             ' WCHAR *

#IF %DEF(%UNICODE)
   MACRO dbprtype = dbprtypeW
#ELSE
   MACRO dbprtype = dbprtypeA
#ENDIF

'#ifdef UNICODE
'#define bcp_init      bcp_initW
'#define bcp_readfmt   bcp_readfmtW
'#define bcp_writefmt  bcp_writefmtW
'#define dbprtype      dbprtypeW
'#define BCPHINTS      BCPHINTSW

'#else
'#define bcp_init      bcp_initA
'#define bcp_readfmt   bcp_readfmtA
'#define bcp_writefmt  bcp_writefmtA
'#define dbprtype      dbprtypeA
'#define BCPHINTS      BCPHINTSA
'#endif

'//   SQL Server catalog extensions for distributed queries
DECLARE FUNCTION SQLLinkedServers IMPORT "Odbcbcp.dll" ALIAS "SQLLinkedServers" ( _
   BYVAL hstmt AS DWORD _                               ' __in SQLHSTMT hstmt
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLLinkedCatalogsA IMPORT "Odbcbcp.dll" ALIAS "SQLLinkedCatalogsA" ( _
   BYVAL hstmt AS DWORD _                               ' __in SQLHSTMT  hstmt
 , BYREF ServerName AS ASCIIZ _                         ' __in LPCSTR   *ServerName
 , BYVAL NameLength1 AS INTEGER _                       ' __in SWORD     NameLength1
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLLinkedCatalogsW IMPORT "Odbcbcp.dll" ALIAS "SQLLinkedCatalogsW" ( _
   BYVAL hstmt AS DWORD _                               ' __in SQLHSTMT  hstmt
 , BYREF ServerName AS WSTRINGZ _                       ' __in LPCWSTR  *ServerName
 , BYVAL NameLength1 AS INTEGER _                       ' __in SWORD     NameLength1
 ) AS INTEGER                                           ' SQLRETURN

#IF %DEF(%UNICODE)
   MACRO SQLLinkedCatalogs = SQLLinkedCatalogsW
#ELSE
   MACRO SQLLinkedCatalogs = SQLLinkedCatalogsA
#ENDIF

'//   SQL Server extensions for server enumeration
DECLARE FUNCTION SQLInitEnumServers IMPORT "Odbcbcp.dll" ALIAS "SQLInitEnumServers" ( _
   BYREF pwchServerName AS WSTRINGZ _                   ' __out WCHAR *pwchServerName
 , BYREF pwchInstanceName AS WSTRINGZ _                 ' __out WCHAR *pwchInstanceName
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION SQLGetNextEnumeration IMPORT "Odbcbcp.dll" ALIAS "SQLGetNextEnumeration" ( _
   BYVAL hEnumHandle AS DWORD _                         ' __in  HANDLE  hEnumHandle
 , BYREF prgEnumData AS BYTE _                          ' __out BYTE   *prgEnumData
 , BYREF piEnumLength AS LONG _                         ' __out INT    *piEnumLength
 ) AS LONG                                              ' RETCODE

DECLARE FUNCTION SQLCloseEnumServers IMPORT "Odbcbcp.dll" ALIAS "SQLCloseEnumServers" ( _
   BYVAL hEnumHandle AS DWORD _                         ' __in HANDLE hEnumHandle
 ) AS LONG                                              ' RETCODE

'#ifdef UNICODE
'#define SQLLinkedCatalogs   SQLLinkedCatalogsW
'#else
'#define SQLLinkedCatalogs   SQLLinkedCatalogsA
'#endif

'//  BCP column format properties
%BCP_FMT_TYPE          = &H01
%BCP_FMT_INDICATOR_LEN = &H02
%BCP_FMT_DATA_LEN      = &H03
%BCP_FMT_TERMINATOR    = &H04
%BCP_FMT_SERVER_COL    = &H05
%BCP_FMT_COLLATION     = &H06
%BCP_FMT_COLLATION_ID  = &H07

'//   The following options have been deprecated

%SQL_FAST_CONNECT     = %SQL_COPT_SS_BASE + 0
'//   Defines for use with SQL_FAST_CONNECT - only useable before connecting
%SQL_FC_OFF           = 0&                     ' //   Fast connect is off
%SQL_FC_ON            = 1&                     ' //   Fast connect is on
%SQL_FC_DEFAULT       = %SQL_FC_OFF
%SQL_COPT_SS_ANSI_OEM = %SQL_COPT_SS_BASE + 6
%SQL_AO_OFF           = 0&
%SQL_AO_ON            = 1&
%SQL_AO_DEFAULT       = %SQL_AO_OFF

'//   Define old names
%SQL_REMOTE_PWD                = %SQL_COPT_SS_REMOTE_PWD
%SQL_USE_PROCEDURE_FOR_PREPARE = %SQL_COPT_SS_USE_PROC_FOR_PREP
%SQL_INTEGRATED_SECURITY       = %SQL_COPT_SS_INTEGRATED_SECURITY
%SQL_PRESERVE_CURSORS          = %SQL_COPT_SS_PRESERVE_CURSORS
%SQL_TEXTPTR_LOGGING           = %SQL_SOPT_SS_TEXTPTR_LOGGING
%SQL_CA_SS_BASE_COLUMN_NAME    = %SQL_DESC_BASE_COLUMN_NAME
%SQLDECIMALN                   = &H6a
%SQLNUMERICN                   = &H6c
