' ########################################################################################
' Microsoft Windows
' File: sqlucode.inc
' Contents: This is the the unicode include for ODBC Core functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SQLUCODE_INC = 1

#INCLUDE ONCE "sqlext.inc"

%SQL_WCHAR          = -8
%SQL_WVARCHAR       = -9
%SQL_WLONGVARCHAR   = -10
%SQL_C_WCHAR        = %SQL_WCHAR

'#ifdef UNICODE
'#define SQL_C_TCHAR      SQL_C_WCHAR
'#else
'#define SQL_C_TCHAR      SQL_C_CHAR
'#endif

%SQL_SQLSTATE_SIZEW = 10  ' /* size of SQLSTATE for unicode */

'// UNICODE versions

DECLARE FUNCTION SQLColAttributeW IMPORT "ODBC32.DLL" ALIAS "SQLColAttributeW" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT      hstmt
 , BYVAL icol AS WORD _                                 ' SQLUSMALLINT  icol
 , BYVAL iField AS WORD _                               ' SQLUSMALLINT  iField
 , BYREF pCharAttr AS ANY _                             ' SQLPOINTER    pCharAttr
 , BYVAL cbCharAttrMax AS INTEGER _                     ' SQLSMALLINT   cbCharAttrMax
 , BYREF pcbCharAttr AS INTEGER _                       ' SQLSMALLINT  *pcbCharAttr
 , BYREF pNumAttr AS ANY _                              ' SQLPOINTER    pNumAttr
 ) AS INTEGER                                           ' SQLRETURN


DECLARE FUNCTION SQLColAttributesW IMPORT "ODBC32.DLL" ALIAS "SQLColAttributesW" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT      hstmt
 , BYVAL icol AS WORD _                                 ' SQLUSMALLINT  icol
 , BYVAL fDescType AS WORD _                            ' SQLUSMALLINT  fDescType
 , BYREF rgbDesc AS ANY _                               ' SQLPOINTER    rgbDesc
 , BYVAL cbDescMax AS INTEGER _                         ' SQLSMALLINT   cbDescMax
 , BYREF pcbDesc AS INTEGER _                           ' SQLSMALLINT  *pcbDesc
 , BYREF pfDesc AS INTEGER _                            ' SQLLEN       *pfDesc
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLConnectW IMPORT "ODBC32.DLL" ALIAS "SQLConnectW" ( _
   BYVAL hdbc AS DWORD _                                ' SQLHDBC      hdbc
 , BYREF szDSN AS WSTRINGZ _                            ' SQLWCHAR    *szDSN
 , BYVAL cbDSN AS INTEGER _                             ' SQLSMALLINT  cbDSN
 , BYREF szUID AS WSTRINGZ _                            ' SQLWCHAR    *szUID
 , BYVAL cbUID AS INTEGER _                             ' SQLSMALLINT  cbUID
 , BYREF szAuthStr AS WSTRINGZ _                        ' SQLWCHAR    *szAuthStr
 , BYVAL cbAuthStr AS INTEGER _                         ' SQLSMALLINT  cbAuthStr
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLDescribeColW IMPORT "ODBC32.DLL" ALIAS "SQLDescribeColW" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT      hstmt
 , BYVAL icol AS WORD _                                 ' SQLUSMALLINT  icol
 , BYREF szColName AS WSTRINGZ _                        ' SQLWCHAR     *szColName
 , BYVAL cbColNameMax AS INTEGER _                      ' SQLSMALLINT   cbColNameMax
 , BYREF pcbColName AS INTEGER _                        ' SQLSMALLINT  *pcbColName
 , BYREF pfSqlType AS INTEGER _                         ' SQLSMALLINT  *pfSqlType
 , BYREF pcbColDef AS DWORD _                           ' SQLULEN      *pcbColDef
 , BYREF pibScale AS INTEGER _                          ' SQLSMALLINT  *pibScale
 , BYREF pfNullable AS INTEGER _                        ' SQLSMALLINT  *pfNullable
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLErrorW IMPORT "ODBC32.DLL" ALIAS "SQLErrorW" ( _
   BYVAL henv AS DWORD _                                ' SQLHENV      henv
 , BYVAL hdbc AS DWORD _                                ' SQLHDBC      hdbc
 , BYVAL hstmt AS DWORD _                               ' SQLHSTMT     hstmt
 , BYREF szSqlState AS WSTRINGZ _                       ' SQLWCHAR    *szSqlState
 , BYREF pfNativeError AS LONG _                        ' SQLINTEGER  *pfNativeError
 , BYREF szErrorMsg AS WSTRINGZ _                       ' SQLWCHAR    *szErrorMsg
 , BYVAL cbErrorMsgMax AS INTEGER _                     ' SQLSMALLINT  cbErrorMsgMax
 , BYREF pcbErrorMsg AS INTEGER _                       ' SQLSMALLINT *pcbErrorMsg
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLExecDirectW IMPORT "ODBC32.DLL" ALIAS "SQLExecDirectW" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT    hstmt
 , BYREF szSqlStr AS WSTRINGZ _                         ' SQLWCHAR   *szSqlStr
 , BYVAL cbSqlStr AS LONG _                             ' SQLINTEGER  cbSqlStr
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLGetConnectAttrW IMPORT "ODBC32.DLL" ALIAS "SQLGetConnectAttrW" ( _
   BYVAL hdbc AS DWORD _                                ' SQLHDBC     hdbc
 , BYVAL fAttribute AS LONG _                           ' SQLINTEGER  fAttribute
 , BYREF rgbValue AS ANY _                              ' SQLPOINTER  rgbValue
 , BYVAL cbValueMax AS LONG _                           ' SQLINTEGER  cbValueMax
 , BYREF pcbValue AS LONG _                             ' SQLINTEGER *pcbValue
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLGetCursorNameW IMPORT "ODBC32.DLL" ALIAS "SQLGetCursorNameW" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT     hstmt
 , BYREF szCursor AS WSTRINGZ _                         ' SQLWCHAR    *szCursor
 , BYVAL cbCursorMax AS INTEGER _                       ' SQLSMALLINT  cbCursorMax
 , BYREF pcbCursor AS INTEGER _                         ' SQLSMALLINT *pcbCursor
 ) AS INTEGER                                           ' SQLRETURN

#IF %ODBCVER >= &H0300
DECLARE FUNCTION SQLSetDescFieldW IMPORT "ODBC32.DLL" ALIAS "SQLSetDescFieldW" ( _
   BYVAL DescriptorHandle AS DWORD _                    ' SQLHDESC    DescriptorHandle
 , BYVAL RecNumber AS INTEGER _                         ' SQLSMALLINT RecNumber
 , BYVAL FieldIdentifier AS INTEGER _                   ' SQLSMALLINT FieldIdentifier
 , BYREF Value AS ANY _                                 ' SQLPOINTER  Value
 , BYVAL BufferLength AS LONG _                         ' SQLINTEGER  BufferLength
 ) AS INTEGER                                           ' SQLRETURN


DECLARE FUNCTION SQLGetDescFieldW IMPORT "ODBC32.DLL" ALIAS "SQLGetDescFieldW" ( _
   BYVAL hdesc AS DWORD _                               ' SQLHDESC     hdesc
 , BYVAL iRecord AS INTEGER _                           ' SQLSMALLINT  iRecord
 , BYVAL iField AS INTEGER _                            ' SQLSMALLINT  iField
 , BYREF rgbValue AS ANY _                              ' SQLPOINTER   rgbValue
 , BYVAL cbValueMax AS LONG _                           ' SQLINTEGER   cbValueMax
 , BYREF pcbValue AS LONG _                             ' SQLINTEGER  *pcbValue
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLGetDescRecW IMPORT "ODBC32.DLL" ALIAS "SQLGetDescRecW" ( _
   BYVAL hdesc AS DWORD _                               ' SQLHDESC     hdesc
 , BYVAL iRecord AS INTEGER _                           ' SQLSMALLINT  iRecord
 , BYREF szName AS WSTRINGZ _                           ' SQLWCHAR    *szName
 , BYVAL cbNameMax AS INTEGER _                         ' SQLSMALLINT  cbNameMax
 , BYREF pcbName AS INTEGER _                           ' SQLSMALLINT *pcbName
 , BYREF pfType AS INTEGER _                            ' SQLSMALLINT *pfType
 , BYREF pfSubType AS INTEGER _                         ' SQLSMALLINT *pfSubType
 , BYREF pLength AS LONG _                              ' SQLLEN      *pLength
 , BYREF pPrecision AS INTEGER _                        ' SQLSMALLINT *pPrecision
 , BYREF pScale AS INTEGER _                            ' SQLSMALLINT *pScale
 , BYREF pNullable AS INTEGER _                         ' SQLSMALLINT *pNullable
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLGetDiagFieldW IMPORT "ODBC32.DLL" ALIAS "SQLGetDiagFieldW" ( _
   BYVAL fHandleType AS INTEGER _                       ' SQLSMALLINT  fHandleType
 , BYVAL Handle AS DWORD _                              ' SQLHANDLE    Handle
 , BYVAL iRecord AS INTEGER _                           ' SQLSMALLINT  iRecord
 , BYVAL fDiagField AS INTEGER _                        ' SQLSMALLINT  fDiagField
 , BYREF rgbDiagInfo AS ANY _                           ' SQLPOINTER   rgbDiagInfo
 , BYVAL cbDiagInfoMax AS INTEGER _                     ' SQLSMALLINT  cbDiagInfoMax
 , BYREF pcbDiagInfo AS INTEGER _                       ' SQLSMALLINT *pcbDiagInfo
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLGetDiagRecW IMPORT "ODBC32.DLL" ALIAS "SQLGetDiagRecW" ( _
   BYVAL fHandleType AS INTEGER _                       ' SQLSMALLINT  fHandleType
 , BYVAL handle As DWORD _                              ' SQLHANDLE    handle
 , BYVAL iRecord AS INTEGER _                           ' SQLSMALLINT  iRecord
 , BYREF szSqlState AS WSTRINGZ _                       ' SQLWCHAR    *szSqlState
 , BYREF pfNativeError AS LONG _                        ' SQLINTEGER  *pfNativeError
 , BYREF szErrorMsg AS WSTRINGZ _                       ' SQLWCHAR    *szErrorMsg
 , BYVAL cbErrorMsgMax AS INTEGER _                     ' SQLSMALLINT  cbErrorMsgMax
 , BYREF pcbErrorMsg AS INTEGER _                       ' SQLSMALLINT *pcbErrorMsg
 ) AS INTEGER                                           ' SQLRETURN

#ENDIF   ' #IF %ODBCVER >= &H0300


DECLARE FUNCTION SQLPrepareW IMPORT "ODBC32.DLL" ALIAS "SQLPrepareW" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT    hstmt
 , BYREF szSqlStr AS WSTRINGZ _                         ' SQLWCHAR   *szSqlStr
 , BYVAL cbSqlStr AS LONG _                             ' SQLINTEGER  cbSqlStr
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLSetConnectAttrW IMPORT "ODBC32.DLL" ALIAS "SQLSetConnectAttrW" ( _
   BYVAL ConnectionHandle AS DWORD _                    ' SQLHDBC    ConnectionHandle
 , BYVAL Attribute AS LONG _                            ' SQLINTEGER Attribute
 , BYREF Value AS ANY _                                 ' SQLPOINTER Value
 , BYVAL StringLength AS LONG _                         ' SQLINTEGER StringLength
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLSetCursorNameW IMPORT "ODBC32.DLL" ALIAS "SQLSetCursorNameW" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT     hstmt
 , BYREF szCursor AS WSTRINGZ _                         ' SQLWCHAR    *szCursor
 , BYVAL cbCursor AS INTEGER _                          ' SQLSMALLINT  cbCursor
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLColumnsW IMPORT "ODBC32.DLL" ALIAS "SQLColumnsW" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT     hstmt
 , BYREF szCatalogName AS WSTRINGZ _                    ' SQLWCHAR    *szCatalogName
 , BYVAL cbCatalogName AS INTEGER _                     ' SQLSMALLINT  cbCatalogName
 , BYREF szSchemaName AS WSTRINGZ _                     ' SQLWCHAR    *szSchemaName
 , BYVAL cbSchemaName AS INTEGER _                      ' SQLSMALLINT  cbSchemaName
 , BYREF szTableName AS WSTRINGZ _                      ' SQLWCHAR    *szTableName
 , BYVAL cbTableName AS INTEGER _                       ' SQLSMALLINT  cbTableName
 , BYREF szColumnName AS WSTRINGZ _                     ' SQLWCHAR    *szColumnName
 , BYVAL cbColumnName AS INTEGER _                      ' SQLSMALLINT  cbColumnName
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLGetConnectOptionW IMPORT "ODBC32.DLL" ALIAS "SQLGetConnectOptionW" ( _
   BYVAL hdbc AS DWORD _                                ' SQLHDBC      hdbc
 , BYVAL fOption AS WORD _                              ' SQLUSMALLINT fOption
 , BYREF pvParam AS ANY _                               ' SQLPOINTER   pvParam
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLGetInfoW IMPORT "ODBC32.DLL" ALIAS "SQLGetInfoW" ( _
   BYVAL hdbc AS DWORD _                                ' SQLHDBC      hdbc
 , BYVAL fInfoType AS WORD _                            ' SQLUSMALLINT fInfoType
 , BYREF rgbInfoValue AS ANY _                          ' SQLPOINTER   rgbInfoValue
 , BYVAL cbInfoValueMax AS INTEGER _                    ' SQLSMALLINT  cbInfoValueMax
 , BYREF pcbInfoValue AS INTEGER _                      ' SQLSMALLINT *pcbInfoValue
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLGetTypeInfoW IMPORT "ODBC32.DLL" ALIAS "SQLGetTypeInfoW" ( _
   BYVAL StatementHandle AS DWORD _                     ' SQLHSTMT    StatementHandle
 , BYVAL DataType AS INTEGER _                          ' SQLSMALLINT DataType
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLSetConnectOptionW IMPORT "ODBC32.DLL" ALIAS "SQLSetConnectOptionW" ( _
   BYVAL hdbc AS DWORD _                                ' SQLHDBC      hdbc
 , BYVAL fOption AS WORD _                              ' SQLUSMALLINT fOption
 , BYVAL vParam AS DWORD _                              ' SQLULEN      vParam
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLSpecialColumnsW IMPORT "ODBC32.DLL" ALIAS "SQLSpecialColumnsW" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT      hstmt
 , BYVAL fColType AS WORD _                             ' SQLUSMALLINT  fColType
 , BYREF szCatalogName AS WSTRINGZ _                    ' SQLWCHAR     *szCatalogName
 , BYVAL cbCatalogName AS INTEGER _                     ' SQLSMALLINT   cbCatalogName
 , BYREF szSchemaName AS WSTRINGZ _                     ' SQLWCHAR     *szSchemaName
 , BYVAL cbSchemaName AS INTEGER _                      ' SQLSMALLINT   cbSchemaName
 , BYREF szTableName AS WSTRINGZ _                      ' SQLWCHAR     *szTableName
 , BYVAL cbTableName AS INTEGER _                       ' SQLSMALLINT   cbTableName
 , BYVAL fScope AS WORD _                               ' SQLUSMALLINT  fScope
 , BYVAL fNullable AS WORD _                            ' SQLUSMALLINT  fNullable
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLStatisticsW IMPORT "ODBC32.DLL" ALIAS "SQLStatisticsW" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT      hstmt
 , BYREF szCatalogName AS WSTRINGZ _                    ' SQLWCHAR     *szCatalogName
 , BYVAL cbCatalogName AS INTEGER _                     ' SQLSMALLINT   cbCatalogName
 , BYREF szSchemaName AS WSTRINGZ _                     ' SQLWCHAR     *szSchemaName
 , BYVAL cbSchemaName AS INTEGER _                      ' SQLSMALLINT   cbSchemaName
 , BYREF szTableName AS WSTRINGZ _                      ' SQLWCHAR     *szTableName
 , BYVAL cbTableName AS INTEGER _                       ' SQLSMALLINT   cbTableName
 , BYVAL fUnique AS WORD _                              ' SQLUSMALLINT  fUnique
 , BYVAL fAccuracy AS WORD _                            ' SQLUSMALLINT  fAccuracy
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLTablesW IMPORT "ODBC32.DLL" ALIAS "SQLTablesW" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT     hstmt
 , BYREF szCatalogName AS WSTRINGZ _                    ' SQLWCHAR     *szCatalogName
 , BYVAL cbCatalogName AS INTEGER _                     ' SQLSMALLINT  cbCatalogName
 , BYREF szSchemaName AS WSTRINGZ _                     ' SQLWCHAR     *szSchemaName
 , BYVAL cbSchemaName AS INTEGER _                      ' SQLSMALLINT  cbSchemaName
 , BYREF szTableName AS WSTRINGZ _                      ' SQLWCHAR     *szTableName
 , BYVAL cbTableName AS INTEGER _                       ' SQLSMALLINT  cbTableName
 , BYREF szTableType AS WSTRINGZ _                      ' SQLWCHAR     *szTableType
 , BYVAL cbTableType As INTEGER _                       ' SQLSMALLINT  cbTableType
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLDataSourcesW IMPORT "ODBC32.DLL" ALIAS "SQLDataSourcesW" ( _
   BYVAL henv AS DWORD _                                ' SQLHENV       henv
 , BYVAL fDirection AS WORD _                           ' SQLUSMALLINT  fDirection
 , BYREF szDSN AS WSTRINGZ _                            ' SQLWCHAR     *szDSN
 , BYVAL cbDSNMax AS INTEGER _                          ' SQLSMALLINT   cbDSNMax
 , BYREF pcbDSN AS INTEGER _                            ' SQLSMALLINT  *pcbDSN
 , BYREF szDescription AS WSTRINGZ _                    ' SQLWCHAR     *szDescription
 , BYVAL cbDescriptionMax AS INTEGER _                  ' SQLSMALLINT   cbDescriptionMax
 , BYREF pcbDescription AS INTEGER _                    ' SQLSMALLINT  *pcbDescription
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLDriverConnectW IMPORT "ODBC32.DLL" ALIAS "SQLDriverConnectW" ( _
   BYVAL hdbc AS DWORD _                                ' SQLHDBC       hdbc
 , BYVAL hwnd AS DWORD _                                ' SQLHWND       hwnd
 , BYREF szConnStrIn As WSTRINGZ _                      ' SQLWCHAR     *szConnStrIn
 , BYVAL cbConnStrIn AS INTEGER _                       ' SQLSMALLINT   cbConnStrIn
 , BYREF szConnStrOut AS WSTRINGZ _                     ' SQLWCHAR     *szConnStrOut
 , BYVAL cbConnStrOutMax AS INTEGER _                   ' SQLSMALLINT   cbConnStrOutMax
 , BYREF pcbConnStrOut AS INTEGER _                     ' SQLSMALLINT  *pcbConnStrOut
 , BYVAL fDriverCompletion AS WORD _                    ' SQLUSMALLINT  fDriverCompletion
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLBrowseConnectW IMPORT "ODBC32.DLL" ALIAS "SQLBrowseConnectW" ( _
   BYVAL hdbc AS DWORD _                                ' SQLHDBC       hdbc
 , BYREF szConnStrIn AS WSTRINGZ _                      ' SQLWCHAR     *szConnStrIn
 , BYVAL cbConnStrIn AS INTEGER _                       ' SQLSMALLINT   cbConnStrIn
 , BYREF szConnStrOut AS WSTRINGZ _                     ' SQLWCHAR     *szConnStrOut
 , BYVAL cbConnStrOutMax AS INTEGER  _                  ' SQLSMALLINT   cbConnStrOutMax
 , BYREF pcbConnStrOut AS INTEGER _                     ' SQLSMALLINT  *pcbConnStrOut
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLColumnPrivilegesW IMPORT "ODBC32.DLL" ALIAS "SQLColumnPrivilegesW" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT     hstmt
 , BYREF szCatalogName AS WSTRINGZ _                    ' SQLWCHAR    *szCatalogName
 , BYVAL cbCatalogName AS INTEGER _                     ' SQLSMALLINT  cbCatalogName
 , BYREF szSchemaName AS WSTRINGZ _                     ' SQLWCHAR    *szSchemaName
 , BYVAL cbSchemaName AS INTEGER _                      ' SQLSMALLINT  cbSchemaName
 , BYREF szTableName AS WSTRINGZ _                      ' SQLWCHAR    *szTableName
 , BYVAL cbTableName AS INTEGER _                       ' SQLSMALLINT  cbTableName
 , BYREF szColumnName AS WSTRINGZ _                     ' SQLWCHAR    *szColumnName
 , BYVAL cbColumnName AS INTEGER _                      ' SQLSMALLINT  cbColumnName
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLGetStmtAttrW IMPORT "ODBC32.DLL" ALIAS "SQLGetStmtAttrW" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT    hstmt
 , BYVAL fAttribute AS LONG _                           ' SQLINTEGER  fAttribute
 , BYREF rgbValue AS ANY _                              ' SQLPOINTER  rgbValue
 , BYVAL cbValueMax AS LONG _                           ' SQLINTEGER  cbValueMax
 , BYREF pcbValue AS LONG _                             ' SQLINTEGER *pcbValue
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLSetStmtAttrW IMPORT "ODBC32.DLL" ALIAS "SQLSetStmtAttrW" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT   hstmt
 , BYVAL fAttribute AS LONG _                           ' SQLINTEGER fAttribute
 , BYREF rgbValue AS ANY _                              ' SQLPOINTER rgbValue
 , BYVAL cbValueMax AS LONG _                           ' SQLINTEGER cbValueMax
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLForeignKeysW IMPORT "ODBC32.DLL" ALIAS "SQLForeignKeysW" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT     hstmt
 , BYREF szPkCatalogName AS WSTRINGZ _                  ' SQLWCHAR    *szPkCatalogName
 , BYVAL cbPkCatalogName AS INTEGER _                   ' SQLSMALLINT  cbPkCatalogName
 , BYREF szPkSchemaName AS WSTRINGZ _                   ' SQLWCHAR    *szPkSchemaName
 , BYVAL cbPkSchemaName AS INTEGER _                    ' SQLSMALLINT  cbPkSchemaName
 , BYREF szPkTableName AS WSTRINGZ _                    ' SQLWCHAR    *szPkTableName
 , BYVAL cbPkTableName AS INTEGER _                     ' SQLSMALLINT  cbPkTableName
 , BYREF szFkCatalogName AS WSTRINGZ _                  ' SQLWCHAR    *szFkCatalogName
 , BYVAL cbFkCatalogName AS INTEGER _                   ' SQLSMALLINT  cbFkCatalogName
 , BYREF szFkSchemaName AS WSTRINGZ _                   ' SQLWCHAR    *szFkSchemaName
 , BYVAL cbFkSchemaName AS INTEGER _                    ' SQLSMALLINT  cbFkSchemaName
 , BYREF szFkTableName AS WSTRINGZ _                    ' SQLWCHAR    *szFkTableName
 , BYVAL cbFkTableName AS INTEGER _                     ' SQLSMALLINT cbFkTableName
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLNativeSqlW IMPORT "ODBC32.DLL" ALIAS "SQLNativeSqlW" ( _
   BYVAL hdbc AS DWORD _                                ' SQLHDBC     hdbc
 , BYREF szSqlStrIn AS WSTRINGZ _                       ' SQLWCHAR   *szSqlStrIn
 , BYVAL cbSqlStrIn AS LONG _                           ' SQLINTEGER  cbSqlStrIn
 , BYREF szSqlStr AS WSTRINGZ  _                        ' SQLWCHAR   *szSqlStr
 , BYVAL cbSqlStrMax AS LONG  _                         ' SQLINTEGER  cbSqlStrMax
 , BYREF pcbSqlStr AS LONG _                            ' SQLINTEGER *pcbSqlStr
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLPrimaryKeysW IMPORT "ODBC32.DLL" ALIAS "SQLPrimaryKeysW" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT     hstmt
 , BYREF szCatalogName AS WSTRINGZ _                    ' SQLWCHAR    *szCatalogName
 , BYVAL cbCatalogName AS INTEGER _                     ' SQLSMALLINT  cbCatalogName
 , BYREF szSchemaName AS WSTRINGZ _                     ' SQLWCHAR    *szSchemaName
 , BYVAL cbSchemaName AS INTEGER _                      ' SQLSMALLINT  cbSchemaName
 , BYREF szTableName AS WSTRINGZ _                      ' SQLWCHAR    *szTableName
 , BYVAL cbTableName AS INTEGER _                       ' SQLSMALLINT  cbTableName
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLProcedureColumnsW IMPORT "ODBC32.DLL" ALIAS "SQLProcedureColumnsW" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT     hstmt
 , BYREF szCatalogName AS WSTRINGZ _                    ' SQLWCHAR    *szCatalogName
 , BYVAL cbCatalogName AS INTEGER _                     ' SQLSMALLINT  cbCatalogName
 , BYREF szSchemaName AS WSTRINGZ _                     ' SQLWCHAR    *szSchemaName
 , BYVAL cbSchemaName AS INTEGER _                      ' SQLSMALLINT  cbSchemaName
 , BYREF szProcName AS WSTRINGZ _                       ' SQLWCHAR    *szProcName
 , BYVAL cbProcName AS INTEGER _                        ' SQLSMALLINT  cbProcName
 , BYREF szColumnName AS WSTRINGZ _                     ' SQLWCHAR    *szColumnName
 , BYVAL cbColumnName AS INTEGER _                      ' SQLSMALLINT  cbColumnName
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLProceduresW IMPORT "ODBC32.DLL" ALIAS "SQLProceduresW" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT     hstmt
 , BYREF szCatalogName AS WSTRINGZ _                    ' SQLWCHAR    *szCatalogName
 , BYVAL cbCatalogName AS INTEGER _                     ' SQLSMALLINT  cbCatalogName
 , BYREF szSchemaName AS WSTRINGZ _                     ' SQLWCHAR    *szSchemaName
 , BYVAL cbSchemaName AS INTEGER _                      ' SQLSMALLINT  cbSchemaName
 , BYREF szProcName AS WSTRINGZ _                       ' SQLWCHAR    *szProcName
 , BYVAL cbProcName AS INTEGER _                        ' SQLSMALLINT  cbProcName
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLTablePrivilegesW IMPORT "ODBC32.DLL" ALIAS "SQLTablePrivilegesW" ( _
   BYVAL hstmt AS DWORD _                               ' SQLHSTMT     hstmt
 , BYREF szCatalogName AS WSTRINGZ _                    ' SQLWCHAR    *szCatalogName
 , BYVAL cbCatalogName AS INTEGER _                     ' SQLSMALLINT  cbCatalogName
 , BYREF szSchemaName AS WSTRINGZ _                     ' SQLWCHAR    *szSchemaName
 , BYVAL cbSchemaName AS INTEGER _                      ' SQLSMALLINT  cbSchemaName
 , BYREF szTableName AS WSTRINGZ _                      ' SQLWCHAR    *szTableName
 , BYVAL cbTableName AS INTEGER _                       ' SQLSMALLINT  cbTableName
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLDriversW IMPORT "ODBC32.DLL" ALIAS "SQLDriversW" ( _
   BYVAL henv AS DWORD _                                ' SQLHENV       henv
 , BYVAL fDirection AS WORD _                           ' SQLUSMALLINT  fDirection
 , BYREF szDriverDesc AS WSTRINGZ _                     ' SQLWCHAR     *szDriverDesc
 , BYVAL cbDriverDescMax AS INTEGER _                   ' SQLSMALLINT   cbDriverDescMax
 , BYREF pcbDriverDesc AS INTEGER _                     ' SQLSMALLINT  *pcbDriverDesc
 , BYREF szDriverAttributes AS WSTRINGZ _               ' SQLWCHAR     *szDriverAttributes
 , BYVAL cbDrvrAttrMax AS INTEGER _                     ' SQLSMALLINT   cbDrvrAttrMax
 , BYREF pcbDrvrAttr AS INTEGER _                       ' SQLSMALLINT  *pcbDrvrAttr
 ) AS INTEGER                                           ' SQLRETURN
