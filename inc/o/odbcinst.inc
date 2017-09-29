' ########################################################################################
' Microsoft Windows
' File: odbcinst.inc
' Contents: Installer DLL API.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ODBCINST_INC = 1

#INCLUDE ONCE "sql.inc"

#IF NOT %DEF(%ODBCVER)
%ODBCVER = &H0380                 ' // Default to ODBC 3.80
#ENDIF

'#ifndef WINVER
'#define  WINVER  0x0400                     // Assume Windows 4.0
'#endif

'// Constants ---------------------------------------------------------------
'// SQLConfigDataSource request flags
%ODBC_ADD_DSN     = 1            ' // Add data source
%ODBC_CONFIG_DSN  = 2            ' // Configure (edit) data source
%ODBC_REMOVE_DSN  = 3            ' // Remove data source

#IF %ODBCVER >= &H0250
%ODBC_ADD_SYS_DSN        = 4     ' // add a system DSN
%ODBC_CONFIG_SYS_DSN     = 5     ' // Configure a system DSN
%ODBC_REMOVE_SYS_DSN     = 6     ' // remove a system DSN
#IF %ODBCVER >= &H0300
%ODBC_REMOVE_DEFAULT_DSN = 7     ' // remove the default DSN
#ENDIF   ' /* ODBCVER >= &H0300 */

'// install request flags
%ODBC_INSTALL_INQUIRY    = 1
%ODBC_INSTALL_COMPLETE   = 2

'// config driver flags
%ODBC_INSTALL_DRIVER     = 1
%ODBC_REMOVE_DRIVER      = 2
%ODBC_CONFIG_DRIVER      = 3
%ODBC_CONFIG_DRIVER_MAX  = 100
#ENDIF   ' /* ODBCVER >= &H0250 */

'// SQLGetConfigMode and SQLSetConfigMode flags
#IF %ODBCVER >= &H0300
%ODBC_BOTH_DSN           = 0
%ODBC_USER_DSN           = 1
%ODBC_SYSTEM_DSN         = 2
#ENDIF   ' /* ODBCVER >= &H0300 */

'// SQLInstallerError code
#IF %ODBCVER >= &H0300
%ODBC_ERROR_GENERAL_ERR                 =  1
%ODBC_ERROR_INVALID_BUFF_LEN            =  2
%ODBC_ERROR_INVALID_HWND                =  3
%ODBC_ERROR_INVALID_STR                 =  4
%ODBC_ERROR_INVALID_REQUEST_TYPE        =  5
%ODBC_ERROR_COMPONENT_NOT_FOUND         =  6
%ODBC_ERROR_INVALID_NAME                =  7
%ODBC_ERROR_INVALID_KEYWORD_VALUE       =  8
%ODBC_ERROR_INVALID_DSN                 =  9
%ODBC_ERROR_INVALID_INF                 = 10
%ODBC_ERROR_REQUEST_FAILED              = 11
%ODBC_ERROR_INVALID_PATH                = 12
%ODBC_ERROR_LOAD_LIB_FAILED             = 13
%ODBC_ERROR_INVALID_PARAM_SEQUENCE      = 14
%ODBC_ERROR_INVALID_LOG_FILE            = 15
%ODBC_ERROR_USER_CANCELED               = 16
%ODBC_ERROR_USAGE_UPDATE_FAILED         = 17
%ODBC_ERROR_CREATE_DSN_FAILED           = 18
%ODBC_ERROR_WRITING_SYSINFO_FAILED      = 19
%ODBC_ERROR_REMOVE_DSN_FAILED           = 20
%ODBC_ERROR_OUT_OF_MEM                  = 21
%ODBC_ERROR_OUTPUT_STRING_TRUNCATED     = 22
%ODBC_ERROR_NOTRANINFO                  = 23
%ODBC_ERROR_MAX                         = %ODBC_ERROR_NOTRANINFO   ' // update this when we add new error message
#ENDIF   ' /* ODBCVER >= &H0300 */

'// Prototypes --------------------------------------------------------------

'// High level APIs

DECLARE FUNCTION SQLInstallODBCA IMPORT "ODBCCP32.DLL" ALIAS "SQLInstallODBC" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND   hwndParent
 , BYREF lpszInfFile AS ASCIIZ _                        ' __in LPCSTR lpszInfFile
 , BYREF lpszSrcPath AS ASCIIZ _                        ' __in LPCSTR lpszSrcPath
 , BYREF lpszDrivers AS ASCIIZ _                        ' __in LPCSTR lpszDrivers
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SQLManageDataSources IMPORT "ODBCCP32.DLL" ALIAS "SQLManageDataSources" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SQLCreateDataSourceA IMPORT "ODBCCP32.DLL" ALIAS "SQLCreateDataSource" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND   hwndParent
 , BYREF lpszDSN AS ASCIIZ _                            ' __in LPCSTR lpszDSN
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SQLGetTranslatorA IMPORT "ODBCCP32.DLL" ALIAS "SQLGetTranslator" ( _
   BYVAL hwnd AS DWORD _                                ' __in  HWND      hwnd
 , BYREF lpszName AS ASCIIZ _                           ' __inout LPSTR   lpszName
 , BYVAL cbNameMax AS WORD _                            ' __in  WORD      cbNameMax
 , BYREF pcbNameOut AS WORD _                           ' __inout WORD   *pcbNameOut
 , BYREF lpszPath AS ASCIIZ _                           ' __out LPSTR     lpszPath
 , BYVAL cbPathMax AS WORD _                            ' __in  WORD      cbPathMax
 , BYREF pcbPathOut AS WORD _                           ' __out WORD     *pcbPathOut
 , BYREF pvOption AS DWORD _                            ' __out DWORD    *pvOption
 ) AS LONG                                              ' BOOL

'// Low level APIs
'// NOTE: The high-level APIs should always be used. These APIs
'//       have been left for compatibility.

DECLARE FUNCTION SQLInstallDriverA IMPORT "ODBCCP32.DLL" ALIAS "SQLInstallDriver" ( _
   BYREF lpszInfFile AS ASCIIZ _                        ' __in  LPCSTR  lpszInfFile
 , BYREF lpszDriver AS ASCIIZ _                         ' __in  LPCSTR  lpszDriver
 , BYREF lpszPath AS ASCIIZ _                           ' __out LPSTR   lpszPath
 , BYVAL cbPathMax AS WORD _                            ' __in  WORD    cbPathMax
 , BYREF pcbPathOut AS WORD _                           ' __out WORD   *pcbPathOut
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SQLInstallDriverManagerA IMPORT "ODBCCP32.DLL" ALIAS "SQLInstallDriverManager" ( _
   BYREF lpszPath AS ASCIIZ _                           ' __out LPSTR  lpszPath
 , BYVAL cbPathMax AS WORD _                            ' __in  WORD   cbPathMax
 , BYREF pcbPathOut AS WORD _                           ' __out WORD  *pcbPathOut
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SQLGetInstalledDriversA IMPORT "ODBCCP32.DLL" ALIAS "SQLGetInstalledDrivers" ( _
   BYREF lpszBuf AS ASCIIZ _                            ' __out LPSTR  lpszBuf
 , BYVAL cbBufMax AS WORD _                             ' __in  WORD   cbBufMax
 , BYREF pcbBufOut AS WORD _                            ' __out WORD  *pcbBufOut
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SQLGetAvailableDriversA IMPORT "ODBCCP32.DLL" ALIAS "SQLGetAvailableDrivers" ( _
   BYREF lpszInfile AS ASCIIZ _                         ' __in  LPCSTR  lpszInfile
 , BYREF lpszBuf AS ASCIIZ _                            ' __out LPSTR   lpszBuf
 , BYVAL cbBufMax AS WORD _                             ' __in  WORD    cbBufMax
 , BYREF pcbBufOut AS WORD _                            ' __out WORD   *pcbBufOut
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SQLConfigDataSourceA IMPORT "ODBCCP32.DLL" ALIAS "SQLConfigDataSource" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND   hwndParent
 , BYVAL fRequest AS WORD _                             ' __in WORD   fRequest
 , BYREF lpszDriver AS ASCIIZ _                         ' __in LPCSTR lpszDriver
 , BYREF lpszAttributes AS ASCIIZ _                     ' __in LPCSTR lpszAttributes
 ) AS LONG                                              ' BOOL

' In ODBC 3.0, the SQLRemoveDefaultDataSource function has been replaced by
' a call to SQLConfigDataSource with an fRequest argument of
' ODBC_REMOVE_DEFAULT_DSN.

DECLARE FUNCTION SQLRemoveDefaultDataSource IMPORT "ODBCCP32.DLL" ALIAS "SQLRemoveDefaultDataSource" ( _
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SQLWriteDSNToIniA IMPORT "ODBCCP32.DLL" ALIAS "SQLWriteDSNToIni" ( _
   BYREF lpszDSN AS ASCIIZ _                            ' __in LPCSTR lpszDSN
 , BYREF lpszDriver AS ASCIIZ _                         ' __in LPCSTR lpszDriver
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SQLRemoveDSNFromIniA IMPORT "ODBCCP32.DLL" ALIAS "SQLRemoveDSNFromIni" ( _
   BYREF lpszDSN AS ASCIIZ _                            ' __in LPCSTR lpszDSN
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SQLValidDSNA IMPORT "ODBCCP32.DLL" ALIAS "SQLValidDSN" ( _
   BYREF lpszDSN AS ASCIIZ _                            ' __in LPCSTR lpszDSN
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SQLWritePrivateProfileStringA IMPORT "ODBCCP32.DLL" ALIAS "SQLWritePrivateProfileString" ( _
   BYREF lpszSection AS ASCIIZ _                        ' __in  LPCSTR lpszSection
 , BYREF lpszEntry AS ASCIIZ _                          ' __in  LPCSTR lpszEntry
 , BYREF lpszString AS ASCIIZ _                         ' __in  LPCSTR lpszString
 , BYREF lpszFileName AS ASCIIZ _                       ' __out LPCSTR lpszFileName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SQLGetPrivateProfileStringA IMPORT "ODBCCP32.DLL" ALIAS "SQLGetPrivateProfileString" ( _
   BYREF lpszSection AS ASCIIZ _                        ' __in  LPCSTR lpszSection
 , BYREF lpszEntry AS ASCIIZ _                          ' __in  LPCSTR lpszEntry
 , BYREF lpszDefault AS ASCIIZ _                        ' __in  LPCSTR lpszDefault
 , BYREF lpszRetBuffer AS ASCIIZ _                      ' __out LPSTR  lpszRetBuffer
 , BYVAL cbRetBuffer AS INTEGER _                       ' __in  int    cbRetBuffer
 , BYREF lpszFileName AS ASCIIZ _                       ' __out LPCSTR lpszFileName
 ) AS LONG                                              ' int

#IF %ODBCVER >= &H0250

DECLARE FUNCTION SQLRemoveDriverManager IMPORT "ODBCCP32.DLL" ALIAS "SQLRemoveDriverManager" ( _
   BYREF lpdwUsageCount AS DWORD _                      ' __out LPDWORD lpdwUsageCount
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SQLInstallTranslatorA IMPORT "ODBCCP32.DLL" ALIAS "SQLInstallTranslator" ( _
   BYREF lpszInfFile AS ASCIIZ _                        ' __in  LPCSTR   lpszInfFile
 , BYREF lpszTranslator AS ASCIIZ _                     ' __in  LPCSTR   lpszTranslator
 , BYREF lpszPathIn AS ASCIIZ _                         ' __in  LPCSTR   lpszPathIn
 , BYREF lpszPathOut AS ASCIIZ _                        ' __out LPSTR    lpszPathOut
 , BYVAL cbPathOutMax AS WORD _                         ' __in  WORD     cbPathOutMax
 , BYREF pcbPathOut AS WORD _                           ' __out WORD    *pcbPathOut
 , BYVAL fRqquest AS WORD _                             ' __in  WORD     fRqquest
 , BYREF lpdwUsageCount AS DWORD _                      ' __out LPDWORD  lpdwUsageCount
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SQLRemoveTranslatorA IMPORT "ODBCCP32.DLL" ALIAS "SQLRemoveTranslator" ( _
   BYREF lpszTranslator AS ASCIIZ _                     ' __in  LPCSTR  lpszTranslator
 , BYREF lpdwUsageCount AS DWORD _                      ' __out LPDWORD lpdwUsageCount
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SQLRemoveDriverA IMPORT "ODBCCP32.DLL" ALIAS "SQLRemoveDriver" ( _
   BYREF lpszDriver AS ASCIIZ _                         ' __in  LPCSTR  lpszDriver
 , BYVAL fRemoveDSN AS LONG _                           ' __in  BOOL    fRemoveDSN
 , BYREF lpdwUsageCount AS DWORD _                      ' __out LPDWORD lpdwUsageCount
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SQLConfigDriverA IMPORT "ODBCCP32.DLL" ALIAS "SQLConfigDriver" ( _
   BYVAL hwndParent AS DWORD _                          ' __in  HWND   hwndParent
 , BYVAL fRequest AS WORD _                             ' __in  WORD   fRequest
 , BYREF lpszDriver AS ASCIIZ _                         ' __in  LPCSTR lpszDriver
 , BYREF lpszArgs AS ASCIIZ _                           ' __in  LPCSTR lpszArgs
 , BYREF lpszMsg AS ASCIIZ _                            ' __out LPSTR  lpszMsg
 , BYVAL cbMsgMax AS WORD _                             ' __in  WORD   cbMsgMax
 , BYREF pcbMsgOut AS WORD _                            ' __out WORD   pcbMsgOut
 ) AS LONG                                              ' BOOL

#ENDIF   ' /* ODBCVER >= 0x0250 */

#IF %ODBCVER >=  &H0300

DECLARE FUNCTION SQLInstallerErrorA IMPORT "ODBCCP32.DLL" ALIAS "SQLInstallerError" ( _
   BYVAL iError AS WORD _                               ' WORD    iError
 , BYREF pfErrorCode AS DWORD _                         ' DWORD  *pfErrorCode
 , BYREF lpszErrorMsg AS ASCIIZ _                       ' LPCSTR  lpszErrorMsg
 , BYVAL cbErrorMsgMax AS WORD _                        ' WORD    cbErrorMsgMax
 , BYREF pcbErrorMsg AS WORD _                          ' WORD    pcbErrorMsg
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLPostInstallerErrorA IMPORT "ODBCCP32.DLL" ALIAS "SQLPostInstallerError" ( _
   BYVAL dwErrorCode AS DWORD _                         ' DWORD  dwErrorCode
 , BYREF lpszErrMsg AS ASCIIZ _                         ' LPCSTR lpszErrMsg
 ) AS INTEGER                                           ' SQLRETURN

DECLARE FUNCTION SQLWriteFileDSNA IMPORT "ODBCCP32.DLL" ALIAS "SQLWriteFileDSN" ( _
   BYREF lpszFileName AS ASCIIZ _                       ' LPCSTR lpszFileName
 , BYREF lpszAppName AS ASCIIZ _                        ' LPCSTR lpszAppName
 , BYREF lpszKeyName AS ASCIIZ _                        ' LPCSTR lpszKeyName
 , BYREF lpszString AS ASCIIZ _                         ' LPCSTR lpszString
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SQLReadFileDSNA IMPORT "ODBCCP32.DLL" ALIAS "SQLReadFileDSN" ( _
   BYREF lpszFileName AS ASCIIZ _                       ' LPCSTR  lpszFileName
 , BYREF lpszAppName AS ASCIIZ _                        ' LPCSTR  lpszAppName
 , BYREF lpszKeyName AS ASCIIZ _                        ' LPCSTR  lpszKeyName
 , BYREF lpszString AS ASCIIZ _                         ' LPSTR   lpszString
 , BYVAL cbString AS WORD _                             ' WORD    cbString
 , BYREF pcbString AS WORD _                            ' WORD   *pcbString
 ) AS LONG                                              ' BOOL

' // Note: lpszDriver has been declared as BYVAL DWORD instead of BYREF ASCIIZ because
' // we have to pass a doubly null-terminated list of null separated keyword-value pairs
' // describing the driver.
DECLARE FUNCTION SQLInstallDriverExA IMPORT "ODBCCP32.DLL" ALIAS "SQLInstallDriverEx" ( _
   BYVAL lpszDriver AS DWORD _                          ' LPCSTR   lpszDriver
 , BYREF lpszPathIn AS ASCIIZ _                         ' LPCSTR   lpszPathIn
 , BYREF lpszPathOut AS ASCIIZ _                        ' LPSTR    lpszPathOut
 , BYVAL cbPathOutMax AS WORD _                         ' WORD     cbPathOutMax
 , BYREF pcbPathOut AS WORD _                           ' WORD    *pcbPathOut
 , BYVAL fRequest AS WORD _                             ' WORD     fRequest
 , BYREF lpdwUsageCount AS DWORD _                      ' LPDWORD  lpdwUsageCount
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SQLInstallTranslatorExA IMPORT "ODBCCP32.DLL" ALIAS "SQLInstallTranslatorEx" ( _
   BYREF lpszTranslator AS ASCIIZ _                     ' LPCSTR  lpszTranslator
 , BYREF lpszPathIn AS ASCIIZ _                         ' LPCSTR  lpszPathIn
 , BYREF lpszPathOut AS ASCIIZ _                        ' LPSTR   lpszPathOut
 , BYVAL cbPathOutMax AS WORD _                         ' WORD    cbPathOutMax
 , BYREF pcbPathOut AS WORD _                           ' WORD    pcbPathOut
 , BYVAL fRqquest AS WORD _                             ' WORD    fRqquest
 , BYREF lpdwUsageCount AS DWORD _                      ' LPDWORD lpdwUsageCount
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SQLGetConfigMode IMPORT "ODBCCP32.DLL" ALIAS "SQLGetConfigMode" ( _
   BYREF pwConfigMode AS WORD _                         ' UWORD *pwConfigMode
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SQLSetConfigMode IMPORT "ODBCCP32.DLL" ALIAS "SQLSetConfigMode" ( _
   BYVAL wConfigMode AS WORD _                          ' UWORD wConfigMode
 ) AS LONG                                              ' BOOL


#ENDIF   ' /* ODBCVER >= 0x0300 */

'//   Driver specific Setup APIs called by installer

'BOOL INSTAPI ConfigDSN (
'   HWND   hwndParent,
'   WORD     fRequest,
'   LPCSTR   lpszDriver,
'   LPCSTR   lpszAttributes);

'BOOL INSTAPI ConfigTranslator (
'   HWND      hwndParent,
'   DWORD    *pvOption);

'#IF %ODBCVER >= &H0250
'BOOL INSTAPI ConfigDriver (
'   HWND hwndParent,
'   WORD fRequest,
'   LPCSTR lpszDriver,
'   LPCSTR lpszArgs,
'   LPSTR  lpszMsg,
'   WORD   cbMsgMax,
'   WORD   *pcbMsgOut);

'#ENDIF


'// UNICODE APIs

'// High level APIs

DECLARE FUNCTION SQLInstallODBCW IMPORT "ODBCCP32.DLL" ALIAS "SQLInstallODBCW" ( _
   BYREF hwndParent AS DWORD _                          ' HWND    hwndParent
 , BYREF lpszInfFile AS WSTRINGZ _                      ' LPCWSTR lpszInfFile
 , BYREF lpszSrcPath AS WSTRINGZ _                      ' LPCWSTR lpszSrcPath
 , BYREF lpszDrivers AS WSTRINGZ _                      ' LPCWSTR lpszDrivers
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SQLInstallODBC = SQLInstallODBCW
#ELSE
   MACRO SQLInstallODBC = SQLInstallODBCA
#ENDIF

DECLARE FUNCTION SQLCreateDataSourceW IMPORT "ODBCCP32.DLL" ALIAS "SQLCreateDataSourceW" ( _
   BYVAL hwndParent AS DWORD _                          ' HWND    hwndParent
 , BYREF lpszDSN AS WSTRINGZ _                          ' LPCWSTR lpszDSN
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SQLCreateDataSource = SQLCreateDataSourceW
#ELSE
   MACRO SQLCreateDataSource = SQLCreateDataSourceA
#ENDIF

DECLARE FUNCTION SQLGetTranslatorW IMPORT "ODBCCP32.DLL" ALIAS "SQLGetTranslatorW" ( _
   BYVAL hwnd AS DWORD _                                ' HWND    hwnd
 , BYREF lpszName AS WSTRINGZ _                         ' LPWSTR  lpszName
 , BYVAL cbNameMax AS WORD _                            ' WORD    cbNameMax
 , BYREF pcbNameOut AS WORD _                           ' WORD   *pcbNameOut
 , BYREF lpszPath AS WSTRINGZ _                         ' LPWSTR  lpszPath
 , BYVAL cbPathMax AS WORD _                            ' WORD    cbPathMax
 , BYREF pcbPathOut AS WORD _                           ' WORD   *pcbPathOut
 , BYREF pvOption AS DWORD _                            ' DWORD  *pvOption
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SQLGetTranslator = SQLGetTranslatorW
#ELSE
   MACRO SQLGetTranslator = SQLGetTranslatorA
#ENDIF

'// Low level APIs
'// NOTE: The high-level APIs should always be used. These APIs
'//       have been left for compatibility.

DECLARE FUNCTION SQLInstallDriverW IMPORT "ODBCCP32.DLL" ALIAS "SQLInstallDriverW" ( _
   BYREF lpszInfFile AS WSTRINGZ _                      ' LPCWSTR    lpszInfFile
 , BYREF lpszDriver AS WSTRINGZ _                       ' LPCWSTR    lpszDriver
 , BYREF lpszPath AS WSTRINGZ _                         ' LPWSTR     lpszPath
 , BYVAL cbPathMax AS WORD _                            ' WORD       cbPathMax
 , BYREF pcbPathOut AS WORD _                           ' WORD      *pcbPathOut
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SQLInstallDriver = SQLInstallDriverW
#ELSE
   MACRO SQLInstallDriver = SQLInstallDriverA
#ENDIF

DECLARE FUNCTION SQLInstallDriverManagerW IMPORT "ODBCCP32.DLL" ALIAS "SQLInstallDriverManagerW" ( _
   BYREF lpszPath AS WSTRINGZ _                         ' LPWSTR lpszPath
 , BYVAL cbPathMax AS WORD _                            ' WORD   cbPathMax
 , BYREF pcbPathOut AS WORD _                           ' WORD  *pcbPathOut
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SQLInstallDriverManager = SQLInstallDriverManagerW
#ELSE
   MACRO SQLInstallDriverManager = SQLInstallDriverManagerA
#ENDIF

DECLARE FUNCTION SQLGetInstalledDriversW IMPORT "ODBCCP32.DLL" ALIAS "SQLGetInstalledDriversW" ( _
   BYREF lpszBuf AS WSTRINGZ _                          ' LPWSTR lpszBuf
 , BYVAL cbBufMax AS WORD _                             ' WORD  cbBufMax
 , BYREF pcbBufOut AS WORD _                            ' WORD *pcbBufOut
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SQLGetInstalledDrivers = SQLGetInstalledDriversW
#ELSE
   MACRO SQLGetInstalledDrivers = SQLGetInstalledDriversA
#ENDIF

DECLARE FUNCTION SQLGetAvailableDriversW IMPORT "ODBCCP32.DLL" ALIAS "SQLGetAvailableDriversW" ( _
   BYREF lpszInfile AS WSTRINGZ _                       ' LPCWSTR  lpszInfile
 , BYREF lpszBuf AS WSTRINGZ _                          ' LPWSTR   lpszBuf
 , BYVAL cbBufMax AS WORD _                             ' WORD     cbBufMax
 , BYREF pcbBufOut AS WORD _                            ' WORD    *pcbBufOut
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SQLGetAvailableDrivers = SQLGetAvailableDriversW
#ELSE
   MACRO SQLGetAvailableDrivers = SQLGetAvailableDriversA
#ENDIF

DECLARE FUNCTION SQLConfigDataSourceW IMPORT "ODBCCP32.DLL" ALIAS "SQLConfigDataSourceW" ( _
   BYVAL hwndParent AS DWORD _                          ' HWND    hwndParent
 , BYVAL fRequest AS WORD _                             ' WORD    fRequest
 , BYREF lpszDriver AS WSTRINGZ _                       ' LPCWSTR lpszDriver
 , BYREF lpszAttributes AS WSTRINGZ _                   ' LPCWSTR lpszAttributes
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SQLConfigDataSource = SQLConfigDataSourceW
#ELSE
   MACRO SQLConfigDataSource = SQLConfigDataSourceA
#ENDIF

DECLARE FUNCTION SQLWriteDSNToIniW IMPORT "ODBCCP32.DLL" ALIAS "SQLWriteDSNToIniW" ( _
   BYREF lpszDSN AS WSTRINGZ _                          ' LPCWSTR lpszDSN
 , BYREF lpszDriver AS WSTRINGZ _                       ' LPCWSTR lpszDriver
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SQLWriteDSNToIni = SQLWriteDSNToIniW
#ELSE
   MACRO SQLWriteDSNToIni = SQLWriteDSNToIniA
#ENDIF

DECLARE FUNCTION SQLRemoveDSNFromIniW IMPORT "ODBCCP32.DLL" ALIAS "SQLRemoveDSNFromIniW" ( _
   BYREF lpszDSN AS WSTRINGZ _                          ' LPCWSTR lpszDSN
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SQLRemoveDSNFromIni = SQLRemoveDSNFromIniW
#ELSE
   MACRO SQLRemoveDSNFromIni = SQLRemoveDSNFromIniA
#ENDIF

DECLARE FUNCTION SQLValidDSNW IMPORT "ODBCCP32.DLL" ALIAS "SQLValidDSNW" ( _
   BYREF lpszDSN AS WSTRINGZ _                          ' LPCWSTR lpszDSN
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SQLValidDSN = SQLValidDSNW
#ELSE
   MACRO SQLValidDSN = SQLValidDSNA
#ENDIF

DECLARE FUNCTION SQLWritePrivateProfileStringW IMPORT "ODBCCP32.DLL" ALIAS "SQLWritePrivateProfileStringW" ( _
   BYREF lpszSection AS WSTRINGZ _                      ' LPCWSTR lpszSection
 , BYREF lpszEntry AS WSTRINGZ _                        ' LPCWSTR lpszEntry
 , BYREF lpszString AS WSTRINGZ _                       ' LPCWSTR lpszString
 , BYREF lpszFileName AS WSTRINGZ _                     ' LPCWSTR lpszFileName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SQLWritePrivateProfileString = SQLWritePrivateProfileStringW
#ELSE
   MACRO SQLWritePrivateProfileString = SQLWritePrivateProfileStringA
#ENDIF

DECLARE FUNCTION SQLGetPrivateProfileStringW IMPORT "ODBCCP32.DLL" ALIAS "SQLGetPrivateProfileStringW" ( _
   BYREF lpszSection AS WSTRINGZ _                      ' LPCWSTR lpszSection
 , BYREF lpszEntry AS WSTRINGZ _                        ' LPCWSTR lpszEntry
 , BYREF lpszDefault AS WSTRINGZ _                      ' LPCWSTR lpszDefault
 , BYREF lpszRetBuffer AS WSTRINGZ _                    ' LPWSTR  lpszRetBuffer
 , BYVAL cbRetBuffer AS INTEGER _                       ' int     cbRetBuffer
 , BYREF lpszFileName AS WSTRINGZ _                     ' LPCWSTR lpszFileName
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO SQLGetPrivateProfileString = SQLGetPrivateProfileStringW
#ELSE
   MACRO SQLGetPrivateProfileString = SQLGetPrivateProfileStringA
#ENDIF

#IF %ODBCVER >= &H0250

DECLARE FUNCTION SQLInstallTranslatorW IMPORT "ODBCCP32.DLL" ALIAS "SQLInstallTranslatorW" ( _
   BYREF lpszInfFile AS WSTRINGZ _                      ' LPCWSTR   lpszInfFile
 , BYREF lpszTranslator AS WSTRINGZ _                   ' LPCWSTR   lpszTranslator
 , BYREF lpszPathIn AS WSTRINGZ _                       ' LPCWSTR   lpszPathIn
 , BYREF lpszPathOut AS WSTRINGZ _                      ' LPWSTR    lpszPathOut
 , BYVAL cbPathOutMax AS WORD _                         ' WORD      cbPathOutMax
 , BYREF pcbPathOut AS WORD _                           ' WORD     *pcbPathOut
 , BYVAL fRqquest AS WORD _                             ' WORD      fRqquest
 , BYREF lpdwUsageCount AS DWORD _                      ' LPDWORD   lpdwUsageCount
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SQLInstallTranslator = SQLInstallTranslatorW
#ELSE
   MACRO SQLInstallTranslator = SQLInstallTranslatorA
#ENDIF

DECLARE FUNCTION SQLRemoveTranslatorW IMPORT "ODBCCP32.DLL" ALIAS "SQLRemoveTranslatorW" ( _
   BYREF lpszTranslator AS WSTRINGZ _                   ' LPCWSTR  lpszTranslator
 , BYREF lpdwUsageCount AS DWORD _                      ' LPDWORD  lpdwUsageCount
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SQLRemoveTranslator = SQLRemoveTranslatorW
#ELSE
   MACRO SQLRemoveTranslator = SQLRemoveTranslatorA
#ENDIF

DECLARE FUNCTION SQLRemoveDriverW IMPORT "ODBCCP32.DLL" ALIAS "SQLRemoveDriverW" ( _
   BYREF lpszDriver AS WSTRINGZ _                       ' LPCWSTR  lpszDriver
 , BYVAL fRemoveDSN AS LONG _                           ' BOOL     fRemoveDSN
 , BYREF lpdwUsageCount AS DWORD _                      ' LPDWORD  lpdwUsageCount
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SQLRemoveDriver = SQLRemoveDriverW
#ELSE
   MACRO SQLRemoveDriver = SQLRemoveDriverA
#ENDIF

DECLARE FUNCTION SQLConfigDriverW IMPORT "ODBCCP32.DLL" ALIAS "SQLConfigDriverW" ( _
   BYVAL hwndParent AS DWORD _                          ' HWND    hwndParent
 , BYVAL fRequest AS WORD _                             ' WORD    fRequest
 , BYREF lpszDriver AS WSTRINGZ _                       ' LPCWSTR lpszDriver
 , BYREF lpszArgs AS WSTRINGZ _                         ' LPCWSTR lpszArgs
 , BYREF lpszMsg AS WSTRINGZ _                          ' LPWSTR  lpszMsg
 , BYVAL cbMsgMax AS WORD _                             ' WORD    cbMsgMax
 , BYREF pcbMsgOut AS WORD _                            ' WORD    pcbMsgOut
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SQLConfigDriver = SQLConfigDriverW
#ELSE
   MACRO SQLConfigDriver = SQLConfigDriverA
#ENDIF

#ENDIF

#IF %ODBCVER >= &H0300
DECLARE FUNCTION SQLInstallerErrorW IMPORT "ODBCCP32.DLL" ALIAS "SQLInstallerErrorW" ( _
   BYVAL iError AS WORD _                               ' WORD     iError
 , BYREF pfErrorCode AS DWORD _                         ' DWORD   *pfErrorCode
 , BYREF lpszErrorMsg AS WSTRINGZ _                     ' LPCWSTR  lpszErrorMsg
 , BYVAL cbErrorMsgMax AS WORD _                        ' WORD     cbErrorMsgMax
 , BYREF pcbErrorMsg AS WORD _                          ' WORD     pcbErrorMsg
 ) AS INTEGER                                           ' SQLRETURN

#IF %DEF(%UNICODE)
   MACRO SQLInstallerError = SQLInstallerErrorW
#ELSE
   MACRO SQLInstallerError = SQLInstallerErrorA
#ENDIF

DECLARE FUNCTION SQLPostInstallerErrorW IMPORT "ODBCCP32.DLL" ALIAS "SQLPostInstallerErrorW" ( _
   BYVAL dwErrorCode AS DWORD _                         ' DWORD   dwErrorCode
 , BYREF lpszErrMsg AS WSTRINGZ _                       ' LPCWSTR lpszErrMsg
 ) AS INTEGER                                           ' SQLRETURN

#IF %DEF(%UNICODE)
   MACRO SQLPostInstallerError = SQLPostInstallerErrorW
#ELSE
   MACRO SQLPostInstallerError = SQLPostInstallerErrorA
#ENDIF

DECLARE FUNCTION SQLWriteFileDSNW IMPORT "ODBCCP32.DLL" ALIAS "SQLWriteFileDSNW" ( _
   BYREF lpszFileName AS WSTRINGZ _                     ' LPCWSTR lpszFileName
 , BYREF lpszAppName AS WSTRINGZ _                      ' LPCWSTR lpszAppName
 , BYREF lpszKeyName AS WSTRINGZ _                      ' LPCWSTR lpszKeyName
 , BYREF lpszString AS WSTRINGZ _                       ' LPCWSTR lpszString
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SQLWriteFileDSN = SQLWriteFileDSNW
#ELSE
   MACRO SQLWriteFileDSN = SQLWriteFileDSNA
#ENDIF

DECLARE FUNCTION SQLReadFileDSNW IMPORT "ODBCCP32.DLL" ALIAS "SQLReadFileDSNW" ( _
   BYREF lpszFileName AS WSTRINGZ _                     ' LPCWSTR  lpszFileName
 , BYREF lpszAppName AS WSTRINGZ _                      ' LPCWSTR  lpszAppName
 , BYREF lpszKeyName AS WSTRINGZ _                      ' LPCWSTR  lpszKeyName
 , BYREF lpszString AS WSTRINGZ  _                      ' LPWSTR   lpszString
 , BYVAL cbString AS WORD _                             ' WORD     cbString
 , BYREF pcbString AS WORD _                            ' WORD    *pcbString
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SQLReadFileDSN = SQLReadFileDSNW
#ELSE
   MACRO SQLReadFileDSN = SQLReadFileDSNA
#ENDIF

' // Note: lpszDriver has been declared as BYVAL DWORD instead of BYREF ASCIIZ because
' // we have to pass a doubly null-terminated list of null separated keyword-value pairs
' // describing the driver.
DECLARE FUNCTION SQLInstallDriverExW IMPORT "ODBCCP32.DLL" ALIAS "SQLInstallDriverExW" ( _
   BYVAL lpszDriver AS DWORD _                          ' LPCWSTR   lpszDriver
 , BYREF lpszPathIn AS WSTRINGZ _                       ' LPCWSTR   lpszPathIn
 , BYREF lpszPathOut AS WSTRINGZ _                      ' LPWSTR    lpszPathOut
 , BYVAL cbPathOutMax AS WORD _                         ' WORD      cbPathOutMax
 , BYREF pcbPathOut AS WORD _                           ' WORD     *pcbPathOut
 , BYVAL fRequest AS WORD _                             ' WORD      fRequest
 , BYREF lpdwUsageCount AS DWORD _                      ' LPDWORD   lpdwUsageCount
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SQLInstallDriverEx = SQLInstallDriverExW
#ELSE
   MACRO SQLInstallDriverEx = SQLInstallDriverExA
#ENDIF

DECLARE FUNCTION SQLInstallTranslatorExW IMPORT "ODBCCP32.DLL" ALIAS "SQLInstallTranslatorExW" ( _
   BYREF lpszTranslator AS WSTRINGZ _                   ' LPCWSTR  lpszTranslator
 , BYREF lpszPathIn AS WSTRINGZ _                       ' LPCWSTR  lpszPathIn
 , BYREF lpszPathOut AS WSTRINGZ _                      ' LPWSTR   lpszPathOut
 , BYVAL cbPathOutMax AS WORD _                         ' WORD     cbPathOutMax
 , BYREF pcbPathOut AS WORD _                           ' WORD     pcbPathOut
 , BYVAL fRqquest AS WORD _                             ' WORD     fRqquest
 , BYREF lpdwUsageCount AS DWORD _                      ' LPDWORD  lpdwUsageCount
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SQLInstallTranslatorEx = SQLInstallTranslatorExW
#ELSE
   MACRO SQLInstallTranslatorEx = SQLInstallTranslatorExA
#ENDIF

#ENDIF   ' /* ODBCVER >= 0x0300 */

'//   Driver specific Setup APIs called by installer

'BOOL INSTAPI ConfigDSNW (
'   HWND   hwndParent,
'   WORD   fRequest,
'   LPCWSTR   lpszDriver,
'   LPCWSTR   lpszAttributes);


'#if (ODBCVER >= 0x0250)
'BOOL INSTAPI ConfigDriverW (
'   HWND hwndParent,
'   WORD fRequest,
'   LPCWSTR lpszDriver,
'   LPCWSTR lpszArgs,
'   LPWSTR  lpszMsg,
'   WORD   cbMsgMax,
'   WORD    *pcbMsgOut);
'#endif
